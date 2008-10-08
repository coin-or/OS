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
#define YYLAST   722

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  150
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  488
/* YYNRULES -- Number of rules.  */
#define YYNRULES  720
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
     493,   496,   498,   500,   502,   504,   506,   508,   511,   512,
     517,   522,   524,   529,   532,   533,   536,   537,   542,   543,
     546,   548,   550,   552,   553,   558,   559,   564,   565,   570,
     572,   575,   578,   580,   584,   586,   587,   590,   592,   594,
     596,   598,   600,   602,   604,   606,   608,   610,   612,   614,
     616,   618,   620,   624,   626,   627,   628,   633,   635,   638,
     639,   644,   645,   650,   653,   655,   657,   660,   661,   666,
     672,   674,   679,   680,   683,   684,   690,   696,   698,   703,
     704,   707,   708,   714,   720,   722,   727,   728,   731,   732,
     738,   744,   746,   751,   752,   755,   756,   762,   768,   770,
     775,   776,   779,   780,   786,   792,   794,   799,   800,   803,
     807,   809,   810,   813,   815,   817,   819,   820,   825,   826,
     831,   832,   837,   840,   842,   848,   850,   855,   856,   859,
     863,   865,   866,   869,   871,   873,   875,   876,   881,   882,
     887,   888,   893,   896,   898,   904,   906,   911,   912,   915,
     919,   921,   922,   925,   927,   929,   931,   932,   937,   938,
     943,   944,   949,   952,   954,   960,   962,   967,   968,   971,
     975,   977,   978,   981,   983,   985,   987,   988,   993,   994,
     999,  1000,  1005,  1008,  1010,  1016,  1018,  1023,  1024,  1027,
    1028,  1034,  1040,  1042,  1047,  1048,  1051,  1052,  1058,  1064,
    1066,  1071,  1072,  1075,  1076,  1082,  1087,  1089,  1094,  1097,
    1098,  1101,  1102,  1107,  1108,  1111,  1113,  1115,  1117,  1118,
    1123,  1124,  1129,  1130,  1135,  1137,  1140,  1141,  1145,  1147,
    1148,  1151,  1153,  1155,  1157,  1162,  1167,  1172,  1176,  1178,
    1183,  1184,  1188,  1190,  1191,  1196,  1202,  1204,  1205,  1211,
    1216,  1217,  1220,  1224,  1226,  1227,  1230,  1232,  1234,  1239,
    1240,  1245,  1248,  1250,  1251,  1257,  1262,  1263,  1266,  1270,
    1272,  1273,  1276,  1278,  1280,  1285,  1286,  1291,  1294,  1296,
    1297,  1300,  1304,  1306,  1307,  1310,  1312,  1314,  1316,  1318,
    1320,  1322,  1324,  1329,  1330,  1335,  1336,  1341,  1342,  1347,
    1348,  1353,  1354,  1359,  1360,  1365,  1369,  1370,  1373,  1377,
    1379,  1380,  1383,  1385,  1387,  1389,  1391,  1396,  1397,  1402,
    1403,  1408,  1409,  1414,  1417,  1419,  1420,  1424,  1426,  1427,
    1432,  1438,  1440,  1441,  1447,  1452,  1453,  1456,  1460,  1462,
    1463,  1466,  1468,  1470,  1475,  1476,  1481,  1484,  1486,  1487,
    1493,  1498,  1499,  1502,  1506,  1508,  1509,  1512,  1514,  1516,
    1518,  1523,  1524,  1529,  1530,  1535,  1538,  1540,  1541,  1544,
    1548,  1550,  1551,  1554,  1556,  1558,  1560,  1562,  1564,  1566,
    1568,  1573,  1574,  1579,  1580,  1585,  1586,  1591,  1592,  1597,
    1598,  1603,  1604,  1609,  1613,  1614,  1617,  1621,  1623,  1624,
    1627,  1629,  1631,  1633,  1635,  1640,  1641,  1646,  1647,  1652,
    1653,  1658,  1661,  1663,  1664,  1668,  1670,  1671,  1676,  1682,
    1684,  1685,  1691,  1696,  1697,  1700,  1704,  1706,  1707,  1710,
    1712,  1714,  1719,  1720,  1725,  1728,  1730,  1731,  1737,  1742,
    1743,  1746,  1750,  1752,  1753,  1756,  1758,  1760,  1762,  1767,
    1768,  1773,  1774,  1779,  1782,  1784,  1785,  1788,  1792,  1794,
    1795,  1798,  1800,  1802,  1804,  1806,  1808,  1810,  1812,  1817,
    1818,  1823,  1824,  1829,  1830,  1835,  1836,  1841,  1842,  1847,
    1848,  1853,  1857,  1858,  1861,  1865,  1867,  1868,  1871,  1873,
    1875,  1877,  1879,  1884,  1885,  1890,  1891,  1896,  1897,  1902,
    1905,  1907,  1908,  1914,  1916,  1921,  1922,  1925,  1926,  1931,
    1932,  1935,  1937,  1939,  1941,  1943,  1945,  1947,  1948,  1953,
    1954,  1959,  1960,  1965,  1966,  1971,  1972,  1977,  1978,  1983,
    1986
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
     271,    -1,   272,    -1,    85,    -1,     9,    -1,     8,    86,
      -1,    -1,     8,     5,   273,    86,    -1,   275,   276,     8,
     277,    -1,    73,    -1,    15,     7,     5,     7,    -1,   278,
      74,    -1,    -1,   278,   279,    -1,    -1,    75,   280,   281,
     289,    -1,    -1,   281,   282,    -1,   283,    -1,   285,    -1,
     287,    -1,    -1,    36,     3,   284,     7,    -1,    -1,    38,
       3,   286,     7,    -1,    -1,    40,     3,   288,     7,    -1,
       9,    -1,     8,    76,    -1,   291,   292,    -1,    49,    -1,
       8,   293,    50,    -1,     9,    -1,    -1,   293,   294,    -1,
     295,    -1,   302,    -1,   306,    -1,   312,    -1,   318,    -1,
     324,    -1,   330,    -1,   336,    -1,   351,    -1,   366,    -1,
     381,    -1,   396,    -1,   402,    -1,   408,    -1,   414,    -1,
     296,   297,   299,    -1,    87,    -1,    -1,    -1,    39,     3,
     298,     7,    -1,     9,    -1,     8,    88,    -1,    -1,     8,
       6,   300,    88,    -1,    -1,     8,     5,   301,    88,    -1,
     303,   304,    -1,    89,    -1,     9,    -1,     8,    90,    -1,
      -1,     8,     4,   305,    90,    -1,   307,   308,     8,   309,
      92,    -1,    91,    -1,    16,     7,     5,     7,    -1,    -1,
     309,   310,    -1,    -1,    61,     8,     4,   311,    62,    -1,
     313,   314,     8,   315,    94,    -1,    93,    -1,    17,     7,
       5,     7,    -1,    -1,   315,   316,    -1,    -1,    97,     8,
       4,   317,    98,    -1,   319,   320,     8,   321,    96,    -1,
      95,    -1,    17,     7,     5,     7,    -1,    -1,   321,   322,
      -1,    -1,    97,     8,     4,   323,    98,    -1,   325,   326,
       8,   327,   102,    -1,   101,    -1,    17,     7,     5,     7,
      -1,    -1,   327,   328,    -1,    -1,    97,     8,     4,   329,
      98,    -1,   331,   332,     8,   333,   104,    -1,   103,    -1,
      17,     7,     5,     7,    -1,    -1,   333,   334,    -1,    -1,
      97,     8,     4,   335,    98,    -1,   337,   338,     8,   339,
     110,    -1,   109,    -1,    18,     7,     5,     7,    -1,    -1,
     339,   340,    -1,   341,   342,   350,    -1,    99,    -1,    -1,
     342,   343,    -1,   344,    -1,   346,    -1,   348,    -1,    -1,
      19,     3,   345,     7,    -1,    -1,    20,     3,   347,     7,
      -1,    -1,    21,     3,   349,     7,    -1,     8,   100,    -1,
       9,    -1,   352,   353,     8,   354,   112,    -1,   111,    -1,
      18,     7,     5,     7,    -1,    -1,   354,   355,    -1,   356,
     357,   365,    -1,    99,    -1,    -1,   357,   358,    -1,   359,
      -1,   361,    -1,   363,    -1,    -1,    19,     3,   360,     7,
      -1,    -1,    20,     3,   362,     7,    -1,    -1,    21,     3,
     364,     7,    -1,     8,   100,    -1,     9,    -1,   367,   368,
       8,   369,   114,    -1,   113,    -1,    18,     7,     5,     7,
      -1,    -1,   369,   370,    -1,   371,   372,   380,    -1,    99,
      -1,    -1,   372,   373,    -1,   374,    -1,   376,    -1,   378,
      -1,    -1,    19,     3,   375,     7,    -1,    -1,    20,     3,
     377,     7,    -1,    -1,    21,     3,   379,     7,    -1,     8,
     100,    -1,     9,    -1,   382,   383,     8,   384,   116,    -1,
     115,    -1,    18,     7,     5,     7,    -1,    -1,   384,   385,
      -1,   386,   387,   395,    -1,    99,    -1,    -1,   387,   388,
      -1,   389,    -1,   391,    -1,   393,    -1,    -1,    19,     3,
     390,     7,    -1,    -1,    20,     3,   392,     7,    -1,    -1,
      21,     3,   394,     7,    -1,     8,   100,    -1,     9,    -1,
     397,   398,     8,   399,   108,    -1,   107,    -1,    17,     7,
       5,     7,    -1,    -1,   399,   400,    -1,    -1,    97,     8,
       4,   401,    98,    -1,   403,   404,     8,   405,   106,    -1,
     105,    -1,    17,     7,     5,     7,    -1,    -1,   405,   406,
      -1,    -1,    97,     8,     4,   407,    98,    -1,   409,   410,
       8,   411,   118,    -1,   117,    -1,    25,     7,     5,     7,
      -1,    -1,   411,   412,    -1,    -1,   119,     8,     4,   413,
     120,    -1,   415,   416,     8,   417,    -1,    73,    -1,    15,
       7,     5,     7,    -1,   418,    74,    -1,    -1,   418,   419,
      -1,    -1,    75,   420,   421,   429,    -1,    -1,   421,   422,
      -1,   423,    -1,   425,    -1,   427,    -1,    -1,    36,     3,
     424,     7,    -1,    -1,    38,     3,   426,     7,    -1,    -1,
      40,     3,   428,     7,    -1,     9,    -1,     8,    76,    -1,
      -1,   431,   432,   437,    -1,    51,    -1,    -1,   432,   433,
      -1,   434,    -1,   435,    -1,   436,    -1,    27,     7,     5,
       7,    -1,    29,     7,     5,     7,    -1,    28,     7,     5,
       7,    -1,     8,   438,    52,    -1,     9,    -1,   439,   497,
     557,   617,    -1,    -1,   440,   441,   442,    -1,   121,    -1,
      -1,    30,     7,     5,     7,    -1,     8,   443,   454,   465,
     122,    -1,     9,    -1,    -1,   123,   444,     8,   445,   124,
      -1,    33,     7,     5,     7,    -1,    -1,   445,   446,    -1,
     447,   448,   453,    -1,   125,    -1,    -1,   448,   449,    -1,
     450,    -1,   451,    -1,    37,     7,     5,     7,    -1,    -1,
      38,     3,   452,     7,    -1,     8,   126,    -1,     9,    -1,
      -1,   127,   455,     8,   456,   128,    -1,    33,     7,     5,
       7,    -1,    -1,   456,   457,    -1,   458,   459,   464,    -1,
     125,    -1,    -1,   459,   460,    -1,   461,    -1,   462,    -1,
      37,     7,     5,     7,    -1,    -1,    38,     3,   463,     7,
      -1,     8,   126,    -1,     9,    -1,    -1,   465,   466,    -1,
     467,   468,   483,    -1,    75,    -1,    -1,   468,   469,    -1,
     470,    -1,   471,    -1,   473,    -1,   475,    -1,   477,    -1,
     479,    -1,   481,    -1,    33,     7,     5,     7,    -1,    -1,
      36,     3,   472,     7,    -1,    -1,    38,     3,   474,     7,
      -1,    -1,    22,     3,   476,     7,    -1,    -1,    23,     3,
     478,     7,    -1,    -1,    24,     3,   480,     7,    -1,    -1,
      40,     3,   482,     7,    -1,     8,   484,    76,    -1,    -1,
     484,   485,    -1,   486,   487,   496,    -1,   125,    -1,    -1,
     487,   488,    -1,   489,    -1,   490,    -1,   492,    -1,   494,
      -1,    37,     7,     5,     7,    -1,    -1,    38,     3,   491,
       7,    -1,    -1,    41,     3,   493,     7,    -1,    -1,    42,
       3,   495,     7,    -1,     8,   126,    -1,     9,    -1,    -1,
     498,   499,   500,    -1,   129,    -1,    -1,    31,     7,     5,
       7,    -1,     8,   501,   512,   525,   130,    -1,     9,    -1,
      -1,   131,   502,     8,   503,   132,    -1,    34,     7,     5,
       7,    -1,    -1,   503,   504,    -1,   505,   506,   511,    -1,
     133,    -1,    -1,   506,   507,    -1,   508,    -1,   509,    -1,
      37,     7,     5,     7,    -1,    -1,    38,     3,   510,     7,
      -1,     8,   134,    -1,     9,    -1,    -1,   135,   513,     8,
     514,   136,    -1,    34,     7,     5,     7,    -1,    -1,   514,
     515,    -1,   516,   517,   524,    -1,   133,    -1,    -1,   517,
     518,    -1,   519,    -1,   520,    -1,   522,    -1,    37,     7,
       5,     7,    -1,    -1,    41,     3,   521,     7,    -1,    -1,
      42,     3,   523,     7,    -1,     8,   134,    -1,     9,    -1,
      -1,   525,   526,    -1,   527,   528,   543,    -1,    75,    -1,
      -1,   528,   529,    -1,   530,    -1,   531,    -1,   533,    -1,
     535,    -1,   537,    -1,   539,    -1,   541,    -1,    34,     7,
       5,     7,    -1,    -1,    36,     3,   532,     7,    -1,    -1,
      38,     3,   534,     7,    -1,    -1,    22,     3,   536,     7,
      -1,    -1,    23,     3,   538,     7,    -1,    -1,    24,     3,
     540,     7,    -1,    -1,    40,     3,   542,     7,    -1,     8,
     544,    76,    -1,    -1,   544,   545,    -1,   546,   547,   556,
      -1,   133,    -1,    -1,   547,   548,    -1,   549,    -1,   550,
      -1,   552,    -1,   554,    -1,    37,     7,     5,     7,    -1,
      -1,    38,     3,   551,     7,    -1,    -1,    41,     3,   553,
       7,    -1,    -1,    42,     3,   555,     7,    -1,     8,   126,
      -1,     9,    -1,    -1,   558,   559,   560,    -1,   137,    -1,
      -1,    32,     7,     5,     7,    -1,     8,   561,   572,   585,
     138,    -1,     9,    -1,    -1,   139,   562,     8,   563,   140,
      -1,    35,     7,     5,     7,    -1,    -1,   563,   564,    -1,
     565,   566,   571,    -1,   141,    -1,    -1,   566,   567,    -1,
     568,    -1,   569,    -1,    37,     7,     5,     7,    -1,    -1,
      38,     3,   570,     7,    -1,     8,   142,    -1,     9,    -1,
      -1,   143,   573,     8,   574,   144,    -1,    35,     7,     5,
       7,    -1,    -1,   574,   575,    -1,   576,   577,   584,    -1,
     141,    -1,    -1,   577,   578,    -1,   579,    -1,   580,    -1,
     582,    -1,    37,     7,     5,     7,    -1,    -1,    41,     3,
     581,     7,    -1,    -1,    42,     3,   583,     7,    -1,     8,
     142,    -1,     9,    -1,    -1,   585,   586,    -1,   587,   588,
     603,    -1,    75,    -1,    -1,   588,   589,    -1,   590,    -1,
     591,    -1,   593,    -1,   595,    -1,   597,    -1,   599,    -1,
     601,    -1,    35,     7,     5,     7,    -1,    -1,    36,     3,
     592,     7,    -1,    -1,    38,     3,   594,     7,    -1,    -1,
      22,     3,   596,     7,    -1,    -1,    23,     3,   598,     7,
      -1,    -1,    24,     3,   600,     7,    -1,    -1,    40,     3,
     602,     7,    -1,     8,   604,    76,    -1,    -1,   604,   605,
      -1,   606,   607,   616,    -1,   141,    -1,    -1,   607,   608,
      -1,   609,    -1,   610,    -1,   612,    -1,   614,    -1,    37,
       7,     5,     7,    -1,    -1,    38,     3,   611,     7,    -1,
      -1,    41,     3,   613,     7,    -1,    -1,    42,     3,   615,
       7,    -1,     8,   142,    -1,     9,    -1,    -1,   618,   619,
       8,   620,   146,    -1,   145,    -1,    26,     7,     5,     7,
      -1,    -1,   620,   621,    -1,    -1,   147,   622,   623,   637,
      -1,    -1,   623,   624,    -1,   625,    -1,   627,    -1,   629,
      -1,   631,    -1,   633,    -1,   635,    -1,    -1,    36,     3,
     626,     7,    -1,    -1,    38,     3,   628,     7,    -1,    -1,
      22,     3,   630,     7,    -1,    -1,    23,     3,   632,     7,
      -1,    -1,    24,     3,   634,     7,    -1,    -1,    40,     3,
     636,     7,    -1,     8,   148,    -1,     9,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   127,   127,   128,   130,   131,   133,   135,   135,   137,
     148,   149,   151,   151,   153,   153,   153,   153,   153,   154,
     154,   154,   154,   154,   154,   157,   159,   168,   169,   170,
     170,   173,   175,   184,   185,   186,   186,   189,   191,   200,
     201,   202,   202,   205,   207,   217,   217,   217,   219,   220,
     222,   222,   225,   227,   236,   237,   238,   238,   241,   243,
     252,   253,   254,   254,   257,   259,   268,   269,   270,   270,
     273,   275,   284,   285,   286,   286,   289,   291,   300,   301,
     302,   302,   305,   307,   317,   317,   317,   319,   320,   322,
     322,   325,   327,   337,   343,   348,   348,   351,   350,   366,
     366,   368,   368,   368,   371,   370,   382,   381,   393,   392,
     403,   403,   406,   406,   408,   419,   420,   422,   422,   424,
     424,   424,   424,   424,   426,   428,   438,   438,   438,   440,
     441,   442,   442,   443,   443,   446,   448,   458,   458,   458,
     460,   461,   462,   462,   463,   463,   466,   468,   478,   478,
     478,   480,   481,   482,   482,   483,   483,   486,   488,   497,
     498,   499,   499,   502,   504,   514,   520,   525,   525,   528,
     527,   542,   542,   544,   544,   544,   547,   546,   558,   557,
     570,   569,   580,   580,   583,   583,   585,   596,   597,   599,
     599,   601,   601,   603,   603,   605,   614,   615,   616,   616,
     618,   620,   630,   636,   641,   641,   644,   643,   658,   658,
     660,   660,   660,   663,   662,   674,   673,   685,   684,   695,
     695,   698,   700,   710,   711,   713,   713,   715,   715,   715,
     715,   715,   716,   716,   716,   716,   716,   717,   717,   717,
     717,   717,   720,   722,   732,   732,   732,   734,   735,   736,
     736,   737,   737,   739,   741,   750,   751,   752,   752,   754,
     756,   766,   772,   772,   775,   774,   787,   790,   800,   805,
     805,   807,   807,   819,   822,   832,   837,   837,   839,   839,
     851,   854,   863,   868,   868,   871,   870,   882,   885,   895,
     900,   900,   903,   902,   914,   917,   927,   935,   935,   937,
     949,   955,   955,   957,   957,   957,   960,   959,   971,   970,
     982,   981,   993,   993,   996,   999,  1009,  1016,  1016,  1018,
    1030,  1036,  1036,  1038,  1038,  1038,  1041,  1040,  1052,  1051,
    1063,  1062,  1074,  1074,  1077,  1080,  1090,  1098,  1098,  1100,
    1112,  1118,  1118,  1120,  1120,  1120,  1123,  1122,  1134,  1133,
    1145,  1144,  1156,  1156,  1159,  1162,  1172,  1179,  1179,  1181,
    1193,  1199,  1199,  1201,  1201,  1201,  1204,  1203,  1215,  1214,
    1226,  1225,  1237,  1237,  1240,  1243,  1253,  1258,  1258,  1261,
    1260,  1272,  1275,  1285,  1290,  1290,  1293,  1292,  1304,  1308,
    1318,  1323,  1323,  1326,  1325,  1337,  1339,  1349,  1355,  1360,
    1360,  1363,  1362,  1377,  1377,  1379,  1379,  1379,  1382,  1381,
    1393,  1392,  1404,  1403,  1414,  1414,  1417,  1417,  1419,  1429,
    1429,  1431,  1431,  1431,  1433,  1437,  1441,  1445,  1445,  1447,
    1449,  1449,  1451,  1455,  1455,  1463,  1464,  1466,  1466,  1468,
    1477,  1477,  1479,  1487,  1492,  1492,  1494,  1494,  1496,  1509,
    1508,  1516,  1516,  1519,  1519,  1522,  1531,  1531,  1533,  1541,
    1546,  1546,  1548,  1548,  1550,  1563,  1562,  1570,  1570,  1575,
    1575,  1577,  1579,  1584,  1584,  1587,  1588,  1589,  1590,  1591,
    1592,  1593,  1595,  1608,  1607,  1616,  1615,  1624,  1623,  1632,
    1631,  1640,  1639,  1648,  1647,  1656,  1673,  1673,  1675,  1685,
    1690,  1690,  1693,  1694,  1695,  1696,  1698,  1711,  1710,  1719,
    1718,  1727,  1726,  1734,  1734,  1738,  1738,  1740,  1744,  1744,
    1752,  1753,  1755,  1755,  1758,  1767,  1767,  1769,  1777,  1782,
    1782,  1784,  1784,  1786,  1800,  1799,  1807,  1807,  1810,  1810,
    1813,  1822,  1822,  1824,  1833,  1838,  1838,  1840,  1840,  1840,
    1842,  1855,  1854,  1863,  1862,  1870,  1870,  1874,  1874,  1876,
    1878,  1883,  1883,  1886,  1887,  1888,  1889,  1890,  1891,  1892,
    1894,  1907,  1906,  1916,  1915,  1925,  1924,  1934,  1933,  1943,
    1942,  1952,  1951,  1961,  1978,  1978,  1980,  1990,  1995,  1995,
    1998,  1999,  2000,  2001,  2003,  2017,  2016,  2026,  2025,  2035,
    2034,  2043,  2043,  2046,  2046,  2048,  2052,  2052,  2060,  2062,
    2064,  2064,  2067,  2076,  2076,  2078,  2086,  2091,  2091,  2093,
    2093,  2095,  2109,  2108,  2116,  2116,  2119,  2119,  2122,  2131,
    2131,  2133,  2142,  2147,  2147,  2149,  2149,  2149,  2151,  2164,
    2163,  2172,  2171,  2180,  2180,  2183,  2183,  2185,  2187,  2192,
    2192,  2195,  2196,  2197,  2198,  2199,  2200,  2201,  2203,  2216,
    2215,  2224,  2223,  2232,  2231,  2240,  2239,  2248,  2247,  2256,
    2255,  2264,  2281,  2281,  2283,  2293,  2298,  2298,  2301,  2302,
    2303,  2304,  2306,  2320,  2319,  2329,  2328,  2337,  2336,  2344,
    2344,  2347,  2347,  2352,  2362,  2369,  2369,  2372,  2371,  2389,
    2389,  2392,  2393,  2394,  2395,  2396,  2397,  2401,  2400,  2412,
    2411,  2423,  2422,  2434,  2433,  2445,  2444,  2456,  2455,  2467,
    2467
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
     268,   269,   269,   270,   270,   271,   272,   272,   273,   272,
     274,   275,   276,   277,   278,   278,   280,   279,   281,   281,
     282,   282,   282,   284,   283,   286,   285,   288,   287,   289,
     289,   290,   291,   292,   292,   293,   293,   294,   294,   294,
     294,   294,   294,   294,   294,   294,   294,   294,   294,   294,
     294,   294,   295,   296,   297,   298,   297,   299,   299,   300,
     299,   301,   299,   302,   303,   304,   304,   305,   304,   306,
     307,   308,   309,   309,   311,   310,   312,   313,   314,   315,
     315,   317,   316,   318,   319,   320,   321,   321,   323,   322,
     324,   325,   326,   327,   327,   329,   328,   330,   331,   332,
     333,   333,   335,   334,   336,   337,   338,   339,   339,   340,
     341,   342,   342,   343,   343,   343,   345,   344,   347,   346,
     349,   348,   350,   350,   351,   352,   353,   354,   354,   355,
     356,   357,   357,   358,   358,   358,   360,   359,   362,   361,
     364,   363,   365,   365,   366,   367,   368,   369,   369,   370,
     371,   372,   372,   373,   373,   373,   375,   374,   377,   376,
     379,   378,   380,   380,   381,   382,   383,   384,   384,   385,
     386,   387,   387,   388,   388,   388,   390,   389,   392,   391,
     394,   393,   395,   395,   396,   397,   398,   399,   399,   401,
     400,   402,   403,   404,   405,   405,   407,   406,   408,   409,
     410,   411,   411,   413,   412,   414,   415,   416,   417,   418,
     418,   420,   419,   421,   421,   422,   422,   422,   424,   423,
     426,   425,   428,   427,   429,   429,   430,   430,   431,   432,
     432,   433,   433,   433,   434,   435,   436,   437,   437,   438,
     439,   439,   440,   441,   441,   442,   442,   443,   443,   444,
     445,   445,   446,   447,   448,   448,   449,   449,   450,   452,
     451,   453,   453,   454,   454,   455,   456,   456,   457,   458,
     459,   459,   460,   460,   461,   463,   462,   464,   464,   465,
     465,   466,   467,   468,   468,   469,   469,   469,   469,   469,
     469,   469,   470,   472,   471,   474,   473,   476,   475,   478,
     477,   480,   479,   482,   481,   483,   484,   484,   485,   486,
     487,   487,   488,   488,   488,   488,   489,   491,   490,   493,
     492,   495,   494,   496,   496,   497,   497,   498,   499,   499,
     500,   500,   501,   501,   502,   503,   503,   504,   505,   506,
     506,   507,   507,   508,   510,   509,   511,   511,   512,   512,
     513,   514,   514,   515,   516,   517,   517,   518,   518,   518,
     519,   521,   520,   523,   522,   524,   524,   525,   525,   526,
     527,   528,   528,   529,   529,   529,   529,   529,   529,   529,
     530,   532,   531,   534,   533,   536,   535,   538,   537,   540,
     539,   542,   541,   543,   544,   544,   545,   546,   547,   547,
     548,   548,   548,   548,   549,   551,   550,   553,   552,   555,
     554,   556,   556,   557,   557,   558,   559,   559,   560,   560,
     561,   561,   562,   563,   563,   564,   565,   566,   566,   567,
     567,   568,   570,   569,   571,   571,   572,   572,   573,   574,
     574,   575,   576,   577,   577,   578,   578,   578,   579,   581,
     580,   583,   582,   584,   584,   585,   585,   586,   587,   588,
     588,   589,   589,   589,   589,   589,   589,   589,   590,   592,
     591,   594,   593,   596,   595,   598,   597,   600,   599,   602,
     601,   603,   604,   604,   605,   606,   607,   607,   608,   608,
     608,   608,   609,   611,   610,   613,   612,   615,   614,   616,
     616,   617,   617,   618,   619,   620,   620,   622,   621,   623,
     623,   624,   624,   624,   624,   624,   624,   626,   625,   628,
     627,   630,   629,   632,   631,   634,   633,   636,   635,   637,
     637
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
       2,     1,     1,     1,     1,     1,     1,     2,     0,     4,
       4,     1,     4,     2,     0,     2,     0,     4,     0,     2,
       1,     1,     1,     0,     4,     0,     4,     0,     4,     1,
       2,     2,     1,     3,     1,     0,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     3,     1,     0,     0,     4,     1,     2,     0,
       4,     0,     4,     2,     1,     1,     2,     0,     4,     5,
       1,     4,     0,     2,     0,     5,     5,     1,     4,     0,
       2,     0,     5,     5,     1,     4,     0,     2,     0,     5,
       5,     1,     4,     0,     2,     0,     5,     5,     1,     4,
       0,     2,     0,     5,     5,     1,     4,     0,     2,     3,
       1,     0,     2,     1,     1,     1,     0,     4,     0,     4,
       0,     4,     2,     1,     5,     1,     4,     0,     2,     3,
       1,     0,     2,     1,     1,     1,     0,     4,     0,     4,
       0,     4,     2,     1,     5,     1,     4,     0,     2,     3,
       1,     0,     2,     1,     1,     1,     0,     4,     0,     4,
       0,     4,     2,     1,     5,     1,     4,     0,     2,     3,
       1,     0,     2,     1,     1,     1,     0,     4,     0,     4,
       0,     4,     2,     1,     5,     1,     4,     0,     2,     0,
       5,     5,     1,     4,     0,     2,     0,     5,     5,     1,
       4,     0,     2,     0,     5,     4,     1,     4,     2,     0,
       2,     0,     4,     0,     2,     1,     1,     1,     0,     4,
       0,     4,     0,     4,     1,     2,     0,     3,     1,     0,
       2,     1,     1,     1,     4,     4,     4,     3,     1,     4,
       0,     3,     1,     0,     4,     5,     1,     0,     5,     4,
       0,     2,     3,     1,     0,     2,     1,     1,     4,     0,
       4,     2,     1,     0,     5,     4,     0,     2,     3,     1,
       0,     2,     1,     1,     4,     0,     4,     2,     1,     0,
       2,     3,     1,     0,     2,     1,     1,     1,     1,     1,
       1,     1,     4,     0,     4,     0,     4,     0,     4,     0,
       4,     0,     4,     0,     4,     3,     0,     2,     3,     1,
       0,     2,     1,     1,     1,     1,     4,     0,     4,     0,
       4,     0,     4,     2,     1,     0,     3,     1,     0,     4,
       5,     1,     0,     5,     4,     0,     2,     3,     1,     0,
       2,     1,     1,     4,     0,     4,     2,     1,     0,     5,
       4,     0,     2,     3,     1,     0,     2,     1,     1,     1,
       4,     0,     4,     0,     4,     2,     1,     0,     2,     3,
       1,     0,     2,     1,     1,     1,     1,     1,     1,     1,
       4,     0,     4,     0,     4,     0,     4,     0,     4,     0,
       4,     0,     4,     3,     0,     2,     3,     1,     0,     2,
       1,     1,     1,     1,     4,     0,     4,     0,     4,     0,
       4,     2,     1,     0,     3,     1,     0,     4,     5,     1,
       0,     5,     4,     0,     2,     3,     1,     0,     2,     1,
       1,     4,     0,     4,     2,     1,     0,     5,     4,     0,
       2,     3,     1,     0,     2,     1,     1,     1,     4,     0,
       4,     0,     4,     2,     1,     0,     2,     3,     1,     0,
       2,     1,     1,     1,     1,     1,     1,     1,     4,     0,
       4,     0,     4,     0,     4,     0,     4,     0,     4,     0,
       4,     3,     0,     2,     3,     1,     0,     2,     1,     1,
       1,     1,     4,     0,     4,     0,     4,     0,     4,     2,
       1,     0,     5,     1,     4,     0,     2,     0,     4,     0,
       2,     1,     1,     1,     1,     1,     1,     0,     4,     0,
       4,     0,     4,     0,     4,     0,     4,     0,     4,     2,
       1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       0,     4,     0,     0,     5,     1,     7,     3,     9,     0,
     112,     0,     2,   114,   184,     0,    12,    11,     8,   186,
       0,     0,   117,   116,   113,     0,   222,   416,     0,   189,
     188,   185,     0,    10,    26,    32,    38,    44,    53,    59,
      65,    71,    77,    83,    92,    13,    14,     0,    15,     0,
      16,     0,    17,    45,    18,     0,    19,     0,    20,     0,
      21,     0,    22,     0,    23,    84,    24,     0,   418,     6,
     419,   225,   224,   221,     0,   115,   164,   125,   136,   147,
     158,   118,   119,   126,   120,   137,   121,   148,   122,     0,
     123,     0,     0,    27,    25,     0,    33,    31,     0,    39,
      37,     0,     0,     0,    54,    52,     0,    60,    58,     0,
      66,    64,     0,    72,    70,     0,    78,    76,     0,     0,
       0,     0,     0,     0,     0,   196,   187,   201,   195,   190,
     191,   193,   194,   192,     0,     0,     0,     0,     0,     0,
       0,     0,   159,   157,     0,     0,    29,    28,    35,    34,
      41,    40,    46,    50,    48,    43,    56,    55,    62,    61,
      68,    67,    74,    73,    80,    79,    85,    89,    87,    82,
       0,    95,   430,   428,     0,     0,     0,   420,   421,   422,
     423,   417,   223,   396,   243,   254,   260,   267,   274,   281,
     288,   382,   375,   295,   315,   335,   355,   389,   226,   227,
     244,   228,     0,   229,     0,   230,     0,   231,     0,   232,
       0,   233,     0,   234,     0,   235,     0,   236,     0,   237,
       0,   238,     0,   239,     0,   240,     0,   241,     0,   198,
     197,     0,     0,   127,     0,   129,   124,   138,     0,   140,
     135,   149,     0,   151,   146,   161,   160,     0,   167,     0,
       0,     0,     0,    51,     0,     0,     0,     0,     0,     0,
       0,    90,     0,     0,    91,     0,   432,     0,   515,   433,
       0,     0,     0,     0,     0,     0,   255,   253,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   204,     0,   133,   131,
     130,     0,   144,   142,   141,     0,   155,   153,   152,     0,
       0,   163,     0,    30,    36,    42,    47,    49,    57,    63,
      69,    75,    81,    86,    88,    93,    94,    97,    96,   427,
     517,   603,   518,     0,     0,     0,     0,     0,   245,     0,
     247,   242,   257,   256,     0,   262,     0,   269,     0,   276,
       0,   283,     0,   290,     0,   297,     0,   317,     0,   337,
       0,   357,     0,   377,     0,   384,     0,   391,     0,   399,
     199,     0,   200,     0,   128,     0,     0,   139,     0,     0,
     150,     0,     0,   162,   165,   166,   169,   168,    99,   605,
     691,   606,     0,     0,     0,   437,   436,   431,   424,   426,
     425,     0,   251,   249,   248,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   395,     0,   202,   203,   206,   205,   134,   132,   145,
     143,   156,   154,   171,     0,   693,   429,     0,     0,     0,
       0,   522,   521,   516,     0,     0,   453,   246,     0,     0,
     258,   261,     0,   259,   263,   268,   266,     0,   270,   275,
     273,     0,   277,   282,     0,   280,   284,   289,     0,   287,
     291,   296,   300,   294,   298,   301,   316,   320,   314,   318,
     321,   336,   340,   334,   338,   341,   356,   360,   354,   358,
     361,   376,     0,   374,   378,   383,     0,   381,   385,   390,
     388,     0,   392,   397,   398,   401,   400,   208,     0,     0,
     110,     0,     0,     0,   100,   101,   102,   103,    98,     0,
       0,     0,   610,   609,   604,     0,     0,   538,   434,     0,
       0,     0,   469,   252,   250,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   403,     0,     0,
     182,     0,     0,     0,   172,   173,   174,   175,   170,   111,
     104,   106,   108,     0,   695,     0,     0,   626,   519,     0,
       0,     0,   557,     0,   440,     0,     0,     0,   264,   271,
     278,   285,   292,     0,   313,     0,     0,     0,   302,   303,
     304,   305,   299,     0,   333,     0,     0,     0,   322,   323,
     324,   325,   319,     0,   353,     0,     0,     0,   342,   343,
     344,   345,   339,     0,   373,     0,     0,     0,   362,   363,
     364,   365,   359,   379,   386,   393,     0,     0,   219,     0,
       0,     0,   209,   210,   211,   212,   207,   183,   176,   178,
     180,     0,     0,     0,     0,     0,   607,     0,     0,     0,
     645,     0,   525,     0,     0,     0,     0,     0,     0,   456,
     472,   435,   470,   473,     0,     0,     0,     0,     0,   312,
     306,   308,   310,   332,   326,   328,   330,   352,   346,   348,
     350,   372,   366,   368,   370,     0,     0,     0,     0,   414,
       0,     0,     0,   404,   405,   406,   407,   402,   220,   213,
     215,   217,     0,     0,     0,   105,   107,   109,   694,   692,
     697,   696,     0,   613,     0,     0,     0,     0,     0,     0,
     541,   560,   520,   558,   561,   439,   438,   443,   441,   444,
       0,     0,     0,   265,   272,   279,   286,   293,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     380,   387,   394,   415,   408,   410,   412,     0,     0,     0,
     177,   179,   181,   699,     0,     0,     0,   629,   648,   608,
     646,   649,   524,   523,   528,   526,   529,     0,     0,     0,
       0,   455,   459,   454,   457,   460,   496,     0,     0,     0,
       0,     0,     0,     0,   474,   475,   476,   477,   478,   479,
     480,   481,   471,   307,   309,   311,   327,   329,   331,   347,
     349,   351,   367,   369,   371,     0,     0,     0,   214,   216,
     218,     0,   612,   611,   616,   614,   617,     0,     0,     0,
       0,   540,   544,   539,   542,   545,   584,     0,     0,     0,
       0,     0,     0,     0,   562,   563,   564,   565,   566,   567,
     568,   569,   559,     0,   452,     0,     0,   445,   446,   447,
     442,     0,     0,   487,   489,   491,     0,   483,   485,   493,
     409,   411,   413,     0,   720,     0,     0,     0,     0,     0,
       0,   700,   701,   702,   703,   704,   705,   706,   698,     0,
     628,   632,   627,   630,   633,   672,     0,     0,     0,     0,
       0,     0,     0,   650,   651,   652,   653,   654,   655,   656,
     657,   647,     0,   537,     0,     0,   530,   531,   532,   527,
       0,     0,   575,   577,   579,     0,   571,   573,   581,   451,
       0,   449,     0,   468,     0,     0,   461,   462,   463,   458,
     495,   499,   497,   500,     0,     0,     0,     0,     0,     0,
       0,   719,   711,   713,   715,   707,   709,   717,     0,   625,
       0,     0,   618,   619,   620,   615,     0,     0,   663,   665,
     667,     0,   659,   661,   669,   536,     0,   534,     0,   556,
       0,     0,     0,   546,   547,   548,   549,   543,   583,   587,
     585,   588,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   467,     0,   465,     0,   488,   490,   492,   482,   484,
     486,   494,     0,     0,     0,     0,     0,     0,   624,     0,
     622,     0,   644,     0,     0,     0,   634,   635,   636,   637,
     631,   671,   675,   673,   676,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   555,     0,   551,   553,     0,   576,
     578,   580,   570,   572,   574,   582,   448,   450,     0,     0,
       0,   514,     0,     0,     0,     0,   501,   502,   503,   504,
     505,   498,   712,   714,   716,   708,   710,   718,     0,     0,
     643,     0,   639,   641,     0,   664,   666,   668,   658,   660,
     662,   670,   533,   535,     0,     0,     0,     0,   602,     0,
       0,     0,     0,   589,   590,   591,   592,   593,   586,   464,
     466,   513,     0,   507,   509,   511,   621,   623,     0,     0,
       0,     0,   690,     0,     0,     0,     0,   677,   678,   679,
     680,   681,   674,   550,   552,   554,   601,     0,   595,   597,
     599,     0,     0,     0,     0,   638,   640,   642,   689,     0,
     683,   685,   687,     0,     0,     0,     0,   506,   508,   510,
     512,     0,     0,     0,     0,   594,   596,   598,   600,   682,
     684,   686,   688
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,     9,    10,    11,    18,    25,    45,    46,
      47,    94,   249,    48,    49,    97,   250,    50,    51,   100,
     251,    52,    53,   102,   252,   155,   254,    54,    55,   105,
     255,    56,    57,   108,   256,    58,    59,   111,   257,    60,
      61,   114,   258,    62,    63,   117,   259,    64,    65,   119,
     260,   169,   262,    66,    67,   121,   264,   265,   338,   398,
     454,   534,   535,   661,   536,   662,   537,   663,   538,    14,
      15,    24,    32,    81,    82,    83,   136,   307,   236,   386,
     385,    84,    85,   138,   311,   240,   389,   388,    86,    87,
     140,   315,   244,   392,   391,    88,    89,   143,   319,    90,
      91,   145,   321,   322,   397,   453,   528,   574,   575,   722,
     576,   723,   577,   724,   578,    20,    21,    31,    74,   129,
     130,   131,   132,   304,   133,   134,   232,   382,   383,   446,
     527,   568,   652,   653,   777,   654,   778,   655,   779,   656,
      27,    28,    73,   123,   198,   199,   200,   274,   411,   351,
     469,   468,   201,   202,   277,   415,   203,   204,   279,   417,
     474,   684,   205,   206,   281,   419,   478,   685,   207,   208,
     283,   421,   482,   686,   209,   210,   285,   423,   486,   687,
     211,   212,   287,   425,   490,   688,   213,   214,   289,   427,
     494,   495,   560,   608,   609,   758,   610,   759,   611,   760,
     612,   215,   216,   291,   429,   499,   500,   561,   618,   619,
     761,   620,   762,   621,   763,   622,   217,   218,   293,   431,
     504,   505,   562,   628,   629,   764,   630,   765,   631,   766,
     632,   219,   220,   295,   433,   509,   510,   563,   638,   639,
     767,   640,   768,   641,   769,   642,   221,   222,   297,   435,
     514,   705,   223,   224,   299,   437,   518,   706,   225,   226,
     301,   439,   522,   707,   227,   228,   303,   441,   442,   526,
     567,   646,   713,   714,   835,   715,   836,   716,   837,   717,
      69,    70,   122,   177,   178,   179,   180,   181,   267,   268,
     269,   344,   407,   466,   550,   677,   748,   749,   800,   877,
     878,   879,  1020,   880,   552,   596,   751,   804,   805,   881,
     956,   957,   958,  1079,   959,   597,   682,   683,   752,   814,
     815,   816,   968,   817,   969,   818,   964,   819,   965,   820,
     966,   821,   970,   822,   882,   962,   963,  1024,  1086,  1087,
    1088,  1162,  1089,  1163,  1090,  1164,  1091,   341,   342,   403,
     463,   547,   590,   738,   795,   796,   850,   936,   937,   938,
    1063,   939,   592,   674,   798,   854,   855,   940,  1003,  1004,
    1005,  1115,  1006,  1116,  1007,   675,   743,   744,   799,   864,
     865,   866,  1016,   867,  1017,   868,  1012,   869,  1013,   870,
    1014,   871,  1018,   872,   941,  1010,  1011,  1068,  1123,  1124,
    1125,  1174,  1126,  1175,  1127,  1176,  1128,   400,   401,   459,
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
#define YYPACT_NINF -87
static const yytype_int16 yypact[] =
{
      17,    20,    29,   101,   -87,   -87,   -10,   -87,   -87,    23,
      -2,   115,   -87,   -87,    -6,   146,   -87,   -87,   -87,   -87,
      22,   222,   -87,   -87,   -87,   198,   -87,    42,   228,   -87,
     -87,   -87,   -20,   -87,   -87,   -87,   -87,   -87,   -87,   -87,
     -87,   -87,   -87,   -87,   -87,   -87,   -87,   272,   -87,   284,
     -87,   286,   -87,    52,   -87,   288,   -87,   290,   -87,   292,
     -87,   294,   -87,   296,   -87,    41,   -87,    54,   -87,   -87,
     -87,   -87,   -87,   -87,     3,   -87,   -87,   -87,   -87,   -87,
     -87,   -87,   -87,    34,   -87,    61,   -87,    76,   -87,   298,
     -87,   129,    18,   -87,   -87,    19,   -87,   -87,    16,   -87,
     -87,   157,   300,    15,   -87,   -87,    26,   -87,   -87,    13,
     -87,   -87,    12,   -87,   -87,    21,   -87,   -87,   164,   302,
     158,   166,    93,   -49,     1,   -87,   -87,   -87,   -87,   -87,
     -87,   -87,   -87,   -87,   176,   169,   304,   178,   306,   186,
     308,    -1,   -87,   -87,   192,   185,   -87,   -87,   -87,   -87,
     -87,   -87,   -87,   204,   -87,   -87,   -87,   -87,   -87,   -87,
     -87,   -87,   -87,   -87,   -87,   -87,   -87,   214,   -87,   -87,
     196,   -87,   105,   -87,   215,   217,   231,   -87,   -87,   -87,
     -87,   -87,   -87,   -87,   -87,   -87,   -87,   -87,   -87,   -87,
     -87,   -87,   -87,   -87,   -87,   -87,   -87,   -87,   -87,   -87,
     206,   -87,   310,   -87,   232,   -87,   235,   -87,   237,   -87,
     239,   -87,   241,   -87,   242,   -87,   244,   -87,   248,   -87,
     252,   -87,   247,   -87,   251,   -87,   249,   -87,   329,   -87,
     -87,   275,   269,   -87,     4,   -87,   -87,   -87,     9,   -87,
     -87,   -87,     2,   -87,   -87,   -87,   -87,   344,   -87,   297,
     299,   295,   343,   -87,   301,   303,   293,   305,   291,   282,
     347,   -87,   307,   349,   -87,   246,   -87,   311,   229,   332,
     355,   359,   361,   364,   314,    -4,   -87,   -87,   362,   360,
     363,   365,   367,   368,   370,   372,   371,   373,   375,   376,
     378,   379,   381,   382,   384,   385,   387,   388,   390,   391,
     393,   394,   396,   397,   289,   399,   -87,   400,   -87,   -87,
     -87,   401,   -87,   -87,   -87,   402,   -87,   -87,   -87,   317,
     403,   -87,   250,   -87,   -87,   -87,   -87,   -87,   -87,   -87,
     -87,   -87,   -87,   -87,   -87,   -87,   -87,   -87,   -87,   -87,
     -87,   255,   341,   404,   318,   405,   406,   407,   -87,    -3,
     -87,   -87,   -87,   -87,   410,   -87,   411,   -87,   412,   -87,
     413,   -87,   414,   -87,   415,   -87,   416,   -87,   417,   -87,
     418,   -87,   419,   -87,   420,   -87,   421,   -87,   422,   -87,
     -87,   423,   -87,   254,   -87,   320,   328,   -87,   309,   315,
     -87,   346,   350,   -87,   -87,   -87,   -87,   -87,   -87,   -87,
     238,   354,   424,   322,   428,   312,   -87,   -87,   -87,   -87,
     -87,   427,   -87,   -87,   -87,   339,   429,   -25,   430,    59,
     431,   236,   432,    14,   433,    45,   434,   -60,   435,   -65,
     436,   -86,   437,   -67,   438,     6,   439,    11,   440,   216,
     441,   -87,   262,   -87,   -87,   -87,   -87,   -87,   -87,   -87,
     -87,   -87,   -87,   -87,   171,   -87,   -87,   425,   442,   330,
     445,   321,   -87,   -87,   446,   426,   327,   -87,   369,   374,
     -87,   -87,   447,   -87,   -87,   -87,   -87,   448,   -87,   -87,
     -87,   450,   -87,   -87,   452,   -87,   -87,   -87,   453,   -87,
     -87,   -87,   -87,   -87,   -87,   -87,   -87,   -87,   -87,   -87,
     -87,   -87,   -87,   -87,   -87,   -87,   -87,   -87,   -87,   -87,
     -87,   -87,   455,   -87,   -87,   -87,   456,   -87,   -87,   -87,
     -87,   457,   -87,   -87,   -87,   -87,   -87,   -87,   174,   392,
     -87,   463,   464,   466,   -87,   -87,   -87,   -87,   -87,   465,
     462,   468,   335,   -87,   -87,   469,   443,   336,   -87,   471,
     467,   449,   -87,   -87,   -87,   475,   476,   477,   479,   480,
     220,   264,   267,   270,   481,   482,   483,   -87,   179,   444,
     -87,   485,   486,   487,   -87,   -87,   -87,   -87,   -87,   -87,
     -87,   -87,   -87,   488,   -87,   484,   459,   352,   -87,   489,
     490,   458,   -87,   492,   -87,   493,   491,   -27,   -87,   -87,
     -87,   -87,   -87,   408,   -87,   498,   499,   500,   -87,   -87,
     -87,   -87,   -87,   409,   -87,   501,   502,   503,   -87,   -87,
     -87,   -87,   -87,   451,   -87,   504,   507,   508,   -87,   -87,
     -87,   -87,   -87,   454,   -87,   509,   510,   511,   -87,   -87,
     -87,   -87,   -87,   -87,   -87,   -87,   187,   460,   -87,   512,
     513,   514,   -87,   -87,   -87,   -87,   -87,   -87,   -87,   -87,
     -87,   515,   516,   517,   518,   194,   -87,   519,   520,   494,
     -87,   522,   -87,   523,   524,   -38,   526,   218,   529,   -87,
     -87,   -87,   -87,   -87,   473,   461,   470,   472,   474,   -87,
     -87,   -87,   -87,   -87,   -87,   -87,   -87,   -87,   -87,   -87,
     -87,   -87,   -87,   -87,   -87,   478,   495,   398,   497,   -87,
     528,   534,   535,   -87,   -87,   -87,   -87,   -87,   -87,   -87,
     -87,   -87,   532,   533,   536,   -87,   -87,   -87,   -87,   -87,
     -87,   -87,   537,   -87,   538,   539,   -57,   541,   213,   544,
     -87,   -87,   -87,   -87,   -87,   -87,   -87,   -87,   -87,   -87,
     543,   118,   128,   -87,   -87,   -87,   -87,   -87,   545,   546,
     548,   549,   550,   551,   553,   554,   555,   556,   557,   558,
     -87,   -87,   -87,   -87,   -87,   -87,   -87,   559,   560,   562,
     -87,   -87,   -87,   -87,   564,   207,   569,   -87,   -87,   -87,
     -87,   -87,   -87,   -87,   -87,   -87,   -87,   568,    80,   135,
     110,   -87,   -87,   -87,   -87,   -87,   -87,   574,   575,   576,
     573,   578,   579,   580,   -87,   -87,   -87,   -87,   -87,   -87,
     -87,   -87,   -87,   -87,   -87,   -87,   -87,   -87,   -87,   -87,
     -87,   -87,   -87,   -87,   -87,   577,   581,   582,   -87,   -87,
     -87,   154,   -87,   -87,   -87,   -87,   -87,   583,   103,   162,
     195,   -87,   -87,   -87,   -87,   -87,   -87,   584,   588,   589,
     587,   592,   593,   594,   -87,   -87,   -87,   -87,   -87,   -87,
     -87,   -87,   -87,   395,   -87,   591,   596,   -87,   -87,   -87,
     -87,   197,   -31,   -87,   -87,   -87,   595,   -87,   -87,   -87,
     -87,   -87,   -87,   496,   -87,   598,   599,   600,   601,   602,
     603,   -87,   -87,   -87,   -87,   -87,   -87,   -87,   -87,   212,
     -87,   -87,   -87,   -87,   -87,   -87,   604,   605,   606,   607,
     608,   609,   610,   -87,   -87,   -87,   -87,   -87,   -87,   -87,
     -87,   -87,   505,   -87,   611,   612,   -87,   -87,   -87,   -87,
      98,   -55,   -87,   -87,   -87,   614,   -87,   -87,   -87,   -87,
     615,   -87,   506,   -87,   616,   613,   -87,   -87,   -87,   -87,
     -87,   -87,   -87,   -87,   617,   618,   619,   620,   621,   622,
     623,   -87,   -87,   -87,   -87,   -87,   -87,   -87,   377,   -87,
     624,   630,   -87,   -87,   -87,   -87,   104,   -71,   -87,   -87,
     -87,   629,   -87,   -87,   -87,   -87,   631,   -87,   521,   -87,
     628,   634,   635,   -87,   -87,   -87,   -87,   -87,   -87,   -87,
     -87,   -87,   633,   636,   638,   639,   640,   641,   642,   643,
     644,   -87,   637,   -87,    88,   -87,   -87,   -87,   -87,   -87,
     -87,   -87,   645,   646,   647,   649,   650,   651,   -87,   654,
     -87,   525,   -87,   653,   658,   659,   -87,   -87,   -87,   -87,
     -87,   -87,   -87,   -87,   -87,   656,   657,   661,   662,   663,
     664,   665,   666,   667,   -87,   660,   -87,   -87,    90,   -87,
     -87,   -87,   -87,   -87,   -87,   -87,   -87,   -87,   668,   669,
     540,   -87,   670,   675,   676,   677,   -87,   -87,   -87,   -87,
     -87,   -87,   -87,   -87,   -87,   -87,   -87,   -87,   674,   678,
     -87,   679,   -87,   -87,    96,   -87,   -87,   -87,   -87,   -87,
     -87,   -87,   -87,   -87,   680,   681,   682,   565,   -87,   683,
     689,   690,   691,   -87,   -87,   -87,   -87,   -87,   -87,   -87,
     -87,   -87,   692,   -87,   -87,   -87,   -87,   -87,   688,   693,
     694,   561,   -87,   695,   696,   701,   702,   -87,   -87,   -87,
     -87,   -87,   -87,   -87,   -87,   -87,   -87,   703,   -87,   -87,
     -87,   699,   700,   704,   705,   -87,   -87,   -87,   -87,   708,
     -87,   -87,   -87,   707,   709,   710,   711,   -87,   -87,   -87,
     -87,   712,   713,   714,   715,   -87,   -87,   -87,   -87,   -87,
     -87,   -87,   -87
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -87,   -87,   -87,   -87,   -87,   -87,   -87,   -87,   -87,   -87,
     -87,   -87,   -87,   -87,   -87,   -87,   -87,   -87,   -87,   -87,
     -87,   -87,   -87,   -87,   -87,   -87,   -87,   -87,   -87,   -87,
     -87,   -87,   -87,   -87,   -87,   -87,   -87,   -87,   -87,   -87,
     -87,   -87,   -87,   -87,   -87,   -87,   -87,   -87,   -87,   -87,
     -87,   -87,   -87,   -87,   -87,   -87,   -87,   -87,   -87,   -87,
     -87,   -87,   -87,   -87,   -87,   -87,   -87,   -87,   -87,   -87,
     -87,   -87,   -87,   -87,   -87,   -87,   -87,   -87,   -87,   -87,
     -87,   -87,   -87,   -87,   -87,   -87,   -87,   -87,   -87,   -87,
     -87,   -87,   -87,   -87,   -87,   -87,   -87,   -87,   -87,   -87,
     -87,   -87,   -87,   -87,   -87,   -87,   -87,   -87,   -87,   -87,
     -87,   -87,   -87,   -87,   -87,   -87,   -87,   -87,   -87,   -87,
     -87,   -87,   -87,   -87,   -87,   -87,   -87,   -87,   -87,   -87,
     -87,   -87,   -87,   -87,   -87,   -87,   -87,   -87,   -87,   -87,
     -87,   -87,   -87,   -87,   -87,   -87,   -87,   -87,   -87,   -87,
     -87,   -87,   -87,   -87,   -87,   -87,   -87,   -87,   -87,   -87,
     -87,   -87,   -87,   -87,   -87,   -87,   -87,   -87,   -87,   -87,
     -87,   -87,   -87,   -87,   -87,   -87,   -87,   -87,   -87,   -87,
     -87,   -87,   -87,   -87,   -87,   -87,   -87,   -87,   -87,   -87,
     -87,   -87,   -87,   -87,   -87,   -87,   -87,   -87,   -87,   -87,
     -87,   -87,   -87,   -87,   -87,   -87,   -87,   -87,   -87,   -87,
     -87,   -87,   -87,   -87,   -87,   -87,   -87,   -87,   -87,   -87,
     -87,   -87,   -87,   -87,   -87,   -87,   -87,   -87,   -87,   -87,
     -87,   -87,   -87,   -87,   -87,   -87,   -87,   -87,   -87,   -87,
     -87,   -87,   -87,   -87,   -87,   -87,   -87,   -87,   -87,   -87,
     -87,   -87,   -87,   -87,   -87,   -87,   -87,   -87,   -87,   -87,
     -87,   -87,   -87,   -87,   -87,   -87,   -87,   -87,   -87,   -87,
     -87,   -87,   -87,   -87,   -87,   -87,   -87,   -87,   -87,   -87,
     -87,   -87,   -87,   -87,   -87,   -87,   -87,   -87,   -87,   -87,
     -87,   -87,   -87,   -87,   -87,   -87,   -87,   -87,   -87,   -87,
     -87,   -87,   -87,   -87,   -87,   -87,   -87,   -87,   -87,   -87,
     -87,   -87,   -87,   -87,   -87,   -87,   -87,   -87,   -87,   -87,
     -87,   -87,   -87,   -87,   -87,   -87,   -87,   -87,   -87,   -87,
     -87,   -87,   -87,   -87,   -87,   -87,   -87,   -87,   -87,   -87,
     -87,   -87,   -87,   -87,   -87,   -87,   -87,   -87,   -87,   -87,
     -87,   -87,   -87,   -87,   -87,   -87,   -87,   -87,   -87,   -87,
     -87,   -87,   -87,   -87,   -87,   -87,   -87,   -87,   -87,   -87,
     -87,   -87,   -87,   -87,   -87,   -87,   -87,   -87,   -87,   -87,
     -87,   -87,   -87,   -87,   -87,   -87,   -87,   -87,   -87,   -87,
     -87,   -87,   -87,   -87,   -87,   -87,   -87,   -87,   -87,   -87,
     -87,   -87,   -87,   -87,   -87,   -87,   -87,   -87,   -87,   -87,
     -87,   -87,   -87,   -87,   -87,   -87,   -87,   -87,   -87,   -87,
     -87,   -87,   -87,   -87,   -87,   -87,   -87,   -87,   -87,   -87,
     -87,   -87,   -87,   -87,   -87,   -87,   -87,   -87,   -87,   -87,
     -87,   -87,   -87,   -87,   -87,   -87,   -87,   -87,   -87,   -87,
     -87,   -87,   -87,   -87,   -87,   -87,   -87,   -87,   -87,   -87,
     -87,   -87,   -87,   -87,   -87,   -87,   -87,   -87,   -87,   -87,
     -87,   -87,   -87,   -87,   -87,   -87,   -87,   -87,   -87,   -87,
     -87,   -87,   -87,   -87,   -87,   -87,   -87,   -87
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint16 yytable[] =
{
     352,   182,   412,   413,   245,  1051,   229,   316,   317,   308,
     309,   124,   125,   502,   312,   313,   162,   160,   788,   156,
     150,  1008,   146,   148,   183,   164,    75,     1,   503,     5,
     158,     4,   507,     8,   497,    12,   472,   741,   184,   492,
     185,    19,   186,    13,   187,   960,   188,   498,   680,   508,
     493,   126,   189,    76,   190,   118,   191,    77,   192,    78,
     193,    79,   194,    80,   195,   101,   196,   473,   197,   120,
    1052,    26,   147,   135,   151,   149,   127,   157,  1009,   161,
     163,   789,   310,   246,   318,   414,   353,   230,   128,   314,
     159,   165,   742,    68,   961,   681,  1080,  1081,  1117,  1118,
     137,   172,   173,   512,  1141,  1142,   998,   999,   516,     6,
       7,   484,  1041,  1042,   513,   139,   485,   517,   873,   874,
     174,   175,   176,    16,    17,  1082,  1083,  1119,  1120,  1084,
    1085,  1121,  1122,  1143,  1144,  1000,   806,  1145,  1146,  1001,
    1002,  1043,   488,   856,   144,  1044,  1045,   875,   876,   489,
     807,   808,   809,   476,    22,    23,   477,   857,   858,   859,
     152,   810,   893,   894,   811,   170,   812,   166,   813,   860,
     915,   861,   233,   862,   171,   863,   895,   896,   897,   529,
     530,   237,   569,   570,   916,   917,   918,   647,   648,   241,
     898,   231,   899,   248,   900,   708,   709,   919,   920,   247,
     921,   263,   922,   932,   933,   952,   953,   531,   253,   532,
     571,   533,   572,   852,   573,   649,   853,   650,   261,   651,
     978,   979,   270,   710,   271,   711,   266,   712,   603,   604,
      29,    30,   934,   935,   954,   955,    71,    72,   272,   605,
     606,   607,    33,   802,   911,   273,   803,   912,   278,   980,
     981,    34,   280,    35,   282,    36,   284,    37,   286,    38,
     288,    39,   290,    40,   296,    41,   292,    42,   298,    43,
     294,    44,   613,   614,   300,   623,   624,   306,   633,   634,
      92,    93,   305,   615,   616,   617,   625,   626,   627,   635,
     636,   637,    95,    96,    98,    99,   103,   104,   106,   107,
     109,   110,   112,   113,   115,   116,   141,   142,   153,   154,
     167,   168,   234,   235,   238,   239,   242,   243,   275,   276,
     336,   337,   349,   350,   395,   396,   405,   406,   444,   445,
     461,   462,   480,   481,   520,   521,   524,   525,   542,   543,
     729,   730,   746,   747,   302,   793,   794,   843,   844,   320,
     326,   323,   332,   325,   333,   324,   335,   329,   340,   331,
     345,   327,   343,   339,   346,   328,   347,   348,   355,   354,
     356,   330,   402,   357,   358,   380,   359,   360,   362,   334,
     361,   363,   364,   455,   365,   366,   458,   367,   368,   449,
     369,   370,   399,   371,   372,   450,   373,   374,   447,   375,
     376,   393,   377,   378,   381,   379,   448,   384,   387,   390,
     394,   404,   408,   409,   410,   416,   418,   420,   422,   424,
     426,   428,   430,   432,   434,   436,   438,   440,   451,   470,
     443,   460,   452,   464,   467,   465,   471,   475,   479,   483,
     487,   491,   496,   501,   506,   511,   515,   519,   523,   541,
     545,   539,   546,   548,   551,   555,   556,   553,   557,   549,
     558,   559,   554,   564,   565,   566,   580,   581,   579,   582,
     584,   591,   583,   585,   586,   594,   588,   589,   593,   598,
     599,   600,   595,   601,   602,   643,   644,   645,   658,   659,
     660,   666,   673,   664,   667,   669,   671,   676,   672,   679,
     678,   690,   691,   692,   694,   695,   696,   698,   689,   693,
     699,   700,   702,   703,   704,   719,   720,   721,   772,  1038,
     657,   949,   725,   726,   727,   728,   732,   737,   733,   734,
     739,   774,   740,   745,   750,   753,   718,   775,   776,   780,
     781,     0,   784,   782,     0,   786,     0,   787,   792,   797,
     801,   697,   823,   824,   701,   825,   826,   827,   828,   754,
     829,   830,   831,   832,   833,   834,   838,   839,   755,   840,
     756,   842,   757,   773,   847,   851,   770,   883,   884,   885,
     886,   887,   888,   889,   890,     0,     0,   942,   891,   892,
     910,   943,   944,   771,   945,   946,   947,   948,   950,   951,
     967,   972,   973,   974,   975,   976,   977,   988,   989,   990,
       0,   992,   993,   994,   991,   997,  1023,     0,   996,  1015,
    1019,     0,     0,  1022,  1025,  1026,  1027,  1028,  1029,  1030,
    1031,  1039,  1021,  1040,  1058,  1065,  1062,  1066,  1067,   995,
    1069,     0,  1078,  1070,   971,  1071,  1072,  1073,  1074,  1075,
    1076,  1077,  1092,  1093,  1094,  1064,  1095,  1096,  1097,  1098,
    1101,  1102,  1103,  1105,  1106,  1114,  1131,  1100,  1107,  1108,
    1109,  1110,  1111,  1112,  1113,  1129,  1130,  1132,  1133,  1134,
    1135,  1136,     0,     0,  1138,  1137,     0,  1153,  1154,  1155,
    1157,  1156,  1158,  1159,  1160,  1165,     0,  1161,     0,  1170,
    1166,  1167,  1169,  1168,  1171,  1172,  1177,  1178,  1173,     0,
       0,  1179,  1180,  1181,  1185,     0,  1186,  1187,  1188,  1189,
    1190,  1191,  1192
};

static const yytype_int16 yycheck[] =
{
       4,    50,     5,     6,     5,    76,     5,     5,     6,     5,
       6,     8,     9,    99,     5,     6,     4,     4,    75,     4,
       4,    76,     4,     4,    73,     4,    46,    10,   114,     0,
       4,    11,    99,    43,    99,    12,    61,    75,    87,    99,
      89,    47,    91,    45,    93,    76,    95,   112,    75,   116,
     110,    48,   101,    73,   103,    14,   105,    77,   107,    79,
     109,    81,   111,    83,   113,    13,   115,    92,   117,    15,
     141,    49,    54,    39,    58,    56,    73,    62,   133,    66,
      68,   138,    78,    84,    82,    88,    90,    86,    85,    80,
      64,    70,   130,    51,   125,   122,     8,     9,     8,     9,
      39,     8,     9,    97,     8,     9,     8,     9,    97,     8,
       9,    97,     8,     9,   108,    39,   102,   106,     8,     9,
      27,    28,    29,     8,     9,    37,    38,    37,    38,    41,
      42,    41,    42,    37,    38,    37,     8,    41,    42,    41,
      42,    37,    97,     8,    15,    41,    42,    37,    38,   104,
      22,    23,    24,    94,     8,     9,    97,    22,    23,    24,
       3,    33,     8,     9,    36,     7,    38,     3,    40,    34,
       8,    36,     3,    38,     8,    40,    22,    23,    24,     8,
       9,     3,     8,     9,    22,    23,    24,     8,     9,     3,
      36,    15,    38,     8,    40,     8,     9,    35,    36,     7,
      38,     5,    40,     8,     9,     8,     9,    36,     4,    38,
      36,    40,    38,   133,    40,    36,   136,    38,     4,    40,
       8,     9,     7,    36,     7,    38,   121,    40,     8,     9,
       8,     9,    37,    38,    37,    38,     8,     9,     7,    19,
      20,    21,    44,   125,   141,    39,   128,   144,    16,    37,
      38,    53,    17,    55,    17,    57,    17,    59,    17,    61,
      18,    63,    18,    65,    17,    67,    18,    69,    17,    71,
      18,    73,     8,     9,    25,     8,     9,     8,     8,     9,
       8,     9,     7,    19,    20,    21,    19,    20,    21,    19,
      20,    21,     8,     9,     8,     9,     8,     9,     8,     9,
       8,     9,     8,     9,     8,     9,     8,     9,     8,     9,
       8,     9,     8,     9,     8,     9,     8,     9,     8,     9,
      74,    75,     8,     9,    74,    75,     8,     9,    74,    75,
       8,     9,    96,    97,   118,   119,    74,    75,     8,     9,
     146,   147,   124,   125,    15,   132,   133,   140,   141,     5,
       7,    54,    70,    58,     7,    56,     7,    64,   129,    68,
       5,    60,    30,    52,     5,    62,     5,     3,     8,     7,
       7,    66,    31,     8,     7,    86,     8,     7,     7,    72,
       8,     8,     7,   145,     8,     7,    32,     8,     7,    80,
       8,     7,   137,     8,     7,    80,     8,     7,    78,     8,
       7,    84,     8,     7,     5,     8,    78,     7,     7,     7,
       7,     7,     7,     7,     7,     5,     5,     5,     5,     5,
       5,     5,     5,     5,     5,     5,     5,     5,    82,    90,
       7,     7,    82,     5,     7,   123,     7,     7,     7,     7,
       7,     7,     7,     7,     7,     7,     7,     7,     7,     7,
       5,    26,   131,     7,   127,     8,     8,    88,     8,    33,
       8,     8,    88,     8,     8,     8,     3,     3,    76,     3,
       8,   135,     7,     5,   139,     8,     7,    34,     7,     4,
       4,     4,    33,     4,     4,     4,     4,     4,     3,     3,
       3,     7,    34,     5,    35,   143,     7,     5,     8,     8,
       7,     3,     3,     3,     3,     3,     3,     3,   100,   100,
       3,     3,     3,     3,     3,     3,     3,     3,   120,   142,
      76,   126,     7,     7,     7,     7,     7,     5,     8,    35,
       7,     3,     8,     7,     5,    62,    76,     3,     3,     7,
       7,    -1,     5,     7,    -1,     7,    -1,     8,     7,     5,
       7,   100,     7,     7,   100,     7,     7,     7,     7,    98,
       7,     7,     7,     7,     7,     7,     7,     7,    98,     7,
      98,     7,    98,    76,     5,     7,    98,     3,     3,     3,
       7,     3,     3,     3,     7,    -1,    -1,     3,     7,     7,
       7,     3,     3,    98,     7,     3,     3,     3,     7,     3,
       5,     3,     3,     3,     3,     3,     3,     3,     3,     3,
      -1,     3,     3,     3,     7,     3,     3,    -1,     7,     5,
       5,    -1,    -1,     7,     7,     7,     7,     7,     7,     7,
       7,     7,   126,     3,     5,     7,     5,     3,     3,   134,
       7,    -1,     5,     7,   148,     7,     7,     7,     7,     7,
       7,     7,     7,     7,     7,   134,     7,     7,     7,     5,
       7,     3,     3,     7,     7,     5,   126,   142,     7,     7,
       7,     7,     7,     7,     7,     7,     7,     7,     3,     3,
       3,     7,    -1,    -1,     5,     7,    -1,     7,     7,     7,
       7,   126,     3,     3,     3,     7,    -1,     5,    -1,     3,
       7,     7,     7,   142,     3,     3,     7,     7,     5,    -1,
      -1,     7,     7,     5,     7,    -1,     7,     7,     7,     7,
       7,     7,     7
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
      15,   205,   432,   293,     8,     9,    48,    73,    85,   269,
     270,   271,   272,   274,   275,    39,   226,    39,   233,    39,
     240,     8,     9,   247,    15,   251,     4,    54,     4,    56,
       4,    58,     3,     8,     9,   175,     4,    62,     4,    64,
       4,    66,     4,    68,     4,    70,     3,     8,     9,   201,
       7,     8,     8,     9,    27,    28,    29,   433,   434,   435,
     436,   437,    50,    73,    87,    89,    91,    93,    95,   101,
     103,   105,   107,   109,   111,   113,   115,   117,   294,   295,
     296,   302,   303,   306,   307,   312,   313,   318,   319,   324,
     325,   330,   331,   336,   337,   351,   352,   366,   367,   381,
     382,   396,   397,   402,   403,   408,   409,   414,   415,     5,
      86,    15,   276,     3,     8,     9,   228,     3,     8,     9,
     235,     3,     8,     9,   242,     5,    84,     7,     8,   162,
     166,   170,   174,     4,   176,   180,   184,   188,   192,   196,
     200,     4,   202,     5,   206,   207,   121,   438,   439,   440,
       7,     7,     7,    39,   297,     8,     9,   304,    16,   308,
      17,   314,    17,   320,    17,   326,    17,   332,    18,   338,
      18,   353,    18,   368,    18,   383,    17,   398,    17,   404,
      25,   410,    15,   416,   273,     7,     8,   227,     5,     6,
      78,   234,     5,     6,    80,   241,     5,     6,    82,   248,
       5,   252,   253,    54,    56,    58,     7,    60,    62,    64,
      66,    68,    70,     7,    72,     7,    74,    75,   208,    52,
     129,   497,   498,    30,   441,     5,     5,     5,     3,     8,
       9,   299,     4,    90,     7,     8,     7,     8,     7,     8,
       7,     8,     7,     8,     7,     8,     7,     8,     7,     8,
       7,     8,     7,     8,     7,     8,     7,     8,     7,     8,
      86,     5,   277,   278,     7,   230,   229,     7,   237,   236,
       7,   244,   243,    84,     7,    74,    75,   254,   209,   137,
     557,   558,    31,   499,     7,     8,     9,   442,     7,     7,
       7,   298,     5,     6,    88,   305,     5,   309,     5,   315,
       5,   321,     5,   327,     5,   333,     5,   339,     5,   354,
       5,   369,     5,   384,     5,   399,     5,   405,     5,   411,
       5,   417,   418,     7,    74,    75,   279,    78,    78,    80,
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

  case 195:

    {	if (parserData->serviceTypePresent)
	{	osolerror( NULL, osoption, parserData, "only one <type> element allowed");
	}
	else
	{	parserData->serviceTypePresent = true;
	}
}
    break;

  case 198:

    {osoption->service->type = (yyvsp[(2) - (2)].ival);}
    break;

  case 201:

    {	if (parserData->otherServiceOptionsPresent)
	{	osolerror( NULL, osoption, parserData, "only one <otherOptions> element allowed");
	}
	else
	{	parserData->otherServiceOptionsPresent = true;
		osoption->service->otherOptions = new OtherOptions();
	}
}
    break;

  case 202:

    {	osoption->service->otherOptions->numberOfOtherOptions = (yyvsp[(3) - (4)].ival);
	osoption->service->otherOptions->other = new OtherOption*[(yyvsp[(3) - (4)].ival)];
	for (int i=0; i < (yyvsp[(3) - (4)].ival); i++) osoption->service->otherOptions->other[i] = new OtherOption();
}
    break;

  case 203:

    {	if (parserData->numberOfOtherServiceOptions != osoption->service->otherOptions->numberOfOtherOptions)
		osolerror (NULL, osoption, parserData, "wrong number of other options in <service> element");
}
    break;

  case 206:

    {	if (parserData->numberOfOtherServiceOptions >= osoption->service->otherOptions->numberOfOtherOptions)
		{	osolerror (NULL, osoption, parserData, "too many other options in <service> element");
		};
	}
    break;

  case 207:

    {	if (!parserData->otherOptionNamePresent)
		osolerror (NULL, osoption, parserData, "name attribute must be present");
	/* reset defaults for the next option */
	parserData->otherOptionNamePresent = false;
	parserData->otherOptionValuePresent = false;
	parserData->otherOptionDescriptionPresent = false;
	parserData->numberOfOtherServiceOptions++;
}
    break;

  case 213:

    {	if (parserData->otherOptionNamePresent)
	{	osolerror( NULL, osoption, parserData, "only one name attribute allowed");
	}
	else
	{	parserData->otherOptionNamePresent = true;
		osoption->service->otherOptions->other[parserData->numberOfOtherServiceOptions]->name = (yyvsp[(2) - (2)].sval);
	}
}
    break;

  case 215:

    {	if (parserData->otherOptionValuePresent)
	{	osolerror( NULL, osoption, parserData, "only one value attribute allowed");
	}
	else
	{	parserData->otherOptionValuePresent = true;
		osoption->service->otherOptions->other[parserData->numberOfOtherServiceOptions]->value = (yyvsp[(2) - (2)].sval);
	}
}
    break;

  case 217:

    {	if (parserData->otherOptionDescriptionPresent)
	{	osolerror( NULL, osoption, parserData, "only one description attribute allowed");
	}
	else
	{	parserData->otherOptionDescriptionPresent = true;
		osoption->service->otherOptions->other[parserData->numberOfOtherServiceOptions]->description = (yyvsp[(2) - (2)].sval);
	}
}
    break;

  case 222:

    {	if (parserData->osoljobPresent)
	{	osolerror( NULL, osoption, parserData, "only one <job> element allowed");
	}
	else
	{	parserData->osoljobPresent = true;
		osoption->job = new JobOption();
	}
}
    break;

  case 243:

    {	if (parserData->maxTimePresent)
	{	osolerror( NULL, osoption, parserData, "only one <maxTime> element allowed");
	}
	else
	{	parserData-> maxTimePresent = true;
		osoption->job->maxTime = new MaxTime();
	}
}
    break;

  case 245:

    {osoption->job->maxTime->unit = (yyvsp[(2) - (2)].sval);}
    break;

  case 249:

    {osoption->job->maxTime->value = (yyvsp[(2) - (2)].dval);}
    break;

  case 251:

    {osoption->job->maxTime->value = (yyvsp[(2) - (2)].ival);}
    break;

  case 254:

    {	if (parserData->scheduledStartTimePresent)
	{	osolerror( NULL, osoption, parserData, "only one <scheduledStartTime> element allowed");
	}
	else
	{	parserData->scheduledStartTimePresent = true;
	}
}
    break;

  case 257:

    {osoption->job->scheduledStartTime = (yyvsp[(2) - (2)].sval);}
    break;

  case 260:

    {	if (parserData->dependenciesPresent)
	{	osolerror( NULL, osoption, parserData, "only one <dependencies> element allowed");
	}
	else
	{	parserData->dependenciesPresent = true;
		osoption->job->dependencies = new JobDependencies();
	}
}
    break;

  case 261:

    {	osoption->job->dependencies->numberOfJobIDs = (yyvsp[(3) - (4)].ival);
	osoption->job->dependencies->jobID = new std::string[(yyvsp[(3) - (4)].ival)];
}
    break;

  case 264:

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

  case 267:

    {	if (parserData->requiredDirectoriesPresent)
	{	osolerror( NULL, osoption, parserData, "only one <requiredDirectories> element allowed");
	}
	else
	{	parserData->requiredDirectoriesPresent = true;
		osoption->job->requiredDirectories = new DirectoriesAndFiles();
	}
}
    break;

  case 268:

    {	osoption->job->requiredDirectories->numberOfPaths = (yyvsp[(3) - (4)].ival);
	osoption->job->requiredDirectories->path = new std::string[(yyvsp[(3) - (4)].ival)];
}
    break;

  case 271:

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

  case 274:

    {	if (parserData->requiredFilesPresent)
	{	osolerror( NULL, osoption, parserData, "only one <requiredFiles> element allowed");
	}
	else
	{	parserData->requiredFilesPresent = true;
		osoption->job->requiredFiles = new DirectoriesAndFiles();
	}
}
    break;

  case 275:

    {	osoption->job->requiredFiles->numberOfPaths = (yyvsp[(3) - (4)].ival);
	osoption->job->requiredFiles->path = new std::string[(yyvsp[(3) - (4)].ival)];
}
    break;

  case 278:

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

  case 281:

    {	if (parserData->directoriesToMakePresent)
	{	osolerror( NULL, osoption, parserData, "only one <directoriesToMake> element allowed");
	}
	else
	{	parserData->directoriesToMakePresent = true;
		osoption->job->directoriesToMake = new DirectoriesAndFiles();
	}
}
    break;

  case 282:

    {	osoption->job->directoriesToMake->numberOfPaths = (yyvsp[(3) - (4)].ival);
	osoption->job->directoriesToMake->path = new std::string[(yyvsp[(3) - (4)].ival)];
}
    break;

  case 285:

    {	if (parserData->numberOfDirectoriesToMake >= osoption->job->directoriesToMake->numberOfPaths)
	{	osolerror (NULL, osoption, parserData, "too many job IDs in <directoriesToMake> element");
	}
	else
	{	osoption->job->directoriesToMake->path[parserData->numberOfDirectoriesToMake] = (yyvsp[(3) - (3)].sval);
		parserData->numberOfDirectoriesToMake++;
	};
}
    break;

  case 288:

    {	if (parserData->filesToCreatePresent)
	{	osolerror( NULL, osoption, parserData, "only one <filesToCreate> element allowed");
	}
	else
	{	parserData->filesToCreatePresent = true;
		osoption->job->filesToCreate = new DirectoriesAndFiles();
	}
}
    break;

  case 289:

    {	osoption->job->filesToCreate->numberOfPaths = (yyvsp[(3) - (4)].ival);
	osoption->job->filesToCreate->path = new std::string[(yyvsp[(3) - (4)].ival)];
}
    break;

  case 292:

    {	if (parserData->numberOfFilesToCreate >= osoption->job->filesToCreate->numberOfPaths)
	{	osolerror (NULL, osoption, parserData, "too many job IDs in <filesToCreate> element");
	}
	else
	{	osoption->job->filesToCreate->path[parserData->numberOfFilesToCreate] = (yyvsp[(3) - (3)].sval);
		parserData->numberOfFilesToCreate++;
	};
}
    break;

  case 295:

    {	if (parserData->inputDirectoriesToMovePresent)
	{	osolerror( NULL, osoption, parserData, "only one <inputDirectoriesToMove> element allowed");
	}
	else
	{	parserData->inputDirectoriesToMovePresent = true;
		osoption->job->inputDirectoriesToMove = new PathPairs();
	}
}
    break;

  case 296:

    {	if ((yyvsp[(3) - (4)].ival) <= 0) osolerror (NULL, osoption, parserData, "Require positive number of directories to move");
	osoption->job->inputDirectoriesToMove->numberOfPathPairs = (yyvsp[(3) - (4)].ival);
	osoption->job->inputDirectoriesToMove->pathPair = new PathPair*[(yyvsp[(3) - (4)].ival)];
	for (int i = 0; i < (yyvsp[(3) - (4)].ival); i++)
		osoption->job->inputDirectoriesToMove->pathPair[i] = new PathPair();
}
    break;

  case 299:

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

  case 300:

    {	if (parserData->numberOfInputDirectoriesToMove >= osoption->job->inputDirectoriesToMove->numberOfPathPairs)
	{	osolerror (NULL, osoption, parserData, "too many path pairs in <inputDirectoriesToMove> element");
	};
}
    break;

  case 306:

    {	if (parserData->pathPairFromPresent)
	{	osolerror( NULL, osoption, parserData, "only one \"from\" attribute allowed");
	}
	else
	{	parserData->pathPairFromPresent = true;
		osoption->job->inputDirectoriesToMove->pathPair[parserData->numberOfInputDirectoriesToMove]->from = (yyvsp[(2) - (2)].sval);
	}
}
    break;

  case 308:

    {	if (parserData->pathPairToPresent)
	{	osolerror( NULL, osoption, parserData, "only one \"to\" attribute allowed");
	}
	else
	{	parserData->pathPairToPresent = true;
		osoption->job->inputDirectoriesToMove->pathPair[parserData->numberOfInputDirectoriesToMove]->to = (yyvsp[(2) - (2)].sval);
	}
}
    break;

  case 310:

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

  case 315:

    {	if (parserData->inputFilesToMovePresent)
	{	osolerror( NULL, osoption, parserData, "only one <inputFilesToMove> element allowed");
	}
	else
	{	parserData->inputFilesToMovePresent = true;
		osoption->job->inputFilesToMove = new PathPairs();
	}
}
    break;

  case 316:

    {	if ((yyvsp[(3) - (4)].ival) <= 0) osolerror (NULL, osoption, parserData, "Require positive number of files to move");
	osoption->job->inputFilesToMove->numberOfPathPairs = (yyvsp[(3) - (4)].ival);
	osoption->job->inputFilesToMove->pathPair = new PathPair*[(yyvsp[(3) - (4)].ival)];
	for (int i = 0; i < (yyvsp[(3) - (4)].ival); i++) osoption->job->inputFilesToMove->pathPair[i] = new PathPair();
}
    break;

  case 319:

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

  case 320:

    {	if (parserData->numberOfInputFilesToMove >= osoption->job->inputFilesToMove->numberOfPathPairs)
	{	osolerror (NULL, osoption, parserData, "too many path pairs in <inputFilesToMove> element");
	};
}
    break;

  case 326:

    {	if (parserData->pathPairFromPresent)
	{	osolerror( NULL, osoption, parserData, "only one \"from\" attribute allowed");
	}
	else
	{	parserData->pathPairFromPresent = true;
		osoption->job->inputFilesToMove->pathPair[parserData->numberOfInputFilesToMove]->from = (yyvsp[(2) - (2)].sval);
	}
}
    break;

  case 328:

    {	if (parserData->pathPairToPresent)
	{	osolerror( NULL, osoption, parserData, "only one \"to\" attribute allowed");
	}
	else
	{	parserData->pathPairToPresent = true;
		osoption->job->inputFilesToMove->pathPair[parserData->numberOfInputFilesToMove]->to = (yyvsp[(2) - (2)].sval);
	}
}
    break;

  case 330:

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

  case 335:

    {	if (parserData->outputDirectoriesToMovePresent)
	{	osolerror( NULL, osoption, parserData, "only one <outputDirectoriesToMove> element allowed");
	}
	else
	{	parserData->outputDirectoriesToMovePresent = true;
		osoption->job->outputDirectoriesToMove = new PathPairs();
	}
}
    break;

  case 336:

    {	if ((yyvsp[(3) - (4)].ival) <= 0) osolerror (NULL, osoption, parserData, "Require positive number of directories to move");
	osoption->job->outputDirectoriesToMove->numberOfPathPairs = (yyvsp[(3) - (4)].ival);
	osoption->job->outputDirectoriesToMove->pathPair = new PathPair*[(yyvsp[(3) - (4)].ival)];
	for (int i = 0; i < (yyvsp[(3) - (4)].ival); i++)
		osoption->job->outputDirectoriesToMove->pathPair[i] = new PathPair();
}
    break;

  case 339:

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

  case 340:

    {	if (parserData->numberOfOutputDirectoriesToMove >= osoption->job->outputDirectoriesToMove->numberOfPathPairs)
	{	osolerror (NULL, osoption, parserData, "too many path pairs in <outputDirectoriesToMove> element");
	};
}
    break;

  case 346:

    {	if (parserData->pathPairFromPresent)
	{	osolerror( NULL, osoption, parserData, "only one \"from\" attribute allowed");
	}
	else
	{	parserData->pathPairFromPresent = true;
		osoption->job->outputDirectoriesToMove->pathPair[parserData->numberOfOutputDirectoriesToMove]->from = (yyvsp[(2) - (2)].sval);
	}
}
    break;

  case 348:

    {	if (parserData->pathPairToPresent)
	{	osolerror( NULL, osoption, parserData, "only one \"to\" attribute allowed");
	}
	else
	{	parserData->pathPairToPresent = true;
		osoption->job->outputDirectoriesToMove->pathPair[parserData->numberOfOutputDirectoriesToMove]->to = (yyvsp[(2) - (2)].sval);
	}
}
    break;

  case 350:

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

  case 355:

    {	if (parserData->outputFilesToMovePresent)
	{	osolerror( NULL, osoption, parserData, "only one <outputFilesToMove> element allowed");
	}
	else
	{	parserData->outputFilesToMovePresent = true;
		osoption->job->outputFilesToMove = new PathPairs();
	}
}
    break;

  case 356:

    {	if ((yyvsp[(3) - (4)].ival) <= 0) osolerror (NULL, osoption, parserData, "Require positive number of files to move");
	osoption->job->outputFilesToMove->numberOfPathPairs = (yyvsp[(3) - (4)].ival);
	osoption->job->outputFilesToMove->pathPair = new PathPair*[(yyvsp[(3) - (4)].ival)];
	for (int i = 0; i < (yyvsp[(3) - (4)].ival); i++)
		osoption->job->outputFilesToMove->pathPair[i] = new PathPair();}
    break;

  case 359:

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

  case 360:

    {	if (parserData->numberOfOutputFilesToMove >= osoption->job->outputFilesToMove->numberOfPathPairs)
	{	osolerror (NULL, osoption, parserData, "too many path pairs in <outputFilesToMove> element");
	};
}
    break;

  case 366:

    {	if (parserData->pathPairFromPresent)
	{	osolerror( NULL, osoption, parserData, "only one \"from\" attribute allowed");
	}
	else
	{	parserData->pathPairFromPresent = true;
		osoption->job->outputFilesToMove->pathPair[parserData->numberOfOutputFilesToMove]->from = (yyvsp[(2) - (2)].sval);
	}
}
    break;

  case 368:

    {	if (parserData->pathPairToPresent)
	{	osolerror( NULL, osoption, parserData, "only one \"to\" attribute allowed");
	}
	else
	{	parserData->pathPairToPresent = true;
		osoption->job->outputFilesToMove->pathPair[parserData->numberOfOutputFilesToMove]->to = (yyvsp[(2) - (2)].sval);
	}
}
    break;

  case 370:

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

  case 375:

    {	if (parserData->filesToDeletePresent)
	{	osolerror( NULL, osoption, parserData, "only one <filesToDelete> element allowed");
	}
	else
	{	parserData->filesToDeletePresent = true;
		osoption->job->filesToDelete = new DirectoriesAndFiles();
	}
}
    break;

  case 376:

    {	osoption->job->filesToDelete->numberOfPaths = (yyvsp[(3) - (4)].ival);
	osoption->job->filesToDelete->path = new std::string[(yyvsp[(3) - (4)].ival)];
}
    break;

  case 379:

    {	if (parserData->numberOfFilesToDelete >= osoption->job->filesToDelete->numberOfPaths)
	{	osolerror (NULL, osoption, parserData, "too many job IDs in <filesToDelete> element");
	}
	else
	{	osoption->job->filesToDelete->path[parserData->numberOfFilesToDelete] = (yyvsp[(3) - (3)].sval);
		parserData->numberOfFilesToDelete++;
	};
}
    break;

  case 382:

    {	if (parserData->directoriesToDeletePresent)
	{	osolerror( NULL, osoption, parserData, "only one <directoriesToDelete> element allowed");
	}
	else
	{	parserData->directoriesToDeletePresent = true;
		osoption->job->directoriesToDelete = new DirectoriesAndFiles();
	}
}
    break;

  case 383:

    {	osoption->job->directoriesToDelete->numberOfPaths = (yyvsp[(3) - (4)].ival);
	osoption->job->directoriesToDelete->path = new std::string[(yyvsp[(3) - (4)].ival)];
}
    break;

  case 386:

    {	if (parserData->numberOfDirectoriesToDelete >= osoption->job->directoriesToDelete->numberOfPaths)
	{	osolerror (NULL, osoption, parserData, "too many job IDs in <directoriesToDelete> element");
	}
	else
	{	osoption->job->directoriesToDelete->path[parserData->numberOfDirectoriesToDelete] = (yyvsp[(3) - (3)].sval);
		parserData->numberOfDirectoriesToDelete++;
	};
}
    break;

  case 389:

    {	if (parserData->processesToKillPresent)
	{	osolerror( NULL, osoption, parserData, "only one <processesToKill> element allowed");
	}
	else
	{	parserData->processesToKillPresent = true;
		osoption->job->processesToKill = new Processes();
	}
}
    break;

  case 390:

    {	osoption->job->processesToKill->numberOfProcesses = (yyvsp[(3) - (4)].ival);
	osoption->job->processesToKill->process = new std::string[(yyvsp[(3) - (4)].ival)];
}
    break;

  case 393:

    {	if (parserData->numberOfProcessesToKill >= osoption->job->processesToKill->numberOfProcesses)
	{	osolerror (NULL, osoption, parserData, "too many job IDs in <processesToKill> element");
	}
	else
	{	osoption->job->processesToKill->process[parserData->numberOfProcessesToKill] = (yyvsp[(3) - (3)].sval);
		parserData->numberOfProcessesToKill++;
	};
}
    break;

  case 396:

    {	if (parserData->otherJobOptionsPresent)
	{	osolerror( NULL, osoption, parserData, "only one <otherOptions> element allowed");
	}
	else
	{	parserData->otherJobOptionsPresent = true;
		osoption->job->otherOptions = new OtherOptions();
	}
}
    break;

  case 397:

    {	osoption->job->otherOptions->numberOfOtherOptions = (yyvsp[(3) - (4)].ival);
	osoption->job->otherOptions->other = new OtherOption*[(yyvsp[(3) - (4)].ival)];
	for (int i=0; i < (yyvsp[(3) - (4)].ival); i++) osoption->job->otherOptions->other[i] = new OtherOption();
}
    break;

  case 398:

    {	if (parserData->numberOfOtherJobOptions != osoption->job->otherOptions->numberOfOtherOptions)
		osolerror (NULL, osoption, parserData, "wrong number of other options in <job> element");
}
    break;

  case 401:

    {	if (parserData->numberOfOtherJobOptions >= osoption->job->otherOptions->numberOfOtherOptions)
		{	osolerror (NULL, osoption, parserData, "too many other options in <job> element");
		};
	}
    break;

  case 402:

    {	if (!parserData->otherOptionNamePresent)
		osolerror (NULL, osoption, parserData, "name attribute must be present");
	/* reset defaults for the next option */
	parserData->otherOptionNamePresent = false;
	parserData->otherOptionValuePresent = false;
	parserData->otherOptionDescriptionPresent = false;
	parserData->numberOfOtherJobOptions++;
}
    break;

  case 408:

    {	if (parserData->otherOptionNamePresent)
	{	osolerror( NULL, osoption, parserData, "only one name attribute allowed");
	}
	else
	{	parserData->otherOptionNamePresent = true;
		osoption->job->otherOptions->other[parserData->numberOfOtherJobOptions]->name = (yyvsp[(2) - (2)].sval);
	}
}
    break;

  case 410:

    {	if (parserData->otherOptionValuePresent)
	{	osolerror( NULL, osoption, parserData, "only one value attribute allowed");
	}
	else
	{	parserData->otherOptionValuePresent = true;
		osoption->job->otherOptions->other[parserData->numberOfOtherJobOptions]->value = (yyvsp[(2) - (2)].sval);
	}
}
    break;

  case 412:

    {	if (parserData->otherOptionDescriptionPresent)
	{	osolerror( NULL, osoption, parserData, "only one description attribute allowed");
	}
	else
	{	parserData->otherOptionDescriptionPresent = true;
		osoption->job->otherOptions->other[parserData->numberOfOtherJobOptions]->description = (yyvsp[(2) - (2)].sval);
	}
}
    break;

  case 418:

    {	if (parserData->osoloptimizationPresent)
	{	osolerror( NULL, osoption, parserData, "only one <optimization> element allowed");
	}
	else
	{	parserData->osoloptimizationPresent = true;
		osoption->optimization = new OptimizationOption();
	}
}
    break;

  case 424:

    {	osoption->optimization->numberOfVariables = (yyvsp[(3) - (4)].ival);
}
    break;

  case 425:

    {	osoption->optimization->numberOfConstraints = (yyvsp[(3) - (4)].ival);
}
    break;

  case 426:

    {	osoption->optimization->numberOfObjectives = (yyvsp[(3) - (4)].ival);
}
    break;

  case 432:

    {	osoption->optimization->variables = new VariableOption();
}
    break;

  case 434:

    {	if ((yyvsp[(3) - (4)].ival) < 0) osolerror (NULL, osoption, parserData, "number of <other> variable options cannot be negative");
	osoption->optimization->variables->numberOfOtherVariableOptions = (yyvsp[(3) - (4)].ival);
	osoption->optimization->variables->other = new OtherVariableOption*[(yyvsp[(3) - (4)].ival)];
	for (int i= 0; i < (yyvsp[(3) - (4)].ival); i++)
		osoption->optimization->variables->other[i] = new OtherVariableOption();
}
    break;

  case 439:

    {	if ((yyvsp[(3) - (4)].ival) <= 0) osolerror (NULL, osoption, parserData, "number of <var> elements must be positive");
	osoption->optimization->variables->initialVariableValues = new InitVariableValues();
	osoption->optimization->variables->initialVariableValues->numberOfVar = (yyvsp[(3) - (4)].ival);
	osoption->optimization->variables->initialVariableValues->var = new InitVarValue*[(yyvsp[(3) - (4)].ival)];
	for (int i = 0; i < (yyvsp[(3) - (4)].ival); i++)
		osoption->optimization->variables->initialVariableValues->var[i] = new InitVarValue();
}
    break;

  case 442:

    {	if (!parserData->idxAttributePresent)
		osolerror (NULL, osoption, parserData, "variable index required");
	parserData->idxAttributePresent = false;
	parserData->valAttributePresent = false;
	parserData->numberOfVar++;
}
    break;

  case 443:

    {	if (parserData->numberOfVar >= osoption->optimization->variables->initialVariableValues->numberOfVar)
		osolerror(NULL, osoption, parserData, "too many initial variable values");
}
    break;

  case 448:

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

  case 449:

    {	if (parserData->valAttributePresent)
		osolerror (NULL, osoption, parserData, "only one variable value allowed");
	parserData->valAttributePresent = true;
	osoption->optimization->variables->initialVariableValues->var[parserData->numberOfVar]->value = strtod((yyvsp[(2) - (2)].sval), NULL);
}
    break;

  case 455:

    {	if ((yyvsp[(3) - (4)].ival) <= 0) osolerror (NULL, osoption, parserData, "number of <var> elements must be positive");
	osoption->optimization->variables->initialVariableValuesString = new InitVariableValuesString ();
	osoption->optimization->variables->initialVariableValuesString->numberOfVar = (yyvsp[(3) - (4)].ival);
	osoption->optimization->variables->initialVariableValuesString->var = new InitVarValueString*[(yyvsp[(3) - (4)].ival)];
	for (int i = 0; i < (yyvsp[(3) - (4)].ival); i++)
		osoption->optimization->variables->initialVariableValuesString->var[i] = new InitVarValueString ();
}
    break;

  case 458:

    {	if (!parserData->idxAttributePresent)
		osolerror (NULL, osoption, parserData, "variable index required");
	parserData->idxAttributePresent = false;
	parserData->valAttributePresent = false;
	parserData->numberOfVarStr++;
}
    break;

  case 459:

    {	if (parserData->numberOfVarStr >= osoption->optimization->variables->initialVariableValuesString->numberOfVar)
		osolerror(NULL, osoption, parserData, "too many initial variable strings");
}
    break;

  case 464:

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

  case 465:

    {	if (parserData->valAttributePresent)
		osolerror (NULL, osoption, parserData, "only one variable index allowed");
	parserData->valAttributePresent = true;
	osoption->optimization->variables->initialVariableValuesString->var[parserData->numberOfVarStr]->value = (yyvsp[(2) - (2)].sval);
}
    break;

  case 472:

    {	if (parserData->numberOfOtherVariableOptions >= osoption->optimization->variables->numberOfOtherVariableOptions)
		osolerror(NULL, osoption, parserData, "too many <other> variable options");
}
    break;

  case 482:

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

  case 483:

    {	if (parserData->otherOptionNamePresent)
		osolerror (NULL, osoption, parserData, "only one name attribute allowed");
	parserData->otherOptionNamePresent = true;
	osoption->optimization->variables->other[parserData->numberOfOtherVariableOptions]->name = (yyvsp[(2) - (2)].sval);
}
    break;

  case 485:

    {	if (parserData->otherOptionValuePresent)
		osolerror (NULL, osoption, parserData, "only one value attribute allowed");
	parserData->otherOptionValuePresent = true;
	osoption->optimization->variables->other[parserData->numberOfOtherVariableOptions]->value = (yyvsp[(2) - (2)].sval);
}
    break;

  case 487:

    {	if (parserData->otherOptionSolverPresent)
		osolerror (NULL, osoption, parserData, "only one solver attribute allowed");
	parserData->otherOptionSolverPresent = true;
	osoption->optimization->variables->other[parserData->numberOfOtherVariableOptions]->solver = (yyvsp[(2) - (2)].sval);
}
    break;

  case 489:

    {	if (parserData->otherOptionCategoryPresent)
		osolerror (NULL, osoption, parserData, "only one category attribute allowed");
	parserData->otherOptionCategoryPresent = true;
	osoption->optimization->variables->other[parserData->numberOfOtherVariableOptions]->category = (yyvsp[(2) - (2)].sval);
}
    break;

  case 491:

    {	if (parserData->otherOptionTypePresent)
		osolerror (NULL, osoption, parserData, "only one type attribute allowed");
	parserData->otherOptionTypePresent = true;
	osoption->optimization->variables->other[parserData->numberOfOtherVariableOptions]->type = (yyvsp[(2) - (2)].sval);
}
    break;

  case 493:

    {	if (parserData->otherOptionDescriptionPresent)
		osolerror (NULL, osoption, parserData, "only one description attribute allowed");
	parserData->otherOptionDescriptionPresent = true;
	osoption->optimization->variables->other[parserData->numberOfOtherVariableOptions]->description = (yyvsp[(2) - (2)].sval);
}
    break;

  case 495:

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

  case 498:

    {	if (!parserData->idxAttributePresent)
		osolerror(NULL, osoption, parserData, "required idx attribute was not found");
	parserData->idxAttributePresent = false;
	parserData->valAttributePresent = false;
	parserData->lbvalAttributePresent = false;
	parserData->ubvalAttributePresent = false;
	parserData->numberOfVar++;
}
    break;

  case 499:

    {	if (parserData->numberOfVar >= osoption->optimization->variables->other[parserData->numberOfOtherVariableOptions]->numberOfVar)
		osolerror(NULL, osoption, parserData, "too many <var> entries in <other> variable element");
}
    break;

  case 506:

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

  case 507:

    {	if (parserData->valAttributePresent)
		osolerror (NULL, osoption, parserData, "only one variable value allowed");
	parserData->valAttributePresent = true;
	osoption->optimization->variables-> other[parserData->numberOfOtherVariableOptions]->var[parserData->numberOfVar]->value = (yyvsp[(2) - (2)].sval);
}
    break;

  case 509:

    {	if (parserData->lbvalAttributePresent)
		osolerror (NULL, osoption, parserData, "only one lower bound value allowed");
	parserData->lbvalAttributePresent = true;
	osoption->optimization->variables-> other[parserData->numberOfOtherVariableOptions]->var[parserData->numberOfVar]->lbValue = (yyvsp[(2) - (2)].sval);
}
    break;

  case 511:

    {	if (parserData->ubvalAttributePresent)
		osolerror (NULL, osoption, parserData, "only one upper bound value allowed");
	parserData->ubvalAttributePresent = true;
	osoption->optimization->variables-> other[parserData->numberOfOtherVariableOptions]->var[parserData->numberOfVar]->ubValue = (yyvsp[(2) - (2)].sval);
}
    break;

  case 517:

    {	osoption->optimization->objectives = new ObjectiveOption();
}
    break;

  case 519:

    {	if ((yyvsp[(3) - (4)].ival) < 0) osolerror (NULL, osoption, parserData, "number of <other> objective options cannot be negative");
        osoption->optimization->objectives->numberOfOtherObjectiveOptions = (yyvsp[(3) - (4)].ival);
	osoption->optimization->objectives->other = new OtherObjectiveOption*[(yyvsp[(3) - (4)].ival)];
	for (int i= 0; i < (yyvsp[(3) - (4)].ival); i++)
		osoption->optimization->objectives->other[i] = new OtherObjectiveOption();
}
    break;

  case 524:

    {	if ((yyvsp[(3) - (4)].ival) <= 0) osolerror (NULL, osoption, parserData, "number of <obj> elements must be positive");
	osoption->optimization->objectives->initialObjectiveValues = new InitObjectiveValues();
	osoption->optimization->objectives->initialObjectiveValues->numberOfObj = (yyvsp[(3) - (4)].ival);
	osoption->optimization->objectives->initialObjectiveValues->obj = new InitObjValue*[(yyvsp[(3) - (4)].ival)];
	for (int i = 0; i < (yyvsp[(3) - (4)].ival); i++)
		osoption->optimization->objectives->initialObjectiveValues->obj[i] = new InitObjValue();
}
    break;

  case 527:

    {	if (!parserData->idxAttributePresent)
		osolerror (NULL, osoption, parserData, "objective index required");
	parserData->idxAttributePresent = false;
	parserData->valAttributePresent = false;
	parserData->numberOfObjValues++;
}
    break;

  case 528:

    {	if (parserData->numberOfObjValues >= osoption->optimization->objectives->initialObjectiveValues->numberOfObj)
		osolerror(NULL, osoption, parserData, "too many initial objective values");
}
    break;

  case 533:

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

  case 534:

    {	if (parserData->valAttributePresent)
		osolerror (NULL, osoption, parserData, "only one objective value allowed");
	parserData->valAttributePresent = true;
	osoption->optimization->objectives->initialObjectiveValues->obj[parserData->numberOfObjValues]->value = strtod((yyvsp[(2) - (2)].sval), NULL);
}
    break;

  case 540:

    {	if ((yyvsp[(3) - (4)].ival) <= 0) osolerror (NULL, osoption, parserData, "number of <obj> elements must be positive");
	osoption->optimization->objectives->initialObjectiveBounds = new InitObjectiveBounds();
	osoption->optimization->objectives->initialObjectiveBounds->numberOfObj = (yyvsp[(3) - (4)].ival);
	osoption->optimization->objectives->initialObjectiveBounds->obj = new InitObjBound*[(yyvsp[(3) - (4)].ival)];
	for (int i = 0; i < (yyvsp[(3) - (4)].ival); i++)
		osoption->optimization->objectives->initialObjectiveBounds->obj[i] = new InitObjBound ();
}
    break;

  case 543:

    {	if (!parserData->idxAttributePresent)
		osolerror (NULL, osoption, parserData, "objective index required");
	parserData->idxAttributePresent = false;
	parserData->lbvalAttributePresent = false;
	parserData->ubvalAttributePresent = false;
	parserData->numberOfObjBounds++;
}
    break;

  case 544:

    {	if (parserData->numberOfObjBounds >= osoption->optimization->objectives->initialObjectiveBounds->numberOfObj)
		osolerror(NULL, osoption, parserData, "too many initial objective bounds");
}
    break;

  case 550:

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

  case 551:

    {	if (parserData->lbvalAttributePresent)
		osolerror (NULL, osoption, parserData, "only one objective lower bound allowed");
	parserData->lbvalAttributePresent = true;
	osoption->optimization->objectives->initialObjectiveBounds->obj[parserData->numberOfObjBounds]->lbValue = strtod((yyvsp[(2) - (2)].sval), NULL);
}
    break;

  case 553:

    {	if (parserData->ubvalAttributePresent)
		osolerror (NULL, osoption, parserData, "only one objective upper bound allowed");
	parserData->ubvalAttributePresent = true;
	osoption->optimization->objectives->initialObjectiveBounds->obj[parserData->numberOfObjBounds]->ubValue = strtod((yyvsp[(2) - (2)].sval), NULL);
}
    break;

  case 560:

    {	if (parserData->numberOfOtherObjectiveOptions >= osoption->optimization->objectives->numberOfOtherObjectiveOptions)
		osolerror(NULL, osoption, parserData, "too many <other> objective options");
}
    break;

  case 570:

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

  case 571:

    {	if (parserData->otherOptionNamePresent)
		osolerror (NULL, osoption, parserData, "only one name attribute allowed");
	parserData->otherOptionNamePresent = true;
	osoption->optimization->objectives->other[parserData->numberOfOtherObjectiveOptions]->name = (yyvsp[(2) - (2)].sval);
}
    break;

  case 573:

    {	if (parserData->otherOptionValuePresent)
		osolerror (NULL, osoption, parserData, "only one value attribute allowed");
	parserData->otherOptionValuePresent = true;
	osoption->optimization->objectives->other[parserData->numberOfOtherObjectiveOptions]->value = (yyvsp[(2) - (2)].sval);
}
    break;

  case 575:

    {	if (parserData->otherOptionSolverPresent)
		osolerror (NULL, osoption, parserData, "only one solver attribute allowed");
	parserData->otherOptionSolverPresent = true;
	osoption->optimization->objectives->other[parserData->numberOfOtherObjectiveOptions]->solver = (yyvsp[(2) - (2)].sval);
}
    break;

  case 577:

    {	if (parserData->otherOptionCategoryPresent)
		osolerror (NULL, osoption, parserData, "only one category attribute allowed");
	parserData->otherOptionCategoryPresent = true;
	osoption->optimization->objectives->other[parserData->numberOfOtherObjectiveOptions]->category = (yyvsp[(2) - (2)].sval);
}
    break;

  case 579:

    {	if (parserData->otherOptionTypePresent)
		osolerror (NULL, osoption, parserData, "only one type attribute allowed");
	parserData->otherOptionTypePresent = true;
	osoption->optimization->objectives->other[parserData->numberOfOtherObjectiveOptions]->type = (yyvsp[(2) - (2)].sval);
}
    break;

  case 581:

    {	if (parserData->otherOptionDescriptionPresent)
		osolerror (NULL, osoption, parserData, "only one description attribute allowed");
	parserData->otherOptionDescriptionPresent = true;
	osoption->optimization->objectives->other[parserData->numberOfOtherObjectiveOptions]->description = (yyvsp[(2) - (2)].sval);
}
    break;

  case 583:

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

  case 586:

    {	if (!parserData->idxAttributePresent)
		osolerror(NULL, osoption, parserData, "required idx attribute was not found");
	parserData->idxAttributePresent = false;
	parserData->valAttributePresent = false;
	parserData->lbvalAttributePresent = false;
	parserData->ubvalAttributePresent = false;
	parserData->numberOfObj++;
}
    break;

  case 587:

    {	if (parserData->numberOfObj >= osoption->optimization->objectives->other[parserData->numberOfOtherObjectiveOptions]->numberOfObj)
		osolerror(NULL, osoption, parserData, "too many <obj> entries in <other> objective element");
}
    break;

  case 594:

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

  case 595:

    {	if (parserData->valAttributePresent)
		osolerror (NULL, osoption, parserData, "only one variable value allowed");
	parserData->valAttributePresent = true;
	osoption->optimization->objectives-> other[parserData->numberOfOtherObjectiveOptions]->obj[parserData->numberOfObj]->value = (yyvsp[(2) - (2)].sval);
}
    break;

  case 597:

    {	if (parserData->lbvalAttributePresent)
		osolerror (NULL, osoption, parserData, "only one lower bound value allowed");
	parserData->lbvalAttributePresent = true;
	osoption->optimization->objectives-> other[parserData->numberOfOtherObjectiveOptions]->obj[parserData->numberOfObj]->lbValue = (yyvsp[(2) - (2)].sval);
}
    break;

  case 599:

    {	if (parserData->ubvalAttributePresent)
		osolerror (NULL, osoption, parserData, "only one upper bound value allowed");
	parserData->ubvalAttributePresent = true;
	osoption->optimization->objectives-> other[parserData->numberOfOtherObjectiveOptions]->obj[parserData->numberOfObj]->ubValue = (yyvsp[(2) - (2)].sval);
}
    break;

  case 605:

    {	osoption->optimization->constraints = new ConstraintOption();
}
    break;

  case 607:

    {	if ((yyvsp[(3) - (4)].ival) < 0) osolerror (NULL, osoption, parserData, "number of <other> constraint options cannot be negative");
        osoption->optimization->constraints->numberOfOtherConstraintOptions = (yyvsp[(3) - (4)].ival);
	osoption->optimization->constraints->other = new OtherConstraintOption*[(yyvsp[(3) - (4)].ival)];
	for (int i= 0; i < (yyvsp[(3) - (4)].ival); i++)
		osoption->optimization->constraints->other[i] = new OtherConstraintOption();
}
    break;

  case 612:

    {	if ((yyvsp[(3) - (4)].ival) <= 0) osolerror (NULL, osoption, parserData, "number of <con> elements must be positive");
	osoption->optimization->constraints->initialConstraintValues = new InitConstraintValues();
	osoption->optimization->constraints->initialConstraintValues->numberOfCon = (yyvsp[(3) - (4)].ival);
	osoption->optimization->constraints->initialConstraintValues->con = new InitConValue*[(yyvsp[(3) - (4)].ival)];
	for (int i = 0; i < (yyvsp[(3) - (4)].ival); i++)
		osoption->optimization->constraints->initialConstraintValues->con[i] = new InitConValue();
}
    break;

  case 615:

    {	if (!parserData->idxAttributePresent)
		osolerror (NULL, osoption, parserData, "variable index required");
	parserData->idxAttributePresent = false;
	parserData->valAttributePresent = false;
	parserData->numberOfCon++;
}
    break;

  case 616:

    {	if (parserData->numberOfCon >= osoption->optimization->constraints->initialConstraintValues->numberOfCon)
		osolerror(NULL, osoption, parserData, "too many initial constraint values");
}
    break;

  case 621:

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

  case 622:

    {	if (parserData->valAttributePresent)
		osolerror (NULL, osoption, parserData, "only one constraint value allowed");
	parserData->valAttributePresent = true;
	osoption->optimization->constraints->initialConstraintValues->con[parserData->numberOfCon]->value = strtod((yyvsp[(2) - (2)].sval), NULL);
}
    break;

  case 628:

    {	if ((yyvsp[(3) - (4)].ival) <= 0) osolerror (NULL, osoption, parserData, "number of <con> elements must be positive");
	osoption->optimization->constraints->initialDualValues = new InitDualVariableValues();
	osoption->optimization->constraints->initialDualValues->numberOfCon = (yyvsp[(3) - (4)].ival);
	osoption->optimization->constraints->initialDualValues->con = new InitDualVarValue*[(yyvsp[(3) - (4)].ival)];
	for (int i = 0; i < (yyvsp[(3) - (4)].ival); i++)
		osoption->optimization->constraints->initialDualValues->con[i] = new InitDualVarValue ();
}
    break;

  case 631:

    {	if (!parserData->idxAttributePresent)
		osolerror (NULL, osoption, parserData, "constraint index required");
	parserData->idxAttributePresent = false;
	parserData->lbvalAttributePresent = false;
	parserData->ubvalAttributePresent = false;
	parserData->numberOfDuals++;
}
    break;

  case 632:

    {	if (parserData->numberOfDuals >= osoption->optimization->constraints->initialDualValues->numberOfCon)
		osolerror(NULL, osoption, parserData, "too many initial dual variable bounds");
}
    break;

  case 638:

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

  case 639:

    {	if (parserData->lbvalAttributePresent)
		osolerror (NULL, osoption, parserData, "only one dual variable lower bound allowed");
	parserData->lbvalAttributePresent = true;
	osoption->optimization->constraints->initialDualValues->con[parserData->numberOfDuals]->lbValue = strtod((yyvsp[(2) - (2)].sval), NULL);
}
    break;

  case 641:

    {	if (parserData->ubvalAttributePresent)
		osolerror (NULL, osoption, parserData, "only one dual variable upper bound allowed");
	parserData->ubvalAttributePresent = true;
	osoption->optimization->constraints->initialDualValues->con[parserData->numberOfDuals]->ubValue = strtod((yyvsp[(2) - (2)].sval), NULL);
}
    break;

  case 648:

    {	if (parserData->numberOfOtherConstraintOptions >= osoption->optimization->constraints->numberOfOtherConstraintOptions)
		osolerror(NULL, osoption, parserData, "too many <other> constraint options");
}
    break;

  case 658:

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

  case 659:

    {	if (parserData->otherOptionNamePresent)
		osolerror (NULL, osoption, parserData, "only one name attribute allowed");
	parserData->otherOptionNamePresent = true;
	osoption->optimization->constraints->other[parserData->numberOfOtherConstraintOptions]->name = (yyvsp[(2) - (2)].sval);
}
    break;

  case 661:

    {	if (parserData->otherOptionValuePresent)
		osolerror (NULL, osoption, parserData, "only one value attribute allowed");
	parserData->otherOptionValuePresent = true;
	osoption->optimization->constraints->other[parserData->numberOfOtherConstraintOptions]->value = (yyvsp[(2) - (2)].sval);
}
    break;

  case 663:

    {	if (parserData->otherOptionSolverPresent)
		osolerror (NULL, osoption, parserData, "only one solver attribute allowed");
	parserData->otherOptionSolverPresent = true;
	osoption->optimization->constraints->other[parserData->numberOfOtherConstraintOptions]->solver = (yyvsp[(2) - (2)].sval);
}
    break;

  case 665:

    {	if (parserData->otherOptionCategoryPresent)
		osolerror (NULL, osoption, parserData, "only one category attribute allowed");
	parserData->otherOptionCategoryPresent = true;
	osoption->optimization->constraints->other[parserData->numberOfOtherConstraintOptions]->category = (yyvsp[(2) - (2)].sval);
}
    break;

  case 667:

    {	if (parserData->otherOptionTypePresent)
		osolerror (NULL, osoption, parserData, "only one type attribute allowed");
	parserData->otherOptionTypePresent = true;
	osoption->optimization->constraints->other[parserData->numberOfOtherConstraintOptions]->type = (yyvsp[(2) - (2)].sval);
}
    break;

  case 669:

    {	if (parserData->otherOptionDescriptionPresent)
		osolerror (NULL, osoption, parserData, "only one description attribute allowed");
	parserData->otherOptionDescriptionPresent = true;
	osoption->optimization->constraints->other[parserData->numberOfOtherConstraintOptions]->description = (yyvsp[(2) - (2)].sval);
}
    break;

  case 671:

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

  case 674:

    {	if (!parserData->idxAttributePresent)
		osolerror(NULL, osoption, parserData, "required idx attribute was not found");
	parserData->idxAttributePresent = false;
	parserData->valAttributePresent = false;
	parserData->lbvalAttributePresent = false;
	parserData->ubvalAttributePresent = false;
	parserData->numberOfCon++;
}
    break;

  case 675:

    {	if (parserData->numberOfVar >= osoption->optimization->variables->other[parserData->numberOfOtherVariableOptions]->numberOfVar)
		osolerror(NULL, osoption, parserData, "too many <var> entries in <other> variable element");
}
    break;

  case 682:

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

  case 683:

    {	if (parserData->valAttributePresent)
		osolerror (NULL, osoption, parserData, "only one constraint value allowed");
	parserData->valAttributePresent = true;
	osoption->optimization->constraints-> other[parserData->numberOfOtherConstraintOptions]->con[parserData->numberOfCon]->value = (yyvsp[(2) - (2)].sval);
}
    break;

  case 685:

    {	if (parserData->lbvalAttributePresent)
		osolerror (NULL, osoption, parserData, "only one lower bound value allowed");
	parserData->lbvalAttributePresent = true;
	osoption->optimization->constraints-> other[parserData->numberOfOtherConstraintOptions]->con[parserData->numberOfCon]->lbValue = (yyvsp[(2) - (2)].sval);
}
    break;

  case 687:

    {	if (parserData->ubvalAttributePresent)
		osolerror (NULL, osoption, parserData, "only one upper bound value allowed");
	parserData->ubvalAttributePresent = true;
	osoption->optimization->constraints-> other[parserData->numberOfOtherConstraintOptions]->con[parserData->numberOfCon]->ubValue = (yyvsp[(2) - (2)].sval);
}
    break;

  case 692:

    {	if (parserData->numberOfSolverOptions != osoption->optimization->solverOptions->numberOfSolverOptions)
		osolerror (NULL, osoption, parserData, "wrong number of solver options in <optimization> element");
}
    break;

  case 693:

    {	if (parserData->solverOptionsPresent)
	{	osolerror( NULL, osoption, parserData, "only one <solverOptions> element allowed");
	}
	else
	{	parserData->solverOptionsPresent = true;
		osoption->optimization->solverOptions = new SolverOptions();
	}
}
    break;

  case 694:

    {	if ((yyvsp[(3) - (4)].ival) < 0) osolerror (NULL, osoption, parserData, "number of solver options cannot be negative");
	osoption->optimization->solverOptions->numberOfSolverOptions = (yyvsp[(3) - (4)].ival);
	osoption->optimization->solverOptions->solverOption = new SolverOption*[(yyvsp[(3) - (4)].ival)];
	for (int i=0; i < (yyvsp[(3) - (4)].ival); i++) osoption->optimization->solverOptions->solverOption[i] = new SolverOption();
}
    break;

  case 697:

    {	if (parserData->numberOfSolverOptions >= osoption->optimization->solverOptions->numberOfSolverOptions)
	{	osolerror (NULL, osoption, parserData, "too many solver options in <optimization> element");
	};
}
    break;

  case 698:

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

  case 707:

    {	if (parserData->solverOptionNamePresent)
	{	osolerror( NULL, osoption, parserData, "only one name attribute allowed");
	}
	else
	{	parserData->solverOptionNamePresent = true;
		osoption->optimization->solverOptions->solverOption[parserData->numberOfSolverOptions]->name = (yyvsp[(2) - (2)].sval);
	}
}
    break;

  case 709:

    {	if (parserData->solverOptionValuePresent)
	{	osolerror( NULL, osoption, parserData, "only one value attribute allowed");
	}
	else
	{	parserData->solverOptionValuePresent = true;
		osoption->optimization->solverOptions->solverOption[parserData->numberOfSolverOptions]->value = (yyvsp[(2) - (2)].sval);
	}
}
    break;

  case 711:

    {	if (parserData->solverOptionSolverPresent)
	{	osolerror( NULL, osoption, parserData, "only one solver attribute allowed");
	}
	else
	{	parserData->solverOptionSolverPresent = true;
		osoption->optimization->solverOptions->solverOption[parserData->numberOfSolverOptions]->solver = (yyvsp[(2) - (2)].sval);
	}
}
    break;

  case 713:

    {	if (parserData->solverOptionCategoryPresent)
	{	osolerror( NULL, osoption, parserData, "only one category attribute allowed");
	}
	else
	{	parserData->solverOptionCategoryPresent = true;
		osoption->optimization->solverOptions->solverOption[parserData->numberOfSolverOptions]->category = (yyvsp[(2) - (2)].sval);
	}
}
    break;

  case 715:

    {	if (parserData->solverOptionTypePresent)
	{	osolerror( NULL, osoption, parserData, "only one type attribute allowed");
	}
	else
	{	parserData->solverOptionTypePresent = true;
		osoption->optimization->solverOptions->solverOption[parserData->numberOfSolverOptions]->type = (yyvsp[(2) - (2)].sval);
	}
}
    break;

  case 717:

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


