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
#define YYLAST   649

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  148
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  308
/* YYNRULES -- Number of rules.  */
#define YYNRULES  521
/* YYNRULES -- Number of states.  */
#define YYNSTATES  940

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
      71,    76,    78,    80,    83,    87,    92,    94,    96,    99,
     103,   108,   110,   112,   115,   120,   126,   127,   131,   133,
     135,   138,   142,   147,   149,   151,   154,   158,   163,   165,
     167,   170,   174,   179,   181,   183,   186,   190,   195,   197,
     199,   202,   206,   211,   213,   215,   218,   223,   229,   230,
     231,   236,   242,   246,   247,   250,   254,   255,   258,   262,
     266,   267,   271,   272,   276,   278,   281,   282,   287,   290,
     291,   294,   296,   298,   300,   302,   304,   310,   316,   317,
     321,   327,   333,   334,   338,   344,   350,   351,   355,   357,
     359,   362,   366,   371,   377,   381,   382,   385,   389,   390,
     393,   397,   401,   402,   406,   407,   411,   413,   416,   417,
     422,   425,   426,   429,   431,   433,   435,   437,   440,   444,
     449,   455,   459,   460,   463,   467,   468,   471,   475,   479,
     480,   484,   485,   489,   491,   494,   495,   500,   503,   504,
     507,   509,   511,   513,   515,   517,   519,   521,   523,   525,
     527,   529,   531,   533,   535,   537,   543,   544,   548,   550,
     552,   555,   559,   564,   569,   573,   574,   577,   582,   587,
     591,   592,   595,   600,   606,   610,   611,   614,   619,   625,
     629,   630,   633,   638,   644,   648,   649,   652,   657,   663,
     667,   668,   671,   675,   676,   679,   681,   683,   685,   689,
     693,   697,   700,   702,   708,   712,   713,   716,   720,   721,
     724,   726,   728,   730,   734,   738,   742,   745,   747,   753,
     757,   758,   761,   765,   766,   769,   771,   773,   775,   779,
     783,   787,   790,   792,   798,   802,   803,   806,   810,   811,
     814,   816,   818,   820,   824,   828,   832,   835,   837,   843,
     847,   848,   851,   856,   862,   866,   867,   870,   875,   881,
     885,   886,   889,   894,   900,   904,   905,   908,   912,   913,
     916,   920,   924,   925,   929,   930,   934,   936,   939,   940,
     944,   945,   948,   950,   952,   954,   958,   962,   966,   970,
     972,   977,   978,   982,   983,   987,   992,   994,   995,  1003,
    1004,  1007,  1011,  1012,  1015,  1017,  1019,  1023,  1027,  1030,
    1032,  1033,  1037,  1038,  1041,  1043,  1045,  1047,  1049,  1051,
    1053,  1055,  1059,  1063,  1067,  1071,  1075,  1079,  1083,  1087,
    1091,  1092,  1095,  1097,  1099,  1101,  1103,  1107,  1111,  1115,
    1119,  1122,  1124,  1125,  1129,  1130,  1134,  1140,  1142,  1143,
    1151,  1152,  1155,  1159,  1160,  1163,  1165,  1167,  1171,  1175,
    1178,  1180,  1181,  1189,  1190,  1193,  1197,  1198,  1201,  1203,
    1205,  1209,  1213,  1216,  1218,  1219,  1223,  1224,  1227,  1229,
    1231,  1233,  1235,  1237,  1239,  1241,  1245,  1249,  1253,  1257,
    1261,  1265,  1269,  1273,  1277,  1278,  1281,  1283,  1285,  1287,
    1289,  1293,  1297,  1301,  1305,  1308,  1310,  1311,  1315,  1316,
    1320,  1326,  1328,  1329,  1337,  1338,  1341,  1345,  1346,  1349,
    1351,  1353,  1357,  1361,  1364,  1366,  1367,  1375,  1376,  1379,
    1383,  1384,  1387,  1389,  1391,  1395,  1399,  1402,  1404,  1405,
    1409,  1410,  1413,  1415,  1417,  1419,  1421,  1423,  1425,  1427,
    1431,  1435,  1439,  1443,  1447,  1451,  1455,  1459,  1463,  1464,
    1467,  1469,  1471,  1473,  1475,  1479,  1483,  1487,  1491,  1494,
    1496,  1497,  1503,  1507,  1508,  1511,  1515,  1516,  1519,  1521,
    1523,  1525,  1527,  1529,  1531,  1535,  1539,  1543,  1547,  1551,
    1555,  1558
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     149,     0,    -1,   150,     8,   151,    12,    -1,   150,     9,
      -1,    10,    -1,    10,    11,    -1,   152,   201,   223,   239,
     329,    -1,    -1,   153,   154,    -1,    43,    -1,     8,   155,
      44,    -1,     9,    -1,    -1,   155,   156,    -1,   157,    -1,
     161,    -1,   164,    -1,   167,    -1,   171,    -1,   174,    -1,
     177,    -1,   180,    -1,   183,    -1,   186,    -1,   191,    -1,
     158,   159,    -1,    53,    -1,     9,    -1,     8,    54,    -1,
      -1,     8,     4,   160,    54,    -1,   162,    -1,   163,    -1,
      55,     9,    -1,    55,     8,    56,    -1,    55,     8,     4,
      56,    -1,   165,    -1,   166,    -1,    57,     9,    -1,    57,
       8,    58,    -1,    57,     8,     4,    58,    -1,   168,    -1,
     169,    -1,    59,     9,    -1,    59,   170,     8,    60,    -1,
      59,   170,     8,     4,    60,    -1,    -1,    13,     3,     7,
      -1,   172,    -1,   173,    -1,    61,     9,    -1,    61,     8,
      62,    -1,    61,     8,     4,    62,    -1,   175,    -1,   176,
      -1,    63,     9,    -1,    63,     8,    64,    -1,    63,     8,
       4,    64,    -1,   178,    -1,   179,    -1,    65,     9,    -1,
      65,     8,    66,    -1,    65,     8,     4,    66,    -1,   181,
      -1,   182,    -1,    67,     9,    -1,    67,     8,    68,    -1,
      67,     8,     4,    68,    -1,   184,    -1,   185,    -1,    69,
       9,    -1,    69,     8,    70,    -1,    69,     8,     4,    70,
      -1,   187,    -1,   188,    -1,    71,     9,    -1,    71,   189,
       8,    72,    -1,    71,   189,     8,     4,    72,    -1,    -1,
      -1,    14,     3,   190,     7,    -1,    73,   192,     8,   193,
      74,    -1,    15,     3,     7,    -1,    -1,   193,   194,    -1,
      75,   195,   200,    -1,    -1,   195,   196,    -1,   197,   198,
     199,    -1,    36,     3,     7,    -1,    -1,    38,     3,     7,
      -1,    -1,    40,     3,     7,    -1,     9,    -1,     8,    76,
      -1,    -1,    45,     8,   202,    46,    -1,    45,     9,    -1,
      -1,   202,   203,    -1,   204,    -1,   206,    -1,   208,    -1,
     210,    -1,   213,    -1,    77,   205,     8,     6,    78,    -1,
      77,   205,     8,     5,    78,    -1,    -1,    39,     3,     7,
      -1,    79,   207,     8,     6,    80,    -1,    79,   207,     8,
       5,    80,    -1,    -1,    39,     3,     7,    -1,    81,   209,
       8,     6,    82,    -1,    81,   209,     8,     5,    82,    -1,
      -1,    39,     3,     7,    -1,   211,    -1,   212,    -1,    83,
       9,    -1,    83,     8,    84,    -1,    83,     8,     5,    84,
      -1,    73,   214,     8,   215,    74,    -1,    15,     3,     7,
      -1,    -1,   215,   216,    -1,    75,   217,   222,    -1,    -1,
     217,   218,    -1,   219,   220,   221,    -1,    36,     3,     7,
      -1,    -1,    38,     3,     7,    -1,    -1,    40,     3,     7,
      -1,     9,    -1,     8,    76,    -1,    -1,    47,     8,   224,
      48,    -1,    47,     9,    -1,    -1,   224,   225,    -1,   226,
      -1,   229,    -1,   227,    -1,   228,    -1,    85,     9,    -1,
      85,     8,    86,    -1,    85,     8,     4,    86,    -1,    73,
     230,     8,   231,    74,    -1,    15,     3,     7,    -1,    -1,
     231,   232,    -1,    75,   233,   238,    -1,    -1,   233,   234,
      -1,   235,   236,   237,    -1,    36,     3,     7,    -1,    -1,
      38,     3,     7,    -1,    -1,    40,     3,     7,    -1,     9,
      -1,     8,    76,    -1,    -1,    49,     8,   240,    50,    -1,
      49,     9,    -1,    -1,   240,   241,    -1,   242,    -1,   244,
      -1,   247,    -1,   251,    -1,   255,    -1,   259,    -1,   263,
      -1,   267,    -1,   277,    -1,   287,    -1,   297,    -1,   307,
      -1,   311,    -1,   315,    -1,   319,    -1,    87,   243,     8,
       4,    88,    -1,    -1,    39,     3,     7,    -1,   245,    -1,
     246,    -1,    89,     9,    -1,    89,     8,    90,    -1,    89,
       8,     4,    90,    -1,    91,   248,   249,    92,    -1,    16,
       3,     7,    -1,    -1,   249,   250,    -1,    61,     8,     4,
      62,    -1,    93,   252,   253,    94,    -1,    17,     3,     7,
      -1,    -1,   253,   254,    -1,    97,     8,     4,    98,    -1,
      95,   256,     8,   257,    96,    -1,    17,     3,     7,    -1,
      -1,   257,   258,    -1,    97,     8,     4,    98,    -1,   101,
     260,     8,   261,   102,    -1,    17,     3,     7,    -1,    -1,
     261,   262,    -1,    97,     8,     4,    98,    -1,   103,   264,
       8,   265,   104,    -1,    17,     3,     7,    -1,    -1,   265,
     266,    -1,    97,     8,     4,    98,    -1,   109,   268,     8,
     269,   110,    -1,    18,     3,     7,    -1,    -1,   269,   270,
      -1,    99,   271,   276,    -1,    -1,   271,   272,    -1,   273,
      -1,   274,    -1,   275,    -1,    19,     3,     7,    -1,    20,
       3,     7,    -1,    21,     3,     7,    -1,     8,   100,    -1,
       9,    -1,   111,   278,     8,   279,   112,    -1,    18,     3,
       7,    -1,    -1,   279,   280,    -1,    99,   281,   286,    -1,
      -1,   281,   282,    -1,   283,    -1,   284,    -1,   285,    -1,
      19,     3,     7,    -1,    20,     3,     7,    -1,    21,     3,
       7,    -1,     8,   100,    -1,     9,    -1,   113,   288,     8,
     289,   114,    -1,    18,     3,     7,    -1,    -1,   289,   290,
      -1,    99,   291,   296,    -1,    -1,   291,   292,    -1,   293,
      -1,   294,    -1,   295,    -1,    19,     3,     7,    -1,    20,
       3,     7,    -1,    21,     3,     7,    -1,     8,   100,    -1,
       9,    -1,   115,   298,     8,   299,   116,    -1,    18,     3,
       7,    -1,    -1,   299,   300,    -1,    99,   301,   306,    -1,
      -1,   301,   302,    -1,   303,    -1,   304,    -1,   305,    -1,
      19,     3,     7,    -1,    20,     3,     7,    -1,    21,     3,
       7,    -1,     8,   100,    -1,     9,    -1,   107,   308,     8,
     309,   108,    -1,    17,     3,     7,    -1,    -1,   309,   310,
      -1,    97,     8,     4,    98,    -1,   105,   312,     8,   313,
     106,    -1,    17,     3,     7,    -1,    -1,   313,   314,    -1,
      97,     8,     4,    98,    -1,   117,   316,     8,   317,   118,
      -1,    25,     3,     7,    -1,    -1,   317,   318,    -1,   119,
       8,     4,   120,    -1,    73,   320,     8,   321,    74,    -1,
      15,     3,     7,    -1,    -1,   321,   322,    -1,    75,   323,
     328,    -1,    -1,   323,   324,    -1,   325,   326,   327,    -1,
      36,     3,     7,    -1,    -1,    38,     3,     7,    -1,    -1,
      40,     3,     7,    -1,     9,    -1,     8,    76,    -1,    -1,
      51,   330,   335,    -1,    -1,   330,   331,    -1,   332,    -1,
     333,    -1,   334,    -1,    27,     3,     7,    -1,    29,     3,
       7,    -1,    28,     3,     7,    -1,     8,   336,    52,    -1,
       9,    -1,   337,   367,   405,   443,    -1,    -1,   121,   338,
     339,    -1,    -1,    30,     3,     7,    -1,     8,   340,   348,
     122,    -1,     9,    -1,    -1,   123,    33,     3,     7,     8,
     341,   124,    -1,    -1,   341,   342,    -1,   125,   343,   347,
      -1,    -1,   343,   344,    -1,   345,    -1,   346,    -1,    37,
       3,     7,    -1,    38,     3,     7,    -1,     8,   126,    -1,
       9,    -1,    -1,    75,   349,   358,    -1,    -1,   349,   350,
      -1,   351,    -1,   352,    -1,   353,    -1,   354,    -1,   355,
      -1,   356,    -1,   357,    -1,    33,     3,     7,    -1,    36,
       3,     7,    -1,    38,     3,     7,    -1,    22,     3,     7,
      -1,    23,     3,     7,    -1,    24,     3,     7,    -1,    40,
       3,     7,    -1,     8,   359,    76,    -1,   125,   360,   366,
      -1,    -1,   360,   361,    -1,   362,    -1,   363,    -1,   364,
      -1,   365,    -1,    37,     3,     7,    -1,    38,     3,     7,
      -1,    41,     3,     7,    -1,    42,     3,     7,    -1,     8,
     126,    -1,     9,    -1,    -1,   127,   368,   369,    -1,    -1,
      31,     3,     7,    -1,     8,   370,   378,   386,   128,    -1,
       9,    -1,    -1,   129,    34,     3,     7,     8,   371,   130,
      -1,    -1,   371,   372,    -1,   131,   373,   377,    -1,    -1,
     373,   374,    -1,   375,    -1,   376,    -1,    37,     3,     7,
      -1,    38,     3,     7,    -1,     8,   132,    -1,     9,    -1,
      -1,   133,    34,     3,     7,     8,   379,   134,    -1,    -1,
     379,   380,    -1,   131,   381,   385,    -1,    -1,   381,   382,
      -1,   383,    -1,   384,    -1,    37,     3,     7,    -1,    38,
       3,     7,    -1,     8,   132,    -1,     9,    -1,    -1,    75,
     387,   396,    -1,    -1,   387,   388,    -1,   389,    -1,   390,
      -1,   391,    -1,   392,    -1,   393,    -1,   394,    -1,   395,
      -1,    34,     3,     7,    -1,    36,     3,     7,    -1,    38,
       3,     7,    -1,    22,     3,     7,    -1,    23,     3,     7,
      -1,    24,     3,     7,    -1,    40,     3,     7,    -1,     8,
     397,    76,    -1,   131,   398,   404,    -1,    -1,   398,   399,
      -1,   400,    -1,   401,    -1,   402,    -1,   403,    -1,    37,
       3,     7,    -1,    38,     3,     7,    -1,    41,     3,     7,
      -1,    42,     3,     7,    -1,     8,   126,    -1,     9,    -1,
      -1,   135,   406,   407,    -1,    -1,    32,     3,     7,    -1,
       8,   408,   416,   424,   136,    -1,     9,    -1,    -1,   137,
      35,     3,     7,     8,   409,   138,    -1,    -1,   409,   410,
      -1,   139,   411,   415,    -1,    -1,   411,   412,    -1,   413,
      -1,   414,    -1,    37,     3,     7,    -1,    38,     3,     7,
      -1,     8,   140,    -1,     9,    -1,    -1,   141,    35,     3,
       7,     8,   417,   142,    -1,    -1,   417,   418,    -1,   139,
     419,   423,    -1,    -1,   419,   420,    -1,   421,    -1,   422,
      -1,    37,     3,     7,    -1,    38,     3,     7,    -1,     8,
     140,    -1,     9,    -1,    -1,    75,   425,   434,    -1,    -1,
     425,   426,    -1,   427,    -1,   428,    -1,   429,    -1,   430,
      -1,   431,    -1,   432,    -1,   433,    -1,    35,     3,     7,
      -1,    36,     3,     7,    -1,    38,     3,     7,    -1,    22,
       3,     7,    -1,    23,     3,     7,    -1,    24,     3,     7,
      -1,    40,     3,     7,    -1,     8,   435,    76,    -1,   139,
     436,   442,    -1,    -1,   436,   437,    -1,   438,    -1,   439,
      -1,   440,    -1,   441,    -1,    37,     3,     7,    -1,    38,
       3,     7,    -1,    41,     3,     7,    -1,    42,     3,     7,
      -1,     8,   140,    -1,     9,    -1,    -1,   143,   444,     8,
     445,   144,    -1,    26,     3,     7,    -1,    -1,   445,   446,
      -1,   145,   447,   455,    -1,    -1,   447,   448,    -1,   449,
      -1,   450,    -1,   451,    -1,   452,    -1,   453,    -1,   454,
      -1,    36,     3,     7,    -1,    38,     3,     7,    -1,    22,
       3,     7,    -1,    23,     3,     7,    -1,    24,     3,     7,
      -1,    40,     3,     7,    -1,     8,   146,    -1,     9,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   124,   124,   125,   127,   128,   130,   132,   132,   134,
     145,   146,   148,   148,   150,   150,   150,   150,   150,   151,
     151,   151,   151,   151,   151,   154,   156,   166,   167,   168,
     168,   175,   175,   177,   178,   182,   187,   187,   189,   190,
     194,   199,   199,   201,   202,   206,   210,   210,   215,   215,
     217,   218,   222,   227,   227,   229,   230,   234,   239,   239,
     241,   242,   246,   251,   251,   253,   254,   258,   263,   263,
     265,   266,   270,   274,   274,   276,   277,   281,   285,   286,
     285,   292,   294,   298,   298,   300,   302,   302,   304,   306,
     310,   310,   314,   314,   318,   318,   323,   324,   325,   327,
     327,   329,   329,   329,   329,   329,   331,   332,   336,   336,
     340,   341,   345,   345,   349,   350,   354,   354,   358,   358,
     360,   361,   365,   369,   371,   375,   375,   377,   379,   379,
     381,   383,   387,   387,   391,   391,   395,   395,   400,   401,
     402,   404,   404,   406,   406,   408,   408,   410,   411,   415,
     420,   422,   426,   426,   428,   430,   430,   432,   434,   438,
     438,   442,   442,   446,   446,   451,   452,   453,   455,   455,
     457,   457,   457,   457,   457,   458,   458,   458,   458,   458,
     459,   459,   459,   459,   459,   461,   465,   465,   469,   469,
     471,   472,   476,   480,   482,   486,   486,   489,   493,   496,
     500,   500,   502,   506,   509,   513,   513,   515,   519,   522,
     526,   526,   528,   532,   535,   539,   539,   541,   545,   548,
     552,   552,   554,   558,   558,   560,   560,   560,   562,   566,
     570,   574,   574,   577,   580,   584,   584,   586,   590,   590,
     592,   592,   592,   594,   598,   602,   606,   606,   609,   612,
     616,   616,   618,   622,   622,   624,   624,   624,   626,   630,
     634,   638,   638,   641,   644,   648,   648,   650,   654,   654,
     656,   656,   656,   658,   662,   666,   670,   670,   674,   677,
     681,   681,   683,   687,   690,   694,   694,   696,   701,   704,
     708,   708,   710,   715,   717,   721,   721,   723,   725,   725,
     727,   729,   733,   733,   737,   737,   741,   741,   746,   746,
     748,   748,   750,   750,   750,   752,   756,   760,   764,   764,
     766,   768,   768,   770,   770,   774,   775,   777,   777,   780,
     780,   782,   784,   784,   786,   786,   788,   792,   796,   796,
     799,   799,   801,   801,   804,   805,   806,   807,   808,   809,
     810,   812,   816,   820,   824,   828,   832,   836,   841,   843,
     845,   845,   848,   849,   850,   851,   853,   857,   861,   865,
     869,   869,   871,   871,   873,   873,   877,   879,   882,   882,
     885,   885,   887,   889,   889,   891,   891,   893,   897,   901,
     901,   904,   904,   907,   907,   909,   911,   911,   913,   913,
     915,   919,   923,   923,   926,   926,   928,   928,   931,   932,
     933,   934,   935,   936,   937,   939,   943,   947,   951,   955,
     959,   963,   968,   970,   972,   972,   975,   976,   977,   978,
     980,   984,   988,   992,   996,   996,   998,   998,  1000,  1000,
    1004,  1006,  1008,  1008,  1011,  1011,  1013,  1015,  1015,  1017,
    1017,  1019,  1023,  1027,  1027,  1030,  1030,  1033,  1033,  1035,
    1037,  1037,  1039,  1039,  1041,  1045,  1049,  1049,  1052,  1052,
    1054,  1054,  1057,  1058,  1059,  1060,  1061,  1062,  1063,  1065,
    1069,  1073,  1077,  1081,  1085,  1089,  1094,  1096,  1098,  1098,
    1101,  1102,  1103,  1104,  1106,  1110,  1114,  1118,  1122,  1122,
    1125,  1125,  1127,  1131,  1131,  1133,  1135,  1135,  1138,  1139,
    1140,  1141,  1142,  1143,  1145,  1149,  1153,  1157,  1161,  1165,
    1170,  1170
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
  "emptyservicename", "nonemptyservicename", "instancename",
  "emptyinstancename", "nonemptyinstancename", "instancelocation",
  "emptylocation", "nonemptylocation", "locationtypeatt", "jobid",
  "emptyjobid", "nonemptyjobid", "solvertoinvoke", "emptysolver",
  "nonemptysolver", "license", "emptylicense", "nonemptylicense",
  "username", "emptyusername", "nonemptyusername", "password",
  "emptypassword", "nonemptypassword", "contact", "emptycontact",
  "nonemptycontact", "transporttypeatt", "@2", "othergeneraloptions",
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
     156,   156,   156,   156,   156,   157,   158,   159,   159,   160,
     159,   161,   161,   162,   162,   163,   164,   164,   165,   165,
     166,   167,   167,   168,   168,   169,   170,   170,   171,   171,
     172,   172,   173,   174,   174,   175,   175,   176,   177,   177,
     178,   178,   179,   180,   180,   181,   181,   182,   183,   183,
     184,   184,   185,   186,   186,   187,   187,   188,   189,   190,
     189,   191,   192,   193,   193,   194,   195,   195,   196,   197,
     198,   198,   199,   199,   200,   200,   201,   201,   201,   202,
     202,   203,   203,   203,   203,   203,   204,   204,   205,   205,
     206,   206,   207,   207,   208,   208,   209,   209,   210,   210,
     211,   211,   212,   213,   214,   215,   215,   216,   217,   217,
     218,   219,   220,   220,   221,   221,   222,   222,   223,   223,
     223,   224,   224,   225,   225,   226,   226,   227,   227,   228,
     229,   230,   231,   231,   232,   233,   233,   234,   235,   236,
     236,   237,   237,   238,   238,   239,   239,   239,   240,   240,
     241,   241,   241,   241,   241,   241,   241,   241,   241,   241,
     241,   241,   241,   241,   241,   242,   243,   243,   244,   244,
     245,   245,   246,   247,   248,   249,   249,   250,   251,   252,
     253,   253,   254,   255,   256,   257,   257,   258,   259,   260,
     261,   261,   262,   263,   264,   265,   265,   266,   267,   268,
     269,   269,   270,   271,   271,   272,   272,   272,   273,   274,
     275,   276,   276,   277,   278,   279,   279,   280,   281,   281,
     282,   282,   282,   283,   284,   285,   286,   286,   287,   288,
     289,   289,   290,   291,   291,   292,   292,   292,   293,   294,
     295,   296,   296,   297,   298,   299,   299,   300,   301,   301,
     302,   302,   302,   303,   304,   305,   306,   306,   307,   308,
     309,   309,   310,   311,   312,   313,   313,   314,   315,   316,
     317,   317,   318,   319,   320,   321,   321,   322,   323,   323,
     324,   325,   326,   326,   327,   327,   328,   328,   329,   329,
     330,   330,   331,   331,   331,   332,   333,   334,   335,   335,
     336,   337,   337,   338,   338,   339,   339,   340,   340,   341,
     341,   342,   343,   343,   344,   344,   345,   346,   347,   347,
     348,   348,   349,   349,   350,   350,   350,   350,   350,   350,
     350,   351,   352,   353,   354,   355,   356,   357,   358,   359,
     360,   360,   361,   361,   361,   361,   362,   363,   364,   365,
     366,   366,   367,   367,   368,   368,   369,   369,   370,   370,
     371,   371,   372,   373,   373,   374,   374,   375,   376,   377,
     377,   378,   378,   379,   379,   380,   381,   381,   382,   382,
     383,   384,   385,   385,   386,   386,   387,   387,   388,   388,
     388,   388,   388,   388,   388,   389,   390,   391,   392,   393,
     394,   395,   396,   397,   398,   398,   399,   399,   399,   399,
     400,   401,   402,   403,   404,   404,   405,   405,   406,   406,
     407,   407,   408,   408,   409,   409,   410,   411,   411,   412,
     412,   413,   414,   415,   415,   416,   416,   417,   417,   418,
     419,   419,   420,   420,   421,   422,   423,   423,   424,   424,
     425,   425,   426,   426,   426,   426,   426,   426,   426,   427,
     428,   429,   430,   431,   432,   433,   434,   435,   436,   436,
     437,   437,   437,   437,   438,   439,   440,   441,   442,   442,
     443,   443,   444,   445,   445,   446,   447,   447,   448,   448,
     448,   448,   448,   448,   449,   450,   451,   452,   453,   454,
     455,   455
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     4,     2,     1,     2,     5,     0,     2,     1,
       3,     1,     0,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     2,     1,     1,     2,     0,
       4,     1,     1,     2,     3,     4,     1,     1,     2,     3,
       4,     1,     1,     2,     4,     5,     0,     3,     1,     1,
       2,     3,     4,     1,     1,     2,     3,     4,     1,     1,
       2,     3,     4,     1,     1,     2,     3,     4,     1,     1,
       2,     3,     4,     1,     1,     2,     4,     5,     0,     0,
       4,     5,     3,     0,     2,     3,     0,     2,     3,     3,
       0,     3,     0,     3,     1,     2,     0,     4,     2,     0,
       2,     1,     1,     1,     1,     1,     5,     5,     0,     3,
       5,     5,     0,     3,     5,     5,     0,     3,     1,     1,
       2,     3,     4,     5,     3,     0,     2,     3,     0,     2,
       3,     3,     0,     3,     0,     3,     1,     2,     0,     4,
       2,     0,     2,     1,     1,     1,     1,     2,     3,     4,
       5,     3,     0,     2,     3,     0,     2,     3,     3,     0,
       3,     0,     3,     1,     2,     0,     4,     2,     0,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     5,     0,     3,     1,     1,
       2,     3,     4,     4,     3,     0,     2,     4,     4,     3,
       0,     2,     4,     5,     3,     0,     2,     4,     5,     3,
       0,     2,     4,     5,     3,     0,     2,     4,     5,     3,
       0,     2,     3,     0,     2,     1,     1,     1,     3,     3,
       3,     2,     1,     5,     3,     0,     2,     3,     0,     2,
       1,     1,     1,     3,     3,     3,     2,     1,     5,     3,
       0,     2,     3,     0,     2,     1,     1,     1,     3,     3,
       3,     2,     1,     5,     3,     0,     2,     3,     0,     2,
       1,     1,     1,     3,     3,     3,     2,     1,     5,     3,
       0,     2,     4,     5,     3,     0,     2,     4,     5,     3,
       0,     2,     4,     5,     3,     0,     2,     3,     0,     2,
       3,     3,     0,     3,     0,     3,     1,     2,     0,     3,
       0,     2,     1,     1,     1,     3,     3,     3,     3,     1,
       4,     0,     3,     0,     3,     4,     1,     0,     7,     0,
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
       3,     3,     3,     3,     2,     1,     0,     3,     0,     3,
       5,     1,     0,     7,     0,     2,     3,     0,     2,     1,
       1,     3,     3,     2,     1,     0,     7,     0,     2,     3,
       0,     2,     1,     1,     3,     3,     2,     1,     0,     3,
       0,     2,     1,     1,     1,     1,     1,     1,     1,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     0,     2,
       1,     1,     1,     1,     3,     3,     3,     3,     2,     1,
       0,     5,     3,     0,     2,     3,     0,     2,     1,     1,
       1,     1,     1,     1,     3,     3,     3,     3,     3,     3,
       2,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       0,     4,     0,     0,     5,     1,     7,     3,     9,     0,
      96,     0,     2,     0,   138,    12,    11,     8,    99,    98,
       0,   165,     0,     0,   141,   140,     0,   308,    10,    26,
       0,     0,    46,     0,     0,     0,     0,     0,    78,     0,
      13,    14,     0,    15,    31,    32,    16,    36,    37,    17,
      41,    42,    18,    48,    49,    19,    53,    54,    20,    58,
      59,    21,    63,    64,    22,    68,    69,    23,    73,    74,
      24,    97,     0,   108,   112,   116,     0,   100,   101,   102,
     103,   104,   118,   119,   105,     0,   168,   167,   310,     6,
       0,    33,     0,    38,    43,     0,     0,     0,    50,     0,
      55,     0,    60,     0,    65,     0,    70,    75,     0,     0,
       0,     0,     0,    27,    25,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   120,   139,     0,     0,   142,   143,
     145,   146,   144,     0,     0,     0,    34,     0,    39,     0,
       0,     0,    51,     0,    56,     0,    61,     0,    66,     0,
      71,    79,     0,     0,    83,    29,    28,     0,   125,     0,
       0,     0,     0,     0,     0,     0,   121,     0,     0,     0,
     147,   166,     0,   186,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   169,   170,   171,
     188,   189,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   321,   319,     0,     0,     0,
     311,   312,   313,   314,   309,    35,    40,    47,     0,    44,
      52,    57,    62,    67,    72,     0,     0,    76,    82,     0,
       0,   124,     0,   109,     0,     0,   113,     0,     0,   117,
       0,     0,   122,     0,   152,     0,   148,     0,     0,     0,
       0,     0,   190,     0,   195,     0,   200,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   323,     0,   372,
       0,     0,     0,    45,    80,    77,    81,    86,    84,    30,
     123,   128,   126,   107,   106,   111,   110,   115,   114,   151,
       0,   149,     0,   295,     0,     0,     0,   191,     0,     0,
       0,     0,     0,   205,     0,   210,     0,   215,     0,   285,
       0,   280,     0,   220,     0,   235,     0,   250,     0,   265,
       0,   290,     0,     0,   318,   374,   436,   315,   317,   316,
       0,     0,   150,   155,   153,   294,     0,   187,     0,   192,
     194,     0,   193,   196,   199,   198,     0,   201,   204,     0,
     209,     0,   214,     0,   284,     0,   279,     0,   219,     0,
     234,     0,   249,     0,   264,     0,   289,     0,     0,   327,
     326,   322,     0,     0,   438,   500,     0,    94,     0,    87,
      90,    85,     0,   136,     0,   129,   132,   127,     0,   293,
     298,   296,   185,     0,     0,   203,     0,   206,     0,   208,
     211,     0,   213,   216,     0,   283,   286,     0,   278,   281,
     223,   218,   221,   238,   233,   236,   253,   248,   251,   268,
     263,   266,   288,     0,   291,   324,     0,   340,     0,   378,
     377,   373,     0,     0,     0,   320,    95,     0,     0,    92,
     137,     0,     0,   134,     0,   163,     0,   156,   159,   154,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   342,     0,   375,     0,   391,     0,
     442,   441,   437,     0,     0,    89,     0,     0,    88,   131,
       0,     0,   130,   164,     0,     0,   161,     0,   306,     0,
     299,   302,   297,   197,   202,     0,     0,     0,     0,     0,
       0,   232,     0,     0,     0,   224,   225,   226,   227,   222,
       0,   247,     0,     0,     0,   239,   240,   241,   242,   237,
       0,   262,     0,     0,     0,   254,   255,   256,   257,   252,
       0,   277,     0,     0,     0,   269,   270,   271,   272,   267,
       0,     0,     0,   325,     0,     0,   404,   439,     0,   455,
       0,   503,    91,     0,   133,     0,   158,     0,     0,   157,
     307,     0,     0,   304,   207,   212,   217,   287,   282,   231,
       0,     0,     0,   246,     0,     0,     0,   261,     0,     0,
       0,   276,     0,     0,     0,   292,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   343,   344,   345,   346,   347,
     348,   349,   350,   341,     0,     0,   406,     0,     0,     0,
     468,   502,     0,    93,   135,   160,     0,   301,     0,     0,
     300,   228,   229,   230,   243,   244,   245,   258,   259,   260,
     273,   274,   275,   329,   360,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   376,     0,     0,   470,
       0,   501,   506,   504,   162,   303,     0,     0,     0,   358,
     354,   355,   356,   351,   352,   353,   357,   380,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   407,   408,   409,
     410,   411,   412,   413,   414,   405,     0,     0,     0,   440,
       0,   305,   328,   332,   330,     0,   371,     0,     0,     0,
       0,   361,   362,   363,   364,   365,   359,     0,   393,   424,
       0,     0,     0,     0,     0,     0,     0,     0,   444,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   471,   472,
     473,   474,   475,   476,   477,   478,   469,     0,   521,     0,
       0,     0,     0,     0,     0,   507,   508,   509,   510,   511,
     512,   513,   505,     0,   370,     0,     0,     0,     0,   379,
     383,   381,     0,     0,   422,   418,   419,   420,   415,   416,
     417,   421,     0,   457,   488,     0,     0,     0,     0,     0,
       0,     0,     0,   520,     0,     0,     0,     0,     0,     0,
       0,   339,     0,     0,   333,   334,   335,   331,   366,   367,
     368,   369,     0,   396,   392,   394,     0,   435,     0,     0,
       0,     0,   425,   426,   427,   428,   429,   423,   443,   447,
     445,     0,     0,   486,   482,   483,   484,   479,   480,   481,
     485,   516,   517,   518,   514,   515,   519,   338,     0,     0,
       0,   390,     0,     0,   384,   385,   386,   382,     0,   434,
       0,     0,     0,     0,     0,   460,   456,   458,     0,   499,
       0,     0,     0,     0,   489,   490,   491,   492,   493,   487,
     336,   337,   389,     0,     0,     0,   403,     0,     0,   397,
     398,   399,   395,   430,   431,   432,   433,     0,   454,     0,
       0,   448,   449,   450,   446,     0,   498,     0,     0,     0,
       0,   387,   388,   402,     0,     0,   453,     0,     0,     0,
     467,     0,     0,   461,   462,   463,   459,   494,   495,   496,
     497,   400,   401,   451,   452,   466,     0,     0,   464,   465
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,     9,    10,    11,    17,    22,    40,    41,
      42,   114,   230,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    96,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,   109,   225,    70,   111,   229,   288,   340,   389,   390,
     449,   488,   391,    14,    23,    77,    78,   118,    79,   120,
      80,   122,    81,    82,    83,    84,   116,   232,   292,   341,
     395,   396,   453,   492,   397,    21,    85,   128,   129,   130,
     131,   132,   168,   300,   344,   398,   457,   458,   496,   569,
     459,    27,   133,   187,   188,   250,   189,   190,   191,   192,
     254,   309,   353,   193,   256,   311,   357,   194,   258,   359,
     407,   195,   260,   361,   410,   196,   262,   363,   413,   197,
     268,   369,   422,   468,   515,   516,   517,   518,   519,   198,
     270,   371,   425,   469,   525,   526,   527,   528,   529,   199,
     272,   373,   428,   470,   535,   536,   537,   538,   539,   200,
     274,   375,   431,   471,   545,   546,   547,   548,   549,   201,
     266,   367,   419,   202,   264,   365,   416,   203,   276,   377,
     434,   204,   248,   346,   401,   460,   500,   501,   573,   630,
     502,    89,   134,   210,   211,   212,   213,   214,   278,   279,
     333,   381,   437,   667,   704,   763,   804,   805,   806,   807,
     475,   552,   605,   606,   607,   608,   609,   610,   611,   612,
     613,   645,   668,   711,   712,   713,   714,   715,   716,   336,
     383,   441,   478,   717,   771,   812,   854,   855,   856,   857,
     556,   772,   815,   858,   889,   890,   891,   892,   617,   655,
     687,   688,   689,   690,   691,   692,   693,   694,   695,   720,
     773,   822,   823,   824,   825,   826,   827,   385,   443,   482,
     559,   782,   830,   864,   901,   902,   903,   904,   620,   831,
     867,   905,   923,   924,   925,   926,   660,   698,   738,   739,
     740,   741,   742,   743,   744,   745,   746,   785,   832,   874,
     875,   876,   877,   878,   879,   445,   484,   622,   663,   700,
     755,   756,   757,   758,   759,   760,   761,   762
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
     -91,   -91,     0,   218,   -91,   -91,   -91,   220,   -91,   291,
     262,   292,   264,   297,   266,   222,   -91,   231,   299,    -3,
     -91,   -91,   290,   269,   265,   293,   294,   295,   296,   298,
     300,   301,   302,   303,   304,   305,   285,   -91,   -91,   -91,
     -91,   -91,   -91,   -91,   -91,   -91,   -91,   -91,   -91,   -91,
     -91,   -91,   -91,   -91,   -91,   193,   -91,   313,   316,   321,
     -91,   -91,   -91,   -91,   -91,   -91,   -91,   -91,   267,   -91,
     -91,   -91,   -91,   -91,   -91,   318,   254,   -91,   -91,   201,
     274,   -91,   203,   -91,   252,   256,   -91,   258,   259,   -91,
     250,   260,   -91,   322,   -91,   261,   -91,   328,   325,   332,
     329,    -4,   -91,   333,   -91,   337,   -91,   338,   335,   341,
     340,   342,   343,   346,   344,   347,   345,   351,   348,   352,
     349,   355,   353,   356,   354,   357,   358,   334,   311,   219,
     360,   361,   362,   -91,   -91,   -91,   -91,   -91,   -91,   -91,
     -91,   -91,   -91,   -91,   -91,   -91,   -91,   -91,   -91,   -91,
     205,   -91,   363,   -91,   364,   368,   275,   -91,   366,   -46,
     367,   -61,   369,   -91,   370,   -91,   371,   -91,   372,   -91,
     373,   -91,   374,   -91,   375,   -91,   376,   -91,   377,   -91,
     378,   -91,   383,   273,   -91,   359,   240,   -91,   -91,   -91,
      20,    83,   -91,   -91,   -91,   -91,   209,   -91,   306,   -91,
     -91,   379,   -91,   -91,   -91,   -91,   380,   -91,   -91,   189,
     -91,   -80,   -91,     5,   -91,    -1,   -91,   -77,   -91,   -20,
     -91,   -85,   -91,   -90,   -91,   -86,   -91,   169,   382,   268,
     -91,   -91,   389,   281,   365,   263,   317,   -91,   392,   -91,
     381,   -91,   320,   -91,   395,   -91,   384,   -91,    86,   -91,
     -91,   -91,   -91,   396,   397,   -91,   391,   -91,   394,   -91,
     -91,   399,   -91,   -91,   400,   -91,   -91,   401,   -91,   -91,
     -91,   -91,   -91,   -91,   -91,   -91,   -91,   -91,   -91,   -91,
     -91,   -91,   -91,   402,   -91,   -91,   385,   330,   404,   284,
     -91,   -91,   409,   283,   388,   -91,   -91,   408,   413,   386,
     -91,   410,   417,   387,   327,   -91,   418,   -91,   390,   -91,
      91,   393,   326,   419,   421,   425,   426,   427,   173,   221,
     224,   227,   428,   430,   -91,   282,   -91,   403,   307,   429,
     308,   -91,   -91,   431,   433,   -91,   432,   435,   -91,   -91,
     436,   439,   -91,   -91,   437,   443,   407,   398,   -91,   445,
     -91,   411,   -91,   -91,   -91,   405,   406,   412,   414,   415,
     350,   -91,   448,   449,   450,   -91,   -91,   -91,   -91,   -91,
     416,   -91,   451,   453,   454,   -91,   -91,   -91,   -91,   -91,
     420,   -91,   455,   456,   457,   -91,   -91,   -91,   -91,   -91,
     422,   -91,   458,   459,   460,   -91,   -91,   -91,   -91,   -91,
     315,   461,    90,   -91,   462,   438,   423,   -91,   434,   323,
     463,   -91,   -91,   464,   -91,   466,   -91,   468,   473,   -91,
     -91,   470,   475,   440,   -91,   -91,   -91,   -91,   -91,   -91,
     472,   474,   476,   -91,   477,   478,   479,   -91,   480,   481,
     482,   -91,   483,   484,   485,   -91,   486,   424,   490,   492,
     493,   494,   496,   497,   498,   -91,   -91,   -91,   -91,   -91,
     -91,   -91,   -91,   -91,   495,   502,   -91,   339,   503,   447,
     442,   -91,   150,   -91,   -91,   -91,   500,   -91,   501,   506,
     -91,   -91,   -91,   -91,   -91,   -91,   -91,   -91,   -91,   -91,
     -91,   -91,   -91,   -91,   -91,   452,   504,   507,   508,   511,
     512,   514,   516,   517,   519,   110,   -91,   520,   521,   -91,
     441,   -91,   -91,   -91,   -91,   -91,   522,   172,    43,   -91,
     -91,   -91,   -91,   -91,   -91,   -91,   -91,   -91,   523,   444,
     527,   529,   530,   531,   532,   533,   534,   -91,   -91,   -91,
     -91,   -91,   -91,   -91,   -91,   -91,   535,   537,   116,   -91,
     149,   -91,   -91,   -91,   -91,   446,   -91,   536,   538,   539,
     542,   -91,   -91,   -91,   -91,   -91,   -91,   170,   -91,   -91,
     471,   541,   543,   544,   545,   546,   547,   548,   -91,   549,
     465,   553,   555,   556,   557,   558,   559,   560,   -91,   -91,
     -91,   -91,   -91,   -91,   -91,   -91,   -91,   467,   -91,   561,
     562,   563,   564,   565,   566,   -91,   -91,   -91,   -91,   -91,
     -91,   -91,   -91,   127,   -91,   567,   569,   571,   572,   -91,
     -91,   -91,   -30,    69,   -91,   -91,   -91,   -91,   -91,   -91,
     -91,   -91,   164,   -91,   -91,   505,   573,   575,   576,   577,
     578,   579,   580,   -91,   581,   582,   583,   584,   585,   586,
     469,   -91,   568,   570,   -91,   -91,   -91,   -91,   -91,   -91,
     -91,   -91,   153,   -91,   -91,   -91,   488,   -91,   591,   593,
     594,   595,   -91,   -91,   -91,   -91,   -91,   -91,   -91,   -91,
     -91,     3,    79,   -91,   -91,   -91,   -91,   -91,   -91,   -91,
     -91,   -91,   -91,   -91,   -91,   -91,   -91,   -91,   592,   596,
     487,   -91,   597,   598,   -91,   -91,   -91,   -91,   158,   -91,
     599,   600,   601,   602,   160,   -91,   -91,   -91,   489,   -91,
     607,   608,   609,   612,   -91,   -91,   -91,   -91,   -91,   -91,
     -91,   -91,   -91,   610,   611,   491,   -91,   613,   617,   -91,
     -91,   -91,   -91,   -91,   -91,   -91,   -91,   499,   -91,   618,
     619,   -91,   -91,   -91,   -91,   166,   -91,   620,   621,   623,
     624,   -91,   -91,   -91,   625,   626,   -91,   627,   628,   509,
     -91,   622,   633,   -91,   -91,   -91,   -91,   -91,   -91,   -91,
     -91,   -91,   -91,   -91,   -91,   -91,   630,   631,   -91,   -91
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
     -91,   -91,   -91,   -91,   -91,   -91,   -91,   -91
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint16 yytable[] =
{
     306,   245,   171,   165,   226,   149,   147,    71,   143,   426,
     218,   145,   135,   429,   423,   351,   141,   408,     6,     7,
     417,   137,   409,   125,   427,   172,   155,   424,   386,   387,
     430,   418,   107,   355,    72,     1,   356,   108,    73,   173,
      74,   174,    75,   175,    76,   176,   352,   177,   126,     4,
      94,   705,   706,   178,    95,   179,   388,   180,     5,   181,
     127,   182,     8,   183,   136,   184,   219,   185,   144,   186,
     148,   150,   227,   146,   142,   138,   156,   816,   817,   420,
     707,   708,   166,   246,   709,   710,   307,   868,   869,    12,
     421,   392,   393,    13,   454,   455,   414,    20,   597,   497,
     498,   813,   411,    26,   814,   415,   818,   819,    88,   412,
     820,   821,   598,   599,   600,   110,   870,   871,   679,   394,
     872,   873,   456,   601,   730,   139,   602,   499,   603,   115,
     604,   117,   680,   681,   682,   800,   801,   119,   731,   732,
     733,   121,   865,   140,   683,   866,   684,   151,   685,   152,
     686,   734,   735,   154,   736,   153,   737,   747,   748,   205,
     206,   850,   851,   167,   802,   803,   885,   886,   897,   898,
     157,   749,   750,   751,   919,   920,    15,    16,   207,   208,
     209,   510,   511,    18,    19,   752,   158,   753,   159,   754,
     852,   853,   512,   513,   514,   887,   888,   899,   900,    28,
      24,    25,   160,   921,   922,    86,    87,   161,    29,   163,
      30,   221,    31,   215,    32,   162,    33,   216,    34,   164,
      35,   217,    36,   220,    37,   228,    38,   231,    39,   520,
     521,   222,   530,   531,   243,   540,   541,    90,    91,   223,
     522,   523,   524,   532,   533,   534,   542,   543,   544,    92,
      93,    97,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   112,   113,   123,   124,   169,   170,   234,   235,   237,
     238,   240,   241,   251,   252,   286,   287,   290,   291,   342,
     343,   379,   380,   399,   400,   405,   406,   432,   433,   439,
     440,   480,   481,   224,   661,   662,   702,   703,   233,   236,
     769,   770,   828,   829,   239,   247,   242,   244,   249,   253,
     275,   255,   257,   259,   277,   261,   280,   263,   265,   281,
     267,   269,   271,   273,   282,   284,   285,   283,   289,   299,
     293,   302,   297,   303,   294,   304,   308,   305,   295,   296,
     310,   312,   298,   313,   314,   316,   335,   301,   315,   318,
     320,   317,   319,   321,   322,   324,   323,   325,   326,   328,
     330,   327,   329,   334,   332,   349,   331,   337,   338,   339,
     345,   347,   348,   350,   354,   384,   358,   360,   362,   364,
     366,   368,   370,   372,   374,   376,   378,   403,   404,   435,
     382,   436,   438,   446,   402,   447,   450,   442,   451,   463,
     461,   462,   464,   493,   553,   474,   444,   465,   466,   467,
     472,   476,   479,   477,   483,   485,   486,   489,   473,   448,
     490,   494,   452,   505,   504,   506,   487,   491,   495,   507,
     508,   509,   550,   551,   560,   595,   557,   554,   563,   562,
     555,   561,   565,   564,   566,   558,   567,   568,   571,   572,
     579,   580,   581,   582,   584,   503,   585,   586,   588,   589,
     590,   592,   593,   594,   619,   614,     0,   656,   596,   618,
     621,   623,   615,   624,   570,   625,   626,   627,   628,   631,
     629,   632,   658,   633,   634,   635,   636,   637,   638,   639,
     640,   641,   642,   646,   643,   647,   648,   649,   616,   650,
     651,   652,   653,   574,   575,   654,   657,   664,   665,   666,
     576,   670,   577,   578,   671,   672,   583,   659,   673,   674,
     587,   675,   591,   676,   697,   677,   678,   696,   669,   701,
     721,   718,   722,   723,   724,   725,   726,   727,     0,   765,
       0,   766,   767,   728,   729,   768,     0,   774,   775,   644,
     776,   777,   778,   779,   780,   781,   786,   783,   787,   788,
     789,   790,   791,   792,   794,   795,   796,   797,   798,   799,
       0,   848,   764,   849,   808,   719,   809,   699,   810,   811,
     834,   833,   835,   836,   837,   838,   839,   840,   841,   842,
     843,   844,   845,   846,   860,   847,   861,   862,   863,   880,
     883,   884,     0,   881,   784,     0,   893,   894,   895,   896,
     907,   908,   909,   793,   859,   910,   914,   911,   912,   882,
     915,   917,   918,   913,     0,   936,     0,   927,   928,   906,
     929,   930,   931,   932,   933,   934,   937,   938,   939,   916,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   935
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
       9,    66,     8,     9,     3,     8,     9,     8,     9,    68,
      19,    20,    21,    19,    20,    21,    19,    20,    21,     8,
       9,     8,     9,     8,     9,     8,     9,     8,     9,     8,
       9,     8,     9,     8,     9,     8,     9,     5,     6,     5,
       6,     5,     6,     8,     9,    74,    75,    74,    75,    74,
      75,     8,     9,    74,    75,    96,    97,   118,   119,     8,
       9,     8,     9,    70,   144,   145,   124,   125,     7,     7,
     130,   131,   138,   139,     7,    15,    84,     8,    39,    16,
      25,    17,    17,    17,   121,    17,     3,    17,    17,     3,
      18,    18,    18,    18,     3,     7,    72,    60,    54,     7,
      78,     3,    82,     8,    78,     3,     3,     8,    80,    80,
       3,     3,    82,     8,     3,     3,   127,    86,     8,     3,
       3,     8,     8,     8,     3,     3,     8,     8,     3,     3,
       3,     8,     8,    52,    30,    90,     8,     7,     7,     7,
       7,     7,     4,     7,     7,   135,     7,     7,     7,     7,
       7,     7,     7,     7,     7,     7,     3,     8,     8,     7,
      31,   123,     3,    76,    88,     3,    76,    32,     3,     8,
       4,     4,     8,    76,   122,    75,   143,     8,     8,     8,
       8,     7,     3,   129,    26,     7,     3,     7,    33,    38,
       3,     3,    38,     4,    98,     4,    40,    40,    38,     4,
       4,     4,     4,     3,     3,   120,     7,    34,     3,     7,
     133,     8,     3,     7,     7,   137,     3,    40,     3,    38,
     100,     3,     3,     3,     3,    62,     3,     3,     3,     3,
       3,     3,     3,     3,   141,     3,    -1,   128,     7,    35,
       7,     7,    34,     7,    76,     7,     3,     7,     3,     7,
      40,     7,    35,     7,     7,     7,     7,     7,     7,     7,
       7,     7,     7,     3,     8,     3,     3,     3,    75,     3,
       3,     3,     7,    98,    98,     3,     3,     7,     7,     3,
      98,     7,    98,    98,     7,     7,   100,    75,     7,     7,
     100,     7,   100,     7,     3,     8,     7,     7,    76,     7,
       3,     8,     3,     3,     3,     3,     3,     3,    -1,     3,
      -1,     3,     3,     8,     7,     3,    -1,    76,     7,   125,
       7,     7,     7,     7,     7,     7,     3,     8,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
      -1,     3,   126,     3,     7,   131,     7,   136,     7,     7,
       7,    76,     7,     7,     7,     7,     7,     7,     7,     7,
       7,     7,     7,     7,     3,   126,     3,     3,     3,     7,
       3,     3,    -1,     7,   139,    -1,     7,     7,     7,     7,
       3,     3,     3,   146,   126,     3,     3,     7,     7,   132,
       3,     3,     3,   132,    -1,     3,    -1,     7,     7,   140,
       7,     7,     7,     7,     7,     7,     3,     7,     7,   140,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   140
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,    10,   149,   150,    11,     0,     8,     9,    43,   151,
     152,   153,    12,    45,   201,     8,     9,   154,     8,     9,
      47,   223,   155,   202,     8,     9,    49,   239,    44,    53,
      55,    57,    59,    61,    63,    65,    67,    69,    71,    73,
     156,   157,   158,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     191,    46,    73,    77,    79,    81,    83,   203,   204,   206,
     208,   210,   211,   212,   213,   224,     8,     9,    51,   329,
       8,     9,     8,     9,     9,    13,   170,     8,     9,     8,
       9,     8,     9,     8,     9,     8,     9,     9,    14,   189,
      15,   192,     8,     9,   159,    15,   214,    39,   205,    39,
     207,    39,   209,     8,     9,    48,    73,    85,   225,   226,
     227,   228,   229,   240,   330,     4,    56,     4,    58,     3,
       8,     4,    62,     4,    64,     4,    66,     4,    68,     4,
      70,     3,     8,     3,     8,     4,    54,     3,     8,     3,
       8,     3,     8,     3,     8,     5,    84,    15,   230,     8,
       9,    50,    73,    87,    89,    91,    93,    95,   101,   103,
     105,   107,   109,   111,   113,   115,   117,   241,   242,   244,
     245,   246,   247,   251,   255,   259,   263,   267,   277,   287,
     297,   307,   311,   315,   319,     8,     9,    27,    28,    29,
     331,   332,   333,   334,   335,    56,    58,     7,     4,    60,
      62,    64,    66,    68,    70,   190,     4,    72,     7,   193,
     160,     7,   215,     7,     5,     6,     7,     5,     6,     7,
       5,     6,    84,     3,     8,     4,    86,    15,   320,    39,
     243,     8,     9,    16,   248,    17,   252,    17,   256,    17,
     260,    17,   264,    17,   312,    17,   308,    18,   268,    18,
     278,    18,   288,    18,   298,    25,   316,   121,   336,   337,
       3,     3,     3,    60,     7,    72,    74,    75,   194,    54,
      74,    75,   216,    78,    78,    80,    80,    82,    82,     7,
     231,    86,     3,     8,     3,     8,     4,    90,     3,   249,
       3,   253,     3,     8,     3,     8,     3,     8,     3,     8,
       3,     8,     3,     8,     3,     8,     3,     8,     3,     8,
       3,     8,    30,   338,    52,   127,   367,     7,     7,     7,
     195,   217,    74,    75,   232,     7,   321,     7,     4,    90,
       7,    61,    92,   250,     7,    94,    97,   254,     7,   257,
       7,   261,     7,   265,     7,   313,     7,   309,     7,   269,
       7,   279,     7,   289,     7,   299,     7,   317,     3,     8,
       9,   339,    31,   368,   135,   405,     8,     9,    36,   196,
     197,   200,     8,     9,    36,   218,   219,   222,   233,    74,
      75,   322,    88,     8,     8,    96,    97,   258,    97,   102,
     262,    97,   104,   266,    97,   106,   314,    97,   108,   310,
      99,   110,   270,    99,   112,   280,    99,   114,   290,    99,
     116,   300,   118,   119,   318,     7,   123,   340,     3,     8,
       9,   369,    32,   406,   143,   443,    76,     3,    38,   198,
      76,     3,    38,   220,     8,     9,    36,   234,   235,   238,
     323,     4,     4,     8,     8,     8,     8,     8,   271,   281,
     291,   301,     8,    33,    75,   348,     7,   129,   370,     3,
       8,     9,   407,    26,   444,     7,     3,    40,   199,     7,
       3,    40,   221,    76,     3,    38,   236,     8,     9,    36,
     324,   325,   328,    62,    98,     4,     4,     4,     4,     4,
       8,     9,    19,    20,    21,   272,   273,   274,   275,   276,
       8,     9,    19,    20,    21,   282,   283,   284,   285,   286,
       8,     9,    19,    20,    21,   292,   293,   294,   295,   296,
       8,     9,    19,    20,    21,   302,   303,   304,   305,   306,
       4,     3,   349,   122,    34,   133,   378,     7,   137,   408,
       3,     8,     7,     3,     7,     3,     7,     3,    40,   237,
      76,     3,    38,   326,    98,    98,    98,    98,    98,   100,
       3,     3,     3,   100,     3,     3,     3,   100,     3,     3,
       3,   100,     3,     3,     3,   120,     7,     8,    22,    23,
      24,    33,    36,    38,    40,   350,   351,   352,   353,   354,
     355,   356,   357,   358,     3,    34,    75,   386,    35,   141,
     416,     7,   445,     7,     7,     7,     3,     7,     3,    40,
     327,     7,     7,     7,     7,     7,     7,     7,     7,     7,
       7,     7,     7,     8,   125,   359,     3,     3,     3,     3,
       3,     3,     3,     7,     3,   387,   128,     3,    35,    75,
     424,   144,   145,   446,     7,     7,     3,   341,   360,    76,
       7,     7,     7,     7,     7,     7,     7,     8,     7,     8,
      22,    23,    24,    34,    36,    38,    40,   388,   389,   390,
     391,   392,   393,   394,   395,   396,     7,     3,   425,   136,
     447,     7,   124,   125,   342,     8,     9,    37,    38,    41,
      42,   361,   362,   363,   364,   365,   366,   371,     8,   131,
     397,     3,     3,     3,     3,     3,     3,     3,     8,     7,
       8,    22,    23,    24,    35,    36,    38,    40,   426,   427,
     428,   429,   430,   431,   432,   433,   434,     8,     9,    22,
      23,    24,    36,    38,    40,   448,   449,   450,   451,   452,
     453,   454,   455,   343,   126,     3,     3,     3,     3,   130,
     131,   372,   379,   398,    76,     7,     7,     7,     7,     7,
       7,     7,   409,     8,   139,   435,     3,     3,     3,     3,
       3,     3,     3,   146,     3,     3,     3,     3,     3,     3,
       8,     9,    37,    38,   344,   345,   346,   347,     7,     7,
       7,     7,   373,   131,   134,   380,     8,     9,    37,    38,
      41,    42,   399,   400,   401,   402,   403,   404,   138,   139,
     410,   417,   436,    76,     7,     7,     7,     7,     7,     7,
       7,     7,     7,     7,     7,     7,     7,   126,     3,     3,
       8,     9,    37,    38,   374,   375,   376,   377,   381,   126,
       3,     3,     3,     3,   411,   139,   142,   418,     8,     9,
      37,    38,    41,    42,   437,   438,   439,   440,   441,   442,
       7,     7,   132,     3,     3,     8,     9,    37,    38,   382,
     383,   384,   385,     7,     7,     7,     7,     8,     9,    37,
      38,   412,   413,   414,   415,   419,   140,     3,     3,     3,
       3,     7,     7,   132,     3,     3,   140,     3,     3,     8,
       9,    37,    38,   420,   421,   422,   423,     7,     7,     7,
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
osoption->general->serviceURI = (yyvsp[(2) - (2)].sval);
printf("%s","\n$2 contains: ");printf("%s",(yyvsp[(2) - (2)].sval));printf("%s","\n");
}
    break;

  case 34:

    {
}
    break;

  case 35:

    {
}
    break;

  case 39:

    {
}
    break;

  case 40:

    {
}
    break;

  case 44:

    {
}
    break;

  case 45:

    {
}
    break;

  case 47:

    {
}
    break;

  case 51:

    {
}
    break;

  case 52:

    {
}
    break;

  case 56:

    {
}
    break;

  case 57:

    {
}
    break;

  case 61:

    {
}
    break;

  case 62:

    {
}
    break;

  case 66:

    {
}
    break;

  case 67:

    {
}
    break;

  case 71:

    {
}
    break;

  case 72:

    {
}
    break;

  case 76:

    {
}
    break;

  case 77:

    {
}
    break;

  case 79:

    {
printf("TRANSSPORT ATTRIBUTE TEXT =  %s",(yyvsp[(2) - (2)].sval));printf("%s","\n");
//delete($2);
}
    break;

  case 82:

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

  case 95:

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

  case 117:

    {
}
    break;

  case 121:

    {
}
    break;

  case 122:

    {
}
    break;

  case 124:

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

  case 137:

    {
}
    break;

  case 148:

    {
}
    break;

  case 149:

    {
}
    break;

  case 151:

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

  case 164:

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

  case 191:

    {
}
    break;

  case 192:

    {
}
    break;

  case 194:

    {
}
    break;

  case 197:

    {
}
    break;

  case 199:

    {
}
    break;

  case 202:

    {
}
    break;

  case 204:

    {
}
    break;

  case 207:

    {
}
    break;

  case 209:

    {
}
    break;

  case 212:

    {
}
    break;

  case 214:

    {
}
    break;

  case 217:

    {
}
    break;

  case 219:

    {
}
    break;

  case 222:

    {
}
    break;

  case 228:

    {
}
    break;

  case 229:

    {
}
    break;

  case 230:

    {
}
    break;

  case 234:

    {
}
    break;

  case 237:

    {
}
    break;

  case 243:

    {
}
    break;

  case 244:

    {
}
    break;

  case 245:

    {
}
    break;

  case 249:

    {
}
    break;

  case 252:

    {
}
    break;

  case 258:

    {
}
    break;

  case 259:

    {
}
    break;

  case 260:

    {
}
    break;

  case 264:

    {
}
    break;

  case 267:

    {
}
    break;

  case 273:

    {
}
    break;

  case 274:

    {
}
    break;

  case 275:

    {
}
    break;

  case 279:

    {
}
    break;

  case 282:

    {
}
    break;

  case 284:

    {
}
    break;

  case 287:

    {
}
    break;

  case 289:

    {
}
    break;

  case 292:

    {
}
    break;

  case 294:

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

  case 307:

    {
}
    break;

  case 315:

    {
}
    break;

  case 316:

    {
}
    break;

  case 317:

    {
}
    break;

  case 324:

    {
}
    break;

  case 336:

    {
}
    break;

  case 337:

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

  case 356:

    {
}
    break;

  case 357:

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

  case 368:

    {
}
    break;

  case 369:

    {
}
    break;

  case 375:

    {
}
    break;

  case 387:

    {
}
    break;

  case 388:

    {
}
    break;

  case 400:

    {
}
    break;

  case 401:

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

  case 420:

    {
}
    break;

  case 421:

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

  case 432:

    {
}
    break;

  case 433:

    {
}
    break;

  case 439:

    {
}
    break;

  case 451:

    {
}
    break;

  case 452:

    {
}
    break;

  case 464:

    {
}
    break;

  case 465:

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

  case 484:

    {
}
    break;

  case 485:

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

  case 496:

    {
}
    break;

  case 497:

    {
}
    break;

  case 502:

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

  case 518:

    {
}
    break;

  case 519:

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


