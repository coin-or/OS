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
#define YYLAST   655

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  148
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  304
/* YYNRULES -- Number of rules.  */
#define YYNRULES  517
/* YYNRULES -- Number of states.  */
#define YYNSTATES  936

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
       0,     0,     3,     8,    11,    13,    16,    22,    23,    28,
      31,    32,    35,    37,    39,    41,    43,    45,    47,    49,
      51,    53,    55,    57,    59,    61,    64,    68,    73,    75,
      77,    80,    84,    89,    91,    93,    96,   100,   105,   107,
     109,   112,   117,   123,   124,   128,   130,   132,   135,   139,
     144,   146,   148,   151,   155,   160,   162,   164,   167,   171,
     176,   178,   180,   183,   187,   192,   194,   196,   199,   203,
     208,   210,   212,   215,   220,   226,   227,   231,   237,   241,
     242,   245,   249,   250,   253,   257,   261,   262,   266,   267,
     271,   273,   276,   277,   282,   285,   286,   289,   291,   293,
     295,   297,   299,   305,   311,   312,   316,   322,   328,   329,
     333,   339,   345,   346,   350,   352,   354,   357,   361,   366,
     372,   376,   377,   380,   384,   385,   388,   392,   396,   397,
     401,   402,   406,   408,   411,   412,   417,   420,   421,   424,
     426,   428,   430,   432,   435,   439,   444,   450,   454,   455,
     458,   462,   463,   466,   470,   474,   475,   479,   480,   484,
     486,   489,   490,   495,   498,   499,   502,   504,   506,   508,
     510,   512,   514,   516,   518,   520,   522,   524,   526,   528,
     530,   532,   538,   539,   543,   545,   547,   550,   554,   559,
     564,   568,   569,   572,   577,   582,   586,   587,   590,   595,
     601,   605,   606,   609,   614,   620,   624,   625,   628,   633,
     639,   643,   644,   647,   652,   658,   662,   663,   666,   670,
     671,   674,   676,   678,   680,   684,   688,   692,   695,   697,
     703,   707,   708,   711,   715,   716,   719,   721,   723,   725,
     729,   733,   737,   740,   742,   748,   752,   753,   756,   760,
     761,   764,   766,   768,   770,   774,   778,   782,   785,   787,
     793,   797,   798,   801,   805,   806,   809,   811,   813,   815,
     819,   823,   827,   830,   832,   838,   842,   843,   846,   851,
     857,   861,   862,   865,   870,   876,   880,   881,   884,   889,
     895,   899,   900,   903,   907,   908,   911,   915,   919,   920,
     924,   925,   929,   931,   934,   935,   939,   940,   943,   945,
     947,   949,   953,   957,   961,   965,   967,   972,   973,   977,
     978,   982,   987,   989,   990,   998,   999,  1002,  1006,  1007,
    1010,  1012,  1014,  1018,  1022,  1025,  1027,  1028,  1032,  1033,
    1036,  1038,  1040,  1042,  1044,  1046,  1048,  1050,  1054,  1058,
    1062,  1066,  1070,  1074,  1078,  1082,  1086,  1087,  1090,  1092,
    1094,  1096,  1098,  1102,  1106,  1110,  1114,  1117,  1119,  1120,
    1124,  1125,  1129,  1135,  1137,  1138,  1146,  1147,  1150,  1154,
    1155,  1158,  1160,  1162,  1166,  1170,  1173,  1175,  1176,  1184,
    1185,  1188,  1192,  1193,  1196,  1198,  1200,  1204,  1208,  1211,
    1213,  1214,  1218,  1219,  1222,  1224,  1226,  1228,  1230,  1232,
    1234,  1236,  1240,  1244,  1248,  1252,  1256,  1260,  1264,  1268,
    1272,  1273,  1276,  1278,  1280,  1282,  1284,  1288,  1292,  1296,
    1300,  1303,  1305,  1306,  1310,  1311,  1315,  1321,  1323,  1324,
    1332,  1333,  1336,  1340,  1341,  1344,  1346,  1348,  1352,  1356,
    1359,  1361,  1362,  1370,  1371,  1374,  1378,  1379,  1382,  1384,
    1386,  1390,  1394,  1397,  1399,  1400,  1404,  1405,  1408,  1410,
    1412,  1414,  1416,  1418,  1420,  1422,  1426,  1430,  1434,  1438,
    1442,  1446,  1450,  1454,  1458,  1459,  1462,  1464,  1466,  1468,
    1470,  1474,  1478,  1482,  1486,  1489,  1491,  1492,  1498,  1502,
    1503,  1506,  1510,  1511,  1514,  1516,  1518,  1520,  1522,  1524,
    1526,  1530,  1534,  1538,  1542,  1546,  1550,  1553
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     149,     0,    -1,   150,     8,   151,    12,    -1,   150,     9,
      -1,    10,    -1,    10,    11,    -1,   152,   197,   219,   235,
     325,    -1,    -1,    43,     8,   153,    44,    -1,    43,     9,
      -1,    -1,   153,   154,    -1,   155,    -1,   158,    -1,   161,
      -1,   164,    -1,   168,    -1,   171,    -1,   174,    -1,   177,
      -1,   180,    -1,   183,    -1,   187,    -1,   156,    -1,   157,
      -1,    53,     9,    -1,    53,     8,    54,    -1,    53,     8,
       4,    54,    -1,   159,    -1,   160,    -1,    55,     9,    -1,
      55,     8,    56,    -1,    55,     8,     4,    56,    -1,   162,
      -1,   163,    -1,    57,     9,    -1,    57,     8,    58,    -1,
      57,     8,     4,    58,    -1,   165,    -1,   166,    -1,    59,
       9,    -1,    59,   167,     8,    60,    -1,    59,   167,     8,
       4,    60,    -1,    -1,    13,     3,     7,    -1,   169,    -1,
     170,    -1,    61,     9,    -1,    61,     8,    62,    -1,    61,
       8,     4,    62,    -1,   172,    -1,   173,    -1,    63,     9,
      -1,    63,     8,    64,    -1,    63,     8,     4,    64,    -1,
     175,    -1,   176,    -1,    65,     9,    -1,    65,     8,    66,
      -1,    65,     8,     4,    66,    -1,   178,    -1,   179,    -1,
      67,     9,    -1,    67,     8,    68,    -1,    67,     8,     4,
      68,    -1,   181,    -1,   182,    -1,    69,     9,    -1,    69,
       8,    70,    -1,    69,     8,     4,    70,    -1,   184,    -1,
     185,    -1,    71,     9,    -1,    71,   186,     8,    72,    -1,
      71,   186,     8,     4,    72,    -1,    -1,    14,     3,     7,
      -1,    73,   188,     8,   189,    74,    -1,    15,     3,     7,
      -1,    -1,   189,   190,    -1,    75,   191,   196,    -1,    -1,
     191,   192,    -1,   193,   194,   195,    -1,    36,     3,     7,
      -1,    -1,    38,     3,     7,    -1,    -1,    40,     3,     7,
      -1,     9,    -1,     8,    76,    -1,    -1,    45,     8,   198,
      46,    -1,    45,     9,    -1,    -1,   198,   199,    -1,   200,
      -1,   202,    -1,   204,    -1,   206,    -1,   209,    -1,    77,
     201,     8,     6,    78,    -1,    77,   201,     8,     5,    78,
      -1,    -1,    39,     3,     7,    -1,    79,   203,     8,     6,
      80,    -1,    79,   203,     8,     5,    80,    -1,    -1,    39,
       3,     7,    -1,    81,   205,     8,     6,    82,    -1,    81,
     205,     8,     5,    82,    -1,    -1,    39,     3,     7,    -1,
     207,    -1,   208,    -1,    83,     9,    -1,    83,     8,    84,
      -1,    83,     8,     5,    84,    -1,    73,   210,     8,   211,
      74,    -1,    15,     3,     7,    -1,    -1,   211,   212,    -1,
      75,   213,   218,    -1,    -1,   213,   214,    -1,   215,   216,
     217,    -1,    36,     3,     7,    -1,    -1,    38,     3,     7,
      -1,    -1,    40,     3,     7,    -1,     9,    -1,     8,    76,
      -1,    -1,    47,     8,   220,    48,    -1,    47,     9,    -1,
      -1,   220,   221,    -1,   222,    -1,   225,    -1,   223,    -1,
     224,    -1,    85,     9,    -1,    85,     8,    86,    -1,    85,
       8,     4,    86,    -1,    73,   226,     8,   227,    74,    -1,
      15,     3,     7,    -1,    -1,   227,   228,    -1,    75,   229,
     234,    -1,    -1,   229,   230,    -1,   231,   232,   233,    -1,
      36,     3,     7,    -1,    -1,    38,     3,     7,    -1,    -1,
      40,     3,     7,    -1,     9,    -1,     8,    76,    -1,    -1,
      49,     8,   236,    50,    -1,    49,     9,    -1,    -1,   236,
     237,    -1,   238,    -1,   240,    -1,   243,    -1,   247,    -1,
     251,    -1,   255,    -1,   259,    -1,   263,    -1,   273,    -1,
     283,    -1,   293,    -1,   303,    -1,   307,    -1,   311,    -1,
     315,    -1,    87,   239,     8,     4,    88,    -1,    -1,    39,
       3,     7,    -1,   241,    -1,   242,    -1,    89,     9,    -1,
      89,     8,    90,    -1,    89,     8,     4,    90,    -1,    91,
     244,   245,    92,    -1,    16,     3,     7,    -1,    -1,   245,
     246,    -1,    61,     8,     4,    62,    -1,    93,   248,   249,
      94,    -1,    17,     3,     7,    -1,    -1,   249,   250,    -1,
      97,     8,     4,    98,    -1,    95,   252,     8,   253,    96,
      -1,    17,     3,     7,    -1,    -1,   253,   254,    -1,    97,
       8,     4,    98,    -1,   101,   256,     8,   257,   102,    -1,
      17,     3,     7,    -1,    -1,   257,   258,    -1,    97,     8,
       4,    98,    -1,   103,   260,     8,   261,   104,    -1,    17,
       3,     7,    -1,    -1,   261,   262,    -1,    97,     8,     4,
      98,    -1,   109,   264,     8,   265,   110,    -1,    18,     3,
       7,    -1,    -1,   265,   266,    -1,    99,   267,   272,    -1,
      -1,   267,   268,    -1,   269,    -1,   270,    -1,   271,    -1,
      19,     3,     7,    -1,    20,     3,     7,    -1,    21,     3,
       7,    -1,     8,   100,    -1,     9,    -1,   111,   274,     8,
     275,   112,    -1,    18,     3,     7,    -1,    -1,   275,   276,
      -1,    99,   277,   282,    -1,    -1,   277,   278,    -1,   279,
      -1,   280,    -1,   281,    -1,    19,     3,     7,    -1,    20,
       3,     7,    -1,    21,     3,     7,    -1,     8,   100,    -1,
       9,    -1,   113,   284,     8,   285,   114,    -1,    18,     3,
       7,    -1,    -1,   285,   286,    -1,    99,   287,   292,    -1,
      -1,   287,   288,    -1,   289,    -1,   290,    -1,   291,    -1,
      19,     3,     7,    -1,    20,     3,     7,    -1,    21,     3,
       7,    -1,     8,   100,    -1,     9,    -1,   115,   294,     8,
     295,   116,    -1,    18,     3,     7,    -1,    -1,   295,   296,
      -1,    99,   297,   302,    -1,    -1,   297,   298,    -1,   299,
      -1,   300,    -1,   301,    -1,    19,     3,     7,    -1,    20,
       3,     7,    -1,    21,     3,     7,    -1,     8,   100,    -1,
       9,    -1,   107,   304,     8,   305,   108,    -1,    17,     3,
       7,    -1,    -1,   305,   306,    -1,    97,     8,     4,    98,
      -1,   105,   308,     8,   309,   106,    -1,    17,     3,     7,
      -1,    -1,   309,   310,    -1,    97,     8,     4,    98,    -1,
     117,   312,     8,   313,   118,    -1,    25,     3,     7,    -1,
      -1,   313,   314,    -1,   119,     8,     4,   120,    -1,    73,
     316,     8,   317,    74,    -1,    15,     3,     7,    -1,    -1,
     317,   318,    -1,    75,   319,   324,    -1,    -1,   319,   320,
      -1,   321,   322,   323,    -1,    36,     3,     7,    -1,    -1,
      38,     3,     7,    -1,    -1,    40,     3,     7,    -1,     9,
      -1,     8,    76,    -1,    -1,    51,   326,   331,    -1,    -1,
     326,   327,    -1,   328,    -1,   329,    -1,   330,    -1,    27,
       3,     7,    -1,    29,     3,     7,    -1,    28,     3,     7,
      -1,     8,   332,    52,    -1,     9,    -1,   333,   363,   401,
     439,    -1,    -1,   121,   334,   335,    -1,    -1,    30,     3,
       7,    -1,     8,   336,   344,   122,    -1,     9,    -1,    -1,
     123,    33,     3,     7,     8,   337,   124,    -1,    -1,   337,
     338,    -1,   125,   339,   343,    -1,    -1,   339,   340,    -1,
     341,    -1,   342,    -1,    37,     3,     7,    -1,    38,     3,
       7,    -1,     8,   126,    -1,     9,    -1,    -1,    75,   345,
     354,    -1,    -1,   345,   346,    -1,   347,    -1,   348,    -1,
     349,    -1,   350,    -1,   351,    -1,   352,    -1,   353,    -1,
      33,     3,     7,    -1,    36,     3,     7,    -1,    38,     3,
       7,    -1,    22,     3,     7,    -1,    23,     3,     7,    -1,
      24,     3,     7,    -1,    40,     3,     7,    -1,     8,   355,
      76,    -1,   125,   356,   362,    -1,    -1,   356,   357,    -1,
     358,    -1,   359,    -1,   360,    -1,   361,    -1,    37,     3,
       7,    -1,    38,     3,     7,    -1,    41,     3,     7,    -1,
      42,     3,     7,    -1,     8,   126,    -1,     9,    -1,    -1,
     127,   364,   365,    -1,    -1,    31,     3,     7,    -1,     8,
     366,   374,   382,   128,    -1,     9,    -1,    -1,   129,    34,
       3,     7,     8,   367,   130,    -1,    -1,   367,   368,    -1,
     131,   369,   373,    -1,    -1,   369,   370,    -1,   371,    -1,
     372,    -1,    37,     3,     7,    -1,    38,     3,     7,    -1,
       8,   132,    -1,     9,    -1,    -1,   133,    34,     3,     7,
       8,   375,   134,    -1,    -1,   375,   376,    -1,   131,   377,
     381,    -1,    -1,   377,   378,    -1,   379,    -1,   380,    -1,
      37,     3,     7,    -1,    38,     3,     7,    -1,     8,   132,
      -1,     9,    -1,    -1,    75,   383,   392,    -1,    -1,   383,
     384,    -1,   385,    -1,   386,    -1,   387,    -1,   388,    -1,
     389,    -1,   390,    -1,   391,    -1,    34,     3,     7,    -1,
      36,     3,     7,    -1,    38,     3,     7,    -1,    22,     3,
       7,    -1,    23,     3,     7,    -1,    24,     3,     7,    -1,
      40,     3,     7,    -1,     8,   393,    76,    -1,   131,   394,
     400,    -1,    -1,   394,   395,    -1,   396,    -1,   397,    -1,
     398,    -1,   399,    -1,    37,     3,     7,    -1,    38,     3,
       7,    -1,    41,     3,     7,    -1,    42,     3,     7,    -1,
       8,   126,    -1,     9,    -1,    -1,   135,   402,   403,    -1,
      -1,    32,     3,     7,    -1,     8,   404,   412,   420,   136,
      -1,     9,    -1,    -1,   137,    35,     3,     7,     8,   405,
     138,    -1,    -1,   405,   406,    -1,   139,   407,   411,    -1,
      -1,   407,   408,    -1,   409,    -1,   410,    -1,    37,     3,
       7,    -1,    38,     3,     7,    -1,     8,   140,    -1,     9,
      -1,    -1,   141,    35,     3,     7,     8,   413,   142,    -1,
      -1,   413,   414,    -1,   139,   415,   419,    -1,    -1,   415,
     416,    -1,   417,    -1,   418,    -1,    37,     3,     7,    -1,
      38,     3,     7,    -1,     8,   140,    -1,     9,    -1,    -1,
      75,   421,   430,    -1,    -1,   421,   422,    -1,   423,    -1,
     424,    -1,   425,    -1,   426,    -1,   427,    -1,   428,    -1,
     429,    -1,    35,     3,     7,    -1,    36,     3,     7,    -1,
      38,     3,     7,    -1,    22,     3,     7,    -1,    23,     3,
       7,    -1,    24,     3,     7,    -1,    40,     3,     7,    -1,
       8,   431,    76,    -1,   139,   432,   438,    -1,    -1,   432,
     433,    -1,   434,    -1,   435,    -1,   436,    -1,   437,    -1,
      37,     3,     7,    -1,    38,     3,     7,    -1,    41,     3,
       7,    -1,    42,     3,     7,    -1,     8,   140,    -1,     9,
      -1,    -1,   143,   440,     8,   441,   144,    -1,    26,     3,
       7,    -1,    -1,   441,   442,    -1,   145,   443,   451,    -1,
      -1,   443,   444,    -1,   445,    -1,   446,    -1,   447,    -1,
     448,    -1,   449,    -1,   450,    -1,    36,     3,     7,    -1,
      38,     3,     7,    -1,    22,     3,     7,    -1,    23,     3,
       7,    -1,    24,     3,     7,    -1,    40,     3,     7,    -1,
       8,   146,    -1,     9,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   124,   124,   125,   127,   128,   130,   132,   133,   134,
     136,   136,   138,   138,   138,   138,   138,   139,   139,   139,
     139,   139,   139,   142,   142,   144,   145,   149,   154,   154,
     156,   157,   161,   166,   166,   168,   169,   173,   178,   178,
     180,   181,   185,   189,   189,   194,   194,   196,   197,   201,
     206,   206,   208,   209,   213,   218,   218,   220,   221,   225,
     230,   230,   232,   233,   237,   242,   242,   244,   245,   249,
     253,   253,   255,   256,   260,   264,   264,   269,   271,   275,
     275,   277,   279,   279,   281,   283,   287,   287,   291,   291,
     295,   295,   300,   301,   302,   304,   304,   306,   306,   306,
     306,   306,   308,   309,   313,   313,   317,   318,   322,   322,
     326,   327,   331,   331,   335,   335,   337,   338,   342,   346,
     348,   352,   352,   354,   356,   356,   358,   360,   364,   364,
     368,   368,   372,   372,   377,   378,   379,   381,   381,   383,
     383,   385,   385,   387,   388,   392,   397,   399,   403,   403,
     405,   407,   407,   409,   411,   415,   415,   419,   419,   423,
     423,   428,   429,   430,   432,   432,   434,   434,   434,   434,
     434,   435,   435,   435,   435,   435,   436,   436,   436,   436,
     436,   438,   442,   442,   446,   446,   448,   449,   453,   457,
     459,   463,   463,   466,   470,   473,   477,   477,   479,   483,
     486,   490,   490,   492,   496,   499,   503,   503,   505,   509,
     512,   516,   516,   518,   522,   525,   529,   529,   531,   535,
     535,   537,   537,   537,   539,   543,   547,   551,   551,   554,
     557,   561,   561,   563,   567,   567,   569,   569,   569,   571,
     575,   579,   583,   583,   586,   589,   593,   593,   595,   599,
     599,   601,   601,   601,   603,   607,   611,   615,   615,   618,
     621,   625,   625,   627,   631,   631,   633,   633,   633,   635,
     639,   643,   647,   647,   651,   654,   658,   658,   660,   664,
     667,   671,   671,   673,   678,   681,   685,   685,   687,   692,
     694,   698,   698,   700,   702,   702,   704,   706,   710,   710,
     714,   714,   718,   718,   723,   723,   725,   725,   727,   727,
     727,   729,   733,   737,   741,   741,   743,   745,   745,   747,
     747,   751,   752,   754,   754,   757,   757,   759,   761,   761,
     763,   763,   765,   769,   773,   773,   776,   776,   778,   778,
     781,   782,   783,   784,   785,   786,   787,   789,   793,   797,
     801,   805,   809,   813,   818,   820,   822,   822,   825,   826,
     827,   828,   830,   834,   838,   842,   846,   846,   848,   848,
     850,   850,   854,   856,   859,   859,   862,   862,   864,   866,
     866,   868,   868,   870,   874,   878,   878,   881,   881,   884,
     884,   886,   888,   888,   890,   890,   892,   896,   900,   900,
     903,   903,   905,   905,   908,   909,   910,   911,   912,   913,
     914,   916,   920,   924,   928,   932,   936,   940,   945,   947,
     949,   949,   952,   953,   954,   955,   957,   961,   965,   969,
     973,   973,   975,   975,   977,   977,   981,   983,   985,   985,
     988,   988,   990,   992,   992,   994,   994,   996,  1000,  1004,
    1004,  1007,  1007,  1010,  1010,  1012,  1014,  1014,  1016,  1016,
    1018,  1022,  1026,  1026,  1029,  1029,  1031,  1031,  1034,  1035,
    1036,  1037,  1038,  1039,  1040,  1042,  1046,  1050,  1054,  1058,
    1062,  1066,  1071,  1073,  1075,  1075,  1078,  1079,  1080,  1081,
    1083,  1087,  1091,  1095,  1099,  1099,  1102,  1102,  1104,  1108,
    1108,  1110,  1112,  1112,  1115,  1116,  1117,  1118,  1119,  1120,
    1122,  1126,  1130,  1134,  1138,  1142,  1147,  1147
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
  "generalcontent", "generaloption", "serviceURI", "emptyURI",
  "nonemptyURI", "servicename", "emptyservicename", "nonemptyservicename",
  "instancename", "emptyinstancename", "nonemptyinstancename",
  "instancelocation", "emptylocation", "nonemptylocation",
  "locationtypeatt", "jobid", "emptyjobid", "nonemptyjobid",
  "solvertoinvoke", "emptysolver", "nonemptysolver", "license",
  "emptylicense", "nonemptylicense", "username", "emptyusername",
  "nonemptyusername", "password", "emptypassword", "nonemptypassword",
  "contact", "emptycontact", "nonemptycontact", "transporttypeatt",
  "othergeneraloptions", "numberofothergeneraloptions",
  "othergeneraloptionslist", "othergeneraloption",
  "othergeneralattributes", "othergeneralattribute",
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
       0,   148,   149,   149,   150,   150,   151,   152,   152,   152,
     153,   153,   154,   154,   154,   154,   154,   154,   154,   154,
     154,   154,   154,   155,   155,   156,   156,   157,   158,   158,
     159,   159,   160,   161,   161,   162,   162,   163,   164,   164,
     165,   165,   166,   167,   167,   168,   168,   169,   169,   170,
     171,   171,   172,   172,   173,   174,   174,   175,   175,   176,
     177,   177,   178,   178,   179,   180,   180,   181,   181,   182,
     183,   183,   184,   184,   185,   186,   186,   187,   188,   189,
     189,   190,   191,   191,   192,   193,   194,   194,   195,   195,
     196,   196,   197,   197,   197,   198,   198,   199,   199,   199,
     199,   199,   200,   200,   201,   201,   202,   202,   203,   203,
     204,   204,   205,   205,   206,   206,   207,   207,   208,   209,
     210,   211,   211,   212,   213,   213,   214,   215,   216,   216,
     217,   217,   218,   218,   219,   219,   219,   220,   220,   221,
     221,   222,   222,   223,   223,   224,   225,   226,   227,   227,
     228,   229,   229,   230,   231,   232,   232,   233,   233,   234,
     234,   235,   235,   235,   236,   236,   237,   237,   237,   237,
     237,   237,   237,   237,   237,   237,   237,   237,   237,   237,
     237,   238,   239,   239,   240,   240,   241,   241,   242,   243,
     244,   245,   245,   246,   247,   248,   249,   249,   250,   251,
     252,   253,   253,   254,   255,   256,   257,   257,   258,   259,
     260,   261,   261,   262,   263,   264,   265,   265,   266,   267,
     267,   268,   268,   268,   269,   270,   271,   272,   272,   273,
     274,   275,   275,   276,   277,   277,   278,   278,   278,   279,
     280,   281,   282,   282,   283,   284,   285,   285,   286,   287,
     287,   288,   288,   288,   289,   290,   291,   292,   292,   293,
     294,   295,   295,   296,   297,   297,   298,   298,   298,   299,
     300,   301,   302,   302,   303,   304,   305,   305,   306,   307,
     308,   309,   309,   310,   311,   312,   313,   313,   314,   315,
     316,   317,   317,   318,   319,   319,   320,   321,   322,   322,
     323,   323,   324,   324,   325,   325,   326,   326,   327,   327,
     327,   328,   329,   330,   331,   331,   332,   333,   333,   334,
     334,   335,   335,   336,   336,   337,   337,   338,   339,   339,
     340,   340,   341,   342,   343,   343,   344,   344,   345,   345,
     346,   346,   346,   346,   346,   346,   346,   347,   348,   349,
     350,   351,   352,   353,   354,   355,   356,   356,   357,   357,
     357,   357,   358,   359,   360,   361,   362,   362,   363,   363,
     364,   364,   365,   365,   366,   366,   367,   367,   368,   369,
     369,   370,   370,   371,   372,   373,   373,   374,   374,   375,
     375,   376,   377,   377,   378,   378,   379,   380,   381,   381,
     382,   382,   383,   383,   384,   384,   384,   384,   384,   384,
     384,   385,   386,   387,   388,   389,   390,   391,   392,   393,
     394,   394,   395,   395,   395,   395,   396,   397,   398,   399,
     400,   400,   401,   401,   402,   402,   403,   403,   404,   404,
     405,   405,   406,   407,   407,   408,   408,   409,   410,   411,
     411,   412,   412,   413,   413,   414,   415,   415,   416,   416,
     417,   418,   419,   419,   420,   420,   421,   421,   422,   422,
     422,   422,   422,   422,   422,   423,   424,   425,   426,   427,
     428,   429,   430,   431,   432,   432,   433,   433,   433,   433,
     434,   435,   436,   437,   438,   438,   439,   439,   440,   441,
     441,   442,   443,   443,   444,   444,   444,   444,   444,   444,
     445,   446,   447,   448,   449,   450,   451,   451
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     4,     2,     1,     2,     5,     0,     4,     2,
       0,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     2,     3,     4,     1,     1,
       2,     3,     4,     1,     1,     2,     3,     4,     1,     1,
       2,     4,     5,     0,     3,     1,     1,     2,     3,     4,
       1,     1,     2,     3,     4,     1,     1,     2,     3,     4,
       1,     1,     2,     3,     4,     1,     1,     2,     3,     4,
       1,     1,     2,     4,     5,     0,     3,     5,     3,     0,
       2,     3,     0,     2,     3,     3,     0,     3,     0,     3,
       1,     2,     0,     4,     2,     0,     2,     1,     1,     1,
       1,     1,     5,     5,     0,     3,     5,     5,     0,     3,
       5,     5,     0,     3,     1,     1,     2,     3,     4,     5,
       3,     0,     2,     3,     0,     2,     3,     3,     0,     3,
       0,     3,     1,     2,     0,     4,     2,     0,     2,     1,
       1,     1,     1,     2,     3,     4,     5,     3,     0,     2,
       3,     0,     2,     3,     3,     0,     3,     0,     3,     1,
       2,     0,     4,     2,     0,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     5,     0,     3,     1,     1,     2,     3,     4,     4,
       3,     0,     2,     4,     4,     3,     0,     2,     4,     5,
       3,     0,     2,     4,     5,     3,     0,     2,     4,     5,
       3,     0,     2,     4,     5,     3,     0,     2,     3,     0,
       2,     1,     1,     1,     3,     3,     3,     2,     1,     5,
       3,     0,     2,     3,     0,     2,     1,     1,     1,     3,
       3,     3,     2,     1,     5,     3,     0,     2,     3,     0,
       2,     1,     1,     1,     3,     3,     3,     2,     1,     5,
       3,     0,     2,     3,     0,     2,     1,     1,     1,     3,
       3,     3,     2,     1,     5,     3,     0,     2,     4,     5,
       3,     0,     2,     4,     5,     3,     0,     2,     4,     5,
       3,     0,     2,     3,     0,     2,     3,     3,     0,     3,
       0,     3,     1,     2,     0,     3,     0,     2,     1,     1,
       1,     3,     3,     3,     3,     1,     4,     0,     3,     0,
       3,     4,     1,     0,     7,     0,     2,     3,     0,     2,
       1,     1,     3,     3,     2,     1,     0,     3,     0,     2,
       1,     1,     1,     1,     1,     1,     1,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     0,     2,     1,     1,
       1,     1,     3,     3,     3,     3,     2,     1,     0,     3,
       0,     3,     5,     1,     0,     7,     0,     2,     3,     0,
       2,     1,     1,     3,     3,     2,     1,     0,     7,     0,
       2,     3,     0,     2,     1,     1,     3,     3,     2,     1,
       0,     3,     0,     2,     1,     1,     1,     1,     1,     1,
       1,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       0,     2,     1,     1,     1,     1,     3,     3,     3,     3,
       2,     1,     0,     3,     0,     3,     5,     1,     0,     7,
       0,     2,     3,     0,     2,     1,     1,     3,     3,     2,
       1,     0,     7,     0,     2,     3,     0,     2,     1,     1,
       3,     3,     2,     1,     0,     3,     0,     2,     1,     1,
       1,     1,     1,     1,     1,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     0,     2,     1,     1,     1,     1,
       3,     3,     3,     3,     2,     1,     0,     5,     3,     0,
       2,     3,     0,     2,     1,     1,     1,     1,     1,     1,
       3,     3,     3,     3,     3,     3,     2,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       0,     4,     0,     0,     5,     1,     7,     3,     0,     0,
      92,    10,     9,     2,     0,   134,     0,    95,    94,     0,
     161,     8,     0,     0,     0,    43,     0,     0,     0,     0,
       0,    75,     0,    11,    12,    23,    24,    13,    28,    29,
      14,    33,    34,    15,    38,    39,    16,    45,    46,    17,
      50,    51,    18,    55,    56,    19,    60,    61,    20,    65,
      66,    21,    70,    71,    22,     0,   137,   136,     0,   304,
       0,    25,     0,    30,     0,    35,    40,     0,     0,     0,
      47,     0,    52,     0,    57,     0,    62,     0,    67,    72,
       0,     0,     0,     0,    93,     0,   104,   108,   112,     0,
      96,    97,    98,    99,   100,   114,   115,   101,     0,   164,
     163,   306,     6,     0,    26,     0,    31,     0,    36,     0,
       0,     0,    48,     0,    53,     0,    58,     0,    63,     0,
      68,     0,     0,     0,    79,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   116,   135,     0,     0,   138,   139,
     141,   142,   140,     0,     0,    27,    32,    37,    44,     0,
      41,    49,    54,    59,    64,    69,    76,     0,    73,    78,
       0,     0,   121,     0,     0,     0,     0,     0,     0,     0,
     117,     0,     0,     0,   143,   162,     0,   182,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   165,   166,   167,   184,   185,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   317,
     315,     0,     0,     0,   307,   308,   309,   310,   305,    42,
      74,    77,    82,    80,   120,     0,   105,     0,     0,   109,
       0,     0,   113,     0,     0,   118,     0,   148,     0,   144,
       0,     0,     0,     0,     0,   186,     0,   191,     0,   196,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     319,     0,   368,     0,     0,     0,     0,   119,   124,   122,
     103,   102,   107,   106,   111,   110,   147,     0,   145,     0,
     291,     0,     0,     0,   187,     0,     0,     0,     0,     0,
     201,     0,   206,     0,   211,     0,   281,     0,   276,     0,
     216,     0,   231,     0,   246,     0,   261,     0,   286,     0,
       0,   314,   370,   432,   311,   313,   312,     0,    90,     0,
      83,    86,    81,     0,   146,   151,   149,   290,     0,   183,
       0,   188,   190,     0,   189,   192,   195,   194,     0,   197,
     200,     0,   205,     0,   210,     0,   280,     0,   275,     0,
     215,     0,   230,     0,   245,     0,   260,     0,   285,     0,
       0,   323,   322,   318,     0,     0,   434,   496,    91,     0,
       0,    88,     0,   132,     0,   125,   128,   123,     0,   289,
     294,   292,   181,     0,     0,   199,     0,   202,     0,   204,
     207,     0,   209,   212,     0,   279,   282,     0,   274,   277,
     219,   214,   217,   234,   229,   232,   249,   244,   247,   264,
     259,   262,   284,     0,   287,   320,     0,   336,     0,   374,
     373,   369,     0,     0,     0,   316,    85,     0,     0,    84,
     133,     0,     0,   130,     0,   159,     0,   152,   155,   150,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   338,     0,   371,     0,   387,     0,
     438,   437,   433,     0,     0,    87,     0,   127,     0,     0,
     126,   160,     0,     0,   157,     0,   302,     0,   295,   298,
     293,   193,   198,     0,     0,     0,     0,     0,     0,   228,
       0,     0,     0,   220,   221,   222,   223,   218,     0,   243,
       0,     0,     0,   235,   236,   237,   238,   233,     0,   258,
       0,     0,     0,   250,   251,   252,   253,   248,     0,   273,
       0,     0,     0,   265,   266,   267,   268,   263,     0,     0,
       0,   321,     0,     0,   400,   435,     0,   451,     0,   499,
      89,   129,     0,   154,     0,     0,   153,   303,     0,     0,
     300,   203,   208,   213,   283,   278,   227,     0,     0,     0,
     242,     0,     0,     0,   257,     0,     0,     0,   272,     0,
       0,     0,   288,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   339,   340,   341,   342,   343,   344,   345,   346,
     337,     0,     0,   402,     0,     0,     0,   464,   498,     0,
     131,   156,     0,   297,     0,     0,   296,   224,   225,   226,
     239,   240,   241,   254,   255,   256,   269,   270,   271,   325,
     356,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   372,     0,     0,   466,     0,   497,   502,   500,
     158,   299,     0,     0,     0,   354,   350,   351,   352,   347,
     348,   349,   353,   376,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   403,   404,   405,   406,   407,   408,   409,
     410,   401,     0,     0,     0,   436,     0,   301,   324,   328,
     326,     0,   367,     0,     0,     0,     0,   357,   358,   359,
     360,   361,   355,     0,   389,   420,     0,     0,     0,     0,
       0,     0,     0,     0,   440,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   467,   468,   469,   470,   471,   472,
     473,   474,   465,     0,   517,     0,     0,     0,     0,     0,
       0,   503,   504,   505,   506,   507,   508,   509,   501,     0,
     366,     0,     0,     0,     0,   375,   379,   377,     0,     0,
     418,   414,   415,   416,   411,   412,   413,   417,     0,   453,
     484,     0,     0,     0,     0,     0,     0,     0,     0,   516,
       0,     0,     0,     0,     0,     0,     0,   335,     0,     0,
     329,   330,   331,   327,   362,   363,   364,   365,     0,   392,
     388,   390,     0,   431,     0,     0,     0,     0,   421,   422,
     423,   424,   425,   419,   439,   443,   441,     0,     0,   482,
     478,   479,   480,   475,   476,   477,   481,   512,   513,   514,
     510,   511,   515,   334,     0,     0,     0,   386,     0,     0,
     380,   381,   382,   378,     0,   430,     0,     0,     0,     0,
       0,   456,   452,   454,     0,   495,     0,     0,     0,     0,
     485,   486,   487,   488,   489,   483,   332,   333,   385,     0,
       0,     0,   399,     0,     0,   393,   394,   395,   391,   426,
     427,   428,   429,     0,   450,     0,     0,   444,   445,   446,
     442,     0,   494,     0,     0,     0,     0,   383,   384,   398,
       0,     0,   449,     0,     0,     0,   463,     0,     0,   457,
     458,   459,   455,   490,   491,   492,   493,   396,   397,   447,
     448,   462,     0,     0,   460,   461
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,     9,    10,    16,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    78,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    91,    64,
      93,   170,   233,   286,   340,   341,   391,   449,   342,    15,
      65,   100,   101,   138,   102,   140,   103,   142,   104,   105,
     106,   107,   136,   235,   289,   343,   395,   396,   453,   490,
     397,    20,   108,   148,   149,   150,   151,   152,   182,   297,
     346,   398,   457,   458,   494,   566,   459,    69,   153,   201,
     202,   253,   203,   204,   205,   206,   257,   306,   355,   207,
     259,   308,   359,   208,   261,   361,   407,   209,   263,   363,
     410,   210,   265,   365,   413,   211,   271,   371,   422,   468,
     513,   514,   515,   516,   517,   212,   273,   373,   425,   469,
     523,   524,   525,   526,   527,   213,   275,   375,   428,   470,
     533,   534,   535,   536,   537,   214,   277,   377,   431,   471,
     543,   544,   545,   546,   547,   215,   269,   369,   419,   216,
     267,   367,   416,   217,   279,   379,   434,   218,   251,   348,
     401,   460,   498,   499,   570,   626,   500,   112,   154,   224,
     225,   226,   227,   228,   281,   282,   330,   383,   437,   663,
     700,   759,   800,   801,   802,   803,   475,   550,   602,   603,
     604,   605,   606,   607,   608,   609,   610,   641,   664,   707,
     708,   709,   710,   711,   712,   333,   385,   441,   478,   713,
     767,   808,   850,   851,   852,   853,   554,   768,   811,   854,
     885,   886,   887,   888,   614,   651,   683,   684,   685,   686,
     687,   688,   689,   690,   691,   716,   769,   818,   819,   820,
     821,   822,   823,   387,   443,   482,   557,   778,   826,   860,
     897,   898,   899,   900,   617,   827,   863,   901,   919,   920,
     921,   922,   656,   694,   734,   735,   736,   737,   738,   739,
     740,   741,   742,   781,   828,   870,   871,   872,   873,   874,
     875,   445,   484,   619,   659,   696,   751,   752,   753,   754,
     755,   756,   757,   758
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -91
static const yytype_int16 yypact[] =
{
      25,    38,    58,    10,   -91,   -91,    19,   -91,   168,    77,
      48,   -91,   -91,   -91,   175,    50,   155,   -91,   -91,   192,
      54,   -91,   197,   229,   241,    41,   243,   245,   247,   249,
     251,    23,    93,   -91,   -91,   -91,   -91,   -91,   -91,   -91,
     -91,   -91,   -91,   -91,   -91,   -91,   -91,   -91,   -91,   -91,
     -91,   -91,   -91,   -91,   -91,   -91,   -91,   -91,   -91,   -91,
     -91,   -91,   -91,   -91,   -91,   -39,   -91,   -91,   253,    64,
      22,   -91,     8,   -91,    17,   -91,   -91,   122,   121,    12,
     -91,     4,   -91,     7,   -91,     2,   -91,     1,   -91,   -91,
     128,   129,   138,   135,   -91,   132,   114,   124,   131,   255,
     -91,   -91,   -91,   -91,   -91,   -91,   -91,   -91,   -25,   -91,
     -91,   -91,   -91,    95,   -91,    99,   -91,   130,   -91,   179,
       6,   140,   -91,   143,   -91,   145,   -91,   141,   -91,   147,
     -91,   206,     0,   208,   -91,   216,   213,   220,   217,   228,
     219,   231,   285,    -2,   -91,   -91,   284,   257,   -91,   -91,
     -91,   -91,   -91,   -48,   151,   -91,   -91,   -91,   -91,   238,
     -91,   -91,   -91,   -91,   -91,   -91,   -91,   167,   -91,   -91,
     193,   297,   -91,   298,   264,   299,   266,   300,   268,   225,
     -91,   305,   302,    -3,   -91,   -91,   296,   274,   267,   301,
     295,   303,   304,   306,   307,   308,   309,   310,   311,   312,
     289,   -91,   -91,   -91,   -91,   -91,   -91,   -91,   -91,   -91,
     -91,   -91,   -91,   -91,   -91,   -91,   -91,   -91,   -91,   194,
     -91,   313,   315,   316,   -91,   -91,   -91,   -91,   -91,   -91,
     -91,   -91,   -91,   -91,   -91,   203,   -91,   244,   248,   -91,
     252,   254,   -91,   256,   258,   -91,   324,   -91,   250,   -91,
     330,   327,   334,   331,    -4,   -91,   338,   -91,   339,   -91,
     340,   336,   342,   341,   343,   344,   345,   346,   347,   348,
     350,   349,   352,   351,   355,   353,   357,   354,   360,   356,
     317,   314,   240,   358,   361,   362,    20,   -91,   -91,   -91,
     -91,   -91,   -91,   -91,   -91,   -91,   -91,   205,   -91,   363,
     -91,   364,   368,   261,   -91,   366,   -46,   367,   -61,   369,
     -91,   370,   -91,   371,   -91,   372,   -91,   373,   -91,   374,
     -91,   375,   -91,   376,   -91,   377,   -91,   378,   -91,   383,
     273,   -91,   359,   259,   -91,   -91,   -91,   319,   -91,   384,
     -91,   337,   -91,    83,   -91,   -91,   -91,   -91,   209,   -91,
     318,   -91,   -91,   380,   -91,   -91,   -91,   -91,   381,   -91,
     -91,   189,   -91,   -80,   -91,     5,   -91,    -1,   -91,   -77,
     -91,   -20,   -91,   -85,   -91,   -90,   -91,   -86,   -91,   169,
     385,   270,   -91,   -91,   388,   281,   365,   260,   -91,   389,
     395,   379,   323,   -91,   397,   -91,   382,   -91,    86,   -91,
     -91,   -91,   -91,   398,   400,   -91,   393,   -91,   399,   -91,
     -91,   401,   -91,   -91,   402,   -91,   -91,   403,   -91,   -91,
     -91,   -91,   -91,   -91,   -91,   -91,   -91,   -91,   -91,   -91,
     -91,   -91,   -91,   404,   -91,   -91,   390,   333,   406,   276,
     -91,   -91,   411,   283,   391,   -91,   -91,   408,   413,   -91,
     -91,   414,   415,   386,   387,   -91,   419,   -91,   392,   -91,
      91,   394,   326,   421,   423,   424,   425,   427,   173,   221,
     224,   227,   428,   430,   -91,   320,   -91,   405,   321,   429,
     322,   -91,   -91,   431,   432,   -91,   434,   -91,   436,   435,
     -91,   -91,   437,   442,   407,   396,   -91,   443,   -91,   410,
     -91,   -91,   -91,   409,   412,   416,   417,   418,   335,   -91,
     446,   447,   448,   -91,   -91,   -91,   -91,   -91,   420,   -91,
     449,   450,   452,   -91,   -91,   -91,   -91,   -91,   422,   -91,
     454,   455,   457,   -91,   -91,   -91,   -91,   -91,   426,   -91,
     458,   459,   461,   -91,   -91,   -91,   -91,   -91,   433,   460,
      90,   -91,   462,   439,   438,   -91,   440,   325,   463,   -91,
     -91,   -91,   464,   -91,   467,   465,   -91,   -91,   469,   466,
     441,   -91,   -91,   -91,   -91,   -91,   -91,   470,   471,   472,
     -91,   473,   475,   476,   -91,   477,   478,   479,   -91,   480,
     481,   482,   -91,   483,   444,   487,   489,   490,   491,   492,
     493,   494,   -91,   -91,   -91,   -91,   -91,   -91,   -91,   -91,
     -91,   495,   496,   -91,   445,   497,   468,   453,   -91,   150,
     -91,   -91,   498,   -91,   499,   501,   -91,   -91,   -91,   -91,
     -91,   -91,   -91,   -91,   -91,   -91,   -91,   -91,   -91,   -91,
     -91,   451,   502,   504,   505,   510,   511,   512,   514,   500,
     516,   110,   -91,   517,   522,   -91,   456,   -91,   -91,   -91,
     -91,   -91,   523,   172,    43,   -91,   -91,   -91,   -91,   -91,
     -91,   -91,   -91,   -91,   521,   474,   528,   529,   530,   531,
     532,   533,   534,   -91,   -91,   -91,   -91,   -91,   -91,   -91,
     -91,   -91,   535,   537,   116,   -91,   149,   -91,   -91,   -91,
     -91,   484,   -91,   536,   538,   539,   542,   -91,   -91,   -91,
     -91,   -91,   -91,   170,   -91,   -91,   485,   540,   541,   543,
     544,   545,   547,   548,   -91,   549,   486,   546,   553,   555,
     556,   557,   559,   560,   -91,   -91,   -91,   -91,   -91,   -91,
     -91,   -91,   -91,   291,   -91,   561,   562,   563,   564,   565,
     567,   -91,   -91,   -91,   -91,   -91,   -91,   -91,   -91,   127,
     -91,   568,   569,   570,   571,   -91,   -91,   -91,   -30,    69,
     -91,   -91,   -91,   -91,   -91,   -91,   -91,   -91,   164,   -91,
     -91,   503,   573,   574,   575,   576,   577,   578,   579,   -91,
     580,   581,   582,   583,   584,   586,   488,   -91,   591,   592,
     -91,   -91,   -91,   -91,   -91,   -91,   -91,   -91,   153,   -91,
     -91,   -91,   506,   -91,   593,   594,   595,   596,   -91,   -91,
     -91,   -91,   -91,   -91,   -91,   -91,   -91,     3,    79,   -91,
     -91,   -91,   -91,   -91,   -91,   -91,   -91,   -91,   -91,   -91,
     -91,   -91,   -91,   -91,   597,   599,   507,   -91,   598,   600,
     -91,   -91,   -91,   -91,   158,   -91,   601,   602,   604,   605,
     160,   -91,   -91,   -91,   508,   -91,   610,   612,   613,   614,
     -91,   -91,   -91,   -91,   -91,   -91,   -91,   -91,   -91,   611,
     615,   509,   -91,   616,   617,   -91,   -91,   -91,   -91,   -91,
     -91,   -91,   -91,   513,   -91,   618,   620,   -91,   -91,   -91,
     -91,   166,   -91,   619,   621,   622,   623,   -91,   -91,   -91,
     624,   626,   -91,   627,   628,   515,   -91,   633,   634,   -91,
     -91,   -91,   -91,   -91,   -91,   -91,   -91,   -91,   -91,   -91,
     -91,   -91,   631,   635,   -91,   -91
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
     -91,   -91,   -91,   -91
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint16 yytable[] =
{
     303,   248,   185,   179,   167,   129,   127,    94,   123,   426,
     159,   125,   115,   429,   423,   353,   121,   408,     6,     7,
     417,   117,   409,   145,   427,   186,   113,   424,   337,   338,
     430,   418,    89,   357,    95,     1,   358,    90,    96,   187,
      97,   188,    98,   189,    99,   190,   354,   191,   146,     4,
      76,   701,   702,   192,    77,   193,   339,   194,     5,   195,
     147,   196,     8,   197,   116,   198,   160,   199,   124,   200,
     128,   130,   168,   126,   122,   118,   114,   812,   813,   420,
     703,   704,   180,   249,   705,   706,   304,   864,   865,    13,
     421,   392,   393,    14,   454,   455,   414,    19,   594,   495,
     496,   809,   411,    68,   810,   415,   814,   815,    92,   412,
     816,   817,   595,   596,   597,   111,   866,   867,   675,   394,
     868,   869,   456,   598,   726,   119,   599,   497,   600,   120,
     601,   131,   676,   677,   678,   796,   797,   132,   727,   728,
     729,   133,   861,   134,   679,   862,   680,   135,   681,   155,
     682,   730,   731,   137,   732,   156,   733,   743,   744,   219,
     220,   846,   847,   139,   798,   799,   881,   882,   893,   894,
     141,   745,   746,   747,   915,   916,    11,    12,   221,   222,
     223,   508,   509,    17,    18,   748,   158,   749,   157,   750,
     848,   849,   510,   511,   512,   883,   884,   895,   896,    21,
      66,    67,   161,   917,   918,    70,    71,   162,    22,   164,
      23,   163,    24,   166,    25,   169,    26,   165,    27,   171,
      28,   172,    29,   173,    30,   174,    31,   176,    32,   518,
     519,   175,   528,   529,   177,   538,   539,    72,    73,   230,
     520,   521,   522,   530,   531,   532,   540,   541,   542,    74,
      75,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,   109,   110,   143,   144,   183,   184,   231,   232,   237,
     238,   240,   241,   243,   244,   254,   255,   287,   288,   344,
     345,   381,   382,   399,   400,   405,   406,   432,   433,   439,
     440,   480,   481,   178,   657,   658,   698,   699,   229,   181,
     765,   766,   824,   825,   234,   236,   239,   242,   246,   245,
     247,   250,   258,   252,   278,   280,   283,   256,   284,   285,
     260,   262,   290,   264,   266,   268,   291,   270,   272,   274,
     276,   296,   292,   299,   293,   300,   298,   301,   294,   302,
     295,   305,   307,   309,   310,   311,   313,   329,   315,   312,
     317,   351,   314,   319,   316,   321,   318,   320,   323,   322,
     325,   324,   326,   327,   328,   334,   331,   332,   335,   336,
     347,   349,   350,   352,   356,   390,   360,   362,   364,   366,
     368,   370,   372,   374,   376,   378,   380,   389,   403,   404,
     384,   438,   435,   436,   386,   388,   446,   442,   447,   450,
     451,   463,   461,   444,   462,   477,   402,   464,   474,   465,
     466,   467,   472,   476,   479,   485,   486,   483,   488,   448,
     452,   487,   492,   473,   502,   503,   489,   504,   505,   506,
     493,   507,   548,   549,   558,   576,   555,   789,   562,   552,
     559,   560,   551,   561,   563,   564,   568,   565,   569,   577,
     578,   579,   581,   582,   553,   583,   501,   585,   586,   556,
     587,   589,   590,   491,   591,   611,   616,   593,   622,   624,
     618,   620,   567,   612,   621,   615,   623,   627,   628,   629,
     630,   625,   631,   632,   633,   634,   635,   636,   637,   638,
     642,   639,   643,   644,   645,   646,   647,   648,     0,   650,
     653,     0,   649,   654,   662,   660,   661,   571,   673,   666,
     572,   667,   668,   613,   573,   574,   575,   669,   670,   671,
     580,   672,   584,   674,   692,   693,   588,   665,   655,   714,
     697,   717,   718,   719,   720,   721,   722,   723,     0,   761,
       0,   762,   763,   724,   725,   764,     0,   771,   772,   782,
     773,   774,   775,   592,   776,   777,   783,   779,   784,   785,
     786,   770,   787,   788,   790,   791,   792,   793,   794,   640,
     795,     0,     0,   652,     0,   804,   805,   806,   807,   829,
     830,   831,   832,   833,   834,   835,   836,   837,   838,   839,
     840,   841,   695,   842,   844,   845,   856,   857,   858,   859,
       0,   879,     0,   880,   876,   715,   877,     0,   889,   890,
     760,   891,   892,   903,   843,   904,   905,   906,   907,   910,
     911,   913,   908,   914,     0,   780,   923,     0,   924,   925,
     926,   927,   855,   928,   929,   930,   932,   933,   934,   878,
       0,   909,   935,     0,     0,     0,     0,     0,   902,     0,
       0,     0,     0,   912,     0,   931
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
       9,   131,    97,    49,   134,   106,    37,    38,    15,   104,
      41,    42,    22,    23,    24,    51,    37,    38,     8,    36,
      41,    42,    36,    33,     8,     3,    36,    36,    38,     8,
      40,     3,    22,    23,    24,     8,     9,     8,    22,    23,
      24,     3,   139,     8,    34,   142,    36,    15,    38,    54,
      40,    35,    36,    39,    38,    56,    40,     8,     9,     8,
       9,     8,     9,    39,    37,    38,     8,     9,     8,     9,
      39,    22,    23,    24,     8,     9,     8,     9,    27,    28,
      29,     8,     9,     8,     9,    36,     7,    38,    58,    40,
      37,    38,    19,    20,    21,    37,    38,    37,    38,    44,
       8,     9,    62,    37,    38,     8,     9,    64,    53,    68,
      55,    66,    57,     7,    59,     7,    61,    70,    63,     3,
      65,     8,    67,     3,    69,     8,    71,     8,    73,     8,
       9,     3,     8,     9,     3,     8,     9,     8,     9,    72,
      19,    20,    21,    19,    20,    21,    19,    20,    21,     8,
       9,     8,     9,     8,     9,     8,     9,     8,     9,     8,
       9,     8,     9,     8,     9,     8,     9,    74,    75,     5,
       6,     5,     6,     5,     6,     8,     9,    74,    75,    74,
      75,     8,     9,    74,    75,    96,    97,   118,   119,     8,
       9,     8,     9,     8,   144,   145,   124,   125,    60,    15,
     130,   131,   138,   139,     7,     7,     7,     7,     3,    84,
       8,    15,    17,    39,    25,   121,     3,    16,     3,     3,
      17,    17,    78,    17,    17,    17,    78,    18,    18,    18,
      18,     7,    80,     3,    80,     8,    86,     3,    82,     8,
      82,     3,     3,     3,     8,     3,     3,    30,     3,     8,
       3,    90,     8,     3,     8,     3,     8,     8,     3,     8,
       3,     8,     8,     3,     8,     7,    52,   127,     7,     7,
       7,     7,     4,     7,     7,    38,     7,     7,     7,     7,
       7,     7,     7,     7,     7,     7,     3,     3,     8,     8,
      31,     3,     7,   123,   135,    76,     7,    32,     3,    76,
       3,     8,     4,   143,     4,   129,    88,     8,    75,     8,
       8,     8,     8,     7,     3,     7,     3,    26,     3,    40,
      38,     7,     3,    33,    98,     4,    40,     4,     4,     4,
      38,     4,     4,     3,     3,   100,     7,   146,     3,    34,
       8,     7,   122,     7,     7,     3,     3,    40,    38,     3,
       3,     3,     3,     3,   133,     3,    62,     3,     3,   137,
       3,     3,     3,    76,     3,     3,   141,     7,     3,     3,
       7,     7,    76,    34,     7,    35,     7,     7,     7,     7,
       7,    40,     7,     7,     7,     7,     7,     7,     7,     7,
       3,     8,     3,     3,     3,     3,     3,     3,    -1,     3,
       3,    -1,     7,    35,     3,     7,     7,    98,     8,     7,
      98,     7,     7,    75,    98,    98,    98,     7,     7,     7,
     100,     7,   100,     7,     7,     3,   100,    76,    75,     8,
       7,     3,     3,     3,     3,     3,     3,     3,    -1,     3,
      -1,     3,     3,     8,     7,     3,    -1,     7,     7,     3,
       7,     7,     7,   120,     7,     7,     3,     8,     3,     3,
       3,    76,     3,     3,     3,     3,     3,     3,     3,   125,
       3,    -1,    -1,   128,    -1,     7,     7,     7,     7,    76,
       7,     7,     7,     7,     7,     7,     7,     7,     7,     7,
       7,     7,   136,     7,     3,     3,     3,     3,     3,     3,
      -1,     3,    -1,     3,     7,   131,     7,    -1,     7,     7,
     126,     7,     7,     3,   126,     3,     3,     3,     7,     3,
       3,     3,     7,     3,    -1,   139,     7,    -1,     7,     7,
       7,     7,   126,     7,     7,     7,     3,     3,     7,   132,
      -1,   132,     7,    -1,    -1,    -1,    -1,    -1,   140,    -1,
      -1,    -1,    -1,   140,    -1,   140
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,    10,   149,   150,    11,     0,     8,     9,    43,   151,
     152,     8,     9,    12,    45,   197,   153,     8,     9,    47,
     219,    44,    53,    55,    57,    59,    61,    63,    65,    67,
      69,    71,    73,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   187,   198,     8,     9,    49,   235,
       8,     9,     8,     9,     8,     9,     9,    13,   167,     8,
       9,     8,     9,     8,     9,     8,     9,     8,     9,     9,
      14,   186,    15,   188,    46,    73,    77,    79,    81,    83,
     199,   200,   202,   204,   206,   207,   208,   209,   220,     8,
       9,    51,   325,     4,    54,     4,    56,     4,    58,     3,
       8,     4,    62,     4,    64,     4,    66,     4,    68,     4,
      70,     3,     8,     3,     8,    15,   210,    39,   201,    39,
     203,    39,   205,     8,     9,    48,    73,    85,   221,   222,
     223,   224,   225,   236,   326,    54,    56,    58,     7,     4,
      60,    62,    64,    66,    68,    70,     7,     4,    72,     7,
     189,     3,     8,     3,     8,     3,     8,     3,     8,     5,
      84,    15,   226,     8,     9,    50,    73,    87,    89,    91,
      93,    95,   101,   103,   105,   107,   109,   111,   113,   115,
     117,   237,   238,   240,   241,   242,   243,   247,   251,   255,
     259,   263,   273,   283,   293,   303,   307,   311,   315,     8,
       9,    27,    28,    29,   327,   328,   329,   330,   331,    60,
      72,    74,    75,   190,     7,   211,     7,     5,     6,     7,
       5,     6,     7,     5,     6,    84,     3,     8,     4,    86,
      15,   316,    39,   239,     8,     9,    16,   244,    17,   248,
      17,   252,    17,   256,    17,   260,    17,   308,    17,   304,
      18,   264,    18,   274,    18,   284,    18,   294,    25,   312,
     121,   332,   333,     3,     3,     3,   191,    74,    75,   212,
      78,    78,    80,    80,    82,    82,     7,   227,    86,     3,
       8,     3,     8,     4,    90,     3,   245,     3,   249,     3,
       8,     3,     8,     3,     8,     3,     8,     3,     8,     3,
       8,     3,     8,     3,     8,     3,     8,     3,     8,    30,
     334,    52,   127,   363,     7,     7,     7,     8,     9,    36,
     192,   193,   196,   213,    74,    75,   228,     7,   317,     7,
       4,    90,     7,    61,    92,   246,     7,    94,    97,   250,
       7,   253,     7,   257,     7,   261,     7,   309,     7,   305,
       7,   265,     7,   275,     7,   285,     7,   295,     7,   313,
       3,     8,     9,   335,    31,   364,   135,   401,    76,     3,
      38,   194,     8,     9,    36,   214,   215,   218,   229,    74,
      75,   318,    88,     8,     8,    96,    97,   254,    97,   102,
     258,    97,   104,   262,    97,   106,   310,    97,   108,   306,
      99,   110,   266,    99,   112,   276,    99,   114,   286,    99,
     116,   296,   118,   119,   314,     7,   123,   336,     3,     8,
       9,   365,    32,   402,   143,   439,     7,     3,    40,   195,
      76,     3,    38,   216,     8,     9,    36,   230,   231,   234,
     319,     4,     4,     8,     8,     8,     8,     8,   267,   277,
     287,   297,     8,    33,    75,   344,     7,   129,   366,     3,
       8,     9,   403,    26,   440,     7,     3,     7,     3,    40,
     217,    76,     3,    38,   232,     8,     9,    36,   320,   321,
     324,    62,    98,     4,     4,     4,     4,     4,     8,     9,
      19,    20,    21,   268,   269,   270,   271,   272,     8,     9,
      19,    20,    21,   278,   279,   280,   281,   282,     8,     9,
      19,    20,    21,   288,   289,   290,   291,   292,     8,     9,
      19,    20,    21,   298,   299,   300,   301,   302,     4,     3,
     345,   122,    34,   133,   374,     7,   137,   404,     3,     8,
       7,     7,     3,     7,     3,    40,   233,    76,     3,    38,
     322,    98,    98,    98,    98,    98,   100,     3,     3,     3,
     100,     3,     3,     3,   100,     3,     3,     3,   100,     3,
       3,     3,   120,     7,     8,    22,    23,    24,    33,    36,
      38,    40,   346,   347,   348,   349,   350,   351,   352,   353,
     354,     3,    34,    75,   382,    35,   141,   412,     7,   441,
       7,     7,     3,     7,     3,    40,   323,     7,     7,     7,
       7,     7,     7,     7,     7,     7,     7,     7,     7,     8,
     125,   355,     3,     3,     3,     3,     3,     3,     3,     7,
       3,   383,   128,     3,    35,    75,   420,   144,   145,   442,
       7,     7,     3,   337,   356,    76,     7,     7,     7,     7,
       7,     7,     7,     8,     7,     8,    22,    23,    24,    34,
      36,    38,    40,   384,   385,   386,   387,   388,   389,   390,
     391,   392,     7,     3,   421,   136,   443,     7,   124,   125,
     338,     8,     9,    37,    38,    41,    42,   357,   358,   359,
     360,   361,   362,   367,     8,   131,   393,     3,     3,     3,
       3,     3,     3,     3,     8,     7,     8,    22,    23,    24,
      35,    36,    38,    40,   422,   423,   424,   425,   426,   427,
     428,   429,   430,     8,     9,    22,    23,    24,    36,    38,
      40,   444,   445,   446,   447,   448,   449,   450,   451,   339,
     126,     3,     3,     3,     3,   130,   131,   368,   375,   394,
      76,     7,     7,     7,     7,     7,     7,     7,   405,     8,
     139,   431,     3,     3,     3,     3,     3,     3,     3,   146,
       3,     3,     3,     3,     3,     3,     8,     9,    37,    38,
     340,   341,   342,   343,     7,     7,     7,     7,   369,   131,
     134,   376,     8,     9,    37,    38,    41,    42,   395,   396,
     397,   398,   399,   400,   138,   139,   406,   413,   432,    76,
       7,     7,     7,     7,     7,     7,     7,     7,     7,     7,
       7,     7,     7,   126,     3,     3,     8,     9,    37,    38,
     370,   371,   372,   373,   377,   126,     3,     3,     3,     3,
     407,   139,   142,   414,     8,     9,    37,    38,    41,    42,
     433,   434,   435,   436,   437,   438,     7,     7,   132,     3,
       3,     8,     9,    37,    38,   378,   379,   380,   381,     7,
       7,     7,     7,     8,     9,    37,    38,   408,   409,   410,
     411,   415,   140,     3,     3,     3,     3,     7,     7,   132,
       3,     3,   140,     3,     3,     8,     9,    37,    38,   416,
     417,   418,   419,     7,     7,     7,     7,     7,     7,     7,
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
        case 26:

    {
;}
    break;

  case 27:

    {
;}
    break;

  case 31:

    {
;}
    break;

  case 32:

    {
;}
    break;

  case 36:

    {
;}
    break;

  case 37:

    {
;}
    break;

  case 41:

    {
;}
    break;

  case 42:

    {
;}
    break;

  case 44:

    {
;}
    break;

  case 48:

    {
;}
    break;

  case 49:

    {
;}
    break;

  case 53:

    {
;}
    break;

  case 54:

    {
;}
    break;

  case 58:

    {
;}
    break;

  case 59:

    {
;}
    break;

  case 63:

    {
;}
    break;

  case 64:

    {
;}
    break;

  case 68:

    {
;}
    break;

  case 69:

    {
;}
    break;

  case 73:

    {
;}
    break;

  case 74:

    {
;}
    break;

  case 76:

    {
;}
    break;

  case 78:

    {
;}
    break;

  case 85:

    {
;}
    break;

  case 87:

    {
;}
    break;

  case 89:

    {
;}
    break;

  case 91:

    {
;}
    break;

  case 103:

    {
;}
    break;

  case 105:

    {
;}
    break;

  case 107:

    {
;}
    break;

  case 109:

    {
;}
    break;

  case 111:

    {
;}
    break;

  case 113:

    {
;}
    break;

  case 117:

    {
;}
    break;

  case 118:

    {
;}
    break;

  case 120:

    {
;}
    break;

  case 127:

    {
;}
    break;

  case 129:

    {
;}
    break;

  case 131:

    {
;}
    break;

  case 133:

    {
;}
    break;

  case 144:

    {
;}
    break;

  case 145:

    {
;}
    break;

  case 147:

    {
;}
    break;

  case 154:

    {
;}
    break;

  case 156:

    {
;}
    break;

  case 158:

    {
;}
    break;

  case 160:

    {
;}
    break;

  case 181:

    {
;}
    break;

  case 183:

    {
;}
    break;

  case 187:

    {
;}
    break;

  case 188:

    {
;}
    break;

  case 190:

    {
;}
    break;

  case 193:

    {
;}
    break;

  case 195:

    {
;}
    break;

  case 198:

    {
;}
    break;

  case 200:

    {
;}
    break;

  case 203:

    {
;}
    break;

  case 205:

    {
;}
    break;

  case 208:

    {
;}
    break;

  case 210:

    {
;}
    break;

  case 213:

    {
;}
    break;

  case 215:

    {
;}
    break;

  case 218:

    {
;}
    break;

  case 224:

    {
;}
    break;

  case 225:

    {
;}
    break;

  case 226:

    {
;}
    break;

  case 230:

    {
;}
    break;

  case 233:

    {
;}
    break;

  case 239:

    {
;}
    break;

  case 240:

    {
;}
    break;

  case 241:

    {
;}
    break;

  case 245:

    {
;}
    break;

  case 248:

    {
;}
    break;

  case 254:

    {
;}
    break;

  case 255:

    {
;}
    break;

  case 256:

    {
;}
    break;

  case 260:

    {
;}
    break;

  case 263:

    {
;}
    break;

  case 269:

    {
;}
    break;

  case 270:

    {
;}
    break;

  case 271:

    {
;}
    break;

  case 275:

    {
;}
    break;

  case 278:

    {
;}
    break;

  case 280:

    {
;}
    break;

  case 283:

    {
;}
    break;

  case 285:

    {
;}
    break;

  case 288:

    {
;}
    break;

  case 290:

    {
;}
    break;

  case 297:

    {
;}
    break;

  case 299:

    {
;}
    break;

  case 301:

    {
;}
    break;

  case 303:

    {
;}
    break;

  case 311:

    {
;}
    break;

  case 312:

    {
;}
    break;

  case 313:

    {
;}
    break;

  case 320:

    {
;}
    break;

  case 332:

    {
;}
    break;

  case 333:

    {
;}
    break;

  case 347:

    {
;}
    break;

  case 348:

    {
;}
    break;

  case 349:

    {
;}
    break;

  case 350:

    {
;}
    break;

  case 351:

    {
;}
    break;

  case 352:

    {
;}
    break;

  case 353:

    {
;}
    break;

  case 362:

    {
;}
    break;

  case 363:

    {
;}
    break;

  case 364:

    {
;}
    break;

  case 365:

    {
;}
    break;

  case 371:

    {
;}
    break;

  case 383:

    {
;}
    break;

  case 384:

    {
;}
    break;

  case 396:

    {
;}
    break;

  case 397:

    {
;}
    break;

  case 411:

    {
;}
    break;

  case 412:

    {
;}
    break;

  case 413:

    {
;}
    break;

  case 414:

    {
;}
    break;

  case 415:

    {
;}
    break;

  case 416:

    {
;}
    break;

  case 417:

    {
;}
    break;

  case 426:

    {
;}
    break;

  case 427:

    {
;}
    break;

  case 428:

    {
;}
    break;

  case 429:

    {
;}
    break;

  case 435:

    {
;}
    break;

  case 447:

    {
;}
    break;

  case 448:

    {
;}
    break;

  case 460:

    {
;}
    break;

  case 461:

    {
;}
    break;

  case 475:

    {
;}
    break;

  case 476:

    {
;}
    break;

  case 477:

    {
;}
    break;

  case 478:

    {
;}
    break;

  case 479:

    {
;}
    break;

  case 480:

    {
;}
    break;

  case 481:

    {
;}
    break;

  case 490:

    {
;}
    break;

  case 491:

    {
;}
    break;

  case 492:

    {
;}
    break;

  case 493:

    {
;}
    break;

  case 498:

    {
;}
    break;

  case 510:

    {
;}
    break;

  case 511:

    {
;}
    break;

  case 512:

    {
;}
    break;

  case 513:

    {
;}
    break;

  case 514:

    {
;}
    break;

  case 515:

    {
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


