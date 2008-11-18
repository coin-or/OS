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
     GREATERTHAN = 263,
     ENDOFELEMENT = 264,
     OSOLSTART = 265,
     OSOLATTRIBUTETEXT = 266,
     OSOLEND = 267,
     LOCATIONTYPEATT = 268,
     TRANSPORTTYPEATT = 269,
     NUMBEROFOTHEROPTIONSATT = 270,
     NUMBEROFJOBIDSATT = 271,
     NUMBEROFPATHSATT = 272,
     NUMBEROFPATHPAIRSATT = 273,
     FROMATT = 274,
     TOATT = 275,
     MAKECOPYATT = 276,
     SOLVERATT = 277,
     CATEGORYATT = 278,
     TYPEATT = 279,
     NUMBEROFPROCESSESATT = 280,
     NUMBEROFSOLVEROPTIONSATT = 281,
     NUMBEROFVARIABLESATT = 282,
     NUMBEROFOBJECTIVESATT = 283,
     NUMBEROFCONSTRAINTSATT = 284,
     NUMBEROFOTHERVARIABLEOPTIONSATT = 285,
     NUMBEROFOTHEROBJECTIVEOPTIONSATT = 286,
     NUMBEROFOTHERCONSTRAINTOPTIONSATT = 287,
     NUMBEROFVARATT = 288,
     NUMBEROFOBJATT = 289,
     NUMBEROFCONATT = 290,
     NAMEATT = 291,
     IDXATT = 292,
     VALUEATT = 293,
     UNITATT = 294,
     DESCRIPTIONATT = 295,
     LBVALUEATT = 296,
     UBVALUEATT = 297,
     GENERALSTART = 298,
     GENERALEND = 299,
     SYSTEMSTART = 300,
     SYSTEMEND = 301,
     SERVICESTART = 302,
     SERVICEEND = 303,
     JOBSTART = 304,
     JOBEND = 305,
     OPTIMIZATIONSTART = 306,
     OPTIMIZATIONEND = 307,
     SERVICEURISTART = 308,
     SERVICEURIEND = 309,
     SERVICENAMESTART = 310,
     SERVICENAMEEND = 311,
     INSTANCENAMESTART = 312,
     INSTANCENAMEEND = 313,
     INSTANCELOCATIONSTART = 314,
     INSTANCELOCATIONEND = 315,
     JOBIDSTART = 316,
     JOBIDEND = 317,
     SOLVERTOINVOKESTART = 318,
     SOLVERTOINVOKEEND = 319,
     LICENSESTART = 320,
     LICENSEEND = 321,
     USERNAMESTART = 322,
     USERNAMEEND = 323,
     PASSWORDSTART = 324,
     PASSWORDEND = 325,
     CONTACTSTART = 326,
     CONTACTEND = 327,
     OTHEROPTIONSSTART = 328,
     OTHEROPTIONSEND = 329,
     OTHERSTART = 330,
     OTHEREND = 331,
     MINDISKSPACESTART = 332,
     MINDISKSPACEEND = 333,
     MINMEMORYSIZESTART = 334,
     MINMEMORYSIZEEND = 335,
     MINCPUSPEEDSTART = 336,
     MINCPUSPEEDEND = 337,
     MINCPUNUMBERSTART = 338,
     MINCPUNUMBEREND = 339,
     SERVICETYPESTART = 340,
     SERVICETYPEEND = 341,
     MAXTIMESTART = 342,
     MAXTIMEEND = 343,
     SCHEDULEDSTARTTIMESTART = 344,
     SCHEDULEDSTARTTIMEEND = 345,
     DEPENDENCIESSTART = 346,
     DEPENDENCIESEND = 347,
     REQUIREDDIRECTORIESSTART = 348,
     REQUIREDDIRECTORIESEND = 349,
     REQUIREDFILESSTART = 350,
     REQUIREDFILESEND = 351,
     PATHSTART = 352,
     PATHEND = 353,
     PATHPAIRSTART = 354,
     PATHPAIREND = 355,
     DIRECTORIESTOMAKESTART = 356,
     DIRECTORIESTOMAKEEND = 357,
     FILESTOCREATESTART = 358,
     FILESTOCREATEEND = 359,
     DIRECTORIESTODELETESTART = 360,
     DIRECTORIESTODELETEEND = 361,
     FILESTODELETESTART = 362,
     FILESTODELETEEND = 363,
     INPUTDIRECTORIESTOMOVESTART = 364,
     INPUTDIRECTORIESTOMOVEEND = 365,
     INPUTFILESTOMOVESTART = 366,
     INPUTFILESTOMOVEEND = 367,
     OUTPUTDIRECTORIESTOMOVESTART = 368,
     OUTPUTDIRECTORIESTOMOVEEND = 369,
     OUTPUTFILESTOMOVESTART = 370,
     OUTPUTFILESTOMOVEEND = 371,
     PROCESSESTOKILLSTART = 372,
     PROCESSESTOKILLEND = 373,
     PROCESSSTART = 374,
     PROCESSEND = 375,
     VARIABLESSTART = 376,
     VARIABLESEND = 377,
     INITIALVARIABLEVALUESSTART = 378,
     INITIALVARIABLEVALUESEND = 379,
     VARSTART = 380,
     VAREND = 381,
     INITIALVARIABLEVALUESSTRINGSTART = 382,
     INITIALVARIABLEVALUESSTRINGEND = 383,
     INITIALBASISSTATUSSTART = 384,
     INITIALBASISSTATUSEND = 385,
     OBJECTIVESSTART = 386,
     OBJECTIVESEND = 387,
     INITIALOBJECTIVEVALUESSTART = 388,
     INITIALOBJECTIVEVALUESEND = 389,
     OBJSTART = 390,
     OBJEND = 391,
     INITIALOBJECTIVEBOUNDSSTART = 392,
     INITIALOBJECTIVEBOUNDSEND = 393,
     CONSTRAINTSSTART = 394,
     CONSTRAINTSEND = 395,
     INITIALCONSTRAINTVALUESSTART = 396,
     INITIALCONSTRAINTVALUESEND = 397,
     CONSTART = 398,
     CONEND = 399,
     INITIALDUALVALUESSTART = 400,
     INITIALDUALVALUESEND = 401,
     SOLVEROPTIONSSTART = 402,
     SOLVEROPTIONSEND = 403,
     SOLVEROPTIONSTART = 404,
     SOLVEROPTIONEND = 405,
     DUMMY = 406
   };
#endif
/* Tokens.  */
#define ATTRIBUTETEXT 258
#define ELEMENTTEXT 259
#define INTEGER 260
#define DOUBLE 261
#define QUOTE 262
#define GREATERTHAN 263
#define ENDOFELEMENT 264
#define OSOLSTART 265
#define OSOLATTRIBUTETEXT 266
#define OSOLEND 267
#define LOCATIONTYPEATT 268
#define TRANSPORTTYPEATT 269
#define NUMBEROFOTHEROPTIONSATT 270
#define NUMBEROFJOBIDSATT 271
#define NUMBEROFPATHSATT 272
#define NUMBEROFPATHPAIRSATT 273
#define FROMATT 274
#define TOATT 275
#define MAKECOPYATT 276
#define SOLVERATT 277
#define CATEGORYATT 278
#define TYPEATT 279
#define NUMBEROFPROCESSESATT 280
#define NUMBEROFSOLVEROPTIONSATT 281
#define NUMBEROFVARIABLESATT 282
#define NUMBEROFOBJECTIVESATT 283
#define NUMBEROFCONSTRAINTSATT 284
#define NUMBEROFOTHERVARIABLEOPTIONSATT 285
#define NUMBEROFOTHEROBJECTIVEOPTIONSATT 286
#define NUMBEROFOTHERCONSTRAINTOPTIONSATT 287
#define NUMBEROFVARATT 288
#define NUMBEROFOBJATT 289
#define NUMBEROFCONATT 290
#define NAMEATT 291
#define IDXATT 292
#define VALUEATT 293
#define UNITATT 294
#define DESCRIPTIONATT 295
#define LBVALUEATT 296
#define UBVALUEATT 297
#define GENERALSTART 298
#define GENERALEND 299
#define SYSTEMSTART 300
#define SYSTEMEND 301
#define SERVICESTART 302
#define SERVICEEND 303
#define JOBSTART 304
#define JOBEND 305
#define OPTIMIZATIONSTART 306
#define OPTIMIZATIONEND 307
#define SERVICEURISTART 308
#define SERVICEURIEND 309
#define SERVICENAMESTART 310
#define SERVICENAMEEND 311
#define INSTANCENAMESTART 312
#define INSTANCENAMEEND 313
#define INSTANCELOCATIONSTART 314
#define INSTANCELOCATIONEND 315
#define JOBIDSTART 316
#define JOBIDEND 317
#define SOLVERTOINVOKESTART 318
#define SOLVERTOINVOKEEND 319
#define LICENSESTART 320
#define LICENSEEND 321
#define USERNAMESTART 322
#define USERNAMEEND 323
#define PASSWORDSTART 324
#define PASSWORDEND 325
#define CONTACTSTART 326
#define CONTACTEND 327
#define OTHEROPTIONSSTART 328
#define OTHEROPTIONSEND 329
#define OTHERSTART 330
#define OTHEREND 331
#define MINDISKSPACESTART 332
#define MINDISKSPACEEND 333
#define MINMEMORYSIZESTART 334
#define MINMEMORYSIZEEND 335
#define MINCPUSPEEDSTART 336
#define MINCPUSPEEDEND 337
#define MINCPUNUMBERSTART 338
#define MINCPUNUMBEREND 339
#define SERVICETYPESTART 340
#define SERVICETYPEEND 341
#define MAXTIMESTART 342
#define MAXTIMEEND 343
#define SCHEDULEDSTARTTIMESTART 344
#define SCHEDULEDSTARTTIMEEND 345
#define DEPENDENCIESSTART 346
#define DEPENDENCIESEND 347
#define REQUIREDDIRECTORIESSTART 348
#define REQUIREDDIRECTORIESEND 349
#define REQUIREDFILESSTART 350
#define REQUIREDFILESEND 351
#define PATHSTART 352
#define PATHEND 353
#define PATHPAIRSTART 354
#define PATHPAIREND 355
#define DIRECTORIESTOMAKESTART 356
#define DIRECTORIESTOMAKEEND 357
#define FILESTOCREATESTART 358
#define FILESTOCREATEEND 359
#define DIRECTORIESTODELETESTART 360
#define DIRECTORIESTODELETEEND 361
#define FILESTODELETESTART 362
#define FILESTODELETEEND 363
#define INPUTDIRECTORIESTOMOVESTART 364
#define INPUTDIRECTORIESTOMOVEEND 365
#define INPUTFILESTOMOVESTART 366
#define INPUTFILESTOMOVEEND 367
#define OUTPUTDIRECTORIESTOMOVESTART 368
#define OUTPUTDIRECTORIESTOMOVEEND 369
#define OUTPUTFILESTOMOVESTART 370
#define OUTPUTFILESTOMOVEEND 371
#define PROCESSESTOKILLSTART 372
#define PROCESSESTOKILLEND 373
#define PROCESSSTART 374
#define PROCESSEND 375
#define VARIABLESSTART 376
#define VARIABLESEND 377
#define INITIALVARIABLEVALUESSTART 378
#define INITIALVARIABLEVALUESEND 379
#define VARSTART 380
#define VAREND 381
#define INITIALVARIABLEVALUESSTRINGSTART 382
#define INITIALVARIABLEVALUESSTRINGEND 383
#define INITIALBASISSTATUSSTART 384
#define INITIALBASISSTATUSEND 385
#define OBJECTIVESSTART 386
#define OBJECTIVESEND 387
#define INITIALOBJECTIVEVALUESSTART 388
#define INITIALOBJECTIVEVALUESEND 389
#define OBJSTART 390
#define OBJEND 391
#define INITIALOBJECTIVEBOUNDSSTART 392
#define INITIALOBJECTIVEBOUNDSEND 393
#define CONSTRAINTSSTART 394
#define CONSTRAINTSEND 395
#define INITIALCONSTRAINTVALUESSTART 396
#define INITIALCONSTRAINTVALUESEND 397
#define CONSTART 398
#define CONEND 399
#define INITIALDUALVALUESSTART 400
#define INITIALDUALVALUESEND 401
#define SOLVEROPTIONSSTART 402
#define SOLVEROPTIONSEND 403
#define SOLVEROPTIONSTART 404
#define SOLVEROPTIONEND 405
#define DUMMY 406




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
#define YYFINAL  5
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   737

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  152
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  491
/* YYNRULES -- Number of rules.  */
#define YYNRULES  727
/* YYNRULES -- Number of states.  */
#define YYNSTATES  1214

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   406

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
     145,   146,   147,   148,   149,   150,   151
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     8,    11,    13,    16,    22,    23,    26,
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
     551,   552,   557,   559,   562,   565,   567,   571,   573,   574,
     577,   579,   581,   583,   585,   587,   589,   591,   593,   595,
     597,   599,   601,   603,   605,   607,   611,   613,   614,   615,
     620,   622,   625,   629,   633,   636,   638,   640,   643,   644,
     649,   655,   657,   662,   663,   666,   667,   673,   679,   681,
     686,   687,   690,   691,   697,   703,   705,   710,   711,   714,
     715,   721,   727,   729,   734,   735,   738,   739,   745,   751,
     753,   758,   759,   762,   763,   769,   775,   777,   782,   783,
     786,   790,   792,   793,   796,   798,   800,   802,   803,   808,
     809,   814,   815,   820,   823,   825,   831,   833,   838,   839,
     842,   846,   848,   849,   852,   854,   856,   858,   859,   864,
     865,   870,   871,   876,   879,   881,   887,   889,   894,   895,
     898,   902,   904,   905,   908,   910,   912,   914,   915,   920,
     921,   926,   927,   932,   935,   937,   943,   945,   950,   951,
     954,   958,   960,   961,   964,   966,   968,   970,   971,   976,
     977,   982,   983,   988,   991,   993,   999,  1001,  1006,  1007,
    1010,  1011,  1017,  1023,  1025,  1030,  1031,  1034,  1035,  1041,
    1047,  1049,  1054,  1055,  1058,  1059,  1065,  1070,  1072,  1077,
    1080,  1081,  1084,  1085,  1090,  1091,  1094,  1096,  1098,  1100,
    1101,  1106,  1107,  1112,  1113,  1118,  1120,  1123,  1124,  1128,
    1130,  1131,  1134,  1136,  1138,  1140,  1145,  1150,  1155,  1159,
    1161,  1166,  1167,  1171,  1173,  1174,  1179,  1186,  1188,  1189,
    1195,  1200,  1201,  1204,  1208,  1210,  1211,  1214,  1216,  1218,
    1223,  1224,  1229,  1232,  1234,  1235,  1241,  1246,  1247,  1250,
    1254,  1256,  1257,  1260,  1262,  1264,  1269,  1270,  1275,  1278,
    1280,  1281,  1287,  1292,  1293,  1296,  1300,  1302,  1303,  1306,
    1308,  1310,  1315,  1316,  1321,  1324,  1326,  1327,  1330,  1334,
    1336,  1337,  1340,  1342,  1344,  1346,  1348,  1350,  1352,  1354,
    1359,  1360,  1365,  1366,  1371,  1372,  1377,  1378,  1383,  1384,
    1389,  1390,  1395,  1399,  1400,  1403,  1407,  1409,  1410,  1413,
    1415,  1417,  1419,  1421,  1426,  1427,  1432,  1433,  1438,  1439,
    1444,  1447,  1449,  1450,  1454,  1456,  1457,  1462,  1468,  1470,
    1471,  1477,  1482,  1483,  1486,  1490,  1492,  1493,  1496,  1498,
    1500,  1505,  1506,  1511,  1514,  1516,  1517,  1523,  1528,  1529,
    1532,  1536,  1538,  1539,  1542,  1544,  1546,  1548,  1553,  1554,
    1559,  1560,  1565,  1568,  1570,  1571,  1574,  1578,  1580,  1581,
    1584,  1586,  1588,  1590,  1592,  1594,  1596,  1598,  1603,  1604,
    1609,  1610,  1615,  1616,  1621,  1622,  1627,  1628,  1633,  1634,
    1639,  1643,  1644,  1647,  1651,  1653,  1654,  1657,  1659,  1661,
    1663,  1665,  1670,  1671,  1676,  1677,  1682,  1683,  1688,  1691,
    1693,  1694,  1698,  1700,  1701,  1706,  1712,  1714,  1715,  1721,
    1726,  1727,  1730,  1734,  1736,  1737,  1740,  1742,  1744,  1749,
    1750,  1755,  1758,  1760,  1761,  1767,  1772,  1773,  1776,  1780,
    1782,  1783,  1786,  1788,  1790,  1792,  1797,  1798,  1803,  1804,
    1809,  1812,  1814,  1815,  1818,  1822,  1824,  1825,  1828,  1830,
    1832,  1834,  1836,  1838,  1840,  1842,  1847,  1848,  1853,  1854,
    1859,  1860,  1865,  1866,  1871,  1872,  1877,  1878,  1883,  1887,
    1888,  1891,  1895,  1897,  1898,  1901,  1903,  1905,  1907,  1909,
    1914,  1915,  1920,  1921,  1926,  1927,  1932,  1935,  1937,  1938,
    1944,  1946,  1951,  1952,  1955,  1956,  1961,  1962,  1965,  1967,
    1969,  1971,  1973,  1975,  1977,  1978,  1983,  1984,  1989,  1990,
    1995,  1996,  2001,  2002,  2007,  2008,  2013,  2016
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     153,     0,    -1,   154,     8,   155,    12,    -1,   154,     9,
      -1,    10,    -1,    10,    11,    -1,   156,   221,   261,   286,
     424,    -1,    -1,   157,   158,    -1,    43,    -1,     8,   159,
      44,    -1,     9,    -1,    -1,   159,   160,    -1,   161,    -1,
     165,    -1,   169,    -1,   173,    -1,   179,    -1,   183,    -1,
     187,    -1,   191,    -1,   195,    -1,   199,    -1,   205,    -1,
     162,   163,    -1,    53,    -1,     9,    -1,     8,    54,    -1,
      -1,     8,     4,   164,    54,    -1,   166,   167,    -1,    55,
      -1,     9,    -1,     8,    56,    -1,    -1,     8,     4,   168,
      56,    -1,   170,   171,    -1,    57,    -1,     9,    -1,     8,
      58,    -1,    -1,     8,     4,   172,    58,    -1,   174,   175,
     177,    -1,    59,    -1,    -1,    -1,    13,     3,   176,     7,
      -1,     9,    -1,     8,   178,    60,    -1,    -1,     4,    -1,
     180,   181,    -1,    61,    -1,     9,    -1,     8,    62,    -1,
      -1,     8,     4,   182,    62,    -1,   184,   185,    -1,    63,
      -1,     9,    -1,     8,    64,    -1,    -1,     8,     4,   186,
      64,    -1,   188,   189,    -1,    65,    -1,     9,    -1,     8,
      66,    -1,    -1,     8,     4,   190,    66,    -1,   192,   193,
      -1,    67,    -1,     9,    -1,     8,    68,    -1,    -1,     8,
       4,   194,    68,    -1,   196,   197,    -1,    69,    -1,     9,
      -1,     8,    70,    -1,    -1,     8,     4,   198,    70,    -1,
     200,   201,   203,    -1,    71,    -1,    -1,    -1,    14,     3,
     202,     7,    -1,     9,    -1,     8,   204,    72,    -1,    -1,
       4,    -1,   206,   207,     8,   208,    -1,    73,    -1,    15,
       7,     5,     7,    -1,   209,    74,    -1,    -1,   209,   210,
      -1,    -1,    75,   211,   212,   220,    -1,    -1,   212,   213,
      -1,   214,    -1,   216,    -1,   218,    -1,    -1,    36,     3,
     215,     7,    -1,    -1,    38,     3,   217,     7,    -1,    -1,
      40,     3,   219,     7,    -1,     9,    -1,     8,    76,    -1,
      -1,   222,   223,    -1,    45,    -1,     8,   224,    46,    -1,
       9,    -1,    -1,   224,   225,    -1,   226,    -1,   231,    -1,
     236,    -1,   241,    -1,   245,    -1,   227,   228,   230,    -1,
      77,    -1,    -1,    -1,    39,     3,   229,     7,    -1,     9,
      -1,     8,    78,    -1,     8,     6,    78,    -1,     8,     5,
      78,    -1,   232,   233,   235,    -1,    79,    -1,    -1,    -1,
      39,     3,   234,     7,    -1,     9,    -1,     8,    80,    -1,
       8,     6,    80,    -1,     8,     5,    80,    -1,   237,   238,
     240,    -1,    81,    -1,    -1,    -1,    39,     3,   239,     7,
      -1,     9,    -1,     8,    82,    -1,     8,     6,    82,    -1,
       8,     5,    82,    -1,   242,   243,    -1,    83,    -1,     9,
      -1,     8,    84,    -1,    -1,     8,     5,   244,    84,    -1,
     246,   247,     8,   248,    -1,    73,    -1,    15,     7,     5,
       7,    -1,   249,    74,    -1,    -1,   249,   250,    -1,    -1,
      75,   251,   252,   260,    -1,    -1,   252,   253,    -1,   254,
      -1,   256,    -1,   258,    -1,    -1,    36,     3,   255,     7,
      -1,    -1,    38,     3,   257,     7,    -1,    -1,    40,     3,
     259,     7,    -1,     9,    -1,     8,    76,    -1,    -1,   262,
     263,    -1,    47,    -1,     8,   264,    48,    -1,     9,    -1,
      -1,   264,   265,    -1,   266,    -1,   270,    -1,   267,   268,
      -1,    85,    -1,     9,    -1,     8,    86,    -1,    -1,     8,
       4,   269,    86,    -1,   271,   272,     8,   273,    -1,    73,
      -1,    15,     7,     5,     7,    -1,   274,    74,    -1,    -1,
     274,   275,    -1,    -1,    75,   276,   277,   285,    -1,    -1,
     277,   278,    -1,   279,    -1,   281,    -1,   283,    -1,    -1,
      36,     3,   280,     7,    -1,    -1,    38,     3,   282,     7,
      -1,    -1,    40,     3,   284,     7,    -1,     9,    -1,     8,
      76,    -1,   287,   288,    -1,    49,    -1,     8,   289,    50,
      -1,     9,    -1,    -1,   289,   290,    -1,   291,    -1,   296,
      -1,   300,    -1,   306,    -1,   312,    -1,   318,    -1,   324,
      -1,   330,    -1,   345,    -1,   360,    -1,   375,    -1,   390,
      -1,   396,    -1,   402,    -1,   408,    -1,   292,   293,   295,
      -1,    87,    -1,    -1,    -1,    39,     3,   294,     7,    -1,
       9,    -1,     8,    88,    -1,     8,     6,    88,    -1,     8,
       5,    88,    -1,   297,   298,    -1,    89,    -1,     9,    -1,
       8,    90,    -1,    -1,     8,     4,   299,    90,    -1,   301,
     302,     8,   303,    92,    -1,    91,    -1,    16,     7,     5,
       7,    -1,    -1,   303,   304,    -1,    -1,    61,     8,     4,
     305,    62,    -1,   307,   308,     8,   309,    94,    -1,    93,
      -1,    17,     7,     5,     7,    -1,    -1,   309,   310,    -1,
      -1,    97,     8,     4,   311,    98,    -1,   313,   314,     8,
     315,    96,    -1,    95,    -1,    17,     7,     5,     7,    -1,
      -1,   315,   316,    -1,    -1,    97,     8,     4,   317,    98,
      -1,   319,   320,     8,   321,   102,    -1,   101,    -1,    17,
       7,     5,     7,    -1,    -1,   321,   322,    -1,    -1,    97,
       8,     4,   323,    98,    -1,   325,   326,     8,   327,   104,
      -1,   103,    -1,    17,     7,     5,     7,    -1,    -1,   327,
     328,    -1,    -1,    97,     8,     4,   329,    98,    -1,   331,
     332,     8,   333,   110,    -1,   109,    -1,    18,     7,     5,
       7,    -1,    -1,   333,   334,    -1,   335,   336,   344,    -1,
      99,    -1,    -1,   336,   337,    -1,   338,    -1,   340,    -1,
     342,    -1,    -1,    19,     3,   339,     7,    -1,    -1,    20,
       3,   341,     7,    -1,    -1,    21,     3,   343,     7,    -1,
       8,   100,    -1,     9,    -1,   346,   347,     8,   348,   112,
      -1,   111,    -1,    18,     7,     5,     7,    -1,    -1,   348,
     349,    -1,   350,   351,   359,    -1,    99,    -1,    -1,   351,
     352,    -1,   353,    -1,   355,    -1,   357,    -1,    -1,    19,
       3,   354,     7,    -1,    -1,    20,     3,   356,     7,    -1,
      -1,    21,     3,   358,     7,    -1,     8,   100,    -1,     9,
      -1,   361,   362,     8,   363,   114,    -1,   113,    -1,    18,
       7,     5,     7,    -1,    -1,   363,   364,    -1,   365,   366,
     374,    -1,    99,    -1,    -1,   366,   367,    -1,   368,    -1,
     370,    -1,   372,    -1,    -1,    19,     3,   369,     7,    -1,
      -1,    20,     3,   371,     7,    -1,    -1,    21,     3,   373,
       7,    -1,     8,   100,    -1,     9,    -1,   376,   377,     8,
     378,   116,    -1,   115,    -1,    18,     7,     5,     7,    -1,
      -1,   378,   379,    -1,   380,   381,   389,    -1,    99,    -1,
      -1,   381,   382,    -1,   383,    -1,   385,    -1,   387,    -1,
      -1,    19,     3,   384,     7,    -1,    -1,    20,     3,   386,
       7,    -1,    -1,    21,     3,   388,     7,    -1,     8,   100,
      -1,     9,    -1,   391,   392,     8,   393,   108,    -1,   107,
      -1,    17,     7,     5,     7,    -1,    -1,   393,   394,    -1,
      -1,    97,     8,     4,   395,    98,    -1,   397,   398,     8,
     399,   106,    -1,   105,    -1,    17,     7,     5,     7,    -1,
      -1,   399,   400,    -1,    -1,    97,     8,     4,   401,    98,
      -1,   403,   404,     8,   405,   118,    -1,   117,    -1,    25,
       7,     5,     7,    -1,    -1,   405,   406,    -1,    -1,   119,
       8,     4,   407,   120,    -1,   409,   410,     8,   411,    -1,
      73,    -1,    15,     7,     5,     7,    -1,   412,    74,    -1,
      -1,   412,   413,    -1,    -1,    75,   414,   415,   423,    -1,
      -1,   415,   416,    -1,   417,    -1,   419,    -1,   421,    -1,
      -1,    36,     3,   418,     7,    -1,    -1,    38,     3,   420,
       7,    -1,    -1,    40,     3,   422,     7,    -1,     9,    -1,
       8,    76,    -1,    -1,   425,   426,   431,    -1,    51,    -1,
      -1,   426,   427,    -1,   428,    -1,   429,    -1,   430,    -1,
      27,     7,     5,     7,    -1,    29,     7,     5,     7,    -1,
      28,     7,     5,     7,    -1,     8,   432,    52,    -1,     9,
      -1,   433,   502,   562,   622,    -1,    -1,   434,   435,   436,
      -1,   121,    -1,    -1,    30,     7,     5,     7,    -1,     8,
     437,   448,   459,   470,   122,    -1,     9,    -1,    -1,   123,
     438,     8,   439,   124,    -1,    33,     7,     5,     7,    -1,
      -1,   439,   440,    -1,   441,   442,   447,    -1,   125,    -1,
      -1,   442,   443,    -1,   444,    -1,   445,    -1,    37,     7,
       5,     7,    -1,    -1,    38,     3,   446,     7,    -1,     8,
     126,    -1,     9,    -1,    -1,   127,   449,     8,   450,   128,
      -1,    33,     7,     5,     7,    -1,    -1,   450,   451,    -1,
     452,   453,   458,    -1,   125,    -1,    -1,   453,   454,    -1,
     455,    -1,   456,    -1,    37,     7,     5,     7,    -1,    -1,
      38,     3,   457,     7,    -1,     8,   126,    -1,     9,    -1,
      -1,   129,   460,     8,   461,   130,    -1,    33,     7,     5,
       7,    -1,    -1,   461,   462,    -1,   463,   464,   469,    -1,
     125,    -1,    -1,   464,   465,    -1,   466,    -1,   467,    -1,
      37,     7,     5,     7,    -1,    -1,    38,     3,   468,     7,
      -1,     8,   126,    -1,     9,    -1,    -1,   470,   471,    -1,
     472,   473,   488,    -1,    75,    -1,    -1,   473,   474,    -1,
     475,    -1,   476,    -1,   478,    -1,   480,    -1,   482,    -1,
     484,    -1,   486,    -1,    33,     7,     5,     7,    -1,    -1,
      36,     3,   477,     7,    -1,    -1,    38,     3,   479,     7,
      -1,    -1,    22,     3,   481,     7,    -1,    -1,    23,     3,
     483,     7,    -1,    -1,    24,     3,   485,     7,    -1,    -1,
      40,     3,   487,     7,    -1,     8,   489,    76,    -1,    -1,
     489,   490,    -1,   491,   492,   501,    -1,   125,    -1,    -1,
     492,   493,    -1,   494,    -1,   495,    -1,   497,    -1,   499,
      -1,    37,     7,     5,     7,    -1,    -1,    38,     3,   496,
       7,    -1,    -1,    41,     3,   498,     7,    -1,    -1,    42,
       3,   500,     7,    -1,     8,   126,    -1,     9,    -1,    -1,
     503,   504,   505,    -1,   131,    -1,    -1,    31,     7,     5,
       7,    -1,     8,   506,   517,   530,   132,    -1,     9,    -1,
      -1,   133,   507,     8,   508,   134,    -1,    34,     7,     5,
       7,    -1,    -1,   508,   509,    -1,   510,   511,   516,    -1,
     135,    -1,    -1,   511,   512,    -1,   513,    -1,   514,    -1,
      37,     7,     5,     7,    -1,    -1,    38,     3,   515,     7,
      -1,     8,   136,    -1,     9,    -1,    -1,   137,   518,     8,
     519,   138,    -1,    34,     7,     5,     7,    -1,    -1,   519,
     520,    -1,   521,   522,   529,    -1,   135,    -1,    -1,   522,
     523,    -1,   524,    -1,   525,    -1,   527,    -1,    37,     7,
       5,     7,    -1,    -1,    41,     3,   526,     7,    -1,    -1,
      42,     3,   528,     7,    -1,     8,   136,    -1,     9,    -1,
      -1,   530,   531,    -1,   532,   533,   548,    -1,    75,    -1,
      -1,   533,   534,    -1,   535,    -1,   536,    -1,   538,    -1,
     540,    -1,   542,    -1,   544,    -1,   546,    -1,    34,     7,
       5,     7,    -1,    -1,    36,     3,   537,     7,    -1,    -1,
      38,     3,   539,     7,    -1,    -1,    22,     3,   541,     7,
      -1,    -1,    23,     3,   543,     7,    -1,    -1,    24,     3,
     545,     7,    -1,    -1,    40,     3,   547,     7,    -1,     8,
     549,    76,    -1,    -1,   549,   550,    -1,   551,   552,   561,
      -1,   135,    -1,    -1,   552,   553,    -1,   554,    -1,   555,
      -1,   557,    -1,   559,    -1,    37,     7,     5,     7,    -1,
      -1,    38,     3,   556,     7,    -1,    -1,    41,     3,   558,
       7,    -1,    -1,    42,     3,   560,     7,    -1,     8,   126,
      -1,     9,    -1,    -1,   563,   564,   565,    -1,   139,    -1,
      -1,    32,     7,     5,     7,    -1,     8,   566,   577,   590,
     140,    -1,     9,    -1,    -1,   141,   567,     8,   568,   142,
      -1,    35,     7,     5,     7,    -1,    -1,   568,   569,    -1,
     570,   571,   576,    -1,   143,    -1,    -1,   571,   572,    -1,
     573,    -1,   574,    -1,    37,     7,     5,     7,    -1,    -1,
      38,     3,   575,     7,    -1,     8,   144,    -1,     9,    -1,
      -1,   145,   578,     8,   579,   146,    -1,    35,     7,     5,
       7,    -1,    -1,   579,   580,    -1,   581,   582,   589,    -1,
     143,    -1,    -1,   582,   583,    -1,   584,    -1,   585,    -1,
     587,    -1,    37,     7,     5,     7,    -1,    -1,    41,     3,
     586,     7,    -1,    -1,    42,     3,   588,     7,    -1,     8,
     144,    -1,     9,    -1,    -1,   590,   591,    -1,   592,   593,
     608,    -1,    75,    -1,    -1,   593,   594,    -1,   595,    -1,
     596,    -1,   598,    -1,   600,    -1,   602,    -1,   604,    -1,
     606,    -1,    35,     7,     5,     7,    -1,    -1,    36,     3,
     597,     7,    -1,    -1,    38,     3,   599,     7,    -1,    -1,
      22,     3,   601,     7,    -1,    -1,    23,     3,   603,     7,
      -1,    -1,    24,     3,   605,     7,    -1,    -1,    40,     3,
     607,     7,    -1,     8,   609,    76,    -1,    -1,   609,   610,
      -1,   611,   612,   621,    -1,   143,    -1,    -1,   612,   613,
      -1,   614,    -1,   615,    -1,   617,    -1,   619,    -1,    37,
       7,     5,     7,    -1,    -1,    38,     3,   616,     7,    -1,
      -1,    41,     3,   618,     7,    -1,    -1,    42,     3,   620,
       7,    -1,     8,   144,    -1,     9,    -1,    -1,   623,   624,
       8,   625,   148,    -1,   147,    -1,    26,     7,     5,     7,
      -1,    -1,   625,   626,    -1,    -1,   149,   627,   628,   642,
      -1,    -1,   628,   629,    -1,   630,    -1,   632,    -1,   634,
      -1,   636,    -1,   638,    -1,   640,    -1,    -1,    36,     3,
     631,     7,    -1,    -1,    38,     3,   633,     7,    -1,    -1,
      22,     3,   635,     7,    -1,    -1,    23,     3,   637,     7,
      -1,    -1,    24,     3,   639,     7,    -1,    -1,    40,     3,
     641,     7,    -1,     8,   150,    -1,     9,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   130,   130,   131,   133,   134,   136,   138,   138,   140,
     151,   152,   154,   154,   156,   156,   156,   156,   156,   157,
     157,   157,   157,   157,   157,   160,   162,   171,   172,   173,
     173,   176,   178,   187,   188,   189,   189,   192,   194,   203,
     204,   205,   205,   208,   210,   221,   222,   221,   229,   230,
     232,   232,   235,   237,   246,   247,   248,   248,   251,   253,
     262,   263,   264,   264,   267,   269,   278,   279,   280,   280,
     283,   285,   294,   295,   296,   296,   299,   301,   310,   311,
     312,   312,   315,   317,   328,   329,   328,   337,   338,   340,
     340,   343,   345,   355,   363,   368,   368,   371,   370,   386,
     386,   388,   388,   388,   391,   390,   402,   401,   413,   412,
     423,   423,   426,   426,   428,   439,   440,   442,   442,   444,
     444,   444,   444,   444,   446,   448,   459,   460,   459,   468,
     469,   470,   475,   482,   484,   495,   496,   495,   504,   505,
     506,   511,   519,   521,   532,   533,   532,   543,   544,   545,
     550,   558,   560,   569,   570,   572,   571,   579,   581,   591,
     599,   604,   604,   607,   606,   621,   621,   623,   623,   623,
     626,   625,   637,   636,   649,   648,   659,   659,   662,   662,
     664,   675,   676,   678,   678,   680,   680,   682,   684,   694,
     695,   697,   696,   706,   708,   718,   726,   731,   731,   734,
     733,   748,   748,   750,   750,   750,   753,   752,   764,   763,
     775,   774,   785,   785,   788,   790,   800,   801,   803,   803,
     805,   805,   805,   805,   805,   806,   806,   806,   806,   806,
     807,   807,   807,   807,   807,   810,   812,   823,   824,   823,
     833,   834,   835,   840,   847,   849,   859,   860,   861,   861,
     863,   865,   875,   882,   882,   885,   884,   897,   900,   910,
     917,   917,   919,   919,   931,   934,   944,   951,   951,   953,
     953,   965,   968,   977,   984,   984,   987,   986,   998,  1001,
    1011,  1018,  1018,  1021,  1020,  1032,  1035,  1045,  1054,  1054,
    1056,  1068,  1074,  1074,  1076,  1076,  1076,  1079,  1078,  1090,
    1089,  1101,  1100,  1112,  1112,  1115,  1118,  1128,  1136,  1136,
    1138,  1150,  1156,  1156,  1158,  1158,  1158,  1161,  1160,  1172,
    1171,  1183,  1182,  1194,  1194,  1197,  1200,  1210,  1219,  1219,
    1221,  1233,  1239,  1239,  1241,  1241,  1241,  1244,  1243,  1255,
    1254,  1266,  1265,  1277,  1277,  1280,  1283,  1293,  1301,  1301,
    1303,  1315,  1321,  1321,  1323,  1323,  1323,  1326,  1325,  1337,
    1336,  1348,  1347,  1359,  1359,  1362,  1365,  1375,  1382,  1382,
    1385,  1384,  1396,  1399,  1409,  1416,  1416,  1419,  1418,  1430,
    1434,  1444,  1451,  1451,  1454,  1453,  1465,  1467,  1477,  1485,
    1490,  1490,  1493,  1492,  1507,  1507,  1509,  1509,  1509,  1512,
    1511,  1523,  1522,  1534,  1533,  1544,  1544,  1547,  1547,  1549,
    1559,  1559,  1561,  1561,  1561,  1563,  1569,  1575,  1581,  1581,
    1583,  1585,  1585,  1587,  1591,  1591,  1600,  1601,  1603,  1603,
    1605,  1615,  1615,  1617,  1625,  1630,  1630,  1632,  1632,  1634,
    1648,  1647,  1660,  1660,  1663,  1663,  1666,  1676,  1676,  1678,
    1686,  1691,  1691,  1693,  1693,  1695,  1709,  1708,  1716,  1716,
    1719,  1719,  1722,  1732,  1732,  1734,  1742,  1747,  1747,  1749,
    1749,  1751,  1765,  1764,  1772,  1772,  1774,  1774,  1776,  1778,
    1783,  1783,  1786,  1787,  1788,  1789,  1790,  1791,  1792,  1794,
    1808,  1807,  1816,  1815,  1824,  1823,  1832,  1831,  1840,  1839,
    1848,  1847,  1856,  1873,  1873,  1875,  1885,  1890,  1890,  1893,
    1894,  1895,  1896,  1898,  1912,  1911,  1920,  1919,  1928,  1927,
    1935,  1935,  1939,  1939,  1941,  1945,  1945,  1954,  1955,  1957,
    1957,  1960,  1970,  1970,  1972,  1980,  1985,  1985,  1987,  1987,
    1989,  2004,  2003,  2016,  2016,  2019,  2019,  2022,  2032,  2032,
    2034,  2043,  2048,  2048,  2050,  2050,  2050,  2052,  2066,  2065,
    2079,  2078,  2091,  2091,  2095,  2095,  2097,  2099,  2104,  2104,
    2107,  2108,  2109,  2110,  2111,  2112,  2113,  2115,  2129,  2128,
    2138,  2137,  2147,  2146,  2156,  2155,  2165,  2164,  2174,  2173,
    2183,  2200,  2200,  2202,  2212,  2217,  2217,  2220,  2221,  2222,
    2223,  2225,  2240,  2239,  2249,  2248,  2258,  2257,  2266,  2266,
    2269,  2269,  2271,  2275,  2275,  2284,  2286,  2288,  2288,  2291,
    2301,  2301,  2303,  2311,  2316,  2316,  2318,  2318,  2320,  2335,
    2334,  2347,  2347,  2350,  2350,  2353,  2363,  2363,  2365,  2374,
    2379,  2379,  2381,  2381,  2381,  2383,  2397,  2396,  2410,  2409,
    2423,  2423,  2426,  2426,  2428,  2430,  2435,  2435,  2438,  2439,
    2440,  2441,  2442,  2443,  2444,  2446,  2460,  2459,  2468,  2467,
    2476,  2475,  2484,  2483,  2492,  2491,  2500,  2499,  2508,  2525,
    2525,  2527,  2537,  2542,  2542,  2545,  2546,  2547,  2548,  2550,
    2565,  2564,  2574,  2573,  2582,  2581,  2589,  2589,  2592,  2592,
    2597,  2607,  2615,  2615,  2618,  2617,  2635,  2635,  2638,  2639,
    2640,  2641,  2642,  2643,  2647,  2646,  2658,  2657,  2669,  2668,
    2680,  2679,  2691,  2690,  2702,  2701,  2713,  2713
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "ATTRIBUTETEXT", "ELEMENTTEXT",
  "INTEGER", "DOUBLE", "QUOTE", "GREATERTHAN", "ENDOFELEMENT", "OSOLSTART",
  "OSOLATTRIBUTETEXT", "OSOLEND", "LOCATIONTYPEATT", "TRANSPORTTYPEATT",
  "NUMBEROFOTHEROPTIONSATT", "NUMBEROFJOBIDSATT", "NUMBEROFPATHSATT",
  "NUMBEROFPATHPAIRSATT", "FROMATT", "TOATT", "MAKECOPYATT", "SOLVERATT",
  "CATEGORYATT", "TYPEATT", "NUMBEROFPROCESSESATT",
  "NUMBEROFSOLVEROPTIONSATT", "NUMBEROFVARIABLESATT",
  "NUMBEROFOBJECTIVESATT", "NUMBEROFCONSTRAINTSATT",
  "NUMBEROFOTHERVARIABLEOPTIONSATT", "NUMBEROFOTHEROBJECTIVEOPTIONSATT",
  "NUMBEROFOTHERCONSTRAINTOPTIONSATT", "NUMBEROFVARATT", "NUMBEROFOBJATT",
  "NUMBEROFCONATT", "NAMEATT", "IDXATT", "VALUEATT", "UNITATT",
  "DESCRIPTIONATT", "LBVALUEATT", "UBVALUEATT", "GENERALSTART",
  "GENERALEND", "SYSTEMSTART", "SYSTEMEND", "SERVICESTART", "SERVICEEND",
  "JOBSTART", "JOBEND", "OPTIMIZATIONSTART", "OPTIMIZATIONEND",
  "SERVICEURISTART", "SERVICEURIEND", "SERVICENAMESTART", "SERVICENAMEEND",
  "INSTANCENAMESTART", "INSTANCENAMEEND", "INSTANCELOCATIONSTART",
  "INSTANCELOCATIONEND", "JOBIDSTART", "JOBIDEND", "SOLVERTOINVOKESTART",
  "SOLVERTOINVOKEEND", "LICENSESTART", "LICENSEEND", "USERNAMESTART",
  "USERNAMEEND", "PASSWORDSTART", "PASSWORDEND", "CONTACTSTART",
  "CONTACTEND", "OTHEROPTIONSSTART", "OTHEROPTIONSEND", "OTHERSTART",
  "OTHEREND", "MINDISKSPACESTART", "MINDISKSPACEEND", "MINMEMORYSIZESTART",
  "MINMEMORYSIZEEND", "MINCPUSPEEDSTART", "MINCPUSPEEDEND",
  "MINCPUNUMBERSTART", "MINCPUNUMBEREND", "SERVICETYPESTART",
  "SERVICETYPEEND", "MAXTIMESTART", "MAXTIMEEND",
  "SCHEDULEDSTARTTIMESTART", "SCHEDULEDSTARTTIMEEND", "DEPENDENCIESSTART",
  "DEPENDENCIESEND", "REQUIREDDIRECTORIESSTART", "REQUIREDDIRECTORIESEND",
  "REQUIREDFILESSTART", "REQUIREDFILESEND", "PATHSTART", "PATHEND",
  "PATHPAIRSTART", "PATHPAIREND", "DIRECTORIESTOMAKESTART",
  "DIRECTORIESTOMAKEEND", "FILESTOCREATESTART", "FILESTOCREATEEND",
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
  "INITIALBASISSTATUSEND", "OBJECTIVESSTART", "OBJECTIVESEND",
  "INITIALOBJECTIVEVALUESSTART", "INITIALOBJECTIVEVALUESEND", "OBJSTART",
  "OBJEND", "INITIALOBJECTIVEBOUNDSSTART", "INITIALOBJECTIVEBOUNDSEND",
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
  "maxtimehead", "maxtimeunit", "@28", "maxtimebody", "scheduledstarttime",
  "starttimehead", "starttimebody", "@29", "dependencies",
  "dependencieshead", "numberofjobidsatt", "dependencieslist",
  "dependencyjobid", "@30", "requireddirectories",
  "requireddirectorieshead", "numberofreqdirpathsatt", "reqdirpathlist",
  "reqdirpath", "@31", "requiredfiles", "requiredfileshead",
  "numberofreqfilespathsatt", "reqfilespathlist", "reqfilepath", "@32",
  "directoriestomake", "directoriestomakehead",
  "numberofdirtomakepathsatt", "dirtomakepathlist", "dirtomakepath", "@33",
  "filestocreate", "filestocreatehead", "numberoffilestomakepathsatt",
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
  "@56", "initbasvarvalueend", "othervariableoptionlist",
  "othervariableoption", "othervariableoptionstart",
  "othervariableoptionsattlist", "othervariableoptionsatt",
  "othervariableoptionnumberofvar", "othervariableoptionname", "@57",
  "othervariableoptionvalue", "@58", "othervariableoptionsolver", "@59",
  "othervariableoptioncategory", "@60", "othervariableoptiontype", "@61",
  "othervariableoptiondescription", "@62", "restofothervariableoption",
  "othervariableoptionsvarlist", "othervariableoptionsvar",
  "othervariableoptionsvarstart", "othervaroptionattlist",
  "othervaroptionatt", "othervaroptionidx", "othervaroptionvalue", "@63",
  "othervaroptionlbvalue", "@64", "othervaroptionubvalue", "@65",
  "othervaroptionend", "objectives", "objectivesstart",
  "numberofotherobjectivesatt", "restofobjectives",
  "initialobjectivevalues", "numberofobjval", "objvaluelist",
  "initobjvalue", "objvaluestart", "initobjvalueattlist",
  "initobjvalueatt", "initobjvalueidxatt", "initobjvaluevalueatt", "@66",
  "initobjvalueend", "initialobjectivebounds", "numberofobjbounds",
  "objboundlist", "initobjbound", "objboundstart", "initobjboundattlist",
  "initobjboundatt", "initobjboundidxatt", "initobjvaluelowerboundatt",
  "@67", "initobjvalueupperboundatt", "@68", "initobjboundend",
  "otherobjectiveoptionlist", "otherobjectiveoption",
  "otherobjectiveoptionstart", "otherobjectiveoptionsattlist",
  "otherobjectiveoptionsatt", "otherobjectiveoptionnumberofvar",
  "otherobjectiveoptionname", "@69", "otherobjectiveoptionvalue", "@70",
  "otherobjectiveoptionsolver", "@71", "otherobjectiveoptioncategory",
  "@72", "otherobjectiveoptiontype", "@73",
  "otherobjectiveoptiondescription", "@74", "restofotherobjectiveoption",
  "otherobjectiveoptionsvarlist", "otherobjectiveoptionsvar",
  "otherobjectiveoptionsvarstart", "otherobjoptionattlist",
  "otherobjoptionatt", "otherobjoptionidx", "otherobjoptionvalue", "@75",
  "otherobjoptionlbvalue", "@76", "otherobjoptionubvalue", "@77",
  "otherobjoptionend", "constraints", "constraintsstart",
  "numberofotherconstraintsatt", "restofconstraints",
  "initialconstraintvalues", "numberofconval", "conlist", "initconvalue",
  "constart", "initconvalueattlist", "initconvalueatt",
  "initconvalueidxatt", "initconvaluevalueatt", "@78", "initconvalueend",
  "initialdualvalues", "numberofduals", "duallist", "initdualvalue",
  "dualstart", "initdualvalueattlist", "initdualvalueatt",
  "initdualvalueidxatt", "initdualvaluelowerboundatt", "@79",
  "initdualvalueupperboundatt", "@80", "initdualvalueend",
  "otherconstraintoptionlist", "otherconstraintoption",
  "otherconstraintoptionstart", "otherconstraintoptionsattlist",
  "otherconstraintoptionsatt", "otherconstraintoptionnumberofvar",
  "otherconstraintoptionname", "@81", "otherconstraintoptionvalue", "@82",
  "otherconstraintoptionsolver", "@83", "otherconstraintoptioncategory",
  "@84", "otherconstraintoptiontype", "@85",
  "otherconstraintoptiondescription", "@86", "restofotherconstraintoption",
  "otherconstraintoptionsvarlist", "otherconstraintoptionsvar",
  "otherconstraintoptionsvarstart", "otherconoptionattlist",
  "otherconoptionatt", "otherconoptionidx", "otherconoptionvalue", "@87",
  "otherconoptionlbvalue", "@88", "otherconoptionubvalue", "@89",
  "otherconoptionend", "solveroptions", "solveroptionsstart",
  "numberofsolveroptionsatt", "solveroptionlist", "solveroption", "@90",
  "solveroptionattlist", "solveroptionatt", "solveroptionname", "@91",
  "solveroptionvalue", "@92", "solveroptionsolver", "@93",
  "solveroptioncategory", "@94", "solveroptiontype", "@95",
  "solveroptiondescription", "@96", "solveroptionend", 0
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
     405,   406
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   152,   153,   153,   154,   154,   155,   156,   156,   157,
     158,   158,   159,   159,   160,   160,   160,   160,   160,   160,
     160,   160,   160,   160,   160,   161,   162,   163,   163,   164,
     163,   165,   166,   167,   167,   168,   167,   169,   170,   171,
     171,   172,   171,   173,   174,   175,   176,   175,   177,   177,
     178,   178,   179,   180,   181,   181,   182,   181,   183,   184,
     185,   185,   186,   185,   187,   188,   189,   189,   190,   189,
     191,   192,   193,   193,   194,   193,   195,   196,   197,   197,
     198,   197,   199,   200,   201,   202,   201,   203,   203,   204,
     204,   205,   206,   207,   208,   209,   209,   211,   210,   212,
     212,   213,   213,   213,   215,   214,   217,   216,   219,   218,
     220,   220,   221,   221,   222,   223,   223,   224,   224,   225,
     225,   225,   225,   225,   226,   227,   228,   229,   228,   230,
     230,   230,   230,   231,   232,   233,   234,   233,   235,   235,
     235,   235,   236,   237,   238,   239,   238,   240,   240,   240,
     240,   241,   242,   243,   243,   244,   243,   245,   246,   247,
     248,   249,   249,   251,   250,   252,   252,   253,   253,   253,
     255,   254,   257,   256,   259,   258,   260,   260,   261,   261,
     262,   263,   263,   264,   264,   265,   265,   266,   267,   268,
     268,   269,   268,   270,   271,   272,   273,   274,   274,   276,
     275,   277,   277,   278,   278,   278,   280,   279,   282,   281,
     284,   283,   285,   285,   286,   287,   288,   288,   289,   289,
     290,   290,   290,   290,   290,   290,   290,   290,   290,   290,
     290,   290,   290,   290,   290,   291,   292,   293,   294,   293,
     295,   295,   295,   295,   296,   297,   298,   298,   299,   298,
     300,   301,   302,   303,   303,   305,   304,   306,   307,   308,
     309,   309,   311,   310,   312,   313,   314,   315,   315,   317,
     316,   318,   319,   320,   321,   321,   323,   322,   324,   325,
     326,   327,   327,   329,   328,   330,   331,   332,   333,   333,
     334,   335,   336,   336,   337,   337,   337,   339,   338,   341,
     340,   343,   342,   344,   344,   345,   346,   347,   348,   348,
     349,   350,   351,   351,   352,   352,   352,   354,   353,   356,
     355,   358,   357,   359,   359,   360,   361,   362,   363,   363,
     364,   365,   366,   366,   367,   367,   367,   369,   368,   371,
     370,   373,   372,   374,   374,   375,   376,   377,   378,   378,
     379,   380,   381,   381,   382,   382,   382,   384,   383,   386,
     385,   388,   387,   389,   389,   390,   391,   392,   393,   393,
     395,   394,   396,   397,   398,   399,   399,   401,   400,   402,
     403,   404,   405,   405,   407,   406,   408,   409,   410,   411,
     412,   412,   414,   413,   415,   415,   416,   416,   416,   418,
     417,   420,   419,   422,   421,   423,   423,   424,   424,   425,
     426,   426,   427,   427,   427,   428,   429,   430,   431,   431,
     432,   433,   433,   434,   435,   435,   436,   436,   437,   437,
     438,   439,   439,   440,   441,   442,   442,   443,   443,   444,
     446,   445,   447,   447,   448,   448,   449,   450,   450,   451,
     452,   453,   453,   454,   454,   455,   457,   456,   458,   458,
     459,   459,   460,   461,   461,   462,   463,   464,   464,   465,
     465,   466,   468,   467,   469,   469,   470,   470,   471,   472,
     473,   473,   474,   474,   474,   474,   474,   474,   474,   475,
     477,   476,   479,   478,   481,   480,   483,   482,   485,   484,
     487,   486,   488,   489,   489,   490,   491,   492,   492,   493,
     493,   493,   493,   494,   496,   495,   498,   497,   500,   499,
     501,   501,   502,   502,   503,   504,   504,   505,   505,   506,
     506,   507,   508,   508,   509,   510,   511,   511,   512,   512,
     513,   515,   514,   516,   516,   517,   517,   518,   519,   519,
     520,   521,   522,   522,   523,   523,   523,   524,   526,   525,
     528,   527,   529,   529,   530,   530,   531,   532,   533,   533,
     534,   534,   534,   534,   534,   534,   534,   535,   537,   536,
     539,   538,   541,   540,   543,   542,   545,   544,   547,   546,
     548,   549,   549,   550,   551,   552,   552,   553,   553,   553,
     553,   554,   556,   555,   558,   557,   560,   559,   561,   561,
     562,   562,   563,   564,   564,   565,   565,   566,   566,   567,
     568,   568,   569,   570,   571,   571,   572,   572,   573,   575,
     574,   576,   576,   577,   577,   578,   579,   579,   580,   581,
     582,   582,   583,   583,   583,   584,   586,   585,   588,   587,
     589,   589,   590,   590,   591,   592,   593,   593,   594,   594,
     594,   594,   594,   594,   594,   595,   597,   596,   599,   598,
     601,   600,   603,   602,   605,   604,   607,   606,   608,   609,
     609,   610,   611,   612,   612,   613,   613,   613,   613,   614,
     616,   615,   618,   617,   620,   619,   621,   621,   622,   622,
     623,   624,   625,   625,   627,   626,   628,   628,   629,   629,
     629,   629,   629,   629,   631,   630,   633,   632,   635,   634,
     637,   636,   639,   638,   641,   640,   642,   642
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     4,     2,     1,     2,     5,     0,     2,     1,
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
       0,     4,     1,     2,     2,     1,     3,     1,     0,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     3,     1,     0,     0,     4,
       1,     2,     3,     3,     2,     1,     1,     2,     0,     4,
       5,     1,     4,     0,     2,     0,     5,     5,     1,     4,
       0,     2,     0,     5,     5,     1,     4,     0,     2,     0,
       5,     5,     1,     4,     0,     2,     0,     5,     5,     1,
       4,     0,     2,     0,     5,     5,     1,     4,     0,     2,
       3,     1,     0,     2,     1,     1,     1,     0,     4,     0,
       4,     0,     4,     2,     1,     5,     1,     4,     0,     2,
       3,     1,     0,     2,     1,     1,     1,     0,     4,     0,
       4,     0,     4,     2,     1,     5,     1,     4,     0,     2,
       3,     1,     0,     2,     1,     1,     1,     0,     4,     0,
       4,     0,     4,     2,     1,     5,     1,     4,     0,     2,
       3,     1,     0,     2,     1,     1,     1,     0,     4,     0,
       4,     0,     4,     2,     1,     5,     1,     4,     0,     2,
       0,     5,     5,     1,     4,     0,     2,     0,     5,     5,
       1,     4,     0,     2,     0,     5,     4,     1,     4,     2,
       0,     2,     0,     4,     0,     2,     1,     1,     1,     0,
       4,     0,     4,     0,     4,     1,     2,     0,     3,     1,
       0,     2,     1,     1,     1,     4,     4,     4,     3,     1,
       4,     0,     3,     1,     0,     4,     6,     1,     0,     5,
       4,     0,     2,     3,     1,     0,     2,     1,     1,     4,
       0,     4,     2,     1,     0,     5,     4,     0,     2,     3,
       1,     0,     2,     1,     1,     4,     0,     4,     2,     1,
       0,     5,     4,     0,     2,     3,     1,     0,     2,     1,
       1,     4,     0,     4,     2,     1,     0,     2,     3,     1,
       0,     2,     1,     1,     1,     1,     1,     1,     1,     4,
       0,     4,     0,     4,     0,     4,     0,     4,     0,     4,
       0,     4,     3,     0,     2,     3,     1,     0,     2,     1,
       1,     1,     1,     4,     0,     4,     0,     4,     0,     4,
       2,     1,     0,     3,     1,     0,     4,     5,     1,     0,
       5,     4,     0,     2,     3,     1,     0,     2,     1,     1,
       4,     0,     4,     2,     1,     0,     5,     4,     0,     2,
       3,     1,     0,     2,     1,     1,     1,     4,     0,     4,
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
       0,     4,     0,     4,     0,     4,     2,     1,     0,     5,
       1,     4,     0,     2,     0,     4,     0,     2,     1,     1,
       1,     1,     1,     1,     0,     4,     0,     4,     0,     4,
       0,     4,     0,     4,     0,     4,     2,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       0,     4,     0,     0,     5,     1,     7,     3,     9,     0,
     112,     0,     2,   114,   178,     0,    12,    11,     8,   180,
       0,     0,   117,   116,   113,     0,   215,   407,     0,   183,
     182,   179,     0,    10,    26,    32,    38,    44,    53,    59,
      65,    71,    77,    83,    92,    13,    14,     0,    15,     0,
      16,     0,    17,    45,    18,     0,    19,     0,    20,     0,
      21,     0,    22,     0,    23,    84,    24,     0,   409,     6,
     410,   218,   217,   214,     0,   115,   158,   125,   134,   143,
     152,   118,   119,   126,   120,   135,   121,   144,   122,     0,
     123,     0,     0,    27,    25,     0,    33,    31,     0,    39,
      37,     0,     0,     0,    54,    52,     0,    60,    58,     0,
      66,    64,     0,    72,    70,     0,    78,    76,     0,     0,
       0,     0,     0,     0,   181,   194,   188,   184,   185,     0,
     186,     0,     0,     0,     0,     0,     0,     0,     0,   153,
     151,     0,     0,    29,    28,    35,    34,    41,    40,    46,
      50,    48,    43,    56,    55,    62,    61,    68,    67,    74,
      73,    80,    79,    85,    89,    87,    82,     0,    95,   421,
     419,     0,     0,     0,   411,   412,   413,   414,   408,   216,
     387,   236,   245,   251,   258,   265,   272,   279,   373,   366,
     286,   306,   326,   346,   380,   219,   220,   237,   221,     0,
     222,     0,   223,     0,   224,     0,   225,     0,   226,     0,
     227,     0,   228,     0,   229,     0,   230,     0,   231,     0,
     232,     0,   233,     0,   234,     0,     0,   189,   187,     0,
       0,   127,     0,   129,   124,   136,     0,   138,   133,   145,
       0,   147,   142,   155,   154,     0,   161,     0,     0,     0,
       0,    51,     0,     0,     0,     0,     0,     0,     0,    90,
       0,     0,    91,     0,   423,     0,   522,   424,     0,     0,
       0,     0,     0,     0,   246,   244,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   191,   190,     0,   197,     0,     0,     0,   130,
       0,     0,     0,   139,     0,     0,     0,   148,     0,     0,
     157,     0,    30,    36,    42,    47,    49,    57,    63,    69,
      75,    81,    86,    88,    93,    94,    97,    96,   418,   524,
     610,   525,     0,     0,     0,     0,     0,   238,     0,   240,
     235,   248,   247,     0,   253,     0,   260,     0,   267,     0,
     274,     0,   281,     0,   288,     0,   308,     0,   328,     0,
     348,     0,   368,     0,   375,     0,   382,     0,   390,     0,
       0,   193,     0,   128,   132,   131,   137,   141,   140,   146,
     150,   149,   156,   159,   160,   163,   162,    99,   612,   698,
     613,     0,     0,     0,   428,   427,   422,   415,   417,   416,
       0,     0,     0,   241,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     386,     0,   192,   195,   196,   199,   198,   165,     0,   700,
     420,     0,     0,     0,     0,   529,   528,   523,     0,     0,
     444,   239,   243,   242,   249,   252,     0,   250,   254,   259,
     257,     0,   261,   266,   264,     0,   268,   273,     0,   271,
     275,   280,     0,   278,   282,   287,   291,   285,   289,   292,
     307,   311,   305,   309,   312,   327,   331,   325,   329,   332,
     347,   351,   345,   349,   352,   367,     0,   365,   369,   374,
       0,   372,   376,   381,   379,     0,   383,   388,   389,   392,
     391,   201,     0,     0,   110,     0,     0,     0,   100,   101,
     102,   103,    98,     0,     0,     0,   617,   616,   611,     0,
       0,   545,   425,     0,     0,     0,   460,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   394,
       0,     0,   176,     0,     0,     0,   166,   167,   168,   169,
     164,   111,   104,   106,   108,     0,   702,     0,     0,   633,
     526,     0,     0,     0,   564,     0,   431,     0,     0,     0,
     476,   255,   262,   269,   276,   283,     0,   304,     0,     0,
       0,   293,   294,   295,   296,   290,     0,   324,     0,     0,
       0,   313,   314,   315,   316,   310,     0,   344,     0,     0,
       0,   333,   334,   335,   336,   330,     0,   364,     0,     0,
       0,   353,   354,   355,   356,   350,   370,   377,   384,     0,
       0,   212,     0,     0,     0,   202,   203,   204,   205,   200,
     177,   170,   172,   174,     0,     0,     0,     0,     0,   614,
       0,     0,     0,   652,     0,   532,     0,     0,     0,     0,
       0,     0,   447,     0,     0,     0,     0,     0,     0,     0,
       0,   303,   297,   299,   301,   323,   317,   319,   321,   343,
     337,   339,   341,   363,   357,   359,   361,     0,     0,     0,
       0,   405,     0,     0,     0,   395,   396,   397,   398,   393,
     213,   206,   208,   210,     0,     0,     0,   105,   107,   109,
     701,   699,   704,   703,     0,   620,     0,     0,     0,     0,
       0,     0,   548,   567,   527,   565,   568,   430,   429,   434,
     432,   435,     0,     0,     0,   463,   479,   426,   477,   480,
     256,   263,   270,   277,   284,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   371,   378,   385,
     406,   399,   401,   403,     0,     0,     0,   171,   173,   175,
     706,     0,     0,     0,   636,   655,   615,   653,   656,   531,
     530,   535,   533,   536,     0,     0,     0,     0,   446,   450,
     445,   448,   451,     0,     0,     0,   298,   300,   302,   318,
     320,   322,   338,   340,   342,   358,   360,   362,     0,     0,
       0,   207,   209,   211,     0,   619,   618,   623,   621,   624,
       0,     0,     0,     0,   547,   551,   546,   549,   552,   591,
       0,     0,     0,     0,     0,     0,     0,   569,   570,   571,
     572,   573,   574,   575,   576,   566,     0,   443,     0,     0,
     436,   437,   438,   433,     0,   462,   466,   461,   464,   467,
     503,     0,     0,     0,     0,     0,     0,     0,   481,   482,
     483,   484,   485,   486,   487,   488,   478,   400,   402,   404,
       0,   727,     0,     0,     0,     0,     0,     0,   707,   708,
     709,   710,   711,   712,   713,   705,     0,   635,   639,   634,
     637,   640,   679,     0,     0,     0,     0,     0,     0,     0,
     657,   658,   659,   660,   661,   662,   663,   664,   654,     0,
     544,     0,     0,   537,   538,   539,   534,     0,     0,   582,
     584,   586,     0,   578,   580,   588,   442,     0,   440,     0,
     459,     0,     0,   452,   453,   454,   449,     0,     0,   494,
     496,   498,     0,   490,   492,   500,   726,   718,   720,   722,
     714,   716,   724,     0,   632,     0,     0,   625,   626,   627,
     622,     0,     0,   670,   672,   674,     0,   666,   668,   676,
     543,     0,   541,     0,   563,     0,     0,     0,   553,   554,
     555,   556,   550,   590,   594,   592,   595,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   458,     0,   456,     0,
     475,     0,     0,   468,   469,   470,   465,   502,   506,   504,
     507,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   631,     0,   629,     0,   651,     0,
       0,     0,   641,   642,   643,   644,   638,   678,   682,   680,
     683,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     562,     0,   558,   560,     0,   583,   585,   587,   577,   579,
     581,   589,   439,   441,     0,     0,   474,     0,   472,     0,
     495,   497,   499,   489,   491,   493,   501,   719,   721,   723,
     715,   717,   725,     0,     0,   650,     0,   646,   648,     0,
     671,   673,   675,   665,   667,   669,   677,   540,   542,     0,
       0,     0,     0,   609,     0,     0,     0,     0,   596,   597,
     598,   599,   600,   593,   455,   457,     0,     0,     0,   521,
       0,     0,     0,     0,   508,   509,   510,   511,   512,   505,
     628,   630,     0,     0,     0,     0,   697,     0,     0,     0,
       0,   684,   685,   686,   687,   688,   681,   557,   559,   561,
     608,     0,   602,   604,   606,   471,   473,   520,     0,   514,
     516,   518,   645,   647,   649,   696,     0,   690,   692,   694,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   601,   603,   605,   607,   513,   515,   517,   519,
     689,   691,   693,   695
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,     9,    10,    11,    18,    25,    45,    46,
      47,    94,   247,    48,    49,    97,   248,    50,    51,   100,
     249,    52,    53,   102,   250,   152,   252,    54,    55,   105,
     253,    56,    57,   108,   254,    58,    59,   111,   255,    60,
      61,   114,   256,    62,    63,   117,   257,    64,    65,   119,
     258,   166,   260,    66,    67,   121,   262,   263,   337,   397,
     448,   528,   529,   654,   530,   655,   531,   656,   532,    14,
      15,    24,    32,    81,    82,    83,   133,   306,   234,    84,
      85,   135,   310,   238,    86,    87,   137,   314,   242,    88,
      89,   140,   318,    90,    91,   142,   320,   321,   396,   447,
     522,   566,   567,   714,   568,   715,   569,   716,   570,    20,
      21,    31,    74,   127,   128,   129,   228,   379,   130,   131,
     230,   381,   382,   446,   521,   560,   645,   646,   774,   647,
     775,   648,   776,   649,    27,    28,    73,   123,   195,   196,
     197,   272,   410,   350,   198,   199,   275,   414,   200,   201,
     277,   416,   468,   676,   202,   203,   279,   418,   472,   677,
     204,   205,   281,   420,   476,   678,   206,   207,   283,   422,
     480,   679,   208,   209,   285,   424,   484,   680,   210,   211,
     287,   426,   488,   489,   552,   601,   602,   755,   603,   756,
     604,   757,   605,   212,   213,   289,   428,   493,   494,   553,
     611,   612,   758,   613,   759,   614,   760,   615,   214,   215,
     291,   430,   498,   499,   554,   621,   622,   761,   623,   762,
     624,   763,   625,   216,   217,   293,   432,   503,   504,   555,
     631,   632,   764,   633,   765,   634,   766,   635,   218,   219,
     295,   434,   508,   697,   220,   221,   297,   436,   512,   698,
     222,   223,   299,   438,   516,   699,   224,   225,   301,   440,
     441,   520,   559,   639,   705,   706,   818,   707,   819,   708,
     820,   709,    69,    70,   122,   174,   175,   176,   177,   178,
     265,   266,   267,   343,   406,   460,   544,   670,   740,   741,
     797,   860,   861,   862,  1015,   863,   546,   588,   743,   801,
     802,   864,   953,   954,   955,  1085,   956,   590,   674,   804,
     868,   869,   957,  1023,  1024,  1025,  1137,  1026,   675,   748,
     749,   805,   878,   879,   880,  1035,   881,  1036,   882,  1031,
     883,  1032,   884,  1033,   885,  1037,   886,   958,  1029,  1030,
    1089,  1144,  1145,  1146,  1195,  1147,  1196,  1148,  1197,  1149,
     340,   341,   402,   457,   541,   582,   730,   792,   793,   833,
     933,   934,   935,  1069,   936,   584,   667,   795,   837,   838,
     937,   998,   999,  1000,  1120,  1001,  1121,  1002,   668,   735,
     736,   796,   847,   848,   849,  1011,   850,  1012,   851,  1007,
     852,  1008,   853,  1009,   854,  1013,   855,   938,  1005,  1006,
    1074,  1128,  1129,  1130,  1191,  1131,  1192,  1132,  1193,  1133,
     399,   400,   453,   538,   579,   661,   782,   828,   829,   906,
     977,   978,   979,  1104,   980,   663,   727,   831,   910,   911,
     981,  1052,  1053,  1054,  1153,  1055,  1154,  1056,   728,   787,
     788,   832,   920,   921,   922,  1065,   923,  1066,   924,  1061,
     925,  1062,   926,  1063,   927,  1067,   928,   982,  1059,  1060,
    1109,  1161,  1162,  1163,  1199,  1164,  1200,  1165,  1201,  1166,
     450,   451,   534,   658,   723,   780,   824,   898,   899,  1041,
     900,  1042,   901,  1038,   902,  1039,   903,  1040,   904,  1043,
     905
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -71
static const yytype_int16 yypact[] =
{
      17,    24,    25,    89,   -71,   -71,   -12,   -71,   -71,    27,
      -8,   110,   -71,   -71,    -6,   260,   -71,   -71,   -71,   -71,
      47,   273,   -71,   -71,   -71,   186,   -71,    60,   276,   -71,
     -71,   -71,   -20,   -71,   -71,   -71,   -71,   -71,   -71,   -71,
     -71,   -71,   -71,   -71,   -71,   -71,   -71,   278,   -71,   280,
     -71,   282,   -71,    32,   -71,   284,   -71,   286,   -71,   288,
     -71,   290,   -71,   292,   -71,    55,   -71,   133,   -71,   -71,
     -71,   -71,   -71,   -71,   -18,   -71,   -71,   -71,   -71,   -71,
     -71,   -71,   -71,   115,   -71,   117,   -71,   119,   -71,   294,
     -71,   149,    18,   -71,   -71,    19,   -71,   -71,    16,   -71,
     -71,   169,   296,    14,   -71,   -71,    15,   -71,   -71,    12,
     -71,   -71,    13,   -71,   -71,     7,   -71,   -71,   177,   298,
     184,   136,    20,   -49,   -71,   -71,   -71,   -71,   -71,   300,
     -71,   180,   196,   302,   198,   304,   206,   306,    -1,   -71,
     -71,   208,   219,   -71,   -71,   -71,   -71,   -71,   -71,   -71,
     225,   -71,   -71,   -71,   -71,   -71,   -71,   -71,   -71,   -71,
     -71,   -71,   -71,   -71,   227,   -71,   -71,   233,   -71,   121,
     -71,   237,   239,   241,   -71,   -71,   -71,   -71,   -71,   -71,
     -71,   -71,   -71,   -71,   -71,   -71,   -71,   -71,   -71,   -71,
     -71,   -71,   -71,   -71,   -71,   -71,   -71,   201,   -71,   308,
     -71,   234,   -71,   309,   -71,   330,   -71,   331,   -71,   332,
     -71,   236,   -71,   238,   -71,   240,   -71,   333,   -71,   335,
     -71,   336,   -71,   245,   -71,   339,     1,   -71,   -71,   343,
     347,   -71,     4,   -71,   -71,   -71,     8,   -71,   -71,   -71,
       2,   -71,   -71,   -71,   -71,   247,   -71,   303,   305,   301,
     349,   -71,   307,   310,   299,   311,   297,   313,   351,   -71,
     314,   353,   -71,   244,   -71,   317,   231,   334,   361,   363,
     365,   368,   312,    -4,   -71,   -71,   366,   367,   369,   370,
     372,   373,   375,   376,   378,   379,   381,   382,   384,   385,
     387,   388,   390,   391,   393,   394,   396,   397,   399,   400,
     402,   403,   -71,   -71,   405,   -71,   406,   320,   323,   -71,
     407,   315,   324,   -71,   408,   325,   337,   -71,   328,   409,
     -71,   248,   -71,   -71,   -71,   -71,   -71,   -71,   -71,   -71,
     -71,   -71,   -71,   -71,   -71,   -71,   -71,   -71,   -71,   -71,
     250,   386,   411,   316,   413,   414,   415,   -71,    -3,   -71,
     -71,   -71,   -71,   418,   -71,   419,   -71,   420,   -71,   421,
     -71,   422,   -71,   423,   -71,   424,   -71,   425,   -71,   426,
     -71,   427,   -71,   428,   -71,   429,   -71,   430,   -71,   350,
     431,   -71,   253,   -71,   -71,   -71,   -71,   -71,   -71,   -71,
     -71,   -71,   -71,   -71,   -71,   -71,   -71,   -71,   -71,   293,
     342,   432,   321,   436,   257,   -71,   -71,   -71,   -71,   -71,
     435,   355,   356,   -71,   357,   438,   -27,   439,   125,   441,
     235,   442,   114,   443,    69,   444,    79,   445,    56,   446,
     -63,   447,   -66,   448,    -2,   449,     6,   450,   215,   451,
     -71,   261,   -71,   -71,   -71,   -71,   -71,   -71,   141,   -71,
     -71,   433,   453,   329,   456,   259,   -71,   -71,   455,   404,
     338,   -71,   -71,   -71,   -71,   -71,   458,   -71,   -71,   -71,
     -71,   459,   -71,   -71,   -71,   460,   -71,   -71,   461,   -71,
     -71,   -71,   462,   -71,   -71,   -71,   -71,   -71,   -71,   -71,
     -71,   -71,   -71,   -71,   -71,   -71,   -71,   -71,   -71,   -71,
     -71,   -71,   -71,   -71,   -71,   -71,   463,   -71,   -71,   -71,
     464,   -71,   -71,   -71,   -71,   465,   -71,   -71,   -71,   -71,
     -71,   -71,   174,   398,   -71,   472,   473,   474,   -71,   -71,
     -71,   -71,   -71,   457,   470,   475,   322,   -71,   -71,   476,
     452,   344,   -71,   477,   471,   454,   359,   478,   481,   485,
     486,   487,    96,   252,   255,   258,   488,   489,   490,   -71,
     185,   434,   -71,   492,   493,   494,   -71,   -71,   -71,   -71,
     -71,   -71,   -71,   -71,   -71,   495,   -71,   491,   466,   354,
     -71,   496,   497,   468,   -71,   499,   -71,   500,   498,   479,
     -71,   -71,   -71,   -71,   -71,   -71,   416,   -71,   505,   506,
     508,   -71,   -71,   -71,   -71,   -71,   417,   -71,   510,   511,
     512,   -71,   -71,   -71,   -71,   -71,   437,   -71,   515,   516,
     517,   -71,   -71,   -71,   -71,   -71,   440,   -71,   518,   519,
     520,   -71,   -71,   -71,   -71,   -71,   -71,   -71,   -71,   188,
     467,   -71,   521,   522,   523,   -71,   -71,   -71,   -71,   -71,
     -71,   -71,   -71,   -71,   524,   525,   526,   527,   191,   -71,
     528,   530,   501,   -71,   534,   -71,   535,   533,   -43,   537,
     217,   540,   -71,   539,   541,   -32,   502,   469,   480,   482,
     483,   -71,   -71,   -71,   -71,   -71,   -71,   -71,   -71,   -71,
     -71,   -71,   -71,   -71,   -71,   -71,   -71,   484,   503,   410,
     507,   -71,   544,   545,   547,   -71,   -71,   -71,   -71,   -71,
     -71,   -71,   -71,   -71,   546,   548,   549,   -71,   -71,   -71,
     -71,   -71,   -71,   -71,   552,   -71,   551,   543,   -60,   553,
     209,   554,   -71,   -71,   -71,   -71,   -71,   -71,   -71,   -71,
     -71,   -71,   555,    92,   556,   -71,   -71,   -71,   -71,   -71,
     -71,   -71,   -71,   -71,   -71,   558,   559,   561,   562,   563,
     564,   565,   566,   567,   568,   569,   570,   -71,   -71,   -71,
     -71,   -71,   -71,   -71,   572,   577,   578,   -71,   -71,   -71,
     -71,   579,   203,   582,   -71,   -71,   -71,   -71,   -71,   -71,
     -71,   -71,   -71,   -71,   581,   127,   123,   101,   -71,   -71,
     -71,   -71,   -71,   583,    88,   129,   -71,   -71,   -71,   -71,
     -71,   -71,   -71,   -71,   -71,   -71,   -71,   -71,   584,   585,
     586,   -71,   -71,   -71,   162,   -71,   -71,   -71,   -71,   -71,
     587,   137,   152,   105,   -71,   -71,   -71,   -71,   -71,   -71,
     560,   592,   593,   590,   595,   596,   597,   -71,   -71,   -71,
     -71,   -71,   -71,   -71,   -71,   -71,   401,   -71,   598,   599,
     -71,   -71,   -71,   -71,   195,   -71,   -71,   -71,   -71,   -71,
     -71,   600,   601,   603,   602,   604,   605,   607,   -71,   -71,
     -71,   -71,   -71,   -71,   -71,   -71,   -71,   -71,   -71,   -71,
     504,   -71,   608,   609,   610,   611,   612,   613,   -71,   -71,
     -71,   -71,   -71,   -71,   -71,   -71,   197,   -71,   -71,   -71,
     -71,   -71,   -71,   614,   615,   616,   617,   618,   619,   620,
     -71,   -71,   -71,   -71,   -71,   -71,   -71,   -71,   -71,   392,
     -71,   621,   622,   -71,   -71,   -71,   -71,    93,   -64,   -71,
     -71,   -71,   624,   -71,   -71,   -71,   -71,   625,   -71,   509,
     -71,   626,   623,   -71,   -71,   -71,   -71,   199,   -55,   -71,
     -71,   -71,   627,   -71,   -71,   -71,   -71,   -71,   -71,   -71,
     -71,   -71,   -71,   513,   -71,   629,   628,   -71,   -71,   -71,
     -71,    99,   -70,   -71,   -71,   -71,   632,   -71,   -71,   -71,
     -71,   633,   -71,   514,   -71,   634,   631,   636,   -71,   -71,
     -71,   -71,   -71,   -71,   -71,   -71,   -71,   635,   637,   638,
     639,   640,   641,   642,   644,   645,   -71,   648,   -71,   529,
     -71,   649,   655,   -71,   -71,   -71,   -71,   -71,   -71,   -71,
     -71,   652,   653,   654,   656,   657,   658,   659,   660,   661,
     662,   663,   664,   665,   -71,   668,   -71,   531,   -71,   667,
     673,   674,   -71,   -71,   -71,   -71,   -71,   -71,   -71,   -71,
     -71,   671,   672,   675,   676,   677,   678,   679,   680,   681,
     -71,   684,   -71,   -71,    83,   -71,   -71,   -71,   -71,   -71,
     -71,   -71,   -71,   -71,   683,   685,   -71,   686,   -71,    85,
     -71,   -71,   -71,   -71,   -71,   -71,   -71,   -71,   -71,   -71,
     -71,   -71,   -71,   687,   688,   -71,   691,   -71,   -71,    91,
     -71,   -71,   -71,   -71,   -71,   -71,   -71,   -71,   -71,   690,
     692,   693,   536,   -71,   694,   695,   699,   700,   -71,   -71,
     -71,   -71,   -71,   -71,   -71,   -71,   697,   698,   580,   -71,
     701,   704,   706,   707,   -71,   -71,   -71,   -71,   -71,   -71,
     -71,   -71,   705,   708,   709,   573,   -71,   711,   710,   716,
     717,   -71,   -71,   -71,   -71,   -71,   -71,   -71,   -71,   -71,
     -71,   718,   -71,   -71,   -71,   -71,   -71,   -71,   719,   -71,
     -71,   -71,   -71,   -71,   -71,   -71,   720,   -71,   -71,   -71,
     714,   715,   721,   722,   723,   724,   725,   726,   727,   728,
     729,   730,   -71,   -71,   -71,   -71,   -71,   -71,   -71,   -71,
     -71,   -71,   -71,   -71
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -71,   -71,   -71,   -71,   -71,   -71,   -71,   -71,   -71,   -71,
     -71,   -71,   -71,   -71,   -71,   -71,   -71,   -71,   -71,   -71,
     -71,   -71,   -71,   -71,   -71,   -71,   -71,   -71,   -71,   -71,
     -71,   -71,   -71,   -71,   -71,   -71,   -71,   -71,   -71,   -71,
     -71,   -71,   -71,   -71,   -71,   -71,   -71,   -71,   -71,   -71,
     -71,   -71,   -71,   -71,   -71,   -71,   -71,   -71,   -71,   -71,
     -71,   -71,   -71,   -71,   -71,   -71,   -71,   -71,   -71,   -71,
     -71,   -71,   -71,   -71,   -71,   -71,   -71,   -71,   -71,   -71,
     -71,   -71,   -71,   -71,   -71,   -71,   -71,   -71,   -71,   -71,
     -71,   -71,   -71,   -71,   -71,   -71,   -71,   -71,   -71,   -71,
     -71,   -71,   -71,   -71,   -71,   -71,   -71,   -71,   -71,   -71,
     -71,   -71,   -71,   -71,   -71,   -71,   -71,   -71,   -71,   -71,
     -71,   -71,   -71,   -71,   -71,   -71,   -71,   -71,   -71,   -71,
     -71,   -71,   -71,   -71,   -71,   -71,   -71,   -71,   -71,   -71,
     -71,   -71,   -71,   -71,   -71,   -71,   -71,   -71,   -71,   -71,
     -71,   -71,   -71,   -71,   -71,   -71,   -71,   -71,   -71,   -71,
     -71,   -71,   -71,   -71,   -71,   -71,   -71,   -71,   -71,   -71,
     -71,   -71,   -71,   -71,   -71,   -71,   -71,   -71,   -71,   -71,
     -71,   -71,   -71,   -71,   -71,   -71,   -71,   -71,   -71,   -71,
     -71,   -71,   -71,   -71,   -71,   -71,   -71,   -71,   -71,   -71,
     -71,   -71,   -71,   -71,   -71,   -71,   -71,   -71,   -71,   -71,
     -71,   -71,   -71,   -71,   -71,   -71,   -71,   -71,   -71,   -71,
     -71,   -71,   -71,   -71,   -71,   -71,   -71,   -71,   -71,   -71,
     -71,   -71,   -71,   -71,   -71,   -71,   -71,   -71,   -71,   -71,
     -71,   -71,   -71,   -71,   -71,   -71,   -71,   -71,   -71,   -71,
     -71,   -71,   -71,   -71,   -71,   -71,   -71,   -71,   -71,   -71,
     -71,   -71,   -71,   -71,   -71,   -71,   -71,   -71,   -71,   -71,
     -71,   -71,   -71,   -71,   -71,   -71,   -71,   -71,   -71,   -71,
     -71,   -71,   -71,   -71,   -71,   -71,   -71,   -71,   -71,   -71,
     -71,   -71,   -71,   -71,   -71,   -71,   -71,   -71,   -71,   -71,
     -71,   -71,   -71,   -71,   -71,   -71,   -71,   -71,   -71,   -71,
     -71,   -71,   -71,   -71,   -71,   -71,   -71,   -71,   -71,   -71,
     -71,   -71,   -71,   -71,   -71,   -71,   -71,   -71,   -71,   -71,
     -71,   -71,   -71,   -71,   -71,   -71,   -71,   -71,   -71,   -71,
     -71,   -71,   -71,   -71,   -71,   -71,   -71,   -71,   -71,   -71,
     -71,   -71,   -71,   -71,   -71,   -71,   -71,   -71,   -71,   -71,
     -71,   -71,   -71,   -71,   -71,   -71,   -71,   -71,   -71,   -71,
     -71,   -71,   -71,   -71,   -71,   -71,   -71,   -71,   -71,   -71,
     -71,   -71,   -71,   -71,   -71,   -71,   -71,   -71,   -71,   -71,
     -71,   -71,   -71,   -71,   -71,   -71,   -71,   -71,   -71,   -71,
     -71,   -71,   -71,   -71,   -71,   -71,   -71,   -71,   -71,   -71,
     -71,   -71,   -71,   -71,   -71,   -71,   -71,   -71,   -71,   -71,
     -71,   -71,   -71,   -71,   -71,   -71,   -71,   -71,   -71,   -71,
     -71,   -71,   -71,   -71,   -71,   -71,   -71,   -71,   -71,   -71,
     -71,   -71,   -71,   -71,   -71,   -71,   -71,   -71,   -71,   -71,
     -71,   -71,   -71,   -71,   -71,   -71,   -71,   -71,   -71,   -71,
     -71,   -71,   -71,   -71,   -71,   -71,   -71,   -71,   -71,   -71,
     -71,   -71,   -71,   -71,   -71,   -71,   -71,   -71,   -71,   -71,
     -71,   -71,   -71,   -71,   -71,   -71,   -71,   -71,   -71,   -71,
     -71
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint16 yytable[] =
{
     351,   179,   411,   412,   243,   302,  1057,   315,   316,   307,
     308,   161,  1003,   311,   312,   785,   157,   159,   153,   155,
     147,  1027,   143,   145,   180,     5,    75,     1,   169,   170,
     124,     8,   733,   501,   466,     4,   496,    13,   181,    12,
     182,    19,   183,   746,   184,   101,   185,   171,   172,   173,
     502,   497,   186,    76,   187,   125,   188,    77,   189,    78,
     190,    79,   191,    80,   192,   467,   193,   126,   194,   118,
    1028,  1004,   144,  1058,   148,   146,   154,   162,   158,   156,
     786,   160,   309,   244,   317,   413,   352,   303,   313,   734,
     747,  1122,  1123,  1138,  1139,   506,    26,     6,     7,  1155,
    1156,   993,   994,   510,   596,   597,   507,  1047,  1048,   856,
     857,    68,   511,   929,   930,   598,   599,   600,    16,    17,
    1124,  1125,  1140,  1141,  1126,  1127,  1142,  1143,  1157,  1158,
     995,   839,  1159,  1160,   996,   997,  1049,   870,   858,   859,
    1050,  1051,   931,   932,   168,   840,   841,   842,   120,   523,
     524,   871,   872,   873,   132,   491,   134,   843,   136,   844,
     912,   845,   874,   846,   141,   875,   482,   876,   492,   877,
     890,   891,   149,   483,   913,   914,   915,   525,   486,   526,
     163,   527,   561,   562,   892,   893,   894,   916,   917,   487,
     918,   167,   919,   640,   641,   229,   700,   701,   895,   231,
     896,   235,   897,   949,   950,   973,   974,  1019,  1020,   239,
     563,   478,   564,   866,   565,   245,   479,   799,   867,   470,
     800,   642,   471,   643,   702,   644,   703,   246,   704,   251,
      33,   259,   951,   952,   975,   976,  1021,  1022,   261,    34,
     271,    35,   264,    36,   268,    37,   269,    38,   270,    39,
     276,    40,   319,    41,   286,    42,   288,    43,   290,    44,
     606,   607,   835,   616,   617,   836,   626,   627,    22,    23,
     298,   608,   609,   610,   618,   619,   620,   628,   629,   630,
     908,    29,    30,   909,    71,    72,    92,    93,    95,    96,
      98,    99,   103,   104,   106,   107,   109,   110,   112,   113,
     115,   116,   138,   139,   150,   151,   164,   165,   226,   227,
     232,   233,   236,   237,   240,   241,   273,   274,   335,   336,
     348,   349,   394,   395,   404,   405,   278,   444,   445,   455,
     456,   474,   475,   514,   515,   518,   519,   536,   537,   721,
     722,   738,   739,   790,   791,   826,   827,   280,   282,   284,
     304,   292,   294,   296,   300,   305,   325,   322,   332,   324,
     334,   323,   339,   328,   342,   330,   344,   326,   345,   338,
     346,   347,   327,   353,   452,   354,   355,   329,   356,   357,
     459,   358,   359,   331,   360,   361,   333,   362,   363,   398,
     364,   365,   540,   366,   367,   387,   368,   369,   384,   370,
     371,   385,   372,   373,   388,   374,   375,   390,   376,   377,
     380,   378,   392,   383,   386,   389,   393,   401,   403,   391,
     407,   408,   409,   415,   417,   419,   421,   423,   425,   427,
     429,   431,   433,   435,   437,   439,   442,   543,   443,   454,
     449,   458,   461,   462,   463,   465,   469,   464,   473,   477,
     481,   485,   490,   495,   500,   505,   509,   513,   517,   533,
     535,   539,   542,   578,   575,   545,   547,   548,   549,   550,
     551,   556,   557,   558,   571,   572,   573,   574,   576,   586,
     577,   583,   591,   580,   585,   592,   581,   587,   589,   593,
     594,   595,   636,   637,   638,   651,   652,   653,   659,   662,
     657,   660,   666,   664,   669,   665,   672,   671,   682,   683,
     650,   684,   673,   686,   687,   688,   681,   685,   690,   691,
     692,   694,   695,   696,   711,   712,   713,   946,   990,     0,
     769,   717,   718,   719,   720,   724,   726,   689,   725,   729,
     693,   732,   731,   710,   737,   742,   744,   771,   772,   745,
     773,   784,     0,   777,     0,   778,   779,   781,   783,   794,
     789,   803,   798,   939,   750,   806,   807,   751,   808,   809,
     810,   811,   812,   813,   814,   815,   816,   817,   752,   821,
     753,   754,   767,   770,   822,   823,   825,   830,   834,     0,
     865,   887,   888,   889,   907,   940,   941,   942,   943,   944,
     945,   768,   948,   959,   960,   947,   961,   963,   964,   962,
     965,   967,   968,   969,   970,   971,   972,   983,   984,   985,
       0,   987,   988,   989,   986,   992,  1018,     0,   991,  1010,
    1014,  1046,  1034,  1017,  1072,  1016,  1045,  1064,  1068,  1073,
       0,  1071,  1075,     0,  1076,  1077,  1078,  1079,  1080,  1081,
    1070,  1082,  1083,  1084,   966,  1086,  1087,  1044,  1088,  1090,
    1091,  1092,  1170,  1093,  1094,  1095,  1096,  1097,  1098,  1099,
    1100,  1101,  1102,  1103,  1106,  1105,  1107,  1108,  1110,  1111,
       0,     0,  1112,  1113,  1114,  1115,  1116,  1117,  1118,  1119,
    1134,  1136,  1135,     0,  1150,  1151,  1152,  1167,  1172,  1168,
    1169,  1171,  1173,  1174,  1175,  1176,  1177,  1179,  1178,  1180,
    1181,     0,  1182,  1187,     0,  1183,  1184,  1185,  1186,  1188,
    1189,  1202,  1203,  1190,  1194,  1198,     0,     0,  1204,  1205,
    1206,  1207,  1208,  1209,  1210,  1211,  1212,  1213
};

static const yytype_int16 yycheck[] =
{
       4,    50,     5,     6,     5,     4,    76,     5,     6,     5,
       6,     4,    76,     5,     6,    75,     4,     4,     4,     4,
       4,    76,     4,     4,    73,     0,    46,    10,     8,     9,
      48,    43,    75,    99,    61,    11,    99,    45,    87,    12,
      89,    47,    91,    75,    93,    13,    95,    27,    28,    29,
     116,   114,   101,    73,   103,    73,   105,    77,   107,    79,
     109,    81,   111,    83,   113,    92,   115,    85,   117,    14,
     125,   135,    54,   143,    58,    56,    62,    70,    66,    64,
     140,    68,    78,    84,    82,    88,    90,    86,    80,   132,
     122,     8,     9,     8,     9,    97,    49,     8,     9,     8,
       9,     8,     9,    97,     8,     9,   108,     8,     9,     8,
       9,    51,   106,     8,     9,    19,    20,    21,     8,     9,
      37,    38,    37,    38,    41,    42,    41,    42,    37,    38,
      37,     8,    41,    42,    41,    42,    37,     8,    37,    38,
      41,    42,    37,    38,     8,    22,    23,    24,    15,     8,
       9,    22,    23,    24,    39,    99,    39,    34,    39,    36,
       8,    38,    33,    40,    15,    36,    97,    38,   112,    40,
       8,     9,     3,   104,    22,    23,    24,    36,    99,    38,
       3,    40,     8,     9,    22,    23,    24,    35,    36,   110,
      38,     7,    40,     8,     9,    15,     8,     9,    36,     3,
      38,     3,    40,     8,     9,     8,     9,     8,     9,     3,
      36,    97,    38,   125,    40,     7,   102,   125,   130,    94,
     128,    36,    97,    38,    36,    40,    38,     8,    40,     4,
      44,     4,    37,    38,    37,    38,    37,    38,     5,    53,
      39,    55,   121,    57,     7,    59,     7,    61,     7,    63,
      16,    65,     5,    67,    18,    69,    18,    71,    18,    73,
       8,     9,   135,     8,     9,   138,     8,     9,     8,     9,
      25,    19,    20,    21,    19,    20,    21,    19,    20,    21,
     143,     8,     9,   146,     8,     9,     8,     9,     8,     9,
       8,     9,     8,     9,     8,     9,     8,     9,     8,     9,
       8,     9,     8,     9,     8,     9,     8,     9,     8,     9,
       8,     9,     8,     9,     8,     9,     8,     9,    74,    75,
       8,     9,    74,    75,     8,     9,    17,    74,    75,     8,
       9,    96,    97,   118,   119,    74,    75,     8,     9,   148,
     149,   124,   125,   134,   135,   142,   143,    17,    17,    17,
       7,    18,    17,    17,    15,     8,     7,    54,     7,    58,
       7,    56,   131,    64,    30,    68,     5,    60,     5,    52,
       5,     3,    62,     7,    32,     8,     7,    66,     8,     7,
     123,     8,     7,    70,     8,     7,    72,     8,     7,   139,
       8,     7,   133,     8,     7,    80,     8,     7,    78,     8,
       7,    78,     8,     7,    80,     8,     7,    82,     8,     7,
       5,     8,    84,     7,     7,     7,     7,    31,     7,    82,
       7,     7,     7,     5,     5,     5,     5,     5,     5,     5,
       5,     5,     5,     5,     5,     5,    86,    33,     7,     7,
     147,     5,     7,    88,    88,     7,     7,    90,     7,     7,
       7,     7,     7,     7,     7,     7,     7,     7,     7,    26,
       7,     5,     7,   141,     7,   127,     8,     8,     8,     8,
       8,     8,     8,     8,    76,     3,     3,     3,     8,     8,
       5,   137,     4,     7,     7,     4,    34,    33,   129,     4,
       4,     4,     4,     4,     4,     3,     3,     3,     7,   145,
       5,    35,    34,     7,     5,     8,     8,     7,     3,     3,
      76,     3,    33,     3,     3,     3,   100,   100,     3,     3,
       3,     3,     3,     3,     3,     3,     3,   126,   136,    -1,
     120,     7,     7,     7,     7,     7,    35,   100,     8,     5,
     100,     8,     7,    76,     7,     5,     7,     3,     3,     8,
       3,     8,    -1,     7,    -1,     7,     7,     5,     7,     5,
       7,     5,     7,     3,    62,     7,     7,    98,     7,     7,
       7,     7,     7,     7,     7,     7,     7,     7,    98,     7,
      98,    98,    98,    76,     7,     7,     7,     5,     7,    -1,
       7,     7,     7,     7,     7,     3,     3,     7,     3,     3,
       3,    98,     3,     3,     3,     7,     3,     3,     3,     7,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
      -1,     3,     3,     3,     7,     3,     3,    -1,     7,     5,
       5,     3,     5,     7,     3,   126,     7,     5,     5,     3,
      -1,     7,     7,    -1,     7,     7,     7,     7,     7,     7,
     136,     7,     7,     5,   150,   126,     7,   144,     3,     7,
       7,     7,   126,     7,     7,     7,     7,     7,     7,     7,
       7,     7,     7,     5,     7,   144,     3,     3,     7,     7,
      -1,    -1,     7,     7,     7,     7,     7,     7,     7,     5,
       7,     5,     7,    -1,     7,     7,     5,     7,     3,     7,
       7,     7,     3,     3,     7,     7,   126,     3,     7,     3,
       3,    -1,     7,     3,    -1,     7,     7,   144,     7,     3,
       3,     7,     7,     5,     5,     5,    -1,    -1,     7,     7,
       7,     7,     7,     7,     7,     7,     7,     7
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,    10,   153,   154,    11,     0,     8,     9,    43,   155,
     156,   157,    12,    45,   221,   222,     8,     9,   158,    47,
     261,   262,     8,     9,   223,   159,    49,   286,   287,     8,
       9,   263,   224,    44,    53,    55,    57,    59,    61,    63,
      65,    67,    69,    71,    73,   160,   161,   162,   165,   166,
     169,   170,   173,   174,   179,   180,   183,   184,   187,   188,
     191,   192,   195,   196,   199,   200,   205,   206,    51,   424,
     425,     8,     9,   288,   264,    46,    73,    77,    79,    81,
      83,   225,   226,   227,   231,   232,   236,   237,   241,   242,
     245,   246,     8,     9,   163,     8,     9,   167,     8,     9,
     171,    13,   175,     8,     9,   181,     8,     9,   185,     8,
       9,   189,     8,     9,   193,     8,     9,   197,    14,   201,
      15,   207,   426,   289,    48,    73,    85,   265,   266,   267,
     270,   271,    39,   228,    39,   233,    39,   238,     8,     9,
     243,    15,   247,     4,    54,     4,    56,     4,    58,     3,
       8,     9,   177,     4,    62,     4,    64,     4,    66,     4,
      68,     4,    70,     3,     8,     9,   203,     7,     8,     8,
       9,    27,    28,    29,   427,   428,   429,   430,   431,    50,
      73,    87,    89,    91,    93,    95,   101,   103,   105,   107,
     109,   111,   113,   115,   117,   290,   291,   292,   296,   297,
     300,   301,   306,   307,   312,   313,   318,   319,   324,   325,
     330,   331,   345,   346,   360,   361,   375,   376,   390,   391,
     396,   397,   402,   403,   408,   409,     8,     9,   268,    15,
     272,     3,     8,     9,   230,     3,     8,     9,   235,     3,
       8,     9,   240,     5,    84,     7,     8,   164,   168,   172,
     176,     4,   178,   182,   186,   190,   194,   198,   202,     4,
     204,     5,   208,   209,   121,   432,   433,   434,     7,     7,
       7,    39,   293,     8,     9,   298,    16,   302,    17,   308,
      17,   314,    17,   320,    17,   326,    18,   332,    18,   347,
      18,   362,    18,   377,    17,   392,    17,   398,    25,   404,
      15,   410,     4,    86,     7,     8,   229,     5,     6,    78,
     234,     5,     6,    80,   239,     5,     6,    82,   244,     5,
     248,   249,    54,    56,    58,     7,    60,    62,    64,    66,
      68,    70,     7,    72,     7,    74,    75,   210,    52,   131,
     502,   503,    30,   435,     5,     5,     5,     3,     8,     9,
     295,     4,    90,     7,     8,     7,     8,     7,     8,     7,
       8,     7,     8,     7,     8,     7,     8,     7,     8,     7,
       8,     7,     8,     7,     8,     7,     8,     7,     8,   269,
       5,   273,   274,     7,    78,    78,     7,    80,    80,     7,
      82,    82,    84,     7,    74,    75,   250,   211,   139,   562,
     563,    31,   504,     7,     8,     9,   436,     7,     7,     7,
     294,     5,     6,    88,   299,     5,   303,     5,   309,     5,
     315,     5,   321,     5,   327,     5,   333,     5,   348,     5,
     363,     5,   378,     5,   393,     5,   399,     5,   405,     5,
     411,   412,    86,     7,    74,    75,   275,   251,   212,   147,
     622,   623,    32,   564,     7,     8,     9,   505,     5,   123,
     437,     7,    88,    88,    90,     7,    61,    92,   304,     7,
      94,    97,   310,     7,    96,    97,   316,     7,    97,   102,
     322,     7,    97,   104,   328,     7,    99,   110,   334,   335,
       7,    99,   112,   349,   350,     7,    99,   114,   364,   365,
       7,    99,   116,   379,   380,     7,    97,   108,   394,     7,
      97,   106,   400,     7,   118,   119,   406,     7,    74,    75,
     413,   276,   252,     8,     9,    36,    38,    40,   213,   214,
     216,   218,   220,    26,   624,     7,     8,     9,   565,     5,
     133,   506,     7,    33,   438,   127,   448,     8,     8,     8,
       8,     8,   336,   351,   366,   381,     8,     8,     8,   414,
     277,     8,     9,    36,    38,    40,   253,   254,   256,   258,
     260,    76,     3,     3,     3,     7,     8,     5,   141,   566,
       7,    34,   507,   137,   517,     7,     8,    33,   449,   129,
     459,     4,     4,     4,     4,     4,     8,     9,    19,    20,
      21,   337,   338,   340,   342,   344,     8,     9,    19,    20,
      21,   352,   353,   355,   357,   359,     8,     9,    19,    20,
      21,   367,   368,   370,   372,   374,     8,     9,    19,    20,
      21,   382,   383,   385,   387,   389,     4,     4,     4,   415,
       8,     9,    36,    38,    40,   278,   279,   281,   283,   285,
      76,     3,     3,     3,   215,   217,   219,     5,   625,     7,
      35,   567,   145,   577,     7,     8,    34,   518,   530,     5,
     439,     7,     8,    33,   460,   470,   305,   311,   317,   323,
     329,   100,     3,     3,     3,   100,     3,     3,     3,   100,
       3,     3,     3,   100,     3,     3,     3,   395,   401,   407,
       8,     9,    36,    38,    40,   416,   417,   419,   421,   423,
      76,     3,     3,     3,   255,   257,   259,     7,     7,     7,
       7,   148,   149,   626,     7,     8,    35,   578,   590,     5,
     508,     7,     8,    75,   132,   531,   532,     7,   124,   125,
     440,   441,     5,   450,     7,     8,    75,   122,   471,   472,
      62,    98,    98,    98,    98,   339,   341,   343,   354,   356,
     358,   369,   371,   373,   384,   386,   388,    98,    98,   120,
      76,     3,     3,     3,   280,   282,   284,     7,     7,     7,
     627,     5,   568,     7,     8,    75,   140,   591,   592,     7,
     134,   135,   509,   510,     5,   519,   533,   442,     7,   125,
     128,   451,   452,     5,   461,   473,     7,     7,     7,     7,
       7,     7,     7,     7,     7,     7,     7,     7,   418,   420,
     422,     7,     7,     7,   628,     7,   142,   143,   569,   570,
       5,   579,   593,   511,     7,   135,   138,   520,   521,     8,
      22,    23,    24,    34,    36,    38,    40,   534,   535,   536,
     538,   540,   542,   544,   546,   548,     8,     9,    37,    38,
     443,   444,   445,   447,   453,     7,   125,   130,   462,   463,
       8,    22,    23,    24,    33,    36,    38,    40,   474,   475,
     476,   478,   480,   482,   484,   486,   488,     7,     7,     7,
       8,     9,    22,    23,    24,    36,    38,    40,   629,   630,
     632,   634,   636,   638,   640,   642,   571,     7,   143,   146,
     580,   581,     8,    22,    23,    24,    35,    36,    38,    40,
     594,   595,   596,   598,   600,   602,   604,   606,   608,     8,
       9,    37,    38,   512,   513,   514,   516,   522,   549,     3,
       3,     3,     7,     3,     3,     3,   126,     7,     3,     8,
       9,    37,    38,   454,   455,   456,   458,   464,   489,     3,
       3,     3,     7,     3,     3,     3,   150,     3,     3,     3,
       3,     3,     3,     8,     9,    37,    38,   572,   573,   574,
     576,   582,   609,     3,     3,     3,     7,     3,     3,     3,
     136,     7,     3,     8,     9,    37,    41,    42,   523,   524,
     525,   527,   529,    76,   135,   550,   551,   541,   543,   545,
       5,   537,   539,   547,     5,   446,   126,     7,     3,     8,
       9,    37,    38,   465,   466,   467,   469,    76,   125,   490,
     491,   481,   483,   485,     5,   477,   479,   487,   635,   637,
     639,   631,   633,   641,   144,     7,     3,     8,     9,    37,
      41,    42,   583,   584,   585,   587,   589,    76,   143,   610,
     611,   601,   603,   605,     5,   597,   599,   607,     5,   515,
     136,     7,     3,     3,   552,     7,     7,     7,     7,     7,
       7,     7,     7,     7,     5,   457,   126,     7,     3,   492,
       7,     7,     7,     7,     7,     7,     7,     7,     7,     7,
       7,     7,     7,     5,   575,   144,     7,     3,     3,   612,
       7,     7,     7,     7,     7,     7,     7,     7,     7,     5,
     526,   528,     8,     9,    37,    38,    41,    42,   553,   554,
     555,   557,   559,   561,     7,     7,     5,   468,     8,     9,
      37,    38,    41,    42,   493,   494,   495,   497,   499,   501,
       7,     7,     5,   586,   588,     8,     9,    37,    38,    41,
      42,   613,   614,   615,   617,   619,   621,     7,     7,     7,
     126,     7,     3,     3,     3,     7,     7,   126,     7,     3,
       3,     3,     7,     7,     7,   144,     7,     3,     3,     3,
       5,   556,   558,   560,     5,   496,   498,   500,     5,   616,
     618,   620,     7,     7,     7,     7,     7,     7,     7,     7,
       7,     7,     7,     7
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
	{	parserData-> minDiskSpacePresent = true;
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
	{	parserData-> minMemorySizePresent = true;
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
	{	parserData-> minCPUSpeedPresent = true;
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

  case 215:

    {	if (parserData->osoljobPresent)
	{	osolerror( NULL, osoption, parserData, "only one <job> element allowed");
	}
	else
	{	parserData->osoljobPresent = true;
		osoption->job = new JobOption();
	}
;}
    break;

  case 236:

    {	if (parserData->maxTimePresent)
	{	osolerror( NULL, osoption, parserData, "only one <maxTime> element allowed");
	}
	else
	{	parserData-> maxTimePresent = true;
		osoption->job->maxTime = new MaxTime();
		osoption->job->maxTime->unit = "second"; 
	}
;}
    break;

  case 238:

    {	if ( (strcmp((yyvsp[(2) - (2)].sval),"second") == 0) || (strcmp((yyvsp[(2) - (2)].sval),"minute") == 0) || (strcmp((yyvsp[(2) - (2)].sval),"hour") == 0) ||
						     (strcmp((yyvsp[(2) - (2)].sval),"day")    == 0) || (strcmp((yyvsp[(2) - (2)].sval),"week") == 0) ||
						     (strcmp((yyvsp[(2) - (2)].sval),"month")  == 0) || (strcmp((yyvsp[(2) - (2)].sval),"year") == 0) ) 
                osoption->job->maxTime->unit = (yyvsp[(2) - (2)].sval);
	else
		osolerror( NULL, osoption, parserData, "Not a valid time unit");
;}
    break;

  case 242:

    {	if ((yyvsp[(2) - (3)].dval) < 0)
		osolerror( NULL, osoption, parserData, "maxTime cannot be negative");
	osoption->job->maxTime->value = (yyvsp[(2) - (3)].dval);
;}
    break;

  case 243:

    {	if ((yyvsp[(2) - (3)].ival) < 0)
		osolerror( NULL, osoption, parserData, "maxTime cannot be negative");
	osoption->job->maxTime->value = (yyvsp[(2) - (3)].ival);
;}
    break;

  case 245:

    {	if (parserData->scheduledStartTimePresent)
	{	osolerror( NULL, osoption, parserData, "only one <scheduledStartTime> element allowed");
	}
	else
	{	parserData->scheduledStartTimePresent = true;
		osoption->job->scheduledStartTime = "1970-01-01T00:00:00-00:00";
	}
;}
    break;

  case 248:

    {osoption->job->scheduledStartTime = (yyvsp[(2) - (2)].sval);;}
    break;

  case 251:

    {	if (parserData->dependenciesPresent)
	{	osolerror( NULL, osoption, parserData, "only one <dependencies> element allowed");
	}
	else
	{	parserData->dependenciesPresent = true;
		osoption->job->dependencies = new JobDependencies();
	}
;}
    break;

  case 252:

    {	if ((yyvsp[(3) - (4)].ival) < 1)
		osolerror( NULL, osoption, parserData, "Number of job IDs must be at least 1");
	osoption->job->dependencies->numberOfJobIDs = (yyvsp[(3) - (4)].ival);
	osoption->job->dependencies->jobID = new std::string[(yyvsp[(3) - (4)].ival)];
;}
    break;

  case 255:

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

  case 258:

    {	if (parserData->requiredDirectoriesPresent)
	{	osolerror( NULL, osoption, parserData, "only one <requiredDirectories> element allowed");
	}
	else
	{	parserData->requiredDirectoriesPresent = true;
		osoption->job->requiredDirectories = new DirectoriesAndFiles();
	}
;}
    break;

  case 259:

    {	if ((yyvsp[(3) - (4)].ival) < 1)
		osolerror( NULL, osoption, parserData, "Number of paths must be at least 1");
	osoption->job->requiredDirectories->numberOfPaths = (yyvsp[(3) - (4)].ival);
	osoption->job->requiredDirectories->path = new std::string[(yyvsp[(3) - (4)].ival)];
;}
    break;

  case 262:

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

  case 265:

    {	if (parserData->requiredFilesPresent)
	{	osolerror( NULL, osoption, parserData, "only one <requiredFiles> element allowed");
	}
	else
	{	parserData->requiredFilesPresent = true;
		osoption->job->requiredFiles = new DirectoriesAndFiles();
	}
;}
    break;

  case 266:

    {	if ((yyvsp[(3) - (4)].ival) < 1)
		osolerror( NULL, osoption, parserData, "Number of paths must be at least 1");
	osoption->job->requiredFiles->numberOfPaths = (yyvsp[(3) - (4)].ival);
	osoption->job->requiredFiles->path = new std::string[(yyvsp[(3) - (4)].ival)];
;}
    break;

  case 269:

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

  case 272:

    {	if (parserData->directoriesToMakePresent)
	{	osolerror( NULL, osoption, parserData, "only one <directoriesToMake> element allowed");
	}
	else
	{	parserData->directoriesToMakePresent = true;
		osoption->job->directoriesToMake = new DirectoriesAndFiles();
	}
;}
    break;

  case 273:

    {	if ((yyvsp[(3) - (4)].ival) < 1)
		osolerror( NULL, osoption, parserData, "Number of paths must be at least 1");
	osoption->job->directoriesToMake->numberOfPaths = (yyvsp[(3) - (4)].ival);
	osoption->job->directoriesToMake->path = new std::string[(yyvsp[(3) - (4)].ival)];
;}
    break;

  case 276:

    {	if (parserData->numberOfDirectoriesToMake >= osoption->job->directoriesToMake->numberOfPaths)
	{	osolerror (NULL, osoption, parserData, "too many job IDs in <directoriesToMake> element");
	}
	else
	{	osoption->job->directoriesToMake->path[parserData->numberOfDirectoriesToMake] = (yyvsp[(3) - (3)].sval);
		parserData->numberOfDirectoriesToMake++;
	};
;}
    break;

  case 279:

    {	if (parserData->filesToCreatePresent)
	{	osolerror( NULL, osoption, parserData, "only one <filesToCreate> element allowed");
	}
	else
	{	parserData->filesToCreatePresent = true;
		osoption->job->filesToCreate = new DirectoriesAndFiles();
	}
;}
    break;

  case 280:

    {	if ((yyvsp[(3) - (4)].ival) < 0)
		osolerror( NULL, osoption, parserData, "Number of paths cannot be negative");
	osoption->job->filesToCreate->numberOfPaths = (yyvsp[(3) - (4)].ival);
	osoption->job->filesToCreate->path = new std::string[(yyvsp[(3) - (4)].ival)];
;}
    break;

  case 283:

    {	if (parserData->numberOfFilesToCreate >= osoption->job->filesToCreate->numberOfPaths)
	{	osolerror (NULL, osoption, parserData, "too many job IDs in <filesToCreate> element");
	}
	else
	{	osoption->job->filesToCreate->path[parserData->numberOfFilesToCreate] = (yyvsp[(3) - (3)].sval);
		parserData->numberOfFilesToCreate++;
	};
;}
    break;

  case 286:

    {	if (parserData->inputDirectoriesToMovePresent)
	{	osolerror( NULL, osoption, parserData, "only one <inputDirectoriesToMove> element allowed");
	}
	else
	{	parserData->inputDirectoriesToMovePresent = true;
		osoption->job->inputDirectoriesToMove = new PathPairs();
	}
;}
    break;

  case 287:

    {	if ((yyvsp[(3) - (4)].ival) <= 0)
		osolerror (NULL, osoption, parserData, "Require positive number of directories to move");
	osoption->job->inputDirectoriesToMove->numberOfPathPairs = (yyvsp[(3) - (4)].ival);
	osoption->job->inputDirectoriesToMove->pathPair = new PathPair*[(yyvsp[(3) - (4)].ival)];
	for (int i = 0; i < (yyvsp[(3) - (4)].ival); i++)
		osoption->job->inputDirectoriesToMove->pathPair[i] = new PathPair();
;}
    break;

  case 290:

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

  case 291:

    {	if (parserData->numberOfInputDirectoriesToMove >= osoption->job->inputDirectoriesToMove->numberOfPathPairs)
	{	osolerror (NULL, osoption, parserData, "too many path pairs in <inputDirectoriesToMove> element");
	};
;}
    break;

  case 297:

    {	if (parserData->pathPairFromPresent)
	{	osolerror( NULL, osoption, parserData, "only one \"from\" attribute allowed");
	}
	else
	{	parserData->pathPairFromPresent = true;
		osoption->job->inputDirectoriesToMove->pathPair[parserData->numberOfInputDirectoriesToMove]->from = (yyvsp[(2) - (2)].sval);
	}
;}
    break;

  case 299:

    {	if (parserData->pathPairToPresent)
	{	osolerror( NULL, osoption, parserData, "only one \"to\" attribute allowed");
	}
	else
	{	parserData->pathPairToPresent = true;
		osoption->job->inputDirectoriesToMove->pathPair[parserData->numberOfInputDirectoriesToMove]->to = (yyvsp[(2) - (2)].sval);
	}
;}
    break;

  case 301:

    {	if (parserData->pathPairMakeCopyPresent)
	{	osolerror( NULL, osoption, parserData, "only one \"makeCopy\" attribute allowed");
	}
	else
	{	parserData->pathPairMakeCopyPresent = true;
		if ((yyvsp[(2) - (2)].sval) == "true")
			osoption->job->inputDirectoriesToMove->pathPair[parserData->numberOfInputDirectoriesToMove]->makeCopy = true;
	}
;}
    break;

  case 306:

    {	if (parserData->inputFilesToMovePresent)
	{	osolerror( NULL, osoption, parserData, "only one <inputFilesToMove> element allowed");
	}
	else
	{	parserData->inputFilesToMovePresent = true;
		osoption->job->inputFilesToMove = new PathPairs();
	}
;}
    break;

  case 307:

    {	if ((yyvsp[(3) - (4)].ival) <= 0)
		osolerror (NULL, osoption, parserData, "Require positive number of files to move");
	osoption->job->inputFilesToMove->numberOfPathPairs = (yyvsp[(3) - (4)].ival);
	osoption->job->inputFilesToMove->pathPair = new PathPair*[(yyvsp[(3) - (4)].ival)];
	for (int i = 0; i < (yyvsp[(3) - (4)].ival); i++) osoption->job->inputFilesToMove->pathPair[i] = new PathPair();
;}
    break;

  case 310:

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

  case 311:

    {	if (parserData->numberOfInputFilesToMove >= osoption->job->inputFilesToMove->numberOfPathPairs)
	{	osolerror (NULL, osoption, parserData, "too many path pairs in <inputFilesToMove> element");
	};
;}
    break;

  case 317:

    {	if (parserData->pathPairFromPresent)
	{	osolerror( NULL, osoption, parserData, "only one \"from\" attribute allowed");
	}
	else
	{	parserData->pathPairFromPresent = true;
		osoption->job->inputFilesToMove->pathPair[parserData->numberOfInputFilesToMove]->from = (yyvsp[(2) - (2)].sval);
	}
;}
    break;

  case 319:

    {	if (parserData->pathPairToPresent)
	{	osolerror( NULL, osoption, parserData, "only one \"to\" attribute allowed");
	}
	else
	{	parserData->pathPairToPresent = true;
		osoption->job->inputFilesToMove->pathPair[parserData->numberOfInputFilesToMove]->to = (yyvsp[(2) - (2)].sval);
	}
;}
    break;

  case 321:

    {	if (parserData->pathPairMakeCopyPresent)
	{	osolerror( NULL, osoption, parserData, "only one \"makeCopy\" attribute allowed");
	}
	else
	{	parserData->pathPairMakeCopyPresent = true;
		if ((yyvsp[(2) - (2)].sval) == "true")
			osoption->job->inputFilesToMove->pathPair[parserData->numberOfInputFilesToMove]->makeCopy = true;
	}
;}
    break;

  case 326:

    {	if (parserData->outputDirectoriesToMovePresent)
	{	osolerror( NULL, osoption, parserData, "only one <outputDirectoriesToMove> element allowed");
	}
	else
	{	parserData->outputDirectoriesToMovePresent = true;
		osoption->job->outputDirectoriesToMove = new PathPairs();
	}
;}
    break;

  case 327:

    {	if ((yyvsp[(3) - (4)].ival) <= 0)
		osolerror (NULL, osoption, parserData, "Require positive number of directories to move");
	osoption->job->outputDirectoriesToMove->numberOfPathPairs = (yyvsp[(3) - (4)].ival);
	osoption->job->outputDirectoriesToMove->pathPair = new PathPair*[(yyvsp[(3) - (4)].ival)];
	for (int i = 0; i < (yyvsp[(3) - (4)].ival); i++)
		osoption->job->outputDirectoriesToMove->pathPair[i] = new PathPair();
;}
    break;

  case 330:

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

  case 331:

    {	if (parserData->numberOfOutputDirectoriesToMove >= osoption->job->outputDirectoriesToMove->numberOfPathPairs)
	{	osolerror (NULL, osoption, parserData, "too many path pairs in <outputDirectoriesToMove> element");
	};
;}
    break;

  case 337:

    {	if (parserData->pathPairFromPresent)
	{	osolerror( NULL, osoption, parserData, "only one \"from\" attribute allowed");
	}
	else
	{	parserData->pathPairFromPresent = true;
		osoption->job->outputDirectoriesToMove->pathPair[parserData->numberOfOutputDirectoriesToMove]->from = (yyvsp[(2) - (2)].sval);
	}
;}
    break;

  case 339:

    {	if (parserData->pathPairToPresent)
	{	osolerror( NULL, osoption, parserData, "only one \"to\" attribute allowed");
	}
	else
	{	parserData->pathPairToPresent = true;
		osoption->job->outputDirectoriesToMove->pathPair[parserData->numberOfOutputDirectoriesToMove]->to = (yyvsp[(2) - (2)].sval);
	}
;}
    break;

  case 341:

    {	if (parserData->pathPairMakeCopyPresent)
	{	osolerror( NULL, osoption, parserData, "only one \"makeCopy\" attribute allowed");
	}
	else
	{	parserData->pathPairMakeCopyPresent = true;
		if ((yyvsp[(2) - (2)].sval) == "true")
			osoption->job->outputDirectoriesToMove->pathPair[parserData->numberOfOutputDirectoriesToMove]->makeCopy = true;
	}
;}
    break;

  case 346:

    {	if (parserData->outputFilesToMovePresent)
	{	osolerror( NULL, osoption, parserData, "only one <outputFilesToMove> element allowed");
	}
	else
	{	parserData->outputFilesToMovePresent = true;
		osoption->job->outputFilesToMove = new PathPairs();
	}
;}
    break;

  case 347:

    {	if ((yyvsp[(3) - (4)].ival) <= 0)
		osolerror (NULL, osoption, parserData, "Require positive number of files to move");
	osoption->job->outputFilesToMove->numberOfPathPairs = (yyvsp[(3) - (4)].ival);
	osoption->job->outputFilesToMove->pathPair = new PathPair*[(yyvsp[(3) - (4)].ival)];
	for (int i = 0; i < (yyvsp[(3) - (4)].ival); i++)
		osoption->job->outputFilesToMove->pathPair[i] = new PathPair();;}
    break;

  case 350:

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

  case 351:

    {	if (parserData->numberOfOutputFilesToMove >= osoption->job->outputFilesToMove->numberOfPathPairs)
	{	osolerror (NULL, osoption, parserData, "too many path pairs in <outputFilesToMove> element");
	};
;}
    break;

  case 357:

    {	if (parserData->pathPairFromPresent)
	{	osolerror( NULL, osoption, parserData, "only one \"from\" attribute allowed");
	}
	else
	{	parserData->pathPairFromPresent = true;
		osoption->job->outputFilesToMove->pathPair[parserData->numberOfOutputFilesToMove]->from = (yyvsp[(2) - (2)].sval);
	}
;}
    break;

  case 359:

    {	if (parserData->pathPairToPresent)
	{	osolerror( NULL, osoption, parserData, "only one \"to\" attribute allowed");
	}
	else
	{	parserData->pathPairToPresent = true;
		osoption->job->outputFilesToMove->pathPair[parserData->numberOfOutputFilesToMove]->to = (yyvsp[(2) - (2)].sval);
	}
;}
    break;

  case 361:

    {	if (parserData->pathPairMakeCopyPresent)
	{	osolerror( NULL, osoption, parserData, "only one \"makeCopy\" attribute allowed");
	}
	else
	{	parserData->pathPairMakeCopyPresent = true;
		if ((yyvsp[(2) - (2)].sval) == "true")
			osoption->job->outputFilesToMove->pathPair[parserData->numberOfOutputFilesToMove]->makeCopy = true;
	}
;}
    break;

  case 366:

    {	if (parserData->filesToDeletePresent)
	{	osolerror( NULL, osoption, parserData, "only one <filesToDelete> element allowed");
	}
	else
	{	parserData->filesToDeletePresent = true;
		osoption->job->filesToDelete = new DirectoriesAndFiles();
	}
;}
    break;

  case 367:

    {	if ((yyvsp[(3) - (4)].ival) < 1)
		osolerror( NULL, osoption, parserData, "Number of paths must be at least 1");
	osoption->job->filesToDelete->numberOfPaths = (yyvsp[(3) - (4)].ival);
	osoption->job->filesToDelete->path = new std::string[(yyvsp[(3) - (4)].ival)];
;}
    break;

  case 370:

    {	if (parserData->numberOfFilesToDelete >= osoption->job->filesToDelete->numberOfPaths)
	{	osolerror (NULL, osoption, parserData, "too many job IDs in <filesToDelete> element");
	}
	else
	{	osoption->job->filesToDelete->path[parserData->numberOfFilesToDelete] = (yyvsp[(3) - (3)].sval);
		parserData->numberOfFilesToDelete++;
	};
;}
    break;

  case 373:

    {	if (parserData->directoriesToDeletePresent)
	{	osolerror( NULL, osoption, parserData, "only one <directoriesToDelete> element allowed");
	}
	else
	{	parserData->directoriesToDeletePresent = true;
		osoption->job->directoriesToDelete = new DirectoriesAndFiles();
	}
;}
    break;

  case 374:

    {	if ((yyvsp[(3) - (4)].ival) < 1)
		osolerror( NULL, osoption, parserData, "Number of paths must be at least 1");
	osoption->job->directoriesToDelete->numberOfPaths = (yyvsp[(3) - (4)].ival);
	osoption->job->directoriesToDelete->path = new std::string[(yyvsp[(3) - (4)].ival)];
;}
    break;

  case 377:

    {	if (parserData->numberOfDirectoriesToDelete >= osoption->job->directoriesToDelete->numberOfPaths)
	{	osolerror (NULL, osoption, parserData, "too many job IDs in <directoriesToDelete> element");
	}
	else
	{	osoption->job->directoriesToDelete->path[parserData->numberOfDirectoriesToDelete] = (yyvsp[(3) - (3)].sval);
		parserData->numberOfDirectoriesToDelete++;
	};
;}
    break;

  case 380:

    {	if (parserData->processesToKillPresent)
	{	osolerror( NULL, osoption, parserData, "only one <processesToKill> element allowed");
	}
	else
	{	parserData->processesToKillPresent = true;
		osoption->job->processesToKill = new Processes();
	}
;}
    break;

  case 381:

    {	if ((yyvsp[(3) - (4)].ival) < 1)
		osolerror( NULL, osoption, parserData, "Number of job IDs must be at least 1");
	osoption->job->processesToKill->numberOfProcesses = (yyvsp[(3) - (4)].ival);
	osoption->job->processesToKill->process = new std::string[(yyvsp[(3) - (4)].ival)];
;}
    break;

  case 384:

    {	if (parserData->numberOfProcessesToKill >= osoption->job->processesToKill->numberOfProcesses)
	{	osolerror (NULL, osoption, parserData, "too many job IDs in <processesToKill> element");
	}
	else
	{	osoption->job->processesToKill->process[parserData->numberOfProcessesToKill] = (yyvsp[(3) - (3)].sval);
		parserData->numberOfProcessesToKill++;
	};
;}
    break;

  case 387:

    {	if (parserData->otherJobOptionsPresent)
	{	osolerror( NULL, osoption, parserData, "only one <otherOptions> element allowed");
	}
	else
	{	parserData->otherJobOptionsPresent = true;
		osoption->job->otherOptions = new OtherOptions();
	}
;}
    break;

  case 388:

    {	if ((yyvsp[(3) - (4)].ival) < 0)
		osolerror( NULL, osoption, parserData, "Number of <other> elements cannot be negative");
	osoption->job->otherOptions->numberOfOtherOptions = (yyvsp[(3) - (4)].ival);
	osoption->job->otherOptions->other = new OtherOption*[(yyvsp[(3) - (4)].ival)];
	for (int i=0; i < (yyvsp[(3) - (4)].ival); i++) osoption->job->otherOptions->other[i] = new OtherOption();
;}
    break;

  case 389:

    {	if (parserData->numberOfOtherJobOptions != osoption->job->otherOptions->numberOfOtherOptions)
		osolerror (NULL, osoption, parserData, "wrong number of other options in <job> element");
;}
    break;

  case 392:

    {	if (parserData->numberOfOtherJobOptions >= osoption->job->otherOptions->numberOfOtherOptions)
		{	osolerror (NULL, osoption, parserData, "too many other options in <job> element");
		};
	;}
    break;

  case 393:

    {	if (!parserData->otherOptionNamePresent)
		osolerror (NULL, osoption, parserData, "name attribute must be present");
	/* reset defaults for the next option */
	parserData->otherOptionNamePresent = false;
	parserData->otherOptionValuePresent = false;
	parserData->otherOptionDescriptionPresent = false;
	parserData->numberOfOtherJobOptions++;
;}
    break;

  case 399:

    {	if (parserData->otherOptionNamePresent)
	{	osolerror( NULL, osoption, parserData, "only one name attribute allowed");
	}
	else
	{	parserData->otherOptionNamePresent = true;
		osoption->job->otherOptions->other[parserData->numberOfOtherJobOptions]->name = (yyvsp[(2) - (2)].sval);
	}
;}
    break;

  case 401:

    {	if (parserData->otherOptionValuePresent)
	{	osolerror( NULL, osoption, parserData, "only one value attribute allowed");
	}
	else
	{	parserData->otherOptionValuePresent = true;
		osoption->job->otherOptions->other[parserData->numberOfOtherJobOptions]->value = (yyvsp[(2) - (2)].sval);
	}
;}
    break;

  case 403:

    {	if (parserData->otherOptionDescriptionPresent)
	{	osolerror( NULL, osoption, parserData, "only one description attribute allowed");
	}
	else
	{	parserData->otherOptionDescriptionPresent = true;
		osoption->job->otherOptions->other[parserData->numberOfOtherJobOptions]->description = (yyvsp[(2) - (2)].sval);
	}
;}
    break;

  case 409:

    {	if (parserData->osoloptimizationPresent)
	{	osolerror( NULL, osoption, parserData, "only one <optimization> element allowed");
	}
	else
	{	parserData->osoloptimizationPresent = true;
		osoption->optimization = new OptimizationOption();
	}
;}
    break;

  case 415:

    {	if ((yyvsp[(3) - (4)].ival) < 0)
		osolerror( NULL, osoption, parserData, "Number of variables cannot be negative");
	osoption->optimization->numberOfVariables = (yyvsp[(3) - (4)].ival);
;}
    break;

  case 416:

    {	if ((yyvsp[(3) - (4)].ival) < 0)
		osolerror( NULL, osoption, parserData, "Number of constraints cannot be negative");
	osoption->optimization->numberOfConstraints = (yyvsp[(3) - (4)].ival);
;}
    break;

  case 417:

    {	if ((yyvsp[(3) - (4)].ival) < 0)
		osolerror( NULL, osoption, parserData, "Number of objectives cannot be negative");
	osoption->optimization->numberOfObjectives = (yyvsp[(3) - (4)].ival);
;}
    break;

  case 423:

    {	osoption->optimization->variables = new VariableOption();
;}
    break;

  case 425:

    {	if ((yyvsp[(3) - (4)].ival) < 0)
		osolerror (NULL, osoption, parserData, "number of <other> variable options cannot be negative");
	osoption->optimization->variables->numberOfOtherVariableOptions = (yyvsp[(3) - (4)].ival);
	osoption->optimization->variables->other = new OtherVariableOption*[(yyvsp[(3) - (4)].ival)];
	for (int i= 0; i < (yyvsp[(3) - (4)].ival); i++)
		osoption->optimization->variables->other[i] = new OtherVariableOption();
;}
    break;

  case 430:

    {	if ((yyvsp[(3) - (4)].ival) <= 0)
		osolerror (NULL, osoption, parserData, "number of <var> elements must be positive");
	osoption->optimization->variables->initialVariableValues = new InitVariableValues();
	osoption->optimization->variables->initialVariableValues->numberOfVar = (yyvsp[(3) - (4)].ival);
	osoption->optimization->variables->initialVariableValues->var = new InitVarValue*[(yyvsp[(3) - (4)].ival)];
	for (int i = 0; i < (yyvsp[(3) - (4)].ival); i++)
		osoption->optimization->variables->initialVariableValues->var[i] = new InitVarValue();
;}
    break;

  case 433:

    {	if (!parserData->idxAttributePresent)
		osolerror (NULL, osoption, parserData, "variable index required");
	parserData->idxAttributePresent = false;
	parserData->valAttributePresent = false;
	parserData->numberOfVar++;
;}
    break;

  case 434:

    {	if (parserData->numberOfVar >= osoption->optimization->variables->initialVariableValues->numberOfVar)
		osolerror(NULL, osoption, parserData, "too many initial variable values");
;}
    break;

  case 439:

    {	if (parserData->idxAttributePresent)
		osolerror (NULL, osoption, parserData, "only one variable index allowed");
	parserData->idxAttributePresent = true;
	if ((yyvsp[(3) - (4)].ival) < 0)
		osolerror (NULL, osoption, parserData, "variable index must be nonnegative");
	if (parserData->numberOfVariablesPresent)
	{	if ((yyvsp[(3) - (4)].ival) >= parserData->numberOfVariables)
			osolerror (NULL, osoption, parserData, "variable index exceeds upper limit");
	};
	osoption->optimization->variables->initialVariableValues->var[parserData->numberOfVar]->idx = (yyvsp[(3) - (4)].ival);
;}
    break;

  case 440:

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

  case 446:

    {	if ((yyvsp[(3) - (4)].ival) <= 0)
		osolerror (NULL, osoption, parserData, "number of <var> elements must be positive");
	osoption->optimization->variables->initialVariableValuesString = new InitVariableValuesString ();
	osoption->optimization->variables->initialVariableValuesString->numberOfVar = (yyvsp[(3) - (4)].ival);
	osoption->optimization->variables->initialVariableValuesString->var = new InitVarValueString*[(yyvsp[(3) - (4)].ival)];
	for (int i = 0; i < (yyvsp[(3) - (4)].ival); i++)
		osoption->optimization->variables->initialVariableValuesString->var[i] = new InitVarValueString ();
;}
    break;

  case 449:

    {	if (!parserData->idxAttributePresent)
		osolerror (NULL, osoption, parserData, "variable index required");
	parserData->idxAttributePresent = false;
	parserData->valAttributePresent = false;
	parserData->numberOfVarStr++;
;}
    break;

  case 450:

    {	if (parserData->numberOfVarStr >= osoption->optimization->variables->initialVariableValuesString->numberOfVar)
		osolerror(NULL, osoption, parserData, "too many initial variable strings");
;}
    break;

  case 455:

    {	if (parserData->idxAttributePresent)
		osolerror (NULL, osoption, parserData, "only one variable index allowed");
	parserData->idxAttributePresent = true;
	if ((yyvsp[(3) - (4)].ival) < 0)
		osolerror (NULL, osoption, parserData, "variable index must be nonnegative");
	if (parserData->numberOfVariablesPresent)
	{	if ((yyvsp[(3) - (4)].ival) >= parserData->numberOfVariables)
			osolerror (NULL, osoption, parserData, "variable index exceeds upper limit");
	};
	osoption->optimization->variables->initialVariableValuesString->var[parserData->numberOfVarStr]->idx = (yyvsp[(3) - (4)].ival);
;}
    break;

  case 456:

    {	if (parserData->valAttributePresent)
		osolerror (NULL, osoption, parserData, "only one variable string value allowed");
	parserData->valAttributePresent = true;
	osoption->optimization->variables->initialVariableValuesString->var[parserData->numberOfVarStr]->value = (yyvsp[(2) - (2)].sval);
;}
    break;

  case 462:

    {	if ((yyvsp[(3) - (4)].ival) <= 0)
		osolerror (NULL, osoption, parserData, "number of <var> elements must be positive");
	osoption->optimization->variables->initialBasisStatus = new InitialBasisStatus ();
	osoption->optimization->variables->initialBasisStatus->numberOfVar = (yyvsp[(3) - (4)].ival);
	osoption->optimization->variables->initialBasisStatus->var = new InitBasStatus*[(yyvsp[(3) - (4)].ival)];
	for (int i = 0; i < (yyvsp[(3) - (4)].ival); i++)
		osoption->optimization->variables->initialBasisStatus->var[i] = new InitBasStatus();
;}
    break;

  case 465:

    {	if (!parserData->idxAttributePresent)
		osolerror (NULL, osoption, parserData, "variable index required");
	parserData->idxAttributePresent = false;
	parserData->valAttributePresent = false;
	parserData->numberOfVarStr++;
;}
    break;

  case 466:

    {	if (parserData->numberOfVarStr >= osoption->optimization->variables->initialBasisStatus->numberOfVar)
		osolerror(NULL, osoption, parserData, "too many initial variable strings");
;}
    break;

  case 471:

    {	if (parserData->idxAttributePresent)
		osolerror (NULL, osoption, parserData, "only one variable index allowed");
	parserData->idxAttributePresent = true;
	if ((yyvsp[(3) - (4)].ival) < 0)
		osolerror (NULL, osoption, parserData, "variable index must be nonnegative");
	if (parserData->numberOfVariablesPresent)
	{	if ((yyvsp[(3) - (4)].ival) >= parserData->numberOfVariables)
			osolerror (NULL, osoption, parserData, "variable index exceeds upper limit");
	};
	osoption->optimization->variables->initialBasisStatus->var[parserData->numberOfBasVar]->idx = (yyvsp[(3) - (4)].ival);
;}
    break;

  case 472:

    {	if (parserData->valAttributePresent)
		osolerror (NULL, osoption, parserData, "only one variable value allowed");
	parserData->valAttributePresent = true;
	osoption->optimization->variables->initialBasisStatus->var[parserData->numberOfBasVar]->value = (yyvsp[(2) - (2)].sval);
;}
    break;

  case 479:

    {	if (parserData->numberOfOtherVariableOptions >= osoption->optimization->variables->numberOfOtherVariableOptions)
		osolerror(NULL, osoption, parserData, "too many <other> variable options");
;}
    break;

  case 489:

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

  case 490:

    {	if (parserData->otherOptionNamePresent)
		osolerror (NULL, osoption, parserData, "only one name attribute allowed");
	parserData->otherOptionNamePresent = true;
	osoption->optimization->variables->other[parserData->numberOfOtherVariableOptions]->name = (yyvsp[(2) - (2)].sval);
;}
    break;

  case 492:

    {	if (parserData->otherOptionValuePresent)
		osolerror (NULL, osoption, parserData, "only one value attribute allowed");
	parserData->otherOptionValuePresent = true;
	osoption->optimization->variables->other[parserData->numberOfOtherVariableOptions]->value = (yyvsp[(2) - (2)].sval);
;}
    break;

  case 494:

    {	if (parserData->otherOptionSolverPresent)
		osolerror (NULL, osoption, parserData, "only one solver attribute allowed");
	parserData->otherOptionSolverPresent = true;
	osoption->optimization->variables->other[parserData->numberOfOtherVariableOptions]->solver = (yyvsp[(2) - (2)].sval);
;}
    break;

  case 496:

    {	if (parserData->otherOptionCategoryPresent)
		osolerror (NULL, osoption, parserData, "only one category attribute allowed");
	parserData->otherOptionCategoryPresent = true;
	osoption->optimization->variables->other[parserData->numberOfOtherVariableOptions]->category = (yyvsp[(2) - (2)].sval);
;}
    break;

  case 498:

    {	if (parserData->otherOptionTypePresent)
		osolerror (NULL, osoption, parserData, "only one type attribute allowed");
	parserData->otherOptionTypePresent = true;
	osoption->optimization->variables->other[parserData->numberOfOtherVariableOptions]->type = (yyvsp[(2) - (2)].sval);
;}
    break;

  case 500:

    {	if (parserData->otherOptionDescriptionPresent)
		osolerror (NULL, osoption, parserData, "only one description attribute allowed");
	parserData->otherOptionDescriptionPresent = true;
	osoption->optimization->variables->other[parserData->numberOfOtherVariableOptions]->description = (yyvsp[(2) - (2)].sval);
;}
    break;

  case 502:

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

  case 505:

    {	if (!parserData->idxAttributePresent)
		osolerror(NULL, osoption, parserData, "required idx attribute was not found");
	parserData->idxAttributePresent = false;
	parserData->valAttributePresent = false;
	parserData->lbvalAttributePresent = false;
	parserData->ubvalAttributePresent = false;
	parserData->numberOfVar++;
;}
    break;

  case 506:

    {	if (parserData->numberOfVar >= osoption->optimization->variables->other[parserData->numberOfOtherVariableOptions]->numberOfVar)
		osolerror(NULL, osoption, parserData, "too many <var> entries in <other> variable element");
;}
    break;

  case 513:

    {	if (parserData->idxAttributePresent)
		osolerror (NULL, osoption, parserData, "only one variable index allowed");
	parserData->idxAttributePresent = true;
	if ((yyvsp[(3) - (4)].ival) < 0)
		osolerror (NULL, osoption, parserData, "variable index must be nonnegative");
	if (parserData->numberOfVariablesPresent)
	{	if ((yyvsp[(3) - (4)].ival) >= parserData->numberOfVariables)
			osolerror (NULL, osoption, parserData, "variable index exceeds upper limit");
	};
	osoption->optimization->variables->other[parserData->numberOfOtherVariableOptions]->var[parserData->numberOfVar]->idx = (yyvsp[(3) - (4)].ival);
;}
    break;

  case 514:

    {	if (parserData->valAttributePresent)
		osolerror (NULL, osoption, parserData, "only one variable value allowed");
	parserData->valAttributePresent = true;
	osoption->optimization->variables-> other[parserData->numberOfOtherVariableOptions]->var[parserData->numberOfVar]->value = (yyvsp[(2) - (2)].sval);
;}
    break;

  case 516:

    {	if (parserData->lbvalAttributePresent)
		osolerror (NULL, osoption, parserData, "only one lower bound value allowed");
	parserData->lbvalAttributePresent = true;
	osoption->optimization->variables-> other[parserData->numberOfOtherVariableOptions]->var[parserData->numberOfVar]->lbValue = (yyvsp[(2) - (2)].sval);
;}
    break;

  case 518:

    {	if (parserData->ubvalAttributePresent)
		osolerror (NULL, osoption, parserData, "only one upper bound value allowed");
	parserData->ubvalAttributePresent = true;
	osoption->optimization->variables-> other[parserData->numberOfOtherVariableOptions]->var[parserData->numberOfVar]->ubValue = (yyvsp[(2) - (2)].sval);
;}
    break;

  case 524:

    {	osoption->optimization->objectives = new ObjectiveOption();
;}
    break;

  case 526:

    {	if ((yyvsp[(3) - (4)].ival) < 0)
		osolerror (NULL, osoption, parserData, "number of <other> objective options cannot be negative");
	osoption->optimization->objectives->numberOfOtherObjectiveOptions = (yyvsp[(3) - (4)].ival);
	osoption->optimization->objectives->other = new OtherObjectiveOption*[(yyvsp[(3) - (4)].ival)];
	for (int i= 0; i < (yyvsp[(3) - (4)].ival); i++)
		osoption->optimization->objectives->other[i] = new OtherObjectiveOption();
;}
    break;

  case 531:

    {	if ((yyvsp[(3) - (4)].ival) <= 0)
		osolerror (NULL, osoption, parserData, "number of <obj> elements must be positive");
	osoption->optimization->objectives->initialObjectiveValues = new InitObjectiveValues();
	osoption->optimization->objectives->initialObjectiveValues->numberOfObj = (yyvsp[(3) - (4)].ival);
	osoption->optimization->objectives->initialObjectiveValues->obj = new InitObjValue*[(yyvsp[(3) - (4)].ival)];
	for (int i = 0; i < (yyvsp[(3) - (4)].ival); i++)
		osoption->optimization->objectives->initialObjectiveValues->obj[i] = new InitObjValue();
;}
    break;

  case 534:

    {	if (!parserData->idxAttributePresent)
		osolerror (NULL, osoption, parserData, "objective index required");
	parserData->idxAttributePresent = false;
	parserData->valAttributePresent = false;
	parserData->numberOfObjValues++;
;}
    break;

  case 535:

    {	if (parserData->numberOfObjValues >= osoption->optimization->objectives->initialObjectiveValues->numberOfObj)
		osolerror(NULL, osoption, parserData, "too many initial objective values");
;}
    break;

  case 540:

    {	if (parserData->idxAttributePresent)
		osolerror (NULL, osoption, parserData, "only one objective index allowed");
	parserData->idxAttributePresent = true;
	if ((yyvsp[(3) - (4)].ival) >= 0)
		osolerror (NULL, osoption, parserData, "objective index must be negative");
	if (parserData->numberOfObjectivesPresent)
	{	if (-(yyvsp[(3) - (4)].ival) > parserData->numberOfObjectives)
			osolerror (NULL, osoption, parserData, "objective index out of range");
	};
	osoption->optimization->objectives->initialObjectiveValues->obj[parserData->numberOfObjValues]->idx = (yyvsp[(3) - (4)].ival);
;}
    break;

  case 541:

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

  case 547:

    {	if ((yyvsp[(3) - (4)].ival) <= 0)
		osolerror (NULL, osoption, parserData, "number of <obj> elements must be positive");
	osoption->optimization->objectives->initialObjectiveBounds = new InitObjectiveBounds();
	osoption->optimization->objectives->initialObjectiveBounds->numberOfObj = (yyvsp[(3) - (4)].ival);
	osoption->optimization->objectives->initialObjectiveBounds->obj = new InitObjBound*[(yyvsp[(3) - (4)].ival)];
	for (int i = 0; i < (yyvsp[(3) - (4)].ival); i++)
		osoption->optimization->objectives->initialObjectiveBounds->obj[i] = new InitObjBound ();
;}
    break;

  case 550:

    {	if (!parserData->idxAttributePresent)
		osolerror (NULL, osoption, parserData, "objective index required");
	parserData->idxAttributePresent = false;
	parserData->lbvalAttributePresent = false;
	parserData->ubvalAttributePresent = false;
	parserData->numberOfObjBounds++;
;}
    break;

  case 551:

    {	if (parserData->numberOfObjBounds >= osoption->optimization->objectives->initialObjectiveBounds->numberOfObj)
		osolerror(NULL, osoption, parserData, "too many initial objective bounds");
;}
    break;

  case 557:

    {	if (parserData->idxAttributePresent)
		osolerror (NULL, osoption, parserData, "only one objective index allowed");
	parserData->idxAttributePresent = true;
	if ((yyvsp[(3) - (4)].ival) >= 0)
		osolerror (NULL, osoption, parserData, "objective index must be negative");
	if (parserData->numberOfObjectivesPresent)
	{	if (-(yyvsp[(3) - (4)].ival) > parserData->numberOfObjectives)
			osolerror (NULL, osoption, parserData, "objective index out of range");
	};
	osoption->optimization->objectives->initialObjectiveBounds->obj[parserData->numberOfObjBounds]->idx = (yyvsp[(3) - (4)].ival);
;}
    break;

  case 558:

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

  case 560:

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

  case 567:

    {	if (parserData->numberOfOtherObjectiveOptions >= osoption->optimization->objectives->numberOfOtherObjectiveOptions)
		osolerror(NULL, osoption, parserData, "too many <other> objective options");
;}
    break;

  case 577:

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

  case 578:

    {	if (parserData->otherOptionNamePresent)
		osolerror (NULL, osoption, parserData, "only one name attribute allowed");
	parserData->otherOptionNamePresent = true;
	osoption->optimization->objectives->other[parserData->numberOfOtherObjectiveOptions]->name = (yyvsp[(2) - (2)].sval);
;}
    break;

  case 580:

    {	if (parserData->otherOptionValuePresent)
		osolerror (NULL, osoption, parserData, "only one value attribute allowed");
	parserData->otherOptionValuePresent = true;
	osoption->optimization->objectives->other[parserData->numberOfOtherObjectiveOptions]->value = (yyvsp[(2) - (2)].sval);
;}
    break;

  case 582:

    {	if (parserData->otherOptionSolverPresent)
		osolerror (NULL, osoption, parserData, "only one solver attribute allowed");
	parserData->otherOptionSolverPresent = true;
	osoption->optimization->objectives->other[parserData->numberOfOtherObjectiveOptions]->solver = (yyvsp[(2) - (2)].sval);
;}
    break;

  case 584:

    {	if (parserData->otherOptionCategoryPresent)
		osolerror (NULL, osoption, parserData, "only one category attribute allowed");
	parserData->otherOptionCategoryPresent = true;
	osoption->optimization->objectives->other[parserData->numberOfOtherObjectiveOptions]->category = (yyvsp[(2) - (2)].sval);
;}
    break;

  case 586:

    {	if (parserData->otherOptionTypePresent)
		osolerror (NULL, osoption, parserData, "only one type attribute allowed");
	parserData->otherOptionTypePresent = true;
	osoption->optimization->objectives->other[parserData->numberOfOtherObjectiveOptions]->type = (yyvsp[(2) - (2)].sval);
;}
    break;

  case 588:

    {	if (parserData->otherOptionDescriptionPresent)
		osolerror (NULL, osoption, parserData, "only one description attribute allowed");
	parserData->otherOptionDescriptionPresent = true;
	osoption->optimization->objectives->other[parserData->numberOfOtherObjectiveOptions]->description = (yyvsp[(2) - (2)].sval);
;}
    break;

  case 590:

    { 	if (parserData->numberOfVar < osoption->optimization->objectives->other[parserData->numberOfOtherObjectiveOptions]->numberOfObj)
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

  case 593:

    {	if (!parserData->idxAttributePresent)
		osolerror(NULL, osoption, parserData, "required idx attribute was not found");
	parserData->idxAttributePresent = false;
	parserData->valAttributePresent = false;
	parserData->lbvalAttributePresent = false;
	parserData->ubvalAttributePresent = false;
	parserData->numberOfObj++;
;}
    break;

  case 594:

    {	if (parserData->numberOfObj >= osoption->optimization->objectives->other[parserData->numberOfOtherObjectiveOptions]->numberOfObj)
		osolerror(NULL, osoption, parserData, "too many <obj> entries in <other> objective element");
;}
    break;

  case 601:

    {	if (parserData->idxAttributePresent)
		osolerror (NULL, osoption, parserData, "only one objective index allowed");
	parserData->idxAttributePresent = true;
	if ((yyvsp[(3) - (4)].ival) >= 0)
		osolerror (NULL, osoption, parserData, "objective index must be negative");
	if (parserData->numberOfObjectivesPresent)
	{	if (-(yyvsp[(3) - (4)].ival) > parserData->numberOfObjectives)
			osolerror (NULL, osoption, parserData, "objecive index exceeds upper limit");
	};
	osoption->optimization->objectives->other[parserData->numberOfOtherObjectiveOptions]->obj[parserData->numberOfObj]->idx = (yyvsp[(3) - (4)].ival);
;}
    break;

  case 602:

    {	if (parserData->valAttributePresent)
		osolerror (NULL, osoption, parserData, "only one variable value allowed");
	parserData->valAttributePresent = true;
	osoption->optimization->objectives-> other[parserData->numberOfOtherObjectiveOptions]->obj[parserData->numberOfObj]->value = (yyvsp[(2) - (2)].sval);
;}
    break;

  case 604:

    {	if (parserData->lbvalAttributePresent)
		osolerror (NULL, osoption, parserData, "only one lower bound value allowed");
	parserData->lbvalAttributePresent = true;
	osoption->optimization->objectives-> other[parserData->numberOfOtherObjectiveOptions]->obj[parserData->numberOfObj]->lbValue = (yyvsp[(2) - (2)].sval);
;}
    break;

  case 606:

    {	if (parserData->ubvalAttributePresent)
		osolerror (NULL, osoption, parserData, "only one upper bound value allowed");
	parserData->ubvalAttributePresent = true;
	osoption->optimization->objectives-> other[parserData->numberOfOtherObjectiveOptions]->obj[parserData->numberOfObj]->ubValue = (yyvsp[(2) - (2)].sval);
;}
    break;

  case 612:

    {	osoption->optimization->constraints = new ConstraintOption();
;}
    break;

  case 614:

    {	if ((yyvsp[(3) - (4)].ival) < 0)
		osolerror (NULL, osoption, parserData, "number of <other> constraint options cannot be negative");
        osoption->optimization->constraints->numberOfOtherConstraintOptions = (yyvsp[(3) - (4)].ival);
	osoption->optimization->constraints->other = new OtherConstraintOption*[(yyvsp[(3) - (4)].ival)];
	for (int i= 0; i < (yyvsp[(3) - (4)].ival); i++)
		osoption->optimization->constraints->other[i] = new OtherConstraintOption();
;}
    break;

  case 619:

    {	if ((yyvsp[(3) - (4)].ival) <= 0)
		osolerror (NULL, osoption, parserData, "number of <con> elements must be positive");
	osoption->optimization->constraints->initialConstraintValues = new InitConstraintValues();
	osoption->optimization->constraints->initialConstraintValues->numberOfCon = (yyvsp[(3) - (4)].ival);
	osoption->optimization->constraints->initialConstraintValues->con = new InitConValue*[(yyvsp[(3) - (4)].ival)];
	for (int i = 0; i < (yyvsp[(3) - (4)].ival); i++)
		osoption->optimization->constraints->initialConstraintValues->con[i] = new InitConValue();
;}
    break;

  case 622:

    {	if (!parserData->idxAttributePresent)
		osolerror (NULL, osoption, parserData, "variable index required");
	parserData->idxAttributePresent = false;
	parserData->valAttributePresent = false;
	parserData->numberOfCon++;
;}
    break;

  case 623:

    {	if (parserData->numberOfCon >= osoption->optimization->constraints->initialConstraintValues->numberOfCon)
		osolerror(NULL, osoption, parserData, "too many initial constraint values");
;}
    break;

  case 628:

    {	if (parserData->idxAttributePresent)
		osolerror (NULL, osoption, parserData, "only one constraint index allowed");
	parserData->idxAttributePresent = true;
	if ((yyvsp[(3) - (4)].ival) < 0)
		osolerror (NULL, osoption, parserData, "constraint index must be nonnegative");
	if (parserData->numberOfConstraintsPresent)
	{	if ((yyvsp[(3) - (4)].ival) > parserData->numberOfConstraints)
			osolerror (NULL, osoption, parserData, "constraint index out of range");
	};
	osoption->optimization->constraints->initialConstraintValues->con[parserData->numberOfCon]->idx = (yyvsp[(3) - (4)].ival);
;}
    break;

  case 629:

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

  case 635:

    {	if ((yyvsp[(3) - (4)].ival) <= 0)
		osolerror (NULL, osoption, parserData, "number of <con> elements must be positive");
	osoption->optimization->constraints->initialDualValues = new InitDualVariableValues();
	osoption->optimization->constraints->initialDualValues->numberOfCon = (yyvsp[(3) - (4)].ival);
	osoption->optimization->constraints->initialDualValues->con = new InitDualVarValue*[(yyvsp[(3) - (4)].ival)];
	for (int i = 0; i < (yyvsp[(3) - (4)].ival); i++)
		osoption->optimization->constraints->initialDualValues->con[i] = new InitDualVarValue ();
;}
    break;

  case 638:

    {	if (!parserData->idxAttributePresent)
		osolerror (NULL, osoption, parserData, "constraint index required");
	parserData->idxAttributePresent = false;
	parserData->lbvalAttributePresent = false;
	parserData->ubvalAttributePresent = false;
	parserData->numberOfDuals++;
;}
    break;

  case 639:

    {	if (parserData->numberOfDuals >= osoption->optimization->constraints->initialDualValues->numberOfCon)
		osolerror(NULL, osoption, parserData, "too many initial dual variable bounds");
;}
    break;

  case 645:

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

  case 646:

    {	if (parserData->lbvalAttributePresent)
		osolerror (NULL, osoption, parserData, "only one dual variable lower bound allowed");
	parserData->lbvalAttributePresent = true;
	if (strcmp((yyvsp[(2) - (2)].sval),"INF") == 0)
		osoption->optimization->constraints->initialDualValues->con[parserData->numberOfDuals]->lbValue = OSDBL_MAX;
	else if (strcmp((yyvsp[(2) - (2)].sval),"-INF") == 0)
		osoption->optimization->constraints->initialDualValues->con[parserData->numberOfDuals]->lbValue = -OSDBL_MAX;
	else
		osoption->optimization->constraints->initialDualValues->con[parserData->numberOfDuals]->lbValue = os_strtod((yyvsp[(2) - (2)].sval), NULL);
;}
    break;

  case 648:

    {	if (parserData->ubvalAttributePresent)
		osolerror (NULL, osoption, parserData, "only one dual variable upper bound allowed");
	parserData->ubvalAttributePresent = true;
	if (strcmp((yyvsp[(2) - (2)].sval),"INF") == 0)
		osoption->optimization->constraints->initialDualValues->con[parserData->numberOfDuals]->ubValue = OSDBL_MAX;
	else if (strcmp((yyvsp[(2) - (2)].sval),"-INF") == 0)
		osoption->optimization->constraints->initialDualValues->con[parserData->numberOfDuals]->ubValue = -OSDBL_MAX;
	else
		osoption->optimization->constraints->initialDualValues->con[parserData->numberOfDuals]->ubValue = os_strtod((yyvsp[(2) - (2)].sval), NULL);
;}
    break;

  case 655:

    {	if (parserData->numberOfOtherConstraintOptions >= osoption->optimization->constraints->numberOfOtherConstraintOptions)
		osolerror(NULL, osoption, parserData, "too many <other> constraint options");
;}
    break;

  case 665:

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

  case 666:

    {	if (parserData->otherOptionNamePresent)
		osolerror (NULL, osoption, parserData, "only one name attribute allowed");
	parserData->otherOptionNamePresent = true;
	osoption->optimization->constraints->other[parserData->numberOfOtherConstraintOptions]->name = (yyvsp[(2) - (2)].sval);
;}
    break;

  case 668:

    {	if (parserData->otherOptionValuePresent)
		osolerror (NULL, osoption, parserData, "only one value attribute allowed");
	parserData->otherOptionValuePresent = true;
	osoption->optimization->constraints->other[parserData->numberOfOtherConstraintOptions]->value = (yyvsp[(2) - (2)].sval);
;}
    break;

  case 670:

    {	if (parserData->otherOptionSolverPresent)
		osolerror (NULL, osoption, parserData, "only one solver attribute allowed");
	parserData->otherOptionSolverPresent = true;
	osoption->optimization->constraints->other[parserData->numberOfOtherConstraintOptions]->solver = (yyvsp[(2) - (2)].sval);
;}
    break;

  case 672:

    {	if (parserData->otherOptionCategoryPresent)
		osolerror (NULL, osoption, parserData, "only one category attribute allowed");
	parserData->otherOptionCategoryPresent = true;
	osoption->optimization->constraints->other[parserData->numberOfOtherConstraintOptions]->category = (yyvsp[(2) - (2)].sval);
;}
    break;

  case 674:

    {	if (parserData->otherOptionTypePresent)
		osolerror (NULL, osoption, parserData, "only one type attribute allowed");
	parserData->otherOptionTypePresent = true;
	osoption->optimization->constraints->other[parserData->numberOfOtherConstraintOptions]->type = (yyvsp[(2) - (2)].sval);
;}
    break;

  case 676:

    {	if (parserData->otherOptionDescriptionPresent)
		osolerror (NULL, osoption, parserData, "only one description attribute allowed");
	parserData->otherOptionDescriptionPresent = true;
	osoption->optimization->constraints->other[parserData->numberOfOtherConstraintOptions]->description = (yyvsp[(2) - (2)].sval);
;}
    break;

  case 678:

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

  case 681:

    {	if (!parserData->idxAttributePresent)
		osolerror(NULL, osoption, parserData, "required idx attribute was not found");
	parserData->idxAttributePresent = false;
	parserData->valAttributePresent = false;
	parserData->lbvalAttributePresent = false;
	parserData->ubvalAttributePresent = false;
	parserData->numberOfCon++;
;}
    break;

  case 682:

    {	if (parserData->numberOfVar >= osoption->optimization->variables->other[parserData->numberOfOtherVariableOptions]->numberOfVar)
		osolerror(NULL, osoption, parserData, "too many <var> entries in <other> variable element");
;}
    break;

  case 689:

    {	if (parserData->idxAttributePresent)
		osolerror (NULL, osoption, parserData, "only one constraint index allowed");
	parserData->idxAttributePresent = true;
	if ((yyvsp[(3) - (4)].ival) < 0)
		osolerror (NULL, osoption, parserData, "constraint index must be nonnegative");
	if (parserData->numberOfConstraintsPresent)
	{	if ((yyvsp[(3) - (4)].ival) >= parserData->numberOfConstraints)
			osolerror (NULL, osoption, parserData, "constraint index exceeds upper limit");
	};
	osoption->optimization->constraints->other[parserData->numberOfOtherConstraintOptions]->con[parserData->numberOfCon]->idx = (yyvsp[(3) - (4)].ival);
;}
    break;

  case 690:

    {	if (parserData->valAttributePresent)
		osolerror (NULL, osoption, parserData, "only one constraint value allowed");
	parserData->valAttributePresent = true;
	osoption->optimization->constraints-> other[parserData->numberOfOtherConstraintOptions]->con[parserData->numberOfCon]->value = (yyvsp[(2) - (2)].sval);
;}
    break;

  case 692:

    {	if (parserData->lbvalAttributePresent)
		osolerror (NULL, osoption, parserData, "only one lower bound value allowed");
	parserData->lbvalAttributePresent = true;
	osoption->optimization->constraints-> other[parserData->numberOfOtherConstraintOptions]->con[parserData->numberOfCon]->lbValue = (yyvsp[(2) - (2)].sval);
;}
    break;

  case 694:

    {	if (parserData->ubvalAttributePresent)
		osolerror (NULL, osoption, parserData, "only one upper bound value allowed");
	parserData->ubvalAttributePresent = true;
	osoption->optimization->constraints-> other[parserData->numberOfOtherConstraintOptions]->con[parserData->numberOfCon]->ubValue = (yyvsp[(2) - (2)].sval);
;}
    break;

  case 699:

    {	if (parserData->numberOfSolverOptions != osoption->optimization->solverOptions->numberOfSolverOptions)
		osolerror (NULL, osoption, parserData, "wrong number of solver options in <optimization> element");
;}
    break;

  case 700:

    {	if (parserData->solverOptionsPresent)
	{	osolerror( NULL, osoption, parserData, "only one <solverOptions> element allowed");
	}
	else
	{	parserData->solverOptionsPresent = true;
		osoption->optimization->solverOptions = new SolverOptions();
	}
;}
    break;

  case 701:

    {	if ((yyvsp[(3) - (4)].ival) < 0)
		osolerror (NULL, osoption, parserData, "number of solver options cannot be negative");
	osoption->optimization->solverOptions->numberOfSolverOptions = (yyvsp[(3) - (4)].ival);
	osoption->optimization->solverOptions->solverOption = new SolverOption*[(yyvsp[(3) - (4)].ival)];
	for (int i=0; i < (yyvsp[(3) - (4)].ival); i++) osoption->optimization->solverOptions->solverOption[i] = new SolverOption();
;}
    break;

  case 704:

    {	if (parserData->numberOfSolverOptions >= osoption->optimization->solverOptions->numberOfSolverOptions)
	{	osolerror (NULL, osoption, parserData, "too many solver options in <optimization> element");
	};
;}
    break;

  case 705:

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

  case 714:

    {	if (parserData->solverOptionNamePresent)
	{	osolerror( NULL, osoption, parserData, "only one name attribute allowed");
	}
	else
	{	parserData->solverOptionNamePresent = true;
		osoption->optimization->solverOptions->solverOption[parserData->numberOfSolverOptions]->name = (yyvsp[(2) - (2)].sval);
	}
;}
    break;

  case 716:

    {	if (parserData->solverOptionValuePresent)
	{	osolerror( NULL, osoption, parserData, "only one value attribute allowed");
	}
	else
	{	parserData->solverOptionValuePresent = true;
		osoption->optimization->solverOptions->solverOption[parserData->numberOfSolverOptions]->value = (yyvsp[(2) - (2)].sval);
	}
;}
    break;

  case 718:

    {	if (parserData->solverOptionSolverPresent)
	{	osolerror( NULL, osoption, parserData, "only one solver attribute allowed");
	}
	else
	{	parserData->solverOptionSolverPresent = true;
		osoption->optimization->solverOptions->solverOption[parserData->numberOfSolverOptions]->solver = (yyvsp[(2) - (2)].sval);
	}
;}
    break;

  case 720:

    {	if (parserData->solverOptionCategoryPresent)
	{	osolerror( NULL, osoption, parserData, "only one category attribute allowed");
	}
	else
	{	parserData->solverOptionCategoryPresent = true;
		osoption->optimization->solverOptions->solverOption[parserData->numberOfSolverOptions]->category = (yyvsp[(2) - (2)].sval);
	}
;}
    break;

  case 722:

    {	if (parserData->solverOptionTypePresent)
	{	osolerror( NULL, osoption, parserData, "only one type attribute allowed");
	}
	else
	{	parserData->solverOptionTypePresent = true;
		osoption->optimization->solverOptions->solverOption[parserData->numberOfSolverOptions]->type = (yyvsp[(2) - (2)].sval);
	}
;}
    break;

  case 724:

    {	if (parserData->solverOptionNamePresent)
	{	osolerror( NULL, osoption, parserData, "only one name attribute allowed");
	}
	else
	{	parserData->solverOptionNamePresent = true;
		osoption->optimization->solverOptions->solverOption[parserData->numberOfSolverOptions]->name = (yyvsp[(2) - (2)].sval);
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


