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
     GENERALSTART = 322,
     GENERALEND = 323,
     SYSTEMSTART = 324,
     SYSTEMEND = 325,
     SERVICESTART = 326,
     SERVICEEND = 327,
     JOBSTART = 328,
     JOBEND = 329,
     OPTIMIZATIONSTART = 330,
     OPTIMIZATIONEND = 331,
     SERVICEURISTART = 332,
     SERVICEURIEND = 333,
     SERVICENAMESTART = 334,
     SERVICENAMEEND = 335,
     INSTANCENAMESTART = 336,
     INSTANCENAMEEND = 337,
     INSTANCELOCATIONSTART = 338,
     INSTANCELOCATIONEND = 339,
     JOBIDSTART = 340,
     JOBIDEND = 341,
     SOLVERTOINVOKESTART = 342,
     SOLVERTOINVOKEEND = 343,
     LICENSESTART = 344,
     LICENSEEND = 345,
     USERNAMESTART = 346,
     USERNAMEEND = 347,
     PASSWORDSTART = 348,
     PASSWORDEND = 349,
     CONTACTSTART = 350,
     CONTACTEND = 351,
     OTHEROPTIONSSTART = 352,
     OTHEROPTIONSEND = 353,
     OTHERSTART = 354,
     OTHEREND = 355,
     MINDISKSPACESTART = 356,
     MINDISKSPACEEND = 357,
     MINMEMORYSTART = 358,
     MINMEMORYEND = 359,
     MINCPUSPEEDSTART = 360,
     MINCPUSPEEDEND = 361,
     MINCPUNUMBERSTART = 362,
     MINCPUNUMBEREND = 363,
     SERVICETYPESTART = 364,
     SERVICETYPEEND = 365,
     MAXTIMESTART = 366,
     MAXTIMEEND = 367,
     REQUESTEDSTARTTIMESTART = 368,
     REQUESTEDSTARTTIMEEND = 369,
     DEPENDENCIESSTART = 370,
     DEPENDENCIESEND = 371,
     REQUIREDDIRECTORIESSTART = 372,
     REQUIREDDIRECTORIESEND = 373,
     REQUIREDFILESSTART = 374,
     REQUIREDFILESEND = 375,
     PATHSTART = 376,
     PATHEND = 377,
     PATHPAIRSTART = 378,
     PATHPAIREND = 379,
     DIRECTORIESTOMAKESTART = 380,
     DIRECTORIESTOMAKEEND = 381,
     FILESTOMAKESTART = 382,
     FILESTOMAKEEND = 383,
     DIRECTORIESTODELETESTART = 384,
     DIRECTORIESTODELETEEND = 385,
     FILESTODELETESTART = 386,
     FILESTODELETEEND = 387,
     INPUTDIRECTORIESTOMOVESTART = 388,
     INPUTDIRECTORIESTOMOVEEND = 389,
     INPUTFILESTOMOVESTART = 390,
     INPUTFILESTOMOVEEND = 391,
     OUTPUTDIRECTORIESTOMOVESTART = 392,
     OUTPUTDIRECTORIESTOMOVEEND = 393,
     OUTPUTFILESTOMOVESTART = 394,
     OUTPUTFILESTOMOVEEND = 395,
     PROCESSESTOKILLSTART = 396,
     PROCESSESTOKILLEND = 397,
     PROCESSSTART = 398,
     PROCESSEND = 399,
     VARIABLESSTART = 400,
     VARIABLESEND = 401,
     INITIALVARIABLEVALUESSTART = 402,
     INITIALVARIABLEVALUESEND = 403,
     VARSTART = 404,
     VAREND = 405,
     INITIALVARIABLEVALUESSTRINGSTART = 406,
     INITIALVARIABLEVALUESSTRINGEND = 407,
     INITIALBASISSTATUSSTART = 408,
     INITIALBASISSTATUSEND = 409,
     BASICSTART = 410,
     BASICEND = 411,
     ATUPPERSTART = 412,
     ATUPPEREND = 413,
     ATLOWERSTART = 414,
     ATLOWEREND = 415,
     SUPERBASICSTART = 416,
     SUPERBASICEND = 417,
     ISFREESTART = 418,
     ISFREEEND = 419,
     UNKNOWNSTART = 420,
     UNKNOWNEND = 421,
     INTEGERVARIABLEBRANCHINGWEIGHTSSTART = 422,
     INTEGERVARIABLEBRANCHINGWEIGHTSEND = 423,
     SOSVARIABLEBRANCHINGWEIGHTSSTART = 424,
     SOSVARIABLEBRANCHINGWEIGHTSEND = 425,
     SOSSTART = 426,
     SOSEND = 427,
     OBJECTIVESSTART = 428,
     OBJECTIVESEND = 429,
     INITIALOBJECTIVEVALUESSTART = 430,
     INITIALOBJECTIVEVALUESEND = 431,
     OBJSTART = 432,
     OBJEND = 433,
     INITIALOBJECTIVEBOUNDSSTART = 434,
     INITIALOBJECTIVEBOUNDSEND = 435,
     CONSTRAINTSSTART = 436,
     CONSTRAINTSEND = 437,
     INITIALCONSTRAINTVALUESSTART = 438,
     INITIALCONSTRAINTVALUESEND = 439,
     CONSTART = 440,
     CONEND = 441,
     INITIALDUALVALUESSTART = 442,
     INITIALDUALVALUESEND = 443,
     SOLVEROPTIONSSTART = 444,
     SOLVEROPTIONSEND = 445,
     SOLVEROPTIONSTART = 446,
     SOLVEROPTIONEND = 447,
     ENUMERATIONSTART = 448,
     ENUMERATIONEND = 449,
     ITEMEMPTY = 450,
     ITEMSTART = 451,
     ITEMEND = 452,
     ITEMSTARTANDEND = 453,
     BASE64START = 454,
     BASE64END = 455,
     INCRATT = 456,
     MULTATT = 457,
     SIZEOFATT = 458,
     ELSTART = 459,
     ELEND = 460,
     DUMMY = 461
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
#define GENERALSTART 322
#define GENERALEND 323
#define SYSTEMSTART 324
#define SYSTEMEND 325
#define SERVICESTART 326
#define SERVICEEND 327
#define JOBSTART 328
#define JOBEND 329
#define OPTIMIZATIONSTART 330
#define OPTIMIZATIONEND 331
#define SERVICEURISTART 332
#define SERVICEURIEND 333
#define SERVICENAMESTART 334
#define SERVICENAMEEND 335
#define INSTANCENAMESTART 336
#define INSTANCENAMEEND 337
#define INSTANCELOCATIONSTART 338
#define INSTANCELOCATIONEND 339
#define JOBIDSTART 340
#define JOBIDEND 341
#define SOLVERTOINVOKESTART 342
#define SOLVERTOINVOKEEND 343
#define LICENSESTART 344
#define LICENSEEND 345
#define USERNAMESTART 346
#define USERNAMEEND 347
#define PASSWORDSTART 348
#define PASSWORDEND 349
#define CONTACTSTART 350
#define CONTACTEND 351
#define OTHEROPTIONSSTART 352
#define OTHEROPTIONSEND 353
#define OTHERSTART 354
#define OTHEREND 355
#define MINDISKSPACESTART 356
#define MINDISKSPACEEND 357
#define MINMEMORYSTART 358
#define MINMEMORYEND 359
#define MINCPUSPEEDSTART 360
#define MINCPUSPEEDEND 361
#define MINCPUNUMBERSTART 362
#define MINCPUNUMBEREND 363
#define SERVICETYPESTART 364
#define SERVICETYPEEND 365
#define MAXTIMESTART 366
#define MAXTIMEEND 367
#define REQUESTEDSTARTTIMESTART 368
#define REQUESTEDSTARTTIMEEND 369
#define DEPENDENCIESSTART 370
#define DEPENDENCIESEND 371
#define REQUIREDDIRECTORIESSTART 372
#define REQUIREDDIRECTORIESEND 373
#define REQUIREDFILESSTART 374
#define REQUIREDFILESEND 375
#define PATHSTART 376
#define PATHEND 377
#define PATHPAIRSTART 378
#define PATHPAIREND 379
#define DIRECTORIESTOMAKESTART 380
#define DIRECTORIESTOMAKEEND 381
#define FILESTOMAKESTART 382
#define FILESTOMAKEEND 383
#define DIRECTORIESTODELETESTART 384
#define DIRECTORIESTODELETEEND 385
#define FILESTODELETESTART 386
#define FILESTODELETEEND 387
#define INPUTDIRECTORIESTOMOVESTART 388
#define INPUTDIRECTORIESTOMOVEEND 389
#define INPUTFILESTOMOVESTART 390
#define INPUTFILESTOMOVEEND 391
#define OUTPUTDIRECTORIESTOMOVESTART 392
#define OUTPUTDIRECTORIESTOMOVEEND 393
#define OUTPUTFILESTOMOVESTART 394
#define OUTPUTFILESTOMOVEEND 395
#define PROCESSESTOKILLSTART 396
#define PROCESSESTOKILLEND 397
#define PROCESSSTART 398
#define PROCESSEND 399
#define VARIABLESSTART 400
#define VARIABLESEND 401
#define INITIALVARIABLEVALUESSTART 402
#define INITIALVARIABLEVALUESEND 403
#define VARSTART 404
#define VAREND 405
#define INITIALVARIABLEVALUESSTRINGSTART 406
#define INITIALVARIABLEVALUESSTRINGEND 407
#define INITIALBASISSTATUSSTART 408
#define INITIALBASISSTATUSEND 409
#define BASICSTART 410
#define BASICEND 411
#define ATUPPERSTART 412
#define ATUPPEREND 413
#define ATLOWERSTART 414
#define ATLOWEREND 415
#define SUPERBASICSTART 416
#define SUPERBASICEND 417
#define ISFREESTART 418
#define ISFREEEND 419
#define UNKNOWNSTART 420
#define UNKNOWNEND 421
#define INTEGERVARIABLEBRANCHINGWEIGHTSSTART 422
#define INTEGERVARIABLEBRANCHINGWEIGHTSEND 423
#define SOSVARIABLEBRANCHINGWEIGHTSSTART 424
#define SOSVARIABLEBRANCHINGWEIGHTSEND 425
#define SOSSTART 426
#define SOSEND 427
#define OBJECTIVESSTART 428
#define OBJECTIVESEND 429
#define INITIALOBJECTIVEVALUESSTART 430
#define INITIALOBJECTIVEVALUESEND 431
#define OBJSTART 432
#define OBJEND 433
#define INITIALOBJECTIVEBOUNDSSTART 434
#define INITIALOBJECTIVEBOUNDSEND 435
#define CONSTRAINTSSTART 436
#define CONSTRAINTSEND 437
#define INITIALCONSTRAINTVALUESSTART 438
#define INITIALCONSTRAINTVALUESEND 439
#define CONSTART 440
#define CONEND 441
#define INITIALDUALVALUESSTART 442
#define INITIALDUALVALUESEND 443
#define SOLVEROPTIONSSTART 444
#define SOLVEROPTIONSEND 445
#define SOLVEROPTIONSTART 446
#define SOLVEROPTIONEND 447
#define ENUMERATIONSTART 448
#define ENUMERATIONEND 449
#define ITEMEMPTY 450
#define ITEMSTART 451
#define ITEMEND 452
#define ITEMSTARTANDEND 453
#define BASE64START 454
#define BASE64END 455
#define INCRATT 456
#define MULTATT 457
#define SIZEOFATT 458
#define ELSTART 459
#define ELEND 460
#define DUMMY 461




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
#define YYLAST   1253

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  211
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  775
/* YYNRULES -- Number of rules.  */
#define YYNRULES  1138
/* YYNRULES -- Number of states.  */
#define YYNSTATES  1583

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   461

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,   208,
     210,     2,     2,   209,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,   207,     2,     2,     2,     2,     2,     2,     2,
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
     205,   206
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     7,    11,    13,    15,    16,    18,    20,
      22,    24,    28,    34,    35,    38,    40,    42,    44,    47,
      49,    53,    55,    57,    60,    62,    64,    66,    68,    70,
      72,    74,    76,    78,    80,    82,    85,    87,    89,    91,
      94,    96,   100,   102,   105,   107,   109,   111,   114,   116,
     120,   122,   125,   127,   129,   131,   134,   136,   140,   142,
     146,   148,   149,   151,   155,   157,   159,   162,   164,   168,
     170,   173,   175,   177,   179,   182,   184,   188,   190,   193,
     195,   197,   199,   202,   204,   208,   210,   213,   215,   217,
     219,   222,   224,   228,   230,   233,   235,   237,   239,   242,
     244,   248,   250,   253,   255,   257,   259,   262,   264,   268,
     270,   274,   276,   277,   279,   283,   285,   287,   290,   292,
     296,   298,   302,   304,   306,   308,   310,   313,   315,   319,
     321,   323,   326,   330,   332,   334,   335,   338,   340,   342,
     344,   347,   349,   350,   353,   355,   357,   359,   362,   364,
     368,   370,   372,   375,   377,   379,   381,   383,   385,   389,
     391,   393,   394,   397,   399,   401,   405,   407,   411,   413,
     415,   416,   419,   421,   423,   427,   429,   433,   435,   437,
     438,   441,   443,   445,   449,   451,   455,   457,   458,   460,
     464,   466,   470,   472,   474,   476,   478,   481,   483,   487,
     489,   491,   494,   498,   500,   502,   503,   506,   508,   510,
     512,   515,   517,   518,   521,   523,   525,   527,   530,   532,
     536,   538,   540,   543,   545,   547,   550,   552,   554,   556,
     559,   561,   565,   567,   571,   573,   575,   577,   579,   582,
     584,   588,   590,   592,   595,   599,   601,   603,   604,   607,
     609,   611,   613,   616,   618,   619,   622,   624,   626,   628,
     631,   633,   637,   639,   641,   644,   646,   648,   650,   652,
     654,   656,   658,   660,   662,   664,   666,   668,   670,   672,
     674,   678,   680,   682,   684,   686,   689,   691,   695,   697,
     699,   702,   704,   706,   708,   711,   713,   717,   719,   723,
     725,   727,   729,   731,   734,   736,   740,   742,   745,   750,
     754,   756,   758,   760,   762,   765,   767,   771,   773,   776,
     781,   785,   787,   789,   791,   793,   796,   798,   802,   804,
     807,   812,   816,   818,   820,   822,   824,   827,   829,   833,
     835,   838,   843,   847,   849,   851,   853,   855,   858,   860,
     864,   866,   869,   874,   878,   880,   882,   884,   886,   889,
     891,   895,   897,   900,   902,   906,   908,   910,   912,   914,
     917,   919,   923,   925,   928,   930,   934,   936,   938,   940,
     942,   945,   947,   951,   953,   956,   958,   962,   964,   966,
     968,   970,   973,   975,   979,   981,   984,   986,   990,   992,
     994,   996,   998,  1001,  1003,  1007,  1009,  1012,  1017,  1021,
    1023,  1025,  1027,  1029,  1032,  1034,  1038,  1040,  1043,  1048,
    1052,  1054,  1056,  1058,  1060,  1063,  1065,  1069,  1071,  1074,
    1079,  1083,  1085,  1087,  1089,  1091,  1094,  1096,  1100,  1102,
    1104,  1107,  1111,  1113,  1115,  1116,  1119,  1121,  1123,  1125,
    1128,  1130,  1131,  1135,  1137,  1139,  1140,  1143,  1145,  1147,
    1149,  1151,  1153,  1155,  1159,  1164,  1165,  1169,  1171,  1173,
    1174,  1176,  1178,  1180,  1182,  1186,  1193,  1194,  1198,  1200,
    1202,  1204,  1206,  1209,  1211,  1215,  1217,  1219,  1222,  1226,
    1228,  1229,  1232,  1234,  1236,  1239,  1241,  1242,  1246,  1248,
    1250,  1252,  1254,  1257,  1259,  1263,  1265,  1267,  1270,  1274,
    1276,  1278,  1279,  1282,  1284,  1286,  1289,  1291,  1292,  1295,
    1297,  1299,  1301,  1303,  1307,  1314,  1315,  1319,  1321,  1323,
    1325,  1327,  1329,  1333,  1335,  1336,  1340,  1342,  1344,  1346,
    1348,  1350,  1354,  1356,  1357,  1361,  1363,  1365,  1367,  1369,
    1371,  1375,  1377,  1378,  1382,  1384,  1386,  1388,  1390,  1392,
    1396,  1398,  1399,  1403,  1405,  1407,  1409,  1411,  1413,  1417,
    1419,  1420,  1424,  1426,  1428,  1430,  1432,  1434,  1438,  1440,
    1441,  1445,  1447,  1449,  1451,  1453,  1456,  1458,  1462,  1464,
    1466,  1469,  1473,  1475,  1477,  1478,  1481,  1483,  1485,  1488,
    1490,  1491,  1495,  1497,  1502,  1504,  1506,  1509,  1511,  1515,
    1517,  1520,  1524,  1526,  1528,  1529,  1532,  1534,  1536,  1538,
    1540,  1542,  1545,  1547,  1551,  1552,  1555,  1559,  1561,  1563,
    1564,  1567,  1569,  1571,  1573,  1575,  1577,  1579,  1581,  1583,
    1585,  1587,  1590,  1592,  1596,  1598,  1600,  1602,  1605,  1609,
    1611,  1613,  1614,  1617,  1619,  1621,  1623,  1625,  1627,  1630,
    1632,  1633,  1637,  1639,  1641,  1642,  1644,  1646,  1648,  1650,
    1654,  1659,  1660,  1664,  1666,  1668,  1670,  1672,  1675,  1677,
    1681,  1683,  1685,  1688,  1692,  1694,  1696,  1697,  1700,  1702,
    1704,  1707,  1709,  1710,  1714,  1716,  1718,  1720,  1722,  1725,
    1727,  1731,  1733,  1735,  1738,  1742,  1744,  1746,  1747,  1750,
    1752,  1754,  1756,  1759,  1761,  1762,  1765,  1767,  1769,  1771,
    1773,  1777,  1784,  1785,  1789,  1791,  1793,  1795,  1797,  1799,
    1803,  1805,  1806,  1810,  1812,  1814,  1816,  1818,  1820,  1824,
    1826,  1827,  1831,  1833,  1835,  1837,  1839,  1841,  1845,  1847,
    1848,  1852,  1854,  1856,  1858,  1860,  1862,  1866,  1868,  1869,
    1873,  1875,  1877,  1879,  1881,  1883,  1887,  1889,  1890,  1894,
    1896,  1898,  1900,  1902,  1904,  1908,  1910,  1911,  1914,  1918,
    1920,  1922,  1923,  1926,  1928,  1930,  1932,  1934,  1936,  1938,
    1940,  1942,  1944,  1946,  1949,  1951,  1955,  1957,  1959,  1961,
    1964,  1968,  1970,  1972,  1973,  1976,  1978,  1980,  1982,  1984,
    1986,  1989,  1991,  1992,  1996,  1998,  2000,  2001,  2003,  2005,
    2007,  2009,  2013,  2018,  2019,  2023,  2025,  2027,  2029,  2031,
    2034,  2036,  2040,  2042,  2044,  2047,  2051,  2053,  2054,  2057,
    2059,  2061,  2064,  2066,  2067,  2071,  2073,  2075,  2077,  2079,
    2082,  2084,  2088,  2090,  2092,  2095,  2099,  2101,  2103,  2104,
    2107,  2109,  2111,  2113,  2116,  2118,  2119,  2122,  2124,  2126,
    2128,  2130,  2134,  2141,  2142,  2146,  2148,  2150,  2152,  2154,
    2156,  2160,  2162,  2163,  2167,  2169,  2171,  2173,  2175,  2177,
    2181,  2183,  2184,  2188,  2190,  2192,  2194,  2196,  2198,  2202,
    2204,  2205,  2209,  2211,  2213,  2215,  2217,  2219,  2223,  2225,
    2226,  2230,  2232,  2234,  2236,  2238,  2240,  2244,  2246,  2247,
    2251,  2253,  2255,  2257,  2259,  2261,  2265,  2267,  2268,  2271,
    2275,  2277,  2279,  2280,  2283,  2285,  2287,  2289,  2291,  2293,
    2295,  2297,  2299,  2301,  2303,  2306,  2308,  2312,  2314,  2316,
    2318,  2321,  2325,  2327,  2329,  2330,  2333,  2335,  2337,  2339,
    2341,  2343,  2346,  2348,  2349,  2353,  2355,  2357,  2359,  2361,
    2363,  2367,  2368,  2371,  2375,  2377,  2379,  2381,  2384,  2386,
    2388,  2390,  2392,  2394,  2396,  2398,  2400,  2402,  2405,  2407,
    2411,  2413,  2415,  2418,  2420,  2422,  2424,  2426,  2428,  2432,
    2434,  2438,  2440,  2442,  2443,  2446,  2448,  2450,  2452,  2456,
    2460,  2464,  2467,  2469,  2471,  2473,  2475,  2477,  2481,  2483,
    2485,  2487,  2489,  2493,  2495,  2500,  2502,  2504,  2509,  2511,
    2513,  2515,  2517,  2521,  2523,  2525,  2527,  2529,  2534,  2536,
    2538,  2540,  2542,  2546,  2548,  2550,  2552,  2554,  2558,  2560,
    2562,  2567,  2569,  2571,  2573,  2575,  2579,  2581,  2583,  2585,
    2587,  2591,  2593,  2595,  2597,  2599,  2604,  2606,  2608,  2610,
    2612,  2616,  2618,  2620,  2622,  2624,  2628,  2633,  2638,  2643,
    2648,  2653,  2658,  2663,  2668,  2673,  2678,  2683,  2688,  2693,
    2698,  2703,  2708,  2713,  2718,  2720,  2723,  2727,  2729,  2731,
    2732,  2735,  2737,  2739,  2741,  2743,  2745,  2747,  2751,  2753,
    2755,  2757,  2758,  2761,  2765,  2767,  2769,  2770,  2773,  2775,
    2777,  2781,  2785,  2790,  2792,  2794,  2797,  2799,  2803,  2808,
    2813,  2815,  2817,  2820,  2821,  2824,  2826,  2828,  2830
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     212,     0,    -1,   213,   219,    15,    -1,   214,   215,   216,
      -1,    13,    -1,    12,    -1,    -1,    14,    -1,   217,    -1,
     218,    -1,    11,    -1,    10,   219,    15,    -1,   220,   306,
     354,   382,   514,    -1,    -1,   221,   222,    -1,    67,    -1,
     223,    -1,   224,    -1,    10,    68,    -1,    11,    -1,    10,
     225,    68,    -1,   226,    -1,   227,    -1,   226,   227,    -1,
     228,    -1,   234,    -1,   240,    -1,   246,    -1,   254,    -1,
     260,    -1,   266,    -1,   272,    -1,   278,    -1,   284,    -1,
     292,    -1,   229,   230,    -1,    77,    -1,   231,    -1,   232,
      -1,    10,    78,    -1,    11,    -1,    10,   233,    78,    -1,
       4,    -1,   235,   236,    -1,    79,    -1,   237,    -1,   238,
      -1,    10,    80,    -1,    11,    -1,    10,   239,    80,    -1,
       4,    -1,   241,   242,    -1,    81,    -1,   243,    -1,   244,
      -1,    10,    82,    -1,    11,    -1,    10,   245,    82,    -1,
       4,    -1,   247,   248,   250,    -1,    83,    -1,    -1,   249,
      -1,    66,     3,     8,    -1,   251,    -1,   252,    -1,    10,
      84,    -1,    11,    -1,    10,   253,    84,    -1,     4,    -1,
     255,   256,    -1,    85,    -1,   257,    -1,   258,    -1,    10,
      86,    -1,    11,    -1,    10,   259,    86,    -1,     4,    -1,
     261,   262,    -1,    87,    -1,   263,    -1,   264,    -1,    10,
      88,    -1,    11,    -1,    10,   265,    88,    -1,     4,    -1,
     267,   268,    -1,    89,    -1,   269,    -1,   270,    -1,    10,
      90,    -1,    11,    -1,    10,   271,    90,    -1,     4,    -1,
     273,   274,    -1,    91,    -1,   275,    -1,   276,    -1,    10,
      92,    -1,    11,    -1,    10,   277,    92,    -1,     4,    -1,
     279,   280,    -1,    93,    -1,   281,    -1,   282,    -1,    10,
      94,    -1,    11,    -1,    10,   283,    94,    -1,     4,    -1,
     285,   286,   288,    -1,    95,    -1,    -1,   287,    -1,    65,
       3,     8,    -1,   289,    -1,   290,    -1,    10,    96,    -1,
      11,    -1,    10,   291,    96,    -1,     4,    -1,   293,   294,
     295,    -1,    97,    -1,   949,    -1,   296,    -1,   297,    -1,
      10,    98,    -1,    11,    -1,    10,   298,    98,    -1,   299,
      -1,   300,    -1,   299,   300,    -1,   301,   302,   305,    -1,
      99,    -1,   303,    -1,    -1,   303,   304,    -1,   908,    -1,
     935,    -1,   891,    -1,    10,   100,    -1,    11,    -1,    -1,
     307,   308,    -1,    69,    -1,   309,    -1,   310,    -1,    10,
      70,    -1,    11,    -1,    10,   311,    70,    -1,   312,    -1,
     313,    -1,   312,   313,    -1,   314,    -1,   321,    -1,   328,
      -1,   335,    -1,   340,    -1,   315,   316,   319,    -1,   101,
      -1,   317,    -1,    -1,   317,   318,    -1,   931,    -1,   891,
      -1,    10,   320,   102,    -1,   982,    -1,   322,   323,   326,
      -1,   103,    -1,   324,    -1,    -1,   324,   325,    -1,   931,
      -1,   891,    -1,    10,   327,   104,    -1,   982,    -1,   329,
     330,   333,    -1,   105,    -1,   331,    -1,    -1,   331,   332,
      -1,   931,    -1,   891,    -1,    10,   334,   106,    -1,   982,
      -1,   336,   337,   338,    -1,   107,    -1,    -1,   891,    -1,
      10,   339,   108,    -1,     6,    -1,   341,   342,   343,    -1,
      97,    -1,   949,    -1,   344,    -1,   345,    -1,    10,    98,
      -1,    11,    -1,    10,   346,    98,    -1,   347,    -1,   348,
      -1,   347,   348,    -1,   349,   350,   353,    -1,    99,    -1,
     351,    -1,    -1,   351,   352,    -1,   908,    -1,   935,    -1,
     891,    -1,    10,   100,    -1,    11,    -1,    -1,   355,   356,
      -1,    71,    -1,   357,    -1,   358,    -1,    10,    72,    -1,
      11,    -1,    10,   359,    72,    -1,   360,    -1,   361,    -1,
     360,   361,    -1,   362,    -1,   368,    -1,   363,   364,    -1,
     109,    -1,   365,    -1,   366,    -1,    10,   110,    -1,    11,
      -1,    10,   367,   110,    -1,     4,    -1,   369,   370,   371,
      -1,    97,    -1,   949,    -1,   372,    -1,   373,    -1,    10,
      98,    -1,    11,    -1,    10,   374,    98,    -1,   375,    -1,
     376,    -1,   375,   376,    -1,   377,   378,   381,    -1,    99,
      -1,   379,    -1,    -1,   379,   380,    -1,   908,    -1,   935,
      -1,   891,    -1,    10,   100,    -1,    11,    -1,    -1,   383,
     384,    -1,    73,    -1,   385,    -1,   386,    -1,    10,    74,
      -1,    11,    -1,    10,   387,    74,    -1,   388,    -1,   389,
      -1,   388,   389,    -1,   390,    -1,   398,    -1,   404,    -1,
     412,    -1,   420,    -1,   428,    -1,   436,    -1,   444,    -1,
     452,    -1,   468,    -1,   460,    -1,   476,    -1,   484,    -1,
     492,    -1,   500,    -1,   391,   392,   393,    -1,   111,    -1,
     931,    -1,   394,    -1,   395,    -1,    10,   112,    -1,    11,
      -1,    10,   396,   112,    -1,   397,    -1,   982,    -1,   399,
     400,    -1,   113,    -1,   401,    -1,   402,    -1,    10,   114,
      -1,    11,    -1,    10,   403,   114,    -1,     4,    -1,   405,
     406,   407,    -1,   115,    -1,   944,    -1,   408,    -1,   409,
      -1,    10,   116,    -1,    11,    -1,    10,   410,   116,    -1,
     411,    -1,   410,   411,    -1,    85,    10,     4,    86,    -1,
     413,   414,   415,    -1,   117,    -1,   952,    -1,   416,    -1,
     417,    -1,    10,   118,    -1,    11,    -1,    10,   418,   118,
      -1,   419,    -1,   418,   419,    -1,   121,    10,     4,   122,
      -1,   421,   422,   423,    -1,   119,    -1,   952,    -1,   424,
      -1,   425,    -1,    10,   120,    -1,    11,    -1,    10,   426,
     120,    -1,   427,    -1,   426,   427,    -1,   121,    10,     4,
     122,    -1,   429,   430,   431,    -1,   125,    -1,   952,    -1,
     432,    -1,   433,    -1,    10,   126,    -1,    11,    -1,    10,
     434,   126,    -1,   435,    -1,   434,   435,    -1,   121,    10,
       4,   122,    -1,   437,   438,   439,    -1,   127,    -1,   952,
      -1,   440,    -1,   441,    -1,    10,   128,    -1,    11,    -1,
      10,   442,   128,    -1,   443,    -1,   442,   443,    -1,   121,
      10,     4,   122,    -1,   445,   446,   447,    -1,   133,    -1,
     951,    -1,   448,    -1,   449,    -1,    10,   134,    -1,    11,
      -1,    10,   450,   134,    -1,   451,    -1,   450,   451,    -1,
     878,    -1,   453,   454,   455,    -1,   135,    -1,   951,    -1,
     456,    -1,   457,    -1,    10,   136,    -1,    11,    -1,    10,
     458,   136,    -1,   459,    -1,   458,   459,    -1,   878,    -1,
     461,   462,   463,    -1,   139,    -1,   951,    -1,   464,    -1,
     465,    -1,    10,   140,    -1,    11,    -1,    10,   466,   140,
      -1,   467,    -1,   466,   467,    -1,   878,    -1,   469,   470,
     471,    -1,   137,    -1,   951,    -1,   472,    -1,   473,    -1,
      10,   138,    -1,    11,    -1,    10,   474,   138,    -1,   475,
      -1,   474,   475,    -1,   878,    -1,   477,   478,   479,    -1,
     131,    -1,   952,    -1,   480,    -1,   481,    -1,    10,   132,
      -1,    11,    -1,    10,   482,   132,    -1,   483,    -1,   482,
     483,    -1,   121,    10,     4,   122,    -1,   485,   486,   487,
      -1,   129,    -1,   952,    -1,   488,    -1,   489,    -1,    10,
     130,    -1,    11,    -1,    10,   490,   130,    -1,   491,    -1,
     490,   491,    -1,   121,    10,     4,   122,    -1,   493,   494,
     495,    -1,   141,    -1,   953,    -1,   496,    -1,   497,    -1,
      10,   142,    -1,    11,    -1,    10,   498,   142,    -1,   499,
      -1,   498,   499,    -1,   143,    10,     4,   144,    -1,   501,
     502,   503,    -1,    97,    -1,   949,    -1,   504,    -1,   505,
      -1,    10,    98,    -1,    11,    -1,    10,   506,    98,    -1,
     507,    -1,   508,    -1,   507,   508,    -1,   509,   510,   513,
      -1,    99,    -1,   511,    -1,    -1,   511,   512,    -1,   908,
      -1,   935,    -1,   891,    -1,    10,   100,    -1,    11,    -1,
      -1,   515,   516,   519,    -1,    75,    -1,   517,    -1,    -1,
     517,   518,    -1,   956,    -1,   940,    -1,   946,    -1,   520,
      -1,   521,    -1,    11,    -1,    10,   522,    76,    -1,   523,
     653,   755,   856,    -1,    -1,   524,   525,   527,    -1,   145,
      -1,   526,    -1,    -1,   950,    -1,   528,    -1,   529,    -1,
      11,    -1,    10,   530,   146,    -1,   531,   544,   558,   606,
     620,   635,    -1,    -1,   532,   533,   534,    -1,   147,    -1,
     955,    -1,   535,    -1,   536,    -1,    10,   148,    -1,    11,
      -1,    10,   537,   148,    -1,   538,    -1,   539,    -1,   538,
     539,    -1,   540,   541,   543,    -1,   149,    -1,    -1,   541,
     542,    -1,   897,    -1,   935,    -1,    10,   150,    -1,    11,
      -1,    -1,   545,   546,   547,    -1,   151,    -1,   955,    -1,
     548,    -1,   549,    -1,    10,   152,    -1,    11,    -1,    10,
     550,   152,    -1,   551,    -1,   552,    -1,   551,   552,    -1,
     553,   554,   557,    -1,   149,    -1,   555,    -1,    -1,   555,
     556,    -1,   897,    -1,   935,    -1,    10,   150,    -1,    11,
      -1,    -1,   559,   560,    -1,   153,    -1,   561,    -1,   562,
      -1,    11,    -1,    10,   563,   154,    -1,   564,   571,   578,
     585,   592,   599,    -1,    -1,   565,   566,   567,    -1,   155,
      -1,   941,    -1,   568,    -1,   569,    -1,    11,    -1,    10,
     570,   156,    -1,   967,    -1,    -1,   572,   573,   574,    -1,
     159,    -1,   941,    -1,   575,    -1,   576,    -1,    11,    -1,
      10,   577,   160,    -1,   967,    -1,    -1,   579,   580,   581,
      -1,   157,    -1,   941,    -1,   582,    -1,   583,    -1,    11,
      -1,    10,   584,   158,    -1,   967,    -1,    -1,   586,   587,
     588,    -1,   163,    -1,   941,    -1,   589,    -1,   590,    -1,
      11,    -1,    10,   591,   164,    -1,   967,    -1,    -1,   593,
     594,   595,    -1,   161,    -1,   941,    -1,   596,    -1,   597,
      -1,    11,    -1,    10,   598,   162,    -1,   967,    -1,    -1,
     600,   601,   602,    -1,   165,    -1,   941,    -1,   603,    -1,
     604,    -1,    11,    -1,    10,   605,   166,    -1,   967,    -1,
      -1,   607,   608,   609,    -1,   167,    -1,   955,    -1,   610,
      -1,   611,    -1,    10,   168,    -1,    11,    -1,    10,   612,
     168,    -1,   613,    -1,   614,    -1,   613,   614,    -1,   615,
     616,   619,    -1,   149,    -1,   617,    -1,    -1,   617,   618,
      -1,   897,    -1,   935,    -1,    10,   150,    -1,    11,    -1,
      -1,   621,   622,   623,    -1,   169,    -1,    29,     8,     6,
       8,    -1,   624,    -1,   625,    -1,    10,   170,    -1,    11,
      -1,    10,   626,   170,    -1,   627,    -1,   626,   627,    -1,
     628,   629,   632,    -1,   171,    -1,   630,    -1,    -1,   630,
     631,    -1,   916,    -1,   955,    -1,   895,    -1,   633,    -1,
     634,    -1,    10,   172,    -1,    11,    -1,    10,   613,   172,
      -1,    -1,   635,   636,    -1,   637,   638,   641,    -1,    99,
      -1,   639,    -1,    -1,   639,   640,    -1,   955,    -1,   942,
      -1,   908,    -1,   935,    -1,   912,    -1,   887,    -1,   919,
      -1,   891,    -1,   642,    -1,   643,    -1,    10,   100,    -1,
      11,    -1,    10,   644,   100,    -1,   645,    -1,   957,    -1,
     646,    -1,   645,   646,    -1,   647,   648,   651,    -1,   149,
      -1,   649,    -1,    -1,   649,   650,    -1,   897,    -1,   935,
      -1,   900,    -1,   923,    -1,   652,    -1,    10,   150,    -1,
      11,    -1,    -1,   654,   655,   657,    -1,   173,    -1,   656,
      -1,    -1,   948,    -1,   658,    -1,   659,    -1,    11,    -1,
      10,   660,   174,    -1,   661,   675,   689,   737,    -1,    -1,
     662,   663,   664,    -1,   175,    -1,   945,    -1,   665,    -1,
     666,    -1,    10,   176,    -1,    11,    -1,    10,   667,   176,
      -1,   668,    -1,   669,    -1,   668,   669,    -1,   670,   671,
     674,    -1,   177,    -1,   672,    -1,    -1,   672,   673,    -1,
     897,    -1,   935,    -1,    10,   178,    -1,    11,    -1,    -1,
     676,   677,   678,    -1,   179,    -1,   945,    -1,   679,    -1,
     680,    -1,    10,   180,    -1,    11,    -1,    10,   681,   180,
      -1,   682,    -1,   683,    -1,   682,   683,    -1,   684,   685,
     688,    -1,   177,    -1,   686,    -1,    -1,   686,   687,    -1,
     897,    -1,   900,    -1,   923,    -1,    10,   178,    -1,    11,
      -1,    -1,   690,   691,    -1,   153,    -1,   692,    -1,   693,
      -1,    11,    -1,    10,   694,   154,    -1,   695,   702,   709,
     716,   723,   730,    -1,    -1,   696,   697,   698,    -1,   155,
      -1,   941,    -1,   699,    -1,   700,    -1,    11,    -1,    10,
     701,   156,    -1,   967,    -1,    -1,   703,   704,   705,    -1,
     159,    -1,   941,    -1,   706,    -1,   707,    -1,    11,    -1,
      10,   708,   160,    -1,   967,    -1,    -1,   710,   711,   712,
      -1,   157,    -1,   941,    -1,   713,    -1,   714,    -1,    11,
      -1,    10,   715,   158,    -1,   967,    -1,    -1,   717,   718,
     719,    -1,   163,    -1,   941,    -1,   720,    -1,   721,    -1,
      11,    -1,    10,   722,   164,    -1,   967,    -1,    -1,   724,
     725,   726,    -1,   161,    -1,   941,    -1,   727,    -1,   728,
      -1,    11,    -1,    10,   729,   162,    -1,   967,    -1,    -1,
     731,   732,   733,    -1,   165,    -1,   941,    -1,   734,    -1,
     735,    -1,    11,    -1,    10,   736,   166,    -1,   967,    -1,
      -1,   737,   738,    -1,   739,   740,   743,    -1,    99,    -1,
     741,    -1,    -1,   741,   742,    -1,   945,    -1,   942,    -1,
     908,    -1,   935,    -1,   912,    -1,   887,    -1,   919,    -1,
     891,    -1,   744,    -1,   745,    -1,    10,   100,    -1,    11,
      -1,    10,   746,   100,    -1,   747,    -1,   957,    -1,   748,
      -1,   747,   748,    -1,   749,   750,   753,    -1,   177,    -1,
     751,    -1,    -1,   751,   752,    -1,   897,    -1,   935,    -1,
     900,    -1,   923,    -1,   754,    -1,    10,   178,    -1,    11,
      -1,    -1,   756,   757,   759,    -1,   181,    -1,   758,    -1,
      -1,   947,    -1,   760,    -1,   761,    -1,    11,    -1,    10,
     762,   182,    -1,   763,   776,   790,   838,    -1,    -1,   764,
     765,   766,    -1,   183,    -1,   939,    -1,   767,    -1,   768,
      -1,    10,   184,    -1,    11,    -1,    10,   769,   184,    -1,
     770,    -1,   771,    -1,   770,   771,    -1,   772,   773,   775,
      -1,   185,    -1,    -1,   773,   774,    -1,   897,    -1,   935,
      -1,    10,   186,    -1,    11,    -1,    -1,   777,   778,   779,
      -1,   187,    -1,   939,    -1,   780,    -1,   781,    -1,    10,
     188,    -1,    11,    -1,    10,   782,   188,    -1,   783,    -1,
     784,    -1,   783,   784,    -1,   785,   786,   789,    -1,   185,
      -1,   787,    -1,    -1,   787,   788,    -1,   897,    -1,   904,
      -1,   927,    -1,    10,   186,    -1,    11,    -1,    -1,   791,
     792,    -1,   153,    -1,   793,    -1,   794,    -1,    11,    -1,
      10,   795,   154,    -1,   796,   803,   810,   817,   824,   831,
      -1,    -1,   797,   798,   799,    -1,   155,    -1,   941,    -1,
     800,    -1,   801,    -1,    11,    -1,    10,   802,   156,    -1,
     967,    -1,    -1,   804,   805,   806,    -1,   159,    -1,   941,
      -1,   807,    -1,   808,    -1,    11,    -1,    10,   809,   160,
      -1,   967,    -1,    -1,   811,   812,   813,    -1,   157,    -1,
     941,    -1,   814,    -1,   815,    -1,    11,    -1,    10,   816,
     158,    -1,   967,    -1,    -1,   818,   819,   820,    -1,   163,
      -1,   941,    -1,   821,    -1,   822,    -1,    11,    -1,    10,
     823,   164,    -1,   967,    -1,    -1,   825,   826,   827,    -1,
     161,    -1,   941,    -1,   828,    -1,   829,    -1,    11,    -1,
      10,   830,   162,    -1,   967,    -1,    -1,   832,   833,   834,
      -1,   165,    -1,   941,    -1,   835,    -1,   836,    -1,    11,
      -1,    10,   837,   166,    -1,   967,    -1,    -1,   838,   839,
      -1,   840,   841,   844,    -1,    99,    -1,   842,    -1,    -1,
     842,   843,    -1,   939,    -1,   942,    -1,   908,    -1,   935,
      -1,   912,    -1,   887,    -1,   919,    -1,   891,    -1,   845,
      -1,   846,    -1,    10,   100,    -1,    11,    -1,    10,   847,
     100,    -1,   848,    -1,   957,    -1,   849,    -1,   848,   849,
      -1,   850,   851,   854,    -1,   185,    -1,   852,    -1,    -1,
     852,   853,    -1,   897,    -1,   935,    -1,   900,    -1,   923,
      -1,   855,    -1,    10,   186,    -1,    11,    -1,    -1,   857,
     858,   859,    -1,   189,    -1,   954,    -1,   860,    -1,   861,
      -1,    11,    -1,    10,   862,   190,    -1,    -1,   862,   863,
      -1,   864,   865,   868,    -1,   191,    -1,   866,    -1,   867,
      -1,   866,   867,    -1,   908,    -1,   935,    -1,   912,    -1,
     887,    -1,   919,    -1,   891,    -1,   943,    -1,   869,    -1,
     870,    -1,    10,   192,    -1,    11,    -1,    10,   871,   192,
      -1,   872,    -1,   873,    -1,   872,   873,    -1,   874,    -1,
     875,    -1,   876,    -1,   198,    -1,   195,    -1,   196,   877,
     197,    -1,     5,    -1,   879,   880,   886,    -1,   123,    -1,
     881,    -1,    -1,   881,   882,    -1,   883,    -1,   884,    -1,
     885,    -1,    21,     3,     8,    -1,    22,     3,     8,    -1,
      23,     3,     8,    -1,    10,   124,    -1,    11,    -1,   888,
      -1,   889,    -1,   890,    -1,    49,    -1,    24,     3,   983,
      -1,   892,    -1,   893,    -1,   894,    -1,    50,    -1,    46,
       3,   983,    -1,   896,    -1,    26,     8,   982,     8,    -1,
     898,    -1,   899,    -1,    42,   983,     6,   983,    -1,   901,
      -1,   902,    -1,   903,    -1,    53,    -1,    55,     3,   983,
      -1,   905,    -1,   906,    -1,   907,    -1,    57,    -1,    59,
     983,   982,   983,    -1,   909,    -1,   910,    -1,   911,    -1,
      48,    -1,    41,     3,   983,    -1,   913,    -1,   914,    -1,
     915,    -1,    62,    -1,    61,     3,   983,    -1,   917,    -1,
     918,    -1,    43,   983,     6,   983,    -1,   920,    -1,   921,
      -1,   922,    -1,    47,    -1,    25,     3,     8,    -1,   924,
      -1,   925,    -1,   926,    -1,    54,    -1,    56,     3,   983,
      -1,   928,    -1,   929,    -1,   930,    -1,    58,    -1,    60,
     983,   982,   983,    -1,   932,    -1,   933,    -1,   934,    -1,
      51,    -1,    45,     3,     8,    -1,   936,    -1,   937,    -1,
     938,    -1,    52,    -1,    44,     3,     8,    -1,    39,   983,
       6,   983,    -1,    32,   983,     6,   983,    -1,    40,   983,
       6,   983,    -1,    17,   983,     6,   983,    -1,    36,   983,
       6,   983,    -1,    18,     8,     6,     8,    -1,    38,   983,
       6,   983,    -1,    31,   983,     6,   983,    -1,    35,   983,
       6,   983,    -1,    34,   983,     6,   983,    -1,    16,   983,
       6,   983,    -1,    33,   983,     6,   983,    -1,    20,     8,
       6,     8,    -1,    19,     8,     6,     8,    -1,    27,     8,
       6,     8,    -1,    28,   983,     6,   983,    -1,    37,   983,
       6,   983,    -1,    30,   983,     6,   983,    -1,   958,    -1,
     957,   958,    -1,   959,   960,   963,    -1,   193,    -1,   961,
      -1,    -1,   961,   962,    -1,   941,    -1,   935,    -1,   891,
      -1,   964,    -1,   965,    -1,    11,    -1,    10,   966,   194,
      -1,   967,    -1,   968,    -1,   975,    -1,    -1,   968,   969,
      -1,   970,   971,   974,    -1,   204,    -1,   972,    -1,    -1,
     972,   973,    -1,   981,    -1,   980,    -1,    10,     6,   205,
      -1,   199,   976,   977,    -1,   203,   983,     6,   983,    -1,
     978,    -1,   979,    -1,    10,   200,    -1,    11,    -1,    10,
       4,   200,    -1,   201,   983,     6,   983,    -1,   202,   983,
       6,   983,    -1,     6,    -1,     7,    -1,   984,     8,    -1,
      -1,   984,   985,    -1,   207,    -1,   208,    -1,   209,    -1,
     210,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   154,   154,   155,   157,   164,   171,   171,   173,   173,
     175,   177,   180,   188,   188,   190,   192,   192,   194,   194,
     196,   198,   200,   200,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   217,   219,   227,   227,   229,
     229,   231,   233,   243,   245,   251,   251,   253,   253,   255,
     257,   266,   268,   274,   274,   276,   276,   278,   280,   290,
     297,   305,   306,   313,   319,   319,   321,   321,   323,   325,
     333,   335,   341,   341,   343,   343,   345,   347,   356,   358,
     365,   365,   367,   367,   369,   371,   381,   383,   390,   390,
     392,   392,   394,   396,   406,   408,   414,   414,   416,   416,
     418,   420,   430,   432,   438,   438,   440,   440,   442,   444,
     454,   461,   470,   471,   477,   484,   484,   486,   486,   488,
     490,   497,   499,   505,   513,   517,   522,   522,   524,   526,
     530,   530,   532,   539,   550,   556,   556,   559,   563,   564,
     567,   567,   576,   576,   578,   580,   580,   582,   582,   584,
     586,   588,   588,   591,   592,   593,   594,   595,   599,   601,
     611,   613,   613,   616,   617,   620,   622,   630,   632,   642,
     644,   644,   647,   648,   651,   653,   662,   664,   674,   676,
     676,   679,   680,   683,   685,   694,   696,   704,   705,   707,
     709,   720,   722,   728,   736,   740,   745,   745,   747,   749,
     753,   753,   755,   762,   773,   778,   778,   781,   786,   787,
     790,   790,   799,   799,   801,   803,   803,   805,   805,   807,
     809,   811,   811,   814,   815,   819,   821,   827,   827,   829,
     829,   831,   833,   844,   846,   852,   860,   864,   869,   869,
     871,   873,   877,   877,   879,   886,   897,   902,   902,   905,
     910,   911,   914,   914,   922,   922,   924,   926,   926,   928,
     928,   930,   932,   934,   934,   937,   938,   939,   940,   941,
     942,   943,   944,   945,   946,   947,   948,   949,   950,   951,
     956,   962,   972,   974,   974,   976,   976,   978,   980,   982,
     989,   991,   997,   997,   999,   999,  1001,  1003,  1013,  1015,
    1022,  1024,  1024,  1026,  1026,  1028,  1038,  1038,  1040,  1051,
    1053,  1059,  1061,  1061,  1063,  1063,  1065,  1075,  1075,  1077,
    1088,  1090,  1096,  1098,  1098,  1100,  1100,  1102,  1112,  1112,
    1114,  1124,  1126,  1132,  1134,  1134,  1136,  1136,  1138,  1148,
    1148,  1150,  1160,  1162,  1168,  1170,  1170,  1172,  1172,  1174,
    1184,  1184,  1186,  1197,  1199,  1205,  1207,  1207,  1209,  1209,
    1211,  1226,  1226,  1228,  1232,  1234,  1240,  1242,  1242,  1244,
    1244,  1246,  1261,  1261,  1263,  1267,  1269,  1275,  1277,  1277,
    1279,  1279,  1281,  1296,  1296,  1298,  1302,  1304,  1310,  1312,
    1312,  1314,  1314,  1316,  1331,  1331,  1333,  1337,  1339,  1345,
    1347,  1347,  1349,  1349,  1351,  1361,  1361,  1363,  1374,  1376,
    1382,  1384,  1384,  1386,  1386,  1388,  1398,  1398,  1400,  1411,
    1413,  1420,  1422,  1422,  1424,  1424,  1426,  1436,  1436,  1438,
    1450,  1452,  1458,  1466,  1470,  1475,  1475,  1477,  1479,  1483,
    1483,  1485,  1492,  1503,  1508,  1508,  1511,  1516,  1517,  1520,
    1520,  1528,  1528,  1530,  1541,  1543,  1543,  1546,  1552,  1558,
    1566,  1566,  1568,  1570,  1572,  1579,  1579,  1581,  1586,  1593,
    1593,  1598,  1598,  1600,  1602,  1604,  1609,  1609,  1611,  1616,
    1624,  1629,  1641,  1641,  1643,  1645,  1647,  1647,  1650,  1655,
    1663,  1663,  1666,  1677,  1684,  1684,  1688,  1688,  1690,  1695,
    1703,  1708,  1720,  1720,  1722,  1724,  1726,  1726,  1729,  1734,
    1743,  1749,  1749,  1752,  1762,  1765,  1765,  1769,  1769,  1771,
    1773,  1773,  1775,  1777,  1779,  1782,  1782,  1790,  1796,  1803,
    1803,  1805,  1807,  1809,  1813,  1813,  1822,  1828,  1835,  1835,
    1837,  1839,  1841,  1845,  1845,  1853,  1859,  1866,  1866,  1868,
    1870,  1872,  1876,  1876,  1884,  1890,  1897,  1897,  1899,  1901,
    1903,  1907,  1907,  1915,  1921,  1928,  1928,  1930,  1932,  1934,
    1938,  1938,  1946,  1952,  1959,  1959,  1961,  1963,  1965,  1969,
    1969,  1972,  1977,  1985,  1990,  2002,  2002,  2004,  2006,  2010,
    2010,  2012,  2017,  2026,  2032,  2032,  2035,  2045,  2051,  2051,
    2055,  2055,  2057,  2063,  2071,  2075,  2080,  2080,  2082,  2084,
    2084,  2086,  2096,  2106,  2114,  2114,  2117,  2118,  2125,  2128,
    2128,  2130,  2130,  2132,  2137,  2137,  2139,  2144,  2166,  2183,
    2183,  2186,  2190,  2194,  2195,  2196,  2197,  2198,  2199,  2202,
    2202,  2204,  2204,  2206,  2208,  2208,  2210,  2210,  2213,  2226,
    2239,  2241,  2241,  2244,  2254,  2255,  2256,  2259,  2261,  2261,
    2323,  2323,  2325,  2328,  2335,  2335,  2340,  2340,  2342,  2344,
    2346,  2350,  2350,  2352,  2358,  2366,  2371,  2383,  2383,  2385,
    2387,  2389,  2389,  2392,  2397,  2406,  2412,  2412,  2415,  2425,
    2432,  2432,  2435,  2435,  2437,  2442,  2451,  2456,  2470,  2470,
    2472,  2474,  2476,  2476,  2479,  2484,  2496,  2503,  2503,  2506,
    2516,  2521,  2527,  2527,  2531,  2531,  2533,  2535,  2535,  2537,
    2539,  2541,  2544,  2544,  2552,  2558,  2565,  2565,  2567,  2569,
    2571,  2574,  2574,  2582,  2588,  2595,  2595,  2597,  2599,  2601,
    2604,  2604,  2612,  2618,  2625,  2625,  2627,  2629,  2631,  2634,
    2634,  2642,  2648,  2655,  2655,  2657,  2659,  2661,  2664,  2664,
    2672,  2679,  2686,  2686,  2688,  2690,  2692,  2696,  2696,  2704,
    2710,  2717,  2717,  2719,  2721,  2723,  2727,  2727,  2729,  2735,
    2757,  2774,  2774,  2777,  2781,  2785,  2786,  2787,  2788,  2789,
    2790,  2793,  2793,  2795,  2795,  2797,  2799,  2799,  2801,  2801,
    2804,  2817,  2831,  2839,  2839,  2842,  2852,  2853,  2854,  2857,
    2859,  2859,  2919,  2919,  2921,  2926,  2933,  2933,  2938,  2938,
    2940,  2942,  2944,  2948,  2948,  2950,  2955,  2963,  2968,  2980,
    2980,  2982,  2984,  2986,  2986,  2989,  2994,  3002,  3002,  3005,
    3016,  3023,  3023,  3027,  3027,  3029,  3034,  3043,  3048,  3062,
    3062,  3064,  3066,  3068,  3068,  3071,  3076,  3087,  3093,  3093,
    3096,  3107,  3108,  3111,  3111,  3115,  3115,  3117,  3119,  3119,
    3121,  3123,  3125,  3128,  3128,  3136,  3142,  3149,  3149,  3151,
    3153,  3155,  3158,  3158,  3166,  3172,  3179,  3179,  3181,  3183,
    3185,  3189,  3189,  3197,  3203,  3210,  3210,  3212,  3214,  3216,
    3220,  3220,  3228,  3234,  3241,  3241,  3243,  3245,  3247,  3251,
    3251,  3259,  3265,  3272,  3272,  3274,  3276,  3278,  3282,  3282,
    3290,  3296,  3303,  3303,  3305,  3307,  3309,  3313,  3313,  3315,
    3321,  3343,  3360,  3360,  3363,  3367,  3371,  3372,  3373,  3374,
    3375,  3376,  3379,  3379,  3381,  3381,  3383,  3385,  3385,  3387,
    3387,  3390,  3403,  3416,  3418,  3418,  3421,  3431,  3432,  3433,
    3436,  3438,  3438,  3502,  3502,  3504,  3512,  3520,  3525,  3531,
    3533,  3535,  3535,  3539,  3558,  3576,  3582,  3582,  3585,  3586,
    3587,  3588,  3589,  3590,  3591,  3598,  3602,  3607,  3607,  3609,
    3611,  3613,  3613,  3615,  3622,  3628,  3630,  3630,  3632,  3634,
    3645,  3654,  3664,  3669,  3669,  3672,  3673,  3674,  3676,  3684,
    3692,  3700,  3700,  3706,  3713,  3713,  3715,  3720,  3727,  3734,
    3734,  3736,  3739,  3746,  3753,  3760,  3767,  3769,  3775,  3782,
    3782,  3784,  3789,  3796,  3802,  3802,  3804,  3807,  3812,  3818,
    3818,  3820,  3823,  3830,  3836,  3836,  3838,  3841,  3848,  3854,
    3856,  3864,  3870,  3870,  3872,  3875,  3882,  3889,  3889,  3891,
    3896,  3903,  3909,  3909,  3911,  3914,  3921,  3927,  3927,  3929,
    3932,  3939,  3945,  3945,  3947,  3950,  3962,  3971,  3980,  3989,
    3998,  4007,  4016,  4025,  4033,  4039,  4045,  4051,  4057,  4068,
    4077,  4087,  4093,  4102,  4122,  4122,  4124,  4141,  4152,  4159,
    4159,  4162,  4169,  4170,  4174,  4174,  4176,  4178,  4180,  4197,
    4202,  4204,  4204,  4206,  4208,  4217,  4219,  4219,  4221,  4221,
    4223,  4231,  4233,  4238,  4238,  4240,  4240,  4242,  4264,  4272,
    4286,  4287,  4294,  4296,  4296,  4298,  4299,  4300,  4301
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
  "EMPTYWEIGHTATT", "TRANSPORTTYPEATT", "LOCATIONTYPEATT", "GENERALSTART",
  "GENERALEND", "SYSTEMSTART", "SYSTEMEND", "SERVICESTART", "SERVICEEND",
  "JOBSTART", "JOBEND", "OPTIMIZATIONSTART", "OPTIMIZATIONEND",
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
     455,   456,   457,   458,   459,   460,   461,    32,     9,    13,
      10
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   211,   212,   212,   213,   214,   215,   215,   216,   216,
     217,   218,   219,   220,   220,   221,   222,   222,   223,   223,
     224,   225,   226,   226,   227,   227,   227,   227,   227,   227,
     227,   227,   227,   227,   227,   228,   229,   230,   230,   231,
     231,   232,   233,   234,   235,   236,   236,   237,   237,   238,
     239,   240,   241,   242,   242,   243,   243,   244,   245,   246,
     247,   248,   248,   249,   250,   250,   251,   251,   252,   253,
     254,   255,   256,   256,   257,   257,   258,   259,   260,   261,
     262,   262,   263,   263,   264,   265,   266,   267,   268,   268,
     269,   269,   270,   271,   272,   273,   274,   274,   275,   275,
     276,   277,   278,   279,   280,   280,   281,   281,   282,   283,
     284,   285,   286,   286,   287,   288,   288,   289,   289,   290,
     291,   292,   293,   294,   295,   295,   296,   296,   297,   298,
     299,   299,   300,   301,   302,   303,   303,   304,   304,   304,
     305,   305,   306,   306,   307,   308,   308,   309,   309,   310,
     311,   312,   312,   313,   313,   313,   313,   313,   314,   315,
     316,   317,   317,   318,   318,   319,   320,   321,   322,   323,
     324,   324,   325,   325,   326,   327,   328,   329,   330,   331,
     331,   332,   332,   333,   334,   335,   336,   337,   337,   338,
     339,   340,   341,   342,   343,   343,   344,   344,   345,   346,
     347,   347,   348,   349,   350,   351,   351,   352,   352,   352,
     353,   353,   354,   354,   355,   356,   356,   357,   357,   358,
     359,   360,   360,   361,   361,   362,   363,   364,   364,   365,
     365,   366,   367,   368,   369,   370,   371,   371,   372,   372,
     373,   374,   375,   375,   376,   377,   378,   379,   379,   380,
     380,   380,   381,   381,   382,   382,   383,   384,   384,   385,
     385,   386,   387,   388,   388,   389,   389,   389,   389,   389,
     389,   389,   389,   389,   389,   389,   389,   389,   389,   389,
     390,   391,   392,   393,   393,   394,   394,   395,   396,   397,
     398,   399,   400,   400,   401,   401,   402,   403,   404,   405,
     406,   407,   407,   408,   408,   409,   410,   410,   411,   412,
     413,   414,   415,   415,   416,   416,   417,   418,   418,   419,
     420,   421,   422,   423,   423,   424,   424,   425,   426,   426,
     427,   428,   429,   430,   431,   431,   432,   432,   433,   434,
     434,   435,   436,   437,   438,   439,   439,   440,   440,   441,
     442,   442,   443,   444,   445,   446,   447,   447,   448,   448,
     449,   450,   450,   451,   452,   453,   454,   455,   455,   456,
     456,   457,   458,   458,   459,   460,   461,   462,   463,   463,
     464,   464,   465,   466,   466,   467,   468,   469,   470,   471,
     471,   472,   472,   473,   474,   474,   475,   476,   477,   478,
     479,   479,   480,   480,   481,   482,   482,   483,   484,   485,
     486,   487,   487,   488,   488,   489,   490,   490,   491,   492,
     493,   494,   495,   495,   496,   496,   497,   498,   498,   499,
     500,   501,   502,   503,   503,   504,   504,   505,   506,   507,
     507,   508,   509,   510,   511,   511,   512,   512,   512,   513,
     513,   514,   514,   515,   516,   517,   517,   518,   518,   518,
     519,   519,   520,   521,   522,   523,   523,   524,   525,   526,
     526,   527,   527,   528,   529,   530,   531,   531,   532,   533,
     534,   534,   535,   535,   536,   537,   538,   538,   539,   540,
     541,   541,   542,   542,   543,   543,   544,   544,   545,   546,
     547,   547,   548,   548,   549,   550,   551,   551,   552,   553,
     554,   555,   555,   556,   556,   557,   557,   558,   558,   559,
     560,   560,   561,   562,   563,   564,   564,   565,   566,   567,
     567,   568,   569,   570,   571,   571,   572,   573,   574,   574,
     575,   576,   577,   578,   578,   579,   580,   581,   581,   582,
     583,   584,   585,   585,   586,   587,   588,   588,   589,   590,
     591,   592,   592,   593,   594,   595,   595,   596,   597,   598,
     599,   599,   600,   601,   602,   602,   603,   604,   605,   606,
     606,   607,   608,   609,   609,   610,   610,   611,   612,   613,
     613,   614,   615,   616,   617,   617,   618,   618,   619,   619,
     620,   620,   621,   622,   623,   623,   624,   624,   625,   626,
     626,   627,   628,   629,   630,   630,   631,   631,   631,   632,
     632,   633,   633,   634,   635,   635,   636,   637,   638,   639,
     639,   640,   640,   640,   640,   640,   640,   640,   640,   641,
     641,   642,   642,   643,   644,   644,   645,   645,   646,   647,
     648,   649,   649,   650,   650,   650,   650,   651,   652,   652,
     653,   653,   654,   655,   656,   656,   657,   657,   658,   659,
     660,   661,   661,   662,   663,   664,   664,   665,   665,   666,
     667,   668,   668,   669,   670,   671,   672,   672,   673,   673,
     674,   674,   675,   675,   676,   677,   678,   678,   679,   679,
     680,   681,   682,   682,   683,   684,   685,   686,   686,   687,
     687,   687,   688,   688,   689,   689,   690,   691,   691,   692,
     693,   694,   695,   695,   696,   697,   698,   698,   699,   700,
     701,   702,   702,   703,   704,   705,   705,   706,   707,   708,
     709,   709,   710,   711,   712,   712,   713,   714,   715,   716,
     716,   717,   718,   719,   719,   720,   721,   722,   723,   723,
     724,   725,   726,   726,   727,   728,   729,   730,   730,   731,
     732,   733,   733,   734,   735,   736,   737,   737,   738,   739,
     740,   741,   741,   742,   742,   742,   742,   742,   742,   742,
     742,   743,   743,   744,   744,   745,   746,   746,   747,   747,
     748,   749,   750,   751,   751,   752,   752,   752,   752,   753,
     754,   754,   755,   755,   756,   757,   758,   758,   759,   759,
     760,   761,   762,   763,   763,   764,   765,   766,   766,   767,
     767,   768,   769,   770,   770,   771,   772,   773,   773,   774,
     774,   775,   775,   776,   776,   777,   778,   779,   779,   780,
     780,   781,   782,   783,   783,   784,   785,   786,   787,   787,
     788,   788,   788,   789,   789,   790,   790,   791,   792,   792,
     793,   794,   795,   796,   796,   797,   798,   799,   799,   800,
     801,   802,   803,   803,   804,   805,   806,   806,   807,   808,
     809,   810,   810,   811,   812,   813,   813,   814,   815,   816,
     817,   817,   818,   819,   820,   820,   821,   822,   823,   824,
     824,   825,   826,   827,   827,   828,   829,   830,   831,   831,
     832,   833,   834,   834,   835,   836,   837,   838,   838,   839,
     840,   841,   842,   842,   843,   843,   843,   843,   843,   843,
     843,   843,   844,   844,   845,   845,   846,   847,   847,   848,
     848,   849,   850,   851,   852,   852,   853,   853,   853,   853,
     854,   855,   855,   856,   856,   857,   858,   859,   859,   860,
     861,   862,   862,   863,   864,   865,   866,   866,   867,   867,
     867,   867,   867,   867,   867,   868,   868,   869,   869,   870,
     871,   872,   872,   873,   874,   874,   875,   875,   876,   877,
     878,   879,   880,   881,   881,   882,   882,   882,   883,   884,
     885,   886,   886,   887,   888,   888,   889,   890,   891,   892,
     892,   893,   894,   895,   896,   897,   898,   899,   900,   901,
     901,   902,   903,   904,   905,   905,   906,   907,   908,   909,
     909,   910,   911,   912,   913,   913,   914,   915,   916,   917,
     918,   919,   920,   920,   921,   922,   923,   924,   924,   925,
     926,   927,   928,   928,   929,   930,   931,   932,   932,   933,
     934,   935,   936,   936,   937,   938,   939,   940,   941,   942,
     943,   944,   945,   946,   947,   948,   949,   950,   951,   952,
     953,   954,   955,   956,   957,   957,   958,   959,   960,   961,
     961,   962,   962,   962,   963,   963,   964,   965,   966,   967,
     967,   968,   968,   969,   970,   971,   972,   972,   973,   973,
     974,   975,   976,   977,   977,   978,   978,   979,   980,   981,
     982,   982,   983,   984,   984,   985,   985,   985,   985
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     3,     3,     1,     1,     0,     1,     1,     1,
       1,     3,     5,     0,     2,     1,     1,     1,     2,     1,
       3,     1,     1,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     2,     1,     1,     1,     2,
       1,     3,     1,     2,     1,     1,     1,     2,     1,     3,
       1,     2,     1,     1,     1,     2,     1,     3,     1,     3,
       1,     0,     1,     3,     1,     1,     2,     1,     3,     1,
       2,     1,     1,     1,     2,     1,     3,     1,     2,     1,
       1,     1,     2,     1,     3,     1,     2,     1,     1,     1,
       2,     1,     3,     1,     2,     1,     1,     1,     2,     1,
       3,     1,     2,     1,     1,     1,     2,     1,     3,     1,
       3,     1,     0,     1,     3,     1,     1,     2,     1,     3,
       1,     3,     1,     1,     1,     1,     2,     1,     3,     1,
       1,     2,     3,     1,     1,     0,     2,     1,     1,     1,
       2,     1,     0,     2,     1,     1,     1,     2,     1,     3,
       1,     1,     2,     1,     1,     1,     1,     1,     3,     1,
       1,     0,     2,     1,     1,     3,     1,     3,     1,     1,
       0,     2,     1,     1,     3,     1,     3,     1,     1,     0,
       2,     1,     1,     3,     1,     3,     1,     0,     1,     3,
       1,     3,     1,     1,     1,     1,     2,     1,     3,     1,
       1,     2,     3,     1,     1,     0,     2,     1,     1,     1,
       2,     1,     0,     2,     1,     1,     1,     2,     1,     3,
       1,     1,     2,     1,     1,     2,     1,     1,     1,     2,
       1,     3,     1,     3,     1,     1,     1,     1,     2,     1,
       3,     1,     1,     2,     3,     1,     1,     0,     2,     1,
       1,     1,     2,     1,     0,     2,     1,     1,     1,     2,
       1,     3,     1,     1,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       3,     1,     1,     1,     1,     2,     1,     3,     1,     1,
       2,     1,     1,     1,     2,     1,     3,     1,     3,     1,
       1,     1,     1,     2,     1,     3,     1,     2,     4,     3,
       1,     1,     1,     1,     2,     1,     3,     1,     2,     4,
       3,     1,     1,     1,     1,     2,     1,     3,     1,     2,
       4,     3,     1,     1,     1,     1,     2,     1,     3,     1,
       2,     4,     3,     1,     1,     1,     1,     2,     1,     3,
       1,     2,     4,     3,     1,     1,     1,     1,     2,     1,
       3,     1,     2,     1,     3,     1,     1,     1,     1,     2,
       1,     3,     1,     2,     1,     3,     1,     1,     1,     1,
       2,     1,     3,     1,     2,     1,     3,     1,     1,     1,
       1,     2,     1,     3,     1,     2,     1,     3,     1,     1,
       1,     1,     2,     1,     3,     1,     2,     4,     3,     1,
       1,     1,     1,     2,     1,     3,     1,     2,     4,     3,
       1,     1,     1,     1,     2,     1,     3,     1,     2,     4,
       3,     1,     1,     1,     1,     2,     1,     3,     1,     1,
       2,     3,     1,     1,     0,     2,     1,     1,     1,     2,
       1,     0,     3,     1,     1,     0,     2,     1,     1,     1,
       1,     1,     1,     3,     4,     0,     3,     1,     1,     0,
       1,     1,     1,     1,     3,     6,     0,     3,     1,     1,
       1,     1,     2,     1,     3,     1,     1,     2,     3,     1,
       0,     2,     1,     1,     2,     1,     0,     3,     1,     1,
       1,     1,     2,     1,     3,     1,     1,     2,     3,     1,
       1,     0,     2,     1,     1,     2,     1,     0,     2,     1,
       1,     1,     1,     3,     6,     0,     3,     1,     1,     1,
       1,     1,     3,     1,     0,     3,     1,     1,     1,     1,
       1,     3,     1,     0,     3,     1,     1,     1,     1,     1,
       3,     1,     0,     3,     1,     1,     1,     1,     1,     3,
       1,     0,     3,     1,     1,     1,     1,     1,     3,     1,
       0,     3,     1,     1,     1,     1,     1,     3,     1,     0,
       3,     1,     1,     1,     1,     2,     1,     3,     1,     1,
       2,     3,     1,     1,     0,     2,     1,     1,     2,     1,
       0,     3,     1,     4,     1,     1,     2,     1,     3,     1,
       2,     3,     1,     1,     0,     2,     1,     1,     1,     1,
       1,     2,     1,     3,     0,     2,     3,     1,     1,     0,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     2,     1,     3,     1,     1,     1,     2,     3,     1,
       1,     0,     2,     1,     1,     1,     1,     1,     2,     1,
       0,     3,     1,     1,     0,     1,     1,     1,     1,     3,
       4,     0,     3,     1,     1,     1,     1,     2,     1,     3,
       1,     1,     2,     3,     1,     1,     0,     2,     1,     1,
       2,     1,     0,     3,     1,     1,     1,     1,     2,     1,
       3,     1,     1,     2,     3,     1,     1,     0,     2,     1,
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
       2,     1,     0,     3,     1,     1,     0,     1,     1,     1,
       1,     3,     4,     0,     3,     1,     1,     1,     1,     2,
       1,     3,     1,     1,     2,     3,     1,     0,     2,     1,
       1,     2,     1,     0,     3,     1,     1,     1,     1,     2,
       1,     3,     1,     1,     2,     3,     1,     1,     0,     2,
       1,     1,     1,     2,     1,     0,     2,     1,     1,     1,
       1,     3,     6,     0,     3,     1,     1,     1,     1,     1,
       3,     1,     0,     3,     1,     1,     1,     1,     1,     3,
       1,     0,     3,     1,     1,     1,     1,     1,     3,     1,
       0,     3,     1,     1,     1,     1,     1,     3,     1,     0,
       3,     1,     1,     1,     1,     1,     3,     1,     0,     3,
       1,     1,     1,     1,     1,     3,     1,     0,     2,     3,
       1,     1,     0,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     2,     1,     3,     1,     1,     1,
       2,     3,     1,     1,     0,     2,     1,     1,     1,     1,
       1,     2,     1,     0,     3,     1,     1,     1,     1,     1,
       3,     0,     2,     3,     1,     1,     1,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     2,     1,     3,
       1,     1,     2,     1,     1,     1,     1,     1,     3,     1,
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
       0,     5,     4,     0,    13,     6,     1,    15,     0,   142,
       0,     7,     0,     2,   144,   212,     0,     0,    19,    14,
      16,    17,    13,    10,     3,     8,     9,   214,   254,     0,
       0,   148,   143,   145,   146,    18,    36,    44,    52,    60,
      71,    79,    87,    95,   103,   111,   122,     0,    21,    22,
      24,     0,    25,     0,    26,     0,    27,    61,    28,     0,
      29,     0,    30,     0,    31,     0,    32,     0,    33,   112,
      34,     0,     0,   256,   451,     0,     0,   218,   213,   215,
     216,   147,   192,   159,   168,   177,   186,     0,   150,   151,
     153,   161,   154,   170,   155,   179,   156,   187,   157,     0,
      20,    23,     0,    40,    35,    37,    38,     0,    48,    43,
      45,    46,     0,    56,    51,    53,    54,     0,     0,    62,
       0,    75,    70,    72,    73,     0,    83,    78,    80,    81,
       0,    91,    86,    88,    89,     0,    99,    94,    96,    97,
       0,   107,   102,   104,   105,     0,     0,   113,  1133,     0,
     123,    11,   453,    12,   455,     0,   260,   255,   257,   258,
     217,   234,   226,     0,   220,   221,   223,     0,   224,     0,
     149,   152,     0,   160,     0,   169,     0,   178,     0,  1021,
       0,   188,  1018,  1019,  1020,     0,   193,    42,    39,     0,
      50,    47,     0,    58,    55,     0,     0,     0,    67,    59,
      64,    65,    77,    74,     0,    85,    82,     0,    93,    90,
       0,   101,    98,     0,   109,   106,     0,     0,     0,   118,
     110,   115,   116,     0,     0,     0,   127,   121,   124,   125,
       0,   454,   259,   431,   281,   291,   299,   310,   321,   332,
     343,   409,   398,   354,   365,   387,   376,   420,     0,   262,
     263,   265,     0,   266,     0,   267,     0,   268,     0,   269,
       0,   270,     0,   271,     0,   272,     0,   273,     0,   275,
       0,   274,     0,   276,     0,   277,     0,   278,     0,   279,
       0,   219,   222,     0,   230,   225,   227,   228,     0,   235,
       0,   158,     0,  1069,   162,   164,   163,  1066,  1067,  1068,
       0,   167,   171,   173,   172,     0,   176,   180,   182,   181,
    1133,     0,   185,     0,   197,   191,   194,   195,    41,    49,
      57,    63,    69,    66,     0,    76,    84,    92,   100,   108,
     114,   120,   117,     0,  1133,  1132,  1135,  1136,  1137,  1138,
    1134,   126,   133,     0,   129,   130,   135,   465,   462,   452,
     460,   461,  1133,  1133,  1133,   456,   458,   459,   457,   261,
     264,     0,   282,     0,   295,   290,   292,   293,     0,     0,
     300,     0,     0,   311,     0,   322,     0,   333,     0,   344,
       0,     0,   355,     0,   366,     0,   377,     0,   388,     0,
     399,     0,   410,     0,     0,   421,     0,   432,   232,   229,
       0,     0,   239,   233,   236,   237,  1130,  1131,     0,   166,
       0,     0,   175,     0,   184,  1022,   190,     0,   196,   203,
       0,   199,   200,   205,    68,   119,  1086,   128,   131,     0,
     134,   467,     0,   660,   469,     0,     0,     0,     0,   286,
     280,   283,   284,   297,   294,     0,     0,     0,   304,   298,
     301,   302,     0,     0,   315,   309,   312,   313,     0,   326,
     320,   323,   324,     0,   337,   331,   334,   335,     0,   348,
     342,   345,   346,     0,     0,   359,   353,   356,   357,     0,
     370,   364,   367,   368,     0,   381,   375,   378,   379,     0,
     392,   386,   389,   390,     0,   403,   397,   400,   401,     0,
     414,   408,   411,   412,     0,     0,   425,   419,   422,   423,
       0,   436,   430,   433,   434,   231,   238,   245,     0,   241,
     242,   247,   165,  1070,   174,   183,   189,   198,   201,     0,
     204,     0,   141,   132,     0,     0,  1041,  1074,   136,   139,
     137,  1038,  1039,  1040,   138,  1071,  1072,  1073,   463,   662,
     812,   664,  1133,     0,   468,   470,  1133,  1133,  1133,   285,
       0,   288,   289,   296,     0,     0,   303,     0,   306,     0,
     314,     0,     0,   317,   325,     0,     0,   328,     0,   336,
       0,   339,     0,   347,     0,   350,     0,  1001,   358,     0,
     361,   363,  1003,   369,     0,   372,   374,   380,     0,   383,
     385,   391,     0,   394,   396,     0,   402,     0,   405,     0,
     413,     0,   416,     0,   424,     0,     0,   427,   435,   442,
       0,   438,   439,   444,   240,   243,     0,   246,     0,   211,
     202,   206,   209,   207,   208,   140,  1133,     0,   814,   963,
     816,  1133,     0,   663,   665,     0,   476,   473,   466,   471,
     472,  1093,  1083,  1077,   287,  1081,     0,   305,   307,  1089,
       0,   316,   318,     0,   327,   329,     0,   338,   340,     0,
     349,   351,  1088,   360,   362,     0,  1002,   371,   373,   382,
     384,   393,   395,     0,   404,   406,     0,   415,   417,  1090,
       0,   426,   428,   437,   440,     0,   443,     0,   253,   244,
     248,   251,   249,   250,   210,  1042,  1075,   965,   464,     0,
    1133,     0,   815,   817,     0,   671,   668,   661,   666,   667,
    1133,   478,     0,   496,     0,     0,     0,     0,     0,     0,
       0,  1012,  1000,     0,     0,     0,  1004,  1005,  1006,  1007,
       0,     0,     0,     0,   450,   441,   445,   448,   446,   447,
     252,  1133,     0,   966,     0,   823,   820,   813,   818,   819,
    1133,   673,     0,   692,     0,  1087,   474,   498,   517,     0,
    1133,     0,   479,   308,   319,   330,   341,   352,  1011,     0,
       0,     0,   407,   418,   429,   449,     0,   971,   969,   964,
     967,   968,  1133,   825,     0,   843,     0,  1085,   669,   694,
     714,     0,  1133,     0,   674,   519,   579,     0,     0,   499,
       0,     0,   483,   477,   480,   481,  1008,  1009,  1010,  1133,
       0,  1084,   821,   845,   865,     0,  1133,     0,   826,   716,
     776,     0,     0,   695,     0,     0,   678,   672,   675,   676,
     581,   600,     0,   525,   522,   518,   520,   521,     0,   503,
     497,   500,   501,  1133,   482,   489,     0,   485,   486,   490,
    1091,   970,   974,   972,     0,   867,   927,     0,     0,   846,
       0,     0,   830,   824,   827,   828,   670,   722,   719,   715,
     717,   718,     0,   699,   693,   696,   697,  1133,   677,   684,
       0,   680,   681,   686,   602,   624,     0,     0,   582,   527,
       0,   534,     0,   509,   502,     0,   505,   506,   511,  1092,
     484,   487,     0,     0,     0,  1133,  1054,  1016,     0,  1046,
       0,   975,   976,   981,  1013,  1014,  1015,   983,   978,   980,
    1043,  1044,  1045,   982,  1051,  1052,  1053,   979,   984,   822,
     873,   870,   866,   868,   869,     0,   850,   844,   847,   848,
    1133,   829,   836,     0,   832,   833,   837,   779,   777,   781,
     724,     0,   731,     0,   705,   698,     0,   701,   702,   707,
    1082,   679,   682,     0,   685,   475,     0,     0,     0,   586,
     580,   583,   584,   523,   536,   543,     0,  1133,     0,   528,
     504,   507,     0,   510,     0,   495,  1133,   491,   488,   492,
    1025,  1026,   493,  1133,     0,     0,  1133,     0,   988,   973,
     985,   986,   977,   930,   928,   932,   875,     0,   882,     0,
     856,   849,     0,   852,   853,   858,  1076,   831,   834,     0,
       0,   780,   720,   733,   740,     0,     0,   725,   700,   703,
       0,   706,     0,   691,   683,   687,   688,   689,   627,   625,
     629,     0,     0,   607,   601,   604,   605,   592,   585,     0,
     588,   589,   594,   545,   552,     0,     0,   537,     0,  1111,
     531,   526,   529,   530,     0,   516,   508,   512,   513,   514,
     494,     0,  1017,  1055,  1133,  1047,   987,   997,     0,   996,
       0,   990,   991,   993,   994,   995,     0,   931,   871,   884,
     891,     0,     0,   876,   851,   854,     0,   857,     0,   842,
     838,   835,   839,   840,     0,   794,   778,   791,   792,  1133,
     782,   788,   790,   785,   787,   789,   786,   784,   783,   742,
     749,     0,     0,   734,  1111,   728,   723,   726,   727,     0,
     713,   704,  1031,  1059,     0,     0,   708,   709,   710,  1028,
    1029,  1030,   711,  1056,  1057,  1058,   690,     0,   628,     0,
     606,   612,     0,   609,   614,   587,   590,     0,   593,   554,
     561,     0,     0,   546,  1111,   540,   535,   538,   539,  1133,
       0,     0,   533,  1109,  1110,   515,  1133,  1080,   999,     0,
     989,   992,     0,   945,   929,   942,   943,   933,   939,   941,
     936,   938,   940,   937,   934,   935,   893,   900,     0,     0,
     885,  1111,   879,   874,   877,   878,     0,   864,   855,  1036,
    1064,  1133,  1133,   859,   860,   861,  1033,  1034,  1035,   862,
    1061,  1062,  1063,   841,   793,   801,  1097,     0,   796,   798,
     803,   797,  1094,  1099,     0,   751,   758,     0,     0,   743,
    1111,   737,   732,   735,   736,     0,   730,   712,  1133,  1133,
       0,   642,   626,   639,   640,   630,   636,   638,   633,   635,
     637,   634,   632,   631,   603,   608,   610,     0,   613,     0,
     599,   591,   595,   596,   597,   563,   570,     0,     0,   555,
    1111,   549,   544,   547,   548,     0,   542,  1078,  1133,     0,
     532,  1114,  1112,  1116,  1027,   998,   944,   952,     0,   947,
     949,   954,   948,   902,   909,     0,     0,   894,  1111,   888,
     883,   886,   887,     0,   881,   863,     0,     0,   795,   799,
       0,   802,  1095,     0,  1098,  1133,   760,   767,     0,     0,
     752,  1111,   746,   741,   744,   745,     0,   739,   729,  1032,
    1060,   641,   649,     0,   644,   646,   651,   645,     0,   622,
     611,   619,   620,     0,  1133,   615,   618,  1023,   616,  1048,
    1049,   617,   598,   572,   524,     0,     0,   564,  1111,   558,
     553,   556,   557,     0,   551,   541,     0,     0,  1126,  1121,
    1123,  1124,     0,  1115,   946,   950,     0,   953,   911,   918,
       0,     0,   903,  1111,   897,   892,   895,   896,     0,   890,
     880,  1133,  1133,     0,   811,   800,   809,   804,   805,   807,
     808,   806,  1111,  1106,  1096,  1104,  1105,  1103,  1102,  1101,
    1100,  1079,   769,   721,     0,     0,   761,  1111,   755,   750,
     753,   754,     0,   748,   738,   643,   647,     0,   650,   621,
       0,     0,     0,     0,   573,  1111,   567,   562,   565,   566,
       0,   560,   550,  1133,     0,  1125,     0,  1113,  1133,  1133,
    1117,  1119,  1118,     0,   962,   951,   960,   955,   956,   958,
     959,   957,   920,   872,     0,     0,   912,  1111,   906,   901,
     904,   905,     0,   899,   889,  1037,  1065,   810,     0,  1108,
       0,   770,  1111,   764,   759,   762,   763,     0,   757,   747,
       0,   659,   648,   657,   652,   653,   655,   656,   654,   623,
       0,  1133,  1111,   576,   571,   574,   575,     0,   569,   559,
    1122,  1127,     0,     0,     0,   961,     0,   921,  1111,   915,
     910,   913,   914,     0,   908,   898,  1107,  1111,   773,   768,
     771,   772,     0,   766,   756,   658,  1024,  1050,     0,   578,
     568,  1120,  1133,  1133,  1111,   924,   919,   922,   923,     0,
     917,   907,     0,   775,   765,   577,  1128,  1129,     0,   926,
     916,   774,   925
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     3,     4,     5,    12,    24,    25,    26,     8,     9,
      10,    19,    20,    21,    47,    48,    49,    50,    51,   104,
     105,   106,   189,    52,    53,   109,   110,   111,   192,    54,
      55,   114,   115,   116,   195,    56,    57,   118,   119,   199,
     200,   201,   324,    58,    59,   122,   123,   124,   204,    60,
      61,   127,   128,   129,   207,    62,    63,   132,   133,   134,
     210,    64,    65,   137,   138,   139,   213,    66,    67,   142,
     143,   144,   216,    68,    69,   146,   147,   220,   221,   222,
     333,    70,    71,   149,   227,   228,   229,   343,   344,   345,
     346,   429,   430,   538,   533,    15,    16,    32,    33,    34,
      87,    88,    89,    90,    91,   172,   173,   294,   291,   408,
      92,    93,   174,   175,   302,   301,   411,    94,    95,   176,
     177,   307,   306,   413,    96,    97,   180,   312,   417,    98,
      99,   185,   315,   316,   317,   420,   421,   422,   423,   529,
     530,   631,   630,    28,    29,    78,    79,    80,   163,   164,
     165,   166,   167,   285,   286,   287,   400,   168,   169,   288,
     403,   404,   405,   518,   519,   520,   521,   626,   627,   700,
     699,    74,    75,   157,   158,   159,   248,   249,   250,   251,
     252,   361,   440,   441,   442,   560,   561,   253,   254,   365,
     366,   367,   445,   255,   256,   369,   449,   450,   451,   567,
     568,   257,   258,   372,   455,   456,   457,   572,   573,   259,
     260,   374,   460,   461,   462,   576,   577,   261,   262,   376,
     465,   466,   467,   580,   581,   263,   264,   378,   470,   471,
     472,   584,   585,   265,   266,   381,   476,   477,   478,   589,
     590,   267,   268,   383,   481,   482,   483,   594,   595,   269,
     270,   385,   486,   487,   488,   598,   599,   271,   272,   387,
     491,   492,   493,   602,   603,   273,   274,   389,   496,   497,
     498,   607,   608,   275,   276,   391,   501,   502,   503,   611,
     612,   277,   278,   394,   507,   508,   509,   616,   617,   279,
     280,   396,   512,   513,   514,   620,   621,   622,   623,   695,
     696,   746,   745,   153,   154,   230,   231,   355,   349,   350,
     351,   432,   433,   434,   553,   554,   648,   649,   650,   722,
     723,   724,   771,   813,   814,   815,   856,   857,   858,   859,
     912,   997,   998,   768,   769,   808,   850,   851,   852,   905,
     906,   907,   908,   992,   993,  1077,  1076,   806,   807,   845,
     846,   847,   900,   901,   902,   988,  1071,  1072,  1073,  1181,
     985,   986,  1066,  1176,  1177,  1178,  1295,  1064,  1065,  1172,
    1292,  1293,  1294,  1383,  1170,  1171,  1288,  1380,  1381,  1382,
    1460,  1286,  1287,  1376,  1457,  1458,  1459,  1527,  1374,  1375,
    1453,  1524,  1525,  1526,  1558,   841,   842,   897,   980,   981,
     982,  1059,  1060,  1061,  1062,  1167,  1168,  1282,  1281,   895,
     896,   977,  1054,  1055,  1056,  1162,  1163,  1164,  1277,  1278,
    1365,  1360,  1361,  1362,   975,  1049,  1050,  1157,  1158,  1265,
    1262,  1263,  1264,  1353,  1354,  1355,  1356,  1447,  1448,  1514,
    1512,  1513,   550,   551,   642,   643,   717,   718,   719,   762,
     763,   764,   803,   837,   838,   839,   890,   891,   892,   893,
     973,   974,  1045,  1044,   800,   801,   832,   884,   885,   886,
     966,   967,   968,   969,  1040,  1041,  1146,  1141,   830,   831,
     879,   880,   881,   961,   962,   963,  1036,  1136,  1137,  1138,
    1255,  1034,  1035,  1132,  1252,  1253,  1254,  1346,  1130,  1131,
    1248,  1343,  1344,  1345,  1442,  1246,  1247,  1339,  1439,  1440,
    1441,  1507,  1337,  1338,  1435,  1504,  1505,  1506,  1552,  1433,
    1434,  1500,  1549,  1550,  1551,  1572,   876,   958,   959,  1030,
    1031,  1120,  1116,  1117,  1118,  1237,  1238,  1239,  1240,  1330,
    1331,  1417,  1415,  1416,   639,   640,   711,   712,   757,   758,
     759,   794,   795,   796,   827,   873,   874,   875,   953,   954,
     955,   956,  1029,  1110,  1111,   824,   825,   868,   947,   948,
     949,  1022,  1023,  1024,  1025,  1106,  1107,  1223,  1218,   866,
     867,   942,   943,   944,  1017,  1018,  1019,  1102,  1213,  1214,
    1215,  1323,  1100,  1101,  1209,  1320,  1321,  1322,  1408,  1207,
    1208,  1316,  1405,  1406,  1407,  1492,  1314,  1315,  1401,  1489,
    1490,  1491,  1543,  1399,  1400,  1485,  1540,  1541,  1542,  1569,
    1483,  1484,  1536,  1566,  1567,  1568,  1578,   939,  1014,  1015,
    1096,  1097,  1197,  1194,  1195,  1196,  1308,  1309,  1310,  1311,
    1396,  1397,  1477,  1475,  1476,   708,   709,   752,   789,   790,
     791,   820,   863,   864,   920,   921,   922,  1009,  1010,  1011,
    1090,  1091,  1092,  1093,  1094,  1095,  1189,   591,   592,   675,
     676,   736,   737,   738,   739,   732,   923,   924,   925,   926,
     927,   182,   183,   184,  1366,  1367,   999,  1000,  1001,  1148,
    1149,  1150,  1151,  1225,  1226,  1227,  1228,   928,   541,   542,
     543,   929,   930,   931,   932,  1368,  1369,  1370,   933,   934,
     935,   936,  1152,  1153,  1154,  1155,  1229,  1230,  1231,  1232,
     296,   297,   298,   299,   937,   545,   546,   547,   828,   356,
     989,  1127,   938,   370,   804,   357,   713,   644,   150,   555,
     382,   373,   395,   753,   772,   358,  1241,  1242,  1243,  1333,
    1334,  1430,  1424,  1425,  1426,  1498,  1182,  1183,  1302,  1303,
    1392,  1393,  1470,  1467,  1184,  1299,  1389,  1390,  1391,  1471,
    1472,   409,   223,   224,   340
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -1318
static const yytype_int16 yypact[] =
{
     232, -1318, -1318,    67,    36,   134, -1318, -1318,   177,   159,
     264, -1318,   278, -1318, -1318,   107,   317,   322, -1318, -1318,
   -1318, -1318,    36, -1318, -1318, -1318, -1318, -1318,   211,   368,
     246, -1318, -1318, -1318, -1318, -1318, -1318, -1318, -1318, -1318,
   -1318, -1318, -1318, -1318, -1318, -1318, -1318,   212,   443, -1318,
   -1318,   385, -1318,   413, -1318,   425, -1318,   230, -1318,   427,
   -1318,   429, -1318,   434, -1318,   437, -1318,   441, -1318,   236,
   -1318,   291,   298, -1318,   261,   444,    -9, -1318, -1318, -1318,
   -1318, -1318, -1318, -1318, -1318, -1318, -1318,   251,   325, -1318,
   -1318, -1318, -1318, -1318, -1318, -1318, -1318,    90, -1318,   291,
   -1318, -1318,    49, -1318, -1318, -1318, -1318,    35, -1318, -1318,
   -1318, -1318,    34, -1318, -1318, -1318, -1318,   335,   446, -1318,
      43, -1318, -1318, -1318, -1318,    32, -1318, -1318, -1318, -1318,
      29, -1318, -1318, -1318, -1318,    30, -1318, -1318, -1318, -1318,
      27, -1318, -1318, -1318, -1318,   337,   448, -1318, -1318,   451,
   -1318, -1318, -1318, -1318, -1318,    38, -1318, -1318, -1318, -1318,
   -1318, -1318, -1318,   270,   -37, -1318, -1318,   455, -1318,   291,
   -1318, -1318,   349,   207,   353,   207,   355,   207,   364, -1318,
     361, -1318, -1318, -1318, -1318,   457, -1318, -1318, -1318,   295,
   -1318, -1318,   302, -1318, -1318,   293,   378,    33, -1318, -1318,
   -1318, -1318, -1318, -1318,   316, -1318, -1318,   300, -1318, -1318,
     318, -1318, -1318,   314, -1318, -1318,   320,   404,    28, -1318,
   -1318, -1318, -1318,   410,     9,   371, -1318, -1318, -1318, -1318,
     461,   362, -1318, -1318, -1318, -1318, -1318, -1318, -1318, -1318,
   -1318, -1318, -1318, -1318, -1318, -1318, -1318, -1318,   347,   235,
   -1318, -1318,   204, -1318,   463, -1318,   407, -1318,   412, -1318,
     412, -1318,   412, -1318,   412, -1318,   422, -1318,   422, -1318,
     422, -1318,   422, -1318,   412, -1318,   412, -1318,   406, -1318,
     291, -1318, -1318,    18, -1318, -1318, -1318, -1318,   483, -1318,
     338, -1318,   450, -1318, -1318, -1318, -1318, -1318, -1318, -1318,
     338, -1318, -1318, -1318, -1318,   338, -1318, -1318, -1318, -1318,
   -1318,   473, -1318,   397, -1318, -1318, -1318, -1318, -1318, -1318,
   -1318, -1318, -1318, -1318,   365, -1318, -1318, -1318, -1318, -1318,
   -1318, -1318, -1318,   380, -1318, -1318, -1318, -1318, -1318, -1318,
   -1318, -1318, -1318,   383,   391, -1318, -1318,   354, -1318, -1318,
   -1318, -1318, -1318, -1318, -1318, -1318, -1318, -1318, -1318, -1318,
   -1318,   487, -1318,    11, -1318, -1318, -1318, -1318,   509,   492,
   -1318,   511,   494, -1318,   496, -1318,   500, -1318,   502, -1318,
     513,   504, -1318,   531, -1318,   534, -1318,   537, -1318,   539,
   -1318,   541, -1318,   515,   543, -1318,   545, -1318, -1318, -1318,
     398,   459, -1318, -1318, -1318, -1318, -1318, -1318,   423, -1318,
     521,   431, -1318,   433, -1318, -1318, -1318,   453, -1318, -1318,
     435,   438, -1318, -1318, -1318, -1318, -1318, -1318, -1318,   549,
     339, -1318,   488,   403,   569,   598,   601,   614,    21, -1318,
   -1318, -1318, -1318, -1318, -1318,   525,   705,   -24, -1318, -1318,
   -1318, -1318,   706,   109, -1318, -1318, -1318, -1318,   442, -1318,
   -1318, -1318, -1318,    69, -1318, -1318, -1318, -1318,    40, -1318,
   -1318, -1318, -1318,   707,    62, -1318, -1318, -1318, -1318,    16,
   -1318, -1318, -1318, -1318,   -29, -1318, -1318, -1318, -1318,   -69,
   -1318, -1318, -1318, -1318,    65, -1318, -1318, -1318, -1318,   -26,
   -1318, -1318, -1318, -1318,   708,   424, -1318, -1318, -1318, -1318,
     470, -1318, -1318, -1318, -1318, -1318, -1318, -1318,   618,   616,
   -1318, -1318, -1318, -1318, -1318, -1318, -1318, -1318, -1318,   560,
     339,   620, -1318, -1318,   714,   715, -1318, -1318, -1318, -1318,
   -1318, -1318, -1318, -1318, -1318, -1318, -1318, -1318, -1318, -1318,
     538,   688, -1318,   562, -1318, -1318, -1318, -1318, -1318, -1318,
     609, -1318, -1318, -1318,   716,   713, -1318,   -15, -1318,   717,
   -1318,   718,   184, -1318, -1318,   719,   454, -1318,   721, -1318,
     152, -1318,   722, -1318,   122, -1318,   726, -1318, -1318,    97,
   -1318, -1318, -1318, -1318,    20, -1318, -1318, -1318,   -10, -1318,
   -1318, -1318,    83, -1318, -1318,   725, -1318,   105, -1318,   727,
   -1318,   108, -1318,   728, -1318,   729,   436, -1318, -1318, -1318,
     628,   642, -1318, -1318, -1318, -1318,   570,   339,   638, -1318,
   -1318, -1318, -1318, -1318, -1318, -1318, -1318,   734, -1318,   554,
     692, -1318,   572, -1318, -1318,   738,   599, -1318, -1318, -1318,
   -1318, -1318, -1318, -1318, -1318, -1318,   741, -1318, -1318, -1318,
     743, -1318, -1318,   744, -1318, -1318,   745, -1318, -1318,   746,
   -1318, -1318, -1318, -1318, -1318,   574,   334, -1318, -1318, -1318,
   -1318, -1318, -1318,   747, -1318, -1318,   748, -1318, -1318, -1318,
     749, -1318, -1318, -1318, -1318,   576,   339,   654, -1318, -1318,
   -1318, -1318, -1318, -1318, -1318, -1318, -1318, -1318, -1318,   730,
   -1318,   578, -1318, -1318,   750,   585, -1318, -1318, -1318, -1318,
   -1318, -1318,   611,   610,   731,   669,   637,   640,   644,   648,
     651, -1318, -1318,   760,   761,   762, -1318, -1318, -1318, -1318,
     650,   656,   629,   667, -1318, -1318, -1318, -1318, -1318, -1318,
   -1318, -1318,   580, -1318,   763,   593, -1318, -1318, -1318, -1318,
   -1318, -1318,   597,   600,   739, -1318, -1318, -1318,   630,   731,
   -1318,   582, -1318, -1318, -1318, -1318, -1318, -1318, -1318,   772,
     773,   774, -1318, -1318, -1318, -1318,   778, -1318, -1318, -1318,
   -1318, -1318, -1318, -1318,   603,   605,   751, -1318, -1318, -1318,
     634,   739, -1318,   584, -1318, -1318,   621,   586,   588, -1318,
     780,   460, -1318, -1318, -1318, -1318, -1318, -1318, -1318, -1318,
     420, -1318, -1318, -1318,   636,   751, -1318,   602, -1318, -1318,
   -1318,   604,   606, -1318,   785,   445, -1318, -1318, -1318, -1318,
   -1318,   624,   731,   646, -1318, -1318, -1318, -1318,   166, -1318,
   -1318, -1318, -1318, -1318, -1318, -1318,   652,   658, -1318, -1318,
   -1318, -1318, -1318, -1318,   439, -1318, -1318,   608,   613, -1318,
     788,   447, -1318, -1318, -1318, -1318,   696,   659, -1318, -1318,
   -1318, -1318,   140, -1318, -1318, -1318, -1318, -1318, -1318, -1318,
     622,   626, -1318, -1318, -1318, -1318,   767,   615, -1318, -1318,
     661,   662,   757, -1318, -1318,   664,   671, -1318, -1318, -1318,
   -1318, -1318,    47,   796,   799, -1318, -1318, -1318,   801, -1318,
     617,   439, -1318, -1318, -1318, -1318, -1318, -1318, -1318, -1318,
   -1318, -1318, -1318, -1318, -1318, -1318, -1318, -1318, -1318,   709,
     673, -1318, -1318, -1318, -1318,   137, -1318, -1318, -1318, -1318,
   -1318, -1318, -1318,   666,   632, -1318, -1318, -1318, -1318, -1318,
   -1318,   675,   676,   757, -1318, -1318,   678,   680, -1318, -1318,
   -1318, -1318, -1318,   619,    24,   711,   797,   623,   -94, -1318,
   -1318, -1318, -1318, -1318, -1318,   681,   757, -1318,   625, -1318,
   -1318, -1318,   627,    24,   682, -1318, -1318, -1318, -1318, -1318,
   -1318, -1318, -1318, -1318,   798,   805, -1318,    74, -1318, -1318,
   -1318, -1318, -1318, -1318, -1318, -1318, -1318,   683,   685,   757,
   -1318, -1318,   686,   690, -1318, -1318, -1318, -1318, -1318,    54,
     631,   163, -1318, -1318,   694,   757,   633, -1318, -1318, -1318,
     635,   180,   700, -1318, -1318, -1318, -1318, -1318, -1318, -1318,
   -1318,   806,   477, -1318, -1318, -1318, -1318, -1318, -1318,   698,
     703, -1318, -1318, -1318,   701,   757,   639, -1318,   807,   702,
   -1318, -1318, -1318, -1318,   704, -1318, -1318, -1318, -1318, -1318,
   -1318,   812, -1318, -1318, -1318, -1318, -1318, -1318,   814, -1318,
     710,   102, -1318, -1318, -1318, -1318,   641,   215, -1318, -1318,
     720,   757,   643, -1318, -1318, -1318,   645,   124,   712, -1318,
   -1318, -1318, -1318, -1318,   -70, -1318, -1318, -1318, -1318, -1318,
   -1318, -1318, -1318, -1318, -1318, -1318, -1318, -1318, -1318, -1318,
     723,   757,   647, -1318,   702, -1318, -1318, -1318, -1318,   732,
   -1318, -1318, -1318, -1318,   819,   820, -1318, -1318, -1318, -1318,
   -1318, -1318, -1318, -1318, -1318, -1318, -1318,   649,   262,   816,
   -1318, -1318,   491, -1318, -1318, -1318, -1318,   653,    24, -1318,
     724,   757,   655, -1318,   702, -1318, -1318, -1318, -1318, -1318,
     733,   735, -1318,   736, -1318, -1318, -1318, -1318, -1318,   737,
   -1318, -1318,   -75, -1318, -1318, -1318, -1318, -1318, -1318, -1318,
   -1318, -1318, -1318, -1318, -1318, -1318, -1318,   742,   757,   657,
   -1318,   702, -1318, -1318, -1318, -1318,   740, -1318, -1318, -1318,
   -1318, -1318, -1318, -1318, -1318, -1318, -1318, -1318, -1318, -1318,
   -1318, -1318, -1318, -1318, -1318, -1318, -1318,   753,   752, -1318,
   -1318,   754, -1318, -1318,   821, -1318,   755,   757,   660, -1318,
     702, -1318, -1318, -1318, -1318,   758, -1318, -1318, -1318, -1318,
     -59, -1318, -1318, -1318, -1318, -1318, -1318, -1318, -1318, -1318,
   -1318, -1318, -1318, -1318, -1318, -1318, -1318,   663,   133,   759,
   -1318, -1318, -1318, -1318, -1318, -1318,   756,   757,   665, -1318,
     702, -1318, -1318, -1318, -1318,   764, -1318, -1318, -1318,   668,
   -1318, -1318, -1318, -1318, -1318, -1318, -1318, -1318,   765,   766,
   -1318, -1318,   754, -1318,   769,   757,   670, -1318,   702, -1318,
   -1318, -1318, -1318,   771, -1318, -1318,   338,   338, -1318, -1318,
     672,   239, -1318,   674,   289, -1318, -1318,   768,   757,   677,
   -1318,   702, -1318, -1318, -1318, -1318,   777, -1318, -1318, -1318,
   -1318, -1318, -1318,   770,   776, -1318, -1318,   754,   -99, -1318,
   -1318, -1318, -1318,   817, -1318, -1318, -1318, -1318, -1318, -1318,
   -1318, -1318, -1318, -1318, -1318,   757,   679, -1318,   702, -1318,
   -1318, -1318, -1318,   781, -1318, -1318,   824,     8, -1318, -1318,
   -1318, -1318,   823,   490, -1318, -1318,   684,   239, -1318,   779,
     757,   687, -1318,   702, -1318, -1318, -1318, -1318,   782, -1318,
   -1318, -1318, -1318,   775, -1318, -1318, -1318, -1318, -1318, -1318,
   -1318, -1318,   702, -1318, -1318, -1318, -1318, -1318, -1318, -1318,
   -1318, -1318, -1318, -1318,   757,   689, -1318,   702, -1318, -1318,
   -1318, -1318,   783, -1318, -1318, -1318, -1318,   691,   239, -1318,
     -97,   338,   825,   693, -1318,   702, -1318, -1318, -1318, -1318,
     786, -1318, -1318, -1318,   784, -1318,   828, -1318, -1318, -1318,
   -1318, -1318, -1318,   787, -1318, -1318, -1318, -1318, -1318, -1318,
   -1318, -1318, -1318, -1318,   757,   695, -1318,   702, -1318, -1318,
   -1318, -1318,   794, -1318, -1318, -1318, -1318, -1318,   789, -1318,
     697, -1318,   702, -1318, -1318, -1318, -1318,   790, -1318, -1318,
     793, -1318, -1318, -1318, -1318, -1318, -1318, -1318, -1318, -1318,
     818, -1318,   702, -1318, -1318, -1318, -1318,   795, -1318, -1318,
   -1318, -1318,   791,   830,   833, -1318,   699, -1318,   702, -1318,
   -1318, -1318, -1318,   792, -1318, -1318, -1318,   702, -1318, -1318,
   -1318, -1318,   800, -1318, -1318, -1318, -1318, -1318,   802, -1318,
   -1318, -1318, -1318, -1318,   702, -1318, -1318, -1318, -1318,   803,
   -1318, -1318,   804, -1318, -1318, -1318, -1318, -1318,   808, -1318,
   -1318, -1318, -1318
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
   -1318, -1318, -1318, -1318, -1318, -1318, -1318, -1318,   826, -1318,
   -1318, -1318, -1318, -1318, -1318, -1318,   811, -1318, -1318, -1318,
   -1318, -1318, -1318, -1318, -1318, -1318, -1318, -1318, -1318, -1318,
   -1318, -1318, -1318, -1318, -1318, -1318, -1318, -1318, -1318, -1318,
   -1318, -1318, -1318, -1318, -1318, -1318, -1318, -1318, -1318, -1318,
   -1318, -1318, -1318, -1318, -1318, -1318, -1318, -1318, -1318, -1318,
   -1318, -1318, -1318, -1318, -1318, -1318, -1318, -1318, -1318, -1318,
   -1318, -1318, -1318, -1318, -1318, -1318, -1318, -1318, -1318, -1318,
   -1318, -1318, -1318, -1318, -1318, -1318, -1318, -1318, -1318,   497,
   -1318, -1318, -1318, -1318, -1318, -1318, -1318, -1318, -1318, -1318,
   -1318, -1318,   809, -1318, -1318, -1318, -1318, -1318, -1318, -1318,
   -1318, -1318, -1318, -1318, -1318, -1318, -1318, -1318, -1318, -1318,
   -1318, -1318, -1318, -1318, -1318, -1318, -1318, -1318, -1318, -1318,
   -1318, -1318, -1318, -1318, -1318, -1318, -1318,   419, -1318, -1318,
   -1318, -1318, -1318, -1318, -1318, -1318, -1318, -1318, -1318, -1318,
     813, -1318, -1318, -1318, -1318, -1318, -1318, -1318, -1318, -1318,
   -1318, -1318, -1318, -1318, -1318,   323, -1318, -1318, -1318, -1318,
   -1318, -1318, -1318, -1318, -1318, -1318, -1318, -1318,   594, -1318,
   -1318, -1318, -1318, -1318, -1318, -1318, -1318, -1318, -1318, -1318,
   -1318, -1318, -1318, -1318, -1318, -1318, -1318, -1318, -1318, -1318,
     279, -1318, -1318, -1318, -1318, -1318, -1318, -1318,   273, -1318,
   -1318, -1318, -1318, -1318, -1318, -1318,   271, -1318, -1318, -1318,
   -1318, -1318, -1318, -1318,   269, -1318, -1318, -1318, -1318, -1318,
   -1318, -1318,   272, -1318, -1318, -1318, -1318, -1318, -1318, -1318,
     266, -1318, -1318, -1318, -1318, -1318, -1318, -1318,   267, -1318,
   -1318, -1318, -1318, -1318, -1318, -1318,   265, -1318, -1318, -1318,
   -1318, -1318, -1318, -1318,   258, -1318, -1318, -1318, -1318, -1318,
   -1318, -1318,   255, -1318, -1318, -1318, -1318, -1318, -1318, -1318,
     256, -1318, -1318, -1318, -1318, -1318, -1318, -1318,   252, -1318,
   -1318, -1318, -1318, -1318, -1318, -1318, -1318,   250, -1318, -1318,
   -1318, -1318, -1318, -1318, -1318, -1318, -1318, -1318, -1318, -1318,
   -1318, -1318, -1318, -1318, -1318, -1318, -1318, -1318, -1318, -1318,
   -1318, -1318, -1318, -1318, -1318, -1318, -1318, -1318,    15, -1318,
   -1318, -1318, -1318, -1318, -1318, -1318, -1318, -1318, -1318, -1318,
   -1318,   -33, -1318, -1318, -1318, -1318, -1318, -1318, -1318, -1318,
   -1318, -1318, -1318, -1318, -1318, -1318, -1318, -1318, -1318, -1318,
   -1318, -1318, -1318, -1318, -1318, -1318, -1318, -1318, -1318, -1318,
   -1318, -1318, -1318, -1318, -1318, -1318, -1318, -1318, -1318, -1318,
   -1318, -1318, -1318, -1318, -1318, -1318, -1318, -1318, -1318, -1318,
   -1318, -1318, -1318, -1318, -1318, -1318, -1318, -1318, -1318, -1318,
   -1318, -1318,  -479, -1053, -1318, -1318, -1318, -1318, -1318, -1318,
   -1318, -1318, -1318, -1318, -1318, -1318,  -282, -1318, -1318, -1318,
   -1318, -1318, -1318, -1318, -1318, -1318, -1318, -1318, -1318, -1318,
   -1318, -1318, -1318, -1318, -1318,  -473, -1318, -1318, -1318, -1318,
   -1318, -1318, -1318, -1318, -1318, -1318, -1318, -1318, -1318, -1318,
   -1318, -1318, -1318, -1318, -1318, -1318, -1318, -1318,    -8, -1318,
   -1318, -1318, -1318, -1318, -1318, -1318, -1318, -1318, -1318, -1318,
   -1318, -1318,   -85, -1318, -1318, -1318, -1318, -1318, -1318, -1318,
   -1318, -1318, -1318, -1318, -1318, -1318, -1318, -1318, -1318, -1318,
   -1318, -1318, -1318, -1318, -1318, -1318, -1318, -1318, -1318, -1318,
   -1318, -1318, -1318, -1318, -1318, -1318, -1318, -1318, -1318, -1318,
   -1318, -1318, -1318, -1318, -1318, -1318, -1318, -1318, -1318, -1318,
   -1318, -1318, -1318, -1318, -1318, -1318, -1318, -1318, -1318, -1318,
   -1318, -1318, -1318, -1318, -1318, -1318, -1318,  -354, -1318, -1318,
   -1318, -1318, -1318, -1318, -1318, -1318, -1318, -1318, -1318, -1318,
   -1318, -1318, -1318, -1318, -1318, -1318, -1318, -1318, -1318, -1318,
     -67, -1318, -1318, -1318, -1318, -1318, -1318, -1318, -1318, -1318,
   -1318, -1318, -1318,  -135, -1318, -1318, -1318, -1318, -1318, -1318,
   -1318, -1318, -1318, -1318, -1318, -1318, -1318, -1318, -1318, -1318,
   -1318, -1318, -1318, -1318, -1318, -1318, -1318, -1318, -1318, -1318,
   -1318, -1318, -1318, -1318, -1318, -1318, -1318, -1318, -1318, -1318,
   -1318, -1318, -1318, -1318, -1318, -1318, -1318, -1318, -1318, -1318,
   -1318, -1318, -1318, -1318, -1318, -1318, -1318, -1318, -1318, -1318,
   -1318, -1318, -1318, -1318, -1318, -1318, -1318, -1318,  -420, -1318,
   -1318, -1318, -1318, -1318, -1318, -1318, -1318, -1318, -1318, -1318,
   -1318, -1318, -1318, -1318, -1318, -1318,   -31, -1318, -1318, -1318,
   -1318, -1318,  -199, -1318, -1318, -1318, -1318,  -444, -1318, -1318,
   -1318, -1318, -1318, -1318, -1318, -1318, -1013, -1318, -1318, -1318,
     -96, -1318, -1318, -1318, -1318, -1318,  -970, -1318, -1318, -1317,
   -1318, -1318, -1318, -1318, -1318, -1318, -1318,  -425, -1318, -1318,
   -1318, -1012, -1318, -1318, -1318, -1318, -1318, -1318, -1011, -1318,
   -1318, -1318, -1310, -1318, -1318, -1318, -1318, -1318, -1318, -1318,
    -126, -1318, -1318, -1318,  -428, -1318, -1318, -1318,  -815, -1318,
    -957, -1049, -1318, -1318,  -790, -1318, -1318, -1318,   -86, -1318,
    -108,   -71, -1318, -1318,  -760, -1318, -1146, -1215, -1318, -1318,
   -1318, -1318, -1318, -1318, -1318, -1318, -1118, -1318, -1318, -1318,
   -1318, -1318, -1318, -1318, -1318, -1318, -1318, -1318, -1318, -1318,
   -1318,  -297,  -310, -1318, -1318
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint16 yytable[] =
{
     415,   181,   544,   412,  1046,   540,  1037,  1166,   414,   809,
     869,   833,  1464,   186,  1419,   443,  1256,   335,  1121,  1124,
    1125,  1420,   398,  1078,   426,  1306,  1332,   406,   407,  1067,
    1234,   214,   331,   208,   211,   596,   205,   322,   193,   190,
     600,  1351,   435,   436,   437,   604,  1312,   202,  1205,   304,
    1057,   309,  1057,   187,   587,  1057,  1296,   994,   995,  1112,
     161,   565,  1103,   160,  1108,  1109,   996,     6,   535,   601,
     565,  1147,   162,  1449,  1058,  1519,   537,   295,  1133,   303,
    1479,   308,   898,   289,  1198,  1201,  1202,  1480,   161,   996,
    1352,   535,   566,  1324,   587,   609,   996,  1332,   535,   537,
     162,   657,   634,     7,   610,   633,   537,  1235,  1173,  1272,
    1307,   597,   232,   587,  1357,   191,   194,   323,  1236,   209,
     206,   215,   212,  1236,   332,   444,   362,   188,   399,   203,
     679,  1516,  1347,   559,  1236,   233,   178,  1224,  1517,   587,
     179,   562,  1332,   587,  1210,  1266,  1269,  1270,    11,   234,
     596,   235,   593,   236,   600,   237,   677,   238,   604,  1363,
     384,   582,   386,   239,   388,   240,   996,   241,   583,   242,
     770,   243,  1384,   244,  1249,   245,  1364,   246,    27,   247,
    1119,  1219,  1220,  1221,  1222,   587,   605,   913,   914,   375,
     578,   377,    13,   379,   397,   579,   588,   606,  1283,   703,
    1409,   802,   702,   390,   534,   392,   587,   535,  1465,   178,
     916,   536,   917,   179,  1289,   537,   336,   337,   338,   339,
     587,   681,   996,  1443,   918,   919,   605,   570,    14,   609,
     571,   673,  1119,  1142,  1143,  1144,  1145,   684,   687,   913,
     914,  1128,   645,   582,     1,     2,   651,   652,   653,   292,
     670,  1317,   292,   178,   826,   293,   534,   179,   293,   535,
    1461,   178,   916,   536,   917,   179,  1086,   537,   749,  1087,
    1088,   748,  1089,   578,    17,    18,   918,   919,   667,  1119,
     100,   996,  1204,   535,    73,  1493,   913,   914,    22,    23,
    1340,   537,  1142,  1143,  1144,  1145,   117,  1087,  1088,   770,
    1089,   145,   661,   534,  1499,   571,   535,   148,   178,   916,
     536,   917,   179,   151,   537,   903,    81,   964,   904,  1508,
     965,   170,  1020,   918,   919,  1021,   705,    30,    31,   987,
    1377,   714,   233,   535,   539,   178,   152,  1528,   196,   179,
     217,   537,   281,    82,   406,   407,   234,    83,   235,    84,
     236,    85,   237,    86,   238,   733,   734,   735,  1402,   290,
     239,  1418,   240,   300,   241,   305,   242,   310,   243,  1544,
     244,   311,   245,   318,   246,   320,   247,  1429,    76,    77,
     534,  1436,   319,   535,  1553,   178,   321,   536,   326,   179,
      35,   537,   352,   353,   354,   102,   103,  1166,  1273,    36,
     754,    37,   325,    38,  1559,    39,   328,    40,   327,    41,
     765,    42,   330,    43,   329,    44,   334,    45,  1454,    46,
    1570,   359,    82,   107,   108,   368,    83,  1478,    84,  1573,
      85,   371,    86,   393,   632,   112,   113,   120,   121,   125,
     126,   786,   380,  1486,   130,   131,  1579,   135,   136,   424,
     797,   140,   141,   410,   155,   156,   197,   198,   218,   219,
     810,   225,   226,   913,   914,   283,   284,   313,   314,   341,
     342,   347,   348,   363,   364,   915,   425,  1501,  1515,   416,
     534,   427,   821,   535,  1002,   178,   916,   536,   917,   179,
     342,   537,   834,   401,   402,   418,   419,   438,   439,   431,
     918,   919,   447,   448,   453,   454,   458,   459,   515,   860,
     463,   464,   468,   469,   474,   475,   870,   446,  1371,   452,
      36,   473,    37,   504,    38,   522,    39,  1537,    40,   523,
      41,   701,    42,   527,    43,   524,    44,   419,    45,   525,
      46,   479,   480,   909,   484,   485,  1047,   489,   490,   494,
     495,   499,   500,   505,   506,   510,   511,   516,   517,   531,
     532,   526,   574,   575,   548,  1079,   614,   615,   618,   619,
     628,   629,   646,   647,   664,   575,   549,   970,   691,   615,
     697,   698,   715,   716,   730,   731,   743,   744,   755,   756,
     787,   788,   811,   812,   835,   836,   843,   844,   848,   849,
     747,  1113,   552,  1126,   556,  1005,  1123,   557,   854,   855,
     861,   862,   871,   872,   877,   878,   882,   883,   940,   941,
     558,   888,   889,   945,   946,   978,   979,  1007,  1008,  1042,
    1043,   951,   952,  1052,  1053,  1069,  1070,  1074,  1075,   563,
    1026,  1114,  1115,  1134,  1135,  1139,  1140,  1160,  1161,  1174,
    1175,  1192,  1193,  1211,  1212,  1216,  1217,  1250,  1251,  1260,
    1261,  1275,  1161,  1279,  1280,  1290,  1291,  1318,  1319,  1203,
    1341,  1342,  1200,  1358,  1359,  1378,  1379,  1068,  1387,  1388,
    1403,  1404,  1413,  1414,  1422,  1423,  1081,  1437,  1438,  1455,
    1456,  1468,  1469,  1082,  1473,  1474,  1085,  1487,  1488,  1502,
    1503,  1510,  1511,  1522,  1523,  1538,  1539,  1547,  1548,  1564,
    1565,   564,   569,   586,   613,   517,   624,   636,   637,   638,
     635,   654,   641,   656,   655,   659,   693,   710,   660,   663,
    1271,   666,   669,  1268,   672,   683,   689,   686,   704,   690,
    1284,   619,   706,   707,   720,   725,   721,   726,   727,   728,
     729,   740,   741,   742,   750,   773,   760,   766,   751,   774,
     761,   767,   775,   779,   780,   781,   776,   785,   770,   792,
     777,   798,   782,   784,  1187,   778,   793,   802,   783,   799,
     816,   817,   818,   805,   819,   822,   853,   829,   840,   865,
     826,   887,   823,   894,   950,   957,   976,   987,   971,  1003,
     910,   899,  1004,   889,  1006,  1051,  1083,   855,  1013,  1244,
    1048,  1084,  1159,  1179,   960,   983,   990,   952,  1186,  1188,
     903,   984,  1258,  1259,  1274,  1451,  1556,  1335,  1016,  1032,
    1463,  1521,  1080,  1466,  1532,  1033,  1562,  1098,  1063,  1563,
     528,   428,   625,   360,  1099,   662,   658,   665,    72,   668,
    1027,  1129,  1057,  1328,  1185,   674,   671,   964,  1038,   101,
     682,   678,   685,   680,  1169,  1394,  1165,   688,   692,  1297,
    1445,   694,   911,   991,  1104,  1020,  1304,  1206,  1156,  1450,
    1276,  1446,  1039,   972,  1329,  1285,  1245,  1028,  1105,  1395,
    1012,  1300,  1191,     0,     0,     0,     0,   171,  1233,     0,
       0,  1180,  1190,  1421,     0,  1313,  1428,     0,     0,  1372,
    1257,  1326,  1327,     0,  1348,     0,  1336,     0,     0,     0,
       0,  1373,     0,     0,  1385,  1352,  1325,  1410,     0,  1235,
    1398,     0,     0,  1432,  1305,  1122,  1298,  1444,     0,  1462,
    1301,  1509,  1494,  1555,  1482,     0,     0,  1236,  1349,  1350,
    1529,  1307,  1545,  1497,  1554,     0,  1571,  1560,     0,     0,
       0,     0,  1574,     0,     0,  1580,     0,     0,  1575,  1481,
    1581,     0,     0,  1535,  1582,     0,     0,   282,     0,     0,
       0,     0,     0,  1546,  1531,     0,     0,     0,  1386,     0,
       0,     0,     0,     0,     0,     0,  1561,     0,     0,     0,
       0,  1199,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    1518,     0,     0,     0,     0,  1431,     0,     0,     0,  1411,
    1412,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  1452,     0,     0,     0,     0,     0,
       0,     0,  1267,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1495,  1496,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  1530,  1520,     0,     0,     0,  1533,  1534,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1557,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1427,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  1576,  1577
};

static const yytype_int16 yycheck[] =
{
     310,    97,   430,   300,   974,   430,   963,  1060,   305,   769,
     825,   801,     4,    99,  1331,     4,  1134,     8,  1031,  1031,
    1031,  1331,     4,   993,   334,   100,  1241,     6,     7,   986,
     100,     4,     4,     4,     4,   479,     4,     4,     4,     4,
     484,   100,   352,   353,   354,   489,  1192,     4,  1097,   175,
     149,   177,   149,     4,   123,   149,  1174,    10,    11,  1029,
      97,    85,  1019,    72,    10,    11,    42,     0,    44,   138,
      85,  1041,   109,   172,   168,   172,    52,   173,  1035,   175,
    1397,   177,   842,   169,  1097,  1097,  1097,  1397,    97,    42,
     149,    44,   116,  1211,   123,   121,    42,  1312,    44,    52,
     109,   116,   530,    67,   130,   530,    52,   177,  1065,  1158,
     185,   140,    74,   123,  1260,    80,    82,    84,   193,    90,
      88,    94,    92,   193,    96,   114,   252,    78,   110,    86,
     140,  1448,  1250,   112,   193,    97,    46,  1107,  1448,   123,
      50,   438,  1357,   123,  1101,  1158,  1158,  1158,    14,   111,
     594,   113,   136,   115,   598,   117,   136,   119,   602,    26,
     268,   121,   270,   125,   272,   127,    42,   129,   128,   131,
      37,   133,  1290,   135,  1131,   137,    43,   139,    71,   141,
      17,    57,    58,    59,    60,   123,   121,    24,    25,   260,
     121,   262,    15,   264,   280,   126,   134,   132,  1168,   627,
    1318,    38,   627,   274,    41,   276,   123,    44,   200,    46,
      47,    48,    49,    50,  1171,    52,   207,   208,   209,   210,
     123,   138,    42,  1341,    61,    62,   121,   118,    69,   121,
     121,   134,    17,    53,    54,    55,    56,   132,   130,    24,
      25,  1031,   552,   121,    12,    13,   556,   557,   558,    45,
     128,  1208,    45,    46,    39,    51,    41,    50,    51,    44,
    1378,    46,    47,    48,    49,    50,   192,    52,   696,   195,
     196,   696,   198,   121,    10,    11,    61,    62,   126,    17,
      68,    42,  1097,    44,    73,  1403,    24,    25,    10,    11,
    1247,    52,    53,    54,    55,    56,    66,   195,   196,    37,
     198,    65,   118,    41,  1422,   121,    44,    16,    46,    47,
      48,    49,    50,    15,    52,   149,    70,   177,   152,  1437,
     180,    70,   185,    61,    62,   188,   636,    10,    11,    40,
    1287,   641,    97,    44,   430,    46,    75,  1455,     3,    50,
       3,    52,    72,    97,     6,     7,   111,   101,   113,   103,
     115,   105,   117,   107,   119,    21,    22,    23,  1315,    10,
     125,  1331,   127,    10,   129,    10,   131,     3,   133,  1487,
     135,    10,   137,    78,   139,    82,   141,  1334,    10,    11,
      41,  1338,    80,    44,  1502,    46,     8,    48,    88,    50,
      68,    52,    30,    31,    32,    10,    11,  1450,  1158,    77,
     710,    79,    86,    81,  1522,    83,    92,    85,    90,    87,
     720,    89,     8,    91,    94,    93,     6,    95,  1375,    97,
    1538,    74,    97,    10,    11,    18,   101,  1397,   103,  1547,
     105,    19,   107,    27,   530,    10,    11,    10,    11,    10,
      11,   751,    20,  1400,    10,    11,  1564,    10,    11,    84,
     760,    10,    11,     3,    10,    11,    10,    11,    10,    11,
     770,    10,    11,    24,    25,    10,    11,    10,    11,    98,
      99,    10,    11,    10,    11,    36,    96,  1434,  1448,     6,
      41,    98,   792,    44,   912,    46,    47,    48,    49,    50,
      99,    52,   802,    10,    11,    98,    99,    10,    11,   145,
      61,    62,    10,    11,    10,    11,    10,    11,   110,   819,
      10,    11,    10,    11,    10,    11,   826,     8,  1278,     8,
      77,     8,    79,     8,    81,   102,    83,  1484,    85,     8,
      87,   627,    89,    98,    91,   104,    93,    99,    95,   106,
      97,    10,    11,   853,    10,    11,   974,    10,    11,    10,
      11,    10,    11,    10,    11,    10,    11,    98,    99,    10,
      11,   108,   120,   121,    76,   993,   142,   143,    98,    99,
      10,    11,    10,    11,   120,   121,   173,   887,   142,   143,
      10,    11,    10,    11,    10,    11,    10,    11,    10,    11,
      10,    11,    10,    11,    10,    11,    10,    11,    10,    11,
     696,  1029,    33,  1031,     6,   915,  1031,     6,   148,   149,
     190,   191,    10,    11,    10,    11,    10,    11,    10,    11,
       6,   176,   177,    10,    11,    10,    11,    10,    11,    10,
      11,   184,   185,    10,    11,    10,    11,    10,    11,   114,
     950,    10,    11,    10,    11,    10,    11,   170,   171,    10,
      11,    10,    11,    10,    11,    10,    11,    10,    11,    10,
      11,   170,   171,    10,    11,    10,    11,    10,    11,  1097,
      10,    11,  1097,    10,    11,    10,    11,   987,    10,    11,
      10,    11,    10,    11,    10,    11,   996,    10,    11,    10,
      11,   201,   202,  1003,    10,    11,  1006,    10,    11,    10,
      11,    10,    11,    10,    11,    10,    11,    10,    11,    10,
      11,     6,     6,     6,     6,    99,    98,     3,     3,   181,
     100,   112,    34,    10,     8,     8,    98,    35,    10,    10,
    1158,    10,    10,  1158,     8,    10,     8,    10,   100,    10,
    1168,    99,     8,   189,     6,     4,   147,     4,     4,     4,
       4,     4,     4,     4,   100,    86,     6,   146,    28,   122,
     175,   151,   122,     3,     3,     3,   122,   100,    37,     6,
     122,   174,   122,   144,  1084,   124,   183,    38,   122,   179,
       8,     8,     8,   153,     6,   182,     6,   153,   167,   153,
      39,     6,   187,   169,     6,    99,    29,    40,   176,     3,
     148,   155,     3,   177,     3,     8,     8,   149,    99,  1119,
      99,     6,     6,     6,   155,   154,   152,   185,     6,     5,
     149,   159,     3,     3,     8,     8,     8,     6,   155,   154,
       6,     6,   150,    10,     6,   159,     6,   154,   157,     6,
     421,   344,   519,   249,   159,   572,   567,   576,    22,   580,
     184,   157,   149,   100,   150,   589,   584,   177,   180,    48,
     602,   594,   607,   598,   163,   100,   168,   611,   616,  1179,
     100,   621,   857,   906,   188,   185,  1186,   157,   178,  1358,
    1162,  1354,   967,   891,  1238,   161,   163,   954,  1023,  1309,
     921,   156,  1091,    -1,    -1,    -1,    -1,    88,   186,    -1,
      -1,   199,   192,  1331,    -1,   163,  1334,    -1,    -1,   150,
     178,  1221,  1222,    -1,   156,    -1,   161,    -1,    -1,    -1,
      -1,   165,    -1,    -1,   160,   149,   186,   156,    -1,   177,
     161,    -1,    -1,   165,   197,  1031,   203,   160,    -1,   158,
     204,   158,   160,   150,   165,    -1,    -1,   193,  1258,  1259,
     164,   185,   158,   178,   164,    -1,   164,   162,    -1,    -1,
      -1,    -1,   162,    -1,    -1,   162,    -1,    -1,   166,  1397,
     166,    -1,    -1,   186,   166,    -1,    -1,   164,    -1,    -1,
      -1,    -1,    -1,   194,   200,    -1,    -1,    -1,  1298,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   205,    -1,    -1,    -1,
      -1,  1097,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    1448,    -1,    -1,    -1,    -1,  1335,    -1,    -1,    -1,  1326,
    1327,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1364,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1158,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1411,  1412,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1463,  1451,    -1,    -1,    -1,  1468,  1469,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1521,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1334,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1562,  1563
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,    12,    13,   212,   213,   214,     0,    67,   219,   220,
     221,    14,   215,    15,    69,   306,   307,    10,    11,   222,
     223,   224,    10,    11,   216,   217,   218,    71,   354,   355,
      10,    11,   308,   309,   310,    68,    77,    79,    81,    83,
      85,    87,    89,    91,    93,    95,    97,   225,   226,   227,
     228,   229,   234,   235,   240,   241,   246,   247,   254,   255,
     260,   261,   266,   267,   272,   273,   278,   279,   284,   285,
     292,   293,   219,    73,   382,   383,    10,    11,   356,   357,
     358,    70,    97,   101,   103,   105,   107,   311,   312,   313,
     314,   315,   321,   322,   328,   329,   335,   336,   340,   341,
      68,   227,    10,    11,   230,   231,   232,    10,    11,   236,
     237,   238,    10,    11,   242,   243,   244,    66,   248,   249,
      10,    11,   256,   257,   258,    10,    11,   262,   263,   264,
      10,    11,   268,   269,   270,    10,    11,   274,   275,   276,
      10,    11,   280,   281,   282,    65,   286,   287,    16,   294,
     949,    15,    75,   514,   515,    10,    11,   384,   385,   386,
      72,    97,   109,   359,   360,   361,   362,   363,   368,   369,
      70,   313,   316,   317,   323,   324,   330,   331,    46,    50,
     337,   891,   892,   893,   894,   342,   949,     4,    78,   233,
       4,    80,   239,     4,    82,   245,     3,    10,    11,   250,
     251,   252,     4,    86,   259,     4,    88,   265,     4,    90,
     271,     4,    92,   277,     4,    94,   283,     3,    10,    11,
     288,   289,   290,   983,   984,    10,    11,   295,   296,   297,
     516,   517,    74,    97,   111,   113,   115,   117,   119,   125,
     127,   129,   131,   133,   135,   137,   139,   141,   387,   388,
     389,   390,   391,   398,   399,   404,   405,   412,   413,   420,
     421,   428,   429,   436,   437,   444,   445,   452,   453,   460,
     461,   468,   469,   476,   477,   484,   485,   492,   493,   500,
     501,    72,   361,    10,    11,   364,   365,   366,   370,   949,
      10,   319,    45,    51,   318,   891,   931,   932,   933,   934,
      10,   326,   325,   891,   931,    10,   333,   332,   891,   931,
       3,    10,   338,    10,    11,   343,   344,   345,    78,    80,
      82,     8,     4,    84,   253,    86,    88,    90,    92,    94,
       8,     4,    96,   291,     6,     8,   207,   208,   209,   210,
     985,    98,    99,   298,   299,   300,   301,    10,    11,   519,
     520,   521,    30,    31,    32,   518,   940,   946,   956,    74,
     389,   392,   931,    10,    11,   400,   401,   402,    18,   406,
     944,    19,   414,   952,   422,   952,   430,   952,   438,   952,
      20,   446,   951,   454,   951,   462,   951,   470,   951,   478,
     952,   486,   952,    27,   494,   953,   502,   949,     4,   110,
     367,    10,    11,   371,   372,   373,     6,     7,   320,   982,
       3,   327,   982,   334,   982,   983,     6,   339,    98,    99,
     346,   347,   348,   349,    84,    96,   983,    98,   300,   302,
     303,   145,   522,   523,   524,   983,   983,   983,    10,    11,
     393,   394,   395,     4,   114,   403,     8,    10,    11,   407,
     408,   409,     8,    10,    11,   415,   416,   417,    10,    11,
     423,   424,   425,    10,    11,   431,   432,   433,    10,    11,
     439,   440,   441,     8,    10,    11,   447,   448,   449,    10,
      11,   455,   456,   457,    10,    11,   463,   464,   465,    10,
      11,   471,   472,   473,    10,    11,   479,   480,   481,    10,
      11,   487,   488,   489,     8,    10,    11,   495,   496,   497,
      10,    11,   503,   504,   505,   110,    98,    99,   374,   375,
     376,   377,   102,     8,   104,   106,   108,    98,   348,   350,
     351,    10,    11,   305,    41,    44,    48,    52,   304,   891,
     908,   909,   910,   911,   935,   936,   937,   938,    76,   173,
     653,   654,    33,   525,   526,   950,     6,     6,     6,   112,
     396,   397,   982,   114,     6,    85,   116,   410,   411,     6,
     118,   121,   418,   419,   120,   121,   426,   427,   121,   126,
     434,   435,   121,   128,   442,   443,     6,   123,   134,   450,
     451,   878,   879,   136,   458,   459,   878,   140,   466,   467,
     878,   138,   474,   475,   878,   121,   132,   482,   483,   121,
     130,   490,   491,     6,   142,   143,   498,   499,    98,    99,
     506,   507,   508,   509,    98,   376,   378,   379,    10,    11,
     353,   352,   891,   908,   935,   100,     3,     3,   181,   755,
     756,    34,   655,   656,   948,   983,    10,    11,   527,   528,
     529,   983,   983,   983,   112,     8,    10,   116,   411,     8,
      10,   118,   419,    10,   120,   427,    10,   126,   435,    10,
     128,   443,     8,   134,   451,   880,   881,   136,   459,   140,
     467,   138,   475,    10,   132,   483,    10,   130,   491,     8,
      10,   142,   499,    98,   508,   510,   511,    10,    11,   381,
     380,   891,   908,   935,   100,   983,     8,   189,   856,   857,
      35,   757,   758,   947,   983,    10,    11,   657,   658,   659,
       6,   147,   530,   531,   532,     4,     4,     4,     4,     4,
      10,    11,   886,    21,    22,    23,   882,   883,   884,   885,
       4,     4,     4,    10,    11,   513,   512,   891,   908,   935,
     100,    28,   858,   954,   983,    10,    11,   759,   760,   761,
       6,   175,   660,   661,   662,   983,   146,   151,   544,   545,
      37,   533,   955,    86,   122,   122,   122,   122,   124,     3,
       3,     3,   122,   122,   144,   100,   983,    10,    11,   859,
     860,   861,     6,   183,   762,   763,   764,   983,   174,   179,
     675,   676,    38,   663,   945,   153,   558,   559,   546,   955,
     983,    10,    11,   534,   535,   536,     8,     8,     8,     6,
     862,   983,   182,   187,   776,   777,    39,   765,   939,   153,
     689,   690,   677,   945,   983,    10,    11,   664,   665,   666,
     167,   606,   607,    10,    11,   560,   561,   562,    10,    11,
     547,   548,   549,     6,   148,   149,   537,   538,   539,   540,
     983,   190,   191,   863,   864,   153,   790,   791,   778,   939,
     983,    10,    11,   766,   767,   768,   737,    10,    11,   691,
     692,   693,    10,    11,   678,   679,   680,     6,   176,   177,
     667,   668,   669,   670,   169,   620,   621,   608,   955,   155,
     563,   564,   565,   149,   152,   550,   551,   552,   553,   983,
     148,   539,   541,    24,    25,    36,    47,    49,    61,    62,
     865,   866,   867,   887,   888,   889,   890,   891,   908,   912,
     913,   914,   915,   919,   920,   921,   922,   935,   943,   838,
      10,    11,   792,   793,   794,    10,    11,   779,   780,   781,
       6,   184,   185,   769,   770,   771,   772,    99,   738,   739,
     155,   694,   695,   696,   177,   180,   681,   682,   683,   684,
     983,   176,   669,   671,   672,   635,    29,   622,    10,    11,
     609,   610,   611,   154,   159,   571,   572,    40,   566,   941,
     152,   552,   554,   555,    10,    11,    42,   542,   543,   897,
     898,   899,   935,     3,     3,   983,     3,    10,    11,   868,
     869,   870,   867,    99,   839,   840,   155,   795,   796,   797,
     185,   188,   782,   783,   784,   785,   983,   184,   771,   773,
     740,   741,   154,   159,   702,   703,   697,   941,   180,   683,
     685,   686,    10,    11,   674,   673,   897,   935,    99,   636,
     637,     8,    10,    11,   623,   624,   625,   149,   168,   612,
     613,   614,   615,   157,   578,   579,   573,   941,   983,    10,
      11,   567,   568,   569,    10,    11,   557,   556,   897,   935,
     150,   983,   983,     8,     6,   983,   192,   195,   196,   198,
     871,   872,   873,   874,   875,   876,   841,   842,   154,   159,
     803,   804,   798,   941,   188,   784,   786,   787,    10,    11,
     774,   775,   897,   935,    10,    11,   743,   744,   745,    17,
     742,   887,   891,   908,   912,   919,   935,   942,   945,   157,
     709,   710,   704,   941,    10,    11,   698,   699,   700,    10,
      11,   688,    53,    54,    55,    56,   687,   897,   900,   901,
     902,   903,   923,   924,   925,   926,   178,   638,   639,     6,
     170,   171,   626,   627,   628,   168,   614,   616,   617,   163,
     585,   586,   580,   941,    10,    11,   574,   575,   576,     6,
     199,   570,   967,   968,   975,   150,     6,   983,     5,   877,
     192,   873,    10,    11,   844,   845,   846,   843,   887,   891,
     908,   912,   919,   935,   939,   942,   157,   810,   811,   805,
     941,    10,    11,   799,   800,   801,    10,    11,   789,    57,
      58,    59,    60,   788,   897,   904,   905,   906,   907,   927,
     928,   929,   930,   186,   100,   177,   193,   746,   747,   748,
     749,   957,   958,   959,   983,   163,   716,   717,   711,   941,
      10,    11,   705,   706,   707,   701,   967,   178,     3,     3,
      10,    11,   641,   642,   643,   640,   887,   891,   908,   912,
     919,   935,   942,   955,     8,   170,   627,   629,   630,    10,
      11,   619,   618,   897,   935,   161,   592,   593,   587,   941,
      10,    11,   581,   582,   583,   577,   967,   983,   203,   976,
     156,   204,   969,   970,   983,   197,   100,   185,   847,   848,
     849,   850,   957,   163,   817,   818,   812,   941,    10,    11,
     806,   807,   808,   802,   967,   186,   983,   983,   100,   748,
     750,   751,   958,   960,   961,     6,   161,   723,   724,   718,
     941,    10,    11,   712,   713,   714,   708,   967,   156,   983,
     983,   100,   149,   644,   645,   646,   647,   957,    10,    11,
     632,   633,   634,    26,    43,   631,   895,   896,   916,   917,
     918,   955,   150,   165,   599,   600,   594,   941,    10,    11,
     588,   589,   590,   584,   967,   160,   983,    10,    11,   977,
     978,   979,   971,   972,   100,   849,   851,   852,   161,   824,
     825,   819,   941,    10,    11,   813,   814,   815,   809,   967,
     156,   982,   982,    10,    11,   753,   754,   752,   897,   900,
     923,   935,    10,    11,   963,   964,   965,   891,   935,   941,
     962,   983,   165,   730,   731,   725,   941,    10,    11,   719,
     720,   721,   715,   967,   160,   100,   646,   648,   649,   172,
     613,     8,   983,   601,   941,    10,    11,   595,   596,   597,
     591,   967,   158,     6,     4,   200,    10,   974,   201,   202,
     973,   980,   981,    10,    11,   854,   855,   853,   897,   900,
     923,   935,   165,   831,   832,   826,   941,    10,    11,   820,
     821,   822,   816,   967,   160,   983,   983,   178,   966,   967,
     732,   941,    10,    11,   726,   727,   728,   722,   967,   158,
      10,    11,   651,   652,   650,   897,   900,   923,   935,   172,
     982,     6,    10,    11,   602,   603,   604,   598,   967,   164,
     983,   200,     6,   983,   983,   186,   833,   941,    10,    11,
     827,   828,   829,   823,   967,   158,   194,    10,    11,   733,
     734,   735,   729,   967,   164,   150,     8,   983,   605,   967,
     162,   205,     6,     6,    10,    11,   834,   835,   836,   830,
     967,   164,   736,   967,   162,   166,   983,   983,   837,   967,
     162,   166,   166
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
;}
    break;

  case 5:

    {
#ifdef DEBUG
yydebug = 1;
#endif
;}
    break;

  case 36:

    {	if (parserData->serviceURIPresent)
		osolerror( NULL, osoption, parserData, osglData, "only one <serviceURI> element allowed");
	else
		parserData->serviceURIPresent = true;
	
;}
    break;

  case 42:

    {
		if (osoption->setServiceURI((yyvsp[(1) - (1)].sval)) == false)
			osolerror( NULL, osoption, parserData, osglData, "setServiceURI failed");
			//free($1); 
		parserData->errorText = NULL;
	;}
    break;

  case 44:

    {	if (parserData->serviceNamePresent)
			osolerror(NULL, NULL, parserData, osglData, "only one serviceName element allowed");
		parserData->serviceNamePresent = true;
	;}
    break;

  case 50:

    {
			osoption->setServiceName((yyvsp[(1) - (1)].sval)); 
			//free($1); 
			parserData->errorText = NULL;
		;}
    break;

  case 52:

    {	if (parserData->instanceNamePresent)
			osolerror(NULL, NULL, parserData, osglData, "only one instanceName element allowed");
		parserData->instanceNamePresent = true;
	;}
    break;

  case 58:

    {
		if (osoption->setInstanceName((yyvsp[(1) - (1)].sval)) == false) 
			osolerror( NULL, osoption, parserData, osglData, "setInstanceName failed");
		//free($1); 
		parserData->errorText = NULL;
	;}
    break;

  case 59:

    {
	if (osoption->setInstanceLocation(parserData->tempStr,parserData->typeAttribute) == false)
		osolerror(NULL, NULL, parserData, osglData, "setInstanceLocation failed");
	parserData->errorText = NULL;
;}
    break;

  case 60:

    {
		if (parserData->instanceLocationPresent)
			osolerror(NULL, NULL, parserData, osglData, "only one instanceLocation element allowed");
		parserData->instanceLocationPresent = true;
		parserData->typeAttribute = "local";
	;}
    break;

  case 62:

    {   
		if (verifyLocationType(parserData->typeAttribute) == false)
			osolerror(NULL, NULL, parserData, osglData, "instance location type not recognized");
		parserData->errorText = NULL;
	;}
    break;

  case 63:

    { 
	parserData->typeAttribute = (yyvsp[(2) - (3)].sval); 
	free((yyvsp[(2) - (3)].sval));
;}
    break;

  case 69:

    {	
		parserData->tempStr = (yyvsp[(1) - (1)].sval);
		//free($1); 
	;}
    break;

  case 71:

    {	if (parserData->jobIDPresent)
			osolerror(NULL, NULL, parserData, osglData, "only one jobID element allowed");
		parserData->jobIDPresent = true;
	;}
    break;

  case 77:

    {
		if (osoption->setJobID((yyvsp[(1) - (1)].sval)) == false)
			osolerror( NULL, osoption, parserData, osglData, "setJobID failed");
		//free($1); 
		parserData->errorText = NULL;
	;}
    break;

  case 79:

    {
		if (parserData->solverToInvokePresent)
			osolerror(NULL, NULL, parserData, osglData, "only one solverToInvoke element allowed");
		parserData->solverToInvokePresent = true;
	;}
    break;

  case 85:

    {
		if (osoption->setSolverToInvoke((yyvsp[(1) - (1)].sval)) == false)
			osolerror( NULL, osoption, parserData, osglData, "setSolverToInvoke failed");
		//free($1); 
		parserData->errorText = NULL;
	;}
    break;

  case 87:

    {
	if (parserData->licensePresent)
		osolerror( NULL, osoption, parserData, osglData, "only one <license> element allowed");
	parserData->licensePresent = true;	
;}
    break;

  case 93:

    {
		if (osoption->setLicense((yyvsp[(1) - (1)].sval)) == false)
			osolerror( NULL, osoption, parserData, osglData, "setLicense failed");
		//free($1);
		parserData->errorText = NULL;
	;}
    break;

  case 95:

    {	if (parserData->usernamePresent)
		osolerror( NULL, osoption, parserData, osglData, "only one <username> element allowed");
	parserData->usernamePresent = true;	
;}
    break;

  case 101:

    {
		if (osoption->setUserName((yyvsp[(1) - (1)].sval)) == false)
			osolerror( NULL, osoption, parserData, osglData, "setUsername failed");
		//free($1); 
		parserData->errorText = NULL;
	;}
    break;

  case 103:

    {	if (parserData->passwordPresent)
		osolerror( NULL, osoption, parserData, osglData, "only one <password> element allowed");
	parserData->passwordPresent = true;	
;}
    break;

  case 109:

    {
		if (osoption->setPassword((yyvsp[(1) - (1)].sval)) == false)
			osolerror( NULL, osoption, parserData, osglData, "setPassword failed");
		//free($1); 
		parserData->errorText = NULL;
	;}
    break;

  case 110:

    {
	if (osoption->setContact(parserData->tempStr,parserData->typeAttribute) == false)
		osolerror( NULL, osoption, parserData, osglData, "setContact failed");
	parserData->errorText = NULL;
;}
    break;

  case 111:

    {
	if (parserData->contactPresent)
		osolerror( NULL, osoption, parserData, osglData, "only one <contact> element allowed");
	parserData->contactPresent = true;
	parserData->typeAttribute = "osp";
	parserData->tempStr = "";
;}
    break;

  case 113:

    {   
		if (verifyTransportType(parserData->typeAttribute) == false)
			osolerror(NULL, NULL, parserData, osglData, "transport type not recognized");
	;}
    break;

  case 114:

    { 
	parserData->typeAttribute = (yyvsp[(2) - (3)].sval); 
	free((yyvsp[(2) - (3)].sval));
;}
    break;

  case 120:

    {
		parserData->tempStr = (yyvsp[(1) - (1)].sval);
	;}
    break;

  case 122:

    {	if (parserData->otherGeneralOptionsPresent)
			osolerror(NULL, NULL, parserData, osglData, "only one <general> <other> element allowed");
		parserData->otherGeneralOptionsPresent = true;
	;}
    break;

  case 123:

    {
	if (parserData->tempInt < 0) osolerror(NULL, NULL, parserData, osglData, "number of other general options cannot be negative");
	parserData->numberOf = parserData->tempInt;
	parserData->kounter = 0;
;}
    break;

  case 124:

    {	if (parserData->numberOf > 0)
			osolerror(NULL, NULL, parserData, osglData, "expected at least one <other> element");
	;}
    break;

  case 125:

    {	if (parserData->kounter < parserData->numberOf - 1)
			osolerror(NULL, NULL, parserData, osglData, "fewer <other> elements than specified");
	;}
    break;

  case 132:

    {	
	parserData->kounter++;
	if (osoption->setAnOtherGeneralOption(parserData->nameAttribute, parserData->valueAttribute, parserData->descriptionAttribute) == false)
		osolerror(NULL, NULL, parserData, osglData, "setOtherGeneralOption failed");
;}
    break;

  case 133:

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

  case 134:

    {
	if (!parserData->nameAttributePresent)
		osolerror (NULL, NULL, parserData, osglData, "<other> must have name attribute");
;}
    break;

  case 137:

    {	if (parserData->nameAttribute.length() == 0)
			osolerror(NULL, NULL, parserData, osglData, "otherOption name cannot be empty");
	;}
    break;

  case 159:

    {	if (parserData->minDiskSpacePresent)
			osolerror(NULL, NULL, parserData, osglData, "only one minDiskSpace element allowed");
		parserData->minDiskSpacePresent = true;	
		parserData->unitAttributePresent = false;	
		parserData->descriptionAttributePresent = false;	
		parserData->unitAttribute = "byte";	
		parserData->descriptionAttribute = "";
	;}
    break;

  case 166:

    {
	if (osoption->setMinDiskSpace(parserData->unitAttribute, parserData->descriptionAttribute, parserData->tempVal) == false)
		osolerror(NULL, NULL, parserData, osglData, "setMinDiskSpace failed");
	parserData->errorText = NULL;
;}
    break;

  case 168:

    {	if (parserData->minMemoryPresent)
			osolerror(NULL, NULL, parserData, osglData, "only one minMemory element allowed");
		parserData->minMemoryPresent = true;
		parserData->unitAttributePresent = false;	
		parserData->descriptionAttributePresent = false;	
		parserData->unitAttribute = "byte";	
		parserData->descriptionAttribute = "";
	;}
    break;

  case 175:

    {
	if (osoption->setMinMemorySize(parserData->unitAttribute, parserData->descriptionAttribute, parserData->tempVal) == false)
		osolerror(NULL, NULL, parserData, osglData, "setMinMemorySize failed");
    parserData->errorText = NULL;
;}
    break;

  case 177:

    {	if (parserData->minCPUSpeedPresent)
			osolerror(NULL, NULL, parserData, osglData, "only one minCPUSpeed element allowed");
		parserData->minCPUSpeedPresent = true;
		parserData->unitAttributePresent = false;	
		parserData->descriptionAttributePresent = false;	
		parserData->unitAttribute = "hertz";	
		parserData->descriptionAttribute = "";
	;}
    break;

  case 184:

    {	
	if (osoption->setMinCPUSpeed(parserData->unitAttribute, parserData->descriptionAttribute, parserData->tempVal) == false)
		osolerror(NULL, NULL, parserData, osglData, "setMinCPUSpeed failed");
    parserData->errorText = NULL;
;}
    break;

  case 186:

    {	if (parserData->minCPUNumberPresent)
			osolerror(NULL, NULL, parserData, osglData, "only one minCPUNumber element allowed");
		parserData->minCPUNumberPresent = true;
		parserData->descriptionAttributePresent = false;	
		parserData->descriptionAttribute = "";	
	;}
    break;

  case 190:

    {
	if (osoption->setMinCPUNumber((yyvsp[(1) - (1)].ival), parserData->descriptionAttribute) == false)
		osolerror(NULL, NULL, parserData, osglData, "setMinCPUNumber failed");
	//free($1); 
	parserData->errorText = NULL; 
;}
    break;

  case 192:

    {	if (parserData->otherSystemOptionsPresent)
			osolerror(NULL, NULL, parserData, osglData, "only one <system> <other> element allowed");
		parserData->otherSystemOptionsPresent = true;
	;}
    break;

  case 193:

    {
	if (parserData->tempInt < 0) osolerror(NULL, NULL, parserData, osglData, "number of other system options cannot be negative");
	parserData->numberOf = parserData->tempInt;
	parserData->kounter = 0;
;}
    break;

  case 194:

    {	if (parserData->numberOf > 0)
			osolerror(NULL, NULL, parserData, osglData, "expected at least one <other> element");
	;}
    break;

  case 195:

    {	if (parserData->kounter < parserData->numberOf - 1)
			osolerror(NULL, NULL, parserData, osglData, "fewer <other> elements than specified");
	;}
    break;

  case 202:

    {
	parserData->kounter++;
	if (osoption->setAnOtherSystemOption(parserData->nameAttribute, parserData->valueAttribute, parserData->descriptionAttribute) == false)
		osolerror(NULL, NULL, parserData, osglData, "setOtherSystemOption failed");
;}
    break;

  case 203:

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

  case 204:

    {	if (!parserData->nameAttributePresent)
		osolerror (NULL, NULL, parserData, osglData, "<other> must have name attribute");
;}
    break;

  case 207:

    {
		if (parserData->nameAttribute.length() == 0)
			osolerror(NULL, NULL, parserData, osglData, "otherOption name cannot be empty");
	;}
    break;

  case 226:

    {	if (parserData->serviceTypePresent)
			osolerror(NULL, NULL, parserData, osglData, "only one currentState element allowed");
		parserData->serviceTypePresent = true;
	;}
    break;

  case 232:

    {
       parserData->tempStr = (yyvsp[(1) - (1)].sval); 
		//free($1);
		if (osoption->setServiceType(parserData->tempStr) == false)
			osolerror(NULL, NULL, parserData, osglData, "setServiceType failed; current system state not recognized");
		parserData->errorText = NULL;
	;}
    break;

  case 234:

    {	if (parserData->otherServiceOptionsPresent)
			osolerror(NULL, NULL, parserData, osglData, "only one <service> <other> element allowed");
		parserData->otherServiceOptionsPresent = true;
	;}
    break;

  case 235:

    {
	if (parserData->tempInt < 0) osolerror(NULL, NULL, parserData, osglData, "number of other service options cannot be negative");
	parserData->numberOf = parserData->tempInt;
	parserData->kounter = 0;
;}
    break;

  case 236:

    {	if (parserData->numberOf > 0)
			osolerror(NULL, NULL, parserData, osglData, "expected at least one <other> element");
	;}
    break;

  case 237:

    {	if (parserData->kounter < parserData->numberOf - 1)
			osolerror(NULL, NULL, parserData, osglData, "fewer <other> elements than specified");
	;}
    break;

  case 244:

    {	
	parserData->kounter++;
	if (osoption->setAnOtherServiceOption(parserData->nameAttribute, parserData->valueAttribute, parserData->descriptionAttribute) == false)
		osolerror(NULL, NULL, parserData, osglData, "setOtherServiceOption failed");
;}
    break;

  case 245:

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

  case 246:

    {	if (!parserData->nameAttributePresent)
		osolerror (NULL, NULL, parserData, osglData, "<other> must have name attribute");
;}
    break;

  case 249:

    {
		if (parserData->nameAttribute.length() == 0)
			osolerror(NULL, NULL, parserData, osglData, "otherOption name cannot be empty");
	;}
    break;

  case 280:

    {	
	if (osoption->setMaxTime(parserData->maxTimeValue, parserData->unitAttribute) == false)       
			osolerror(NULL, NULL, parserData, osglData, "max time request could not be honored");
;}
    break;

  case 281:

    {	
	if (parserData->maxTimePresent)
		osolerror( NULL, osoption, parserData, osglData, "only one <maxTime> element allowed");
	parserData->maxTimePresent = true;
	parserData->unitAttributePresent = false;	
	parserData->unitAttribute = "second"; 
	parserData->maxTimeValue = OSDBL_MAX;
;}
    break;

  case 289:

    {
	parserData->maxTimeValue = parserData->tempVal;
;}
    break;

  case 291:

    {	if (parserData->requestedStartTimePresent)
			osolerror(NULL, NULL, parserData, osglData, "only one requestedStartTime element allowed");
		parserData->requestedStartTimePresent = true;
	;}
    break;

  case 297:

    {
		if (osoption->setRequestedStartTime((yyvsp[(1) - (1)].sval)) == false)
			osolerror(NULL, NULL, parserData, osglData, "setRequestedStartTime failed");	
		//free($1); 
		parserData->errorText = NULL;
		;}
    break;

  case 299:

    {
	if (parserData->dependenciesPresent)
		osolerror( NULL, osoption, parserData, osglData, "only one <dependencies> element allowed");
	parserData->dependenciesPresent = true;
;}
    break;

  case 305:

    {
	if (parserData->kounter > parserData->numberOf)
		osolerror (NULL, osoption, parserData, osglData, "too few job IDs in <dependencies> element");
	if (osoption->setJobDependencies(parserData->numberOf, parserData->jobDependencies) == false)
		osolerror (NULL, osoption, parserData, osglData, "set <job> <dependencies> failed");
	delete[] parserData->jobDependencies;
	parserData->jobDependencies = NULL;
;}
    break;

  case 308:

    {
	if (parserData->kounter >= parserData->numberOf)
		osolerror (NULL, osoption, parserData, osglData, "too many job IDs in <dependencies> element");
	parserData->jobDependencies[parserData->kounter] = (yyvsp[(3) - (4)].sval);
	//free($3); 
	parserData->kounter++;
;}
    break;

  case 310:

    {	if (parserData->requiredDirectoriesPresent)
		osolerror( NULL, osoption, parserData, osglData, "only one <requiredDirectories> element allowed");
	parserData->requiredDirectoriesPresent = true;
;}
    break;

  case 316:

    {
	if (parserData->kounter > parserData->numberOf)
		osolerror (NULL, osoption, parserData, osglData, "too few job IDs in <requiredDirectories> element");
	if (osoption->setRequiredDirectories(parserData->numberOf,parserData->paths) == false)
		osolerror (NULL, osoption, parserData, osglData, "set <requiredDirectories> failed");
	delete[] parserData->paths;
	parserData->paths = NULL;
;}
    break;

  case 319:

    {
	if (parserData->kounter >= parserData->numberOf)
		osolerror (NULL, osoption, parserData, osglData, "too many ¨paths in <requiredDirectories> element");
	parserData->paths[parserData->kounter] = (yyvsp[(3) - (4)].sval);
	//free($3); 
	parserData->kounter++;
;}
    break;

  case 321:

    {	if (parserData->requiredFilesPresent)
		osolerror( NULL, osoption, parserData, osglData, "only one <requiredFiles> element allowed");
	parserData->requiredFilesPresent = true;
;}
    break;

  case 327:

    {
	if (parserData->kounter > parserData->numberOf)
		osolerror (NULL, osoption, parserData, osglData, "too few job IDs in <requiredFiles> element");
	if (osoption->setRequiredFiles(parserData->numberOf, parserData->paths) == false)
		osolerror (NULL, osoption, parserData, osglData, "set <requiredFiles> failed");
	delete[] parserData->paths;
	parserData->paths = NULL;
;}
    break;

  case 330:

    {
	if (parserData->kounter >= parserData->numberOf)
		osolerror (NULL, osoption, parserData, osglData, "too many ¨paths in <requiredFiles> element");
	parserData->paths[parserData->kounter] = (yyvsp[(3) - (4)].sval);
	//free($3);
	parserData->kounter++;
;}
    break;

  case 332:

    {	if (parserData->directoriesToMakePresent)
		osolerror( NULL, osoption, parserData, osglData, "only one <directoriesToMake> element allowed");
	parserData->directoriesToMakePresent = true;
;}
    break;

  case 338:

    {
	if (parserData->kounter > parserData->numberOf)
		osolerror (NULL, osoption, parserData, osglData, "too few job IDs in <directoriesToMake> element");
	if (osoption->setDirectoriesToMake(parserData->numberOf, parserData->paths) == false)
		osolerror (NULL, osoption, parserData, osglData, "set <directoriesToMake> failed");
	delete[] parserData->paths;
	parserData->paths = NULL;
;}
    break;

  case 341:

    {
	if (parserData->kounter >= parserData->numberOf)
		osolerror (NULL, osoption, parserData, osglData, "too many ¨paths in <directoriesToMake> element");
	parserData->paths[parserData->kounter] = (yyvsp[(3) - (4)].sval);
	//free($3); 
	parserData->kounter++;
;}
    break;

  case 343:

    {	if (parserData->filesToMakePresent)
		osolerror( NULL, osoption, parserData, osglData, "only one <filesToMake> element allowed");
	parserData->filesToMakePresent = true;
;}
    break;

  case 349:

    {
	if (parserData->kounter > parserData->numberOf)
		osolerror (NULL, osoption, parserData, osglData, "too few job IDs in <filesToMake> element");
	if (osoption->setFilesToMake(parserData->numberOf, parserData->paths) == false)
		osolerror (NULL, osoption, parserData, osglData, "set <filesToMake> failed");
	delete[] parserData->paths;
	parserData->paths = NULL;
;}
    break;

  case 352:

    {
	if (parserData->kounter >= parserData->numberOf)
		osolerror (NULL, osoption, parserData, osglData, "too many ¨paths in <filesToMake> element");
	parserData->paths[parserData->kounter] = (yyvsp[(3) - (4)].sval);
	//free($3); 
	parserData->kounter++;
;}
    break;

  case 354:

    {	if (parserData->inputDirectoriesToMovePresent)
		osolerror( NULL, osoption, parserData, osglData, "only one <inputDirectoriesToMove> element allowed");
		parserData->inputDirectoriesToMovePresent = true;
;}
    break;

  case 360:

    {
	if (parserData->kounter > parserData->numberOf)
		osolerror (NULL, osoption, parserData, osglData, "too few job IDs in <inputDirectoriesToMake> element");
	if (osoption->setPathPairs(ENUM_PATHPAIR_input_dir, parserData->fromPaths, 
			parserData->toPaths, parserData->makeCopy, parserData->numberOf) == false)
		osolerror (NULL, osoption, parserData, osglData, "set <inputDirectoriesToMake> failed");
	delete[] parserData->fromPaths;
	delete[] parserData->toPaths;
	delete[] parserData->makeCopy;
	parserData->fromPaths = NULL;
	parserData->toPaths   = NULL;
	parserData->makeCopy  = NULL;
;}
    break;

  case 365:

    {	if (parserData->inputFilesToMovePresent)
		osolerror( NULL, osoption, parserData, osglData, "only one <inputFilesToMove> element allowed");
		parserData->inputFilesToMovePresent = true;
;}
    break;

  case 371:

    {
	if (parserData->kounter > parserData->numberOf)
		osolerror (NULL, osoption, parserData, osglData, "too few job IDs in <inputFilesToMake> element");
	if (osoption->setPathPairs(ENUM_PATHPAIR_input_file, parserData->fromPaths, 
			parserData->toPaths, parserData->makeCopy, parserData->numberOf) == false)
		osolerror (NULL, osoption, parserData, osglData, "set <inputDirectoriesToMake> failed");
	delete[] parserData->fromPaths;
	delete[] parserData->toPaths;
	delete[] parserData->makeCopy;
	parserData->fromPaths = NULL;
	parserData->toPaths   = NULL;
	parserData->makeCopy  = NULL;
;}
    break;

  case 376:

    {	if (parserData->outputFilesToMovePresent)
		osolerror( NULL, osoption, parserData, osglData, "only one <outputFilesToMove> element allowed");
		parserData->outputFilesToMovePresent = true;
;}
    break;

  case 382:

    {
	if (parserData->kounter > parserData->numberOf)
		osolerror (NULL, osoption, parserData, osglData, "too few job IDs in <outputFilesToMake> element");
	if (osoption->setPathPairs(ENUM_PATHPAIR_output_file, parserData->fromPaths, 
			parserData->toPaths, parserData->makeCopy, parserData->numberOf) == false)
		osolerror (NULL, osoption, parserData, osglData, "set <inputDirectoriesToMake> failed");
	delete[] parserData->fromPaths;
	delete[] parserData->toPaths;
	delete[] parserData->makeCopy;
	parserData->fromPaths = NULL;
	parserData->toPaths   = NULL;
	parserData->makeCopy  = NULL;
;}
    break;

  case 387:

    {	if (parserData->outputDirectoriesToMovePresent)
		osolerror( NULL, osoption, parserData, osglData, "only one <outputDirectoriesToMove> element allowed");
		parserData->outputDirectoriesToMovePresent = true;
;}
    break;

  case 393:

    {
	if (parserData->kounter > parserData->numberOf)
		osolerror (NULL, osoption, parserData, osglData, "too few job IDs in <outputDirectoriesToMake> element");
	if (osoption->setPathPairs(ENUM_PATHPAIR_output_dir, parserData->fromPaths, 
			parserData->toPaths, parserData->makeCopy, parserData->numberOf) == false)
		osolerror (NULL, osoption, parserData, osglData, "set <inputDirectoriesToMake> failed");
	delete[] parserData->fromPaths;
	delete[] parserData->toPaths;
	delete[] parserData->makeCopy;
	parserData->fromPaths = NULL;
	parserData->toPaths   = NULL;
	parserData->makeCopy  = NULL;
;}
    break;

  case 398:

    {	if (parserData->filesToDeletePresent)
		osolerror( NULL, osoption, parserData, osglData, "only one <filesToDelete> element allowed");
	parserData->filesToDeletePresent = true;
;}
    break;

  case 404:

    {
	if (parserData->kounter > parserData->numberOf)
		osolerror (NULL, osoption, parserData, osglData, "too few job IDs in <filesToDelete> element");
	if (osoption->setFilesToDelete(parserData->numberOf, parserData->paths) == false)
		osolerror (NULL, osoption, parserData, osglData, "set <filesToDelete> failed");
	delete[] parserData->paths;
	parserData->paths = NULL;
;}
    break;

  case 407:

    {
	if (parserData->kounter >= parserData->numberOf)
		osolerror (NULL, osoption, parserData, osglData, "too many ¨paths in <filesToDelete> element");
	parserData->paths[parserData->kounter] = (yyvsp[(3) - (4)].sval);
	//free($3); 
	parserData->kounter++;
;}
    break;

  case 409:

    {	if (parserData->directoriesToDeletePresent)
		osolerror( NULL, osoption, parserData, osglData, "only one <directoriesToDelete> element allowed");
	parserData->directoriesToDeletePresent = true;
;}
    break;

  case 415:

    {
	if (parserData->kounter > parserData->numberOf)
		osolerror (NULL, osoption, parserData, osglData, "too few job IDs in <directoriesToDelete> element");
	if (osoption->setDirectoriesToDelete(parserData->numberOf, parserData->paths) == false)
		osolerror (NULL, osoption, parserData, osglData, "set <directoriesToDelete> failed");
	delete[] parserData->paths;
	parserData->paths = NULL;
;}
    break;

  case 418:

    {
	if (parserData->kounter >= parserData->numberOf)
		osolerror (NULL, osoption, parserData, osglData, "too many ¨paths in <directoriesToDelete> element");
	parserData->paths[parserData->kounter] = (yyvsp[(3) - (4)].sval);
	//free($3); 
	parserData->kounter++;
;}
    break;

  case 420:

    {
	if (parserData->processesToKillPresent)
		osolerror( NULL, osoption, parserData, osglData, "only one <processesToKill> element allowed");
	parserData->processesToKillPresent = true;
;}
    break;

  case 426:

    {
	if (parserData->kounter > parserData->numberOf)
		osolerror (NULL, osoption, parserData, osglData, "too few job IDs in <processesToKill> element");
	if (osoption->setProcessesToKill(parserData->numberOf, parserData->processesToKill) == false)
		osolerror (NULL, osoption, parserData, osglData, "set <processesToKill> failed");
	delete[] parserData->processesToKill;
	parserData->processesToKill = NULL;
;}
    break;

  case 429:

    {
	if (parserData->kounter >= parserData->numberOf)
		osolerror (NULL, osoption, parserData, osglData, "too many job IDs in <processesToKill> element");
	parserData->processesToKill[parserData->kounter] = (yyvsp[(3) - (4)].sval);
	//free($3); 
	parserData->kounter++;
;}
    break;

  case 431:

    {	if (parserData->otherJobOptionsPresent)
			osolerror(NULL, NULL, parserData, osglData, "only one <job> <other> element allowed");
		parserData->otherJobOptionsPresent = true;
	;}
    break;

  case 432:

    {
	if (parserData->tempInt < 0) osolerror(NULL, NULL, parserData, osglData, "number of other job options cannot be negative");
	parserData->numberOf = parserData->tempInt;
	parserData->kounter = 0;
;}
    break;

  case 433:

    {	if (parserData->numberOf > 0)
			osolerror(NULL, NULL, parserData, osglData, "expected at least one <other> element");
	;}
    break;

  case 434:

    {	if (parserData->kounter < parserData->numberOf - 1)
			osolerror(NULL, NULL, parserData, osglData, "fewer <other> elements than specified");
	;}
    break;

  case 441:

    {
	parserData->kounter++;
	if (osoption->setAnOtherJobOption(parserData->nameAttribute, parserData->valueAttribute, parserData->descriptionAttribute) == false)
		osolerror(NULL, NULL, parserData, osglData, "setOtherJobOption failed");
;}
    break;

  case 442:

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

  case 443:

    {	if (!parserData->nameAttributePresent)
		osolerror (NULL, NULL, parserData, osglData, "<other> must have name attribute");
;}
    break;

  case 446:

    {
		if (parserData->nameAttribute.length() == 0)
			osolerror(NULL, NULL, parserData, osglData, "otherOption name cannot be empty");
	;}
    break;

  case 453:

    {
	if (parserData->osoloptimizationPresent)
		osolerror( NULL, osoption, parserData, osglData, "only one <optimization> element allowed");
	parserData->osoloptimizationPresent = true;
	osoption->optimization = new OptimizationOption();
	parserData->numberOfVariablesPresent = false;
	parserData->numberOfObjectivesPresent = false;
	parserData->numberOfConstraintsPresent = false;
;}
    break;

  case 457:

    {	
		parserData->numberOfVariables = parserData->tempInt; 
		if (osoption->setNumberOfVariables(parserData->tempInt) == false)
			osolerror(NULL, NULL, parserData, osglData, "setNumberOfVariables failed");
	;}
    break;

  case 458:

    {
		parserData->numberOfConstraints = parserData->tempInt; 
		if (osoption->setNumberOfConstraints(parserData->tempInt) == false)
			osolerror(NULL, NULL, parserData, osglData, "setNumberOfConstraints failed");
	;}
    break;

  case 459:

    {	
		parserData->numberOfObjectives = parserData->tempInt; 
		if (osoption->setNumberOfObjectives(parserData->tempInt) == false)
			osolerror(NULL, NULL, parserData, osglData, "setNumberOfObjectives failed");
	;}
    break;

  case 467:

    {
	parserData->numberOfOtherVariableOptions = 0;
;}
    break;

  case 468:

    {	
	if (osoption->setNumberOfOtherVariableOptions(parserData->numberOfOtherVariableOptions) == false)
		osolerror(NULL, NULL, parserData, osglData, "setNumberOfOtherVariableOptions failed");
	parserData->iOther = 0;
;}
    break;

  case 470:

    {	
	parserData->numberOfOtherVariableOptions = parserData->tempInt;
;}
    break;

  case 478:

    {
	parserData->numberOfVarAttributePresent = false;
;}
    break;

  case 479:

    {
	parserData->kounter = 0;
	parserData->idxArray = new    int[parserData->numberOfVar];
	parserData->valArray = new double[parserData->numberOfVar];
;}
    break;

  case 480:

    {
		if (parserData->numberOfVar > 0)
			osolerror(NULL, NULL, parserData, osglData, "expected at least one <var> element");
	;}
    break;

  case 481:

    {
		if (parserData->kounter > parserData->numberOfVar)
			osolerror (NULL, osoption, parserData, osglData, "too few initial values in <initialVariableValues> element");
		if (osoption->setInitVarValues(parserData->numberOfVar, parserData->idxArray, parserData->valArray) == false)
			osolerror (NULL, osoption, parserData, osglData, "set <initialVariableValues> failed");
		delete[] parserData->idxArray;
		delete[] parserData->valArray;
		parserData->idxArray = NULL;
		parserData->valArray = NULL;
	;}
    break;

  case 488:

    {
	parserData->kounter++;
;}
    break;

  case 489:

    {	
	if (parserData->kounter >= parserData->numberOfVar)
		osolerror(NULL, NULL, parserData, osglData, "more <var> elements than specified");
	parserData->idxAttributePresent = false;
	parserData->valueAttributePresent = false;
;}
    break;

  case 492:

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

  case 493:

    {
		if (parserData->valueAttribute == "")
			osolerror (NULL, osoption, parserData, osglData, "expected an integer or floating point value");
		parserData->valArray[parserData->kounter] = os_strtod((parserData->valueAttribute).c_str(), NULL);
	;}
    break;

  case 498:

    {
	parserData->numberOfVarAttributePresent = false;
;}
    break;

  case 499:

    {
	parserData->kounter = 0;
	parserData->idxArray = new int[parserData->numberOfVar];
	parserData->valueString = new std::string[parserData->numberOfVar];
;}
    break;

  case 500:

    {
		if (parserData->numberOfVar > 0)
			osolerror(NULL, NULL, parserData, osglData, "expected at least one <var> element");
	;}
    break;

  case 501:

    {
		if (parserData->kounter != parserData->numberOfVar)
			osolerror(NULL, NULL, parserData, osglData, "fewer <var> elements than specified");
		if (osoption->setInitVarValuesString(parserData->numberOfVar, parserData->idxArray, parserData->valueString) == false)
			osolerror (NULL, osoption, parserData, osglData, "set <initialVariableValuesString> failed");
		delete[] parserData->idxArray;
		delete[] parserData->valueString;
		parserData->idxArray = NULL;
		parserData->valueString = NULL;
	;}
    break;

  case 508:

    {
	parserData->kounter++;
;}
    break;

  case 509:

    {	
	if (parserData->kounter >= parserData->numberOfVar)
		osolerror(NULL, NULL, parserData, osglData, "more <var> elements than specified");
	parserData->idxAttributePresent = false;
	parserData->valueAttributePresent = false;
	parserData->valueAttribute = "48r 87e WY EUV e7 df"; //random string...
;}
    break;

  case 510:

    {
	parserData->idxArray[parserData->kounter] = parserData->idxAttribute;
	parserData->valueString[parserData->kounter] = parserData->valueAttribute;
;}
    break;

  case 513:

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

  case 526:

    {
	if (osoption->setInitBasisStatus(ENUM_PROBLEM_COMPONENT_variables, ENUM_BASIS_STATUS_basic, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
		osolerror(NULL, NULL, parserData, osglData, "set variables basic failed");	
	delete[] osglData->osglIntArray;
	osglData->osglIntArray = NULL;
;}
    break;

  case 527:

    {
	osglData->osglNumberOfEl = 0;
	osglData->osglNumberOfElPresent= false;
;}
    break;

  case 528:

    {
	osglData->osglCounter = 0; 
	osglData->osglNumberOfEl = parserData->numberOf;
	osglData->osglIntArray = new int[parserData->numberOf];
;}
    break;

  case 535:

    {
	if (osoption->setInitBasisStatus(ENUM_PROBLEM_COMPONENT_variables, ENUM_BASIS_STATUS_atLower, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
		osolerror(NULL, NULL, parserData, osglData, "set variables atLower failed");	
	delete[] osglData->osglIntArray;
	osglData->osglIntArray = NULL;
;}
    break;

  case 536:

    {
	osglData->osglNumberOfEl = 0;
	osglData->osglNumberOfElPresent= false;
;}
    break;

  case 537:

    {
	osglData->osglCounter = 0; 
	osglData->osglNumberOfEl = parserData->numberOf;
	osglData->osglIntArray = new int[parserData->numberOf];
;}
    break;

  case 544:

    {
	if (osoption->setInitBasisStatus(ENUM_PROBLEM_COMPONENT_variables, ENUM_BASIS_STATUS_atUpper, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
		osolerror(NULL, NULL, parserData, osglData, "set variables atUpper failed");	
	delete[] osglData->osglIntArray;
	osglData->osglIntArray = NULL;
;}
    break;

  case 545:

    {
	osglData->osglNumberOfEl = 0;
	osglData->osglNumberOfElPresent= false;
;}
    break;

  case 546:

    {
	osglData->osglCounter = 0; 
	osglData->osglNumberOfEl = parserData->numberOf;
	osglData->osglIntArray = new int[parserData->numberOf];
;}
    break;

  case 553:

    {
	if (osoption->setInitBasisStatus(ENUM_PROBLEM_COMPONENT_variables, ENUM_BASIS_STATUS_isFree, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
		osolerror(NULL, NULL, parserData, osglData, "set variables isFree failed");	
	delete[] osglData->osglIntArray;
	osglData->osglIntArray = NULL;
;}
    break;

  case 554:

    {
	osglData->osglNumberOfEl = 0;
	osglData->osglNumberOfElPresent= false;
;}
    break;

  case 555:

    {
	osglData->osglCounter = 0; 
	osglData->osglNumberOfEl = parserData->numberOf;
	osglData->osglIntArray = new int[parserData->numberOf];
;}
    break;

  case 562:

    {
	if (osoption->setInitBasisStatus(ENUM_PROBLEM_COMPONENT_variables, ENUM_BASIS_STATUS_superbasic, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
		osolerror(NULL, NULL, parserData, osglData, "set variables superbasic failed");	
	delete[] osglData->osglIntArray;
	osglData->osglIntArray = NULL;
;}
    break;

  case 563:

    {
	osglData->osglNumberOfEl = 0;
	osglData->osglNumberOfElPresent= false;
;}
    break;

  case 564:

    {
	osglData->osglCounter = 0; 
	osglData->osglNumberOfEl = parserData->numberOf;
	osglData->osglIntArray = new int[parserData->numberOf];
;}
    break;

  case 571:

    {
	if (osoption->setInitBasisStatus(ENUM_PROBLEM_COMPONENT_variables, ENUM_BASIS_STATUS_unknown, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
		osolerror(NULL, NULL, parserData, osglData, "set variables unknown failed");	
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

  case 581:

    {
	parserData->numberOfVarAttributePresent = false;
;}
    break;

  case 582:

    {
	parserData->kounter = 0;
	parserData->idxArray = new    int[parserData->numberOfVar];
	parserData->valArray = new double[parserData->numberOfVar];
;}
    break;

  case 583:

    {
		if (parserData->numberOfVar > 0)
			osolerror(NULL, NULL, parserData, osglData, "expected at least one <var> element");
	;}
    break;

  case 584:

    {
		if (parserData->kounter != parserData->numberOfVar)
			osolerror(NULL, NULL, parserData, osglData, "fewer <var> elements than specified");
		if (osoption->setIntegerVariableBranchingWeights(parserData->numberOfVar, parserData->idxArray, parserData->valArray) == false)
			osolerror (NULL, osoption, parserData, osglData, "set <initialVariableValues> failed");
		delete[] parserData->idxArray;
		delete[] parserData->valArray;
		parserData->idxArray = NULL;
		parserData->valArray = NULL;
	;}
    break;

  case 591:

    {
	parserData->kounter++;
;}
    break;

  case 592:

    {	
	if (parserData->kounter >= parserData->numberOfVar)
		osolerror(NULL, NULL, parserData, osglData, "more <var> elements than specified");
	parserData->idxAttributePresent = false;
	parserData->valueAttributePresent = false;
	parserData->valueAttribute = "1.0";
;}
    break;

  case 593:

    {
	parserData->idxArray[parserData->kounter] = parserData->idxAttribute;
	parserData->valArray[parserData->kounter] = os_strtod((parserData->valueAttribute).c_str(), NULL);
;}
    break;

  case 596:

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

  case 597:

    {
		if (parserData->valueAttribute == "")
			osolerror (NULL, osoption, parserData, osglData, "expected an integer or floating point value");
	;}
    break;

  case 602:

    {
	parserData->sosIdxAttributePresent = false;	
	parserData->currentSOS = 0;
;}
    break;

  case 603:

    {
	if ((yyvsp[(3) - (4)].ival) < 0)
		osolerror (NULL, osoption, parserData, osglData, "number of <sos> elements must be nonnegative");
	parserData->numberOfSOS = (yyvsp[(3) - (4)].ival);
;}
    break;

  case 604:

    {	if (parserData->numberOfSOS > 0)
			osolerror(NULL, NULL, parserData, osglData, "expected at least one <sos> element");
	;}
    break;

  case 605:

    {	if (parserData->currentSOS != parserData->numberOfSOS)
			osolerror(NULL, NULL, parserData, osglData, "fewer <sos> elements than specified");
	;}
    break;

  case 611:

    {
	if (!osoption->setAnotherSOSVariableBranchingWeight(parserData->sosIdx, 
				parserData->numberOfVar, parserData->groupWeight,
				parserData->idxArray,	 parserData->valArray) )
		osolerror (NULL, osoption, parserData, osglData, "error processing SOS branching weights");
	parserData->currentSOS++;
;}
    break;

  case 612:

    {	if (parserData->currentSOS >= parserData->numberOfSOS)
		osolerror(NULL, osoption, parserData, osglData, "too many SOS branching weights");
	parserData->sosIdxAttributePresent = false;
	parserData->groupWeightAttributePresent = false;
	parserData->numberOfVarAttributePresent = false;
	parserData->groupWeight = 1.0;
	parserData->numberOfSOSVar = 0;
;}
    break;

  case 613:

    {
	if (!parserData->sosIdxAttributePresent)
		osolerror (NULL, osoption, parserData, osglData, "SOS index required");
	if (!parserData->numberOfVarAttributePresent)
		osolerror (NULL, osoption, parserData, osglData, "numberOfVar required");
;}
    break;

  case 617:

    {
		parserData->kounter = 0;
		parserData->idxArray = new    int[parserData->numberOfVar];
		parserData->valArray = new double[parserData->numberOfVar];
		parserData->numberOfVarAttributePresent = true;
	;}
    break;

  case 626:

    { 	 
		parserData->iOther++;
	;}
    break;

  case 627:

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

  case 628:

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

  case 631:

    {
		parserData->kounter = 0;
	;}
    break;

  case 632:

    {
		parserData->kounter = 0;
	;}
    break;

  case 648:

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

  case 649:

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

  case 653:

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

  case 662:

    {	parserData->numberOfOtherObjectiveOptions = 0; ;}
    break;

  case 663:

    {	
	if (osoption->setNumberOfOtherObjectiveOptions(parserData->numberOfOtherObjectiveOptions) == false)
		osolerror(NULL, NULL, parserData, osglData, "setNumberOfOtherVariableOptions failed");
	parserData->iOther = 0;
;}
    break;

  case 665:

    {	
	parserData->numberOfOtherObjectiveOptions = parserData->tempInt;
;}
    break;

  case 673:

    {
	parserData->numberOfObjAttributePresent = false;
;}
    break;

  case 674:

    {
	parserData->kounter = 0;
	parserData->idxArray = new    int[parserData->numberOfObj];
	parserData->valArray = new double[parserData->numberOfObj];
;}
    break;

  case 675:

    {	
		if (parserData->numberOfObj > 0)
			osolerror(NULL, NULL, parserData, osglData, "expected at least one <obj> element");
	;}
    break;

  case 676:

    {
		if (parserData->kounter != parserData->numberOfObj)
			osolerror(NULL, NULL, parserData, osglData, "fewer <obj> elements than specified");
		if (osoption->setInitObjValues(parserData->numberOfObj, parserData->idxArray, parserData->valArray) == false)
			osolerror (NULL, osoption, parserData, osglData, "set <initialObjectiveValues> failed");
		delete[] parserData->idxArray;
		delete[] parserData->valArray;
		parserData->idxArray = NULL;
		parserData->valArray = NULL;
	;}
    break;

  case 683:

    {
	parserData->kounter++;
;}
    break;

  case 684:

    {	
	if (parserData->kounter >= parserData->numberOfObj)
		osolerror(NULL, NULL, parserData, osglData, "more <obj> elements than specified");
	parserData->idxAttributePresent = false;
	parserData->valueAttributePresent = false;
	parserData->idxAttribute = -1;
;}
    break;

  case 685:

    {	
	parserData->idxArray[parserData->kounter] = parserData->idxAttribute;
;}
    break;

  case 688:

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

  case 689:

    {
		if (parserData->valueAttribute == "")
			osolerror (NULL, osoption, parserData, osglData, "expected an integer or floating point value");
		parserData->valArray[parserData->kounter] = os_strtod((parserData->valueAttribute).c_str(), NULL);
	;}
    break;

  case 694:

    {
	parserData->numberOfObjAttributePresent = false;
;}
    break;

  case 695:

    {
	parserData->kounter = 0;
	parserData->idxArray   = new    int[parserData->numberOfObj];
	parserData->lbValArray = new double[parserData->numberOfObj];
	parserData->ubValArray = new double[parserData->numberOfObj];
;}
    break;

  case 696:

    {
		if (parserData->numberOfObj > 0)
			osolerror(NULL, NULL, parserData, osglData, "expected at least one <obj> element");
	;}
    break;

  case 697:

    {
		if (parserData->kounter != parserData->numberOfObj)
			osolerror(NULL, NULL, parserData, osglData, "fewer <obj> elements than specified");
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

  case 704:

    {
	parserData->kounter++;
;}
    break;

  case 705:

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

  case 706:

    {	
	parserData->idxArray[parserData->kounter] = parserData->idxAttribute;
	parserData->lbValArray[parserData->kounter] = os_strtod((parserData->lbValueAttribute).c_str(), NULL);
	parserData->ubValArray[parserData->kounter] = os_strtod((parserData->ubValueAttribute).c_str(), NULL);
;}
    break;

  case 709:

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

  case 710:

    {
		if (parserData->lbValueAttribute == "")
			osolerror (NULL, osoption, parserData, osglData, "expected an integer or floating point value");
	;}
    break;

  case 711:

    {
		if (parserData->ubValueAttribute == "")
			osolerror (NULL, osoption, parserData, osglData, "expected an integer or floating point value");
	;}
    break;

  case 723:

    {
	if (osoption->setInitBasisStatus(ENUM_PROBLEM_COMPONENT_objectives, ENUM_BASIS_STATUS_basic, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
		osolerror(NULL, NULL, parserData, osglData, "set objectives basic failed");	
	delete[] osglData->osglIntArray;
	osglData->osglIntArray = NULL;
;}
    break;

  case 724:

    {
	osglData->osglNumberOfEl = 0;
	osglData->osglNumberOfElPresent= false;
;}
    break;

  case 725:

    {
	osglData->osglCounter = 0; 
	osglData->osglNumberOfEl = parserData->numberOf;
	osglData->osglIntArray = new int[parserData->numberOf];
;}
    break;

  case 732:

    {
	if (osoption->setInitBasisStatus(ENUM_PROBLEM_COMPONENT_objectives, ENUM_BASIS_STATUS_atLower, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
		osolerror(NULL, NULL, parserData, osglData, "set objectives atLower failed");	
	delete[] osglData->osglIntArray;
	osglData->osglIntArray = NULL;
;}
    break;

  case 733:

    {
	osglData->osglNumberOfEl = 0;
	osglData->osglNumberOfElPresent= false;
;}
    break;

  case 734:

    {
	osglData->osglCounter = 0; 
	osglData->osglNumberOfEl = parserData->numberOf;
	osglData->osglIntArray = new int[parserData->numberOf];
;}
    break;

  case 741:

    {
	if (osoption->setInitBasisStatus(ENUM_PROBLEM_COMPONENT_objectives, ENUM_BASIS_STATUS_atUpper, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
		osolerror(NULL, NULL, parserData, osglData, "set objectives atUpper failed");	
	delete[] osglData->osglIntArray;
	osglData->osglIntArray = NULL;
;}
    break;

  case 742:

    {
	osglData->osglNumberOfEl = 0;
	osglData->osglNumberOfElPresent= false;
;}
    break;

  case 743:

    {
	osglData->osglCounter = 0; 
	osglData->osglNumberOfEl = parserData->numberOf;
	osglData->osglIntArray = new int[parserData->numberOf];
;}
    break;

  case 750:

    {
	if (osoption->setInitBasisStatus(ENUM_PROBLEM_COMPONENT_objectives, ENUM_BASIS_STATUS_isFree, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
		osolerror(NULL, NULL, parserData, osglData, "set objectives isFree failed");	
	delete[] osglData->osglIntArray;
	osglData->osglIntArray = NULL;
;}
    break;

  case 751:

    {
	osglData->osglNumberOfEl = 0;
	osglData->osglNumberOfElPresent= false;
;}
    break;

  case 752:

    {
	osglData->osglCounter = 0; 
	osglData->osglNumberOfEl = parserData->numberOf;
	osglData->osglIntArray = new int[parserData->numberOf];
;}
    break;

  case 759:

    {
	if (osoption->setInitBasisStatus(ENUM_PROBLEM_COMPONENT_objectives, ENUM_BASIS_STATUS_superbasic, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
		osolerror(NULL, NULL, parserData, osglData, "set objectives superbasic failed");	
	delete[] osglData->osglIntArray;
	osglData->osglIntArray = NULL;
;}
    break;

  case 760:

    {
	osglData->osglNumberOfEl = 0;
	osglData->osglNumberOfElPresent= false;
;}
    break;

  case 761:

    {
	osglData->osglCounter = 0; 
	osglData->osglNumberOfEl = parserData->numberOf;
	osglData->osglIntArray = new int[parserData->numberOf];
;}
    break;

  case 768:

    {
	if (osoption->setInitBasisStatus(ENUM_PROBLEM_COMPONENT_objectives, ENUM_BASIS_STATUS_unknown, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
		osolerror(NULL, NULL, parserData, osglData, "set objectives unknown failed");	
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

  case 778:

    { 	 
		parserData->iOther++;  
	;}
    break;

  case 779:

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

  case 780:

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

  case 783:

    {
		parserData->kounter = 0;
	;}
    break;

  case 784:

    {
		parserData->kounter = 0;
	;}
    break;

  case 800:

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

  case 801:

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

  case 802:

    {	
	parserData->idxArray[parserData->kounter] = parserData->idxAttribute;
	parserData->valueString[parserData->kounter] = parserData->valueAttribute;
	parserData->lbValueString[parserData->kounter] = parserData->lbValueAttribute;
	parserData->ubValueString[parserData->kounter] = parserData->ubValueAttribute;
;}
    break;

  case 805:

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

  case 814:

    {
	parserData->numberOfOtherConstraintOptions = 0; 
;}
    break;

  case 815:

    {	
	if (osoption->setNumberOfOtherConstraintOptions(parserData->numberOfOtherConstraintOptions) == false)
		osolerror(NULL, NULL, parserData, osglData, "setNumberOfOtherConstraintOptions failed");
	parserData->iOther = 0;
;}
    break;

  case 817:

    {	
	parserData->numberOfOtherConstraintOptions = parserData->tempInt;
;}
    break;

  case 825:

    {
	parserData->numberOfConAttributePresent = false;
;}
    break;

  case 826:

    {
	parserData->kounter = 0;
	parserData->idxArray = new    int[parserData->numberOfCon];
	parserData->valArray = new double[parserData->numberOfCon];
;}
    break;

  case 827:

    {
		if (parserData->numberOfCon > 0)
			osolerror(NULL, NULL, parserData, osglData, "expected at least one <con element");
	;}
    break;

  case 828:

    {
		if (parserData->kounter > parserData->numberOfCon)
			osolerror(NULL, NULL, parserData, osglData, "fewer <con> elements than specified");
		if (osoption->setInitConValues(parserData->numberOfCon, parserData->idxArray, parserData->valArray) == false)
			osolerror (NULL, osoption, parserData, osglData, "set <initialConstraintValues> failed");
		delete[] parserData->idxArray;
		delete[] parserData->valArray;
		parserData->idxArray = NULL;
		parserData->valArray = NULL;
	;}
    break;

  case 835:

    {
	parserData->kounter++;
;}
    break;

  case 836:

    {	
	if (parserData->kounter >= parserData->numberOfCon)
		osolerror(NULL, NULL, parserData, osglData, "more <con> elements than specified");
	parserData->idxAttributePresent = false;
	parserData->valueAttributePresent = false;
;}
    break;

  case 839:

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

  case 840:

    {
		if (parserData->valueAttribute == "")
			osolerror (NULL, osoption, parserData, osglData, "expected an integer or floating point value");
		parserData->valArray[parserData->kounter] = os_strtod((parserData->valueAttribute).c_str(), NULL);
	;}
    break;

  case 845:

    {
	parserData->numberOfConAttributePresent = false;
;}
    break;

  case 846:

    {
	parserData->kounter = 0;
	parserData->idxArray   = new    int[parserData->numberOfCon];
	parserData->lbValArray = new double[parserData->numberOfCon];
	parserData->ubValArray = new double[parserData->numberOfCon];
;}
    break;

  case 847:

    {
		if (parserData->numberOfCon > 0)
			osolerror(NULL, NULL, parserData, osglData, "expected at least one <con> element");
	;}
    break;

  case 848:

    {
		if (parserData->kounter != parserData->numberOfCon)
			osolerror(NULL, NULL, parserData, osglData, "fewer <con> elements than specified");
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

  case 855:

    {	
	parserData->kounter++;
;}
    break;

  case 856:

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

  case 857:

    {
	parserData->lbValArray[parserData->kounter] = parserData->lbDualValue;
	parserData->ubValArray[parserData->kounter] = parserData->ubDualValue;
;}
    break;

  case 860:

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

  case 874:

    {
	if (osoption->setInitBasisStatus(ENUM_PROBLEM_COMPONENT_constraints, ENUM_BASIS_STATUS_basic, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
		osolerror(NULL, NULL, parserData, osglData, "set slacks basic failed");	
	delete[] osglData->osglIntArray;
	osglData->osglIntArray = NULL;
;}
    break;

  case 875:

    {
	osglData->osglNumberOfEl = 0;
	osglData->osglNumberOfElPresent= false;
;}
    break;

  case 876:

    {
	osglData->osglCounter = 0; 
	osglData->osglNumberOfEl = parserData->numberOf;
	osglData->osglIntArray = new int[parserData->numberOf];
;}
    break;

  case 883:

    {
	if (osoption->setInitBasisStatus(ENUM_PROBLEM_COMPONENT_constraints, ENUM_BASIS_STATUS_atLower, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
		osolerror(NULL, NULL, parserData, osglData, "set slacks atLower failed");	
	delete[] osglData->osglIntArray;
	osglData->osglIntArray = NULL;
;}
    break;

  case 884:

    {
	osglData->osglNumberOfEl = 0;
	osglData->osglNumberOfElPresent= false;
;}
    break;

  case 885:

    {
	osglData->osglCounter = 0; 
	osglData->osglNumberOfEl = parserData->numberOf;
	osglData->osglIntArray = new int[parserData->numberOf];
;}
    break;

  case 892:

    {
	if (osoption->setInitBasisStatus(ENUM_PROBLEM_COMPONENT_constraints, ENUM_BASIS_STATUS_atUpper, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
		osolerror(NULL, NULL, parserData, osglData, "set slacks atUpper failed");	
	delete[] osglData->osglIntArray;
	osglData->osglIntArray = NULL;
;}
    break;

  case 893:

    {
	osglData->osglNumberOfEl = 0;
	osglData->osglNumberOfElPresent= false;
;}
    break;

  case 894:

    {
	osglData->osglCounter = 0; 
	osglData->osglNumberOfEl = parserData->numberOf;
	osglData->osglIntArray = new int[parserData->numberOf];
;}
    break;

  case 901:

    {
	if (osoption->setInitBasisStatus(ENUM_PROBLEM_COMPONENT_constraints, ENUM_BASIS_STATUS_isFree, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
		osolerror(NULL, NULL, parserData, osglData, "set slacks isFree failed");	
	delete[] osglData->osglIntArray;
	osglData->osglIntArray = NULL;
;}
    break;

  case 902:

    {
	osglData->osglNumberOfEl = 0;
	osglData->osglNumberOfElPresent= false;
;}
    break;

  case 903:

    {
	osglData->osglCounter = 0; 
	osglData->osglNumberOfEl = parserData->numberOf;
	osglData->osglIntArray = new int[parserData->numberOf];
;}
    break;

  case 910:

    {
	if (osoption->setInitBasisStatus(ENUM_PROBLEM_COMPONENT_constraints, ENUM_BASIS_STATUS_superbasic, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
		osolerror(NULL, NULL, parserData, osglData, "set variables superbasic failed");	
	delete[] osglData->osglIntArray;
	osglData->osglIntArray = NULL;
;}
    break;

  case 911:

    {
	osglData->osglNumberOfEl = 0;
	osglData->osglNumberOfElPresent= false;
;}
    break;

  case 912:

    {
	osglData->osglCounter = 0; 
	osglData->osglNumberOfEl = parserData->numberOf;
	osglData->osglIntArray = new int[parserData->numberOf];
;}
    break;

  case 919:

    {
	if (osoption->setInitBasisStatus(ENUM_PROBLEM_COMPONENT_constraints, ENUM_BASIS_STATUS_unknown, osglData->osglIntArray, osglData->osglNumberOfEl) != true)
		osolerror(NULL, NULL, parserData, osglData, "set slacks unknown failed");	
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

  case 929:

    { 	 
		parserData->iOther++;  
	;}
    break;

  case 930:

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

  case 931:

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

  case 934:

    {
		parserData->kounter = 0;
	;}
    break;

  case 935:

    {
		parserData->kounter = 0;
	;}
    break;

  case 951:

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

  case 952:

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

  case 956:

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

  case 965:

    {
	if (parserData->solverOptionsPresent)
		osolerror( NULL, osoption, parserData, osglData, "only one <solverOptions> element allowed");
	else
		parserData->solverOptionsPresent = true;
;}
    break;

  case 966:

    {
	if (!osoption->setNumberOfSolverOptions(parserData->numberOfSolverOptions) )
		osolerror( NULL, osoption, parserData, osglData, "setNumberOfSolverOptions failed");
	parserData->iOption = 0;
;}
    break;

  case 967:

    {
		if (parserData->numberOfSolverOptions > 0)
			osolerror(NULL, NULL, parserData, osglData, "expected at least one <solverOption> element");
	;}
    break;

  case 968:

    {
		if (parserData->iOption != parserData->numberOfSolverOptions)
			osolerror(NULL, NULL, parserData, osglData, "fewer <solverOption> elements than specified");
	;}
    break;

  case 973:

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

  case 974:

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

  case 975:

    {
	if (!parserData->nameAttributePresent)
		osolerror (NULL, osoption, parserData, osglData, "name attribute must be present");
;}
    break;

  case 984:

    {
			parserData->itemList = new std::string[parserData->numberOfItems];
    ;}
    break;

  case 985:

    {	if (parserData->numberOfItems > 0)
			osolerror(NULL, NULL, parserData, osglData, "expected at least one <item> element");
	;}
    break;

  case 986:

    {	if (parserData->kounter != parserData->numberOfItems)
			osolerror(NULL, NULL, parserData, osglData, "fewer <item> elements than specified");
	;}
    break;

  case 993:

    {	
	parserData->itemList[parserData->kounter] = parserData->itemContent;
	parserData->kounter++;
;}
    break;

  case 994:

    {
		if (parserData->kounter >= parserData->numberOfItems)
			osolerror(NULL, NULL, parserData, osglData, "more <item> elements than specified");
		parserData->itemContent = "";			
	;}
    break;

  case 999:

    {
	if (parserData->kounter >= parserData->numberOfItems)
		osolerror(NULL, NULL, parserData, osglData, "more <item> elements than specified");
	parserData->itemContent = (yyvsp[(1) - (1)].sval); 
;}
    break;

  case 1000:

    {	
	if (!parserData->pathPairFromPresent)
		osolerror (NULL, osoption, parserData, osglData, "\"from\" attribute must be present");
	if (!parserData->pathPairToPresent)
		osolerror (NULL, osoption, parserData, osglData, "\"to\" attribute must be present");
	parserData->kounter++;
;}
    break;

  case 1001:

    {
	if (parserData->kounter >= parserData->numberOfPathPairs)
		osolerror (NULL, osoption, parserData, osglData, "too many path pairs");
	parserData->pathPairFromPresent = false;
	parserData->pathPairToPresent = false;
	parserData->pathPairMakeCopyPresent = false;
	parserData->pathPairMakeCopy = false;
;}
    break;

  case 1002:

    {
	parserData->makeCopy[parserData->kounter] = parserData->pathPairMakeCopy;
;}
    break;

  case 1008:

    {
	if (parserData->pathPairFromPresent)
		osolerror( NULL, osoption, parserData, osglData, "only one \"from\" attribute allowed");
	parserData->pathPairFromPresent = true;
	parserData->fromPaths[parserData->kounter] = (yyvsp[(2) - (3)].sval);
;}
    break;

  case 1009:

    {
	if (parserData->pathPairToPresent)
		osolerror( NULL, osoption, parserData, osglData, "only one \"to\" attribute allowed");
	parserData->pathPairToPresent = true;
	parserData->toPaths[parserData->kounter] = (yyvsp[(2) - (3)].sval);
;}
    break;

  case 1010:

    {
	if (parserData->pathPairMakeCopyPresent)
		osolerror( NULL, osoption, parserData, osglData, "only one \"makeCopy\" attribute allowed");
	parserData->pathPairMakeCopyPresent = true;
	parserData->pathPairMakeCopy = (strcmp((yyvsp[(2) - (3)].sval),"true") == 0);
;}
    break;

  case 1013:

    {   
	if (parserData->categoryAttributePresent ) 
		osolerror(NULL, NULL, parserData, osglData, "only one category attribute allowed for this element");
	parserData->categoryAttributePresent = true;
;}
    break;

  case 1016:

    { 
	parserData->categoryAttribute = "";
;}
    break;

  case 1017:

    { 
	parserData->categoryAttribute = (yyvsp[(2) - (3)].sval); 
	free((yyvsp[(2) - (3)].sval)); 
;}
    break;

  case 1018:

    {
	if (parserData->descriptionAttributePresent ) 
		osolerror(NULL, NULL, parserData, osglData, "only one description attribute allowed for this element");
	parserData->descriptionAttributePresent = true;
;}
    break;

  case 1021:

    { parserData->descriptionAttribute = ""; ;}
    break;

  case 1022:

    { 
	parserData->descriptionAttribute = (yyvsp[(2) - (3)].sval); 
	free((yyvsp[(2) - (3)].sval));
;}
    break;

  case 1023:

    {
	if (parserData->groupWeightAttributePresent ) 
		osolerror(NULL, NULL, parserData, osglData, "only one groupWeight attribute allowed for this element");
	parserData->groupWeightAttributePresent = true;
;}
    break;

  case 1024:

    {
	parserData->groupWeight = parserData->tempVal;
;}
    break;

  case 1025:

    {   
	if (parserData->idxAttributePresent ) 
		osolerror(NULL, NULL, parserData, osglData, "only one idx attribute allowed for this element");
	parserData->idxAttributePresent = true;
;}
    break;

  case 1027:

    { 
	parserData->idxAttribute = (yyvsp[(3) - (4)].ival);
;}
    break;

  case 1028:

    {   
	if (parserData->lbValueAttributePresent ) 
		osolerror(NULL, NULL, parserData, osglData, "only one lb attribute allowed for this element");
	parserData->lbValueAttributePresent = true;
;}
    break;

  case 1031:

    { 
	parserData->lbValueAttribute = ""; 
;}
    break;

  case 1032:

    { 
	parserData->lbValueAttribute = (yyvsp[(2) - (3)].sval); 
	free((yyvsp[(2) - (3)].sval));
;}
    break;

  case 1033:

    {   if (parserData->lbValueAttributePresent ) 
				osolerror(NULL, NULL, parserData, osglData, "only one lb attribute allowed for this element");
			parserData->lbValueAttributePresent = true;
		;}
    break;

  case 1036:

    { parserData->lbDualValue = 0.0; ;}
    break;

  case 1037:

    { parserData->lbDualValue = parserData->tempVal;;}
    break;

  case 1038:

    {   if (parserData->nameAttributePresent ) 
				osolerror(NULL, NULL, parserData, osglData, "only one name attribute allowed for this element");
			parserData->nameAttributePresent = true;
		;}
    break;

  case 1041:

    { parserData->nameAttribute = ""; ;}
    break;

  case 1042:

    { 
	parserData->nameAttribute = (yyvsp[(2) - (3)].sval); 
	free((yyvsp[(2) - (3)].sval));
;}
    break;

  case 1043:

    {   if (parserData->solverAttributePresent ) 
				osolerror(NULL, NULL, parserData, osglData, "only one solver attribute allowed for this element");
			parserData->solverAttributePresent = true;
		;}
    break;

  case 1046:

    { parserData->solverAttribute = ""; ;}
    break;

  case 1047:

    { 
	parserData->solverAttribute = (yyvsp[(2) - (3)].sval); 
	free((yyvsp[(2) - (3)].sval));
;}
    break;

  case 1048:

    {   if (parserData->sosIdxAttributePresent ) 
			osolerror(NULL, NULL, parserData, osglData, "only one sosIdx attribute allowed for this element");
		parserData->sosIdxAttributePresent = true;
	;}
    break;

  case 1050:

    {
	if ((yyvsp[(3) - (4)].ival) < 0)
		osolerror (NULL, osoption, parserData, osglData, "SOS index must be nonnegative");
	parserData->sosIdx = (yyvsp[(3) - (4)].ival);
;}
    break;

  case 1051:

    {   if (parserData->typeAttributePresent ) 
				osolerror(NULL, NULL, parserData, osglData, "only one type attribute allowed for this element");
			parserData->typeAttributePresent = true;
		;}
    break;

  case 1054:

    { parserData->typeAttribute = ""; ;}
    break;

  case 1055:

    { 
	parserData->typeAttribute = (yyvsp[(2) - (3)].sval); 
	free((yyvsp[(2) - (3)].sval));
;}
    break;

  case 1056:

    {
   if (parserData->ubValueAttributePresent ) 
		osolerror(NULL, NULL, parserData, osglData, "only one ub attribute allowed for this element");
	parserData->ubValueAttributePresent = true;
;}
    break;

  case 1059:

    { 
	parserData->ubValueAttribute = ""; 
;}
    break;

  case 1060:

    { 
	parserData->ubValueAttribute = (yyvsp[(2) - (3)].sval); 
	free((yyvsp[(2) - (3)].sval));
;}
    break;

  case 1061:

    {   if (parserData->ubValueAttributePresent ) 
				osolerror(NULL, NULL, parserData, osglData, "only one ub attribute allowed for this element");
			parserData->ubValueAttributePresent = true;
		;}
    break;

  case 1064:

    { parserData->ubDualValue = 0.0; ;}
    break;

  case 1065:

    { 
	parserData->ubDualValue = parserData->tempVal;
;}
    break;

  case 1066:

    {   if (parserData->unitAttributePresent ) 
				osolerror(NULL, NULL, parserData, osglData, "only one unit attribute allowed for this element");
			parserData->unitAttributePresent = true;
		;}
    break;

  case 1069:

    { parserData->unitAttribute = ""; ;}
    break;

  case 1070:

    { 
	parserData->unitAttribute = (yyvsp[(2) - (3)].sval); 
	free((yyvsp[(2) - (3)].sval));
;}
    break;

  case 1071:

    {   if (parserData->valueAttributePresent ) 
				osolerror(NULL, NULL, parserData, osglData, "only one value attribute allowed for this element");
			parserData->valueAttributePresent = true;
		;}
    break;

  case 1074:

    { parserData->valueAttribute = ""; ;}
    break;

  case 1075:

    {
	parserData->valueAttribute = (yyvsp[(2) - (3)].sval); 
	free((yyvsp[(2) - (3)].sval));
;}
    break;

  case 1076:

    {
	if (parserData->numberOfConAttributePresent)
		osolerror(NULL, NULL, parserData, osglData, "numberOfCon attribute previously set");
	if ((yyvsp[(3) - (4)].ival) < 0) osolerror(NULL, NULL, parserData, osglData, "number of <con> cannot be negative");
	parserData->numberOfConAttributePresent = true;		
	parserData->numberOfCon = (yyvsp[(3) - (4)].ival);
;}
    break;

  case 1077:

    {
	if (parserData->numberOfConstraintsPresent)
		osolerror(NULL, NULL, parserData, osglData, "numberOfConstraints attribute previously set");
	if ((yyvsp[(3) - (4)].ival) < 0) osolerror(NULL, NULL, parserData, osglData, "number of constraints cannot be negative");
	parserData->numberOfConstraintsPresent = true;		
	parserData->tempInt = (yyvsp[(3) - (4)].ival); 
;}
    break;

  case 1078:

    {
	if (osglData->osglNumberOfElPresent)
		osolerror(NULL, NULL, parserData, osglData, "numberOfEl attribute previously set");
	if ((yyvsp[(3) - (4)].ival) < 0) osolerror(NULL, NULL, parserData, osglData, "number of <el> cannot be negative");
	osglData->osglNumberOfElPresent = true;
	parserData->numberOf = (yyvsp[(3) - (4)].ival); 
;}
    break;

  case 1079:

    {
	if (parserData->numberOfEnumerationsAttributePresent)
		osolerror(NULL, NULL, parserData, osglData, "numberOfEnumerations attribute previously set");
	if ((yyvsp[(3) - (4)].ival) < 0) osolerror(NULL, NULL, parserData, osglData, "number of <enumeration> elements cannot be negative");
	parserData->numberOfEnumerationsAttributePresent = true;		
	parserData->numberOfEnumerations = (yyvsp[(3) - (4)].ival); 
;}
    break;

  case 1080:

    {	
   if (parserData->numberOfItemsPresent ) 
        osolerror(NULL, NULL, parserData, osglData, "only one numberOfItems attribute allowed");
	if ((yyvsp[(3) - (4)].ival) < 0) osolerror(NULL, NULL, parserData, osglData, "number of items cannot be negative");
	parserData->numberOfItemsPresent = true;
	parserData->numberOfItems = (yyvsp[(3) - (4)].ival);
;}
    break;

  case 1081:

    {
	if ((yyvsp[(3) - (4)].ival) < 0)
		osolerror( NULL, osoption, parserData, osglData, "Number of job IDs cannot be negative");
	parserData->numberOf = (yyvsp[(3) - (4)].ival);
	parserData->kounter = 0;
	parserData->jobDependencies = new std::string[(yyvsp[(3) - (4)].ival)];
;}
    break;

  case 1082:

    {
	if (parserData->numberOfObjAttributePresent)
		osolerror(NULL, NULL, parserData, osglData, "numberOfObj attribute previously set");
	if ((yyvsp[(3) - (4)].ival) < 0) osolerror(NULL, NULL, parserData, osglData, "number of <obj> cannot be negative");
	parserData->numberOfObjAttributePresent = true;		
	parserData->numberOfObj = (yyvsp[(3) - (4)].ival);
;}
    break;

  case 1083:

    {	if (parserData->numberOfObjectivesPresent)
		osolerror(NULL, NULL, parserData, osglData, "numberOfObjectives attribute previously set");
	if ((yyvsp[(3) - (4)].ival) < 0) osolerror(NULL, NULL, parserData, osglData, "number of objectives cannot be negative");
	parserData->numberOfObjectivesPresent = true;
	parserData->tempInt = (yyvsp[(3) - (4)].ival); 
;}
    break;

  case 1084:

    {
	if ((yyvsp[(3) - (4)].ival) < 0) osolerror(NULL, NULL, parserData, osglData, "number of other constraint options cannot be negative");
	parserData->tempInt = (yyvsp[(3) - (4)].ival);
;}
    break;

  case 1085:

    {
	if ((yyvsp[(3) - (4)].ival) < 0) osolerror(NULL, NULL, parserData, osglData, "number of other objective options cannot be negative");
	parserData->tempInt = (yyvsp[(3) - (4)].ival);
;}
    break;

  case 1086:

    {
	if ((yyvsp[(3) - (4)].ival) < 0) osolerror(NULL, NULL, parserData, osglData, "number of other options cannot be negative");
	parserData->tempInt = (yyvsp[(3) - (4)].ival);
;}
    break;

  case 1087:

    {	
	if ((yyvsp[(3) - (4)].ival) < 0) osolerror(NULL, NULL, parserData, osglData, "number of other variable options cannot be negative");
	parserData->tempInt = (yyvsp[(3) - (4)].ival);
;}
    break;

  case 1088:

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

  case 1089:

    {
	if ((yyvsp[(3) - (4)].ival) < 0)
		osolerror( NULL, osoption, parserData, osglData, "Number of paths cannot be negative");
	parserData->numberOf = (yyvsp[(3) - (4)].ival);
	parserData->kounter = 0;
	parserData->paths = new std::string[(yyvsp[(3) - (4)].ival)];
;}
    break;

  case 1090:

    {
	if ((yyvsp[(3) - (4)].ival) < 0)
		osolerror( NULL, osoption, parserData, osglData, "Number of job IDs cannot be negative");
	parserData->numberOf = (yyvsp[(3) - (4)].ival);
	parserData->kounter = 0;
	parserData->processesToKill = new std::string[(yyvsp[(3) - (4)].ival)];
;}
    break;

  case 1091:

    {	
	if ((yyvsp[(3) - (4)].ival) < 0) osolerror(NULL, NULL, parserData, osglData, "number of solver options cannot be negative");
	parserData->numberOfSolverOptions = (yyvsp[(3) - (4)].ival);
;}
    break;

  case 1092:

    {
	if (parserData->numberOfVarAttributePresent)
		osolerror(NULL, NULL, parserData, osglData, "numberOfVar attribute previously set");
	if ((yyvsp[(3) - (4)].ival) < 0) osolerror(NULL, NULL, parserData, osglData, "number of <var> cannot be negative");
	parserData->numberOfVarAttributePresent = true;		
	parserData->numberOfVar = (yyvsp[(3) - (4)].ival); 
;}
    break;

  case 1093:

    {	if (parserData->numberOfVariablesPresent)
		osolerror(NULL, NULL, parserData, osglData, "numberOfVariables attribute previously set");
	if ((yyvsp[(3) - (4)].ival) < 0) osolerror(NULL, NULL, parserData, osglData, "number of variables cannot be negative");
	parserData->numberOfVariablesPresent = true;	
	parserData->tempInt = (yyvsp[(3) - (4)].ival); 
;}
    break;

  case 1096:

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

  case 1097:

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

  case 1098:

    {	if(!osglData->osglNumberOfElPresent) 
			osolerror(NULL, NULL, parserData, osglData, "<other> element enumeration requires numberOfEl attribute"); 
		if(!parserData->valueAttributePresent) 
			osolerror(NULL, NULL, parserData, osglData, "<other> element enumeration requires value attribute"); 
	;}
    break;

  case 1101:

    {
		osglData->osglCounter = 0; 
		osglData->osglNumberOfElPresent = true;
		osglData->osglNumberOfEl = parserData->numberOf;
		osglData->osglIntArray = new int[parserData->numberOf];
	;}
    break;

  case 1109:

    {
	 	if (osglData->osglCounter + osglData->osglMult < osglData->osglNumberOfEl)
		osolerror(NULL, NULL, parserData, osglData, "fewer data elements than specified");
	;}
    break;

  case 1114:

    {	
	osglData->osglMultPresent = false;
	osglData->osglIncrPresent = false;
	osglData->osglMult = 1;
	osglData->osglIncr = 0;
;}
    break;

  case 1120:

    {
	if (osglData->osglCounter + osglData->osglMult > osglData->osglNumberOfEl)
		osolerror(NULL, NULL, parserData, osglData, "more data elements than specified");
	for (int i=0; i<osglData->osglMult; i++)
		osglData->osglIntArray[osglData->osglCounter++] = (yyvsp[(2) - (3)].ival) + i*osglData->osglIncr;	
;}
    break;

  case 1122:

    {
	osglData->osglSize = (yyvsp[(3) - (4)].ival);
;}
    break;

  case 1127:

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
;}
    break;

  case 1128:

    {	
	if (osglData->osglIncrPresent) 
        osolerror(NULL, NULL, parserData, osglData, "only one incr attribute allowed");
	osglData->osglIncrPresent = true;
	osglData->osglIncr = (yyvsp[(3) - (4)].ival);
;}
    break;

  case 1129:

    {	
	if (osglData->osglMultPresent) 
        osolerror(NULL, NULL, parserData, osglData, "only one mult attribute allowed");
	if ((yyvsp[(3) - (4)].ival) <= 0) osolerror(NULL, NULL, parserData, osglData, "mult must be positive");
	osglData->osglMultPresent = true;
	osglData->osglMult = (yyvsp[(3) - (4)].ival);
;}
    break;

  case 1130:

    {parserData->tempVal = (yyvsp[(1) - (1)].ival);;}
    break;

  case 1131:

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

