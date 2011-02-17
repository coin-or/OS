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
#define YYLAST   1270

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  233
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  801
/* YYNRULES -- Number of rules.  */
#define YYNRULES  1181
/* YYNRULES -- Number of states.  */
#define YYNSTATES  1638

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
      22,    24,    28,    35,    36,    39,    41,    43,    45,    47,
      51,    57,    58,    60,    62,    64,    66,    68,    72,    73,
      75,    77,    79,    81,    83,    87,    88,    90,    92,    94,
      96,    98,   102,   103,   105,   107,   109,   111,   113,   117,
     118,   120,   122,   124,   126,   128,   132,   133,   136,   138,
     140,   142,   145,   147,   151,   153,   155,   158,   160,   162,
     164,   166,   168,   170,   172,   174,   176,   178,   180,   183,
     185,   187,   189,   192,   194,   198,   200,   203,   205,   207,
     209,   212,   214,   218,   220,   223,   225,   227,   229,   232,
     234,   238,   240,   244,   246,   247,   249,   253,   255,   257,
     260,   262,   266,   268,   271,   273,   275,   277,   280,   282,
     286,   288,   291,   293,   295,   297,   300,   302,   306,   308,
     311,   313,   315,   317,   320,   322,   326,   328,   331,   333,
     335,   337,   340,   342,   346,   348,   351,   353,   355,   357,
     360,   362,   366,   368,   372,   374,   375,   377,   381,   383,
     385,   388,   390,   394,   396,   400,   402,   404,   406,   408,
     411,   413,   417,   419,   421,   424,   428,   430,   432,   433,
     436,   438,   440,   442,   445,   447,   448,   451,   453,   455,
     457,   460,   462,   466,   468,   470,   473,   475,   477,   479,
     481,   483,   487,   489,   491,   492,   495,   497,   499,   503,
     505,   509,   511,   513,   514,   517,   519,   521,   525,   527,
     531,   533,   535,   536,   539,   541,   543,   547,   549,   553,
     555,   556,   558,   562,   564,   568,   570,   572,   574,   576,
     579,   581,   585,   587,   589,   592,   596,   598,   600,   601,
     604,   606,   608,   610,   613,   615,   616,   619,   621,   623,
     625,   628,   630,   634,   636,   638,   641,   643,   645,   648,
     650,   652,   654,   657,   659,   663,   665,   669,   671,   673,
     675,   677,   680,   682,   686,   688,   690,   693,   697,   699,
     701,   702,   705,   707,   709,   711,   714,   716,   717,   720,
     722,   724,   726,   729,   731,   735,   737,   739,   742,   744,
     746,   748,   750,   752,   754,   756,   758,   760,   762,   764,
     766,   768,   770,   772,   776,   778,   780,   782,   784,   787,
     789,   793,   795,   797,   800,   802,   804,   806,   809,   811,
     815,   817,   821,   823,   825,   827,   829,   832,   834,   838,
     840,   843,   848,   852,   854,   856,   858,   860,   863,   865,
     869,   871,   874,   879,   883,   885,   887,   889,   891,   894,
     896,   900,   902,   905,   910,   914,   916,   918,   920,   922,
     925,   927,   931,   933,   936,   941,   945,   947,   949,   951,
     953,   956,   958,   962,   964,   967,   972,   976,   978,   980,
     982,   984,   987,   989,   993,   995,   998,  1000,  1004,  1006,
    1008,  1010,  1012,  1015,  1017,  1021,  1023,  1026,  1028,  1032,
    1034,  1036,  1038,  1040,  1043,  1045,  1049,  1051,  1054,  1056,
    1060,  1062,  1064,  1066,  1068,  1071,  1073,  1077,  1079,  1082,
    1084,  1088,  1090,  1092,  1094,  1096,  1099,  1101,  1105,  1107,
    1110,  1115,  1119,  1121,  1123,  1125,  1127,  1130,  1132,  1136,
    1138,  1141,  1146,  1150,  1152,  1154,  1156,  1158,  1161,  1163,
    1167,  1169,  1172,  1177,  1181,  1183,  1185,  1187,  1189,  1192,
    1194,  1198,  1200,  1202,  1205,  1209,  1211,  1213,  1214,  1217,
    1219,  1221,  1223,  1226,  1228,  1229,  1233,  1235,  1237,  1238,
    1241,  1243,  1245,  1247,  1249,  1251,  1253,  1257,  1262,  1263,
    1267,  1269,  1271,  1272,  1274,  1276,  1278,  1280,  1284,  1291,
    1292,  1296,  1298,  1300,  1302,  1304,  1307,  1309,  1313,  1315,
    1317,  1320,  1324,  1326,  1327,  1330,  1332,  1334,  1337,  1339,
    1340,  1344,  1346,  1348,  1350,  1352,  1355,  1357,  1361,  1363,
    1365,  1368,  1372,  1374,  1376,  1377,  1380,  1382,  1384,  1387,
    1389,  1390,  1393,  1395,  1397,  1399,  1401,  1405,  1412,  1413,
    1417,  1419,  1421,  1423,  1425,  1427,  1431,  1433,  1434,  1438,
    1440,  1442,  1444,  1446,  1448,  1452,  1454,  1455,  1459,  1461,
    1463,  1465,  1467,  1469,  1473,  1475,  1476,  1480,  1482,  1484,
    1486,  1488,  1490,  1494,  1496,  1497,  1501,  1503,  1505,  1507,
    1509,  1511,  1515,  1517,  1518,  1522,  1524,  1526,  1528,  1530,
    1532,  1536,  1538,  1539,  1543,  1545,  1547,  1549,  1551,  1554,
    1556,  1560,  1562,  1564,  1567,  1571,  1573,  1575,  1576,  1579,
    1581,  1583,  1586,  1588,  1589,  1593,  1595,  1600,  1602,  1604,
    1607,  1609,  1613,  1615,  1618,  1622,  1624,  1626,  1627,  1630,
    1632,  1634,  1636,  1638,  1640,  1643,  1645,  1649,  1650,  1653,
    1657,  1659,  1661,  1662,  1665,  1667,  1669,  1671,  1673,  1675,
    1677,  1679,  1681,  1683,  1685,  1688,  1690,  1694,  1696,  1698,
    1700,  1703,  1707,  1709,  1711,  1712,  1715,  1717,  1719,  1721,
    1723,  1725,  1728,  1730,  1731,  1735,  1737,  1739,  1740,  1742,
    1744,  1746,  1748,  1752,  1757,  1758,  1762,  1764,  1766,  1768,
    1770,  1773,  1775,  1779,  1781,  1783,  1786,  1790,  1792,  1794,
    1795,  1798,  1800,  1802,  1805,  1807,  1808,  1812,  1814,  1816,
    1818,  1820,  1823,  1825,  1829,  1831,  1833,  1836,  1840,  1842,
    1844,  1845,  1848,  1850,  1852,  1854,  1857,  1859,  1860,  1863,
    1865,  1867,  1869,  1871,  1875,  1882,  1883,  1887,  1889,  1891,
    1893,  1895,  1897,  1901,  1903,  1904,  1908,  1910,  1912,  1914,
    1916,  1918,  1922,  1924,  1925,  1929,  1931,  1933,  1935,  1937,
    1939,  1943,  1945,  1946,  1950,  1952,  1954,  1956,  1958,  1960,
    1964,  1966,  1967,  1971,  1973,  1975,  1977,  1979,  1981,  1985,
    1987,  1988,  1992,  1994,  1996,  1998,  2000,  2002,  2006,  2008,
    2009,  2012,  2016,  2018,  2020,  2021,  2024,  2026,  2028,  2030,
    2032,  2034,  2036,  2038,  2040,  2042,  2044,  2047,  2049,  2053,
    2055,  2057,  2059,  2062,  2066,  2068,  2070,  2071,  2074,  2076,
    2078,  2080,  2082,  2084,  2087,  2089,  2090,  2094,  2096,  2098,
    2099,  2101,  2103,  2105,  2107,  2111,  2116,  2117,  2121,  2123,
    2125,  2127,  2129,  2132,  2134,  2138,  2140,  2142,  2145,  2149,
    2151,  2152,  2155,  2157,  2159,  2162,  2164,  2165,  2169,  2171,
    2173,  2175,  2177,  2180,  2182,  2186,  2188,  2190,  2193,  2197,
    2199,  2201,  2202,  2205,  2207,  2209,  2211,  2214,  2216,  2217,
    2220,  2222,  2224,  2226,  2228,  2232,  2239,  2240,  2244,  2246,
    2248,  2250,  2252,  2254,  2258,  2260,  2261,  2265,  2267,  2269,
    2271,  2273,  2275,  2279,  2281,  2282,  2286,  2288,  2290,  2292,
    2294,  2296,  2300,  2302,  2303,  2307,  2309,  2311,  2313,  2315,
    2317,  2321,  2323,  2324,  2328,  2330,  2332,  2334,  2336,  2338,
    2342,  2344,  2345,  2349,  2351,  2353,  2355,  2357,  2359,  2363,
    2365,  2366,  2369,  2373,  2375,  2377,  2378,  2381,  2383,  2385,
    2387,  2389,  2391,  2393,  2395,  2397,  2399,  2401,  2404,  2406,
    2410,  2412,  2414,  2416,  2419,  2423,  2425,  2427,  2428,  2431,
    2433,  2435,  2437,  2439,  2441,  2444,  2446,  2447,  2451,  2453,
    2455,  2457,  2459,  2461,  2465,  2466,  2469,  2473,  2475,  2477,
    2479,  2482,  2484,  2486,  2488,  2490,  2492,  2494,  2496,  2498,
    2500,  2503,  2505,  2509,  2511,  2513,  2516,  2518,  2520,  2522,
    2524,  2526,  2530,  2532,  2536,  2538,  2540,  2541,  2544,  2546,
    2548,  2550,  2554,  2558,  2562,  2565,  2567,  2569,  2571,  2573,
    2575,  2579,  2581,  2583,  2585,  2587,  2591,  2593,  2598,  2600,
    2602,  2607,  2609,  2611,  2613,  2615,  2619,  2621,  2623,  2625,
    2627,  2632,  2634,  2636,  2638,  2640,  2644,  2646,  2648,  2650,
    2652,  2656,  2658,  2660,  2665,  2667,  2669,  2671,  2673,  2677,
    2679,  2681,  2683,  2685,  2689,  2691,  2693,  2695,  2697,  2702,
    2704,  2706,  2708,  2710,  2714,  2716,  2718,  2720,  2722,  2726,
    2731,  2736,  2741,  2746,  2751,  2756,  2761,  2766,  2771,  2776,
    2781,  2786,  2791,  2796,  2801,  2806,  2811,  2816,  2818,  2821,
    2825,  2827,  2829,  2830,  2833,  2835,  2837,  2839,  2841,  2843,
    2845,  2849,  2851,  2853,  2855,  2856,  2859,  2863,  2865,  2867,
    2868,  2871,  2873,  2875,  2879,  2883,  2888,  2890,  2892,  2895,
    2897,  2901,  2906,  2911,  2913,  2915,  2918,  2919,  2922,  2924,
    2926,  2928
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     234,     0,    -1,   235,   241,    15,    -1,   236,   237,   238,
      -1,    13,    -1,    12,    -1,    -1,    14,    -1,   239,    -1,
     240,    -1,    11,    -1,    10,   241,    15,    -1,   242,   268,
     354,   402,   430,   562,    -1,    -1,   243,   244,    -1,    67,
      -1,   245,    -1,   246,    -1,    11,    -1,    10,   247,    68,
      -1,   248,   252,   256,   260,   264,    -1,    -1,   249,    -1,
     250,    -1,   251,    -1,    82,    -1,    81,    -1,    79,     5,
      80,    -1,    -1,   253,    -1,   254,    -1,   255,    -1,    86,
      -1,    85,    -1,    83,     5,    84,    -1,    -1,   257,    -1,
     258,    -1,   259,    -1,    90,    -1,    89,    -1,    87,     5,
      88,    -1,    -1,   261,    -1,   262,    -1,   263,    -1,    94,
      -1,    93,    -1,    91,     5,    92,    -1,    -1,   265,    -1,
     266,    -1,   267,    -1,    98,    -1,    97,    -1,    95,     5,
      96,    -1,    -1,   269,   270,    -1,    69,    -1,   271,    -1,
     272,    -1,    10,    70,    -1,    11,    -1,    10,   273,    70,
      -1,   274,    -1,   275,    -1,   274,   275,    -1,   276,    -1,
     282,    -1,   288,    -1,   294,    -1,   302,    -1,   308,    -1,
     314,    -1,   320,    -1,   326,    -1,   332,    -1,   340,    -1,
     277,   278,    -1,    99,    -1,   279,    -1,   280,    -1,    10,
     100,    -1,    11,    -1,    10,   281,   100,    -1,     4,    -1,
     283,   284,    -1,   101,    -1,   285,    -1,   286,    -1,    10,
     102,    -1,    11,    -1,    10,   287,   102,    -1,     4,    -1,
     289,   290,    -1,   103,    -1,   291,    -1,   292,    -1,    10,
     104,    -1,    11,    -1,    10,   293,   104,    -1,     4,    -1,
     295,   296,   298,    -1,   105,    -1,    -1,   297,    -1,    66,
       3,     8,    -1,   299,    -1,   300,    -1,    10,   106,    -1,
      11,    -1,    10,   301,   106,    -1,     4,    -1,   303,   304,
      -1,   107,    -1,   305,    -1,   306,    -1,    10,   108,    -1,
      11,    -1,    10,   307,   108,    -1,     4,    -1,   309,   310,
      -1,   109,    -1,   311,    -1,   312,    -1,    10,   110,    -1,
      11,    -1,    10,   313,   110,    -1,     4,    -1,   315,   316,
      -1,   111,    -1,   317,    -1,   318,    -1,    10,   112,    -1,
      11,    -1,    10,   319,   112,    -1,     4,    -1,   321,   322,
      -1,   113,    -1,   323,    -1,   324,    -1,    10,   114,    -1,
      11,    -1,    10,   325,   114,    -1,     4,    -1,   327,   328,
      -1,   115,    -1,   329,    -1,   330,    -1,    10,   116,    -1,
      11,    -1,    10,   331,   116,    -1,     4,    -1,   333,   334,
     336,    -1,   117,    -1,    -1,   335,    -1,    65,     3,     8,
      -1,   337,    -1,   338,    -1,    10,   118,    -1,    11,    -1,
      10,   339,   118,    -1,     4,    -1,   341,   342,   343,    -1,
     119,    -1,   997,    -1,   344,    -1,   345,    -1,    10,   120,
      -1,    11,    -1,    10,   346,   120,    -1,   347,    -1,   348,
      -1,   347,   348,    -1,   349,   350,   353,    -1,   121,    -1,
     351,    -1,    -1,   351,   352,    -1,   956,    -1,   983,    -1,
     939,    -1,    10,   122,    -1,    11,    -1,    -1,   355,   356,
      -1,    71,    -1,   357,    -1,   358,    -1,    10,    72,    -1,
      11,    -1,    10,   359,    72,    -1,   360,    -1,   361,    -1,
     360,   361,    -1,   362,    -1,   369,    -1,   376,    -1,   383,
      -1,   388,    -1,   363,   364,   367,    -1,   123,    -1,   365,
      -1,    -1,   365,   366,    -1,   979,    -1,   939,    -1,    10,
     368,   124,    -1,  1030,    -1,   370,   371,   374,    -1,   125,
      -1,   372,    -1,    -1,   372,   373,    -1,   979,    -1,   939,
      -1,    10,   375,   126,    -1,  1030,    -1,   377,   378,   381,
      -1,   127,    -1,   379,    -1,    -1,   379,   380,    -1,   979,
      -1,   939,    -1,    10,   382,   128,    -1,  1030,    -1,   384,
     385,   386,    -1,   129,    -1,    -1,   939,    -1,    10,   387,
     130,    -1,     6,    -1,   389,   390,   391,    -1,   119,    -1,
     997,    -1,   392,    -1,   393,    -1,    10,   120,    -1,    11,
      -1,    10,   394,   120,    -1,   395,    -1,   396,    -1,   395,
     396,    -1,   397,   398,   401,    -1,   121,    -1,   399,    -1,
      -1,   399,   400,    -1,   956,    -1,   983,    -1,   939,    -1,
      10,   122,    -1,    11,    -1,    -1,   403,   404,    -1,    73,
      -1,   405,    -1,   406,    -1,    10,    74,    -1,    11,    -1,
      10,   407,    74,    -1,   408,    -1,   409,    -1,   408,   409,
      -1,   410,    -1,   416,    -1,   411,   412,    -1,   131,    -1,
     413,    -1,   414,    -1,    10,   132,    -1,    11,    -1,    10,
     415,   132,    -1,     4,    -1,   417,   418,   419,    -1,   119,
      -1,   997,    -1,   420,    -1,   421,    -1,    10,   120,    -1,
      11,    -1,    10,   422,   120,    -1,   423,    -1,   424,    -1,
     423,   424,    -1,   425,   426,   429,    -1,   121,    -1,   427,
      -1,    -1,   427,   428,    -1,   956,    -1,   983,    -1,   939,
      -1,    10,   122,    -1,    11,    -1,    -1,   431,   432,    -1,
      75,    -1,   433,    -1,   434,    -1,    10,    76,    -1,    11,
      -1,    10,   435,    76,    -1,   436,    -1,   437,    -1,   436,
     437,    -1,   438,    -1,   446,    -1,   452,    -1,   460,    -1,
     468,    -1,   476,    -1,   484,    -1,   492,    -1,   500,    -1,
     516,    -1,   508,    -1,   524,    -1,   532,    -1,   540,    -1,
     548,    -1,   439,   440,   441,    -1,   133,    -1,   979,    -1,
     442,    -1,   443,    -1,    10,   134,    -1,    11,    -1,    10,
     444,   134,    -1,   445,    -1,  1030,    -1,   447,   448,    -1,
     135,    -1,   449,    -1,   450,    -1,    10,   136,    -1,    11,
      -1,    10,   451,   136,    -1,     4,    -1,   453,   454,   455,
      -1,   137,    -1,   992,    -1,   456,    -1,   457,    -1,    10,
     138,    -1,    11,    -1,    10,   458,   138,    -1,   459,    -1,
     458,   459,    -1,   107,    10,     4,   108,    -1,   461,   462,
     463,    -1,   139,    -1,  1000,    -1,   464,    -1,   465,    -1,
      10,   140,    -1,    11,    -1,    10,   466,   140,    -1,   467,
      -1,   466,   467,    -1,   143,    10,     4,   144,    -1,   469,
     470,   471,    -1,   141,    -1,  1000,    -1,   472,    -1,   473,
      -1,    10,   142,    -1,    11,    -1,    10,   474,   142,    -1,
     475,    -1,   474,   475,    -1,   143,    10,     4,   144,    -1,
     477,   478,   479,    -1,   147,    -1,  1000,    -1,   480,    -1,
     481,    -1,    10,   148,    -1,    11,    -1,    10,   482,   148,
      -1,   483,    -1,   482,   483,    -1,   143,    10,     4,   144,
      -1,   485,   486,   487,    -1,   149,    -1,  1000,    -1,   488,
      -1,   489,    -1,    10,   150,    -1,    11,    -1,    10,   490,
     150,    -1,   491,    -1,   490,   491,    -1,   143,    10,     4,
     144,    -1,   493,   494,   495,    -1,   155,    -1,   999,    -1,
     496,    -1,   497,    -1,    10,   156,    -1,    11,    -1,    10,
     498,   156,    -1,   499,    -1,   498,   499,    -1,   926,    -1,
     501,   502,   503,    -1,   157,    -1,   999,    -1,   504,    -1,
     505,    -1,    10,   158,    -1,    11,    -1,    10,   506,   158,
      -1,   507,    -1,   506,   507,    -1,   926,    -1,   509,   510,
     511,    -1,   161,    -1,   999,    -1,   512,    -1,   513,    -1,
      10,   162,    -1,    11,    -1,    10,   514,   162,    -1,   515,
      -1,   514,   515,    -1,   926,    -1,   517,   518,   519,    -1,
     159,    -1,   999,    -1,   520,    -1,   521,    -1,    10,   160,
      -1,    11,    -1,    10,   522,   160,    -1,   523,    -1,   522,
     523,    -1,   926,    -1,   525,   526,   527,    -1,   153,    -1,
    1000,    -1,   528,    -1,   529,    -1,    10,   154,    -1,    11,
      -1,    10,   530,   154,    -1,   531,    -1,   530,   531,    -1,
     143,    10,     4,   144,    -1,   533,   534,   535,    -1,   151,
      -1,  1000,    -1,   536,    -1,   537,    -1,    10,   152,    -1,
      11,    -1,    10,   538,   152,    -1,   539,    -1,   538,   539,
      -1,   143,    10,     4,   144,    -1,   541,   542,   543,    -1,
     163,    -1,  1001,    -1,   544,    -1,   545,    -1,    10,   164,
      -1,    11,    -1,    10,   546,   164,    -1,   547,    -1,   546,
     547,    -1,   165,    10,     4,   166,    -1,   549,   550,   551,
      -1,   119,    -1,   997,    -1,   552,    -1,   553,    -1,    10,
     120,    -1,    11,    -1,    10,   554,   120,    -1,   555,    -1,
     556,    -1,   555,   556,    -1,   557,   558,   561,    -1,   121,
      -1,   559,    -1,    -1,   559,   560,    -1,   956,    -1,   983,
      -1,   939,    -1,    10,   122,    -1,    11,    -1,    -1,   563,
     564,   567,    -1,    77,    -1,   565,    -1,    -1,   565,   566,
      -1,  1004,    -1,   988,    -1,   994,    -1,   568,    -1,   569,
      -1,    11,    -1,    10,   570,    78,    -1,   571,   701,   803,
     904,    -1,    -1,   572,   573,   575,    -1,   167,    -1,   574,
      -1,    -1,   998,    -1,   576,    -1,   577,    -1,    11,    -1,
      10,   578,   168,    -1,   579,   592,   606,   654,   668,   683,
      -1,    -1,   580,   581,   582,    -1,   169,    -1,  1003,    -1,
     583,    -1,   584,    -1,    10,   170,    -1,    11,    -1,    10,
     585,   170,    -1,   586,    -1,   587,    -1,   586,   587,    -1,
     588,   589,   591,    -1,   171,    -1,    -1,   589,   590,    -1,
     945,    -1,   983,    -1,    10,   172,    -1,    11,    -1,    -1,
     593,   594,   595,    -1,   173,    -1,  1003,    -1,   596,    -1,
     597,    -1,    10,   174,    -1,    11,    -1,    10,   598,   174,
      -1,   599,    -1,   600,    -1,   599,   600,    -1,   601,   602,
     605,    -1,   171,    -1,   603,    -1,    -1,   603,   604,    -1,
     945,    -1,   983,    -1,    10,   172,    -1,    11,    -1,    -1,
     607,   608,    -1,   175,    -1,   609,    -1,   610,    -1,    11,
      -1,    10,   611,   176,    -1,   612,   619,   626,   633,   640,
     647,    -1,    -1,   613,   614,   615,    -1,   177,    -1,   989,
      -1,   616,    -1,   617,    -1,    11,    -1,    10,   618,   178,
      -1,  1015,    -1,    -1,   620,   621,   622,    -1,   181,    -1,
     989,    -1,   623,    -1,   624,    -1,    11,    -1,    10,   625,
     182,    -1,  1015,    -1,    -1,   627,   628,   629,    -1,   179,
      -1,   989,    -1,   630,    -1,   631,    -1,    11,    -1,    10,
     632,   180,    -1,  1015,    -1,    -1,   634,   635,   636,    -1,
     185,    -1,   989,    -1,   637,    -1,   638,    -1,    11,    -1,
      10,   639,   186,    -1,  1015,    -1,    -1,   641,   642,   643,
      -1,   183,    -1,   989,    -1,   644,    -1,   645,    -1,    11,
      -1,    10,   646,   184,    -1,  1015,    -1,    -1,   648,   649,
     650,    -1,   187,    -1,   989,    -1,   651,    -1,   652,    -1,
      11,    -1,    10,   653,   188,    -1,  1015,    -1,    -1,   655,
     656,   657,    -1,   189,    -1,  1003,    -1,   658,    -1,   659,
      -1,    10,   190,    -1,    11,    -1,    10,   660,   190,    -1,
     661,    -1,   662,    -1,   661,   662,    -1,   663,   664,   667,
      -1,   171,    -1,   665,    -1,    -1,   665,   666,    -1,   945,
      -1,   983,    -1,    10,   172,    -1,    11,    -1,    -1,   669,
     670,   671,    -1,   191,    -1,    29,     8,     6,     8,    -1,
     672,    -1,   673,    -1,    10,   192,    -1,    11,    -1,    10,
     674,   192,    -1,   675,    -1,   674,   675,    -1,   676,   677,
     680,    -1,   193,    -1,   678,    -1,    -1,   678,   679,    -1,
     964,    -1,  1003,    -1,   943,    -1,   681,    -1,   682,    -1,
      10,   194,    -1,    11,    -1,    10,   661,   194,    -1,    -1,
     683,   684,    -1,   685,   686,   689,    -1,   121,    -1,   687,
      -1,    -1,   687,   688,    -1,  1003,    -1,   990,    -1,   956,
      -1,   983,    -1,   960,    -1,   935,    -1,   967,    -1,   939,
      -1,   690,    -1,   691,    -1,    10,   122,    -1,    11,    -1,
      10,   692,   122,    -1,   693,    -1,  1005,    -1,   694,    -1,
     693,   694,    -1,   695,   696,   699,    -1,   171,    -1,   697,
      -1,    -1,   697,   698,    -1,   945,    -1,   983,    -1,   948,
      -1,   971,    -1,   700,    -1,    10,   172,    -1,    11,    -1,
      -1,   702,   703,   705,    -1,   195,    -1,   704,    -1,    -1,
     996,    -1,   706,    -1,   707,    -1,    11,    -1,    10,   708,
     196,    -1,   709,   723,   737,   785,    -1,    -1,   710,   711,
     712,    -1,   197,    -1,   993,    -1,   713,    -1,   714,    -1,
      10,   198,    -1,    11,    -1,    10,   715,   198,    -1,   716,
      -1,   717,    -1,   716,   717,    -1,   718,   719,   722,    -1,
     199,    -1,   720,    -1,    -1,   720,   721,    -1,   945,    -1,
     983,    -1,    10,   200,    -1,    11,    -1,    -1,   724,   725,
     726,    -1,   201,    -1,   993,    -1,   727,    -1,   728,    -1,
      10,   202,    -1,    11,    -1,    10,   729,   202,    -1,   730,
      -1,   731,    -1,   730,   731,    -1,   732,   733,   736,    -1,
     199,    -1,   734,    -1,    -1,   734,   735,    -1,   945,    -1,
     948,    -1,   971,    -1,    10,   200,    -1,    11,    -1,    -1,
     738,   739,    -1,   175,    -1,   740,    -1,   741,    -1,    11,
      -1,    10,   742,   176,    -1,   743,   750,   757,   764,   771,
     778,    -1,    -1,   744,   745,   746,    -1,   177,    -1,   989,
      -1,   747,    -1,   748,    -1,    11,    -1,    10,   749,   178,
      -1,  1015,    -1,    -1,   751,   752,   753,    -1,   181,    -1,
     989,    -1,   754,    -1,   755,    -1,    11,    -1,    10,   756,
     182,    -1,  1015,    -1,    -1,   758,   759,   760,    -1,   179,
      -1,   989,    -1,   761,    -1,   762,    -1,    11,    -1,    10,
     763,   180,    -1,  1015,    -1,    -1,   765,   766,   767,    -1,
     185,    -1,   989,    -1,   768,    -1,   769,    -1,    11,    -1,
      10,   770,   186,    -1,  1015,    -1,    -1,   772,   773,   774,
      -1,   183,    -1,   989,    -1,   775,    -1,   776,    -1,    11,
      -1,    10,   777,   184,    -1,  1015,    -1,    -1,   779,   780,
     781,    -1,   187,    -1,   989,    -1,   782,    -1,   783,    -1,
      11,    -1,    10,   784,   188,    -1,  1015,    -1,    -1,   785,
     786,    -1,   787,   788,   791,    -1,   121,    -1,   789,    -1,
      -1,   789,   790,    -1,   993,    -1,   990,    -1,   956,    -1,
     983,    -1,   960,    -1,   935,    -1,   967,    -1,   939,    -1,
     792,    -1,   793,    -1,    10,   122,    -1,    11,    -1,    10,
     794,   122,    -1,   795,    -1,  1005,    -1,   796,    -1,   795,
     796,    -1,   797,   798,   801,    -1,   199,    -1,   799,    -1,
      -1,   799,   800,    -1,   945,    -1,   983,    -1,   948,    -1,
     971,    -1,   802,    -1,    10,   200,    -1,    11,    -1,    -1,
     804,   805,   807,    -1,   203,    -1,   806,    -1,    -1,   995,
      -1,   808,    -1,   809,    -1,    11,    -1,    10,   810,   204,
      -1,   811,   824,   838,   886,    -1,    -1,   812,   813,   814,
      -1,   205,    -1,   987,    -1,   815,    -1,   816,    -1,    10,
     206,    -1,    11,    -1,    10,   817,   206,    -1,   818,    -1,
     819,    -1,   818,   819,    -1,   820,   821,   823,    -1,   207,
      -1,    -1,   821,   822,    -1,   945,    -1,   983,    -1,    10,
     208,    -1,    11,    -1,    -1,   825,   826,   827,    -1,   209,
      -1,   987,    -1,   828,    -1,   829,    -1,    10,   210,    -1,
      11,    -1,    10,   830,   210,    -1,   831,    -1,   832,    -1,
     831,   832,    -1,   833,   834,   837,    -1,   207,    -1,   835,
      -1,    -1,   835,   836,    -1,   945,    -1,   952,    -1,   975,
      -1,    10,   208,    -1,    11,    -1,    -1,   839,   840,    -1,
     175,    -1,   841,    -1,   842,    -1,    11,    -1,    10,   843,
     176,    -1,   844,   851,   858,   865,   872,   879,    -1,    -1,
     845,   846,   847,    -1,   177,    -1,   989,    -1,   848,    -1,
     849,    -1,    11,    -1,    10,   850,   178,    -1,  1015,    -1,
      -1,   852,   853,   854,    -1,   181,    -1,   989,    -1,   855,
      -1,   856,    -1,    11,    -1,    10,   857,   182,    -1,  1015,
      -1,    -1,   859,   860,   861,    -1,   179,    -1,   989,    -1,
     862,    -1,   863,    -1,    11,    -1,    10,   864,   180,    -1,
    1015,    -1,    -1,   866,   867,   868,    -1,   185,    -1,   989,
      -1,   869,    -1,   870,    -1,    11,    -1,    10,   871,   186,
      -1,  1015,    -1,    -1,   873,   874,   875,    -1,   183,    -1,
     989,    -1,   876,    -1,   877,    -1,    11,    -1,    10,   878,
     184,    -1,  1015,    -1,    -1,   880,   881,   882,    -1,   187,
      -1,   989,    -1,   883,    -1,   884,    -1,    11,    -1,    10,
     885,   188,    -1,  1015,    -1,    -1,   886,   887,    -1,   888,
     889,   892,    -1,   121,    -1,   890,    -1,    -1,   890,   891,
      -1,   987,    -1,   990,    -1,   956,    -1,   983,    -1,   960,
      -1,   935,    -1,   967,    -1,   939,    -1,   893,    -1,   894,
      -1,    10,   122,    -1,    11,    -1,    10,   895,   122,    -1,
     896,    -1,  1005,    -1,   897,    -1,   896,   897,    -1,   898,
     899,   902,    -1,   207,    -1,   900,    -1,    -1,   900,   901,
      -1,   945,    -1,   983,    -1,   948,    -1,   971,    -1,   903,
      -1,    10,   208,    -1,    11,    -1,    -1,   905,   906,   907,
      -1,   211,    -1,  1002,    -1,   908,    -1,   909,    -1,    11,
      -1,    10,   910,   212,    -1,    -1,   910,   911,    -1,   912,
     913,   916,    -1,   213,    -1,   914,    -1,   915,    -1,   914,
     915,    -1,   956,    -1,   983,    -1,   960,    -1,   935,    -1,
     967,    -1,   939,    -1,   991,    -1,   917,    -1,   918,    -1,
      10,   214,    -1,    11,    -1,    10,   919,   214,    -1,   920,
      -1,   921,    -1,   920,   921,    -1,   922,    -1,   923,    -1,
     924,    -1,   220,    -1,   217,    -1,   218,   925,   219,    -1,
       5,    -1,   927,   928,   934,    -1,   145,    -1,   929,    -1,
      -1,   929,   930,    -1,   931,    -1,   932,    -1,   933,    -1,
      21,     3,     8,    -1,    22,     3,     8,    -1,    23,     3,
       8,    -1,    10,   146,    -1,    11,    -1,   936,    -1,   937,
      -1,   938,    -1,    49,    -1,    24,     3,  1031,    -1,   940,
      -1,   941,    -1,   942,    -1,    50,    -1,    46,     3,  1031,
      -1,   944,    -1,    26,     8,  1030,     8,    -1,   946,    -1,
     947,    -1,    42,  1031,     6,  1031,    -1,   949,    -1,   950,
      -1,   951,    -1,    53,    -1,    55,     3,  1031,    -1,   953,
      -1,   954,    -1,   955,    -1,    57,    -1,    59,  1031,  1030,
    1031,    -1,   957,    -1,   958,    -1,   959,    -1,    48,    -1,
      41,     3,  1031,    -1,   961,    -1,   962,    -1,   963,    -1,
      62,    -1,    61,     3,  1031,    -1,   965,    -1,   966,    -1,
      43,  1031,     6,  1031,    -1,   968,    -1,   969,    -1,   970,
      -1,    47,    -1,    25,     3,     8,    -1,   972,    -1,   973,
      -1,   974,    -1,    54,    -1,    56,     3,  1031,    -1,   976,
      -1,   977,    -1,   978,    -1,    58,    -1,    60,  1031,  1030,
    1031,    -1,   980,    -1,   981,    -1,   982,    -1,    51,    -1,
      45,     3,     8,    -1,   984,    -1,   985,    -1,   986,    -1,
      52,    -1,    44,     3,     8,    -1,    39,  1031,     6,  1031,
      -1,    32,  1031,     6,  1031,    -1,    40,  1031,     6,  1031,
      -1,    17,  1031,     6,  1031,    -1,    36,  1031,     6,  1031,
      -1,    18,     8,     6,     8,    -1,    38,  1031,     6,  1031,
      -1,    31,  1031,     6,  1031,    -1,    35,  1031,     6,  1031,
      -1,    34,  1031,     6,  1031,    -1,    16,  1031,     6,  1031,
      -1,    33,  1031,     6,  1031,    -1,    20,     8,     6,     8,
      -1,    19,     8,     6,     8,    -1,    27,     8,     6,     8,
      -1,    28,  1031,     6,  1031,    -1,    37,  1031,     6,  1031,
      -1,    30,  1031,     6,  1031,    -1,  1006,    -1,  1005,  1006,
      -1,  1007,  1008,  1011,    -1,   215,    -1,  1009,    -1,    -1,
    1009,  1010,    -1,   989,    -1,   983,    -1,   939,    -1,  1012,
      -1,  1013,    -1,    11,    -1,    10,  1014,   216,    -1,  1015,
      -1,  1016,    -1,  1023,    -1,    -1,  1016,  1017,    -1,  1018,
    1019,  1022,    -1,   226,    -1,  1020,    -1,    -1,  1020,  1021,
      -1,  1029,    -1,  1028,    -1,    10,     6,   227,    -1,   221,
    1024,  1025,    -1,   225,  1031,     6,  1031,    -1,  1026,    -1,
    1027,    -1,    10,   222,    -1,    11,    -1,    10,     4,   222,
      -1,   223,  1031,     6,  1031,    -1,   224,  1031,     6,  1031,
      -1,     6,    -1,     7,    -1,  1032,     8,    -1,    -1,  1032,
    1033,    -1,   229,    -1,   230,    -1,   231,    -1,   232,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   163,   163,   164,   166,   173,   180,   180,   182,   182,
     184,   186,   189,   197,   197,   204,   213,   213,   215,   217,
     219,   221,   221,   223,   223,   225,   225,   227,   232,   232,
     234,   234,   236,   236,   238,   243,   243,   245,   245,   247,
     247,   249,   254,   254,   256,   256,   258,   258,   260,   265,
     265,   267,   267,   269,   269,   271,   281,   281,   283,   299,
     299,   301,   301,   303,   305,   307,   307,   310,   311,   312,
     313,   314,   315,   316,   317,   318,   319,   320,   324,   326,
     334,   334,   336,   336,   338,   340,   350,   352,   358,   358,
     360,   360,   362,   364,   373,   375,   381,   381,   383,   383,
     385,   387,   397,   404,   412,   413,   420,   426,   426,   428,
     428,   430,   432,   440,   442,   448,   448,   450,   450,   452,
     454,   463,   465,   472,   472,   474,   474,   476,   478,   488,
     490,   497,   497,   499,   499,   501,   503,   513,   515,   521,
     521,   523,   523,   525,   527,   537,   539,   545,   545,   547,
     547,   549,   551,   561,   568,   577,   578,   584,   591,   591,
     593,   593,   595,   597,   604,   606,   612,   620,   624,   629,
     629,   631,   633,   637,   637,   639,   646,   657,   663,   663,
     666,   670,   671,   674,   674,   683,   683,   685,   695,   695,
     697,   697,   699,   701,   703,   703,   706,   707,   708,   709,
     710,   714,   716,   726,   728,   728,   731,   732,   735,   737,
     745,   747,   757,   759,   759,   762,   763,   766,   768,   777,
     779,   789,   791,   791,   794,   795,   798,   800,   809,   811,
     819,   820,   822,   824,   835,   837,   844,   852,   856,   861,
     861,   863,   865,   869,   869,   871,   878,   889,   894,   894,
     897,   902,   903,   906,   906,   915,   915,   917,   924,   924,
     926,   926,   928,   930,   932,   932,   935,   936,   940,   942,
     948,   948,   950,   950,   952,   954,   965,   967,   974,   982,
     986,   991,   991,   993,   995,   999,   999,  1001,  1008,  1019,
    1024,  1024,  1027,  1032,  1033,  1036,  1036,  1044,  1044,  1046,
    1066,  1066,  1068,  1068,  1070,  1072,  1074,  1074,  1077,  1078,
    1079,  1080,  1081,  1082,  1083,  1084,  1085,  1086,  1087,  1088,
    1089,  1090,  1091,  1096,  1102,  1112,  1114,  1114,  1116,  1116,
    1118,  1120,  1122,  1129,  1131,  1137,  1137,  1139,  1139,  1141,
    1143,  1153,  1161,  1168,  1170,  1170,  1172,  1172,  1174,  1180,
    1180,  1182,  1193,  1201,  1207,  1209,  1209,  1211,  1211,  1213,
    1219,  1219,  1221,  1232,  1240,  1246,  1248,  1248,  1250,  1250,
    1252,  1258,  1258,  1260,  1270,  1278,  1284,  1286,  1286,  1288,
    1288,  1290,  1296,  1296,  1298,  1308,  1316,  1322,  1324,  1324,
    1326,  1326,  1328,  1334,  1334,  1336,  1347,  1360,  1366,  1368,
    1368,  1370,  1370,  1372,  1378,  1378,  1380,  1384,  1397,  1403,
    1405,  1405,  1407,  1407,  1409,  1415,  1415,  1417,  1421,  1434,
    1440,  1442,  1442,  1444,  1444,  1446,  1452,  1452,  1454,  1458,
    1471,  1477,  1479,  1479,  1481,  1481,  1483,  1489,  1489,  1491,
    1495,  1503,  1509,  1511,  1511,  1513,  1513,  1515,  1521,  1521,
    1523,  1534,  1542,  1548,  1550,  1550,  1552,  1552,  1554,  1560,
    1560,  1562,  1573,  1581,  1588,  1590,  1590,  1592,  1592,  1594,
    1600,  1600,  1602,  1614,  1616,  1622,  1630,  1634,  1639,  1639,
    1641,  1643,  1647,  1647,  1649,  1656,  1667,  1672,  1672,  1675,
    1680,  1681,  1684,  1684,  1692,  1692,  1694,  1702,  1704,  1704,
    1707,  1713,  1719,  1727,  1727,  1729,  1731,  1733,  1740,  1740,
    1742,  1747,  1754,  1754,  1759,  1759,  1761,  1763,  1765,  1770,
    1770,  1780,  1785,  1793,  1798,  1804,  1804,  1806,  1808,  1810,
    1810,  1813,  1818,  1826,  1826,  1829,  1840,  1847,  1847,  1851,
    1851,  1861,  1866,  1874,  1879,  1885,  1885,  1887,  1889,  1891,
    1891,  1894,  1899,  1908,  1914,  1914,  1917,  1927,  1930,  1930,
    1934,  1934,  1936,  1938,  1938,  1940,  1942,  1944,  1947,  1947,
    1955,  1961,  1968,  1968,  1970,  1972,  1974,  1978,  1978,  1987,
    1993,  2000,  2000,  2002,  2004,  2006,  2010,  2010,  2018,  2024,
    2031,  2031,  2033,  2035,  2037,  2041,  2041,  2049,  2055,  2062,
    2062,  2064,  2066,  2068,  2072,  2072,  2080,  2086,  2093,  2093,
    2095,  2097,  2099,  2103,  2103,  2111,  2117,  2124,  2124,  2126,
    2128,  2130,  2134,  2134,  2145,  2150,  2158,  2163,  2169,  2169,
    2171,  2173,  2177,  2177,  2179,  2184,  2193,  2199,  2199,  2202,
    2212,  2218,  2218,  2222,  2222,  2224,  2230,  2238,  2242,  2247,
    2247,  2249,  2251,  2251,  2253,  2267,  2277,  2285,  2285,  2288,
    2289,  2296,  2299,  2299,  2301,  2301,  2303,  2308,  2308,  2310,
    2315,  2337,  2354,  2354,  2357,  2361,  2365,  2366,  2367,  2368,
    2369,  2370,  2373,  2373,  2375,  2375,  2377,  2379,  2379,  2381,
    2381,  2384,  2397,  2410,  2412,  2412,  2415,  2425,  2426,  2427,
    2430,  2432,  2432,  2440,  2440,  2442,  2445,  2452,  2452,  2457,
    2457,  2459,  2461,  2463,  2467,  2467,  2478,  2484,  2492,  2497,
    2503,  2503,  2505,  2507,  2509,  2509,  2512,  2517,  2526,  2532,
    2532,  2535,  2545,  2552,  2552,  2555,  2555,  2568,  2573,  2582,
    2587,  2593,  2593,  2595,  2597,  2599,  2599,  2602,  2607,  2619,
    2626,  2626,  2629,  2639,  2644,  2650,  2650,  2654,  2654,  2656,
    2658,  2658,  2660,  2662,  2664,  2667,  2667,  2675,  2681,  2688,
    2688,  2690,  2692,  2694,  2697,  2697,  2705,  2711,  2718,  2718,
    2720,  2722,  2724,  2727,  2727,  2735,  2741,  2748,  2748,  2750,
    2752,  2754,  2757,  2757,  2765,  2771,  2778,  2778,  2780,  2782,
    2784,  2787,  2787,  2795,  2802,  2809,  2809,  2811,  2813,  2815,
    2819,  2819,  2827,  2833,  2840,  2840,  2842,  2844,  2846,  2850,
    2850,  2852,  2858,  2880,  2897,  2897,  2900,  2904,  2908,  2909,
    2910,  2911,  2912,  2913,  2916,  2916,  2918,  2918,  2920,  2922,
    2922,  2924,  2924,  2927,  2940,  2954,  2962,  2962,  2965,  2975,
    2976,  2977,  2980,  2982,  2982,  2990,  2990,  2992,  2997,  3004,
    3004,  3009,  3009,  3011,  3013,  3015,  3019,  3019,  3030,  3035,
    3043,  3048,  3054,  3054,  3056,  3058,  3060,  3060,  3063,  3068,
    3076,  3076,  3079,  3090,  3097,  3097,  3101,  3101,  3114,  3119,
    3128,  3133,  3139,  3139,  3141,  3143,  3145,  3145,  3148,  3153,
    3164,  3170,  3170,  3173,  3184,  3185,  3188,  3188,  3192,  3192,
    3194,  3196,  3196,  3198,  3200,  3202,  3205,  3205,  3213,  3219,
    3226,  3226,  3228,  3230,  3232,  3235,  3235,  3243,  3249,  3256,
    3256,  3258,  3260,  3262,  3266,  3266,  3274,  3280,  3287,  3287,
    3289,  3291,  3293,  3297,  3297,  3305,  3311,  3318,  3318,  3320,
    3322,  3324,  3328,  3328,  3336,  3342,  3349,  3349,  3351,  3353,
    3355,  3359,  3359,  3367,  3373,  3380,  3380,  3382,  3384,  3386,
    3390,  3390,  3392,  3398,  3420,  3437,  3437,  3440,  3444,  3448,
    3449,  3450,  3451,  3452,  3453,  3456,  3456,  3458,  3458,  3460,
    3462,  3462,  3464,  3464,  3467,  3480,  3493,  3495,  3495,  3498,
    3508,  3509,  3510,  3513,  3515,  3515,  3523,  3523,  3525,  3527,
    3535,  3540,  3546,  3548,  3550,  3550,  3554,  3573,  3591,  3597,
    3597,  3600,  3601,  3602,  3603,  3604,  3605,  3606,  3613,  3617,
    3622,  3622,  3624,  3626,  3628,  3628,  3630,  3637,  3643,  3645,
    3645,  3647,  3649,  3660,  3669,  3679,  3684,  3684,  3687,  3688,
    3689,  3691,  3699,  3707,  3715,  3715,  3721,  3728,  3728,  3730,
    3735,  3742,  3749,  3749,  3751,  3754,  3761,  3768,  3775,  3782,
    3784,  3790,  3797,  3797,  3799,  3804,  3811,  3817,  3817,  3819,
    3822,  3827,  3833,  3833,  3835,  3838,  3845,  3851,  3851,  3853,
    3856,  3863,  3869,  3871,  3879,  3885,  3885,  3887,  3890,  3897,
    3904,  3904,  3906,  3911,  3918,  3924,  3924,  3926,  3929,  3936,
    3942,  3942,  3944,  3947,  3954,  3960,  3960,  3962,  3965,  3977,
    3986,  3995,  4004,  4013,  4022,  4031,  4040,  4048,  4054,  4060,
    4066,  4072,  4083,  4092,  4102,  4108,  4117,  4137,  4137,  4139,
    4156,  4167,  4174,  4174,  4177,  4184,  4185,  4189,  4189,  4191,
    4193,  4195,  4212,  4217,  4219,  4219,  4221,  4223,  4232,  4234,
    4234,  4236,  4236,  4238,  4246,  4248,  4253,  4253,  4255,  4255,
    4257,  4279,  4287,  4301,  4302,  4309,  4311,  4311,  4313,  4314,
    4315,  4316
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
  "osolAttributes", "osolContent", "osolEmpty", "osolLaden", "osolBody",
  "headerElement", "headerElementStart", "headerElementContent",
  "headerElementEmpty", "headerElementLaden", "headerElementBody",
  "fileName", "fileNameContent", "fileNameEmpty", "fileNameLaden",
  "fileSource", "fileSourceContent", "fileSourceEmpty", "fileSourceLaden",
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
     239,   240,   241,   242,   242,   243,   244,   244,   245,   246,
     247,   248,   248,   249,   249,   250,   250,   251,   252,   252,
     253,   253,   254,   254,   255,   256,   256,   257,   257,   258,
     258,   259,   260,   260,   261,   261,   262,   262,   263,   264,
     264,   265,   265,   266,   266,   267,   268,   268,   269,   270,
     270,   271,   271,   272,   273,   274,   274,   275,   275,   275,
     275,   275,   275,   275,   275,   275,   275,   275,   276,   277,
     278,   278,   279,   279,   280,   281,   282,   283,   284,   284,
     285,   285,   286,   287,   288,   289,   290,   290,   291,   291,
     292,   293,   294,   295,   296,   296,   297,   298,   298,   299,
     299,   300,   301,   302,   303,   304,   304,   305,   305,   306,
     307,   308,   309,   310,   310,   311,   311,   312,   313,   314,
     315,   316,   316,   317,   317,   318,   319,   320,   321,   322,
     322,   323,   323,   324,   325,   326,   327,   328,   328,   329,
     329,   330,   331,   332,   333,   334,   334,   335,   336,   336,
     337,   337,   338,   339,   340,   341,   342,   343,   343,   344,
     344,   345,   346,   347,   347,   348,   349,   350,   351,   351,
     352,   352,   352,   353,   353,   354,   354,   355,   356,   356,
     357,   357,   358,   359,   360,   360,   361,   361,   361,   361,
     361,   362,   363,   364,   365,   365,   366,   366,   367,   368,
     369,   370,   371,   372,   372,   373,   373,   374,   375,   376,
     377,   378,   379,   379,   380,   380,   381,   382,   383,   384,
     385,   385,   386,   387,   388,   389,   390,   391,   391,   392,
     392,   393,   394,   395,   395,   396,   397,   398,   399,   399,
     400,   400,   400,   401,   401,   402,   402,   403,   404,   404,
     405,   405,   406,   407,   408,   408,   409,   409,   410,   411,
     412,   412,   413,   413,   414,   415,   416,   417,   418,   419,
     419,   420,   420,   421,   422,   423,   423,   424,   425,   426,
     427,   427,   428,   428,   428,   429,   429,   430,   430,   431,
     432,   432,   433,   433,   434,   435,   436,   436,   437,   437,
     437,   437,   437,   437,   437,   437,   437,   437,   437,   437,
     437,   437,   437,   438,   439,   440,   441,   441,   442,   442,
     443,   444,   445,   446,   447,   448,   448,   449,   449,   450,
     451,   452,   453,   454,   455,   455,   456,   456,   457,   458,
     458,   459,   460,   461,   462,   463,   463,   464,   464,   465,
     466,   466,   467,   468,   469,   470,   471,   471,   472,   472,
     473,   474,   474,   475,   476,   477,   478,   479,   479,   480,
     480,   481,   482,   482,   483,   484,   485,   486,   487,   487,
     488,   488,   489,   490,   490,   491,   492,   493,   494,   495,
     495,   496,   496,   497,   498,   498,   499,   500,   501,   502,
     503,   503,   504,   504,   505,   506,   506,   507,   508,   509,
     510,   511,   511,   512,   512,   513,   514,   514,   515,   516,
     517,   518,   519,   519,   520,   520,   521,   522,   522,   523,
     524,   525,   526,   527,   527,   528,   528,   529,   530,   530,
     531,   532,   533,   534,   535,   535,   536,   536,   537,   538,
     538,   539,   540,   541,   542,   543,   543,   544,   544,   545,
     546,   546,   547,   548,   549,   550,   551,   551,   552,   552,
     553,   554,   555,   555,   556,   557,   558,   559,   559,   560,
     560,   560,   561,   561,   562,   562,   563,   564,   565,   565,
     566,   566,   566,   567,   567,   568,   569,   570,   571,   571,
     572,   573,   574,   574,   575,   575,   576,   577,   578,   579,
     579,   580,   581,   582,   582,   583,   583,   584,   585,   586,
     586,   587,   588,   589,   589,   590,   590,   591,   591,   592,
     592,   593,   594,   595,   595,   596,   596,   597,   598,   599,
     599,   600,   601,   602,   603,   603,   604,   604,   605,   605,
     606,   606,   607,   608,   608,   609,   610,   611,   612,   612,
     613,   614,   615,   615,   616,   617,   618,   619,   619,   620,
     621,   622,   622,   623,   624,   625,   626,   626,   627,   628,
     629,   629,   630,   631,   632,   633,   633,   634,   635,   636,
     636,   637,   638,   639,   640,   640,   641,   642,   643,   643,
     644,   645,   646,   647,   647,   648,   649,   650,   650,   651,
     652,   653,   654,   654,   655,   656,   657,   657,   658,   658,
     659,   660,   661,   661,   662,   663,   664,   665,   665,   666,
     666,   667,   667,   668,   668,   669,   670,   671,   671,   672,
     672,   673,   674,   674,   675,   676,   677,   678,   678,   679,
     679,   679,   680,   680,   681,   681,   682,   683,   683,   684,
     685,   686,   687,   687,   688,   688,   688,   688,   688,   688,
     688,   688,   689,   689,   690,   690,   691,   692,   692,   693,
     693,   694,   695,   696,   697,   697,   698,   698,   698,   698,
     699,   700,   700,   701,   701,   702,   703,   704,   704,   705,
     705,   706,   707,   708,   709,   709,   710,   711,   712,   712,
     713,   713,   714,   715,   716,   716,   717,   718,   719,   720,
     720,   721,   721,   722,   722,   723,   723,   724,   725,   726,
     726,   727,   727,   728,   729,   730,   730,   731,   732,   733,
     734,   734,   735,   735,   735,   736,   736,   737,   737,   738,
     739,   739,   740,   741,   742,   743,   743,   744,   745,   746,
     746,   747,   748,   749,   750,   750,   751,   752,   753,   753,
     754,   755,   756,   757,   757,   758,   759,   760,   760,   761,
     762,   763,   764,   764,   765,   766,   767,   767,   768,   769,
     770,   771,   771,   772,   773,   774,   774,   775,   776,   777,
     778,   778,   779,   780,   781,   781,   782,   783,   784,   785,
     785,   786,   787,   788,   789,   789,   790,   790,   790,   790,
     790,   790,   790,   790,   791,   791,   792,   792,   793,   794,
     794,   795,   795,   796,   797,   798,   799,   799,   800,   800,
     800,   800,   801,   802,   802,   803,   803,   804,   805,   806,
     806,   807,   807,   808,   809,   810,   811,   811,   812,   813,
     814,   814,   815,   815,   816,   817,   818,   818,   819,   820,
     821,   821,   822,   822,   823,   823,   824,   824,   825,   826,
     827,   827,   828,   828,   829,   830,   831,   831,   832,   833,
     834,   835,   835,   836,   836,   836,   837,   837,   838,   838,
     839,   840,   840,   841,   842,   843,   844,   844,   845,   846,
     847,   847,   848,   849,   850,   851,   851,   852,   853,   854,
     854,   855,   856,   857,   858,   858,   859,   860,   861,   861,
     862,   863,   864,   865,   865,   866,   867,   868,   868,   869,
     870,   871,   872,   872,   873,   874,   875,   875,   876,   877,
     878,   879,   879,   880,   881,   882,   882,   883,   884,   885,
     886,   886,   887,   888,   889,   890,   890,   891,   891,   891,
     891,   891,   891,   891,   891,   892,   892,   893,   893,   894,
     895,   895,   896,   896,   897,   898,   899,   900,   900,   901,
     901,   901,   901,   902,   903,   903,   904,   904,   905,   906,
     907,   907,   908,   909,   910,   910,   911,   912,   913,   914,
     914,   915,   915,   915,   915,   915,   915,   915,   916,   916,
     917,   917,   918,   919,   920,   920,   921,   922,   922,   923,
     923,   924,   925,   926,   927,   928,   929,   929,   930,   930,
     930,   931,   932,   933,   934,   934,   935,   936,   936,   937,
     938,   939,   940,   940,   941,   942,   943,   944,   945,   946,
     947,   948,   949,   949,   950,   951,   952,   953,   953,   954,
     955,   956,   957,   957,   958,   959,   960,   961,   961,   962,
     963,   964,   965,   966,   967,   968,   968,   969,   970,   971,
     972,   972,   973,   974,   975,   976,   976,   977,   978,   979,
     980,   980,   981,   982,   983,   984,   984,   985,   986,   987,
     988,   989,   990,   991,   992,   993,   994,   995,   996,   997,
     998,   999,  1000,  1001,  1002,  1003,  1004,  1005,  1005,  1006,
    1007,  1008,  1009,  1009,  1010,  1010,  1010,  1011,  1011,  1012,
    1013,  1014,  1015,  1015,  1016,  1016,  1017,  1018,  1019,  1020,
    1020,  1021,  1021,  1022,  1023,  1024,  1025,  1025,  1026,  1026,
    1027,  1028,  1029,  1030,  1030,  1031,  1032,  1032,  1033,  1033,
    1033,  1033
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     3,     3,     1,     1,     0,     1,     1,     1,
       1,     3,     6,     0,     2,     1,     1,     1,     1,     3,
       5,     0,     1,     1,     1,     1,     1,     3,     0,     1,
       1,     1,     1,     1,     3,     0,     1,     1,     1,     1,
       1,     3,     0,     1,     1,     1,     1,     1,     3,     0,
       1,     1,     1,     1,     1,     3,     0,     2,     1,     1,
       1,     2,     1,     3,     1,     1,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     2,     1,
       1,     1,     2,     1,     3,     1,     2,     1,     1,     1,
       2,     1,     3,     1,     2,     1,     1,     1,     2,     1,
       3,     1,     3,     1,     0,     1,     3,     1,     1,     2,
       1,     3,     1,     2,     1,     1,     1,     2,     1,     3,
       1,     2,     1,     1,     1,     2,     1,     3,     1,     2,
       1,     1,     1,     2,     1,     3,     1,     2,     1,     1,
       1,     2,     1,     3,     1,     2,     1,     1,     1,     2,
       1,     3,     1,     3,     1,     0,     1,     3,     1,     1,
       2,     1,     3,     1,     3,     1,     1,     1,     1,     2,
       1,     3,     1,     1,     2,     3,     1,     1,     0,     2,
       1,     1,     1,     2,     1,     0,     2,     1,     1,     1,
       2,     1,     3,     1,     1,     2,     1,     1,     1,     1,
       1,     3,     1,     1,     0,     2,     1,     1,     3,     1,
       3,     1,     1,     0,     2,     1,     1,     3,     1,     3,
       1,     1,     0,     2,     1,     1,     3,     1,     3,     1,
       0,     1,     3,     1,     3,     1,     1,     1,     1,     2,
       1,     3,     1,     1,     2,     3,     1,     1,     0,     2,
       1,     1,     1,     2,     1,     0,     2,     1,     1,     1,
       2,     1,     3,     1,     1,     2,     1,     1,     2,     1,
       1,     1,     2,     1,     3,     1,     3,     1,     1,     1,
       1,     2,     1,     3,     1,     1,     2,     3,     1,     1,
       0,     2,     1,     1,     1,     2,     1,     0,     2,     1,
       1,     1,     2,     1,     3,     1,     1,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     3,     1,     1,     1,     1,     2,     1,
       3,     1,     1,     2,     1,     1,     1,     2,     1,     3,
       1,     3,     1,     1,     1,     1,     2,     1,     3,     1,
       2,     4,     3,     1,     1,     1,     1,     2,     1,     3,
       1,     2,     4,     3,     1,     1,     1,     1,     2,     1,
       3,     1,     2,     4,     3,     1,     1,     1,     1,     2,
       1,     3,     1,     2,     4,     3,     1,     1,     1,     1,
       2,     1,     3,     1,     2,     4,     3,     1,     1,     1,
       1,     2,     1,     3,     1,     2,     1,     3,     1,     1,
       1,     1,     2,     1,     3,     1,     2,     1,     3,     1,
       1,     1,     1,     2,     1,     3,     1,     2,     1,     3,
       1,     1,     1,     1,     2,     1,     3,     1,     2,     1,
       3,     1,     1,     1,     1,     2,     1,     3,     1,     2,
       4,     3,     1,     1,     1,     1,     2,     1,     3,     1,
       2,     4,     3,     1,     1,     1,     1,     2,     1,     3,
       1,     2,     4,     3,     1,     1,     1,     1,     2,     1,
       3,     1,     1,     2,     3,     1,     1,     0,     2,     1,
       1,     1,     2,     1,     0,     3,     1,     1,     0,     2,
       1,     1,     1,     1,     1,     1,     3,     4,     0,     3,
       1,     1,     0,     1,     1,     1,     1,     3,     6,     0,
       3,     1,     1,     1,     1,     2,     1,     3,     1,     1,
       2,     3,     1,     0,     2,     1,     1,     2,     1,     0,
       3,     1,     1,     1,     1,     2,     1,     3,     1,     1,
       2,     3,     1,     1,     0,     2,     1,     1,     2,     1,
       0,     2,     1,     1,     1,     1,     3,     6,     0,     3,
       1,     1,     1,     1,     1,     3,     1,     0,     3,     1,
       1,     1,     1,     1,     3,     1,     0,     3,     1,     1,
       1,     1,     1,     3,     1,     0,     3,     1,     1,     1,
       1,     1,     3,     1,     0,     3,     1,     1,     1,     1,
       1,     3,     1,     0,     3,     1,     1,     1,     1,     1,
       3,     1,     0,     3,     1,     1,     1,     1,     2,     1,
       3,     1,     1,     2,     3,     1,     1,     0,     2,     1,
       1,     2,     1,     0,     3,     1,     4,     1,     1,     2,
       1,     3,     1,     2,     3,     1,     1,     0,     2,     1,
       1,     1,     1,     1,     2,     1,     3,     0,     2,     3,
       1,     1,     0,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     2,     1,     3,     1,     1,     1,
       2,     3,     1,     1,     0,     2,     1,     1,     1,     1,
       1,     2,     1,     0,     3,     1,     1,     0,     1,     1,
       1,     1,     3,     4,     0,     3,     1,     1,     1,     1,
       2,     1,     3,     1,     1,     2,     3,     1,     1,     0,
       2,     1,     1,     2,     1,     0,     3,     1,     1,     1,
       1,     2,     1,     3,     1,     1,     2,     3,     1,     1,
       0,     2,     1,     1,     1,     2,     1,     0,     2,     1,
       1,     1,     1,     3,     6,     0,     3,     1,     1,     1,
       1,     1,     3,     1,     0,     3,     1,     1,     1,     1,
       1,     3,     1,     0,     3,     1,     1,     1,     1,     1,
       3,     1,     0,     3,     1,     1,     1,     1,     1,     3,
       1,     0,     3,     1,     1,     1,     1,     1,     3,     1,
       0,     3,     1,     1,     1,     1,     1,     3,     1,     0,
       2,     3,     1,     1,     0,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     2,     1,     3,     1,
       1,     1,     2,     3,     1,     1,     0,     2,     1,     1,
       1,     1,     1,     2,     1,     0,     3,     1,     1,     0,
       1,     1,     1,     1,     3,     4,     0,     3,     1,     1,
       1,     1,     2,     1,     3,     1,     1,     2,     3,     1,
       0,     2,     1,     1,     2,     1,     0,     3,     1,     1,
       1,     1,     2,     1,     3,     1,     1,     2,     3,     1,
       1,     0,     2,     1,     1,     1,     2,     1,     0,     2,
       1,     1,     1,     1,     3,     6,     0,     3,     1,     1,
       1,     1,     1,     3,     1,     0,     3,     1,     1,     1,
       1,     1,     3,     1,     0,     3,     1,     1,     1,     1,
       1,     3,     1,     0,     3,     1,     1,     1,     1,     1,
       3,     1,     0,     3,     1,     1,     1,     1,     1,     3,
       1,     0,     3,     1,     1,     1,     1,     1,     3,     1,
       0,     2,     3,     1,     1,     0,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     2,     1,     3,
       1,     1,     1,     2,     3,     1,     1,     0,     2,     1,
       1,     1,     1,     1,     2,     1,     0,     3,     1,     1,
       1,     1,     1,     3,     0,     2,     3,     1,     1,     1,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       2,     1,     3,     1,     1,     2,     1,     1,     1,     1,
       1,     3,     1,     3,     1,     1,     0,     2,     1,     1,
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
       0,     5,     4,     0,    13,     6,     1,    15,     0,    56,
       0,     7,     0,     2,    58,   185,     0,    21,    18,    14,
      16,    17,    13,    10,     3,     8,     9,   187,   255,     0,
       0,    62,    57,    59,    60,     0,    26,    25,     0,    28,
      22,    23,    24,     0,   257,   297,     0,     0,   191,   186,
     188,   189,    61,    79,    87,    95,   103,   114,   122,   130,
     138,   146,   154,   165,     0,    64,    65,    67,     0,    68,
       0,    69,     0,    70,   104,    71,     0,    72,     0,    73,
       0,    74,     0,    75,     0,    76,   155,    77,     0,     0,
      19,     0,    33,    32,    35,    29,    30,    31,    11,   299,
     494,     0,     0,   261,   256,   258,   259,   190,   235,   202,
     211,   220,   229,     0,   193,   194,   196,   204,   197,   213,
     198,   222,   199,   230,   200,     0,    63,    66,     0,    83,
      78,    80,    81,     0,    91,    86,    88,    89,     0,    99,
      94,    96,    97,     0,     0,   105,     0,   118,   113,   115,
     116,     0,   126,   121,   123,   124,     0,   134,   129,   131,
     132,     0,   142,   137,   139,   140,     0,   150,   145,   147,
     148,     0,     0,   156,  1176,     0,   166,    27,     0,     0,
      40,    39,    42,    36,    37,    38,   496,    12,   498,     0,
     303,   298,   300,   301,   260,   277,   269,     0,   263,   264,
     266,     0,   267,     0,   192,   195,     0,   203,     0,   212,
       0,   221,     0,  1064,     0,   231,  1061,  1062,  1063,     0,
     236,    85,    82,     0,    93,    90,     0,   101,    98,     0,
       0,     0,   110,   102,   107,   108,   120,   117,     0,   128,
     125,     0,   136,   133,     0,   144,   141,     0,   152,   149,
       0,     0,     0,   161,   153,   158,   159,     0,     0,     0,
     170,   164,   167,   168,    34,     0,     0,    47,    46,    49,
      43,    44,    45,     0,   497,   302,   474,   324,   334,   342,
     353,   364,   375,   386,   452,   441,   397,   408,   430,   419,
     463,     0,   305,   306,   308,     0,   309,     0,   310,     0,
     311,     0,   312,     0,   313,     0,   314,     0,   315,     0,
     316,     0,   318,     0,   317,     0,   319,     0,   320,     0,
     321,     0,   322,     0,   262,   265,     0,   273,   268,   270,
     271,     0,   278,     0,   201,     0,  1112,   205,   207,   206,
    1109,  1110,  1111,     0,   210,   214,   216,   215,     0,   219,
     223,   225,   224,  1176,     0,   228,     0,   240,   234,   237,
     238,    84,    92,   100,   106,   112,   109,     0,   119,   127,
     135,   143,   151,   157,   163,   160,     0,  1176,  1175,  1178,
    1179,  1180,  1181,  1177,   169,   176,     0,   172,   173,   178,
      41,     0,     0,    54,    53,    20,    50,    51,    52,   508,
     505,   495,   503,   504,  1176,  1176,  1176,   499,   501,   502,
     500,   304,   307,     0,   325,     0,   338,   333,   335,   336,
       0,     0,   343,     0,     0,   354,     0,   365,     0,   376,
       0,   387,     0,     0,   398,     0,   409,     0,   420,     0,
     431,     0,   442,     0,   453,     0,     0,   464,     0,   475,
     275,   272,     0,     0,   282,   276,   279,   280,  1173,  1174,
       0,   209,     0,     0,   218,     0,   227,  1065,   233,     0,
     239,   246,     0,   242,   243,   248,   111,   162,  1129,   171,
     174,     0,   177,    48,     0,   510,     0,   703,   512,     0,
       0,     0,     0,   329,   323,   326,   327,   340,   337,     0,
       0,     0,   347,   341,   344,   345,     0,     0,   358,   352,
     355,   356,     0,   369,   363,   366,   367,     0,   380,   374,
     377,   378,     0,   391,   385,   388,   389,     0,     0,   402,
     396,   399,   400,     0,   413,   407,   410,   411,     0,   424,
     418,   421,   422,     0,   435,   429,   432,   433,     0,   446,
     440,   443,   444,     0,   457,   451,   454,   455,     0,     0,
     468,   462,   465,   466,     0,   479,   473,   476,   477,   274,
     281,   288,     0,   284,   285,   290,   208,  1113,   217,   226,
     232,   241,   244,     0,   247,     0,   184,   175,     0,     0,
    1084,  1117,   179,   182,   180,  1081,  1082,  1083,   181,  1114,
    1115,  1116,    55,   506,   705,   855,   707,  1176,     0,   511,
     513,  1176,  1176,  1176,   328,     0,   331,   332,   339,     0,
       0,   346,     0,   349,     0,   357,     0,     0,   360,   368,
       0,     0,   371,     0,   379,     0,   382,     0,   390,     0,
     393,     0,  1044,   401,     0,   404,   406,  1046,   412,     0,
     415,   417,   423,     0,   426,   428,   434,     0,   437,   439,
       0,   445,     0,   448,     0,   456,     0,   459,     0,   467,
       0,     0,   470,   478,   485,     0,   481,   482,   487,   283,
     286,     0,   289,     0,   254,   245,   249,   252,   250,   251,
     183,  1176,     0,   857,  1006,   859,  1176,     0,   706,   708,
       0,   519,   516,   509,   514,   515,  1136,  1126,  1120,   330,
    1124,     0,   348,   350,  1132,     0,   359,   361,     0,   370,
     372,     0,   381,   383,     0,   392,   394,  1131,   403,   405,
       0,  1045,   414,   416,   425,   427,   436,   438,     0,   447,
     449,     0,   458,   460,  1133,     0,   469,   471,   480,   483,
       0,   486,     0,   296,   287,   291,   294,   292,   293,   253,
    1085,  1118,  1008,   507,     0,  1176,     0,   858,   860,     0,
     714,   711,   704,   709,   710,  1176,   521,     0,   539,     0,
       0,     0,     0,     0,     0,     0,  1055,  1043,     0,     0,
       0,  1047,  1048,  1049,  1050,     0,     0,     0,     0,   493,
     484,   488,   491,   489,   490,   295,  1176,     0,  1009,     0,
     866,   863,   856,   861,   862,  1176,   716,     0,   735,     0,
    1130,   517,   541,   560,     0,  1176,     0,   522,   351,   362,
     373,   384,   395,  1054,     0,     0,     0,   450,   461,   472,
     492,     0,  1014,  1012,  1007,  1010,  1011,  1176,   868,     0,
     886,     0,  1128,   712,   737,   757,     0,  1176,     0,   717,
     562,   622,     0,     0,   542,     0,     0,   526,   520,   523,
     524,  1051,  1052,  1053,  1176,     0,  1127,   864,   888,   908,
       0,  1176,     0,   869,   759,   819,     0,     0,   738,     0,
       0,   721,   715,   718,   719,   624,   643,     0,   568,   565,
     561,   563,   564,     0,   546,   540,   543,   544,  1176,   525,
     532,     0,   528,   529,   533,  1134,  1013,  1017,  1015,     0,
     910,   970,     0,     0,   889,     0,     0,   873,   867,   870,
     871,   713,   765,   762,   758,   760,   761,     0,   742,   736,
     739,   740,  1176,   720,   727,     0,   723,   724,   729,   645,
     667,     0,     0,   625,   570,     0,   577,     0,   552,   545,
       0,   548,   549,   554,  1135,   527,   530,     0,     0,     0,
    1176,  1097,  1059,     0,  1089,     0,  1018,  1019,  1024,  1056,
    1057,  1058,  1026,  1021,  1023,  1086,  1087,  1088,  1025,  1094,
    1095,  1096,  1022,  1027,   865,   916,   913,   909,   911,   912,
       0,   893,   887,   890,   891,  1176,   872,   879,     0,   875,
     876,   880,   822,   820,   824,   767,     0,   774,     0,   748,
     741,     0,   744,   745,   750,  1125,   722,   725,     0,   728,
     518,     0,     0,     0,   629,   623,   626,   627,   566,   579,
     586,     0,  1176,     0,   571,   547,   550,     0,   553,     0,
     538,  1176,   534,   531,   535,  1068,  1069,   536,  1176,     0,
       0,  1176,     0,  1031,  1016,  1028,  1029,  1020,   973,   971,
     975,   918,     0,   925,     0,   899,   892,     0,   895,   896,
     901,  1119,   874,   877,     0,     0,   823,   763,   776,   783,
       0,     0,   768,   743,   746,     0,   749,     0,   734,   726,
     730,   731,   732,   670,   668,   672,     0,     0,   650,   644,
     647,   648,   635,   628,     0,   631,   632,   637,   588,   595,
       0,     0,   580,     0,  1154,   574,   569,   572,   573,     0,
     559,   551,   555,   556,   557,   537,     0,  1060,  1098,  1176,
    1090,  1030,  1040,     0,  1039,     0,  1033,  1034,  1036,  1037,
    1038,     0,   974,   914,   927,   934,     0,     0,   919,   894,
     897,     0,   900,     0,   885,   881,   878,   882,   883,     0,
     837,   821,   834,   835,  1176,   825,   831,   833,   828,   830,
     832,   829,   827,   826,   785,   792,     0,     0,   777,  1154,
     771,   766,   769,   770,     0,   756,   747,  1074,  1102,     0,
       0,   751,   752,   753,  1071,  1072,  1073,   754,  1099,  1100,
    1101,   733,     0,   671,     0,   649,   655,     0,   652,   657,
     630,   633,     0,   636,   597,   604,     0,     0,   589,  1154,
     583,   578,   581,   582,  1176,     0,     0,   576,  1152,  1153,
     558,  1176,  1123,  1042,     0,  1032,  1035,     0,   988,   972,
     985,   986,   976,   982,   984,   979,   981,   983,   980,   977,
     978,   936,   943,     0,     0,   928,  1154,   922,   917,   920,
     921,     0,   907,   898,  1079,  1107,  1176,  1176,   902,   903,
     904,  1076,  1077,  1078,   905,  1104,  1105,  1106,   884,   836,
     844,  1140,     0,   839,   841,   846,   840,  1137,  1142,     0,
     794,   801,     0,     0,   786,  1154,   780,   775,   778,   779,
       0,   773,   755,  1176,  1176,     0,   685,   669,   682,   683,
     673,   679,   681,   676,   678,   680,   677,   675,   674,   646,
     651,   653,     0,   656,     0,   642,   634,   638,   639,   640,
     606,   613,     0,     0,   598,  1154,   592,   587,   590,   591,
       0,   585,  1121,  1176,     0,   575,  1157,  1155,  1159,  1070,
    1041,   987,   995,     0,   990,   992,   997,   991,   945,   952,
       0,     0,   937,  1154,   931,   926,   929,   930,     0,   924,
     906,     0,     0,   838,   842,     0,   845,  1138,     0,  1141,
    1176,   803,   810,     0,     0,   795,  1154,   789,   784,   787,
     788,     0,   782,   772,  1075,  1103,   684,   692,     0,   687,
     689,   694,   688,     0,   665,   654,   662,   663,     0,  1176,
     658,   661,  1066,   659,  1091,  1092,   660,   641,   615,   567,
       0,     0,   607,  1154,   601,   596,   599,   600,     0,   594,
     584,     0,     0,  1169,  1164,  1166,  1167,     0,  1158,   989,
     993,     0,   996,   954,   961,     0,     0,   946,  1154,   940,
     935,   938,   939,     0,   933,   923,  1176,  1176,     0,   854,
     843,   852,   847,   848,   850,   851,   849,  1154,  1149,  1139,
    1147,  1148,  1146,  1145,  1144,  1143,  1122,   812,   764,     0,
       0,   804,  1154,   798,   793,   796,   797,     0,   791,   781,
     686,   690,     0,   693,   664,     0,     0,     0,     0,   616,
    1154,   610,   605,   608,   609,     0,   603,   593,  1176,     0,
    1168,     0,  1156,  1176,  1176,  1160,  1162,  1161,     0,  1005,
     994,  1003,   998,   999,  1001,  1002,  1000,   963,   915,     0,
       0,   955,  1154,   949,   944,   947,   948,     0,   942,   932,
    1080,  1108,   853,     0,  1151,     0,   813,  1154,   807,   802,
     805,   806,     0,   800,   790,     0,   702,   691,   700,   695,
     696,   698,   699,   697,   666,     0,  1176,  1154,   619,   614,
     617,   618,     0,   612,   602,  1165,  1170,     0,     0,     0,
    1004,     0,   964,  1154,   958,   953,   956,   957,     0,   951,
     941,  1150,  1154,   816,   811,   814,   815,     0,   809,   799,
     701,  1067,  1093,     0,   621,   611,  1163,  1176,  1176,  1154,
     967,   962,   965,   966,     0,   960,   950,     0,   818,   808,
     620,  1171,  1172,     0,   969,   959,   817,   968
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     3,     4,     5,    12,    24,    25,    26,     8,     9,
      10,    19,    20,    21,    38,    39,    40,    41,    42,    94,
      95,    96,    97,   182,   183,   184,   185,   269,   270,   271,
     272,   395,   396,   397,   398,    15,    16,    32,    33,    34,
      64,    65,    66,    67,    68,   130,   131,   132,   223,    69,
      70,   135,   136,   137,   226,    71,    72,   140,   141,   142,
     229,    73,    74,   144,   145,   233,   234,   235,   367,    75,
      76,   148,   149,   150,   238,    77,    78,   153,   154,   155,
     241,    79,    80,   158,   159,   160,   244,    81,    82,   163,
     164,   165,   247,    83,    84,   168,   169,   170,   250,    85,
      86,   172,   173,   254,   255,   256,   376,    87,    88,   175,
     261,   262,   263,   386,   387,   388,   389,   481,   482,   592,
     587,    28,    29,    49,    50,    51,   113,   114,   115,   116,
     117,   206,   207,   337,   334,   460,   118,   119,   208,   209,
     345,   344,   463,   120,   121,   210,   211,   350,   349,   465,
     122,   123,   214,   355,   469,   124,   125,   219,   358,   359,
     360,   472,   473,   474,   475,   583,   584,   686,   685,    45,
      46,   104,   105,   106,   197,   198,   199,   200,   201,   328,
     329,   330,   452,   202,   203,   331,   455,   456,   457,   572,
     573,   574,   575,   681,   682,   755,   754,   100,   101,   191,
     192,   193,   291,   292,   293,   294,   295,   413,   494,   495,
     496,   615,   616,   296,   297,   417,   418,   419,   499,   298,
     299,   421,   503,   504,   505,   622,   623,   300,   301,   424,
     509,   510,   511,   627,   628,   302,   303,   426,   514,   515,
     516,   631,   632,   304,   305,   428,   519,   520,   521,   635,
     636,   306,   307,   430,   524,   525,   526,   639,   640,   308,
     309,   433,   530,   531,   532,   644,   645,   310,   311,   435,
     535,   536,   537,   649,   650,   312,   313,   437,   540,   541,
     542,   653,   654,   314,   315,   439,   545,   546,   547,   657,
     658,   316,   317,   441,   550,   551,   552,   662,   663,   318,
     319,   443,   555,   556,   557,   666,   667,   320,   321,   446,
     561,   562,   563,   671,   672,   322,   323,   448,   566,   567,
     568,   675,   676,   677,   678,   750,   751,   801,   800,   187,
     188,   273,   274,   407,   401,   402,   403,   486,   487,   488,
     608,   609,   703,   704,   705,   777,   778,   779,   826,   868,
     869,   870,   911,   912,   913,   914,   967,  1052,  1053,   823,
     824,   863,   905,   906,   907,   960,   961,   962,   963,  1047,
    1048,  1132,  1131,   861,   862,   900,   901,   902,   955,   956,
     957,  1043,  1126,  1127,  1128,  1236,  1040,  1041,  1121,  1231,
    1232,  1233,  1350,  1119,  1120,  1227,  1347,  1348,  1349,  1438,
    1225,  1226,  1343,  1435,  1436,  1437,  1515,  1341,  1342,  1431,
    1512,  1513,  1514,  1582,  1429,  1430,  1508,  1579,  1580,  1581,
    1613,   896,   897,   952,  1035,  1036,  1037,  1114,  1115,  1116,
    1117,  1222,  1223,  1337,  1336,   950,   951,  1032,  1109,  1110,
    1111,  1217,  1218,  1219,  1332,  1333,  1420,  1415,  1416,  1417,
    1030,  1104,  1105,  1212,  1213,  1320,  1317,  1318,  1319,  1408,
    1409,  1410,  1411,  1502,  1503,  1569,  1567,  1568,   605,   606,
     697,   698,   772,   773,   774,   817,   818,   819,   858,   892,
     893,   894,   945,   946,   947,   948,  1028,  1029,  1100,  1099,
     855,   856,   887,   939,   940,   941,  1021,  1022,  1023,  1024,
    1095,  1096,  1201,  1196,   885,   886,   934,   935,   936,  1016,
    1017,  1018,  1091,  1191,  1192,  1193,  1310,  1089,  1090,  1187,
    1307,  1308,  1309,  1401,  1185,  1186,  1303,  1398,  1399,  1400,
    1497,  1301,  1302,  1394,  1494,  1495,  1496,  1562,  1392,  1393,
    1490,  1559,  1560,  1561,  1607,  1488,  1489,  1555,  1604,  1605,
    1606,  1627,   931,  1013,  1014,  1085,  1086,  1175,  1171,  1172,
    1173,  1292,  1293,  1294,  1295,  1385,  1386,  1472,  1470,  1471,
     694,   695,   766,   767,   812,   813,   814,   849,   850,   851,
     882,   928,   929,   930,  1008,  1009,  1010,  1011,  1084,  1165,
    1166,   879,   880,   923,  1002,  1003,  1004,  1077,  1078,  1079,
    1080,  1161,  1162,  1278,  1273,   921,   922,   997,   998,   999,
    1072,  1073,  1074,  1157,  1268,  1269,  1270,  1378,  1155,  1156,
    1264,  1375,  1376,  1377,  1463,  1262,  1263,  1371,  1460,  1461,
    1462,  1547,  1369,  1370,  1456,  1544,  1545,  1546,  1598,  1454,
    1455,  1540,  1595,  1596,  1597,  1624,  1538,  1539,  1591,  1621,
    1622,  1623,  1633,   994,  1069,  1070,  1151,  1152,  1252,  1249,
    1250,  1251,  1363,  1364,  1365,  1366,  1451,  1452,  1532,  1530,
    1531,   763,   764,   807,   844,   845,   846,   875,   918,   919,
     975,   976,   977,  1064,  1065,  1066,  1145,  1146,  1147,  1148,
    1149,  1150,  1244,   646,   647,   730,   731,   791,   792,   793,
     794,   787,   978,   979,   980,   981,   982,   216,   217,   218,
    1421,  1422,  1054,  1055,  1056,  1203,  1204,  1205,  1206,  1280,
    1281,  1282,  1283,   983,   595,   596,   597,   984,   985,   986,
     987,  1423,  1424,  1425,   988,   989,   990,   991,  1207,  1208,
    1209,  1210,  1284,  1285,  1286,  1287,   339,   340,   341,   342,
     992,   599,   600,   601,   883,   408,  1044,  1182,   993,   422,
     859,   409,   768,   699,   176,   610,   434,   425,   447,   808,
     827,   410,  1296,  1297,  1298,  1388,  1389,  1485,  1479,  1480,
    1481,  1553,  1237,  1238,  1357,  1358,  1447,  1448,  1525,  1522,
    1239,  1354,  1444,  1445,  1446,  1526,  1527,   461,   257,   258,
     383
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -1364
static const yytype_int16 yypact[] =
{
     249, -1364, -1364,    61,     8,   146, -1364, -1364,   131,   174,
     310, -1364,   362, -1364, -1364,   133,   366,    20, -1364, -1364,
   -1364, -1364,     8, -1364, -1364, -1364, -1364, -1364,   147,   373,
     182, -1364, -1364, -1364, -1364,   246, -1364, -1364,   187,   191,
   -1364, -1364, -1364,   242, -1364,   200,   384,    -8, -1364, -1364,
   -1364, -1364, -1364, -1364, -1364, -1364, -1364, -1364, -1364, -1364,
   -1364, -1364, -1364, -1364,   212,   462, -1364, -1364,   390, -1364,
     397, -1364,   399, -1364,   218, -1364,   402, -1364,   409, -1364,
     411, -1364,   418, -1364,   420, -1364,   225, -1364,   270,   216,
   -1364,   287, -1364, -1364,   215, -1364, -1364, -1364, -1364, -1364,
     223,   422,   -22, -1364, -1364, -1364, -1364, -1364, -1364, -1364,
   -1364, -1364, -1364,   222,   121, -1364, -1364, -1364, -1364, -1364,
   -1364, -1364, -1364,   195, -1364,   270, -1364, -1364,    31, -1364,
   -1364, -1364, -1364,    41, -1364, -1364, -1364, -1364,    37, -1364,
   -1364, -1364, -1364,   304,   425, -1364,    30, -1364, -1364, -1364,
   -1364,    27, -1364, -1364, -1364, -1364,    24, -1364, -1364, -1364,
   -1364,    18, -1364, -1364, -1364, -1364,    17, -1364, -1364, -1364,
   -1364,   308,   433, -1364, -1364,   444, -1364, -1364,   231,   332,
   -1364, -1364,   241, -1364, -1364, -1364, -1364, -1364, -1364,    38,
   -1364, -1364, -1364, -1364, -1364, -1364, -1364,   271,   -60, -1364,
   -1364,   446, -1364,   270, -1364, -1364,   337,   273,   345,   273,
     352,   273,   348, -1364,   371, -1364, -1364, -1364, -1364,   449,
   -1364, -1364, -1364,   286, -1364, -1364,   290, -1364, -1364,   293,
     403,    29, -1364, -1364, -1364, -1364, -1364, -1364,   307, -1364,
   -1364,   314, -1364, -1364,   325, -1364, -1364,   355, -1364, -1364,
     323,   438,    16, -1364, -1364, -1364, -1364,   465,     5,   344,
   -1364, -1364, -1364, -1364, -1364,   388,   478, -1364, -1364,   272,
   -1364, -1364, -1364,   468,    93, -1364, -1364, -1364, -1364, -1364,
   -1364, -1364, -1364, -1364, -1364, -1364, -1364, -1364, -1364, -1364,
   -1364,   405,   333, -1364, -1364,   135, -1364,   487, -1364,   455,
   -1364,   470, -1364,   470, -1364,   470, -1364,   470, -1364,   471,
   -1364,   471, -1364,   471, -1364,   471, -1364,   470, -1364,   470,
   -1364,   466, -1364,   270, -1364, -1364,    15, -1364, -1364, -1364,
   -1364,   490, -1364,   496, -1364,   501, -1364, -1364, -1364, -1364,
   -1364, -1364, -1364,   496, -1364, -1364, -1364, -1364,   496, -1364,
   -1364, -1364, -1364, -1364,   489, -1364,   385, -1364, -1364, -1364,
   -1364, -1364, -1364, -1364, -1364, -1364, -1364,   432, -1364, -1364,
   -1364, -1364, -1364, -1364, -1364, -1364,   414, -1364, -1364, -1364,
   -1364, -1364, -1364, -1364, -1364, -1364,   424,   427, -1364, -1364,
   -1364,   474,   553, -1364, -1364, -1364, -1364, -1364, -1364,   395,
   -1364, -1364, -1364, -1364, -1364, -1364, -1364, -1364, -1364, -1364,
   -1364, -1364, -1364,   497, -1364,    12, -1364, -1364, -1364, -1364,
     556,   500, -1364,   562,   502, -1364,   504, -1364,   509, -1364,
     511, -1364,   564,   513, -1364,   517, -1364,   520, -1364,   525,
   -1364,   536, -1364,   540, -1364,   566,   542, -1364,   546, -1364,
   -1364, -1364,   448,   463, -1364, -1364, -1364, -1364, -1364, -1364,
     452, -1364,   570,   456, -1364,   475, -1364, -1364, -1364,   459,
   -1364, -1364,   485,   506, -1364, -1364, -1364, -1364, -1364, -1364,
   -1364,   575,   262, -1364,   636, -1364,   657,   541,   704,   732,
     733,   734,    11, -1364, -1364, -1364, -1364, -1364, -1364,   605,
     736,   -53, -1364, -1364, -1364, -1364,   738,   217, -1364, -1364,
   -1364, -1364,   445, -1364, -1364, -1364, -1364,    83, -1364, -1364,
   -1364, -1364,    80, -1364, -1364, -1364, -1364,   739,    55, -1364,
   -1364, -1364, -1364,   -42, -1364, -1364, -1364, -1364,   -80, -1364,
   -1364, -1364, -1364,   -92, -1364, -1364, -1364, -1364,    75, -1364,
   -1364, -1364, -1364,   -25, -1364, -1364, -1364, -1364,   740,   426,
   -1364, -1364, -1364, -1364,   472, -1364, -1364, -1364, -1364, -1364,
   -1364, -1364,   628,   626, -1364, -1364, -1364, -1364, -1364, -1364,
   -1364, -1364, -1364,   585,   262,   630, -1364, -1364,   746,   747,
   -1364, -1364, -1364, -1364, -1364, -1364, -1364, -1364, -1364, -1364,
   -1364, -1364, -1364, -1364, -1364,   548,   719, -1364,   587, -1364,
   -1364, -1364, -1364, -1364, -1364,   620, -1364, -1364, -1364,   748,
     745, -1364,   -44, -1364,   749, -1364,   750,   221, -1364, -1364,
     751,   457, -1364,   752, -1364,   130, -1364,   753, -1364,   110,
   -1364,   756, -1364, -1364,    77, -1364, -1364, -1364, -1364,   -38,
   -1364, -1364, -1364,   -62, -1364, -1364, -1364,   -64, -1364, -1364,
     755, -1364,    85, -1364,   757, -1364,    95, -1364,   758, -1364,
     759,   437, -1364, -1364, -1364,   638,   647, -1364, -1364, -1364,
   -1364,   598,   262,   637, -1364, -1364, -1364, -1364, -1364, -1364,
   -1364, -1364,   762, -1364,   560,   737, -1364,   600, -1364, -1364,
     767,   607, -1364, -1364, -1364, -1364, -1364, -1364, -1364, -1364,
   -1364,   770, -1364, -1364, -1364,   771, -1364, -1364,   773, -1364,
   -1364,   774, -1364, -1364,   775, -1364, -1364, -1364, -1364, -1364,
     602,   383, -1364, -1364, -1364, -1364, -1364, -1364,   776, -1364,
   -1364,   777, -1364, -1364, -1364,   778, -1364, -1364, -1364, -1364,
     604,   262,   661, -1364, -1364, -1364, -1364, -1364, -1364, -1364,
   -1364, -1364, -1364, -1364,   760, -1364,   606, -1364, -1364,   779,
     589, -1364, -1364, -1364, -1364, -1364, -1364,   616,   614,   761,
     681,   646,   649,   651,   653,   655, -1364, -1364,   789,   791,
     793, -1364, -1364, -1364, -1364,   658,   659,   634,   677, -1364,
   -1364, -1364, -1364, -1364, -1364, -1364, -1364,   608, -1364,   798,
     601, -1364, -1364, -1364, -1364, -1364, -1364,   609,   611,   769,
   -1364, -1364, -1364,   640,   761, -1364,   610, -1364, -1364, -1364,
   -1364, -1364, -1364, -1364,   800,   801,   802, -1364, -1364, -1364,
   -1364,   805, -1364, -1364, -1364, -1364, -1364, -1364, -1364,   612,
     618,   780, -1364, -1364, -1364,   642,   769, -1364,   613, -1364,
   -1364,   624,   615,   619, -1364,   808,   461, -1364, -1364, -1364,
   -1364, -1364, -1364, -1364, -1364,   421, -1364, -1364, -1364,   662,
     780, -1364,   625, -1364, -1364, -1364,   627,   629, -1364,   812,
     443, -1364, -1364, -1364, -1364, -1364,   631,   761,   644, -1364,
   -1364, -1364, -1364,   151, -1364, -1364, -1364, -1364, -1364, -1364,
   -1364,   663,   665, -1364, -1364, -1364, -1364, -1364, -1364,   493,
   -1364, -1364,   633,   635, -1364,   814,   441, -1364, -1364, -1364,
   -1364,   702,   667, -1364, -1364, -1364, -1364,   -18, -1364, -1364,
   -1364, -1364, -1364, -1364, -1364,   632,   669, -1364, -1364, -1364,
   -1364,   795,   639, -1364, -1364,   671,   673,   785, -1364, -1364,
     674,   675, -1364, -1364, -1364, -1364, -1364,   154,   825,   826,
   -1364, -1364, -1364,   828, -1364,   641,   493, -1364, -1364, -1364,
   -1364, -1364, -1364, -1364, -1364, -1364, -1364, -1364, -1364, -1364,
   -1364, -1364, -1364, -1364,   711,   679, -1364, -1364, -1364, -1364,
     164, -1364, -1364, -1364, -1364, -1364, -1364, -1364,   683,   684,
   -1364, -1364, -1364, -1364, -1364, -1364,   686,   688,   785, -1364,
   -1364,   690,   695, -1364, -1364, -1364, -1364, -1364,   643,    25,
     713,   827,   645,  -116, -1364, -1364, -1364, -1364, -1364, -1364,
     692,   785, -1364,   648, -1364, -1364, -1364,   650,    25,   693,
   -1364, -1364, -1364, -1364, -1364, -1364, -1364, -1364, -1364,   830,
     833, -1364,   132, -1364, -1364, -1364, -1364, -1364, -1364, -1364,
   -1364, -1364,   697,   699,   785, -1364, -1364,   700,   705, -1364,
   -1364, -1364, -1364, -1364,   172,   652,   292, -1364, -1364,   703,
     785,   654, -1364, -1364, -1364,   656,   114,   707, -1364, -1364,
   -1364, -1364, -1364, -1364, -1364, -1364,   834,   476, -1364, -1364,
   -1364, -1364, -1364, -1364,   709,   717, -1364, -1364, -1364,   715,
     785,   660, -1364,   835,   621, -1364, -1364, -1364, -1364,   723,
   -1364, -1364, -1364, -1364, -1364, -1364,   837, -1364, -1364, -1364,
   -1364, -1364, -1364,   840, -1364,   721,   109, -1364, -1364, -1364,
   -1364,   664,   341, -1364, -1364,   722,   785,   666, -1364, -1364,
   -1364,   668,   150,   724, -1364, -1364, -1364, -1364, -1364,   -86,
   -1364, -1364, -1364, -1364, -1364, -1364, -1364, -1364, -1364, -1364,
   -1364, -1364, -1364, -1364, -1364,   726,   785,   670, -1364,   621,
   -1364, -1364, -1364, -1364,   725, -1364, -1364, -1364, -1364,   846,
     847, -1364, -1364, -1364, -1364, -1364, -1364, -1364, -1364, -1364,
   -1364, -1364,   672,   401,   843, -1364, -1364,   492, -1364, -1364,
   -1364, -1364,   676,    25, -1364,   730,   785,   678, -1364,   621,
   -1364, -1364, -1364, -1364, -1364,   727,   741, -1364,   728, -1364,
   -1364, -1364, -1364, -1364,   729, -1364, -1364,   -85, -1364, -1364,
   -1364, -1364, -1364, -1364, -1364, -1364, -1364, -1364, -1364, -1364,
   -1364, -1364,   731,   785,   680, -1364,   621, -1364, -1364, -1364,
   -1364,   735, -1364, -1364, -1364, -1364, -1364, -1364, -1364, -1364,
   -1364, -1364, -1364, -1364, -1364, -1364, -1364, -1364, -1364, -1364,
   -1364, -1364,   742,   743, -1364, -1364,   744, -1364, -1364,   849,
   -1364,   754,   785,   682, -1364,   621, -1364, -1364, -1364, -1364,
     763, -1364, -1364, -1364, -1364,   -76, -1364, -1364, -1364, -1364,
   -1364, -1364, -1364, -1364, -1364, -1364, -1364, -1364, -1364, -1364,
   -1364, -1364,   685,    36,   764, -1364, -1364, -1364, -1364, -1364,
   -1364,   766,   785,   687, -1364,   621, -1364, -1364, -1364, -1364,
     765, -1364, -1364, -1364,   689, -1364, -1364, -1364, -1364, -1364,
   -1364, -1364, -1364,   768,   772, -1364, -1364,   744, -1364,   781,
     785,   691, -1364,   621, -1364, -1364, -1364, -1364,   782, -1364,
   -1364,   496,   496, -1364, -1364,   694,   214, -1364,   696,   175,
   -1364, -1364,   783,   785,   698, -1364,   621, -1364, -1364, -1364,
   -1364,   786, -1364, -1364, -1364, -1364, -1364, -1364,   792,   784,
   -1364, -1364,   744,  -124, -1364, -1364, -1364, -1364,   844, -1364,
   -1364, -1364, -1364, -1364, -1364, -1364, -1364, -1364, -1364, -1364,
     785,   701, -1364,   621, -1364, -1364, -1364, -1364,   787, -1364,
   -1364,   851,    10, -1364, -1364, -1364, -1364,   848,   491, -1364,
   -1364,   706,   214, -1364,   788,   785,   708, -1364,   621, -1364,
   -1364, -1364, -1364,   794, -1364, -1364, -1364, -1364,   790, -1364,
   -1364, -1364, -1364, -1364, -1364, -1364, -1364,   621, -1364, -1364,
   -1364, -1364, -1364, -1364, -1364, -1364, -1364, -1364, -1364,   785,
     710, -1364,   621, -1364, -1364, -1364, -1364,   797, -1364, -1364,
   -1364, -1364,   712,   214, -1364,  -122,   496,   853,   714, -1364,
     621, -1364, -1364, -1364, -1364,   796, -1364, -1364, -1364,   799,
   -1364,   854, -1364, -1364, -1364, -1364, -1364, -1364,   803, -1364,
   -1364, -1364, -1364, -1364, -1364, -1364, -1364, -1364, -1364,   785,
     716, -1364,   621, -1364, -1364, -1364, -1364,   804, -1364, -1364,
   -1364, -1364, -1364,   806, -1364,   718, -1364,   621, -1364, -1364,
   -1364, -1364,   807, -1364, -1364,   809, -1364, -1364, -1364, -1364,
   -1364, -1364, -1364, -1364, -1364,   845, -1364,   621, -1364, -1364,
   -1364, -1364,   810, -1364, -1364, -1364, -1364,   811,   855,   857,
   -1364,   720, -1364,   621, -1364, -1364, -1364, -1364,   813, -1364,
   -1364, -1364,   621, -1364, -1364, -1364, -1364,   816, -1364, -1364,
   -1364, -1364, -1364,   815, -1364, -1364, -1364, -1364, -1364,   621,
   -1364, -1364, -1364, -1364,   817, -1364, -1364,   818, -1364, -1364,
   -1364, -1364, -1364,   819, -1364, -1364, -1364, -1364
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
   -1364, -1364, -1364, -1364, -1364, -1364, -1364, -1364,   850, -1364,
   -1364, -1364, -1364, -1364, -1364, -1364, -1364, -1364, -1364, -1364,
   -1364, -1364, -1364, -1364, -1364, -1364, -1364, -1364, -1364, -1364,
   -1364, -1364, -1364, -1364, -1364, -1364, -1364, -1364, -1364, -1364,
   -1364, -1364,   820, -1364, -1364, -1364, -1364, -1364, -1364, -1364,
   -1364, -1364, -1364, -1364, -1364, -1364, -1364, -1364, -1364, -1364,
   -1364, -1364, -1364, -1364, -1364, -1364, -1364, -1364, -1364, -1364,
   -1364, -1364, -1364, -1364, -1364, -1364, -1364, -1364, -1364, -1364,
   -1364, -1364, -1364, -1364, -1364, -1364, -1364, -1364, -1364, -1364,
   -1364, -1364, -1364, -1364, -1364, -1364, -1364, -1364, -1364, -1364,
   -1364, -1364, -1364, -1364, -1364, -1364, -1364, -1364, -1364, -1364,
   -1364, -1364, -1364, -1364, -1364,   479, -1364, -1364, -1364, -1364,
   -1364, -1364, -1364, -1364, -1364, -1364, -1364, -1364,   824, -1364,
   -1364, -1364, -1364, -1364, -1364, -1364, -1364, -1364, -1364, -1364,
   -1364, -1364, -1364, -1364, -1364, -1364, -1364, -1364, -1364, -1364,
   -1364, -1364, -1364, -1364, -1364, -1364, -1364, -1364, -1364, -1364,
   -1364, -1364, -1364,   394, -1364, -1364, -1364, -1364, -1364, -1364,
   -1364, -1364, -1364, -1364, -1364, -1364,   821, -1364, -1364, -1364,
   -1364, -1364, -1364, -1364, -1364, -1364, -1364, -1364, -1364, -1364,
   -1364,   297, -1364, -1364, -1364, -1364, -1364, -1364, -1364, -1364,
   -1364, -1364, -1364, -1364,   582, -1364, -1364, -1364, -1364, -1364,
   -1364, -1364, -1364, -1364, -1364, -1364, -1364, -1364, -1364, -1364,
   -1364, -1364, -1364, -1364, -1364, -1364,   253, -1364, -1364, -1364,
   -1364, -1364, -1364, -1364,   250, -1364, -1364, -1364, -1364, -1364,
   -1364, -1364,   245, -1364, -1364, -1364, -1364, -1364, -1364, -1364,
     243, -1364, -1364, -1364, -1364, -1364, -1364, -1364,   240, -1364,
   -1364, -1364, -1364, -1364, -1364, -1364,   237, -1364, -1364, -1364,
   -1364, -1364, -1364, -1364,   234, -1364, -1364, -1364, -1364, -1364,
   -1364, -1364,   244, -1364, -1364, -1364, -1364, -1364, -1364, -1364,
     227, -1364, -1364, -1364, -1364, -1364, -1364, -1364,   236, -1364,
   -1364, -1364, -1364, -1364, -1364, -1364,   230, -1364, -1364, -1364,
   -1364, -1364, -1364, -1364,   232, -1364, -1364, -1364, -1364, -1364,
   -1364, -1364, -1364,   211, -1364, -1364, -1364, -1364, -1364, -1364,
   -1364, -1364, -1364, -1364, -1364, -1364, -1364, -1364, -1364, -1364,
   -1364, -1364, -1364, -1364, -1364, -1364, -1364, -1364, -1364, -1364,
   -1364, -1364, -1364, -1364,   -10, -1364, -1364, -1364, -1364, -1364,
   -1364, -1364, -1364, -1364, -1364, -1364, -1364,   -57, -1364, -1364,
   -1364, -1364, -1364, -1364, -1364, -1364, -1364, -1364, -1364, -1364,
   -1364, -1364, -1364, -1364, -1364, -1364, -1364, -1364, -1364, -1364,
   -1364, -1364, -1364, -1364, -1364, -1364, -1364, -1364, -1364, -1364,
   -1364, -1364, -1364, -1364, -1364, -1364, -1364, -1364, -1364, -1364,
   -1364, -1364, -1364, -1364, -1364, -1364, -1364, -1364, -1364, -1364,
   -1364, -1364, -1364, -1364, -1364, -1364, -1364, -1364,  -508, -1106,
   -1364, -1364, -1364, -1364, -1364, -1364, -1364, -1364, -1364, -1364,
   -1364, -1364,  -309, -1364, -1364, -1364, -1364, -1364, -1364, -1364,
   -1364, -1364, -1364, -1364, -1364, -1364, -1364, -1364, -1364, -1364,
   -1364,  -494, -1364, -1364, -1364, -1364, -1364, -1364, -1364, -1364,
   -1364, -1364, -1364, -1364, -1364, -1364, -1364, -1364, -1364, -1364,
   -1364, -1364, -1364, -1364,   -29, -1364, -1364, -1364, -1364, -1364,
   -1364, -1364, -1364, -1364, -1364, -1364, -1364, -1364,  -104, -1364,
   -1364, -1364, -1364, -1364, -1364, -1364, -1364, -1364, -1364, -1364,
   -1364, -1364, -1364, -1364, -1364, -1364, -1364, -1364, -1364, -1364,
   -1364, -1364, -1364, -1364, -1364, -1364, -1364, -1364, -1364, -1364,
   -1364, -1364, -1364, -1364, -1364, -1364, -1364, -1364, -1364, -1364,
   -1364, -1364, -1364, -1364, -1364, -1364, -1364, -1364, -1364, -1364,
   -1364, -1364, -1364, -1364, -1364, -1364, -1364, -1364, -1364, -1364,
   -1364, -1364, -1364,  -373, -1364, -1364, -1364, -1364, -1364, -1364,
   -1364, -1364, -1364, -1364, -1364, -1364, -1364, -1364, -1364, -1364,
   -1364, -1364, -1364, -1364, -1364, -1364,   -88, -1364, -1364, -1364,
   -1364, -1364, -1364, -1364, -1364, -1364, -1364, -1364, -1364,  -156,
   -1364, -1364, -1364, -1364, -1364, -1364, -1364, -1364, -1364, -1364,
   -1364, -1364, -1364, -1364, -1364, -1364, -1364, -1364, -1364, -1364,
   -1364, -1364, -1364, -1364, -1364, -1364, -1364, -1364, -1364, -1364,
   -1364, -1364, -1364, -1364, -1364, -1364, -1364, -1364, -1364, -1364,
   -1364, -1364, -1364, -1364, -1364, -1364, -1364, -1364, -1364, -1364,
   -1364, -1364, -1364, -1364, -1364, -1364, -1364, -1364, -1364, -1364,
   -1364, -1364, -1364, -1364,  -441, -1364, -1364, -1364, -1364, -1364,
   -1364, -1364, -1364, -1364, -1364, -1364, -1364, -1364, -1364, -1364,
   -1364, -1364,   -52, -1364, -1364, -1364, -1364, -1364,  -220, -1364,
   -1364, -1364, -1364,  -495, -1364, -1364, -1364, -1364, -1364, -1364,
   -1364, -1364, -1062, -1364, -1364, -1364,  -123, -1364, -1364, -1364,
   -1364, -1364, -1018, -1364, -1364, -1363, -1364, -1364, -1364, -1364,
   -1364, -1364, -1364,  -479, -1364, -1364, -1364, -1061, -1364, -1364,
   -1364, -1364, -1364, -1364, -1060, -1364, -1364, -1364, -1354, -1364,
   -1364, -1364, -1364, -1364, -1364, -1364,  -167, -1364, -1364, -1364,
    -480, -1364, -1364, -1364,  -872, -1364, -1014, -1101, -1364, -1364,
    -844, -1364, -1364, -1364,  -110, -1364,  -152,  -129, -1364, -1364,
    -817, -1364, -1207, -1257, -1364, -1364, -1364, -1364, -1364, -1364,
   -1364, -1364, -1179, -1364, -1364, -1364, -1364, -1364, -1364, -1364,
   -1364, -1364, -1364, -1364, -1364, -1364, -1364,  -342,  -348, -1364,
   -1364
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint16 yytable[] =
{
     215,   464,   598,   594,  1092,   467,   466,   864,   924,  1221,
    1311,  1101,   888,   378,  1519,   220,   497,   458,   459,   450,
     374,   248,   245,  1474,  1176,  1179,  1180,  1122,   242,   478,
    1133,   239,  1475,   365,   236,   221,  1289,  1361,   651,  1387,
    1367,   227,   347,   655,   352,   224,  1406,  1112,   659,  1112,
    1351,  1260,   194,   642,   620,  1112,   489,   490,   491,   195,
    1158,     6,  1418,   620,   107,   642,  1167,  1051,   656,   589,
    1504,   196,  1574,   825,  1113,     7,  1188,   591,  1202,  1419,
     953,   642,   652,   642,   338,   621,   346,  1379,   351,  1534,
    1253,  1256,  1257,   332,   712,  1407,   736,   195,  1535,    35,
     734,    36,    37,   642,   689,   688,  1228,   642,  1412,   196,
    1387,   108,  1327,  1290,   275,   109,   648,   110,   664,   111,
     732,   112,  1362,   404,   405,   406,  1402,   665,   414,  1291,
    1291,   222,   246,   249,   375,   366,   243,   240,   237,  1291,
    1571,   228,  1265,   225,  1279,   614,    13,   451,   498,  1572,
     617,  1321,  1324,  1325,   651,  1387,  1051,   276,   655,   436,
      11,   438,   659,   440,  1049,  1050,  1439,  1197,  1198,  1199,
    1200,   277,  1304,   278,   427,   279,   429,   280,   431,   281,
     335,  1019,  1163,  1164,  1020,   282,   336,   283,   442,   284,
     444,   285,  1051,   286,  1464,   287,  1051,   288,   589,   289,
     642,   290,   758,   757,    27,  1338,   591,  1274,  1275,  1276,
    1277,   643,  1344,   449,  1051,  1042,   589,  1498,   660,   589,
      44,   212,   642,   637,   591,   213,   633,   591,   660,   661,
     638,   634,  1520,   728,   379,   380,   381,   382,   664,   739,
     108,   212,  1183,    14,   109,   213,   110,   742,   111,  1372,
     112,    89,    52,   637,  1516,    90,  1051,    98,   589,   700,
     725,     1,     2,   706,   707,   708,   591,  1197,  1198,  1199,
    1200,   804,   803,   633,    91,    99,    92,    93,   722,  1548,
    1259,    53,   126,    54,   143,    55,   174,    56,  1395,    57,
     171,    58,   178,    59,   204,    60,   177,    61,  1554,    62,
     186,    63,   179,   588,   180,   181,   589,   230,   212,  1174,
     590,   251,   213,  1563,   591,   264,   968,   969,   335,   212,
      17,    18,   958,   213,   336,   959,  1142,  1143,  1432,  1144,
     857,  1583,   266,   588,   267,   268,   589,   265,   212,   971,
     590,   972,   213,   760,   591,   324,  1141,   333,   769,  1142,
    1143,   353,  1144,   973,   974,   343,  1457,   625,  1174,   593,
     626,   716,   348,  1599,   626,   968,   969,   392,  1473,   393,
     394,  1075,    22,    23,  1076,  1484,    30,    31,  1608,  1491,
     881,   354,   588,    47,    48,   589,   361,   212,   971,   590,
     972,   213,   362,   591,   102,   103,  1328,   363,  1614,  1221,
     128,   129,   973,   974,   788,   789,   790,   133,   134,   138,
     139,   364,   146,   147,  1625,   368,  1509,   809,  1174,   151,
     152,   156,   157,  1628,   369,   968,   969,   820,   161,   162,
     166,   167,   189,   190,  1533,   231,   232,   370,   825,   372,
    1634,  1541,   588,   252,   253,   589,   373,   212,   971,   590,
     972,   213,   276,   591,   259,   260,   326,   327,   841,   356,
     357,   687,   973,   974,   384,   385,   277,   852,   278,   371,
     279,   377,   280,   420,   281,  1556,   390,   865,   399,   400,
     282,   411,   283,   391,   284,  1570,   285,  1057,   286,   423,
     287,   432,   288,   445,   289,   468,   290,   415,   416,   876,
     453,   454,   458,   459,   462,   470,   471,   492,   493,   889,
     501,   502,   507,   508,   512,   513,  1426,   968,   969,   517,
     518,   522,   523,   528,   529,  1592,   915,   533,   534,   970,
     538,   539,   477,   925,   588,   543,   544,   589,   476,   212,
     971,   590,   972,   213,   479,   591,   548,   549,   385,  1102,
     553,   554,   559,   560,   973,   974,   564,   565,   484,   756,
     964,    53,   485,    54,   500,    55,   483,    56,  1134,    57,
     506,    58,   527,    59,   558,    60,   576,    61,   577,    62,
     569,    63,   578,   570,   571,   585,   586,   629,   630,   580,
     669,   670,   673,   674,  1025,   683,   684,   701,   702,   719,
     630,   746,   670,   579,  1168,   581,  1181,  1178,   752,   753,
     770,   771,   785,   786,   798,   799,   810,   811,   842,   843,
     866,   867,  1060,   890,   891,   898,   899,   471,   802,   903,
     904,   909,   910,   916,   917,   926,   927,   932,   933,   937,
     938,   943,   944,   995,   996,  1000,  1001,  1006,  1007,  1033,
    1034,  1062,  1063,  1097,  1098,  1107,  1108,  1081,  1124,  1125,
    1129,  1130,  1169,  1170,  1189,  1190,  1194,  1195,  1215,  1216,
    1229,  1230,  1258,  1255,  1247,  1248,  1266,  1267,  1271,  1272,
    1305,  1306,  1315,  1316,  1330,  1216,  1334,  1335,  1345,  1346,
    1373,  1374,  1396,  1397,  1123,  1413,  1414,  1433,  1434,  1442,
    1443,  1458,  1459,  1136,  1468,  1469,  1477,  1478,  1492,  1493,
    1137,  1510,  1511,  1140,  1523,  1524,  1528,  1529,  1542,  1543,
    1557,  1558,  1565,  1566,  1577,  1578,  1593,  1594,  1602,  1603,
    1619,  1620,   602,  1326,  1323,   603,   604,   607,   611,   612,
     613,   618,   619,  1339,   624,   641,   668,   571,   679,   691,
     692,   693,   690,   696,   709,   711,   710,   714,   748,   759,
     715,   718,   721,   724,   727,   738,   744,   741,   674,   745,
     761,   762,   765,   775,   780,   781,   776,   782,   783,   784,
     795,   796,   797,   805,   821,   815,   816,   822,   806,   828,
     829,  1242,   834,   830,   835,   831,   836,   832,   825,   840,
     839,   833,   837,   838,   847,   853,   848,   857,   871,   872,
     873,   874,   854,   895,   908,   860,   877,   884,   942,   881,
    1005,   954,   949,  1012,  1031,  1042,  1299,   878,  1058,  1059,
    1026,  1061,  1068,   965,  1103,  1106,   910,   920,  1138,  1139,
    1214,  1234,  1235,  1241,  1015,  1243,   958,  1038,  1045,  1313,
    1314,  1329,  1506,  1611,  1039,  1390,  1071,  1518,  1521,  1576,
    1587,  1617,  1087,  1618,  1383,  1135,   480,   582,   944,  1088,
     680,  1118,    43,  1153,   412,   713,   720,   717,   723,   726,
    1154,   729,  1184,   733,   737,   127,  1352,   749,  1112,  1082,
    1449,  1007,  1093,  1359,  1019,  1240,   743,   735,   740,  1220,
    1224,  1261,   966,   747,  1046,  1505,  1476,  1211,  1331,  1483,
    1159,  1300,  1075,  1340,  1500,  1501,  1368,  1027,  1094,  1355,
    1384,  1083,  1160,  1450,  1067,  1312,  1246,     0,  1381,  1382,
       0,     0,  1288,     0,     0,  1245,  1427,  1391,   205,     0,
       0,  1403,  1290,  1380,     0,     0,     0,  1440,  1360,     0,
       0,     0,  1353,  1428,  1356,  1407,     0,     0,     0,  1291,
    1465,     0,     0,  1177,  1453,  1404,  1405,  1517,  1499,     0,
    1487,     0,  1536,     0,     0,  1537,  1549,  1564,     0,  1362,
       0,  1610,  1584,     0,  1600,     0,     0,     0,     0,     0,
    1552,     0,     0,  1609,  1615,     0,     0,     0,     0,  1626,
    1629,  1635,     0,  1630,     0,  1441,  1636,  1637,     0,     0,
       0,  1590,     0,     0,     0,     0,     0,     0,     0,   325,
       0,  1586,  1601,  1573,     0,     0,     0,     0,     0,  1254,
       0,     0,     0,     0,     0,     0,     0,     0,  1616,  1466,
    1467,     0,  1486,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1507,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1322,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1550,  1551,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1575,     0,     0,     0,     0,     0,
    1585,     0,     0,     0,     0,  1588,  1589,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1612,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1482,     0,     0,  1631,
    1632
};

static const yytype_int16 yycheck[] =
{
     123,   343,   482,   482,  1018,   353,   348,   824,   880,  1115,
    1189,  1029,   856,     8,     4,   125,     4,     6,     7,     4,
       4,     4,     4,  1386,  1086,  1086,  1086,  1041,     4,   377,
    1048,     4,  1386,     4,     4,     4,   122,   122,   533,  1296,
    1247,     4,   209,   538,   211,     4,   122,   171,   543,   171,
    1229,  1152,    74,   145,   107,   171,   404,   405,   406,   119,
    1074,     0,    26,   107,    72,   145,  1084,    42,   160,    44,
     194,   131,   194,    37,   190,    67,  1090,    52,  1096,    43,
     897,   145,   162,   145,   207,   138,   209,  1266,   211,  1452,
    1152,  1152,  1152,   203,   138,   171,   160,   119,  1452,    79,
     162,    81,    82,   145,   584,   584,  1120,   145,  1315,   131,
    1367,   119,  1213,   199,    76,   123,   158,   125,   143,   127,
     158,   129,   207,    30,    31,    32,  1305,   152,   295,   215,
     215,   100,   114,   116,   118,   106,   112,   110,   108,   215,
    1503,   104,  1156,   102,  1162,   134,    15,   132,   136,  1503,
     492,  1213,  1213,  1213,   649,  1412,    42,   119,   653,   311,
      14,   313,   657,   315,    10,    11,  1345,    53,    54,    55,
      56,   133,  1186,   135,   303,   137,   305,   139,   307,   141,
      45,   199,    10,    11,   202,   147,    51,   149,   317,   151,
     319,   153,    42,   155,  1373,   157,    42,   159,    44,   161,
     145,   163,   682,   682,    71,  1223,    52,    57,    58,    59,
      60,   156,  1226,   323,    42,    40,    44,  1396,   143,    44,
      73,    46,   145,   143,    52,    50,   143,    52,   143,   154,
     150,   148,   222,   156,   229,   230,   231,   232,   143,   154,
     119,    46,  1086,    69,   123,    50,   125,   152,   127,  1263,
     129,     5,    70,   143,  1433,    68,    42,    15,    44,   607,
     150,    12,    13,   611,   612,   613,    52,    53,    54,    55,
      56,   751,   751,   143,    83,    75,    85,    86,   148,  1458,
    1152,    99,    70,   101,    66,   103,    16,   105,  1302,   107,
      65,   109,     5,   111,    72,   113,    80,   115,  1477,   117,
      77,   119,    87,    41,    89,    90,    44,     3,    46,    17,
      48,     3,    50,  1492,    52,    84,    24,    25,    45,    46,
      10,    11,   171,    50,    51,   174,   217,   218,  1342,   220,
      38,  1510,    91,    41,    93,    94,    44,     5,    46,    47,
      48,    49,    50,   691,    52,    74,   214,    10,   696,   217,
     218,     3,   220,    61,    62,    10,  1370,   140,    17,   482,
     143,   140,    10,  1542,   143,    24,    25,    95,  1386,    97,
      98,   207,    10,    11,   210,  1389,    10,    11,  1557,  1393,
      39,    10,    41,    10,    11,    44,   100,    46,    47,    48,
      49,    50,   102,    52,    10,    11,  1213,   104,  1577,  1505,
      10,    11,    61,    62,    21,    22,    23,    10,    11,    10,
      11,     8,    10,    11,  1593,   108,  1430,   765,    17,    10,
      11,    10,    11,  1602,   110,    24,    25,   775,    10,    11,
      10,    11,    10,    11,  1452,    10,    11,   112,    37,   116,
    1619,  1455,    41,    10,    11,    44,     8,    46,    47,    48,
      49,    50,   119,    52,    10,    11,    10,    11,   806,    10,
      11,   584,    61,    62,   120,   121,   133,   815,   135,   114,
     137,     6,   139,    18,   141,  1489,    88,   825,    10,    11,
     147,    76,   149,     5,   151,  1503,   153,   967,   155,    19,
     157,    20,   159,    27,   161,     6,   163,    10,    11,   847,
      10,    11,     6,     7,     3,   120,   121,    10,    11,   857,
      10,    11,    10,    11,    10,    11,  1333,    24,    25,    10,
      11,    10,    11,    10,    11,  1539,   874,    10,    11,    36,
      10,    11,   118,   881,    41,    10,    11,    44,   106,    46,
      47,    48,    49,    50,   120,    52,    10,    11,   121,  1029,
      10,    11,    10,    11,    61,    62,    10,    11,     5,   682,
     908,    99,   167,   101,     8,   103,    92,   105,  1048,   107,
       8,   109,     8,   111,     8,   113,   124,   115,     8,   117,
     132,   119,   126,   120,   121,    10,    11,   142,   143,   130,
     164,   165,   120,   121,   942,    10,    11,    10,    11,   142,
     143,   164,   165,   128,  1084,   120,  1086,  1086,    10,    11,
      10,    11,    10,    11,    10,    11,    10,    11,    10,    11,
      10,    11,   970,    10,    11,    10,    11,   121,   751,    10,
      11,   170,   171,   212,   213,    10,    11,    10,    11,    10,
      11,   198,   199,    10,    11,    10,    11,   206,   207,    10,
      11,    10,    11,    10,    11,    10,    11,  1005,    10,    11,
      10,    11,    10,    11,    10,    11,    10,    11,   192,   193,
      10,    11,  1152,  1152,    10,    11,    10,    11,    10,    11,
      10,    11,    10,    11,   192,   193,    10,    11,    10,    11,
      10,    11,    10,    11,  1042,    10,    11,    10,    11,    10,
      11,    10,    11,  1051,    10,    11,    10,    11,    10,    11,
    1058,    10,    11,  1061,   223,   224,    10,    11,    10,    11,
      10,    11,    10,    11,    10,    11,    10,    11,    10,    11,
      10,    11,    96,  1213,  1213,    78,   195,    33,     6,     6,
       6,   136,     6,  1223,     6,     6,     6,   121,   120,     3,
       3,   203,   122,    34,   134,    10,     8,     8,   120,   122,
      10,    10,    10,    10,     8,    10,     8,    10,   121,    10,
       8,   211,    35,     6,     4,     4,   169,     4,     4,     4,
       4,     4,     4,   122,   168,     6,   197,   173,    28,   108,
     144,  1139,     3,   144,     3,   144,     3,   144,    37,   122,
     166,   146,   144,   144,     6,   196,   205,    38,     8,     8,
       8,     6,   201,   189,     6,   175,   204,   175,     6,    39,
       6,   177,   191,   121,    29,    40,  1174,   209,     3,     3,
     198,     3,   121,   170,   121,     8,   171,   175,     8,     6,
       6,     6,   221,     6,   177,     5,   171,   176,   174,     3,
       3,     8,     8,     8,   181,     6,   177,     6,    10,     6,
       6,     6,   176,     6,   122,   172,   387,   473,   199,   181,
     573,   179,    22,   176,   292,   622,   631,   627,   635,   639,
     181,   644,   179,   649,   657,    65,  1234,   676,   171,   206,
     122,   207,   202,  1241,   199,   172,   666,   653,   662,   190,
     185,   179,   912,   671,   961,  1413,  1386,   200,  1217,  1389,
     210,   185,   207,   183,   122,  1409,   185,   946,  1022,   178,
    1293,  1009,  1078,  1364,   976,   200,  1146,    -1,  1276,  1277,
      -1,    -1,   208,    -1,    -1,   214,   172,   183,   114,    -1,
      -1,   178,   199,   208,    -1,    -1,    -1,   182,   219,    -1,
      -1,    -1,   225,   187,   226,   171,    -1,    -1,    -1,   215,
     178,    -1,    -1,  1086,   183,  1313,  1314,   180,   182,    -1,
     187,    -1,  1452,    -1,    -1,   187,   182,   180,    -1,   207,
      -1,   172,   186,    -1,   180,    -1,    -1,    -1,    -1,    -1,
     200,    -1,    -1,   186,   184,    -1,    -1,    -1,    -1,   186,
     184,   184,    -1,   188,    -1,  1353,   188,   188,    -1,    -1,
      -1,   208,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   198,
      -1,   222,   216,  1503,    -1,    -1,    -1,    -1,    -1,  1152,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   227,  1381,
    1382,    -1,  1390,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1419,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1213,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1466,  1467,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1506,    -1,    -1,    -1,    -1,    -1,
    1518,    -1,    -1,    -1,    -1,  1523,  1524,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1576,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1389,    -1,    -1,  1617,
    1618
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,    12,    13,   234,   235,   236,     0,    67,   241,   242,
     243,    14,   237,    15,    69,   268,   269,    10,    11,   244,
     245,   246,    10,    11,   238,   239,   240,    71,   354,   355,
      10,    11,   270,   271,   272,    79,    81,    82,   247,   248,
     249,   250,   251,   241,    73,   402,   403,    10,    11,   356,
     357,   358,    70,    99,   101,   103,   105,   107,   109,   111,
     113,   115,   117,   119,   273,   274,   275,   276,   277,   282,
     283,   288,   289,   294,   295,   302,   303,   308,   309,   314,
     315,   320,   321,   326,   327,   332,   333,   340,   341,     5,
      68,    83,    85,    86,   252,   253,   254,   255,    15,    75,
     430,   431,    10,    11,   404,   405,   406,    72,   119,   123,
     125,   127,   129,   359,   360,   361,   362,   363,   369,   370,
     376,   377,   383,   384,   388,   389,    70,   275,    10,    11,
     278,   279,   280,    10,    11,   284,   285,   286,    10,    11,
     290,   291,   292,    66,   296,   297,    10,    11,   304,   305,
     306,    10,    11,   310,   311,   312,    10,    11,   316,   317,
     318,    10,    11,   322,   323,   324,    10,    11,   328,   329,
     330,    65,   334,   335,    16,   342,   997,    80,     5,    87,
      89,    90,   256,   257,   258,   259,    77,   562,   563,    10,
      11,   432,   433,   434,    74,   119,   131,   407,   408,   409,
     410,   411,   416,   417,    72,   361,   364,   365,   371,   372,
     378,   379,    46,    50,   385,   939,   940,   941,   942,   390,
     997,     4,   100,   281,     4,   102,   287,     4,   104,   293,
       3,    10,    11,   298,   299,   300,     4,   108,   307,     4,
     110,   313,     4,   112,   319,     4,   114,   325,     4,   116,
     331,     3,    10,    11,   336,   337,   338,  1031,  1032,    10,
      11,   343,   344,   345,    84,     5,    91,    93,    94,   260,
     261,   262,   263,   564,   565,    76,   119,   133,   135,   137,
     139,   141,   147,   149,   151,   153,   155,   157,   159,   161,
     163,   435,   436,   437,   438,   439,   446,   447,   452,   453,
     460,   461,   468,   469,   476,   477,   484,   485,   492,   493,
     500,   501,   508,   509,   516,   517,   524,   525,   532,   533,
     540,   541,   548,   549,    74,   409,    10,    11,   412,   413,
     414,   418,   997,    10,   367,    45,    51,   366,   939,   979,
     980,   981,   982,    10,   374,   373,   939,   979,    10,   381,
     380,   939,   979,     3,    10,   386,    10,    11,   391,   392,
     393,   100,   102,   104,     8,     4,   106,   301,   108,   110,
     112,   114,   116,     8,     4,   118,   339,     6,     8,   229,
     230,   231,   232,  1033,   120,   121,   346,   347,   348,   349,
      88,     5,    95,    97,    98,   264,   265,   266,   267,    10,
      11,   567,   568,   569,    30,    31,    32,   566,   988,   994,
    1004,    76,   437,   440,   979,    10,    11,   448,   449,   450,
      18,   454,   992,    19,   462,  1000,   470,  1000,   478,  1000,
     486,  1000,    20,   494,   999,   502,   999,   510,   999,   518,
     999,   526,  1000,   534,  1000,    27,   542,  1001,   550,   997,
       4,   132,   415,    10,    11,   419,   420,   421,     6,     7,
     368,  1030,     3,   375,  1030,   382,  1030,  1031,     6,   387,
     120,   121,   394,   395,   396,   397,   106,   118,  1031,   120,
     348,   350,   351,    92,     5,   167,   570,   571,   572,  1031,
    1031,  1031,    10,    11,   441,   442,   443,     4,   136,   451,
       8,    10,    11,   455,   456,   457,     8,    10,    11,   463,
     464,   465,    10,    11,   471,   472,   473,    10,    11,   479,
     480,   481,    10,    11,   487,   488,   489,     8,    10,    11,
     495,   496,   497,    10,    11,   503,   504,   505,    10,    11,
     511,   512,   513,    10,    11,   519,   520,   521,    10,    11,
     527,   528,   529,    10,    11,   535,   536,   537,     8,    10,
      11,   543,   544,   545,    10,    11,   551,   552,   553,   132,
     120,   121,   422,   423,   424,   425,   124,     8,   126,   128,
     130,   120,   396,   398,   399,    10,    11,   353,    41,    44,
      48,    52,   352,   939,   956,   957,   958,   959,   983,   984,
     985,   986,    96,    78,   195,   701,   702,    33,   573,   574,
     998,     6,     6,     6,   134,   444,   445,  1030,   136,     6,
     107,   138,   458,   459,     6,   140,   143,   466,   467,   142,
     143,   474,   475,   143,   148,   482,   483,   143,   150,   490,
     491,     6,   145,   156,   498,   499,   926,   927,   158,   506,
     507,   926,   162,   514,   515,   926,   160,   522,   523,   926,
     143,   154,   530,   531,   143,   152,   538,   539,     6,   164,
     165,   546,   547,   120,   121,   554,   555,   556,   557,   120,
     424,   426,   427,    10,    11,   401,   400,   939,   956,   983,
     122,     3,     3,   203,   803,   804,    34,   703,   704,   996,
    1031,    10,    11,   575,   576,   577,  1031,  1031,  1031,   134,
       8,    10,   138,   459,     8,    10,   140,   467,    10,   142,
     475,    10,   148,   483,    10,   150,   491,     8,   156,   499,
     928,   929,   158,   507,   162,   515,   160,   523,    10,   154,
     531,    10,   152,   539,     8,    10,   164,   547,   120,   556,
     558,   559,    10,    11,   429,   428,   939,   956,   983,   122,
    1031,     8,   211,   904,   905,    35,   805,   806,   995,  1031,
      10,    11,   705,   706,   707,     6,   169,   578,   579,   580,
       4,     4,     4,     4,     4,    10,    11,   934,    21,    22,
      23,   930,   931,   932,   933,     4,     4,     4,    10,    11,
     561,   560,   939,   956,   983,   122,    28,   906,  1002,  1031,
      10,    11,   807,   808,   809,     6,   197,   708,   709,   710,
    1031,   168,   173,   592,   593,    37,   581,  1003,   108,   144,
     144,   144,   144,   146,     3,     3,     3,   144,   144,   166,
     122,  1031,    10,    11,   907,   908,   909,     6,   205,   810,
     811,   812,  1031,   196,   201,   723,   724,    38,   711,   993,
     175,   606,   607,   594,  1003,  1031,    10,    11,   582,   583,
     584,     8,     8,     8,     6,   910,  1031,   204,   209,   824,
     825,    39,   813,   987,   175,   737,   738,   725,   993,  1031,
      10,    11,   712,   713,   714,   189,   654,   655,    10,    11,
     608,   609,   610,    10,    11,   595,   596,   597,     6,   170,
     171,   585,   586,   587,   588,  1031,   212,   213,   911,   912,
     175,   838,   839,   826,   987,  1031,    10,    11,   814,   815,
     816,   785,    10,    11,   739,   740,   741,    10,    11,   726,
     727,   728,     6,   198,   199,   715,   716,   717,   718,   191,
     668,   669,   656,  1003,   177,   611,   612,   613,   171,   174,
     598,   599,   600,   601,  1031,   170,   587,   589,    24,    25,
      36,    47,    49,    61,    62,   913,   914,   915,   935,   936,
     937,   938,   939,   956,   960,   961,   962,   963,   967,   968,
     969,   970,   983,   991,   886,    10,    11,   840,   841,   842,
      10,    11,   827,   828,   829,     6,   206,   207,   817,   818,
     819,   820,   121,   786,   787,   177,   742,   743,   744,   199,
     202,   729,   730,   731,   732,  1031,   198,   717,   719,   720,
     683,    29,   670,    10,    11,   657,   658,   659,   176,   181,
     619,   620,    40,   614,   989,   174,   600,   602,   603,    10,
      11,    42,   590,   591,   945,   946,   947,   983,     3,     3,
    1031,     3,    10,    11,   916,   917,   918,   915,   121,   887,
     888,   177,   843,   844,   845,   207,   210,   830,   831,   832,
     833,  1031,   206,   819,   821,   788,   789,   176,   181,   750,
     751,   745,   989,   202,   731,   733,   734,    10,    11,   722,
     721,   945,   983,   121,   684,   685,     8,    10,    11,   671,
     672,   673,   171,   190,   660,   661,   662,   663,   179,   626,
     627,   621,   989,  1031,    10,    11,   615,   616,   617,    10,
      11,   605,   604,   945,   983,   172,  1031,  1031,     8,     6,
    1031,   214,   217,   218,   220,   919,   920,   921,   922,   923,
     924,   889,   890,   176,   181,   851,   852,   846,   989,   210,
     832,   834,   835,    10,    11,   822,   823,   945,   983,    10,
      11,   791,   792,   793,    17,   790,   935,   939,   956,   960,
     967,   983,   990,   993,   179,   757,   758,   752,   989,    10,
      11,   746,   747,   748,    10,    11,   736,    53,    54,    55,
      56,   735,   945,   948,   949,   950,   951,   971,   972,   973,
     974,   200,   686,   687,     6,   192,   193,   674,   675,   676,
     190,   662,   664,   665,   185,   633,   634,   628,   989,    10,
      11,   622,   623,   624,     6,   221,   618,  1015,  1016,  1023,
     172,     6,  1031,     5,   925,   214,   921,    10,    11,   892,
     893,   894,   891,   935,   939,   956,   960,   967,   983,   987,
     990,   179,   858,   859,   853,   989,    10,    11,   847,   848,
     849,    10,    11,   837,    57,    58,    59,    60,   836,   945,
     952,   953,   954,   955,   975,   976,   977,   978,   208,   122,
     199,   215,   794,   795,   796,   797,  1005,  1006,  1007,  1031,
     185,   764,   765,   759,   989,    10,    11,   753,   754,   755,
     749,  1015,   200,     3,     3,    10,    11,   689,   690,   691,
     688,   935,   939,   956,   960,   967,   983,   990,  1003,     8,
     192,   675,   677,   678,    10,    11,   667,   666,   945,   983,
     183,   640,   641,   635,   989,    10,    11,   629,   630,   631,
     625,  1015,  1031,   225,  1024,   178,   226,  1017,  1018,  1031,
     219,   122,   207,   895,   896,   897,   898,  1005,   185,   865,
     866,   860,   989,    10,    11,   854,   855,   856,   850,  1015,
     208,  1031,  1031,   122,   796,   798,   799,  1006,  1008,  1009,
       6,   183,   771,   772,   766,   989,    10,    11,   760,   761,
     762,   756,  1015,   178,  1031,  1031,   122,   171,   692,   693,
     694,   695,  1005,    10,    11,   680,   681,   682,    26,    43,
     679,   943,   944,   964,   965,   966,  1003,   172,   187,   647,
     648,   642,   989,    10,    11,   636,   637,   638,   632,  1015,
     182,  1031,    10,    11,  1025,  1026,  1027,  1019,  1020,   122,
     897,   899,   900,   183,   872,   873,   867,   989,    10,    11,
     861,   862,   863,   857,  1015,   178,  1030,  1030,    10,    11,
     801,   802,   800,   945,   948,   971,   983,    10,    11,  1011,
    1012,  1013,   939,   983,   989,  1010,  1031,   187,   778,   779,
     773,   989,    10,    11,   767,   768,   769,   763,  1015,   182,
     122,   694,   696,   697,   194,   661,     8,  1031,   649,   989,
      10,    11,   643,   644,   645,   639,  1015,   180,     6,     4,
     222,    10,  1022,   223,   224,  1021,  1028,  1029,    10,    11,
     902,   903,   901,   945,   948,   971,   983,   187,   879,   880,
     874,   989,    10,    11,   868,   869,   870,   864,  1015,   182,
    1031,  1031,   200,  1014,  1015,   780,   989,    10,    11,   774,
     775,   776,   770,  1015,   180,    10,    11,   699,   700,   698,
     945,   948,   971,   983,   194,  1030,     6,    10,    11,   650,
     651,   652,   646,  1015,   186,  1031,   222,     6,  1031,  1031,
     208,   881,   989,    10,    11,   875,   876,   877,   871,  1015,
     180,   216,    10,    11,   781,   782,   783,   777,  1015,   186,
     172,     8,  1031,   653,  1015,   184,   227,     6,     6,    10,
      11,   882,   883,   884,   878,  1015,   186,   784,  1015,   184,
     188,  1031,  1031,   885,  1015,   184,   188,   188
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

  case 14:

    {
		if(!osoption->setOptionHeader(osglData->fileName, osglData->source,
				osglData->description, osglData->fileCreator, osglData->licence) ) 	
			osolerror( NULL, osoption, parserData, osglData, "setHeader failed");
}
    break;

  case 15:

    {
	osglData->fileName    = "";
	osglData->source      = "";
	osglData->description = "";
	osglData->fileCreator = "";
	osglData->licence     = "";
}
    break;

  case 27:

    {
	osglData->fileName = (yyvsp[(2) - (3)].sval);
}
    break;

  case 34:

    {
	osglData->source = (yyvsp[(2) - (3)].sval);
}
    break;

  case 41:

    {
	osglData->description = (yyvsp[(2) - (3)].sval);
}
    break;

  case 48:

    {
	osglData->fileCreator = (yyvsp[(2) - (3)].sval);
}
    break;

  case 55:

    {
	osglData->licence = (yyvsp[(2) - (3)].sval);
}
    break;

  case 58:

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

  case 79:

    {	if (parserData->serviceURIPresent)
		osolerror( NULL, osoption, parserData, osglData, "only one <serviceURI> element allowed");
	else
		parserData->serviceURIPresent = true;
	
}
    break;

  case 85:

    {
		if (osoption->setServiceURI((yyvsp[(1) - (1)].sval)) == false)
			osolerror( NULL, osoption, parserData, osglData, "setServiceURI failed");
			//free($1); 
		parserData->errorText = NULL;
	}
    break;

  case 87:

    {	if (parserData->serviceNamePresent)
			osolerror(NULL, NULL, parserData, osglData, "only one serviceName element allowed");
		parserData->serviceNamePresent = true;
	}
    break;

  case 93:

    {
			osoption->setServiceName((yyvsp[(1) - (1)].sval)); 
			//free($1); 
			parserData->errorText = NULL;
		}
    break;

  case 95:

    {	if (parserData->instanceNamePresent)
			osolerror(NULL, NULL, parserData, osglData, "only one instanceName element allowed");
		parserData->instanceNamePresent = true;
	}
    break;

  case 101:

    {
		if (osoption->setInstanceName((yyvsp[(1) - (1)].sval)) == false) 
			osolerror( NULL, osoption, parserData, osglData, "setInstanceName failed");
		//free($1); 
		parserData->errorText = NULL;
	}
    break;

  case 102:

    {
	if (osoption->setInstanceLocation(parserData->tempStr,parserData->typeAttribute) == false)
		osolerror(NULL, NULL, parserData, osglData, "setInstanceLocation failed");
	parserData->errorText = NULL;
}
    break;

  case 103:

    {
		if (parserData->instanceLocationPresent)
			osolerror(NULL, NULL, parserData, osglData, "only one instanceLocation element allowed");
		parserData->instanceLocationPresent = true;
		parserData->typeAttribute = "local";
	}
    break;

  case 105:

    {   
		if (verifyLocationType(parserData->typeAttribute) == false)
			osolerror(NULL, NULL, parserData, osglData, "instance location type not recognized");
		parserData->errorText = NULL;
	}
    break;

  case 106:

    { 
	parserData->typeAttribute = (yyvsp[(2) - (3)].sval); 
	free((yyvsp[(2) - (3)].sval));
}
    break;

  case 112:

    {	
		parserData->tempStr = (yyvsp[(1) - (1)].sval);
		//free($1); 
	}
    break;

  case 114:

    {	if (parserData->jobIDPresent)
			osolerror(NULL, NULL, parserData, osglData, "only one jobID element allowed");
		parserData->jobIDPresent = true;
	}
    break;

  case 120:

    {
		if (osoption->setJobID((yyvsp[(1) - (1)].sval)) == false)
			osolerror( NULL, osoption, parserData, osglData, "setJobID failed");
		//free($1); 
		parserData->errorText = NULL;
	}
    break;

  case 122:

    {
		if (parserData->solverToInvokePresent)
			osolerror(NULL, NULL, parserData, osglData, "only one solverToInvoke element allowed");
		parserData->solverToInvokePresent = true;
	}
    break;

  case 128:

    {
		if (osoption->setSolverToInvoke((yyvsp[(1) - (1)].sval)) == false)
			osolerror( NULL, osoption, parserData, osglData, "setSolverToInvoke failed");
		//free($1); 
		parserData->errorText = NULL;
	}
    break;

  case 130:

    {
	if (parserData->licensePresent)
		osolerror( NULL, osoption, parserData, osglData, "only one <license> element allowed");
	parserData->licensePresent = true;	
}
    break;

  case 136:

    {
		if (osoption->setLicense((yyvsp[(1) - (1)].sval)) == false)
			osolerror( NULL, osoption, parserData, osglData, "setLicense failed");
		//free($1);
		parserData->errorText = NULL;
	}
    break;

  case 138:

    {	if (parserData->usernamePresent)
		osolerror( NULL, osoption, parserData, osglData, "only one <username> element allowed");
	parserData->usernamePresent = true;	
}
    break;

  case 144:

    {
		if (osoption->setUserName((yyvsp[(1) - (1)].sval)) == false)
			osolerror( NULL, osoption, parserData, osglData, "setUsername failed");
		//free($1); 
		parserData->errorText = NULL;
	}
    break;

  case 146:

    {	if (parserData->passwordPresent)
		osolerror( NULL, osoption, parserData, osglData, "only one <password> element allowed");
	parserData->passwordPresent = true;	
}
    break;

  case 152:

    {
		if (osoption->setPassword((yyvsp[(1) - (1)].sval)) == false)
			osolerror( NULL, osoption, parserData, osglData, "setPassword failed");
		//free($1); 
		parserData->errorText = NULL;
	}
    break;

  case 153:

    {
	if (osoption->setContact(parserData->tempStr,parserData->typeAttribute) == false)
		osolerror( NULL, osoption, parserData, osglData, "setContact failed");
	parserData->errorText = NULL;
}
    break;

  case 154:

    {
	if (parserData->contactPresent)
		osolerror( NULL, osoption, parserData, osglData, "only one <contact> element allowed");
	parserData->contactPresent = true;
	parserData->typeAttribute = "osp";
	parserData->tempStr = "";
}
    break;

  case 156:

    {   
		if (verifyTransportType(parserData->typeAttribute) == false)
			osolerror(NULL, NULL, parserData, osglData, "transport type not recognized");
	}
    break;

  case 157:

    { 
	parserData->typeAttribute = (yyvsp[(2) - (3)].sval); 
	free((yyvsp[(2) - (3)].sval));
}
    break;

  case 163:

    {
		parserData->tempStr = (yyvsp[(1) - (1)].sval);
	}
    break;

  case 165:

    {	if (parserData->otherGeneralOptionsPresent)
		osolerror(NULL, NULL, parserData, osglData, "only one <general> <other> element allowed");
	parserData->otherGeneralOptionsPresent = true;
}
    break;

  case 166:

    {
	if (parserData->tempInt < 0) osolerror(NULL, NULL, parserData, osglData, "number of other general options cannot be negative");
	parserData->numberOf = parserData->tempInt;
	parserData->kounter = 0;
}
    break;

  case 167:

    {	if (parserData->numberOf > 0)
			osolerror(NULL, NULL, parserData, osglData, "expected at least one <other> element");
	}
    break;

  case 168:

    {	if (parserData->kounter < parserData->numberOf - 1)
			osolerror(NULL, NULL, parserData, osglData, "fewer <other> elements than specified");
	}
    break;

  case 175:

    {	
	parserData->kounter++;
	if (osoption->setAnOtherGeneralOption(parserData->nameAttribute, parserData->valueAttribute, parserData->descriptionAttribute) == false)
		osolerror(NULL, NULL, parserData, osglData, "setOtherGeneralOption failed");
}
    break;

  case 176:

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

  case 177:

    {
	if (!parserData->nameAttributePresent)
		osolerror (NULL, NULL, parserData, osglData, "<other> must have name attribute");
}
    break;

  case 180:

    {	if (parserData->nameAttribute.length() == 0)
			osolerror(NULL, NULL, parserData, osglData, "otherOption name cannot be empty");
	}
    break;

  case 187:

    {
	parserData->minDiskSpacePresent = false;	
	parserData->minMemoryPresent = false;
	parserData->minCPUSpeedPresent = false;
	parserData->minCPUNumberPresent = false;
	parserData->otherSystemOptionsPresent = false;
	osoption->system = new SystemOption();
}
    break;

  case 202:

    {	if (parserData->minDiskSpacePresent)
			osolerror(NULL, NULL, parserData, osglData, "only one minDiskSpace element allowed");
		parserData->minDiskSpacePresent = true;	
		parserData->unitAttributePresent = false;	
		parserData->descriptionAttributePresent = false;	
		parserData->unitAttribute = "byte";	
		parserData->descriptionAttribute = "";
	}
    break;

  case 209:

    {
	if (osoption->setMinDiskSpace(parserData->unitAttribute, parserData->descriptionAttribute, parserData->tempVal) == false)
		osolerror(NULL, NULL, parserData, osglData, "setMinDiskSpace failed");
	parserData->errorText = NULL;
}
    break;

  case 211:

    {	if (parserData->minMemoryPresent)
			osolerror(NULL, NULL, parserData, osglData, "only one minMemory element allowed");
		parserData->minMemoryPresent = true;
		parserData->unitAttributePresent = false;	
		parserData->descriptionAttributePresent = false;	
		parserData->unitAttribute = "byte";	
		parserData->descriptionAttribute = "";
	}
    break;

  case 218:

    {
	if (osoption->setMinMemorySize(parserData->unitAttribute, parserData->descriptionAttribute, parserData->tempVal) == false)
		osolerror(NULL, NULL, parserData, osglData, "setMinMemorySize failed");
    parserData->errorText = NULL;
}
    break;

  case 220:

    {	if (parserData->minCPUSpeedPresent)
			osolerror(NULL, NULL, parserData, osglData, "only one minCPUSpeed element allowed");
		parserData->minCPUSpeedPresent = true;
		parserData->unitAttributePresent = false;	
		parserData->descriptionAttributePresent = false;	
		parserData->unitAttribute = "hertz";	
		parserData->descriptionAttribute = "";
	}
    break;

  case 227:

    {	
	if (osoption->setMinCPUSpeed(parserData->unitAttribute, parserData->descriptionAttribute, parserData->tempVal) == false)
		osolerror(NULL, NULL, parserData, osglData, "setMinCPUSpeed failed");
    parserData->errorText = NULL;
}
    break;

  case 229:

    {	if (parserData->minCPUNumberPresent)
			osolerror(NULL, NULL, parserData, osglData, "only one minCPUNumber element allowed");
		parserData->minCPUNumberPresent = true;
		parserData->descriptionAttributePresent = false;	
		parserData->descriptionAttribute = "";	
	}
    break;

  case 233:

    {
	if (osoption->setMinCPUNumber((yyvsp[(1) - (1)].ival), parserData->descriptionAttribute) == false)
		osolerror(NULL, NULL, parserData, osglData, "setMinCPUNumber failed");
	//free($1); 
	parserData->errorText = NULL; 
}
    break;

  case 235:

    {
	if (parserData->otherSystemOptionsPresent)
		osolerror(NULL, NULL, parserData, osglData, "only one <system> <other> element allowed");
	parserData->otherSystemOptionsPresent = true;
}
    break;

  case 236:

    {
	if (parserData->tempInt < 0) osolerror(NULL, NULL, parserData, osglData, "number of other system options cannot be negative");
	parserData->numberOf = parserData->tempInt;
	parserData->kounter = 0;
}
    break;

  case 237:

    {	if (parserData->numberOf > 0)
			osolerror(NULL, NULL, parserData, osglData, "expected at least one <other> element");
	}
    break;

  case 238:

    {	if (parserData->kounter < parserData->numberOf - 1)
			osolerror(NULL, NULL, parserData, osglData, "fewer <other> elements than specified");
	}
    break;

  case 245:

    {
	parserData->kounter++;
	if (osoption->setAnOtherSystemOption(parserData->nameAttribute, parserData->valueAttribute, parserData->descriptionAttribute) == false)
		osolerror(NULL, NULL, parserData, osglData, "setOtherSystemOption failed");
}
    break;

  case 246:

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

  case 247:

    {	if (!parserData->nameAttributePresent)
		osolerror (NULL, NULL, parserData, osglData, "<other> must have name attribute");
}
    break;

  case 250:

    {
		if (parserData->nameAttribute.length() == 0)
			osolerror(NULL, NULL, parserData, osglData, "otherOption name cannot be empty");
	}
    break;

  case 257:

    {
	parserData->serviceTypePresent = false;	
	parserData->otherServiceOptionsPresent = false;
	osoption->service = new ServiceOption();
}
    break;

  case 269:

    {	if (parserData->serviceTypePresent)
			osolerror(NULL, NULL, parserData, osglData, "only one currentState element allowed");
		parserData->serviceTypePresent = true;
	}
    break;

  case 275:

    {
       parserData->tempStr = (yyvsp[(1) - (1)].sval); 
		//free($1);
		if (osoption->setServiceType(parserData->tempStr) == false)
			osolerror(NULL, NULL, parserData, osglData, "setServiceType failed; current system state not recognized");
		parserData->errorText = NULL;
	}
    break;

  case 277:

    {
	if (parserData->otherServiceOptionsPresent)
		osolerror(NULL, NULL, parserData, osglData, "only one <service> <other> element allowed");
	parserData->otherServiceOptionsPresent = true;
}
    break;

  case 278:

    {
	if (parserData->tempInt < 0) osolerror(NULL, NULL, parserData, osglData, "number of other service options cannot be negative");
	parserData->numberOf = parserData->tempInt;
	parserData->kounter = 0;
}
    break;

  case 279:

    {	if (parserData->numberOf > 0)
			osolerror(NULL, NULL, parserData, osglData, "expected at least one <other> element");
	}
    break;

  case 280:

    {	if (parserData->kounter < parserData->numberOf - 1)
			osolerror(NULL, NULL, parserData, osglData, "fewer <other> elements than specified");
	}
    break;

  case 287:

    {	
	parserData->kounter++;
	if (osoption->setAnOtherServiceOption(parserData->nameAttribute, parserData->valueAttribute, parserData->descriptionAttribute) == false)
		osolerror(NULL, NULL, parserData, osglData, "setOtherServiceOption failed");
}
    break;

  case 288:

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

  case 289:

    {	if (!parserData->nameAttributePresent)
		osolerror (NULL, NULL, parserData, osglData, "<other> must have name attribute");
}
    break;

  case 292:

    {
		if (parserData->nameAttribute.length() == 0)
			osolerror(NULL, NULL, parserData, osglData, "otherOption name cannot be empty");
	}
    break;

  case 299:

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

  case 323:

    {	
	if (osoption->setMaxTime(parserData->maxTimeValue, parserData->unitAttribute) == false)       
			osolerror(NULL, NULL, parserData, osglData, "max time request could not be honored");
}
    break;

  case 324:

    {	
	if (parserData->maxTimePresent)
		osolerror( NULL, osoption, parserData, osglData, "only one <maxTime> element allowed");
	parserData->maxTimePresent = true;
	parserData->unitAttributePresent = false;	
	parserData->unitAttribute = "second"; 
	parserData->maxTimeValue = OSDBL_MAX;
}
    break;

  case 332:

    {
	parserData->maxTimeValue = parserData->tempVal;
}
    break;

  case 334:

    {	if (parserData->requestedStartTimePresent)
			osolerror(NULL, NULL, parserData, osglData, "only one requestedStartTime element allowed");
		parserData->requestedStartTimePresent = true;
	}
    break;

  case 340:

    {
		if (osoption->setRequestedStartTime((yyvsp[(1) - (1)].sval)) == false)
			osolerror(NULL, NULL, parserData, osglData, "setRequestedStartTime failed");	
		//free($1); 
		parserData->errorText = NULL;
		}
    break;

  case 341:

    {
	if (osoption->setJobDependencies(parserData->numberOf, parserData->jobDependencies) == false)
		osolerror (NULL, osoption, parserData, osglData, "set <job> <dependencies> failed");
	delete[] parserData->jobDependencies;
	parserData->jobDependencies = NULL;
}
    break;

  case 342:

    {
	if (parserData->dependenciesPresent)
		osolerror( NULL, osoption, parserData, osglData, "only one <dependencies> element allowed");
	parserData->dependenciesPresent = true;
}
    break;

  case 348:

    {
	if (parserData->kounter > parserData->numberOf)
		osolerror (NULL, osoption, parserData, osglData, "too few job IDs in <dependencies> element");
}
    break;

  case 351:

    {
	if (parserData->kounter >= parserData->numberOf)
		osolerror (NULL, osoption, parserData, osglData, "too many job IDs in <dependencies> element");
	parserData->jobDependencies[parserData->kounter] = (yyvsp[(3) - (4)].sval);
	//free($3); 
	parserData->kounter++;
}
    break;

  case 352:

    {
	if (osoption->setRequiredDirectories(parserData->numberOf,parserData->paths) == false)
		osolerror (NULL, osoption, parserData, osglData, "set <requiredDirectories> failed");
	delete[] parserData->paths;
	parserData->paths = NULL;
}
    break;

  case 353:

    {	if (parserData->requiredDirectoriesPresent)
		osolerror( NULL, osoption, parserData, osglData, "only one <requiredDirectories> element allowed");
	parserData->requiredDirectoriesPresent = true;
}
    break;

  case 359:

    {
	if (parserData->kounter > parserData->numberOf)
		osolerror (NULL, osoption, parserData, osglData, "too few paths in <requiredDirectories> element");
}
    break;

  case 362:

    {
	if (parserData->kounter >= parserData->numberOf)
		osolerror (NULL, osoption, parserData, osglData, "too many paths in <requiredDirectories> element");
	parserData->paths[parserData->kounter] = (yyvsp[(3) - (4)].sval);
	//free($3); 
	parserData->kounter++;
}
    break;

  case 363:

    {
	if (osoption->setRequiredFiles(parserData->numberOf, parserData->paths) == false)
		osolerror (NULL, osoption, parserData, osglData, "set <requiredFiles> failed");
	delete[] parserData->paths;
	parserData->paths = NULL;
}
    break;

  case 364:

    {	if (parserData->requiredFilesPresent)
		osolerror( NULL, osoption, parserData, osglData, "only one <requiredFiles> element allowed");
	parserData->requiredFilesPresent = true;
}
    break;

  case 370:

    {
	if (parserData->kounter > parserData->numberOf)
		osolerror (NULL, osoption, parserData, osglData, "too few paths in <requiredFiles> element");
}
    break;

  case 373:

    {
	if (parserData->kounter >= parserData->numberOf)
		osolerror (NULL, osoption, parserData, osglData, "too many paths in <requiredFiles> element");
	parserData->paths[parserData->kounter] = (yyvsp[(3) - (4)].sval);
	//free($3);
	parserData->kounter++;
}
    break;

  case 374:

    {
	if (osoption->setDirectoriesToMake(parserData->numberOf, parserData->paths) == false)
		osolerror (NULL, osoption, parserData, osglData, "set <directoriesToMake> failed");
	delete[] parserData->paths;
	parserData->paths = NULL;
}
    break;

  case 375:

    {	if (parserData->directoriesToMakePresent)
		osolerror( NULL, osoption, parserData, osglData, "only one <directoriesToMake> element allowed");
	parserData->directoriesToMakePresent = true;
}
    break;

  case 381:

    {
	if (parserData->kounter > parserData->numberOf)
		osolerror (NULL, osoption, parserData, osglData, "too few paths in <directoriesToMake> element");
}
    break;

  case 384:

    {
	if (parserData->kounter >= parserData->numberOf)
		osolerror (NULL, osoption, parserData, osglData, "too many paths in <directoriesToMake> element");
	parserData->paths[parserData->kounter] = (yyvsp[(3) - (4)].sval);
	//free($3); 
	parserData->kounter++;
}
    break;

  case 385:

    {
	if (osoption->setFilesToMake(parserData->numberOf, parserData->paths) == false)
		osolerror (NULL, osoption, parserData, osglData, "set <filesToMake> failed");
	delete[] parserData->paths;
	parserData->paths = NULL;
}
    break;

  case 386:

    {	if (parserData->filesToMakePresent)
		osolerror( NULL, osoption, parserData, osglData, "only one <filesToMake> element allowed");
	parserData->filesToMakePresent = true;
}
    break;

  case 392:

    {
	if (parserData->kounter > parserData->numberOf)
		osolerror (NULL, osoption, parserData, osglData, "too few paths in <filesToMake> element");
}
    break;

  case 395:

    {
	if (parserData->kounter >= parserData->numberOf)
		osolerror (NULL, osoption, parserData, osglData, "too many paths in <filesToMake> element");
	parserData->paths[parserData->kounter] = (yyvsp[(3) - (4)].sval);
	//free($3); 
	parserData->kounter++;
}
    break;

  case 396:

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

  case 397:

    {	if (parserData->inputDirectoriesToMovePresent)
		osolerror( NULL, osoption, parserData, osglData, "only one <inputDirectoriesToMove> element allowed");
		parserData->inputDirectoriesToMovePresent = true;
}
    break;

  case 403:

    {
	if (parserData->kounter > parserData->numberOfPathPairs)
		osolerror (NULL, osoption, parserData, osglData, "too few path pairs in <inputDirectoriesToMove> element");
}
    break;

  case 407:

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

  case 408:

    {	if (parserData->inputFilesToMovePresent)
		osolerror( NULL, osoption, parserData, osglData, "only one <inputFilesToMove> element allowed");
		parserData->inputFilesToMovePresent = true;
}
    break;

  case 414:

    {
	if (parserData->kounter > parserData->numberOfPathPairs)
		osolerror (NULL, osoption, parserData, osglData, "too few path pairs in <inputFilesToMove> element");
}
    break;

  case 418:

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

  case 419:

    {	if (parserData->outputFilesToMovePresent)
		osolerror( NULL, osoption, parserData, osglData, "only one <outputFilesToMove> element allowed");
		parserData->outputFilesToMovePresent = true;
}
    break;

  case 425:

    {
	if (parserData->kounter > parserData->numberOfPathPairs)
		osolerror (NULL, osoption, parserData, osglData, "too few path pairs in <outputFilesToMake> element");
}
    break;

  case 429:

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

  case 430:

    {	if (parserData->outputDirectoriesToMovePresent)
		osolerror( NULL, osoption, parserData, osglData, "only one <outputDirectoriesToMove> element allowed");
		parserData->outputDirectoriesToMovePresent = true;
}
    break;

  case 436:

    {
	if (parserData->kounter > parserData->numberOfPathPairs)
		osolerror (NULL, osoption, parserData, osglData, "too few path pairs in <outputDirectoriesToMake> element");
}
    break;

  case 440:

    {
	if (osoption->setFilesToDelete(parserData->numberOf, parserData->paths) == false)
		osolerror (NULL, osoption, parserData, osglData, "set <filesToDelete> failed");
	delete[] parserData->paths;
	parserData->paths = NULL;
}
    break;

  case 441:

    {	if (parserData->filesToDeletePresent)
		osolerror( NULL, osoption, parserData, osglData, "only one <filesToDelete> element allowed");
	parserData->filesToDeletePresent = true;
}
    break;

  case 447:

    {
	if (parserData->kounter > parserData->numberOf)
		osolerror (NULL, osoption, parserData, osglData, "too few paths in <filesToDelete> element");
}
    break;

  case 450:

    {
	if (parserData->kounter >= parserData->numberOf)
		osolerror (NULL, osoption, parserData, osglData, "too many paths in <filesToDelete> element");
	parserData->paths[parserData->kounter] = (yyvsp[(3) - (4)].sval);
	//free($3); 
	parserData->kounter++;
}
    break;

  case 451:

    {
	if (osoption->setDirectoriesToDelete(parserData->numberOf, parserData->paths) == false)
		osolerror (NULL, osoption, parserData, osglData, "set <directoriesToDelete> failed");
	delete[] parserData->paths;
	parserData->paths = NULL;
}
    break;

  case 452:

    {	if (parserData->directoriesToDeletePresent)
		osolerror( NULL, osoption, parserData, osglData, "only one <directoriesToDelete> element allowed");
	parserData->directoriesToDeletePresent = true;
}
    break;

  case 458:

    {
	if (parserData->kounter > parserData->numberOf)
		osolerror (NULL, osoption, parserData, osglData, "too few paths in <directoriesToDelete> element");
}
    break;

  case 461:

    {
	if (parserData->kounter >= parserData->numberOf)
		osolerror (NULL, osoption, parserData, osglData, "too many paths in <directoriesToDelete> element");
	parserData->paths[parserData->kounter] = (yyvsp[(3) - (4)].sval);
	//free($3); 
	parserData->kounter++;
}
    break;

  case 462:

    {
	if (osoption->setProcessesToKill(parserData->numberOf, parserData->processesToKill) == false)
		osolerror (NULL, osoption, parserData, osglData, "set <processesToKill> failed");
	delete[] parserData->processesToKill;
	parserData->processesToKill = NULL;
}
    break;

  case 463:

    {
	if (parserData->processesToKillPresent)
		osolerror( NULL, osoption, parserData, osglData, "only one <processesToKill> element allowed");
	parserData->processesToKillPresent = true;
}
    break;

  case 469:

    {
	if (parserData->kounter > parserData->numberOf)
		osolerror (NULL, osoption, parserData, osglData, "too few process IDs in <processesToKill> element");
}
    break;

  case 472:

    {
	if (parserData->kounter >= parserData->numberOf)
		osolerror (NULL, osoption, parserData, osglData, "too many process IDs in <processesToKill> element");
	parserData->processesToKill[parserData->kounter] = (yyvsp[(3) - (4)].sval);
	//free($3); 
	parserData->kounter++;
}
    break;

  case 474:

    {	if (parserData->otherJobOptionsPresent)
		osolerror(NULL, NULL, parserData, osglData, "only one <job> <other> element allowed");
	parserData->otherJobOptionsPresent = true;
}
    break;

  case 475:

    {
	if (parserData->tempInt < 0) osolerror(NULL, NULL, parserData, osglData, "number of other job options cannot be negative");
	parserData->numberOf = parserData->tempInt;
	parserData->kounter = 0;
}
    break;

  case 476:

    {	if (parserData->numberOf > 0)
			osolerror(NULL, NULL, parserData, osglData, "expected at least one <other> element");
	}
    break;

  case 477:

    {	if (parserData->kounter < parserData->numberOf - 1)
			osolerror(NULL, NULL, parserData, osglData, "fewer <other> elements than specified");
	}
    break;

  case 484:

    {
	parserData->kounter++;
	if (osoption->setAnOtherJobOption(parserData->nameAttribute, parserData->valueAttribute, parserData->descriptionAttribute) == false)
		osolerror(NULL, NULL, parserData, osglData, "setOtherJobOption failed");
}
    break;

  case 485:

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

  case 486:

    {	if (!parserData->nameAttributePresent)
		osolerror (NULL, NULL, parserData, osglData, "<other> must have name attribute");
}
    break;

  case 489:

    {
		if (parserData->nameAttribute.length() == 0)
			osolerror(NULL, NULL, parserData, osglData, "otherOption name cannot be empty");
	}
    break;

  case 496:

    {
	osoption->optimization = new OptimizationOption();
	parserData->numberOfVariablesPresent = false;
	parserData->numberOfObjectivesPresent = false;
	parserData->numberOfConstraintsPresent = false;
}
    break;

  case 500:

    {	
		parserData->numberOfVariables = parserData->tempInt; 
		if (osoption->setNumberOfVariables(parserData->tempInt) == false)
			osolerror(NULL, NULL, parserData, osglData, "setNumberOfVariables failed");
	}
    break;

  case 501:

    {
		parserData->numberOfConstraints = parserData->tempInt; 
		if (osoption->setNumberOfConstraints(parserData->tempInt) == false)
			osolerror(NULL, NULL, parserData, osglData, "setNumberOfConstraints failed");
	}
    break;

  case 502:

    {	
		parserData->numberOfObjectives = parserData->tempInt; 
		if (osoption->setNumberOfObjectives(parserData->tempInt) == false)
			osolerror(NULL, NULL, parserData, osglData, "setNumberOfObjectives failed");
	}
    break;

  case 510:

    {
	parserData->numberOfOtherVariableOptions = 0;
}
    break;

  case 511:

    {	
	if (osoption->setNumberOfOtherVariableOptions(parserData->numberOfOtherVariableOptions) == false)
		osolerror(NULL, NULL, parserData, osglData, "setNumberOfOtherVariableOptions failed");
	parserData->iOther = 0;
}
    break;

  case 513:

    {	
	parserData->numberOfOtherVariableOptions = parserData->tempInt;
}
    break;

  case 520:

    {
		if (osoption->setInitVarValues(parserData->numberOfVar, parserData->idxArray, parserData->valArray) == false)
			osolerror (NULL, osoption, parserData, osglData, "set <initialVariableValues> failed");
		delete[] parserData->idxArray;
		delete[] parserData->valArray;
		parserData->idxArray = NULL;
		parserData->valArray = NULL;
}
    break;

  case 521:

    {
	parserData->numberOfVarAttributePresent = false;
}
    break;

  case 522:

    {
	parserData->kounter = 0;
	parserData->idxArray = new    int[parserData->numberOfVar];
	parserData->valArray = new double[parserData->numberOfVar];
}
    break;

  case 523:

    {
		if (parserData->numberOfVar > 0)
			osolerror(NULL, NULL, parserData, osglData, "expected at least one <var> element");
	}
    break;

  case 524:

    {
		if (parserData->kounter > parserData->numberOfVar)
			osolerror (NULL, osoption, parserData, osglData, "too few initial values in <initialVariableValues> element");
	}
    break;

  case 531:

    {
	parserData->kounter++;
}
    break;

  case 532:

    {	
	if (parserData->kounter >= parserData->numberOfVar)
		osolerror(NULL, NULL, parserData, osglData, "more <var> elements than specified");
	parserData->idxAttributePresent = false;
	parserData->valueAttributePresent = false;
}
    break;

  case 535:

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

  case 536:

    {
		if (parserData->valueAttribute == "")
			osolerror (NULL, osoption, parserData, osglData, "expected an integer or floating point value");
		parserData->valArray[parserData->kounter] = os_strtod((parserData->valueAttribute).c_str(), NULL);
	}
    break;

  case 540:

    {
	if (osoption->setInitVarValuesString(parserData->numberOfVar, parserData->idxArray, parserData->valueString) == false)
		osolerror (NULL, osoption, parserData, osglData, "set <initialVariableValuesString> failed");
	delete[] parserData->idxArray;
	delete[] parserData->valueString;
	parserData->idxArray = NULL;
	parserData->valueString = NULL;
}
    break;

  case 541:

    {
	parserData->numberOfVarAttributePresent = false;
}
    break;

  case 542:

    {
	parserData->kounter = 0;
	parserData->idxArray = new int[parserData->numberOfVar];
	parserData->valueString = new std::string[parserData->numberOfVar];
}
    break;

  case 543:

    {
		if (parserData->numberOfVar > 0)
			osolerror(NULL, NULL, parserData, osglData, "expected at least one <var> element");
	}
    break;

  case 544:

    {
		if (parserData->kounter != parserData->numberOfVar)
			osolerror(NULL, NULL, parserData, osglData, "fewer <var> elements than specified");
	}
    break;

  case 551:

    {
	parserData->kounter++;
}
    break;

  case 552:

    {	
	if (parserData->kounter >= parserData->numberOfVar)
		osolerror(NULL, NULL, parserData, osglData, "more <var> elements than specified");
	parserData->idxAttributePresent = false;
	parserData->valueAttributePresent = false;
	parserData->valueAttribute = "48r 87e WY EUV e7 df"; //random string...
}
    break;

  case 553:

    {
	parserData->idxArray[parserData->kounter] = parserData->idxAttribute;
	parserData->valueString[parserData->kounter] = parserData->valueAttribute;
}
    break;

  case 556:

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

  case 569:

    {
	if (osoption->setInitBasisStatus(ENUM_PROBLEM_COMPONENT_variables, ENUM_BASIS_STATUS_basic, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
		osolerror(NULL, NULL, parserData, osglData, "set variables basic failed");	
	delete[] osglData->osglIntArray;
	osglData->osglIntArray = NULL;
}
    break;

  case 570:

    {
	osglData->osglNumberOfEl = 0;
	osglData->osglNumberOfElPresent= false;
}
    break;

  case 571:

    {
	osglData->osglCounter = 0; 
	osglData->osglNumberOfEl = parserData->numberOf;
	osglData->osglIntArray = new int[parserData->numberOf];
}
    break;

  case 578:

    {
	if (osoption->setInitBasisStatus(ENUM_PROBLEM_COMPONENT_variables, ENUM_BASIS_STATUS_atLower, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
		osolerror(NULL, NULL, parserData, osglData, "set variables atLower failed");	
	delete[] osglData->osglIntArray;
	osglData->osglIntArray = NULL;
}
    break;

  case 579:

    {
	osglData->osglNumberOfEl = 0;
	osglData->osglNumberOfElPresent= false;
}
    break;

  case 580:

    {
	osglData->osglCounter = 0; 
	osglData->osglNumberOfEl = parserData->numberOf;
	osglData->osglIntArray = new int[parserData->numberOf];
}
    break;

  case 587:

    {
	if (osoption->setInitBasisStatus(ENUM_PROBLEM_COMPONENT_variables, ENUM_BASIS_STATUS_atUpper, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
		osolerror(NULL, NULL, parserData, osglData, "set variables atUpper failed");	
	delete[] osglData->osglIntArray;
	osglData->osglIntArray = NULL;
}
    break;

  case 588:

    {
	osglData->osglNumberOfEl = 0;
	osglData->osglNumberOfElPresent= false;
}
    break;

  case 589:

    {
	osglData->osglCounter = 0; 
	osglData->osglNumberOfEl = parserData->numberOf;
	osglData->osglIntArray = new int[parserData->numberOf];
}
    break;

  case 596:

    {
	if (osoption->setInitBasisStatus(ENUM_PROBLEM_COMPONENT_variables, ENUM_BASIS_STATUS_isFree, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
		osolerror(NULL, NULL, parserData, osglData, "set variables isFree failed");	
	delete[] osglData->osglIntArray;
	osglData->osglIntArray = NULL;
}
    break;

  case 597:

    {
	osglData->osglNumberOfEl = 0;
	osglData->osglNumberOfElPresent= false;
}
    break;

  case 598:

    {
	osglData->osglCounter = 0; 
	osglData->osglNumberOfEl = parserData->numberOf;
	osglData->osglIntArray = new int[parserData->numberOf];
}
    break;

  case 605:

    {
	if (osoption->setInitBasisStatus(ENUM_PROBLEM_COMPONENT_variables, ENUM_BASIS_STATUS_superbasic, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
		osolerror(NULL, NULL, parserData, osglData, "set variables superbasic failed");	
	delete[] osglData->osglIntArray;
	osglData->osglIntArray = NULL;
}
    break;

  case 606:

    {
	osglData->osglNumberOfEl = 0;
	osglData->osglNumberOfElPresent= false;
}
    break;

  case 607:

    {
	osglData->osglCounter = 0; 
	osglData->osglNumberOfEl = parserData->numberOf;
	osglData->osglIntArray = new int[parserData->numberOf];
}
    break;

  case 614:

    {
	if (osoption->setInitBasisStatus(ENUM_PROBLEM_COMPONENT_variables, ENUM_BASIS_STATUS_unknown, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
		osolerror(NULL, NULL, parserData, osglData, "set variables unknown failed");	
	delete[] osglData->osglIntArray;
	osglData->osglIntArray = NULL;
}
    break;

  case 615:

    {
	osglData->osglNumberOfEl = 0;
	osglData->osglNumberOfElPresent= false;
}
    break;

  case 616:

    {
	osglData->osglCounter = 0; 
	osglData->osglNumberOfEl = parserData->numberOf;
	osglData->osglIntArray = new int[parserData->numberOf];
}
    break;

  case 623:

    {
	if (osoption->setIntegerVariableBranchingWeights(parserData->numberOfVar, parserData->idxArray, parserData->valArray) == false)
		osolerror (NULL, osoption, parserData, osglData, "set <initialVariableValues> failed");
	delete[] parserData->idxArray;
	delete[] parserData->valArray;
	parserData->idxArray = NULL;
	parserData->valArray = NULL;
}
    break;

  case 624:

    {
	parserData->numberOfVarAttributePresent = false;
}
    break;

  case 625:

    {
	parserData->kounter = 0;
	parserData->idxArray = new    int[parserData->numberOfVar];
	parserData->valArray = new double[parserData->numberOfVar];
}
    break;

  case 626:

    {
		if (parserData->numberOfVar > 0)
			osolerror(NULL, NULL, parserData, osglData, "expected at least one <var> element");
	}
    break;

  case 627:

    {
		if (parserData->kounter != parserData->numberOfVar)
			osolerror(NULL, NULL, parserData, osglData, "fewer <var> elements than specified");
	}
    break;

  case 634:

    {
	parserData->kounter++;
}
    break;

  case 635:

    {	
	if (parserData->kounter >= parserData->numberOfVar)
		osolerror(NULL, NULL, parserData, osglData, "more <var> elements than specified");
	parserData->idxAttributePresent = false;
	parserData->valueAttributePresent = false;
	parserData->valueAttribute = "1.0";
}
    break;

  case 636:

    {
	parserData->idxArray[parserData->kounter] = parserData->idxAttribute;
	parserData->valArray[parserData->kounter] = os_strtod((parserData->valueAttribute).c_str(), NULL);
}
    break;

  case 639:

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

  case 640:

    {
		if (parserData->valueAttribute == "")
			osolerror (NULL, osoption, parserData, osglData, "expected an integer or floating point value");
	}
    break;

  case 645:

    {
	parserData->sosIdxAttributePresent = false;	
	parserData->currentSOS = 0;
}
    break;

  case 646:

    {
	if ((yyvsp[(3) - (4)].ival) < 0)
		osolerror (NULL, osoption, parserData, osglData, "number of <sos> elements must be nonnegative");
	parserData->numberOfSOS = (yyvsp[(3) - (4)].ival);
}
    break;

  case 647:

    {	if (parserData->numberOfSOS > 0)
			osolerror(NULL, NULL, parserData, osglData, "expected at least one <sos> element");
	}
    break;

  case 648:

    {	if (parserData->currentSOS != parserData->numberOfSOS)
			osolerror(NULL, NULL, parserData, osglData, "fewer <sos> elements than specified");
	}
    break;

  case 654:

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
}
    break;

  case 655:

    {	if (parserData->currentSOS >= parserData->numberOfSOS)
		osolerror(NULL, osoption, parserData, osglData, "too many SOS branching weights");
	parserData->sosIdxAttributePresent = false;
	parserData->groupWeightAttributePresent = false;
	parserData->numberOfVarAttributePresent = false;
	parserData->groupWeight = 1.0;
	parserData->numberOfSOSVar = 0;
}
    break;

  case 656:

    {
	if (!parserData->sosIdxAttributePresent)
		osolerror (NULL, osoption, parserData, osglData, "SOS index required");
	if (!parserData->numberOfVarAttributePresent)
		osolerror (NULL, osoption, parserData, osglData, "numberOfVar required");
}
    break;

  case 660:

    {
		parserData->kounter = 0;
		parserData->idxArray = new    int[parserData->numberOfVar];
		parserData->valArray = new double[parserData->numberOfVar];
		parserData->numberOfVarAttributePresent = true;
	}
    break;

  case 669:

    { 	 
		parserData->iOther++;
	}
    break;

  case 670:

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

  case 671:

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

  case 674:

    {
		parserData->kounter = 0;
	}
    break;

  case 675:

    {
		parserData->kounter = 0;
	}
    break;

  case 691:

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
}
    break;

  case 692:

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
}
    break;

  case 696:

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

  case 705:

    {	parserData->numberOfOtherObjectiveOptions = 0; }
    break;

  case 706:

    {	
	if (osoption->setNumberOfOtherObjectiveOptions(parserData->numberOfOtherObjectiveOptions) == false)
		osolerror(NULL, NULL, parserData, osglData, "setNumberOfOtherVariableOptions failed");
	parserData->iOther = 0;
}
    break;

  case 708:

    {	
	parserData->numberOfOtherObjectiveOptions = parserData->tempInt;
}
    break;

  case 715:

    {
	if (osoption->setInitObjValues(parserData->numberOfObj, parserData->idxArray, parserData->valArray) == false)
		osolerror (NULL, osoption, parserData, osglData, "set <initialObjectiveValues> failed");
	delete[] parserData->idxArray;
	delete[] parserData->valArray;
	parserData->idxArray = NULL;
	parserData->valArray = NULL;
}
    break;

  case 716:

    {
	parserData->numberOfObjAttributePresent = false;
}
    break;

  case 717:

    {
	parserData->kounter = 0;
	parserData->idxArray = new    int[parserData->numberOfObj];
	parserData->valArray = new double[parserData->numberOfObj];
}
    break;

  case 718:

    {	
		if (parserData->numberOfObj > 0)
			osolerror(NULL, NULL, parserData, osglData, "expected at least one <obj> element");
	}
    break;

  case 719:

    {
		if (parserData->kounter != parserData->numberOfObj)
			osolerror(NULL, NULL, parserData, osglData, "fewer <obj> elements than specified");
	}
    break;

  case 726:

    {
	parserData->kounter++;
}
    break;

  case 727:

    {	
	if (parserData->kounter >= parserData->numberOfObj)
		osolerror(NULL, NULL, parserData, osglData, "more <obj> elements than specified");
	parserData->idxAttributePresent = false;
	parserData->valueAttributePresent = false;
	parserData->idxAttribute = -1;
}
    break;

  case 728:

    {	
	parserData->idxArray[parserData->kounter] = parserData->idxAttribute;
}
    break;

  case 731:

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

  case 732:

    {
		if (parserData->valueAttribute == "")
			osolerror (NULL, osoption, parserData, osglData, "expected an integer or floating point value");
		parserData->valArray[parserData->kounter] = os_strtod((parserData->valueAttribute).c_str(), NULL);
	}
    break;

  case 736:

    {
	if (osoption->setInitObjBounds(parserData->numberOfObj, parserData->idxArray, parserData->lbValArray, parserData->ubValArray) == false)
		osolerror (NULL, osoption, parserData, osglData, "set <initialObjectiveBounds> failed");
	delete[] parserData->idxArray;
	delete[] parserData->lbValArray;
	delete[] parserData->ubValArray;
	parserData->idxArray = NULL;
	parserData->lbValArray = NULL;
	parserData->ubValArray = NULL;
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
	parserData->idxArray   = new    int[parserData->numberOfObj];
	parserData->lbValArray = new double[parserData->numberOfObj];
	parserData->ubValArray = new double[parserData->numberOfObj];
}
    break;

  case 739:

    {
		if (parserData->numberOfObj > 0)
			osolerror(NULL, NULL, parserData, osglData, "expected at least one <obj> element");
	}
    break;

  case 740:

    {
		if (parserData->kounter != parserData->numberOfObj)
			osolerror(NULL, NULL, parserData, osglData, "fewer <obj> elements than specified");
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
		osolerror(NULL, NULL, parserData, osglData, "more <obj> elements than specified");
	parserData->idxAttributePresent = false;
	parserData->lbValueAttributePresent = false;
	parserData->ubValueAttributePresent = false;
	parserData->idxAttribute = -1;
	parserData->lbValueAttribute = "-INF";
	parserData->ubValueAttribute = "INF";
}
    break;

  case 749:

    {	
	parserData->idxArray[parserData->kounter] = parserData->idxAttribute;
	parserData->lbValArray[parserData->kounter] = os_strtod((parserData->lbValueAttribute).c_str(), NULL);
	parserData->ubValArray[parserData->kounter] = os_strtod((parserData->ubValueAttribute).c_str(), NULL);
}
    break;

  case 752:

    {
		if (parserData->idxAttribute >= 0)
			osolerror (NULL, osoption, parserData, osglData, "objective index must be nonnegative");
		if (osoption->optimization->numberOfObjectives >= 0)
		{
			if (parserData->idxAttribute < -osoption->optimization->numberOfVariables)
				osolerror (NULL, osoption, parserData, osglData, "objective index exceeds limit");
		};
	}
    break;

  case 753:

    {
		if (parserData->lbValueAttribute == "")
			osolerror (NULL, osoption, parserData, osglData, "expected an integer or floating point value");
	}
    break;

  case 754:

    {
		if (parserData->ubValueAttribute == "")
			osolerror (NULL, osoption, parserData, osglData, "expected an integer or floating point value");
	}
    break;

  case 766:

    {
	if (osoption->setInitBasisStatus(ENUM_PROBLEM_COMPONENT_objectives, ENUM_BASIS_STATUS_basic, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
		osolerror(NULL, NULL, parserData, osglData, "set objectives basic failed");	
	delete[] osglData->osglIntArray;
	osglData->osglIntArray = NULL;
}
    break;

  case 767:

    {
	osglData->osglNumberOfEl = 0;
	osglData->osglNumberOfElPresent= false;
}
    break;

  case 768:

    {
	osglData->osglCounter = 0; 
	osglData->osglNumberOfEl = parserData->numberOf;
	osglData->osglIntArray = new int[parserData->numberOf];
}
    break;

  case 775:

    {
	if (osoption->setInitBasisStatus(ENUM_PROBLEM_COMPONENT_objectives, ENUM_BASIS_STATUS_atLower, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
		osolerror(NULL, NULL, parserData, osglData, "set objectives atLower failed");	
	delete[] osglData->osglIntArray;
	osglData->osglIntArray = NULL;
}
    break;

  case 776:

    {
	osglData->osglNumberOfEl = 0;
	osglData->osglNumberOfElPresent= false;
}
    break;

  case 777:

    {
	osglData->osglCounter = 0; 
	osglData->osglNumberOfEl = parserData->numberOf;
	osglData->osglIntArray = new int[parserData->numberOf];
}
    break;

  case 784:

    {
	if (osoption->setInitBasisStatus(ENUM_PROBLEM_COMPONENT_objectives, ENUM_BASIS_STATUS_atUpper, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
		osolerror(NULL, NULL, parserData, osglData, "set objectives atUpper failed");	
	delete[] osglData->osglIntArray;
	osglData->osglIntArray = NULL;
}
    break;

  case 785:

    {
	osglData->osglNumberOfEl = 0;
	osglData->osglNumberOfElPresent= false;
}
    break;

  case 786:

    {
	osglData->osglCounter = 0; 
	osglData->osglNumberOfEl = parserData->numberOf;
	osglData->osglIntArray = new int[parserData->numberOf];
}
    break;

  case 793:

    {
	if (osoption->setInitBasisStatus(ENUM_PROBLEM_COMPONENT_objectives, ENUM_BASIS_STATUS_isFree, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
		osolerror(NULL, NULL, parserData, osglData, "set objectives isFree failed");	
	delete[] osglData->osglIntArray;
	osglData->osglIntArray = NULL;
}
    break;

  case 794:

    {
	osglData->osglNumberOfEl = 0;
	osglData->osglNumberOfElPresent= false;
}
    break;

  case 795:

    {
	osglData->osglCounter = 0; 
	osglData->osglNumberOfEl = parserData->numberOf;
	osglData->osglIntArray = new int[parserData->numberOf];
}
    break;

  case 802:

    {
	if (osoption->setInitBasisStatus(ENUM_PROBLEM_COMPONENT_objectives, ENUM_BASIS_STATUS_superbasic, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
		osolerror(NULL, NULL, parserData, osglData, "set objectives superbasic failed");	
	delete[] osglData->osglIntArray;
	osglData->osglIntArray = NULL;
}
    break;

  case 803:

    {
	osglData->osglNumberOfEl = 0;
	osglData->osglNumberOfElPresent= false;
}
    break;

  case 804:

    {
	osglData->osglCounter = 0; 
	osglData->osglNumberOfEl = parserData->numberOf;
	osglData->osglIntArray = new int[parserData->numberOf];
}
    break;

  case 811:

    {
	if (osoption->setInitBasisStatus(ENUM_PROBLEM_COMPONENT_objectives, ENUM_BASIS_STATUS_unknown, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
		osolerror(NULL, NULL, parserData, osglData, "set objectives unknown failed");	
	delete[] osglData->osglIntArray;
	osglData->osglIntArray = NULL;
}
    break;

  case 812:

    {
	osglData->osglNumberOfEl = 0;
	osglData->osglNumberOfElPresent= false;
}
    break;

  case 813:

    {
	osglData->osglCounter = 0; 
	osglData->osglNumberOfEl = parserData->numberOf;
	osglData->osglIntArray = new int[parserData->numberOf];
}
    break;

  case 821:

    { 	 
		parserData->iOther++;  
	}
    break;

  case 822:

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

  case 823:

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
	}
    break;

  case 826:

    {
		parserData->kounter = 0;
	}
    break;

  case 827:

    {
		parserData->kounter = 0;
	}
    break;

  case 843:

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
}
    break;

  case 844:

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
}
    break;

  case 845:

    {	
	parserData->idxArray[parserData->kounter] = parserData->idxAttribute;
	parserData->valueString[parserData->kounter] = parserData->valueAttribute;
	parserData->lbValueString[parserData->kounter] = parserData->lbValueAttribute;
	parserData->ubValueString[parserData->kounter] = parserData->ubValueAttribute;
}
    break;

  case 848:

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

  case 857:

    {
	parserData->numberOfOtherConstraintOptions = 0; 
}
    break;

  case 858:

    {	
	if (osoption->setNumberOfOtherConstraintOptions(parserData->numberOfOtherConstraintOptions) == false)
		osolerror(NULL, NULL, parserData, osglData, "setNumberOfOtherConstraintOptions failed");
	parserData->iOther = 0;
}
    break;

  case 860:

    {	
	parserData->numberOfOtherConstraintOptions = parserData->tempInt;
}
    break;

  case 867:

    {
	if (osoption->setInitConValues(parserData->numberOfCon, parserData->idxArray, parserData->valArray) == false)
		osolerror (NULL, osoption, parserData, osglData, "set <initialConstraintValues> failed");
	delete[] parserData->idxArray;
	delete[] parserData->valArray;
	parserData->idxArray = NULL;
	parserData->valArray = NULL;
}
    break;

  case 868:

    {
	parserData->numberOfConAttributePresent = false;
}
    break;

  case 869:

    {
	parserData->kounter = 0;
	parserData->idxArray = new    int[parserData->numberOfCon];
	parserData->valArray = new double[parserData->numberOfCon];
}
    break;

  case 870:

    {
		if (parserData->numberOfCon > 0)
			osolerror(NULL, NULL, parserData, osglData, "expected at least one <con element");
	}
    break;

  case 871:

    {
		if (parserData->kounter > parserData->numberOfCon)
			osolerror(NULL, NULL, parserData, osglData, "fewer <con> elements than specified");
	}
    break;

  case 878:

    {
	parserData->kounter++;
}
    break;

  case 879:

    {	
	if (parserData->kounter >= parserData->numberOfCon)
		osolerror(NULL, NULL, parserData, osglData, "more <con> elements than specified");
	parserData->idxAttributePresent = false;
	parserData->valueAttributePresent = false;
}
    break;

  case 882:

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

  case 883:

    {
		if (parserData->valueAttribute == "")
			osolerror (NULL, osoption, parserData, osglData, "expected an integer or floating point value");
		parserData->valArray[parserData->kounter] = os_strtod((parserData->valueAttribute).c_str(), NULL);
	}
    break;

  case 887:

    {
	if (osoption->setInitDualValues(parserData->numberOfCon, parserData->idxArray, parserData->lbValArray, parserData->ubValArray) == false)
		osolerror (NULL, osoption, parserData, osglData, "set <initialConstraintValues> failed");
	delete[] parserData->idxArray;
	delete[] parserData->lbValArray;
	delete[] parserData->ubValArray;
	parserData->idxArray = NULL;
	parserData->lbValArray = NULL;
	parserData->ubValArray = NULL;
}
    break;

  case 888:

    {
	parserData->numberOfConAttributePresent = false;
}
    break;

  case 889:

    {
	parserData->kounter = 0;
	parserData->idxArray   = new    int[parserData->numberOfCon];
	parserData->lbValArray = new double[parserData->numberOfCon];
	parserData->ubValArray = new double[parserData->numberOfCon];
}
    break;

  case 890:

    {
		if (parserData->numberOfCon > 0)
			osolerror(NULL, NULL, parserData, osglData, "expected at least one <con> element");
	}
    break;

  case 891:

    {
		if (parserData->kounter != parserData->numberOfCon)
			osolerror(NULL, NULL, parserData, osglData, "fewer <con> elements than specified");
	}
    break;

  case 898:

    {	
	parserData->kounter++;
}
    break;

  case 899:

    {	
	if (parserData->kounter >= parserData->numberOfCon)
		osolerror(NULL, NULL, parserData, osglData, "more <con> elements than specified");
	parserData->idxAttributePresent = false;
	parserData->lbValueAttributePresent = false;
	parserData->ubValueAttributePresent = false;
	parserData->lbDualValue = 0;
	parserData->ubDualValue = 0;
}
    break;

  case 900:

    {
	parserData->lbValArray[parserData->kounter] = parserData->lbDualValue;
	parserData->ubValArray[parserData->kounter] = parserData->ubDualValue;
}
    break;

  case 903:

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
	if (osoption->setInitBasisStatus(ENUM_PROBLEM_COMPONENT_constraints, ENUM_BASIS_STATUS_basic, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
		osolerror(NULL, NULL, parserData, osglData, "set slacks basic failed");	
	delete[] osglData->osglIntArray;
	osglData->osglIntArray = NULL;
}
    break;

  case 918:

    {
	osglData->osglNumberOfEl = 0;
	osglData->osglNumberOfElPresent= false;
}
    break;

  case 919:

    {
	osglData->osglCounter = 0; 
	osglData->osglNumberOfEl = parserData->numberOf;
	osglData->osglIntArray = new int[parserData->numberOf];
}
    break;

  case 926:

    {
	if (osoption->setInitBasisStatus(ENUM_PROBLEM_COMPONENT_constraints, ENUM_BASIS_STATUS_atLower, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
		osolerror(NULL, NULL, parserData, osglData, "set slacks atLower failed");	
	delete[] osglData->osglIntArray;
	osglData->osglIntArray = NULL;
}
    break;

  case 927:

    {
	osglData->osglNumberOfEl = 0;
	osglData->osglNumberOfElPresent= false;
}
    break;

  case 928:

    {
	osglData->osglCounter = 0; 
	osglData->osglNumberOfEl = parserData->numberOf;
	osglData->osglIntArray = new int[parserData->numberOf];
}
    break;

  case 935:

    {
	if (osoption->setInitBasisStatus(ENUM_PROBLEM_COMPONENT_constraints, ENUM_BASIS_STATUS_atUpper, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
		osolerror(NULL, NULL, parserData, osglData, "set slacks atUpper failed");	
	delete[] osglData->osglIntArray;
	osglData->osglIntArray = NULL;
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
	if (osoption->setInitBasisStatus(ENUM_PROBLEM_COMPONENT_constraints, ENUM_BASIS_STATUS_isFree, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
		osolerror(NULL, NULL, parserData, osglData, "set slacks isFree failed");	
	delete[] osglData->osglIntArray;
	osglData->osglIntArray = NULL;
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
	if (osoption->setInitBasisStatus(ENUM_PROBLEM_COMPONENT_constraints, ENUM_BASIS_STATUS_superbasic, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
		osolerror(NULL, NULL, parserData, osglData, "set variables superbasic failed");	
	delete[] osglData->osglIntArray;
	osglData->osglIntArray = NULL;
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
	if (osoption->setInitBasisStatus(ENUM_PROBLEM_COMPONENT_constraints, ENUM_BASIS_STATUS_unknown, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
		osolerror(NULL, NULL, parserData, osglData, "set slacks unknown failed");	
	delete[] osglData->osglIntArray;
	osglData->osglIntArray = NULL;
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

  case 972:

    { 	 
		parserData->iOther++;  
	}
    break;

  case 973:

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

  case 974:

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

  case 977:

    {
		parserData->kounter = 0;
	}
    break;

  case 978:

    {
		parserData->kounter = 0;
	}
    break;

  case 994:

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
}
    break;

  case 995:

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
}
    break;

  case 999:

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

  case 1009:

    {
	if (!osoption->setNumberOfSolverOptions(parserData->numberOfSolverOptions) )
		osolerror( NULL, osoption, parserData, osglData, "setNumberOfSolverOptions failed");
	parserData->iOption = 0;
}
    break;

  case 1010:

    {
		if (parserData->numberOfSolverOptions > 0)
			osolerror(NULL, NULL, parserData, osglData, "expected at least one <solverOption> element");
	}
    break;

  case 1011:

    {
		if (parserData->iOption != parserData->numberOfSolverOptions)
			osolerror(NULL, NULL, parserData, osglData, "fewer <solverOption> elements than specified");
	}
    break;

  case 1016:

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

  case 1017:

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

  case 1018:

    {
	if (!parserData->nameAttributePresent)
		osolerror (NULL, osoption, parserData, osglData, "name attribute must be present");
}
    break;

  case 1027:

    {
			parserData->itemList = new std::string[parserData->numberOfItems];
    }
    break;

  case 1028:

    {	if (parserData->numberOfItems > 0)
			osolerror(NULL, NULL, parserData, osglData, "expected at least one <item> element");
	}
    break;

  case 1029:

    {	if (parserData->kounter != parserData->numberOfItems)
			osolerror(NULL, NULL, parserData, osglData, "fewer <item> elements than specified");
	}
    break;

  case 1036:

    {	
	parserData->itemList[parserData->kounter] = parserData->itemContent;
	parserData->kounter++;
}
    break;

  case 1037:

    {
		if (parserData->kounter >= parserData->numberOfItems)
			osolerror(NULL, NULL, parserData, osglData, "more <item> elements than specified");
		parserData->itemContent = "";			
	}
    break;

  case 1042:

    {
	if (parserData->kounter >= parserData->numberOfItems)
		osolerror(NULL, NULL, parserData, osglData, "more <item> elements than specified");
	parserData->itemContent = (yyvsp[(1) - (1)].sval); 
}
    break;

  case 1043:

    {	
	if (!parserData->pathPairFromPresent)
		osolerror (NULL, osoption, parserData, osglData, "\"from\" attribute must be present");
	if (!parserData->pathPairToPresent)
		osolerror (NULL, osoption, parserData, osglData, "\"to\" attribute must be present");
	parserData->kounter++;
}
    break;

  case 1044:

    {
	if (parserData->kounter >= parserData->numberOfPathPairs)
		osolerror (NULL, osoption, parserData, osglData, "too many path pairs");
	parserData->pathPairFromPresent = false;
	parserData->pathPairToPresent = false;
	parserData->pathPairMakeCopyPresent = false;
	parserData->pathPairMakeCopy = false;
}
    break;

  case 1045:

    {
	parserData->makeCopy[parserData->kounter] = parserData->pathPairMakeCopy;
}
    break;

  case 1051:

    {
	if (parserData->pathPairFromPresent)
		osolerror( NULL, osoption, parserData, osglData, "only one \"from\" attribute allowed");
	parserData->pathPairFromPresent = true;
	parserData->fromPaths[parserData->kounter] = (yyvsp[(2) - (3)].sval);
}
    break;

  case 1052:

    {
	if (parserData->pathPairToPresent)
		osolerror( NULL, osoption, parserData, osglData, "only one \"to\" attribute allowed");
	parserData->pathPairToPresent = true;
	parserData->toPaths[parserData->kounter] = (yyvsp[(2) - (3)].sval);
}
    break;

  case 1053:

    {
	if (parserData->pathPairMakeCopyPresent)
		osolerror( NULL, osoption, parserData, osglData, "only one \"makeCopy\" attribute allowed");
	parserData->pathPairMakeCopyPresent = true;
	parserData->pathPairMakeCopy = (strcmp((yyvsp[(2) - (3)].sval),"true") == 0);
}
    break;

  case 1056:

    {   
	if (parserData->categoryAttributePresent ) 
		osolerror(NULL, NULL, parserData, osglData, "only one category attribute allowed for this element");
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
		osolerror(NULL, NULL, parserData, osglData, "only one description attribute allowed for this element");
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
		osolerror(NULL, NULL, parserData, osglData, "only one groupWeight attribute allowed for this element");
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
		osolerror(NULL, NULL, parserData, osglData, "only one idx attribute allowed for this element");
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
		osolerror(NULL, NULL, parserData, osglData, "only one lb attribute allowed for this element");
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
				osolerror(NULL, NULL, parserData, osglData, "only one lb attribute allowed for this element");
			parserData->lbValueAttributePresent = true;
		}
    break;

  case 1079:

    { parserData->lbDualValue = 0.0; }
    break;

  case 1080:

    { parserData->lbDualValue = parserData->tempVal;}
    break;

  case 1081:

    {   if (parserData->nameAttributePresent ) 
				osolerror(NULL, NULL, parserData, osglData, "only one name attribute allowed for this element");
			parserData->nameAttributePresent = true;
		}
    break;

  case 1084:

    { parserData->nameAttribute = ""; }
    break;

  case 1085:

    { 
	parserData->nameAttribute = (yyvsp[(2) - (3)].sval); 
	free((yyvsp[(2) - (3)].sval));
}
    break;

  case 1086:

    {   if (parserData->solverAttributePresent ) 
				osolerror(NULL, NULL, parserData, osglData, "only one solver attribute allowed for this element");
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
			osolerror(NULL, NULL, parserData, osglData, "only one sosIdx attribute allowed for this element");
		parserData->sosIdxAttributePresent = true;
	}
    break;

  case 1093:

    {
	if ((yyvsp[(3) - (4)].ival) < 0)
		osolerror (NULL, osoption, parserData, osglData, "SOS index must be nonnegative");
	parserData->sosIdx = (yyvsp[(3) - (4)].ival);
}
    break;

  case 1094:

    {   if (parserData->typeAttributePresent ) 
				osolerror(NULL, NULL, parserData, osglData, "only one type attribute allowed for this element");
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
		osolerror(NULL, NULL, parserData, osglData, "only one ub attribute allowed for this element");
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
				osolerror(NULL, NULL, parserData, osglData, "only one ub attribute allowed for this element");
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
				osolerror(NULL, NULL, parserData, osglData, "only one unit attribute allowed for this element");
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
				osolerror(NULL, NULL, parserData, osglData, "only one value attribute allowed for this element");
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
		osolerror(NULL, NULL, parserData, osglData, "numberOfCon attribute previously set");
	if ((yyvsp[(3) - (4)].ival) < 0) osolerror(NULL, NULL, parserData, osglData, "number of <con> cannot be negative");
	parserData->numberOfConAttributePresent = true;		
	parserData->numberOfCon = (yyvsp[(3) - (4)].ival);
}
    break;

  case 1120:

    {
	if (parserData->numberOfConstraintsPresent)
		osolerror(NULL, NULL, parserData, osglData, "numberOfConstraints attribute previously set");
	if ((yyvsp[(3) - (4)].ival) < 0) osolerror(NULL, NULL, parserData, osglData, "number of constraints cannot be negative");
	parserData->numberOfConstraintsPresent = true;		
	parserData->tempInt = (yyvsp[(3) - (4)].ival); 
}
    break;

  case 1121:

    {
	if (osglData->osglNumberOfElPresent)
		osolerror(NULL, NULL, parserData, osglData, "numberOfEl attribute previously set");
	if ((yyvsp[(3) - (4)].ival) < 0) osolerror(NULL, NULL, parserData, osglData, "number of <el> cannot be negative");
	osglData->osglNumberOfElPresent = true;
	parserData->numberOf = (yyvsp[(3) - (4)].ival); 
}
    break;

  case 1122:

    {
	if (parserData->numberOfEnumerationsAttributePresent)
		osolerror(NULL, NULL, parserData, osglData, "numberOfEnumerations attribute previously set");
	if ((yyvsp[(3) - (4)].ival) < 0) osolerror(NULL, NULL, parserData, osglData, "number of <enumeration> elements cannot be negative");
	parserData->numberOfEnumerationsAttributePresent = true;		
	parserData->numberOfEnumerations = (yyvsp[(3) - (4)].ival); 
}
    break;

  case 1123:

    {	
   if (parserData->numberOfItemsPresent ) 
        osolerror(NULL, NULL, parserData, osglData, "only one numberOfItems attribute allowed");
	if ((yyvsp[(3) - (4)].ival) < 0) osolerror(NULL, NULL, parserData, osglData, "number of items cannot be negative");
	parserData->numberOfItemsPresent = true;
	parserData->numberOfItems = (yyvsp[(3) - (4)].ival);
}
    break;

  case 1124:

    {
	if ((yyvsp[(3) - (4)].ival) < 0)
		osolerror( NULL, osoption, parserData, osglData, "Number of job IDs cannot be negative");
	parserData->numberOf = (yyvsp[(3) - (4)].ival);
	parserData->kounter = 0;
	parserData->jobDependencies = new std::string[(yyvsp[(3) - (4)].ival)];
}
    break;

  case 1125:

    {
	if (parserData->numberOfObjAttributePresent)
		osolerror(NULL, NULL, parserData, osglData, "numberOfObj attribute previously set");
	if ((yyvsp[(3) - (4)].ival) < 0) osolerror(NULL, NULL, parserData, osglData, "number of <obj> cannot be negative");
	parserData->numberOfObjAttributePresent = true;		
	parserData->numberOfObj = (yyvsp[(3) - (4)].ival);
}
    break;

  case 1126:

    {	if (parserData->numberOfObjectivesPresent)
		osolerror(NULL, NULL, parserData, osglData, "numberOfObjectives attribute previously set");
	if ((yyvsp[(3) - (4)].ival) < 0) osolerror(NULL, NULL, parserData, osglData, "number of objectives cannot be negative");
	parserData->numberOfObjectivesPresent = true;
	parserData->tempInt = (yyvsp[(3) - (4)].ival); 
}
    break;

  case 1127:

    {
	if ((yyvsp[(3) - (4)].ival) < 0) osolerror(NULL, NULL, parserData, osglData, "number of other constraint options cannot be negative");
	parserData->tempInt = (yyvsp[(3) - (4)].ival);
}
    break;

  case 1128:

    {
	if ((yyvsp[(3) - (4)].ival) < 0) osolerror(NULL, NULL, parserData, osglData, "number of other objective options cannot be negative");
	parserData->tempInt = (yyvsp[(3) - (4)].ival);
}
    break;

  case 1129:

    {
	if ((yyvsp[(3) - (4)].ival) < 0) osolerror(NULL, NULL, parserData, osglData, "number of other options cannot be negative");
	parserData->tempInt = (yyvsp[(3) - (4)].ival);
}
    break;

  case 1130:

    {	
	if ((yyvsp[(3) - (4)].ival) < 0) osolerror(NULL, NULL, parserData, osglData, "number of other variable options cannot be negative");
	parserData->tempInt = (yyvsp[(3) - (4)].ival);
}
    break;

  case 1131:

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

  case 1132:

    {
	if ((yyvsp[(3) - (4)].ival) < 0)
		osolerror( NULL, osoption, parserData, osglData, "Number of paths cannot be negative");
	parserData->numberOf = (yyvsp[(3) - (4)].ival);
	parserData->kounter = 0;
	parserData->paths = new std::string[(yyvsp[(3) - (4)].ival)];
}
    break;

  case 1133:

    {
	if ((yyvsp[(3) - (4)].ival) < 0)
		osolerror( NULL, osoption, parserData, osglData, "Number of job IDs cannot be negative");
	parserData->numberOf = (yyvsp[(3) - (4)].ival);
	parserData->kounter = 0;
	parserData->processesToKill = new std::string[(yyvsp[(3) - (4)].ival)];
}
    break;

  case 1134:

    {	
	if ((yyvsp[(3) - (4)].ival) < 0) osolerror(NULL, NULL, parserData, osglData, "number of solver options cannot be negative");
	parserData->numberOfSolverOptions = (yyvsp[(3) - (4)].ival);
}
    break;

  case 1135:

    {
	if (parserData->numberOfVarAttributePresent)
		osolerror(NULL, NULL, parserData, osglData, "numberOfVar attribute previously set");
	if ((yyvsp[(3) - (4)].ival) < 0) osolerror(NULL, NULL, parserData, osglData, "number of <var> cannot be negative");
	parserData->numberOfVarAttributePresent = true;		
	parserData->numberOfVar = (yyvsp[(3) - (4)].ival); 
}
    break;

  case 1136:

    {	if (parserData->numberOfVariablesPresent)
		osolerror(NULL, NULL, parserData, osglData, "numberOfVariables attribute previously set");
	if ((yyvsp[(3) - (4)].ival) < 0) osolerror(NULL, NULL, parserData, osglData, "number of variables cannot be negative");
	parserData->numberOfVariablesPresent = true;	
	parserData->tempInt = (yyvsp[(3) - (4)].ival); 
}
    break;

  case 1139:

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

  case 1140:

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

  case 1141:

    {	if(!osglData->osglNumberOfElPresent) 
			osolerror(NULL, NULL, parserData, osglData, "<other> element enumeration requires numberOfEl attribute"); 
		if(!parserData->valueAttributePresent) 
			osolerror(NULL, NULL, parserData, osglData, "<other> element enumeration requires value attribute"); 
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
	 	if (osglData->osglCounter + osglData->osglMult < osglData->osglNumberOfEl)
		osolerror(NULL, NULL, parserData, osglData, "fewer data elements than specified");
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
		osolerror(NULL, NULL, parserData, osglData, "more data elements than specified");
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
	delete[] b64string;
}
    break;

  case 1171:

    {	
	if (osglData->osglIncrPresent) 
        osolerror(NULL, NULL, parserData, osglData, "only one incr attribute allowed");
	osglData->osglIncrPresent = true;
	osglData->osglIncr = (yyvsp[(3) - (4)].ival);
}
    break;

  case 1172:

    {	
	if (osglData->osglMultPresent) 
        osolerror(NULL, NULL, parserData, osglData, "only one mult attribute allowed");
	if ((yyvsp[(3) - (4)].ival) <= 0) osolerror(NULL, NULL, parserData, osglData, "mult must be positive");
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
	osol_empty_vectors( parserData);
	osgl_empty_vectors( osglData);
	std::ostringstream outStr;
	std::string error = errormsg;
	error = "OSoL input is either not valid or well formed: "  + error;
	outStr << error << std::endl;
	outStr << "Error occurred when reading: " << osolget_text ( scanner ) << std::endl; 
	outStr << "See line number: " << osolget_lineno( scanner) << std::endl; 
	error = outStr.str();
	//printf("THIS DID NOT GET DESTROYED:   %s\n", parserData->errorText);
	//if( (parserData->errorText != NULL) &&  (strlen(parserData->errorText) > 0) ) free(  parserData->errorText);
	//osollex_destroy( scanner);
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


