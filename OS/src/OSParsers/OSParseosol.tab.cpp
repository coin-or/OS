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
     GROUPWEIGHTATT = 280,
     NUMBEROFPROCESSESATT = 281,
     NUMBEROFSOLVEROPTIONSATT = 282,
     NUMBEROFSOSATT = 283,
     NUMBEROFVARIABLESATT = 284,
     NUMBEROFOBJECTIVESATT = 285,
     NUMBEROFCONSTRAINTSATT = 286,
     NUMBEROFOTHERVARIABLEOPTIONSATT = 287,
     NUMBEROFOTHEROBJECTIVEOPTIONSATT = 288,
     NUMBEROFOTHERCONSTRAINTOPTIONSATT = 289,
     NUMBEROFVARATT = 290,
     NUMBEROFOBJATT = 291,
     NUMBEROFCONATT = 292,
     NAMEATT = 293,
     IDXATT = 294,
     SOSIDXATT = 295,
     VALUEATT = 296,
     UNITATT = 297,
     DESCRIPTIONATT = 298,
     LBVALUEATT = 299,
     UBVALUEATT = 300,
     LBDUALVALUEATT = 301,
     UBDUALVALUEATT = 302,
     GENERALSTART = 303,
     GENERALEND = 304,
     SYSTEMSTART = 305,
     SYSTEMEND = 306,
     SERVICESTART = 307,
     SERVICEEND = 308,
     JOBSTART = 309,
     JOBEND = 310,
     OPTIMIZATIONSTART = 311,
     OPTIMIZATIONEND = 312,
     SERVICEURISTART = 313,
     SERVICEURIEND = 314,
     SERVICENAMESTART = 315,
     SERVICENAMEEND = 316,
     INSTANCENAMESTART = 317,
     INSTANCENAMEEND = 318,
     INSTANCELOCATIONSTART = 319,
     INSTANCELOCATIONEND = 320,
     JOBIDSTART = 321,
     JOBIDEND = 322,
     SOLVERTOINVOKESTART = 323,
     SOLVERTOINVOKEEND = 324,
     LICENSESTART = 325,
     LICENSEEND = 326,
     USERNAMESTART = 327,
     USERNAMEEND = 328,
     PASSWORDSTART = 329,
     PASSWORDEND = 330,
     CONTACTSTART = 331,
     CONTACTEND = 332,
     OTHEROPTIONSSTART = 333,
     OTHEROPTIONSEND = 334,
     OTHERSTART = 335,
     OTHEREND = 336,
     MINDISKSPACESTART = 337,
     MINDISKSPACEEND = 338,
     MINMEMORYSIZESTART = 339,
     MINMEMORYSIZEEND = 340,
     MINCPUSPEEDSTART = 341,
     MINCPUSPEEDEND = 342,
     MINCPUNUMBERSTART = 343,
     MINCPUNUMBEREND = 344,
     SERVICETYPESTART = 345,
     SERVICETYPEEND = 346,
     MAXTIMESTART = 347,
     MAXTIMEEND = 348,
     SCHEDULEDSTARTTIMESTART = 349,
     SCHEDULEDSTARTTIMEEND = 350,
     DEPENDENCIESSTART = 351,
     DEPENDENCIESEND = 352,
     REQUIREDDIRECTORIESSTART = 353,
     REQUIREDDIRECTORIESEND = 354,
     REQUIREDFILESSTART = 355,
     REQUIREDFILESEND = 356,
     PATHSTART = 357,
     PATHEND = 358,
     PATHPAIRSTART = 359,
     PATHPAIREND = 360,
     DIRECTORIESTOMAKESTART = 361,
     DIRECTORIESTOMAKEEND = 362,
     FILESTOMAKESTART = 363,
     FILESTOMAKEEND = 364,
     DIRECTORIESTODELETESTART = 365,
     DIRECTORIESTODELETEEND = 366,
     FILESTODELETESTART = 367,
     FILESTODELETEEND = 368,
     INPUTDIRECTORIESTOMOVESTART = 369,
     INPUTDIRECTORIESTOMOVEEND = 370,
     INPUTFILESTOMOVESTART = 371,
     INPUTFILESTOMOVEEND = 372,
     OUTPUTDIRECTORIESTOMOVESTART = 373,
     OUTPUTDIRECTORIESTOMOVEEND = 374,
     OUTPUTFILESTOMOVESTART = 375,
     OUTPUTFILESTOMOVEEND = 376,
     PROCESSESTOKILLSTART = 377,
     PROCESSESTOKILLEND = 378,
     PROCESSSTART = 379,
     PROCESSEND = 380,
     VARIABLESSTART = 381,
     VARIABLESEND = 382,
     INITIALVARIABLEVALUESSTART = 383,
     INITIALVARIABLEVALUESEND = 384,
     VARSTART = 385,
     VAREND = 386,
     INITIALVARIABLEVALUESSTRINGSTART = 387,
     INITIALVARIABLEVALUESSTRINGEND = 388,
     INITIALBASISSTATUSSTART = 389,
     INITIALBASISSTATUSEND = 390,
     INTEGERVARIABLEBRANCHINGWEIGHTSSTART = 391,
     INTEGERVARIABLEBRANCHINGWEIGHTSEND = 392,
     SOSVARIABLEBRANCHINGWEIGHTSSTART = 393,
     SOSVARIABLEBRANCHINGWEIGHTSEND = 394,
     SOSSTART = 395,
     SOSEND = 396,
     OBJECTIVESSTART = 397,
     OBJECTIVESEND = 398,
     INITIALOBJECTIVEVALUESSTART = 399,
     INITIALOBJECTIVEVALUESEND = 400,
     OBJSTART = 401,
     OBJEND = 402,
     INITIALOBJECTIVEBOUNDSSTART = 403,
     INITIALOBJECTIVEBOUNDSEND = 404,
     CONSTRAINTSSTART = 405,
     CONSTRAINTSEND = 406,
     INITIALCONSTRAINTVALUESSTART = 407,
     INITIALCONSTRAINTVALUESEND = 408,
     CONSTART = 409,
     CONEND = 410,
     INITIALDUALVALUESSTART = 411,
     INITIALDUALVALUESEND = 412,
     SOLVEROPTIONSSTART = 413,
     SOLVEROPTIONSEND = 414,
     SOLVEROPTIONSTART = 415,
     SOLVEROPTIONEND = 416,
     DUMMY = 417
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
#define GROUPWEIGHTATT 280
#define NUMBEROFPROCESSESATT 281
#define NUMBEROFSOLVEROPTIONSATT 282
#define NUMBEROFSOSATT 283
#define NUMBEROFVARIABLESATT 284
#define NUMBEROFOBJECTIVESATT 285
#define NUMBEROFCONSTRAINTSATT 286
#define NUMBEROFOTHERVARIABLEOPTIONSATT 287
#define NUMBEROFOTHEROBJECTIVEOPTIONSATT 288
#define NUMBEROFOTHERCONSTRAINTOPTIONSATT 289
#define NUMBEROFVARATT 290
#define NUMBEROFOBJATT 291
#define NUMBEROFCONATT 292
#define NAMEATT 293
#define IDXATT 294
#define SOSIDXATT 295
#define VALUEATT 296
#define UNITATT 297
#define DESCRIPTIONATT 298
#define LBVALUEATT 299
#define UBVALUEATT 300
#define LBDUALVALUEATT 301
#define UBDUALVALUEATT 302
#define GENERALSTART 303
#define GENERALEND 304
#define SYSTEMSTART 305
#define SYSTEMEND 306
#define SERVICESTART 307
#define SERVICEEND 308
#define JOBSTART 309
#define JOBEND 310
#define OPTIMIZATIONSTART 311
#define OPTIMIZATIONEND 312
#define SERVICEURISTART 313
#define SERVICEURIEND 314
#define SERVICENAMESTART 315
#define SERVICENAMEEND 316
#define INSTANCENAMESTART 317
#define INSTANCENAMEEND 318
#define INSTANCELOCATIONSTART 319
#define INSTANCELOCATIONEND 320
#define JOBIDSTART 321
#define JOBIDEND 322
#define SOLVERTOINVOKESTART 323
#define SOLVERTOINVOKEEND 324
#define LICENSESTART 325
#define LICENSEEND 326
#define USERNAMESTART 327
#define USERNAMEEND 328
#define PASSWORDSTART 329
#define PASSWORDEND 330
#define CONTACTSTART 331
#define CONTACTEND 332
#define OTHEROPTIONSSTART 333
#define OTHEROPTIONSEND 334
#define OTHERSTART 335
#define OTHEREND 336
#define MINDISKSPACESTART 337
#define MINDISKSPACEEND 338
#define MINMEMORYSIZESTART 339
#define MINMEMORYSIZEEND 340
#define MINCPUSPEEDSTART 341
#define MINCPUSPEEDEND 342
#define MINCPUNUMBERSTART 343
#define MINCPUNUMBEREND 344
#define SERVICETYPESTART 345
#define SERVICETYPEEND 346
#define MAXTIMESTART 347
#define MAXTIMEEND 348
#define SCHEDULEDSTARTTIMESTART 349
#define SCHEDULEDSTARTTIMEEND 350
#define DEPENDENCIESSTART 351
#define DEPENDENCIESEND 352
#define REQUIREDDIRECTORIESSTART 353
#define REQUIREDDIRECTORIESEND 354
#define REQUIREDFILESSTART 355
#define REQUIREDFILESEND 356
#define PATHSTART 357
#define PATHEND 358
#define PATHPAIRSTART 359
#define PATHPAIREND 360
#define DIRECTORIESTOMAKESTART 361
#define DIRECTORIESTOMAKEEND 362
#define FILESTOMAKESTART 363
#define FILESTOMAKEEND 364
#define DIRECTORIESTODELETESTART 365
#define DIRECTORIESTODELETEEND 366
#define FILESTODELETESTART 367
#define FILESTODELETEEND 368
#define INPUTDIRECTORIESTOMOVESTART 369
#define INPUTDIRECTORIESTOMOVEEND 370
#define INPUTFILESTOMOVESTART 371
#define INPUTFILESTOMOVEEND 372
#define OUTPUTDIRECTORIESTOMOVESTART 373
#define OUTPUTDIRECTORIESTOMOVEEND 374
#define OUTPUTFILESTOMOVESTART 375
#define OUTPUTFILESTOMOVEEND 376
#define PROCESSESTOKILLSTART 377
#define PROCESSESTOKILLEND 378
#define PROCESSSTART 379
#define PROCESSEND 380
#define VARIABLESSTART 381
#define VARIABLESEND 382
#define INITIALVARIABLEVALUESSTART 383
#define INITIALVARIABLEVALUESEND 384
#define VARSTART 385
#define VAREND 386
#define INITIALVARIABLEVALUESSTRINGSTART 387
#define INITIALVARIABLEVALUESSTRINGEND 388
#define INITIALBASISSTATUSSTART 389
#define INITIALBASISSTATUSEND 390
#define INTEGERVARIABLEBRANCHINGWEIGHTSSTART 391
#define INTEGERVARIABLEBRANCHINGWEIGHTSEND 392
#define SOSVARIABLEBRANCHINGWEIGHTSSTART 393
#define SOSVARIABLEBRANCHINGWEIGHTSEND 394
#define SOSSTART 395
#define SOSEND 396
#define OBJECTIVESSTART 397
#define OBJECTIVESEND 398
#define INITIALOBJECTIVEVALUESSTART 399
#define INITIALOBJECTIVEVALUESEND 400
#define OBJSTART 401
#define OBJEND 402
#define INITIALOBJECTIVEBOUNDSSTART 403
#define INITIALOBJECTIVEBOUNDSEND 404
#define CONSTRAINTSSTART 405
#define CONSTRAINTSEND 406
#define INITIALCONSTRAINTVALUESSTART 407
#define INITIALCONSTRAINTVALUESEND 408
#define CONSTART 409
#define CONEND 410
#define INITIALDUALVALUESSTART 411
#define INITIALDUALVALUESEND 412
#define SOLVEROPTIONSSTART 413
#define SOLVEROPTIONSEND 414
#define SOLVEROPTIONSTART 415
#define SOLVEROPTIONEND 416
#define DUMMY 417




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
#define YYFINAL  5
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   792

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  163
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  522
/* YYNRULES -- Number of rules.  */
#define YYNRULES  775
/* YYNRULES -- Number of states.  */
#define YYNSTATES  1299

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   417

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
     155,   156,   157,   158,   159,   160,   161,   162
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
     164,     0,    -1,   165,     8,   166,    12,    -1,   165,     9,
      -1,    10,    -1,    10,    11,    -1,   167,   232,   272,   297,
     435,    -1,    -1,   168,   169,    -1,    48,    -1,     8,   170,
      49,    -1,     9,    -1,    -1,   170,   171,    -1,   172,    -1,
     176,    -1,   180,    -1,   184,    -1,   190,    -1,   194,    -1,
     198,    -1,   202,    -1,   206,    -1,   210,    -1,   216,    -1,
     173,   174,    -1,    58,    -1,     9,    -1,     8,    59,    -1,
      -1,     8,     4,   175,    59,    -1,   177,   178,    -1,    60,
      -1,     9,    -1,     8,    61,    -1,    -1,     8,     4,   179,
      61,    -1,   181,   182,    -1,    62,    -1,     9,    -1,     8,
      63,    -1,    -1,     8,     4,   183,    63,    -1,   185,   186,
     188,    -1,    64,    -1,    -1,    -1,    13,     3,   187,     7,
      -1,     9,    -1,     8,   189,    65,    -1,    -1,     4,    -1,
     191,   192,    -1,    66,    -1,     9,    -1,     8,    67,    -1,
      -1,     8,     4,   193,    67,    -1,   195,   196,    -1,    68,
      -1,     9,    -1,     8,    69,    -1,    -1,     8,     4,   197,
      69,    -1,   199,   200,    -1,    70,    -1,     9,    -1,     8,
      71,    -1,    -1,     8,     4,   201,    71,    -1,   203,   204,
      -1,    72,    -1,     9,    -1,     8,    73,    -1,    -1,     8,
       4,   205,    73,    -1,   207,   208,    -1,    74,    -1,     9,
      -1,     8,    75,    -1,    -1,     8,     4,   209,    75,    -1,
     211,   212,   214,    -1,    76,    -1,    -1,    -1,    14,     3,
     213,     7,    -1,     9,    -1,     8,   215,    77,    -1,    -1,
       4,    -1,   217,   218,     8,   219,    -1,    78,    -1,    15,
       7,     5,     7,    -1,   220,    79,    -1,    -1,   220,   221,
      -1,    -1,    80,   222,   223,   231,    -1,    -1,   223,   224,
      -1,   225,    -1,   227,    -1,   229,    -1,    -1,    38,     3,
     226,     7,    -1,    -1,    41,     3,   228,     7,    -1,    -1,
      43,     3,   230,     7,    -1,     9,    -1,     8,    81,    -1,
      -1,   233,   234,    -1,    50,    -1,     8,   235,    51,    -1,
       9,    -1,    -1,   235,   236,    -1,   237,    -1,   242,    -1,
     247,    -1,   252,    -1,   256,    -1,   238,   239,   241,    -1,
      82,    -1,    -1,    -1,    42,     3,   240,     7,    -1,     9,
      -1,     8,    83,    -1,     8,     6,    83,    -1,     8,     5,
      83,    -1,   243,   244,   246,    -1,    84,    -1,    -1,    -1,
      42,     3,   245,     7,    -1,     9,    -1,     8,    85,    -1,
       8,     6,    85,    -1,     8,     5,    85,    -1,   248,   249,
     251,    -1,    86,    -1,    -1,    -1,    42,     3,   250,     7,
      -1,     9,    -1,     8,    87,    -1,     8,     6,    87,    -1,
       8,     5,    87,    -1,   253,   254,    -1,    88,    -1,     9,
      -1,     8,    89,    -1,    -1,     8,     5,   255,    89,    -1,
     257,   258,     8,   259,    -1,    78,    -1,    15,     7,     5,
       7,    -1,   260,    79,    -1,    -1,   260,   261,    -1,    -1,
      80,   262,   263,   271,    -1,    -1,   263,   264,    -1,   265,
      -1,   267,    -1,   269,    -1,    -1,    38,     3,   266,     7,
      -1,    -1,    41,     3,   268,     7,    -1,    -1,    43,     3,
     270,     7,    -1,     9,    -1,     8,    81,    -1,    -1,   273,
     274,    -1,    52,    -1,     8,   275,    53,    -1,     9,    -1,
      -1,   275,   276,    -1,   277,    -1,   281,    -1,   278,   279,
      -1,    90,    -1,     9,    -1,     8,    91,    -1,    -1,     8,
       4,   280,    91,    -1,   282,   283,     8,   284,    -1,    78,
      -1,    15,     7,     5,     7,    -1,   285,    79,    -1,    -1,
     285,   286,    -1,    -1,    80,   287,   288,   296,    -1,    -1,
     288,   289,    -1,   290,    -1,   292,    -1,   294,    -1,    -1,
      38,     3,   291,     7,    -1,    -1,    41,     3,   293,     7,
      -1,    -1,    43,     3,   295,     7,    -1,     9,    -1,     8,
      81,    -1,    -1,   298,   299,    -1,    54,    -1,     8,   300,
      55,    -1,     9,    -1,    -1,   300,   301,    -1,   302,    -1,
     307,    -1,   311,    -1,   317,    -1,   323,    -1,   329,    -1,
     335,    -1,   341,    -1,   356,    -1,   371,    -1,   386,    -1,
     401,    -1,   407,    -1,   413,    -1,   419,    -1,   303,   304,
     306,    -1,    92,    -1,    -1,    -1,    42,     3,   305,     7,
      -1,     9,    -1,     8,    93,    -1,     8,     6,    93,    -1,
       8,     5,    93,    -1,   308,   309,    -1,    94,    -1,     9,
      -1,     8,    95,    -1,    -1,     8,     4,   310,    95,    -1,
     312,   313,     8,   314,    97,    -1,    96,    -1,    16,     7,
       5,     7,    -1,    -1,   314,   315,    -1,    -1,    66,     8,
       4,   316,    67,    -1,   318,   319,     8,   320,    99,    -1,
      98,    -1,    17,     7,     5,     7,    -1,    -1,   320,   321,
      -1,    -1,   102,     8,     4,   322,   103,    -1,   324,   325,
       8,   326,   101,    -1,   100,    -1,    17,     7,     5,     7,
      -1,    -1,   326,   327,    -1,    -1,   102,     8,     4,   328,
     103,    -1,   330,   331,     8,   332,   107,    -1,   106,    -1,
      17,     7,     5,     7,    -1,    -1,   332,   333,    -1,    -1,
     102,     8,     4,   334,   103,    -1,   336,   337,     8,   338,
     109,    -1,   108,    -1,    17,     7,     5,     7,    -1,    -1,
     338,   339,    -1,    -1,   102,     8,     4,   340,   103,    -1,
     342,   343,     8,   344,   115,    -1,   114,    -1,    18,     7,
       5,     7,    -1,    -1,   344,   345,    -1,   346,   347,   355,
      -1,   104,    -1,    -1,   347,   348,    -1,   349,    -1,   351,
      -1,   353,    -1,    -1,    19,     3,   350,     7,    -1,    -1,
      20,     3,   352,     7,    -1,    -1,    21,     3,   354,     7,
      -1,     8,   105,    -1,     9,    -1,   357,   358,     8,   359,
     117,    -1,   116,    -1,    18,     7,     5,     7,    -1,    -1,
     359,   360,    -1,   361,   362,   370,    -1,   104,    -1,    -1,
     362,   363,    -1,   364,    -1,   366,    -1,   368,    -1,    -1,
      19,     3,   365,     7,    -1,    -1,    20,     3,   367,     7,
      -1,    -1,    21,     3,   369,     7,    -1,     8,   105,    -1,
       9,    -1,   372,   373,     8,   374,   119,    -1,   118,    -1,
      18,     7,     5,     7,    -1,    -1,   374,   375,    -1,   376,
     377,   385,    -1,   104,    -1,    -1,   377,   378,    -1,   379,
      -1,   381,    -1,   383,    -1,    -1,    19,     3,   380,     7,
      -1,    -1,    20,     3,   382,     7,    -1,    -1,    21,     3,
     384,     7,    -1,     8,   105,    -1,     9,    -1,   387,   388,
       8,   389,   121,    -1,   120,    -1,    18,     7,     5,     7,
      -1,    -1,   389,   390,    -1,   391,   392,   400,    -1,   104,
      -1,    -1,   392,   393,    -1,   394,    -1,   396,    -1,   398,
      -1,    -1,    19,     3,   395,     7,    -1,    -1,    20,     3,
     397,     7,    -1,    -1,    21,     3,   399,     7,    -1,     8,
     105,    -1,     9,    -1,   402,   403,     8,   404,   113,    -1,
     112,    -1,    17,     7,     5,     7,    -1,    -1,   404,   405,
      -1,    -1,   102,     8,     4,   406,   103,    -1,   408,   409,
       8,   410,   111,    -1,   110,    -1,    17,     7,     5,     7,
      -1,    -1,   410,   411,    -1,    -1,   102,     8,     4,   412,
     103,    -1,   414,   415,     8,   416,   123,    -1,   122,    -1,
      26,     7,     5,     7,    -1,    -1,   416,   417,    -1,    -1,
     124,     8,     4,   418,   125,    -1,   420,   421,     8,   422,
      -1,    78,    -1,    15,     7,     5,     7,    -1,   423,    79,
      -1,    -1,   423,   424,    -1,    -1,    80,   425,   426,   434,
      -1,    -1,   426,   427,    -1,   428,    -1,   430,    -1,   432,
      -1,    -1,    38,     3,   429,     7,    -1,    -1,    41,     3,
     431,     7,    -1,    -1,    43,     3,   433,     7,    -1,     9,
      -1,     8,    81,    -1,    -1,   436,   437,   442,    -1,    56,
      -1,    -1,   437,   438,    -1,   439,    -1,   440,    -1,   441,
      -1,    29,     7,     5,     7,    -1,    31,     7,     5,     7,
      -1,    30,     7,     5,     7,    -1,     8,   443,    57,    -1,
       9,    -1,   444,   544,   604,   664,    -1,    -1,   445,   446,
     447,    -1,   126,    -1,    -1,    32,     7,     5,     7,    -1,
       8,   448,   459,   470,   481,   492,   512,   127,    -1,     9,
      -1,    -1,   128,   449,     8,   450,   129,    -1,    35,     7,
       5,     7,    -1,    -1,   450,   451,    -1,   452,   453,   458,
      -1,   130,    -1,    -1,   453,   454,    -1,   455,    -1,   456,
      -1,    39,     7,     5,     7,    -1,    -1,    41,     3,   457,
       7,    -1,     8,   131,    -1,     9,    -1,    -1,   132,   460,
       8,   461,   133,    -1,    35,     7,     5,     7,    -1,    -1,
     461,   462,    -1,   463,   464,   469,    -1,   130,    -1,    -1,
     464,   465,    -1,   466,    -1,   467,    -1,    39,     7,     5,
       7,    -1,    -1,    41,     3,   468,     7,    -1,     8,   131,
      -1,     9,    -1,    -1,   134,   471,     8,   472,   135,    -1,
      35,     7,     5,     7,    -1,    -1,   472,   473,    -1,   474,
     475,   480,    -1,   130,    -1,    -1,   475,   476,    -1,   477,
      -1,   478,    -1,    39,     7,     5,     7,    -1,    -1,    41,
       3,   479,     7,    -1,     8,   131,    -1,     9,    -1,    -1,
     136,   482,     8,   483,   137,    -1,    35,     7,     5,     7,
      -1,    -1,   483,   484,    -1,   485,   486,   491,    -1,   130,
      -1,    -1,   486,   487,    -1,   488,    -1,   489,    -1,    39,
       7,     5,     7,    -1,    -1,    41,     3,   490,     7,    -1,
       8,   131,    -1,     9,    -1,    -1,   138,   493,     8,   494,
     139,    -1,    28,     7,     5,     7,    -1,    -1,   494,   495,
      -1,   496,   497,   502,    -1,   140,    -1,    -1,   497,   498,
      -1,   499,    -1,   501,    -1,   500,    -1,    40,     7,     5,
       7,    -1,    25,     7,     6,     7,    -1,    25,     7,     5,
       7,    -1,    35,     7,     5,     7,    -1,     8,   503,   141,
      -1,     9,    -1,    -1,   503,   504,    -1,   505,   506,   511,
      -1,   130,    -1,    -1,   506,   507,    -1,   508,    -1,   509,
      -1,    39,     7,     5,     7,    -1,    -1,    41,     3,   510,
       7,    -1,     8,   131,    -1,     9,    -1,    -1,   512,   513,
      -1,   514,   515,   530,    -1,    80,    -1,    -1,   515,   516,
      -1,   517,    -1,   518,    -1,   520,    -1,   522,    -1,   524,
      -1,   526,    -1,   528,    -1,    35,     7,     5,     7,    -1,
      -1,    38,     3,   519,     7,    -1,    -1,    41,     3,   521,
       7,    -1,    -1,    22,     3,   523,     7,    -1,    -1,    23,
       3,   525,     7,    -1,    -1,    24,     3,   527,     7,    -1,
      -1,    43,     3,   529,     7,    -1,     8,   531,    81,    -1,
      -1,   531,   532,    -1,   533,   534,   543,    -1,   130,    -1,
      -1,   534,   535,    -1,   536,    -1,   537,    -1,   539,    -1,
     541,    -1,    39,     7,     5,     7,    -1,    -1,    41,     3,
     538,     7,    -1,    -1,    44,     3,   540,     7,    -1,    -1,
      45,     3,   542,     7,    -1,     8,   131,    -1,     9,    -1,
      -1,   545,   546,   547,    -1,   142,    -1,    -1,    33,     7,
       5,     7,    -1,     8,   548,   559,   572,   143,    -1,     9,
      -1,    -1,   144,   549,     8,   550,   145,    -1,    36,     7,
       5,     7,    -1,    -1,   550,   551,    -1,   552,   553,   558,
      -1,   146,    -1,    -1,   553,   554,    -1,   555,    -1,   556,
      -1,    39,     7,     5,     7,    -1,    -1,    41,     3,   557,
       7,    -1,     8,   147,    -1,     9,    -1,    -1,   148,   560,
       8,   561,   149,    -1,    36,     7,     5,     7,    -1,    -1,
     561,   562,    -1,   563,   564,   571,    -1,   146,    -1,    -1,
     564,   565,    -1,   566,    -1,   567,    -1,   569,    -1,    39,
       7,     5,     7,    -1,    -1,    44,     3,   568,     7,    -1,
      -1,    45,     3,   570,     7,    -1,     8,   147,    -1,     9,
      -1,    -1,   572,   573,    -1,   574,   575,   590,    -1,    80,
      -1,    -1,   575,   576,    -1,   577,    -1,   578,    -1,   580,
      -1,   582,    -1,   584,    -1,   586,    -1,   588,    -1,    36,
       7,     5,     7,    -1,    -1,    38,     3,   579,     7,    -1,
      -1,    41,     3,   581,     7,    -1,    -1,    22,     3,   583,
       7,    -1,    -1,    23,     3,   585,     7,    -1,    -1,    24,
       3,   587,     7,    -1,    -1,    43,     3,   589,     7,    -1,
       8,   591,    81,    -1,    -1,   591,   592,    -1,   593,   594,
     603,    -1,   146,    -1,    -1,   594,   595,    -1,   596,    -1,
     597,    -1,   599,    -1,   601,    -1,    39,     7,     5,     7,
      -1,    -1,    41,     3,   598,     7,    -1,    -1,    44,     3,
     600,     7,    -1,    -1,    45,     3,   602,     7,    -1,     8,
     131,    -1,     9,    -1,    -1,   605,   606,   607,    -1,   150,
      -1,    -1,    34,     7,     5,     7,    -1,     8,   608,   619,
     632,   151,    -1,     9,    -1,    -1,   152,   609,     8,   610,
     153,    -1,    37,     7,     5,     7,    -1,    -1,   610,   611,
      -1,   612,   613,   618,    -1,   154,    -1,    -1,   613,   614,
      -1,   615,    -1,   616,    -1,    39,     7,     5,     7,    -1,
      -1,    41,     3,   617,     7,    -1,     8,   155,    -1,     9,
      -1,    -1,   156,   620,     8,   621,   157,    -1,    37,     7,
       5,     7,    -1,    -1,   621,   622,    -1,   623,   624,   631,
      -1,   154,    -1,    -1,   624,   625,    -1,   626,    -1,   627,
      -1,   629,    -1,    39,     7,     5,     7,    -1,    -1,    46,
       3,   628,     7,    -1,    -1,    47,     3,   630,     7,    -1,
       8,   155,    -1,     9,    -1,    -1,   632,   633,    -1,   634,
     635,   650,    -1,    80,    -1,    -1,   635,   636,    -1,   637,
      -1,   638,    -1,   640,    -1,   642,    -1,   644,    -1,   646,
      -1,   648,    -1,    37,     7,     5,     7,    -1,    -1,    38,
       3,   639,     7,    -1,    -1,    41,     3,   641,     7,    -1,
      -1,    22,     3,   643,     7,    -1,    -1,    23,     3,   645,
       7,    -1,    -1,    24,     3,   647,     7,    -1,    -1,    43,
       3,   649,     7,    -1,     8,   651,    81,    -1,    -1,   651,
     652,    -1,   653,   654,   663,    -1,   154,    -1,    -1,   654,
     655,    -1,   656,    -1,   657,    -1,   659,    -1,   661,    -1,
      39,     7,     5,     7,    -1,    -1,    41,     3,   658,     7,
      -1,    -1,    44,     3,   660,     7,    -1,    -1,    45,     3,
     662,     7,    -1,     8,   155,    -1,     9,    -1,    -1,   665,
     666,     8,   667,   159,    -1,   158,    -1,    27,     7,     5,
       7,    -1,    -1,   667,   668,    -1,    -1,   160,   669,   670,
     684,    -1,    -1,   670,   671,    -1,   672,    -1,   674,    -1,
     676,    -1,   678,    -1,   680,    -1,   682,    -1,    -1,    38,
       3,   673,     7,    -1,    -1,    41,     3,   675,     7,    -1,
      -1,    22,     3,   677,     7,    -1,    -1,    23,     3,   679,
       7,    -1,    -1,    24,     3,   681,     7,    -1,    -1,    43,
       3,   683,     7,    -1,     8,   161,    -1,     9,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   134,   134,   135,   137,   138,   140,   142,   142,   144,
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
    1825,  1838,  1838,  1841,  1841,  1844,  1855,  1855,  1857,  1870,
    1876,  1876,  1878,  1878,  1878,  1880,  1893,  1900,  1907,  1918,
    1919,  1921,  1921,  1923,  1931,  1938,  1938,  1940,  1940,  1942,
    1956,  1955,  1968,  1968,  1971,  1971,  1973,  1975,  1980,  1980,
    1983,  1984,  1985,  1986,  1987,  1988,  1989,  1991,  2005,  2004,
    2013,  2012,  2021,  2020,  2029,  2028,  2037,  2036,  2045,  2044,
    2053,  2070,  2070,  2072,  2082,  2087,  2087,  2090,  2091,  2092,
    2093,  2095,  2109,  2108,  2117,  2116,  2125,  2124,  2132,  2132,
    2136,  2136,  2138,  2142,  2142,  2151,  2152,  2154,  2154,  2157,
    2167,  2167,  2169,  2177,  2182,  2182,  2184,  2184,  2186,  2201,
    2200,  2213,  2213,  2216,  2216,  2219,  2229,  2229,  2231,  2240,
    2245,  2245,  2247,  2247,  2247,  2249,  2263,  2262,  2276,  2275,
    2288,  2288,  2292,  2292,  2294,  2296,  2301,  2301,  2304,  2305,
    2306,  2307,  2308,  2309,  2310,  2312,  2326,  2325,  2335,  2334,
    2344,  2343,  2353,  2352,  2362,  2361,  2371,  2370,  2380,  2397,
    2397,  2399,  2409,  2414,  2414,  2417,  2418,  2419,  2420,  2422,
    2437,  2436,  2446,  2445,  2455,  2454,  2463,  2463,  2466,  2466,
    2468,  2472,  2472,  2481,  2483,  2485,  2485,  2488,  2498,  2498,
    2500,  2508,  2513,  2513,  2515,  2515,  2517,  2532,  2531,  2544,
    2544,  2547,  2547,  2550,  2560,  2560,  2562,  2571,  2576,  2576,
    2578,  2578,  2578,  2580,  2594,  2593,  2607,  2606,  2620,  2620,
    2623,  2623,  2625,  2627,  2632,  2632,  2635,  2636,  2637,  2638,
    2639,  2640,  2641,  2643,  2657,  2656,  2665,  2664,  2673,  2672,
    2681,  2680,  2689,  2688,  2697,  2696,  2705,  2722,  2722,  2724,
    2734,  2741,  2741,  2744,  2745,  2746,  2747,  2749,  2765,  2764,
    2775,  2774,  2784,  2783,  2792,  2792,  2795,  2795,  2800,  2810,
    2818,  2818,  2821,  2820,  2838,  2838,  2841,  2842,  2843,  2844,
    2845,  2846,  2850,  2849,  2861,  2860,  2872,  2871,  2883,  2882,
    2894,  2893,  2905,  2904,  2916,  2916
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
  "CATEGORYATT", "TYPEATT", "GROUPWEIGHTATT", "NUMBEROFPROCESSESATT",
  "NUMBEROFSOLVEROPTIONSATT", "NUMBEROFSOSATT", "NUMBEROFVARIABLESATT",
  "NUMBEROFOBJECTIVESATT", "NUMBEROFCONSTRAINTSATT",
  "NUMBEROFOTHERVARIABLEOPTIONSATT", "NUMBEROFOTHEROBJECTIVEOPTIONSATT",
  "NUMBEROFOTHERCONSTRAINTOPTIONSATT", "NUMBEROFVARATT", "NUMBEROFOBJATT",
  "NUMBEROFCONATT", "NAMEATT", "IDXATT", "SOSIDXATT", "VALUEATT",
  "UNITATT", "DESCRIPTIONATT", "LBVALUEATT", "UBVALUEATT",
  "LBDUALVALUEATT", "UBDUALVALUEATT", "GENERALSTART", "GENERALEND",
  "SYSTEMSTART", "SYSTEMEND", "SERVICESTART", "SERVICEEND", "JOBSTART",
  "JOBEND", "OPTIMIZATIONSTART", "OPTIMIZATIONEND", "SERVICEURISTART",
  "SERVICEURIEND", "SERVICENAMESTART", "SERVICENAMEEND",
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
     415,   416,   417
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   163,   164,   164,   165,   165,   166,   167,   167,   168,
     169,   169,   170,   170,   171,   171,   171,   171,   171,   171,
     171,   171,   171,   171,   171,   172,   173,   174,   174,   175,
     174,   176,   177,   178,   178,   179,   178,   180,   181,   182,
     182,   183,   182,   184,   185,   186,   187,   186,   188,   188,
     189,   189,   190,   191,   192,   192,   193,   192,   194,   195,
     196,   196,   197,   196,   198,   199,   200,   200,   201,   200,
     202,   203,   204,   204,   205,   204,   206,   207,   208,   208,
     209,   208,   210,   211,   212,   213,   212,   214,   214,   215,
     215,   216,   217,   218,   219,   220,   220,   222,   221,   223,
     223,   224,   224,   224,   226,   225,   228,   227,   230,   229,
     231,   231,   232,   232,   233,   234,   234,   235,   235,   236,
     236,   236,   236,   236,   237,   238,   239,   240,   239,   241,
     241,   241,   241,   242,   243,   244,   245,   244,   246,   246,
     246,   246,   247,   248,   249,   250,   249,   251,   251,   251,
     251,   252,   253,   254,   254,   255,   254,   256,   257,   258,
     259,   260,   260,   262,   261,   263,   263,   264,   264,   264,
     266,   265,   268,   267,   270,   269,   271,   271,   272,   272,
     273,   274,   274,   275,   275,   276,   276,   277,   278,   279,
     279,   280,   279,   281,   282,   283,   284,   285,   285,   287,
     286,   288,   288,   289,   289,   289,   291,   290,   293,   292,
     295,   294,   296,   296,   297,   297,   298,   299,   299,   300,
     300,   301,   301,   301,   301,   301,   301,   301,   301,   301,
     301,   301,   301,   301,   301,   301,   302,   303,   304,   305,
     304,   306,   306,   306,   306,   307,   308,   309,   309,   310,
     309,   311,   312,   313,   314,   314,   316,   315,   317,   318,
     319,   320,   320,   322,   321,   323,   324,   325,   326,   326,
     328,   327,   329,   330,   331,   332,   332,   334,   333,   335,
     336,   337,   338,   338,   340,   339,   341,   342,   343,   344,
     344,   345,   346,   347,   347,   348,   348,   348,   350,   349,
     352,   351,   354,   353,   355,   355,   356,   357,   358,   359,
     359,   360,   361,   362,   362,   363,   363,   363,   365,   364,
     367,   366,   369,   368,   370,   370,   371,   372,   373,   374,
     374,   375,   376,   377,   377,   378,   378,   378,   380,   379,
     382,   381,   384,   383,   385,   385,   386,   387,   388,   389,
     389,   390,   391,   392,   392,   393,   393,   393,   395,   394,
     397,   396,   399,   398,   400,   400,   401,   402,   403,   404,
     404,   406,   405,   407,   408,   409,   410,   410,   412,   411,
     413,   414,   415,   416,   416,   418,   417,   419,   420,   421,
     422,   423,   423,   425,   424,   426,   426,   427,   427,   427,
     429,   428,   431,   430,   433,   432,   434,   434,   435,   435,
     436,   437,   437,   438,   438,   438,   439,   440,   441,   442,
     442,   443,   444,   444,   445,   446,   446,   447,   447,   448,
     448,   449,   450,   450,   451,   452,   453,   453,   454,   454,
     455,   457,   456,   458,   458,   459,   459,   460,   461,   461,
     462,   463,   464,   464,   465,   465,   466,   468,   467,   469,
     469,   470,   470,   471,   472,   472,   473,   474,   475,   475,
     476,   476,   477,   479,   478,   480,   480,   481,   481,   482,
     483,   483,   484,   485,   486,   486,   487,   487,   488,   490,
     489,   491,   491,   492,   492,   493,   494,   494,   495,   496,
     497,   497,   498,   498,   498,   499,   500,   500,   501,   502,
     502,   503,   503,   504,   505,   506,   506,   507,   507,   508,
     510,   509,   511,   511,   512,   512,   513,   514,   515,   515,
     516,   516,   516,   516,   516,   516,   516,   517,   519,   518,
     521,   520,   523,   522,   525,   524,   527,   526,   529,   528,
     530,   531,   531,   532,   533,   534,   534,   535,   535,   535,
     535,   536,   538,   537,   540,   539,   542,   541,   543,   543,
     544,   544,   545,   546,   546,   547,   547,   548,   548,   549,
     550,   550,   551,   552,   553,   553,   554,   554,   555,   557,
     556,   558,   558,   559,   559,   560,   561,   561,   562,   563,
     564,   564,   565,   565,   565,   566,   568,   567,   570,   569,
     571,   571,   572,   572,   573,   574,   575,   575,   576,   576,
     576,   576,   576,   576,   576,   577,   579,   578,   581,   580,
     583,   582,   585,   584,   587,   586,   589,   588,   590,   591,
     591,   592,   593,   594,   594,   595,   595,   595,   595,   596,
     598,   597,   600,   599,   602,   601,   603,   603,   604,   604,
     605,   606,   606,   607,   607,   608,   608,   609,   610,   610,
     611,   612,   613,   613,   614,   614,   615,   617,   616,   618,
     618,   619,   619,   620,   621,   621,   622,   623,   624,   624,
     625,   625,   625,   626,   628,   627,   630,   629,   631,   631,
     632,   632,   633,   634,   635,   635,   636,   636,   636,   636,
     636,   636,   636,   637,   639,   638,   641,   640,   643,   642,
     645,   644,   647,   646,   649,   648,   650,   651,   651,   652,
     653,   654,   654,   655,   655,   655,   655,   656,   658,   657,
     660,   659,   662,   661,   663,   663,   664,   664,   665,   666,
     667,   667,   669,   668,   670,   670,   671,   671,   671,   671,
     671,   671,   673,   672,   675,   674,   677,   676,   679,   678,
     681,   680,   683,   682,   684,   684
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
       0,     4,     0,     0,     5,     1,     7,     3,     9,     0,
     112,     0,     2,   114,   178,     0,    12,    11,     8,   180,
     214,     0,   117,   116,   113,     0,   216,   408,     0,   183,
     182,   179,     0,    10,    26,    32,    38,    44,    53,    59,
      65,    71,    77,    83,    92,    13,    14,     0,    15,     0,
      16,     0,    17,    45,    18,     0,    19,     0,    20,     0,
      21,     0,    22,     0,    23,    84,    24,     0,   410,     6,
     411,   219,   218,   215,     0,   115,   158,   125,   134,   143,
     152,   118,   119,   126,   120,   135,   121,   144,   122,     0,
     123,     0,     0,    27,    25,     0,    33,    31,     0,    39,
      37,     0,     0,     0,    54,    52,     0,    60,    58,     0,
      66,    64,     0,    72,    70,     0,    78,    76,     0,     0,
       0,     0,     0,     0,   181,   194,   188,   184,   185,     0,
     186,     0,     0,     0,     0,     0,     0,     0,     0,   153,
     151,     0,     0,    29,    28,    35,    34,    41,    40,    46,
      50,    48,    43,    56,    55,    62,    61,    68,    67,    74,
      73,    80,    79,    85,    89,    87,    82,     0,    95,   422,
     420,     0,     0,     0,   412,   413,   414,   415,   409,   217,
     388,   237,   246,   252,   259,   266,   273,   280,   374,   367,
     287,   307,   327,   347,   381,   220,   221,   238,   222,     0,
     223,     0,   224,     0,   225,     0,   226,     0,   227,     0,
     228,     0,   229,     0,   230,     0,   231,     0,   232,     0,
     233,     0,   234,     0,   235,     0,     0,   189,   187,     0,
       0,   127,     0,   129,   124,   136,     0,   138,   133,   145,
       0,   147,   142,   155,   154,     0,   161,     0,     0,     0,
       0,    51,     0,     0,     0,     0,     0,     0,     0,    90,
       0,     0,    91,     0,   424,     0,   570,   425,     0,     0,
       0,     0,     0,     0,   247,   245,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   191,   190,     0,   197,     0,     0,     0,   130,
       0,     0,     0,   139,     0,     0,     0,   148,     0,     0,
     157,     0,    30,    36,    42,    47,    49,    57,    63,    69,
      75,    81,    86,    88,    93,    94,    97,    96,   419,   572,
     658,   573,     0,     0,     0,     0,     0,   239,     0,   241,
     236,   249,   248,     0,   254,     0,   261,     0,   268,     0,
     275,     0,   282,     0,   289,     0,   309,     0,   329,     0,
     349,     0,   369,     0,   376,     0,   383,     0,   391,     0,
       0,   193,     0,   128,   132,   131,   137,   141,   140,   146,
     150,   149,   156,   159,   160,   163,   162,    99,   660,   746,
     661,     0,     0,     0,   429,   428,   423,   416,   418,   417,
       0,     0,     0,   242,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     387,     0,   192,   195,   196,   199,   198,   165,     0,   748,
     421,     0,     0,     0,     0,   577,   576,   571,     0,     0,
     445,   240,   244,   243,   250,   253,     0,   251,   255,   260,
     258,     0,   262,   267,   265,     0,   269,   274,     0,   272,
     276,   281,     0,   279,   283,   288,   292,   286,   290,   293,
     308,   312,   306,   310,   313,   328,   332,   326,   330,   333,
     348,   352,   346,   350,   353,   368,     0,   366,   370,   375,
       0,   373,   377,   382,   380,     0,   384,   389,   390,   393,
     392,   201,     0,     0,   110,     0,     0,     0,   100,   101,
     102,   103,    98,     0,     0,     0,   665,   664,   659,     0,
       0,   593,   426,     0,     0,     0,   461,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   395,
       0,     0,   176,     0,     0,     0,   166,   167,   168,   169,
     164,   111,   104,   106,   108,     0,   750,     0,     0,   681,
     574,     0,     0,     0,   612,     0,   432,     0,     0,     0,
     477,   256,   263,   270,   277,   284,     0,   305,     0,     0,
       0,   294,   295,   296,   297,   291,     0,   325,     0,     0,
       0,   314,   315,   316,   317,   311,     0,   345,     0,     0,
       0,   334,   335,   336,   337,   331,     0,   365,     0,     0,
       0,   354,   355,   356,   357,   351,   371,   378,   385,     0,
       0,   212,     0,     0,     0,   202,   203,   204,   205,   200,
     177,   170,   172,   174,     0,     0,     0,     0,     0,   662,
       0,     0,     0,   700,     0,   580,     0,     0,     0,     0,
       0,     0,   448,     0,     0,     0,   493,     0,     0,     0,
       0,     0,   304,   298,   300,   302,   324,   318,   320,   322,
     344,   338,   340,   342,   364,   358,   360,   362,     0,     0,
       0,     0,   406,     0,     0,     0,   396,   397,   398,   399,
     394,   213,   206,   208,   210,     0,     0,     0,   105,   107,
     109,   749,   747,   752,   751,     0,   668,     0,     0,     0,
       0,     0,     0,   596,   615,   575,   613,   616,   431,   430,
     435,   433,   436,     0,     0,     0,   464,     0,     0,     0,
     524,   257,   264,   271,   278,   285,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   372,   379,
     386,   407,   400,   402,   404,     0,     0,     0,   171,   173,
     175,   754,     0,     0,     0,   684,   703,   663,   701,   704,
     579,   578,   583,   581,   584,     0,     0,     0,     0,   447,
     451,   446,   449,   452,     0,     0,     0,   480,     0,     0,
       0,   299,   301,   303,   319,   321,   323,   339,   341,   343,
     359,   361,   363,     0,     0,     0,   207,   209,   211,     0,
     667,   666,   671,   669,   672,     0,     0,     0,     0,   595,
     599,   594,   597,   600,   639,     0,     0,     0,     0,     0,
       0,     0,   617,   618,   619,   620,   621,   622,   623,   624,
     614,     0,   444,     0,     0,   437,   438,   439,   434,     0,
     463,   467,   462,   465,   468,     0,     0,     0,   496,   527,
     427,   525,   528,   401,   403,   405,     0,   775,     0,     0,
       0,     0,     0,     0,   755,   756,   757,   758,   759,   760,
     761,   753,     0,   683,   687,   682,   685,   688,   727,     0,
       0,     0,     0,     0,     0,     0,   705,   706,   707,   708,
     709,   710,   711,   712,   702,     0,   592,     0,     0,   585,
     586,   587,   582,     0,     0,   630,   632,   634,     0,   626,
     628,   636,   443,     0,   441,     0,   460,     0,     0,   453,
     454,   455,   450,     0,   479,   483,   478,   481,   484,     0,
       0,     0,   774,   766,   768,   770,   762,   764,   772,     0,
     680,     0,     0,   673,   674,   675,   670,     0,     0,   718,
     720,   722,     0,   714,   716,   724,   591,     0,   589,     0,
     611,     0,     0,     0,   601,   602,   603,   604,   598,   638,
     642,   640,   643,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   459,     0,   457,     0,   476,     0,     0,   469,
     470,   471,   466,     0,   495,   494,   499,   497,   500,   551,
       0,     0,     0,     0,     0,     0,     0,   529,   530,   531,
     532,   533,   534,   535,   536,   526,     0,     0,     0,     0,
       0,     0,   679,     0,   677,     0,   699,     0,     0,     0,
     689,   690,   691,   692,   686,   726,   730,   728,   731,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   610,     0,
     606,   608,     0,   631,   633,   635,   625,   627,   629,   637,
     440,   442,     0,     0,   475,     0,   473,     0,   492,     0,
       0,   485,   486,   487,   482,     0,     0,   542,   544,   546,
       0,   538,   540,   548,   767,   769,   771,   763,   765,   773,
       0,     0,   698,     0,   694,   696,     0,   719,   721,   723,
     713,   715,   717,   725,   588,   590,     0,     0,     0,     0,
     657,     0,     0,     0,     0,   644,   645,   646,   647,   648,
     641,   456,   458,     0,     0,   491,     0,   489,   511,   510,
       0,     0,     0,   501,   502,   504,   503,   498,   550,   554,
     552,   555,     0,     0,     0,     0,     0,     0,     0,   676,
     678,     0,     0,     0,     0,   745,     0,     0,     0,     0,
     732,   733,   734,   735,   736,   729,   605,   607,   609,   656,
       0,   650,   652,   654,   472,   474,     0,     0,     0,     0,
       0,     0,     0,   543,   545,   547,   537,   539,   541,   549,
     693,   695,   697,   744,     0,   738,   740,   742,     0,     0,
       0,     0,   488,   490,   514,   509,   512,   515,     0,     0,
       0,     0,     0,   569,     0,     0,     0,     0,   556,   557,
     558,   559,   560,   553,     0,     0,     0,     0,   649,   651,
     653,   655,     0,   507,   506,   508,   505,   568,     0,   562,
     564,   566,   737,   739,   741,   743,     0,   523,     0,     0,
     516,   517,   518,   513,     0,     0,     0,     0,   522,     0,
     520,   561,   563,   565,   567,     0,     0,   519,   521
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,     9,    10,    11,    18,    25,    45,    46,
      47,    94,   247,    48,    49,    97,   248,    50,    51,   100,
     249,    52,    53,   102,   250,   152,   252,    54,    55,   105,
     253,    56,    57,   108,   254,    58,    59,   111,   255,    60,
      61,   114,   256,    62,    63,   117,   257,    64,    65,   119,
     258,   166,   260,    66,    67,   121,   262,   263,   337,   397,
     448,   528,   529,   654,   530,   655,   531,   656,   532,    14,
      15,    24,    32,    81,    82,    83,   133,   306,   234,    84,
      85,   135,   310,   238,    86,    87,   137,   314,   242,    88,
      89,   140,   318,    90,    91,   142,   320,   321,   396,   447,
     522,   566,   567,   715,   568,   716,   569,   717,   570,    20,
      21,    31,    74,   127,   128,   129,   228,   379,   130,   131,
     230,   381,   382,   446,   521,   560,   645,   646,   775,   647,
     776,   648,   777,   649,    27,    28,    73,   123,   195,   196,
     197,   272,   410,   350,   198,   199,   275,   414,   200,   201,
     277,   416,   468,   677,   202,   203,   279,   418,   472,   678,
     204,   205,   281,   420,   476,   679,   206,   207,   283,   422,
     480,   680,   208,   209,   285,   424,   484,   681,   210,   211,
     287,   426,   488,   489,   552,   601,   602,   756,   603,   757,
     604,   758,   605,   212,   213,   289,   428,   493,   494,   553,
     611,   612,   759,   613,   760,   614,   761,   615,   214,   215,
     291,   430,   498,   499,   554,   621,   622,   762,   623,   763,
     624,   764,   625,   216,   217,   293,   432,   503,   504,   555,
     631,   632,   765,   633,   766,   634,   767,   635,   218,   219,
     295,   434,   508,   698,   220,   221,   297,   436,   512,   699,
     222,   223,   299,   438,   516,   700,   224,   225,   301,   440,
     441,   520,   559,   639,   706,   707,   823,   708,   824,   709,
     825,   710,    69,    70,   122,   174,   175,   176,   177,   178,
     265,   266,   267,   343,   406,   460,   544,   670,   741,   742,
     798,   865,   866,   867,  1011,   868,   546,   588,   744,   802,
     803,   869,   949,   950,   951,  1093,   952,   590,   674,   805,
     873,   874,   953,  1019,  1020,  1021,  1154,  1022,   676,   748,
     876,   957,   958,  1023,  1101,  1102,  1103,  1207,  1104,   750,
     809,   960,  1027,  1028,  1105,  1163,  1164,  1165,  1166,  1167,
    1208,  1236,  1237,  1262,  1280,  1281,  1282,  1296,  1283,   810,
     881,   882,   961,  1037,  1038,  1039,  1176,  1040,  1177,  1041,
    1172,  1042,  1173,  1043,  1174,  1044,  1178,  1045,  1106,  1170,
    1171,  1212,  1248,  1249,  1250,  1285,  1251,  1286,  1252,  1287,
    1253,   340,   341,   402,   457,   541,   582,   731,   793,   794,
     838,   929,   930,   931,  1077,   932,   584,   667,   796,   842,
     843,   933,   994,   995,   996,  1137,   997,  1138,   998,   668,
     736,   737,   797,   852,   853,   854,  1007,   855,  1008,   856,
    1003,   857,  1004,   858,  1005,   859,  1009,   860,   934,  1001,
    1002,  1082,  1145,  1146,  1147,  1229,  1148,  1230,  1149,  1231,
    1150,   399,   400,   453,   538,   579,   661,   783,   833,   834,
     902,   973,   974,   975,  1121,   976,   663,   728,   836,   906,
     907,   977,  1060,  1061,  1062,  1182,  1063,  1183,  1064,   729,
     788,   789,   837,   916,   917,   918,  1073,   919,  1074,   920,
    1069,   921,  1070,   922,  1071,   923,  1075,   924,   978,  1067,
    1068,  1126,  1190,  1191,  1192,  1255,  1193,  1256,  1194,  1257,
    1195,   450,   451,   534,   658,   724,   781,   829,   894,   895,
    1049,   896,  1050,   897,  1046,   898,  1047,   899,  1048,   900,
    1051,   901
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -81
static const yytype_int16 yypact[] =
{
      25,    30,    43,   137,   -81,   -81,    46,   -81,   -81,    33,
       5,   248,   -81,   -81,    -5,   254,   -81,   -81,   -81,   -81,
      22,   262,   -81,   -81,   -81,   219,   -81,    42,   295,   -81,
     -81,   -81,    49,   -81,   -81,   -81,   -81,   -81,   -81,   -81,
     -81,   -81,   -81,   -81,   -81,   -81,   -81,   297,   -81,   299,
     -81,   307,   -81,    48,   -81,   309,   -81,   311,   -81,   313,
     -81,   315,   -81,   317,   -81,    88,   -81,    89,   -81,   -81,
     -81,   -81,   -81,   -81,   -21,   -81,   -81,   -81,   -81,   -81,
     -81,   -81,   -81,    66,   -81,    68,   -81,    70,   -81,   319,
     -81,    99,    14,   -81,   -81,    18,   -81,   -81,    15,   -81,
     -81,   113,   321,    13,   -81,   -81,    16,   -81,   -81,    12,
     -81,   -81,    11,   -81,   -81,     7,   -81,   -81,   115,   323,
     117,   112,   142,     3,   -81,   -81,   -81,   -81,   -81,   325,
     -81,   107,   123,   327,   127,   329,   129,   331,    -1,   -81,
     -81,   156,   126,   -81,   -81,   -81,   -81,   -81,   -81,   -81,
     143,   -81,   -81,   -81,   -81,   -81,   -81,   -81,   -81,   -81,
     -81,   -81,   -81,   -81,   170,   -81,   -81,   192,   -81,   102,
     -81,   227,   241,   243,   -81,   -81,   -81,   -81,   -81,   -81,
     -81,   -81,   -81,   -81,   -81,   -81,   -81,   -81,   -81,   -81,
     -81,   -81,   -81,   -81,   -81,   -81,   -81,   211,   -81,   333,
     -81,   249,   -81,   242,   -81,   257,   -81,   263,   -81,   265,
     -81,   266,   -81,   270,   -81,   274,   -81,   276,   -81,   269,
     -81,   273,   -81,   246,   -81,   285,     1,   -81,   -81,   289,
     347,   -81,     4,   -81,   -81,   -81,     8,   -81,   -81,   -81,
       2,   -81,   -81,   -81,   -81,   361,   -81,   318,   320,   316,
     371,   -81,   322,   324,   314,   326,   312,   305,   375,   -81,
     328,   377,   -81,   264,   -81,   332,   244,   356,   385,   387,
     388,   391,   337,    -4,   -81,   -81,   389,   390,   392,   393,
     395,   396,   399,   400,   402,   403,   405,   406,   408,   409,
     411,   412,   414,   415,   417,   418,   420,   421,   423,   424,
     426,   427,   -81,   -81,   398,   -81,   429,   330,   336,   -81,
     430,   310,   340,   -81,   431,   335,   344,   -81,   339,   432,
     -81,   268,   -81,   -81,   -81,   -81,   -81,   -81,   -81,   -81,
     -81,   -81,   -81,   -81,   -81,   -81,   -81,   -81,   -81,   -81,
     250,   374,   433,   341,   434,   435,   436,   -81,    -3,   -81,
     -81,   -81,   -81,   439,   -81,   440,   -81,   441,   -81,   442,
     -81,   443,   -81,   444,   -81,   445,   -81,   446,   -81,   447,
     -81,   448,   -81,   449,   -81,   450,   -81,   451,   -81,   343,
     452,   -81,   272,   -81,   -81,   -81,   -81,   -81,   -81,   -81,
     -81,   -81,   -81,   -81,   -81,   -81,   -81,   -81,   -81,   252,
     382,   453,   345,   456,   334,   -81,   -81,   -81,   -81,   -81,
     457,   364,   365,   -81,   370,   459,   -30,   460,    58,   461,
     255,   462,    94,   463,   145,   464,   -62,   465,   -71,   466,
     -70,   467,   -73,   468,    -6,   469,    51,   470,   235,   471,
     -81,   281,   -81,   -81,   -81,   -81,   -81,   -81,   186,   -81,
     -81,   454,   472,   354,   458,   338,   -81,   -81,   473,   455,
     351,   -81,   -81,   -81,   -81,   -81,   476,   -81,   -81,   -81,
     -81,   477,   -81,   -81,   -81,   478,   -81,   -81,   479,   -81,
     -81,   -81,   480,   -81,   -81,   -81,   -81,   -81,   -81,   -81,
     -81,   -81,   -81,   -81,   -81,   -81,   -81,   -81,   -81,   -81,
     -81,   -81,   -81,   -81,   -81,   -81,   481,   -81,   -81,   -81,
     483,   -81,   -81,   -81,   -81,   484,   -81,   -81,   -81,   -81,
     -81,   -81,   197,   413,   -81,   490,   492,   493,   -81,   -81,
     -81,   -81,   -81,   491,   489,   494,   348,   -81,   -81,   495,
     474,   353,   -81,   496,   497,   482,   372,   500,   503,   504,
     505,   507,    31,   135,   290,   293,   508,   509,   510,   -81,
     217,   437,   -81,   512,   513,   516,   -81,   -81,   -81,   -81,
     -81,   -81,   -81,   -81,   -81,   515,   -81,   514,   485,   367,
     -81,   517,   518,   498,   -81,   520,   -81,   521,   519,   501,
     394,   -81,   -81,   -81,   -81,   -81,   428,   -81,   526,   528,
     529,   -81,   -81,   -81,   -81,   -81,   438,   -81,   532,   534,
     535,   -81,   -81,   -81,   -81,   -81,   475,   -81,   536,   537,
     538,   -81,   -81,   -81,   -81,   -81,   486,   -81,   539,   541,
     542,   -81,   -81,   -81,   -81,   -81,   -81,   -81,   -81,   223,
     487,   -81,   543,   544,   545,   -81,   -81,   -81,   -81,   -81,
     -81,   -81,   -81,   -81,   546,   547,   548,   549,   205,   -81,
     550,   551,   523,   -81,   553,   -81,   554,   555,   -68,   557,
     238,   560,   -81,   559,   561,   527,   488,   506,   499,   502,
     511,   522,   -81,   -81,   -81,   -81,   -81,   -81,   -81,   -81,
     -81,   -81,   -81,   -81,   -81,   -81,   -81,   -81,   524,   525,
     425,   530,   -81,   564,   567,   568,   -81,   -81,   -81,   -81,
     -81,   -81,   -81,   -81,   -81,   565,   569,   570,   -81,   -81,
     -81,   -81,   -81,   -81,   -81,   573,   -81,   572,   566,   -74,
     574,   224,   577,   -81,   -81,   -81,   -81,   -81,   -81,   -81,
     -81,   -81,   -81,   576,    53,   579,   -81,   578,   580,   558,
     -81,   -81,   -81,   -81,   -81,   -81,   582,   583,   585,   586,
     587,   588,   589,   590,   591,   592,   593,   594,   -81,   -81,
     -81,   -81,   -81,   -81,   -81,   596,   597,   599,   -81,   -81,
     -81,   -81,   600,   218,   603,   -81,   -81,   -81,   -81,   -81,
     -81,   -81,   -81,   -81,   -81,   602,    84,   144,    29,   -81,
     -81,   -81,   -81,   -81,   605,    81,   608,   -81,   609,   607,
     -56,   -81,   -81,   -81,   -81,   -81,   -81,   -81,   -81,   -81,
     -81,   -81,   -81,   610,   611,   612,   -81,   -81,   -81,   169,
     -81,   -81,   -81,   -81,   -81,   613,    95,   176,   140,   -81,
     -81,   -81,   -81,   -81,   -81,   584,   618,   619,   616,   621,
     626,   627,   -81,   -81,   -81,   -81,   -81,   -81,   -81,   -81,
     -81,   531,   -81,   624,   629,   -81,   -81,   -81,   -81,   181,
     -81,   -81,   -81,   -81,   -81,   628,   114,   631,   -81,   -81,
     -81,   -81,   -81,   -81,   -81,   -81,   533,   -81,   630,   634,
     635,   636,   637,   638,   -81,   -81,   -81,   -81,   -81,   -81,
     -81,   -81,   200,   -81,   -81,   -81,   -81,   -81,   -81,   639,
     640,   641,   642,   643,   644,   645,   -81,   -81,   -81,   -81,
     -81,   -81,   -81,   -81,   -81,   404,   -81,   646,   647,   -81,
     -81,   -81,   -81,   131,   -60,   -81,   -81,   -81,   649,   -81,
     -81,   -81,   -81,   650,   -81,   540,   -81,   651,   648,   -81,
     -81,   -81,   -81,   228,   -81,   -81,   -81,   -81,   -81,   652,
     236,   180,   -81,   -81,   -81,   -81,   -81,   -81,   -81,   397,
     -81,   653,   654,   -81,   -81,   -81,   -81,    17,   -80,   -81,
     -81,   -81,   656,   -81,   -81,   -81,   -81,   658,   -81,   552,
     -81,   657,   662,   663,   -81,   -81,   -81,   -81,   -81,   -81,
     -81,   -81,   -81,   660,   661,   665,   666,   667,   668,   669,
     670,   671,   -81,   664,   -81,   556,   -81,   672,   677,   -81,
     -81,   -81,   -81,   234,   -81,   -81,   -81,   -81,   -81,   -81,
     678,   679,   680,   681,   682,   683,   686,   -81,   -81,   -81,
     -81,   -81,   -81,   -81,   -81,   -81,   684,   685,   688,   689,
     690,   691,   -81,   695,   -81,   562,   -81,   694,   687,   699,
     -81,   -81,   -81,   -81,   -81,   -81,   -81,   -81,   -81,   696,
     697,   698,   700,   701,   702,   703,   704,   705,   -81,   708,
     -81,   -81,    21,   -81,   -81,   -81,   -81,   -81,   -81,   -81,
     -81,   -81,   707,   709,   -81,   710,   -81,   575,   -81,   711,
     716,   -81,   -81,   -81,   -81,    19,   -58,   -81,   -81,   -81,
     715,   -81,   -81,   -81,   -81,   -81,   -81,   -81,   -81,   -81,
     714,   717,   -81,   718,   -81,   -81,    97,   -81,   -81,   -81,
     -81,   -81,   -81,   -81,   -81,   -81,   719,   720,   721,   598,
     -81,   723,   722,   728,   729,   -81,   -81,   -81,   -81,   -81,
     -81,   -81,   -81,   726,   727,   -81,   730,   -81,   -81,   -81,
     731,   732,   733,   -81,   -81,   -81,   -81,   -81,   -81,   -81,
     -81,   -81,   734,   735,   736,   737,   738,   739,   740,   -81,
     -81,   741,   742,   743,   581,   -81,   744,   749,   750,   751,
     -81,   -81,   -81,   -81,   -81,   -81,   -81,   -81,   -81,   -81,
     752,   -81,   -81,   -81,   -81,   -81,   748,   753,    28,   368,
     754,   756,   120,   -81,   -81,   -81,   -81,   -81,   -81,   -81,
     -81,   -81,   -81,   -81,   757,   -81,   -81,   -81,   758,   759,
     760,   761,   -81,   -81,   -81,   -81,   -81,   -81,   762,   763,
     764,   765,   606,   -81,   766,   755,   771,   772,   -81,   -81,
     -81,   -81,   -81,   -81,   769,   770,   773,   774,   -81,   -81,
     -81,   -81,   237,   -81,   -81,   -81,   -81,   -81,   777,   -81,
     -81,   -81,   -81,   -81,   -81,   -81,   625,   -81,   776,   775,
     -81,   -81,   -81,   -81,   778,   779,   780,   781,   -81,   784,
     -81,   -81,   -81,   -81,   -81,   783,   785,   -81,   -81
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -81,   -81,   -81,   -81,   -81,   -81,   -81,   -81,   -81,   -81,
     -81,   -81,   -81,   -81,   -81,   -81,   -81,   -81,   -81,   -81,
     -81,   -81,   -81,   -81,   -81,   -81,   -81,   -81,   -81,   -81,
     -81,   -81,   -81,   -81,   -81,   -81,   -81,   -81,   -81,   -81,
     -81,   -81,   -81,   -81,   -81,   -81,   -81,   -81,   -81,   -81,
     -81,   -81,   -81,   -81,   -81,   -81,   -81,   -81,   -81,   -81,
     -81,   -81,   -81,   -81,   -81,   -81,   -81,   -81,   -81,   -81,
     -81,   -81,   -81,   -81,   -81,   -81,   -81,   -81,   -81,   -81,
     -81,   -81,   -81,   -81,   -81,   -81,   -81,   -81,   -81,   -81,
     -81,   -81,   -81,   -81,   -81,   -81,   -81,   -81,   -81,   -81,
     -81,   -81,   -81,   -81,   -81,   -81,   -81,   -81,   -81,   -81,
     -81,   -81,   -81,   -81,   -81,   -81,   -81,   -81,   -81,   -81,
     -81,   -81,   -81,   -81,   -81,   -81,   -81,   -81,   -81,   -81,
     -81,   -81,   -81,   -81,   -81,   -81,   -81,   -81,   -81,   -81,
     -81,   -81,   -81,   -81,   -81,   -81,   -81,   -81,   -81,   -81,
     -81,   -81,   -81,   -81,   -81,   -81,   -81,   -81,   -81,   -81,
     -81,   -81,   -81,   -81,   -81,   -81,   -81,   -81,   -81,   -81,
     -81,   -81,   -81,   -81,   -81,   -81,   -81,   -81,   -81,   -81,
     -81,   -81,   -81,   -81,   -81,   -81,   -81,   -81,   -81,   -81,
     -81,   -81,   -81,   -81,   -81,   -81,   -81,   -81,   -81,   -81,
     -81,   -81,   -81,   -81,   -81,   -81,   -81,   -81,   -81,   -81,
     -81,   -81,   -81,   -81,   -81,   -81,   -81,   -81,   -81,   -81,
     -81,   -81,   -81,   -81,   -81,   -81,   -81,   -81,   -81,   -81,
     -81,   -81,   -81,   -81,   -81,   -81,   -81,   -81,   -81,   -81,
     -81,   -81,   -81,   -81,   -81,   -81,   -81,   -81,   -81,   -81,
     -81,   -81,   -81,   -81,   -81,   -81,   -81,   -81,   -81,   -81,
     -81,   -81,   -81,   -81,   -81,   -81,   -81,   -81,   -81,   -81,
     -81,   -81,   -81,   -81,   -81,   -81,   -81,   -81,   -81,   -81,
     -81,   -81,   -81,   -81,   -81,   -81,   -81,   -81,   -81,   -81,
     -81,   -81,   -81,   -81,   -81,   -81,   -81,   -81,   -81,   -81,
     -81,   -81,   -81,   -81,   -81,   -81,   -81,   -81,   -81,   -81,
     -81,   -81,   -81,   -81,   -81,   -81,   -81,   -81,   -81,   -81,
     -81,   -81,   -81,   -81,   -81,   -81,   -81,   -81,   -81,   -81,
     -81,   -81,   -81,   -81,   -81,   -81,   -81,   -81,   -81,   -81,
     -81,   -81,   -81,   -81,   -81,   -81,   -81,   -81,   -81,   -81,
     -81,   -81,   -81,   -81,   -81,   -81,   -81,   -81,   -81,   -81,
     -81,   -81,   -81,   -81,   -81,   -81,   -81,   -81,   -81,   -81,
     -81,   -81,   -81,   -81,   -81,   -81,   -81,   -81,   -81,   -81,
     -81,   -81,   -81,   -81,   -81,   -81,   -81,   -81,   -81,   -81,
     -81,   -81,   -81,   -81,   -81,   -81,   -81,   -81,   -81,   -81,
     -81,   -81,   -81,   -81,   -81,   -81,   -81,   -81,   -81,   -81,
     -81,   -81,   -81,   -81,   -81,   -81,   -81,   -81,   -81,   -81,
     -81,   -81,   -81,   -81,   -81,   -81,   -81,   -81,   -81,   -81,
     -81,   -81,   -81,   -81,   -81,   -81,   -81,   -81,   -81,   -81,
     -81,   -81,   -81,   -81,   -81,   -81,   -81,   -81,   -81,   -81,
     -81,   -81,   -81,   -81,   -81,   -81,   -81,   -81,   -81,   -81,
     -81,   -81,   -81,   -81,   -81,   -81,   -81,   -81,   -81,   -81,
     -81,   -81,   -81,   -81,   -81,   -81,   -81,   -81,   -81,   -81,
     -81,   -81,   -81,   -81,   -81,   -81,   -81,   -81,   -81,   -81,
     -81,   -81,   -81,   -81,   -81,   -81,   -81,   -81,   -81,   -81,
     -81,   -81,   -81,   -81,   -81,   -81,   -81,   -81,   -81,   -81,
     -81,   -81,   -81,   -81,   -81,   -81,   -81,   -81,   -81,   -81,
     -81,   -81
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint16 yytable[] =
{
     351,  1065,   411,   412,   243,   302,   786,   315,   316,   307,
     308,   161,   734,   311,   312,   159,   157,   153,   143,   147,
     155,   999,   145,  1168,   879,  1055,  1056,  1158,  1159,  1139,
    1140,   501,   124,   491,   496,     1,   466,   861,   862,   596,
     597,     4,   486,     5,  1160,    12,   492,    19,   502,   497,
     598,   599,   600,   487,  1161,    13,  1057,   125,   179,  1162,
    1141,   101,  1142,  1058,  1059,  1143,  1144,   467,   863,   126,
     864,   880,  1169,   144,  1066,   735,    26,   787,   148,   146,
     154,   180,   162,   158,   160,   156,  1000,   309,   244,   317,
     413,   352,   303,   313,     8,   181,   506,   182,    68,   183,
      75,   184,   118,   185,   120,  1184,  1185,   507,   132,   186,
     134,   187,   136,   188,   141,   189,   149,   190,   163,   191,
     168,   192,   229,   193,   167,   194,   231,    76,  1242,  1243,
     235,    77,   239,    78,   246,    79,  1186,    80,  1187,   989,
     990,  1188,  1189,   606,   607,     6,     7,   251,   925,   926,
     169,   170,   844,   510,   608,   609,   610,   470,  1234,  1244,
     471,  1245,   511,   245,  1246,  1247,   845,   846,   847,  1235,
     991,   171,   172,   173,   259,   992,   993,   886,   887,   927,
     848,   928,   849,   800,   908,   850,   801,   851,  1029,   945,
     946,   888,   889,   890,   523,   524,   478,   261,   909,   910,
     911,   479,  1030,  1031,  1032,   561,   562,   891,   969,   970,
     892,   871,   893,   912,   913,  1033,   872,   914,  1034,   915,
     947,  1035,   948,  1036,   525,   640,   641,   526,   264,   527,
     840,   701,   702,   841,   268,   563,  1015,  1016,   564,   971,
     565,   972,  1097,  1098,   955,  1276,  1277,   482,   269,   904,
     270,   956,   905,   271,   483,   642,    16,    17,   643,   278,
     644,   703,    22,    23,   704,   276,   705,  1017,    33,  1018,
      29,    30,   298,  1099,   280,  1100,  1278,    34,  1279,    35,
     282,    36,   284,    37,   286,    38,   294,    39,   288,    40,
     296,    41,   290,    42,   292,    43,   304,    44,   616,   617,
     300,   626,   627,    71,    72,    92,    93,    95,    96,   618,
     619,   620,   628,   629,   630,    98,    99,   103,   104,   106,
     107,   109,   110,   112,   113,   115,   116,   138,   139,   150,
     151,   164,   165,   226,   227,   232,   233,   236,   237,   240,
     241,   273,   274,   335,   336,   348,   349,   394,   395,   404,
     405,   444,   445,   455,   456,   305,   474,   475,   514,   515,
     518,   519,   536,   537,   722,   723,   319,   739,   740,   791,
     792,   831,   832,  1238,  1239,  1025,  1026,   322,   325,   324,
     331,   323,   332,   328,   334,   330,   339,   326,   342,   338,
     344,   327,   345,   346,   347,   387,   353,   329,   354,   355,
     398,   356,   357,   380,   358,   333,   359,   401,   360,   361,
     449,   362,   363,   384,   364,   365,   452,   366,   367,   385,
     368,   369,   390,   370,   371,   388,   372,   373,   392,   374,
     375,   391,   376,   377,   442,   378,   383,   386,   389,   393,
     403,   407,   408,   409,   415,   417,   419,   421,   423,   425,
     427,   429,   431,   433,   435,   437,   439,   462,   463,   443,
     454,   458,   459,   539,   461,   464,   465,   469,   473,   477,
     481,   485,   490,   495,   500,   505,   509,   513,   517,   535,
     542,   533,   540,   545,   547,   548,   549,   550,   551,   556,
     543,   557,   558,   572,   571,   573,   574,   576,   575,   577,
     578,   583,   580,   585,   591,   586,   589,   592,   593,   594,
     581,   595,   636,   637,   638,   651,   652,   587,   650,   653,
     657,   659,   660,   662,   664,   669,   665,   672,   671,   683,
     675,   684,   685,   682,   666,   687,   673,   688,   689,   691,
     692,   693,   695,   686,   696,   697,   712,   713,   714,     0,
     770,   986,  1052,   718,   719,   720,   721,   725,   730,   726,
     727,   732,   747,   733,   738,   743,   745,   772,   711,   746,
     773,   774,   778,   751,   785,     0,   779,   780,   782,   784,
     690,   790,   795,   799,   804,   806,   808,   935,   807,   811,
     812,   694,   813,   814,   815,   816,   817,   818,   819,   820,
     821,   822,   752,   826,   827,   753,   828,   830,   835,   839,
       0,   771,   870,   875,   754,   878,   877,   883,   884,   885,
     903,   936,   937,   938,   939,   755,   749,   768,   769,   940,
     941,   943,   944,   963,     0,   954,   959,   964,   965,   966,
     967,   968,   979,   980,   981,     0,   983,   984,   985,   982,
     988,  1014,     0,   987,  1006,  1010,     0,  1054,  1013,  1024,
    1053,  1072,   942,  1076,  1079,  1080,  1081,  1083,  1084,  1092,
       0,  1012,  1085,  1086,  1087,  1088,  1089,  1090,  1091,  1095,
    1096,  1107,  1108,  1109,     0,  1111,  1112,  1094,  1110,  1113,
    1124,  1114,  1115,     0,   962,  1116,  1117,  1118,  1119,  1078,
    1120,  1123,  1125,  1127,  1128,  1129,  1155,  1130,  1131,  1132,
    1133,  1134,  1135,  1136,  1151,  1153,  1152,  1122,  1156,  1157,
    1175,  1179,     0,  1181,  1180,  1201,  1196,  1197,  1198,  1199,
    1200,  1202,  1203,  1204,  1205,  1206,  1223,  1267,  1209,  1210,
    1211,  1213,  1214,  1215,  1216,  1217,  1218,  1219,  1220,  1221,
    1222,  1224,  1225,  1226,  1227,  1232,  1288,  1228,  1269,  1240,
    1233,  1241,  1254,     0,     0,  1258,  1259,  1260,  1261,  1263,
    1264,  1265,  1266,  1268,  1270,  1271,  1272,  1273,  1290,     0,
    1274,  1275,  1284,  1289,     0,  1291,  1292,  1293,  1294,  1295,
    1297,     0,  1298
};

static const yytype_int16 yycheck[] =
{
       4,    81,     5,     6,     5,     4,    80,     5,     6,     5,
       6,     4,    80,     5,     6,     4,     4,     4,     4,     4,
       4,    81,     4,    81,    80,     8,     9,     8,     9,     8,
       9,   104,    53,   104,   104,    10,    66,     8,     9,     8,
       9,    11,   104,     0,    25,    12,   117,    52,   121,   119,
      19,    20,    21,   115,    35,    50,    39,    78,    55,    40,
      39,    13,    41,    46,    47,    44,    45,    97,    39,    90,
      41,   127,   130,    59,   154,   143,    54,   151,    63,    61,
      67,    78,    75,    71,    73,    69,   146,    83,    89,    87,
      93,    95,    91,    85,    48,    92,   102,    94,    56,    96,
      51,    98,    14,   100,    15,     8,     9,   113,    42,   106,
      42,   108,    42,   110,    15,   112,     3,   114,     3,   116,
       8,   118,    15,   120,     7,   122,     3,    78,     8,     9,
       3,    82,     3,    84,     8,    86,    39,    88,    41,     8,
       9,    44,    45,     8,     9,     8,     9,     4,     8,     9,
       8,     9,     8,   102,    19,    20,    21,    99,   130,    39,
     102,    41,   111,     7,    44,    45,    22,    23,    24,   141,
      39,    29,    30,    31,     4,    44,    45,     8,     9,    39,
      36,    41,    38,   130,     8,    41,   133,    43,     8,     8,
       9,    22,    23,    24,     8,     9,   102,     5,    22,    23,
      24,   107,    22,    23,    24,     8,     9,    38,     8,     9,
      41,   130,    43,    37,    38,    35,   135,    41,    38,    43,
      39,    41,    41,    43,    38,     8,     9,    41,   126,    43,
     146,     8,     9,   149,     7,    38,     8,     9,    41,    39,
      43,    41,     8,     9,   130,     8,     9,   102,     7,   154,
       7,   137,   157,    42,   109,    38,     8,     9,    41,    17,
      43,    38,     8,     9,    41,    16,    43,    39,    49,    41,
       8,     9,    26,    39,    17,    41,    39,    58,    41,    60,
      17,    62,    17,    64,    18,    66,    17,    68,    18,    70,
      17,    72,    18,    74,    18,    76,     7,    78,     8,     9,
      15,     8,     9,     8,     9,     8,     9,     8,     9,    19,
      20,    21,    19,    20,    21,     8,     9,     8,     9,     8,
       9,     8,     9,     8,     9,     8,     9,     8,     9,     8,
       9,     8,     9,     8,     9,     8,     9,     8,     9,     8,
       9,     8,     9,    79,    80,     8,     9,    79,    80,     8,
       9,    79,    80,     8,     9,     8,   101,   102,   123,   124,
      79,    80,     8,     9,   159,   160,     5,   129,   130,   145,
     146,   153,   154,     5,     6,   139,   140,    59,     7,    63,
      75,    61,     7,    69,     7,    73,   142,    65,    32,    57,
       5,    67,     5,     5,     3,    85,     7,    71,     8,     7,
     150,     8,     7,     5,     8,    77,     7,    33,     8,     7,
     158,     8,     7,    83,     8,     7,    34,     8,     7,    83,
       8,     7,    87,     8,     7,    85,     8,     7,    89,     8,
       7,    87,     8,     7,    91,     8,     7,     7,     7,     7,
       7,     7,     7,     7,     5,     5,     5,     5,     5,     5,
       5,     5,     5,     5,     5,     5,     5,    93,    93,     7,
       7,     5,   128,     5,     7,    95,     7,     7,     7,     7,
       7,     7,     7,     7,     7,     7,     7,     7,     7,     7,
       7,    27,   144,   132,     8,     8,     8,     8,     8,     8,
      35,     8,     8,     3,    81,     3,     3,     8,     7,     5,
     152,   148,     7,     7,     4,     8,   134,     4,     4,     4,
      36,     4,     4,     4,     4,     3,     3,    35,    81,     3,
       5,     7,    37,   156,     7,     5,     8,     8,     7,     3,
     136,     3,     3,   105,    36,     3,    35,     3,     3,     3,
       3,     3,     3,   105,     3,     3,     3,     3,     3,    -1,
     125,   147,   155,     7,     7,     7,     7,     7,     5,     8,
      37,     7,    35,     8,     7,     5,     7,     3,    81,     8,
       3,     3,     7,    67,     8,    -1,     7,     7,     5,     7,
     105,     7,     5,     7,     5,     7,    28,     3,     8,     7,
       7,   105,     7,     7,     7,     7,     7,     7,     7,     7,
       7,     7,   103,     7,     7,   103,     7,     7,     5,     7,
      -1,    81,     7,     5,   103,     8,     7,     7,     7,     7,
       7,     3,     3,     7,     3,   103,   138,   103,   103,     3,
       3,     7,     3,     3,    -1,     7,     5,     3,     3,     3,
       3,     3,     3,     3,     3,    -1,     3,     3,     3,     7,
       3,     3,    -1,     7,     5,     5,    -1,     3,     7,     7,
       7,     5,   131,     5,     7,     3,     3,     7,     7,     5,
      -1,   131,     7,     7,     7,     7,     7,     7,     7,     7,
       3,     3,     3,     3,    -1,     3,     3,   131,     7,     3,
       3,     7,     7,    -1,   161,     7,     7,     7,     7,   147,
       5,     7,     3,     7,     7,     7,   131,     7,     7,     7,
       7,     7,     7,     5,     7,     5,     7,   155,     7,     3,
       5,     7,    -1,     5,     7,     3,     7,     7,     7,   131,
       7,     3,     3,     7,     7,     5,   155,   131,     7,     7,
       7,     7,     7,     7,     7,     7,     7,     7,     7,     7,
       7,     7,     3,     3,     3,     7,   131,     5,     3,     5,
       7,     5,     5,    -1,    -1,     7,     7,     7,     7,     7,
       7,     7,     7,     7,     3,     3,     7,     7,     3,    -1,
       7,     7,     5,     7,    -1,     7,     7,     7,     7,     5,
       7,    -1,     7
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,    10,   164,   165,    11,     0,     8,     9,    48,   166,
     167,   168,    12,    50,   232,   233,     8,     9,   169,    52,
     272,   273,     8,     9,   234,   170,    54,   297,   298,     8,
       9,   274,   235,    49,    58,    60,    62,    64,    66,    68,
      70,    72,    74,    76,    78,   171,   172,   173,   176,   177,
     180,   181,   184,   185,   190,   191,   194,   195,   198,   199,
     202,   203,   206,   207,   210,   211,   216,   217,    56,   435,
     436,     8,     9,   299,   275,    51,    78,    82,    84,    86,
      88,   236,   237,   238,   242,   243,   247,   248,   252,   253,
     256,   257,     8,     9,   174,     8,     9,   178,     8,     9,
     182,    13,   186,     8,     9,   192,     8,     9,   196,     8,
       9,   200,     8,     9,   204,     8,     9,   208,    14,   212,
      15,   218,   437,   300,    53,    78,    90,   276,   277,   278,
     281,   282,    42,   239,    42,   244,    42,   249,     8,     9,
     254,    15,   258,     4,    59,     4,    61,     4,    63,     3,
       8,     9,   188,     4,    67,     4,    69,     4,    71,     4,
      73,     4,    75,     3,     8,     9,   214,     7,     8,     8,
       9,    29,    30,    31,   438,   439,   440,   441,   442,    55,
      78,    92,    94,    96,    98,   100,   106,   108,   110,   112,
     114,   116,   118,   120,   122,   301,   302,   303,   307,   308,
     311,   312,   317,   318,   323,   324,   329,   330,   335,   336,
     341,   342,   356,   357,   371,   372,   386,   387,   401,   402,
     407,   408,   413,   414,   419,   420,     8,     9,   279,    15,
     283,     3,     8,     9,   241,     3,     8,     9,   246,     3,
       8,     9,   251,     5,    89,     7,     8,   175,   179,   183,
     187,     4,   189,   193,   197,   201,   205,   209,   213,     4,
     215,     5,   219,   220,   126,   443,   444,   445,     7,     7,
       7,    42,   304,     8,     9,   309,    16,   313,    17,   319,
      17,   325,    17,   331,    17,   337,    18,   343,    18,   358,
      18,   373,    18,   388,    17,   403,    17,   409,    26,   415,
      15,   421,     4,    91,     7,     8,   240,     5,     6,    83,
     245,     5,     6,    85,   250,     5,     6,    87,   255,     5,
     259,   260,    59,    61,    63,     7,    65,    67,    69,    71,
      73,    75,     7,    77,     7,    79,    80,   221,    57,   142,
     544,   545,    32,   446,     5,     5,     5,     3,     8,     9,
     306,     4,    95,     7,     8,     7,     8,     7,     8,     7,
       8,     7,     8,     7,     8,     7,     8,     7,     8,     7,
       8,     7,     8,     7,     8,     7,     8,     7,     8,   280,
       5,   284,   285,     7,    83,    83,     7,    85,    85,     7,
      87,    87,    89,     7,    79,    80,   261,   222,   150,   604,
     605,    33,   546,     7,     8,     9,   447,     7,     7,     7,
     305,     5,     6,    93,   310,     5,   314,     5,   320,     5,
     326,     5,   332,     5,   338,     5,   344,     5,   359,     5,
     374,     5,   389,     5,   404,     5,   410,     5,   416,     5,
     422,   423,    91,     7,    79,    80,   286,   262,   223,   158,
     664,   665,    34,   606,     7,     8,     9,   547,     5,   128,
     448,     7,    93,    93,    95,     7,    66,    97,   315,     7,
      99,   102,   321,     7,   101,   102,   327,     7,   102,   107,
     333,     7,   102,   109,   339,     7,   104,   115,   345,   346,
       7,   104,   117,   360,   361,     7,   104,   119,   375,   376,
       7,   104,   121,   390,   391,     7,   102,   113,   405,     7,
     102,   111,   411,     7,   123,   124,   417,     7,    79,    80,
     424,   287,   263,     8,     9,    38,    41,    43,   224,   225,
     227,   229,   231,    27,   666,     7,     8,     9,   607,     5,
     144,   548,     7,    35,   449,   132,   459,     8,     8,     8,
       8,     8,   347,   362,   377,   392,     8,     8,     8,   425,
     288,     8,     9,    38,    41,    43,   264,   265,   267,   269,
     271,    81,     3,     3,     3,     7,     8,     5,   152,   608,
       7,    36,   549,   148,   559,     7,     8,    35,   460,   134,
     470,     4,     4,     4,     4,     4,     8,     9,    19,    20,
      21,   348,   349,   351,   353,   355,     8,     9,    19,    20,
      21,   363,   364,   366,   368,   370,     8,     9,    19,    20,
      21,   378,   379,   381,   383,   385,     8,     9,    19,    20,
      21,   393,   394,   396,   398,   400,     4,     4,     4,   426,
       8,     9,    38,    41,    43,   289,   290,   292,   294,   296,
      81,     3,     3,     3,   226,   228,   230,     5,   667,     7,
      37,   609,   156,   619,     7,     8,    36,   560,   572,     5,
     450,     7,     8,    35,   471,   136,   481,   316,   322,   328,
     334,   340,   105,     3,     3,     3,   105,     3,     3,     3,
     105,     3,     3,     3,   105,     3,     3,     3,   406,   412,
     418,     8,     9,    38,    41,    43,   427,   428,   430,   432,
     434,    81,     3,     3,     3,   266,   268,   270,     7,     7,
       7,     7,   159,   160,   668,     7,     8,    37,   620,   632,
       5,   550,     7,     8,    80,   143,   573,   574,     7,   129,
     130,   451,   452,     5,   461,     7,     8,    35,   482,   138,
     492,    67,   103,   103,   103,   103,   350,   352,   354,   365,
     367,   369,   380,   382,   384,   395,   397,   399,   103,   103,
     125,    81,     3,     3,     3,   291,   293,   295,     7,     7,
       7,   669,     5,   610,     7,     8,    80,   151,   633,   634,
       7,   145,   146,   551,   552,     5,   561,   575,   453,     7,
     130,   133,   462,   463,     5,   472,     7,     8,    28,   493,
     512,     7,     7,     7,     7,     7,     7,     7,     7,     7,
       7,     7,     7,   429,   431,   433,     7,     7,     7,   670,
       7,   153,   154,   611,   612,     5,   621,   635,   553,     7,
     146,   149,   562,   563,     8,    22,    23,    24,    36,    38,
      41,    43,   576,   577,   578,   580,   582,   584,   586,   588,
     590,     8,     9,    39,    41,   454,   455,   456,   458,   464,
       7,   130,   135,   473,   474,     5,   483,     7,     8,    80,
     127,   513,   514,     7,     7,     7,     8,     9,    22,    23,
      24,    38,    41,    43,   671,   672,   674,   676,   678,   680,
     682,   684,   613,     7,   154,   157,   622,   623,     8,    22,
      23,    24,    37,    38,    41,    43,   636,   637,   638,   640,
     642,   644,   646,   648,   650,     8,     9,    39,    41,   554,
     555,   556,   558,   564,   591,     3,     3,     3,     7,     3,
       3,     3,   131,     7,     3,     8,     9,    39,    41,   465,
     466,   467,   469,   475,     7,   130,   137,   484,   485,     5,
     494,   515,   161,     3,     3,     3,     3,     3,     3,     8,
       9,    39,    41,   614,   615,   616,   618,   624,   651,     3,
       3,     3,     7,     3,     3,     3,   147,     7,     3,     8,
       9,    39,    44,    45,   565,   566,   567,   569,   571,    81,
     146,   592,   593,   583,   585,   587,     5,   579,   581,   589,
       5,   457,   131,     7,     3,     8,     9,    39,    41,   476,
     477,   478,   480,   486,     7,   139,   140,   495,   496,     8,
      22,    23,    24,    35,    38,    41,    43,   516,   517,   518,
     520,   522,   524,   526,   528,   530,   677,   679,   681,   673,
     675,   683,   155,     7,     3,     8,     9,    39,    46,    47,
     625,   626,   627,   629,   631,    81,   154,   652,   653,   643,
     645,   647,     5,   639,   641,   649,     5,   557,   147,     7,
       3,     3,   594,     7,     7,     7,     7,     7,     7,     7,
       7,     7,     5,   468,   131,     7,     3,     8,     9,    39,
      41,   487,   488,   489,   491,   497,   531,     3,     3,     3,
       7,     3,     3,     3,     7,     7,     7,     7,     7,     7,
       5,   617,   155,     7,     3,     3,   654,     7,     7,     7,
       7,     7,     7,     7,     7,     7,     5,   568,   570,     8,
       9,    39,    41,    44,    45,   595,   596,   597,   599,   601,
     603,     7,     7,     5,   479,   131,     7,     3,     8,     9,
      25,    35,    40,   498,   499,   500,   501,   502,    81,   130,
     532,   533,   523,   525,   527,     5,   519,   521,   529,     7,
       7,     5,   628,   630,     8,     9,    39,    41,    44,    45,
     655,   656,   657,   659,   661,   663,     7,     7,     7,   131,
       7,     3,     3,     3,     7,     7,     5,   490,   503,     7,
       7,     7,   534,     7,     7,     7,     7,     7,     7,     7,
       7,     7,     7,   155,     7,     3,     3,     3,     5,   598,
     600,   602,     7,     7,   130,   141,   504,   505,     5,     6,
       5,     5,     8,     9,    39,    41,    44,    45,   535,   536,
     537,   539,   541,   543,     5,   658,   660,   662,     7,     7,
       7,     7,   506,     7,     7,     7,     7,   131,     7,     3,
       3,     3,     7,     7,     7,     7,     8,     9,    39,    41,
     507,   508,   509,   511,     5,   538,   540,   542,   131,     7,
       3,     7,     7,     7,     7,     5,   510,     7,     7
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

    {	if (parserData->scheduledStartTimePresent)
	{	osolerror( NULL, osoption, parserData, "only one <scheduledStartTime> element allowed");
	}
	else
	{	parserData->scheduledStartTimePresent = true;
		osoption->job->scheduledStartTime = "1970-01-01T00:00:00-00:00";
	}
;}
    break;

  case 249:

    {osoption->job->scheduledStartTime = (yyvsp[(2) - (2)].sval);;}
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

    {	if ((yyvsp[(3) - (4)].ival) <= 0)
		osolerror (NULL, osoption, parserData, "Require positive number of directories to move");
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
		if ((yyvsp[(2) - (2)].sval) == "true")
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

    {	if ((yyvsp[(3) - (4)].ival) <= 0)
		osolerror (NULL, osoption, parserData, "Require positive number of files to move");
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
		if ((yyvsp[(2) - (2)].sval) == "true")
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

    {	if ((yyvsp[(3) - (4)].ival) <= 0)
		osolerror (NULL, osoption, parserData, "Require positive number of directories to move");
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
		if ((yyvsp[(2) - (2)].sval) == "true")
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

    {	if ((yyvsp[(3) - (4)].ival) <= 0)
		osolerror (NULL, osoption, parserData, "Require positive number of files to move");
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
		if ((yyvsp[(2) - (2)].sval) == "true")
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

    {	if ((yyvsp[(3) - (4)].ival) <= 0)
		osolerror (NULL, osoption, parserData, "number of <var> elements must be positive");
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

    {	if ((yyvsp[(3) - (4)].ival) <= 0)
		osolerror (NULL, osoption, parserData, "number of <var> elements must be positive");
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

  case 461:

    {printf("initial basis empty\n");;}
    break;

  case 463:

    {	if ((yyvsp[(3) - (4)].ival) <= 0)
		osolerror (NULL, osoption, parserData, "number of <var> elements must be positive");
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

    {	if ((yyvsp[(3) - (4)].ival) <= 0)
		osolerror (NULL, osoption, parserData, "number of <var> elements must be positive");
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

    {	if ((yyvsp[(3) - (4)].ival) <= 0)
		osolerror (NULL, osoption, parserData, "number of <sos> elements must be positive");
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
	printf("Increment parserData->numberOfSOS to %d",parserData->numberOfSOS);
;}
    break;

  case 499:

    {	if (parserData->numberOfSOS >= osoption->optimization->variables->sosVariableBranchingWeights->numberOfSOS)
		osolerror(NULL, osoption, parserData, "too many SOS branching weights");
	printf("Reset parserData->numberOfSOSVar (to 0)\n"); parserData->numberOfSOSVar = 0;
;}
    break;

  case 505:

    {	if (parserData->sosIdxAttributePresent)
		osolerror (NULL, osoption, parserData, "only one SOS index allowed");
	parserData->sosIdxAttributePresent = true;
	printf("SOS index found:%d\n",(yyvsp[(3) - (4)].ival));
	if ((yyvsp[(3) - (4)].ival) < 0)
		osolerror (NULL, osoption, parserData, "SOS index must be nonnegative");
	printf("store into %d:%d\n",parserData->numberOfSOS,(yyvsp[(3) - (4)].ival));
	osoption->optimization->variables->sosVariableBranchingWeights->sos[parserData->numberOfSOS]->sosIdx = (yyvsp[(3) - (4)].ival);
	printf(" Check:%d\n",osoption->optimization->variables->sosVariableBranchingWeights->sos[parserData->numberOfSOS]->sosIdx);
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

    {	printf("numberOfSOSVar:%d, numberOfVar in this SOS:%d",parserData->numberOfSOSVar,
		osoption->optimization->variables->sosVariableBranchingWeights->sos[parserData->numberOfSOS]->numberOfVar);
	if (parserData->numberOfSOSVar >= osoption->optimization->variables->sosVariableBranchingWeights->sos[parserData->numberOfSOS]->numberOfVar)
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

    {	if ((yyvsp[(3) - (4)].ival) <= 0)
		osolerror (NULL, osoption, parserData, "number of <obj> elements must be positive");
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

    {	if ((yyvsp[(3) - (4)].ival) <= 0)
		osolerror (NULL, osoption, parserData, "number of <obj> elements must be positive");
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

    {	if ((yyvsp[(3) - (4)].ival) <= 0)
		osolerror (NULL, osoption, parserData, "number of <con> elements must be positive");
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

    {	if ((yyvsp[(3) - (4)].ival) <= 0)
		osolerror (NULL, osoption, parserData, "number of <con> elements must be positive");
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

    {	printf("Found <con>; number %d out of %d\n",parserData->numberOfCon,
		osoption->optimization->constraints->other[parserData->numberOfOtherConstraintOptions]->numberOfCon);
	if (parserData->numberOfCon >= osoption->optimization->constraints->other[parserData->numberOfOtherConstraintOptions]->numberOfCon)
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
	printf("idx = %d\n",(yyvsp[(3) - (4)].ival));
	osoption->optimization->constraints->other[parserData->numberOfOtherConstraintOptions]->con[parserData->numberOfCon]->idx = (yyvsp[(3) - (4)].ival);
;}
    break;

  case 738:

    {	if (parserData->valAttributePresent)
		osolerror (NULL, osoption, parserData, "only one constraint value allowed");
	parserData->valAttributePresent = true;
	printf("Value attribute read\n");
	osoption->optimization->constraints->other[parserData->numberOfOtherConstraintOptions]->con[parserData->numberOfCon]->value = (yyvsp[(2) - (2)].sval);
;}
    break;

  case 740:

    {	if (parserData->lbvalAttributePresent)
		osolerror (NULL, osoption, parserData, "only one lower bound value allowed");
	parserData->lbvalAttributePresent = true;
	printf("lbValue attribute read\n");
	osoption->optimization->constraints->other[parserData->numberOfOtherConstraintOptions]->con[parserData->numberOfCon]->lbValue = (yyvsp[(2) - (2)].sval);
;}
    break;

  case 742:

    {	if (parserData->ubvalAttributePresent)
		osolerror (NULL, osoption, parserData, "only one upper bound value allowed");
	parserData->ubvalAttributePresent = true;
	printf("ubValue attribute read\n");
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


