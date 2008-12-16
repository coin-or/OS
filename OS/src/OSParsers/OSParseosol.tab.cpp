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
     GROUPWEIGHTATT = 280,
     NUMBEROFPROCESSESATT = 281,
     NUMBEROFSOLVEROPTIONSATT = 282,
     NUMBEROFSOSATT = 283,
     NUMBEROFVARIABLESATT = 284,
     NUMBEROFOBJECTIVESATT = 285,
     NUMBEROFCONSTRAINTSATT = 286,
     NUMBEROFOTHERVARIABLEOPTIONSATT = 287,
     NUMBEROFOTHEROBJECTIVEOPTIONSATT = 288,
     NUMBEROFOTHERCONSTRAINTOPTIONSATT = 289,
     NUMBEROFVARATT = 290,
     NUMBEROFOBJATT = 291,
     NUMBEROFCONATT = 292,
     NAMEATT = 293,
     IDXATT = 294,
     SOSIDXATT = 295,
     VALUEATT = 296,
     UNITATT = 297,
     DESCRIPTIONATT = 298,
     LBVALUEATT = 299,
     UBVALUEATT = 300,
     GENERALSTART = 301,
     GENERALEND = 302,
     SYSTEMSTART = 303,
     SYSTEMEND = 304,
     SERVICESTART = 305,
     SERVICEEND = 306,
     JOBSTART = 307,
     JOBEND = 308,
     OPTIMIZATIONSTART = 309,
     OPTIMIZATIONEND = 310,
     SERVICEURISTART = 311,
     SERVICEURIEND = 312,
     SERVICENAMESTART = 313,
     SERVICENAMEEND = 314,
     INSTANCENAMESTART = 315,
     INSTANCENAMEEND = 316,
     INSTANCELOCATIONSTART = 317,
     INSTANCELOCATIONEND = 318,
     JOBIDSTART = 319,
     JOBIDEND = 320,
     SOLVERTOINVOKESTART = 321,
     SOLVERTOINVOKEEND = 322,
     LICENSESTART = 323,
     LICENSEEND = 324,
     USERNAMESTART = 325,
     USERNAMEEND = 326,
     PASSWORDSTART = 327,
     PASSWORDEND = 328,
     CONTACTSTART = 329,
     CONTACTEND = 330,
     OTHEROPTIONSSTART = 331,
     OTHEROPTIONSEND = 332,
     OTHERSTART = 333,
     OTHEREND = 334,
     MINDISKSPACESTART = 335,
     MINDISKSPACEEND = 336,
     MINMEMORYSIZESTART = 337,
     MINMEMORYSIZEEND = 338,
     MINCPUSPEEDSTART = 339,
     MINCPUSPEEDEND = 340,
     MINCPUNUMBERSTART = 341,
     MINCPUNUMBEREND = 342,
     SERVICETYPESTART = 343,
     SERVICETYPEEND = 344,
     MAXTIMESTART = 345,
     MAXTIMEEND = 346,
     SCHEDULEDSTARTTIMESTART = 347,
     SCHEDULEDSTARTTIMEEND = 348,
     DEPENDENCIESSTART = 349,
     DEPENDENCIESEND = 350,
     REQUIREDDIRECTORIESSTART = 351,
     REQUIREDDIRECTORIESEND = 352,
     REQUIREDFILESSTART = 353,
     REQUIREDFILESEND = 354,
     PATHSTART = 355,
     PATHEND = 356,
     PATHPAIRSTART = 357,
     PATHPAIREND = 358,
     DIRECTORIESTOMAKESTART = 359,
     DIRECTORIESTOMAKEEND = 360,
     FILESTOMAKESTART = 361,
     FILESTOMAKEEND = 362,
     DIRECTORIESTODELETESTART = 363,
     DIRECTORIESTODELETEEND = 364,
     FILESTODELETESTART = 365,
     FILESTODELETEEND = 366,
     INPUTDIRECTORIESTOMOVESTART = 367,
     INPUTDIRECTORIESTOMOVEEND = 368,
     INPUTFILESTOMOVESTART = 369,
     INPUTFILESTOMOVEEND = 370,
     OUTPUTDIRECTORIESTOMOVESTART = 371,
     OUTPUTDIRECTORIESTOMOVEEND = 372,
     OUTPUTFILESTOMOVESTART = 373,
     OUTPUTFILESTOMOVEEND = 374,
     PROCESSESTOKILLSTART = 375,
     PROCESSESTOKILLEND = 376,
     PROCESSSTART = 377,
     PROCESSEND = 378,
     VARIABLESSTART = 379,
     VARIABLESEND = 380,
     INITIALVARIABLEVALUESSTART = 381,
     INITIALVARIABLEVALUESEND = 382,
     VARSTART = 383,
     VAREND = 384,
     INITIALVARIABLEVALUESSTRINGSTART = 385,
     INITIALVARIABLEVALUESSTRINGEND = 386,
     INITIALBASISSTATUSSTART = 387,
     INITIALBASISSTATUSEND = 388,
     INTEGERVARIABLEBRANCHINGWEIGHTSSTART = 389,
     INTEGERVARIABLEBRANCHINGWEIGHTSEND = 390,
     SOSVARIABLEBRANCHINGWEIGHTSSTART = 391,
     SOSVARIABLEBRANCHINGWEIGHTSEND = 392,
     SOSSTART = 393,
     SOSEND = 394,
     OBJECTIVESSTART = 395,
     OBJECTIVESEND = 396,
     INITIALOBJECTIVEVALUESSTART = 397,
     INITIALOBJECTIVEVALUESEND = 398,
     OBJSTART = 399,
     OBJEND = 400,
     INITIALOBJECTIVEBOUNDSSTART = 401,
     INITIALOBJECTIVEBOUNDSEND = 402,
     CONSTRAINTSSTART = 403,
     CONSTRAINTSEND = 404,
     INITIALCONSTRAINTVALUESSTART = 405,
     INITIALCONSTRAINTVALUESEND = 406,
     CONSTART = 407,
     CONEND = 408,
     INITIALDUALVALUESSTART = 409,
     INITIALDUALVALUESEND = 410,
     SOLVEROPTIONSSTART = 411,
     SOLVEROPTIONSEND = 412,
     SOLVEROPTIONSTART = 413,
     SOLVEROPTIONEND = 414,
     DUMMY = 415
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
#define GROUPWEIGHTATT 280
#define NUMBEROFPROCESSESATT 281
#define NUMBEROFSOLVEROPTIONSATT 282
#define NUMBEROFSOSATT 283
#define NUMBEROFVARIABLESATT 284
#define NUMBEROFOBJECTIVESATT 285
#define NUMBEROFCONSTRAINTSATT 286
#define NUMBEROFOTHERVARIABLEOPTIONSATT 287
#define NUMBEROFOTHEROBJECTIVEOPTIONSATT 288
#define NUMBEROFOTHERCONSTRAINTOPTIONSATT 289
#define NUMBEROFVARATT 290
#define NUMBEROFOBJATT 291
#define NUMBEROFCONATT 292
#define NAMEATT 293
#define IDXATT 294
#define SOSIDXATT 295
#define VALUEATT 296
#define UNITATT 297
#define DESCRIPTIONATT 298
#define LBVALUEATT 299
#define UBVALUEATT 300
#define GENERALSTART 301
#define GENERALEND 302
#define SYSTEMSTART 303
#define SYSTEMEND 304
#define SERVICESTART 305
#define SERVICEEND 306
#define JOBSTART 307
#define JOBEND 308
#define OPTIMIZATIONSTART 309
#define OPTIMIZATIONEND 310
#define SERVICEURISTART 311
#define SERVICEURIEND 312
#define SERVICENAMESTART 313
#define SERVICENAMEEND 314
#define INSTANCENAMESTART 315
#define INSTANCENAMEEND 316
#define INSTANCELOCATIONSTART 317
#define INSTANCELOCATIONEND 318
#define JOBIDSTART 319
#define JOBIDEND 320
#define SOLVERTOINVOKESTART 321
#define SOLVERTOINVOKEEND 322
#define LICENSESTART 323
#define LICENSEEND 324
#define USERNAMESTART 325
#define USERNAMEEND 326
#define PASSWORDSTART 327
#define PASSWORDEND 328
#define CONTACTSTART 329
#define CONTACTEND 330
#define OTHEROPTIONSSTART 331
#define OTHEROPTIONSEND 332
#define OTHERSTART 333
#define OTHEREND 334
#define MINDISKSPACESTART 335
#define MINDISKSPACEEND 336
#define MINMEMORYSIZESTART 337
#define MINMEMORYSIZEEND 338
#define MINCPUSPEEDSTART 339
#define MINCPUSPEEDEND 340
#define MINCPUNUMBERSTART 341
#define MINCPUNUMBEREND 342
#define SERVICETYPESTART 343
#define SERVICETYPEEND 344
#define MAXTIMESTART 345
#define MAXTIMEEND 346
#define SCHEDULEDSTARTTIMESTART 347
#define SCHEDULEDSTARTTIMEEND 348
#define DEPENDENCIESSTART 349
#define DEPENDENCIESEND 350
#define REQUIREDDIRECTORIESSTART 351
#define REQUIREDDIRECTORIESEND 352
#define REQUIREDFILESSTART 353
#define REQUIREDFILESEND 354
#define PATHSTART 355
#define PATHEND 356
#define PATHPAIRSTART 357
#define PATHPAIREND 358
#define DIRECTORIESTOMAKESTART 359
#define DIRECTORIESTOMAKEEND 360
#define FILESTOMAKESTART 361
#define FILESTOMAKEEND 362
#define DIRECTORIESTODELETESTART 363
#define DIRECTORIESTODELETEEND 364
#define FILESTODELETESTART 365
#define FILESTODELETEEND 366
#define INPUTDIRECTORIESTOMOVESTART 367
#define INPUTDIRECTORIESTOMOVEEND 368
#define INPUTFILESTOMOVESTART 369
#define INPUTFILESTOMOVEEND 370
#define OUTPUTDIRECTORIESTOMOVESTART 371
#define OUTPUTDIRECTORIESTOMOVEEND 372
#define OUTPUTFILESTOMOVESTART 373
#define OUTPUTFILESTOMOVEEND 374
#define PROCESSESTOKILLSTART 375
#define PROCESSESTOKILLEND 376
#define PROCESSSTART 377
#define PROCESSEND 378
#define VARIABLESSTART 379
#define VARIABLESEND 380
#define INITIALVARIABLEVALUESSTART 381
#define INITIALVARIABLEVALUESEND 382
#define VARSTART 383
#define VAREND 384
#define INITIALVARIABLEVALUESSTRINGSTART 385
#define INITIALVARIABLEVALUESSTRINGEND 386
#define INITIALBASISSTATUSSTART 387
#define INITIALBASISSTATUSEND 388
#define INTEGERVARIABLEBRANCHINGWEIGHTSSTART 389
#define INTEGERVARIABLEBRANCHINGWEIGHTSEND 390
#define SOSVARIABLEBRANCHINGWEIGHTSSTART 391
#define SOSVARIABLEBRANCHINGWEIGHTSEND 392
#define SOSSTART 393
#define SOSEND 394
#define OBJECTIVESSTART 395
#define OBJECTIVESEND 396
#define INITIALOBJECTIVEVALUESSTART 397
#define INITIALOBJECTIVEVALUESEND 398
#define OBJSTART 399
#define OBJEND 400
#define INITIALOBJECTIVEBOUNDSSTART 401
#define INITIALOBJECTIVEBOUNDSEND 402
#define CONSTRAINTSSTART 403
#define CONSTRAINTSEND 404
#define INITIALCONSTRAINTVALUESSTART 405
#define INITIALCONSTRAINTVALUESEND 406
#define CONSTART 407
#define CONEND 408
#define INITIALDUALVALUESSTART 409
#define INITIALDUALVALUESEND 410
#define SOLVEROPTIONSSTART 411
#define SOLVEROPTIONSEND 412
#define SOLVEROPTIONSTART 413
#define SOLVEROPTIONEND 414
#define DUMMY 415




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
#define YYLAST   795

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  161
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  522
/* YYNRULES -- Number of rules.  */
#define YYNRULES  774
/* YYNRULES -- Number of states.  */
#define YYNSTATES  1299

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   415

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
     155,   156,   157,   158,   159,   160
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
    1161,  1166,  1167,  1171,  1173,  1174,  1179,  1188,  1190,  1191,
    1197,  1202,  1203,  1206,  1210,  1212,  1213,  1216,  1218,  1220,
    1225,  1226,  1231,  1234,  1236,  1237,  1243,  1248,  1249,  1252,
    1256,  1258,  1259,  1262,  1264,  1266,  1271,  1272,  1277,  1280,
    1282,  1283,  1289,  1294,  1295,  1298,  1302,  1304,  1305,  1308,
    1310,  1312,  1317,  1318,  1323,  1326,  1328,  1329,  1335,  1340,
    1341,  1344,  1348,  1350,  1351,  1354,  1356,  1358,  1363,  1364,
    1369,  1372,  1374,  1375,  1381,  1386,  1387,  1390,  1394,  1396,
    1397,  1400,  1402,  1404,  1406,  1411,  1416,  1421,  1426,  1430,
    1432,  1433,  1436,  1440,  1442,  1443,  1446,  1448,  1450,  1455,
    1456,  1461,  1464,  1466,  1467,  1470,  1474,  1476,  1477,  1480,
    1482,  1484,  1486,  1488,  1490,  1492,  1494,  1499,  1500,  1505,
    1506,  1511,  1512,  1517,  1518,  1523,  1524,  1529,  1530,  1535,
    1539,  1540,  1543,  1547,  1549,  1550,  1553,  1555,  1557,  1559,
    1561,  1566,  1567,  1572,  1573,  1578,  1579,  1584,  1587,  1589,
    1590,  1594,  1596,  1597,  1602,  1608,  1610,  1611,  1617,  1622,
    1623,  1626,  1630,  1632,  1633,  1636,  1638,  1640,  1645,  1646,
    1651,  1654,  1656,  1657,  1663,  1668,  1669,  1672,  1676,  1678,
    1679,  1682,  1684,  1686,  1688,  1693,  1694,  1699,  1700,  1705,
    1708,  1710,  1711,  1714,  1718,  1720,  1721,  1724,  1726,  1728,
    1730,  1732,  1734,  1736,  1738,  1743,  1744,  1749,  1750,  1755,
    1756,  1761,  1762,  1767,  1768,  1773,  1774,  1779,  1783,  1784,
    1787,  1791,  1793,  1794,  1797,  1799,  1801,  1803,  1805,  1810,
    1811,  1816,  1817,  1822,  1823,  1828,  1831,  1833,  1834,  1838,
    1840,  1841,  1846,  1852,  1854,  1855,  1861,  1866,  1867,  1870,
    1874,  1876,  1877,  1880,  1882,  1884,  1889,  1890,  1895,  1898,
    1900,  1901,  1907,  1912,  1913,  1916,  1920,  1922,  1923,  1926,
    1928,  1930,  1932,  1937,  1938,  1943,  1944,  1949,  1952,  1954,
    1955,  1958,  1962,  1964,  1965,  1968,  1970,  1972,  1974,  1976,
    1978,  1980,  1982,  1987,  1988,  1993,  1994,  1999,  2000,  2005,
    2006,  2011,  2012,  2017,  2018,  2023,  2027,  2028,  2031,  2035,
    2037,  2038,  2041,  2043,  2045,  2047,  2049,  2054,  2055,  2060,
    2061,  2066,  2067,  2072,  2075,  2077,  2078,  2084,  2086,  2091,
    2092,  2095,  2096,  2101,  2102,  2105,  2107,  2109,  2111,  2113,
    2115,  2117,  2118,  2123,  2124,  2129,  2130,  2135,  2136,  2141,
    2142,  2147,  2148,  2153,  2156
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     162,     0,    -1,   163,     8,   164,    12,    -1,   163,     9,
      -1,    10,    -1,    10,    11,    -1,   165,   230,   270,   295,
     433,    -1,    -1,   166,   167,    -1,    46,    -1,     8,   168,
      47,    -1,     9,    -1,    -1,   168,   169,    -1,   170,    -1,
     174,    -1,   178,    -1,   182,    -1,   188,    -1,   192,    -1,
     196,    -1,   200,    -1,   204,    -1,   208,    -1,   214,    -1,
     171,   172,    -1,    56,    -1,     9,    -1,     8,    57,    -1,
      -1,     8,     4,   173,    57,    -1,   175,   176,    -1,    58,
      -1,     9,    -1,     8,    59,    -1,    -1,     8,     4,   177,
      59,    -1,   179,   180,    -1,    60,    -1,     9,    -1,     8,
      61,    -1,    -1,     8,     4,   181,    61,    -1,   183,   184,
     186,    -1,    62,    -1,    -1,    -1,    13,     3,   185,     7,
      -1,     9,    -1,     8,   187,    63,    -1,    -1,     4,    -1,
     189,   190,    -1,    64,    -1,     9,    -1,     8,    65,    -1,
      -1,     8,     4,   191,    65,    -1,   193,   194,    -1,    66,
      -1,     9,    -1,     8,    67,    -1,    -1,     8,     4,   195,
      67,    -1,   197,   198,    -1,    68,    -1,     9,    -1,     8,
      69,    -1,    -1,     8,     4,   199,    69,    -1,   201,   202,
      -1,    70,    -1,     9,    -1,     8,    71,    -1,    -1,     8,
       4,   203,    71,    -1,   205,   206,    -1,    72,    -1,     9,
      -1,     8,    73,    -1,    -1,     8,     4,   207,    73,    -1,
     209,   210,   212,    -1,    74,    -1,    -1,    -1,    14,     3,
     211,     7,    -1,     9,    -1,     8,   213,    75,    -1,    -1,
       4,    -1,   215,   216,     8,   217,    -1,    76,    -1,    15,
       7,     5,     7,    -1,   218,    77,    -1,    -1,   218,   219,
      -1,    -1,    78,   220,   221,   229,    -1,    -1,   221,   222,
      -1,   223,    -1,   225,    -1,   227,    -1,    -1,    38,     3,
     224,     7,    -1,    -1,    41,     3,   226,     7,    -1,    -1,
      43,     3,   228,     7,    -1,     9,    -1,     8,    79,    -1,
      -1,   231,   232,    -1,    48,    -1,     8,   233,    49,    -1,
       9,    -1,    -1,   233,   234,    -1,   235,    -1,   240,    -1,
     245,    -1,   250,    -1,   254,    -1,   236,   237,   239,    -1,
      80,    -1,    -1,    -1,    42,     3,   238,     7,    -1,     9,
      -1,     8,    81,    -1,     8,     6,    81,    -1,     8,     5,
      81,    -1,   241,   242,   244,    -1,    82,    -1,    -1,    -1,
      42,     3,   243,     7,    -1,     9,    -1,     8,    83,    -1,
       8,     6,    83,    -1,     8,     5,    83,    -1,   246,   247,
     249,    -1,    84,    -1,    -1,    -1,    42,     3,   248,     7,
      -1,     9,    -1,     8,    85,    -1,     8,     6,    85,    -1,
       8,     5,    85,    -1,   251,   252,    -1,    86,    -1,     9,
      -1,     8,    87,    -1,    -1,     8,     5,   253,    87,    -1,
     255,   256,     8,   257,    -1,    76,    -1,    15,     7,     5,
       7,    -1,   258,    77,    -1,    -1,   258,   259,    -1,    -1,
      78,   260,   261,   269,    -1,    -1,   261,   262,    -1,   263,
      -1,   265,    -1,   267,    -1,    -1,    38,     3,   264,     7,
      -1,    -1,    41,     3,   266,     7,    -1,    -1,    43,     3,
     268,     7,    -1,     9,    -1,     8,    79,    -1,    -1,   271,
     272,    -1,    50,    -1,     8,   273,    51,    -1,     9,    -1,
      -1,   273,   274,    -1,   275,    -1,   279,    -1,   276,   277,
      -1,    88,    -1,     9,    -1,     8,    89,    -1,    -1,     8,
       4,   278,    89,    -1,   280,   281,     8,   282,    -1,    76,
      -1,    15,     7,     5,     7,    -1,   283,    77,    -1,    -1,
     283,   284,    -1,    -1,    78,   285,   286,   294,    -1,    -1,
     286,   287,    -1,   288,    -1,   290,    -1,   292,    -1,    -1,
      38,     3,   289,     7,    -1,    -1,    41,     3,   291,     7,
      -1,    -1,    43,     3,   293,     7,    -1,     9,    -1,     8,
      79,    -1,   296,   297,    -1,    52,    -1,     8,   298,    53,
      -1,     9,    -1,    -1,   298,   299,    -1,   300,    -1,   305,
      -1,   309,    -1,   315,    -1,   321,    -1,   327,    -1,   333,
      -1,   339,    -1,   354,    -1,   369,    -1,   384,    -1,   399,
      -1,   405,    -1,   411,    -1,   417,    -1,   301,   302,   304,
      -1,    90,    -1,    -1,    -1,    42,     3,   303,     7,    -1,
       9,    -1,     8,    91,    -1,     8,     6,    91,    -1,     8,
       5,    91,    -1,   306,   307,    -1,    92,    -1,     9,    -1,
       8,    93,    -1,    -1,     8,     4,   308,    93,    -1,   310,
     311,     8,   312,    95,    -1,    94,    -1,    16,     7,     5,
       7,    -1,    -1,   312,   313,    -1,    -1,    64,     8,     4,
     314,    65,    -1,   316,   317,     8,   318,    97,    -1,    96,
      -1,    17,     7,     5,     7,    -1,    -1,   318,   319,    -1,
      -1,   100,     8,     4,   320,   101,    -1,   322,   323,     8,
     324,    99,    -1,    98,    -1,    17,     7,     5,     7,    -1,
      -1,   324,   325,    -1,    -1,   100,     8,     4,   326,   101,
      -1,   328,   329,     8,   330,   105,    -1,   104,    -1,    17,
       7,     5,     7,    -1,    -1,   330,   331,    -1,    -1,   100,
       8,     4,   332,   101,    -1,   334,   335,     8,   336,   107,
      -1,   106,    -1,    17,     7,     5,     7,    -1,    -1,   336,
     337,    -1,    -1,   100,     8,     4,   338,   101,    -1,   340,
     341,     8,   342,   113,    -1,   112,    -1,    18,     7,     5,
       7,    -1,    -1,   342,   343,    -1,   344,   345,   353,    -1,
     102,    -1,    -1,   345,   346,    -1,   347,    -1,   349,    -1,
     351,    -1,    -1,    19,     3,   348,     7,    -1,    -1,    20,
       3,   350,     7,    -1,    -1,    21,     3,   352,     7,    -1,
       8,   103,    -1,     9,    -1,   355,   356,     8,   357,   115,
      -1,   114,    -1,    18,     7,     5,     7,    -1,    -1,   357,
     358,    -1,   359,   360,   368,    -1,   102,    -1,    -1,   360,
     361,    -1,   362,    -1,   364,    -1,   366,    -1,    -1,    19,
       3,   363,     7,    -1,    -1,    20,     3,   365,     7,    -1,
      -1,    21,     3,   367,     7,    -1,     8,   103,    -1,     9,
      -1,   370,   371,     8,   372,   117,    -1,   116,    -1,    18,
       7,     5,     7,    -1,    -1,   372,   373,    -1,   374,   375,
     383,    -1,   102,    -1,    -1,   375,   376,    -1,   377,    -1,
     379,    -1,   381,    -1,    -1,    19,     3,   378,     7,    -1,
      -1,    20,     3,   380,     7,    -1,    -1,    21,     3,   382,
       7,    -1,     8,   103,    -1,     9,    -1,   385,   386,     8,
     387,   119,    -1,   118,    -1,    18,     7,     5,     7,    -1,
      -1,   387,   388,    -1,   389,   390,   398,    -1,   102,    -1,
      -1,   390,   391,    -1,   392,    -1,   394,    -1,   396,    -1,
      -1,    19,     3,   393,     7,    -1,    -1,    20,     3,   395,
       7,    -1,    -1,    21,     3,   397,     7,    -1,     8,   103,
      -1,     9,    -1,   400,   401,     8,   402,   111,    -1,   110,
      -1,    17,     7,     5,     7,    -1,    -1,   402,   403,    -1,
      -1,   100,     8,     4,   404,   101,    -1,   406,   407,     8,
     408,   109,    -1,   108,    -1,    17,     7,     5,     7,    -1,
      -1,   408,   409,    -1,    -1,   100,     8,     4,   410,   101,
      -1,   412,   413,     8,   414,   121,    -1,   120,    -1,    26,
       7,     5,     7,    -1,    -1,   414,   415,    -1,    -1,   122,
       8,     4,   416,   123,    -1,   418,   419,     8,   420,    -1,
      76,    -1,    15,     7,     5,     7,    -1,   421,    77,    -1,
      -1,   421,   422,    -1,    -1,    78,   423,   424,   432,    -1,
      -1,   424,   425,    -1,   426,    -1,   428,    -1,   430,    -1,
      -1,    38,     3,   427,     7,    -1,    -1,    41,     3,   429,
       7,    -1,    -1,    43,     3,   431,     7,    -1,     9,    -1,
       8,    79,    -1,    -1,   434,   435,   440,    -1,    54,    -1,
      -1,   435,   436,    -1,   437,    -1,   438,    -1,   439,    -1,
      29,     7,     5,     7,    -1,    31,     7,     5,     7,    -1,
      30,     7,     5,     7,    -1,     8,   441,    55,    -1,     9,
      -1,   442,   542,   602,   662,    -1,    -1,   443,   444,   445,
      -1,   124,    -1,    -1,    32,     7,     5,     7,    -1,     8,
     446,   457,   468,   479,   490,   510,   125,    -1,     9,    -1,
      -1,   126,   447,     8,   448,   127,    -1,    35,     7,     5,
       7,    -1,    -1,   448,   449,    -1,   450,   451,   456,    -1,
     128,    -1,    -1,   451,   452,    -1,   453,    -1,   454,    -1,
      39,     7,     5,     7,    -1,    -1,    41,     3,   455,     7,
      -1,     8,   129,    -1,     9,    -1,    -1,   130,   458,     8,
     459,   131,    -1,    35,     7,     5,     7,    -1,    -1,   459,
     460,    -1,   461,   462,   467,    -1,   128,    -1,    -1,   462,
     463,    -1,   464,    -1,   465,    -1,    39,     7,     5,     7,
      -1,    -1,    41,     3,   466,     7,    -1,     8,   129,    -1,
       9,    -1,    -1,   132,   469,     8,   470,   133,    -1,    35,
       7,     5,     7,    -1,    -1,   470,   471,    -1,   472,   473,
     478,    -1,   128,    -1,    -1,   473,   474,    -1,   475,    -1,
     476,    -1,    39,     7,     5,     7,    -1,    -1,    41,     3,
     477,     7,    -1,     8,   129,    -1,     9,    -1,    -1,   134,
     480,     8,   481,   135,    -1,    35,     7,     5,     7,    -1,
      -1,   481,   482,    -1,   483,   484,   489,    -1,   128,    -1,
      -1,   484,   485,    -1,   486,    -1,   487,    -1,    39,     7,
       5,     7,    -1,    -1,    41,     3,   488,     7,    -1,     8,
     129,    -1,     9,    -1,    -1,   136,   491,     8,   492,   137,
      -1,    28,     7,     5,     7,    -1,    -1,   492,   493,    -1,
     494,   495,   500,    -1,   138,    -1,    -1,   495,   496,    -1,
     497,    -1,   499,    -1,   498,    -1,    40,     7,     5,     7,
      -1,    25,     7,     6,     7,    -1,    25,     7,     5,     7,
      -1,    35,     7,     5,     7,    -1,     8,   501,   139,    -1,
       9,    -1,    -1,   501,   502,    -1,   503,   504,   509,    -1,
     128,    -1,    -1,   504,   505,    -1,   506,    -1,   507,    -1,
      39,     7,     5,     7,    -1,    -1,    41,     3,   508,     7,
      -1,     8,   129,    -1,     9,    -1,    -1,   510,   511,    -1,
     512,   513,   528,    -1,    78,    -1,    -1,   513,   514,    -1,
     515,    -1,   516,    -1,   518,    -1,   520,    -1,   522,    -1,
     524,    -1,   526,    -1,    35,     7,     5,     7,    -1,    -1,
      38,     3,   517,     7,    -1,    -1,    41,     3,   519,     7,
      -1,    -1,    22,     3,   521,     7,    -1,    -1,    23,     3,
     523,     7,    -1,    -1,    24,     3,   525,     7,    -1,    -1,
      43,     3,   527,     7,    -1,     8,   529,    79,    -1,    -1,
     529,   530,    -1,   531,   532,   541,    -1,   128,    -1,    -1,
     532,   533,    -1,   534,    -1,   535,    -1,   537,    -1,   539,
      -1,    39,     7,     5,     7,    -1,    -1,    41,     3,   536,
       7,    -1,    -1,    44,     3,   538,     7,    -1,    -1,    45,
       3,   540,     7,    -1,     8,   129,    -1,     9,    -1,    -1,
     543,   544,   545,    -1,   140,    -1,    -1,    33,     7,     5,
       7,    -1,     8,   546,   557,   570,   141,    -1,     9,    -1,
      -1,   142,   547,     8,   548,   143,    -1,    36,     7,     5,
       7,    -1,    -1,   548,   549,    -1,   550,   551,   556,    -1,
     144,    -1,    -1,   551,   552,    -1,   553,    -1,   554,    -1,
      39,     7,     5,     7,    -1,    -1,    41,     3,   555,     7,
      -1,     8,   145,    -1,     9,    -1,    -1,   146,   558,     8,
     559,   147,    -1,    36,     7,     5,     7,    -1,    -1,   559,
     560,    -1,   561,   562,   569,    -1,   144,    -1,    -1,   562,
     563,    -1,   564,    -1,   565,    -1,   567,    -1,    39,     7,
       5,     7,    -1,    -1,    44,     3,   566,     7,    -1,    -1,
      45,     3,   568,     7,    -1,     8,   145,    -1,     9,    -1,
      -1,   570,   571,    -1,   572,   573,   588,    -1,    78,    -1,
      -1,   573,   574,    -1,   575,    -1,   576,    -1,   578,    -1,
     580,    -1,   582,    -1,   584,    -1,   586,    -1,    36,     7,
       5,     7,    -1,    -1,    38,     3,   577,     7,    -1,    -1,
      41,     3,   579,     7,    -1,    -1,    22,     3,   581,     7,
      -1,    -1,    23,     3,   583,     7,    -1,    -1,    24,     3,
     585,     7,    -1,    -1,    43,     3,   587,     7,    -1,     8,
     589,    79,    -1,    -1,   589,   590,    -1,   591,   592,   601,
      -1,   144,    -1,    -1,   592,   593,    -1,   594,    -1,   595,
      -1,   597,    -1,   599,    -1,    39,     7,     5,     7,    -1,
      -1,    41,     3,   596,     7,    -1,    -1,    44,     3,   598,
       7,    -1,    -1,    45,     3,   600,     7,    -1,     8,   129,
      -1,     9,    -1,    -1,   603,   604,   605,    -1,   148,    -1,
      -1,    34,     7,     5,     7,    -1,     8,   606,   617,   630,
     149,    -1,     9,    -1,    -1,   150,   607,     8,   608,   151,
      -1,    37,     7,     5,     7,    -1,    -1,   608,   609,    -1,
     610,   611,   616,    -1,   152,    -1,    -1,   611,   612,    -1,
     613,    -1,   614,    -1,    39,     7,     5,     7,    -1,    -1,
      41,     3,   615,     7,    -1,     8,   153,    -1,     9,    -1,
      -1,   154,   618,     8,   619,   155,    -1,    37,     7,     5,
       7,    -1,    -1,   619,   620,    -1,   621,   622,   629,    -1,
     152,    -1,    -1,   622,   623,    -1,   624,    -1,   625,    -1,
     627,    -1,    39,     7,     5,     7,    -1,    -1,    44,     3,
     626,     7,    -1,    -1,    45,     3,   628,     7,    -1,     8,
     153,    -1,     9,    -1,    -1,   630,   631,    -1,   632,   633,
     648,    -1,    78,    -1,    -1,   633,   634,    -1,   635,    -1,
     636,    -1,   638,    -1,   640,    -1,   642,    -1,   644,    -1,
     646,    -1,    37,     7,     5,     7,    -1,    -1,    38,     3,
     637,     7,    -1,    -1,    41,     3,   639,     7,    -1,    -1,
      22,     3,   641,     7,    -1,    -1,    23,     3,   643,     7,
      -1,    -1,    24,     3,   645,     7,    -1,    -1,    43,     3,
     647,     7,    -1,     8,   649,    79,    -1,    -1,   649,   650,
      -1,   651,   652,   661,    -1,   152,    -1,    -1,   652,   653,
      -1,   654,    -1,   655,    -1,   657,    -1,   659,    -1,    39,
       7,     5,     7,    -1,    -1,    41,     3,   656,     7,    -1,
      -1,    44,     3,   658,     7,    -1,    -1,    45,     3,   660,
       7,    -1,     8,   153,    -1,     9,    -1,    -1,   663,   664,
       8,   665,   157,    -1,   156,    -1,    27,     7,     5,     7,
      -1,    -1,   665,   666,    -1,    -1,   158,   667,   668,   682,
      -1,    -1,   668,   669,    -1,   670,    -1,   672,    -1,   674,
      -1,   676,    -1,   678,    -1,   680,    -1,    -1,    38,     3,
     671,     7,    -1,    -1,    41,     3,   673,     7,    -1,    -1,
      22,     3,   675,     7,    -1,    -1,    23,     3,   677,     7,
      -1,    -1,    24,     3,   679,     7,    -1,    -1,    43,     3,
     681,     7,    -1,     8,   159,    -1,     9,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   133,   133,   134,   136,   137,   139,   141,   141,   143,
     154,   155,   157,   157,   159,   159,   159,   159,   159,   160,
     160,   160,   160,   160,   160,   163,   165,   174,   175,   176,
     176,   179,   181,   190,   191,   192,   192,   195,   197,   206,
     207,   208,   208,   211,   213,   224,   225,   224,   232,   233,
     235,   235,   238,   240,   249,   250,   251,   251,   254,   256,
     265,   266,   267,   267,   270,   272,   281,   282,   283,   283,
     286,   288,   297,   298,   299,   299,   302,   304,   313,   314,
     315,   315,   318,   320,   331,   332,   331,   340,   341,   343,
     343,   346,   348,   358,   366,   371,   371,   374,   373,   389,
     389,   391,   391,   391,   394,   393,   405,   404,   416,   415,
     426,   426,   429,   429,   431,   442,   443,   445,   445,   447,
     447,   447,   447,   447,   449,   451,   462,   463,   462,   471,
     472,   473,   478,   485,   487,   498,   499,   498,   507,   508,
     509,   514,   522,   524,   535,   536,   535,   546,   547,   548,
     553,   561,   563,   572,   573,   575,   574,   582,   584,   594,
     602,   607,   607,   610,   609,   624,   624,   626,   626,   626,
     629,   628,   640,   639,   652,   651,   662,   662,   665,   665,
     667,   678,   679,   681,   681,   683,   683,   685,   687,   697,
     698,   700,   699,   709,   711,   721,   729,   734,   734,   737,
     736,   751,   751,   753,   753,   753,   756,   755,   767,   766,
     778,   777,   788,   788,   791,   793,   803,   804,   806,   806,
     808,   808,   808,   808,   808,   809,   809,   809,   809,   809,
     810,   810,   810,   810,   810,   813,   815,   826,   827,   826,
     836,   837,   838,   843,   850,   852,   862,   863,   864,   864,
     866,   868,   878,   885,   885,   888,   887,   900,   903,   913,
     920,   920,   922,   922,   934,   937,   947,   954,   954,   956,
     956,   968,   971,   980,   987,   987,   990,   989,  1001,  1004,
    1014,  1021,  1021,  1024,  1023,  1035,  1038,  1048,  1057,  1057,
    1059,  1071,  1077,  1077,  1079,  1079,  1079,  1082,  1081,  1093,
    1092,  1104,  1103,  1115,  1115,  1118,  1121,  1131,  1139,  1139,
    1141,  1153,  1159,  1159,  1161,  1161,  1161,  1164,  1163,  1175,
    1174,  1186,  1185,  1197,  1197,  1200,  1203,  1213,  1222,  1222,
    1224,  1236,  1242,  1242,  1244,  1244,  1244,  1247,  1246,  1258,
    1257,  1269,  1268,  1280,  1280,  1283,  1286,  1296,  1304,  1304,
    1306,  1318,  1324,  1324,  1326,  1326,  1326,  1329,  1328,  1340,
    1339,  1351,  1350,  1362,  1362,  1365,  1368,  1378,  1385,  1385,
    1388,  1387,  1399,  1402,  1412,  1419,  1419,  1422,  1421,  1433,
    1437,  1447,  1454,  1454,  1457,  1456,  1468,  1470,  1480,  1488,
    1493,  1493,  1496,  1495,  1510,  1510,  1512,  1512,  1512,  1515,
    1514,  1526,  1525,  1537,  1536,  1547,  1547,  1550,  1550,  1552,
    1562,  1562,  1564,  1564,  1564,  1566,  1572,  1578,  1584,  1584,
    1586,  1588,  1588,  1590,  1594,  1594,  1603,  1605,  1607,  1607,
    1609,  1619,  1619,  1621,  1629,  1634,  1634,  1636,  1636,  1638,
    1652,  1651,  1664,  1664,  1667,  1667,  1670,  1680,  1680,  1682,
    1690,  1695,  1695,  1697,  1697,  1699,  1713,  1712,  1720,  1720,
    1723,  1723,  1726,  1736,  1736,  1738,  1746,  1751,  1751,  1753,
    1753,  1755,  1769,  1768,  1776,  1776,  1779,  1779,  1782,  1792,
    1792,  1794,  1802,  1807,  1807,  1809,  1809,  1811,  1825,  1824,
    1837,  1837,  1840,  1840,  1843,  1854,  1854,  1856,  1868,  1873,
    1873,  1875,  1875,  1875,  1877,  1890,  1897,  1904,  1915,  1916,
    1918,  1918,  1920,  1928,  1933,  1933,  1935,  1935,  1937,  1951,
    1950,  1963,  1963,  1966,  1966,  1968,  1970,  1975,  1975,  1978,
    1979,  1980,  1981,  1982,  1983,  1984,  1986,  2000,  1999,  2008,
    2007,  2016,  2015,  2024,  2023,  2032,  2031,  2040,  2039,  2048,
    2065,  2065,  2067,  2077,  2082,  2082,  2085,  2086,  2087,  2088,
    2090,  2104,  2103,  2112,  2111,  2120,  2119,  2127,  2127,  2131,
    2131,  2133,  2137,  2137,  2146,  2147,  2149,  2149,  2152,  2162,
    2162,  2164,  2172,  2177,  2177,  2179,  2179,  2181,  2196,  2195,
    2208,  2208,  2211,  2211,  2214,  2224,  2224,  2226,  2235,  2240,
    2240,  2242,  2242,  2242,  2244,  2258,  2257,  2271,  2270,  2283,
    2283,  2287,  2287,  2289,  2291,  2296,  2296,  2299,  2300,  2301,
    2302,  2303,  2304,  2305,  2307,  2321,  2320,  2330,  2329,  2339,
    2338,  2348,  2347,  2357,  2356,  2366,  2365,  2375,  2392,  2392,
    2394,  2404,  2409,  2409,  2412,  2413,  2414,  2415,  2417,  2432,
    2431,  2441,  2440,  2450,  2449,  2458,  2458,  2461,  2461,  2463,
    2467,  2467,  2476,  2478,  2480,  2480,  2483,  2493,  2493,  2495,
    2503,  2508,  2508,  2510,  2510,  2512,  2527,  2526,  2539,  2539,
    2542,  2542,  2545,  2555,  2555,  2557,  2566,  2571,  2571,  2573,
    2573,  2573,  2575,  2589,  2588,  2602,  2601,  2615,  2615,  2618,
    2618,  2620,  2622,  2627,  2627,  2630,  2631,  2632,  2633,  2634,
    2635,  2636,  2638,  2652,  2651,  2660,  2659,  2668,  2667,  2676,
    2675,  2684,  2683,  2692,  2691,  2700,  2717,  2717,  2719,  2729,
    2734,  2734,  2737,  2738,  2739,  2740,  2742,  2757,  2756,  2766,
    2765,  2774,  2773,  2781,  2781,  2784,  2784,  2789,  2799,  2807,
    2807,  2810,  2809,  2827,  2827,  2830,  2831,  2832,  2833,  2834,
    2835,  2839,  2838,  2850,  2849,  2861,  2860,  2872,  2871,  2883,
    2882,  2894,  2893,  2905,  2905
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
  "CATEGORYATT", "TYPEATT", "GROUPWEIGHTATT", "NUMBEROFPROCESSESATT",
  "NUMBEROFSOLVEROPTIONSATT", "NUMBEROFSOSATT", "NUMBEROFVARIABLESATT",
  "NUMBEROFOBJECTIVESATT", "NUMBEROFCONSTRAINTSATT",
  "NUMBEROFOTHERVARIABLEOPTIONSATT", "NUMBEROFOTHEROBJECTIVEOPTIONSATT",
  "NUMBEROFOTHERCONSTRAINTOPTIONSATT", "NUMBEROFVARATT", "NUMBEROFOBJATT",
  "NUMBEROFCONATT", "NAMEATT", "IDXATT", "SOSIDXATT", "VALUEATT",
  "UNITATT", "DESCRIPTIONATT", "LBVALUEATT", "UBVALUEATT", "GENERALSTART",
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
  "maxtimehead", "maxtimeunit", "@28", "maxtimebody", "scheduledstarttime",
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
  "otherobjectiveoptionsatt", "otherobjectiveoptionnumberofvar",
  "otherobjectiveoptionname", "@71", "otherobjectiveoptionvalue", "@72",
  "otherobjectiveoptionsolver", "@73", "otherobjectiveoptioncategory",
  "@74", "otherobjectiveoptiontype", "@75",
  "otherobjectiveoptiondescription", "@76", "restofotherobjectiveoption",
  "otherobjectiveoptionsvarlist", "otherobjectiveoptionsvar",
  "otherobjectiveoptionsvarstart", "otherobjoptionattlist",
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
  "otherconstraintoptionsatt", "otherconstraintoptionnumberofvar",
  "otherconstraintoptionname", "@83", "otherconstraintoptionvalue", "@84",
  "otherconstraintoptionsolver", "@85", "otherconstraintoptioncategory",
  "@86", "otherconstraintoptiontype", "@87",
  "otherconstraintoptiondescription", "@88", "restofotherconstraintoption",
  "otherconstraintoptionsvarlist", "otherconstraintoptionsvar",
  "otherconstraintoptionsvarstart", "otherconoptionattlist",
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
     415
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   161,   162,   162,   163,   163,   164,   165,   165,   166,
     167,   167,   168,   168,   169,   169,   169,   169,   169,   169,
     169,   169,   169,   169,   169,   170,   171,   172,   172,   173,
     172,   174,   175,   176,   176,   177,   176,   178,   179,   180,
     180,   181,   180,   182,   183,   184,   185,   184,   186,   186,
     187,   187,   188,   189,   190,   190,   191,   190,   192,   193,
     194,   194,   195,   194,   196,   197,   198,   198,   199,   198,
     200,   201,   202,   202,   203,   202,   204,   205,   206,   206,
     207,   206,   208,   209,   210,   211,   210,   212,   212,   213,
     213,   214,   215,   216,   217,   218,   218,   220,   219,   221,
     221,   222,   222,   222,   224,   223,   226,   225,   228,   227,
     229,   229,   230,   230,   231,   232,   232,   233,   233,   234,
     234,   234,   234,   234,   235,   236,   237,   238,   237,   239,
     239,   239,   239,   240,   241,   242,   243,   242,   244,   244,
     244,   244,   245,   246,   247,   248,   247,   249,   249,   249,
     249,   250,   251,   252,   252,   253,   252,   254,   255,   256,
     257,   258,   258,   260,   259,   261,   261,   262,   262,   262,
     264,   263,   266,   265,   268,   267,   269,   269,   270,   270,
     271,   272,   272,   273,   273,   274,   274,   275,   276,   277,
     277,   278,   277,   279,   280,   281,   282,   283,   283,   285,
     284,   286,   286,   287,   287,   287,   289,   288,   291,   290,
     293,   292,   294,   294,   295,   296,   297,   297,   298,   298,
     299,   299,   299,   299,   299,   299,   299,   299,   299,   299,
     299,   299,   299,   299,   299,   300,   301,   302,   303,   302,
     304,   304,   304,   304,   305,   306,   307,   307,   308,   307,
     309,   310,   311,   312,   312,   314,   313,   315,   316,   317,
     318,   318,   320,   319,   321,   322,   323,   324,   324,   326,
     325,   327,   328,   329,   330,   330,   332,   331,   333,   334,
     335,   336,   336,   338,   337,   339,   340,   341,   342,   342,
     343,   344,   345,   345,   346,   346,   346,   348,   347,   350,
     349,   352,   351,   353,   353,   354,   355,   356,   357,   357,
     358,   359,   360,   360,   361,   361,   361,   363,   362,   365,
     364,   367,   366,   368,   368,   369,   370,   371,   372,   372,
     373,   374,   375,   375,   376,   376,   376,   378,   377,   380,
     379,   382,   381,   383,   383,   384,   385,   386,   387,   387,
     388,   389,   390,   390,   391,   391,   391,   393,   392,   395,
     394,   397,   396,   398,   398,   399,   400,   401,   402,   402,
     404,   403,   405,   406,   407,   408,   408,   410,   409,   411,
     412,   413,   414,   414,   416,   415,   417,   418,   419,   420,
     421,   421,   423,   422,   424,   424,   425,   425,   425,   427,
     426,   429,   428,   431,   430,   432,   432,   433,   433,   434,
     435,   435,   436,   436,   436,   437,   438,   439,   440,   440,
     441,   442,   442,   443,   444,   444,   445,   445,   446,   446,
     447,   448,   448,   449,   450,   451,   451,   452,   452,   453,
     455,   454,   456,   456,   457,   457,   458,   459,   459,   460,
     461,   462,   462,   463,   463,   464,   466,   465,   467,   467,
     468,   468,   469,   470,   470,   471,   472,   473,   473,   474,
     474,   475,   477,   476,   478,   478,   479,   479,   480,   481,
     481,   482,   483,   484,   484,   485,   485,   486,   488,   487,
     489,   489,   490,   490,   491,   492,   492,   493,   494,   495,
     495,   496,   496,   496,   497,   498,   498,   499,   500,   500,
     501,   501,   502,   503,   504,   504,   505,   505,   506,   508,
     507,   509,   509,   510,   510,   511,   512,   513,   513,   514,
     514,   514,   514,   514,   514,   514,   515,   517,   516,   519,
     518,   521,   520,   523,   522,   525,   524,   527,   526,   528,
     529,   529,   530,   531,   532,   532,   533,   533,   533,   533,
     534,   536,   535,   538,   537,   540,   539,   541,   541,   542,
     542,   543,   544,   544,   545,   545,   546,   546,   547,   548,
     548,   549,   550,   551,   551,   552,   552,   553,   555,   554,
     556,   556,   557,   557,   558,   559,   559,   560,   561,   562,
     562,   563,   563,   563,   564,   566,   565,   568,   567,   569,
     569,   570,   570,   571,   572,   573,   573,   574,   574,   574,
     574,   574,   574,   574,   575,   577,   576,   579,   578,   581,
     580,   583,   582,   585,   584,   587,   586,   588,   589,   589,
     590,   591,   592,   592,   593,   593,   593,   593,   594,   596,
     595,   598,   597,   600,   599,   601,   601,   602,   602,   603,
     604,   604,   605,   605,   606,   606,   607,   608,   608,   609,
     610,   611,   611,   612,   612,   613,   615,   614,   616,   616,
     617,   617,   618,   619,   619,   620,   621,   622,   622,   623,
     623,   623,   624,   626,   625,   628,   627,   629,   629,   630,
     630,   631,   632,   633,   633,   634,   634,   634,   634,   634,
     634,   634,   635,   637,   636,   639,   638,   641,   640,   643,
     642,   645,   644,   647,   646,   648,   649,   649,   650,   651,
     652,   652,   653,   653,   653,   653,   654,   656,   655,   658,
     657,   660,   659,   661,   661,   662,   662,   663,   664,   665,
     665,   667,   666,   668,   668,   669,   669,   669,   669,   669,
     669,   671,   670,   673,   672,   675,   674,   677,   676,   679,
     678,   681,   680,   682,   682
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
       4,     0,     3,     1,     0,     4,     8,     1,     0,     5,
       4,     0,     2,     3,     1,     0,     2,     1,     1,     4,
       0,     4,     2,     1,     0,     5,     4,     0,     2,     3,
       1,     0,     2,     1,     1,     4,     0,     4,     2,     1,
       0,     5,     4,     0,     2,     3,     1,     0,     2,     1,
       1,     4,     0,     4,     2,     1,     0,     5,     4,     0,
       2,     3,     1,     0,     2,     1,     1,     4,     0,     4,
       2,     1,     0,     5,     4,     0,     2,     3,     1,     0,
       2,     1,     1,     1,     4,     4,     4,     4,     3,     1,
       0,     2,     3,     1,     0,     2,     1,     1,     4,     0,
       4,     2,     1,     0,     2,     3,     1,     0,     2,     1,
       1,     1,     1,     1,     1,     1,     4,     0,     4,     0,
       4,     0,     4,     0,     4,     0,     4,     0,     4,     3,
       0,     2,     3,     1,     0,     2,     1,     1,     1,     1,
       4,     0,     4,     0,     4,     0,     4,     2,     1,     0,
       3,     1,     0,     4,     5,     1,     0,     5,     4,     0,
       2,     3,     1,     0,     2,     1,     1,     4,     0,     4,
       2,     1,     0,     5,     4,     0,     2,     3,     1,     0,
       2,     1,     1,     1,     4,     0,     4,     0,     4,     2,
       1,     0,     2,     3,     1,     0,     2,     1,     1,     1,
       1,     1,     1,     1,     4,     0,     4,     0,     4,     0,
       4,     0,     4,     0,     4,     0,     4,     3,     0,     2,
       3,     1,     0,     2,     1,     1,     1,     1,     4,     0,
       4,     0,     4,     0,     4,     2,     1,     0,     3,     1,
       0,     4,     5,     1,     0,     5,     4,     0,     2,     3,
       1,     0,     2,     1,     1,     4,     0,     4,     2,     1,
       0,     5,     4,     0,     2,     3,     1,     0,     2,     1,
       1,     1,     4,     0,     4,     0,     4,     2,     1,     0,
       2,     3,     1,     0,     2,     1,     1,     1,     1,     1,
       1,     1,     4,     0,     4,     0,     4,     0,     4,     0,
       4,     0,     4,     0,     4,     3,     0,     2,     3,     1,
       0,     2,     1,     1,     1,     1,     4,     0,     4,     0,
       4,     0,     4,     2,     1,     0,     5,     1,     4,     0,
       2,     0,     4,     0,     2,     1,     1,     1,     1,     1,
       1,     0,     4,     0,     4,     0,     4,     0,     4,     0,
       4,     0,     4,     2,     1
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
       0,     0,    91,     0,   423,     0,   569,   424,     0,     0,
       0,     0,     0,     0,   246,   244,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   191,   190,     0,   197,     0,     0,     0,   130,
       0,     0,     0,   139,     0,     0,     0,   148,     0,     0,
     157,     0,    30,    36,    42,    47,    49,    57,    63,    69,
      75,    81,    86,    88,    93,    94,    97,    96,   418,   571,
     657,   572,     0,     0,     0,     0,     0,   238,     0,   240,
     235,   248,   247,     0,   253,     0,   260,     0,   267,     0,
     274,     0,   281,     0,   288,     0,   308,     0,   328,     0,
     348,     0,   368,     0,   375,     0,   382,     0,   390,     0,
       0,   193,     0,   128,   132,   131,   137,   141,   140,   146,
     150,   149,   156,   159,   160,   163,   162,    99,   659,   745,
     660,     0,     0,     0,   428,   427,   422,   415,   417,   416,
       0,     0,     0,   241,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     386,     0,   192,   195,   196,   199,   198,   165,     0,   747,
     420,     0,     0,     0,     0,   576,   575,   570,     0,     0,
     444,   239,   243,   242,   249,   252,     0,   250,   254,   259,
     257,     0,   261,   266,   264,     0,   268,   273,     0,   271,
     275,   280,     0,   278,   282,   287,   291,   285,   289,   292,
     307,   311,   305,   309,   312,   327,   331,   325,   329,   332,
     347,   351,   345,   349,   352,   367,     0,   365,   369,   374,
       0,   372,   376,   381,   379,     0,   383,   388,   389,   392,
     391,   201,     0,     0,   110,     0,     0,     0,   100,   101,
     102,   103,    98,     0,     0,     0,   664,   663,   658,     0,
       0,   592,   425,     0,     0,     0,   460,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   394,
       0,     0,   176,     0,     0,     0,   166,   167,   168,   169,
     164,   111,   104,   106,   108,     0,   749,     0,     0,   680,
     573,     0,     0,     0,   611,     0,   431,     0,     0,     0,
     476,   255,   262,   269,   276,   283,     0,   304,     0,     0,
       0,   293,   294,   295,   296,   290,     0,   324,     0,     0,
       0,   313,   314,   315,   316,   310,     0,   344,     0,     0,
       0,   333,   334,   335,   336,   330,     0,   364,     0,     0,
       0,   353,   354,   355,   356,   350,   370,   377,   384,     0,
       0,   212,     0,     0,     0,   202,   203,   204,   205,   200,
     177,   170,   172,   174,     0,     0,     0,     0,     0,   661,
       0,     0,     0,   699,     0,   579,     0,     0,     0,     0,
       0,     0,   447,     0,     0,     0,   492,     0,     0,     0,
       0,     0,   303,   297,   299,   301,   323,   317,   319,   321,
     343,   337,   339,   341,   363,   357,   359,   361,     0,     0,
       0,     0,   405,     0,     0,     0,   395,   396,   397,   398,
     393,   213,   206,   208,   210,     0,     0,     0,   105,   107,
     109,   748,   746,   751,   750,     0,   667,     0,     0,     0,
       0,     0,     0,   595,   614,   574,   612,   615,   430,   429,
     434,   432,   435,     0,     0,     0,   463,     0,     0,     0,
     523,   256,   263,   270,   277,   284,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   371,   378,
     385,   406,   399,   401,   403,     0,     0,     0,   171,   173,
     175,   753,     0,     0,     0,   683,   702,   662,   700,   703,
     578,   577,   582,   580,   583,     0,     0,     0,     0,   446,
     450,   445,   448,   451,     0,     0,     0,   479,     0,     0,
       0,   298,   300,   302,   318,   320,   322,   338,   340,   342,
     358,   360,   362,     0,     0,     0,   207,   209,   211,     0,
     666,   665,   670,   668,   671,     0,     0,     0,     0,   594,
     598,   593,   596,   599,   638,     0,     0,     0,     0,     0,
       0,     0,   616,   617,   618,   619,   620,   621,   622,   623,
     613,     0,   443,     0,     0,   436,   437,   438,   433,     0,
     462,   466,   461,   464,   467,     0,     0,     0,   495,   526,
     426,   524,   527,   400,   402,   404,     0,   774,     0,     0,
       0,     0,     0,     0,   754,   755,   756,   757,   758,   759,
     760,   752,     0,   682,   686,   681,   684,   687,   726,     0,
       0,     0,     0,     0,     0,     0,   704,   705,   706,   707,
     708,   709,   710,   711,   701,     0,   591,     0,     0,   584,
     585,   586,   581,     0,     0,   629,   631,   633,     0,   625,
     627,   635,   442,     0,   440,     0,   459,     0,     0,   452,
     453,   454,   449,     0,   478,   482,   477,   480,   483,     0,
       0,     0,   773,   765,   767,   769,   761,   763,   771,     0,
     679,     0,     0,   672,   673,   674,   669,     0,     0,   717,
     719,   721,     0,   713,   715,   723,   590,     0,   588,     0,
     610,     0,     0,     0,   600,   601,   602,   603,   597,   637,
     641,   639,   642,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   458,     0,   456,     0,   475,     0,     0,   468,
     469,   470,   465,     0,   494,   493,   498,   496,   499,   550,
       0,     0,     0,     0,     0,     0,     0,   528,   529,   530,
     531,   532,   533,   534,   535,   525,     0,     0,     0,     0,
       0,     0,   678,     0,   676,     0,   698,     0,     0,     0,
     688,   689,   690,   691,   685,   725,   729,   727,   730,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   609,     0,
     605,   607,     0,   630,   632,   634,   624,   626,   628,   636,
     439,   441,     0,     0,   474,     0,   472,     0,   491,     0,
       0,   484,   485,   486,   481,     0,     0,   541,   543,   545,
       0,   537,   539,   547,   766,   768,   770,   762,   764,   772,
       0,     0,   697,     0,   693,   695,     0,   718,   720,   722,
     712,   714,   716,   724,   587,   589,     0,     0,     0,     0,
     656,     0,     0,     0,     0,   643,   644,   645,   646,   647,
     640,   455,   457,     0,     0,   490,     0,   488,   510,   509,
       0,     0,     0,   500,   501,   503,   502,   497,   549,   553,
     551,   554,     0,     0,     0,     0,     0,     0,     0,   675,
     677,     0,     0,     0,     0,   744,     0,     0,     0,     0,
     731,   732,   733,   734,   735,   728,   604,   606,   608,   655,
       0,   649,   651,   653,   471,   473,     0,     0,     0,     0,
       0,     0,     0,   542,   544,   546,   536,   538,   540,   548,
     692,   694,   696,   743,     0,   737,   739,   741,     0,     0,
       0,     0,   487,   489,   513,   508,   511,   514,     0,     0,
       0,     0,     0,   568,     0,     0,     0,     0,   555,   556,
     557,   558,   559,   552,     0,     0,     0,     0,   648,   650,
     652,   654,     0,   506,   505,   507,   504,   567,     0,   561,
     563,   565,   736,   738,   740,   742,     0,   522,     0,     0,
     515,   516,   517,   512,     0,     0,     0,     0,   521,     0,
     519,   560,   562,   564,   566,     0,     0,   518,   520
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
     522,   566,   567,   715,   568,   716,   569,   717,   570,    20,
      21,    31,    74,   127,   128,   129,   228,   379,   130,   131,
     230,   381,   382,   446,   521,   560,   645,   646,   775,   647,
     776,   648,   777,   649,    27,    28,    73,   123,   195,   196,
     197,   272,   410,   350,   198,   199,   275,   414,   200,   201,
     277,   416,   468,   677,   202,   203,   279,   418,   472,   678,
     204,   205,   281,   420,   476,   679,   206,   207,   283,   422,
     480,   680,   208,   209,   285,   424,   484,   681,   210,   211,
     287,   426,   488,   489,   552,   601,   602,   756,   603,   757,
     604,   758,   605,   212,   213,   289,   428,   493,   494,   553,
     611,   612,   759,   613,   760,   614,   761,   615,   214,   215,
     291,   430,   498,   499,   554,   621,   622,   762,   623,   763,
     624,   764,   625,   216,   217,   293,   432,   503,   504,   555,
     631,   632,   765,   633,   766,   634,   767,   635,   218,   219,
     295,   434,   508,   698,   220,   221,   297,   436,   512,   699,
     222,   223,   299,   438,   516,   700,   224,   225,   301,   440,
     441,   520,   559,   639,   706,   707,   823,   708,   824,   709,
     825,   710,    69,    70,   122,   174,   175,   176,   177,   178,
     265,   266,   267,   343,   406,   460,   544,   670,   741,   742,
     798,   865,   866,   867,  1011,   868,   546,   588,   744,   802,
     803,   869,   949,   950,   951,  1093,   952,   590,   674,   805,
     873,   874,   953,  1019,  1020,  1021,  1154,  1022,   676,   748,
     876,   957,   958,  1023,  1101,  1102,  1103,  1207,  1104,   750,
     809,   960,  1027,  1028,  1105,  1163,  1164,  1165,  1166,  1167,
    1208,  1236,  1237,  1262,  1280,  1281,  1282,  1296,  1283,   810,
     881,   882,   961,  1037,  1038,  1039,  1176,  1040,  1177,  1041,
    1172,  1042,  1173,  1043,  1174,  1044,  1178,  1045,  1106,  1170,
    1171,  1212,  1248,  1249,  1250,  1285,  1251,  1286,  1252,  1287,
    1253,   340,   341,   402,   457,   541,   582,   731,   793,   794,
     838,   929,   930,   931,  1077,   932,   584,   667,   796,   842,
     843,   933,   994,   995,   996,  1137,   997,  1138,   998,   668,
     736,   737,   797,   852,   853,   854,  1007,   855,  1008,   856,
    1003,   857,  1004,   858,  1005,   859,  1009,   860,   934,  1001,
    1002,  1082,  1145,  1146,  1147,  1229,  1148,  1230,  1149,  1231,
    1150,   399,   400,   453,   538,   579,   661,   783,   833,   834,
     902,   973,   974,   975,  1121,   976,   663,   728,   836,   906,
     907,   977,  1060,  1061,  1062,  1182,  1063,  1183,  1064,   729,
     788,   789,   837,   916,   917,   918,  1073,   919,  1074,   920,
    1069,   921,  1070,   922,  1071,   923,  1075,   924,   978,  1067,
    1068,  1126,  1190,  1191,  1192,  1255,  1193,  1256,  1194,  1257,
    1195,   450,   451,   534,   658,   724,   781,   829,   894,   895,
    1049,   896,  1050,   897,  1046,   898,  1047,   899,  1048,   900,
    1051,   901
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -79
static const yytype_int16 yypact[] =
{
      29,    61,    94,   163,   -79,   -79,    50,   -79,   -79,    90,
      60,   175,   -79,   -79,    62,   238,   -79,   -79,   -79,   -79,
      58,   257,   -79,   -79,   -79,   221,   -79,    68,   298,   -79,
     -79,   -79,   -25,   -79,   -79,   -79,   -79,   -79,   -79,   -79,
     -79,   -79,   -79,   -79,   -79,   -79,   -79,   310,   -79,   312,
     -79,   314,   -79,   101,   -79,   316,   -79,   318,   -79,   320,
     -79,   322,   -79,   324,   -79,   129,   -79,   132,   -79,   -79,
     -79,   -79,   -79,   -79,   -26,   -79,   -79,   -79,   -79,   -79,
     -79,   -79,   -79,   112,   -79,   114,   -79,   122,   -79,   326,
     -79,   135,    16,   -79,   -79,    33,   -79,   -79,    15,   -79,
     -79,   177,   328,    13,   -79,   -79,    17,   -79,   -79,    12,
     -79,   -79,    11,   -79,   -79,     7,   -79,   -79,   183,   330,
     186,   190,    23,     3,   -79,   -79,   -79,   -79,   -79,   332,
     -79,   188,   206,   334,   210,   336,   212,   338,    -1,   -79,
     -79,   217,   211,   -79,   -79,   -79,   -79,   -79,   -79,   -79,
     230,   -79,   -79,   -79,   -79,   -79,   -79,   -79,   -79,   -79,
     -79,   -79,   -79,   -79,   233,   -79,   -79,   236,   -79,   120,
     -79,   244,   249,   251,   -79,   -79,   -79,   -79,   -79,   -79,
     -79,   -79,   -79,   -79,   -79,   -79,   -79,   -79,   -79,   -79,
     -79,   -79,   -79,   -79,   -79,   -79,   -79,   207,   -79,   340,
     -79,   237,   -79,   250,   -79,   252,   -79,   254,   -79,   259,
     -79,   245,   -79,   256,   -79,   260,   -79,   262,   -79,   265,
     -79,   267,   -79,   235,   -79,   271,     1,   -79,   -79,   283,
     280,   -79,     4,   -79,   -79,   -79,     8,   -79,   -79,   -79,
       2,   -79,   -79,   -79,   -79,   287,   -79,   239,   241,   247,
     363,   -79,   240,   229,   317,   319,   315,   321,   378,   -79,
     308,   380,   -79,   273,   -79,   335,   253,   357,   386,   387,
     390,   393,   344,    -4,   -79,   -79,   391,   389,   392,   394,
     396,   397,   399,   400,   402,   403,   405,   406,   408,   409,
     411,   412,   414,   415,   417,   418,   420,   421,   423,   424,
     426,   427,   -79,   -79,   395,   -79,   429,   323,   329,   -79,
     430,   333,   339,   -79,   431,   343,   346,   -79,   347,   432,
     -79,   277,   -79,   -79,   -79,   -79,   -79,   -79,   -79,   -79,
     -79,   -79,   -79,   -79,   -79,   -79,   -79,   -79,   -79,   -79,
     292,   368,   434,   348,   435,   436,   437,   -79,    -3,   -79,
     -79,   -79,   -79,   440,   -79,   441,   -79,   442,   -79,   443,
     -79,   444,   -79,   445,   -79,   446,   -79,   447,   -79,   448,
     -79,   449,   -79,   450,   -79,   451,   -79,   452,   -79,   369,
     453,   -79,   281,   -79,   -79,   -79,   -79,   -79,   -79,   -79,
     -79,   -79,   -79,   -79,   -79,   -79,   -79,   -79,   -79,   269,
     373,   454,   352,   457,   337,   -79,   -79,   -79,   -79,   -79,
     458,   375,   377,   -79,   366,   460,   -30,   462,   -31,   463,
     263,   464,   -60,   465,    28,   466,   -64,   467,    18,   468,
     -73,   469,   -76,   470,   -70,   471,   -67,   472,   243,   473,
     -79,   289,   -79,   -79,   -79,   -79,   -79,   -79,   161,   -79,
     -79,   455,   474,   360,   459,   341,   -79,   -79,   477,   384,
     355,   -79,   -79,   -79,   -79,   -79,   478,   -79,   -79,   -79,
     -79,   479,   -79,   -79,   -79,   480,   -79,   -79,   481,   -79,
     -79,   -79,   482,   -79,   -79,   -79,   -79,   -79,   -79,   -79,
     -79,   -79,   -79,   -79,   -79,   -79,   -79,   -79,   -79,   -79,
     -79,   -79,   -79,   -79,   -79,   -79,   483,   -79,   -79,   -79,
     484,   -79,   -79,   -79,   -79,   485,   -79,   -79,   -79,   -79,
     -79,   -79,   169,   416,   -79,   410,   491,   493,   -79,   -79,
     -79,   -79,   -79,   490,   492,   494,   351,   -79,   -79,   495,
     475,   358,   -79,   496,   497,   486,   374,   503,   504,   505,
     506,   508,    27,   290,   293,   296,   509,   510,   511,   -79,
     182,   419,   -79,   513,   514,   515,   -79,   -79,   -79,   -79,
     -79,   -79,   -79,   -79,   -79,   517,   -79,   512,   487,   371,
     -79,   516,   518,   498,   -79,   522,   -79,   521,   523,   500,
     398,   -79,   -79,   -79,   -79,   -79,   433,   -79,   526,   527,
     530,   -79,   -79,   -79,   -79,   -79,   438,   -79,   534,   535,
     536,   -79,   -79,   -79,   -79,   -79,   439,   -79,   537,   540,
     541,   -79,   -79,   -79,   -79,   -79,   456,   -79,   542,   543,
     544,   -79,   -79,   -79,   -79,   -79,   -79,   -79,   -79,   192,
     476,   -79,   545,   546,   547,   -79,   -79,   -79,   -79,   -79,
     -79,   -79,   -79,   -79,   549,   550,   551,   553,   214,   -79,
     554,   555,   525,   -79,   548,   -79,   557,   558,   -66,   560,
     246,   563,   -79,   562,   564,   519,   461,   520,   488,   489,
     499,   501,   -79,   -79,   -79,   -79,   -79,   -79,   -79,   -79,
     -79,   -79,   -79,   -79,   -79,   -79,   -79,   -79,   502,   507,
     428,   528,   -79,   567,   568,   570,   -79,   -79,   -79,   -79,
     -79,   -79,   -79,   -79,   -79,   569,   571,   572,   -79,   -79,
     -79,   -79,   -79,   -79,   -79,   575,   -79,   574,   566,   -72,
     576,   232,   577,   -79,   -79,   -79,   -79,   -79,   -79,   -79,
     -79,   -79,   -79,   579,     9,   582,   -79,   581,   583,   524,
     -79,   -79,   -79,   -79,   -79,   -79,   585,   586,   587,   588,
     589,   591,   592,   594,   597,   598,   599,   602,   -79,   -79,
     -79,   -79,   -79,   -79,   -79,   603,   604,   605,   -79,   -79,
     -79,   -79,   606,   226,   609,   -79,   -79,   -79,   -79,   -79,
     -79,   -79,   -79,   -79,   -79,   608,    32,   108,   197,   -79,
     -79,   -79,   -79,   -79,   610,     6,   611,   -79,   612,   613,
     -55,   -79,   -79,   -79,   -79,   -79,   -79,   -79,   -79,   -79,
     -79,   -79,   -79,   615,   616,   617,   -79,   -79,   -79,   144,
     -79,   -79,   -79,   -79,   -79,   618,    -7,   151,   209,   -79,
     -79,   -79,   -79,   -79,   -79,   623,   624,   625,   622,   627,
     628,   629,   -79,   -79,   -79,   -79,   -79,   -79,   -79,   -79,
     -79,   529,   -79,   626,   631,   -79,   -79,   -79,   -79,   213,
     -79,   -79,   -79,   -79,   -79,   630,    30,   633,   -79,   -79,
     -79,   -79,   -79,   -79,   -79,   -79,   361,   -79,   632,   636,
     637,   638,   639,   640,   -79,   -79,   -79,   -79,   -79,   -79,
     -79,   -79,   218,   -79,   -79,   -79,   -79,   -79,   -79,   641,
     642,   643,   644,   645,   646,   647,   -79,   -79,   -79,   -79,
     -79,   -79,   -79,   -79,   -79,   531,   -79,   648,   649,   -79,
     -79,   -79,   -79,   116,   -61,   -79,   -79,   -79,   651,   -79,
     -79,   -79,   -79,   652,   -79,   532,   -79,   653,   650,   -79,
     -79,   -79,   -79,   223,   -79,   -79,   -79,   -79,   -79,   655,
     242,   173,   -79,   -79,   -79,   -79,   -79,   -79,   -79,   422,
     -79,   656,   661,   -79,   -79,   -79,   -79,   118,   -78,   -79,
     -79,   -79,   654,   -79,   -79,   -79,   -79,   660,   -79,   533,
     -79,   659,   664,   665,   -79,   -79,   -79,   -79,   -79,   -79,
     -79,   -79,   -79,   662,   663,   666,   667,   668,   670,   672,
     673,   674,   -79,   677,   -79,   556,   -79,   676,   669,   -79,
     -79,   -79,   -79,   231,   -79,   -79,   -79,   -79,   -79,   -79,
     681,   683,   684,   682,   685,   687,   688,   -79,   -79,   -79,
     -79,   -79,   -79,   -79,   -79,   -79,   686,   689,   690,   691,
     692,   693,   -79,   696,   -79,   539,   -79,   695,   700,   701,
     -79,   -79,   -79,   -79,   -79,   -79,   -79,   -79,   -79,   698,
     699,   702,   703,   704,   705,   706,   707,   708,   -79,   711,
     -79,   -79,    19,   -79,   -79,   -79,   -79,   -79,   -79,   -79,
     -79,   -79,   710,   712,   -79,   713,   -79,   565,   -79,   714,
     717,   -79,   -79,   -79,   -79,   220,   -57,   -79,   -79,   -79,
     718,   -79,   -79,   -79,   -79,   -79,   -79,   -79,   -79,   -79,
     715,   719,   -79,   720,   -79,   -79,    59,   -79,   -79,   -79,
     -79,   -79,   -79,   -79,   -79,   -79,   721,   722,   723,   578,
     -79,   724,   729,   730,   731,   -79,   -79,   -79,   -79,   -79,
     -79,   -79,   -79,   728,   732,   -79,   733,   -79,   -79,   -79,
     734,   735,   736,   -79,   -79,   -79,   -79,   -79,   -79,   -79,
     -79,   -79,   737,   738,   739,   740,   741,   742,   743,   -79,
     -79,   744,   745,   746,   584,   -79,   747,   752,   753,   754,
     -79,   -79,   -79,   -79,   -79,   -79,   -79,   -79,   -79,   -79,
     755,   -79,   -79,   -79,   -79,   -79,   751,   756,   -10,   376,
     757,   759,    97,   -79,   -79,   -79,   -79,   -79,   -79,   -79,
     -79,   -79,   -79,   -79,   760,   -79,   -79,   -79,   761,   762,
     763,   764,   -79,   -79,   -79,   -79,   -79,   -79,   765,   766,
     767,   768,   595,   -79,   769,   758,   774,   775,   -79,   -79,
     -79,   -79,   -79,   -79,   772,   773,   776,   777,   -79,   -79,
     -79,   -79,   234,   -79,   -79,   -79,   -79,   -79,   780,   -79,
     -79,   -79,   -79,   -79,   -79,   -79,   607,   -79,   779,   778,
     -79,   -79,   -79,   -79,   781,   782,   783,   784,   -79,   787,
     -79,   -79,   -79,   -79,   -79,   786,   788,   -79,   -79
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -79,   -79,   -79,   -79,   -79,   -79,   -79,   -79,   -79,   -79,
     -79,   -79,   -79,   -79,   -79,   -79,   -79,   -79,   -79,   -79,
     -79,   -79,   -79,   -79,   -79,   -79,   -79,   -79,   -79,   -79,
     -79,   -79,   -79,   -79,   -79,   -79,   -79,   -79,   -79,   -79,
     -79,   -79,   -79,   -79,   -79,   -79,   -79,   -79,   -79,   -79,
     -79,   -79,   -79,   -79,   -79,   -79,   -79,   -79,   -79,   -79,
     -79,   -79,   -79,   -79,   -79,   -79,   -79,   -79,   -79,   -79,
     -79,   -79,   -79,   -79,   -79,   -79,   -79,   -79,   -79,   -79,
     -79,   -79,   -79,   -79,   -79,   -79,   -79,   -79,   -79,   -79,
     -79,   -79,   -79,   -79,   -79,   -79,   -79,   -79,   -79,   -79,
     -79,   -79,   -79,   -79,   -79,   -79,   -79,   -79,   -79,   -79,
     -79,   -79,   -79,   -79,   -79,   -79,   -79,   -79,   -79,   -79,
     -79,   -79,   -79,   -79,   -79,   -79,   -79,   -79,   -79,   -79,
     -79,   -79,   -79,   -79,   -79,   -79,   -79,   -79,   -79,   -79,
     -79,   -79,   -79,   -79,   -79,   -79,   -79,   -79,   -79,   -79,
     -79,   -79,   -79,   -79,   -79,   -79,   -79,   -79,   -79,   -79,
     -79,   -79,   -79,   -79,   -79,   -79,   -79,   -79,   -79,   -79,
     -79,   -79,   -79,   -79,   -79,   -79,   -79,   -79,   -79,   -79,
     -79,   -79,   -79,   -79,   -79,   -79,   -79,   -79,   -79,   -79,
     -79,   -79,   -79,   -79,   -79,   -79,   -79,   -79,   -79,   -79,
     -79,   -79,   -79,   -79,   -79,   -79,   -79,   -79,   -79,   -79,
     -79,   -79,   -79,   -79,   -79,   -79,   -79,   -79,   -79,   -79,
     -79,   -79,   -79,   -79,   -79,   -79,   -79,   -79,   -79,   -79,
     -79,   -79,   -79,   -79,   -79,   -79,   -79,   -79,   -79,   -79,
     -79,   -79,   -79,   -79,   -79,   -79,   -79,   -79,   -79,   -79,
     -79,   -79,   -79,   -79,   -79,   -79,   -79,   -79,   -79,   -79,
     -79,   -79,   -79,   -79,   -79,   -79,   -79,   -79,   -79,   -79,
     -79,   -79,   -79,   -79,   -79,   -79,   -79,   -79,   -79,   -79,
     -79,   -79,   -79,   -79,   -79,   -79,   -79,   -79,   -79,   -79,
     -79,   -79,   -79,   -79,   -79,   -79,   -79,   -79,   -79,   -79,
     -79,   -79,   -79,   -79,   -79,   -79,   -79,   -79,   -79,   -79,
     -79,   -79,   -79,   -79,   -79,   -79,   -79,   -79,   -79,   -79,
     -79,   -79,   -79,   -79,   -79,   -79,   -79,   -79,   -79,   -79,
     -79,   -79,   -79,   -79,   -79,   -79,   -79,   -79,   -79,   -79,
     -79,   -79,   -79,   -79,   -79,   -79,   -79,   -79,   -79,   -79,
     -79,   -79,   -79,   -79,   -79,   -79,   -79,   -79,   -79,   -79,
     -79,   -79,   -79,   -79,   -79,   -79,   -79,   -79,   -79,   -79,
     -79,   -79,   -79,   -79,   -79,   -79,   -79,   -79,   -79,   -79,
     -79,   -79,   -79,   -79,   -79,   -79,   -79,   -79,   -79,   -79,
     -79,   -79,   -79,   -79,   -79,   -79,   -79,   -79,   -79,   -79,
     -79,   -79,   -79,   -79,   -79,   -79,   -79,   -79,   -79,   -79,
     -79,   -79,   -79,   -79,   -79,   -79,   -79,   -79,   -79,   -79,
     -79,   -79,   -79,   -79,   -79,   -79,   -79,   -79,   -79,   -79,
     -79,   -79,   -79,   -79,   -79,   -79,   -79,   -79,   -79,   -79,
     -79,   -79,   -79,   -79,   -79,   -79,   -79,   -79,   -79,   -79,
     -79,   -79,   -79,   -79,   -79,   -79,   -79,   -79,   -79,   -79,
     -79,   -79,   -79,   -79,   -79,   -79,   -79,   -79,   -79,   -79,
     -79,   -79,   -79,   -79,   -79,   -79,   -79,   -79,   -79,   -79,
     -79,   -79,   -79,   -79,   -79,   -79,   -79,   -79,   -79,   -79,
     -79,   -79,   -79,   -79,   -79,   -79,   -79,   -79,   -79,   -79,
     -79,   -79,   -79,   -79,   -79,   -79,   -79,   -79,   -79,   -79,
     -79,   -79,   -79,   -79,   -79,   -79,   -79,   -79,   -79,   -79,
     -79,   -79
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint16 yytable[] =
{
     351,  1065,   411,   412,   243,   302,   786,   315,   316,   307,
     308,   161,   734,   311,   312,   159,   157,   153,   999,   147,
     143,   155,  1168,   879,    75,   124,   501,  1139,  1140,   496,
     506,   169,   170,   510,   466,   596,   597,   145,   486,     1,
     478,   507,   511,   502,   497,   479,   598,   599,   600,   487,
     125,    76,   171,   172,   173,    77,   179,    78,  1141,    79,
    1142,    80,   126,  1143,  1144,   467,   470,  1184,  1185,   471,
     880,  1169,     4,   144,  1066,   735,   148,   787,   154,   180,
     162,   158,   160,  1000,   156,   309,   244,   317,   413,   352,
     303,   313,   146,   181,     5,   182,     8,   183,  1186,   184,
    1187,   185,    12,  1188,  1189,  1242,  1243,   186,    13,   187,
      26,   188,    19,   189,   101,   190,   844,   191,  1234,   192,
     491,   193,    68,   194,   989,   990,  1055,  1056,   482,  1235,
     845,   846,   847,   492,   871,   483,  1244,   800,  1245,   872,
     801,  1246,  1247,   118,   848,   904,   849,   120,   905,   850,
     141,   851,   886,   887,   132,   991,   134,  1057,   955,   908,
     992,   993,  1058,  1059,   136,   956,   888,   889,   890,   523,
     524,     6,     7,   909,   910,   911,   840,   561,   562,   841,
     149,  1029,   891,    16,    17,   892,   163,   893,   912,   913,
     640,   641,   914,   167,   915,  1030,  1031,  1032,   168,   525,
     701,   702,   526,   229,   527,   861,   862,   563,  1033,   231,
     564,  1034,   565,   235,  1035,   239,  1036,   925,   926,   246,
     642,   945,   946,   643,   245,   644,   969,   970,  1158,  1159,
     703,  1015,  1016,   704,   251,   705,   863,   259,   864,  1097,
    1098,   261,  1276,  1277,   264,  1160,    22,    23,   927,   271,
     928,   268,   947,   276,   948,  1161,   269,   971,   270,   972,
    1162,   298,  1017,   286,  1018,    29,    30,   278,    33,   280,
    1099,   282,  1100,  1278,   288,  1279,   284,    34,   290,    35,
     292,    36,   294,    37,   296,    38,   300,    39,   305,    40,
     304,    41,   319,    42,   327,    43,   322,    44,   606,   607,
     323,   616,   617,   326,   626,   627,    71,    72,   324,   608,
     609,   610,   618,   619,   620,   628,   629,   630,    92,    93,
      95,    96,    98,    99,   103,   104,   106,   107,   109,   110,
     112,   113,   115,   116,   138,   139,   150,   151,   164,   165,
     226,   227,   232,   233,   236,   237,   240,   241,   273,   274,
     335,   336,   348,   349,   394,   395,   404,   405,   444,   445,
     455,   456,   474,   475,   514,   515,   518,   519,   536,   537,
     325,   722,   723,   739,   740,   791,   792,   831,   832,  1025,
    1026,  1238,  1239,   333,   328,   332,   330,   334,   329,   342,
     338,   344,   345,   339,   331,   346,   347,   354,   353,   355,
     380,   401,   356,   357,   384,   358,   359,   452,   360,   361,
     385,   362,   363,   572,   364,   365,   387,   366,   367,   543,
     368,   369,   388,   370,   371,   449,   372,   373,   390,   374,
     375,   391,   376,   377,   392,   378,   383,   386,   389,   393,
     398,   403,   407,   408,   409,   415,   417,   419,   421,   423,
     425,   427,   429,   431,   433,   435,   437,   439,   442,   464,
     443,   454,   458,   459,   539,   461,   462,   465,   463,   469,
     473,   477,   481,   485,   490,   495,   500,   505,   509,   513,
     517,   535,   533,   540,   542,   545,   547,   548,   549,   550,
     551,   556,   557,   558,   573,   571,   574,   575,   650,   577,
     576,   578,   580,   585,   583,   586,   589,   591,   592,   593,
     594,   581,   595,   636,   637,   638,   651,   652,   653,   659,
     962,   587,   657,   664,   660,   662,   665,   669,   671,   683,
     684,   672,   675,   685,   666,   673,   682,   687,   688,   689,
     691,   686,   690,   692,   693,   695,   696,   697,   712,   713,
     714,   770,   808,   730,   747,   711,   718,   719,   720,   694,
     721,   725,   727,   726,   732,     0,   733,   738,   743,   745,
     772,   773,   746,   774,   785,  1052,   778,     0,   779,   780,
     782,   784,   795,   790,     0,   751,   799,   804,   806,   752,
     753,   807,   811,   812,   813,   814,   815,   749,   816,   817,
     754,   818,   755,   768,   819,   820,   821,   771,   769,   822,
     826,   827,   828,   830,   835,   839,   875,   870,     0,   877,
       0,   878,   883,   884,   885,   903,   935,   936,   937,   938,
     939,   940,   941,   943,   944,   963,     0,   954,   959,   964,
     965,   966,   967,   968,   979,   980,   981,     0,   983,   984,
     985,   982,   988,  1014,     0,   987,  1006,  1010,   942,  1072,
    1013,  1012,  1024,  1053,  1054,  1076,  1079,  1080,  1081,  1083,
    1084,     0,  1096,  1085,  1086,  1087,   986,  1088,  1078,  1089,
    1090,  1091,  1092,  1095,  1107,  1094,  1108,  1109,  1111,  1110,
    1112,  1113,  1122,  1114,  1155,     0,  1115,  1116,  1117,  1118,
    1119,  1120,  1123,  1124,  1125,  1127,  1128,  1199,     0,  1129,
    1130,  1131,  1132,  1133,  1134,  1135,  1136,  1151,  1153,  1152,
    1157,  1156,  1179,  1175,  1267,  1181,  1180,     0,  1196,  1197,
    1198,  1200,  1201,  1202,  1203,  1204,  1288,  1223,  1206,  1205,
       0,  1209,  1210,  1211,  1213,  1214,  1215,  1216,  1217,  1218,
    1219,  1220,  1221,  1222,  1224,  1225,  1226,  1227,  1232,     0,
    1228,  1269,  1240,  1233,  1241,  1254,     0,     0,  1258,  1259,
    1260,  1261,  1263,  1264,  1265,  1266,  1268,  1270,  1271,  1272,
    1273,  1290,     0,  1274,  1275,  1284,  1289,     0,  1291,  1292,
    1293,  1294,  1295,  1297,     0,  1298
};

static const yytype_int16 yycheck[] =
{
       4,    79,     5,     6,     5,     4,    78,     5,     6,     5,
       6,     4,    78,     5,     6,     4,     4,     4,    79,     4,
       4,     4,    79,    78,    49,    51,   102,     8,     9,   102,
     100,     8,     9,   100,    64,     8,     9,     4,   102,    10,
     100,   111,   109,   119,   117,   105,    19,    20,    21,   113,
      76,    76,    29,    30,    31,    80,    53,    82,    39,    84,
      41,    86,    88,    44,    45,    95,    97,     8,     9,   100,
     125,   128,    11,    57,   152,   141,    61,   149,    65,    76,
      73,    69,    71,   144,    67,    81,    87,    85,    91,    93,
      89,    83,    59,    90,     0,    92,    46,    94,    39,    96,
      41,    98,    12,    44,    45,     8,     9,   104,    48,   106,
      52,   108,    50,   110,    13,   112,     8,   114,   128,   116,
     102,   118,    54,   120,     8,     9,     8,     9,   100,   139,
      22,    23,    24,   115,   128,   107,    39,   128,    41,   133,
     131,    44,    45,    14,    36,   152,    38,    15,   155,    41,
      15,    43,     8,     9,    42,    39,    42,    39,   128,     8,
      44,    45,    44,    45,    42,   135,    22,    23,    24,     8,
       9,     8,     9,    22,    23,    24,   144,     8,     9,   147,
       3,     8,    38,     8,     9,    41,     3,    43,    37,    38,
       8,     9,    41,     7,    43,    22,    23,    24,     8,    38,
       8,     9,    41,    15,    43,     8,     9,    38,    35,     3,
      41,    38,    43,     3,    41,     3,    43,     8,     9,     8,
      38,     8,     9,    41,     7,    43,     8,     9,     8,     9,
      38,     8,     9,    41,     4,    43,    39,     4,    41,     8,
       9,     5,     8,     9,   124,    25,     8,     9,    39,    42,
      41,     7,    39,    16,    41,    35,     7,    39,     7,    41,
      40,    26,    39,    18,    41,     8,     9,    17,    47,    17,
      39,    17,    41,    39,    18,    41,    17,    56,    18,    58,
      18,    60,    17,    62,    17,    64,    15,    66,     8,    68,
       7,    70,     5,    72,    65,    74,    57,    76,     8,     9,
      59,     8,     9,    63,     8,     9,     8,     9,    61,    19,
      20,    21,    19,    20,    21,    19,    20,    21,     8,     9,
       8,     9,     8,     9,     8,     9,     8,     9,     8,     9,
       8,     9,     8,     9,     8,     9,     8,     9,     8,     9,
       8,     9,     8,     9,     8,     9,     8,     9,     8,     9,
      77,    78,     8,     9,    77,    78,     8,     9,    77,    78,
       8,     9,    99,   100,   121,   122,    77,    78,     8,     9,
       7,   157,   158,   127,   128,   143,   144,   151,   152,   137,
     138,     5,     6,    75,    67,     7,    71,     7,    69,    32,
      55,     5,     5,   140,    73,     5,     3,     8,     7,     7,
       5,    33,     8,     7,    81,     8,     7,    34,     8,     7,
      81,     8,     7,     3,     8,     7,    83,     8,     7,    35,
       8,     7,    83,     8,     7,   156,     8,     7,    85,     8,
       7,    85,     8,     7,    87,     8,     7,     7,     7,     7,
     148,     7,     7,     7,     7,     5,     5,     5,     5,     5,
       5,     5,     5,     5,     5,     5,     5,     5,    89,    93,
       7,     7,     5,   126,     5,     7,    91,     7,    91,     7,
       7,     7,     7,     7,     7,     7,     7,     7,     7,     7,
       7,     7,    27,   142,     7,   130,     8,     8,     8,     8,
       8,     8,     8,     8,     3,    79,     3,     7,    79,     5,
       8,   150,     7,     7,   146,     8,   132,     4,     4,     4,
       4,    36,     4,     4,     4,     4,     3,     3,     3,     7,
     159,    35,     5,     7,    37,   154,     8,     5,     7,     3,
       3,     8,   134,     3,    36,    35,   103,     3,     3,     3,
       3,   103,   103,     3,     3,     3,     3,     3,     3,     3,
       3,   123,    28,     5,    35,    79,     7,     7,     7,   103,
       7,     7,    37,     8,     7,    -1,     8,     7,     5,     7,
       3,     3,     8,     3,     8,   153,     7,    -1,     7,     7,
       5,     7,     5,     7,    -1,    65,     7,     5,     7,   101,
     101,     8,     7,     7,     7,     7,     7,   136,     7,     7,
     101,     7,   101,   101,     7,     7,     7,    79,   101,     7,
       7,     7,     7,     7,     5,     7,     5,     7,    -1,     7,
      -1,     8,     7,     7,     7,     7,     3,     3,     3,     7,
       3,     3,     3,     7,     3,     3,    -1,     7,     5,     3,
       3,     3,     3,     3,     3,     3,     3,    -1,     3,     3,
       3,     7,     3,     3,    -1,     7,     5,     5,   129,     5,
       7,   129,     7,     7,     3,     5,     7,     3,     3,     7,
       7,    -1,     3,     7,     7,     7,   145,     7,   145,     7,
       7,     7,     5,     7,     3,   129,     3,     3,     3,     7,
       3,     3,   153,     7,   129,    -1,     7,     7,     7,     7,
       7,     5,     7,     3,     3,     7,     7,   129,    -1,     7,
       7,     7,     7,     7,     7,     7,     5,     7,     5,     7,
       3,     7,     7,     5,   129,     5,     7,    -1,     7,     7,
       7,     7,     3,     3,     3,     7,   129,   153,     5,     7,
      -1,     7,     7,     7,     7,     7,     7,     7,     7,     7,
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
       0,    10,   162,   163,    11,     0,     8,     9,    46,   164,
     165,   166,    12,    48,   230,   231,     8,     9,   167,    50,
     270,   271,     8,     9,   232,   168,    52,   295,   296,     8,
       9,   272,   233,    47,    56,    58,    60,    62,    64,    66,
      68,    70,    72,    74,    76,   169,   170,   171,   174,   175,
     178,   179,   182,   183,   188,   189,   192,   193,   196,   197,
     200,   201,   204,   205,   208,   209,   214,   215,    54,   433,
     434,     8,     9,   297,   273,    49,    76,    80,    82,    84,
      86,   234,   235,   236,   240,   241,   245,   246,   250,   251,
     254,   255,     8,     9,   172,     8,     9,   176,     8,     9,
     180,    13,   184,     8,     9,   190,     8,     9,   194,     8,
       9,   198,     8,     9,   202,     8,     9,   206,    14,   210,
      15,   216,   435,   298,    51,    76,    88,   274,   275,   276,
     279,   280,    42,   237,    42,   242,    42,   247,     8,     9,
     252,    15,   256,     4,    57,     4,    59,     4,    61,     3,
       8,     9,   186,     4,    65,     4,    67,     4,    69,     4,
      71,     4,    73,     3,     8,     9,   212,     7,     8,     8,
       9,    29,    30,    31,   436,   437,   438,   439,   440,    53,
      76,    90,    92,    94,    96,    98,   104,   106,   108,   110,
     112,   114,   116,   118,   120,   299,   300,   301,   305,   306,
     309,   310,   315,   316,   321,   322,   327,   328,   333,   334,
     339,   340,   354,   355,   369,   370,   384,   385,   399,   400,
     405,   406,   411,   412,   417,   418,     8,     9,   277,    15,
     281,     3,     8,     9,   239,     3,     8,     9,   244,     3,
       8,     9,   249,     5,    87,     7,     8,   173,   177,   181,
     185,     4,   187,   191,   195,   199,   203,   207,   211,     4,
     213,     5,   217,   218,   124,   441,   442,   443,     7,     7,
       7,    42,   302,     8,     9,   307,    16,   311,    17,   317,
      17,   323,    17,   329,    17,   335,    18,   341,    18,   356,
      18,   371,    18,   386,    17,   401,    17,   407,    26,   413,
      15,   419,     4,    89,     7,     8,   238,     5,     6,    81,
     243,     5,     6,    83,   248,     5,     6,    85,   253,     5,
     257,   258,    57,    59,    61,     7,    63,    65,    67,    69,
      71,    73,     7,    75,     7,    77,    78,   219,    55,   140,
     542,   543,    32,   444,     5,     5,     5,     3,     8,     9,
     304,     4,    93,     7,     8,     7,     8,     7,     8,     7,
       8,     7,     8,     7,     8,     7,     8,     7,     8,     7,
       8,     7,     8,     7,     8,     7,     8,     7,     8,   278,
       5,   282,   283,     7,    81,    81,     7,    83,    83,     7,
      85,    85,    87,     7,    77,    78,   259,   220,   148,   602,
     603,    33,   544,     7,     8,     9,   445,     7,     7,     7,
     303,     5,     6,    91,   308,     5,   312,     5,   318,     5,
     324,     5,   330,     5,   336,     5,   342,     5,   357,     5,
     372,     5,   387,     5,   402,     5,   408,     5,   414,     5,
     420,   421,    89,     7,    77,    78,   284,   260,   221,   156,
     662,   663,    34,   604,     7,     8,     9,   545,     5,   126,
     446,     7,    91,    91,    93,     7,    64,    95,   313,     7,
      97,   100,   319,     7,    99,   100,   325,     7,   100,   105,
     331,     7,   100,   107,   337,     7,   102,   113,   343,   344,
       7,   102,   115,   358,   359,     7,   102,   117,   373,   374,
       7,   102,   119,   388,   389,     7,   100,   111,   403,     7,
     100,   109,   409,     7,   121,   122,   415,     7,    77,    78,
     422,   285,   261,     8,     9,    38,    41,    43,   222,   223,
     225,   227,   229,    27,   664,     7,     8,     9,   605,     5,
     142,   546,     7,    35,   447,   130,   457,     8,     8,     8,
       8,     8,   345,   360,   375,   390,     8,     8,     8,   423,
     286,     8,     9,    38,    41,    43,   262,   263,   265,   267,
     269,    79,     3,     3,     3,     7,     8,     5,   150,   606,
       7,    36,   547,   146,   557,     7,     8,    35,   458,   132,
     468,     4,     4,     4,     4,     4,     8,     9,    19,    20,
      21,   346,   347,   349,   351,   353,     8,     9,    19,    20,
      21,   361,   362,   364,   366,   368,     8,     9,    19,    20,
      21,   376,   377,   379,   381,   383,     8,     9,    19,    20,
      21,   391,   392,   394,   396,   398,     4,     4,     4,   424,
       8,     9,    38,    41,    43,   287,   288,   290,   292,   294,
      79,     3,     3,     3,   224,   226,   228,     5,   665,     7,
      37,   607,   154,   617,     7,     8,    36,   558,   570,     5,
     448,     7,     8,    35,   469,   134,   479,   314,   320,   326,
     332,   338,   103,     3,     3,     3,   103,     3,     3,     3,
     103,     3,     3,     3,   103,     3,     3,     3,   404,   410,
     416,     8,     9,    38,    41,    43,   425,   426,   428,   430,
     432,    79,     3,     3,     3,   264,   266,   268,     7,     7,
       7,     7,   157,   158,   666,     7,     8,    37,   618,   630,
       5,   548,     7,     8,    78,   141,   571,   572,     7,   127,
     128,   449,   450,     5,   459,     7,     8,    35,   480,   136,
     490,    65,   101,   101,   101,   101,   348,   350,   352,   363,
     365,   367,   378,   380,   382,   393,   395,   397,   101,   101,
     123,    79,     3,     3,     3,   289,   291,   293,     7,     7,
       7,   667,     5,   608,     7,     8,    78,   149,   631,   632,
       7,   143,   144,   549,   550,     5,   559,   573,   451,     7,
     128,   131,   460,   461,     5,   470,     7,     8,    28,   491,
     510,     7,     7,     7,     7,     7,     7,     7,     7,     7,
       7,     7,     7,   427,   429,   431,     7,     7,     7,   668,
       7,   151,   152,   609,   610,     5,   619,   633,   551,     7,
     144,   147,   560,   561,     8,    22,    23,    24,    36,    38,
      41,    43,   574,   575,   576,   578,   580,   582,   584,   586,
     588,     8,     9,    39,    41,   452,   453,   454,   456,   462,
       7,   128,   133,   471,   472,     5,   481,     7,     8,    78,
     125,   511,   512,     7,     7,     7,     8,     9,    22,    23,
      24,    38,    41,    43,   669,   670,   672,   674,   676,   678,
     680,   682,   611,     7,   152,   155,   620,   621,     8,    22,
      23,    24,    37,    38,    41,    43,   634,   635,   636,   638,
     640,   642,   644,   646,   648,     8,     9,    39,    41,   552,
     553,   554,   556,   562,   589,     3,     3,     3,     7,     3,
       3,     3,   129,     7,     3,     8,     9,    39,    41,   463,
     464,   465,   467,   473,     7,   128,   135,   482,   483,     5,
     492,   513,   159,     3,     3,     3,     3,     3,     3,     8,
       9,    39,    41,   612,   613,   614,   616,   622,   649,     3,
       3,     3,     7,     3,     3,     3,   145,     7,     3,     8,
       9,    39,    44,    45,   563,   564,   565,   567,   569,    79,
     144,   590,   591,   581,   583,   585,     5,   577,   579,   587,
       5,   455,   129,     7,     3,     8,     9,    39,    41,   474,
     475,   476,   478,   484,     7,   137,   138,   493,   494,     8,
      22,    23,    24,    35,    38,    41,    43,   514,   515,   516,
     518,   520,   522,   524,   526,   528,   675,   677,   679,   671,
     673,   681,   153,     7,     3,     8,     9,    39,    44,    45,
     623,   624,   625,   627,   629,    79,   152,   650,   651,   641,
     643,   645,     5,   637,   639,   647,     5,   555,   145,     7,
       3,     3,   592,     7,     7,     7,     7,     7,     7,     7,
       7,     7,     5,   466,   129,     7,     3,     8,     9,    39,
      41,   485,   486,   487,   489,   495,   529,     3,     3,     3,
       7,     3,     3,     3,     7,     7,     7,     7,     7,     7,
       5,   615,   153,     7,     3,     3,   652,     7,     7,     7,
       7,     7,     7,     7,     7,     7,     5,   566,   568,     8,
       9,    39,    41,    44,    45,   593,   594,   595,   597,   599,
     601,     7,     7,     5,   477,   129,     7,     3,     8,     9,
      25,    35,    40,   496,   497,   498,   499,   500,    79,   128,
     530,   531,   521,   523,   525,     5,   517,   519,   527,     7,
       7,     5,   626,   628,     8,     9,    39,    41,    44,    45,
     653,   654,   655,   657,   659,   661,     7,     7,     7,   129,
       7,     3,     3,     3,     7,     7,     5,   488,   501,     7,
       7,     7,   532,     7,     7,     7,     7,     7,     7,     7,
       7,     7,     7,   153,     7,     3,     3,     3,     5,   596,
     598,   600,     7,     7,   128,   139,   502,   503,     5,     6,
       5,     5,     8,     9,    39,    41,    44,    45,   533,   534,
     535,   537,   539,   541,     5,   656,   658,   660,     7,     7,
       7,     7,   504,     7,     7,     7,     7,   129,     7,     3,
       3,     3,     7,     7,     7,     7,     8,     9,    39,    41,
     505,   506,   507,   509,     5,   536,   538,   540,   129,     7,
       3,     7,     7,     7,     7,     5,   508,     7,     7
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

    {	if (parserData->filesToMakePresent)
	{	osolerror( NULL, osoption, parserData, "only one <filesToMake> element allowed");
	}
	else
	{	parserData->filesToMakePresent = true;
		osoption->job->filesToMake = new DirectoriesAndFiles();
	}
;}
    break;

  case 280:

    {	if ((yyvsp[(3) - (4)].ival) < 0)
		osolerror( NULL, osoption, parserData, "Number of paths cannot be negative");
	osoption->job->filesToMake->numberOfPaths = (yyvsp[(3) - (4)].ival);
	osoption->job->filesToMake->path = new std::string[(yyvsp[(3) - (4)].ival)];
;}
    break;

  case 283:

    {	if (parserData->numberOfFilesToMake >= osoption->job->filesToMake->numberOfPaths)
	{	osolerror (NULL, osoption, parserData, "too many job IDs in <filesToMake> element");
	}
	else
	{	osoption->job->filesToMake->path[parserData->numberOfFilesToMake] = (yyvsp[(3) - (3)].sval);
		parserData->numberOfFilesToMake++;
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
	osoption->optimization->variables->initialVariableValuesString = new InitVariableValuesString();
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

  case 460:

    {printf("initial basis empty\n");;}
    break;

  case 462:

    {	if ((yyvsp[(3) - (4)].ival) <= 0)
		osolerror (NULL, osoption, parserData, "number of <var> elements must be positive");
	osoption->optimization->variables->initialBasisStatus = new InitialBasisStatus();
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
	parserData->numberOfBasVar++;
;}
    break;

  case 466:

    {	if (parserData->numberOfBasVar >= osoption->optimization->variables->initialBasisStatus->numberOfVar)
		osolerror(NULL, osoption, parserData, "too many initial basis variables");
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

  case 478:

    {	if ((yyvsp[(3) - (4)].ival) <= 0)
		osolerror (NULL, osoption, parserData, "number of <var> elements must be positive");
	osoption->optimization->variables->integerVariableBranchingWeights = new IntegerVariableBranchingWeights();
	osoption->optimization->variables->integerVariableBranchingWeights->numberOfVar = (yyvsp[(3) - (4)].ival);
	osoption->optimization->variables->integerVariableBranchingWeights->var = new BranchingWeight*[(yyvsp[(3) - (4)].ival)];
	for (int i = 0; i < (yyvsp[(3) - (4)].ival); i++)
		osoption->optimization->variables->integerVariableBranchingWeights->var[i] = new BranchingWeight();
;}
    break;

  case 481:

    {	if (!parserData->idxAttributePresent)
		osolerror (NULL, osoption, parserData, "variable index required");
	parserData->idxAttributePresent = false;
	parserData->valAttributePresent = false;
	parserData->numberOfIntWt++;
;}
    break;

  case 482:

    {	if (parserData->numberOfIntWt >= osoption->optimization->variables->integerVariableBranchingWeights->numberOfVar)
		osolerror(NULL, osoption, parserData, "too many integer branching weights");
;}
    break;

  case 487:

    {	if (parserData->idxAttributePresent)
		osolerror (NULL, osoption, parserData, "only one variable index allowed");
	parserData->idxAttributePresent = true;
	if ((yyvsp[(3) - (4)].ival) < 0)
		osolerror (NULL, osoption, parserData, "variable index must be nonnegative");
	if (parserData->numberOfVariablesPresent)
	{	if ((yyvsp[(3) - (4)].ival) >= parserData->numberOfVariables)
			osolerror (NULL, osoption, parserData, "variable index exceeds upper limit");
	};
	osoption->optimization->variables->integerVariableBranchingWeights->var[parserData->numberOfIntWt]->idx = (yyvsp[(3) - (4)].ival);
;}
    break;

  case 488:

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

  case 494:

    {	if ((yyvsp[(3) - (4)].ival) <= 0)
		osolerror (NULL, osoption, parserData, "number of <sos> elements must be positive");
	osoption->optimization->variables->sosVariableBranchingWeights = new SOSVariableBranchingWeights();
	osoption->optimization->variables->sosVariableBranchingWeights->numberOfSOS = (yyvsp[(3) - (4)].ival);
	osoption->optimization->variables->sosVariableBranchingWeights->sos = new SOSWeights*[(yyvsp[(3) - (4)].ival)];
	for (int i = 0; i < (yyvsp[(3) - (4)].ival); i++)
		osoption->optimization->variables->sosVariableBranchingWeights->sos[i] = new SOSWeights();
;}
    break;

  case 497:

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

  case 498:

    {	if (parserData->numberOfSOS >= osoption->optimization->variables->sosVariableBranchingWeights->numberOfSOS)
		osolerror(NULL, osoption, parserData, "too many SOS branching weights");
;}
    break;

  case 504:

    {	if (parserData->sosIdxAttributePresent)
		osolerror (NULL, osoption, parserData, "only one SOS index allowed");
	parserData->sosIdxAttributePresent = true;
	printf("SOS index found:%d\n",(yyvsp[(3) - (4)].ival));
	if ((yyvsp[(3) - (4)].ival) < 0)
		osolerror (NULL, osoption, parserData, "SOS index must be nonnegative");
	printf("store into %d:%d\n",parserData->numberOfSOS,(yyvsp[(3) - (4)].ival));
	osoption->optimization->variables->sosVariableBranchingWeights->sos[parserData->numberOfSOS]->sosIdx = (yyvsp[(3) - (4)].ival);
	printf(" Check:%d\n",osoption->optimization->variables->sosVariableBranchingWeights->sos[parserData->numberOfSOS]->sosIdx);
;}
    break;

  case 505:

    {	if (parserData->grpWgtAttributePresent)
		osolerror (NULL, osoption, parserData, "only one group weight allowed");
	parserData->grpWgtAttributePresent = true;
	osoption->optimization->variables->sosVariableBranchingWeights->sos[parserData->numberOfSOS]->groupWeight = (yyvsp[(3) - (4)].dval);
;}
    break;

  case 506:

    {	if (parserData->grpWgtAttributePresent)
		osolerror (NULL, osoption, parserData, "only one group weight allowed");
	parserData->grpWgtAttributePresent = true;
	osoption->optimization->variables->sosVariableBranchingWeights->sos[parserData->numberOfSOS]->groupWeight = (yyvsp[(3) - (4)].ival);
;}
    break;

  case 507:

    {	if ((yyvsp[(3) - (4)].ival) < 0)
		osolerror (NULL, osoption, parserData, "number of <var> elements must be nonnegative");
//	osoption->optimization->variables->sosVariableBranchingWeights->sos[parserData->numberOfSOS] = new SOSWeights();
	osoption->optimization->variables->sosVariableBranchingWeights->sos[parserData->numberOfSOS]->numberOfVar = (yyvsp[(3) - (4)].ival);
	osoption->optimization->variables->sosVariableBranchingWeights->sos[parserData->numberOfSOS]->var = new BranchingWeight*[(yyvsp[(3) - (4)].ival)];
	for (int i = 0; i < (yyvsp[(3) - (4)].ival); i++)
		osoption->optimization->variables->sosVariableBranchingWeights->sos[parserData->numberOfSOS]->var[i] = new BranchingWeight();
;}
    break;

  case 512:

    {	if (!parserData->idxAttributePresent)
		osolerror (NULL, osoption, parserData, "variable index required");
	parserData->idxAttributePresent = false;
	parserData->valAttributePresent = false;
	parserData->numberOfSOSVar++;
;}
    break;

  case 513:

    {	if (parserData->numberOfSOSVar >= osoption->optimization->variables->sosVariableBranchingWeights->sos[parserData->numberOfSOS]->numberOfVar)
		osolerror(NULL, osoption, parserData, "too many variable branching weights");
;}
    break;

  case 518:

    {	if (parserData->idxAttributePresent)
		osolerror (NULL, osoption, parserData, "only one variable index allowed");
	parserData->idxAttributePresent = true;
	if ((yyvsp[(3) - (4)].ival) < 0)
		osolerror (NULL, osoption, parserData, "variable index must be nonnegative");
	if (parserData->numberOfVariablesPresent)
	{	if ((yyvsp[(3) - (4)].ival) >= parserData->numberOfVariables)
			osolerror (NULL, osoption, parserData, "variable index exceeds upper limit");
	};
	osoption->optimization->variables->sosVariableBranchingWeights->sos[parserData->numberOfSOS]->var[parserData->numberOfSOSVar]->idx = (yyvsp[(3) - (4)].ival);
;}
    break;

  case 519:

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

  case 526:

    {	if (parserData->numberOfOtherVariableOptions >= osoption->optimization->variables->numberOfOtherVariableOptions)
		osolerror(NULL, osoption, parserData, "too many <other> variable options");
;}
    break;

  case 536:

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

  case 537:

    {	if (parserData->otherOptionNamePresent)
		osolerror (NULL, osoption, parserData, "only one name attribute allowed");
	parserData->otherOptionNamePresent = true;
	osoption->optimization->variables->other[parserData->numberOfOtherVariableOptions]->name = (yyvsp[(2) - (2)].sval);
;}
    break;

  case 539:

    {	if (parserData->otherOptionValuePresent)
		osolerror (NULL, osoption, parserData, "only one value attribute allowed");
	parserData->otherOptionValuePresent = true;
	osoption->optimization->variables->other[parserData->numberOfOtherVariableOptions]->value = (yyvsp[(2) - (2)].sval);
;}
    break;

  case 541:

    {	if (parserData->otherOptionSolverPresent)
		osolerror (NULL, osoption, parserData, "only one solver attribute allowed");
	parserData->otherOptionSolverPresent = true;
	osoption->optimization->variables->other[parserData->numberOfOtherVariableOptions]->solver = (yyvsp[(2) - (2)].sval);
;}
    break;

  case 543:

    {	if (parserData->otherOptionCategoryPresent)
		osolerror (NULL, osoption, parserData, "only one category attribute allowed");
	parserData->otherOptionCategoryPresent = true;
	osoption->optimization->variables->other[parserData->numberOfOtherVariableOptions]->category = (yyvsp[(2) - (2)].sval);
;}
    break;

  case 545:

    {	if (parserData->otherOptionTypePresent)
		osolerror (NULL, osoption, parserData, "only one type attribute allowed");
	parserData->otherOptionTypePresent = true;
	osoption->optimization->variables->other[parserData->numberOfOtherVariableOptions]->type = (yyvsp[(2) - (2)].sval);
;}
    break;

  case 547:

    {	if (parserData->otherOptionDescriptionPresent)
		osolerror (NULL, osoption, parserData, "only one description attribute allowed");
	parserData->otherOptionDescriptionPresent = true;
	osoption->optimization->variables->other[parserData->numberOfOtherVariableOptions]->description = (yyvsp[(2) - (2)].sval);
;}
    break;

  case 549:

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

  case 552:

    {	if (!parserData->idxAttributePresent)
		osolerror(NULL, osoption, parserData, "required idx attribute was not found");
	parserData->idxAttributePresent = false;
	parserData->valAttributePresent = false;
	parserData->lbvalAttributePresent = false;
	parserData->ubvalAttributePresent = false;
	parserData->numberOfVar++;
;}
    break;

  case 553:

    {	if (parserData->numberOfVar >= osoption->optimization->variables->other[parserData->numberOfOtherVariableOptions]->numberOfVar)
		osolerror(NULL, osoption, parserData, "too many <var> entries in <other> variable element");
;}
    break;

  case 560:

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

  case 561:

    {	if (parserData->valAttributePresent)
		osolerror (NULL, osoption, parserData, "only one variable value allowed");
	parserData->valAttributePresent = true;
	osoption->optimization->variables-> other[parserData->numberOfOtherVariableOptions]->var[parserData->numberOfVar]->value = (yyvsp[(2) - (2)].sval);
;}
    break;

  case 563:

    {	if (parserData->lbvalAttributePresent)
		osolerror (NULL, osoption, parserData, "only one lower bound value allowed");
	parserData->lbvalAttributePresent = true;
	osoption->optimization->variables-> other[parserData->numberOfOtherVariableOptions]->var[parserData->numberOfVar]->lbValue = (yyvsp[(2) - (2)].sval);
;}
    break;

  case 565:

    {	if (parserData->ubvalAttributePresent)
		osolerror (NULL, osoption, parserData, "only one upper bound value allowed");
	parserData->ubvalAttributePresent = true;
	osoption->optimization->variables-> other[parserData->numberOfOtherVariableOptions]->var[parserData->numberOfVar]->ubValue = (yyvsp[(2) - (2)].sval);
;}
    break;

  case 571:

    {	osoption->optimization->objectives = new ObjectiveOption();
;}
    break;

  case 573:

    {	if ((yyvsp[(3) - (4)].ival) < 0)
		osolerror (NULL, osoption, parserData, "number of <other> objective options cannot be negative");
	osoption->optimization->objectives->numberOfOtherObjectiveOptions = (yyvsp[(3) - (4)].ival);
	osoption->optimization->objectives->other = new OtherObjectiveOption*[(yyvsp[(3) - (4)].ival)];
	for (int i= 0; i < (yyvsp[(3) - (4)].ival); i++)
		osoption->optimization->objectives->other[i] = new OtherObjectiveOption();
;}
    break;

  case 578:

    {	if ((yyvsp[(3) - (4)].ival) <= 0)
		osolerror (NULL, osoption, parserData, "number of <obj> elements must be positive");
	osoption->optimization->objectives->initialObjectiveValues = new InitObjectiveValues();
	osoption->optimization->objectives->initialObjectiveValues->numberOfObj = (yyvsp[(3) - (4)].ival);
	osoption->optimization->objectives->initialObjectiveValues->obj = new InitObjValue*[(yyvsp[(3) - (4)].ival)];
	for (int i = 0; i < (yyvsp[(3) - (4)].ival); i++)
		osoption->optimization->objectives->initialObjectiveValues->obj[i] = new InitObjValue();
;}
    break;

  case 581:

    {	if (!parserData->idxAttributePresent)
		osolerror (NULL, osoption, parserData, "objective index required");
	parserData->idxAttributePresent = false;
	parserData->valAttributePresent = false;
	parserData->numberOfObjValues++;
;}
    break;

  case 582:

    {	if (parserData->numberOfObjValues >= osoption->optimization->objectives->initialObjectiveValues->numberOfObj)
		osolerror(NULL, osoption, parserData, "too many initial objective values");
;}
    break;

  case 587:

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

  case 588:

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

  case 594:

    {	if ((yyvsp[(3) - (4)].ival) <= 0)
		osolerror (NULL, osoption, parserData, "number of <obj> elements must be positive");
	osoption->optimization->objectives->initialObjectiveBounds = new InitObjectiveBounds();
	osoption->optimization->objectives->initialObjectiveBounds->numberOfObj = (yyvsp[(3) - (4)].ival);
	osoption->optimization->objectives->initialObjectiveBounds->obj = new InitObjBound*[(yyvsp[(3) - (4)].ival)];
	for (int i = 0; i < (yyvsp[(3) - (4)].ival); i++)
		osoption->optimization->objectives->initialObjectiveBounds->obj[i] = new InitObjBound ();
;}
    break;

  case 597:

    {	if (!parserData->idxAttributePresent)
		osolerror (NULL, osoption, parserData, "objective index required");
	parserData->idxAttributePresent = false;
	parserData->lbvalAttributePresent = false;
	parserData->ubvalAttributePresent = false;
	parserData->numberOfObjBounds++;
;}
    break;

  case 598:

    {	if (parserData->numberOfObjBounds >= osoption->optimization->objectives->initialObjectiveBounds->numberOfObj)
		osolerror(NULL, osoption, parserData, "too many initial objective bounds");
;}
    break;

  case 604:

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

  case 605:

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

  case 607:

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

  case 614:

    {	if (parserData->numberOfOtherObjectiveOptions >= osoption->optimization->objectives->numberOfOtherObjectiveOptions)
		osolerror(NULL, osoption, parserData, "too many <other> objective options");
;}
    break;

  case 624:

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

  case 625:

    {	if (parserData->otherOptionNamePresent)
		osolerror (NULL, osoption, parserData, "only one name attribute allowed");
	parserData->otherOptionNamePresent = true;
	osoption->optimization->objectives->other[parserData->numberOfOtherObjectiveOptions]->name = (yyvsp[(2) - (2)].sval);
;}
    break;

  case 627:

    {	if (parserData->otherOptionValuePresent)
		osolerror (NULL, osoption, parserData, "only one value attribute allowed");
	parserData->otherOptionValuePresent = true;
	osoption->optimization->objectives->other[parserData->numberOfOtherObjectiveOptions]->value = (yyvsp[(2) - (2)].sval);
;}
    break;

  case 629:

    {	if (parserData->otherOptionSolverPresent)
		osolerror (NULL, osoption, parserData, "only one solver attribute allowed");
	parserData->otherOptionSolverPresent = true;
	osoption->optimization->objectives->other[parserData->numberOfOtherObjectiveOptions]->solver = (yyvsp[(2) - (2)].sval);
;}
    break;

  case 631:

    {	if (parserData->otherOptionCategoryPresent)
		osolerror (NULL, osoption, parserData, "only one category attribute allowed");
	parserData->otherOptionCategoryPresent = true;
	osoption->optimization->objectives->other[parserData->numberOfOtherObjectiveOptions]->category = (yyvsp[(2) - (2)].sval);
;}
    break;

  case 633:

    {	if (parserData->otherOptionTypePresent)
		osolerror (NULL, osoption, parserData, "only one type attribute allowed");
	parserData->otherOptionTypePresent = true;
	osoption->optimization->objectives->other[parserData->numberOfOtherObjectiveOptions]->type = (yyvsp[(2) - (2)].sval);
;}
    break;

  case 635:

    {	if (parserData->otherOptionDescriptionPresent)
		osolerror (NULL, osoption, parserData, "only one description attribute allowed");
	parserData->otherOptionDescriptionPresent = true;
	osoption->optimization->objectives->other[parserData->numberOfOtherObjectiveOptions]->description = (yyvsp[(2) - (2)].sval);
;}
    break;

  case 637:

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

  case 640:

    {	if (!parserData->idxAttributePresent)
		osolerror(NULL, osoption, parserData, "required idx attribute was not found");
	parserData->idxAttributePresent = false;
	parserData->valAttributePresent = false;
	parserData->lbvalAttributePresent = false;
	parserData->ubvalAttributePresent = false;
	parserData->numberOfObj++;
;}
    break;

  case 641:

    {	if (parserData->numberOfObj >= osoption->optimization->objectives->other[parserData->numberOfOtherObjectiveOptions]->numberOfObj)
		osolerror(NULL, osoption, parserData, "too many <obj> entries in <other> objective element");
;}
    break;

  case 648:

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

  case 649:

    {	if (parserData->valAttributePresent)
		osolerror (NULL, osoption, parserData, "only one variable value allowed");
	parserData->valAttributePresent = true;
	osoption->optimization->objectives-> other[parserData->numberOfOtherObjectiveOptions]->obj[parserData->numberOfObj]->value = (yyvsp[(2) - (2)].sval);
;}
    break;

  case 651:

    {	if (parserData->lbvalAttributePresent)
		osolerror (NULL, osoption, parserData, "only one lower bound value allowed");
	parserData->lbvalAttributePresent = true;
	osoption->optimization->objectives-> other[parserData->numberOfOtherObjectiveOptions]->obj[parserData->numberOfObj]->lbValue = (yyvsp[(2) - (2)].sval);
;}
    break;

  case 653:

    {	if (parserData->ubvalAttributePresent)
		osolerror (NULL, osoption, parserData, "only one upper bound value allowed");
	parserData->ubvalAttributePresent = true;
	osoption->optimization->objectives-> other[parserData->numberOfOtherObjectiveOptions]->obj[parserData->numberOfObj]->ubValue = (yyvsp[(2) - (2)].sval);
;}
    break;

  case 659:

    {	osoption->optimization->constraints = new ConstraintOption();
;}
    break;

  case 661:

    {	if ((yyvsp[(3) - (4)].ival) < 0)
		osolerror (NULL, osoption, parserData, "number of <other> constraint options cannot be negative");
        osoption->optimization->constraints->numberOfOtherConstraintOptions = (yyvsp[(3) - (4)].ival);
	osoption->optimization->constraints->other = new OtherConstraintOption*[(yyvsp[(3) - (4)].ival)];
	for (int i= 0; i < (yyvsp[(3) - (4)].ival); i++)
		osoption->optimization->constraints->other[i] = new OtherConstraintOption();
;}
    break;

  case 666:

    {	if ((yyvsp[(3) - (4)].ival) <= 0)
		osolerror (NULL, osoption, parserData, "number of <con> elements must be positive");
	osoption->optimization->constraints->initialConstraintValues = new InitConstraintValues();
	osoption->optimization->constraints->initialConstraintValues->numberOfCon = (yyvsp[(3) - (4)].ival);
	osoption->optimization->constraints->initialConstraintValues->con = new InitConValue*[(yyvsp[(3) - (4)].ival)];
	for (int i = 0; i < (yyvsp[(3) - (4)].ival); i++)
		osoption->optimization->constraints->initialConstraintValues->con[i] = new InitConValue();
;}
    break;

  case 669:

    {	if (!parserData->idxAttributePresent)
		osolerror (NULL, osoption, parserData, "variable index required");
	parserData->idxAttributePresent = false;
	parserData->valAttributePresent = false;
	parserData->numberOfCon++;
;}
    break;

  case 670:

    {	if (parserData->numberOfCon >= osoption->optimization->constraints->initialConstraintValues->numberOfCon)
		osolerror(NULL, osoption, parserData, "too many initial constraint values");
;}
    break;

  case 675:

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

  case 676:

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

  case 682:

    {	if ((yyvsp[(3) - (4)].ival) <= 0)
		osolerror (NULL, osoption, parserData, "number of <con> elements must be positive");
	osoption->optimization->constraints->initialDualValues = new InitDualVariableValues();
	osoption->optimization->constraints->initialDualValues->numberOfCon = (yyvsp[(3) - (4)].ival);
	osoption->optimization->constraints->initialDualValues->con = new InitDualVarValue*[(yyvsp[(3) - (4)].ival)];
	for (int i = 0; i < (yyvsp[(3) - (4)].ival); i++)
		osoption->optimization->constraints->initialDualValues->con[i] = new InitDualVarValue ();
;}
    break;

  case 685:

    {	if (!parserData->idxAttributePresent)
		osolerror (NULL, osoption, parserData, "constraint index required");
	parserData->idxAttributePresent = false;
	parserData->lbvalAttributePresent = false;
	parserData->ubvalAttributePresent = false;
	parserData->numberOfDuals++;
;}
    break;

  case 686:

    {	if (parserData->numberOfDuals >= osoption->optimization->constraints->initialDualValues->numberOfCon)
		osolerror(NULL, osoption, parserData, "too many initial dual variable bounds");
;}
    break;

  case 692:

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

  case 693:

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

  case 695:

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

  case 702:

    {	if (parserData->numberOfOtherConstraintOptions >= osoption->optimization->constraints->numberOfOtherConstraintOptions)
		osolerror(NULL, osoption, parserData, "too many <other> constraint options");
;}
    break;

  case 712:

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

  case 713:

    {	if (parserData->otherOptionNamePresent)
		osolerror (NULL, osoption, parserData, "only one name attribute allowed");
	parserData->otherOptionNamePresent = true;
	osoption->optimization->constraints->other[parserData->numberOfOtherConstraintOptions]->name = (yyvsp[(2) - (2)].sval);
;}
    break;

  case 715:

    {	if (parserData->otherOptionValuePresent)
		osolerror (NULL, osoption, parserData, "only one value attribute allowed");
	parserData->otherOptionValuePresent = true;
	osoption->optimization->constraints->other[parserData->numberOfOtherConstraintOptions]->value = (yyvsp[(2) - (2)].sval);
;}
    break;

  case 717:

    {	if (parserData->otherOptionSolverPresent)
		osolerror (NULL, osoption, parserData, "only one solver attribute allowed");
	parserData->otherOptionSolverPresent = true;
	osoption->optimization->constraints->other[parserData->numberOfOtherConstraintOptions]->solver = (yyvsp[(2) - (2)].sval);
;}
    break;

  case 719:

    {	if (parserData->otherOptionCategoryPresent)
		osolerror (NULL, osoption, parserData, "only one category attribute allowed");
	parserData->otherOptionCategoryPresent = true;
	osoption->optimization->constraints->other[parserData->numberOfOtherConstraintOptions]->category = (yyvsp[(2) - (2)].sval);
;}
    break;

  case 721:

    {	if (parserData->otherOptionTypePresent)
		osolerror (NULL, osoption, parserData, "only one type attribute allowed");
	parserData->otherOptionTypePresent = true;
	osoption->optimization->constraints->other[parserData->numberOfOtherConstraintOptions]->type = (yyvsp[(2) - (2)].sval);
;}
    break;

  case 723:

    {	if (parserData->otherOptionDescriptionPresent)
		osolerror (NULL, osoption, parserData, "only one description attribute allowed");
	parserData->otherOptionDescriptionPresent = true;
	osoption->optimization->constraints->other[parserData->numberOfOtherConstraintOptions]->description = (yyvsp[(2) - (2)].sval);
;}
    break;

  case 725:

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

  case 728:

    {	if (!parserData->idxAttributePresent)
		osolerror(NULL, osoption, parserData, "required idx attribute was not found");
	parserData->idxAttributePresent = false;
	parserData->valAttributePresent = false;
	parserData->lbvalAttributePresent = false;
	parserData->ubvalAttributePresent = false;
	parserData->numberOfCon++;
;}
    break;

  case 729:

    {	if (parserData->numberOfVar >= osoption->optimization->variables->other[parserData->numberOfOtherVariableOptions]->numberOfVar)
		osolerror(NULL, osoption, parserData, "too many <var> entries in <other> variable element");
;}
    break;

  case 736:

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

  case 737:

    {	if (parserData->valAttributePresent)
		osolerror (NULL, osoption, parserData, "only one constraint value allowed");
	parserData->valAttributePresent = true;
	osoption->optimization->constraints-> other[parserData->numberOfOtherConstraintOptions]->con[parserData->numberOfCon]->value = (yyvsp[(2) - (2)].sval);
;}
    break;

  case 739:

    {	if (parserData->lbvalAttributePresent)
		osolerror (NULL, osoption, parserData, "only one lower bound value allowed");
	parserData->lbvalAttributePresent = true;
	osoption->optimization->constraints-> other[parserData->numberOfOtherConstraintOptions]->con[parserData->numberOfCon]->lbValue = (yyvsp[(2) - (2)].sval);
;}
    break;

  case 741:

    {	if (parserData->ubvalAttributePresent)
		osolerror (NULL, osoption, parserData, "only one upper bound value allowed");
	parserData->ubvalAttributePresent = true;
	osoption->optimization->constraints-> other[parserData->numberOfOtherConstraintOptions]->con[parserData->numberOfCon]->ubValue = (yyvsp[(2) - (2)].sval);
;}
    break;

  case 746:

    {	if (parserData->numberOfSolverOptions != osoption->optimization->solverOptions->numberOfSolverOptions)
		osolerror (NULL, osoption, parserData, "wrong number of solver options in <optimization> element");
;}
    break;

  case 747:

    {	if (parserData->solverOptionsPresent)
	{	osolerror( NULL, osoption, parserData, "only one <solverOptions> element allowed");
	}
	else
	{	parserData->solverOptionsPresent = true;
		osoption->optimization->solverOptions = new SolverOptions();
	}
;}
    break;

  case 748:

    {	if ((yyvsp[(3) - (4)].ival) < 0)
		osolerror (NULL, osoption, parserData, "number of solver options cannot be negative");
	osoption->optimization->solverOptions->numberOfSolverOptions = (yyvsp[(3) - (4)].ival);
	osoption->optimization->solverOptions->solverOption = new SolverOption*[(yyvsp[(3) - (4)].ival)];
	for (int i=0; i < (yyvsp[(3) - (4)].ival); i++) osoption->optimization->solverOptions->solverOption[i] = new SolverOption();
;}
    break;

  case 751:

    {	if (parserData->numberOfSolverOptions >= osoption->optimization->solverOptions->numberOfSolverOptions)
	{	osolerror (NULL, osoption, parserData, "too many solver options in <optimization> element");
	};
;}
    break;

  case 752:

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

  case 761:

    {	if (parserData->solverOptionNamePresent)
	{	osolerror( NULL, osoption, parserData, "only one name attribute allowed");
	}
	else
	{	parserData->solverOptionNamePresent = true;
		osoption->optimization->solverOptions->solverOption[parserData->numberOfSolverOptions]->name = (yyvsp[(2) - (2)].sval);
	}
;}
    break;

  case 763:

    {	if (parserData->solverOptionValuePresent)
	{	osolerror( NULL, osoption, parserData, "only one value attribute allowed");
	}
	else
	{	parserData->solverOptionValuePresent = true;
		osoption->optimization->solverOptions->solverOption[parserData->numberOfSolverOptions]->value = (yyvsp[(2) - (2)].sval);
	}
;}
    break;

  case 765:

    {	if (parserData->solverOptionSolverPresent)
	{	osolerror( NULL, osoption, parserData, "only one solver attribute allowed");
	}
	else
	{	parserData->solverOptionSolverPresent = true;
		osoption->optimization->solverOptions->solverOption[parserData->numberOfSolverOptions]->solver = (yyvsp[(2) - (2)].sval);
	}
;}
    break;

  case 767:

    {	if (parserData->solverOptionCategoryPresent)
	{	osolerror( NULL, osoption, parserData, "only one category attribute allowed");
	}
	else
	{	parserData->solverOptionCategoryPresent = true;
		osoption->optimization->solverOptions->solverOption[parserData->numberOfSolverOptions]->category = (yyvsp[(2) - (2)].sval);
	}
;}
    break;

  case 769:

    {	if (parserData->solverOptionTypePresent)
	{	osolerror( NULL, osoption, parserData, "only one type attribute allowed");
	}
	else
	{	parserData->solverOptionTypePresent = true;
		osoption->optimization->solverOptions->solverOption[parserData->numberOfSolverOptions]->type = (yyvsp[(2) - (2)].sval);
	}
;}
    break;

  case 771:

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


