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
#define YYLAST   647

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  148
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  304
/* YYNRULES -- Number of rules.  */
#define YYNRULES  518
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
     371,   377,   381,   382,   385,   389,   390,   393,   397,   401,
     402,   406,   407,   411,   413,   416,   417,   422,   425,   426,
     429,   431,   433,   435,   437,   440,   444,   449,   455,   459,
     460,   463,   467,   468,   471,   475,   479,   480,   484,   485,
     489,   491,   494,   495,   500,   503,   504,   507,   509,   511,
     513,   515,   517,   519,   521,   523,   525,   527,   529,   531,
     533,   535,   537,   543,   544,   548,   550,   552,   555,   559,
     564,   569,   573,   574,   577,   582,   587,   591,   592,   595,
     600,   606,   610,   611,   614,   619,   625,   629,   630,   633,
     638,   644,   648,   649,   652,   657,   663,   667,   668,   671,
     675,   676,   679,   681,   683,   685,   689,   693,   697,   700,
     702,   708,   712,   713,   716,   720,   721,   724,   726,   728,
     730,   734,   738,   742,   745,   747,   753,   757,   758,   761,
     765,   766,   769,   771,   773,   775,   779,   783,   787,   790,
     792,   798,   802,   803,   806,   810,   811,   814,   816,   818,
     820,   824,   828,   832,   835,   837,   843,   847,   848,   851,
     856,   862,   866,   867,   870,   875,   881,   885,   886,   889,
     894,   900,   904,   905,   908,   912,   913,   916,   920,   924,
     925,   929,   930,   934,   936,   939,   940,   944,   945,   948,
     950,   952,   954,   958,   962,   966,   970,   972,   977,   978,
     982,   983,   987,   992,   994,   995,  1003,  1004,  1007,  1011,
    1012,  1015,  1017,  1019,  1023,  1027,  1030,  1032,  1033,  1037,
    1038,  1041,  1043,  1045,  1047,  1049,  1051,  1053,  1055,  1059,
    1063,  1067,  1071,  1075,  1079,  1083,  1087,  1091,  1092,  1095,
    1097,  1099,  1101,  1103,  1107,  1111,  1115,  1119,  1122,  1124,
    1125,  1129,  1130,  1134,  1140,  1142,  1143,  1151,  1152,  1155,
    1159,  1160,  1163,  1165,  1167,  1171,  1175,  1178,  1180,  1181,
    1189,  1190,  1193,  1197,  1198,  1201,  1203,  1205,  1209,  1213,
    1216,  1218,  1219,  1223,  1224,  1227,  1229,  1231,  1233,  1235,
    1237,  1239,  1241,  1245,  1249,  1253,  1257,  1261,  1265,  1269,
    1273,  1277,  1278,  1281,  1283,  1285,  1287,  1289,  1293,  1297,
    1301,  1305,  1308,  1310,  1311,  1315,  1316,  1320,  1326,  1328,
    1329,  1337,  1338,  1341,  1345,  1346,  1349,  1351,  1353,  1357,
    1361,  1364,  1366,  1367,  1375,  1376,  1379,  1383,  1384,  1387,
    1389,  1391,  1395,  1399,  1402,  1404,  1405,  1409,  1410,  1413,
    1415,  1417,  1419,  1421,  1423,  1425,  1427,  1431,  1435,  1439,
    1443,  1447,  1451,  1455,  1459,  1463,  1464,  1467,  1469,  1471,
    1473,  1475,  1479,  1483,  1487,  1491,  1494,  1496,  1497,  1503,
    1507,  1508,  1511,  1515,  1516,  1519,  1521,  1523,  1525,  1527,
    1529,  1531,  1535,  1539,  1543,  1547,  1551,  1555,  1558
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
      -1,    83,     8,     6,    84,    -1,    83,     8,     5,    84,
      -1,    73,   210,     8,   211,    74,    -1,    15,     3,     7,
      -1,    -1,   211,   212,    -1,    75,   213,   218,    -1,    -1,
     213,   214,    -1,   215,   216,   217,    -1,    36,     3,     7,
      -1,    -1,    38,     3,     7,    -1,    -1,    40,     3,     7,
      -1,     9,    -1,     8,    76,    -1,    -1,    47,     8,   220,
      48,    -1,    47,     9,    -1,    -1,   220,   221,    -1,   222,
      -1,   225,    -1,   223,    -1,   224,    -1,    85,     9,    -1,
      85,     8,    86,    -1,    85,     8,     4,    86,    -1,    73,
     226,     8,   227,    74,    -1,    15,     3,     7,    -1,    -1,
     227,   228,    -1,    75,   229,   234,    -1,    -1,   229,   230,
      -1,   231,   232,   233,    -1,    36,     3,     7,    -1,    -1,
      38,     3,     7,    -1,    -1,    40,     3,     7,    -1,     9,
      -1,     8,    76,    -1,    -1,    49,     8,   236,    50,    -1,
      49,     9,    -1,    -1,   236,   237,    -1,   238,    -1,   240,
      -1,   243,    -1,   247,    -1,   251,    -1,   255,    -1,   259,
      -1,   263,    -1,   273,    -1,   283,    -1,   293,    -1,   303,
      -1,   307,    -1,   311,    -1,   315,    -1,    87,   239,     8,
       4,    88,    -1,    -1,    39,     3,     7,    -1,   241,    -1,
     242,    -1,    89,     9,    -1,    89,     8,    90,    -1,    89,
       8,     4,    90,    -1,    91,   244,   245,    92,    -1,    16,
       3,     7,    -1,    -1,   245,   246,    -1,    61,     8,     4,
      62,    -1,    93,   248,   249,    94,    -1,    17,     3,     7,
      -1,    -1,   249,   250,    -1,    97,     8,     4,    98,    -1,
      95,   252,     8,   253,    96,    -1,    17,     3,     7,    -1,
      -1,   253,   254,    -1,    97,     8,     4,    98,    -1,   101,
     256,     8,   257,   102,    -1,    17,     3,     7,    -1,    -1,
     257,   258,    -1,    97,     8,     4,    98,    -1,   103,   260,
       8,   261,   104,    -1,    17,     3,     7,    -1,    -1,   261,
     262,    -1,    97,     8,     4,    98,    -1,   109,   264,     8,
     265,   110,    -1,    18,     3,     7,    -1,    -1,   265,   266,
      -1,    99,   267,   272,    -1,    -1,   267,   268,    -1,   269,
      -1,   270,    -1,   271,    -1,    19,     3,     7,    -1,    20,
       3,     7,    -1,    21,     3,     7,    -1,     8,   100,    -1,
       9,    -1,   111,   274,     8,   275,   112,    -1,    18,     3,
       7,    -1,    -1,   275,   276,    -1,    99,   277,   282,    -1,
      -1,   277,   278,    -1,   279,    -1,   280,    -1,   281,    -1,
      19,     3,     7,    -1,    20,     3,     7,    -1,    21,     3,
       7,    -1,     8,   100,    -1,     9,    -1,   113,   284,     8,
     285,   114,    -1,    18,     3,     7,    -1,    -1,   285,   286,
      -1,    99,   287,   292,    -1,    -1,   287,   288,    -1,   289,
      -1,   290,    -1,   291,    -1,    19,     3,     7,    -1,    20,
       3,     7,    -1,    21,     3,     7,    -1,     8,   100,    -1,
       9,    -1,   115,   294,     8,   295,   116,    -1,    18,     3,
       7,    -1,    -1,   295,   296,    -1,    99,   297,   302,    -1,
      -1,   297,   298,    -1,   299,    -1,   300,    -1,   301,    -1,
      19,     3,     7,    -1,    20,     3,     7,    -1,    21,     3,
       7,    -1,     8,   100,    -1,     9,    -1,   107,   304,     8,
     305,   108,    -1,    17,     3,     7,    -1,    -1,   305,   306,
      -1,    97,     8,     4,    98,    -1,   105,   308,     8,   309,
     106,    -1,    17,     3,     7,    -1,    -1,   309,   310,    -1,
      97,     8,     4,    98,    -1,   117,   312,     8,   313,   118,
      -1,    25,     3,     7,    -1,    -1,   313,   314,    -1,   119,
       8,     4,   120,    -1,    73,   316,     8,   317,    74,    -1,
      15,     3,     7,    -1,    -1,   317,   318,    -1,    75,   319,
     324,    -1,    -1,   319,   320,    -1,   321,   322,   323,    -1,
      36,     3,     7,    -1,    -1,    38,     3,     7,    -1,    -1,
      40,     3,     7,    -1,     9,    -1,     8,    76,    -1,    -1,
      51,   326,   331,    -1,    -1,   326,   327,    -1,   328,    -1,
     329,    -1,   330,    -1,    27,     3,     7,    -1,    29,     3,
       7,    -1,    28,     3,     7,    -1,     8,   332,    52,    -1,
       9,    -1,   333,   363,   401,   439,    -1,    -1,   121,   334,
     335,    -1,    -1,    30,     3,     7,    -1,     8,   336,   344,
     122,    -1,     9,    -1,    -1,   123,    33,     3,     7,     8,
     337,   124,    -1,    -1,   337,   338,    -1,   125,   339,   343,
      -1,    -1,   339,   340,    -1,   341,    -1,   342,    -1,    37,
       3,     7,    -1,    38,     3,     7,    -1,     8,   126,    -1,
       9,    -1,    -1,    75,   345,   354,    -1,    -1,   345,   346,
      -1,   347,    -1,   348,    -1,   349,    -1,   350,    -1,   351,
      -1,   352,    -1,   353,    -1,    33,     3,     7,    -1,    36,
       3,     7,    -1,    38,     3,     7,    -1,    22,     3,     7,
      -1,    23,     3,     7,    -1,    24,     3,     7,    -1,    40,
       3,     7,    -1,     8,   355,    76,    -1,   125,   356,   362,
      -1,    -1,   356,   357,    -1,   358,    -1,   359,    -1,   360,
      -1,   361,    -1,    37,     3,     7,    -1,    38,     3,     7,
      -1,    41,     3,     7,    -1,    42,     3,     7,    -1,     8,
     126,    -1,     9,    -1,    -1,   127,   364,   365,    -1,    -1,
      31,     3,     7,    -1,     8,   366,   374,   382,   128,    -1,
       9,    -1,    -1,   129,    34,     3,     7,     8,   367,   130,
      -1,    -1,   367,   368,    -1,   131,   369,   373,    -1,    -1,
     369,   370,    -1,   371,    -1,   372,    -1,    37,     3,     7,
      -1,    38,     3,     7,    -1,     8,   132,    -1,     9,    -1,
      -1,   133,    34,     3,     7,     8,   375,   134,    -1,    -1,
     375,   376,    -1,   131,   377,   381,    -1,    -1,   377,   378,
      -1,   379,    -1,   380,    -1,    37,     3,     7,    -1,    38,
       3,     7,    -1,     8,   132,    -1,     9,    -1,    -1,    75,
     383,   392,    -1,    -1,   383,   384,    -1,   385,    -1,   386,
      -1,   387,    -1,   388,    -1,   389,    -1,   390,    -1,   391,
      -1,    34,     3,     7,    -1,    36,     3,     7,    -1,    38,
       3,     7,    -1,    22,     3,     7,    -1,    23,     3,     7,
      -1,    24,     3,     7,    -1,    40,     3,     7,    -1,     8,
     393,    76,    -1,   131,   394,   400,    -1,    -1,   394,   395,
      -1,   396,    -1,   397,    -1,   398,    -1,   399,    -1,    37,
       3,     7,    -1,    38,     3,     7,    -1,    41,     3,     7,
      -1,    42,     3,     7,    -1,     8,   126,    -1,     9,    -1,
      -1,   135,   402,   403,    -1,    -1,    32,     3,     7,    -1,
       8,   404,   412,   420,   136,    -1,     9,    -1,    -1,   137,
      35,     3,     7,     8,   405,   138,    -1,    -1,   405,   406,
      -1,   139,   407,   411,    -1,    -1,   407,   408,    -1,   409,
      -1,   410,    -1,    37,     3,     7,    -1,    38,     3,     7,
      -1,     8,   140,    -1,     9,    -1,    -1,   141,    35,     3,
       7,     8,   413,   142,    -1,    -1,   413,   414,    -1,   139,
     415,   419,    -1,    -1,   415,   416,    -1,   417,    -1,   418,
      -1,    37,     3,     7,    -1,    38,     3,     7,    -1,     8,
     140,    -1,     9,    -1,    -1,    75,   421,   430,    -1,    -1,
     421,   422,    -1,   423,    -1,   424,    -1,   425,    -1,   426,
      -1,   427,    -1,   428,    -1,   429,    -1,    35,     3,     7,
      -1,    36,     3,     7,    -1,    38,     3,     7,    -1,    22,
       3,     7,    -1,    23,     3,     7,    -1,    24,     3,     7,
      -1,    40,     3,     7,    -1,     8,   431,    76,    -1,   139,
     432,   438,    -1,    -1,   432,   433,    -1,   434,    -1,   435,
      -1,   436,    -1,   437,    -1,    37,     3,     7,    -1,    38,
       3,     7,    -1,    41,     3,     7,    -1,    42,     3,     7,
      -1,     8,   140,    -1,     9,    -1,    -1,   143,   440,     8,
     441,   144,    -1,    26,     3,     7,    -1,    -1,   441,   442,
      -1,   145,   443,   451,    -1,    -1,   443,   444,    -1,   445,
      -1,   446,    -1,   447,    -1,   448,    -1,   449,    -1,   450,
      -1,    36,     3,     7,    -1,    38,     3,     7,    -1,    22,
       3,     7,    -1,    23,     3,     7,    -1,    24,     3,     7,
      -1,    40,     3,     7,    -1,     8,   146,    -1,     9,    -1
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
     326,   327,   331,   331,   335,   335,   337,   338,   342,   343,
     347,   349,   353,   353,   355,   357,   357,   359,   361,   365,
     365,   369,   369,   373,   373,   378,   379,   380,   382,   382,
     384,   384,   386,   386,   388,   389,   393,   398,   400,   404,
     404,   406,   408,   408,   410,   412,   416,   416,   420,   420,
     424,   424,   429,   430,   431,   433,   433,   435,   435,   435,
     435,   435,   436,   436,   436,   436,   436,   437,   437,   437,
     437,   437,   439,   443,   443,   447,   447,   449,   450,   454,
     458,   460,   464,   464,   467,   471,   474,   478,   478,   480,
     484,   487,   491,   491,   493,   497,   500,   504,   504,   506,
     510,   513,   517,   517,   519,   523,   526,   530,   530,   532,
     536,   536,   538,   538,   538,   540,   544,   548,   552,   552,
     555,   558,   562,   562,   564,   568,   568,   570,   570,   570,
     572,   576,   580,   584,   584,   587,   590,   594,   594,   596,
     600,   600,   602,   602,   602,   604,   608,   612,   616,   616,
     619,   622,   626,   626,   628,   632,   632,   634,   634,   634,
     636,   640,   644,   648,   648,   652,   655,   659,   659,   661,
     665,   668,   672,   672,   674,   679,   682,   686,   686,   688,
     693,   695,   699,   699,   701,   703,   703,   705,   707,   711,
     711,   715,   715,   719,   719,   724,   724,   726,   726,   728,
     728,   728,   730,   734,   738,   742,   742,   744,   746,   746,
     748,   748,   752,   753,   755,   755,   758,   758,   760,   762,
     762,   764,   764,   766,   770,   774,   774,   777,   777,   779,
     779,   782,   783,   784,   785,   786,   787,   788,   790,   794,
     798,   802,   806,   810,   814,   819,   821,   823,   823,   826,
     827,   828,   829,   831,   835,   839,   843,   847,   847,   849,
     849,   851,   851,   855,   857,   860,   860,   863,   863,   865,
     867,   867,   869,   869,   871,   875,   879,   879,   882,   882,
     885,   885,   887,   889,   889,   891,   891,   893,   897,   901,
     901,   904,   904,   906,   906,   909,   910,   911,   912,   913,
     914,   915,   917,   921,   925,   929,   933,   937,   941,   946,
     948,   950,   950,   953,   954,   955,   956,   958,   962,   966,
     970,   974,   974,   976,   976,   978,   978,   982,   984,   986,
     986,   989,   989,   991,   993,   993,   995,   995,   997,  1001,
    1005,  1005,  1008,  1008,  1011,  1011,  1013,  1015,  1015,  1017,
    1017,  1019,  1023,  1027,  1027,  1030,  1030,  1032,  1032,  1035,
    1036,  1037,  1038,  1039,  1040,  1041,  1043,  1047,  1051,  1055,
    1059,  1063,  1067,  1072,  1074,  1076,  1076,  1079,  1080,  1081,
    1082,  1084,  1088,  1092,  1096,  1100,  1100,  1103,  1103,  1105,
    1109,  1109,  1111,  1113,  1113,  1116,  1117,  1118,  1119,  1120,
    1121,  1123,  1127,  1131,  1135,  1139,  1143,  1148,  1148
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
     204,   204,   205,   205,   206,   206,   207,   207,   208,   208,
     209,   210,   211,   211,   212,   213,   213,   214,   215,   216,
     216,   217,   217,   218,   218,   219,   219,   219,   220,   220,
     221,   221,   222,   222,   223,   223,   224,   225,   226,   227,
     227,   228,   229,   229,   230,   231,   232,   232,   233,   233,
     234,   234,   235,   235,   235,   236,   236,   237,   237,   237,
     237,   237,   237,   237,   237,   237,   237,   237,   237,   237,
     237,   237,   238,   239,   239,   240,   240,   241,   241,   242,
     243,   244,   245,   245,   246,   247,   248,   249,   249,   250,
     251,   252,   253,   253,   254,   255,   256,   257,   257,   258,
     259,   260,   261,   261,   262,   263,   264,   265,   265,   266,
     267,   267,   268,   268,   268,   269,   270,   271,   272,   272,
     273,   274,   275,   275,   276,   277,   277,   278,   278,   278,
     279,   280,   281,   282,   282,   283,   284,   285,   285,   286,
     287,   287,   288,   288,   288,   289,   290,   291,   292,   292,
     293,   294,   295,   295,   296,   297,   297,   298,   298,   298,
     299,   300,   301,   302,   302,   303,   304,   305,   305,   306,
     307,   308,   309,   309,   310,   311,   312,   313,   313,   314,
     315,   316,   317,   317,   318,   319,   319,   320,   321,   322,
     322,   323,   323,   324,   324,   325,   325,   326,   326,   327,
     327,   327,   328,   329,   330,   331,   331,   332,   333,   333,
     334,   334,   335,   335,   336,   336,   337,   337,   338,   339,
     339,   340,   340,   341,   342,   343,   343,   344,   344,   345,
     345,   346,   346,   346,   346,   346,   346,   346,   347,   348,
     349,   350,   351,   352,   353,   354,   355,   356,   356,   357,
     357,   357,   357,   358,   359,   360,   361,   362,   362,   363,
     363,   364,   364,   365,   365,   366,   366,   367,   367,   368,
     369,   369,   370,   370,   371,   372,   373,   373,   374,   374,
     375,   375,   376,   377,   377,   378,   378,   379,   380,   381,
     381,   382,   382,   383,   383,   384,   384,   384,   384,   384,
     384,   384,   385,   386,   387,   388,   389,   390,   391,   392,
     393,   394,   394,   395,   395,   395,   395,   396,   397,   398,
     399,   400,   400,   401,   401,   402,   402,   403,   403,   404,
     404,   405,   405,   406,   407,   407,   408,   408,   409,   410,
     411,   411,   412,   412,   413,   413,   414,   415,   415,   416,
     416,   417,   418,   419,   419,   420,   420,   421,   421,   422,
     422,   422,   422,   422,   422,   422,   423,   424,   425,   426,
     427,   428,   429,   430,   431,   432,   432,   433,   433,   433,
     433,   434,   435,   436,   437,   438,   438,   439,   439,   440,
     441,   441,   442,   443,   443,   444,   444,   444,   444,   444,
     444,   445,   446,   447,   448,   449,   450,   451,   451
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
       5,     5,     0,     3,     1,     1,     2,     3,     4,     4,
       5,     3,     0,     2,     3,     0,     2,     3,     3,     0,
       3,     0,     3,     1,     2,     0,     4,     2,     0,     2,
       1,     1,     1,     1,     2,     3,     4,     5,     3,     0,
       2,     3,     0,     2,     3,     3,     0,     3,     0,     3,
       1,     2,     0,     4,     2,     0,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     5,     0,     3,     1,     1,     2,     3,     4,
       4,     3,     0,     2,     4,     4,     3,     0,     2,     4,
       5,     3,     0,     2,     4,     5,     3,     0,     2,     4,
       5,     3,     0,     2,     4,     5,     3,     0,     2,     3,
       0,     2,     1,     1,     1,     3,     3,     3,     2,     1,
       5,     3,     0,     2,     3,     0,     2,     1,     1,     1,
       3,     3,     3,     2,     1,     5,     3,     0,     2,     3,
       0,     2,     1,     1,     1,     3,     3,     3,     2,     1,
       5,     3,     0,     2,     3,     0,     2,     1,     1,     1,
       3,     3,     3,     2,     1,     5,     3,     0,     2,     4,
       5,     3,     0,     2,     4,     5,     3,     0,     2,     4,
       5,     3,     0,     2,     3,     0,     2,     3,     3,     0,
       3,     0,     3,     1,     2,     0,     3,     0,     2,     1,
       1,     1,     3,     3,     3,     3,     1,     4,     0,     3,
       0,     3,     4,     1,     0,     7,     0,     2,     3,     0,
       2,     1,     1,     3,     3,     2,     1,     0,     3,     0,
       2,     1,     1,     1,     1,     1,     1,     1,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     0,     2,     1,
       1,     1,     1,     3,     3,     3,     3,     2,     1,     0,
       3,     0,     3,     5,     1,     0,     7,     0,     2,     3,
       0,     2,     1,     1,     3,     3,     2,     1,     0,     7,
       0,     2,     3,     0,     2,     1,     1,     3,     3,     2,
       1,     0,     3,     0,     2,     1,     1,     1,     1,     1,
       1,     1,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     0,     2,     1,     1,     1,     1,     3,     3,     3,
       3,     2,     1,     0,     3,     0,     3,     5,     1,     0,
       7,     0,     2,     3,     0,     2,     1,     1,     3,     3,
       2,     1,     0,     7,     0,     2,     3,     0,     2,     1,
       1,     3,     3,     2,     1,     0,     3,     0,     2,     1,
       1,     1,     1,     1,     1,     1,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     0,     2,     1,     1,     1,
       1,     3,     3,     3,     3,     2,     1,     0,     5,     3,
       0,     2,     3,     0,     2,     1,     1,     1,     1,     1,
       1,     3,     3,     3,     3,     3,     3,     2,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       0,     4,     0,     0,     5,     1,     7,     3,     0,     0,
      92,    10,     9,     2,     0,   135,     0,    95,    94,     0,
     162,     8,     0,     0,     0,    43,     0,     0,     0,     0,
       0,    75,     0,    11,    12,    23,    24,    13,    28,    29,
      14,    33,    34,    15,    38,    39,    16,    45,    46,    17,
      50,    51,    18,    55,    56,    19,    60,    61,    20,    65,
      66,    21,    70,    71,    22,     0,   138,   137,     0,   305,
       0,    25,     0,    30,     0,    35,    40,     0,     0,     0,
      47,     0,    52,     0,    57,     0,    62,     0,    67,    72,
       0,     0,     0,     0,    93,     0,   104,   108,   112,     0,
      96,    97,    98,    99,   100,   114,   115,   101,     0,   165,
     164,   307,     6,     0,    26,     0,    31,     0,    36,     0,
       0,     0,    48,     0,    53,     0,    58,     0,    63,     0,
      68,     0,     0,     0,    79,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   116,   136,     0,     0,   139,   140,
     142,   143,   141,     0,     0,    27,    32,    37,    44,     0,
      41,    49,    54,    59,    64,    69,    76,     0,    73,    78,
       0,     0,   122,     0,     0,     0,     0,     0,     0,     0,
       0,   117,     0,     0,     0,   144,   163,     0,   183,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   166,   167,   168,   185,   186,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     318,   316,     0,     0,     0,   308,   309,   310,   311,   306,
      42,    74,    77,    82,    80,   121,     0,   105,     0,     0,
     109,     0,     0,   113,     0,     0,   119,   118,     0,   149,
       0,   145,     0,     0,     0,     0,     0,   187,     0,   192,
       0,   197,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   320,     0,   369,     0,     0,     0,     0,   120,
     125,   123,   103,   102,   107,   106,   111,   110,   148,     0,
     146,     0,   292,     0,     0,     0,   188,     0,     0,     0,
       0,     0,   202,     0,   207,     0,   212,     0,   282,     0,
     277,     0,   217,     0,   232,     0,   247,     0,   262,     0,
     287,     0,     0,   315,   371,   433,   312,   314,   313,     0,
      90,     0,    83,    86,    81,     0,   147,   152,   150,   291,
       0,   184,     0,   189,   191,     0,   190,   193,   196,   195,
       0,   198,   201,     0,   206,     0,   211,     0,   281,     0,
     276,     0,   216,     0,   231,     0,   246,     0,   261,     0,
     286,     0,     0,   324,   323,   319,     0,     0,   435,   497,
      91,     0,     0,    88,     0,   133,     0,   126,   129,   124,
       0,   290,   295,   293,   182,     0,     0,   200,     0,   203,
       0,   205,   208,     0,   210,   213,     0,   280,   283,     0,
     275,   278,   220,   215,   218,   235,   230,   233,   250,   245,
     248,   265,   260,   263,   285,     0,   288,   321,     0,   337,
       0,   375,   374,   370,     0,     0,     0,   317,    85,     0,
       0,    84,   134,     0,     0,   131,     0,   160,     0,   153,
     156,   151,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   339,     0,   372,     0,
     388,     0,   439,   438,   434,     0,     0,    87,     0,   128,
       0,     0,   127,   161,     0,     0,   158,     0,   303,     0,
     296,   299,   294,   194,   199,     0,     0,     0,     0,     0,
       0,   229,     0,     0,     0,   221,   222,   223,   224,   219,
       0,   244,     0,     0,     0,   236,   237,   238,   239,   234,
       0,   259,     0,     0,     0,   251,   252,   253,   254,   249,
       0,   274,     0,     0,     0,   266,   267,   268,   269,   264,
       0,     0,     0,   322,     0,     0,   401,   436,     0,   452,
       0,   500,    89,   130,     0,   155,     0,     0,   154,   304,
       0,     0,   301,   204,   209,   214,   284,   279,   228,     0,
       0,     0,   243,     0,     0,     0,   258,     0,     0,     0,
     273,     0,     0,     0,   289,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   340,   341,   342,   343,   344,   345,
     346,   347,   338,     0,     0,   403,     0,     0,     0,   465,
     499,     0,   132,   157,     0,   298,     0,     0,   297,   225,
     226,   227,   240,   241,   242,   255,   256,   257,   270,   271,
     272,   326,   357,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   373,     0,     0,   467,     0,   498,
     503,   501,   159,   300,     0,     0,     0,   355,   351,   352,
     353,   348,   349,   350,   354,   377,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   404,   405,   406,   407,   408,
     409,   410,   411,   402,     0,     0,     0,   437,     0,   302,
     325,   329,   327,     0,   368,     0,     0,     0,     0,   358,
     359,   360,   361,   362,   356,     0,   390,   421,     0,     0,
       0,     0,     0,     0,     0,     0,   441,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   468,   469,   470,   471,
     472,   473,   474,   475,   466,     0,   518,     0,     0,     0,
       0,     0,     0,   504,   505,   506,   507,   508,   509,   510,
     502,     0,   367,     0,     0,     0,     0,   376,   380,   378,
       0,     0,   419,   415,   416,   417,   412,   413,   414,   418,
       0,   454,   485,     0,     0,     0,     0,     0,     0,     0,
       0,   517,     0,     0,     0,     0,     0,     0,     0,   336,
       0,     0,   330,   331,   332,   328,   363,   364,   365,   366,
       0,   393,   389,   391,     0,   432,     0,     0,     0,     0,
     422,   423,   424,   425,   426,   420,   440,   444,   442,     0,
       0,   483,   479,   480,   481,   476,   477,   478,   482,   513,
     514,   515,   511,   512,   516,   335,     0,     0,     0,   387,
       0,     0,   381,   382,   383,   379,     0,   431,     0,     0,
       0,     0,     0,   457,   453,   455,     0,   496,     0,     0,
       0,     0,   486,   487,   488,   489,   490,   484,   333,   334,
     386,     0,     0,     0,   400,     0,     0,   394,   395,   396,
     392,   427,   428,   429,   430,     0,   451,     0,     0,   445,
     446,   447,   443,     0,   495,     0,     0,     0,     0,   384,
     385,   399,     0,     0,   450,     0,     0,     0,   464,     0,
       0,   458,   459,   460,   456,   491,   492,   493,   494,   397,
     398,   448,   449,   463,     0,     0,   461,   462
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,     9,    10,    16,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    78,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    91,    64,
      93,   170,   234,   288,   342,   343,   393,   451,   344,    15,
      65,   100,   101,   138,   102,   140,   103,   142,   104,   105,
     106,   107,   136,   236,   291,   345,   397,   398,   455,   492,
     399,    20,   108,   148,   149,   150,   151,   152,   183,   299,
     348,   400,   459,   460,   496,   568,   461,    69,   153,   202,
     203,   255,   204,   205,   206,   207,   259,   308,   357,   208,
     261,   310,   361,   209,   263,   363,   409,   210,   265,   365,
     412,   211,   267,   367,   415,   212,   273,   373,   424,   470,
     515,   516,   517,   518,   519,   213,   275,   375,   427,   471,
     525,   526,   527,   528,   529,   214,   277,   377,   430,   472,
     535,   536,   537,   538,   539,   215,   279,   379,   433,   473,
     545,   546,   547,   548,   549,   216,   271,   371,   421,   217,
     269,   369,   418,   218,   281,   381,   436,   219,   253,   350,
     403,   462,   500,   501,   572,   628,   502,   112,   154,   225,
     226,   227,   228,   229,   283,   284,   332,   385,   439,   665,
     702,   761,   802,   803,   804,   805,   477,   552,   604,   605,
     606,   607,   608,   609,   610,   611,   612,   643,   666,   709,
     710,   711,   712,   713,   714,   335,   387,   443,   480,   715,
     769,   810,   852,   853,   854,   855,   556,   770,   813,   856,
     887,   888,   889,   890,   616,   653,   685,   686,   687,   688,
     689,   690,   691,   692,   693,   718,   771,   820,   821,   822,
     823,   824,   825,   389,   445,   484,   559,   780,   828,   862,
     899,   900,   901,   902,   619,   829,   865,   903,   921,   922,
     923,   924,   658,   696,   736,   737,   738,   739,   740,   741,
     742,   743,   744,   783,   830,   872,   873,   874,   875,   876,
     877,   447,   486,   621,   661,   698,   753,   754,   755,   756,
     757,   758,   759,   760
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -89
static const yytype_int16 yypact[] =
{
      27,    53,    56,   162,   -89,   -89,   -23,   -89,   168,    42,
      50,   -89,   -89,   -89,   220,    58,   149,   -89,   -89,   222,
      77,   -89,   224,   232,   234,    83,   236,   238,   240,   242,
     244,     9,    95,   -89,   -89,   -89,   -89,   -89,   -89,   -89,
     -89,   -89,   -89,   -89,   -89,   -89,   -89,   -89,   -89,   -89,
     -89,   -89,   -89,   -89,   -89,   -89,   -89,   -89,   -89,   -89,
     -89,   -89,   -89,   -89,   -89,   -37,   -89,   -89,   246,    49,
      23,   -89,    20,   -89,     8,   -89,   -89,   116,   120,     6,
     -89,    10,   -89,     4,   -89,     3,   -89,     2,   -89,   -89,
     140,   122,   142,   139,   -89,   172,   115,   166,   170,   248,
     -89,   -89,   -89,   -89,   -89,   -89,   -89,   -89,   -35,   -89,
     -89,   -89,   -89,   135,   -89,   145,   -89,   141,   -89,   200,
      15,   151,   -89,   147,   -89,   153,   -89,   157,   -89,   210,
     -89,   208,     1,   214,   -89,   292,   209,   293,   289,   295,
     291,   297,   294,    -2,   -89,   -89,   286,   250,   -89,   -89,
     -89,   -89,   -89,   -48,   152,   -89,   -89,   -89,   -89,   243,
     -89,   -89,   -89,   -89,   -89,   -89,   -89,   233,   -89,   -89,
     186,   299,   -89,   300,   257,   301,   259,   302,   261,   226,
     227,   -89,   309,   296,    -3,   -89,   -89,   298,   276,   260,
     303,   304,   305,   306,   307,   308,   310,   311,   312,   313,
     314,   315,   -89,   -89,   -89,   -89,   -89,   -89,   -89,   -89,
     -89,   -89,   -89,   -89,   -89,   -89,   -89,   -89,   -89,   -89,
     193,   -89,   317,   323,   325,   -89,   -89,   -89,   -89,   -89,
     -89,   -89,   -89,   -89,   -89,   -89,   196,   -89,   239,   255,
     -89,   254,   256,   -89,   253,   262,   -89,   -89,   330,   -89,
     230,   -89,   335,   331,   338,   334,    -4,   -89,   340,   -89,
     342,   -89,   343,   339,   345,   341,   347,   344,   348,   346,
     350,   349,   352,   351,   353,   354,   355,   356,   357,   358,
     360,   359,   288,   316,   245,   362,   363,   364,    13,   -89,
     -89,   -89,   -89,   -89,   -89,   -89,   -89,   -89,   -89,   198,
     -89,   366,   -89,   367,   361,   271,   -89,   368,   -44,   369,
      81,   370,   -89,   371,   -89,   372,   -89,   373,   -89,   374,
     -89,   375,   -89,   376,   -89,   377,   -89,   378,   -89,   379,
     -89,   384,   266,   -89,   365,   258,   -89,   -89,   -89,   318,
     -89,   385,   -89,   380,   -89,    22,   -89,   -89,   -89,   -89,
     202,   -89,   319,   -89,   -89,   381,   -89,   -89,   -89,   -89,
     382,   -89,   -89,   182,   -89,    54,   -89,    45,   -89,     0,
     -89,   -82,   -89,    -1,   -89,   -83,   -89,   -10,   -89,   -88,
     -89,   163,   388,   268,   -89,   -89,   389,   275,   383,   263,
     -89,   390,   395,   386,   324,   -89,   396,   -89,   387,   -89,
      24,   -89,   -89,   -89,   -89,   397,   398,   -89,   400,   -89,
     401,   -89,   -89,   402,   -89,   -89,   403,   -89,   -89,   404,
     -89,   -89,   -89,   -89,   -89,   -89,   -89,   -89,   -89,   -89,
     -89,   -89,   -89,   -89,   -89,   405,   -89,   -89,   391,   328,
     407,   287,   -89,   -89,   414,   277,   393,   -89,   -89,   413,
     418,   -89,   -89,   415,   420,   392,   329,   -89,   424,   -89,
     399,   -89,    26,   394,   332,   425,   427,   429,   430,   431,
      82,   175,   215,   218,   432,   435,   -89,   282,   -89,   406,
     320,   421,   321,   -89,   -89,   436,   433,   -89,   437,   -89,
     438,   439,   -89,   -89,   440,   443,   408,   409,   -89,   446,
     -89,   412,   -89,   -89,   -89,   410,   411,   416,   417,   419,
     422,   -89,   448,   449,   451,   -89,   -89,   -89,   -89,   -89,
     423,   -89,   452,   454,   456,   -89,   -89,   -89,   -89,   -89,
     426,   -89,   457,   458,   459,   -89,   -89,   -89,   -89,   -89,
     428,   -89,   460,   461,   462,   -89,   -89,   -89,   -89,   -89,
     434,   463,    91,   -89,   464,   441,   444,   -89,   442,   327,
     465,   -89,   -89,   -89,   466,   -89,   467,   468,   -89,   -89,
     469,   475,   447,   -89,   -89,   -89,   -89,   -89,   -89,   472,
     473,   474,   -89,   476,   477,   479,   -89,   481,   482,   483,
     -89,   484,   485,   486,   -89,   487,   445,   491,   493,   494,
     495,   496,   497,   498,   -89,   -89,   -89,   -89,   -89,   -89,
     -89,   -89,   -89,   499,   500,   -89,   450,   501,   470,   455,
     -89,   143,   -89,   -89,   503,   -89,   504,   509,   -89,   -89,
     -89,   -89,   -89,   -89,   -89,   -89,   -89,   -89,   -89,   -89,
     -89,   -89,   -89,   453,   506,   511,   513,   514,   517,   518,
     520,   508,   524,   110,   -89,   525,   530,   -89,   333,   -89,
     -89,   -89,   -89,   -89,   527,   165,    43,   -89,   -89,   -89,
     -89,   -89,   -89,   -89,   -89,   -89,   528,   471,   532,   534,
     535,   536,   537,   538,   539,   -89,   -89,   -89,   -89,   -89,
     -89,   -89,   -89,   -89,   540,   542,   117,   -89,   150,   -89,
     -89,   -89,   -89,   478,   -89,   541,   543,   544,   547,   -89,
     -89,   -89,   -89,   -89,   -89,   161,   -89,   -89,   480,   545,
     546,   548,   550,   551,   552,   553,   -89,   554,   488,   558,
     560,   561,   562,   563,   564,   565,   -89,   -89,   -89,   -89,
     -89,   -89,   -89,   -89,   -89,   336,   -89,   566,   568,   569,
     570,   571,   572,   -89,   -89,   -89,   -89,   -89,   -89,   -89,
     -89,    85,   -89,   573,   574,   575,   576,   -89,   -89,   -89,
      51,    70,   -89,   -89,   -89,   -89,   -89,   -89,   -89,   -89,
     155,   -89,   -89,   510,   577,   578,   580,   581,   582,   583,
     584,   -89,   585,   586,   587,   588,   589,   590,   489,   -89,
     595,   596,   -89,   -89,   -89,   -89,   -89,   -89,   -89,   -89,
     127,   -89,   -89,   -89,   490,   -89,   597,   598,   600,   602,
     -89,   -89,   -89,   -89,   -89,   -89,   -89,   -89,   -89,    61,
      79,   -89,   -89,   -89,   -89,   -89,   -89,   -89,   -89,   -89,
     -89,   -89,   -89,   -89,   -89,   -89,   599,   601,   492,   -89,
     604,   606,   -89,   -89,   -89,   -89,   129,   -89,   603,   605,
     607,   610,   154,   -89,   -89,   -89,   326,   -89,   608,   615,
     616,   617,   -89,   -89,   -89,   -89,   -89,   -89,   -89,   -89,
     -89,   614,   618,   502,   -89,   619,   620,   -89,   -89,   -89,
     -89,   -89,   -89,   -89,   -89,   505,   -89,   623,   625,   -89,
     -89,   -89,   -89,   160,   -89,   622,   624,   626,   628,   -89,
     -89,   -89,   629,   630,   -89,   631,   632,   507,   -89,   627,
     637,   -89,   -89,   -89,   -89,   -89,   -89,   -89,   -89,   -89,
     -89,   -89,   -89,   -89,   634,   635,   -89,   -89
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -89,   -89,   -89,   -89,   -89,   -89,   -89,   -89,   -89,   -89,
     -89,   -89,   -89,   -89,   -89,   -89,   -89,   -89,   -89,   -89,
     -89,   -89,   -89,   -89,   -89,   -89,   -89,   -89,   -89,   -89,
     -89,   -89,   -89,   -89,   -89,   -89,   -89,   -89,   -89,   -89,
     -89,   -89,   -89,   -89,   -89,   -89,   -89,   -89,   -89,   -89,
     -89,   -89,   -89,   -89,   -89,   -89,   -89,   -89,   -89,   -89,
     -89,   -89,   -89,   -89,   -89,   -89,   -89,   -89,   -89,   -89,
     -89,   -89,   -89,   -89,   -89,   -89,   -89,   -89,   -89,   -89,
     -89,   -89,   -89,   -89,   -89,   -89,   -89,   -89,   -89,   -89,
     -89,   -89,   -89,   -89,   -89,   -89,   -89,   -89,   -89,   -89,
     -89,   -89,   -89,   -89,   -89,   -89,   -89,   -89,   -89,   -89,
     -89,   -89,   -89,   -89,   -89,   -89,   -89,   -89,   -89,   -89,
     -89,   -89,   -89,   -89,   -89,   -89,   -89,   -89,   -89,   -89,
     -89,   -89,   -89,   -89,   -89,   -89,   -89,   -89,   -89,   -89,
     -89,   -89,   -89,   -89,   -89,   -89,   -89,   -89,   -89,   -89,
     -89,   -89,   -89,   -89,   -89,   -89,   -89,   -89,   -89,   -89,
     -89,   -89,   -89,   -89,   -89,   -89,   -89,   -89,   -89,   -89,
     -89,   -89,   -89,   -89,   -89,   -89,   -89,   -89,   -89,   -89,
     -89,   -89,   -89,   -89,   -89,   -89,   -89,   -89,   -89,   -89,
     -89,   -89,   -89,   -89,   -89,   -89,   -89,   -89,   -89,   -89,
     -89,   -89,   -89,   -89,   -89,   -89,   -89,   -89,   -89,   -89,
     -89,   -89,   -89,   -89,   -89,   -89,   -89,   -89,   -89,   -89,
     -89,   -89,   -89,   -89,   -89,   -89,   -89,   -89,   -89,   -89,
     -89,   -89,   -89,   -89,   -89,   -89,   -89,   -89,   -89,   -89,
     -89,   -89,   -89,   -89,   -89,   -89,   -89,   -89,   -89,   -89,
     -89,   -89,   -89,   -89,   -89,   -89,   -89,   -89,   -89,   -89,
     -89,   -89,   -89,   -89,   -89,   -89,   -89,   -89,   -89,   -89,
     -89,   -89,   -89,   -89,   -89,   -89,   -89,   -89,   -89,   -89,
     -89,   -89,   -89,   -89,   -89,   -89,   -89,   -89,   -89,   -89,
     -89,   -89,   -89,   -89,   -89,   -89,   -89,   -89,   -89,   -89,
     -89,   -89,   -89,   -89
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint16 yytable[] =
{
     305,   250,   186,   179,   180,   167,   129,   127,   125,    94,
     121,   431,   117,   145,   123,   419,   425,   355,    89,   159,
       8,   339,   340,    90,   115,   187,   420,   113,   432,   426,
     394,   395,   456,   457,   497,   498,    95,     1,   146,   188,
      96,   189,    97,   190,    98,   191,    99,   192,   356,   341,
     147,   703,   704,   193,    13,   194,     5,   195,   396,   196,
     458,   197,   499,   198,     4,   199,   118,   200,   122,   201,
     126,   128,   130,   168,   124,   160,   116,   114,   814,   815,
     705,   706,   181,   251,   707,   708,   306,   866,   867,   428,
     510,   511,    76,   798,   799,    14,    77,   416,   422,   596,
     111,   512,   513,   514,   429,    19,   417,   816,   817,   423,
      92,   818,   819,   597,   598,   599,   868,   869,   677,   119,
     870,   871,   800,   801,   600,   728,    68,   601,   120,   602,
     132,   603,   678,   679,   680,   848,   849,   883,   884,   729,
     730,   731,   413,   131,   681,   133,   682,   134,   683,   414,
     684,   410,   732,   733,   137,   734,   411,   735,   745,   746,
     220,   221,   895,   896,   850,   851,   885,   886,   917,   918,
       6,     7,   747,   748,   749,   359,    11,    12,   360,   222,
     223,   224,   811,   520,   521,   812,   750,   135,   751,   155,
     752,   897,   898,    21,   522,   523,   524,   919,   920,   157,
     863,   156,    22,   864,    23,   139,    24,   158,    25,   141,
      26,   162,    27,   161,    28,   166,    29,   172,    30,   163,
      31,   169,    32,   530,   531,   164,   540,   541,    17,    18,
      66,    67,    70,    71,   532,   533,   534,   542,   543,   544,
      72,    73,    74,    75,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,   109,   110,   143,   144,   184,   185,
     232,   233,   238,   239,   241,   242,   244,   245,   256,   257,
     289,   290,   346,   347,   383,   384,   401,   402,   407,   408,
     165,   434,   435,   441,   442,   482,   483,   659,   660,   700,
     701,   767,   768,   826,   827,   171,   173,   174,   175,   176,
     177,   182,   178,   230,   249,   231,   235,   237,   240,   243,
     246,   247,   248,   252,   282,   254,   300,   292,   331,   258,
     285,   260,   262,   264,   266,   268,   286,   270,   287,   272,
     274,   276,   278,   293,   294,   296,   295,   298,   301,   302,
     280,   303,   304,   307,   297,   309,   311,   312,   313,   314,
     315,   317,   316,   319,   318,   321,   323,   320,   325,   322,
     327,   353,   324,   329,   326,   352,   328,   330,   333,   336,
     337,   338,   334,   349,   351,   354,   358,   362,   364,   366,
     368,   370,   372,   374,   376,   378,   380,   382,   391,   405,
     406,   438,   440,   388,   390,   437,   386,   448,   449,   453,
     452,   463,   464,   476,   553,   493,   446,   404,   465,   466,
     467,   468,   469,   474,   478,   444,   479,   481,   392,   485,
     487,   488,   489,   490,   475,   454,   450,   494,   557,   505,
     504,   506,   491,   507,   508,   509,   550,   495,   551,   560,
     554,   561,   564,     0,   562,   563,   566,   565,   567,   570,
     571,   579,   580,   555,   581,   583,   503,   584,   558,   585,
     587,   588,   589,   591,   592,   593,   904,   613,   618,   697,
     595,   624,   620,   622,   623,   614,   625,   617,   626,   629,
     630,   631,   791,   632,   633,   569,   634,   627,   635,   636,
     637,   638,   639,   640,   644,   641,   645,   646,   647,   648,
     649,   650,     0,   652,   655,   656,   651,     0,   573,   574,
     662,   663,   664,   668,   575,   576,   675,   577,   669,   615,
     670,   671,   578,   582,   672,   673,   586,   674,   590,   667,
     657,   676,   694,   695,   699,   719,   716,   720,   721,   722,
     723,   724,   725,     0,   763,     0,   764,   765,   726,   727,
     766,     0,   773,   774,   594,   775,   772,   776,   777,   778,
     779,   784,   781,   785,   786,   787,   788,   789,   790,   792,
     642,   793,   794,   795,   796,   797,     0,     0,   654,     0,
     806,   807,   808,   809,   832,   833,   831,   834,   835,   836,
     837,   838,   839,   840,   841,   842,   843,   844,   846,   847,
     858,   859,   717,   860,   762,   861,   878,   881,   879,   882,
     891,   905,   892,     0,   893,   845,   857,   894,   906,   907,
     908,   909,   912,   913,   880,   910,   915,   782,   916,   925,
     934,   926,     0,   927,   911,   928,   929,   930,   931,   932,
     935,   936,   937,     0,     0,   914,     0,   933
};

static const yytype_int16 yycheck[] =
{
       4,     4,    50,     5,     6,     4,     4,     4,     4,    46,
       4,    99,     4,    48,     4,    97,    99,    61,     9,     4,
      43,     8,     9,    14,     4,    73,   108,     4,   116,   112,
       8,     9,     8,     9,     8,     9,    73,    10,    73,    87,
      77,    89,    79,    91,    81,    93,    83,    95,    92,    36,
      85,     8,     9,   101,    12,   103,     0,   105,    36,   107,
      36,   109,    36,   111,    11,   113,    58,   115,    62,   117,
      66,    68,    70,    72,    64,    60,    56,    54,     8,     9,
      37,    38,    84,    86,    41,    42,    90,     8,     9,    99,
       8,     9,     9,     8,     9,    45,    13,    97,    99,     8,
      51,    19,    20,    21,   114,    47,   106,    37,    38,   110,
      15,    41,    42,    22,    23,    24,    37,    38,     8,     3,
      41,    42,    37,    38,    33,     8,    49,    36,     8,    38,
       8,    40,    22,    23,    24,     8,     9,     8,     9,    22,
      23,    24,    97,     3,    34,     3,    36,     8,    38,   104,
      40,    97,    35,    36,    39,    38,   102,    40,     8,     9,
       8,     9,     8,     9,    37,    38,    37,    38,     8,     9,
       8,     9,    22,    23,    24,    94,     8,     9,    97,    27,
      28,    29,   131,     8,     9,   134,    36,    15,    38,    54,
      40,    37,    38,    44,    19,    20,    21,    37,    38,    58,
     139,    56,    53,   142,    55,    39,    57,     7,    59,    39,
      61,    64,    63,    62,    65,     7,    67,     8,    69,    66,
      71,     7,    73,     8,     9,    68,     8,     9,     8,     9,
       8,     9,     8,     9,    19,    20,    21,    19,    20,    21,
       8,     9,     8,     9,     8,     9,     8,     9,     8,     9,
       8,     9,     8,     9,     8,     9,     8,     9,     8,     9,
      74,    75,     5,     6,     5,     6,     5,     6,     8,     9,
      74,    75,    74,    75,     8,     9,    74,    75,    96,    97,
      70,   118,   119,     8,     9,     8,     9,   144,   145,   124,
     125,   130,   131,   138,   139,     3,     3,     8,     3,     8,
       3,    15,     8,    60,     8,    72,     7,     7,     7,     7,
      84,    84,     3,    15,   121,    39,    86,    78,    30,    16,
       3,    17,    17,    17,    17,    17,     3,    17,     3,    18,
      18,    18,    18,    78,    80,    82,    80,     7,     3,     8,
      25,     3,     8,     3,    82,     3,     3,     8,     3,     8,
       3,     3,     8,     3,     8,     3,     3,     8,     3,     8,
       3,    90,     8,     3,     8,     4,     8,     8,    52,     7,
       7,     7,   127,     7,     7,     7,     7,     7,     7,     7,
       7,     7,     7,     7,     7,     7,     7,     3,     3,     8,
       8,   123,     3,   135,    76,     7,    31,     7,     3,     3,
      76,     4,     4,    75,   122,    76,   143,    88,     8,     8,
       8,     8,     8,     8,     7,    32,   129,     3,    38,    26,
       7,     3,     7,     3,    33,    38,    40,     3,     7,     4,
      98,     4,    40,     4,     4,     4,     4,    38,     3,     3,
      34,     8,     3,    -1,     7,     7,     3,     7,    40,     3,
      38,     3,     3,   133,     3,     3,    62,     3,   137,     3,
       3,     3,     3,     3,     3,     3,   140,     3,   141,   136,
       7,     3,     7,     7,     7,    34,     7,    35,     3,     7,
       7,     7,   146,     7,     7,    76,     7,    40,     7,     7,
       7,     7,     7,     7,     3,     8,     3,     3,     3,     3,
       3,     3,    -1,     3,     3,    35,     7,    -1,    98,    98,
       7,     7,     3,     7,    98,    98,     8,    98,     7,    75,
       7,     7,   100,   100,     7,     7,   100,     7,   100,    76,
      75,     7,     7,     3,     7,     3,     8,     3,     3,     3,
       3,     3,     3,    -1,     3,    -1,     3,     3,     8,     7,
       3,    -1,     7,     7,   120,     7,    76,     7,     7,     7,
       7,     3,     8,     3,     3,     3,     3,     3,     3,     3,
     125,     3,     3,     3,     3,     3,    -1,    -1,   128,    -1,
       7,     7,     7,     7,     7,     7,    76,     7,     7,     7,
       7,     7,     7,     7,     7,     7,     7,     7,     3,     3,
       3,     3,   131,     3,   126,     3,     7,     3,     7,     3,
       7,     3,     7,    -1,     7,   126,   126,     7,     3,     3,
       3,     7,     3,     3,   132,     7,     3,   139,     3,     7,
       3,     7,    -1,     7,   132,     7,     7,     7,     7,     7,
       3,     7,     7,    -1,    -1,   140,    -1,   140
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
       6,    84,    15,   226,     8,     9,    50,    73,    87,    89,
      91,    93,    95,   101,   103,   105,   107,   109,   111,   113,
     115,   117,   237,   238,   240,   241,   242,   243,   247,   251,
     255,   259,   263,   273,   283,   293,   303,   307,   311,   315,
       8,     9,    27,    28,    29,   327,   328,   329,   330,   331,
      60,    72,    74,    75,   190,     7,   211,     7,     5,     6,
       7,     5,     6,     7,     5,     6,    84,    84,     3,     8,
       4,    86,    15,   316,    39,   239,     8,     9,    16,   244,
      17,   248,    17,   252,    17,   256,    17,   260,    17,   308,
      17,   304,    18,   264,    18,   274,    18,   284,    18,   294,
      25,   312,   121,   332,   333,     3,     3,     3,   191,    74,
      75,   212,    78,    78,    80,    80,    82,    82,     7,   227,
      86,     3,     8,     3,     8,     4,    90,     3,   245,     3,
     249,     3,     8,     3,     8,     3,     8,     3,     8,     3,
       8,     3,     8,     3,     8,     3,     8,     3,     8,     3,
       8,    30,   334,    52,   127,   363,     7,     7,     7,     8,
       9,    36,   192,   193,   196,   213,    74,    75,   228,     7,
     317,     7,     4,    90,     7,    61,    92,   246,     7,    94,
      97,   250,     7,   253,     7,   257,     7,   261,     7,   309,
       7,   305,     7,   265,     7,   275,     7,   285,     7,   295,
       7,   313,     3,     8,     9,   335,    31,   364,   135,   401,
      76,     3,    38,   194,     8,     9,    36,   214,   215,   218,
     229,    74,    75,   318,    88,     8,     8,    96,    97,   254,
      97,   102,   258,    97,   104,   262,    97,   106,   310,    97,
     108,   306,    99,   110,   266,    99,   112,   276,    99,   114,
     286,    99,   116,   296,   118,   119,   314,     7,   123,   336,
       3,     8,     9,   365,    32,   402,   143,   439,     7,     3,
      40,   195,    76,     3,    38,   216,     8,     9,    36,   230,
     231,   234,   319,     4,     4,     8,     8,     8,     8,     8,
     267,   277,   287,   297,     8,    33,    75,   344,     7,   129,
     366,     3,     8,     9,   403,    26,   440,     7,     3,     7,
       3,    40,   217,    76,     3,    38,   232,     8,     9,    36,
     320,   321,   324,    62,    98,     4,     4,     4,     4,     4,
       8,     9,    19,    20,    21,   268,   269,   270,   271,   272,
       8,     9,    19,    20,    21,   278,   279,   280,   281,   282,
       8,     9,    19,    20,    21,   288,   289,   290,   291,   292,
       8,     9,    19,    20,    21,   298,   299,   300,   301,   302,
       4,     3,   345,   122,    34,   133,   374,     7,   137,   404,
       3,     8,     7,     7,     3,     7,     3,    40,   233,    76,
       3,    38,   322,    98,    98,    98,    98,    98,   100,     3,
       3,     3,   100,     3,     3,     3,   100,     3,     3,     3,
     100,     3,     3,     3,   120,     7,     8,    22,    23,    24,
      33,    36,    38,    40,   346,   347,   348,   349,   350,   351,
     352,   353,   354,     3,    34,    75,   382,    35,   141,   412,
       7,   441,     7,     7,     3,     7,     3,    40,   323,     7,
       7,     7,     7,     7,     7,     7,     7,     7,     7,     7,
       7,     8,   125,   355,     3,     3,     3,     3,     3,     3,
       3,     7,     3,   383,   128,     3,    35,    75,   420,   144,
     145,   442,     7,     7,     3,   337,   356,    76,     7,     7,
       7,     7,     7,     7,     7,     8,     7,     8,    22,    23,
      24,    34,    36,    38,    40,   384,   385,   386,   387,   388,
     389,   390,   391,   392,     7,     3,   421,   136,   443,     7,
     124,   125,   338,     8,     9,    37,    38,    41,    42,   357,
     358,   359,   360,   361,   362,   367,     8,   131,   393,     3,
       3,     3,     3,     3,     3,     3,     8,     7,     8,    22,
      23,    24,    35,    36,    38,    40,   422,   423,   424,   425,
     426,   427,   428,   429,   430,     8,     9,    22,    23,    24,
      36,    38,    40,   444,   445,   446,   447,   448,   449,   450,
     451,   339,   126,     3,     3,     3,     3,   130,   131,   368,
     375,   394,    76,     7,     7,     7,     7,     7,     7,     7,
     405,     8,   139,   431,     3,     3,     3,     3,     3,     3,
       3,   146,     3,     3,     3,     3,     3,     3,     8,     9,
      37,    38,   340,   341,   342,   343,     7,     7,     7,     7,
     369,   131,   134,   376,     8,     9,    37,    38,    41,    42,
     395,   396,   397,   398,   399,   400,   138,   139,   406,   413,
     432,    76,     7,     7,     7,     7,     7,     7,     7,     7,
       7,     7,     7,     7,     7,   126,     3,     3,     8,     9,
      37,    38,   370,   371,   372,   373,   377,   126,     3,     3,
       3,     3,   407,   139,   142,   414,     8,     9,    37,    38,
      41,    42,   433,   434,   435,   436,   437,   438,     7,     7,
     132,     3,     3,     8,     9,    37,    38,   378,   379,   380,
     381,     7,     7,     7,     7,     8,     9,    37,    38,   408,
     409,   410,   411,   415,   140,     3,     3,     3,     3,     7,
       7,   132,     3,     3,   140,     3,     3,     8,     9,    37,
      38,   416,   417,   418,   419,     7,     7,     7,     7,     7,
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
        case 26:

    {
}
    break;

  case 27:

    {
}
    break;

  case 31:

    {
}
    break;

  case 32:

    {
}
    break;

  case 36:

    {
}
    break;

  case 37:

    {
}
    break;

  case 41:

    {
}
    break;

  case 42:

    {
}
    break;

  case 44:

    {
}
    break;

  case 48:

    {
}
    break;

  case 49:

    {
}
    break;

  case 53:

    {
}
    break;

  case 54:

    {
}
    break;

  case 58:

    {
}
    break;

  case 59:

    {
}
    break;

  case 63:

    {
}
    break;

  case 64:

    {
}
    break;

  case 68:

    {
}
    break;

  case 69:

    {
}
    break;

  case 73:

    {
}
    break;

  case 74:

    {
}
    break;

  case 76:

    {
}
    break;

  case 78:

    {
}
    break;

  case 85:

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

  case 103:

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

  case 117:

    {
}
    break;

  case 119:

    {
}
    break;

  case 121:

    {
}
    break;

  case 128:

    {
}
    break;

  case 130:

    {
}
    break;

  case 132:

    {
}
    break;

  case 134:

    {
}
    break;

  case 145:

    {
}
    break;

  case 146:

    {
}
    break;

  case 148:

    {
}
    break;

  case 155:

    {
}
    break;

  case 157:

    {
}
    break;

  case 159:

    {
}
    break;

  case 161:

    {
}
    break;

  case 182:

    {
}
    break;

  case 184:

    {
}
    break;

  case 188:

    {
}
    break;

  case 189:

    {
}
    break;

  case 191:

    {
}
    break;

  case 194:

    {
}
    break;

  case 196:

    {
}
    break;

  case 199:

    {
}
    break;

  case 201:

    {
}
    break;

  case 204:

    {
}
    break;

  case 206:

    {
}
    break;

  case 209:

    {
}
    break;

  case 211:

    {
}
    break;

  case 214:

    {
}
    break;

  case 216:

    {
}
    break;

  case 219:

    {
}
    break;

  case 225:

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

  case 231:

    {
}
    break;

  case 234:

    {
}
    break;

  case 240:

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

  case 246:

    {
}
    break;

  case 249:

    {
}
    break;

  case 255:

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

  case 261:

    {
}
    break;

  case 264:

    {
}
    break;

  case 270:

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

  case 276:

    {
}
    break;

  case 279:

    {
}
    break;

  case 281:

    {
}
    break;

  case 284:

    {
}
    break;

  case 286:

    {
}
    break;

  case 289:

    {
}
    break;

  case 291:

    {
}
    break;

  case 298:

    {
}
    break;

  case 300:

    {
}
    break;

  case 302:

    {
}
    break;

  case 304:

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

  case 321:

    {
}
    break;

  case 333:

    {
}
    break;

  case 334:

    {
}
    break;

  case 348:

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

  case 363:

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

  case 372:

    {
}
    break;

  case 384:

    {
}
    break;

  case 385:

    {
}
    break;

  case 397:

    {
}
    break;

  case 398:

    {
}
    break;

  case 412:

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

  case 427:

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

  case 436:

    {
}
    break;

  case 448:

    {
}
    break;

  case 449:

    {
}
    break;

  case 461:

    {
}
    break;

  case 462:

    {
}
    break;

  case 476:

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

  case 491:

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

  case 499:

    {
}
    break;

  case 511:

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


