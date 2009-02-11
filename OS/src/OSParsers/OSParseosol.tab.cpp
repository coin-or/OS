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
     OSOLSTARTEMPTY = 266,
     OSOLATTRIBUTETEXT = 267,
     OSOLEND = 268,
     LOCATIONTYPEATT = 269,
     TRANSPORTTYPEATT = 270,
     NUMBEROFOTHEROPTIONSATT = 271,
     NUMBEROFJOBIDSATT = 272,
     NUMBEROFPATHSATT = 273,
     NUMBEROFPATHPAIRSATT = 274,
     FROMATT = 275,
     TOATT = 276,
     MAKECOPYATT = 277,
     SOLVERATT = 278,
     CATEGORYATT = 279,
     TYPEATT = 280,
     GROUPWEIGHTATT = 281,
     NUMBEROFPROCESSESATT = 282,
     NUMBEROFSOLVEROPTIONSATT = 283,
     NUMBEROFSOSATT = 284,
     NUMBEROFVARIABLESATT = 285,
     NUMBEROFOBJECTIVESATT = 286,
     NUMBEROFCONSTRAINTSATT = 287,
     NUMBEROFOTHERVARIABLEOPTIONSATT = 288,
     NUMBEROFOTHEROBJECTIVEOPTIONSATT = 289,
     NUMBEROFOTHERCONSTRAINTOPTIONSATT = 290,
     NUMBEROFVARATT = 291,
     NUMBEROFOBJATT = 292,
     NUMBEROFCONATT = 293,
     NAMEATT = 294,
     IDXATT = 295,
     SOSIDXATT = 296,
     VALUEATT = 297,
     UNITATT = 298,
     DESCRIPTIONATT = 299,
     LBVALUEATT = 300,
     UBVALUEATT = 301,
     LBDUALVALUEATT = 302,
     UBDUALVALUEATT = 303,
     GENERALSTART = 304,
     GENERALEND = 305,
     SYSTEMSTART = 306,
     SYSTEMEND = 307,
     SERVICESTART = 308,
     SERVICEEND = 309,
     JOBSTART = 310,
     JOBEND = 311,
     OPTIMIZATIONSTART = 312,
     OPTIMIZATIONEND = 313,
     SERVICEURISTART = 314,
     SERVICEURIEND = 315,
     SERVICENAMESTART = 316,
     SERVICENAMEEND = 317,
     INSTANCENAMESTART = 318,
     INSTANCENAMEEND = 319,
     INSTANCELOCATIONSTART = 320,
     INSTANCELOCATIONEND = 321,
     JOBIDSTART = 322,
     JOBIDEND = 323,
     SOLVERTOINVOKESTART = 324,
     SOLVERTOINVOKEEND = 325,
     LICENSESTART = 326,
     LICENSEEND = 327,
     USERNAMESTART = 328,
     USERNAMEEND = 329,
     PASSWORDSTART = 330,
     PASSWORDEND = 331,
     CONTACTSTART = 332,
     CONTACTEND = 333,
     OTHEROPTIONSSTART = 334,
     OTHEROPTIONSEND = 335,
     OTHERSTART = 336,
     OTHEREND = 337,
     MINDISKSPACESTART = 338,
     MINDISKSPACEEND = 339,
     MINMEMORYSIZESTART = 340,
     MINMEMORYSIZEEND = 341,
     MINCPUSPEEDSTART = 342,
     MINCPUSPEEDEND = 343,
     MINCPUNUMBERSTART = 344,
     MINCPUNUMBEREND = 345,
     SERVICETYPESTART = 346,
     SERVICETYPEEND = 347,
     MAXTIMESTART = 348,
     MAXTIMEEND = 349,
     SCHEDULEDSTARTTIMESTART = 350,
     SCHEDULEDSTARTTIMEEND = 351,
     DEPENDENCIESSTART = 352,
     DEPENDENCIESEND = 353,
     REQUIREDDIRECTORIESSTART = 354,
     REQUIREDDIRECTORIESEND = 355,
     REQUIREDFILESSTART = 356,
     REQUIREDFILESEND = 357,
     PATHSTART = 358,
     PATHEND = 359,
     PATHPAIRSTART = 360,
     PATHPAIREND = 361,
     DIRECTORIESTOMAKESTART = 362,
     DIRECTORIESTOMAKEEND = 363,
     FILESTOMAKESTART = 364,
     FILESTOMAKEEND = 365,
     DIRECTORIESTODELETESTART = 366,
     DIRECTORIESTODELETEEND = 367,
     FILESTODELETESTART = 368,
     FILESTODELETEEND = 369,
     INPUTDIRECTORIESTOMOVESTART = 370,
     INPUTDIRECTORIESTOMOVEEND = 371,
     INPUTFILESTOMOVESTART = 372,
     INPUTFILESTOMOVEEND = 373,
     OUTPUTDIRECTORIESTOMOVESTART = 374,
     OUTPUTDIRECTORIESTOMOVEEND = 375,
     OUTPUTFILESTOMOVESTART = 376,
     OUTPUTFILESTOMOVEEND = 377,
     PROCESSESTOKILLSTART = 378,
     PROCESSESTOKILLEND = 379,
     PROCESSSTART = 380,
     PROCESSEND = 381,
     VARIABLESSTART = 382,
     VARIABLESEND = 383,
     INITIALVARIABLEVALUESSTART = 384,
     INITIALVARIABLEVALUESEND = 385,
     VARSTART = 386,
     VAREND = 387,
     INITIALVARIABLEVALUESSTRINGSTART = 388,
     INITIALVARIABLEVALUESSTRINGEND = 389,
     INITIALBASISSTATUSSTART = 390,
     INITIALBASISSTATUSEND = 391,
     INTEGERVARIABLEBRANCHINGWEIGHTSSTART = 392,
     INTEGERVARIABLEBRANCHINGWEIGHTSEND = 393,
     SOSVARIABLEBRANCHINGWEIGHTSSTART = 394,
     SOSVARIABLEBRANCHINGWEIGHTSEND = 395,
     SOSSTART = 396,
     SOSEND = 397,
     OBJECTIVESSTART = 398,
     OBJECTIVESEND = 399,
     INITIALOBJECTIVEVALUESSTART = 400,
     INITIALOBJECTIVEVALUESEND = 401,
     OBJSTART = 402,
     OBJEND = 403,
     INITIALOBJECTIVEBOUNDSSTART = 404,
     INITIALOBJECTIVEBOUNDSEND = 405,
     CONSTRAINTSSTART = 406,
     CONSTRAINTSEND = 407,
     INITIALCONSTRAINTVALUESSTART = 408,
     INITIALCONSTRAINTVALUESEND = 409,
     CONSTART = 410,
     CONEND = 411,
     INITIALDUALVALUESSTART = 412,
     INITIALDUALVALUESEND = 413,
     SOLVEROPTIONSSTART = 414,
     SOLVEROPTIONSEND = 415,
     SOLVEROPTIONSTART = 416,
     SOLVEROPTIONEND = 417,
     DUMMY = 418
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
#define OSOLSTARTEMPTY 266
#define OSOLATTRIBUTETEXT 267
#define OSOLEND 268
#define LOCATIONTYPEATT 269
#define TRANSPORTTYPEATT 270
#define NUMBEROFOTHEROPTIONSATT 271
#define NUMBEROFJOBIDSATT 272
#define NUMBEROFPATHSATT 273
#define NUMBEROFPATHPAIRSATT 274
#define FROMATT 275
#define TOATT 276
#define MAKECOPYATT 277
#define SOLVERATT 278
#define CATEGORYATT 279
#define TYPEATT 280
#define GROUPWEIGHTATT 281
#define NUMBEROFPROCESSESATT 282
#define NUMBEROFSOLVEROPTIONSATT 283
#define NUMBEROFSOSATT 284
#define NUMBEROFVARIABLESATT 285
#define NUMBEROFOBJECTIVESATT 286
#define NUMBEROFCONSTRAINTSATT 287
#define NUMBEROFOTHERVARIABLEOPTIONSATT 288
#define NUMBEROFOTHEROBJECTIVEOPTIONSATT 289
#define NUMBEROFOTHERCONSTRAINTOPTIONSATT 290
#define NUMBEROFVARATT 291
#define NUMBEROFOBJATT 292
#define NUMBEROFCONATT 293
#define NAMEATT 294
#define IDXATT 295
#define SOSIDXATT 296
#define VALUEATT 297
#define UNITATT 298
#define DESCRIPTIONATT 299
#define LBVALUEATT 300
#define UBVALUEATT 301
#define LBDUALVALUEATT 302
#define UBDUALVALUEATT 303
#define GENERALSTART 304
#define GENERALEND 305
#define SYSTEMSTART 306
#define SYSTEMEND 307
#define SERVICESTART 308
#define SERVICEEND 309
#define JOBSTART 310
#define JOBEND 311
#define OPTIMIZATIONSTART 312
#define OPTIMIZATIONEND 313
#define SERVICEURISTART 314
#define SERVICEURIEND 315
#define SERVICENAMESTART 316
#define SERVICENAMEEND 317
#define INSTANCENAMESTART 318
#define INSTANCENAMEEND 319
#define INSTANCELOCATIONSTART 320
#define INSTANCELOCATIONEND 321
#define JOBIDSTART 322
#define JOBIDEND 323
#define SOLVERTOINVOKESTART 324
#define SOLVERTOINVOKEEND 325
#define LICENSESTART 326
#define LICENSEEND 327
#define USERNAMESTART 328
#define USERNAMEEND 329
#define PASSWORDSTART 330
#define PASSWORDEND 331
#define CONTACTSTART 332
#define CONTACTEND 333
#define OTHEROPTIONSSTART 334
#define OTHEROPTIONSEND 335
#define OTHERSTART 336
#define OTHEREND 337
#define MINDISKSPACESTART 338
#define MINDISKSPACEEND 339
#define MINMEMORYSIZESTART 340
#define MINMEMORYSIZEEND 341
#define MINCPUSPEEDSTART 342
#define MINCPUSPEEDEND 343
#define MINCPUNUMBERSTART 344
#define MINCPUNUMBEREND 345
#define SERVICETYPESTART 346
#define SERVICETYPEEND 347
#define MAXTIMESTART 348
#define MAXTIMEEND 349
#define SCHEDULEDSTARTTIMESTART 350
#define SCHEDULEDSTARTTIMEEND 351
#define DEPENDENCIESSTART 352
#define DEPENDENCIESEND 353
#define REQUIREDDIRECTORIESSTART 354
#define REQUIREDDIRECTORIESEND 355
#define REQUIREDFILESSTART 356
#define REQUIREDFILESEND 357
#define PATHSTART 358
#define PATHEND 359
#define PATHPAIRSTART 360
#define PATHPAIREND 361
#define DIRECTORIESTOMAKESTART 362
#define DIRECTORIESTOMAKEEND 363
#define FILESTOMAKESTART 364
#define FILESTOMAKEEND 365
#define DIRECTORIESTODELETESTART 366
#define DIRECTORIESTODELETEEND 367
#define FILESTODELETESTART 368
#define FILESTODELETEEND 369
#define INPUTDIRECTORIESTOMOVESTART 370
#define INPUTDIRECTORIESTOMOVEEND 371
#define INPUTFILESTOMOVESTART 372
#define INPUTFILESTOMOVEEND 373
#define OUTPUTDIRECTORIESTOMOVESTART 374
#define OUTPUTDIRECTORIESTOMOVEEND 375
#define OUTPUTFILESTOMOVESTART 376
#define OUTPUTFILESTOMOVEEND 377
#define PROCESSESTOKILLSTART 378
#define PROCESSESTOKILLEND 379
#define PROCESSSTART 380
#define PROCESSEND 381
#define VARIABLESSTART 382
#define VARIABLESEND 383
#define INITIALVARIABLEVALUESSTART 384
#define INITIALVARIABLEVALUESEND 385
#define VARSTART 386
#define VAREND 387
#define INITIALVARIABLEVALUESSTRINGSTART 388
#define INITIALVARIABLEVALUESSTRINGEND 389
#define INITIALBASISSTATUSSTART 390
#define INITIALBASISSTATUSEND 391
#define INTEGERVARIABLEBRANCHINGWEIGHTSSTART 392
#define INTEGERVARIABLEBRANCHINGWEIGHTSEND 393
#define SOSVARIABLEBRANCHINGWEIGHTSSTART 394
#define SOSVARIABLEBRANCHINGWEIGHTSEND 395
#define SOSSTART 396
#define SOSEND 397
#define OBJECTIVESSTART 398
#define OBJECTIVESEND 399
#define INITIALOBJECTIVEVALUESSTART 400
#define INITIALOBJECTIVEVALUESEND 401
#define OBJSTART 402
#define OBJEND 403
#define INITIALOBJECTIVEBOUNDSSTART 404
#define INITIALOBJECTIVEBOUNDSEND 405
#define CONSTRAINTSSTART 406
#define CONSTRAINTSEND 407
#define INITIALCONSTRAINTVALUESSTART 408
#define INITIALCONSTRAINTVALUESEND 409
#define CONSTART 410
#define CONEND 411
#define INITIALDUALVALUESSTART 412
#define INITIALDUALVALUESEND 413
#define SOLVEROPTIONSSTART 414
#define SOLVEROPTIONSEND 415
#define SOLVEROPTIONSTART 416
#define SOLVEROPTIONEND 417
#define DUMMY 418




/* Copy the first part of user declarations.  */




#include "OSDataStructures.h"
#include "OSMathUtil.h"
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
#define YYFINAL  10
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   801

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  164
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  522
/* YYNRULES -- Number of rules.  */
#define YYNRULES  777
/* YYNRULES -- Number of states.  */
#define YYNSTATES  1302

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   418

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
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     8,    11,    15,    17,    20,    21,    27,
      28,    31,    33,    37,    39,    40,    43,    45,    47,    49,
      51,    53,    55,    57,    59,    61,    63,    65,    68,    70,
      72,    75,    76,    81,    84,    86,    88,    91,    92,    97,
     100,   102,   104,   107,   108,   113,   117,   119,   120,   121,
     126,   128,   132,   133,   135,   138,   140,   142,   145,   146,
     151,   154,   156,   158,   161,   162,   167,   170,   172,   174,
     177,   178,   183,   186,   188,   190,   193,   194,   199,   202,
     204,   206,   209,   210,   215,   219,   221,   222,   223,   228,
     230,   234,   235,   237,   242,   244,   249,   252,   253,   256,
     257,   262,   263,   266,   268,   270,   272,   273,   278,   279,
     284,   285,   290,   292,   295,   296,   299,   301,   305,   307,
     308,   311,   313,   315,   317,   319,   321,   325,   327,   328,
     329,   334,   336,   339,   343,   347,   351,   353,   354,   355,
     360,   362,   365,   369,   373,   377,   379,   380,   381,   386,
     388,   391,   395,   399,   402,   404,   406,   409,   410,   415,
     420,   422,   427,   430,   431,   434,   435,   440,   441,   444,
     446,   448,   450,   451,   456,   457,   462,   463,   468,   470,
     473,   474,   477,   479,   483,   485,   486,   489,   491,   493,
     496,   498,   500,   503,   504,   509,   514,   516,   521,   524,
     525,   528,   529,   534,   535,   538,   540,   542,   544,   545,
     550,   551,   556,   557,   562,   564,   567,   568,   571,   573,
     577,   579,   580,   583,   585,   587,   589,   591,   593,   595,
     597,   599,   601,   603,   605,   607,   609,   611,   613,   617,
     619,   620,   621,   626,   628,   631,   635,   639,   642,   644,
     646,   649,   650,   655,   661,   663,   668,   669,   672,   673,
     679,   685,   687,   692,   693,   696,   697,   703,   709,   711,
     716,   717,   720,   721,   727,   733,   735,   740,   741,   744,
     745,   751,   757,   759,   764,   765,   768,   769,   775,   781,
     783,   788,   789,   792,   796,   798,   799,   802,   804,   806,
     808,   809,   814,   815,   820,   821,   826,   829,   831,   837,
     839,   844,   845,   848,   852,   854,   855,   858,   860,   862,
     864,   865,   870,   871,   876,   877,   882,   885,   887,   893,
     895,   900,   901,   904,   908,   910,   911,   914,   916,   918,
     920,   921,   926,   927,   932,   933,   938,   941,   943,   949,
     951,   956,   957,   960,   964,   966,   967,   970,   972,   974,
     976,   977,   982,   983,   988,   989,   994,   997,   999,  1005,
    1007,  1012,  1013,  1016,  1017,  1023,  1029,  1031,  1036,  1037,
    1040,  1041,  1047,  1053,  1055,  1060,  1061,  1064,  1065,  1071,
    1076,  1078,  1083,  1086,  1087,  1090,  1091,  1096,  1097,  1100,
    1102,  1104,  1106,  1107,  1112,  1113,  1118,  1119,  1124,  1126,
    1129,  1130,  1134,  1136,  1137,  1140,  1142,  1144,  1146,  1151,
    1156,  1161,  1165,  1167,  1172,  1173,  1177,  1179,  1180,  1185,
    1194,  1196,  1197,  1203,  1208,  1209,  1212,  1216,  1218,  1219,
    1222,  1224,  1226,  1231,  1232,  1237,  1240,  1242,  1243,  1249,
    1254,  1255,  1258,  1262,  1264,  1265,  1268,  1270,  1272,  1277,
    1278,  1283,  1286,  1288,  1289,  1295,  1300,  1301,  1304,  1308,
    1310,  1311,  1314,  1316,  1318,  1323,  1324,  1329,  1332,  1334,
    1335,  1341,  1346,  1347,  1350,  1354,  1356,  1357,  1360,  1362,
    1364,  1369,  1370,  1375,  1378,  1380,  1381,  1387,  1392,  1393,
    1396,  1400,  1402,  1403,  1406,  1408,  1410,  1412,  1417,  1422,
    1427,  1432,  1436,  1438,  1439,  1442,  1446,  1448,  1449,  1452,
    1454,  1456,  1461,  1462,  1467,  1470,  1472,  1473,  1476,  1480,
    1482,  1483,  1486,  1488,  1490,  1492,  1494,  1496,  1498,  1500,
    1505,  1506,  1511,  1512,  1517,  1518,  1523,  1524,  1529,  1530,
    1535,  1536,  1541,  1545,  1546,  1549,  1553,  1555,  1556,  1559,
    1561,  1563,  1565,  1567,  1572,  1573,  1578,  1579,  1584,  1585,
    1590,  1593,  1595,  1596,  1600,  1602,  1603,  1608,  1614,  1616,
    1617,  1623,  1628,  1629,  1632,  1636,  1638,  1639,  1642,  1644,
    1646,  1651,  1652,  1657,  1660,  1662,  1663,  1669,  1674,  1675,
    1678,  1682,  1684,  1685,  1688,  1690,  1692,  1694,  1699,  1700,
    1705,  1706,  1711,  1714,  1716,  1717,  1720,  1724,  1726,  1727,
    1730,  1732,  1734,  1736,  1738,  1740,  1742,  1744,  1749,  1750,
    1755,  1756,  1761,  1762,  1767,  1768,  1773,  1774,  1779,  1780,
    1785,  1789,  1790,  1793,  1797,  1799,  1800,  1803,  1805,  1807,
    1809,  1811,  1816,  1817,  1822,  1823,  1828,  1829,  1834,  1837,
    1839,  1840,  1844,  1846,  1847,  1852,  1858,  1860,  1861,  1867,
    1872,  1873,  1876,  1880,  1882,  1883,  1886,  1888,  1890,  1895,
    1896,  1901,  1904,  1906,  1907,  1913,  1918,  1919,  1922,  1926,
    1928,  1929,  1932,  1934,  1936,  1938,  1943,  1944,  1949,  1950,
    1955,  1958,  1960,  1961,  1964,  1968,  1970,  1971,  1974,  1976,
    1978,  1980,  1982,  1984,  1986,  1988,  1993,  1994,  1999,  2000,
    2005,  2006,  2011,  2012,  2017,  2018,  2023,  2024,  2029,  2033,
    2034,  2037,  2041,  2043,  2044,  2047,  2049,  2051,  2053,  2055,
    2060,  2061,  2066,  2067,  2072,  2073,  2078,  2081,  2083,  2084,
    2090,  2092,  2097,  2098,  2101,  2102,  2107,  2108,  2111,  2113,
    2115,  2117,  2119,  2121,  2123,  2124,  2129,  2130,  2135,  2136,
    2141,  2142,  2147,  2148,  2153,  2154,  2159,  2162
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     165,     0,    -1,   166,     8,   167,    13,    -1,   166,     9,
      -1,    11,   167,    13,    -1,    10,    -1,    10,    12,    -1,
      -1,   168,   233,   273,   298,   436,    -1,    -1,   169,   170,
      -1,    49,    -1,     8,   171,    50,    -1,     9,    -1,    -1,
     171,   172,    -1,   173,    -1,   177,    -1,   181,    -1,   185,
      -1,   191,    -1,   195,    -1,   199,    -1,   203,    -1,   207,
      -1,   211,    -1,   217,    -1,   174,   175,    -1,    59,    -1,
       9,    -1,     8,    60,    -1,    -1,     8,     4,   176,    60,
      -1,   178,   179,    -1,    61,    -1,     9,    -1,     8,    62,
      -1,    -1,     8,     4,   180,    62,    -1,   182,   183,    -1,
      63,    -1,     9,    -1,     8,    64,    -1,    -1,     8,     4,
     184,    64,    -1,   186,   187,   189,    -1,    65,    -1,    -1,
      -1,    14,     3,   188,     7,    -1,     9,    -1,     8,   190,
      66,    -1,    -1,     4,    -1,   192,   193,    -1,    67,    -1,
       9,    -1,     8,    68,    -1,    -1,     8,     4,   194,    68,
      -1,   196,   197,    -1,    69,    -1,     9,    -1,     8,    70,
      -1,    -1,     8,     4,   198,    70,    -1,   200,   201,    -1,
      71,    -1,     9,    -1,     8,    72,    -1,    -1,     8,     4,
     202,    72,    -1,   204,   205,    -1,    73,    -1,     9,    -1,
       8,    74,    -1,    -1,     8,     4,   206,    74,    -1,   208,
     209,    -1,    75,    -1,     9,    -1,     8,    76,    -1,    -1,
       8,     4,   210,    76,    -1,   212,   213,   215,    -1,    77,
      -1,    -1,    -1,    15,     3,   214,     7,    -1,     9,    -1,
       8,   216,    78,    -1,    -1,     4,    -1,   218,   219,     8,
     220,    -1,    79,    -1,    16,     7,     5,     7,    -1,   221,
      80,    -1,    -1,   221,   222,    -1,    -1,    81,   223,   224,
     232,    -1,    -1,   224,   225,    -1,   226,    -1,   228,    -1,
     230,    -1,    -1,    39,     3,   227,     7,    -1,    -1,    42,
       3,   229,     7,    -1,    -1,    44,     3,   231,     7,    -1,
       9,    -1,     8,    82,    -1,    -1,   234,   235,    -1,    51,
      -1,     8,   236,    52,    -1,     9,    -1,    -1,   236,   237,
      -1,   238,    -1,   243,    -1,   248,    -1,   253,    -1,   257,
      -1,   239,   240,   242,    -1,    83,    -1,    -1,    -1,    43,
       3,   241,     7,    -1,     9,    -1,     8,    84,    -1,     8,
       6,    84,    -1,     8,     5,    84,    -1,   244,   245,   247,
      -1,    85,    -1,    -1,    -1,    43,     3,   246,     7,    -1,
       9,    -1,     8,    86,    -1,     8,     6,    86,    -1,     8,
       5,    86,    -1,   249,   250,   252,    -1,    87,    -1,    -1,
      -1,    43,     3,   251,     7,    -1,     9,    -1,     8,    88,
      -1,     8,     6,    88,    -1,     8,     5,    88,    -1,   254,
     255,    -1,    89,    -1,     9,    -1,     8,    90,    -1,    -1,
       8,     5,   256,    90,    -1,   258,   259,     8,   260,    -1,
      79,    -1,    16,     7,     5,     7,    -1,   261,    80,    -1,
      -1,   261,   262,    -1,    -1,    81,   263,   264,   272,    -1,
      -1,   264,   265,    -1,   266,    -1,   268,    -1,   270,    -1,
      -1,    39,     3,   267,     7,    -1,    -1,    42,     3,   269,
       7,    -1,    -1,    44,     3,   271,     7,    -1,     9,    -1,
       8,    82,    -1,    -1,   274,   275,    -1,    53,    -1,     8,
     276,    54,    -1,     9,    -1,    -1,   276,   277,    -1,   278,
      -1,   282,    -1,   279,   280,    -1,    91,    -1,     9,    -1,
       8,    92,    -1,    -1,     8,     4,   281,    92,    -1,   283,
     284,     8,   285,    -1,    79,    -1,    16,     7,     5,     7,
      -1,   286,    80,    -1,    -1,   286,   287,    -1,    -1,    81,
     288,   289,   297,    -1,    -1,   289,   290,    -1,   291,    -1,
     293,    -1,   295,    -1,    -1,    39,     3,   292,     7,    -1,
      -1,    42,     3,   294,     7,    -1,    -1,    44,     3,   296,
       7,    -1,     9,    -1,     8,    82,    -1,    -1,   299,   300,
      -1,    55,    -1,     8,   301,    56,    -1,     9,    -1,    -1,
     301,   302,    -1,   303,    -1,   308,    -1,   312,    -1,   318,
      -1,   324,    -1,   330,    -1,   336,    -1,   342,    -1,   357,
      -1,   372,    -1,   387,    -1,   402,    -1,   408,    -1,   414,
      -1,   420,    -1,   304,   305,   307,    -1,    93,    -1,    -1,
      -1,    43,     3,   306,     7,    -1,     9,    -1,     8,    94,
      -1,     8,     6,    94,    -1,     8,     5,    94,    -1,   309,
     310,    -1,    95,    -1,     9,    -1,     8,    96,    -1,    -1,
       8,     4,   311,    96,    -1,   313,   314,     8,   315,    98,
      -1,    97,    -1,    17,     7,     5,     7,    -1,    -1,   315,
     316,    -1,    -1,    67,     8,     4,   317,    68,    -1,   319,
     320,     8,   321,   100,    -1,    99,    -1,    18,     7,     5,
       7,    -1,    -1,   321,   322,    -1,    -1,   103,     8,     4,
     323,   104,    -1,   325,   326,     8,   327,   102,    -1,   101,
      -1,    18,     7,     5,     7,    -1,    -1,   327,   328,    -1,
      -1,   103,     8,     4,   329,   104,    -1,   331,   332,     8,
     333,   108,    -1,   107,    -1,    18,     7,     5,     7,    -1,
      -1,   333,   334,    -1,    -1,   103,     8,     4,   335,   104,
      -1,   337,   338,     8,   339,   110,    -1,   109,    -1,    18,
       7,     5,     7,    -1,    -1,   339,   340,    -1,    -1,   103,
       8,     4,   341,   104,    -1,   343,   344,     8,   345,   116,
      -1,   115,    -1,    19,     7,     5,     7,    -1,    -1,   345,
     346,    -1,   347,   348,   356,    -1,   105,    -1,    -1,   348,
     349,    -1,   350,    -1,   352,    -1,   354,    -1,    -1,    20,
       3,   351,     7,    -1,    -1,    21,     3,   353,     7,    -1,
      -1,    22,     3,   355,     7,    -1,     8,   106,    -1,     9,
      -1,   358,   359,     8,   360,   118,    -1,   117,    -1,    19,
       7,     5,     7,    -1,    -1,   360,   361,    -1,   362,   363,
     371,    -1,   105,    -1,    -1,   363,   364,    -1,   365,    -1,
     367,    -1,   369,    -1,    -1,    20,     3,   366,     7,    -1,
      -1,    21,     3,   368,     7,    -1,    -1,    22,     3,   370,
       7,    -1,     8,   106,    -1,     9,    -1,   373,   374,     8,
     375,   120,    -1,   119,    -1,    19,     7,     5,     7,    -1,
      -1,   375,   376,    -1,   377,   378,   386,    -1,   105,    -1,
      -1,   378,   379,    -1,   380,    -1,   382,    -1,   384,    -1,
      -1,    20,     3,   381,     7,    -1,    -1,    21,     3,   383,
       7,    -1,    -1,    22,     3,   385,     7,    -1,     8,   106,
      -1,     9,    -1,   388,   389,     8,   390,   122,    -1,   121,
      -1,    19,     7,     5,     7,    -1,    -1,   390,   391,    -1,
     392,   393,   401,    -1,   105,    -1,    -1,   393,   394,    -1,
     395,    -1,   397,    -1,   399,    -1,    -1,    20,     3,   396,
       7,    -1,    -1,    21,     3,   398,     7,    -1,    -1,    22,
       3,   400,     7,    -1,     8,   106,    -1,     9,    -1,   403,
     404,     8,   405,   114,    -1,   113,    -1,    18,     7,     5,
       7,    -1,    -1,   405,   406,    -1,    -1,   103,     8,     4,
     407,   104,    -1,   409,   410,     8,   411,   112,    -1,   111,
      -1,    18,     7,     5,     7,    -1,    -1,   411,   412,    -1,
      -1,   103,     8,     4,   413,   104,    -1,   415,   416,     8,
     417,   124,    -1,   123,    -1,    27,     7,     5,     7,    -1,
      -1,   417,   418,    -1,    -1,   125,     8,     4,   419,   126,
      -1,   421,   422,     8,   423,    -1,    79,    -1,    16,     7,
       5,     7,    -1,   424,    80,    -1,    -1,   424,   425,    -1,
      -1,    81,   426,   427,   435,    -1,    -1,   427,   428,    -1,
     429,    -1,   431,    -1,   433,    -1,    -1,    39,     3,   430,
       7,    -1,    -1,    42,     3,   432,     7,    -1,    -1,    44,
       3,   434,     7,    -1,     9,    -1,     8,    82,    -1,    -1,
     437,   438,   443,    -1,    57,    -1,    -1,   438,   439,    -1,
     440,    -1,   441,    -1,   442,    -1,    30,     7,     5,     7,
      -1,    32,     7,     5,     7,    -1,    31,     7,     5,     7,
      -1,     8,   444,    58,    -1,     9,    -1,   445,   545,   605,
     665,    -1,    -1,   446,   447,   448,    -1,   127,    -1,    -1,
      33,     7,     5,     7,    -1,     8,   449,   460,   471,   482,
     493,   513,   128,    -1,     9,    -1,    -1,   129,   450,     8,
     451,   130,    -1,    36,     7,     5,     7,    -1,    -1,   451,
     452,    -1,   453,   454,   459,    -1,   131,    -1,    -1,   454,
     455,    -1,   456,    -1,   457,    -1,    40,     7,     5,     7,
      -1,    -1,    42,     3,   458,     7,    -1,     8,   132,    -1,
       9,    -1,    -1,   133,   461,     8,   462,   134,    -1,    36,
       7,     5,     7,    -1,    -1,   462,   463,    -1,   464,   465,
     470,    -1,   131,    -1,    -1,   465,   466,    -1,   467,    -1,
     468,    -1,    40,     7,     5,     7,    -1,    -1,    42,     3,
     469,     7,    -1,     8,   132,    -1,     9,    -1,    -1,   135,
     472,     8,   473,   136,    -1,    36,     7,     5,     7,    -1,
      -1,   473,   474,    -1,   475,   476,   481,    -1,   131,    -1,
      -1,   476,   477,    -1,   478,    -1,   479,    -1,    40,     7,
       5,     7,    -1,    -1,    42,     3,   480,     7,    -1,     8,
     132,    -1,     9,    -1,    -1,   137,   483,     8,   484,   138,
      -1,    36,     7,     5,     7,    -1,    -1,   484,   485,    -1,
     486,   487,   492,    -1,   131,    -1,    -1,   487,   488,    -1,
     489,    -1,   490,    -1,    40,     7,     5,     7,    -1,    -1,
      42,     3,   491,     7,    -1,     8,   132,    -1,     9,    -1,
      -1,   139,   494,     8,   495,   140,    -1,    29,     7,     5,
       7,    -1,    -1,   495,   496,    -1,   497,   498,   503,    -1,
     141,    -1,    -1,   498,   499,    -1,   500,    -1,   502,    -1,
     501,    -1,    41,     7,     5,     7,    -1,    26,     7,     6,
       7,    -1,    26,     7,     5,     7,    -1,    36,     7,     5,
       7,    -1,     8,   504,   142,    -1,     9,    -1,    -1,   504,
     505,    -1,   506,   507,   512,    -1,   131,    -1,    -1,   507,
     508,    -1,   509,    -1,   510,    -1,    40,     7,     5,     7,
      -1,    -1,    42,     3,   511,     7,    -1,     8,   132,    -1,
       9,    -1,    -1,   513,   514,    -1,   515,   516,   531,    -1,
      81,    -1,    -1,   516,   517,    -1,   518,    -1,   519,    -1,
     521,    -1,   523,    -1,   525,    -1,   527,    -1,   529,    -1,
      36,     7,     5,     7,    -1,    -1,    39,     3,   520,     7,
      -1,    -1,    42,     3,   522,     7,    -1,    -1,    23,     3,
     524,     7,    -1,    -1,    24,     3,   526,     7,    -1,    -1,
      25,     3,   528,     7,    -1,    -1,    44,     3,   530,     7,
      -1,     8,   532,    82,    -1,    -1,   532,   533,    -1,   534,
     535,   544,    -1,   131,    -1,    -1,   535,   536,    -1,   537,
      -1,   538,    -1,   540,    -1,   542,    -1,    40,     7,     5,
       7,    -1,    -1,    42,     3,   539,     7,    -1,    -1,    45,
       3,   541,     7,    -1,    -1,    46,     3,   543,     7,    -1,
       8,   132,    -1,     9,    -1,    -1,   546,   547,   548,    -1,
     143,    -1,    -1,    34,     7,     5,     7,    -1,     8,   549,
     560,   573,   144,    -1,     9,    -1,    -1,   145,   550,     8,
     551,   146,    -1,    37,     7,     5,     7,    -1,    -1,   551,
     552,    -1,   553,   554,   559,    -1,   147,    -1,    -1,   554,
     555,    -1,   556,    -1,   557,    -1,    40,     7,     5,     7,
      -1,    -1,    42,     3,   558,     7,    -1,     8,   148,    -1,
       9,    -1,    -1,   149,   561,     8,   562,   150,    -1,    37,
       7,     5,     7,    -1,    -1,   562,   563,    -1,   564,   565,
     572,    -1,   147,    -1,    -1,   565,   566,    -1,   567,    -1,
     568,    -1,   570,    -1,    40,     7,     5,     7,    -1,    -1,
      45,     3,   569,     7,    -1,    -1,    46,     3,   571,     7,
      -1,     8,   148,    -1,     9,    -1,    -1,   573,   574,    -1,
     575,   576,   591,    -1,    81,    -1,    -1,   576,   577,    -1,
     578,    -1,   579,    -1,   581,    -1,   583,    -1,   585,    -1,
     587,    -1,   589,    -1,    37,     7,     5,     7,    -1,    -1,
      39,     3,   580,     7,    -1,    -1,    42,     3,   582,     7,
      -1,    -1,    23,     3,   584,     7,    -1,    -1,    24,     3,
     586,     7,    -1,    -1,    25,     3,   588,     7,    -1,    -1,
      44,     3,   590,     7,    -1,     8,   592,    82,    -1,    -1,
     592,   593,    -1,   594,   595,   604,    -1,   147,    -1,    -1,
     595,   596,    -1,   597,    -1,   598,    -1,   600,    -1,   602,
      -1,    40,     7,     5,     7,    -1,    -1,    42,     3,   599,
       7,    -1,    -1,    45,     3,   601,     7,    -1,    -1,    46,
       3,   603,     7,    -1,     8,   132,    -1,     9,    -1,    -1,
     606,   607,   608,    -1,   151,    -1,    -1,    35,     7,     5,
       7,    -1,     8,   609,   620,   633,   152,    -1,     9,    -1,
      -1,   153,   610,     8,   611,   154,    -1,    38,     7,     5,
       7,    -1,    -1,   611,   612,    -1,   613,   614,   619,    -1,
     155,    -1,    -1,   614,   615,    -1,   616,    -1,   617,    -1,
      40,     7,     5,     7,    -1,    -1,    42,     3,   618,     7,
      -1,     8,   156,    -1,     9,    -1,    -1,   157,   621,     8,
     622,   158,    -1,    38,     7,     5,     7,    -1,    -1,   622,
     623,    -1,   624,   625,   632,    -1,   155,    -1,    -1,   625,
     626,    -1,   627,    -1,   628,    -1,   630,    -1,    40,     7,
       5,     7,    -1,    -1,    47,     3,   629,     7,    -1,    -1,
      48,     3,   631,     7,    -1,     8,   156,    -1,     9,    -1,
      -1,   633,   634,    -1,   635,   636,   651,    -1,    81,    -1,
      -1,   636,   637,    -1,   638,    -1,   639,    -1,   641,    -1,
     643,    -1,   645,    -1,   647,    -1,   649,    -1,    38,     7,
       5,     7,    -1,    -1,    39,     3,   640,     7,    -1,    -1,
      42,     3,   642,     7,    -1,    -1,    23,     3,   644,     7,
      -1,    -1,    24,     3,   646,     7,    -1,    -1,    25,     3,
     648,     7,    -1,    -1,    44,     3,   650,     7,    -1,     8,
     652,    82,    -1,    -1,   652,   653,    -1,   654,   655,   664,
      -1,   155,    -1,    -1,   655,   656,    -1,   657,    -1,   658,
      -1,   660,    -1,   662,    -1,    40,     7,     5,     7,    -1,
      -1,    42,     3,   659,     7,    -1,    -1,    45,     3,   661,
       7,    -1,    -1,    46,     3,   663,     7,    -1,     8,   156,
      -1,     9,    -1,    -1,   666,   667,     8,   668,   160,    -1,
     159,    -1,    28,     7,     5,     7,    -1,    -1,   668,   669,
      -1,    -1,   161,   670,   671,   685,    -1,    -1,   671,   672,
      -1,   673,    -1,   675,    -1,   677,    -1,   679,    -1,   681,
      -1,   683,    -1,    -1,    39,     3,   674,     7,    -1,    -1,
      42,     3,   676,     7,    -1,    -1,    23,     3,   678,     7,
      -1,    -1,    24,     3,   680,     7,    -1,    -1,    25,     3,
     682,     7,    -1,    -1,    44,     3,   684,     7,    -1,     8,
     162,    -1,     9,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   133,   133,   134,   135,   137,   138,   140,   141,   143,
     143,   145,   156,   157,   159,   159,   161,   161,   161,   161,
     161,   162,   162,   162,   162,   162,   162,   165,   167,   176,
     177,   178,   178,   181,   183,   192,   193,   194,   194,   197,
     199,   208,   209,   210,   210,   213,   215,   226,   227,   226,
     234,   235,   237,   237,   240,   242,   251,   252,   253,   253,
     256,   258,   267,   268,   269,   269,   272,   274,   283,   284,
     285,   285,   288,   290,   299,   300,   301,   301,   304,   306,
     315,   316,   317,   317,   320,   322,   333,   334,   333,   342,
     343,   345,   345,   348,   350,   360,   368,   373,   373,   376,
     375,   391,   391,   393,   393,   393,   396,   395,   407,   406,
     418,   417,   428,   428,   431,   431,   433,   444,   445,   447,
     447,   449,   449,   449,   449,   449,   451,   453,   464,   465,
     464,   473,   474,   475,   480,   487,   489,   500,   501,   500,
     509,   510,   511,   516,   524,   526,   537,   538,   537,   548,
     549,   550,   555,   563,   565,   574,   575,   577,   576,   584,
     586,   596,   604,   609,   609,   612,   611,   626,   626,   628,
     628,   628,   631,   630,   642,   641,   654,   653,   664,   664,
     667,   667,   669,   680,   681,   683,   683,   685,   685,   687,
     689,   699,   700,   702,   701,   711,   713,   723,   731,   736,
     736,   739,   738,   753,   753,   755,   755,   755,   758,   757,
     769,   768,   780,   779,   790,   790,   793,   793,   795,   805,
     806,   808,   808,   810,   810,   810,   810,   810,   811,   811,
     811,   811,   811,   812,   812,   812,   812,   812,   815,   817,
     828,   829,   828,   838,   839,   840,   845,   852,   854,   864,
     865,   866,   866,   868,   870,   880,   887,   887,   890,   889,
     902,   905,   915,   922,   922,   924,   924,   936,   939,   949,
     956,   956,   958,   958,   970,   973,   982,   989,   989,   992,
     991,  1003,  1006,  1016,  1023,  1023,  1026,  1025,  1037,  1040,
    1050,  1059,  1059,  1061,  1073,  1079,  1079,  1081,  1081,  1081,
    1084,  1083,  1095,  1094,  1106,  1105,  1117,  1117,  1120,  1123,
    1133,  1141,  1141,  1143,  1155,  1161,  1161,  1163,  1163,  1163,
    1166,  1165,  1177,  1176,  1188,  1187,  1199,  1199,  1202,  1205,
    1215,  1224,  1224,  1226,  1238,  1244,  1244,  1246,  1246,  1246,
    1249,  1248,  1260,  1259,  1271,  1270,  1282,  1282,  1285,  1288,
    1298,  1306,  1306,  1308,  1320,  1326,  1326,  1328,  1328,  1328,
    1331,  1330,  1342,  1341,  1353,  1352,  1364,  1364,  1367,  1370,
    1380,  1387,  1387,  1390,  1389,  1401,  1404,  1414,  1421,  1421,
    1424,  1423,  1435,  1439,  1449,  1456,  1456,  1459,  1458,  1470,
    1472,  1482,  1490,  1495,  1495,  1498,  1497,  1512,  1512,  1514,
    1514,  1514,  1517,  1516,  1528,  1527,  1539,  1538,  1549,  1549,
    1552,  1552,  1554,  1564,  1564,  1566,  1566,  1566,  1568,  1574,
    1580,  1586,  1586,  1588,  1590,  1590,  1592,  1596,  1596,  1605,
    1607,  1609,  1609,  1611,  1621,  1621,  1623,  1631,  1636,  1636,
    1638,  1638,  1640,  1654,  1653,  1666,  1666,  1669,  1669,  1672,
    1682,  1682,  1684,  1692,  1697,  1697,  1699,  1699,  1701,  1715,
    1714,  1722,  1722,  1725,  1725,  1728,  1738,  1738,  1740,  1748,
    1753,  1753,  1755,  1755,  1757,  1771,  1770,  1778,  1778,  1781,
    1781,  1784,  1794,  1794,  1796,  1804,  1809,  1809,  1811,  1811,
    1813,  1827,  1826,  1839,  1839,  1842,  1842,  1845,  1856,  1856,
    1858,  1870,  1876,  1876,  1878,  1878,  1878,  1880,  1890,  1897,
    1904,  1915,  1916,  1918,  1918,  1920,  1928,  1933,  1933,  1935,
    1935,  1937,  1951,  1950,  1963,  1963,  1966,  1966,  1968,  1970,
    1975,  1975,  1978,  1979,  1980,  1981,  1982,  1983,  1984,  1986,
    2000,  1999,  2008,  2007,  2016,  2015,  2024,  2023,  2032,  2031,
    2040,  2039,  2048,  2065,  2065,  2067,  2077,  2082,  2082,  2085,
    2086,  2087,  2088,  2090,  2104,  2103,  2112,  2111,  2120,  2119,
    2127,  2127,  2131,  2131,  2133,  2137,  2137,  2146,  2147,  2149,
    2149,  2152,  2162,  2162,  2164,  2172,  2177,  2177,  2179,  2179,
    2181,  2196,  2195,  2208,  2208,  2211,  2211,  2214,  2224,  2224,
    2226,  2235,  2240,  2240,  2242,  2242,  2242,  2244,  2258,  2257,
    2271,  2270,  2283,  2283,  2287,  2287,  2289,  2291,  2296,  2296,
    2299,  2300,  2301,  2302,  2303,  2304,  2305,  2307,  2321,  2320,
    2330,  2329,  2339,  2338,  2348,  2347,  2357,  2356,  2366,  2365,
    2375,  2392,  2392,  2394,  2404,  2409,  2409,  2412,  2413,  2414,
    2415,  2417,  2432,  2431,  2441,  2440,  2450,  2449,  2458,  2458,
    2461,  2461,  2463,  2467,  2467,  2476,  2478,  2480,  2480,  2483,
    2493,  2493,  2495,  2503,  2508,  2508,  2510,  2510,  2512,  2527,
    2526,  2539,  2539,  2542,  2542,  2545,  2555,  2555,  2557,  2566,
    2571,  2571,  2573,  2573,  2573,  2575,  2589,  2588,  2602,  2601,
    2615,  2615,  2618,  2618,  2620,  2622,  2627,  2627,  2630,  2631,
    2632,  2633,  2634,  2635,  2636,  2638,  2652,  2651,  2660,  2659,
    2668,  2667,  2676,  2675,  2684,  2683,  2692,  2691,  2700,  2717,
    2717,  2719,  2729,  2734,  2734,  2737,  2738,  2739,  2740,  2742,
    2757,  2756,  2766,  2765,  2774,  2773,  2781,  2781,  2784,  2784,
    2789,  2799,  2807,  2807,  2810,  2809,  2827,  2827,  2830,  2831,
    2832,  2833,  2834,  2835,  2839,  2838,  2850,  2849,  2861,  2860,
    2872,  2871,  2883,  2882,  2894,  2893,  2905,  2905
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "ATTRIBUTETEXT", "ELEMENTTEXT",
  "INTEGER", "DOUBLE", "QUOTE", "GREATERTHAN", "ENDOFELEMENT", "OSOLSTART",
  "OSOLSTARTEMPTY", "OSOLATTRIBUTETEXT", "OSOLEND", "LOCATIONTYPEATT",
  "TRANSPORTTYPEATT", "NUMBEROFOTHEROPTIONSATT", "NUMBEROFJOBIDSATT",
  "NUMBEROFPATHSATT", "NUMBEROFPATHPAIRSATT", "FROMATT", "TOATT",
  "MAKECOPYATT", "SOLVERATT", "CATEGORYATT", "TYPEATT", "GROUPWEIGHTATT",
  "NUMBEROFPROCESSESATT", "NUMBEROFSOLVEROPTIONSATT", "NUMBEROFSOSATT",
  "NUMBEROFVARIABLESATT", "NUMBEROFOBJECTIVESATT",
  "NUMBEROFCONSTRAINTSATT", "NUMBEROFOTHERVARIABLEOPTIONSATT",
  "NUMBEROFOTHEROBJECTIVEOPTIONSATT", "NUMBEROFOTHERCONSTRAINTOPTIONSATT",
  "NUMBEROFVARATT", "NUMBEROFOBJATT", "NUMBEROFCONATT", "NAMEATT",
  "IDXATT", "SOSIDXATT", "VALUEATT", "UNITATT", "DESCRIPTIONATT",
  "LBVALUEATT", "UBVALUEATT", "LBDUALVALUEATT", "UBDUALVALUEATT",
  "GENERALSTART", "GENERALEND", "SYSTEMSTART", "SYSTEMEND", "SERVICESTART",
  "SERVICEEND", "JOBSTART", "JOBEND", "OPTIMIZATIONSTART",
  "OPTIMIZATIONEND", "SERVICEURISTART", "SERVICEURIEND",
  "SERVICENAMESTART", "SERVICENAMEEND", "INSTANCENAMESTART",
  "INSTANCENAMEEND", "INSTANCELOCATIONSTART", "INSTANCELOCATIONEND",
  "JOBIDSTART", "JOBIDEND", "SOLVERTOINVOKESTART", "SOLVERTOINVOKEEND",
  "LICENSESTART", "LICENSEEND", "USERNAMESTART", "USERNAMEEND",
  "PASSWORDSTART", "PASSWORDEND", "CONTACTSTART", "CONTACTEND",
  "OTHEROPTIONSSTART", "OTHEROPTIONSEND", "OTHERSTART", "OTHEREND",
  "MINDISKSPACESTART", "MINDISKSPACEEND", "MINMEMORYSIZESTART",
  "MINMEMORYSIZEEND", "MINCPUSPEEDSTART", "MINCPUSPEEDEND",
  "MINCPUNUMBERSTART", "MINCPUNUMBEREND", "SERVICETYPESTART",
  "SERVICETYPEEND", "MAXTIMESTART", "MAXTIMEEND",
  "SCHEDULEDSTARTTIMESTART", "SCHEDULEDSTARTTIMEEND", "DEPENDENCIESSTART",
  "DEPENDENCIESEND", "REQUIREDDIRECTORIESSTART", "REQUIREDDIRECTORIESEND",
  "REQUIREDFILESSTART", "REQUIREDFILESEND", "PATHSTART", "PATHEND",
  "PATHPAIRSTART", "PATHPAIREND", "DIRECTORIESTOMAKESTART",
  "DIRECTORIESTOMAKEEND", "FILESTOMAKESTART", "FILESTOMAKEEND",
  "DIRECTORIESTODELETESTART", "DIRECTORIESTODELETEEND",
  "FILESTODELETESTART", "FILESTODELETEEND", "INPUTDIRECTORIESTOMOVESTART",
  "INPUTDIRECTORIESTOMOVEEND", "INPUTFILESTOMOVESTART",
  "INPUTFILESTOMOVEEND", "OUTPUTDIRECTORIESTOMOVESTART",
  "OUTPUTDIRECTORIESTOMOVEEND", "OUTPUTFILESTOMOVESTART",
  "OUTPUTFILESTOMOVEEND", "PROCESSESTOKILLSTART", "PROCESSESTOKILLEND",
  "PROCESSSTART", "PROCESSEND", "VARIABLESSTART", "VARIABLESEND",
  "INITIALVARIABLEVALUESSTART", "INITIALVARIABLEVALUESEND", "VARSTART",
  "VAREND", "INITIALVARIABLEVALUESSTRINGSTART",
  "INITIALVARIABLEVALUESSTRINGEND", "INITIALBASISSTATUSSTART",
  "INITIALBASISSTATUSEND", "INTEGERVARIABLEBRANCHINGWEIGHTSSTART",
  "INTEGERVARIABLEBRANCHINGWEIGHTSEND", "SOSVARIABLEBRANCHINGWEIGHTSSTART",
  "SOSVARIABLEBRANCHINGWEIGHTSEND", "SOSSTART", "SOSEND",
  "OBJECTIVESSTART", "OBJECTIVESEND", "INITIALOBJECTIVEVALUESSTART",
  "INITIALOBJECTIVEVALUESEND", "OBJSTART", "OBJEND",
  "INITIALOBJECTIVEBOUNDSSTART", "INITIALOBJECTIVEBOUNDSEND",
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
  "mindiskspaceunit", "@15", "mindiskspacebody", "minmemorysize",
  "minmemorysizehead", "minmemoryunit", "@16", "minmemorysizebody",
  "mincpuspeed", "mincpuspeedhead", "mincpuspeedunit", "@17",
  "mincpuspeedbody", "mincpunumber", "mincpunumberhead",
  "mincpunumberbody", "@18", "othersystemoptions",
  "othersystemoptionshead", "numberofothersystemoptions",
  "othersystemoptionsbody", "othersystemoptionslist", "othersystemoption",
  "@19", "othersystemattributes", "othersystemattribute",
  "systemoptionnameatt", "@20", "systemoptionvalueatt", "@21",
  "systemoptiondescriptionatt", "@22", "othersystemoptionend",
  "osolservice", "servicehead", "servicebody", "servicecontent",
  "serviceoption", "servicetype", "servicetypehead", "servicetypebody",
  "@23", "otherserviceoptions", "otherserviceoptionshead",
  "numberofotherserviceoptions", "otherserviceoptionsbody",
  "otherserviceoptionslist", "otherserviceoption", "@24",
  "otherserviceattributes", "otherserviceattribute",
  "serviceoptionnameatt", "@25", "serviceoptionvalueatt", "@26",
  "serviceoptiondescriptionatt", "@27", "otherserviceoptionsend",
  "osoljob", "jobhead", "jobbody", "jobcontent", "joboption", "maxtime",
  "maxtimehead", "maxtimeunit", "@28", "maxtimebody", "scheduledstarttime",
  "starttimehead", "starttimebody", "@29", "dependencies",
  "dependencieshead", "numberofjobidsatt", "dependencieslist",
  "dependencyjobid", "@30", "requireddirectories",
  "requireddirectorieshead", "numberofreqdirpathsatt", "reqdirpathlist",
  "reqdirpath", "@31", "requiredfiles", "requiredfileshead",
  "numberofreqfilespathsatt", "reqfilespathlist", "reqfilepath", "@32",
  "directoriestomake", "directoriestomakehead",
  "numberofdirtomakepathsatt", "dirtomakepathlist", "dirtomakepath", "@33",
  "filestomake", "filestomakehead", "numberoffilestomakepathsatt",
  "filestomakepathlist", "filestomakepath", "@34",
  "inputdirectoriestomove", "inputdirectoriestomovehead",
  "numberofindirtomovepathpairsatt", "indirtomovepathpairlist",
  "indirtomovepathpair", "indirtomovepathpairhead",
  "indirtomovepathpairattlist", "indirtomovepathpairatt",
  "indirtomovefromatt", "@35", "indirtomovetoatt", "@36",
  "indirtomovemakecopyatt", "@37", "indirtomovepathpairend",
  "inputfilestomove", "inputfilestomovehead",
  "numberofinfilestomovepathpairsatt", "infilestomovepathpairlist",
  "infilestomovepathpair", "infilestomovepathpairhead",
  "infilestomovepathpairattlist", "infilestomovepathpairatt",
  "infilestomovefromatt", "@38", "infilestomovetoatt", "@39",
  "infilestomovemakecopyatt", "@40", "infilestomovepathpairend",
  "outputdirectoriestomove", "outputdirectoriestomovehead",
  "numberofoutdirtomovepathpairsatt", "outdirtomovepathpairlist",
  "outdirtomovepathpair", "outdirtomovepathpairhead",
  "outdirtomovepathpairattlist", "outdirtomovepathpairatt",
  "outdirtomovefromatt", "@41", "outdirtomovetoatt", "@42",
  "outdirtomovemakecopyatt", "@43", "outdirtomovepathpairend",
  "outputfilestomove", "outputfilestomovehead",
  "numberofoutfilestomovepathpairsatt", "outfilestomovepathpairlist",
  "outfilestomovepathpair", "outfilestomovepathpairhead",
  "outfilestomovepathpairattlist", "outfilestomovepathpairatt",
  "outfilestomovefromatt", "@44", "outfilestomovetoatt", "@45",
  "outfilestomovemakecopyatt", "@46", "outfilestomovepathpairend",
  "filestodelete", "filestodeletehead", "numberoffilestodeletepathsatt",
  "filestodeletepathlist", "filestodeletepath", "@47",
  "directoriestodelete", "directoriestodeletehead",
  "numberofdirtodeletepathsatt", "dirtodeletepathlist", "dirtodeletepath",
  "@48", "processestokill", "processestokillhead",
  "numberofprocesstokillatt", "processestokilllist", "processtokill",
  "@49", "otherjoboptions", "otherjoboptionshead",
  "numberofotherjoboptions", "otherjoboptionsbody", "otherjoboptionslist",
  "otherjoboption", "@50", "otherjobattributes", "otherjobattribute",
  "joboptionnameatt", "@51", "joboptionvalueatt", "@52",
  "joboptiondescriptionatt", "@53", "otherjoboptionsend",
  "osoloptimization", "optimizationhead", "optimizationattlist",
  "optimizationatt", "optimizationnvar", "optimizationncon",
  "optimizationnobj", "optimizationbody", "optimizationcontent",
  "variables", "variablesstart", "numberofothervariablesatt",
  "restofvariables", "initialvariablevalues", "numberofvar", "varlist",
  "initvarvalue", "varstart", "initvarvalueattlist", "initvarvalueatt",
  "initvarvalueidxatt", "initvarvaluevalueatt", "@54", "initvarvalueend",
  "initialvariablevaluesstring", "numberofvarstr", "varstrlist",
  "initvarstrvalue", "varstrstart", "initvarstrvalueattlist",
  "initvarstrvalueatt", "initvarstrvalueidxatt", "initvarstrvaluevalueatt",
  "@55", "initvarstrvalueend", "initialbasisstatus", "numberofbasvar",
  "basvarlist", "initbasvalue", "basvarstart", "initbasvarvalueattlist",
  "initbasvarvalueatt", "initbasvarvalueidxatt", "initbasvarvaluevalueatt",
  "@56", "initbasvarvalueend", "integervariablebranchingweights",
  "numberofintegerweights", "intweightlist", "intweight", "intweightstart",
  "intweightattlist", "intweightatt", "intweightidxatt",
  "intweightvalueatt", "@57", "intweightend",
  "sosvariablebranchingweights", "numberofsosweightgroups",
  "sosweightgrouplist", "sosweightgroup", "sosweightgroupstart",
  "sosweightgroupattlist", "sosweightgroupatt", "sosweightgroupidxatt",
  "sosweightgroupweightatt", "sosweightgroupnvaratt",
  "sosweightgroupcontent", "sosweightgroupvars", "sosweightvar",
  "sosweightvarstart", "sosweightvarattlist", "sosweightvaratt",
  "sosweightvaridxatt", "sosweightvarvalueatt", "@58", "sosweightvarend",
  "othervariableoptionlist", "othervariableoption",
  "othervariableoptionstart", "othervariableoptionsattlist",
  "othervariableoptionsatt", "othervariableoptionnumberofvar",
  "othervariableoptionname", "@59", "othervariableoptionvalue", "@60",
  "othervariableoptionsolver", "@61", "othervariableoptioncategory", "@62",
  "othervariableoptiontype", "@63", "othervariableoptiondescription",
  "@64", "restofothervariableoption", "othervariableoptionsvarlist",
  "othervariableoptionsvar", "othervariableoptionsvarstart",
  "othervaroptionattlist", "othervaroptionatt", "othervaroptionidx",
  "othervaroptionvalue", "@65", "othervaroptionlbvalue", "@66",
  "othervaroptionubvalue", "@67", "othervaroptionend", "objectives",
  "objectivesstart", "numberofotherobjectivesatt", "restofobjectives",
  "initialobjectivevalues", "numberofobjval", "objvaluelist",
  "initobjvalue", "objvaluestart", "initobjvalueattlist",
  "initobjvalueatt", "initobjvalueidxatt", "initobjvaluevalueatt", "@68",
  "initobjvalueend", "initialobjectivebounds", "numberofobjbounds",
  "objboundlist", "initobjbound", "objboundstart", "initobjboundattlist",
  "initobjboundatt", "initobjboundidxatt", "initobjvaluelowerboundatt",
  "@69", "initobjvalueupperboundatt", "@70", "initobjboundend",
  "otherobjectiveoptionlist", "otherobjectiveoption",
  "otherobjectiveoptionstart", "otherobjectiveoptionsattlist",
  "otherobjectiveoptionsatt", "otherobjectiveoptionnumberofobj",
  "otherobjectiveoptionname", "@71", "otherobjectiveoptionvalue", "@72",
  "otherobjectiveoptionsolver", "@73", "otherobjectiveoptioncategory",
  "@74", "otherobjectiveoptiontype", "@75",
  "otherobjectiveoptiondescription", "@76", "restofotherobjectiveoption",
  "otherobjectiveoptionsobjlist", "otherobjectiveoptionsobj",
  "otherobjectiveoptionsobjstart", "otherobjoptionattlist",
  "otherobjoptionatt", "otherobjoptionidx", "otherobjoptionvalue", "@77",
  "otherobjoptionlbvalue", "@78", "otherobjoptionubvalue", "@79",
  "otherobjoptionend", "constraints", "constraintsstart",
  "numberofotherconstraintsatt", "restofconstraints",
  "initialconstraintvalues", "numberofconval", "conlist", "initconvalue",
  "constart", "initconvalueattlist", "initconvalueatt",
  "initconvalueidxatt", "initconvaluevalueatt", "@80", "initconvalueend",
  "initialdualvalues", "numberofduals", "duallist", "initdualvalue",
  "dualstart", "initdualvalueattlist", "initdualvalueatt",
  "initdualvalueidxatt", "initdualvaluelowerboundatt", "@81",
  "initdualvalueupperboundatt", "@82", "initdualvalueend",
  "otherconstraintoptionlist", "otherconstraintoption",
  "otherconstraintoptionstart", "otherconstraintoptionsattlist",
  "otherconstraintoptionsatt", "otherconstraintoptionnumberofcon",
  "otherconstraintoptionname", "@83", "otherconstraintoptionvalue", "@84",
  "otherconstraintoptionsolver", "@85", "otherconstraintoptioncategory",
  "@86", "otherconstraintoptiontype", "@87",
  "otherconstraintoptiondescription", "@88", "restofotherconstraintoption",
  "otherconstraintoptionsconlist", "otherconstraintoptionscon",
  "otherconstraintoptionsconstart", "otherconoptionattlist",
  "otherconoptionatt", "otherconoptionidx", "otherconoptionvalue", "@89",
  "otherconoptionlbvalue", "@90", "otherconoptionubvalue", "@91",
  "otherconoptionend", "solveroptions", "solveroptionsstart",
  "numberofsolveroptionsatt", "solveroptionlist", "solveroption", "@92",
  "solveroptionattlist", "solveroptionatt", "solveroptionname", "@93",
  "solveroptionvalue", "@94", "solveroptionsolver", "@95",
  "solveroptioncategory", "@96", "solveroptiontype", "@97",
  "solveroptiondescription", "@98", "solveroptionend", 0
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
     395,   396,   397,   398,   399,   400,   401,   402,   403,   404,
     405,   406,   407,   408,   409,   410,   411,   412,   413,   414,
     415,   416,   417,   418
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   164,   165,   165,   165,   166,   166,   167,   167,   168,
     168,   169,   170,   170,   171,   171,   172,   172,   172,   172,
     172,   172,   172,   172,   172,   172,   172,   173,   174,   175,
     175,   176,   175,   177,   178,   179,   179,   180,   179,   181,
     182,   183,   183,   184,   183,   185,   186,   187,   188,   187,
     189,   189,   190,   190,   191,   192,   193,   193,   194,   193,
     195,   196,   197,   197,   198,   197,   199,   200,   201,   201,
     202,   201,   203,   204,   205,   205,   206,   205,   207,   208,
     209,   209,   210,   209,   211,   212,   213,   214,   213,   215,
     215,   216,   216,   217,   218,   219,   220,   221,   221,   223,
     222,   224,   224,   225,   225,   225,   227,   226,   229,   228,
     231,   230,   232,   232,   233,   233,   234,   235,   235,   236,
     236,   237,   237,   237,   237,   237,   238,   239,   240,   241,
     240,   242,   242,   242,   242,   243,   244,   245,   246,   245,
     247,   247,   247,   247,   248,   249,   250,   251,   250,   252,
     252,   252,   252,   253,   254,   255,   255,   256,   255,   257,
     258,   259,   260,   261,   261,   263,   262,   264,   264,   265,
     265,   265,   267,   266,   269,   268,   271,   270,   272,   272,
     273,   273,   274,   275,   275,   276,   276,   277,   277,   278,
     279,   280,   280,   281,   280,   282,   283,   284,   285,   286,
     286,   288,   287,   289,   289,   290,   290,   290,   292,   291,
     294,   293,   296,   295,   297,   297,   298,   298,   299,   300,
     300,   301,   301,   302,   302,   302,   302,   302,   302,   302,
     302,   302,   302,   302,   302,   302,   302,   302,   303,   304,
     305,   306,   305,   307,   307,   307,   307,   308,   309,   310,
     310,   311,   310,   312,   313,   314,   315,   315,   317,   316,
     318,   319,   320,   321,   321,   323,   322,   324,   325,   326,
     327,   327,   329,   328,   330,   331,   332,   333,   333,   335,
     334,   336,   337,   338,   339,   339,   341,   340,   342,   343,
     344,   345,   345,   346,   347,   348,   348,   349,   349,   349,
     351,   350,   353,   352,   355,   354,   356,   356,   357,   358,
     359,   360,   360,   361,   362,   363,   363,   364,   364,   364,
     366,   365,   368,   367,   370,   369,   371,   371,   372,   373,
     374,   375,   375,   376,   377,   378,   378,   379,   379,   379,
     381,   380,   383,   382,   385,   384,   386,   386,   387,   388,
     389,   390,   390,   391,   392,   393,   393,   394,   394,   394,
     396,   395,   398,   397,   400,   399,   401,   401,   402,   403,
     404,   405,   405,   407,   406,   408,   409,   410,   411,   411,
     413,   412,   414,   415,   416,   417,   417,   419,   418,   420,
     421,   422,   423,   424,   424,   426,   425,   427,   427,   428,
     428,   428,   430,   429,   432,   431,   434,   433,   435,   435,
     436,   436,   437,   438,   438,   439,   439,   439,   440,   441,
     442,   443,   443,   444,   445,   445,   446,   447,   447,   448,
     448,   449,   449,   450,   451,   451,   452,   453,   454,   454,
     455,   455,   456,   458,   457,   459,   459,   460,   460,   461,
     462,   462,   463,   464,   465,   465,   466,   466,   467,   469,
     468,   470,   470,   471,   471,   472,   473,   473,   474,   475,
     476,   476,   477,   477,   478,   480,   479,   481,   481,   482,
     482,   483,   484,   484,   485,   486,   487,   487,   488,   488,
     489,   491,   490,   492,   492,   493,   493,   494,   495,   495,
     496,   497,   498,   498,   499,   499,   499,   500,   501,   501,
     502,   503,   503,   504,   504,   505,   506,   507,   507,   508,
     508,   509,   511,   510,   512,   512,   513,   513,   514,   515,
     516,   516,   517,   517,   517,   517,   517,   517,   517,   518,
     520,   519,   522,   521,   524,   523,   526,   525,   528,   527,
     530,   529,   531,   532,   532,   533,   534,   535,   535,   536,
     536,   536,   536,   537,   539,   538,   541,   540,   543,   542,
     544,   544,   545,   545,   546,   547,   547,   548,   548,   549,
     549,   550,   551,   551,   552,   553,   554,   554,   555,   555,
     556,   558,   557,   559,   559,   560,   560,   561,   562,   562,
     563,   564,   565,   565,   566,   566,   566,   567,   569,   568,
     571,   570,   572,   572,   573,   573,   574,   575,   576,   576,
     577,   577,   577,   577,   577,   577,   577,   578,   580,   579,
     582,   581,   584,   583,   586,   585,   588,   587,   590,   589,
     591,   592,   592,   593,   594,   595,   595,   596,   596,   596,
     596,   597,   599,   598,   601,   600,   603,   602,   604,   604,
     605,   605,   606,   607,   607,   608,   608,   609,   609,   610,
     611,   611,   612,   613,   614,   614,   615,   615,   616,   618,
     617,   619,   619,   620,   620,   621,   622,   622,   623,   624,
     625,   625,   626,   626,   626,   627,   629,   628,   631,   630,
     632,   632,   633,   633,   634,   635,   636,   636,   637,   637,
     637,   637,   637,   637,   637,   638,   640,   639,   642,   641,
     644,   643,   646,   645,   648,   647,   650,   649,   651,   652,
     652,   653,   654,   655,   655,   656,   656,   656,   656,   657,
     659,   658,   661,   660,   663,   662,   664,   664,   665,   665,
     666,   667,   668,   668,   670,   669,   671,   671,   672,   672,
     672,   672,   672,   672,   674,   673,   676,   675,   678,   677,
     680,   679,   682,   681,   684,   683,   685,   685
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     4,     2,     3,     1,     2,     0,     5,     0,
       2,     1,     3,     1,     0,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     2,     1,     1,
       2,     0,     4,     2,     1,     1,     2,     0,     4,     2,
       1,     1,     2,     0,     4,     3,     1,     0,     0,     4,
       1,     3,     0,     1,     2,     1,     1,     2,     0,     4,
       2,     1,     1,     2,     0,     4,     2,     1,     1,     2,
       0,     4,     2,     1,     1,     2,     0,     4,     2,     1,
       1,     2,     0,     4,     3,     1,     0,     0,     4,     1,
       3,     0,     1,     4,     1,     4,     2,     0,     2,     0,
       4,     0,     2,     1,     1,     1,     0,     4,     0,     4,
       0,     4,     1,     2,     0,     2,     1,     3,     1,     0,
       2,     1,     1,     1,     1,     1,     3,     1,     0,     0,
       4,     1,     2,     3,     3,     3,     1,     0,     0,     4,
       1,     2,     3,     3,     3,     1,     0,     0,     4,     1,
       2,     3,     3,     2,     1,     1,     2,     0,     4,     4,
       1,     4,     2,     0,     2,     0,     4,     0,     2,     1,
       1,     1,     0,     4,     0,     4,     0,     4,     1,     2,
       0,     2,     1,     3,     1,     0,     2,     1,     1,     2,
       1,     1,     2,     0,     4,     4,     1,     4,     2,     0,
       2,     0,     4,     0,     2,     1,     1,     1,     0,     4,
       0,     4,     0,     4,     1,     2,     0,     2,     1,     3,
       1,     0,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     3,     1,
       0,     0,     4,     1,     2,     3,     3,     2,     1,     1,
       2,     0,     4,     5,     1,     4,     0,     2,     0,     5,
       5,     1,     4,     0,     2,     0,     5,     5,     1,     4,
       0,     2,     0,     5,     5,     1,     4,     0,     2,     0,
       5,     5,     1,     4,     0,     2,     0,     5,     5,     1,
       4,     0,     2,     3,     1,     0,     2,     1,     1,     1,
       0,     4,     0,     4,     0,     4,     2,     1,     5,     1,
       4,     0,     2,     3,     1,     0,     2,     1,     1,     1,
       0,     4,     0,     4,     0,     4,     2,     1,     5,     1,
       4,     0,     2,     3,     1,     0,     2,     1,     1,     1,
       0,     4,     0,     4,     0,     4,     2,     1,     5,     1,
       4,     0,     2,     3,     1,     0,     2,     1,     1,     1,
       0,     4,     0,     4,     0,     4,     2,     1,     5,     1,
       4,     0,     2,     0,     5,     5,     1,     4,     0,     2,
       0,     5,     5,     1,     4,     0,     2,     0,     5,     4,
       1,     4,     2,     0,     2,     0,     4,     0,     2,     1,
       1,     1,     0,     4,     0,     4,     0,     4,     1,     2,
       0,     3,     1,     0,     2,     1,     1,     1,     4,     4,
       4,     3,     1,     4,     0,     3,     1,     0,     4,     8,
       1,     0,     5,     4,     0,     2,     3,     1,     0,     2,
       1,     1,     4,     0,     4,     2,     1,     0,     5,     4,
       0,     2,     3,     1,     0,     2,     1,     1,     4,     0,
       4,     2,     1,     0,     5,     4,     0,     2,     3,     1,
       0,     2,     1,     1,     4,     0,     4,     2,     1,     0,
       5,     4,     0,     2,     3,     1,     0,     2,     1,     1,
       4,     0,     4,     2,     1,     0,     5,     4,     0,     2,
       3,     1,     0,     2,     1,     1,     1,     4,     4,     4,
       4,     3,     1,     0,     2,     3,     1,     0,     2,     1,
       1,     4,     0,     4,     2,     1,     0,     2,     3,     1,
       0,     2,     1,     1,     1,     1,     1,     1,     1,     4,
       0,     4,     0,     4,     0,     4,     0,     4,     0,     4,
       0,     4,     3,     0,     2,     3,     1,     0,     2,     1,
       1,     1,     1,     4,     0,     4,     0,     4,     0,     4,
       2,     1,     0,     3,     1,     0,     4,     5,     1,     0,
       5,     4,     0,     2,     3,     1,     0,     2,     1,     1,
       4,     0,     4,     2,     1,     0,     5,     4,     0,     2,
       3,     1,     0,     2,     1,     1,     1,     4,     0,     4,
       0,     4,     2,     1,     0,     2,     3,     1,     0,     2,
       1,     1,     1,     1,     1,     1,     1,     4,     0,     4,
       0,     4,     0,     4,     0,     4,     0,     4,     0,     4,
       3,     0,     2,     3,     1,     0,     2,     1,     1,     1,
       1,     4,     0,     4,     0,     4,     0,     4,     2,     1,
       0,     3,     1,     0,     4,     5,     1,     0,     5,     4,
       0,     2,     3,     1,     0,     2,     1,     1,     4,     0,
       4,     2,     1,     0,     5,     4,     0,     2,     3,     1,
       0,     2,     1,     1,     1,     4,     0,     4,     0,     4,
       2,     1,     0,     2,     3,     1,     0,     2,     1,     1,
       1,     1,     1,     1,     1,     4,     0,     4,     0,     4,
       0,     4,     0,     4,     0,     4,     0,     4,     3,     0,
       2,     3,     1,     0,     2,     1,     1,     1,     1,     4,
       0,     4,     0,     4,     0,     4,     2,     1,     0,     5,
       1,     4,     0,     2,     0,     4,     0,     2,     1,     1,
       1,     1,     1,     1,     0,     4,     0,     4,     0,     4,
       0,     4,     0,     4,     0,     4,     2,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       0,     5,     9,     0,     0,     6,    11,     0,   114,     0,
       1,     9,     3,     4,   116,   180,     0,    14,    13,    10,
       0,   182,   216,     0,   119,   118,   115,     0,     2,   218,
     410,     0,   185,   184,   181,     0,    12,    28,    34,    40,
      46,    55,    61,    67,    73,    79,    85,    94,    15,    16,
       0,    17,     0,    18,     0,    19,    47,    20,     0,    21,
       0,    22,     0,    23,     0,    24,     0,    25,    86,    26,
       0,   412,     8,   413,   221,   220,   217,     0,   117,   160,
     127,   136,   145,   154,   120,   121,   128,   122,   137,   123,
     146,   124,     0,   125,     0,     0,    29,    27,     0,    35,
      33,     0,    41,    39,     0,     0,     0,    56,    54,     0,
      62,    60,     0,    68,    66,     0,    74,    72,     0,    80,
      78,     0,     0,     0,     0,     0,     0,   183,   196,   190,
     186,   187,     0,   188,     0,     0,     0,     0,     0,     0,
       0,     0,   155,   153,     0,     0,    31,    30,    37,    36,
      43,    42,    48,    52,    50,    45,    58,    57,    64,    63,
      70,    69,    76,    75,    82,    81,    87,    91,    89,    84,
       0,    97,   424,   422,     0,     0,     0,   414,   415,   416,
     417,   411,   219,   390,   239,   248,   254,   261,   268,   275,
     282,   376,   369,   289,   309,   329,   349,   383,   222,   223,
     240,   224,     0,   225,     0,   226,     0,   227,     0,   228,
       0,   229,     0,   230,     0,   231,     0,   232,     0,   233,
       0,   234,     0,   235,     0,   236,     0,   237,     0,     0,
     191,   189,     0,     0,   129,     0,   131,   126,   138,     0,
     140,   135,   147,     0,   149,   144,   157,   156,     0,   163,
       0,     0,     0,     0,    53,     0,     0,     0,     0,     0,
       0,     0,    92,     0,     0,    93,     0,   426,     0,   572,
     427,     0,     0,     0,     0,     0,     0,   249,   247,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   193,   192,     0,   199,     0,
       0,     0,   132,     0,     0,     0,   141,     0,     0,     0,
     150,     0,     0,   159,     0,    32,    38,    44,    49,    51,
      59,    65,    71,    77,    83,    88,    90,    95,    96,    99,
      98,   421,   574,   660,   575,     0,     0,     0,     0,     0,
     241,     0,   243,   238,   251,   250,     0,   256,     0,   263,
       0,   270,     0,   277,     0,   284,     0,   291,     0,   311,
       0,   331,     0,   351,     0,   371,     0,   378,     0,   385,
       0,   393,     0,     0,   195,     0,   130,   134,   133,   139,
     143,   142,   148,   152,   151,   158,   161,   162,   165,   164,
     101,   662,   748,   663,     0,     0,     0,   431,   430,   425,
     418,   420,   419,     0,     0,     0,   244,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   389,     0,   194,   197,   198,   201,   200,
     167,     0,   750,   423,     0,     0,     0,     0,   579,   578,
     573,     0,     0,   447,   242,   246,   245,   252,   255,     0,
     253,   257,   262,   260,     0,   264,   269,   267,     0,   271,
     276,     0,   274,   278,   283,     0,   281,   285,   290,   294,
     288,   292,   295,   310,   314,   308,   312,   315,   330,   334,
     328,   332,   335,   350,   354,   348,   352,   355,   370,     0,
     368,   372,   377,     0,   375,   379,   384,   382,     0,   386,
     391,   392,   395,   394,   203,     0,     0,   112,     0,     0,
       0,   102,   103,   104,   105,   100,     0,     0,     0,   667,
     666,   661,     0,     0,   595,   428,     0,     0,     0,   463,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   397,     0,     0,   178,     0,     0,     0,   168,
     169,   170,   171,   166,   113,   106,   108,   110,     0,   752,
       0,     0,   683,   576,     0,     0,     0,   614,     0,   434,
       0,     0,     0,   479,   258,   265,   272,   279,   286,     0,
     307,     0,     0,     0,   296,   297,   298,   299,   293,     0,
     327,     0,     0,     0,   316,   317,   318,   319,   313,     0,
     347,     0,     0,     0,   336,   337,   338,   339,   333,     0,
     367,     0,     0,     0,   356,   357,   358,   359,   353,   373,
     380,   387,     0,     0,   214,     0,     0,     0,   204,   205,
     206,   207,   202,   179,   172,   174,   176,     0,     0,     0,
       0,     0,   664,     0,     0,     0,   702,     0,   582,     0,
       0,     0,     0,     0,     0,   450,     0,     0,     0,   495,
       0,     0,     0,     0,     0,   306,   300,   302,   304,   326,
     320,   322,   324,   346,   340,   342,   344,   366,   360,   362,
     364,     0,     0,     0,     0,   408,     0,     0,     0,   398,
     399,   400,   401,   396,   215,   208,   210,   212,     0,     0,
       0,   107,   109,   111,   751,   749,   754,   753,     0,   670,
       0,     0,     0,     0,     0,     0,   598,   617,   577,   615,
     618,   433,   432,   437,   435,   438,     0,     0,     0,   466,
       0,     0,     0,   526,   259,   266,   273,   280,   287,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   374,   381,   388,   409,   402,   404,   406,     0,     0,
       0,   173,   175,   177,   756,     0,     0,     0,   686,   705,
     665,   703,   706,   581,   580,   585,   583,   586,     0,     0,
       0,     0,   449,   453,   448,   451,   454,     0,     0,     0,
     482,     0,     0,     0,   301,   303,   305,   321,   323,   325,
     341,   343,   345,   361,   363,   365,     0,     0,     0,   209,
     211,   213,     0,   669,   668,   673,   671,   674,     0,     0,
       0,     0,   597,   601,   596,   599,   602,   641,     0,     0,
       0,     0,     0,     0,     0,   619,   620,   621,   622,   623,
     624,   625,   626,   616,     0,   446,     0,     0,   439,   440,
     441,   436,     0,   465,   469,   464,   467,   470,     0,     0,
       0,   498,   529,   429,   527,   530,   403,   405,   407,     0,
     777,     0,     0,     0,     0,     0,     0,   757,   758,   759,
     760,   761,   762,   763,   755,     0,   685,   689,   684,   687,
     690,   729,     0,     0,     0,     0,     0,     0,     0,   707,
     708,   709,   710,   711,   712,   713,   714,   704,     0,   594,
       0,     0,   587,   588,   589,   584,     0,     0,   632,   634,
     636,     0,   628,   630,   638,   445,     0,   443,     0,   462,
       0,     0,   455,   456,   457,   452,     0,   481,   485,   480,
     483,   486,     0,     0,     0,   776,   768,   770,   772,   764,
     766,   774,     0,   682,     0,     0,   675,   676,   677,   672,
       0,     0,   720,   722,   724,     0,   716,   718,   726,   593,
       0,   591,     0,   613,     0,     0,     0,   603,   604,   605,
     606,   600,   640,   644,   642,   645,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   461,     0,   459,     0,   478,
       0,     0,   471,   472,   473,   468,     0,   497,   496,   501,
     499,   502,   553,     0,     0,     0,     0,     0,     0,     0,
     531,   532,   533,   534,   535,   536,   537,   538,   528,     0,
       0,     0,     0,     0,     0,   681,     0,   679,     0,   701,
       0,     0,     0,   691,   692,   693,   694,   688,   728,   732,
     730,   733,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   612,     0,   608,   610,     0,   633,   635,   637,   627,
     629,   631,   639,   442,   444,     0,     0,   477,     0,   475,
       0,   494,     0,     0,   487,   488,   489,   484,     0,     0,
     544,   546,   548,     0,   540,   542,   550,   769,   771,   773,
     765,   767,   775,     0,     0,   700,     0,   696,   698,     0,
     721,   723,   725,   715,   717,   719,   727,   590,   592,     0,
       0,     0,     0,   659,     0,     0,     0,     0,   646,   647,
     648,   649,   650,   643,   458,   460,     0,     0,   493,     0,
     491,   513,   512,     0,     0,     0,   503,   504,   506,   505,
     500,   552,   556,   554,   557,     0,     0,     0,     0,     0,
       0,     0,   678,   680,     0,     0,     0,     0,   747,     0,
       0,     0,     0,   734,   735,   736,   737,   738,   731,   607,
     609,   611,   658,     0,   652,   654,   656,   474,   476,     0,
       0,     0,     0,     0,     0,     0,   545,   547,   549,   539,
     541,   543,   551,   695,   697,   699,   746,     0,   740,   742,
     744,     0,     0,     0,     0,   490,   492,   516,   511,   514,
     517,     0,     0,     0,     0,     0,   571,     0,     0,     0,
       0,   558,   559,   560,   561,   562,   555,     0,     0,     0,
       0,   651,   653,   655,   657,     0,   509,   508,   510,   507,
     570,     0,   564,   566,   568,   739,   741,   743,   745,     0,
     525,     0,     0,   518,   519,   520,   515,     0,     0,     0,
       0,   524,     0,   522,   563,   565,   567,   569,     0,     0,
     521,   523
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     3,     4,     7,     8,     9,    19,    27,    48,    49,
      50,    97,   250,    51,    52,   100,   251,    53,    54,   103,
     252,    55,    56,   105,   253,   155,   255,    57,    58,   108,
     256,    59,    60,   111,   257,    61,    62,   114,   258,    63,
      64,   117,   259,    65,    66,   120,   260,    67,    68,   122,
     261,   169,   263,    69,    70,   124,   265,   266,   340,   400,
     451,   531,   532,   657,   533,   658,   534,   659,   535,    15,
      16,    26,    35,    84,    85,    86,   136,   309,   237,    87,
      88,   138,   313,   241,    89,    90,   140,   317,   245,    91,
      92,   143,   321,    93,    94,   145,   323,   324,   399,   450,
     525,   569,   570,   718,   571,   719,   572,   720,   573,    22,
      23,    34,    77,   130,   131,   132,   231,   382,   133,   134,
     233,   384,   385,   449,   524,   563,   648,   649,   778,   650,
     779,   651,   780,   652,    30,    31,    76,   126,   198,   199,
     200,   275,   413,   353,   201,   202,   278,   417,   203,   204,
     280,   419,   471,   680,   205,   206,   282,   421,   475,   681,
     207,   208,   284,   423,   479,   682,   209,   210,   286,   425,
     483,   683,   211,   212,   288,   427,   487,   684,   213,   214,
     290,   429,   491,   492,   555,   604,   605,   759,   606,   760,
     607,   761,   608,   215,   216,   292,   431,   496,   497,   556,
     614,   615,   762,   616,   763,   617,   764,   618,   217,   218,
     294,   433,   501,   502,   557,   624,   625,   765,   626,   766,
     627,   767,   628,   219,   220,   296,   435,   506,   507,   558,
     634,   635,   768,   636,   769,   637,   770,   638,   221,   222,
     298,   437,   511,   701,   223,   224,   300,   439,   515,   702,
     225,   226,   302,   441,   519,   703,   227,   228,   304,   443,
     444,   523,   562,   642,   709,   710,   826,   711,   827,   712,
     828,   713,    72,    73,   125,   177,   178,   179,   180,   181,
     268,   269,   270,   346,   409,   463,   547,   673,   744,   745,
     801,   868,   869,   870,  1014,   871,   549,   591,   747,   805,
     806,   872,   952,   953,   954,  1096,   955,   593,   677,   808,
     876,   877,   956,  1022,  1023,  1024,  1157,  1025,   679,   751,
     879,   960,   961,  1026,  1104,  1105,  1106,  1210,  1107,   753,
     812,   963,  1030,  1031,  1108,  1166,  1167,  1168,  1169,  1170,
    1211,  1239,  1240,  1265,  1283,  1284,  1285,  1299,  1286,   813,
     884,   885,   964,  1040,  1041,  1042,  1179,  1043,  1180,  1044,
    1175,  1045,  1176,  1046,  1177,  1047,  1181,  1048,  1109,  1173,
    1174,  1215,  1251,  1252,  1253,  1288,  1254,  1289,  1255,  1290,
    1256,   343,   344,   405,   460,   544,   585,   734,   796,   797,
     841,   932,   933,   934,  1080,   935,   587,   670,   799,   845,
     846,   936,   997,   998,   999,  1140,  1000,  1141,  1001,   671,
     739,   740,   800,   855,   856,   857,  1010,   858,  1011,   859,
    1006,   860,  1007,   861,  1008,   862,  1012,   863,   937,  1004,
    1005,  1085,  1148,  1149,  1150,  1232,  1151,  1233,  1152,  1234,
    1153,   402,   403,   456,   541,   582,   664,   786,   836,   837,
     905,   976,   977,   978,  1124,   979,   666,   731,   839,   909,
     910,   980,  1063,  1064,  1065,  1185,  1066,  1186,  1067,   732,
     791,   792,   840,   919,   920,   921,  1076,   922,  1077,   923,
    1072,   924,  1073,   925,  1074,   926,  1078,   927,   981,  1070,
    1071,  1129,  1193,  1194,  1195,  1258,  1196,  1259,  1197,  1260,
    1198,   453,   454,   537,   661,   727,   784,   832,   897,   898,
    1052,   899,  1053,   900,  1049,   901,  1050,   902,  1051,   903,
    1054,   904
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -95
static const yytype_int16 yypact[] =
{
     168,    29,    15,    43,   178,   -95,   -95,    47,    25,   226,
     -95,    15,   -95,   -95,   -95,    42,   248,   -95,   -95,   -95,
      84,   -95,    44,   250,   -95,   -95,   -95,   225,   -95,   -95,
      46,   252,   -95,   -95,   -95,    65,   -95,   -95,   -95,   -95,
     -95,   -95,   -95,   -95,   -95,   -95,   -95,   -95,   -95,   -95,
     254,   -95,   269,   -95,   305,   -95,    87,   -95,   307,   -95,
     318,   -95,   320,   -95,   322,   -95,   324,   -95,    92,   -95,
      95,   -95,   -95,   -95,   -95,   -95,   -95,   -29,   -95,   -95,
     -95,   -95,   -95,   -95,   -95,   -95,    70,   -95,    72,   -95,
      76,   -95,   326,   -95,   105,    20,   -95,   -95,    17,   -95,
     -95,    14,   -95,   -95,   120,   328,    13,   -95,   -95,    16,
     -95,   -95,    12,   -95,   -95,    11,   -95,   -95,     7,   -95,
     -95,   128,   330,   131,   139,    23,     3,   -95,   -95,   -95,
     -95,   -95,   332,   -95,   135,   146,   334,   150,   336,   166,
     338,    -1,   -95,   -95,   167,   172,   -95,   -95,   -95,   -95,
     -95,   -95,   -95,   190,   -95,   -95,   -95,   -95,   -95,   -95,
     -95,   -95,   -95,   -95,   -95,   -95,   -95,   195,   -95,   -95,
     171,   -95,    74,   -95,   201,   212,   221,   -95,   -95,   -95,
     -95,   -95,   -95,   -95,   -95,   -95,   -95,   -95,   -95,   -95,
     -95,   -95,   -95,   -95,   -95,   -95,   -95,   -95,   -95,   -95,
     203,   -95,   340,   -95,   213,   -95,   231,   -95,   235,   -95,
     247,   -95,   255,   -95,   251,   -95,   272,   -95,   276,   -95,
     280,   -95,   271,   -95,   275,   -95,   217,   -95,   281,     1,
     -95,   -95,   233,   293,   -95,     4,   -95,   -95,   -95,     8,
     -95,   -95,   -95,     2,   -95,   -95,   -95,   -95,   298,   -95,
     323,   245,   321,   377,   -95,   244,   314,   316,   315,   317,
     312,   382,   -95,   319,   383,   -95,   270,   -95,   335,   249,
     361,   390,   391,   393,   396,   344,    -4,   -95,   -95,   394,
     392,   395,   397,   399,   400,   402,   403,   405,   406,   408,
     409,   411,   412,   414,   415,   417,   418,   420,   421,   423,
     424,   426,   427,   429,   430,   -95,   -95,   398,   -95,   432,
     329,   341,   -95,   433,   333,   342,   -95,   434,   343,   346,
     -95,   347,   435,   -95,   274,   -95,   -95,   -95,   -95,   -95,
     -95,   -95,   -95,   -95,   -95,   -95,   -95,   -95,   -95,   -95,
     -95,   -95,   -95,   253,   373,   436,   348,   437,   438,   439,
     -95,    -3,   -95,   -95,   -95,   -95,   442,   -95,   443,   -95,
     444,   -95,   445,   -95,   446,   -95,   447,   -95,   448,   -95,
     449,   -95,   450,   -95,   451,   -95,   452,   -95,   453,   -95,
     454,   -95,   368,   455,   -95,   278,   -95,   -95,   -95,   -95,
     -95,   -95,   -95,   -95,   -95,   -95,   -95,   -95,   -95,   -95,
     -95,   -95,   257,   387,   456,   352,   459,   337,   -95,   -95,
     -95,   -95,   -95,   458,   367,   374,   -95,   371,   462,   -27,
     463,    30,   464,   260,   465,   -61,   466,    26,   467,   -67,
     468,   -66,   469,   -72,   470,   -71,   471,   -57,   472,    22,
     473,   240,   474,   -95,   286,   -95,   -95,   -95,   -95,   -95,
     -95,   154,   -95,   -95,   457,   475,   360,   478,   265,   -95,
     -95,   477,   460,   353,   -95,   -95,   -95,   -95,   -95,   479,
     -95,   -95,   -95,   -95,   480,   -95,   -95,   -95,   481,   -95,
     -95,   482,   -95,   -95,   -95,   483,   -95,   -95,   -95,   -95,
     -95,   -95,   -95,   -95,   -95,   -95,   -95,   -95,   -95,   -95,
     -95,   -95,   -95,   -95,   -95,   -95,   -95,   -95,   -95,   484,
     -95,   -95,   -95,   485,   -95,   -95,   -95,   -95,   486,   -95,
     -95,   -95,   -95,   -95,   -95,   176,   413,   -95,   494,   495,
     496,   -95,   -95,   -95,   -95,   -95,   493,   497,   498,   349,
     -95,   -95,   499,   476,   355,   -95,   500,   501,   487,   366,
     504,   506,   507,   508,   510,   259,   297,   300,   303,   511,
     512,   513,   -95,   183,   440,   -95,   515,   516,   517,   -95,
     -95,   -95,   -95,   -95,   -95,   -95,   -95,   -95,   519,   -95,
     514,   488,   370,   -95,   518,   520,   492,   -95,   525,   -95,
     524,   526,   502,   404,   -95,   -95,   -95,   -95,   -95,   431,
     -95,   529,   530,   532,   -95,   -95,   -95,   -95,   -95,   441,
     -95,   533,   536,   537,   -95,   -95,   -95,   -95,   -95,   461,
     -95,   539,   540,   541,   -95,   -95,   -95,   -95,   -95,   489,
     -95,   542,   543,   545,   -95,   -95,   -95,   -95,   -95,   -95,
     -95,   -95,   197,   490,   -95,   546,   547,   548,   -95,   -95,
     -95,   -95,   -95,   -95,   -95,   -95,   -95,   549,   550,   551,
     552,   210,   -95,   553,   544,   523,   -95,   557,   -95,   556,
     558,   -69,   561,   242,   559,   -95,   562,   563,   534,   416,
     505,   503,   509,   521,   522,   -95,   -95,   -95,   -95,   -95,
     -95,   -95,   -95,   -95,   -95,   -95,   -95,   -95,   -95,   -95,
     -95,   527,   528,   428,   535,   -95,   571,   572,   573,   -95,
     -95,   -95,   -95,   -95,   -95,   -95,   -95,   -95,   570,   574,
     575,   -95,   -95,   -95,   -95,   -95,   -95,   -95,   560,   -95,
     576,   577,   -75,   579,   228,   582,   -95,   -95,   -95,   -95,
     -95,   -95,   -95,   -95,   -95,   -95,   581,    37,   584,   -95,
     583,   585,   555,   -95,   -95,   -95,   -95,   -95,   -95,   587,
     589,   590,   591,   592,   593,   594,   595,   596,   597,   598,
     599,   -95,   -95,   -95,   -95,   -95,   -95,   -95,   601,   602,
     603,   -95,   -95,   -95,   -95,   604,   222,   586,   -95,   -95,
     -95,   -95,   -95,   -95,   -95,   -95,   -95,   -95,   605,   -15,
     133,    21,   -95,   -95,   -95,   -95,   -95,   607,    24,   610,
     -95,   609,   611,   -58,   -95,   -95,   -95,   -95,   -95,   -95,
     -95,   -95,   -95,   -95,   -95,   -95,   613,   614,   615,   -95,
     -95,   -95,   158,   -95,   -95,   -95,   -95,   -95,   616,    66,
     165,   205,   -95,   -95,   -95,   -95,   -95,   -95,   621,   624,
     625,   622,   627,   630,   631,   -95,   -95,   -95,   -95,   -95,
     -95,   -95,   -95,   -95,   531,   -95,   628,   633,   -95,   -95,
     -95,   -95,   208,   -95,   -95,   -95,   -95,   -95,   632,   -94,
     635,   -95,   -95,   -95,   -95,   -95,   -95,   -95,   -95,   491,
     -95,   634,   638,   639,   640,   641,   642,   -95,   -95,   -95,
     -95,   -95,   -95,   -95,   -95,   224,   -95,   -95,   -95,   -95,
     -95,   -95,   643,   644,   645,   647,   646,   648,   649,   -95,
     -95,   -95,   -95,   -95,   -95,   -95,   -95,   -95,   538,   -95,
     650,   652,   -95,   -95,   -95,   -95,   100,   -60,   -95,   -95,
     -95,   651,   -95,   -95,   -95,   -95,   653,   -95,   564,   -95,
     654,   656,   -95,   -95,   -95,   -95,   229,   -95,   -95,   -95,
     -95,   -95,   655,   238,   187,   -95,   -95,   -95,   -95,   -95,
     -95,   -95,   422,   -95,   657,   662,   -95,   -95,   -95,   -95,
      18,   -81,   -95,   -95,   -95,   661,   -95,   -95,   -95,   -95,
     663,   -95,   554,   -95,   660,   666,   667,   -95,   -95,   -95,
     -95,   -95,   -95,   -95,   -95,   -95,   664,   665,   668,   669,
     670,   671,   672,   673,   674,   -95,   677,   -95,   565,   -95,
     676,   681,   -95,   -95,   -95,   -95,   234,   -95,   -95,   -95,
     -95,   -95,   -95,   682,   684,   685,   683,   686,   688,   689,
     -95,   -95,   -95,   -95,   -95,   -95,   -95,   -95,   -95,   687,
     691,   692,   693,   694,   696,   -95,   690,   -95,   566,   -95,
     697,   702,   703,   -95,   -95,   -95,   -95,   -95,   -95,   -95,
     -95,   -95,   700,   701,   704,   705,   706,   707,   708,   709,
     710,   -95,   713,   -95,   -95,    27,   -95,   -95,   -95,   -95,
     -95,   -95,   -95,   -95,   -95,   712,   714,   -95,   715,   -95,
     578,   -95,   716,   721,   -95,   -95,   -95,   -95,   246,   -63,
     -95,   -95,   -95,   720,   -95,   -95,   -95,   -95,   -95,   -95,
     -95,   -95,   -95,   719,   722,   -95,   723,   -95,   -95,    97,
     -95,   -95,   -95,   -95,   -95,   -95,   -95,   -95,   -95,   724,
     725,   726,   606,   -95,   727,   732,   733,   734,   -95,   -95,
     -95,   -95,   -95,   -95,   -95,   -95,   735,   736,   -95,   739,
     -95,   -95,   -95,   738,   740,   741,   -95,   -95,   -95,   -95,
     -95,   -95,   -95,   -95,   -95,   742,   743,   744,   745,   746,
     747,   748,   -95,   -95,   749,   750,   751,   608,   -95,   752,
     737,   757,   758,   -95,   -95,   -95,   -95,   -95,   -95,   -95,
     -95,   -95,   -95,   760,   -95,   -95,   -95,   -95,   -95,   755,
     756,   -86,   375,   761,   762,   119,   -95,   -95,   -95,   -95,
     -95,   -95,   -95,   -95,   -95,   -95,   -95,   763,   -95,   -95,
     -95,   764,   765,   766,   767,   -95,   -95,   -95,   -95,   -95,
     -95,   768,   769,   770,   771,   637,   -95,   772,   777,   778,
     779,   -95,   -95,   -95,   -95,   -95,   -95,   776,   780,   781,
     782,   -95,   -95,   -95,   -95,   243,   -95,   -95,   -95,   -95,
     -95,   785,   -95,   -95,   -95,   -95,   -95,   -95,   -95,   659,
     -95,   786,   783,   -95,   -95,   -95,   -95,   787,   788,   789,
     790,   -95,   793,   -95,   -95,   -95,   -95,   -95,   792,   794,
     -95,   -95
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -95,   -95,   -95,   568,   -95,   -95,   -95,   -95,   -95,   -95,
     -95,   -95,   -95,   -95,   -95,   -95,   -95,   -95,   -95,   -95,
     -95,   -95,   -95,   -95,   -95,   -95,   -95,   -95,   -95,   -95,
     -95,   -95,   -95,   -95,   -95,   -95,   -95,   -95,   -95,   -95,
     -95,   -95,   -95,   -95,   -95,   -95,   -95,   -95,   -95,   -95,
     -95,   -95,   -95,   -95,   -95,   -95,   -95,   -95,   -95,   -95,
     -95,   -95,   -95,   -95,   -95,   -95,   -95,   -95,   -95,   -95,
     -95,   -95,   -95,   -95,   -95,   -95,   -95,   -95,   -95,   -95,
     -95,   -95,   -95,   -95,   -95,   -95,   -95,   -95,   -95,   -95,
     -95,   -95,   -95,   -95,   -95,   -95,   -95,   -95,   -95,   -95,
     -95,   -95,   -95,   -95,   -95,   -95,   -95,   -95,   -95,   -95,
     -95,   -95,   -95,   -95,   -95,   -95,   -95,   -95,   -95,   -95,
     -95,   -95,   -95,   -95,   -95,   -95,   -95,   -95,   -95,   -95,
     -95,   -95,   -95,   -95,   -95,   -95,   -95,   -95,   -95,   -95,
     -95,   -95,   -95,   -95,   -95,   -95,   -95,   -95,   -95,   -95,
     -95,   -95,   -95,   -95,   -95,   -95,   -95,   -95,   -95,   -95,
     -95,   -95,   -95,   -95,   -95,   -95,   -95,   -95,   -95,   -95,
     -95,   -95,   -95,   -95,   -95,   -95,   -95,   -95,   -95,   -95,
     -95,   -95,   -95,   -95,   -95,   -95,   -95,   -95,   -95,   -95,
     -95,   -95,   -95,   -95,   -95,   -95,   -95,   -95,   -95,   -95,
     -95,   -95,   -95,   -95,   -95,   -95,   -95,   -95,   -95,   -95,
     -95,   -95,   -95,   -95,   -95,   -95,   -95,   -95,   -95,   -95,
     -95,   -95,   -95,   -95,   -95,   -95,   -95,   -95,   -95,   -95,
     -95,   -95,   -95,   -95,   -95,   -95,   -95,   -95,   -95,   -95,
     -95,   -95,   -95,   -95,   -95,   -95,   -95,   -95,   -95,   -95,
     -95,   -95,   -95,   -95,   -95,   -95,   -95,   -95,   -95,   -95,
     -95,   -95,   -95,   -95,   -95,   -95,   -95,   -95,   -95,   -95,
     -95,   -95,   -95,   -95,   -95,   -95,   -95,   -95,   -95,   -95,
     -95,   -95,   -95,   -95,   -95,   -95,   -95,   -95,   -95,   -95,
     -95,   -95,   -95,   -95,   -95,   -95,   -95,   -95,   -95,   -95,
     -95,   -95,   -95,   -95,   -95,   -95,   -95,   -95,   -95,   -95,
     -95,   -95,   -95,   -95,   -95,   -95,   -95,   -95,   -95,   -95,
     -95,   -95,   -95,   -95,   -95,   -95,   -95,   -95,   -95,   -95,
     -95,   -95,   -95,   -95,   -95,   -95,   -95,   -95,   -95,   -95,
     -95,   -95,   -95,   -95,   -95,   -95,   -95,   -95,   -95,   -95,
     -95,   -95,   -95,   -95,   -95,   -95,   -95,   -95,   -95,   -95,
     -95,   -95,   -95,   -95,   -95,   -95,   -95,   -95,   -95,   -95,
     -95,   -95,   -95,   -95,   -95,   -95,   -95,   -95,   -95,   -95,
     -95,   -95,   -95,   -95,   -95,   -95,   -95,   -95,   -95,   -95,
     -95,   -95,   -95,   -95,   -95,   -95,   -95,   -95,   -95,   -95,
     -95,   -95,   -95,   -95,   -95,   -95,   -95,   -95,   -95,   -95,
     -95,   -95,   -95,   -95,   -95,   -95,   -95,   -95,   -95,   -95,
     -95,   -95,   -95,   -95,   -95,   -95,   -95,   -95,   -95,   -95,
     -95,   -95,   -95,   -95,   -95,   -95,   -95,   -95,   -95,   -95,
     -95,   -95,   -95,   -95,   -95,   -95,   -95,   -95,   -95,   -95,
     -95,   -95,   -95,   -95,   -95,   -95,   -95,   -95,   -95,   -95,
     -95,   -95,   -95,   -95,   -95,   -95,   -95,   -95,   -95,   -95,
     -95,   -95,   -95,   -95,   -95,   -95,   -95,   -95,   -95,   -95,
     -95,   -95,   -95,   -95,   -95,   -95,   -95,   -95,   -95,   -95,
     -95,   -95,   -95,   -95,   -95,   -95,   -95,   -95,   -95,   -95,
     -95,   -95,   -95,   -95,   -95,   -95,   -95,   -95,   -95,   -95,
     -95,   -95,   -95,   -95,   -95,   -95,   -95,   -95,   -95,   -95,
     -95,   -95
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -8
static const yytype_int16 yytable[] =
{
     354,  1068,   414,   415,   246,   305,   789,   318,   319,   310,
     311,   164,   737,   314,   315,   162,   160,   156,   150,  1171,
     158,   148,  1002,   882,   146,   127,  1058,  1059,    -7,   864,
     865,   172,   173,   499,   504,  1142,  1143,   958,   489,   494,
     469,     5,   481,    10,   959,  1237,   509,   482,   500,   490,
     128,   505,   495,   174,   175,   176,  1238,   510,  1060,   182,
      13,   866,   129,   867,     6,  1061,  1062,  1144,  1172,  1145,
     883,   470,  1146,  1147,  1069,   738,    14,   790,   151,   149,
     147,   157,   183,   165,   161,   163,   159,  1003,   312,   247,
     320,   416,   355,   306,   316,    21,   184,    28,   185,    29,
     186,   104,   187,    71,   188,  1187,  1188,   121,   992,   993,
     189,   123,   190,   135,   191,   137,   192,    78,   193,   139,
     194,   144,   195,   152,   196,   513,   197,  1245,  1246,   485,
     473,   166,   843,   474,   514,   844,   486,  1189,   170,  1190,
     994,   847,  1191,  1192,    79,   995,   996,   171,    80,   234,
      81,   232,    82,   238,    83,   874,   848,   849,   850,  1247,
     875,  1248,   526,   527,  1249,  1250,   889,   890,   803,   242,
     851,   804,   852,   911,   248,   853,   264,   854,     1,     2,
     249,   891,   892,   893,   564,   565,    11,    12,   912,   913,
     914,   643,   644,   528,   254,  1032,   529,   894,   530,   262,
     895,   267,   896,   915,   916,   704,   705,   917,   271,   918,
    1033,  1034,  1035,   928,   929,   566,   948,   949,   567,   272,
     568,   907,   645,  1036,   908,   646,  1037,   647,   273,  1038,
     279,  1039,   972,   973,    17,    18,   706,  1018,  1019,   707,
     307,   708,  1100,  1101,   301,   930,   274,   931,   950,   281,
     951,  1279,  1280,   283,  1161,  1162,    24,    25,    32,    33,
      74,    75,    95,    96,   974,   285,   975,   599,   600,  1020,
     289,  1021,  1163,   287,  1102,    36,  1103,    98,    99,   601,
     602,   603,  1164,  1281,    37,  1282,    38,  1165,    39,   297,
      40,   291,    41,   299,    42,   293,    43,   303,    44,   295,
      45,   308,    46,   322,    47,   609,   610,   326,   619,   620,
     329,   629,   630,   101,   102,   106,   107,   611,   612,   613,
     621,   622,   623,   631,   632,   633,   109,   110,   112,   113,
     115,   116,   118,   119,   141,   142,   153,   154,   167,   168,
     229,   230,   235,   236,   239,   240,   243,   244,   276,   277,
     338,   339,   351,   352,   397,   398,   407,   408,   447,   448,
     458,   459,   477,   478,   517,   518,   521,   522,   539,   540,
     725,   726,   742,   743,   794,   795,   834,   835,  1028,  1029,
    1241,  1242,   330,   325,   328,   327,   331,   332,   334,   335,
     337,   333,   342,   341,   345,   347,   348,   336,   349,   350,
     357,   356,   358,   383,   401,   359,   360,   404,   361,   362,
     543,   363,   364,   387,   365,   366,   452,   367,   368,   390,
     369,   370,   455,   371,   372,   388,   373,   374,   391,   375,
     376,   393,   377,   378,   394,   379,   380,   395,   381,   386,
     389,   392,   396,   406,   410,   411,   412,   418,   420,   422,
     424,   426,   428,   430,   432,   434,   436,   438,   440,   442,
     445,   465,   446,   457,   461,   464,   462,   467,   466,   468,
     472,   476,   480,   484,   488,   493,   498,   503,   508,   512,
     516,   520,   538,   542,   545,   536,   548,   550,   551,   552,
     553,   554,   559,   560,   561,   574,   546,   575,   576,   577,
     578,   592,   581,   580,   586,   579,   583,   588,   594,   589,
     595,   596,   597,   584,   598,   639,   640,   641,   654,   655,
     656,   662,   653,   590,   660,   667,   663,   665,   668,   669,
     672,   674,   686,   687,   675,   688,   690,   685,   676,   691,
     692,   678,   694,   695,   696,   698,   699,   689,   700,   715,
     716,   717,   729,     0,   773,   752,   721,   722,   723,   724,
     728,   730,   733,   735,   746,   785,   736,   693,   741,   748,
     750,   749,   714,   754,   775,   776,   777,   781,  1055,    20,
       0,   782,   783,   787,   811,   788,   793,   798,   802,   807,
     809,   838,     0,   810,   814,   697,   815,   816,   817,   818,
     819,   820,   821,   822,   823,   824,   825,   755,   829,   830,
     831,   833,   842,   756,   873,   878,   880,   774,     0,   881,
     886,   887,   888,   906,   938,   757,   758,   939,   940,   941,
     942,   771,   772,   943,   944,   946,   947,   966,     0,   957,
     962,   967,   968,   969,   970,   971,   982,   983,   984,   986,
       0,   987,   988,   965,   985,   991,  1009,   990,  1013,  1017,
       0,  1016,  1027,   945,  1056,  1057,  1075,  1082,  1079,  1083,
    1084,  1086,  1087,     0,     0,  1088,  1089,  1090,  1091,  1092,
    1093,  1094,  1095,  1098,  1099,  1110,   989,  1111,  1112,  1114,
    1113,  1115,  1116,     0,  1117,  1123,  1015,  1097,  1118,  1119,
    1120,  1121,  1081,  1122,  1126,  1127,  1128,  1130,  1131,     0,
    1158,  1132,  1133,  1134,  1135,  1136,  1137,  1138,  1139,  1154,
    1156,  1155,  1125,  1159,  1160,  1178,  1182,     0,  1184,  1183,
       0,  1199,  1200,  1201,  1203,  1204,  1205,  1206,  1202,     0,
    1228,     0,  1207,  1208,  1209,  1212,     0,  1213,  1214,  1216,
    1217,  1218,  1219,  1220,  1221,  1222,  1223,  1224,  1225,  1227,
    1229,  1230,  1235,  1236,  1226,  1231,  1243,  1244,  1257,  1270,
       0,  1261,  1262,  1263,  1264,  1266,  1267,  1268,  1269,  1271,
    1272,  1273,  1274,  1275,     0,     0,  1293,  1276,  1277,  1278,
    1287,  1291,     0,  1292,  1294,  1295,  1296,  1297,  1298,  1300,
       0,  1301
};

static const yytype_int16 yycheck[] =
{
       4,    82,     5,     6,     5,     4,    81,     5,     6,     5,
       6,     4,    81,     5,     6,     4,     4,     4,     4,    82,
       4,     4,    82,    81,     4,    54,     8,     9,    13,     8,
       9,     8,     9,   105,   105,     8,     9,   131,   105,   105,
      67,    12,   103,     0,   138,   131,   103,   108,   120,   116,
      79,   122,   118,    30,    31,    32,   142,   114,    40,    56,
      13,    40,    91,    42,    49,    47,    48,    40,   131,    42,
     128,    98,    45,    46,   155,   144,    51,   152,    64,    62,
      60,    68,    79,    76,    72,    74,    70,   147,    84,    90,
      88,    94,    96,    92,    86,    53,    93,    13,    95,    55,
      97,    14,    99,    57,   101,     8,     9,    15,     8,     9,
     107,    16,   109,    43,   111,    43,   113,    52,   115,    43,
     117,    16,   119,     3,   121,   103,   123,     8,     9,   103,
     100,     3,   147,   103,   112,   150,   110,    40,     7,    42,
      40,     8,    45,    46,    79,    45,    46,     8,    83,     3,
      85,    16,    87,     3,    89,   131,    23,    24,    25,    40,
     136,    42,     8,     9,    45,    46,     8,     9,   131,     3,
      37,   134,    39,     8,     7,    42,     5,    44,    10,    11,
       8,    23,    24,    25,     8,     9,     8,     9,    23,    24,
      25,     8,     9,    39,     4,     8,    42,    39,    44,     4,
      42,   127,    44,    38,    39,     8,     9,    42,     7,    44,
      23,    24,    25,     8,     9,    39,     8,     9,    42,     7,
      44,   155,    39,    36,   158,    42,    39,    44,     7,    42,
      17,    44,     8,     9,     8,     9,    39,     8,     9,    42,
       7,    44,     8,     9,    27,    40,    43,    42,    40,    18,
      42,     8,     9,    18,     8,     9,     8,     9,     8,     9,
       8,     9,     8,     9,    40,    18,    42,     8,     9,    40,
      19,    42,    26,    18,    40,    50,    42,     8,     9,    20,
      21,    22,    36,    40,    59,    42,    61,    41,    63,    18,
      65,    19,    67,    18,    69,    19,    71,    16,    73,    19,
      75,     8,    77,     5,    79,     8,     9,    62,     8,     9,
      66,     8,     9,     8,     9,     8,     9,    20,    21,    22,
      20,    21,    22,    20,    21,    22,     8,     9,     8,     9,
       8,     9,     8,     9,     8,     9,     8,     9,     8,     9,
       8,     9,     8,     9,     8,     9,     8,     9,     8,     9,
      80,    81,     8,     9,    80,    81,     8,     9,    80,    81,
       8,     9,   102,   103,   124,   125,    80,    81,     8,     9,
     160,   161,   130,   131,   146,   147,   154,   155,   140,   141,
       5,     6,    68,    60,     7,    64,    70,    72,    76,     7,
       7,    74,   143,    58,    33,     5,     5,    78,     5,     3,
       8,     7,     7,     5,   151,     8,     7,    34,     8,     7,
     145,     8,     7,    84,     8,     7,   159,     8,     7,    86,
       8,     7,    35,     8,     7,    84,     8,     7,    86,     8,
       7,    88,     8,     7,    88,     8,     7,    90,     8,     7,
       7,     7,     7,     7,     7,     7,     7,     5,     5,     5,
       5,     5,     5,     5,     5,     5,     5,     5,     5,     5,
      92,    94,     7,     7,     5,     7,   129,    96,    94,     7,
       7,     7,     7,     7,     7,     7,     7,     7,     7,     7,
       7,     7,     7,     5,     7,    28,   133,     8,     8,     8,
       8,     8,     8,     8,     8,    82,    36,     3,     3,     3,
       7,   135,   153,     5,   149,     8,     7,     7,     4,     8,
       4,     4,     4,    37,     4,     4,     4,     4,     3,     3,
       3,     7,    82,    36,     5,     7,    38,   157,     8,    37,
       5,     7,     3,     3,     8,     3,     3,   106,    36,     3,
       3,   137,     3,     3,     3,     3,     3,   106,     3,     3,
       3,     3,     8,    -1,   126,   139,     7,     7,     7,     7,
       7,    38,     5,     7,     5,     5,     8,   106,     7,     7,
      36,     8,    82,    68,     3,     3,     3,     7,   156,    11,
      -1,     7,     7,     7,    29,     8,     7,     5,     7,     5,
       7,     5,    -1,     8,     7,   106,     7,     7,     7,     7,
       7,     7,     7,     7,     7,     7,     7,   104,     7,     7,
       7,     7,     7,   104,     7,     5,     7,    82,    -1,     8,
       7,     7,     7,     7,     3,   104,   104,     3,     3,     7,
       3,   104,   104,     3,     3,     7,     3,     3,    -1,     7,
       5,     3,     3,     3,     3,     3,     3,     3,     3,     3,
      -1,     3,     3,   162,     7,     3,     5,     7,     5,     3,
      -1,     7,     7,   132,     7,     3,     5,     7,     5,     3,
       3,     7,     7,    -1,    -1,     7,     7,     7,     7,     7,
       7,     7,     5,     7,     3,     3,   148,     3,     3,     3,
       7,     3,     3,    -1,     7,     5,   132,   132,     7,     7,
       7,     7,   148,     7,     7,     3,     3,     7,     7,    -1,
     132,     7,     7,     7,     7,     7,     7,     7,     5,     7,
       5,     7,   156,     7,     3,     5,     7,    -1,     5,     7,
      -1,     7,     7,     7,     7,     3,     3,     3,   132,    -1,
       3,    -1,     7,     7,     5,     7,    -1,     7,     7,     7,
       7,     7,     7,     7,     7,     7,     7,     7,     7,     7,
       3,     3,     7,     7,   156,     5,     5,     5,     5,   132,
      -1,     7,     7,     7,     7,     7,     7,     7,     7,     7,
       3,     3,     3,     7,    -1,    -1,     3,     7,     7,     7,
       5,   132,    -1,     7,     7,     7,     7,     7,     5,     7,
      -1,     7
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,    10,    11,   165,   166,    12,    49,   167,   168,   169,
       0,     8,     9,    13,    51,   233,   234,     8,     9,   170,
     167,    53,   273,   274,     8,     9,   235,   171,    13,    55,
     298,   299,     8,     9,   275,   236,    50,    59,    61,    63,
      65,    67,    69,    71,    73,    75,    77,    79,   172,   173,
     174,   177,   178,   181,   182,   185,   186,   191,   192,   195,
     196,   199,   200,   203,   204,   207,   208,   211,   212,   217,
     218,    57,   436,   437,     8,     9,   300,   276,    52,    79,
      83,    85,    87,    89,   237,   238,   239,   243,   244,   248,
     249,   253,   254,   257,   258,     8,     9,   175,     8,     9,
     179,     8,     9,   183,    14,   187,     8,     9,   193,     8,
       9,   197,     8,     9,   201,     8,     9,   205,     8,     9,
     209,    15,   213,    16,   219,   438,   301,    54,    79,    91,
     277,   278,   279,   282,   283,    43,   240,    43,   245,    43,
     250,     8,     9,   255,    16,   259,     4,    60,     4,    62,
       4,    64,     3,     8,     9,   189,     4,    68,     4,    70,
       4,    72,     4,    74,     4,    76,     3,     8,     9,   215,
       7,     8,     8,     9,    30,    31,    32,   439,   440,   441,
     442,   443,    56,    79,    93,    95,    97,    99,   101,   107,
     109,   111,   113,   115,   117,   119,   121,   123,   302,   303,
     304,   308,   309,   312,   313,   318,   319,   324,   325,   330,
     331,   336,   337,   342,   343,   357,   358,   372,   373,   387,
     388,   402,   403,   408,   409,   414,   415,   420,   421,     8,
       9,   280,    16,   284,     3,     8,     9,   242,     3,     8,
       9,   247,     3,     8,     9,   252,     5,    90,     7,     8,
     176,   180,   184,   188,     4,   190,   194,   198,   202,   206,
     210,   214,     4,   216,     5,   220,   221,   127,   444,   445,
     446,     7,     7,     7,    43,   305,     8,     9,   310,    17,
     314,    18,   320,    18,   326,    18,   332,    18,   338,    19,
     344,    19,   359,    19,   374,    19,   389,    18,   404,    18,
     410,    27,   416,    16,   422,     4,    92,     7,     8,   241,
       5,     6,    84,   246,     5,     6,    86,   251,     5,     6,
      88,   256,     5,   260,   261,    60,    62,    64,     7,    66,
      68,    70,    72,    74,    76,     7,    78,     7,    80,    81,
     222,    58,   143,   545,   546,    33,   447,     5,     5,     5,
       3,     8,     9,   307,     4,    96,     7,     8,     7,     8,
       7,     8,     7,     8,     7,     8,     7,     8,     7,     8,
       7,     8,     7,     8,     7,     8,     7,     8,     7,     8,
       7,     8,   281,     5,   285,   286,     7,    84,    84,     7,
      86,    86,     7,    88,    88,    90,     7,    80,    81,   262,
     223,   151,   605,   606,    34,   547,     7,     8,     9,   448,
       7,     7,     7,   306,     5,     6,    94,   311,     5,   315,
       5,   321,     5,   327,     5,   333,     5,   339,     5,   345,
       5,   360,     5,   375,     5,   390,     5,   405,     5,   411,
       5,   417,     5,   423,   424,    92,     7,    80,    81,   287,
     263,   224,   159,   665,   666,    35,   607,     7,     8,     9,
     548,     5,   129,   449,     7,    94,    94,    96,     7,    67,
      98,   316,     7,   100,   103,   322,     7,   102,   103,   328,
       7,   103,   108,   334,     7,   103,   110,   340,     7,   105,
     116,   346,   347,     7,   105,   118,   361,   362,     7,   105,
     120,   376,   377,     7,   105,   122,   391,   392,     7,   103,
     114,   406,     7,   103,   112,   412,     7,   124,   125,   418,
       7,    80,    81,   425,   288,   264,     8,     9,    39,    42,
      44,   225,   226,   228,   230,   232,    28,   667,     7,     8,
       9,   608,     5,   145,   549,     7,    36,   450,   133,   460,
       8,     8,     8,     8,     8,   348,   363,   378,   393,     8,
       8,     8,   426,   289,     8,     9,    39,    42,    44,   265,
     266,   268,   270,   272,    82,     3,     3,     3,     7,     8,
       5,   153,   609,     7,    37,   550,   149,   560,     7,     8,
      36,   461,   135,   471,     4,     4,     4,     4,     4,     8,
       9,    20,    21,    22,   349,   350,   352,   354,   356,     8,
       9,    20,    21,    22,   364,   365,   367,   369,   371,     8,
       9,    20,    21,    22,   379,   380,   382,   384,   386,     8,
       9,    20,    21,    22,   394,   395,   397,   399,   401,     4,
       4,     4,   427,     8,     9,    39,    42,    44,   290,   291,
     293,   295,   297,    82,     3,     3,     3,   227,   229,   231,
       5,   668,     7,    38,   610,   157,   620,     7,     8,    37,
     561,   573,     5,   451,     7,     8,    36,   472,   137,   482,
     317,   323,   329,   335,   341,   106,     3,     3,     3,   106,
       3,     3,     3,   106,     3,     3,     3,   106,     3,     3,
       3,   407,   413,   419,     8,     9,    39,    42,    44,   428,
     429,   431,   433,   435,    82,     3,     3,     3,   267,   269,
     271,     7,     7,     7,     7,   160,   161,   669,     7,     8,
      38,   621,   633,     5,   551,     7,     8,    81,   144,   574,
     575,     7,   130,   131,   452,   453,     5,   462,     7,     8,
      36,   483,   139,   493,    68,   104,   104,   104,   104,   351,
     353,   355,   366,   368,   370,   381,   383,   385,   396,   398,
     400,   104,   104,   126,    82,     3,     3,     3,   292,   294,
     296,     7,     7,     7,   670,     5,   611,     7,     8,    81,
     152,   634,   635,     7,   146,   147,   552,   553,     5,   562,
     576,   454,     7,   131,   134,   463,   464,     5,   473,     7,
       8,    29,   494,   513,     7,     7,     7,     7,     7,     7,
       7,     7,     7,     7,     7,     7,   430,   432,   434,     7,
       7,     7,   671,     7,   154,   155,   612,   613,     5,   622,
     636,   554,     7,   147,   150,   563,   564,     8,    23,    24,
      25,    37,    39,    42,    44,   577,   578,   579,   581,   583,
     585,   587,   589,   591,     8,     9,    40,    42,   455,   456,
     457,   459,   465,     7,   131,   136,   474,   475,     5,   484,
       7,     8,    81,   128,   514,   515,     7,     7,     7,     8,
       9,    23,    24,    25,    39,    42,    44,   672,   673,   675,
     677,   679,   681,   683,   685,   614,     7,   155,   158,   623,
     624,     8,    23,    24,    25,    38,    39,    42,    44,   637,
     638,   639,   641,   643,   645,   647,   649,   651,     8,     9,
      40,    42,   555,   556,   557,   559,   565,   592,     3,     3,
       3,     7,     3,     3,     3,   132,     7,     3,     8,     9,
      40,    42,   466,   467,   468,   470,   476,     7,   131,   138,
     485,   486,     5,   495,   516,   162,     3,     3,     3,     3,
       3,     3,     8,     9,    40,    42,   615,   616,   617,   619,
     625,   652,     3,     3,     3,     7,     3,     3,     3,   148,
       7,     3,     8,     9,    40,    45,    46,   566,   567,   568,
     570,   572,    82,   147,   593,   594,   584,   586,   588,     5,
     580,   582,   590,     5,   458,   132,     7,     3,     8,     9,
      40,    42,   477,   478,   479,   481,   487,     7,   140,   141,
     496,   497,     8,    23,    24,    25,    36,    39,    42,    44,
     517,   518,   519,   521,   523,   525,   527,   529,   531,   678,
     680,   682,   674,   676,   684,   156,     7,     3,     8,     9,
      40,    47,    48,   626,   627,   628,   630,   632,    82,   155,
     653,   654,   644,   646,   648,     5,   640,   642,   650,     5,
     558,   148,     7,     3,     3,   595,     7,     7,     7,     7,
       7,     7,     7,     7,     7,     5,   469,   132,     7,     3,
       8,     9,    40,    42,   488,   489,   490,   492,   498,   532,
       3,     3,     3,     7,     3,     3,     3,     7,     7,     7,
       7,     7,     7,     5,   618,   156,     7,     3,     3,   655,
       7,     7,     7,     7,     7,     7,     7,     7,     7,     5,
     569,   571,     8,     9,    40,    42,    45,    46,   596,   597,
     598,   600,   602,   604,     7,     7,     5,   480,   132,     7,
       3,     8,     9,    26,    36,    41,   499,   500,   501,   502,
     503,    82,   131,   533,   534,   524,   526,   528,     5,   520,
     522,   530,     7,     7,     5,   629,   631,     8,     9,    40,
      42,    45,    46,   656,   657,   658,   660,   662,   664,     7,
       7,     7,   132,     7,     3,     3,     3,     7,     7,     5,
     491,   504,     7,     7,     7,   535,     7,     7,     7,     7,
       7,     7,     7,     7,     7,     7,   156,     7,     3,     3,
       3,     5,   599,   601,   603,     7,     7,   131,   142,   505,
     506,     5,     6,     5,     5,     8,     9,    40,    42,    45,
      46,   536,   537,   538,   540,   542,   544,     5,   659,   661,
     663,     7,     7,     7,     7,   507,     7,     7,     7,     7,
     132,     7,     3,     3,     3,     7,     7,     7,     7,     8,
       9,    40,    42,   508,   509,   510,   512,     5,   539,   541,
     543,   132,     7,     3,     7,     7,     7,     7,     5,   511,
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
        case 11:

    {	if (parserData->osolgeneralPresent)
	{	osolerror( NULL, osoption, parserData, "only one <general> element allowed");
	}
	else
	{	parserData->osolgeneralPresent = true;
		osoption->general = new GeneralOption();
	}
}
    break;

  case 28:

    {	if (parserData->serviceURIPresent)
	{	osolerror( NULL, osoption, parserData, "only one <serviceURI> element allowed");
	}
	else
	{	parserData->serviceURIPresent = true;
	}
}
    break;

  case 31:

    {osoption->general->serviceURI = (yyvsp[(2) - (2)].sval);}
    break;

  case 34:

    {	if (parserData->serviceNamePresent)
	{	osolerror( NULL, osoption, parserData, "only one <serviceName> element allowed");
	}
	else
	{	parserData->serviceNamePresent = true;
	}
}
    break;

  case 37:

    {osoption->general->serviceName = (yyvsp[(2) - (2)].sval);}
    break;

  case 40:

    {	if (parserData->instanceNamePresent)
	{	osolerror( NULL, osoption, parserData, "only one <instanceName> element allowed");
	}
	else
	{	parserData->instanceNamePresent = true;
	}
}
    break;

  case 43:

    {osoption->general->instanceName = (yyvsp[(2) - (2)].sval);}
    break;

  case 46:

    {	if (parserData->instanceLocationPresent)
	{	osolerror( NULL, osoption, parserData, "only one <instanceLocation> element allowed");
	}
	else
	{	parserData->instanceLocationPresent = true;
		osoption->general->instanceLocation = new InstanceLocationOption();
		osoption->general->instanceLocation->locationType = "local";
	}
}
    break;

  case 48:

    {	if ( (strcmp((yyvsp[(2) - (2)].sval), "local") == 0) || (strcmp((yyvsp[(2) - (2)].sval), "http") == 0) || (strcmp((yyvsp[(2) - (2)].sval), "ftp") == 0) )
		osoption->general->instanceLocation->locationType = (yyvsp[(2) - (2)].sval);
	else
		osolerror( NULL, osoption, parserData, "Not a valid locationType");
}
    break;

  case 53:

    {osoption->general->instanceLocation->value = (yyvsp[(1) - (1)].sval);}
    break;

  case 55:

    {	if (parserData->jobIDPresent)
	{	osolerror( NULL, osoption, parserData, "only one <jobID> element allowed");
	}
	else
	{	parserData->jobIDPresent = true;
	}
}
    break;

  case 58:

    {osoption->general->jobID = (yyvsp[(2) - (2)].sval);}
    break;

  case 61:

    {	if (parserData->solverToInvokePresent)
	{	osolerror( NULL, osoption, parserData, "only one <solverToInvoke> element allowed");
	}
	else
	{	parserData->solverToInvokePresent = true;
	}
}
    break;

  case 64:

    {osoption->general->solverToInvoke = (yyvsp[(2) - (2)].sval);}
    break;

  case 67:

    {	if (parserData->licensePresent)
	{	osolerror( NULL, osoption, parserData, "only one <license> element allowed");
	}
	else
	{	parserData->licensePresent = true;	
	}
}
    break;

  case 70:

    {osoption->general->license = (yyvsp[(2) - (2)].sval);}
    break;

  case 73:

    {	if (parserData->usernamePresent)
	{	osolerror( NULL, osoption, parserData, "only one <userName> element allowed");
	}
	else
	{	parserData->usernamePresent = true;
	}
}
    break;

  case 76:

    {osoption->general->userName = (yyvsp[(2) - (2)].sval);}
    break;

  case 79:

    {	if (parserData->passwordPresent)
	{	osolerror( NULL, osoption, parserData, "only one <password> element allowed");
	}
	else
	{	parserData->passwordPresent = true;
	}
}
    break;

  case 82:

    {osoption->general->password = (yyvsp[(2) - (2)].sval);}
    break;

  case 85:

    {	if (parserData->contactPresent)
	{	osolerror( NULL, osoption, parserData, "only one <contact> element allowed");
	}
	else
	{	parserData->contactPresent = true;
		osoption->general->contact = new ContactOption();
		osoption->general->contact->transportType = "osp";
	}
}
    break;

  case 87:

    {	if ( (strcmp((yyvsp[(2) - (2)].sval),"osp") == 0) || (strcmp((yyvsp[(2) - (2)].sval),"smtp") == 0) || (strcmp((yyvsp[(2) - (2)].sval),"http")  == 0) || 
						  (strcmp((yyvsp[(2) - (2)].sval),"ftp")  == 0) || (strcmp((yyvsp[(2) - (2)].sval),"other") == 0) )
		osoption->general->contact->transportType = (yyvsp[(2) - (2)].sval);
	else
		osolerror( NULL, osoption, parserData, "Not a valid transport type");
}
    break;

  case 92:

    {osoption->general->contact->value = (yyvsp[(1) - (1)].sval);}
    break;

  case 94:

    {	if (parserData->otherGeneralOptionsPresent)
	{	osolerror( NULL, osoption, parserData, "only one <otherOptions> element allowed");
	}
	else
	{	parserData->otherGeneralOptionsPresent = true;
		osoption->general->otherOptions = new OtherOptions();
	}
}
    break;

  case 95:

    {	if ((yyvsp[(3) - (4)].ival) < 0)
		osolerror( NULL, osoption, parserData, "Number of <other> elements cannot be negative");
	osoption->general->otherOptions->numberOfOtherOptions = (yyvsp[(3) - (4)].ival);
	osoption->general->otherOptions->other = new OtherOption*[(yyvsp[(3) - (4)].ival)];
	for (int i=0; i < (yyvsp[(3) - (4)].ival); i++) osoption->general->otherOptions->other[i] = new OtherOption();
}
    break;

  case 96:

    {	if (parserData->numberOfOtherGeneralOptions != osoption->general->otherOptions->numberOfOtherOptions)
		osolerror (NULL, osoption, parserData, "wrong number of other options in <general> element");
}
    break;

  case 99:

    {	if (parserData->numberOfOtherGeneralOptions >= osoption->general->otherOptions->numberOfOtherOptions)
		{	osolerror (NULL, osoption, parserData, "too many other options in <general> element");
		};
	}
    break;

  case 100:

    {	if (!parserData->otherOptionNamePresent)
		osolerror (NULL, osoption, parserData, "name attribute must be present");
	/* reset defaults for the next option */
	parserData->otherOptionNamePresent = false;
	parserData->otherOptionValuePresent = false;
	parserData->otherOptionDescriptionPresent = false;
	parserData->numberOfOtherGeneralOptions++;
}
    break;

  case 106:

    {	if (parserData->otherOptionNamePresent)
	{	osolerror( NULL, osoption, parserData, "only one name attribute allowed");
	}
	else
	{	parserData->otherOptionNamePresent = true;
		osoption->general->otherOptions->other[parserData->numberOfOtherGeneralOptions]->name = (yyvsp[(2) - (2)].sval);
	}
}
    break;

  case 108:

    {	if (parserData->otherOptionValuePresent)
	{	osolerror( NULL, osoption, parserData, "only one value attribute allowed");
	}
	else
	{	parserData->otherOptionValuePresent = true;
		osoption->general->otherOptions->other[parserData->numberOfOtherGeneralOptions]->value = (yyvsp[(2) - (2)].sval);
	}
}
    break;

  case 110:

    {	if (parserData->otherOptionDescriptionPresent)
	{	osolerror( NULL, osoption, parserData, "only one description attribute allowed");
	}
	else
	{	parserData->otherOptionDescriptionPresent = true;
		osoption->general->otherOptions->other[parserData->numberOfOtherGeneralOptions]->description = (yyvsp[(2) - (2)].sval);
	}
}
    break;

  case 116:

    {	if (parserData->osolsystemPresent)
	{	osolerror( NULL, osoption, parserData, "only one <system> element allowed");
	}
	else
	{	parserData->osolsystemPresent = true;
		osoption->system = new SystemOption();
	}
}
    break;

  case 127:

    {	if (parserData->minDiskSpacePresent)
	{	osolerror( NULL, osoption, parserData, "only one <minDiskSpace> element allowed");
	}
	else
	{	parserData->minDiskSpacePresent = true;
		osoption->system->minDiskSpace = new MinDiskSpace();
		osoption->system->minDiskSpace->unit = "byte";
	}
}
    break;

  case 129:

    {	if ( (strcmp((yyvsp[(2) - (2)].sval),"byte") == 0) || (strcmp((yyvsp[(2) - (2)].sval),"kilobyte") == 0) || (strcmp((yyvsp[(2) - (2)].sval),"megabyte") == 0) || 
						   (strcmp((yyvsp[(2) - (2)].sval),"terabyte") == 0) || (strcmp((yyvsp[(2) - (2)].sval),"petabyte") == 0) )
		osoption->system->minDiskSpace->unit = (yyvsp[(2) - (2)].sval);
	else
		osolerror( NULL, osoption, parserData, "Not a valid unit");
}
    break;

  case 133:

    {	if ((yyvsp[(2) - (3)].dval) < 0)
		osolerror( NULL, osoption, parserData, "minDiskSpace cannot be negative");
	osoption->system->minDiskSpace->value = (yyvsp[(2) - (3)].dval);
}
    break;

  case 134:

    {	if ((yyvsp[(2) - (3)].ival) < 0)
		osolerror( NULL, osoption, parserData, "minDiskSpace cannot be negative");
	osoption->system->minDiskSpace->value = (yyvsp[(2) - (3)].ival);
}
    break;

  case 136:

    {	if (parserData->minMemorySizePresent)
	{	osolerror( NULL, osoption, parserData, "only one <minMemorySize> element allowed");
	}
	else
	{	parserData->minMemorySizePresent = true;
		osoption->system->minMemorySize = new MinMemorySize();
		osoption->system->minMemorySize->unit = "byte";
	}
}
    break;

  case 138:

    {	if ( (strcmp((yyvsp[(2) - (2)].sval),"byte") == 0) || (strcmp((yyvsp[(2) - (2)].sval),"kilobyte") == 0) || (strcmp((yyvsp[(2) - (2)].sval),"megabyte") == 0) || 
						   (strcmp((yyvsp[(2) - (2)].sval),"terabyte") == 0) || (strcmp((yyvsp[(2) - (2)].sval),"petabyte") == 0) )
		osoption->system->minMemorySize->unit = (yyvsp[(2) - (2)].sval);
	else
		osolerror( NULL, osoption, parserData, "Not a valid unit");
}
    break;

  case 142:

    {	if ((yyvsp[(2) - (3)].dval) < 0)
		osolerror( NULL, osoption, parserData, "minMemorySize cannot be negative");
	osoption->system->minMemorySize->value = (yyvsp[(2) - (3)].dval);
}
    break;

  case 143:

    {	if ((yyvsp[(2) - (3)].ival) < 0)
		osolerror( NULL, osoption, parserData, "minMemorySize cannot be negative");
	osoption->system->minMemorySize->value = (yyvsp[(2) - (3)].ival);
}
    break;

  case 145:

    {	if (parserData->minCPUSpeedPresent)
	{	osolerror( NULL, osoption, parserData, "only one <minCPUSpeed> element allowed");
	}
	else
	{	parserData->minCPUSpeedPresent = true;
		osoption->system->minCPUSpeed = new MinCPUSpeed();
		osoption->system->minCPUSpeed->unit = "hertz";
	}
}
    break;

  case 147:

    {	if ( (strcmp((yyvsp[(2) - (2)].sval),    "hertz") == 0) || (strcmp((yyvsp[(2) - (2)].sval),"kilohertz") == 0) || (strcmp((yyvsp[(2) - (2)].sval),"megahertz") == 0) || 
	     (strcmp((yyvsp[(2) - (2)].sval),"gigahertz") == 0) || (strcmp((yyvsp[(2) - (2)].sval),"terahertz") == 0) || (strcmp((yyvsp[(2) - (2)].sval),"petahertz") == 0) ||
	     (strcmp((yyvsp[(2) - (2)].sval),    "flops") == 0) || (strcmp((yyvsp[(2) - (2)].sval),"kiloflops") == 0) || (strcmp((yyvsp[(2) - (2)].sval),"megaflops") == 0) || 
	     (strcmp((yyvsp[(2) - (2)].sval),"gigaflops") == 0) || (strcmp((yyvsp[(2) - (2)].sval),"teraflops") == 0) || (strcmp((yyvsp[(2) - (2)].sval),"petahertz") == 0) ) 
		osoption->system->minCPUSpeed->unit = (yyvsp[(2) - (2)].sval);
	else
		osolerror( NULL, osoption, parserData, "Not a valid unit");
}
    break;

  case 151:

    {	if ((yyvsp[(2) - (3)].dval) < 0)
		osolerror( NULL, osoption, parserData, "minCPUSpeed cannot be negative");
	osoption->system->minCPUSpeed->value = (yyvsp[(2) - (3)].dval);
}
    break;

  case 152:

    {	if ((yyvsp[(2) - (3)].ival) < 0)
		osolerror( NULL, osoption, parserData, "minCPUSpeed cannot be negative");
	osoption->system->minCPUSpeed->value = (yyvsp[(2) - (3)].ival);
}
    break;

  case 154:

    {	if (parserData->minCPUNumberPresent)
	{	osolerror( NULL, osoption, parserData, "only one <minCPUNumber> element allowed");
	}
	else
	{	parserData->minCPUNumberPresent = true;
	}
}
    break;

  case 157:

    {	if ((yyvsp[(2) - (2)].ival) < 0)
		osolerror( NULL, osoption, parserData, "minCPUNumber cannot be negative");
	osoption->system->minCPUNumber = (yyvsp[(2) - (2)].ival);
}
    break;

  case 160:

    {	if (parserData->otherSystemOptionsPresent)
	{	osolerror( NULL, osoption, parserData, "only one <otherOptions> element allowed");
	}
	else
	{	parserData->otherSystemOptionsPresent = true;
		osoption->system->otherOptions = new OtherOptions();
	}
}
    break;

  case 161:

    {	if ((yyvsp[(3) - (4)].ival) < 0)
		osolerror( NULL, osoption, parserData, "Number of <other> elements cannot be negative");
	osoption->system->otherOptions->numberOfOtherOptions = (yyvsp[(3) - (4)].ival);
	osoption->system->otherOptions->other = new OtherOption*[(yyvsp[(3) - (4)].ival)];
	for (int i=0; i < (yyvsp[(3) - (4)].ival); i++) osoption->system->otherOptions->other[i] = new OtherOption();
}
    break;

  case 162:

    {	if (parserData->numberOfOtherSystemOptions != osoption->system->otherOptions->numberOfOtherOptions)
		osolerror (NULL, osoption, parserData, "wrong number of other options in <system> element");
}
    break;

  case 165:

    {	if (parserData->numberOfOtherSystemOptions >= osoption->system->otherOptions->numberOfOtherOptions)
		{	osolerror (NULL, osoption, parserData, "too many other options in <system> element");
		};
	}
    break;

  case 166:

    {	if (!parserData->otherOptionNamePresent)
		osolerror (NULL, osoption, parserData, "name attribute must be present");
	/* reset defaults for the next option */
	parserData->otherOptionNamePresent = false;
	parserData->otherOptionValuePresent = false;
	parserData->otherOptionDescriptionPresent = false;
	parserData->numberOfOtherSystemOptions++;
}
    break;

  case 172:

    {	if (parserData->otherOptionNamePresent)
	{	osolerror( NULL, osoption, parserData, "only one name attribute allowed");
	}
	else
	{	parserData->otherOptionNamePresent = true;
		osoption->system->otherOptions->other[parserData->numberOfOtherSystemOptions]->name = (yyvsp[(2) - (2)].sval);
	}
}
    break;

  case 174:

    {	if (parserData->otherOptionValuePresent)
	{	osolerror( NULL, osoption, parserData, "only one value attribute allowed");
	}
	else
	{	parserData->otherOptionValuePresent = true;
		osoption->system->otherOptions->other[parserData->numberOfOtherSystemOptions]->value = (yyvsp[(2) - (2)].sval);
	}
}
    break;

  case 176:

    {	if (parserData->otherOptionDescriptionPresent)
	{	osolerror( NULL, osoption, parserData, "only one description attribute allowed");
	}
	else
	{	parserData->otherOptionDescriptionPresent = true;
		osoption->system->otherOptions->other[parserData->numberOfOtherSystemOptions]->description = (yyvsp[(2) - (2)].sval);
	}
}
    break;

  case 182:

    {	if (parserData->osolservicePresent)
	{	osolerror( NULL, osoption, parserData, "only one <service> element allowed");
	}
	else
	{	parserData->osolservicePresent = true;
		osoption->service = new ServiceOption();
	}
}
    break;

  case 190:

    {	if (parserData->serviceTypePresent)
	{	osolerror( NULL, osoption, parserData, "only one <type> element allowed");
	}
	else
	{	parserData->serviceTypePresent = true;
		osoption->service->type = "solver";
	}
}
    break;

  case 193:

    {	if ( (strcmp((yyvsp[(2) - (2)].sval),"solver") == 0) || (strcmp((yyvsp[(2) - (2)].sval),"analyzer")   == 0) || (strcmp((yyvsp[(2) - (2)].sval),"scheduler") == 0) ||
						     (strcmp((yyvsp[(2) - (2)].sval),"simulation") == 0) || (strcmp((yyvsp[(2) - (2)].sval),"registry")  == 0) ||
						     (strcmp((yyvsp[(2) - (2)].sval),"modeler")    == 0) || (strcmp((yyvsp[(2) - (2)].sval),"agent")     == 0) ) 
		osoption->service->type = (yyvsp[(2) - (2)].sval);
	else
		osolerror( NULL, osoption, parserData, "Not a valid service type");
}
    break;

  case 196:

    {	if (parserData->otherServiceOptionsPresent)
	{	osolerror( NULL, osoption, parserData, "only one <otherOptions> element allowed");
	}
	else
	{	parserData->otherServiceOptionsPresent = true;
		osoption->service->otherOptions = new OtherOptions();
	}
}
    break;

  case 197:

    {	if ((yyvsp[(3) - (4)].ival) < 0)
		osolerror( NULL, osoption, parserData, "Number of <other> elements cannot be negative");
	osoption->service->otherOptions->numberOfOtherOptions = (yyvsp[(3) - (4)].ival);
	osoption->service->otherOptions->other = new OtherOption*[(yyvsp[(3) - (4)].ival)];
	for (int i=0; i < (yyvsp[(3) - (4)].ival); i++) osoption->service->otherOptions->other[i] = new OtherOption();
}
    break;

  case 198:

    {	if (parserData->numberOfOtherServiceOptions != osoption->service->otherOptions->numberOfOtherOptions)
		osolerror (NULL, osoption, parserData, "wrong number of other options in <service> element");
}
    break;

  case 201:

    {	if (parserData->numberOfOtherServiceOptions >= osoption->service->otherOptions->numberOfOtherOptions)
		{	osolerror (NULL, osoption, parserData, "too many other options in <service> element");
		};
	}
    break;

  case 202:

    {	if (!parserData->otherOptionNamePresent)
		osolerror (NULL, osoption, parserData, "name attribute must be present");
	/* reset defaults for the next option */
	parserData->otherOptionNamePresent = false;
	parserData->otherOptionValuePresent = false;
	parserData->otherOptionDescriptionPresent = false;
	parserData->numberOfOtherServiceOptions++;
}
    break;

  case 208:

    {	if (parserData->otherOptionNamePresent)
	{	osolerror( NULL, osoption, parserData, "only one name attribute allowed");
	}
	else
	{	parserData->otherOptionNamePresent = true;
		osoption->service->otherOptions->other[parserData->numberOfOtherServiceOptions]->name = (yyvsp[(2) - (2)].sval);
	}
}
    break;

  case 210:

    {	if (parserData->otherOptionValuePresent)
	{	osolerror( NULL, osoption, parserData, "only one value attribute allowed");
	}
	else
	{	parserData->otherOptionValuePresent = true;
		osoption->service->otherOptions->other[parserData->numberOfOtherServiceOptions]->value = (yyvsp[(2) - (2)].sval);
	}
}
    break;

  case 212:

    {	if (parserData->otherOptionDescriptionPresent)
	{	osolerror( NULL, osoption, parserData, "only one description attribute allowed");
	}
	else
	{	parserData->otherOptionDescriptionPresent = true;
		osoption->service->otherOptions->other[parserData->numberOfOtherServiceOptions]->description = (yyvsp[(2) - (2)].sval);
	}
}
    break;

  case 218:

    {	if (parserData->osoljobPresent)
	{	osolerror( NULL, osoption, parserData, "only one <job> element allowed");
	}
	else
	{	parserData->osoljobPresent = true;
		osoption->job = new JobOption();
	}
}
    break;

  case 239:

    {	if (parserData->maxTimePresent)
	{	osolerror( NULL, osoption, parserData, "only one <maxTime> element allowed");
	}
	else
	{	parserData->maxTimePresent = true;
		osoption->job->maxTime = new MaxTime();
		osoption->job->maxTime->unit = "second"; 
	}
}
    break;

  case 241:

    {	if ( (strcmp((yyvsp[(2) - (2)].sval),"second") == 0) || (strcmp((yyvsp[(2) - (2)].sval),"minute") == 0) || (strcmp((yyvsp[(2) - (2)].sval),"hour") == 0) ||
						     (strcmp((yyvsp[(2) - (2)].sval),"day")    == 0) || (strcmp((yyvsp[(2) - (2)].sval),"week") == 0) ||
						     (strcmp((yyvsp[(2) - (2)].sval),"month")  == 0) || (strcmp((yyvsp[(2) - (2)].sval),"year") == 0) ) 
                osoption->job->maxTime->unit = (yyvsp[(2) - (2)].sval);
	else
		osolerror( NULL, osoption, parserData, "Not a valid time unit");
}
    break;

  case 245:

    {	if ((yyvsp[(2) - (3)].dval) < 0)
		osolerror( NULL, osoption, parserData, "maxTime cannot be negative");
	osoption->job->maxTime->value = (yyvsp[(2) - (3)].dval);
}
    break;

  case 246:

    {	if ((yyvsp[(2) - (3)].ival) < 0)
		osolerror( NULL, osoption, parserData, "maxTime cannot be negative");
	osoption->job->maxTime->value = (yyvsp[(2) - (3)].ival);
}
    break;

  case 248:

    {	if (parserData->scheduledStartTimePresent)
	{	osolerror( NULL, osoption, parserData, "only one <scheduledStartTime> element allowed");
	}
	else
	{	parserData->scheduledStartTimePresent = true;
		osoption->job->scheduledStartTime = "1970-01-01T00:00:00-00:00";
	}
}
    break;

  case 251:

    {osoption->job->scheduledStartTime = (yyvsp[(2) - (2)].sval);}
    break;

  case 254:

    {	if (parserData->dependenciesPresent)
	{	osolerror( NULL, osoption, parserData, "only one <dependencies> element allowed");
	}
	else
	{	parserData->dependenciesPresent = true;
		osoption->job->dependencies = new JobDependencies();
	}
}
    break;

  case 255:

    {	if ((yyvsp[(3) - (4)].ival) < 1)
		osolerror( NULL, osoption, parserData, "Number of job IDs must be at least 1");
	osoption->job->dependencies->numberOfJobIDs = (yyvsp[(3) - (4)].ival);
	osoption->job->dependencies->jobID = new std::string[(yyvsp[(3) - (4)].ival)];
}
    break;

  case 258:

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

  case 261:

    {	if (parserData->requiredDirectoriesPresent)
	{	osolerror( NULL, osoption, parserData, "only one <requiredDirectories> element allowed");
	}
	else
	{	parserData->requiredDirectoriesPresent = true;
		osoption->job->requiredDirectories = new DirectoriesAndFiles();
	}
}
    break;

  case 262:

    {	if ((yyvsp[(3) - (4)].ival) < 1)
		osolerror( NULL, osoption, parserData, "Number of paths must be at least 1");
	osoption->job->requiredDirectories->numberOfPaths = (yyvsp[(3) - (4)].ival);
	osoption->job->requiredDirectories->path = new std::string[(yyvsp[(3) - (4)].ival)];
}
    break;

  case 265:

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

  case 268:

    {	if (parserData->requiredFilesPresent)
	{	osolerror( NULL, osoption, parserData, "only one <requiredFiles> element allowed");
	}
	else
	{	parserData->requiredFilesPresent = true;
		osoption->job->requiredFiles = new DirectoriesAndFiles();
	}
}
    break;

  case 269:

    {	if ((yyvsp[(3) - (4)].ival) < 1)
		osolerror( NULL, osoption, parserData, "Number of paths must be at least 1");
	osoption->job->requiredFiles->numberOfPaths = (yyvsp[(3) - (4)].ival);
	osoption->job->requiredFiles->path = new std::string[(yyvsp[(3) - (4)].ival)];
}
    break;

  case 272:

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

  case 275:

    {	if (parserData->directoriesToMakePresent)
	{	osolerror( NULL, osoption, parserData, "only one <directoriesToMake> element allowed");
	}
	else
	{	parserData->directoriesToMakePresent = true;
		osoption->job->directoriesToMake = new DirectoriesAndFiles();
	}
}
    break;

  case 276:

    {	if ((yyvsp[(3) - (4)].ival) < 1)
		osolerror( NULL, osoption, parserData, "Number of paths must be at least 1");
	osoption->job->directoriesToMake->numberOfPaths = (yyvsp[(3) - (4)].ival);
	osoption->job->directoriesToMake->path = new std::string[(yyvsp[(3) - (4)].ival)];
}
    break;

  case 279:

    {	if (parserData->numberOfDirectoriesToMake >= osoption->job->directoriesToMake->numberOfPaths)
	{	osolerror (NULL, osoption, parserData, "too many job IDs in <directoriesToMake> element");
	}
	else
	{	osoption->job->directoriesToMake->path[parserData->numberOfDirectoriesToMake] = (yyvsp[(3) - (3)].sval);
		parserData->numberOfDirectoriesToMake++;
	};
}
    break;

  case 282:

    {	if (parserData->filesToMakePresent)
	{	osolerror( NULL, osoption, parserData, "only one <filesToMake> element allowed");
	}
	else
	{	parserData->filesToMakePresent = true;
		osoption->job->filesToMake = new DirectoriesAndFiles();
	}
}
    break;

  case 283:

    {	if ((yyvsp[(3) - (4)].ival) < 0)
		osolerror( NULL, osoption, parserData, "Number of paths cannot be negative");
	osoption->job->filesToMake->numberOfPaths = (yyvsp[(3) - (4)].ival);
	osoption->job->filesToMake->path = new std::string[(yyvsp[(3) - (4)].ival)];
}
    break;

  case 286:

    {	if (parserData->numberOfFilesToMake >= osoption->job->filesToMake->numberOfPaths)
	{	osolerror (NULL, osoption, parserData, "too many job IDs in <filesToMake> element");
	}
	else
	{	osoption->job->filesToMake->path[parserData->numberOfFilesToMake] = (yyvsp[(3) - (3)].sval);
		parserData->numberOfFilesToMake++;
	};
}
    break;

  case 289:

    {	if (parserData->inputDirectoriesToMovePresent)
	{	osolerror( NULL, osoption, parserData, "only one <inputDirectoriesToMove> element allowed");
	}
	else
	{	parserData->inputDirectoriesToMovePresent = true;
		osoption->job->inputDirectoriesToMove = new PathPairs();
	}
}
    break;

  case 290:

    {	if ((yyvsp[(3) - (4)].ival) < 0)
		osolerror (NULL, osoption, parserData, "Require nonnegative number of directories to move");
	osoption->job->inputDirectoriesToMove->numberOfPathPairs = (yyvsp[(3) - (4)].ival);
	osoption->job->inputDirectoriesToMove->pathPair = new PathPair*[(yyvsp[(3) - (4)].ival)];
	for (int i = 0; i < (yyvsp[(3) - (4)].ival); i++)
		osoption->job->inputDirectoriesToMove->pathPair[i] = new PathPair();
}
    break;

  case 293:

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

  case 294:

    {	if (parserData->numberOfInputDirectoriesToMove >= osoption->job->inputDirectoriesToMove->numberOfPathPairs)
	{	osolerror (NULL, osoption, parserData, "too many path pairs in <inputDirectoriesToMove> element");
	};
}
    break;

  case 300:

    {	if (parserData->pathPairFromPresent)
	{	osolerror( NULL, osoption, parserData, "only one \"from\" attribute allowed");
	}
	else
	{	parserData->pathPairFromPresent = true;
		osoption->job->inputDirectoriesToMove->pathPair[parserData->numberOfInputDirectoriesToMove]->from = (yyvsp[(2) - (2)].sval);
	}
}
    break;

  case 302:

    {	if (parserData->pathPairToPresent)
	{	osolerror( NULL, osoption, parserData, "only one \"to\" attribute allowed");
	}
	else
	{	parserData->pathPairToPresent = true;
		osoption->job->inputDirectoriesToMove->pathPair[parserData->numberOfInputDirectoriesToMove]->to = (yyvsp[(2) - (2)].sval);
	}
}
    break;

  case 304:

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

  case 309:

    {	if (parserData->inputFilesToMovePresent)
	{	osolerror( NULL, osoption, parserData, "only one <inputFilesToMove> element allowed");
	}
	else
	{	parserData->inputFilesToMovePresent = true;
		osoption->job->inputFilesToMove = new PathPairs();
	}
}
    break;

  case 310:

    {	if ((yyvsp[(3) - (4)].ival) < 0)
		osolerror (NULL, osoption, parserData, "Require nonnegative number of files to move");
	osoption->job->inputFilesToMove->numberOfPathPairs = (yyvsp[(3) - (4)].ival);
	osoption->job->inputFilesToMove->pathPair = new PathPair*[(yyvsp[(3) - (4)].ival)];
	for (int i = 0; i < (yyvsp[(3) - (4)].ival); i++) osoption->job->inputFilesToMove->pathPair[i] = new PathPair();
}
    break;

  case 313:

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

  case 314:

    {	if (parserData->numberOfInputFilesToMove >= osoption->job->inputFilesToMove->numberOfPathPairs)
	{	osolerror (NULL, osoption, parserData, "too many path pairs in <inputFilesToMove> element");
	};
}
    break;

  case 320:

    {	if (parserData->pathPairFromPresent)
	{	osolerror( NULL, osoption, parserData, "only one \"from\" attribute allowed");
	}
	else
	{	parserData->pathPairFromPresent = true;
		osoption->job->inputFilesToMove->pathPair[parserData->numberOfInputFilesToMove]->from = (yyvsp[(2) - (2)].sval);
	}
}
    break;

  case 322:

    {	if (parserData->pathPairToPresent)
	{	osolerror( NULL, osoption, parserData, "only one \"to\" attribute allowed");
	}
	else
	{	parserData->pathPairToPresent = true;
		osoption->job->inputFilesToMove->pathPair[parserData->numberOfInputFilesToMove]->to = (yyvsp[(2) - (2)].sval);
	}
}
    break;

  case 324:

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

  case 329:

    {	if (parserData->outputDirectoriesToMovePresent)
	{	osolerror( NULL, osoption, parserData, "only one <outputDirectoriesToMove> element allowed");
	}
	else
	{	parserData->outputDirectoriesToMovePresent = true;
		osoption->job->outputDirectoriesToMove = new PathPairs();
	}
}
    break;

  case 330:

    {	if ((yyvsp[(3) - (4)].ival) < 0)
		osolerror (NULL, osoption, parserData, "Require nonnegative number of directories to move");
	osoption->job->outputDirectoriesToMove->numberOfPathPairs = (yyvsp[(3) - (4)].ival);
	osoption->job->outputDirectoriesToMove->pathPair = new PathPair*[(yyvsp[(3) - (4)].ival)];
	for (int i = 0; i < (yyvsp[(3) - (4)].ival); i++)
		osoption->job->outputDirectoriesToMove->pathPair[i] = new PathPair();
}
    break;

  case 333:

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

  case 334:

    {	if (parserData->numberOfOutputDirectoriesToMove >= osoption->job->outputDirectoriesToMove->numberOfPathPairs)
	{	osolerror (NULL, osoption, parserData, "too many path pairs in <outputDirectoriesToMove> element");
	};
}
    break;

  case 340:

    {	if (parserData->pathPairFromPresent)
	{	osolerror( NULL, osoption, parserData, "only one \"from\" attribute allowed");
	}
	else
	{	parserData->pathPairFromPresent = true;
		osoption->job->outputDirectoriesToMove->pathPair[parserData->numberOfOutputDirectoriesToMove]->from = (yyvsp[(2) - (2)].sval);
	}
}
    break;

  case 342:

    {	if (parserData->pathPairToPresent)
	{	osolerror( NULL, osoption, parserData, "only one \"to\" attribute allowed");
	}
	else
	{	parserData->pathPairToPresent = true;
		osoption->job->outputDirectoriesToMove->pathPair[parserData->numberOfOutputDirectoriesToMove]->to = (yyvsp[(2) - (2)].sval);
	}
}
    break;

  case 344:

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

  case 349:

    {	if (parserData->outputFilesToMovePresent)
	{	osolerror( NULL, osoption, parserData, "only one <outputFilesToMove> element allowed");
	}
	else
	{	parserData->outputFilesToMovePresent = true;
		osoption->job->outputFilesToMove = new PathPairs();
	}
}
    break;

  case 350:

    {	if ((yyvsp[(3) - (4)].ival) < 0)
		osolerror (NULL, osoption, parserData, "Require nonnegative number of files to move");
	osoption->job->outputFilesToMove->numberOfPathPairs = (yyvsp[(3) - (4)].ival);
	osoption->job->outputFilesToMove->pathPair = new PathPair*[(yyvsp[(3) - (4)].ival)];
	for (int i = 0; i < (yyvsp[(3) - (4)].ival); i++)
		osoption->job->outputFilesToMove->pathPair[i] = new PathPair();}
    break;

  case 353:

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

  case 354:

    {	if (parserData->numberOfOutputFilesToMove >= osoption->job->outputFilesToMove->numberOfPathPairs)
	{	osolerror (NULL, osoption, parserData, "too many path pairs in <outputFilesToMove> element");
	};
}
    break;

  case 360:

    {	if (parserData->pathPairFromPresent)
	{	osolerror( NULL, osoption, parserData, "only one \"from\" attribute allowed");
	}
	else
	{	parserData->pathPairFromPresent = true;
		osoption->job->outputFilesToMove->pathPair[parserData->numberOfOutputFilesToMove]->from = (yyvsp[(2) - (2)].sval);
	}
}
    break;

  case 362:

    {	if (parserData->pathPairToPresent)
	{	osolerror( NULL, osoption, parserData, "only one \"to\" attribute allowed");
	}
	else
	{	parserData->pathPairToPresent = true;
		osoption->job->outputFilesToMove->pathPair[parserData->numberOfOutputFilesToMove]->to = (yyvsp[(2) - (2)].sval);
	}
}
    break;

  case 364:

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

  case 369:

    {	if (parserData->filesToDeletePresent)
	{	osolerror( NULL, osoption, parserData, "only one <filesToDelete> element allowed");
	}
	else
	{	parserData->filesToDeletePresent = true;
		osoption->job->filesToDelete = new DirectoriesAndFiles();
	}
}
    break;

  case 370:

    {	if ((yyvsp[(3) - (4)].ival) < 1)
		osolerror( NULL, osoption, parserData, "Number of paths must be at least 1");
	osoption->job->filesToDelete->numberOfPaths = (yyvsp[(3) - (4)].ival);
	osoption->job->filesToDelete->path = new std::string[(yyvsp[(3) - (4)].ival)];
}
    break;

  case 373:

    {	if (parserData->numberOfFilesToDelete >= osoption->job->filesToDelete->numberOfPaths)
	{	osolerror (NULL, osoption, parserData, "too many job IDs in <filesToDelete> element");
	}
	else
	{	osoption->job->filesToDelete->path[parserData->numberOfFilesToDelete] = (yyvsp[(3) - (3)].sval);
		parserData->numberOfFilesToDelete++;
	};
}
    break;

  case 376:

    {	if (parserData->directoriesToDeletePresent)
	{	osolerror( NULL, osoption, parserData, "only one <directoriesToDelete> element allowed");
	}
	else
	{	parserData->directoriesToDeletePresent = true;
		osoption->job->directoriesToDelete = new DirectoriesAndFiles();
	}
}
    break;

  case 377:

    {	if ((yyvsp[(3) - (4)].ival) < 1)
		osolerror( NULL, osoption, parserData, "Number of paths must be at least 1");
	osoption->job->directoriesToDelete->numberOfPaths = (yyvsp[(3) - (4)].ival);
	osoption->job->directoriesToDelete->path = new std::string[(yyvsp[(3) - (4)].ival)];
}
    break;

  case 380:

    {	if (parserData->numberOfDirectoriesToDelete >= osoption->job->directoriesToDelete->numberOfPaths)
	{	osolerror (NULL, osoption, parserData, "too many job IDs in <directoriesToDelete> element");
	}
	else
	{	osoption->job->directoriesToDelete->path[parserData->numberOfDirectoriesToDelete] = (yyvsp[(3) - (3)].sval);
		parserData->numberOfDirectoriesToDelete++;
	};
}
    break;

  case 383:

    {	if (parserData->processesToKillPresent)
	{	osolerror( NULL, osoption, parserData, "only one <processesToKill> element allowed");
	}
	else
	{	parserData->processesToKillPresent = true;
		osoption->job->processesToKill = new Processes();
	}
}
    break;

  case 384:

    {	if ((yyvsp[(3) - (4)].ival) < 1)
		osolerror( NULL, osoption, parserData, "Number of job IDs must be at least 1");
	osoption->job->processesToKill->numberOfProcesses = (yyvsp[(3) - (4)].ival);
	osoption->job->processesToKill->process = new std::string[(yyvsp[(3) - (4)].ival)];
}
    break;

  case 387:

    {	if (parserData->numberOfProcessesToKill >= osoption->job->processesToKill->numberOfProcesses)
	{	osolerror (NULL, osoption, parserData, "too many job IDs in <processesToKill> element");
	}
	else
	{	osoption->job->processesToKill->process[parserData->numberOfProcessesToKill] = (yyvsp[(3) - (3)].sval);
		parserData->numberOfProcessesToKill++;
	};
}
    break;

  case 390:

    {	if (parserData->otherJobOptionsPresent)
	{	osolerror( NULL, osoption, parserData, "only one <otherOptions> element allowed");
	}
	else
	{	parserData->otherJobOptionsPresent = true;
		osoption->job->otherOptions = new OtherOptions();
	}
}
    break;

  case 391:

    {	if ((yyvsp[(3) - (4)].ival) < 0)
		osolerror( NULL, osoption, parserData, "Number of <other> elements cannot be negative");
	osoption->job->otherOptions->numberOfOtherOptions = (yyvsp[(3) - (4)].ival);
	osoption->job->otherOptions->other = new OtherOption*[(yyvsp[(3) - (4)].ival)];
	for (int i=0; i < (yyvsp[(3) - (4)].ival); i++) osoption->job->otherOptions->other[i] = new OtherOption();
}
    break;

  case 392:

    {	if (parserData->numberOfOtherJobOptions != osoption->job->otherOptions->numberOfOtherOptions)
		osolerror (NULL, osoption, parserData, "wrong number of other options in <job> element");
}
    break;

  case 395:

    {	if (parserData->numberOfOtherJobOptions >= osoption->job->otherOptions->numberOfOtherOptions)
		{	osolerror (NULL, osoption, parserData, "too many other options in <job> element");
		};
	}
    break;

  case 396:

    {	if (!parserData->otherOptionNamePresent)
		osolerror (NULL, osoption, parserData, "name attribute must be present");
	/* reset defaults for the next option */
	parserData->otherOptionNamePresent = false;
	parserData->otherOptionValuePresent = false;
	parserData->otherOptionDescriptionPresent = false;
	parserData->numberOfOtherJobOptions++;
}
    break;

  case 402:

    {	if (parserData->otherOptionNamePresent)
	{	osolerror( NULL, osoption, parserData, "only one name attribute allowed");
	}
	else
	{	parserData->otherOptionNamePresent = true;
		osoption->job->otherOptions->other[parserData->numberOfOtherJobOptions]->name = (yyvsp[(2) - (2)].sval);
	}
}
    break;

  case 404:

    {	if (parserData->otherOptionValuePresent)
	{	osolerror( NULL, osoption, parserData, "only one value attribute allowed");
	}
	else
	{	parserData->otherOptionValuePresent = true;
		osoption->job->otherOptions->other[parserData->numberOfOtherJobOptions]->value = (yyvsp[(2) - (2)].sval);
	}
}
    break;

  case 406:

    {	if (parserData->otherOptionDescriptionPresent)
	{	osolerror( NULL, osoption, parserData, "only one description attribute allowed");
	}
	else
	{	parserData->otherOptionDescriptionPresent = true;
		osoption->job->otherOptions->other[parserData->numberOfOtherJobOptions]->description = (yyvsp[(2) - (2)].sval);
	}
}
    break;

  case 412:

    {	if (parserData->osoloptimizationPresent)
	{	osolerror( NULL, osoption, parserData, "only one <optimization> element allowed");
	}
	else
	{	parserData->osoloptimizationPresent = true;
		osoption->optimization = new OptimizationOption();
	}
}
    break;

  case 418:

    {	if ((yyvsp[(3) - (4)].ival) < 0)
		osolerror( NULL, osoption, parserData, "Number of variables cannot be negative");
	osoption->optimization->numberOfVariables = (yyvsp[(3) - (4)].ival);
}
    break;

  case 419:

    {	if ((yyvsp[(3) - (4)].ival) < 0)
		osolerror( NULL, osoption, parserData, "Number of constraints cannot be negative");
	osoption->optimization->numberOfConstraints = (yyvsp[(3) - (4)].ival);
}
    break;

  case 420:

    {	if ((yyvsp[(3) - (4)].ival) < 0)
		osolerror( NULL, osoption, parserData, "Number of objectives cannot be negative");
	osoption->optimization->numberOfObjectives = (yyvsp[(3) - (4)].ival);
}
    break;

  case 426:

    {	osoption->optimization->variables = new VariableOption();
}
    break;

  case 428:

    {	if ((yyvsp[(3) - (4)].ival) < 0)
		osolerror (NULL, osoption, parserData, "number of <other> variable options cannot be negative");
	osoption->optimization->variables->numberOfOtherVariableOptions = (yyvsp[(3) - (4)].ival);
	osoption->optimization->variables->other = new OtherVariableOption*[(yyvsp[(3) - (4)].ival)];
	for (int i= 0; i < (yyvsp[(3) - (4)].ival); i++)
		osoption->optimization->variables->other[i] = new OtherVariableOption();
}
    break;

  case 433:

    {	if ((yyvsp[(3) - (4)].ival) < 0)
		osolerror (NULL, osoption, parserData, "number of <var> elements must be nonnegative");
	osoption->optimization->variables->initialVariableValues = new InitVariableValues();
	osoption->optimization->variables->initialVariableValues->numberOfVar = (yyvsp[(3) - (4)].ival);
	osoption->optimization->variables->initialVariableValues->var = new InitVarValue*[(yyvsp[(3) - (4)].ival)];
	for (int i = 0; i < (yyvsp[(3) - (4)].ival); i++)
		osoption->optimization->variables->initialVariableValues->var[i] = new InitVarValue();
}
    break;

  case 436:

    {	if (!parserData->idxAttributePresent)
		osolerror (NULL, osoption, parserData, "variable index required");
	parserData->idxAttributePresent = false;
	parserData->valAttributePresent = false;
	parserData->numberOfVar++;
}
    break;

  case 437:

    {	if (parserData->numberOfVar >= osoption->optimization->variables->initialVariableValues->numberOfVar)
		osolerror(NULL, osoption, parserData, "too many initial variable values");
}
    break;

  case 442:

    {	if (parserData->idxAttributePresent)
		osolerror (NULL, osoption, parserData, "only one variable index allowed");
	parserData->idxAttributePresent = true;
	if ((yyvsp[(3) - (4)].ival) < 0)
		osolerror (NULL, osoption, parserData, "variable index must be nonnegative");
	if (parserData->numberOfVariablesPresent)
	{	if ((yyvsp[(3) - (4)].ival) >= parserData->numberOfVariables)
			osolerror (NULL, osoption, parserData, "variable index exceeds upper limit");
	};
	osoption->optimization->variables->initialVariableValues->var[parserData->numberOfVar]->idx = (yyvsp[(3) - (4)].ival);
}
    break;

  case 443:

    {	if (parserData->valAttributePresent)
		osolerror (NULL, osoption, parserData, "only one variable value allowed");
	parserData->valAttributePresent = true;
	if (strcmp((yyvsp[(2) - (2)].sval),"INF") == 0)
		osoption->optimization->variables->initialVariableValues->var[parserData->numberOfVar]->value = OSDBL_MAX;
	else if (strcmp((yyvsp[(2) - (2)].sval),"-INF") == 0)
		osoption->optimization->variables->initialVariableValues->var[parserData->numberOfVar]->value = -OSDBL_MAX;
	else
		osoption->optimization->variables->initialVariableValues->var[parserData->numberOfVar]->value = os_strtod((yyvsp[(2) - (2)].sval), NULL);
}
    break;

  case 449:

    {	if ((yyvsp[(3) - (4)].ival) < 0)
		osolerror (NULL, osoption, parserData, "number of <var> elements must be nonnegative");
	osoption->optimization->variables->initialVariableValuesString = new InitVariableValuesString();
	osoption->optimization->variables->initialVariableValuesString->numberOfVar = (yyvsp[(3) - (4)].ival);
	osoption->optimization->variables->initialVariableValuesString->var = new InitVarValueString*[(yyvsp[(3) - (4)].ival)];
	for (int i = 0; i < (yyvsp[(3) - (4)].ival); i++)
		osoption->optimization->variables->initialVariableValuesString->var[i] = new InitVarValueString ();
}
    break;

  case 452:

    {	if (!parserData->idxAttributePresent)
		osolerror (NULL, osoption, parserData, "variable index required");
	parserData->idxAttributePresent = false;
	parserData->valAttributePresent = false;
	parserData->numberOfVarStr++;
}
    break;

  case 453:

    {	if (parserData->numberOfVarStr >= osoption->optimization->variables->initialVariableValuesString->numberOfVar)
		osolerror(NULL, osoption, parserData, "too many initial variable strings");
}
    break;

  case 458:

    {	if (parserData->idxAttributePresent)
		osolerror (NULL, osoption, parserData, "only one variable index allowed");
	parserData->idxAttributePresent = true;
	if ((yyvsp[(3) - (4)].ival) < 0)
		osolerror (NULL, osoption, parserData, "variable index must be nonnegative");
	if (parserData->numberOfVariablesPresent)
	{	if ((yyvsp[(3) - (4)].ival) >= parserData->numberOfVariables)
			osolerror (NULL, osoption, parserData, "variable index exceeds upper limit");
	};
	osoption->optimization->variables->initialVariableValuesString->var[parserData->numberOfVarStr]->idx = (yyvsp[(3) - (4)].ival);
}
    break;

  case 459:

    {	if (parserData->valAttributePresent)
		osolerror (NULL, osoption, parserData, "only one variable string value allowed");
	parserData->valAttributePresent = true;
	osoption->optimization->variables->initialVariableValuesString->var[parserData->numberOfVarStr]->value = (yyvsp[(2) - (2)].sval);
}
    break;

  case 465:

    {	if ((yyvsp[(3) - (4)].ival) < 0)
		osolerror (NULL, osoption, parserData, "number of <var> elements must be nonnegative");
	osoption->optimization->variables->initialBasisStatus = new InitialBasisStatus();
	osoption->optimization->variables->initialBasisStatus->numberOfVar = (yyvsp[(3) - (4)].ival);
	osoption->optimization->variables->initialBasisStatus->var = new InitBasStatus*[(yyvsp[(3) - (4)].ival)];
	for (int i = 0; i < (yyvsp[(3) - (4)].ival); i++)
		osoption->optimization->variables->initialBasisStatus->var[i] = new InitBasStatus();
}
    break;

  case 468:

    {	if (!parserData->idxAttributePresent)
		osolerror (NULL, osoption, parserData, "variable index required");
	parserData->idxAttributePresent = false;
	parserData->valAttributePresent = false;
	parserData->numberOfBasVar++;
}
    break;

  case 469:

    {	if (parserData->numberOfBasVar >= osoption->optimization->variables->initialBasisStatus->numberOfVar)
		osolerror(NULL, osoption, parserData, "too many initial basis variables");
}
    break;

  case 474:

    {	if (parserData->idxAttributePresent)
		osolerror (NULL, osoption, parserData, "only one variable index allowed");
	parserData->idxAttributePresent = true;
	if ((yyvsp[(3) - (4)].ival) < 0)
		osolerror (NULL, osoption, parserData, "variable index must be nonnegative");
	if (parserData->numberOfVariablesPresent)
	{	if ((yyvsp[(3) - (4)].ival) >= parserData->numberOfVariables)
			osolerror (NULL, osoption, parserData, "variable index exceeds upper limit");
	};
	osoption->optimization->variables->initialBasisStatus->var[parserData->numberOfBasVar]->idx = (yyvsp[(3) - (4)].ival);
}
    break;

  case 475:

    {	if (parserData->valAttributePresent)
		osolerror (NULL, osoption, parserData, "only one variable value allowed");
	parserData->valAttributePresent = true;
	osoption->optimization->variables->initialBasisStatus->var[parserData->numberOfBasVar]->value = (yyvsp[(2) - (2)].sval);
}
    break;

  case 481:

    {	if ((yyvsp[(3) - (4)].ival) < 0)
		osolerror (NULL, osoption, parserData, "number of <var> elements must be nonnegative");
	osoption->optimization->variables->integerVariableBranchingWeights = new IntegerVariableBranchingWeights();
	osoption->optimization->variables->integerVariableBranchingWeights->numberOfVar = (yyvsp[(3) - (4)].ival);
	osoption->optimization->variables->integerVariableBranchingWeights->var = new BranchingWeight*[(yyvsp[(3) - (4)].ival)];
	for (int i = 0; i < (yyvsp[(3) - (4)].ival); i++)
		osoption->optimization->variables->integerVariableBranchingWeights->var[i] = new BranchingWeight();
}
    break;

  case 484:

    {	if (!parserData->idxAttributePresent)
		osolerror (NULL, osoption, parserData, "variable index required");
	parserData->idxAttributePresent = false;
	parserData->valAttributePresent = false;
	parserData->numberOfIntWt++;
}
    break;

  case 485:

    {	if (parserData->numberOfIntWt >= osoption->optimization->variables->integerVariableBranchingWeights->numberOfVar)
		osolerror(NULL, osoption, parserData, "too many integer branching weights");
}
    break;

  case 490:

    {	if (parserData->idxAttributePresent)
		osolerror (NULL, osoption, parserData, "only one variable index allowed");
	parserData->idxAttributePresent = true;
	if ((yyvsp[(3) - (4)].ival) < 0)
		osolerror (NULL, osoption, parserData, "variable index must be nonnegative");
	if (parserData->numberOfVariablesPresent)
	{	if ((yyvsp[(3) - (4)].ival) >= parserData->numberOfVariables)
			osolerror (NULL, osoption, parserData, "variable index exceeds upper limit");
	};
	osoption->optimization->variables->integerVariableBranchingWeights->var[parserData->numberOfIntWt]->idx = (yyvsp[(3) - (4)].ival);
}
    break;

  case 491:

    {	if (parserData->valAttributePresent)
		osolerror (NULL, osoption, parserData, "only one branching weight allowed");
	parserData->valAttributePresent = true;
	if (strcmp((yyvsp[(2) - (2)].sval),"INF") == 0)
		osoption->optimization->variables->integerVariableBranchingWeights->var[parserData->numberOfIntWt]->value = OSDBL_MAX;
	else if (strcmp((yyvsp[(2) - (2)].sval),"-INF") == 0)
		osoption->optimization->variables->integerVariableBranchingWeights->var[parserData->numberOfIntWt]->value = -OSDBL_MAX;
	else
		osoption->optimization->variables->integerVariableBranchingWeights->var[parserData->numberOfIntWt]->value = os_strtod((yyvsp[(2) - (2)].sval), NULL);
}
    break;

  case 497:

    {	if ((yyvsp[(3) - (4)].ival) < 0)
		osolerror (NULL, osoption, parserData, "number of <sos> elements must be nonnegative");
	osoption->optimization->variables->sosVariableBranchingWeights = new SOSVariableBranchingWeights();
	osoption->optimization->variables->sosVariableBranchingWeights->numberOfSOS = (yyvsp[(3) - (4)].ival);
	osoption->optimization->variables->sosVariableBranchingWeights->sos = new SOSWeights*[(yyvsp[(3) - (4)].ival)];
	for (int i = 0; i < (yyvsp[(3) - (4)].ival); i++)
		osoption->optimization->variables->sosVariableBranchingWeights->sos[i] = new SOSWeights();
}
    break;

  case 500:

    {	if (!parserData->sosIdxAttributePresent)
		osolerror (NULL, osoption, parserData, "SOS index required");
	if (!parserData->sosIdxAttributePresent)
		osolerror (NULL, osoption, parserData, "numberOfVar required");
	parserData->sosIdxAttributePresent = false;
	parserData->grpWgtAttributePresent = false;
	parserData->nOfVarAttributePresent = false;
	parserData->numberOfSOS++;
}
    break;

  case 501:

    {	if (parserData->numberOfSOS >= osoption->optimization->variables->sosVariableBranchingWeights->numberOfSOS)
		osolerror(NULL, osoption, parserData, "too many SOS branching weights");
	parserData->numberOfSOSVar = 0;
}
    break;

  case 507:

    {	if (parserData->sosIdxAttributePresent)
		osolerror (NULL, osoption, parserData, "only one SOS index allowed");
	parserData->sosIdxAttributePresent = true;
	if ((yyvsp[(3) - (4)].ival) < 0)
		osolerror (NULL, osoption, parserData, "SOS index must be nonnegative");
	osoption->optimization->variables->sosVariableBranchingWeights->sos[parserData->numberOfSOS]->sosIdx = (yyvsp[(3) - (4)].ival);
}
    break;

  case 508:

    {	if (parserData->grpWgtAttributePresent)
		osolerror (NULL, osoption, parserData, "only one group weight allowed");
	parserData->grpWgtAttributePresent = true;
	osoption->optimization->variables->sosVariableBranchingWeights->sos[parserData->numberOfSOS]->groupWeight = (yyvsp[(3) - (4)].dval);
}
    break;

  case 509:

    {	if (parserData->grpWgtAttributePresent)
		osolerror (NULL, osoption, parserData, "only one group weight allowed");
	parserData->grpWgtAttributePresent = true;
	osoption->optimization->variables->sosVariableBranchingWeights->sos[parserData->numberOfSOS]->groupWeight = (yyvsp[(3) - (4)].ival);
}
    break;

  case 510:

    {	if ((yyvsp[(3) - (4)].ival) < 0)
		osolerror (NULL, osoption, parserData, "number of <var> elements must be nonnegative");
//	osoption->optimization->variables->sosVariableBranchingWeights->sos[parserData->numberOfSOS] = new SOSWeights();
	osoption->optimization->variables->sosVariableBranchingWeights->sos[parserData->numberOfSOS]->numberOfVar = (yyvsp[(3) - (4)].ival);
	osoption->optimization->variables->sosVariableBranchingWeights->sos[parserData->numberOfSOS]->var = new BranchingWeight*[(yyvsp[(3) - (4)].ival)];
	for (int i = 0; i < (yyvsp[(3) - (4)].ival); i++)
		osoption->optimization->variables->sosVariableBranchingWeights->sos[parserData->numberOfSOS]->var[i] = new BranchingWeight();
}
    break;

  case 515:

    {	if (!parserData->idxAttributePresent)
		osolerror (NULL, osoption, parserData, "variable index required");
	parserData->idxAttributePresent = false;
	parserData->valAttributePresent = false;
	parserData->numberOfSOSVar++;
}
    break;

  case 516:

    {	if (parserData->numberOfSOSVar >= osoption->optimization->variables->sosVariableBranchingWeights->sos[parserData->numberOfSOS]->numberOfVar)
		osolerror(NULL, osoption, parserData, "too many variable branching weights");
}
    break;

  case 521:

    {	if (parserData->idxAttributePresent)
		osolerror (NULL, osoption, parserData, "only one variable index allowed");
	parserData->idxAttributePresent = true;
	if ((yyvsp[(3) - (4)].ival) < 0)
		osolerror (NULL, osoption, parserData, "variable index must be nonnegative");
	if (parserData->numberOfVariablesPresent)
	{	if ((yyvsp[(3) - (4)].ival) >= parserData->numberOfVariables)
			osolerror (NULL, osoption, parserData, "variable index exceeds upper limit");
	};
	osoption->optimization->variables->sosVariableBranchingWeights->sos[parserData->numberOfSOS]->var[parserData->numberOfSOSVar]->idx = (yyvsp[(3) - (4)].ival);
}
    break;

  case 522:

    {	if (parserData->valAttributePresent)
		osolerror (NULL, osoption, parserData, "only one variable weight allowed");
	parserData->valAttributePresent = true;
	if (strcmp((yyvsp[(2) - (2)].sval),"INF") == 0)
		osoption->optimization->variables->sosVariableBranchingWeights->sos[parserData->numberOfSOS]->var[parserData->numberOfSOSVar]->value = OSDBL_MAX;
	else if (strcmp((yyvsp[(2) - (2)].sval),"-INF") == 0)
		osoption->optimization->variables->sosVariableBranchingWeights->sos[parserData->numberOfSOS]->var[parserData->numberOfSOSVar]->value = -OSDBL_MAX;
	else
		osoption->optimization->variables->sosVariableBranchingWeights->sos[parserData->numberOfSOS]->var[parserData->numberOfSOSVar]->value = os_strtod((yyvsp[(2) - (2)].sval), NULL);
}
    break;

  case 529:

    {	if (parserData->numberOfOtherVariableOptions >= osoption->optimization->variables->numberOfOtherVariableOptions)
		osolerror(NULL, osoption, parserData, "too many <other> variable options");
}
    break;

  case 539:

    { 	if (parserData->otherOptionNumberPresent)
		osolerror (NULL, osoption, parserData, "only one numberOfVar attribute allowed");
	parserData->otherOptionNumberPresent = true;
	parserData->numberOfVar = 0;
	if ((yyvsp[(3) - (4)].ival) < 0)
		osolerror (NULL, osoption, parserData, "number of <other> variable options must be nonnegative");
	osoption->optimization->variables->other[parserData->numberOfOtherVariableOptions]->numberOfVar = (yyvsp[(3) - (4)].ival);
	osoption->optimization->variables->other[parserData->numberOfOtherVariableOptions]->var = new OtherVarOption*[(yyvsp[(3) - (4)].ival)];
	for (int i = 0; i < (yyvsp[(3) - (4)].ival); i++)
		osoption->optimization->variables->other[parserData->numberOfOtherVariableOptions]->var[i] = new OtherVarOption();	
}
    break;

  case 540:

    {	if (parserData->otherOptionNamePresent)
		osolerror (NULL, osoption, parserData, "only one name attribute allowed");
	parserData->otherOptionNamePresent = true;
	osoption->optimization->variables->other[parserData->numberOfOtherVariableOptions]->name = (yyvsp[(2) - (2)].sval);
}
    break;

  case 542:

    {	if (parserData->otherOptionValuePresent)
		osolerror (NULL, osoption, parserData, "only one value attribute allowed");
	parserData->otherOptionValuePresent = true;
	osoption->optimization->variables->other[parserData->numberOfOtherVariableOptions]->value = (yyvsp[(2) - (2)].sval);
}
    break;

  case 544:

    {	if (parserData->otherOptionSolverPresent)
		osolerror (NULL, osoption, parserData, "only one solver attribute allowed");
	parserData->otherOptionSolverPresent = true;
	osoption->optimization->variables->other[parserData->numberOfOtherVariableOptions]->solver = (yyvsp[(2) - (2)].sval);
}
    break;

  case 546:

    {	if (parserData->otherOptionCategoryPresent)
		osolerror (NULL, osoption, parserData, "only one category attribute allowed");
	parserData->otherOptionCategoryPresent = true;
	osoption->optimization->variables->other[parserData->numberOfOtherVariableOptions]->category = (yyvsp[(2) - (2)].sval);
}
    break;

  case 548:

    {	if (parserData->otherOptionTypePresent)
		osolerror (NULL, osoption, parserData, "only one type attribute allowed");
	parserData->otherOptionTypePresent = true;
	osoption->optimization->variables->other[parserData->numberOfOtherVariableOptions]->type = (yyvsp[(2) - (2)].sval);
}
    break;

  case 550:

    {	if (parserData->otherOptionDescriptionPresent)
		osolerror (NULL, osoption, parserData, "only one description attribute allowed");
	parserData->otherOptionDescriptionPresent = true;
	osoption->optimization->variables->other[parserData->numberOfOtherVariableOptions]->description = (yyvsp[(2) - (2)].sval);
}
    break;

  case 552:

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

  case 555:

    {	if (!parserData->idxAttributePresent)
		osolerror(NULL, osoption, parserData, "required idx attribute was not found");
	parserData->idxAttributePresent = false;
	parserData->valAttributePresent = false;
	parserData->lbvalAttributePresent = false;
	parserData->ubvalAttributePresent = false;
	parserData->numberOfVar++;
}
    break;

  case 556:

    {	if (parserData->numberOfVar >= osoption->optimization->variables->other[parserData->numberOfOtherVariableOptions]->numberOfVar)
		osolerror(NULL, osoption, parserData, "too many <var> entries in <other> variable element");
}
    break;

  case 563:

    {	if (parserData->idxAttributePresent)
		osolerror (NULL, osoption, parserData, "only one variable index allowed");
	parserData->idxAttributePresent = true;
	if ((yyvsp[(3) - (4)].ival) < 0)
		osolerror (NULL, osoption, parserData, "variable index must be nonnegative");
	if (parserData->numberOfVariablesPresent)
	{	if ((yyvsp[(3) - (4)].ival) >= parserData->numberOfVariables)
			osolerror (NULL, osoption, parserData, "variable index exceeds upper limit");
	};
	osoption->optimization->variables->other[parserData->numberOfOtherVariableOptions]->var[parserData->numberOfVar]->idx = (yyvsp[(3) - (4)].ival);
}
    break;

  case 564:

    {	if (parserData->valAttributePresent)
		osolerror (NULL, osoption, parserData, "only one variable value allowed");
	parserData->valAttributePresent = true;
	osoption->optimization->variables->other[parserData->numberOfOtherVariableOptions]->var[parserData->numberOfVar]->value = (yyvsp[(2) - (2)].sval);
}
    break;

  case 566:

    {	if (parserData->lbvalAttributePresent)
		osolerror (NULL, osoption, parserData, "only one lower bound value allowed");
	parserData->lbvalAttributePresent = true;
	osoption->optimization->variables->other[parserData->numberOfOtherVariableOptions]->var[parserData->numberOfVar]->lbValue = (yyvsp[(2) - (2)].sval);
}
    break;

  case 568:

    {	if (parserData->ubvalAttributePresent)
		osolerror (NULL, osoption, parserData, "only one upper bound value allowed");
	parserData->ubvalAttributePresent = true;
	osoption->optimization->variables->other[parserData->numberOfOtherVariableOptions]->var[parserData->numberOfVar]->ubValue = (yyvsp[(2) - (2)].sval);
}
    break;

  case 574:

    {	osoption->optimization->objectives = new ObjectiveOption();
}
    break;

  case 576:

    {	if ((yyvsp[(3) - (4)].ival) < 0)
		osolerror (NULL, osoption, parserData, "number of <other> objective options cannot be negative");
	osoption->optimization->objectives->numberOfOtherObjectiveOptions = (yyvsp[(3) - (4)].ival);
	osoption->optimization->objectives->other = new OtherObjectiveOption*[(yyvsp[(3) - (4)].ival)];
	for (int i= 0; i < (yyvsp[(3) - (4)].ival); i++)
		osoption->optimization->objectives->other[i] = new OtherObjectiveOption();
}
    break;

  case 581:

    {	if ((yyvsp[(3) - (4)].ival) < 0)
		osolerror (NULL, osoption, parserData, "number of <obj> elements must be nonnegative");
	osoption->optimization->objectives->initialObjectiveValues = new InitObjectiveValues();
	osoption->optimization->objectives->initialObjectiveValues->numberOfObj = (yyvsp[(3) - (4)].ival);
	osoption->optimization->objectives->initialObjectiveValues->obj = new InitObjValue*[(yyvsp[(3) - (4)].ival)];
	for (int i = 0; i < (yyvsp[(3) - (4)].ival); i++)
		osoption->optimization->objectives->initialObjectiveValues->obj[i] = new InitObjValue();
}
    break;

  case 584:

    {	if (!parserData->idxAttributePresent)
		osolerror (NULL, osoption, parserData, "objective index required");
	parserData->idxAttributePresent = false;
	parserData->valAttributePresent = false;
	parserData->numberOfObjValues++;
}
    break;

  case 585:

    {	if (parserData->numberOfObjValues >= osoption->optimization->objectives->initialObjectiveValues->numberOfObj)
		osolerror(NULL, osoption, parserData, "too many initial objective values");
}
    break;

  case 590:

    {	if (parserData->idxAttributePresent)
		osolerror (NULL, osoption, parserData, "only one objective index allowed");
	parserData->idxAttributePresent = true;
	if ((yyvsp[(3) - (4)].ival) >= 0)
		osolerror (NULL, osoption, parserData, "objective index must be negative");
	if (parserData->numberOfObjectivesPresent)
	{	if (-(yyvsp[(3) - (4)].ival) > parserData->numberOfObjectives)
			osolerror (NULL, osoption, parserData, "objective index out of range");
	};
	osoption->optimization->objectives->initialObjectiveValues->obj[parserData->numberOfObjValues]->idx = (yyvsp[(3) - (4)].ival);
}
    break;

  case 591:

    {	if (parserData->valAttributePresent)
		osolerror (NULL, osoption, parserData, "only one objective value allowed");
	parserData->valAttributePresent = true;
	if (strcmp((yyvsp[(2) - (2)].sval),"INF") == 0)
		osoption->optimization->objectives->initialObjectiveValues->obj[parserData->numberOfObjValues]->value = OSDBL_MAX;
	else if (strcmp((yyvsp[(2) - (2)].sval),"-INF") == 0)
		osoption->optimization->objectives->initialObjectiveValues->obj[parserData->numberOfObjValues]->value = -OSDBL_MAX;
	else
		osoption->optimization->objectives->initialObjectiveValues->obj[parserData->numberOfObjValues]->value = os_strtod((yyvsp[(2) - (2)].sval), NULL);
}
    break;

  case 597:

    {	if ((yyvsp[(3) - (4)].ival) < 0)
		osolerror (NULL, osoption, parserData, "number of <obj> elements must be nonnegative");
	osoption->optimization->objectives->initialObjectiveBounds = new InitObjectiveBounds();
	osoption->optimization->objectives->initialObjectiveBounds->numberOfObj = (yyvsp[(3) - (4)].ival);
	osoption->optimization->objectives->initialObjectiveBounds->obj = new InitObjBound*[(yyvsp[(3) - (4)].ival)];
	for (int i = 0; i < (yyvsp[(3) - (4)].ival); i++)
		osoption->optimization->objectives->initialObjectiveBounds->obj[i] = new InitObjBound ();
}
    break;

  case 600:

    {	if (!parserData->idxAttributePresent)
		osolerror (NULL, osoption, parserData, "objective index required");
	parserData->idxAttributePresent = false;
	parserData->lbvalAttributePresent = false;
	parserData->ubvalAttributePresent = false;
	parserData->numberOfObjBounds++;
}
    break;

  case 601:

    {	if (parserData->numberOfObjBounds >= osoption->optimization->objectives->initialObjectiveBounds->numberOfObj)
		osolerror(NULL, osoption, parserData, "too many initial objective bounds");
}
    break;

  case 607:

    {	if (parserData->idxAttributePresent)
		osolerror (NULL, osoption, parserData, "only one objective index allowed");
	parserData->idxAttributePresent = true;
	if ((yyvsp[(3) - (4)].ival) >= 0)
		osolerror (NULL, osoption, parserData, "objective index must be negative");
	if (parserData->numberOfObjectivesPresent)
	{	if (-(yyvsp[(3) - (4)].ival) > parserData->numberOfObjectives)
			osolerror (NULL, osoption, parserData, "objective index out of range");
	};
	osoption->optimization->objectives->initialObjectiveBounds->obj[parserData->numberOfObjBounds]->idx = (yyvsp[(3) - (4)].ival);
}
    break;

  case 608:

    {	if (parserData->lbvalAttributePresent)
		osolerror (NULL, osoption, parserData, "only one objective lower bound allowed");
	parserData->lbvalAttributePresent = true;
	if (strcmp((yyvsp[(2) - (2)].sval),"INF") == 0)
		osoption->optimization->objectives->initialObjectiveBounds->obj[parserData->numberOfObjBounds]->lbValue = OSDBL_MAX;
	else if (strcmp((yyvsp[(2) - (2)].sval),"-INF") == 0)
		osoption->optimization->objectives->initialObjectiveBounds->obj[parserData->numberOfObjBounds]->lbValue = -OSDBL_MAX;
	else
		osoption->optimization->objectives->initialObjectiveBounds->obj[parserData->numberOfObjBounds]->lbValue = os_strtod((yyvsp[(2) - (2)].sval), NULL);
}
    break;

  case 610:

    {	if (parserData->ubvalAttributePresent)
		osolerror (NULL, osoption, parserData, "only one objective upper bound allowed");
	parserData->ubvalAttributePresent = true;
	if (strcmp((yyvsp[(2) - (2)].sval),"INF") == 0)
		osoption->optimization->objectives->initialObjectiveBounds->obj[parserData->numberOfObjBounds]->ubValue = OSDBL_MAX;
	else if (strcmp((yyvsp[(2) - (2)].sval),"-INF") == 0)
		osoption->optimization->objectives->initialObjectiveBounds->obj[parserData->numberOfObjBounds]->ubValue = -OSDBL_MAX;
	else
		osoption->optimization->objectives->initialObjectiveBounds->obj[parserData->numberOfObjBounds]->ubValue = os_strtod((yyvsp[(2) - (2)].sval), NULL);
}
    break;

  case 617:

    {	if (parserData->numberOfOtherObjectiveOptions >= osoption->optimization->objectives->numberOfOtherObjectiveOptions)
		osolerror(NULL, osoption, parserData, "too many <other> objective options");
}
    break;

  case 627:

    { 	if (parserData->otherOptionNumberPresent)
		osolerror (NULL, osoption, parserData, "only one numberOfObj attribute allowed");
	parserData->otherOptionNumberPresent = true;
	parserData->numberOfObj = 0;
	if ((yyvsp[(3) - (4)].ival) < 0)
		osolerror (NULL, osoption, parserData, "number of <other> objective options must be nonnegative");
	osoption->optimization->objectives->other[parserData->numberOfOtherObjectiveOptions]->numberOfObj = (yyvsp[(3) - (4)].ival);
	osoption->optimization->objectives->other[parserData->numberOfOtherObjectiveOptions]->obj = new OtherObjOption*[(yyvsp[(3) - (4)].ival)];
	for (int i = 0; i < (yyvsp[(3) - (4)].ival); i++)
		osoption->optimization->objectives->other[parserData->numberOfOtherObjectiveOptions]->obj[i] = new OtherObjOption();
}
    break;

  case 628:

    {	if (parserData->otherOptionNamePresent)
		osolerror (NULL, osoption, parserData, "only one name attribute allowed");
	parserData->otherOptionNamePresent = true;
	osoption->optimization->objectives->other[parserData->numberOfOtherObjectiveOptions]->name = (yyvsp[(2) - (2)].sval);
}
    break;

  case 630:

    {	if (parserData->otherOptionValuePresent)
		osolerror (NULL, osoption, parserData, "only one value attribute allowed");
	parserData->otherOptionValuePresent = true;
	osoption->optimization->objectives->other[parserData->numberOfOtherObjectiveOptions]->value = (yyvsp[(2) - (2)].sval);
}
    break;

  case 632:

    {	if (parserData->otherOptionSolverPresent)
		osolerror (NULL, osoption, parserData, "only one solver attribute allowed");
	parserData->otherOptionSolverPresent = true;
	osoption->optimization->objectives->other[parserData->numberOfOtherObjectiveOptions]->solver = (yyvsp[(2) - (2)].sval);
}
    break;

  case 634:

    {	if (parserData->otherOptionCategoryPresent)
		osolerror (NULL, osoption, parserData, "only one category attribute allowed");
	parserData->otherOptionCategoryPresent = true;
	osoption->optimization->objectives->other[parserData->numberOfOtherObjectiveOptions]->category = (yyvsp[(2) - (2)].sval);
}
    break;

  case 636:

    {	if (parserData->otherOptionTypePresent)
		osolerror (NULL, osoption, parserData, "only one type attribute allowed");
	parserData->otherOptionTypePresent = true;
	osoption->optimization->objectives->other[parserData->numberOfOtherObjectiveOptions]->type = (yyvsp[(2) - (2)].sval);
}
    break;

  case 638:

    {	if (parserData->otherOptionDescriptionPresent)
		osolerror (NULL, osoption, parserData, "only one description attribute allowed");
	parserData->otherOptionDescriptionPresent = true;
	osoption->optimization->objectives->other[parserData->numberOfOtherObjectiveOptions]->description = (yyvsp[(2) - (2)].sval);
}
    break;

  case 640:

    { 	if (parserData->numberOfObj < osoption->optimization->objectives->other[parserData->numberOfOtherObjectiveOptions]->numberOfObj)
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

  case 643:

    {	if (!parserData->idxAttributePresent)
		osolerror(NULL, osoption, parserData, "required idx attribute was not found");
	parserData->idxAttributePresent = false;
	parserData->valAttributePresent = false;
	parserData->lbvalAttributePresent = false;
	parserData->ubvalAttributePresent = false;
	parserData->numberOfObj++;
}
    break;

  case 644:

    {	if (parserData->numberOfObj >= osoption->optimization->objectives->other[parserData->numberOfOtherObjectiveOptions]->numberOfObj)
		osolerror(NULL, osoption, parserData, "too many <obj> entries in <other> objective element");
}
    break;

  case 651:

    {	if (parserData->idxAttributePresent)
		osolerror (NULL, osoption, parserData, "only one objective index allowed");
	parserData->idxAttributePresent = true;
	if ((yyvsp[(3) - (4)].ival) >= 0)
		osolerror (NULL, osoption, parserData, "objective index must be negative");
	if (parserData->numberOfObjectivesPresent)
	{	if (-(yyvsp[(3) - (4)].ival) > parserData->numberOfObjectives)
			osolerror (NULL, osoption, parserData, "objective index exceeds upper limit");
	};
	osoption->optimization->objectives->other[parserData->numberOfOtherObjectiveOptions]->obj[parserData->numberOfObj]->idx = (yyvsp[(3) - (4)].ival);
}
    break;

  case 652:

    {	if (parserData->valAttributePresent)
		osolerror (NULL, osoption, parserData, "only one variable value allowed");
	parserData->valAttributePresent = true;
	osoption->optimization->objectives->other[parserData->numberOfOtherObjectiveOptions]->obj[parserData->numberOfObj]->value = (yyvsp[(2) - (2)].sval);
}
    break;

  case 654:

    {	if (parserData->lbvalAttributePresent)
		osolerror (NULL, osoption, parserData, "only one lower bound value allowed");
	parserData->lbvalAttributePresent = true;
	osoption->optimization->objectives->other[parserData->numberOfOtherObjectiveOptions]->obj[parserData->numberOfObj]->lbValue = (yyvsp[(2) - (2)].sval);
}
    break;

  case 656:

    {	if (parserData->ubvalAttributePresent)
		osolerror (NULL, osoption, parserData, "only one upper bound value allowed");
	parserData->ubvalAttributePresent = true;
	osoption->optimization->objectives->other[parserData->numberOfOtherObjectiveOptions]->obj[parserData->numberOfObj]->ubValue = (yyvsp[(2) - (2)].sval);
}
    break;

  case 662:

    {	osoption->optimization->constraints = new ConstraintOption();
}
    break;

  case 664:

    {	if ((yyvsp[(3) - (4)].ival) < 0)
		osolerror (NULL, osoption, parserData, "number of <other> constraint options cannot be negative");
        osoption->optimization->constraints->numberOfOtherConstraintOptions = (yyvsp[(3) - (4)].ival);
	osoption->optimization->constraints->other = new OtherConstraintOption*[(yyvsp[(3) - (4)].ival)];
	for (int i= 0; i < (yyvsp[(3) - (4)].ival); i++)
		osoption->optimization->constraints->other[i] = new OtherConstraintOption();
}
    break;

  case 669:

    {	if ((yyvsp[(3) - (4)].ival) < 0)
		osolerror (NULL, osoption, parserData, "number of <con> elements must be nonnegative");
	osoption->optimization->constraints->initialConstraintValues = new InitConstraintValues();
	osoption->optimization->constraints->initialConstraintValues->numberOfCon = (yyvsp[(3) - (4)].ival);
	osoption->optimization->constraints->initialConstraintValues->con = new InitConValue*[(yyvsp[(3) - (4)].ival)];
	for (int i = 0; i < (yyvsp[(3) - (4)].ival); i++)
		osoption->optimization->constraints->initialConstraintValues->con[i] = new InitConValue();
}
    break;

  case 672:

    {	if (!parserData->idxAttributePresent)
		osolerror (NULL, osoption, parserData, "variable index required");
	parserData->idxAttributePresent = false;
	parserData->valAttributePresent = false;
	parserData->numberOfCon++;
}
    break;

  case 673:

    {	if (parserData->numberOfCon >= osoption->optimization->constraints->initialConstraintValues->numberOfCon)
		osolerror(NULL, osoption, parserData, "too many initial constraint values");
}
    break;

  case 678:

    {	if (parserData->idxAttributePresent)
		osolerror (NULL, osoption, parserData, "only one constraint index allowed");
	parserData->idxAttributePresent = true;
	if ((yyvsp[(3) - (4)].ival) < 0)
		osolerror (NULL, osoption, parserData, "constraint index must be nonnegative");
	if (parserData->numberOfConstraintsPresent)
	{	if ((yyvsp[(3) - (4)].ival) > parserData->numberOfConstraints)
			osolerror (NULL, osoption, parserData, "constraint index out of range");
	};
	osoption->optimization->constraints->initialConstraintValues->con[parserData->numberOfCon]->idx = (yyvsp[(3) - (4)].ival);
}
    break;

  case 679:

    {	if (parserData->valAttributePresent)
		osolerror (NULL, osoption, parserData, "only one constraint value allowed");
	parserData->valAttributePresent = true;
	if (strcmp((yyvsp[(2) - (2)].sval),"INF") == 0)
		osoption->optimization->constraints->initialConstraintValues->con[parserData->numberOfCon]->value = OSDBL_MAX;
	else if (strcmp((yyvsp[(2) - (2)].sval),"-INF") == 0)
		osoption->optimization->constraints->initialConstraintValues->con[parserData->numberOfCon]->value = -OSDBL_MAX;
	else
		osoption->optimization->constraints->initialConstraintValues->con[parserData->numberOfCon]->value = os_strtod((yyvsp[(2) - (2)].sval), NULL);
}
    break;

  case 685:

    {	if ((yyvsp[(3) - (4)].ival) < 0)
		osolerror (NULL, osoption, parserData, "number of <con> elements must be nonnegative");
	osoption->optimization->constraints->initialDualValues = new InitDualVariableValues();
	osoption->optimization->constraints->initialDualValues->numberOfCon = (yyvsp[(3) - (4)].ival);
	osoption->optimization->constraints->initialDualValues->con = new InitDualVarValue*[(yyvsp[(3) - (4)].ival)];
	for (int i = 0; i < (yyvsp[(3) - (4)].ival); i++)
		osoption->optimization->constraints->initialDualValues->con[i] = new InitDualVarValue ();
}
    break;

  case 688:

    {	if (!parserData->idxAttributePresent)
		osolerror (NULL, osoption, parserData, "constraint index required");
	parserData->idxAttributePresent = false;
	parserData->lbvalAttributePresent = false;
	parserData->ubvalAttributePresent = false;
	parserData->numberOfDuals++;
}
    break;

  case 689:

    {	if (parserData->numberOfDuals >= osoption->optimization->constraints->initialDualValues->numberOfCon)
		osolerror(NULL, osoption, parserData, "too many initial dual variable bounds");
}
    break;

  case 695:

    {	if (parserData->idxAttributePresent)
		osolerror (NULL, osoption, parserData, "only one constraint index allowed");
	parserData->idxAttributePresent = true;
	if ((yyvsp[(3) - (4)].ival) < 0)
		osolerror (NULL, osoption, parserData, "constraint index must be nonnegative");
	if (parserData->numberOfConstraintsPresent)
	{	if ((yyvsp[(3) - (4)].ival) > parserData->numberOfConstraints)
			osolerror (NULL, osoption, parserData, "constraint index out of range");
	};
	osoption->optimization->constraints->initialDualValues->con[parserData->numberOfDuals]->idx = (yyvsp[(3) - (4)].ival);
}
    break;

  case 696:

    {	if (parserData->lbvalAttributePresent)
		osolerror (NULL, osoption, parserData, "only one dual variable lower bound allowed");
	parserData->lbvalAttributePresent = true;
	if (strcmp((yyvsp[(2) - (2)].sval),"INF") == 0)
		osoption->optimization->constraints->initialDualValues->con[parserData->numberOfDuals]->lbDualValue = OSDBL_MAX;
	else if (strcmp((yyvsp[(2) - (2)].sval),"-INF") == 0)
		osoption->optimization->constraints->initialDualValues->con[parserData->numberOfDuals]->lbDualValue = -OSDBL_MAX;
	else
		osoption->optimization->constraints->initialDualValues->con[parserData->numberOfDuals]->lbDualValue = os_strtod((yyvsp[(2) - (2)].sval), NULL);
}
    break;

  case 698:

    {	if (parserData->ubvalAttributePresent)
		osolerror (NULL, osoption, parserData, "only one dual variable upper bound allowed");
	parserData->ubvalAttributePresent = true;
	if (strcmp((yyvsp[(2) - (2)].sval),"INF") == 0)
		osoption->optimization->constraints->initialDualValues->con[parserData->numberOfDuals]->ubDualValue = OSDBL_MAX;
	else if (strcmp((yyvsp[(2) - (2)].sval),"-INF") == 0)
		osoption->optimization->constraints->initialDualValues->con[parserData->numberOfDuals]->ubDualValue = -OSDBL_MAX;
	else
		osoption->optimization->constraints->initialDualValues->con[parserData->numberOfDuals]->ubDualValue = os_strtod((yyvsp[(2) - (2)].sval), NULL);
}
    break;

  case 705:

    {	if (parserData->numberOfOtherConstraintOptions >= osoption->optimization->constraints->numberOfOtherConstraintOptions)
		osolerror(NULL, osoption, parserData, "too many <other> constraint options");
}
    break;

  case 715:

    { 	if (parserData->otherOptionNumberPresent)
		osolerror (NULL, osoption, parserData, "only one numberOfCon attribute allowed");
	parserData->otherOptionNumberPresent = true;
	parserData->numberOfCon = 0;
	if ((yyvsp[(3) - (4)].ival) < 0)
		osolerror (NULL, osoption, parserData, "number of <other> constraint options must be nonnegative");
	osoption->optimization->constraints->other[parserData->numberOfOtherConstraintOptions]->numberOfCon = (yyvsp[(3) - (4)].ival);
	osoption->optimization->constraints->other[parserData->numberOfOtherConstraintOptions]->con = new OtherConOption*[(yyvsp[(3) - (4)].ival)];
	for (int i = 0; i < (yyvsp[(3) - (4)].ival); i++)
		osoption->optimization->constraints->other[parserData->numberOfOtherConstraintOptions]->con[i] = new OtherConOption();
}
    break;

  case 716:

    {	if (parserData->otherOptionNamePresent)
		osolerror (NULL, osoption, parserData, "only one name attribute allowed");
	parserData->otherOptionNamePresent = true;
	osoption->optimization->constraints->other[parserData->numberOfOtherConstraintOptions]->name = (yyvsp[(2) - (2)].sval);
}
    break;

  case 718:

    {	if (parserData->otherOptionValuePresent)
		osolerror (NULL, osoption, parserData, "only one value attribute allowed");
	parserData->otherOptionValuePresent = true;
	osoption->optimization->constraints->other[parserData->numberOfOtherConstraintOptions]->value = (yyvsp[(2) - (2)].sval);
}
    break;

  case 720:

    {	if (parserData->otherOptionSolverPresent)
		osolerror (NULL, osoption, parserData, "only one solver attribute allowed");
	parserData->otherOptionSolverPresent = true;
	osoption->optimization->constraints->other[parserData->numberOfOtherConstraintOptions]->solver = (yyvsp[(2) - (2)].sval);
}
    break;

  case 722:

    {	if (parserData->otherOptionCategoryPresent)
		osolerror (NULL, osoption, parserData, "only one category attribute allowed");
	parserData->otherOptionCategoryPresent = true;
	osoption->optimization->constraints->other[parserData->numberOfOtherConstraintOptions]->category = (yyvsp[(2) - (2)].sval);
}
    break;

  case 724:

    {	if (parserData->otherOptionTypePresent)
		osolerror (NULL, osoption, parserData, "only one type attribute allowed");
	parserData->otherOptionTypePresent = true;
	osoption->optimization->constraints->other[parserData->numberOfOtherConstraintOptions]->type = (yyvsp[(2) - (2)].sval);
}
    break;

  case 726:

    {	if (parserData->otherOptionDescriptionPresent)
		osolerror (NULL, osoption, parserData, "only one description attribute allowed");
	parserData->otherOptionDescriptionPresent = true;
	osoption->optimization->constraints->other[parserData->numberOfOtherConstraintOptions]->description = (yyvsp[(2) - (2)].sval);
}
    break;

  case 728:

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

  case 731:

    {	if (!parserData->idxAttributePresent)
		osolerror(NULL, osoption, parserData, "required idx attribute was not found");
	parserData->idxAttributePresent = false;
	parserData->valAttributePresent = false;
	parserData->lbvalAttributePresent = false;
	parserData->ubvalAttributePresent = false;
	parserData->numberOfCon++;
}
    break;

  case 732:

    {	if (parserData->numberOfCon >= osoption->optimization->constraints->other[parserData->numberOfOtherConstraintOptions]->numberOfCon)
		osolerror(NULL, osoption, parserData, "too many <con> entries in <other> constraint element");
}
    break;

  case 739:

    {	if (parserData->idxAttributePresent)
		osolerror (NULL, osoption, parserData, "only one constraint index allowed");
	parserData->idxAttributePresent = true;
	if ((yyvsp[(3) - (4)].ival) < 0)
		osolerror (NULL, osoption, parserData, "constraint index must be nonnegative");
	if (parserData->numberOfConstraintsPresent)
	{	if ((yyvsp[(3) - (4)].ival) >= parserData->numberOfConstraints)
			osolerror (NULL, osoption, parserData, "constraint index exceeds upper limit");
	};
	osoption->optimization->constraints->other[parserData->numberOfOtherConstraintOptions]->con[parserData->numberOfCon]->idx = (yyvsp[(3) - (4)].ival);
}
    break;

  case 740:

    {	if (parserData->valAttributePresent)
		osolerror (NULL, osoption, parserData, "only one constraint value allowed");
	parserData->valAttributePresent = true;
	osoption->optimization->constraints->other[parserData->numberOfOtherConstraintOptions]->con[parserData->numberOfCon]->value = (yyvsp[(2) - (2)].sval);
}
    break;

  case 742:

    {	if (parserData->lbvalAttributePresent)
		osolerror (NULL, osoption, parserData, "only one lower bound value allowed");
	parserData->lbvalAttributePresent = true;
	osoption->optimization->constraints->other[parserData->numberOfOtherConstraintOptions]->con[parserData->numberOfCon]->lbValue = (yyvsp[(2) - (2)].sval);
}
    break;

  case 744:

    {	if (parserData->ubvalAttributePresent)
		osolerror (NULL, osoption, parserData, "only one upper bound value allowed");
	parserData->ubvalAttributePresent = true;
	osoption->optimization->constraints->other[parserData->numberOfOtherConstraintOptions]->con[parserData->numberOfCon]->ubValue = (yyvsp[(2) - (2)].sval);
}
    break;

  case 749:

    {	if (parserData->numberOfSolverOptions != osoption->optimization->solverOptions->numberOfSolverOptions)
		osolerror (NULL, osoption, parserData, "wrong number of solver options in <optimization> element");
}
    break;

  case 750:

    {	if (parserData->solverOptionsPresent)
	{	osolerror( NULL, osoption, parserData, "only one <solverOptions> element allowed");
	}
	else
	{	parserData->solverOptionsPresent = true;
		osoption->optimization->solverOptions = new SolverOptions();
	}
}
    break;

  case 751:

    {	if ((yyvsp[(3) - (4)].ival) < 0)
		osolerror (NULL, osoption, parserData, "number of solver options cannot be negative");
	osoption->optimization->solverOptions->numberOfSolverOptions = (yyvsp[(3) - (4)].ival);
	osoption->optimization->solverOptions->solverOption = new SolverOption*[(yyvsp[(3) - (4)].ival)];
	for (int i=0; i < (yyvsp[(3) - (4)].ival); i++) osoption->optimization->solverOptions->solverOption[i] = new SolverOption();
}
    break;

  case 754:

    {	if (parserData->numberOfSolverOptions >= osoption->optimization->solverOptions->numberOfSolverOptions)
	{	osolerror (NULL, osoption, parserData, "too many solver options in <optimization> element");
	};
}
    break;

  case 755:

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

  case 764:

    {	if (parserData->solverOptionNamePresent)
	{	osolerror( NULL, osoption, parserData, "only one name attribute allowed");
	}
	else
	{	parserData->solverOptionNamePresent = true;
		osoption->optimization->solverOptions->solverOption[parserData->numberOfSolverOptions]->name = (yyvsp[(2) - (2)].sval);
	}
}
    break;

  case 766:

    {	if (parserData->solverOptionValuePresent)
	{	osolerror( NULL, osoption, parserData, "only one value attribute allowed");
	}
	else
	{	parserData->solverOptionValuePresent = true;
		osoption->optimization->solverOptions->solverOption[parserData->numberOfSolverOptions]->value = (yyvsp[(2) - (2)].sval);
	}
}
    break;

  case 768:

    {	if (parserData->solverOptionSolverPresent)
	{	osolerror( NULL, osoption, parserData, "only one solver attribute allowed");
	}
	else
	{	parserData->solverOptionSolverPresent = true;
		osoption->optimization->solverOptions->solverOption[parserData->numberOfSolverOptions]->solver = (yyvsp[(2) - (2)].sval);
	}
}
    break;

  case 770:

    {	if (parserData->solverOptionCategoryPresent)
	{	osolerror( NULL, osoption, parserData, "only one category attribute allowed");
	}
	else
	{	parserData->solverOptionCategoryPresent = true;
		osoption->optimization->solverOptions->solverOption[parserData->numberOfSolverOptions]->category = (yyvsp[(2) - (2)].sval);
	}
}
    break;

  case 772:

    {	if (parserData->solverOptionTypePresent)
	{	osolerror( NULL, osoption, parserData, "only one type attribute allowed");
	}
	else
	{	parserData->solverOptionTypePresent = true;
		osoption->optimization->solverOptions->solverOption[parserData->numberOfSolverOptions]->type = (yyvsp[(2) - (2)].sval);
	}
}
    break;

  case 774:

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


