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
     INTEGER = 260,
     DOUBLE = 261,
     QUOTE = 262,
     TWOQUOTES = 263,
     GREATERTHAN = 264,
     ENDOFELEMENT = 265,
     OSOLSTART = 266,
     OSOLSTARTEMPTY = 267,
     OSOLATTRIBUTETEXT = 268,
     OSOLEND = 269,
     LOCATIONTYPEATT = 270,
     TRANSPORTTYPEATT = 271,
     NUMBEROFOTHEROPTIONSATT = 272,
     NUMBEROFJOBIDSATT = 273,
     NUMBEROFPATHSATT = 274,
     NUMBEROFPATHPAIRSATT = 275,
     FROMATT = 276,
     TOATT = 277,
     MAKECOPYATT = 278,
     SOLVERATT = 279,
     CATEGORYATT = 280,
     TYPEATT = 281,
     GROUPWEIGHTATT = 282,
     NUMBEROFPROCESSESATT = 283,
     NUMBEROFSOLVEROPTIONSATT = 284,
     NUMBEROFSOSATT = 285,
     NUMBEROFVARIABLESATT = 286,
     NUMBEROFOBJECTIVESATT = 287,
     NUMBEROFCONSTRAINTSATT = 288,
     NUMBEROFOTHERVARIABLEOPTIONSATT = 289,
     NUMBEROFOTHEROBJECTIVEOPTIONSATT = 290,
     NUMBEROFOTHERCONSTRAINTOPTIONSATT = 291,
     NUMBEROFVARATT = 292,
     NUMBEROFOBJATT = 293,
     NUMBEROFCONATT = 294,
     NAMEATT = 295,
     IDXATT = 296,
     SOSIDXATT = 297,
     VALUEATT = 298,
     UNITATT = 299,
     DESCRIPTIONATT = 300,
     LBVALUEATT = 301,
     UBVALUEATT = 302,
     LBDUALVALUEATT = 303,
     UBDUALVALUEATT = 304,
     GENERALSTART = 305,
     GENERALEND = 306,
     SYSTEMSTART = 307,
     SYSTEMEND = 308,
     SERVICESTART = 309,
     SERVICEEND = 310,
     JOBSTART = 311,
     JOBEND = 312,
     OPTIMIZATIONSTART = 313,
     OPTIMIZATIONEND = 314,
     SERVICEURISTART = 315,
     SERVICEURIEND = 316,
     SERVICENAMESTART = 317,
     SERVICENAMEEND = 318,
     INSTANCENAMESTART = 319,
     INSTANCENAMEEND = 320,
     INSTANCELOCATIONSTART = 321,
     INSTANCELOCATIONEND = 322,
     JOBIDSTART = 323,
     JOBIDEND = 324,
     SOLVERTOINVOKESTART = 325,
     SOLVERTOINVOKEEND = 326,
     LICENSESTART = 327,
     LICENSEEND = 328,
     USERNAMESTART = 329,
     USERNAMEEND = 330,
     PASSWORDSTART = 331,
     PASSWORDEND = 332,
     CONTACTSTART = 333,
     CONTACTEND = 334,
     OTHEROPTIONSSTART = 335,
     OTHEROPTIONSEND = 336,
     OTHERSTART = 337,
     OTHEREND = 338,
     MINDISKSPACESTART = 339,
     MINDISKSPACEEND = 340,
     MINMEMORYSIZESTART = 341,
     MINMEMORYSIZEEND = 342,
     MINCPUSPEEDSTART = 343,
     MINCPUSPEEDEND = 344,
     MINCPUNUMBERSTART = 345,
     MINCPUNUMBEREND = 346,
     SERVICETYPESTART = 347,
     SERVICETYPEEND = 348,
     MAXTIMESTART = 349,
     MAXTIMEEND = 350,
     REQUESTEDSTARTTIMESTART = 351,
     REQUESTEDSTARTTIMEEND = 352,
     DEPENDENCIESSTART = 353,
     DEPENDENCIESEND = 354,
     REQUIREDDIRECTORIESSTART = 355,
     REQUIREDDIRECTORIESEND = 356,
     REQUIREDFILESSTART = 357,
     REQUIREDFILESEND = 358,
     PATHSTART = 359,
     PATHEND = 360,
     PATHPAIRSTART = 361,
     PATHPAIREND = 362,
     DIRECTORIESTOMAKESTART = 363,
     DIRECTORIESTOMAKEEND = 364,
     FILESTOMAKESTART = 365,
     FILESTOMAKEEND = 366,
     DIRECTORIESTODELETESTART = 367,
     DIRECTORIESTODELETEEND = 368,
     FILESTODELETESTART = 369,
     FILESTODELETEEND = 370,
     INPUTDIRECTORIESTOMOVESTART = 371,
     INPUTDIRECTORIESTOMOVEEND = 372,
     INPUTFILESTOMOVESTART = 373,
     INPUTFILESTOMOVEEND = 374,
     OUTPUTDIRECTORIESTOMOVESTART = 375,
     OUTPUTDIRECTORIESTOMOVEEND = 376,
     OUTPUTFILESTOMOVESTART = 377,
     OUTPUTFILESTOMOVEEND = 378,
     PROCESSESTOKILLSTART = 379,
     PROCESSESTOKILLEND = 380,
     PROCESSSTART = 381,
     PROCESSEND = 382,
     VARIABLESSTART = 383,
     VARIABLESEND = 384,
     INITIALVARIABLEVALUESSTART = 385,
     INITIALVARIABLEVALUESEND = 386,
     VARSTART = 387,
     VAREND = 388,
     INITIALVARIABLEVALUESSTRINGSTART = 389,
     INITIALVARIABLEVALUESSTRINGEND = 390,
     INITIALBASISSTATUSSTART = 391,
     INITIALBASISSTATUSEND = 392,
     INTEGERVARIABLEBRANCHINGWEIGHTSSTART = 393,
     INTEGERVARIABLEBRANCHINGWEIGHTSEND = 394,
     SOSVARIABLEBRANCHINGWEIGHTSSTART = 395,
     SOSVARIABLEBRANCHINGWEIGHTSEND = 396,
     SOSSTART = 397,
     SOSEND = 398,
     OBJECTIVESSTART = 399,
     OBJECTIVESEND = 400,
     INITIALOBJECTIVEVALUESSTART = 401,
     INITIALOBJECTIVEVALUESEND = 402,
     OBJSTART = 403,
     OBJEND = 404,
     INITIALOBJECTIVEBOUNDSSTART = 405,
     INITIALOBJECTIVEBOUNDSEND = 406,
     CONSTRAINTSSTART = 407,
     CONSTRAINTSEND = 408,
     INITIALCONSTRAINTVALUESSTART = 409,
     INITIALCONSTRAINTVALUESEND = 410,
     CONSTART = 411,
     CONEND = 412,
     INITIALDUALVALUESSTART = 413,
     INITIALDUALVALUESEND = 414,
     SOLVEROPTIONSSTART = 415,
     SOLVEROPTIONSEND = 416,
     SOLVEROPTIONSTART = 417,
     SOLVEROPTIONEND = 418,
     DUMMY = 419
   };
#endif
/* Tokens.  */
#define ATTRIBUTETEXT 258
#define ELEMENTTEXT 259
#define INTEGER 260
#define DOUBLE 261
#define QUOTE 262
#define TWOQUOTES 263
#define GREATERTHAN 264
#define ENDOFELEMENT 265
#define OSOLSTART 266
#define OSOLSTARTEMPTY 267
#define OSOLATTRIBUTETEXT 268
#define OSOLEND 269
#define LOCATIONTYPEATT 270
#define TRANSPORTTYPEATT 271
#define NUMBEROFOTHEROPTIONSATT 272
#define NUMBEROFJOBIDSATT 273
#define NUMBEROFPATHSATT 274
#define NUMBEROFPATHPAIRSATT 275
#define FROMATT 276
#define TOATT 277
#define MAKECOPYATT 278
#define SOLVERATT 279
#define CATEGORYATT 280
#define TYPEATT 281
#define GROUPWEIGHTATT 282
#define NUMBEROFPROCESSESATT 283
#define NUMBEROFSOLVEROPTIONSATT 284
#define NUMBEROFSOSATT 285
#define NUMBEROFVARIABLESATT 286
#define NUMBEROFOBJECTIVESATT 287
#define NUMBEROFCONSTRAINTSATT 288
#define NUMBEROFOTHERVARIABLEOPTIONSATT 289
#define NUMBEROFOTHEROBJECTIVEOPTIONSATT 290
#define NUMBEROFOTHERCONSTRAINTOPTIONSATT 291
#define NUMBEROFVARATT 292
#define NUMBEROFOBJATT 293
#define NUMBEROFCONATT 294
#define NAMEATT 295
#define IDXATT 296
#define SOSIDXATT 297
#define VALUEATT 298
#define UNITATT 299
#define DESCRIPTIONATT 300
#define LBVALUEATT 301
#define UBVALUEATT 302
#define LBDUALVALUEATT 303
#define UBDUALVALUEATT 304
#define GENERALSTART 305
#define GENERALEND 306
#define SYSTEMSTART 307
#define SYSTEMEND 308
#define SERVICESTART 309
#define SERVICEEND 310
#define JOBSTART 311
#define JOBEND 312
#define OPTIMIZATIONSTART 313
#define OPTIMIZATIONEND 314
#define SERVICEURISTART 315
#define SERVICEURIEND 316
#define SERVICENAMESTART 317
#define SERVICENAMEEND 318
#define INSTANCENAMESTART 319
#define INSTANCENAMEEND 320
#define INSTANCELOCATIONSTART 321
#define INSTANCELOCATIONEND 322
#define JOBIDSTART 323
#define JOBIDEND 324
#define SOLVERTOINVOKESTART 325
#define SOLVERTOINVOKEEND 326
#define LICENSESTART 327
#define LICENSEEND 328
#define USERNAMESTART 329
#define USERNAMEEND 330
#define PASSWORDSTART 331
#define PASSWORDEND 332
#define CONTACTSTART 333
#define CONTACTEND 334
#define OTHEROPTIONSSTART 335
#define OTHEROPTIONSEND 336
#define OTHERSTART 337
#define OTHEREND 338
#define MINDISKSPACESTART 339
#define MINDISKSPACEEND 340
#define MINMEMORYSIZESTART 341
#define MINMEMORYSIZEEND 342
#define MINCPUSPEEDSTART 343
#define MINCPUSPEEDEND 344
#define MINCPUNUMBERSTART 345
#define MINCPUNUMBEREND 346
#define SERVICETYPESTART 347
#define SERVICETYPEEND 348
#define MAXTIMESTART 349
#define MAXTIMEEND 350
#define REQUESTEDSTARTTIMESTART 351
#define REQUESTEDSTARTTIMEEND 352
#define DEPENDENCIESSTART 353
#define DEPENDENCIESEND 354
#define REQUIREDDIRECTORIESSTART 355
#define REQUIREDDIRECTORIESEND 356
#define REQUIREDFILESSTART 357
#define REQUIREDFILESEND 358
#define PATHSTART 359
#define PATHEND 360
#define PATHPAIRSTART 361
#define PATHPAIREND 362
#define DIRECTORIESTOMAKESTART 363
#define DIRECTORIESTOMAKEEND 364
#define FILESTOMAKESTART 365
#define FILESTOMAKEEND 366
#define DIRECTORIESTODELETESTART 367
#define DIRECTORIESTODELETEEND 368
#define FILESTODELETESTART 369
#define FILESTODELETEEND 370
#define INPUTDIRECTORIESTOMOVESTART 371
#define INPUTDIRECTORIESTOMOVEEND 372
#define INPUTFILESTOMOVESTART 373
#define INPUTFILESTOMOVEEND 374
#define OUTPUTDIRECTORIESTOMOVESTART 375
#define OUTPUTDIRECTORIESTOMOVEEND 376
#define OUTPUTFILESTOMOVESTART 377
#define OUTPUTFILESTOMOVEEND 378
#define PROCESSESTOKILLSTART 379
#define PROCESSESTOKILLEND 380
#define PROCESSSTART 381
#define PROCESSEND 382
#define VARIABLESSTART 383
#define VARIABLESEND 384
#define INITIALVARIABLEVALUESSTART 385
#define INITIALVARIABLEVALUESEND 386
#define VARSTART 387
#define VAREND 388
#define INITIALVARIABLEVALUESSTRINGSTART 389
#define INITIALVARIABLEVALUESSTRINGEND 390
#define INITIALBASISSTATUSSTART 391
#define INITIALBASISSTATUSEND 392
#define INTEGERVARIABLEBRANCHINGWEIGHTSSTART 393
#define INTEGERVARIABLEBRANCHINGWEIGHTSEND 394
#define SOSVARIABLEBRANCHINGWEIGHTSSTART 395
#define SOSVARIABLEBRANCHINGWEIGHTSEND 396
#define SOSSTART 397
#define SOSEND 398
#define OBJECTIVESSTART 399
#define OBJECTIVESEND 400
#define INITIALOBJECTIVEVALUESSTART 401
#define INITIALOBJECTIVEVALUESEND 402
#define OBJSTART 403
#define OBJEND 404
#define INITIALOBJECTIVEBOUNDSSTART 405
#define INITIALOBJECTIVEBOUNDSEND 406
#define CONSTRAINTSSTART 407
#define CONSTRAINTSEND 408
#define INITIALCONSTRAINTVALUESSTART 409
#define INITIALCONSTRAINTVALUESEND 410
#define CONSTART 411
#define CONEND 412
#define INITIALDUALVALUESSTART 413
#define INITIALDUALVALUESEND 414
#define SOLVEROPTIONSSTART 415
#define SOLVEROPTIONSEND 416
#define SOLVEROPTIONSTART 417
#define SOLVEROPTIONEND 418
#define DUMMY 419




/* Copy the first part of user declarations.  */




#include "OSDataStructures.h"
#include "OSMathUtil.h"
#include "OSParameters.h"
#include "OSConfig.h"
#include "OSErrorClass.h"
#include "OSOption.h"
#include "OSoLParserData.h"
#include <iostream>
#include <sstream>
#include <stdio.h>


typedef struct yy_buffer_state *YY_BUFFER_STATE;
YY_BUFFER_STATE osol_scan_string (const char *yy_str , void* yyscanner  );
int osollex_init(void** ptr_yy_globals);
int osollex_destroy (void* yyscanner );
int osolget_lineno( void* yyscanner);
char *osolget_text (void* yyscanner );
void osolset_lineno (int line_number , void* yyscanner );
void osolset_extra (OSoLParserData* parserData , void* yyscanner );
void  yygetOSOption(const char *ch, OSOption* m_osoption, OSoLParserData *m_parserData ) throw(ErrorClass);




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



void osolerror(YYLTYPE* type, OSOption *osoption,  OSoLParserData *parserData, const char* errormsg ) ;
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
#define YYLAST   795

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  165
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  522
/* YYNRULES -- Number of rules.  */
#define YYNRULES  775
/* YYNRULES -- Number of states.  */
#define YYNSTATES  1300

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   419

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
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
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     7,    10,    12,    16,    22,    23,    26,
      28,    32,    34,    35,    38,    40,    42,    44,    46,    48,
      50,    52,    54,    56,    58,    60,    63,    65,    67,    70,
      71,    76,    79,    81,    83,    86,    87,    92,    95,    97,
      99,   102,   103,   108,   112,   114,   115,   116,   121,   123,
     127,   128,   130,   133,   135,   137,   140,   141,   146,   149,
     151,   153,   156,   157,   162,   165,   167,   169,   172,   173,
     178,   181,   183,   185,   188,   189,   194,   197,   199,   201,
     204,   205,   210,   214,   216,   217,   218,   223,   225,   229,
     230,   232,   237,   239,   244,   247,   248,   251,   252,   257,
     258,   261,   263,   265,   267,   268,   273,   274,   279,   280,
     285,   287,   290,   291,   294,   296,   300,   302,   303,   306,
     308,   310,   312,   314,   316,   320,   322,   323,   324,   329,
     331,   334,   338,   342,   346,   348,   349,   350,   355,   357,
     360,   364,   368,   372,   374,   375,   376,   381,   383,   386,
     390,   394,   397,   399,   401,   404,   405,   410,   415,   417,
     422,   425,   426,   429,   430,   435,   436,   439,   441,   443,
     445,   446,   451,   452,   457,   458,   463,   465,   468,   469,
     472,   474,   478,   480,   481,   484,   486,   488,   491,   493,
     495,   498,   499,   504,   509,   511,   516,   519,   520,   523,
     524,   529,   530,   533,   535,   537,   539,   540,   545,   546,
     551,   552,   557,   559,   562,   563,   566,   568,   572,   574,
     575,   578,   580,   582,   584,   586,   588,   590,   592,   594,
     596,   598,   600,   602,   604,   606,   608,   612,   614,   615,
     616,   621,   623,   626,   630,   634,   637,   639,   641,   644,
     645,   650,   656,   658,   663,   664,   667,   668,   674,   680,
     682,   687,   688,   691,   692,   698,   704,   706,   711,   712,
     715,   716,   722,   728,   730,   735,   736,   739,   740,   746,
     752,   754,   759,   760,   763,   764,   770,   776,   778,   783,
     784,   787,   791,   793,   794,   797,   799,   801,   803,   804,
     809,   810,   815,   816,   821,   824,   826,   832,   834,   839,
     840,   843,   847,   849,   850,   853,   855,   857,   859,   860,
     865,   866,   871,   872,   877,   880,   882,   888,   890,   895,
     896,   899,   903,   905,   906,   909,   911,   913,   915,   916,
     921,   922,   927,   928,   933,   936,   938,   944,   946,   951,
     952,   955,   959,   961,   962,   965,   967,   969,   971,   972,
     977,   978,   983,   984,   989,   992,   994,  1000,  1002,  1007,
    1008,  1011,  1012,  1018,  1024,  1026,  1031,  1032,  1035,  1036,
    1042,  1048,  1050,  1055,  1056,  1059,  1060,  1066,  1071,  1073,
    1078,  1081,  1082,  1085,  1086,  1091,  1092,  1095,  1097,  1099,
    1101,  1102,  1107,  1108,  1113,  1114,  1119,  1121,  1124,  1125,
    1129,  1131,  1132,  1135,  1137,  1139,  1141,  1146,  1151,  1156,
    1160,  1162,  1167,  1168,  1172,  1174,  1175,  1180,  1189,  1191,
    1192,  1198,  1203,  1204,  1207,  1211,  1213,  1214,  1217,  1219,
    1221,  1226,  1227,  1232,  1235,  1237,  1238,  1244,  1249,  1250,
    1253,  1257,  1259,  1260,  1263,  1265,  1267,  1272,  1273,  1278,
    1281,  1283,  1284,  1290,  1295,  1296,  1299,  1303,  1305,  1306,
    1309,  1311,  1313,  1318,  1319,  1324,  1327,  1329,  1330,  1336,
    1341,  1342,  1345,  1349,  1351,  1352,  1355,  1357,  1359,  1364,
    1365,  1370,  1373,  1375,  1376,  1382,  1387,  1388,  1391,  1395,
    1397,  1398,  1401,  1403,  1405,  1407,  1412,  1417,  1422,  1427,
    1431,  1433,  1434,  1437,  1441,  1443,  1444,  1447,  1449,  1451,
    1456,  1457,  1462,  1465,  1467,  1468,  1471,  1475,  1477,  1478,
    1481,  1483,  1485,  1487,  1489,  1491,  1493,  1495,  1500,  1501,
    1506,  1507,  1512,  1513,  1518,  1519,  1524,  1525,  1530,  1531,
    1536,  1540,  1541,  1544,  1548,  1550,  1551,  1554,  1556,  1558,
    1560,  1562,  1567,  1568,  1573,  1574,  1579,  1580,  1585,  1588,
    1590,  1591,  1595,  1597,  1598,  1603,  1609,  1611,  1612,  1618,
    1623,  1624,  1627,  1631,  1633,  1634,  1637,  1639,  1641,  1646,
    1647,  1652,  1655,  1657,  1658,  1664,  1669,  1670,  1673,  1677,
    1679,  1680,  1683,  1685,  1687,  1689,  1694,  1695,  1700,  1701,
    1706,  1709,  1711,  1712,  1715,  1719,  1721,  1722,  1725,  1727,
    1729,  1731,  1733,  1735,  1737,  1739,  1744,  1745,  1750,  1751,
    1756,  1757,  1762,  1763,  1768,  1769,  1774,  1775,  1780,  1784,
    1785,  1788,  1792,  1794,  1795,  1798,  1800,  1802,  1804,  1806,
    1811,  1812,  1817,  1818,  1823,  1824,  1829,  1832,  1834,  1835,
    1839,  1841,  1842,  1847,  1853,  1855,  1856,  1862,  1867,  1868,
    1871,  1875,  1877,  1878,  1881,  1883,  1885,  1890,  1891,  1896,
    1899,  1901,  1902,  1908,  1913,  1914,  1917,  1921,  1923,  1924,
    1927,  1929,  1931,  1933,  1938,  1939,  1944,  1945,  1950,  1953,
    1955,  1956,  1959,  1963,  1965,  1966,  1969,  1971,  1973,  1975,
    1977,  1979,  1981,  1983,  1988,  1989,  1994,  1995,  2000,  2001,
    2006,  2007,  2012,  2013,  2018,  2019,  2024,  2028,  2029,  2032,
    2036,  2038,  2039,  2042,  2044,  2046,  2048,  2050,  2055,  2056,
    2061,  2062,  2067,  2068,  2073,  2076,  2078,  2079,  2085,  2087,
    2092,  2093,  2096,  2097,  2102,  2103,  2106,  2108,  2110,  2112,
    2114,  2116,  2118,  2119,  2124,  2125,  2130,  2131,  2136,  2137,
    2142,  2143,  2148,  2149,  2154,  2157
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     166,     0,    -1,   167,   168,    14,    -1,   167,    10,    -1,
      12,    -1,    11,    13,     9,    -1,   169,   234,   274,   299,
     437,    -1,    -1,   170,   171,    -1,    50,    -1,     9,   172,
      51,    -1,    10,    -1,    -1,   172,   173,    -1,   174,    -1,
     178,    -1,   182,    -1,   186,    -1,   192,    -1,   196,    -1,
     200,    -1,   204,    -1,   208,    -1,   212,    -1,   218,    -1,
     175,   176,    -1,    60,    -1,    10,    -1,     9,    61,    -1,
      -1,     9,     4,   177,    61,    -1,   179,   180,    -1,    62,
      -1,    10,    -1,     9,    63,    -1,    -1,     9,     4,   181,
      63,    -1,   183,   184,    -1,    64,    -1,    10,    -1,     9,
      65,    -1,    -1,     9,     4,   185,    65,    -1,   187,   188,
     190,    -1,    66,    -1,    -1,    -1,    15,     3,   189,     7,
      -1,    10,    -1,     9,   191,    67,    -1,    -1,     4,    -1,
     193,   194,    -1,    68,    -1,    10,    -1,     9,    69,    -1,
      -1,     9,     4,   195,    69,    -1,   197,   198,    -1,    70,
      -1,    10,    -1,     9,    71,    -1,    -1,     9,     4,   199,
      71,    -1,   201,   202,    -1,    72,    -1,    10,    -1,     9,
      73,    -1,    -1,     9,     4,   203,    73,    -1,   205,   206,
      -1,    74,    -1,    10,    -1,     9,    75,    -1,    -1,     9,
       4,   207,    75,    -1,   209,   210,    -1,    76,    -1,    10,
      -1,     9,    77,    -1,    -1,     9,     4,   211,    77,    -1,
     213,   214,   216,    -1,    78,    -1,    -1,    -1,    16,     3,
     215,     7,    -1,    10,    -1,     9,   217,    79,    -1,    -1,
       4,    -1,   219,   220,     9,   221,    -1,    80,    -1,    17,
       7,     5,     7,    -1,   222,    81,    -1,    -1,   222,   223,
      -1,    -1,    82,   224,   225,   233,    -1,    -1,   225,   226,
      -1,   227,    -1,   229,    -1,   231,    -1,    -1,    40,     3,
     228,     7,    -1,    -1,    43,     3,   230,     7,    -1,    -1,
      45,     3,   232,     7,    -1,    10,    -1,     9,    83,    -1,
      -1,   235,   236,    -1,    52,    -1,     9,   237,    53,    -1,
      10,    -1,    -1,   237,   238,    -1,   239,    -1,   244,    -1,
     249,    -1,   254,    -1,   258,    -1,   240,   241,   243,    -1,
      84,    -1,    -1,    -1,    44,     3,   242,     7,    -1,    10,
      -1,     9,    85,    -1,     9,     6,    85,    -1,     9,     5,
      85,    -1,   245,   246,   248,    -1,    86,    -1,    -1,    -1,
      44,     3,   247,     7,    -1,    10,    -1,     9,    87,    -1,
       9,     6,    87,    -1,     9,     5,    87,    -1,   250,   251,
     253,    -1,    88,    -1,    -1,    -1,    44,     3,   252,     7,
      -1,    10,    -1,     9,    89,    -1,     9,     6,    89,    -1,
       9,     5,    89,    -1,   255,   256,    -1,    90,    -1,    10,
      -1,     9,    91,    -1,    -1,     9,     5,   257,    91,    -1,
     259,   260,     9,   261,    -1,    80,    -1,    17,     7,     5,
       7,    -1,   262,    81,    -1,    -1,   262,   263,    -1,    -1,
      82,   264,   265,   273,    -1,    -1,   265,   266,    -1,   267,
      -1,   269,    -1,   271,    -1,    -1,    40,     3,   268,     7,
      -1,    -1,    43,     3,   270,     7,    -1,    -1,    45,     3,
     272,     7,    -1,    10,    -1,     9,    83,    -1,    -1,   275,
     276,    -1,    54,    -1,     9,   277,    55,    -1,    10,    -1,
      -1,   277,   278,    -1,   279,    -1,   283,    -1,   280,   281,
      -1,    92,    -1,    10,    -1,     9,    93,    -1,    -1,     9,
       4,   282,    93,    -1,   284,   285,     9,   286,    -1,    80,
      -1,    17,     7,     5,     7,    -1,   287,    81,    -1,    -1,
     287,   288,    -1,    -1,    82,   289,   290,   298,    -1,    -1,
     290,   291,    -1,   292,    -1,   294,    -1,   296,    -1,    -1,
      40,     3,   293,     7,    -1,    -1,    43,     3,   295,     7,
      -1,    -1,    45,     3,   297,     7,    -1,    10,    -1,     9,
      83,    -1,    -1,   300,   301,    -1,    56,    -1,     9,   302,
      57,    -1,    10,    -1,    -1,   302,   303,    -1,   304,    -1,
     309,    -1,   313,    -1,   319,    -1,   325,    -1,   331,    -1,
     337,    -1,   343,    -1,   358,    -1,   373,    -1,   388,    -1,
     403,    -1,   409,    -1,   415,    -1,   421,    -1,   305,   306,
     308,    -1,    94,    -1,    -1,    -1,    44,     3,   307,     7,
      -1,    10,    -1,     9,    95,    -1,     9,     6,    95,    -1,
       9,     5,    95,    -1,   310,   311,    -1,    96,    -1,    10,
      -1,     9,    97,    -1,    -1,     9,     4,   312,    97,    -1,
     314,   315,     9,   316,    99,    -1,    98,    -1,    18,     7,
       5,     7,    -1,    -1,   316,   317,    -1,    -1,    68,     9,
       4,   318,    69,    -1,   320,   321,     9,   322,   101,    -1,
     100,    -1,    19,     7,     5,     7,    -1,    -1,   322,   323,
      -1,    -1,   104,     9,     4,   324,   105,    -1,   326,   327,
       9,   328,   103,    -1,   102,    -1,    19,     7,     5,     7,
      -1,    -1,   328,   329,    -1,    -1,   104,     9,     4,   330,
     105,    -1,   332,   333,     9,   334,   109,    -1,   108,    -1,
      19,     7,     5,     7,    -1,    -1,   334,   335,    -1,    -1,
     104,     9,     4,   336,   105,    -1,   338,   339,     9,   340,
     111,    -1,   110,    -1,    19,     7,     5,     7,    -1,    -1,
     340,   341,    -1,    -1,   104,     9,     4,   342,   105,    -1,
     344,   345,     9,   346,   117,    -1,   116,    -1,    20,     7,
       5,     7,    -1,    -1,   346,   347,    -1,   348,   349,   357,
      -1,   106,    -1,    -1,   349,   350,    -1,   351,    -1,   353,
      -1,   355,    -1,    -1,    21,     3,   352,     7,    -1,    -1,
      22,     3,   354,     7,    -1,    -1,    23,     3,   356,     7,
      -1,     9,   107,    -1,    10,    -1,   359,   360,     9,   361,
     119,    -1,   118,    -1,    20,     7,     5,     7,    -1,    -1,
     361,   362,    -1,   363,   364,   372,    -1,   106,    -1,    -1,
     364,   365,    -1,   366,    -1,   368,    -1,   370,    -1,    -1,
      21,     3,   367,     7,    -1,    -1,    22,     3,   369,     7,
      -1,    -1,    23,     3,   371,     7,    -1,     9,   107,    -1,
      10,    -1,   374,   375,     9,   376,   121,    -1,   120,    -1,
      20,     7,     5,     7,    -1,    -1,   376,   377,    -1,   378,
     379,   387,    -1,   106,    -1,    -1,   379,   380,    -1,   381,
      -1,   383,    -1,   385,    -1,    -1,    21,     3,   382,     7,
      -1,    -1,    22,     3,   384,     7,    -1,    -1,    23,     3,
     386,     7,    -1,     9,   107,    -1,    10,    -1,   389,   390,
       9,   391,   123,    -1,   122,    -1,    20,     7,     5,     7,
      -1,    -1,   391,   392,    -1,   393,   394,   402,    -1,   106,
      -1,    -1,   394,   395,    -1,   396,    -1,   398,    -1,   400,
      -1,    -1,    21,     3,   397,     7,    -1,    -1,    22,     3,
     399,     7,    -1,    -1,    23,     3,   401,     7,    -1,     9,
     107,    -1,    10,    -1,   404,   405,     9,   406,   115,    -1,
     114,    -1,    19,     7,     5,     7,    -1,    -1,   406,   407,
      -1,    -1,   104,     9,     4,   408,   105,    -1,   410,   411,
       9,   412,   113,    -1,   112,    -1,    19,     7,     5,     7,
      -1,    -1,   412,   413,    -1,    -1,   104,     9,     4,   414,
     105,    -1,   416,   417,     9,   418,   125,    -1,   124,    -1,
      28,     7,     5,     7,    -1,    -1,   418,   419,    -1,    -1,
     126,     9,     4,   420,   127,    -1,   422,   423,     9,   424,
      -1,    80,    -1,    17,     7,     5,     7,    -1,   425,    81,
      -1,    -1,   425,   426,    -1,    -1,    82,   427,   428,   436,
      -1,    -1,   428,   429,    -1,   430,    -1,   432,    -1,   434,
      -1,    -1,    40,     3,   431,     7,    -1,    -1,    43,     3,
     433,     7,    -1,    -1,    45,     3,   435,     7,    -1,    10,
      -1,     9,    83,    -1,    -1,   438,   439,   444,    -1,    58,
      -1,    -1,   439,   440,    -1,   441,    -1,   442,    -1,   443,
      -1,    31,     7,     5,     7,    -1,    33,     7,     5,     7,
      -1,    32,     7,     5,     7,    -1,     9,   445,    59,    -1,
      10,    -1,   446,   546,   606,   666,    -1,    -1,   447,   448,
     449,    -1,   128,    -1,    -1,    34,     7,     5,     7,    -1,
       9,   450,   461,   472,   483,   494,   514,   129,    -1,    10,
      -1,    -1,   130,   451,     9,   452,   131,    -1,    37,     7,
       5,     7,    -1,    -1,   452,   453,    -1,   454,   455,   460,
      -1,   132,    -1,    -1,   455,   456,    -1,   457,    -1,   458,
      -1,    41,     7,     5,     7,    -1,    -1,    43,     3,   459,
       7,    -1,     9,   133,    -1,    10,    -1,    -1,   134,   462,
       9,   463,   135,    -1,    37,     7,     5,     7,    -1,    -1,
     463,   464,    -1,   465,   466,   471,    -1,   132,    -1,    -1,
     466,   467,    -1,   468,    -1,   469,    -1,    41,     7,     5,
       7,    -1,    -1,    43,     3,   470,     7,    -1,     9,   133,
      -1,    10,    -1,    -1,   136,   473,     9,   474,   137,    -1,
      37,     7,     5,     7,    -1,    -1,   474,   475,    -1,   476,
     477,   482,    -1,   132,    -1,    -1,   477,   478,    -1,   479,
      -1,   480,    -1,    41,     7,     5,     7,    -1,    -1,    43,
       3,   481,     7,    -1,     9,   133,    -1,    10,    -1,    -1,
     138,   484,     9,   485,   139,    -1,    37,     7,     5,     7,
      -1,    -1,   485,   486,    -1,   487,   488,   493,    -1,   132,
      -1,    -1,   488,   489,    -1,   490,    -1,   491,    -1,    41,
       7,     5,     7,    -1,    -1,    43,     3,   492,     7,    -1,
       9,   133,    -1,    10,    -1,    -1,   140,   495,     9,   496,
     141,    -1,    30,     7,     5,     7,    -1,    -1,   496,   497,
      -1,   498,   499,   504,    -1,   142,    -1,    -1,   499,   500,
      -1,   501,    -1,   503,    -1,   502,    -1,    42,     7,     5,
       7,    -1,    27,     7,     6,     7,    -1,    27,     7,     5,
       7,    -1,    37,     7,     5,     7,    -1,     9,   505,   143,
      -1,    10,    -1,    -1,   505,   506,    -1,   507,   508,   513,
      -1,   132,    -1,    -1,   508,   509,    -1,   510,    -1,   511,
      -1,    41,     7,     5,     7,    -1,    -1,    43,     3,   512,
       7,    -1,     9,   133,    -1,    10,    -1,    -1,   514,   515,
      -1,   516,   517,   532,    -1,    82,    -1,    -1,   517,   518,
      -1,   519,    -1,   520,    -1,   522,    -1,   524,    -1,   526,
      -1,   528,    -1,   530,    -1,    37,     7,     5,     7,    -1,
      -1,    40,     3,   521,     7,    -1,    -1,    43,     3,   523,
       7,    -1,    -1,    24,     3,   525,     7,    -1,    -1,    25,
       3,   527,     7,    -1,    -1,    26,     3,   529,     7,    -1,
      -1,    45,     3,   531,     7,    -1,     9,   533,    83,    -1,
      -1,   533,   534,    -1,   535,   536,   545,    -1,   132,    -1,
      -1,   536,   537,    -1,   538,    -1,   539,    -1,   541,    -1,
     543,    -1,    41,     7,     5,     7,    -1,    -1,    43,     3,
     540,     7,    -1,    -1,    46,     3,   542,     7,    -1,    -1,
      47,     3,   544,     7,    -1,     9,   133,    -1,    10,    -1,
      -1,   547,   548,   549,    -1,   144,    -1,    -1,    35,     7,
       5,     7,    -1,     9,   550,   561,   574,   145,    -1,    10,
      -1,    -1,   146,   551,     9,   552,   147,    -1,    38,     7,
       5,     7,    -1,    -1,   552,   553,    -1,   554,   555,   560,
      -1,   148,    -1,    -1,   555,   556,    -1,   557,    -1,   558,
      -1,    41,     7,     5,     7,    -1,    -1,    43,     3,   559,
       7,    -1,     9,   149,    -1,    10,    -1,    -1,   150,   562,
       9,   563,   151,    -1,    38,     7,     5,     7,    -1,    -1,
     563,   564,    -1,   565,   566,   573,    -1,   148,    -1,    -1,
     566,   567,    -1,   568,    -1,   569,    -1,   571,    -1,    41,
       7,     5,     7,    -1,    -1,    46,     3,   570,     7,    -1,
      -1,    47,     3,   572,     7,    -1,     9,   149,    -1,    10,
      -1,    -1,   574,   575,    -1,   576,   577,   592,    -1,    82,
      -1,    -1,   577,   578,    -1,   579,    -1,   580,    -1,   582,
      -1,   584,    -1,   586,    -1,   588,    -1,   590,    -1,    38,
       7,     5,     7,    -1,    -1,    40,     3,   581,     7,    -1,
      -1,    43,     3,   583,     7,    -1,    -1,    24,     3,   585,
       7,    -1,    -1,    25,     3,   587,     7,    -1,    -1,    26,
       3,   589,     7,    -1,    -1,    45,     3,   591,     7,    -1,
       9,   593,    83,    -1,    -1,   593,   594,    -1,   595,   596,
     605,    -1,   148,    -1,    -1,   596,   597,    -1,   598,    -1,
     599,    -1,   601,    -1,   603,    -1,    41,     7,     5,     7,
      -1,    -1,    43,     3,   600,     7,    -1,    -1,    46,     3,
     602,     7,    -1,    -1,    47,     3,   604,     7,    -1,     9,
     133,    -1,    10,    -1,    -1,   607,   608,   609,    -1,   152,
      -1,    -1,    36,     7,     5,     7,    -1,     9,   610,   621,
     634,   153,    -1,    10,    -1,    -1,   154,   611,     9,   612,
     155,    -1,    39,     7,     5,     7,    -1,    -1,   612,   613,
      -1,   614,   615,   620,    -1,   156,    -1,    -1,   615,   616,
      -1,   617,    -1,   618,    -1,    41,     7,     5,     7,    -1,
      -1,    43,     3,   619,     7,    -1,     9,   157,    -1,    10,
      -1,    -1,   158,   622,     9,   623,   159,    -1,    39,     7,
       5,     7,    -1,    -1,   623,   624,    -1,   625,   626,   633,
      -1,   156,    -1,    -1,   626,   627,    -1,   628,    -1,   629,
      -1,   631,    -1,    41,     7,     5,     7,    -1,    -1,    48,
       3,   630,     7,    -1,    -1,    49,     3,   632,     7,    -1,
       9,   157,    -1,    10,    -1,    -1,   634,   635,    -1,   636,
     637,   652,    -1,    82,    -1,    -1,   637,   638,    -1,   639,
      -1,   640,    -1,   642,    -1,   644,    -1,   646,    -1,   648,
      -1,   650,    -1,    39,     7,     5,     7,    -1,    -1,    40,
       3,   641,     7,    -1,    -1,    43,     3,   643,     7,    -1,
      -1,    24,     3,   645,     7,    -1,    -1,    25,     3,   647,
       7,    -1,    -1,    26,     3,   649,     7,    -1,    -1,    45,
       3,   651,     7,    -1,     9,   653,    83,    -1,    -1,   653,
     654,    -1,   655,   656,   665,    -1,   156,    -1,    -1,   656,
     657,    -1,   658,    -1,   659,    -1,   661,    -1,   663,    -1,
      41,     7,     5,     7,    -1,    -1,    43,     3,   660,     7,
      -1,    -1,    46,     3,   662,     7,    -1,    -1,    47,     3,
     664,     7,    -1,     9,   157,    -1,    10,    -1,    -1,   667,
     668,     9,   669,   161,    -1,   160,    -1,    29,     7,     5,
       7,    -1,    -1,   669,   670,    -1,    -1,   162,   671,   672,
     686,    -1,    -1,   672,   673,    -1,   674,    -1,   676,    -1,
     678,    -1,   680,    -1,   682,    -1,   684,    -1,    -1,    40,
       3,   675,     7,    -1,    -1,    43,     3,   677,     7,    -1,
      -1,    24,     3,   679,     7,    -1,    -1,    25,     3,   681,
       7,    -1,    -1,    26,     3,   683,     7,    -1,    -1,    45,
       3,   685,     7,    -1,     9,   163,    -1,    10,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   134,   134,   135,   137,   138,   141,   143,   143,   145,
     156,   157,   159,   159,   161,   161,   161,   161,   161,   162,
     162,   162,   162,   162,   162,   165,   167,   176,   177,   178,
     178,   181,   183,   192,   193,   194,   194,   197,   199,   208,
     209,   210,   210,   213,   215,   226,   227,   226,   234,   235,
     237,   237,   240,   242,   251,   252,   253,   253,   256,   258,
     267,   268,   269,   269,   272,   274,   283,   284,   285,   285,
     288,   290,   299,   300,   301,   301,   304,   306,   315,   316,
     317,   317,   320,   322,   333,   334,   333,   342,   343,   345,
     345,   348,   350,   360,   368,   373,   373,   376,   375,   391,
     391,   393,   393,   393,   396,   395,   407,   406,   418,   417,
     428,   428,   431,   431,   433,   444,   445,   447,   447,   449,
     449,   449,   449,   449,   451,   453,   464,   465,   464,   473,
     474,   475,   480,   487,   489,   500,   501,   500,   509,   510,
     511,   516,   524,   526,   537,   538,   537,   548,   549,   550,
     555,   563,   565,   574,   575,   577,   576,   584,   586,   596,
     604,   609,   609,   612,   611,   626,   626,   628,   628,   628,
     631,   630,   642,   641,   654,   653,   664,   664,   667,   667,
     669,   680,   681,   683,   683,   685,   685,   687,   689,   699,
     700,   702,   701,   711,   713,   723,   731,   736,   736,   739,
     738,   753,   753,   755,   755,   755,   758,   757,   769,   768,
     780,   779,   790,   790,   793,   793,   795,   805,   806,   808,
     808,   810,   810,   810,   810,   810,   811,   811,   811,   811,
     811,   812,   812,   812,   812,   812,   815,   817,   828,   829,
     828,   838,   839,   840,   845,   852,   854,   864,   865,   866,
     866,   868,   870,   880,   887,   887,   890,   889,   902,   905,
     915,   922,   922,   924,   924,   936,   939,   949,   956,   956,
     958,   958,   970,   973,   982,   989,   989,   992,   991,  1003,
    1006,  1016,  1023,  1023,  1026,  1025,  1037,  1040,  1050,  1059,
    1059,  1061,  1073,  1079,  1079,  1081,  1081,  1081,  1084,  1083,
    1095,  1094,  1106,  1105,  1117,  1117,  1120,  1123,  1133,  1141,
    1141,  1143,  1155,  1161,  1161,  1163,  1163,  1163,  1166,  1165,
    1177,  1176,  1188,  1187,  1199,  1199,  1202,  1205,  1215,  1224,
    1224,  1226,  1238,  1244,  1244,  1246,  1246,  1246,  1249,  1248,
    1260,  1259,  1271,  1270,  1282,  1282,  1285,  1288,  1298,  1306,
    1306,  1308,  1320,  1326,  1326,  1328,  1328,  1328,  1331,  1330,
    1342,  1341,  1353,  1352,  1364,  1364,  1367,  1370,  1380,  1387,
    1387,  1390,  1389,  1401,  1404,  1414,  1421,  1421,  1424,  1423,
    1435,  1439,  1449,  1456,  1456,  1459,  1458,  1470,  1472,  1482,
    1490,  1495,  1495,  1498,  1497,  1512,  1512,  1514,  1514,  1514,
    1517,  1516,  1528,  1527,  1539,  1538,  1549,  1549,  1552,  1552,
    1554,  1564,  1564,  1566,  1566,  1566,  1568,  1574,  1580,  1586,
    1586,  1588,  1590,  1590,  1592,  1596,  1596,  1605,  1607,  1609,
    1609,  1611,  1621,  1621,  1623,  1631,  1636,  1636,  1638,  1638,
    1640,  1654,  1653,  1666,  1666,  1669,  1669,  1672,  1682,  1682,
    1684,  1692,  1697,  1697,  1699,  1699,  1701,  1715,  1714,  1722,
    1722,  1725,  1725,  1728,  1738,  1738,  1740,  1748,  1753,  1753,
    1755,  1755,  1757,  1771,  1770,  1778,  1778,  1781,  1781,  1784,
    1794,  1794,  1796,  1804,  1809,  1809,  1811,  1811,  1813,  1827,
    1826,  1839,  1839,  1842,  1842,  1845,  1856,  1856,  1858,  1870,
    1876,  1876,  1878,  1878,  1878,  1880,  1890,  1897,  1904,  1915,
    1916,  1918,  1918,  1920,  1928,  1933,  1933,  1935,  1935,  1937,
    1951,  1950,  1963,  1963,  1966,  1966,  1968,  1970,  1975,  1975,
    1978,  1979,  1980,  1981,  1982,  1983,  1984,  1986,  2000,  1999,
    2008,  2007,  2016,  2015,  2024,  2023,  2032,  2031,  2040,  2039,
    2048,  2065,  2065,  2067,  2077,  2082,  2082,  2085,  2086,  2087,
    2088,  2090,  2104,  2103,  2112,  2111,  2120,  2119,  2127,  2127,
    2131,  2131,  2133,  2137,  2137,  2146,  2147,  2149,  2149,  2152,
    2162,  2162,  2164,  2172,  2177,  2177,  2179,  2179,  2181,  2196,
    2195,  2208,  2208,  2211,  2211,  2214,  2224,  2224,  2226,  2235,
    2240,  2240,  2242,  2242,  2242,  2244,  2258,  2257,  2271,  2270,
    2283,  2283,  2287,  2287,  2289,  2291,  2296,  2296,  2299,  2300,
    2301,  2302,  2303,  2304,  2305,  2307,  2321,  2320,  2330,  2329,
    2339,  2338,  2348,  2347,  2357,  2356,  2366,  2365,  2375,  2392,
    2392,  2394,  2404,  2409,  2409,  2412,  2413,  2414,  2415,  2417,
    2432,  2431,  2441,  2440,  2450,  2449,  2458,  2458,  2461,  2461,
    2463,  2467,  2467,  2476,  2478,  2480,  2480,  2483,  2493,  2493,
    2495,  2503,  2508,  2508,  2510,  2510,  2512,  2527,  2526,  2539,
    2539,  2542,  2542,  2545,  2555,  2555,  2557,  2566,  2571,  2571,
    2573,  2573,  2573,  2575,  2589,  2588,  2602,  2601,  2615,  2615,
    2618,  2618,  2620,  2622,  2627,  2627,  2630,  2631,  2632,  2633,
    2634,  2635,  2636,  2638,  2652,  2651,  2660,  2659,  2668,  2667,
    2676,  2675,  2684,  2683,  2692,  2691,  2700,  2717,  2717,  2719,
    2729,  2734,  2734,  2737,  2738,  2739,  2740,  2742,  2757,  2756,
    2766,  2765,  2774,  2773,  2781,  2781,  2784,  2784,  2789,  2799,
    2807,  2807,  2810,  2809,  2827,  2827,  2830,  2831,  2832,  2833,
    2834,  2835,  2839,  2838,  2850,  2849,  2861,  2860,  2872,  2871,
    2883,  2882,  2894,  2893,  2905,  2905
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "ATTRIBUTETEXT", "ELEMENTTEXT",
  "INTEGER", "DOUBLE", "QUOTE", "TWOQUOTES", "GREATERTHAN", "ENDOFELEMENT",
  "OSOLSTART", "OSOLSTARTEMPTY", "OSOLATTRIBUTETEXT", "OSOLEND",
  "LOCATIONTYPEATT", "TRANSPORTTYPEATT", "NUMBEROFOTHEROPTIONSATT",
  "NUMBEROFJOBIDSATT", "NUMBEROFPATHSATT", "NUMBEROFPATHPAIRSATT",
  "FROMATT", "TOATT", "MAKECOPYATT", "SOLVERATT", "CATEGORYATT", "TYPEATT",
  "GROUPWEIGHTATT", "NUMBEROFPROCESSESATT", "NUMBEROFSOLVEROPTIONSATT",
  "NUMBEROFSOSATT", "NUMBEROFVARIABLESATT", "NUMBEROFOBJECTIVESATT",
  "NUMBEROFCONSTRAINTSATT", "NUMBEROFOTHERVARIABLEOPTIONSATT",
  "NUMBEROFOTHEROBJECTIVEOPTIONSATT", "NUMBEROFOTHERCONSTRAINTOPTIONSATT",
  "NUMBEROFVARATT", "NUMBEROFOBJATT", "NUMBEROFCONATT", "NAMEATT",
  "IDXATT", "SOSIDXATT", "VALUEATT", "UNITATT", "DESCRIPTIONATT",
  "LBVALUEATT", "UBVALUEATT", "LBDUALVALUEATT", "UBDUALVALUEATT",
  "GENERALSTART", "GENERALEND", "SYSTEMSTART", "SYSTEMEND", "SERVICESTART",
  "SERVICEEND", "JOBSTART", "JOBEND", "OPTIMIZATIONSTART",
  "OPTIMIZATIONEND", "SERVICEURISTART", "SERVICEURIEND",
  "SERVICENAMESTART", "SERVICENAMEEND", "INSTANCENAMESTART",
  "INSTANCENAMEEND", "INSTANCELOCATIONSTART", "INSTANCELOCATIONEND",
  "JOBIDSTART", "JOBIDEND", "SOLVERTOINVOKESTART", "SOLVERTOINVOKEEND",
  "LICENSESTART", "LICENSEEND", "USERNAMESTART", "USERNAMEEND",
  "PASSWORDSTART", "PASSWORDEND", "CONTACTSTART", "CONTACTEND",
  "OTHEROPTIONSSTART", "OTHEROPTIONSEND", "OTHERSTART", "OTHEREND",
  "MINDISKSPACESTART", "MINDISKSPACEEND", "MINMEMORYSIZESTART",
  "MINMEMORYSIZEEND", "MINCPUSPEEDSTART", "MINCPUSPEEDEND",
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
  "INITIALBASISSTATUSEND", "INTEGERVARIABLEBRANCHINGWEIGHTSSTART",
  "INTEGERVARIABLEBRANCHINGWEIGHTSEND", "SOSVARIABLEBRANCHINGWEIGHTSSTART",
  "SOSVARIABLEBRANCHINGWEIGHTSEND", "SOSSTART", "SOSEND",
  "OBJECTIVESSTART", "OBJECTIVESEND", "INITIALOBJECTIVEVALUESSTART",
  "INITIALOBJECTIVEVALUESEND", "OBJSTART", "OBJEND",
  "INITIALOBJECTIVEBOUNDSSTART", "INITIALOBJECTIVEBOUNDSEND",
  "CONSTRAINTSSTART", "CONSTRAINTSEND", "INITIALCONSTRAINTVALUESSTART",
  "INITIALCONSTRAINTVALUESEND", "CONSTART", "CONEND",
  "INITIALDUALVALUESSTART", "INITIALDUALVALUESEND", "SOLVEROPTIONSSTART",
  "SOLVEROPTIONSEND", "SOLVEROPTIONSTART", "SOLVEROPTIONEND", "DUMMY",
  "$accept", "osoldoc", "osolstart", "osolcontent", "osolgeneral",
  "generalhead", "generalbody", "generalcontent", "generaloption",
  "serviceURI", "serviceURIhead", "serviceURIbody", "@1", "servicename",
  "servicenamehead", "servicenamebody", "@2", "instancename",
  "instancenamehead", "instancenamebody", "@3", "instancelocation",
  "instancelocationhead", "locationtypeatt", "@4", "instancelocationbody",
  "instancelocationtext", "jobid", "jobidhead", "jobidbody", "@5",
  "solvertoinvoke", "solvertoinvokehead", "solvertoinvokebody", "@6",
  "license", "licensehead", "licensebody", "@7", "username",
  "usernamehead", "usernamebody", "@8", "password", "passwordhead",
  "passwordbody", "@9", "contact", "contacthead", "transporttypeatt",
  "@10", "contactbody", "contacttext", "othergeneraloptions",
  "othergeneraloptionshead", "numberofothergeneraloptions",
  "othergeneraloptionsbody", "othergeneraloptionslist",
  "othergeneraloption", "@11", "othergeneralattributes",
  "othergeneralattribute", "generaloptionnameatt", "@12",
  "generaloptionvalueatt", "@13", "generaloptiondescriptionatt", "@14",
  "othergeneraloptionend", "osolsystem", "systemhead", "systembody",
  "systemcontent", "systemoption", "mindiskspace", "mindiskspacehead",
  "mindiskspaceunit", "@15", "mindiskspacebody", "minmemorysize",
  "minmemorysizehead", "minmemoryunit", "@16", "minmemorysizebody",
  "mincpuspeed", "mincpuspeedhead", "mincpuspeedunit", "@17",
  "mincpuspeedbody", "mincpunumber", "mincpunumberhead",
  "mincpunumberbody", "@18", "othersystemoptions",
  "othersystemoptionshead", "numberofothersystemoptions",
  "othersystemoptionsbody", "othersystemoptionslist", "othersystemoption",
  "@19", "othersystemattributes", "othersystemattribute",
  "systemoptionnameatt", "@20", "systemoptionvalueatt", "@21",
  "systemoptiondescriptionatt", "@22", "othersystemoptionend",
  "osolservice", "servicehead", "servicebody", "servicecontent",
  "serviceoption", "servicetype", "servicetypehead", "servicetypebody",
  "@23", "otherserviceoptions", "otherserviceoptionshead",
  "numberofotherserviceoptions", "otherserviceoptionsbody",
  "otherserviceoptionslist", "otherserviceoption", "@24",
  "otherserviceattributes", "otherserviceattribute",
  "serviceoptionnameatt", "@25", "serviceoptionvalueatt", "@26",
  "serviceoptiondescriptionatt", "@27", "otherserviceoptionsend",
  "osoljob", "jobhead", "jobbody", "jobcontent", "joboption", "maxtime",
  "maxtimehead", "maxtimeunit", "@28", "maxtimebody", "requestedstarttime",
  "starttimehead", "starttimebody", "@29", "dependencies",
  "dependencieshead", "numberofjobidsatt", "dependencieslist",
  "dependencyjobid", "@30", "requireddirectories",
  "requireddirectorieshead", "numberofreqdirpathsatt", "reqdirpathlist",
  "reqdirpath", "@31", "requiredfiles", "requiredfileshead",
  "numberofreqfilespathsatt", "reqfilespathlist", "reqfilepath", "@32",
  "directoriestomake", "directoriestomakehead",
  "numberofdirtomakepathsatt", "dirtomakepathlist", "dirtomakepath", "@33",
  "filestomake", "filestomakehead", "numberoffilestomakepathsatt",
  "filestomakepathlist", "filestomakepath", "@34",
  "inputdirectoriestomove", "inputdirectoriestomovehead",
  "numberofindirtomovepathpairsatt", "indirtomovepathpairlist",
  "indirtomovepathpair", "indirtomovepathpairhead",
  "indirtomovepathpairattlist", "indirtomovepathpairatt",
  "indirtomovefromatt", "@35", "indirtomovetoatt", "@36",
  "indirtomovemakecopyatt", "@37", "indirtomovepathpairend",
  "inputfilestomove", "inputfilestomovehead",
  "numberofinfilestomovepathpairsatt", "infilestomovepathpairlist",
  "infilestomovepathpair", "infilestomovepathpairhead",
  "infilestomovepathpairattlist", "infilestomovepathpairatt",
  "infilestomovefromatt", "@38", "infilestomovetoatt", "@39",
  "infilestomovemakecopyatt", "@40", "infilestomovepathpairend",
  "outputdirectoriestomove", "outputdirectoriestomovehead",
  "numberofoutdirtomovepathpairsatt", "outdirtomovepathpairlist",
  "outdirtomovepathpair", "outdirtomovepathpairhead",
  "outdirtomovepathpairattlist", "outdirtomovepathpairatt",
  "outdirtomovefromatt", "@41", "outdirtomovetoatt", "@42",
  "outdirtomovemakecopyatt", "@43", "outdirtomovepathpairend",
  "outputfilestomove", "outputfilestomovehead",
  "numberofoutfilestomovepathpairsatt", "outfilestomovepathpairlist",
  "outfilestomovepathpair", "outfilestomovepathpairhead",
  "outfilestomovepathpairattlist", "outfilestomovepathpairatt",
  "outfilestomovefromatt", "@44", "outfilestomovetoatt", "@45",
  "outfilestomovemakecopyatt", "@46", "outfilestomovepathpairend",
  "filestodelete", "filestodeletehead", "numberoffilestodeletepathsatt",
  "filestodeletepathlist", "filestodeletepath", "@47",
  "directoriestodelete", "directoriestodeletehead",
  "numberofdirtodeletepathsatt", "dirtodeletepathlist", "dirtodeletepath",
  "@48", "processestokill", "processestokillhead",
  "numberofprocesstokillatt", "processestokilllist", "processtokill",
  "@49", "otherjoboptions", "otherjoboptionshead",
  "numberofotherjoboptions", "otherjoboptionsbody", "otherjoboptionslist",
  "otherjoboption", "@50", "otherjobattributes", "otherjobattribute",
  "joboptionnameatt", "@51", "joboptionvalueatt", "@52",
  "joboptiondescriptionatt", "@53", "otherjoboptionsend",
  "osoloptimization", "optimizationhead", "optimizationattlist",
  "optimizationatt", "optimizationnvar", "optimizationncon",
  "optimizationnobj", "optimizationbody", "optimizationcontent",
  "variables", "variablesstart", "numberofothervariablesatt",
  "restofvariables", "initialvariablevalues", "numberofvar", "varlist",
  "initvarvalue", "varstart", "initvarvalueattlist", "initvarvalueatt",
  "initvarvalueidxatt", "initvarvaluevalueatt", "@54", "initvarvalueend",
  "initialvariablevaluesstring", "numberofvarstr", "varstrlist",
  "initvarstrvalue", "varstrstart", "initvarstrvalueattlist",
  "initvarstrvalueatt", "initvarstrvalueidxatt", "initvarstrvaluevalueatt",
  "@55", "initvarstrvalueend", "initialbasisstatus", "numberofbasvar",
  "basvarlist", "initbasvalue", "basvarstart", "initbasvarvalueattlist",
  "initbasvarvalueatt", "initbasvarvalueidxatt", "initbasvarvaluevalueatt",
  "@56", "initbasvarvalueend", "integervariablebranchingweights",
  "numberofintegerweights", "intweightlist", "intweight", "intweightstart",
  "intweightattlist", "intweightatt", "intweightidxatt",
  "intweightvalueatt", "@57", "intweightend",
  "sosvariablebranchingweights", "numberofsosweightgroups",
  "sosweightgrouplist", "sosweightgroup", "sosweightgroupstart",
  "sosweightgroupattlist", "sosweightgroupatt", "sosweightgroupidxatt",
  "sosweightgroupweightatt", "sosweightgroupnvaratt",
  "sosweightgroupcontent", "sosweightgroupvars", "sosweightvar",
  "sosweightvarstart", "sosweightvarattlist", "sosweightvaratt",
  "sosweightvaridxatt", "sosweightvarvalueatt", "@58", "sosweightvarend",
  "othervariableoptionlist", "othervariableoption",
  "othervariableoptionstart", "othervariableoptionsattlist",
  "othervariableoptionsatt", "othervariableoptionnumberofvar",
  "othervariableoptionname", "@59", "othervariableoptionvalue", "@60",
  "othervariableoptionsolver", "@61", "othervariableoptioncategory", "@62",
  "othervariableoptiontype", "@63", "othervariableoptiondescription",
  "@64", "restofothervariableoption", "othervariableoptionsvarlist",
  "othervariableoptionsvar", "othervariableoptionsvarstart",
  "othervaroptionattlist", "othervaroptionatt", "othervaroptionidx",
  "othervaroptionvalue", "@65", "othervaroptionlbvalue", "@66",
  "othervaroptionubvalue", "@67", "othervaroptionend", "objectives",
  "objectivesstart", "numberofotherobjectivesatt", "restofobjectives",
  "initialobjectivevalues", "numberofobjval", "objvaluelist",
  "initobjvalue", "objvaluestart", "initobjvalueattlist",
  "initobjvalueatt", "initobjvalueidxatt", "initobjvaluevalueatt", "@68",
  "initobjvalueend", "initialobjectivebounds", "numberofobjbounds",
  "objboundlist", "initobjbound", "objboundstart", "initobjboundattlist",
  "initobjboundatt", "initobjboundidxatt", "initobjvaluelowerboundatt",
  "@69", "initobjvalueupperboundatt", "@70", "initobjboundend",
  "otherobjectiveoptionlist", "otherobjectiveoption",
  "otherobjectiveoptionstart", "otherobjectiveoptionsattlist",
  "otherobjectiveoptionsatt", "otherobjectiveoptionnumberofobj",
  "otherobjectiveoptionname", "@71", "otherobjectiveoptionvalue", "@72",
  "otherobjectiveoptionsolver", "@73", "otherobjectiveoptioncategory",
  "@74", "otherobjectiveoptiontype", "@75",
  "otherobjectiveoptiondescription", "@76", "restofotherobjectiveoption",
  "otherobjectiveoptionsobjlist", "otherobjectiveoptionsobj",
  "otherobjectiveoptionsobjstart", "otherobjoptionattlist",
  "otherobjoptionatt", "otherobjoptionidx", "otherobjoptionvalue", "@77",
  "otherobjoptionlbvalue", "@78", "otherobjoptionubvalue", "@79",
  "otherobjoptionend", "constraints", "constraintsstart",
  "numberofotherconstraintsatt", "restofconstraints",
  "initialconstraintvalues", "numberofconval", "conlist", "initconvalue",
  "constart", "initconvalueattlist", "initconvalueatt",
  "initconvalueidxatt", "initconvaluevalueatt", "@80", "initconvalueend",
  "initialdualvalues", "numberofduals", "duallist", "initdualvalue",
  "dualstart", "initdualvalueattlist", "initdualvalueatt",
  "initdualvalueidxatt", "initdualvaluelowerboundatt", "@81",
  "initdualvalueupperboundatt", "@82", "initdualvalueend",
  "otherconstraintoptionlist", "otherconstraintoption",
  "otherconstraintoptionstart", "otherconstraintoptionsattlist",
  "otherconstraintoptionsatt", "otherconstraintoptionnumberofcon",
  "otherconstraintoptionname", "@83", "otherconstraintoptionvalue", "@84",
  "otherconstraintoptionsolver", "@85", "otherconstraintoptioncategory",
  "@86", "otherconstraintoptiontype", "@87",
  "otherconstraintoptiondescription", "@88", "restofotherconstraintoption",
  "otherconstraintoptionsconlist", "otherconstraintoptionscon",
  "otherconstraintoptionsconstart", "otherconoptionattlist",
  "otherconoptionatt", "otherconoptionidx", "otherconoptionvalue", "@89",
  "otherconoptionlbvalue", "@90", "otherconoptionubvalue", "@91",
  "otherconoptionend", "solveroptions", "solveroptionsstart",
  "numberofsolveroptionsatt", "solveroptionlist", "solveroption", "@92",
  "solveroptionattlist", "solveroptionatt", "solveroptionname", "@93",
  "solveroptionvalue", "@94", "solveroptionsolver", "@95",
  "solveroptioncategory", "@96", "solveroptiontype", "@97",
  "solveroptiondescription", "@98", "solveroptionend", 0
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
     415,   416,   417,   418,   419
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   165,   166,   166,   167,   167,   168,   169,   169,   170,
     171,   171,   172,   172,   173,   173,   173,   173,   173,   173,
     173,   173,   173,   173,   173,   174,   175,   176,   176,   177,
     176,   178,   179,   180,   180,   181,   180,   182,   183,   184,
     184,   185,   184,   186,   187,   188,   189,   188,   190,   190,
     191,   191,   192,   193,   194,   194,   195,   194,   196,   197,
     198,   198,   199,   198,   200,   201,   202,   202,   203,   202,
     204,   205,   206,   206,   207,   206,   208,   209,   210,   210,
     211,   210,   212,   213,   214,   215,   214,   216,   216,   217,
     217,   218,   219,   220,   221,   222,   222,   224,   223,   225,
     225,   226,   226,   226,   228,   227,   230,   229,   232,   231,
     233,   233,   234,   234,   235,   236,   236,   237,   237,   238,
     238,   238,   238,   238,   239,   240,   241,   242,   241,   243,
     243,   243,   243,   244,   245,   246,   247,   246,   248,   248,
     248,   248,   249,   250,   251,   252,   251,   253,   253,   253,
     253,   254,   255,   256,   256,   257,   256,   258,   259,   260,
     261,   262,   262,   264,   263,   265,   265,   266,   266,   266,
     268,   267,   270,   269,   272,   271,   273,   273,   274,   274,
     275,   276,   276,   277,   277,   278,   278,   279,   280,   281,
     281,   282,   281,   283,   284,   285,   286,   287,   287,   289,
     288,   290,   290,   291,   291,   291,   293,   292,   295,   294,
     297,   296,   298,   298,   299,   299,   300,   301,   301,   302,
     302,   303,   303,   303,   303,   303,   303,   303,   303,   303,
     303,   303,   303,   303,   303,   303,   304,   305,   306,   307,
     306,   308,   308,   308,   308,   309,   310,   311,   311,   312,
     311,   313,   314,   315,   316,   316,   318,   317,   319,   320,
     321,   322,   322,   324,   323,   325,   326,   327,   328,   328,
     330,   329,   331,   332,   333,   334,   334,   336,   335,   337,
     338,   339,   340,   340,   342,   341,   343,   344,   345,   346,
     346,   347,   348,   349,   349,   350,   350,   350,   352,   351,
     354,   353,   356,   355,   357,   357,   358,   359,   360,   361,
     361,   362,   363,   364,   364,   365,   365,   365,   367,   366,
     369,   368,   371,   370,   372,   372,   373,   374,   375,   376,
     376,   377,   378,   379,   379,   380,   380,   380,   382,   381,
     384,   383,   386,   385,   387,   387,   388,   389,   390,   391,
     391,   392,   393,   394,   394,   395,   395,   395,   397,   396,
     399,   398,   401,   400,   402,   402,   403,   404,   405,   406,
     406,   408,   407,   409,   410,   411,   412,   412,   414,   413,
     415,   416,   417,   418,   418,   420,   419,   421,   422,   423,
     424,   425,   425,   427,   426,   428,   428,   429,   429,   429,
     431,   430,   433,   432,   435,   434,   436,   436,   437,   437,
     438,   439,   439,   440,   440,   440,   441,   442,   443,   444,
     444,   445,   446,   446,   447,   448,   448,   449,   449,   450,
     450,   451,   452,   452,   453,   454,   455,   455,   456,   456,
     457,   459,   458,   460,   460,   461,   461,   462,   463,   463,
     464,   465,   466,   466,   467,   467,   468,   470,   469,   471,
     471,   472,   472,   473,   474,   474,   475,   476,   477,   477,
     478,   478,   479,   481,   480,   482,   482,   483,   483,   484,
     485,   485,   486,   487,   488,   488,   489,   489,   490,   492,
     491,   493,   493,   494,   494,   495,   496,   496,   497,   498,
     499,   499,   500,   500,   500,   501,   502,   502,   503,   504,
     504,   505,   505,   506,   507,   508,   508,   509,   509,   510,
     512,   511,   513,   513,   514,   514,   515,   516,   517,   517,
     518,   518,   518,   518,   518,   518,   518,   519,   521,   520,
     523,   522,   525,   524,   527,   526,   529,   528,   531,   530,
     532,   533,   533,   534,   535,   536,   536,   537,   537,   537,
     537,   538,   540,   539,   542,   541,   544,   543,   545,   545,
     546,   546,   547,   548,   548,   549,   549,   550,   550,   551,
     552,   552,   553,   554,   555,   555,   556,   556,   557,   559,
     558,   560,   560,   561,   561,   562,   563,   563,   564,   565,
     566,   566,   567,   567,   567,   568,   570,   569,   572,   571,
     573,   573,   574,   574,   575,   576,   577,   577,   578,   578,
     578,   578,   578,   578,   578,   579,   581,   580,   583,   582,
     585,   584,   587,   586,   589,   588,   591,   590,   592,   593,
     593,   594,   595,   596,   596,   597,   597,   597,   597,   598,
     600,   599,   602,   601,   604,   603,   605,   605,   606,   606,
     607,   608,   608,   609,   609,   610,   610,   611,   612,   612,
     613,   614,   615,   615,   616,   616,   617,   619,   618,   620,
     620,   621,   621,   622,   623,   623,   624,   625,   626,   626,
     627,   627,   627,   628,   630,   629,   632,   631,   633,   633,
     634,   634,   635,   636,   637,   637,   638,   638,   638,   638,
     638,   638,   638,   639,   641,   640,   643,   642,   645,   644,
     647,   646,   649,   648,   651,   650,   652,   653,   653,   654,
     655,   656,   656,   657,   657,   657,   657,   658,   660,   659,
     662,   661,   664,   663,   665,   665,   666,   666,   667,   668,
     669,   669,   671,   670,   672,   672,   673,   673,   673,   673,
     673,   673,   675,   674,   677,   676,   679,   678,   681,   680,
     683,   682,   685,   684,   686,   686
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     3,     2,     1,     3,     5,     0,     2,     1,
       3,     1,     0,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     2,     1,     1,     2,     0,
       4,     2,     1,     1,     2,     0,     4,     2,     1,     1,
       2,     0,     4,     3,     1,     0,     0,     4,     1,     3,
       0,     1,     2,     1,     1,     2,     0,     4,     2,     1,
       1,     2,     0,     4,     2,     1,     1,     2,     0,     4,
       2,     1,     1,     2,     0,     4,     2,     1,     1,     2,
       0,     4,     3,     1,     0,     0,     4,     1,     3,     0,
       1,     4,     1,     4,     2,     0,     2,     0,     4,     0,
       2,     1,     1,     1,     0,     4,     0,     4,     0,     4,
       1,     2,     0,     2,     1,     3,     1,     0,     2,     1,
       1,     1,     1,     1,     3,     1,     0,     0,     4,     1,
       2,     3,     3,     3,     1,     0,     0,     4,     1,     2,
       3,     3,     3,     1,     0,     0,     4,     1,     2,     3,
       3,     2,     1,     1,     2,     0,     4,     4,     1,     4,
       2,     0,     2,     0,     4,     0,     2,     1,     1,     1,
       0,     4,     0,     4,     0,     4,     1,     2,     0,     2,
       1,     3,     1,     0,     2,     1,     1,     2,     1,     1,
       2,     0,     4,     4,     1,     4,     2,     0,     2,     0,
       4,     0,     2,     1,     1,     1,     0,     4,     0,     4,
       0,     4,     1,     2,     0,     2,     1,     3,     1,     0,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     3,     1,     0,     0,
       4,     1,     2,     3,     3,     2,     1,     1,     2,     0,
       4,     5,     1,     4,     0,     2,     0,     5,     5,     1,
       4,     0,     2,     0,     5,     5,     1,     4,     0,     2,
       0,     5,     5,     1,     4,     0,     2,     0,     5,     5,
       1,     4,     0,     2,     0,     5,     5,     1,     4,     0,
       2,     3,     1,     0,     2,     1,     1,     1,     0,     4,
       0,     4,     0,     4,     2,     1,     5,     1,     4,     0,
       2,     3,     1,     0,     2,     1,     1,     1,     0,     4,
       0,     4,     0,     4,     2,     1,     5,     1,     4,     0,
       2,     3,     1,     0,     2,     1,     1,     1,     0,     4,
       0,     4,     0,     4,     2,     1,     5,     1,     4,     0,
       2,     3,     1,     0,     2,     1,     1,     1,     0,     4,
       0,     4,     0,     4,     2,     1,     5,     1,     4,     0,
       2,     0,     5,     5,     1,     4,     0,     2,     0,     5,
       5,     1,     4,     0,     2,     0,     5,     4,     1,     4,
       2,     0,     2,     0,     4,     0,     2,     1,     1,     1,
       0,     4,     0,     4,     0,     4,     1,     2,     0,     3,
       1,     0,     2,     1,     1,     1,     4,     4,     4,     3,
       1,     4,     0,     3,     1,     0,     4,     8,     1,     0,
       5,     4,     0,     2,     3,     1,     0,     2,     1,     1,
       4,     0,     4,     2,     1,     0,     5,     4,     0,     2,
       3,     1,     0,     2,     1,     1,     4,     0,     4,     2,
       1,     0,     5,     4,     0,     2,     3,     1,     0,     2,
       1,     1,     4,     0,     4,     2,     1,     0,     5,     4,
       0,     2,     3,     1,     0,     2,     1,     1,     4,     0,
       4,     2,     1,     0,     5,     4,     0,     2,     3,     1,
       0,     2,     1,     1,     1,     4,     4,     4,     4,     3,
       1,     0,     2,     3,     1,     0,     2,     1,     1,     4,
       0,     4,     2,     1,     0,     2,     3,     1,     0,     2,
       1,     1,     1,     1,     1,     1,     1,     4,     0,     4,
       0,     4,     0,     4,     0,     4,     0,     4,     0,     4,
       3,     0,     2,     3,     1,     0,     2,     1,     1,     1,
       1,     4,     0,     4,     0,     4,     0,     4,     2,     1,
       0,     3,     1,     0,     4,     5,     1,     0,     5,     4,
       0,     2,     3,     1,     0,     2,     1,     1,     4,     0,
       4,     2,     1,     0,     5,     4,     0,     2,     3,     1,
       0,     2,     1,     1,     1,     4,     0,     4,     0,     4,
       2,     1,     0,     2,     3,     1,     0,     2,     1,     1,
       1,     1,     1,     1,     1,     4,     0,     4,     0,     4,
       0,     4,     0,     4,     0,     4,     0,     4,     3,     0,
       2,     3,     1,     0,     2,     1,     1,     1,     1,     4,
       0,     4,     0,     4,     0,     4,     2,     1,     0,     3,
       1,     0,     4,     5,     1,     0,     5,     4,     0,     2,
       3,     1,     0,     2,     1,     1,     4,     0,     4,     2,
       1,     0,     5,     4,     0,     2,     3,     1,     0,     2,
       1,     1,     1,     4,     0,     4,     0,     4,     2,     1,
       0,     2,     3,     1,     0,     2,     1,     1,     1,     1,
       1,     1,     1,     4,     0,     4,     0,     4,     0,     4,
       0,     4,     0,     4,     0,     4,     3,     0,     2,     3,
       1,     0,     2,     1,     1,     1,     1,     4,     0,     4,
       0,     4,     0,     4,     2,     1,     0,     5,     1,     4,
       0,     2,     0,     4,     0,     2,     1,     1,     1,     1,
       1,     1,     0,     4,     0,     4,     0,     4,     0,     4,
       0,     4,     0,     4,     2,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       0,     0,     4,     0,     7,     0,     1,     3,     9,     0,
     112,     0,     5,     2,   114,   178,     0,    12,    11,     8,
     180,   214,     0,   117,   116,   113,     0,   216,   408,     0,
     183,   182,   179,     0,    10,    26,    32,    38,    44,    53,
      59,    65,    71,    77,    83,    92,    13,    14,     0,    15,
       0,    16,     0,    17,    45,    18,     0,    19,     0,    20,
       0,    21,     0,    22,     0,    23,    84,    24,     0,   410,
       6,   411,   219,   218,   215,     0,   115,   158,   125,   134,
     143,   152,   118,   119,   126,   120,   135,   121,   144,   122,
       0,   123,     0,     0,    27,    25,     0,    33,    31,     0,
      39,    37,     0,     0,     0,    54,    52,     0,    60,    58,
       0,    66,    64,     0,    72,    70,     0,    78,    76,     0,
       0,     0,     0,     0,     0,   181,   194,   188,   184,   185,
       0,   186,     0,     0,     0,     0,     0,     0,     0,     0,
     153,   151,     0,     0,    29,    28,    35,    34,    41,    40,
      46,    50,    48,    43,    56,    55,    62,    61,    68,    67,
      74,    73,    80,    79,    85,    89,    87,    82,     0,    95,
     422,   420,     0,     0,     0,   412,   413,   414,   415,   409,
     217,   388,   237,   246,   252,   259,   266,   273,   280,   374,
     367,   287,   307,   327,   347,   381,   220,   221,   238,   222,
       0,   223,     0,   224,     0,   225,     0,   226,     0,   227,
       0,   228,     0,   229,     0,   230,     0,   231,     0,   232,
       0,   233,     0,   234,     0,   235,     0,     0,   189,   187,
       0,     0,   127,     0,   129,   124,   136,     0,   138,   133,
     145,     0,   147,   142,   155,   154,     0,   161,     0,     0,
       0,     0,    51,     0,     0,     0,     0,     0,     0,     0,
      90,     0,     0,    91,     0,   424,     0,   570,   425,     0,
       0,     0,     0,     0,     0,   247,   245,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   191,   190,     0,   197,     0,     0,     0,
     130,     0,     0,     0,   139,     0,     0,     0,   148,     0,
       0,   157,     0,    30,    36,    42,    47,    49,    57,    63,
      69,    75,    81,    86,    88,    93,    94,    97,    96,   419,
     572,   658,   573,     0,     0,     0,     0,     0,   239,     0,
     241,   236,   249,   248,     0,   254,     0,   261,     0,   268,
       0,   275,     0,   282,     0,   289,     0,   309,     0,   329,
       0,   349,     0,   369,     0,   376,     0,   383,     0,   391,
       0,     0,   193,     0,   128,   132,   131,   137,   141,   140,
     146,   150,   149,   156,   159,   160,   163,   162,    99,   660,
     746,   661,     0,     0,     0,   429,   428,   423,   416,   418,
     417,     0,     0,     0,   242,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   387,     0,   192,   195,   196,   199,   198,   165,     0,
     748,   421,     0,     0,     0,     0,   577,   576,   571,     0,
       0,   445,   240,   244,   243,   250,   253,     0,   251,   255,
     260,   258,     0,   262,   267,   265,     0,   269,   274,     0,
     272,   276,   281,     0,   279,   283,   288,   292,   286,   290,
     293,   308,   312,   306,   310,   313,   328,   332,   326,   330,
     333,   348,   352,   346,   350,   353,   368,     0,   366,   370,
     375,     0,   373,   377,   382,   380,     0,   384,   389,   390,
     393,   392,   201,     0,     0,   110,     0,     0,     0,   100,
     101,   102,   103,    98,     0,     0,     0,   665,   664,   659,
       0,     0,   593,   426,     0,     0,     0,   461,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     395,     0,     0,   176,     0,     0,     0,   166,   167,   168,
     169,   164,   111,   104,   106,   108,     0,   750,     0,     0,
     681,   574,     0,     0,     0,   612,     0,   432,     0,     0,
       0,   477,   256,   263,   270,   277,   284,     0,   305,     0,
       0,     0,   294,   295,   296,   297,   291,     0,   325,     0,
       0,     0,   314,   315,   316,   317,   311,     0,   345,     0,
       0,     0,   334,   335,   336,   337,   331,     0,   365,     0,
       0,     0,   354,   355,   356,   357,   351,   371,   378,   385,
       0,     0,   212,     0,     0,     0,   202,   203,   204,   205,
     200,   177,   170,   172,   174,     0,     0,     0,     0,     0,
     662,     0,     0,     0,   700,     0,   580,     0,     0,     0,
       0,     0,     0,   448,     0,     0,     0,   493,     0,     0,
       0,     0,     0,   304,   298,   300,   302,   324,   318,   320,
     322,   344,   338,   340,   342,   364,   358,   360,   362,     0,
       0,     0,     0,   406,     0,     0,     0,   396,   397,   398,
     399,   394,   213,   206,   208,   210,     0,     0,     0,   105,
     107,   109,   749,   747,   752,   751,     0,   668,     0,     0,
       0,     0,     0,     0,   596,   615,   575,   613,   616,   431,
     430,   435,   433,   436,     0,     0,     0,   464,     0,     0,
       0,   524,   257,   264,   271,   278,   285,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   372,
     379,   386,   407,   400,   402,   404,     0,     0,     0,   171,
     173,   175,   754,     0,     0,     0,   684,   703,   663,   701,
     704,   579,   578,   583,   581,   584,     0,     0,     0,     0,
     447,   451,   446,   449,   452,     0,     0,     0,   480,     0,
       0,     0,   299,   301,   303,   319,   321,   323,   339,   341,
     343,   359,   361,   363,     0,     0,     0,   207,   209,   211,
       0,   667,   666,   671,   669,   672,     0,     0,     0,     0,
     595,   599,   594,   597,   600,   639,     0,     0,     0,     0,
       0,     0,     0,   617,   618,   619,   620,   621,   622,   623,
     624,   614,     0,   444,     0,     0,   437,   438,   439,   434,
       0,   463,   467,   462,   465,   468,     0,     0,     0,   496,
     527,   427,   525,   528,   401,   403,   405,     0,   775,     0,
       0,     0,     0,     0,     0,   755,   756,   757,   758,   759,
     760,   761,   753,     0,   683,   687,   682,   685,   688,   727,
       0,     0,     0,     0,     0,     0,     0,   705,   706,   707,
     708,   709,   710,   711,   712,   702,     0,   592,     0,     0,
     585,   586,   587,   582,     0,     0,   630,   632,   634,     0,
     626,   628,   636,   443,     0,   441,     0,   460,     0,     0,
     453,   454,   455,   450,     0,   479,   483,   478,   481,   484,
       0,     0,     0,   774,   766,   768,   770,   762,   764,   772,
       0,   680,     0,     0,   673,   674,   675,   670,     0,     0,
     718,   720,   722,     0,   714,   716,   724,   591,     0,   589,
       0,   611,     0,     0,     0,   601,   602,   603,   604,   598,
     638,   642,   640,   643,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   459,     0,   457,     0,   476,     0,     0,
     469,   470,   471,   466,     0,   495,   494,   499,   497,   500,
     551,     0,     0,     0,     0,     0,     0,     0,   529,   530,
     531,   532,   533,   534,   535,   536,   526,     0,     0,     0,
       0,     0,     0,   679,     0,   677,     0,   699,     0,     0,
       0,   689,   690,   691,   692,   686,   726,   730,   728,   731,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   610,
       0,   606,   608,     0,   631,   633,   635,   625,   627,   629,
     637,   440,   442,     0,     0,   475,     0,   473,     0,   492,
       0,     0,   485,   486,   487,   482,     0,     0,   542,   544,
     546,     0,   538,   540,   548,   767,   769,   771,   763,   765,
     773,     0,     0,   698,     0,   694,   696,     0,   719,   721,
     723,   713,   715,   717,   725,   588,   590,     0,     0,     0,
       0,   657,     0,     0,     0,     0,   644,   645,   646,   647,
     648,   641,   456,   458,     0,     0,   491,     0,   489,   511,
     510,     0,     0,     0,   501,   502,   504,   503,   498,   550,
     554,   552,   555,     0,     0,     0,     0,     0,     0,     0,
     676,   678,     0,     0,     0,     0,   745,     0,     0,     0,
       0,   732,   733,   734,   735,   736,   729,   605,   607,   609,
     656,     0,   650,   652,   654,   472,   474,     0,     0,     0,
       0,     0,     0,     0,   543,   545,   547,   537,   539,   541,
     549,   693,   695,   697,   744,     0,   738,   740,   742,     0,
       0,     0,     0,   488,   490,   514,   509,   512,   515,     0,
       0,     0,     0,     0,   569,     0,     0,     0,     0,   556,
     557,   558,   559,   560,   553,     0,     0,     0,     0,   649,
     651,   653,   655,     0,   507,   506,   508,   505,   568,     0,
     562,   564,   566,   737,   739,   741,   743,     0,   523,     0,
       0,   516,   517,   518,   513,     0,     0,     0,     0,   522,
       0,   520,   561,   563,   565,   567,     0,     0,   519,   521
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     3,     4,     9,    10,    11,    19,    26,    46,    47,
      48,    95,   248,    49,    50,    98,   249,    51,    52,   101,
     250,    53,    54,   103,   251,   153,   253,    55,    56,   106,
     254,    57,    58,   109,   255,    59,    60,   112,   256,    61,
      62,   115,   257,    63,    64,   118,   258,    65,    66,   120,
     259,   167,   261,    67,    68,   122,   263,   264,   338,   398,
     449,   529,   530,   655,   531,   656,   532,   657,   533,    15,
      16,    25,    33,    82,    83,    84,   134,   307,   235,    85,
      86,   136,   311,   239,    87,    88,   138,   315,   243,    89,
      90,   141,   319,    91,    92,   143,   321,   322,   397,   448,
     523,   567,   568,   716,   569,   717,   570,   718,   571,    21,
      22,    32,    75,   128,   129,   130,   229,   380,   131,   132,
     231,   382,   383,   447,   522,   561,   646,   647,   776,   648,
     777,   649,   778,   650,    28,    29,    74,   124,   196,   197,
     198,   273,   411,   351,   199,   200,   276,   415,   201,   202,
     278,   417,   469,   678,   203,   204,   280,   419,   473,   679,
     205,   206,   282,   421,   477,   680,   207,   208,   284,   423,
     481,   681,   209,   210,   286,   425,   485,   682,   211,   212,
     288,   427,   489,   490,   553,   602,   603,   757,   604,   758,
     605,   759,   606,   213,   214,   290,   429,   494,   495,   554,
     612,   613,   760,   614,   761,   615,   762,   616,   215,   216,
     292,   431,   499,   500,   555,   622,   623,   763,   624,   764,
     625,   765,   626,   217,   218,   294,   433,   504,   505,   556,
     632,   633,   766,   634,   767,   635,   768,   636,   219,   220,
     296,   435,   509,   699,   221,   222,   298,   437,   513,   700,
     223,   224,   300,   439,   517,   701,   225,   226,   302,   441,
     442,   521,   560,   640,   707,   708,   824,   709,   825,   710,
     826,   711,    70,    71,   123,   175,   176,   177,   178,   179,
     266,   267,   268,   344,   407,   461,   545,   671,   742,   743,
     799,   866,   867,   868,  1012,   869,   547,   589,   745,   803,
     804,   870,   950,   951,   952,  1094,   953,   591,   675,   806,
     874,   875,   954,  1020,  1021,  1022,  1155,  1023,   677,   749,
     877,   958,   959,  1024,  1102,  1103,  1104,  1208,  1105,   751,
     810,   961,  1028,  1029,  1106,  1164,  1165,  1166,  1167,  1168,
    1209,  1237,  1238,  1263,  1281,  1282,  1283,  1297,  1284,   811,
     882,   883,   962,  1038,  1039,  1040,  1177,  1041,  1178,  1042,
    1173,  1043,  1174,  1044,  1175,  1045,  1179,  1046,  1107,  1171,
    1172,  1213,  1249,  1250,  1251,  1286,  1252,  1287,  1253,  1288,
    1254,   341,   342,   403,   458,   542,   583,   732,   794,   795,
     839,   930,   931,   932,  1078,   933,   585,   668,   797,   843,
     844,   934,   995,   996,   997,  1138,   998,  1139,   999,   669,
     737,   738,   798,   853,   854,   855,  1008,   856,  1009,   857,
    1004,   858,  1005,   859,  1006,   860,  1010,   861,   935,  1002,
    1003,  1083,  1146,  1147,  1148,  1230,  1149,  1231,  1150,  1232,
    1151,   400,   401,   454,   539,   580,   662,   784,   834,   835,
     903,   974,   975,   976,  1122,   977,   664,   729,   837,   907,
     908,   978,  1061,  1062,  1063,  1183,  1064,  1184,  1065,   730,
     789,   790,   838,   917,   918,   919,  1074,   920,  1075,   921,
    1070,   922,  1071,   923,  1072,   924,  1076,   925,   979,  1068,
    1069,  1127,  1191,  1192,  1193,  1256,  1194,  1257,  1195,  1258,
    1196,   451,   452,   535,   659,   725,   782,   830,   895,   896,
    1050,   897,  1051,   898,  1047,   899,  1048,   900,  1049,   901,
    1052,   902
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -103
static const yytype_int16 yypact[] =
{
     138,    27,  -103,    42,    18,    54,  -103,  -103,  -103,    62,
      44,   174,  -103,  -103,  -103,    46,   233,  -103,  -103,  -103,
    -103,    48,   260,  -103,  -103,  -103,   211,  -103,    40,   291,
    -103,  -103,  -103,   -31,  -103,  -103,  -103,  -103,  -103,  -103,
    -103,  -103,  -103,  -103,  -103,  -103,  -103,  -103,   293,  -103,
     304,  -103,   306,  -103,    87,  -103,   308,  -103,   310,  -103,
     312,  -103,   314,  -103,   316,  -103,    92,  -103,    95,  -103,
    -103,  -103,  -103,  -103,  -103,   -19,  -103,  -103,  -103,  -103,
    -103,  -103,  -103,  -103,    70,  -103,    72,  -103,    74,  -103,
     318,  -103,   103,    20,  -103,  -103,    15,  -103,  -103,    14,
    -103,  -103,   131,   320,    13,  -103,  -103,    16,  -103,  -103,
      12,  -103,  -103,    11,  -103,  -103,     7,  -103,  -103,   152,
     322,   115,   168,   121,     3,  -103,  -103,  -103,  -103,  -103,
     324,  -103,   107,   158,   326,   195,   328,   213,   330,    -1,
    -103,  -103,   189,   196,  -103,  -103,  -103,  -103,  -103,  -103,
    -103,   223,  -103,  -103,  -103,  -103,  -103,  -103,  -103,  -103,
    -103,  -103,  -103,  -103,  -103,   244,  -103,  -103,   246,  -103,
     111,  -103,   247,   250,   253,  -103,  -103,  -103,  -103,  -103,
    -103,  -103,  -103,  -103,  -103,  -103,  -103,  -103,  -103,  -103,
    -103,  -103,  -103,  -103,  -103,  -103,  -103,  -103,   228,  -103,
     332,  -103,   249,  -103,   255,  -103,   257,  -103,   259,  -103,
     261,  -103,   245,  -103,   264,  -103,   268,  -103,   274,  -103,
     263,  -103,   267,  -103,   269,  -103,   273,     1,  -103,  -103,
     360,   361,  -103,     4,  -103,  -103,  -103,     8,  -103,  -103,
    -103,     2,  -103,  -103,  -103,  -103,   370,  -103,   317,   319,
     315,   372,  -103,   321,   323,   313,   325,   311,   327,   374,
    -103,   329,   376,  -103,   262,  -103,   331,   241,   353,   384,
     386,   388,   391,   336,    -4,  -103,  -103,   389,   390,   393,
     392,   395,   394,   398,   397,   400,   401,   402,   403,   404,
     405,   406,   407,   408,   409,   410,   411,   412,   413,   414,
     415,   416,   417,  -103,  -103,   420,  -103,   421,   342,   345,
    -103,   422,   346,   347,  -103,   424,   343,   348,  -103,   349,
     428,  -103,   266,  -103,  -103,  -103,  -103,  -103,  -103,  -103,
    -103,  -103,  -103,  -103,  -103,  -103,  -103,  -103,  -103,  -103,
    -103,   243,   362,   429,   340,   431,   432,   434,  -103,    -3,
    -103,  -103,  -103,  -103,   437,  -103,   438,  -103,   439,  -103,
     440,  -103,   441,  -103,   442,  -103,   443,  -103,   444,  -103,
     445,  -103,   446,  -103,   447,  -103,   448,  -103,   449,  -103,
     363,   450,  -103,   270,  -103,  -103,  -103,  -103,  -103,  -103,
    -103,  -103,  -103,  -103,  -103,  -103,  -103,  -103,  -103,  -103,
     295,   423,   451,   344,   455,   333,  -103,  -103,  -103,  -103,
    -103,   454,   367,   369,  -103,   371,   458,   -37,   459,    38,
     460,   252,   462,    28,   463,   -67,   464,   -63,   465,   -71,
     466,   -74,   467,   -77,   468,   -59,   469,   -33,   470,   232,
     471,  -103,   278,  -103,  -103,  -103,  -103,  -103,  -103,    24,
    -103,  -103,   452,   472,   352,   475,   337,  -103,  -103,   477,
     453,   351,  -103,  -103,  -103,  -103,  -103,   473,  -103,  -103,
    -103,  -103,   478,  -103,  -103,  -103,   479,  -103,  -103,   480,
    -103,  -103,  -103,   482,  -103,  -103,  -103,  -103,  -103,  -103,
    -103,  -103,  -103,  -103,  -103,  -103,  -103,  -103,  -103,  -103,
    -103,  -103,  -103,  -103,  -103,  -103,  -103,   483,  -103,  -103,
    -103,   484,  -103,  -103,  -103,  -103,   485,  -103,  -103,  -103,
    -103,  -103,  -103,   172,   418,  -103,   492,   493,   494,  -103,
    -103,  -103,  -103,  -103,   491,   490,   481,   350,  -103,  -103,
     495,   474,   355,  -103,   496,   497,   476,   364,   503,   504,
     505,   506,   507,    29,   283,   286,   289,   510,   511,   512,
    -103,   193,   435,  -103,   514,   516,   517,  -103,  -103,  -103,
    -103,  -103,  -103,  -103,  -103,  -103,   518,  -103,   515,   486,
     366,  -103,   519,   520,   489,  -103,   523,  -103,   524,   521,
     498,   383,  -103,  -103,  -103,  -103,  -103,   425,  -103,   530,
     531,   533,  -103,  -103,  -103,  -103,  -103,   430,  -103,   535,
     536,   537,  -103,  -103,  -103,  -103,  -103,   436,  -103,   538,
     539,   541,  -103,  -103,  -103,  -103,  -103,   456,  -103,   542,
     543,   544,  -103,  -103,  -103,  -103,  -103,  -103,  -103,  -103,
     201,   487,  -103,   545,   546,   547,  -103,  -103,  -103,  -103,
    -103,  -103,  -103,  -103,  -103,   548,   549,   550,   551,   202,
    -103,   552,   553,   513,  -103,   555,  -103,   554,   556,   -70,
     557,   234,   561,  -103,   560,   559,   532,   433,   502,   488,
     499,   500,   501,  -103,  -103,  -103,  -103,  -103,  -103,  -103,
    -103,  -103,  -103,  -103,  -103,  -103,  -103,  -103,  -103,   508,
     509,   426,   525,  -103,   569,   571,   572,  -103,  -103,  -103,
    -103,  -103,  -103,  -103,  -103,  -103,   570,   573,   574,  -103,
    -103,  -103,  -103,  -103,  -103,  -103,   577,  -103,   576,   567,
     -76,   578,   221,   579,  -103,  -103,  -103,  -103,  -103,  -103,
    -103,  -103,  -103,  -103,   580,    36,   581,  -103,   582,   583,
     558,  -103,  -103,  -103,  -103,  -103,  -103,   584,   587,   588,
     589,   590,   591,   592,   593,   594,   595,   596,   600,  -103,
    -103,  -103,  -103,  -103,  -103,  -103,   602,   603,   604,  -103,
    -103,  -103,  -103,   605,   216,   585,  -103,  -103,  -103,  -103,
    -103,  -103,  -103,  -103,  -103,  -103,   608,    89,   150,   148,
    -103,  -103,  -103,  -103,  -103,   609,    19,   612,  -103,   611,
     610,   -57,  -103,  -103,  -103,  -103,  -103,  -103,  -103,  -103,
    -103,  -103,  -103,  -103,   613,   614,   615,  -103,  -103,  -103,
     154,  -103,  -103,  -103,  -103,  -103,   616,   -11,   161,   204,
    -103,  -103,  -103,  -103,  -103,  -103,   575,   621,   622,   619,
     624,   625,   626,  -103,  -103,  -103,  -103,  -103,  -103,  -103,
    -103,  -103,   522,  -103,   623,   628,  -103,  -103,  -103,  -103,
     209,  -103,  -103,  -103,  -103,  -103,   627,    -6,   630,  -103,
    -103,  -103,  -103,  -103,  -103,  -103,  -103,   526,  -103,   629,
     633,   634,   635,   636,   637,  -103,  -103,  -103,  -103,  -103,
    -103,  -103,  -103,   212,  -103,  -103,  -103,  -103,  -103,  -103,
     638,   639,   640,   641,   642,   643,   644,  -103,  -103,  -103,
    -103,  -103,  -103,  -103,  -103,  -103,   527,  -103,   645,   646,
    -103,  -103,  -103,  -103,   100,   -60,  -103,  -103,  -103,   648,
    -103,  -103,  -103,  -103,   649,  -103,   528,  -103,   650,   647,
    -103,  -103,  -103,  -103,   215,  -103,  -103,  -103,  -103,  -103,
     651,   235,   183,  -103,  -103,  -103,  -103,  -103,  -103,  -103,
     529,  -103,   652,   653,  -103,  -103,  -103,  -103,    17,   -82,
    -103,  -103,  -103,   655,  -103,  -103,  -103,  -103,   657,  -103,
     534,  -103,   656,   661,   662,  -103,  -103,  -103,  -103,  -103,
    -103,  -103,  -103,  -103,   659,   660,   663,   664,   665,   666,
     667,   668,   670,  -103,   673,  -103,   562,  -103,   672,   677,
    -103,  -103,  -103,  -103,   220,  -103,  -103,  -103,  -103,  -103,
    -103,   678,   679,   681,   680,   682,   685,   687,  -103,  -103,
    -103,  -103,  -103,  -103,  -103,  -103,  -103,   684,   686,   689,
     690,   691,   692,  -103,   695,  -103,   563,  -103,   694,   699,
     700,  -103,  -103,  -103,  -103,  -103,  -103,  -103,  -103,  -103,
     697,   698,   701,   702,   703,   704,   705,   706,   707,  -103,
     710,  -103,  -103,    97,  -103,  -103,  -103,  -103,  -103,  -103,
    -103,  -103,  -103,   709,   711,  -103,   712,  -103,   586,  -103,
     714,   719,  -103,  -103,  -103,  -103,   222,   -62,  -103,  -103,
    -103,   718,  -103,  -103,  -103,  -103,  -103,  -103,  -103,  -103,
    -103,   717,   720,  -103,   721,  -103,  -103,   119,  -103,  -103,
    -103,  -103,  -103,  -103,  -103,  -103,  -103,   722,   723,   724,
     599,  -103,   726,   725,   731,   732,  -103,  -103,  -103,  -103,
    -103,  -103,  -103,  -103,   729,   730,  -103,   733,  -103,  -103,
    -103,   734,   735,   736,  -103,  -103,  -103,  -103,  -103,  -103,
    -103,  -103,  -103,   737,   738,   739,   740,   741,   742,   743,
    -103,  -103,   744,   745,   746,   568,  -103,   747,   752,   753,
     754,  -103,  -103,  -103,  -103,  -103,  -103,  -103,  -103,  -103,
    -103,   755,  -103,  -103,  -103,  -103,  -103,   751,   756,  -102,
     368,   757,   759,   126,  -103,  -103,  -103,  -103,  -103,  -103,
    -103,  -103,  -103,  -103,  -103,   760,  -103,  -103,  -103,   761,
     762,   763,   764,  -103,  -103,  -103,  -103,  -103,  -103,   765,
     766,   767,   768,   606,  -103,   769,   758,   774,   775,  -103,
    -103,  -103,  -103,  -103,  -103,   772,   773,   776,   777,  -103,
    -103,  -103,  -103,   225,  -103,  -103,  -103,  -103,  -103,   780,
    -103,  -103,  -103,  -103,  -103,  -103,  -103,   607,  -103,   779,
     778,  -103,  -103,  -103,  -103,   781,   782,   783,   784,  -103,
     787,  -103,  -103,  -103,  -103,  -103,   786,   788,  -103,  -103
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
    -103,  -103,  -103,  -103,  -103,  -103,  -103,  -103,  -103,  -103,
    -103,  -103,  -103,  -103,  -103,  -103,  -103,  -103,  -103,  -103,
    -103,  -103,  -103,  -103,  -103,  -103,  -103,  -103,  -103,  -103,
    -103,  -103,  -103,  -103,  -103,  -103,  -103,  -103,  -103,  -103,
    -103,  -103,  -103,  -103,  -103,  -103,  -103,  -103,  -103,  -103,
    -103,  -103,  -103,  -103,  -103,  -103,  -103,  -103,  -103,  -103,
    -103,  -103,  -103,  -103,  -103,  -103,  -103,  -103,  -103,  -103,
    -103,  -103,  -103,  -103,  -103,  -103,  -103,  -103,  -103,  -103,
    -103,  -103,  -103,  -103,  -103,  -103,  -103,  -103,  -103,  -103,
    -103,  -103,  -103,  -103,  -103,  -103,  -103,  -103,  -103,  -103,
    -103,  -103,  -103,  -103,  -103,  -103,  -103,  -103,  -103,  -103,
    -103,  -103,  -103,  -103,  -103,  -103,  -103,  -103,  -103,  -103,
    -103,  -103,  -103,  -103,  -103,  -103,  -103,  -103,  -103,  -103,
    -103,  -103,  -103,  -103,  -103,  -103,  -103,  -103,  -103,  -103,
    -103,  -103,  -103,  -103,  -103,  -103,  -103,  -103,  -103,  -103,
    -103,  -103,  -103,  -103,  -103,  -103,  -103,  -103,  -103,  -103,
    -103,  -103,  -103,  -103,  -103,  -103,  -103,  -103,  -103,  -103,
    -103,  -103,  -103,  -103,  -103,  -103,  -103,  -103,  -103,  -103,
    -103,  -103,  -103,  -103,  -103,  -103,  -103,  -103,  -103,  -103,
    -103,  -103,  -103,  -103,  -103,  -103,  -103,  -103,  -103,  -103,
    -103,  -103,  -103,  -103,  -103,  -103,  -103,  -103,  -103,  -103,
    -103,  -103,  -103,  -103,  -103,  -103,  -103,  -103,  -103,  -103,
    -103,  -103,  -103,  -103,  -103,  -103,  -103,  -103,  -103,  -103,
    -103,  -103,  -103,  -103,  -103,  -103,  -103,  -103,  -103,  -103,
    -103,  -103,  -103,  -103,  -103,  -103,  -103,  -103,  -103,  -103,
    -103,  -103,  -103,  -103,  -103,  -103,  -103,  -103,  -103,  -103,
    -103,  -103,  -103,  -103,  -103,  -103,  -103,  -103,  -103,  -103,
    -103,  -103,  -103,  -103,  -103,  -103,  -103,  -103,  -103,  -103,
    -103,  -103,  -103,  -103,  -103,  -103,  -103,  -103,  -103,  -103,
    -103,  -103,  -103,  -103,  -103,  -103,  -103,  -103,  -103,  -103,
    -103,  -103,  -103,  -103,  -103,  -103,  -103,  -103,  -103,  -103,
    -103,  -103,  -103,  -103,  -103,  -103,  -103,  -103,  -103,  -103,
    -103,  -103,  -103,  -103,  -103,  -103,  -103,  -103,  -103,  -103,
    -103,  -103,  -103,  -103,  -103,  -103,  -103,  -103,  -103,  -103,
    -103,  -103,  -103,  -103,  -103,  -103,  -103,  -103,  -103,  -103,
    -103,  -103,  -103,  -103,  -103,  -103,  -103,  -103,  -103,  -103,
    -103,  -103,  -103,  -103,  -103,  -103,  -103,  -103,  -103,  -103,
    -103,  -103,  -103,  -103,  -103,  -103,  -103,  -103,  -103,  -103,
    -103,  -103,  -103,  -103,  -103,  -103,  -103,  -103,  -103,  -103,
    -103,  -103,  -103,  -103,  -103,  -103,  -103,  -103,  -103,  -103,
    -103,  -103,  -103,  -103,  -103,  -103,  -103,  -103,  -103,  -103,
    -103,  -103,  -103,  -103,  -103,  -103,  -103,  -103,  -103,  -103,
    -103,  -103,  -103,  -103,  -103,  -103,  -103,  -103,  -103,  -103,
    -103,  -103,  -103,  -103,  -103,  -103,  -103,  -103,  -103,  -103,
    -103,  -103,  -103,  -103,  -103,  -103,  -103,  -103,  -103,  -103,
    -103,  -103,  -103,  -103,  -103,  -103,  -103,  -103,  -103,  -103,
    -103,  -103,  -103,  -103,  -103,  -103,  -103,  -103,  -103,  -103,
    -103,  -103,  -103,  -103,  -103,  -103,  -103,  -103,  -103,  -103,
    -103,  -103,  -103,  -103,  -103,  -103,  -103,  -103,  -103,  -103,
    -103,  -103,  -103,  -103,  -103,  -103,  -103,  -103,  -103,  -103,
    -103,  -103,  -103,  -103,  -103,  -103,  -103,  -103,  -103,  -103,
    -103,  -103,  -103,  -103,  -103,  -103,  -103,  -103,  -103,  -103,
    -103,  -103
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint16 yytable[] =
{
     352,  1066,   412,   413,   244,   303,   787,   316,   317,   308,
     309,   162,   735,   312,   313,   160,   158,   154,   148,   146,
     156,  1169,    76,  1000,   144,   880,  1056,  1057,     7,   502,
    1235,   467,   497,   524,   525,   492,   125,   483,   597,   598,
       5,  1236,     6,   487,   484,   507,   503,   498,   493,    77,
     599,   600,   601,    78,   488,    79,   508,    80,  1058,    81,
     180,   126,   468,    12,   526,  1059,  1060,   527,     8,   528,
    1170,   511,   881,   127,  1067,   736,    13,   788,   147,   149,
     512,   145,   155,   181,   163,   159,   161,   157,  1001,   310,
     245,   318,   414,   353,   304,   314,    14,   182,    69,   183,
      20,   184,   102,   185,    27,   186,  1140,  1141,   119,   990,
     991,   187,   121,   188,   133,   189,   135,   190,   137,   191,
     142,   192,   168,   193,   230,   194,   956,   195,  1185,  1186,
     170,   171,   479,   957,   150,  1243,  1244,   480,  1142,   471,
    1143,   992,   472,  1144,  1145,   905,   993,   994,   906,     1,
       2,   872,   172,   173,   174,   164,   873,   862,   863,   845,
    1187,   232,  1188,   887,   888,  1189,  1190,  1245,   801,  1246,
     909,   802,  1247,  1248,   846,   847,   848,   169,   889,   890,
     891,   562,   563,    17,    18,   910,   911,   912,   849,   864,
     850,   865,  1030,   851,   892,   852,   246,   893,   236,   894,
     913,   914,   641,   642,   915,   247,   916,  1031,  1032,  1033,
     702,   703,   564,   926,   927,   565,   240,   566,   946,   947,
    1034,   970,   971,  1035,  1016,  1017,  1036,   252,  1037,  1098,
    1099,  1159,  1160,   643,  1277,  1278,   644,   841,   645,   265,
     842,   704,    23,    24,   705,   928,   706,   929,   260,  1161,
     948,   262,   949,   972,   269,   973,  1018,   270,  1019,  1162,
     271,  1100,    34,  1101,  1163,   287,  1279,   277,  1280,    30,
      31,    35,   272,    36,   279,    37,   281,    38,   283,    39,
     285,    40,   295,    41,   289,    42,   297,    43,   291,    44,
     301,    45,   607,   608,   293,   617,   618,   299,   627,   628,
      72,    73,    93,    94,   609,   610,   611,   619,   620,   621,
     629,   630,   631,    96,    97,    99,   100,   104,   105,   107,
     108,   110,   111,   113,   114,   116,   117,   139,   140,   151,
     152,   165,   166,   227,   228,   233,   234,   237,   238,   241,
     242,   274,   275,   336,   337,   349,   350,   395,   396,   405,
     406,   445,   446,   456,   457,   475,   476,   515,   516,   519,
     520,   537,   538,   723,   724,   740,   741,   305,   792,   793,
     306,   832,   833,  1239,  1240,   320,  1026,  1027,   323,   326,
     325,   333,   324,   335,   329,   340,   331,   343,   327,   345,
     339,   346,   328,   347,   348,   399,   354,   402,   330,   355,
     356,   357,   358,   359,   332,   360,   361,   362,   334,   364,
     363,   366,   365,   368,   367,   370,   369,   372,   371,   374,
     373,   376,   375,   378,   377,   381,   379,   385,   384,   387,
     386,   390,   391,   388,   389,   394,   404,   392,   408,   409,
     393,   410,   416,   418,   420,   422,   424,   426,   428,   430,
     432,   434,   436,   438,   440,   450,   443,   444,   455,   453,
     459,   462,   463,   460,   464,   466,   470,   474,   465,   478,
     482,   486,   491,   496,   501,   506,   510,   514,   518,   536,
     540,   534,   548,   541,   543,   546,   578,   549,   550,   551,
     544,   552,   557,   558,   559,   573,   574,   575,   576,   577,
     590,   572,   581,   586,   579,   584,   587,   592,   593,   594,
     595,   596,   582,   588,   637,   638,   639,   652,   651,   653,
     654,   676,   660,   658,   663,   661,   665,   667,   670,   666,
     673,   672,   683,   684,   685,   674,   686,   687,   688,   689,
     690,   692,   693,   691,   694,   696,   697,   698,   713,   714,
     715,     0,   728,   771,     0,   719,   720,   721,   722,   726,
     731,   733,   727,   695,   739,   734,   744,   746,   747,   748,
     712,   752,   773,   750,   774,   775,   786,   779,   936,     0,
     780,   781,   783,   785,   796,   791,   805,   800,   809,   807,
     836,   812,   808,   753,   813,   814,   815,   816,   817,   818,
     819,   820,   821,   822,   754,   755,   756,   823,   772,   827,
     828,   829,   831,   769,   770,   840,   871,   876,   878,   879,
     884,   885,   886,   904,   937,   938,   939,   940,   941,   942,
     944,   945,   964,     0,   955,   960,   965,   966,   967,   968,
     969,   980,   981,   982,     0,   984,   985,   986,   983,   989,
    1015,     0,   988,  1007,  1011,   943,  1055,  1014,  1025,  1054,
    1073,  1013,  1077,  1080,  1081,  1082,  1084,  1085,     0,     0,
    1086,  1087,  1088,  1089,  1090,  1091,   987,  1092,  1093,  1096,
    1097,  1108,  1109,  1079,  1110,  1112,  1053,  1111,  1113,   963,
    1114,  1115,     0,  1116,     0,  1095,  1117,  1118,  1119,  1120,
    1121,  1124,  1125,  1126,  1128,  1129,     0,     0,  1130,  1131,
    1132,  1133,  1134,  1135,  1136,  1137,  1152,  1154,  1153,  1156,
    1123,  1157,  1158,  1176,  1180,  1224,  1182,  1181,  1202,  1197,
    1198,  1199,  1200,  1201,  1203,  1204,  1205,  1206,  1207,  1268,
    1289,  1210,  1211,  1212,  1214,  1215,  1216,  1217,  1218,  1219,
    1220,  1221,  1222,  1223,  1225,  1226,  1227,  1228,  1233,     0,
    1229,  1270,  1241,  1234,  1242,  1255,     0,     0,  1259,  1260,
    1261,  1262,  1264,  1265,  1266,  1267,  1269,  1271,  1272,  1273,
    1274,  1291,     0,  1275,  1276,  1285,  1290,     0,  1292,  1293,
    1294,  1295,  1296,  1298,     0,  1299
};

static const yytype_int16 yycheck[] =
{
       4,    83,     5,     6,     5,     4,    82,     5,     6,     5,
       6,     4,    82,     5,     6,     4,     4,     4,     4,     4,
       4,    83,    53,    83,     4,    82,     9,    10,    10,   106,
     132,    68,   106,     9,    10,   106,    55,   104,     9,    10,
      13,   143,     0,   106,   111,   104,   123,   121,   119,    80,
      21,    22,    23,    84,   117,    86,   115,    88,    41,    90,
      57,    80,    99,     9,    40,    48,    49,    43,    50,    45,
     132,   104,   129,    92,   156,   145,    14,   153,    63,    65,
     113,    61,    69,    80,    77,    73,    75,    71,   148,    85,
      91,    89,    95,    97,    93,    87,    52,    94,    58,    96,
      54,    98,    15,   100,    56,   102,     9,    10,    16,     9,
      10,   108,    17,   110,    44,   112,    44,   114,    44,   116,
      17,   118,     7,   120,    17,   122,   132,   124,     9,    10,
       9,    10,   104,   139,     3,     9,    10,   109,    41,   101,
      43,    41,   104,    46,    47,   156,    46,    47,   159,    11,
      12,   132,    31,    32,    33,     3,   137,     9,    10,     9,
      41,     3,    43,     9,    10,    46,    47,    41,   132,    43,
       9,   135,    46,    47,    24,    25,    26,     9,    24,    25,
      26,     9,    10,     9,    10,    24,    25,    26,    38,    41,
      40,    43,     9,    43,    40,    45,     7,    43,     3,    45,
      39,    40,     9,    10,    43,     9,    45,    24,    25,    26,
       9,    10,    40,     9,    10,    43,     3,    45,     9,    10,
      37,     9,    10,    40,     9,    10,    43,     4,    45,     9,
      10,     9,    10,    40,     9,    10,    43,   148,    45,   128,
     151,    40,     9,    10,    43,    41,    45,    43,     4,    27,
      41,     5,    43,    41,     7,    43,    41,     7,    43,    37,
       7,    41,    51,    43,    42,    20,    41,    18,    43,     9,
      10,    60,    44,    62,    19,    64,    19,    66,    19,    68,
      19,    70,    19,    72,    20,    74,    19,    76,    20,    78,
      17,    80,     9,    10,    20,     9,    10,    28,     9,    10,
       9,    10,     9,    10,    21,    22,    23,    21,    22,    23,
      21,    22,    23,     9,    10,     9,    10,     9,    10,     9,
      10,     9,    10,     9,    10,     9,    10,     9,    10,     9,
      10,     9,    10,     9,    10,     9,    10,     9,    10,     9,
      10,     9,    10,    81,    82,     9,    10,    81,    82,     9,
      10,    81,    82,     9,    10,   103,   104,   125,   126,    81,
      82,     9,    10,   161,   162,   131,   132,     7,   147,   148,
       9,   155,   156,     5,     6,     5,   141,   142,    61,     7,
      65,     7,    63,     7,    71,   144,    75,    34,    67,     5,
      59,     5,    69,     5,     3,   152,     7,    35,    73,     9,
       7,     9,     7,     9,    77,     7,     9,     7,    79,     7,
       9,     7,     9,     7,     9,     7,     9,     7,     9,     7,
       9,     7,     9,     7,     9,     5,     9,    85,     7,     7,
      85,     7,    89,    87,    87,     7,     7,    89,     7,     7,
      91,     7,     5,     5,     5,     5,     5,     5,     5,     5,
       5,     5,     5,     5,     5,   160,    93,     7,     7,    36,
       5,     7,    95,   130,    95,     7,     7,     7,    97,     7,
       7,     7,     7,     7,     7,     7,     7,     7,     7,     7,
       5,    29,     9,   146,     7,   134,     5,     9,     9,     9,
      37,     9,     9,     9,     9,     3,     3,     3,     7,     9,
     136,    83,     7,     7,   154,   150,     9,     4,     4,     4,
       4,     4,    38,    37,     4,     4,     4,     3,    83,     3,
       3,   138,     7,     5,   158,    39,     7,    38,     5,     9,
       9,     7,   107,     3,     3,    37,     3,   107,     3,     3,
       3,     3,     3,   107,     3,     3,     3,     3,     3,     3,
       3,    -1,    39,   127,    -1,     7,     7,     7,     7,     7,
       5,     7,     9,   107,     7,     9,     5,     7,     9,    37,
      83,    69,     3,   140,     3,     3,     9,     7,     3,    -1,
       7,     7,     5,     7,     5,     7,     5,     7,    30,     7,
       5,     7,     9,   105,     7,     7,     7,     7,     7,     7,
       7,     7,     7,     7,   105,   105,   105,     7,    83,     7,
       7,     7,     7,   105,   105,     7,     7,     5,     7,     9,
       7,     7,     7,     7,     3,     3,     7,     3,     3,     3,
       7,     3,     3,    -1,     7,     5,     3,     3,     3,     3,
       3,     3,     3,     3,    -1,     3,     3,     3,     7,     3,
       3,    -1,     7,     5,     5,   133,     3,     7,     7,     7,
       5,   133,     5,     7,     3,     3,     7,     7,    -1,    -1,
       7,     7,     7,     7,     7,     7,   149,     7,     5,     7,
       3,     3,     3,   149,     3,     3,   157,     7,     3,   163,
       3,     7,    -1,     7,    -1,   133,     7,     7,     7,     7,
       5,     7,     3,     3,     7,     7,    -1,    -1,     7,     7,
       7,     7,     7,     7,     7,     5,     7,     5,     7,   133,
     157,     7,     3,     5,     7,   157,     5,     7,     3,     7,
       7,     7,   133,     7,     3,     3,     7,     7,     5,   133,
     133,     7,     7,     7,     7,     7,     7,     7,     7,     7,
       7,     7,     7,     7,     7,     3,     3,     3,     7,    -1,
       5,     3,     5,     7,     5,     5,    -1,    -1,     7,     7,
       7,     7,     7,     7,     7,     7,     7,     3,     3,     7,
       7,     3,    -1,     7,     7,     5,     7,    -1,     7,     7,
       7,     7,     5,     7,    -1,     7
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,    11,    12,   166,   167,    13,     0,    10,    50,   168,
     169,   170,     9,    14,    52,   234,   235,     9,    10,   171,
      54,   274,   275,     9,    10,   236,   172,    56,   299,   300,
       9,    10,   276,   237,    51,    60,    62,    64,    66,    68,
      70,    72,    74,    76,    78,    80,   173,   174,   175,   178,
     179,   182,   183,   186,   187,   192,   193,   196,   197,   200,
     201,   204,   205,   208,   209,   212,   213,   218,   219,    58,
     437,   438,     9,    10,   301,   277,    53,    80,    84,    86,
      88,    90,   238,   239,   240,   244,   245,   249,   250,   254,
     255,   258,   259,     9,    10,   176,     9,    10,   180,     9,
      10,   184,    15,   188,     9,    10,   194,     9,    10,   198,
       9,    10,   202,     9,    10,   206,     9,    10,   210,    16,
     214,    17,   220,   439,   302,    55,    80,    92,   278,   279,
     280,   283,   284,    44,   241,    44,   246,    44,   251,     9,
      10,   256,    17,   260,     4,    61,     4,    63,     4,    65,
       3,     9,    10,   190,     4,    69,     4,    71,     4,    73,
       4,    75,     4,    77,     3,     9,    10,   216,     7,     9,
       9,    10,    31,    32,    33,   440,   441,   442,   443,   444,
      57,    80,    94,    96,    98,   100,   102,   108,   110,   112,
     114,   116,   118,   120,   122,   124,   303,   304,   305,   309,
     310,   313,   314,   319,   320,   325,   326,   331,   332,   337,
     338,   343,   344,   358,   359,   373,   374,   388,   389,   403,
     404,   409,   410,   415,   416,   421,   422,     9,    10,   281,
      17,   285,     3,     9,    10,   243,     3,     9,    10,   248,
       3,     9,    10,   253,     5,    91,     7,     9,   177,   181,
     185,   189,     4,   191,   195,   199,   203,   207,   211,   215,
       4,   217,     5,   221,   222,   128,   445,   446,   447,     7,
       7,     7,    44,   306,     9,    10,   311,    18,   315,    19,
     321,    19,   327,    19,   333,    19,   339,    20,   345,    20,
     360,    20,   375,    20,   390,    19,   405,    19,   411,    28,
     417,    17,   423,     4,    93,     7,     9,   242,     5,     6,
      85,   247,     5,     6,    87,   252,     5,     6,    89,   257,
       5,   261,   262,    61,    63,    65,     7,    67,    69,    71,
      73,    75,    77,     7,    79,     7,    81,    82,   223,    59,
     144,   546,   547,    34,   448,     5,     5,     5,     3,     9,
      10,   308,     4,    97,     7,     9,     7,     9,     7,     9,
       7,     9,     7,     9,     7,     9,     7,     9,     7,     9,
       7,     9,     7,     9,     7,     9,     7,     9,     7,     9,
     282,     5,   286,   287,     7,    85,    85,     7,    87,    87,
       7,    89,    89,    91,     7,    81,    82,   263,   224,   152,
     606,   607,    35,   548,     7,     9,    10,   449,     7,     7,
       7,   307,     5,     6,    95,   312,     5,   316,     5,   322,
       5,   328,     5,   334,     5,   340,     5,   346,     5,   361,
       5,   376,     5,   391,     5,   406,     5,   412,     5,   418,
       5,   424,   425,    93,     7,    81,    82,   288,   264,   225,
     160,   666,   667,    36,   608,     7,     9,    10,   549,     5,
     130,   450,     7,    95,    95,    97,     7,    68,    99,   317,
       7,   101,   104,   323,     7,   103,   104,   329,     7,   104,
     109,   335,     7,   104,   111,   341,     7,   106,   117,   347,
     348,     7,   106,   119,   362,   363,     7,   106,   121,   377,
     378,     7,   106,   123,   392,   393,     7,   104,   115,   407,
       7,   104,   113,   413,     7,   125,   126,   419,     7,    81,
      82,   426,   289,   265,     9,    10,    40,    43,    45,   226,
     227,   229,   231,   233,    29,   668,     7,     9,    10,   609,
       5,   146,   550,     7,    37,   451,   134,   461,     9,     9,
       9,     9,     9,   349,   364,   379,   394,     9,     9,     9,
     427,   290,     9,    10,    40,    43,    45,   266,   267,   269,
     271,   273,    83,     3,     3,     3,     7,     9,     5,   154,
     610,     7,    38,   551,   150,   561,     7,     9,    37,   462,
     136,   472,     4,     4,     4,     4,     4,     9,    10,    21,
      22,    23,   350,   351,   353,   355,   357,     9,    10,    21,
      22,    23,   365,   366,   368,   370,   372,     9,    10,    21,
      22,    23,   380,   381,   383,   385,   387,     9,    10,    21,
      22,    23,   395,   396,   398,   400,   402,     4,     4,     4,
     428,     9,    10,    40,    43,    45,   291,   292,   294,   296,
     298,    83,     3,     3,     3,   228,   230,   232,     5,   669,
       7,    39,   611,   158,   621,     7,     9,    38,   562,   574,
       5,   452,     7,     9,    37,   473,   138,   483,   318,   324,
     330,   336,   342,   107,     3,     3,     3,   107,     3,     3,
       3,   107,     3,     3,     3,   107,     3,     3,     3,   408,
     414,   420,     9,    10,    40,    43,    45,   429,   430,   432,
     434,   436,    83,     3,     3,     3,   268,   270,   272,     7,
       7,     7,     7,   161,   162,   670,     7,     9,    39,   622,
     634,     5,   552,     7,     9,    82,   145,   575,   576,     7,
     131,   132,   453,   454,     5,   463,     7,     9,    37,   484,
     140,   494,    69,   105,   105,   105,   105,   352,   354,   356,
     367,   369,   371,   382,   384,   386,   397,   399,   401,   105,
     105,   127,    83,     3,     3,     3,   293,   295,   297,     7,
       7,     7,   671,     5,   612,     7,     9,    82,   153,   635,
     636,     7,   147,   148,   553,   554,     5,   563,   577,   455,
       7,   132,   135,   464,   465,     5,   474,     7,     9,    30,
     495,   514,     7,     7,     7,     7,     7,     7,     7,     7,
       7,     7,     7,     7,   431,   433,   435,     7,     7,     7,
     672,     7,   155,   156,   613,   614,     5,   623,   637,   555,
       7,   148,   151,   564,   565,     9,    24,    25,    26,    38,
      40,    43,    45,   578,   579,   580,   582,   584,   586,   588,
     590,   592,     9,    10,    41,    43,   456,   457,   458,   460,
     466,     7,   132,   137,   475,   476,     5,   485,     7,     9,
      82,   129,   515,   516,     7,     7,     7,     9,    10,    24,
      25,    26,    40,    43,    45,   673,   674,   676,   678,   680,
     682,   684,   686,   615,     7,   156,   159,   624,   625,     9,
      24,    25,    26,    39,    40,    43,    45,   638,   639,   640,
     642,   644,   646,   648,   650,   652,     9,    10,    41,    43,
     556,   557,   558,   560,   566,   593,     3,     3,     3,     7,
       3,     3,     3,   133,     7,     3,     9,    10,    41,    43,
     467,   468,   469,   471,   477,     7,   132,   139,   486,   487,
       5,   496,   517,   163,     3,     3,     3,     3,     3,     3,
       9,    10,    41,    43,   616,   617,   618,   620,   626,   653,
       3,     3,     3,     7,     3,     3,     3,   149,     7,     3,
       9,    10,    41,    46,    47,   567,   568,   569,   571,   573,
      83,   148,   594,   595,   585,   587,   589,     5,   581,   583,
     591,     5,   459,   133,     7,     3,     9,    10,    41,    43,
     478,   479,   480,   482,   488,     7,   141,   142,   497,   498,
       9,    24,    25,    26,    37,    40,    43,    45,   518,   519,
     520,   522,   524,   526,   528,   530,   532,   679,   681,   683,
     675,   677,   685,   157,     7,     3,     9,    10,    41,    48,
      49,   627,   628,   629,   631,   633,    83,   156,   654,   655,
     645,   647,   649,     5,   641,   643,   651,     5,   559,   149,
       7,     3,     3,   596,     7,     7,     7,     7,     7,     7,
       7,     7,     7,     5,   470,   133,     7,     3,     9,    10,
      41,    43,   489,   490,   491,   493,   499,   533,     3,     3,
       3,     7,     3,     3,     3,     7,     7,     7,     7,     7,
       7,     5,   619,   157,     7,     3,     3,   656,     7,     7,
       7,     7,     7,     7,     7,     7,     7,     5,   570,   572,
       9,    10,    41,    43,    46,    47,   597,   598,   599,   601,
     603,   605,     7,     7,     5,   481,   133,     7,     3,     9,
      10,    27,    37,    42,   500,   501,   502,   503,   504,    83,
     132,   534,   535,   525,   527,   529,     5,   521,   523,   531,
       7,     7,     5,   630,   632,     9,    10,    41,    43,    46,
      47,   657,   658,   659,   661,   663,   665,     7,     7,     7,
     133,     7,     3,     3,     3,     7,     7,     5,   492,   505,
       7,     7,     7,   536,     7,     7,     7,     7,     7,     7,
       7,     7,     7,     7,   157,     7,     3,     3,     3,     5,
     600,   602,   604,     7,     7,   132,   143,   506,   507,     5,
       6,     5,     5,     9,    10,    41,    43,    46,    47,   537,
     538,   539,   541,   543,   545,     5,   660,   662,   664,     7,
       7,     7,     7,   508,     7,     7,     7,     7,   133,     7,
       3,     3,     3,     7,     7,     7,     7,     9,    10,    41,
      43,   509,   510,   511,   513,     5,   540,   542,   544,   133,
       7,     3,     7,     7,     7,     7,     5,   512,     7,     7
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
      yyerror (&yylloc, osoption, parserData, YY_("syntax error: cannot back up")); \
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
		  Type, Value, Location, osoption, parserData); \
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
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp, OSOption *osoption, OSoLParserData *parserData)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp, osoption, parserData)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
    YYLTYPE const * const yylocationp;
    OSOption *osoption;
    OSoLParserData *parserData;
#endif
{
  if (!yyvaluep)
    return;
  YYUSE (yylocationp);
  YYUSE (osoption);
  YYUSE (parserData);
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
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp, OSOption *osoption, OSoLParserData *parserData)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep, yylocationp, osoption, parserData)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
    YYLTYPE const * const yylocationp;
    OSOption *osoption;
    OSoLParserData *parserData;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  YY_LOCATION_PRINT (yyoutput, *yylocationp);
  YYFPRINTF (yyoutput, ": ");
  yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp, osoption, parserData);
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
yy_reduce_print (YYSTYPE *yyvsp, YYLTYPE *yylsp, int yyrule, OSOption *osoption, OSoLParserData *parserData)
#else
static void
yy_reduce_print (yyvsp, yylsp, yyrule, osoption, parserData)
    YYSTYPE *yyvsp;
    YYLTYPE *yylsp;
    int yyrule;
    OSOption *osoption;
    OSoLParserData *parserData;
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
		       , &(yylsp[(yyi + 1) - (yynrhs)])		       , osoption, parserData);
      fprintf (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, yylsp, Rule, osoption, parserData); \
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
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp, OSOption *osoption, OSoLParserData *parserData)
#else
static void
yydestruct (yymsg, yytype, yyvaluep, yylocationp, osoption, parserData)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
    YYLTYPE *yylocationp;
    OSOption *osoption;
    OSoLParserData *parserData;
#endif
{
  YYUSE (yyvaluep);
  YYUSE (yylocationp);
  YYUSE (osoption);
  YYUSE (parserData);

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
int yyparse (OSOption *osoption, OSoLParserData *parserData);
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
yyparse (OSOption *osoption, OSoLParserData *parserData)
#else
int
yyparse (osoption, parserData)
    OSOption *osoption;
    OSoLParserData *parserData;
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
        case 9:

    {	if (parserData->osolgeneralPresent)
	{	osolerror( NULL, osoption, parserData, "only one <general> element allowed");
	}
	else
	{	parserData->osolgeneralPresent = true;
		osoption->general = new GeneralOption();
	}
;}
    break;

  case 26:

    {	if (parserData->serviceURIPresent)
	{	osolerror( NULL, osoption, parserData, "only one <serviceURI> element allowed");
	}
	else
	{	parserData->serviceURIPresent = true;
	}
;}
    break;

  case 29:

    {osoption->general->serviceURI = (yyvsp[(2) - (2)].sval);;}
    break;

  case 32:

    {	if (parserData->serviceNamePresent)
	{	osolerror( NULL, osoption, parserData, "only one <serviceName> element allowed");
	}
	else
	{	parserData->serviceNamePresent = true;
	}
;}
    break;

  case 35:

    {osoption->general->serviceName = (yyvsp[(2) - (2)].sval);;}
    break;

  case 38:

    {	if (parserData->instanceNamePresent)
	{	osolerror( NULL, osoption, parserData, "only one <instanceName> element allowed");
	}
	else
	{	parserData->instanceNamePresent = true;
	}
;}
    break;

  case 41:

    {osoption->general->instanceName = (yyvsp[(2) - (2)].sval);;}
    break;

  case 44:

    {	if (parserData->instanceLocationPresent)
	{	osolerror( NULL, osoption, parserData, "only one <instanceLocation> element allowed");
	}
	else
	{	parserData->instanceLocationPresent = true;
		osoption->general->instanceLocation = new InstanceLocationOption();
		osoption->general->instanceLocation->locationType = "local";
	}
;}
    break;

  case 46:

    {	if ( (strcmp((yyvsp[(2) - (2)].sval), "local") == 0) || (strcmp((yyvsp[(2) - (2)].sval), "http") == 0) || (strcmp((yyvsp[(2) - (2)].sval), "ftp") == 0) )
		osoption->general->instanceLocation->locationType = (yyvsp[(2) - (2)].sval);
	else
		osolerror( NULL, osoption, parserData, "Not a valid locationType");
;}
    break;

  case 51:

    {osoption->general->instanceLocation->value = (yyvsp[(1) - (1)].sval);;}
    break;

  case 53:

    {	if (parserData->jobIDPresent)
	{	osolerror( NULL, osoption, parserData, "only one <jobID> element allowed");
	}
	else
	{	parserData->jobIDPresent = true;
	}
;}
    break;

  case 56:

    {osoption->general->jobID = (yyvsp[(2) - (2)].sval);;}
    break;

  case 59:

    {	if (parserData->solverToInvokePresent)
	{	osolerror( NULL, osoption, parserData, "only one <solverToInvoke> element allowed");
	}
	else
	{	parserData->solverToInvokePresent = true;
	}
;}
    break;

  case 62:

    {osoption->general->solverToInvoke = (yyvsp[(2) - (2)].sval);;}
    break;

  case 65:

    {	if (parserData->licensePresent)
	{	osolerror( NULL, osoption, parserData, "only one <license> element allowed");
	}
	else
	{	parserData->licensePresent = true;	
	}
;}
    break;

  case 68:

    {osoption->general->license = (yyvsp[(2) - (2)].sval);;}
    break;

  case 71:

    {	if (parserData->usernamePresent)
	{	osolerror( NULL, osoption, parserData, "only one <userName> element allowed");
	}
	else
	{	parserData->usernamePresent = true;
	}
;}
    break;

  case 74:

    {osoption->general->userName = (yyvsp[(2) - (2)].sval);;}
    break;

  case 77:

    {	if (parserData->passwordPresent)
	{	osolerror( NULL, osoption, parserData, "only one <password> element allowed");
	}
	else
	{	parserData->passwordPresent = true;
	}
;}
    break;

  case 80:

    {osoption->general->password = (yyvsp[(2) - (2)].sval);;}
    break;

  case 83:

    {	if (parserData->contactPresent)
	{	osolerror( NULL, osoption, parserData, "only one <contact> element allowed");
	}
	else
	{	parserData->contactPresent = true;
		osoption->general->contact = new ContactOption();
		osoption->general->contact->transportType = "osp";
	}
;}
    break;

  case 85:

    {	if ( (strcmp((yyvsp[(2) - (2)].sval),"osp") == 0) || (strcmp((yyvsp[(2) - (2)].sval),"smtp") == 0) || (strcmp((yyvsp[(2) - (2)].sval),"http")  == 0) || 
						  (strcmp((yyvsp[(2) - (2)].sval),"ftp")  == 0) || (strcmp((yyvsp[(2) - (2)].sval),"other") == 0) )
		osoption->general->contact->transportType = (yyvsp[(2) - (2)].sval);
	else
		osolerror( NULL, osoption, parserData, "Not a valid transport type");
;}
    break;

  case 90:

    {osoption->general->contact->value = (yyvsp[(1) - (1)].sval);;}
    break;

  case 92:

    {	if (parserData->otherGeneralOptionsPresent)
	{	osolerror( NULL, osoption, parserData, "only one <otherOptions> element allowed");
	}
	else
	{	parserData->otherGeneralOptionsPresent = true;
		osoption->general->otherOptions = new OtherOptions();
	}
;}
    break;

  case 93:

    {	if ((yyvsp[(3) - (4)].ival) < 0)
		osolerror( NULL, osoption, parserData, "Number of <other> elements cannot be negative");
	osoption->general->otherOptions->numberOfOtherOptions = (yyvsp[(3) - (4)].ival);
	osoption->general->otherOptions->other = new OtherOption*[(yyvsp[(3) - (4)].ival)];
	for (int i=0; i < (yyvsp[(3) - (4)].ival); i++) osoption->general->otherOptions->other[i] = new OtherOption();
;}
    break;

  case 94:

    {	if (parserData->numberOfOtherGeneralOptions != osoption->general->otherOptions->numberOfOtherOptions)
		osolerror (NULL, osoption, parserData, "wrong number of other options in <general> element");
;}
    break;

  case 97:

    {	if (parserData->numberOfOtherGeneralOptions >= osoption->general->otherOptions->numberOfOtherOptions)
		{	osolerror (NULL, osoption, parserData, "too many other options in <general> element");
		};
	;}
    break;

  case 98:

    {	if (!parserData->otherOptionNamePresent)
		osolerror (NULL, osoption, parserData, "name attribute must be present");
	/* reset defaults for the next option */
	parserData->otherOptionNamePresent = false;
	parserData->otherOptionValuePresent = false;
	parserData->otherOptionDescriptionPresent = false;
	parserData->numberOfOtherGeneralOptions++;
;}
    break;

  case 104:

    {	if (parserData->otherOptionNamePresent)
	{	osolerror( NULL, osoption, parserData, "only one name attribute allowed");
	}
	else
	{	parserData->otherOptionNamePresent = true;
		osoption->general->otherOptions->other[parserData->numberOfOtherGeneralOptions]->name = (yyvsp[(2) - (2)].sval);
	}
;}
    break;

  case 106:

    {	if (parserData->otherOptionValuePresent)
	{	osolerror( NULL, osoption, parserData, "only one value attribute allowed");
	}
	else
	{	parserData->otherOptionValuePresent = true;
		osoption->general->otherOptions->other[parserData->numberOfOtherGeneralOptions]->value = (yyvsp[(2) - (2)].sval);
	}
;}
    break;

  case 108:

    {	if (parserData->otherOptionDescriptionPresent)
	{	osolerror( NULL, osoption, parserData, "only one description attribute allowed");
	}
	else
	{	parserData->otherOptionDescriptionPresent = true;
		osoption->general->otherOptions->other[parserData->numberOfOtherGeneralOptions]->description = (yyvsp[(2) - (2)].sval);
	}
;}
    break;

  case 114:

    {	if (parserData->osolsystemPresent)
	{	osolerror( NULL, osoption, parserData, "only one <system> element allowed");
	}
	else
	{	parserData->osolsystemPresent = true;
		osoption->system = new SystemOption();
	}
;}
    break;

  case 125:

    {	if (parserData->minDiskSpacePresent)
	{	osolerror( NULL, osoption, parserData, "only one <minDiskSpace> element allowed");
	}
	else
	{	parserData->minDiskSpacePresent = true;
		osoption->system->minDiskSpace = new MinDiskSpace();
		osoption->system->minDiskSpace->unit = "byte";
	}
;}
    break;

  case 127:

    {	if ( (strcmp((yyvsp[(2) - (2)].sval),"byte") == 0) || (strcmp((yyvsp[(2) - (2)].sval),"kilobyte") == 0) || (strcmp((yyvsp[(2) - (2)].sval),"megabyte") == 0) || 
						   (strcmp((yyvsp[(2) - (2)].sval),"terabyte") == 0) || (strcmp((yyvsp[(2) - (2)].sval),"petabyte") == 0) )
		osoption->system->minDiskSpace->unit = (yyvsp[(2) - (2)].sval);
	else
		osolerror( NULL, osoption, parserData, "Not a valid unit");
;}
    break;

  case 131:

    {	if ((yyvsp[(2) - (3)].dval) < 0)
		osolerror( NULL, osoption, parserData, "minDiskSpace cannot be negative");
	osoption->system->minDiskSpace->value = (yyvsp[(2) - (3)].dval);
;}
    break;

  case 132:

    {	if ((yyvsp[(2) - (3)].ival) < 0)
		osolerror( NULL, osoption, parserData, "minDiskSpace cannot be negative");
	osoption->system->minDiskSpace->value = (yyvsp[(2) - (3)].ival);
;}
    break;

  case 134:

    {	if (parserData->minMemorySizePresent)
	{	osolerror( NULL, osoption, parserData, "only one <minMemorySize> element allowed");
	}
	else
	{	parserData->minMemorySizePresent = true;
		osoption->system->minMemorySize = new MinMemorySize();
		osoption->system->minMemorySize->unit = "byte";
	}
;}
    break;

  case 136:

    {	if ( (strcmp((yyvsp[(2) - (2)].sval),"byte") == 0) || (strcmp((yyvsp[(2) - (2)].sval),"kilobyte") == 0) || (strcmp((yyvsp[(2) - (2)].sval),"megabyte") == 0) || 
						   (strcmp((yyvsp[(2) - (2)].sval),"terabyte") == 0) || (strcmp((yyvsp[(2) - (2)].sval),"petabyte") == 0) )
		osoption->system->minMemorySize->unit = (yyvsp[(2) - (2)].sval);
	else
		osolerror( NULL, osoption, parserData, "Not a valid unit");
;}
    break;

  case 140:

    {	if ((yyvsp[(2) - (3)].dval) < 0)
		osolerror( NULL, osoption, parserData, "minMemorySize cannot be negative");
	osoption->system->minMemorySize->value = (yyvsp[(2) - (3)].dval);
;}
    break;

  case 141:

    {	if ((yyvsp[(2) - (3)].ival) < 0)
		osolerror( NULL, osoption, parserData, "minMemorySize cannot be negative");
	osoption->system->minMemorySize->value = (yyvsp[(2) - (3)].ival);
;}
    break;

  case 143:

    {	if (parserData->minCPUSpeedPresent)
	{	osolerror( NULL, osoption, parserData, "only one <minCPUSpeed> element allowed");
	}
	else
	{	parserData->minCPUSpeedPresent = true;
		osoption->system->minCPUSpeed = new MinCPUSpeed();
		osoption->system->minCPUSpeed->unit = "hertz";
	}
;}
    break;

  case 145:

    {	if ( (strcmp((yyvsp[(2) - (2)].sval),    "hertz") == 0) || (strcmp((yyvsp[(2) - (2)].sval),"kilohertz") == 0) || (strcmp((yyvsp[(2) - (2)].sval),"megahertz") == 0) || 
	     (strcmp((yyvsp[(2) - (2)].sval),"gigahertz") == 0) || (strcmp((yyvsp[(2) - (2)].sval),"terahertz") == 0) || (strcmp((yyvsp[(2) - (2)].sval),"petahertz") == 0) ||
	     (strcmp((yyvsp[(2) - (2)].sval),    "flops") == 0) || (strcmp((yyvsp[(2) - (2)].sval),"kiloflops") == 0) || (strcmp((yyvsp[(2) - (2)].sval),"megaflops") == 0) || 
	     (strcmp((yyvsp[(2) - (2)].sval),"gigaflops") == 0) || (strcmp((yyvsp[(2) - (2)].sval),"teraflops") == 0) || (strcmp((yyvsp[(2) - (2)].sval),"petahertz") == 0) ) 
		osoption->system->minCPUSpeed->unit = (yyvsp[(2) - (2)].sval);
	else
		osolerror( NULL, osoption, parserData, "Not a valid unit");
;}
    break;

  case 149:

    {	if ((yyvsp[(2) - (3)].dval) < 0)
		osolerror( NULL, osoption, parserData, "minCPUSpeed cannot be negative");
	osoption->system->minCPUSpeed->value = (yyvsp[(2) - (3)].dval);
;}
    break;

  case 150:

    {	if ((yyvsp[(2) - (3)].ival) < 0)
		osolerror( NULL, osoption, parserData, "minCPUSpeed cannot be negative");
	osoption->system->minCPUSpeed->value = (yyvsp[(2) - (3)].ival);
;}
    break;

  case 152:

    {	if (parserData->minCPUNumberPresent)
	{	osolerror( NULL, osoption, parserData, "only one <minCPUNumber> element allowed");
	}
	else
	{	parserData->minCPUNumberPresent = true;
	}
;}
    break;

  case 155:

    {	if ((yyvsp[(2) - (2)].ival) < 0)
		osolerror( NULL, osoption, parserData, "minCPUNumber cannot be negative");
	osoption->system->minCPUNumber = (yyvsp[(2) - (2)].ival);
;}
    break;

  case 158:

    {	if (parserData->otherSystemOptionsPresent)
	{	osolerror( NULL, osoption, parserData, "only one <otherOptions> element allowed");
	}
	else
	{	parserData->otherSystemOptionsPresent = true;
		osoption->system->otherOptions = new OtherOptions();
	}
;}
    break;

  case 159:

    {	if ((yyvsp[(3) - (4)].ival) < 0)
		osolerror( NULL, osoption, parserData, "Number of <other> elements cannot be negative");
	osoption->system->otherOptions->numberOfOtherOptions = (yyvsp[(3) - (4)].ival);
	osoption->system->otherOptions->other = new OtherOption*[(yyvsp[(3) - (4)].ival)];
	for (int i=0; i < (yyvsp[(3) - (4)].ival); i++) osoption->system->otherOptions->other[i] = new OtherOption();
;}
    break;

  case 160:

    {	if (parserData->numberOfOtherSystemOptions != osoption->system->otherOptions->numberOfOtherOptions)
		osolerror (NULL, osoption, parserData, "wrong number of other options in <system> element");
;}
    break;

  case 163:

    {	if (parserData->numberOfOtherSystemOptions >= osoption->system->otherOptions->numberOfOtherOptions)
		{	osolerror (NULL, osoption, parserData, "too many other options in <system> element");
		};
	;}
    break;

  case 164:

    {	if (!parserData->otherOptionNamePresent)
		osolerror (NULL, osoption, parserData, "name attribute must be present");
	/* reset defaults for the next option */
	parserData->otherOptionNamePresent = false;
	parserData->otherOptionValuePresent = false;
	parserData->otherOptionDescriptionPresent = false;
	parserData->numberOfOtherSystemOptions++;
;}
    break;

  case 170:

    {	if (parserData->otherOptionNamePresent)
	{	osolerror( NULL, osoption, parserData, "only one name attribute allowed");
	}
	else
	{	parserData->otherOptionNamePresent = true;
		osoption->system->otherOptions->other[parserData->numberOfOtherSystemOptions]->name = (yyvsp[(2) - (2)].sval);
	}
;}
    break;

  case 172:

    {	if (parserData->otherOptionValuePresent)
	{	osolerror( NULL, osoption, parserData, "only one value attribute allowed");
	}
	else
	{	parserData->otherOptionValuePresent = true;
		osoption->system->otherOptions->other[parserData->numberOfOtherSystemOptions]->value = (yyvsp[(2) - (2)].sval);
	}
;}
    break;

  case 174:

    {	if (parserData->otherOptionDescriptionPresent)
	{	osolerror( NULL, osoption, parserData, "only one description attribute allowed");
	}
	else
	{	parserData->otherOptionDescriptionPresent = true;
		osoption->system->otherOptions->other[parserData->numberOfOtherSystemOptions]->description = (yyvsp[(2) - (2)].sval);
	}
;}
    break;

  case 180:

    {	if (parserData->osolservicePresent)
	{	osolerror( NULL, osoption, parserData, "only one <service> element allowed");
	}
	else
	{	parserData->osolservicePresent = true;
		osoption->service = new ServiceOption();
	}
;}
    break;

  case 188:

    {	if (parserData->serviceTypePresent)
	{	osolerror( NULL, osoption, parserData, "only one <type> element allowed");
	}
	else
	{	parserData->serviceTypePresent = true;
		osoption->service->type = "solver";
	}
;}
    break;

  case 191:

    {	if ( (strcmp((yyvsp[(2) - (2)].sval),"solver") == 0) || (strcmp((yyvsp[(2) - (2)].sval),"analyzer")   == 0) || (strcmp((yyvsp[(2) - (2)].sval),"scheduler") == 0) ||
						     (strcmp((yyvsp[(2) - (2)].sval),"simulation") == 0) || (strcmp((yyvsp[(2) - (2)].sval),"registry")  == 0) ||
						     (strcmp((yyvsp[(2) - (2)].sval),"modeler")    == 0) || (strcmp((yyvsp[(2) - (2)].sval),"agent")     == 0) ) 
		osoption->service->type = (yyvsp[(2) - (2)].sval);
	else
		osolerror( NULL, osoption, parserData, "Not a valid service type");
;}
    break;

  case 194:

    {	if (parserData->otherServiceOptionsPresent)
	{	osolerror( NULL, osoption, parserData, "only one <otherOptions> element allowed");
	}
	else
	{	parserData->otherServiceOptionsPresent = true;
		osoption->service->otherOptions = new OtherOptions();
	}
;}
    break;

  case 195:

    {	if ((yyvsp[(3) - (4)].ival) < 0)
		osolerror( NULL, osoption, parserData, "Number of <other> elements cannot be negative");
	osoption->service->otherOptions->numberOfOtherOptions = (yyvsp[(3) - (4)].ival);
	osoption->service->otherOptions->other = new OtherOption*[(yyvsp[(3) - (4)].ival)];
	for (int i=0; i < (yyvsp[(3) - (4)].ival); i++) osoption->service->otherOptions->other[i] = new OtherOption();
;}
    break;

  case 196:

    {	if (parserData->numberOfOtherServiceOptions != osoption->service->otherOptions->numberOfOtherOptions)
		osolerror (NULL, osoption, parserData, "wrong number of other options in <service> element");
;}
    break;

  case 199:

    {	if (parserData->numberOfOtherServiceOptions >= osoption->service->otherOptions->numberOfOtherOptions)
		{	osolerror (NULL, osoption, parserData, "too many other options in <service> element");
		};
	;}
    break;

  case 200:

    {	if (!parserData->otherOptionNamePresent)
		osolerror (NULL, osoption, parserData, "name attribute must be present");
	/* reset defaults for the next option */
	parserData->otherOptionNamePresent = false;
	parserData->otherOptionValuePresent = false;
	parserData->otherOptionDescriptionPresent = false;
	parserData->numberOfOtherServiceOptions++;
;}
    break;

  case 206:

    {	if (parserData->otherOptionNamePresent)
	{	osolerror( NULL, osoption, parserData, "only one name attribute allowed");
	}
	else
	{	parserData->otherOptionNamePresent = true;
		osoption->service->otherOptions->other[parserData->numberOfOtherServiceOptions]->name = (yyvsp[(2) - (2)].sval);
	}
;}
    break;

  case 208:

    {	if (parserData->otherOptionValuePresent)
	{	osolerror( NULL, osoption, parserData, "only one value attribute allowed");
	}
	else
	{	parserData->otherOptionValuePresent = true;
		osoption->service->otherOptions->other[parserData->numberOfOtherServiceOptions]->value = (yyvsp[(2) - (2)].sval);
	}
;}
    break;

  case 210:

    {	if (parserData->otherOptionDescriptionPresent)
	{	osolerror( NULL, osoption, parserData, "only one description attribute allowed");
	}
	else
	{	parserData->otherOptionDescriptionPresent = true;
		osoption->service->otherOptions->other[parserData->numberOfOtherServiceOptions]->description = (yyvsp[(2) - (2)].sval);
	}
;}
    break;

  case 216:

    {	if (parserData->osoljobPresent)
	{	osolerror( NULL, osoption, parserData, "only one <job> element allowed");
	}
	else
	{	parserData->osoljobPresent = true;
		osoption->job = new JobOption();
	}
;}
    break;

  case 237:

    {	if (parserData->maxTimePresent)
	{	osolerror( NULL, osoption, parserData, "only one <maxTime> element allowed");
	}
	else
	{	parserData->maxTimePresent = true;
		osoption->job->maxTime = new MaxTime();
		osoption->job->maxTime->unit = "second"; 
	}
;}
    break;

  case 239:

    {	if ( (strcmp((yyvsp[(2) - (2)].sval),"second") == 0) || (strcmp((yyvsp[(2) - (2)].sval),"minute") == 0) || (strcmp((yyvsp[(2) - (2)].sval),"hour") == 0) ||
						     (strcmp((yyvsp[(2) - (2)].sval),"day")    == 0) || (strcmp((yyvsp[(2) - (2)].sval),"week") == 0) ||
						     (strcmp((yyvsp[(2) - (2)].sval),"month")  == 0) || (strcmp((yyvsp[(2) - (2)].sval),"year") == 0) ) 
                osoption->job->maxTime->unit = (yyvsp[(2) - (2)].sval);
	else
		osolerror( NULL, osoption, parserData, "Not a valid time unit");
;}
    break;

  case 243:

    {	if ((yyvsp[(2) - (3)].dval) < 0)
		osolerror( NULL, osoption, parserData, "maxTime cannot be negative");
	osoption->job->maxTime->value = (yyvsp[(2) - (3)].dval);
;}
    break;

  case 244:

    {	if ((yyvsp[(2) - (3)].ival) < 0)
		osolerror( NULL, osoption, parserData, "maxTime cannot be negative");
	osoption->job->maxTime->value = (yyvsp[(2) - (3)].ival);
;}
    break;

  case 246:

    {	if (parserData->requestedStartTimePresent)
	{	osolerror( NULL, osoption, parserData, "only one <requestedStartTime> element allowed");
	}
	else
	{	parserData->requestedStartTimePresent = true;
		osoption->job->requestedStartTime = "1970-01-01T00:00:00-00:00";
	}
;}
    break;

  case 249:

    {osoption->job->requestedStartTime = (yyvsp[(2) - (2)].sval);;}
    break;

  case 252:

    {	if (parserData->dependenciesPresent)
	{	osolerror( NULL, osoption, parserData, "only one <dependencies> element allowed");
	}
	else
	{	parserData->dependenciesPresent = true;
		osoption->job->dependencies = new JobDependencies();
	}
;}
    break;

  case 253:

    {	if ((yyvsp[(3) - (4)].ival) < 1)
		osolerror( NULL, osoption, parserData, "Number of job IDs must be at least 1");
	osoption->job->dependencies->numberOfJobIDs = (yyvsp[(3) - (4)].ival);
	osoption->job->dependencies->jobID = new std::string[(yyvsp[(3) - (4)].ival)];
;}
    break;

  case 256:

    {
	if (parserData->numberOfDependencies >= osoption->job->dependencies->numberOfJobIDs)
	{	osolerror (NULL, osoption, parserData, "too many job IDs in <dependencies> element");
	}
	else
	{	osoption->job->dependencies->jobID[parserData->numberOfDependencies] = (yyvsp[(3) - (3)].sval);
		parserData->numberOfDependencies++;
	};
;}
    break;

  case 259:

    {	if (parserData->requiredDirectoriesPresent)
	{	osolerror( NULL, osoption, parserData, "only one <requiredDirectories> element allowed");
	}
	else
	{	parserData->requiredDirectoriesPresent = true;
		osoption->job->requiredDirectories = new DirectoriesAndFiles();
	}
;}
    break;

  case 260:

    {	if ((yyvsp[(3) - (4)].ival) < 1)
		osolerror( NULL, osoption, parserData, "Number of paths must be at least 1");
	osoption->job->requiredDirectories->numberOfPaths = (yyvsp[(3) - (4)].ival);
	osoption->job->requiredDirectories->path = new std::string[(yyvsp[(3) - (4)].ival)];
;}
    break;

  case 263:

    {
	if (parserData->numberOfRequiredDirectories >= osoption->job->requiredDirectories->numberOfPaths)
	{	osolerror (NULL, osoption, parserData, "too many job IDs in <requiredDirectories> element");
	}
	else
	{	osoption->job->requiredDirectories->path[parserData->numberOfRequiredDirectories] = (yyvsp[(3) - (3)].sval);
		parserData->numberOfRequiredDirectories++;
	};
;}
    break;

  case 266:

    {	if (parserData->requiredFilesPresent)
	{	osolerror( NULL, osoption, parserData, "only one <requiredFiles> element allowed");
	}
	else
	{	parserData->requiredFilesPresent = true;
		osoption->job->requiredFiles = new DirectoriesAndFiles();
	}
;}
    break;

  case 267:

    {	if ((yyvsp[(3) - (4)].ival) < 1)
		osolerror( NULL, osoption, parserData, "Number of paths must be at least 1");
	osoption->job->requiredFiles->numberOfPaths = (yyvsp[(3) - (4)].ival);
	osoption->job->requiredFiles->path = new std::string[(yyvsp[(3) - (4)].ival)];
;}
    break;

  case 270:

    {
	if (parserData->numberOfRequiredFiles >= osoption->job->requiredFiles->numberOfPaths)
	{	osolerror (NULL, osoption, parserData, "too many job IDs in <requiredFiles> element");
	}
	else
	{	osoption->job->requiredFiles->path[parserData->numberOfRequiredFiles] = (yyvsp[(3) - (3)].sval);
		parserData->numberOfRequiredFiles++;
	};
;}
    break;

  case 273:

    {	if (parserData->directoriesToMakePresent)
	{	osolerror( NULL, osoption, parserData, "only one <directoriesToMake> element allowed");
	}
	else
	{	parserData->directoriesToMakePresent = true;
		osoption->job->directoriesToMake = new DirectoriesAndFiles();
	}
;}
    break;

  case 274:

    {	if ((yyvsp[(3) - (4)].ival) < 1)
		osolerror( NULL, osoption, parserData, "Number of paths must be at least 1");
	osoption->job->directoriesToMake->numberOfPaths = (yyvsp[(3) - (4)].ival);
	osoption->job->directoriesToMake->path = new std::string[(yyvsp[(3) - (4)].ival)];
;}
    break;

  case 277:

    {	if (parserData->numberOfDirectoriesToMake >= osoption->job->directoriesToMake->numberOfPaths)
	{	osolerror (NULL, osoption, parserData, "too many job IDs in <directoriesToMake> element");
	}
	else
	{	osoption->job->directoriesToMake->path[parserData->numberOfDirectoriesToMake] = (yyvsp[(3) - (3)].sval);
		parserData->numberOfDirectoriesToMake++;
	};
;}
    break;

  case 280:

    {	if (parserData->filesToMakePresent)
	{	osolerror( NULL, osoption, parserData, "only one <filesToMake> element allowed");
	}
	else
	{	parserData->filesToMakePresent = true;
		osoption->job->filesToMake = new DirectoriesAndFiles();
	}
;}
    break;

  case 281:

    {	if ((yyvsp[(3) - (4)].ival) < 0)
		osolerror( NULL, osoption, parserData, "Number of paths cannot be negative");
	osoption->job->filesToMake->numberOfPaths = (yyvsp[(3) - (4)].ival);
	osoption->job->filesToMake->path = new std::string[(yyvsp[(3) - (4)].ival)];
;}
    break;

  case 284:

    {	if (parserData->numberOfFilesToMake >= osoption->job->filesToMake->numberOfPaths)
	{	osolerror (NULL, osoption, parserData, "too many job IDs in <filesToMake> element");
	}
	else
	{	osoption->job->filesToMake->path[parserData->numberOfFilesToMake] = (yyvsp[(3) - (3)].sval);
		parserData->numberOfFilesToMake++;
	};
;}
    break;

  case 287:

    {	if (parserData->inputDirectoriesToMovePresent)
	{	osolerror( NULL, osoption, parserData, "only one <inputDirectoriesToMove> element allowed");
	}
	else
	{	parserData->inputDirectoriesToMovePresent = true;
		osoption->job->inputDirectoriesToMove = new PathPairs();
	}
;}
    break;

  case 288:

    {	if ((yyvsp[(3) - (4)].ival) < 0)
		osolerror (NULL, osoption, parserData, "Require nonnegative number of directories to move");
	osoption->job->inputDirectoriesToMove->numberOfPathPairs = (yyvsp[(3) - (4)].ival);
	osoption->job->inputDirectoriesToMove->pathPair = new PathPair*[(yyvsp[(3) - (4)].ival)];
	for (int i = 0; i < (yyvsp[(3) - (4)].ival); i++)
		osoption->job->inputDirectoriesToMove->pathPair[i] = new PathPair();
;}
    break;

  case 291:

    {	if (!parserData->pathPairFromPresent)
		osolerror (NULL, osoption, parserData, "\"from\" attribute must be present");
	if (!parserData->pathPairToPresent)
		osolerror (NULL, osoption, parserData, "\"to\" attribute must be present");
	/* reset defaults for the next option */
	parserData->pathPairFromPresent= false;
	parserData->pathPairToPresent= false;
	parserData->pathPairMakeCopyPresent= false;
	parserData->numberOfInputDirectoriesToMove++;
;}
    break;

  case 292:

    {	if (parserData->numberOfInputDirectoriesToMove >= osoption->job->inputDirectoriesToMove->numberOfPathPairs)
	{	osolerror (NULL, osoption, parserData, "too many path pairs in <inputDirectoriesToMove> element");
	};
;}
    break;

  case 298:

    {	if (parserData->pathPairFromPresent)
	{	osolerror( NULL, osoption, parserData, "only one \"from\" attribute allowed");
	}
	else
	{	parserData->pathPairFromPresent = true;
		osoption->job->inputDirectoriesToMove->pathPair[parserData->numberOfInputDirectoriesToMove]->from = (yyvsp[(2) - (2)].sval);
	}
;}
    break;

  case 300:

    {	if (parserData->pathPairToPresent)
	{	osolerror( NULL, osoption, parserData, "only one \"to\" attribute allowed");
	}
	else
	{	parserData->pathPairToPresent = true;
		osoption->job->inputDirectoriesToMove->pathPair[parserData->numberOfInputDirectoriesToMove]->to = (yyvsp[(2) - (2)].sval);
	}
;}
    break;

  case 302:

    {	if (parserData->pathPairMakeCopyPresent)
	{	osolerror( NULL, osoption, parserData, "only one \"makeCopy\" attribute allowed");
	}
	else
	{	parserData->pathPairMakeCopyPresent = true;
		if (strcmp((yyvsp[(2) - (2)].sval),"true") == 0)
			osoption->job->inputDirectoriesToMove->pathPair[parserData->numberOfInputDirectoriesToMove]->makeCopy = true;
	}
;}
    break;

  case 307:

    {	if (parserData->inputFilesToMovePresent)
	{	osolerror( NULL, osoption, parserData, "only one <inputFilesToMove> element allowed");
	}
	else
	{	parserData->inputFilesToMovePresent = true;
		osoption->job->inputFilesToMove = new PathPairs();
	}
;}
    break;

  case 308:

    {	if ((yyvsp[(3) - (4)].ival) < 0)
		osolerror (NULL, osoption, parserData, "Require nonnegative number of files to move");
	osoption->job->inputFilesToMove->numberOfPathPairs = (yyvsp[(3) - (4)].ival);
	osoption->job->inputFilesToMove->pathPair = new PathPair*[(yyvsp[(3) - (4)].ival)];
	for (int i = 0; i < (yyvsp[(3) - (4)].ival); i++) osoption->job->inputFilesToMove->pathPair[i] = new PathPair();
;}
    break;

  case 311:

    {	if (!parserData->pathPairFromPresent)
		osolerror (NULL, osoption, parserData, "\"from\" attribute must be present");
	if (!parserData->pathPairToPresent)
		osolerror (NULL, osoption, parserData, "\"to\" attribute must be present");
	/* reset defaults for the next option */
	parserData->pathPairFromPresent= false;
	parserData->pathPairToPresent= false;
	parserData->pathPairMakeCopyPresent= false;
	parserData->numberOfInputFilesToMove++;
;}
    break;

  case 312:

    {	if (parserData->numberOfInputFilesToMove >= osoption->job->inputFilesToMove->numberOfPathPairs)
	{	osolerror (NULL, osoption, parserData, "too many path pairs in <inputFilesToMove> element");
	};
;}
    break;

  case 318:

    {	if (parserData->pathPairFromPresent)
	{	osolerror( NULL, osoption, parserData, "only one \"from\" attribute allowed");
	}
	else
	{	parserData->pathPairFromPresent = true;
		osoption->job->inputFilesToMove->pathPair[parserData->numberOfInputFilesToMove]->from = (yyvsp[(2) - (2)].sval);
	}
;}
    break;

  case 320:

    {	if (parserData->pathPairToPresent)
	{	osolerror( NULL, osoption, parserData, "only one \"to\" attribute allowed");
	}
	else
	{	parserData->pathPairToPresent = true;
		osoption->job->inputFilesToMove->pathPair[parserData->numberOfInputFilesToMove]->to = (yyvsp[(2) - (2)].sval);
	}
;}
    break;

  case 322:

    {	if (parserData->pathPairMakeCopyPresent)
	{	osolerror( NULL, osoption, parserData, "only one \"makeCopy\" attribute allowed");
	}
	else
	{	parserData->pathPairMakeCopyPresent = true;
		if (strcmp((yyvsp[(2) - (2)].sval),"true") == 0)
			osoption->job->inputFilesToMove->pathPair[parserData->numberOfInputFilesToMove]->makeCopy = true;
	}
;}
    break;

  case 327:

    {	if (parserData->outputDirectoriesToMovePresent)
	{	osolerror( NULL, osoption, parserData, "only one <outputDirectoriesToMove> element allowed");
	}
	else
	{	parserData->outputDirectoriesToMovePresent = true;
		osoption->job->outputDirectoriesToMove = new PathPairs();
	}
;}
    break;

  case 328:

    {	if ((yyvsp[(3) - (4)].ival) < 0)
		osolerror (NULL, osoption, parserData, "Require nonnegative number of directories to move");
	osoption->job->outputDirectoriesToMove->numberOfPathPairs = (yyvsp[(3) - (4)].ival);
	osoption->job->outputDirectoriesToMove->pathPair = new PathPair*[(yyvsp[(3) - (4)].ival)];
	for (int i = 0; i < (yyvsp[(3) - (4)].ival); i++)
		osoption->job->outputDirectoriesToMove->pathPair[i] = new PathPair();
;}
    break;

  case 331:

    {	if (!parserData->pathPairFromPresent)
		osolerror (NULL, osoption, parserData, "\"from\" attribute must be present");
	if (!parserData->pathPairToPresent)
		osolerror (NULL, osoption, parserData, "\"to\" attribute must be present");
	/* reset defaults for the next option */
	parserData->pathPairFromPresent= false;
	parserData->pathPairToPresent= false;
	parserData->pathPairMakeCopyPresent= false;
	parserData->numberOfOutputDirectoriesToMove++;
;}
    break;

  case 332:

    {	if (parserData->numberOfOutputDirectoriesToMove >= osoption->job->outputDirectoriesToMove->numberOfPathPairs)
	{	osolerror (NULL, osoption, parserData, "too many path pairs in <outputDirectoriesToMove> element");
	};
;}
    break;

  case 338:

    {	if (parserData->pathPairFromPresent)
	{	osolerror( NULL, osoption, parserData, "only one \"from\" attribute allowed");
	}
	else
	{	parserData->pathPairFromPresent = true;
		osoption->job->outputDirectoriesToMove->pathPair[parserData->numberOfOutputDirectoriesToMove]->from = (yyvsp[(2) - (2)].sval);
	}
;}
    break;

  case 340:

    {	if (parserData->pathPairToPresent)
	{	osolerror( NULL, osoption, parserData, "only one \"to\" attribute allowed");
	}
	else
	{	parserData->pathPairToPresent = true;
		osoption->job->outputDirectoriesToMove->pathPair[parserData->numberOfOutputDirectoriesToMove]->to = (yyvsp[(2) - (2)].sval);
	}
;}
    break;

  case 342:

    {	if (parserData->pathPairMakeCopyPresent)
	{	osolerror( NULL, osoption, parserData, "only one \"makeCopy\" attribute allowed");
	}
	else
	{	parserData->pathPairMakeCopyPresent = true;
		if (strcmp((yyvsp[(2) - (2)].sval),"true") == 0)
			osoption->job->outputDirectoriesToMove->pathPair[parserData->numberOfOutputDirectoriesToMove]->makeCopy = true;
	}
;}
    break;

  case 347:

    {	if (parserData->outputFilesToMovePresent)
	{	osolerror( NULL, osoption, parserData, "only one <outputFilesToMove> element allowed");
	}
	else
	{	parserData->outputFilesToMovePresent = true;
		osoption->job->outputFilesToMove = new PathPairs();
	}
;}
    break;

  case 348:

    {	if ((yyvsp[(3) - (4)].ival) < 0)
		osolerror (NULL, osoption, parserData, "Require nonnegative number of files to move");
	osoption->job->outputFilesToMove->numberOfPathPairs = (yyvsp[(3) - (4)].ival);
	osoption->job->outputFilesToMove->pathPair = new PathPair*[(yyvsp[(3) - (4)].ival)];
	for (int i = 0; i < (yyvsp[(3) - (4)].ival); i++)
		osoption->job->outputFilesToMove->pathPair[i] = new PathPair();;}
    break;

  case 351:

    {	if (!parserData->pathPairFromPresent)
		osolerror (NULL, osoption, parserData, "\"from\" attribute must be present");
	if (!parserData->pathPairToPresent)
		osolerror (NULL, osoption, parserData, "\"to\" attribute must be present");
	/* reset defaults for the next option */
	parserData->pathPairFromPresent= false;
	parserData->pathPairToPresent= false;
	parserData->pathPairMakeCopyPresent= false;
	parserData->numberOfOutputFilesToMove++;
;}
    break;

  case 352:

    {	if (parserData->numberOfOutputFilesToMove >= osoption->job->outputFilesToMove->numberOfPathPairs)
	{	osolerror (NULL, osoption, parserData, "too many path pairs in <outputFilesToMove> element");
	};
;}
    break;

  case 358:

    {	if (parserData->pathPairFromPresent)
	{	osolerror( NULL, osoption, parserData, "only one \"from\" attribute allowed");
	}
	else
	{	parserData->pathPairFromPresent = true;
		osoption->job->outputFilesToMove->pathPair[parserData->numberOfOutputFilesToMove]->from = (yyvsp[(2) - (2)].sval);
	}
;}
    break;

  case 360:

    {	if (parserData->pathPairToPresent)
	{	osolerror( NULL, osoption, parserData, "only one \"to\" attribute allowed");
	}
	else
	{	parserData->pathPairToPresent = true;
		osoption->job->outputFilesToMove->pathPair[parserData->numberOfOutputFilesToMove]->to = (yyvsp[(2) - (2)].sval);
	}
;}
    break;

  case 362:

    {	if (parserData->pathPairMakeCopyPresent)
	{	osolerror( NULL, osoption, parserData, "only one \"makeCopy\" attribute allowed");
	}
	else
	{	parserData->pathPairMakeCopyPresent = true;
		if (strcmp((yyvsp[(2) - (2)].sval),"true") == 0)
			osoption->job->outputFilesToMove->pathPair[parserData->numberOfOutputFilesToMove]->makeCopy = true;
	}
;}
    break;

  case 367:

    {	if (parserData->filesToDeletePresent)
	{	osolerror( NULL, osoption, parserData, "only one <filesToDelete> element allowed");
	}
	else
	{	parserData->filesToDeletePresent = true;
		osoption->job->filesToDelete = new DirectoriesAndFiles();
	}
;}
    break;

  case 368:

    {	if ((yyvsp[(3) - (4)].ival) < 1)
		osolerror( NULL, osoption, parserData, "Number of paths must be at least 1");
	osoption->job->filesToDelete->numberOfPaths = (yyvsp[(3) - (4)].ival);
	osoption->job->filesToDelete->path = new std::string[(yyvsp[(3) - (4)].ival)];
;}
    break;

  case 371:

    {	if (parserData->numberOfFilesToDelete >= osoption->job->filesToDelete->numberOfPaths)
	{	osolerror (NULL, osoption, parserData, "too many job IDs in <filesToDelete> element");
	}
	else
	{	osoption->job->filesToDelete->path[parserData->numberOfFilesToDelete] = (yyvsp[(3) - (3)].sval);
		parserData->numberOfFilesToDelete++;
	};
;}
    break;

  case 374:

    {	if (parserData->directoriesToDeletePresent)
	{	osolerror( NULL, osoption, parserData, "only one <directoriesToDelete> element allowed");
	}
	else
	{	parserData->directoriesToDeletePresent = true;
		osoption->job->directoriesToDelete = new DirectoriesAndFiles();
	}
;}
    break;

  case 375:

    {	if ((yyvsp[(3) - (4)].ival) < 1)
		osolerror( NULL, osoption, parserData, "Number of paths must be at least 1");
	osoption->job->directoriesToDelete->numberOfPaths = (yyvsp[(3) - (4)].ival);
	osoption->job->directoriesToDelete->path = new std::string[(yyvsp[(3) - (4)].ival)];
;}
    break;

  case 378:

    {	if (parserData->numberOfDirectoriesToDelete >= osoption->job->directoriesToDelete->numberOfPaths)
	{	osolerror (NULL, osoption, parserData, "too many job IDs in <directoriesToDelete> element");
	}
	else
	{	osoption->job->directoriesToDelete->path[parserData->numberOfDirectoriesToDelete] = (yyvsp[(3) - (3)].sval);
		parserData->numberOfDirectoriesToDelete++;
	};
;}
    break;

  case 381:

    {	if (parserData->processesToKillPresent)
	{	osolerror( NULL, osoption, parserData, "only one <processesToKill> element allowed");
	}
	else
	{	parserData->processesToKillPresent = true;
		osoption->job->processesToKill = new Processes();
	}
;}
    break;

  case 382:

    {	if ((yyvsp[(3) - (4)].ival) < 1)
		osolerror( NULL, osoption, parserData, "Number of job IDs must be at least 1");
	osoption->job->processesToKill->numberOfProcesses = (yyvsp[(3) - (4)].ival);
	osoption->job->processesToKill->process = new std::string[(yyvsp[(3) - (4)].ival)];
;}
    break;

  case 385:

    {	if (parserData->numberOfProcessesToKill >= osoption->job->processesToKill->numberOfProcesses)
	{	osolerror (NULL, osoption, parserData, "too many job IDs in <processesToKill> element");
	}
	else
	{	osoption->job->processesToKill->process[parserData->numberOfProcessesToKill] = (yyvsp[(3) - (3)].sval);
		parserData->numberOfProcessesToKill++;
	};
;}
    break;

  case 388:

    {	if (parserData->otherJobOptionsPresent)
	{	osolerror( NULL, osoption, parserData, "only one <otherOptions> element allowed");
	}
	else
	{	parserData->otherJobOptionsPresent = true;
		osoption->job->otherOptions = new OtherOptions();
	}
;}
    break;

  case 389:

    {	if ((yyvsp[(3) - (4)].ival) < 0)
		osolerror( NULL, osoption, parserData, "Number of <other> elements cannot be negative");
	osoption->job->otherOptions->numberOfOtherOptions = (yyvsp[(3) - (4)].ival);
	osoption->job->otherOptions->other = new OtherOption*[(yyvsp[(3) - (4)].ival)];
	for (int i=0; i < (yyvsp[(3) - (4)].ival); i++) osoption->job->otherOptions->other[i] = new OtherOption();
;}
    break;

  case 390:

    {	if (parserData->numberOfOtherJobOptions != osoption->job->otherOptions->numberOfOtherOptions)
		osolerror (NULL, osoption, parserData, "wrong number of other options in <job> element");
;}
    break;

  case 393:

    {	if (parserData->numberOfOtherJobOptions >= osoption->job->otherOptions->numberOfOtherOptions)
		{	osolerror (NULL, osoption, parserData, "too many other options in <job> element");
		};
	;}
    break;

  case 394:

    {	if (!parserData->otherOptionNamePresent)
		osolerror (NULL, osoption, parserData, "name attribute must be present");
	/* reset defaults for the next option */
	parserData->otherOptionNamePresent = false;
	parserData->otherOptionValuePresent = false;
	parserData->otherOptionDescriptionPresent = false;
	parserData->numberOfOtherJobOptions++;
;}
    break;

  case 400:

    {	if (parserData->otherOptionNamePresent)
	{	osolerror( NULL, osoption, parserData, "only one name attribute allowed");
	}
	else
	{	parserData->otherOptionNamePresent = true;
		osoption->job->otherOptions->other[parserData->numberOfOtherJobOptions]->name = (yyvsp[(2) - (2)].sval);
	}
;}
    break;

  case 402:

    {	if (parserData->otherOptionValuePresent)
	{	osolerror( NULL, osoption, parserData, "only one value attribute allowed");
	}
	else
	{	parserData->otherOptionValuePresent = true;
		osoption->job->otherOptions->other[parserData->numberOfOtherJobOptions]->value = (yyvsp[(2) - (2)].sval);
	}
;}
    break;

  case 404:

    {	if (parserData->otherOptionDescriptionPresent)
	{	osolerror( NULL, osoption, parserData, "only one description attribute allowed");
	}
	else
	{	parserData->otherOptionDescriptionPresent = true;
		osoption->job->otherOptions->other[parserData->numberOfOtherJobOptions]->description = (yyvsp[(2) - (2)].sval);
	}
;}
    break;

  case 410:

    {	if (parserData->osoloptimizationPresent)
	{	osolerror( NULL, osoption, parserData, "only one <optimization> element allowed");
	}
	else
	{	parserData->osoloptimizationPresent = true;
		osoption->optimization = new OptimizationOption();
	}
;}
    break;

  case 416:

    {	if ((yyvsp[(3) - (4)].ival) < -1)
		osolerror( NULL, osoption, parserData, "Illegal number of variables specified");  
	osoption->optimization->numberOfVariables = (yyvsp[(3) - (4)].ival);
;}
    break;

  case 417:

    {	if ((yyvsp[(3) - (4)].ival) < 0)
		osolerror( NULL, osoption, parserData, "Illegal number of constraints specified");
	osoption->optimization->numberOfConstraints = (yyvsp[(3) - (4)].ival);
;}
    break;

  case 418:

    {	if ((yyvsp[(3) - (4)].ival) < 0)
		osolerror( NULL, osoption, parserData, "Illegal number of objectives specified");
	osoption->optimization->numberOfObjectives = (yyvsp[(3) - (4)].ival);
;}
    break;

  case 424:

    {	osoption->optimization->variables = new VariableOption();
;}
    break;

  case 426:

    {	if ((yyvsp[(3) - (4)].ival) < 0)
		osolerror (NULL, osoption, parserData, "number of <other> variable options cannot be negative");
	osoption->optimization->variables->numberOfOtherVariableOptions = (yyvsp[(3) - (4)].ival);
	osoption->optimization->variables->other = new OtherVariableOption*[(yyvsp[(3) - (4)].ival)];
	for (int i= 0; i < (yyvsp[(3) - (4)].ival); i++)
		osoption->optimization->variables->other[i] = new OtherVariableOption();
;}
    break;

  case 431:

    {	if ((yyvsp[(3) - (4)].ival) < 0)
		osolerror (NULL, osoption, parserData, "number of <var> elements must be nonnegative");
	osoption->optimization->variables->initialVariableValues = new InitVariableValues();
	osoption->optimization->variables->initialVariableValues->numberOfVar = (yyvsp[(3) - (4)].ival);
	osoption->optimization->variables->initialVariableValues->var = new InitVarValue*[(yyvsp[(3) - (4)].ival)];
	for (int i = 0; i < (yyvsp[(3) - (4)].ival); i++)
		osoption->optimization->variables->initialVariableValues->var[i] = new InitVarValue();
;}
    break;

  case 434:

    {	if (!parserData->idxAttributePresent)
		osolerror (NULL, osoption, parserData, "variable index required");
	parserData->idxAttributePresent = false;
	parserData->valAttributePresent = false;
	parserData->numberOfVar++;
;}
    break;

  case 435:

    {	if (parserData->numberOfVar >= osoption->optimization->variables->initialVariableValues->numberOfVar)
		osolerror(NULL, osoption, parserData, "too many initial variable values");
;}
    break;

  case 440:

    {	if (parserData->idxAttributePresent)
		osolerror (NULL, osoption, parserData, "only one variable index allowed");
	parserData->idxAttributePresent = true;
	if ((yyvsp[(3) - (4)].ival) < 0)
		osolerror (NULL, osoption, parserData, "variable index must be nonnegative");
	if (osoption->optimization->numberOfVariables >= 0)
	{	if ((yyvsp[(3) - (4)].ival) >= osoption->optimization->numberOfVariables)
			osolerror (NULL, osoption, parserData, "variable index exceeds upper limit");
	};
	osoption->optimization->variables->initialVariableValues->var[parserData->numberOfVar]->idx = (yyvsp[(3) - (4)].ival);
;}
    break;

  case 441:

    {	if (parserData->valAttributePresent)
		osolerror (NULL, osoption, parserData, "only one variable value allowed");
	parserData->valAttributePresent = true;
	if (strcmp((yyvsp[(2) - (2)].sval),"INF") == 0)
		osoption->optimization->variables->initialVariableValues->var[parserData->numberOfVar]->value = OSDBL_MAX;
	else if (strcmp((yyvsp[(2) - (2)].sval),"-INF") == 0)
		osoption->optimization->variables->initialVariableValues->var[parserData->numberOfVar]->value = -OSDBL_MAX;
	else
		osoption->optimization->variables->initialVariableValues->var[parserData->numberOfVar]->value = os_strtod((yyvsp[(2) - (2)].sval), NULL);
;}
    break;

  case 447:

    {	if ((yyvsp[(3) - (4)].ival) < 0)
		osolerror (NULL, osoption, parserData, "number of <var> elements must be nonnegative");
	osoption->optimization->variables->initialVariableValuesString = new InitVariableValuesString();
	osoption->optimization->variables->initialVariableValuesString->numberOfVar = (yyvsp[(3) - (4)].ival);
	osoption->optimization->variables->initialVariableValuesString->var = new InitVarValueString*[(yyvsp[(3) - (4)].ival)];
	for (int i = 0; i < (yyvsp[(3) - (4)].ival); i++)
		osoption->optimization->variables->initialVariableValuesString->var[i] = new InitVarValueString ();
;}
    break;

  case 450:

    {	if (!parserData->idxAttributePresent)
		osolerror (NULL, osoption, parserData, "variable index required");
	parserData->idxAttributePresent = false;
	parserData->valAttributePresent = false;
	parserData->numberOfVarStr++;
;}
    break;

  case 451:

    {	if (parserData->numberOfVarStr >= osoption->optimization->variables->initialVariableValuesString->numberOfVar)
		osolerror(NULL, osoption, parserData, "too many initial variable strings");
;}
    break;

  case 456:

    {	if (parserData->idxAttributePresent)
		osolerror (NULL, osoption, parserData, "only one variable index allowed");
	parserData->idxAttributePresent = true;
	if ((yyvsp[(3) - (4)].ival) < 0)
		osolerror (NULL, osoption, parserData, "variable index must be nonnegative");
	if (osoption->optimization->numberOfVariables >= 0)
	{	if ((yyvsp[(3) - (4)].ival) >= osoption->optimization->numberOfVariables)
			osolerror (NULL, osoption, parserData, "variable index exceeds upper limit");
	};
	osoption->optimization->variables->initialVariableValuesString->var[parserData->numberOfVarStr]->idx = (yyvsp[(3) - (4)].ival);
;}
    break;

  case 457:

    {	if (parserData->valAttributePresent)
		osolerror (NULL, osoption, parserData, "only one variable string value allowed");
	parserData->valAttributePresent = true;
	osoption->optimization->variables->initialVariableValuesString->var[parserData->numberOfVarStr]->value = (yyvsp[(2) - (2)].sval);
;}
    break;

  case 463:

    {	if ((yyvsp[(3) - (4)].ival) < 0)
		osolerror (NULL, osoption, parserData, "number of <var> elements must be nonnegative");
	osoption->optimization->variables->initialBasisStatus = new InitialBasisStatus();
	osoption->optimization->variables->initialBasisStatus->numberOfVar = (yyvsp[(3) - (4)].ival);
	osoption->optimization->variables->initialBasisStatus->var = new InitBasStatus*[(yyvsp[(3) - (4)].ival)];
	for (int i = 0; i < (yyvsp[(3) - (4)].ival); i++)
		osoption->optimization->variables->initialBasisStatus->var[i] = new InitBasStatus();
;}
    break;

  case 466:

    {	if (!parserData->idxAttributePresent)
		osolerror (NULL, osoption, parserData, "variable index required");
	parserData->idxAttributePresent = false;
	parserData->valAttributePresent = false;
	parserData->numberOfBasVar++;
;}
    break;

  case 467:

    {	if (parserData->numberOfBasVar >= osoption->optimization->variables->initialBasisStatus->numberOfVar)
		osolerror(NULL, osoption, parserData, "too many initial basis variables");
;}
    break;

  case 472:

    {	if (parserData->idxAttributePresent)
		osolerror (NULL, osoption, parserData, "only one variable index allowed");
	parserData->idxAttributePresent = true;
	if ((yyvsp[(3) - (4)].ival) < 0)
		osolerror (NULL, osoption, parserData, "variable index must be nonnegative");
	if (osoption->optimization->numberOfVariables >= 0)
	{	if ((yyvsp[(3) - (4)].ival) >= osoption->optimization->numberOfVariables)
			osolerror (NULL, osoption, parserData, "variable index exceeds upper limit");
	};
	osoption->optimization->variables->initialBasisStatus->var[parserData->numberOfBasVar]->idx = (yyvsp[(3) - (4)].ival);
;}
    break;

  case 473:

    {	if (parserData->valAttributePresent)
		osolerror (NULL, osoption, parserData, "only one variable value allowed");
	parserData->valAttributePresent = true;
	osoption->optimization->variables->initialBasisStatus->var[parserData->numberOfBasVar]->value = (yyvsp[(2) - (2)].sval);
;}
    break;

  case 479:

    {	if ((yyvsp[(3) - (4)].ival) < 0)
		osolerror (NULL, osoption, parserData, "number of <var> elements must be nonnegative");
	osoption->optimization->variables->integerVariableBranchingWeights = new IntegerVariableBranchingWeights();
	osoption->optimization->variables->integerVariableBranchingWeights->numberOfVar = (yyvsp[(3) - (4)].ival);
	osoption->optimization->variables->integerVariableBranchingWeights->var = new BranchingWeight*[(yyvsp[(3) - (4)].ival)];
	for (int i = 0; i < (yyvsp[(3) - (4)].ival); i++)
		osoption->optimization->variables->integerVariableBranchingWeights->var[i] = new BranchingWeight();
;}
    break;

  case 482:

    {	if (!parserData->idxAttributePresent)
		osolerror (NULL, osoption, parserData, "variable index required");
	parserData->idxAttributePresent = false;
	parserData->valAttributePresent = false;
	parserData->numberOfIntWt++;
;}
    break;

  case 483:

    {	if (parserData->numberOfIntWt >= osoption->optimization->variables->integerVariableBranchingWeights->numberOfVar)
		osolerror(NULL, osoption, parserData, "too many integer branching weights");
;}
    break;

  case 488:

    {	if (parserData->idxAttributePresent)
		osolerror (NULL, osoption, parserData, "only one variable index allowed");
	parserData->idxAttributePresent = true;
	if ((yyvsp[(3) - (4)].ival) < 0)
		osolerror (NULL, osoption, parserData, "variable index must be nonnegative");
	if (osoption->optimization->numberOfVariables >= 0)
	{	if ((yyvsp[(3) - (4)].ival) >= osoption->optimization->numberOfVariables)
			osolerror (NULL, osoption, parserData, "variable index exceeds upper limit");
	};
	osoption->optimization->variables->integerVariableBranchingWeights->var[parserData->numberOfIntWt]->idx = (yyvsp[(3) - (4)].ival);
;}
    break;

  case 489:

    {	if (parserData->valAttributePresent)
		osolerror (NULL, osoption, parserData, "only one branching weight allowed");
	parserData->valAttributePresent = true;
	if (strcmp((yyvsp[(2) - (2)].sval),"INF") == 0)
		osoption->optimization->variables->integerVariableBranchingWeights->var[parserData->numberOfIntWt]->value = OSDBL_MAX;
	else if (strcmp((yyvsp[(2) - (2)].sval),"-INF") == 0)
		osoption->optimization->variables->integerVariableBranchingWeights->var[parserData->numberOfIntWt]->value = -OSDBL_MAX;
	else
		osoption->optimization->variables->integerVariableBranchingWeights->var[parserData->numberOfIntWt]->value = os_strtod((yyvsp[(2) - (2)].sval), NULL);
;}
    break;

  case 495:

    {	if ((yyvsp[(3) - (4)].ival) < 0)
		osolerror (NULL, osoption, parserData, "number of <sos> elements must be nonnegative");
	osoption->optimization->variables->sosVariableBranchingWeights = new SOSVariableBranchingWeights();
	osoption->optimization->variables->sosVariableBranchingWeights->numberOfSOS = (yyvsp[(3) - (4)].ival);
	osoption->optimization->variables->sosVariableBranchingWeights->sos = new SOSWeights*[(yyvsp[(3) - (4)].ival)];
	for (int i = 0; i < (yyvsp[(3) - (4)].ival); i++)
		osoption->optimization->variables->sosVariableBranchingWeights->sos[i] = new SOSWeights();
;}
    break;

  case 498:

    {	if (!parserData->sosIdxAttributePresent)
		osolerror (NULL, osoption, parserData, "SOS index required");
	if (!parserData->sosIdxAttributePresent)
		osolerror (NULL, osoption, parserData, "numberOfVar required");
	parserData->sosIdxAttributePresent = false;
	parserData->grpWgtAttributePresent = false;
	parserData->nOfVarAttributePresent = false;
	parserData->numberOfSOS++;
;}
    break;

  case 499:

    {	if (parserData->numberOfSOS >= osoption->optimization->variables->sosVariableBranchingWeights->numberOfSOS)
		osolerror(NULL, osoption, parserData, "too many SOS branching weights");
	parserData->numberOfSOSVar = 0;
;}
    break;

  case 505:

    {	if (parserData->sosIdxAttributePresent)
		osolerror (NULL, osoption, parserData, "only one SOS index allowed");
	parserData->sosIdxAttributePresent = true;
	if ((yyvsp[(3) - (4)].ival) < 0)
		osolerror (NULL, osoption, parserData, "SOS index must be nonnegative");
	osoption->optimization->variables->sosVariableBranchingWeights->sos[parserData->numberOfSOS]->sosIdx = (yyvsp[(3) - (4)].ival);
;}
    break;

  case 506:

    {	if (parserData->grpWgtAttributePresent)
		osolerror (NULL, osoption, parserData, "only one group weight allowed");
	parserData->grpWgtAttributePresent = true;
	osoption->optimization->variables->sosVariableBranchingWeights->sos[parserData->numberOfSOS]->groupWeight = (yyvsp[(3) - (4)].dval);
;}
    break;

  case 507:

    {	if (parserData->grpWgtAttributePresent)
		osolerror (NULL, osoption, parserData, "only one group weight allowed");
	parserData->grpWgtAttributePresent = true;
	osoption->optimization->variables->sosVariableBranchingWeights->sos[parserData->numberOfSOS]->groupWeight = (yyvsp[(3) - (4)].ival);
;}
    break;

  case 508:

    {	if ((yyvsp[(3) - (4)].ival) < 0)
		osolerror (NULL, osoption, parserData, "number of <var> elements must be nonnegative");
//	osoption->optimization->variables->sosVariableBranchingWeights->sos[parserData->numberOfSOS] = new SOSWeights();
	osoption->optimization->variables->sosVariableBranchingWeights->sos[parserData->numberOfSOS]->numberOfVar = (yyvsp[(3) - (4)].ival);
	osoption->optimization->variables->sosVariableBranchingWeights->sos[parserData->numberOfSOS]->var = new BranchingWeight*[(yyvsp[(3) - (4)].ival)];
	for (int i = 0; i < (yyvsp[(3) - (4)].ival); i++)
		osoption->optimization->variables->sosVariableBranchingWeights->sos[parserData->numberOfSOS]->var[i] = new BranchingWeight();
;}
    break;

  case 513:

    {	if (!parserData->idxAttributePresent)
		osolerror (NULL, osoption, parserData, "variable index required");
	parserData->idxAttributePresent = false;
	parserData->valAttributePresent = false;
	parserData->numberOfSOSVar++;
;}
    break;

  case 514:

    {	if (parserData->numberOfSOSVar >= osoption->optimization->variables->sosVariableBranchingWeights->sos[parserData->numberOfSOS]->numberOfVar)
		osolerror(NULL, osoption, parserData, "too many variable branching weights");
;}
    break;

  case 519:

    {	if (parserData->idxAttributePresent)
		osolerror (NULL, osoption, parserData, "only one variable index allowed");
	parserData->idxAttributePresent = true;
	if ((yyvsp[(3) - (4)].ival) < 0)
		osolerror (NULL, osoption, parserData, "variable index must be nonnegative");
	if (osoption->optimization->numberOfVariables >= 0)
	{	if ((yyvsp[(3) - (4)].ival) >= osoption->optimization->numberOfVariables)
			osolerror (NULL, osoption, parserData, "variable index exceeds upper limit");
	};
	osoption->optimization->variables->sosVariableBranchingWeights->sos[parserData->numberOfSOS]->var[parserData->numberOfSOSVar]->idx = (yyvsp[(3) - (4)].ival);
;}
    break;

  case 520:

    {	if (parserData->valAttributePresent)
		osolerror (NULL, osoption, parserData, "only one variable weight allowed");
	parserData->valAttributePresent = true;
	if (strcmp((yyvsp[(2) - (2)].sval),"INF") == 0)
		osoption->optimization->variables->sosVariableBranchingWeights->sos[parserData->numberOfSOS]->var[parserData->numberOfSOSVar]->value = OSDBL_MAX;
	else if (strcmp((yyvsp[(2) - (2)].sval),"-INF") == 0)
		osoption->optimization->variables->sosVariableBranchingWeights->sos[parserData->numberOfSOS]->var[parserData->numberOfSOSVar]->value = -OSDBL_MAX;
	else
		osoption->optimization->variables->sosVariableBranchingWeights->sos[parserData->numberOfSOS]->var[parserData->numberOfSOSVar]->value = os_strtod((yyvsp[(2) - (2)].sval), NULL);
;}
    break;

  case 527:

    {	if (parserData->numberOfOtherVariableOptions >= osoption->optimization->variables->numberOfOtherVariableOptions)
		osolerror(NULL, osoption, parserData, "too many <other> variable options");
;}
    break;

  case 537:

    { 	if (parserData->otherOptionNumberPresent)
		osolerror (NULL, osoption, parserData, "only one numberOfVar attribute allowed");
	parserData->otherOptionNumberPresent = true;
	parserData->numberOfVar = 0;
	if ((yyvsp[(3) - (4)].ival) < 0)
		osolerror (NULL, osoption, parserData, "number of <other> variable options must be nonnegative");
	osoption->optimization->variables->other[parserData->numberOfOtherVariableOptions]->numberOfVar = (yyvsp[(3) - (4)].ival);
	osoption->optimization->variables->other[parserData->numberOfOtherVariableOptions]->var = new OtherVarOption*[(yyvsp[(3) - (4)].ival)];
	for (int i = 0; i < (yyvsp[(3) - (4)].ival); i++)
		osoption->optimization->variables->other[parserData->numberOfOtherVariableOptions]->var[i] = new OtherVarOption();	
;}
    break;

  case 538:

    {	if (parserData->otherOptionNamePresent)
		osolerror (NULL, osoption, parserData, "only one name attribute allowed");
	parserData->otherOptionNamePresent = true;
	osoption->optimization->variables->other[parserData->numberOfOtherVariableOptions]->name = (yyvsp[(2) - (2)].sval);
;}
    break;

  case 540:

    {	if (parserData->otherOptionValuePresent)
		osolerror (NULL, osoption, parserData, "only one value attribute allowed");
	parserData->otherOptionValuePresent = true;
	osoption->optimization->variables->other[parserData->numberOfOtherVariableOptions]->value = (yyvsp[(2) - (2)].sval);
;}
    break;

  case 542:

    {	if (parserData->otherOptionSolverPresent)
		osolerror (NULL, osoption, parserData, "only one solver attribute allowed");
	parserData->otherOptionSolverPresent = true;
	osoption->optimization->variables->other[parserData->numberOfOtherVariableOptions]->solver = (yyvsp[(2) - (2)].sval);
;}
    break;

  case 544:

    {	if (parserData->otherOptionCategoryPresent)
		osolerror (NULL, osoption, parserData, "only one category attribute allowed");
	parserData->otherOptionCategoryPresent = true;
	osoption->optimization->variables->other[parserData->numberOfOtherVariableOptions]->category = (yyvsp[(2) - (2)].sval);
;}
    break;

  case 546:

    {	if (parserData->otherOptionTypePresent)
		osolerror (NULL, osoption, parserData, "only one type attribute allowed");
	parserData->otherOptionTypePresent = true;
	osoption->optimization->variables->other[parserData->numberOfOtherVariableOptions]->type = (yyvsp[(2) - (2)].sval);
;}
    break;

  case 548:

    {	if (parserData->otherOptionDescriptionPresent)
		osolerror (NULL, osoption, parserData, "only one description attribute allowed");
	parserData->otherOptionDescriptionPresent = true;
	osoption->optimization->variables->other[parserData->numberOfOtherVariableOptions]->description = (yyvsp[(2) - (2)].sval);
;}
    break;

  case 550:

    { 	if (parserData->numberOfVar < osoption->optimization->variables->other[parserData->numberOfOtherVariableOptions]->numberOfVar)
		osolerror(NULL, osoption, parserData, "not enough <var> entries in <other> variable element");
	if (!parserData->otherOptionNumberPresent)
		osolerror (NULL, osoption, parserData, "number attribute required");
	if (!parserData->otherOptionNamePresent)
		osolerror (NULL, osoption, parserData, "name attribute required");
	parserData->otherOptionNumberPresent = false;
	parserData->otherOptionNamePresent = false;
	parserData->otherOptionValuePresent = false;
	parserData->otherOptionSolverPresent = false;
	parserData->otherOptionCategoryPresent = false;
	parserData->otherOptionTypePresent = false;
	parserData->otherOptionDescriptionPresent = false;
	parserData->numberOfOtherVariableOptions++;
;}
    break;

  case 553:

    {	if (!parserData->idxAttributePresent)
		osolerror(NULL, osoption, parserData, "required idx attribute was not found");
	parserData->idxAttributePresent = false;
	parserData->valAttributePresent = false;
	parserData->lbvalAttributePresent = false;
	parserData->ubvalAttributePresent = false;
	parserData->numberOfVar++;
;}
    break;

  case 554:

    {	if (parserData->numberOfVar >= osoption->optimization->variables->other[parserData->numberOfOtherVariableOptions]->numberOfVar)
		osolerror(NULL, osoption, parserData, "too many <var> entries in <other> variable element");
;}
    break;

  case 561:

    {	if (parserData->idxAttributePresent)
		osolerror (NULL, osoption, parserData, "only one variable index allowed");
	parserData->idxAttributePresent = true;
	if ((yyvsp[(3) - (4)].ival) < 0)
		osolerror (NULL, osoption, parserData, "variable index must be nonnegative");
	if (osoption->optimization->numberOfVariables >= 0)
	{	if ((yyvsp[(3) - (4)].ival) >= osoption->optimization->numberOfVariables)
			osolerror (NULL, osoption, parserData, "variable index exceeds upper limit");
	};
	osoption->optimization->variables->other[parserData->numberOfOtherVariableOptions]->var[parserData->numberOfVar]->idx = (yyvsp[(3) - (4)].ival);
;}
    break;

  case 562:

    {	if (parserData->valAttributePresent)
		osolerror (NULL, osoption, parserData, "only one variable value allowed");
	parserData->valAttributePresent = true;
	osoption->optimization->variables->other[parserData->numberOfOtherVariableOptions]->var[parserData->numberOfVar]->value = (yyvsp[(2) - (2)].sval);
;}
    break;

  case 564:

    {	if (parserData->lbvalAttributePresent)
		osolerror (NULL, osoption, parserData, "only one lower bound value allowed");
	parserData->lbvalAttributePresent = true;
	osoption->optimization->variables->other[parserData->numberOfOtherVariableOptions]->var[parserData->numberOfVar]->lbValue = (yyvsp[(2) - (2)].sval);
;}
    break;

  case 566:

    {	if (parserData->ubvalAttributePresent)
		osolerror (NULL, osoption, parserData, "only one upper bound value allowed");
	parserData->ubvalAttributePresent = true;
	osoption->optimization->variables->other[parserData->numberOfOtherVariableOptions]->var[parserData->numberOfVar]->ubValue = (yyvsp[(2) - (2)].sval);
;}
    break;

  case 572:

    {	osoption->optimization->objectives = new ObjectiveOption();
;}
    break;

  case 574:

    {	if ((yyvsp[(3) - (4)].ival) < 0)
		osolerror (NULL, osoption, parserData, "number of <other> objective options cannot be negative");
	osoption->optimization->objectives->numberOfOtherObjectiveOptions = (yyvsp[(3) - (4)].ival);
	osoption->optimization->objectives->other = new OtherObjectiveOption*[(yyvsp[(3) - (4)].ival)];
	for (int i= 0; i < (yyvsp[(3) - (4)].ival); i++)
		osoption->optimization->objectives->other[i] = new OtherObjectiveOption();
;}
    break;

  case 579:

    {	if ((yyvsp[(3) - (4)].ival) < 0)
		osolerror (NULL, osoption, parserData, "number of <obj> elements must be nonnegative");
	osoption->optimization->objectives->initialObjectiveValues = new InitObjectiveValues();
	osoption->optimization->objectives->initialObjectiveValues->numberOfObj = (yyvsp[(3) - (4)].ival);
	osoption->optimization->objectives->initialObjectiveValues->obj = new InitObjValue*[(yyvsp[(3) - (4)].ival)];
	for (int i = 0; i < (yyvsp[(3) - (4)].ival); i++)
		osoption->optimization->objectives->initialObjectiveValues->obj[i] = new InitObjValue();
;}
    break;

  case 582:

    {	if (!parserData->idxAttributePresent)
		osolerror (NULL, osoption, parserData, "objective index required");
	parserData->idxAttributePresent = false;
	parserData->valAttributePresent = false;
	parserData->numberOfObjValues++;
;}
    break;

  case 583:

    {	if (parserData->numberOfObjValues >= osoption->optimization->objectives->initialObjectiveValues->numberOfObj)
		osolerror(NULL, osoption, parserData, "too many initial objective values");
;}
    break;

  case 588:

    {	if (parserData->idxAttributePresent)
		osolerror (NULL, osoption, parserData, "only one objective index allowed");
	parserData->idxAttributePresent = true;
	if ((yyvsp[(3) - (4)].ival) >= 0)
		osolerror (NULL, osoption, parserData, "objective index must be negative");
	if (osoption->optimization->numberOfObjectives >= 0)
	{	if (-(yyvsp[(3) - (4)].ival) > osoption->optimization->numberOfObjectives)
			osolerror (NULL, osoption, parserData, "objective index out of range");
	};
	osoption->optimization->objectives->initialObjectiveValues->obj[parserData->numberOfObjValues]->idx = (yyvsp[(3) - (4)].ival);
;}
    break;

  case 589:

    {	if (parserData->valAttributePresent)
		osolerror (NULL, osoption, parserData, "only one objective value allowed");
	parserData->valAttributePresent = true;
	if (strcmp((yyvsp[(2) - (2)].sval),"INF") == 0)
		osoption->optimization->objectives->initialObjectiveValues->obj[parserData->numberOfObjValues]->value = OSDBL_MAX;
	else if (strcmp((yyvsp[(2) - (2)].sval),"-INF") == 0)
		osoption->optimization->objectives->initialObjectiveValues->obj[parserData->numberOfObjValues]->value = -OSDBL_MAX;
	else
		osoption->optimization->objectives->initialObjectiveValues->obj[parserData->numberOfObjValues]->value = os_strtod((yyvsp[(2) - (2)].sval), NULL);
;}
    break;

  case 595:

    {	if ((yyvsp[(3) - (4)].ival) < 0)
		osolerror (NULL, osoption, parserData, "number of <obj> elements must be nonnegative");
	osoption->optimization->objectives->initialObjectiveBounds = new InitObjectiveBounds();
	osoption->optimization->objectives->initialObjectiveBounds->numberOfObj = (yyvsp[(3) - (4)].ival);
	osoption->optimization->objectives->initialObjectiveBounds->obj = new InitObjBound*[(yyvsp[(3) - (4)].ival)];
	for (int i = 0; i < (yyvsp[(3) - (4)].ival); i++)
		osoption->optimization->objectives->initialObjectiveBounds->obj[i] = new InitObjBound ();
;}
    break;

  case 598:

    {	if (!parserData->idxAttributePresent)
		osolerror (NULL, osoption, parserData, "objective index required");
	parserData->idxAttributePresent = false;
	parserData->lbvalAttributePresent = false;
	parserData->ubvalAttributePresent = false;
	parserData->numberOfObjBounds++;
;}
    break;

  case 599:

    {	if (parserData->numberOfObjBounds >= osoption->optimization->objectives->initialObjectiveBounds->numberOfObj)
		osolerror(NULL, osoption, parserData, "too many initial objective bounds");
;}
    break;

  case 605:

    {	if (parserData->idxAttributePresent)
		osolerror (NULL, osoption, parserData, "only one objective index allowed");
	parserData->idxAttributePresent = true;
	if ((yyvsp[(3) - (4)].ival) >= 0)
		osolerror (NULL, osoption, parserData, "objective index must be negative");
	if (osoption->optimization->numberOfObjectives >= 0)
	{	if (-(yyvsp[(3) - (4)].ival) > osoption->optimization->numberOfObjectives)
			osolerror (NULL, osoption, parserData, "objective index out of range");
	};
	osoption->optimization->objectives->initialObjectiveBounds->obj[parserData->numberOfObjBounds]->idx = (yyvsp[(3) - (4)].ival);
;}
    break;

  case 606:

    {	if (parserData->lbvalAttributePresent)
		osolerror (NULL, osoption, parserData, "only one objective lower bound allowed");
	parserData->lbvalAttributePresent = true;
	if (strcmp((yyvsp[(2) - (2)].sval),"INF") == 0)
		osoption->optimization->objectives->initialObjectiveBounds->obj[parserData->numberOfObjBounds]->lbValue = OSDBL_MAX;
	else if (strcmp((yyvsp[(2) - (2)].sval),"-INF") == 0)
		osoption->optimization->objectives->initialObjectiveBounds->obj[parserData->numberOfObjBounds]->lbValue = -OSDBL_MAX;
	else
		osoption->optimization->objectives->initialObjectiveBounds->obj[parserData->numberOfObjBounds]->lbValue = os_strtod((yyvsp[(2) - (2)].sval), NULL);
;}
    break;

  case 608:

    {	if (parserData->ubvalAttributePresent)
		osolerror (NULL, osoption, parserData, "only one objective upper bound allowed");
	parserData->ubvalAttributePresent = true;
	if (strcmp((yyvsp[(2) - (2)].sval),"INF") == 0)
		osoption->optimization->objectives->initialObjectiveBounds->obj[parserData->numberOfObjBounds]->ubValue = OSDBL_MAX;
	else if (strcmp((yyvsp[(2) - (2)].sval),"-INF") == 0)
		osoption->optimization->objectives->initialObjectiveBounds->obj[parserData->numberOfObjBounds]->ubValue = -OSDBL_MAX;
	else
		osoption->optimization->objectives->initialObjectiveBounds->obj[parserData->numberOfObjBounds]->ubValue = os_strtod((yyvsp[(2) - (2)].sval), NULL);
;}
    break;

  case 615:

    {	if (parserData->numberOfOtherObjectiveOptions >= osoption->optimization->objectives->numberOfOtherObjectiveOptions)
		osolerror(NULL, osoption, parserData, "too many <other> objective options");
;}
    break;

  case 625:

    { 	if (parserData->otherOptionNumberPresent)
		osolerror (NULL, osoption, parserData, "only one numberOfObj attribute allowed");
	parserData->otherOptionNumberPresent = true;
	parserData->numberOfObj = 0;
	if ((yyvsp[(3) - (4)].ival) < 0)
		osolerror (NULL, osoption, parserData, "number of <other> objective options must be nonnegative");
	osoption->optimization->objectives->other[parserData->numberOfOtherObjectiveOptions]->numberOfObj = (yyvsp[(3) - (4)].ival);
	osoption->optimization->objectives->other[parserData->numberOfOtherObjectiveOptions]->obj = new OtherObjOption*[(yyvsp[(3) - (4)].ival)];
	for (int i = 0; i < (yyvsp[(3) - (4)].ival); i++)
		osoption->optimization->objectives->other[parserData->numberOfOtherObjectiveOptions]->obj[i] = new OtherObjOption();
;}
    break;

  case 626:

    {	if (parserData->otherOptionNamePresent)
		osolerror (NULL, osoption, parserData, "only one name attribute allowed");
	parserData->otherOptionNamePresent = true;
	osoption->optimization->objectives->other[parserData->numberOfOtherObjectiveOptions]->name = (yyvsp[(2) - (2)].sval);
;}
    break;

  case 628:

    {	if (parserData->otherOptionValuePresent)
		osolerror (NULL, osoption, parserData, "only one value attribute allowed");
	parserData->otherOptionValuePresent = true;
	osoption->optimization->objectives->other[parserData->numberOfOtherObjectiveOptions]->value = (yyvsp[(2) - (2)].sval);
;}
    break;

  case 630:

    {	if (parserData->otherOptionSolverPresent)
		osolerror (NULL, osoption, parserData, "only one solver attribute allowed");
	parserData->otherOptionSolverPresent = true;
	osoption->optimization->objectives->other[parserData->numberOfOtherObjectiveOptions]->solver = (yyvsp[(2) - (2)].sval);
;}
    break;

  case 632:

    {	if (parserData->otherOptionCategoryPresent)
		osolerror (NULL, osoption, parserData, "only one category attribute allowed");
	parserData->otherOptionCategoryPresent = true;
	osoption->optimization->objectives->other[parserData->numberOfOtherObjectiveOptions]->category = (yyvsp[(2) - (2)].sval);
;}
    break;

  case 634:

    {	if (parserData->otherOptionTypePresent)
		osolerror (NULL, osoption, parserData, "only one type attribute allowed");
	parserData->otherOptionTypePresent = true;
	osoption->optimization->objectives->other[parserData->numberOfOtherObjectiveOptions]->type = (yyvsp[(2) - (2)].sval);
;}
    break;

  case 636:

    {	if (parserData->otherOptionDescriptionPresent)
		osolerror (NULL, osoption, parserData, "only one description attribute allowed");
	parserData->otherOptionDescriptionPresent = true;
	osoption->optimization->objectives->other[parserData->numberOfOtherObjectiveOptions]->description = (yyvsp[(2) - (2)].sval);
;}
    break;

  case 638:

    { 	if (parserData->numberOfObj < osoption->optimization->objectives->other[parserData->numberOfOtherObjectiveOptions]->numberOfObj)
		osolerror(NULL, osoption, parserData, "not enough <obj> entries in <other> variable element");
	if (!parserData->otherOptionNumberPresent)
		osolerror (NULL, osoption, parserData, "number attribute required");
	if (!parserData->otherOptionNamePresent)
		osolerror (NULL, osoption, parserData, "name attribute required");
	parserData->otherOptionNumberPresent = false;
	parserData->otherOptionNamePresent = false;
	parserData->otherOptionValuePresent = false;
	parserData->otherOptionSolverPresent = false;
	parserData->otherOptionCategoryPresent = false;
	parserData->otherOptionTypePresent = false;
	parserData->otherOptionDescriptionPresent = false;
	parserData->numberOfOtherObjectiveOptions++;
;}
    break;

  case 641:

    {	if (!parserData->idxAttributePresent)
		osolerror(NULL, osoption, parserData, "required idx attribute was not found");
	parserData->idxAttributePresent = false;
	parserData->valAttributePresent = false;
	parserData->lbvalAttributePresent = false;
	parserData->ubvalAttributePresent = false;
	parserData->numberOfObj++;
;}
    break;

  case 642:

    {	if (parserData->numberOfObj >= osoption->optimization->objectives->other[parserData->numberOfOtherObjectiveOptions]->numberOfObj)
		osolerror(NULL, osoption, parserData, "too many <obj> entries in <other> objective element");
;}
    break;

  case 649:

    {	if (parserData->idxAttributePresent)
		osolerror (NULL, osoption, parserData, "only one objective index allowed");
	parserData->idxAttributePresent = true;
	if ((yyvsp[(3) - (4)].ival) >= 0)
		osolerror (NULL, osoption, parserData, "objective index must be negative");
	if (parserData->numberOfObjectivesPresent)
	{	if (-(yyvsp[(3) - (4)].ival) > parserData->numberOfObjectives)
			osolerror (NULL, osoption, parserData, "objective index exceeds upper limit");
	};
	osoption->optimization->objectives->other[parserData->numberOfOtherObjectiveOptions]->obj[parserData->numberOfObj]->idx = (yyvsp[(3) - (4)].ival);
;}
    break;

  case 650:

    {	if (parserData->valAttributePresent)
		osolerror (NULL, osoption, parserData, "only one variable value allowed");
	parserData->valAttributePresent = true;
	osoption->optimization->objectives->other[parserData->numberOfOtherObjectiveOptions]->obj[parserData->numberOfObj]->value = (yyvsp[(2) - (2)].sval);
;}
    break;

  case 652:

    {	if (parserData->lbvalAttributePresent)
		osolerror (NULL, osoption, parserData, "only one lower bound value allowed");
	parserData->lbvalAttributePresent = true;
	osoption->optimization->objectives->other[parserData->numberOfOtherObjectiveOptions]->obj[parserData->numberOfObj]->lbValue = (yyvsp[(2) - (2)].sval);
;}
    break;

  case 654:

    {	if (parserData->ubvalAttributePresent)
		osolerror (NULL, osoption, parserData, "only one upper bound value allowed");
	parserData->ubvalAttributePresent = true;
	osoption->optimization->objectives->other[parserData->numberOfOtherObjectiveOptions]->obj[parserData->numberOfObj]->ubValue = (yyvsp[(2) - (2)].sval);
;}
    break;

  case 660:

    {	osoption->optimization->constraints = new ConstraintOption();
;}
    break;

  case 662:

    {	if ((yyvsp[(3) - (4)].ival) < 0)
		osolerror (NULL, osoption, parserData, "number of <other> constraint options cannot be negative");
        osoption->optimization->constraints->numberOfOtherConstraintOptions = (yyvsp[(3) - (4)].ival);
	osoption->optimization->constraints->other = new OtherConstraintOption*[(yyvsp[(3) - (4)].ival)];
	for (int i= 0; i < (yyvsp[(3) - (4)].ival); i++)
		osoption->optimization->constraints->other[i] = new OtherConstraintOption();
;}
    break;

  case 667:

    {	if ((yyvsp[(3) - (4)].ival) < 0)
		osolerror (NULL, osoption, parserData, "number of <con> elements must be nonnegative");
	osoption->optimization->constraints->initialConstraintValues = new InitConstraintValues();
	osoption->optimization->constraints->initialConstraintValues->numberOfCon = (yyvsp[(3) - (4)].ival);
	osoption->optimization->constraints->initialConstraintValues->con = new InitConValue*[(yyvsp[(3) - (4)].ival)];
	for (int i = 0; i < (yyvsp[(3) - (4)].ival); i++)
		osoption->optimization->constraints->initialConstraintValues->con[i] = new InitConValue();
;}
    break;

  case 670:

    {	if (!parserData->idxAttributePresent)
		osolerror (NULL, osoption, parserData, "variable index required");
	parserData->idxAttributePresent = false;
	parserData->valAttributePresent = false;
	parserData->numberOfCon++;
;}
    break;

  case 671:

    {	if (parserData->numberOfCon >= osoption->optimization->constraints->initialConstraintValues->numberOfCon)
		osolerror(NULL, osoption, parserData, "too many initial constraint values");
;}
    break;

  case 676:

    {	if (parserData->idxAttributePresent)
		osolerror (NULL, osoption, parserData, "only one constraint index allowed");
	parserData->idxAttributePresent = true;
	if ((yyvsp[(3) - (4)].ival) < 0)
		osolerror (NULL, osoption, parserData, "constraint index must be nonnegative");
	if (osoption->optimization->numberOfConstraints >= 0)
	{	if ((yyvsp[(3) - (4)].ival) > osoption->optimization->numberOfConstraints)
			osolerror (NULL, osoption, parserData, "constraint index out of range");
	};
	osoption->optimization->constraints->initialConstraintValues->con[parserData->numberOfCon]->idx = (yyvsp[(3) - (4)].ival);
;}
    break;

  case 677:

    {	if (parserData->valAttributePresent)
		osolerror (NULL, osoption, parserData, "only one constraint value allowed");
	parserData->valAttributePresent = true;
	if (strcmp((yyvsp[(2) - (2)].sval),"INF") == 0)
		osoption->optimization->constraints->initialConstraintValues->con[parserData->numberOfCon]->value = OSDBL_MAX;
	else if (strcmp((yyvsp[(2) - (2)].sval),"-INF") == 0)
		osoption->optimization->constraints->initialConstraintValues->con[parserData->numberOfCon]->value = -OSDBL_MAX;
	else
		osoption->optimization->constraints->initialConstraintValues->con[parserData->numberOfCon]->value = os_strtod((yyvsp[(2) - (2)].sval), NULL);
;}
    break;

  case 683:

    {	if ((yyvsp[(3) - (4)].ival) < 0)
		osolerror (NULL, osoption, parserData, "number of <con> elements must be nonnegative");
	osoption->optimization->constraints->initialDualValues = new InitDualVariableValues();
	osoption->optimization->constraints->initialDualValues->numberOfCon = (yyvsp[(3) - (4)].ival);
	osoption->optimization->constraints->initialDualValues->con = new InitDualVarValue*[(yyvsp[(3) - (4)].ival)];
	for (int i = 0; i < (yyvsp[(3) - (4)].ival); i++)
		osoption->optimization->constraints->initialDualValues->con[i] = new InitDualVarValue ();
;}
    break;

  case 686:

    {	if (!parserData->idxAttributePresent)
		osolerror (NULL, osoption, parserData, "constraint index required");
	parserData->idxAttributePresent = false;
	parserData->lbvalAttributePresent = false;
	parserData->ubvalAttributePresent = false;
	parserData->numberOfDuals++;
;}
    break;

  case 687:

    {	if (parserData->numberOfDuals >= osoption->optimization->constraints->initialDualValues->numberOfCon)
		osolerror(NULL, osoption, parserData, "too many initial dual variable bounds");
;}
    break;

  case 693:

    {	if (parserData->idxAttributePresent)
		osolerror (NULL, osoption, parserData, "only one constraint index allowed");
	parserData->idxAttributePresent = true;
	if ((yyvsp[(3) - (4)].ival) < 0)
		osolerror (NULL, osoption, parserData, "constraint index must be nonnegative");
	if (parserData->numberOfConstraintsPresent)
	{	if ((yyvsp[(3) - (4)].ival) > parserData->numberOfConstraints)
			osolerror (NULL, osoption, parserData, "constraint index out of range");
	};
	osoption->optimization->constraints->initialDualValues->con[parserData->numberOfDuals]->idx = (yyvsp[(3) - (4)].ival);
;}
    break;

  case 694:

    {	if (parserData->lbvalAttributePresent)
		osolerror (NULL, osoption, parserData, "only one dual variable lower bound allowed");
	parserData->lbvalAttributePresent = true;
	if (strcmp((yyvsp[(2) - (2)].sval),"INF") == 0)
		osoption->optimization->constraints->initialDualValues->con[parserData->numberOfDuals]->lbDualValue = OSDBL_MAX;
	else if (strcmp((yyvsp[(2) - (2)].sval),"-INF") == 0)
		osoption->optimization->constraints->initialDualValues->con[parserData->numberOfDuals]->lbDualValue = -OSDBL_MAX;
	else
		osoption->optimization->constraints->initialDualValues->con[parserData->numberOfDuals]->lbDualValue = os_strtod((yyvsp[(2) - (2)].sval), NULL);
;}
    break;

  case 696:

    {	if (parserData->ubvalAttributePresent)
		osolerror (NULL, osoption, parserData, "only one dual variable upper bound allowed");
	parserData->ubvalAttributePresent = true;
	if (strcmp((yyvsp[(2) - (2)].sval),"INF") == 0)
		osoption->optimization->constraints->initialDualValues->con[parserData->numberOfDuals]->ubDualValue = OSDBL_MAX;
	else if (strcmp((yyvsp[(2) - (2)].sval),"-INF") == 0)
		osoption->optimization->constraints->initialDualValues->con[parserData->numberOfDuals]->ubDualValue = -OSDBL_MAX;
	else
		osoption->optimization->constraints->initialDualValues->con[parserData->numberOfDuals]->ubDualValue = os_strtod((yyvsp[(2) - (2)].sval), NULL);
;}
    break;

  case 703:

    {	if (parserData->numberOfOtherConstraintOptions >= osoption->optimization->constraints->numberOfOtherConstraintOptions)
		osolerror(NULL, osoption, parserData, "too many <other> constraint options");
;}
    break;

  case 713:

    { 	if (parserData->otherOptionNumberPresent)
		osolerror (NULL, osoption, parserData, "only one numberOfCon attribute allowed");
	parserData->otherOptionNumberPresent = true;
	parserData->numberOfCon = 0;
	if ((yyvsp[(3) - (4)].ival) < 0)
		osolerror (NULL, osoption, parserData, "number of <other> constraint options must be nonnegative");
	osoption->optimization->constraints->other[parserData->numberOfOtherConstraintOptions]->numberOfCon = (yyvsp[(3) - (4)].ival);
	osoption->optimization->constraints->other[parserData->numberOfOtherConstraintOptions]->con = new OtherConOption*[(yyvsp[(3) - (4)].ival)];
	for (int i = 0; i < (yyvsp[(3) - (4)].ival); i++)
		osoption->optimization->constraints->other[parserData->numberOfOtherConstraintOptions]->con[i] = new OtherConOption();
;}
    break;

  case 714:

    {	if (parserData->otherOptionNamePresent)
		osolerror (NULL, osoption, parserData, "only one name attribute allowed");
	parserData->otherOptionNamePresent = true;
	osoption->optimization->constraints->other[parserData->numberOfOtherConstraintOptions]->name = (yyvsp[(2) - (2)].sval);
;}
    break;

  case 716:

    {	if (parserData->otherOptionValuePresent)
		osolerror (NULL, osoption, parserData, "only one value attribute allowed");
	parserData->otherOptionValuePresent = true;
	osoption->optimization->constraints->other[parserData->numberOfOtherConstraintOptions]->value = (yyvsp[(2) - (2)].sval);
;}
    break;

  case 718:

    {	if (parserData->otherOptionSolverPresent)
		osolerror (NULL, osoption, parserData, "only one solver attribute allowed");
	parserData->otherOptionSolverPresent = true;
	osoption->optimization->constraints->other[parserData->numberOfOtherConstraintOptions]->solver = (yyvsp[(2) - (2)].sval);
;}
    break;

  case 720:

    {	if (parserData->otherOptionCategoryPresent)
		osolerror (NULL, osoption, parserData, "only one category attribute allowed");
	parserData->otherOptionCategoryPresent = true;
	osoption->optimization->constraints->other[parserData->numberOfOtherConstraintOptions]->category = (yyvsp[(2) - (2)].sval);
;}
    break;

  case 722:

    {	if (parserData->otherOptionTypePresent)
		osolerror (NULL, osoption, parserData, "only one type attribute allowed");
	parserData->otherOptionTypePresent = true;
	osoption->optimization->constraints->other[parserData->numberOfOtherConstraintOptions]->type = (yyvsp[(2) - (2)].sval);
;}
    break;

  case 724:

    {	if (parserData->otherOptionDescriptionPresent)
		osolerror (NULL, osoption, parserData, "only one description attribute allowed");
	parserData->otherOptionDescriptionPresent = true;
	osoption->optimization->constraints->other[parserData->numberOfOtherConstraintOptions]->description = (yyvsp[(2) - (2)].sval);
;}
    break;

  case 726:

    { 	if (parserData->numberOfCon < osoption->optimization->constraints->other[parserData->numberOfOtherConstraintOptions]->numberOfCon)
		osolerror(NULL, osoption, parserData, "not enough <con> entries in <other> constraint element");
	if (!parserData->otherOptionNumberPresent)
		osolerror (NULL, osoption, parserData, "number attribute required");
	if (!parserData->otherOptionNamePresent)
		osolerror (NULL, osoption, parserData, "name attribute required");
	parserData->otherOptionNumberPresent = false;
	parserData->otherOptionNamePresent = false;
	parserData->otherOptionValuePresent = false;
	parserData->otherOptionSolverPresent = false;
	parserData->otherOptionCategoryPresent = false;
	parserData->otherOptionTypePresent = false;
	parserData->otherOptionDescriptionPresent = false;
	parserData->numberOfOtherConstraintOptions++;
;}
    break;

  case 729:

    {	if (!parserData->idxAttributePresent)
		osolerror(NULL, osoption, parserData, "required idx attribute was not found");
	parserData->idxAttributePresent = false;
	parserData->valAttributePresent = false;
	parserData->lbvalAttributePresent = false;
	parserData->ubvalAttributePresent = false;
	parserData->numberOfCon++;
;}
    break;

  case 730:

    {	if (parserData->numberOfCon >= osoption->optimization->constraints->other[parserData->numberOfOtherConstraintOptions]->numberOfCon)
		osolerror(NULL, osoption, parserData, "too many <con> entries in <other> constraint element");
;}
    break;

  case 737:

    {	if (parserData->idxAttributePresent)
		osolerror (NULL, osoption, parserData, "only one constraint index allowed");
	parserData->idxAttributePresent = true;
	if ((yyvsp[(3) - (4)].ival) < 0)
		osolerror (NULL, osoption, parserData, "constraint index must be nonnegative");
	if (parserData->numberOfConstraintsPresent)
	{	if ((yyvsp[(3) - (4)].ival) > parserData->numberOfConstraints)
			osolerror (NULL, osoption, parserData, "constraint index exceeds upper limit");
	};
	osoption->optimization->constraints->other[parserData->numberOfOtherConstraintOptions]->con[parserData->numberOfCon]->idx = (yyvsp[(3) - (4)].ival);
;}
    break;

  case 738:

    {	if (parserData->valAttributePresent)
		osolerror (NULL, osoption, parserData, "only one constraint value allowed");
	parserData->valAttributePresent = true;
	osoption->optimization->constraints->other[parserData->numberOfOtherConstraintOptions]->con[parserData->numberOfCon]->value = (yyvsp[(2) - (2)].sval);
;}
    break;

  case 740:

    {	if (parserData->lbvalAttributePresent)
		osolerror (NULL, osoption, parserData, "only one lower bound value allowed");
	parserData->lbvalAttributePresent = true;
	osoption->optimization->constraints->other[parserData->numberOfOtherConstraintOptions]->con[parserData->numberOfCon]->lbValue = (yyvsp[(2) - (2)].sval);
;}
    break;

  case 742:

    {	if (parserData->ubvalAttributePresent)
		osolerror (NULL, osoption, parserData, "only one upper bound value allowed");
	parserData->ubvalAttributePresent = true;
	osoption->optimization->constraints->other[parserData->numberOfOtherConstraintOptions]->con[parserData->numberOfCon]->ubValue = (yyvsp[(2) - (2)].sval);
;}
    break;

  case 747:

    {	if (parserData->numberOfSolverOptions != osoption->optimization->solverOptions->numberOfSolverOptions)
		osolerror (NULL, osoption, parserData, "wrong number of solver options in <optimization> element");
;}
    break;

  case 748:

    {	if (parserData->solverOptionsPresent)
	{	osolerror( NULL, osoption, parserData, "only one <solverOptions> element allowed");
	}
	else
	{	parserData->solverOptionsPresent = true;
		osoption->optimization->solverOptions = new SolverOptions();
	}
;}
    break;

  case 749:

    {	if ((yyvsp[(3) - (4)].ival) < 0)
		osolerror (NULL, osoption, parserData, "number of solver options cannot be negative");
	osoption->optimization->solverOptions->numberOfSolverOptions = (yyvsp[(3) - (4)].ival);
	osoption->optimization->solverOptions->solverOption = new SolverOption*[(yyvsp[(3) - (4)].ival)];
	for (int i=0; i < (yyvsp[(3) - (4)].ival); i++) osoption->optimization->solverOptions->solverOption[i] = new SolverOption();
;}
    break;

  case 752:

    {	if (parserData->numberOfSolverOptions >= osoption->optimization->solverOptions->numberOfSolverOptions)
	{	osolerror (NULL, osoption, parserData, "too many solver options in <optimization> element");
	};
;}
    break;

  case 753:

    {	if (!parserData->solverOptionNamePresent)
		osolerror (NULL, osoption, parserData, "name attribute must be present");
	/* reset defaults for the next option */
	parserData->solverOptionNamePresent = false;
	parserData->solverOptionValuePresent = false;
	parserData->solverOptionSolverPresent = false;
	parserData->solverOptionCategoryPresent = false;
	parserData->solverOptionTypePresent = false;
	parserData->solverOptionDescriptionPresent = false;
	parserData->numberOfSolverOptions++;
;}
    break;

  case 762:

    {	if (parserData->solverOptionNamePresent)
	{	osolerror( NULL, osoption, parserData, "only one name attribute allowed");
	}
	else
	{	parserData->solverOptionNamePresent = true;
		osoption->optimization->solverOptions->solverOption[parserData->numberOfSolverOptions]->name = (yyvsp[(2) - (2)].sval);
	}
;}
    break;

  case 764:

    {	if (parserData->solverOptionValuePresent)
	{	osolerror( NULL, osoption, parserData, "only one value attribute allowed");
	}
	else
	{	parserData->solverOptionValuePresent = true;
		osoption->optimization->solverOptions->solverOption[parserData->numberOfSolverOptions]->value = (yyvsp[(2) - (2)].sval);
	}
;}
    break;

  case 766:

    {	if (parserData->solverOptionSolverPresent)
	{	osolerror( NULL, osoption, parserData, "only one solver attribute allowed");
	}
	else
	{	parserData->solverOptionSolverPresent = true;
		osoption->optimization->solverOptions->solverOption[parserData->numberOfSolverOptions]->solver = (yyvsp[(2) - (2)].sval);
	}
;}
    break;

  case 768:

    {	if (parserData->solverOptionCategoryPresent)
	{	osolerror( NULL, osoption, parserData, "only one category attribute allowed");
	}
	else
	{	parserData->solverOptionCategoryPresent = true;
		osoption->optimization->solverOptions->solverOption[parserData->numberOfSolverOptions]->category = (yyvsp[(2) - (2)].sval);
	}
;}
    break;

  case 770:

    {	if (parserData->solverOptionTypePresent)
	{	osolerror( NULL, osoption, parserData, "only one type attribute allowed");
	}
	else
	{	parserData->solverOptionTypePresent = true;
		osoption->optimization->solverOptions->solverOption[parserData->numberOfSolverOptions]->type = (yyvsp[(2) - (2)].sval);
	}
;}
    break;

  case 772:

    {	if (parserData->solverOptionDescriptionPresent)
	{	osolerror( NULL, osoption, parserData, "only one description attribute allowed");
	}
	else
	{	parserData->solverOptionDescriptionPresent = true;
		osoption->optimization->solverOptions->solverOption[parserData->numberOfSolverOptions]->description = (yyvsp[(2) - (2)].sval);
	}
;}
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
      yyerror (&yylloc, osoption, parserData, YY_("syntax error"));
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
	    yyerror (&yylloc, osoption, parserData, yymsg);
	  }
	else
	  {
	    yyerror (&yylloc, osoption, parserData, YY_("syntax error"));
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
		      yytoken, &yylval, &yylloc, osoption, parserData);
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
		  yystos[yystate], yyvsp, yylsp, osoption, parserData);
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
  yyerror (&yylloc, osoption, parserData, YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval, &yylloc, osoption, parserData);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp, yylsp, osoption, parserData);
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





void osolerror(YYLTYPE* mytype, OSOption *osoption, OSoLParserData* parserData, const char* errormsg )
{
	std::ostringstream outStr;
	std::string error = errormsg;
	error = "Input is either not valid or well formed: "  + error;
	outStr << error << std::endl;
	outStr << "See line number: " << osolget_lineno( scanner) << std::endl;
	outStr << "The offending text is: " << osolget_text ( scanner ) << std::endl;
	error = outStr.str();
	//printf("THIS DID NOT GET DESTROYED:   %s\n", parserData->errorText);
	//if( (parserData->errorText != NULL) &&  (strlen(parserData->errorText) > 0) ) free(  parserData->errorText);
	//osollex_destroy( scanner);
	throw ErrorClass( error);
} //end osolerror

void  yygetOSOption(const char *parsestring, OSOption *osoption, OSoLParserData *parserData) throw(ErrorClass){
	try{
		osol_scan_string( parsestring, scanner);
		osolset_lineno (1 , scanner );
		//
		// call the Bison parser
		//
		if(  osolparse( osoption,  parserData) != 0) {
			//osollex_destroy(scanner);
		  	throw ErrorClass(  "Error parsing the OSoL file");
		 }
	}
	catch(const ErrorClass& eclass){
		throw ErrorClass(  eclass.errormsg);
	}
} //end yygetOSOption


