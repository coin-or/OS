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
#define YYLAST   648

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  148
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  312
/* YYNRULES -- Number of rules.  */
#define YYNRULES  525
/* YYNRULES -- Number of states.  */
#define YYNSTATES  943

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
      99,   102,   103,   108,   111,   113,   115,   120,   121,   122,
     127,   128,   130,   132,   134,   137,   141,   146,   148,   150,
     153,   157,   162,   164,   166,   169,   173,   178,   180,   182,
     185,   189,   194,   196,   198,   201,   205,   210,   212,   214,
     217,   222,   228,   229,   230,   235,   241,   245,   246,   249,
     253,   254,   257,   261,   265,   266,   270,   271,   275,   277,
     280,   281,   286,   289,   290,   293,   295,   297,   299,   301,
     303,   309,   315,   316,   320,   326,   332,   333,   337,   343,
     349,   350,   354,   356,   358,   361,   365,   370,   376,   380,
     381,   384,   388,   389,   392,   396,   400,   401,   405,   406,
     410,   412,   415,   416,   421,   424,   425,   428,   430,   432,
     434,   436,   439,   443,   448,   454,   458,   459,   462,   466,
     467,   470,   474,   478,   479,   483,   484,   488,   490,   493,
     494,   499,   502,   503,   506,   508,   510,   512,   514,   516,
     518,   520,   522,   524,   526,   528,   530,   532,   534,   536,
     542,   543,   547,   549,   551,   554,   558,   563,   568,   572,
     573,   576,   581,   586,   590,   591,   594,   599,   605,   609,
     610,   613,   618,   624,   628,   629,   632,   637,   643,   647,
     648,   651,   656,   662,   666,   667,   670,   674,   675,   678,
     680,   682,   684,   688,   692,   696,   699,   701,   707,   711,
     712,   715,   719,   720,   723,   725,   727,   729,   733,   737,
     741,   744,   746,   752,   756,   757,   760,   764,   765,   768,
     770,   772,   774,   778,   782,   786,   789,   791,   797,   801,
     802,   805,   809,   810,   813,   815,   817,   819,   823,   827,
     831,   834,   836,   842,   846,   847,   850,   855,   861,   865,
     866,   869,   874,   880,   884,   885,   888,   893,   899,   903,
     904,   907,   911,   912,   915,   919,   923,   924,   928,   929,
     933,   935,   938,   939,   943,   944,   947,   949,   951,   953,
     957,   961,   965,   969,   971,   976,   977,   981,   982,   986,
     991,   993,   994,  1002,  1003,  1006,  1010,  1011,  1014,  1016,
    1018,  1022,  1026,  1029,  1031,  1032,  1036,  1037,  1040,  1042,
    1044,  1046,  1048,  1050,  1052,  1054,  1058,  1062,  1066,  1070,
    1074,  1078,  1082,  1086,  1090,  1091,  1094,  1096,  1098,  1100,
    1102,  1106,  1110,  1114,  1118,  1121,  1123,  1124,  1128,  1129,
    1133,  1139,  1141,  1142,  1150,  1151,  1154,  1158,  1159,  1162,
    1164,  1166,  1170,  1174,  1177,  1179,  1180,  1188,  1189,  1192,
    1196,  1197,  1200,  1202,  1204,  1208,  1212,  1215,  1217,  1218,
    1222,  1223,  1226,  1228,  1230,  1232,  1234,  1236,  1238,  1240,
    1244,  1248,  1252,  1256,  1260,  1264,  1268,  1272,  1276,  1277,
    1280,  1282,  1284,  1286,  1288,  1292,  1296,  1300,  1304,  1307,
    1309,  1310,  1314,  1315,  1319,  1325,  1327,  1328,  1336,  1337,
    1340,  1344,  1345,  1348,  1350,  1352,  1356,  1360,  1363,  1365,
    1366,  1374,  1375,  1378,  1382,  1383,  1386,  1388,  1390,  1394,
    1398,  1401,  1403,  1404,  1408,  1409,  1412,  1414,  1416,  1418,
    1420,  1422,  1424,  1426,  1430,  1434,  1438,  1442,  1446,  1450,
    1454,  1458,  1462,  1463,  1466,  1468,  1470,  1472,  1474,  1478,
    1482,  1486,  1490,  1493,  1495,  1496,  1502,  1506,  1507,  1510,
    1514,  1515,  1518,  1520,  1522,  1524,  1526,  1528,  1530,  1534,
    1538,  1542,  1546,  1550,  1554,  1557
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     149,     0,    -1,   150,     8,   151,    12,    -1,   150,     9,
      -1,    10,    -1,    10,    11,    -1,   152,   205,   227,   243,
     333,    -1,    -1,   153,   154,    -1,    43,    -1,     8,   155,
      44,    -1,     9,    -1,    -1,   155,   156,    -1,   157,    -1,
     161,    -1,   165,    -1,   169,    -1,   175,    -1,   178,    -1,
     181,    -1,   184,    -1,   187,    -1,   190,    -1,   195,    -1,
     158,   159,    -1,    53,    -1,     9,    -1,     8,    54,    -1,
      -1,     8,     4,   160,    54,    -1,   162,   163,    -1,    55,
      -1,     9,    -1,     8,    56,    -1,    -1,     8,     4,   164,
      56,    -1,   166,   167,    -1,    57,    -1,     9,    -1,     8,
      58,    -1,    -1,     8,     4,   168,    58,    -1,   170,   171,
      -1,    59,    -1,     9,    -1,   172,     8,   174,    60,    -1,
      -1,    -1,    13,     3,   173,     7,    -1,    -1,     4,    -1,
     176,    -1,   177,    -1,    61,     9,    -1,    61,     8,    62,
      -1,    61,     8,     4,    62,    -1,   179,    -1,   180,    -1,
      63,     9,    -1,    63,     8,    64,    -1,    63,     8,     4,
      64,    -1,   182,    -1,   183,    -1,    65,     9,    -1,    65,
       8,    66,    -1,    65,     8,     4,    66,    -1,   185,    -1,
     186,    -1,    67,     9,    -1,    67,     8,    68,    -1,    67,
       8,     4,    68,    -1,   188,    -1,   189,    -1,    69,     9,
      -1,    69,     8,    70,    -1,    69,     8,     4,    70,    -1,
     191,    -1,   192,    -1,    71,     9,    -1,    71,   193,     8,
      72,    -1,    71,   193,     8,     4,    72,    -1,    -1,    -1,
      14,     3,   194,     7,    -1,    73,   196,     8,   197,    74,
      -1,    15,     3,     7,    -1,    -1,   197,   198,    -1,    75,
     199,   204,    -1,    -1,   199,   200,    -1,   201,   202,   203,
      -1,    36,     3,     7,    -1,    -1,    38,     3,     7,    -1,
      -1,    40,     3,     7,    -1,     9,    -1,     8,    76,    -1,
      -1,    45,     8,   206,    46,    -1,    45,     9,    -1,    -1,
     206,   207,    -1,   208,    -1,   210,    -1,   212,    -1,   214,
      -1,   217,    -1,    77,   209,     8,     6,    78,    -1,    77,
     209,     8,     5,    78,    -1,    -1,    39,     3,     7,    -1,
      79,   211,     8,     6,    80,    -1,    79,   211,     8,     5,
      80,    -1,    -1,    39,     3,     7,    -1,    81,   213,     8,
       6,    82,    -1,    81,   213,     8,     5,    82,    -1,    -1,
      39,     3,     7,    -1,   215,    -1,   216,    -1,    83,     9,
      -1,    83,     8,    84,    -1,    83,     8,     5,    84,    -1,
      73,   218,     8,   219,    74,    -1,    15,     3,     7,    -1,
      -1,   219,   220,    -1,    75,   221,   226,    -1,    -1,   221,
     222,    -1,   223,   224,   225,    -1,    36,     3,     7,    -1,
      -1,    38,     3,     7,    -1,    -1,    40,     3,     7,    -1,
       9,    -1,     8,    76,    -1,    -1,    47,     8,   228,    48,
      -1,    47,     9,    -1,    -1,   228,   229,    -1,   230,    -1,
     233,    -1,   231,    -1,   232,    -1,    85,     9,    -1,    85,
       8,    86,    -1,    85,     8,     4,    86,    -1,    73,   234,
       8,   235,    74,    -1,    15,     3,     7,    -1,    -1,   235,
     236,    -1,    75,   237,   242,    -1,    -1,   237,   238,    -1,
     239,   240,   241,    -1,    36,     3,     7,    -1,    -1,    38,
       3,     7,    -1,    -1,    40,     3,     7,    -1,     9,    -1,
       8,    76,    -1,    -1,    49,     8,   244,    50,    -1,    49,
       9,    -1,    -1,   244,   245,    -1,   246,    -1,   248,    -1,
     251,    -1,   255,    -1,   259,    -1,   263,    -1,   267,    -1,
     271,    -1,   281,    -1,   291,    -1,   301,    -1,   311,    -1,
     315,    -1,   319,    -1,   323,    -1,    87,   247,     8,     4,
      88,    -1,    -1,    39,     3,     7,    -1,   249,    -1,   250,
      -1,    89,     9,    -1,    89,     8,    90,    -1,    89,     8,
       4,    90,    -1,    91,   252,   253,    92,    -1,    16,     3,
       7,    -1,    -1,   253,   254,    -1,    61,     8,     4,    62,
      -1,    93,   256,   257,    94,    -1,    17,     3,     7,    -1,
      -1,   257,   258,    -1,    97,     8,     4,    98,    -1,    95,
     260,     8,   261,    96,    -1,    17,     3,     7,    -1,    -1,
     261,   262,    -1,    97,     8,     4,    98,    -1,   101,   264,
       8,   265,   102,    -1,    17,     3,     7,    -1,    -1,   265,
     266,    -1,    97,     8,     4,    98,    -1,   103,   268,     8,
     269,   104,    -1,    17,     3,     7,    -1,    -1,   269,   270,
      -1,    97,     8,     4,    98,    -1,   109,   272,     8,   273,
     110,    -1,    18,     3,     7,    -1,    -1,   273,   274,    -1,
      99,   275,   280,    -1,    -1,   275,   276,    -1,   277,    -1,
     278,    -1,   279,    -1,    19,     3,     7,    -1,    20,     3,
       7,    -1,    21,     3,     7,    -1,     8,   100,    -1,     9,
      -1,   111,   282,     8,   283,   112,    -1,    18,     3,     7,
      -1,    -1,   283,   284,    -1,    99,   285,   290,    -1,    -1,
     285,   286,    -1,   287,    -1,   288,    -1,   289,    -1,    19,
       3,     7,    -1,    20,     3,     7,    -1,    21,     3,     7,
      -1,     8,   100,    -1,     9,    -1,   113,   292,     8,   293,
     114,    -1,    18,     3,     7,    -1,    -1,   293,   294,    -1,
      99,   295,   300,    -1,    -1,   295,   296,    -1,   297,    -1,
     298,    -1,   299,    -1,    19,     3,     7,    -1,    20,     3,
       7,    -1,    21,     3,     7,    -1,     8,   100,    -1,     9,
      -1,   115,   302,     8,   303,   116,    -1,    18,     3,     7,
      -1,    -1,   303,   304,    -1,    99,   305,   310,    -1,    -1,
     305,   306,    -1,   307,    -1,   308,    -1,   309,    -1,    19,
       3,     7,    -1,    20,     3,     7,    -1,    21,     3,     7,
      -1,     8,   100,    -1,     9,    -1,   107,   312,     8,   313,
     108,    -1,    17,     3,     7,    -1,    -1,   313,   314,    -1,
      97,     8,     4,    98,    -1,   105,   316,     8,   317,   106,
      -1,    17,     3,     7,    -1,    -1,   317,   318,    -1,    97,
       8,     4,    98,    -1,   117,   320,     8,   321,   118,    -1,
      25,     3,     7,    -1,    -1,   321,   322,    -1,   119,     8,
       4,   120,    -1,    73,   324,     8,   325,    74,    -1,    15,
       3,     7,    -1,    -1,   325,   326,    -1,    75,   327,   332,
      -1,    -1,   327,   328,    -1,   329,   330,   331,    -1,    36,
       3,     7,    -1,    -1,    38,     3,     7,    -1,    -1,    40,
       3,     7,    -1,     9,    -1,     8,    76,    -1,    -1,    51,
     334,   339,    -1,    -1,   334,   335,    -1,   336,    -1,   337,
      -1,   338,    -1,    27,     3,     7,    -1,    29,     3,     7,
      -1,    28,     3,     7,    -1,     8,   340,    52,    -1,     9,
      -1,   341,   371,   409,   447,    -1,    -1,   121,   342,   343,
      -1,    -1,    30,     3,     7,    -1,     8,   344,   352,   122,
      -1,     9,    -1,    -1,   123,    33,     3,     7,     8,   345,
     124,    -1,    -1,   345,   346,    -1,   125,   347,   351,    -1,
      -1,   347,   348,    -1,   349,    -1,   350,    -1,    37,     3,
       7,    -1,    38,     3,     7,    -1,     8,   126,    -1,     9,
      -1,    -1,    75,   353,   362,    -1,    -1,   353,   354,    -1,
     355,    -1,   356,    -1,   357,    -1,   358,    -1,   359,    -1,
     360,    -1,   361,    -1,    33,     3,     7,    -1,    36,     3,
       7,    -1,    38,     3,     7,    -1,    22,     3,     7,    -1,
      23,     3,     7,    -1,    24,     3,     7,    -1,    40,     3,
       7,    -1,     8,   363,    76,    -1,   125,   364,   370,    -1,
      -1,   364,   365,    -1,   366,    -1,   367,    -1,   368,    -1,
     369,    -1,    37,     3,     7,    -1,    38,     3,     7,    -1,
      41,     3,     7,    -1,    42,     3,     7,    -1,     8,   126,
      -1,     9,    -1,    -1,   127,   372,   373,    -1,    -1,    31,
       3,     7,    -1,     8,   374,   382,   390,   128,    -1,     9,
      -1,    -1,   129,    34,     3,     7,     8,   375,   130,    -1,
      -1,   375,   376,    -1,   131,   377,   381,    -1,    -1,   377,
     378,    -1,   379,    -1,   380,    -1,    37,     3,     7,    -1,
      38,     3,     7,    -1,     8,   132,    -1,     9,    -1,    -1,
     133,    34,     3,     7,     8,   383,   134,    -1,    -1,   383,
     384,    -1,   131,   385,   389,    -1,    -1,   385,   386,    -1,
     387,    -1,   388,    -1,    37,     3,     7,    -1,    38,     3,
       7,    -1,     8,   132,    -1,     9,    -1,    -1,    75,   391,
     400,    -1,    -1,   391,   392,    -1,   393,    -1,   394,    -1,
     395,    -1,   396,    -1,   397,    -1,   398,    -1,   399,    -1,
      34,     3,     7,    -1,    36,     3,     7,    -1,    38,     3,
       7,    -1,    22,     3,     7,    -1,    23,     3,     7,    -1,
      24,     3,     7,    -1,    40,     3,     7,    -1,     8,   401,
      76,    -1,   131,   402,   408,    -1,    -1,   402,   403,    -1,
     404,    -1,   405,    -1,   406,    -1,   407,    -1,    37,     3,
       7,    -1,    38,     3,     7,    -1,    41,     3,     7,    -1,
      42,     3,     7,    -1,     8,   126,    -1,     9,    -1,    -1,
     135,   410,   411,    -1,    -1,    32,     3,     7,    -1,     8,
     412,   420,   428,   136,    -1,     9,    -1,    -1,   137,    35,
       3,     7,     8,   413,   138,    -1,    -1,   413,   414,    -1,
     139,   415,   419,    -1,    -1,   415,   416,    -1,   417,    -1,
     418,    -1,    37,     3,     7,    -1,    38,     3,     7,    -1,
       8,   140,    -1,     9,    -1,    -1,   141,    35,     3,     7,
       8,   421,   142,    -1,    -1,   421,   422,    -1,   139,   423,
     427,    -1,    -1,   423,   424,    -1,   425,    -1,   426,    -1,
      37,     3,     7,    -1,    38,     3,     7,    -1,     8,   140,
      -1,     9,    -1,    -1,    75,   429,   438,    -1,    -1,   429,
     430,    -1,   431,    -1,   432,    -1,   433,    -1,   434,    -1,
     435,    -1,   436,    -1,   437,    -1,    35,     3,     7,    -1,
      36,     3,     7,    -1,    38,     3,     7,    -1,    22,     3,
       7,    -1,    23,     3,     7,    -1,    24,     3,     7,    -1,
      40,     3,     7,    -1,     8,   439,    76,    -1,   139,   440,
     446,    -1,    -1,   440,   441,    -1,   442,    -1,   443,    -1,
     444,    -1,   445,    -1,    37,     3,     7,    -1,    38,     3,
       7,    -1,    41,     3,     7,    -1,    42,     3,     7,    -1,
       8,   140,    -1,     9,    -1,    -1,   143,   448,     8,   449,
     144,    -1,    26,     3,     7,    -1,    -1,   449,   450,    -1,
     145,   451,   459,    -1,    -1,   451,   452,    -1,   453,    -1,
     454,    -1,   455,    -1,   456,    -1,   457,    -1,   458,    -1,
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
     198,   199,   199,   202,   204,   214,   215,   217,   217,   217,
     219,   219,   222,   222,   224,   225,   229,   234,   234,   236,
     237,   241,   246,   246,   248,   249,   253,   258,   258,   260,
     261,   265,   270,   270,   272,   273,   277,   281,   281,   283,
     284,   288,   292,   293,   292,   299,   301,   305,   305,   307,
     309,   309,   311,   313,   317,   317,   321,   321,   325,   325,
     330,   331,   332,   334,   334,   336,   336,   336,   336,   336,
     338,   339,   343,   343,   347,   348,   352,   352,   356,   357,
     361,   361,   365,   365,   367,   368,   372,   376,   378,   382,
     382,   384,   386,   386,   388,   390,   394,   394,   398,   398,
     402,   402,   407,   408,   409,   411,   411,   413,   413,   415,
     415,   417,   418,   422,   427,   429,   433,   433,   435,   437,
     437,   439,   441,   445,   445,   449,   449,   453,   453,   458,
     459,   460,   462,   462,   464,   464,   464,   464,   464,   465,
     465,   465,   465,   465,   466,   466,   466,   466,   466,   468,
     472,   472,   476,   476,   478,   479,   483,   487,   489,   493,
     493,   496,   500,   503,   507,   507,   509,   513,   516,   520,
     520,   522,   526,   529,   533,   533,   535,   539,   542,   546,
     546,   548,   552,   555,   559,   559,   561,   565,   565,   567,
     567,   567,   569,   573,   577,   581,   581,   584,   587,   591,
     591,   593,   597,   597,   599,   599,   599,   601,   605,   609,
     613,   613,   616,   619,   623,   623,   625,   629,   629,   631,
     631,   631,   633,   637,   641,   645,   645,   648,   651,   655,
     655,   657,   661,   661,   663,   663,   663,   665,   669,   673,
     677,   677,   681,   684,   688,   688,   690,   694,   697,   701,
     701,   703,   708,   711,   715,   715,   717,   722,   724,   728,
     728,   730,   732,   732,   734,   736,   740,   740,   744,   744,
     748,   748,   753,   753,   755,   755,   757,   757,   757,   759,
     763,   767,   771,   771,   773,   775,   775,   777,   777,   781,
     782,   784,   784,   787,   787,   789,   791,   791,   793,   793,
     795,   799,   803,   803,   806,   806,   808,   808,   811,   812,
     813,   814,   815,   816,   817,   819,   823,   827,   831,   835,
     839,   843,   848,   850,   852,   852,   855,   856,   857,   858,
     860,   864,   868,   872,   876,   876,   878,   878,   880,   880,
     884,   886,   889,   889,   892,   892,   894,   896,   896,   898,
     898,   900,   904,   908,   908,   911,   911,   914,   914,   916,
     918,   918,   920,   920,   922,   926,   930,   930,   933,   933,
     935,   935,   938,   939,   940,   941,   942,   943,   944,   946,
     950,   954,   958,   962,   966,   970,   975,   977,   979,   979,
     982,   983,   984,   985,   987,   991,   995,   999,  1003,  1003,
    1005,  1005,  1007,  1007,  1011,  1013,  1015,  1015,  1018,  1018,
    1020,  1022,  1022,  1024,  1024,  1026,  1030,  1034,  1034,  1037,
    1037,  1040,  1040,  1042,  1044,  1044,  1046,  1046,  1048,  1052,
    1056,  1056,  1059,  1059,  1061,  1061,  1064,  1065,  1066,  1067,
    1068,  1069,  1070,  1072,  1076,  1080,  1084,  1088,  1092,  1096,
    1101,  1103,  1105,  1105,  1108,  1109,  1110,  1111,  1113,  1117,
    1121,  1125,  1129,  1129,  1132,  1132,  1134,  1138,  1138,  1140,
    1142,  1142,  1145,  1146,  1147,  1148,  1149,  1150,  1152,  1156,
    1160,  1164,  1168,  1172,  1177,  1177
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
  "instancelocationhead", "instancelocationbody", "locationtypeatt", "@4",
  "instancelocationtext", "jobid", "emptyjobid", "nonemptyjobid",
  "solvertoinvoke", "emptysolver", "nonemptysolver", "license",
  "emptylicense", "nonemptylicense", "username", "emptyusername",
  "nonemptyusername", "password", "emptypassword", "nonemptypassword",
  "contact", "emptycontact", "nonemptycontact", "transporttypeatt", "@5",
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
       0,   148,   149,   149,   150,   150,   151,   152,   152,   153,
     154,   154,   155,   155,   156,   156,   156,   156,   156,   156,
     156,   156,   156,   156,   156,   157,   158,   159,   159,   160,
     159,   161,   162,   163,   163,   164,   163,   165,   166,   167,
     167,   168,   167,   169,   170,   171,   171,   172,   173,   172,
     174,   174,   175,   175,   176,   176,   177,   178,   178,   179,
     179,   180,   181,   181,   182,   182,   183,   184,   184,   185,
     185,   186,   187,   187,   188,   188,   189,   190,   190,   191,
     191,   192,   193,   194,   193,   195,   196,   197,   197,   198,
     199,   199,   200,   201,   202,   202,   203,   203,   204,   204,
     205,   205,   205,   206,   206,   207,   207,   207,   207,   207,
     208,   208,   209,   209,   210,   210,   211,   211,   212,   212,
     213,   213,   214,   214,   215,   215,   216,   217,   218,   219,
     219,   220,   221,   221,   222,   223,   224,   224,   225,   225,
     226,   226,   227,   227,   227,   228,   228,   229,   229,   230,
     230,   231,   231,   232,   233,   234,   235,   235,   236,   237,
     237,   238,   239,   240,   240,   241,   241,   242,   242,   243,
     243,   243,   244,   244,   245,   245,   245,   245,   245,   245,
     245,   245,   245,   245,   245,   245,   245,   245,   245,   246,
     247,   247,   248,   248,   249,   249,   250,   251,   252,   253,
     253,   254,   255,   256,   257,   257,   258,   259,   260,   261,
     261,   262,   263,   264,   265,   265,   266,   267,   268,   269,
     269,   270,   271,   272,   273,   273,   274,   275,   275,   276,
     276,   276,   277,   278,   279,   280,   280,   281,   282,   283,
     283,   284,   285,   285,   286,   286,   286,   287,   288,   289,
     290,   290,   291,   292,   293,   293,   294,   295,   295,   296,
     296,   296,   297,   298,   299,   300,   300,   301,   302,   303,
     303,   304,   305,   305,   306,   306,   306,   307,   308,   309,
     310,   310,   311,   312,   313,   313,   314,   315,   316,   317,
     317,   318,   319,   320,   321,   321,   322,   323,   324,   325,
     325,   326,   327,   327,   328,   329,   330,   330,   331,   331,
     332,   332,   333,   333,   334,   334,   335,   335,   335,   336,
     337,   338,   339,   339,   340,   341,   341,   342,   342,   343,
     343,   344,   344,   345,   345,   346,   347,   347,   348,   348,
     349,   350,   351,   351,   352,   352,   353,   353,   354,   354,
     354,   354,   354,   354,   354,   355,   356,   357,   358,   359,
     360,   361,   362,   363,   364,   364,   365,   365,   365,   365,
     366,   367,   368,   369,   370,   370,   371,   371,   372,   372,
     373,   373,   374,   374,   375,   375,   376,   377,   377,   378,
     378,   379,   380,   381,   381,   382,   382,   383,   383,   384,
     385,   385,   386,   386,   387,   388,   389,   389,   390,   390,
     391,   391,   392,   392,   392,   392,   392,   392,   392,   393,
     394,   395,   396,   397,   398,   399,   400,   401,   402,   402,
     403,   403,   403,   403,   404,   405,   406,   407,   408,   408,
     409,   409,   410,   410,   411,   411,   412,   412,   413,   413,
     414,   415,   415,   416,   416,   417,   418,   419,   419,   420,
     420,   421,   421,   422,   423,   423,   424,   424,   425,   426,
     427,   427,   428,   428,   429,   429,   430,   430,   430,   430,
     430,   430,   430,   431,   432,   433,   434,   435,   436,   437,
     438,   439,   440,   440,   441,   441,   441,   441,   442,   443,
     444,   445,   446,   446,   447,   447,   448,   449,   449,   450,
     451,   451,   452,   452,   452,   452,   452,   452,   453,   454,
     455,   456,   457,   458,   459,   459
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     4,     2,     1,     2,     5,     0,     2,     1,
       3,     1,     0,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     2,     1,     1,     2,     0,
       4,     2,     1,     1,     2,     0,     4,     2,     1,     1,
       2,     0,     4,     2,     1,     1,     4,     0,     0,     4,
       0,     1,     1,     1,     2,     3,     4,     1,     1,     2,
       3,     4,     1,     1,     2,     3,     4,     1,     1,     2,
       3,     4,     1,     1,     2,     3,     4,     1,     1,     2,
       4,     5,     0,     0,     4,     5,     3,     0,     2,     3,
       0,     2,     3,     3,     0,     3,     0,     3,     1,     2,
       0,     4,     2,     0,     2,     1,     1,     1,     1,     1,
       5,     5,     0,     3,     5,     5,     0,     3,     5,     5,
       0,     3,     1,     1,     2,     3,     4,     5,     3,     0,
       2,     3,     0,     2,     3,     3,     0,     3,     0,     3,
       1,     2,     0,     4,     2,     0,     2,     1,     1,     1,
       1,     2,     3,     4,     5,     3,     0,     2,     3,     0,
       2,     3,     3,     0,     3,     0,     3,     1,     2,     0,
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
     100,     0,     2,     0,   142,    12,    11,     8,   103,   102,
       0,   169,     0,     0,   145,   144,     0,   312,    10,    26,
      32,    38,    44,     0,     0,     0,     0,     0,    82,     0,
      13,    14,     0,    15,     0,    16,     0,    17,    47,    18,
      52,    53,    19,    57,    58,    20,    62,    63,    21,    67,
      68,    22,    72,    73,    23,    77,    78,    24,   101,     0,
     112,   116,   120,     0,   104,   105,   106,   107,   108,   122,
     123,   109,     0,   172,   171,   314,     6,     0,    54,     0,
      59,     0,    64,     0,    69,     0,    74,    79,     0,     0,
       0,     0,     0,    27,    25,     0,    33,    31,     0,    39,
      37,    45,     0,    43,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   124,   143,     0,     0,   146,   147,
     149,   150,   148,     0,     0,     0,    55,     0,    60,     0,
      65,     0,    70,     0,    75,    83,     0,     0,    87,    29,
      28,    35,    34,    41,    40,    48,    50,     0,   129,     0,
       0,     0,     0,     0,     0,     0,   125,     0,     0,     0,
     151,   170,     0,   190,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   173,   174,   175,
     192,   193,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   325,   323,     0,     0,     0,
     315,   316,   317,   318,   313,    56,    61,    66,    71,    76,
       0,     0,    80,    86,     0,     0,     0,     0,     0,    51,
       0,   128,     0,   113,     0,     0,   117,     0,     0,   121,
       0,     0,   126,     0,   156,     0,   152,     0,     0,     0,
       0,     0,   194,     0,   199,     0,   204,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   327,     0,   376,
       0,     0,     0,    84,    81,    85,    90,    88,    30,    36,
      42,    49,    46,   127,   132,   130,   111,   110,   115,   114,
     119,   118,   155,     0,   153,     0,   299,     0,     0,     0,
     195,     0,     0,     0,     0,     0,   209,     0,   214,     0,
     219,     0,   289,     0,   284,     0,   224,     0,   239,     0,
     254,     0,   269,     0,   294,     0,     0,   322,   378,   440,
     319,   321,   320,     0,     0,   154,   159,   157,   298,     0,
     191,     0,   196,   198,     0,   197,   200,   203,   202,     0,
     205,   208,     0,   213,     0,   218,     0,   288,     0,   283,
       0,   223,     0,   238,     0,   253,     0,   268,     0,   293,
       0,     0,   331,   330,   326,     0,     0,   442,   504,     0,
      98,     0,    91,    94,    89,     0,   140,     0,   133,   136,
     131,     0,   297,   302,   300,   189,     0,     0,   207,     0,
     210,     0,   212,   215,     0,   217,   220,     0,   287,   290,
       0,   282,   285,   227,   222,   225,   242,   237,   240,   257,
     252,   255,   272,   267,   270,   292,     0,   295,   328,     0,
     344,     0,   382,   381,   377,     0,     0,     0,   324,    99,
       0,     0,    96,   141,     0,     0,   138,     0,   167,     0,
     160,   163,   158,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   346,     0,   379,
       0,   395,     0,   446,   445,   441,     0,     0,    93,     0,
       0,    92,   135,     0,     0,   134,   168,     0,     0,   165,
       0,   310,     0,   303,   306,   301,   201,   206,     0,     0,
       0,     0,     0,     0,   236,     0,     0,     0,   228,   229,
     230,   231,   226,     0,   251,     0,     0,     0,   243,   244,
     245,   246,   241,     0,   266,     0,     0,     0,   258,   259,
     260,   261,   256,     0,   281,     0,     0,     0,   273,   274,
     275,   276,   271,     0,     0,     0,   329,     0,     0,   408,
     443,     0,   459,     0,   507,    95,     0,   137,     0,   162,
       0,     0,   161,   311,     0,     0,   308,   211,   216,   221,
     291,   286,   235,     0,     0,     0,   250,     0,     0,     0,
     265,     0,     0,     0,   280,     0,     0,     0,   296,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   347,   348,
     349,   350,   351,   352,   353,   354,   345,     0,     0,   410,
       0,     0,     0,   472,   506,     0,    97,   139,   164,     0,
     305,     0,     0,   304,   232,   233,   234,   247,   248,   249,
     262,   263,   264,   277,   278,   279,   333,   364,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   380,
       0,     0,   474,     0,   505,   510,   508,   166,   307,     0,
       0,     0,   362,   358,   359,   360,   355,   356,   357,   361,
     384,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     411,   412,   413,   414,   415,   416,   417,   418,   409,     0,
       0,     0,   444,     0,   309,   332,   336,   334,     0,   375,
       0,     0,     0,     0,   365,   366,   367,   368,   369,   363,
       0,   397,   428,     0,     0,     0,     0,     0,     0,     0,
       0,   448,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   475,   476,   477,   478,   479,   480,   481,   482,   473,
       0,   525,     0,     0,     0,     0,     0,     0,   511,   512,
     513,   514,   515,   516,   517,   509,     0,   374,     0,     0,
       0,     0,   383,   387,   385,     0,     0,   426,   422,   423,
     424,   419,   420,   421,   425,     0,   461,   492,     0,     0,
       0,     0,     0,     0,     0,     0,   524,     0,     0,     0,
       0,     0,     0,     0,   343,     0,     0,   337,   338,   339,
     335,   370,   371,   372,   373,     0,   400,   396,   398,     0,
     439,     0,     0,     0,     0,   429,   430,   431,   432,   433,
     427,   447,   451,   449,     0,     0,   490,   486,   487,   488,
     483,   484,   485,   489,   520,   521,   522,   518,   519,   523,
     342,     0,     0,     0,   394,     0,     0,   388,   389,   390,
     386,     0,   438,     0,     0,     0,     0,     0,   464,   460,
     462,     0,   503,     0,     0,     0,     0,   493,   494,   495,
     496,   497,   491,   340,   341,   393,     0,     0,     0,   407,
       0,     0,   401,   402,   403,   399,   434,   435,   436,   437,
       0,   458,     0,     0,   452,   453,   454,   450,     0,   502,
       0,     0,     0,     0,   391,   392,   406,     0,     0,   457,
       0,     0,     0,   471,     0,     0,   465,   466,   467,   463,
     498,   499,   500,   501,   404,   405,   455,   456,   470,     0,
       0,   468,   469
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,     9,    10,    11,    17,    22,    40,    41,
      42,   104,   225,    43,    44,   107,   226,    45,    46,   110,
     227,    47,    48,   113,   114,   228,   230,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    99,   220,    67,   101,   224,
     287,   343,   392,   393,   452,   491,   394,    14,    23,    74,
      75,   118,    76,   120,    77,   122,    78,    79,    80,    81,
     116,   232,   295,   344,   398,   399,   456,   495,   400,    21,
      82,   128,   129,   130,   131,   132,   168,   303,   347,   401,
     460,   461,   499,   572,   462,    27,   133,   187,   188,   250,
     189,   190,   191,   192,   254,   312,   356,   193,   256,   314,
     360,   194,   258,   362,   410,   195,   260,   364,   413,   196,
     262,   366,   416,   197,   268,   372,   425,   471,   518,   519,
     520,   521,   522,   198,   270,   374,   428,   472,   528,   529,
     530,   531,   532,   199,   272,   376,   431,   473,   538,   539,
     540,   541,   542,   200,   274,   378,   434,   474,   548,   549,
     550,   551,   552,   201,   266,   370,   422,   202,   264,   368,
     419,   203,   276,   380,   437,   204,   248,   349,   404,   463,
     503,   504,   576,   633,   505,    86,   134,   210,   211,   212,
     213,   214,   278,   279,   336,   384,   440,   670,   707,   766,
     807,   808,   809,   810,   478,   555,   608,   609,   610,   611,
     612,   613,   614,   615,   616,   648,   671,   714,   715,   716,
     717,   718,   719,   339,   386,   444,   481,   720,   774,   815,
     857,   858,   859,   860,   559,   775,   818,   861,   892,   893,
     894,   895,   620,   658,   690,   691,   692,   693,   694,   695,
     696,   697,   698,   723,   776,   825,   826,   827,   828,   829,
     830,   388,   446,   485,   562,   785,   833,   867,   904,   905,
     906,   907,   623,   834,   870,   908,   926,   927,   928,   929,
     663,   701,   741,   742,   743,   744,   745,   746,   747,   748,
     749,   788,   835,   877,   878,   879,   880,   881,   882,   448,
     487,   625,   666,   703,   758,   759,   760,   761,   762,   763,
     764,   765
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -91
static const yytype_int16 yypact[] =
{
       9,    26,    49,    27,   -91,   -91,    48,   -91,   -91,   102,
      55,   156,   -91,   209,    71,   -91,   -91,   -91,   -91,   -91,
     212,   106,   119,   -39,   -91,   -91,   214,    65,   -91,   -91,
     -91,   -91,   -91,   216,   218,   220,   222,   224,   137,   151,
     -91,   -91,   226,   -91,   228,   -91,   230,   -91,   131,   -91,
     -91,   -91,   -91,   -91,   -91,   -91,   -91,   -91,   -91,   -91,
     -91,   -91,   -91,   -91,   -91,   -91,   -91,   -91,   -91,   160,
     132,   140,   150,   232,   -91,   -91,   -91,   -91,   -91,   -91,
     -91,   -91,   -27,   -91,   -91,   -91,   -91,    12,   -91,     4,
     -91,     7,   -91,     2,   -91,     1,   -91,   -91,   174,   179,
     198,   183,     8,   -91,   -91,    10,   -91,   -91,     6,   -91,
     -91,   -91,   275,   -91,   271,   277,   273,   279,   276,   280,
     278,   282,   281,    -2,   -91,   -91,   272,   234,   -91,   -91,
     -91,   -91,   -91,   -48,   129,   229,   -91,   231,   -91,   227,
     -91,   233,   -91,   235,   -91,   -91,     0,   283,   -91,   -91,
     -91,   -91,   -91,   -91,   -91,   -91,   284,   285,   -91,   287,
     239,   289,   241,   290,   243,   215,   -91,   295,   292,    -3,
     -91,   -91,   288,   263,   242,   291,   293,   294,   296,   297,
     298,   299,   286,   300,   301,   302,   303,   -91,   -91,   -91,
     -91,   -91,   -91,   -91,   -91,   -91,   -91,   -91,   -91,   -91,
     -91,   -91,   -91,   -91,   -91,   187,   -91,   306,   309,   314,
     -91,   -91,   -91,   -91,   -91,   -91,   -91,   -91,   -91,   -91,
     315,   249,   -91,   -91,   178,   252,   267,   266,   318,   -91,
     269,   -91,   180,   -91,   248,   253,   -91,   247,   254,   -91,
     251,   255,   -91,   323,   -91,   246,   -91,   332,   328,   335,
     331,    -4,   -91,   337,   -91,   338,   -91,   339,   336,   340,
     341,   342,   343,   344,   345,   347,   346,   349,   348,   352,
     350,   354,   351,   357,   353,   359,   355,   316,   312,   221,
     358,   360,   361,   -91,   -91,   -91,   -91,   -91,   -91,   -91,
     -91,   -91,   -91,   -91,   -91,   -91,   -91,   -91,   -91,   -91,
     -91,   -91,   -91,   182,   -91,   362,   -91,   363,   367,   304,
     -91,   365,   -44,   366,    76,   368,   -91,   369,   -91,   370,
     -91,   371,   -91,   372,   -91,   373,   -91,   374,   -91,   375,
     -91,   376,   -91,   377,   -91,   382,   250,   -91,   356,   256,
     -91,   -91,   -91,    14,    18,   -91,   -91,   -91,   -91,   186,
     -91,   305,   -91,   -91,   378,   -91,   -91,   -91,   -91,   380,
     -91,   -91,   166,   -91,   -82,   -91,    45,   -91,    -8,   -91,
     -18,   -91,   -11,   -91,   -81,   -91,   -90,   -91,   -86,   -91,
     146,   383,   274,   -91,   -91,   386,   258,   334,   257,   319,
     -91,   389,   -91,   364,   -91,   320,   -91,   395,   -91,   379,
     -91,    20,   -91,   -91,   -91,   -91,   397,   399,   -91,   391,
     -91,   396,   -91,   -91,   398,   -91,   -91,   400,   -91,   -91,
     401,   -91,   -91,   -91,   -91,   -91,   -91,   -91,   -91,   -91,
     -91,   -91,   -91,   -91,   -91,   -91,   402,   -91,   -91,   381,
     330,   404,   245,   -91,   -91,   409,   260,   387,   -91,   -91,
     408,   413,   384,   -91,   411,   416,   385,   388,   -91,   417,
     -91,   390,   -91,    24,   392,   324,   403,   419,   422,   423,
     425,   185,   188,   191,   194,   426,   418,   -91,   310,   -91,
     405,   307,   424,   308,   -91,   -91,   430,   427,   -91,   429,
     431,   -91,   -91,   434,   435,   -91,   -91,   436,   439,   406,
     393,   -91,   441,   -91,   410,   -91,   -91,   -91,   394,   407,
     412,   414,   415,   420,   -91,   444,   446,   447,   -91,   -91,
     -91,   -91,   -91,   421,   -91,   448,   449,   450,   -91,   -91,
     -91,   -91,   -91,   428,   -91,   452,   453,   454,   -91,   -91,
     -91,   -91,   -91,   432,   -91,   455,   456,   457,   -91,   -91,
     -91,   -91,   -91,   317,   458,    79,   -91,   459,   433,   440,
     -91,   437,   322,   461,   -91,   -91,   463,   -91,   464,   -91,
     466,   471,   -91,   -91,   468,   473,   438,   -91,   -91,   -91,
     -91,   -91,   -91,   470,   472,   474,   -91,   475,   476,   477,
     -91,   478,   479,   480,   -91,   481,   482,   483,   -91,   485,
     442,   488,   491,   492,   493,   494,   495,   496,   -91,   -91,
     -91,   -91,   -91,   -91,   -91,   -91,   -91,   497,   498,   -91,
     333,   499,   445,   443,   -91,   126,   -91,   -91,   -91,   500,
     -91,   501,   503,   -91,   -91,   -91,   -91,   -91,   -91,   -91,
     -91,   -91,   -91,   -91,   -91,   -91,   -91,   -91,   451,   502,
     504,   507,   509,   510,   512,   515,   516,   518,   105,   -91,
     519,   520,   -91,   460,   -91,   -91,   -91,   -91,   -91,   522,
     148,    43,   -91,   -91,   -91,   -91,   -91,   -91,   -91,   -91,
     -91,   523,   462,   527,   530,   531,   532,   533,   534,   535,
     -91,   -91,   -91,   -91,   -91,   -91,   -91,   -91,   -91,   536,
     538,   112,   -91,   145,   -91,   -91,   -91,   -91,   465,   -91,
     537,   539,   540,   543,   -91,   -91,   -91,   -91,   -91,   -91,
     144,   -91,   -91,   484,   541,   542,   544,   545,   546,   547,
     548,   -91,   549,   327,   553,   555,   556,   558,   559,   560,
     561,   -91,   -91,   -91,   -91,   -91,   -91,   -91,   -91,   -91,
     467,   -91,   562,   563,   565,   566,   567,   568,   -91,   -91,
     -91,   -91,   -91,   -91,   -91,   -91,    84,   -91,   569,   570,
     571,   572,   -91,   -91,   -91,    64,    67,   -91,   -91,   -91,
     -91,   -91,   -91,   -91,   -91,   138,   -91,   -91,   505,   573,
     575,   576,   577,   578,   579,   580,   -91,   581,   582,   583,
     585,   587,   588,   486,   -91,   594,   595,   -91,   -91,   -91,
     -91,   -91,   -91,   -91,   -91,    86,   -91,   -91,   -91,   489,
     -91,   596,   597,   598,   599,   -91,   -91,   -91,   -91,   -91,
     -91,   -91,   -91,   -91,    77,    69,   -91,   -91,   -91,   -91,
     -91,   -91,   -91,   -91,   -91,   -91,   -91,   -91,   -91,   -91,
     -91,   600,   601,   487,   -91,   602,   603,   -91,   -91,   -91,
     -91,    88,   -91,   604,   607,   609,   610,   122,   -91,   -91,
     -91,   469,   -91,   615,   617,   618,   619,   -91,   -91,   -91,
     -91,   -91,   -91,   -91,   -91,   -91,   616,   620,   506,   -91,
     621,   622,   -91,   -91,   -91,   -91,   -91,   -91,   -91,   -91,
     490,   -91,   623,   625,   -91,   -91,   -91,   -91,   124,   -91,
     624,   626,   627,   628,   -91,   -91,   -91,   629,   630,   -91,
     632,   633,   508,   -91,   638,   639,   -91,   -91,   -91,   -91,
     -91,   -91,   -91,   -91,   -91,   -91,   -91,   -91,   -91,   636,
     637,   -91,   -91
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
     -91,   -91
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint16 yytable[] =
{
     309,   245,   171,   165,   221,   143,   141,    68,   137,   429,
     153,   139,   149,   432,   151,   411,   135,   354,   426,     1,
     412,   125,   389,   390,   430,   172,   395,   396,   457,   458,
     433,   427,   500,   501,    69,     6,     7,     4,    70,   173,
      71,   174,    72,   175,    73,   176,   126,   177,   355,     5,
     391,   708,   709,   178,   397,   179,   459,   180,   127,   181,
     502,   182,   150,   183,   154,   184,   152,   185,   138,   186,
     142,   144,   222,   140,   136,   819,   820,   871,   872,   420,
     710,   711,   166,   246,   712,   713,   310,   600,   423,   417,
     421,     8,   803,   804,   853,   854,   888,   889,   418,   424,
      13,   601,   602,   603,   821,   822,   873,   874,   823,   824,
     875,   876,   604,   682,    12,   605,    85,   606,    20,   607,
     733,   805,   806,   855,   856,   890,   891,   683,   684,   685,
     900,   901,   922,   923,   734,   735,   736,   205,   206,   686,
     111,   687,   414,   688,   112,   689,    97,   737,   738,   415,
     739,    98,   740,   750,   751,    26,   207,   208,   209,   902,
     903,   924,   925,    28,    15,    16,   100,   752,   753,   754,
     358,   117,    29,   359,    30,   115,    31,   145,    32,   119,
      33,   755,    34,   756,    35,   757,    36,   146,    37,   121,
      38,   148,    39,   513,   514,   816,   523,   524,   817,   533,
     534,   147,   543,   544,   515,   516,   517,   525,   526,   527,
     535,   536,   537,   545,   546,   547,   868,    18,    19,   869,
      24,    25,    83,    84,    87,    88,    89,    90,    91,    92,
      93,    94,    95,    96,   102,   103,   105,   106,   108,   109,
     123,   124,   169,   170,   234,   235,   237,   238,   240,   241,
     251,   252,   285,   286,   293,   294,   345,   346,   382,   383,
     402,   403,   408,   409,   435,   436,   442,   443,   483,   484,
     664,   665,   705,   706,   772,   773,   831,   832,   155,   156,
     157,   158,   159,   161,   160,   163,   162,   167,   229,   164,
     223,   215,   231,   217,   233,   216,   236,   239,   243,   242,
     244,   218,   249,   247,   267,   219,   288,   253,   277,   280,
     255,   257,   281,   259,   261,   263,   265,   282,   269,   271,
     273,   284,   283,   289,   290,   291,   296,   298,   275,   292,
     302,   297,   304,   300,   299,   305,   306,   301,   307,   308,
     311,   313,   315,   317,   316,   319,   335,   321,   338,   318,
     323,   320,   325,   322,   324,   327,   326,   329,   328,   330,
     331,   332,   333,   334,   337,   340,   445,   341,   342,   348,
     350,   351,   353,   357,   480,   361,   363,   365,   367,   369,
     371,   373,   375,   377,   379,   381,   406,   385,   407,   441,
     438,   387,   450,   405,   352,   449,   453,   439,   454,   466,
     447,   464,   451,   465,   467,   477,   468,   508,   469,   470,
     475,   479,   482,   486,   476,   488,   489,   455,   492,   493,
     497,   554,   507,   509,   490,   494,   510,   511,   498,   512,
     553,   560,   556,   563,   566,   564,   565,   598,   568,   557,
     558,   567,   570,   569,   574,   561,   571,   583,   575,   584,
     585,   587,   588,   589,   506,   591,   592,   593,   595,   596,
     597,   659,   617,   622,   496,   599,   787,   618,   624,   573,
     626,   627,   621,   628,   629,   630,   631,   634,   632,   635,
     661,   636,   637,   638,   639,   640,   641,   642,   643,   644,
     645,   649,   577,   646,   650,   651,   652,   653,   654,   655,
       0,   657,   660,     0,   656,   578,   669,   667,   668,   673,
     579,   674,   580,   581,   675,   619,   676,   677,   662,   678,
     582,   586,   679,   700,   680,   681,   699,   672,   590,   704,
     724,   721,   594,   725,   726,   727,   728,   729,   730,     0,
     768,     0,   769,   770,   731,   732,   771,     0,   778,   779,
       0,   780,   781,   782,   783,   784,   789,   786,   790,   791,
     777,   792,   793,   794,   795,   797,   798,   647,   799,   800,
     801,   802,     0,     0,     0,     0,   811,   812,   813,   814,
     837,   836,   838,   839,   840,   841,   842,   843,   844,   845,
     846,   767,   847,   722,   848,   849,   702,   851,   852,   863,
     864,   865,   866,     0,     0,   886,   887,   883,   884,   909,
       0,   896,   850,   796,   897,   862,   898,   899,   910,   885,
     911,   912,   913,   914,   917,   918,   920,   915,   921,     0,
     919,   930,     0,   931,   932,   933,   934,   935,   916,   936,
     937,   939,   940,   941,   942,     0,     0,     0,   938
};

static const yytype_int16 yycheck[] =
{
       4,     4,    50,     5,     4,     4,     4,    46,     4,    99,
       4,     4,     4,    99,     4,    97,     4,    61,    99,    10,
     102,    48,     8,     9,   114,    73,     8,     9,     8,     9,
     116,   112,     8,     9,    73,     8,     9,    11,    77,    87,
      79,    89,    81,    91,    83,    93,    73,    95,    92,     0,
      36,     8,     9,   101,    36,   103,    36,   105,    85,   107,
      36,   109,    54,   111,    58,   113,    56,   115,    64,   117,
      68,    70,    72,    66,    62,     8,     9,     8,     9,    97,
      37,    38,    84,    86,    41,    42,    90,     8,    99,    97,
     108,    43,     8,     9,     8,     9,     8,     9,   106,   110,
      45,    22,    23,    24,    37,    38,    37,    38,    41,    42,
      41,    42,    33,     8,    12,    36,    51,    38,    47,    40,
       8,    37,    38,    37,    38,    37,    38,    22,    23,    24,
       8,     9,     8,     9,    22,    23,    24,     8,     9,    34,
       9,    36,    97,    38,    13,    40,     9,    35,    36,   104,
      38,    14,    40,     8,     9,    49,    27,    28,    29,    37,
      38,    37,    38,    44,     8,     9,    15,    22,    23,    24,
      94,    39,    53,    97,    55,    15,    57,     3,    59,    39,
      61,    36,    63,    38,    65,    40,    67,     8,    69,    39,
      71,     8,    73,     8,     9,   131,     8,     9,   134,     8,
       9,     3,     8,     9,    19,    20,    21,    19,    20,    21,
      19,    20,    21,    19,    20,    21,   139,     8,     9,   142,
       8,     9,     8,     9,     8,     9,     8,     9,     8,     9,
       8,     9,     8,     9,     8,     9,     8,     9,     8,     9,
       8,     9,     8,     9,     5,     6,     5,     6,     5,     6,
       8,     9,    74,    75,    74,    75,    74,    75,     8,     9,
      74,    75,    96,    97,   118,   119,     8,     9,     8,     9,
     144,   145,   124,   125,   130,   131,   138,   139,     3,     8,
       3,     8,     3,     3,     8,     3,     8,    15,     4,     8,
       7,    62,     7,    66,     7,    64,     7,     7,     3,    84,
       8,    68,    39,    15,    18,    70,    54,    16,   121,     3,
      17,    17,     3,    17,    17,    17,    17,     3,    18,    18,
      18,    72,     7,    56,    58,     7,    78,    80,    25,    60,
       7,    78,    86,    82,    80,     3,     8,    82,     3,     8,
       3,     3,     3,     3,     8,     3,    30,     3,   127,     8,
       3,     8,     3,     8,     8,     3,     8,     3,     8,     8,
       3,     8,     3,     8,    52,     7,    32,     7,     7,     7,
       7,     4,     7,     7,   129,     7,     7,     7,     7,     7,
       7,     7,     7,     7,     7,     3,     8,    31,     8,     3,
       7,   135,     3,    88,    90,    76,    76,   123,     3,     8,
     143,     4,    38,     4,     8,    75,     8,     4,     8,     8,
       8,     7,     3,    26,    33,     7,     3,    38,     7,     3,
       3,     3,    98,     4,    40,    40,     4,     4,    38,     4,
       4,     7,   122,     3,     3,     8,     7,   120,     3,    34,
     133,     7,     3,     7,     3,   137,    40,     3,    38,     3,
       3,     3,     3,     3,    62,     3,     3,     3,     3,     3,
       3,   128,     3,   141,    76,     7,   139,    34,     7,    76,
       7,     7,    35,     7,     3,     7,     3,     7,    40,     7,
      35,     7,     7,     7,     7,     7,     7,     7,     7,     7,
       7,     3,    98,     8,     3,     3,     3,     3,     3,     3,
      -1,     3,     3,    -1,     7,    98,     3,     7,     7,     7,
      98,     7,    98,    98,     7,    75,     7,     7,    75,     7,
     100,   100,     7,     3,     8,     7,     7,    76,   100,     7,
       3,     8,   100,     3,     3,     3,     3,     3,     3,    -1,
       3,    -1,     3,     3,     8,     7,     3,    -1,     7,     7,
      -1,     7,     7,     7,     7,     7,     3,     8,     3,     3,
      76,     3,     3,     3,     3,     3,     3,   125,     3,     3,
       3,     3,    -1,    -1,    -1,    -1,     7,     7,     7,     7,
       7,    76,     7,     7,     7,     7,     7,     7,     7,     7,
       7,   126,     7,   131,     7,     7,   136,     3,     3,     3,
       3,     3,     3,    -1,    -1,     3,     3,     7,     7,   140,
      -1,     7,   126,   146,     7,   126,     7,     7,     3,   132,
       3,     3,     3,     7,     3,     3,     3,     7,     3,    -1,
     140,     7,    -1,     7,     7,     7,     7,     7,   132,     7,
       7,     3,     3,     7,     7,    -1,    -1,    -1,   140
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,    10,   149,   150,    11,     0,     8,     9,    43,   151,
     152,   153,    12,    45,   205,     8,     9,   154,     8,     9,
      47,   227,   155,   206,     8,     9,    49,   243,    44,    53,
      55,    57,    59,    61,    63,    65,    67,    69,    71,    73,
     156,   157,   158,   161,   162,   165,   166,   169,   170,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,   195,    46,    73,
      77,    79,    81,    83,   207,   208,   210,   212,   214,   215,
     216,   217,   228,     8,     9,    51,   333,     8,     9,     8,
       9,     8,     9,     8,     9,     8,     9,     9,    14,   193,
      15,   196,     8,     9,   159,     8,     9,   163,     8,     9,
     167,     9,    13,   171,   172,    15,   218,    39,   209,    39,
     211,    39,   213,     8,     9,    48,    73,    85,   229,   230,
     231,   232,   233,   244,   334,     4,    62,     4,    64,     4,
      66,     4,    68,     4,    70,     3,     8,     3,     8,     4,
      54,     4,    56,     4,    58,     3,     8,     3,     8,     3,
       8,     3,     8,     3,     8,     5,    84,    15,   234,     8,
       9,    50,    73,    87,    89,    91,    93,    95,   101,   103,
     105,   107,   109,   111,   113,   115,   117,   245,   246,   248,
     249,   250,   251,   255,   259,   263,   267,   271,   281,   291,
     301,   311,   315,   319,   323,     8,     9,    27,    28,    29,
     335,   336,   337,   338,   339,    62,    64,    66,    68,    70,
     194,     4,    72,     7,   197,   160,   164,   168,   173,     4,
     174,     7,   219,     7,     5,     6,     7,     5,     6,     7,
       5,     6,    84,     3,     8,     4,    86,    15,   324,    39,
     247,     8,     9,    16,   252,    17,   256,    17,   260,    17,
     264,    17,   268,    17,   316,    17,   312,    18,   272,    18,
     282,    18,   292,    18,   302,    25,   320,   121,   340,   341,
       3,     3,     3,     7,    72,    74,    75,   198,    54,    56,
      58,     7,    60,    74,    75,   220,    78,    78,    80,    80,
      82,    82,     7,   235,    86,     3,     8,     3,     8,     4,
      90,     3,   253,     3,   257,     3,     8,     3,     8,     3,
       8,     3,     8,     3,     8,     3,     8,     3,     8,     3,
       8,     3,     8,     3,     8,    30,   342,    52,   127,   371,
       7,     7,     7,   199,   221,    74,    75,   236,     7,   325,
       7,     4,    90,     7,    61,    92,   254,     7,    94,    97,
     258,     7,   261,     7,   265,     7,   269,     7,   317,     7,
     313,     7,   273,     7,   283,     7,   293,     7,   303,     7,
     321,     3,     8,     9,   343,    31,   372,   135,   409,     8,
       9,    36,   200,   201,   204,     8,     9,    36,   222,   223,
     226,   237,    74,    75,   326,    88,     8,     8,    96,    97,
     262,    97,   102,   266,    97,   104,   270,    97,   106,   318,
      97,   108,   314,    99,   110,   274,    99,   112,   284,    99,
     114,   294,    99,   116,   304,   118,   119,   322,     7,   123,
     344,     3,     8,     9,   373,    32,   410,   143,   447,    76,
       3,    38,   202,    76,     3,    38,   224,     8,     9,    36,
     238,   239,   242,   327,     4,     4,     8,     8,     8,     8,
       8,   275,   285,   295,   305,     8,    33,    75,   352,     7,
     129,   374,     3,     8,     9,   411,    26,   448,     7,     3,
      40,   203,     7,     3,    40,   225,    76,     3,    38,   240,
       8,     9,    36,   328,   329,   332,    62,    98,     4,     4,
       4,     4,     4,     8,     9,    19,    20,    21,   276,   277,
     278,   279,   280,     8,     9,    19,    20,    21,   286,   287,
     288,   289,   290,     8,     9,    19,    20,    21,   296,   297,
     298,   299,   300,     8,     9,    19,    20,    21,   306,   307,
     308,   309,   310,     4,     3,   353,   122,    34,   133,   382,
       7,   137,   412,     3,     8,     7,     3,     7,     3,     7,
       3,    40,   241,    76,     3,    38,   330,    98,    98,    98,
      98,    98,   100,     3,     3,     3,   100,     3,     3,     3,
     100,     3,     3,     3,   100,     3,     3,     3,   120,     7,
       8,    22,    23,    24,    33,    36,    38,    40,   354,   355,
     356,   357,   358,   359,   360,   361,   362,     3,    34,    75,
     390,    35,   141,   420,     7,   449,     7,     7,     7,     3,
       7,     3,    40,   331,     7,     7,     7,     7,     7,     7,
       7,     7,     7,     7,     7,     7,     8,   125,   363,     3,
       3,     3,     3,     3,     3,     3,     7,     3,   391,   128,
       3,    35,    75,   428,   144,   145,   450,     7,     7,     3,
     345,   364,    76,     7,     7,     7,     7,     7,     7,     7,
       8,     7,     8,    22,    23,    24,    34,    36,    38,    40,
     392,   393,   394,   395,   396,   397,   398,   399,   400,     7,
       3,   429,   136,   451,     7,   124,   125,   346,     8,     9,
      37,    38,    41,    42,   365,   366,   367,   368,   369,   370,
     375,     8,   131,   401,     3,     3,     3,     3,     3,     3,
       3,     8,     7,     8,    22,    23,    24,    35,    36,    38,
      40,   430,   431,   432,   433,   434,   435,   436,   437,   438,
       8,     9,    22,    23,    24,    36,    38,    40,   452,   453,
     454,   455,   456,   457,   458,   459,   347,   126,     3,     3,
       3,     3,   130,   131,   376,   383,   402,    76,     7,     7,
       7,     7,     7,     7,     7,   413,     8,   139,   439,     3,
       3,     3,     3,     3,     3,     3,   146,     3,     3,     3,
       3,     3,     3,     8,     9,    37,    38,   348,   349,   350,
     351,     7,     7,     7,     7,   377,   131,   134,   384,     8,
       9,    37,    38,    41,    42,   403,   404,   405,   406,   407,
     408,   138,   139,   414,   421,   440,    76,     7,     7,     7,
       7,     7,     7,     7,     7,     7,     7,     7,     7,     7,
     126,     3,     3,     8,     9,    37,    38,   378,   379,   380,
     381,   385,   126,     3,     3,     3,     3,   415,   139,   142,
     422,     8,     9,    37,    38,    41,    42,   441,   442,   443,
     444,   445,   446,     7,     7,   132,     3,     3,     8,     9,
      37,    38,   386,   387,   388,   389,     7,     7,     7,     7,
       8,     9,    37,    38,   416,   417,   418,   419,   423,   140,
       3,     3,     3,     3,     7,     7,   132,     3,     3,   140,
       3,     3,     8,     9,    37,    38,   424,   425,   426,   427,
       7,     7,     7,     7,     7,     7,     7,     7,   140,     3,
       3,     7,     7
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
	}
;}
    break;

  case 48:

    {osoption->general->instanceLocation->locationType = (yyvsp[(2) - (2)].sval);;}
    break;

  case 51:

    {osoption->general->instanceLocation->value = (yyvsp[(1) - (1)].sval);;}
    break;

  case 55:

    {
;}
    break;

  case 56:

    {
;}
    break;

  case 60:

    {
;}
    break;

  case 61:

    {
;}
    break;

  case 65:

    {
;}
    break;

  case 66:

    {
;}
    break;

  case 70:

    {
;}
    break;

  case 71:

    {
;}
    break;

  case 75:

    {
;}
    break;

  case 76:

    {
;}
    break;

  case 80:

    {
;}
    break;

  case 81:

    {
;}
    break;

  case 83:

    {
printf("TRANSSPORT ATTRIBUTE TEXT =  %s",(yyvsp[(2) - (2)].sval));printf("%s","\n");
//delete($2);
;}
    break;

  case 86:

    {
;}
    break;

  case 93:

    {
;}
    break;

  case 95:

    {
;}
    break;

  case 97:

    {
;}
    break;

  case 99:

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

  case 115:

    {
;}
    break;

  case 117:

    {
;}
    break;

  case 119:

    {
;}
    break;

  case 121:

    {
;}
    break;

  case 125:

    {
;}
    break;

  case 126:

    {
;}
    break;

  case 128:

    {
;}
    break;

  case 135:

    {
;}
    break;

  case 137:

    {
;}
    break;

  case 139:

    {
;}
    break;

  case 141:

    {
;}
    break;

  case 152:

    {
;}
    break;

  case 153:

    {
;}
    break;

  case 155:

    {
;}
    break;

  case 162:

    {
;}
    break;

  case 164:

    {
;}
    break;

  case 166:

    {
;}
    break;

  case 168:

    {
;}
    break;

  case 189:

    {
;}
    break;

  case 191:

    {
;}
    break;

  case 195:

    {
;}
    break;

  case 196:

    {
;}
    break;

  case 198:

    {
;}
    break;

  case 201:

    {
;}
    break;

  case 203:

    {
;}
    break;

  case 206:

    {
;}
    break;

  case 208:

    {
;}
    break;

  case 211:

    {
;}
    break;

  case 213:

    {
;}
    break;

  case 216:

    {
;}
    break;

  case 218:

    {
;}
    break;

  case 221:

    {
;}
    break;

  case 223:

    {
;}
    break;

  case 226:

    {
;}
    break;

  case 232:

    {
;}
    break;

  case 233:

    {
;}
    break;

  case 234:

    {
;}
    break;

  case 238:

    {
;}
    break;

  case 241:

    {
;}
    break;

  case 247:

    {
;}
    break;

  case 248:

    {
;}
    break;

  case 249:

    {
;}
    break;

  case 253:

    {
;}
    break;

  case 256:

    {
;}
    break;

  case 262:

    {
;}
    break;

  case 263:

    {
;}
    break;

  case 264:

    {
;}
    break;

  case 268:

    {
;}
    break;

  case 271:

    {
;}
    break;

  case 277:

    {
;}
    break;

  case 278:

    {
;}
    break;

  case 279:

    {
;}
    break;

  case 283:

    {
;}
    break;

  case 286:

    {
;}
    break;

  case 288:

    {
;}
    break;

  case 291:

    {
;}
    break;

  case 293:

    {
;}
    break;

  case 296:

    {
;}
    break;

  case 298:

    {
;}
    break;

  case 305:

    {
;}
    break;

  case 307:

    {
;}
    break;

  case 309:

    {
;}
    break;

  case 311:

    {
;}
    break;

  case 319:

    {
;}
    break;

  case 320:

    {
;}
    break;

  case 321:

    {
;}
    break;

  case 328:

    {
;}
    break;

  case 340:

    {
;}
    break;

  case 341:

    {
;}
    break;

  case 355:

    {
;}
    break;

  case 356:

    {
;}
    break;

  case 357:

    {
;}
    break;

  case 358:

    {
;}
    break;

  case 359:

    {
;}
    break;

  case 360:

    {
;}
    break;

  case 361:

    {
;}
    break;

  case 370:

    {
;}
    break;

  case 371:

    {
;}
    break;

  case 372:

    {
;}
    break;

  case 373:

    {
;}
    break;

  case 379:

    {
;}
    break;

  case 391:

    {
;}
    break;

  case 392:

    {
;}
    break;

  case 404:

    {
;}
    break;

  case 405:

    {
;}
    break;

  case 419:

    {
;}
    break;

  case 420:

    {
;}
    break;

  case 421:

    {
;}
    break;

  case 422:

    {
;}
    break;

  case 423:

    {
;}
    break;

  case 424:

    {
;}
    break;

  case 425:

    {
;}
    break;

  case 434:

    {
;}
    break;

  case 435:

    {
;}
    break;

  case 436:

    {
;}
    break;

  case 437:

    {
;}
    break;

  case 443:

    {
;}
    break;

  case 455:

    {
;}
    break;

  case 456:

    {
;}
    break;

  case 468:

    {
;}
    break;

  case 469:

    {
;}
    break;

  case 483:

    {
;}
    break;

  case 484:

    {
;}
    break;

  case 485:

    {
;}
    break;

  case 486:

    {
;}
    break;

  case 487:

    {
;}
    break;

  case 488:

    {
;}
    break;

  case 489:

    {
;}
    break;

  case 498:

    {
;}
    break;

  case 499:

    {
;}
    break;

  case 500:

    {
;}
    break;

  case 501:

    {
;}
    break;

  case 506:

    {
;}
    break;

  case 518:

    {
;}
    break;

  case 519:

    {
;}
    break;

  case 520:

    {
;}
    break;

  case 521:

    {
;}
    break;

  case 522:

    {
;}
    break;

  case 523:

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


