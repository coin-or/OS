/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

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
#define YYBISON_VERSION "2.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 1

/* Using locations.  */
#define YYLSP_NEEDED 1

/* Substitute the variable and function names.  */
#define yyparse osolparse
#define yylex   osollex
#define yyerror osolerror
#define yylval  osollval
#define yychar  osolchar
#define yydebug osoldebug
#define yynerrs osolnerrs
#define yylloc osollloc

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

#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE

{
	double dval;
	int ival;
	char* sval;
}
/* Line 193 of yacc.c.  */

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


/* Copy the second part of user declarations.  */



void osolerror(YYLTYPE* type, OSOption *osoption,  OSoLParserData *parserData, OSgLParserData *osglData, const char* errormsg ) ;
int osollex(YYSTYPE* lvalp,  YYLTYPE* llocp, void* scanner);

#define scanner parserData->scanner


/* Line 216 of yacc.c.  */


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
# if defined YYENABLE_NLS && YYENABLE_NLS
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
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
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
  yytype_int16 yyss;
  YYSTYPE yyvs;
    YYLTYPE yyls;
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
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
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
#define YYNNTS  804
/* YYNRULES -- Number of rules.  */
#define YYNRULES  1196
/* YYNRULES -- Number of states.  */
#define YYNSTATES  1651

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
      22,    24,    28,    30,    31,    38,    39,    42,    44,    46,
      48,    50,    54,    60,    61,    63,    65,    67,    69,    71,
      75,    76,    78,    80,    82,    84,    86,    90,    91,    93,
      95,    97,    99,   101,   105,   106,   108,   110,   112,   114,
     116,   120,   121,   123,   125,   127,   129,   131,   135,   136,
     139,   141,   143,   145,   148,   150,   154,   156,   158,   161,
     163,   165,   167,   169,   171,   173,   175,   177,   179,   181,
     183,   186,   188,   190,   192,   195,   197,   201,   203,   206,
     208,   210,   212,   215,   217,   221,   223,   226,   228,   230,
     232,   235,   237,   241,   243,   247,   249,   250,   252,   256,
     258,   260,   263,   265,   269,   271,   274,   276,   278,   280,
     283,   285,   289,   291,   294,   296,   298,   300,   303,   305,
     309,   311,   314,   316,   318,   320,   323,   325,   329,   331,
     334,   336,   338,   340,   343,   345,   349,   351,   354,   356,
     358,   360,   363,   365,   369,   371,   375,   377,   378,   380,
     384,   386,   388,   391,   393,   397,   399,   403,   405,   407,
     409,   411,   414,   416,   420,   422,   424,   427,   431,   433,
     435,   436,   439,   441,   443,   445,   448,   450,   451,   454,
     456,   458,   460,   463,   465,   469,   471,   473,   476,   478,
     480,   482,   484,   486,   490,   492,   494,   495,   498,   500,
     502,   506,   508,   512,   514,   516,   517,   520,   522,   524,
     528,   530,   534,   536,   538,   539,   542,   544,   546,   550,
     552,   556,   558,   559,   561,   565,   567,   571,   573,   575,
     577,   579,   582,   584,   588,   590,   592,   595,   599,   601,
     603,   604,   607,   609,   611,   613,   616,   618,   619,   622,
     624,   626,   628,   631,   633,   637,   639,   641,   644,   646,
     648,   651,   653,   655,   657,   660,   662,   666,   668,   672,
     674,   676,   678,   680,   683,   685,   689,   691,   693,   696,
     700,   702,   704,   705,   708,   710,   712,   714,   717,   719,
     720,   723,   725,   727,   729,   732,   734,   738,   740,   742,
     745,   747,   749,   751,   753,   755,   757,   759,   761,   763,
     765,   767,   769,   771,   773,   775,   779,   781,   782,   784,
     786,   788,   791,   793,   797,   799,   801,   804,   806,   808,
     810,   813,   815,   819,   821,   825,   827,   829,   831,   833,
     836,   838,   842,   844,   847,   852,   856,   858,   860,   862,
     864,   867,   869,   873,   875,   878,   883,   887,   889,   891,
     893,   895,   898,   900,   904,   906,   909,   914,   918,   920,
     922,   924,   926,   929,   931,   935,   937,   940,   945,   949,
     951,   953,   955,   957,   960,   962,   966,   968,   971,   976,
     980,   982,   984,   986,   988,   991,   993,   997,   999,  1002,
    1004,  1008,  1010,  1012,  1014,  1016,  1019,  1021,  1025,  1027,
    1030,  1032,  1036,  1038,  1040,  1042,  1044,  1047,  1049,  1053,
    1055,  1058,  1060,  1064,  1066,  1068,  1070,  1072,  1075,  1077,
    1081,  1083,  1086,  1088,  1092,  1094,  1096,  1098,  1100,  1103,
    1105,  1109,  1111,  1114,  1119,  1123,  1125,  1127,  1129,  1131,
    1134,  1136,  1140,  1142,  1145,  1150,  1154,  1156,  1158,  1160,
    1162,  1165,  1167,  1171,  1173,  1176,  1181,  1185,  1187,  1189,
    1191,  1193,  1196,  1198,  1202,  1204,  1206,  1209,  1213,  1215,
    1217,  1218,  1221,  1223,  1225,  1227,  1230,  1232,  1233,  1237,
    1239,  1241,  1242,  1245,  1247,  1249,  1251,  1253,  1255,  1257,
    1261,  1266,  1267,  1271,  1273,  1275,  1276,  1278,  1280,  1282,
    1284,  1288,  1295,  1296,  1300,  1302,  1304,  1306,  1308,  1311,
    1313,  1317,  1319,  1321,  1324,  1328,  1330,  1332,  1333,  1336,
    1338,  1340,  1342,  1345,  1347,  1348,  1352,  1354,  1356,  1358,
    1360,  1363,  1365,  1369,  1371,  1373,  1376,  1380,  1382,  1384,
    1385,  1388,  1390,  1392,  1394,  1397,  1399,  1400,  1403,  1405,
    1407,  1409,  1411,  1415,  1422,  1423,  1427,  1429,  1431,  1433,
    1435,  1437,  1441,  1443,  1444,  1448,  1450,  1452,  1454,  1456,
    1458,  1462,  1464,  1465,  1469,  1471,  1473,  1475,  1477,  1479,
    1483,  1485,  1486,  1490,  1492,  1494,  1496,  1498,  1500,  1504,
    1506,  1507,  1511,  1513,  1515,  1517,  1519,  1521,  1525,  1527,
    1528,  1532,  1534,  1536,  1538,  1540,  1542,  1546,  1548,  1549,
    1553,  1555,  1557,  1559,  1561,  1564,  1566,  1570,  1572,  1574,
    1577,  1581,  1583,  1585,  1586,  1589,  1591,  1593,  1595,  1598,
    1600,  1601,  1605,  1607,  1612,  1614,  1616,  1619,  1621,  1625,
    1627,  1630,  1634,  1636,  1638,  1639,  1642,  1644,  1646,  1648,
    1650,  1652,  1655,  1657,  1661,  1662,  1665,  1669,  1671,  1673,
    1674,  1677,  1679,  1681,  1683,  1685,  1687,  1689,  1691,  1693,
    1695,  1697,  1700,  1702,  1706,  1708,  1710,  1712,  1715,  1719,
    1721,  1723,  1724,  1727,  1729,  1731,  1733,  1735,  1737,  1739,
    1742,  1744,  1745,  1749,  1751,  1753,  1754,  1756,  1758,  1760,
    1762,  1766,  1771,  1772,  1776,  1778,  1780,  1782,  1784,  1787,
    1789,  1793,  1795,  1797,  1800,  1804,  1806,  1808,  1809,  1812,
    1814,  1816,  1818,  1821,  1823,  1824,  1828,  1830,  1832,  1834,
    1836,  1839,  1841,  1845,  1847,  1849,  1852,  1856,  1858,  1860,
    1861,  1864,  1866,  1868,  1870,  1872,  1875,  1877,  1878,  1881,
    1883,  1885,  1887,  1889,  1893,  1900,  1901,  1905,  1907,  1909,
    1911,  1913,  1915,  1919,  1921,  1922,  1926,  1928,  1930,  1932,
    1934,  1936,  1940,  1942,  1943,  1947,  1949,  1951,  1953,  1955,
    1957,  1961,  1963,  1964,  1968,  1970,  1972,  1974,  1976,  1978,
    1982,  1984,  1985,  1989,  1991,  1993,  1995,  1997,  1999,  2003,
    2005,  2006,  2010,  2012,  2014,  2016,  2018,  2020,  2024,  2026,
    2027,  2030,  2034,  2036,  2038,  2039,  2042,  2044,  2046,  2048,
    2050,  2052,  2054,  2056,  2058,  2060,  2062,  2065,  2067,  2071,
    2073,  2075,  2077,  2080,  2084,  2086,  2088,  2089,  2092,  2094,
    2096,  2098,  2100,  2102,  2104,  2107,  2109,  2110,  2114,  2116,
    2118,  2119,  2121,  2123,  2125,  2127,  2131,  2136,  2137,  2141,
    2143,  2145,  2147,  2149,  2152,  2154,  2158,  2160,  2162,  2165,
    2169,  2171,  2173,  2174,  2177,  2179,  2181,  2183,  2186,  2188,
    2189,  2193,  2195,  2197,  2199,  2201,  2204,  2206,  2210,  2212,
    2214,  2217,  2221,  2223,  2225,  2226,  2229,  2231,  2233,  2235,
    2237,  2240,  2242,  2243,  2246,  2248,  2250,  2252,  2254,  2258,
    2265,  2266,  2270,  2272,  2274,  2276,  2278,  2280,  2284,  2286,
    2287,  2291,  2293,  2295,  2297,  2299,  2301,  2305,  2307,  2308,
    2312,  2314,  2316,  2318,  2320,  2322,  2326,  2328,  2329,  2333,
    2335,  2337,  2339,  2341,  2343,  2347,  2349,  2350,  2354,  2356,
    2358,  2360,  2362,  2364,  2368,  2370,  2371,  2375,  2377,  2379,
    2381,  2383,  2385,  2389,  2391,  2392,  2395,  2399,  2401,  2403,
    2404,  2407,  2409,  2411,  2413,  2415,  2417,  2419,  2421,  2423,
    2425,  2427,  2430,  2432,  2436,  2438,  2440,  2442,  2445,  2449,
    2451,  2453,  2454,  2457,  2459,  2461,  2463,  2465,  2467,  2469,
    2472,  2474,  2475,  2479,  2481,  2483,  2485,  2487,  2489,  2493,
    2494,  2497,  2501,  2503,  2505,  2507,  2510,  2512,  2514,  2516,
    2518,  2520,  2522,  2524,  2526,  2528,  2531,  2533,  2537,  2539,
    2541,  2544,  2546,  2548,  2550,  2552,  2554,  2558,  2560,  2564,
    2566,  2568,  2569,  2572,  2574,  2576,  2578,  2582,  2586,  2590,
    2593,  2595,  2597,  2599,  2601,  2603,  2607,  2609,  2611,  2613,
    2615,  2619,  2621,  2626,  2628,  2630,  2635,  2637,  2639,  2641,
    2643,  2647,  2649,  2651,  2653,  2655,  2660,  2662,  2664,  2666,
    2668,  2672,  2674,  2676,  2678,  2680,  2684,  2686,  2688,  2693,
    2695,  2697,  2699,  2701,  2705,  2707,  2709,  2711,  2713,  2717,
    2719,  2721,  2723,  2725,  2730,  2732,  2734,  2736,  2738,  2742,
    2744,  2746,  2748,  2750,  2754,  2759,  2764,  2769,  2774,  2779,
    2784,  2789,  2794,  2799,  2804,  2809,  2814,  2819,  2824,  2829,
    2834,  2839,  2844,  2846,  2849,  2853,  2855,  2857,  2858,  2861,
    2863,  2865,  2867,  2869,  2871,  2873,  2877,  2879,  2881,  2883,
    2884,  2887,  2891,  2893,  2895,  2896,  2899,  2901,  2903,  2907,
    2911,  2916,  2918,  2920,  2923,  2925,  2929,  2934,  2939,  2941,
    2943,  2946,  2947,  2950,  2952,  2954,  2956
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     234,     0,    -1,   235,   242,   241,    -1,   236,   237,   238,
      -1,    13,    -1,    12,    -1,    -1,    14,    -1,   239,    -1,
     240,    -1,    11,    -1,    10,   242,   241,    -1,    15,    -1,
      -1,   243,   269,   355,   403,   431,   563,    -1,    -1,   244,
     245,    -1,    67,    -1,   246,    -1,   247,    -1,    11,    -1,
      10,   248,    68,    -1,   249,   253,   257,   261,   265,    -1,
      -1,   250,    -1,   251,    -1,   252,    -1,    82,    -1,    81,
      -1,    79,     5,    80,    -1,    -1,   254,    -1,   255,    -1,
     256,    -1,    86,    -1,    85,    -1,    83,     5,    84,    -1,
      -1,   258,    -1,   259,    -1,   260,    -1,    90,    -1,    89,
      -1,    87,     5,    88,    -1,    -1,   262,    -1,   263,    -1,
     264,    -1,    94,    -1,    93,    -1,    91,     5,    92,    -1,
      -1,   266,    -1,   267,    -1,   268,    -1,    98,    -1,    97,
      -1,    95,     5,    96,    -1,    -1,   270,   271,    -1,    69,
      -1,   272,    -1,   273,    -1,    10,    70,    -1,    11,    -1,
      10,   274,    70,    -1,   275,    -1,   276,    -1,   275,   276,
      -1,   277,    -1,   283,    -1,   289,    -1,   295,    -1,   303,
      -1,   309,    -1,   315,    -1,   321,    -1,   327,    -1,   333,
      -1,   341,    -1,   278,   279,    -1,    99,    -1,   280,    -1,
     281,    -1,    10,   100,    -1,    11,    -1,    10,   282,   100,
      -1,     4,    -1,   284,   285,    -1,   101,    -1,   286,    -1,
     287,    -1,    10,   102,    -1,    11,    -1,    10,   288,   102,
      -1,     4,    -1,   290,   291,    -1,   103,    -1,   292,    -1,
     293,    -1,    10,   104,    -1,    11,    -1,    10,   294,   104,
      -1,     4,    -1,   296,   297,   299,    -1,   105,    -1,    -1,
     298,    -1,    66,     3,     8,    -1,   300,    -1,   301,    -1,
      10,   106,    -1,    11,    -1,    10,   302,   106,    -1,     4,
      -1,   304,   305,    -1,   107,    -1,   306,    -1,   307,    -1,
      10,   108,    -1,    11,    -1,    10,   308,   108,    -1,     4,
      -1,   310,   311,    -1,   109,    -1,   312,    -1,   313,    -1,
      10,   110,    -1,    11,    -1,    10,   314,   110,    -1,     4,
      -1,   316,   317,    -1,   111,    -1,   318,    -1,   319,    -1,
      10,   112,    -1,    11,    -1,    10,   320,   112,    -1,     4,
      -1,   322,   323,    -1,   113,    -1,   324,    -1,   325,    -1,
      10,   114,    -1,    11,    -1,    10,   326,   114,    -1,     4,
      -1,   328,   329,    -1,   115,    -1,   330,    -1,   331,    -1,
      10,   116,    -1,    11,    -1,    10,   332,   116,    -1,     4,
      -1,   334,   335,   337,    -1,   117,    -1,    -1,   336,    -1,
      65,     3,     8,    -1,   338,    -1,   339,    -1,    10,   118,
      -1,    11,    -1,    10,   340,   118,    -1,     4,    -1,   342,
     343,   344,    -1,   119,    -1,  1000,    -1,   345,    -1,   346,
      -1,    10,   120,    -1,    11,    -1,    10,   347,   120,    -1,
     348,    -1,   349,    -1,   348,   349,    -1,   350,   351,   354,
      -1,   121,    -1,   352,    -1,    -1,   352,   353,    -1,   959,
      -1,   986,    -1,   942,    -1,    10,   122,    -1,    11,    -1,
      -1,   356,   357,    -1,    71,    -1,   358,    -1,   359,    -1,
      10,    72,    -1,    11,    -1,    10,   360,    72,    -1,   361,
      -1,   362,    -1,   361,   362,    -1,   363,    -1,   370,    -1,
     377,    -1,   384,    -1,   389,    -1,   364,   365,   368,    -1,
     123,    -1,   366,    -1,    -1,   366,   367,    -1,   982,    -1,
     942,    -1,    10,   369,   124,    -1,  1033,    -1,   371,   372,
     375,    -1,   125,    -1,   373,    -1,    -1,   373,   374,    -1,
     982,    -1,   942,    -1,    10,   376,   126,    -1,  1033,    -1,
     378,   379,   382,    -1,   127,    -1,   380,    -1,    -1,   380,
     381,    -1,   982,    -1,   942,    -1,    10,   383,   128,    -1,
    1033,    -1,   385,   386,   387,    -1,   129,    -1,    -1,   942,
      -1,    10,   388,   130,    -1,     6,    -1,   390,   391,   392,
      -1,   119,    -1,  1000,    -1,   393,    -1,   394,    -1,    10,
     120,    -1,    11,    -1,    10,   395,   120,    -1,   396,    -1,
     397,    -1,   396,   397,    -1,   398,   399,   402,    -1,   121,
      -1,   400,    -1,    -1,   400,   401,    -1,   959,    -1,   986,
      -1,   942,    -1,    10,   122,    -1,    11,    -1,    -1,   404,
     405,    -1,    73,    -1,   406,    -1,   407,    -1,    10,    74,
      -1,    11,    -1,    10,   408,    74,    -1,   409,    -1,   410,
      -1,   409,   410,    -1,   411,    -1,   417,    -1,   412,   413,
      -1,   131,    -1,   414,    -1,   415,    -1,    10,   132,    -1,
      11,    -1,    10,   416,   132,    -1,     4,    -1,   418,   419,
     420,    -1,   119,    -1,  1000,    -1,   421,    -1,   422,    -1,
      10,   120,    -1,    11,    -1,    10,   423,   120,    -1,   424,
      -1,   425,    -1,   424,   425,    -1,   426,   427,   430,    -1,
     121,    -1,   428,    -1,    -1,   428,   429,    -1,   959,    -1,
     986,    -1,   942,    -1,    10,   122,    -1,    11,    -1,    -1,
     432,   433,    -1,    75,    -1,   434,    -1,   435,    -1,    10,
      76,    -1,    11,    -1,    10,   436,    76,    -1,   437,    -1,
     438,    -1,   437,   438,    -1,   439,    -1,   447,    -1,   453,
      -1,   461,    -1,   469,    -1,   477,    -1,   485,    -1,   493,
      -1,   501,    -1,   517,    -1,   509,    -1,   525,    -1,   533,
      -1,   541,    -1,   549,    -1,   440,   441,   442,    -1,   133,
      -1,    -1,   982,    -1,   443,    -1,   444,    -1,    10,   134,
      -1,    11,    -1,    10,   445,   134,    -1,   446,    -1,  1033,
      -1,   448,   449,    -1,   135,    -1,   450,    -1,   451,    -1,
      10,   136,    -1,    11,    -1,    10,   452,   136,    -1,     4,
      -1,   454,   455,   456,    -1,   137,    -1,   995,    -1,   457,
      -1,   458,    -1,    10,   138,    -1,    11,    -1,    10,   459,
     138,    -1,   460,    -1,   459,   460,    -1,   107,    10,     4,
     108,    -1,   462,   463,   464,    -1,   139,    -1,  1003,    -1,
     465,    -1,   466,    -1,    10,   140,    -1,    11,    -1,    10,
     467,   140,    -1,   468,    -1,   467,   468,    -1,   143,    10,
       4,   144,    -1,   470,   471,   472,    -1,   141,    -1,  1003,
      -1,   473,    -1,   474,    -1,    10,   142,    -1,    11,    -1,
      10,   475,   142,    -1,   476,    -1,   475,   476,    -1,   143,
      10,     4,   144,    -1,   478,   479,   480,    -1,   147,    -1,
    1003,    -1,   481,    -1,   482,    -1,    10,   148,    -1,    11,
      -1,    10,   483,   148,    -1,   484,    -1,   483,   484,    -1,
     143,    10,     4,   144,    -1,   486,   487,   488,    -1,   149,
      -1,  1003,    -1,   489,    -1,   490,    -1,    10,   150,    -1,
      11,    -1,    10,   491,   150,    -1,   492,    -1,   491,   492,
      -1,   143,    10,     4,   144,    -1,   494,   495,   496,    -1,
     155,    -1,  1002,    -1,   497,    -1,   498,    -1,    10,   156,
      -1,    11,    -1,    10,   499,   156,    -1,   500,    -1,   499,
     500,    -1,   929,    -1,   502,   503,   504,    -1,   157,    -1,
    1002,    -1,   505,    -1,   506,    -1,    10,   158,    -1,    11,
      -1,    10,   507,   158,    -1,   508,    -1,   507,   508,    -1,
     929,    -1,   510,   511,   512,    -1,   161,    -1,  1002,    -1,
     513,    -1,   514,    -1,    10,   162,    -1,    11,    -1,    10,
     515,   162,    -1,   516,    -1,   515,   516,    -1,   929,    -1,
     518,   519,   520,    -1,   159,    -1,  1002,    -1,   521,    -1,
     522,    -1,    10,   160,    -1,    11,    -1,    10,   523,   160,
      -1,   524,    -1,   523,   524,    -1,   929,    -1,   526,   527,
     528,    -1,   153,    -1,  1003,    -1,   529,    -1,   530,    -1,
      10,   154,    -1,    11,    -1,    10,   531,   154,    -1,   532,
      -1,   531,   532,    -1,   143,    10,     4,   144,    -1,   534,
     535,   536,    -1,   151,    -1,  1003,    -1,   537,    -1,   538,
      -1,    10,   152,    -1,    11,    -1,    10,   539,   152,    -1,
     540,    -1,   539,   540,    -1,   143,    10,     4,   144,    -1,
     542,   543,   544,    -1,   163,    -1,  1004,    -1,   545,    -1,
     546,    -1,    10,   164,    -1,    11,    -1,    10,   547,   164,
      -1,   548,    -1,   547,   548,    -1,   165,    10,     4,   166,
      -1,   550,   551,   552,    -1,   119,    -1,  1000,    -1,   553,
      -1,   554,    -1,    10,   120,    -1,    11,    -1,    10,   555,
     120,    -1,   556,    -1,   557,    -1,   556,   557,    -1,   558,
     559,   562,    -1,   121,    -1,   560,    -1,    -1,   560,   561,
      -1,   959,    -1,   986,    -1,   942,    -1,    10,   122,    -1,
      11,    -1,    -1,   564,   565,   568,    -1,    77,    -1,   566,
      -1,    -1,   566,   567,    -1,  1007,    -1,   991,    -1,   997,
      -1,   569,    -1,   570,    -1,    11,    -1,    10,   571,    78,
      -1,   572,   703,   805,   907,    -1,    -1,   573,   574,   576,
      -1,   167,    -1,   575,    -1,    -1,  1001,    -1,   577,    -1,
     578,    -1,    11,    -1,    10,   579,   168,    -1,   580,   594,
     608,   656,   670,   685,    -1,    -1,   581,   582,   583,    -1,
     169,    -1,  1006,    -1,   584,    -1,   585,    -1,    10,   170,
      -1,    11,    -1,    10,   586,   170,    -1,   587,    -1,   588,
      -1,   587,   588,    -1,   589,   590,   593,    -1,   171,    -1,
     591,    -1,    -1,   591,   592,    -1,   948,    -1,   959,    -1,
     986,    -1,    10,   172,    -1,    11,    -1,    -1,   595,   596,
     597,    -1,   173,    -1,  1006,    -1,   598,    -1,   599,    -1,
      10,   174,    -1,    11,    -1,    10,   600,   174,    -1,   601,
      -1,   602,    -1,   601,   602,    -1,   603,   604,   607,    -1,
     171,    -1,   605,    -1,    -1,   605,   606,    -1,   948,    -1,
     959,    -1,   986,    -1,    10,   172,    -1,    11,    -1,    -1,
     609,   610,    -1,   175,    -1,   611,    -1,   612,    -1,    11,
      -1,    10,   613,   176,    -1,   614,   621,   628,   635,   642,
     649,    -1,    -1,   615,   616,   617,    -1,   177,    -1,   992,
      -1,   618,    -1,   619,    -1,    11,    -1,    10,   620,   178,
      -1,  1018,    -1,    -1,   622,   623,   624,    -1,   181,    -1,
     992,    -1,   625,    -1,   626,    -1,    11,    -1,    10,   627,
     182,    -1,  1018,    -1,    -1,   629,   630,   631,    -1,   179,
      -1,   992,    -1,   632,    -1,   633,    -1,    11,    -1,    10,
     634,   180,    -1,  1018,    -1,    -1,   636,   637,   638,    -1,
     185,    -1,   992,    -1,   639,    -1,   640,    -1,    11,    -1,
      10,   641,   186,    -1,  1018,    -1,    -1,   643,   644,   645,
      -1,   183,    -1,   992,    -1,   646,    -1,   647,    -1,    11,
      -1,    10,   648,   184,    -1,  1018,    -1,    -1,   650,   651,
     652,    -1,   187,    -1,   992,    -1,   653,    -1,   654,    -1,
      11,    -1,    10,   655,   188,    -1,  1018,    -1,    -1,   657,
     658,   659,    -1,   189,    -1,  1006,    -1,   660,    -1,   661,
      -1,    10,   190,    -1,    11,    -1,    10,   662,   190,    -1,
     663,    -1,   664,    -1,   663,   664,    -1,   665,   666,   669,
      -1,   171,    -1,   667,    -1,    -1,   667,   668,    -1,   948,
      -1,   959,    -1,   986,    -1,    10,   172,    -1,    11,    -1,
      -1,   671,   672,   673,    -1,   191,    -1,    29,     8,     6,
       8,    -1,   674,    -1,   675,    -1,    10,   192,    -1,    11,
      -1,    10,   676,   192,    -1,   677,    -1,   676,   677,    -1,
     678,   679,   682,    -1,   193,    -1,   680,    -1,    -1,   680,
     681,    -1,   967,    -1,  1006,    -1,   946,    -1,   683,    -1,
     684,    -1,    10,   194,    -1,    11,    -1,    10,   663,   194,
      -1,    -1,   685,   686,    -1,   687,   688,   691,    -1,   121,
      -1,   689,    -1,    -1,   689,   690,    -1,  1006,    -1,   993,
      -1,   959,    -1,   986,    -1,   963,    -1,   938,    -1,   970,
      -1,   942,    -1,   692,    -1,   693,    -1,    10,   122,    -1,
      11,    -1,    10,   694,   122,    -1,   695,    -1,  1008,    -1,
     696,    -1,   695,   696,    -1,   697,   698,   701,    -1,   171,
      -1,   699,    -1,    -1,   699,   700,    -1,   948,    -1,   959,
      -1,   986,    -1,   951,    -1,   974,    -1,   702,    -1,    10,
     172,    -1,    11,    -1,    -1,   704,   705,   707,    -1,   195,
      -1,   706,    -1,    -1,   999,    -1,   708,    -1,   709,    -1,
      11,    -1,    10,   710,   196,    -1,   711,   725,   739,   787,
      -1,    -1,   712,   713,   714,    -1,   197,    -1,   996,    -1,
     715,    -1,   716,    -1,    10,   198,    -1,    11,    -1,    10,
     717,   198,    -1,   718,    -1,   719,    -1,   718,   719,    -1,
     720,   721,   724,    -1,   199,    -1,   722,    -1,    -1,   722,
     723,    -1,   948,    -1,   959,    -1,   986,    -1,    10,   200,
      -1,    11,    -1,    -1,   726,   727,   728,    -1,   201,    -1,
     996,    -1,   729,    -1,   730,    -1,    10,   202,    -1,    11,
      -1,    10,   731,   202,    -1,   732,    -1,   733,    -1,   732,
     733,    -1,   734,   735,   738,    -1,   199,    -1,   736,    -1,
      -1,   736,   737,    -1,   948,    -1,   959,    -1,   951,    -1,
     974,    -1,    10,   200,    -1,    11,    -1,    -1,   740,   741,
      -1,   175,    -1,   742,    -1,   743,    -1,    11,    -1,    10,
     744,   176,    -1,   745,   752,   759,   766,   773,   780,    -1,
      -1,   746,   747,   748,    -1,   177,    -1,   992,    -1,   749,
      -1,   750,    -1,    11,    -1,    10,   751,   178,    -1,  1018,
      -1,    -1,   753,   754,   755,    -1,   181,    -1,   992,    -1,
     756,    -1,   757,    -1,    11,    -1,    10,   758,   182,    -1,
    1018,    -1,    -1,   760,   761,   762,    -1,   179,    -1,   992,
      -1,   763,    -1,   764,    -1,    11,    -1,    10,   765,   180,
      -1,  1018,    -1,    -1,   767,   768,   769,    -1,   185,    -1,
     992,    -1,   770,    -1,   771,    -1,    11,    -1,    10,   772,
     186,    -1,  1018,    -1,    -1,   774,   775,   776,    -1,   183,
      -1,   992,    -1,   777,    -1,   778,    -1,    11,    -1,    10,
     779,   184,    -1,  1018,    -1,    -1,   781,   782,   783,    -1,
     187,    -1,   992,    -1,   784,    -1,   785,    -1,    11,    -1,
      10,   786,   188,    -1,  1018,    -1,    -1,   787,   788,    -1,
     789,   790,   793,    -1,   121,    -1,   791,    -1,    -1,   791,
     792,    -1,   996,    -1,   993,    -1,   959,    -1,   986,    -1,
     963,    -1,   938,    -1,   970,    -1,   942,    -1,   794,    -1,
     795,    -1,    10,   122,    -1,    11,    -1,    10,   796,   122,
      -1,   797,    -1,  1008,    -1,   798,    -1,   797,   798,    -1,
     799,   800,   803,    -1,   199,    -1,   801,    -1,    -1,   801,
     802,    -1,   948,    -1,   959,    -1,   986,    -1,   951,    -1,
     974,    -1,   804,    -1,    10,   200,    -1,    11,    -1,    -1,
     806,   807,   809,    -1,   203,    -1,   808,    -1,    -1,   998,
      -1,   810,    -1,   811,    -1,    11,    -1,    10,   812,   204,
      -1,   813,   827,   841,   889,    -1,    -1,   814,   815,   816,
      -1,   205,    -1,   990,    -1,   817,    -1,   818,    -1,    10,
     206,    -1,    11,    -1,    10,   819,   206,    -1,   820,    -1,
     821,    -1,   820,   821,    -1,   822,   823,   826,    -1,   207,
      -1,   824,    -1,    -1,   824,   825,    -1,   948,    -1,   959,
      -1,   986,    -1,    10,   208,    -1,    11,    -1,    -1,   828,
     829,   830,    -1,   209,    -1,   990,    -1,   831,    -1,   832,
      -1,    10,   210,    -1,    11,    -1,    10,   833,   210,    -1,
     834,    -1,   835,    -1,   834,   835,    -1,   836,   837,   840,
      -1,   207,    -1,   838,    -1,    -1,   838,   839,    -1,   948,
      -1,   959,    -1,   955,    -1,   978,    -1,    10,   208,    -1,
      11,    -1,    -1,   842,   843,    -1,   175,    -1,   844,    -1,
     845,    -1,    11,    -1,    10,   846,   176,    -1,   847,   854,
     861,   868,   875,   882,    -1,    -1,   848,   849,   850,    -1,
     177,    -1,   992,    -1,   851,    -1,   852,    -1,    11,    -1,
      10,   853,   178,    -1,  1018,    -1,    -1,   855,   856,   857,
      -1,   181,    -1,   992,    -1,   858,    -1,   859,    -1,    11,
      -1,    10,   860,   182,    -1,  1018,    -1,    -1,   862,   863,
     864,    -1,   179,    -1,   992,    -1,   865,    -1,   866,    -1,
      11,    -1,    10,   867,   180,    -1,  1018,    -1,    -1,   869,
     870,   871,    -1,   185,    -1,   992,    -1,   872,    -1,   873,
      -1,    11,    -1,    10,   874,   186,    -1,  1018,    -1,    -1,
     876,   877,   878,    -1,   183,    -1,   992,    -1,   879,    -1,
     880,    -1,    11,    -1,    10,   881,   184,    -1,  1018,    -1,
      -1,   883,   884,   885,    -1,   187,    -1,   992,    -1,   886,
      -1,   887,    -1,    11,    -1,    10,   888,   188,    -1,  1018,
      -1,    -1,   889,   890,    -1,   891,   892,   895,    -1,   121,
      -1,   893,    -1,    -1,   893,   894,    -1,   990,    -1,   993,
      -1,   959,    -1,   986,    -1,   963,    -1,   938,    -1,   970,
      -1,   942,    -1,   896,    -1,   897,    -1,    10,   122,    -1,
      11,    -1,    10,   898,   122,    -1,   899,    -1,  1008,    -1,
     900,    -1,   899,   900,    -1,   901,   902,   905,    -1,   207,
      -1,   903,    -1,    -1,   903,   904,    -1,   948,    -1,   959,
      -1,   986,    -1,   951,    -1,   974,    -1,   906,    -1,    10,
     208,    -1,    11,    -1,    -1,   908,   909,   910,    -1,   211,
      -1,  1005,    -1,   911,    -1,   912,    -1,    11,    -1,    10,
     913,   212,    -1,    -1,   913,   914,    -1,   915,   916,   919,
      -1,   213,    -1,   917,    -1,   918,    -1,   917,   918,    -1,
     959,    -1,   986,    -1,   963,    -1,   938,    -1,   970,    -1,
     942,    -1,   994,    -1,   920,    -1,   921,    -1,    10,   214,
      -1,    11,    -1,    10,   922,   214,    -1,   923,    -1,   924,
      -1,   923,   924,    -1,   925,    -1,   926,    -1,   927,    -1,
     220,    -1,   217,    -1,   218,   928,   219,    -1,     5,    -1,
     930,   931,   937,    -1,   145,    -1,   932,    -1,    -1,   932,
     933,    -1,   934,    -1,   935,    -1,   936,    -1,    21,     3,
       8,    -1,    22,     3,     8,    -1,    23,     3,     8,    -1,
      10,   146,    -1,    11,    -1,   939,    -1,   940,    -1,   941,
      -1,    49,    -1,    24,     3,  1034,    -1,   943,    -1,   944,
      -1,   945,    -1,    50,    -1,    46,     3,  1034,    -1,   947,
      -1,    26,     8,  1033,     8,    -1,   949,    -1,   950,    -1,
      42,  1034,     6,  1034,    -1,   952,    -1,   953,    -1,   954,
      -1,    53,    -1,    55,     3,  1034,    -1,   956,    -1,   957,
      -1,   958,    -1,    57,    -1,    59,  1034,  1033,  1034,    -1,
     960,    -1,   961,    -1,   962,    -1,    48,    -1,    41,     3,
    1034,    -1,   964,    -1,   965,    -1,   966,    -1,    62,    -1,
      61,     3,  1034,    -1,   968,    -1,   969,    -1,    43,  1034,
       6,  1034,    -1,   971,    -1,   972,    -1,   973,    -1,    47,
      -1,    25,     3,     8,    -1,   975,    -1,   976,    -1,   977,
      -1,    54,    -1,    56,     3,  1034,    -1,   979,    -1,   980,
      -1,   981,    -1,    58,    -1,    60,  1034,  1033,  1034,    -1,
     983,    -1,   984,    -1,   985,    -1,    51,    -1,    45,     3,
       8,    -1,   987,    -1,   988,    -1,   989,    -1,    52,    -1,
      44,     3,     8,    -1,    39,  1034,     6,  1034,    -1,    32,
    1034,     6,  1034,    -1,    40,  1034,     6,  1034,    -1,    17,
    1034,     6,  1034,    -1,    36,  1034,     6,  1034,    -1,    18,
       8,     6,     8,    -1,    38,  1034,     6,  1034,    -1,    31,
    1034,     6,  1034,    -1,    35,  1034,     6,  1034,    -1,    34,
    1034,     6,  1034,    -1,    16,  1034,     6,  1034,    -1,    33,
    1034,     6,  1034,    -1,    20,     8,     6,     8,    -1,    19,
       8,     6,     8,    -1,    27,     8,     6,     8,    -1,    28,
    1034,     6,  1034,    -1,    37,  1034,     6,  1034,    -1,    30,
    1034,     6,  1034,    -1,  1009,    -1,  1008,  1009,    -1,  1010,
    1011,  1014,    -1,   215,    -1,  1012,    -1,    -1,  1012,  1013,
      -1,   992,    -1,   986,    -1,   942,    -1,  1015,    -1,  1016,
      -1,    11,    -1,    10,  1017,   216,    -1,  1018,    -1,  1019,
      -1,  1026,    -1,    -1,  1019,  1020,    -1,  1021,  1022,  1025,
      -1,   226,    -1,  1023,    -1,    -1,  1023,  1024,    -1,  1032,
      -1,  1031,    -1,    10,     6,   227,    -1,   221,  1027,  1028,
      -1,   225,  1034,     6,  1034,    -1,  1029,    -1,  1030,    -1,
      10,   222,    -1,    11,    -1,    10,     4,   222,    -1,   223,
    1034,     6,  1034,    -1,   224,  1034,     6,  1034,    -1,     6,
      -1,     7,    -1,  1035,     8,    -1,    -1,  1035,  1036,    -1,
     229,    -1,   230,    -1,   231,    -1,   232,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   164,   164,   165,   167,   174,   181,   181,   183,   183,
     185,   187,   189,   190,   193,   201,   201,   208,   217,   217,
     219,   221,   223,   225,   225,   227,   227,   229,   229,   231,
     237,   237,   239,   239,   241,   241,   243,   249,   249,   251,
     251,   253,   253,   255,   261,   261,   263,   263,   265,   265,
     267,   273,   273,   275,   275,   277,   277,   279,   290,   290,
     292,   308,   308,   310,   310,   312,   314,   316,   316,   319,
     320,   321,   322,   323,   324,   325,   326,   327,   328,   329,
     333,   335,   343,   343,   345,   345,   347,   349,   359,   361,
     367,   367,   369,   369,   371,   373,   382,   384,   390,   390,
     392,   392,   394,   396,   406,   413,   421,   422,   429,   435,
     435,   437,   437,   439,   441,   449,   451,   457,   457,   459,
     459,   461,   463,   472,   474,   481,   481,   483,   483,   485,
     487,   497,   499,   506,   506,   508,   508,   510,   512,   522,
     524,   530,   530,   532,   532,   534,   536,   546,   548,   554,
     554,   556,   556,   558,   560,   570,   577,   586,   587,   593,
     600,   600,   602,   602,   604,   606,   614,   616,   622,   630,
     634,   639,   639,   641,   643,   647,   647,   649,   656,   667,
     673,   673,   676,   680,   681,   684,   684,   693,   693,   695,
     705,   705,   707,   707,   709,   711,   713,   713,   716,   717,
     718,   719,   720,   724,   726,   736,   738,   738,   741,   742,
     745,   747,   755,   757,   767,   769,   769,   772,   773,   776,
     778,   787,   789,   799,   801,   801,   804,   805,   808,   810,
     819,   821,   829,   830,   832,   834,   845,   847,   854,   862,
     866,   871,   871,   873,   875,   879,   879,   881,   888,   899,
     904,   904,   907,   912,   913,   916,   916,   925,   925,   927,
     934,   934,   936,   936,   938,   940,   942,   942,   945,   946,
     950,   952,   958,   958,   960,   960,   962,   964,   975,   977,
     984,   992,   996,  1001,  1001,  1003,  1005,  1009,  1009,  1011,
    1018,  1029,  1034,  1034,  1037,  1042,  1043,  1046,  1046,  1054,
    1054,  1056,  1076,  1076,  1078,  1078,  1080,  1082,  1084,  1084,
    1087,  1088,  1089,  1090,  1091,  1092,  1093,  1094,  1095,  1096,
    1097,  1098,  1099,  1100,  1101,  1106,  1112,  1122,  1123,  1125,
    1125,  1127,  1127,  1129,  1131,  1133,  1140,  1142,  1148,  1148,
    1150,  1150,  1152,  1154,  1164,  1172,  1179,  1181,  1181,  1183,
    1183,  1185,  1191,  1191,  1193,  1204,  1212,  1218,  1220,  1220,
    1222,  1222,  1224,  1230,  1230,  1232,  1243,  1251,  1257,  1259,
    1259,  1261,  1261,  1263,  1269,  1269,  1271,  1281,  1289,  1295,
    1297,  1297,  1299,  1299,  1301,  1307,  1307,  1309,  1319,  1327,
    1333,  1335,  1335,  1337,  1337,  1339,  1345,  1345,  1347,  1358,
    1371,  1377,  1379,  1379,  1381,  1381,  1383,  1389,  1389,  1391,
    1395,  1408,  1414,  1416,  1416,  1418,  1418,  1420,  1426,  1426,
    1428,  1432,  1445,  1451,  1453,  1453,  1455,  1455,  1457,  1463,
    1463,  1465,  1469,  1482,  1488,  1490,  1490,  1492,  1492,  1494,
    1500,  1500,  1502,  1506,  1514,  1520,  1522,  1522,  1524,  1524,
    1526,  1532,  1532,  1534,  1545,  1553,  1559,  1561,  1561,  1563,
    1563,  1565,  1571,  1571,  1573,  1584,  1592,  1599,  1601,  1601,
    1603,  1603,  1605,  1611,  1611,  1613,  1625,  1627,  1633,  1641,
    1645,  1650,  1650,  1652,  1654,  1658,  1658,  1660,  1667,  1678,
    1683,  1683,  1686,  1691,  1692,  1695,  1695,  1703,  1703,  1705,
    1713,  1715,  1715,  1718,  1724,  1730,  1738,  1738,  1740,  1742,
    1744,  1751,  1751,  1753,  1759,  1766,  1766,  1771,  1771,  1773,
    1775,  1777,  1782,  1782,  1794,  1799,  1810,  1815,  1821,  1821,
    1823,  1825,  1827,  1827,  1830,  1835,  1844,  1850,  1850,  1853,
    1864,  1868,  1875,  1875,  1879,  1879,  1891,  1896,  1907,  1912,
    1918,  1918,  1920,  1922,  1924,  1924,  1927,  1932,  1942,  1948,
    1948,  1951,  1962,  1966,  1971,  1971,  1975,  1975,  1977,  1982,
    1982,  1984,  1986,  1988,  1991,  1991,  1999,  2005,  2012,  2012,
    2014,  2016,  2018,  2022,  2022,  2031,  2037,  2044,  2044,  2046,
    2048,  2050,  2054,  2054,  2062,  2068,  2075,  2075,  2077,  2079,
    2081,  2085,  2085,  2093,  2099,  2106,  2106,  2108,  2110,  2112,
    2116,  2116,  2124,  2130,  2137,  2137,  2139,  2141,  2143,  2147,
    2147,  2155,  2161,  2168,  2168,  2170,  2172,  2174,  2178,  2178,
    2191,  2196,  2207,  2212,  2218,  2218,  2220,  2222,  2228,  2228,
    2230,  2235,  2246,  2255,  2255,  2258,  2269,  2273,  2280,  2280,
    2284,  2284,  2286,  2292,  2300,  2304,  2309,  2309,  2311,  2313,
    2313,  2315,  2331,  2341,  2349,  2349,  2352,  2353,  2362,  2365,
    2365,  2367,  2367,  2369,  2374,  2374,  2376,  2381,  2403,  2420,
    2420,  2423,  2427,  2431,  2432,  2433,  2434,  2435,  2436,  2439,
    2439,  2441,  2441,  2443,  2445,  2445,  2447,  2447,  2450,  2464,
    2479,  2481,  2481,  2484,  2494,  2495,  2496,  2497,  2500,  2502,
    2502,  2510,  2510,  2512,  2518,  2525,  2525,  2530,  2530,  2532,
    2534,  2536,  2540,  2540,  2553,  2559,  2571,  2576,  2582,  2582,
    2584,  2586,  2588,  2588,  2591,  2596,  2606,  2608,  2608,  2611,
    2622,  2626,  2633,  2633,  2636,  2636,  2651,  2656,  2670,  2675,
    2681,  2681,  2683,  2685,  2687,  2687,  2690,  2695,  2708,  2710,
    2710,  2713,  2724,  2728,  2734,  2741,  2741,  2745,  2745,  2747,
    2752,  2752,  2754,  2756,  2758,  2761,  2761,  2769,  2775,  2782,
    2782,  2784,  2786,  2788,  2791,  2791,  2799,  2805,  2812,  2812,
    2814,  2816,  2818,  2821,  2821,  2829,  2835,  2842,  2842,  2844,
    2846,  2848,  2851,  2851,  2859,  2865,  2872,  2872,  2874,  2876,
    2878,  2881,  2881,  2889,  2896,  2903,  2903,  2905,  2907,  2909,
    2913,  2913,  2921,  2927,  2934,  2934,  2936,  2938,  2940,  2944,
    2944,  2946,  2952,  2974,  2992,  2992,  2995,  2999,  3003,  3004,
    3005,  3006,  3007,  3008,  3011,  3011,  3013,  3013,  3015,  3017,
    3017,  3019,  3019,  3022,  3036,  3052,  3061,  3061,  3064,  3074,
    3075,  3076,  3077,  3080,  3082,  3082,  3090,  3090,  3092,  3098,
    3105,  3105,  3110,  3110,  3112,  3114,  3116,  3120,  3120,  3133,
    3138,  3149,  3154,  3160,  3160,  3162,  3164,  3166,  3166,  3169,
    3174,  3184,  3190,  3190,  3193,  3204,  3208,  3215,  3215,  3219,
    3219,  3234,  3239,  3252,  3257,  3263,  3263,  3265,  3267,  3269,
    3269,  3272,  3277,  3290,  3296,  3296,  3299,  3310,  3314,  3318,
    3324,  3324,  3328,  3328,  3330,  3335,  3335,  3337,  3339,  3341,
    3344,  3344,  3352,  3358,  3365,  3365,  3367,  3369,  3371,  3374,
    3374,  3382,  3388,  3395,  3395,  3397,  3399,  3401,  3405,  3405,
    3413,  3419,  3426,  3426,  3428,  3430,  3432,  3436,  3436,  3444,
    3450,  3457,  3457,  3459,  3461,  3463,  3467,  3467,  3475,  3481,
    3488,  3488,  3490,  3492,  3494,  3498,  3498,  3506,  3512,  3519,
    3519,  3521,  3523,  3525,  3529,  3529,  3531,  3537,  3559,  3576,
    3576,  3579,  3583,  3587,  3588,  3589,  3590,  3591,  3592,  3595,
    3595,  3597,  3597,  3599,  3601,  3601,  3603,  3603,  3606,  3620,
    3635,  3637,  3637,  3640,  3650,  3651,  3652,  3653,  3656,  3658,
    3658,  3666,  3666,  3668,  3670,  3678,  3683,  3689,  3691,  3693,
    3693,  3697,  3716,  3734,  3740,  3740,  3743,  3744,  3745,  3746,
    3747,  3748,  3749,  3756,  3760,  3765,  3765,  3767,  3769,  3771,
    3771,  3773,  3780,  3786,  3788,  3788,  3790,  3792,  3804,  3813,
    3823,  3828,  3828,  3831,  3832,  3833,  3835,  3844,  3853,  3862,
    3862,  3868,  3875,  3875,  3877,  3882,  3889,  3896,  3896,  3898,
    3901,  3908,  3915,  3922,  3929,  3931,  3937,  3944,  3944,  3946,
    3951,  3958,  3964,  3964,  3966,  3969,  3974,  3980,  3980,  3982,
    3985,  3992,  3998,  3998,  4000,  4003,  4010,  4016,  4018,  4026,
    4032,  4032,  4034,  4037,  4044,  4051,  4051,  4053,  4058,  4065,
    4071,  4071,  4073,  4076,  4083,  4089,  4089,  4091,  4094,  4101,
    4107,  4107,  4109,  4112,  4124,  4133,  4142,  4151,  4160,  4169,
    4178,  4187,  4195,  4201,  4207,  4213,  4219,  4230,  4239,  4249,
    4255,  4264,  4284,  4284,  4286,  4303,  4314,  4321,  4321,  4324,
    4331,  4332,  4336,  4336,  4338,  4340,  4342,  4359,  4364,  4366,
    4366,  4368,  4370,  4379,  4381,  4381,  4383,  4383,  4385,  4393,
    4395,  4400,  4400,  4402,  4402,  4404,  4427,  4435,  4449,  4450,
    4457,  4459,  4459,  4461,  4462,  4463,  4464
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
  "osolBody", "headerElement", "headerElementStart",
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
     239,   240,   241,   241,   242,   243,   243,   244,   245,   245,
     246,   247,   248,   249,   249,   250,   250,   251,   251,   252,
     253,   253,   254,   254,   255,   255,   256,   257,   257,   258,
     258,   259,   259,   260,   261,   261,   262,   262,   263,   263,
     264,   265,   265,   266,   266,   267,   267,   268,   269,   269,
     270,   271,   271,   272,   272,   273,   274,   275,   275,   276,
     276,   276,   276,   276,   276,   276,   276,   276,   276,   276,
     277,   278,   279,   279,   280,   280,   281,   282,   283,   284,
     285,   285,   286,   286,   287,   288,   289,   290,   291,   291,
     292,   292,   293,   294,   295,   296,   297,   297,   298,   299,
     299,   300,   300,   301,   302,   303,   304,   305,   305,   306,
     306,   307,   308,   309,   310,   311,   311,   312,   312,   313,
     314,   315,   316,   317,   317,   318,   318,   319,   320,   321,
     322,   323,   323,   324,   324,   325,   326,   327,   328,   329,
     329,   330,   330,   331,   332,   333,   334,   335,   335,   336,
     337,   337,   338,   338,   339,   340,   341,   342,   343,   344,
     344,   345,   345,   346,   347,   348,   348,   349,   350,   351,
     352,   352,   353,   353,   353,   354,   354,   355,   355,   356,
     357,   357,   358,   358,   359,   360,   361,   361,   362,   362,
     362,   362,   362,   363,   364,   365,   366,   366,   367,   367,
     368,   369,   370,   371,   372,   373,   373,   374,   374,   375,
     376,   377,   378,   379,   380,   380,   381,   381,   382,   383,
     384,   385,   386,   386,   387,   388,   389,   390,   391,   392,
     392,   393,   393,   394,   395,   396,   396,   397,   398,   399,
     400,   400,   401,   401,   401,   402,   402,   403,   403,   404,
     405,   405,   406,   406,   407,   408,   409,   409,   410,   410,
     411,   412,   413,   413,   414,   414,   415,   416,   417,   418,
     419,   420,   420,   421,   421,   422,   423,   424,   424,   425,
     426,   427,   428,   428,   429,   429,   429,   430,   430,   431,
     431,   432,   433,   433,   434,   434,   435,   436,   437,   437,
     438,   438,   438,   438,   438,   438,   438,   438,   438,   438,
     438,   438,   438,   438,   438,   439,   440,   441,   441,   442,
     442,   443,   443,   444,   445,   446,   447,   448,   449,   449,
     450,   450,   451,   452,   453,   454,   455,   456,   456,   457,
     457,   458,   459,   459,   460,   461,   462,   463,   464,   464,
     465,   465,   466,   467,   467,   468,   469,   470,   471,   472,
     472,   473,   473,   474,   475,   475,   476,   477,   478,   479,
     480,   480,   481,   481,   482,   483,   483,   484,   485,   486,
     487,   488,   488,   489,   489,   490,   491,   491,   492,   493,
     494,   495,   496,   496,   497,   497,   498,   499,   499,   500,
     501,   502,   503,   504,   504,   505,   505,   506,   507,   507,
     508,   509,   510,   511,   512,   512,   513,   513,   514,   515,
     515,   516,   517,   518,   519,   520,   520,   521,   521,   522,
     523,   523,   524,   525,   526,   527,   528,   528,   529,   529,
     530,   531,   531,   532,   533,   534,   535,   536,   536,   537,
     537,   538,   539,   539,   540,   541,   542,   543,   544,   544,
     545,   545,   546,   547,   547,   548,   549,   550,   551,   552,
     552,   553,   553,   554,   555,   556,   556,   557,   558,   559,
     560,   560,   561,   561,   561,   562,   562,   563,   563,   564,
     565,   566,   566,   567,   567,   567,   568,   568,   569,   570,
     571,   572,   572,   573,   574,   575,   575,   576,   576,   577,
     578,   579,   580,   580,   581,   582,   583,   583,   584,   584,
     585,   586,   587,   587,   588,   589,   590,   591,   591,   592,
     592,   592,   593,   593,   594,   594,   595,   596,   597,   597,
     598,   598,   599,   600,   601,   601,   602,   603,   604,   605,
     605,   606,   606,   606,   607,   607,   608,   608,   609,   610,
     610,   611,   612,   613,   614,   614,   615,   616,   617,   617,
     618,   619,   620,   621,   621,   622,   623,   624,   624,   625,
     626,   627,   628,   628,   629,   630,   631,   631,   632,   633,
     634,   635,   635,   636,   637,   638,   638,   639,   640,   641,
     642,   642,   643,   644,   645,   645,   646,   647,   648,   649,
     649,   650,   651,   652,   652,   653,   654,   655,   656,   656,
     657,   658,   659,   659,   660,   660,   661,   662,   663,   663,
     664,   665,   666,   667,   667,   668,   668,   668,   669,   669,
     670,   670,   671,   672,   673,   673,   674,   674,   675,   676,
     676,   677,   678,   679,   680,   680,   681,   681,   681,   682,
     682,   683,   683,   684,   685,   685,   686,   687,   688,   689,
     689,   690,   690,   690,   690,   690,   690,   690,   690,   691,
     691,   692,   692,   693,   694,   694,   695,   695,   696,   697,
     698,   699,   699,   700,   700,   700,   700,   700,   701,   702,
     702,   703,   703,   704,   705,   706,   706,   707,   707,   708,
     709,   710,   711,   711,   712,   713,   714,   714,   715,   715,
     716,   717,   718,   718,   719,   720,   721,   722,   722,   723,
     723,   723,   724,   724,   725,   725,   726,   727,   728,   728,
     729,   729,   730,   731,   732,   732,   733,   734,   735,   736,
     736,   737,   737,   737,   737,   738,   738,   739,   739,   740,
     741,   741,   742,   743,   744,   745,   745,   746,   747,   748,
     748,   749,   750,   751,   752,   752,   753,   754,   755,   755,
     756,   757,   758,   759,   759,   760,   761,   762,   762,   763,
     764,   765,   766,   766,   767,   768,   769,   769,   770,   771,
     772,   773,   773,   774,   775,   776,   776,   777,   778,   779,
     780,   780,   781,   782,   783,   783,   784,   785,   786,   787,
     787,   788,   789,   790,   791,   791,   792,   792,   792,   792,
     792,   792,   792,   792,   793,   793,   794,   794,   795,   796,
     796,   797,   797,   798,   799,   800,   801,   801,   802,   802,
     802,   802,   802,   803,   804,   804,   805,   805,   806,   807,
     808,   808,   809,   809,   810,   811,   812,   813,   813,   814,
     815,   816,   816,   817,   817,   818,   819,   820,   820,   821,
     822,   823,   824,   824,   825,   825,   825,   826,   826,   827,
     827,   828,   829,   830,   830,   831,   831,   832,   833,   834,
     834,   835,   836,   837,   838,   838,   839,   839,   839,   839,
     840,   840,   841,   841,   842,   843,   843,   844,   845,   846,
     847,   847,   848,   849,   850,   850,   851,   852,   853,   854,
     854,   855,   856,   857,   857,   858,   859,   860,   861,   861,
     862,   863,   864,   864,   865,   866,   867,   868,   868,   869,
     870,   871,   871,   872,   873,   874,   875,   875,   876,   877,
     878,   878,   879,   880,   881,   882,   882,   883,   884,   885,
     885,   886,   887,   888,   889,   889,   890,   891,   892,   893,
     893,   894,   894,   894,   894,   894,   894,   894,   894,   895,
     895,   896,   896,   897,   898,   898,   899,   899,   900,   901,
     902,   903,   903,   904,   904,   904,   904,   904,   905,   906,
     906,   907,   907,   908,   909,   910,   910,   911,   912,   913,
     913,   914,   915,   916,   917,   917,   918,   918,   918,   918,
     918,   918,   918,   919,   919,   920,   920,   921,   922,   923,
     923,   924,   925,   925,   926,   926,   927,   928,   929,   930,
     931,   932,   932,   933,   933,   933,   934,   935,   936,   937,
     937,   938,   939,   939,   940,   941,   942,   943,   943,   944,
     945,   946,   947,   948,   949,   950,   951,   952,   952,   953,
     954,   955,   956,   956,   957,   958,   959,   960,   960,   961,
     962,   963,   964,   964,   965,   966,   967,   968,   969,   970,
     971,   971,   972,   973,   974,   975,   975,   976,   977,   978,
     979,   979,   980,   981,   982,   983,   983,   984,   985,   986,
     987,   987,   988,   989,   990,   991,   992,   993,   994,   995,
     996,   997,   998,   999,  1000,  1001,  1002,  1003,  1004,  1005,
    1006,  1007,  1008,  1008,  1009,  1010,  1011,  1012,  1012,  1013,
    1013,  1013,  1014,  1014,  1015,  1016,  1017,  1018,  1018,  1019,
    1019,  1020,  1021,  1022,  1023,  1023,  1024,  1024,  1025,  1026,
    1027,  1028,  1028,  1029,  1029,  1030,  1031,  1032,  1033,  1033,
    1034,  1035,  1035,  1036,  1036,  1036,  1036
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     3,     3,     1,     1,     0,     1,     1,     1,
       1,     3,     1,     0,     6,     0,     2,     1,     1,     1,
       1,     3,     5,     0,     1,     1,     1,     1,     1,     3,
       0,     1,     1,     1,     1,     1,     3,     0,     1,     1,
       1,     1,     1,     3,     0,     1,     1,     1,     1,     1,
       3,     0,     1,     1,     1,     1,     1,     3,     0,     2,
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
       1,     3,     1,     2,     4,     3,     1,     1,     1,     1,
       2,     1,     3,     1,     2,     4,     3,     1,     1,     1,
       1,     2,     1,     3,     1,     2,     4,     3,     1,     1,
       1,     1,     2,     1,     3,     1,     2,     4,     3,     1,
       1,     1,     1,     2,     1,     3,     1,     2,     4,     3,
       1,     1,     1,     1,     2,     1,     3,     1,     2,     1,
       3,     1,     1,     1,     1,     2,     1,     3,     1,     2,
       1,     3,     1,     1,     1,     1,     2,     1,     3,     1,
       2,     1,     3,     1,     1,     1,     1,     2,     1,     3,
       1,     2,     1,     3,     1,     1,     1,     1,     2,     1,
       3,     1,     2,     4,     3,     1,     1,     1,     1,     2,
       1,     3,     1,     2,     4,     3,     1,     1,     1,     1,
       2,     1,     3,     1,     2,     4,     3,     1,     1,     1,
       1,     2,     1,     3,     1,     1,     2,     3,     1,     1,
       0,     2,     1,     1,     1,     2,     1,     0,     3,     1,
       1,     0,     2,     1,     1,     1,     1,     1,     1,     3,
       4,     0,     3,     1,     1,     0,     1,     1,     1,     1,
       3,     6,     0,     3,     1,     1,     1,     1,     2,     1,
       3,     1,     1,     2,     3,     1,     1,     0,     2,     1,
       1,     1,     2,     1,     0,     3,     1,     1,     1,     1,
       2,     1,     3,     1,     1,     2,     3,     1,     1,     0,
       2,     1,     1,     1,     2,     1,     0,     2,     1,     1,
       1,     1,     3,     6,     0,     3,     1,     1,     1,     1,
       1,     3,     1,     0,     3,     1,     1,     1,     1,     1,
       3,     1,     0,     3,     1,     1,     1,     1,     1,     3,
       1,     0,     3,     1,     1,     1,     1,     1,     3,     1,
       0,     3,     1,     1,     1,     1,     1,     3,     1,     0,
       3,     1,     1,     1,     1,     1,     3,     1,     0,     3,
       1,     1,     1,     1,     2,     1,     3,     1,     1,     2,
       3,     1,     1,     0,     2,     1,     1,     1,     2,     1,
       0,     3,     1,     4,     1,     1,     2,     1,     3,     1,
       2,     3,     1,     1,     0,     2,     1,     1,     1,     1,
       1,     2,     1,     3,     0,     2,     3,     1,     1,     0,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     2,     1,     3,     1,     1,     1,     2,     3,     1,
       1,     0,     2,     1,     1,     1,     1,     1,     1,     2,
       1,     0,     3,     1,     1,     0,     1,     1,     1,     1,
       3,     4,     0,     3,     1,     1,     1,     1,     2,     1,
       3,     1,     1,     2,     3,     1,     1,     0,     2,     1,
       1,     1,     2,     1,     0,     3,     1,     1,     1,     1,
       2,     1,     3,     1,     1,     2,     3,     1,     1,     0,
       2,     1,     1,     1,     1,     2,     1,     0,     2,     1,
       1,     1,     1,     3,     6,     0,     3,     1,     1,     1,
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
       2,     1,     0,     2,     1,     1,     1,     1,     3,     6,
       0,     3,     1,     1,     1,     1,     1,     3,     1,     0,
       3,     1,     1,     1,     1,     1,     3,     1,     0,     3,
       1,     1,     1,     1,     1,     3,     1,     0,     3,     1,
       1,     1,     1,     1,     3,     1,     0,     3,     1,     1,
       1,     1,     1,     3,     1,     0,     3,     1,     1,     1,
       1,     1,     3,     1,     0,     2,     3,     1,     1,     0,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     2,     1,     3,     1,     1,     1,     2,     3,     1,
       1,     0,     2,     1,     1,     1,     1,     1,     1,     2,
       1,     0,     3,     1,     1,     1,     1,     1,     3,     0,
       2,     3,     1,     1,     1,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     2,     1,     3,     1,     1,
       2,     1,     1,     1,     1,     1,     3,     1,     3,     1,
       1,     0,     2,     1,     1,     1,     3,     3,     3,     2,
       1,     1,     1,     1,     1,     3,     1,     1,     1,     1,
       3,     1,     4,     1,     1,     4,     1,     1,     1,     1,
       3,     1,     1,     1,     1,     4,     1,     1,     1,     1,
       3,     1,     1,     1,     1,     3,     1,     1,     4,     1,
       1,     1,     1,     3,     1,     1,     1,     1,     3,     1,
       1,     1,     1,     4,     1,     1,     1,     1,     3,     1,
       1,     1,     1,     3,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     1,     2,     3,     1,     1,     0,     2,     1,
       1,     1,     1,     1,     1,     3,     1,     1,     1,     0,
       2,     3,     1,     1,     0,     2,     1,     1,     3,     3,
       4,     1,     1,     2,     1,     3,     4,     4,     1,     1,
       2,     0,     2,     1,     1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       0,     5,     4,     0,    15,     6,     1,    17,    13,    58,
       0,     7,     0,    12,     2,    60,   187,     0,    23,    20,
      16,    18,    19,    15,    10,     3,     8,     9,   189,   257,
       0,     0,    64,    59,    61,    62,     0,    28,    27,     0,
      30,    24,    25,    26,    13,   259,   299,     0,     0,   193,
     188,   190,   191,    63,    81,    89,    97,   105,   116,   124,
     132,   140,   148,   156,   167,     0,    66,    67,    69,     0,
      70,     0,    71,     0,    72,   106,    73,     0,    74,     0,
      75,     0,    76,     0,    77,     0,    78,   157,    79,     0,
       0,    21,     0,    35,    34,    37,    31,    32,    33,    11,
     301,   497,     0,     0,   263,   258,   260,   261,   192,   237,
     204,   213,   222,   231,     0,   195,   196,   198,   206,   199,
     215,   200,   224,   201,   232,   202,     0,    65,    68,     0,
      85,    80,    82,    83,     0,    93,    88,    90,    91,     0,
     101,    96,    98,    99,     0,     0,   107,     0,   120,   115,
     117,   118,     0,   128,   123,   125,   126,     0,   136,   131,
     133,   134,     0,   144,   139,   141,   142,     0,   152,   147,
     149,   150,     0,     0,   158,  1191,     0,   168,    29,     0,
       0,    42,    41,    44,    38,    39,    40,   499,    14,   501,
       0,   305,   300,   302,   303,   262,   279,   271,     0,   265,
     266,   268,     0,   269,     0,   194,   197,     0,   205,     0,
     214,     0,   223,     0,  1079,     0,   233,  1076,  1077,  1078,
       0,   238,    87,    84,     0,    95,    92,     0,   103,   100,
       0,     0,     0,   112,   104,   109,   110,   122,   119,     0,
     130,   127,     0,   138,   135,     0,   146,   143,     0,   154,
     151,     0,     0,     0,   163,   155,   160,   161,     0,     0,
       0,   172,   166,   169,   170,    36,     0,     0,    49,    48,
      51,    45,    46,    47,     0,   500,   304,   477,   326,   337,
     345,   356,   367,   378,   389,   455,   444,   400,   411,   433,
     422,   466,     0,   307,   308,   310,   327,   311,     0,   312,
       0,   313,     0,   314,     0,   315,     0,   316,     0,   317,
       0,   318,     0,   320,     0,   319,     0,   321,     0,   322,
       0,   323,     0,   324,     0,   264,   267,     0,   275,   270,
     272,   273,     0,   280,     0,   203,     0,  1127,   207,   209,
     208,  1124,  1125,  1126,     0,   212,   216,   218,   217,     0,
     221,   225,   227,   226,  1191,     0,   230,     0,   242,   236,
     239,   240,    86,    94,   102,   108,   114,   111,     0,   121,
     129,   137,   145,   153,   159,   165,   162,     0,  1191,  1190,
    1193,  1194,  1195,  1196,  1192,   171,   178,     0,   174,   175,
     180,    43,     0,     0,    56,    55,    22,    52,    53,    54,
     511,   508,   498,   506,   507,  1191,  1191,  1191,   502,   504,
     505,   503,   306,   309,     0,   328,     0,   341,   336,   338,
     339,     0,     0,   346,     0,     0,   357,     0,   368,     0,
     379,     0,   390,     0,     0,   401,     0,   412,     0,   423,
       0,   434,     0,   445,     0,   456,     0,     0,   467,     0,
     478,   277,   274,     0,     0,   284,   278,   281,   282,  1188,
    1189,     0,   211,     0,     0,   220,     0,   229,  1080,   235,
       0,   241,   248,     0,   244,   245,   250,   113,   164,  1144,
     173,   176,     0,   179,    50,     0,   513,     0,   711,   515,
       0,     0,     0,     0,   332,   325,   329,   330,   343,   340,
       0,     0,     0,   350,   344,   347,   348,     0,     0,   361,
     355,   358,   359,     0,   372,   366,   369,   370,     0,   383,
     377,   380,   381,     0,   394,   388,   391,   392,     0,     0,
     405,   399,   402,   403,     0,   416,   410,   413,   414,     0,
     427,   421,   424,   425,     0,   438,   432,   435,   436,     0,
     449,   443,   446,   447,     0,   460,   454,   457,   458,     0,
       0,   471,   465,   468,   469,     0,   482,   476,   479,   480,
     276,   283,   290,     0,   286,   287,   292,   210,  1128,   219,
     228,   234,   243,   246,     0,   249,     0,   186,   177,     0,
       0,  1099,  1132,   181,   184,   182,  1096,  1097,  1098,   183,
    1129,  1130,  1131,    57,   509,   713,   866,   715,  1191,     0,
     514,   516,  1191,  1191,  1191,   331,     0,   334,   335,   342,
       0,     0,   349,     0,   352,     0,   360,     0,     0,   363,
     371,     0,     0,   374,     0,   382,     0,   385,     0,   393,
       0,   396,     0,  1059,   404,     0,   407,   409,  1061,   415,
       0,   418,   420,   426,     0,   429,   431,   437,     0,   440,
     442,     0,   448,     0,   451,     0,   459,     0,   462,     0,
     470,     0,     0,   473,   481,   488,     0,   484,   485,   490,
     285,   288,     0,   291,     0,   256,   247,   251,   254,   252,
     253,   185,  1191,     0,   868,  1021,   870,  1191,     0,   714,
     716,     0,   522,   519,   512,   517,   518,  1151,  1141,  1135,
     333,  1139,     0,   351,   353,  1147,     0,   362,   364,     0,
     373,   375,     0,   384,   386,     0,   395,   397,  1146,   406,
     408,     0,  1060,   417,   419,   428,   430,   439,   441,     0,
     450,   452,     0,   461,   463,  1148,     0,   472,   474,   483,
     486,     0,   489,     0,   298,   289,   293,   296,   294,   295,
     255,  1100,  1133,  1023,   510,     0,  1191,     0,   869,   871,
       0,   722,   719,   712,   717,   718,  1191,   524,     0,   544,
       0,     0,     0,     0,     0,     0,     0,  1070,  1058,     0,
       0,     0,  1062,  1063,  1064,  1065,     0,     0,     0,     0,
     496,   487,   491,   494,   492,   493,   297,  1191,     0,  1024,
       0,   877,   874,   867,   872,   873,  1191,   724,     0,   744,
       0,  1145,   520,   546,   566,     0,  1191,     0,   525,   354,
     365,   376,   387,   398,  1069,     0,     0,     0,   453,   464,
     475,   495,     0,  1029,  1027,  1022,  1025,  1026,  1191,   879,
       0,   899,     0,  1143,   720,   746,   767,     0,  1191,     0,
     725,   568,   628,     0,     0,   547,     0,     0,   529,   523,
     526,   527,  1066,  1067,  1068,  1191,     0,  1142,   875,   901,
     922,     0,  1191,     0,   880,   769,   829,     0,     0,   747,
       0,     0,   729,   723,   726,   727,   630,   650,     0,   574,
     571,   567,   569,   570,     0,   551,   545,   548,   549,  1191,
     528,   535,     0,   531,   532,   537,  1149,  1028,  1032,  1030,
       0,   924,   984,     0,     0,   902,     0,     0,   884,   878,
     881,   882,   721,   775,   772,   768,   770,   771,     0,   751,
     745,   748,   749,  1191,   728,   735,     0,   731,   732,   737,
     652,   674,     0,     0,   631,   576,     0,   583,     0,   557,
     550,     0,   553,   554,   559,  1150,   530,   533,     0,   536,
       0,     0,  1191,  1112,  1074,     0,  1104,     0,  1033,  1034,
    1039,  1071,  1072,  1073,  1041,  1036,  1038,  1101,  1102,  1103,
    1040,  1109,  1110,  1111,  1037,  1042,   876,   930,   927,   923,
     925,   926,     0,   906,   900,   903,   904,  1191,   883,   890,
       0,   886,   887,   892,   832,   830,   834,   777,     0,   784,
       0,   757,   750,     0,   753,   754,   759,  1140,   730,   733,
       0,   736,   521,     0,     0,     0,   635,   629,   632,   633,
     572,   585,   592,     0,  1191,     0,   577,   552,   555,     0,
     558,     0,   543,   534,  1191,   538,   539,  1083,  1084,   540,
     541,  1191,     0,     0,  1191,     0,  1046,  1031,  1043,  1044,
    1035,   987,   985,   989,   932,     0,   939,     0,   912,   905,
       0,   908,   909,   914,  1134,   885,   888,     0,   891,     0,
     833,   773,   786,   793,     0,     0,   778,   752,   755,     0,
     758,     0,   743,   734,   738,   739,   740,   741,   677,   675,
     679,     0,     0,   657,   651,   654,   655,   641,   634,     0,
     637,   638,   643,   594,   601,     0,     0,   586,     0,  1169,
     580,   575,   578,   579,     0,   565,   556,   560,   561,   562,
     563,   542,     0,  1075,  1113,  1191,  1105,  1045,  1055,     0,
    1054,     0,  1048,  1049,  1051,  1052,  1053,     0,   988,   928,
     941,   948,     0,     0,   933,   907,   910,     0,   913,     0,
     898,   889,   893,   894,   895,   896,     0,   847,   831,   844,
     845,  1191,   835,   841,   843,   838,   840,   842,   839,   837,
     836,   795,   802,     0,     0,   787,  1169,   781,   776,   779,
     780,     0,   766,   756,  1089,  1117,     0,     0,   760,   761,
     763,  1086,  1087,  1088,   762,   764,  1114,  1115,  1116,   742,
       0,   678,     0,   656,   662,     0,   659,   664,   636,   639,
       0,   642,   603,   610,     0,     0,   595,  1169,   589,   584,
     587,   588,  1191,     0,     0,   582,  1167,  1168,   564,  1191,
    1138,  1057,     0,  1047,  1050,     0,  1002,   986,   999,  1000,
     990,   996,   998,   993,   995,   997,   994,   991,   992,   950,
     957,     0,     0,   942,  1169,   936,   931,   934,   935,     0,
     921,   911,  1094,  1122,  1191,  1191,   915,   916,   918,  1091,
    1092,  1093,   917,   919,  1119,  1120,  1121,   897,   846,   854,
    1155,     0,   849,   851,   856,   850,  1152,  1157,     0,   804,
     811,     0,     0,   796,  1169,   790,   785,   788,   789,     0,
     783,   765,  1191,  1191,     0,   692,   676,   689,   690,   680,
     686,   688,   683,   685,   687,   684,   682,   681,   653,   658,
     660,     0,   663,     0,   649,   640,   644,   645,   646,   647,
     612,   619,     0,     0,   604,  1169,   598,   593,   596,   597,
       0,   591,  1136,  1191,     0,   581,  1172,  1170,  1174,  1085,
    1056,  1001,  1009,     0,  1004,  1006,  1011,  1005,   959,   966,
       0,     0,   951,  1169,   945,   940,   943,   944,     0,   938,
     920,     0,     0,   848,   852,     0,   855,  1153,     0,  1156,
    1191,   813,   820,     0,     0,   805,  1169,   799,   794,   797,
     798,     0,   792,   782,  1090,  1118,   691,   699,     0,   694,
     696,   701,   695,     0,   672,   661,   669,   670,     0,  1191,
     665,   668,  1081,   666,  1106,  1107,   667,   648,   621,   573,
       0,     0,   613,  1169,   607,   602,   605,   606,     0,   600,
     590,     0,     0,  1184,  1179,  1181,  1182,     0,  1173,  1003,
    1007,     0,  1010,   968,   975,     0,     0,   960,  1169,   954,
     949,   952,   953,     0,   947,   937,  1191,  1191,     0,   865,
     853,   863,   857,   858,   861,   859,   862,   860,  1169,  1164,
    1154,  1162,  1163,  1161,  1160,  1159,  1158,  1137,   822,   774,
       0,     0,   814,  1169,   808,   803,   806,   807,     0,   801,
     791,   693,   697,     0,   700,   671,     0,     0,     0,     0,
     622,  1169,   616,   611,   614,   615,     0,   609,   599,  1191,
       0,  1183,     0,  1171,  1191,  1191,  1175,  1177,  1176,     0,
    1020,  1008,  1018,  1012,  1013,  1016,  1014,  1017,  1015,   977,
     929,     0,     0,   969,  1169,   963,   958,   961,   962,     0,
     956,   946,  1095,  1123,   864,     0,  1166,     0,   823,  1169,
     817,   812,   815,   816,     0,   810,   800,     0,   710,   698,
     708,   702,   703,   706,   704,   707,   705,   673,     0,  1191,
    1169,   625,   620,   623,   624,     0,   618,   608,  1180,  1185,
       0,     0,     0,  1019,     0,   978,  1169,   972,   967,   970,
     971,     0,   965,   955,  1165,  1169,   826,   821,   824,   825,
       0,   819,   809,   709,  1082,  1108,     0,   627,   617,  1178,
    1191,  1191,  1169,   981,   976,   979,   980,     0,   974,   964,
       0,   828,   818,   626,  1186,  1187,     0,   983,   973,   827,
     982
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     3,     4,     5,    12,    25,    26,    27,    14,     8,
       9,    10,    20,    21,    22,    39,    40,    41,    42,    43,
      95,    96,    97,    98,   183,   184,   185,   186,   270,   271,
     272,   273,   396,   397,   398,   399,    16,    17,    33,    34,
      35,    65,    66,    67,    68,    69,   131,   132,   133,   224,
      70,    71,   136,   137,   138,   227,    72,    73,   141,   142,
     143,   230,    74,    75,   145,   146,   234,   235,   236,   368,
      76,    77,   149,   150,   151,   239,    78,    79,   154,   155,
     156,   242,    80,    81,   159,   160,   161,   245,    82,    83,
     164,   165,   166,   248,    84,    85,   169,   170,   171,   251,
      86,    87,   173,   174,   255,   256,   257,   377,    88,    89,
     176,   262,   263,   264,   387,   388,   389,   390,   482,   483,
     593,   588,    29,    30,    50,    51,    52,   114,   115,   116,
     117,   118,   207,   208,   338,   335,   461,   119,   120,   209,
     210,   346,   345,   464,   121,   122,   211,   212,   351,   350,
     466,   123,   124,   215,   356,   470,   125,   126,   220,   359,
     360,   361,   473,   474,   475,   476,   584,   585,   687,   686,
      46,    47,   105,   106,   107,   198,   199,   200,   201,   202,
     329,   330,   331,   453,   203,   204,   332,   456,   457,   458,
     573,   574,   575,   576,   682,   683,   756,   755,   101,   102,
     192,   193,   194,   292,   293,   294,   295,   296,   414,   495,
     496,   497,   616,   617,   297,   298,   418,   419,   420,   500,
     299,   300,   422,   504,   505,   506,   623,   624,   301,   302,
     425,   510,   511,   512,   628,   629,   303,   304,   427,   515,
     516,   517,   632,   633,   305,   306,   429,   520,   521,   522,
     636,   637,   307,   308,   431,   525,   526,   527,   640,   641,
     309,   310,   434,   531,   532,   533,   645,   646,   311,   312,
     436,   536,   537,   538,   650,   651,   313,   314,   438,   541,
     542,   543,   654,   655,   315,   316,   440,   546,   547,   548,
     658,   659,   317,   318,   442,   551,   552,   553,   663,   664,
     319,   320,   444,   556,   557,   558,   667,   668,   321,   322,
     447,   562,   563,   564,   672,   673,   323,   324,   449,   567,
     568,   569,   676,   677,   678,   679,   751,   752,   802,   801,
     188,   189,   274,   275,   408,   402,   403,   404,   487,   488,
     489,   609,   610,   704,   705,   706,   778,   779,   780,   827,
     869,   870,   871,   912,   913,   914,   915,   968,   969,  1055,
    1053,   824,   825,   864,   906,   907,   908,   961,   962,   963,
     964,  1049,  1050,  1137,  1136,   862,   863,   901,   902,   903,
     956,   957,   958,  1045,  1131,  1132,  1133,  1244,  1042,  1043,
    1126,  1239,  1240,  1241,  1360,  1124,  1125,  1235,  1357,  1358,
    1359,  1448,  1233,  1234,  1353,  1445,  1446,  1447,  1526,  1351,
    1352,  1441,  1523,  1524,  1525,  1595,  1439,  1440,  1519,  1592,
    1593,  1594,  1626,   897,   898,   953,  1037,  1038,  1039,  1119,
    1120,  1121,  1122,  1230,  1231,  1346,  1345,   951,   952,  1034,
    1114,  1115,  1116,  1225,  1226,  1227,  1341,  1342,  1430,  1425,
    1426,  1427,  1032,  1109,  1110,  1220,  1221,  1329,  1326,  1327,
    1328,  1418,  1419,  1420,  1421,  1513,  1514,  1581,  1579,  1580,
     606,   607,   698,   699,   773,   774,   775,   818,   819,   820,
     859,   893,   894,   895,   946,   947,   948,   949,  1030,  1031,
    1104,  1103,   856,   857,   888,   940,   941,   942,  1023,  1024,
    1025,  1026,  1099,  1100,  1208,  1203,   886,   887,   935,   936,
     937,  1018,  1019,  1020,  1095,  1198,  1199,  1200,  1319,  1093,
    1094,  1194,  1316,  1317,  1318,  1411,  1192,  1193,  1312,  1408,
    1409,  1410,  1508,  1310,  1311,  1404,  1505,  1506,  1507,  1574,
    1402,  1403,  1501,  1571,  1572,  1573,  1620,  1499,  1500,  1567,
    1617,  1618,  1619,  1640,   932,  1015,  1016,  1089,  1090,  1182,
    1178,  1179,  1180,  1301,  1302,  1303,  1304,  1395,  1396,  1482,
    1480,  1481,   695,   696,   767,   768,   813,   814,   815,   850,
     851,   852,   883,   929,   930,   931,  1010,  1011,  1012,  1013,
    1087,  1088,  1172,  1171,   880,   881,   924,  1004,  1005,  1006,
    1080,  1081,  1082,  1083,  1167,  1168,  1286,  1281,   922,   923,
     999,  1000,  1001,  1075,  1076,  1077,  1163,  1276,  1277,  1278,
    1388,  1161,  1162,  1272,  1385,  1386,  1387,  1473,  1270,  1271,
    1381,  1470,  1471,  1472,  1559,  1379,  1380,  1466,  1556,  1557,
    1558,  1611,  1464,  1465,  1552,  1608,  1609,  1610,  1637,  1550,
    1551,  1604,  1634,  1635,  1636,  1646,   996,  1072,  1073,  1157,
    1158,  1260,  1257,  1258,  1259,  1373,  1374,  1375,  1376,  1461,
    1462,  1543,  1541,  1542,   764,   765,   808,   845,   846,   847,
     876,   919,   920,   977,   978,   979,  1067,  1068,  1069,  1151,
    1152,  1153,  1154,  1155,  1156,  1252,   647,   648,   731,   732,
     792,   793,   794,   795,   788,   980,   981,   982,   983,   984,
     217,   218,   219,  1431,  1432,  1056,  1057,  1058,  1210,  1211,
    1212,  1213,  1288,  1289,  1290,  1291,   985,   596,   597,   598,
     986,   987,   988,   989,  1433,  1434,  1435,   990,   991,   992,
     993,  1215,  1216,  1217,  1218,  1293,  1294,  1295,  1296,   340,
     341,   342,   343,   994,   600,   601,   602,   884,   409,  1046,
    1189,   995,   423,   860,   410,   769,   700,   177,   611,   435,
     426,   448,   809,   828,   411,  1305,  1306,  1307,  1398,  1399,
    1496,  1490,  1491,  1492,  1565,  1245,  1246,  1367,  1368,  1457,
    1458,  1536,  1533,  1247,  1364,  1454,  1455,  1456,  1537,  1538,
     462,   258,   259,   384
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -1361
static const yytype_int16 yypact[] =
{
     332, -1361, -1361,    23,     2,    85, -1361, -1361,   108,    95,
     360, -1361,   376, -1361, -1361, -1361,   103,   435,   117, -1361,
   -1361, -1361, -1361,     2, -1361, -1361, -1361, -1361, -1361,    93,
     437,   204, -1361, -1361, -1361, -1361,   183, -1361, -1361,   122,
     144, -1361, -1361, -1361,   108, -1361,   139,   441,    -5, -1361,
   -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361,
   -1361, -1361, -1361, -1361, -1361,   134,   291, -1361, -1361,   444,
   -1361,   446, -1361,   450, -1361,   174, -1361,   453, -1361,   457,
   -1361,   459, -1361,   465, -1361,   467, -1361,   177, -1361,   231,
     175, -1361,   274, -1361, -1361,   163, -1361, -1361, -1361, -1361,
   -1361,   206,   469,   -25, -1361, -1361, -1361, -1361, -1361, -1361,
   -1361, -1361, -1361, -1361,   209,   138, -1361, -1361, -1361, -1361,
   -1361, -1361, -1361, -1361,    79, -1361,   231, -1361, -1361,    33,
   -1361, -1361, -1361, -1361,    30, -1361, -1361, -1361, -1361,    52,
   -1361, -1361, -1361, -1361,   282,   471, -1361,    35, -1361, -1361,
   -1361, -1361,    27, -1361, -1361, -1361, -1361,    26, -1361, -1361,
   -1361, -1361,    28, -1361, -1361, -1361, -1361,    25, -1361, -1361,
   -1361, -1361,   288,   473, -1361, -1361,   492, -1361, -1361,   205,
     292, -1361, -1361,   242, -1361, -1361, -1361, -1361, -1361, -1361,
     129, -1361, -1361, -1361, -1361, -1361, -1361, -1361,   219,   -55,
   -1361, -1361,   495, -1361,   231, -1361, -1361,   289,   165,   298,
     165,   300,   165,   309, -1361,   306, -1361, -1361, -1361, -1361,
     497, -1361, -1361, -1361,   201, -1361, -1361,   218, -1361, -1361,
     214,   318,    29, -1361, -1361, -1361, -1361, -1361, -1361,   222,
   -1361, -1361,   248, -1361, -1361,   250, -1361, -1361,   252, -1361,
   -1361,   265,   356,    16, -1361, -1361, -1361, -1361,   385,     4,
     392, -1361, -1361, -1361, -1361, -1361,   311,   396, -1361, -1361,
     277, -1361, -1361, -1361,   504,   397, -1361, -1361, -1361, -1361,
   -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361,
   -1361, -1361,   321,   425, -1361, -1361,    56, -1361,   506, -1361,
     389, -1361,   390, -1361,   390, -1361,   390, -1361,   390, -1361,
     393, -1361,   393, -1361,   393, -1361,   393, -1361,   390, -1361,
     390, -1361,   394, -1361,   231, -1361, -1361,    12, -1361, -1361,
   -1361, -1361,   508, -1361,   516, -1361,   416, -1361, -1361, -1361,
   -1361, -1361, -1361, -1361,   516, -1361, -1361, -1361, -1361,   516,
   -1361, -1361, -1361, -1361, -1361,   427, -1361,   405, -1361, -1361,
   -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361,   325, -1361,
   -1361, -1361, -1361, -1361, -1361, -1361, -1361,   322, -1361, -1361,
   -1361, -1361, -1361, -1361, -1361, -1361, -1361,   329,   338, -1361,
   -1361, -1361,   379,   482, -1361, -1361, -1361, -1361, -1361, -1361,
     333, -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361,
   -1361, -1361, -1361, -1361,   519, -1361,    10, -1361, -1361, -1361,
   -1361,   501,   521, -1361,   512,   523, -1361,   527, -1361,   529,
   -1361,   531, -1361,   541,   535, -1361,   537, -1361,   542, -1361,
     546, -1361,   557, -1361,   580, -1361,   551,   582, -1361,   584,
   -1361, -1361, -1361,   395,   476, -1361, -1361, -1361, -1361, -1361,
   -1361,   368, -1361,   553,   409, -1361,   415, -1361, -1361, -1361,
     424, -1361, -1361,   445,   452, -1361, -1361, -1361, -1361, -1361,
   -1361, -1361,   588,   254, -1361,   479, -1361,   493,   384,   544,
     575,   577,   579,    19, -1361, -1361, -1361, -1361, -1361, -1361,
     451,   600,   -60, -1361, -1361, -1361, -1361,   609,    78, -1361,
   -1361, -1361, -1361,   458, -1361, -1361, -1361, -1361,   -22, -1361,
   -1361, -1361, -1361,    18, -1361, -1361, -1361, -1361,   670,   -85,
   -1361, -1361, -1361, -1361,   -49, -1361, -1361, -1361, -1361,   -87,
   -1361, -1361, -1361, -1361,   -90, -1361, -1361, -1361, -1361,   -56,
   -1361, -1361, -1361, -1361,    15, -1361, -1361, -1361, -1361,   733,
     438, -1361, -1361, -1361, -1361,   484, -1361, -1361, -1361, -1361,
   -1361, -1361, -1361,   636,   578, -1361, -1361, -1361, -1361, -1361,
   -1361, -1361, -1361, -1361,   601,   254,   635, -1361, -1361,   755,
     756, -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361,
   -1361, -1361, -1361, -1361, -1361, -1361,   558,   726, -1361,   603,
   -1361, -1361, -1361, -1361, -1361, -1361,   628, -1361, -1361, -1361,
     757,   753, -1361,   -57, -1361,   758, -1361,   754,   182, -1361,
   -1361,   759,   474, -1361,   760, -1361,    98, -1361,   761, -1361,
      34, -1361,   764, -1361, -1361,   -28, -1361, -1361, -1361, -1361,
     -42, -1361, -1361, -1361,   -79, -1361, -1361, -1361,   -48, -1361,
   -1361,   763, -1361,   -24, -1361,   765, -1361,    20, -1361,   766,
   -1361,   767,   456, -1361, -1361, -1361,   647,   655, -1361, -1361,
   -1361, -1361,   612,   254,   657, -1361, -1361, -1361, -1361, -1361,
   -1361, -1361, -1361,   770, -1361,   569,   746, -1361,   614, -1361,
   -1361,   762,   613, -1361, -1361, -1361, -1361, -1361, -1361, -1361,
   -1361, -1361,   779, -1361, -1361, -1361,   780, -1361, -1361,   781,
   -1361, -1361,   782, -1361, -1361,   783, -1361, -1361, -1361, -1361,
   -1361,   616,   421, -1361, -1361, -1361, -1361, -1361, -1361,   784,
   -1361, -1361,   785, -1361, -1361, -1361,   786, -1361, -1361, -1361,
   -1361,   618,   254,   672, -1361, -1361, -1361, -1361, -1361, -1361,
   -1361, -1361, -1361, -1361, -1361,   768, -1361,   620, -1361, -1361,
     787,   595, -1361, -1361, -1361, -1361, -1361, -1361,   630,   622,
     769,   689,   659,   661,   663,   665,   653, -1361, -1361,   797,
     798,   799, -1361, -1361, -1361, -1361,   666,   667,   638,   686,
   -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361,   623, -1361,
     806,   608, -1361, -1361, -1361, -1361, -1361, -1361,   619,   615,
     776, -1361, -1361, -1361,   642,   769, -1361,   625, -1361, -1361,
   -1361, -1361, -1361, -1361, -1361,   810,   811,   812, -1361, -1361,
   -1361, -1361,   815, -1361, -1361, -1361, -1361, -1361, -1361, -1361,
     621,   617,   789, -1361, -1361, -1361,   648,   776, -1361,   627,
   -1361, -1361,   633,   629,   631, -1361,   818,   475, -1361, -1361,
   -1361, -1361, -1361, -1361, -1361, -1361,   431, -1361, -1361, -1361,
     668,   789, -1361,   637, -1361, -1361, -1361,   639,   641, -1361,
     823,   460, -1361, -1361, -1361, -1361, -1361,   640,   769,   674,
   -1361, -1361, -1361, -1361,   240, -1361, -1361, -1361, -1361, -1361,
   -1361, -1361,   676,   677, -1361, -1361, -1361, -1361, -1361, -1361,
     176, -1361, -1361,   644,   646, -1361,   824,   454, -1361, -1361,
   -1361, -1361,   712,   678, -1361, -1361, -1361, -1361,   216, -1361,
   -1361, -1361, -1361, -1361, -1361, -1361,   634,   643, -1361, -1361,
   -1361, -1361,   805,   652, -1361, -1361,   680,   679,   795, -1361,
   -1361,   684,   682, -1361, -1361, -1361, -1361, -1361,   654,   341,
     833,   834, -1361, -1361, -1361,   835, -1361,   656,   176, -1361,
   -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361,
   -1361, -1361, -1361, -1361, -1361, -1361,   718,   688, -1361, -1361,
   -1361, -1361,   210, -1361, -1361, -1361, -1361, -1361, -1361, -1361,
     651,   645, -1361, -1361, -1361, -1361, -1361, -1361,   690,   692,
     795, -1361, -1361,   694,   650, -1361, -1361, -1361, -1361, -1361,
     658,   341,   720,   832,   660,  -117, -1361, -1361, -1361, -1361,
   -1361, -1361,   695,   795, -1361,   662, -1361, -1361, -1361,   664,
     341,   696, -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361,
   -1361, -1361,   836,   839, -1361,   -38, -1361, -1361, -1361, -1361,
   -1361, -1361, -1361, -1361, -1361,   699,   697,   795, -1361, -1361,
     649,   700, -1361, -1361, -1361, -1361, -1361,   669,   341,   671,
     145, -1361, -1361,   702,   795,   673, -1361, -1361, -1361,   675,
     286,   704, -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361,
   -1361,   841,   496, -1361, -1361, -1361, -1361, -1361, -1361,   708,
     706, -1361, -1361, -1361,   714,   795,   681, -1361,   844,   716,
   -1361, -1361, -1361, -1361,   710, -1361, -1361, -1361, -1361, -1361,
   -1361, -1361,   848, -1361, -1361, -1361, -1361, -1361, -1361,   856,
   -1361,   722,   132, -1361, -1361, -1361, -1361,   683,   307, -1361,
   -1361,   723,   795,   685, -1361, -1361, -1361,   687,   319,   724,
   -1361, -1361, -1361, -1361, -1361, -1361,   -84, -1361, -1361, -1361,
   -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361,
   -1361, -1361,   728,   795,   691, -1361,   716, -1361, -1361, -1361,
   -1361,   729, -1361, -1361, -1361, -1361,   859,   860, -1361, -1361,
   -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361,
     693,   449,   861, -1361, -1361,   513, -1361, -1361, -1361, -1361,
     698,   341, -1361,   731,   795,   701, -1361,   716, -1361, -1361,
   -1361, -1361, -1361,   730,   739, -1361,   735, -1361, -1361, -1361,
   -1361, -1361,   737, -1361, -1361,   -50, -1361, -1361, -1361, -1361,
   -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361,
     740,   795,   703, -1361,   716, -1361, -1361, -1361, -1361,   741,
   -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361,
   -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361,
   -1361,   745,   743, -1361, -1361,   747, -1361, -1361,   858, -1361,
     750,   795,   705, -1361,   716, -1361, -1361, -1361, -1361,   748,
   -1361, -1361, -1361, -1361,   -76, -1361, -1361, -1361, -1361, -1361,
   -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361,
   -1361,   707,    31,   749, -1361, -1361, -1361, -1361, -1361, -1361,
   -1361,   751,   795,   709, -1361,   716, -1361, -1361, -1361, -1361,
     752, -1361, -1361, -1361,   711, -1361, -1361, -1361, -1361, -1361,
   -1361, -1361, -1361,   771,   772, -1361, -1361,   747, -1361,   774,
     795,   713, -1361,   716, -1361, -1361, -1361, -1361,   773, -1361,
   -1361,   516,   516, -1361, -1361,   715,   382, -1361,   717,   199,
   -1361, -1361,   777,   795,   719, -1361,   716, -1361, -1361, -1361,
   -1361,   778, -1361, -1361, -1361, -1361, -1361, -1361,   775,   788,
   -1361, -1361,   747,  -112, -1361, -1361, -1361, -1361,   862, -1361,
   -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361,
     795,   721, -1361,   716, -1361, -1361, -1361, -1361,   791, -1361,
   -1361,   865,     9, -1361, -1361, -1361, -1361,   866,   510, -1361,
   -1361,   725,   382, -1361,   790,   795,   727, -1361,   716, -1361,
   -1361, -1361, -1361,   792, -1361, -1361, -1361, -1361,   793, -1361,
   -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361,   716, -1361,
   -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361,
     795,   732, -1361,   716, -1361, -1361, -1361, -1361,   796, -1361,
   -1361, -1361, -1361,   734,   382, -1361,  -110,   516,   873,   736,
   -1361,   716, -1361, -1361, -1361, -1361,   794, -1361, -1361, -1361,
     800, -1361,   874, -1361, -1361, -1361, -1361, -1361, -1361,   802,
   -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361,
   -1361,   795,   738, -1361,   716, -1361, -1361, -1361, -1361,   803,
   -1361, -1361, -1361, -1361, -1361,   801, -1361,   742, -1361,   716,
   -1361, -1361, -1361, -1361,   804, -1361, -1361,   813, -1361, -1361,
   -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361,   864, -1361,
     716, -1361, -1361, -1361, -1361,   807, -1361, -1361, -1361, -1361,
     808,   877,   878, -1361,   744, -1361,   716, -1361, -1361, -1361,
   -1361,   809, -1361, -1361, -1361,   716, -1361, -1361, -1361, -1361,
     814, -1361, -1361, -1361, -1361, -1361,   816, -1361, -1361, -1361,
   -1361, -1361,   716, -1361, -1361, -1361, -1361,   817, -1361, -1361,
     819, -1361, -1361, -1361, -1361, -1361,   820, -1361, -1361, -1361,
   -1361
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
   -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361,   842,   867,
   -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361,
   -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361,
   -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361,
   -1361, -1361, -1361,   821, -1361, -1361, -1361, -1361, -1361, -1361,
   -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361,
   -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361,
   -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361,
   -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361,
   -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361,
   -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361,
   -1361, -1361, -1361, -1361, -1361, -1361,   503, -1361, -1361, -1361,
   -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361,   825,
   -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361,
   -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361,
   -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361,
   -1361, -1361, -1361, -1361,   411, -1361, -1361, -1361, -1361, -1361,
   -1361, -1361, -1361, -1361, -1361, -1361, -1361,   822, -1361, -1361,
   -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361,
   -1361, -1361,   315, -1361, -1361, -1361, -1361, -1361, -1361, -1361,
   -1361, -1361, -1361, -1361, -1361,   599, -1361, -1361, -1361, -1361,
   -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361,
   -1361, -1361, -1361, -1361, -1361, -1361, -1361,   271, -1361, -1361,
   -1361, -1361, -1361, -1361, -1361,   272, -1361, -1361, -1361, -1361,
   -1361, -1361, -1361,   269, -1361, -1361, -1361, -1361, -1361, -1361,
   -1361,   267, -1361, -1361, -1361, -1361, -1361, -1361, -1361,   266,
   -1361, -1361, -1361, -1361, -1361, -1361, -1361,   260, -1361, -1361,
   -1361, -1361, -1361, -1361, -1361,   258, -1361, -1361, -1361, -1361,
   -1361, -1361, -1361,   255, -1361, -1361, -1361, -1361, -1361, -1361,
   -1361,   253, -1361, -1361, -1361, -1361, -1361, -1361, -1361,   247,
   -1361, -1361, -1361, -1361, -1361, -1361, -1361,   245, -1361, -1361,
   -1361, -1361, -1361, -1361, -1361,   246, -1361, -1361, -1361, -1361,
   -1361, -1361, -1361, -1361,   243, -1361, -1361, -1361, -1361, -1361,
   -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361,
   -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361,
   -1361, -1361, -1361, -1361, -1361,    11, -1361, -1361, -1361, -1361,
   -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361,   -40,
   -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361,
   -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361,
   -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361,
   -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361,
   -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361,
   -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361,
    -500, -1111, -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361,
   -1361, -1361, -1361, -1361,  -298, -1361, -1361, -1361, -1361, -1361,
   -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361,
   -1361, -1361, -1361,  -491, -1361, -1361, -1361, -1361, -1361, -1361,
   -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361,
   -1361, -1361, -1361, -1361, -1361, -1361,   -12, -1361, -1361, -1361,
   -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361,
     -83, -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361,
   -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361,
   -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361,
   -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361,
   -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361,
   -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361,
   -1361, -1361, -1361, -1361, -1361,  -363, -1361, -1361, -1361, -1361,
   -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361,
   -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361,   -68, -1361,
   -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361,
   -1361, -1361,  -137, -1361, -1361, -1361, -1361, -1361, -1361, -1361,
   -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361,
   -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361,
   -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361,
   -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361,
   -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361,
   -1361, -1361, -1361, -1361, -1361, -1361, -1361,  -429, -1361, -1361,
   -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361,
   -1361, -1361, -1361, -1361, -1361,   -32, -1361, -1361, -1361, -1361,
   -1361,  -205, -1361, -1361, -1361, -1361,  -499, -1361, -1361, -1361,
   -1361, -1361, -1361, -1361, -1361, -1073, -1361, -1361, -1361,  -120,
   -1361, -1361, -1361, -1361, -1361, -1023, -1361, -1361, -1360, -1361,
   -1361, -1361, -1361, -1361, -1361, -1361,  -481, -1361, -1361, -1361,
   -1072, -1361, -1361, -1361, -1361, -1361, -1361, -1069, -1361, -1361,
   -1361, -1354, -1361, -1361, -1361, -1361, -1361, -1361, -1361,  -169,
   -1361, -1361, -1361,  -480, -1361, -1361, -1361,  -871, -1361, -1015,
   -1110, -1361, -1361,  -846, -1361, -1361, -1361,  -111, -1361,   -39,
    -133, -1361, -1361,  -818, -1361, -1211, -1286, -1361, -1361, -1361,
   -1361, -1361, -1361, -1361, -1361, -1174, -1361, -1361, -1361, -1361,
   -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361, -1361,
    -343,  -354, -1361, -1361
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint16 yytable[] =
{
     468,   465,   595,   599,   216,  1096,   467,   865,  1105,  1229,
     925,   889,   379,  1530,   498,   221,   451,  1183,  1186,  1397,
     375,  1187,  1320,     6,   479,   459,   460,  1138,  1127,   249,
     243,   240,   246,   366,   225,   652,  1484,   222,  1298,   237,
     656,   348,  1486,   353,  1377,   660,  1416,   621,  1268,   195,
     621,   490,   491,   492,  1117,   643,   228,  1428,   643,  1117,
     643,  1117,  1164,  1361,   196,  1173,   643,   108,   826,     7,
     657,   644,  1371,  1118,  1429,   653,   197,  1209,   622,  1195,
     954,   713,  1515,   735,  1587,  1261,  1264,   661,   339,  1265,
     347,  1397,   352,   333,   196,  1417,   643,   643,   662,    11,
    1389,   336,  1545,   643,   689,   690,   197,   337,  1547,   649,
    1236,  1336,   737,  1422,   109,  1299,   733,   643,   110,   661,
     111,   634,   112,    13,   113,   213,   635,   415,   729,   214,
     740,  1300,   226,   223,   376,   367,  1397,   241,   244,  1300,
    1412,   250,   247,   238,   452,  1287,   499,  1273,  1330,  1333,
     618,   652,  1334,   615,  1583,   656,   229,  1372,   665,   660,
    1585,   638,  1181,   665,    15,  1300,    45,   666,   639,   970,
     971,   428,   743,   430,    28,   432,  1147,   638,  1313,  1148,
    1149,  1449,  1150,   858,   726,   443,   589,   445,    90,   590,
      91,   213,   973,   591,   974,   214,    36,   592,    37,    38,
     970,   971,   758,   759,   127,   276,   975,   976,  1347,  1474,
     336,   213,   972,   450,   100,   214,   337,   589,   626,  1354,
     590,   627,   213,   973,   591,   974,   214,    92,   592,    93,
      94,  1531,  1509,   380,   381,   382,   383,   975,   976,  1044,
     144,   634,   172,   590,  1190,   213,   723,   175,   277,   214,
     180,   592,   181,   182,   701,   178,  1382,   109,   707,   708,
     709,   110,   278,   111,   279,   112,   280,   113,   281,  1527,
     282,   804,   805,   437,    53,   439,   283,   441,   284,   179,
     285,   205,   286,   187,   287,   231,   288,  1267,   289,   265,
     290,   252,   291,   325,  1560,   589,  1405,   266,   590,   334,
     213,   362,   591,    54,   214,    55,   592,    56,   344,    57,
     349,    58,   354,    59,  1566,    60,   355,    61,   364,    62,
     363,    63,   717,    64,  1181,   627,   365,   589,  1054,  1575,
     369,   970,   971,   267,   591,   268,   269,  1442,   761,  1204,
    1205,  1206,  1207,   770,     1,     2,   882,  1596,   589,  1148,
    1149,   590,  1150,   213,   973,   591,   974,   214,   370,   592,
     589,  1054,   371,   594,   374,  1467,   372,   591,   975,   976,
      18,    19,   393,  1483,   394,   395,  1282,  1283,  1284,  1285,
    1612,   373,   589,  1054,  1495,   590,    23,    24,  1502,   591,
      54,   378,    55,   592,    56,  1621,    57,   412,    58,   391,
      59,   392,    60,  1337,    61,  1229,    62,   421,    63,   424,
      64,   959,   810,   433,   960,  1021,  1627,  1078,  1022,   463,
    1079,   446,   821,   589,  1054,  1520,   590,   405,   406,   407,
     591,   477,  1638,   469,   592,  1204,  1205,  1206,  1207,  1544,
     478,  1641,   789,   790,   791,    31,    32,    48,    49,   480,
    1553,   103,   104,   842,   129,   130,   134,   135,  1647,   386,
     139,   140,   853,   147,   148,   688,  1181,   152,   153,   157,
     158,   484,   866,   970,   971,   162,   163,   167,   168,   190,
     191,   232,   233,   253,   254,  1568,   826,   485,  1059,  1060,
     589,  1582,   577,   590,   877,   213,   973,   591,   974,   214,
     486,   592,   260,   261,   890,   327,   328,   357,   358,   501,
     975,   976,   385,   386,   400,   401,   416,   417,   454,   455,
     507,   916,   459,   460,  1436,   471,   472,   570,   926,   493,
     494,   502,   503,   508,   509,   579,  1605,   513,   514,   518,
     519,   523,   524,   580,   277,   529,   530,   534,   535,   528,
    1106,  1107,   539,   540,   581,   965,   544,   545,   278,   559,
     279,   578,   280,   757,   281,   582,   282,   549,   550,  1139,
    1140,   604,   283,   472,   284,   603,   285,   608,   286,   605,
     287,   612,   288,   613,   289,   614,   290,   619,   291,  1027,
     554,   555,   560,   561,   565,   566,   571,   572,   586,   587,
     630,   631,   670,   671,   674,   675,   620,  1174,  1175,  1185,
    1188,   684,   685,   702,   703,   625,   720,   631,  1063,  1214,
     747,   671,   753,   754,   771,   772,   786,   787,   799,   800,
     811,   812,   803,   843,   844,   867,   868,   891,   892,   899,
     900,   904,   905,   917,   918,   910,   911,   927,   928,   933,
     934,   938,   939,  1084,   997,   998,  1002,  1003,   944,   945,
    1008,  1009,  1035,  1036,  1051,  1052,  1065,  1066,  1101,  1102,
    1112,  1113,  1129,  1130,  1134,  1135,   642,  1263,  1266,  1169,
    1170,  1176,  1177,  1196,  1197,  1201,  1202,  1292,  1223,  1224,
    1128,  1237,  1238,  1255,  1256,  1274,  1275,  1279,  1280,   572,
    1142,  1314,  1315,  1324,  1325,  1339,  1224,  1143,  1343,  1344,
    1146,  1355,  1356,  1383,  1384,  1406,  1407,  1423,  1424,  1443,
    1444,  1452,  1453,  1468,  1469,  1478,  1479,  1488,  1489,  1503,
    1504,  1521,  1522,  1534,  1535,  1539,  1540,  1554,  1555,   669,
    1332,  1335,  1569,  1570,  1577,  1578,  1590,  1591,  1606,  1607,
    1348,  1349,  1615,  1616,  1632,  1633,   680,   691,   692,   693,
     697,   694,   710,   712,   716,   711,   715,   749,   776,   719,
     722,   725,   728,   739,   745,   742,   675,   746,   762,   760,
     763,   766,   777,   781,   782,   783,   784,   785,   796,   797,
     798,  1250,   817,   816,   806,   823,   807,   829,   822,   834,
     835,   836,   837,   830,   840,   831,   826,   832,   841,   833,
     838,   839,   848,   849,   858,   854,   855,   861,   872,   873,
     874,   875,   896,   885,   909,   878,   879,  1308,   882,   943,
    1007,   950,  1028,  1014,  1033,  1044,  1061,  1062,  1064,  1071,
    1111,  1108,   945,   921,  1144,  1145,   966,  1222,   911,  1021,
    1242,   955,  1009,   959,  1249,  1017,  1040,  1085,  1047,  1165,
    1041,  1251,  1322,  1323,  1400,  1074,  1091,  1393,  1141,  1338,
    1517,  1529,  1624,  1092,  1123,  1159,  1532,  1117,  1160,  1589,
    1600,  1191,  1248,  1630,  1631,   583,    99,   128,  1362,   681,
      44,   481,   413,  1459,   714,  1369,  1097,  1511,  1228,  1232,
     718,   721,  1269,   724,  1219,   730,   727,  1078,   734,   736,
     741,   738,   744,  1309,  1350,  1485,  1487,  1365,   748,  1494,
     750,  1437,  1048,  1516,   967,  1378,  1413,  1340,  1512,  1321,
    1391,  1392,  1297,  1401,  1450,  1029,  1253,  1243,  1438,  1394,
     206,  1098,  1299,  1086,  1166,  1460,  1070,  1254,     0,  1390,
       0,  1475,     0,     0,     0,  1363,  1370,  1463,     0,  1417,
    1510,  1366,  1300,     0,  1498,     0,     0,     0,  1414,  1415,
    1184,  1528,     0,     0,  1561,     0,  1576,  1549,     0,  1372,
    1597,  1546,  1548,  1613,     0,  1623,     0,     0,     0,     0,
    1622,  1628,     0,  1564,     0,  1639,     0,     0,  1642,     0,
       0,  1648,     0,     0,  1643,     0,     0,  1649,  1650,  1451,
    1603,     0,     0,     0,     0,     0,     0,  1614,     0,     0,
       0,   326,  1599,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1584,  1586,  1629,     0,     0,  1262,     0,
       0,     0,     0,     0,     0,     0,  1497,     0,  1476,  1477,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1518,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1331,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1562,  1563,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1588,  1598,     0,     0,     0,     0,
    1601,  1602,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1625,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1644,  1645,     0,  1493
};

static const yytype_int16 yycheck[] =
{
     354,   344,   483,   483,   124,  1020,   349,   825,  1031,  1120,
     881,   857,     8,     4,     4,   126,     4,  1090,  1090,  1305,
       4,  1090,  1196,     0,   378,     6,     7,  1050,  1043,     4,
       4,     4,     4,     4,     4,   534,  1396,     4,   122,     4,
     539,   210,  1396,   212,  1255,   544,   122,   107,  1158,    74,
     107,   405,   406,   407,   171,   145,     4,    26,   145,   171,
     145,   171,  1077,  1237,   119,  1088,   145,    72,    37,    67,
     160,   156,   122,   190,    43,   162,   131,  1100,   138,  1094,
     898,   138,   194,   162,   194,  1158,  1158,   143,   208,  1158,
     210,  1377,   212,   204,   119,   171,   145,   145,   154,    14,
    1274,    45,  1462,   145,   585,   585,   131,    51,  1462,   158,
    1125,  1221,   160,  1324,   119,   199,   158,   145,   123,   143,
     125,   143,   127,    15,   129,    46,   148,   296,   156,    50,
     154,   215,   102,   100,   118,   106,  1422,   110,   112,   215,
    1314,   116,   114,   108,   132,  1168,   136,  1162,  1221,  1221,
     493,   650,  1221,   134,  1514,   654,   104,   207,   143,   658,
    1514,   143,    17,   143,    69,   215,    73,   152,   150,    24,
      25,   304,   152,   306,    71,   308,   214,   143,  1193,   217,
     218,  1355,   220,    38,   150,   318,    41,   320,     5,    44,
      68,    46,    47,    48,    49,    50,    79,    52,    81,    82,
      24,    25,   683,   683,    70,    76,    61,    62,  1231,  1383,
      45,    46,    36,   324,    75,    50,    51,    41,   140,  1234,
      44,   143,    46,    47,    48,    49,    50,    83,    52,    85,
      86,   222,  1406,   229,   230,   231,   232,    61,    62,    40,
      66,   143,    65,    44,  1090,    46,   148,    16,   119,    50,
      87,    52,    89,    90,   608,    80,  1271,   119,   612,   613,
     614,   123,   133,   125,   135,   127,   137,   129,   139,  1443,
     141,   752,   752,   312,    70,   314,   147,   316,   149,     5,
     151,    72,   153,    77,   155,     3,   157,  1158,   159,    84,
     161,     3,   163,    74,  1468,    41,  1311,     5,    44,    10,
      46,   100,    48,    99,    50,   101,    52,   103,    10,   105,
      10,   107,     3,   109,  1488,   111,    10,   113,   104,   115,
     102,   117,   140,   119,    17,   143,     8,    41,    42,  1503,
     108,    24,    25,    91,    48,    93,    94,  1352,   692,    53,
      54,    55,    56,   697,    12,    13,    39,  1521,    41,   217,
     218,    44,   220,    46,    47,    48,    49,    50,   110,    52,
      41,    42,   112,   483,     8,  1380,   114,    48,    61,    62,
      10,    11,    95,  1396,    97,    98,    57,    58,    59,    60,
    1554,   116,    41,    42,  1399,    44,    10,    11,  1403,    48,
      99,     6,   101,    52,   103,  1569,   105,    76,   107,    88,
     109,     5,   111,  1221,   113,  1516,   115,    18,   117,    19,
     119,   171,   766,    20,   174,   199,  1590,   207,   202,     3,
     210,    27,   776,    41,    42,  1440,    44,    30,    31,    32,
      48,   106,  1606,     6,    52,    53,    54,    55,    56,  1462,
     118,  1615,    21,    22,    23,    10,    11,    10,    11,   120,
    1465,    10,    11,   807,    10,    11,    10,    11,  1632,   121,
      10,    11,   816,    10,    11,   585,    17,    10,    11,    10,
      11,    92,   826,    24,    25,    10,    11,    10,    11,    10,
      11,    10,    11,    10,    11,  1500,    37,     5,   969,   969,
      41,  1514,   124,    44,   848,    46,    47,    48,    49,    50,
     167,    52,    10,    11,   858,    10,    11,    10,    11,     8,
      61,    62,   120,   121,    10,    11,    10,    11,    10,    11,
       8,   875,     6,     7,  1342,   120,   121,   132,   882,    10,
      11,    10,    11,    10,    11,   126,  1551,    10,    11,    10,
      11,    10,    11,   128,   119,    10,    11,    10,    11,     8,
    1031,  1031,    10,    11,   130,   909,    10,    11,   133,     8,
     135,     8,   137,   683,   139,   120,   141,    10,    11,  1050,
    1050,    78,   147,   121,   149,    96,   151,    33,   153,   195,
     155,     6,   157,     6,   159,     6,   161,   136,   163,   943,
      10,    11,    10,    11,    10,    11,   120,   121,    10,    11,
     142,   143,   164,   165,   120,   121,     6,  1088,  1088,  1090,
    1090,    10,    11,    10,    11,     6,   142,   143,   972,  1100,
     164,   165,    10,    11,    10,    11,    10,    11,    10,    11,
      10,    11,   752,    10,    11,    10,    11,    10,    11,    10,
      11,    10,    11,   212,   213,   170,   171,    10,    11,    10,
      11,    10,    11,  1007,    10,    11,    10,    11,   198,   199,
     206,   207,    10,    11,    10,    11,    10,    11,    10,    11,
      10,    11,    10,    11,    10,    11,     6,  1158,  1158,    10,
      11,    10,    11,    10,    11,    10,    11,  1168,   192,   193,
    1044,    10,    11,    10,    11,    10,    11,    10,    11,   121,
    1054,    10,    11,    10,    11,   192,   193,  1061,    10,    11,
    1064,    10,    11,    10,    11,    10,    11,    10,    11,    10,
      11,    10,    11,    10,    11,    10,    11,    10,    11,    10,
      11,    10,    11,   223,   224,    10,    11,    10,    11,     6,
    1221,  1221,    10,    11,    10,    11,    10,    11,    10,    11,
    1231,  1231,    10,    11,    10,    11,   120,   122,     3,     3,
      34,   203,   134,    10,    10,     8,     8,   120,     6,    10,
      10,    10,     8,    10,     8,    10,   121,    10,     8,   122,
     211,    35,   169,     4,     4,     4,     4,     4,     4,     4,
       4,  1145,   197,     6,   122,   173,    28,   108,   168,   146,
       3,     3,     3,   144,   166,   144,    37,   144,   122,   144,
     144,   144,     6,   205,    38,   196,   201,   175,     8,     8,
       8,     6,   189,   175,     6,   204,   209,  1181,    39,     6,
       6,   191,   198,   121,    29,    40,     3,     3,     3,   121,
       8,   121,   199,   175,     8,     6,   170,     6,   171,   199,
       6,   177,   207,   171,     6,   177,   176,   206,   174,   210,
     181,     5,     3,     3,     6,   177,   176,   122,   172,     8,
       8,     6,     8,   181,   179,   176,    10,   171,   181,     6,
       6,   179,   172,     6,     6,   474,    44,    66,  1242,   574,
      23,   388,   293,   122,   623,  1249,   202,   122,   190,   185,
     628,   632,   179,   636,   200,   645,   640,   207,   650,   654,
     663,   658,   667,   185,   183,  1396,  1396,   178,   672,  1399,
     677,   172,   962,  1423,   913,   185,   178,  1225,  1419,   200,
    1284,  1285,   208,   183,   182,   947,   214,   221,   187,  1302,
     115,  1024,   199,  1011,  1081,  1374,   978,  1152,    -1,   208,
      -1,   178,    -1,    -1,    -1,   225,   219,   183,    -1,   171,
     182,   226,   215,    -1,   187,    -1,    -1,    -1,  1322,  1323,
    1090,   180,    -1,    -1,   182,    -1,   180,   187,    -1,   207,
     186,  1462,  1462,   180,    -1,   172,    -1,    -1,    -1,    -1,
     186,   184,    -1,   200,    -1,   186,    -1,    -1,   184,    -1,
      -1,   184,    -1,    -1,   188,    -1,    -1,   188,   188,  1363,
     208,    -1,    -1,    -1,    -1,    -1,    -1,   216,    -1,    -1,
      -1,   199,   222,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1514,  1514,   227,    -1,    -1,  1158,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1400,    -1,  1391,  1392,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1429,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1221,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1476,  1477,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1517,  1529,    -1,    -1,    -1,    -1,
    1534,  1535,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,  1589,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1630,  1631,    -1,  1399
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,    12,    13,   234,   235,   236,     0,    67,   242,   243,
     244,    14,   237,    15,   241,    69,   269,   270,    10,    11,
     245,   246,   247,    10,    11,   238,   239,   240,    71,   355,
     356,    10,    11,   271,   272,   273,    79,    81,    82,   248,
     249,   250,   251,   252,   242,    73,   403,   404,    10,    11,
     357,   358,   359,    70,    99,   101,   103,   105,   107,   109,
     111,   113,   115,   117,   119,   274,   275,   276,   277,   278,
     283,   284,   289,   290,   295,   296,   303,   304,   309,   310,
     315,   316,   321,   322,   327,   328,   333,   334,   341,   342,
       5,    68,    83,    85,    86,   253,   254,   255,   256,   241,
      75,   431,   432,    10,    11,   405,   406,   407,    72,   119,
     123,   125,   127,   129,   360,   361,   362,   363,   364,   370,
     371,   377,   378,   384,   385,   389,   390,    70,   276,    10,
      11,   279,   280,   281,    10,    11,   285,   286,   287,    10,
      11,   291,   292,   293,    66,   297,   298,    10,    11,   305,
     306,   307,    10,    11,   311,   312,   313,    10,    11,   317,
     318,   319,    10,    11,   323,   324,   325,    10,    11,   329,
     330,   331,    65,   335,   336,    16,   343,  1000,    80,     5,
      87,    89,    90,   257,   258,   259,   260,    77,   563,   564,
      10,    11,   433,   434,   435,    74,   119,   131,   408,   409,
     410,   411,   412,   417,   418,    72,   362,   365,   366,   372,
     373,   379,   380,    46,    50,   386,   942,   943,   944,   945,
     391,  1000,     4,   100,   282,     4,   102,   288,     4,   104,
     294,     3,    10,    11,   299,   300,   301,     4,   108,   308,
       4,   110,   314,     4,   112,   320,     4,   114,   326,     4,
     116,   332,     3,    10,    11,   337,   338,   339,  1034,  1035,
      10,    11,   344,   345,   346,    84,     5,    91,    93,    94,
     261,   262,   263,   264,   565,   566,    76,   119,   133,   135,
     137,   139,   141,   147,   149,   151,   153,   155,   157,   159,
     161,   163,   436,   437,   438,   439,   440,   447,   448,   453,
     454,   461,   462,   469,   470,   477,   478,   485,   486,   493,
     494,   501,   502,   509,   510,   517,   518,   525,   526,   533,
     534,   541,   542,   549,   550,    74,   410,    10,    11,   413,
     414,   415,   419,  1000,    10,   368,    45,    51,   367,   942,
     982,   983,   984,   985,    10,   375,   374,   942,   982,    10,
     382,   381,   942,   982,     3,    10,   387,    10,    11,   392,
     393,   394,   100,   102,   104,     8,     4,   106,   302,   108,
     110,   112,   114,   116,     8,     4,   118,   340,     6,     8,
     229,   230,   231,   232,  1036,   120,   121,   347,   348,   349,
     350,    88,     5,    95,    97,    98,   265,   266,   267,   268,
      10,    11,   568,   569,   570,    30,    31,    32,   567,   991,
     997,  1007,    76,   438,   441,   982,    10,    11,   449,   450,
     451,    18,   455,   995,    19,   463,  1003,   471,  1003,   479,
    1003,   487,  1003,    20,   495,  1002,   503,  1002,   511,  1002,
     519,  1002,   527,  1003,   535,  1003,    27,   543,  1004,   551,
    1000,     4,   132,   416,    10,    11,   420,   421,   422,     6,
       7,   369,  1033,     3,   376,  1033,   383,  1033,  1034,     6,
     388,   120,   121,   395,   396,   397,   398,   106,   118,  1034,
     120,   349,   351,   352,    92,     5,   167,   571,   572,   573,
    1034,  1034,  1034,    10,    11,   442,   443,   444,     4,   136,
     452,     8,    10,    11,   456,   457,   458,     8,    10,    11,
     464,   465,   466,    10,    11,   472,   473,   474,    10,    11,
     480,   481,   482,    10,    11,   488,   489,   490,     8,    10,
      11,   496,   497,   498,    10,    11,   504,   505,   506,    10,
      11,   512,   513,   514,    10,    11,   520,   521,   522,    10,
      11,   528,   529,   530,    10,    11,   536,   537,   538,     8,
      10,    11,   544,   545,   546,    10,    11,   552,   553,   554,
     132,   120,   121,   423,   424,   425,   426,   124,     8,   126,
     128,   130,   120,   397,   399,   400,    10,    11,   354,    41,
      44,    48,    52,   353,   942,   959,   960,   961,   962,   986,
     987,   988,   989,    96,    78,   195,   703,   704,    33,   574,
     575,  1001,     6,     6,     6,   134,   445,   446,  1033,   136,
       6,   107,   138,   459,   460,     6,   140,   143,   467,   468,
     142,   143,   475,   476,   143,   148,   483,   484,   143,   150,
     491,   492,     6,   145,   156,   499,   500,   929,   930,   158,
     507,   508,   929,   162,   515,   516,   929,   160,   523,   524,
     929,   143,   154,   531,   532,   143,   152,   539,   540,     6,
     164,   165,   547,   548,   120,   121,   555,   556,   557,   558,
     120,   425,   427,   428,    10,    11,   402,   401,   942,   959,
     986,   122,     3,     3,   203,   805,   806,    34,   705,   706,
     999,  1034,    10,    11,   576,   577,   578,  1034,  1034,  1034,
     134,     8,    10,   138,   460,     8,    10,   140,   468,    10,
     142,   476,    10,   148,   484,    10,   150,   492,     8,   156,
     500,   931,   932,   158,   508,   162,   516,   160,   524,    10,
     154,   532,    10,   152,   540,     8,    10,   164,   548,   120,
     557,   559,   560,    10,    11,   430,   429,   942,   959,   986,
     122,  1034,     8,   211,   907,   908,    35,   807,   808,   998,
    1034,    10,    11,   707,   708,   709,     6,   169,   579,   580,
     581,     4,     4,     4,     4,     4,    10,    11,   937,    21,
      22,    23,   933,   934,   935,   936,     4,     4,     4,    10,
      11,   562,   561,   942,   959,   986,   122,    28,   909,  1005,
    1034,    10,    11,   809,   810,   811,     6,   197,   710,   711,
     712,  1034,   168,   173,   594,   595,    37,   582,  1006,   108,
     144,   144,   144,   144,   146,     3,     3,     3,   144,   144,
     166,   122,  1034,    10,    11,   910,   911,   912,     6,   205,
     812,   813,   814,  1034,   196,   201,   725,   726,    38,   713,
     996,   175,   608,   609,   596,  1006,  1034,    10,    11,   583,
     584,   585,     8,     8,     8,     6,   913,  1034,   204,   209,
     827,   828,    39,   815,   990,   175,   739,   740,   727,   996,
    1034,    10,    11,   714,   715,   716,   189,   656,   657,    10,
      11,   610,   611,   612,    10,    11,   597,   598,   599,     6,
     170,   171,   586,   587,   588,   589,  1034,   212,   213,   914,
     915,   175,   841,   842,   829,   990,  1034,    10,    11,   816,
     817,   818,   787,    10,    11,   741,   742,   743,    10,    11,
     728,   729,   730,     6,   198,   199,   717,   718,   719,   720,
     191,   670,   671,   658,  1006,   177,   613,   614,   615,   171,
     174,   600,   601,   602,   603,  1034,   170,   588,   590,   591,
      24,    25,    36,    47,    49,    61,    62,   916,   917,   918,
     938,   939,   940,   941,   942,   959,   963,   964,   965,   966,
     970,   971,   972,   973,   986,   994,   889,    10,    11,   843,
     844,   845,    10,    11,   830,   831,   832,     6,   206,   207,
     819,   820,   821,   822,   121,   788,   789,   177,   744,   745,
     746,   199,   202,   731,   732,   733,   734,  1034,   198,   719,
     721,   722,   685,    29,   672,    10,    11,   659,   660,   661,
     176,   181,   621,   622,    40,   616,   992,   174,   602,   604,
     605,    10,    11,   593,    42,   592,   948,   949,   950,   959,
     986,     3,     3,  1034,     3,    10,    11,   919,   920,   921,
     918,   121,   890,   891,   177,   846,   847,   848,   207,   210,
     833,   834,   835,   836,  1034,   206,   821,   823,   824,   790,
     791,   176,   181,   752,   753,   747,   992,   202,   733,   735,
     736,    10,    11,   724,   723,   948,   959,   986,   121,   686,
     687,     8,    10,    11,   673,   674,   675,   171,   190,   662,
     663,   664,   665,   179,   628,   629,   623,   992,  1034,    10,
      11,   617,   618,   619,    10,    11,   607,   606,   948,   959,
     986,   172,  1034,  1034,     8,     6,  1034,   214,   217,   218,
     220,   922,   923,   924,   925,   926,   927,   892,   893,   176,
     181,   854,   855,   849,   992,   210,   835,   837,   838,    10,
      11,   826,   825,   948,   959,   986,    10,    11,   793,   794,
     795,    17,   792,   938,   942,   959,   963,   970,   986,   993,
     996,   179,   759,   760,   754,   992,    10,    11,   748,   749,
     750,    10,    11,   738,    53,    54,    55,    56,   737,   948,
     951,   952,   953,   954,   959,   974,   975,   976,   977,   200,
     688,   689,     6,   192,   193,   676,   677,   678,   190,   664,
     666,   667,   185,   635,   636,   630,   992,    10,    11,   624,
     625,   626,     6,   221,   620,  1018,  1019,  1026,   172,     6,
    1034,     5,   928,   214,   924,    10,    11,   895,   896,   897,
     894,   938,   942,   959,   963,   970,   986,   990,   993,   179,
     861,   862,   856,   992,    10,    11,   850,   851,   852,    10,
      11,   840,    57,    58,    59,    60,   839,   948,   955,   956,
     957,   958,   959,   978,   979,   980,   981,   208,   122,   199,
     215,   796,   797,   798,   799,  1008,  1009,  1010,  1034,   185,
     766,   767,   761,   992,    10,    11,   755,   756,   757,   751,
    1018,   200,     3,     3,    10,    11,   691,   692,   693,   690,
     938,   942,   959,   963,   970,   986,   993,  1006,     8,   192,
     677,   679,   680,    10,    11,   669,   668,   948,   959,   986,
     183,   642,   643,   637,   992,    10,    11,   631,   632,   633,
     627,  1018,  1034,   225,  1027,   178,   226,  1020,  1021,  1034,
     219,   122,   207,   898,   899,   900,   901,  1008,   185,   868,
     869,   863,   992,    10,    11,   857,   858,   859,   853,  1018,
     208,  1034,  1034,   122,   798,   800,   801,  1009,  1011,  1012,
       6,   183,   773,   774,   768,   992,    10,    11,   762,   763,
     764,   758,  1018,   178,  1034,  1034,   122,   171,   694,   695,
     696,   697,  1008,    10,    11,   682,   683,   684,    26,    43,
     681,   946,   947,   967,   968,   969,  1006,   172,   187,   649,
     650,   644,   992,    10,    11,   638,   639,   640,   634,  1018,
     182,  1034,    10,    11,  1028,  1029,  1030,  1022,  1023,   122,
     900,   902,   903,   183,   875,   876,   870,   992,    10,    11,
     864,   865,   866,   860,  1018,   178,  1033,  1033,    10,    11,
     803,   804,   802,   948,   951,   959,   974,   986,    10,    11,
    1014,  1015,  1016,   942,   986,   992,  1013,  1034,   187,   780,
     781,   775,   992,    10,    11,   769,   770,   771,   765,  1018,
     182,   122,   696,   698,   699,   194,   663,     8,  1034,   651,
     992,    10,    11,   645,   646,   647,   641,  1018,   180,     6,
       4,   222,    10,  1025,   223,   224,  1024,  1031,  1032,    10,
      11,   905,   906,   904,   948,   951,   959,   974,   986,   187,
     882,   883,   877,   992,    10,    11,   871,   872,   873,   867,
    1018,   182,  1034,  1034,   200,  1017,  1018,   782,   992,    10,
      11,   776,   777,   778,   772,  1018,   180,    10,    11,   701,
     702,   700,   948,   951,   959,   974,   986,   194,  1033,     6,
      10,    11,   652,   653,   654,   648,  1018,   186,  1034,   222,
       6,  1034,  1034,   208,   884,   992,    10,    11,   878,   879,
     880,   874,  1018,   180,   216,    10,    11,   783,   784,   785,
     779,  1018,   186,   172,     8,  1034,   655,  1018,   184,   227,
       6,     6,    10,    11,   885,   886,   887,   881,  1018,   186,
     786,  1018,   184,   188,  1034,  1034,   888,  1018,   184,   188,
     188
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
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
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
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
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
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       , &(yylsp[(yyi + 1) - (yynrhs)])		       , osoption, parserData, osglData);
      fprintf (stderr, "\n");
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






/*----------.
| yyparse.  |
`----------*/

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
  /* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;
/* Location data for the look-ahead symbol.  */
YYLTYPE yylloc;

  int yystate;
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;

  /* The location stack.  */
  YYLTYPE yylsa[YYINITDEPTH];
  YYLTYPE *yyls = yylsa;
  YYLTYPE *yylsp;
  /* The locations where the error started and ended.  */
  YYLTYPE yyerror_range[2];

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss;
  yyvsp = yyvs;
  yylsp = yyls;
#if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  /* Initialize the default location before parsing starts.  */
  yylloc.first_line   = yylloc.last_line   = 1;
  yylloc.first_column = yylloc.last_column = 0;
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
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);
	YYSTACK_RELOCATE (yyls);
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

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to look-ahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
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

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
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

  case 13:

    {	osolerror( NULL, osoption, parserData, osglData, "unexpected end of file, expecting </osol>");}
    break;

  case 16:

    {
	if(!osoption->setOptionHeader(osglData->fileName, osglData->source,
			osglData->description, osglData->fileCreator, osglData->licence) ) 	
		osolerror( NULL, osoption, parserData, osglData, "setHeader failed");
}
    break;

  case 17:

    {
	osglData->fileName    = "";
	osglData->source      = "";
	osglData->description = "";
	osglData->fileCreator = "";
	osglData->licence     = "";
}
    break;

  case 29:

    {
	osglData->fileName = (yyvsp[(2) - (3)].sval);
	free((yyvsp[(2) - (3)].sval));
}
    break;

  case 36:

    {
	osglData->source = (yyvsp[(2) - (3)].sval);
	free((yyvsp[(2) - (3)].sval));
}
    break;

  case 43:

    {
	osglData->description = (yyvsp[(2) - (3)].sval);
	free((yyvsp[(2) - (3)].sval));
}
    break;

  case 50:

    {
	osglData->fileCreator = (yyvsp[(2) - (3)].sval);
	free((yyvsp[(2) - (3)].sval));
}
    break;

  case 57:

    {
	osglData->licence = (yyvsp[(2) - (3)].sval);
	free((yyvsp[(2) - (3)].sval));
}
    break;

  case 60:

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

  case 81:

    {	if (parserData->serviceURIPresent)
		osolerror( NULL, osoption, parserData, osglData, "only one <serviceURI> element allowed");
	else
		parserData->serviceURIPresent = true;
	
}
    break;

  case 87:

    {
		if (osoption->setServiceURI((yyvsp[(1) - (1)].sval)) == false)
			osolerror( NULL, osoption, parserData, osglData, "setServiceURI failed");
			free((yyvsp[(1) - (1)].sval)); 
		parserData->errorText = NULL;
	}
    break;

  case 89:

    {	if (parserData->serviceNamePresent)
			osolerror(NULL, NULL, parserData, osglData, "only one serviceName element allowed");
		parserData->serviceNamePresent = true;
	}
    break;

  case 95:

    {
			osoption->setServiceName((yyvsp[(1) - (1)].sval)); 
			free((yyvsp[(1) - (1)].sval)); 
			parserData->errorText = NULL;
		}
    break;

  case 97:

    {	if (parserData->instanceNamePresent)
			osolerror(NULL, NULL, parserData, osglData, "only one instanceName element allowed");
		parserData->instanceNamePresent = true;
	}
    break;

  case 103:

    {
		if (osoption->setInstanceName((yyvsp[(1) - (1)].sval)) == false) 
			osolerror( NULL, osoption, parserData, osglData, "setInstanceName failed");
		free((yyvsp[(1) - (1)].sval)); 
		parserData->errorText = NULL;
	}
    break;

  case 104:

    {
	if (osoption->setInstanceLocation(parserData->tempStr,parserData->typeAttribute) == false)
		osolerror(NULL, NULL, parserData, osglData, "setInstanceLocation failed");
	parserData->errorText = NULL;
}
    break;

  case 105:

    {
		if (parserData->instanceLocationPresent)
			osolerror(NULL, NULL, parserData, osglData, "only one instanceLocation element allowed");
		parserData->instanceLocationPresent = true;
		parserData->typeAttribute = "local";
	}
    break;

  case 107:

    {   
		if (verifyLocationType(parserData->typeAttribute) == false)
			osolerror(NULL, NULL, parserData, osglData, "instance location type not recognized");
		parserData->errorText = NULL;
	}
    break;

  case 108:

    { 
	parserData->typeAttribute = (yyvsp[(2) - (3)].sval); 
	free((yyvsp[(2) - (3)].sval));
}
    break;

  case 114:

    {	
		parserData->tempStr = (yyvsp[(1) - (1)].sval);
		free((yyvsp[(1) - (1)].sval)); 
	}
    break;

  case 116:

    {	if (parserData->jobIDPresent)
			osolerror(NULL, NULL, parserData, osglData, "only one jobID element allowed");
		parserData->jobIDPresent = true;
	}
    break;

  case 122:

    {
		if (osoption->setJobID((yyvsp[(1) - (1)].sval)) == false)
			osolerror( NULL, osoption, parserData, osglData, "setJobID failed");
		free((yyvsp[(1) - (1)].sval)); 
		parserData->errorText = NULL;
	}
    break;

  case 124:

    {
		if (parserData->solverToInvokePresent)
			osolerror(NULL, NULL, parserData, osglData, "only one solverToInvoke element allowed");
		parserData->solverToInvokePresent = true;
	}
    break;

  case 130:

    {
		if (osoption->setSolverToInvoke((yyvsp[(1) - (1)].sval)) == false)
			osolerror( NULL, osoption, parserData, osglData, "setSolverToInvoke failed");
		free((yyvsp[(1) - (1)].sval)); 
		parserData->errorText = NULL;
	}
    break;

  case 132:

    {
	if (parserData->licensePresent)
		osolerror( NULL, osoption, parserData, osglData, "only one <license> element allowed");
	parserData->licensePresent = true;	
}
    break;

  case 138:

    {
		if (osoption->setLicense((yyvsp[(1) - (1)].sval)) == false)
			osolerror( NULL, osoption, parserData, osglData, "setLicense failed");
		free((yyvsp[(1) - (1)].sval));
		parserData->errorText = NULL;
	}
    break;

  case 140:

    {	if (parserData->usernamePresent)
		osolerror( NULL, osoption, parserData, osglData, "only one <username> element allowed");
	parserData->usernamePresent = true;	
}
    break;

  case 146:

    {
		if (osoption->setUserName((yyvsp[(1) - (1)].sval)) == false)
			osolerror( NULL, osoption, parserData, osglData, "setUsername failed");
		free((yyvsp[(1) - (1)].sval)); 
		parserData->errorText = NULL;
	}
    break;

  case 148:

    {	if (parserData->passwordPresent)
		osolerror( NULL, osoption, parserData, osglData, "only one <password> element allowed");
	parserData->passwordPresent = true;	
}
    break;

  case 154:

    {
		if (osoption->setPassword((yyvsp[(1) - (1)].sval)) == false)
			osolerror( NULL, osoption, parserData, osglData, "setPassword failed");
		free((yyvsp[(1) - (1)].sval)); 
		parserData->errorText = NULL;
	}
    break;

  case 155:

    {
	if (osoption->setContact(parserData->tempStr,parserData->typeAttribute) == false)
		osolerror( NULL, osoption, parserData, osglData, "setContact failed");
	parserData->errorText = NULL;
}
    break;

  case 156:

    {
	if (parserData->contactPresent)
		osolerror( NULL, osoption, parserData, osglData, "only one <contact> element allowed");
	parserData->contactPresent = true;
	parserData->typeAttribute = "osp";
	parserData->tempStr = "";
}
    break;

  case 158:

    {   
		if (verifyTransportType(parserData->typeAttribute) == false)
			osolerror(NULL, NULL, parserData, osglData, "transport type not recognized");
	}
    break;

  case 159:

    { 
	parserData->typeAttribute = (yyvsp[(2) - (3)].sval); 
	free((yyvsp[(2) - (3)].sval));
}
    break;

  case 165:

    {
		parserData->tempStr = (yyvsp[(1) - (1)].sval);
		free((yyvsp[(1) - (1)].sval));
	}
    break;

  case 167:

    {	if (parserData->otherGeneralOptionsPresent)
		osolerror(NULL, NULL, parserData, osglData, "only one <general> <other> element allowed");
	parserData->otherGeneralOptionsPresent = true;
}
    break;

  case 168:

    {
	if (parserData->tempInt < 0) osolerror(NULL, NULL, parserData, osglData, "number of other general options cannot be negative");
	parserData->numberOf = parserData->tempInt;
	parserData->kounter = 0;
}
    break;

  case 169:

    {	if (parserData->numberOf > 0)
			osolerror(NULL, NULL, parserData, osglData, "expected at least one <other> element");
	}
    break;

  case 170:

    {	if (parserData->kounter < parserData->numberOf - 1)
			osolerror(NULL, NULL, parserData, osglData, "fewer <other> elements than specified");
	}
    break;

  case 177:

    {	
	parserData->kounter++;
	if (osoption->setAnOtherGeneralOption(parserData->nameAttribute, parserData->valueAttribute, parserData->descriptionAttribute) == false)
		osolerror(NULL, NULL, parserData, osglData, "setOtherGeneralOption failed");
}
    break;

  case 178:

    {	if (parserData->kounter >= parserData->numberOf)
		osolerror(NULL, NULL, parserData, osglData, "more <other> elements than specified");
	parserData->nameAttributePresent = false;
	parserData->valueAttributePresent = false;
	parserData->descriptionAttributePresent = false;
	parserData->nameAttribute = "";
	parserData->valueAttribute = "";
	parserData->descriptionAttribute = "";
}
    break;

  case 179:

    {
	if (!parserData->nameAttributePresent)
		osolerror (NULL, NULL, parserData, osglData, "<other> must have name attribute");
}
    break;

  case 182:

    {	if (parserData->nameAttribute.length() == 0)
			osolerror(NULL, NULL, parserData, osglData, "otherOption name cannot be empty");
	}
    break;

  case 189:

    {
	parserData->minDiskSpacePresent = false;	
	parserData->minMemoryPresent = false;
	parserData->minCPUSpeedPresent = false;
	parserData->minCPUNumberPresent = false;
	parserData->otherSystemOptionsPresent = false;
	osoption->system = new SystemOption();
}
    break;

  case 204:

    {	if (parserData->minDiskSpacePresent)
			osolerror(NULL, NULL, parserData, osglData, "only one minDiskSpace element allowed");
		parserData->minDiskSpacePresent = true;	
		parserData->unitAttributePresent = false;	
		parserData->descriptionAttributePresent = false;	
		parserData->unitAttribute = "byte";	
		parserData->descriptionAttribute = "";
	}
    break;

  case 211:

    {
	if (osoption->setMinDiskSpace(parserData->unitAttribute, parserData->descriptionAttribute, parserData->tempVal) == false)
		osolerror(NULL, NULL, parserData, osglData, "setMinDiskSpace failed");
	parserData->errorText = NULL;
}
    break;

  case 213:

    {	if (parserData->minMemoryPresent)
			osolerror(NULL, NULL, parserData, osglData, "only one minMemory element allowed");
		parserData->minMemoryPresent = true;
		parserData->unitAttributePresent = false;	
		parserData->descriptionAttributePresent = false;	
		parserData->unitAttribute = "byte";	
		parserData->descriptionAttribute = "";
	}
    break;

  case 220:

    {
	if (osoption->setMinMemorySize(parserData->unitAttribute, parserData->descriptionAttribute, parserData->tempVal) == false)
		osolerror(NULL, NULL, parserData, osglData, "setMinMemorySize failed");
    parserData->errorText = NULL;
}
    break;

  case 222:

    {	if (parserData->minCPUSpeedPresent)
			osolerror(NULL, NULL, parserData, osglData, "only one minCPUSpeed element allowed");
		parserData->minCPUSpeedPresent = true;
		parserData->unitAttributePresent = false;	
		parserData->descriptionAttributePresent = false;	
		parserData->unitAttribute = "hertz";	
		parserData->descriptionAttribute = "";
	}
    break;

  case 229:

    {	
	if (osoption->setMinCPUSpeed(parserData->unitAttribute, parserData->descriptionAttribute, parserData->tempVal) == false)
		osolerror(NULL, NULL, parserData, osglData, "setMinCPUSpeed failed");
    parserData->errorText = NULL;
}
    break;

  case 231:

    {	if (parserData->minCPUNumberPresent)
			osolerror(NULL, NULL, parserData, osglData, "only one minCPUNumber element allowed");
		parserData->minCPUNumberPresent = true;
		parserData->descriptionAttributePresent = false;	
		parserData->descriptionAttribute = "";	
	}
    break;

  case 235:

    {
	if (osoption->setMinCPUNumber((yyvsp[(1) - (1)].ival), parserData->descriptionAttribute) == false)
		osolerror(NULL, NULL, parserData, osglData, "setMinCPUNumber failed");
	//free($1); 
	parserData->errorText = NULL; 
}
    break;

  case 237:

    {
	if (parserData->otherSystemOptionsPresent)
		osolerror(NULL, NULL, parserData, osglData, "only one <system> <other> element allowed");
	parserData->otherSystemOptionsPresent = true;
}
    break;

  case 238:

    {
	if (parserData->tempInt < 0) osolerror(NULL, NULL, parserData, osglData, "number of other system options cannot be negative");
	parserData->numberOf = parserData->tempInt;
	parserData->kounter = 0;
}
    break;

  case 239:

    {	if (parserData->numberOf > 0)
			osolerror(NULL, NULL, parserData, osglData, "expected at least one <other> element");
	}
    break;

  case 240:

    {	if (parserData->kounter < parserData->numberOf - 1)
			osolerror(NULL, NULL, parserData, osglData, "fewer <other> elements than specified");
	}
    break;

  case 247:

    {
	parserData->kounter++;
	if (osoption->setAnOtherSystemOption(parserData->nameAttribute, parserData->valueAttribute, parserData->descriptionAttribute) == false)
		osolerror(NULL, NULL, parserData, osglData, "setOtherSystemOption failed");
}
    break;

  case 248:

    {	if (parserData->kounter >= parserData->numberOf)
		osolerror(NULL, NULL, parserData, osglData, "more <other> elements than specified");
	parserData->nameAttributePresent = false;
	parserData->valueAttributePresent = false;
	parserData->descriptionAttributePresent = false;
	parserData->nameAttribute = "";
	parserData->valueAttribute = "";
	parserData->descriptionAttribute = "";
}
    break;

  case 249:

    {	if (!parserData->nameAttributePresent)
		osolerror (NULL, NULL, parserData, osglData, "<other> must have name attribute");
}
    break;

  case 252:

    {
		if (parserData->nameAttribute.length() == 0)
			osolerror(NULL, NULL, parserData, osglData, "otherOption name cannot be empty");
	}
    break;

  case 259:

    {
	parserData->serviceTypePresent = false;	
	parserData->otherServiceOptionsPresent = false;
	osoption->service = new ServiceOption();
}
    break;

  case 271:

    {	if (parserData->serviceTypePresent)
			osolerror(NULL, NULL, parserData, osglData, "only one currentState element allowed");
		parserData->serviceTypePresent = true;
	}
    break;

  case 277:

    {
       parserData->tempStr = (yyvsp[(1) - (1)].sval); 
		free((yyvsp[(1) - (1)].sval));
		if (osoption->setServiceType(parserData->tempStr) == false)
			osolerror(NULL, NULL, parserData, osglData, "setServiceType failed; current system state not recognized");
		parserData->errorText = NULL;
	}
    break;

  case 279:

    {
	if (parserData->otherServiceOptionsPresent)
		osolerror(NULL, NULL, parserData, osglData, "only one <service> <other> element allowed");
	parserData->otherServiceOptionsPresent = true;
}
    break;

  case 280:

    {
	if (parserData->tempInt < 0) osolerror(NULL, NULL, parserData, osglData, "number of other service options cannot be negative");
	parserData->numberOf = parserData->tempInt;
	parserData->kounter = 0;
}
    break;

  case 281:

    {	if (parserData->numberOf > 0)
			osolerror(NULL, NULL, parserData, osglData, "expected at least one <other> element");
	}
    break;

  case 282:

    {	if (parserData->kounter < parserData->numberOf - 1)
			osolerror(NULL, NULL, parserData, osglData, "fewer <other> elements than specified");
	}
    break;

  case 289:

    {	
	parserData->kounter++;
	if (osoption->setAnOtherServiceOption(parserData->nameAttribute, parserData->valueAttribute, parserData->descriptionAttribute) == false)
		osolerror(NULL, NULL, parserData, osglData, "setOtherServiceOption failed");
}
    break;

  case 290:

    {	if (parserData->kounter >= parserData->numberOf)
		osolerror(NULL, NULL, parserData, osglData, "more <other> elements than specified");
	parserData->nameAttributePresent = false;
	parserData->valueAttributePresent = false;
	parserData->descriptionAttributePresent = false;
	parserData->nameAttribute = "";
	parserData->valueAttribute = "";
	parserData->descriptionAttribute = "";
}
    break;

  case 291:

    {	if (!parserData->nameAttributePresent)
		osolerror (NULL, NULL, parserData, osglData, "<other> must have name attribute");
}
    break;

  case 294:

    {
		if (parserData->nameAttribute.length() == 0)
			osolerror(NULL, NULL, parserData, osglData, "otherOption name cannot be empty");
	}
    break;

  case 301:

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

  case 325:

    {	
	if (osoption->setMaxTime(parserData->maxTimeValue, parserData->unitAttribute) == false)       
			osolerror(NULL, NULL, parserData, osglData, "max time request could not be honored");
}
    break;

  case 326:

    {	
	if (parserData->maxTimePresent)
		osolerror( NULL, osoption, parserData, osglData, "only one <maxTime> element allowed");
	parserData->maxTimePresent = true;
	parserData->unitAttributePresent = false;	
	parserData->unitAttribute = "second"; 
	parserData->maxTimeValue = OSDBL_MAX;
}
    break;

  case 335:

    {
	parserData->maxTimeValue = parserData->tempVal;
}
    break;

  case 337:

    {	if (parserData->requestedStartTimePresent)
			osolerror(NULL, NULL, parserData, osglData, "only one requestedStartTime element allowed");
		parserData->requestedStartTimePresent = true;
	}
    break;

  case 343:

    {
		if (osoption->setRequestedStartTime((yyvsp[(1) - (1)].sval)) == false)
			osolerror(NULL, NULL, parserData, osglData, "setRequestedStartTime failed");	
		free((yyvsp[(1) - (1)].sval)); 
		parserData->errorText = NULL;
		}
    break;

  case 344:

    {
	if (osoption->setJobDependencies(parserData->numberOf, parserData->jobDependencies) == false)
		osolerror (NULL, osoption, parserData, osglData, "set <job> <dependencies> failed");
	delete[] parserData->jobDependencies;
	parserData->jobDependencies = NULL;
}
    break;

  case 345:

    {
	if (parserData->dependenciesPresent)
		osolerror( NULL, osoption, parserData, osglData, "only one <dependencies> element allowed");
	parserData->dependenciesPresent = true;
}
    break;

  case 351:

    {
	if (parserData->kounter > parserData->numberOf)
		osolerror (NULL, osoption, parserData, osglData, "too few job IDs in <dependencies> element");
}
    break;

  case 354:

    {
	if (parserData->kounter >= parserData->numberOf)
		osolerror (NULL, osoption, parserData, osglData, "too many job IDs in <dependencies> element");
	parserData->jobDependencies[parserData->kounter] = (yyvsp[(3) - (4)].sval);
	free((yyvsp[(3) - (4)].sval)); 
	parserData->kounter++;
}
    break;

  case 355:

    {
	if (osoption->setRequiredDirectories(parserData->numberOf,parserData->paths) == false)
		osolerror (NULL, osoption, parserData, osglData, "set <requiredDirectories> failed");
	delete[] parserData->paths;
	parserData->paths = NULL;
}
    break;

  case 356:

    {	if (parserData->requiredDirectoriesPresent)
		osolerror( NULL, osoption, parserData, osglData, "only one <requiredDirectories> element allowed");
	parserData->requiredDirectoriesPresent = true;
}
    break;

  case 362:

    {
	if (parserData->kounter > parserData->numberOf)
		osolerror (NULL, osoption, parserData, osglData, "too few paths in <requiredDirectories> element");
}
    break;

  case 365:

    {
	if (parserData->kounter >= parserData->numberOf)
		osolerror (NULL, osoption, parserData, osglData, "too many paths in <requiredDirectories> element");
	parserData->paths[parserData->kounter] = (yyvsp[(3) - (4)].sval);
	free((yyvsp[(3) - (4)].sval)); 
	parserData->kounter++;
}
    break;

  case 366:

    {
	if (osoption->setRequiredFiles(parserData->numberOf, parserData->paths) == false)
		osolerror (NULL, osoption, parserData, osglData, "set <requiredFiles> failed");
	delete[] parserData->paths;
	parserData->paths = NULL;
}
    break;

  case 367:

    {	if (parserData->requiredFilesPresent)
		osolerror( NULL, osoption, parserData, osglData, "only one <requiredFiles> element allowed");
	parserData->requiredFilesPresent = true;
}
    break;

  case 373:

    {
	if (parserData->kounter > parserData->numberOf)
		osolerror (NULL, osoption, parserData, osglData, "too few paths in <requiredFiles> element");
}
    break;

  case 376:

    {
	if (parserData->kounter >= parserData->numberOf)
		osolerror (NULL, osoption, parserData, osglData, "too many paths in <requiredFiles> element");
	parserData->paths[parserData->kounter] = (yyvsp[(3) - (4)].sval);
	free((yyvsp[(3) - (4)].sval));
	parserData->kounter++;
}
    break;

  case 377:

    {
	if (osoption->setDirectoriesToMake(parserData->numberOf, parserData->paths) == false)
		osolerror (NULL, osoption, parserData, osglData, "set <directoriesToMake> failed");
	delete[] parserData->paths;
	parserData->paths = NULL;
}
    break;

  case 378:

    {	if (parserData->directoriesToMakePresent)
		osolerror( NULL, osoption, parserData, osglData, "only one <directoriesToMake> element allowed");
	parserData->directoriesToMakePresent = true;
}
    break;

  case 384:

    {
	if (parserData->kounter > parserData->numberOf)
		osolerror (NULL, osoption, parserData, osglData, "too few paths in <directoriesToMake> element");
}
    break;

  case 387:

    {
	if (parserData->kounter >= parserData->numberOf)
		osolerror (NULL, osoption, parserData, osglData, "too many paths in <directoriesToMake> element");
	parserData->paths[parserData->kounter] = (yyvsp[(3) - (4)].sval);
	free((yyvsp[(3) - (4)].sval)); 
	parserData->kounter++;
}
    break;

  case 388:

    {
	if (osoption->setFilesToMake(parserData->numberOf, parserData->paths) == false)
		osolerror (NULL, osoption, parserData, osglData, "set <filesToMake> failed");
	delete[] parserData->paths;
	parserData->paths = NULL;
}
    break;

  case 389:

    {	if (parserData->filesToMakePresent)
		osolerror( NULL, osoption, parserData, osglData, "only one <filesToMake> element allowed");
	parserData->filesToMakePresent = true;
}
    break;

  case 395:

    {
	if (parserData->kounter > parserData->numberOf)
		osolerror (NULL, osoption, parserData, osglData, "too few paths in <filesToMake> element");
}
    break;

  case 398:

    {
	if (parserData->kounter >= parserData->numberOf)
		osolerror (NULL, osoption, parserData, osglData, "too many paths in <filesToMake> element");
	parserData->paths[parserData->kounter] = (yyvsp[(3) - (4)].sval);
	free((yyvsp[(3) - (4)].sval)); 
	parserData->kounter++;
}
    break;

  case 399:

    {
	if (osoption->setPathPairs(ENUM_PATHPAIR_input_dir, parserData->fromPaths, 
			parserData->toPaths, parserData->makeCopy, parserData->numberOfPathPairs) == false)
		osolerror (NULL, osoption, parserData, osglData, "set <inputDirectoriesToMove> failed");
	delete[] parserData->fromPaths;
	delete[] parserData->toPaths;
	delete[] parserData->makeCopy;
	parserData->fromPaths = NULL;
	parserData->toPaths   = NULL;
	parserData->makeCopy  = NULL;
}
    break;

  case 400:

    {	if (parserData->inputDirectoriesToMovePresent)
		osolerror( NULL, osoption, parserData, osglData, "only one <inputDirectoriesToMove> element allowed");
		parserData->inputDirectoriesToMovePresent = true;
}
    break;

  case 406:

    {
	if (parserData->kounter > parserData->numberOfPathPairs)
		osolerror (NULL, osoption, parserData, osglData, "too few path pairs in <inputDirectoriesToMove> element");
}
    break;

  case 410:

    {
	if (osoption->setPathPairs(ENUM_PATHPAIR_input_file, parserData->fromPaths, 
			parserData->toPaths, parserData->makeCopy, parserData->numberOfPathPairs) == false)
		osolerror (NULL, osoption, parserData, osglData, "set <inputFilesToMove> failed");
	delete[] parserData->fromPaths;
	delete[] parserData->toPaths;
	delete[] parserData->makeCopy;
	parserData->fromPaths = NULL;
	parserData->toPaths   = NULL;
	parserData->makeCopy  = NULL;
}
    break;

  case 411:

    {	if (parserData->inputFilesToMovePresent)
		osolerror( NULL, osoption, parserData, osglData, "only one <inputFilesToMove> element allowed");
		parserData->inputFilesToMovePresent = true;
}
    break;

  case 417:

    {
	if (parserData->kounter > parserData->numberOfPathPairs)
		osolerror (NULL, osoption, parserData, osglData, "too few path pairs in <inputFilesToMove> element");
}
    break;

  case 421:

    {
	if (osoption->setPathPairs(ENUM_PATHPAIR_output_file, parserData->fromPaths, 
			parserData->toPaths, parserData->makeCopy, parserData->numberOfPathPairs) == false)
		osolerror (NULL, osoption, parserData, osglData, "set <inputDirectoriesToMake> failed");
	delete[] parserData->fromPaths;
	delete[] parserData->toPaths;
	delete[] parserData->makeCopy;
	parserData->fromPaths = NULL;
	parserData->toPaths   = NULL;
	parserData->makeCopy  = NULL;
}
    break;

  case 422:

    {	if (parserData->outputFilesToMovePresent)
		osolerror( NULL, osoption, parserData, osglData, "only one <outputFilesToMove> element allowed");
		parserData->outputFilesToMovePresent = true;
}
    break;

  case 428:

    {
	if (parserData->kounter > parserData->numberOfPathPairs)
		osolerror (NULL, osoption, parserData, osglData, "too few path pairs in <outputFilesToMake> element");
}
    break;

  case 432:

    {
	if (osoption->setPathPairs(ENUM_PATHPAIR_output_dir, parserData->fromPaths, 
			parserData->toPaths, parserData->makeCopy, parserData->numberOfPathPairs) == false)
		osolerror (NULL, osoption, parserData, osglData, "set <inputDirectoriesToMake> failed");
	delete[] parserData->fromPaths;
	delete[] parserData->toPaths;
	delete[] parserData->makeCopy;
	parserData->fromPaths = NULL;
	parserData->toPaths   = NULL;
	parserData->makeCopy  = NULL;
}
    break;

  case 433:

    {	if (parserData->outputDirectoriesToMovePresent)
		osolerror( NULL, osoption, parserData, osglData, "only one <outputDirectoriesToMove> element allowed");
		parserData->outputDirectoriesToMovePresent = true;
}
    break;

  case 439:

    {
	if (parserData->kounter > parserData->numberOfPathPairs)
		osolerror (NULL, osoption, parserData, osglData, "too few path pairs in <outputDirectoriesToMake> element");
}
    break;

  case 443:

    {
	if (osoption->setFilesToDelete(parserData->numberOf, parserData->paths) == false)
		osolerror (NULL, osoption, parserData, osglData, "set <filesToDelete> failed");
	delete[] parserData->paths;
	parserData->paths = NULL;
}
    break;

  case 444:

    {	if (parserData->filesToDeletePresent)
		osolerror( NULL, osoption, parserData, osglData, "only one <filesToDelete> element allowed");
	parserData->filesToDeletePresent = true;
}
    break;

  case 450:

    {
	if (parserData->kounter > parserData->numberOf)
		osolerror (NULL, osoption, parserData, osglData, "too few paths in <filesToDelete> element");
}
    break;

  case 453:

    {
	if (parserData->kounter >= parserData->numberOf)
		osolerror (NULL, osoption, parserData, osglData, "too many paths in <filesToDelete> element");
	parserData->paths[parserData->kounter] = (yyvsp[(3) - (4)].sval);
	free((yyvsp[(3) - (4)].sval)); 
	parserData->kounter++;
}
    break;

  case 454:

    {
	if (osoption->setDirectoriesToDelete(parserData->numberOf, parserData->paths) == false)
		osolerror (NULL, osoption, parserData, osglData, "set <directoriesToDelete> failed");
	delete[] parserData->paths;
	parserData->paths = NULL;
}
    break;

  case 455:

    {	if (parserData->directoriesToDeletePresent)
		osolerror( NULL, osoption, parserData, osglData, "only one <directoriesToDelete> element allowed");
	parserData->directoriesToDeletePresent = true;
}
    break;

  case 461:

    {
	if (parserData->kounter > parserData->numberOf)
		osolerror (NULL, osoption, parserData, osglData, "too few paths in <directoriesToDelete> element");
}
    break;

  case 464:

    {
	if (parserData->kounter >= parserData->numberOf)
		osolerror (NULL, osoption, parserData, osglData, "too many paths in <directoriesToDelete> element");
	parserData->paths[parserData->kounter] = (yyvsp[(3) - (4)].sval);
	free((yyvsp[(3) - (4)].sval)); 
	parserData->kounter++;
}
    break;

  case 465:

    {
	if (osoption->setProcessesToKill(parserData->numberOf, parserData->processesToKill) == false)
		osolerror (NULL, osoption, parserData, osglData, "set <processesToKill> failed");
	delete[] parserData->processesToKill;
	parserData->processesToKill = NULL;
}
    break;

  case 466:

    {
	if (parserData->processesToKillPresent)
		osolerror( NULL, osoption, parserData, osglData, "only one <processesToKill> element allowed");
	parserData->processesToKillPresent = true;
}
    break;

  case 472:

    {
	if (parserData->kounter > parserData->numberOf)
		osolerror (NULL, osoption, parserData, osglData, "too few process IDs in <processesToKill> element");
}
    break;

  case 475:

    {
	if (parserData->kounter >= parserData->numberOf)
		osolerror (NULL, osoption, parserData, osglData, "too many process IDs in <processesToKill> element");
	parserData->processesToKill[parserData->kounter] = (yyvsp[(3) - (4)].sval);
	free((yyvsp[(3) - (4)].sval)); 
	parserData->kounter++;
}
    break;

  case 477:

    {	if (parserData->otherJobOptionsPresent)
		osolerror(NULL, NULL, parserData, osglData, "only one <job> <other> element allowed");
	parserData->otherJobOptionsPresent = true;
}
    break;

  case 478:

    {
	if (parserData->tempInt < 0) osolerror(NULL, NULL, parserData, osglData, "number of other job options cannot be negative");
	parserData->numberOf = parserData->tempInt;
	parserData->kounter = 0;
}
    break;

  case 479:

    {	if (parserData->numberOf > 0)
			osolerror(NULL, NULL, parserData, osglData, "expected at least one <other> element");
	}
    break;

  case 480:

    {	if (parserData->kounter < parserData->numberOf - 1)
			osolerror(NULL, NULL, parserData, osglData, "fewer <other> elements than specified");
	}
    break;

  case 487:

    {
	parserData->kounter++;
	if (osoption->setAnOtherJobOption(parserData->nameAttribute, parserData->valueAttribute, parserData->descriptionAttribute) == false)
		osolerror(NULL, NULL, parserData, osglData, "setOtherJobOption failed");
}
    break;

  case 488:

    {	if (parserData->kounter >= parserData->numberOf)
		osolerror(NULL, NULL, parserData, osglData, "more <other> elements than specified");
	parserData->nameAttributePresent = false;
	parserData->valueAttributePresent = false;
	parserData->descriptionAttributePresent = false;
	parserData->nameAttribute = "";
	parserData->valueAttribute = "";
	parserData->descriptionAttribute = "";
}
    break;

  case 489:

    {	if (!parserData->nameAttributePresent)
		osolerror (NULL, NULL, parserData, osglData, "<other> must have name attribute");
}
    break;

  case 492:

    {
		if (parserData->nameAttribute.length() == 0)
			osolerror(NULL, NULL, parserData, osglData, "otherOption name cannot be empty");
	}
    break;

  case 499:

    {
	osoption->optimization = new OptimizationOption();
	parserData->numberOfVariablesPresent = false;
	parserData->numberOfObjectivesPresent = false;
	parserData->numberOfConstraintsPresent = false;
}
    break;

  case 503:

    {	
		parserData->numberOfVariables = parserData->tempInt; 
		if (osoption->setNumberOfVariables(parserData->tempInt) == false)
			osolerror(NULL, NULL, parserData, osglData, "setNumberOfVariables failed");
	}
    break;

  case 504:

    {
		parserData->numberOfConstraints = parserData->tempInt; 
		if (osoption->setNumberOfConstraints(parserData->tempInt) == false)
			osolerror(NULL, NULL, parserData, osglData, "setNumberOfConstraints failed");
	}
    break;

  case 505:

    {	
		parserData->numberOfObjectives = parserData->tempInt; 
		if (osoption->setNumberOfObjectives(parserData->tempInt) == false)
			osolerror(NULL, NULL, parserData, osglData, "setNumberOfObjectives failed");
	}
    break;

  case 513:

    {
	parserData->numberOfOtherVariableOptions = 0;
	osoption->optimization->variables = new VariableOption();
}
    break;

  case 514:

    {	
	if (osoption->setNumberOfOtherVariableOptions(parserData->numberOfOtherVariableOptions) == false)
		osolerror(NULL, NULL, parserData, osglData, "setNumberOfOtherVariableOptions failed");
	parserData->iOther = 0;
}
    break;

  case 516:

    {	
	parserData->numberOfOtherVariableOptions = parserData->tempInt;
}
    break;

  case 523:

    {
	if (osoption->setInitVarValues(parserData->numberOfVar, parserData->idxArray, parserData->valArray, parserData->namArray) == false)
		osolerror (NULL, osoption, parserData, osglData, "set <initialVariableValues> failed");
	delete[] parserData->idxArray;
	delete[] parserData->namArray;
	delete[] parserData->valArray;
	parserData->idxArray = NULL;
	parserData->namArray = NULL;
	parserData->valArray = NULL;
}
    break;

  case 524:

    {
	parserData->numberOfVarAttributePresent = false;
}
    break;

  case 525:

    {
	parserData->kounter = 0;
	parserData->idxArray = new         int[parserData->numberOfVar];
	parserData->namArray = new std::string[parserData->numberOfVar];
	parserData->valArray = new      double[parserData->numberOfVar];
	for (int i=0; i < parserData->numberOfVar; i++) parserData->namArray[i] = "";
	for (int i=0; i < parserData->numberOfVar; i++) parserData->valArray[i] = OSNaN();
}
    break;

  case 526:

    {
		if (parserData->numberOfVar > 0)
			osolerror(NULL, NULL, parserData, osglData, "<initialVariableValues>: expected at least one <var> element");
	}
    break;

  case 527:

    {
		if (parserData->kounter > parserData->numberOfVar)
			osolerror (NULL, osoption, parserData, osglData, "<initialVariableValues>: fewer <var> elements than specified");
	}
    break;

  case 534:

    {
	parserData->kounter++;
}
    break;

  case 535:

    {	
	if (parserData->kounter >= parserData->numberOfVar)
		osolerror(NULL, NULL, parserData, osglData, "more <var> elements than specified");
	parserData->idxAttributePresent = false;
	parserData->nameAttributePresent = false;
	parserData->valueAttributePresent = false;
}
    break;

  case 536:

    {
	if (parserData->idxAttributePresent == false)
		osolerror(NULL, NULL, parserData, osglData, "<var> element must have idx attribute");
}
    break;

  case 539:

    {
		if (parserData->idxAttribute < 0)
			osolerror (NULL, osoption, parserData, osglData, "variable index must be nonnegative");
		if (osoption->optimization->numberOfVariables >= 0)
		{
			if (parserData->idxAttribute >= osoption->optimization->numberOfVariables)
				osolerror (NULL, osoption, parserData, osglData, "variable index exceeds upper limit");
		};
		parserData->idxArray[parserData->kounter] = parserData->idxAttribute;
	}
    break;

  case 540:

    {
		parserData->namArray[parserData->kounter] = parserData->nameAttribute;
	}
    break;

  case 541:

    {
		if (parserData->valueAttribute == "")
			osolerror (NULL, osoption, parserData, osglData, "expected an integer or floating point value");
		parserData->valArray[parserData->kounter] = os_strtod((parserData->valueAttribute).c_str(), NULL);
	}
    break;

  case 545:

    {
	if (osoption->setInitVarValuesString(parserData->numberOfVar, parserData->idxArray, parserData->valueString, parserData->namArray) == false)
		osolerror (NULL, osoption, parserData, osglData, "set <initialVariableValuesString> failed");
	delete[] parserData->idxArray;
	delete[] parserData->namArray;
	delete[] parserData->valArray;
	parserData->idxArray = NULL;
	parserData->namArray = NULL;
	parserData->valueString = NULL;
}
    break;

  case 546:

    {
	parserData->numberOfVarAttributePresent = false;
}
    break;

  case 547:

    {
	parserData->kounter = 0;
	parserData->idxArray    = new         int[parserData->numberOfVar];
	parserData->namArray    = new std::string[parserData->numberOfVar];
	parserData->valueString = new std::string[parserData->numberOfVar];
	for (int i=0; i < parserData->numberOfVar; i++) parserData->namArray[i] = "";
	for (int i=0; i < parserData->numberOfVar; i++) parserData->valueString[i] = "";
}
    break;

  case 548:

    {
		if (parserData->numberOfVar > 0)
			osolerror(NULL, NULL, parserData, osglData, "expected at least one <var> element");
	}
    break;

  case 549:

    {
		if (parserData->kounter != parserData->numberOfVar)
			osolerror(NULL, NULL, parserData, osglData, "too few initial values in <initialVariableValuesString> element");
	}
    break;

  case 556:

    {
	parserData->kounter++;
}
    break;

  case 557:

    {	
	if (parserData->kounter >= parserData->numberOfVar)
		osolerror(NULL, NULL, parserData, osglData, "more <var> elements than specified");
	parserData->idxAttributePresent = false;
	parserData->nameAttributePresent = false;
	parserData->valueAttributePresent = false;
	parserData->valueAttribute = "48r 87e WY EUV e7 df"; //random string...
}
    break;

  case 558:

    {
	if (parserData->idxAttributePresent == false)
		osolerror(NULL, NULL, parserData, osglData, "<var> element must have idx attribute");
}
    break;

  case 561:

    {
		if (parserData->idxAttribute < 0)
			osolerror (NULL, osoption, parserData, osglData, "variable index must be nonnegative");
		if (osoption->optimization->numberOfVariables >= 0)
		{
			if (parserData->idxAttribute >= osoption->optimization->numberOfVariables)
				osolerror (NULL, osoption, parserData, osglData, "variable index exceeds upper limit");
		};
		parserData->idxArray[parserData->kounter] = parserData->idxAttribute;
	}
    break;

  case 562:

    {
		parserData->namArray[parserData->kounter] = parserData->nameAttribute;
	}
    break;

  case 563:

    {
		parserData->valueString[parserData->kounter] = parserData->valueAttribute;
	}
    break;

  case 568:

    {
	osoption->optimization->variables->initialBasisStatus = new BasisStatus();
}
    break;

  case 575:

    {
	if (osoption->setInitBasisStatus(ENUM_PROBLEM_COMPONENT_variables, ENUM_BASIS_STATUS_basic, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
		osolerror(NULL, NULL, parserData, osglData, "set variables basic failed");	
	delete[] osglData->osglIntArray;
	osglData->osglIntArray = NULL;
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
	if (osoption->setInitBasisStatus(ENUM_PROBLEM_COMPONENT_variables, ENUM_BASIS_STATUS_atLower, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
		osolerror(NULL, NULL, parserData, osglData, "set variables atLower failed");	
	delete[] osglData->osglIntArray;
	osglData->osglIntArray = NULL;
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
	if (osoption->setInitBasisStatus(ENUM_PROBLEM_COMPONENT_variables, ENUM_BASIS_STATUS_atUpper, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
		osolerror(NULL, NULL, parserData, osglData, "set variables atUpper failed");	
	delete[] osglData->osglIntArray;
	osglData->osglIntArray = NULL;
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
	if (osoption->setInitBasisStatus(ENUM_PROBLEM_COMPONENT_variables, ENUM_BASIS_STATUS_isFree, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
		osolerror(NULL, NULL, parserData, osglData, "set variables isFree failed");	
	delete[] osglData->osglIntArray;
	osglData->osglIntArray = NULL;
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
	if (osoption->setInitBasisStatus(ENUM_PROBLEM_COMPONENT_variables, ENUM_BASIS_STATUS_superbasic, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
		osolerror(NULL, NULL, parserData, osglData, "set variables superbasic failed");	
	delete[] osglData->osglIntArray;
	osglData->osglIntArray = NULL;
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
	if (osoption->setInitBasisStatus(ENUM_PROBLEM_COMPONENT_variables, ENUM_BASIS_STATUS_unknown, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
		osolerror(NULL, NULL, parserData, osglData, "set variables unknown failed");	
	delete[] osglData->osglIntArray;
	osglData->osglIntArray = NULL;
}
    break;

  case 621:

    {
	osglData->osglNumberOfEl = 0;
	osglData->osglNumberOfElPresent= false;
}
    break;

  case 622:

    {
	osglData->osglCounter = 0; 
	osglData->osglNumberOfEl = parserData->numberOf;
	osglData->osglIntArray = new int[parserData->numberOf];
}
    break;

  case 629:

    {
	if (osoption->setIntegerVariableBranchingWeights(parserData->numberOfVar, parserData->idxArray, parserData->valArray, parserData->namArray) == false)
		osolerror (NULL, osoption, parserData, osglData, "set <initialVariableValues> failed");
	delete[] parserData->idxArray;
	delete[] parserData->namArray;
	delete[] parserData->valArray;
	parserData->idxArray = NULL;
	parserData->namArray = NULL;
	parserData->valArray = NULL;
}
    break;

  case 630:

    {
	parserData->numberOfVarAttributePresent = false;
}
    break;

  case 631:

    {
	parserData->kounter = 0;
	parserData->idxArray = new         int[parserData->numberOfVar];
	parserData->namArray = new std::string[parserData->numberOfVar];
	parserData->valArray = new      double[parserData->numberOfVar];
	for (int i=0; i < parserData->numberOfVar; i++) parserData->namArray[i] = "";
	for (int i=0; i < parserData->numberOfVar; i++) parserData->valArray[i] = OSNaN();
}
    break;

  case 632:

    {
		if (parserData->numberOfVar > 0)
			osolerror(NULL, NULL, parserData, osglData, "expected at least one <var> element");
	}
    break;

  case 633:

    {
		if (parserData->kounter != parserData->numberOfVar)
			osolerror(NULL, NULL, parserData, osglData, "fewer <var> elements than specified");
	}
    break;

  case 640:

    {
	parserData->kounter++;
}
    break;

  case 641:

    {	
	if (parserData->kounter >= parserData->numberOfVar)
		osolerror(NULL, NULL, parserData, osglData, "more <var> elements than specified");
	parserData->idxAttributePresent = false;
	parserData->nameAttributePresent = false;
	parserData->nameAttribute = "";
	parserData->valueAttributePresent = false;
	parserData->valueAttribute = "1.0";
}
    break;

  case 642:

    {
	if (parserData->idxAttributePresent == false)
		osolerror(NULL, NULL, parserData, osglData, "<var> element must have idx attribute");
//	parserData->idxArray[parserData->kounter] = parserData->idxAttribute;
//	parserData->namArray[parserData->kounter] = parserData->nameAttribute;
//	parserData->valArray[parserData->kounter] = os_strtod((parserData->valueAttribute).c_str(), NULL);
}
    break;

  case 645:

    {
		if (parserData->idxAttribute < 0)
			osolerror (NULL, osoption, parserData, osglData, "variable index must be nonnegative");
		if (osoption->optimization->numberOfVariables >= 0)
		{
			if (parserData->idxAttribute >= osoption->optimization->numberOfVariables)
				osolerror (NULL, osoption, parserData, osglData, "variable index exceeds upper limit");
		};
		parserData->idxArray[parserData->kounter] = parserData->idxAttribute;
	}
    break;

  case 646:

    {
		parserData->namArray[parserData->kounter] = parserData->nameAttribute;
	}
    break;

  case 647:

    {
		if (parserData->valueAttribute == "")
			osolerror (NULL, osoption, parserData, osglData, "expected an integer or floating point value");
		parserData->valArray[parserData->kounter] = os_strtod((parserData->valueAttribute).c_str(), NULL);
	}
    break;

  case 652:

    {
	parserData->sosIdxAttributePresent = false;	
	parserData->currentSOS = 0;
}
    break;

  case 653:

    {
	if ((yyvsp[(3) - (4)].ival) < 0)
		osolerror (NULL, osoption, parserData, osglData, "number of <sos> elements must be nonnegative");
	parserData->numberOfSOS = (yyvsp[(3) - (4)].ival);
}
    break;

  case 654:

    {	if (parserData->numberOfSOS > 0)
			osolerror(NULL, NULL, parserData, osglData, "expected at least one <sos> element");
	}
    break;

  case 655:

    {	if (parserData->currentSOS != parserData->numberOfSOS)
			osolerror(NULL, NULL, parserData, osglData, "fewer <sos> elements than specified");
	}
    break;

  case 661:

    {
	if (!osoption->setAnotherSOSVariableBranchingWeight(parserData->sosIdx, 
				parserData->numberOfVar, parserData->groupWeight,
				parserData->idxArray,	 parserData->valArray, parserData->namArray) )
		osolerror (NULL, osoption, parserData, osglData, "error processing SOS branching weights");
	delete[] parserData->idxArray;
	delete[] parserData->namArray;
	delete[] parserData->valArray;
	parserData->idxArray = NULL;
	parserData->namArray = NULL;
	parserData->valArray = NULL;
	parserData->currentSOS++;
}
    break;

  case 662:

    {	if (parserData->currentSOS >= parserData->numberOfSOS)
		osolerror(NULL, osoption, parserData, osglData, "too many SOS branching weights");
	parserData->sosIdxAttributePresent = false;
	parserData->groupWeightAttributePresent = false;
	parserData->numberOfVarAttributePresent = false;
	parserData->groupWeight = 1.0;
	parserData->numberOfSOSVar = 0;
}
    break;

  case 663:

    {
	if (!parserData->sosIdxAttributePresent)
		osolerror (NULL, osoption, parserData, osglData, "SOS index required");
	if (!parserData->numberOfVarAttributePresent)
		osolerror (NULL, osoption, parserData, osglData, "numberOfVar required");
}
    break;

  case 667:

    {
		parserData->kounter = 0;
		parserData->idxArray = new         int[parserData->numberOfVar];
		parserData->namArray = new std::string[parserData->numberOfVar];
		parserData->valArray = new      double[parserData->numberOfVar];
		for (int i=0; i < parserData->numberOfVar; i++) parserData->valArray[i] = OSNaN();
		parserData->numberOfVarAttributePresent = true;
	}
    break;

  case 676:

    { 	 
		parserData->iOther++;
	}
    break;

  case 677:

    {
	if (parserData->iOther >= parserData->numberOfOtherVariableOptions)
		osolerror(NULL, NULL, parserData, osglData, "more <otherVariableOptions> than specified");
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

  case 678:

    {
		if (!parserData->nameAttributePresent) 
			osolerror(NULL, NULL, parserData, osglData, "<other> element requires name attribute"); 
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
			osolerror(NULL, NULL, parserData, osglData, "<other> element could not be initialed"); 
	}
    break;

  case 681:

    {
		parserData->kounter = 0;
	}
    break;

  case 682:

    {
		parserData->kounter = 0;
	}
    break;

  case 698:

    { 	
	if (!osoption->setOtherVariableOptionVar(
				parserData->iOther, 
				parserData->kounter,
				parserData->idxAttribute, 
				parserData->nameAttribute,
				parserData->valueAttribute,
				parserData->lbValueAttribute, 
				parserData->ubValueAttribute) )
		osolerror(NULL, NULL, parserData, osglData, "set other variable option <var> element failed");
	parserData->kounter++;
}
    break;

  case 699:

    {
	if (parserData->kounter >= parserData->numberOfVar)
		osolerror(NULL, NULL, parserData, osglData, "more <var> elements than specified");
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

  case 703:

    {
		if (parserData->idxAttribute < 0)
			osolerror (NULL, osoption, parserData, osglData, "variable index must be nonnegative");
		if (osoption->optimization->numberOfVariables >= 0)
		{
			if (parserData->idxAttribute >= osoption->optimization->numberOfVariables)
				osolerror (NULL, osoption, parserData, osglData, "variable index exceeds upper limit");
		};
	}
    break;

  case 713:

    {
	parserData->numberOfOtherObjectiveOptions = 0; 
	osoption->optimization->objectives = new ObjectiveOption();
}
    break;

  case 714:

    {	
	if (osoption->setNumberOfOtherObjectiveOptions(parserData->numberOfOtherObjectiveOptions) == false)
		osolerror(NULL, NULL, parserData, osglData, "setNumberOfOtherVariableOptions failed");
	parserData->iOther = 0;
}
    break;

  case 716:

    {	
	parserData->numberOfOtherObjectiveOptions = parserData->tempInt;
}
    break;

  case 723:

    {
	if (osoption->setInitObjValues(parserData->numberOfObj, parserData->idxArray, parserData->valArray, parserData->namArray) == false)
		osolerror (NULL, osoption, parserData, osglData, "set <initialObjectiveValues> failed");
	delete[] parserData->idxArray;
	delete[] parserData->namArray;
	delete[] parserData->valArray;
	parserData->idxArray = NULL;
	parserData->namArray = NULL;
	parserData->valArray = NULL;
}
    break;

  case 724:

    {
	parserData->numberOfObjAttributePresent = false;
}
    break;

  case 725:

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

  case 726:

    {	
		if (parserData->numberOfObj > 0)
			osolerror(NULL, NULL, parserData, osglData, "<initialObjectiveValues>: expected at least one <obj> element");
	}
    break;

  case 727:

    {
		if (parserData->kounter != parserData->numberOfObj)
			osolerror(NULL, NULL, parserData, osglData, "<initialObjectiveValues>: fewer <obj> elements than specified");
	}
    break;

  case 734:

    {
	parserData->kounter++;
}
    break;

  case 735:

    {	
	if (parserData->kounter >= parserData->numberOfObj)
		osolerror(NULL, NULL, parserData, osglData, "more <obj> elements than specified");
	parserData->idxAttributePresent = false;
	parserData->nameAttributePresent = false;
	parserData->valueAttributePresent = false;
	parserData->idxAttribute = -1;
}
    break;

  case 739:

    {
		if (parserData->idxAttribute >= 0)
			osolerror (NULL, osoption, parserData, osglData, "objective index must be negative");
		if (osoption->optimization->numberOfObjectives >= 0)
		{
			if (parserData->idxAttribute < -osoption->optimization->numberOfObjectives)
				osolerror (NULL, osoption, parserData, osglData, "objective index exceeds limit");
		};
		parserData->idxArray[parserData->kounter] = parserData->idxAttribute;
	}
    break;

  case 740:

    {
		parserData->namArray[parserData->kounter] = parserData->nameAttribute;
	}
    break;

  case 741:

    {
		if (parserData->valueAttribute == "")
			osolerror (NULL, osoption, parserData, osglData, "expected an integer or floating point value");
		parserData->valArray[parserData->kounter] = os_strtod((parserData->valueAttribute).c_str(), NULL);
	}
    break;

  case 745:

    {
	if (osoption->setInitObjBounds(parserData->numberOfObj, parserData->idxArray, parserData->lbValArray, parserData->ubValArray, parserData->namArray) == false)
		osolerror (NULL, osoption, parserData, osglData, "set <initialObjectiveBounds> failed");
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

  case 746:

    {
	parserData->numberOfObjAttributePresent = false;
}
    break;

  case 747:

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

  case 748:

    {
		if (parserData->numberOfObj > 0)
			osolerror(NULL, NULL, parserData, osglData, "<initialObjectiveBounds>: expected at least one <obj> element");
	}
    break;

  case 749:

    {
		if (parserData->kounter != parserData->numberOfObj)
			osolerror(NULL, NULL, parserData, osglData, "<initialObjectiveBounds>: fewer <obj> elements than specified");
	}
    break;

  case 756:

    {
	parserData->kounter++;
}
    break;

  case 757:

    {	
	if (parserData->kounter >= parserData->numberOfObj)
		osolerror(NULL, NULL, parserData, osglData, "more <obj> elements than specified");
	parserData->idxAttributePresent = false;
	parserData->nameAttributePresent = false;
	parserData->lbValueAttributePresent = false;
	parserData->ubValueAttributePresent = false;
	parserData->idxAttribute = -1;
	parserData->lbValueAttribute = "-INF";
	parserData->ubValueAttribute = "INF";
}
    break;

  case 761:

    {
		if (parserData->idxAttribute >= 0)
			osolerror (NULL, osoption, parserData, osglData, "objective index must be nonnegative");
		if (osoption->optimization->numberOfObjectives >= 0)
		{
			if (parserData->idxAttribute < -osoption->optimization->numberOfVariables)
				osolerror (NULL, osoption, parserData, osglData, "objective index exceeds limit");
		};
		parserData->idxArray[parserData->kounter] = parserData->idxAttribute;
	}
    break;

  case 762:

    {
		parserData->namArray[parserData->kounter] = parserData->nameAttribute;
	}
    break;

  case 763:

    {
		if (parserData->lbValueAttribute == "")
			osolerror (NULL, osoption, parserData, osglData, "expected an integer or floating point value");
		parserData->lbValArray[parserData->kounter] = os_strtod((parserData->lbValueAttribute).c_str(), NULL);
	}
    break;

  case 764:

    {
		if (parserData->ubValueAttribute == "")
			osolerror (NULL, osoption, parserData, osglData, "expected an integer or floating point value");
		parserData->ubValArray[parserData->kounter] = os_strtod((parserData->ubValueAttribute).c_str(), NULL);
	}
    break;

  case 769:

    {
	osoption->optimization->objectives->initialBasisStatus = new BasisStatus();
}
    break;

  case 776:

    {
	if (osoption->setInitBasisStatus(ENUM_PROBLEM_COMPONENT_objectives, ENUM_BASIS_STATUS_basic, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
		osolerror(NULL, NULL, parserData, osglData, "set objectives basic failed");	
	delete[] osglData->osglIntArray;
	osglData->osglIntArray = NULL;
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
	if (osoption->setInitBasisStatus(ENUM_PROBLEM_COMPONENT_objectives, ENUM_BASIS_STATUS_atLower, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
		osolerror(NULL, NULL, parserData, osglData, "set objectives atLower failed");	
	delete[] osglData->osglIntArray;
	osglData->osglIntArray = NULL;
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
	if (osoption->setInitBasisStatus(ENUM_PROBLEM_COMPONENT_objectives, ENUM_BASIS_STATUS_atUpper, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
		osolerror(NULL, NULL, parserData, osglData, "set objectives atUpper failed");	
	delete[] osglData->osglIntArray;
	osglData->osglIntArray = NULL;
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
	if (osoption->setInitBasisStatus(ENUM_PROBLEM_COMPONENT_objectives, ENUM_BASIS_STATUS_isFree, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
		osolerror(NULL, NULL, parserData, osglData, "set objectives isFree failed");	
	delete[] osglData->osglIntArray;
	osglData->osglIntArray = NULL;
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
	if (osoption->setInitBasisStatus(ENUM_PROBLEM_COMPONENT_objectives, ENUM_BASIS_STATUS_superbasic, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
		osolerror(NULL, NULL, parserData, osglData, "set objectives superbasic failed");	
	delete[] osglData->osglIntArray;
	osglData->osglIntArray = NULL;
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
	if (osoption->setInitBasisStatus(ENUM_PROBLEM_COMPONENT_objectives, ENUM_BASIS_STATUS_unknown, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
		osolerror(NULL, NULL, parserData, osglData, "set objectives unknown failed");	
	delete[] osglData->osglIntArray;
	osglData->osglIntArray = NULL;
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
		osolerror(NULL, NULL, parserData, osglData, "more <otherObjectiveOptions> than specified");
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
			osolerror(NULL, NULL, parserData, osglData, "<other> element requires name attribute"); 
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
			osolerror(NULL, NULL, parserData, osglData, "<other> element could not be initialed"); 
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
	if (!osoption->setOtherObjectiveOptionObj(
				parserData->iOther, 
				parserData->kounter,
				parserData->idxAttribute, 
				parserData->nameAttribute,
				parserData->valueAttribute,
				parserData->lbValueAttribute, 
				parserData->ubValueAttribute) )
		osolerror(NULL, NULL, parserData, osglData, "set other objective option <obj> element failed");
	parserData->kounter++;
}
    break;

  case 854:

    {
	if (parserData->kounter >= parserData->numberOfObj)
		osolerror(NULL, NULL, parserData, osglData, "more <obj> elements than specified");
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

  case 855:

    {	
	parserData->idxArray[parserData->kounter] = parserData->idxAttribute;
	parserData->namArray[parserData->kounter] = parserData->nameAttribute;
	parserData->valueString[parserData->kounter] = parserData->valueAttribute;
	parserData->lbValueString[parserData->kounter] = parserData->lbValueAttribute;
	parserData->ubValueString[parserData->kounter] = parserData->ubValueAttribute;
}
    break;

  case 858:

    {
		if (parserData->idxAttribute >= 0)
			osolerror (NULL, osoption, parserData, osglData, "objective index must be negative");
		if (osoption->optimization->numberOfObjectives >= 0)
		{
			if (parserData->idxAttribute < -osoption->optimization->numberOfObjectives)
				osolerror (NULL, osoption, parserData, osglData, "objective index exceeds limit");
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
		osolerror(NULL, NULL, parserData, osglData, "setNumberOfOtherConstraintOptions failed");
	parserData->iOther = 0;
}
    break;

  case 871:

    {	
	parserData->numberOfOtherConstraintOptions = parserData->tempInt;
}
    break;

  case 878:

    {
	if (osoption->setInitConValues(parserData->numberOfCon, parserData->idxArray, parserData->valArray, parserData->namArray) == false)
		osolerror (NULL, osoption, parserData, osglData, "set <initialConstraintValues> failed");
	delete[] parserData->idxArray;
	delete[] parserData->namArray;
	delete[] parserData->valArray;
	parserData->idxArray = NULL;
	parserData->namArray = NULL;
	parserData->valArray = NULL;
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
			osolerror(NULL, NULL, parserData, osglData, "<initialConstraintValues>: expected at least one <con element");
	}
    break;

  case 882:

    {
		if (parserData->kounter > parserData->numberOfCon)
			osolerror(NULL, NULL, parserData, osglData, "<initialConstraintValues>: fewer <con> elements than specified");
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
		osolerror(NULL, NULL, parserData, osglData, "more <con> elements than specified");
	parserData->idxAttributePresent = false;
	parserData->nameAttribute = "";
	parserData->nameAttributePresent = false;
	parserData->valueAttributePresent = false;
}
    break;

  case 891:

    {
	if (parserData->idxAttributePresent == false)
		osolerror(NULL, NULL, parserData, osglData, "<con> element must have idx attribute");
}
    break;

  case 894:

    {
		if (parserData->idxAttribute < 0)
			osolerror (NULL, osoption, parserData, osglData, "constraint index must be nonnegative");
		if (osoption->optimization->numberOfConstraints >= 0)
		{
			if (parserData->idxAttribute >= osoption->optimization->numberOfConstraints)
				osolerror (NULL, osoption, parserData, osglData, "constraint index exceeds upper limit");
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
			osolerror (NULL, osoption, parserData, osglData, "expected an integer or floating point value");
		parserData->valArray[parserData->kounter] = os_strtod((parserData->valueAttribute).c_str(), NULL);
	}
    break;

  case 900:

    {
	if (osoption->setInitDualValues(parserData->numberOfCon, parserData->idxArray, parserData->lbValArray, parserData->ubValArray, parserData->namArray) == false)
		osolerror (NULL, osoption, parserData, osglData, "set <initialConstraintValues> failed");
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
			osolerror(NULL, NULL, parserData, osglData, "<initialDualValues>: expected at least one <con> element");
	}
    break;

  case 904:

    {
		if (parserData->kounter != parserData->numberOfCon)
			osolerror(NULL, NULL, parserData, osglData, "<initialDualValues>: fewer <con> elements than specified");
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
		osolerror(NULL, NULL, parserData, osglData, "more <con> elements than specified");
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
		osolerror(NULL, NULL, parserData, osglData, "<con> element must have idx attribute");
}
    break;

  case 916:

    {
		if (parserData->idxAttribute < 0)
			osolerror (NULL, osoption, parserData, osglData, "constraint index must be nonnegative");
		if (osoption->optimization->numberOfConstraints >= 0)
		{
			if (parserData->idxAttribute >= osoption->optimization->numberOfConstraints)
				osolerror (NULL, osoption, parserData, osglData, "constraint index exceeds upper limit");
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
	if (osoption->setInitBasisStatus(ENUM_PROBLEM_COMPONENT_constraints, ENUM_BASIS_STATUS_basic, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
		osolerror(NULL, NULL, parserData, osglData, "set slacks basic failed");	
	delete[] osglData->osglIntArray;
	osglData->osglIntArray = NULL;
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
	if (osoption->setInitBasisStatus(ENUM_PROBLEM_COMPONENT_constraints, ENUM_BASIS_STATUS_atLower, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
		osolerror(NULL, NULL, parserData, osglData, "set slacks atLower failed");	
	delete[] osglData->osglIntArray;
	osglData->osglIntArray = NULL;
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
	if (osoption->setInitBasisStatus(ENUM_PROBLEM_COMPONENT_constraints, ENUM_BASIS_STATUS_atUpper, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
		osolerror(NULL, NULL, parserData, osglData, "set slacks atUpper failed");	
	delete[] osglData->osglIntArray;
	osglData->osglIntArray = NULL;
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
	if (osoption->setInitBasisStatus(ENUM_PROBLEM_COMPONENT_constraints, ENUM_BASIS_STATUS_isFree, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
		osolerror(NULL, NULL, parserData, osglData, "set slacks isFree failed");	
	delete[] osglData->osglIntArray;
	osglData->osglIntArray = NULL;
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
	if (osoption->setInitBasisStatus(ENUM_PROBLEM_COMPONENT_constraints, ENUM_BASIS_STATUS_superbasic, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
		osolerror(NULL, NULL, parserData, osglData, "set variables superbasic failed");	
	delete[] osglData->osglIntArray;
	osglData->osglIntArray = NULL;
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
	if (osoption->setInitBasisStatus(ENUM_PROBLEM_COMPONENT_constraints, ENUM_BASIS_STATUS_unknown, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
		osolerror(NULL, NULL, parserData, osglData, "set slacks unknown failed");	
	delete[] osglData->osglIntArray;
	osglData->osglIntArray = NULL;
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

  case 986:

    { 	 
		parserData->iOther++;  
	}
    break;

  case 987:

    {
	if (parserData->iOther >= parserData->numberOfOtherConstraintOptions)
		osolerror(NULL, NULL, parserData, osglData, "more <otherConstraintOptions> than specified");
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

  case 988:

    {
		if(!parserData->nameAttributePresent) 
			osolerror(NULL, NULL, parserData, osglData, "<other> element requires name attribute"); 
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
			osolerror(NULL, NULL, parserData, osglData, "<other> element could not be initialed"); 
	}
    break;

  case 991:

    {
		parserData->kounter = 0;
	}
    break;

  case 992:

    {
		parserData->kounter = 0;
	}
    break;

  case 1008:

    { 	
	if (!osoption->setOtherConstraintOptionCon(
				parserData->iOther, 
				parserData->kounter,
				parserData->idxAttribute, 
				parserData->nameAttribute,
				parserData->valueAttribute,
				parserData->lbValueAttribute, 
				parserData->ubValueAttribute) )
		osolerror(NULL, NULL, parserData, osglData, "set other constraint option <con> element failed");
	parserData->kounter++;
}
    break;

  case 1009:

    {
	if (parserData->kounter >= parserData->numberOfCon)
		osolerror(NULL, NULL, parserData, osglData, "more <con> elements than specified");
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

  case 1013:

    {
		if (parserData->idxAttribute < 0)
			osolerror (NULL, osoption, parserData, osglData, "constraint index must be nonnegative");
		if (osoption->optimization->numberOfConstraints >= 0)
		{
			if (parserData->idxAttribute >= osoption->optimization->numberOfConstraints)
				osolerror (NULL, osoption, parserData, osglData, "constraint index exceeds upper limit");
		};
	}
    break;

  case 1024:

    {
	if (!osoption->setNumberOfSolverOptions(parserData->numberOfSolverOptions) )
		osolerror( NULL, osoption, parserData, osglData, "setNumberOfSolverOptions failed");
	parserData->iOption = 0;
}
    break;

  case 1025:

    {
		if (parserData->numberOfSolverOptions > 0)
			osolerror(NULL, NULL, parserData, osglData, "expected at least one <solverOption> element");
	}
    break;

  case 1026:

    {
		if (parserData->iOption != parserData->numberOfSolverOptions)
			osolerror(NULL, NULL, parserData, osglData, "fewer <solverOption> elements than specified");
	}
    break;

  case 1031:

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
		osolerror(NULL, NULL, parserData, osglData, "setSolverOptionContent failed");
	if (parserData->numberOfItems > 0)
		delete[] parserData->itemList;
	parserData->itemList = NULL;
	parserData->iOption++;
}
    break;

  case 1032:

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

  case 1033:

    {
	if (!parserData->nameAttributePresent)
		osolerror (NULL, osoption, parserData, osglData, "name attribute must be present");
}
    break;

  case 1042:

    {
			parserData->itemList = new std::string[parserData->numberOfItems];
    }
    break;

  case 1043:

    {	if (parserData->numberOfItems > 0)
			osolerror(NULL, NULL, parserData, osglData, "expected at least one <item> element");
	}
    break;

  case 1044:

    {	if (parserData->kounter != parserData->numberOfItems)
			osolerror(NULL, NULL, parserData, osglData, "fewer <item> elements than specified");
	}
    break;

  case 1051:

    {	
	parserData->itemList[parserData->kounter] = parserData->itemContent;
	parserData->kounter++;
}
    break;

  case 1052:

    {
		if (parserData->kounter >= parserData->numberOfItems)
			osolerror(NULL, NULL, parserData, osglData, "more <item> elements than specified");
		parserData->itemContent = "";			
	}
    break;

  case 1057:

    {
	if (parserData->kounter >= parserData->numberOfItems)
		osolerror(NULL, NULL, parserData, osglData, "more <item> elements than specified");
	parserData->itemContent = (yyvsp[(1) - (1)].sval); 
	free((yyvsp[(1) - (1)].sval));
}
    break;

  case 1058:

    {	
	if (!parserData->pathPairFromPresent)
		osolerror (NULL, osoption, parserData, osglData, "\"from\" attribute must be present");
	if (!parserData->pathPairToPresent)
		osolerror (NULL, osoption, parserData, osglData, "\"to\" attribute must be present");
	parserData->kounter++;
}
    break;

  case 1059:

    {
	if (parserData->kounter >= parserData->numberOfPathPairs)
		osolerror (NULL, osoption, parserData, osglData, "too many path pairs");
	parserData->pathPairFromPresent = false;
	parserData->pathPairToPresent = false;
	parserData->pathPairMakeCopyPresent = false;
	parserData->pathPairMakeCopy = false;
}
    break;

  case 1060:

    {
	parserData->makeCopy[parserData->kounter] = parserData->pathPairMakeCopy;
}
    break;

  case 1066:

    {
	if (parserData->pathPairFromPresent)
		osolerror( NULL, osoption, parserData, osglData, "only one \"from\" attribute allowed");
	parserData->pathPairFromPresent = true;
	parserData->fromPaths[parserData->kounter] = (yyvsp[(2) - (3)].sval);
	free((yyvsp[(2) - (3)].sval));
}
    break;

  case 1067:

    {
	if (parserData->pathPairToPresent)
		osolerror( NULL, osoption, parserData, osglData, "only one \"to\" attribute allowed");
	parserData->pathPairToPresent = true;
	parserData->toPaths[parserData->kounter] = (yyvsp[(2) - (3)].sval);
	free((yyvsp[(2) - (3)].sval));
}
    break;

  case 1068:

    {
	if (parserData->pathPairMakeCopyPresent)
		osolerror( NULL, osoption, parserData, osglData, "only one \"makeCopy\" attribute allowed");
	parserData->pathPairMakeCopyPresent = true;
	parserData->pathPairMakeCopy = (strcmp((yyvsp[(2) - (3)].sval),"true") == 0);
	free((yyvsp[(2) - (3)].sval));
}
    break;

  case 1071:

    {   
	if (parserData->categoryAttributePresent ) 
		osolerror(NULL, NULL, parserData, osglData, "only one category attribute allowed for this element");
	parserData->categoryAttributePresent = true;
}
    break;

  case 1074:

    { 
	parserData->categoryAttribute = "";
}
    break;

  case 1075:

    { 
	parserData->categoryAttribute = (yyvsp[(2) - (3)].sval); 
	free((yyvsp[(2) - (3)].sval)); 
}
    break;

  case 1076:

    {
	if (parserData->descriptionAttributePresent ) 
		osolerror(NULL, NULL, parserData, osglData, "only one description attribute allowed for this element");
	parserData->descriptionAttributePresent = true;
}
    break;

  case 1079:

    { parserData->descriptionAttribute = ""; }
    break;

  case 1080:

    { 
	parserData->descriptionAttribute = (yyvsp[(2) - (3)].sval); 
	free((yyvsp[(2) - (3)].sval));
}
    break;

  case 1081:

    {
	if (parserData->groupWeightAttributePresent ) 
		osolerror(NULL, NULL, parserData, osglData, "only one groupWeight attribute allowed for this element");
	parserData->groupWeightAttributePresent = true;
}
    break;

  case 1082:

    {
	parserData->groupWeight = parserData->tempVal;
}
    break;

  case 1083:

    {   
	if (parserData->idxAttributePresent ) 
		osolerror(NULL, NULL, parserData, osglData, "only one idx attribute allowed for this element");
	parserData->idxAttributePresent = true;
}
    break;

  case 1085:

    { 
	parserData->idxAttribute = (yyvsp[(3) - (4)].ival);
}
    break;

  case 1086:

    {   
	if (parserData->lbValueAttributePresent ) 
		osolerror(NULL, NULL, parserData, osglData, "only one lb attribute allowed for this element");
	parserData->lbValueAttributePresent = true;
}
    break;

  case 1089:

    { 
	parserData->lbValueAttribute = ""; 
}
    break;

  case 1090:

    { 
	parserData->lbValueAttribute = (yyvsp[(2) - (3)].sval); 
	free((yyvsp[(2) - (3)].sval));
}
    break;

  case 1091:

    {   if (parserData->lbValueAttributePresent ) 
				osolerror(NULL, NULL, parserData, osglData, "only one lb attribute allowed for this element");
			parserData->lbValueAttributePresent = true;
		}
    break;

  case 1094:

    { parserData->lbDualValue = 0.0; }
    break;

  case 1095:

    { parserData->lbDualValue = parserData->tempVal;}
    break;

  case 1096:

    {   if (parserData->nameAttributePresent ) 
				osolerror(NULL, NULL, parserData, osglData, "only one name attribute allowed for this element");
			parserData->nameAttributePresent = true;
		}
    break;

  case 1099:

    { parserData->nameAttribute = ""; }
    break;

  case 1100:

    { 
	parserData->nameAttribute = (yyvsp[(2) - (3)].sval); 
	free((yyvsp[(2) - (3)].sval));
}
    break;

  case 1101:

    {   if (parserData->solverAttributePresent ) 
				osolerror(NULL, NULL, parserData, osglData, "only one solver attribute allowed for this element");
			parserData->solverAttributePresent = true;
		}
    break;

  case 1104:

    { parserData->solverAttribute = ""; }
    break;

  case 1105:

    { 
	parserData->solverAttribute = (yyvsp[(2) - (3)].sval); 
	free((yyvsp[(2) - (3)].sval));
}
    break;

  case 1106:

    {   if (parserData->sosIdxAttributePresent ) 
			osolerror(NULL, NULL, parserData, osglData, "only one sosIdx attribute allowed for this element");
		parserData->sosIdxAttributePresent = true;
	}
    break;

  case 1108:

    {
	if ((yyvsp[(3) - (4)].ival) < 0)
		osolerror (NULL, osoption, parserData, osglData, "SOS index must be nonnegative");
	parserData->sosIdx = (yyvsp[(3) - (4)].ival);
}
    break;

  case 1109:

    {   if (parserData->typeAttributePresent ) 
				osolerror(NULL, NULL, parserData, osglData, "only one type attribute allowed for this element");
			parserData->typeAttributePresent = true;
		}
    break;

  case 1112:

    { parserData->typeAttribute = ""; }
    break;

  case 1113:

    { 
	parserData->typeAttribute = (yyvsp[(2) - (3)].sval); 
	free((yyvsp[(2) - (3)].sval));
}
    break;

  case 1114:

    {
   if (parserData->ubValueAttributePresent ) 
		osolerror(NULL, NULL, parserData, osglData, "only one ub attribute allowed for this element");
	parserData->ubValueAttributePresent = true;
}
    break;

  case 1117:

    { 
	parserData->ubValueAttribute = ""; 
}
    break;

  case 1118:

    { 
	parserData->ubValueAttribute = (yyvsp[(2) - (3)].sval); 
	free((yyvsp[(2) - (3)].sval));
}
    break;

  case 1119:

    {   if (parserData->ubValueAttributePresent ) 
				osolerror(NULL, NULL, parserData, osglData, "only one ub attribute allowed for this element");
			parserData->ubValueAttributePresent = true;
		}
    break;

  case 1122:

    { parserData->ubDualValue = 0.0; }
    break;

  case 1123:

    { 
	parserData->ubDualValue = parserData->tempVal;
}
    break;

  case 1124:

    {   if (parserData->unitAttributePresent ) 
				osolerror(NULL, NULL, parserData, osglData, "only one unit attribute allowed for this element");
			parserData->unitAttributePresent = true;
		}
    break;

  case 1127:

    { parserData->unitAttribute = ""; }
    break;

  case 1128:

    { 
	parserData->unitAttribute = (yyvsp[(2) - (3)].sval); 
	free((yyvsp[(2) - (3)].sval));
}
    break;

  case 1129:

    {   if (parserData->valueAttributePresent ) 
				osolerror(NULL, NULL, parserData, osglData, "only one value attribute allowed for this element");
			parserData->valueAttributePresent = true;
		}
    break;

  case 1132:

    { parserData->valueAttribute = ""; }
    break;

  case 1133:

    {
	parserData->valueAttribute = (yyvsp[(2) - (3)].sval); 
	free((yyvsp[(2) - (3)].sval));
}
    break;

  case 1134:

    {
	if (parserData->numberOfConAttributePresent)
		osolerror(NULL, NULL, parserData, osglData, "numberOfCon attribute previously set");
	if ((yyvsp[(3) - (4)].ival) < 0) osolerror(NULL, NULL, parserData, osglData, "number of <con> cannot be negative");
	parserData->numberOfConAttributePresent = true;		
	parserData->numberOfCon = (yyvsp[(3) - (4)].ival);
}
    break;

  case 1135:

    {
	if (parserData->numberOfConstraintsPresent)
		osolerror(NULL, NULL, parserData, osglData, "numberOfConstraints attribute previously set");
	if ((yyvsp[(3) - (4)].ival) < 0) osolerror(NULL, NULL, parserData, osglData, "number of constraints cannot be negative");
	parserData->numberOfConstraintsPresent = true;		
	parserData->tempInt = (yyvsp[(3) - (4)].ival); 
}
    break;

  case 1136:

    {
	if (osglData->osglNumberOfElPresent)
		osolerror(NULL, NULL, parserData, osglData, "numberOfEl attribute previously set");
	if ((yyvsp[(3) - (4)].ival) < 0) osolerror(NULL, NULL, parserData, osglData, "number of <el> cannot be negative");
	osglData->osglNumberOfElPresent = true;
	parserData->numberOf = (yyvsp[(3) - (4)].ival); 
}
    break;

  case 1137:

    {
	if (parserData->numberOfEnumerationsAttributePresent)
		osolerror(NULL, NULL, parserData, osglData, "numberOfEnumerations attribute previously set");
	if ((yyvsp[(3) - (4)].ival) < 0) osolerror(NULL, NULL, parserData, osglData, "number of <enumeration> elements cannot be negative");
	parserData->numberOfEnumerationsAttributePresent = true;		
	parserData->numberOfEnumerations = (yyvsp[(3) - (4)].ival); 
}
    break;

  case 1138:

    {	
   if (parserData->numberOfItemsPresent ) 
        osolerror(NULL, NULL, parserData, osglData, "only one numberOfItems attribute allowed");
	if ((yyvsp[(3) - (4)].ival) < 0) osolerror(NULL, NULL, parserData, osglData, "number of items cannot be negative");
	parserData->numberOfItemsPresent = true;
	parserData->numberOfItems = (yyvsp[(3) - (4)].ival);
}
    break;

  case 1139:

    {
	if ((yyvsp[(3) - (4)].ival) < 0)
		osolerror( NULL, osoption, parserData, osglData, "Number of job IDs cannot be negative");
	parserData->numberOf = (yyvsp[(3) - (4)].ival);
	parserData->kounter = 0;
	parserData->jobDependencies = new std::string[(yyvsp[(3) - (4)].ival)];
}
    break;

  case 1140:

    {
	if (parserData->numberOfObjAttributePresent)
		osolerror(NULL, NULL, parserData, osglData, "numberOfObj attribute previously set");
	if ((yyvsp[(3) - (4)].ival) < 0) osolerror(NULL, NULL, parserData, osglData, "number of <obj> cannot be negative");
	parserData->numberOfObjAttributePresent = true;		
	parserData->numberOfObj = (yyvsp[(3) - (4)].ival);
}
    break;

  case 1141:

    {	if (parserData->numberOfObjectivesPresent)
		osolerror(NULL, NULL, parserData, osglData, "numberOfObjectives attribute previously set");
	if ((yyvsp[(3) - (4)].ival) < 0) osolerror(NULL, NULL, parserData, osglData, "number of objectives cannot be negative");
	parserData->numberOfObjectivesPresent = true;
	parserData->tempInt = (yyvsp[(3) - (4)].ival); 
}
    break;

  case 1142:

    {
	if ((yyvsp[(3) - (4)].ival) < 0) osolerror(NULL, NULL, parserData, osglData, "number of other constraint options cannot be negative");
	parserData->tempInt = (yyvsp[(3) - (4)].ival);
}
    break;

  case 1143:

    {
	if ((yyvsp[(3) - (4)].ival) < 0) osolerror(NULL, NULL, parserData, osglData, "number of other objective options cannot be negative");
	parserData->tempInt = (yyvsp[(3) - (4)].ival);
}
    break;

  case 1144:

    {
	if ((yyvsp[(3) - (4)].ival) < 0) osolerror(NULL, NULL, parserData, osglData, "number of other options cannot be negative");
	parserData->tempInt = (yyvsp[(3) - (4)].ival);
}
    break;

  case 1145:

    {	
	if ((yyvsp[(3) - (4)].ival) < 0) osolerror(NULL, NULL, parserData, osglData, "number of other variable options cannot be negative");
	parserData->tempInt = (yyvsp[(3) - (4)].ival);
}
    break;

  case 1146:

    {
	if ((yyvsp[(3) - (4)].ival) < 0)
		osolerror( NULL, osoption, parserData, osglData, "Number of path pairs cannot be negative");
	parserData->numberOfPathPairs = (yyvsp[(3) - (4)].ival);
	parserData->kounter = 0;
	parserData->fromPaths = new std::string[(yyvsp[(3) - (4)].ival)];
	parserData->toPaths   = new std::string[(yyvsp[(3) - (4)].ival)];
	parserData->makeCopy  = new bool[(yyvsp[(3) - (4)].ival)];
}
    break;

  case 1147:

    {
	if ((yyvsp[(3) - (4)].ival) < 0)
		osolerror( NULL, osoption, parserData, osglData, "Number of paths cannot be negative");
	parserData->numberOf = (yyvsp[(3) - (4)].ival);
	parserData->kounter = 0;
	parserData->paths = new std::string[(yyvsp[(3) - (4)].ival)];
}
    break;

  case 1148:

    {
	if ((yyvsp[(3) - (4)].ival) < 0)
		osolerror( NULL, osoption, parserData, osglData, "Number of job IDs cannot be negative");
	parserData->numberOf = (yyvsp[(3) - (4)].ival);
	parserData->kounter = 0;
	parserData->processesToKill = new std::string[(yyvsp[(3) - (4)].ival)];
}
    break;

  case 1149:

    {	
	if ((yyvsp[(3) - (4)].ival) < 0) osolerror(NULL, NULL, parserData, osglData, "number of solver options cannot be negative");
	parserData->numberOfSolverOptions = (yyvsp[(3) - (4)].ival);
}
    break;

  case 1150:

    {
	if (parserData->numberOfVarAttributePresent)
		osolerror(NULL, NULL, parserData, osglData, "numberOfVar attribute previously set");
	if ((yyvsp[(3) - (4)].ival) < 0) osolerror(NULL, NULL, parserData, osglData, "number of <var> cannot be negative");
	parserData->numberOfVarAttributePresent = true;		
	parserData->numberOfVar = (yyvsp[(3) - (4)].ival); 
}
    break;

  case 1151:

    {	if (parserData->numberOfVariablesPresent)
		osolerror(NULL, NULL, parserData, osglData, "numberOfVariables attribute previously set");
	if ((yyvsp[(3) - (4)].ival) < 0) osolerror(NULL, NULL, parserData, osglData, "number of variables cannot be negative");
	parserData->numberOfVariablesPresent = true;	
	parserData->tempInt = (yyvsp[(3) - (4)].ival); 
}
    break;

  case 1154:

    { 	
	if (!osoption->setOtherOptionEnumeration(parserData->otherOptionType, 
			parserData->iOther,
			parserData->kounter,
			osglData->osglNumberOfEl, 
			parserData->valueAttribute, 
			parserData->descriptionAttribute, 
			osglData->osglIntArray) )
		osolerror(NULL, NULL, parserData, osglData, "set <other> option enumeration failed");

	delete[] osglData->osglIntArray;
	osglData->osglIntArray = NULL;
	osglData->osglNumberOfEl = 0;
	parserData->kounter++;
}
    break;

  case 1155:

    {
	if (parserData->kounter >= parserData->numberOfEnumerations)
		osolerror(NULL, NULL, parserData, osglData, "more <enumeration> elements than specified");
	osglData->osglNumberOfElPresent = false;
	parserData->valueAttributePresent = false;
	parserData->descriptionAttributePresent = false;
	parserData->valueAttribute = "";
	parserData->descriptionAttribute = "";
}
    break;

  case 1156:

    {	if(!osglData->osglNumberOfElPresent) 
			osolerror(NULL, NULL, parserData, osglData, "<other> element enumeration requires numberOfEl attribute"); 
		if(!parserData->valueAttributePresent) 
			osolerror(NULL, NULL, parserData, osglData, "<other> element enumeration requires value attribute"); 
	}
    break;

  case 1159:

    {
		osglData->osglCounter = 0; 
		osglData->osglNumberOfElPresent = true;
		osglData->osglNumberOfEl = parserData->numberOf;
		osglData->osglIntArray = new int[parserData->numberOf];
	}
    break;

  case 1167:

    {
	 	if (osglData->osglCounter < osglData->osglNumberOfEl)
			osolerror(NULL, NULL, parserData, osglData, "fewer data elements than specified");
	}
    break;

  case 1172:

    {	
	osglData->osglMultPresent = false;
	osglData->osglIncrPresent = false;
	osglData->osglMult = 1;
	osglData->osglIncr = 0;
}
    break;

  case 1178:

    {
	if (osglData->osglCounter + osglData->osglMult > osglData->osglNumberOfEl)
		osolerror(NULL, NULL, parserData, osglData, "more data elements than specified");
	for (int i=0; i<osglData->osglMult; i++)
		osglData->osglIntArray[osglData->osglCounter++] = (yyvsp[(2) - (3)].ival) + i*osglData->osglIncr;	
}
    break;

  case 1180:

    {
	osglData->osglSize = (yyvsp[(3) - (4)].ival);
}
    break;

  case 1185:

    {
	char* b64string = (yyvsp[(2) - (3)].sval);
	if( b64string == NULL) 
		osolerror(NULL, NULL, parserData, osglData, "base 64 data expected"); 
	if (osglData->osglSize != sizeof(int))
		osolerror(NULL, NULL, parserData, osglData, "base 64 encoded with a size of int different than on this machine"); 

	std::string base64decodeddata = Base64::decodeb64( b64string );
	int base64decodeddatalength = base64decodeddata.length();
	int *intvec = NULL;
	if ( parserData->numberOf != (base64decodeddatalength/osglData->osglSize) )
		osolerror(NULL, NULL, parserData, osglData, "base 64 data length does not match numberOfEl"); 
	intvec = (int*)&base64decodeddata[0];
	for(int i = 0; i < (base64decodeddatalength/osglData->osglSize); i++)
	{
		osglData->osglIntArray[i] = *(intvec++);
	}
	//delete[] b64string;
	free((yyvsp[(2) - (3)].sval));
}
    break;

  case 1186:

    {	
	if (osglData->osglIncrPresent) 
        osolerror(NULL, NULL, parserData, osglData, "only one incr attribute allowed");
	osglData->osglIncrPresent = true;
	osglData->osglIncr = (yyvsp[(3) - (4)].ival);
}
    break;

  case 1187:

    {	
	if (osglData->osglMultPresent) 
        osolerror(NULL, NULL, parserData, osglData, "only one mult attribute allowed");
	if ((yyvsp[(3) - (4)].ival) <= 0) osolerror(NULL, NULL, parserData, osglData, "mult must be positive");
	osglData->osglMultPresent = true;
	osglData->osglMult = (yyvsp[(3) - (4)].ival);
}
    break;

  case 1188:

    {parserData->tempVal = (yyvsp[(1) - (1)].ival);}
    break;

  case 1189:

    {parserData->tempVal = (yyvsp[(1) - (1)].dval);}
    break;


/* Line 1267 of yacc.c.  */

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
      /* If just tried and failed to reuse look-ahead token after an
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

  /* Else will try to reuse look-ahead token after shifting the error
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

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;

  yyerror_range[1] = yylloc;
  /* Using YYLLOC is tempting, but would change the location of
     the look-ahead.  YYLOC is available though.  */
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

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (&yylloc, osoption, parserData, osglData, YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
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





void osolerror(YYLTYPE* mytype, OSOption *osoption, OSoLParserData* parserData, OSgLParserData* osglData, const char* errormsg )
{
std::cout << "empty osol vectors in osolerror" << std::endl;
	osol_empty_vectors( parserData);
std::cout << "empty osgl vectors in osolerror" << std::endl;
	osgl_empty_vectors( osglData);
std::cout << "emptied all vectors in osolerror" << std::endl;
	std::ostringstream outStr;
	std::string error = errormsg;
std::cout << "error defined and assigned" << std::endl;
	error = "OSoL input is either not valid or well formed: "  + error;
	outStr << error << std::endl;
	outStr << "Error occurred when reading: " << osolget_text ( scanner ) << std::endl; 
	outStr << "See line number: " << osolget_lineno( scanner) << std::endl; 
	error = outStr.str();
	//printf("THIS DID NOT GET DESTROYED:   %s\n", parserData->errorText);
	//if( (parserData->errorText != NULL) &&  (strlen(parserData->errorText) > 0) ) free(  parserData->errorText);
	//osollex_destroy( scanner);
std::cout << "error: " << error << std::endl;
std::cout << "throw error" << std::endl;

	throw ErrorClass( error);
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


