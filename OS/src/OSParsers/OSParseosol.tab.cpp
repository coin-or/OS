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
#define YYLAST   654

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  148
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  306
/* YYNRULES -- Number of rules.  */
#define YYNRULES  519
/* YYNRULES -- Number of states.  */
#define YYNSTATES  938

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
      74,    76,    78,    81,    85,    90,    92,    94,    97,   101,
     106,   108,   110,   113,   118,   124,   125,   129,   131,   133,
     136,   140,   145,   147,   149,   152,   156,   161,   163,   165,
     168,   172,   177,   179,   181,   184,   188,   193,   195,   197,
     200,   204,   209,   211,   213,   216,   221,   227,   228,   232,
     238,   242,   243,   246,   250,   251,   254,   258,   262,   263,
     267,   268,   272,   274,   277,   278,   283,   286,   287,   290,
     292,   294,   296,   298,   300,   306,   312,   313,   317,   323,
     329,   330,   334,   340,   346,   347,   351,   353,   355,   358,
     362,   367,   373,   377,   378,   381,   385,   386,   389,   393,
     397,   398,   402,   403,   407,   409,   412,   413,   418,   421,
     422,   425,   427,   429,   431,   433,   436,   440,   445,   451,
     455,   456,   459,   463,   464,   467,   471,   475,   476,   480,
     481,   485,   487,   490,   491,   496,   499,   500,   503,   505,
     507,   509,   511,   513,   515,   517,   519,   521,   523,   525,
     527,   529,   531,   533,   539,   540,   544,   546,   548,   551,
     555,   560,   565,   569,   570,   573,   578,   583,   587,   588,
     591,   596,   602,   606,   607,   610,   615,   621,   625,   626,
     629,   634,   640,   644,   645,   648,   653,   659,   663,   664,
     667,   671,   672,   675,   677,   679,   681,   685,   689,   693,
     696,   698,   704,   708,   709,   712,   716,   717,   720,   722,
     724,   726,   730,   734,   738,   741,   743,   749,   753,   754,
     757,   761,   762,   765,   767,   769,   771,   775,   779,   783,
     786,   788,   794,   798,   799,   802,   806,   807,   810,   812,
     814,   816,   820,   824,   828,   831,   833,   839,   843,   844,
     847,   852,   858,   862,   863,   866,   871,   877,   881,   882,
     885,   890,   896,   900,   901,   904,   908,   909,   912,   916,
     920,   921,   925,   926,   930,   932,   935,   936,   940,   941,
     944,   946,   948,   950,   954,   958,   962,   966,   968,   973,
     974,   978,   979,   983,   988,   990,   991,   999,  1000,  1003,
    1007,  1008,  1011,  1013,  1015,  1019,  1023,  1026,  1028,  1029,
    1033,  1034,  1037,  1039,  1041,  1043,  1045,  1047,  1049,  1051,
    1055,  1059,  1063,  1067,  1071,  1075,  1079,  1083,  1087,  1088,
    1091,  1093,  1095,  1097,  1099,  1103,  1107,  1111,  1115,  1118,
    1120,  1121,  1125,  1126,  1130,  1136,  1138,  1139,  1147,  1148,
    1151,  1155,  1156,  1159,  1161,  1163,  1167,  1171,  1174,  1176,
    1177,  1185,  1186,  1189,  1193,  1194,  1197,  1199,  1201,  1205,
    1209,  1212,  1214,  1215,  1219,  1220,  1223,  1225,  1227,  1229,
    1231,  1233,  1235,  1237,  1241,  1245,  1249,  1253,  1257,  1261,
    1265,  1269,  1273,  1274,  1277,  1279,  1281,  1283,  1285,  1289,
    1293,  1297,  1301,  1304,  1306,  1307,  1311,  1312,  1316,  1322,
    1324,  1325,  1333,  1334,  1337,  1341,  1342,  1345,  1347,  1349,
    1353,  1357,  1360,  1362,  1363,  1371,  1372,  1375,  1379,  1380,
    1383,  1385,  1387,  1391,  1395,  1398,  1400,  1401,  1405,  1406,
    1409,  1411,  1413,  1415,  1417,  1419,  1421,  1423,  1427,  1431,
    1435,  1439,  1443,  1447,  1451,  1455,  1459,  1460,  1463,  1465,
    1467,  1469,  1471,  1475,  1479,  1483,  1487,  1490,  1492,  1493,
    1499,  1503,  1504,  1507,  1511,  1512,  1515,  1517,  1519,  1521,
    1523,  1525,  1527,  1531,  1535,  1539,  1543,  1547,  1551,  1554
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     149,     0,    -1,   150,     8,   151,    12,    -1,   150,     9,
      -1,    10,    -1,    10,    11,    -1,   152,   199,   221,   237,
     327,    -1,    -1,   153,   154,    -1,    43,    -1,     8,   155,
      44,    -1,     9,    -1,    -1,   155,   156,    -1,   157,    -1,
     160,    -1,   163,    -1,   166,    -1,   170,    -1,   173,    -1,
     176,    -1,   179,    -1,   182,    -1,   185,    -1,   189,    -1,
     158,   159,    -1,    53,    -1,     9,    -1,     8,    54,    -1,
       8,     4,    54,    -1,   161,    -1,   162,    -1,    55,     9,
      -1,    55,     8,    56,    -1,    55,     8,     4,    56,    -1,
     164,    -1,   165,    -1,    57,     9,    -1,    57,     8,    58,
      -1,    57,     8,     4,    58,    -1,   167,    -1,   168,    -1,
      59,     9,    -1,    59,   169,     8,    60,    -1,    59,   169,
       8,     4,    60,    -1,    -1,    13,     3,     7,    -1,   171,
      -1,   172,    -1,    61,     9,    -1,    61,     8,    62,    -1,
      61,     8,     4,    62,    -1,   174,    -1,   175,    -1,    63,
       9,    -1,    63,     8,    64,    -1,    63,     8,     4,    64,
      -1,   177,    -1,   178,    -1,    65,     9,    -1,    65,     8,
      66,    -1,    65,     8,     4,    66,    -1,   180,    -1,   181,
      -1,    67,     9,    -1,    67,     8,    68,    -1,    67,     8,
       4,    68,    -1,   183,    -1,   184,    -1,    69,     9,    -1,
      69,     8,    70,    -1,    69,     8,     4,    70,    -1,   186,
      -1,   187,    -1,    71,     9,    -1,    71,   188,     8,    72,
      -1,    71,   188,     8,     4,    72,    -1,    -1,    14,     3,
       7,    -1,    73,   190,     8,   191,    74,    -1,    15,     3,
       7,    -1,    -1,   191,   192,    -1,    75,   193,   198,    -1,
      -1,   193,   194,    -1,   195,   196,   197,    -1,    36,     3,
       7,    -1,    -1,    38,     3,     7,    -1,    -1,    40,     3,
       7,    -1,     9,    -1,     8,    76,    -1,    -1,    45,     8,
     200,    46,    -1,    45,     9,    -1,    -1,   200,   201,    -1,
     202,    -1,   204,    -1,   206,    -1,   208,    -1,   211,    -1,
      77,   203,     8,     6,    78,    -1,    77,   203,     8,     5,
      78,    -1,    -1,    39,     3,     7,    -1,    79,   205,     8,
       6,    80,    -1,    79,   205,     8,     5,    80,    -1,    -1,
      39,     3,     7,    -1,    81,   207,     8,     6,    82,    -1,
      81,   207,     8,     5,    82,    -1,    -1,    39,     3,     7,
      -1,   209,    -1,   210,    -1,    83,     9,    -1,    83,     8,
      84,    -1,    83,     8,     5,    84,    -1,    73,   212,     8,
     213,    74,    -1,    15,     3,     7,    -1,    -1,   213,   214,
      -1,    75,   215,   220,    -1,    -1,   215,   216,    -1,   217,
     218,   219,    -1,    36,     3,     7,    -1,    -1,    38,     3,
       7,    -1,    -1,    40,     3,     7,    -1,     9,    -1,     8,
      76,    -1,    -1,    47,     8,   222,    48,    -1,    47,     9,
      -1,    -1,   222,   223,    -1,   224,    -1,   227,    -1,   225,
      -1,   226,    -1,    85,     9,    -1,    85,     8,    86,    -1,
      85,     8,     4,    86,    -1,    73,   228,     8,   229,    74,
      -1,    15,     3,     7,    -1,    -1,   229,   230,    -1,    75,
     231,   236,    -1,    -1,   231,   232,    -1,   233,   234,   235,
      -1,    36,     3,     7,    -1,    -1,    38,     3,     7,    -1,
      -1,    40,     3,     7,    -1,     9,    -1,     8,    76,    -1,
      -1,    49,     8,   238,    50,    -1,    49,     9,    -1,    -1,
     238,   239,    -1,   240,    -1,   242,    -1,   245,    -1,   249,
      -1,   253,    -1,   257,    -1,   261,    -1,   265,    -1,   275,
      -1,   285,    -1,   295,    -1,   305,    -1,   309,    -1,   313,
      -1,   317,    -1,    87,   241,     8,     4,    88,    -1,    -1,
      39,     3,     7,    -1,   243,    -1,   244,    -1,    89,     9,
      -1,    89,     8,    90,    -1,    89,     8,     4,    90,    -1,
      91,   246,   247,    92,    -1,    16,     3,     7,    -1,    -1,
     247,   248,    -1,    61,     8,     4,    62,    -1,    93,   250,
     251,    94,    -1,    17,     3,     7,    -1,    -1,   251,   252,
      -1,    97,     8,     4,    98,    -1,    95,   254,     8,   255,
      96,    -1,    17,     3,     7,    -1,    -1,   255,   256,    -1,
      97,     8,     4,    98,    -1,   101,   258,     8,   259,   102,
      -1,    17,     3,     7,    -1,    -1,   259,   260,    -1,    97,
       8,     4,    98,    -1,   103,   262,     8,   263,   104,    -1,
      17,     3,     7,    -1,    -1,   263,   264,    -1,    97,     8,
       4,    98,    -1,   109,   266,     8,   267,   110,    -1,    18,
       3,     7,    -1,    -1,   267,   268,    -1,    99,   269,   274,
      -1,    -1,   269,   270,    -1,   271,    -1,   272,    -1,   273,
      -1,    19,     3,     7,    -1,    20,     3,     7,    -1,    21,
       3,     7,    -1,     8,   100,    -1,     9,    -1,   111,   276,
       8,   277,   112,    -1,    18,     3,     7,    -1,    -1,   277,
     278,    -1,    99,   279,   284,    -1,    -1,   279,   280,    -1,
     281,    -1,   282,    -1,   283,    -1,    19,     3,     7,    -1,
      20,     3,     7,    -1,    21,     3,     7,    -1,     8,   100,
      -1,     9,    -1,   113,   286,     8,   287,   114,    -1,    18,
       3,     7,    -1,    -1,   287,   288,    -1,    99,   289,   294,
      -1,    -1,   289,   290,    -1,   291,    -1,   292,    -1,   293,
      -1,    19,     3,     7,    -1,    20,     3,     7,    -1,    21,
       3,     7,    -1,     8,   100,    -1,     9,    -1,   115,   296,
       8,   297,   116,    -1,    18,     3,     7,    -1,    -1,   297,
     298,    -1,    99,   299,   304,    -1,    -1,   299,   300,    -1,
     301,    -1,   302,    -1,   303,    -1,    19,     3,     7,    -1,
      20,     3,     7,    -1,    21,     3,     7,    -1,     8,   100,
      -1,     9,    -1,   107,   306,     8,   307,   108,    -1,    17,
       3,     7,    -1,    -1,   307,   308,    -1,    97,     8,     4,
      98,    -1,   105,   310,     8,   311,   106,    -1,    17,     3,
       7,    -1,    -1,   311,   312,    -1,    97,     8,     4,    98,
      -1,   117,   314,     8,   315,   118,    -1,    25,     3,     7,
      -1,    -1,   315,   316,    -1,   119,     8,     4,   120,    -1,
      73,   318,     8,   319,    74,    -1,    15,     3,     7,    -1,
      -1,   319,   320,    -1,    75,   321,   326,    -1,    -1,   321,
     322,    -1,   323,   324,   325,    -1,    36,     3,     7,    -1,
      -1,    38,     3,     7,    -1,    -1,    40,     3,     7,    -1,
       9,    -1,     8,    76,    -1,    -1,    51,   328,   333,    -1,
      -1,   328,   329,    -1,   330,    -1,   331,    -1,   332,    -1,
      27,     3,     7,    -1,    29,     3,     7,    -1,    28,     3,
       7,    -1,     8,   334,    52,    -1,     9,    -1,   335,   365,
     403,   441,    -1,    -1,   121,   336,   337,    -1,    -1,    30,
       3,     7,    -1,     8,   338,   346,   122,    -1,     9,    -1,
      -1,   123,    33,     3,     7,     8,   339,   124,    -1,    -1,
     339,   340,    -1,   125,   341,   345,    -1,    -1,   341,   342,
      -1,   343,    -1,   344,    -1,    37,     3,     7,    -1,    38,
       3,     7,    -1,     8,   126,    -1,     9,    -1,    -1,    75,
     347,   356,    -1,    -1,   347,   348,    -1,   349,    -1,   350,
      -1,   351,    -1,   352,    -1,   353,    -1,   354,    -1,   355,
      -1,    33,     3,     7,    -1,    36,     3,     7,    -1,    38,
       3,     7,    -1,    22,     3,     7,    -1,    23,     3,     7,
      -1,    24,     3,     7,    -1,    40,     3,     7,    -1,     8,
     357,    76,    -1,   125,   358,   364,    -1,    -1,   358,   359,
      -1,   360,    -1,   361,    -1,   362,    -1,   363,    -1,    37,
       3,     7,    -1,    38,     3,     7,    -1,    41,     3,     7,
      -1,    42,     3,     7,    -1,     8,   126,    -1,     9,    -1,
      -1,   127,   366,   367,    -1,    -1,    31,     3,     7,    -1,
       8,   368,   376,   384,   128,    -1,     9,    -1,    -1,   129,
      34,     3,     7,     8,   369,   130,    -1,    -1,   369,   370,
      -1,   131,   371,   375,    -1,    -1,   371,   372,    -1,   373,
      -1,   374,    -1,    37,     3,     7,    -1,    38,     3,     7,
      -1,     8,   132,    -1,     9,    -1,    -1,   133,    34,     3,
       7,     8,   377,   134,    -1,    -1,   377,   378,    -1,   131,
     379,   383,    -1,    -1,   379,   380,    -1,   381,    -1,   382,
      -1,    37,     3,     7,    -1,    38,     3,     7,    -1,     8,
     132,    -1,     9,    -1,    -1,    75,   385,   394,    -1,    -1,
     385,   386,    -1,   387,    -1,   388,    -1,   389,    -1,   390,
      -1,   391,    -1,   392,    -1,   393,    -1,    34,     3,     7,
      -1,    36,     3,     7,    -1,    38,     3,     7,    -1,    22,
       3,     7,    -1,    23,     3,     7,    -1,    24,     3,     7,
      -1,    40,     3,     7,    -1,     8,   395,    76,    -1,   131,
     396,   402,    -1,    -1,   396,   397,    -1,   398,    -1,   399,
      -1,   400,    -1,   401,    -1,    37,     3,     7,    -1,    38,
       3,     7,    -1,    41,     3,     7,    -1,    42,     3,     7,
      -1,     8,   126,    -1,     9,    -1,    -1,   135,   404,   405,
      -1,    -1,    32,     3,     7,    -1,     8,   406,   414,   422,
     136,    -1,     9,    -1,    -1,   137,    35,     3,     7,     8,
     407,   138,    -1,    -1,   407,   408,    -1,   139,   409,   413,
      -1,    -1,   409,   410,    -1,   411,    -1,   412,    -1,    37,
       3,     7,    -1,    38,     3,     7,    -1,     8,   140,    -1,
       9,    -1,    -1,   141,    35,     3,     7,     8,   415,   142,
      -1,    -1,   415,   416,    -1,   139,   417,   421,    -1,    -1,
     417,   418,    -1,   419,    -1,   420,    -1,    37,     3,     7,
      -1,    38,     3,     7,    -1,     8,   140,    -1,     9,    -1,
      -1,    75,   423,   432,    -1,    -1,   423,   424,    -1,   425,
      -1,   426,    -1,   427,    -1,   428,    -1,   429,    -1,   430,
      -1,   431,    -1,    35,     3,     7,    -1,    36,     3,     7,
      -1,    38,     3,     7,    -1,    22,     3,     7,    -1,    23,
       3,     7,    -1,    24,     3,     7,    -1,    40,     3,     7,
      -1,     8,   433,    76,    -1,   139,   434,   440,    -1,    -1,
     434,   435,    -1,   436,    -1,   437,    -1,   438,    -1,   439,
      -1,    37,     3,     7,    -1,    38,     3,     7,    -1,    41,
       3,     7,    -1,    42,     3,     7,    -1,     8,   140,    -1,
       9,    -1,    -1,   143,   442,     8,   443,   144,    -1,    26,
       3,     7,    -1,    -1,   443,   444,    -1,   145,   445,   453,
      -1,    -1,   445,   446,    -1,   447,    -1,   448,    -1,   449,
      -1,   450,    -1,   451,    -1,   452,    -1,    36,     3,     7,
      -1,    38,     3,     7,    -1,    22,     3,     7,    -1,    23,
       3,     7,    -1,    24,     3,     7,    -1,    40,     3,     7,
      -1,     8,   146,    -1,     9,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   124,   124,   125,   127,   128,   130,   132,   132,   134,
     145,   146,   148,   148,   150,   150,   150,   150,   150,   151,
     151,   151,   151,   151,   151,   154,   156,   166,   167,   168,
     175,   175,   177,   178,   182,   187,   187,   189,   190,   194,
     199,   199,   201,   202,   206,   210,   210,   215,   215,   217,
     218,   222,   227,   227,   229,   230,   234,   239,   239,   241,
     242,   246,   251,   251,   253,   254,   258,   263,   263,   265,
     266,   270,   274,   274,   276,   277,   281,   285,   285,   291,
     293,   297,   297,   299,   301,   301,   303,   305,   309,   309,
     313,   313,   317,   317,   322,   323,   324,   326,   326,   328,
     328,   328,   328,   328,   330,   331,   335,   335,   339,   340,
     344,   344,   348,   349,   353,   353,   357,   357,   359,   360,
     364,   368,   370,   374,   374,   376,   378,   378,   380,   382,
     386,   386,   390,   390,   394,   394,   399,   400,   401,   403,
     403,   405,   405,   407,   407,   409,   410,   414,   419,   421,
     425,   425,   427,   429,   429,   431,   433,   437,   437,   441,
     441,   445,   445,   450,   451,   452,   454,   454,   456,   456,
     456,   456,   456,   457,   457,   457,   457,   457,   458,   458,
     458,   458,   458,   460,   464,   464,   468,   468,   470,   471,
     475,   479,   481,   485,   485,   488,   492,   495,   499,   499,
     501,   505,   508,   512,   512,   514,   518,   521,   525,   525,
     527,   531,   534,   538,   538,   540,   544,   547,   551,   551,
     553,   557,   557,   559,   559,   559,   561,   565,   569,   573,
     573,   576,   579,   583,   583,   585,   589,   589,   591,   591,
     591,   593,   597,   601,   605,   605,   608,   611,   615,   615,
     617,   621,   621,   623,   623,   623,   625,   629,   633,   637,
     637,   640,   643,   647,   647,   649,   653,   653,   655,   655,
     655,   657,   661,   665,   669,   669,   673,   676,   680,   680,
     682,   686,   689,   693,   693,   695,   700,   703,   707,   707,
     709,   714,   716,   720,   720,   722,   724,   724,   726,   728,
     732,   732,   736,   736,   740,   740,   745,   745,   747,   747,
     749,   749,   749,   751,   755,   759,   763,   763,   765,   767,
     767,   769,   769,   773,   774,   776,   776,   779,   779,   781,
     783,   783,   785,   785,   787,   791,   795,   795,   798,   798,
     800,   800,   803,   804,   805,   806,   807,   808,   809,   811,
     815,   819,   823,   827,   831,   835,   840,   842,   844,   844,
     847,   848,   849,   850,   852,   856,   860,   864,   868,   868,
     870,   870,   872,   872,   876,   878,   881,   881,   884,   884,
     886,   888,   888,   890,   890,   892,   896,   900,   900,   903,
     903,   906,   906,   908,   910,   910,   912,   912,   914,   918,
     922,   922,   925,   925,   927,   927,   930,   931,   932,   933,
     934,   935,   936,   938,   942,   946,   950,   954,   958,   962,
     967,   969,   971,   971,   974,   975,   976,   977,   979,   983,
     987,   991,   995,   995,   997,   997,   999,   999,  1003,  1005,
    1007,  1007,  1010,  1010,  1012,  1014,  1014,  1016,  1016,  1018,
    1022,  1026,  1026,  1029,  1029,  1032,  1032,  1034,  1036,  1036,
    1038,  1038,  1040,  1044,  1048,  1048,  1051,  1051,  1053,  1053,
    1056,  1057,  1058,  1059,  1060,  1061,  1062,  1064,  1068,  1072,
    1076,  1080,  1084,  1088,  1093,  1095,  1097,  1097,  1100,  1101,
    1102,  1103,  1105,  1109,  1113,  1117,  1121,  1121,  1124,  1124,
    1126,  1130,  1130,  1132,  1134,  1134,  1137,  1138,  1139,  1140,
    1141,  1142,  1144,  1148,  1152,  1156,  1160,  1164,  1169,  1169
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
  "serviceURI", "serviceURIhead", "serviceURIbody", "servicename",
  "emptyservicename", "nonemptyservicename", "instancename",
  "emptyinstancename", "nonemptyinstancename", "instancelocation",
  "emptylocation", "nonemptylocation", "locationtypeatt", "jobid",
  "emptyjobid", "nonemptyjobid", "solvertoinvoke", "emptysolver",
  "nonemptysolver", "license", "emptylicense", "nonemptylicense",
  "username", "emptyusername", "nonemptyusername", "password",
  "emptypassword", "nonemptypassword", "contact", "emptycontact",
  "nonemptycontact", "transporttypeatt", "othergeneraloptions",
  "numberofothergeneraloptions", "othergeneraloptionslist",
  "othergeneraloption", "othergeneralattributes", "othergeneralattribute",
  "generaloptionnameatt", "generaloptionvalueatt",
  "generaloptiondescriptionatt", "othergeneraloptionsend", "osolsystem",
  "systemcontent", "systemoption", "mindiskspace", "mindiskspaceunit",
  "minmemorysize", "minmemoryunit", "mincpuspeed", "mincpuspeedunit",
  "mincpunumber", "emptymincpunumber", "nonemptymincpunumber",
  "othersystemoptions", "numberofothersystemoptions",
  "othersystemoptionslist", "othersystemoption", "othersystemattributes",
  "othersystemattribute", "systemoptionnameatt", "systemoptionvalueatt",
  "systemoptiondescriptionatt", "othersystemoptionsend", "osolservice",
  "servicecontent", "serviceoption", "servicetype", "emptyservicetype",
  "nonemptyservicetype", "otherserviceoptions",
  "numberofotherserviceoptions", "otherserviceoptionslist",
  "otherserviceoption", "otherserviceattributes", "otherserviceattribute",
  "serviceoptionnameatt", "serviceoptionvalueatt",
  "serviceoptiondescriptionatt", "otherserviceoptionsend", "osoljob",
  "jobcontent", "joboption", "maxtime", "maxtimeunit",
  "scheduledstarttime", "emptystarttime", "nonemptystarttime",
  "dependencies", "numberofjobidsatt", "dependencieslist",
  "dependencyjobid", "requireddirectories", "numberofreqdirpathsatt",
  "reqdirpathlist", "reqdirpath", "requiredfiles",
  "numberofreqfilpathsatt", "reqfilpathlist", "reqfilpath",
  "directoriestomake", "numberofdirtomakepathsatt", "dirtomakepathlist",
  "dirtomakepath", "filestocreate", "numberoffilestomakepathsatt",
  "filestomakepathlist", "filestomakepath", "inputdirectoriestomove",
  "numberofindirtomovepathpairsatt", "indirtomovepathpairlist",
  "indirtomovepathpair", "indirtomovepathpairattlist",
  "indirtomovepathpairatt", "indirtomovefromatt", "indirtomovetoatt",
  "indirtomovemakecopyatt", "indirtomovepathpairend", "inputfilestomove",
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
     156,   156,   156,   156,   156,   157,   158,   159,   159,   159,
     160,   160,   161,   161,   162,   163,   163,   164,   164,   165,
     166,   166,   167,   167,   168,   169,   169,   170,   170,   171,
     171,   172,   173,   173,   174,   174,   175,   176,   176,   177,
     177,   178,   179,   179,   180,   180,   181,   182,   182,   183,
     183,   184,   185,   185,   186,   186,   187,   188,   188,   189,
     190,   191,   191,   192,   193,   193,   194,   195,   196,   196,
     197,   197,   198,   198,   199,   199,   199,   200,   200,   201,
     201,   201,   201,   201,   202,   202,   203,   203,   204,   204,
     205,   205,   206,   206,   207,   207,   208,   208,   209,   209,
     210,   211,   212,   213,   213,   214,   215,   215,   216,   217,
     218,   218,   219,   219,   220,   220,   221,   221,   221,   222,
     222,   223,   223,   224,   224,   225,   225,   226,   227,   228,
     229,   229,   230,   231,   231,   232,   233,   234,   234,   235,
     235,   236,   236,   237,   237,   237,   238,   238,   239,   239,
     239,   239,   239,   239,   239,   239,   239,   239,   239,   239,
     239,   239,   239,   240,   241,   241,   242,   242,   243,   243,
     244,   245,   246,   247,   247,   248,   249,   250,   251,   251,
     252,   253,   254,   255,   255,   256,   257,   258,   259,   259,
     260,   261,   262,   263,   263,   264,   265,   266,   267,   267,
     268,   269,   269,   270,   270,   270,   271,   272,   273,   274,
     274,   275,   276,   277,   277,   278,   279,   279,   280,   280,
     280,   281,   282,   283,   284,   284,   285,   286,   287,   287,
     288,   289,   289,   290,   290,   290,   291,   292,   293,   294,
     294,   295,   296,   297,   297,   298,   299,   299,   300,   300,
     300,   301,   302,   303,   304,   304,   305,   306,   307,   307,
     308,   309,   310,   311,   311,   312,   313,   314,   315,   315,
     316,   317,   318,   319,   319,   320,   321,   321,   322,   323,
     324,   324,   325,   325,   326,   326,   327,   327,   328,   328,
     329,   329,   329,   330,   331,   332,   333,   333,   334,   335,
     335,   336,   336,   337,   337,   338,   338,   339,   339,   340,
     341,   341,   342,   342,   343,   344,   345,   345,   346,   346,
     347,   347,   348,   348,   348,   348,   348,   348,   348,   349,
     350,   351,   352,   353,   354,   355,   356,   357,   358,   358,
     359,   359,   359,   359,   360,   361,   362,   363,   364,   364,
     365,   365,   366,   366,   367,   367,   368,   368,   369,   369,
     370,   371,   371,   372,   372,   373,   374,   375,   375,   376,
     376,   377,   377,   378,   379,   379,   380,   380,   381,   382,
     383,   383,   384,   384,   385,   385,   386,   386,   386,   386,
     386,   386,   386,   387,   388,   389,   390,   391,   392,   393,
     394,   395,   396,   396,   397,   397,   397,   397,   398,   399,
     400,   401,   402,   402,   403,   403,   404,   404,   405,   405,
     406,   406,   407,   407,   408,   409,   409,   410,   410,   411,
     412,   413,   413,   414,   414,   415,   415,   416,   417,   417,
     418,   418,   419,   420,   421,   421,   422,   422,   423,   423,
     424,   424,   424,   424,   424,   424,   424,   425,   426,   427,
     428,   429,   430,   431,   432,   433,   434,   434,   435,   435,
     435,   435,   436,   437,   438,   439,   440,   440,   441,   441,
     442,   443,   443,   444,   445,   445,   446,   446,   446,   446,
     446,   446,   447,   448,   449,   450,   451,   452,   453,   453
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     4,     2,     1,     2,     5,     0,     2,     1,
       3,     1,     0,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     2,     1,     1,     2,     3,
       1,     1,     2,     3,     4,     1,     1,     2,     3,     4,
       1,     1,     2,     4,     5,     0,     3,     1,     1,     2,
       3,     4,     1,     1,     2,     3,     4,     1,     1,     2,
       3,     4,     1,     1,     2,     3,     4,     1,     1,     2,
       3,     4,     1,     1,     2,     4,     5,     0,     3,     5,
       3,     0,     2,     3,     0,     2,     3,     3,     0,     3,
       0,     3,     1,     2,     0,     4,     2,     0,     2,     1,
       1,     1,     1,     1,     5,     5,     0,     3,     5,     5,
       0,     3,     5,     5,     0,     3,     1,     1,     2,     3,
       4,     5,     3,     0,     2,     3,     0,     2,     3,     3,
       0,     3,     0,     3,     1,     2,     0,     4,     2,     0,
       2,     1,     1,     1,     1,     2,     3,     4,     5,     3,
       0,     2,     3,     0,     2,     3,     3,     0,     3,     0,
       3,     1,     2,     0,     4,     2,     0,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     5,     0,     3,     1,     1,     2,     3,
       4,     4,     3,     0,     2,     4,     4,     3,     0,     2,
       4,     5,     3,     0,     2,     4,     5,     3,     0,     2,
       4,     5,     3,     0,     2,     4,     5,     3,     0,     2,
       3,     0,     2,     1,     1,     1,     3,     3,     3,     2,
       1,     5,     3,     0,     2,     3,     0,     2,     1,     1,
       1,     3,     3,     3,     2,     1,     5,     3,     0,     2,
       3,     0,     2,     1,     1,     1,     3,     3,     3,     2,
       1,     5,     3,     0,     2,     3,     0,     2,     1,     1,
       1,     3,     3,     3,     2,     1,     5,     3,     0,     2,
       4,     5,     3,     0,     2,     4,     5,     3,     0,     2,
       4,     5,     3,     0,     2,     3,     0,     2,     3,     3,
       0,     3,     0,     3,     1,     2,     0,     3,     0,     2,
       1,     1,     1,     3,     3,     3,     3,     1,     4,     0,
       3,     0,     3,     4,     1,     0,     7,     0,     2,     3,
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
       3,     3,     2,     1,     0,     3,     0,     3,     5,     1,
       0,     7,     0,     2,     3,     0,     2,     1,     1,     3,
       3,     2,     1,     0,     7,     0,     2,     3,     0,     2,
       1,     1,     3,     3,     2,     1,     0,     3,     0,     2,
       1,     1,     1,     1,     1,     1,     1,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     0,     2,     1,     1,
       1,     1,     3,     3,     3,     3,     2,     1,     0,     5,
       3,     0,     2,     3,     0,     2,     1,     1,     1,     1,
       1,     1,     3,     3,     3,     3,     3,     3,     2,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       0,     4,     0,     0,     5,     1,     7,     3,     9,     0,
      94,     0,     2,     0,   136,    12,    11,     8,    97,    96,
       0,   163,     0,     0,   139,   138,     0,   306,    10,    26,
       0,     0,    45,     0,     0,     0,     0,     0,    77,     0,
      13,    14,     0,    15,    30,    31,    16,    35,    36,    17,
      40,    41,    18,    47,    48,    19,    52,    53,    20,    57,
      58,    21,    62,    63,    22,    67,    68,    23,    72,    73,
      24,    95,     0,   106,   110,   114,     0,    98,    99,   100,
     101,   102,   116,   117,   103,     0,   166,   165,   308,     6,
       0,    32,     0,    37,    42,     0,     0,     0,    49,     0,
      54,     0,    59,     0,    64,     0,    69,    74,     0,     0,
       0,     0,     0,    27,    25,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   118,   137,     0,     0,   140,   141,
     143,   144,   142,     0,     0,     0,    33,     0,    38,     0,
       0,     0,    50,     0,    55,     0,    60,     0,    65,     0,
      70,     0,     0,     0,    81,     0,    28,     0,   123,     0,
       0,     0,     0,     0,     0,     0,   119,     0,     0,     0,
     145,   164,     0,   184,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   167,   168,   169,
     186,   187,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   319,   317,     0,     0,     0,
     309,   310,   311,   312,   307,    34,    39,    46,     0,    43,
      51,    56,    61,    66,    71,    78,     0,    75,    80,     0,
      29,   122,     0,   107,     0,     0,   111,     0,     0,   115,
       0,     0,   120,     0,   150,     0,   146,     0,     0,     0,
       0,     0,   188,     0,   193,     0,   198,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   321,     0,   370,
       0,     0,     0,    44,    76,    79,    84,    82,   121,   126,
     124,   105,   104,   109,   108,   113,   112,   149,     0,   147,
       0,   293,     0,     0,     0,   189,     0,     0,     0,     0,
       0,   203,     0,   208,     0,   213,     0,   283,     0,   278,
       0,   218,     0,   233,     0,   248,     0,   263,     0,   288,
       0,     0,   316,   372,   434,   313,   315,   314,     0,     0,
     148,   153,   151,   292,     0,   185,     0,   190,   192,     0,
     191,   194,   197,   196,     0,   199,   202,     0,   207,     0,
     212,     0,   282,     0,   277,     0,   217,     0,   232,     0,
     247,     0,   262,     0,   287,     0,     0,   325,   324,   320,
       0,     0,   436,   498,     0,    92,     0,    85,    88,    83,
       0,   134,     0,   127,   130,   125,     0,   291,   296,   294,
     183,     0,     0,   201,     0,   204,     0,   206,   209,     0,
     211,   214,     0,   281,   284,     0,   276,   279,   221,   216,
     219,   236,   231,   234,   251,   246,   249,   266,   261,   264,
     286,     0,   289,   322,     0,   338,     0,   376,   375,   371,
       0,     0,     0,   318,    93,     0,     0,    90,   135,     0,
       0,   132,     0,   161,     0,   154,   157,   152,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   340,     0,   373,     0,   389,     0,   440,   439,
     435,     0,     0,    87,     0,     0,    86,   129,     0,     0,
     128,   162,     0,     0,   159,     0,   304,     0,   297,   300,
     295,   195,   200,     0,     0,     0,     0,     0,     0,   230,
       0,     0,     0,   222,   223,   224,   225,   220,     0,   245,
       0,     0,     0,   237,   238,   239,   240,   235,     0,   260,
       0,     0,     0,   252,   253,   254,   255,   250,     0,   275,
       0,     0,     0,   267,   268,   269,   270,   265,     0,     0,
       0,   323,     0,     0,   402,   437,     0,   453,     0,   501,
      89,     0,   131,     0,   156,     0,     0,   155,   305,     0,
       0,   302,   205,   210,   215,   285,   280,   229,     0,     0,
       0,   244,     0,     0,     0,   259,     0,     0,     0,   274,
       0,     0,     0,   290,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   341,   342,   343,   344,   345,   346,   347,
     348,   339,     0,     0,   404,     0,     0,     0,   466,   500,
       0,    91,   133,   158,     0,   299,     0,     0,   298,   226,
     227,   228,   241,   242,   243,   256,   257,   258,   271,   272,
     273,   327,   358,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   374,     0,     0,   468,     0,   499,
     504,   502,   160,   301,     0,     0,     0,   356,   352,   353,
     354,   349,   350,   351,   355,   378,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   405,   406,   407,   408,   409,
     410,   411,   412,   403,     0,     0,     0,   438,     0,   303,
     326,   330,   328,     0,   369,     0,     0,     0,     0,   359,
     360,   361,   362,   363,   357,     0,   391,   422,     0,     0,
       0,     0,     0,     0,     0,     0,   442,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   469,   470,   471,   472,
     473,   474,   475,   476,   467,     0,   519,     0,     0,     0,
       0,     0,     0,   505,   506,   507,   508,   509,   510,   511,
     503,     0,   368,     0,     0,     0,     0,   377,   381,   379,
       0,     0,   420,   416,   417,   418,   413,   414,   415,   419,
       0,   455,   486,     0,     0,     0,     0,     0,     0,     0,
       0,   518,     0,     0,     0,     0,     0,     0,     0,   337,
       0,     0,   331,   332,   333,   329,   364,   365,   366,   367,
       0,   394,   390,   392,     0,   433,     0,     0,     0,     0,
     423,   424,   425,   426,   427,   421,   441,   445,   443,     0,
       0,   484,   480,   481,   482,   477,   478,   479,   483,   514,
     515,   516,   512,   513,   517,   336,     0,     0,     0,   388,
       0,     0,   382,   383,   384,   380,     0,   432,     0,     0,
       0,     0,     0,   458,   454,   456,     0,   497,     0,     0,
       0,     0,   487,   488,   489,   490,   491,   485,   334,   335,
     387,     0,     0,     0,   401,     0,     0,   395,   396,   397,
     393,   428,   429,   430,   431,     0,   452,     0,     0,   446,
     447,   448,   444,     0,   496,     0,     0,     0,     0,   385,
     386,   400,     0,     0,   451,     0,     0,     0,   465,     0,
       0,   459,   460,   461,   457,   492,   493,   494,   495,   398,
     399,   449,   450,   464,     0,     0,   462,   463
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,     9,    10,    11,    17,    22,    40,    41,
      42,   114,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    96,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
     109,    70,   111,   229,   287,   338,   387,   388,   447,   486,
     389,    14,    23,    77,    78,   118,    79,   120,    80,   122,
      81,    82,    83,    84,   116,   232,   290,   339,   393,   394,
     451,   490,   395,    21,    85,   128,   129,   130,   131,   132,
     168,   298,   342,   396,   455,   456,   494,   567,   457,    27,
     133,   187,   188,   250,   189,   190,   191,   192,   254,   307,
     351,   193,   256,   309,   355,   194,   258,   357,   405,   195,
     260,   359,   408,   196,   262,   361,   411,   197,   268,   367,
     420,   466,   513,   514,   515,   516,   517,   198,   270,   369,
     423,   467,   523,   524,   525,   526,   527,   199,   272,   371,
     426,   468,   533,   534,   535,   536,   537,   200,   274,   373,
     429,   469,   543,   544,   545,   546,   547,   201,   266,   365,
     417,   202,   264,   363,   414,   203,   276,   375,   432,   204,
     248,   344,   399,   458,   498,   499,   571,   628,   500,    89,
     134,   210,   211,   212,   213,   214,   278,   279,   331,   379,
     435,   665,   702,   761,   802,   803,   804,   805,   473,   550,
     603,   604,   605,   606,   607,   608,   609,   610,   611,   643,
     666,   709,   710,   711,   712,   713,   714,   334,   381,   439,
     476,   715,   769,   810,   852,   853,   854,   855,   554,   770,
     813,   856,   887,   888,   889,   890,   615,   653,   685,   686,
     687,   688,   689,   690,   691,   692,   693,   718,   771,   820,
     821,   822,   823,   824,   825,   383,   441,   480,   557,   780,
     828,   862,   899,   900,   901,   902,   618,   829,   865,   903,
     921,   922,   923,   924,   658,   696,   736,   737,   738,   739,
     740,   741,   742,   743,   744,   783,   830,   872,   873,   874,
     875,   876,   877,   443,   482,   620,   661,   698,   753,   754,
     755,   756,   757,   758,   759,   760
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -91
static const yytype_int16 yypact[] =
{
      25,    38,    58,    10,   -91,   -91,    19,   -91,   -91,    77,
      48,   168,   -91,   175,    50,   -91,   -91,   -91,   -91,   -91,
     192,    54,   155,   -39,   -91,   -91,   197,    57,   -91,   -91,
     229,   241,    41,   243,   245,   247,   249,   251,    23,   100,
     -91,   -91,   253,   -91,   -91,   -91,   -91,   -91,   -91,   -91,
     -91,   -91,   -91,   -91,   -91,   -91,   -91,   -91,   -91,   -91,
     -91,   -91,   -91,   -91,   -91,   -91,   -91,   -91,   -91,   -91,
     -91,   -91,   114,    92,    98,   102,   255,   -91,   -91,   -91,
     -91,   -91,   -91,   -91,   -91,   -25,   -91,   -91,   -91,   -91,
       8,   -91,    17,   -91,   -91,   122,   135,    12,   -91,     4,
     -91,     7,   -91,     2,   -91,     1,   -91,   -91,   144,   141,
     152,   145,    22,   -91,   -91,   167,   178,   185,   194,   204,
     207,   206,   211,    -2,   -91,   -91,   148,   257,   -91,   -91,
     -91,   -91,   -91,   -48,   151,   157,   -91,   159,   -91,   214,
       6,   161,   -91,   147,   -91,   165,   -91,   171,   -91,   223,
     -91,   218,     0,   220,   -91,   180,   -91,   291,   -91,   292,
     262,   297,   264,   298,   266,   222,   -91,   304,   300,    -3,
     -91,   -91,   294,   271,   265,   295,   296,   299,   301,   302,
     303,   305,   306,   307,   308,   309,   287,   -91,   -91,   -91,
     -91,   -91,   -91,   -91,   -91,   -91,   -91,   -91,   -91,   -91,
     -91,   -91,   -91,   -91,   -91,   193,   -91,   312,   314,   318,
     -91,   -91,   -91,   -91,   -91,   -91,   -91,   -91,   263,   -91,
     -91,   -91,   -91,   -91,   -91,   -91,   256,   -91,   -91,   201,
     -91,   -91,   203,   -91,   252,   254,   -91,   258,   259,   -91,
     260,   261,   -91,   322,   -91,   248,   -91,   328,   325,   332,
     329,    -4,   -91,   333,   -91,   337,   -91,   338,   336,   342,
     339,   343,   340,   346,   344,   347,   345,   348,   349,   351,
     350,   352,   353,   356,   354,   357,   355,   326,   313,   237,
     359,   360,   361,   -91,   -91,   -91,   -91,   -91,   -91,   -91,
     -91,   -91,   -91,   -91,   -91,   -91,   -91,   -91,   205,   -91,
     362,   -91,   363,   367,   282,   -91,   366,   -46,   368,   -61,
     369,   -91,   370,   -91,   371,   -91,   372,   -91,   373,   -91,
     374,   -91,   375,   -91,   376,   -91,   377,   -91,   378,   -91,
     383,   273,   -91,   358,   239,   -91,   -91,   -91,    20,    83,
     -91,   -91,   -91,   -91,   209,   -91,   310,   -91,   -91,   379,
     -91,   -91,   -91,   -91,   380,   -91,   -91,   189,   -91,   -80,
     -91,     5,   -91,    -1,   -91,   -77,   -91,   -20,   -91,   -85,
     -91,   -90,   -91,   -86,   -91,   169,   384,   267,   -91,   -91,
     389,   281,   364,   250,   319,   -91,   391,   -91,   365,   -91,
     321,   -91,   396,   -91,   381,   -91,    86,   -91,   -91,   -91,
     -91,   397,   398,   -91,   392,   -91,   399,   -91,   -91,   400,
     -91,   -91,   401,   -91,   -91,   402,   -91,   -91,   -91,   -91,
     -91,   -91,   -91,   -91,   -91,   -91,   -91,   -91,   -91,   -91,
     -91,   403,   -91,   -91,   382,   330,   405,   275,   -91,   -91,
     410,   283,   388,   -91,   -91,   409,   414,   385,   -91,   411,
     417,   386,   387,   -91,   418,   -91,   390,   -91,    91,   393,
     324,   419,   420,   423,   425,   426,   173,   221,   224,   227,
     427,   429,   -91,   284,   -91,   404,   311,   428,   315,   -91,
     -91,   430,   431,   -91,   433,   434,   -91,   -91,   435,   438,
     -91,   -91,   436,   442,   394,   395,   -91,   443,   -91,   412,
     -91,   -91,   -91,   406,   407,   408,   413,   415,   416,   -91,
     444,   445,   446,   -91,   -91,   -91,   -91,   -91,   421,   -91,
     448,   450,   451,   -91,   -91,   -91,   -91,   -91,   422,   -91,
     453,   454,   455,   -91,   -91,   -91,   -91,   -91,   424,   -91,
     456,   457,   458,   -91,   -91,   -91,   -91,   -91,   316,   459,
      90,   -91,   461,   439,   432,   -91,   437,   327,   460,   -91,
     -91,   462,   -91,   463,   -91,   467,   472,   -91,   -91,   469,
     474,   440,   -91,   -91,   -91,   -91,   -91,   -91,   471,   475,
     476,   -91,   477,   478,   479,   -91,   480,   481,   482,   -91,
     483,   484,   485,   -91,   473,   441,   490,   491,   492,   493,
     494,   495,   496,   -91,   -91,   -91,   -91,   -91,   -91,   -91,
     -91,   -91,   501,   497,   -91,   334,   498,   468,   452,   -91,
     150,   -91,   -91,   -91,   502,   -91,   503,   499,   -91,   -91,
     -91,   -91,   -91,   -91,   -91,   -91,   -91,   -91,   -91,   -91,
     -91,   -91,   -91,   447,   505,   507,   508,   510,   511,   512,
     513,   517,   519,   110,   -91,   521,   526,   -91,   449,   -91,
     -91,   -91,   -91,   -91,   523,   172,    43,   -91,   -91,   -91,
     -91,   -91,   -91,   -91,   -91,   -91,   524,   464,   528,   530,
     531,   532,   533,   534,   535,   -91,   -91,   -91,   -91,   -91,
     -91,   -91,   -91,   -91,   536,   538,   116,   -91,   149,   -91,
     -91,   -91,   -91,   465,   -91,   537,   539,   540,   543,   -91,
     -91,   -91,   -91,   -91,   -91,   170,   -91,   -91,   486,   541,
     542,   544,   545,   546,   547,   548,   -91,   549,   466,   553,
     555,   556,   557,   558,   560,   561,   -91,   -91,   -91,   -91,
     -91,   -91,   -91,   -91,   -91,   470,   -91,   562,   564,   565,
     566,   567,   568,   -91,   -91,   -91,   -91,   -91,   -91,   -91,
     -91,   127,   -91,   569,   570,   571,   572,   -91,   -91,   -91,
     -30,    69,   -91,   -91,   -91,   -91,   -91,   -91,   -91,   -91,
     164,   -91,   -91,   504,   574,   575,   576,   577,   579,   580,
     581,   -91,   582,   583,   585,   586,   587,   589,   487,   -91,
     594,   595,   -91,   -91,   -91,   -91,   -91,   -91,   -91,   -91,
     153,   -91,   -91,   -91,   488,   -91,   596,   597,   598,   599,
     -91,   -91,   -91,   -91,   -91,   -91,   -91,   -91,   -91,     3,
      79,   -91,   -91,   -91,   -91,   -91,   -91,   -91,   -91,   -91,
     -91,   -91,   -91,   -91,   -91,   -91,   600,   601,   489,   -91,
     603,   606,   -91,   -91,   -91,   -91,   158,   -91,   604,   605,
     608,   610,   160,   -91,   -91,   -91,   500,   -91,   607,   615,
     616,   617,   -91,   -91,   -91,   -91,   -91,   -91,   -91,   -91,
     -91,   618,   619,   506,   -91,   620,   621,   -91,   -91,   -91,
     -91,   -91,   -91,   -91,   -91,   509,   -91,   624,   625,   -91,
     -91,   -91,   -91,   166,   -91,   622,   623,   626,   627,   -91,
     -91,   -91,   628,   629,   -91,   630,   632,   514,   -91,   638,
     639,   -91,   -91,   -91,   -91,   -91,   -91,   -91,   -91,   -91,
     -91,   -91,   -91,   -91,   636,   637,   -91,   -91
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
     -91,   -91,   -91,   -91,   -91,   -91
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint16 yytable[] =
{
     304,   245,   171,   165,   226,   149,   147,    71,   143,   424,
     218,   145,   135,   427,   421,   349,   141,   406,     6,     7,
     415,   137,   407,   125,   425,   172,   155,   422,   384,   385,
     428,   416,   107,   353,    72,     1,   354,   108,    73,   173,
      74,   174,    75,   175,    76,   176,   350,   177,   126,     4,
      94,   703,   704,   178,    95,   179,   386,   180,     5,   181,
     127,   182,     8,   183,   136,   184,   219,   185,   144,   186,
     148,   150,   227,   146,   142,   138,   156,   814,   815,   418,
     705,   706,   166,   246,   707,   708,   305,   866,   867,    12,
     419,   390,   391,    13,   452,   453,   412,    20,   595,   495,
     496,   811,   409,    26,   812,   413,   816,   817,    88,   410,
     818,   819,   596,   597,   598,   110,   868,   869,   677,   392,
     870,   871,   454,   599,   728,   139,   600,   497,   601,   115,
     602,   117,   678,   679,   680,   798,   799,   119,   729,   730,
     731,   121,   863,   140,   681,   864,   682,   151,   683,   152,
     684,   732,   733,   154,   734,   153,   735,   745,   746,   205,
     206,   848,   849,   167,   800,   801,   883,   884,   895,   896,
     157,   747,   748,   749,   917,   918,    15,    16,   207,   208,
     209,   508,   509,    18,    19,   750,   158,   751,   159,   752,
     850,   851,   510,   511,   512,   885,   886,   897,   898,    28,
      24,    25,   160,   919,   920,    86,    87,   161,    29,   163,
      30,   221,    31,   215,    32,   162,    33,   216,    34,   164,
      35,   217,    36,   220,    37,   225,    38,   228,    39,   518,
     519,   222,   528,   529,   230,   538,   539,    90,    91,   223,
     520,   521,   522,   530,   531,   532,   540,   541,   542,    92,
      93,    97,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   112,   113,   123,   124,   169,   170,   234,   235,   237,
     238,   240,   241,   251,   252,   285,   286,   288,   289,   340,
     341,   377,   378,   397,   398,   403,   404,   430,   431,   437,
     438,   478,   479,   224,   659,   660,   700,   701,   231,   233,
     767,   768,   826,   827,   236,   239,   242,   243,   244,   247,
     249,   253,   275,   255,   277,   280,   257,   281,   259,   261,
     263,   282,   265,   283,   267,   269,   271,   273,   284,   297,
     291,   300,   292,   301,   299,   302,   306,   303,   293,   294,
     308,   310,   295,   296,   311,   312,   314,   313,   315,   316,
     318,   320,   317,   319,   322,   324,   330,   321,   323,   326,
     328,   325,   327,   329,   333,   332,   335,   336,   337,   343,
     345,   346,   347,   348,   382,   352,   356,   358,   360,   362,
     364,   366,   368,   370,   372,   374,   376,   401,   402,   380,
     434,   433,   436,   442,   445,   444,   440,   448,   400,   449,
     461,   459,   460,   446,   475,   472,   551,   462,   463,   464,
     465,   470,   474,   477,   481,   471,   483,   484,   487,   450,
     488,   492,   502,   503,   504,   485,   489,   505,   493,   506,
     507,   548,   549,   558,   566,   555,   593,   561,   552,   559,
     560,   563,   562,   564,   553,   565,   569,   578,   579,   580,
     570,   582,   556,   583,   584,   501,   586,   587,   588,   590,
     591,   592,   654,   491,   612,     0,   594,   619,   617,   621,
     622,   568,   616,   613,   623,   624,   625,   626,   629,     0,
     627,   641,   630,   631,   632,   633,   634,   635,   636,   637,
     638,   639,   640,   644,   645,   646,   647,   648,   649,   650,
     652,   655,   664,   656,   572,   573,   574,   614,   651,   662,
     663,   575,   668,   576,   669,   670,   577,   671,   672,   673,
     674,   581,   585,   667,   589,   675,   676,   657,   694,   695,
     699,   719,   716,   720,   721,   722,   723,   724,   725,     0,
     763,     0,   764,   765,   726,   727,   766,     0,   773,   774,
       0,   775,   776,   777,   778,   779,   784,   781,   785,   786,
     787,   788,   772,   789,   790,   792,   642,   793,   794,   795,
     796,   797,     0,     0,     0,     0,   806,   807,   808,   809,
     831,   832,   833,   834,   835,   697,   836,   837,   838,   839,
     840,   762,   841,   842,   843,   717,   844,   846,   847,   858,
     859,   860,   861,     0,     0,   782,   881,   878,   879,   882,
     905,   891,   892,   845,   857,   893,   791,   894,   906,   907,
     908,   880,     0,   912,   913,   909,   910,   915,   916,   925,
     926,     0,     0,   927,   928,   929,   930,   931,   911,   932,
     904,   934,   935,   936,   937,     0,     0,     0,     0,   914,
       0,     0,     0,     0,   933
};

static const yytype_int16 yycheck[] =
{
       4,     4,    50,     5,     4,     4,     4,    46,     4,    99,
       4,     4,     4,    99,    99,    61,     4,    97,     8,     9,
      97,     4,   102,    48,   114,    73,     4,   112,     8,     9,
     116,   108,     9,    94,    73,    10,    97,    14,    77,    87,
      79,    89,    81,    91,    83,    93,    92,    95,    73,    11,
       9,     8,     9,   101,    13,   103,    36,   105,     0,   107,
      85,   109,    43,   111,    56,   113,    60,   115,    64,   117,
      68,    70,    72,    66,    62,    58,    54,     8,     9,    99,
      37,    38,    84,    86,    41,    42,    90,     8,     9,    12,
     110,     8,     9,    45,     8,     9,    97,    47,     8,     8,
       9,   131,    97,    49,   134,   106,    37,    38,    51,   104,
      41,    42,    22,    23,    24,    15,    37,    38,     8,    36,
      41,    42,    36,    33,     8,     3,    36,    36,    38,    15,
      40,    39,    22,    23,    24,     8,     9,    39,    22,    23,
      24,    39,   139,     8,    34,   142,    36,     3,    38,     8,
      40,    35,    36,     8,    38,     3,    40,     8,     9,     8,
       9,     8,     9,    15,    37,    38,     8,     9,     8,     9,
       3,    22,    23,    24,     8,     9,     8,     9,    27,    28,
      29,     8,     9,     8,     9,    36,     8,    38,     3,    40,
      37,    38,    19,    20,    21,    37,    38,    37,    38,    44,
       8,     9,     8,    37,    38,     8,     9,     3,    53,     3,
      55,    64,    57,    56,    59,     8,    61,    58,    63,     8,
      65,     7,    67,    62,    69,     7,    71,     7,    73,     8,
       9,    66,     8,     9,    54,     8,     9,     8,     9,    68,
      19,    20,    21,    19,    20,    21,    19,    20,    21,     8,
       9,     8,     9,     8,     9,     8,     9,     8,     9,     8,
       9,     8,     9,     8,     9,     8,     9,     5,     6,     5,
       6,     5,     6,     8,     9,    74,    75,    74,    75,    74,
      75,     8,     9,    74,    75,    96,    97,   118,   119,     8,
       9,     8,     9,    70,   144,   145,   124,   125,     7,     7,
     130,   131,   138,   139,     7,     7,    84,     3,     8,    15,
      39,    16,    25,    17,   121,     3,    17,     3,    17,    17,
      17,     3,    17,    60,    18,    18,    18,    18,    72,     7,
      78,     3,    78,     8,    86,     3,     3,     8,    80,    80,
       3,     3,    82,    82,     8,     3,     3,     8,     8,     3,
       3,     3,     8,     8,     3,     3,    30,     8,     8,     3,
       3,     8,     8,     8,   127,    52,     7,     7,     7,     7,
       7,     4,    90,     7,   135,     7,     7,     7,     7,     7,
       7,     7,     7,     7,     7,     7,     3,     8,     8,    31,
     123,     7,     3,   143,     3,    76,    32,    76,    88,     3,
       8,     4,     4,    38,   129,    75,   122,     8,     8,     8,
       8,     8,     7,     3,    26,    33,     7,     3,     7,    38,
       3,     3,    98,     4,     4,    40,    40,     4,    38,     4,
       4,     4,     3,     3,    40,     7,   120,     3,    34,     8,
       7,     3,     7,     7,   133,     3,     3,     3,     3,     3,
      38,     3,   137,     3,     3,    62,     3,     3,     3,     3,
       3,     3,   128,    76,     3,    -1,     7,     7,   141,     7,
       7,    76,    35,    34,     7,     3,     7,     3,     7,    -1,
      40,     8,     7,     7,     7,     7,     7,     7,     7,     7,
       7,     7,     7,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,    35,    98,    98,    98,    75,     7,     7,
       7,    98,     7,    98,     7,     7,   100,     7,     7,     7,
       7,   100,   100,    76,   100,     8,     7,    75,     7,     3,
       7,     3,     8,     3,     3,     3,     3,     3,     3,    -1,
       3,    -1,     3,     3,     8,     7,     3,    -1,     7,     7,
      -1,     7,     7,     7,     7,     7,     3,     8,     3,     3,
       3,     3,    76,     3,     3,     3,   125,     3,     3,     3,
       3,     3,    -1,    -1,    -1,    -1,     7,     7,     7,     7,
      76,     7,     7,     7,     7,   136,     7,     7,     7,     7,
       7,   126,     7,     7,     7,   131,     7,     3,     3,     3,
       3,     3,     3,    -1,    -1,   139,     3,     7,     7,     3,
       3,     7,     7,   126,   126,     7,   146,     7,     3,     3,
       3,   132,    -1,     3,     3,     7,     7,     3,     3,     7,
       7,    -1,    -1,     7,     7,     7,     7,     7,   132,     7,
     140,     3,     3,     7,     7,    -1,    -1,    -1,    -1,   140,
      -1,    -1,    -1,    -1,   140
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,    10,   149,   150,    11,     0,     8,     9,    43,   151,
     152,   153,    12,    45,   199,     8,     9,   154,     8,     9,
      47,   221,   155,   200,     8,     9,    49,   237,    44,    53,
      55,    57,    59,    61,    63,    65,    67,    69,    71,    73,
     156,   157,   158,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     189,    46,    73,    77,    79,    81,    83,   201,   202,   204,
     206,   208,   209,   210,   211,   222,     8,     9,    51,   327,
       8,     9,     8,     9,     9,    13,   169,     8,     9,     8,
       9,     8,     9,     8,     9,     8,     9,     9,    14,   188,
      15,   190,     8,     9,   159,    15,   212,    39,   203,    39,
     205,    39,   207,     8,     9,    48,    73,    85,   223,   224,
     225,   226,   227,   238,   328,     4,    56,     4,    58,     3,
       8,     4,    62,     4,    64,     4,    66,     4,    68,     4,
      70,     3,     8,     3,     8,     4,    54,     3,     8,     3,
       8,     3,     8,     3,     8,     5,    84,    15,   228,     8,
       9,    50,    73,    87,    89,    91,    93,    95,   101,   103,
     105,   107,   109,   111,   113,   115,   117,   239,   240,   242,
     243,   244,   245,   249,   253,   257,   261,   265,   275,   285,
     295,   305,   309,   313,   317,     8,     9,    27,    28,    29,
     329,   330,   331,   332,   333,    56,    58,     7,     4,    60,
      62,    64,    66,    68,    70,     7,     4,    72,     7,   191,
      54,     7,   213,     7,     5,     6,     7,     5,     6,     7,
       5,     6,    84,     3,     8,     4,    86,    15,   318,    39,
     241,     8,     9,    16,   246,    17,   250,    17,   254,    17,
     258,    17,   262,    17,   310,    17,   306,    18,   266,    18,
     276,    18,   286,    18,   296,    25,   314,   121,   334,   335,
       3,     3,     3,    60,    72,    74,    75,   192,    74,    75,
     214,    78,    78,    80,    80,    82,    82,     7,   229,    86,
       3,     8,     3,     8,     4,    90,     3,   247,     3,   251,
       3,     8,     3,     8,     3,     8,     3,     8,     3,     8,
       3,     8,     3,     8,     3,     8,     3,     8,     3,     8,
      30,   336,    52,   127,   365,     7,     7,     7,   193,   215,
      74,    75,   230,     7,   319,     7,     4,    90,     7,    61,
      92,   248,     7,    94,    97,   252,     7,   255,     7,   259,
       7,   263,     7,   311,     7,   307,     7,   267,     7,   277,
       7,   287,     7,   297,     7,   315,     3,     8,     9,   337,
      31,   366,   135,   403,     8,     9,    36,   194,   195,   198,
       8,     9,    36,   216,   217,   220,   231,    74,    75,   320,
      88,     8,     8,    96,    97,   256,    97,   102,   260,    97,
     104,   264,    97,   106,   312,    97,   108,   308,    99,   110,
     268,    99,   112,   278,    99,   114,   288,    99,   116,   298,
     118,   119,   316,     7,   123,   338,     3,     8,     9,   367,
      32,   404,   143,   441,    76,     3,    38,   196,    76,     3,
      38,   218,     8,     9,    36,   232,   233,   236,   321,     4,
       4,     8,     8,     8,     8,     8,   269,   279,   289,   299,
       8,    33,    75,   346,     7,   129,   368,     3,     8,     9,
     405,    26,   442,     7,     3,    40,   197,     7,     3,    40,
     219,    76,     3,    38,   234,     8,     9,    36,   322,   323,
     326,    62,    98,     4,     4,     4,     4,     4,     8,     9,
      19,    20,    21,   270,   271,   272,   273,   274,     8,     9,
      19,    20,    21,   280,   281,   282,   283,   284,     8,     9,
      19,    20,    21,   290,   291,   292,   293,   294,     8,     9,
      19,    20,    21,   300,   301,   302,   303,   304,     4,     3,
     347,   122,    34,   133,   376,     7,   137,   406,     3,     8,
       7,     3,     7,     3,     7,     3,    40,   235,    76,     3,
      38,   324,    98,    98,    98,    98,    98,   100,     3,     3,
       3,   100,     3,     3,     3,   100,     3,     3,     3,   100,
       3,     3,     3,   120,     7,     8,    22,    23,    24,    33,
      36,    38,    40,   348,   349,   350,   351,   352,   353,   354,
     355,   356,     3,    34,    75,   384,    35,   141,   414,     7,
     443,     7,     7,     7,     3,     7,     3,    40,   325,     7,
       7,     7,     7,     7,     7,     7,     7,     7,     7,     7,
       7,     8,   125,   357,     3,     3,     3,     3,     3,     3,
       3,     7,     3,   385,   128,     3,    35,    75,   422,   144,
     145,   444,     7,     7,     3,   339,   358,    76,     7,     7,
       7,     7,     7,     7,     7,     8,     7,     8,    22,    23,
      24,    34,    36,    38,    40,   386,   387,   388,   389,   390,
     391,   392,   393,   394,     7,     3,   423,   136,   445,     7,
     124,   125,   340,     8,     9,    37,    38,    41,    42,   359,
     360,   361,   362,   363,   364,   369,     8,   131,   395,     3,
       3,     3,     3,     3,     3,     3,     8,     7,     8,    22,
      23,    24,    35,    36,    38,    40,   424,   425,   426,   427,
     428,   429,   430,   431,   432,     8,     9,    22,    23,    24,
      36,    38,    40,   446,   447,   448,   449,   450,   451,   452,
     453,   341,   126,     3,     3,     3,     3,   130,   131,   370,
     377,   396,    76,     7,     7,     7,     7,     7,     7,     7,
     407,     8,   139,   433,     3,     3,     3,     3,     3,     3,
       3,   146,     3,     3,     3,     3,     3,     3,     8,     9,
      37,    38,   342,   343,   344,   345,     7,     7,     7,     7,
     371,   131,   134,   378,     8,     9,    37,    38,    41,    42,
     397,   398,   399,   400,   401,   402,   138,   139,   408,   415,
     434,    76,     7,     7,     7,     7,     7,     7,     7,     7,
       7,     7,     7,     7,     7,   126,     3,     3,     8,     9,
      37,    38,   372,   373,   374,   375,   379,   126,     3,     3,
       3,     3,   409,   139,   142,   416,     8,     9,    37,    38,
      41,    42,   435,   436,   437,   438,   439,   440,     7,     7,
     132,     3,     3,     8,     9,    37,    38,   380,   381,   382,
     383,     7,     7,     7,     7,     8,     9,    37,    38,   410,
     411,   412,   413,   417,   140,     3,     3,     3,     3,     7,
       7,   132,     3,     3,   140,     3,     3,     8,     9,    37,
      38,   418,   419,   420,   421,     7,     7,     7,     7,     7,
       7,     7,     7,   140,     3,     3,     7,     7
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
	printf("%s","serviceURI found\n");
}
    break;

  case 29:

    {
osoption->general->serviceURI = (yyvsp[(2) - (3)].sval);//free($2);
printf("%s","\n$2 contains: ");printf("%s",(yyvsp[(2) - (3)].sval));printf("%s","\n");
}
    break;

  case 33:

    {
}
    break;

  case 34:

    {
}
    break;

  case 38:

    {
}
    break;

  case 39:

    {
}
    break;

  case 43:

    {
}
    break;

  case 44:

    {
}
    break;

  case 46:

    {
}
    break;

  case 50:

    {
}
    break;

  case 51:

    {
}
    break;

  case 55:

    {
}
    break;

  case 56:

    {
}
    break;

  case 60:

    {
}
    break;

  case 61:

    {
}
    break;

  case 65:

    {
}
    break;

  case 66:

    {
}
    break;

  case 70:

    {
}
    break;

  case 71:

    {
}
    break;

  case 75:

    {
}
    break;

  case 76:

    {
}
    break;

  case 78:

    {
printf("TRANSSPORT ATTRIBUTE TEXT =  %s",(yyvsp[(2) - (3)].sval));printf("%s","\n");
}
    break;

  case 80:

    {
}
    break;

  case 87:

    {
}
    break;

  case 89:

    {
}
    break;

  case 91:

    {
}
    break;

  case 93:

    {
}
    break;

  case 105:

    {
}
    break;

  case 107:

    {
}
    break;

  case 109:

    {
}
    break;

  case 111:

    {
}
    break;

  case 113:

    {
}
    break;

  case 115:

    {
}
    break;

  case 119:

    {
}
    break;

  case 120:

    {
}
    break;

  case 122:

    {
}
    break;

  case 129:

    {
}
    break;

  case 131:

    {
}
    break;

  case 133:

    {
}
    break;

  case 135:

    {
}
    break;

  case 146:

    {
}
    break;

  case 147:

    {
}
    break;

  case 149:

    {
}
    break;

  case 156:

    {
}
    break;

  case 158:

    {
}
    break;

  case 160:

    {
}
    break;

  case 162:

    {
}
    break;

  case 183:

    {
}
    break;

  case 185:

    {
}
    break;

  case 189:

    {
}
    break;

  case 190:

    {
}
    break;

  case 192:

    {
}
    break;

  case 195:

    {
}
    break;

  case 197:

    {
}
    break;

  case 200:

    {
}
    break;

  case 202:

    {
}
    break;

  case 205:

    {
}
    break;

  case 207:

    {
}
    break;

  case 210:

    {
}
    break;

  case 212:

    {
}
    break;

  case 215:

    {
}
    break;

  case 217:

    {
}
    break;

  case 220:

    {
}
    break;

  case 226:

    {
}
    break;

  case 227:

    {
}
    break;

  case 228:

    {
}
    break;

  case 232:

    {
}
    break;

  case 235:

    {
}
    break;

  case 241:

    {
}
    break;

  case 242:

    {
}
    break;

  case 243:

    {
}
    break;

  case 247:

    {
}
    break;

  case 250:

    {
}
    break;

  case 256:

    {
}
    break;

  case 257:

    {
}
    break;

  case 258:

    {
}
    break;

  case 262:

    {
}
    break;

  case 265:

    {
}
    break;

  case 271:

    {
}
    break;

  case 272:

    {
}
    break;

  case 273:

    {
}
    break;

  case 277:

    {
}
    break;

  case 280:

    {
}
    break;

  case 282:

    {
}
    break;

  case 285:

    {
}
    break;

  case 287:

    {
}
    break;

  case 290:

    {
}
    break;

  case 292:

    {
}
    break;

  case 299:

    {
}
    break;

  case 301:

    {
}
    break;

  case 303:

    {
}
    break;

  case 305:

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

  case 315:

    {
}
    break;

  case 322:

    {
}
    break;

  case 334:

    {
}
    break;

  case 335:

    {
}
    break;

  case 349:

    {
}
    break;

  case 350:

    {
}
    break;

  case 351:

    {
}
    break;

  case 352:

    {
}
    break;

  case 353:

    {
}
    break;

  case 354:

    {
}
    break;

  case 355:

    {
}
    break;

  case 364:

    {
}
    break;

  case 365:

    {
}
    break;

  case 366:

    {
}
    break;

  case 367:

    {
}
    break;

  case 373:

    {
}
    break;

  case 385:

    {
}
    break;

  case 386:

    {
}
    break;

  case 398:

    {
}
    break;

  case 399:

    {
}
    break;

  case 413:

    {
}
    break;

  case 414:

    {
}
    break;

  case 415:

    {
}
    break;

  case 416:

    {
}
    break;

  case 417:

    {
}
    break;

  case 418:

    {
}
    break;

  case 419:

    {
}
    break;

  case 428:

    {
}
    break;

  case 429:

    {
}
    break;

  case 430:

    {
}
    break;

  case 431:

    {
}
    break;

  case 437:

    {
}
    break;

  case 449:

    {
}
    break;

  case 450:

    {
}
    break;

  case 462:

    {
}
    break;

  case 463:

    {
}
    break;

  case 477:

    {
}
    break;

  case 478:

    {
}
    break;

  case 479:

    {
}
    break;

  case 480:

    {
}
    break;

  case 481:

    {
}
    break;

  case 482:

    {
}
    break;

  case 483:

    {
}
    break;

  case 492:

    {
}
    break;

  case 493:

    {
}
    break;

  case 494:

    {
}
    break;

  case 495:

    {
}
    break;

  case 500:

    {
}
    break;

  case 512:

    {
}
    break;

  case 513:

    {
}
    break;

  case 514:

    {
}
    break;

  case 515:

    {
}
    break;

  case 516:

    {
}
    break;

  case 517:

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


