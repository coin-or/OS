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
#define YYLAST   652

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  148
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  304
/* YYNRULES -- Number of rules.  */
#define YYNRULES  514
/* YYNRULES -- Number of states.  */
#define YYNSTATES  930

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
     295,   297,   299,   305,   306,   310,   316,   317,   321,   327,
     328,   332,   334,   336,   339,   343,   348,   354,   358,   359,
     362,   366,   367,   370,   374,   378,   379,   383,   384,   388,
     390,   393,   394,   399,   402,   403,   406,   408,   410,   412,
     414,   417,   421,   426,   432,   436,   437,   440,   444,   445,
     448,   452,   456,   457,   461,   462,   466,   468,   471,   472,
     477,   480,   481,   484,   486,   488,   490,   492,   494,   496,
     498,   500,   502,   504,   506,   508,   510,   512,   514,   520,
     521,   525,   527,   529,   532,   536,   541,   546,   550,   551,
     554,   559,   564,   568,   569,   572,   577,   583,   587,   588,
     591,   596,   602,   606,   607,   610,   615,   621,   625,   626,
     629,   634,   640,   644,   645,   648,   652,   653,   656,   658,
     660,   662,   666,   670,   674,   677,   679,   685,   689,   690,
     693,   697,   698,   701,   703,   705,   707,   711,   715,   719,
     722,   724,   730,   734,   735,   738,   742,   743,   746,   748,
     750,   752,   756,   760,   764,   767,   769,   775,   779,   780,
     783,   787,   788,   791,   793,   795,   797,   801,   805,   809,
     812,   814,   820,   824,   825,   828,   833,   839,   843,   844,
     847,   852,   858,   862,   863,   866,   871,   877,   881,   882,
     885,   889,   890,   893,   897,   901,   902,   906,   907,   911,
     913,   916,   917,   921,   922,   925,   927,   929,   931,   935,
     939,   943,   947,   949,   954,   955,   959,   960,   964,   969,
     971,   972,   980,   981,   984,   988,   989,   992,   994,   996,
    1000,  1004,  1007,  1009,  1010,  1014,  1015,  1018,  1020,  1022,
    1024,  1026,  1028,  1030,  1032,  1036,  1040,  1044,  1048,  1052,
    1056,  1060,  1064,  1068,  1069,  1072,  1074,  1076,  1078,  1080,
    1084,  1088,  1092,  1096,  1099,  1101,  1102,  1106,  1107,  1111,
    1117,  1119,  1120,  1128,  1129,  1132,  1136,  1137,  1140,  1142,
    1144,  1148,  1152,  1155,  1157,  1158,  1166,  1167,  1170,  1174,
    1175,  1178,  1180,  1182,  1186,  1190,  1193,  1195,  1196,  1200,
    1201,  1204,  1206,  1208,  1210,  1212,  1214,  1216,  1218,  1222,
    1226,  1230,  1234,  1238,  1242,  1246,  1250,  1254,  1255,  1258,
    1260,  1262,  1264,  1266,  1270,  1274,  1278,  1282,  1285,  1287,
    1288,  1292,  1293,  1297,  1303,  1305,  1306,  1314,  1315,  1318,
    1322,  1323,  1326,  1328,  1330,  1334,  1338,  1341,  1343,  1344,
    1352,  1353,  1356,  1360,  1361,  1364,  1366,  1368,  1372,  1376,
    1379,  1381,  1382,  1386,  1387,  1390,  1392,  1394,  1396,  1398,
    1400,  1402,  1404,  1408,  1412,  1416,  1420,  1424,  1428,  1432,
    1436,  1440,  1441,  1444,  1446,  1448,  1450,  1452,  1456,  1460,
    1464,  1468,  1471,  1473,  1474,  1480,  1484,  1485,  1488,  1492,
    1493,  1496,  1498,  1500,  1502,  1504,  1506,  1508,  1512,  1516,
    1520,  1524,  1528,  1532,  1535
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
     201,     8,     6,    78,    -1,    -1,    39,     3,     7,    -1,
      79,   203,     8,     6,    80,    -1,    -1,    39,     3,     7,
      -1,    81,   205,     8,     6,    82,    -1,    -1,    39,     3,
       7,    -1,   207,    -1,   208,    -1,    83,     9,    -1,    83,
       8,    84,    -1,    83,     8,     6,    84,    -1,    73,   210,
       8,   211,    74,    -1,    15,     3,     7,    -1,    -1,   211,
     212,    -1,    75,   213,   218,    -1,    -1,   213,   214,    -1,
     215,   216,   217,    -1,    36,     3,     7,    -1,    -1,    38,
       3,     7,    -1,    -1,    40,     3,     7,    -1,     9,    -1,
       8,    76,    -1,    -1,    47,     8,   220,    48,    -1,    47,
       9,    -1,    -1,   220,   221,    -1,   222,    -1,   225,    -1,
     223,    -1,   224,    -1,    85,     9,    -1,    85,     8,    86,
      -1,    85,     8,     4,    86,    -1,    73,   226,     8,   227,
      74,    -1,    15,     3,     7,    -1,    -1,   227,   228,    -1,
      75,   229,   234,    -1,    -1,   229,   230,    -1,   231,   232,
     233,    -1,    36,     3,     7,    -1,    -1,    38,     3,     7,
      -1,    -1,    40,     3,     7,    -1,     9,    -1,     8,    76,
      -1,    -1,    49,     8,   236,    50,    -1,    49,     9,    -1,
      -1,   236,   237,    -1,   238,    -1,   240,    -1,   243,    -1,
     247,    -1,   251,    -1,   255,    -1,   259,    -1,   263,    -1,
     273,    -1,   283,    -1,   293,    -1,   303,    -1,   307,    -1,
     311,    -1,   315,    -1,    87,   239,     8,     4,    88,    -1,
      -1,    39,     3,     7,    -1,   241,    -1,   242,    -1,    89,
       9,    -1,    89,     8,    90,    -1,    89,     8,     4,    90,
      -1,    91,   244,   245,    92,    -1,    16,     3,     7,    -1,
      -1,   245,   246,    -1,    61,     8,     4,    62,    -1,    93,
     248,   249,    94,    -1,    17,     3,     7,    -1,    -1,   249,
     250,    -1,    97,     8,     4,    98,    -1,    95,   252,     8,
     253,    96,    -1,    17,     3,     7,    -1,    -1,   253,   254,
      -1,    97,     8,     4,    98,    -1,   101,   256,     8,   257,
     102,    -1,    17,     3,     7,    -1,    -1,   257,   258,    -1,
      97,     8,     4,    98,    -1,   103,   260,     8,   261,   104,
      -1,    17,     3,     7,    -1,    -1,   261,   262,    -1,    97,
       8,     4,    98,    -1,   109,   264,     8,   265,   110,    -1,
      18,     3,     7,    -1,    -1,   265,   266,    -1,    99,   267,
     272,    -1,    -1,   267,   268,    -1,   269,    -1,   270,    -1,
     271,    -1,    19,     3,     7,    -1,    20,     3,     7,    -1,
      21,     3,     7,    -1,     8,   100,    -1,     9,    -1,   111,
     274,     8,   275,   112,    -1,    18,     3,     7,    -1,    -1,
     275,   276,    -1,    99,   277,   282,    -1,    -1,   277,   278,
      -1,   279,    -1,   280,    -1,   281,    -1,    19,     3,     7,
      -1,    20,     3,     7,    -1,    21,     3,     7,    -1,     8,
     100,    -1,     9,    -1,   113,   284,     8,   285,   114,    -1,
      18,     3,     7,    -1,    -1,   285,   286,    -1,    99,   287,
     292,    -1,    -1,   287,   288,    -1,   289,    -1,   290,    -1,
     291,    -1,    19,     3,     7,    -1,    20,     3,     7,    -1,
      21,     3,     7,    -1,     8,   100,    -1,     9,    -1,   115,
     294,     8,   295,   116,    -1,    18,     3,     7,    -1,    -1,
     295,   296,    -1,    99,   297,   302,    -1,    -1,   297,   298,
      -1,   299,    -1,   300,    -1,   301,    -1,    19,     3,     7,
      -1,    20,     3,     7,    -1,    21,     3,     7,    -1,     8,
     100,    -1,     9,    -1,   107,   304,     8,   305,   108,    -1,
      17,     3,     7,    -1,    -1,   305,   306,    -1,    97,     8,
       4,    98,    -1,   105,   308,     8,   309,   106,    -1,    17,
       3,     7,    -1,    -1,   309,   310,    -1,    97,     8,     4,
      98,    -1,   117,   312,     8,   313,   118,    -1,    25,     3,
       7,    -1,    -1,   313,   314,    -1,   119,     8,     4,   120,
      -1,    73,   316,     8,   317,    74,    -1,    15,     3,     7,
      -1,    -1,   317,   318,    -1,    75,   319,   324,    -1,    -1,
     319,   320,    -1,   321,   322,   323,    -1,    36,     3,     7,
      -1,    -1,    38,     3,     7,    -1,    -1,    40,     3,     7,
      -1,     9,    -1,     8,    76,    -1,    -1,    51,   326,   331,
      -1,    -1,   326,   327,    -1,   328,    -1,   329,    -1,   330,
      -1,    27,     3,     7,    -1,    29,     3,     7,    -1,    28,
       3,     7,    -1,     8,   332,    52,    -1,     9,    -1,   333,
     363,   401,   439,    -1,    -1,   121,   334,   335,    -1,    -1,
      30,     3,     7,    -1,     8,   336,   344,   122,    -1,     9,
      -1,    -1,   123,    33,     3,     7,     8,   337,   124,    -1,
      -1,   337,   338,    -1,   125,   339,   343,    -1,    -1,   339,
     340,    -1,   341,    -1,   342,    -1,    37,     3,     7,    -1,
      38,     3,     7,    -1,     8,   126,    -1,     9,    -1,    -1,
      75,   345,   354,    -1,    -1,   345,   346,    -1,   347,    -1,
     348,    -1,   349,    -1,   350,    -1,   351,    -1,   352,    -1,
     353,    -1,    33,     3,     7,    -1,    36,     3,     7,    -1,
      38,     3,     7,    -1,    22,     3,     7,    -1,    23,     3,
       7,    -1,    24,     3,     7,    -1,    40,     3,     7,    -1,
       8,   355,    76,    -1,   125,   356,   362,    -1,    -1,   356,
     357,    -1,   358,    -1,   359,    -1,   360,    -1,   361,    -1,
      37,     3,     7,    -1,    38,     3,     7,    -1,    41,     3,
       7,    -1,    42,     3,     7,    -1,     8,   126,    -1,     9,
      -1,    -1,   127,   364,   365,    -1,    -1,    31,     3,     7,
      -1,     8,   366,   374,   382,   128,    -1,     9,    -1,    -1,
     129,    34,     3,     7,     8,   367,   130,    -1,    -1,   367,
     368,    -1,   131,   369,   373,    -1,    -1,   369,   370,    -1,
     371,    -1,   372,    -1,    37,     3,     7,    -1,    38,     3,
       7,    -1,     8,   132,    -1,     9,    -1,    -1,   133,    34,
       3,     7,     8,   375,   134,    -1,    -1,   375,   376,    -1,
     131,   377,   381,    -1,    -1,   377,   378,    -1,   379,    -1,
     380,    -1,    37,     3,     7,    -1,    38,     3,     7,    -1,
       8,   132,    -1,     9,    -1,    -1,    75,   383,   392,    -1,
      -1,   383,   384,    -1,   385,    -1,   386,    -1,   387,    -1,
     388,    -1,   389,    -1,   390,    -1,   391,    -1,    34,     3,
       7,    -1,    36,     3,     7,    -1,    38,     3,     7,    -1,
      22,     3,     7,    -1,    23,     3,     7,    -1,    24,     3,
       7,    -1,    40,     3,     7,    -1,     8,   393,    76,    -1,
     131,   394,   400,    -1,    -1,   394,   395,    -1,   396,    -1,
     397,    -1,   398,    -1,   399,    -1,    37,     3,     7,    -1,
      38,     3,     7,    -1,    41,     3,     7,    -1,    42,     3,
       7,    -1,     8,   126,    -1,     9,    -1,    -1,   135,   402,
     403,    -1,    -1,    32,     3,     7,    -1,     8,   404,   412,
     420,   136,    -1,     9,    -1,    -1,   137,    35,     3,     7,
       8,   405,   138,    -1,    -1,   405,   406,    -1,   139,   407,
     411,    -1,    -1,   407,   408,    -1,   409,    -1,   410,    -1,
      37,     3,     7,    -1,    38,     3,     7,    -1,     8,   140,
      -1,     9,    -1,    -1,   141,    35,     3,     7,     8,   413,
     142,    -1,    -1,   413,   414,    -1,   139,   415,   419,    -1,
      -1,   415,   416,    -1,   417,    -1,   418,    -1,    37,     3,
       7,    -1,    38,     3,     7,    -1,     8,   140,    -1,     9,
      -1,    -1,    75,   421,   430,    -1,    -1,   421,   422,    -1,
     423,    -1,   424,    -1,   425,    -1,   426,    -1,   427,    -1,
     428,    -1,   429,    -1,    35,     3,     7,    -1,    36,     3,
       7,    -1,    38,     3,     7,    -1,    22,     3,     7,    -1,
      23,     3,     7,    -1,    24,     3,     7,    -1,    40,     3,
       7,    -1,     8,   431,    76,    -1,   139,   432,   438,    -1,
      -1,   432,   433,    -1,   434,    -1,   435,    -1,   436,    -1,
     437,    -1,    37,     3,     7,    -1,    38,     3,     7,    -1,
      41,     3,     7,    -1,    42,     3,     7,    -1,     8,   140,
      -1,     9,    -1,    -1,   143,   440,     8,   441,   144,    -1,
      26,     3,     7,    -1,    -1,   441,   442,    -1,   145,   443,
     451,    -1,    -1,   443,   444,    -1,   445,    -1,   446,    -1,
     447,    -1,   448,    -1,   449,    -1,   450,    -1,    36,     3,
       7,    -1,    38,     3,     7,    -1,    22,     3,     7,    -1,
      23,     3,     7,    -1,    24,     3,     7,    -1,    40,     3,
       7,    -1,     8,   146,    -1,     9,    -1
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
     306,   306,   308,   311,   311,   315,   319,   319,   323,   327,
     327,   331,   331,   333,   334,   338,   342,   344,   348,   348,
     350,   352,   352,   354,   356,   360,   360,   364,   364,   368,
     368,   373,   374,   375,   377,   377,   379,   379,   381,   381,
     383,   384,   388,   393,   395,   399,   399,   401,   403,   403,
     405,   407,   411,   411,   415,   415,   419,   419,   424,   425,
     426,   428,   428,   430,   430,   430,   430,   430,   431,   431,
     431,   431,   431,   432,   432,   432,   432,   432,   434,   438,
     438,   442,   442,   444,   445,   449,   453,   455,   459,   459,
     462,   466,   469,   473,   473,   475,   479,   482,   486,   486,
     488,   492,   495,   499,   499,   501,   505,   508,   512,   512,
     514,   518,   521,   525,   525,   527,   531,   531,   533,   533,
     533,   535,   539,   543,   547,   547,   550,   553,   557,   557,
     559,   563,   563,   565,   565,   565,   567,   571,   575,   579,
     579,   582,   585,   589,   589,   591,   595,   595,   597,   597,
     597,   599,   603,   607,   611,   611,   614,   617,   621,   621,
     623,   627,   627,   629,   629,   629,   631,   635,   639,   643,
     643,   647,   650,   654,   654,   656,   660,   663,   667,   667,
     669,   674,   677,   681,   681,   683,   688,   690,   694,   694,
     696,   698,   698,   700,   702,   706,   706,   710,   710,   714,
     714,   719,   719,   721,   721,   723,   723,   723,   725,   729,
     733,   737,   737,   739,   741,   741,   743,   743,   747,   748,
     750,   750,   753,   753,   755,   757,   757,   759,   759,   761,
     765,   769,   769,   772,   772,   774,   774,   777,   778,   779,
     780,   781,   782,   783,   785,   789,   793,   797,   801,   805,
     809,   814,   816,   818,   818,   821,   822,   823,   824,   826,
     830,   834,   838,   842,   842,   844,   844,   846,   846,   850,
     852,   855,   855,   858,   858,   860,   862,   862,   864,   864,
     866,   870,   874,   874,   877,   877,   880,   880,   882,   884,
     884,   886,   886,   888,   892,   896,   896,   899,   899,   901,
     901,   904,   905,   906,   907,   908,   909,   910,   912,   916,
     920,   924,   928,   932,   936,   941,   943,   945,   945,   948,
     949,   950,   951,   953,   957,   961,   965,   969,   969,   971,
     971,   973,   973,   977,   979,   981,   981,   984,   984,   986,
     988,   988,   990,   990,   992,   996,  1000,  1000,  1003,  1003,
    1006,  1006,  1008,  1010,  1010,  1012,  1012,  1014,  1018,  1022,
    1022,  1025,  1025,  1027,  1027,  1030,  1031,  1032,  1033,  1034,
    1035,  1036,  1038,  1042,  1046,  1050,  1054,  1058,  1062,  1067,
    1069,  1071,  1071,  1074,  1075,  1076,  1077,  1079,  1083,  1087,
    1091,  1095,  1095,  1098,  1098,  1100,  1104,  1104,  1106,  1108,
    1108,  1111,  1112,  1113,  1114,  1115,  1116,  1118,  1122,  1126,
    1130,  1134,  1138,  1143,  1143
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
     199,   199,   200,   201,   201,   202,   203,   203,   204,   205,
     205,   206,   206,   207,   207,   208,   209,   210,   211,   211,
     212,   213,   213,   214,   215,   216,   216,   217,   217,   218,
     218,   219,   219,   219,   220,   220,   221,   221,   222,   222,
     223,   223,   224,   225,   226,   227,   227,   228,   229,   229,
     230,   231,   232,   232,   233,   233,   234,   234,   235,   235,
     235,   236,   236,   237,   237,   237,   237,   237,   237,   237,
     237,   237,   237,   237,   237,   237,   237,   237,   238,   239,
     239,   240,   240,   241,   241,   242,   243,   244,   245,   245,
     246,   247,   248,   249,   249,   250,   251,   252,   253,   253,
     254,   255,   256,   257,   257,   258,   259,   260,   261,   261,
     262,   263,   264,   265,   265,   266,   267,   267,   268,   268,
     268,   269,   270,   271,   272,   272,   273,   274,   275,   275,
     276,   277,   277,   278,   278,   278,   279,   280,   281,   282,
     282,   283,   284,   285,   285,   286,   287,   287,   288,   288,
     288,   289,   290,   291,   292,   292,   293,   294,   295,   295,
     296,   297,   297,   298,   298,   298,   299,   300,   301,   302,
     302,   303,   304,   305,   305,   306,   307,   308,   309,   309,
     310,   311,   312,   313,   313,   314,   315,   316,   317,   317,
     318,   319,   319,   320,   321,   322,   322,   323,   323,   324,
     324,   325,   325,   326,   326,   327,   327,   327,   328,   329,
     330,   331,   331,   332,   333,   333,   334,   334,   335,   335,
     336,   336,   337,   337,   338,   339,   339,   340,   340,   341,
     342,   343,   343,   344,   344,   345,   345,   346,   346,   346,
     346,   346,   346,   346,   347,   348,   349,   350,   351,   352,
     353,   354,   355,   356,   356,   357,   357,   357,   357,   358,
     359,   360,   361,   362,   362,   363,   363,   364,   364,   365,
     365,   366,   366,   367,   367,   368,   369,   369,   370,   370,
     371,   372,   373,   373,   374,   374,   375,   375,   376,   377,
     377,   378,   378,   379,   380,   381,   381,   382,   382,   383,
     383,   384,   384,   384,   384,   384,   384,   384,   385,   386,
     387,   388,   389,   390,   391,   392,   393,   394,   394,   395,
     395,   395,   395,   396,   397,   398,   399,   400,   400,   401,
     401,   402,   402,   403,   403,   404,   404,   405,   405,   406,
     407,   407,   408,   408,   409,   410,   411,   411,   412,   412,
     413,   413,   414,   415,   415,   416,   416,   417,   418,   419,
     419,   420,   420,   421,   421,   422,   422,   422,   422,   422,
     422,   422,   423,   424,   425,   426,   427,   428,   429,   430,
     431,   432,   432,   433,   433,   433,   433,   434,   435,   436,
     437,   438,   438,   439,   439,   440,   441,   441,   442,   443,
     443,   444,   444,   444,   444,   444,   444,   445,   446,   447,
     448,   449,   450,   451,   451
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
       1,     1,     5,     0,     3,     5,     0,     3,     5,     0,
       3,     1,     1,     2,     3,     4,     5,     3,     0,     2,
       3,     0,     2,     3,     3,     0,     3,     0,     3,     1,
       2,     0,     4,     2,     0,     2,     1,     1,     1,     1,
       2,     3,     4,     5,     3,     0,     2,     3,     0,     2,
       3,     3,     0,     3,     0,     3,     1,     2,     0,     4,
       2,     0,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     5,     0,
       3,     1,     1,     2,     3,     4,     4,     3,     0,     2,
       4,     4,     3,     0,     2,     4,     5,     3,     0,     2,
       4,     5,     3,     0,     2,     4,     5,     3,     0,     2,
       4,     5,     3,     0,     2,     3,     0,     2,     1,     1,
       1,     3,     3,     3,     2,     1,     5,     3,     0,     2,
       3,     0,     2,     1,     1,     1,     3,     3,     3,     2,
       1,     5,     3,     0,     2,     3,     0,     2,     1,     1,
       1,     3,     3,     3,     2,     1,     5,     3,     0,     2,
       3,     0,     2,     1,     1,     1,     3,     3,     3,     2,
       1,     5,     3,     0,     2,     4,     5,     3,     0,     2,
       4,     5,     3,     0,     2,     4,     5,     3,     0,     2,
       3,     0,     2,     3,     3,     0,     3,     0,     3,     1,
       2,     0,     3,     0,     2,     1,     1,     1,     3,     3,
       3,     3,     1,     4,     0,     3,     0,     3,     4,     1,
       0,     7,     0,     2,     3,     0,     2,     1,     1,     3,
       3,     2,     1,     0,     3,     0,     2,     1,     1,     1,
       1,     1,     1,     1,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     0,     2,     1,     1,     1,     1,     3,
       3,     3,     3,     2,     1,     0,     3,     0,     3,     5,
       1,     0,     7,     0,     2,     3,     0,     2,     1,     1,
       3,     3,     2,     1,     0,     7,     0,     2,     3,     0,
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
       3,     2,     1,     0,     5,     3,     0,     2,     3,     0,
       2,     1,     1,     1,     1,     1,     1,     3,     3,     3,
       3,     3,     3,     2,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       0,     4,     0,     0,     5,     1,     7,     3,     0,     0,
      92,    10,     9,     2,     0,   131,     0,    95,    94,     0,
     158,     8,     0,     0,     0,    43,     0,     0,     0,     0,
       0,    75,     0,    11,    12,    23,    24,    13,    28,    29,
      14,    33,    34,    15,    38,    39,    16,    45,    46,    17,
      50,    51,    18,    55,    56,    19,    60,    61,    20,    65,
      66,    21,    70,    71,    22,     0,   134,   133,     0,   301,
       0,    25,     0,    30,     0,    35,    40,     0,     0,     0,
      47,     0,    52,     0,    57,     0,    62,     0,    67,    72,
       0,     0,     0,     0,    93,     0,   103,   106,   109,     0,
      96,    97,    98,    99,   100,   111,   112,   101,     0,   161,
     160,   303,     6,     0,    26,     0,    31,     0,    36,     0,
       0,     0,    48,     0,    53,     0,    58,     0,    63,     0,
      68,     0,     0,     0,    79,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   113,   132,     0,     0,   135,   136,
     138,   139,   137,     0,     0,    27,    32,    37,    44,     0,
      41,    49,    54,    59,    64,    69,    76,     0,    73,    78,
       0,     0,   118,     0,     0,     0,     0,     0,     0,     0,
     114,     0,     0,     0,   140,   159,     0,   179,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   162,   163,   164,   181,   182,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   314,
     312,     0,     0,     0,   304,   305,   306,   307,   302,    42,
      74,    77,    82,    80,   117,     0,   104,     0,   107,     0,
     110,     0,   115,     0,   145,     0,   141,     0,     0,     0,
       0,     0,   183,     0,   188,     0,   193,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   316,     0,   365,
       0,     0,     0,     0,   116,   121,   119,   102,   105,   108,
     144,     0,   142,     0,   288,     0,     0,     0,   184,     0,
       0,     0,     0,     0,   198,     0,   203,     0,   208,     0,
     278,     0,   273,     0,   213,     0,   228,     0,   243,     0,
     258,     0,   283,     0,     0,   311,   367,   429,   308,   310,
     309,     0,    90,     0,    83,    86,    81,     0,   143,   148,
     146,   287,     0,   180,     0,   185,   187,     0,   186,   189,
     192,   191,     0,   194,   197,     0,   202,     0,   207,     0,
     277,     0,   272,     0,   212,     0,   227,     0,   242,     0,
     257,     0,   282,     0,     0,   320,   319,   315,     0,     0,
     431,   493,    91,     0,     0,    88,     0,   129,     0,   122,
     125,   120,     0,   286,   291,   289,   178,     0,     0,   196,
       0,   199,     0,   201,   204,     0,   206,   209,     0,   276,
     279,     0,   271,   274,   216,   211,   214,   231,   226,   229,
     246,   241,   244,   261,   256,   259,   281,     0,   284,   317,
       0,   333,     0,   371,   370,   366,     0,     0,     0,   313,
      85,     0,     0,    84,   130,     0,     0,   127,     0,   156,
       0,   149,   152,   147,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   335,     0,
     368,     0,   384,     0,   435,   434,   430,     0,     0,    87,
       0,   124,     0,     0,   123,   157,     0,     0,   154,     0,
     299,     0,   292,   295,   290,   190,   195,     0,     0,     0,
       0,     0,     0,   225,     0,     0,     0,   217,   218,   219,
     220,   215,     0,   240,     0,     0,     0,   232,   233,   234,
     235,   230,     0,   255,     0,     0,     0,   247,   248,   249,
     250,   245,     0,   270,     0,     0,     0,   262,   263,   264,
     265,   260,     0,     0,     0,   318,     0,     0,   397,   432,
       0,   448,     0,   496,    89,   126,     0,   151,     0,     0,
     150,   300,     0,     0,   297,   200,   205,   210,   280,   275,
     224,     0,     0,     0,   239,     0,     0,     0,   254,     0,
       0,     0,   269,     0,     0,     0,   285,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   336,   337,   338,   339,
     340,   341,   342,   343,   334,     0,     0,   399,     0,     0,
       0,   461,   495,     0,   128,   153,     0,   294,     0,     0,
     293,   221,   222,   223,   236,   237,   238,   251,   252,   253,
     266,   267,   268,   322,   353,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   369,     0,     0,   463,
       0,   494,   499,   497,   155,   296,     0,     0,     0,   351,
     347,   348,   349,   344,   345,   346,   350,   373,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   400,   401,   402,
     403,   404,   405,   406,   407,   398,     0,     0,     0,   433,
       0,   298,   321,   325,   323,     0,   364,     0,     0,     0,
       0,   354,   355,   356,   357,   358,   352,     0,   386,   417,
       0,     0,     0,     0,     0,     0,     0,     0,   437,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   464,   465,
     466,   467,   468,   469,   470,   471,   462,     0,   514,     0,
       0,     0,     0,     0,     0,   500,   501,   502,   503,   504,
     505,   506,   498,     0,   363,     0,     0,     0,     0,   372,
     376,   374,     0,     0,   415,   411,   412,   413,   408,   409,
     410,   414,     0,   450,   481,     0,     0,     0,     0,     0,
       0,     0,     0,   513,     0,     0,     0,     0,     0,     0,
       0,   332,     0,     0,   326,   327,   328,   324,   359,   360,
     361,   362,     0,   389,   385,   387,     0,   428,     0,     0,
       0,     0,   418,   419,   420,   421,   422,   416,   436,   440,
     438,     0,     0,   479,   475,   476,   477,   472,   473,   474,
     478,   509,   510,   511,   507,   508,   512,   331,     0,     0,
       0,   383,     0,     0,   377,   378,   379,   375,     0,   427,
       0,     0,     0,     0,     0,   453,   449,   451,     0,   492,
       0,     0,     0,     0,   482,   483,   484,   485,   486,   480,
     329,   330,   382,     0,     0,     0,   396,     0,     0,   390,
     391,   392,   388,   423,   424,   425,   426,     0,   447,     0,
       0,   441,   442,   443,   439,     0,   491,     0,     0,     0,
       0,   380,   381,   395,     0,     0,   446,     0,     0,     0,
     460,     0,     0,   454,   455,   456,   452,   487,   488,   489,
     490,   393,   394,   444,   445,   459,     0,     0,   457,   458
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,     9,    10,    16,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    78,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    91,    64,
      93,   170,   233,   283,   334,   335,   385,   443,   336,    15,
      65,   100,   101,   138,   102,   140,   103,   142,   104,   105,
     106,   107,   136,   235,   286,   337,   389,   390,   447,   484,
     391,    20,   108,   148,   149,   150,   151,   152,   182,   291,
     340,   392,   451,   452,   488,   560,   453,    69,   153,   201,
     202,   250,   203,   204,   205,   206,   254,   300,   349,   207,
     256,   302,   353,   208,   258,   355,   401,   209,   260,   357,
     404,   210,   262,   359,   407,   211,   268,   365,   416,   462,
     507,   508,   509,   510,   511,   212,   270,   367,   419,   463,
     517,   518,   519,   520,   521,   213,   272,   369,   422,   464,
     527,   528,   529,   530,   531,   214,   274,   371,   425,   465,
     537,   538,   539,   540,   541,   215,   266,   363,   413,   216,
     264,   361,   410,   217,   276,   373,   428,   218,   248,   342,
     395,   454,   492,   493,   564,   620,   494,   112,   154,   224,
     225,   226,   227,   228,   278,   279,   324,   377,   431,   657,
     694,   753,   794,   795,   796,   797,   469,   544,   596,   597,
     598,   599,   600,   601,   602,   603,   604,   635,   658,   701,
     702,   703,   704,   705,   706,   327,   379,   435,   472,   707,
     761,   802,   844,   845,   846,   847,   548,   762,   805,   848,
     879,   880,   881,   882,   608,   645,   677,   678,   679,   680,
     681,   682,   683,   684,   685,   710,   763,   812,   813,   814,
     815,   816,   817,   381,   437,   476,   551,   772,   820,   854,
     891,   892,   893,   894,   611,   821,   857,   895,   913,   914,
     915,   916,   650,   688,   728,   729,   730,   731,   732,   733,
     734,   735,   736,   775,   822,   864,   865,   866,   867,   868,
     869,   439,   478,   613,   653,   690,   745,   746,   747,   748,
     749,   750,   751,   752
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -93
static const yytype_int16 yypact[] =
{
      21,    22,    54,    87,   -93,   -93,    67,   -93,   134,    52,
      81,   -93,   -93,   -93,   162,    98,   149,   -93,   -93,   167,
     100,   -93,   169,   191,   223,    47,   235,   237,   239,   241,
     243,    35,   115,   -93,   -93,   -93,   -93,   -93,   -93,   -93,
     -93,   -93,   -93,   -93,   -93,   -93,   -93,   -93,   -93,   -93,
     -93,   -93,   -93,   -93,   -93,   -93,   -93,   -93,   -93,   -93,
     -93,   -93,   -93,   -93,   -93,   -41,   -93,   -93,   245,    96,
      23,   -93,    20,   -93,     8,   -93,   -93,   148,   146,     6,
     -93,    10,   -93,     4,   -93,     5,   -93,     2,   -93,   -93,
     153,   174,   182,   179,   -93,   186,   164,   166,   168,   247,
     -93,   -93,   -93,   -93,   -93,   -93,   -93,   -93,   -27,   -93,
     -93,   -93,   -93,   135,   -93,   157,   -93,   159,   -93,   202,
      15,   163,   -93,   147,   -93,   199,   -93,   165,   -93,   145,
     -93,   212,    -1,   214,   -93,   225,   276,   284,   280,   288,
     285,   289,   286,    -2,   -93,   -93,   281,   249,   -93,   -93,
     -93,   -93,   -93,   -48,   152,   -93,   -93,   -93,   -93,   238,
     -93,   -93,   -93,   -93,   -93,   -93,   -93,   227,   -93,   -93,
     185,   290,   -93,   293,   295,   296,   298,   299,   301,   211,
     -93,   302,   294,    -3,   -93,   -93,   297,   269,   253,   300,
     292,   303,   304,   305,   306,   307,   308,   309,   310,   311,
     312,   -93,   -93,   -93,   -93,   -93,   -93,   -93,   -93,   -93,
     -93,   -93,   -93,   -93,   -93,   -93,   -93,   -93,   -93,   190,
     -93,   314,   315,   316,   -93,   -93,   -93,   -93,   -93,   -93,
     -93,   -93,   -93,   -93,   -93,   189,   -93,   232,   -93,   233,
     -93,   248,   -93,   318,   -93,   228,   -93,   328,   324,   330,
     326,    -4,   -93,   332,   -93,   333,   -93,   335,   331,   337,
     334,   338,   336,   340,   339,   342,   341,   343,   344,   345,
     346,   347,   348,   350,   349,   352,   351,   321,   263,   231,
     353,   354,   355,    14,   -93,   -93,   -93,   -93,   -93,   -93,
     -93,   192,   -93,   356,   -93,   357,   361,   277,   -93,   359,
     -44,   362,   -81,   363,   -93,   364,   -93,   365,   -93,   366,
     -93,   367,   -93,   368,   -93,   369,   -93,   370,   -93,   371,
     -93,   372,   -93,   377,   260,   -93,   358,   246,   -93,   -93,
     -93,   317,   -93,   379,   -93,   360,   -93,    26,   -93,   -93,
     -93,   -93,   196,   -93,   313,   -93,   -93,   375,   -93,   -93,
     -93,   -93,   376,   -93,   -93,   176,   -93,     7,   -93,    -7,
     -93,    -8,   -93,   -79,   -93,   -73,   -93,   -92,   -93,   -84,
     -93,   -88,   -93,   156,   378,   264,   -93,   -93,   383,   268,
     373,   251,   -93,   381,   387,   374,   319,   -93,   388,   -93,
     380,   -93,    83,   -93,   -93,   -93,   -93,   392,   393,   -93,
     384,   -93,   391,   -93,   -93,   394,   -93,   -93,   395,   -93,
     -93,   396,   -93,   -93,   -93,   -93,   -93,   -93,   -93,   -93,
     -93,   -93,   -93,   -93,   -93,   -93,   -93,   398,   -93,   -93,
     382,   325,   400,   279,   -93,   -93,   406,   270,   385,   -93,
     -93,   403,   409,   -93,   -93,   410,   413,   386,   389,   -93,
     416,   -93,   390,   -93,    92,   397,   322,   417,   418,   419,
     420,   421,   175,   215,   218,   221,   423,   426,   -93,   291,
     -93,   399,   320,   424,   323,   -93,   -93,   427,   428,   -93,
     425,   -93,   430,   431,   -93,   -93,   432,   435,   401,   402,
     -93,   437,   -93,   404,   -93,   -93,   -93,   405,   407,   408,
     411,   412,   414,   -93,   440,   441,   442,   -93,   -93,   -93,
     -93,   -93,   415,   -93,   443,   444,   445,   -93,   -93,   -93,
     -93,   -93,   422,   -93,   446,   447,   448,   -93,   -93,   -93,
     -93,   -93,   429,   -93,   449,   451,   452,   -93,   -93,   -93,
     -93,   -93,   433,   450,    91,   -93,   453,   434,   436,   -93,
     438,   329,   454,   -93,   -93,   -93,   455,   -93,   456,   461,
     -93,   -93,   459,   464,   439,   -93,   -93,   -93,   -93,   -93,
     -93,   462,   465,   467,   -93,   468,   469,   470,   -93,   473,
     474,   475,   -93,   476,   477,   478,   -93,   463,   457,   483,
     484,   485,   486,   487,   488,   489,   -93,   -93,   -93,   -93,
     -93,   -93,   -93,   -93,   -93,   490,   491,   -93,   240,   492,
     458,   460,   -93,   136,   -93,   -93,   493,   -93,   494,   495,
     -93,   -93,   -93,   -93,   -93,   -93,   -93,   -93,   -93,   -93,
     -93,   -93,   -93,   -93,   -93,   466,   497,   500,   501,   505,
     506,   509,   510,   511,   513,   110,   -93,   514,   496,   -93,
     471,   -93,   -93,   -93,   -93,   -93,   516,   158,    43,   -93,
     -93,   -93,   -93,   -93,   -93,   -93,   -93,   -93,   517,   327,
     499,   515,   521,   523,   524,   525,   527,   -93,   -93,   -93,
     -93,   -93,   -93,   -93,   -93,   -93,   526,   529,   117,   -93,
     150,   -93,   -93,   -93,   -93,   472,   -93,   528,   530,   534,
     535,   -93,   -93,   -93,   -93,   -93,   -93,   155,   -93,   -93,
     479,   532,   533,   536,   537,   538,   539,   540,   -93,   541,
     480,   545,   547,   548,   549,   551,   553,   554,   -93,   -93,
     -93,   -93,   -93,   -93,   -93,   -93,   -93,   481,   -93,   555,
     556,   557,   558,   559,   560,   -93,   -93,   -93,   -93,   -93,
     -93,   -93,   -93,    85,   -93,   561,   562,   563,   564,   -93,
     -93,   -93,   -29,    70,   -93,   -93,   -93,   -93,   -93,   -93,
     -93,   -93,   151,   -93,   -93,   498,   565,   566,   568,   569,
     570,   571,   572,   -93,   573,   574,   576,   577,   578,   579,
     482,   -93,   584,   585,   -93,   -93,   -93,   -93,   -93,   -93,
     -93,   -93,   127,   -93,   -93,   -93,   502,   -93,   586,   587,
     588,   589,   -93,   -93,   -93,   -93,   -93,   -93,   -93,   -93,
     -93,   -36,    79,   -93,   -93,   -93,   -93,   -93,   -93,   -93,
     -93,   -93,   -93,   -93,   -93,   -93,   -93,   -93,   590,   592,
     503,   -93,   591,   593,   -93,   -93,   -93,   -93,   129,   -93,
     594,   595,   596,   597,   154,   -93,   -93,   -93,   504,   -93,
     602,   603,   606,   607,   -93,   -93,   -93,   -93,   -93,   -93,
     -93,   -93,   -93,   604,   605,   507,   -93,   610,   611,   -93,
     -93,   -93,   -93,   -93,   -93,   -93,   -93,   508,   -93,   612,
     613,   -93,   -93,   -93,   -93,   160,   -93,   614,   615,   616,
     617,   -93,   -93,   -93,   618,   619,   -93,   622,   623,   512,
     -93,   628,   629,   -93,   -93,   -93,   -93,   -93,   -93,   -93,
     -93,   -93,   -93,   -93,   -93,   -93,   626,   627,   -93,   -93
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -93,   -93,   -93,   -93,   -93,   -93,   -93,   -93,   -93,   -93,
     -93,   -93,   -93,   -93,   -93,   -93,   -93,   -93,   -93,   -93,
     -93,   -93,   -93,   -93,   -93,   -93,   -93,   -93,   -93,   -93,
     -93,   -93,   -93,   -93,   -93,   -93,   -93,   -93,   -93,   -93,
     -93,   -93,   -93,   -93,   -93,   -93,   -93,   -93,   -93,   -93,
     -93,   -93,   -93,   -93,   -93,   -93,   -93,   -93,   -93,   -93,
     -93,   -93,   -93,   -93,   -93,   -93,   -93,   -93,   -93,   -93,
     -93,   -93,   -93,   -93,   -93,   -93,   -93,   -93,   -93,   -93,
     -93,   -93,   -93,   -93,   -93,   -93,   -93,   -93,   -93,   -93,
     -93,   -93,   -93,   -93,   -93,   -93,   -93,   -93,   -93,   -93,
     -93,   -93,   -93,   -93,   -93,   -93,   -93,   -93,   -93,   -93,
     -93,   -93,   -93,   -93,   -93,   -93,   -93,   -93,   -93,   -93,
     -93,   -93,   -93,   -93,   -93,   -93,   -93,   -93,   -93,   -93,
     -93,   -93,   -93,   -93,   -93,   -93,   -93,   -93,   -93,   -93,
     -93,   -93,   -93,   -93,   -93,   -93,   -93,   -93,   -93,   -93,
     -93,   -93,   -93,   -93,   -93,   -93,   -93,   -93,   -93,   -93,
     -93,   -93,   -93,   -93,   -93,   -93,   -93,   -93,   -93,   -93,
     -93,   -93,   -93,   -93,   -93,   -93,   -93,   -93,   -93,   -93,
     -93,   -93,   -93,   -93,   -93,   -93,   -93,   -93,   -93,   -93,
     -93,   -93,   -93,   -93,   -93,   -93,   -93,   -93,   -93,   -93,
     -93,   -93,   -93,   -93,   -93,   -93,   -93,   -93,   -93,   -93,
     -93,   -93,   -93,   -93,   -93,   -93,   -93,   -93,   -93,   -93,
     -93,   -93,   -93,   -93,   -93,   -93,   -93,   -93,   -93,   -93,
     -93,   -93,   -93,   -93,   -93,   -93,   -93,   -93,   -93,   -93,
     -93,   -93,   -93,   -93,   -93,   -93,   -93,   -93,   -93,   -93,
     -93,   -93,   -93,   -93,   -93,   -93,   -93,   -93,   -93,   -93,
     -93,   -93,   -93,   -93,   -93,   -93,   -93,   -93,   -93,   -93,
     -93,   -93,   -93,   -93,   -93,   -93,   -93,   -93,   -93,   -93,
     -93,   -93,   -93,   -93,   -93,   -93,   -93,   -93,   -93,   -93,
     -93,   -93,   -93,   -93,   -93,   -93,   -93,   -93,   -93,   -93,
     -93,   -93,   -93,   -93
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint16 yytable[] =
{
     297,   245,   185,   167,   179,    94,   129,   417,   125,   127,
     121,   423,   117,   351,   123,   420,   352,   347,   411,   159,
     418,   145,   331,   332,   115,   186,   414,   113,   424,   412,
     421,     1,    95,     4,   386,   387,    96,   415,    97,   187,
      98,   188,    99,   189,    89,   190,   146,   191,   348,    90,
     333,   695,   696,   192,     5,   193,    76,   194,   147,   195,
      77,   196,   388,   197,    13,   198,   118,   199,   122,   200,
     126,   168,   130,   128,   124,   160,   116,   114,   806,   807,
     697,   698,   180,   246,   699,   700,   298,   858,   859,   408,
     405,   448,   449,   790,   791,     6,     7,   406,   409,   588,
     489,   490,   803,   855,   402,   804,   856,   808,   809,   403,
       8,   810,   811,   589,   590,   591,   860,   861,   669,   450,
     862,   863,   792,   793,   592,   720,    14,   593,   491,   594,
      92,   595,   670,   671,   672,   840,   841,   875,   876,   721,
     722,   723,    11,    12,   673,    19,   674,   111,   675,    68,
     676,   119,   724,   725,   120,   726,   131,   727,   737,   738,
     219,   220,   887,   888,   842,   843,   877,   878,   909,   910,
      17,    18,   739,   740,   741,    66,    67,    70,    71,   221,
     222,   223,   132,   502,   503,   133,   742,   134,   743,   155,
     744,   889,   890,    21,   504,   505,   506,   911,   912,    72,
      73,   135,    22,   137,    23,   139,    24,   141,    25,   158,
      26,   162,    27,   156,    28,   165,    29,   157,    30,   166,
      31,   169,    32,   512,   513,   161,   522,   523,   171,   532,
     533,    74,    75,   164,   514,   515,   516,   524,   525,   526,
     534,   535,   536,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,   109,   110,   143,   144,   183,   184,   231,
     232,   251,   252,   284,   285,   163,   338,   339,   375,   376,
     393,   394,   399,   400,   426,   427,   433,   434,   474,   475,
     651,   652,   692,   693,   172,   759,   760,   173,   174,   818,
     819,   175,   177,   176,   178,   242,   181,   234,   229,   230,
     236,   237,   244,   238,   239,   243,   240,   241,   249,   255,
     287,   277,   247,   288,   292,   325,   253,   280,   281,   282,
     257,   259,   261,   263,   265,   290,   267,   269,   271,   273,
     289,   293,   294,   295,   296,   299,   301,   275,   303,   304,
     305,   307,   306,   309,   308,   311,   313,   310,   315,   312,
     317,   323,   314,   319,   316,   321,   318,   320,   326,   322,
     328,   329,   330,   341,   343,   344,   346,   345,   646,   350,
     354,   356,   358,   360,   362,   364,   366,   368,   370,   372,
     374,   380,   383,   397,   398,   429,   432,   430,   440,   378,
     441,   445,   457,   382,   438,   444,   455,   456,   384,   458,
     468,   396,   459,   460,   461,   436,   466,   470,   471,   473,
     479,   477,   480,   545,   442,   467,   482,   481,   446,   486,
     496,   497,   498,   499,   500,   501,   483,   542,   487,   543,
     552,   549,   554,   546,   556,     0,   553,   555,   558,   557,
     562,   559,   563,   571,   572,   573,   575,   576,   577,   579,
     580,   581,   583,   547,   584,   585,   605,   587,   709,   495,
     550,   612,   614,   615,   616,   485,   617,   618,   606,   621,
     610,   633,   622,   609,   623,   624,   625,   626,   561,   619,
     627,   628,   629,   630,   631,   632,   636,   637,   638,   639,
     640,   641,   642,   648,   644,   647,     0,   643,   656,   687,
     654,   655,   711,   565,   660,   566,   567,   661,   662,   568,
     569,   607,   663,   664,   570,   574,   665,   666,   712,   667,
     668,   686,   578,   691,   713,   708,   714,   715,   716,   582,
     717,   755,     0,   756,   718,   649,   719,   757,   758,   765,
     766,     0,   659,   767,   768,   769,   770,   771,   776,   773,
     777,   778,   779,   586,   780,   764,   781,   782,   784,   785,
     786,   787,   788,   789,     0,     0,     0,     0,   798,   799,
     800,   801,   824,   825,   823,   826,   827,   828,   829,   830,
     831,   832,   634,   833,   834,   835,   836,   838,   839,   850,
     851,   852,   853,     0,   873,     0,   874,   870,   754,   871,
       0,   883,   884,   885,   886,   897,   898,   689,   837,   899,
     900,   901,   902,   904,   905,   907,   908,     0,     0,   774,
       0,   917,   918,   919,   920,   921,   922,   783,   849,   923,
     924,   926,   927,   928,   929,   872,     0,     0,     0,   903,
       0,     0,     0,     0,   896,     0,     0,     0,   906,     0,
       0,     0,   925
};

static const yytype_int16 yycheck[] =
{
       4,     4,    50,     4,     6,    46,     4,    99,     4,     4,
       4,    99,     4,    94,     4,    99,    97,    61,    97,     4,
     112,    48,     8,     9,     4,    73,    99,     4,   116,   108,
     114,    10,    73,    11,     8,     9,    77,   110,    79,    87,
      81,    89,    83,    91,     9,    93,    73,    95,    92,    14,
      36,     8,     9,   101,     0,   103,     9,   105,    85,   107,
      13,   109,    36,   111,    12,   113,    58,   115,    62,   117,
      66,    72,    70,    68,    64,    60,    56,    54,     8,     9,
      37,    38,    84,    86,    41,    42,    90,     8,     9,    97,
      97,     8,     9,     8,     9,     8,     9,   104,   106,     8,
       8,     9,   131,   139,    97,   134,   142,    37,    38,   102,
      43,    41,    42,    22,    23,    24,    37,    38,     8,    36,
      41,    42,    37,    38,    33,     8,    45,    36,    36,    38,
      15,    40,    22,    23,    24,     8,     9,     8,     9,    22,
      23,    24,     8,     9,    34,    47,    36,    51,    38,    49,
      40,     3,    35,    36,     8,    38,     3,    40,     8,     9,
       8,     9,     8,     9,    37,    38,    37,    38,     8,     9,
       8,     9,    22,    23,    24,     8,     9,     8,     9,    27,
      28,    29,     8,     8,     9,     3,    36,     8,    38,    54,
      40,    37,    38,    44,    19,    20,    21,    37,    38,     8,
       9,    15,    53,    39,    55,    39,    57,    39,    59,     7,
      61,    64,    63,    56,    65,    70,    67,    58,    69,     7,
      71,     7,    73,     8,     9,    62,     8,     9,     3,     8,
       9,     8,     9,    68,    19,    20,    21,    19,    20,    21,
      19,    20,    21,     8,     9,     8,     9,     8,     9,     8,
       9,     8,     9,     8,     9,     8,     9,     8,     9,    74,
      75,     8,     9,    74,    75,    66,    74,    75,     8,     9,
      74,    75,    96,    97,   118,   119,     8,     9,     8,     9,
     144,   145,   124,   125,     8,   130,   131,     3,     8,   138,
     139,     3,     3,     8,     8,    84,    15,     7,    60,    72,
       7,     6,     8,     7,     6,     3,     7,     6,    39,    17,
      78,   121,    15,    80,    86,    52,    16,     3,     3,     3,
      17,    17,    17,    17,    17,     7,    18,    18,    18,    18,
      82,     3,     8,     3,     8,     3,     3,    25,     3,     8,
       3,     3,     8,     3,     8,     3,     3,     8,     3,     8,
       3,    30,     8,     3,     8,     3,     8,     8,   127,     8,
       7,     7,     7,     7,     7,     4,     7,    90,   128,     7,
       7,     7,     7,     7,     7,     7,     7,     7,     7,     7,
       3,   135,     3,     8,     8,     7,     3,   123,     7,    31,
       3,     3,     8,    76,   143,    76,     4,     4,    38,     8,
      75,    88,     8,     8,     8,    32,     8,     7,   129,     3,
       7,    26,     3,   122,    40,    33,     3,     7,    38,     3,
      98,     4,     4,     4,     4,     4,    40,     4,    38,     3,
       3,     7,     7,    34,     3,    -1,     8,     7,     3,     7,
       3,    40,    38,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,   133,     3,     3,     3,     7,   131,    62,
     137,     7,     7,     7,     3,    76,     7,     3,    34,     7,
     141,     8,     7,    35,     7,     7,     7,     7,    76,    40,
       7,     7,     7,     7,     7,     7,     3,     3,     3,     3,
       3,     3,     3,    35,     3,     3,    -1,     7,     3,     3,
       7,     7,     3,    98,     7,    98,    98,     7,     7,    98,
      98,    75,     7,     7,   100,   100,     7,     7,     3,     8,
       7,     7,   100,     7,     3,     8,     3,     3,     3,   100,
       3,     3,    -1,     3,     8,    75,     7,     3,     3,     7,
       7,    -1,    76,     7,     7,     7,     7,     7,     3,     8,
       3,     3,     3,   120,     3,    76,     3,     3,     3,     3,
       3,     3,     3,     3,    -1,    -1,    -1,    -1,     7,     7,
       7,     7,     7,     7,    76,     7,     7,     7,     7,     7,
       7,     7,   125,     7,     7,     7,     7,     3,     3,     3,
       3,     3,     3,    -1,     3,    -1,     3,     7,   126,     7,
      -1,     7,     7,     7,     7,     3,     3,   136,   126,     3,
       3,     7,     7,     3,     3,     3,     3,    -1,    -1,   139,
      -1,     7,     7,     7,     7,     7,     7,   146,   126,     7,
       7,     3,     3,     7,     7,   132,    -1,    -1,    -1,   132,
      -1,    -1,    -1,    -1,   140,    -1,    -1,    -1,   140,    -1,
      -1,    -1,   140
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
     189,     3,     8,     3,     8,     3,     8,     3,     8,     6,
      84,    15,   226,     8,     9,    50,    73,    87,    89,    91,
      93,    95,   101,   103,   105,   107,   109,   111,   113,   115,
     117,   237,   238,   240,   241,   242,   243,   247,   251,   255,
     259,   263,   273,   283,   293,   303,   307,   311,   315,     8,
       9,    27,    28,    29,   327,   328,   329,   330,   331,    60,
      72,    74,    75,   190,     7,   211,     7,     6,     7,     6,
       7,     6,    84,     3,     8,     4,    86,    15,   316,    39,
     239,     8,     9,    16,   244,    17,   248,    17,   252,    17,
     256,    17,   260,    17,   308,    17,   304,    18,   264,    18,
     274,    18,   284,    18,   294,    25,   312,   121,   332,   333,
       3,     3,     3,   191,    74,    75,   212,    78,    80,    82,
       7,   227,    86,     3,     8,     3,     8,     4,    90,     3,
     245,     3,   249,     3,     8,     3,     8,     3,     8,     3,
       8,     3,     8,     3,     8,     3,     8,     3,     8,     3,
       8,     3,     8,    30,   334,    52,   127,   363,     7,     7,
       7,     8,     9,    36,   192,   193,   196,   213,    74,    75,
     228,     7,   317,     7,     4,    90,     7,    61,    92,   246,
       7,    94,    97,   250,     7,   253,     7,   257,     7,   261,
       7,   309,     7,   305,     7,   265,     7,   275,     7,   285,
       7,   295,     7,   313,     3,     8,     9,   335,    31,   364,
     135,   401,    76,     3,    38,   194,     8,     9,    36,   214,
     215,   218,   229,    74,    75,   318,    88,     8,     8,    96,
      97,   254,    97,   102,   258,    97,   104,   262,    97,   106,
     310,    97,   108,   306,    99,   110,   266,    99,   112,   276,
      99,   114,   286,    99,   116,   296,   118,   119,   314,     7,
     123,   336,     3,     8,     9,   365,    32,   402,   143,   439,
       7,     3,    40,   195,    76,     3,    38,   216,     8,     9,
      36,   230,   231,   234,   319,     4,     4,     8,     8,     8,
       8,     8,   267,   277,   287,   297,     8,    33,    75,   344,
       7,   129,   366,     3,     8,     9,   403,    26,   440,     7,
       3,     7,     3,    40,   217,    76,     3,    38,   232,     8,
       9,    36,   320,   321,   324,    62,    98,     4,     4,     4,
       4,     4,     8,     9,    19,    20,    21,   268,   269,   270,
     271,   272,     8,     9,    19,    20,    21,   278,   279,   280,
     281,   282,     8,     9,    19,    20,    21,   288,   289,   290,
     291,   292,     8,     9,    19,    20,    21,   298,   299,   300,
     301,   302,     4,     3,   345,   122,    34,   133,   374,     7,
     137,   404,     3,     8,     7,     7,     3,     7,     3,    40,
     233,    76,     3,    38,   322,    98,    98,    98,    98,    98,
     100,     3,     3,     3,   100,     3,     3,     3,   100,     3,
       3,     3,   100,     3,     3,     3,   120,     7,     8,    22,
      23,    24,    33,    36,    38,    40,   346,   347,   348,   349,
     350,   351,   352,   353,   354,     3,    34,    75,   382,    35,
     141,   412,     7,   441,     7,     7,     3,     7,     3,    40,
     323,     7,     7,     7,     7,     7,     7,     7,     7,     7,
       7,     7,     7,     8,   125,   355,     3,     3,     3,     3,
       3,     3,     3,     7,     3,   383,   128,     3,    35,    75,
     420,   144,   145,   442,     7,     7,     3,   337,   356,    76,
       7,     7,     7,     7,     7,     7,     7,     8,     7,     8,
      22,    23,    24,    34,    36,    38,    40,   384,   385,   386,
     387,   388,   389,   390,   391,   392,     7,     3,   421,   136,
     443,     7,   124,   125,   338,     8,     9,    37,    38,    41,
      42,   357,   358,   359,   360,   361,   362,   367,     8,   131,
     393,     3,     3,     3,     3,     3,     3,     3,     8,     7,
       8,    22,    23,    24,    35,    36,    38,    40,   422,   423,
     424,   425,   426,   427,   428,   429,   430,     8,     9,    22,
      23,    24,    36,    38,    40,   444,   445,   446,   447,   448,
     449,   450,   451,   339,   126,     3,     3,     3,     3,   130,
     131,   368,   375,   394,    76,     7,     7,     7,     7,     7,
       7,     7,   405,     8,   139,   431,     3,     3,     3,     3,
       3,     3,     3,   146,     3,     3,     3,     3,     3,     3,
       8,     9,    37,    38,   340,   341,   342,   343,     7,     7,
       7,     7,   369,   131,   134,   376,     8,     9,    37,    38,
      41,    42,   395,   396,   397,   398,   399,   400,   138,   139,
     406,   413,   432,    76,     7,     7,     7,     7,     7,     7,
       7,     7,     7,     7,     7,     7,     7,   126,     3,     3,
       8,     9,    37,    38,   370,   371,   372,   373,   377,   126,
       3,     3,     3,     3,   407,   139,   142,   414,     8,     9,
      37,    38,    41,    42,   433,   434,   435,   436,   437,   438,
       7,     7,   132,     3,     3,     8,     9,    37,    38,   378,
     379,   380,   381,     7,     7,     7,     7,     8,     9,    37,
      38,   408,   409,   410,   411,   415,   140,     3,     3,     3,
       3,     7,     7,   132,     3,     3,   140,     3,     3,     8,
       9,    37,    38,   416,   417,   418,   419,     7,     7,     7,
       7,     7,     7,     7,     7,   140,     3,     3,     7,     7
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

  case 102:

    {
}
    break;

  case 104:

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

  case 108:

    {
}
    break;

  case 110:

    {
}
    break;

  case 114:

    {
}
    break;

  case 115:

    {
}
    break;

  case 117:

    {
}
    break;

  case 124:

    {
}
    break;

  case 126:

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

  case 141:

    {
}
    break;

  case 142:

    {
}
    break;

  case 144:

    {
}
    break;

  case 151:

    {
}
    break;

  case 153:

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

  case 178:

    {
}
    break;

  case 180:

    {
}
    break;

  case 184:

    {
}
    break;

  case 185:

    {
}
    break;

  case 187:

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

  case 221:

    {
}
    break;

  case 222:

    {
}
    break;

  case 223:

    {
}
    break;

  case 227:

    {
}
    break;

  case 230:

    {
}
    break;

  case 236:

    {
}
    break;

  case 237:

    {
}
    break;

  case 238:

    {
}
    break;

  case 242:

    {
}
    break;

  case 245:

    {
}
    break;

  case 251:

    {
}
    break;

  case 252:

    {
}
    break;

  case 253:

    {
}
    break;

  case 257:

    {
}
    break;

  case 260:

    {
}
    break;

  case 266:

    {
}
    break;

  case 267:

    {
}
    break;

  case 268:

    {
}
    break;

  case 272:

    {
}
    break;

  case 275:

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

  case 294:

    {
}
    break;

  case 296:

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

  case 308:

    {
}
    break;

  case 309:

    {
}
    break;

  case 310:

    {
}
    break;

  case 317:

    {
}
    break;

  case 329:

    {
}
    break;

  case 330:

    {
}
    break;

  case 344:

    {
}
    break;

  case 345:

    {
}
    break;

  case 346:

    {
}
    break;

  case 347:

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

  case 359:

    {
}
    break;

  case 360:

    {
}
    break;

  case 361:

    {
}
    break;

  case 362:

    {
}
    break;

  case 368:

    {
}
    break;

  case 380:

    {
}
    break;

  case 381:

    {
}
    break;

  case 393:

    {
}
    break;

  case 394:

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

  case 423:

    {
}
    break;

  case 424:

    {
}
    break;

  case 425:

    {
}
    break;

  case 426:

    {
}
    break;

  case 432:

    {
}
    break;

  case 444:

    {
}
    break;

  case 445:

    {
}
    break;

  case 457:

    {
}
    break;

  case 458:

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

  case 487:

    {
}
    break;

  case 488:

    {
}
    break;

  case 489:

    {
}
    break;

  case 490:

    {
}
    break;

  case 495:

    {
}
    break;

  case 507:

    {
}
    break;

  case 508:

    {
}
    break;

  case 509:

    {
}
    break;

  case 510:

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


