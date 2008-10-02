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
#define YYLAST   723

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  150
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  450
/* YYNRULES -- Number of rules.  */
#define YYNRULES  679
/* YYNRULES -- Number of states.  */
#define YYNSTATES  1152

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
    1209,  1215,  1220,  1221,  1224,  1228,  1230,  1231,  1234,  1236,
    1238,  1243,  1244,  1249,  1252,  1254,  1255,  1261,  1266,  1267,
    1270,  1274,  1276,  1277,  1280,  1282,  1284,  1289,  1290,  1295,
    1298,  1300,  1301,  1305,  1306,  1309,  1311,  1313,  1315,  1317,
    1319,  1321,  1323,  1324,  1330,  1331,  1336,  1337,  1342,  1343,
    1348,  1349,  1354,  1355,  1360,  1361,  1366,  1370,  1374,  1375,
    1378,  1380,  1382,  1384,  1386,  1390,  1394,  1398,  1402,  1405,
    1407,  1408,  1412,  1414,  1415,  1420,  1426,  1428,  1429,  1435,
    1440,  1441,  1444,  1448,  1450,  1451,  1454,  1456,  1458,  1463,
    1464,  1469,  1472,  1474,  1475,  1481,  1486,  1487,  1490,  1494,
    1496,  1497,  1500,  1502,  1504,  1506,  1511,  1512,  1517,  1518,
    1523,  1526,  1528,  1529,  1533,  1534,  1537,  1539,  1541,  1543,
    1545,  1547,  1549,  1551,  1556,  1560,  1564,  1568,  1572,  1576,
    1580,  1584,  1588,  1589,  1592,  1594,  1596,  1598,  1600,  1604,
    1608,  1612,  1616,  1619,  1621,  1622,  1626,  1628,  1629,  1634,
    1640,  1642,  1643,  1649,  1654,  1655,  1658,  1662,  1664,  1665,
    1668,  1670,  1672,  1677,  1678,  1683,  1686,  1688,  1689,  1695,
    1700,  1701,  1704,  1708,  1710,  1711,  1714,  1716,  1718,  1720,
    1725,  1726,  1731,  1732,  1737,  1740,  1742,  1743,  1747,  1748,
    1751,  1753,  1755,  1757,  1759,  1761,  1763,  1765,  1770,  1774,
    1778,  1782,  1786,  1790,  1794,  1798,  1802,  1803,  1806,  1808,
    1810,  1812,  1814,  1818,  1822,  1826,  1830,  1833,  1835,  1836,
    1842,  1847,  1848,  1851,  1855,  1856,  1859,  1861,  1863,  1865,
    1867,  1869,  1871,  1875,  1879,  1883,  1887,  1891,  1895,  1898
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
       9,    -1,   441,   493,   540,   587,    -1,    -1,   442,   443,
     444,    -1,   121,    -1,    -1,    30,     7,     5,     7,    -1,
       8,   445,   456,   467,   122,    -1,     9,    -1,    -1,   123,
     446,     8,   447,   124,    -1,    33,     7,     5,     7,    -1,
      -1,   447,   448,    -1,   449,   450,   455,    -1,   125,    -1,
      -1,   450,   451,    -1,   452,    -1,   453,    -1,    37,     7,
       5,     7,    -1,    -1,    38,     3,   454,     7,    -1,     8,
     126,    -1,     9,    -1,    -1,   127,   457,     8,   458,   128,
      -1,    33,     7,     5,     7,    -1,    -1,   458,   459,    -1,
     460,   461,   466,    -1,   125,    -1,    -1,   461,   462,    -1,
     463,    -1,   464,    -1,    37,     7,     5,     7,    -1,    -1,
      38,     3,   465,     7,    -1,     8,   126,    -1,     9,    -1,
      -1,    75,   468,   484,    -1,    -1,   468,   469,    -1,   470,
      -1,   472,    -1,   474,    -1,   476,    -1,   478,    -1,   480,
      -1,   482,    -1,    -1,    33,     7,     5,   471,     7,    -1,
      -1,    36,     3,   473,     7,    -1,    -1,    38,     3,   475,
       7,    -1,    -1,    22,     3,   477,     7,    -1,    -1,    23,
       3,   479,     7,    -1,    -1,    24,     3,   481,     7,    -1,
      -1,    40,     3,   483,     7,    -1,     8,   485,    76,    -1,
     125,   486,   492,    -1,    -1,   486,   487,    -1,   488,    -1,
     489,    -1,   490,    -1,   491,    -1,    37,     5,     7,    -1,
      38,     3,     7,    -1,    41,     3,     7,    -1,    42,     3,
       7,    -1,     8,   126,    -1,     9,    -1,    -1,   494,   495,
     496,    -1,   129,    -1,    -1,    31,     7,     5,     7,    -1,
       8,   497,   508,   521,   130,    -1,     9,    -1,    -1,   131,
     498,     8,   499,   132,    -1,    34,     7,     5,     7,    -1,
      -1,   499,   500,    -1,   501,   502,   507,    -1,   133,    -1,
      -1,   502,   503,    -1,   504,    -1,   505,    -1,    37,     7,
       5,     7,    -1,    -1,    38,     3,   506,     7,    -1,     8,
     134,    -1,     9,    -1,    -1,   135,   509,     8,   510,   136,
      -1,    34,     7,     5,     7,    -1,    -1,   510,   511,    -1,
     512,   513,   520,    -1,   133,    -1,    -1,   513,   514,    -1,
     515,    -1,   516,    -1,   518,    -1,    37,     7,     5,     7,
      -1,    -1,    41,     3,   517,     7,    -1,    -1,    42,     3,
     519,     7,    -1,     8,   134,    -1,     9,    -1,    -1,    75,
     522,   531,    -1,    -1,   522,   523,    -1,   524,    -1,   525,
      -1,   526,    -1,   527,    -1,   528,    -1,   529,    -1,   530,
      -1,    34,     7,     5,     7,    -1,    36,     3,     7,    -1,
      38,     3,     7,    -1,    22,     3,     7,    -1,    23,     3,
       7,    -1,    24,     3,     7,    -1,    40,     3,     7,    -1,
       8,   532,    76,    -1,   133,   533,   539,    -1,    -1,   533,
     534,    -1,   535,    -1,   536,    -1,   537,    -1,   538,    -1,
      37,     3,     7,    -1,    38,     3,     7,    -1,    41,     3,
       7,    -1,    42,     3,     7,    -1,     8,   126,    -1,     9,
      -1,    -1,   541,   542,   543,    -1,   137,    -1,    -1,    32,
       7,     5,     7,    -1,     8,   544,   555,   568,   138,    -1,
       9,    -1,    -1,   139,   545,     8,   546,   140,    -1,    35,
       7,     5,     7,    -1,    -1,   546,   547,    -1,   548,   549,
     554,    -1,   141,    -1,    -1,   549,   550,    -1,   551,    -1,
     552,    -1,    37,     7,     5,     7,    -1,    -1,    38,     3,
     553,     7,    -1,     8,   142,    -1,     9,    -1,    -1,   143,
     556,     8,   557,   144,    -1,    35,     7,     5,     7,    -1,
      -1,   557,   558,    -1,   559,   560,   567,    -1,   141,    -1,
      -1,   560,   561,    -1,   562,    -1,   563,    -1,   565,    -1,
      37,     7,     5,     7,    -1,    -1,    41,     3,   564,     7,
      -1,    -1,    42,     3,   566,     7,    -1,     8,   142,    -1,
       9,    -1,    -1,    75,   569,   578,    -1,    -1,   569,   570,
      -1,   571,    -1,   572,    -1,   573,    -1,   574,    -1,   575,
      -1,   576,    -1,   577,    -1,    35,     7,     5,     7,    -1,
      36,     3,     7,    -1,    38,     3,     7,    -1,    22,     3,
       7,    -1,    23,     3,     7,    -1,    24,     3,     7,    -1,
      40,     3,     7,    -1,     8,   579,    76,    -1,   141,   580,
     586,    -1,    -1,   580,   581,    -1,   582,    -1,   583,    -1,
     584,    -1,   585,    -1,    37,     3,     7,    -1,    38,     3,
       7,    -1,    41,     3,     7,    -1,    42,     3,     7,    -1,
       8,   142,    -1,     9,    -1,    -1,   145,   588,     8,   589,
     146,    -1,    26,     7,     5,     7,    -1,    -1,   589,   590,
      -1,   147,   591,   599,    -1,    -1,   591,   592,    -1,   593,
      -1,   594,    -1,   595,    -1,   596,    -1,   597,    -1,   598,
      -1,    36,     3,     7,    -1,    38,     3,     7,    -1,    22,
       3,     7,    -1,    23,     3,     7,    -1,    24,     3,     7,
      -1,    40,     3,     7,    -1,     8,   148,    -1,     9,    -1
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
    1444,  1446,  1449,  1449,  1451,  1455,  1455,  1463,  1464,  1466,
    1466,  1468,  1477,  1477,  1479,  1487,  1492,  1492,  1494,  1494,
    1496,  1509,  1508,  1516,  1516,  1519,  1519,  1522,  1531,  1531,
    1533,  1541,  1546,  1546,  1548,  1548,  1550,  1563,  1562,  1570,
    1570,  1573,  1573,  1575,  1575,  1578,  1579,  1580,  1581,  1582,
    1583,  1584,  1587,  1586,  1591,  1590,  1595,  1594,  1599,  1598,
    1603,  1602,  1607,  1606,  1611,  1610,  1615,  1617,  1619,  1619,
    1622,  1623,  1624,  1625,  1627,  1631,  1635,  1639,  1643,  1643,
    1646,  1646,  1648,  1652,  1652,  1660,  1661,  1663,  1663,  1666,
    1675,  1675,  1677,  1685,  1690,  1690,  1692,  1692,  1694,  1708,
    1707,  1715,  1715,  1718,  1718,  1721,  1730,  1730,  1732,  1741,
    1746,  1746,  1748,  1748,  1748,  1750,  1763,  1762,  1771,  1770,
    1778,  1778,  1781,  1781,  1783,  1783,  1786,  1787,  1788,  1789,
    1790,  1791,  1792,  1794,  1798,  1802,  1806,  1810,  1814,  1818,
    1823,  1825,  1827,  1827,  1830,  1831,  1832,  1833,  1835,  1839,
    1843,  1847,  1851,  1851,  1854,  1854,  1856,  1860,  1860,  1868,
    1870,  1872,  1872,  1875,  1884,  1884,  1886,  1894,  1899,  1899,
    1901,  1901,  1903,  1917,  1916,  1924,  1924,  1927,  1927,  1930,
    1939,  1939,  1941,  1950,  1955,  1955,  1957,  1957,  1957,  1959,
    1972,  1971,  1980,  1979,  1988,  1988,  1991,  1991,  1993,  1993,
    1996,  1997,  1998,  1999,  2000,  2001,  2002,  2004,  2008,  2012,
    2016,  2020,  2024,  2028,  2033,  2035,  2037,  2037,  2040,  2041,
    2042,  2043,  2045,  2049,  2053,  2057,  2061,  2061,  2064,  2064,
    2066,  2070,  2070,  2072,  2074,  2074,  2077,  2078,  2079,  2080,
    2081,  2082,  2084,  2088,  2092,  2096,  2100,  2104,  2109,  2109
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
  "initvarvalue", "varstart", "initvarvalueattlist", "initvarvalueatt",
  "initvarvalueidxatt", "initvarvaluevalueatt", "@64", "initvarvalueend",
  "initialvariablevaluesstring", "numberofvarstr", "varstrlist",
  "initvarstrvalue", "varstrstart", "initvarstrvalueattlist",
  "initvarstrvalueatt", "initvarstrvalueidxatt", "initvarstrvaluevalueatt",
  "@65", "initvarstrvalueend", "othervariableoptions",
  "othervariableoptionsattlist", "othervariableoptionsatt",
  "othervariableoptionnumberofvar", "@66", "othervariableoptionname",
  "@67", "othervariableoptionvalue", "@68", "othervariableoptionsolver",
  "@69", "othervariableoptioncategory", "@70", "othervariableoptiontype",
  "@71", "othervariableoptiondescription", "@72",
  "restofothervariableoptions", "othervariableoptionsvarlist",
  "othervaroptionattlist", "othervaroptionatt", "othervaroptionidx",
  "othervaroptionvalue", "othervaroptionlbvalue", "othervaroptionubvalue",
  "othervaroptionend", "objectives", "objectivesstart",
  "numberofotherobjectivesatt", "restofobjectives",
  "initialobjectivevalues", "numberofobjval", "objvaluelist",
  "initobjvalue", "objvaluestart", "initobjvalueattlist",
  "initobjvalueatt", "initobjvalueidxatt", "initobjvaluevalueatt", "@73",
  "initobjvalueend", "initialobjectivebounds", "numberofobjbounds",
  "objboundlist", "initobjbound", "objboundstart", "initobjboundattlist",
  "initobjboundatt", "initobjboundidxatt", "initobjvaluelowerboundatt",
  "@74", "initobjvalueupperboundatt", "@75", "initobjboundend",
  "otherobjectiveoptions", "otherobjectiveoptionsattlist",
  "otherobjectiveoptionsatt", "otherobjectiveoptionnumberofvar",
  "otherobjectiveoptionname", "otherobjectiveoptionvalue",
  "otherobjectiveoptionsolver", "otherobjectiveoptioncategory",
  "otherobjectiveoptiontype", "otherobjectiveoptiondescription",
  "restofotherobjectiveoptions", "otherobjectiveoptionsvarlist",
  "otherobjoptionattlist", "otherobjoptionatt", "otherobjoptionidx",
  "otherobjoptionvalue", "otherobjoptionlbvalue", "otherobjoptionubvalue",
  "otherobjoptionend", "constraints", "constraintsstart",
  "numberofotherconstraintsatt", "restofconstraints",
  "initialconstraintvalues", "numberofconval", "conlist", "initconvalue",
  "constart", "initconvalueattlist", "initconvalueatt",
  "initconvalueidxatt", "initconvaluevalueatt", "@76", "initconvalueend",
  "initialdualvalues", "numberofduals", "duallist", "initdualvalue",
  "dualstart", "initdualvalueattlist", "initdualvalueatt",
  "initdualvalueidxatt", "initdualvaluelowerboundatt", "@77",
  "initdualvalueupperboundatt", "@78", "initdualvalueend",
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
     445,   446,   447,   447,   448,   449,   450,   450,   451,   451,
     452,   454,   453,   455,   455,   456,   456,   457,   458,   458,
     459,   460,   461,   461,   462,   462,   463,   465,   464,   466,
     466,   467,   467,   468,   468,   469,   469,   469,   469,   469,
     469,   469,   471,   470,   473,   472,   475,   474,   477,   476,
     479,   478,   481,   480,   483,   482,   484,   485,   486,   486,
     487,   487,   487,   487,   488,   489,   490,   491,   492,   492,
     493,   493,   494,   495,   495,   496,   496,   497,   497,   498,
     499,   499,   500,   501,   502,   502,   503,   503,   504,   506,
     505,   507,   507,   508,   508,   509,   510,   510,   511,   512,
     513,   513,   514,   514,   514,   515,   517,   516,   519,   518,
     520,   520,   521,   521,   522,   522,   523,   523,   523,   523,
     523,   523,   523,   524,   525,   526,   527,   528,   529,   530,
     531,   532,   533,   533,   534,   534,   534,   534,   535,   536,
     537,   538,   539,   539,   540,   540,   541,   542,   542,   543,
     543,   544,   544,   545,   546,   546,   547,   548,   549,   549,
     550,   550,   551,   553,   552,   554,   554,   555,   555,   556,
     557,   557,   558,   559,   560,   560,   561,   561,   561,   562,
     564,   563,   566,   565,   567,   567,   568,   568,   569,   569,
     570,   570,   570,   570,   570,   570,   570,   571,   572,   573,
     574,   575,   576,   577,   578,   579,   580,   580,   581,   581,
     581,   581,   582,   583,   584,   585,   586,   586,   587,   587,
     588,   589,   589,   590,   591,   591,   592,   592,   592,   592,
     592,   592,   593,   594,   595,   596,   597,   598,   599,   599
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
       5,     4,     0,     2,     3,     1,     0,     2,     1,     1,
       4,     0,     4,     2,     1,     0,     5,     4,     0,     2,
       3,     1,     0,     2,     1,     1,     4,     0,     4,     2,
       1,     0,     3,     0,     2,     1,     1,     1,     1,     1,
       1,     1,     0,     5,     0,     4,     0,     4,     0,     4,
       0,     4,     0,     4,     0,     4,     3,     3,     0,     2,
       1,     1,     1,     1,     3,     3,     3,     3,     2,     1,
       0,     3,     1,     0,     4,     5,     1,     0,     5,     4,
       0,     2,     3,     1,     0,     2,     1,     1,     4,     0,
       4,     2,     1,     0,     5,     4,     0,     2,     3,     1,
       0,     2,     1,     1,     1,     4,     0,     4,     0,     4,
       2,     1,     0,     3,     0,     2,     1,     1,     1,     1,
       1,     1,     1,     4,     3,     3,     3,     3,     3,     3,
       3,     3,     0,     2,     1,     1,     1,     1,     3,     3,
       3,     3,     2,     1,     0,     3,     1,     0,     4,     5,
       1,     0,     5,     4,     0,     2,     3,     1,     0,     2,
       1,     1,     4,     0,     4,     2,     1,     0,     5,     4,
       0,     2,     3,     1,     0,     2,     1,     1,     1,     4,
       0,     4,     0,     4,     2,     1,     0,     3,     0,     2,
       1,     1,     1,     1,     1,     1,     1,     4,     3,     3,
       3,     3,     3,     3,     3,     3,     0,     2,     1,     1,
       1,     1,     3,     3,     3,     3,     2,     1,     0,     5,
       4,     0,     2,     3,     0,     2,     1,     1,     1,     1,
       1,     1,     3,     3,     3,     3,     3,     3,     2,     1
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
       0,    90,     0,     0,    91,     0,   434,     0,   510,   435,
       0,     0,     0,     0,     0,     0,   257,   255,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   206,     0,   133,   131,
     130,     0,   144,   142,   141,     0,   155,   153,   152,     0,
       0,   163,     0,    30,    36,    42,    47,    49,    57,    63,
      69,    75,    81,    86,    88,    93,    94,    97,    96,   429,
     512,   584,   513,     0,     0,     0,     0,     0,   247,     0,
     249,   244,   259,   258,     0,   264,     0,   271,     0,   278,
       0,   285,     0,   292,     0,   299,     0,   319,     0,   339,
       0,   359,     0,   379,     0,   386,     0,   393,     0,   401,
     201,     0,   202,     0,   128,     0,     0,   139,     0,     0,
     150,     0,     0,   162,   165,   166,   169,   168,    99,   586,
     658,   587,     0,     0,     0,   439,   438,   433,   426,   428,
     427,     0,   253,   251,   250,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   397,     0,   204,   205,   208,   207,   134,   132,   145,
     143,   156,   154,   171,     0,     0,   431,     0,     0,     0,
     517,   516,   511,     0,     0,   455,   248,     0,     0,   260,
     263,     0,   261,   265,   270,   268,     0,   272,   277,   275,
       0,   279,   284,     0,   282,   286,   291,     0,   289,   293,
     298,   302,   296,   300,   303,   318,   322,   316,   320,   323,
     338,   342,   336,   340,   343,   358,   362,   356,   360,   363,
     378,     0,   376,   380,   385,     0,   383,   387,   392,   390,
       0,   394,   399,   400,   403,   402,   210,   182,     0,   110,
       0,     0,     0,   100,   101,   102,   103,    98,     0,     0,
       0,   591,   590,   585,     0,     0,   533,   436,     0,     0,
       0,   471,   254,   252,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   405,     0,     0,     0,
       0,   172,   173,   174,   175,   170,     0,     0,   111,   104,
     106,   108,     0,   661,     0,     0,   607,   514,     0,     0,
       0,   552,     0,   442,     0,     0,   473,     0,   266,   273,
     280,   287,   294,     0,   315,     0,     0,     0,   304,   305,
     306,   307,   301,     0,   335,     0,     0,     0,   324,   325,
     326,   327,   321,     0,   355,     0,     0,     0,   344,   345,
     346,   347,   341,     0,   375,     0,     0,     0,   364,   365,
     366,   367,   361,   381,   388,   395,     0,     0,   221,     0,
       0,     0,   211,   212,   213,   214,   209,   176,   178,   180,
     183,     0,     0,     0,     0,     0,     0,   588,     0,     0,
       0,   626,     0,   520,     0,     0,   554,     0,     0,     0,
       0,   458,     0,   437,     0,     0,     0,     0,     0,   314,
     308,   310,   312,   334,   328,   330,   332,   354,   348,   350,
     352,   374,   368,   370,   372,     0,     0,     0,     0,   416,
       0,     0,     0,   406,   407,   408,   409,   404,   222,   215,
     217,   219,     0,     0,     0,   185,   105,   107,   109,   660,
     659,   664,   662,     0,   594,     0,     0,   628,     0,     0,
       0,     0,   536,     0,   515,   441,   440,   445,   443,   446,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     474,   475,   476,   477,   478,   479,   480,   481,   472,   267,
     274,   281,   288,   295,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   382,   389,   396,   417,
     410,   412,   414,     0,     0,     0,   177,   179,   181,     0,
       0,     0,     0,   610,     0,   589,   519,   518,   523,   521,
     524,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   555,   556,   557,   558,   559,   560,   561,   562,   553,
       0,   457,   461,   456,   459,   462,   498,     0,   488,   490,
     492,     0,   484,   486,   494,   309,   311,   313,   329,   331,
     333,   349,   351,   353,   369,   371,   373,     0,     0,     0,
     216,   218,   220,     0,   679,     0,     0,     0,     0,     0,
       0,   665,   666,   667,   668,   669,   670,   671,   663,   593,
     592,   597,   595,   598,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   629,   630,   631,   632,   633,   634,
     635,   636,   627,     0,   535,   539,   534,   537,   540,   572,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   454,
       0,     0,   447,   448,   449,   444,     0,     0,   496,     0,
       0,     0,   482,     0,     0,     0,   411,   413,   415,   678,
       0,     0,     0,     0,     0,     0,     0,   609,   613,   608,
     611,   614,   646,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   532,     0,     0,   525,   526,   527,   522,     0,
       0,   570,   566,   567,   568,     0,   564,   565,   569,   453,
       0,   451,     0,   470,     0,     0,   463,   464,   465,   460,
       0,   509,     0,     0,     0,     0,   499,   500,   501,   502,
     503,   497,   489,   491,   493,     0,   485,   487,   495,   674,
     675,   676,   672,   673,   677,     0,   606,     0,     0,   599,
     600,   601,   596,     0,     0,   644,   640,   641,   642,     0,
     638,   639,   643,   531,     0,   529,     0,   551,     0,     0,
       0,   541,   542,   543,   544,   538,     0,   583,     0,     0,
       0,     0,   573,   574,   575,   576,   577,   571,   563,     0,
       0,   469,     0,   467,   508,     0,     0,     0,     0,   483,
     605,     0,   603,     0,   625,     0,     0,     0,   615,   616,
     617,   618,   612,     0,   657,     0,     0,     0,     0,   647,
     648,   649,   650,   651,   645,   637,     0,     0,   550,     0,
     546,   548,   582,     0,     0,     0,     0,   450,   452,     0,
       0,   504,   505,   506,   507,     0,     0,   624,     0,   620,
     622,   656,     0,     0,     0,     0,   528,   530,     0,     0,
       0,   578,   579,   580,   581,   466,   468,   602,   604,     0,
       0,     0,   652,   653,   654,   655,   545,   547,   549,   619,
     621,   623
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
     454,   533,   534,   662,   535,   663,   536,   664,   537,    14,
      15,    24,    32,    81,    82,    83,   136,   307,   236,   386,
     385,    84,    85,   138,   311,   240,   389,   388,    86,    87,
     140,   315,   244,   392,   391,    88,    89,   143,   319,    90,
      91,   145,   321,   322,   397,   453,   527,   571,   572,   722,
     573,   723,   574,   724,   575,   576,   577,    20,    21,    31,
      74,   129,   130,   131,   132,   304,   133,   134,   232,   382,
     383,   446,   526,   567,   652,   653,   793,   654,   794,   655,
     795,   656,    27,    28,    73,   123,   198,   199,   200,   274,
     411,   351,   468,   467,   201,   202,   277,   415,   203,   204,
     279,   417,   473,   684,   205,   206,   281,   419,   477,   685,
     207,   208,   283,   421,   481,   686,   209,   210,   285,   423,
     485,   687,   211,   212,   287,   425,   489,   688,   213,   214,
     289,   427,   493,   494,   559,   608,   609,   774,   610,   775,
     611,   776,   612,   215,   216,   291,   429,   498,   499,   560,
     618,   619,   777,   620,   778,   621,   779,   622,   217,   218,
     293,   431,   503,   504,   561,   628,   629,   780,   630,   781,
     631,   782,   632,   219,   220,   295,   433,   508,   509,   562,
     638,   639,   783,   640,   784,   641,   785,   642,   221,   222,
     297,   435,   513,   705,   223,   224,   299,   437,   517,   706,
     225,   226,   301,   439,   521,   707,   227,   228,   303,   441,
     442,   525,   566,   646,   713,   714,   857,   715,   858,   716,
     859,   717,    69,    70,   122,   177,   178,   179,   180,   181,
     267,   268,   269,   344,   407,   465,   549,   679,   748,   749,
     830,   922,   923,   924,  1060,   925,   551,   595,   751,   834,
     835,   926,   986,   987,   988,  1110,   989,   597,   682,   760,
     761,  1005,   762,   933,   763,   934,   764,   929,   765,   930,
     766,   931,   767,   935,   768,   837,   927,   996,   997,   998,
     999,  1000,  1001,   341,   342,   403,   462,   546,   589,   740,
     809,   810,   903,   965,   966,   967,  1097,   968,   591,   675,
     812,   907,   908,   969,  1041,  1042,  1043,  1129,  1044,  1130,
    1045,   677,   743,   821,   822,   823,   824,   825,   826,   827,
     828,   829,   910,   970,  1052,  1053,  1054,  1055,  1056,  1057,
     400,   401,   458,   543,   586,   669,   801,   882,   883,   946,
    1019,  1020,  1021,  1116,  1022,   671,   736,   885,   950,   951,
    1023,  1078,  1079,  1080,  1140,  1081,  1141,  1082,   738,   804,
     894,   895,   896,   897,   898,   899,   900,   901,   902,   953,
    1024,  1089,  1090,  1091,  1092,  1093,  1094,   456,   539,   666,
     732,   799,   871,   872,   873,   874,   875,   876,   877,   878
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -94
static const yytype_int16 yypact[] =
{
      39,    20,    55,   111,   -94,   -94,    22,   -94,   -94,    59,
      30,   193,   -94,   -94,    43,   210,   -94,   -94,   -94,   -94,
      47,   244,   -94,   -94,   -94,   170,   -94,    53,   256,   -94,
     -94,   -94,   -20,   -94,   -94,   -94,   -94,   -94,   -94,   -94,
     -94,   -94,   -94,   -94,   -94,   -94,   -94,   258,   -94,   260,
     -94,   262,   -94,    54,   -94,   264,   -94,   266,   -94,   268,
     -94,   270,   -94,   272,   -94,    96,   -94,   146,   -94,   -94,
     -94,   -94,   -94,   -94,     3,   -94,   -94,   -94,   -94,   -94,
     -94,   -94,   -94,   124,   -94,   126,   -94,   132,   -94,   274,
     -94,   152,    18,   -94,   -94,    17,   -94,   -94,    16,   -94,
     -94,   179,   276,    15,   -94,   -94,    14,   -94,   -94,    13,
     -94,   -94,    12,   -94,   -94,    21,   -94,   -94,   181,   278,
     166,   178,   188,   -49,     1,   -94,   -94,   -94,   -94,   -94,
     -94,   -94,   -94,   -94,   173,   187,   280,   200,   282,   217,
     284,    -1,   -94,   -94,   206,   186,   -94,   -94,   -94,   -94,
     -94,   -94,   -94,   220,   -94,   -94,   -94,   -94,   -94,   -94,
     -94,   -94,   -94,   -94,   -94,   -94,   -94,   224,   -94,   -94,
     221,   -94,   113,   -94,   223,   225,   229,   -94,   -94,   -94,
     -94,   -94,   -94,   -94,   -94,   -94,   -94,   -94,   -94,   -94,
     -94,   -94,   -94,   -94,   -94,   -94,   -94,   -94,   -94,   -94,
     199,   -94,   286,   -94,   308,   -94,   237,   -94,   309,   -94,
     310,   -94,   311,   -94,   307,   -94,   312,   -94,   313,   -94,
     314,   -94,   316,   -94,   317,   -94,   215,   -94,   227,   -94,
     -94,   322,   327,   -94,     4,   -94,   -94,   -94,     9,   -94,
     -94,   -94,     2,   -94,   -94,   -94,   -94,   331,   -94,   283,
     285,   281,   333,   -94,   287,   288,   279,   289,   277,   291,
     335,   -94,   292,   337,   -94,   222,   -94,   296,   209,   319,
     341,   346,   347,   350,   290,    -4,   -94,   -94,   349,   351,
     353,   354,   356,   357,   359,   360,   362,   363,   365,   366,
     368,   369,   371,   372,   374,   375,   377,   378,   380,   381,
     383,   384,   386,   387,   271,   389,   -94,   390,   -94,   -94,
     -94,   391,   -94,   -94,   -94,   392,   -94,   -94,   -94,   295,
     393,   -94,   226,   -94,   -94,   -94,   -94,   -94,   -94,   -94,
     -94,   -94,   -94,   -94,   -94,   -94,   -94,   -94,   -94,   -94,
     -94,   233,   323,   394,   294,   395,   396,   397,   -94,    -3,
     -94,   -94,   -94,   -94,   400,   -94,   401,   -94,   402,   -94,
     403,   -94,   404,   -94,   405,   -94,   406,   -94,   407,   -94,
     408,   -94,   409,   -94,   410,   -94,   411,   -94,   412,   -94,
     -94,   413,   -94,   230,   -94,   304,   318,   -94,   293,   305,
     -94,   336,   339,   -94,   -94,   -94,   -94,   -94,   -94,   -94,
     213,   344,   415,   298,   414,   265,   -94,   -94,   -94,   -94,
     -94,   416,   -94,   -94,   -94,   301,   417,   -56,   418,   101,
     419,   212,   420,    41,   421,    58,   422,   -76,   423,   -62,
     424,   -66,   425,   -69,   426,     0,   427,     8,   428,   192,
     429,   -94,   238,   -94,   -94,   -94,   -94,   -94,   -94,   -94,
     -94,   -94,   -94,   -94,   109,   430,   -94,   431,   306,   432,
     315,   -94,   -94,   433,   334,   320,   -94,   355,   361,   -94,
     -94,   434,   -94,   -94,   -94,   -94,   436,   -94,   -94,   -94,
     437,   -94,   -94,   440,   -94,   -94,   -94,   442,   -94,   -94,
     -94,   -94,   -94,   -94,   -94,   -94,   -94,   -94,   -94,   -94,
     -94,   -94,   -94,   -94,   -94,   -94,   -94,   -94,   -94,   -94,
     -94,   443,   -94,   -94,   -94,   444,   -94,   -94,   -94,   -94,
     445,   -94,   -94,   -94,   -94,   -94,   -94,    73,   379,   -94,
     438,   451,   454,   -94,   -94,   -94,   -94,   -94,   452,   450,
     455,   300,   -94,   -94,   456,   435,   326,   -94,   457,   458,
     439,   398,   -94,   -94,   461,   463,   464,   466,   467,   191,
     236,   239,   242,   470,   471,   472,   -94,   145,   459,   474,
     475,   -94,   -94,   -94,   -94,   -94,   473,   476,   -94,   -94,
     -94,   -94,   478,   -94,   479,   446,   342,   -94,   480,   481,
     460,   441,   483,   -94,   484,   482,   -94,   358,   -94,   -94,
     -94,   -94,   -94,   399,   -94,   489,   490,   492,   -94,   -94,
     -94,   -94,   -94,   447,   -94,   493,   494,   495,   -94,   -94,
     -94,   -94,   -94,   448,   -94,   497,   498,   499,   -94,   -94,
     -94,   -94,   -94,   449,   -94,   500,   501,   502,   -94,   -94,
     -94,   -94,   -94,   -94,   -94,   -94,   151,   453,   -94,   503,
     504,   505,   -94,   -94,   -94,   -94,   -94,   -94,   -94,   -94,
     -94,   462,   506,   507,   508,   510,   172,   -94,   511,   512,
     477,   465,   514,   -94,   515,   513,   -94,   468,   516,   196,
     519,   -94,   108,   -94,   469,   485,   486,   487,   488,   -94,
     -94,   -94,   -94,   -94,   -94,   -94,   -94,   -94,   -94,   -94,
     -94,   -94,   -94,   -94,   -94,   491,   496,   509,   517,   -94,
     522,   523,   524,   -94,   -94,   -94,   -94,   -94,   -94,   -94,
     -94,   -94,   521,   525,   526,   -94,   -94,   -94,   -94,   -94,
     -94,   -94,   -94,   529,   -94,   528,   531,   -94,   373,   530,
     190,   536,   -94,     5,   -94,   -94,   -94,   -94,   -94,   -94,
     535,   -93,   385,   527,   533,   540,   537,   542,   543,   547,
     -94,   -94,   -94,   -94,   -94,   -94,   -94,   -94,   -94,   -94,
     -94,   -94,   -94,   -94,   544,   545,   546,   548,   549,   550,
     551,   552,   553,   554,   555,   556,   -94,   -94,   -94,   -94,
     -94,   -94,   -94,   557,   558,   559,   -94,   -94,   -94,   128,
     560,   176,   563,   -94,   134,   -94,   -94,   -94,   -94,   -94,
     -94,   562,   -21,   376,   567,   568,   569,   566,   571,   572,
     573,   -94,   -94,   -94,   -94,   -94,   -94,   -94,   -94,   -94,
     167,   -94,   -94,   -94,   -94,   -94,   -94,   520,   -94,   -94,
     -94,   574,   -94,   -94,   -94,   -94,   -94,   -94,   -94,   -94,
     -94,   -94,   -94,   -94,   -94,   -94,   -94,   570,   575,   580,
     -94,   -94,   -94,   518,   -94,   577,   578,   585,   587,   588,
     589,   -94,   -94,   -94,   -94,   -94,   -94,   -94,   -94,   -94,
     -94,   -94,   -94,   -94,   590,   105,   338,   592,   596,   597,
     594,   599,   600,   601,   -94,   -94,   -94,   -94,   -94,   -94,
     -94,   -94,   -94,   169,   -94,   -94,   -94,   -94,   -94,   -94,
     532,   598,   602,   603,   606,   605,   607,   608,   534,   -94,
     609,   604,   -94,   -94,   -94,   -94,   171,    61,   -94,   610,
     611,   612,   -94,   613,   614,   615,   -94,   -94,   -94,   -94,
     616,   617,   618,   619,   620,   621,   184,   -94,   -94,   -94,
     -94,   -94,   -94,   561,   623,   624,   625,   628,   627,   629,
     631,   538,   -94,   632,   637,   -94,   -94,   -94,   -94,    92,
      84,   -94,   -94,   -94,   -94,   634,   -94,   -94,   -94,   -94,
     630,   -94,   539,   -94,   635,   640,   -94,   -94,   -94,   -94,
     541,   -94,   639,   642,   643,   644,   -94,   -94,   -94,   -94,
     -94,   -94,   -94,   -94,   -94,   641,   -94,   -94,   -94,   -94,
     -94,   -94,   -94,   -94,   -94,   564,   -94,   645,   646,   -94,
     -94,   -94,   -94,    98,    86,   -94,   -94,   -94,   -94,   647,
     -94,   -94,   -94,   -94,   648,   -94,   565,   -94,   649,   652,
     654,   -94,   -94,   -94,   -94,   -94,   576,   -94,   655,   656,
     658,   659,   -94,   -94,   -94,   -94,   -94,   -94,   -94,   657,
     661,   -94,   664,   -94,   -94,   663,   666,   667,   668,   -94,
     -94,   671,   -94,   579,   -94,   670,   660,   675,   -94,   -94,
     -94,   -94,   -94,   581,   -94,   676,   677,   678,   679,   -94,
     -94,   -94,   -94,   -94,   -94,   -94,   680,   681,   -94,   684,
     -94,   -94,   -94,   683,   685,   686,   687,   -94,   -94,   688,
     689,   -94,   -94,   -94,   -94,   690,   691,   -94,   695,   -94,
     -94,   -94,   694,   696,   697,   698,   -94,   -94,   700,   701,
     702,   -94,   -94,   -94,   -94,   -94,   -94,   -94,   -94,   703,
     704,   705,   -94,   -94,   -94,   -94,   -94,   -94,   -94,   -94,
     -94,   -94
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
     352,   182,   412,   413,   245,   471,   229,   316,   317,   308,
     309,   124,   125,   813,   312,   313,   162,   160,   158,   156,
     150,   148,   146,   491,   183,   164,    75,   814,   815,   816,
     506,     4,   832,   501,   492,   833,   472,   496,   184,   817,
     185,   818,   186,   819,   187,   820,   188,   507,   502,     1,
     497,   126,   189,    76,   190,     5,   191,    77,   192,    78,
     193,    79,   194,    80,   195,     8,   196,   101,   197,   990,
     991,    12,   147,   149,   151,    13,   127,   157,   159,   161,
     163,  -184,   310,   246,   318,   414,   353,   230,   128,   314,
      19,   165,  1046,  1047,  1083,  1084,    26,   511,   992,   993,
    1036,  1037,   994,   995,    68,   515,  1073,  1074,   512,   568,
     118,   569,   905,   570,   516,   906,   752,   528,   529,     6,
       7,  1048,  1049,  1085,  1086,  1050,  1051,  1087,  1088,  1038,
     753,   754,   755,  1039,  1040,  1075,   863,   864,   483,  1076,
    1077,   756,   886,   484,   757,   530,   758,   531,   759,   532,
     865,   866,   867,   647,   648,   487,   887,   888,   889,   708,
     709,   120,   488,   135,   868,   137,   869,   144,   870,   890,
     891,   139,   892,   170,   893,   918,   919,   961,   962,   982,
     983,   649,   152,   650,   166,   651,   171,   710,   231,   711,
     233,   712,  1015,  1016,   248,   475,   172,   173,   476,   603,
     604,    16,    17,   237,   920,   921,   963,   964,   984,   985,
     605,   606,   607,   247,    33,   174,   175,   176,    22,    23,
     241,  1017,  1018,    34,   253,    35,   263,    36,   261,    37,
     270,    38,   271,    39,   266,    40,   272,    41,   273,    42,
     300,    43,   302,    44,   613,   614,   948,   623,   624,   949,
     633,   634,    29,    30,   280,   615,   616,   617,   625,   626,
     627,   635,   636,   637,    71,    72,    92,    93,    95,    96,
      98,    99,   103,   104,   106,   107,   109,   110,   112,   113,
     115,   116,   141,   142,   153,   154,   167,   168,   234,   235,
     238,   239,   242,   243,   275,   276,   336,   337,   349,   350,
     395,   396,   405,   406,   444,   445,   460,   461,   479,   480,
     519,   520,   523,   524,   541,   542,   880,   881,   730,   731,
     746,   747,   807,   808,   278,   288,   282,   284,   286,   305,
     290,   292,   294,   296,   298,   306,   320,   323,   340,   325,
     326,   324,   333,   329,   335,   331,   345,   327,   339,   343,
     328,   346,   347,   348,   402,   330,   354,   380,   455,   355,
     356,   332,   357,   358,   334,   359,   360,   548,   361,   362,
     399,   363,   364,   449,   365,   366,   457,   367,   368,   393,
     369,   370,   447,   371,   372,   450,   373,   374,   464,   375,
     376,   469,   377,   378,   381,   379,   448,   384,   387,   390,
     394,   404,   408,   409,   410,   416,   418,   420,   422,   424,
     426,   428,   430,   432,   434,   436,   438,   440,   451,   463,
     443,   452,   459,   466,   470,   474,   478,   482,   486,   490,
     495,   500,   505,   510,   514,   518,   522,   544,   540,   585,
     547,   579,   554,   552,   555,   556,   545,   550,   557,   553,
     558,   563,   564,   565,   580,   578,   538,   581,   583,   582,
     584,   590,   657,   587,   592,   598,   593,   599,   600,   588,
     601,   602,   594,   596,   643,   644,   645,   658,   659,   952,
     683,   668,   660,   665,   661,   670,   667,   672,   678,   673,
     681,   680,   690,   691,   674,   692,   694,   695,   696,   689,
     698,   699,   700,   702,   703,   704,   719,   720,   721,   909,
     836,   805,   735,   726,   727,   728,   676,   729,   733,   739,
     734,   742,   741,   745,   750,   790,   791,   792,   796,   718,
     838,   769,   797,   798,   800,   802,   839,   806,   725,   803,
     737,   811,   831,   840,   841,   842,   843,   693,   697,   701,
     844,   845,   846,   847,     0,   848,   849,   850,   851,   852,
     853,   854,   855,   856,   860,   861,   862,   879,   884,   904,
     911,   912,   913,   914,   915,   916,   917,   936,     0,   932,
     940,   941,   937,   770,   771,   772,   773,   938,   942,   786,
     943,   944,   945,   789,   787,   954,   928,   947,   744,   955,
     956,   957,   958,   959,   960,   972,     0,   981,   971,   973,
     974,   975,   976,     0,   977,   978,   980,  1002,  1003,  1004,
    1006,  1007,  1008,  1009,  1010,  1011,  1012,  1013,  1014,   788,
    1026,  1027,  1028,  1029,  1030,  1059,  1031,  1025,  1032,  1034,
    1035,  1058,  1062,  1063,  1065,  1066,  1067,  1068,  1069,  1072,
       0,     0,  1071,  1096,  1095,  1100,  1099,  1101,  1103,  1104,
     979,  1105,  1106,  1119,  1107,  1061,   939,  1064,  1108,  1109,
    1111,     0,  1033,  1112,  1113,  1114,  1115,  1118,  1120,  1122,
    1123,  1124,  1125,     0,     0,     0,     0,  1126,  1127,  1128,
    1131,     0,  1132,  1133,  1134,  1135,  1136,  1137,  1138,  1098,
    1139,  1142,  1102,  1143,  1144,  1145,  1070,  1146,  1147,  1148,
    1149,  1150,  1151,     0,     0,     0,     0,     0,     0,     0,
       0,  1117,     0,  1121
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
      68,     8,    78,    84,    82,    88,    90,    86,    85,    80,
      47,    70,     8,     9,     8,     9,    49,    97,    37,    38,
       8,     9,    41,    42,    51,    97,     8,     9,   108,    36,
      14,    38,   133,    40,   106,   136,     8,     8,     9,     8,
       9,    37,    38,    37,    38,    41,    42,    41,    42,    37,
      22,    23,    24,    41,    42,    37,     8,     9,    97,    41,
      42,    33,     8,   102,    36,    36,    38,    38,    40,    40,
      22,    23,    24,     8,     9,    97,    22,    23,    24,     8,
       9,    15,   104,    39,    36,    39,    38,    15,    40,    35,
      36,    39,    38,     7,    40,     8,     9,     8,     9,     8,
       9,    36,     3,    38,     3,    40,     8,    36,    15,    38,
       3,    40,     8,     9,     8,    94,     8,     9,    97,     8,
       9,     8,     9,     3,    37,    38,    37,    38,    37,    38,
      19,    20,    21,     7,    44,    27,    28,    29,     8,     9,
       3,    37,    38,    53,     4,    55,     5,    57,     4,    59,
       7,    61,     7,    63,   121,    65,     7,    67,    39,    69,
      25,    71,    15,    73,     8,     9,   141,     8,     9,   144,
       8,     9,     8,     9,    17,    19,    20,    21,    19,    20,
      21,    19,    20,    21,     8,     9,     8,     9,     8,     9,
       8,     9,     8,     9,     8,     9,     8,     9,     8,     9,
       8,     9,     8,     9,     8,     9,     8,     9,     8,     9,
       8,     9,     8,     9,     8,     9,    74,    75,     8,     9,
      74,    75,     8,     9,    74,    75,     8,     9,    96,    97,
     118,   119,    74,    75,     8,     9,   140,   141,   146,   147,
     124,   125,   132,   133,    16,    18,    17,    17,    17,     7,
      18,    18,    18,    17,    17,     8,     5,    54,   129,    58,
       7,    56,     7,    64,     7,    68,     5,    60,    52,    30,
      62,     5,     5,     3,    31,    66,     7,    86,   145,     8,
       7,    70,     8,     7,    72,     8,     7,    33,     8,     7,
     137,     8,     7,    80,     8,     7,    32,     8,     7,    84,
       8,     7,    78,     8,     7,    80,     8,     7,   123,     8,
       7,    90,     8,     7,     5,     8,    78,     7,     7,     7,
       7,     7,     7,     7,     7,     5,     5,     5,     5,     5,
       5,     5,     5,     5,     5,     5,     5,     5,    82,     5,
       7,    82,     7,     7,     7,     7,     7,     7,     7,     7,
       7,     7,     7,     7,     7,     7,     7,     5,     7,   139,
       7,     3,     8,    88,     8,     8,   131,   127,     8,    88,
       8,     8,     8,     8,     3,    76,    26,     3,     8,     7,
       5,   135,     3,     7,     7,     4,     8,     4,     4,    34,
       4,     4,    33,    75,     4,     4,     4,     3,     3,   141,
     122,    35,     9,     5,     8,   143,     7,     7,     5,     8,
       8,     7,     3,     3,    34,     3,     3,     3,     3,   100,
       3,     3,     3,     3,     3,     3,     3,     3,     3,   133,
     125,   138,    35,     7,     7,     7,    75,     7,     7,     5,
       8,     8,     7,     7,     5,     3,     3,     3,     7,    76,
       3,    62,     7,     7,     5,     7,     3,     7,    76,     8,
      75,     5,     7,     3,     7,     3,     3,   100,   100,   100,
       3,     7,     7,     7,    -1,     7,     7,     7,     7,     7,
       7,     7,     7,     7,     7,     7,     7,     7,     5,     7,
       3,     3,     3,     7,     3,     3,     3,     7,    -1,     5,
       3,     3,     7,    98,    98,    98,    98,     7,     3,    98,
       3,     3,     3,    76,    98,     3,    76,     7,   130,     3,
       3,     7,     3,     3,     3,     7,    -1,     3,    76,     7,
       7,     5,     7,    -1,     7,     7,     7,     7,     7,     7,
       7,     7,     7,     7,     7,     7,     7,     7,     7,   120,
       7,     7,     7,     5,     7,     5,     7,    76,     7,     7,
       3,     7,     7,     3,     5,     3,     3,     3,     7,     3,
      -1,    -1,     7,     5,     7,     3,     7,     3,     3,     3,
     126,     3,     3,     3,     7,   126,   148,   126,     7,     5,
       7,    -1,   134,     7,     7,     7,     5,     7,     3,     3,
       3,     3,     3,    -1,    -1,    -1,    -1,     7,     7,     5,
       7,    -1,     7,     7,     7,     7,     7,     7,     7,   134,
       5,     7,   126,     7,     7,     7,   142,     7,     7,     7,
       7,     7,     7,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   142,    -1,   142
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
     129,   493,   494,    30,   443,     5,     5,     5,     3,     8,
       9,   301,     4,    90,     7,     8,     7,     8,     7,     8,
       7,     8,     7,     8,     7,     8,     7,     8,     7,     8,
       7,     8,     7,     8,     7,     8,     7,     8,     7,     8,
      86,     5,   279,   280,     7,   230,   229,     7,   237,   236,
       7,   244,   243,    84,     7,    74,    75,   254,   209,   137,
     540,   541,    31,   495,     7,     8,     9,   444,     7,     7,
       7,   300,     5,     6,    88,   307,     5,   311,     5,   317,
       5,   323,     5,   329,     5,   335,     5,   341,     5,   356,
       5,   371,     5,   386,     5,   401,     5,   407,     5,   413,
       5,   419,   420,     7,    74,    75,   281,    78,    78,    80,
      80,    82,    82,   255,   210,   145,   587,    32,   542,     7,
       8,     9,   496,     5,   123,   445,     7,   303,   302,    90,
       7,    61,    92,   312,     7,    94,    97,   318,     7,    96,
      97,   324,     7,    97,   102,   330,     7,    97,   104,   336,
       7,    99,   110,   342,   343,     7,    99,   112,   357,   358,
       7,    99,   114,   372,   373,     7,    99,   116,   387,   388,
       7,    97,   108,   402,     7,    97,   106,   408,     7,   118,
     119,   414,     7,    74,    75,   421,   282,   256,     8,     9,
      36,    38,    40,   211,   212,   214,   216,   218,    26,   588,
       7,     8,     9,   543,     5,   131,   497,     7,    33,   446,
     127,   456,    88,    88,     8,     8,     8,     8,     8,   344,
     359,   374,   389,     8,     8,     8,   422,   283,    36,    38,
      40,   257,   258,   260,   262,   264,   265,   266,    76,     3,
       3,     3,     7,     8,     5,   139,   544,     7,    34,   498,
     135,   508,     7,     8,    33,   457,    75,   467,     4,     4,
       4,     4,     4,     8,     9,    19,    20,    21,   345,   346,
     348,   350,   352,     8,     9,    19,    20,    21,   360,   361,
     363,   365,   367,     8,     9,    19,    20,    21,   375,   376,
     378,   380,   382,     8,     9,    19,    20,    21,   390,   391,
     393,   395,   397,     4,     4,     4,   423,     8,     9,    36,
      38,    40,   284,   285,   287,   289,   291,     3,     3,     3,
       9,     8,   213,   215,   217,     5,   589,     7,    35,   545,
     143,   555,     7,     8,    34,   509,    75,   521,     5,   447,
       7,     8,   468,   122,   313,   319,   325,   331,   337,   100,
       3,     3,     3,   100,     3,     3,     3,   100,     3,     3,
       3,   100,     3,     3,     3,   403,   409,   415,     8,     9,
      36,    38,    40,   424,   425,   427,   429,   431,    76,     3,
       3,     3,   259,   261,   263,    76,     7,     7,     7,     7,
     146,   147,   590,     7,     8,    35,   556,    75,   568,     5,
     499,     7,     8,   522,   130,     7,   124,   125,   448,   449,
       5,   458,     8,    22,    23,    24,    33,    36,    38,    40,
     469,   470,   472,   474,   476,   478,   480,   482,   484,    62,
      98,    98,    98,    98,   347,   349,   351,   362,   364,   366,
     377,   379,   381,   392,   394,   396,    98,    98,   120,    76,
       3,     3,     3,   286,   288,   290,     7,     7,     7,   591,
       5,   546,     7,     8,   569,   138,     7,   132,   133,   500,
     501,     5,   510,     8,    22,    23,    24,    34,    36,    38,
      40,   523,   524,   525,   526,   527,   528,   529,   530,   531,
     450,     7,   125,   128,   459,   460,   125,   485,     3,     3,
       3,     7,     3,     3,     3,     7,     7,     7,     7,     7,
       7,     7,     7,     7,     7,     7,     7,   426,   428,   430,
       7,     7,     7,     8,     9,    22,    23,    24,    36,    38,
      40,   592,   593,   594,   595,   596,   597,   598,   599,     7,
     140,   141,   547,   548,     5,   557,     8,    22,    23,    24,
      35,    36,    38,    40,   570,   571,   572,   573,   574,   575,
     576,   577,   578,   502,     7,   133,   136,   511,   512,   133,
     532,     3,     3,     3,     7,     3,     3,     3,     8,     9,
      37,    38,   451,   452,   453,   455,   461,   486,    76,   477,
     479,   481,     5,   473,   475,   483,     7,     7,     7,   148,
       3,     3,     3,     3,     3,     3,   549,     7,   141,   144,
     558,   559,   141,   579,     3,     3,     3,     7,     3,     3,
       3,     8,     9,    37,    38,   503,   504,   505,   507,   513,
     533,    76,     7,     7,     7,     5,     7,     7,     7,   126,
       7,     3,     8,     9,    37,    38,   462,   463,   464,   466,
       8,     9,    37,    38,    41,    42,   487,   488,   489,   490,
     491,   492,     7,     7,     7,   471,     7,     7,     7,     7,
       7,     7,     7,     7,     7,     8,     9,    37,    38,   550,
     551,   552,   554,   560,   580,    76,     7,     7,     7,     5,
       7,     7,     7,   134,     7,     3,     8,     9,    37,    41,
      42,   514,   515,   516,   518,   520,     8,     9,    37,    38,
      41,    42,   534,   535,   536,   537,   538,   539,     7,     5,
     454,   126,     7,     3,   126,     5,     3,     3,     3,     7,
     142,     7,     3,     8,     9,    37,    41,    42,   561,   562,
     563,   565,   567,     8,     9,    37,    38,    41,    42,   581,
     582,   583,   584,   585,   586,     7,     5,   506,   134,     7,
       3,     3,   126,     3,     3,     3,     3,     7,     7,     5,
     465,     7,     7,     7,     7,     5,   553,   142,     7,     3,
       3,   142,     3,     3,     3,     3,     7,     7,     5,   517,
     519,     7,     7,     7,     7,     7,     7,     7,     7,     5,
     564,   566,     7,     7,     7,     7,     7,     7,     7,     7,
       7,     7
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
;}
    break;

  case 445:

    {	if (parserData->numberOfVar >= osoption->optimization->variables->initialVariableValues->numberOfVar)
		osolerror(NULL, osoption, parserData, "too many initial variable values");
;}
    break;

  case 450:

    {	if (parserData->idxAttributePresent)
		osolerror (NULL, osoption, parserData, "only one variable index allowed");
	parserData->idxAttributePresent = true;
	if ((yyvsp[(3) - (4)].ival) < 0) osolerror (NULL, osoption, parserData, "variable index must be nonnegative");
	if (parserData->numberOfVariablesPresent)
	{	if ((yyvsp[(3) - (4)].ival) >= parserData->numberOfVariables)
			osolerror (NULL, osoption, parserData, "variable index exceeds upper limit");
	};
	osoption->optimization->variables->initialVariableValues->var[parserData->numberOfVar]->idx = (yyvsp[(3) - (4)].ival);  
;}
    break;

  case 451:

    {	if (parserData->valAttributePresent)
		osolerror (NULL, osoption, parserData, "only one variable value allowed");
	parserData->valAttributePresent = true;
	osoption->optimization->variables->initialVariableValues->var[parserData->numberOfVar]->value = strtod((yyvsp[(2) - (2)].sval), NULL);  
;}
    break;

  case 457:

    {	if ((yyvsp[(3) - (4)].ival) <= 0) osolerror (NULL, osoption, parserData, "number of <var> elements must be positive");
	osoption->optimization->variables->initialVariableValuesString = new InitVariableValuesString ();
	osoption->optimization->variables->initialVariableValuesString->numberOfVar = (yyvsp[(3) - (4)].ival);
	osoption->optimization->variables->initialVariableValuesString->var = new InitVarValueString*[(yyvsp[(3) - (4)].ival)];
	for (int i = 0; i < (yyvsp[(3) - (4)].ival); i++)
		osoption->optimization->variables->initialVariableValuesString->var[i] = new InitVarValueString ();
;}
    break;

  case 460:

    {	if (!parserData->idxAttributePresent)
		osolerror (NULL, osoption, parserData, "variable index required");
	parserData->idxAttributePresent = false;
	parserData->valAttributePresent = false;
	parserData->numberOfVarStr++;
;}
    break;

  case 461:

    {	if (parserData->numberOfVarStr >= osoption->optimization->variables->initialVariableValuesString->numberOfVar)
		osolerror(NULL, osoption, parserData, "too many initial variable strings");
;}
    break;

  case 466:

    {	if (parserData->idxAttributePresent)
		osolerror (NULL, osoption, parserData, "only one variable index allowed");
	parserData->idxAttributePresent = true;
	if ((yyvsp[(3) - (4)].ival) < 0) osolerror (NULL, osoption, parserData, "variable index must be nonnegative");
	if (parserData->numberOfVariablesPresent)
	{	if ((yyvsp[(3) - (4)].ival) >= parserData->numberOfVariables)
			osolerror (NULL, osoption, parserData, "variable index exceeds upper limit");
	};
	osoption->optimization->variables->initialVariableValuesString->var[parserData->numberOfVarStr]->idx = (yyvsp[(3) - (4)].ival);  
;}
    break;

  case 467:

    {	if (parserData->valAttributePresent)
		osolerror (NULL, osoption, parserData, "only one variable index allowed");
	parserData->valAttributePresent = true;
	osoption->optimization->variables->initialVariableValuesString->var[parserData->numberOfVarStr]->value = strtod((yyvsp[(2) - (2)].sval), NULL);  
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

  case 494:

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

  case 506:

    {
;}
    break;

  case 507:

    {
;}
    break;

  case 512:

    {	osoption->optimization->objectives = new ObjectiveOption();
;}
    break;

  case 514:

    {	if ((yyvsp[(3) - (4)].ival) < 0) osolerror (NULL, osoption, parserData, "number of <other> objective options cannot be negative");
        osoption->optimization->objectives->numberOfOtherObjectiveOptions = (yyvsp[(3) - (4)].ival);
	osoption->optimization->objectives->other = new OtherObjectiveOption*[(yyvsp[(3) - (4)].ival)];
	for (int i= 0; i < (yyvsp[(3) - (4)].ival); i++)
		osoption->optimization->objectives->other[i] = new OtherObjectiveOption();
;}
    break;

  case 519:

    {	if ((yyvsp[(3) - (4)].ival) <= 0) osolerror (NULL, osoption, parserData, "number of <obj> elements must be positive");
	osoption->optimization->objectives->initialObjectiveValues = new InitObjectiveValues();
	osoption->optimization->objectives->initialObjectiveValues->numberOfObj = (yyvsp[(3) - (4)].ival);
	osoption->optimization->objectives->initialObjectiveValues->obj = new InitObjValue*[(yyvsp[(3) - (4)].ival)];
	for (int i = 0; i < (yyvsp[(3) - (4)].ival); i++)
		osoption->optimization->objectives->initialObjectiveValues->obj[i] = new InitObjValue();
;}
    break;

  case 522:

    {	if (!parserData->idxAttributePresent)
		osolerror (NULL, osoption, parserData, "variable index required");
	parserData->idxAttributePresent = false;
	parserData->valAttributePresent = false;
	parserData->numberOfObjValues++;
;}
    break;

  case 523:

    {	if (parserData->numberOfObjValues >= osoption->optimization->objectives->initialObjectiveValues->numberOfObj)
		osolerror(NULL, osoption, parserData, "too many initial objective values");
;}
    break;

  case 528:

    {	if (parserData->idxAttributePresent)
		osolerror (NULL, osoption, parserData, "only one objective index allowed");
	parserData->idxAttributePresent = true;
	if ((yyvsp[(3) - (4)].ival) >= 0) osolerror (NULL, osoption, parserData, "objective index must be negative");
	if (parserData->numberOfObjectivesPresent)
	{	if (-(yyvsp[(3) - (4)].ival) > parserData->numberOfObjectives)
			osolerror (NULL, osoption, parserData, "objective index out of range");
	};
	osoption->optimization->objectives->initialObjectiveValues->obj[parserData->numberOfObjValues]->idx = (yyvsp[(3) - (4)].ival);  
;}
    break;

  case 529:

    {	if (parserData->valAttributePresent)
		osolerror (NULL, osoption, parserData, "only one objective value allowed");
	parserData->valAttributePresent = true;
	osoption->optimization->objectives->initialObjectiveValues->obj[parserData->numberOfObjValues]->value = strtod((yyvsp[(2) - (2)].sval), NULL);  
;}
    break;

  case 535:

    {	if ((yyvsp[(3) - (4)].ival) <= 0) osolerror (NULL, osoption, parserData, "number of <obj> elements must be positive");
	osoption->optimization->objectives->initialObjectiveBounds = new InitObjectiveBounds();
	osoption->optimization->objectives->initialObjectiveBounds->numberOfObj = (yyvsp[(3) - (4)].ival);
	osoption->optimization->objectives->initialObjectiveBounds->obj = new InitObjBound*[(yyvsp[(3) - (4)].ival)];
	for (int i = 0; i < (yyvsp[(3) - (4)].ival); i++)
		osoption->optimization->objectives->initialObjectiveBounds->obj[i] = new InitObjBound ();
;}
    break;

  case 538:

    {	if (!parserData->idxAttributePresent)
		osolerror (NULL, osoption, parserData, "variable index required");
	parserData->idxAttributePresent = false;
	parserData->lbvalAttributePresent = false;
	parserData->ubvalAttributePresent = false;
	parserData->numberOfObjBounds++;
;}
    break;

  case 539:

    {	if (parserData->numberOfObjBounds >= osoption->optimization->objectives->initialObjectiveBounds->numberOfObj)
		osolerror(NULL, osoption, parserData, "too many initial objective bounds");
;}
    break;

  case 545:

    {	if (parserData->idxAttributePresent)
		osolerror (NULL, osoption, parserData, "only one objective index allowed");
	parserData->idxAttributePresent = true;
	if ((yyvsp[(3) - (4)].ival) >= 0) osolerror (NULL, osoption, parserData, "objective index must be negative");
	if (parserData->numberOfObjectivesPresent)
	{	if (-(yyvsp[(3) - (4)].ival) > parserData->numberOfObjectives)
			osolerror (NULL, osoption, parserData, "objective index out of range");
	};
	osoption->optimization->objectives->initialObjectiveBounds->obj[parserData->numberOfObjBounds]->idx = (yyvsp[(3) - (4)].ival);  
;}
    break;

  case 546:

    {	if (parserData->lbvalAttributePresent)
		osolerror (NULL, osoption, parserData, "only one objective lower bound allowed");
	parserData->lbvalAttributePresent = true;
	osoption->optimization->objectives->initialObjectiveBounds->obj[parserData->numberOfObjBounds]->lbValue = strtod((yyvsp[(2) - (2)].sval), NULL);  
;}
    break;

  case 548:

    {	if (parserData->ubvalAttributePresent)
		osolerror (NULL, osoption, parserData, "only one objective upper bound allowed");
	parserData->ubvalAttributePresent = true;
	osoption->optimization->objectives->initialObjectiveBounds->obj[parserData->numberOfObjBounds]->ubValue = strtod((yyvsp[(2) - (2)].sval), NULL);  
;}
    break;

  case 563:

    {
;}
    break;

  case 564:

    {
;}
    break;

  case 565:

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

  case 578:

    {	
;}
    break;

  case 579:

    {
;}
    break;

  case 580:

    {
;}
    break;

  case 581:

    {
;}
    break;

  case 586:

    {	osoption->optimization->constraints = new ConstraintOption();
;}
    break;

  case 588:

    {	if ((yyvsp[(3) - (4)].ival) < 0) osolerror (NULL, osoption, parserData, "number of <other> constraint options cannot be negative");
        osoption->optimization->constraints->numberOfOtherConstraintOptions = (yyvsp[(3) - (4)].ival);
	osoption->optimization->constraints->other = new OtherConstraintOption*[(yyvsp[(3) - (4)].ival)];
	for (int i= 0; i < (yyvsp[(3) - (4)].ival); i++)
		osoption->optimization->constraints->other[i] = new OtherConstraintOption();
;}
    break;

  case 593:

    {	if ((yyvsp[(3) - (4)].ival) <= 0) osolerror (NULL, osoption, parserData, "number of <con> elements must be positive");
	osoption->optimization->constraints->initialConstraintValues = new InitConstraintValues();
	osoption->optimization->constraints->initialConstraintValues->numberOfCon = (yyvsp[(3) - (4)].ival);
	osoption->optimization->constraints->initialConstraintValues->con = new InitConValue*[(yyvsp[(3) - (4)].ival)];
	for (int i = 0; i < (yyvsp[(3) - (4)].ival); i++)
		osoption->optimization->constraints->initialConstraintValues->con[i] = new InitConValue();
;}
    break;

  case 596:

    {	if (!parserData->idxAttributePresent)
		osolerror (NULL, osoption, parserData, "variable index required");
	parserData->idxAttributePresent = false;
	parserData->valAttributePresent = false;
	parserData->numberOfCon++;
;}
    break;

  case 597:

    {	if (parserData->numberOfCon >= osoption->optimization->constraints->initialConstraintValues->numberOfCon)
		osolerror(NULL, osoption, parserData, "too many initial constraint values");
;}
    break;

  case 602:

    {	if (parserData->idxAttributePresent)
		osolerror (NULL, osoption, parserData, "only one constraint index allowed");
	parserData->idxAttributePresent = true;
	if ((yyvsp[(3) - (4)].ival) < 0) osolerror (NULL, osoption, parserData, "constraint index must be nonnegative");
	if (parserData->numberOfConstraintsPresent)
	{	if ((yyvsp[(3) - (4)].ival) > parserData->numberOfConstraints)
			osolerror (NULL, osoption, parserData, "constraint index out of range");
	};
	osoption->optimization->constraints->initialConstraintValues->con[parserData->numberOfCon]->idx = (yyvsp[(3) - (4)].ival);  
;}
    break;

  case 603:

    {	if (parserData->valAttributePresent)
		osolerror (NULL, osoption, parserData, "only one constraint value allowed");
	parserData->valAttributePresent = true;
	osoption->optimization->constraints->initialConstraintValues->con[parserData->numberOfCon]->value = strtod((yyvsp[(2) - (2)].sval), NULL);  
;}
    break;

  case 609:

    {	if ((yyvsp[(3) - (4)].ival) <= 0) osolerror (NULL, osoption, parserData, "number of <con> elements must be positive");
	osoption->optimization->constraints->initialDualValues = new InitDualVariableValues();
	osoption->optimization->constraints->initialDualValues->numberOfCon = (yyvsp[(3) - (4)].ival);
	osoption->optimization->constraints->initialDualValues->con = new InitDualVarValue*[(yyvsp[(3) - (4)].ival)];
	for (int i = 0; i < (yyvsp[(3) - (4)].ival); i++)
		osoption->optimization->constraints->initialDualValues->con[i] = new InitDualVarValue ();
;}
    break;

  case 612:

    {	if (!parserData->idxAttributePresent)
		osolerror (NULL, osoption, parserData, "constraint index required");
	parserData->idxAttributePresent = false;
	parserData->lbvalAttributePresent = false;
	parserData->ubvalAttributePresent = false;
	parserData->numberOfDuals++;
;}
    break;

  case 613:

    {	if (parserData->numberOfDuals >= osoption->optimization->constraints->initialDualValues->numberOfCon)
		osolerror(NULL, osoption, parserData, "too many initial dual variable bounds");
;}
    break;

  case 619:

    {	if (parserData->idxAttributePresent)
		osolerror (NULL, osoption, parserData, "only one constraint index allowed");
	parserData->idxAttributePresent = true;
	if ((yyvsp[(3) - (4)].ival) < 0) osolerror (NULL, osoption, parserData, "constraint index must be nonnegative");
	if (parserData->numberOfConstraintsPresent)
	{	if ((yyvsp[(3) - (4)].ival) > parserData->numberOfConstraints)
			osolerror (NULL, osoption, parserData, "constraint index out of range");
	};
	osoption->optimization->constraints->initialDualValues->con[parserData->numberOfDuals]->idx = (yyvsp[(3) - (4)].ival);  
;}
    break;

  case 620:

    {	if (parserData->lbvalAttributePresent)
		osolerror (NULL, osoption, parserData, "only one dual variable lower bound allowed");
	parserData->lbvalAttributePresent = true;
	osoption->optimization->constraints->initialDualValues->con[parserData->numberOfDuals]->lbValue = strtod((yyvsp[(2) - (2)].sval), NULL);  
;}
    break;

  case 622:

    {	if (parserData->ubvalAttributePresent)
		osolerror (NULL, osoption, parserData, "only one dual variable upper bound allowed");
	parserData->ubvalAttributePresent = true;
	osoption->optimization->constraints->initialDualValues->con[parserData->numberOfDuals]->ubValue = strtod((yyvsp[(2) - (2)].sval), NULL);  
;}
    break;

  case 637:

    {
;}
    break;

  case 638:

    {
;}
    break;

  case 639:

    {
;}
    break;

  case 640:

    {
;}
    break;

  case 641:

    {
;}
    break;

  case 642:

    {
;}
    break;

  case 643:

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

  case 660:

    {
;}
    break;

  case 672:

    {
;}
    break;

  case 673:

    {
;}
    break;

  case 674:

    {
;}
    break;

  case 675:

    {
;}
    break;

  case 676:

    {
;}
    break;

  case 677:

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


