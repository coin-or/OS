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
#include <stdio.h>

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
#define YYLAST   1270

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  233
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  802
/* YYNRULES -- Number of rules.  */
#define YYNRULES  1183
/* YYNRULES -- Number of states.  */
#define YYNSTATES  1639

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
     765,   767,   769,   771,   773,   775,   779,   781,   783,   785,
     787,   790,   792,   796,   798,   800,   803,   805,   807,   809,
     812,   814,   818,   820,   824,   826,   828,   830,   832,   835,
     837,   841,   843,   846,   851,   855,   857,   859,   861,   863,
     866,   868,   872,   874,   877,   882,   886,   888,   890,   892,
     894,   897,   899,   903,   905,   908,   913,   917,   919,   921,
     923,   925,   928,   930,   934,   936,   939,   944,   948,   950,
     952,   954,   956,   959,   961,   965,   967,   970,   975,   979,
     981,   983,   985,   987,   990,   992,   996,   998,  1001,  1003,
    1007,  1009,  1011,  1013,  1015,  1018,  1020,  1024,  1026,  1029,
    1031,  1035,  1037,  1039,  1041,  1043,  1046,  1048,  1052,  1054,
    1057,  1059,  1063,  1065,  1067,  1069,  1071,  1074,  1076,  1080,
    1082,  1085,  1087,  1091,  1093,  1095,  1097,  1099,  1102,  1104,
    1108,  1110,  1113,  1118,  1122,  1124,  1126,  1128,  1130,  1133,
    1135,  1139,  1141,  1144,  1149,  1153,  1155,  1157,  1159,  1161,
    1164,  1166,  1170,  1172,  1175,  1180,  1184,  1186,  1188,  1190,
    1192,  1195,  1197,  1201,  1203,  1205,  1208,  1212,  1214,  1216,
    1217,  1220,  1222,  1224,  1226,  1229,  1231,  1232,  1236,  1238,
    1240,  1241,  1244,  1246,  1248,  1250,  1252,  1254,  1256,  1260,
    1265,  1266,  1270,  1272,  1274,  1275,  1277,  1279,  1281,  1283,
    1287,  1294,  1295,  1299,  1301,  1303,  1305,  1307,  1310,  1312,
    1316,  1318,  1320,  1323,  1327,  1329,  1330,  1333,  1335,  1337,
    1340,  1342,  1343,  1347,  1349,  1351,  1353,  1355,  1358,  1360,
    1364,  1366,  1368,  1371,  1375,  1377,  1379,  1380,  1383,  1385,
    1387,  1390,  1392,  1393,  1396,  1398,  1400,  1402,  1404,  1408,
    1415,  1416,  1420,  1422,  1424,  1426,  1428,  1430,  1434,  1436,
    1437,  1441,  1443,  1445,  1447,  1449,  1451,  1455,  1457,  1458,
    1462,  1464,  1466,  1468,  1470,  1472,  1476,  1478,  1479,  1483,
    1485,  1487,  1489,  1491,  1493,  1497,  1499,  1500,  1504,  1506,
    1508,  1510,  1512,  1514,  1518,  1520,  1521,  1525,  1527,  1529,
    1531,  1533,  1535,  1539,  1541,  1542,  1546,  1548,  1550,  1552,
    1554,  1557,  1559,  1563,  1565,  1567,  1570,  1574,  1576,  1578,
    1579,  1582,  1584,  1586,  1589,  1591,  1592,  1596,  1598,  1603,
    1605,  1607,  1610,  1612,  1616,  1618,  1621,  1625,  1627,  1629,
    1630,  1633,  1635,  1637,  1639,  1641,  1643,  1646,  1648,  1652,
    1653,  1656,  1660,  1662,  1664,  1665,  1668,  1670,  1672,  1674,
    1676,  1678,  1680,  1682,  1684,  1686,  1688,  1691,  1693,  1697,
    1699,  1701,  1703,  1706,  1710,  1712,  1714,  1715,  1718,  1720,
    1722,  1724,  1726,  1728,  1731,  1733,  1734,  1738,  1740,  1742,
    1743,  1745,  1747,  1749,  1751,  1755,  1760,  1761,  1765,  1767,
    1769,  1771,  1773,  1776,  1778,  1782,  1784,  1786,  1789,  1793,
    1795,  1797,  1798,  1801,  1803,  1805,  1808,  1810,  1811,  1815,
    1817,  1819,  1821,  1823,  1826,  1828,  1832,  1834,  1836,  1839,
    1843,  1845,  1847,  1848,  1851,  1853,  1855,  1857,  1860,  1862,
    1863,  1866,  1868,  1870,  1872,  1874,  1878,  1885,  1886,  1890,
    1892,  1894,  1896,  1898,  1900,  1904,  1906,  1907,  1911,  1913,
    1915,  1917,  1919,  1921,  1925,  1927,  1928,  1932,  1934,  1936,
    1938,  1940,  1942,  1946,  1948,  1949,  1953,  1955,  1957,  1959,
    1961,  1963,  1967,  1969,  1970,  1974,  1976,  1978,  1980,  1982,
    1984,  1988,  1990,  1991,  1995,  1997,  1999,  2001,  2003,  2005,
    2009,  2011,  2012,  2015,  2019,  2021,  2023,  2024,  2027,  2029,
    2031,  2033,  2035,  2037,  2039,  2041,  2043,  2045,  2047,  2050,
    2052,  2056,  2058,  2060,  2062,  2065,  2069,  2071,  2073,  2074,
    2077,  2079,  2081,  2083,  2085,  2087,  2090,  2092,  2093,  2097,
    2099,  2101,  2102,  2104,  2106,  2108,  2110,  2114,  2119,  2120,
    2124,  2126,  2128,  2130,  2132,  2135,  2137,  2141,  2143,  2145,
    2148,  2152,  2154,  2155,  2158,  2160,  2162,  2165,  2167,  2168,
    2172,  2174,  2176,  2178,  2180,  2183,  2185,  2189,  2191,  2193,
    2196,  2200,  2202,  2204,  2205,  2208,  2210,  2212,  2214,  2217,
    2219,  2220,  2223,  2225,  2227,  2229,  2231,  2235,  2242,  2243,
    2247,  2249,  2251,  2253,  2255,  2257,  2261,  2263,  2264,  2268,
    2270,  2272,  2274,  2276,  2278,  2282,  2284,  2285,  2289,  2291,
    2293,  2295,  2297,  2299,  2303,  2305,  2306,  2310,  2312,  2314,
    2316,  2318,  2320,  2324,  2326,  2327,  2331,  2333,  2335,  2337,
    2339,  2341,  2345,  2347,  2348,  2352,  2354,  2356,  2358,  2360,
    2362,  2366,  2368,  2369,  2372,  2376,  2378,  2380,  2381,  2384,
    2386,  2388,  2390,  2392,  2394,  2396,  2398,  2400,  2402,  2404,
    2407,  2409,  2413,  2415,  2417,  2419,  2422,  2426,  2428,  2430,
    2431,  2434,  2436,  2438,  2440,  2442,  2444,  2447,  2449,  2450,
    2454,  2456,  2458,  2460,  2462,  2464,  2468,  2469,  2472,  2476,
    2478,  2480,  2482,  2485,  2487,  2489,  2491,  2493,  2495,  2497,
    2499,  2501,  2503,  2506,  2508,  2512,  2514,  2516,  2519,  2521,
    2523,  2525,  2527,  2529,  2533,  2535,  2539,  2541,  2543,  2544,
    2547,  2549,  2551,  2553,  2557,  2561,  2565,  2568,  2570,  2572,
    2574,  2576,  2578,  2582,  2584,  2586,  2588,  2590,  2594,  2596,
    2601,  2603,  2605,  2610,  2612,  2614,  2616,  2618,  2622,  2624,
    2626,  2628,  2630,  2635,  2637,  2639,  2641,  2643,  2647,  2649,
    2651,  2653,  2655,  2659,  2661,  2663,  2668,  2670,  2672,  2674,
    2676,  2680,  2682,  2684,  2686,  2688,  2692,  2694,  2696,  2698,
    2700,  2705,  2707,  2709,  2711,  2713,  2717,  2719,  2721,  2723,
    2725,  2729,  2734,  2739,  2744,  2749,  2754,  2759,  2764,  2769,
    2774,  2779,  2784,  2789,  2794,  2799,  2804,  2809,  2814,  2819,
    2821,  2824,  2828,  2830,  2832,  2833,  2836,  2838,  2840,  2842,
    2844,  2846,  2848,  2852,  2854,  2856,  2858,  2859,  2862,  2866,
    2868,  2870,  2871,  2874,  2876,  2878,  2882,  2886,  2891,  2893,
    2895,  2898,  2900,  2904,  2909,  2914,  2916,  2918,  2921,  2922,
    2925,  2927,  2929,  2931
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
     343,   344,    -1,   119,    -1,   998,    -1,   345,    -1,   346,
      -1,    10,   120,    -1,    11,    -1,    10,   347,   120,    -1,
     348,    -1,   349,    -1,   348,   349,    -1,   350,   351,   354,
      -1,   121,    -1,   352,    -1,    -1,   352,   353,    -1,   957,
      -1,   984,    -1,   940,    -1,    10,   122,    -1,    11,    -1,
      -1,   356,   357,    -1,    71,    -1,   358,    -1,   359,    -1,
      10,    72,    -1,    11,    -1,    10,   360,    72,    -1,   361,
      -1,   362,    -1,   361,   362,    -1,   363,    -1,   370,    -1,
     377,    -1,   384,    -1,   389,    -1,   364,   365,   368,    -1,
     123,    -1,   366,    -1,    -1,   366,   367,    -1,   980,    -1,
     940,    -1,    10,   369,   124,    -1,  1031,    -1,   371,   372,
     375,    -1,   125,    -1,   373,    -1,    -1,   373,   374,    -1,
     980,    -1,   940,    -1,    10,   376,   126,    -1,  1031,    -1,
     378,   379,   382,    -1,   127,    -1,   380,    -1,    -1,   380,
     381,    -1,   980,    -1,   940,    -1,    10,   383,   128,    -1,
    1031,    -1,   385,   386,   387,    -1,   129,    -1,    -1,   940,
      -1,    10,   388,   130,    -1,     6,    -1,   390,   391,   392,
      -1,   119,    -1,   998,    -1,   393,    -1,   394,    -1,    10,
     120,    -1,    11,    -1,    10,   395,   120,    -1,   396,    -1,
     397,    -1,   396,   397,    -1,   398,   399,   402,    -1,   121,
      -1,   400,    -1,    -1,   400,   401,    -1,   957,    -1,   984,
      -1,   940,    -1,    10,   122,    -1,    11,    -1,    -1,   404,
     405,    -1,    73,    -1,   406,    -1,   407,    -1,    10,    74,
      -1,    11,    -1,    10,   408,    74,    -1,   409,    -1,   410,
      -1,   409,   410,    -1,   411,    -1,   417,    -1,   412,   413,
      -1,   131,    -1,   414,    -1,   415,    -1,    10,   132,    -1,
      11,    -1,    10,   416,   132,    -1,     4,    -1,   418,   419,
     420,    -1,   119,    -1,   998,    -1,   421,    -1,   422,    -1,
      10,   120,    -1,    11,    -1,    10,   423,   120,    -1,   424,
      -1,   425,    -1,   424,   425,    -1,   426,   427,   430,    -1,
     121,    -1,   428,    -1,    -1,   428,   429,    -1,   957,    -1,
     984,    -1,   940,    -1,    10,   122,    -1,    11,    -1,    -1,
     432,   433,    -1,    75,    -1,   434,    -1,   435,    -1,    10,
      76,    -1,    11,    -1,    10,   436,    76,    -1,   437,    -1,
     438,    -1,   437,   438,    -1,   439,    -1,   447,    -1,   453,
      -1,   461,    -1,   469,    -1,   477,    -1,   485,    -1,   493,
      -1,   501,    -1,   517,    -1,   509,    -1,   525,    -1,   533,
      -1,   541,    -1,   549,    -1,   440,   441,   442,    -1,   133,
      -1,   980,    -1,   443,    -1,   444,    -1,    10,   134,    -1,
      11,    -1,    10,   445,   134,    -1,   446,    -1,  1031,    -1,
     448,   449,    -1,   135,    -1,   450,    -1,   451,    -1,    10,
     136,    -1,    11,    -1,    10,   452,   136,    -1,     4,    -1,
     454,   455,   456,    -1,   137,    -1,   993,    -1,   457,    -1,
     458,    -1,    10,   138,    -1,    11,    -1,    10,   459,   138,
      -1,   460,    -1,   459,   460,    -1,   107,    10,     4,   108,
      -1,   462,   463,   464,    -1,   139,    -1,  1001,    -1,   465,
      -1,   466,    -1,    10,   140,    -1,    11,    -1,    10,   467,
     140,    -1,   468,    -1,   467,   468,    -1,   143,    10,     4,
     144,    -1,   470,   471,   472,    -1,   141,    -1,  1001,    -1,
     473,    -1,   474,    -1,    10,   142,    -1,    11,    -1,    10,
     475,   142,    -1,   476,    -1,   475,   476,    -1,   143,    10,
       4,   144,    -1,   478,   479,   480,    -1,   147,    -1,  1001,
      -1,   481,    -1,   482,    -1,    10,   148,    -1,    11,    -1,
      10,   483,   148,    -1,   484,    -1,   483,   484,    -1,   143,
      10,     4,   144,    -1,   486,   487,   488,    -1,   149,    -1,
    1001,    -1,   489,    -1,   490,    -1,    10,   150,    -1,    11,
      -1,    10,   491,   150,    -1,   492,    -1,   491,   492,    -1,
     143,    10,     4,   144,    -1,   494,   495,   496,    -1,   155,
      -1,  1000,    -1,   497,    -1,   498,    -1,    10,   156,    -1,
      11,    -1,    10,   499,   156,    -1,   500,    -1,   499,   500,
      -1,   927,    -1,   502,   503,   504,    -1,   157,    -1,  1000,
      -1,   505,    -1,   506,    -1,    10,   158,    -1,    11,    -1,
      10,   507,   158,    -1,   508,    -1,   507,   508,    -1,   927,
      -1,   510,   511,   512,    -1,   161,    -1,  1000,    -1,   513,
      -1,   514,    -1,    10,   162,    -1,    11,    -1,    10,   515,
     162,    -1,   516,    -1,   515,   516,    -1,   927,    -1,   518,
     519,   520,    -1,   159,    -1,  1000,    -1,   521,    -1,   522,
      -1,    10,   160,    -1,    11,    -1,    10,   523,   160,    -1,
     524,    -1,   523,   524,    -1,   927,    -1,   526,   527,   528,
      -1,   153,    -1,  1001,    -1,   529,    -1,   530,    -1,    10,
     154,    -1,    11,    -1,    10,   531,   154,    -1,   532,    -1,
     531,   532,    -1,   143,    10,     4,   144,    -1,   534,   535,
     536,    -1,   151,    -1,  1001,    -1,   537,    -1,   538,    -1,
      10,   152,    -1,    11,    -1,    10,   539,   152,    -1,   540,
      -1,   539,   540,    -1,   143,    10,     4,   144,    -1,   542,
     543,   544,    -1,   163,    -1,  1002,    -1,   545,    -1,   546,
      -1,    10,   164,    -1,    11,    -1,    10,   547,   164,    -1,
     548,    -1,   547,   548,    -1,   165,    10,     4,   166,    -1,
     550,   551,   552,    -1,   119,    -1,   998,    -1,   553,    -1,
     554,    -1,    10,   120,    -1,    11,    -1,    10,   555,   120,
      -1,   556,    -1,   557,    -1,   556,   557,    -1,   558,   559,
     562,    -1,   121,    -1,   560,    -1,    -1,   560,   561,    -1,
     957,    -1,   984,    -1,   940,    -1,    10,   122,    -1,    11,
      -1,    -1,   564,   565,   568,    -1,    77,    -1,   566,    -1,
      -1,   566,   567,    -1,  1005,    -1,   989,    -1,   995,    -1,
     569,    -1,   570,    -1,    11,    -1,    10,   571,    78,    -1,
     572,   702,   804,   905,    -1,    -1,   573,   574,   576,    -1,
     167,    -1,   575,    -1,    -1,   999,    -1,   577,    -1,   578,
      -1,    11,    -1,    10,   579,   168,    -1,   580,   593,   607,
     655,   669,   684,    -1,    -1,   581,   582,   583,    -1,   169,
      -1,  1004,    -1,   584,    -1,   585,    -1,    10,   170,    -1,
      11,    -1,    10,   586,   170,    -1,   587,    -1,   588,    -1,
     587,   588,    -1,   589,   590,   592,    -1,   171,    -1,    -1,
     590,   591,    -1,   946,    -1,   984,    -1,    10,   172,    -1,
      11,    -1,    -1,   594,   595,   596,    -1,   173,    -1,  1004,
      -1,   597,    -1,   598,    -1,    10,   174,    -1,    11,    -1,
      10,   599,   174,    -1,   600,    -1,   601,    -1,   600,   601,
      -1,   602,   603,   606,    -1,   171,    -1,   604,    -1,    -1,
     604,   605,    -1,   946,    -1,   984,    -1,    10,   172,    -1,
      11,    -1,    -1,   608,   609,    -1,   175,    -1,   610,    -1,
     611,    -1,    11,    -1,    10,   612,   176,    -1,   613,   620,
     627,   634,   641,   648,    -1,    -1,   614,   615,   616,    -1,
     177,    -1,   990,    -1,   617,    -1,   618,    -1,    11,    -1,
      10,   619,   178,    -1,  1016,    -1,    -1,   621,   622,   623,
      -1,   181,    -1,   990,    -1,   624,    -1,   625,    -1,    11,
      -1,    10,   626,   182,    -1,  1016,    -1,    -1,   628,   629,
     630,    -1,   179,    -1,   990,    -1,   631,    -1,   632,    -1,
      11,    -1,    10,   633,   180,    -1,  1016,    -1,    -1,   635,
     636,   637,    -1,   185,    -1,   990,    -1,   638,    -1,   639,
      -1,    11,    -1,    10,   640,   186,    -1,  1016,    -1,    -1,
     642,   643,   644,    -1,   183,    -1,   990,    -1,   645,    -1,
     646,    -1,    11,    -1,    10,   647,   184,    -1,  1016,    -1,
      -1,   649,   650,   651,    -1,   187,    -1,   990,    -1,   652,
      -1,   653,    -1,    11,    -1,    10,   654,   188,    -1,  1016,
      -1,    -1,   656,   657,   658,    -1,   189,    -1,  1004,    -1,
     659,    -1,   660,    -1,    10,   190,    -1,    11,    -1,    10,
     661,   190,    -1,   662,    -1,   663,    -1,   662,   663,    -1,
     664,   665,   668,    -1,   171,    -1,   666,    -1,    -1,   666,
     667,    -1,   946,    -1,   984,    -1,    10,   172,    -1,    11,
      -1,    -1,   670,   671,   672,    -1,   191,    -1,    29,     8,
       6,     8,    -1,   673,    -1,   674,    -1,    10,   192,    -1,
      11,    -1,    10,   675,   192,    -1,   676,    -1,   675,   676,
      -1,   677,   678,   681,    -1,   193,    -1,   679,    -1,    -1,
     679,   680,    -1,   965,    -1,  1004,    -1,   944,    -1,   682,
      -1,   683,    -1,    10,   194,    -1,    11,    -1,    10,   662,
     194,    -1,    -1,   684,   685,    -1,   686,   687,   690,    -1,
     121,    -1,   688,    -1,    -1,   688,   689,    -1,  1004,    -1,
     991,    -1,   957,    -1,   984,    -1,   961,    -1,   936,    -1,
     968,    -1,   940,    -1,   691,    -1,   692,    -1,    10,   122,
      -1,    11,    -1,    10,   693,   122,    -1,   694,    -1,  1006,
      -1,   695,    -1,   694,   695,    -1,   696,   697,   700,    -1,
     171,    -1,   698,    -1,    -1,   698,   699,    -1,   946,    -1,
     984,    -1,   949,    -1,   972,    -1,   701,    -1,    10,   172,
      -1,    11,    -1,    -1,   703,   704,   706,    -1,   195,    -1,
     705,    -1,    -1,   997,    -1,   707,    -1,   708,    -1,    11,
      -1,    10,   709,   196,    -1,   710,   724,   738,   786,    -1,
      -1,   711,   712,   713,    -1,   197,    -1,   994,    -1,   714,
      -1,   715,    -1,    10,   198,    -1,    11,    -1,    10,   716,
     198,    -1,   717,    -1,   718,    -1,   717,   718,    -1,   719,
     720,   723,    -1,   199,    -1,   721,    -1,    -1,   721,   722,
      -1,   946,    -1,   984,    -1,    10,   200,    -1,    11,    -1,
      -1,   725,   726,   727,    -1,   201,    -1,   994,    -1,   728,
      -1,   729,    -1,    10,   202,    -1,    11,    -1,    10,   730,
     202,    -1,   731,    -1,   732,    -1,   731,   732,    -1,   733,
     734,   737,    -1,   199,    -1,   735,    -1,    -1,   735,   736,
      -1,   946,    -1,   949,    -1,   972,    -1,    10,   200,    -1,
      11,    -1,    -1,   739,   740,    -1,   175,    -1,   741,    -1,
     742,    -1,    11,    -1,    10,   743,   176,    -1,   744,   751,
     758,   765,   772,   779,    -1,    -1,   745,   746,   747,    -1,
     177,    -1,   990,    -1,   748,    -1,   749,    -1,    11,    -1,
      10,   750,   178,    -1,  1016,    -1,    -1,   752,   753,   754,
      -1,   181,    -1,   990,    -1,   755,    -1,   756,    -1,    11,
      -1,    10,   757,   182,    -1,  1016,    -1,    -1,   759,   760,
     761,    -1,   179,    -1,   990,    -1,   762,    -1,   763,    -1,
      11,    -1,    10,   764,   180,    -1,  1016,    -1,    -1,   766,
     767,   768,    -1,   185,    -1,   990,    -1,   769,    -1,   770,
      -1,    11,    -1,    10,   771,   186,    -1,  1016,    -1,    -1,
     773,   774,   775,    -1,   183,    -1,   990,    -1,   776,    -1,
     777,    -1,    11,    -1,    10,   778,   184,    -1,  1016,    -1,
      -1,   780,   781,   782,    -1,   187,    -1,   990,    -1,   783,
      -1,   784,    -1,    11,    -1,    10,   785,   188,    -1,  1016,
      -1,    -1,   786,   787,    -1,   788,   789,   792,    -1,   121,
      -1,   790,    -1,    -1,   790,   791,    -1,   994,    -1,   991,
      -1,   957,    -1,   984,    -1,   961,    -1,   936,    -1,   968,
      -1,   940,    -1,   793,    -1,   794,    -1,    10,   122,    -1,
      11,    -1,    10,   795,   122,    -1,   796,    -1,  1006,    -1,
     797,    -1,   796,   797,    -1,   798,   799,   802,    -1,   199,
      -1,   800,    -1,    -1,   800,   801,    -1,   946,    -1,   984,
      -1,   949,    -1,   972,    -1,   803,    -1,    10,   200,    -1,
      11,    -1,    -1,   805,   806,   808,    -1,   203,    -1,   807,
      -1,    -1,   996,    -1,   809,    -1,   810,    -1,    11,    -1,
      10,   811,   204,    -1,   812,   825,   839,   887,    -1,    -1,
     813,   814,   815,    -1,   205,    -1,   988,    -1,   816,    -1,
     817,    -1,    10,   206,    -1,    11,    -1,    10,   818,   206,
      -1,   819,    -1,   820,    -1,   819,   820,    -1,   821,   822,
     824,    -1,   207,    -1,    -1,   822,   823,    -1,   946,    -1,
     984,    -1,    10,   208,    -1,    11,    -1,    -1,   826,   827,
     828,    -1,   209,    -1,   988,    -1,   829,    -1,   830,    -1,
      10,   210,    -1,    11,    -1,    10,   831,   210,    -1,   832,
      -1,   833,    -1,   832,   833,    -1,   834,   835,   838,    -1,
     207,    -1,   836,    -1,    -1,   836,   837,    -1,   946,    -1,
     953,    -1,   976,    -1,    10,   208,    -1,    11,    -1,    -1,
     840,   841,    -1,   175,    -1,   842,    -1,   843,    -1,    11,
      -1,    10,   844,   176,    -1,   845,   852,   859,   866,   873,
     880,    -1,    -1,   846,   847,   848,    -1,   177,    -1,   990,
      -1,   849,    -1,   850,    -1,    11,    -1,    10,   851,   178,
      -1,  1016,    -1,    -1,   853,   854,   855,    -1,   181,    -1,
     990,    -1,   856,    -1,   857,    -1,    11,    -1,    10,   858,
     182,    -1,  1016,    -1,    -1,   860,   861,   862,    -1,   179,
      -1,   990,    -1,   863,    -1,   864,    -1,    11,    -1,    10,
     865,   180,    -1,  1016,    -1,    -1,   867,   868,   869,    -1,
     185,    -1,   990,    -1,   870,    -1,   871,    -1,    11,    -1,
      10,   872,   186,    -1,  1016,    -1,    -1,   874,   875,   876,
      -1,   183,    -1,   990,    -1,   877,    -1,   878,    -1,    11,
      -1,    10,   879,   184,    -1,  1016,    -1,    -1,   881,   882,
     883,    -1,   187,    -1,   990,    -1,   884,    -1,   885,    -1,
      11,    -1,    10,   886,   188,    -1,  1016,    -1,    -1,   887,
     888,    -1,   889,   890,   893,    -1,   121,    -1,   891,    -1,
      -1,   891,   892,    -1,   988,    -1,   991,    -1,   957,    -1,
     984,    -1,   961,    -1,   936,    -1,   968,    -1,   940,    -1,
     894,    -1,   895,    -1,    10,   122,    -1,    11,    -1,    10,
     896,   122,    -1,   897,    -1,  1006,    -1,   898,    -1,   897,
     898,    -1,   899,   900,   903,    -1,   207,    -1,   901,    -1,
      -1,   901,   902,    -1,   946,    -1,   984,    -1,   949,    -1,
     972,    -1,   904,    -1,    10,   208,    -1,    11,    -1,    -1,
     906,   907,   908,    -1,   211,    -1,  1003,    -1,   909,    -1,
     910,    -1,    11,    -1,    10,   911,   212,    -1,    -1,   911,
     912,    -1,   913,   914,   917,    -1,   213,    -1,   915,    -1,
     916,    -1,   915,   916,    -1,   957,    -1,   984,    -1,   961,
      -1,   936,    -1,   968,    -1,   940,    -1,   992,    -1,   918,
      -1,   919,    -1,    10,   214,    -1,    11,    -1,    10,   920,
     214,    -1,   921,    -1,   922,    -1,   921,   922,    -1,   923,
      -1,   924,    -1,   925,    -1,   220,    -1,   217,    -1,   218,
     926,   219,    -1,     5,    -1,   928,   929,   935,    -1,   145,
      -1,   930,    -1,    -1,   930,   931,    -1,   932,    -1,   933,
      -1,   934,    -1,    21,     3,     8,    -1,    22,     3,     8,
      -1,    23,     3,     8,    -1,    10,   146,    -1,    11,    -1,
     937,    -1,   938,    -1,   939,    -1,    49,    -1,    24,     3,
    1032,    -1,   941,    -1,   942,    -1,   943,    -1,    50,    -1,
      46,     3,  1032,    -1,   945,    -1,    26,     8,  1031,     8,
      -1,   947,    -1,   948,    -1,    42,  1032,     6,  1032,    -1,
     950,    -1,   951,    -1,   952,    -1,    53,    -1,    55,     3,
    1032,    -1,   954,    -1,   955,    -1,   956,    -1,    57,    -1,
      59,  1032,  1031,  1032,    -1,   958,    -1,   959,    -1,   960,
      -1,    48,    -1,    41,     3,  1032,    -1,   962,    -1,   963,
      -1,   964,    -1,    62,    -1,    61,     3,  1032,    -1,   966,
      -1,   967,    -1,    43,  1032,     6,  1032,    -1,   969,    -1,
     970,    -1,   971,    -1,    47,    -1,    25,     3,     8,    -1,
     973,    -1,   974,    -1,   975,    -1,    54,    -1,    56,     3,
    1032,    -1,   977,    -1,   978,    -1,   979,    -1,    58,    -1,
      60,  1032,  1031,  1032,    -1,   981,    -1,   982,    -1,   983,
      -1,    51,    -1,    45,     3,     8,    -1,   985,    -1,   986,
      -1,   987,    -1,    52,    -1,    44,     3,     8,    -1,    39,
    1032,     6,  1032,    -1,    32,  1032,     6,  1032,    -1,    40,
    1032,     6,  1032,    -1,    17,  1032,     6,  1032,    -1,    36,
    1032,     6,  1032,    -1,    18,     8,     6,     8,    -1,    38,
    1032,     6,  1032,    -1,    31,  1032,     6,  1032,    -1,    35,
    1032,     6,  1032,    -1,    34,  1032,     6,  1032,    -1,    16,
    1032,     6,  1032,    -1,    33,  1032,     6,  1032,    -1,    20,
       8,     6,     8,    -1,    19,     8,     6,     8,    -1,    27,
       8,     6,     8,    -1,    28,  1032,     6,  1032,    -1,    37,
    1032,     6,  1032,    -1,    30,  1032,     6,  1032,    -1,  1007,
      -1,  1006,  1007,    -1,  1008,  1009,  1012,    -1,   215,    -1,
    1010,    -1,    -1,  1010,  1011,    -1,   990,    -1,   984,    -1,
     940,    -1,  1013,    -1,  1014,    -1,    11,    -1,    10,  1015,
     216,    -1,  1016,    -1,  1017,    -1,  1024,    -1,    -1,  1017,
    1018,    -1,  1019,  1020,  1023,    -1,   226,    -1,  1021,    -1,
      -1,  1021,  1022,    -1,  1030,    -1,  1029,    -1,    10,     6,
     227,    -1,   221,  1025,  1026,    -1,   225,  1032,     6,  1032,
      -1,  1027,    -1,  1028,    -1,    10,   222,    -1,    11,    -1,
      10,     4,   222,    -1,   223,  1032,     6,  1032,    -1,   224,
    1032,     6,  1032,    -1,     6,    -1,     7,    -1,  1033,     8,
      -1,    -1,  1033,  1034,    -1,   229,    -1,   230,    -1,   231,
      -1,   232,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   163,   163,   164,   166,   173,   180,   180,   182,   182,
     184,   186,   188,   189,   192,   200,   200,   207,   216,   216,
     218,   220,   222,   224,   224,   226,   226,   228,   228,   230,
     235,   235,   237,   237,   239,   239,   241,   246,   246,   248,
     248,   250,   250,   252,   257,   257,   259,   259,   261,   261,
     263,   268,   268,   270,   270,   272,   272,   274,   284,   284,
     286,   302,   302,   304,   304,   306,   308,   310,   310,   313,
     314,   315,   316,   317,   318,   319,   320,   321,   322,   323,
     327,   329,   337,   337,   339,   339,   341,   343,   353,   355,
     361,   361,   363,   363,   365,   367,   376,   378,   384,   384,
     386,   386,   388,   390,   400,   407,   415,   416,   423,   429,
     429,   431,   431,   433,   435,   443,   445,   451,   451,   453,
     453,   455,   457,   466,   468,   475,   475,   477,   477,   479,
     481,   491,   493,   500,   500,   502,   502,   504,   506,   516,
     518,   524,   524,   526,   526,   528,   530,   540,   542,   548,
     548,   550,   550,   552,   554,   564,   571,   580,   581,   587,
     594,   594,   596,   596,   598,   600,   607,   609,   615,   623,
     627,   632,   632,   634,   636,   640,   640,   642,   649,   660,
     666,   666,   669,   673,   674,   677,   677,   686,   686,   688,
     698,   698,   700,   700,   702,   704,   706,   706,   709,   710,
     711,   712,   713,   717,   719,   729,   731,   731,   734,   735,
     738,   740,   748,   750,   760,   762,   762,   765,   766,   769,
     771,   780,   782,   792,   794,   794,   797,   798,   801,   803,
     812,   814,   822,   823,   825,   827,   838,   840,   847,   855,
     859,   864,   864,   866,   868,   872,   872,   874,   881,   892,
     897,   897,   900,   905,   906,   909,   909,   918,   918,   920,
     927,   927,   929,   929,   931,   933,   935,   935,   938,   939,
     943,   945,   951,   951,   953,   953,   955,   957,   968,   970,
     977,   985,   989,   994,   994,   996,   998,  1002,  1002,  1004,
    1011,  1022,  1027,  1027,  1030,  1035,  1036,  1039,  1039,  1047,
    1047,  1049,  1069,  1069,  1071,  1071,  1073,  1075,  1077,  1077,
    1080,  1081,  1082,  1083,  1084,  1085,  1086,  1087,  1088,  1089,
    1090,  1091,  1092,  1093,  1094,  1099,  1105,  1115,  1117,  1117,
    1119,  1119,  1121,  1123,  1125,  1132,  1134,  1140,  1140,  1142,
    1142,  1144,  1146,  1156,  1164,  1171,  1173,  1173,  1175,  1175,
    1177,  1183,  1183,  1185,  1196,  1204,  1210,  1212,  1212,  1214,
    1214,  1216,  1222,  1222,  1224,  1235,  1243,  1249,  1251,  1251,
    1253,  1253,  1255,  1261,  1261,  1263,  1273,  1281,  1287,  1289,
    1289,  1291,  1291,  1293,  1299,  1299,  1301,  1311,  1319,  1325,
    1327,  1327,  1329,  1329,  1331,  1337,  1337,  1339,  1350,  1363,
    1369,  1371,  1371,  1373,  1373,  1375,  1381,  1381,  1383,  1387,
    1400,  1406,  1408,  1408,  1410,  1410,  1412,  1418,  1418,  1420,
    1424,  1437,  1443,  1445,  1445,  1447,  1447,  1449,  1455,  1455,
    1457,  1461,  1474,  1480,  1482,  1482,  1484,  1484,  1486,  1492,
    1492,  1494,  1498,  1506,  1512,  1514,  1514,  1516,  1516,  1518,
    1524,  1524,  1526,  1537,  1545,  1551,  1553,  1553,  1555,  1555,
    1557,  1563,  1563,  1565,  1576,  1584,  1591,  1593,  1593,  1595,
    1595,  1597,  1603,  1603,  1605,  1617,  1619,  1625,  1633,  1637,
    1642,  1642,  1644,  1646,  1650,  1650,  1652,  1659,  1670,  1675,
    1675,  1678,  1683,  1684,  1687,  1687,  1695,  1695,  1697,  1705,
    1707,  1707,  1710,  1716,  1722,  1730,  1730,  1732,  1734,  1736,
    1743,  1743,  1745,  1751,  1758,  1758,  1763,  1763,  1765,  1767,
    1769,  1774,  1774,  1784,  1789,  1797,  1802,  1808,  1808,  1810,
    1812,  1814,  1814,  1817,  1822,  1830,  1830,  1833,  1844,  1851,
    1851,  1855,  1855,  1865,  1870,  1878,  1883,  1889,  1889,  1891,
    1893,  1895,  1895,  1898,  1903,  1912,  1918,  1918,  1921,  1931,
    1934,  1934,  1938,  1938,  1940,  1945,  1945,  1947,  1949,  1951,
    1954,  1954,  1962,  1968,  1975,  1975,  1977,  1979,  1981,  1985,
    1985,  1994,  2000,  2007,  2007,  2009,  2011,  2013,  2017,  2017,
    2025,  2031,  2038,  2038,  2040,  2042,  2044,  2048,  2048,  2056,
    2062,  2069,  2069,  2071,  2073,  2075,  2079,  2079,  2087,  2093,
    2100,  2100,  2102,  2104,  2106,  2110,  2110,  2118,  2124,  2131,
    2131,  2133,  2135,  2137,  2141,  2141,  2152,  2157,  2165,  2170,
    2176,  2176,  2178,  2180,  2184,  2184,  2186,  2191,  2200,  2206,
    2206,  2209,  2219,  2225,  2225,  2229,  2229,  2231,  2237,  2245,
    2249,  2254,  2254,  2256,  2258,  2258,  2260,  2274,  2284,  2292,
    2292,  2295,  2296,  2303,  2306,  2306,  2308,  2308,  2310,  2315,
    2315,  2317,  2322,  2344,  2361,  2361,  2364,  2368,  2372,  2373,
    2374,  2375,  2376,  2377,  2380,  2380,  2382,  2382,  2384,  2386,
    2386,  2388,  2388,  2391,  2404,  2417,  2419,  2419,  2422,  2432,
    2433,  2434,  2437,  2439,  2439,  2447,  2447,  2449,  2455,  2462,
    2462,  2467,  2467,  2469,  2471,  2473,  2477,  2477,  2488,  2494,
    2502,  2507,  2513,  2513,  2515,  2517,  2519,  2519,  2522,  2527,
    2536,  2542,  2542,  2545,  2555,  2562,  2562,  2565,  2565,  2578,
    2583,  2592,  2597,  2603,  2603,  2605,  2607,  2609,  2609,  2612,
    2617,  2629,  2636,  2636,  2639,  2649,  2654,  2660,  2660,  2664,
    2664,  2666,  2671,  2671,  2673,  2675,  2677,  2680,  2680,  2688,
    2694,  2701,  2701,  2703,  2705,  2707,  2710,  2710,  2718,  2724,
    2731,  2731,  2733,  2735,  2737,  2740,  2740,  2748,  2754,  2761,
    2761,  2763,  2765,  2767,  2770,  2770,  2778,  2784,  2791,  2791,
    2793,  2795,  2797,  2800,  2800,  2808,  2815,  2822,  2822,  2824,
    2826,  2828,  2832,  2832,  2840,  2846,  2853,  2853,  2855,  2857,
    2859,  2863,  2863,  2865,  2871,  2893,  2910,  2910,  2913,  2917,
    2921,  2922,  2923,  2924,  2925,  2926,  2929,  2929,  2931,  2931,
    2933,  2935,  2935,  2937,  2937,  2940,  2953,  2967,  2975,  2975,
    2978,  2988,  2989,  2990,  2993,  2995,  2995,  3003,  3003,  3005,
    3011,  3018,  3018,  3023,  3023,  3025,  3027,  3029,  3033,  3033,
    3044,  3049,  3057,  3062,  3068,  3068,  3070,  3072,  3074,  3074,
    3077,  3082,  3090,  3090,  3093,  3104,  3111,  3111,  3115,  3115,
    3128,  3133,  3142,  3147,  3153,  3153,  3155,  3157,  3159,  3159,
    3162,  3167,  3178,  3184,  3184,  3187,  3198,  3199,  3202,  3202,
    3206,  3206,  3208,  3213,  3213,  3215,  3217,  3219,  3222,  3222,
    3230,  3236,  3243,  3243,  3245,  3247,  3249,  3252,  3252,  3260,
    3266,  3273,  3273,  3275,  3277,  3279,  3283,  3283,  3291,  3297,
    3304,  3304,  3306,  3308,  3310,  3314,  3314,  3322,  3328,  3335,
    3335,  3337,  3339,  3341,  3345,  3345,  3353,  3359,  3366,  3366,
    3368,  3370,  3372,  3376,  3376,  3384,  3390,  3397,  3397,  3399,
    3401,  3403,  3407,  3407,  3409,  3415,  3437,  3454,  3454,  3457,
    3461,  3465,  3466,  3467,  3468,  3469,  3470,  3473,  3473,  3475,
    3475,  3477,  3479,  3479,  3481,  3481,  3484,  3497,  3510,  3512,
    3512,  3515,  3525,  3526,  3527,  3530,  3532,  3532,  3540,  3540,
    3542,  3544,  3552,  3557,  3563,  3565,  3567,  3567,  3571,  3590,
    3608,  3614,  3614,  3617,  3618,  3619,  3620,  3621,  3622,  3623,
    3630,  3634,  3639,  3639,  3641,  3643,  3645,  3645,  3647,  3654,
    3660,  3662,  3662,  3664,  3666,  3677,  3686,  3696,  3701,  3701,
    3704,  3705,  3706,  3708,  3716,  3724,  3732,  3732,  3738,  3745,
    3745,  3747,  3752,  3759,  3766,  3766,  3768,  3771,  3778,  3785,
    3792,  3799,  3801,  3807,  3814,  3814,  3816,  3821,  3828,  3834,
    3834,  3836,  3839,  3844,  3850,  3850,  3852,  3855,  3862,  3868,
    3868,  3870,  3873,  3880,  3886,  3888,  3896,  3902,  3902,  3904,
    3907,  3914,  3921,  3921,  3923,  3928,  3935,  3941,  3941,  3943,
    3946,  3953,  3959,  3959,  3961,  3964,  3971,  3977,  3977,  3979,
    3982,  3994,  4003,  4012,  4021,  4030,  4039,  4048,  4057,  4065,
    4071,  4077,  4083,  4089,  4100,  4109,  4119,  4125,  4134,  4154,
    4154,  4156,  4173,  4184,  4191,  4191,  4194,  4201,  4202,  4206,
    4206,  4208,  4210,  4212,  4229,  4234,  4236,  4236,  4238,  4240,
    4249,  4251,  4251,  4253,  4253,  4255,  4263,  4265,  4270,  4270,
    4272,  4272,  4274,  4297,  4305,  4319,  4320,  4327,  4329,  4329,
    4331,  4332,  4333,  4334
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
  "initVarValueAttList", "initVarValueAtt", "initVarValueContent",
  "initialVariableValuesString", "initialVariableValuesStringStart",
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
  "initConValueStart", "initConValueAttList", "initConValueAtt",
  "initConValueContent", "initialDualValues", "initialDualValuesStart",
  "numberOfConATT", "initialDualValuesContent", "initialDualValuesEmpty",
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
     438,   438,   438,   438,   438,   439,   440,   441,   442,   442,
     443,   443,   444,   445,   446,   447,   448,   449,   449,   450,
     450,   451,   452,   453,   454,   455,   456,   456,   457,   457,
     458,   459,   459,   460,   461,   462,   463,   464,   464,   465,
     465,   466,   467,   467,   468,   469,   470,   471,   472,   472,
     473,   473,   474,   475,   475,   476,   477,   478,   479,   480,
     480,   481,   481,   482,   483,   483,   484,   485,   486,   487,
     488,   488,   489,   489,   490,   491,   491,   492,   493,   494,
     495,   496,   496,   497,   497,   498,   499,   499,   500,   501,
     502,   503,   504,   504,   505,   505,   506,   507,   507,   508,
     509,   510,   511,   512,   512,   513,   513,   514,   515,   515,
     516,   517,   518,   519,   520,   520,   521,   521,   522,   523,
     523,   524,   525,   526,   527,   528,   528,   529,   529,   530,
     531,   531,   532,   533,   534,   535,   536,   536,   537,   537,
     538,   539,   539,   540,   541,   542,   543,   544,   544,   545,
     545,   546,   547,   547,   548,   549,   550,   551,   552,   552,
     553,   553,   554,   555,   556,   556,   557,   558,   559,   560,
     560,   561,   561,   561,   562,   562,   563,   563,   564,   565,
     566,   566,   567,   567,   567,   568,   568,   569,   570,   571,
     572,   572,   573,   574,   575,   575,   576,   576,   577,   578,
     579,   580,   580,   581,   582,   583,   583,   584,   584,   585,
     586,   587,   587,   588,   589,   590,   590,   591,   591,   592,
     592,   593,   593,   594,   595,   596,   596,   597,   597,   598,
     599,   600,   600,   601,   602,   603,   604,   604,   605,   605,
     606,   606,   607,   607,   608,   609,   609,   610,   611,   612,
     613,   613,   614,   615,   616,   616,   617,   618,   619,   620,
     620,   621,   622,   623,   623,   624,   625,   626,   627,   627,
     628,   629,   630,   630,   631,   632,   633,   634,   634,   635,
     636,   637,   637,   638,   639,   640,   641,   641,   642,   643,
     644,   644,   645,   646,   647,   648,   648,   649,   650,   651,
     651,   652,   653,   654,   655,   655,   656,   657,   658,   658,
     659,   659,   660,   661,   662,   662,   663,   664,   665,   666,
     666,   667,   667,   668,   668,   669,   669,   670,   671,   672,
     672,   673,   673,   674,   675,   675,   676,   677,   678,   679,
     679,   680,   680,   680,   681,   681,   682,   682,   683,   684,
     684,   685,   686,   687,   688,   688,   689,   689,   689,   689,
     689,   689,   689,   689,   690,   690,   691,   691,   692,   693,
     693,   694,   694,   695,   696,   697,   698,   698,   699,   699,
     699,   699,   700,   701,   701,   702,   702,   703,   704,   705,
     705,   706,   706,   707,   708,   709,   710,   710,   711,   712,
     713,   713,   714,   714,   715,   716,   717,   717,   718,   719,
     720,   721,   721,   722,   722,   723,   723,   724,   724,   725,
     726,   727,   727,   728,   728,   729,   730,   731,   731,   732,
     733,   734,   735,   735,   736,   736,   736,   737,   737,   738,
     738,   739,   740,   740,   741,   742,   743,   744,   744,   745,
     746,   747,   747,   748,   749,   750,   751,   751,   752,   753,
     754,   754,   755,   756,   757,   758,   758,   759,   760,   761,
     761,   762,   763,   764,   765,   765,   766,   767,   768,   768,
     769,   770,   771,   772,   772,   773,   774,   775,   775,   776,
     777,   778,   779,   779,   780,   781,   782,   782,   783,   784,
     785,   786,   786,   787,   788,   789,   790,   790,   791,   791,
     791,   791,   791,   791,   791,   791,   792,   792,   793,   793,
     794,   795,   795,   796,   796,   797,   798,   799,   800,   800,
     801,   801,   801,   801,   802,   803,   803,   804,   804,   805,
     806,   807,   807,   808,   808,   809,   810,   811,   812,   812,
     813,   814,   815,   815,   816,   816,   817,   818,   819,   819,
     820,   821,   822,   822,   823,   823,   824,   824,   825,   825,
     826,   827,   828,   828,   829,   829,   830,   831,   832,   832,
     833,   834,   835,   836,   836,   837,   837,   837,   838,   838,
     839,   839,   840,   841,   841,   842,   843,   844,   845,   845,
     846,   847,   848,   848,   849,   850,   851,   852,   852,   853,
     854,   855,   855,   856,   857,   858,   859,   859,   860,   861,
     862,   862,   863,   864,   865,   866,   866,   867,   868,   869,
     869,   870,   871,   872,   873,   873,   874,   875,   876,   876,
     877,   878,   879,   880,   880,   881,   882,   883,   883,   884,
     885,   886,   887,   887,   888,   889,   890,   891,   891,   892,
     892,   892,   892,   892,   892,   892,   892,   893,   893,   894,
     894,   895,   896,   896,   897,   897,   898,   899,   900,   901,
     901,   902,   902,   902,   902,   903,   904,   904,   905,   905,
     906,   907,   908,   908,   909,   910,   911,   911,   912,   913,
     914,   915,   915,   916,   916,   916,   916,   916,   916,   916,
     917,   917,   918,   918,   919,   920,   921,   921,   922,   923,
     923,   924,   924,   925,   926,   927,   928,   929,   930,   930,
     931,   931,   931,   932,   933,   934,   935,   935,   936,   937,
     937,   938,   939,   940,   941,   941,   942,   943,   944,   945,
     946,   947,   948,   949,   950,   950,   951,   952,   953,   954,
     954,   955,   956,   957,   958,   958,   959,   960,   961,   962,
     962,   963,   964,   965,   966,   967,   968,   969,   969,   970,
     971,   972,   973,   973,   974,   975,   976,   977,   977,   978,
     979,   980,   981,   981,   982,   983,   984,   985,   985,   986,
     987,   988,   989,   990,   991,   992,   993,   994,   995,   996,
     997,   998,   999,  1000,  1001,  1002,  1003,  1004,  1005,  1006,
    1006,  1007,  1008,  1009,  1010,  1010,  1011,  1011,  1011,  1012,
    1012,  1013,  1014,  1015,  1016,  1016,  1017,  1017,  1018,  1019,
    1020,  1021,  1021,  1022,  1022,  1023,  1024,  1025,  1026,  1026,
    1027,  1027,  1028,  1029,  1030,  1031,  1031,  1032,  1033,  1033,
    1034,  1034,  1034,  1034
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
       1,     1,     1,     1,     1,     3,     1,     1,     1,     1,
       2,     1,     3,     1,     1,     2,     1,     1,     1,     2,
       1,     3,     1,     3,     1,     1,     1,     1,     2,     1,
       3,     1,     2,     4,     3,     1,     1,     1,     1,     2,
       1,     3,     1,     2,     4,     3,     1,     1,     1,     1,
       2,     1,     3,     1,     2,     4,     3,     1,     1,     1,
       1,     2,     1,     3,     1,     2,     4,     3,     1,     1,
       1,     1,     2,     1,     3,     1,     2,     4,     3,     1,
       1,     1,     1,     2,     1,     3,     1,     2,     1,     3,
       1,     1,     1,     1,     2,     1,     3,     1,     2,     1,
       3,     1,     1,     1,     1,     2,     1,     3,     1,     2,
       1,     3,     1,     1,     1,     1,     2,     1,     3,     1,
       2,     1,     3,     1,     1,     1,     1,     2,     1,     3,
       1,     2,     4,     3,     1,     1,     1,     1,     2,     1,
       3,     1,     2,     4,     3,     1,     1,     1,     1,     2,
       1,     3,     1,     2,     4,     3,     1,     1,     1,     1,
       2,     1,     3,     1,     1,     2,     3,     1,     1,     0,
       2,     1,     1,     1,     2,     1,     0,     3,     1,     1,
       0,     2,     1,     1,     1,     1,     1,     1,     3,     4,
       0,     3,     1,     1,     0,     1,     1,     1,     1,     3,
       6,     0,     3,     1,     1,     1,     1,     2,     1,     3,
       1,     1,     2,     3,     1,     0,     2,     1,     1,     2,
       1,     0,     3,     1,     1,     1,     1,     2,     1,     3,
       1,     1,     2,     3,     1,     1,     0,     2,     1,     1,
       2,     1,     0,     2,     1,     1,     1,     1,     3,     6,
       0,     3,     1,     1,     1,     1,     1,     3,     1,     0,
       3,     1,     1,     1,     1,     1,     3,     1,     0,     3,
       1,     1,     1,     1,     1,     3,     1,     0,     3,     1,
       1,     1,     1,     1,     3,     1,     0,     3,     1,     1,
       1,     1,     1,     3,     1,     0,     3,     1,     1,     1,
       1,     1,     3,     1,     0,     3,     1,     1,     1,     1,
       2,     1,     3,     1,     1,     2,     3,     1,     1,     0,
       2,     1,     1,     2,     1,     0,     3,     1,     4,     1,
       1,     2,     1,     3,     1,     2,     3,     1,     1,     0,
       2,     1,     1,     1,     1,     1,     2,     1,     3,     0,
       2,     3,     1,     1,     0,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     2,     1,     3,     1,
       1,     1,     2,     3,     1,     1,     0,     2,     1,     1,
       1,     1,     1,     2,     1,     0,     3,     1,     1,     0,
       1,     1,     1,     1,     3,     4,     0,     3,     1,     1,
       1,     1,     2,     1,     3,     1,     1,     2,     3,     1,
       1,     0,     2,     1,     1,     2,     1,     0,     3,     1,
       1,     1,     1,     2,     1,     3,     1,     1,     2,     3,
       1,     1,     0,     2,     1,     1,     1,     2,     1,     0,
       2,     1,     1,     1,     1,     3,     6,     0,     3,     1,
       1,     1,     1,     1,     3,     1,     0,     3,     1,     1,
       1,     1,     1,     3,     1,     0,     3,     1,     1,     1,
       1,     1,     3,     1,     0,     3,     1,     1,     1,     1,
       1,     3,     1,     0,     3,     1,     1,     1,     1,     1,
       3,     1,     0,     3,     1,     1,     1,     1,     1,     3,
       1,     0,     2,     3,     1,     1,     0,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     2,     1,
       3,     1,     1,     1,     2,     3,     1,     1,     0,     2,
       1,     1,     1,     1,     1,     2,     1,     0,     3,     1,
       1,     0,     1,     1,     1,     1,     3,     4,     0,     3,
       1,     1,     1,     1,     2,     1,     3,     1,     1,     2,
       3,     1,     0,     2,     1,     1,     2,     1,     0,     3,
       1,     1,     1,     1,     2,     1,     3,     1,     1,     2,
       3,     1,     1,     0,     2,     1,     1,     1,     2,     1,
       0,     2,     1,     1,     1,     1,     3,     6,     0,     3,
       1,     1,     1,     1,     1,     3,     1,     0,     3,     1,
       1,     1,     1,     1,     3,     1,     0,     3,     1,     1,
       1,     1,     1,     3,     1,     0,     3,     1,     1,     1,
       1,     1,     3,     1,     0,     3,     1,     1,     1,     1,
       1,     3,     1,     0,     3,     1,     1,     1,     1,     1,
       3,     1,     0,     2,     3,     1,     1,     0,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     2,
       1,     3,     1,     1,     1,     2,     3,     1,     1,     0,
       2,     1,     1,     1,     1,     1,     2,     1,     0,     3,
       1,     1,     1,     1,     1,     3,     0,     2,     3,     1,
       1,     1,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     2,     1,     3,     1,     1,     2,     1,     1,
       1,     1,     1,     3,     1,     3,     1,     1,     0,     2,
       1,     1,     1,     3,     3,     3,     2,     1,     1,     1,
       1,     1,     3,     1,     1,     1,     1,     3,     1,     4,
       1,     1,     4,     1,     1,     1,     1,     3,     1,     1,
       1,     1,     4,     1,     1,     1,     1,     3,     1,     1,
       1,     1,     3,     1,     1,     4,     1,     1,     1,     1,
       3,     1,     1,     1,     1,     3,     1,     1,     1,     1,
       4,     1,     1,     1,     1,     3,     1,     1,     1,     1,
       3,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     1,
       2,     3,     1,     1,     0,     2,     1,     1,     1,     1,
       1,     1,     3,     1,     1,     1,     0,     2,     3,     1,
       1,     0,     2,     1,     1,     3,     3,     4,     1,     1,
       2,     1,     3,     4,     4,     1,     1,     2,     0,     2,
       1,     1,     1,     1
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
     301,   496,     0,     0,   263,   258,   260,   261,   192,   237,
     204,   213,   222,   231,     0,   195,   196,   198,   206,   199,
     215,   200,   224,   201,   232,   202,     0,    65,    68,     0,
      85,    80,    82,    83,     0,    93,    88,    90,    91,     0,
     101,    96,    98,    99,     0,     0,   107,     0,   120,   115,
     117,   118,     0,   128,   123,   125,   126,     0,   136,   131,
     133,   134,     0,   144,   139,   141,   142,     0,   152,   147,
     149,   150,     0,     0,   158,  1178,     0,   168,    29,     0,
       0,    42,    41,    44,    38,    39,    40,   498,    14,   500,
       0,   305,   300,   302,   303,   262,   279,   271,     0,   265,
     266,   268,     0,   269,     0,   194,   197,     0,   205,     0,
     214,     0,   223,     0,  1066,     0,   233,  1063,  1064,  1065,
       0,   238,    87,    84,     0,    95,    92,     0,   103,   100,
       0,     0,     0,   112,   104,   109,   110,   122,   119,     0,
     130,   127,     0,   138,   135,     0,   146,   143,     0,   154,
     151,     0,     0,     0,   163,   155,   160,   161,     0,     0,
       0,   172,   166,   169,   170,    36,     0,     0,    49,    48,
      51,    45,    46,    47,     0,   499,   304,   476,   326,   336,
     344,   355,   366,   377,   388,   454,   443,   399,   410,   432,
     421,   465,     0,   307,   308,   310,     0,   311,     0,   312,
       0,   313,     0,   314,     0,   315,     0,   316,     0,   317,
       0,   318,     0,   320,     0,   319,     0,   321,     0,   322,
       0,   323,     0,   324,     0,   264,   267,     0,   275,   270,
     272,   273,     0,   280,     0,   203,     0,  1114,   207,   209,
     208,  1111,  1112,  1113,     0,   212,   216,   218,   217,     0,
     221,   225,   227,   226,  1178,     0,   230,     0,   242,   236,
     239,   240,    86,    94,   102,   108,   114,   111,     0,   121,
     129,   137,   145,   153,   159,   165,   162,     0,  1178,  1177,
    1180,  1181,  1182,  1183,  1179,   171,   178,     0,   174,   175,
     180,    43,     0,     0,    56,    55,    22,    52,    53,    54,
     510,   507,   497,   505,   506,  1178,  1178,  1178,   501,   503,
     504,   502,   306,   309,     0,   327,     0,   340,   335,   337,
     338,     0,     0,   345,     0,     0,   356,     0,   367,     0,
     378,     0,   389,     0,     0,   400,     0,   411,     0,   422,
       0,   433,     0,   444,     0,   455,     0,     0,   466,     0,
     477,   277,   274,     0,     0,   284,   278,   281,   282,  1175,
    1176,     0,   211,     0,     0,   220,     0,   229,  1067,   235,
       0,   241,   248,     0,   244,   245,   250,   113,   164,  1131,
     173,   176,     0,   179,    50,     0,   512,     0,   705,   514,
       0,     0,     0,     0,   331,   325,   328,   329,   342,   339,
       0,     0,     0,   349,   343,   346,   347,     0,     0,   360,
     354,   357,   358,     0,   371,   365,   368,   369,     0,   382,
     376,   379,   380,     0,   393,   387,   390,   391,     0,     0,
     404,   398,   401,   402,     0,   415,   409,   412,   413,     0,
     426,   420,   423,   424,     0,   437,   431,   434,   435,     0,
     448,   442,   445,   446,     0,   459,   453,   456,   457,     0,
       0,   470,   464,   467,   468,     0,   481,   475,   478,   479,
     276,   283,   290,     0,   286,   287,   292,   210,  1115,   219,
     228,   234,   243,   246,     0,   249,     0,   186,   177,     0,
       0,  1086,  1119,   181,   184,   182,  1083,  1084,  1085,   183,
    1116,  1117,  1118,    57,   508,   707,   857,   709,  1178,     0,
     513,   515,  1178,  1178,  1178,   330,     0,   333,   334,   341,
       0,     0,   348,     0,   351,     0,   359,     0,     0,   362,
     370,     0,     0,   373,     0,   381,     0,   384,     0,   392,
       0,   395,     0,  1046,   403,     0,   406,   408,  1048,   414,
       0,   417,   419,   425,     0,   428,   430,   436,     0,   439,
     441,     0,   447,     0,   450,     0,   458,     0,   461,     0,
     469,     0,     0,   472,   480,   487,     0,   483,   484,   489,
     285,   288,     0,   291,     0,   256,   247,   251,   254,   252,
     253,   185,  1178,     0,   859,  1008,   861,  1178,     0,   708,
     710,     0,   521,   518,   511,   516,   517,  1138,  1128,  1122,
     332,  1126,     0,   350,   352,  1134,     0,   361,   363,     0,
     372,   374,     0,   383,   385,     0,   394,   396,  1133,   405,
     407,     0,  1047,   416,   418,   427,   429,   438,   440,     0,
     449,   451,     0,   460,   462,  1135,     0,   471,   473,   482,
     485,     0,   488,     0,   298,   289,   293,   296,   294,   295,
     255,  1087,  1120,  1010,   509,     0,  1178,     0,   860,   862,
       0,   716,   713,   706,   711,   712,  1178,   523,     0,   541,
       0,     0,     0,     0,     0,     0,     0,  1057,  1045,     0,
       0,     0,  1049,  1050,  1051,  1052,     0,     0,     0,     0,
     495,   486,   490,   493,   491,   492,   297,  1178,     0,  1011,
       0,   868,   865,   858,   863,   864,  1178,   718,     0,   737,
       0,  1132,   519,   543,   562,     0,  1178,     0,   524,   353,
     364,   375,   386,   397,  1056,     0,     0,     0,   452,   463,
     474,   494,     0,  1016,  1014,  1009,  1012,  1013,  1178,   870,
       0,   888,     0,  1130,   714,   739,   759,     0,  1178,     0,
     719,   564,   624,     0,     0,   544,     0,     0,   528,   522,
     525,   526,  1053,  1054,  1055,  1178,     0,  1129,   866,   890,
     910,     0,  1178,     0,   871,   761,   821,     0,     0,   740,
       0,     0,   723,   717,   720,   721,   626,   645,     0,   570,
     567,   563,   565,   566,     0,   548,   542,   545,   546,  1178,
     527,   534,     0,   530,   531,   535,  1136,  1015,  1019,  1017,
       0,   912,   972,     0,     0,   891,     0,     0,   875,   869,
     872,   873,   715,   767,   764,   760,   762,   763,     0,   744,
     738,   741,   742,  1178,   722,   729,     0,   725,   726,   731,
     647,   669,     0,     0,   627,   572,     0,   579,     0,   554,
     547,     0,   550,   551,   556,  1137,   529,   532,     0,     0,
       0,  1178,  1099,  1061,     0,  1091,     0,  1020,  1021,  1026,
    1058,  1059,  1060,  1028,  1023,  1025,  1088,  1089,  1090,  1027,
    1096,  1097,  1098,  1024,  1029,   867,   918,   915,   911,   913,
     914,     0,   895,   889,   892,   893,  1178,   874,   881,     0,
     877,   878,   882,   824,   822,   826,   769,     0,   776,     0,
     750,   743,     0,   746,   747,   752,  1127,   724,   727,     0,
     730,   520,     0,     0,     0,   631,   625,   628,   629,   568,
     581,   588,     0,  1178,     0,   573,   549,   552,     0,   555,
       0,   540,  1178,   536,   533,   537,  1070,  1071,   538,  1178,
       0,     0,  1178,     0,  1033,  1018,  1030,  1031,  1022,   975,
     973,   977,   920,     0,   927,     0,   901,   894,     0,   897,
     898,   903,  1121,   876,   879,     0,     0,   825,   765,   778,
     785,     0,     0,   770,   745,   748,     0,   751,     0,   736,
     728,   732,   733,   734,   672,   670,   674,     0,     0,   652,
     646,   649,   650,   637,   630,     0,   633,   634,   639,   590,
     597,     0,     0,   582,     0,  1156,   576,   571,   574,   575,
       0,   561,   553,   557,   558,   559,   539,     0,  1062,  1100,
    1178,  1092,  1032,  1042,     0,  1041,     0,  1035,  1036,  1038,
    1039,  1040,     0,   976,   916,   929,   936,     0,     0,   921,
     896,   899,     0,   902,     0,   887,   883,   880,   884,   885,
       0,   839,   823,   836,   837,  1178,   827,   833,   835,   830,
     832,   834,   831,   829,   828,   787,   794,     0,     0,   779,
    1156,   773,   768,   771,   772,     0,   758,   749,  1076,  1104,
       0,     0,   753,   754,   755,  1073,  1074,  1075,   756,  1101,
    1102,  1103,   735,     0,   673,     0,   651,   657,     0,   654,
     659,   632,   635,     0,   638,   599,   606,     0,     0,   591,
    1156,   585,   580,   583,   584,  1178,     0,     0,   578,  1154,
    1155,   560,  1178,  1125,  1044,     0,  1034,  1037,     0,   990,
     974,   987,   988,   978,   984,   986,   981,   983,   985,   982,
     979,   980,   938,   945,     0,     0,   930,  1156,   924,   919,
     922,   923,     0,   909,   900,  1081,  1109,  1178,  1178,   904,
     905,   906,  1078,  1079,  1080,   907,  1106,  1107,  1108,   886,
     838,   846,  1142,     0,   841,   843,   848,   842,  1139,  1144,
       0,   796,   803,     0,     0,   788,  1156,   782,   777,   780,
     781,     0,   775,   757,  1178,  1178,     0,   687,   671,   684,
     685,   675,   681,   683,   678,   680,   682,   679,   677,   676,
     648,   653,   655,     0,   658,     0,   644,   636,   640,   641,
     642,   608,   615,     0,     0,   600,  1156,   594,   589,   592,
     593,     0,   587,  1123,  1178,     0,   577,  1159,  1157,  1161,
    1072,  1043,   989,   997,     0,   992,   994,   999,   993,   947,
     954,     0,     0,   939,  1156,   933,   928,   931,   932,     0,
     926,   908,     0,     0,   840,   844,     0,   847,  1140,     0,
    1143,  1178,   805,   812,     0,     0,   797,  1156,   791,   786,
     789,   790,     0,   784,   774,  1077,  1105,   686,   694,     0,
     689,   691,   696,   690,     0,   667,   656,   664,   665,     0,
    1178,   660,   663,  1068,   661,  1093,  1094,   662,   643,   617,
     569,     0,     0,   609,  1156,   603,   598,   601,   602,     0,
     596,   586,     0,     0,  1171,  1166,  1168,  1169,     0,  1160,
     991,   995,     0,   998,   956,   963,     0,     0,   948,  1156,
     942,   937,   940,   941,     0,   935,   925,  1178,  1178,     0,
     856,   845,   854,   849,   850,   852,   853,   851,  1156,  1151,
    1141,  1149,  1150,  1148,  1147,  1146,  1145,  1124,   814,   766,
       0,     0,   806,  1156,   800,   795,   798,   799,     0,   793,
     783,   688,   692,     0,   695,   666,     0,     0,     0,     0,
     618,  1156,   612,   607,   610,   611,     0,   605,   595,  1178,
       0,  1170,     0,  1158,  1178,  1178,  1162,  1164,  1163,     0,
    1007,   996,  1005,  1000,  1001,  1003,  1004,  1002,   965,   917,
       0,     0,   957,  1156,   951,   946,   949,   950,     0,   944,
     934,  1082,  1110,   855,     0,  1153,     0,   815,  1156,   809,
     804,   807,   808,     0,   802,   792,     0,   704,   693,   702,
     697,   698,   700,   701,   699,   668,     0,  1178,  1156,   621,
     616,   619,   620,     0,   614,   604,  1167,  1172,     0,     0,
       0,  1006,     0,   966,  1156,   960,   955,   958,   959,     0,
     953,   943,  1152,  1156,   818,   813,   816,   817,     0,   811,
     801,   703,  1069,  1095,     0,   623,   613,  1165,  1178,  1178,
    1156,   969,   964,   967,   968,     0,   962,   952,     0,   820,
     810,   622,  1173,  1174,     0,   971,   961,   819,   970
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
     869,   870,   871,   912,   913,   914,   915,   968,  1053,  1054,
     824,   825,   864,   906,   907,   908,   961,   962,   963,   964,
    1048,  1049,  1133,  1132,   862,   863,   901,   902,   903,   956,
     957,   958,  1044,  1127,  1128,  1129,  1237,  1041,  1042,  1122,
    1232,  1233,  1234,  1351,  1120,  1121,  1228,  1348,  1349,  1350,
    1439,  1226,  1227,  1344,  1436,  1437,  1438,  1516,  1342,  1343,
    1432,  1513,  1514,  1515,  1583,  1430,  1431,  1509,  1580,  1581,
    1582,  1614,   897,   898,   953,  1036,  1037,  1038,  1115,  1116,
    1117,  1118,  1223,  1224,  1338,  1337,   951,   952,  1033,  1110,
    1111,  1112,  1218,  1219,  1220,  1333,  1334,  1421,  1416,  1417,
    1418,  1031,  1105,  1106,  1213,  1214,  1321,  1318,  1319,  1320,
    1409,  1410,  1411,  1412,  1503,  1504,  1570,  1568,  1569,   606,
     607,   698,   699,   773,   774,   775,   818,   819,   820,   859,
     893,   894,   895,   946,   947,   948,   949,  1029,  1030,  1101,
    1100,   856,   857,   888,   940,   941,   942,  1022,  1023,  1024,
    1025,  1096,  1097,  1202,  1197,   886,   887,   935,   936,   937,
    1017,  1018,  1019,  1092,  1192,  1193,  1194,  1311,  1090,  1091,
    1188,  1308,  1309,  1310,  1402,  1186,  1187,  1304,  1399,  1400,
    1401,  1498,  1302,  1303,  1395,  1495,  1496,  1497,  1563,  1393,
    1394,  1491,  1560,  1561,  1562,  1608,  1489,  1490,  1556,  1605,
    1606,  1607,  1628,   932,  1014,  1015,  1086,  1087,  1176,  1172,
    1173,  1174,  1293,  1294,  1295,  1296,  1386,  1387,  1473,  1471,
    1472,   695,   696,   767,   768,   813,   814,   815,   850,   851,
     852,   883,   929,   930,   931,  1009,  1010,  1011,  1012,  1085,
    1166,  1167,   880,   881,   924,  1003,  1004,  1005,  1078,  1079,
    1080,  1081,  1162,  1163,  1279,  1274,   922,   923,   998,   999,
    1000,  1073,  1074,  1075,  1158,  1269,  1270,  1271,  1379,  1156,
    1157,  1265,  1376,  1377,  1378,  1464,  1263,  1264,  1372,  1461,
    1462,  1463,  1548,  1370,  1371,  1457,  1545,  1546,  1547,  1599,
    1455,  1456,  1541,  1596,  1597,  1598,  1625,  1539,  1540,  1592,
    1622,  1623,  1624,  1634,   995,  1070,  1071,  1152,  1153,  1253,
    1250,  1251,  1252,  1364,  1365,  1366,  1367,  1452,  1453,  1533,
    1531,  1532,   764,   765,   808,   845,   846,   847,   876,   919,
     920,   976,   977,   978,  1065,  1066,  1067,  1146,  1147,  1148,
    1149,  1150,  1151,  1245,   647,   648,   731,   732,   792,   793,
     794,   795,   788,   979,   980,   981,   982,   983,   217,   218,
     219,  1422,  1423,  1055,  1056,  1057,  1204,  1205,  1206,  1207,
    1281,  1282,  1283,  1284,   984,   596,   597,   598,   985,   986,
     987,   988,  1424,  1425,  1426,   989,   990,   991,   992,  1208,
    1209,  1210,  1211,  1285,  1286,  1287,  1288,   340,   341,   342,
     343,   993,   600,   601,   602,   884,   409,  1045,  1183,   994,
     423,   860,   410,   769,   700,   177,   611,   435,   426,   448,
     809,   828,   411,  1297,  1298,  1299,  1389,  1390,  1486,  1480,
    1481,  1482,  1554,  1238,  1239,  1358,  1359,  1448,  1449,  1526,
    1523,  1240,  1355,  1445,  1446,  1447,  1527,  1528,   462,   258,
     259,   384
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -1365
static const yytype_int16 yypact[] =
{
     348, -1365, -1365,    47,     0,   186, -1365, -1365,   203,   151,
     359, -1365,   361, -1365, -1365, -1365,   174,   363,    20, -1365,
   -1365, -1365, -1365,     0, -1365, -1365, -1365, -1365, -1365,   200,
     366,   182, -1365, -1365, -1365, -1365,   273, -1365, -1365,   216,
     191, -1365, -1365, -1365,   203, -1365,   215,   373,    -8, -1365,
   -1365, -1365, -1365, -1365, -1365, -1365, -1365, -1365, -1365, -1365,
   -1365, -1365, -1365, -1365, -1365,   230,   462, -1365, -1365,   384,
   -1365,   390, -1365,   394, -1365,   220, -1365,   396, -1365,   398,
   -1365,   400, -1365,   402, -1365,   409, -1365,   245, -1365,   296,
     249, -1365,   320, -1365, -1365,   233, -1365, -1365, -1365, -1365,
   -1365,   260,   411,   -22, -1365, -1365, -1365, -1365, -1365, -1365,
   -1365, -1365, -1365, -1365,   279,   121, -1365, -1365, -1365, -1365,
   -1365, -1365, -1365, -1365,   211, -1365,   296, -1365, -1365,    31,
   -1365, -1365, -1365, -1365,    41, -1365, -1365, -1365, -1365,    37,
   -1365, -1365, -1365, -1365,   342,   418, -1365,    30, -1365, -1365,
   -1365, -1365,    27, -1365, -1365, -1365, -1365,    24, -1365, -1365,
   -1365, -1365,    18, -1365, -1365, -1365, -1365,    17, -1365, -1365,
   -1365, -1365,   354,   420, -1365, -1365,   422, -1365, -1365,   278,
     362, -1365, -1365,   241, -1365, -1365, -1365, -1365, -1365, -1365,
      38, -1365, -1365, -1365, -1365, -1365, -1365, -1365,   290,    92,
   -1365, -1365,   425, -1365,   296, -1365, -1365,   371,   257,   376,
     257,   382,   257,   412, -1365,   387, -1365, -1365, -1365, -1365,
     433, -1365, -1365, -1365,   324, -1365, -1365,   335, -1365, -1365,
     365,   438,    29, -1365, -1365, -1365, -1365, -1365, -1365,   331,
   -1365, -1365,   379, -1365, -1365,   364, -1365, -1365,   357, -1365,
   -1365,   367,   473,    16, -1365, -1365, -1365, -1365,   467,     5,
     334, -1365, -1365, -1365, -1365, -1365,   403,   488, -1365, -1365,
     229, -1365, -1365, -1365,   446,    93, -1365, -1365, -1365, -1365,
   -1365, -1365, -1365, -1365, -1365, -1365, -1365, -1365, -1365, -1365,
   -1365, -1365,   432,   333, -1365, -1365,   135, -1365,   449, -1365,
     477, -1365,   519, -1365,   519, -1365,   519, -1365,   519, -1365,
     512, -1365,   512, -1365,   512, -1365,   512, -1365,   519, -1365,
     519, -1365,   521, -1365,   296, -1365, -1365,    15, -1365, -1365,
   -1365, -1365,   454, -1365,   472, -1365,   541, -1365, -1365, -1365,
   -1365, -1365, -1365, -1365,   472, -1365, -1365, -1365, -1365,   472,
   -1365, -1365, -1365, -1365, -1365,   552, -1365,   377, -1365, -1365,
   -1365, -1365, -1365, -1365, -1365, -1365, -1365, -1365,   456, -1365,
   -1365, -1365, -1365, -1365, -1365, -1365, -1365,   448, -1365, -1365,
   -1365, -1365, -1365, -1365, -1365, -1365, -1365,   444,   451, -1365,
   -1365, -1365,   478,   569, -1365, -1365, -1365, -1365, -1365, -1365,
     415, -1365, -1365, -1365, -1365, -1365, -1365, -1365, -1365, -1365,
   -1365, -1365, -1365, -1365,   490, -1365,    12, -1365, -1365, -1365,
   -1365,   568,   492, -1365,   570,   494, -1365,   496, -1365,   500,
   -1365,   502, -1365,   572,   504, -1365,   509, -1365,   511, -1365,
     513, -1365,   517, -1365,   520, -1365,   583,   525, -1365,   536,
   -1365, -1365, -1365,   471,   430, -1365, -1365, -1365, -1365, -1365,
   -1365,   481, -1365,   718,   501, -1365,   599, -1365, -1365, -1365,
     601, -1365, -1365,   609,   607, -1365, -1365, -1365, -1365, -1365,
   -1365, -1365,   542,   181, -1365,   634, -1365,   657,   537,   703,
     731,   732,   733,    11, -1365, -1365, -1365, -1365, -1365, -1365,
     605,   734,   -53, -1365, -1365, -1365, -1365,   736,   171, -1365,
   -1365, -1365, -1365,   414, -1365, -1365, -1365, -1365,    78, -1365,
   -1365, -1365, -1365,   -82, -1365, -1365, -1365, -1365,   738,   -29,
   -1365, -1365, -1365, -1365,   -38, -1365, -1365, -1365, -1365,   -92,
   -1365, -1365, -1365, -1365,   -64, -1365, -1365, -1365, -1365,    61,
   -1365, -1365, -1365, -1365,    95, -1365, -1365, -1365, -1365,   739,
     419, -1365, -1365, -1365, -1365,   465, -1365, -1365, -1365, -1365,
   -1365, -1365, -1365,   626,   628, -1365, -1365, -1365, -1365, -1365,
   -1365, -1365, -1365, -1365,   577,   181,   625, -1365, -1365,   745,
     747, -1365, -1365, -1365, -1365, -1365, -1365, -1365, -1365, -1365,
   -1365, -1365, -1365, -1365, -1365, -1365,   548,   719, -1365,   579,
   -1365, -1365, -1365, -1365, -1365, -1365,   618, -1365, -1365, -1365,
     746,   748, -1365,   -44, -1365,   749, -1365,   750,   206, -1365,
   -1365,   751,   450, -1365,   752, -1365,   112, -1365,   753, -1365,
     132, -1365,   756, -1365, -1365,    74, -1365, -1365, -1365, -1365,
       1, -1365, -1365, -1365,   -62, -1365, -1365, -1365,   -42, -1365,
   -1365,   755, -1365,    85, -1365,   757, -1365,   110, -1365,   758,
   -1365,   759,   431, -1365, -1365, -1365,   636,   638, -1365, -1365,
   -1365, -1365,   587,   181,   646, -1365, -1365, -1365, -1365, -1365,
   -1365, -1365, -1365,   762, -1365,   544,   737, -1365,   589, -1365,
   -1365,   765,   611, -1365, -1365, -1365, -1365, -1365, -1365, -1365,
   -1365, -1365,   769, -1365, -1365, -1365,   770, -1365, -1365,   771,
   -1365, -1365,   772, -1365, -1365,   773, -1365, -1365, -1365, -1365,
   -1365,   591,   283, -1365, -1365, -1365, -1365, -1365, -1365,   774,
   -1365, -1365,   775, -1365, -1365, -1365,   777, -1365, -1365, -1365,
   -1365,   598,   181,   661, -1365, -1365, -1365, -1365, -1365, -1365,
   -1365, -1365, -1365, -1365, -1365,   754, -1365,   600, -1365, -1365,
     778,   588, -1365, -1365, -1365, -1365, -1365, -1365,   620,   613,
     760,   679,   649,   651,   652,   655,   644, -1365, -1365,   786,
     789,   791, -1365, -1365, -1365, -1365,   659,   662,   632,   683,
   -1365, -1365, -1365, -1365, -1365, -1365, -1365, -1365,   602, -1365,
     794,   596, -1365, -1365, -1365, -1365, -1365, -1365,   612,   603,
     764, -1365, -1365, -1365,   640,   760, -1365,   604, -1365, -1365,
   -1365, -1365, -1365, -1365, -1365,   799,   801,   802, -1365, -1365,
   -1365, -1365,   805, -1365, -1365, -1365, -1365, -1365, -1365, -1365,
     614,   615,   780, -1365, -1365, -1365,   642,   764, -1365,   606,
   -1365, -1365,   624,   608,   610, -1365,   806,   453, -1365, -1365,
   -1365, -1365, -1365, -1365, -1365, -1365,   413, -1365, -1365, -1365,
     647,   780, -1365,   619, -1365, -1365, -1365,   621,   623, -1365,
     808,   437, -1365, -1365, -1365, -1365, -1365,   630,   760,   653,
   -1365, -1365, -1365, -1365,   176, -1365, -1365, -1365, -1365, -1365,
   -1365, -1365,   663,   665, -1365, -1365, -1365, -1365, -1365, -1365,
     493, -1365, -1365,   627,   629, -1365,   810,   435, -1365, -1365,
   -1365, -1365,   699,   667, -1365, -1365, -1365, -1365,   -18, -1365,
   -1365, -1365, -1365, -1365, -1365, -1365,   631,   668, -1365, -1365,
   -1365, -1365,   796,   633, -1365, -1365,   669,   671,   783, -1365,
   -1365,   673,   675, -1365, -1365, -1365, -1365, -1365,   154,   824,
     825, -1365, -1365, -1365,   828, -1365,   635,   493, -1365, -1365,
   -1365, -1365, -1365, -1365, -1365, -1365, -1365, -1365, -1365, -1365,
   -1365, -1365, -1365, -1365, -1365,   711,   677, -1365, -1365, -1365,
   -1365,   145, -1365, -1365, -1365, -1365, -1365, -1365, -1365,   681,
     684, -1365, -1365, -1365, -1365, -1365, -1365,   686,   688,   783,
   -1365, -1365,   690,   695, -1365, -1365, -1365, -1365, -1365,   637,
     199,   713,   827,   639,  -116, -1365, -1365, -1365, -1365, -1365,
   -1365,   692,   783, -1365,   641, -1365, -1365, -1365,   643,   199,
     693, -1365, -1365, -1365, -1365, -1365, -1365, -1365, -1365, -1365,
     829,   832, -1365,   101, -1365, -1365, -1365, -1365, -1365, -1365,
   -1365, -1365, -1365,   696,   697,   783, -1365, -1365,   700,   705,
   -1365, -1365, -1365, -1365, -1365,   172,   645,   292, -1365, -1365,
     702,   783,   648, -1365, -1365, -1365,   650,   114,   707, -1365,
   -1365, -1365, -1365, -1365, -1365, -1365, -1365,   833,   470, -1365,
   -1365, -1365, -1365, -1365, -1365,   709,   717, -1365, -1365, -1365,
     715,   783,   654, -1365,   834,   622, -1365, -1365, -1365, -1365,
     723, -1365, -1365, -1365, -1365, -1365, -1365,   835, -1365, -1365,
   -1365, -1365, -1365, -1365,   837, -1365,   716,   -57, -1365, -1365,
   -1365, -1365,   656,   341, -1365, -1365,   722,   783,   658, -1365,
   -1365, -1365,   660,   150,   724, -1365, -1365, -1365, -1365, -1365,
     -86, -1365, -1365, -1365, -1365, -1365, -1365, -1365, -1365, -1365,
   -1365, -1365, -1365, -1365, -1365, -1365,   720,   783,   664, -1365,
     622, -1365, -1365, -1365, -1365,   721, -1365, -1365, -1365, -1365,
     845,   846, -1365, -1365, -1365, -1365, -1365, -1365, -1365, -1365,
   -1365, -1365, -1365,   666,   401,   842, -1365, -1365,   486, -1365,
   -1365, -1365, -1365,   670,   199, -1365,   725,   783,   672, -1365,
     622, -1365, -1365, -1365, -1365, -1365,   726,   735, -1365,   727,
   -1365, -1365, -1365, -1365, -1365,   728, -1365, -1365,   -85, -1365,
   -1365, -1365, -1365, -1365, -1365, -1365, -1365, -1365, -1365, -1365,
   -1365, -1365, -1365,   729,   783,   674, -1365,   622, -1365, -1365,
   -1365, -1365,   730, -1365, -1365, -1365, -1365, -1365, -1365, -1365,
   -1365, -1365, -1365, -1365, -1365, -1365, -1365, -1365, -1365, -1365,
   -1365, -1365, -1365,   741,   740, -1365, -1365,   742, -1365, -1365,
     847, -1365,   743,   783,   676, -1365,   622, -1365, -1365, -1365,
   -1365,   744, -1365, -1365, -1365, -1365,   -76, -1365, -1365, -1365,
   -1365, -1365, -1365, -1365, -1365, -1365, -1365, -1365, -1365, -1365,
   -1365, -1365, -1365,   678,    36,   761, -1365, -1365, -1365, -1365,
   -1365, -1365,   763,   783,   680, -1365,   622, -1365, -1365, -1365,
   -1365,   766, -1365, -1365, -1365,   682, -1365, -1365, -1365, -1365,
   -1365, -1365, -1365, -1365,   767,   768, -1365, -1365,   742, -1365,
     776,   783,   685, -1365,   622, -1365, -1365, -1365, -1365,   782,
   -1365, -1365,   472,   472, -1365, -1365,   687,   214, -1365,   689,
      25, -1365, -1365,   781,   783,   691, -1365,   622, -1365, -1365,
   -1365, -1365,   779, -1365, -1365, -1365, -1365, -1365, -1365,   793,
     784, -1365, -1365,   742,  -122, -1365, -1365, -1365, -1365,   843,
   -1365, -1365, -1365, -1365, -1365, -1365, -1365, -1365, -1365, -1365,
   -1365,   783,   694, -1365,   622, -1365, -1365, -1365, -1365,   787,
   -1365, -1365,   849,    10, -1365, -1365, -1365, -1365,   848,   483,
   -1365, -1365,   698,   214, -1365,   790,   783,   701, -1365,   622,
   -1365, -1365, -1365, -1365,   788, -1365, -1365, -1365, -1365,   785,
   -1365, -1365, -1365, -1365, -1365, -1365, -1365, -1365,   622, -1365,
   -1365, -1365, -1365, -1365, -1365, -1365, -1365, -1365, -1365, -1365,
     783,   704, -1365,   622, -1365, -1365, -1365, -1365,   798, -1365,
   -1365, -1365, -1365,   706,   214, -1365,  -112,   472,   850,   708,
   -1365,   622, -1365, -1365, -1365, -1365,   795, -1365, -1365, -1365,
     792, -1365,   851, -1365, -1365, -1365, -1365, -1365, -1365,   800,
   -1365, -1365, -1365, -1365, -1365, -1365, -1365, -1365, -1365, -1365,
     783,   710, -1365,   622, -1365, -1365, -1365, -1365,   803, -1365,
   -1365, -1365, -1365, -1365,   797, -1365,   712, -1365,   622, -1365,
   -1365, -1365, -1365,   804, -1365, -1365,   807, -1365, -1365, -1365,
   -1365, -1365, -1365, -1365, -1365, -1365,   852, -1365,   622, -1365,
   -1365, -1365, -1365,   809, -1365, -1365, -1365, -1365,   811,   853,
     855, -1365,   714, -1365,   622, -1365, -1365, -1365, -1365,   812,
   -1365, -1365, -1365,   622, -1365, -1365, -1365, -1365,   813, -1365,
   -1365, -1365, -1365, -1365,   814, -1365, -1365, -1365, -1365, -1365,
     622, -1365, -1365, -1365, -1365,   815, -1365, -1365,   816, -1365,
   -1365, -1365, -1365, -1365,   818, -1365, -1365, -1365, -1365
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
   -1365, -1365, -1365, -1365, -1365, -1365, -1365, -1365,   820,   854,
   -1365, -1365, -1365, -1365, -1365, -1365, -1365, -1365, -1365, -1365,
   -1365, -1365, -1365, -1365, -1365, -1365, -1365, -1365, -1365, -1365,
   -1365, -1365, -1365, -1365, -1365, -1365, -1365, -1365, -1365, -1365,
   -1365, -1365, -1365,   817, -1365, -1365, -1365, -1365, -1365, -1365,
   -1365, -1365, -1365, -1365, -1365, -1365, -1365, -1365, -1365, -1365,
   -1365, -1365, -1365, -1365, -1365, -1365, -1365, -1365, -1365, -1365,
   -1365, -1365, -1365, -1365, -1365, -1365, -1365, -1365, -1365, -1365,
   -1365, -1365, -1365, -1365, -1365, -1365, -1365, -1365, -1365, -1365,
   -1365, -1365, -1365, -1365, -1365, -1365, -1365, -1365, -1365, -1365,
   -1365, -1365, -1365, -1365, -1365, -1365, -1365, -1365, -1365, -1365,
   -1365, -1365, -1365, -1365, -1365, -1365,   480, -1365, -1365, -1365,
   -1365, -1365, -1365, -1365, -1365, -1365, -1365, -1365, -1365,   819,
   -1365, -1365, -1365, -1365, -1365, -1365, -1365, -1365, -1365, -1365,
   -1365, -1365, -1365, -1365, -1365, -1365, -1365, -1365, -1365, -1365,
   -1365, -1365, -1365, -1365, -1365, -1365, -1365, -1365, -1365, -1365,
   -1365, -1365, -1365, -1365,   392, -1365, -1365, -1365, -1365, -1365,
   -1365, -1365, -1365, -1365, -1365, -1365, -1365,   821, -1365, -1365,
   -1365, -1365, -1365, -1365, -1365, -1365, -1365, -1365, -1365, -1365,
   -1365, -1365,   299, -1365, -1365, -1365, -1365, -1365, -1365, -1365,
   -1365, -1365, -1365, -1365, -1365,   581, -1365, -1365, -1365, -1365,
   -1365, -1365, -1365, -1365, -1365, -1365, -1365, -1365, -1365, -1365,
   -1365, -1365, -1365, -1365, -1365, -1365, -1365,   247, -1365, -1365,
   -1365, -1365, -1365, -1365, -1365,   248, -1365, -1365, -1365, -1365,
   -1365, -1365, -1365,   243, -1365, -1365, -1365, -1365, -1365, -1365,
   -1365,   244, -1365, -1365, -1365, -1365, -1365, -1365, -1365,   239,
   -1365, -1365, -1365, -1365, -1365, -1365, -1365,   237, -1365, -1365,
   -1365, -1365, -1365, -1365, -1365,   234, -1365, -1365, -1365, -1365,
   -1365, -1365, -1365,   231, -1365, -1365, -1365, -1365, -1365, -1365,
   -1365,   232, -1365, -1365, -1365, -1365, -1365, -1365, -1365,   235,
   -1365, -1365, -1365, -1365, -1365, -1365, -1365,   236, -1365, -1365,
   -1365, -1365, -1365, -1365, -1365,   224, -1365, -1365, -1365, -1365,
   -1365, -1365, -1365, -1365,   225, -1365, -1365, -1365, -1365, -1365,
   -1365, -1365, -1365, -1365, -1365, -1365, -1365, -1365, -1365, -1365,
   -1365, -1365, -1365, -1365, -1365, -1365, -1365, -1365, -1365, -1365,
   -1365, -1365, -1365, -1365, -1365,   -16, -1365, -1365, -1365, -1365,
   -1365, -1365, -1365, -1365, -1365, -1365, -1365, -1365,   -58, -1365,
   -1365, -1365, -1365, -1365, -1365, -1365, -1365, -1365, -1365, -1365,
   -1365, -1365, -1365, -1365, -1365, -1365, -1365, -1365, -1365, -1365,
   -1365, -1365, -1365, -1365, -1365, -1365, -1365, -1365, -1365, -1365,
   -1365, -1365, -1365, -1365, -1365, -1365, -1365, -1365, -1365, -1365,
   -1365, -1365, -1365, -1365, -1365, -1365, -1365, -1365, -1365, -1365,
   -1365, -1365, -1365, -1365, -1365, -1365, -1365, -1365, -1365,  -503,
   -1107, -1365, -1365, -1365, -1365, -1365, -1365, -1365, -1365, -1365,
   -1365, -1365, -1365,  -302, -1365, -1365, -1365, -1365, -1365, -1365,
   -1365, -1365, -1365, -1365, -1365, -1365, -1365, -1365, -1365, -1365,
   -1365, -1365,  -493, -1365, -1365, -1365, -1365, -1365, -1365, -1365,
   -1365, -1365, -1365, -1365, -1365, -1365, -1365, -1365, -1365, -1365,
   -1365, -1365, -1365, -1365, -1365,   -28, -1365, -1365, -1365, -1365,
   -1365, -1365, -1365, -1365, -1365, -1365, -1365, -1365, -1365,  -105,
   -1365, -1365, -1365, -1365, -1365, -1365, -1365, -1365, -1365, -1365,
   -1365, -1365, -1365, -1365, -1365, -1365, -1365, -1365, -1365, -1365,
   -1365, -1365, -1365, -1365, -1365, -1365, -1365, -1365, -1365, -1365,
   -1365, -1365, -1365, -1365, -1365, -1365, -1365, -1365, -1365, -1365,
   -1365, -1365, -1365, -1365, -1365, -1365, -1365, -1365, -1365, -1365,
   -1365, -1365, -1365, -1365, -1365, -1365, -1365, -1365, -1365, -1365,
   -1365, -1365, -1365, -1365,  -374, -1365, -1365, -1365, -1365, -1365,
   -1365, -1365, -1365, -1365, -1365, -1365, -1365, -1365, -1365, -1365,
   -1365, -1365, -1365, -1365, -1365, -1365, -1365,   -87, -1365, -1365,
   -1365, -1365, -1365, -1365, -1365, -1365, -1365, -1365, -1365, -1365,
    -155, -1365, -1365, -1365, -1365, -1365, -1365, -1365, -1365, -1365,
   -1365, -1365, -1365, -1365, -1365, -1365, -1365, -1365, -1365, -1365,
   -1365, -1365, -1365, -1365, -1365, -1365, -1365, -1365, -1365, -1365,
   -1365, -1365, -1365, -1365, -1365, -1365, -1365, -1365, -1365, -1365,
   -1365, -1365, -1365, -1365, -1365, -1365, -1365, -1365, -1365, -1365,
   -1365, -1365, -1365, -1365, -1365, -1365, -1365, -1365, -1365, -1365,
   -1365, -1365, -1365, -1365, -1365,  -440, -1365, -1365, -1365, -1365,
   -1365, -1365, -1365, -1365, -1365, -1365, -1365, -1365, -1365, -1365,
   -1365, -1365, -1365,   -50, -1365, -1365, -1365, -1365, -1365,  -216,
   -1365, -1365, -1365, -1365,  -496, -1365, -1365, -1365, -1365, -1365,
   -1365, -1365, -1365, -1063, -1365, -1365, -1365,  -124, -1365, -1365,
   -1365, -1365, -1365, -1019, -1365, -1365, -1364, -1365, -1365, -1365,
   -1365, -1365, -1365, -1365,  -480, -1365, -1365, -1365, -1062, -1365,
   -1365, -1365, -1365, -1365, -1365, -1061, -1365, -1365, -1365, -1355,
   -1365, -1365, -1365, -1365, -1365, -1365, -1365,  -168, -1365, -1365,
   -1365,  -481, -1365, -1365, -1365,  -873, -1365, -1015, -1102, -1365,
   -1365,  -845, -1365, -1365, -1365,  -111, -1365,   -20,  -130, -1365,
   -1365,  -818, -1365, -1208, -1258, -1365, -1365, -1365, -1365, -1365,
   -1365, -1365, -1365, -1180, -1365, -1365, -1365, -1365, -1365, -1365,
   -1365, -1365, -1365, -1365, -1365, -1365, -1365, -1365,  -343,  -349,
   -1365, -1365
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint16 yytable[] =
{
     216,   465,   599,   595,  1093,   468,   467,   865,   925,  1222,
    1312,  1102,   889,   379,  1520,   221,   498,   459,   460,   451,
     375,   249,   246,  1475,  1177,  1180,  1181,  1123,   243,   479,
    1134,   240,  1476,   366,   237,   222,  1290,  1362,   652,  1388,
    1368,   228,   348,   656,   353,   225,  1407,     6,   660,  1113,
    1352,  1261,   195,   643,   621,  1113,   490,   491,   492,  1113,
    1159,   638,  1419,   621,   108,  1043,  1168,     7,   639,   590,
     653,   213,  1505,   826,  1114,   214,  1189,   592,  1203,  1420,
     954,   643,  1575,   643,   339,   622,   347,  1380,   352,  1535,
    1254,  1257,  1258,   333,   713,  1408,   657,   196,  1536,    36,
     735,    37,    38,   643,   690,   689,  1229,   643,  1413,   197,
    1388,   109,  1328,  1291,   276,   110,   643,   111,   737,   112,
     649,   113,  1363,   405,   406,   407,  1403,   644,   415,  1292,
    1292,   223,   247,   250,   376,   367,   244,   241,   238,  1292,
    1572,   229,  1266,   226,  1280,   615,   643,   452,   499,  1573,
     618,  1322,  1325,  1326,   652,  1388,  1052,   277,   656,   733,
    1143,  1144,   660,  1145,  1050,  1051,  1440,  1198,  1199,  1200,
    1201,   278,  1305,   279,   428,   280,   430,   281,   432,   282,
     336,  1020,  1164,  1165,  1021,   283,   337,   284,   443,   285,
     445,   286,  1052,   287,  1465,   288,  1052,   289,   590,   290,
      11,   291,   759,   758,   661,  1339,   592,  1275,  1276,  1277,
    1278,   196,  1345,   450,  1052,   662,   590,  1499,    13,   643,
      15,   634,   589,   197,   592,   590,   635,   213,   661,   591,
     729,   214,  1521,   592,   380,   381,   382,   383,   665,   740,
     109,  1052,  1184,   590,   110,    28,   111,   666,   112,  1373,
     113,   592,    53,   665,  1517,   634,  1052,   213,   590,   701,
     723,   214,   743,   707,   708,   709,   592,  1198,  1199,  1200,
    1201,   805,   804,    45,    92,   638,    93,    94,    90,  1549,
    1260,    54,   726,    55,    91,    56,   144,    57,  1396,    58,
     100,    59,   437,    60,   439,    61,   441,    62,  1555,    63,
     127,    64,   336,   213,   789,   790,   791,   214,   337,  1175,
     172,   626,   175,  1564,   627,  1142,   969,   970,  1143,  1144,
     180,  1145,   181,   182,   393,   179,   394,   395,  1433,   178,
     858,  1584,   267,   589,   268,   269,   590,   187,   213,   972,
     591,   973,   214,   761,   592,   231,   717,   959,   770,   627,
     960,   205,  1076,   974,   975,  1077,  1458,   252,  1175,   594,
       1,     2,   265,  1600,   325,   969,   970,   266,  1474,    18,
      19,    23,    24,    31,    32,  1485,    48,    49,  1609,  1492,
     882,   334,   589,   103,   104,   590,   344,   213,   972,   591,
     973,   214,   349,   592,   129,   130,  1329,   355,  1615,  1222,
     134,   135,   974,   975,   139,   140,   147,   148,   152,   153,
     157,   158,   162,   163,  1626,   354,  1510,   810,  1175,   167,
     168,   190,   191,  1629,   362,   969,   970,   821,   232,   233,
     253,   254,   260,   261,  1534,   327,   328,   363,   826,   369,
    1635,  1542,   589,   357,   358,   590,   365,   213,   972,   591,
     973,   214,   277,   592,   385,   386,   400,   401,   842,   416,
     417,   688,   974,   975,   454,   455,   278,   853,   279,   364,
     280,   372,   281,   378,   282,  1557,   371,   866,   459,   460,
     283,   374,   284,   373,   285,  1571,   286,  1058,   287,   370,
     288,   391,   289,   392,   290,   421,   291,   471,   472,   877,
     493,   494,   502,   503,   508,   509,   513,   514,   412,   890,
     518,   519,   523,   524,   529,   530,  1427,   969,   970,   534,
     535,   539,   540,   544,   545,  1593,   916,   549,   550,   971,
     554,   555,   433,   926,   589,   560,   561,   590,   424,   213,
     972,   591,   973,   214,   463,   592,   565,   566,   446,  1103,
     571,   572,   586,   587,   974,   975,   630,   631,   469,   757,
     965,    54,   477,    55,   480,    56,   478,    57,  1135,    58,
     484,    59,   386,    60,   485,    61,   501,    62,   507,    63,
     528,    64,   486,   670,   671,   674,   675,   684,   685,   702,
     703,   559,   720,   631,  1026,   747,   671,   753,   754,   771,
     772,   786,   787,   570,  1169,   577,  1182,  1179,   799,   800,
     811,   812,   843,   844,   867,   868,   891,   892,   899,   900,
     904,   905,  1061,   910,   911,   917,   918,   579,   803,   927,
     928,   933,   934,   938,   939,   944,   945,   996,   997,  1001,
    1002,  1007,  1008,  1034,  1035,  1063,  1064,  1098,  1099,  1108,
    1109,  1125,  1126,  1130,  1131,  1170,  1171,  1082,  1190,  1191,
    1195,  1196,  1216,  1217,  1230,  1231,  1248,  1249,  1267,  1268,
    1272,  1273,  1259,  1256,  1306,  1307,  1316,  1317,  1331,  1217,
    1335,  1336,  1346,  1347,  1374,  1375,  1397,  1398,  1414,  1415,
    1434,  1435,  1443,  1444,  1124,  1459,  1460,  1469,  1470,  1478,
    1479,  1493,  1494,  1137,  1511,  1512,  1524,  1525,  1529,  1530,
    1138,  1543,  1544,  1141,  1558,  1559,  1566,  1567,  1578,  1579,
    1594,  1595,  1603,  1604,  1620,  1621,   578,   580,   472,   582,
     603,   581,   605,  1327,  1324,   604,   608,   612,   613,   614,
     620,   619,   625,  1340,   642,   669,   680,   691,   692,   572,
     693,   694,   710,   697,   711,   763,   749,   715,   712,   675,
     716,   719,   722,   725,   728,   739,   745,   742,   760,   746,
     762,   776,   766,   781,   782,   783,   784,   785,   796,   797,
     777,   798,   807,   806,   816,   817,   823,   829,   822,   835,
     834,  1243,   836,   830,   837,   831,   832,   826,   840,   833,
     848,   849,   858,   838,   855,   841,   839,   872,   854,   873,
     874,   875,   909,   896,   943,   861,  1006,   885,   878,   882,
    1013,   950,   921,  1043,   879,  1032,  1300,  1059,  1060,  1027,
     955,  1062,  1069,   966,  1104,  1107,   911,  1139,  1140,  1215,
    1235,  1242,  1244,  1236,  1016,  1039,   959,  1046,  1314,  1315,
    1330,  1507,  1040,  1391,  1072,  1519,  1577,  1588,  1522,  1618,
    1612,  1619,  1088,  1384,    99,  1136,   583,   945,   481,  1089,
     714,  1119,  1154,   681,   413,   721,   718,    44,  1155,   727,
     724,  1185,   730,   128,   734,   736,  1353,  1083,  1113,  1450,
     738,  1008,  1094,  1360,  1020,  1241,   748,   967,   741,  1221,
    1225,  1262,   750,   744,  1047,  1301,  1477,  1212,  1341,  1484,
    1160,  1506,  1076,  1356,  1369,  1501,  1332,  1502,  1095,  1028,
    1385,  1313,  1404,  1084,  1161,  1451,  1392,  1068,  1382,  1383,
    1246,  1247,  1289,  1428,   206,     0,     0,     0,  1381,  1291,
       0,     0,     0,     0,     0,     0,     0,  1361,  1441,     0,
    1429,  1354,     0,  1357,     0,  1408,     0,  1292,     0,  1454,
    1466,  1500,     0,  1178,     0,  1405,  1406,  1518,  1488,     0,
    1550,     0,  1537,     0,     0,  1363,     0,  1538,  1565,  1611,
       0,  1585,     0,  1601,     0,  1553,     0,     0,     0,     0,
    1610,     0,     0,  1616,     0,     0,     0,  1630,  1627,  1636,
       0,     0,  1631,     0,  1637,  1442,  1638,     0,  1591,     0,
       0,     0,     0,  1602,  1587,     0,     0,     0,     0,     0,
     326,     0,     0,  1574,     0,     0,     0,     0,     0,  1255,
       0,     0,     0,     0,     0,     0,     0,     0,  1617,  1467,
    1468,     0,  1487,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1508,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1323,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1551,  1552,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1576,     0,     0,     0,     0,     0,
    1586,     0,     0,     0,     0,  1589,  1590,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1613,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1483,     0,     0,  1632,
    1633
};

static const yytype_int16 yycheck[] =
{
     124,   344,   483,   483,  1019,   354,   349,   825,   881,  1116,
    1190,  1030,   857,     8,     4,   126,     4,     6,     7,     4,
       4,     4,     4,  1387,  1087,  1087,  1087,  1042,     4,   378,
    1049,     4,  1387,     4,     4,     4,   122,   122,   534,  1297,
    1248,     4,   210,   539,   212,     4,   122,     0,   544,   171,
    1230,  1153,    74,   145,   107,   171,   405,   406,   407,   171,
    1075,   143,    26,   107,    72,    40,  1085,    67,   150,    44,
     162,    46,   194,    37,   190,    50,  1091,    52,  1097,    43,
     898,   145,   194,   145,   208,   138,   210,  1267,   212,  1453,
    1153,  1153,  1153,   204,   138,   171,   160,   119,  1453,    79,
     162,    81,    82,   145,   585,   585,  1121,   145,  1316,   131,
    1368,   119,  1214,   199,    76,   123,   145,   125,   160,   127,
     158,   129,   207,    30,    31,    32,  1306,   156,   296,   215,
     215,   100,   114,   116,   118,   106,   112,   110,   108,   215,
    1504,   104,  1157,   102,  1163,   134,   145,   132,   136,  1504,
     493,  1214,  1214,  1214,   650,  1413,    42,   119,   654,   158,
     217,   218,   658,   220,    10,    11,  1346,    53,    54,    55,
      56,   133,  1187,   135,   304,   137,   306,   139,   308,   141,
      45,   199,    10,    11,   202,   147,    51,   149,   318,   151,
     320,   153,    42,   155,  1374,   157,    42,   159,    44,   161,
      14,   163,   683,   683,   143,  1224,    52,    57,    58,    59,
      60,   119,  1227,   324,    42,   154,    44,  1397,    15,   145,
      69,   143,    41,   131,    52,    44,   148,    46,   143,    48,
     156,    50,   222,    52,   229,   230,   231,   232,   143,   154,
     119,    42,  1087,    44,   123,    71,   125,   152,   127,  1264,
     129,    52,    70,   143,  1434,   143,    42,    46,    44,   608,
     148,    50,   152,   612,   613,   614,    52,    53,    54,    55,
      56,   752,   752,    73,    83,   143,    85,    86,     5,  1459,
    1153,    99,   150,   101,    68,   103,    66,   105,  1303,   107,
      75,   109,   312,   111,   314,   113,   316,   115,  1478,   117,
      70,   119,    45,    46,    21,    22,    23,    50,    51,    17,
      65,   140,    16,  1493,   143,   214,    24,    25,   217,   218,
      87,   220,    89,    90,    95,     5,    97,    98,  1343,    80,
      38,  1511,    91,    41,    93,    94,    44,    77,    46,    47,
      48,    49,    50,   692,    52,     3,   140,   171,   697,   143,
     174,    72,   207,    61,    62,   210,  1371,     3,    17,   483,
      12,    13,    84,  1543,    74,    24,    25,     5,  1387,    10,
      11,    10,    11,    10,    11,  1390,    10,    11,  1558,  1394,
      39,    10,    41,    10,    11,    44,    10,    46,    47,    48,
      49,    50,    10,    52,    10,    11,  1214,    10,  1578,  1506,
      10,    11,    61,    62,    10,    11,    10,    11,    10,    11,
      10,    11,    10,    11,  1594,     3,  1431,   766,    17,    10,
      11,    10,    11,  1603,   100,    24,    25,   776,    10,    11,
      10,    11,    10,    11,  1453,    10,    11,   102,    37,   108,
    1620,  1456,    41,    10,    11,    44,     8,    46,    47,    48,
      49,    50,   119,    52,   120,   121,    10,    11,   807,    10,
      11,   585,    61,    62,    10,    11,   133,   816,   135,   104,
     137,   114,   139,     6,   141,  1490,   112,   826,     6,     7,
     147,     8,   149,   116,   151,  1504,   153,   968,   155,   110,
     157,    88,   159,     5,   161,    18,   163,   120,   121,   848,
      10,    11,    10,    11,    10,    11,    10,    11,    76,   858,
      10,    11,    10,    11,    10,    11,  1334,    24,    25,    10,
      11,    10,    11,    10,    11,  1540,   875,    10,    11,    36,
      10,    11,    20,   882,    41,    10,    11,    44,    19,    46,
      47,    48,    49,    50,     3,    52,    10,    11,    27,  1030,
     120,   121,    10,    11,    61,    62,   142,   143,     6,   683,
     909,    99,   106,   101,   120,   103,   118,   105,  1049,   107,
      92,   109,   121,   111,     5,   113,     8,   115,     8,   117,
       8,   119,   167,   164,   165,   120,   121,    10,    11,    10,
      11,     8,   142,   143,   943,   164,   165,    10,    11,    10,
      11,    10,    11,   132,  1085,   124,  1087,  1087,    10,    11,
      10,    11,    10,    11,    10,    11,    10,    11,    10,    11,
      10,    11,   971,   170,   171,   212,   213,   126,   752,    10,
      11,    10,    11,    10,    11,   198,   199,    10,    11,    10,
      11,   206,   207,    10,    11,    10,    11,    10,    11,    10,
      11,    10,    11,    10,    11,    10,    11,  1006,    10,    11,
      10,    11,   192,   193,    10,    11,    10,    11,    10,    11,
      10,    11,  1153,  1153,    10,    11,    10,    11,   192,   193,
      10,    11,    10,    11,    10,    11,    10,    11,    10,    11,
      10,    11,    10,    11,  1043,    10,    11,    10,    11,    10,
      11,    10,    11,  1052,    10,    11,   223,   224,    10,    11,
    1059,    10,    11,  1062,    10,    11,    10,    11,    10,    11,
      10,    11,    10,    11,    10,    11,     8,   128,   121,   120,
      96,   130,   195,  1214,  1214,    78,    33,     6,     6,     6,
       6,   136,     6,  1224,     6,     6,   120,   122,     3,   121,
       3,   203,   134,    34,     8,   211,   120,     8,    10,   121,
      10,    10,    10,    10,     8,    10,     8,    10,   122,    10,
       8,     6,    35,     4,     4,     4,     4,     4,     4,     4,
     169,     4,    28,   122,     6,   197,   173,   108,   168,     3,
     146,  1140,     3,   144,     3,   144,   144,    37,   166,   144,
       6,   205,    38,   144,   201,   122,   144,     8,   196,     8,
       8,     6,     6,   189,     6,   175,     6,   175,   204,    39,
     121,   191,   175,    40,   209,    29,  1175,     3,     3,   198,
     177,     3,   121,   170,   121,     8,   171,     8,     6,     6,
       6,     6,     5,   221,   177,   176,   171,   174,     3,     3,
       8,     8,   181,     6,   177,     6,     6,     6,    10,     6,
       8,     6,   176,   122,    44,   172,   474,   199,   388,   181,
     623,   179,   176,   574,   293,   632,   628,    23,   181,   640,
     636,   179,   645,    66,   650,   654,  1235,   206,   171,   122,
     658,   207,   202,  1242,   199,   172,   672,   913,   663,   190,
     185,   179,   677,   667,   962,   185,  1387,   200,   183,  1390,
     210,  1414,   207,   178,   185,   122,  1218,  1410,  1023,   947,
    1294,   200,   178,  1010,  1079,  1365,   183,   977,  1277,  1278,
     214,  1147,   208,   172,   115,    -1,    -1,    -1,   208,   199,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   219,   182,    -1,
     187,   225,    -1,   226,    -1,   171,    -1,   215,    -1,   183,
     178,   182,    -1,  1087,    -1,  1314,  1315,   180,   187,    -1,
     182,    -1,  1453,    -1,    -1,   207,    -1,   187,   180,   172,
      -1,   186,    -1,   180,    -1,   200,    -1,    -1,    -1,    -1,
     186,    -1,    -1,   184,    -1,    -1,    -1,   184,   186,   184,
      -1,    -1,   188,    -1,   188,  1354,   188,    -1,   208,    -1,
      -1,    -1,    -1,   216,   222,    -1,    -1,    -1,    -1,    -1,
     199,    -1,    -1,  1504,    -1,    -1,    -1,    -1,    -1,  1153,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   227,  1382,
    1383,    -1,  1391,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1420,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1214,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1467,  1468,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1507,    -1,    -1,    -1,    -1,    -1,
    1519,    -1,    -1,    -1,    -1,  1524,  1525,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1577,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1390,    -1,    -1,  1618,
    1619
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
     330,   331,    65,   335,   336,    16,   343,   998,    80,     5,
      87,    89,    90,   257,   258,   259,   260,    77,   563,   564,
      10,    11,   433,   434,   435,    74,   119,   131,   408,   409,
     410,   411,   412,   417,   418,    72,   362,   365,   366,   372,
     373,   379,   380,    46,    50,   386,   940,   941,   942,   943,
     391,   998,     4,   100,   282,     4,   102,   288,     4,   104,
     294,     3,    10,    11,   299,   300,   301,     4,   108,   308,
       4,   110,   314,     4,   112,   320,     4,   114,   326,     4,
     116,   332,     3,    10,    11,   337,   338,   339,  1032,  1033,
      10,    11,   344,   345,   346,    84,     5,    91,    93,    94,
     261,   262,   263,   264,   565,   566,    76,   119,   133,   135,
     137,   139,   141,   147,   149,   151,   153,   155,   157,   159,
     161,   163,   436,   437,   438,   439,   440,   447,   448,   453,
     454,   461,   462,   469,   470,   477,   478,   485,   486,   493,
     494,   501,   502,   509,   510,   517,   518,   525,   526,   533,
     534,   541,   542,   549,   550,    74,   410,    10,    11,   413,
     414,   415,   419,   998,    10,   368,    45,    51,   367,   940,
     980,   981,   982,   983,    10,   375,   374,   940,   980,    10,
     382,   381,   940,   980,     3,    10,   387,    10,    11,   392,
     393,   394,   100,   102,   104,     8,     4,   106,   302,   108,
     110,   112,   114,   116,     8,     4,   118,   340,     6,     8,
     229,   230,   231,   232,  1034,   120,   121,   347,   348,   349,
     350,    88,     5,    95,    97,    98,   265,   266,   267,   268,
      10,    11,   568,   569,   570,    30,    31,    32,   567,   989,
     995,  1005,    76,   438,   441,   980,    10,    11,   449,   450,
     451,    18,   455,   993,    19,   463,  1001,   471,  1001,   479,
    1001,   487,  1001,    20,   495,  1000,   503,  1000,   511,  1000,
     519,  1000,   527,  1001,   535,  1001,    27,   543,  1002,   551,
     998,     4,   132,   416,    10,    11,   420,   421,   422,     6,
       7,   369,  1031,     3,   376,  1031,   383,  1031,  1032,     6,
     388,   120,   121,   395,   396,   397,   398,   106,   118,  1032,
     120,   349,   351,   352,    92,     5,   167,   571,   572,   573,
    1032,  1032,  1032,    10,    11,   442,   443,   444,     4,   136,
     452,     8,    10,    11,   456,   457,   458,     8,    10,    11,
     464,   465,   466,    10,    11,   472,   473,   474,    10,    11,
     480,   481,   482,    10,    11,   488,   489,   490,     8,    10,
      11,   496,   497,   498,    10,    11,   504,   505,   506,    10,
      11,   512,   513,   514,    10,    11,   520,   521,   522,    10,
      11,   528,   529,   530,    10,    11,   536,   537,   538,     8,
      10,    11,   544,   545,   546,    10,    11,   552,   553,   554,
     132,   120,   121,   423,   424,   425,   426,   124,     8,   126,
     128,   130,   120,   397,   399,   400,    10,    11,   354,    41,
      44,    48,    52,   353,   940,   957,   958,   959,   960,   984,
     985,   986,   987,    96,    78,   195,   702,   703,    33,   574,
     575,   999,     6,     6,     6,   134,   445,   446,  1031,   136,
       6,   107,   138,   459,   460,     6,   140,   143,   467,   468,
     142,   143,   475,   476,   143,   148,   483,   484,   143,   150,
     491,   492,     6,   145,   156,   499,   500,   927,   928,   158,
     507,   508,   927,   162,   515,   516,   927,   160,   523,   524,
     927,   143,   154,   531,   532,   143,   152,   539,   540,     6,
     164,   165,   547,   548,   120,   121,   555,   556,   557,   558,
     120,   425,   427,   428,    10,    11,   402,   401,   940,   957,
     984,   122,     3,     3,   203,   804,   805,    34,   704,   705,
     997,  1032,    10,    11,   576,   577,   578,  1032,  1032,  1032,
     134,     8,    10,   138,   460,     8,    10,   140,   468,    10,
     142,   476,    10,   148,   484,    10,   150,   492,     8,   156,
     500,   929,   930,   158,   508,   162,   516,   160,   524,    10,
     154,   532,    10,   152,   540,     8,    10,   164,   548,   120,
     557,   559,   560,    10,    11,   430,   429,   940,   957,   984,
     122,  1032,     8,   211,   905,   906,    35,   806,   807,   996,
    1032,    10,    11,   706,   707,   708,     6,   169,   579,   580,
     581,     4,     4,     4,     4,     4,    10,    11,   935,    21,
      22,    23,   931,   932,   933,   934,     4,     4,     4,    10,
      11,   562,   561,   940,   957,   984,   122,    28,   907,  1003,
    1032,    10,    11,   808,   809,   810,     6,   197,   709,   710,
     711,  1032,   168,   173,   593,   594,    37,   582,  1004,   108,
     144,   144,   144,   144,   146,     3,     3,     3,   144,   144,
     166,   122,  1032,    10,    11,   908,   909,   910,     6,   205,
     811,   812,   813,  1032,   196,   201,   724,   725,    38,   712,
     994,   175,   607,   608,   595,  1004,  1032,    10,    11,   583,
     584,   585,     8,     8,     8,     6,   911,  1032,   204,   209,
     825,   826,    39,   814,   988,   175,   738,   739,   726,   994,
    1032,    10,    11,   713,   714,   715,   189,   655,   656,    10,
      11,   609,   610,   611,    10,    11,   596,   597,   598,     6,
     170,   171,   586,   587,   588,   589,  1032,   212,   213,   912,
     913,   175,   839,   840,   827,   988,  1032,    10,    11,   815,
     816,   817,   786,    10,    11,   740,   741,   742,    10,    11,
     727,   728,   729,     6,   198,   199,   716,   717,   718,   719,
     191,   669,   670,   657,  1004,   177,   612,   613,   614,   171,
     174,   599,   600,   601,   602,  1032,   170,   588,   590,    24,
      25,    36,    47,    49,    61,    62,   914,   915,   916,   936,
     937,   938,   939,   940,   957,   961,   962,   963,   964,   968,
     969,   970,   971,   984,   992,   887,    10,    11,   841,   842,
     843,    10,    11,   828,   829,   830,     6,   206,   207,   818,
     819,   820,   821,   121,   787,   788,   177,   743,   744,   745,
     199,   202,   730,   731,   732,   733,  1032,   198,   718,   720,
     721,   684,    29,   671,    10,    11,   658,   659,   660,   176,
     181,   620,   621,    40,   615,   990,   174,   601,   603,   604,
      10,    11,    42,   591,   592,   946,   947,   948,   984,     3,
       3,  1032,     3,    10,    11,   917,   918,   919,   916,   121,
     888,   889,   177,   844,   845,   846,   207,   210,   831,   832,
     833,   834,  1032,   206,   820,   822,   789,   790,   176,   181,
     751,   752,   746,   990,   202,   732,   734,   735,    10,    11,
     723,   722,   946,   984,   121,   685,   686,     8,    10,    11,
     672,   673,   674,   171,   190,   661,   662,   663,   664,   179,
     627,   628,   622,   990,  1032,    10,    11,   616,   617,   618,
      10,    11,   606,   605,   946,   984,   172,  1032,  1032,     8,
       6,  1032,   214,   217,   218,   220,   920,   921,   922,   923,
     924,   925,   890,   891,   176,   181,   852,   853,   847,   990,
     210,   833,   835,   836,    10,    11,   823,   824,   946,   984,
      10,    11,   792,   793,   794,    17,   791,   936,   940,   957,
     961,   968,   984,   991,   994,   179,   758,   759,   753,   990,
      10,    11,   747,   748,   749,    10,    11,   737,    53,    54,
      55,    56,   736,   946,   949,   950,   951,   952,   972,   973,
     974,   975,   200,   687,   688,     6,   192,   193,   675,   676,
     677,   190,   663,   665,   666,   185,   634,   635,   629,   990,
      10,    11,   623,   624,   625,     6,   221,   619,  1016,  1017,
    1024,   172,     6,  1032,     5,   926,   214,   922,    10,    11,
     893,   894,   895,   892,   936,   940,   957,   961,   968,   984,
     988,   991,   179,   859,   860,   854,   990,    10,    11,   848,
     849,   850,    10,    11,   838,    57,    58,    59,    60,   837,
     946,   953,   954,   955,   956,   976,   977,   978,   979,   208,
     122,   199,   215,   795,   796,   797,   798,  1006,  1007,  1008,
    1032,   185,   765,   766,   760,   990,    10,    11,   754,   755,
     756,   750,  1016,   200,     3,     3,    10,    11,   690,   691,
     692,   689,   936,   940,   957,   961,   968,   984,   991,  1004,
       8,   192,   676,   678,   679,    10,    11,   668,   667,   946,
     984,   183,   641,   642,   636,   990,    10,    11,   630,   631,
     632,   626,  1016,  1032,   225,  1025,   178,   226,  1018,  1019,
    1032,   219,   122,   207,   896,   897,   898,   899,  1006,   185,
     866,   867,   861,   990,    10,    11,   855,   856,   857,   851,
    1016,   208,  1032,  1032,   122,   797,   799,   800,  1007,  1009,
    1010,     6,   183,   772,   773,   767,   990,    10,    11,   761,
     762,   763,   757,  1016,   178,  1032,  1032,   122,   171,   693,
     694,   695,   696,  1006,    10,    11,   681,   682,   683,    26,
      43,   680,   944,   945,   965,   966,   967,  1004,   172,   187,
     648,   649,   643,   990,    10,    11,   637,   638,   639,   633,
    1016,   182,  1032,    10,    11,  1026,  1027,  1028,  1020,  1021,
     122,   898,   900,   901,   183,   873,   874,   868,   990,    10,
      11,   862,   863,   864,   858,  1016,   178,  1031,  1031,    10,
      11,   802,   803,   801,   946,   949,   972,   984,    10,    11,
    1012,  1013,  1014,   940,   984,   990,  1011,  1032,   187,   779,
     780,   774,   990,    10,    11,   768,   769,   770,   764,  1016,
     182,   122,   695,   697,   698,   194,   662,     8,  1032,   650,
     990,    10,    11,   644,   645,   646,   640,  1016,   180,     6,
       4,   222,    10,  1023,   223,   224,  1022,  1029,  1030,    10,
      11,   903,   904,   902,   946,   949,   972,   984,   187,   880,
     881,   875,   990,    10,    11,   869,   870,   871,   865,  1016,
     182,  1032,  1032,   200,  1015,  1016,   781,   990,    10,    11,
     775,   776,   777,   771,  1016,   180,    10,    11,   700,   701,
     699,   946,   949,   972,   984,   194,  1031,     6,    10,    11,
     651,   652,   653,   647,  1016,   186,  1032,   222,     6,  1032,
    1032,   208,   882,   990,    10,    11,   876,   877,   878,   872,
    1016,   180,   216,    10,    11,   782,   783,   784,   778,  1016,
     186,   172,     8,  1032,   654,  1016,   184,   227,     6,     6,
      10,    11,   883,   884,   885,   879,  1016,   186,   785,  1016,
     184,   188,  1032,  1032,   886,  1016,   184,   188,   188
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
#if YYLTYPE_IS_TRIVIAL
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
;}
    break;

  case 5:

    {
#ifdef DEBUG
yydebug = 1;
#endif
;}
    break;

  case 13:

    {	osolerror( NULL, osoption, parserData, osglData, "unexpected end of file, expecting </osol>");;}
    break;

  case 16:

    {
	if(!osoption->setOptionHeader(osglData->fileName, osglData->source,
			osglData->description, osglData->fileCreator, osglData->licence) ) 	
		osolerror( NULL, osoption, parserData, osglData, "setHeader failed");
;}
    break;

  case 17:

    {
	osglData->fileName    = "";
	osglData->source      = "";
	osglData->description = "";
	osglData->fileCreator = "";
	osglData->licence     = "";
;}
    break;

  case 29:

    {
	osglData->fileName = (yyvsp[(2) - (3)].sval);
;}
    break;

  case 36:

    {
	osglData->source = (yyvsp[(2) - (3)].sval);
;}
    break;

  case 43:

    {
	osglData->description = (yyvsp[(2) - (3)].sval);
;}
    break;

  case 50:

    {
	osglData->fileCreator = (yyvsp[(2) - (3)].sval);
;}
    break;

  case 57:

    {
	osglData->licence = (yyvsp[(2) - (3)].sval);
;}
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
;}
    break;

  case 81:

    {	if (parserData->serviceURIPresent)
		osolerror( NULL, osoption, parserData, osglData, "only one <serviceURI> element allowed");
	else
		parserData->serviceURIPresent = true;
	
;}
    break;

  case 87:

    {
		if (osoption->setServiceURI((yyvsp[(1) - (1)].sval)) == false)
			osolerror( NULL, osoption, parserData, osglData, "setServiceURI failed");
			//free($1); 
		parserData->errorText = NULL;
	;}
    break;

  case 89:

    {	if (parserData->serviceNamePresent)
			osolerror(NULL, NULL, parserData, osglData, "only one serviceName element allowed");
		parserData->serviceNamePresent = true;
	;}
    break;

  case 95:

    {
			osoption->setServiceName((yyvsp[(1) - (1)].sval)); 
			//free($1); 
			parserData->errorText = NULL;
		;}
    break;

  case 97:

    {	if (parserData->instanceNamePresent)
			osolerror(NULL, NULL, parserData, osglData, "only one instanceName element allowed");
		parserData->instanceNamePresent = true;
	;}
    break;

  case 103:

    {
		if (osoption->setInstanceName((yyvsp[(1) - (1)].sval)) == false) 
			osolerror( NULL, osoption, parserData, osglData, "setInstanceName failed");
		//free($1); 
		parserData->errorText = NULL;
	;}
    break;

  case 104:

    {
	if (osoption->setInstanceLocation(parserData->tempStr,parserData->typeAttribute) == false)
		osolerror(NULL, NULL, parserData, osglData, "setInstanceLocation failed");
	parserData->errorText = NULL;
;}
    break;

  case 105:

    {
		if (parserData->instanceLocationPresent)
			osolerror(NULL, NULL, parserData, osglData, "only one instanceLocation element allowed");
		parserData->instanceLocationPresent = true;
		parserData->typeAttribute = "local";
	;}
    break;

  case 107:

    {   
		if (verifyLocationType(parserData->typeAttribute) == false)
			osolerror(NULL, NULL, parserData, osglData, "instance location type not recognized");
		parserData->errorText = NULL;
	;}
    break;

  case 108:

    { 
	parserData->typeAttribute = (yyvsp[(2) - (3)].sval); 
	free((yyvsp[(2) - (3)].sval));
;}
    break;

  case 114:

    {	
		parserData->tempStr = (yyvsp[(1) - (1)].sval);
		//free($1); 
	;}
    break;

  case 116:

    {	if (parserData->jobIDPresent)
			osolerror(NULL, NULL, parserData, osglData, "only one jobID element allowed");
		parserData->jobIDPresent = true;
	;}
    break;

  case 122:

    {
		if (osoption->setJobID((yyvsp[(1) - (1)].sval)) == false)
			osolerror( NULL, osoption, parserData, osglData, "setJobID failed");
		//free($1); 
		parserData->errorText = NULL;
	;}
    break;

  case 124:

    {
		if (parserData->solverToInvokePresent)
			osolerror(NULL, NULL, parserData, osglData, "only one solverToInvoke element allowed");
		parserData->solverToInvokePresent = true;
	;}
    break;

  case 130:

    {
		if (osoption->setSolverToInvoke((yyvsp[(1) - (1)].sval)) == false)
			osolerror( NULL, osoption, parserData, osglData, "setSolverToInvoke failed");
		//free($1); 
		parserData->errorText = NULL;
	;}
    break;

  case 132:

    {
	if (parserData->licensePresent)
		osolerror( NULL, osoption, parserData, osglData, "only one <license> element allowed");
	parserData->licensePresent = true;	
;}
    break;

  case 138:

    {
		if (osoption->setLicense((yyvsp[(1) - (1)].sval)) == false)
			osolerror( NULL, osoption, parserData, osglData, "setLicense failed");
		//free($1);
		parserData->errorText = NULL;
	;}
    break;

  case 140:

    {	if (parserData->usernamePresent)
		osolerror( NULL, osoption, parserData, osglData, "only one <username> element allowed");
	parserData->usernamePresent = true;	
;}
    break;

  case 146:

    {
		if (osoption->setUserName((yyvsp[(1) - (1)].sval)) == false)
			osolerror( NULL, osoption, parserData, osglData, "setUsername failed");
		//free($1); 
		parserData->errorText = NULL;
	;}
    break;

  case 148:

    {	if (parserData->passwordPresent)
		osolerror( NULL, osoption, parserData, osglData, "only one <password> element allowed");
	parserData->passwordPresent = true;	
;}
    break;

  case 154:

    {
		if (osoption->setPassword((yyvsp[(1) - (1)].sval)) == false)
			osolerror( NULL, osoption, parserData, osglData, "setPassword failed");
		//free($1); 
		parserData->errorText = NULL;
	;}
    break;

  case 155:

    {
	if (osoption->setContact(parserData->tempStr,parserData->typeAttribute) == false)
		osolerror( NULL, osoption, parserData, osglData, "setContact failed");
	parserData->errorText = NULL;
;}
    break;

  case 156:

    {
	if (parserData->contactPresent)
		osolerror( NULL, osoption, parserData, osglData, "only one <contact> element allowed");
	parserData->contactPresent = true;
	parserData->typeAttribute = "osp";
	parserData->tempStr = "";
;}
    break;

  case 158:

    {   
		if (verifyTransportType(parserData->typeAttribute) == false)
			osolerror(NULL, NULL, parserData, osglData, "transport type not recognized");
	;}
    break;

  case 159:

    { 
	parserData->typeAttribute = (yyvsp[(2) - (3)].sval); 
	free((yyvsp[(2) - (3)].sval));
;}
    break;

  case 165:

    {
		parserData->tempStr = (yyvsp[(1) - (1)].sval);
	;}
    break;

  case 167:

    {	if (parserData->otherGeneralOptionsPresent)
		osolerror(NULL, NULL, parserData, osglData, "only one <general> <other> element allowed");
	parserData->otherGeneralOptionsPresent = true;
;}
    break;

  case 168:

    {
	if (parserData->tempInt < 0) osolerror(NULL, NULL, parserData, osglData, "number of other general options cannot be negative");
	parserData->numberOf = parserData->tempInt;
	parserData->kounter = 0;
;}
    break;

  case 169:

    {	if (parserData->numberOf > 0)
			osolerror(NULL, NULL, parserData, osglData, "expected at least one <other> element");
	;}
    break;

  case 170:

    {	if (parserData->kounter < parserData->numberOf - 1)
			osolerror(NULL, NULL, parserData, osglData, "fewer <other> elements than specified");
	;}
    break;

  case 177:

    {	
	parserData->kounter++;
	if (osoption->setAnOtherGeneralOption(parserData->nameAttribute, parserData->valueAttribute, parserData->descriptionAttribute) == false)
		osolerror(NULL, NULL, parserData, osglData, "setOtherGeneralOption failed");
;}
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
;}
    break;

  case 179:

    {
	if (!parserData->nameAttributePresent)
		osolerror (NULL, NULL, parserData, osglData, "<other> must have name attribute");
;}
    break;

  case 182:

    {	if (parserData->nameAttribute.length() == 0)
			osolerror(NULL, NULL, parserData, osglData, "otherOption name cannot be empty");
	;}
    break;

  case 189:

    {
	parserData->minDiskSpacePresent = false;	
	parserData->minMemoryPresent = false;
	parserData->minCPUSpeedPresent = false;
	parserData->minCPUNumberPresent = false;
	parserData->otherSystemOptionsPresent = false;
	osoption->system = new SystemOption();
;}
    break;

  case 204:

    {	if (parserData->minDiskSpacePresent)
			osolerror(NULL, NULL, parserData, osglData, "only one minDiskSpace element allowed");
		parserData->minDiskSpacePresent = true;	
		parserData->unitAttributePresent = false;	
		parserData->descriptionAttributePresent = false;	
		parserData->unitAttribute = "byte";	
		parserData->descriptionAttribute = "";
	;}
    break;

  case 211:

    {
	if (osoption->setMinDiskSpace(parserData->unitAttribute, parserData->descriptionAttribute, parserData->tempVal) == false)
		osolerror(NULL, NULL, parserData, osglData, "setMinDiskSpace failed");
	parserData->errorText = NULL;
;}
    break;

  case 213:

    {	if (parserData->minMemoryPresent)
			osolerror(NULL, NULL, parserData, osglData, "only one minMemory element allowed");
		parserData->minMemoryPresent = true;
		parserData->unitAttributePresent = false;	
		parserData->descriptionAttributePresent = false;	
		parserData->unitAttribute = "byte";	
		parserData->descriptionAttribute = "";
	;}
    break;

  case 220:

    {
	if (osoption->setMinMemorySize(parserData->unitAttribute, parserData->descriptionAttribute, parserData->tempVal) == false)
		osolerror(NULL, NULL, parserData, osglData, "setMinMemorySize failed");
    parserData->errorText = NULL;
;}
    break;

  case 222:

    {	if (parserData->minCPUSpeedPresent)
			osolerror(NULL, NULL, parserData, osglData, "only one minCPUSpeed element allowed");
		parserData->minCPUSpeedPresent = true;
		parserData->unitAttributePresent = false;	
		parserData->descriptionAttributePresent = false;	
		parserData->unitAttribute = "hertz";	
		parserData->descriptionAttribute = "";
	;}
    break;

  case 229:

    {	
	if (osoption->setMinCPUSpeed(parserData->unitAttribute, parserData->descriptionAttribute, parserData->tempVal) == false)
		osolerror(NULL, NULL, parserData, osglData, "setMinCPUSpeed failed");
    parserData->errorText = NULL;
;}
    break;

  case 231:

    {	if (parserData->minCPUNumberPresent)
			osolerror(NULL, NULL, parserData, osglData, "only one minCPUNumber element allowed");
		parserData->minCPUNumberPresent = true;
		parserData->descriptionAttributePresent = false;	
		parserData->descriptionAttribute = "";	
	;}
    break;

  case 235:

    {
	if (osoption->setMinCPUNumber((yyvsp[(1) - (1)].ival), parserData->descriptionAttribute) == false)
		osolerror(NULL, NULL, parserData, osglData, "setMinCPUNumber failed");
	//free($1); 
	parserData->errorText = NULL; 
;}
    break;

  case 237:

    {
	if (parserData->otherSystemOptionsPresent)
		osolerror(NULL, NULL, parserData, osglData, "only one <system> <other> element allowed");
	parserData->otherSystemOptionsPresent = true;
;}
    break;

  case 238:

    {
	if (parserData->tempInt < 0) osolerror(NULL, NULL, parserData, osglData, "number of other system options cannot be negative");
	parserData->numberOf = parserData->tempInt;
	parserData->kounter = 0;
;}
    break;

  case 239:

    {	if (parserData->numberOf > 0)
			osolerror(NULL, NULL, parserData, osglData, "expected at least one <other> element");
	;}
    break;

  case 240:

    {	if (parserData->kounter < parserData->numberOf - 1)
			osolerror(NULL, NULL, parserData, osglData, "fewer <other> elements than specified");
	;}
    break;

  case 247:

    {
	parserData->kounter++;
	if (osoption->setAnOtherSystemOption(parserData->nameAttribute, parserData->valueAttribute, parserData->descriptionAttribute) == false)
		osolerror(NULL, NULL, parserData, osglData, "setOtherSystemOption failed");
;}
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
;}
    break;

  case 249:

    {	if (!parserData->nameAttributePresent)
		osolerror (NULL, NULL, parserData, osglData, "<other> must have name attribute");
;}
    break;

  case 252:

    {
		if (parserData->nameAttribute.length() == 0)
			osolerror(NULL, NULL, parserData, osglData, "otherOption name cannot be empty");
	;}
    break;

  case 259:

    {
	parserData->serviceTypePresent = false;	
	parserData->otherServiceOptionsPresent = false;
	osoption->service = new ServiceOption();
;}
    break;

  case 271:

    {	if (parserData->serviceTypePresent)
			osolerror(NULL, NULL, parserData, osglData, "only one currentState element allowed");
		parserData->serviceTypePresent = true;
	;}
    break;

  case 277:

    {
       parserData->tempStr = (yyvsp[(1) - (1)].sval); 
		//free($1);
		if (osoption->setServiceType(parserData->tempStr) == false)
			osolerror(NULL, NULL, parserData, osglData, "setServiceType failed; current system state not recognized");
		parserData->errorText = NULL;
	;}
    break;

  case 279:

    {
	if (parserData->otherServiceOptionsPresent)
		osolerror(NULL, NULL, parserData, osglData, "only one <service> <other> element allowed");
	parserData->otherServiceOptionsPresent = true;
;}
    break;

  case 280:

    {
	if (parserData->tempInt < 0) osolerror(NULL, NULL, parserData, osglData, "number of other service options cannot be negative");
	parserData->numberOf = parserData->tempInt;
	parserData->kounter = 0;
;}
    break;

  case 281:

    {	if (parserData->numberOf > 0)
			osolerror(NULL, NULL, parserData, osglData, "expected at least one <other> element");
	;}
    break;

  case 282:

    {	if (parserData->kounter < parserData->numberOf - 1)
			osolerror(NULL, NULL, parserData, osglData, "fewer <other> elements than specified");
	;}
    break;

  case 289:

    {	
	parserData->kounter++;
	if (osoption->setAnOtherServiceOption(parserData->nameAttribute, parserData->valueAttribute, parserData->descriptionAttribute) == false)
		osolerror(NULL, NULL, parserData, osglData, "setOtherServiceOption failed");
;}
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
;}
    break;

  case 291:

    {	if (!parserData->nameAttributePresent)
		osolerror (NULL, NULL, parserData, osglData, "<other> must have name attribute");
;}
    break;

  case 294:

    {
		if (parserData->nameAttribute.length() == 0)
			osolerror(NULL, NULL, parserData, osglData, "otherOption name cannot be empty");
	;}
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
 ;}
    break;

  case 325:

    {	
	if (osoption->setMaxTime(parserData->maxTimeValue, parserData->unitAttribute) == false)       
			osolerror(NULL, NULL, parserData, osglData, "max time request could not be honored");
;}
    break;

  case 326:

    {	
	if (parserData->maxTimePresent)
		osolerror( NULL, osoption, parserData, osglData, "only one <maxTime> element allowed");
	parserData->maxTimePresent = true;
	parserData->unitAttributePresent = false;	
	parserData->unitAttribute = "second"; 
	parserData->maxTimeValue = OSDBL_MAX;
;}
    break;

  case 334:

    {
	parserData->maxTimeValue = parserData->tempVal;
;}
    break;

  case 336:

    {	if (parserData->requestedStartTimePresent)
			osolerror(NULL, NULL, parserData, osglData, "only one requestedStartTime element allowed");
		parserData->requestedStartTimePresent = true;
	;}
    break;

  case 342:

    {
		if (osoption->setRequestedStartTime((yyvsp[(1) - (1)].sval)) == false)
			osolerror(NULL, NULL, parserData, osglData, "setRequestedStartTime failed");	
		//free($1); 
		parserData->errorText = NULL;
		;}
    break;

  case 343:

    {
	if (osoption->setJobDependencies(parserData->numberOf, parserData->jobDependencies) == false)
		osolerror (NULL, osoption, parserData, osglData, "set <job> <dependencies> failed");
	delete[] parserData->jobDependencies;
	parserData->jobDependencies = NULL;
;}
    break;

  case 344:

    {
	if (parserData->dependenciesPresent)
		osolerror( NULL, osoption, parserData, osglData, "only one <dependencies> element allowed");
	parserData->dependenciesPresent = true;
;}
    break;

  case 350:

    {
	if (parserData->kounter > parserData->numberOf)
		osolerror (NULL, osoption, parserData, osglData, "too few job IDs in <dependencies> element");
;}
    break;

  case 353:

    {
	if (parserData->kounter >= parserData->numberOf)
		osolerror (NULL, osoption, parserData, osglData, "too many job IDs in <dependencies> element");
	parserData->jobDependencies[parserData->kounter] = (yyvsp[(3) - (4)].sval);
	//free($3); 
	parserData->kounter++;
;}
    break;

  case 354:

    {
	if (osoption->setRequiredDirectories(parserData->numberOf,parserData->paths) == false)
		osolerror (NULL, osoption, parserData, osglData, "set <requiredDirectories> failed");
	delete[] parserData->paths;
	parserData->paths = NULL;
;}
    break;

  case 355:

    {	if (parserData->requiredDirectoriesPresent)
		osolerror( NULL, osoption, parserData, osglData, "only one <requiredDirectories> element allowed");
	parserData->requiredDirectoriesPresent = true;
;}
    break;

  case 361:

    {
	if (parserData->kounter > parserData->numberOf)
		osolerror (NULL, osoption, parserData, osglData, "too few paths in <requiredDirectories> element");
;}
    break;

  case 364:

    {
	if (parserData->kounter >= parserData->numberOf)
		osolerror (NULL, osoption, parserData, osglData, "too many paths in <requiredDirectories> element");
	parserData->paths[parserData->kounter] = (yyvsp[(3) - (4)].sval);
	//free($3); 
	parserData->kounter++;
;}
    break;

  case 365:

    {
	if (osoption->setRequiredFiles(parserData->numberOf, parserData->paths) == false)
		osolerror (NULL, osoption, parserData, osglData, "set <requiredFiles> failed");
	delete[] parserData->paths;
	parserData->paths = NULL;
;}
    break;

  case 366:

    {	if (parserData->requiredFilesPresent)
		osolerror( NULL, osoption, parserData, osglData, "only one <requiredFiles> element allowed");
	parserData->requiredFilesPresent = true;
;}
    break;

  case 372:

    {
	if (parserData->kounter > parserData->numberOf)
		osolerror (NULL, osoption, parserData, osglData, "too few paths in <requiredFiles> element");
;}
    break;

  case 375:

    {
	if (parserData->kounter >= parserData->numberOf)
		osolerror (NULL, osoption, parserData, osglData, "too many paths in <requiredFiles> element");
	parserData->paths[parserData->kounter] = (yyvsp[(3) - (4)].sval);
	//free($3);
	parserData->kounter++;
;}
    break;

  case 376:

    {
	if (osoption->setDirectoriesToMake(parserData->numberOf, parserData->paths) == false)
		osolerror (NULL, osoption, parserData, osglData, "set <directoriesToMake> failed");
	delete[] parserData->paths;
	parserData->paths = NULL;
;}
    break;

  case 377:

    {	if (parserData->directoriesToMakePresent)
		osolerror( NULL, osoption, parserData, osglData, "only one <directoriesToMake> element allowed");
	parserData->directoriesToMakePresent = true;
;}
    break;

  case 383:

    {
	if (parserData->kounter > parserData->numberOf)
		osolerror (NULL, osoption, parserData, osglData, "too few paths in <directoriesToMake> element");
;}
    break;

  case 386:

    {
	if (parserData->kounter >= parserData->numberOf)
		osolerror (NULL, osoption, parserData, osglData, "too many paths in <directoriesToMake> element");
	parserData->paths[parserData->kounter] = (yyvsp[(3) - (4)].sval);
	//free($3); 
	parserData->kounter++;
;}
    break;

  case 387:

    {
	if (osoption->setFilesToMake(parserData->numberOf, parserData->paths) == false)
		osolerror (NULL, osoption, parserData, osglData, "set <filesToMake> failed");
	delete[] parserData->paths;
	parserData->paths = NULL;
;}
    break;

  case 388:

    {	if (parserData->filesToMakePresent)
		osolerror( NULL, osoption, parserData, osglData, "only one <filesToMake> element allowed");
	parserData->filesToMakePresent = true;
;}
    break;

  case 394:

    {
	if (parserData->kounter > parserData->numberOf)
		osolerror (NULL, osoption, parserData, osglData, "too few paths in <filesToMake> element");
;}
    break;

  case 397:

    {
	if (parserData->kounter >= parserData->numberOf)
		osolerror (NULL, osoption, parserData, osglData, "too many paths in <filesToMake> element");
	parserData->paths[parserData->kounter] = (yyvsp[(3) - (4)].sval);
	//free($3); 
	parserData->kounter++;
;}
    break;

  case 398:

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
;}
    break;

  case 399:

    {	if (parserData->inputDirectoriesToMovePresent)
		osolerror( NULL, osoption, parserData, osglData, "only one <inputDirectoriesToMove> element allowed");
		parserData->inputDirectoriesToMovePresent = true;
;}
    break;

  case 405:

    {
	if (parserData->kounter > parserData->numberOfPathPairs)
		osolerror (NULL, osoption, parserData, osglData, "too few path pairs in <inputDirectoriesToMove> element");
;}
    break;

  case 409:

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
;}
    break;

  case 410:

    {	if (parserData->inputFilesToMovePresent)
		osolerror( NULL, osoption, parserData, osglData, "only one <inputFilesToMove> element allowed");
		parserData->inputFilesToMovePresent = true;
;}
    break;

  case 416:

    {
	if (parserData->kounter > parserData->numberOfPathPairs)
		osolerror (NULL, osoption, parserData, osglData, "too few path pairs in <inputFilesToMove> element");
;}
    break;

  case 420:

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
;}
    break;

  case 421:

    {	if (parserData->outputFilesToMovePresent)
		osolerror( NULL, osoption, parserData, osglData, "only one <outputFilesToMove> element allowed");
		parserData->outputFilesToMovePresent = true;
;}
    break;

  case 427:

    {
	if (parserData->kounter > parserData->numberOfPathPairs)
		osolerror (NULL, osoption, parserData, osglData, "too few path pairs in <outputFilesToMake> element");
;}
    break;

  case 431:

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
;}
    break;

  case 432:

    {	if (parserData->outputDirectoriesToMovePresent)
		osolerror( NULL, osoption, parserData, osglData, "only one <outputDirectoriesToMove> element allowed");
		parserData->outputDirectoriesToMovePresent = true;
;}
    break;

  case 438:

    {
	if (parserData->kounter > parserData->numberOfPathPairs)
		osolerror (NULL, osoption, parserData, osglData, "too few path pairs in <outputDirectoriesToMake> element");
;}
    break;

  case 442:

    {
	if (osoption->setFilesToDelete(parserData->numberOf, parserData->paths) == false)
		osolerror (NULL, osoption, parserData, osglData, "set <filesToDelete> failed");
	delete[] parserData->paths;
	parserData->paths = NULL;
;}
    break;

  case 443:

    {	if (parserData->filesToDeletePresent)
		osolerror( NULL, osoption, parserData, osglData, "only one <filesToDelete> element allowed");
	parserData->filesToDeletePresent = true;
;}
    break;

  case 449:

    {
	if (parserData->kounter > parserData->numberOf)
		osolerror (NULL, osoption, parserData, osglData, "too few paths in <filesToDelete> element");
;}
    break;

  case 452:

    {
	if (parserData->kounter >= parserData->numberOf)
		osolerror (NULL, osoption, parserData, osglData, "too many paths in <filesToDelete> element");
	parserData->paths[parserData->kounter] = (yyvsp[(3) - (4)].sval);
	//free($3); 
	parserData->kounter++;
;}
    break;

  case 453:

    {
	if (osoption->setDirectoriesToDelete(parserData->numberOf, parserData->paths) == false)
		osolerror (NULL, osoption, parserData, osglData, "set <directoriesToDelete> failed");
	delete[] parserData->paths;
	parserData->paths = NULL;
;}
    break;

  case 454:

    {	if (parserData->directoriesToDeletePresent)
		osolerror( NULL, osoption, parserData, osglData, "only one <directoriesToDelete> element allowed");
	parserData->directoriesToDeletePresent = true;
;}
    break;

  case 460:

    {
	if (parserData->kounter > parserData->numberOf)
		osolerror (NULL, osoption, parserData, osglData, "too few paths in <directoriesToDelete> element");
;}
    break;

  case 463:

    {
	if (parserData->kounter >= parserData->numberOf)
		osolerror (NULL, osoption, parserData, osglData, "too many paths in <directoriesToDelete> element");
	parserData->paths[parserData->kounter] = (yyvsp[(3) - (4)].sval);
	//free($3); 
	parserData->kounter++;
;}
    break;

  case 464:

    {
	if (osoption->setProcessesToKill(parserData->numberOf, parserData->processesToKill) == false)
		osolerror (NULL, osoption, parserData, osglData, "set <processesToKill> failed");
	delete[] parserData->processesToKill;
	parserData->processesToKill = NULL;
;}
    break;

  case 465:

    {
	if (parserData->processesToKillPresent)
		osolerror( NULL, osoption, parserData, osglData, "only one <processesToKill> element allowed");
	parserData->processesToKillPresent = true;
;}
    break;

  case 471:

    {
	if (parserData->kounter > parserData->numberOf)
		osolerror (NULL, osoption, parserData, osglData, "too few process IDs in <processesToKill> element");
;}
    break;

  case 474:

    {
	if (parserData->kounter >= parserData->numberOf)
		osolerror (NULL, osoption, parserData, osglData, "too many process IDs in <processesToKill> element");
	parserData->processesToKill[parserData->kounter] = (yyvsp[(3) - (4)].sval);
	//free($3); 
	parserData->kounter++;
;}
    break;

  case 476:

    {	if (parserData->otherJobOptionsPresent)
		osolerror(NULL, NULL, parserData, osglData, "only one <job> <other> element allowed");
	parserData->otherJobOptionsPresent = true;
;}
    break;

  case 477:

    {
	if (parserData->tempInt < 0) osolerror(NULL, NULL, parserData, osglData, "number of other job options cannot be negative");
	parserData->numberOf = parserData->tempInt;
	parserData->kounter = 0;
;}
    break;

  case 478:

    {	if (parserData->numberOf > 0)
			osolerror(NULL, NULL, parserData, osglData, "expected at least one <other> element");
	;}
    break;

  case 479:

    {	if (parserData->kounter < parserData->numberOf - 1)
			osolerror(NULL, NULL, parserData, osglData, "fewer <other> elements than specified");
	;}
    break;

  case 486:

    {
	parserData->kounter++;
	if (osoption->setAnOtherJobOption(parserData->nameAttribute, parserData->valueAttribute, parserData->descriptionAttribute) == false)
		osolerror(NULL, NULL, parserData, osglData, "setOtherJobOption failed");
;}
    break;

  case 487:

    {	if (parserData->kounter >= parserData->numberOf)
		osolerror(NULL, NULL, parserData, osglData, "more <other> elements than specified");
	parserData->nameAttributePresent = false;
	parserData->valueAttributePresent = false;
	parserData->descriptionAttributePresent = false;
	parserData->nameAttribute = "";
	parserData->valueAttribute = "";
	parserData->descriptionAttribute = "";
;}
    break;

  case 488:

    {	if (!parserData->nameAttributePresent)
		osolerror (NULL, NULL, parserData, osglData, "<other> must have name attribute");
;}
    break;

  case 491:

    {
		if (parserData->nameAttribute.length() == 0)
			osolerror(NULL, NULL, parserData, osglData, "otherOption name cannot be empty");
	;}
    break;

  case 498:

    {
	osoption->optimization = new OptimizationOption();
	parserData->numberOfVariablesPresent = false;
	parserData->numberOfObjectivesPresent = false;
	parserData->numberOfConstraintsPresent = false;
;}
    break;

  case 502:

    {	
		parserData->numberOfVariables = parserData->tempInt; 
		if (osoption->setNumberOfVariables(parserData->tempInt) == false)
			osolerror(NULL, NULL, parserData, osglData, "setNumberOfVariables failed");
	;}
    break;

  case 503:

    {
		parserData->numberOfConstraints = parserData->tempInt; 
		if (osoption->setNumberOfConstraints(parserData->tempInt) == false)
			osolerror(NULL, NULL, parserData, osglData, "setNumberOfConstraints failed");
	;}
    break;

  case 504:

    {	
		parserData->numberOfObjectives = parserData->tempInt; 
		if (osoption->setNumberOfObjectives(parserData->tempInt) == false)
			osolerror(NULL, NULL, parserData, osglData, "setNumberOfObjectives failed");
	;}
    break;

  case 512:

    {
	parserData->numberOfOtherVariableOptions = 0;
	osoption->optimization->variables = new VariableOption();
;}
    break;

  case 513:

    {	
	if (osoption->setNumberOfOtherVariableOptions(parserData->numberOfOtherVariableOptions) == false)
		osolerror(NULL, NULL, parserData, osglData, "setNumberOfOtherVariableOptions failed");
	parserData->iOther = 0;
;}
    break;

  case 515:

    {	
	parserData->numberOfOtherVariableOptions = parserData->tempInt;
;}
    break;

  case 522:

    {
		if (osoption->setInitVarValues(parserData->numberOfVar, parserData->idxArray, parserData->valArray) == false)
			osolerror (NULL, osoption, parserData, osglData, "set <initialVariableValues> failed");
		delete[] parserData->idxArray;
		delete[] parserData->valArray;
		parserData->idxArray = NULL;
		parserData->valArray = NULL;
;}
    break;

  case 523:

    {
	parserData->numberOfVarAttributePresent = false;
;}
    break;

  case 524:

    {
	parserData->kounter = 0;
	parserData->idxArray = new    int[parserData->numberOfVar];
	parserData->valArray = new double[parserData->numberOfVar];
;}
    break;

  case 525:

    {
		if (parserData->numberOfVar > 0)
			osolerror(NULL, NULL, parserData, osglData, "expected at least one <var> element");
	;}
    break;

  case 526:

    {
		if (parserData->kounter > parserData->numberOfVar)
			osolerror (NULL, osoption, parserData, osglData, "too few initial values in <initialVariableValues> element");
	;}
    break;

  case 533:

    {
	parserData->kounter++;
;}
    break;

  case 534:

    {	
	if (parserData->kounter >= parserData->numberOfVar)
		osolerror(NULL, NULL, parserData, osglData, "more <var> elements than specified");
	parserData->idxAttributePresent = false;
	parserData->valueAttributePresent = false;
;}
    break;

  case 537:

    {
		if (parserData->idxAttribute < 0)
			osolerror (NULL, osoption, parserData, osglData, "variable index must be nonnegative");
		if (osoption->optimization->numberOfVariables >= 0)
		{
			if (parserData->idxAttribute >= osoption->optimization->numberOfVariables)
				osolerror (NULL, osoption, parserData, osglData, "variable index exceeds upper limit");
		};
		parserData->idxArray[parserData->kounter] = parserData->idxAttribute;
	;}
    break;

  case 538:

    {
		if (parserData->valueAttribute == "")
			osolerror (NULL, osoption, parserData, osglData, "expected an integer or floating point value");
		parserData->valArray[parserData->kounter] = os_strtod((parserData->valueAttribute).c_str(), NULL);
	;}
    break;

  case 542:

    {
	if (osoption->setInitVarValuesString(parserData->numberOfVar, parserData->idxArray, parserData->valueString) == false)
		osolerror (NULL, osoption, parserData, osglData, "set <initialVariableValuesString> failed");
	delete[] parserData->idxArray;
	delete[] parserData->valueString;
	parserData->idxArray = NULL;
	parserData->valueString = NULL;
;}
    break;

  case 543:

    {
	parserData->numberOfVarAttributePresent = false;
;}
    break;

  case 544:

    {
	parserData->kounter = 0;
	parserData->idxArray = new int[parserData->numberOfVar];
	parserData->valueString = new std::string[parserData->numberOfVar];
;}
    break;

  case 545:

    {
		if (parserData->numberOfVar > 0)
			osolerror(NULL, NULL, parserData, osglData, "expected at least one <var> element");
	;}
    break;

  case 546:

    {
		if (parserData->kounter != parserData->numberOfVar)
			osolerror(NULL, NULL, parserData, osglData, "fewer <var> elements than specified");
	;}
    break;

  case 553:

    {
	parserData->kounter++;
;}
    break;

  case 554:

    {	
	if (parserData->kounter >= parserData->numberOfVar)
		osolerror(NULL, NULL, parserData, osglData, "more <var> elements than specified");
	parserData->idxAttributePresent = false;
	parserData->valueAttributePresent = false;
	parserData->valueAttribute = "48r 87e WY EUV e7 df"; //random string...
;}
    break;

  case 555:

    {
	parserData->idxArray[parserData->kounter] = parserData->idxAttribute;
	parserData->valueString[parserData->kounter] = parserData->valueAttribute;
;}
    break;

  case 558:

    {
		if (parserData->idxAttribute < 0)
			osolerror (NULL, osoption, parserData, osglData, "variable index must be nonnegative");
		if (osoption->optimization->numberOfVariables >= 0)
		{
			if (parserData->idxAttribute >= osoption->optimization->numberOfVariables)
				osolerror (NULL, osoption, parserData, osglData, "variable index exceeds upper limit");
		};
	;}
    break;

  case 564:

    {
	osoption->optimization->variables->initialBasisStatus = new BasisStatus();
;}
    break;

  case 571:

    {
	if (osoption->setInitBasisStatus(ENUM_PROBLEM_COMPONENT_variables, ENUM_BASIS_STATUS_basic, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
		osolerror(NULL, NULL, parserData, osglData, "set variables basic failed");	
	delete[] osglData->osglIntArray;
	osglData->osglIntArray = NULL;
;}
    break;

  case 572:

    {
	osglData->osglNumberOfEl = 0;
	osglData->osglNumberOfElPresent= false;
;}
    break;

  case 573:

    {
	osglData->osglCounter = 0; 
	osglData->osglNumberOfEl = parserData->numberOf;
	osglData->osglIntArray = new int[parserData->numberOf];
;}
    break;

  case 580:

    {
	if (osoption->setInitBasisStatus(ENUM_PROBLEM_COMPONENT_variables, ENUM_BASIS_STATUS_atLower, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
		osolerror(NULL, NULL, parserData, osglData, "set variables atLower failed");	
	delete[] osglData->osglIntArray;
	osglData->osglIntArray = NULL;
;}
    break;

  case 581:

    {
	osglData->osglNumberOfEl = 0;
	osglData->osglNumberOfElPresent= false;
;}
    break;

  case 582:

    {
	osglData->osglCounter = 0; 
	osglData->osglNumberOfEl = parserData->numberOf;
	osglData->osglIntArray = new int[parserData->numberOf];
;}
    break;

  case 589:

    {
	if (osoption->setInitBasisStatus(ENUM_PROBLEM_COMPONENT_variables, ENUM_BASIS_STATUS_atUpper, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
		osolerror(NULL, NULL, parserData, osglData, "set variables atUpper failed");	
	delete[] osglData->osglIntArray;
	osglData->osglIntArray = NULL;
;}
    break;

  case 590:

    {
	osglData->osglNumberOfEl = 0;
	osglData->osglNumberOfElPresent= false;
;}
    break;

  case 591:

    {
	osglData->osglCounter = 0; 
	osglData->osglNumberOfEl = parserData->numberOf;
	osglData->osglIntArray = new int[parserData->numberOf];
;}
    break;

  case 598:

    {
	if (osoption->setInitBasisStatus(ENUM_PROBLEM_COMPONENT_variables, ENUM_BASIS_STATUS_isFree, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
		osolerror(NULL, NULL, parserData, osglData, "set variables isFree failed");	
	delete[] osglData->osglIntArray;
	osglData->osglIntArray = NULL;
;}
    break;

  case 599:

    {
	osglData->osglNumberOfEl = 0;
	osglData->osglNumberOfElPresent= false;
;}
    break;

  case 600:

    {
	osglData->osglCounter = 0; 
	osglData->osglNumberOfEl = parserData->numberOf;
	osglData->osglIntArray = new int[parserData->numberOf];
;}
    break;

  case 607:

    {
	if (osoption->setInitBasisStatus(ENUM_PROBLEM_COMPONENT_variables, ENUM_BASIS_STATUS_superbasic, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
		osolerror(NULL, NULL, parserData, osglData, "set variables superbasic failed");	
	delete[] osglData->osglIntArray;
	osglData->osglIntArray = NULL;
;}
    break;

  case 608:

    {
	osglData->osglNumberOfEl = 0;
	osglData->osglNumberOfElPresent= false;
;}
    break;

  case 609:

    {
	osglData->osglCounter = 0; 
	osglData->osglNumberOfEl = parserData->numberOf;
	osglData->osglIntArray = new int[parserData->numberOf];
;}
    break;

  case 616:

    {
	if (osoption->setInitBasisStatus(ENUM_PROBLEM_COMPONENT_variables, ENUM_BASIS_STATUS_unknown, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
		osolerror(NULL, NULL, parserData, osglData, "set variables unknown failed");	
	delete[] osglData->osglIntArray;
	osglData->osglIntArray = NULL;
;}
    break;

  case 617:

    {
	osglData->osglNumberOfEl = 0;
	osglData->osglNumberOfElPresent= false;
;}
    break;

  case 618:

    {
	osglData->osglCounter = 0; 
	osglData->osglNumberOfEl = parserData->numberOf;
	osglData->osglIntArray = new int[parserData->numberOf];
;}
    break;

  case 625:

    {
	if (osoption->setIntegerVariableBranchingWeights(parserData->numberOfVar, parserData->idxArray, parserData->valArray) == false)
		osolerror (NULL, osoption, parserData, osglData, "set <initialVariableValues> failed");
	delete[] parserData->idxArray;
	delete[] parserData->valArray;
	parserData->idxArray = NULL;
	parserData->valArray = NULL;
;}
    break;

  case 626:

    {
	parserData->numberOfVarAttributePresent = false;
;}
    break;

  case 627:

    {
	parserData->kounter = 0;
	parserData->idxArray = new    int[parserData->numberOfVar];
	parserData->valArray = new double[parserData->numberOfVar];
;}
    break;

  case 628:

    {
		if (parserData->numberOfVar > 0)
			osolerror(NULL, NULL, parserData, osglData, "expected at least one <var> element");
	;}
    break;

  case 629:

    {
		if (parserData->kounter != parserData->numberOfVar)
			osolerror(NULL, NULL, parserData, osglData, "fewer <var> elements than specified");
	;}
    break;

  case 636:

    {
	parserData->kounter++;
;}
    break;

  case 637:

    {	
	if (parserData->kounter >= parserData->numberOfVar)
		osolerror(NULL, NULL, parserData, osglData, "more <var> elements than specified");
	parserData->idxAttributePresent = false;
	parserData->valueAttributePresent = false;
	parserData->valueAttribute = "1.0";
;}
    break;

  case 638:

    {
	parserData->idxArray[parserData->kounter] = parserData->idxAttribute;
	parserData->valArray[parserData->kounter] = os_strtod((parserData->valueAttribute).c_str(), NULL);
;}
    break;

  case 641:

    {
		if (parserData->idxAttribute < 0)
			osolerror (NULL, osoption, parserData, osglData, "variable index must be nonnegative");
		if (osoption->optimization->numberOfVariables >= 0)
		{
			if (parserData->idxAttribute >= osoption->optimization->numberOfVariables)
				osolerror (NULL, osoption, parserData, osglData, "variable index exceeds upper limit");
		};
	;}
    break;

  case 642:

    {
		if (parserData->valueAttribute == "")
			osolerror (NULL, osoption, parserData, osglData, "expected an integer or floating point value");
	;}
    break;

  case 647:

    {
	parserData->sosIdxAttributePresent = false;	
	parserData->currentSOS = 0;
;}
    break;

  case 648:

    {
	if ((yyvsp[(3) - (4)].ival) < 0)
		osolerror (NULL, osoption, parserData, osglData, "number of <sos> elements must be nonnegative");
	parserData->numberOfSOS = (yyvsp[(3) - (4)].ival);
;}
    break;

  case 649:

    {	if (parserData->numberOfSOS > 0)
			osolerror(NULL, NULL, parserData, osglData, "expected at least one <sos> element");
	;}
    break;

  case 650:

    {	if (parserData->currentSOS != parserData->numberOfSOS)
			osolerror(NULL, NULL, parserData, osglData, "fewer <sos> elements than specified");
	;}
    break;

  case 656:

    {
	if (!osoption->setAnotherSOSVariableBranchingWeight(parserData->sosIdx, 
				parserData->numberOfVar, parserData->groupWeight,
				parserData->idxArray,	 parserData->valArray) )
		osolerror (NULL, osoption, parserData, osglData, "error processing SOS branching weights");
	delete[] parserData->idxArray;
	delete[] parserData->valArray;
	parserData->idxArray = NULL;
	parserData->valArray = NULL;
	parserData->currentSOS++;
;}
    break;

  case 657:

    {	if (parserData->currentSOS >= parserData->numberOfSOS)
		osolerror(NULL, osoption, parserData, osglData, "too many SOS branching weights");
	parserData->sosIdxAttributePresent = false;
	parserData->groupWeightAttributePresent = false;
	parserData->numberOfVarAttributePresent = false;
	parserData->groupWeight = 1.0;
	parserData->numberOfSOSVar = 0;
;}
    break;

  case 658:

    {
	if (!parserData->sosIdxAttributePresent)
		osolerror (NULL, osoption, parserData, osglData, "SOS index required");
	if (!parserData->numberOfVarAttributePresent)
		osolerror (NULL, osoption, parserData, osglData, "numberOfVar required");
;}
    break;

  case 662:

    {
		parserData->kounter = 0;
		parserData->idxArray = new    int[parserData->numberOfVar];
		parserData->valArray = new double[parserData->numberOfVar];
		parserData->numberOfVarAttributePresent = true;
	;}
    break;

  case 671:

    { 	 
		parserData->iOther++;
	;}
    break;

  case 672:

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
;}
    break;

  case 673:

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
	;}
    break;

  case 676:

    {
		parserData->kounter = 0;
	;}
    break;

  case 677:

    {
		parserData->kounter = 0;
	;}
    break;

  case 693:

    { 	
	if (!osoption->setOtherVariableOptionVar(
				parserData->iOther, 
				parserData->kounter,
				parserData->idxAttribute, 
				parserData->valueAttribute,
				parserData->lbValueAttribute, 
				parserData->ubValueAttribute) )
		osolerror(NULL, NULL, parserData, osglData, "set other variable option <var> element failed");
	parserData->kounter++;
;}
    break;

  case 694:

    {
	if (parserData->kounter >= parserData->numberOfVar)
		osolerror(NULL, NULL, parserData, osglData, "more <var> elements than specified");
	parserData->idxAttributePresent = false;	
	parserData->valueAttributePresent = false;	
	parserData->valueAttribute = "";
	parserData->lbValueAttributePresent = false;	
	parserData->lbValueAttribute = "";
	parserData->ubValueAttributePresent = false;	
	parserData->ubValueAttribute = "";
;}
    break;

  case 698:

    {
		if (parserData->idxAttribute < 0)
			osolerror (NULL, osoption, parserData, osglData, "variable index must be nonnegative");
		if (osoption->optimization->numberOfVariables >= 0)
		{
			if (parserData->idxAttribute >= osoption->optimization->numberOfVariables)
				osolerror (NULL, osoption, parserData, osglData, "variable index exceeds upper limit");
		};
	;}
    break;

  case 707:

    {
	parserData->numberOfOtherObjectiveOptions = 0; 
	osoption->optimization->objectives = new ObjectiveOption();
;}
    break;

  case 708:

    {	
	if (osoption->setNumberOfOtherObjectiveOptions(parserData->numberOfOtherObjectiveOptions) == false)
		osolerror(NULL, NULL, parserData, osglData, "setNumberOfOtherVariableOptions failed");
	parserData->iOther = 0;
;}
    break;

  case 710:

    {	
	parserData->numberOfOtherObjectiveOptions = parserData->tempInt;
;}
    break;

  case 717:

    {
	if (osoption->setInitObjValues(parserData->numberOfObj, parserData->idxArray, parserData->valArray) == false)
		osolerror (NULL, osoption, parserData, osglData, "set <initialObjectiveValues> failed");
	delete[] parserData->idxArray;
	delete[] parserData->valArray;
	parserData->idxArray = NULL;
	parserData->valArray = NULL;
;}
    break;

  case 718:

    {
	parserData->numberOfObjAttributePresent = false;
;}
    break;

  case 719:

    {
	parserData->kounter = 0;
	parserData->idxArray = new    int[parserData->numberOfObj];
	parserData->valArray = new double[parserData->numberOfObj];
;}
    break;

  case 720:

    {	
		if (parserData->numberOfObj > 0)
			osolerror(NULL, NULL, parserData, osglData, "expected at least one <obj> element");
	;}
    break;

  case 721:

    {
		if (parserData->kounter != parserData->numberOfObj)
			osolerror(NULL, NULL, parserData, osglData, "fewer <obj> elements than specified");
	;}
    break;

  case 728:

    {
	parserData->kounter++;
;}
    break;

  case 729:

    {	
	if (parserData->kounter >= parserData->numberOfObj)
		osolerror(NULL, NULL, parserData, osglData, "more <obj> elements than specified");
	parserData->idxAttributePresent = false;
	parserData->valueAttributePresent = false;
	parserData->idxAttribute = -1;
;}
    break;

  case 730:

    {	
	parserData->idxArray[parserData->kounter] = parserData->idxAttribute;
;}
    break;

  case 733:

    {
		if (parserData->idxAttribute >= 0)
			osolerror (NULL, osoption, parserData, osglData, "objective index must be negative");
		if (osoption->optimization->numberOfObjectives >= 0)
		{
			if (parserData->idxAttribute < -osoption->optimization->numberOfObjectives)
				osolerror (NULL, osoption, parserData, osglData, "objective index exceeds limit");
		};
	;}
    break;

  case 734:

    {
		if (parserData->valueAttribute == "")
			osolerror (NULL, osoption, parserData, osglData, "expected an integer or floating point value");
		parserData->valArray[parserData->kounter] = os_strtod((parserData->valueAttribute).c_str(), NULL);
	;}
    break;

  case 738:

    {
	if (osoption->setInitObjBounds(parserData->numberOfObj, parserData->idxArray, parserData->lbValArray, parserData->ubValArray) == false)
		osolerror (NULL, osoption, parserData, osglData, "set <initialObjectiveBounds> failed");
	delete[] parserData->idxArray;
	delete[] parserData->lbValArray;
	delete[] parserData->ubValArray;
	parserData->idxArray = NULL;
	parserData->lbValArray = NULL;
	parserData->ubValArray = NULL;
;}
    break;

  case 739:

    {
	parserData->numberOfObjAttributePresent = false;
;}
    break;

  case 740:

    {
	parserData->kounter = 0;
	parserData->idxArray   = new    int[parserData->numberOfObj];
	parserData->lbValArray = new double[parserData->numberOfObj];
	parserData->ubValArray = new double[parserData->numberOfObj];
;}
    break;

  case 741:

    {
		if (parserData->numberOfObj > 0)
			osolerror(NULL, NULL, parserData, osglData, "expected at least one <obj> element");
	;}
    break;

  case 742:

    {
		if (parserData->kounter != parserData->numberOfObj)
			osolerror(NULL, NULL, parserData, osglData, "fewer <obj> elements than specified");
	;}
    break;

  case 749:

    {
	parserData->kounter++;
;}
    break;

  case 750:

    {	
	if (parserData->kounter >= parserData->numberOfObj)
		osolerror(NULL, NULL, parserData, osglData, "more <obj> elements than specified");
	parserData->idxAttributePresent = false;
	parserData->lbValueAttributePresent = false;
	parserData->ubValueAttributePresent = false;
	parserData->idxAttribute = -1;
	parserData->lbValueAttribute = "-INF";
	parserData->ubValueAttribute = "INF";
;}
    break;

  case 751:

    {	
	parserData->idxArray[parserData->kounter] = parserData->idxAttribute;
	parserData->lbValArray[parserData->kounter] = os_strtod((parserData->lbValueAttribute).c_str(), NULL);
	parserData->ubValArray[parserData->kounter] = os_strtod((parserData->ubValueAttribute).c_str(), NULL);
;}
    break;

  case 754:

    {
		if (parserData->idxAttribute >= 0)
			osolerror (NULL, osoption, parserData, osglData, "objective index must be nonnegative");
		if (osoption->optimization->numberOfObjectives >= 0)
		{
			if (parserData->idxAttribute < -osoption->optimization->numberOfVariables)
				osolerror (NULL, osoption, parserData, osglData, "objective index exceeds limit");
		};
	;}
    break;

  case 755:

    {
		if (parserData->lbValueAttribute == "")
			osolerror (NULL, osoption, parserData, osglData, "expected an integer or floating point value");
	;}
    break;

  case 756:

    {
		if (parserData->ubValueAttribute == "")
			osolerror (NULL, osoption, parserData, osglData, "expected an integer or floating point value");
	;}
    break;

  case 761:

    {
	osoption->optimization->objectives->initialBasisStatus = new BasisStatus();
;}
    break;

  case 768:

    {
	if (osoption->setInitBasisStatus(ENUM_PROBLEM_COMPONENT_objectives, ENUM_BASIS_STATUS_basic, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
		osolerror(NULL, NULL, parserData, osglData, "set objectives basic failed");	
	delete[] osglData->osglIntArray;
	osglData->osglIntArray = NULL;
;}
    break;

  case 769:

    {
	osglData->osglNumberOfEl = 0;
	osglData->osglNumberOfElPresent= false;
;}
    break;

  case 770:

    {
	osglData->osglCounter = 0; 
	osglData->osglNumberOfEl = parserData->numberOf;
	osglData->osglIntArray = new int[parserData->numberOf];
;}
    break;

  case 777:

    {
	if (osoption->setInitBasisStatus(ENUM_PROBLEM_COMPONENT_objectives, ENUM_BASIS_STATUS_atLower, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
		osolerror(NULL, NULL, parserData, osglData, "set objectives atLower failed");	
	delete[] osglData->osglIntArray;
	osglData->osglIntArray = NULL;
;}
    break;

  case 778:

    {
	osglData->osglNumberOfEl = 0;
	osglData->osglNumberOfElPresent= false;
;}
    break;

  case 779:

    {
	osglData->osglCounter = 0; 
	osglData->osglNumberOfEl = parserData->numberOf;
	osglData->osglIntArray = new int[parserData->numberOf];
;}
    break;

  case 786:

    {
	if (osoption->setInitBasisStatus(ENUM_PROBLEM_COMPONENT_objectives, ENUM_BASIS_STATUS_atUpper, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
		osolerror(NULL, NULL, parserData, osglData, "set objectives atUpper failed");	
	delete[] osglData->osglIntArray;
	osglData->osglIntArray = NULL;
;}
    break;

  case 787:

    {
	osglData->osglNumberOfEl = 0;
	osglData->osglNumberOfElPresent= false;
;}
    break;

  case 788:

    {
	osglData->osglCounter = 0; 
	osglData->osglNumberOfEl = parserData->numberOf;
	osglData->osglIntArray = new int[parserData->numberOf];
;}
    break;

  case 795:

    {
	if (osoption->setInitBasisStatus(ENUM_PROBLEM_COMPONENT_objectives, ENUM_BASIS_STATUS_isFree, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
		osolerror(NULL, NULL, parserData, osglData, "set objectives isFree failed");	
	delete[] osglData->osglIntArray;
	osglData->osglIntArray = NULL;
;}
    break;

  case 796:

    {
	osglData->osglNumberOfEl = 0;
	osglData->osglNumberOfElPresent= false;
;}
    break;

  case 797:

    {
	osglData->osglCounter = 0; 
	osglData->osglNumberOfEl = parserData->numberOf;
	osglData->osglIntArray = new int[parserData->numberOf];
;}
    break;

  case 804:

    {
	if (osoption->setInitBasisStatus(ENUM_PROBLEM_COMPONENT_objectives, ENUM_BASIS_STATUS_superbasic, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
		osolerror(NULL, NULL, parserData, osglData, "set objectives superbasic failed");	
	delete[] osglData->osglIntArray;
	osglData->osglIntArray = NULL;
;}
    break;

  case 805:

    {
	osglData->osglNumberOfEl = 0;
	osglData->osglNumberOfElPresent= false;
;}
    break;

  case 806:

    {
	osglData->osglCounter = 0; 
	osglData->osglNumberOfEl = parserData->numberOf;
	osglData->osglIntArray = new int[parserData->numberOf];
;}
    break;

  case 813:

    {
	if (osoption->setInitBasisStatus(ENUM_PROBLEM_COMPONENT_objectives, ENUM_BASIS_STATUS_unknown, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
		osolerror(NULL, NULL, parserData, osglData, "set objectives unknown failed");	
	delete[] osglData->osglIntArray;
	osglData->osglIntArray = NULL;
;}
    break;

  case 814:

    {
	osglData->osglNumberOfEl = 0;
	osglData->osglNumberOfElPresent= false;
;}
    break;

  case 815:

    {
	osglData->osglCounter = 0; 
	osglData->osglNumberOfEl = parserData->numberOf;
	osglData->osglIntArray = new int[parserData->numberOf];
;}
    break;

  case 823:

    { 	 
		parserData->iOther++;  
	;}
    break;

  case 824:

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
;}
    break;

  case 825:

    {	if(!parserData->nameAttributePresent) 
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
	;}
    break;

  case 828:

    {
		parserData->kounter = 0;
	;}
    break;

  case 829:

    {
		parserData->kounter = 0;
	;}
    break;

  case 845:

    {  
	if (!osoption->setOtherObjectiveOptionObj(
				parserData->iOther, 
				parserData->kounter,
				parserData->idxAttribute, 
				parserData->valueAttribute,
				parserData->lbValueAttribute, 
				parserData->ubValueAttribute) )
		osolerror(NULL, NULL, parserData, osglData, "set other objective option <obj> element failed");
	parserData->kounter++;
;}
    break;

  case 846:

    {
	if (parserData->kounter >= parserData->numberOfObj)
		osolerror(NULL, NULL, parserData, osglData, "more <obj> elements than specified");
	parserData->idxAttributePresent = false;	
	parserData->idxAttribute = -1;
	parserData->valueAttributePresent = false;	
	parserData->valueAttribute = "";
	parserData->lbValueAttributePresent = false;	
	parserData->lbValueAttribute = "";
	parserData->ubValueAttributePresent = false;	
	parserData->ubValueAttribute = "";
;}
    break;

  case 847:

    {	
	parserData->idxArray[parserData->kounter] = parserData->idxAttribute;
	parserData->valueString[parserData->kounter] = parserData->valueAttribute;
	parserData->lbValueString[parserData->kounter] = parserData->lbValueAttribute;
	parserData->ubValueString[parserData->kounter] = parserData->ubValueAttribute;
;}
    break;

  case 850:

    {
		if (parserData->idxAttribute >= 0)
			osolerror (NULL, osoption, parserData, osglData, "objective index must be negative");
		if (osoption->optimization->numberOfObjectives >= 0)
		{
			if (parserData->idxAttribute < -osoption->optimization->numberOfObjectives)
				osolerror (NULL, osoption, parserData, osglData, "objective index exceeds limit");
		};
	;}
    break;

  case 859:

    {
	parserData->numberOfOtherConstraintOptions = 0; 
	osoption->optimization->constraints = new ConstraintOption();
;}
    break;

  case 860:

    {	
	if (osoption->setNumberOfOtherConstraintOptions(parserData->numberOfOtherConstraintOptions) == false)
		osolerror(NULL, NULL, parserData, osglData, "setNumberOfOtherConstraintOptions failed");
	parserData->iOther = 0;
;}
    break;

  case 862:

    {	
	parserData->numberOfOtherConstraintOptions = parserData->tempInt;
;}
    break;

  case 869:

    {
	if (osoption->setInitConValues(parserData->numberOfCon, parserData->idxArray, parserData->valArray) == false)
		osolerror (NULL, osoption, parserData, osglData, "set <initialConstraintValues> failed");
	delete[] parserData->idxArray;
	delete[] parserData->valArray;
	parserData->idxArray = NULL;
	parserData->valArray = NULL;
;}
    break;

  case 870:

    {
	parserData->numberOfConAttributePresent = false;
;}
    break;

  case 871:

    {
	parserData->kounter = 0;
	parserData->idxArray = new    int[parserData->numberOfCon];
	parserData->valArray = new double[parserData->numberOfCon];
;}
    break;

  case 872:

    {
		if (parserData->numberOfCon > 0)
			osolerror(NULL, NULL, parserData, osglData, "expected at least one <con element");
	;}
    break;

  case 873:

    {
		if (parserData->kounter > parserData->numberOfCon)
			osolerror(NULL, NULL, parserData, osglData, "fewer <con> elements than specified");
	;}
    break;

  case 880:

    {
	parserData->kounter++;
;}
    break;

  case 881:

    {	
	if (parserData->kounter >= parserData->numberOfCon)
		osolerror(NULL, NULL, parserData, osglData, "more <con> elements than specified");
	parserData->idxAttributePresent = false;
	parserData->valueAttributePresent = false;
;}
    break;

  case 884:

    {
		if (parserData->idxAttribute < 0)
			osolerror (NULL, osoption, parserData, osglData, "constraint index must be nonnegative");
		if (osoption->optimization->numberOfConstraints >= 0)
		{
			if (parserData->idxAttribute >= osoption->optimization->numberOfConstraints)
				osolerror (NULL, osoption, parserData, osglData, "constraint index exceeds upper limit");
		};
		parserData->idxArray[parserData->kounter] = parserData->idxAttribute;
	;}
    break;

  case 885:

    {
		if (parserData->valueAttribute == "")
			osolerror (NULL, osoption, parserData, osglData, "expected an integer or floating point value");
		parserData->valArray[parserData->kounter] = os_strtod((parserData->valueAttribute).c_str(), NULL);
	;}
    break;

  case 889:

    {
	if (osoption->setInitDualValues(parserData->numberOfCon, parserData->idxArray, parserData->lbValArray, parserData->ubValArray) == false)
		osolerror (NULL, osoption, parserData, osglData, "set <initialConstraintValues> failed");
	delete[] parserData->idxArray;
	delete[] parserData->lbValArray;
	delete[] parserData->ubValArray;
	parserData->idxArray = NULL;
	parserData->lbValArray = NULL;
	parserData->ubValArray = NULL;
;}
    break;

  case 890:

    {
	parserData->numberOfConAttributePresent = false;
;}
    break;

  case 891:

    {
	parserData->kounter = 0;
	parserData->idxArray   = new    int[parserData->numberOfCon];
	parserData->lbValArray = new double[parserData->numberOfCon];
	parserData->ubValArray = new double[parserData->numberOfCon];
;}
    break;

  case 892:

    {
		if (parserData->numberOfCon > 0)
			osolerror(NULL, NULL, parserData, osglData, "expected at least one <con> element");
	;}
    break;

  case 893:

    {
		if (parserData->kounter != parserData->numberOfCon)
			osolerror(NULL, NULL, parserData, osglData, "fewer <con> elements than specified");
	;}
    break;

  case 900:

    {	
	parserData->kounter++;
;}
    break;

  case 901:

    {	
	if (parserData->kounter >= parserData->numberOfCon)
		osolerror(NULL, NULL, parserData, osglData, "more <con> elements than specified");
	parserData->idxAttributePresent = false;
	parserData->lbValueAttributePresent = false;
	parserData->ubValueAttributePresent = false;
	parserData->lbDualValue = 0;
	parserData->ubDualValue = 0;
;}
    break;

  case 902:

    {
	parserData->lbValArray[parserData->kounter] = parserData->lbDualValue;
	parserData->ubValArray[parserData->kounter] = parserData->ubDualValue;
;}
    break;

  case 905:

    {
		if (parserData->idxAttribute < 0)
			osolerror (NULL, osoption, parserData, osglData, "constraint index must be nonnegative");
		if (osoption->optimization->numberOfConstraints >= 0)
		{
			if (parserData->idxAttribute >= osoption->optimization->numberOfConstraints)
				osolerror (NULL, osoption, parserData, osglData, "constraint index exceeds upper limit");
		};
		parserData->idxArray[parserData->kounter] = parserData->idxAttribute;
	;}
    break;

  case 912:

    {
	osoption->optimization->constraints->initialBasisStatus = new BasisStatus();
;}
    break;

  case 919:

    {
	if (osoption->setInitBasisStatus(ENUM_PROBLEM_COMPONENT_constraints, ENUM_BASIS_STATUS_basic, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
		osolerror(NULL, NULL, parserData, osglData, "set slacks basic failed");	
	delete[] osglData->osglIntArray;
	osglData->osglIntArray = NULL;
;}
    break;

  case 920:

    {
	osglData->osglNumberOfEl = 0;
	osglData->osglNumberOfElPresent= false;
;}
    break;

  case 921:

    {
	osglData->osglCounter = 0; 
	osglData->osglNumberOfEl = parserData->numberOf;
	osglData->osglIntArray = new int[parserData->numberOf];
;}
    break;

  case 928:

    {
	if (osoption->setInitBasisStatus(ENUM_PROBLEM_COMPONENT_constraints, ENUM_BASIS_STATUS_atLower, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
		osolerror(NULL, NULL, parserData, osglData, "set slacks atLower failed");	
	delete[] osglData->osglIntArray;
	osglData->osglIntArray = NULL;
;}
    break;

  case 929:

    {
	osglData->osglNumberOfEl = 0;
	osglData->osglNumberOfElPresent= false;
;}
    break;

  case 930:

    {
	osglData->osglCounter = 0; 
	osglData->osglNumberOfEl = parserData->numberOf;
	osglData->osglIntArray = new int[parserData->numberOf];
;}
    break;

  case 937:

    {
	if (osoption->setInitBasisStatus(ENUM_PROBLEM_COMPONENT_constraints, ENUM_BASIS_STATUS_atUpper, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
		osolerror(NULL, NULL, parserData, osglData, "set slacks atUpper failed");	
	delete[] osglData->osglIntArray;
	osglData->osglIntArray = NULL;
;}
    break;

  case 938:

    {
	osglData->osglNumberOfEl = 0;
	osglData->osglNumberOfElPresent= false;
;}
    break;

  case 939:

    {
	osglData->osglCounter = 0; 
	osglData->osglNumberOfEl = parserData->numberOf;
	osglData->osglIntArray = new int[parserData->numberOf];
;}
    break;

  case 946:

    {
	if (osoption->setInitBasisStatus(ENUM_PROBLEM_COMPONENT_constraints, ENUM_BASIS_STATUS_isFree, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
		osolerror(NULL, NULL, parserData, osglData, "set slacks isFree failed");	
	delete[] osglData->osglIntArray;
	osglData->osglIntArray = NULL;
;}
    break;

  case 947:

    {
	osglData->osglNumberOfEl = 0;
	osglData->osglNumberOfElPresent= false;
;}
    break;

  case 948:

    {
	osglData->osglCounter = 0; 
	osglData->osglNumberOfEl = parserData->numberOf;
	osglData->osglIntArray = new int[parserData->numberOf];
;}
    break;

  case 955:

    {
	if (osoption->setInitBasisStatus(ENUM_PROBLEM_COMPONENT_constraints, ENUM_BASIS_STATUS_superbasic, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
		osolerror(NULL, NULL, parserData, osglData, "set variables superbasic failed");	
	delete[] osglData->osglIntArray;
	osglData->osglIntArray = NULL;
;}
    break;

  case 956:

    {
	osglData->osglNumberOfEl = 0;
	osglData->osglNumberOfElPresent= false;
;}
    break;

  case 957:

    {
	osglData->osglCounter = 0; 
	osglData->osglNumberOfEl = parserData->numberOf;
	osglData->osglIntArray = new int[parserData->numberOf];
;}
    break;

  case 964:

    {
	if (osoption->setInitBasisStatus(ENUM_PROBLEM_COMPONENT_constraints, ENUM_BASIS_STATUS_unknown, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
		osolerror(NULL, NULL, parserData, osglData, "set slacks unknown failed");	
	delete[] osglData->osglIntArray;
	osglData->osglIntArray = NULL;
;}
    break;

  case 965:

    {
	osglData->osglNumberOfEl = 0;
	osglData->osglNumberOfElPresent= false;
;}
    break;

  case 966:

    {
	osglData->osglCounter = 0; 
	osglData->osglNumberOfEl = parserData->numberOf;
	osglData->osglIntArray = new int[parserData->numberOf];
;}
    break;

  case 974:

    { 	 
		parserData->iOther++;  
	;}
    break;

  case 975:

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
;}
    break;

  case 976:

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
	;}
    break;

  case 979:

    {
		parserData->kounter = 0;
	;}
    break;

  case 980:

    {
		parserData->kounter = 0;
	;}
    break;

  case 996:

    { 	
	if (!osoption->setOtherConstraintOptionCon(
				parserData->iOther, 
				parserData->kounter,
				parserData->idxAttribute, 
				parserData->valueAttribute,
				parserData->lbValueAttribute, 
				parserData->ubValueAttribute) )
		osolerror(NULL, NULL, parserData, osglData, "set other constraint option <con> element failed");
	parserData->kounter++;
;}
    break;

  case 997:

    {
	if (parserData->kounter >= parserData->numberOfCon)
		osolerror(NULL, NULL, parserData, osglData, "more <con> elements than specified");
	parserData->idxAttributePresent = false;	
	parserData->valueAttributePresent = false;	
	parserData->valueAttribute = "";
	parserData->lbValueAttributePresent = false;	
	parserData->lbValueAttribute = "";
	parserData->ubValueAttributePresent = false;	
	parserData->ubValueAttribute = "";
;}
    break;

  case 1001:

    {
		if (parserData->idxAttribute < 0)
			osolerror (NULL, osoption, parserData, osglData, "constraint index must be nonnegative");
		if (osoption->optimization->numberOfConstraints >= 0)
		{
			if (parserData->idxAttribute >= osoption->optimization->numberOfConstraints)
				osolerror (NULL, osoption, parserData, osglData, "constraint index exceeds upper limit");
		};
	;}
    break;

  case 1011:

    {
	if (!osoption->setNumberOfSolverOptions(parserData->numberOfSolverOptions) )
		osolerror( NULL, osoption, parserData, osglData, "setNumberOfSolverOptions failed");
	parserData->iOption = 0;
;}
    break;

  case 1012:

    {
		if (parserData->numberOfSolverOptions > 0)
			osolerror(NULL, NULL, parserData, osglData, "expected at least one <solverOption> element");
	;}
    break;

  case 1013:

    {
		if (parserData->iOption != parserData->numberOfSolverOptions)
			osolerror(NULL, NULL, parserData, osglData, "fewer <solverOption> elements than specified");
	;}
    break;

  case 1018:

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
;}
    break;

  case 1019:

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
;}
    break;

  case 1020:

    {
	if (!parserData->nameAttributePresent)
		osolerror (NULL, osoption, parserData, osglData, "name attribute must be present");
;}
    break;

  case 1029:

    {
			parserData->itemList = new std::string[parserData->numberOfItems];
    ;}
    break;

  case 1030:

    {	if (parserData->numberOfItems > 0)
			osolerror(NULL, NULL, parserData, osglData, "expected at least one <item> element");
	;}
    break;

  case 1031:

    {	if (parserData->kounter != parserData->numberOfItems)
			osolerror(NULL, NULL, parserData, osglData, "fewer <item> elements than specified");
	;}
    break;

  case 1038:

    {	
	parserData->itemList[parserData->kounter] = parserData->itemContent;
	parserData->kounter++;
;}
    break;

  case 1039:

    {
		if (parserData->kounter >= parserData->numberOfItems)
			osolerror(NULL, NULL, parserData, osglData, "more <item> elements than specified");
		parserData->itemContent = "";			
	;}
    break;

  case 1044:

    {
	if (parserData->kounter >= parserData->numberOfItems)
		osolerror(NULL, NULL, parserData, osglData, "more <item> elements than specified");
	parserData->itemContent = (yyvsp[(1) - (1)].sval); 
;}
    break;

  case 1045:

    {	
	if (!parserData->pathPairFromPresent)
		osolerror (NULL, osoption, parserData, osglData, "\"from\" attribute must be present");
	if (!parserData->pathPairToPresent)
		osolerror (NULL, osoption, parserData, osglData, "\"to\" attribute must be present");
	parserData->kounter++;
;}
    break;

  case 1046:

    {
	if (parserData->kounter >= parserData->numberOfPathPairs)
		osolerror (NULL, osoption, parserData, osglData, "too many path pairs");
	parserData->pathPairFromPresent = false;
	parserData->pathPairToPresent = false;
	parserData->pathPairMakeCopyPresent = false;
	parserData->pathPairMakeCopy = false;
;}
    break;

  case 1047:

    {
	parserData->makeCopy[parserData->kounter] = parserData->pathPairMakeCopy;
;}
    break;

  case 1053:

    {
	if (parserData->pathPairFromPresent)
		osolerror( NULL, osoption, parserData, osglData, "only one \"from\" attribute allowed");
	parserData->pathPairFromPresent = true;
	parserData->fromPaths[parserData->kounter] = (yyvsp[(2) - (3)].sval);
;}
    break;

  case 1054:

    {
	if (parserData->pathPairToPresent)
		osolerror( NULL, osoption, parserData, osglData, "only one \"to\" attribute allowed");
	parserData->pathPairToPresent = true;
	parserData->toPaths[parserData->kounter] = (yyvsp[(2) - (3)].sval);
;}
    break;

  case 1055:

    {
	if (parserData->pathPairMakeCopyPresent)
		osolerror( NULL, osoption, parserData, osglData, "only one \"makeCopy\" attribute allowed");
	parserData->pathPairMakeCopyPresent = true;
	parserData->pathPairMakeCopy = (strcmp((yyvsp[(2) - (3)].sval),"true") == 0);
;}
    break;

  case 1058:

    {   
	if (parserData->categoryAttributePresent ) 
		osolerror(NULL, NULL, parserData, osglData, "only one category attribute allowed for this element");
	parserData->categoryAttributePresent = true;
;}
    break;

  case 1061:

    { 
	parserData->categoryAttribute = "";
;}
    break;

  case 1062:

    { 
	parserData->categoryAttribute = (yyvsp[(2) - (3)].sval); 
	free((yyvsp[(2) - (3)].sval)); 
;}
    break;

  case 1063:

    {
	if (parserData->descriptionAttributePresent ) 
		osolerror(NULL, NULL, parserData, osglData, "only one description attribute allowed for this element");
	parserData->descriptionAttributePresent = true;
;}
    break;

  case 1066:

    { parserData->descriptionAttribute = ""; ;}
    break;

  case 1067:

    { 
	parserData->descriptionAttribute = (yyvsp[(2) - (3)].sval); 
	free((yyvsp[(2) - (3)].sval));
;}
    break;

  case 1068:

    {
	if (parserData->groupWeightAttributePresent ) 
		osolerror(NULL, NULL, parserData, osglData, "only one groupWeight attribute allowed for this element");
	parserData->groupWeightAttributePresent = true;
;}
    break;

  case 1069:

    {
	parserData->groupWeight = parserData->tempVal;
;}
    break;

  case 1070:

    {   
	if (parserData->idxAttributePresent ) 
		osolerror(NULL, NULL, parserData, osglData, "only one idx attribute allowed for this element");
	parserData->idxAttributePresent = true;
;}
    break;

  case 1072:

    { 
	parserData->idxAttribute = (yyvsp[(3) - (4)].ival);
;}
    break;

  case 1073:

    {   
	if (parserData->lbValueAttributePresent ) 
		osolerror(NULL, NULL, parserData, osglData, "only one lb attribute allowed for this element");
	parserData->lbValueAttributePresent = true;
;}
    break;

  case 1076:

    { 
	parserData->lbValueAttribute = ""; 
;}
    break;

  case 1077:

    { 
	parserData->lbValueAttribute = (yyvsp[(2) - (3)].sval); 
	free((yyvsp[(2) - (3)].sval));
;}
    break;

  case 1078:

    {   if (parserData->lbValueAttributePresent ) 
				osolerror(NULL, NULL, parserData, osglData, "only one lb attribute allowed for this element");
			parserData->lbValueAttributePresent = true;
		;}
    break;

  case 1081:

    { parserData->lbDualValue = 0.0; ;}
    break;

  case 1082:

    { parserData->lbDualValue = parserData->tempVal;;}
    break;

  case 1083:

    {   if (parserData->nameAttributePresent ) 
				osolerror(NULL, NULL, parserData, osglData, "only one name attribute allowed for this element");
			parserData->nameAttributePresent = true;
		;}
    break;

  case 1086:

    { parserData->nameAttribute = ""; ;}
    break;

  case 1087:

    { 
	parserData->nameAttribute = (yyvsp[(2) - (3)].sval); 
	free((yyvsp[(2) - (3)].sval));
;}
    break;

  case 1088:

    {   if (parserData->solverAttributePresent ) 
				osolerror(NULL, NULL, parserData, osglData, "only one solver attribute allowed for this element");
			parserData->solverAttributePresent = true;
		;}
    break;

  case 1091:

    { parserData->solverAttribute = ""; ;}
    break;

  case 1092:

    { 
	parserData->solverAttribute = (yyvsp[(2) - (3)].sval); 
	free((yyvsp[(2) - (3)].sval));
;}
    break;

  case 1093:

    {   if (parserData->sosIdxAttributePresent ) 
			osolerror(NULL, NULL, parserData, osglData, "only one sosIdx attribute allowed for this element");
		parserData->sosIdxAttributePresent = true;
	;}
    break;

  case 1095:

    {
	if ((yyvsp[(3) - (4)].ival) < 0)
		osolerror (NULL, osoption, parserData, osglData, "SOS index must be nonnegative");
	parserData->sosIdx = (yyvsp[(3) - (4)].ival);
;}
    break;

  case 1096:

    {   if (parserData->typeAttributePresent ) 
				osolerror(NULL, NULL, parserData, osglData, "only one type attribute allowed for this element");
			parserData->typeAttributePresent = true;
		;}
    break;

  case 1099:

    { parserData->typeAttribute = ""; ;}
    break;

  case 1100:

    { 
	parserData->typeAttribute = (yyvsp[(2) - (3)].sval); 
	free((yyvsp[(2) - (3)].sval));
;}
    break;

  case 1101:

    {
   if (parserData->ubValueAttributePresent ) 
		osolerror(NULL, NULL, parserData, osglData, "only one ub attribute allowed for this element");
	parserData->ubValueAttributePresent = true;
;}
    break;

  case 1104:

    { 
	parserData->ubValueAttribute = ""; 
;}
    break;

  case 1105:

    { 
	parserData->ubValueAttribute = (yyvsp[(2) - (3)].sval); 
	free((yyvsp[(2) - (3)].sval));
;}
    break;

  case 1106:

    {   if (parserData->ubValueAttributePresent ) 
				osolerror(NULL, NULL, parserData, osglData, "only one ub attribute allowed for this element");
			parserData->ubValueAttributePresent = true;
		;}
    break;

  case 1109:

    { parserData->ubDualValue = 0.0; ;}
    break;

  case 1110:

    { 
	parserData->ubDualValue = parserData->tempVal;
;}
    break;

  case 1111:

    {   if (parserData->unitAttributePresent ) 
				osolerror(NULL, NULL, parserData, osglData, "only one unit attribute allowed for this element");
			parserData->unitAttributePresent = true;
		;}
    break;

  case 1114:

    { parserData->unitAttribute = ""; ;}
    break;

  case 1115:

    { 
	parserData->unitAttribute = (yyvsp[(2) - (3)].sval); 
	free((yyvsp[(2) - (3)].sval));
;}
    break;

  case 1116:

    {   if (parserData->valueAttributePresent ) 
				osolerror(NULL, NULL, parserData, osglData, "only one value attribute allowed for this element");
			parserData->valueAttributePresent = true;
		;}
    break;

  case 1119:

    { parserData->valueAttribute = ""; ;}
    break;

  case 1120:

    {
	parserData->valueAttribute = (yyvsp[(2) - (3)].sval); 
	free((yyvsp[(2) - (3)].sval));
;}
    break;

  case 1121:

    {
	if (parserData->numberOfConAttributePresent)
		osolerror(NULL, NULL, parserData, osglData, "numberOfCon attribute previously set");
	if ((yyvsp[(3) - (4)].ival) < 0) osolerror(NULL, NULL, parserData, osglData, "number of <con> cannot be negative");
	parserData->numberOfConAttributePresent = true;		
	parserData->numberOfCon = (yyvsp[(3) - (4)].ival);
;}
    break;

  case 1122:

    {
	if (parserData->numberOfConstraintsPresent)
		osolerror(NULL, NULL, parserData, osglData, "numberOfConstraints attribute previously set");
	if ((yyvsp[(3) - (4)].ival) < 0) osolerror(NULL, NULL, parserData, osglData, "number of constraints cannot be negative");
	parserData->numberOfConstraintsPresent = true;		
	parserData->tempInt = (yyvsp[(3) - (4)].ival); 
;}
    break;

  case 1123:

    {
	if (osglData->osglNumberOfElPresent)
		osolerror(NULL, NULL, parserData, osglData, "numberOfEl attribute previously set");
	if ((yyvsp[(3) - (4)].ival) < 0) osolerror(NULL, NULL, parserData, osglData, "number of <el> cannot be negative");
	osglData->osglNumberOfElPresent = true;
	parserData->numberOf = (yyvsp[(3) - (4)].ival); 
;}
    break;

  case 1124:

    {
	if (parserData->numberOfEnumerationsAttributePresent)
		osolerror(NULL, NULL, parserData, osglData, "numberOfEnumerations attribute previously set");
	if ((yyvsp[(3) - (4)].ival) < 0) osolerror(NULL, NULL, parserData, osglData, "number of <enumeration> elements cannot be negative");
	parserData->numberOfEnumerationsAttributePresent = true;		
	parserData->numberOfEnumerations = (yyvsp[(3) - (4)].ival); 
;}
    break;

  case 1125:

    {	
   if (parserData->numberOfItemsPresent ) 
        osolerror(NULL, NULL, parserData, osglData, "only one numberOfItems attribute allowed");
	if ((yyvsp[(3) - (4)].ival) < 0) osolerror(NULL, NULL, parserData, osglData, "number of items cannot be negative");
	parserData->numberOfItemsPresent = true;
	parserData->numberOfItems = (yyvsp[(3) - (4)].ival);
;}
    break;

  case 1126:

    {
	if ((yyvsp[(3) - (4)].ival) < 0)
		osolerror( NULL, osoption, parserData, osglData, "Number of job IDs cannot be negative");
	parserData->numberOf = (yyvsp[(3) - (4)].ival);
	parserData->kounter = 0;
	parserData->jobDependencies = new std::string[(yyvsp[(3) - (4)].ival)];
;}
    break;

  case 1127:

    {
	if (parserData->numberOfObjAttributePresent)
		osolerror(NULL, NULL, parserData, osglData, "numberOfObj attribute previously set");
	if ((yyvsp[(3) - (4)].ival) < 0) osolerror(NULL, NULL, parserData, osglData, "number of <obj> cannot be negative");
	parserData->numberOfObjAttributePresent = true;		
	parserData->numberOfObj = (yyvsp[(3) - (4)].ival);
;}
    break;

  case 1128:

    {	if (parserData->numberOfObjectivesPresent)
		osolerror(NULL, NULL, parserData, osglData, "numberOfObjectives attribute previously set");
	if ((yyvsp[(3) - (4)].ival) < 0) osolerror(NULL, NULL, parserData, osglData, "number of objectives cannot be negative");
	parserData->numberOfObjectivesPresent = true;
	parserData->tempInt = (yyvsp[(3) - (4)].ival); 
;}
    break;

  case 1129:

    {
	if ((yyvsp[(3) - (4)].ival) < 0) osolerror(NULL, NULL, parserData, osglData, "number of other constraint options cannot be negative");
	parserData->tempInt = (yyvsp[(3) - (4)].ival);
;}
    break;

  case 1130:

    {
	if ((yyvsp[(3) - (4)].ival) < 0) osolerror(NULL, NULL, parserData, osglData, "number of other objective options cannot be negative");
	parserData->tempInt = (yyvsp[(3) - (4)].ival);
;}
    break;

  case 1131:

    {
	if ((yyvsp[(3) - (4)].ival) < 0) osolerror(NULL, NULL, parserData, osglData, "number of other options cannot be negative");
	parserData->tempInt = (yyvsp[(3) - (4)].ival);
;}
    break;

  case 1132:

    {	
	if ((yyvsp[(3) - (4)].ival) < 0) osolerror(NULL, NULL, parserData, osglData, "number of other variable options cannot be negative");
	parserData->tempInt = (yyvsp[(3) - (4)].ival);
;}
    break;

  case 1133:

    {
	if ((yyvsp[(3) - (4)].ival) < 0)
		osolerror( NULL, osoption, parserData, osglData, "Number of path pairs cannot be negative");
	parserData->numberOfPathPairs = (yyvsp[(3) - (4)].ival);
	parserData->kounter = 0;
	parserData->fromPaths = new std::string[(yyvsp[(3) - (4)].ival)];
	parserData->toPaths   = new std::string[(yyvsp[(3) - (4)].ival)];
	parserData->makeCopy  = new bool[(yyvsp[(3) - (4)].ival)];
;}
    break;

  case 1134:

    {
	if ((yyvsp[(3) - (4)].ival) < 0)
		osolerror( NULL, osoption, parserData, osglData, "Number of paths cannot be negative");
	parserData->numberOf = (yyvsp[(3) - (4)].ival);
	parserData->kounter = 0;
	parserData->paths = new std::string[(yyvsp[(3) - (4)].ival)];
;}
    break;

  case 1135:

    {
	if ((yyvsp[(3) - (4)].ival) < 0)
		osolerror( NULL, osoption, parserData, osglData, "Number of job IDs cannot be negative");
	parserData->numberOf = (yyvsp[(3) - (4)].ival);
	parserData->kounter = 0;
	parserData->processesToKill = new std::string[(yyvsp[(3) - (4)].ival)];
;}
    break;

  case 1136:

    {	
	if ((yyvsp[(3) - (4)].ival) < 0) osolerror(NULL, NULL, parserData, osglData, "number of solver options cannot be negative");
	parserData->numberOfSolverOptions = (yyvsp[(3) - (4)].ival);
;}
    break;

  case 1137:

    {
	if (parserData->numberOfVarAttributePresent)
		osolerror(NULL, NULL, parserData, osglData, "numberOfVar attribute previously set");
	if ((yyvsp[(3) - (4)].ival) < 0) osolerror(NULL, NULL, parserData, osglData, "number of <var> cannot be negative");
	parserData->numberOfVarAttributePresent = true;		
	parserData->numberOfVar = (yyvsp[(3) - (4)].ival); 
;}
    break;

  case 1138:

    {	if (parserData->numberOfVariablesPresent)
		osolerror(NULL, NULL, parserData, osglData, "numberOfVariables attribute previously set");
	if ((yyvsp[(3) - (4)].ival) < 0) osolerror(NULL, NULL, parserData, osglData, "number of variables cannot be negative");
	parserData->numberOfVariablesPresent = true;	
	parserData->tempInt = (yyvsp[(3) - (4)].ival); 
;}
    break;

  case 1141:

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
;}
    break;

  case 1142:

    {
	if (parserData->kounter >= parserData->numberOfEnumerations)
		osolerror(NULL, NULL, parserData, osglData, "more <enumeration> elements than specified");
	osglData->osglNumberOfElPresent = false;
	parserData->valueAttributePresent = false;
	parserData->descriptionAttributePresent = false;
	parserData->valueAttribute = "";
	parserData->descriptionAttribute = "";
;}
    break;

  case 1143:

    {	if(!osglData->osglNumberOfElPresent) 
			osolerror(NULL, NULL, parserData, osglData, "<other> element enumeration requires numberOfEl attribute"); 
		if(!parserData->valueAttributePresent) 
			osolerror(NULL, NULL, parserData, osglData, "<other> element enumeration requires value attribute"); 
	;}
    break;

  case 1146:

    {
		osglData->osglCounter = 0; 
		osglData->osglNumberOfElPresent = true;
		osglData->osglNumberOfEl = parserData->numberOf;
		osglData->osglIntArray = new int[parserData->numberOf];
	;}
    break;

  case 1154:

    {
	 	if (osglData->osglCounter < osglData->osglNumberOfEl)
			osolerror(NULL, NULL, parserData, osglData, "fewer data elements than specified");
	;}
    break;

  case 1159:

    {	
	osglData->osglMultPresent = false;
	osglData->osglIncrPresent = false;
	osglData->osglMult = 1;
	osglData->osglIncr = 0;
;}
    break;

  case 1165:

    {
	if (osglData->osglCounter + osglData->osglMult > osglData->osglNumberOfEl)
		osolerror(NULL, NULL, parserData, osglData, "more data elements than specified");
	for (int i=0; i<osglData->osglMult; i++)
		osglData->osglIntArray[osglData->osglCounter++] = (yyvsp[(2) - (3)].ival) + i*osglData->osglIncr;	
;}
    break;

  case 1167:

    {
	osglData->osglSize = (yyvsp[(3) - (4)].ival);
;}
    break;

  case 1172:

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
;}
    break;

  case 1173:

    {	
	if (osglData->osglIncrPresent) 
        osolerror(NULL, NULL, parserData, osglData, "only one incr attribute allowed");
	osglData->osglIncrPresent = true;
	osglData->osglIncr = (yyvsp[(3) - (4)].ival);
;}
    break;

  case 1174:

    {	
	if (osglData->osglMultPresent) 
        osolerror(NULL, NULL, parserData, osglData, "only one mult attribute allowed");
	if ((yyvsp[(3) - (4)].ival) <= 0) osolerror(NULL, NULL, parserData, osglData, "mult must be positive");
	osglData->osglMultPresent = true;
	osglData->osglMult = (yyvsp[(3) - (4)].ival);
;}
    break;

  case 1175:

    {parserData->tempVal = (yyvsp[(1) - (1)].ival);;}
    break;

  case 1176:

    {parserData->tempVal = (yyvsp[(1) - (1)].dval);;}
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


