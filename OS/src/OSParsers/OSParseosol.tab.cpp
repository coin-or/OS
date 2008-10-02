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
#define YYLAST   707

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  150
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  430
/* YYNRULES -- Number of rules.  */
#define YYNRULES  657
/* YYNRULES -- Number of states.  */
#define YYNSTATES  1121

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
     469,   470,   475,   476,   479,   480,   484,   485,   488,   490,
     494,   496,   497,   500,   502,   504,   506,   508,   510,   512,
     515,   516,   521,   526,   528,   533,   536,   537,   540,   541,
     546,   547,   550,   552,   554,   556,   557,   562,   563,   568,
     569,   574,   576,   579,   582,   584,   588,   590,   591,   594,
     596,   598,   600,   602,   604,   606,   608,   610,   612,   614,
     616,   618,   620,   622,   624,   628,   630,   631,   632,   637,
     639,   642,   643,   648,   649,   654,   657,   659,   661,   664,
     665,   670,   676,   678,   683,   684,   687,   688,   694,   700,
     702,   707,   708,   711,   712,   718,   724,   726,   731,   732,
     735,   736,   742,   748,   750,   755,   756,   759,   760,   766,
     772,   774,   779,   780,   783,   784,   790,   796,   798,   803,
     804,   807,   811,   813,   814,   817,   819,   821,   823,   824,
     829,   830,   835,   836,   841,   844,   846,   852,   854,   859,
     860,   863,   867,   869,   870,   873,   875,   877,   879,   880,
     885,   886,   891,   892,   897,   900,   902,   908,   910,   915,
     916,   919,   923,   925,   926,   929,   931,   933,   935,   936,
     941,   942,   947,   948,   953,   956,   958,   964,   966,   971,
     972,   975,   979,   981,   982,   985,   987,   989,   991,   992,
     997,   998,  1003,  1004,  1009,  1012,  1014,  1020,  1022,  1027,
    1028,  1031,  1032,  1038,  1044,  1046,  1051,  1052,  1055,  1056,
    1062,  1068,  1070,  1075,  1076,  1079,  1080,  1086,  1091,  1093,
    1098,  1101,  1102,  1105,  1106,  1111,  1112,  1115,  1117,  1119,
    1121,  1122,  1127,  1128,  1133,  1134,  1139,  1141,  1144,  1145,
    1149,  1151,  1152,  1155,  1157,  1159,  1161,  1166,  1171,  1176,
    1180,  1182,  1187,  1188,  1192,  1194,  1195,  1200,  1206,  1208,
    1209,  1215,  1220,  1221,  1224,  1228,  1230,  1231,  1232,  1236,
    1238,  1240,  1245,  1246,  1251,  1254,  1256,  1257,  1266,  1267,
    1270,  1274,  1275,  1278,  1280,  1282,  1286,  1290,  1293,  1295,
    1296,  1300,  1301,  1304,  1306,  1308,  1310,  1312,  1314,  1316,
    1318,  1319,  1325,  1326,  1331,  1332,  1337,  1338,  1343,  1344,
    1349,  1350,  1355,  1356,  1361,  1365,  1369,  1370,  1373,  1375,
    1377,  1379,  1381,  1385,  1389,  1393,  1397,  1400,  1402,  1403,
    1407,  1408,  1413,  1419,  1421,  1422,  1431,  1432,  1435,  1439,
    1440,  1443,  1445,  1447,  1451,  1455,  1458,  1460,  1461,  1470,
    1471,  1474,  1478,  1479,  1482,  1484,  1486,  1490,  1494,  1497,
    1499,  1500,  1504,  1505,  1508,  1510,  1512,  1514,  1516,  1518,
    1520,  1522,  1527,  1531,  1535,  1539,  1543,  1547,  1551,  1555,
    1559,  1560,  1563,  1565,  1567,  1569,  1571,  1575,  1579,  1583,
    1587,  1590,  1592,  1593,  1597,  1598,  1603,  1609,  1611,  1612,
    1621,  1622,  1625,  1629,  1630,  1633,  1635,  1637,  1641,  1645,
    1648,  1650,  1651,  1660,  1661,  1664,  1668,  1669,  1672,  1674,
    1676,  1680,  1684,  1687,  1689,  1690,  1694,  1695,  1698,  1700,
    1702,  1704,  1706,  1708,  1710,  1712,  1717,  1721,  1725,  1729,
    1733,  1737,  1741,  1745,  1749,  1750,  1753,  1755,  1757,  1759,
    1761,  1765,  1769,  1773,  1777,  1780,  1782,  1783,  1789,  1794,
    1795,  1798,  1802,  1803,  1806,  1808,  1810,  1812,  1814,  1816,
    1818,  1822,  1826,  1830,  1834,  1838,  1842,  1845
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     151,     0,    -1,   152,     8,   153,    12,    -1,   152,     9,
      -1,    10,    -1,    10,    11,    -1,   154,   219,   267,   292,
     432,    -1,    -1,   155,   156,    -1,    43,    -1,     8,   157,
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
      40,     3,   263,     7,    -1,    -1,   265,     9,    -1,    -1,
     266,     8,    76,    -1,    -1,   268,   269,    -1,    47,    -1,
       8,   270,    48,    -1,     9,    -1,    -1,   270,   271,    -1,
     272,    -1,   276,    -1,   273,    -1,   274,    -1,    85,    -1,
       9,    -1,     8,    86,    -1,    -1,     8,     5,   275,    86,
      -1,   277,   278,     8,   279,    -1,    73,    -1,    15,     7,
       5,     7,    -1,   280,    74,    -1,    -1,   280,   281,    -1,
      -1,    75,   282,   283,   291,    -1,    -1,   283,   284,    -1,
     285,    -1,   287,    -1,   289,    -1,    -1,    36,     3,   286,
       7,    -1,    -1,    38,     3,   288,     7,    -1,    -1,    40,
       3,   290,     7,    -1,     9,    -1,     8,    76,    -1,   293,
     294,    -1,    49,    -1,     8,   295,    50,    -1,     9,    -1,
      -1,   295,   296,    -1,   297,    -1,   304,    -1,   308,    -1,
     314,    -1,   320,    -1,   326,    -1,   332,    -1,   338,    -1,
     353,    -1,   368,    -1,   383,    -1,   398,    -1,   404,    -1,
     410,    -1,   416,    -1,   298,   299,   301,    -1,    87,    -1,
      -1,    -1,    39,     3,   300,     7,    -1,     9,    -1,     8,
      88,    -1,    -1,     8,     6,   302,    88,    -1,    -1,     8,
       5,   303,    88,    -1,   305,   306,    -1,    89,    -1,     9,
      -1,     8,    90,    -1,    -1,     8,     4,   307,    90,    -1,
     309,   310,     8,   311,    92,    -1,    91,    -1,    16,     7,
       5,     7,    -1,    -1,   311,   312,    -1,    -1,    61,     8,
       4,   313,    62,    -1,   315,   316,     8,   317,    94,    -1,
      93,    -1,    17,     7,     5,     7,    -1,    -1,   317,   318,
      -1,    -1,    97,     8,     4,   319,    98,    -1,   321,   322,
       8,   323,    96,    -1,    95,    -1,    17,     7,     5,     7,
      -1,    -1,   323,   324,    -1,    -1,    97,     8,     4,   325,
      98,    -1,   327,   328,     8,   329,   102,    -1,   101,    -1,
      17,     7,     5,     7,    -1,    -1,   329,   330,    -1,    -1,
      97,     8,     4,   331,    98,    -1,   333,   334,     8,   335,
     104,    -1,   103,    -1,    17,     7,     5,     7,    -1,    -1,
     335,   336,    -1,    -1,    97,     8,     4,   337,    98,    -1,
     339,   340,     8,   341,   110,    -1,   109,    -1,    18,     7,
       5,     7,    -1,    -1,   341,   342,    -1,   343,   344,   352,
      -1,    99,    -1,    -1,   344,   345,    -1,   346,    -1,   348,
      -1,   350,    -1,    -1,    19,     3,   347,     7,    -1,    -1,
      20,     3,   349,     7,    -1,    -1,    21,     3,   351,     7,
      -1,     8,   100,    -1,     9,    -1,   354,   355,     8,   356,
     112,    -1,   111,    -1,    18,     7,     5,     7,    -1,    -1,
     356,   357,    -1,   358,   359,   367,    -1,    99,    -1,    -1,
     359,   360,    -1,   361,    -1,   363,    -1,   365,    -1,    -1,
      19,     3,   362,     7,    -1,    -1,    20,     3,   364,     7,
      -1,    -1,    21,     3,   366,     7,    -1,     8,   100,    -1,
       9,    -1,   369,   370,     8,   371,   114,    -1,   113,    -1,
      18,     7,     5,     7,    -1,    -1,   371,   372,    -1,   373,
     374,   382,    -1,    99,    -1,    -1,   374,   375,    -1,   376,
      -1,   378,    -1,   380,    -1,    -1,    19,     3,   377,     7,
      -1,    -1,    20,     3,   379,     7,    -1,    -1,    21,     3,
     381,     7,    -1,     8,   100,    -1,     9,    -1,   384,   385,
       8,   386,   116,    -1,   115,    -1,    18,     7,     5,     7,
      -1,    -1,   386,   387,    -1,   388,   389,   397,    -1,    99,
      -1,    -1,   389,   390,    -1,   391,    -1,   393,    -1,   395,
      -1,    -1,    19,     3,   392,     7,    -1,    -1,    20,     3,
     394,     7,    -1,    -1,    21,     3,   396,     7,    -1,     8,
     100,    -1,     9,    -1,   399,   400,     8,   401,   108,    -1,
     107,    -1,    17,     7,     5,     7,    -1,    -1,   401,   402,
      -1,    -1,    97,     8,     4,   403,    98,    -1,   405,   406,
       8,   407,   106,    -1,   105,    -1,    17,     7,     5,     7,
      -1,    -1,   407,   408,    -1,    -1,    97,     8,     4,   409,
      98,    -1,   411,   412,     8,   413,   118,    -1,   117,    -1,
      25,     7,     5,     7,    -1,    -1,   413,   414,    -1,    -1,
     119,     8,     4,   415,   120,    -1,   417,   418,     8,   419,
      -1,    73,    -1,    15,     7,     5,     7,    -1,   420,    74,
      -1,    -1,   420,   421,    -1,    -1,    75,   422,   423,   431,
      -1,    -1,   423,   424,    -1,   425,    -1,   427,    -1,   429,
      -1,    -1,    36,     3,   426,     7,    -1,    -1,    38,     3,
     428,     7,    -1,    -1,    40,     3,   430,     7,    -1,     9,
      -1,     8,    76,    -1,    -1,   433,   434,   439,    -1,    51,
      -1,    -1,   434,   435,    -1,   436,    -1,   437,    -1,   438,
      -1,    27,     7,     5,     7,    -1,    29,     7,     5,     7,
      -1,    28,     7,     5,     7,    -1,     8,   440,    52,    -1,
       9,    -1,   441,   491,   529,   567,    -1,    -1,   442,   443,
     444,    -1,   121,    -1,    -1,    30,     7,     5,     7,    -1,
       8,   445,   457,   465,   122,    -1,     9,    -1,    -1,   123,
     446,     8,   447,   124,    -1,    33,     7,     5,     7,    -1,
      -1,   447,   448,    -1,   449,   450,   456,    -1,   125,    -1,
      -1,    -1,   450,   451,   452,    -1,   453,    -1,   454,    -1,
      37,     7,     5,     7,    -1,    -1,    38,     3,   455,     7,
      -1,     8,   126,    -1,     9,    -1,    -1,   127,    33,     7,
       5,     7,     8,   458,   128,    -1,    -1,   458,   459,    -1,
     125,   460,   464,    -1,    -1,   460,   461,    -1,   462,    -1,
     463,    -1,    37,     3,     7,    -1,    38,     3,     7,    -1,
       8,   126,    -1,     9,    -1,    -1,    75,   466,   482,    -1,
      -1,   466,   467,    -1,   468,    -1,   470,    -1,   472,    -1,
     474,    -1,   476,    -1,   478,    -1,   480,    -1,    -1,    33,
       7,     5,   469,     7,    -1,    -1,    36,     3,   471,     7,
      -1,    -1,    38,     3,   473,     7,    -1,    -1,    22,     3,
     475,     7,    -1,    -1,    23,     3,   477,     7,    -1,    -1,
      24,     3,   479,     7,    -1,    -1,    40,     3,   481,     7,
      -1,     8,   483,    76,    -1,   125,   484,   490,    -1,    -1,
     484,   485,    -1,   486,    -1,   487,    -1,   488,    -1,   489,
      -1,    37,     5,     7,    -1,    38,     3,     7,    -1,    41,
       3,     7,    -1,    42,     3,     7,    -1,     8,   126,    -1,
       9,    -1,    -1,   129,   492,   493,    -1,    -1,    31,     7,
       5,     7,    -1,     8,   494,   502,   510,   130,    -1,     9,
      -1,    -1,   131,    34,     7,     5,     7,     8,   495,   132,
      -1,    -1,   495,   496,    -1,   133,   497,   501,    -1,    -1,
     497,   498,    -1,   499,    -1,   500,    -1,    37,     3,     7,
      -1,    38,     3,     7,    -1,     8,   134,    -1,     9,    -1,
      -1,   135,    34,     7,     5,     7,     8,   503,   136,    -1,
      -1,   503,   504,    -1,   133,   505,   509,    -1,    -1,   505,
     506,    -1,   507,    -1,   508,    -1,    37,     3,     7,    -1,
      38,     3,     7,    -1,     8,   134,    -1,     9,    -1,    -1,
      75,   511,   520,    -1,    -1,   511,   512,    -1,   513,    -1,
     514,    -1,   515,    -1,   516,    -1,   517,    -1,   518,    -1,
     519,    -1,    34,     7,     5,     7,    -1,    36,     3,     7,
      -1,    38,     3,     7,    -1,    22,     3,     7,    -1,    23,
       3,     7,    -1,    24,     3,     7,    -1,    40,     3,     7,
      -1,     8,   521,    76,    -1,   133,   522,   528,    -1,    -1,
     522,   523,    -1,   524,    -1,   525,    -1,   526,    -1,   527,
      -1,    37,     3,     7,    -1,    38,     3,     7,    -1,    41,
       3,     7,    -1,    42,     3,     7,    -1,     8,   126,    -1,
       9,    -1,    -1,   137,   530,   531,    -1,    -1,    32,     7,
       5,     7,    -1,     8,   532,   540,   548,   138,    -1,     9,
      -1,    -1,   139,    35,     7,     5,     7,     8,   533,   140,
      -1,    -1,   533,   534,    -1,   141,   535,   539,    -1,    -1,
     535,   536,    -1,   537,    -1,   538,    -1,    37,     3,     7,
      -1,    38,     3,     7,    -1,     8,   142,    -1,     9,    -1,
      -1,   143,    35,     7,     5,     7,     8,   541,   144,    -1,
      -1,   541,   542,    -1,   141,   543,   547,    -1,    -1,   543,
     544,    -1,   545,    -1,   546,    -1,    37,     3,     7,    -1,
      38,     3,     7,    -1,     8,   142,    -1,     9,    -1,    -1,
      75,   549,   558,    -1,    -1,   549,   550,    -1,   551,    -1,
     552,    -1,   553,    -1,   554,    -1,   555,    -1,   556,    -1,
     557,    -1,    35,     7,     5,     7,    -1,    36,     3,     7,
      -1,    38,     3,     7,    -1,    22,     3,     7,    -1,    23,
       3,     7,    -1,    24,     3,     7,    -1,    40,     3,     7,
      -1,     8,   559,    76,    -1,   141,   560,   566,    -1,    -1,
     560,   561,    -1,   562,    -1,   563,    -1,   564,    -1,   565,
      -1,    37,     3,     7,    -1,    38,     3,     7,    -1,    41,
       3,     7,    -1,    42,     3,     7,    -1,     8,   142,    -1,
       9,    -1,    -1,   145,   568,     8,   569,   146,    -1,    26,
       7,     5,     7,    -1,    -1,   569,   570,    -1,   147,   571,
     579,    -1,    -1,   571,   572,    -1,   573,    -1,   574,    -1,
     575,    -1,   576,    -1,   577,    -1,   578,    -1,    36,     3,
       7,    -1,    38,     3,     7,    -1,    22,     3,     7,    -1,
      23,     3,     7,    -1,    24,     3,     7,    -1,    40,     3,
       7,    -1,     8,   148,    -1,     9,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   126,   126,   127,   129,   130,   132,   134,   134,   136,
     147,   148,   150,   150,   152,   152,   152,   152,   152,   153,
     153,   153,   153,   153,   153,   156,   158,   167,   168,   169,
     169,   172,   174,   183,   184,   185,   185,   188,   190,   199,
     200,   201,   201,   204,   206,   216,   216,   216,   218,   219,
     221,   221,   224,   226,   235,   236,   237,   237,   240,   242,
     251,   252,   253,   253,   256,   258,   267,   268,   269,   269,
     272,   274,   283,   284,   285,   285,   288,   290,   299,   300,
     301,   301,   304,   306,   316,   316,   316,   318,   319,   321,
     321,   324,   326,   336,   342,   347,   347,   350,   349,   365,
     365,   367,   367,   367,   370,   369,   381,   380,   392,   391,
     402,   402,   405,   405,   407,   418,   419,   421,   421,   423,
     423,   423,   423,   423,   425,   427,   437,   437,   437,   439,
     440,   441,   441,   442,   442,   445,   447,   457,   457,   457,
     459,   460,   461,   461,   462,   462,   465,   467,   477,   477,
     477,   479,   480,   481,   481,   482,   482,   485,   487,   496,
     497,   498,   498,   501,   503,   513,   519,   524,   524,   527,
     526,   541,   541,   543,   543,   543,   546,   545,   557,   556,
     569,   568,   579,   579,   579,   579,   582,   582,   584,   595,
     596,   598,   598,   600,   600,   602,   602,   604,   613,   614,
     615,   615,   617,   619,   629,   635,   640,   640,   643,   642,
     657,   657,   659,   659,   659,   662,   661,   673,   672,   684,
     683,   694,   694,   697,   699,   709,   710,   712,   712,   714,
     714,   714,   714,   714,   715,   715,   715,   715,   715,   716,
     716,   716,   716,   716,   719,   721,   731,   731,   731,   733,
     734,   735,   735,   736,   736,   738,   740,   749,   750,   751,
     751,   753,   755,   765,   771,   771,   774,   773,   786,   789,
     799,   804,   804,   806,   806,   818,   821,   831,   836,   836,
     838,   838,   850,   853,   862,   867,   867,   870,   869,   881,
     884,   894,   899,   899,   902,   901,   913,   916,   926,   934,
     934,   936,   948,   954,   954,   956,   956,   956,   959,   958,
     970,   969,   981,   980,   992,   992,   995,   998,  1008,  1015,
    1015,  1017,  1029,  1035,  1035,  1037,  1037,  1037,  1040,  1039,
    1051,  1050,  1062,  1061,  1073,  1073,  1076,  1079,  1089,  1097,
    1097,  1099,  1111,  1117,  1117,  1119,  1119,  1119,  1122,  1121,
    1133,  1132,  1144,  1143,  1155,  1155,  1158,  1161,  1171,  1178,
    1178,  1180,  1192,  1198,  1198,  1200,  1200,  1200,  1203,  1202,
    1214,  1213,  1225,  1224,  1236,  1236,  1239,  1242,  1252,  1257,
    1257,  1260,  1259,  1271,  1274,  1284,  1289,  1289,  1292,  1291,
    1303,  1307,  1317,  1322,  1322,  1325,  1324,  1336,  1338,  1348,
    1354,  1359,  1359,  1362,  1361,  1376,  1376,  1378,  1378,  1378,
    1381,  1380,  1392,  1391,  1403,  1402,  1413,  1413,  1416,  1416,
    1418,  1428,  1428,  1430,  1430,  1430,  1432,  1436,  1440,  1444,
    1444,  1446,  1449,  1449,  1451,  1455,  1455,  1464,  1467,  1469,
    1469,  1474,  1483,  1483,  1485,  1494,  1500,  1500,  1500,  1502,
    1502,  1504,  1521,  1520,  1530,  1531,  1534,  1534,  1537,  1537,
    1539,  1541,  1541,  1543,  1543,  1545,  1549,  1553,  1553,  1556,
    1556,  1558,  1558,  1561,  1562,  1563,  1564,  1565,  1566,  1567,
    1570,  1569,  1574,  1573,  1578,  1577,  1582,  1581,  1586,  1585,
    1590,  1589,  1594,  1593,  1598,  1600,  1602,  1602,  1605,  1606,
    1607,  1608,  1610,  1614,  1618,  1622,  1626,  1626,  1628,  1628,
    1630,  1630,  1634,  1636,  1639,  1639,  1642,  1642,  1644,  1646,
    1646,  1648,  1648,  1650,  1654,  1658,  1658,  1661,  1661,  1664,
    1664,  1666,  1668,  1668,  1670,  1670,  1672,  1676,  1680,  1680,
    1683,  1683,  1685,  1685,  1688,  1689,  1690,  1691,  1692,  1693,
    1694,  1696,  1700,  1704,  1708,  1712,  1716,  1720,  1725,  1727,
    1729,  1729,  1732,  1733,  1734,  1735,  1737,  1741,  1745,  1749,
    1753,  1753,  1755,  1755,  1757,  1757,  1761,  1763,  1765,  1765,
    1768,  1768,  1770,  1772,  1772,  1774,  1774,  1776,  1780,  1784,
    1784,  1787,  1787,  1790,  1790,  1792,  1794,  1794,  1796,  1796,
    1798,  1802,  1806,  1806,  1809,  1809,  1811,  1811,  1814,  1815,
    1816,  1817,  1818,  1819,  1820,  1822,  1826,  1830,  1834,  1838,
    1842,  1846,  1851,  1853,  1855,  1855,  1858,  1859,  1860,  1861,
    1863,  1867,  1871,  1875,  1879,  1879,  1882,  1882,  1884,  1888,
    1888,  1890,  1892,  1892,  1895,  1896,  1897,  1898,  1899,  1900,
    1902,  1906,  1910,  1914,  1918,  1922,  1927,  1927
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
  "@28", "othersystemoptionend", "@29", "@30", "osolservice",
  "servicehead", "servicebody", "servicecontent", "serviceoption",
  "servicetype", "servicetypehead", "servicetypebody", "@31",
  "otherserviceoptions", "otherserviceoptionshead",
  "numberofotherserviceoptions", "otherserviceoptionsbody",
  "otherserviceoptionslist", "otherserviceoption", "@32",
  "otherserviceattributes", "otherserviceattribute",
  "serviceoptionnameatt", "@33", "serviceoptionvalueatt", "@34",
  "serviceoptiondescriptionatt", "@35", "otherserviceoptionsend",
  "osoljob", "jobhead", "jobbody", "jobcontent", "joboption", "maxtime",
  "maxtimehead", "maxtimeunit", "@36", "maxtimebody", "@37", "@38",
  "scheduledstarttime", "starttimehead", "starttimebody", "@39",
  "dependencies", "dependencieshead", "numberofjobidsatt",
  "dependencieslist", "dependencyjobid", "@40", "requireddirectories",
  "requireddirectorieshead", "numberofreqdirpathsatt", "reqdirpathlist",
  "reqdirpath", "@41", "requiredfiles", "requiredfileshead",
  "numberofreqfilespathsatt", "reqfilespathlist", "reqfilepath", "@42",
  "directoriestomake", "directoriestomakehead",
  "numberofdirtomakepathsatt", "dirtomakepathlist", "dirtomakepath", "@43",
  "filestocreate", "filestocreatehead", "numberoffilestomakepathsatt",
  "filestomakepathlist", "filestomakepath", "@44",
  "inputdirectoriestomove", "inputdirectoriestomovehead",
  "numberofindirtomovepathpairsatt", "indirtomovepathpairlist",
  "indirtomovepathpair", "indirtomovepathpairhead",
  "indirtomovepathpairattlist", "indirtomovepathpairatt",
  "indirtomovefromatt", "@45", "indirtomovetoatt", "@46",
  "indirtomovemakecopyatt", "@47", "indirtomovepathpairend",
  "inputfilestomove", "inputfilestomovehead",
  "numberofinfilestomovepathpairsatt", "infilestomovepathpairlist",
  "infilestomovepathpair", "infilestomovepathpairhead",
  "infilestomovepathpairattlist", "infilestomovepathpairatt",
  "infilestomovefromatt", "@48", "infilestomovetoatt", "@49",
  "infilestomovemakecopyatt", "@50", "infilestomovepathpairend",
  "outputdirectoriestomove", "outputdirectoriestomovehead",
  "numberofoutdirtomovepathpairsatt", "outdirtomovepathpairlist",
  "outdirtomovepathpair", "outdirtomovepathpairhead",
  "outdirtomovepathpairattlist", "outdirtomovepathpairatt",
  "outdirtomovefromatt", "@51", "outdirtomovetoatt", "@52",
  "outdirtomovemakecopyatt", "@53", "outdirtomovepathpairend",
  "outputfilestomove", "outputfilestomovehead",
  "numberofoutfilestomovepathpairsatt", "outfilestomovepathpairlist",
  "outfilestomovepathpair", "outfilestomovepathpairhead",
  "outfilestomovepathpairattlist", "outfilestomovepathpairatt",
  "outfilestomovefromatt", "@54", "outfilestomovetoatt", "@55",
  "outfilestomovemakecopyatt", "@56", "outfilestomovepathpairend",
  "filestodelete", "filestodeletehead", "numberoffilestodeletepathsatt",
  "filestodeletepathlist", "filestodeletepath", "@57",
  "directoriestodelete", "directoriestodeletehead",
  "numberofdirtodeletepathsatt", "dirtodeletepathlist", "dirtodeletepath",
  "@58", "processestokill", "processestokillhead",
  "numberofprocesstokillatt", "processestokilllist", "processtokill",
  "@59", "otherjoboptions", "otherjoboptionshead",
  "numberofotherjoboptions", "otherjoboptionsbody", "otherjoboptionslist",
  "otherjoboption", "@60", "otherjobattributes", "otherjobattribute",
  "joboptionnameatt", "@61", "joboptionvalueatt", "@62",
  "joboptiondescriptionatt", "@63", "otherjoboptionsend",
  "osoloptimization", "optimizationhead", "optimizationattlist",
  "optimizationatt", "optimizationnvar", "optimizationncon",
  "optimizationnobj", "optimizationbody", "optimizationcontent",
  "variables", "variablesstart", "numberofothervariablesatt",
  "restofvariables", "initialvariablevalues", "numberofvar", "varlist",
  "initvarvalue", "varstart", "initvarvalueattlist", "@64",
  "initvarvalueatt", "initvarvalueidxatt", "initvarvaluevalueatt", "@65",
  "initvarvalueend", "initialvariablevaluesstring", "varstrlist",
  "initvarstrvalue", "initvarstrvalueattlist", "initvarstrvalueatt",
  "initvarstrvalueidxatt", "initvarstrvaluevalueatt", "initvarstrvalueend",
  "othervariableoptions", "othervariableoptionsattlist",
  "othervariableoptionsatt", "othervariableoptionnumberofvar", "@66",
  "othervariableoptionname", "@67", "othervariableoptionvalue", "@68",
  "othervariableoptionsolver", "@69", "othervariableoptioncategory", "@70",
  "othervariableoptiontype", "@71", "othervariableoptiondescription",
  "@72", "restofothervariableoptions", "othervariableoptionsvarlist",
  "othervaroptionattlist", "othervaroptionatt", "othervaroptionidx",
  "othervaroptionvalue", "othervaroptionlbvalue", "othervaroptionubvalue",
  "othervaroptionend", "objectives", "numberofotherobjectivesatt",
  "restofobjectives", "initialobjectivevalues", "objvaluelist",
  "initobjvalue", "initobjvalueattlist", "initobjvalueatt",
  "initobjvalueidxatt", "initobjvaluevalueatt", "initobjvalueend",
  "initialobjectivebounds", "objboundlist", "initobjbound",
  "initobjboundattlist", "initobjboundatt", "initobjboundidxatt",
  "initobjboundvalueatt", "initobjboundend", "otherobjectiveoptions",
  "otherobjectiveoptionsattlist", "otherobjectiveoptionsatt",
  "otherobjectiveoptionnumberofvar", "otherobjectiveoptionname",
  "otherobjectiveoptionvalue", "otherobjectiveoptionsolver",
  "otherobjectiveoptioncategory", "otherobjectiveoptiontype",
  "otherobjectiveoptiondescription", "restofotherobjectiveoptions",
  "otherobjectiveoptionsvarlist", "otherobjoptionattlist",
  "otherobjoptionatt", "otherobjoptionidx", "otherobjoptionvalue",
  "otherobjoptionlbvalue", "otherobjoptionubvalue", "otherobjoptionend",
  "constraints", "numberofotherconstraintsatt", "restofconstraints",
  "initialconstraintvalues", "conlist", "initconvalue",
  "initconvalueattlist", "initconvalueatt", "initconvalueidxatt",
  "initconvaluevalueatt", "initconvalueend", "initialdualvalues",
  "duallist", "initdualvalue", "initdualvalueattlist", "initdualvalueatt",
  "initdualvalueidxatt", "initdualvaluevalueatt", "initdualvalueend",
  "otherconstraintoptions", "otherconstraintoptionsattlist",
  "otherconstraintoptionsatt", "otherconstraintoptionnumberofvar",
  "otherconstraintoptionname", "otherconstraintoptionvalue",
  "otherconstraintoptionsolver", "otherconstraintoptioncategory",
  "otherconstraintoptiontype", "otherconstraintoptiondescription",
  "restofotherconstraintoptions", "otherconstraintoptionsvarlist",
  "otherconoptionattlist", "otherconoptionatt", "otherconoptionidx",
  "otherconoptionvalue", "otherconoptionlbvalue", "otherconoptionubvalue",
  "otherconoptionend", "solveroptions", "numberofsolveroptionsatt",
  "solveroptionlist", "solveroption", "solveroptionattlist",
  "solveroptionatt", "solveroptionname", "solveroptionvalue",
  "solveroptionsolver", "solveroptioncategory", "solveroptiontype",
  "solveroptiondescription", "solveroptionend", 0
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
     263,   262,   265,   264,   266,   264,   267,   267,   268,   269,
     269,   270,   270,   271,   271,   272,   272,   273,   274,   274,
     275,   274,   276,   277,   278,   279,   280,   280,   282,   281,
     283,   283,   284,   284,   284,   286,   285,   288,   287,   290,
     289,   291,   291,   292,   293,   294,   294,   295,   295,   296,
     296,   296,   296,   296,   296,   296,   296,   296,   296,   296,
     296,   296,   296,   296,   297,   298,   299,   300,   299,   301,
     301,   302,   301,   303,   301,   304,   305,   306,   306,   307,
     306,   308,   309,   310,   311,   311,   313,   312,   314,   315,
     316,   317,   317,   319,   318,   320,   321,   322,   323,   323,
     325,   324,   326,   327,   328,   329,   329,   331,   330,   332,
     333,   334,   335,   335,   337,   336,   338,   339,   340,   341,
     341,   342,   343,   344,   344,   345,   345,   345,   347,   346,
     349,   348,   351,   350,   352,   352,   353,   354,   355,   356,
     356,   357,   358,   359,   359,   360,   360,   360,   362,   361,
     364,   363,   366,   365,   367,   367,   368,   369,   370,   371,
     371,   372,   373,   374,   374,   375,   375,   375,   377,   376,
     379,   378,   381,   380,   382,   382,   383,   384,   385,   386,
     386,   387,   388,   389,   389,   390,   390,   390,   392,   391,
     394,   393,   396,   395,   397,   397,   398,   399,   400,   401,
     401,   403,   402,   404,   405,   406,   407,   407,   409,   408,
     410,   411,   412,   413,   413,   415,   414,   416,   417,   418,
     419,   420,   420,   422,   421,   423,   423,   424,   424,   424,
     426,   425,   428,   427,   430,   429,   431,   431,   432,   432,
     433,   434,   434,   435,   435,   435,   436,   437,   438,   439,
     439,   440,   441,   441,   442,   443,   443,   444,   444,   445,
     445,   446,   447,   447,   448,   449,   450,   451,   450,   452,
     452,   453,   455,   454,   456,   456,   457,   457,   458,   458,
     459,   460,   460,   461,   461,   462,   463,   464,   464,   465,
     465,   466,   466,   467,   467,   467,   467,   467,   467,   467,
     469,   468,   471,   470,   473,   472,   475,   474,   477,   476,
     479,   478,   481,   480,   482,   483,   484,   484,   485,   485,
     485,   485,   486,   487,   488,   489,   490,   490,   491,   491,
     492,   492,   493,   493,   494,   494,   495,   495,   496,   497,
     497,   498,   498,   499,   500,   501,   501,   502,   502,   503,
     503,   504,   505,   505,   506,   506,   507,   508,   509,   509,
     510,   510,   511,   511,   512,   512,   512,   512,   512,   512,
     512,   513,   514,   515,   516,   517,   518,   519,   520,   521,
     522,   522,   523,   523,   523,   523,   524,   525,   526,   527,
     528,   528,   529,   529,   530,   530,   531,   531,   532,   532,
     533,   533,   534,   535,   535,   536,   536,   537,   538,   539,
     539,   540,   540,   541,   541,   542,   543,   543,   544,   544,
     545,   546,   547,   547,   548,   548,   549,   549,   550,   550,
     550,   550,   550,   550,   550,   551,   552,   553,   554,   555,
     556,   557,   558,   559,   560,   560,   561,   561,   561,   561,
     562,   563,   564,   565,   566,   566,   567,   567,   568,   569,
     569,   570,   571,   571,   572,   572,   572,   572,   572,   572,
     573,   574,   575,   576,   577,   578,   579,   579
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
       0,     4,     0,     2,     0,     3,     0,     2,     1,     3,
       1,     0,     2,     1,     1,     1,     1,     1,     1,     2,
       0,     4,     4,     1,     4,     2,     0,     2,     0,     4,
       0,     2,     1,     1,     1,     0,     4,     0,     4,     0,
       4,     1,     2,     2,     1,     3,     1,     0,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     3,     1,     0,     0,     4,     1,
       2,     0,     4,     0,     4,     2,     1,     1,     2,     0,
       4,     5,     1,     4,     0,     2,     0,     5,     5,     1,
       4,     0,     2,     0,     5,     5,     1,     4,     0,     2,
       0,     5,     5,     1,     4,     0,     2,     0,     5,     5,
       1,     4,     0,     2,     0,     5,     5,     1,     4,     0,
       2,     3,     1,     0,     2,     1,     1,     1,     0,     4,
       0,     4,     0,     4,     2,     1,     5,     1,     4,     0,
       2,     3,     1,     0,     2,     1,     1,     1,     0,     4,
       0,     4,     0,     4,     2,     1,     5,     1,     4,     0,
       2,     3,     1,     0,     2,     1,     1,     1,     0,     4,
       0,     4,     0,     4,     2,     1,     5,     1,     4,     0,
       2,     3,     1,     0,     2,     1,     1,     1,     0,     4,
       0,     4,     0,     4,     2,     1,     5,     1,     4,     0,
       2,     0,     5,     5,     1,     4,     0,     2,     0,     5,
       5,     1,     4,     0,     2,     0,     5,     4,     1,     4,
       2,     0,     2,     0,     4,     0,     2,     1,     1,     1,
       0,     4,     0,     4,     0,     4,     1,     2,     0,     3,
       1,     0,     2,     1,     1,     1,     4,     4,     4,     3,
       1,     4,     0,     3,     1,     0,     4,     5,     1,     0,
       5,     4,     0,     2,     3,     1,     0,     0,     3,     1,
       1,     4,     0,     4,     2,     1,     0,     8,     0,     2,
       3,     0,     2,     1,     1,     3,     3,     2,     1,     0,
       3,     0,     2,     1,     1,     1,     1,     1,     1,     1,
       0,     5,     0,     4,     0,     4,     0,     4,     0,     4,
       0,     4,     0,     4,     3,     3,     0,     2,     1,     1,
       1,     1,     3,     3,     3,     3,     2,     1,     0,     3,
       0,     4,     5,     1,     0,     8,     0,     2,     3,     0,
       2,     1,     1,     3,     3,     2,     1,     0,     8,     0,
       2,     3,     0,     2,     1,     1,     3,     3,     2,     1,
       0,     3,     0,     2,     1,     1,     1,     1,     1,     1,
       1,     4,     3,     3,     3,     3,     3,     3,     3,     3,
       0,     2,     1,     1,     1,     1,     3,     3,     3,     3,
       2,     1,     0,     3,     0,     4,     5,     1,     0,     8,
       0,     2,     3,     0,     2,     1,     1,     3,     3,     2,
       1,     0,     8,     0,     2,     3,     0,     2,     1,     1,
       3,     3,     2,     1,     0,     3,     0,     2,     1,     1,
       1,     1,     1,     1,     1,     4,     3,     3,     3,     3,
       3,     3,     3,     3,     0,     2,     1,     1,     1,     1,
       3,     3,     3,     3,     2,     1,     0,     5,     4,     0,
       2,     3,     0,     2,     1,     1,     1,     1,     1,     1,
       3,     3,     3,     3,     3,     3,     2,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       0,     4,     0,     0,     5,     1,     7,     3,     9,     0,
     112,     0,     2,   114,   186,     0,    12,    11,     8,   188,
       0,     0,   117,   116,   113,     0,   224,   418,     0,   191,
     190,   187,     0,    10,    26,    32,    38,    44,    53,    59,
      65,    71,    77,    83,    92,    13,    14,     0,    15,     0,
      16,     0,    17,    45,    18,     0,    19,     0,    20,     0,
      21,     0,    22,     0,    23,    84,    24,     0,   420,     6,
     421,   227,   226,   223,     0,   115,   164,   125,   136,   147,
     158,   118,   119,   126,   120,   137,   121,   148,   122,     0,
     123,     0,     0,    27,    25,     0,    33,    31,     0,    39,
      37,     0,     0,     0,    54,    52,     0,    60,    58,     0,
      66,    64,     0,    72,    70,     0,    78,    76,     0,     0,
       0,     0,     0,     0,     0,   198,   189,   203,   197,   192,
     193,   195,   196,   194,     0,     0,     0,     0,     0,     0,
       0,     0,   159,   157,     0,     0,    29,    28,    35,    34,
      41,    40,    46,    50,    48,    43,    56,    55,    62,    61,
      68,    67,    74,    73,    80,    79,    85,    89,    87,    82,
       0,    95,   432,   430,     0,     0,     0,   422,   423,   424,
     425,   419,   225,   398,   245,   256,   262,   269,   276,   283,
     290,   384,   377,   297,   317,   337,   357,   391,   228,   229,
     246,   230,     0,   231,     0,   232,     0,   233,     0,   234,
       0,   235,     0,   236,     0,   237,     0,   238,     0,   239,
       0,   240,     0,   241,     0,   242,     0,   243,     0,   200,
     199,     0,     0,   127,     0,   129,   124,   138,     0,   140,
     135,   149,     0,   151,   146,   161,   160,     0,   167,     0,
       0,     0,     0,    51,     0,     0,     0,     0,     0,     0,
       0,    90,     0,     0,    91,     0,   434,     0,   508,   435,
       0,     0,     0,     0,     0,     0,   257,   255,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   206,     0,   133,   131,
     130,     0,   144,   142,   141,     0,   155,   153,   152,     0,
       0,   163,     0,    30,    36,    42,    47,    49,    57,    63,
      69,    75,    81,    86,    88,    93,    94,    97,    96,   429,
     510,   572,     0,     0,     0,     0,     0,   247,     0,   249,
     244,   259,   258,     0,   264,     0,   271,     0,   278,     0,
     285,     0,   292,     0,   299,     0,   319,     0,   339,     0,
     359,     0,   379,     0,   386,     0,   393,     0,   401,   201,
       0,   202,     0,   128,     0,     0,   139,     0,     0,   150,
       0,     0,   162,   165,   166,   169,   168,    99,     0,     0,
     574,   636,     0,   439,   438,   433,   426,   428,   427,     0,
     253,   251,   250,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   397,
       0,   204,   205,   208,   207,   134,   132,   145,   143,   156,
     154,   171,     0,     0,   514,   513,   509,     0,     0,     0,
     431,     0,     0,   456,   248,     0,     0,   260,   263,     0,
     261,   265,   270,   268,     0,   272,   277,   275,     0,   279,
     284,     0,   282,   286,   291,     0,   289,   293,   298,   302,
     296,   300,   303,   318,   322,   316,   320,   323,   338,   342,
     336,   340,   343,   358,   362,   356,   360,   363,   378,     0,
     376,   380,   385,     0,   383,   387,   392,   390,     0,   394,
     399,   400,   403,   402,   210,   182,     0,   110,     0,     0,
       0,   100,   101,   102,   103,    98,     0,     0,   527,     0,
     578,   577,   573,     0,     0,   436,     0,     0,     0,   469,
     254,   252,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   405,     0,     0,     0,     0,   172,
     173,   174,   175,   170,     0,     0,   111,   104,   106,   108,
     511,     0,     0,   540,     0,     0,   591,     0,   639,     0,
     442,     0,   471,     0,   266,   273,   280,   287,   294,     0,
     315,     0,     0,     0,   304,   305,   306,   307,   301,     0,
     335,     0,     0,     0,   324,   325,   326,   327,   321,     0,
     355,     0,     0,     0,   344,   345,   346,   347,   341,     0,
     375,     0,     0,     0,   364,   365,   366,   367,   361,   381,
     388,   395,     0,     0,   221,     0,     0,     0,   211,   212,
     213,   214,   209,   176,   178,   180,   183,     0,     0,     0,
       0,     0,     0,   542,     0,   575,     0,     0,   604,     0,
       0,     0,     0,     0,     0,   437,     0,     0,     0,     0,
       0,   314,   308,   310,   312,   334,   328,   330,   332,   354,
     348,   350,   352,   374,   368,   370,   372,     0,     0,     0,
       0,   416,     0,     0,     0,   406,   407,   408,   409,   404,
     222,   215,   217,   219,     0,     0,     0,   185,   105,   107,
     109,     0,     0,     0,   512,     0,     0,   606,     0,   638,
     637,   642,   640,   441,   440,   445,   443,   446,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   472,   473,   474,
     475,   476,   477,   478,   479,   470,   267,   274,   281,   288,
     295,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   382,   389,   396,   417,   410,   412,   414,
       0,     0,     0,   177,   179,   181,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   543,   544,   545,   546,
     547,   548,   549,   550,   541,     0,     0,     0,   576,     0,
     447,     0,   496,     0,   486,   488,   490,     0,   482,   484,
     492,   309,   311,   313,   329,   331,   333,   349,   351,   353,
     369,   371,   373,     0,     0,     0,   216,   218,   220,   516,
       0,   560,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     607,   608,   609,   610,   611,   612,   613,   614,   605,     0,
     657,     0,     0,     0,     0,     0,     0,   643,   644,   645,
     646,   647,   648,   649,   641,     0,   455,     0,   444,   458,
       0,   494,     0,     0,     0,   480,     0,     0,     0,   411,
     413,   415,     0,   529,     0,   558,   554,   555,   556,     0,
     552,   553,   557,   580,     0,   624,     0,     0,     0,     0,
       0,     0,     0,     0,   656,     0,     0,     0,     0,     0,
       0,   454,     0,     0,   448,   449,   450,     0,     0,   507,
       0,     0,     0,     0,   497,   498,   499,   500,   501,   495,
     487,   489,   491,     0,   483,   485,   493,   515,   519,   517,
       0,     0,   571,     0,     0,     0,     0,   561,   562,   563,
     564,   565,   559,   551,     0,   593,     0,   622,   618,   619,
     620,     0,   616,   617,   621,   652,   653,   654,   650,   651,
     655,     0,   452,   461,   457,   459,   506,     0,     0,     0,
       0,   481,     0,   532,   528,   530,   570,     0,     0,     0,
       0,   579,   583,   581,     0,     0,   635,     0,     0,     0,
       0,   625,   626,   627,   628,   629,   623,   615,     0,     0,
       0,   502,   503,   504,   505,     0,   526,     0,     0,   520,
     521,   522,   518,     0,   566,   567,   568,   569,     0,   596,
     592,   594,   634,     0,     0,     0,     0,   451,   453,     0,
     468,     0,     0,   462,   463,   464,   460,   525,     0,     0,
       0,   539,     0,     0,   533,   534,   535,   531,     0,   590,
       0,     0,   584,   585,   586,   582,     0,   630,   631,   632,
     633,   467,     0,     0,   523,   524,   538,     0,     0,   589,
       0,     0,     0,   603,     0,     0,   597,   598,   599,   595,
     465,   466,   536,   537,   587,   588,   602,     0,     0,   600,
     601
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,     9,    10,    11,    18,    25,    45,    46,
      47,    94,   249,    48,    49,    97,   250,    50,    51,   100,
     251,    52,    53,   102,   252,   155,   254,    54,    55,   105,
     255,    56,    57,   108,   256,    58,    59,   111,   257,    60,
      61,   114,   258,    62,    63,   117,   259,    64,    65,   119,
     260,   169,   262,    66,    67,   121,   264,   265,   338,   397,
     452,   531,   532,   658,   533,   659,   534,   660,   535,    14,
      15,    24,    32,    81,    82,    83,   136,   307,   236,   385,
     384,    84,    85,   138,   311,   240,   388,   387,    86,    87,
     140,   315,   244,   391,   390,    88,    89,   143,   319,    90,
      91,   145,   321,   322,   396,   451,   525,   569,   570,   714,
     571,   715,   572,   716,   573,   574,   575,    20,    21,    31,
      74,   129,   130,   131,   132,   304,   133,   134,   232,   381,
     382,   444,   524,   565,   648,   649,   780,   650,   781,   651,
     782,   652,    27,    28,    73,   123,   198,   199,   200,   274,
     409,   350,   466,   465,   201,   202,   277,   413,   203,   204,
     279,   415,   471,   676,   205,   206,   281,   417,   475,   677,
     207,   208,   283,   419,   479,   678,   209,   210,   285,   421,
     483,   679,   211,   212,   287,   423,   487,   680,   213,   214,
     289,   425,   491,   492,   557,   604,   605,   761,   606,   762,
     607,   763,   608,   215,   216,   291,   427,   496,   497,   558,
     614,   615,   764,   616,   765,   617,   766,   618,   217,   218,
     293,   429,   501,   502,   559,   624,   625,   767,   626,   768,
     627,   769,   628,   219,   220,   295,   431,   506,   507,   560,
     634,   635,   770,   636,   771,   637,   772,   638,   221,   222,
     297,   433,   511,   697,   223,   224,   299,   435,   515,   698,
     225,   226,   301,   437,   519,   699,   227,   228,   303,   439,
     440,   523,   564,   642,   705,   706,   833,   707,   834,   708,
     835,   709,    69,    70,   122,   177,   178,   179,   180,   181,
     267,   268,   269,   343,   405,   463,   547,   672,   736,   737,
     810,   887,   934,   935,   936,  1029,   888,   549,   937,   995,
    1030,  1063,  1064,  1065,  1066,   593,   674,   747,   748,   953,
     749,   896,   750,   897,   751,   892,   752,   893,   753,   894,
     754,   898,   755,   813,   890,   944,   945,   946,   947,   948,
     949,   341,   399,   456,   538,   902,   959,  1002,  1039,  1040,
    1041,  1042,   583,   960,  1005,  1043,  1074,  1075,  1076,  1077,
     664,   723,   796,   797,   798,   799,   800,   801,   802,   803,
     804,   842,   904,   967,   968,   969,   970,   971,   972,   401,
     458,   542,   586,   974,  1013,  1048,  1082,  1083,  1084,  1085,
     668,  1014,  1051,  1086,  1106,  1107,  1108,  1109,   728,   807,
     860,   861,   862,   863,   864,   865,   866,   867,   868,   916,
     976,  1021,  1022,  1023,  1024,  1025,  1026,   460,   544,   670,
     732,   809,   877,   878,   879,   880,   881,   882,   883,   884
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -94
static const yytype_int16 yypact[] =
{
      39,    20,    55,   141,   -94,   -94,    22,   -94,   -94,    59,
      30,   189,   -94,   -94,    34,   204,   -94,   -94,   -94,   -94,
      51,   206,   -94,   -94,   -94,   167,   -94,    91,   238,   -94,
     -94,   -94,   -20,   -94,   -94,   -94,   -94,   -94,   -94,   -94,
     -94,   -94,   -94,   -94,   -94,   -94,   -94,   240,   -94,   242,
     -94,   250,   -94,    54,   -94,   252,   -94,   254,   -94,   256,
     -94,   258,   -94,   260,   -94,   121,   -94,   149,   -94,   -94,
     -94,   -94,   -94,   -94,     3,   -94,   -94,   -94,   -94,   -94,
     -94,   -94,   -94,   117,   -94,   127,   -94,   135,   -94,   262,
     -94,   153,    18,   -94,   -94,    17,   -94,   -94,    16,   -94,
     -94,   175,   264,    15,   -94,   -94,    14,   -94,   -94,    13,
     -94,   -94,    12,   -94,   -94,    21,   -94,   -94,   220,   266,
     169,   177,    88,   -49,     1,   -94,   -94,   -94,   -94,   -94,
     -94,   -94,   -94,   -94,   168,   222,   268,   224,   270,   228,
     272,    -1,   -94,   -94,   230,   213,   -94,   -94,   -94,   -94,
     -94,   -94,   -94,   225,   -94,   -94,   -94,   -94,   -94,   -94,
     -94,   -94,   -94,   -94,   -94,   -94,   -94,   229,   -94,   -94,
     234,   -94,   114,   -94,   305,   310,   311,   -94,   -94,   -94,
     -94,   -94,   -94,   -94,   -94,   -94,   -94,   -94,   -94,   -94,
     -94,   -94,   -94,   -94,   -94,   -94,   -94,   -94,   -94,   -94,
     280,   -94,   274,   -94,   227,   -94,   303,   -94,   304,   -94,
     306,   -94,   307,   -94,   308,   -94,   309,   -94,   312,   -94,
     313,   -94,   315,   -94,   316,   -94,   297,   -94,   314,   -94,
     -94,   318,   320,   -94,     4,   -94,   -94,   -94,     9,   -94,
     -94,   -94,     2,   -94,   -94,   -94,   -94,   329,   -94,   281,
     283,   279,   331,   -94,   276,   284,   277,   285,   275,   287,
     333,   -94,   288,   335,   -94,   210,   -94,   292,   216,   317,
     343,   344,   345,   349,   278,    -4,   -94,   -94,   346,   347,
     351,   348,   352,   353,   355,   356,   358,   359,   361,   362,
     364,   365,   367,   368,   370,   371,   373,   374,   376,   377,
     379,   380,   382,   383,   289,   385,   -94,   386,   -94,   -94,
     -94,   387,   -94,   -94,   -94,   388,   -94,   -94,   -94,   319,
     389,   -94,   214,   -94,   -94,   -94,   -94,   -94,   -94,   -94,
     -94,   -94,   -94,   -94,   -94,   -94,   -94,   -94,   -94,   -94,
     323,   232,   390,   282,   391,   392,   393,   -94,    -3,   -94,
     -94,   -94,   -94,   396,   -94,   397,   -94,   399,   -94,   400,
     -94,   401,   -94,   402,   -94,   403,   -94,   404,   -94,   405,
     -94,   406,   -94,   407,   -94,   408,   -94,   409,   -94,   -94,
     410,   -94,   218,   -94,   337,   338,   -94,   298,   301,   -94,
     290,   302,   -94,   -94,   -94,   -94,   -94,   -94,   411,   286,
     334,   247,   414,   299,   -94,   -94,   -94,   -94,   -94,   413,
     -94,   -94,   -94,   336,   416,   -56,   417,    97,   418,   200,
     420,    11,   421,    36,   422,   -76,   423,   -62,   424,   -66,
     425,   -69,   426,    -7,   427,     8,   428,   180,   429,   -94,
     226,   -94,   -94,   -94,   -94,   -94,   -94,   -94,   -94,   -94,
     -94,   -94,   103,   432,   321,   -94,   -94,   431,   294,   395,
     -94,   433,   330,   322,   -94,   354,   357,   -94,   -94,   435,
     -94,   -94,   -94,   -94,   436,   -94,   -94,   -94,   438,   -94,
     -94,   439,   -94,   -94,   -94,   440,   -94,   -94,   -94,   -94,
     -94,   -94,   -94,   -94,   -94,   -94,   -94,   -94,   -94,   -94,
     -94,   -94,   -94,   -94,   -94,   -94,   -94,   -94,   -94,   442,
     -94,   -94,   -94,   443,   -94,   -94,   -94,   -94,   445,   -94,
     -94,   -94,   -94,   -94,   -94,   123,   363,   -94,   384,   451,
     452,   -94,   -94,   -94,   -94,   -94,   434,   430,   324,   453,
     326,   -94,   -94,   449,   454,   -94,   450,   455,   437,   394,
     -94,   -94,   456,   457,   462,   463,   464,   184,   187,   233,
     236,   467,   468,   469,   -94,   139,   471,   472,   473,   -94,
     -94,   -94,   -94,   -94,   470,   474,   -94,   -94,   -94,   -94,
     -94,   476,   444,   412,   477,   446,   342,   475,   -94,   481,
     -94,   482,   -94,   366,   -94,   -94,   -94,   -94,   -94,   398,
     -94,   487,   488,   489,   -94,   -94,   -94,   -94,   -94,   415,
     -94,   490,   491,   492,   -94,   -94,   -94,   -94,   -94,   419,
     -94,   493,   494,   496,   -94,   -94,   -94,   -94,   -94,   441,
     -94,   497,   498,   499,   -94,   -94,   -94,   -94,   -94,   -94,
     -94,   -94,   146,   447,   -94,   500,   501,   502,   -94,   -94,
     -94,   -94,   -94,   -94,   -94,   -94,   -94,   448,   503,   504,
     505,   508,   507,   -94,   378,   -94,   509,   483,   458,   510,
     158,   513,   182,   516,    96,   -94,   460,   459,   461,   465,
     466,   -94,   -94,   -94,   -94,   -94,   -94,   -94,   -94,   -94,
     -94,   -94,   -94,   -94,   -94,   -94,   -94,   478,   479,   480,
     484,   -94,   506,   522,   523,   -94,   -94,   -94,   -94,   -94,
     -94,   -94,   -94,   -94,   520,   521,   524,   -94,   -94,   -94,
     -94,   525,   529,     5,   -94,   530,   531,   -94,   339,   -94,
     -94,   -94,   -94,   -94,   -94,   -94,   -94,   -94,   532,   381,
     526,   527,   533,   535,   534,   537,   540,   -94,   -94,   -94,
     -94,   -94,   -94,   -94,   -94,   -94,   -94,   -94,   -94,   -94,
     -94,   538,   539,   541,   542,   543,   544,   545,   546,   547,
     548,   549,   551,   -94,   -94,   -94,   -94,   -94,   -94,   -94,
     554,   555,   558,   -94,   -94,   -94,   536,   559,   485,   564,
     565,   566,   563,   568,   569,   570,   -94,   -94,   -94,   -94,
     -94,   -94,   -94,   -94,   -94,   567,   573,   122,   -94,   129,
     300,   571,   -94,   511,   -94,   -94,   -94,   575,   -94,   -94,
     -94,   -94,   -94,   -94,   -94,   -94,   -94,   -94,   -94,   -94,
     -94,   -94,   -94,   574,   576,   577,   -94,   -94,   -94,   -94,
     578,   -94,   512,   582,   583,   584,   580,   585,   586,   587,
     588,   590,   486,   572,   579,   592,   591,   596,   598,   599,
     -94,   -94,   -94,   -94,   -94,   -94,   -94,   -94,   -94,   495,
     -94,   600,   601,   602,   603,   604,   605,   -94,   -94,   -94,
     -94,   -94,   -94,   -94,   -94,   514,   -94,   273,   -94,   -94,
      61,   -94,   606,   607,   608,   -94,   609,   610,   612,   -94,
     -94,   -94,   183,   -94,    84,   -94,   -94,   -94,   -94,   613,
     -94,   -94,   -94,   -94,   614,   -94,   550,   616,   617,   618,
     623,   622,   624,   625,   -94,   626,   627,   628,   629,   630,
     631,   -94,   632,   638,   -94,   -94,   -94,   -93,   518,   -94,
     637,   642,   643,   644,   -94,   -94,   -94,   -94,   -94,   -94,
     -94,   -94,   -94,   641,   -94,   -94,   -94,   -94,   -94,   -94,
     -27,   528,   -94,   646,   647,   648,   649,   -94,   -94,   -94,
     -94,   -94,   -94,   -94,   173,   -94,    86,   -94,   -94,   -94,
     -94,   650,   -94,   -94,   -94,   -94,   -94,   -94,   -94,   -94,
     -94,   651,   -94,   -94,   -94,   -94,   -94,   652,   653,   654,
     655,   -94,   162,   -94,   -94,   -94,   -94,   656,   657,   658,
     659,   -94,   -94,   -94,   -34,   552,   -94,   664,   665,   666,
     667,   -94,   -94,   -94,   -94,   -94,   -94,   -94,   668,   669,
     164,   -94,   -94,   -94,   -94,   519,   -94,   670,   671,   -94,
     -94,   -94,   -94,   172,   -94,   -94,   -94,   -94,   179,   -94,
     -94,   -94,   -94,   672,   673,   674,   675,   -94,   -94,   557,
     -94,   681,   682,   -94,   -94,   -94,   -94,   -94,   679,   680,
     556,   -94,   685,   686,   -94,   -94,   -94,   -94,   553,   -94,
     688,   689,   -94,   -94,   -94,   -94,   181,   -94,   -94,   -94,
     -94,   -94,   690,   691,   -94,   -94,   -94,   692,   693,   -94,
     694,   695,   561,   -94,   701,   702,   -94,   -94,   -94,   -94,
     -94,   -94,   -94,   -94,   -94,   -94,   -94,   699,   700,   -94,
     -94
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -94,   -94,   -94,   -94,   -94,   -94,   -94,   -94,   -94,   -94,
     -94,   -94,   -94,   -94,   -94,   -94,   -94,   -94,   -94,   -94,
     -94,   -94,   -94,   -94,   -94,   -94,   -94,   -94,   -94,   -94,
     -94,   -94,   -94,   -94,   -94,   -94,   -94,   -94,   -94,   -94,
     -94,   -94,   -94,   -94,   -94,   -94,   -94,   -94,   -94,   -94,
     -94,   -94,   -94,   -94,   -94,   -94,   -94,   -94,   -94,   -94,
     -94,   -94,   -94,   -94,   -94,   -94,   -94,   -94,   -94,   -94,
     -94,   -94,   -94,   -94,   -94,   -94,   -94,   -94,   -94,   -94,
     -94,   -94,   -94,   -94,   -94,   -94,   -94,   -94,   -94,   -94,
     -94,   -94,   -94,   -94,   -94,   -94,   -94,   -94,   -94,   -94,
     -94,   -94,   -94,   -94,   -94,   -94,   -94,   -94,   -94,   -94,
     -94,   -94,   -94,   -94,   -94,   -94,   -94,   -94,   -94,   -94,
     -94,   -94,   -94,   -94,   -94,   -94,   -94,   -94,   -94,   -94,
     -94,   -94,   -94,   -94,   -94,   -94,   -94,   -94,   -94,   -94,
     -94,   -94,   -94,   -94,   -94,   -94,   -94,   -94,   -94,   -94,
     -94,   -94,   -94,   -94,   -94,   -94,   -94,   -94,   -94,   -94,
     -94,   -94,   -94,   -94,   -94,   -94,   -94,   -94,   -94,   -94,
     -94,   -94,   -94,   -94,   -94,   -94,   -94,   -94,   -94,   -94,
     -94,   -94,   -94,   -94,   -94,   -94,   -94,   -94,   -94,   -94,
     -94,   -94,   -94,   -94,   -94,   -94,   -94,   -94,   -94,   -94,
     -94,   -94,   -94,   -94,   -94,   -94,   -94,   -94,   -94,   -94,
     -94,   -94,   -94,   -94,   -94,   -94,   -94,   -94,   -94,   -94,
     -94,   -94,   -94,   -94,   -94,   -94,   -94,   -94,   -94,   -94,
     -94,   -94,   -94,   -94,   -94,   -94,   -94,   -94,   -94,   -94,
     -94,   -94,   -94,   -94,   -94,   -94,   -94,   -94,   -94,   -94,
     -94,   -94,   -94,   -94,   -94,   -94,   -94,   -94,   -94,   -94,
     -94,   -94,   -94,   -94,   -94,   -94,   -94,   -94,   -94,   -94,
     -94,   -94,   -94,   -94,   -94,   -94,   -94,   -94,   -94,   -94,
     -94,   -94,   -94,   -94,   -94,   -94,   -94,   -94,   -94,   -94,
     -94,   -94,   -94,   -94,   -94,   -94,   -94,   -94,   -94,   -94,
     -94,   -94,   -94,   -94,   -94,   -94,   -94,   -94,   -94,   -94,
     -94,   -94,   -94,   -94,   -94,   -94,   -94,   -94,   -94,   -94,
     -94,   -94,   -94,   -94,   -94,   -94,   -94,   -94,   -94,   -94,
     -94,   -94,   -94,   -94,   -94,   -94,   -94,   -94,   -94,   -94,
     -94,   -94,   -94,   -94,   -94,   -94,   -94,   -94,   -94,   -94,
     -94,   -94,   -94,   -94,   -94,   -94,   -94,   -94,   -94,   -94,
     -94,   -94,   -94,   -94,   -94,   -94,   -94,   -94,   -94,   -94,
     -94,   -94,   -94,   -94,   -94,   -94,   -94,   -94,   -94,   -94,
     -94,   -94,   -94,   -94,   -94,   -94,   -94,   -94,   -94,   -94,
     -94,   -94,   -94,   -94,   -94,   -94,   -94,   -94,   -94,   -94,
     -94,   -94,   -94,   -94,   -94,   -94,   -94,   -94,   -94,   -94,
     -94,   -94,   -94,   -94,   -94,   -94,   -94,   -94,   -94,   -94,
     -94,   -94,   -94,   -94,   -94,   -94,   -94,   -94,   -94,   -94
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -185
static const yytype_int16 yytable[] =
{
     351,   182,   410,   411,   245,   469,   229,   316,   317,   308,
     309,   124,   125,   788,   312,   313,   162,   160,   158,   156,
     150,   148,   146,   489,   183,   164,    75,   789,   790,   791,
     504,     4,   993,   499,   490,   994,   470,   494,   184,   792,
     185,   793,   186,   794,   187,   795,   188,   505,   500,     1,
     495,   126,   189,    76,   190,     5,   191,    77,   192,    78,
     193,    79,   194,    80,   195,     8,   196,   101,   197,   938,
     939,    12,   147,   149,   151,    13,   127,   157,   159,   161,
     163,    19,   310,   246,   318,   412,   352,   230,   128,   314,
     509,   165,   961,   962,  1015,  1016,   172,   173,   940,   941,
      26,   510,   942,   943,   739,   513,  1003,  1049,   481,  1004,
    1050,   526,   527,   482,   514,   174,   175,   176,   740,   741,
     742,   963,   964,  1017,  1018,   965,   966,  1019,  1020,   743,
     852,  -184,   744,   485,   745,   118,   746,   869,   870,   528,
     486,   529,    68,   530,   853,   854,   855,   643,   644,     6,
       7,   871,   872,   873,   700,   701,   135,   856,   857,   566,
     858,   567,   859,   568,   120,   874,   137,   875,   144,   876,
    1035,  1036,  1059,  1060,   139,   645,   170,   646,   152,   647,
    1070,  1071,   702,   231,   703,   171,   704,  1078,  1079,  1102,
    1103,   473,   599,   600,   474,   609,   610,    16,    17,  1037,
    1038,  1061,  1062,   601,   602,   603,   611,   612,   613,  1072,
    1073,    33,    22,    23,    29,    30,  1080,  1081,  1104,  1105,
      34,   248,    35,   166,    36,   233,    37,   237,    38,   253,
      39,   241,    40,   261,    41,   266,    42,   247,    43,   263,
      44,   619,   620,   278,   629,   630,    71,    72,    92,    93,
      95,    96,   621,   622,   623,   631,   632,   633,    98,    99,
     103,   104,   106,   107,   109,   110,   112,   113,   115,   116,
     141,   142,   153,   154,   167,   168,   234,   235,   238,   239,
     242,   243,   275,   276,   336,   337,   348,   349,   394,   395,
     403,   404,   442,   443,   454,   455,   477,   478,   517,   518,
     521,   522,   540,   541,   730,   731,   734,   735,   885,   886,
     932,   933,   270,  1011,  1012,   957,   958,   271,   272,   273,
     280,   282,   300,   284,   286,   305,   288,   290,   306,   302,
     292,   294,   296,   298,   320,   323,   327,   325,   326,   324,
     333,   329,   335,   331,   339,   340,   328,   342,   344,   345,
     346,   330,   347,   353,   398,   354,   356,   332,   355,   357,
     334,   358,   359,   546,   360,   361,   457,   362,   363,   400,
     364,   365,   449,   366,   367,   379,   368,   369,   447,   370,
     371,   448,   372,   373,   450,   374,   375,   577,   376,   377,
     380,   378,   459,   383,   386,   389,   393,   402,   406,   407,
     408,   414,   416,   392,   418,   420,   422,   424,   426,   428,
     430,   432,   434,   436,   438,   445,   446,   441,   453,   461,
     464,   543,   462,   468,   472,   476,   467,   480,   484,   488,
     493,   498,   503,   508,   512,   516,   520,   536,   539,   576,
     545,   580,   550,   552,   553,   551,   554,   555,   556,   548,
     561,   562,   537,   563,   578,   579,   587,   589,   584,   582,
     594,   595,   588,   590,   581,   585,   596,   597,   598,   592,
     591,   639,   640,   641,   653,   654,   655,   808,   662,   656,
     669,   666,   657,   661,   665,   667,   671,   663,   675,   673,
     682,   683,   684,   686,   687,   688,   690,   691,   681,   692,
     694,   695,   696,   711,   712,   713,   812,     0,   724,   777,
     718,   719,   720,   721,   722,   685,   725,   729,   726,   689,
     733,   738,   756,   710,   717,   778,   779,   783,   784,   814,
     815,   785,   786,   727,   787,   805,   816,   818,   806,   811,
     819,   693,   817,   820,   839,   821,   822,     0,   823,   824,
     825,   826,   827,   828,   829,   830,   831,   757,   832,   758,
     776,   836,   837,   759,   760,   838,   840,   843,   844,   845,
     846,   847,   848,   849,   850,   917,   773,   774,   851,   889,
     895,   899,   918,   900,   901,   909,   903,   891,   905,   906,
     907,   908,   910,   911,   912,   919,   913,   914,   920,   921,
     775,   922,   923,   925,   926,   927,   928,   929,   930,     0,
       0,     0,     0,   950,   951,   952,   954,   955,   841,   956,
     973,     0,   975,   978,   979,   980,   977,   915,   981,   982,
       0,   983,   984,   985,   986,   987,   988,   989,   990,   991,
     931,   992,   997,   924,   996,   998,   999,  1000,  1001,  1007,
    1008,  1009,  1010,  1067,  1006,     0,  1028,  1027,     0,  1031,
    1032,  1033,  1034,  1044,  1045,  1046,  1047,  1053,  1054,  1055,
    1056,     0,     0,  1068,  1069,  1057,  1058,     0,     0,  1087,
    1088,  1089,  1090,  1091,  1092,  1093,  1094,  1095,  1097,  1098,
    1096,  1100,  1101,     0,  1052,  1099,     0,  1110,  1111,  1112,
    1113,  1114,  1115,  1116,  1117,  1118,  1119,  1120
};

static const yytype_int16 yycheck[] =
{
       4,    50,     5,     6,     5,    61,     5,     5,     6,     5,
       6,     8,     9,     8,     5,     6,     4,     4,     4,     4,
       4,     4,     4,    99,    73,     4,    46,    22,    23,    24,
      99,    11,   125,    99,   110,   128,    92,    99,    87,    34,
      89,    36,    91,    38,    93,    40,    95,   116,   114,    10,
     112,    48,   101,    73,   103,     0,   105,    77,   107,    79,
     109,    81,   111,    83,   113,    43,   115,    13,   117,     8,
       9,    12,    54,    56,    58,    45,    73,    62,    64,    66,
      68,    47,    78,    84,    82,    88,    90,    86,    85,    80,
      97,    70,     8,     9,     8,     9,     8,     9,    37,    38,
      49,   108,    41,    42,     8,    97,   133,   141,    97,   136,
     144,     8,     9,   102,   106,    27,    28,    29,    22,    23,
      24,    37,    38,    37,    38,    41,    42,    41,    42,    33,
       8,     8,    36,    97,    38,    14,    40,     8,     9,    36,
     104,    38,    51,    40,    22,    23,    24,     8,     9,     8,
       9,    22,    23,    24,     8,     9,    39,    35,    36,    36,
      38,    38,    40,    40,    15,    36,    39,    38,    15,    40,
       8,     9,     8,     9,    39,    36,     7,    38,     3,    40,
       8,     9,    36,    15,    38,     8,    40,     8,     9,     8,
       9,    94,     8,     9,    97,     8,     9,     8,     9,    37,
      38,    37,    38,    19,    20,    21,    19,    20,    21,    37,
      38,    44,     8,     9,     8,     9,    37,    38,    37,    38,
      53,     8,    55,     3,    57,     3,    59,     3,    61,     4,
      63,     3,    65,     4,    67,   121,    69,     7,    71,     5,
      73,     8,     9,    16,     8,     9,     8,     9,     8,     9,
       8,     9,    19,    20,    21,    19,    20,    21,     8,     9,
       8,     9,     8,     9,     8,     9,     8,     9,     8,     9,
       8,     9,     8,     9,     8,     9,     8,     9,     8,     9,
       8,     9,     8,     9,    74,    75,     8,     9,    74,    75,
       8,     9,    74,    75,     8,     9,    96,    97,   118,   119,
      74,    75,     8,     9,   146,   147,   124,   125,     8,     9,
      37,    38,     7,   140,   141,   132,   133,     7,     7,    39,
      17,    17,    25,    17,    17,     7,    18,    18,     8,    15,
      18,    18,    17,    17,     5,    54,    60,    58,     7,    56,
       7,    64,     7,    68,    52,   129,    62,    30,     5,     5,
       5,    66,     3,     7,    31,     8,     8,    70,     7,     7,
      72,     8,     7,    33,     8,     7,    32,     8,     7,   137,
       8,     7,    82,     8,     7,    86,     8,     7,    80,     8,
       7,    80,     8,     7,    82,     8,     7,     3,     8,     7,
       5,     8,   145,     7,     7,     7,     7,     7,     7,     7,
       7,     5,     5,    84,     5,     5,     5,     5,     5,     5,
       5,     5,     5,     5,     5,    78,    78,     7,     7,     5,
       7,    26,   123,     7,     7,     7,    90,     7,     7,     7,
       7,     7,     7,     7,     7,     7,     7,     5,     7,    76,
       7,     7,    88,     8,     8,    88,     8,     8,     8,   127,
       8,     8,   131,     8,     3,     3,     7,     7,     5,   135,
       4,     4,     8,     8,    34,   139,     4,     4,     4,    75,
      33,     4,     4,     4,     3,     3,     3,   138,    34,     9,
       5,    35,     8,     7,     7,   143,     5,    75,   122,     7,
       3,     3,     3,     3,     3,     3,     3,     3,   100,     3,
       3,     3,     3,     3,     3,     3,   125,    -1,   130,     3,
       7,     7,     7,     5,     7,   100,     7,     7,    35,   100,
       7,     5,    62,    76,    76,     3,     3,     7,     7,     3,
       3,     7,     7,    75,     5,     5,     3,     3,     7,     7,
       3,   100,     7,     3,     8,     7,     7,    -1,     7,     7,
       7,     7,     7,     7,     7,     7,     7,    98,     7,    98,
      76,     7,     7,    98,    98,     7,     7,     3,     3,     3,
       7,     3,     3,     3,     7,     3,    98,    98,     5,     8,
       5,     7,     3,     7,     7,     5,     8,    76,    76,     7,
       7,     7,     7,     7,     7,     3,     8,     7,     7,     3,
     120,     3,     3,     3,     3,     3,     3,     3,     3,    -1,
      -1,    -1,    -1,     7,     7,     7,     7,     7,   133,     7,
       7,    -1,     8,     7,     7,     7,    76,   141,     5,     7,
      -1,     7,     7,     7,     7,     7,     7,     7,     7,     7,
     126,     3,     5,   148,   126,     3,     3,     3,     7,     3,
       3,     3,     3,   134,   126,    -1,     5,     7,    -1,     7,
       7,     7,     7,     7,     7,     7,     7,     3,     3,     3,
       3,    -1,    -1,     3,     3,     7,     7,    -1,    -1,     7,
       7,     7,     7,   126,     3,     3,     7,     7,     3,     3,
     134,     3,     3,    -1,   142,   142,    -1,     7,     7,     7,
       7,     7,     7,   142,     3,     3,     7,     7
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,    10,   151,   152,    11,     0,     8,     9,    43,   153,
     154,   155,    12,    45,   219,   220,     8,     9,   156,    47,
     267,   268,     8,     9,   221,   157,    49,   292,   293,     8,
       9,   269,   222,    44,    53,    55,    57,    59,    61,    63,
      65,    67,    69,    71,    73,   158,   159,   160,   163,   164,
     167,   168,   171,   172,   177,   178,   181,   182,   185,   186,
     189,   190,   193,   194,   197,   198,   203,   204,    51,   432,
     433,     8,     9,   294,   270,    46,    73,    77,    79,    81,
      83,   223,   224,   225,   231,   232,   238,   239,   245,   246,
     249,   250,     8,     9,   161,     8,     9,   165,     8,     9,
     169,    13,   173,     8,     9,   179,     8,     9,   183,     8,
       9,   187,     8,     9,   191,     8,     9,   195,    14,   199,
      15,   205,   434,   295,     8,     9,    48,    73,    85,   271,
     272,   273,   274,   276,   277,    39,   226,    39,   233,    39,
     240,     8,     9,   247,    15,   251,     4,    54,     4,    56,
       4,    58,     3,     8,     9,   175,     4,    62,     4,    64,
       4,    66,     4,    68,     4,    70,     3,     8,     9,   201,
       7,     8,     8,     9,    27,    28,    29,   435,   436,   437,
     438,   439,    50,    73,    87,    89,    91,    93,    95,   101,
     103,   105,   107,   109,   111,   113,   115,   117,   296,   297,
     298,   304,   305,   308,   309,   314,   315,   320,   321,   326,
     327,   332,   333,   338,   339,   353,   354,   368,   369,   383,
     384,   398,   399,   404,   405,   410,   411,   416,   417,     5,
      86,    15,   278,     3,     8,     9,   228,     3,     8,     9,
     235,     3,     8,     9,   242,     5,    84,     7,     8,   162,
     166,   170,   174,     4,   176,   180,   184,   188,   192,   196,
     200,     4,   202,     5,   206,   207,   121,   440,   441,   442,
       7,     7,     7,    39,   299,     8,     9,   306,    16,   310,
      17,   316,    17,   322,    17,   328,    17,   334,    18,   340,
      18,   355,    18,   370,    18,   385,    17,   400,    17,   406,
      25,   412,    15,   418,   275,     7,     8,   227,     5,     6,
      78,   234,     5,     6,    80,   241,     5,     6,    82,   248,
       5,   252,   253,    54,    56,    58,     7,    60,    62,    64,
      66,    68,    70,     7,    72,     7,    74,    75,   208,    52,
     129,   491,    30,   443,     5,     5,     5,     3,     8,     9,
     301,     4,    90,     7,     8,     7,     8,     7,     8,     7,
       8,     7,     8,     7,     8,     7,     8,     7,     8,     7,
       8,     7,     8,     7,     8,     7,     8,     7,     8,    86,
       5,   279,   280,     7,   230,   229,     7,   237,   236,     7,
     244,   243,    84,     7,    74,    75,   254,   209,    31,   492,
     137,   529,     7,     8,     9,   444,     7,     7,     7,   300,
       5,     6,    88,   307,     5,   311,     5,   317,     5,   323,
       5,   329,     5,   335,     5,   341,     5,   356,     5,   371,
       5,   386,     5,   401,     5,   407,     5,   413,     5,   419,
     420,     7,    74,    75,   281,    78,    78,    80,    80,    82,
      82,   255,   210,     7,     8,     9,   493,    32,   530,   145,
     567,     5,   123,   445,     7,   303,   302,    90,     7,    61,
      92,   312,     7,    94,    97,   318,     7,    96,    97,   324,
       7,    97,   102,   330,     7,    97,   104,   336,     7,    99,
     110,   342,   343,     7,    99,   112,   357,   358,     7,    99,
     114,   372,   373,     7,    99,   116,   387,   388,     7,    97,
     108,   402,     7,    97,   106,   408,     7,   118,   119,   414,
       7,    74,    75,   421,   282,   256,     8,     9,    36,    38,
      40,   211,   212,   214,   216,   218,     5,   131,   494,     7,
       8,     9,   531,    26,   568,     7,    33,   446,   127,   457,
      88,    88,     8,     8,     8,     8,     8,   344,   359,   374,
     389,     8,     8,     8,   422,   283,    36,    38,    40,   257,
     258,   260,   262,   264,   265,   266,    76,     3,     3,     3,
       7,    34,   135,   502,     5,   139,   532,     7,     8,     7,
       8,    33,    75,   465,     4,     4,     4,     4,     4,     8,
       9,    19,    20,    21,   345,   346,   348,   350,   352,     8,
       9,    19,    20,    21,   360,   361,   363,   365,   367,     8,
       9,    19,    20,    21,   375,   376,   378,   380,   382,     8,
       9,    19,    20,    21,   390,   391,   393,   395,   397,     4,
       4,     4,   423,     8,     9,    36,    38,    40,   284,   285,
     287,   289,   291,     3,     3,     3,     9,     8,   213,   215,
     217,     7,    34,    75,   510,     7,    35,   143,   540,     5,
     569,     5,   447,     7,   466,   122,   313,   319,   325,   331,
     337,   100,     3,     3,     3,   100,     3,     3,     3,   100,
       3,     3,     3,   100,     3,     3,     3,   403,   409,   415,
       8,     9,    36,    38,    40,   424,   425,   427,   429,   431,
      76,     3,     3,     3,   259,   261,   263,    76,     7,     7,
       7,     5,     7,   511,   130,     7,    35,    75,   548,     7,
     146,   147,   570,     7,   124,   125,   448,   449,     5,     8,
      22,    23,    24,    33,    36,    38,    40,   467,   468,   470,
     472,   474,   476,   478,   480,   482,    62,    98,    98,    98,
      98,   347,   349,   351,   362,   364,   366,   377,   379,   381,
     392,   394,   396,    98,    98,   120,    76,     3,     3,     3,
     286,   288,   290,     7,     7,     7,     7,     5,     8,    22,
      23,    24,    34,    36,    38,    40,   512,   513,   514,   515,
     516,   517,   518,   519,   520,     5,     7,   549,   138,   571,
     450,     7,   125,   483,     3,     3,     3,     7,     3,     3,
       3,     7,     7,     7,     7,     7,     7,     7,     7,     7,
       7,     7,     7,   426,   428,   430,     7,     7,     7,     8,
       7,   133,   521,     3,     3,     3,     7,     3,     3,     3,
       7,     5,     8,    22,    23,    24,    35,    36,    38,    40,
     550,   551,   552,   553,   554,   555,   556,   557,   558,     8,
       9,    22,    23,    24,    36,    38,    40,   572,   573,   574,
     575,   576,   577,   578,   579,     8,     9,   451,   456,     8,
     484,    76,   475,   477,   479,     5,   471,   473,   481,     7,
       7,     7,   495,     8,   522,    76,     7,     7,     7,     5,
       7,     7,     7,     8,     7,   141,   559,     3,     3,     3,
       7,     3,     3,     3,   148,     3,     3,     3,     3,     3,
       3,   126,    37,    38,   452,   453,   454,   458,     8,     9,
      37,    38,    41,    42,   485,   486,   487,   488,   489,   490,
       7,     7,     7,   469,     7,     7,     7,   132,   133,   496,
     503,     8,     9,    37,    38,    41,    42,   523,   524,   525,
     526,   527,   528,     7,   533,     8,   560,    76,     7,     7,
       7,     5,     7,     7,     7,     7,     7,     7,     7,     7,
       7,     7,     3,   125,   128,   459,   126,     5,     3,     3,
       3,     7,   497,   133,   136,   504,   126,     3,     3,     3,
       3,   140,   141,   534,   541,     8,     9,    37,    38,    41,
      42,   561,   562,   563,   564,   565,   566,     7,     5,   455,
     460,     7,     7,     7,     7,     8,     9,    37,    38,   498,
     499,   500,   501,   505,     7,     7,     7,     7,   535,   141,
     144,   542,   142,     3,     3,     3,     3,     7,     7,     8,
       9,    37,    38,   461,   462,   463,   464,   134,     3,     3,
       8,     9,    37,    38,   506,   507,   508,   509,     8,     9,
      37,    38,   536,   537,   538,   539,   543,     7,     7,     7,
       7,   126,     3,     3,     7,     7,   134,     3,     3,   142,
       3,     3,     8,     9,    37,    38,   544,   545,   546,   547,
       7,     7,     7,     7,     7,     7,   142,     3,     3,     7,
       7
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

  case 46:

    {osoption->general->instanceLocation->locationType = (yyvsp[(2) - (2)].sval);;}
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
	}
;}
    break;

  case 85:

    {osoption->general->contact->transportType = (yyvsp[(2) - (2)].sval);;}
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

    {	osoption->general->otherOptions->numberOfOtherOptions = (yyvsp[(3) - (4)].ival);
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
	}
;}
    break;

  case 127:

    {osoption->system->minDiskSpace->unit = (yyvsp[(2) - (2)].sval);;}
    break;

  case 131:

    {osoption->system->minDiskSpace->value = (yyvsp[(2) - (2)].dval);;}
    break;

  case 133:

    {osoption->system->minDiskSpace->value = (yyvsp[(2) - (2)].ival);;}
    break;

  case 136:

    {	if (parserData->minMemorySizePresent)
	{	osolerror( NULL, osoption, parserData, "only one <minMemorySize> element allowed");
	}
	else
	{	parserData-> minMemorySizePresent = true;	
		osoption->system->minMemorySize = new MinMemorySize();
	}
;}
    break;

  case 138:

    {osoption->system->minMemorySize->unit = (yyvsp[(2) - (2)].sval);;}
    break;

  case 142:

    {osoption->system->minMemorySize->value = (yyvsp[(2) - (2)].dval);;}
    break;

  case 144:

    {osoption->system->minMemorySize->value = (yyvsp[(2) - (2)].ival);;}
    break;

  case 147:

    {	if (parserData->minCPUSpeedPresent)
	{	osolerror( NULL, osoption, parserData, "only one <minCPUSpeed> element allowed");
	}
	else
	{	parserData-> minCPUSpeedPresent = true;	
		osoption->system->minCPUSpeed = new MinCPUSpeed();
	}
;}
    break;

  case 149:

    {osoption->system->minCPUSpeed->unit = (yyvsp[(2) - (2)].sval);;}
    break;

  case 153:

    {osoption->system->minCPUSpeed->value = (yyvsp[(2) - (2)].dval);;}
    break;

  case 155:

    {osoption->system->minCPUSpeed->value = (yyvsp[(2) - (2)].ival);;}
    break;

  case 158:

    {	if (parserData->minCPUNumberPresent)
	{	osolerror( NULL, osoption, parserData, "only one <minCPUNumber> element allowed");
	}
	else
	{	parserData->minCPUNumberPresent = true;	
	}
;}
    break;

  case 161:

    {osoption->system->minCPUNumber = (yyvsp[(2) - (2)].ival);;}
    break;

  case 164:

    {	if (parserData->otherSystemOptionsPresent)
	{	osolerror( NULL, osoption, parserData, "only one <otherOptions> element allowed");
	}
	else
	{	parserData->otherSystemOptionsPresent = true;
		osoption->system->otherOptions = new OtherOptions();	
	}
;}
    break;

  case 165:

    {	osoption->system->otherOptions->numberOfOtherOptions = (yyvsp[(3) - (4)].ival);
	osoption->system->otherOptions->other = new OtherOption*[(yyvsp[(3) - (4)].ival)];
	for (int i=0; i < (yyvsp[(3) - (4)].ival); i++) osoption->system->otherOptions->other[i] = new OtherOption();
;}
    break;

  case 166:

    {	if (parserData->numberOfOtherSystemOptions != osoption->system->otherOptions->numberOfOtherOptions)
		osolerror (NULL, osoption, parserData, "wrong number of other options in <system> element"); 
;}
    break;

  case 169:

    {	if (parserData->numberOfOtherSystemOptions >= osoption->system->otherOptions->numberOfOtherOptions)
		{	osolerror (NULL, osoption, parserData, "too many other options in <system> element");
		};
	;}
    break;

  case 170:

    {	if (!parserData->otherOptionNamePresent)
		osolerror (NULL, osoption, parserData, "name attribute must be present");
	/* reset defaults for the next option */
	parserData->otherOptionNamePresent = false;
	parserData->otherOptionValuePresent = false;
	parserData->otherOptionDescriptionPresent = false;
	parserData->numberOfOtherSystemOptions++;
;}
    break;

  case 176:

    {	if (parserData->otherOptionNamePresent)
	{	osolerror( NULL, osoption, parserData, "only one name attribute allowed");
	}
	else
	{	parserData->otherOptionNamePresent = true;
		osoption->system->otherOptions->other[parserData->numberOfOtherSystemOptions]->name = (yyvsp[(2) - (2)].sval);	
	}
;}
    break;

  case 178:

    {	if (parserData->otherOptionValuePresent)
	{	osolerror( NULL, osoption, parserData, "only one value attribute allowed");
	}
	else
	{	parserData->otherOptionValuePresent = true;
		osoption->system->otherOptions->other[parserData->numberOfOtherSystemOptions]->value = (yyvsp[(2) - (2)].sval);	
	}
;}
    break;

  case 180:

    {	if (parserData->otherOptionDescriptionPresent)
	{	osolerror( NULL, osoption, parserData, "only one description attribute allowed");
	}
	else
	{	parserData->otherOptionDescriptionPresent = true;
		osoption->system->otherOptions->other[parserData->numberOfOtherSystemOptions]->description = (yyvsp[(2) - (2)].sval);	
	}
;}
    break;

  case 182:

    {printf("%s","firing />");;}
    break;

  case 184:

    {printf("%s","firing </other>");;}
    break;

  case 188:

    {	if (parserData->osolservicePresent)
	{	osolerror( NULL, osoption, parserData, "only one <service> element allowed");
	}
	else
	{	parserData->osolservicePresent = true;	
		osoption->service = new ServiceOption();
	}
;}
    break;

  case 197:

    {	if (parserData->serviceTypePresent)
	{	osolerror( NULL, osoption, parserData, "only one <type> element allowed");
	}
	else
	{	parserData->serviceTypePresent = true;	
	}
;}
    break;

  case 200:

    {osoption->service->type = (yyvsp[(2) - (2)].ival);;}
    break;

  case 203:

    {	if (parserData->otherServiceOptionsPresent)
	{	osolerror( NULL, osoption, parserData, "only one <otherOptions> element allowed");
	}
	else
	{	parserData->otherServiceOptionsPresent = true;
		osoption->service->otherOptions = new OtherOptions();	
	}
;}
    break;

  case 204:

    {	osoption->service->otherOptions->numberOfOtherOptions = (yyvsp[(3) - (4)].ival);
	osoption->service->otherOptions->other = new OtherOption*[(yyvsp[(3) - (4)].ival)];
	for (int i=0; i < (yyvsp[(3) - (4)].ival); i++) osoption->service->otherOptions->other[i] = new OtherOption();
;}
    break;

  case 205:

    {	if (parserData->numberOfOtherServiceOptions != osoption->service->otherOptions->numberOfOtherOptions)
		osolerror (NULL, osoption, parserData, "wrong number of other options in <service> element"); 
;}
    break;

  case 208:

    {	if (parserData->numberOfOtherServiceOptions >= osoption->service->otherOptions->numberOfOtherOptions)
		{	osolerror (NULL, osoption, parserData, "too many other options in <service> element");
		};
	;}
    break;

  case 209:

    {	if (!parserData->otherOptionNamePresent)
		osolerror (NULL, osoption, parserData, "name attribute must be present");
	/* reset defaults for the next option */
	parserData->otherOptionNamePresent = false;
	parserData->otherOptionValuePresent = false;
	parserData->otherOptionDescriptionPresent = false;
	parserData->numberOfOtherServiceOptions++;
;}
    break;

  case 215:

    {	if (parserData->otherOptionNamePresent)
	{	osolerror( NULL, osoption, parserData, "only one name attribute allowed");
	}
	else
	{	parserData->otherOptionNamePresent = true;
		osoption->service->otherOptions->other[parserData->numberOfOtherServiceOptions]->name = (yyvsp[(2) - (2)].sval);	
	}
;}
    break;

  case 217:

    {	if (parserData->otherOptionValuePresent)
	{	osolerror( NULL, osoption, parserData, "only one value attribute allowed");
	}
	else
	{	parserData->otherOptionValuePresent = true;
		osoption->service->otherOptions->other[parserData->numberOfOtherServiceOptions]->value = (yyvsp[(2) - (2)].sval);	
	}
;}
    break;

  case 219:

    {	if (parserData->otherOptionDescriptionPresent)
	{	osolerror( NULL, osoption, parserData, "only one description attribute allowed");
	}
	else
	{	parserData->otherOptionDescriptionPresent = true;
		osoption->service->otherOptions->other[parserData->numberOfOtherServiceOptions]->description = (yyvsp[(2) - (2)].sval);	
	}
;}
    break;

  case 224:

    {	if (parserData->osoljobPresent)
	{	osolerror( NULL, osoption, parserData, "only one <job> element allowed");
	}
	else
	{	parserData->osoljobPresent = true;	
		osoption->job = new JobOption();
	}
;}
    break;

  case 245:

    {	if (parserData->maxTimePresent)
	{	osolerror( NULL, osoption, parserData, "only one <maxTime> element allowed");
	}
	else
	{	parserData-> maxTimePresent = true;	
		osoption->job->maxTime = new MaxTime();
	}
;}
    break;

  case 247:

    {osoption->job->maxTime->unit = (yyvsp[(2) - (2)].sval);;}
    break;

  case 251:

    {osoption->job->maxTime->value = (yyvsp[(2) - (2)].dval);;}
    break;

  case 253:

    {osoption->job->maxTime->value = (yyvsp[(2) - (2)].ival);;}
    break;

  case 256:

    {	if (parserData->scheduledStartTimePresent)
	{	osolerror( NULL, osoption, parserData, "only one <scheduledStartTime> element allowed");
	}
	else
	{	parserData->scheduledStartTimePresent = true;	
	}
;}
    break;

  case 259:

    {osoption->general->userName = (yyvsp[(2) - (2)].sval);;}
    break;

  case 262:

    {	if (parserData->dependenciesPresent)
	{	osolerror( NULL, osoption, parserData, "only one <dependencies> element allowed");
	}
	else
	{	parserData->dependenciesPresent = true;
		osoption->job->dependencies = new JobDependencies();	
	}
;}
    break;

  case 263:

    {	osoption->job->dependencies->numberOfJobIDs = (yyvsp[(3) - (4)].ival);
	osoption->job->dependencies->jobID = new std::string[(yyvsp[(3) - (4)].ival)];
;}
    break;

  case 266:

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

  case 269:

    {	if (parserData->requiredDirectoriesPresent)
	{	osolerror( NULL, osoption, parserData, "only one <requiredDirectories> element allowed");
	}
	else
	{	parserData->requiredDirectoriesPresent = true;
		osoption->job->requiredDirectories = new DirectoriesAndFiles();	
	}
;}
    break;

  case 270:

    {	osoption->job->requiredDirectories->numberOfPaths = (yyvsp[(3) - (4)].ival);
	osoption->job->requiredDirectories->path = new std::string[(yyvsp[(3) - (4)].ival)];
;}
    break;

  case 273:

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

  case 276:

    {	if (parserData->requiredFilesPresent)
	{	osolerror( NULL, osoption, parserData, "only one <requiredFiles> element allowed");
	}
	else
	{	parserData->requiredFilesPresent = true;
		osoption->job->requiredFiles = new DirectoriesAndFiles();	
	}
;}
    break;

  case 277:

    {	osoption->job->requiredFiles->numberOfPaths = (yyvsp[(3) - (4)].ival);
	osoption->job->requiredFiles->path = new std::string[(yyvsp[(3) - (4)].ival)];
;}
    break;

  case 280:

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

  case 283:

    {	if (parserData->directoriesToMakePresent)
	{	osolerror( NULL, osoption, parserData, "only one <directoriesToMake> element allowed");
	}
	else
	{	parserData->directoriesToMakePresent = true;
		osoption->job->directoriesToMake = new DirectoriesAndFiles();	
	}
;}
    break;

  case 284:

    {	osoption->job->directoriesToMake->numberOfPaths = (yyvsp[(3) - (4)].ival);
	osoption->job->directoriesToMake->path = new std::string[(yyvsp[(3) - (4)].ival)];
;}
    break;

  case 287:

    {	if (parserData->numberOfDirectoriesToMake >= osoption->job->directoriesToMake->numberOfPaths)
	{	osolerror (NULL, osoption, parserData, "too many job IDs in <directoriesToMake> element");
	}
	else
	{	osoption->job->directoriesToMake->path[parserData->numberOfDirectoriesToMake] = (yyvsp[(3) - (3)].sval);
		parserData->numberOfDirectoriesToMake++; 
	};
;}
    break;

  case 290:

    {	if (parserData->filesToCreatePresent)
	{	osolerror( NULL, osoption, parserData, "only one <filesToCreate> element allowed");
	}
	else
	{	parserData->filesToCreatePresent = true;
		osoption->job->filesToCreate = new DirectoriesAndFiles();	
	}
;}
    break;

  case 291:

    {	osoption->job->filesToCreate->numberOfPaths = (yyvsp[(3) - (4)].ival);
	osoption->job->filesToCreate->path = new std::string[(yyvsp[(3) - (4)].ival)];
;}
    break;

  case 294:

    {	if (parserData->numberOfFilesToCreate >= osoption->job->filesToCreate->numberOfPaths)
	{	osolerror (NULL, osoption, parserData, "too many job IDs in <filesToCreate> element");
	}
	else
	{	osoption->job->filesToCreate->path[parserData->numberOfFilesToCreate] = (yyvsp[(3) - (3)].sval);
		parserData->numberOfFilesToCreate++; 
	};
;}
    break;

  case 297:

    {	if (parserData->inputDirectoriesToMovePresent)
	{	osolerror( NULL, osoption, parserData, "only one <inputDirectoriesToMove> element allowed");
	}
	else
	{	parserData->inputDirectoriesToMovePresent = true;
		osoption->job->inputDirectoriesToMove = new PathPairs();
	}
;}
    break;

  case 298:

    {	if ((yyvsp[(3) - (4)].ival) <= 0) osolerror (NULL, osoption, parserData, "Require positive number of directories to move");
	osoption->job->inputDirectoriesToMove->numberOfPathPairs = (yyvsp[(3) - (4)].ival);
	osoption->job->inputDirectoriesToMove->pathPair = new PathPair*[(yyvsp[(3) - (4)].ival)];
	for (int i = 0; i < (yyvsp[(3) - (4)].ival); i++)
		osoption->job->inputDirectoriesToMove->pathPair[i] = new PathPair();
;}
    break;

  case 301:

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

  case 302:

    {	if (parserData->numberOfInputDirectoriesToMove >= osoption->job->inputDirectoriesToMove->numberOfPathPairs)
	{	osolerror (NULL, osoption, parserData, "too many path pairs in <inputDirectoriesToMove> element");
	};
;}
    break;

  case 308:

    {	if (parserData->pathPairFromPresent)
	{	osolerror( NULL, osoption, parserData, "only one \"from\" attribute allowed");
	}
	else
	{	parserData->pathPairFromPresent = true;
		osoption->job->inputDirectoriesToMove->pathPair[parserData->numberOfInputDirectoriesToMove]->from = (yyvsp[(2) - (2)].sval);	
	}
;}
    break;

  case 310:

    {	if (parserData->pathPairToPresent)
	{	osolerror( NULL, osoption, parserData, "only one \"to\" attribute allowed");
	}
	else
	{	parserData->pathPairToPresent = true;
		osoption->job->inputDirectoriesToMove->pathPair[parserData->numberOfInputDirectoriesToMove]->to = (yyvsp[(2) - (2)].sval);	
	}
;}
    break;

  case 312:

    {	if (parserData->pathPairMakeCopyPresent)
	{	osolerror( NULL, osoption, parserData, "only one \"makeCopy\" attribute allowed");
	}
	else
	{	parserData->pathPairMakeCopyPresent = true;
		if ((yyvsp[(2) - (2)].sval) == "true")
			osoption->job->inputDirectoriesToMove->pathPair[parserData->numberOfInputDirectoriesToMove]->makeCopy = (yyvsp[(2) - (2)].sval);	
	}
;}
    break;

  case 317:

    {	if (parserData->inputFilesToMovePresent)
	{	osolerror( NULL, osoption, parserData, "only one <inputFilesToMove> element allowed");
	}
	else
	{	parserData->inputFilesToMovePresent = true;
		osoption->job->inputFilesToMove = new PathPairs();	
	}
;}
    break;

  case 318:

    {	if ((yyvsp[(3) - (4)].ival) <= 0) osolerror (NULL, osoption, parserData, "Require positive number of files to move");
	osoption->job->inputFilesToMove->numberOfPathPairs = (yyvsp[(3) - (4)].ival);
	osoption->job->inputFilesToMove->pathPair = new PathPair*[(yyvsp[(3) - (4)].ival)];
	for (int i = 0; i < (yyvsp[(3) - (4)].ival); i++) osoption->job->inputFilesToMove->pathPair[i] = new PathPair();
;}
    break;

  case 321:

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

  case 322:

    {	if (parserData->numberOfInputFilesToMove >= osoption->job->inputFilesToMove->numberOfPathPairs)
	{	osolerror (NULL, osoption, parserData, "too many path pairs in <inputFilesToMove> element");
	};
;}
    break;

  case 328:

    {	if (parserData->pathPairFromPresent)
	{	osolerror( NULL, osoption, parserData, "only one \"from\" attribute allowed");
	}
	else
	{	parserData->pathPairFromPresent = true;
		osoption->job->inputFilesToMove->pathPair[parserData->numberOfInputFilesToMove]->from = (yyvsp[(2) - (2)].sval);	
	}
;}
    break;

  case 330:

    {	if (parserData->pathPairToPresent)
	{	osolerror( NULL, osoption, parserData, "only one \"to\" attribute allowed");
	}
	else
	{	parserData->pathPairToPresent = true;
		osoption->job->inputFilesToMove->pathPair[parserData->numberOfInputFilesToMove]->to = (yyvsp[(2) - (2)].sval);	
	}
;}
    break;

  case 332:

    {	if (parserData->pathPairMakeCopyPresent)
	{	osolerror( NULL, osoption, parserData, "only one \"makeCopy\" attribute allowed");
	}
	else
	{	parserData->pathPairMakeCopyPresent = true;
		if ((yyvsp[(2) - (2)].sval) == "true")
			osoption->job->inputFilesToMove->pathPair[parserData->numberOfInputFilesToMove]->makeCopy = (yyvsp[(2) - (2)].sval);	
	}
;}
    break;

  case 337:

    {	if (parserData->outputDirectoriesToMovePresent)
	{	osolerror( NULL, osoption, parserData, "only one <outputDirectoriesToMove> element allowed");
	}
	else
	{	parserData->outputDirectoriesToMovePresent = true;
		osoption->job->outputDirectoriesToMove = new PathPairs();	
	}
;}
    break;

  case 338:

    {	if ((yyvsp[(3) - (4)].ival) <= 0) osolerror (NULL, osoption, parserData, "Require positive number of directories to move");
	osoption->job->outputDirectoriesToMove->numberOfPathPairs = (yyvsp[(3) - (4)].ival);
	osoption->job->outputDirectoriesToMove->pathPair = new PathPair*[(yyvsp[(3) - (4)].ival)];
	for (int i = 0; i < (yyvsp[(3) - (4)].ival); i++)
		osoption->job->outputDirectoriesToMove->pathPair[i] = new PathPair();
;}
    break;

  case 341:

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

  case 342:

    {	if (parserData->numberOfOutputDirectoriesToMove >= osoption->job->outputDirectoriesToMove->numberOfPathPairs)
	{	osolerror (NULL, osoption, parserData, "too many path pairs in <outputDirectoriesToMove> element");
	};
;}
    break;

  case 348:

    {	if (parserData->pathPairFromPresent)
	{	osolerror( NULL, osoption, parserData, "only one \"from\" attribute allowed");
	}
	else
	{	parserData->pathPairFromPresent = true;
		osoption->job->outputDirectoriesToMove->pathPair[parserData->numberOfOutputDirectoriesToMove]->from = (yyvsp[(2) - (2)].sval);	
	}
;}
    break;

  case 350:

    {	if (parserData->pathPairToPresent)
	{	osolerror( NULL, osoption, parserData, "only one \"to\" attribute allowed");
	}
	else
	{	parserData->pathPairToPresent = true;
		osoption->job->outputDirectoriesToMove->pathPair[parserData->numberOfOutputDirectoriesToMove]->to = (yyvsp[(2) - (2)].sval);	
	}
;}
    break;

  case 352:

    {	if (parserData->pathPairMakeCopyPresent)
	{	osolerror( NULL, osoption, parserData, "only one \"makeCopy\" attribute allowed");
	}
	else
	{	parserData->pathPairMakeCopyPresent = true;
		if ((yyvsp[(2) - (2)].sval) == "true")
			osoption->job->outputDirectoriesToMove->pathPair[parserData->numberOfOutputDirectoriesToMove]->makeCopy = (yyvsp[(2) - (2)].sval);	
	}
;}
    break;

  case 357:

    {	if (parserData->outputFilesToMovePresent)
	{	osolerror( NULL, osoption, parserData, "only one <outputFilesToMove> element allowed");
	}
	else
	{	parserData->outputFilesToMovePresent = true;
		osoption->job->outputFilesToMove = new PathPairs();	
	}
;}
    break;

  case 358:

    {	if ((yyvsp[(3) - (4)].ival) <= 0) osolerror (NULL, osoption, parserData, "Require positive number of files to move");
	osoption->job->outputFilesToMove->numberOfPathPairs = (yyvsp[(3) - (4)].ival);
	osoption->job->outputFilesToMove->pathPair = new PathPair*[(yyvsp[(3) - (4)].ival)];
	for (int i = 0; i < (yyvsp[(3) - (4)].ival); i++)
		osoption->job->outputFilesToMove->pathPair[i] = new PathPair();;}
    break;

  case 361:

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

  case 362:

    {	if (parserData->numberOfOutputFilesToMove >= osoption->job->outputFilesToMove->numberOfPathPairs)
	{	osolerror (NULL, osoption, parserData, "too many path pairs in <outputFilesToMove> element");
	};
;}
    break;

  case 368:

    {	if (parserData->pathPairFromPresent)
	{	osolerror( NULL, osoption, parserData, "only one \"from\" attribute allowed");
	}
	else
	{	parserData->pathPairFromPresent = true;
		osoption->job->outputFilesToMove->pathPair[parserData->numberOfOutputFilesToMove]->from = (yyvsp[(2) - (2)].sval);	
	}
;}
    break;

  case 370:

    {	if (parserData->pathPairToPresent)
	{	osolerror( NULL, osoption, parserData, "only one \"to\" attribute allowed");
	}
	else
	{	parserData->pathPairToPresent = true;
		osoption->job->outputFilesToMove->pathPair[parserData->numberOfOutputFilesToMove]->to = (yyvsp[(2) - (2)].sval);	
	}
;}
    break;

  case 372:

    {	if (parserData->pathPairMakeCopyPresent)
	{	osolerror( NULL, osoption, parserData, "only one \"makeCopy\" attribute allowed");
	}
	else
	{	parserData->pathPairMakeCopyPresent = true;
		if ((yyvsp[(2) - (2)].sval) == "true")
			osoption->job->outputFilesToMove->pathPair[parserData->numberOfOutputFilesToMove]->makeCopy = (yyvsp[(2) - (2)].sval);	
	}
;}
    break;

  case 377:

    {	if (parserData->filesToDeletePresent)
	{	osolerror( NULL, osoption, parserData, "only one <filesToDelete> element allowed");
	}
	else
	{	parserData->filesToDeletePresent = true;
		osoption->job->filesToDelete = new DirectoriesAndFiles();	
	}
;}
    break;

  case 378:

    {	osoption->job->filesToDelete->numberOfPaths = (yyvsp[(3) - (4)].ival);
	osoption->job->filesToDelete->path = new std::string[(yyvsp[(3) - (4)].ival)];
;}
    break;

  case 381:

    {	if (parserData->numberOfFilesToDelete >= osoption->job->filesToDelete->numberOfPaths)
	{	osolerror (NULL, osoption, parserData, "too many job IDs in <filesToDelete> element");
	}
	else
	{	osoption->job->filesToDelete->path[parserData->numberOfFilesToDelete] = (yyvsp[(3) - (3)].sval);
		parserData->numberOfFilesToDelete++; 
	};
;}
    break;

  case 384:

    {	if (parserData->directoriesToDeletePresent)
	{	osolerror( NULL, osoption, parserData, "only one <directoriesToDelete> element allowed");
	}
	else
	{	parserData->directoriesToDeletePresent = true;
		osoption->job->directoriesToDelete = new DirectoriesAndFiles();	
	}
;}
    break;

  case 385:

    {	osoption->job->directoriesToDelete->numberOfPaths = (yyvsp[(3) - (4)].ival);
	osoption->job->directoriesToDelete->path = new std::string[(yyvsp[(3) - (4)].ival)];
;}
    break;

  case 388:

    {	if (parserData->numberOfDirectoriesToDelete >= osoption->job->directoriesToDelete->numberOfPaths)
	{	osolerror (NULL, osoption, parserData, "too many job IDs in <directoriesToDelete> element");
	}
	else
	{	osoption->job->directoriesToDelete->path[parserData->numberOfDirectoriesToDelete] = (yyvsp[(3) - (3)].sval);
		parserData->numberOfDirectoriesToDelete++; 
	};
;}
    break;

  case 391:

    {	if (parserData->processesToKillPresent)
	{	osolerror( NULL, osoption, parserData, "only one <processesToKill> element allowed");
	}
	else
	{	parserData->processesToKillPresent = true;
		osoption->job->processesToKill = new Processes();	
	}
;}
    break;

  case 392:

    {	osoption->job->processesToKill->numberOfProcesses = (yyvsp[(3) - (4)].ival);
	osoption->job->processesToKill->process = new std::string[(yyvsp[(3) - (4)].ival)];
;}
    break;

  case 395:

    {	if (parserData->numberOfProcessesToKill >= osoption->job->processesToKill->numberOfProcesses)
	{	osolerror (NULL, osoption, parserData, "too many job IDs in <processesToKill> element");
	}
	else
	{	osoption->job->processesToKill->process[parserData->numberOfProcessesToKill] = (yyvsp[(3) - (3)].sval);
		parserData->numberOfProcessesToKill++; 
	};
;}
    break;

  case 398:

    {	if (parserData->otherJobOptionsPresent)
	{	osolerror( NULL, osoption, parserData, "only one <otherOptions> element allowed");
	}
	else
	{	parserData->otherJobOptionsPresent = true;
		osoption->job->otherOptions = new OtherOptions();	
	}
;}
    break;

  case 399:

    {	osoption->job->otherOptions->numberOfOtherOptions = (yyvsp[(3) - (4)].ival);
	osoption->job->otherOptions->other = new OtherOption*[(yyvsp[(3) - (4)].ival)];
	for (int i=0; i < (yyvsp[(3) - (4)].ival); i++) osoption->job->otherOptions->other[i] = new OtherOption();
;}
    break;

  case 400:

    {	if (parserData->numberOfOtherJobOptions != osoption->job->otherOptions->numberOfOtherOptions)
		osolerror (NULL, osoption, parserData, "wrong number of other options in <job> element"); 
;}
    break;

  case 403:

    {	if (parserData->numberOfOtherJobOptions >= osoption->job->otherOptions->numberOfOtherOptions)
		{	osolerror (NULL, osoption, parserData, "too many other options in <job> element");
		};
	;}
    break;

  case 404:

    {	if (!parserData->otherOptionNamePresent)
		osolerror (NULL, osoption, parserData, "name attribute must be present");
	/* reset defaults for the next option */
	parserData->otherOptionNamePresent = false;
	parserData->otherOptionValuePresent = false;
	parserData->otherOptionDescriptionPresent = false;
	parserData->numberOfOtherJobOptions++;
;}
    break;

  case 410:

    {	if (parserData->otherOptionNamePresent)
	{	osolerror( NULL, osoption, parserData, "only one name attribute allowed");
	}
	else
	{	parserData->otherOptionNamePresent = true;
		osoption->job->otherOptions->other[parserData->numberOfOtherJobOptions]->name = (yyvsp[(2) - (2)].sval);	
	}
;}
    break;

  case 412:

    {	if (parserData->otherOptionValuePresent)
	{	osolerror( NULL, osoption, parserData, "only one value attribute allowed");
	}
	else
	{	parserData->otherOptionValuePresent = true;
		osoption->job->otherOptions->other[parserData->numberOfOtherJobOptions]->value = (yyvsp[(2) - (2)].sval);	
	}
;}
    break;

  case 414:

    {	if (parserData->otherOptionDescriptionPresent)
	{	osolerror( NULL, osoption, parserData, "only one description attribute allowed");
	}
	else
	{	parserData->otherOptionDescriptionPresent = true;
		osoption->job->otherOptions->other[parserData->numberOfOtherJobOptions]->description = (yyvsp[(2) - (2)].sval);	
	}
;}
    break;

  case 420:

    {	if (parserData->osoloptimizationPresent)
	{	osolerror( NULL, osoption, parserData, "only one <optimization> element allowed");
	}
	else
	{	parserData->osoloptimizationPresent = true;	
		osoption->optimization = new OptimizationOption();
	}
;}
    break;

  case 426:

    {	osoption->optimization->numberOfVariables = (yyvsp[(3) - (4)].ival);
;}
    break;

  case 427:

    {	osoption->optimization->numberOfConstraints = (yyvsp[(3) - (4)].ival);
;}
    break;

  case 428:

    {	osoption->optimization->numberOfObjectives = (yyvsp[(3) - (4)].ival);
;}
    break;

  case 431:

    {printf("\n%s\n","Finished <optimization element>");;}
    break;

  case 434:

    {	osoption->optimization->variables = new VariableOption();
;}
    break;

  case 436:

    {	if ((yyvsp[(3) - (4)].ival) < 0) osolerror (NULL, osoption, parserData, "number of <other> variable options cannot be negative");
	osoption->optimization->variables->numberOfOtherVariableOptions = (yyvsp[(3) - (4)].ival);
	osoption->optimization->variables->other = new OtherVariableOption*[(yyvsp[(3) - (4)].ival)];
	for (int i= 0; i < (yyvsp[(3) - (4)].ival); i++)
		osoption->optimization->variables->other[i] = new OtherVariableOption();

;}
    break;

  case 437:

    {   printf("\n%s\n","Matched </variables");
;}
    break;

  case 440:

    {   printf("\n%s\n","Matched </initialVariableValues");
;}
    break;

  case 441:

    {	if ((yyvsp[(3) - (4)].ival) <= 0) osolerror (NULL, osoption, parserData, "number of <var> elements must be positive");
	osoption->optimization->variables->initialVariableValues = new InitVariableValues();
	osoption->optimization->variables->initialVariableValues->numberOfVar = (yyvsp[(3) - (4)].ival);
	osoption->optimization->variables->initialVariableValues->var = new InitVarValue*[(yyvsp[(3) - (4)].ival)];
	for (int i = 0; i < (yyvsp[(3) - (4)].ival); i++)
		osoption->optimization->variables->initialVariableValues->var[i] = new InitVarValue();
;}
    break;

  case 444:

    {	if (!parserData->idxAttributePresent)
		osolerror (NULL, osoption, parserData, "variable index required");
	parserData->idxAttributePresent = false;
	parserData->valAttributePresent = false;
	parserData->numberOfVar++;
	printf("\n%s%d\n","number of var elements ",parserData->numberOfVar);
;}
    break;

  case 445:

    {	if (parserData->numberOfVar >= osoption->optimization->variables->initialVariableValues->numberOfVar)
		osolerror(NULL, osoption, parserData, "too many initial variable values");
	printf("\n%s%d\n","populate var element ",parserData->numberOfVar); // this is matched...
;}
    break;

  case 447:

    {printf("\n%s\n","Just checking...");;}
    break;

  case 451:

    {	// ...but we never get here!
	printf("\n%s%d%s%d\n","found index for element ",parserData->numberOfVar," ",(yyvsp[(3) - (4)].ival));
	if ((yyvsp[(3) - (4)].ival) < 0) osolerror (NULL, osoption, parserData, "variable index must be nonnegative");
	if (parserData->numberOfVariablesPresent)
	{	if ((yyvsp[(3) - (4)].ival) >= parserData->numberOfVariables)
			osolerror (NULL, osoption, parserData, "variable index exceeds upper limit");
	};
	if (parserData->idxAttributePresent)
		osolerror (NULL, osoption, parserData, "only one variable index allowed");
	parserData->idxAttributePresent = true;
	printf("\n%s%d\n","use var element ",parserData->numberOfVar);
	osoption->optimization->variables->initialVariableValues->var[parserData->numberOfVar]->idx = (yyvsp[(3) - (4)].ival);  
;}
    break;

  case 452:

    {	printf("\n%s%d\n","found value for element ",parserData->numberOfVar);
	if (parserData->valAttributePresent)
		osolerror (NULL, osoption, parserData, "only one variable index allowed");
	parserData->valAttributePresent = true;
	printf("\n%s%d\n","use var element ",parserData->numberOfVar);
	osoption->optimization->variables->initialVariableValues->var[parserData->numberOfVar]->value = strtod((yyvsp[(2) - (2)].sval), NULL);  
;}
    break;

  case 454:

    {{printf("\n%s\n","explicit end of <var> element");};}
    break;

  case 455:

    {printf("\n%s\n","trivial end of <var> element");;}
    break;

  case 465:

    {	
;}
    break;

  case 466:

    {
;}
    break;

  case 480:

    {
;}
    break;

  case 482:

    {
;}
    break;

  case 484:

    {
;}
    break;

  case 486:

    {
;}
    break;

  case 488:

    {
;}
    break;

  case 490:

    {
;}
    break;

  case 492:

    {
;}
    break;

  case 502:

    {	
;}
    break;

  case 503:

    {
;}
    break;

  case 504:

    {
;}
    break;

  case 505:

    {
;}
    break;

  case 511:

    {
;}
    break;

  case 523:

    {	
;}
    break;

  case 524:

    {
;}
    break;

  case 536:

    {	
;}
    break;

  case 537:

    {
;}
    break;

  case 551:

    {
;}
    break;

  case 552:

    {
;}
    break;

  case 553:

    {
;}
    break;

  case 554:

    {
;}
    break;

  case 555:

    {
;}
    break;

  case 556:

    {
;}
    break;

  case 557:

    {
;}
    break;

  case 566:

    {	
;}
    break;

  case 567:

    {
;}
    break;

  case 568:

    {
;}
    break;

  case 569:

    {
;}
    break;

  case 575:

    {
;}
    break;

  case 587:

    {	
;}
    break;

  case 588:

    {
;}
    break;

  case 600:

    {	
;}
    break;

  case 601:

    {
;}
    break;

  case 615:

    {
;}
    break;

  case 616:

    {
;}
    break;

  case 617:

    {
;}
    break;

  case 618:

    {
;}
    break;

  case 619:

    {
;}
    break;

  case 620:

    {
;}
    break;

  case 621:

    {
;}
    break;

  case 630:

    {	
;}
    break;

  case 631:

    {
;}
    break;

  case 632:

    {
;}
    break;

  case 633:

    {
;}
    break;

  case 638:

    {
;}
    break;

  case 650:

    {
;}
    break;

  case 651:

    {
;}
    break;

  case 652:

    {
;}
    break;

  case 653:

    {
;}
    break;

  case 654:

    {
;}
    break;

  case 655:

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


