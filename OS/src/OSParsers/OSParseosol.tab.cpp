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
     REQUESTEDSTARTTIMESTART = 350,
     REQUESTEDSTARTTIMEEND = 351,
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
#define REQUESTEDSTARTTIMESTART 350
#define REQUESTEDSTARTTIMEEND 351
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
#define YYFINAL  6
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   798

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  164
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  522
/* YYNRULES -- Number of rules.  */
#define YYNRULES  775
/* YYNRULES -- Number of states.  */
#define YYNSTATES  1300

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
       0,     0,     3,     7,    10,    12,    16,    22,    23,    26,
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
     331,   334,   338,   342,   346,   348,   349,   350,   355,   357,
     360,   364,   368,   372,   374,   375,   376,   381,   383,   386,
     390,   394,   397,   399,   401,   404,   405,   410,   415,   417,
     422,   425,   426,   429,   430,   435,   436,   439,   441,   443,
     445,   446,   451,   452,   457,   458,   463,   465,   468,   469,
     472,   474,   478,   480,   481,   484,   486,   488,   491,   493,
     495,   498,   499,   504,   509,   511,   516,   519,   520,   523,
     524,   529,   530,   533,   535,   537,   539,   540,   545,   546,
     551,   552,   557,   559,   562,   563,   566,   568,   572,   574,
     575,   578,   580,   582,   584,   586,   588,   590,   592,   594,
     596,   598,   600,   602,   604,   606,   608,   612,   614,   615,
     616,   621,   623,   626,   630,   634,   637,   639,   641,   644,
     645,   650,   656,   658,   663,   664,   667,   668,   674,   680,
     682,   687,   688,   691,   692,   698,   704,   706,   711,   712,
     715,   716,   722,   728,   730,   735,   736,   739,   740,   746,
     752,   754,   759,   760,   763,   764,   770,   776,   778,   783,
     784,   787,   791,   793,   794,   797,   799,   801,   803,   804,
     809,   810,   815,   816,   821,   824,   826,   832,   834,   839,
     840,   843,   847,   849,   850,   853,   855,   857,   859,   860,
     865,   866,   871,   872,   877,   880,   882,   888,   890,   895,
     896,   899,   903,   905,   906,   909,   911,   913,   915,   916,
     921,   922,   927,   928,   933,   936,   938,   944,   946,   951,
     952,   955,   959,   961,   962,   965,   967,   969,   971,   972,
     977,   978,   983,   984,   989,   992,   994,  1000,  1002,  1007,
    1008,  1011,  1012,  1018,  1024,  1026,  1031,  1032,  1035,  1036,
    1042,  1048,  1050,  1055,  1056,  1059,  1060,  1066,  1071,  1073,
    1078,  1081,  1082,  1085,  1086,  1091,  1092,  1095,  1097,  1099,
    1101,  1102,  1107,  1108,  1113,  1114,  1119,  1121,  1124,  1125,
    1129,  1131,  1132,  1135,  1137,  1139,  1141,  1146,  1151,  1156,
    1160,  1162,  1167,  1168,  1172,  1174,  1175,  1180,  1189,  1191,
    1192,  1198,  1203,  1204,  1207,  1211,  1213,  1214,  1217,  1219,
    1221,  1226,  1227,  1232,  1235,  1237,  1238,  1244,  1249,  1250,
    1253,  1257,  1259,  1260,  1263,  1265,  1267,  1272,  1273,  1278,
    1281,  1283,  1284,  1290,  1295,  1296,  1299,  1303,  1305,  1306,
    1309,  1311,  1313,  1318,  1319,  1324,  1327,  1329,  1330,  1336,
    1341,  1342,  1345,  1349,  1351,  1352,  1355,  1357,  1359,  1364,
    1365,  1370,  1373,  1375,  1376,  1382,  1387,  1388,  1391,  1395,
    1397,  1398,  1401,  1403,  1405,  1407,  1412,  1417,  1422,  1427,
    1431,  1433,  1434,  1437,  1441,  1443,  1444,  1447,  1449,  1451,
    1456,  1457,  1462,  1465,  1467,  1468,  1471,  1475,  1477,  1478,
    1481,  1483,  1485,  1487,  1489,  1491,  1493,  1495,  1500,  1501,
    1506,  1507,  1512,  1513,  1518,  1519,  1524,  1525,  1530,  1531,
    1536,  1540,  1541,  1544,  1548,  1550,  1551,  1554,  1556,  1558,
    1560,  1562,  1567,  1568,  1573,  1574,  1579,  1580,  1585,  1588,
    1590,  1591,  1595,  1597,  1598,  1603,  1609,  1611,  1612,  1618,
    1623,  1624,  1627,  1631,  1633,  1634,  1637,  1639,  1641,  1646,
    1647,  1652,  1655,  1657,  1658,  1664,  1669,  1670,  1673,  1677,
    1679,  1680,  1683,  1685,  1687,  1689,  1694,  1695,  1700,  1701,
    1706,  1709,  1711,  1712,  1715,  1719,  1721,  1722,  1725,  1727,
    1729,  1731,  1733,  1735,  1737,  1739,  1744,  1745,  1750,  1751,
    1756,  1757,  1762,  1763,  1768,  1769,  1774,  1775,  1780,  1784,
    1785,  1788,  1792,  1794,  1795,  1798,  1800,  1802,  1804,  1806,
    1811,  1812,  1817,  1818,  1823,  1824,  1829,  1832,  1834,  1835,
    1839,  1841,  1842,  1847,  1853,  1855,  1856,  1862,  1867,  1868,
    1871,  1875,  1877,  1878,  1881,  1883,  1885,  1890,  1891,  1896,
    1899,  1901,  1902,  1908,  1913,  1914,  1917,  1921,  1923,  1924,
    1927,  1929,  1931,  1933,  1938,  1939,  1944,  1945,  1950,  1953,
    1955,  1956,  1959,  1963,  1965,  1966,  1969,  1971,  1973,  1975,
    1977,  1979,  1981,  1983,  1988,  1989,  1994,  1995,  2000,  2001,
    2006,  2007,  2012,  2013,  2018,  2019,  2024,  2028,  2029,  2032,
    2036,  2038,  2039,  2042,  2044,  2046,  2048,  2050,  2055,  2056,
    2061,  2062,  2067,  2068,  2073,  2076,  2078,  2079,  2085,  2087,
    2092,  2093,  2096,  2097,  2102,  2103,  2106,  2108,  2110,  2112,
    2114,  2116,  2118,  2119,  2124,  2125,  2130,  2131,  2136,  2137,
    2142,  2143,  2148,  2149,  2154,  2157
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     165,     0,    -1,   166,   167,    13,    -1,   166,     9,    -1,
      11,    -1,    10,    12,     8,    -1,   168,   233,   273,   298,
     436,    -1,    -1,   169,   170,    -1,    49,    -1,     8,   171,
      50,    -1,     9,    -1,    -1,   171,   172,    -1,   173,    -1,
     177,    -1,   181,    -1,   185,    -1,   191,    -1,   195,    -1,
     199,    -1,   203,    -1,   207,    -1,   211,    -1,   217,    -1,
     174,   175,    -1,    59,    -1,     9,    -1,     8,    60,    -1,
      -1,     8,     4,   176,    60,    -1,   178,   179,    -1,    61,
      -1,     9,    -1,     8,    62,    -1,    -1,     8,     4,   180,
      62,    -1,   182,   183,    -1,    63,    -1,     9,    -1,     8,
      64,    -1,    -1,     8,     4,   184,    64,    -1,   186,   187,
     189,    -1,    65,    -1,    -1,    -1,    14,     3,   188,     7,
      -1,     9,    -1,     8,   190,    66,    -1,    -1,     4,    -1,
     192,   193,    -1,    67,    -1,     9,    -1,     8,    68,    -1,
      -1,     8,     4,   194,    68,    -1,   196,   197,    -1,    69,
      -1,     9,    -1,     8,    70,    -1,    -1,     8,     4,   198,
      70,    -1,   200,   201,    -1,    71,    -1,     9,    -1,     8,
      72,    -1,    -1,     8,     4,   202,    72,    -1,   204,   205,
      -1,    73,    -1,     9,    -1,     8,    74,    -1,    -1,     8,
       4,   206,    74,    -1,   208,   209,    -1,    75,    -1,     9,
      -1,     8,    76,    -1,    -1,     8,     4,   210,    76,    -1,
     212,   213,   215,    -1,    77,    -1,    -1,    -1,    15,     3,
     214,     7,    -1,     9,    -1,     8,   216,    78,    -1,    -1,
       4,    -1,   218,   219,     8,   220,    -1,    79,    -1,    16,
       7,     5,     7,    -1,   221,    80,    -1,    -1,   221,   222,
      -1,    -1,    81,   223,   224,   232,    -1,    -1,   224,   225,
      -1,   226,    -1,   228,    -1,   230,    -1,    -1,    39,     3,
     227,     7,    -1,    -1,    42,     3,   229,     7,    -1,    -1,
      44,     3,   231,     7,    -1,     9,    -1,     8,    82,    -1,
      -1,   234,   235,    -1,    51,    -1,     8,   236,    52,    -1,
       9,    -1,    -1,   236,   237,    -1,   238,    -1,   243,    -1,
     248,    -1,   253,    -1,   257,    -1,   239,   240,   242,    -1,
      83,    -1,    -1,    -1,    43,     3,   241,     7,    -1,     9,
      -1,     8,    84,    -1,     8,     6,    84,    -1,     8,     5,
      84,    -1,   244,   245,   247,    -1,    85,    -1,    -1,    -1,
      43,     3,   246,     7,    -1,     9,    -1,     8,    86,    -1,
       8,     6,    86,    -1,     8,     5,    86,    -1,   249,   250,
     252,    -1,    87,    -1,    -1,    -1,    43,     3,   251,     7,
      -1,     9,    -1,     8,    88,    -1,     8,     6,    88,    -1,
       8,     5,    88,    -1,   254,   255,    -1,    89,    -1,     9,
      -1,     8,    90,    -1,    -1,     8,     5,   256,    90,    -1,
     258,   259,     8,   260,    -1,    79,    -1,    16,     7,     5,
       7,    -1,   261,    80,    -1,    -1,   261,   262,    -1,    -1,
      81,   263,   264,   272,    -1,    -1,   264,   265,    -1,   266,
      -1,   268,    -1,   270,    -1,    -1,    39,     3,   267,     7,
      -1,    -1,    42,     3,   269,     7,    -1,    -1,    44,     3,
     271,     7,    -1,     9,    -1,     8,    82,    -1,    -1,   274,
     275,    -1,    53,    -1,     8,   276,    54,    -1,     9,    -1,
      -1,   276,   277,    -1,   278,    -1,   282,    -1,   279,   280,
      -1,    91,    -1,     9,    -1,     8,    92,    -1,    -1,     8,
       4,   281,    92,    -1,   283,   284,     8,   285,    -1,    79,
      -1,    16,     7,     5,     7,    -1,   286,    80,    -1,    -1,
     286,   287,    -1,    -1,    81,   288,   289,   297,    -1,    -1,
     289,   290,    -1,   291,    -1,   293,    -1,   295,    -1,    -1,
      39,     3,   292,     7,    -1,    -1,    42,     3,   294,     7,
      -1,    -1,    44,     3,   296,     7,    -1,     9,    -1,     8,
      82,    -1,    -1,   299,   300,    -1,    55,    -1,     8,   301,
      56,    -1,     9,    -1,    -1,   301,   302,    -1,   303,    -1,
     308,    -1,   312,    -1,   318,    -1,   324,    -1,   330,    -1,
     336,    -1,   342,    -1,   357,    -1,   372,    -1,   387,    -1,
     402,    -1,   408,    -1,   414,    -1,   420,    -1,   304,   305,
     307,    -1,    93,    -1,    -1,    -1,    43,     3,   306,     7,
      -1,     9,    -1,     8,    94,    -1,     8,     6,    94,    -1,
       8,     5,    94,    -1,   309,   310,    -1,    95,    -1,     9,
      -1,     8,    96,    -1,    -1,     8,     4,   311,    96,    -1,
     313,   314,     8,   315,    98,    -1,    97,    -1,    17,     7,
       5,     7,    -1,    -1,   315,   316,    -1,    -1,    67,     8,
       4,   317,    68,    -1,   319,   320,     8,   321,   100,    -1,
      99,    -1,    18,     7,     5,     7,    -1,    -1,   321,   322,
      -1,    -1,   103,     8,     4,   323,   104,    -1,   325,   326,
       8,   327,   102,    -1,   101,    -1,    18,     7,     5,     7,
      -1,    -1,   327,   328,    -1,    -1,   103,     8,     4,   329,
     104,    -1,   331,   332,     8,   333,   108,    -1,   107,    -1,
      18,     7,     5,     7,    -1,    -1,   333,   334,    -1,    -1,
     103,     8,     4,   335,   104,    -1,   337,   338,     8,   339,
     110,    -1,   109,    -1,    18,     7,     5,     7,    -1,    -1,
     339,   340,    -1,    -1,   103,     8,     4,   341,   104,    -1,
     343,   344,     8,   345,   116,    -1,   115,    -1,    19,     7,
       5,     7,    -1,    -1,   345,   346,    -1,   347,   348,   356,
      -1,   105,    -1,    -1,   348,   349,    -1,   350,    -1,   352,
      -1,   354,    -1,    -1,    20,     3,   351,     7,    -1,    -1,
      21,     3,   353,     7,    -1,    -1,    22,     3,   355,     7,
      -1,     8,   106,    -1,     9,    -1,   358,   359,     8,   360,
     118,    -1,   117,    -1,    19,     7,     5,     7,    -1,    -1,
     360,   361,    -1,   362,   363,   371,    -1,   105,    -1,    -1,
     363,   364,    -1,   365,    -1,   367,    -1,   369,    -1,    -1,
      20,     3,   366,     7,    -1,    -1,    21,     3,   368,     7,
      -1,    -1,    22,     3,   370,     7,    -1,     8,   106,    -1,
       9,    -1,   373,   374,     8,   375,   120,    -1,   119,    -1,
      19,     7,     5,     7,    -1,    -1,   375,   376,    -1,   377,
     378,   386,    -1,   105,    -1,    -1,   378,   379,    -1,   380,
      -1,   382,    -1,   384,    -1,    -1,    20,     3,   381,     7,
      -1,    -1,    21,     3,   383,     7,    -1,    -1,    22,     3,
     385,     7,    -1,     8,   106,    -1,     9,    -1,   388,   389,
       8,   390,   122,    -1,   121,    -1,    19,     7,     5,     7,
      -1,    -1,   390,   391,    -1,   392,   393,   401,    -1,   105,
      -1,    -1,   393,   394,    -1,   395,    -1,   397,    -1,   399,
      -1,    -1,    20,     3,   396,     7,    -1,    -1,    21,     3,
     398,     7,    -1,    -1,    22,     3,   400,     7,    -1,     8,
     106,    -1,     9,    -1,   403,   404,     8,   405,   114,    -1,
     113,    -1,    18,     7,     5,     7,    -1,    -1,   405,   406,
      -1,    -1,   103,     8,     4,   407,   104,    -1,   409,   410,
       8,   411,   112,    -1,   111,    -1,    18,     7,     5,     7,
      -1,    -1,   411,   412,    -1,    -1,   103,     8,     4,   413,
     104,    -1,   415,   416,     8,   417,   124,    -1,   123,    -1,
      27,     7,     5,     7,    -1,    -1,   417,   418,    -1,    -1,
     125,     8,     4,   419,   126,    -1,   421,   422,     8,   423,
      -1,    79,    -1,    16,     7,     5,     7,    -1,   424,    80,
      -1,    -1,   424,   425,    -1,    -1,    81,   426,   427,   435,
      -1,    -1,   427,   428,    -1,   429,    -1,   431,    -1,   433,
      -1,    -1,    39,     3,   430,     7,    -1,    -1,    42,     3,
     432,     7,    -1,    -1,    44,     3,   434,     7,    -1,     9,
      -1,     8,    82,    -1,    -1,   437,   438,   443,    -1,    57,
      -1,    -1,   438,   439,    -1,   440,    -1,   441,    -1,   442,
      -1,    30,     7,     5,     7,    -1,    32,     7,     5,     7,
      -1,    31,     7,     5,     7,    -1,     8,   444,    58,    -1,
       9,    -1,   445,   545,   605,   665,    -1,    -1,   446,   447,
     448,    -1,   127,    -1,    -1,    33,     7,     5,     7,    -1,
       8,   449,   460,   471,   482,   493,   513,   128,    -1,     9,
      -1,    -1,   129,   450,     8,   451,   130,    -1,    36,     7,
       5,     7,    -1,    -1,   451,   452,    -1,   453,   454,   459,
      -1,   131,    -1,    -1,   454,   455,    -1,   456,    -1,   457,
      -1,    40,     7,     5,     7,    -1,    -1,    42,     3,   458,
       7,    -1,     8,   132,    -1,     9,    -1,    -1,   133,   461,
       8,   462,   134,    -1,    36,     7,     5,     7,    -1,    -1,
     462,   463,    -1,   464,   465,   470,    -1,   131,    -1,    -1,
     465,   466,    -1,   467,    -1,   468,    -1,    40,     7,     5,
       7,    -1,    -1,    42,     3,   469,     7,    -1,     8,   132,
      -1,     9,    -1,    -1,   135,   472,     8,   473,   136,    -1,
      36,     7,     5,     7,    -1,    -1,   473,   474,    -1,   475,
     476,   481,    -1,   131,    -1,    -1,   476,   477,    -1,   478,
      -1,   479,    -1,    40,     7,     5,     7,    -1,    -1,    42,
       3,   480,     7,    -1,     8,   132,    -1,     9,    -1,    -1,
     137,   483,     8,   484,   138,    -1,    36,     7,     5,     7,
      -1,    -1,   484,   485,    -1,   486,   487,   492,    -1,   131,
      -1,    -1,   487,   488,    -1,   489,    -1,   490,    -1,    40,
       7,     5,     7,    -1,    -1,    42,     3,   491,     7,    -1,
       8,   132,    -1,     9,    -1,    -1,   139,   494,     8,   495,
     140,    -1,    29,     7,     5,     7,    -1,    -1,   495,   496,
      -1,   497,   498,   503,    -1,   141,    -1,    -1,   498,   499,
      -1,   500,    -1,   502,    -1,   501,    -1,    41,     7,     5,
       7,    -1,    26,     7,     6,     7,    -1,    26,     7,     5,
       7,    -1,    36,     7,     5,     7,    -1,     8,   504,   142,
      -1,     9,    -1,    -1,   504,   505,    -1,   506,   507,   512,
      -1,   131,    -1,    -1,   507,   508,    -1,   509,    -1,   510,
      -1,    40,     7,     5,     7,    -1,    -1,    42,     3,   511,
       7,    -1,     8,   132,    -1,     9,    -1,    -1,   513,   514,
      -1,   515,   516,   531,    -1,    81,    -1,    -1,   516,   517,
      -1,   518,    -1,   519,    -1,   521,    -1,   523,    -1,   525,
      -1,   527,    -1,   529,    -1,    36,     7,     5,     7,    -1,
      -1,    39,     3,   520,     7,    -1,    -1,    42,     3,   522,
       7,    -1,    -1,    23,     3,   524,     7,    -1,    -1,    24,
       3,   526,     7,    -1,    -1,    25,     3,   528,     7,    -1,
      -1,    44,     3,   530,     7,    -1,     8,   532,    82,    -1,
      -1,   532,   533,    -1,   534,   535,   544,    -1,   131,    -1,
      -1,   535,   536,    -1,   537,    -1,   538,    -1,   540,    -1,
     542,    -1,    40,     7,     5,     7,    -1,    -1,    42,     3,
     539,     7,    -1,    -1,    45,     3,   541,     7,    -1,    -1,
      46,     3,   543,     7,    -1,     8,   132,    -1,     9,    -1,
      -1,   546,   547,   548,    -1,   143,    -1,    -1,    34,     7,
       5,     7,    -1,     8,   549,   560,   573,   144,    -1,     9,
      -1,    -1,   145,   550,     8,   551,   146,    -1,    37,     7,
       5,     7,    -1,    -1,   551,   552,    -1,   553,   554,   559,
      -1,   147,    -1,    -1,   554,   555,    -1,   556,    -1,   557,
      -1,    40,     7,     5,     7,    -1,    -1,    42,     3,   558,
       7,    -1,     8,   148,    -1,     9,    -1,    -1,   149,   561,
       8,   562,   150,    -1,    37,     7,     5,     7,    -1,    -1,
     562,   563,    -1,   564,   565,   572,    -1,   147,    -1,    -1,
     565,   566,    -1,   567,    -1,   568,    -1,   570,    -1,    40,
       7,     5,     7,    -1,    -1,    45,     3,   569,     7,    -1,
      -1,    46,     3,   571,     7,    -1,     8,   148,    -1,     9,
      -1,    -1,   573,   574,    -1,   575,   576,   591,    -1,    81,
      -1,    -1,   576,   577,    -1,   578,    -1,   579,    -1,   581,
      -1,   583,    -1,   585,    -1,   587,    -1,   589,    -1,    37,
       7,     5,     7,    -1,    -1,    39,     3,   580,     7,    -1,
      -1,    42,     3,   582,     7,    -1,    -1,    23,     3,   584,
       7,    -1,    -1,    24,     3,   586,     7,    -1,    -1,    25,
       3,   588,     7,    -1,    -1,    44,     3,   590,     7,    -1,
       8,   592,    82,    -1,    -1,   592,   593,    -1,   594,   595,
     604,    -1,   147,    -1,    -1,   595,   596,    -1,   597,    -1,
     598,    -1,   600,    -1,   602,    -1,    40,     7,     5,     7,
      -1,    -1,    42,     3,   599,     7,    -1,    -1,    45,     3,
     601,     7,    -1,    -1,    46,     3,   603,     7,    -1,     8,
     132,    -1,     9,    -1,    -1,   606,   607,   608,    -1,   151,
      -1,    -1,    35,     7,     5,     7,    -1,     8,   609,   620,
     633,   152,    -1,     9,    -1,    -1,   153,   610,     8,   611,
     154,    -1,    38,     7,     5,     7,    -1,    -1,   611,   612,
      -1,   613,   614,   619,    -1,   155,    -1,    -1,   614,   615,
      -1,   616,    -1,   617,    -1,    40,     7,     5,     7,    -1,
      -1,    42,     3,   618,     7,    -1,     8,   156,    -1,     9,
      -1,    -1,   157,   621,     8,   622,   158,    -1,    38,     7,
       5,     7,    -1,    -1,   622,   623,    -1,   624,   625,   632,
      -1,   155,    -1,    -1,   625,   626,    -1,   627,    -1,   628,
      -1,   630,    -1,    40,     7,     5,     7,    -1,    -1,    47,
       3,   629,     7,    -1,    -1,    48,     3,   631,     7,    -1,
       8,   156,    -1,     9,    -1,    -1,   633,   634,    -1,   635,
     636,   651,    -1,    81,    -1,    -1,   636,   637,    -1,   638,
      -1,   639,    -1,   641,    -1,   643,    -1,   645,    -1,   647,
      -1,   649,    -1,    38,     7,     5,     7,    -1,    -1,    39,
       3,   640,     7,    -1,    -1,    42,     3,   642,     7,    -1,
      -1,    23,     3,   644,     7,    -1,    -1,    24,     3,   646,
       7,    -1,    -1,    25,     3,   648,     7,    -1,    -1,    44,
       3,   650,     7,    -1,     8,   652,    82,    -1,    -1,   652,
     653,    -1,   654,   655,   664,    -1,   155,    -1,    -1,   655,
     656,    -1,   657,    -1,   658,    -1,   660,    -1,   662,    -1,
      40,     7,     5,     7,    -1,    -1,    42,     3,   659,     7,
      -1,    -1,    45,     3,   661,     7,    -1,    -1,    46,     3,
     663,     7,    -1,     8,   156,    -1,     9,    -1,    -1,   666,
     667,     8,   668,   160,    -1,   159,    -1,    28,     7,     5,
       7,    -1,    -1,   668,   669,    -1,    -1,   161,   670,   671,
     685,    -1,    -1,   671,   672,    -1,   673,    -1,   675,    -1,
     677,    -1,   679,    -1,   681,    -1,   683,    -1,    -1,    39,
       3,   674,     7,    -1,    -1,    42,     3,   676,     7,    -1,
      -1,    23,     3,   678,     7,    -1,    -1,    24,     3,   680,
       7,    -1,    -1,    25,     3,   682,     7,    -1,    -1,    44,
       3,   684,     7,    -1,     8,   162,    -1,     9,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   133,   133,   134,   136,   137,   140,   142,   142,   144,
     155,   156,   158,   158,   160,   160,   160,   160,   160,   161,
     161,   161,   161,   161,   161,   164,   166,   175,   176,   177,
     177,   180,   182,   191,   192,   193,   193,   196,   198,   207,
     208,   209,   209,   212,   214,   225,   226,   225,   233,   234,
     236,   236,   239,   241,   250,   251,   252,   252,   255,   257,
     266,   267,   268,   268,   271,   273,   282,   283,   284,   284,
     287,   289,   298,   299,   300,   300,   303,   305,   314,   315,
     316,   316,   319,   321,   332,   333,   332,   341,   342,   344,
     344,   347,   349,   359,   367,   372,   372,   375,   374,   390,
     390,   392,   392,   392,   395,   394,   406,   405,   417,   416,
     427,   427,   430,   430,   432,   443,   444,   446,   446,   448,
     448,   448,   448,   448,   450,   452,   463,   464,   463,   472,
     473,   474,   479,   486,   488,   499,   500,   499,   508,   509,
     510,   515,   523,   525,   536,   537,   536,   547,   548,   549,
     554,   562,   564,   573,   574,   576,   575,   583,   585,   595,
     603,   608,   608,   611,   610,   625,   625,   627,   627,   627,
     630,   629,   641,   640,   653,   652,   663,   663,   666,   666,
     668,   679,   680,   682,   682,   684,   684,   686,   688,   698,
     699,   701,   700,   710,   712,   722,   730,   735,   735,   738,
     737,   752,   752,   754,   754,   754,   757,   756,   768,   767,
     779,   778,   789,   789,   792,   792,   794,   804,   805,   807,
     807,   809,   809,   809,   809,   809,   810,   810,   810,   810,
     810,   811,   811,   811,   811,   811,   814,   816,   827,   828,
     827,   837,   838,   839,   844,   851,   853,   863,   864,   865,
     865,   867,   869,   879,   886,   886,   889,   888,   901,   904,
     914,   921,   921,   923,   923,   935,   938,   948,   955,   955,
     957,   957,   969,   972,   981,   988,   988,   991,   990,  1002,
    1005,  1015,  1022,  1022,  1025,  1024,  1036,  1039,  1049,  1058,
    1058,  1060,  1072,  1078,  1078,  1080,  1080,  1080,  1083,  1082,
    1094,  1093,  1105,  1104,  1116,  1116,  1119,  1122,  1132,  1140,
    1140,  1142,  1154,  1160,  1160,  1162,  1162,  1162,  1165,  1164,
    1176,  1175,  1187,  1186,  1198,  1198,  1201,  1204,  1214,  1223,
    1223,  1225,  1237,  1243,  1243,  1245,  1245,  1245,  1248,  1247,
    1259,  1258,  1270,  1269,  1281,  1281,  1284,  1287,  1297,  1305,
    1305,  1307,  1319,  1325,  1325,  1327,  1327,  1327,  1330,  1329,
    1341,  1340,  1352,  1351,  1363,  1363,  1366,  1369,  1379,  1386,
    1386,  1389,  1388,  1400,  1403,  1413,  1420,  1420,  1423,  1422,
    1434,  1438,  1448,  1455,  1455,  1458,  1457,  1469,  1471,  1481,
    1489,  1494,  1494,  1497,  1496,  1511,  1511,  1513,  1513,  1513,
    1516,  1515,  1527,  1526,  1538,  1537,  1548,  1548,  1551,  1551,
    1553,  1563,  1563,  1565,  1565,  1565,  1567,  1573,  1579,  1585,
    1585,  1587,  1589,  1589,  1591,  1595,  1595,  1604,  1606,  1608,
    1608,  1610,  1620,  1620,  1622,  1630,  1635,  1635,  1637,  1637,
    1639,  1653,  1652,  1665,  1665,  1668,  1668,  1671,  1681,  1681,
    1683,  1691,  1696,  1696,  1698,  1698,  1700,  1714,  1713,  1721,
    1721,  1724,  1724,  1727,  1737,  1737,  1739,  1747,  1752,  1752,
    1754,  1754,  1756,  1770,  1769,  1777,  1777,  1780,  1780,  1783,
    1793,  1793,  1795,  1803,  1808,  1808,  1810,  1810,  1812,  1826,
    1825,  1838,  1838,  1841,  1841,  1844,  1855,  1855,  1857,  1869,
    1875,  1875,  1877,  1877,  1877,  1879,  1889,  1896,  1903,  1914,
    1915,  1917,  1917,  1919,  1927,  1932,  1932,  1934,  1934,  1936,
    1950,  1949,  1962,  1962,  1965,  1965,  1967,  1969,  1974,  1974,
    1977,  1978,  1979,  1980,  1981,  1982,  1983,  1985,  1999,  1998,
    2007,  2006,  2015,  2014,  2023,  2022,  2031,  2030,  2039,  2038,
    2047,  2064,  2064,  2066,  2076,  2081,  2081,  2084,  2085,  2086,
    2087,  2089,  2103,  2102,  2111,  2110,  2119,  2118,  2126,  2126,
    2130,  2130,  2132,  2136,  2136,  2145,  2146,  2148,  2148,  2151,
    2161,  2161,  2163,  2171,  2176,  2176,  2178,  2178,  2180,  2195,
    2194,  2207,  2207,  2210,  2210,  2213,  2223,  2223,  2225,  2234,
    2239,  2239,  2241,  2241,  2241,  2243,  2257,  2256,  2270,  2269,
    2282,  2282,  2286,  2286,  2288,  2290,  2295,  2295,  2298,  2299,
    2300,  2301,  2302,  2303,  2304,  2306,  2320,  2319,  2329,  2328,
    2338,  2337,  2347,  2346,  2356,  2355,  2365,  2364,  2374,  2391,
    2391,  2393,  2403,  2408,  2408,  2411,  2412,  2413,  2414,  2416,
    2431,  2430,  2440,  2439,  2449,  2448,  2457,  2457,  2460,  2460,
    2462,  2466,  2466,  2475,  2477,  2479,  2479,  2482,  2492,  2492,
    2494,  2502,  2507,  2507,  2509,  2509,  2511,  2526,  2525,  2538,
    2538,  2541,  2541,  2544,  2554,  2554,  2556,  2565,  2570,  2570,
    2572,  2572,  2572,  2574,  2588,  2587,  2601,  2600,  2614,  2614,
    2617,  2617,  2619,  2621,  2626,  2626,  2629,  2630,  2631,  2632,
    2633,  2634,  2635,  2637,  2651,  2650,  2659,  2658,  2667,  2666,
    2675,  2674,  2683,  2682,  2691,  2690,  2699,  2716,  2716,  2718,
    2728,  2733,  2733,  2736,  2737,  2738,  2739,  2741,  2756,  2755,
    2765,  2764,  2773,  2772,  2780,  2780,  2783,  2783,  2788,  2798,
    2806,  2806,  2809,  2808,  2826,  2826,  2829,  2830,  2831,  2832,
    2833,  2834,  2838,  2837,  2849,  2848,  2860,  2859,  2871,  2870,
    2882,  2881,  2893,  2892,  2904,  2904
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
  "REQUESTEDSTARTTIMESTART", "REQUESTEDSTARTTIMEEND", "DEPENDENCIESSTART",
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
  "maxtimehead", "maxtimeunit", "@28", "maxtimebody", "requestedstarttime",
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
       0,   164,   165,   165,   166,   166,   167,   168,   168,   169,
     170,   170,   171,   171,   172,   172,   172,   172,   172,   172,
     172,   172,   172,   172,   172,   173,   174,   175,   175,   176,
     175,   177,   178,   179,   179,   180,   179,   181,   182,   183,
     183,   184,   183,   185,   186,   187,   188,   187,   189,   189,
     190,   190,   191,   192,   193,   193,   194,   193,   195,   196,
     197,   197,   198,   197,   199,   200,   201,   201,   202,   201,
     203,   204,   205,   205,   206,   205,   207,   208,   209,   209,
     210,   209,   211,   212,   213,   214,   213,   215,   215,   216,
     216,   217,   218,   219,   220,   221,   221,   223,   222,   224,
     224,   225,   225,   225,   227,   226,   229,   228,   231,   230,
     232,   232,   233,   233,   234,   235,   235,   236,   236,   237,
     237,   237,   237,   237,   238,   239,   240,   241,   240,   242,
     242,   242,   242,   243,   244,   245,   246,   245,   247,   247,
     247,   247,   248,   249,   250,   251,   250,   252,   252,   252,
     252,   253,   254,   255,   255,   256,   255,   257,   258,   259,
     260,   261,   261,   263,   262,   264,   264,   265,   265,   265,
     267,   266,   269,   268,   271,   270,   272,   272,   273,   273,
     274,   275,   275,   276,   276,   277,   277,   278,   279,   280,
     280,   281,   280,   282,   283,   284,   285,   286,   286,   288,
     287,   289,   289,   290,   290,   290,   292,   291,   294,   293,
     296,   295,   297,   297,   298,   298,   299,   300,   300,   301,
     301,   302,   302,   302,   302,   302,   302,   302,   302,   302,
     302,   302,   302,   302,   302,   302,   303,   304,   305,   306,
     305,   307,   307,   307,   307,   308,   309,   310,   310,   311,
     310,   312,   313,   314,   315,   315,   317,   316,   318,   319,
     320,   321,   321,   323,   322,   324,   325,   326,   327,   327,
     329,   328,   330,   331,   332,   333,   333,   335,   334,   336,
     337,   338,   339,   339,   341,   340,   342,   343,   344,   345,
     345,   346,   347,   348,   348,   349,   349,   349,   351,   350,
     353,   352,   355,   354,   356,   356,   357,   358,   359,   360,
     360,   361,   362,   363,   363,   364,   364,   364,   366,   365,
     368,   367,   370,   369,   371,   371,   372,   373,   374,   375,
     375,   376,   377,   378,   378,   379,   379,   379,   381,   380,
     383,   382,   385,   384,   386,   386,   387,   388,   389,   390,
     390,   391,   392,   393,   393,   394,   394,   394,   396,   395,
     398,   397,   400,   399,   401,   401,   402,   403,   404,   405,
     405,   407,   406,   408,   409,   410,   411,   411,   413,   412,
     414,   415,   416,   417,   417,   419,   418,   420,   421,   422,
     423,   424,   424,   426,   425,   427,   427,   428,   428,   428,
     430,   429,   432,   431,   434,   433,   435,   435,   436,   436,
     437,   438,   438,   439,   439,   439,   440,   441,   442,   443,
     443,   444,   445,   445,   446,   447,   447,   448,   448,   449,
     449,   450,   451,   451,   452,   453,   454,   454,   455,   455,
     456,   458,   457,   459,   459,   460,   460,   461,   462,   462,
     463,   464,   465,   465,   466,   466,   467,   469,   468,   470,
     470,   471,   471,   472,   473,   473,   474,   475,   476,   476,
     477,   477,   478,   480,   479,   481,   481,   482,   482,   483,
     484,   484,   485,   486,   487,   487,   488,   488,   489,   491,
     490,   492,   492,   493,   493,   494,   495,   495,   496,   497,
     498,   498,   499,   499,   499,   500,   501,   501,   502,   503,
     503,   504,   504,   505,   506,   507,   507,   508,   508,   509,
     511,   510,   512,   512,   513,   513,   514,   515,   516,   516,
     517,   517,   517,   517,   517,   517,   517,   518,   520,   519,
     522,   521,   524,   523,   526,   525,   528,   527,   530,   529,
     531,   532,   532,   533,   534,   535,   535,   536,   536,   536,
     536,   537,   539,   538,   541,   540,   543,   542,   544,   544,
     545,   545,   546,   547,   547,   548,   548,   549,   549,   550,
     551,   551,   552,   553,   554,   554,   555,   555,   556,   558,
     557,   559,   559,   560,   560,   561,   562,   562,   563,   564,
     565,   565,   566,   566,   566,   567,   569,   568,   571,   570,
     572,   572,   573,   573,   574,   575,   576,   576,   577,   577,
     577,   577,   577,   577,   577,   578,   580,   579,   582,   581,
     584,   583,   586,   585,   588,   587,   590,   589,   591,   592,
     592,   593,   594,   595,   595,   596,   596,   596,   596,   597,
     599,   598,   601,   600,   603,   602,   604,   604,   605,   605,
     606,   607,   607,   608,   608,   609,   609,   610,   611,   611,
     612,   613,   614,   614,   615,   615,   616,   618,   617,   619,
     619,   620,   620,   621,   622,   622,   623,   624,   625,   625,
     626,   626,   626,   627,   629,   628,   631,   630,   632,   632,
     633,   633,   634,   635,   636,   636,   637,   637,   637,   637,
     637,   637,   637,   638,   640,   639,   642,   641,   644,   643,
     646,   645,   648,   647,   650,   649,   651,   652,   652,   653,
     654,   655,   655,   656,   656,   656,   656,   657,   659,   658,
     661,   660,   663,   662,   664,   664,   665,   665,   666,   667,
     668,   668,   670,   669,   671,   671,   672,   672,   672,   672,
     672,   672,   674,   673,   676,   675,   678,   677,   680,   679,
     682,   681,   684,   683,   685,   685
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     3,     2,     1,     3,     5,     0,     2,     1,
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
       2,     3,     3,     3,     1,     0,     0,     4,     1,     2,
       3,     3,     3,     1,     0,     0,     4,     1,     2,     3,
       3,     2,     1,     1,     2,     0,     4,     4,     1,     4,
       2,     0,     2,     0,     4,     0,     2,     1,     1,     1,
       0,     4,     0,     4,     0,     4,     1,     2,     0,     2,
       1,     3,     1,     0,     2,     1,     1,     2,     1,     1,
       2,     0,     4,     4,     1,     4,     2,     0,     2,     0,
       4,     0,     2,     1,     1,     1,     0,     4,     0,     4,
       0,     4,     1,     2,     0,     2,     1,     3,     1,     0,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     3,     1,     0,     0,
       4,     1,     2,     3,     3,     2,     1,     1,     2,     0,
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
       1,     4,     0,     3,     1,     0,     4,     8,     1,     0,
       5,     4,     0,     2,     3,     1,     0,     2,     1,     1,
       4,     0,     4,     2,     1,     0,     5,     4,     0,     2,
       3,     1,     0,     2,     1,     1,     4,     0,     4,     2,
       1,     0,     5,     4,     0,     2,     3,     1,     0,     2,
       1,     1,     4,     0,     4,     2,     1,     0,     5,     4,
       0,     2,     3,     1,     0,     2,     1,     1,     4,     0,
       4,     2,     1,     0,     5,     4,     0,     2,     3,     1,
       0,     2,     1,     1,     1,     4,     4,     4,     4,     3,
       1,     0,     2,     3,     1,     0,     2,     1,     1,     4,
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
       0,     4,     0,     4,     0,     4,     2,     1,     0,     3,
       1,     0,     4,     5,     1,     0,     5,     4,     0,     2,
       3,     1,     0,     2,     1,     1,     4,     0,     4,     2,
       1,     0,     5,     4,     0,     2,     3,     1,     0,     2,
       1,     1,     1,     4,     0,     4,     0,     4,     2,     1,
       0,     2,     3,     1,     0,     2,     1,     1,     1,     1,
       1,     1,     1,     4,     0,     4,     0,     4,     0,     4,
       0,     4,     0,     4,     0,     4,     3,     0,     2,     3,
       1,     0,     2,     1,     1,     1,     1,     4,     0,     4,
       0,     4,     0,     4,     2,     1,     0,     5,     1,     4,
       0,     2,     0,     4,     0,     2,     1,     1,     1,     1,
       1,     1,     0,     4,     0,     4,     0,     4,     0,     4,
       0,     4,     0,     4,     2,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       0,     0,     4,     0,     7,     0,     1,     3,     9,     0,
     112,     0,     5,     2,   114,   178,     0,    12,    11,     8,
     180,   214,     0,   117,   116,   113,     0,   216,   408,     0,
     183,   182,   179,     0,    10,    26,    32,    38,    44,    53,
      59,    65,    71,    77,    83,    92,    13,    14,     0,    15,
       0,    16,     0,    17,    45,    18,     0,    19,     0,    20,
       0,    21,     0,    22,     0,    23,    84,    24,     0,   410,
       6,   411,   219,   218,   215,     0,   115,   158,   125,   134,
     143,   152,   118,   119,   126,   120,   135,   121,   144,   122,
       0,   123,     0,     0,    27,    25,     0,    33,    31,     0,
      39,    37,     0,     0,     0,    54,    52,     0,    60,    58,
       0,    66,    64,     0,    72,    70,     0,    78,    76,     0,
       0,     0,     0,     0,     0,   181,   194,   188,   184,   185,
       0,   186,     0,     0,     0,     0,     0,     0,     0,     0,
     153,   151,     0,     0,    29,    28,    35,    34,    41,    40,
      46,    50,    48,    43,    56,    55,    62,    61,    68,    67,
      74,    73,    80,    79,    85,    89,    87,    82,     0,    95,
     422,   420,     0,     0,     0,   412,   413,   414,   415,   409,
     217,   388,   237,   246,   252,   259,   266,   273,   280,   374,
     367,   287,   307,   327,   347,   381,   220,   221,   238,   222,
       0,   223,     0,   224,     0,   225,     0,   226,     0,   227,
       0,   228,     0,   229,     0,   230,     0,   231,     0,   232,
       0,   233,     0,   234,     0,   235,     0,     0,   189,   187,
       0,     0,   127,     0,   129,   124,   136,     0,   138,   133,
     145,     0,   147,   142,   155,   154,     0,   161,     0,     0,
       0,     0,    51,     0,     0,     0,     0,     0,     0,     0,
      90,     0,     0,    91,     0,   424,     0,   570,   425,     0,
       0,     0,     0,     0,     0,   247,   245,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   191,   190,     0,   197,     0,     0,     0,
     130,     0,     0,     0,   139,     0,     0,     0,   148,     0,
       0,   157,     0,    30,    36,    42,    47,    49,    57,    63,
      69,    75,    81,    86,    88,    93,    94,    97,    96,   419,
     572,   658,   573,     0,     0,     0,     0,     0,   239,     0,
     241,   236,   249,   248,     0,   254,     0,   261,     0,   268,
       0,   275,     0,   282,     0,   289,     0,   309,     0,   329,
       0,   349,     0,   369,     0,   376,     0,   383,     0,   391,
       0,     0,   193,     0,   128,   132,   131,   137,   141,   140,
     146,   150,   149,   156,   159,   160,   163,   162,    99,   660,
     746,   661,     0,     0,     0,   429,   428,   423,   416,   418,
     417,     0,     0,     0,   242,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   387,     0,   192,   195,   196,   199,   198,   165,     0,
     748,   421,     0,     0,     0,     0,   577,   576,   571,     0,
       0,   445,   240,   244,   243,   250,   253,     0,   251,   255,
     260,   258,     0,   262,   267,   265,     0,   269,   274,     0,
     272,   276,   281,     0,   279,   283,   288,   292,   286,   290,
     293,   308,   312,   306,   310,   313,   328,   332,   326,   330,
     333,   348,   352,   346,   350,   353,   368,     0,   366,   370,
     375,     0,   373,   377,   382,   380,     0,   384,   389,   390,
     393,   392,   201,     0,     0,   110,     0,     0,     0,   100,
     101,   102,   103,    98,     0,     0,     0,   665,   664,   659,
       0,     0,   593,   426,     0,     0,     0,   461,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     395,     0,     0,   176,     0,     0,     0,   166,   167,   168,
     169,   164,   111,   104,   106,   108,     0,   750,     0,     0,
     681,   574,     0,     0,     0,   612,     0,   432,     0,     0,
       0,   477,   256,   263,   270,   277,   284,     0,   305,     0,
       0,     0,   294,   295,   296,   297,   291,     0,   325,     0,
       0,     0,   314,   315,   316,   317,   311,     0,   345,     0,
       0,     0,   334,   335,   336,   337,   331,     0,   365,     0,
       0,     0,   354,   355,   356,   357,   351,   371,   378,   385,
       0,     0,   212,     0,     0,     0,   202,   203,   204,   205,
     200,   177,   170,   172,   174,     0,     0,     0,     0,     0,
     662,     0,     0,     0,   700,     0,   580,     0,     0,     0,
       0,     0,     0,   448,     0,     0,     0,   493,     0,     0,
       0,     0,     0,   304,   298,   300,   302,   324,   318,   320,
     322,   344,   338,   340,   342,   364,   358,   360,   362,     0,
       0,     0,     0,   406,     0,     0,     0,   396,   397,   398,
     399,   394,   213,   206,   208,   210,     0,     0,     0,   105,
     107,   109,   749,   747,   752,   751,     0,   668,     0,     0,
       0,     0,     0,     0,   596,   615,   575,   613,   616,   431,
     430,   435,   433,   436,     0,     0,     0,   464,     0,     0,
       0,   524,   257,   264,   271,   278,   285,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   372,
     379,   386,   407,   400,   402,   404,     0,     0,     0,   171,
     173,   175,   754,     0,     0,     0,   684,   703,   663,   701,
     704,   579,   578,   583,   581,   584,     0,     0,     0,     0,
     447,   451,   446,   449,   452,     0,     0,     0,   480,     0,
       0,     0,   299,   301,   303,   319,   321,   323,   339,   341,
     343,   359,   361,   363,     0,     0,     0,   207,   209,   211,
       0,   667,   666,   671,   669,   672,     0,     0,     0,     0,
     595,   599,   594,   597,   600,   639,     0,     0,     0,     0,
       0,     0,     0,   617,   618,   619,   620,   621,   622,   623,
     624,   614,     0,   444,     0,     0,   437,   438,   439,   434,
       0,   463,   467,   462,   465,   468,     0,     0,     0,   496,
     527,   427,   525,   528,   401,   403,   405,     0,   775,     0,
       0,     0,     0,     0,     0,   755,   756,   757,   758,   759,
     760,   761,   753,     0,   683,   687,   682,   685,   688,   727,
       0,     0,     0,     0,     0,     0,     0,   705,   706,   707,
     708,   709,   710,   711,   712,   702,     0,   592,     0,     0,
     585,   586,   587,   582,     0,     0,   630,   632,   634,     0,
     626,   628,   636,   443,     0,   441,     0,   460,     0,     0,
     453,   454,   455,   450,     0,   479,   483,   478,   481,   484,
       0,     0,     0,   774,   766,   768,   770,   762,   764,   772,
       0,   680,     0,     0,   673,   674,   675,   670,     0,     0,
     718,   720,   722,     0,   714,   716,   724,   591,     0,   589,
       0,   611,     0,     0,     0,   601,   602,   603,   604,   598,
     638,   642,   640,   643,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   459,     0,   457,     0,   476,     0,     0,
     469,   470,   471,   466,     0,   495,   494,   499,   497,   500,
     551,     0,     0,     0,     0,     0,     0,     0,   529,   530,
     531,   532,   533,   534,   535,   536,   526,     0,     0,     0,
       0,     0,     0,   679,     0,   677,     0,   699,     0,     0,
       0,   689,   690,   691,   692,   686,   726,   730,   728,   731,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   610,
       0,   606,   608,     0,   631,   633,   635,   625,   627,   629,
     637,   440,   442,     0,     0,   475,     0,   473,     0,   492,
       0,     0,   485,   486,   487,   482,     0,     0,   542,   544,
     546,     0,   538,   540,   548,   767,   769,   771,   763,   765,
     773,     0,     0,   698,     0,   694,   696,     0,   719,   721,
     723,   713,   715,   717,   725,   588,   590,     0,     0,     0,
       0,   657,     0,     0,     0,     0,   644,   645,   646,   647,
     648,   641,   456,   458,     0,     0,   491,     0,   489,   511,
     510,     0,     0,     0,   501,   502,   504,   503,   498,   550,
     554,   552,   555,     0,     0,     0,     0,     0,     0,     0,
     676,   678,     0,     0,     0,     0,   745,     0,     0,     0,
       0,   732,   733,   734,   735,   736,   729,   605,   607,   609,
     656,     0,   650,   652,   654,   472,   474,     0,     0,     0,
       0,     0,     0,     0,   543,   545,   547,   537,   539,   541,
     549,   693,   695,   697,   744,     0,   738,   740,   742,     0,
       0,     0,     0,   488,   490,   514,   509,   512,   515,     0,
       0,     0,     0,     0,   569,     0,     0,     0,     0,   556,
     557,   558,   559,   560,   553,     0,     0,     0,     0,   649,
     651,   653,   655,     0,   507,   506,   508,   505,   568,     0,
     562,   564,   566,   737,   739,   741,   743,     0,   523,     0,
       0,   516,   517,   518,   513,     0,     0,     0,     0,   522,
       0,   520,   561,   563,   565,   567,     0,     0,   519,   521
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     3,     4,     9,    10,    11,    19,    26,    46,    47,
      48,    95,   248,    49,    50,    98,   249,    51,    52,   101,
     250,    53,    54,   103,   251,   153,   253,    55,    56,   106,
     254,    57,    58,   109,   255,    59,    60,   112,   256,    61,
      62,   115,   257,    63,    64,   118,   258,    65,    66,   120,
     259,   167,   261,    67,    68,   122,   263,   264,   338,   398,
     449,   529,   530,   655,   531,   656,   532,   657,   533,    15,
      16,    25,    33,    82,    83,    84,   134,   307,   235,    85,
      86,   136,   311,   239,    87,    88,   138,   315,   243,    89,
      90,   141,   319,    91,    92,   143,   321,   322,   397,   448,
     523,   567,   568,   716,   569,   717,   570,   718,   571,    21,
      22,    32,    75,   128,   129,   130,   229,   380,   131,   132,
     231,   382,   383,   447,   522,   561,   646,   647,   776,   648,
     777,   649,   778,   650,    28,    29,    74,   124,   196,   197,
     198,   273,   411,   351,   199,   200,   276,   415,   201,   202,
     278,   417,   469,   678,   203,   204,   280,   419,   473,   679,
     205,   206,   282,   421,   477,   680,   207,   208,   284,   423,
     481,   681,   209,   210,   286,   425,   485,   682,   211,   212,
     288,   427,   489,   490,   553,   602,   603,   757,   604,   758,
     605,   759,   606,   213,   214,   290,   429,   494,   495,   554,
     612,   613,   760,   614,   761,   615,   762,   616,   215,   216,
     292,   431,   499,   500,   555,   622,   623,   763,   624,   764,
     625,   765,   626,   217,   218,   294,   433,   504,   505,   556,
     632,   633,   766,   634,   767,   635,   768,   636,   219,   220,
     296,   435,   509,   699,   221,   222,   298,   437,   513,   700,
     223,   224,   300,   439,   517,   701,   225,   226,   302,   441,
     442,   521,   560,   640,   707,   708,   824,   709,   825,   710,
     826,   711,    70,    71,   123,   175,   176,   177,   178,   179,
     266,   267,   268,   344,   407,   461,   545,   671,   742,   743,
     799,   866,   867,   868,  1012,   869,   547,   589,   745,   803,
     804,   870,   950,   951,   952,  1094,   953,   591,   675,   806,
     874,   875,   954,  1020,  1021,  1022,  1155,  1023,   677,   749,
     877,   958,   959,  1024,  1102,  1103,  1104,  1208,  1105,   751,
     810,   961,  1028,  1029,  1106,  1164,  1165,  1166,  1167,  1168,
    1209,  1237,  1238,  1263,  1281,  1282,  1283,  1297,  1284,   811,
     882,   883,   962,  1038,  1039,  1040,  1177,  1041,  1178,  1042,
    1173,  1043,  1174,  1044,  1175,  1045,  1179,  1046,  1107,  1171,
    1172,  1213,  1249,  1250,  1251,  1286,  1252,  1287,  1253,  1288,
    1254,   341,   342,   403,   458,   542,   583,   732,   794,   795,
     839,   930,   931,   932,  1078,   933,   585,   668,   797,   843,
     844,   934,   995,   996,   997,  1138,   998,  1139,   999,   669,
     737,   738,   798,   853,   854,   855,  1008,   856,  1009,   857,
    1004,   858,  1005,   859,  1006,   860,  1010,   861,   935,  1002,
    1003,  1083,  1146,  1147,  1148,  1230,  1149,  1231,  1150,  1232,
    1151,   400,   401,   454,   539,   580,   662,   784,   834,   835,
     903,   974,   975,   976,  1122,   977,   664,   729,   837,   907,
     908,   978,  1061,  1062,  1063,  1183,  1064,  1184,  1065,   730,
     789,   790,   838,   917,   918,   919,  1074,   920,  1075,   921,
    1070,   922,  1071,   923,  1072,   924,  1076,   925,   979,  1068,
    1069,  1127,  1191,  1192,  1193,  1256,  1194,  1257,  1195,  1258,
    1196,   451,   452,   535,   659,   725,   782,   830,   895,   896,
    1050,   897,  1051,   898,  1047,   899,  1048,   900,  1049,   901,
    1052,   902
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -82
static const yytype_int16 yypact[] =
{
     288,    26,   -82,    32,    22,    34,   -82,   -82,   -82,    35,
     -17,   292,   -82,   -82,   -82,   -13,   294,   -82,   -82,   -82,
     -82,   -11,   302,   -82,   -82,   -82,   -22,   -82,    -5,   304,
     -82,   -82,   -82,    65,   -82,   -82,   -82,   -82,   -82,   -82,
     -82,   -82,   -82,   -82,   -82,   -82,   -82,   -82,   306,   -82,
     308,   -82,   310,   -82,    40,   -82,   312,   -82,   314,   -82,
     316,   -82,   318,   -82,   320,   -82,    41,   -82,    30,   -82,
     -82,   -82,   -82,   -82,   -82,   -29,   -82,   -82,   -82,   -82,
     -82,   -82,   -82,   -82,    52,   -82,    54,   -82,    56,   -82,
     322,   -82,    44,    20,   -82,   -82,    17,   -82,   -82,    14,
     -82,   -82,    73,   324,    13,   -82,   -82,    16,   -82,   -82,
      12,   -82,   -82,    11,   -82,   -82,     7,   -82,   -82,    98,
     326,    96,    99,   226,     3,   -82,   -82,   -82,   -82,   -82,
     328,   -82,    95,   110,   330,   118,   332,   120,   334,    -1,
     -82,   -82,   122,   117,   -82,   -82,   -82,   -82,   -82,   -82,
     -82,   127,   -82,   -82,   -82,   -82,   -82,   -82,   -82,   -82,
     -82,   -82,   -82,   -82,   -82,   129,   -82,   -82,   130,   -82,
      28,   -82,   161,   167,   169,   -82,   -82,   -82,   -82,   -82,
     -82,   -82,   -82,   -82,   -82,   -82,   -82,   -82,   -82,   -82,
     -82,   -82,   -82,   -82,   -82,   -82,   -82,   -82,   178,   -82,
     336,   -82,   136,   -82,   190,   -82,   210,   -82,   212,   -82,
     222,   -82,   182,   -82,   242,   -82,   265,   -82,   267,   -82,
     247,   -82,   257,   -82,   217,   -82,   237,     1,   -82,   -82,
     281,   286,   -82,     4,   -82,   -82,   -82,     8,   -82,   -82,
     -82,     2,   -82,   -82,   -82,   -82,   365,   -82,   319,   321,
     233,   373,   -82,   315,   317,   323,   325,   313,   327,   375,
     -82,   311,   377,   -82,   266,   -82,   333,   245,   353,   385,
     387,   389,   392,   340,    -4,   -82,   -82,   391,   388,   393,
     394,   397,   398,   400,   401,   403,   404,   406,   407,   409,
     410,   412,   413,   415,   416,   418,   419,   421,   422,   424,
     425,   427,   428,   -82,   -82,   396,   -82,   430,   339,   342,
     -82,   431,   331,   343,   -82,   432,   347,   352,   -82,   309,
     434,   -82,   270,   -82,   -82,   -82,   -82,   -82,   -82,   -82,
     -82,   -82,   -82,   -82,   -82,   -82,   -82,   -82,   -82,   -82,
     -82,   254,   374,   435,   344,   436,   437,   438,   -82,    -3,
     -82,   -82,   -82,   -82,   441,   -82,   442,   -82,   443,   -82,
     444,   -82,   445,   -82,   446,   -82,   447,   -82,   448,   -82,
     449,   -82,   450,   -82,   451,   -82,   452,   -82,   453,   -82,
     367,   454,   -82,   274,   -82,   -82,   -82,   -82,   -82,   -82,
     -82,   -82,   -82,   -82,   -82,   -82,   -82,   -82,   -82,   -82,
     252,   379,   455,   348,   458,   291,   -82,   -82,   -82,   -82,
     -82,   457,   338,   366,   -82,   369,   459,   -34,   460,   146,
     461,   256,   462,    91,   463,    76,   464,    31,   465,    33,
     466,    29,   467,    10,   468,    57,   469,    66,   470,   236,
     471,   -82,   282,   -82,   -82,   -82,   -82,   -82,   -82,   154,
     -82,   -82,   456,   472,   356,   475,   337,   -82,   -82,   474,
     473,   350,   -82,   -82,   -82,   -82,   -82,   477,   -82,   -82,
     -82,   -82,   478,   -82,   -82,   -82,   479,   -82,   -82,   480,
     -82,   -82,   -82,   481,   -82,   -82,   -82,   -82,   -82,   -82,
     -82,   -82,   -82,   -82,   -82,   -82,   -82,   -82,   -82,   -82,
     -82,   -82,   -82,   -82,   -82,   -82,   -82,   482,   -82,   -82,
     -82,   483,   -82,   -82,   -82,   -82,   484,   -82,   -82,   -82,
     -82,   -82,   -82,   176,   411,   -82,   491,   492,   493,   -82,
     -82,   -82,   -82,   -82,   490,   494,   495,   345,   -82,   -82,
     496,   476,   355,   -82,   498,   499,   485,   364,   497,   502,
     504,   506,   507,   259,   269,   284,   287,   508,   510,   511,
     -82,   183,   440,   -82,   513,   514,   515,   -82,   -82,   -82,
     -82,   -82,   -82,   -82,   -82,   -82,   518,   -82,   512,   486,
     363,   -82,   519,   517,   500,   -82,   522,   -82,   521,   523,
     503,   395,   -82,   -82,   -82,   -82,   -82,   423,   -82,   527,
     530,   531,   -82,   -82,   -82,   -82,   -82,   429,   -82,   533,
     535,   537,   -82,   -82,   -82,   -82,   -82,   439,   -82,   538,
     539,   540,   -82,   -82,   -82,   -82,   -82,   487,   -82,   541,
     543,   544,   -82,   -82,   -82,   -82,   -82,   -82,   -82,   -82,
     197,   488,   -82,   545,   546,   547,   -82,   -82,   -82,   -82,
     -82,   -82,   -82,   -82,   -82,   548,   549,   550,   551,   206,
     -82,   552,   553,   516,   -82,   555,   -82,   556,   554,   -69,
     557,   238,   560,   -82,   559,   561,   532,   414,   505,   501,
     509,   520,   524,   -82,   -82,   -82,   -82,   -82,   -82,   -82,
     -82,   -82,   -82,   -82,   -82,   -82,   -82,   -82,   -82,   525,
     526,   426,   489,   -82,   564,   569,   571,   -82,   -82,   -82,
     -82,   -82,   -82,   -82,   -82,   -82,   568,   570,   572,   -82,
     -82,   -82,   -82,   -82,   -82,   -82,   573,   -82,   574,   575,
     -75,   577,   225,   580,   -82,   -82,   -82,   -82,   -82,   -82,
     -82,   -82,   -82,   -82,   579,   128,   582,   -82,   581,   583,
     563,   -82,   -82,   -82,   -82,   -82,   -82,   587,   588,   589,
     590,   591,   592,   593,   594,   595,   596,   597,   599,   -82,
     -82,   -82,   -82,   -82,   -82,   -82,   600,   601,   602,   -82,
     -82,   -82,   -82,   603,   219,   584,   -82,   -82,   -82,   -82,
     -82,   -82,   -82,   -82,   -82,   -82,   604,   113,   133,    21,
     -82,   -82,   -82,   -82,   -82,   605,    88,   585,   -82,   607,
     608,   -58,   -82,   -82,   -82,   -82,   -82,   -82,   -82,   -82,
     -82,   -82,   -82,   -82,   610,   611,   612,   -82,   -82,   -82,
     158,   -82,   -82,   -82,   -82,   -82,   613,   115,   165,   205,
     -82,   -82,   -82,   -82,   -82,   -82,   618,   619,   620,   624,
     622,   623,   629,   -82,   -82,   -82,   -82,   -82,   -82,   -82,
     -82,   -82,   528,   -82,   626,   631,   -82,   -82,   -82,   -82,
     208,   -82,   -82,   -82,   -82,   -82,   628,    49,   632,   -82,
     -82,   -82,   -82,   -82,   -82,   -82,   -82,   420,   -82,   633,
     635,   636,   637,   638,   639,   -82,   -82,   -82,   -82,   -82,
     -82,   -82,   -82,   224,   -82,   -82,   -82,   -82,   -82,   -82,
     640,   641,   642,   643,   644,   645,   646,   -82,   -82,   -82,
     -82,   -82,   -82,   -82,   -82,   -82,   529,   -82,   647,   648,
     -82,   -82,   -82,   -82,   100,   -60,   -82,   -82,   -82,   650,
     -82,   -82,   -82,   -82,   651,   -82,   534,   -82,   652,   649,
     -82,   -82,   -82,   -82,   229,   -82,   -82,   -82,   -82,   -82,
     654,   235,   187,   -82,   -82,   -82,   -82,   -82,   -82,   -82,
     536,   -82,   655,   660,   -82,   -82,   -82,   -82,    18,   -81,
     -82,   -82,   -82,   653,   -82,   -82,   -82,   -82,   659,   -82,
     542,   -82,   658,   664,   665,   -82,   -82,   -82,   -82,   -82,
     -82,   -82,   -82,   -82,   662,   663,   666,   667,   668,   669,
     671,   672,   673,   -82,   676,   -82,   562,   -82,   675,   680,
     -82,   -82,   -82,   -82,   234,   -82,   -82,   -82,   -82,   -82,
     -82,   681,   682,   683,   684,   685,   686,   690,   -82,   -82,
     -82,   -82,   -82,   -82,   -82,   -82,   -82,   688,   689,   691,
     692,   693,   694,   -82,   697,   -82,   558,   -82,   696,   701,
     702,   -82,   -82,   -82,   -82,   -82,   -82,   -82,   -82,   -82,
     699,   700,   703,   704,   705,   706,   708,   709,   710,   -82,
     713,   -82,   -82,    27,   -82,   -82,   -82,   -82,   -82,   -82,
     -82,   -82,   -82,   712,   714,   -82,   715,   -82,   565,   -82,
     716,   719,   -82,   -82,   -82,   -82,   246,   -63,   -82,   -82,
     -82,   720,   -82,   -82,   -82,   -82,   -82,   -82,   -82,   -82,
     -82,   717,   721,   -82,   722,   -82,   -82,    97,   -82,   -82,
     -82,   -82,   -82,   -82,   -82,   -82,   -82,   723,   724,   725,
     576,   -82,   726,   731,   732,   733,   -82,   -82,   -82,   -82,
     -82,   -82,   -82,   -82,   730,   734,   -82,   735,   -82,   -82,
     -82,   736,   737,   738,   -82,   -82,   -82,   -82,   -82,   -82,
     -82,   -82,   -82,   739,   740,   741,   742,   743,   744,   745,
     -82,   -82,   746,   747,   748,   586,   -82,   749,   754,   755,
     756,   -82,   -82,   -82,   -82,   -82,   -82,   -82,   -82,   -82,
     -82,   757,   -82,   -82,   -82,   -82,   -82,   753,   758,   -12,
     372,   759,   761,   119,   -82,   -82,   -82,   -82,   -82,   -82,
     -82,   -82,   -82,   -82,   -82,   762,   -82,   -82,   -82,   763,
     764,   765,   766,   -82,   -82,   -82,   -82,   -82,   -82,   767,
     768,   769,   770,   606,   -82,   771,   760,   776,   777,   -82,
     -82,   -82,   -82,   -82,   -82,   774,   775,   778,   779,   -82,
     -82,   -82,   -82,   243,   -82,   -82,   -82,   -82,   -82,   782,
     -82,   -82,   -82,   -82,   -82,   -82,   -82,   656,   -82,   783,
     780,   -82,   -82,   -82,   -82,   784,   785,   786,   787,   -82,
     790,   -82,   -82,   -82,   -82,   -82,   789,   791,   -82,   -82
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -82,   -82,   -82,   -82,   -82,   -82,   -82,   -82,   -82,   -82,
     -82,   -82,   -82,   -82,   -82,   -82,   -82,   -82,   -82,   -82,
     -82,   -82,   -82,   -82,   -82,   -82,   -82,   -82,   -82,   -82,
     -82,   -82,   -82,   -82,   -82,   -82,   -82,   -82,   -82,   -82,
     -82,   -82,   -82,   -82,   -82,   -82,   -82,   -82,   -82,   -82,
     -82,   -82,   -82,   -82,   -82,   -82,   -82,   -82,   -82,   -82,
     -82,   -82,   -82,   -82,   -82,   -82,   -82,   -82,   -82,   -82,
     -82,   -82,   -82,   -82,   -82,   -82,   -82,   -82,   -82,   -82,
     -82,   -82,   -82,   -82,   -82,   -82,   -82,   -82,   -82,   -82,
     -82,   -82,   -82,   -82,   -82,   -82,   -82,   -82,   -82,   -82,
     -82,   -82,   -82,   -82,   -82,   -82,   -82,   -82,   -82,   -82,
     -82,   -82,   -82,   -82,   -82,   -82,   -82,   -82,   -82,   -82,
     -82,   -82,   -82,   -82,   -82,   -82,   -82,   -82,   -82,   -82,
     -82,   -82,   -82,   -82,   -82,   -82,   -82,   -82,   -82,   -82,
     -82,   -82,   -82,   -82,   -82,   -82,   -82,   -82,   -82,   -82,
     -82,   -82,   -82,   -82,   -82,   -82,   -82,   -82,   -82,   -82,
     -82,   -82,   -82,   -82,   -82,   -82,   -82,   -82,   -82,   -82,
     -82,   -82,   -82,   -82,   -82,   -82,   -82,   -82,   -82,   -82,
     -82,   -82,   -82,   -82,   -82,   -82,   -82,   -82,   -82,   -82,
     -82,   -82,   -82,   -82,   -82,   -82,   -82,   -82,   -82,   -82,
     -82,   -82,   -82,   -82,   -82,   -82,   -82,   -82,   -82,   -82,
     -82,   -82,   -82,   -82,   -82,   -82,   -82,   -82,   -82,   -82,
     -82,   -82,   -82,   -82,   -82,   -82,   -82,   -82,   -82,   -82,
     -82,   -82,   -82,   -82,   -82,   -82,   -82,   -82,   -82,   -82,
     -82,   -82,   -82,   -82,   -82,   -82,   -82,   -82,   -82,   -82,
     -82,   -82,   -82,   -82,   -82,   -82,   -82,   -82,   -82,   -82,
     -82,   -82,   -82,   -82,   -82,   -82,   -82,   -82,   -82,   -82,
     -82,   -82,   -82,   -82,   -82,   -82,   -82,   -82,   -82,   -82,
     -82,   -82,   -82,   -82,   -82,   -82,   -82,   -82,   -82,   -82,
     -82,   -82,   -82,   -82,   -82,   -82,   -82,   -82,   -82,   -82,
     -82,   -82,   -82,   -82,   -82,   -82,   -82,   -82,   -82,   -82,
     -82,   -82,   -82,   -82,   -82,   -82,   -82,   -82,   -82,   -82,
     -82,   -82,   -82,   -82,   -82,   -82,   -82,   -82,   -82,   -82,
     -82,   -82,   -82,   -82,   -82,   -82,   -82,   -82,   -82,   -82,
     -82,   -82,   -82,   -82,   -82,   -82,   -82,   -82,   -82,   -82,
     -82,   -82,   -82,   -82,   -82,   -82,   -82,   -82,   -82,   -82,
     -82,   -82,   -82,   -82,   -82,   -82,   -82,   -82,   -82,   -82,
     -82,   -82,   -82,   -82,   -82,   -82,   -82,   -82,   -82,   -82,
     -82,   -82,   -82,   -82,   -82,   -82,   -82,   -82,   -82,   -82,
     -82,   -82,   -82,   -82,   -82,   -82,   -82,   -82,   -82,   -82,
     -82,   -82,   -82,   -82,   -82,   -82,   -82,   -82,   -82,   -82,
     -82,   -82,   -82,   -82,   -82,   -82,   -82,   -82,   -82,   -82,
     -82,   -82,   -82,   -82,   -82,   -82,   -82,   -82,   -82,   -82,
     -82,   -82,   -82,   -82,   -82,   -82,   -82,   -82,   -82,   -82,
     -82,   -82,   -82,   -82,   -82,   -82,   -82,   -82,   -82,   -82,
     -82,   -82,   -82,   -82,   -82,   -82,   -82,   -82,   -82,   -82,
     -82,   -82,   -82,   -82,   -82,   -82,   -82,   -82,   -82,   -82,
     -82,   -82,   -82,   -82,   -82,   -82,   -82,   -82,   -82,   -82,
     -82,   -82,   -82,   -82,   -82,   -82,   -82,   -82,   -82,   -82,
     -82,   -82,   -82,   -82,   -82,   -82,   -82,   -82,   -82,   -82,
     -82,   -82,   -82,   -82,   -82,   -82,   -82,   -82,   -82,   -82,
     -82,   -82,   -82,   -82,   -82,   -82,   -82,   -82,   -82,   -82,
     -82,   -82
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint16 yytable[] =
{
     352,  1066,   412,   413,   244,   303,   787,   316,   317,   308,
     309,   162,   735,   312,   313,   160,   158,   154,   148,  1169,
     156,   146,  1000,   880,   144,   125,  1056,  1057,    34,   862,
     863,     7,     6,   467,    14,  1140,  1141,    35,     5,    36,
      20,    37,    12,    38,    27,    39,   121,    40,    13,    41,
     126,    42,    69,    43,   102,    44,   119,    45,  1058,   180,
     142,   864,   127,   865,   468,  1059,  1060,  1142,  1170,  1143,
     881,     8,  1144,  1145,  1067,   736,   150,   788,   149,   147,
     145,   155,   181,   163,   159,   161,   157,  1001,   310,   245,
     318,   414,   353,   304,   314,   133,   182,   135,   183,   137,
     184,   164,   185,   168,   186,  1185,  1186,   169,   990,   991,
     187,   230,   188,   232,   189,   502,   190,    76,   191,  1235,
     192,   236,   193,   240,   194,   247,   195,  1243,  1244,   246,
    1236,   252,   503,   260,   497,   262,   487,  1187,   492,  1188,
     992,   845,  1189,  1190,    77,   993,   994,   488,    78,   498,
      79,   493,    80,   277,    81,   265,   846,   847,   848,  1245,
     507,  1246,   524,   525,  1247,  1248,   887,   888,   269,   511,
     849,   508,   850,   909,   270,   851,   271,   852,   512,   483,
     956,   889,   890,   891,   562,   563,   484,   957,   910,   911,
     912,   641,   642,   526,   479,  1030,   527,   892,   528,   480,
     893,   287,   894,   913,   914,   702,   703,   915,   279,   916,
    1031,  1032,  1033,   926,   927,   564,   946,   947,   565,   872,
     566,   272,   643,  1034,   873,   644,  1035,   645,   281,  1036,
     283,  1037,   970,   971,   170,   171,   704,  1016,  1017,   705,
     285,   706,  1098,  1099,   299,   928,   471,   929,   948,   472,
     949,  1277,  1278,   301,  1159,  1160,   172,   173,   174,   801,
     841,   289,   802,   842,   972,   295,   973,   597,   598,  1018,
     905,  1019,  1161,   906,  1100,   297,  1101,   607,   608,   599,
     600,   601,  1162,  1279,   291,  1280,   293,  1163,   305,   609,
     610,   611,   617,   618,   306,   627,   628,   325,     1,     2,
      17,    18,    23,    24,   619,   620,   621,   629,   630,   631,
      30,    31,    72,    73,    93,    94,    96,    97,    99,   100,
     104,   105,   107,   108,   110,   111,   113,   114,   116,   117,
     139,   140,   151,   152,   165,   166,   227,   228,   233,   234,
     237,   238,   241,   242,   274,   275,   336,   337,   349,   350,
     395,   396,   405,   406,   445,   446,   456,   457,   475,   476,
     515,   516,   519,   520,   537,   538,   723,   724,   740,   741,
     320,   792,   793,   832,   833,  1026,  1027,  1239,  1240,   323,
     326,   327,   333,   324,   335,   328,   343,   331,   340,   334,
     345,   339,   346,   329,   347,   348,   355,   330,   354,   393,
     356,   381,   357,   332,   358,   399,   359,   360,   402,   361,
     362,   450,   363,   364,   453,   365,   366,   388,   367,   368,
     460,   369,   370,   385,   371,   372,   386,   373,   374,   389,
     375,   376,   463,   377,   378,   391,   379,   384,   387,   390,
     392,   394,   404,   408,   409,   410,   416,   418,   420,   422,
     424,   426,   428,   430,   432,   434,   436,   438,   440,   443,
     464,   444,   455,   459,   462,   465,   466,   470,   474,   478,
     482,   486,   491,   496,   501,   506,   510,   514,   518,   536,
     540,   543,   541,   546,   534,   548,   549,   550,   551,   552,
     557,   558,   559,   572,   573,   574,   575,   576,   579,   590,
     578,   592,   577,   581,   584,   586,   593,   587,   594,   544,
     595,   596,   637,   582,   638,   639,   652,   653,   654,   660,
     663,   588,   651,   658,   661,   666,   665,   670,   672,   683,
     684,   673,   676,   685,   686,   687,   688,   667,   689,   674,
     690,   692,   693,   694,   696,   691,   697,   698,   713,   714,
     715,     0,   771,   750,   728,   719,   720,   721,   722,   726,
     731,   727,   734,   733,   739,   744,   746,   773,   748,   747,
     712,   772,   774,   752,   775,   779,     0,   780,   783,   781,
       0,   785,   963,   786,   791,   796,   800,   805,   807,   836,
     876,   808,   809,   695,   812,   813,   814,   815,   816,   817,
     818,   819,   820,   821,   822,   753,   823,   827,   828,   829,
     831,   840,   871,   754,   878,     0,   879,   884,   885,   886,
     904,   936,   937,   938,   755,   940,   941,     0,   756,   769,
     770,   939,   942,   944,   945,   955,   964,   960,   965,   966,
     967,   968,   969,   980,   981,   982,     0,   984,   985,   986,
     983,   989,  1015,     0,   988,  1007,  1011,     0,  1073,  1014,
     943,  1025,  1054,  1055,  1077,  1080,  1013,  1081,  1082,  1084,
    1085,     0,     0,  1086,  1087,  1088,  1089,   987,  1090,  1091,
    1092,  1093,  1096,  1097,  1108,  1109,  1110,     0,  1112,  1113,
    1079,  1111,  1053,  1114,  1095,  1115,  1116,  1156,  1117,  1118,
    1119,  1120,  1121,  1124,  1125,  1126,  1128,  1129,  1200,     0,
    1130,  1131,  1132,  1133,  1123,  1134,  1135,  1136,  1137,  1152,
    1154,  1153,  1158,  1157,  1180,  1176,     0,  1182,  1181,     0,
    1197,  1198,  1199,  1201,  1202,  1203,  1204,  1205,  1268,     0,
    1207,  1206,  1224,  1210,  1211,  1212,  1214,  1215,  1216,  1217,
    1218,  1219,  1220,  1221,  1222,  1223,  1225,  1226,  1227,  1228,
    1233,     0,  1229,  1270,  1241,  1234,  1242,  1255,     0,     0,
    1259,  1260,  1261,  1262,  1264,  1265,  1266,  1267,  1269,  1271,
    1272,  1273,  1274,  1291,     0,  1275,  1276,  1285,  1289,     0,
    1290,  1292,  1293,  1294,  1295,  1296,  1298,     0,  1299
};

static const yytype_int16 yycheck[] =
{
       4,    82,     5,     6,     5,     4,    81,     5,     6,     5,
       6,     4,    81,     5,     6,     4,     4,     4,     4,    82,
       4,     4,    82,    81,     4,    54,     8,     9,    50,     8,
       9,     9,     0,    67,    51,     8,     9,    59,    12,    61,
      53,    63,     8,    65,    55,    67,    16,    69,    13,    71,
      79,    73,    57,    75,    14,    77,    15,    79,    40,    56,
      16,    40,    91,    42,    98,    47,    48,    40,   131,    42,
     128,    49,    45,    46,   155,   144,     3,   152,    64,    62,
      60,    68,    79,    76,    72,    74,    70,   147,    84,    90,
      88,    94,    96,    92,    86,    43,    93,    43,    95,    43,
      97,     3,    99,     7,   101,     8,     9,     8,     8,     9,
     107,    16,   109,     3,   111,   105,   113,    52,   115,   131,
     117,     3,   119,     3,   121,     8,   123,     8,     9,     7,
     142,     4,   122,     4,   105,     5,   105,    40,   105,    42,
      40,     8,    45,    46,    79,    45,    46,   116,    83,   120,
      85,   118,    87,    17,    89,   127,    23,    24,    25,    40,
     103,    42,     8,     9,    45,    46,     8,     9,     7,   103,
      37,   114,    39,     8,     7,    42,     7,    44,   112,   103,
     131,    23,    24,    25,     8,     9,   110,   138,    23,    24,
      25,     8,     9,    39,   103,     8,    42,    39,    44,   108,
      42,    19,    44,    38,    39,     8,     9,    42,    18,    44,
      23,    24,    25,     8,     9,    39,     8,     9,    42,   131,
      44,    43,    39,    36,   136,    42,    39,    44,    18,    42,
      18,    44,     8,     9,     8,     9,    39,     8,     9,    42,
      18,    44,     8,     9,    27,    40,   100,    42,    40,   103,
      42,     8,     9,    16,     8,     9,    30,    31,    32,   131,
     147,    19,   134,   150,    40,    18,    42,     8,     9,    40,
     155,    42,    26,   158,    40,    18,    42,     8,     9,    20,
      21,    22,    36,    40,    19,    42,    19,    41,     7,    20,
      21,    22,     8,     9,     8,     8,     9,    64,    10,    11,
       8,     9,     8,     9,    20,    21,    22,    20,    21,    22,
       8,     9,     8,     9,     8,     9,     8,     9,     8,     9,
       8,     9,     8,     9,     8,     9,     8,     9,     8,     9,
       8,     9,     8,     9,     8,     9,     8,     9,     8,     9,
       8,     9,     8,     9,     8,     9,    80,    81,     8,     9,
      80,    81,     8,     9,    80,    81,     8,     9,   102,   103,
     124,   125,    80,    81,     8,     9,   160,   161,   130,   131,
       5,   146,   147,   154,   155,   140,   141,     5,     6,    60,
       7,    66,     7,    62,     7,    68,    33,    74,   143,    78,
       5,    58,     5,    70,     5,     3,     8,    72,     7,    90,
       7,     5,     8,    76,     7,   151,     8,     7,    34,     8,
       7,   159,     8,     7,    35,     8,     7,    86,     8,     7,
     129,     8,     7,    84,     8,     7,    84,     8,     7,    86,
       8,     7,    94,     8,     7,    88,     8,     7,     7,     7,
      88,     7,     7,     7,     7,     7,     5,     5,     5,     5,
       5,     5,     5,     5,     5,     5,     5,     5,     5,    92,
      94,     7,     7,     5,     7,    96,     7,     7,     7,     7,
       7,     7,     7,     7,     7,     7,     7,     7,     7,     7,
       5,     7,   145,   133,    28,     8,     8,     8,     8,     8,
       8,     8,     8,    82,     3,     3,     3,     7,   153,   135,
       5,     4,     8,     7,   149,     7,     4,     8,     4,    36,
       4,     4,     4,    37,     4,     4,     3,     3,     3,     7,
     157,    36,    82,     5,    38,     8,     7,     5,     7,   106,
       3,     8,   137,     3,     3,   106,     3,    37,     3,    36,
       3,     3,     3,     3,     3,   106,     3,     3,     3,     3,
       3,    -1,   126,   139,    38,     7,     7,     7,     7,     7,
       5,     8,     8,     7,     7,     5,     7,     3,    36,     8,
      82,    82,     3,    68,     3,     7,    -1,     7,     5,     7,
      -1,     7,   162,     8,     7,     5,     7,     5,     7,     5,
       5,     8,    29,   106,     7,     7,     7,     7,     7,     7,
       7,     7,     7,     7,     7,   104,     7,     7,     7,     7,
       7,     7,     7,   104,     7,    -1,     8,     7,     7,     7,
       7,     3,     3,     3,   104,     3,     3,    -1,   104,   104,
     104,     7,     3,     7,     3,     7,     3,     5,     3,     3,
       3,     3,     3,     3,     3,     3,    -1,     3,     3,     3,
       7,     3,     3,    -1,     7,     5,     5,    -1,     5,     7,
     132,     7,     7,     3,     5,     7,   132,     3,     3,     7,
       7,    -1,    -1,     7,     7,     7,     7,   148,     7,     7,
       7,     5,     7,     3,     3,     3,     3,    -1,     3,     3,
     148,     7,   156,     3,   132,     7,     7,   132,     7,     7,
       7,     7,     5,     7,     3,     3,     7,     7,   132,    -1,
       7,     7,     7,     7,   156,     7,     7,     7,     5,     7,
       5,     7,     3,     7,     7,     5,    -1,     5,     7,    -1,
       7,     7,     7,     7,     3,     3,     3,     7,   132,    -1,
       5,     7,   156,     7,     7,     7,     7,     7,     7,     7,
       7,     7,     7,     7,     7,     7,     7,     3,     3,     3,
       7,    -1,     5,     3,     5,     7,     5,     5,    -1,    -1,
       7,     7,     7,     7,     7,     7,     7,     7,     7,     3,
       3,     7,     7,     3,    -1,     7,     7,     5,   132,    -1,
       7,     7,     7,     7,     7,     5,     7,    -1,     7
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,    10,    11,   165,   166,    12,     0,     9,    49,   167,
     168,   169,     8,    13,    51,   233,   234,     8,     9,   170,
      53,   273,   274,     8,     9,   235,   171,    55,   298,   299,
       8,     9,   275,   236,    50,    59,    61,    63,    65,    67,
      69,    71,    73,    75,    77,    79,   172,   173,   174,   177,
     178,   181,   182,   185,   186,   191,   192,   195,   196,   199,
     200,   203,   204,   207,   208,   211,   212,   217,   218,    57,
     436,   437,     8,     9,   300,   276,    52,    79,    83,    85,
      87,    89,   237,   238,   239,   243,   244,   248,   249,   253,
     254,   257,   258,     8,     9,   175,     8,     9,   179,     8,
       9,   183,    14,   187,     8,     9,   193,     8,     9,   197,
       8,     9,   201,     8,     9,   205,     8,     9,   209,    15,
     213,    16,   219,   438,   301,    54,    79,    91,   277,   278,
     279,   282,   283,    43,   240,    43,   245,    43,   250,     8,
       9,   255,    16,   259,     4,    60,     4,    62,     4,    64,
       3,     8,     9,   189,     4,    68,     4,    70,     4,    72,
       4,    74,     4,    76,     3,     8,     9,   215,     7,     8,
       8,     9,    30,    31,    32,   439,   440,   441,   442,   443,
      56,    79,    93,    95,    97,    99,   101,   107,   109,   111,
     113,   115,   117,   119,   121,   123,   302,   303,   304,   308,
     309,   312,   313,   318,   319,   324,   325,   330,   331,   336,
     337,   342,   343,   357,   358,   372,   373,   387,   388,   402,
     403,   408,   409,   414,   415,   420,   421,     8,     9,   280,
      16,   284,     3,     8,     9,   242,     3,     8,     9,   247,
       3,     8,     9,   252,     5,    90,     7,     8,   176,   180,
     184,   188,     4,   190,   194,   198,   202,   206,   210,   214,
       4,   216,     5,   220,   221,   127,   444,   445,   446,     7,
       7,     7,    43,   305,     8,     9,   310,    17,   314,    18,
     320,    18,   326,    18,   332,    18,   338,    19,   344,    19,
     359,    19,   374,    19,   389,    18,   404,    18,   410,    27,
     416,    16,   422,     4,    92,     7,     8,   241,     5,     6,
      84,   246,     5,     6,    86,   251,     5,     6,    88,   256,
       5,   260,   261,    60,    62,    64,     7,    66,    68,    70,
      72,    74,    76,     7,    78,     7,    80,    81,   222,    58,
     143,   545,   546,    33,   447,     5,     5,     5,     3,     8,
       9,   307,     4,    96,     7,     8,     7,     8,     7,     8,
       7,     8,     7,     8,     7,     8,     7,     8,     7,     8,
       7,     8,     7,     8,     7,     8,     7,     8,     7,     8,
     281,     5,   285,   286,     7,    84,    84,     7,    86,    86,
       7,    88,    88,    90,     7,    80,    81,   262,   223,   151,
     605,   606,    34,   547,     7,     8,     9,   448,     7,     7,
       7,   306,     5,     6,    94,   311,     5,   315,     5,   321,
       5,   327,     5,   333,     5,   339,     5,   345,     5,   360,
       5,   375,     5,   390,     5,   405,     5,   411,     5,   417,
       5,   423,   424,    92,     7,    80,    81,   287,   263,   224,
     159,   665,   666,    35,   607,     7,     8,     9,   548,     5,
     129,   449,     7,    94,    94,    96,     7,    67,    98,   316,
       7,   100,   103,   322,     7,   102,   103,   328,     7,   103,
     108,   334,     7,   103,   110,   340,     7,   105,   116,   346,
     347,     7,   105,   118,   361,   362,     7,   105,   120,   376,
     377,     7,   105,   122,   391,   392,     7,   103,   114,   406,
       7,   103,   112,   412,     7,   124,   125,   418,     7,    80,
      81,   425,   288,   264,     8,     9,    39,    42,    44,   225,
     226,   228,   230,   232,    28,   667,     7,     8,     9,   608,
       5,   145,   549,     7,    36,   450,   133,   460,     8,     8,
       8,     8,     8,   348,   363,   378,   393,     8,     8,     8,
     426,   289,     8,     9,    39,    42,    44,   265,   266,   268,
     270,   272,    82,     3,     3,     3,     7,     8,     5,   153,
     609,     7,    37,   550,   149,   560,     7,     8,    36,   461,
     135,   471,     4,     4,     4,     4,     4,     8,     9,    20,
      21,    22,   349,   350,   352,   354,   356,     8,     9,    20,
      21,    22,   364,   365,   367,   369,   371,     8,     9,    20,
      21,    22,   379,   380,   382,   384,   386,     8,     9,    20,
      21,    22,   394,   395,   397,   399,   401,     4,     4,     4,
     427,     8,     9,    39,    42,    44,   290,   291,   293,   295,
     297,    82,     3,     3,     3,   227,   229,   231,     5,   668,
       7,    38,   610,   157,   620,     7,     8,    37,   561,   573,
       5,   451,     7,     8,    36,   472,   137,   482,   317,   323,
     329,   335,   341,   106,     3,     3,     3,   106,     3,     3,
       3,   106,     3,     3,     3,   106,     3,     3,     3,   407,
     413,   419,     8,     9,    39,    42,    44,   428,   429,   431,
     433,   435,    82,     3,     3,     3,   267,   269,   271,     7,
       7,     7,     7,   160,   161,   669,     7,     8,    38,   621,
     633,     5,   551,     7,     8,    81,   144,   574,   575,     7,
     130,   131,   452,   453,     5,   462,     7,     8,    36,   483,
     139,   493,    68,   104,   104,   104,   104,   351,   353,   355,
     366,   368,   370,   381,   383,   385,   396,   398,   400,   104,
     104,   126,    82,     3,     3,     3,   292,   294,   296,     7,
       7,     7,   670,     5,   611,     7,     8,    81,   152,   634,
     635,     7,   146,   147,   552,   553,     5,   562,   576,   454,
       7,   131,   134,   463,   464,     5,   473,     7,     8,    29,
     494,   513,     7,     7,     7,     7,     7,     7,     7,     7,
       7,     7,     7,     7,   430,   432,   434,     7,     7,     7,
     671,     7,   154,   155,   612,   613,     5,   622,   636,   554,
       7,   147,   150,   563,   564,     8,    23,    24,    25,    37,
      39,    42,    44,   577,   578,   579,   581,   583,   585,   587,
     589,   591,     8,     9,    40,    42,   455,   456,   457,   459,
     465,     7,   131,   136,   474,   475,     5,   484,     7,     8,
      81,   128,   514,   515,     7,     7,     7,     8,     9,    23,
      24,    25,    39,    42,    44,   672,   673,   675,   677,   679,
     681,   683,   685,   614,     7,   155,   158,   623,   624,     8,
      23,    24,    25,    38,    39,    42,    44,   637,   638,   639,
     641,   643,   645,   647,   649,   651,     8,     9,    40,    42,
     555,   556,   557,   559,   565,   592,     3,     3,     3,     7,
       3,     3,     3,   132,     7,     3,     8,     9,    40,    42,
     466,   467,   468,   470,   476,     7,   131,   138,   485,   486,
       5,   495,   516,   162,     3,     3,     3,     3,     3,     3,
       8,     9,    40,    42,   615,   616,   617,   619,   625,   652,
       3,     3,     3,     7,     3,     3,     3,   148,     7,     3,
       8,     9,    40,    45,    46,   566,   567,   568,   570,   572,
      82,   147,   593,   594,   584,   586,   588,     5,   580,   582,
     590,     5,   458,   132,     7,     3,     8,     9,    40,    42,
     477,   478,   479,   481,   487,     7,   140,   141,   496,   497,
       8,    23,    24,    25,    36,    39,    42,    44,   517,   518,
     519,   521,   523,   525,   527,   529,   531,   678,   680,   682,
     674,   676,   684,   156,     7,     3,     8,     9,    40,    47,
      48,   626,   627,   628,   630,   632,    82,   155,   653,   654,
     644,   646,   648,     5,   640,   642,   650,     5,   558,   148,
       7,     3,     3,   595,     7,     7,     7,     7,     7,     7,
       7,     7,     7,     5,   469,   132,     7,     3,     8,     9,
      40,    42,   488,   489,   490,   492,   498,   532,     3,     3,
       3,     7,     3,     3,     3,     7,     7,     7,     7,     7,
       7,     5,   618,   156,     7,     3,     3,   655,     7,     7,
       7,     7,     7,     7,     7,     7,     7,     5,   569,   571,
       8,     9,    40,    42,    45,    46,   596,   597,   598,   600,
     602,   604,     7,     7,     5,   480,   132,     7,     3,     8,
       9,    26,    36,    41,   499,   500,   501,   502,   503,    82,
     131,   533,   534,   524,   526,   528,     5,   520,   522,   530,
       7,     7,     5,   629,   631,     8,     9,    40,    42,    45,
      46,   656,   657,   658,   660,   662,   664,     7,     7,     7,
     132,     7,     3,     3,     3,     7,     7,     5,   491,   504,
       7,     7,     7,   535,     7,     7,     7,     7,     7,     7,
       7,     7,     7,     7,   156,     7,     3,     3,     3,     5,
     599,   601,   603,     7,     7,   131,   142,   505,   506,     5,
       6,     5,     5,     8,     9,    40,    42,    45,    46,   536,
     537,   538,   540,   542,   544,     5,   659,   661,   663,     7,
       7,     7,     7,   507,     7,     7,     7,     7,   132,     7,
       3,     3,     3,     7,     7,     7,     7,     8,     9,    40,
      42,   508,   509,   510,   512,     5,   539,   541,   543,   132,
       7,     3,     7,     7,     7,     7,     5,   511,     7,     7
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
		osoption->general->instanceLocation->locationType = "local";
	}
;}
    break;

  case 46:

    {	if ( (strcmp((yyvsp[(2) - (2)].sval), "local") == 0) || (strcmp((yyvsp[(2) - (2)].sval), "http") == 0) || (strcmp((yyvsp[(2) - (2)].sval), "ftp") == 0) )
		osoption->general->instanceLocation->locationType = (yyvsp[(2) - (2)].sval);
	else
		osolerror( NULL, osoption, parserData, "Not a valid locationType");
;}
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
		osoption->general->contact->transportType = "osp";
	}
;}
    break;

  case 85:

    {	if ( (strcmp((yyvsp[(2) - (2)].sval),"osp") == 0) || (strcmp((yyvsp[(2) - (2)].sval),"smtp") == 0) || (strcmp((yyvsp[(2) - (2)].sval),"http")  == 0) || 
						  (strcmp((yyvsp[(2) - (2)].sval),"ftp")  == 0) || (strcmp((yyvsp[(2) - (2)].sval),"other") == 0) )
		osoption->general->contact->transportType = (yyvsp[(2) - (2)].sval);
	else
		osolerror( NULL, osoption, parserData, "Not a valid transport type");
;}
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

    {	if ((yyvsp[(3) - (4)].ival) < 0)
		osolerror( NULL, osoption, parserData, "Number of <other> elements cannot be negative");
	osoption->general->otherOptions->numberOfOtherOptions = (yyvsp[(3) - (4)].ival);
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
	{	parserData->minDiskSpacePresent = true;
		osoption->system->minDiskSpace = new MinDiskSpace();
		osoption->system->minDiskSpace->unit = "byte";
	}
;}
    break;

  case 127:

    {	if ( (strcmp((yyvsp[(2) - (2)].sval),"byte") == 0) || (strcmp((yyvsp[(2) - (2)].sval),"kilobyte") == 0) || (strcmp((yyvsp[(2) - (2)].sval),"megabyte") == 0) || 
						   (strcmp((yyvsp[(2) - (2)].sval),"terabyte") == 0) || (strcmp((yyvsp[(2) - (2)].sval),"petabyte") == 0) )
		osoption->system->minDiskSpace->unit = (yyvsp[(2) - (2)].sval);
	else
		osolerror( NULL, osoption, parserData, "Not a valid unit");
;}
    break;

  case 131:

    {	if ((yyvsp[(2) - (3)].dval) < 0)
		osolerror( NULL, osoption, parserData, "minDiskSpace cannot be negative");
	osoption->system->minDiskSpace->value = (yyvsp[(2) - (3)].dval);
;}
    break;

  case 132:

    {	if ((yyvsp[(2) - (3)].ival) < 0)
		osolerror( NULL, osoption, parserData, "minDiskSpace cannot be negative");
	osoption->system->minDiskSpace->value = (yyvsp[(2) - (3)].ival);
;}
    break;

  case 134:

    {	if (parserData->minMemorySizePresent)
	{	osolerror( NULL, osoption, parserData, "only one <minMemorySize> element allowed");
	}
	else
	{	parserData->minMemorySizePresent = true;
		osoption->system->minMemorySize = new MinMemorySize();
		osoption->system->minMemorySize->unit = "byte";
	}
;}
    break;

  case 136:

    {	if ( (strcmp((yyvsp[(2) - (2)].sval),"byte") == 0) || (strcmp((yyvsp[(2) - (2)].sval),"kilobyte") == 0) || (strcmp((yyvsp[(2) - (2)].sval),"megabyte") == 0) || 
						   (strcmp((yyvsp[(2) - (2)].sval),"terabyte") == 0) || (strcmp((yyvsp[(2) - (2)].sval),"petabyte") == 0) )
		osoption->system->minMemorySize->unit = (yyvsp[(2) - (2)].sval);
	else
		osolerror( NULL, osoption, parserData, "Not a valid unit");
;}
    break;

  case 140:

    {	if ((yyvsp[(2) - (3)].dval) < 0)
		osolerror( NULL, osoption, parserData, "minMemorySize cannot be negative");
	osoption->system->minMemorySize->value = (yyvsp[(2) - (3)].dval);
;}
    break;

  case 141:

    {	if ((yyvsp[(2) - (3)].ival) < 0)
		osolerror( NULL, osoption, parserData, "minMemorySize cannot be negative");
	osoption->system->minMemorySize->value = (yyvsp[(2) - (3)].ival);
;}
    break;

  case 143:

    {	if (parserData->minCPUSpeedPresent)
	{	osolerror( NULL, osoption, parserData, "only one <minCPUSpeed> element allowed");
	}
	else
	{	parserData->minCPUSpeedPresent = true;
		osoption->system->minCPUSpeed = new MinCPUSpeed();
		osoption->system->minCPUSpeed->unit = "hertz";
	}
;}
    break;

  case 145:

    {	if ( (strcmp((yyvsp[(2) - (2)].sval),    "hertz") == 0) || (strcmp((yyvsp[(2) - (2)].sval),"kilohertz") == 0) || (strcmp((yyvsp[(2) - (2)].sval),"megahertz") == 0) || 
	     (strcmp((yyvsp[(2) - (2)].sval),"gigahertz") == 0) || (strcmp((yyvsp[(2) - (2)].sval),"terahertz") == 0) || (strcmp((yyvsp[(2) - (2)].sval),"petahertz") == 0) ||
	     (strcmp((yyvsp[(2) - (2)].sval),    "flops") == 0) || (strcmp((yyvsp[(2) - (2)].sval),"kiloflops") == 0) || (strcmp((yyvsp[(2) - (2)].sval),"megaflops") == 0) || 
	     (strcmp((yyvsp[(2) - (2)].sval),"gigaflops") == 0) || (strcmp((yyvsp[(2) - (2)].sval),"teraflops") == 0) || (strcmp((yyvsp[(2) - (2)].sval),"petahertz") == 0) ) 
		osoption->system->minCPUSpeed->unit = (yyvsp[(2) - (2)].sval);
	else
		osolerror( NULL, osoption, parserData, "Not a valid unit");
;}
    break;

  case 149:

    {	if ((yyvsp[(2) - (3)].dval) < 0)
		osolerror( NULL, osoption, parserData, "minCPUSpeed cannot be negative");
	osoption->system->minCPUSpeed->value = (yyvsp[(2) - (3)].dval);
;}
    break;

  case 150:

    {	if ((yyvsp[(2) - (3)].ival) < 0)
		osolerror( NULL, osoption, parserData, "minCPUSpeed cannot be negative");
	osoption->system->minCPUSpeed->value = (yyvsp[(2) - (3)].ival);
;}
    break;

  case 152:

    {	if (parserData->minCPUNumberPresent)
	{	osolerror( NULL, osoption, parserData, "only one <minCPUNumber> element allowed");
	}
	else
	{	parserData->minCPUNumberPresent = true;
	}
;}
    break;

  case 155:

    {	if ((yyvsp[(2) - (2)].ival) < 0)
		osolerror( NULL, osoption, parserData, "minCPUNumber cannot be negative");
	osoption->system->minCPUNumber = (yyvsp[(2) - (2)].ival);
;}
    break;

  case 158:

    {	if (parserData->otherSystemOptionsPresent)
	{	osolerror( NULL, osoption, parserData, "only one <otherOptions> element allowed");
	}
	else
	{	parserData->otherSystemOptionsPresent = true;
		osoption->system->otherOptions = new OtherOptions();
	}
;}
    break;

  case 159:

    {	if ((yyvsp[(3) - (4)].ival) < 0)
		osolerror( NULL, osoption, parserData, "Number of <other> elements cannot be negative");
	osoption->system->otherOptions->numberOfOtherOptions = (yyvsp[(3) - (4)].ival);
	osoption->system->otherOptions->other = new OtherOption*[(yyvsp[(3) - (4)].ival)];
	for (int i=0; i < (yyvsp[(3) - (4)].ival); i++) osoption->system->otherOptions->other[i] = new OtherOption();
;}
    break;

  case 160:

    {	if (parserData->numberOfOtherSystemOptions != osoption->system->otherOptions->numberOfOtherOptions)
		osolerror (NULL, osoption, parserData, "wrong number of other options in <system> element");
;}
    break;

  case 163:

    {	if (parserData->numberOfOtherSystemOptions >= osoption->system->otherOptions->numberOfOtherOptions)
		{	osolerror (NULL, osoption, parserData, "too many other options in <system> element");
		};
	;}
    break;

  case 164:

    {	if (!parserData->otherOptionNamePresent)
		osolerror (NULL, osoption, parserData, "name attribute must be present");
	/* reset defaults for the next option */
	parserData->otherOptionNamePresent = false;
	parserData->otherOptionValuePresent = false;
	parserData->otherOptionDescriptionPresent = false;
	parserData->numberOfOtherSystemOptions++;
;}
    break;

  case 170:

    {	if (parserData->otherOptionNamePresent)
	{	osolerror( NULL, osoption, parserData, "only one name attribute allowed");
	}
	else
	{	parserData->otherOptionNamePresent = true;
		osoption->system->otherOptions->other[parserData->numberOfOtherSystemOptions]->name = (yyvsp[(2) - (2)].sval);
	}
;}
    break;

  case 172:

    {	if (parserData->otherOptionValuePresent)
	{	osolerror( NULL, osoption, parserData, "only one value attribute allowed");
	}
	else
	{	parserData->otherOptionValuePresent = true;
		osoption->system->otherOptions->other[parserData->numberOfOtherSystemOptions]->value = (yyvsp[(2) - (2)].sval);
	}
;}
    break;

  case 174:

    {	if (parserData->otherOptionDescriptionPresent)
	{	osolerror( NULL, osoption, parserData, "only one description attribute allowed");
	}
	else
	{	parserData->otherOptionDescriptionPresent = true;
		osoption->system->otherOptions->other[parserData->numberOfOtherSystemOptions]->description = (yyvsp[(2) - (2)].sval);
	}
;}
    break;

  case 180:

    {	if (parserData->osolservicePresent)
	{	osolerror( NULL, osoption, parserData, "only one <service> element allowed");
	}
	else
	{	parserData->osolservicePresent = true;
		osoption->service = new ServiceOption();
	}
;}
    break;

  case 188:

    {	if (parserData->serviceTypePresent)
	{	osolerror( NULL, osoption, parserData, "only one <type> element allowed");
	}
	else
	{	parserData->serviceTypePresent = true;
		osoption->service->type = "solver";
	}
;}
    break;

  case 191:

    {	if ( (strcmp((yyvsp[(2) - (2)].sval),"solver") == 0) || (strcmp((yyvsp[(2) - (2)].sval),"analyzer")   == 0) || (strcmp((yyvsp[(2) - (2)].sval),"scheduler") == 0) ||
						     (strcmp((yyvsp[(2) - (2)].sval),"simulation") == 0) || (strcmp((yyvsp[(2) - (2)].sval),"registry")  == 0) ||
						     (strcmp((yyvsp[(2) - (2)].sval),"modeler")    == 0) || (strcmp((yyvsp[(2) - (2)].sval),"agent")     == 0) ) 
		osoption->service->type = (yyvsp[(2) - (2)].sval);
	else
		osolerror( NULL, osoption, parserData, "Not a valid service type");
;}
    break;

  case 194:

    {	if (parserData->otherServiceOptionsPresent)
	{	osolerror( NULL, osoption, parserData, "only one <otherOptions> element allowed");
	}
	else
	{	parserData->otherServiceOptionsPresent = true;
		osoption->service->otherOptions = new OtherOptions();
	}
;}
    break;

  case 195:

    {	if ((yyvsp[(3) - (4)].ival) < 0)
		osolerror( NULL, osoption, parserData, "Number of <other> elements cannot be negative");
	osoption->service->otherOptions->numberOfOtherOptions = (yyvsp[(3) - (4)].ival);
	osoption->service->otherOptions->other = new OtherOption*[(yyvsp[(3) - (4)].ival)];
	for (int i=0; i < (yyvsp[(3) - (4)].ival); i++) osoption->service->otherOptions->other[i] = new OtherOption();
;}
    break;

  case 196:

    {	if (parserData->numberOfOtherServiceOptions != osoption->service->otherOptions->numberOfOtherOptions)
		osolerror (NULL, osoption, parserData, "wrong number of other options in <service> element");
;}
    break;

  case 199:

    {	if (parserData->numberOfOtherServiceOptions >= osoption->service->otherOptions->numberOfOtherOptions)
		{	osolerror (NULL, osoption, parserData, "too many other options in <service> element");
		};
	;}
    break;

  case 200:

    {	if (!parserData->otherOptionNamePresent)
		osolerror (NULL, osoption, parserData, "name attribute must be present");
	/* reset defaults for the next option */
	parserData->otherOptionNamePresent = false;
	parserData->otherOptionValuePresent = false;
	parserData->otherOptionDescriptionPresent = false;
	parserData->numberOfOtherServiceOptions++;
;}
    break;

  case 206:

    {	if (parserData->otherOptionNamePresent)
	{	osolerror( NULL, osoption, parserData, "only one name attribute allowed");
	}
	else
	{	parserData->otherOptionNamePresent = true;
		osoption->service->otherOptions->other[parserData->numberOfOtherServiceOptions]->name = (yyvsp[(2) - (2)].sval);
	}
;}
    break;

  case 208:

    {	if (parserData->otherOptionValuePresent)
	{	osolerror( NULL, osoption, parserData, "only one value attribute allowed");
	}
	else
	{	parserData->otherOptionValuePresent = true;
		osoption->service->otherOptions->other[parserData->numberOfOtherServiceOptions]->value = (yyvsp[(2) - (2)].sval);
	}
;}
    break;

  case 210:

    {	if (parserData->otherOptionDescriptionPresent)
	{	osolerror( NULL, osoption, parserData, "only one description attribute allowed");
	}
	else
	{	parserData->otherOptionDescriptionPresent = true;
		osoption->service->otherOptions->other[parserData->numberOfOtherServiceOptions]->description = (yyvsp[(2) - (2)].sval);
	}
;}
    break;

  case 216:

    {	if (parserData->osoljobPresent)
	{	osolerror( NULL, osoption, parserData, "only one <job> element allowed");
	}
	else
	{	parserData->osoljobPresent = true;
		osoption->job = new JobOption();
	}
;}
    break;

  case 237:

    {	if (parserData->maxTimePresent)
	{	osolerror( NULL, osoption, parserData, "only one <maxTime> element allowed");
	}
	else
	{	parserData->maxTimePresent = true;
		osoption->job->maxTime = new MaxTime();
		osoption->job->maxTime->unit = "second"; 
	}
;}
    break;

  case 239:

    {	if ( (strcmp((yyvsp[(2) - (2)].sval),"second") == 0) || (strcmp((yyvsp[(2) - (2)].sval),"minute") == 0) || (strcmp((yyvsp[(2) - (2)].sval),"hour") == 0) ||
						     (strcmp((yyvsp[(2) - (2)].sval),"day")    == 0) || (strcmp((yyvsp[(2) - (2)].sval),"week") == 0) ||
						     (strcmp((yyvsp[(2) - (2)].sval),"month")  == 0) || (strcmp((yyvsp[(2) - (2)].sval),"year") == 0) ) 
                osoption->job->maxTime->unit = (yyvsp[(2) - (2)].sval);
	else
		osolerror( NULL, osoption, parserData, "Not a valid time unit");
;}
    break;

  case 243:

    {	if ((yyvsp[(2) - (3)].dval) < 0)
		osolerror( NULL, osoption, parserData, "maxTime cannot be negative");
	osoption->job->maxTime->value = (yyvsp[(2) - (3)].dval);
;}
    break;

  case 244:

    {	if ((yyvsp[(2) - (3)].ival) < 0)
		osolerror( NULL, osoption, parserData, "maxTime cannot be negative");
	osoption->job->maxTime->value = (yyvsp[(2) - (3)].ival);
;}
    break;

  case 246:

    {	if (parserData->requestedStartTimePresent)
	{	osolerror( NULL, osoption, parserData, "only one <requestedStartTime> element allowed");
	}
	else
	{	parserData->requestedStartTimePresent = true;
		osoption->job->requestedStartTime = "1970-01-01T00:00:00-00:00";
	}
;}
    break;

  case 249:

    {osoption->job->requestedStartTime = (yyvsp[(2) - (2)].sval);;}
    break;

  case 252:

    {	if (parserData->dependenciesPresent)
	{	osolerror( NULL, osoption, parserData, "only one <dependencies> element allowed");
	}
	else
	{	parserData->dependenciesPresent = true;
		osoption->job->dependencies = new JobDependencies();
	}
;}
    break;

  case 253:

    {	if ((yyvsp[(3) - (4)].ival) < 1)
		osolerror( NULL, osoption, parserData, "Number of job IDs must be at least 1");
	osoption->job->dependencies->numberOfJobIDs = (yyvsp[(3) - (4)].ival);
	osoption->job->dependencies->jobID = new std::string[(yyvsp[(3) - (4)].ival)];
;}
    break;

  case 256:

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

  case 259:

    {	if (parserData->requiredDirectoriesPresent)
	{	osolerror( NULL, osoption, parserData, "only one <requiredDirectories> element allowed");
	}
	else
	{	parserData->requiredDirectoriesPresent = true;
		osoption->job->requiredDirectories = new DirectoriesAndFiles();
	}
;}
    break;

  case 260:

    {	if ((yyvsp[(3) - (4)].ival) < 1)
		osolerror( NULL, osoption, parserData, "Number of paths must be at least 1");
	osoption->job->requiredDirectories->numberOfPaths = (yyvsp[(3) - (4)].ival);
	osoption->job->requiredDirectories->path = new std::string[(yyvsp[(3) - (4)].ival)];
;}
    break;

  case 263:

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

  case 266:

    {	if (parserData->requiredFilesPresent)
	{	osolerror( NULL, osoption, parserData, "only one <requiredFiles> element allowed");
	}
	else
	{	parserData->requiredFilesPresent = true;
		osoption->job->requiredFiles = new DirectoriesAndFiles();
	}
;}
    break;

  case 267:

    {	if ((yyvsp[(3) - (4)].ival) < 1)
		osolerror( NULL, osoption, parserData, "Number of paths must be at least 1");
	osoption->job->requiredFiles->numberOfPaths = (yyvsp[(3) - (4)].ival);
	osoption->job->requiredFiles->path = new std::string[(yyvsp[(3) - (4)].ival)];
;}
    break;

  case 270:

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

  case 273:

    {	if (parserData->directoriesToMakePresent)
	{	osolerror( NULL, osoption, parserData, "only one <directoriesToMake> element allowed");
	}
	else
	{	parserData->directoriesToMakePresent = true;
		osoption->job->directoriesToMake = new DirectoriesAndFiles();
	}
;}
    break;

  case 274:

    {	if ((yyvsp[(3) - (4)].ival) < 1)
		osolerror( NULL, osoption, parserData, "Number of paths must be at least 1");
	osoption->job->directoriesToMake->numberOfPaths = (yyvsp[(3) - (4)].ival);
	osoption->job->directoriesToMake->path = new std::string[(yyvsp[(3) - (4)].ival)];
;}
    break;

  case 277:

    {	if (parserData->numberOfDirectoriesToMake >= osoption->job->directoriesToMake->numberOfPaths)
	{	osolerror (NULL, osoption, parserData, "too many job IDs in <directoriesToMake> element");
	}
	else
	{	osoption->job->directoriesToMake->path[parserData->numberOfDirectoriesToMake] = (yyvsp[(3) - (3)].sval);
		parserData->numberOfDirectoriesToMake++;
	};
;}
    break;

  case 280:

    {	if (parserData->filesToMakePresent)
	{	osolerror( NULL, osoption, parserData, "only one <filesToMake> element allowed");
	}
	else
	{	parserData->filesToMakePresent = true;
		osoption->job->filesToMake = new DirectoriesAndFiles();
	}
;}
    break;

  case 281:

    {	if ((yyvsp[(3) - (4)].ival) < 0)
		osolerror( NULL, osoption, parserData, "Number of paths cannot be negative");
	osoption->job->filesToMake->numberOfPaths = (yyvsp[(3) - (4)].ival);
	osoption->job->filesToMake->path = new std::string[(yyvsp[(3) - (4)].ival)];
;}
    break;

  case 284:

    {	if (parserData->numberOfFilesToMake >= osoption->job->filesToMake->numberOfPaths)
	{	osolerror (NULL, osoption, parserData, "too many job IDs in <filesToMake> element");
	}
	else
	{	osoption->job->filesToMake->path[parserData->numberOfFilesToMake] = (yyvsp[(3) - (3)].sval);
		parserData->numberOfFilesToMake++;
	};
;}
    break;

  case 287:

    {	if (parserData->inputDirectoriesToMovePresent)
	{	osolerror( NULL, osoption, parserData, "only one <inputDirectoriesToMove> element allowed");
	}
	else
	{	parserData->inputDirectoriesToMovePresent = true;
		osoption->job->inputDirectoriesToMove = new PathPairs();
	}
;}
    break;

  case 288:

    {	if ((yyvsp[(3) - (4)].ival) < 0)
		osolerror (NULL, osoption, parserData, "Require nonnegative number of directories to move");
	osoption->job->inputDirectoriesToMove->numberOfPathPairs = (yyvsp[(3) - (4)].ival);
	osoption->job->inputDirectoriesToMove->pathPair = new PathPair*[(yyvsp[(3) - (4)].ival)];
	for (int i = 0; i < (yyvsp[(3) - (4)].ival); i++)
		osoption->job->inputDirectoriesToMove->pathPair[i] = new PathPair();
;}
    break;

  case 291:

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

  case 292:

    {	if (parserData->numberOfInputDirectoriesToMove >= osoption->job->inputDirectoriesToMove->numberOfPathPairs)
	{	osolerror (NULL, osoption, parserData, "too many path pairs in <inputDirectoriesToMove> element");
	};
;}
    break;

  case 298:

    {	if (parserData->pathPairFromPresent)
	{	osolerror( NULL, osoption, parserData, "only one \"from\" attribute allowed");
	}
	else
	{	parserData->pathPairFromPresent = true;
		osoption->job->inputDirectoriesToMove->pathPair[parserData->numberOfInputDirectoriesToMove]->from = (yyvsp[(2) - (2)].sval);
	}
;}
    break;

  case 300:

    {	if (parserData->pathPairToPresent)
	{	osolerror( NULL, osoption, parserData, "only one \"to\" attribute allowed");
	}
	else
	{	parserData->pathPairToPresent = true;
		osoption->job->inputDirectoriesToMove->pathPair[parserData->numberOfInputDirectoriesToMove]->to = (yyvsp[(2) - (2)].sval);
	}
;}
    break;

  case 302:

    {	if (parserData->pathPairMakeCopyPresent)
	{	osolerror( NULL, osoption, parserData, "only one \"makeCopy\" attribute allowed");
	}
	else
	{	parserData->pathPairMakeCopyPresent = true;
		if (strcmp((yyvsp[(2) - (2)].sval),"true") == 0)
			osoption->job->inputDirectoriesToMove->pathPair[parserData->numberOfInputDirectoriesToMove]->makeCopy = true;
	}
;}
    break;

  case 307:

    {	if (parserData->inputFilesToMovePresent)
	{	osolerror( NULL, osoption, parserData, "only one <inputFilesToMove> element allowed");
	}
	else
	{	parserData->inputFilesToMovePresent = true;
		osoption->job->inputFilesToMove = new PathPairs();
	}
;}
    break;

  case 308:

    {	if ((yyvsp[(3) - (4)].ival) < 0)
		osolerror (NULL, osoption, parserData, "Require nonnegative number of files to move");
	osoption->job->inputFilesToMove->numberOfPathPairs = (yyvsp[(3) - (4)].ival);
	osoption->job->inputFilesToMove->pathPair = new PathPair*[(yyvsp[(3) - (4)].ival)];
	for (int i = 0; i < (yyvsp[(3) - (4)].ival); i++) osoption->job->inputFilesToMove->pathPair[i] = new PathPair();
;}
    break;

  case 311:

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

  case 312:

    {	if (parserData->numberOfInputFilesToMove >= osoption->job->inputFilesToMove->numberOfPathPairs)
	{	osolerror (NULL, osoption, parserData, "too many path pairs in <inputFilesToMove> element");
	};
;}
    break;

  case 318:

    {	if (parserData->pathPairFromPresent)
	{	osolerror( NULL, osoption, parserData, "only one \"from\" attribute allowed");
	}
	else
	{	parserData->pathPairFromPresent = true;
		osoption->job->inputFilesToMove->pathPair[parserData->numberOfInputFilesToMove]->from = (yyvsp[(2) - (2)].sval);
	}
;}
    break;

  case 320:

    {	if (parserData->pathPairToPresent)
	{	osolerror( NULL, osoption, parserData, "only one \"to\" attribute allowed");
	}
	else
	{	parserData->pathPairToPresent = true;
		osoption->job->inputFilesToMove->pathPair[parserData->numberOfInputFilesToMove]->to = (yyvsp[(2) - (2)].sval);
	}
;}
    break;

  case 322:

    {	if (parserData->pathPairMakeCopyPresent)
	{	osolerror( NULL, osoption, parserData, "only one \"makeCopy\" attribute allowed");
	}
	else
	{	parserData->pathPairMakeCopyPresent = true;
		if (strcmp((yyvsp[(2) - (2)].sval),"true") == 0)
			osoption->job->inputFilesToMove->pathPair[parserData->numberOfInputFilesToMove]->makeCopy = true;
	}
;}
    break;

  case 327:

    {	if (parserData->outputDirectoriesToMovePresent)
	{	osolerror( NULL, osoption, parserData, "only one <outputDirectoriesToMove> element allowed");
	}
	else
	{	parserData->outputDirectoriesToMovePresent = true;
		osoption->job->outputDirectoriesToMove = new PathPairs();
	}
;}
    break;

  case 328:

    {	if ((yyvsp[(3) - (4)].ival) < 0)
		osolerror (NULL, osoption, parserData, "Require nonnegative number of directories to move");
	osoption->job->outputDirectoriesToMove->numberOfPathPairs = (yyvsp[(3) - (4)].ival);
	osoption->job->outputDirectoriesToMove->pathPair = new PathPair*[(yyvsp[(3) - (4)].ival)];
	for (int i = 0; i < (yyvsp[(3) - (4)].ival); i++)
		osoption->job->outputDirectoriesToMove->pathPair[i] = new PathPair();
;}
    break;

  case 331:

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

  case 332:

    {	if (parserData->numberOfOutputDirectoriesToMove >= osoption->job->outputDirectoriesToMove->numberOfPathPairs)
	{	osolerror (NULL, osoption, parserData, "too many path pairs in <outputDirectoriesToMove> element");
	};
;}
    break;

  case 338:

    {	if (parserData->pathPairFromPresent)
	{	osolerror( NULL, osoption, parserData, "only one \"from\" attribute allowed");
	}
	else
	{	parserData->pathPairFromPresent = true;
		osoption->job->outputDirectoriesToMove->pathPair[parserData->numberOfOutputDirectoriesToMove]->from = (yyvsp[(2) - (2)].sval);
	}
;}
    break;

  case 340:

    {	if (parserData->pathPairToPresent)
	{	osolerror( NULL, osoption, parserData, "only one \"to\" attribute allowed");
	}
	else
	{	parserData->pathPairToPresent = true;
		osoption->job->outputDirectoriesToMove->pathPair[parserData->numberOfOutputDirectoriesToMove]->to = (yyvsp[(2) - (2)].sval);
	}
;}
    break;

  case 342:

    {	if (parserData->pathPairMakeCopyPresent)
	{	osolerror( NULL, osoption, parserData, "only one \"makeCopy\" attribute allowed");
	}
	else
	{	parserData->pathPairMakeCopyPresent = true;
		if (strcmp((yyvsp[(2) - (2)].sval),"true") == 0)
			osoption->job->outputDirectoriesToMove->pathPair[parserData->numberOfOutputDirectoriesToMove]->makeCopy = true;
	}
;}
    break;

  case 347:

    {	if (parserData->outputFilesToMovePresent)
	{	osolerror( NULL, osoption, parserData, "only one <outputFilesToMove> element allowed");
	}
	else
	{	parserData->outputFilesToMovePresent = true;
		osoption->job->outputFilesToMove = new PathPairs();
	}
;}
    break;

  case 348:

    {	if ((yyvsp[(3) - (4)].ival) < 0)
		osolerror (NULL, osoption, parserData, "Require nonnegative number of files to move");
	osoption->job->outputFilesToMove->numberOfPathPairs = (yyvsp[(3) - (4)].ival);
	osoption->job->outputFilesToMove->pathPair = new PathPair*[(yyvsp[(3) - (4)].ival)];
	for (int i = 0; i < (yyvsp[(3) - (4)].ival); i++)
		osoption->job->outputFilesToMove->pathPair[i] = new PathPair();;}
    break;

  case 351:

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

  case 352:

    {	if (parserData->numberOfOutputFilesToMove >= osoption->job->outputFilesToMove->numberOfPathPairs)
	{	osolerror (NULL, osoption, parserData, "too many path pairs in <outputFilesToMove> element");
	};
;}
    break;

  case 358:

    {	if (parserData->pathPairFromPresent)
	{	osolerror( NULL, osoption, parserData, "only one \"from\" attribute allowed");
	}
	else
	{	parserData->pathPairFromPresent = true;
		osoption->job->outputFilesToMove->pathPair[parserData->numberOfOutputFilesToMove]->from = (yyvsp[(2) - (2)].sval);
	}
;}
    break;

  case 360:

    {	if (parserData->pathPairToPresent)
	{	osolerror( NULL, osoption, parserData, "only one \"to\" attribute allowed");
	}
	else
	{	parserData->pathPairToPresent = true;
		osoption->job->outputFilesToMove->pathPair[parserData->numberOfOutputFilesToMove]->to = (yyvsp[(2) - (2)].sval);
	}
;}
    break;

  case 362:

    {	if (parserData->pathPairMakeCopyPresent)
	{	osolerror( NULL, osoption, parserData, "only one \"makeCopy\" attribute allowed");
	}
	else
	{	parserData->pathPairMakeCopyPresent = true;
		if (strcmp((yyvsp[(2) - (2)].sval),"true") == 0)
			osoption->job->outputFilesToMove->pathPair[parserData->numberOfOutputFilesToMove]->makeCopy = true;
	}
;}
    break;

  case 367:

    {	if (parserData->filesToDeletePresent)
	{	osolerror( NULL, osoption, parserData, "only one <filesToDelete> element allowed");
	}
	else
	{	parserData->filesToDeletePresent = true;
		osoption->job->filesToDelete = new DirectoriesAndFiles();
	}
;}
    break;

  case 368:

    {	if ((yyvsp[(3) - (4)].ival) < 1)
		osolerror( NULL, osoption, parserData, "Number of paths must be at least 1");
	osoption->job->filesToDelete->numberOfPaths = (yyvsp[(3) - (4)].ival);
	osoption->job->filesToDelete->path = new std::string[(yyvsp[(3) - (4)].ival)];
;}
    break;

  case 371:

    {	if (parserData->numberOfFilesToDelete >= osoption->job->filesToDelete->numberOfPaths)
	{	osolerror (NULL, osoption, parserData, "too many job IDs in <filesToDelete> element");
	}
	else
	{	osoption->job->filesToDelete->path[parserData->numberOfFilesToDelete] = (yyvsp[(3) - (3)].sval);
		parserData->numberOfFilesToDelete++;
	};
;}
    break;

  case 374:

    {	if (parserData->directoriesToDeletePresent)
	{	osolerror( NULL, osoption, parserData, "only one <directoriesToDelete> element allowed");
	}
	else
	{	parserData->directoriesToDeletePresent = true;
		osoption->job->directoriesToDelete = new DirectoriesAndFiles();
	}
;}
    break;

  case 375:

    {	if ((yyvsp[(3) - (4)].ival) < 1)
		osolerror( NULL, osoption, parserData, "Number of paths must be at least 1");
	osoption->job->directoriesToDelete->numberOfPaths = (yyvsp[(3) - (4)].ival);
	osoption->job->directoriesToDelete->path = new std::string[(yyvsp[(3) - (4)].ival)];
;}
    break;

  case 378:

    {	if (parserData->numberOfDirectoriesToDelete >= osoption->job->directoriesToDelete->numberOfPaths)
	{	osolerror (NULL, osoption, parserData, "too many job IDs in <directoriesToDelete> element");
	}
	else
	{	osoption->job->directoriesToDelete->path[parserData->numberOfDirectoriesToDelete] = (yyvsp[(3) - (3)].sval);
		parserData->numberOfDirectoriesToDelete++;
	};
;}
    break;

  case 381:

    {	if (parserData->processesToKillPresent)
	{	osolerror( NULL, osoption, parserData, "only one <processesToKill> element allowed");
	}
	else
	{	parserData->processesToKillPresent = true;
		osoption->job->processesToKill = new Processes();
	}
;}
    break;

  case 382:

    {	if ((yyvsp[(3) - (4)].ival) < 1)
		osolerror( NULL, osoption, parserData, "Number of job IDs must be at least 1");
	osoption->job->processesToKill->numberOfProcesses = (yyvsp[(3) - (4)].ival);
	osoption->job->processesToKill->process = new std::string[(yyvsp[(3) - (4)].ival)];
;}
    break;

  case 385:

    {	if (parserData->numberOfProcessesToKill >= osoption->job->processesToKill->numberOfProcesses)
	{	osolerror (NULL, osoption, parserData, "too many job IDs in <processesToKill> element");
	}
	else
	{	osoption->job->processesToKill->process[parserData->numberOfProcessesToKill] = (yyvsp[(3) - (3)].sval);
		parserData->numberOfProcessesToKill++;
	};
;}
    break;

  case 388:

    {	if (parserData->otherJobOptionsPresent)
	{	osolerror( NULL, osoption, parserData, "only one <otherOptions> element allowed");
	}
	else
	{	parserData->otherJobOptionsPresent = true;
		osoption->job->otherOptions = new OtherOptions();
	}
;}
    break;

  case 389:

    {	if ((yyvsp[(3) - (4)].ival) < 0)
		osolerror( NULL, osoption, parserData, "Number of <other> elements cannot be negative");
	osoption->job->otherOptions->numberOfOtherOptions = (yyvsp[(3) - (4)].ival);
	osoption->job->otherOptions->other = new OtherOption*[(yyvsp[(3) - (4)].ival)];
	for (int i=0; i < (yyvsp[(3) - (4)].ival); i++) osoption->job->otherOptions->other[i] = new OtherOption();
;}
    break;

  case 390:

    {	if (parserData->numberOfOtherJobOptions != osoption->job->otherOptions->numberOfOtherOptions)
		osolerror (NULL, osoption, parserData, "wrong number of other options in <job> element");
;}
    break;

  case 393:

    {	if (parserData->numberOfOtherJobOptions >= osoption->job->otherOptions->numberOfOtherOptions)
		{	osolerror (NULL, osoption, parserData, "too many other options in <job> element");
		};
	;}
    break;

  case 394:

    {	if (!parserData->otherOptionNamePresent)
		osolerror (NULL, osoption, parserData, "name attribute must be present");
	/* reset defaults for the next option */
	parserData->otherOptionNamePresent = false;
	parserData->otherOptionValuePresent = false;
	parserData->otherOptionDescriptionPresent = false;
	parserData->numberOfOtherJobOptions++;
;}
    break;

  case 400:

    {	if (parserData->otherOptionNamePresent)
	{	osolerror( NULL, osoption, parserData, "only one name attribute allowed");
	}
	else
	{	parserData->otherOptionNamePresent = true;
		osoption->job->otherOptions->other[parserData->numberOfOtherJobOptions]->name = (yyvsp[(2) - (2)].sval);
	}
;}
    break;

  case 402:

    {	if (parserData->otherOptionValuePresent)
	{	osolerror( NULL, osoption, parserData, "only one value attribute allowed");
	}
	else
	{	parserData->otherOptionValuePresent = true;
		osoption->job->otherOptions->other[parserData->numberOfOtherJobOptions]->value = (yyvsp[(2) - (2)].sval);
	}
;}
    break;

  case 404:

    {	if (parserData->otherOptionDescriptionPresent)
	{	osolerror( NULL, osoption, parserData, "only one description attribute allowed");
	}
	else
	{	parserData->otherOptionDescriptionPresent = true;
		osoption->job->otherOptions->other[parserData->numberOfOtherJobOptions]->description = (yyvsp[(2) - (2)].sval);
	}
;}
    break;

  case 410:

    {	if (parserData->osoloptimizationPresent)
	{	osolerror( NULL, osoption, parserData, "only one <optimization> element allowed");
	}
	else
	{	parserData->osoloptimizationPresent = true;
		osoption->optimization = new OptimizationOption();
	}
;}
    break;

  case 416:

    {	if ((yyvsp[(3) - (4)].ival) < 0)
		osolerror( NULL, osoption, parserData, "Number of variables cannot be negative");
	osoption->optimization->numberOfVariables = (yyvsp[(3) - (4)].ival);
;}
    break;

  case 417:

    {	if ((yyvsp[(3) - (4)].ival) < 0)
		osolerror( NULL, osoption, parserData, "Number of constraints cannot be negative");
	osoption->optimization->numberOfConstraints = (yyvsp[(3) - (4)].ival);
;}
    break;

  case 418:

    {	if ((yyvsp[(3) - (4)].ival) < 0)
		osolerror( NULL, osoption, parserData, "Number of objectives cannot be negative");
	osoption->optimization->numberOfObjectives = (yyvsp[(3) - (4)].ival);
;}
    break;

  case 424:

    {	osoption->optimization->variables = new VariableOption();
;}
    break;

  case 426:

    {	if ((yyvsp[(3) - (4)].ival) < 0)
		osolerror (NULL, osoption, parserData, "number of <other> variable options cannot be negative");
	osoption->optimization->variables->numberOfOtherVariableOptions = (yyvsp[(3) - (4)].ival);
	osoption->optimization->variables->other = new OtherVariableOption*[(yyvsp[(3) - (4)].ival)];
	for (int i= 0; i < (yyvsp[(3) - (4)].ival); i++)
		osoption->optimization->variables->other[i] = new OtherVariableOption();
;}
    break;

  case 431:

    {	if ((yyvsp[(3) - (4)].ival) < 0)
		osolerror (NULL, osoption, parserData, "number of <var> elements must be nonnegative");
	osoption->optimization->variables->initialVariableValues = new InitVariableValues();
	osoption->optimization->variables->initialVariableValues->numberOfVar = (yyvsp[(3) - (4)].ival);
	osoption->optimization->variables->initialVariableValues->var = new InitVarValue*[(yyvsp[(3) - (4)].ival)];
	for (int i = 0; i < (yyvsp[(3) - (4)].ival); i++)
		osoption->optimization->variables->initialVariableValues->var[i] = new InitVarValue();
;}
    break;

  case 434:

    {	if (!parserData->idxAttributePresent)
		osolerror (NULL, osoption, parserData, "variable index required");
	parserData->idxAttributePresent = false;
	parserData->valAttributePresent = false;
	parserData->numberOfVar++;
;}
    break;

  case 435:

    {	if (parserData->numberOfVar >= osoption->optimization->variables->initialVariableValues->numberOfVar)
		osolerror(NULL, osoption, parserData, "too many initial variable values");
;}
    break;

  case 440:

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
;}
    break;

  case 441:

    {	if (parserData->valAttributePresent)
		osolerror (NULL, osoption, parserData, "only one variable value allowed");
	parserData->valAttributePresent = true;
	if (strcmp((yyvsp[(2) - (2)].sval),"INF") == 0)
		osoption->optimization->variables->initialVariableValues->var[parserData->numberOfVar]->value = OSDBL_MAX;
	else if (strcmp((yyvsp[(2) - (2)].sval),"-INF") == 0)
		osoption->optimization->variables->initialVariableValues->var[parserData->numberOfVar]->value = -OSDBL_MAX;
	else
		osoption->optimization->variables->initialVariableValues->var[parserData->numberOfVar]->value = os_strtod((yyvsp[(2) - (2)].sval), NULL);
;}
    break;

  case 447:

    {	if ((yyvsp[(3) - (4)].ival) < 0)
		osolerror (NULL, osoption, parserData, "number of <var> elements must be nonnegative");
	osoption->optimization->variables->initialVariableValuesString = new InitVariableValuesString();
	osoption->optimization->variables->initialVariableValuesString->numberOfVar = (yyvsp[(3) - (4)].ival);
	osoption->optimization->variables->initialVariableValuesString->var = new InitVarValueString*[(yyvsp[(3) - (4)].ival)];
	for (int i = 0; i < (yyvsp[(3) - (4)].ival); i++)
		osoption->optimization->variables->initialVariableValuesString->var[i] = new InitVarValueString ();
;}
    break;

  case 450:

    {	if (!parserData->idxAttributePresent)
		osolerror (NULL, osoption, parserData, "variable index required");
	parserData->idxAttributePresent = false;
	parserData->valAttributePresent = false;
	parserData->numberOfVarStr++;
;}
    break;

  case 451:

    {	if (parserData->numberOfVarStr >= osoption->optimization->variables->initialVariableValuesString->numberOfVar)
		osolerror(NULL, osoption, parserData, "too many initial variable strings");
;}
    break;

  case 456:

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
;}
    break;

  case 457:

    {	if (parserData->valAttributePresent)
		osolerror (NULL, osoption, parserData, "only one variable string value allowed");
	parserData->valAttributePresent = true;
	osoption->optimization->variables->initialVariableValuesString->var[parserData->numberOfVarStr]->value = (yyvsp[(2) - (2)].sval);
;}
    break;

  case 463:

    {	if ((yyvsp[(3) - (4)].ival) < 0)
		osolerror (NULL, osoption, parserData, "number of <var> elements must be nonnegative");
	osoption->optimization->variables->initialBasisStatus = new InitialBasisStatus();
	osoption->optimization->variables->initialBasisStatus->numberOfVar = (yyvsp[(3) - (4)].ival);
	osoption->optimization->variables->initialBasisStatus->var = new InitBasStatus*[(yyvsp[(3) - (4)].ival)];
	for (int i = 0; i < (yyvsp[(3) - (4)].ival); i++)
		osoption->optimization->variables->initialBasisStatus->var[i] = new InitBasStatus();
;}
    break;

  case 466:

    {	if (!parserData->idxAttributePresent)
		osolerror (NULL, osoption, parserData, "variable index required");
	parserData->idxAttributePresent = false;
	parserData->valAttributePresent = false;
	parserData->numberOfBasVar++;
;}
    break;

  case 467:

    {	if (parserData->numberOfBasVar >= osoption->optimization->variables->initialBasisStatus->numberOfVar)
		osolerror(NULL, osoption, parserData, "too many initial basis variables");
;}
    break;

  case 472:

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
;}
    break;

  case 473:

    {	if (parserData->valAttributePresent)
		osolerror (NULL, osoption, parserData, "only one variable value allowed");
	parserData->valAttributePresent = true;
	osoption->optimization->variables->initialBasisStatus->var[parserData->numberOfBasVar]->value = (yyvsp[(2) - (2)].sval);
;}
    break;

  case 479:

    {	if ((yyvsp[(3) - (4)].ival) < 0)
		osolerror (NULL, osoption, parserData, "number of <var> elements must be nonnegative");
	osoption->optimization->variables->integerVariableBranchingWeights = new IntegerVariableBranchingWeights();
	osoption->optimization->variables->integerVariableBranchingWeights->numberOfVar = (yyvsp[(3) - (4)].ival);
	osoption->optimization->variables->integerVariableBranchingWeights->var = new BranchingWeight*[(yyvsp[(3) - (4)].ival)];
	for (int i = 0; i < (yyvsp[(3) - (4)].ival); i++)
		osoption->optimization->variables->integerVariableBranchingWeights->var[i] = new BranchingWeight();
;}
    break;

  case 482:

    {	if (!parserData->idxAttributePresent)
		osolerror (NULL, osoption, parserData, "variable index required");
	parserData->idxAttributePresent = false;
	parserData->valAttributePresent = false;
	parserData->numberOfIntWt++;
;}
    break;

  case 483:

    {	if (parserData->numberOfIntWt >= osoption->optimization->variables->integerVariableBranchingWeights->numberOfVar)
		osolerror(NULL, osoption, parserData, "too many integer branching weights");
;}
    break;

  case 488:

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
;}
    break;

  case 489:

    {	if (parserData->valAttributePresent)
		osolerror (NULL, osoption, parserData, "only one branching weight allowed");
	parserData->valAttributePresent = true;
	if (strcmp((yyvsp[(2) - (2)].sval),"INF") == 0)
		osoption->optimization->variables->integerVariableBranchingWeights->var[parserData->numberOfIntWt]->value = OSDBL_MAX;
	else if (strcmp((yyvsp[(2) - (2)].sval),"-INF") == 0)
		osoption->optimization->variables->integerVariableBranchingWeights->var[parserData->numberOfIntWt]->value = -OSDBL_MAX;
	else
		osoption->optimization->variables->integerVariableBranchingWeights->var[parserData->numberOfIntWt]->value = os_strtod((yyvsp[(2) - (2)].sval), NULL);
;}
    break;

  case 495:

    {	if ((yyvsp[(3) - (4)].ival) < 0)
		osolerror (NULL, osoption, parserData, "number of <sos> elements must be nonnegative");
	osoption->optimization->variables->sosVariableBranchingWeights = new SOSVariableBranchingWeights();
	osoption->optimization->variables->sosVariableBranchingWeights->numberOfSOS = (yyvsp[(3) - (4)].ival);
	osoption->optimization->variables->sosVariableBranchingWeights->sos = new SOSWeights*[(yyvsp[(3) - (4)].ival)];
	for (int i = 0; i < (yyvsp[(3) - (4)].ival); i++)
		osoption->optimization->variables->sosVariableBranchingWeights->sos[i] = new SOSWeights();
;}
    break;

  case 498:

    {	if (!parserData->sosIdxAttributePresent)
		osolerror (NULL, osoption, parserData, "SOS index required");
	if (!parserData->sosIdxAttributePresent)
		osolerror (NULL, osoption, parserData, "numberOfVar required");
	parserData->sosIdxAttributePresent = false;
	parserData->grpWgtAttributePresent = false;
	parserData->nOfVarAttributePresent = false;
	parserData->numberOfSOS++;
;}
    break;

  case 499:

    {	if (parserData->numberOfSOS >= osoption->optimization->variables->sosVariableBranchingWeights->numberOfSOS)
		osolerror(NULL, osoption, parserData, "too many SOS branching weights");
	parserData->numberOfSOSVar = 0;
;}
    break;

  case 505:

    {	if (parserData->sosIdxAttributePresent)
		osolerror (NULL, osoption, parserData, "only one SOS index allowed");
	parserData->sosIdxAttributePresent = true;
	if ((yyvsp[(3) - (4)].ival) < 0)
		osolerror (NULL, osoption, parserData, "SOS index must be nonnegative");
	osoption->optimization->variables->sosVariableBranchingWeights->sos[parserData->numberOfSOS]->sosIdx = (yyvsp[(3) - (4)].ival);
;}
    break;

  case 506:

    {	if (parserData->grpWgtAttributePresent)
		osolerror (NULL, osoption, parserData, "only one group weight allowed");
	parserData->grpWgtAttributePresent = true;
	osoption->optimization->variables->sosVariableBranchingWeights->sos[parserData->numberOfSOS]->groupWeight = (yyvsp[(3) - (4)].dval);
;}
    break;

  case 507:

    {	if (parserData->grpWgtAttributePresent)
		osolerror (NULL, osoption, parserData, "only one group weight allowed");
	parserData->grpWgtAttributePresent = true;
	osoption->optimization->variables->sosVariableBranchingWeights->sos[parserData->numberOfSOS]->groupWeight = (yyvsp[(3) - (4)].ival);
;}
    break;

  case 508:

    {	if ((yyvsp[(3) - (4)].ival) < 0)
		osolerror (NULL, osoption, parserData, "number of <var> elements must be nonnegative");
//	osoption->optimization->variables->sosVariableBranchingWeights->sos[parserData->numberOfSOS] = new SOSWeights();
	osoption->optimization->variables->sosVariableBranchingWeights->sos[parserData->numberOfSOS]->numberOfVar = (yyvsp[(3) - (4)].ival);
	osoption->optimization->variables->sosVariableBranchingWeights->sos[parserData->numberOfSOS]->var = new BranchingWeight*[(yyvsp[(3) - (4)].ival)];
	for (int i = 0; i < (yyvsp[(3) - (4)].ival); i++)
		osoption->optimization->variables->sosVariableBranchingWeights->sos[parserData->numberOfSOS]->var[i] = new BranchingWeight();
;}
    break;

  case 513:

    {	if (!parserData->idxAttributePresent)
		osolerror (NULL, osoption, parserData, "variable index required");
	parserData->idxAttributePresent = false;
	parserData->valAttributePresent = false;
	parserData->numberOfSOSVar++;
;}
    break;

  case 514:

    {	if (parserData->numberOfSOSVar >= osoption->optimization->variables->sosVariableBranchingWeights->sos[parserData->numberOfSOS]->numberOfVar)
		osolerror(NULL, osoption, parserData, "too many variable branching weights");
;}
    break;

  case 519:

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
;}
    break;

  case 520:

    {	if (parserData->valAttributePresent)
		osolerror (NULL, osoption, parserData, "only one variable weight allowed");
	parserData->valAttributePresent = true;
	if (strcmp((yyvsp[(2) - (2)].sval),"INF") == 0)
		osoption->optimization->variables->sosVariableBranchingWeights->sos[parserData->numberOfSOS]->var[parserData->numberOfSOSVar]->value = OSDBL_MAX;
	else if (strcmp((yyvsp[(2) - (2)].sval),"-INF") == 0)
		osoption->optimization->variables->sosVariableBranchingWeights->sos[parserData->numberOfSOS]->var[parserData->numberOfSOSVar]->value = -OSDBL_MAX;
	else
		osoption->optimization->variables->sosVariableBranchingWeights->sos[parserData->numberOfSOS]->var[parserData->numberOfSOSVar]->value = os_strtod((yyvsp[(2) - (2)].sval), NULL);
;}
    break;

  case 527:

    {	if (parserData->numberOfOtherVariableOptions >= osoption->optimization->variables->numberOfOtherVariableOptions)
		osolerror(NULL, osoption, parserData, "too many <other> variable options");
;}
    break;

  case 537:

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
;}
    break;

  case 538:

    {	if (parserData->otherOptionNamePresent)
		osolerror (NULL, osoption, parserData, "only one name attribute allowed");
	parserData->otherOptionNamePresent = true;
	osoption->optimization->variables->other[parserData->numberOfOtherVariableOptions]->name = (yyvsp[(2) - (2)].sval);
;}
    break;

  case 540:

    {	if (parserData->otherOptionValuePresent)
		osolerror (NULL, osoption, parserData, "only one value attribute allowed");
	parserData->otherOptionValuePresent = true;
	osoption->optimization->variables->other[parserData->numberOfOtherVariableOptions]->value = (yyvsp[(2) - (2)].sval);
;}
    break;

  case 542:

    {	if (parserData->otherOptionSolverPresent)
		osolerror (NULL, osoption, parserData, "only one solver attribute allowed");
	parserData->otherOptionSolverPresent = true;
	osoption->optimization->variables->other[parserData->numberOfOtherVariableOptions]->solver = (yyvsp[(2) - (2)].sval);
;}
    break;

  case 544:

    {	if (parserData->otherOptionCategoryPresent)
		osolerror (NULL, osoption, parserData, "only one category attribute allowed");
	parserData->otherOptionCategoryPresent = true;
	osoption->optimization->variables->other[parserData->numberOfOtherVariableOptions]->category = (yyvsp[(2) - (2)].sval);
;}
    break;

  case 546:

    {	if (parserData->otherOptionTypePresent)
		osolerror (NULL, osoption, parserData, "only one type attribute allowed");
	parserData->otherOptionTypePresent = true;
	osoption->optimization->variables->other[parserData->numberOfOtherVariableOptions]->type = (yyvsp[(2) - (2)].sval);
;}
    break;

  case 548:

    {	if (parserData->otherOptionDescriptionPresent)
		osolerror (NULL, osoption, parserData, "only one description attribute allowed");
	parserData->otherOptionDescriptionPresent = true;
	osoption->optimization->variables->other[parserData->numberOfOtherVariableOptions]->description = (yyvsp[(2) - (2)].sval);
;}
    break;

  case 550:

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
;}
    break;

  case 553:

    {	if (!parserData->idxAttributePresent)
		osolerror(NULL, osoption, parserData, "required idx attribute was not found");
	parserData->idxAttributePresent = false;
	parserData->valAttributePresent = false;
	parserData->lbvalAttributePresent = false;
	parserData->ubvalAttributePresent = false;
	parserData->numberOfVar++;
;}
    break;

  case 554:

    {	if (parserData->numberOfVar >= osoption->optimization->variables->other[parserData->numberOfOtherVariableOptions]->numberOfVar)
		osolerror(NULL, osoption, parserData, "too many <var> entries in <other> variable element");
;}
    break;

  case 561:

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
;}
    break;

  case 562:

    {	if (parserData->valAttributePresent)
		osolerror (NULL, osoption, parserData, "only one variable value allowed");
	parserData->valAttributePresent = true;
	osoption->optimization->variables->other[parserData->numberOfOtherVariableOptions]->var[parserData->numberOfVar]->value = (yyvsp[(2) - (2)].sval);
;}
    break;

  case 564:

    {	if (parserData->lbvalAttributePresent)
		osolerror (NULL, osoption, parserData, "only one lower bound value allowed");
	parserData->lbvalAttributePresent = true;
	osoption->optimization->variables->other[parserData->numberOfOtherVariableOptions]->var[parserData->numberOfVar]->lbValue = (yyvsp[(2) - (2)].sval);
;}
    break;

  case 566:

    {	if (parserData->ubvalAttributePresent)
		osolerror (NULL, osoption, parserData, "only one upper bound value allowed");
	parserData->ubvalAttributePresent = true;
	osoption->optimization->variables->other[parserData->numberOfOtherVariableOptions]->var[parserData->numberOfVar]->ubValue = (yyvsp[(2) - (2)].sval);
;}
    break;

  case 572:

    {	osoption->optimization->objectives = new ObjectiveOption();
;}
    break;

  case 574:

    {	if ((yyvsp[(3) - (4)].ival) < 0)
		osolerror (NULL, osoption, parserData, "number of <other> objective options cannot be negative");
	osoption->optimization->objectives->numberOfOtherObjectiveOptions = (yyvsp[(3) - (4)].ival);
	osoption->optimization->objectives->other = new OtherObjectiveOption*[(yyvsp[(3) - (4)].ival)];
	for (int i= 0; i < (yyvsp[(3) - (4)].ival); i++)
		osoption->optimization->objectives->other[i] = new OtherObjectiveOption();
;}
    break;

  case 579:

    {	if ((yyvsp[(3) - (4)].ival) < 0)
		osolerror (NULL, osoption, parserData, "number of <obj> elements must be nonnegative");
	osoption->optimization->objectives->initialObjectiveValues = new InitObjectiveValues();
	osoption->optimization->objectives->initialObjectiveValues->numberOfObj = (yyvsp[(3) - (4)].ival);
	osoption->optimization->objectives->initialObjectiveValues->obj = new InitObjValue*[(yyvsp[(3) - (4)].ival)];
	for (int i = 0; i < (yyvsp[(3) - (4)].ival); i++)
		osoption->optimization->objectives->initialObjectiveValues->obj[i] = new InitObjValue();
;}
    break;

  case 582:

    {	if (!parserData->idxAttributePresent)
		osolerror (NULL, osoption, parserData, "objective index required");
	parserData->idxAttributePresent = false;
	parserData->valAttributePresent = false;
	parserData->numberOfObjValues++;
;}
    break;

  case 583:

    {	if (parserData->numberOfObjValues >= osoption->optimization->objectives->initialObjectiveValues->numberOfObj)
		osolerror(NULL, osoption, parserData, "too many initial objective values");
;}
    break;

  case 588:

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
;}
    break;

  case 589:

    {	if (parserData->valAttributePresent)
		osolerror (NULL, osoption, parserData, "only one objective value allowed");
	parserData->valAttributePresent = true;
	if (strcmp((yyvsp[(2) - (2)].sval),"INF") == 0)
		osoption->optimization->objectives->initialObjectiveValues->obj[parserData->numberOfObjValues]->value = OSDBL_MAX;
	else if (strcmp((yyvsp[(2) - (2)].sval),"-INF") == 0)
		osoption->optimization->objectives->initialObjectiveValues->obj[parserData->numberOfObjValues]->value = -OSDBL_MAX;
	else
		osoption->optimization->objectives->initialObjectiveValues->obj[parserData->numberOfObjValues]->value = os_strtod((yyvsp[(2) - (2)].sval), NULL);
;}
    break;

  case 595:

    {	if ((yyvsp[(3) - (4)].ival) < 0)
		osolerror (NULL, osoption, parserData, "number of <obj> elements must be nonnegative");
	osoption->optimization->objectives->initialObjectiveBounds = new InitObjectiveBounds();
	osoption->optimization->objectives->initialObjectiveBounds->numberOfObj = (yyvsp[(3) - (4)].ival);
	osoption->optimization->objectives->initialObjectiveBounds->obj = new InitObjBound*[(yyvsp[(3) - (4)].ival)];
	for (int i = 0; i < (yyvsp[(3) - (4)].ival); i++)
		osoption->optimization->objectives->initialObjectiveBounds->obj[i] = new InitObjBound ();
;}
    break;

  case 598:

    {	if (!parserData->idxAttributePresent)
		osolerror (NULL, osoption, parserData, "objective index required");
	parserData->idxAttributePresent = false;
	parserData->lbvalAttributePresent = false;
	parserData->ubvalAttributePresent = false;
	parserData->numberOfObjBounds++;
;}
    break;

  case 599:

    {	if (parserData->numberOfObjBounds >= osoption->optimization->objectives->initialObjectiveBounds->numberOfObj)
		osolerror(NULL, osoption, parserData, "too many initial objective bounds");
;}
    break;

  case 605:

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
;}
    break;

  case 606:

    {	if (parserData->lbvalAttributePresent)
		osolerror (NULL, osoption, parserData, "only one objective lower bound allowed");
	parserData->lbvalAttributePresent = true;
	if (strcmp((yyvsp[(2) - (2)].sval),"INF") == 0)
		osoption->optimization->objectives->initialObjectiveBounds->obj[parserData->numberOfObjBounds]->lbValue = OSDBL_MAX;
	else if (strcmp((yyvsp[(2) - (2)].sval),"-INF") == 0)
		osoption->optimization->objectives->initialObjectiveBounds->obj[parserData->numberOfObjBounds]->lbValue = -OSDBL_MAX;
	else
		osoption->optimization->objectives->initialObjectiveBounds->obj[parserData->numberOfObjBounds]->lbValue = os_strtod((yyvsp[(2) - (2)].sval), NULL);
;}
    break;

  case 608:

    {	if (parserData->ubvalAttributePresent)
		osolerror (NULL, osoption, parserData, "only one objective upper bound allowed");
	parserData->ubvalAttributePresent = true;
	if (strcmp((yyvsp[(2) - (2)].sval),"INF") == 0)
		osoption->optimization->objectives->initialObjectiveBounds->obj[parserData->numberOfObjBounds]->ubValue = OSDBL_MAX;
	else if (strcmp((yyvsp[(2) - (2)].sval),"-INF") == 0)
		osoption->optimization->objectives->initialObjectiveBounds->obj[parserData->numberOfObjBounds]->ubValue = -OSDBL_MAX;
	else
		osoption->optimization->objectives->initialObjectiveBounds->obj[parserData->numberOfObjBounds]->ubValue = os_strtod((yyvsp[(2) - (2)].sval), NULL);
;}
    break;

  case 615:

    {	if (parserData->numberOfOtherObjectiveOptions >= osoption->optimization->objectives->numberOfOtherObjectiveOptions)
		osolerror(NULL, osoption, parserData, "too many <other> objective options");
;}
    break;

  case 625:

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
;}
    break;

  case 626:

    {	if (parserData->otherOptionNamePresent)
		osolerror (NULL, osoption, parserData, "only one name attribute allowed");
	parserData->otherOptionNamePresent = true;
	osoption->optimization->objectives->other[parserData->numberOfOtherObjectiveOptions]->name = (yyvsp[(2) - (2)].sval);
;}
    break;

  case 628:

    {	if (parserData->otherOptionValuePresent)
		osolerror (NULL, osoption, parserData, "only one value attribute allowed");
	parserData->otherOptionValuePresent = true;
	osoption->optimization->objectives->other[parserData->numberOfOtherObjectiveOptions]->value = (yyvsp[(2) - (2)].sval);
;}
    break;

  case 630:

    {	if (parserData->otherOptionSolverPresent)
		osolerror (NULL, osoption, parserData, "only one solver attribute allowed");
	parserData->otherOptionSolverPresent = true;
	osoption->optimization->objectives->other[parserData->numberOfOtherObjectiveOptions]->solver = (yyvsp[(2) - (2)].sval);
;}
    break;

  case 632:

    {	if (parserData->otherOptionCategoryPresent)
		osolerror (NULL, osoption, parserData, "only one category attribute allowed");
	parserData->otherOptionCategoryPresent = true;
	osoption->optimization->objectives->other[parserData->numberOfOtherObjectiveOptions]->category = (yyvsp[(2) - (2)].sval);
;}
    break;

  case 634:

    {	if (parserData->otherOptionTypePresent)
		osolerror (NULL, osoption, parserData, "only one type attribute allowed");
	parserData->otherOptionTypePresent = true;
	osoption->optimization->objectives->other[parserData->numberOfOtherObjectiveOptions]->type = (yyvsp[(2) - (2)].sval);
;}
    break;

  case 636:

    {	if (parserData->otherOptionDescriptionPresent)
		osolerror (NULL, osoption, parserData, "only one description attribute allowed");
	parserData->otherOptionDescriptionPresent = true;
	osoption->optimization->objectives->other[parserData->numberOfOtherObjectiveOptions]->description = (yyvsp[(2) - (2)].sval);
;}
    break;

  case 638:

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
;}
    break;

  case 641:

    {	if (!parserData->idxAttributePresent)
		osolerror(NULL, osoption, parserData, "required idx attribute was not found");
	parserData->idxAttributePresent = false;
	parserData->valAttributePresent = false;
	parserData->lbvalAttributePresent = false;
	parserData->ubvalAttributePresent = false;
	parserData->numberOfObj++;
;}
    break;

  case 642:

    {	if (parserData->numberOfObj >= osoption->optimization->objectives->other[parserData->numberOfOtherObjectiveOptions]->numberOfObj)
		osolerror(NULL, osoption, parserData, "too many <obj> entries in <other> objective element");
;}
    break;

  case 649:

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
;}
    break;

  case 650:

    {	if (parserData->valAttributePresent)
		osolerror (NULL, osoption, parserData, "only one variable value allowed");
	parserData->valAttributePresent = true;
	osoption->optimization->objectives->other[parserData->numberOfOtherObjectiveOptions]->obj[parserData->numberOfObj]->value = (yyvsp[(2) - (2)].sval);
;}
    break;

  case 652:

    {	if (parserData->lbvalAttributePresent)
		osolerror (NULL, osoption, parserData, "only one lower bound value allowed");
	parserData->lbvalAttributePresent = true;
	osoption->optimization->objectives->other[parserData->numberOfOtherObjectiveOptions]->obj[parserData->numberOfObj]->lbValue = (yyvsp[(2) - (2)].sval);
;}
    break;

  case 654:

    {	if (parserData->ubvalAttributePresent)
		osolerror (NULL, osoption, parserData, "only one upper bound value allowed");
	parserData->ubvalAttributePresent = true;
	osoption->optimization->objectives->other[parserData->numberOfOtherObjectiveOptions]->obj[parserData->numberOfObj]->ubValue = (yyvsp[(2) - (2)].sval);
;}
    break;

  case 660:

    {	osoption->optimization->constraints = new ConstraintOption();
;}
    break;

  case 662:

    {	if ((yyvsp[(3) - (4)].ival) < 0)
		osolerror (NULL, osoption, parserData, "number of <other> constraint options cannot be negative");
        osoption->optimization->constraints->numberOfOtherConstraintOptions = (yyvsp[(3) - (4)].ival);
	osoption->optimization->constraints->other = new OtherConstraintOption*[(yyvsp[(3) - (4)].ival)];
	for (int i= 0; i < (yyvsp[(3) - (4)].ival); i++)
		osoption->optimization->constraints->other[i] = new OtherConstraintOption();
;}
    break;

  case 667:

    {	if ((yyvsp[(3) - (4)].ival) < 0)
		osolerror (NULL, osoption, parserData, "number of <con> elements must be nonnegative");
	osoption->optimization->constraints->initialConstraintValues = new InitConstraintValues();
	osoption->optimization->constraints->initialConstraintValues->numberOfCon = (yyvsp[(3) - (4)].ival);
	osoption->optimization->constraints->initialConstraintValues->con = new InitConValue*[(yyvsp[(3) - (4)].ival)];
	for (int i = 0; i < (yyvsp[(3) - (4)].ival); i++)
		osoption->optimization->constraints->initialConstraintValues->con[i] = new InitConValue();
;}
    break;

  case 670:

    {	if (!parserData->idxAttributePresent)
		osolerror (NULL, osoption, parserData, "variable index required");
	parserData->idxAttributePresent = false;
	parserData->valAttributePresent = false;
	parserData->numberOfCon++;
;}
    break;

  case 671:

    {	if (parserData->numberOfCon >= osoption->optimization->constraints->initialConstraintValues->numberOfCon)
		osolerror(NULL, osoption, parserData, "too many initial constraint values");
;}
    break;

  case 676:

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
;}
    break;

  case 677:

    {	if (parserData->valAttributePresent)
		osolerror (NULL, osoption, parserData, "only one constraint value allowed");
	parserData->valAttributePresent = true;
	if (strcmp((yyvsp[(2) - (2)].sval),"INF") == 0)
		osoption->optimization->constraints->initialConstraintValues->con[parserData->numberOfCon]->value = OSDBL_MAX;
	else if (strcmp((yyvsp[(2) - (2)].sval),"-INF") == 0)
		osoption->optimization->constraints->initialConstraintValues->con[parserData->numberOfCon]->value = -OSDBL_MAX;
	else
		osoption->optimization->constraints->initialConstraintValues->con[parserData->numberOfCon]->value = os_strtod((yyvsp[(2) - (2)].sval), NULL);
;}
    break;

  case 683:

    {	if ((yyvsp[(3) - (4)].ival) < 0)
		osolerror (NULL, osoption, parserData, "number of <con> elements must be nonnegative");
	osoption->optimization->constraints->initialDualValues = new InitDualVariableValues();
	osoption->optimization->constraints->initialDualValues->numberOfCon = (yyvsp[(3) - (4)].ival);
	osoption->optimization->constraints->initialDualValues->con = new InitDualVarValue*[(yyvsp[(3) - (4)].ival)];
	for (int i = 0; i < (yyvsp[(3) - (4)].ival); i++)
		osoption->optimization->constraints->initialDualValues->con[i] = new InitDualVarValue ();
;}
    break;

  case 686:

    {	if (!parserData->idxAttributePresent)
		osolerror (NULL, osoption, parserData, "constraint index required");
	parserData->idxAttributePresent = false;
	parserData->lbvalAttributePresent = false;
	parserData->ubvalAttributePresent = false;
	parserData->numberOfDuals++;
;}
    break;

  case 687:

    {	if (parserData->numberOfDuals >= osoption->optimization->constraints->initialDualValues->numberOfCon)
		osolerror(NULL, osoption, parserData, "too many initial dual variable bounds");
;}
    break;

  case 693:

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
;}
    break;

  case 694:

    {	if (parserData->lbvalAttributePresent)
		osolerror (NULL, osoption, parserData, "only one dual variable lower bound allowed");
	parserData->lbvalAttributePresent = true;
	if (strcmp((yyvsp[(2) - (2)].sval),"INF") == 0)
		osoption->optimization->constraints->initialDualValues->con[parserData->numberOfDuals]->lbDualValue = OSDBL_MAX;
	else if (strcmp((yyvsp[(2) - (2)].sval),"-INF") == 0)
		osoption->optimization->constraints->initialDualValues->con[parserData->numberOfDuals]->lbDualValue = -OSDBL_MAX;
	else
		osoption->optimization->constraints->initialDualValues->con[parserData->numberOfDuals]->lbDualValue = os_strtod((yyvsp[(2) - (2)].sval), NULL);
;}
    break;

  case 696:

    {	if (parserData->ubvalAttributePresent)
		osolerror (NULL, osoption, parserData, "only one dual variable upper bound allowed");
	parserData->ubvalAttributePresent = true;
	if (strcmp((yyvsp[(2) - (2)].sval),"INF") == 0)
		osoption->optimization->constraints->initialDualValues->con[parserData->numberOfDuals]->ubDualValue = OSDBL_MAX;
	else if (strcmp((yyvsp[(2) - (2)].sval),"-INF") == 0)
		osoption->optimization->constraints->initialDualValues->con[parserData->numberOfDuals]->ubDualValue = -OSDBL_MAX;
	else
		osoption->optimization->constraints->initialDualValues->con[parserData->numberOfDuals]->ubDualValue = os_strtod((yyvsp[(2) - (2)].sval), NULL);
;}
    break;

  case 703:

    {	if (parserData->numberOfOtherConstraintOptions >= osoption->optimization->constraints->numberOfOtherConstraintOptions)
		osolerror(NULL, osoption, parserData, "too many <other> constraint options");
;}
    break;

  case 713:

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
;}
    break;

  case 714:

    {	if (parserData->otherOptionNamePresent)
		osolerror (NULL, osoption, parserData, "only one name attribute allowed");
	parserData->otherOptionNamePresent = true;
	osoption->optimization->constraints->other[parserData->numberOfOtherConstraintOptions]->name = (yyvsp[(2) - (2)].sval);
;}
    break;

  case 716:

    {	if (parserData->otherOptionValuePresent)
		osolerror (NULL, osoption, parserData, "only one value attribute allowed");
	parserData->otherOptionValuePresent = true;
	osoption->optimization->constraints->other[parserData->numberOfOtherConstraintOptions]->value = (yyvsp[(2) - (2)].sval);
;}
    break;

  case 718:

    {	if (parserData->otherOptionSolverPresent)
		osolerror (NULL, osoption, parserData, "only one solver attribute allowed");
	parserData->otherOptionSolverPresent = true;
	osoption->optimization->constraints->other[parserData->numberOfOtherConstraintOptions]->solver = (yyvsp[(2) - (2)].sval);
;}
    break;

  case 720:

    {	if (parserData->otherOptionCategoryPresent)
		osolerror (NULL, osoption, parserData, "only one category attribute allowed");
	parserData->otherOptionCategoryPresent = true;
	osoption->optimization->constraints->other[parserData->numberOfOtherConstraintOptions]->category = (yyvsp[(2) - (2)].sval);
;}
    break;

  case 722:

    {	if (parserData->otherOptionTypePresent)
		osolerror (NULL, osoption, parserData, "only one type attribute allowed");
	parserData->otherOptionTypePresent = true;
	osoption->optimization->constraints->other[parserData->numberOfOtherConstraintOptions]->type = (yyvsp[(2) - (2)].sval);
;}
    break;

  case 724:

    {	if (parserData->otherOptionDescriptionPresent)
		osolerror (NULL, osoption, parserData, "only one description attribute allowed");
	parserData->otherOptionDescriptionPresent = true;
	osoption->optimization->constraints->other[parserData->numberOfOtherConstraintOptions]->description = (yyvsp[(2) - (2)].sval);
;}
    break;

  case 726:

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
;}
    break;

  case 729:

    {	if (!parserData->idxAttributePresent)
		osolerror(NULL, osoption, parserData, "required idx attribute was not found");
	parserData->idxAttributePresent = false;
	parserData->valAttributePresent = false;
	parserData->lbvalAttributePresent = false;
	parserData->ubvalAttributePresent = false;
	parserData->numberOfCon++;
;}
    break;

  case 730:

    {	if (parserData->numberOfCon >= osoption->optimization->constraints->other[parserData->numberOfOtherConstraintOptions]->numberOfCon)
		osolerror(NULL, osoption, parserData, "too many <con> entries in <other> constraint element");
;}
    break;

  case 737:

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
;}
    break;

  case 738:

    {	if (parserData->valAttributePresent)
		osolerror (NULL, osoption, parserData, "only one constraint value allowed");
	parserData->valAttributePresent = true;
	osoption->optimization->constraints->other[parserData->numberOfOtherConstraintOptions]->con[parserData->numberOfCon]->value = (yyvsp[(2) - (2)].sval);
;}
    break;

  case 740:

    {	if (parserData->lbvalAttributePresent)
		osolerror (NULL, osoption, parserData, "only one lower bound value allowed");
	parserData->lbvalAttributePresent = true;
	osoption->optimization->constraints->other[parserData->numberOfOtherConstraintOptions]->con[parserData->numberOfCon]->lbValue = (yyvsp[(2) - (2)].sval);
;}
    break;

  case 742:

    {	if (parserData->ubvalAttributePresent)
		osolerror (NULL, osoption, parserData, "only one upper bound value allowed");
	parserData->ubvalAttributePresent = true;
	osoption->optimization->constraints->other[parserData->numberOfOtherConstraintOptions]->con[parserData->numberOfCon]->ubValue = (yyvsp[(2) - (2)].sval);
;}
    break;

  case 747:

    {	if (parserData->numberOfSolverOptions != osoption->optimization->solverOptions->numberOfSolverOptions)
		osolerror (NULL, osoption, parserData, "wrong number of solver options in <optimization> element");
;}
    break;

  case 748:

    {	if (parserData->solverOptionsPresent)
	{	osolerror( NULL, osoption, parserData, "only one <solverOptions> element allowed");
	}
	else
	{	parserData->solverOptionsPresent = true;
		osoption->optimization->solverOptions = new SolverOptions();
	}
;}
    break;

  case 749:

    {	if ((yyvsp[(3) - (4)].ival) < 0)
		osolerror (NULL, osoption, parserData, "number of solver options cannot be negative");
	osoption->optimization->solverOptions->numberOfSolverOptions = (yyvsp[(3) - (4)].ival);
	osoption->optimization->solverOptions->solverOption = new SolverOption*[(yyvsp[(3) - (4)].ival)];
	for (int i=0; i < (yyvsp[(3) - (4)].ival); i++) osoption->optimization->solverOptions->solverOption[i] = new SolverOption();
;}
    break;

  case 752:

    {	if (parserData->numberOfSolverOptions >= osoption->optimization->solverOptions->numberOfSolverOptions)
	{	osolerror (NULL, osoption, parserData, "too many solver options in <optimization> element");
	};
;}
    break;

  case 753:

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
;}
    break;

  case 762:

    {	if (parserData->solverOptionNamePresent)
	{	osolerror( NULL, osoption, parserData, "only one name attribute allowed");
	}
	else
	{	parserData->solverOptionNamePresent = true;
		osoption->optimization->solverOptions->solverOption[parserData->numberOfSolverOptions]->name = (yyvsp[(2) - (2)].sval);
	}
;}
    break;

  case 764:

    {	if (parserData->solverOptionValuePresent)
	{	osolerror( NULL, osoption, parserData, "only one value attribute allowed");
	}
	else
	{	parserData->solverOptionValuePresent = true;
		osoption->optimization->solverOptions->solverOption[parserData->numberOfSolverOptions]->value = (yyvsp[(2) - (2)].sval);
	}
;}
    break;

  case 766:

    {	if (parserData->solverOptionSolverPresent)
	{	osolerror( NULL, osoption, parserData, "only one solver attribute allowed");
	}
	else
	{	parserData->solverOptionSolverPresent = true;
		osoption->optimization->solverOptions->solverOption[parserData->numberOfSolverOptions]->solver = (yyvsp[(2) - (2)].sval);
	}
;}
    break;

  case 768:

    {	if (parserData->solverOptionCategoryPresent)
	{	osolerror( NULL, osoption, parserData, "only one category attribute allowed");
	}
	else
	{	parserData->solverOptionCategoryPresent = true;
		osoption->optimization->solverOptions->solverOption[parserData->numberOfSolverOptions]->category = (yyvsp[(2) - (2)].sval);
	}
;}
    break;

  case 770:

    {	if (parserData->solverOptionTypePresent)
	{	osolerror( NULL, osoption, parserData, "only one type attribute allowed");
	}
	else
	{	parserData->solverOptionTypePresent = true;
		osoption->optimization->solverOptions->solverOption[parserData->numberOfSolverOptions]->type = (yyvsp[(2) - (2)].sval);
	}
;}
    break;

  case 772:

    {	if (parserData->solverOptionNamePresent)
	{	osolerror( NULL, osoption, parserData, "only one name attribute allowed");
	}
	else
	{	parserData->solverOptionNamePresent = true;
		osoption->optimization->solverOptions->solverOption[parserData->numberOfSolverOptions]->name = (yyvsp[(2) - (2)].sval);
	}
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


