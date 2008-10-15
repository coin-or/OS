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
     OBJECTIVESSTART = 384,
     OBJECTIVESEND = 385,
     INITIALOBJECTIVEVALUESSTART = 386,
     INITIALOBJECTIVEVALUESEND = 387,
     OBJSTART = 388,
     OBJEND = 389,
     INITIALOBJECTIVEBOUNDSSTART = 390,
     INITIALOBJECTIVEBOUNDSEND = 391,
     CONSTRAINTSSTART = 392,
     CONSTRAINTSEND = 393,
     INITIALCONSTRAINTVALUESSTART = 394,
     INITIALCONSTRAINTVALUESEND = 395,
     CONSTART = 396,
     CONEND = 397,
     INITIALDUALVALUESSTART = 398,
     INITIALDUALVALUESEND = 399,
     SOLVEROPTIONSSTART = 400,
     SOLVEROPTIONSEND = 401,
     SOLVEROPTIONSTART = 402,
     SOLVEROPTIONEND = 403,
     DUMMY = 404
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
#define OBJECTIVESSTART 384
#define OBJECTIVESEND 385
#define INITIALOBJECTIVEVALUESSTART 386
#define INITIALOBJECTIVEVALUESEND 387
#define OBJSTART 388
#define OBJEND 389
#define INITIALOBJECTIVEBOUNDSSTART 390
#define INITIALOBJECTIVEBOUNDSEND 391
#define CONSTRAINTSSTART 392
#define CONSTRAINTSEND 393
#define INITIALCONSTRAINTVALUESSTART 394
#define INITIALCONSTRAINTVALUESEND 395
#define CONSTART 396
#define CONEND 397
#define INITIALDUALVALUESSTART 398
#define INITIALDUALVALUESEND 399
#define SOLVEROPTIONSSTART 400
#define SOLVEROPTIONSEND 401
#define SOLVEROPTIONSTART 402
#define SOLVEROPTIONEND 403
#define DUMMY 404




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
#define YYLAST   724

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  150
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  488
/* YYNRULES -- Number of rules.  */
#define YYNRULES  719
/* YYNRULES -- Number of states.  */
#define YYNSTATES  1193

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   404

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
     145,   146,   147,   148,   149
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
     331,   334,   335,   340,   341,   346,   350,   352,   353,   354,
     359,   361,   364,   365,   370,   371,   376,   380,   382,   383,
     384,   389,   391,   394,   395,   400,   401,   406,   409,   411,
     413,   416,   417,   422,   427,   429,   434,   437,   438,   441,
     442,   447,   448,   451,   453,   455,   457,   458,   463,   464,
     469,   470,   475,   477,   480,   481,   484,   486,   490,   492,
     493,   496,   498,   500,   503,   505,   507,   510,   511,   516,
     521,   523,   528,   531,   532,   535,   536,   541,   542,   545,
     547,   549,   551,   552,   557,   558,   563,   564,   569,   571,
     574,   577,   579,   583,   585,   586,   589,   591,   593,   595,
     597,   599,   601,   603,   605,   607,   609,   611,   613,   615,
     617,   619,   623,   625,   626,   627,   632,   634,   637,   638,
     643,   644,   649,   652,   654,   656,   659,   660,   665,   671,
     673,   678,   679,   682,   683,   689,   695,   697,   702,   703,
     706,   707,   713,   719,   721,   726,   727,   730,   731,   737,
     743,   745,   750,   751,   754,   755,   761,   767,   769,   774,
     775,   778,   779,   785,   791,   793,   798,   799,   802,   806,
     808,   809,   812,   814,   816,   818,   819,   824,   825,   830,
     831,   836,   839,   841,   847,   849,   854,   855,   858,   862,
     864,   865,   868,   870,   872,   874,   875,   880,   881,   886,
     887,   892,   895,   897,   903,   905,   910,   911,   914,   918,
     920,   921,   924,   926,   928,   930,   931,   936,   937,   942,
     943,   948,   951,   953,   959,   961,   966,   967,   970,   974,
     976,   977,   980,   982,   984,   986,   987,   992,   993,   998,
     999,  1004,  1007,  1009,  1015,  1017,  1022,  1023,  1026,  1027,
    1033,  1039,  1041,  1046,  1047,  1050,  1051,  1057,  1063,  1065,
    1070,  1071,  1074,  1075,  1081,  1086,  1088,  1093,  1096,  1097,
    1100,  1101,  1106,  1107,  1110,  1112,  1114,  1116,  1117,  1122,
    1123,  1128,  1129,  1134,  1136,  1139,  1140,  1144,  1146,  1147,
    1150,  1152,  1154,  1156,  1161,  1166,  1171,  1175,  1177,  1182,
    1183,  1187,  1189,  1190,  1195,  1201,  1203,  1204,  1210,  1215,
    1216,  1219,  1223,  1225,  1226,  1229,  1231,  1233,  1238,  1239,
    1244,  1247,  1249,  1250,  1256,  1261,  1262,  1265,  1269,  1271,
    1272,  1275,  1277,  1279,  1284,  1285,  1290,  1293,  1295,  1296,
    1299,  1303,  1305,  1306,  1309,  1311,  1313,  1315,  1317,  1319,
    1321,  1323,  1328,  1329,  1334,  1335,  1340,  1341,  1346,  1347,
    1352,  1353,  1358,  1359,  1364,  1368,  1369,  1372,  1376,  1378,
    1379,  1382,  1384,  1386,  1388,  1390,  1395,  1396,  1401,  1402,
    1407,  1408,  1413,  1416,  1418,  1419,  1423,  1425,  1426,  1431,
    1437,  1439,  1440,  1446,  1451,  1452,  1455,  1459,  1461,  1462,
    1465,  1467,  1469,  1474,  1475,  1480,  1483,  1485,  1486,  1492,
    1497,  1498,  1501,  1505,  1507,  1508,  1511,  1513,  1515,  1517,
    1522,  1523,  1528,  1529,  1534,  1537,  1539,  1540,  1543,  1547,
    1549,  1550,  1553,  1555,  1557,  1559,  1561,  1563,  1565,  1567,
    1572,  1573,  1578,  1579,  1584,  1585,  1590,  1591,  1596,  1597,
    1602,  1603,  1608,  1612,  1613,  1616,  1620,  1622,  1623,  1626,
    1628,  1630,  1632,  1634,  1639,  1640,  1645,  1646,  1651,  1652,
    1657,  1660,  1662,  1663,  1667,  1669,  1670,  1675,  1681,  1683,
    1684,  1690,  1695,  1696,  1699,  1703,  1705,  1706,  1709,  1711,
    1713,  1718,  1719,  1724,  1727,  1729,  1730,  1736,  1741,  1742,
    1745,  1749,  1751,  1752,  1755,  1757,  1759,  1761,  1766,  1767,
    1772,  1773,  1778,  1781,  1783,  1784,  1787,  1791,  1793,  1794,
    1797,  1799,  1801,  1803,  1805,  1807,  1809,  1811,  1816,  1817,
    1822,  1823,  1828,  1829,  1834,  1835,  1840,  1841,  1846,  1847,
    1852,  1856,  1857,  1860,  1864,  1866,  1867,  1870,  1872,  1874,
    1876,  1878,  1883,  1884,  1889,  1890,  1895,  1896,  1901,  1904,
    1906,  1907,  1913,  1915,  1920,  1921,  1924,  1925,  1930,  1931,
    1934,  1936,  1938,  1940,  1942,  1944,  1946,  1947,  1952,  1953,
    1958,  1959,  1964,  1965,  1970,  1971,  1976,  1977,  1982,  1985
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     151,     0,    -1,   152,     8,   153,    12,    -1,   152,     9,
      -1,    10,    -1,    10,    11,    -1,   154,   219,   265,   290,
     430,    -1,    -1,   155,   156,    -1,    43,    -1,     8,   157,
      44,    -1,     9,    -1,    -1,   157,   158,    -1,   159,    -1,
     163,    -1,   167,    -1,   171,    -1,   177,    -1,   181,    -1,
     185,    -1,   189,    -1,   193,    -1,   197,    -1,   203,    -1,
     160,   161,    -1,    53,    -1,     9,    -1,     8,    54,    -1,
      -1,     8,     4,   162,    54,    -1,   164,   165,    -1,    55,
      -1,     9,    -1,     8,    56,    -1,    -1,     8,     4,   166,
      56,    -1,   168,   169,    -1,    57,    -1,     9,    -1,     8,
      58,    -1,    -1,     8,     4,   170,    58,    -1,   172,   173,
     175,    -1,    59,    -1,    -1,    -1,    13,     3,   174,     7,
      -1,     9,    -1,     8,   176,    60,    -1,    -1,     4,    -1,
     178,   179,    -1,    61,    -1,     9,    -1,     8,    62,    -1,
      -1,     8,     4,   180,    62,    -1,   182,   183,    -1,    63,
      -1,     9,    -1,     8,    64,    -1,    -1,     8,     4,   184,
      64,    -1,   186,   187,    -1,    65,    -1,     9,    -1,     8,
      66,    -1,    -1,     8,     4,   188,    66,    -1,   190,   191,
      -1,    67,    -1,     9,    -1,     8,    68,    -1,    -1,     8,
       4,   192,    68,    -1,   194,   195,    -1,    69,    -1,     9,
      -1,     8,    70,    -1,    -1,     8,     4,   196,    70,    -1,
     198,   199,   201,    -1,    71,    -1,    -1,    -1,    14,     3,
     200,     7,    -1,     9,    -1,     8,   202,    72,    -1,    -1,
       4,    -1,   204,   205,     8,   206,    -1,    73,    -1,    15,
       7,     5,     7,    -1,   207,    74,    -1,    -1,   207,   208,
      -1,    -1,    75,   209,   210,   218,    -1,    -1,   210,   211,
      -1,   212,    -1,   214,    -1,   216,    -1,    -1,    36,     3,
     213,     7,    -1,    -1,    38,     3,   215,     7,    -1,    -1,
      40,     3,   217,     7,    -1,     9,    -1,     8,    76,    -1,
      -1,   220,   221,    -1,    45,    -1,     8,   222,    46,    -1,
       9,    -1,    -1,   222,   223,    -1,   224,    -1,   231,    -1,
     238,    -1,   245,    -1,   249,    -1,   225,   226,   228,    -1,
      77,    -1,    -1,    -1,    39,     3,   227,     7,    -1,     9,
      -1,     8,    78,    -1,    -1,     8,     6,   229,    78,    -1,
      -1,     8,     5,   230,    78,    -1,   232,   233,   235,    -1,
      79,    -1,    -1,    -1,    39,     3,   234,     7,    -1,     9,
      -1,     8,    80,    -1,    -1,     8,     6,   236,    80,    -1,
      -1,     8,     5,   237,    80,    -1,   239,   240,   242,    -1,
      81,    -1,    -1,    -1,    39,     3,   241,     7,    -1,     9,
      -1,     8,    82,    -1,    -1,     8,     6,   243,    82,    -1,
      -1,     8,     5,   244,    82,    -1,   246,   247,    -1,    83,
      -1,     9,    -1,     8,    84,    -1,    -1,     8,     5,   248,
      84,    -1,   250,   251,     8,   252,    -1,    73,    -1,    15,
       7,     5,     7,    -1,   253,    74,    -1,    -1,   253,   254,
      -1,    -1,    75,   255,   256,   264,    -1,    -1,   256,   257,
      -1,   258,    -1,   260,    -1,   262,    -1,    -1,    36,     3,
     259,     7,    -1,    -1,    38,     3,   261,     7,    -1,    -1,
      40,     3,   263,     7,    -1,     9,    -1,     8,    76,    -1,
      -1,   266,   267,    -1,    47,    -1,     8,   268,    48,    -1,
       9,    -1,    -1,   268,   269,    -1,   270,    -1,   274,    -1,
     271,   272,    -1,    85,    -1,     9,    -1,     8,    86,    -1,
      -1,     8,     4,   273,    86,    -1,   275,   276,     8,   277,
      -1,    73,    -1,    15,     7,     5,     7,    -1,   278,    74,
      -1,    -1,   278,   279,    -1,    -1,    75,   280,   281,   289,
      -1,    -1,   281,   282,    -1,   283,    -1,   285,    -1,   287,
      -1,    -1,    36,     3,   284,     7,    -1,    -1,    38,     3,
     286,     7,    -1,    -1,    40,     3,   288,     7,    -1,     9,
      -1,     8,    76,    -1,   291,   292,    -1,    49,    -1,     8,
     293,    50,    -1,     9,    -1,    -1,   293,   294,    -1,   295,
      -1,   302,    -1,   306,    -1,   312,    -1,   318,    -1,   324,
      -1,   330,    -1,   336,    -1,   351,    -1,   366,    -1,   381,
      -1,   396,    -1,   402,    -1,   408,    -1,   414,    -1,   296,
     297,   299,    -1,    87,    -1,    -1,    -1,    39,     3,   298,
       7,    -1,     9,    -1,     8,    88,    -1,    -1,     8,     6,
     300,    88,    -1,    -1,     8,     5,   301,    88,    -1,   303,
     304,    -1,    89,    -1,     9,    -1,     8,    90,    -1,    -1,
       8,     4,   305,    90,    -1,   307,   308,     8,   309,    92,
      -1,    91,    -1,    16,     7,     5,     7,    -1,    -1,   309,
     310,    -1,    -1,    61,     8,     4,   311,    62,    -1,   313,
     314,     8,   315,    94,    -1,    93,    -1,    17,     7,     5,
       7,    -1,    -1,   315,   316,    -1,    -1,    97,     8,     4,
     317,    98,    -1,   319,   320,     8,   321,    96,    -1,    95,
      -1,    17,     7,     5,     7,    -1,    -1,   321,   322,    -1,
      -1,    97,     8,     4,   323,    98,    -1,   325,   326,     8,
     327,   102,    -1,   101,    -1,    17,     7,     5,     7,    -1,
      -1,   327,   328,    -1,    -1,    97,     8,     4,   329,    98,
      -1,   331,   332,     8,   333,   104,    -1,   103,    -1,    17,
       7,     5,     7,    -1,    -1,   333,   334,    -1,    -1,    97,
       8,     4,   335,    98,    -1,   337,   338,     8,   339,   110,
      -1,   109,    -1,    18,     7,     5,     7,    -1,    -1,   339,
     340,    -1,   341,   342,   350,    -1,    99,    -1,    -1,   342,
     343,    -1,   344,    -1,   346,    -1,   348,    -1,    -1,    19,
       3,   345,     7,    -1,    -1,    20,     3,   347,     7,    -1,
      -1,    21,     3,   349,     7,    -1,     8,   100,    -1,     9,
      -1,   352,   353,     8,   354,   112,    -1,   111,    -1,    18,
       7,     5,     7,    -1,    -1,   354,   355,    -1,   356,   357,
     365,    -1,    99,    -1,    -1,   357,   358,    -1,   359,    -1,
     361,    -1,   363,    -1,    -1,    19,     3,   360,     7,    -1,
      -1,    20,     3,   362,     7,    -1,    -1,    21,     3,   364,
       7,    -1,     8,   100,    -1,     9,    -1,   367,   368,     8,
     369,   114,    -1,   113,    -1,    18,     7,     5,     7,    -1,
      -1,   369,   370,    -1,   371,   372,   380,    -1,    99,    -1,
      -1,   372,   373,    -1,   374,    -1,   376,    -1,   378,    -1,
      -1,    19,     3,   375,     7,    -1,    -1,    20,     3,   377,
       7,    -1,    -1,    21,     3,   379,     7,    -1,     8,   100,
      -1,     9,    -1,   382,   383,     8,   384,   116,    -1,   115,
      -1,    18,     7,     5,     7,    -1,    -1,   384,   385,    -1,
     386,   387,   395,    -1,    99,    -1,    -1,   387,   388,    -1,
     389,    -1,   391,    -1,   393,    -1,    -1,    19,     3,   390,
       7,    -1,    -1,    20,     3,   392,     7,    -1,    -1,    21,
       3,   394,     7,    -1,     8,   100,    -1,     9,    -1,   397,
     398,     8,   399,   108,    -1,   107,    -1,    17,     7,     5,
       7,    -1,    -1,   399,   400,    -1,    -1,    97,     8,     4,
     401,    98,    -1,   403,   404,     8,   405,   106,    -1,   105,
      -1,    17,     7,     5,     7,    -1,    -1,   405,   406,    -1,
      -1,    97,     8,     4,   407,    98,    -1,   409,   410,     8,
     411,   118,    -1,   117,    -1,    25,     7,     5,     7,    -1,
      -1,   411,   412,    -1,    -1,   119,     8,     4,   413,   120,
      -1,   415,   416,     8,   417,    -1,    73,    -1,    15,     7,
       5,     7,    -1,   418,    74,    -1,    -1,   418,   419,    -1,
      -1,    75,   420,   421,   429,    -1,    -1,   421,   422,    -1,
     423,    -1,   425,    -1,   427,    -1,    -1,    36,     3,   424,
       7,    -1,    -1,    38,     3,   426,     7,    -1,    -1,    40,
       3,   428,     7,    -1,     9,    -1,     8,    76,    -1,    -1,
     431,   432,   437,    -1,    51,    -1,    -1,   432,   433,    -1,
     434,    -1,   435,    -1,   436,    -1,    27,     7,     5,     7,
      -1,    29,     7,     5,     7,    -1,    28,     7,     5,     7,
      -1,     8,   438,    52,    -1,     9,    -1,   439,   497,   557,
     617,    -1,    -1,   440,   441,   442,    -1,   121,    -1,    -1,
      30,     7,     5,     7,    -1,     8,   443,   454,   465,   122,
      -1,     9,    -1,    -1,   123,   444,     8,   445,   124,    -1,
      33,     7,     5,     7,    -1,    -1,   445,   446,    -1,   447,
     448,   453,    -1,   125,    -1,    -1,   448,   449,    -1,   450,
      -1,   451,    -1,    37,     7,     5,     7,    -1,    -1,    38,
       3,   452,     7,    -1,     8,   126,    -1,     9,    -1,    -1,
     127,   455,     8,   456,   128,    -1,    33,     7,     5,     7,
      -1,    -1,   456,   457,    -1,   458,   459,   464,    -1,   125,
      -1,    -1,   459,   460,    -1,   461,    -1,   462,    -1,    37,
       7,     5,     7,    -1,    -1,    38,     3,   463,     7,    -1,
       8,   126,    -1,     9,    -1,    -1,   465,   466,    -1,   467,
     468,   483,    -1,    75,    -1,    -1,   468,   469,    -1,   470,
      -1,   471,    -1,   473,    -1,   475,    -1,   477,    -1,   479,
      -1,   481,    -1,    33,     7,     5,     7,    -1,    -1,    36,
       3,   472,     7,    -1,    -1,    38,     3,   474,     7,    -1,
      -1,    22,     3,   476,     7,    -1,    -1,    23,     3,   478,
       7,    -1,    -1,    24,     3,   480,     7,    -1,    -1,    40,
       3,   482,     7,    -1,     8,   484,    76,    -1,    -1,   484,
     485,    -1,   486,   487,   496,    -1,   125,    -1,    -1,   487,
     488,    -1,   489,    -1,   490,    -1,   492,    -1,   494,    -1,
      37,     7,     5,     7,    -1,    -1,    38,     3,   491,     7,
      -1,    -1,    41,     3,   493,     7,    -1,    -1,    42,     3,
     495,     7,    -1,     8,   126,    -1,     9,    -1,    -1,   498,
     499,   500,    -1,   129,    -1,    -1,    31,     7,     5,     7,
      -1,     8,   501,   512,   525,   130,    -1,     9,    -1,    -1,
     131,   502,     8,   503,   132,    -1,    34,     7,     5,     7,
      -1,    -1,   503,   504,    -1,   505,   506,   511,    -1,   133,
      -1,    -1,   506,   507,    -1,   508,    -1,   509,    -1,    37,
       7,     5,     7,    -1,    -1,    38,     3,   510,     7,    -1,
       8,   134,    -1,     9,    -1,    -1,   135,   513,     8,   514,
     136,    -1,    34,     7,     5,     7,    -1,    -1,   514,   515,
      -1,   516,   517,   524,    -1,   133,    -1,    -1,   517,   518,
      -1,   519,    -1,   520,    -1,   522,    -1,    37,     7,     5,
       7,    -1,    -1,    41,     3,   521,     7,    -1,    -1,    42,
       3,   523,     7,    -1,     8,   134,    -1,     9,    -1,    -1,
     525,   526,    -1,   527,   528,   543,    -1,    75,    -1,    -1,
     528,   529,    -1,   530,    -1,   531,    -1,   533,    -1,   535,
      -1,   537,    -1,   539,    -1,   541,    -1,    34,     7,     5,
       7,    -1,    -1,    36,     3,   532,     7,    -1,    -1,    38,
       3,   534,     7,    -1,    -1,    22,     3,   536,     7,    -1,
      -1,    23,     3,   538,     7,    -1,    -1,    24,     3,   540,
       7,    -1,    -1,    40,     3,   542,     7,    -1,     8,   544,
      76,    -1,    -1,   544,   545,    -1,   546,   547,   556,    -1,
     133,    -1,    -1,   547,   548,    -1,   549,    -1,   550,    -1,
     552,    -1,   554,    -1,    37,     7,     5,     7,    -1,    -1,
      38,     3,   551,     7,    -1,    -1,    41,     3,   553,     7,
      -1,    -1,    42,     3,   555,     7,    -1,     8,   126,    -1,
       9,    -1,    -1,   558,   559,   560,    -1,   137,    -1,    -1,
      32,     7,     5,     7,    -1,     8,   561,   572,   585,   138,
      -1,     9,    -1,    -1,   139,   562,     8,   563,   140,    -1,
      35,     7,     5,     7,    -1,    -1,   563,   564,    -1,   565,
     566,   571,    -1,   141,    -1,    -1,   566,   567,    -1,   568,
      -1,   569,    -1,    37,     7,     5,     7,    -1,    -1,    38,
       3,   570,     7,    -1,     8,   142,    -1,     9,    -1,    -1,
     143,   573,     8,   574,   144,    -1,    35,     7,     5,     7,
      -1,    -1,   574,   575,    -1,   576,   577,   584,    -1,   141,
      -1,    -1,   577,   578,    -1,   579,    -1,   580,    -1,   582,
      -1,    37,     7,     5,     7,    -1,    -1,    41,     3,   581,
       7,    -1,    -1,    42,     3,   583,     7,    -1,     8,   142,
      -1,     9,    -1,    -1,   585,   586,    -1,   587,   588,   603,
      -1,    75,    -1,    -1,   588,   589,    -1,   590,    -1,   591,
      -1,   593,    -1,   595,    -1,   597,    -1,   599,    -1,   601,
      -1,    35,     7,     5,     7,    -1,    -1,    36,     3,   592,
       7,    -1,    -1,    38,     3,   594,     7,    -1,    -1,    22,
       3,   596,     7,    -1,    -1,    23,     3,   598,     7,    -1,
      -1,    24,     3,   600,     7,    -1,    -1,    40,     3,   602,
       7,    -1,     8,   604,    76,    -1,    -1,   604,   605,    -1,
     606,   607,   616,    -1,   141,    -1,    -1,   607,   608,    -1,
     609,    -1,   610,    -1,   612,    -1,   614,    -1,    37,     7,
       5,     7,    -1,    -1,    38,     3,   611,     7,    -1,    -1,
      41,     3,   613,     7,    -1,    -1,    42,     3,   615,     7,
      -1,     8,   142,    -1,     9,    -1,    -1,   618,   619,     8,
     620,   146,    -1,   145,    -1,    26,     7,     5,     7,    -1,
      -1,   620,   621,    -1,    -1,   147,   622,   623,   637,    -1,
      -1,   623,   624,    -1,   625,    -1,   627,    -1,   629,    -1,
     631,    -1,   633,    -1,   635,    -1,    -1,    36,     3,   626,
       7,    -1,    -1,    38,     3,   628,     7,    -1,    -1,    22,
       3,   630,     7,    -1,    -1,    23,     3,   632,     7,    -1,
      -1,    24,     3,   634,     7,    -1,    -1,    40,     3,   636,
       7,    -1,     8,   148,    -1,     9,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   128,   128,   129,   131,   132,   134,   136,   136,   138,
     149,   150,   152,   152,   154,   154,   154,   154,   154,   155,
     155,   155,   155,   155,   155,   158,   160,   169,   170,   171,
     171,   174,   176,   185,   186,   187,   187,   190,   192,   201,
     202,   203,   203,   206,   208,   218,   218,   218,   220,   221,
     223,   223,   226,   228,   237,   238,   239,   239,   242,   244,
     253,   254,   255,   255,   258,   260,   269,   270,   271,   271,
     274,   276,   285,   286,   287,   287,   290,   292,   301,   302,
     303,   303,   306,   308,   318,   318,   318,   320,   321,   323,
     323,   326,   328,   338,   344,   349,   349,   352,   351,   367,
     367,   369,   369,   369,   372,   371,   383,   382,   394,   393,
     404,   404,   407,   407,   409,   420,   421,   423,   423,   425,
     425,   425,   425,   425,   427,   429,   439,   439,   439,   441,
     442,   443,   443,   444,   444,   447,   449,   459,   459,   459,
     461,   462,   463,   463,   464,   464,   467,   469,   479,   479,
     479,   481,   482,   483,   483,   484,   484,   487,   489,   498,
     499,   500,   500,   503,   505,   515,   521,   526,   526,   529,
     528,   543,   543,   545,   545,   545,   548,   547,   559,   558,
     571,   570,   581,   581,   584,   584,   586,   597,   598,   600,
     600,   602,   602,   604,   606,   615,   616,   617,   617,   619,
     621,   631,   637,   642,   642,   645,   644,   659,   659,   661,
     661,   661,   664,   663,   675,   674,   686,   685,   696,   696,
     699,   701,   711,   712,   714,   714,   716,   716,   716,   716,
     716,   717,   717,   717,   717,   717,   718,   718,   718,   718,
     718,   721,   723,   733,   733,   733,   735,   736,   737,   737,
     738,   738,   740,   742,   751,   752,   753,   753,   755,   757,
     767,   773,   773,   776,   775,   788,   791,   801,   806,   806,
     808,   808,   820,   823,   833,   838,   838,   840,   840,   852,
     855,   864,   869,   869,   872,   871,   883,   886,   896,   901,
     901,   904,   903,   915,   918,   928,   936,   936,   938,   950,
     956,   956,   958,   958,   958,   961,   960,   972,   971,   983,
     982,   994,   994,   997,  1000,  1010,  1017,  1017,  1019,  1031,
    1037,  1037,  1039,  1039,  1039,  1042,  1041,  1053,  1052,  1064,
    1063,  1075,  1075,  1078,  1081,  1091,  1099,  1099,  1101,  1113,
    1119,  1119,  1121,  1121,  1121,  1124,  1123,  1135,  1134,  1146,
    1145,  1157,  1157,  1160,  1163,  1173,  1180,  1180,  1182,  1194,
    1200,  1200,  1202,  1202,  1202,  1205,  1204,  1216,  1215,  1227,
    1226,  1238,  1238,  1241,  1244,  1254,  1259,  1259,  1262,  1261,
    1273,  1276,  1286,  1291,  1291,  1294,  1293,  1305,  1309,  1319,
    1324,  1324,  1327,  1326,  1338,  1340,  1350,  1356,  1361,  1361,
    1364,  1363,  1378,  1378,  1380,  1380,  1380,  1383,  1382,  1394,
    1393,  1405,  1404,  1415,  1415,  1418,  1418,  1420,  1430,  1430,
    1432,  1432,  1432,  1434,  1438,  1442,  1446,  1446,  1448,  1450,
    1450,  1452,  1456,  1456,  1464,  1465,  1467,  1467,  1469,  1478,
    1478,  1480,  1488,  1493,  1493,  1495,  1495,  1497,  1510,  1509,
    1522,  1522,  1525,  1525,  1528,  1537,  1537,  1539,  1547,  1552,
    1552,  1554,  1554,  1556,  1569,  1568,  1576,  1576,  1581,  1581,
    1583,  1585,  1590,  1590,  1593,  1594,  1595,  1596,  1597,  1598,
    1599,  1601,  1614,  1613,  1622,  1621,  1630,  1629,  1638,  1637,
    1646,  1645,  1654,  1653,  1662,  1679,  1679,  1681,  1691,  1696,
    1696,  1699,  1700,  1701,  1702,  1704,  1717,  1716,  1725,  1724,
    1733,  1732,  1740,  1740,  1744,  1744,  1746,  1750,  1750,  1758,
    1759,  1761,  1761,  1764,  1773,  1773,  1775,  1783,  1788,  1788,
    1790,  1790,  1792,  1806,  1805,  1818,  1818,  1821,  1821,  1824,
    1833,  1833,  1835,  1844,  1849,  1849,  1851,  1851,  1851,  1853,
    1866,  1865,  1879,  1878,  1891,  1891,  1895,  1895,  1897,  1899,
    1904,  1904,  1907,  1908,  1909,  1910,  1911,  1912,  1913,  1915,
    1928,  1927,  1937,  1936,  1946,  1945,  1955,  1954,  1964,  1963,
    1973,  1972,  1982,  1999,  1999,  2001,  2011,  2016,  2016,  2019,
    2020,  2021,  2022,  2024,  2038,  2037,  2047,  2046,  2056,  2055,
    2064,  2064,  2067,  2067,  2069,  2073,  2073,  2081,  2083,  2085,
    2085,  2088,  2097,  2097,  2099,  2107,  2112,  2112,  2114,  2114,
    2116,  2130,  2129,  2142,  2142,  2145,  2145,  2148,  2157,  2157,
    2159,  2168,  2173,  2173,  2175,  2175,  2175,  2177,  2190,  2189,
    2203,  2202,  2216,  2216,  2219,  2219,  2221,  2223,  2228,  2228,
    2231,  2232,  2233,  2234,  2235,  2236,  2237,  2239,  2252,  2251,
    2260,  2259,  2268,  2267,  2276,  2275,  2284,  2283,  2292,  2291,
    2300,  2317,  2317,  2319,  2329,  2334,  2334,  2337,  2338,  2339,
    2340,  2342,  2356,  2355,  2365,  2364,  2373,  2372,  2380,  2380,
    2383,  2383,  2388,  2398,  2405,  2405,  2408,  2407,  2425,  2425,
    2428,  2429,  2430,  2431,  2432,  2433,  2437,  2436,  2448,  2447,
    2459,  2458,  2470,  2469,  2481,  2480,  2492,  2491,  2503,  2503
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
  "INITIALVARIABLEVALUESSTRINGEND", "OBJECTIVESSTART", "OBJECTIVESEND",
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
  "mindiskspaceunit", "@15", "mindiskspacebody", "@16", "@17",
  "minmemorysize", "minmemorysizehead", "minmemoryunit", "@18",
  "minmemorysizebody", "@19", "@20", "mincpuspeed", "mincpuspeedhead",
  "mincpuspeedunit", "@21", "mincpuspeedbody", "@22", "@23",
  "mincpunumber", "mincpunumberhead", "mincpunumberbody", "@24",
  "othersystemoptions", "othersystemoptionshead",
  "numberofothersystemoptions", "othersystemoptionsbody",
  "othersystemoptionslist", "othersystemoption", "@25",
  "othersystemattributes", "othersystemattribute", "systemoptionnameatt",
  "@26", "systemoptionvalueatt", "@27", "systemoptiondescriptionatt",
  "@28", "othersystemoptionend", "osolservice", "servicehead",
  "servicebody", "servicecontent", "serviceoption", "servicetype",
  "servicetypehead", "servicetypebody", "@29", "otherserviceoptions",
  "otherserviceoptionshead", "numberofotherserviceoptions",
  "otherserviceoptionsbody", "otherserviceoptionslist",
  "otherserviceoption", "@30", "otherserviceattributes",
  "otherserviceattribute", "serviceoptionnameatt", "@31",
  "serviceoptionvalueatt", "@32", "serviceoptiondescriptionatt", "@33",
  "otherserviceoptionsend", "osoljob", "jobhead", "jobbody", "jobcontent",
  "joboption", "maxtime", "maxtimehead", "maxtimeunit", "@34",
  "maxtimebody", "@35", "@36", "scheduledstarttime", "starttimehead",
  "starttimebody", "@37", "dependencies", "dependencieshead",
  "numberofjobidsatt", "dependencieslist", "dependencyjobid", "@38",
  "requireddirectories", "requireddirectorieshead",
  "numberofreqdirpathsatt", "reqdirpathlist", "reqdirpath", "@39",
  "requiredfiles", "requiredfileshead", "numberofreqfilespathsatt",
  "reqfilespathlist", "reqfilepath", "@40", "directoriestomake",
  "directoriestomakehead", "numberofdirtomakepathsatt",
  "dirtomakepathlist", "dirtomakepath", "@41", "filestocreate",
  "filestocreatehead", "numberoffilestomakepathsatt",
  "filestomakepathlist", "filestomakepath", "@42",
  "inputdirectoriestomove", "inputdirectoriestomovehead",
  "numberofindirtomovepathpairsatt", "indirtomovepathpairlist",
  "indirtomovepathpair", "indirtomovepathpairhead",
  "indirtomovepathpairattlist", "indirtomovepathpairatt",
  "indirtomovefromatt", "@43", "indirtomovetoatt", "@44",
  "indirtomovemakecopyatt", "@45", "indirtomovepathpairend",
  "inputfilestomove", "inputfilestomovehead",
  "numberofinfilestomovepathpairsatt", "infilestomovepathpairlist",
  "infilestomovepathpair", "infilestomovepathpairhead",
  "infilestomovepathpairattlist", "infilestomovepathpairatt",
  "infilestomovefromatt", "@46", "infilestomovetoatt", "@47",
  "infilestomovemakecopyatt", "@48", "infilestomovepathpairend",
  "outputdirectoriestomove", "outputdirectoriestomovehead",
  "numberofoutdirtomovepathpairsatt", "outdirtomovepathpairlist",
  "outdirtomovepathpair", "outdirtomovepathpairhead",
  "outdirtomovepathpairattlist", "outdirtomovepathpairatt",
  "outdirtomovefromatt", "@49", "outdirtomovetoatt", "@50",
  "outdirtomovemakecopyatt", "@51", "outdirtomovepathpairend",
  "outputfilestomove", "outputfilestomovehead",
  "numberofoutfilestomovepathpairsatt", "outfilestomovepathpairlist",
  "outfilestomovepathpair", "outfilestomovepathpairhead",
  "outfilestomovepathpairattlist", "outfilestomovepathpairatt",
  "outfilestomovefromatt", "@52", "outfilestomovetoatt", "@53",
  "outfilestomovemakecopyatt", "@54", "outfilestomovepathpairend",
  "filestodelete", "filestodeletehead", "numberoffilestodeletepathsatt",
  "filestodeletepathlist", "filestodeletepath", "@55",
  "directoriestodelete", "directoriestodeletehead",
  "numberofdirtodeletepathsatt", "dirtodeletepathlist", "dirtodeletepath",
  "@56", "processestokill", "processestokillhead",
  "numberofprocesstokillatt", "processestokilllist", "processtokill",
  "@57", "otherjoboptions", "otherjoboptionshead",
  "numberofotherjoboptions", "otherjoboptionsbody", "otherjoboptionslist",
  "otherjoboption", "@58", "otherjobattributes", "otherjobattribute",
  "joboptionnameatt", "@59", "joboptionvalueatt", "@60",
  "joboptiondescriptionatt", "@61", "otherjoboptionsend",
  "osoloptimization", "optimizationhead", "optimizationattlist",
  "optimizationatt", "optimizationnvar", "optimizationncon",
  "optimizationnobj", "optimizationbody", "optimizationcontent",
  "variables", "variablesstart", "numberofothervariablesatt",
  "restofvariables", "initialvariablevalues", "numberofvar", "varlist",
  "initvarvalue", "varstart", "initvarvalueattlist", "initvarvalueatt",
  "initvarvalueidxatt", "initvarvaluevalueatt", "@62", "initvarvalueend",
  "initialvariablevaluesstring", "numberofvarstr", "varstrlist",
  "initvarstrvalue", "varstrstart", "initvarstrvalueattlist",
  "initvarstrvalueatt", "initvarstrvalueidxatt", "initvarstrvaluevalueatt",
  "@63", "initvarstrvalueend", "othervariableoptionlist",
  "othervariableoption", "othervariableoptionstart",
  "othervariableoptionsattlist", "othervariableoptionsatt",
  "othervariableoptionnumberofvar", "othervariableoptionname", "@64",
  "othervariableoptionvalue", "@65", "othervariableoptionsolver", "@66",
  "othervariableoptioncategory", "@67", "othervariableoptiontype", "@68",
  "othervariableoptiondescription", "@69", "restofothervariableoption",
  "othervariableoptionsvarlist", "othervariableoptionsvar",
  "othervariableoptionsvarstart", "othervaroptionattlist",
  "othervaroptionatt", "othervaroptionidx", "othervaroptionvalue", "@70",
  "othervaroptionlbvalue", "@71", "othervaroptionubvalue", "@72",
  "othervaroptionend", "objectives", "objectivesstart",
  "numberofotherobjectivesatt", "restofobjectives",
  "initialobjectivevalues", "numberofobjval", "objvaluelist",
  "initobjvalue", "objvaluestart", "initobjvalueattlist",
  "initobjvalueatt", "initobjvalueidxatt", "initobjvaluevalueatt", "@73",
  "initobjvalueend", "initialobjectivebounds", "numberofobjbounds",
  "objboundlist", "initobjbound", "objboundstart", "initobjboundattlist",
  "initobjboundatt", "initobjboundidxatt", "initobjvaluelowerboundatt",
  "@74", "initobjvalueupperboundatt", "@75", "initobjboundend",
  "otherobjectiveoptionlist", "otherobjectiveoption",
  "otherobjectiveoptionstart", "otherobjectiveoptionsattlist",
  "otherobjectiveoptionsatt", "otherobjectiveoptionnumberofvar",
  "otherobjectiveoptionname", "@76", "otherobjectiveoptionvalue", "@77",
  "otherobjectiveoptionsolver", "@78", "otherobjectiveoptioncategory",
  "@79", "otherobjectiveoptiontype", "@80",
  "otherobjectiveoptiondescription", "@81", "restofotherobjectiveoption",
  "otherobjectiveoptionsvarlist", "otherobjectiveoptionsvar",
  "otherobjectiveoptionsvarstart", "otherobjoptionattlist",
  "otherobjoptionatt", "otherobjoptionidx", "otherobjoptionvalue", "@82",
  "otherobjoptionlbvalue", "@83", "otherobjoptionubvalue", "@84",
  "otherobjoptionend", "constraints", "constraintsstart",
  "numberofotherconstraintsatt", "restofconstraints",
  "initialconstraintvalues", "numberofconval", "conlist", "initconvalue",
  "constart", "initconvalueattlist", "initconvalueatt",
  "initconvalueidxatt", "initconvaluevalueatt", "@85", "initconvalueend",
  "initialdualvalues", "numberofduals", "duallist", "initdualvalue",
  "dualstart", "initdualvalueattlist", "initdualvalueatt",
  "initdualvalueidxatt", "initdualvaluelowerboundatt", "@86",
  "initdualvalueupperboundatt", "@87", "initdualvalueend",
  "otherconstraintoptionlist", "otherconstraintoption",
  "otherconstraintoptionstart", "otherconstraintoptionsattlist",
  "otherconstraintoptionsatt", "otherconstraintoptionnumberofvar",
  "otherconstraintoptionname", "@88", "otherconstraintoptionvalue", "@89",
  "otherconstraintoptionsolver", "@90", "otherconstraintoptioncategory",
  "@91", "otherconstraintoptiontype", "@92",
  "otherconstraintoptiondescription", "@93", "restofotherconstraintoption",
  "otherconstraintoptionsvarlist", "otherconstraintoptionsvar",
  "otherconstraintoptionsvarstart", "otherconoptionattlist",
  "otherconoptionatt", "otherconoptionidx", "otherconoptionvalue", "@94",
  "otherconoptionlbvalue", "@95", "otherconoptionubvalue", "@96",
  "otherconoptionend", "solveroptions", "solveroptionsstart",
  "numberofsolveroptionsatt", "solveroptionlist", "solveroption", "@97",
  "solveroptionattlist", "solveroptionatt", "solveroptionname", "@98",
  "solveroptionvalue", "@99", "solveroptionsolver", "@100",
  "solveroptioncategory", "@101", "solveroptiontype", "@102",
  "solveroptiondescription", "@103", "solveroptionend", 0
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
     395,   396,   397,   398,   399,   400,   401,   402,   403,   404
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   150,   151,   151,   152,   152,   153,   154,   154,   155,
     156,   156,   157,   157,   158,   158,   158,   158,   158,   158,
     158,   158,   158,   158,   158,   159,   160,   161,   161,   162,
     161,   163,   164,   165,   165,   166,   165,   167,   168,   169,
     169,   170,   169,   171,   172,   173,   174,   173,   175,   175,
     176,   176,   177,   178,   179,   179,   180,   179,   181,   182,
     183,   183,   184,   183,   185,   186,   187,   187,   188,   187,
     189,   190,   191,   191,   192,   191,   193,   194,   195,   195,
     196,   195,   197,   198,   199,   200,   199,   201,   201,   202,
     202,   203,   204,   205,   206,   207,   207,   209,   208,   210,
     210,   211,   211,   211,   213,   212,   215,   214,   217,   216,
     218,   218,   219,   219,   220,   221,   221,   222,   222,   223,
     223,   223,   223,   223,   224,   225,   226,   227,   226,   228,
     228,   229,   228,   230,   228,   231,   232,   233,   234,   233,
     235,   235,   236,   235,   237,   235,   238,   239,   240,   241,
     240,   242,   242,   243,   242,   244,   242,   245,   246,   247,
     247,   248,   247,   249,   250,   251,   252,   253,   253,   255,
     254,   256,   256,   257,   257,   257,   259,   258,   261,   260,
     263,   262,   264,   264,   265,   265,   266,   267,   267,   268,
     268,   269,   269,   270,   271,   272,   272,   273,   272,   274,
     275,   276,   277,   278,   278,   280,   279,   281,   281,   282,
     282,   282,   284,   283,   286,   285,   288,   287,   289,   289,
     290,   291,   292,   292,   293,   293,   294,   294,   294,   294,
     294,   294,   294,   294,   294,   294,   294,   294,   294,   294,
     294,   295,   296,   297,   298,   297,   299,   299,   300,   299,
     301,   299,   302,   303,   304,   304,   305,   304,   306,   307,
     308,   309,   309,   311,   310,   312,   313,   314,   315,   315,
     317,   316,   318,   319,   320,   321,   321,   323,   322,   324,
     325,   326,   327,   327,   329,   328,   330,   331,   332,   333,
     333,   335,   334,   336,   337,   338,   339,   339,   340,   341,
     342,   342,   343,   343,   343,   345,   344,   347,   346,   349,
     348,   350,   350,   351,   352,   353,   354,   354,   355,   356,
     357,   357,   358,   358,   358,   360,   359,   362,   361,   364,
     363,   365,   365,   366,   367,   368,   369,   369,   370,   371,
     372,   372,   373,   373,   373,   375,   374,   377,   376,   379,
     378,   380,   380,   381,   382,   383,   384,   384,   385,   386,
     387,   387,   388,   388,   388,   390,   389,   392,   391,   394,
     393,   395,   395,   396,   397,   398,   399,   399,   401,   400,
     402,   403,   404,   405,   405,   407,   406,   408,   409,   410,
     411,   411,   413,   412,   414,   415,   416,   417,   418,   418,
     420,   419,   421,   421,   422,   422,   422,   424,   423,   426,
     425,   428,   427,   429,   429,   430,   430,   431,   432,   432,
     433,   433,   433,   434,   435,   436,   437,   437,   438,   439,
     439,   440,   441,   441,   442,   442,   443,   443,   444,   445,
     445,   446,   447,   448,   448,   449,   449,   450,   452,   451,
     453,   453,   454,   454,   455,   456,   456,   457,   458,   459,
     459,   460,   460,   461,   463,   462,   464,   464,   465,   465,
     466,   467,   468,   468,   469,   469,   469,   469,   469,   469,
     469,   470,   472,   471,   474,   473,   476,   475,   478,   477,
     480,   479,   482,   481,   483,   484,   484,   485,   486,   487,
     487,   488,   488,   488,   488,   489,   491,   490,   493,   492,
     495,   494,   496,   496,   497,   497,   498,   499,   499,   500,
     500,   501,   501,   502,   503,   503,   504,   505,   506,   506,
     507,   507,   508,   510,   509,   511,   511,   512,   512,   513,
     514,   514,   515,   516,   517,   517,   518,   518,   518,   519,
     521,   520,   523,   522,   524,   524,   525,   525,   526,   527,
     528,   528,   529,   529,   529,   529,   529,   529,   529,   530,
     532,   531,   534,   533,   536,   535,   538,   537,   540,   539,
     542,   541,   543,   544,   544,   545,   546,   547,   547,   548,
     548,   548,   548,   549,   551,   550,   553,   552,   555,   554,
     556,   556,   557,   557,   558,   559,   559,   560,   560,   561,
     561,   562,   563,   563,   564,   565,   566,   566,   567,   567,
     568,   570,   569,   571,   571,   572,   572,   573,   574,   574,
     575,   576,   577,   577,   578,   578,   578,   579,   581,   580,
     583,   582,   584,   584,   585,   585,   586,   587,   588,   588,
     589,   589,   589,   589,   589,   589,   589,   590,   592,   591,
     594,   593,   596,   595,   598,   597,   600,   599,   602,   601,
     603,   604,   604,   605,   606,   607,   607,   608,   608,   608,
     608,   609,   611,   610,   613,   612,   615,   614,   616,   616,
     617,   617,   618,   619,   620,   620,   622,   621,   623,   623,
     624,   624,   624,   624,   624,   624,   626,   625,   628,   627,
     630,   629,   632,   631,   634,   633,   636,   635,   637,   637
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
       2,     0,     4,     0,     4,     3,     1,     0,     0,     4,
       1,     2,     0,     4,     0,     4,     3,     1,     0,     0,
       4,     1,     2,     0,     4,     0,     4,     2,     1,     1,
       2,     0,     4,     4,     1,     4,     2,     0,     2,     0,
       4,     0,     2,     1,     1,     1,     0,     4,     0,     4,
       0,     4,     1,     2,     0,     2,     1,     3,     1,     0,
       2,     1,     1,     2,     1,     1,     2,     0,     4,     4,
       1,     4,     2,     0,     2,     0,     4,     0,     2,     1,
       1,     1,     0,     4,     0,     4,     0,     4,     1,     2,
       2,     1,     3,     1,     0,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     3,     1,     0,     0,     4,     1,     2,     0,     4,
       0,     4,     2,     1,     1,     2,     0,     4,     5,     1,
       4,     0,     2,     0,     5,     5,     1,     4,     0,     2,
       0,     5,     5,     1,     4,     0,     2,     0,     5,     5,
       1,     4,     0,     2,     0,     5,     5,     1,     4,     0,
       2,     0,     5,     5,     1,     4,     0,     2,     3,     1,
       0,     2,     1,     1,     1,     0,     4,     0,     4,     0,
       4,     2,     1,     5,     1,     4,     0,     2,     3,     1,
       0,     2,     1,     1,     1,     0,     4,     0,     4,     0,
       4,     2,     1,     5,     1,     4,     0,     2,     3,     1,
       0,     2,     1,     1,     1,     0,     4,     0,     4,     0,
       4,     2,     1,     5,     1,     4,     0,     2,     3,     1,
       0,     2,     1,     1,     1,     0,     4,     0,     4,     0,
       4,     2,     1,     5,     1,     4,     0,     2,     0,     5,
       5,     1,     4,     0,     2,     0,     5,     5,     1,     4,
       0,     2,     0,     5,     4,     1,     4,     2,     0,     2,
       0,     4,     0,     2,     1,     1,     1,     0,     4,     0,
       4,     0,     4,     1,     2,     0,     3,     1,     0,     2,
       1,     1,     1,     4,     4,     4,     3,     1,     4,     0,
       3,     1,     0,     4,     5,     1,     0,     5,     4,     0,
       2,     3,     1,     0,     2,     1,     1,     4,     0,     4,
       2,     1,     0,     5,     4,     0,     2,     3,     1,     0,
       2,     1,     1,     4,     0,     4,     2,     1,     0,     2,
       3,     1,     0,     2,     1,     1,     1,     1,     1,     1,
       1,     4,     0,     4,     0,     4,     0,     4,     0,     4,
       0,     4,     0,     4,     3,     0,     2,     3,     1,     0,
       2,     1,     1,     1,     1,     4,     0,     4,     0,     4,
       0,     4,     2,     1,     0,     3,     1,     0,     4,     5,
       1,     0,     5,     4,     0,     2,     3,     1,     0,     2,
       1,     1,     4,     0,     4,     2,     1,     0,     5,     4,
       0,     2,     3,     1,     0,     2,     1,     1,     1,     4,
       0,     4,     0,     4,     2,     1,     0,     2,     3,     1,
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
       0,     5,     1,     4,     0,     2,     0,     4,     0,     2,
       1,     1,     1,     1,     1,     1,     0,     4,     0,     4,
       0,     4,     0,     4,     0,     4,     0,     4,     2,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       0,     4,     0,     0,     5,     1,     7,     3,     9,     0,
     112,     0,     2,   114,   184,     0,    12,    11,     8,   186,
       0,     0,   117,   116,   113,     0,   221,   415,     0,   189,
     188,   185,     0,    10,    26,    32,    38,    44,    53,    59,
      65,    71,    77,    83,    92,    13,    14,     0,    15,     0,
      16,     0,    17,    45,    18,     0,    19,     0,    20,     0,
      21,     0,    22,     0,    23,    84,    24,     0,   417,     6,
     418,   224,   223,   220,     0,   115,   164,   125,   136,   147,
     158,   118,   119,   126,   120,   137,   121,   148,   122,     0,
     123,     0,     0,    27,    25,     0,    33,    31,     0,    39,
      37,     0,     0,     0,    54,    52,     0,    60,    58,     0,
      66,    64,     0,    72,    70,     0,    78,    76,     0,     0,
       0,     0,     0,     0,   187,   200,   194,   190,   191,     0,
     192,     0,     0,     0,     0,     0,     0,     0,     0,   159,
     157,     0,     0,    29,    28,    35,    34,    41,    40,    46,
      50,    48,    43,    56,    55,    62,    61,    68,    67,    74,
      73,    80,    79,    85,    89,    87,    82,     0,    95,   429,
     427,     0,     0,     0,   419,   420,   421,   422,   416,   222,
     395,   242,   253,   259,   266,   273,   280,   287,   381,   374,
     294,   314,   334,   354,   388,   225,   226,   243,   227,     0,
     228,     0,   229,     0,   230,     0,   231,     0,   232,     0,
     233,     0,   234,     0,   235,     0,   236,     0,   237,     0,
     238,     0,   239,     0,   240,     0,     0,   195,   193,     0,
       0,   127,     0,   129,   124,   138,     0,   140,   135,   149,
       0,   151,   146,   161,   160,     0,   167,     0,     0,     0,
       0,    51,     0,     0,     0,     0,     0,     0,     0,    90,
       0,     0,    91,     0,   431,     0,   514,   432,     0,     0,
       0,     0,     0,     0,   254,   252,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   197,   196,     0,   203,     0,   133,   131,   130,
       0,   144,   142,   141,     0,   155,   153,   152,     0,     0,
     163,     0,    30,    36,    42,    47,    49,    57,    63,    69,
      75,    81,    86,    88,    93,    94,    97,    96,   426,   516,
     602,   517,     0,     0,     0,     0,     0,   244,     0,   246,
     241,   256,   255,     0,   261,     0,   268,     0,   275,     0,
     282,     0,   289,     0,   296,     0,   316,     0,   336,     0,
     356,     0,   376,     0,   383,     0,   390,     0,   398,     0,
       0,   199,     0,   128,     0,     0,   139,     0,     0,   150,
       0,     0,   162,   165,   166,   169,   168,    99,   604,   690,
     605,     0,     0,     0,   436,   435,   430,   423,   425,   424,
       0,   250,   248,   247,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     394,     0,   198,   201,   202,   205,   204,   134,   132,   145,
     143,   156,   154,   171,     0,   692,   428,     0,     0,     0,
       0,   521,   520,   515,     0,     0,   452,   245,     0,     0,
     257,   260,     0,   258,   262,   267,   265,     0,   269,   274,
     272,     0,   276,   281,     0,   279,   283,   288,     0,   286,
     290,   295,   299,   293,   297,   300,   315,   319,   313,   317,
     320,   335,   339,   333,   337,   340,   355,   359,   353,   357,
     360,   375,     0,   373,   377,   382,     0,   380,   384,   389,
     387,     0,   391,   396,   397,   400,   399,   207,     0,     0,
     110,     0,     0,     0,   100,   101,   102,   103,    98,     0,
       0,     0,   609,   608,   603,     0,     0,   537,   433,     0,
       0,     0,   468,   251,   249,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   402,     0,     0,
     182,     0,     0,     0,   172,   173,   174,   175,   170,   111,
     104,   106,   108,     0,   694,     0,     0,   625,   518,     0,
       0,     0,   556,     0,   439,     0,     0,     0,   263,   270,
     277,   284,   291,     0,   312,     0,     0,     0,   301,   302,
     303,   304,   298,     0,   332,     0,     0,     0,   321,   322,
     323,   324,   318,     0,   352,     0,     0,     0,   341,   342,
     343,   344,   338,     0,   372,     0,     0,     0,   361,   362,
     363,   364,   358,   378,   385,   392,     0,     0,   218,     0,
       0,     0,   208,   209,   210,   211,   206,   183,   176,   178,
     180,     0,     0,     0,     0,     0,   606,     0,     0,     0,
     644,     0,   524,     0,     0,     0,     0,     0,     0,   455,
     471,   434,   469,   472,     0,     0,     0,     0,     0,   311,
     305,   307,   309,   331,   325,   327,   329,   351,   345,   347,
     349,   371,   365,   367,   369,     0,     0,     0,     0,   413,
       0,     0,     0,   403,   404,   405,   406,   401,   219,   212,
     214,   216,     0,     0,     0,   105,   107,   109,   693,   691,
     696,   695,     0,   612,     0,     0,     0,     0,     0,     0,
     540,   559,   519,   557,   560,   438,   437,   442,   440,   443,
       0,     0,     0,   264,   271,   278,   285,   292,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     379,   386,   393,   414,   407,   409,   411,     0,     0,     0,
     177,   179,   181,   698,     0,     0,     0,   628,   647,   607,
     645,   648,   523,   522,   527,   525,   528,     0,     0,     0,
       0,   454,   458,   453,   456,   459,   495,     0,     0,     0,
       0,     0,     0,     0,   473,   474,   475,   476,   477,   478,
     479,   480,   470,   306,   308,   310,   326,   328,   330,   346,
     348,   350,   366,   368,   370,     0,     0,     0,   213,   215,
     217,     0,   611,   610,   615,   613,   616,     0,     0,     0,
       0,   539,   543,   538,   541,   544,   583,     0,     0,     0,
       0,     0,     0,     0,   561,   562,   563,   564,   565,   566,
     567,   568,   558,     0,   451,     0,     0,   444,   445,   446,
     441,     0,     0,   486,   488,   490,     0,   482,   484,   492,
     408,   410,   412,     0,   719,     0,     0,     0,     0,     0,
       0,   699,   700,   701,   702,   703,   704,   705,   697,     0,
     627,   631,   626,   629,   632,   671,     0,     0,     0,     0,
       0,     0,     0,   649,   650,   651,   652,   653,   654,   655,
     656,   646,     0,   536,     0,     0,   529,   530,   531,   526,
       0,     0,   574,   576,   578,     0,   570,   572,   580,   450,
       0,   448,     0,   467,     0,     0,   460,   461,   462,   457,
     494,   498,   496,   499,     0,     0,     0,     0,     0,     0,
       0,   718,   710,   712,   714,   706,   708,   716,     0,   624,
       0,     0,   617,   618,   619,   614,     0,     0,   662,   664,
     666,     0,   658,   660,   668,   535,     0,   533,     0,   555,
       0,     0,     0,   545,   546,   547,   548,   542,   582,   586,
     584,   587,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   466,     0,   464,     0,   487,   489,   491,   481,   483,
     485,   493,     0,     0,     0,     0,     0,     0,   623,     0,
     621,     0,   643,     0,     0,     0,   633,   634,   635,   636,
     630,   670,   674,   672,   675,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   554,     0,   550,   552,     0,   575,
     577,   579,   569,   571,   573,   581,   447,   449,     0,     0,
       0,   513,     0,     0,     0,     0,   500,   501,   502,   503,
     504,   497,   711,   713,   715,   707,   709,   717,     0,     0,
     642,     0,   638,   640,     0,   663,   665,   667,   657,   659,
     661,   669,   532,   534,     0,     0,     0,     0,   601,     0,
       0,     0,     0,   588,   589,   590,   591,   592,   585,   463,
     465,   512,     0,   506,   508,   510,   620,   622,     0,     0,
       0,     0,   689,     0,     0,     0,     0,   676,   677,   678,
     679,   680,   673,   549,   551,   553,   600,     0,   594,   596,
     598,     0,     0,     0,     0,   637,   639,   641,   688,     0,
     682,   684,   686,     0,     0,     0,     0,   505,   507,   509,
     511,     0,     0,     0,     0,   593,   595,   597,   599,   681,
     683,   685,   687
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
     454,   534,   535,   661,   536,   662,   537,   663,   538,    14,
      15,    24,    32,    81,    82,    83,   133,   306,   234,   385,
     384,    84,    85,   135,   310,   238,   388,   387,    86,    87,
     137,   314,   242,   391,   390,    88,    89,   140,   318,    90,
      91,   142,   320,   321,   396,   453,   528,   574,   575,   722,
     576,   723,   577,   724,   578,    20,    21,    31,    74,   127,
     128,   129,   228,   379,   130,   131,   230,   381,   382,   446,
     527,   568,   652,   653,   777,   654,   778,   655,   779,   656,
      27,    28,    73,   123,   195,   196,   197,   272,   410,   350,
     469,   468,   198,   199,   275,   414,   200,   201,   277,   416,
     474,   684,   202,   203,   279,   418,   478,   685,   204,   205,
     281,   420,   482,   686,   206,   207,   283,   422,   486,   687,
     208,   209,   285,   424,   490,   688,   210,   211,   287,   426,
     494,   495,   560,   608,   609,   758,   610,   759,   611,   760,
     612,   212,   213,   289,   428,   499,   500,   561,   618,   619,
     761,   620,   762,   621,   763,   622,   214,   215,   291,   430,
     504,   505,   562,   628,   629,   764,   630,   765,   631,   766,
     632,   216,   217,   293,   432,   509,   510,   563,   638,   639,
     767,   640,   768,   641,   769,   642,   218,   219,   295,   434,
     514,   705,   220,   221,   297,   436,   518,   706,   222,   223,
     299,   438,   522,   707,   224,   225,   301,   440,   441,   526,
     567,   646,   713,   714,   835,   715,   836,   716,   837,   717,
      69,    70,   122,   174,   175,   176,   177,   178,   265,   266,
     267,   343,   406,   466,   550,   677,   748,   749,   800,   877,
     878,   879,  1020,   880,   552,   596,   751,   804,   805,   881,
     956,   957,   958,  1079,   959,   597,   682,   683,   752,   814,
     815,   816,   968,   817,   969,   818,   964,   819,   965,   820,
     966,   821,   970,   822,   882,   962,   963,  1024,  1086,  1087,
    1088,  1162,  1089,  1163,  1090,  1164,  1091,   340,   341,   402,
     463,   547,   590,   738,   795,   796,   850,   936,   937,   938,
    1063,   939,   592,   674,   798,   854,   855,   940,  1003,  1004,
    1005,  1115,  1006,  1116,  1007,   675,   743,   744,   799,   864,
     865,   866,  1016,   867,  1017,   868,  1012,   869,  1013,   870,
    1014,   871,  1018,   872,   941,  1010,  1011,  1068,  1123,  1124,
    1125,  1174,  1126,  1175,  1127,  1176,  1128,   399,   400,   459,
     544,   587,   668,   785,   845,   846,   909,   982,   983,   984,
    1099,   985,   670,   735,   848,   913,   914,   986,  1046,  1047,
    1048,  1139,  1049,  1140,  1050,   736,   790,   791,   849,   923,
     924,   925,  1059,   926,  1060,   927,  1055,   928,  1056,   929,
    1057,   930,  1061,   931,   987,  1053,  1054,  1104,  1147,  1148,
    1149,  1182,  1150,  1183,  1151,  1184,  1152,   456,   457,   540,
     665,   731,   783,   841,   901,   902,  1035,   903,  1036,   904,
    1032,   905,  1033,   906,  1034,   907,  1037,   908
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -77
static const yytype_int16 yypact[] =
{
      17,    20,    33,   110,   -77,   -77,    -8,   -77,   -77,    13,
      24,   141,   -77,   -77,    -6,   217,   -77,   -77,   -77,   -77,
       0,   223,   -77,   -77,   -77,   193,   -77,    47,   231,   -77,
     -77,   -77,   -20,   -77,   -77,   -77,   -77,   -77,   -77,   -77,
     -77,   -77,   -77,   -77,   -77,   -77,   -77,   234,   -77,   267,
     -77,   279,   -77,    38,   -77,   281,   -77,   283,   -77,   285,
     -77,   287,   -77,   289,   -77,    51,   -77,    90,   -77,   -77,
     -77,   -77,   -77,   -77,   -18,   -77,   -77,   -77,   -77,   -77,
     -77,   -77,   -77,    72,   -77,   116,   -77,   121,   -77,   291,
     -77,   147,    18,   -77,   -77,    25,   -77,   -77,    15,   -77,
     -77,   164,   293,    14,   -77,   -77,    16,   -77,   -77,    12,
     -77,   -77,    11,   -77,   -77,     7,   -77,   -77,   173,   295,
     162,   176,    88,   -49,   -77,   -77,   -77,   -77,   -77,   297,
     -77,   171,   185,   299,   200,   301,   214,   303,    -1,   -77,
     -77,   187,   188,   -77,   -77,   -77,   -77,   -77,   -77,   -77,
     209,   -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,
     -77,   -77,   -77,   -77,   229,   -77,   -77,   242,   -77,    98,
     -77,   244,   246,   248,   -77,   -77,   -77,   -77,   -77,   -77,
     -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,
     -77,   -77,   -77,   -77,   -77,   -77,   -77,   218,   -77,   305,
     -77,   205,   -77,   252,   -77,   255,   -77,   260,   -77,   310,
     -77,   243,   -77,   247,   -77,   318,   -77,   321,   -77,   329,
     -77,   330,   -77,   224,   -77,   333,     1,   -77,   -77,   256,
     251,   -77,     4,   -77,   -77,   -77,     8,   -77,   -77,   -77,
       2,   -77,   -77,   -77,   -77,   344,   -77,   296,   298,   294,
     346,   -77,   300,   302,   292,   304,   290,   306,   348,   -77,
     307,   350,   -77,   241,   -77,   311,   222,   331,   354,   357,
     360,   363,   309,    -4,   -77,   -77,   361,   359,   362,   364,
     366,   367,   370,   372,   371,   373,   375,   376,   378,   379,
     381,   382,   384,   385,   387,   388,   390,   391,   393,   394,
     396,   397,   -77,   -77,   369,   -77,   399,   -77,   -77,   -77,
     400,   -77,   -77,   -77,   401,   -77,   -77,   -77,   308,   402,
     -77,   245,   -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,
     -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,
     261,   340,   403,   313,   404,   405,   406,   -77,    -3,   -77,
     -77,   -77,   -77,   409,   -77,   410,   -77,   411,   -77,   412,
     -77,   413,   -77,   414,   -77,   415,   -77,   416,   -77,   417,
     -77,   418,   -77,   419,   -77,   420,   -77,   421,   -77,   315,
     422,   -77,   249,   -77,   349,   352,   -77,   324,   351,   -77,
     353,   355,   -77,   -77,   -77,   -77,   -77,   -77,   -77,   238,
     407,   425,   317,   423,   263,   -77,   -77,   -77,   -77,   -77,
     426,   -77,   -77,   -77,   356,   427,    45,   429,    54,   431,
     232,   433,    42,   434,     6,   435,   -62,   436,   -76,   437,
     -67,   438,   -71,   440,   -58,   441,    -2,   442,   212,   443,
     -77,   258,   -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,
     -77,   -77,   -77,   -77,   166,   -77,   -77,   428,   444,   326,
     447,   264,   -77,   -77,   446,   424,   328,   -77,   368,   374,
     -77,   -77,   450,   -77,   -77,   -77,   -77,   451,   -77,   -77,
     -77,   452,   -77,   -77,   453,   -77,   -77,   -77,   455,   -77,
     -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,
     -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,
     -77,   -77,   456,   -77,   -77,   -77,   457,   -77,   -77,   -77,
     -77,   458,   -77,   -77,   -77,   -77,   -77,   -77,   169,   392,
     -77,   386,   464,   466,   -77,   -77,   -77,   -77,   -77,   463,
     465,   467,   332,   -77,   -77,   468,   445,   339,   -77,   469,
     470,   448,   -77,   -77,   -77,   473,   476,   478,   479,   480,
     215,   259,   262,   265,   481,   482,   483,   -77,   174,   430,
     -77,   485,   486,   487,   -77,   -77,   -77,   -77,   -77,   -77,
     -77,   -77,   -77,   488,   -77,   484,   459,   358,   -77,   489,
     490,   461,   -77,   492,   -77,   493,   491,   -32,   -77,   -77,
     -77,   -77,   -77,   408,   -77,   499,   500,   501,   -77,   -77,
     -77,   -77,   -77,   432,   -77,   502,   504,   506,   -77,   -77,
     -77,   -77,   -77,   439,   -77,   507,   508,   509,   -77,   -77,
     -77,   -77,   -77,   449,   -77,   510,   511,   512,   -77,   -77,
     -77,   -77,   -77,   -77,   -77,   -77,   182,   454,   -77,   513,
     514,   515,   -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,
     -77,   516,   517,   518,   519,   191,   -77,   520,   521,   496,
     -77,   523,   -77,   526,   527,   -41,   529,   216,   532,   -77,
     -77,   -77,   -77,   -77,   460,   462,   471,   472,   474,   -77,
     -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,
     -77,   -77,   -77,   -77,   -77,   475,   477,   494,   495,   -77,
     531,   535,   537,   -77,   -77,   -77,   -77,   -77,   -77,   -77,
     -77,   -77,   534,   536,   538,   -77,   -77,   -77,   -77,   -77,
     -77,   -77,   539,   -77,   540,   542,   -63,   541,   210,   546,
     -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,
     545,   -16,   123,   -77,   -77,   -77,   -77,   -77,   547,   548,
     549,   550,   551,   552,   554,   555,   556,   557,   558,   559,
     -77,   -77,   -77,   -77,   -77,   -77,   -77,   560,   561,   567,
     -77,   -77,   -77,   -77,   569,   204,   572,   -77,   -77,   -77,
     -77,   -77,   -77,   -77,   -77,   -77,   -77,   571,    75,   130,
     105,   -77,   -77,   -77,   -77,   -77,   -77,   543,   576,   577,
     574,   579,   580,   581,   -77,   -77,   -77,   -77,   -77,   -77,
     -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,
     -77,   -77,   -77,   -77,   -77,   578,   582,   583,   -77,   -77,
     -77,   149,   -77,   -77,   -77,   -77,   -77,   584,    97,   157,
     190,   -77,   -77,   -77,   -77,   -77,   -77,   585,   589,   590,
     587,   592,   593,   594,   -77,   -77,   -77,   -77,   -77,   -77,
     -77,   -77,   -77,   395,   -77,   591,   596,   -77,   -77,   -77,
     -77,   192,   -55,   -77,   -77,   -77,   595,   -77,   -77,   -77,
     -77,   -77,   -77,   497,   -77,   598,   599,   600,   601,   602,
     603,   -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,   207,
     -77,   -77,   -77,   -77,   -77,   -77,   604,   605,   606,   608,
     607,   609,   610,   -77,   -77,   -77,   -77,   -77,   -77,   -77,
     -77,   -77,   498,   -77,   611,   613,   -77,   -77,   -77,   -77,
      93,   -59,   -77,   -77,   -77,   612,   -77,   -77,   -77,   -77,
     614,   -77,   503,   -77,   615,   617,   -77,   -77,   -77,   -77,
     -77,   -77,   -77,   -77,   616,   618,   619,   620,   621,   623,
     624,   -77,   -77,   -77,   -77,   -77,   -77,   -77,   377,   -77,
     626,   631,   -77,   -77,   -77,   -77,    99,   -70,   -77,   -77,
     -77,   630,   -77,   -77,   -77,   -77,   632,   -77,   505,   -77,
     629,   635,   637,   -77,   -77,   -77,   -77,   -77,   -77,   -77,
     -77,   -77,   634,   636,   639,   640,   641,   642,   643,   644,
     645,   -77,   648,   -77,    83,   -77,   -77,   -77,   -77,   -77,
     -77,   -77,   647,   649,   650,   651,   652,   653,   -77,   656,
     -77,   522,   -77,   655,   660,   662,   -77,   -77,   -77,   -77,
     -77,   -77,   -77,   -77,   -77,   659,   661,   663,   664,   665,
     666,   667,   668,   669,   -77,   672,   -77,   -77,    85,   -77,
     -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,   671,   673,
     553,   -77,   674,   679,   680,   681,   -77,   -77,   -77,   -77,
     -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,   678,   682,
     -77,   683,   -77,   -77,    91,   -77,   -77,   -77,   -77,   -77,
     -77,   -77,   -77,   -77,   684,   685,   686,   564,   -77,   687,
     692,   693,   694,   -77,   -77,   -77,   -77,   -77,   -77,   -77,
     -77,   -77,   695,   -77,   -77,   -77,   -77,   -77,   691,   696,
     697,   525,   -77,   698,   699,   703,   704,   -77,   -77,   -77,
     -77,   -77,   -77,   -77,   -77,   -77,   -77,   705,   -77,   -77,
     -77,   701,   702,   706,   707,   -77,   -77,   -77,   -77,   710,
     -77,   -77,   -77,   709,   711,   712,   713,   -77,   -77,   -77,
     -77,   714,   715,   716,   717,   -77,   -77,   -77,   -77,   -77,
     -77,   -77,   -77
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,
     -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,
     -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,
     -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,
     -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,
     -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,
     -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,
     -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,
     -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,
     -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,
     -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,
     -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,
     -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,
     -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,
     -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,
     -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,
     -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,
     -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,
     -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,
     -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,
     -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,
     -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,
     -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,
     -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,
     -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,
     -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,
     -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,
     -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,
     -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,
     -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,
     -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,
     -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,
     -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,
     -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,
     -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,
     -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,
     -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,
     -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,
     -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,
     -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,
     -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,
     -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,
     -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,
     -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,
     -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,
     -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,
     -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,
     -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,
     -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint16 yytable[] =
{
     351,   179,   411,   412,   243,   302,  1051,   315,   316,   307,
     308,   161,   788,   311,   312,   159,   157,  1008,   153,   147,
     155,   960,   143,   497,   180,    12,    75,     1,   507,   145,
     124,     4,   502,     5,   741,     8,   498,   492,   181,   512,
     182,    19,   183,   680,   184,   508,   185,   503,   493,    26,
     513,   101,   186,    76,   187,   125,   188,    77,   189,    78,
     190,    79,   191,    80,   192,   118,   193,   126,   194,    13,
     961,  1052,   144,   148,  1009,   789,   154,   162,   158,   160,
     156,   146,   309,   244,   317,   413,   352,   303,   313,   742,
     681,  1080,  1081,  1117,  1118,   516,   169,   170,    68,  1141,
    1142,   998,   999,   488,   517,   120,   472,  1041,  1042,   802,
     489,   132,   803,   873,   874,   171,   172,   173,     6,     7,
    1082,  1083,  1119,  1120,  1084,  1085,  1121,  1122,  1143,  1144,
    1000,   806,  1145,  1146,  1001,  1002,  1043,   473,   856,   484,
    1044,  1045,   875,   876,   485,   807,   808,   809,   476,    16,
      17,   477,   857,   858,   859,   134,   810,   893,   894,   811,
     136,   812,   141,   813,   860,   915,   861,   149,   862,   167,
     863,   895,   896,   897,   529,   530,   163,   569,   570,   916,
     917,   918,   647,   648,   168,   898,   229,   899,   231,   900,
     708,   709,   919,   920,   245,   921,   246,   922,   932,   933,
     952,   953,   531,   235,   532,   571,   533,   572,   852,   573,
     649,   853,   650,   251,   651,   978,   979,   239,   710,   264,
     711,   276,   712,   603,   604,    22,    23,   934,   935,   954,
     955,    29,    30,   259,   605,   606,   607,    33,   911,    71,
      72,   912,    92,    93,   980,   981,    34,   261,    35,   298,
      36,   268,    37,   269,    38,   270,    39,   271,    40,   305,
      41,   286,    42,   304,    43,   288,    44,   613,   614,   278,
     623,   624,   280,   633,   634,    95,    96,   282,   615,   616,
     617,   625,   626,   627,   635,   636,   637,    98,    99,   103,
     104,   106,   107,   109,   110,   112,   113,   115,   116,   138,
     139,   150,   151,   164,   165,   226,   227,   232,   233,   236,
     237,   240,   241,   273,   274,   335,   336,   348,   349,   394,
     395,   404,   405,   444,   445,   461,   462,   284,   480,   481,
     520,   521,   524,   525,   542,   543,   290,   729,   730,   292,
     746,   747,   793,   794,   843,   844,   294,   296,   300,   319,
     322,   339,   324,   325,   323,   332,   328,   334,   330,   344,
     326,   342,   345,   338,   327,   346,   347,   354,   353,   355,
     329,   401,   356,   357,   380,   358,   331,   359,   361,   333,
     360,   362,   363,   455,   364,   365,   465,   366,   367,   580,
     368,   369,   392,   370,   371,   546,   372,   373,   398,   374,
     375,   442,   376,   377,   449,   378,   383,   386,   389,   393,
     403,   407,   408,   409,   415,   417,   419,   421,   423,   425,
     427,   429,   431,   433,   435,   437,   439,   447,   464,   443,
     448,   450,   460,   467,   471,   451,   475,   452,   479,   458,
     483,   487,   491,   496,   501,   506,   470,   511,   515,   519,
     523,   541,   545,   548,   539,   551,   553,   549,   555,   556,
     557,   558,   554,   559,   564,   565,   566,   581,   579,   582,
     583,   586,   585,   584,   591,   588,   593,   598,   594,   589,
     599,   595,   600,   601,   602,   643,   644,   645,   658,   659,
     660,   666,     0,   664,   667,   673,   671,   676,   672,   679,
     678,   669,   690,   691,   692,   694,   657,   695,   689,   696,
     698,   699,   700,   702,   703,   704,   719,   720,   721,  1038,
       0,   949,   753,   725,   726,   727,   728,   732,   737,   733,
     718,   734,   693,   739,   774,   740,   745,   750,   775,   697,
     776,   780,     0,   781,   784,   782,   883,   786,   792,   701,
     787,   797,   801,     0,   823,   824,   825,   826,   827,   828,
     754,   829,   830,   831,   832,   833,   834,   838,   839,   755,
     756,   773,   757,   770,   840,   771,   842,   847,   851,   884,
     885,   886,   887,   888,   889,   890,     0,     0,   942,   891,
     892,   910,   943,   944,   945,   946,   947,   948,   950,   951,
     967,   972,   973,   974,   975,   976,   977,   988,   989,   990,
     992,     0,   993,   994,   772,   991,   997,  1015,   996,  1019,
    1023,     0,  1022,  1025,     0,  1026,  1027,  1028,  1029,  1021,
    1030,  1031,   995,  1039,  1040,  1058,  1065,  1062,  1066,  1064,
    1067,  1069,     0,  1070,     0,   971,  1071,  1072,  1073,  1074,
    1075,  1076,  1077,  1078,  1092,     0,  1093,  1094,  1095,  1096,
    1097,  1098,  1101,  1102,  1100,  1103,  1105,  1168,  1106,     0,
    1107,  1108,  1109,  1110,  1111,  1112,  1113,  1114,  1129,  1131,
    1130,  1132,  1133,  1134,  1135,  1136,     0,     0,  1138,  1137,
    1156,  1153,  1154,  1155,  1157,  1158,  1159,  1160,  1165,     0,
    1161,     0,  1170,  1166,  1167,  1169,  1171,  1172,  1177,  1178,
    1173,     0,     0,  1179,  1180,  1181,  1185,     0,  1186,  1187,
    1188,  1189,  1190,  1191,  1192
};

static const yytype_int16 yycheck[] =
{
       4,    50,     5,     6,     5,     4,    76,     5,     6,     5,
       6,     4,    75,     5,     6,     4,     4,    76,     4,     4,
       4,    76,     4,    99,    73,    12,    46,    10,    99,     4,
      48,    11,    99,     0,    75,    43,   112,    99,    87,    97,
      89,    47,    91,    75,    93,   116,    95,   114,   110,    49,
     108,    13,   101,    73,   103,    73,   105,    77,   107,    79,
     109,    81,   111,    83,   113,    14,   115,    85,   117,    45,
     125,   141,    54,    58,   133,   138,    62,    70,    66,    68,
      64,    56,    78,    84,    82,    88,    90,    86,    80,   130,
     122,     8,     9,     8,     9,    97,     8,     9,    51,     8,
       9,     8,     9,    97,   106,    15,    61,     8,     9,   125,
     104,    39,   128,     8,     9,    27,    28,    29,     8,     9,
      37,    38,    37,    38,    41,    42,    41,    42,    37,    38,
      37,     8,    41,    42,    41,    42,    37,    92,     8,    97,
      41,    42,    37,    38,   102,    22,    23,    24,    94,     8,
       9,    97,    22,    23,    24,    39,    33,     8,     9,    36,
      39,    38,    15,    40,    34,     8,    36,     3,    38,     7,
      40,    22,    23,    24,     8,     9,     3,     8,     9,    22,
      23,    24,     8,     9,     8,    36,    15,    38,     3,    40,
       8,     9,    35,    36,     7,    38,     8,    40,     8,     9,
       8,     9,    36,     3,    38,    36,    40,    38,   133,    40,
      36,   136,    38,     4,    40,     8,     9,     3,    36,   121,
      38,    16,    40,     8,     9,     8,     9,    37,    38,    37,
      38,     8,     9,     4,    19,    20,    21,    44,   141,     8,
       9,   144,     8,     9,    37,    38,    53,     5,    55,    25,
      57,     7,    59,     7,    61,     7,    63,    39,    65,     8,
      67,    18,    69,     7,    71,    18,    73,     8,     9,    17,
       8,     9,    17,     8,     9,     8,     9,    17,    19,    20,
      21,    19,    20,    21,    19,    20,    21,     8,     9,     8,
       9,     8,     9,     8,     9,     8,     9,     8,     9,     8,
       9,     8,     9,     8,     9,     8,     9,     8,     9,     8,
       9,     8,     9,     8,     9,    74,    75,     8,     9,    74,
      75,     8,     9,    74,    75,     8,     9,    17,    96,    97,
     118,   119,    74,    75,     8,     9,    18,   146,   147,    18,
     124,   125,   132,   133,   140,   141,    17,    17,    15,     5,
      54,   129,    58,     7,    56,     7,    64,     7,    68,     5,
      60,    30,     5,    52,    62,     5,     3,     8,     7,     7,
      66,    31,     8,     7,     5,     8,    70,     7,     7,    72,
       8,     8,     7,   145,     8,     7,   123,     8,     7,     3,
       8,     7,    84,     8,     7,   131,     8,     7,   137,     8,
       7,    86,     8,     7,    80,     8,     7,     7,     7,     7,
       7,     7,     7,     7,     5,     5,     5,     5,     5,     5,
       5,     5,     5,     5,     5,     5,     5,    78,     5,     7,
      78,    80,     7,     7,     7,    82,     7,    82,     7,    32,
       7,     7,     7,     7,     7,     7,    90,     7,     7,     7,
       7,     7,     5,     7,    26,   127,    88,    33,     8,     8,
       8,     8,    88,     8,     8,     8,     8,     3,    76,     3,
       7,   139,     5,     8,   135,     7,     7,     4,     8,    34,
       4,    33,     4,     4,     4,     4,     4,     4,     3,     3,
       3,     7,    -1,     5,    35,    34,     7,     5,     8,     8,
       7,   143,     3,     3,     3,     3,    76,     3,   100,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,   142,
      -1,   126,    62,     7,     7,     7,     7,     7,     5,     8,
      76,    35,   100,     7,     3,     8,     7,     5,     3,   100,
       3,     7,    -1,     7,     5,     7,     3,     7,     7,   100,
       8,     5,     7,    -1,     7,     7,     7,     7,     7,     7,
      98,     7,     7,     7,     7,     7,     7,     7,     7,    98,
      98,    76,    98,    98,     7,    98,     7,     5,     7,     3,
       3,     7,     3,     3,     3,     7,    -1,    -1,     3,     7,
       7,     7,     3,     3,     7,     3,     3,     3,     7,     3,
       5,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,    -1,     3,     3,   120,     7,     3,     5,     7,     5,
       3,    -1,     7,     7,    -1,     7,     7,     7,     7,   126,
       7,     7,   134,     7,     3,     5,     7,     5,     3,   134,
       3,     7,    -1,     7,    -1,   148,     7,     7,     7,     7,
       7,     7,     7,     5,     7,    -1,     7,     7,     7,     7,
       7,     5,     7,     3,   142,     3,     7,   142,     7,    -1,
       7,     7,     7,     7,     7,     7,     7,     5,     7,   126,
       7,     7,     3,     3,     3,     7,    -1,    -1,     5,     7,
     126,     7,     7,     7,     7,     3,     3,     3,     7,    -1,
       5,    -1,     3,     7,     7,     7,     3,     3,     7,     7,
       5,    -1,    -1,     7,     7,     5,     7,    -1,     7,     7,
       7,     7,     7,     7,     7
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,    10,   151,   152,    11,     0,     8,     9,    43,   153,
     154,   155,    12,    45,   219,   220,     8,     9,   156,    47,
     265,   266,     8,     9,   221,   157,    49,   290,   291,     8,
       9,   267,   222,    44,    53,    55,    57,    59,    61,    63,
      65,    67,    69,    71,    73,   158,   159,   160,   163,   164,
     167,   168,   171,   172,   177,   178,   181,   182,   185,   186,
     189,   190,   193,   194,   197,   198,   203,   204,    51,   430,
     431,     8,     9,   292,   268,    46,    73,    77,    79,    81,
      83,   223,   224,   225,   231,   232,   238,   239,   245,   246,
     249,   250,     8,     9,   161,     8,     9,   165,     8,     9,
     169,    13,   173,     8,     9,   179,     8,     9,   183,     8,
       9,   187,     8,     9,   191,     8,     9,   195,    14,   199,
      15,   205,   432,   293,    48,    73,    85,   269,   270,   271,
     274,   275,    39,   226,    39,   233,    39,   240,     8,     9,
     247,    15,   251,     4,    54,     4,    56,     4,    58,     3,
       8,     9,   175,     4,    62,     4,    64,     4,    66,     4,
      68,     4,    70,     3,     8,     9,   201,     7,     8,     8,
       9,    27,    28,    29,   433,   434,   435,   436,   437,    50,
      73,    87,    89,    91,    93,    95,   101,   103,   105,   107,
     109,   111,   113,   115,   117,   294,   295,   296,   302,   303,
     306,   307,   312,   313,   318,   319,   324,   325,   330,   331,
     336,   337,   351,   352,   366,   367,   381,   382,   396,   397,
     402,   403,   408,   409,   414,   415,     8,     9,   272,    15,
     276,     3,     8,     9,   228,     3,     8,     9,   235,     3,
       8,     9,   242,     5,    84,     7,     8,   162,   166,   170,
     174,     4,   176,   180,   184,   188,   192,   196,   200,     4,
     202,     5,   206,   207,   121,   438,   439,   440,     7,     7,
       7,    39,   297,     8,     9,   304,    16,   308,    17,   314,
      17,   320,    17,   326,    17,   332,    18,   338,    18,   353,
      18,   368,    18,   383,    17,   398,    17,   404,    25,   410,
      15,   416,     4,    86,     7,     8,   227,     5,     6,    78,
     234,     5,     6,    80,   241,     5,     6,    82,   248,     5,
     252,   253,    54,    56,    58,     7,    60,    62,    64,    66,
      68,    70,     7,    72,     7,    74,    75,   208,    52,   129,
     497,   498,    30,   441,     5,     5,     5,     3,     8,     9,
     299,     4,    90,     7,     8,     7,     8,     7,     8,     7,
       8,     7,     8,     7,     8,     7,     8,     7,     8,     7,
       8,     7,     8,     7,     8,     7,     8,     7,     8,   273,
       5,   277,   278,     7,   230,   229,     7,   237,   236,     7,
     244,   243,    84,     7,    74,    75,   254,   209,   137,   557,
     558,    31,   499,     7,     8,     9,   442,     7,     7,     7,
     298,     5,     6,    88,   305,     5,   309,     5,   315,     5,
     321,     5,   327,     5,   333,     5,   339,     5,   354,     5,
     369,     5,   384,     5,   399,     5,   405,     5,   411,     5,
     417,   418,    86,     7,    74,    75,   279,    78,    78,    80,
      80,    82,    82,   255,   210,   145,   617,   618,    32,   559,
       7,     8,     9,   500,     5,   123,   443,     7,   301,   300,
      90,     7,    61,    92,   310,     7,    94,    97,   316,     7,
      96,    97,   322,     7,    97,   102,   328,     7,    97,   104,
     334,     7,    99,   110,   340,   341,     7,    99,   112,   355,
     356,     7,    99,   114,   370,   371,     7,    99,   116,   385,
     386,     7,    97,   108,   400,     7,    97,   106,   406,     7,
     118,   119,   412,     7,    74,    75,   419,   280,   256,     8,
       9,    36,    38,    40,   211,   212,   214,   216,   218,    26,
     619,     7,     8,     9,   560,     5,   131,   501,     7,    33,
     444,   127,   454,    88,    88,     8,     8,     8,     8,     8,
     342,   357,   372,   387,     8,     8,     8,   420,   281,     8,
       9,    36,    38,    40,   257,   258,   260,   262,   264,    76,
       3,     3,     3,     7,     8,     5,   139,   561,     7,    34,
     502,   135,   512,     7,     8,    33,   455,   465,     4,     4,
       4,     4,     4,     8,     9,    19,    20,    21,   343,   344,
     346,   348,   350,     8,     9,    19,    20,    21,   358,   359,
     361,   363,   365,     8,     9,    19,    20,    21,   373,   374,
     376,   378,   380,     8,     9,    19,    20,    21,   388,   389,
     391,   393,   395,     4,     4,     4,   421,     8,     9,    36,
      38,    40,   282,   283,   285,   287,   289,    76,     3,     3,
       3,   213,   215,   217,     5,   620,     7,    35,   562,   143,
     572,     7,     8,    34,   513,   525,     5,   445,     7,     8,
      75,   122,   466,   467,   311,   317,   323,   329,   335,   100,
       3,     3,     3,   100,     3,     3,     3,   100,     3,     3,
       3,   100,     3,     3,     3,   401,   407,   413,     8,     9,
      36,    38,    40,   422,   423,   425,   427,   429,    76,     3,
       3,     3,   259,   261,   263,     7,     7,     7,     7,   146,
     147,   621,     7,     8,    35,   573,   585,     5,   503,     7,
       8,    75,   130,   526,   527,     7,   124,   125,   446,   447,
       5,   456,   468,    62,    98,    98,    98,    98,   345,   347,
     349,   360,   362,   364,   375,   377,   379,   390,   392,   394,
      98,    98,   120,    76,     3,     3,     3,   284,   286,   288,
       7,     7,     7,   622,     5,   563,     7,     8,    75,   138,
     586,   587,     7,   132,   133,   504,   505,     5,   514,   528,
     448,     7,   125,   128,   457,   458,     8,    22,    23,    24,
      33,    36,    38,    40,   469,   470,   471,   473,   475,   477,
     479,   481,   483,     7,     7,     7,     7,     7,     7,     7,
       7,     7,     7,     7,     7,   424,   426,   428,     7,     7,
       7,   623,     7,   140,   141,   564,   565,     5,   574,   588,
     506,     7,   133,   136,   515,   516,     8,    22,    23,    24,
      34,    36,    38,    40,   529,   530,   531,   533,   535,   537,
     539,   541,   543,     8,     9,    37,    38,   449,   450,   451,
     453,   459,   484,     3,     3,     3,     7,     3,     3,     3,
       7,     7,     7,     8,     9,    22,    23,    24,    36,    38,
      40,   624,   625,   627,   629,   631,   633,   635,   637,   566,
       7,   141,   144,   575,   576,     8,    22,    23,    24,    35,
      36,    38,    40,   589,   590,   591,   593,   595,   597,   599,
     601,   603,     8,     9,    37,    38,   507,   508,   509,   511,
     517,   544,     3,     3,     3,     7,     3,     3,     3,   126,
       7,     3,     8,     9,    37,    38,   460,   461,   462,   464,
      76,   125,   485,   486,   476,   478,   480,     5,   472,   474,
     482,   148,     3,     3,     3,     3,     3,     3,     8,     9,
      37,    38,   567,   568,   569,   571,   577,   604,     3,     3,
       3,     7,     3,     3,     3,   134,     7,     3,     8,     9,
      37,    41,    42,   518,   519,   520,   522,   524,    76,   133,
     545,   546,   536,   538,   540,     5,   532,   534,   542,     5,
     452,   126,     7,     3,   487,     7,     7,     7,     7,     7,
       7,     7,   630,   632,   634,   626,   628,   636,   142,     7,
       3,     8,     9,    37,    41,    42,   578,   579,   580,   582,
     584,    76,   141,   605,   606,   596,   598,   600,     5,   592,
     594,   602,     5,   510,   134,     7,     3,     3,   547,     7,
       7,     7,     7,     7,     7,     7,     7,     7,     5,   463,
       8,     9,    37,    38,    41,    42,   488,   489,   490,   492,
     494,   496,     7,     7,     7,     7,     7,     7,     5,   570,
     142,     7,     3,     3,   607,     7,     7,     7,     7,     7,
       7,     7,     7,     7,     5,   521,   523,     8,     9,    37,
      38,    41,    42,   548,   549,   550,   552,   554,   556,     7,
       7,   126,     7,     3,     3,     3,     7,     7,     5,   581,
     583,     8,     9,    37,    38,    41,    42,   608,   609,   610,
     612,   614,   616,     7,     7,     7,   126,     7,     3,     3,
       3,     5,   491,   493,   495,     7,     7,     7,   142,     7,
       3,     3,     3,     5,   551,   553,   555,     7,     7,     7,
       7,     5,   611,   613,   615,     7,     7,     7,     7,     7,
       7,     7,     7
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
}
    break;

  case 26:

    {	if (parserData->serviceURIPresent)
	{	osolerror( NULL, osoption, parserData, "only one <serviceURI> element allowed");
	}
	else
	{	parserData->serviceURIPresent = true;
	}
}
    break;

  case 29:

    {osoption->general->serviceURI = (yyvsp[(2) - (2)].sval);}
    break;

  case 32:

    {	if (parserData->serviceNamePresent)
	{	osolerror( NULL, osoption, parserData, "only one <serviceName> element allowed");
	}
	else
	{	parserData->serviceNamePresent = true;
	}
}
    break;

  case 35:

    {osoption->general->serviceName = (yyvsp[(2) - (2)].sval);}
    break;

  case 38:

    {	if (parserData->instanceNamePresent)
	{	osolerror( NULL, osoption, parserData, "only one <instanceName> element allowed");
	}
	else
	{	parserData->instanceNamePresent = true;
	}
}
    break;

  case 41:

    {osoption->general->instanceName = (yyvsp[(2) - (2)].sval);}
    break;

  case 44:

    {	if (parserData->instanceLocationPresent)
	{	osolerror( NULL, osoption, parserData, "only one <instanceLocation> element allowed");
	}
	else
	{	parserData->instanceLocationPresent = true;
		osoption->general->instanceLocation = new InstanceLocationOption();
	}
}
    break;

  case 46:

    {osoption->general->instanceLocation->locationType = (yyvsp[(2) - (2)].sval);}
    break;

  case 51:

    {osoption->general->instanceLocation->value = (yyvsp[(1) - (1)].sval);}
    break;

  case 53:

    {	if (parserData->jobIDPresent)
	{	osolerror( NULL, osoption, parserData, "only one <jobID> element allowed");
	}
	else
	{	parserData->jobIDPresent = true;
	}
}
    break;

  case 56:

    {osoption->general->jobID = (yyvsp[(2) - (2)].sval);}
    break;

  case 59:

    {	if (parserData->solverToInvokePresent)
	{	osolerror( NULL, osoption, parserData, "only one <solverToInvoke> element allowed");
	}
	else
	{	parserData->solverToInvokePresent = true;
	}
}
    break;

  case 62:

    {osoption->general->solverToInvoke = (yyvsp[(2) - (2)].sval);}
    break;

  case 65:

    {	if (parserData->licensePresent)
	{	osolerror( NULL, osoption, parserData, "only one <license> element allowed");
	}
	else
	{	parserData->licensePresent = true;	
	}
}
    break;

  case 68:

    {osoption->general->license = (yyvsp[(2) - (2)].sval);}
    break;

  case 71:

    {	if (parserData->usernamePresent)
	{	osolerror( NULL, osoption, parserData, "only one <userName> element allowed");
	}
	else
	{	parserData->usernamePresent = true;
	}
}
    break;

  case 74:

    {osoption->general->userName = (yyvsp[(2) - (2)].sval);}
    break;

  case 77:

    {	if (parserData->passwordPresent)
	{	osolerror( NULL, osoption, parserData, "only one <password> element allowed");
	}
	else
	{	parserData->passwordPresent = true;
	}
}
    break;

  case 80:

    {osoption->general->password = (yyvsp[(2) - (2)].sval);}
    break;

  case 83:

    {	if (parserData->contactPresent)
	{	osolerror( NULL, osoption, parserData, "only one <contact> element allowed");
	}
	else
	{	parserData->contactPresent = true;
		osoption->general->contact = new ContactOption();
	}
}
    break;

  case 85:

    {osoption->general->contact->transportType = (yyvsp[(2) - (2)].sval);}
    break;

  case 90:

    {osoption->general->contact->value = (yyvsp[(1) - (1)].sval);}
    break;

  case 92:

    {	if (parserData->otherGeneralOptionsPresent)
	{	osolerror( NULL, osoption, parserData, "only one <otherOptions> element allowed");
	}
	else
	{	parserData->otherGeneralOptionsPresent = true;
		osoption->general->otherOptions = new OtherOptions();
	}
}
    break;

  case 93:

    {	osoption->general->otherOptions->numberOfOtherOptions = (yyvsp[(3) - (4)].ival);
	osoption->general->otherOptions->other = new OtherOption*[(yyvsp[(3) - (4)].ival)];
	for (int i=0; i < (yyvsp[(3) - (4)].ival); i++) osoption->general->otherOptions->other[i] = new OtherOption();
}
    break;

  case 94:

    {	if (parserData->numberOfOtherGeneralOptions != osoption->general->otherOptions->numberOfOtherOptions)
		osolerror (NULL, osoption, parserData, "wrong number of other options in <general> element");
}
    break;

  case 97:

    {	if (parserData->numberOfOtherGeneralOptions >= osoption->general->otherOptions->numberOfOtherOptions)
		{	osolerror (NULL, osoption, parserData, "too many other options in <general> element");
		};
	}
    break;

  case 98:

    {	if (!parserData->otherOptionNamePresent)
		osolerror (NULL, osoption, parserData, "name attribute must be present");
	/* reset defaults for the next option */
	parserData->otherOptionNamePresent = false;
	parserData->otherOptionValuePresent = false;
	parserData->otherOptionDescriptionPresent = false;
	parserData->numberOfOtherGeneralOptions++;
}
    break;

  case 104:

    {	if (parserData->otherOptionNamePresent)
	{	osolerror( NULL, osoption, parserData, "only one name attribute allowed");
	}
	else
	{	parserData->otherOptionNamePresent = true;
		osoption->general->otherOptions->other[parserData->numberOfOtherGeneralOptions]->name = (yyvsp[(2) - (2)].sval);
	}
}
    break;

  case 106:

    {	if (parserData->otherOptionValuePresent)
	{	osolerror( NULL, osoption, parserData, "only one value attribute allowed");
	}
	else
	{	parserData->otherOptionValuePresent = true;
		osoption->general->otherOptions->other[parserData->numberOfOtherGeneralOptions]->value = (yyvsp[(2) - (2)].sval);
	}
}
    break;

  case 108:

    {	if (parserData->otherOptionDescriptionPresent)
	{	osolerror( NULL, osoption, parserData, "only one description attribute allowed");
	}
	else
	{	parserData->otherOptionDescriptionPresent = true;
		osoption->general->otherOptions->other[parserData->numberOfOtherGeneralOptions]->description = (yyvsp[(2) - (2)].sval);
	}
}
    break;

  case 114:

    {	if (parserData->osolsystemPresent)
	{	osolerror( NULL, osoption, parserData, "only one <system> element allowed");
	}
	else
	{	parserData->osolsystemPresent = true;
		osoption->system = new SystemOption();
	}
}
    break;

  case 125:

    {	if (parserData->minDiskSpacePresent)
	{	osolerror( NULL, osoption, parserData, "only one <minDiskSpace> element allowed");
	}
	else
	{	parserData-> minDiskSpacePresent = true;
		osoption->system->minDiskSpace = new MinDiskSpace();
	}
}
    break;

  case 127:

    {osoption->system->minDiskSpace->unit = (yyvsp[(2) - (2)].sval);}
    break;

  case 131:

    {osoption->system->minDiskSpace->value = (yyvsp[(2) - (2)].dval);}
    break;

  case 133:

    {osoption->system->minDiskSpace->value = (yyvsp[(2) - (2)].ival);}
    break;

  case 136:

    {	if (parserData->minMemorySizePresent)
	{	osolerror( NULL, osoption, parserData, "only one <minMemorySize> element allowed");
	}
	else
	{	parserData-> minMemorySizePresent = true;
		osoption->system->minMemorySize = new MinMemorySize();
	}
}
    break;

  case 138:

    {osoption->system->minMemorySize->unit = (yyvsp[(2) - (2)].sval);}
    break;

  case 142:

    {osoption->system->minMemorySize->value = (yyvsp[(2) - (2)].dval);}
    break;

  case 144:

    {osoption->system->minMemorySize->value = (yyvsp[(2) - (2)].ival);}
    break;

  case 147:

    {	if (parserData->minCPUSpeedPresent)
	{	osolerror( NULL, osoption, parserData, "only one <minCPUSpeed> element allowed");
	}
	else
	{	parserData-> minCPUSpeedPresent = true;
		osoption->system->minCPUSpeed = new MinCPUSpeed();
	}
}
    break;

  case 149:

    {osoption->system->minCPUSpeed->unit = (yyvsp[(2) - (2)].sval);}
    break;

  case 153:

    {osoption->system->minCPUSpeed->value = (yyvsp[(2) - (2)].dval);}
    break;

  case 155:

    {osoption->system->minCPUSpeed->value = (yyvsp[(2) - (2)].ival);}
    break;

  case 158:

    {	if (parserData->minCPUNumberPresent)
	{	osolerror( NULL, osoption, parserData, "only one <minCPUNumber> element allowed");
	}
	else
	{	parserData->minCPUNumberPresent = true;
	}
}
    break;

  case 161:

    {osoption->system->minCPUNumber = (yyvsp[(2) - (2)].ival);}
    break;

  case 164:

    {	if (parserData->otherSystemOptionsPresent)
	{	osolerror( NULL, osoption, parserData, "only one <otherOptions> element allowed");
	}
	else
	{	parserData->otherSystemOptionsPresent = true;
		osoption->system->otherOptions = new OtherOptions();
	}
}
    break;

  case 165:

    {	osoption->system->otherOptions->numberOfOtherOptions = (yyvsp[(3) - (4)].ival);
	osoption->system->otherOptions->other = new OtherOption*[(yyvsp[(3) - (4)].ival)];
	for (int i=0; i < (yyvsp[(3) - (4)].ival); i++) osoption->system->otherOptions->other[i] = new OtherOption();
}
    break;

  case 166:

    {	if (parserData->numberOfOtherSystemOptions != osoption->system->otherOptions->numberOfOtherOptions)
		osolerror (NULL, osoption, parserData, "wrong number of other options in <system> element");
}
    break;

  case 169:

    {	if (parserData->numberOfOtherSystemOptions >= osoption->system->otherOptions->numberOfOtherOptions)
		{	osolerror (NULL, osoption, parserData, "too many other options in <system> element");
		};
	}
    break;

  case 170:

    {	if (!parserData->otherOptionNamePresent)
		osolerror (NULL, osoption, parserData, "name attribute must be present");
	/* reset defaults for the next option */
	parserData->otherOptionNamePresent = false;
	parserData->otherOptionValuePresent = false;
	parserData->otherOptionDescriptionPresent = false;
	parserData->numberOfOtherSystemOptions++;
}
    break;

  case 176:

    {	if (parserData->otherOptionNamePresent)
	{	osolerror( NULL, osoption, parserData, "only one name attribute allowed");
	}
	else
	{	parserData->otherOptionNamePresent = true;
		osoption->system->otherOptions->other[parserData->numberOfOtherSystemOptions]->name = (yyvsp[(2) - (2)].sval);
	}
}
    break;

  case 178:

    {	if (parserData->otherOptionValuePresent)
	{	osolerror( NULL, osoption, parserData, "only one value attribute allowed");
	}
	else
	{	parserData->otherOptionValuePresent = true;
		osoption->system->otherOptions->other[parserData->numberOfOtherSystemOptions]->value = (yyvsp[(2) - (2)].sval);
	}
}
    break;

  case 180:

    {	if (parserData->otherOptionDescriptionPresent)
	{	osolerror( NULL, osoption, parserData, "only one description attribute allowed");
	}
	else
	{	parserData->otherOptionDescriptionPresent = true;
		osoption->system->otherOptions->other[parserData->numberOfOtherSystemOptions]->description = (yyvsp[(2) - (2)].sval);
	}
}
    break;

  case 186:

    {	if (parserData->osolservicePresent)
	{	osolerror( NULL, osoption, parserData, "only one <service> element allowed");
	}
	else
	{	parserData->osolservicePresent = true;
		osoption->service = new ServiceOption();
	}
}
    break;

  case 194:

    {	if (parserData->serviceTypePresent)
	{	osolerror( NULL, osoption, parserData, "only one <type> element allowed");
	}
	else
	{	parserData->serviceTypePresent = true;
	}
}
    break;

  case 197:

    {osoption->service->type = (yyvsp[(2) - (2)].sval);}
    break;

  case 200:

    {	if (parserData->otherServiceOptionsPresent)
	{	osolerror( NULL, osoption, parserData, "only one <otherOptions> element allowed");
	}
	else
	{	parserData->otherServiceOptionsPresent = true;
		osoption->service->otherOptions = new OtherOptions();
	}
}
    break;

  case 201:

    {	osoption->service->otherOptions->numberOfOtherOptions = (yyvsp[(3) - (4)].ival);
	osoption->service->otherOptions->other = new OtherOption*[(yyvsp[(3) - (4)].ival)];
	for (int i=0; i < (yyvsp[(3) - (4)].ival); i++) osoption->service->otherOptions->other[i] = new OtherOption();
}
    break;

  case 202:

    {	if (parserData->numberOfOtherServiceOptions != osoption->service->otherOptions->numberOfOtherOptions)
		osolerror (NULL, osoption, parserData, "wrong number of other options in <service> element");
}
    break;

  case 205:

    {	if (parserData->numberOfOtherServiceOptions >= osoption->service->otherOptions->numberOfOtherOptions)
		{	osolerror (NULL, osoption, parserData, "too many other options in <service> element");
		};
	}
    break;

  case 206:

    {	if (!parserData->otherOptionNamePresent)
		osolerror (NULL, osoption, parserData, "name attribute must be present");
	/* reset defaults for the next option */
	parserData->otherOptionNamePresent = false;
	parserData->otherOptionValuePresent = false;
	parserData->otherOptionDescriptionPresent = false;
	parserData->numberOfOtherServiceOptions++;
}
    break;

  case 212:

    {	if (parserData->otherOptionNamePresent)
	{	osolerror( NULL, osoption, parserData, "only one name attribute allowed");
	}
	else
	{	parserData->otherOptionNamePresent = true;
		osoption->service->otherOptions->other[parserData->numberOfOtherServiceOptions]->name = (yyvsp[(2) - (2)].sval);
	}
}
    break;

  case 214:

    {	if (parserData->otherOptionValuePresent)
	{	osolerror( NULL, osoption, parserData, "only one value attribute allowed");
	}
	else
	{	parserData->otherOptionValuePresent = true;
		osoption->service->otherOptions->other[parserData->numberOfOtherServiceOptions]->value = (yyvsp[(2) - (2)].sval);
	}
}
    break;

  case 216:

    {	if (parserData->otherOptionDescriptionPresent)
	{	osolerror( NULL, osoption, parserData, "only one description attribute allowed");
	}
	else
	{	parserData->otherOptionDescriptionPresent = true;
		osoption->service->otherOptions->other[parserData->numberOfOtherServiceOptions]->description = (yyvsp[(2) - (2)].sval);
	}
}
    break;

  case 221:

    {	if (parserData->osoljobPresent)
	{	osolerror( NULL, osoption, parserData, "only one <job> element allowed");
	}
	else
	{	parserData->osoljobPresent = true;
		osoption->job = new JobOption();
	}
}
    break;

  case 242:

    {	if (parserData->maxTimePresent)
	{	osolerror( NULL, osoption, parserData, "only one <maxTime> element allowed");
	}
	else
	{	parserData-> maxTimePresent = true;
		osoption->job->maxTime = new MaxTime();
	}
}
    break;

  case 244:

    {osoption->job->maxTime->unit = (yyvsp[(2) - (2)].sval);}
    break;

  case 248:

    {osoption->job->maxTime->value = (yyvsp[(2) - (2)].dval);}
    break;

  case 250:

    {osoption->job->maxTime->value = (yyvsp[(2) - (2)].ival);}
    break;

  case 253:

    {	if (parserData->scheduledStartTimePresent)
	{	osolerror( NULL, osoption, parserData, "only one <scheduledStartTime> element allowed");
	}
	else
	{	parserData->scheduledStartTimePresent = true;
	}
}
    break;

  case 256:

    {osoption->job->scheduledStartTime = (yyvsp[(2) - (2)].sval);}
    break;

  case 259:

    {	if (parserData->dependenciesPresent)
	{	osolerror( NULL, osoption, parserData, "only one <dependencies> element allowed");
	}
	else
	{	parserData->dependenciesPresent = true;
		osoption->job->dependencies = new JobDependencies();
	}
}
    break;

  case 260:

    {	osoption->job->dependencies->numberOfJobIDs = (yyvsp[(3) - (4)].ival);
	osoption->job->dependencies->jobID = new std::string[(yyvsp[(3) - (4)].ival)];
}
    break;

  case 263:

    {
	if (parserData->numberOfDependencies >= osoption->job->dependencies->numberOfJobIDs)
	{	osolerror (NULL, osoption, parserData, "too many job IDs in <dependencies> element");
	}
	else
	{	osoption->job->dependencies->jobID[parserData->numberOfDependencies] = (yyvsp[(3) - (3)].sval);
		parserData->numberOfDependencies++;
	};
}
    break;

  case 266:

    {	if (parserData->requiredDirectoriesPresent)
	{	osolerror( NULL, osoption, parserData, "only one <requiredDirectories> element allowed");
	}
	else
	{	parserData->requiredDirectoriesPresent = true;
		osoption->job->requiredDirectories = new DirectoriesAndFiles();
	}
}
    break;

  case 267:

    {	osoption->job->requiredDirectories->numberOfPaths = (yyvsp[(3) - (4)].ival);
	osoption->job->requiredDirectories->path = new std::string[(yyvsp[(3) - (4)].ival)];
}
    break;

  case 270:

    {
	if (parserData->numberOfRequiredDirectories >= osoption->job->requiredDirectories->numberOfPaths)
	{	osolerror (NULL, osoption, parserData, "too many job IDs in <requiredDirectories> element");
	}
	else
	{	osoption->job->requiredDirectories->path[parserData->numberOfRequiredDirectories] = (yyvsp[(3) - (3)].sval);
		parserData->numberOfRequiredDirectories++;
	};
}
    break;

  case 273:

    {	if (parserData->requiredFilesPresent)
	{	osolerror( NULL, osoption, parserData, "only one <requiredFiles> element allowed");
	}
	else
	{	parserData->requiredFilesPresent = true;
		osoption->job->requiredFiles = new DirectoriesAndFiles();
	}
}
    break;

  case 274:

    {	osoption->job->requiredFiles->numberOfPaths = (yyvsp[(3) - (4)].ival);
	osoption->job->requiredFiles->path = new std::string[(yyvsp[(3) - (4)].ival)];
}
    break;

  case 277:

    {
	if (parserData->numberOfRequiredFiles >= osoption->job->requiredFiles->numberOfPaths)
	{	osolerror (NULL, osoption, parserData, "too many job IDs in <requiredFiles> element");
	}
	else
	{	osoption->job->requiredFiles->path[parserData->numberOfRequiredFiles] = (yyvsp[(3) - (3)].sval);
		parserData->numberOfRequiredFiles++;
	};
}
    break;

  case 280:

    {	if (parserData->directoriesToMakePresent)
	{	osolerror( NULL, osoption, parserData, "only one <directoriesToMake> element allowed");
	}
	else
	{	parserData->directoriesToMakePresent = true;
		osoption->job->directoriesToMake = new DirectoriesAndFiles();
	}
}
    break;

  case 281:

    {	osoption->job->directoriesToMake->numberOfPaths = (yyvsp[(3) - (4)].ival);
	osoption->job->directoriesToMake->path = new std::string[(yyvsp[(3) - (4)].ival)];
}
    break;

  case 284:

    {	if (parserData->numberOfDirectoriesToMake >= osoption->job->directoriesToMake->numberOfPaths)
	{	osolerror (NULL, osoption, parserData, "too many job IDs in <directoriesToMake> element");
	}
	else
	{	osoption->job->directoriesToMake->path[parserData->numberOfDirectoriesToMake] = (yyvsp[(3) - (3)].sval);
		parserData->numberOfDirectoriesToMake++;
	};
}
    break;

  case 287:

    {	if (parserData->filesToCreatePresent)
	{	osolerror( NULL, osoption, parserData, "only one <filesToCreate> element allowed");
	}
	else
	{	parserData->filesToCreatePresent = true;
		osoption->job->filesToCreate = new DirectoriesAndFiles();
	}
}
    break;

  case 288:

    {	osoption->job->filesToCreate->numberOfPaths = (yyvsp[(3) - (4)].ival);
	osoption->job->filesToCreate->path = new std::string[(yyvsp[(3) - (4)].ival)];
}
    break;

  case 291:

    {	if (parserData->numberOfFilesToCreate >= osoption->job->filesToCreate->numberOfPaths)
	{	osolerror (NULL, osoption, parserData, "too many job IDs in <filesToCreate> element");
	}
	else
	{	osoption->job->filesToCreate->path[parserData->numberOfFilesToCreate] = (yyvsp[(3) - (3)].sval);
		parserData->numberOfFilesToCreate++;
	};
}
    break;

  case 294:

    {	if (parserData->inputDirectoriesToMovePresent)
	{	osolerror( NULL, osoption, parserData, "only one <inputDirectoriesToMove> element allowed");
	}
	else
	{	parserData->inputDirectoriesToMovePresent = true;
		osoption->job->inputDirectoriesToMove = new PathPairs();
	}
}
    break;

  case 295:

    {	if ((yyvsp[(3) - (4)].ival) <= 0) osolerror (NULL, osoption, parserData, "Require positive number of directories to move");
	osoption->job->inputDirectoriesToMove->numberOfPathPairs = (yyvsp[(3) - (4)].ival);
	osoption->job->inputDirectoriesToMove->pathPair = new PathPair*[(yyvsp[(3) - (4)].ival)];
	for (int i = 0; i < (yyvsp[(3) - (4)].ival); i++)
		osoption->job->inputDirectoriesToMove->pathPair[i] = new PathPair();
}
    break;

  case 298:

    {	if (!parserData->pathPairFromPresent)
		osolerror (NULL, osoption, parserData, "\"from\" attribute must be present");
	if (!parserData->pathPairToPresent)
		osolerror (NULL, osoption, parserData, "\"to\" attribute must be present");
	/* reset defaults for the next option */
	parserData->pathPairFromPresent= false;
	parserData->pathPairToPresent= false;
	parserData->pathPairMakeCopyPresent= false;
	parserData->numberOfInputDirectoriesToMove++;
}
    break;

  case 299:

    {	if (parserData->numberOfInputDirectoriesToMove >= osoption->job->inputDirectoriesToMove->numberOfPathPairs)
	{	osolerror (NULL, osoption, parserData, "too many path pairs in <inputDirectoriesToMove> element");
	};
}
    break;

  case 305:

    {	if (parserData->pathPairFromPresent)
	{	osolerror( NULL, osoption, parserData, "only one \"from\" attribute allowed");
	}
	else
	{	parserData->pathPairFromPresent = true;
		osoption->job->inputDirectoriesToMove->pathPair[parserData->numberOfInputDirectoriesToMove]->from = (yyvsp[(2) - (2)].sval);
	}
}
    break;

  case 307:

    {	if (parserData->pathPairToPresent)
	{	osolerror( NULL, osoption, parserData, "only one \"to\" attribute allowed");
	}
	else
	{	parserData->pathPairToPresent = true;
		osoption->job->inputDirectoriesToMove->pathPair[parserData->numberOfInputDirectoriesToMove]->to = (yyvsp[(2) - (2)].sval);
	}
}
    break;

  case 309:

    {	if (parserData->pathPairMakeCopyPresent)
	{	osolerror( NULL, osoption, parserData, "only one \"makeCopy\" attribute allowed");
	}
	else
	{	parserData->pathPairMakeCopyPresent = true;
		if ((yyvsp[(2) - (2)].sval) == "true")
			osoption->job->inputDirectoriesToMove->pathPair[parserData->numberOfInputDirectoriesToMove]->makeCopy = true;
	}
}
    break;

  case 314:

    {	if (parserData->inputFilesToMovePresent)
	{	osolerror( NULL, osoption, parserData, "only one <inputFilesToMove> element allowed");
	}
	else
	{	parserData->inputFilesToMovePresent = true;
		osoption->job->inputFilesToMove = new PathPairs();
	}
}
    break;

  case 315:

    {	if ((yyvsp[(3) - (4)].ival) <= 0) osolerror (NULL, osoption, parserData, "Require positive number of files to move");
	osoption->job->inputFilesToMove->numberOfPathPairs = (yyvsp[(3) - (4)].ival);
	osoption->job->inputFilesToMove->pathPair = new PathPair*[(yyvsp[(3) - (4)].ival)];
	for (int i = 0; i < (yyvsp[(3) - (4)].ival); i++) osoption->job->inputFilesToMove->pathPair[i] = new PathPair();
}
    break;

  case 318:

    {	if (!parserData->pathPairFromPresent)
		osolerror (NULL, osoption, parserData, "\"from\" attribute must be present");
	if (!parserData->pathPairToPresent)
		osolerror (NULL, osoption, parserData, "\"to\" attribute must be present");
	/* reset defaults for the next option */
	parserData->pathPairFromPresent= false;
	parserData->pathPairToPresent= false;
	parserData->pathPairMakeCopyPresent= false;
	parserData->numberOfInputFilesToMove++;
}
    break;

  case 319:

    {	if (parserData->numberOfInputFilesToMove >= osoption->job->inputFilesToMove->numberOfPathPairs)
	{	osolerror (NULL, osoption, parserData, "too many path pairs in <inputFilesToMove> element");
	};
}
    break;

  case 325:

    {	if (parserData->pathPairFromPresent)
	{	osolerror( NULL, osoption, parserData, "only one \"from\" attribute allowed");
	}
	else
	{	parserData->pathPairFromPresent = true;
		osoption->job->inputFilesToMove->pathPair[parserData->numberOfInputFilesToMove]->from = (yyvsp[(2) - (2)].sval);
	}
}
    break;

  case 327:

    {	if (parserData->pathPairToPresent)
	{	osolerror( NULL, osoption, parserData, "only one \"to\" attribute allowed");
	}
	else
	{	parserData->pathPairToPresent = true;
		osoption->job->inputFilesToMove->pathPair[parserData->numberOfInputFilesToMove]->to = (yyvsp[(2) - (2)].sval);
	}
}
    break;

  case 329:

    {	if (parserData->pathPairMakeCopyPresent)
	{	osolerror( NULL, osoption, parserData, "only one \"makeCopy\" attribute allowed");
	}
	else
	{	parserData->pathPairMakeCopyPresent = true;
		if ((yyvsp[(2) - (2)].sval) == "true")
			osoption->job->inputFilesToMove->pathPair[parserData->numberOfInputFilesToMove]->makeCopy = true;
	}
}
    break;

  case 334:

    {	if (parserData->outputDirectoriesToMovePresent)
	{	osolerror( NULL, osoption, parserData, "only one <outputDirectoriesToMove> element allowed");
	}
	else
	{	parserData->outputDirectoriesToMovePresent = true;
		osoption->job->outputDirectoriesToMove = new PathPairs();
	}
}
    break;

  case 335:

    {	if ((yyvsp[(3) - (4)].ival) <= 0) osolerror (NULL, osoption, parserData, "Require positive number of directories to move");
	osoption->job->outputDirectoriesToMove->numberOfPathPairs = (yyvsp[(3) - (4)].ival);
	osoption->job->outputDirectoriesToMove->pathPair = new PathPair*[(yyvsp[(3) - (4)].ival)];
	for (int i = 0; i < (yyvsp[(3) - (4)].ival); i++)
		osoption->job->outputDirectoriesToMove->pathPair[i] = new PathPair();
}
    break;

  case 338:

    {	if (!parserData->pathPairFromPresent)
		osolerror (NULL, osoption, parserData, "\"from\" attribute must be present");
	if (!parserData->pathPairToPresent)
		osolerror (NULL, osoption, parserData, "\"to\" attribute must be present");
	/* reset defaults for the next option */
	parserData->pathPairFromPresent= false;
	parserData->pathPairToPresent= false;
	parserData->pathPairMakeCopyPresent= false;
	parserData->numberOfOutputDirectoriesToMove++;
}
    break;

  case 339:

    {	if (parserData->numberOfOutputDirectoriesToMove >= osoption->job->outputDirectoriesToMove->numberOfPathPairs)
	{	osolerror (NULL, osoption, parserData, "too many path pairs in <outputDirectoriesToMove> element");
	};
}
    break;

  case 345:

    {	if (parserData->pathPairFromPresent)
	{	osolerror( NULL, osoption, parserData, "only one \"from\" attribute allowed");
	}
	else
	{	parserData->pathPairFromPresent = true;
		osoption->job->outputDirectoriesToMove->pathPair[parserData->numberOfOutputDirectoriesToMove]->from = (yyvsp[(2) - (2)].sval);
	}
}
    break;

  case 347:

    {	if (parserData->pathPairToPresent)
	{	osolerror( NULL, osoption, parserData, "only one \"to\" attribute allowed");
	}
	else
	{	parserData->pathPairToPresent = true;
		osoption->job->outputDirectoriesToMove->pathPair[parserData->numberOfOutputDirectoriesToMove]->to = (yyvsp[(2) - (2)].sval);
	}
}
    break;

  case 349:

    {	if (parserData->pathPairMakeCopyPresent)
	{	osolerror( NULL, osoption, parserData, "only one \"makeCopy\" attribute allowed");
	}
	else
	{	parserData->pathPairMakeCopyPresent = true;
		if ((yyvsp[(2) - (2)].sval) == "true")
			osoption->job->outputDirectoriesToMove->pathPair[parserData->numberOfOutputDirectoriesToMove]->makeCopy = true;
	}
}
    break;

  case 354:

    {	if (parserData->outputFilesToMovePresent)
	{	osolerror( NULL, osoption, parserData, "only one <outputFilesToMove> element allowed");
	}
	else
	{	parserData->outputFilesToMovePresent = true;
		osoption->job->outputFilesToMove = new PathPairs();
	}
}
    break;

  case 355:

    {	if ((yyvsp[(3) - (4)].ival) <= 0) osolerror (NULL, osoption, parserData, "Require positive number of files to move");
	osoption->job->outputFilesToMove->numberOfPathPairs = (yyvsp[(3) - (4)].ival);
	osoption->job->outputFilesToMove->pathPair = new PathPair*[(yyvsp[(3) - (4)].ival)];
	for (int i = 0; i < (yyvsp[(3) - (4)].ival); i++)
		osoption->job->outputFilesToMove->pathPair[i] = new PathPair();}
    break;

  case 358:

    {	if (!parserData->pathPairFromPresent)
		osolerror (NULL, osoption, parserData, "\"from\" attribute must be present");
	if (!parserData->pathPairToPresent)
		osolerror (NULL, osoption, parserData, "\"to\" attribute must be present");
	/* reset defaults for the next option */
	parserData->pathPairFromPresent= false;
	parserData->pathPairToPresent= false;
	parserData->pathPairMakeCopyPresent= false;
	parserData->numberOfOutputFilesToMove++;
}
    break;

  case 359:

    {	if (parserData->numberOfOutputFilesToMove >= osoption->job->outputFilesToMove->numberOfPathPairs)
	{	osolerror (NULL, osoption, parserData, "too many path pairs in <outputFilesToMove> element");
	};
}
    break;

  case 365:

    {	if (parserData->pathPairFromPresent)
	{	osolerror( NULL, osoption, parserData, "only one \"from\" attribute allowed");
	}
	else
	{	parserData->pathPairFromPresent = true;
		osoption->job->outputFilesToMove->pathPair[parserData->numberOfOutputFilesToMove]->from = (yyvsp[(2) - (2)].sval);
	}
}
    break;

  case 367:

    {	if (parserData->pathPairToPresent)
	{	osolerror( NULL, osoption, parserData, "only one \"to\" attribute allowed");
	}
	else
	{	parserData->pathPairToPresent = true;
		osoption->job->outputFilesToMove->pathPair[parserData->numberOfOutputFilesToMove]->to = (yyvsp[(2) - (2)].sval);
	}
}
    break;

  case 369:

    {	if (parserData->pathPairMakeCopyPresent)
	{	osolerror( NULL, osoption, parserData, "only one \"makeCopy\" attribute allowed");
	}
	else
	{	parserData->pathPairMakeCopyPresent = true;
		if ((yyvsp[(2) - (2)].sval) == "true")
			osoption->job->outputFilesToMove->pathPair[parserData->numberOfOutputFilesToMove]->makeCopy = true;
	}
}
    break;

  case 374:

    {	if (parserData->filesToDeletePresent)
	{	osolerror( NULL, osoption, parserData, "only one <filesToDelete> element allowed");
	}
	else
	{	parserData->filesToDeletePresent = true;
		osoption->job->filesToDelete = new DirectoriesAndFiles();
	}
}
    break;

  case 375:

    {	osoption->job->filesToDelete->numberOfPaths = (yyvsp[(3) - (4)].ival);
	osoption->job->filesToDelete->path = new std::string[(yyvsp[(3) - (4)].ival)];
}
    break;

  case 378:

    {	if (parserData->numberOfFilesToDelete >= osoption->job->filesToDelete->numberOfPaths)
	{	osolerror (NULL, osoption, parserData, "too many job IDs in <filesToDelete> element");
	}
	else
	{	osoption->job->filesToDelete->path[parserData->numberOfFilesToDelete] = (yyvsp[(3) - (3)].sval);
		parserData->numberOfFilesToDelete++;
	};
}
    break;

  case 381:

    {	if (parserData->directoriesToDeletePresent)
	{	osolerror( NULL, osoption, parserData, "only one <directoriesToDelete> element allowed");
	}
	else
	{	parserData->directoriesToDeletePresent = true;
		osoption->job->directoriesToDelete = new DirectoriesAndFiles();
	}
}
    break;

  case 382:

    {	osoption->job->directoriesToDelete->numberOfPaths = (yyvsp[(3) - (4)].ival);
	osoption->job->directoriesToDelete->path = new std::string[(yyvsp[(3) - (4)].ival)];
}
    break;

  case 385:

    {	if (parserData->numberOfDirectoriesToDelete >= osoption->job->directoriesToDelete->numberOfPaths)
	{	osolerror (NULL, osoption, parserData, "too many job IDs in <directoriesToDelete> element");
	}
	else
	{	osoption->job->directoriesToDelete->path[parserData->numberOfDirectoriesToDelete] = (yyvsp[(3) - (3)].sval);
		parserData->numberOfDirectoriesToDelete++;
	};
}
    break;

  case 388:

    {	if (parserData->processesToKillPresent)
	{	osolerror( NULL, osoption, parserData, "only one <processesToKill> element allowed");
	}
	else
	{	parserData->processesToKillPresent = true;
		osoption->job->processesToKill = new Processes();
	}
}
    break;

  case 389:

    {	osoption->job->processesToKill->numberOfProcesses = (yyvsp[(3) - (4)].ival);
	osoption->job->processesToKill->process = new std::string[(yyvsp[(3) - (4)].ival)];
}
    break;

  case 392:

    {	if (parserData->numberOfProcessesToKill >= osoption->job->processesToKill->numberOfProcesses)
	{	osolerror (NULL, osoption, parserData, "too many job IDs in <processesToKill> element");
	}
	else
	{	osoption->job->processesToKill->process[parserData->numberOfProcessesToKill] = (yyvsp[(3) - (3)].sval);
		parserData->numberOfProcessesToKill++;
	};
}
    break;

  case 395:

    {	if (parserData->otherJobOptionsPresent)
	{	osolerror( NULL, osoption, parserData, "only one <otherOptions> element allowed");
	}
	else
	{	parserData->otherJobOptionsPresent = true;
		osoption->job->otherOptions = new OtherOptions();
	}
}
    break;

  case 396:

    {	osoption->job->otherOptions->numberOfOtherOptions = (yyvsp[(3) - (4)].ival);
	osoption->job->otherOptions->other = new OtherOption*[(yyvsp[(3) - (4)].ival)];
	for (int i=0; i < (yyvsp[(3) - (4)].ival); i++) osoption->job->otherOptions->other[i] = new OtherOption();
}
    break;

  case 397:

    {	if (parserData->numberOfOtherJobOptions != osoption->job->otherOptions->numberOfOtherOptions)
		osolerror (NULL, osoption, parserData, "wrong number of other options in <job> element");
}
    break;

  case 400:

    {	if (parserData->numberOfOtherJobOptions >= osoption->job->otherOptions->numberOfOtherOptions)
		{	osolerror (NULL, osoption, parserData, "too many other options in <job> element");
		};
	}
    break;

  case 401:

    {	if (!parserData->otherOptionNamePresent)
		osolerror (NULL, osoption, parserData, "name attribute must be present");
	/* reset defaults for the next option */
	parserData->otherOptionNamePresent = false;
	parserData->otherOptionValuePresent = false;
	parserData->otherOptionDescriptionPresent = false;
	parserData->numberOfOtherJobOptions++;
}
    break;

  case 407:

    {	if (parserData->otherOptionNamePresent)
	{	osolerror( NULL, osoption, parserData, "only one name attribute allowed");
	}
	else
	{	parserData->otherOptionNamePresent = true;
		osoption->job->otherOptions->other[parserData->numberOfOtherJobOptions]->name = (yyvsp[(2) - (2)].sval);
	}
}
    break;

  case 409:

    {	if (parserData->otherOptionValuePresent)
	{	osolerror( NULL, osoption, parserData, "only one value attribute allowed");
	}
	else
	{	parserData->otherOptionValuePresent = true;
		osoption->job->otherOptions->other[parserData->numberOfOtherJobOptions]->value = (yyvsp[(2) - (2)].sval);
	}
}
    break;

  case 411:

    {	if (parserData->otherOptionDescriptionPresent)
	{	osolerror( NULL, osoption, parserData, "only one description attribute allowed");
	}
	else
	{	parserData->otherOptionDescriptionPresent = true;
		osoption->job->otherOptions->other[parserData->numberOfOtherJobOptions]->description = (yyvsp[(2) - (2)].sval);
	}
}
    break;

  case 417:

    {	if (parserData->osoloptimizationPresent)
	{	osolerror( NULL, osoption, parserData, "only one <optimization> element allowed");
	}
	else
	{	parserData->osoloptimizationPresent = true;
		osoption->optimization = new OptimizationOption();
	}
}
    break;

  case 423:

    {	osoption->optimization->numberOfVariables = (yyvsp[(3) - (4)].ival);
}
    break;

  case 424:

    {	osoption->optimization->numberOfConstraints = (yyvsp[(3) - (4)].ival);
}
    break;

  case 425:

    {	osoption->optimization->numberOfObjectives = (yyvsp[(3) - (4)].ival);
}
    break;

  case 431:

    {	osoption->optimization->variables = new VariableOption();
}
    break;

  case 433:

    {	if ((yyvsp[(3) - (4)].ival) < 0) osolerror (NULL, osoption, parserData, "number of <other> variable options cannot be negative");
	osoption->optimization->variables->numberOfOtherVariableOptions = (yyvsp[(3) - (4)].ival);
	osoption->optimization->variables->other = new OtherVariableOption*[(yyvsp[(3) - (4)].ival)];
	for (int i= 0; i < (yyvsp[(3) - (4)].ival); i++)
		osoption->optimization->variables->other[i] = new OtherVariableOption();
}
    break;

  case 438:

    {	if ((yyvsp[(3) - (4)].ival) <= 0) osolerror (NULL, osoption, parserData, "number of <var> elements must be positive");
	osoption->optimization->variables->initialVariableValues = new InitVariableValues();
	osoption->optimization->variables->initialVariableValues->numberOfVar = (yyvsp[(3) - (4)].ival);
	osoption->optimization->variables->initialVariableValues->var = new InitVarValue*[(yyvsp[(3) - (4)].ival)];
	for (int i = 0; i < (yyvsp[(3) - (4)].ival); i++)
		osoption->optimization->variables->initialVariableValues->var[i] = new InitVarValue();
}
    break;

  case 441:

    {	if (!parserData->idxAttributePresent)
		osolerror (NULL, osoption, parserData, "variable index required");
	parserData->idxAttributePresent = false;
	parserData->valAttributePresent = false;
	parserData->numberOfVar++;
}
    break;

  case 442:

    {	if (parserData->numberOfVar >= osoption->optimization->variables->initialVariableValues->numberOfVar)
		osolerror(NULL, osoption, parserData, "too many initial variable values");
}
    break;

  case 447:

    {	if (parserData->idxAttributePresent)
		osolerror (NULL, osoption, parserData, "only one variable index allowed");
	parserData->idxAttributePresent = true;
	if ((yyvsp[(3) - (4)].ival) < 0) osolerror (NULL, osoption, parserData, "variable index must be nonnegative");
	if (parserData->numberOfVariablesPresent)
	{	if ((yyvsp[(3) - (4)].ival) >= parserData->numberOfVariables)
			osolerror (NULL, osoption, parserData, "variable index exceeds upper limit");
	};
	osoption->optimization->variables->initialVariableValues->var[parserData->numberOfVar]->idx = (yyvsp[(3) - (4)].ival);
}
    break;

  case 448:

    {	if (parserData->valAttributePresent)
		osolerror (NULL, osoption, parserData, "only one variable value allowed");
	parserData->valAttributePresent = true;
	if (strncmp((yyvsp[(2) - (2)].sval),"INF",3) == 0)
		osoption->optimization->variables->initialVariableValues->var[parserData->numberOfVar]->value = OSDBL_MAX;
	else if (strncmp((yyvsp[(2) - (2)].sval),"-INF",4) == 0)
		osoption->optimization->variables->initialVariableValues->var[parserData->numberOfVar]->value = -OSDBL_MAX;
	else
		osoption->optimization->variables->initialVariableValues->var[parserData->numberOfVar]->value = os_strtod((yyvsp[(2) - (2)].sval), NULL);
}
    break;

  case 454:

    {	if ((yyvsp[(3) - (4)].ival) <= 0) osolerror (NULL, osoption, parserData, "number of <var> elements must be positive");
	osoption->optimization->variables->initialVariableValuesString = new InitVariableValuesString ();
	osoption->optimization->variables->initialVariableValuesString->numberOfVar = (yyvsp[(3) - (4)].ival);
	osoption->optimization->variables->initialVariableValuesString->var = new InitVarValueString*[(yyvsp[(3) - (4)].ival)];
	for (int i = 0; i < (yyvsp[(3) - (4)].ival); i++)
		osoption->optimization->variables->initialVariableValuesString->var[i] = new InitVarValueString ();
}
    break;

  case 457:

    {	if (!parserData->idxAttributePresent)
		osolerror (NULL, osoption, parserData, "variable index required");
	parserData->idxAttributePresent = false;
	parserData->valAttributePresent = false;
	parserData->numberOfVarStr++;
}
    break;

  case 458:

    {	if (parserData->numberOfVarStr >= osoption->optimization->variables->initialVariableValuesString->numberOfVar)
		osolerror(NULL, osoption, parserData, "too many initial variable strings");
}
    break;

  case 463:

    {	if (parserData->idxAttributePresent)
		osolerror (NULL, osoption, parserData, "only one variable index allowed");
	parserData->idxAttributePresent = true;
	if ((yyvsp[(3) - (4)].ival) < 0) osolerror (NULL, osoption, parserData, "variable index must be nonnegative");
	if (parserData->numberOfVariablesPresent)
	{	if ((yyvsp[(3) - (4)].ival) >= parserData->numberOfVariables)
			osolerror (NULL, osoption, parserData, "variable index exceeds upper limit");
	};
	osoption->optimization->variables->initialVariableValuesString->var[parserData->numberOfVarStr]->idx = (yyvsp[(3) - (4)].ival);
}
    break;

  case 464:

    {	if (parserData->valAttributePresent)
		osolerror (NULL, osoption, parserData, "only one variable index allowed");
	parserData->valAttributePresent = true;
	osoption->optimization->variables->initialVariableValuesString->var[parserData->numberOfVarStr]->value = (yyvsp[(2) - (2)].sval);
}
    break;

  case 471:

    {	if (parserData->numberOfOtherVariableOptions >= osoption->optimization->variables->numberOfOtherVariableOptions)
		osolerror(NULL, osoption, parserData, "too many <other> variable options");
}
    break;

  case 481:

    { 	if (parserData->otherOptionNumberPresent)
		osolerror (NULL, osoption, parserData, "only one numberOfVar attribute allowed");
	parserData->otherOptionNumberPresent = true;
	parserData->numberOfVar = 0;
	if ((yyvsp[(3) - (4)].ival) < 0) osolerror (NULL, osoption, parserData, "number of <other> variable options must be nonnegative");
	osoption->optimization->variables->other[parserData->numberOfOtherVariableOptions]->numberOfVar = (yyvsp[(3) - (4)].ival);
	osoption->optimization->variables->other[parserData->numberOfOtherVariableOptions]->var = new OtherVarOption*[(yyvsp[(3) - (4)].ival)];
	for (int i = 0; i < (yyvsp[(3) - (4)].ival); i++)
		osoption->optimization->variables->other[parserData->numberOfOtherVariableOptions]->var[i] = new OtherVarOption();	
}
    break;

  case 482:

    {	if (parserData->otherOptionNamePresent)
		osolerror (NULL, osoption, parserData, "only one name attribute allowed");
	parserData->otherOptionNamePresent = true;
	osoption->optimization->variables->other[parserData->numberOfOtherVariableOptions]->name = (yyvsp[(2) - (2)].sval);
}
    break;

  case 484:

    {	if (parserData->otherOptionValuePresent)
		osolerror (NULL, osoption, parserData, "only one value attribute allowed");
	parserData->otherOptionValuePresent = true;
	osoption->optimization->variables->other[parserData->numberOfOtherVariableOptions]->value = (yyvsp[(2) - (2)].sval);
}
    break;

  case 486:

    {	if (parserData->otherOptionSolverPresent)
		osolerror (NULL, osoption, parserData, "only one solver attribute allowed");
	parserData->otherOptionSolverPresent = true;
	osoption->optimization->variables->other[parserData->numberOfOtherVariableOptions]->solver = (yyvsp[(2) - (2)].sval);
}
    break;

  case 488:

    {	if (parserData->otherOptionCategoryPresent)
		osolerror (NULL, osoption, parserData, "only one category attribute allowed");
	parserData->otherOptionCategoryPresent = true;
	osoption->optimization->variables->other[parserData->numberOfOtherVariableOptions]->category = (yyvsp[(2) - (2)].sval);
}
    break;

  case 490:

    {	if (parserData->otherOptionTypePresent)
		osolerror (NULL, osoption, parserData, "only one type attribute allowed");
	parserData->otherOptionTypePresent = true;
	osoption->optimization->variables->other[parserData->numberOfOtherVariableOptions]->type = (yyvsp[(2) - (2)].sval);
}
    break;

  case 492:

    {	if (parserData->otherOptionDescriptionPresent)
		osolerror (NULL, osoption, parserData, "only one description attribute allowed");
	parserData->otherOptionDescriptionPresent = true;
	osoption->optimization->variables->other[parserData->numberOfOtherVariableOptions]->description = (yyvsp[(2) - (2)].sval);
}
    break;

  case 494:

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
}
    break;

  case 497:

    {	if (!parserData->idxAttributePresent)
		osolerror(NULL, osoption, parserData, "required idx attribute was not found");
	parserData->idxAttributePresent = false;
	parserData->valAttributePresent = false;
	parserData->lbvalAttributePresent = false;
	parserData->ubvalAttributePresent = false;
	parserData->numberOfVar++;
}
    break;

  case 498:

    {	if (parserData->numberOfVar >= osoption->optimization->variables->other[parserData->numberOfOtherVariableOptions]->numberOfVar)
		osolerror(NULL, osoption, parserData, "too many <var> entries in <other> variable element");
}
    break;

  case 505:

    {	if (parserData->idxAttributePresent)
		osolerror (NULL, osoption, parserData, "only one variable index allowed");
	parserData->idxAttributePresent = true;
	if ((yyvsp[(3) - (4)].ival) < 0) osolerror (NULL, osoption, parserData, "variable index must be nonnegative");
	if (parserData->numberOfVariablesPresent)
	{	if ((yyvsp[(3) - (4)].ival) >= parserData->numberOfVariables)
			osolerror (NULL, osoption, parserData, "variable index exceeds upper limit");
	};
	osoption->optimization->variables->other[parserData->numberOfOtherVariableOptions]->var[parserData->numberOfVar]->idx = (yyvsp[(3) - (4)].ival);
}
    break;

  case 506:

    {	if (parserData->valAttributePresent)
		osolerror (NULL, osoption, parserData, "only one variable value allowed");
	parserData->valAttributePresent = true;
	osoption->optimization->variables-> other[parserData->numberOfOtherVariableOptions]->var[parserData->numberOfVar]->value = (yyvsp[(2) - (2)].sval);
}
    break;

  case 508:

    {	if (parserData->lbvalAttributePresent)
		osolerror (NULL, osoption, parserData, "only one lower bound value allowed");
	parserData->lbvalAttributePresent = true;
	osoption->optimization->variables-> other[parserData->numberOfOtherVariableOptions]->var[parserData->numberOfVar]->lbValue = (yyvsp[(2) - (2)].sval);
}
    break;

  case 510:

    {	if (parserData->ubvalAttributePresent)
		osolerror (NULL, osoption, parserData, "only one upper bound value allowed");
	parserData->ubvalAttributePresent = true;
	osoption->optimization->variables-> other[parserData->numberOfOtherVariableOptions]->var[parserData->numberOfVar]->ubValue = (yyvsp[(2) - (2)].sval);
}
    break;

  case 516:

    {	osoption->optimization->objectives = new ObjectiveOption();
}
    break;

  case 518:

    {	if ((yyvsp[(3) - (4)].ival) < 0) osolerror (NULL, osoption, parserData, "number of <other> objective options cannot be negative");
        osoption->optimization->objectives->numberOfOtherObjectiveOptions = (yyvsp[(3) - (4)].ival);
	osoption->optimization->objectives->other = new OtherObjectiveOption*[(yyvsp[(3) - (4)].ival)];
	for (int i= 0; i < (yyvsp[(3) - (4)].ival); i++)
		osoption->optimization->objectives->other[i] = new OtherObjectiveOption();
}
    break;

  case 523:

    {	if ((yyvsp[(3) - (4)].ival) <= 0) osolerror (NULL, osoption, parserData, "number of <obj> elements must be positive");
	osoption->optimization->objectives->initialObjectiveValues = new InitObjectiveValues();
	osoption->optimization->objectives->initialObjectiveValues->numberOfObj = (yyvsp[(3) - (4)].ival);
	osoption->optimization->objectives->initialObjectiveValues->obj = new InitObjValue*[(yyvsp[(3) - (4)].ival)];
	for (int i = 0; i < (yyvsp[(3) - (4)].ival); i++)
		osoption->optimization->objectives->initialObjectiveValues->obj[i] = new InitObjValue();
}
    break;

  case 526:

    {	if (!parserData->idxAttributePresent)
		osolerror (NULL, osoption, parserData, "objective index required");
	parserData->idxAttributePresent = false;
	parserData->valAttributePresent = false;
	parserData->numberOfObjValues++;
}
    break;

  case 527:

    {	if (parserData->numberOfObjValues >= osoption->optimization->objectives->initialObjectiveValues->numberOfObj)
		osolerror(NULL, osoption, parserData, "too many initial objective values");
}
    break;

  case 532:

    {	if (parserData->idxAttributePresent)
		osolerror (NULL, osoption, parserData, "only one objective index allowed");
	parserData->idxAttributePresent = true;
	if ((yyvsp[(3) - (4)].ival) >= 0) osolerror (NULL, osoption, parserData, "objective index must be negative");
	if (parserData->numberOfObjectivesPresent)
	{	if (-(yyvsp[(3) - (4)].ival) > parserData->numberOfObjectives)
			osolerror (NULL, osoption, parserData, "objective index out of range");
	};
	osoption->optimization->objectives->initialObjectiveValues->obj[parserData->numberOfObjValues]->idx = (yyvsp[(3) - (4)].ival);
}
    break;

  case 533:

    {	if (parserData->valAttributePresent)
		osolerror (NULL, osoption, parserData, "only one objective value allowed");
	parserData->valAttributePresent = true;
	if (strncmp((yyvsp[(2) - (2)].sval),"INF",3) == 0)
		osoption->optimization->objectives->initialObjectiveValues->obj[parserData->numberOfObjValues]->value = OSDBL_MAX;
	else if (strncmp((yyvsp[(2) - (2)].sval),"-INF",4) == 0)
		osoption->optimization->objectives->initialObjectiveValues->obj[parserData->numberOfObjValues]->value = -OSDBL_MAX;
	else
		osoption->optimization->objectives->initialObjectiveValues->obj[parserData->numberOfObjValues]->value = os_strtod((yyvsp[(2) - (2)].sval), NULL);
}
    break;

  case 539:

    {	if ((yyvsp[(3) - (4)].ival) <= 0) osolerror (NULL, osoption, parserData, "number of <obj> elements must be positive");
	osoption->optimization->objectives->initialObjectiveBounds = new InitObjectiveBounds();
	osoption->optimization->objectives->initialObjectiveBounds->numberOfObj = (yyvsp[(3) - (4)].ival);
	osoption->optimization->objectives->initialObjectiveBounds->obj = new InitObjBound*[(yyvsp[(3) - (4)].ival)];
	for (int i = 0; i < (yyvsp[(3) - (4)].ival); i++)
		osoption->optimization->objectives->initialObjectiveBounds->obj[i] = new InitObjBound ();
}
    break;

  case 542:

    {	if (!parserData->idxAttributePresent)
		osolerror (NULL, osoption, parserData, "objective index required");
	parserData->idxAttributePresent = false;
	parserData->lbvalAttributePresent = false;
	parserData->ubvalAttributePresent = false;
	parserData->numberOfObjBounds++;
}
    break;

  case 543:

    {	if (parserData->numberOfObjBounds >= osoption->optimization->objectives->initialObjectiveBounds->numberOfObj)
		osolerror(NULL, osoption, parserData, "too many initial objective bounds");
}
    break;

  case 549:

    {	if (parserData->idxAttributePresent)
		osolerror (NULL, osoption, parserData, "only one objective index allowed");
	parserData->idxAttributePresent = true;
	if ((yyvsp[(3) - (4)].ival) >= 0) osolerror (NULL, osoption, parserData, "objective index must be negative");
	if (parserData->numberOfObjectivesPresent)
	{	if (-(yyvsp[(3) - (4)].ival) > parserData->numberOfObjectives)
			osolerror (NULL, osoption, parserData, "objective index out of range");
	};
	osoption->optimization->objectives->initialObjectiveBounds->obj[parserData->numberOfObjBounds]->idx = (yyvsp[(3) - (4)].ival);
}
    break;

  case 550:

    {	if (parserData->lbvalAttributePresent)
		osolerror (NULL, osoption, parserData, "only one objective lower bound allowed");
	parserData->lbvalAttributePresent = true;
	if (strncmp((yyvsp[(2) - (2)].sval),"INF",3) == 0)
		osoption->optimization->objectives->initialObjectiveBounds->obj[parserData->numberOfObjBounds]->lbValue = OSDBL_MAX;
	else if (strncmp((yyvsp[(2) - (2)].sval),"-INF",4) == 0)
		osoption->optimization->objectives->initialObjectiveBounds->obj[parserData->numberOfObjBounds]->lbValue = -OSDBL_MAX;
	else
		osoption->optimization->objectives->initialObjectiveBounds->obj[parserData->numberOfObjBounds]->lbValue = os_strtod((yyvsp[(2) - (2)].sval), NULL);
}
    break;

  case 552:

    {	if (parserData->ubvalAttributePresent)
		osolerror (NULL, osoption, parserData, "only one objective upper bound allowed");
	parserData->ubvalAttributePresent = true;
	if (strncmp((yyvsp[(2) - (2)].sval),"INF",3) == 0)
		osoption->optimization->objectives->initialObjectiveBounds->obj[parserData->numberOfObjBounds]->ubValue = OSDBL_MAX;
	else if (strncmp((yyvsp[(2) - (2)].sval),"-INF",4) == 0)
		osoption->optimization->objectives->initialObjectiveBounds->obj[parserData->numberOfObjBounds]->ubValue = -OSDBL_MAX;
	else
		osoption->optimization->objectives->initialObjectiveBounds->obj[parserData->numberOfObjBounds]->ubValue = os_strtod((yyvsp[(2) - (2)].sval), NULL);
}
    break;

  case 559:

    {	if (parserData->numberOfOtherObjectiveOptions >= osoption->optimization->objectives->numberOfOtherObjectiveOptions)
		osolerror(NULL, osoption, parserData, "too many <other> objective options");
}
    break;

  case 569:

    { 	if (parserData->otherOptionNumberPresent)
		osolerror (NULL, osoption, parserData, "only one numberOfObj attribute allowed");
	parserData->otherOptionNumberPresent = true;
	parserData->numberOfObj = 0;
	if ((yyvsp[(3) - (4)].ival) < 0) osolerror (NULL, osoption, parserData, "number of <other> objective options must be nonnegative");
	osoption->optimization->objectives->other[parserData->numberOfOtherObjectiveOptions]->numberOfObj = (yyvsp[(3) - (4)].ival);
	osoption->optimization->objectives->other[parserData->numberOfOtherObjectiveOptions]->obj = new OtherObjOption*[(yyvsp[(3) - (4)].ival)];
	for (int i = 0; i < (yyvsp[(3) - (4)].ival); i++)
		osoption->optimization->objectives->other[parserData->numberOfOtherObjectiveOptions]->obj[i] = new OtherObjOption();
}
    break;

  case 570:

    {	if (parserData->otherOptionNamePresent)
		osolerror (NULL, osoption, parserData, "only one name attribute allowed");
	parserData->otherOptionNamePresent = true;
	osoption->optimization->objectives->other[parserData->numberOfOtherObjectiveOptions]->name = (yyvsp[(2) - (2)].sval);
}
    break;

  case 572:

    {	if (parserData->otherOptionValuePresent)
		osolerror (NULL, osoption, parserData, "only one value attribute allowed");
	parserData->otherOptionValuePresent = true;
	osoption->optimization->objectives->other[parserData->numberOfOtherObjectiveOptions]->value = (yyvsp[(2) - (2)].sval);
}
    break;

  case 574:

    {	if (parserData->otherOptionSolverPresent)
		osolerror (NULL, osoption, parserData, "only one solver attribute allowed");
	parserData->otherOptionSolverPresent = true;
	osoption->optimization->objectives->other[parserData->numberOfOtherObjectiveOptions]->solver = (yyvsp[(2) - (2)].sval);
}
    break;

  case 576:

    {	if (parserData->otherOptionCategoryPresent)
		osolerror (NULL, osoption, parserData, "only one category attribute allowed");
	parserData->otherOptionCategoryPresent = true;
	osoption->optimization->objectives->other[parserData->numberOfOtherObjectiveOptions]->category = (yyvsp[(2) - (2)].sval);
}
    break;

  case 578:

    {	if (parserData->otherOptionTypePresent)
		osolerror (NULL, osoption, parserData, "only one type attribute allowed");
	parserData->otherOptionTypePresent = true;
	osoption->optimization->objectives->other[parserData->numberOfOtherObjectiveOptions]->type = (yyvsp[(2) - (2)].sval);
}
    break;

  case 580:

    {	if (parserData->otherOptionDescriptionPresent)
		osolerror (NULL, osoption, parserData, "only one description attribute allowed");
	parserData->otherOptionDescriptionPresent = true;
	osoption->optimization->objectives->other[parserData->numberOfOtherObjectiveOptions]->description = (yyvsp[(2) - (2)].sval);
}
    break;

  case 582:

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
}
    break;

  case 585:

    {	if (!parserData->idxAttributePresent)
		osolerror(NULL, osoption, parserData, "required idx attribute was not found");
	parserData->idxAttributePresent = false;
	parserData->valAttributePresent = false;
	parserData->lbvalAttributePresent = false;
	parserData->ubvalAttributePresent = false;
	parserData->numberOfObj++;
}
    break;

  case 586:

    {	if (parserData->numberOfObj >= osoption->optimization->objectives->other[parserData->numberOfOtherObjectiveOptions]->numberOfObj)
		osolerror(NULL, osoption, parserData, "too many <obj> entries in <other> objective element");
}
    break;

  case 593:

    {	if (parserData->idxAttributePresent)
		osolerror (NULL, osoption, parserData, "only one objective index allowed");
	parserData->idxAttributePresent = true;
	if ((yyvsp[(3) - (4)].ival) >= 0) osolerror (NULL, osoption, parserData, "objective index must be negative");
	if (parserData->numberOfObjectivesPresent)
	{	if (-(yyvsp[(3) - (4)].ival) > parserData->numberOfObjectives)
			osolerror (NULL, osoption, parserData, "objecive index exceeds upper limit");
	};
	osoption->optimization->objectives->other[parserData->numberOfOtherObjectiveOptions]->obj[parserData->numberOfObj]->idx = (yyvsp[(3) - (4)].ival);
}
    break;

  case 594:

    {	if (parserData->valAttributePresent)
		osolerror (NULL, osoption, parserData, "only one variable value allowed");
	parserData->valAttributePresent = true;
	osoption->optimization->objectives-> other[parserData->numberOfOtherObjectiveOptions]->obj[parserData->numberOfObj]->value = (yyvsp[(2) - (2)].sval);
}
    break;

  case 596:

    {	if (parserData->lbvalAttributePresent)
		osolerror (NULL, osoption, parserData, "only one lower bound value allowed");
	parserData->lbvalAttributePresent = true;
	osoption->optimization->objectives-> other[parserData->numberOfOtherObjectiveOptions]->obj[parserData->numberOfObj]->lbValue = (yyvsp[(2) - (2)].sval);
}
    break;

  case 598:

    {	if (parserData->ubvalAttributePresent)
		osolerror (NULL, osoption, parserData, "only one upper bound value allowed");
	parserData->ubvalAttributePresent = true;
	osoption->optimization->objectives-> other[parserData->numberOfOtherObjectiveOptions]->obj[parserData->numberOfObj]->ubValue = (yyvsp[(2) - (2)].sval);
}
    break;

  case 604:

    {	osoption->optimization->constraints = new ConstraintOption();
}
    break;

  case 606:

    {	if ((yyvsp[(3) - (4)].ival) < 0) osolerror (NULL, osoption, parserData, "number of <other> constraint options cannot be negative");
        osoption->optimization->constraints->numberOfOtherConstraintOptions = (yyvsp[(3) - (4)].ival);
	osoption->optimization->constraints->other = new OtherConstraintOption*[(yyvsp[(3) - (4)].ival)];
	for (int i= 0; i < (yyvsp[(3) - (4)].ival); i++)
		osoption->optimization->constraints->other[i] = new OtherConstraintOption();
}
    break;

  case 611:

    {	if ((yyvsp[(3) - (4)].ival) <= 0) osolerror (NULL, osoption, parserData, "number of <con> elements must be positive");
	osoption->optimization->constraints->initialConstraintValues = new InitConstraintValues();
	osoption->optimization->constraints->initialConstraintValues->numberOfCon = (yyvsp[(3) - (4)].ival);
	osoption->optimization->constraints->initialConstraintValues->con = new InitConValue*[(yyvsp[(3) - (4)].ival)];
	for (int i = 0; i < (yyvsp[(3) - (4)].ival); i++)
		osoption->optimization->constraints->initialConstraintValues->con[i] = new InitConValue();
}
    break;

  case 614:

    {	if (!parserData->idxAttributePresent)
		osolerror (NULL, osoption, parserData, "variable index required");
	parserData->idxAttributePresent = false;
	parserData->valAttributePresent = false;
	parserData->numberOfCon++;
}
    break;

  case 615:

    {	if (parserData->numberOfCon >= osoption->optimization->constraints->initialConstraintValues->numberOfCon)
		osolerror(NULL, osoption, parserData, "too many initial constraint values");
}
    break;

  case 620:

    {	if (parserData->idxAttributePresent)
		osolerror (NULL, osoption, parserData, "only one constraint index allowed");
	parserData->idxAttributePresent = true;
	if ((yyvsp[(3) - (4)].ival) < 0) osolerror (NULL, osoption, parserData, "constraint index must be nonnegative");
	if (parserData->numberOfConstraintsPresent)
	{	if ((yyvsp[(3) - (4)].ival) > parserData->numberOfConstraints)
			osolerror (NULL, osoption, parserData, "constraint index out of range");
	};
	osoption->optimization->constraints->initialConstraintValues->con[parserData->numberOfCon]->idx = (yyvsp[(3) - (4)].ival);
}
    break;

  case 621:

    {	if (parserData->valAttributePresent)
		osolerror (NULL, osoption, parserData, "only one constraint value allowed");
	parserData->valAttributePresent = true;
	if (strncmp((yyvsp[(2) - (2)].sval),"INF",3) == 0)
		osoption->optimization->constraints->initialConstraintValues->con[parserData->numberOfCon]->value = OSDBL_MAX;
	else if (strncmp((yyvsp[(2) - (2)].sval),"-INF",4) == 0)
		osoption->optimization->constraints->initialConstraintValues->con[parserData->numberOfCon]->value = -OSDBL_MAX;
	else
		osoption->optimization->constraints->initialConstraintValues->con[parserData->numberOfCon]->value = os_strtod((yyvsp[(2) - (2)].sval), NULL);
}
    break;

  case 627:

    {	if ((yyvsp[(3) - (4)].ival) <= 0) osolerror (NULL, osoption, parserData, "number of <con> elements must be positive");
	osoption->optimization->constraints->initialDualValues = new InitDualVariableValues();
	osoption->optimization->constraints->initialDualValues->numberOfCon = (yyvsp[(3) - (4)].ival);
	osoption->optimization->constraints->initialDualValues->con = new InitDualVarValue*[(yyvsp[(3) - (4)].ival)];
	for (int i = 0; i < (yyvsp[(3) - (4)].ival); i++)
		osoption->optimization->constraints->initialDualValues->con[i] = new InitDualVarValue ();
}
    break;

  case 630:

    {	if (!parserData->idxAttributePresent)
		osolerror (NULL, osoption, parserData, "constraint index required");
	parserData->idxAttributePresent = false;
	parserData->lbvalAttributePresent = false;
	parserData->ubvalAttributePresent = false;
	parserData->numberOfDuals++;
}
    break;

  case 631:

    {	if (parserData->numberOfDuals >= osoption->optimization->constraints->initialDualValues->numberOfCon)
		osolerror(NULL, osoption, parserData, "too many initial dual variable bounds");
}
    break;

  case 637:

    {	if (parserData->idxAttributePresent)
		osolerror (NULL, osoption, parserData, "only one constraint index allowed");
	parserData->idxAttributePresent = true;
	if ((yyvsp[(3) - (4)].ival) < 0) osolerror (NULL, osoption, parserData, "constraint index must be nonnegative");
	if (parserData->numberOfConstraintsPresent)
	{	if ((yyvsp[(3) - (4)].ival) > parserData->numberOfConstraints)
			osolerror (NULL, osoption, parserData, "constraint index out of range");
	};
	osoption->optimization->constraints->initialDualValues->con[parserData->numberOfDuals]->idx = (yyvsp[(3) - (4)].ival);
}
    break;

  case 638:

    {	if (parserData->lbvalAttributePresent)
		osolerror (NULL, osoption, parserData, "only one dual variable lower bound allowed");
	parserData->lbvalAttributePresent = true;
	if (strncmp((yyvsp[(2) - (2)].sval),"INF",3) == 0)
		osoption->optimization->constraints->initialDualValues->con[parserData->numberOfDuals]->lbValue = OSDBL_MAX;
	else if (strncmp((yyvsp[(2) - (2)].sval),"-INF",4) == 0)
		osoption->optimization->constraints->initialDualValues->con[parserData->numberOfDuals]->lbValue = -OSDBL_MAX;
	else
		osoption->optimization->constraints->initialDualValues->con[parserData->numberOfDuals]->lbValue = os_strtod((yyvsp[(2) - (2)].sval), NULL);
}
    break;

  case 640:

    {	if (parserData->ubvalAttributePresent)
		osolerror (NULL, osoption, parserData, "only one dual variable upper bound allowed");
	parserData->ubvalAttributePresent = true;
	if (strncmp((yyvsp[(2) - (2)].sval),"INF",3) == 0)
		osoption->optimization->constraints->initialDualValues->con[parserData->numberOfDuals]->ubValue = OSDBL_MAX;
	else if (strncmp((yyvsp[(2) - (2)].sval),"-INF",4) == 0)
		osoption->optimization->constraints->initialDualValues->con[parserData->numberOfDuals]->ubValue = -OSDBL_MAX;
	else
		osoption->optimization->constraints->initialDualValues->con[parserData->numberOfDuals]->ubValue = os_strtod((yyvsp[(2) - (2)].sval), NULL);
}
    break;

  case 647:

    {	if (parserData->numberOfOtherConstraintOptions >= osoption->optimization->constraints->numberOfOtherConstraintOptions)
		osolerror(NULL, osoption, parserData, "too many <other> constraint options");
}
    break;

  case 657:

    { 	if (parserData->otherOptionNumberPresent)
		osolerror (NULL, osoption, parserData, "only one numberOfCon attribute allowed");
	parserData->otherOptionNumberPresent = true;
	parserData->numberOfCon = 0;
	if ((yyvsp[(3) - (4)].ival) < 0) osolerror (NULL, osoption, parserData, "number of <other> constraint options must be nonnegative");
	osoption->optimization->constraints->other[parserData->numberOfOtherConstraintOptions]->numberOfCon = (yyvsp[(3) - (4)].ival);
	osoption->optimization->constraints->other[parserData->numberOfOtherConstraintOptions]->con = new OtherConOption*[(yyvsp[(3) - (4)].ival)];
	for (int i = 0; i < (yyvsp[(3) - (4)].ival); i++)
		osoption->optimization->constraints->other[parserData->numberOfOtherConstraintOptions]->con[i] = new OtherConOption();
}
    break;

  case 658:

    {	if (parserData->otherOptionNamePresent)
		osolerror (NULL, osoption, parserData, "only one name attribute allowed");
	parserData->otherOptionNamePresent = true;
	osoption->optimization->constraints->other[parserData->numberOfOtherConstraintOptions]->name = (yyvsp[(2) - (2)].sval);
}
    break;

  case 660:

    {	if (parserData->otherOptionValuePresent)
		osolerror (NULL, osoption, parserData, "only one value attribute allowed");
	parserData->otherOptionValuePresent = true;
	osoption->optimization->constraints->other[parserData->numberOfOtherConstraintOptions]->value = (yyvsp[(2) - (2)].sval);
}
    break;

  case 662:

    {	if (parserData->otherOptionSolverPresent)
		osolerror (NULL, osoption, parserData, "only one solver attribute allowed");
	parserData->otherOptionSolverPresent = true;
	osoption->optimization->constraints->other[parserData->numberOfOtherConstraintOptions]->solver = (yyvsp[(2) - (2)].sval);
}
    break;

  case 664:

    {	if (parserData->otherOptionCategoryPresent)
		osolerror (NULL, osoption, parserData, "only one category attribute allowed");
	parserData->otherOptionCategoryPresent = true;
	osoption->optimization->constraints->other[parserData->numberOfOtherConstraintOptions]->category = (yyvsp[(2) - (2)].sval);
}
    break;

  case 666:

    {	if (parserData->otherOptionTypePresent)
		osolerror (NULL, osoption, parserData, "only one type attribute allowed");
	parserData->otherOptionTypePresent = true;
	osoption->optimization->constraints->other[parserData->numberOfOtherConstraintOptions]->type = (yyvsp[(2) - (2)].sval);
}
    break;

  case 668:

    {	if (parserData->otherOptionDescriptionPresent)
		osolerror (NULL, osoption, parserData, "only one description attribute allowed");
	parserData->otherOptionDescriptionPresent = true;
	osoption->optimization->constraints->other[parserData->numberOfOtherConstraintOptions]->description = (yyvsp[(2) - (2)].sval);
}
    break;

  case 670:

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
}
    break;

  case 673:

    {	if (!parserData->idxAttributePresent)
		osolerror(NULL, osoption, parserData, "required idx attribute was not found");
	parserData->idxAttributePresent = false;
	parserData->valAttributePresent = false;
	parserData->lbvalAttributePresent = false;
	parserData->ubvalAttributePresent = false;
	parserData->numberOfCon++;
}
    break;

  case 674:

    {	if (parserData->numberOfVar >= osoption->optimization->variables->other[parserData->numberOfOtherVariableOptions]->numberOfVar)
		osolerror(NULL, osoption, parserData, "too many <var> entries in <other> variable element");
}
    break;

  case 681:

    {	if (parserData->idxAttributePresent)
		osolerror (NULL, osoption, parserData, "only one constraint index allowed");
	parserData->idxAttributePresent = true;
	if ((yyvsp[(3) - (4)].ival) < 0) osolerror (NULL, osoption, parserData, "constraint index must be nonnegative");
	if (parserData->numberOfConstraintsPresent)
	{	if ((yyvsp[(3) - (4)].ival) >= parserData->numberOfConstraints)
			osolerror (NULL, osoption, parserData, "constraint index exceeds upper limit");
	};
	osoption->optimization->constraints->other[parserData->numberOfOtherConstraintOptions]->con[parserData->numberOfCon]->idx = (yyvsp[(3) - (4)].ival);
}
    break;

  case 682:

    {	if (parserData->valAttributePresent)
		osolerror (NULL, osoption, parserData, "only one constraint value allowed");
	parserData->valAttributePresent = true;
	osoption->optimization->constraints-> other[parserData->numberOfOtherConstraintOptions]->con[parserData->numberOfCon]->value = (yyvsp[(2) - (2)].sval);
}
    break;

  case 684:

    {	if (parserData->lbvalAttributePresent)
		osolerror (NULL, osoption, parserData, "only one lower bound value allowed");
	parserData->lbvalAttributePresent = true;
	osoption->optimization->constraints-> other[parserData->numberOfOtherConstraintOptions]->con[parserData->numberOfCon]->lbValue = (yyvsp[(2) - (2)].sval);
}
    break;

  case 686:

    {	if (parserData->ubvalAttributePresent)
		osolerror (NULL, osoption, parserData, "only one upper bound value allowed");
	parserData->ubvalAttributePresent = true;
	osoption->optimization->constraints-> other[parserData->numberOfOtherConstraintOptions]->con[parserData->numberOfCon]->ubValue = (yyvsp[(2) - (2)].sval);
}
    break;

  case 691:

    {	if (parserData->numberOfSolverOptions != osoption->optimization->solverOptions->numberOfSolverOptions)
		osolerror (NULL, osoption, parserData, "wrong number of solver options in <optimization> element");
}
    break;

  case 692:

    {	if (parserData->solverOptionsPresent)
	{	osolerror( NULL, osoption, parserData, "only one <solverOptions> element allowed");
	}
	else
	{	parserData->solverOptionsPresent = true;
		osoption->optimization->solverOptions = new SolverOptions();
	}
}
    break;

  case 693:

    {	if ((yyvsp[(3) - (4)].ival) < 0) osolerror (NULL, osoption, parserData, "number of solver options cannot be negative");
	osoption->optimization->solverOptions->numberOfSolverOptions = (yyvsp[(3) - (4)].ival);
	osoption->optimization->solverOptions->solverOption = new SolverOption*[(yyvsp[(3) - (4)].ival)];
	for (int i=0; i < (yyvsp[(3) - (4)].ival); i++) osoption->optimization->solverOptions->solverOption[i] = new SolverOption();
}
    break;

  case 696:

    {	if (parserData->numberOfSolverOptions >= osoption->optimization->solverOptions->numberOfSolverOptions)
	{	osolerror (NULL, osoption, parserData, "too many solver options in <optimization> element");
	};
}
    break;

  case 697:

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
}
    break;

  case 706:

    {	if (parserData->solverOptionNamePresent)
	{	osolerror( NULL, osoption, parserData, "only one name attribute allowed");
	}
	else
	{	parserData->solverOptionNamePresent = true;
		osoption->optimization->solverOptions->solverOption[parserData->numberOfSolverOptions]->name = (yyvsp[(2) - (2)].sval);
	}
}
    break;

  case 708:

    {	if (parserData->solverOptionValuePresent)
	{	osolerror( NULL, osoption, parserData, "only one value attribute allowed");
	}
	else
	{	parserData->solverOptionValuePresent = true;
		osoption->optimization->solverOptions->solverOption[parserData->numberOfSolverOptions]->value = (yyvsp[(2) - (2)].sval);
	}
}
    break;

  case 710:

    {	if (parserData->solverOptionSolverPresent)
	{	osolerror( NULL, osoption, parserData, "only one solver attribute allowed");
	}
	else
	{	parserData->solverOptionSolverPresent = true;
		osoption->optimization->solverOptions->solverOption[parserData->numberOfSolverOptions]->solver = (yyvsp[(2) - (2)].sval);
	}
}
    break;

  case 712:

    {	if (parserData->solverOptionCategoryPresent)
	{	osolerror( NULL, osoption, parserData, "only one category attribute allowed");
	}
	else
	{	parserData->solverOptionCategoryPresent = true;
		osoption->optimization->solverOptions->solverOption[parserData->numberOfSolverOptions]->category = (yyvsp[(2) - (2)].sval);
	}
}
    break;

  case 714:

    {	if (parserData->solverOptionTypePresent)
	{	osolerror( NULL, osoption, parserData, "only one type attribute allowed");
	}
	else
	{	parserData->solverOptionTypePresent = true;
		osoption->optimization->solverOptions->solverOption[parserData->numberOfSolverOptions]->type = (yyvsp[(2) - (2)].sval);
	}
}
    break;

  case 716:

    {	if (parserData->solverOptionNamePresent)
	{	osolerror( NULL, osoption, parserData, "only one name attribute allowed");
	}
	else
	{	parserData->solverOptionNamePresent = true;
		osoption->optimization->solverOptions->solverOption[parserData->numberOfSolverOptions]->name = (yyvsp[(2) - (2)].sval);
	}
}
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


