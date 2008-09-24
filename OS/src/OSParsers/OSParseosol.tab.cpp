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
     OBJECTIVESSTART = 382,
     OBJECTIVESEND = 383,
     INITIALOBJECTIVEVALUESSTART = 384,
     INITIALOBJECTIVEVALUESEND = 385,
     OBJSTART = 386,
     OBJEND = 387,
     INITIALOBJECTIVEBOUNDSSTART = 388,
     INITIALOBJECTIVEBOUNDSEND = 389,
     CONSTRAINTSSTART = 390,
     CONSTRAINTSEND = 391,
     INITIALCONSTRAINTVALUESSTART = 392,
     INITIALCONSTRAINTVALUESEND = 393,
     CONSTART = 394,
     CONEND = 395,
     INITIALDUALVALUESSTART = 396,
     INITIALDUALVALUESEND = 397,
     SOLVEROPTIONSSTART = 398,
     SOLVEROPTIONSEND = 399,
     SOLVEROPTIONSTART = 400,
     SOLVEROPTIONEND = 401,
     DUMMY = 402
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
#define OBJECTIVESSTART 382
#define OBJECTIVESEND 383
#define INITIALOBJECTIVEVALUESSTART 384
#define INITIALOBJECTIVEVALUESEND 385
#define OBJSTART 386
#define OBJEND 387
#define INITIALOBJECTIVEBOUNDSSTART 388
#define INITIALOBJECTIVEBOUNDSEND 389
#define CONSTRAINTSSTART 390
#define CONSTRAINTSEND 391
#define INITIALCONSTRAINTVALUESSTART 392
#define INITIALCONSTRAINTVALUESEND 393
#define CONSTART 394
#define CONEND 395
#define INITIALDUALVALUESSTART 396
#define INITIALDUALVALUESEND 397
#define SOLVEROPTIONSSTART 398
#define SOLVEROPTIONSEND 399
#define SOLVEROPTIONSTART 400
#define SOLVEROPTIONEND 401
#define DUMMY 402




/* Copy the first part of user declarations.  */



 
  

#include "OSErrorClass.h"
#include "OSOption.h"
#include "OSoLParserData.h"
#include <iostream>
#include <sstream> 


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
#define YYLAST   653

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  148
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  357
/* YYNRULES -- Number of rules.  */
#define YYNRULES  575
/* YYNRULES -- Number of states.  */
#define YYNSTATES  996

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   402

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
     145,   146,   147
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
     442,   447,   448,   451,   455,   456,   461,   462,   467,   468,
     473,   475,   478,   479,   482,   484,   488,   490,   491,   494,
     496,   498,   500,   502,   504,   506,   509,   510,   515,   520,
     522,   527,   530,   531,   534,   535,   540,   541,   544,   548,
     549,   554,   555,   556,   561,   562,   563,   568,   570,   573,
     574,   579,   582,   583,   586,   588,   590,   592,   594,   596,
     598,   600,   602,   604,   606,   608,   610,   612,   614,   616,
     622,   623,   627,   629,   631,   634,   638,   643,   648,   652,
     653,   656,   661,   666,   670,   671,   674,   679,   685,   689,
     690,   693,   698,   704,   708,   709,   712,   717,   723,   727,
     728,   731,   736,   742,   746,   747,   750,   754,   755,   758,
     760,   762,   764,   768,   772,   776,   779,   781,   787,   791,
     792,   795,   799,   800,   803,   805,   807,   809,   813,   817,
     821,   824,   826,   832,   836,   837,   840,   844,   845,   848,
     850,   852,   854,   858,   862,   866,   869,   871,   877,   881,
     882,   885,   889,   890,   893,   895,   897,   899,   903,   907,
     911,   914,   916,   922,   926,   927,   930,   935,   941,   945,
     946,   949,   954,   960,   964,   965,   968,   973,   979,   983,
     984,   987,   991,   992,   995,   999,  1003,  1004,  1008,  1009,
    1013,  1015,  1018,  1019,  1023,  1024,  1027,  1029,  1031,  1033,
    1037,  1041,  1045,  1049,  1051,  1056,  1057,  1061,  1062,  1066,
    1071,  1073,  1074,  1082,  1083,  1086,  1090,  1091,  1094,  1096,
    1098,  1102,  1106,  1109,  1111,  1112,  1116,  1117,  1120,  1122,
    1124,  1126,  1128,  1130,  1132,  1134,  1138,  1142,  1146,  1150,
    1154,  1158,  1162,  1166,  1170,  1171,  1174,  1176,  1178,  1180,
    1182,  1186,  1190,  1194,  1198,  1201,  1203,  1204,  1208,  1209,
    1213,  1219,  1221,  1222,  1230,  1231,  1234,  1238,  1239,  1242,
    1244,  1246,  1250,  1254,  1257,  1259,  1260,  1268,  1269,  1272,
    1276,  1277,  1280,  1282,  1284,  1288,  1292,  1295,  1297,  1298,
    1302,  1303,  1306,  1308,  1310,  1312,  1314,  1316,  1318,  1320,
    1324,  1328,  1332,  1336,  1340,  1344,  1348,  1352,  1356,  1357,
    1360,  1362,  1364,  1366,  1368,  1372,  1376,  1380,  1384,  1387,
    1389,  1390,  1394,  1395,  1399,  1405,  1407,  1408,  1416,  1417,
    1420,  1424,  1425,  1428,  1430,  1432,  1436,  1440,  1443,  1445,
    1446,  1454,  1455,  1458,  1462,  1463,  1466,  1468,  1470,  1474,
    1478,  1481,  1483,  1484,  1488,  1489,  1492,  1494,  1496,  1498,
    1500,  1502,  1504,  1506,  1510,  1514,  1518,  1522,  1526,  1530,
    1534,  1538,  1542,  1543,  1546,  1548,  1550,  1552,  1554,  1558,
    1562,  1566,  1570,  1573,  1575,  1576,  1582,  1586,  1587,  1590,
    1594,  1595,  1598,  1600,  1602,  1604,  1606,  1608,  1610,  1614,
    1618,  1622,  1626,  1630,  1634,  1637
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     149,     0,    -1,   150,     8,   151,    12,    -1,   150,     9,
      -1,    10,    -1,    10,    11,    -1,   152,   217,   263,   288,
     378,    -1,    -1,   153,   154,    -1,    43,    -1,     8,   155,
      44,    -1,     9,    -1,    -1,   155,   156,    -1,   157,    -1,
     161,    -1,   165,    -1,   169,    -1,   175,    -1,   179,    -1,
     183,    -1,   187,    -1,   191,    -1,   195,    -1,   201,    -1,
     158,   159,    -1,    53,    -1,     9,    -1,     8,    54,    -1,
      -1,     8,     4,   160,    54,    -1,   162,   163,    -1,    55,
      -1,     9,    -1,     8,    56,    -1,    -1,     8,     4,   164,
      56,    -1,   166,   167,    -1,    57,    -1,     9,    -1,     8,
      58,    -1,    -1,     8,     4,   168,    58,    -1,   170,   171,
     173,    -1,    59,    -1,    -1,    -1,    13,     3,   172,     7,
      -1,     9,    -1,     8,   174,    60,    -1,    -1,     4,    -1,
     176,   177,    -1,    61,    -1,     9,    -1,     8,    62,    -1,
      -1,     8,     4,   178,    62,    -1,   180,   181,    -1,    63,
      -1,     9,    -1,     8,    64,    -1,    -1,     8,     4,   182,
      64,    -1,   184,   185,    -1,    65,    -1,     9,    -1,     8,
      66,    -1,    -1,     8,     4,   186,    66,    -1,   188,   189,
      -1,    67,    -1,     9,    -1,     8,    68,    -1,    -1,     8,
       4,   190,    68,    -1,   192,   193,    -1,    69,    -1,     9,
      -1,     8,    70,    -1,    -1,     8,     4,   194,    70,    -1,
     196,   197,   199,    -1,    71,    -1,    -1,    -1,    14,     3,
     198,     7,    -1,     9,    -1,     8,   200,    72,    -1,    -1,
       4,    -1,   202,   203,     8,   204,    -1,    73,    -1,    15,
       7,     5,     7,    -1,   205,    74,    -1,    -1,   205,   206,
      -1,    -1,    75,   207,   208,   216,    -1,    -1,   208,   209,
      -1,   210,    -1,   212,    -1,   214,    -1,    -1,    36,     3,
     211,     7,    -1,    -1,    38,     3,   213,     7,    -1,    -1,
      40,     3,   215,     7,    -1,     9,    -1,     8,    76,    -1,
      -1,   218,   219,    -1,    45,    -1,     8,   220,    46,    -1,
       9,    -1,    -1,   220,   221,    -1,   222,    -1,   229,    -1,
     236,    -1,   243,    -1,   247,    -1,   223,   224,   226,    -1,
      77,    -1,    -1,    -1,    39,     3,   225,     7,    -1,     9,
      -1,     8,    78,    -1,    -1,     8,     6,   227,    78,    -1,
      -1,     8,     5,   228,    78,    -1,   230,   231,   233,    -1,
      79,    -1,    -1,    -1,    39,     3,   232,     7,    -1,     9,
      -1,     8,    80,    -1,    -1,     8,     6,   234,    80,    -1,
      -1,     8,     5,   235,    80,    -1,   237,   238,   240,    -1,
      81,    -1,    -1,    -1,    39,     3,   239,     7,    -1,     9,
      -1,     8,    82,    -1,    -1,     8,     6,   241,    82,    -1,
      -1,     8,     5,   242,    82,    -1,   244,   245,    -1,    83,
      -1,     9,    -1,     8,    84,    -1,    -1,     8,     5,   246,
      84,    -1,   248,   249,     8,   250,    -1,    73,    -1,    15,
       7,     5,     7,    -1,   251,    74,    -1,    -1,   251,   252,
      -1,    -1,    75,   253,   254,   262,    -1,    -1,   254,   255,
      -1,   256,   258,   260,    -1,    -1,    36,     3,   257,     7,
      -1,    -1,    38,     3,   259,     7,    -1,    -1,    40,     3,
     261,     7,    -1,     9,    -1,     8,    76,    -1,    -1,   264,
     265,    -1,    47,    -1,     8,   266,    48,    -1,     9,    -1,
      -1,   266,   267,    -1,   268,    -1,   272,    -1,   269,    -1,
     270,    -1,    85,    -1,     9,    -1,     8,    86,    -1,    -1,
       8,     5,   271,    86,    -1,   273,   274,     8,   275,    -1,
      73,    -1,    15,     7,     5,     7,    -1,   276,    74,    -1,
      -1,   276,   277,    -1,    -1,    75,   278,   279,   287,    -1,
      -1,   279,   280,    -1,   281,   283,   285,    -1,    -1,    36,
       3,   282,     7,    -1,    -1,    -1,    38,     3,   284,     7,
      -1,    -1,    -1,    40,     3,   286,     7,    -1,     9,    -1,
       8,    76,    -1,    -1,    49,     8,   289,    50,    -1,    49,
       9,    -1,    -1,   289,   290,    -1,   291,    -1,   293,    -1,
     296,    -1,   300,    -1,   304,    -1,   308,    -1,   312,    -1,
     316,    -1,   326,    -1,   336,    -1,   346,    -1,   356,    -1,
     360,    -1,   364,    -1,   368,    -1,    87,   292,     8,     4,
      88,    -1,    -1,    39,     3,     7,    -1,   294,    -1,   295,
      -1,    89,     9,    -1,    89,     8,    90,    -1,    89,     8,
       4,    90,    -1,    91,   297,   298,    92,    -1,    16,     3,
       7,    -1,    -1,   298,   299,    -1,    61,     8,     4,    62,
      -1,    93,   301,   302,    94,    -1,    17,     3,     7,    -1,
      -1,   302,   303,    -1,    97,     8,     4,    98,    -1,    95,
     305,     8,   306,    96,    -1,    17,     3,     7,    -1,    -1,
     306,   307,    -1,    97,     8,     4,    98,    -1,   101,   309,
       8,   310,   102,    -1,    17,     3,     7,    -1,    -1,   310,
     311,    -1,    97,     8,     4,    98,    -1,   103,   313,     8,
     314,   104,    -1,    17,     3,     7,    -1,    -1,   314,   315,
      -1,    97,     8,     4,    98,    -1,   109,   317,     8,   318,
     110,    -1,    18,     3,     7,    -1,    -1,   318,   319,    -1,
      99,   320,   325,    -1,    -1,   320,   321,    -1,   322,    -1,
     323,    -1,   324,    -1,    19,     3,     7,    -1,    20,     3,
       7,    -1,    21,     3,     7,    -1,     8,   100,    -1,     9,
      -1,   111,   327,     8,   328,   112,    -1,    18,     3,     7,
      -1,    -1,   328,   329,    -1,    99,   330,   335,    -1,    -1,
     330,   331,    -1,   332,    -1,   333,    -1,   334,    -1,    19,
       3,     7,    -1,    20,     3,     7,    -1,    21,     3,     7,
      -1,     8,   100,    -1,     9,    -1,   113,   337,     8,   338,
     114,    -1,    18,     3,     7,    -1,    -1,   338,   339,    -1,
      99,   340,   345,    -1,    -1,   340,   341,    -1,   342,    -1,
     343,    -1,   344,    -1,    19,     3,     7,    -1,    20,     3,
       7,    -1,    21,     3,     7,    -1,     8,   100,    -1,     9,
      -1,   115,   347,     8,   348,   116,    -1,    18,     3,     7,
      -1,    -1,   348,   349,    -1,    99,   350,   355,    -1,    -1,
     350,   351,    -1,   352,    -1,   353,    -1,   354,    -1,    19,
       3,     7,    -1,    20,     3,     7,    -1,    21,     3,     7,
      -1,     8,   100,    -1,     9,    -1,   107,   357,     8,   358,
     108,    -1,    17,     3,     7,    -1,    -1,   358,   359,    -1,
      97,     8,     4,    98,    -1,   105,   361,     8,   362,   106,
      -1,    17,     3,     7,    -1,    -1,   362,   363,    -1,    97,
       8,     4,    98,    -1,   117,   365,     8,   366,   118,    -1,
      25,     3,     7,    -1,    -1,   366,   367,    -1,   119,     8,
       4,   120,    -1,    73,   369,     8,   370,    74,    -1,    15,
       3,     7,    -1,    -1,   370,   371,    -1,    75,   372,   377,
      -1,    -1,   372,   373,    -1,   374,   375,   376,    -1,    36,
       3,     7,    -1,    -1,    38,     3,     7,    -1,    -1,    40,
       3,     7,    -1,     9,    -1,     8,    76,    -1,    -1,    51,
     379,   384,    -1,    -1,   379,   380,    -1,   381,    -1,   382,
      -1,   383,    -1,    27,     3,     7,    -1,    29,     3,     7,
      -1,    28,     3,     7,    -1,     8,   385,    52,    -1,     9,
      -1,   386,   416,   454,   492,    -1,    -1,   121,   387,   388,
      -1,    -1,    30,     3,     7,    -1,     8,   389,   397,   122,
      -1,     9,    -1,    -1,   123,    33,     3,     7,     8,   390,
     124,    -1,    -1,   390,   391,    -1,   125,   392,   396,    -1,
      -1,   392,   393,    -1,   394,    -1,   395,    -1,    37,     3,
       7,    -1,    38,     3,     7,    -1,     8,   126,    -1,     9,
      -1,    -1,    75,   398,   407,    -1,    -1,   398,   399,    -1,
     400,    -1,   401,    -1,   402,    -1,   403,    -1,   404,    -1,
     405,    -1,   406,    -1,    33,     3,     7,    -1,    36,     3,
       7,    -1,    38,     3,     7,    -1,    22,     3,     7,    -1,
      23,     3,     7,    -1,    24,     3,     7,    -1,    40,     3,
       7,    -1,     8,   408,    76,    -1,   125,   409,   415,    -1,
      -1,   409,   410,    -1,   411,    -1,   412,    -1,   413,    -1,
     414,    -1,    37,     3,     7,    -1,    38,     3,     7,    -1,
      41,     3,     7,    -1,    42,     3,     7,    -1,     8,   126,
      -1,     9,    -1,    -1,   127,   417,   418,    -1,    -1,    31,
       3,     7,    -1,     8,   419,   427,   435,   128,    -1,     9,
      -1,    -1,   129,    34,     3,     7,     8,   420,   130,    -1,
      -1,   420,   421,    -1,   131,   422,   426,    -1,    -1,   422,
     423,    -1,   424,    -1,   425,    -1,    37,     3,     7,    -1,
      38,     3,     7,    -1,     8,   132,    -1,     9,    -1,    -1,
     133,    34,     3,     7,     8,   428,   134,    -1,    -1,   428,
     429,    -1,   131,   430,   434,    -1,    -1,   430,   431,    -1,
     432,    -1,   433,    -1,    37,     3,     7,    -1,    38,     3,
       7,    -1,     8,   132,    -1,     9,    -1,    -1,    75,   436,
     445,    -1,    -1,   436,   437,    -1,   438,    -1,   439,    -1,
     440,    -1,   441,    -1,   442,    -1,   443,    -1,   444,    -1,
      34,     3,     7,    -1,    36,     3,     7,    -1,    38,     3,
       7,    -1,    22,     3,     7,    -1,    23,     3,     7,    -1,
      24,     3,     7,    -1,    40,     3,     7,    -1,     8,   446,
      76,    -1,   131,   447,   453,    -1,    -1,   447,   448,    -1,
     449,    -1,   450,    -1,   451,    -1,   452,    -1,    37,     3,
       7,    -1,    38,     3,     7,    -1,    41,     3,     7,    -1,
      42,     3,     7,    -1,     8,   126,    -1,     9,    -1,    -1,
     135,   455,   456,    -1,    -1,    32,     3,     7,    -1,     8,
     457,   465,   473,   136,    -1,     9,    -1,    -1,   137,    35,
       3,     7,     8,   458,   138,    -1,    -1,   458,   459,    -1,
     139,   460,   464,    -1,    -1,   460,   461,    -1,   462,    -1,
     463,    -1,    37,     3,     7,    -1,    38,     3,     7,    -1,
       8,   140,    -1,     9,    -1,    -1,   141,    35,     3,     7,
       8,   466,   142,    -1,    -1,   466,   467,    -1,   139,   468,
     472,    -1,    -1,   468,   469,    -1,   470,    -1,   471,    -1,
      37,     3,     7,    -1,    38,     3,     7,    -1,     8,   140,
      -1,     9,    -1,    -1,    75,   474,   483,    -1,    -1,   474,
     475,    -1,   476,    -1,   477,    -1,   478,    -1,   479,    -1,
     480,    -1,   481,    -1,   482,    -1,    35,     3,     7,    -1,
      36,     3,     7,    -1,    38,     3,     7,    -1,    22,     3,
       7,    -1,    23,     3,     7,    -1,    24,     3,     7,    -1,
      40,     3,     7,    -1,     8,   484,    76,    -1,   139,   485,
     491,    -1,    -1,   485,   486,    -1,   487,    -1,   488,    -1,
     489,    -1,   490,    -1,    37,     3,     7,    -1,    38,     3,
       7,    -1,    41,     3,     7,    -1,    42,     3,     7,    -1,
       8,   140,    -1,     9,    -1,    -1,   143,   493,     8,   494,
     144,    -1,    26,     3,     7,    -1,    -1,   494,   495,    -1,
     145,   496,   504,    -1,    -1,   496,   497,    -1,   498,    -1,
     499,    -1,   500,    -1,   501,    -1,   502,    -1,   503,    -1,
      36,     3,     7,    -1,    38,     3,     7,    -1,    22,     3,
       7,    -1,    23,     3,     7,    -1,    24,     3,     7,    -1,
      40,     3,     7,    -1,     8,   146,    -1,     9,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   124,   124,   125,   127,   128,   130,   132,   132,   134,
     145,   146,   148,   148,   150,   150,   150,   150,   150,   151,
     151,   151,   151,   151,   151,   154,   156,   165,   166,   167,
     167,   170,   172,   181,   182,   183,   183,   186,   188,   197,
     198,   199,   199,   202,   204,   214,   214,   214,   216,   217,
     219,   219,   222,   224,   233,   234,   235,   235,   238,   240,
     249,   250,   251,   251,   254,   256,   265,   266,   267,   267,
     270,   272,   281,   282,   283,   283,   286,   288,   297,   298,
     299,   299,   302,   304,   314,   314,   314,   316,   317,   319,
     319,   322,   324,   335,   341,   346,   346,   349,   348,   364,
     364,   366,   366,   366,   369,   368,   380,   379,   391,   390,
     401,   401,   404,   404,   406,   417,   418,   420,   420,   422,
     422,   422,   422,   422,   424,   426,   436,   436,   436,   438,
     439,   440,   440,   441,   441,   444,   446,   456,   456,   456,
     458,   459,   460,   460,   461,   461,   464,   466,   476,   476,
     476,   478,   479,   480,   480,   481,   481,   484,   486,   495,
     496,   497,   497,   500,   502,   513,   519,   524,   524,   527,
     526,   541,   541,   543,   546,   545,   557,   556,   569,   568,
     579,   579,   582,   582,   584,   595,   596,   598,   598,   600,
     600,   602,   602,   604,   613,   614,   615,   615,   617,   619,
     630,   636,   641,   641,   644,   643,   658,   658,   660,   663,
     662,   673,   674,   673,   684,   685,   684,   695,   695,   698,
     699,   700,   702,   702,   704,   704,   704,   704,   704,   705,
     705,   705,   705,   705,   706,   706,   706,   706,   706,   708,
     712,   712,   716,   716,   718,   719,   723,   727,   729,   733,
     733,   736,   740,   743,   747,   747,   749,   753,   756,   760,
     760,   762,   766,   769,   773,   773,   775,   779,   782,   786,
     786,   788,   792,   795,   799,   799,   801,   805,   805,   807,
     807,   807,   809,   813,   817,   821,   821,   824,   827,   831,
     831,   833,   837,   837,   839,   839,   839,   841,   845,   849,
     853,   853,   856,   859,   863,   863,   865,   869,   869,   871,
     871,   871,   873,   877,   881,   885,   885,   888,   891,   895,
     895,   897,   901,   901,   903,   903,   903,   905,   909,   913,
     917,   917,   921,   924,   928,   928,   930,   934,   937,   941,
     941,   943,   948,   951,   955,   955,   957,   962,   964,   968,
     968,   970,   972,   972,   974,   976,   980,   980,   984,   984,
     988,   988,   993,   993,   995,   995,   997,   997,   997,   999,
    1003,  1007,  1011,  1011,  1013,  1015,  1015,  1017,  1017,  1021,
    1022,  1024,  1024,  1027,  1027,  1029,  1031,  1031,  1033,  1033,
    1035,  1039,  1043,  1043,  1046,  1046,  1048,  1048,  1051,  1052,
    1053,  1054,  1055,  1056,  1057,  1059,  1063,  1067,  1071,  1075,
    1079,  1083,  1088,  1090,  1092,  1092,  1095,  1096,  1097,  1098,
    1100,  1104,  1108,  1112,  1116,  1116,  1118,  1118,  1120,  1120,
    1124,  1126,  1129,  1129,  1132,  1132,  1134,  1136,  1136,  1138,
    1138,  1140,  1144,  1148,  1148,  1151,  1151,  1154,  1154,  1156,
    1158,  1158,  1160,  1160,  1162,  1166,  1170,  1170,  1173,  1173,
    1175,  1175,  1178,  1179,  1180,  1181,  1182,  1183,  1184,  1186,
    1190,  1194,  1198,  1202,  1206,  1210,  1215,  1217,  1219,  1219,
    1222,  1223,  1224,  1225,  1227,  1231,  1235,  1239,  1243,  1243,
    1245,  1245,  1247,  1247,  1251,  1253,  1255,  1255,  1258,  1258,
    1260,  1262,  1262,  1264,  1264,  1266,  1270,  1274,  1274,  1277,
    1277,  1280,  1280,  1282,  1284,  1284,  1286,  1286,  1288,  1292,
    1296,  1296,  1299,  1299,  1301,  1301,  1304,  1305,  1306,  1307,
    1308,  1309,  1310,  1312,  1316,  1320,  1324,  1328,  1332,  1336,
    1341,  1343,  1345,  1345,  1348,  1349,  1350,  1351,  1353,  1357,
    1361,  1365,  1369,  1369,  1372,  1372,  1374,  1378,  1378,  1380,
    1382,  1382,  1385,  1386,  1387,  1388,  1389,  1390,  1392,  1396,
    1400,  1404,  1408,  1412,  1417,  1417
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
  "VAREND", "OBJECTIVESSTART", "OBJECTIVESEND",
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
  "@28", "othersystemoptionsend", "osolservice", "servicehead",
  "servicebody", "servicecontent", "serviceoption", "servicetype",
  "servicetypehead", "servicetypebody", "@29", "otherserviceoptions",
  "otherserviceoptionshead", "numberofotherserviceoptions",
  "otherserviceoptionsbody", "otherserviceoptionslist",
  "otherserviceoption", "@30", "otherserviceattributes",
  "otherserviceattribute", "serviceoptionnameatt", "@31",
  "serviceoptionvalueatt", "@32", "serviceoptiondescriptionatt", "@33",
  "otherserviceoptionsend", "osoljob", "jobcontent", "joboption",
  "maxtime", "maxtimeunit", "scheduledstarttime", "emptystarttime",
  "nonemptystarttime", "dependencies", "numberofjobidsatt",
  "dependencieslist", "dependencyjobid", "requireddirectories",
  "numberofreqdirpathsatt", "reqdirpathlist", "reqdirpath",
  "requiredfiles", "numberofreqfilpathsatt", "reqfilpathlist",
  "reqfilpath", "directoriestomake", "numberofdirtomakepathsatt",
  "dirtomakepathlist", "dirtomakepath", "filestocreate",
  "numberoffilestomakepathsatt", "filestomakepathlist", "filestomakepath",
  "inputdirectoriestomove", "numberofindirtomovepathpairsatt",
  "indirtomovepathpairlist", "indirtomovepathpair",
  "indirtomovepathpairattlist", "indirtomovepathpairatt",
  "indirtomovefromatt", "indirtomovetoatt", "indirtomovemakecopyatt",
  "indirtomovepathpairend", "inputfilestomove",
  "numberofinfilestomovepathpairsatt", "infilestomovepathpairlist",
  "infilestomovepathpair", "infilestomovepathpairattlist",
  "infilestomovepathpairatt", "infilestomovefromatt", "infilestomovetoatt",
  "infilestomovemakecopyatt", "infilestomovepathpairend",
  "outputdirectoriestomove", "numberofoutdirtomovepathpairsatt",
  "outdirtomovepathpairlist", "outdirtomovepathpair",
  "outdirtomovepathpairattlist", "outdirtomovepathpairatt",
  "outdirtomovefromatt", "outdirtomovetoatt", "outdirtomovemakecopyatt",
  "outdirtomovepathpairend", "outputfilestomove",
  "numberofoutfilestomovepathpairsatt", "outfilestomovepathpairlist",
  "outfilestomovepathpair", "outfilestomovepathpairattlist",
  "outfilestomovepathpairatt", "outfilestomovefromatt",
  "outfilestomovetoatt", "outfilestomovemakecopyatt",
  "outfilestomovepathpairend", "filestodelete",
  "numberoffilestodeletepathsatt", "filestodeletepathlist",
  "filestodeletepath", "directoriestodelete",
  "numberofdirtodeletepathsatt", "dirtodeletepathlist", "dirtodeletepath",
  "processestokill", "numberofprocesstokillatt", "processestokilllist",
  "processtokill", "otherjoboptions", "numberofotherjoboptions",
  "otherjoboptionslist", "otherjoboption", "otherjobattributes",
  "otherjobattribute", "joboptionnameatt", "joboptionvalueatt",
  "joboptiondescriptionatt", "otherjoboptionsend", "osoloptimization",
  "optimizationattlist", "optimizationatt", "optimizationnvar",
  "optimizationncon", "optimizationnobj", "restofoptimization",
  "optimizationcontent", "variables", "numberofothervariablesatt",
  "restofvariables", "initialvariablevalues", "varlist", "initvarvalue",
  "initvarvalueattlist", "initvarvalueatt", "initvarvalueidxatt",
  "initvarvaluevalueatt", "initvarvalueend", "othervariableoptions",
  "othervariableoptionsattlist", "othervariableoptionsatt",
  "othervariableoptionnumberofvar", "othervariableoptionname",
  "othervariableoptionvalue", "othervariableoptionsolver",
  "othervariableoptioncategory", "othervariableoptiontype",
  "othervariableoptiondescription", "restofothervariableoptions",
  "othervariableoptionsvarlist", "othervaroptionattlist",
  "othervaroptionatt", "othervaroptionidx", "othervaroptionvalue",
  "othervaroptionlbvalue", "othervaroptionubvalue", "othervaroptionend",
  "objectives", "numberofotherobjectivesatt", "restofobjectives",
  "initialobjectivevalues", "objvaluelist", "initobjvalue",
  "initobjvalueattlist", "initobjvalueatt", "initobjvalueidxatt",
  "initobjvaluevalueatt", "initobjvalueend", "initialobjectivebounds",
  "objboundlist", "initobjbound", "initobjboundattlist", "initobjboundatt",
  "initobjboundidxatt", "initobjboundvalueatt", "initobjboundend",
  "otherobjectiveoptions", "otherobjectiveoptionsattlist",
  "otherobjectiveoptionsatt", "otherobjectiveoptionnumberofvar",
  "otherobjectiveoptionname", "otherobjectiveoptionvalue",
  "otherobjectiveoptionsolver", "otherobjectiveoptioncategory",
  "otherobjectiveoptiontype", "otherobjectiveoptiondescription",
  "restofotherobjectiveoptions", "otherobjectiveoptionsvarlist",
  "otherobjoptionattlist", "otherobjoptionatt", "otherobjoptionidx",
  "otherobjoptionvalue", "otherobjoptionlbvalue", "otherobjoptionubvalue",
  "otherobjoptionend", "constraints", "numberofotherconstraintsatt",
  "restofconstraints", "initialconstraintvalues", "conlist",
  "initconvalue", "initconvalueattlist", "initconvalueatt",
  "initconvalueidxatt", "initconvaluevalueatt", "initconvalueend",
  "initialdualvalues", "duallist", "initdualvalue", "initdualvalueattlist",
  "initdualvalueatt", "initdualvalueidxatt", "initdualvaluevalueatt",
  "initdualvalueend", "otherconstraintoptions",
  "otherconstraintoptionsattlist", "otherconstraintoptionsatt",
  "otherconstraintoptionnumberofvar", "otherconstraintoptionname",
  "otherconstraintoptionvalue", "otherconstraintoptionsolver",
  "otherconstraintoptioncategory", "otherconstraintoptiontype",
  "otherconstraintoptiondescription", "restofotherconstraintoptions",
  "otherconstraintoptionsvarlist", "otherconoptionattlist",
  "otherconoptionatt", "otherconoptionidx", "otherconoptionvalue",
  "otherconoptionlbvalue", "otherconoptionubvalue", "otherconoptionend",
  "solveroptions", "numberofsolveroptionsatt", "solveroptionlist",
  "solveroption", "solveroptionattlist", "solveroptionatt",
  "solveroptionname", "solveroptionvalue", "solveroptionsolver",
  "solveroptioncategory", "solveroptiontype", "solveroptiondescription",
  "solveroptionend", 0
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
     395,   396,   397,   398,   399,   400,   401,   402
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   148,   149,   149,   150,   150,   151,   152,   152,   153,
     154,   154,   155,   155,   156,   156,   156,   156,   156,   156,
     156,   156,   156,   156,   156,   157,   158,   159,   159,   160,
     159,   161,   162,   163,   163,   164,   163,   165,   166,   167,
     167,   168,   167,   169,   170,   171,   172,   171,   173,   173,
     174,   174,   175,   176,   177,   177,   178,   177,   179,   180,
     181,   181,   182,   181,   183,   184,   185,   185,   186,   185,
     187,   188,   189,   189,   190,   189,   191,   192,   193,   193,
     194,   193,   195,   196,   197,   198,   197,   199,   199,   200,
     200,   201,   202,   203,   204,   205,   205,   207,   206,   208,
     208,   209,   209,   209,   211,   210,   213,   212,   215,   214,
     216,   216,   217,   217,   218,   219,   219,   220,   220,   221,
     221,   221,   221,   221,   222,   223,   224,   225,   224,   226,
     226,   227,   226,   228,   226,   229,   230,   231,   232,   231,
     233,   233,   234,   233,   235,   233,   236,   237,   238,   239,
     238,   240,   240,   241,   240,   242,   240,   243,   244,   245,
     245,   246,   245,   247,   248,   249,   250,   251,   251,   253,
     252,   254,   254,   255,   257,   256,   259,   258,   261,   260,
     262,   262,   263,   263,   264,   265,   265,   266,   266,   267,
     267,   268,   268,   269,   270,   270,   271,   270,   272,   273,
     274,   275,   276,   276,   278,   277,   279,   279,   280,   282,
     281,   283,   284,   283,   285,   286,   285,   287,   287,   288,
     288,   288,   289,   289,   290,   290,   290,   290,   290,   290,
     290,   290,   290,   290,   290,   290,   290,   290,   290,   291,
     292,   292,   293,   293,   294,   294,   295,   296,   297,   298,
     298,   299,   300,   301,   302,   302,   303,   304,   305,   306,
     306,   307,   308,   309,   310,   310,   311,   312,   313,   314,
     314,   315,   316,   317,   318,   318,   319,   320,   320,   321,
     321,   321,   322,   323,   324,   325,   325,   326,   327,   328,
     328,   329,   330,   330,   331,   331,   331,   332,   333,   334,
     335,   335,   336,   337,   338,   338,   339,   340,   340,   341,
     341,   341,   342,   343,   344,   345,   345,   346,   347,   348,
     348,   349,   350,   350,   351,   351,   351,   352,   353,   354,
     355,   355,   356,   357,   358,   358,   359,   360,   361,   362,
     362,   363,   364,   365,   366,   366,   367,   368,   369,   370,
     370,   371,   372,   372,   373,   374,   375,   375,   376,   376,
     377,   377,   378,   378,   379,   379,   380,   380,   380,   381,
     382,   383,   384,   384,   385,   386,   386,   387,   387,   388,
     388,   389,   389,   390,   390,   391,   392,   392,   393,   393,
     394,   395,   396,   396,   397,   397,   398,   398,   399,   399,
     399,   399,   399,   399,   399,   400,   401,   402,   403,   404,
     405,   406,   407,   408,   409,   409,   410,   410,   410,   410,
     411,   412,   413,   414,   415,   415,   416,   416,   417,   417,
     418,   418,   419,   419,   420,   420,   421,   422,   422,   423,
     423,   424,   425,   426,   426,   427,   427,   428,   428,   429,
     430,   430,   431,   431,   432,   433,   434,   434,   435,   435,
     436,   436,   437,   437,   437,   437,   437,   437,   437,   438,
     439,   440,   441,   442,   443,   444,   445,   446,   447,   447,
     448,   448,   448,   448,   449,   450,   451,   452,   453,   453,
     454,   454,   455,   455,   456,   456,   457,   457,   458,   458,
     459,   460,   460,   461,   461,   462,   463,   464,   464,   465,
     465,   466,   466,   467,   468,   468,   469,   469,   470,   471,
     472,   472,   473,   473,   474,   474,   475,   475,   475,   475,
     475,   475,   475,   476,   477,   478,   479,   480,   481,   482,
     483,   484,   485,   485,   486,   486,   486,   486,   487,   488,
     489,   490,   491,   491,   492,   492,   493,   494,   494,   495,
     496,   496,   497,   497,   497,   497,   497,   497,   498,   499,
     500,   501,   502,   503,   504,   504
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
       4,     0,     2,     3,     0,     4,     0,     4,     0,     4,
       1,     2,     0,     2,     1,     3,     1,     0,     2,     1,
       1,     1,     1,     1,     1,     2,     0,     4,     4,     1,
       4,     2,     0,     2,     0,     4,     0,     2,     3,     0,
       4,     0,     0,     4,     0,     0,     4,     1,     2,     0,
       4,     2,     0,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     5,
       0,     3,     1,     1,     2,     3,     4,     4,     3,     0,
       2,     4,     4,     3,     0,     2,     4,     5,     3,     0,
       2,     4,     5,     3,     0,     2,     4,     5,     3,     0,
       2,     4,     5,     3,     0,     2,     3,     0,     2,     1,
       1,     1,     3,     3,     3,     2,     1,     5,     3,     0,
       2,     3,     0,     2,     1,     1,     1,     3,     3,     3,
       2,     1,     5,     3,     0,     2,     3,     0,     2,     1,
       1,     1,     3,     3,     3,     2,     1,     5,     3,     0,
       2,     3,     0,     2,     1,     1,     1,     3,     3,     3,
       2,     1,     5,     3,     0,     2,     4,     5,     3,     0,
       2,     4,     5,     3,     0,     2,     4,     5,     3,     0,
       2,     3,     0,     2,     3,     3,     0,     3,     0,     3,
       1,     2,     0,     3,     0,     2,     1,     1,     1,     3,
       3,     3,     3,     1,     4,     0,     3,     0,     3,     4,
       1,     0,     7,     0,     2,     3,     0,     2,     1,     1,
       3,     3,     2,     1,     0,     3,     0,     2,     1,     1,
       1,     1,     1,     1,     1,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     0,     2,     1,     1,     1,     1,
       3,     3,     3,     3,     2,     1,     0,     3,     0,     3,
       5,     1,     0,     7,     0,     2,     3,     0,     2,     1,
       1,     3,     3,     2,     1,     0,     7,     0,     2,     3,
       0,     2,     1,     1,     3,     3,     2,     1,     0,     3,
       0,     2,     1,     1,     1,     1,     1,     1,     1,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     0,     2,
       1,     1,     1,     1,     3,     3,     3,     3,     2,     1,
       0,     3,     0,     3,     5,     1,     0,     7,     0,     2,
       3,     0,     2,     1,     1,     3,     3,     2,     1,     0,
       7,     0,     2,     3,     0,     2,     1,     1,     3,     3,
       2,     1,     0,     3,     0,     2,     1,     1,     1,     1,
       1,     1,     1,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     0,     2,     1,     1,     1,     1,     3,     3,
       3,     3,     2,     1,     0,     5,     3,     0,     2,     3,
       0,     2,     1,     1,     1,     1,     1,     1,     3,     3,
       3,     3,     3,     3,     2,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       0,     4,     0,     0,     5,     1,     7,     3,     9,     0,
     112,     0,     2,   114,   182,     0,    12,    11,     8,   184,
     219,     0,   117,   116,   113,     0,     0,   362,   187,   186,
     183,     0,    10,    26,    32,    38,    44,    53,    59,    65,
      71,    77,    83,    92,    13,    14,     0,    15,     0,    16,
       0,    17,    45,    18,     0,    19,     0,    20,     0,    21,
       0,    22,     0,    23,    84,    24,     0,   222,   221,   364,
       6,     0,   115,   164,   125,   136,   147,   158,   118,   119,
     126,   120,   137,   121,   148,   122,     0,   123,     0,     0,
      27,    25,     0,    33,    31,     0,    39,    37,     0,     0,
       0,    54,    52,     0,    60,    58,     0,    66,    64,     0,
      72,    70,     0,    78,    76,     0,     0,     0,     0,     0,
       0,     0,   194,   185,   199,   193,   188,   189,   191,   192,
     190,     0,     0,     0,     0,     0,     0,     0,     0,   159,
     157,     0,     0,    29,    28,    35,    34,    41,    40,    46,
      50,    48,    43,    56,    55,    62,    61,    68,    67,    74,
      73,    80,    79,    85,    89,    87,    82,     0,    95,   220,
       0,   240,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   223,   224,   225,   242,   243,
     226,   227,   228,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   375,   373,     0,     0,     0,   365,   366,
     367,   368,   363,   196,   195,     0,     0,   127,     0,   129,
     124,   138,     0,   140,   135,   149,     0,   151,   146,   161,
     160,     0,   167,     0,     0,     0,     0,    51,     0,     0,
       0,     0,     0,     0,     0,    90,     0,     0,    91,     0,
       0,     0,     0,     0,     0,   244,     0,   249,     0,   254,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     377,     0,   426,     0,     0,     0,     0,     0,   202,     0,
     133,   131,   130,     0,   144,   142,   141,     0,   155,   153,
     152,     0,     0,   163,     0,    30,    36,    42,    47,    49,
      57,    63,    69,    75,    81,    86,    88,    93,    94,    97,
      96,     0,   349,     0,     0,     0,   245,     0,     0,     0,
       0,     0,   259,     0,   264,     0,   269,     0,   339,     0,
     334,     0,   274,     0,   289,     0,   304,     0,   319,     0,
     344,     0,     0,   372,   428,   490,   369,   371,   370,   197,
       0,   198,     0,   128,     0,     0,   139,     0,     0,   150,
       0,     0,   162,   165,   166,   169,   168,    99,   348,     0,
     241,     0,   246,   248,     0,   247,   250,   253,   252,     0,
     255,   258,     0,   263,     0,   268,     0,   338,     0,   333,
       0,   273,     0,   288,     0,   303,     0,   318,     0,   343,
       0,     0,   381,   380,   376,     0,     0,   492,   554,   200,
     201,   204,   203,   134,   132,   145,   143,   156,   154,   171,
       0,   347,   352,   350,   239,     0,     0,   257,     0,   260,
       0,   262,   265,     0,   267,   270,     0,   337,   340,     0,
     332,   335,   277,   272,   275,   292,   287,   290,   307,   302,
     305,   322,   317,   320,   342,     0,   345,   378,     0,   394,
       0,   432,   431,   427,     0,     0,     0,   374,   206,     0,
       0,   110,     0,     0,     0,   100,   101,   102,   103,    98,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   396,     0,   429,     0,   445,     0,
     496,   495,   491,     0,     0,     0,     0,   180,     0,   172,
       0,   170,   111,   104,   106,   108,     0,   360,     0,   353,
     356,   351,   251,   256,     0,     0,     0,     0,     0,     0,
     286,     0,     0,     0,   278,   279,   280,   281,   276,     0,
     301,     0,     0,     0,   293,   294,   295,   296,   291,     0,
     316,     0,     0,     0,   308,   309,   310,   311,   306,     0,
     331,     0,     0,     0,   323,   324,   325,   326,   321,     0,
       0,     0,   379,     0,     0,   458,   493,     0,   509,     0,
     557,     0,   217,     0,   207,   211,   205,   181,   174,     0,
       0,     0,     0,     0,   361,     0,     0,   358,   261,   266,
     271,   341,   336,   285,     0,     0,     0,   300,     0,     0,
       0,   315,     0,     0,     0,   330,     0,     0,     0,   346,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   397,
     398,   399,   400,   401,   402,   403,   404,   395,     0,     0,
     460,     0,     0,     0,   522,   556,     0,   218,   209,     0,
     214,     0,   176,     0,   173,   105,   107,   109,   355,     0,
       0,   354,   282,   283,   284,   297,   298,   299,   312,   313,
     314,   327,   328,   329,   383,   414,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   430,     0,     0,
     524,     0,   555,   560,   558,     0,   212,     0,   208,   175,
       0,   178,   357,     0,     0,     0,   412,   408,   409,   410,
     405,   406,   407,   411,   434,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   461,   462,   463,   464,   465,   466,
     467,   468,   459,     0,     0,     0,   494,     0,   210,     0,
     215,   177,     0,   359,   382,   386,   384,     0,   425,     0,
       0,     0,     0,   415,   416,   417,   418,   419,   413,     0,
     447,   478,     0,     0,     0,     0,     0,     0,     0,     0,
     498,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     525,   526,   527,   528,   529,   530,   531,   532,   523,     0,
     575,     0,     0,     0,     0,     0,     0,   561,   562,   563,
     564,   565,   566,   567,   559,   213,     0,   179,     0,   424,
       0,     0,     0,     0,   433,   437,   435,     0,     0,   476,
     472,   473,   474,   469,   470,   471,   475,     0,   511,   542,
       0,     0,     0,     0,     0,     0,     0,     0,   574,     0,
       0,     0,     0,     0,     0,   216,     0,   393,     0,     0,
     387,   388,   389,   385,   420,   421,   422,   423,     0,   450,
     446,   448,     0,   489,     0,     0,     0,     0,   479,   480,
     481,   482,   483,   477,   497,   501,   499,     0,     0,   540,
     536,   537,   538,   533,   534,   535,   539,   570,   571,   572,
     568,   569,   573,   392,     0,     0,     0,   444,     0,     0,
     438,   439,   440,   436,     0,   488,     0,     0,     0,     0,
       0,   514,   510,   512,     0,   553,     0,     0,     0,     0,
     543,   544,   545,   546,   547,   541,   390,   391,   443,     0,
       0,     0,   457,     0,     0,   451,   452,   453,   449,   484,
     485,   486,   487,     0,   508,     0,     0,   502,   503,   504,
     500,     0,   552,     0,     0,     0,     0,   441,   442,   456,
       0,     0,   507,     0,     0,     0,   521,     0,     0,   515,
     516,   517,   513,   548,   549,   550,   551,   454,   455,   505,
     506,   520,     0,     0,   518,   519
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,     9,    10,    11,    18,    25,    44,    45,
      46,    91,   233,    47,    48,    94,   234,    49,    50,    97,
     235,    51,    52,    99,   236,   152,   238,    53,    54,   102,
     239,    55,    56,   105,   240,    57,    58,   108,   241,    59,
      60,   111,   242,    61,    62,   114,   243,    63,    64,   116,
     244,   166,   246,    65,    66,   118,   248,   249,   320,   377,
     430,   485,   486,   601,   487,   602,   488,   603,   489,    14,
      15,    24,    31,    78,    79,    80,   133,   289,   220,   365,
     364,    81,    82,   135,   293,   224,   368,   367,    83,    84,
     137,   297,   228,   371,   370,    85,    86,   140,   301,    87,
      88,   142,   303,   304,   376,   429,   479,   519,   520,   661,
     600,   710,   664,   752,   521,    20,    21,    30,    71,   126,
     127,   128,   129,   286,   130,   131,   216,   361,   362,   422,
     478,   515,   594,   595,   705,   660,   749,   708,   816,   596,
      27,   119,   185,   186,   253,   187,   188,   189,   190,   257,
     328,   386,   191,   259,   330,   390,   192,   261,   392,   439,
     193,   263,   394,   442,   194,   265,   396,   445,   195,   271,
     402,   454,   498,   544,   545,   546,   547,   548,   196,   273,
     404,   457,   499,   554,   555,   556,   557,   558,   197,   275,
     406,   460,   500,   564,   565,   566,   567,   568,   198,   277,
     408,   463,   501,   574,   575,   576,   577,   578,   199,   269,
     400,   451,   200,   267,   398,   448,   201,   279,   410,   466,
     202,   251,   379,   433,   490,   529,   530,   607,   671,   531,
      70,   120,   208,   209,   210,   211,   212,   281,   282,   352,
     414,   469,   714,   756,   818,   860,   861,   862,   863,   505,
     581,   639,   640,   641,   642,   643,   644,   645,   646,   647,
     686,   715,   763,   764,   765,   766,   767,   768,   355,   416,
     473,   508,   769,   826,   868,   910,   911,   912,   913,   585,
     827,   871,   914,   945,   946,   947,   948,   651,   696,   734,
     735,   736,   737,   738,   739,   740,   741,   742,   772,   828,
     878,   879,   880,   881,   882,   883,   418,   475,   512,   588,
     837,   886,   920,   957,   958,   959,   960,   654,   887,   923,
     961,   979,   980,   981,   982,   701,   745,   790,   791,   792,
     793,   794,   795,   796,   797,   798,   840,   888,   930,   931,
     932,   933,   934,   935,   477,   514,   656,   704,   747,   807,
     808,   809,   810,   811,   812,   813,   814
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -91
static const yytype_int16 yypact[] =
{
      53,    32,    23,    85,   -91,   -91,   -18,   -91,   -91,    55,
      20,   179,   -91,   -91,    26,   225,   -91,   -91,   -91,   -91,
      50,   227,   -91,   -91,   -91,   136,   229,    18,   -91,   -91,
     -91,   -42,   -91,   -91,   -91,   -91,   -91,   -91,   -91,   -91,
     -91,   -91,   -91,   -91,   -91,   -91,   231,   -91,   233,   -91,
     235,   -91,    62,   -91,   237,   -91,   239,   -91,   241,   -91,
     243,   -91,   245,   -91,   117,   -91,    97,   -91,   -91,   -91,
     -91,    -1,   -91,   -91,   -91,   -91,   -91,   -91,   -91,   -91,
      75,   -91,   134,   -91,   137,   -91,   247,   -91,   167,    17,
     -91,   -91,    14,   -91,   -91,    16,   -91,   -91,   187,   249,
      15,   -91,   -91,    12,   -91,   -91,    13,   -91,   -91,    10,
     -91,   -91,    11,   -91,   -91,   189,   251,   199,   186,   -49,
      21,    -3,   -91,   -91,   -91,   -91,   -91,   -91,   -91,   -91,
     -91,   181,   209,   253,   212,   255,   215,   257,    -2,   -91,
     -91,   280,   196,   -91,   -91,   -91,   -91,   -91,   -91,   -91,
     204,   -91,   -91,   -91,   -91,   -91,   -91,   -91,   -91,   -91,
     -91,   -91,   -91,   -91,   292,   -91,   -91,   293,   -91,   -91,
     282,   260,   259,   284,   285,   286,   287,   288,   289,   290,
     283,   291,   294,   295,   296,   -91,   -91,   -91,   -91,   -91,
     -91,   -91,   -91,   -91,   -91,   -91,   -91,   -91,   -91,   -91,
     -91,   -91,   -91,   190,   -91,   305,   307,   311,   -91,   -91,
     -91,   -91,   -91,   -91,   -91,   308,   309,   -91,     7,   -91,
     -91,   -91,     0,   -91,   -91,   -91,     5,   -91,   -91,   -91,
     -91,   313,   -91,   262,   263,   264,   316,   -91,   266,   258,
     261,   267,   256,   268,   320,   -91,   269,   321,   -91,   195,
     326,   322,   328,   324,    -4,   -91,   331,   -91,   332,   -91,
     333,   329,   336,   334,   337,   335,   341,   338,   342,   339,
     345,   343,   346,   344,   347,   348,   350,   349,   351,   352,
     325,   306,   232,   354,   355,   356,   278,   360,   -91,   359,
     -91,   -91,   -91,   361,   -91,   -91,   -91,   362,   -91,   -91,
     -91,   297,   363,   -91,   197,   -91,   -91,   -91,   -91,   -91,
     -91,   -91,   -91,   -91,   -91,   -91,   -91,   -91,   -91,   -91,
     -91,   364,   -91,   365,   369,   298,   -91,   367,   -39,   368,
       1,   370,   -91,   371,   -91,   372,   -91,   373,   -91,   375,
     -91,   376,   -91,   377,   -91,   378,   -91,   379,   -91,   380,
     -91,   386,   265,   -91,   366,   270,   -91,   -91,   -91,   -91,
     383,   -91,   201,   -91,   314,   315,   -91,   318,   319,   -91,
     312,   327,   -91,   -91,   -91,   -91,   -91,   -91,   -91,   203,
     -91,   279,   -91,   -91,   387,   -91,   -91,   -91,   -91,   388,
     -91,   -91,   183,   -91,    72,   -91,    64,   -91,    57,   -91,
      -5,   -91,     3,   -91,   -67,   -91,   -63,   -91,   -90,   -91,
     163,   384,   281,   -91,   -91,   397,   275,   374,   271,   -91,
     -91,   -91,   -91,   -91,   -91,   -91,   -91,   -91,   -91,   -91,
      19,   -91,   -91,   -91,   -91,   398,   399,   -91,   393,   -91,
     400,   -91,   -91,   402,   -91,   -91,   403,   -91,   -91,   404,
     -91,   -91,   -91,   -91,   -91,   -91,   -91,   -91,   -91,   -91,
     -91,   -91,   -91,   -91,   -91,   405,   -91,   -91,   382,   301,
     409,   299,   -91,   -91,   414,   277,   381,   -91,   -91,    25,
     353,   -91,   415,   416,   417,   -91,   -91,   -91,   -91,   -91,
      92,   385,   323,   418,   419,   420,   421,   422,   202,   205,
     208,   211,   423,   427,   -91,   310,   -91,   401,   300,   424,
     302,   -91,   -91,   431,   428,   141,   389,   -91,   434,   -91,
     406,   -91,   -91,   -91,   -91,   -91,   390,   -91,   435,   -91,
     407,   -91,   -91,   -91,   357,   358,   391,   392,   394,   340,
     -91,   438,   439,   440,   -91,   -91,   -91,   -91,   -91,   395,
     -91,   443,   445,   446,   -91,   -91,   -91,   -91,   -91,   396,
     -91,   447,   448,   449,   -91,   -91,   -91,   -91,   -91,   408,
     -91,   450,   451,   454,   -91,   -91,   -91,   -91,   -91,   410,
     452,   119,   -91,   455,   426,   411,   -91,   429,   330,   456,
     -91,   412,   -91,   458,   -91,   430,   -91,   -91,   -91,   459,
     432,   460,   462,   463,   -91,   466,   471,   436,   -91,   -91,
     -91,   -91,   -91,   -91,   468,   470,   472,   -91,   473,   474,
     475,   -91,   476,   477,   478,   -91,   480,   484,   486,   -91,
     489,   413,   491,   495,   496,   497,   498,   499,   500,   -91,
     -91,   -91,   -91,   -91,   -91,   -91,   -91,   -91,   502,   501,
     -91,   425,   503,   479,   437,   -91,   144,   -91,   -91,   504,
     465,   506,   -91,   507,   -91,   -91,   -91,   -91,   -91,   508,
     513,   -91,   -91,   -91,   -91,   -91,   -91,   -91,   -91,   -91,
     -91,   -91,   -91,   -91,   -91,   -91,   441,   511,   512,   514,
     515,   516,   517,   518,   519,   521,   124,   -91,   522,   523,
     -91,   433,   -91,   -91,   -91,   524,   -91,   529,   -91,   -91,
     526,   -91,   -91,   527,   166,    80,   -91,   -91,   -91,   -91,
     -91,   -91,   -91,   -91,   -91,   528,   442,   532,   534,   536,
     537,   538,   539,   540,   -91,   -91,   -91,   -91,   -91,   -91,
     -91,   -91,   -91,   541,   543,   143,   -91,   162,   -91,   544,
     -91,   -91,   545,   -91,   -91,   -91,   -91,   444,   -91,   542,
     551,   552,   553,   -91,   -91,   -91,   -91,   -91,   -91,   164,
     -91,   -91,   481,   554,   555,   556,   557,   558,   559,   560,
     -91,   550,   453,   565,   568,   569,   571,   572,   573,   574,
     -91,   -91,   -91,   -91,   -91,   -91,   -91,   -91,   -91,   457,
     -91,   575,   576,   577,   578,   579,   580,   -91,   -91,   -91,
     -91,   -91,   -91,   -91,   -91,   -91,   581,   -91,    96,   -91,
     582,   583,   584,   586,   -91,   -91,   -91,    22,    82,   -91,
     -91,   -91,   -91,   -91,   -91,   -91,   -91,   154,   -91,   -91,
     483,   587,   588,   589,   590,   591,   592,   593,   -91,   594,
     595,   597,   598,   599,   600,   -91,   461,   -91,   605,   606,
     -91,   -91,   -91,   -91,   -91,   -91,   -91,   -91,    98,   -91,
     -91,   -91,   485,   -91,   607,   609,   610,   611,   -91,   -91,
     -91,   -91,   -91,   -91,   -91,   -91,   -91,    33,    88,   -91,
     -91,   -91,   -91,   -91,   -91,   -91,   -91,   -91,   -91,   -91,
     -91,   -91,   -91,   -91,   608,   612,   488,   -91,   613,   614,
     -91,   -91,   -91,   -91,   100,   -91,   615,   616,   617,   618,
     102,   -91,   -91,   -91,   487,   -91,   623,   625,   626,   627,
     -91,   -91,   -91,   -91,   -91,   -91,   -91,   -91,   -91,   624,
     628,   505,   -91,   629,   630,   -91,   -91,   -91,   -91,   -91,
     -91,   -91,   -91,   494,   -91,   633,   635,   -91,   -91,   -91,
     -91,   107,   -91,   632,   634,   636,   637,   -91,   -91,   -91,
     638,   639,   -91,   640,   641,   509,   -91,   647,   648,   -91,
     -91,   -91,   -91,   -91,   -91,   -91,   -91,   -91,   -91,   -91,
     -91,   -91,   645,   646,   -91,   -91
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -91,   -91,   -91,   -91,   -91,   -91,   -91,   -91,   -91,   -91,
     -91,   -91,   -91,   -91,   -91,   -91,   -91,   -91,   -91,   -91,
     -91,   -91,   -91,   -91,   -91,   -91,   -91,   -91,   -91,   -91,
     -91,   -91,   -91,   -91,   -91,   -91,   -91,   -91,   -91,   -91,
     -91,   -91,   -91,   -91,   -91,   -91,   -91,   -91,   -91,   -91,
     -91,   -91,   -91,   -91,   -91,   -91,   -91,   -91,   -91,   -91,
     -91,   -91,   -91,   -91,   -91,   -91,   -91,   -91,   -91,   -91,
     -91,   -91,   -91,   -91,   -91,   -91,   -91,   -91,   -91,   -91,
     -91,   -91,   -91,   -91,   -91,   -91,   -91,   -91,   -91,   -91,
     -91,   -91,   -91,   -91,   -91,   -91,   -91,   -91,   -91,   -91,
     -91,   -91,   -91,   -91,   -91,   -91,   -91,   -91,   -91,   -91,
     -91,   -91,   -91,   -91,   -91,   -91,   -91,   -91,   -91,   -91,
     -91,   -91,   -91,   -91,   -91,   -91,   -91,   -91,   -91,   -91,
     -91,   -91,   -91,   -91,   -91,   -91,   -91,   -91,   -91,   -91,
     -91,   -91,   -91,   -91,   -91,   -91,   -91,   -91,   -91,   -91,
     -91,   -91,   -91,   -91,   -91,   -91,   -91,   -91,   -91,   -91,
     -91,   -91,   -91,   -91,   -91,   -91,   -91,   -91,   -91,   -91,
     -91,   -91,   -91,   -91,   -91,   -91,   -91,   -91,   -91,   -91,
     -91,   -91,   -91,   -91,   -91,   -91,   -91,   -91,   -91,   -91,
     -91,   -91,   -91,   -91,   -91,   -91,   -91,   -91,   -91,   -91,
     -91,   -91,   -91,   -91,   -91,   -91,   -91,   -91,   -91,   -91,
     -91,   -91,   -91,   -91,   -91,   -91,   -91,   -91,   -91,   -91,
     -91,   -91,   -91,   -91,   -91,   -91,   -91,   -91,   -91,   -91,
     -91,   -91,   -91,   -91,   -91,   -91,   -91,   -91,   -91,   -91,
     -91,   -91,   -91,   -91,   -91,   -91,   -91,   -91,   -91,   -91,
     -91,   -91,   -91,   -91,   -91,   -91,   -91,   -91,   -91,   -91,
     -91,   -91,   -91,   -91,   -91,   -91,   -91,   -91,   -91,   -91,
     -91,   -91,   -91,   -91,   -91,   -91,   -91,   -91,   -91,   -91,
     -91,   -91,   -91,   -91,   -91,   -91,   -91,   -91,   -91,   -91,
     -91,   -91,   -91,   -91,   -91,   -91,   -91,   -91,   -91,   -91,
     -91,   -91,   -91,   -91,   -91,   -91,   -91,   -91,   -91,   -91,
     -91,   -91,   -91,   -91,   -91,   -91,   -91,   -91,   -91,   -91,
     -91,   -91,   -91,   -91,   -91,   -91,   -91,   -91,   -91,   -91,
     -91,   -91,   -91,   -91,   -91,   -91,   -91,   -91,   -91,   -91,
     -91,   -91,   -91,   -91,   -91,   -91,   -91,   -91,   -91,   -91,
     -91,   -91,   -91,   -91,   -91,   -91,   -91
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint16 yytable[] =
{
     325,   169,   213,   229,    72,   294,   295,   121,   122,   461,
     298,   299,   290,   291,   159,   161,   155,   157,   145,   153,
     147,   143,   384,     5,   170,     8,   462,   480,   481,   203,
     204,    73,   455,   516,   517,    74,   458,    75,   171,    76,
     172,    77,   173,     4,   174,   456,   175,   123,   205,   206,
     207,   459,   176,   385,   177,   482,   178,   483,   179,   484,
     180,   518,   181,     1,   182,    13,   183,    12,   184,    69,
     146,   144,   124,    19,   148,    98,   156,   154,   160,   158,
     296,   162,   230,   214,   125,   292,   326,   300,   757,   758,
     872,   873,   449,     6,     7,   388,   924,   925,   389,    26,
     526,   527,   452,   450,   856,   857,   906,   907,   941,   942,
     953,   954,   117,   453,   132,   975,   976,   759,   760,   874,
     875,   761,   762,   876,   877,   926,   927,   631,   528,   928,
     929,   115,   726,   858,   859,   908,   909,   943,   944,   955,
     956,   632,   633,   634,   977,   978,   727,   728,   729,   591,
     592,   782,   635,   869,   446,   636,   870,   637,   730,   638,
     731,   443,   732,   447,   733,   783,   784,   785,   444,   440,
     799,   800,   921,   134,   441,   922,   136,   593,   786,   787,
      32,   788,   141,   789,   801,   802,   803,    16,    17,    33,
     149,    34,   163,    35,   168,    36,   215,    37,   804,    38,
     805,    39,   806,    40,   232,    41,   167,    42,   237,    43,
     539,   540,   217,   549,   550,   221,   559,   560,   225,   569,
     570,   541,   542,   543,   551,   552,   553,   561,   562,   563,
     571,   572,   573,    22,    23,    28,    29,    67,    68,    89,
      90,    92,    93,    95,    96,   100,   101,   103,   104,   106,
     107,   109,   110,   112,   113,   138,   139,   150,   151,   164,
     165,   218,   219,   222,   223,   226,   227,   254,   255,   318,
     319,   374,   375,   412,   413,   420,   421,   431,   432,   437,
     438,   464,   465,   471,   472,   510,   511,   231,   702,   703,
     754,   755,   884,   885,   824,   825,   245,   250,   247,   252,
     256,   270,   258,   260,   262,   264,   266,   268,   283,   272,
     284,   280,   274,   276,   285,   287,   305,   288,   302,   306,
     310,   278,   307,   308,   313,   311,   309,   315,   317,   321,
     322,   323,   324,   312,   327,   329,   331,   332,   314,   333,
     335,   316,   334,   336,   337,   339,   338,   340,   341,   343,
     345,   342,   344,   347,   349,   351,   346,   348,   353,   354,
     350,   356,   357,   358,   359,   360,   363,   434,   366,   369,
     373,   378,   380,   381,   383,   387,   504,   391,   393,   395,
     397,   372,   399,   401,   403,   405,   407,   409,   382,   411,
     419,   467,   423,   424,   427,   435,   436,   415,   425,   426,
     470,   493,   491,   492,   468,   417,   474,   513,   494,   428,
     495,   496,   497,   502,   476,   503,   506,   509,   523,   524,
     525,   533,   534,   535,   536,   537,   538,   579,   507,   522,
     580,   586,   582,   584,   589,   583,   590,   598,   605,   587,
     613,   614,   615,   616,   599,   606,   618,   532,   619,   620,
     622,   623,   624,   626,   627,   608,   609,   628,   648,   630,
     649,   658,   662,   655,   652,   597,   604,   665,   659,   666,
     667,   653,   663,   668,   669,   672,   670,   673,     0,   674,
     675,   676,   677,   678,   679,   680,   650,   681,   657,   610,
     611,   682,   612,   683,   687,   617,   621,   684,   688,   689,
     690,   691,   692,   693,   695,   707,   698,   706,   625,   694,
     711,     0,   700,   709,   699,   712,   713,   716,   717,   718,
       0,   719,   720,   721,   722,   723,   744,   724,   725,   743,
     629,   748,   750,   751,   753,   773,   770,   774,   685,   775,
     776,   777,   778,   779,     0,   820,     0,     0,     0,   780,
     781,   815,   817,   697,   821,   822,   823,   829,   838,   889,
       0,   830,   831,   832,   833,   834,   835,   836,   841,   746,
     819,   842,   843,   771,   844,   845,   846,   847,   849,   850,
     851,   852,   853,   854,     0,     0,     0,   903,   855,   864,
     865,   866,   839,   867,   890,   891,   892,   893,   894,   895,
     896,   897,   898,   848,   899,   900,   901,   902,   904,   905,
     916,   915,   917,   918,   919,   936,   939,   940,     0,   937,
     938,     0,   949,   950,   951,   952,   963,   962,   964,   965,
     966,   967,   970,   971,   972,   968,   973,   969,   974,   983,
       0,   984,     0,   985,   986,   987,   988,   989,   990,   991,
     992,   993,   994,   995
};

static const yytype_int16 yycheck[] =
{
       4,    50,     5,     5,    46,     5,     6,     8,     9,    99,
       5,     6,     5,     6,     4,     4,     4,     4,     4,     4,
       4,     4,    61,     0,    73,    43,   116,     8,     9,     8,
       9,    73,    99,     8,     9,    77,    99,    79,    87,    81,
      89,    83,    91,    11,    93,   112,    95,    48,    27,    28,
      29,   114,   101,    92,   103,    36,   105,    38,   107,    40,
     109,    36,   111,    10,   113,    45,   115,    12,   117,    51,
      56,    54,    73,    47,    58,    13,    64,    62,    68,    66,
      80,    70,    84,    86,    85,    78,    90,    82,     8,     9,
       8,     9,    97,     8,     9,    94,     8,     9,    97,    49,
       8,     9,    99,   108,     8,     9,     8,     9,     8,     9,
       8,     9,    15,   110,    39,     8,     9,    37,    38,    37,
      38,    41,    42,    41,    42,    37,    38,     8,    36,    41,
      42,    14,     8,    37,    38,    37,    38,    37,    38,    37,
      38,    22,    23,    24,    37,    38,    22,    23,    24,     8,
       9,     8,    33,   131,    97,    36,   134,    38,    34,    40,
      36,    97,    38,   106,    40,    22,    23,    24,   104,    97,
       8,     9,   139,    39,   102,   142,    39,    36,    35,    36,
      44,    38,    15,    40,    22,    23,    24,     8,     9,    53,
       3,    55,     3,    57,     8,    59,    15,    61,    36,    63,
      38,    65,    40,    67,     8,    69,     7,    71,     4,    73,
       8,     9,     3,     8,     9,     3,     8,     9,     3,     8,
       9,    19,    20,    21,    19,    20,    21,    19,    20,    21,
      19,    20,    21,     8,     9,     8,     9,     8,     9,     8,
       9,     8,     9,     8,     9,     8,     9,     8,     9,     8,
       9,     8,     9,     8,     9,     8,     9,     8,     9,     8,
       9,     8,     9,     8,     9,     8,     9,     8,     9,    74,
      75,    74,    75,     8,     9,    74,    75,    74,    75,    96,
      97,   118,   119,     8,     9,     8,     9,     7,   144,   145,
     124,   125,   138,   139,   130,   131,     4,    15,     5,    39,
      16,    18,    17,    17,    17,    17,    17,    17,     3,    18,
       3,   121,    18,    18,     3,     7,    54,     8,     5,    56,
      62,    25,    58,     7,    68,    64,    60,     7,     7,     3,
       8,     3,     8,    66,     3,     3,     3,     8,    70,     3,
       3,    72,     8,     8,     3,     3,     8,     8,     3,     3,
       3,     8,     8,     3,     3,    30,     8,     8,    52,   127,
       8,     7,     7,     7,    86,     5,     7,    88,     7,     7,
       7,     7,     7,     4,     7,     7,    75,     7,     7,     7,
       7,    84,     7,     7,     7,     7,     7,     7,    90,     3,
       7,     7,    78,    78,    82,     8,     8,    31,    80,    80,
       3,     8,     4,     4,   123,   135,    32,    26,     8,    82,
       8,     8,     8,     8,   143,    33,     7,     3,     3,     3,
       3,    98,     4,     4,     4,     4,     4,     4,   129,    76,
       3,     7,   122,   133,     3,    34,     8,     3,     3,   137,
     100,     3,     3,     3,    38,    38,     3,    62,     3,     3,
       3,     3,     3,     3,     3,    98,    98,     3,     3,     7,
      34,     3,     3,     7,    35,    76,    76,     7,    38,     7,
       7,   141,    40,     7,     3,     7,    40,     7,    -1,     7,
       7,     7,     7,     7,     7,     7,    75,     7,    76,    98,
      98,     7,    98,     7,     3,   100,   100,     8,     3,     3,
       3,     3,     3,     3,     3,    40,     3,     3,   100,     7,
       3,    -1,    75,     7,    35,     7,     3,    76,     7,     7,
      -1,     7,     7,     7,     7,     7,     3,     8,     7,     7,
     120,     7,     3,     7,     7,     3,     8,     3,   125,     3,
       3,     3,     3,     3,    -1,     3,    -1,    -1,    -1,     8,
       7,     7,     7,   128,     3,     3,     3,    76,     8,    76,
      -1,     7,     7,     7,     7,     7,     7,     7,     3,   136,
     126,     3,     3,   131,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,    -1,    -1,    -1,   126,     7,     7,
       7,     7,   139,     7,     7,     7,     7,     7,     7,     7,
       7,     7,     7,   146,     7,     7,     7,     7,     3,     3,
       3,   126,     3,     3,     3,     7,     3,     3,    -1,     7,
     132,    -1,     7,     7,     7,     7,     3,   140,     3,     3,
       3,     7,     3,     3,   140,     7,     3,   132,     3,     7,
      -1,     7,    -1,     7,     7,     7,     7,     7,     7,   140,
       3,     3,     7,     7
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,    10,   149,   150,    11,     0,     8,     9,    43,   151,
     152,   153,    12,    45,   217,   218,     8,     9,   154,    47,
     263,   264,     8,     9,   219,   155,    49,   288,     8,     9,
     265,   220,    44,    53,    55,    57,    59,    61,    63,    65,
      67,    69,    71,    73,   156,   157,   158,   161,   162,   165,
     166,   169,   170,   175,   176,   179,   180,   183,   184,   187,
     188,   191,   192,   195,   196,   201,   202,     8,     9,    51,
     378,   266,    46,    73,    77,    79,    81,    83,   221,   222,
     223,   229,   230,   236,   237,   243,   244,   247,   248,     8,
       9,   159,     8,     9,   163,     8,     9,   167,    13,   171,
       8,     9,   177,     8,     9,   181,     8,     9,   185,     8,
       9,   189,     8,     9,   193,    14,   197,    15,   203,   289,
     379,     8,     9,    48,    73,    85,   267,   268,   269,   270,
     272,   273,    39,   224,    39,   231,    39,   238,     8,     9,
     245,    15,   249,     4,    54,     4,    56,     4,    58,     3,
       8,     9,   173,     4,    62,     4,    64,     4,    66,     4,
      68,     4,    70,     3,     8,     9,   199,     7,     8,    50,
      73,    87,    89,    91,    93,    95,   101,   103,   105,   107,
     109,   111,   113,   115,   117,   290,   291,   293,   294,   295,
     296,   300,   304,   308,   312,   316,   326,   336,   346,   356,
     360,   364,   368,     8,     9,    27,    28,    29,   380,   381,
     382,   383,   384,     5,    86,    15,   274,     3,     8,     9,
     226,     3,     8,     9,   233,     3,     8,     9,   240,     5,
      84,     7,     8,   160,   164,   168,   172,     4,   174,   178,
     182,   186,   190,   194,   198,     4,   200,     5,   204,   205,
      15,   369,    39,   292,     8,     9,    16,   297,    17,   301,
      17,   305,    17,   309,    17,   313,    17,   361,    17,   357,
      18,   317,    18,   327,    18,   337,    18,   347,    25,   365,
     121,   385,   386,     3,     3,     3,   271,     7,     8,   225,
       5,     6,    78,   232,     5,     6,    80,   239,     5,     6,
      82,   246,     5,   250,   251,    54,    56,    58,     7,    60,
      62,    64,    66,    68,    70,     7,    72,     7,    74,    75,
     206,     3,     8,     3,     8,     4,    90,     3,   298,     3,
     302,     3,     8,     3,     8,     3,     8,     3,     8,     3,
       8,     3,     8,     3,     8,     3,     8,     3,     8,     3,
       8,    30,   387,    52,   127,   416,     7,     7,     7,    86,
       5,   275,   276,     7,   228,   227,     7,   235,   234,     7,
     242,   241,    84,     7,    74,    75,   252,   207,     7,   370,
       7,     4,    90,     7,    61,    92,   299,     7,    94,    97,
     303,     7,   306,     7,   310,     7,   314,     7,   362,     7,
     358,     7,   318,     7,   328,     7,   338,     7,   348,     7,
     366,     3,     8,     9,   388,    31,   417,   135,   454,     7,
      74,    75,   277,    78,    78,    80,    80,    82,    82,   253,
     208,    74,    75,   371,    88,     8,     8,    96,    97,   307,
      97,   102,   311,    97,   104,   315,    97,   106,   363,    97,
     108,   359,    99,   110,   319,    99,   112,   329,    99,   114,
     339,    99,   116,   349,   118,   119,   367,     7,   123,   389,
       3,     8,     9,   418,    32,   455,   143,   492,   278,   254,
       8,     9,    36,    38,    40,   209,   210,   212,   214,   216,
     372,     4,     4,     8,     8,     8,     8,     8,   320,   330,
     340,   350,     8,    33,    75,   397,     7,   129,   419,     3,
       8,     9,   456,    26,   493,   279,     8,     9,    36,   255,
     256,   262,    76,     3,     3,     3,     8,     9,    36,   373,
     374,   377,    62,    98,     4,     4,     4,     4,     4,     8,
       9,    19,    20,    21,   321,   322,   323,   324,   325,     8,
       9,    19,    20,    21,   331,   332,   333,   334,   335,     8,
       9,    19,    20,    21,   341,   342,   343,   344,   345,     8,
       9,    19,    20,    21,   351,   352,   353,   354,   355,     4,
       3,   398,   122,    34,   133,   427,     7,   137,   457,     3,
       8,     8,     9,    36,   280,   281,   287,    76,     3,    38,
     258,   211,   213,   215,    76,     3,    38,   375,    98,    98,
      98,    98,    98,   100,     3,     3,     3,   100,     3,     3,
       3,   100,     3,     3,     3,   100,     3,     3,     3,   120,
       7,     8,    22,    23,    24,    33,    36,    38,    40,   399,
     400,   401,   402,   403,   404,   405,   406,   407,     3,    34,
      75,   435,    35,   141,   465,     7,   494,    76,     3,    38,
     283,   257,     3,    40,   260,     7,     7,     7,     7,     3,
      40,   376,     7,     7,     7,     7,     7,     7,     7,     7,
       7,     7,     7,     7,     8,   125,   408,     3,     3,     3,
       3,     3,     3,     3,     7,     3,   436,   128,     3,    35,
      75,   473,   144,   145,   495,   282,     3,    40,   285,     7,
     259,     3,     7,     3,   390,   409,    76,     7,     7,     7,
       7,     7,     7,     7,     8,     7,     8,    22,    23,    24,
      34,    36,    38,    40,   437,   438,   439,   440,   441,   442,
     443,   444,   445,     7,     3,   474,   136,   496,     7,   284,
       3,     7,   261,     7,   124,   125,   391,     8,     9,    37,
      38,    41,    42,   410,   411,   412,   413,   414,   415,   420,
       8,   131,   446,     3,     3,     3,     3,     3,     3,     3,
       8,     7,     8,    22,    23,    24,    35,    36,    38,    40,
     475,   476,   477,   478,   479,   480,   481,   482,   483,     8,
       9,    22,    23,    24,    36,    38,    40,   497,   498,   499,
     500,   501,   502,   503,   504,     7,   286,     7,   392,   126,
       3,     3,     3,     3,   130,   131,   421,   428,   447,    76,
       7,     7,     7,     7,     7,     7,     7,   458,     8,   139,
     484,     3,     3,     3,     3,     3,     3,     3,   146,     3,
       3,     3,     3,     3,     3,     7,     8,     9,    37,    38,
     393,   394,   395,   396,     7,     7,     7,     7,   422,   131,
     134,   429,     8,     9,    37,    38,    41,    42,   448,   449,
     450,   451,   452,   453,   138,   139,   459,   466,   485,    76,
       7,     7,     7,     7,     7,     7,     7,     7,     7,     7,
       7,     7,     7,   126,     3,     3,     8,     9,    37,    38,
     423,   424,   425,   426,   430,   126,     3,     3,     3,     3,
     460,   139,   142,   467,     8,     9,    37,    38,    41,    42,
     486,   487,   488,   489,   490,   491,     7,     7,   132,     3,
       3,     8,     9,    37,    38,   431,   432,   433,   434,     7,
       7,     7,     7,     8,     9,    37,    38,   461,   462,   463,
     464,   468,   140,     3,     3,     3,     3,     7,     7,   132,
       3,     3,   140,     3,     3,     8,     9,    37,    38,   469,
     470,   471,   472,     7,     7,     7,     7,     7,     7,     7,
       7,   140,     3,     3,     7,     7
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
		osoption->general->otherOptions->other = new OtherOption*();	
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
		osoption->system->otherOptions->other = new OtherOption*();	
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

  case 174:

    {	if (parserData->otherOptionNamePresent)
	{	osolerror( NULL, osoption, parserData, "only one name attribute allowed");
	}
	else
	{	parserData->otherOptionNamePresent = true;
		osoption->system->otherOptions->other[parserData->numberOfOtherSystemOptions]->name = (yyvsp[(2) - (2)].sval);	
	}
}
    break;

  case 176:

    {	if (parserData->otherOptionValuePresent)
	{	osolerror( NULL, osoption, parserData, "only one value attribute allowed");
	}
	else
	{	parserData->otherOptionValuePresent = true;
		osoption->system->otherOptions->other[parserData->numberOfOtherSystemOptions]->value = (yyvsp[(2) - (2)].sval);	
	}
}
    break;

  case 178:

    {	if (parserData->otherOptionDescriptionPresent)
	{	osolerror( NULL, osoption, parserData, "only one description attribute allowed");
	}
	else
	{	parserData->otherOptionDescriptionPresent = true;
		osoption->system->otherOptions->other[parserData->numberOfOtherSystemOptions]->description = (yyvsp[(2) - (2)].sval);	
	}
}
    break;

  case 184:

    {	if (parserData->osolservicePresent)
	{	osolerror( NULL, osoption, parserData, "only one <service> element allowed");
	}
	else
	{	parserData->osolservicePresent = true;	
		osoption->service = new ServiceOption();
	}
}
    break;

  case 193:

    {	if (parserData->serviceTypePresent)
	{	osolerror( NULL, osoption, parserData, "only one <type> element allowed");
	}
	else
	{	parserData->serviceTypePresent = true;	
	}
}
    break;

  case 196:

    {osoption->service->type = (yyvsp[(2) - (2)].ival);}
    break;

  case 199:

    {	if (parserData->otherServiceOptionsPresent)
	{	osolerror( NULL, osoption, parserData, "only one <otherOptions> element allowed");
	}
	else
	{	parserData->otherServiceOptionsPresent = true;
		osoption->service->otherOptions = new OtherOptions();	
		osoption->service->otherOptions->other = new OtherOption*();	
	}
}
    break;

  case 200:

    {	osoption->service->otherOptions->numberOfOtherOptions = (yyvsp[(3) - (4)].ival);
	osoption->service->otherOptions->other = new OtherOption*[(yyvsp[(3) - (4)].ival)];
	for (int i=0; i < (yyvsp[(3) - (4)].ival); i++) osoption->service->otherOptions->other[i] = new OtherOption();
}
    break;

  case 201:

    {	if (parserData->numberOfOtherServiceOptions != osoption->service->otherOptions->numberOfOtherOptions)
		osolerror (NULL, osoption, parserData, "wrong number of other options in <service> element"); 
}
    break;

  case 204:

    {	if (parserData->numberOfOtherServiceOptions >= osoption->service->otherOptions->numberOfOtherOptions)
		{	osolerror (NULL, osoption, parserData, "too many other options in <service> element");
		};
	}
    break;

  case 205:

    {	if (!parserData->otherOptionNamePresent)
		osolerror (NULL, osoption, parserData, "name attribute must be present");
	/* reset defaults for the next option */
	parserData->otherOptionNamePresent = false;
	parserData->otherOptionValuePresent = false;
	parserData->otherOptionDescriptionPresent = false;
	parserData->numberOfOtherServiceOptions++;
}
    break;

  case 209:

    {	if (parserData->otherOptionNamePresent)
	{	osolerror( NULL, osoption, parserData, "only one name attribute allowed");
	}
	else
	{	parserData->otherOptionNamePresent = true;
		osoption->service->otherOptions->other[parserData->numberOfOtherServiceOptions]->name = (yyvsp[(2) - (2)].sval);	
	}
}
    break;

  case 212:

    {	if (parserData->otherOptionValuePresent)
	{	osolerror( NULL, osoption, parserData, "only one value attribute allowed");
	}
	else
	{	parserData->otherOptionValuePresent = true;
		osoption->service->otherOptions->other[parserData->numberOfOtherServiceOptions]->value = (yyvsp[(2) - (2)].sval);	
	}
}
    break;

  case 215:

    {	if (parserData->otherOptionDescriptionPresent)
	{	osolerror( NULL, osoption, parserData, "only one description attribute allowed");
	}
	else
	{	parserData->otherOptionDescriptionPresent = true;
		osoption->service->otherOptions->other[parserData->numberOfOtherServiceOptions]->description = (yyvsp[(2) - (2)].sval);	
	}
}
    break;

  case 239:

    {
}
    break;

  case 241:

    {
}
    break;

  case 245:

    {
}
    break;

  case 246:

    {
}
    break;

  case 248:

    {
}
    break;

  case 251:

    {
}
    break;

  case 253:

    {
}
    break;

  case 256:

    {
}
    break;

  case 258:

    {
}
    break;

  case 261:

    {
}
    break;

  case 263:

    {
}
    break;

  case 266:

    {
}
    break;

  case 268:

    {
}
    break;

  case 271:

    {
}
    break;

  case 273:

    {
}
    break;

  case 276:

    {
}
    break;

  case 282:

    {
}
    break;

  case 283:

    {
}
    break;

  case 284:

    {
}
    break;

  case 288:

    {
}
    break;

  case 291:

    {
}
    break;

  case 297:

    {
}
    break;

  case 298:

    {
}
    break;

  case 299:

    {
}
    break;

  case 303:

    {
}
    break;

  case 306:

    {
}
    break;

  case 312:

    {
}
    break;

  case 313:

    {
}
    break;

  case 314:

    {
}
    break;

  case 318:

    {
}
    break;

  case 321:

    {
}
    break;

  case 327:

    {
}
    break;

  case 328:

    {
}
    break;

  case 329:

    {
}
    break;

  case 333:

    {
}
    break;

  case 336:

    {
}
    break;

  case 338:

    {
}
    break;

  case 341:

    {
}
    break;

  case 343:

    {
}
    break;

  case 346:

    {
}
    break;

  case 348:

    {
}
    break;

  case 355:

    {
}
    break;

  case 357:

    {
}
    break;

  case 359:

    {
}
    break;

  case 361:

    {
}
    break;

  case 369:

    {
}
    break;

  case 370:

    {
}
    break;

  case 371:

    {
}
    break;

  case 378:

    {
}
    break;

  case 390:

    {
}
    break;

  case 391:

    {
}
    break;

  case 405:

    {
}
    break;

  case 406:

    {
}
    break;

  case 407:

    {
}
    break;

  case 408:

    {
}
    break;

  case 409:

    {
}
    break;

  case 410:

    {
}
    break;

  case 411:

    {
}
    break;

  case 420:

    {
}
    break;

  case 421:

    {
}
    break;

  case 422:

    {
}
    break;

  case 423:

    {
}
    break;

  case 429:

    {
}
    break;

  case 441:

    {
}
    break;

  case 442:

    {
}
    break;

  case 454:

    {
}
    break;

  case 455:

    {
}
    break;

  case 469:

    {
}
    break;

  case 470:

    {
}
    break;

  case 471:

    {
}
    break;

  case 472:

    {
}
    break;

  case 473:

    {
}
    break;

  case 474:

    {
}
    break;

  case 475:

    {
}
    break;

  case 484:

    {
}
    break;

  case 485:

    {
}
    break;

  case 486:

    {
}
    break;

  case 487:

    {
}
    break;

  case 493:

    {
}
    break;

  case 505:

    {
}
    break;

  case 506:

    {
}
    break;

  case 518:

    {
}
    break;

  case 519:

    {
}
    break;

  case 533:

    {
}
    break;

  case 534:

    {
}
    break;

  case 535:

    {
}
    break;

  case 536:

    {
}
    break;

  case 537:

    {
}
    break;

  case 538:

    {
}
    break;

  case 539:

    {
}
    break;

  case 548:

    {
}
    break;

  case 549:

    {
}
    break;

  case 550:

    {
}
    break;

  case 551:

    {
}
    break;

  case 556:

    {
}
    break;

  case 568:

    {
}
    break;

  case 569:

    {
}
    break;

  case 570:

    {
}
    break;

  case 571:

    {
}
    break;

  case 572:

    {
}
    break;

  case 573:

    {
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


