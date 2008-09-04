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
#define yyparse osilparse
#define yylex   osillex
#define yyerror osilerror
#define yylval  osillval
#define yychar  osilchar
#define yydebug osildebug
#define yynerrs osilnerrs
#define yylloc osillloc

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     QUOTE = 258,
     ATTRIBUTETEXT = 259,
     INTEGER = 260,
     DOUBLE = 261,
     OSILEND = 262,
     INSTANCEDATAEND = 263,
     VALUEATT = 264,
     NUMBEROFNONLINEAREXPRESSIONS = 265,
     IDXONEATT = 266,
     IDXTWOATT = 267,
     COEFATT = 268,
     IDATT = 269,
     TIMESSTART = 270,
     TIMESEND = 271,
     NUMBERSTART = 272,
     NUMBEREND = 273,
     NUMBEROFQTERMSATT = 274,
     IDXATT = 275,
     TYPEATT = 276,
     QTERMSTART = 277,
     QTERMEND = 278,
     QUADRATICCOEFFICIENTSSTART = 279,
     QUADRATICCOEFFICIENTSEND = 280,
     NONLINEAREXPRESSIONSSTART = 281,
     NONLINEAREXPRESSIONSEND = 282,
     NLSTART = 283,
     NLEND = 284,
     POWERSTART = 285,
     POWEREND = 286,
     PLUSSTART = 287,
     PLUSEND = 288,
     MINUSSTART = 289,
     MINUSEND = 290,
     DIVIDESTART = 291,
     DIVIDEEND = 292,
     LNSTART = 293,
     LNEND = 294,
     SQRTSTART = 295,
     SQRTEND = 296,
     SUMSTART = 297,
     SUMEND = 298,
     PRODUCTSTART = 299,
     PRODUCTEND = 300,
     ENDOFELEMENT = 301,
     EXPSTART = 302,
     EXPEND = 303,
     NEGATESTART = 304,
     NEGATEEND = 305,
     IFSTART = 306,
     IFEND = 307,
     SQUARESTART = 308,
     SQUAREEND = 309,
     COSSTART = 310,
     COSEND = 311,
     SINSTART = 312,
     SINEND = 313,
     GREATERTHAN = 314,
     VARIABLESTART = 315,
     VARIABLEEND = 316,
     ABSSTART = 317,
     ABSEND = 318,
     MAXSTART = 319,
     MAXEND = 320,
     ALLDIFFSTART = 321,
     ALLDIFFEND = 322,
     MINSTART = 323,
     MINEND = 324,
     ESTART = 325,
     EEND = 326,
     PISTART = 327,
     PIEND = 328,
     TIMEDOMAINSTART = 329,
     TIMEDOMAINEND = 330,
     STAGESSTART = 331,
     STAGESEND = 332,
     STAGESTART = 333,
     STAGEEND = 334,
     NAMEATT = 335,
     MULTATT = 336,
     NUMBEROFSTAGESATT = 337,
     HORIZONATT = 338,
     STARTATT = 339,
     VARIABLESSTART = 340,
     CONSTRAINTSSTART = 341,
     OBJECTIVESSTART = 342,
     VARIABLESEND = 343,
     CONSTRAINTSEND = 344,
     OBJECTIVESEND = 345,
     NUMBEROFVARIABLESATT = 346,
     NUMBEROFCONSTRAINTSATT = 347,
     NUMBEROFOBJECTIVESATT = 348,
     STARTIDXATT = 349,
     ENDIDXATT = 350,
     VARSTART = 351,
     VAREND = 352,
     CONSTART = 353,
     CONEND = 354,
     OBJSTART = 355,
     OBJEND = 356,
     INTERVALSTART = 357,
     INTERVALEND = 358,
     PARAMETERSSTART = 359,
     PARAMETERSEND = 360,
     PARAMSTART = 361,
     PARAMEND = 362,
     NUMBEROFPARAMETERSATT = 363
   };
#endif
/* Tokens.  */
#define QUOTE 258
#define ATTRIBUTETEXT 259
#define INTEGER 260
#define DOUBLE 261
#define OSILEND 262
#define INSTANCEDATAEND 263
#define VALUEATT 264
#define NUMBEROFNONLINEAREXPRESSIONS 265
#define IDXONEATT 266
#define IDXTWOATT 267
#define COEFATT 268
#define IDATT 269
#define TIMESSTART 270
#define TIMESEND 271
#define NUMBERSTART 272
#define NUMBEREND 273
#define NUMBEROFQTERMSATT 274
#define IDXATT 275
#define TYPEATT 276
#define QTERMSTART 277
#define QTERMEND 278
#define QUADRATICCOEFFICIENTSSTART 279
#define QUADRATICCOEFFICIENTSEND 280
#define NONLINEAREXPRESSIONSSTART 281
#define NONLINEAREXPRESSIONSEND 282
#define NLSTART 283
#define NLEND 284
#define POWERSTART 285
#define POWEREND 286
#define PLUSSTART 287
#define PLUSEND 288
#define MINUSSTART 289
#define MINUSEND 290
#define DIVIDESTART 291
#define DIVIDEEND 292
#define LNSTART 293
#define LNEND 294
#define SQRTSTART 295
#define SQRTEND 296
#define SUMSTART 297
#define SUMEND 298
#define PRODUCTSTART 299
#define PRODUCTEND 300
#define ENDOFELEMENT 301
#define EXPSTART 302
#define EXPEND 303
#define NEGATESTART 304
#define NEGATEEND 305
#define IFSTART 306
#define IFEND 307
#define SQUARESTART 308
#define SQUAREEND 309
#define COSSTART 310
#define COSEND 311
#define SINSTART 312
#define SINEND 313
#define GREATERTHAN 314
#define VARIABLESTART 315
#define VARIABLEEND 316
#define ABSSTART 317
#define ABSEND 318
#define MAXSTART 319
#define MAXEND 320
#define ALLDIFFSTART 321
#define ALLDIFFEND 322
#define MINSTART 323
#define MINEND 324
#define ESTART 325
#define EEND 326
#define PISTART 327
#define PIEND 328
#define TIMEDOMAINSTART 329
#define TIMEDOMAINEND 330
#define STAGESSTART 331
#define STAGESEND 332
#define STAGESTART 333
#define STAGEEND 334
#define NAMEATT 335
#define MULTATT 336
#define NUMBEROFSTAGESATT 337
#define HORIZONATT 338
#define STARTATT 339
#define VARIABLESSTART 340
#define CONSTRAINTSSTART 341
#define OBJECTIVESSTART 342
#define VARIABLESEND 343
#define CONSTRAINTSEND 344
#define OBJECTIVESEND 345
#define NUMBEROFVARIABLESATT 346
#define NUMBEROFCONSTRAINTSATT 347
#define NUMBEROFOBJECTIVESATT 348
#define STARTIDXATT 349
#define ENDIDXATT 350
#define VARSTART 351
#define VAREND 352
#define CONSTART 353
#define CONEND 354
#define OBJSTART 355
#define OBJEND 356
#define INTERVALSTART 357
#define INTERVALEND 358
#define PARAMETERSSTART 359
#define PARAMETERSEND 360
#define PARAMSTART 361
#define PARAMEND 362
#define NUMBEROFPARAMETERSATT 363




/* Copy the first part of user declarations.  */



#include <string>
#include <iostream>
#include <sstream>  
 
#include "OSInstance.h" 
#include "OSnLNode.h"
#include "OSErrorClass.h"
#include "OSParameters.h"
#include "OSiLParserData.h"
#include "OSBase64.h"
#include "OSMathUtil.h"

#include "OSConfig.h"



#ifdef HAVE_CTIME
# include <ctime>
#else
# ifdef HAVE_TIME_H
#  include <time.h>
# else
#  error "don't have header file for time"
# endif
#endif

#ifdef HAVE_CSTRING
# include <cstring>
#else
# ifdef HAVE_STRING_H
#  include <string.h>
# else
#  error "don't have header file for string"
# endif
#endif

#ifdef HAVE_CSTDIO
# include <cstdio>
#else
# ifdef HAVE_STDIO_H
#  include <stdio.h>
# else
#  error "don't have header file for stdio"
# endif
#endif

using std::cout;
using std::endl;
using std::ostringstream;


typedef struct yy_buffer_state *YY_BUFFER_STATE;
YY_BUFFER_STATE osil_scan_string (const char *yy_str , void* yyscanner  );
int osillex_init(void** ptr_yy_globals);
int osillex_destroy (void* yyscanner );
void osilset_extra (OSiLParserData* parserData , void* yyscanner );
int osilget_lineno( void* yyscanner);
char *osilget_text (void* yyscanner );
void osilset_lineno (int line_number , void* yyscanner );
void yygetOSInstance(const char *osil, OSInstance* osinstance, OSiLParserData *parserData) throw(ErrorClass);
//

double atofmod1(int* osillineno, const char *ch1, const char *ch2 );
int atoimod1(int* osillineno, const char *ch1, const char *ch2);
// we distinguish a newline from other whitespace
// since we need to know when we hit a new line
void osilerror_wrapper( const char* ch, int* osillineno, const char* errormsg);
bool isnewline(char c, int* osillineno);
bool parseVariables(const char **pchar, OSInstance *osinstance ,int* osillineno);
bool parseObjectives(const char **pchar, OSInstance *osinstance ,int* osillineno);
bool parseObjCoef(const char **pchar, int objcount, OSInstance *osinstance ,int* osillineno);
bool parseConstraints(const char **pchar, OSInstance *osinstance ,int* osillineno);
bool parseLinearConstraintCoefficients(const char **pchar, OSInstance *osinstance ,int* osillineno);
bool parseStart(const char **pchar, OSInstance *osinstance ,int* osillineno);
bool parseRowIdx(const char **pchar, OSInstance *osinstance ,int* osillineno);
bool parseColIdx(const char **pchar, OSInstance *osinstance ,int* osillineno);
bool parseValue(const char **pchar, OSInstance *osinstance ,int* osillineno);
bool parseInstanceHeader(const char **pchar, OSInstance *osinstance ,int* osillineno);
bool parseInstanceData( const char **pchar, OSInstance *osinstance, int* osillineno);
char *parseBase64( const char **p, int *dataSize ,int* osillineno);

#define	ISWHITESPACE( char_) ((char_) == ' ' || \
                     (char_) == '\t' ||  (char_) == '\r')

#define	ISDIGIT(_c) ((_c) >= '0' && (_c) <= '9')

#define GETATTRIBUTETEXT  	\
	for(; ISWHITESPACE( *ch) || isnewline( *ch, osillineno); ch++ ) ; \
	if( *ch != '=') {  osilerror_wrapper( ch, osillineno, "found an attribute not defined"); return false;}  \
	ch++; \
	for(; ISWHITESPACE( *ch) || isnewline( *ch, osillineno); ch++ ) ;	\
	if(*ch == '\"'){ \
		ch++; \
	    for(; ISWHITESPACE( *ch) || isnewline( *ch, osillineno); ch++ ) ; \
	    *p = ch; \
	    for( ; *ch != '\"'; ch++); \
	}\
	else{\
	    if(*ch == '\'') { \
	    	ch++; \
	        for(; ISWHITESPACE( *ch) || isnewline( *ch, osillineno); ch++ ) ; \
	        *p = ch; \
	        for( ; *ch != '\''; ch++); \
	    } \
	    else {  osilerror_wrapper( ch, osillineno,"missing quote on attribute"); return false;} \
	}\
	numChar = ch - *p; \
	attText = new char[numChar + 1]; \
	for(ki = 0; ki < numChar; ki++) attText[ki] = *((*p)++); \
	attText[ki] = '\0'; \
	attTextEnd = &attText[ki]; 
	
#define GAIL printf("GAIL ANN HONDA\n")


	
#define ECHOCHECK \
	GAIL; \
	printf("%c", ch[-2]); \
	printf("%c", ch[-1]); \
	printf("%c", ch[0]); \
	printf("%c", ch[1]); \
	printf("%c", ch[2]); \
	printf("%c", ch[3]); \
	printf("%c", ch[4]); \
	printf("%c", ch[5]); \
	printf("%c \n", ch[6]); \
	GAIL;


/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
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


int osillex(YYSTYPE* lvalp,  YYLTYPE* llocp, void* scanner );
void osilerror(YYLTYPE* type, OSInstance *osintance,  OSiLParserData *parserData ,const char* errormsg );

 
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
#define YYLAST   393

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  109
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  144
/* YYNRULES -- Number of rules.  */
#define YYNRULES  225
/* YYNRULES -- Number of states.  */
#define YYNSTATES  399

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   363

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
     105,   106,   107,   108
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,    10,    11,    12,    17,    23,    25,    28,
      29,    34,    36,    39,    40,    43,    45,    47,    49,    51,
      56,    61,    66,    71,    76,    77,    82,    88,    89,    90,
      98,   103,   105,   107,   109,   111,   113,   115,   117,   119,
     121,   123,   125,   127,   129,   131,   133,   135,   137,   139,
     141,   143,   145,   147,   149,   150,   156,   157,   163,   164,
     170,   171,   176,   177,   183,   184,   190,   191,   196,   198,
     201,   202,   207,   209,   212,   213,   218,   220,   223,   224,
     229,   231,   234,   235,   240,   242,   245,   246,   251,   252,
     257,   258,   263,   264,   269,   270,   275,   276,   281,   282,
     287,   288,   295,   296,   300,   302,   305,   306,   310,   312,
     315,   316,   321,   323,   326,   327,   330,   332,   334,   336,
     337,   342,   343,   348,   353,   358,   359,   364,   366,   367,
     372,   375,   376,   379,   381,   383,   388,   393,   398,   399,
     402,   404,   405,   407,   411,   415,   417,   420,   425,   427,
     433,   435,   438,   439,   444,   445,   449,   451,   455,   459,
     460,   464,   465,   468,   470,   472,   477,   482,   484,   488,
     490,   493,   495,   498,   499,   504,   509,   511,   514,   515,
     519,   520,   523,   525,   527,   532,   537,   539,   543,   545,
     548,   550,   553,   554,   559,   564,   566,   569,   570,   574,
     575,   578,   580,   582,   587,   592,   594,   598,   600,   603,
     605,   608,   609,   614,   619,   621,   624,   625,   630,   632,
     635,   636,   639,   641,   643,   648
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     110,     0,    -1,   112,   124,   197,   111,     8,     7,    -1,
      -1,    -1,    24,   113,   114,    25,    -1,    19,     3,     5,
       3,    59,    -1,   115,    -1,   114,   115,    -1,    -1,   116,
      22,   118,   117,    -1,    46,    -1,    59,    23,    -1,    -1,
     118,   119,    -1,   120,    -1,   121,    -1,   122,    -1,   123,
      -1,    11,     3,     5,     3,    -1,    12,     3,     5,     3,
      -1,    13,     3,     6,     3,    -1,    13,     3,     5,     3,
      -1,    20,     3,     5,     3,    -1,    -1,    26,   125,   126,
      27,    -1,    10,     3,     5,     3,    59,    -1,    -1,    -1,
     126,    28,   128,    59,   129,   127,    29,    -1,    20,     3,
       5,     3,    -1,   179,    -1,   189,    -1,   130,    -1,   132,
      -1,   142,    -1,   134,    -1,   136,    -1,   138,    -1,   140,
      -1,   154,    -1,   157,    -1,   159,    -1,   161,    -1,   165,
      -1,   163,    -1,   167,    -1,   171,    -1,   169,    -1,   148,
      -1,   151,    -1,   173,    -1,   176,    -1,   145,    -1,    -1,
      15,   131,   129,   129,    16,    -1,    -1,    32,   133,   129,
     129,    33,    -1,    -1,    34,   135,   129,   129,    35,    -1,
      -1,    49,   137,   129,    50,    -1,    -1,    36,   139,   129,
     129,    37,    -1,    -1,    30,   141,   129,   129,    31,    -1,
      -1,    42,   143,   144,    43,    -1,   129,    -1,   144,   129,
      -1,    -1,    66,   146,   147,    67,    -1,   129,    -1,   147,
     129,    -1,    -1,    64,   149,   150,    65,    -1,   129,    -1,
     150,   129,    -1,    -1,    68,   152,   153,    69,    -1,   129,
      -1,   153,   129,    -1,    -1,    44,   155,   156,    45,    -1,
     129,    -1,   156,   129,    -1,    -1,    38,   158,   129,    39,
      -1,    -1,    40,   160,   129,    41,    -1,    -1,    53,   162,
     129,    54,    -1,    -1,    55,   164,   129,    56,    -1,    -1,
      57,   166,   129,    58,    -1,    -1,    47,   168,   129,    48,
      -1,    -1,    62,   170,   129,    63,    -1,    -1,    51,   172,
     129,   129,   129,    52,    -1,    -1,    70,   174,   175,    -1,
      46,    -1,    59,    71,    -1,    -1,    72,   177,   178,    -1,
      46,    -1,    59,    73,    -1,    -1,    17,   180,   182,   181,
      -1,    46,    -1,    59,    18,    -1,    -1,   182,   183,    -1,
     184,    -1,   188,    -1,   186,    -1,    -1,    21,     4,   185,
       3,    -1,    -1,    14,     4,   187,     3,    -1,     9,     3,
       6,     3,    -1,     9,     3,     5,     3,    -1,    -1,    60,
     190,   193,   191,    -1,    46,    -1,    -1,    59,   129,   192,
      61,    -1,    59,    61,    -1,    -1,   193,   194,    -1,   195,
      -1,   196,    -1,    13,     3,     6,     3,    -1,    13,     3,
       5,     3,    -1,    20,     3,     5,     3,    -1,    -1,   198,
     199,    -1,    74,    -1,    -1,   200,    -1,    59,   201,    75,
      -1,    59,   246,    75,    -1,    46,    -1,    59,    75,    -1,
     202,   203,   204,    77,    -1,    76,    -1,    82,     3,     5,
       3,    59,    -1,   205,    -1,   204,   205,    -1,    -1,   206,
      78,   207,   208,    -1,    -1,    80,     4,     3,    -1,    46,
      -1,    59,   209,    79,    -1,   210,   222,   234,    -1,    -1,
      85,   211,   215,    -1,    -1,   211,   212,    -1,   213,    -1,
     214,    -1,    91,     3,     5,     3,    -1,    94,     3,     5,
       3,    -1,   216,    -1,    59,   217,    88,    -1,    46,    -1,
      59,    88,    -1,   218,    -1,   217,   218,    -1,    -1,   219,
      96,   220,   221,    -1,    20,     3,     5,     3,    -1,    46,
      -1,    59,    97,    -1,    -1,    86,   223,   227,    -1,    -1,
     223,   224,    -1,   225,    -1,   226,    -1,    92,     3,     5,
       3,    -1,    94,     3,     5,     3,    -1,   228,    -1,    59,
     229,    89,    -1,    46,    -1,    59,    89,    -1,   230,    -1,
     229,   230,    -1,    -1,   231,    98,   232,   233,    -1,    20,
       3,     5,     3,    -1,    46,    -1,    59,    99,    -1,    -1,
      87,   235,   239,    -1,    -1,   235,   236,    -1,   237,    -1,
     238,    -1,    93,     3,     5,     3,    -1,    94,     3,     5,
       3,    -1,   240,    -1,    59,   241,    90,    -1,    46,    -1,
      59,    90,    -1,   242,    -1,   241,   242,    -1,    -1,   243,
     100,   244,   245,    -1,    20,     3,     5,     3,    -1,    46,
      -1,    59,   101,    -1,    -1,   247,   102,   249,   248,    -1,
      46,    -1,    59,   103,    -1,    -1,   249,   250,    -1,   251,
      -1,   252,    -1,    83,     3,     6,     3,    -1,    84,     3,
       6,     3,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   226,   226,   229,   232,   233,   238,   245,   246,   248,
     248,   260,   261,   264,   265,   269,   272,   275,   278,   284,
     291,   298,   300,   304,   307,   308,   312,   318,   320,   319,
     327,   342,   343,   344,   345,   346,   347,   348,   349,   350,
     351,   352,   353,   354,   355,   356,   357,   358,   359,   360,
     361,   362,   363,   364,   367,   367,   372,   372,   377,   377,
     382,   382,   387,   387,   392,   392,   397,   397,   407,   408,
     413,   413,   424,   425,   428,   428,   439,   440,   442,   442,
     453,   454,   457,   457,   467,   468,   471,   471,   476,   476,
     481,   481,   486,   486,   491,   491,   498,   498,   503,   503,
     511,   511,   518,   518,   521,   522,   524,   524,   527,   528,
     530,   530,   535,   536,   538,   539,   541,   543,   545,   549,
     549,   553,   553,   557,   560,   564,   564,   569,   570,   570,
     574,   576,   577,   579,   581,   585,   588,   592,   600,   600,
     602,   604,   605,   606,   607,   609,   610,   612,   663,   665,
     679,   680,   682,   682,   706,   707,   710,   711,   713,   715,
     716,   720,   721,   723,   724,   726,   742,   750,   757,   762,
     763,   765,   766,   768,   768,   771,   780,   781,   783,   784,
     788,   789,   791,   792,   794,   810,   818,   825,   830,   831,
     833,   834,   836,   836,   839,   848,   849,   851,   861,   865,
     866,   868,   869,   871,   887,   895,   902,   907,   908,   910,
     911,   913,   913,   916,   925,   926,   931,   931,   939,   940,
     942,   943,   945,   949,   954,   958
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "QUOTE", "ATTRIBUTETEXT", "INTEGER",
  "DOUBLE", "OSILEND", "INSTANCEDATAEND", "VALUEATT",
  "NUMBEROFNONLINEAREXPRESSIONS", "IDXONEATT", "IDXTWOATT", "COEFATT",
  "IDATT", "TIMESSTART", "TIMESEND", "NUMBERSTART", "NUMBEREND",
  "NUMBEROFQTERMSATT", "IDXATT", "TYPEATT", "QTERMSTART", "QTERMEND",
  "QUADRATICCOEFFICIENTSSTART", "QUADRATICCOEFFICIENTSEND",
  "NONLINEAREXPRESSIONSSTART", "NONLINEAREXPRESSIONSEND", "NLSTART",
  "NLEND", "POWERSTART", "POWEREND", "PLUSSTART", "PLUSEND", "MINUSSTART",
  "MINUSEND", "DIVIDESTART", "DIVIDEEND", "LNSTART", "LNEND", "SQRTSTART",
  "SQRTEND", "SUMSTART", "SUMEND", "PRODUCTSTART", "PRODUCTEND",
  "ENDOFELEMENT", "EXPSTART", "EXPEND", "NEGATESTART", "NEGATEEND",
  "IFSTART", "IFEND", "SQUARESTART", "SQUAREEND", "COSSTART", "COSEND",
  "SINSTART", "SINEND", "GREATERTHAN", "VARIABLESTART", "VARIABLEEND",
  "ABSSTART", "ABSEND", "MAXSTART", "MAXEND", "ALLDIFFSTART", "ALLDIFFEND",
  "MINSTART", "MINEND", "ESTART", "EEND", "PISTART", "PIEND",
  "TIMEDOMAINSTART", "TIMEDOMAINEND", "STAGESSTART", "STAGESEND",
  "STAGESTART", "STAGEEND", "NAMEATT", "MULTATT", "NUMBEROFSTAGESATT",
  "HORIZONATT", "STARTATT", "VARIABLESSTART", "CONSTRAINTSSTART",
  "OBJECTIVESSTART", "VARIABLESEND", "CONSTRAINTSEND", "OBJECTIVESEND",
  "NUMBEROFVARIABLESATT", "NUMBEROFCONSTRAINTSATT",
  "NUMBEROFOBJECTIVESATT", "STARTIDXATT", "ENDIDXATT", "VARSTART",
  "VAREND", "CONSTART", "CONEND", "OBJSTART", "OBJEND", "INTERVALSTART",
  "INTERVALEND", "PARAMETERSSTART", "PARAMETERSEND", "PARAMSTART",
  "PARAMEND", "NUMBEROFPARAMETERSATT", "$accept", "osildoc",
  "parametersAndStochasticElements", "quadraticcoefficients",
  "quadnumberatt", "qTermlist", "qterm", "@1", "qtermend",
  "anotherqTermATT", "qtermatt", "qtermidxOneatt", "qtermidxTwoatt",
  "qtermcoefatt", "qtermidxatt", "nonlinearExpressions", "nlnumberatt",
  "nlnodes", "@2", "nlIdxATT", "nlnode", "times", "@3", "plus", "@4",
  "minus", "@5", "negate", "@6", "divide", "@7", "power", "@8", "sum",
  "@9", "anothersumnlnode", "allDiff", "@10", "anotherallDiffnlnode",
  "max", "@11", "anothermaxnlnode", "min", "@12", "anotherminnlnode",
  "product", "@13", "anotherproductnlnode", "ln", "@14", "sqrt", "@15",
  "square", "@16", "cos", "@17", "sin", "@18", "exp", "@19", "abs", "@20",
  "if", "@21", "E", "@22", "eend", "PI", "@23", "piend", "number", "@24",
  "numberend", "anotherNumberATT", "numberATT", "numbertypeATT", "@25",
  "numberidATT", "@26", "numbervalueATT", "variable", "@27", "variableend",
  "@28", "anotherVariableATT", "variableATT", "variablecoefATT",
  "variableidxATT", "timeDomain", "timedomainstart", "timedomain",
  "timedomainend", "stages", "stagesstart", "numberofstagesatt",
  "stagelist", "stage", "@29", "stagenameATT", "stageend", "stagecontent",
  "stagevariables", "anotherstagevarATT", "stagevaratt",
  "numberofstagevariablesatt", "stagevarstartidxATT",
  "restofstagevariables", "emptyvarlist", "stagevarlist", "stagevar",
  "@30", "stagevaridxATT", "stagevarend", "stageconstraints",
  "anotherstageconATT", "stageconatt", "numberofstageconstraintsatt",
  "stageconstartidxATT", "restofstageconstraints", "emptyconlist",
  "stageconlist", "stagecon", "@31", "stageconidxATT", "stageconend",
  "stageobjectives", "anotherstageobjATT", "stageobjatt",
  "numberofstageobjectivesatt", "stageobjstartidxATT",
  "restofstageobjectives", "emptyobjlist", "stageobjlist", "stageobj",
  "@32", "stageobjidxATT", "stageobjend", "interval", "@33", "intervalend",
  "anotherIntervalATT", "intervalatt", "intervalhorizonatt",
  "intervalstartatt", 0
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
     355,   356,   357,   358,   359,   360,   361,   362,   363
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,   109,   110,   111,   112,   112,   113,   114,   114,   116,
     115,   117,   117,   118,   118,   119,   119,   119,   119,   120,
     121,   122,   122,   123,   124,   124,   125,   126,   127,   126,
     128,   129,   129,   129,   129,   129,   129,   129,   129,   129,
     129,   129,   129,   129,   129,   129,   129,   129,   129,   129,
     129,   129,   129,   129,   131,   130,   133,   132,   135,   134,
     137,   136,   139,   138,   141,   140,   143,   142,   144,   144,
     146,   145,   147,   147,   149,   148,   150,   150,   152,   151,
     153,   153,   155,   154,   156,   156,   158,   157,   160,   159,
     162,   161,   164,   163,   166,   165,   168,   167,   170,   169,
     172,   171,   174,   173,   175,   175,   177,   176,   178,   178,
     180,   179,   181,   181,   182,   182,   183,   183,   183,   185,
     184,   187,   186,   188,   188,   190,   189,   191,   192,   191,
     191,   193,   193,   194,   194,   195,   195,   196,   197,   197,
     198,   199,   199,   199,   199,   200,   200,   201,   202,   203,
     204,   204,   206,   205,   207,   207,   208,   208,   209,   210,
     210,   211,   211,   212,   212,   213,   214,   215,   215,   216,
     216,   217,   217,   219,   218,   220,   221,   221,   222,   222,
     223,   223,   224,   224,   225,   226,   227,   227,   228,   228,
     229,   229,   231,   230,   232,   233,   233,   234,   234,   235,
     235,   236,   236,   237,   238,   239,   239,   240,   240,   241,
     241,   243,   242,   244,   245,   245,   247,   246,   248,   248,
     249,   249,   250,   250,   251,   252
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     6,     0,     0,     4,     5,     1,     2,     0,
       4,     1,     2,     0,     2,     1,     1,     1,     1,     4,
       4,     4,     4,     4,     0,     4,     5,     0,     0,     7,
       4,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     0,     5,     0,     5,     0,     5,
       0,     4,     0,     5,     0,     5,     0,     4,     1,     2,
       0,     4,     1,     2,     0,     4,     1,     2,     0,     4,
       1,     2,     0,     4,     1,     2,     0,     4,     0,     4,
       0,     4,     0,     4,     0,     4,     0,     4,     0,     4,
       0,     6,     0,     3,     1,     2,     0,     3,     1,     2,
       0,     4,     1,     2,     0,     2,     1,     1,     1,     0,
       4,     0,     4,     4,     4,     0,     4,     1,     0,     4,
       2,     0,     2,     1,     1,     4,     4,     4,     0,     2,
       1,     0,     1,     3,     3,     1,     2,     4,     1,     5,
       1,     2,     0,     4,     0,     3,     1,     3,     3,     0,
       3,     0,     2,     1,     1,     4,     4,     1,     3,     1,
       2,     1,     2,     0,     4,     4,     1,     2,     0,     3,
       0,     2,     1,     1,     4,     4,     1,     3,     1,     2,
       1,     2,     0,     4,     4,     1,     2,     0,     3,     0,
       2,     1,     1,     4,     4,     1,     3,     1,     2,     1,
       2,     0,     4,     4,     1,     2,     0,     4,     1,     2,
       0,     2,     1,     1,     4,     4
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       4,     0,     0,    24,     0,     9,     1,     0,   138,     0,
       9,     7,     0,     0,    27,   140,     3,   141,     0,     5,
       8,    13,     0,     0,     0,   145,   216,   139,   142,     0,
       0,     0,    25,     0,     0,   146,   148,     0,     0,     0,
       0,     6,     0,     0,     0,     0,    11,     0,    10,    14,
      15,    16,    17,    18,     0,     0,     0,     2,   143,     0,
     152,   144,   220,     0,     0,     0,     0,    12,    26,     0,
       0,     0,   152,   150,     0,     0,     0,     0,     0,     0,
       0,     0,    54,   110,    64,    56,    58,    62,    86,    88,
      66,    82,    96,    60,   100,    90,    92,    94,   125,    98,
      74,    70,    78,   102,   106,    28,    33,    34,    36,    37,
      38,    39,    35,    53,    49,    50,    40,    41,    42,    43,
      45,    44,    46,    48,    47,    51,    52,    31,    32,     0,
     147,   151,   154,   218,     0,     0,     0,   217,   221,   222,
     223,    19,    20,    22,    21,    23,    30,     0,   114,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   131,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   219,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    68,     0,    84,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    76,     0,    72,
       0,    80,     0,   104,     0,   103,   108,     0,   107,    29,
     149,     0,   156,   159,   153,     0,     0,     0,     0,     0,
       0,   112,     0,   111,   115,   116,   118,   117,     0,     0,
       0,     0,    87,    89,    67,    69,    83,    85,    97,    61,
       0,    91,    93,    95,     0,     0,   127,     0,   126,   132,
     133,   134,    99,    75,    77,    71,    73,    79,    81,   105,
     109,   155,   161,     0,   178,   224,   225,    55,     0,   121,
     119,   113,    65,    57,    59,    63,     0,     0,     0,   130,
     128,     0,   157,   180,   197,     0,     0,     0,     0,   101,
       0,     0,     0,     0,   169,   173,     0,     0,   162,   163,
     164,   160,   167,     0,   199,   158,   124,   123,   122,   120,
     136,   135,   137,   129,   170,   173,   171,     0,     0,     0,
     188,   192,     0,     0,   181,   182,   183,   179,   186,     0,
     168,   172,     0,     0,     0,   189,   192,   190,     0,     0,
       0,   207,   211,     0,     0,   200,   201,   202,   198,   205,
       0,     0,   165,   166,   187,   191,     0,     0,     0,   208,
     211,   209,     0,     0,     0,     0,   176,     0,   174,     0,
       0,   184,   185,   206,   210,     0,     0,     0,     0,   177,
       0,   195,     0,   193,     0,     0,   203,   204,   175,     0,
     196,     0,   214,     0,   212,   194,     0,   215,   213
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,    24,     3,     5,    10,    11,    12,    48,    30,
      49,    50,    51,    52,    53,     8,    14,    23,   170,    56,
     105,   106,   147,   107,   150,   108,   151,   109,   158,   110,
     152,   111,   149,   112,   155,   186,   113,   166,   200,   114,
     165,   198,   115,   167,   202,   116,   156,   188,   117,   153,
     118,   154,   119,   160,   120,   161,   121,   162,   122,   157,
     123,   164,   124,   159,   125,   168,   205,   126,   169,   208,
     127,   148,   223,   178,   224,   225,   288,   226,   287,   227,
     128,   163,   248,   293,   195,   249,   250,   251,    16,    17,
      27,    28,    37,    38,    60,    72,    73,    74,   173,   214,
     263,   264,   281,   298,   299,   300,   301,   302,   315,   316,
     317,   351,   368,   284,   303,   324,   325,   326,   327,   328,
     336,   337,   338,   370,   383,   305,   329,   345,   346,   347,
     348,   349,   360,   361,   362,   385,   394,    39,    40,   137,
      75,   138,   139,   140
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -148
static const yytype_int16 yypact[] =
{
     -23,     7,    28,     5,    34,  -148,  -148,    32,   -26,    49,
      39,  -148,    44,    65,  -148,  -148,  -148,   -21,    95,  -148,
    -148,  -148,   110,    -6,   114,  -148,    73,  -148,  -148,    69,
     315,   121,  -148,   126,   144,  -148,  -148,    78,    77,    89,
      64,  -148,   174,   176,   178,   185,  -148,   160,  -148,  -148,
    -148,  -148,  -148,  -148,   131,   189,   142,  -148,  -148,   200,
    -148,  -148,  -148,   209,   211,   156,   213,  -148,  -148,   215,
     253,   217,   128,  -148,   146,    -3,   222,   224,   226,   228,
     230,   235,  -148,  -148,  -148,  -148,  -148,  -148,  -148,  -148,
    -148,  -148,  -148,  -148,  -148,  -148,  -148,  -148,  -148,  -148,
    -148,  -148,  -148,  -148,  -148,  -148,  -148,  -148,  -148,  -148,
    -148,  -148,  -148,  -148,  -148,  -148,  -148,  -148,  -148,  -148,
    -148,  -148,  -148,  -148,  -148,  -148,  -148,  -148,  -148,   237,
    -148,  -148,   162,  -148,   141,   243,   250,  -148,  -148,  -148,
    -148,  -148,  -148,  -148,  -148,  -148,  -148,   253,  -148,   253,
     253,   253,   253,   253,   253,   253,   253,   253,   253,   253,
     253,   253,   253,  -148,   253,   253,   253,   253,   -19,    -1,
     232,   196,   255,     1,  -148,   251,   257,   253,    15,   253,
     253,   253,   253,   227,   231,  -148,    35,  -148,    72,   246,
     229,   253,   242,   218,   207,     3,   236,  -148,   103,  -148,
     140,  -148,   179,  -148,   205,  -148,  -148,   225,  -148,  -148,
    -148,   275,  -148,   216,  -148,   300,   302,   291,   306,   307,
     308,  -148,   296,  -148,  -148,  -148,  -148,  -148,   285,   287,
     283,   292,  -148,  -148,  -148,  -148,  -148,  -148,  -148,  -148,
     253,  -148,  -148,  -148,   319,   321,  -148,   220,  -148,  -148,
    -148,  -148,  -148,  -148,  -148,  -148,  -148,  -148,  -148,  -148,
    -148,  -148,  -148,   252,   244,  -148,  -148,  -148,   180,  -148,
    -148,  -148,  -148,  -148,  -148,  -148,   280,   193,   328,  -148,
    -148,     0,  -148,  -148,   247,   333,   334,   335,   336,  -148,
     337,   338,   339,   282,  -148,   256,   342,   343,  -148,  -148,
    -148,  -148,  -148,    17,  -148,  -148,  -148,  -148,  -148,  -148,
    -148,  -148,  -148,  -148,  -148,   259,  -148,   254,   344,   346,
    -148,   263,   345,   350,  -148,  -148,  -148,  -148,  -148,    37,
    -148,  -148,   340,   351,   352,  -148,   267,  -148,   260,   354,
     357,  -148,   273,   361,   362,  -148,  -148,  -148,  -148,  -148,
     363,    11,  -148,  -148,  -148,  -148,   347,   365,   366,  -148,
     281,  -148,   270,   367,   368,   370,  -148,   279,  -148,   374,
      26,  -148,  -148,  -148,  -148,   358,   376,   377,   378,  -148,
     379,  -148,   258,  -148,   380,    67,  -148,  -148,  -148,   382,
    -148,   381,  -148,   286,  -148,  -148,   385,  -148,  -148
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -148,  -148,  -148,  -148,  -148,  -148,   372,  -148,  -148,  -148,
    -148,  -148,  -148,  -148,  -148,  -148,  -148,  -148,  -148,  -148,
    -147,  -148,  -148,  -148,  -148,  -148,  -148,  -148,  -148,  -148,
    -148,  -148,  -148,  -148,  -148,  -148,  -148,  -148,  -148,  -148,
    -148,  -148,  -148,  -148,  -148,  -148,  -148,  -148,  -148,  -148,
    -148,  -148,  -148,  -148,  -148,  -148,  -148,  -148,  -148,  -148,
    -148,  -148,  -148,  -148,  -148,  -148,  -148,  -148,  -148,  -148,
    -148,  -148,  -148,  -148,  -148,  -148,  -148,  -148,  -148,  -148,
    -148,  -148,  -148,  -148,  -148,  -148,  -148,  -148,  -148,  -148,
    -148,  -148,  -148,  -148,  -148,  -148,   317,  -148,  -148,  -148,
    -148,  -148,  -148,  -148,  -148,  -148,  -148,  -148,  -148,    75,
    -148,  -148,  -148,  -148,  -148,  -148,  -148,  -148,  -148,  -148,
    -148,    55,  -148,  -148,  -148,  -148,  -148,  -148,  -148,  -148,
    -148,  -148,  -148,    33,  -148,  -148,  -148,  -148,  -148,  -148,
    -148,  -148,  -148,  -148
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint16 yytable[] =
{
     177,     1,   179,   180,   181,   182,   183,   184,   185,   187,
     189,   190,   191,   192,   193,   194,   244,   196,   197,   199,
     201,    32,    33,   245,   218,    25,     4,   203,     6,   219,
     217,     7,   228,   229,   230,   231,   220,     9,    26,   235,
     204,   237,    13,   133,   240,   206,   294,   212,    15,   246,
      82,   254,    83,   256,    18,   258,   134,   366,   207,   295,
     213,   221,   247,   320,    19,    84,    21,    85,    22,    86,
     367,    87,   381,    88,   222,    89,   321,    90,   234,    91,
     135,   136,    92,   341,    93,   382,    94,    82,    95,    83,
      96,   296,    97,   276,   297,    98,   342,    99,    29,   100,
     280,   101,    84,   102,    85,   103,    86,   104,    87,   322,
      88,   323,    89,   392,    90,    31,    91,   236,    82,    92,
      83,    93,    34,    94,    54,    95,   393,    96,    41,    97,
     343,   344,    98,    84,    99,    85,   100,    86,   101,    87,
     102,    88,   103,    89,   104,    90,    55,    91,    35,    36,
      92,    57,    93,    58,    94,    82,    95,    83,    96,    59,
      97,    78,    79,    98,    61,    99,    62,   100,   253,   101,
      84,   102,    85,   103,    86,   104,    87,    63,    88,    64,
      89,    65,    90,    67,    91,   285,   286,    92,    66,    93,
      68,    94,    69,    95,    82,    96,    83,    97,   290,   291,
      98,    70,    99,    71,   100,   130,   101,   255,   102,    84,
     103,    85,   104,    86,    76,    87,    77,    88,    80,    89,
      81,    90,   129,    91,   132,   141,    92,   142,    93,   143,
      94,   144,    95,   145,    96,    82,    97,    83,   146,    98,
     171,    99,   172,   100,   174,   101,   175,   102,   257,   103,
      84,   104,    85,   176,    86,   210,    87,   215,    88,   211,
      89,   209,    90,   216,    91,   243,   232,    92,    82,    93,
      83,    94,   233,    95,   242,    96,   259,    97,   261,   239,
      98,   279,    99,    84,   100,    85,   101,    86,   102,    87,
     103,    88,   104,    89,   238,    90,   241,    91,   260,   252,
      92,   262,    93,   265,    94,   266,    95,   267,    96,   268,
      97,   269,   270,    98,   271,    99,   272,   100,   274,   101,
     273,   102,   277,   103,   278,   104,    42,    43,    44,   275,
     283,   282,   289,   292,   304,    45,   306,   307,   308,   309,
     310,   311,   312,   313,   314,   318,   319,   330,   339,   333,
     332,   334,   335,   340,   352,   353,   354,   390,   356,   357,
     350,    46,   358,   359,   363,   364,   365,   369,   371,   372,
     375,   373,   376,   377,    47,   378,   379,   380,   384,   386,
     387,   388,    20,   391,   389,   395,   396,   397,   398,   131,
     331,   355,     0,   374
};

static const yytype_int16 yycheck[] =
{
     147,    24,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,    13,   164,   165,   166,
     167,    27,    28,    20,     9,    46,    19,    46,     0,    14,
     177,    26,   179,   180,   181,   182,    21,     3,    59,   186,
      59,   188,    10,    46,   191,    46,    46,    46,    74,    46,
      15,   198,    17,   200,     5,   202,    59,    46,    59,    59,
      59,    46,    59,    46,    25,    30,    22,    32,     3,    34,
      59,    36,    46,    38,    59,    40,    59,    42,    43,    44,
      83,    84,    47,    46,    49,    59,    51,    15,    53,    17,
      55,    91,    57,   240,    94,    60,    59,    62,     3,    64,
     247,    66,    30,    68,    32,    70,    34,    72,    36,    92,
      38,    94,    40,    46,    42,     5,    44,    45,    15,    47,
      17,    49,     8,    51,     3,    53,    59,    55,    59,    57,
      93,    94,    60,    30,    62,    32,    64,    34,    66,    36,
      68,    38,    70,    40,    72,    42,    20,    44,    75,    76,
      47,     7,    49,    75,    51,    15,    53,    17,    55,    82,
      57,     5,     6,    60,    75,    62,   102,    64,    65,    66,
      30,    68,    32,    70,    34,    72,    36,     3,    38,     3,
      40,     3,    42,    23,    44,     5,     6,    47,     3,    49,
      59,    51,     3,    53,    15,    55,    17,    57,     5,     6,
      60,    59,    62,     3,    64,    77,    66,    67,    68,    30,
      70,    32,    72,    34,     5,    36,     5,    38,     5,    40,
       5,    42,     5,    44,    78,     3,    47,     3,    49,     3,
      51,     3,    53,     3,    55,    15,    57,    17,     3,    60,
       3,    62,    80,    64,   103,    66,     3,    68,    69,    70,
      30,    72,    32,     3,    34,    59,    36,     6,    38,     4,
      40,    29,    42,     6,    44,    58,    39,    47,    15,    49,
      17,    51,    41,    53,    56,    55,    71,    57,     3,    50,
      60,    61,    62,    30,    64,    32,    66,    34,    68,    36,
      70,    38,    72,    40,    48,    42,    54,    44,    73,    63,
      47,    85,    49,     3,    51,     3,    53,    16,    55,     3,
      57,     4,     4,    60,    18,    62,    31,    64,    35,    66,
      33,    68,     3,    70,     3,    72,    11,    12,    13,    37,
      86,    79,    52,     5,    87,    20,     3,     3,     3,     3,
       3,     3,     3,    61,    88,     3,     3,    88,     3,     5,
      96,     5,    89,     3,     3,     3,    89,    99,    98,     5,
      20,    46,     5,    90,     3,     3,     3,    20,     3,     3,
     100,    90,     5,     5,    59,     5,    97,     3,    20,     3,
       3,     3,    10,     3,     5,     3,     5,   101,     3,    72,
     315,   336,    -1,   360
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    24,   110,   112,    19,   113,     0,    26,   124,     3,
     114,   115,   116,    10,   125,    74,   197,   198,     5,    25,
     115,    22,     3,   126,   111,    46,    59,   199,   200,     3,
     118,     5,    27,    28,     8,    75,    76,   201,   202,   246,
     247,    59,    11,    12,    13,    20,    46,    59,   117,   119,
     120,   121,   122,   123,     3,    20,   128,     7,    75,    82,
     203,    75,   102,     3,     3,     3,     3,    23,    59,     3,
      59,     3,   204,   205,   206,   249,     5,     5,     5,     6,
       5,     5,    15,    17,    30,    32,    34,    36,    38,    40,
      42,    44,    47,    49,    51,    53,    55,    57,    60,    62,
      64,    66,    68,    70,    72,   129,   130,   132,   134,   136,
     138,   140,   142,   145,   148,   151,   154,   157,   159,   161,
     163,   165,   167,   169,   171,   173,   176,   179,   189,     5,
      77,   205,    78,    46,    59,    83,    84,   248,   250,   251,
     252,     3,     3,     3,     3,     3,     3,   131,   180,   141,
     133,   135,   139,   158,   160,   143,   155,   168,   137,   172,
     162,   164,   166,   190,   170,   149,   146,   152,   174,   177,
     127,     3,    80,   207,   103,     3,     3,   129,   182,   129,
     129,   129,   129,   129,   129,   129,   144,   129,   156,   129,
     129,   129,   129,   129,   129,   193,   129,   129,   150,   129,
     147,   129,   153,    46,    59,   175,    46,    59,   178,    29,
      59,     4,    46,    59,   208,     6,     6,   129,     9,    14,
      21,    46,    59,   181,   183,   184,   186,   188,   129,   129,
     129,   129,    39,    41,    43,   129,    45,   129,    48,    50,
     129,    54,    56,    58,    13,    20,    46,    59,   191,   194,
     195,   196,    63,    65,   129,    67,   129,    69,   129,    71,
      73,     3,    85,   209,   210,     3,     3,    16,     3,     4,
       4,    18,    31,    33,    35,    37,   129,     3,     3,    61,
     129,   211,    79,    86,   222,     5,     6,   187,   185,    52,
       5,     6,     5,   192,    46,    59,    91,    94,   212,   213,
     214,   215,   216,   223,    87,   234,     3,     3,     3,     3,
       3,     3,     3,    61,    88,   217,   218,   219,     3,     3,
      46,    59,    92,    94,   224,   225,   226,   227,   228,   235,
      88,   218,    96,     5,     5,    89,   229,   230,   231,     3,
       3,    46,    59,    93,    94,   236,   237,   238,   239,   240,
      20,   220,     3,     3,    89,   230,    98,     5,     5,    90,
     241,   242,   243,     3,     3,     3,    46,    59,   221,    20,
     232,     3,     3,    90,   242,   100,     5,     5,     5,    97,
       3,    46,    59,   233,    20,   244,     3,     3,     3,     5,
      99,     3,    46,    59,   245,     3,     5,   101,     3
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
      yyerror (&yylloc, osinstance, parserData, YY_("syntax error: cannot back up")); \
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
		  Type, Value, Location, osinstance, parserData); \
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
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp, OSInstance *osinstance, OSiLParserData *parserData)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp, osinstance, parserData)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
    YYLTYPE const * const yylocationp;
    OSInstance *osinstance;
    OSiLParserData *parserData;
#endif
{
  if (!yyvaluep)
    return;
  YYUSE (yylocationp);
  YYUSE (osinstance);
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
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp, OSInstance *osinstance, OSiLParserData *parserData)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep, yylocationp, osinstance, parserData)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
    YYLTYPE const * const yylocationp;
    OSInstance *osinstance;
    OSiLParserData *parserData;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  YY_LOCATION_PRINT (yyoutput, *yylocationp);
  YYFPRINTF (yyoutput, ": ");
  yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp, osinstance, parserData);
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
yy_reduce_print (YYSTYPE *yyvsp, YYLTYPE *yylsp, int yyrule, OSInstance *osinstance, OSiLParserData *parserData)
#else
static void
yy_reduce_print (yyvsp, yylsp, yyrule, osinstance, parserData)
    YYSTYPE *yyvsp;
    YYLTYPE *yylsp;
    int yyrule;
    OSInstance *osinstance;
    OSiLParserData *parserData;
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
		       , &(yylsp[(yyi + 1) - (yynrhs)])		       , osinstance, parserData);
      fprintf (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, yylsp, Rule, osinstance, parserData); \
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
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp, OSInstance *osinstance, OSiLParserData *parserData)
#else
static void
yydestruct (yymsg, yytype, yyvaluep, yylocationp, osinstance, parserData)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
    YYLTYPE *yylocationp;
    OSInstance *osinstance;
    OSiLParserData *parserData;
#endif
{
  YYUSE (yyvaluep);
  YYUSE (yylocationp);
  YYUSE (osinstance);
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
int yyparse (OSInstance *osinstance, OSiLParserData *parserData);
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
yyparse (OSInstance *osinstance, OSiLParserData *parserData)
#else
int
yyparse (osinstance, parserData)
    OSInstance *osinstance;
    OSiLParserData *parserData;
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
        case 5:

    {if(osinstance->instanceData->quadraticCoefficients->numberOfQuadraticTerms > parserData->qtermcount ) 
	osilerror( NULL, osinstance, parserData, "actual number of qterms less than numberOfQuadraticTerms");}
    break;

  case 6:

    { 
if ( *(yyvsp[(2) - (5)].sval) != *(yyvsp[(4) - (5)].sval) ) osilerror( NULL, osinstance, parserData, "start and end quotes are not the same");
osinstance->instanceData->quadraticCoefficients->numberOfQuadraticTerms = (yyvsp[(3) - (5)].ival);  
if(osinstance->instanceData->quadraticCoefficients->numberOfQuadraticTerms > 0 ) 
osinstance->instanceData->quadraticCoefficients->qTerm = new QuadraticTerm*[ (yyvsp[(3) - (5)].ival) ];
for(int i = 0; i < (yyvsp[(3) - (5)].ival); i++) osinstance->instanceData->quadraticCoefficients->qTerm[i] = new QuadraticTerm();}
    break;

  case 9:

    {if(osinstance->instanceData->quadraticCoefficients->numberOfQuadraticTerms <= parserData->qtermcount )
 osilerror( NULL, osinstance, parserData, "too many QuadraticTerms");}
    break;

  case 10:

    {parserData->qtermcount++; 
if(!parserData->qtermidxattON)  osilerror( NULL, osinstance, parserData, "the qTerm attribute idx is required"); 
if(!parserData->qtermidxOneattON)  osilerror( NULL, osinstance, parserData, "the qTerm attribute idxOne is required"); 
if(!parserData->qtermidxTwoattON)  osilerror( NULL, osinstance, parserData, "the qTerm attribute idxTwo is required"); 
parserData->qtermidattON = false; 
parserData->qtermidxattON = false; 
parserData->qtermidxOneattON = false; 
parserData->qtermidxTwoattON = false;
parserData->qtermcoefattON = false;}
    break;

  case 15:

    { if(parserData->qtermidxOneattON) osilerror( NULL, osinstance, parserData, "too many qTerm idxOne attributes"); 
			parserData->qtermidxOneattON = true;  }
    break;

  case 16:

    { if(parserData->qtermidxTwoattON) osilerror( NULL, osinstance, parserData, "too many qTerm idxTwo attributes"); 
			parserData->qtermidxTwoattON = true;  }
    break;

  case 17:

    { if(parserData->qtermcoefattON) osilerror( NULL, osinstance, parserData, "too many qTerm coef attributes"); 
			parserData->qtermcoefattON = true;  }
    break;

  case 18:

    { if(parserData->qtermidxattON) osilerror( NULL, osinstance, parserData, "too many qTerm idx attributes"); 
			parserData->qtermidxattON = true;  }
    break;

  case 19:

    {  if ( *(yyvsp[(2) - (4)].sval) != *(yyvsp[(4) - (4)].sval) ) osilerror( NULL, osinstance, parserData, "start and end quotes are not the same");
osinstance->instanceData->quadraticCoefficients->qTerm[parserData->qtermcount]->idxOne = (yyvsp[(3) - (4)].ival);
	if( (yyvsp[(3) - (4)].ival) >= osinstance->instanceData->variables->numberOfVariables){
	 	osilerror( NULL, osinstance, parserData, "variable index exceeds number of variables");
	 }
}
    break;

  case 20:

    { if ( *(yyvsp[(2) - (4)].sval) != *(yyvsp[(4) - (4)].sval) ) osilerror( NULL, osinstance, parserData, "start and end quotes are not the same");
osinstance->instanceData->quadraticCoefficients->qTerm[parserData->qtermcount]->idxTwo = (yyvsp[(3) - (4)].ival);
	if( (yyvsp[(3) - (4)].ival) >= osinstance->instanceData->variables->numberOfVariables){
	 	osilerror( NULL, osinstance, parserData, "variable index exceeds number of variables");
	 }
}
    break;

  case 21:

    {if ( *(yyvsp[(2) - (4)].sval) != *(yyvsp[(4) - (4)].sval) ) osilerror( NULL, osinstance, parserData, "start and end quotes are not the same");
osinstance->instanceData->quadraticCoefficients->qTerm[parserData->qtermcount]->coef = (yyvsp[(3) - (4)].dval);}
    break;

  case 22:

    { 
osinstance->instanceData->quadraticCoefficients->qTerm[parserData->qtermcount]->coef = (yyvsp[(3) - (4)].ival);}
    break;

  case 23:

    {  if ( *(yyvsp[(2) - (4)].sval) != *(yyvsp[(4) - (4)].sval) ) osilerror( NULL, osinstance, parserData, "start and end quotes are not the same");
osinstance->instanceData->quadraticCoefficients->qTerm[parserData->qtermcount]->idx = (yyvsp[(3) - (4)].ival);}
    break;

  case 25:

    {  if(parserData->nlnodecount <  parserData->tmpnlcount)  osilerror( NULL, osinstance, parserData, "actual number of nl terms less than number attribute");   }
    break;

  case 26:

    { if ( *(yyvsp[(2) - (5)].sval) != *(yyvsp[(4) - (5)].sval) ) osilerror( NULL, osinstance, parserData, "start and end quotes are not the same");
parserData->tmpnlcount = (yyvsp[(3) - (5)].ival);
osinstance->instanceData->nonlinearExpressions->numberOfNonlinearExpressions = (yyvsp[(3) - (5)].ival);  
if(osinstance->instanceData->nonlinearExpressions->numberOfNonlinearExpressions > 0 ) osinstance->instanceData->nonlinearExpressions->nl = new Nl*[ (yyvsp[(3) - (5)].ival) ];
}
    break;

  case 28:

    {
	// IMPORTANT -- HERE IS WHERE WE CREATE THE EXPRESSION TREE
	osinstance->instanceData->nonlinearExpressions->nl[ parserData->nlnodecount]->osExpressionTree->m_treeRoot = 
	parserData->nlNodeVec[ 0]->createExpressionTreeFromPrefix( parserData->nlNodeVec);
	parserData->nlnodecount++;
}
    break;

  case 30:

    { if ( *(yyvsp[(2) - (4)].sval) != *(yyvsp[(4) - (4)].sval) ) osilerror( NULL, osinstance, parserData, "start and end quotes are not the same");
osinstance->instanceData->nonlinearExpressions->nl[ parserData->nlnodecount] = new Nl();
osinstance->instanceData->nonlinearExpressions->nl[ parserData->nlnodecount]->idx = (yyvsp[(3) - (4)].ival);
osinstance->instanceData->nonlinearExpressions->nl[ parserData->nlnodecount]->osExpressionTree = new OSExpressionTree();
if(parserData->nlnodecount > parserData->tmpnlcount) osilerror( NULL, osinstance, parserData, "actual number of nl terms greater than number attribute");
// clear the vectors of pointers
parserData->nlNodeVec.clear();
parserData->sumVec.clear();
//parserData->allDiffVec.clear();
parserData->maxVec.clear();
parserData->minVec.clear();
parserData->productVec.clear();
}
    break;

  case 54:

    {
	parserData->nlNodePoint = new OSnLNodeTimes();
	parserData->nlNodeVec.push_back( parserData->nlNodePoint);
}
    break;

  case 56:

    {
	parserData->nlNodePoint = new OSnLNodePlus();
	parserData->nlNodeVec.push_back( parserData->nlNodePoint);
}
    break;

  case 58:

    {
	parserData->nlNodePoint = new OSnLNodeMinus();
	parserData->nlNodeVec.push_back( parserData->nlNodePoint);
}
    break;

  case 60:

    {
	parserData->nlNodePoint = new OSnLNodeNegate();
	parserData->nlNodeVec.push_back( parserData->nlNodePoint);
}
    break;

  case 62:

    { 
	parserData->nlNodePoint = new OSnLNodeDivide();
	parserData->nlNodeVec.push_back( parserData->nlNodePoint);
}
    break;

  case 64:

    {
	parserData->nlNodePoint = new OSnLNodePower();
	parserData->nlNodeVec.push_back( parserData->nlNodePoint);
}
    break;

  case 66:

    {
	parserData->nlNodePoint = new OSnLNodeSum();
	parserData->nlNodeVec.push_back( parserData->nlNodePoint);
	parserData->sumVec.push_back( parserData->nlNodePoint);
}
    break;

  case 67:

    {
	parserData->sumVec.back()->m_mChildren = new OSnLNode*[ parserData->sumVec.back()->inumberOfChildren];
	parserData->sumVec.pop_back();
}
    break;

  case 68:

    {	parserData->sumVec.back()->inumberOfChildren++; }
    break;

  case 69:

    {	parserData->sumVec.back()->inumberOfChildren++; }
    break;

  case 70:

    {
	parserData->nlNodePoint = new OSnLNodeAllDiff();
	parserData->nlNodeVec.push_back( parserData->nlNodePoint);
	parserData->allDiffVec.push_back( parserData->nlNodePoint);
}
    break;

  case 71:

    {
	parserData->allDiffVec.back()->m_mChildren = new OSnLNode*[ parserData->allDiffVec.back()->inumberOfChildren];
	parserData->allDiffVec.pop_back();
	osinstance->instanceData->nonlinearExpressions->nl[ parserData->nlnodecount]->osExpressionTree->bCppADMustReTape = true;
}
    break;

  case 72:

    {	parserData->allDiffVec.back()->inumberOfChildren++; }
    break;

  case 73:

    {	parserData->allDiffVec.back()->inumberOfChildren++; }
    break;

  case 74:

    {
	parserData->nlNodePoint = new OSnLNodeMax();
	parserData->nlNodeVec.push_back( parserData->nlNodePoint);
	parserData->maxVec.push_back( parserData->nlNodePoint);
}
    break;

  case 75:

    {
	parserData->maxVec.back()->m_mChildren = new OSnLNode*[ parserData->maxVec.back()->inumberOfChildren];
	parserData->maxVec.pop_back();
	osinstance->instanceData->nonlinearExpressions->nl[ parserData->nlnodecount]->osExpressionTree->bCppADMustReTape = true;
}
    break;

  case 76:

    {	parserData->maxVec.back()->inumberOfChildren++; }
    break;

  case 77:

    {	parserData->maxVec.back()->inumberOfChildren++; }
    break;

  case 78:

    {
	parserData->nlNodePoint = new OSnLNodeMin();
	parserData->nlNodeVec.push_back( parserData->nlNodePoint);
	parserData->minVec.push_back( parserData->nlNodePoint);
}
    break;

  case 79:

    {
	parserData->minVec.back()->m_mChildren = new OSnLNode*[ parserData->minVec.back()->inumberOfChildren];
	parserData->minVec.pop_back();
	osinstance->instanceData->nonlinearExpressions->nl[ parserData->nlnodecount]->osExpressionTree->bCppADMustReTape = true;
}
    break;

  case 80:

    {	parserData->minVec.back()->inumberOfChildren++; }
    break;

  case 81:

    {	parserData->minVec.back()->inumberOfChildren++; }
    break;

  case 82:

    {
	parserData->nlNodePoint = new OSnLNodeProduct();
	parserData->nlNodeVec.push_back( parserData->nlNodePoint);
	parserData->productVec.push_back( parserData->nlNodePoint);
}
    break;

  case 83:

    {
	parserData->productVec.back()->m_mChildren = new OSnLNode*[ parserData->productVec.back()->inumberOfChildren];
	parserData->productVec.pop_back();
}
    break;

  case 84:

    {	parserData->productVec.back()->inumberOfChildren++; }
    break;

  case 85:

    {	parserData->productVec.back()->inumberOfChildren++; }
    break;

  case 86:

    {
	parserData->nlNodePoint = new OSnLNodeLn();
	parserData->nlNodeVec.push_back( parserData->nlNodePoint);
}
    break;

  case 88:

    {
	parserData->nlNodePoint = new OSnLNodeSqrt();
	parserData->nlNodeVec.push_back( parserData->nlNodePoint);
}
    break;

  case 90:

    {
	parserData->nlNodePoint = new OSnLNodeSquare();
	parserData->nlNodeVec.push_back( parserData->nlNodePoint);
}
    break;

  case 92:

    {
	parserData->nlNodePoint = new OSnLNodeCos();
	parserData->nlNodeVec.push_back( parserData->nlNodePoint);
}
    break;

  case 94:

    {
	parserData->nlNodePoint = new OSnLNodeSin();
	parserData->nlNodeVec.push_back( parserData->nlNodePoint);
}
    break;

  case 96:

    {
	parserData->nlNodePoint = new OSnLNodeExp();
	parserData->nlNodeVec.push_back( parserData->nlNodePoint);
}
    break;

  case 98:

    {
	parserData->nlNodePoint = new OSnLNodeAbs();
	parserData->nlNodeVec.push_back( parserData->nlNodePoint);
}
    break;

  case 99:

    {
osinstance->instanceData->nonlinearExpressions->nl[ parserData->nlnodecount]->osExpressionTree->bCppADMustReTape = true;
}
    break;

  case 100:

    {
	parserData->nlNodePoint = new OSnLNodeIf();
	parserData->nlNodeVec.push_back( parserData->nlNodePoint);
}
    break;

  case 101:

    {
osinstance->instanceData->nonlinearExpressions->nl[ parserData->nlnodecount]->osExpressionTree->bCppADMustReTape = true;
}
    break;

  case 102:

    {	parserData->nlNodePoint = new OSnLNodeE();
	parserData->nlNodeVec.push_back( parserData->nlNodePoint);}
    break;

  case 106:

    {	parserData->nlNodePoint = new OSnLNodePI();
	parserData->nlNodeVec.push_back( parserData->nlNodePoint);}
    break;

  case 110:

    {
	parserData->nlNodeNumberPoint = new OSnLNodeNumber();
	parserData->nlNodeVec.push_back( parserData->nlNodeNumberPoint);
}
    break;

  case 111:

    {parserData->numbervalueattON = false; parserData->numbertypeattON = false; parserData->numberidattON = false;}
    break;

  case 116:

    {if(parserData->numbertypeattON) osilerror( NULL, osinstance, parserData, "too many number type attributes"); 
			parserData->numbertypeattON = true; }
    break;

  case 117:

    {if(parserData->numbervalueattON) osilerror( NULL, osinstance, parserData, "too many number value attributes"); 
			parserData->numbervalueattON = true; }
    break;

  case 118:

    {if(parserData->numberidattON) osilerror( NULL, osinstance, parserData,"too many number id attributes"); 
			parserData->numberidattON = true; }
    break;

  case 119:

    {
	parserData->nlNodeNumberPoint->type = (yyvsp[(2) - (2)].sval);
}
    break;

  case 121:

    {
	parserData->nlNodeNumberPoint->id = (yyvsp[(2) - (2)].sval);
}
    break;

  case 123:

    {if ( *(yyvsp[(2) - (4)].sval) != *(yyvsp[(4) - (4)].sval) ) osilerror( NULL, osinstance, parserData, "start and end quotes are not the same");
	parserData->nlNodeNumberPoint->value = (yyvsp[(3) - (4)].dval);
}
    break;

  case 124:

    {if ( *(yyvsp[(2) - (4)].sval) != *(yyvsp[(4) - (4)].sval) ) osilerror( NULL, osinstance, parserData, "start and end quotes are not the same");
	parserData->nlNodeNumberPoint->value = (yyvsp[(3) - (4)].ival);
}
    break;

  case 125:

    {
	parserData->nlNodeVariablePoint = new OSnLNodeVariable();
	parserData->nlNodeVec.push_back( parserData->nlNodeVariablePoint);
}
    break;

  case 126:

    {parserData->variablecoefattON = false; parserData->variableidxattON = false;}
    break;

  case 128:

    {
	parserData->nlNodeVariablePoint->inumberOfChildren = 1;
	parserData->nlNodeVariablePoint->m_mChildren = new OSnLNode*[ 1];
}
    break;

  case 133:

    {if(parserData->variablecoefattON) osilerror( NULL, osinstance, parserData, "too many variable coef attributes"); 
			parserData->variablecoefattON = true; }
    break;

  case 134:

    {if(parserData->variableidxattON) osilerror( NULL, osinstance, parserData, "too many variable idx attributes"); 
			parserData->variableidxattON = true; 
			}
    break;

  case 135:

    { if ( *(yyvsp[(2) - (4)].sval) != *(yyvsp[(4) - (4)].sval) ) osilerror( NULL, osinstance, parserData, "start and end quotes are not the same");
	parserData->nlNodeVariablePoint->coef = (yyvsp[(3) - (4)].dval);
}
    break;

  case 136:

    { if ( *(yyvsp[(2) - (4)].sval) != *(yyvsp[(4) - (4)].sval) ) osilerror( NULL, osinstance, parserData, "start and end quotes are not the same");
	parserData->nlNodeVariablePoint->coef = (yyvsp[(3) - (4)].ival);		
}
    break;

  case 137:

    { if ( *(yyvsp[(2) - (4)].sval) != *(yyvsp[(4) - (4)].sval) ) osilerror( NULL, osinstance, parserData, "start and end quotes are not the same");
	parserData->nlNodeVariablePoint->idx = (yyvsp[(3) - (4)].ival);
	if( (yyvsp[(3) - (4)].ival) >= osinstance->instanceData->variables->numberOfVariables){
	 	osilerror( NULL, osinstance, parserData, "variable index exceeds number of variables");
	 }
}
    break;

  case 140:

    {osinstance->instanceData->timeDomain = new TimeDomain();}
    break;

  case 147:

    {
	if( osinstance->instanceData->timeDomain->stages->numberOfStages > parserData->stagecount )
		osilerror( NULL, osinstance, parserData, "actual number of stages less than numberOfStages");
 /* After stages have been processed, make sure that all variables and constraints have been assigned
  * to a stage (uniquely) and all objectives have been assigned as well (possibly more than once).
  * For future reference also record the stage to which each variable and constaint belongs. 
  */
	parserData->m_miVarStageInfo = new int [ osinstance->instanceData->variables->numberOfVariables ];
	parserData->m_miObjStageInfo = new int [ osinstance->instanceData->objectives->numberOfObjectives ];
	parserData->m_miConStageInfo = new int [ osinstance->instanceData->constraints->numberOfConstraints ];
	parserData->nvarcovered = 0;
	for (int i = 0; i < osinstance->instanceData->variables->numberOfVariables; i++)
		 parserData->m_miVarStageInfo[i] = -1;
	for (int i = 0; i < osinstance->instanceData->objectives->numberOfObjectives; i++)
		 parserData->m_miObjStageInfo[i] = -1;
	for (int i = 0; i < osinstance->instanceData->constraints->numberOfConstraints; i++)
		 parserData->m_miConStageInfo[i] = -1;
	for (int k = 0; k < osinstance->instanceData->timeDomain->stages->numberOfStages; k++)
		{for (int i = 0; i < osinstance->instanceData->timeDomain->stages->stage[k]->variables->numberOfVariables; i++)
			{			
			if (parserData->m_miVarStageInfo[ osinstance->instanceData->timeDomain->stages->stage[k]->variables->var[i]->idx ] != -1)
					osilerror (NULL, osinstance, parserData, "variable belongs to two stages");
				parserData->m_miVarStageInfo[ osinstance->instanceData->timeDomain->stages->stage[k]->variables->var[i]->idx ] = k;
			};
		 parserData->nvarcovered += osinstance->instanceData->timeDomain->stages->stage[k]->variables->numberOfVariables;
		};
	if (parserData->nvarcovered != osinstance->instanceData->variables->numberOfVariables)
		osilerror (NULL, osinstance, parserData, "some variables not assigned to any stage");
	parserData->nconcovered = 0;
	for (int k = 0; k < osinstance->instanceData->timeDomain->stages->numberOfStages; k++)
		{for (int i = 0; i < osinstance->instanceData->timeDomain->stages->stage[k]->constraints->numberOfConstraints; i++)
			{if (parserData->m_miConStageInfo[ osinstance->instanceData->timeDomain->stages->stage[k]->constraints->con[i]->idx ] != -1)
				osilerror (NULL, osinstance, parserData, "constraint belongs to two stages");
				 parserData->m_miConStageInfo[ osinstance->instanceData->timeDomain->stages->stage[k]->constraints->con[i]->idx ] = k;
			};
		 parserData->nconcovered += osinstance->instanceData->timeDomain->stages->stage[k]->constraints->numberOfConstraints;
		};
	if (parserData->nconcovered != osinstance->instanceData->constraints->numberOfConstraints)
		osilerror (NULL, osinstance, parserData, "some constraints not assigned to any stage");
	for (int k = 0; k < osinstance->instanceData->timeDomain->stages->numberOfStages; k++)
		{ for (int i = 0; i < osinstance->instanceData->timeDomain->stages->stage[k]->objectives->numberOfObjectives; i++)
			{ if (parserData->m_miObjStageInfo[ -osinstance->instanceData->timeDomain->stages->stage[k]->objectives->obj[i]->idx-1 ] == -1)
	  			  parserData->m_miObjStageInfo[ -osinstance->instanceData->timeDomain->stages->stage[k]->objectives->obj[i]->idx-1 ] = k;
			};
		};
	for (int i = 0; i < osinstance->instanceData->objectives->numberOfObjectives; i++)
		if (parserData->m_miObjStageInfo[i] == -1)
			osilerror (NULL, osinstance, parserData, "some objectives not assigned to any stage");
}
    break;

  case 148:

    {osinstance->instanceData->timeDomain->stages = new TimeDomainStages();}
    break;

  case 149:

    {
	if ( *(yyvsp[(2) - (5)].sval) != *(yyvsp[(4) - (5)].sval) ) osilerror( NULL, osinstance, parserData, "start and end quotes are not the same");
	if ((yyvsp[(3) - (5)].ival) < 1) osilerror (NULL, osinstance, parserData, "number of stages must be positive");
	osinstance->instanceData->timeDomain->stages->numberOfStages = (yyvsp[(3) - (5)].ival);
	if (osinstance->instanceData->timeDomain->stages->numberOfStages > 0 )
		osinstance->instanceData->timeDomain->stages->stage = new TimeDomainStage*[ (yyvsp[(3) - (5)].ival) ];
	for(int i = 0; i < (yyvsp[(3) - (5)].ival); i++) 
	{	osinstance->instanceData->timeDomain->stages->stage[i] = new TimeDomainStage();
		osinstance->instanceData->timeDomain->stages->stage[i]->variables   = new TimeDomainStageVariables();
		osinstance->instanceData->timeDomain->stages->stage[i]->constraints = new TimeDomainStageConstraints();
		osinstance->instanceData->timeDomain->stages->stage[i]->objectives  = new TimeDomainStageObjectives();
	}
}
    break;

  case 152:

    {
	if( osinstance->instanceData->timeDomain->stages->numberOfStages <= parserData->stagecount)
		osilerror( NULL, osinstance, parserData, "too many stages");
	osinstance->instanceData->timeDomain->stages->stage[parserData->stagecount]->variables->numberOfVariables = 0;
	osinstance->instanceData->timeDomain->stages->stage[parserData->stagecount]->constraints->numberOfConstraints = 0;
	osinstance->instanceData->timeDomain->stages->stage[parserData->stagecount]->objectives->numberOfObjectives = 0;
}
    break;

  case 153:

    { /* set defaults for next stage */
	parserData->stagenameON = false;
	parserData->stageVariablesON = false;
	parserData->stageObjectivesON = false;
	parserData->stageConstraintsON = false;
	parserData->stageVariablesOrdered = false;
	parserData->stageObjectivesOrdered = false;
	parserData->stageConstraintsOrdered = false;
	parserData->stageVariableStartIdx = 0;
	parserData->stageObjectiveStartIdx = 0;
	parserData->stageConstraintStartIdx = 0;
	parserData->stagevarcount = 0;
	parserData->stageconcount = 0;
	parserData->stageobjcount = 0;
	parserData->stagecount++;
}
    break;

  case 155:

    {
		  osinstance->instanceData->timeDomain->stages->stage[parserData->stagecount]->name = (yyvsp[(2) - (3)].sval);}
    break;

  case 160:

    {
        parserData->stageVariablesON = true;
        }
    break;

  case 165:

    {
	if ((yyvsp[(3) - (4)].ival) < 0) osilerror (NULL, osinstance, parserData, "number of variables cannot be negative");
	if ((yyvsp[(3) - (4)].ival) > osinstance->instanceData->variables->numberOfVariables)
		osilerror (NULL, osinstance, parserData, "too many variables in this stage");		 
	if ((yyvsp[(3) - (4)].ival) > 0) {
		if (osinstance->instanceData->timeDomain->stages->stage[parserData->stagecount]->variables->numberOfVariables > 0)
			osilerror( NULL, osinstance, parserData, "duplicate attribute numberOfVariables");
		osinstance->instanceData->timeDomain->stages->stage[parserData->stagecount]->variables->numberOfVariables = (yyvsp[(3) - (4)].ival);
		osinstance->instanceData->timeDomain->stages->stage[parserData->stagecount]->variables->var = new TimeDomainStageVar*[ (yyvsp[(3) - (4)].ival) ];
		for (int i = 0; i < (yyvsp[(3) - (4)].ival); i++) 
		{	osinstance->instanceData->timeDomain->stages->stage[parserData->stagecount]->variables->var[i] = new TimeDomainStageVar;
			osinstance->instanceData->timeDomain->stages->stage[parserData->stagecount]->variables->var[i]->idx = 0; 
		}
	};
}
    break;

  case 166:

    {
	if (parserData->stageVariablesOrdered == true) osilerror (NULL, osinstance, parserData, "duplicate attribute");
	if ((yyvsp[(3) - (4)].ival) < 0 && (yyvsp[(3) - (4)].ival) >= osinstance->instanceData->variables->numberOfVariables)
		osilerror (NULL, osinstance, parserData, "variable index out of range");
	parserData->stageVariablesOrdered = true;
	parserData->stageVariableStartIdx = (yyvsp[(3) - (4)].ival);
}
    break;

  case 167:

    {
	if ((parserData->stageVariablesOrdered != true) && 
		 (osinstance->instanceData->timeDomain->stages->stage[parserData->stagecount]->variables->numberOfVariables > 0) ) 
		  osilerror (NULL, osinstance, parserData, "varlist missing");
	for (int i = 0; i < osinstance->instanceData->timeDomain->stages->stage[parserData->stagecount]->variables->numberOfVariables; i++)
		osinstance->instanceData->timeDomain->stages->stage[parserData->stagecount]->variables->var[i]->idx = parserData->stageVariableStartIdx + i;
	}
    break;

  case 168:

    {
	  if (parserData->stagevarcount < osinstance->instanceData->timeDomain->stages->stage[parserData->stagecount]->variables->numberOfVariables)
	      osilerror (NULL, osinstance, parserData, "too few variables supplied");
	  }
    break;

  case 173:

    {if (parserData->stageVariablesOrdered == true) osilerror (NULL, osinstance, parserData, "no varlist expected");}
    break;

  case 175:

    {
	if ((yyvsp[(3) - (4)].ival) < 0 && (yyvsp[(3) - (4)].ival) >= osinstance->instanceData->variables->numberOfVariables)
		osilerror (NULL, osinstance, parserData, "variable index out of range");		 
	if (parserData->stagevarcount >= osinstance->instanceData->timeDomain->stages->stage[parserData->stagecount]->variables->numberOfVariables) 
	    osilerror (NULL, osinstance, parserData, "too many variables in this stage");
	osinstance->instanceData->timeDomain->stages->stage[parserData->stagecount]->variables->var[parserData->stagevarcount]->idx = (yyvsp[(3) - (4)].ival);
	parserData->stagevarcount++;
}
    break;

  case 179:

    {
        parserData->stageConstraintsON = true;
	}
    break;

  case 184:

    {
	if ((yyvsp[(3) - (4)].ival) < 0) osilerror (NULL, osinstance, parserData, "number of constraints cannot be negative");
	if ((yyvsp[(3) - (4)].ival) > osinstance->instanceData->constraints->numberOfConstraints)
		osilerror (NULL, osinstance, parserData, "too many constraints in this stage");		 
	if ((yyvsp[(3) - (4)].ival) > 0) {
		if (osinstance->instanceData->timeDomain->stages->stage[parserData->stagecount]->constraints->numberOfConstraints > 0)
			osilerror( NULL, osinstance, parserData, "duplicate attribute numberOfConstraints");
		osinstance->instanceData->timeDomain->stages->stage[parserData->stagecount]->constraints->numberOfConstraints = (yyvsp[(3) - (4)].ival);
		osinstance->instanceData->timeDomain->stages->stage[parserData->stagecount]->constraints->con = new TimeDomainStageCon*[ (yyvsp[(3) - (4)].ival) ];
		for (int i = 0; i < (yyvsp[(3) - (4)].ival); i++) 
		{	osinstance->instanceData->timeDomain->stages->stage[parserData->stagecount]->constraints->con[i] = new TimeDomainStageCon;
			osinstance->instanceData->timeDomain->stages->stage[parserData->stagecount]->constraints->con[i]->idx = 0; 
		}
	};
}
    break;

  case 185:

    {
	if (parserData->stageConstraintsOrdered == true) osilerror (NULL, osinstance, parserData, "duplicate attribute");
	if ((yyvsp[(3) - (4)].ival) < 0 && (yyvsp[(3) - (4)].ival) >= osinstance->instanceData->constraints->numberOfConstraints)
		osilerror (NULL, osinstance, parserData, "constraint index out of range");
	parserData->stageConstraintsOrdered = true;
	parserData->stageConstraintStartIdx = (yyvsp[(3) - (4)].ival);
}
    break;

  case 186:

    {
	if ((parserData->stageConstraintsOrdered != true) && 
		 (osinstance->instanceData->timeDomain->stages->stage[parserData->stagecount]->constraints->numberOfConstraints > 0) ) 
		  osilerror (NULL, osinstance, parserData, "conlist missing");
	for (int i = 0; i < osinstance->instanceData->timeDomain->stages->stage[parserData->stagecount]->constraints->numberOfConstraints; i++)
		osinstance->instanceData->timeDomain->stages->stage[parserData->stagecount]->constraints->con[i]->idx = parserData->stageConstraintStartIdx + i;
	}
    break;

  case 187:

    {
	  if (parserData->stageconcount < osinstance->instanceData->timeDomain->stages->stage[parserData->stagecount]->constraints->numberOfConstraints)
	      osilerror (NULL, osinstance, parserData, "too few constraints supplied");
	  }
    break;

  case 192:

    {if (parserData->stageConstraintsOrdered == true) osilerror (NULL, osinstance, parserData, "no conlist expected");}
    break;

  case 194:

    {
	if ((yyvsp[(3) - (4)].ival) < 0 && (yyvsp[(3) - (4)].ival) >= osinstance->instanceData->constraints->numberOfConstraints)
		osilerror (NULL, osinstance, parserData, "constraint index out of range");		 
	if (parserData->stageconcount >= osinstance->instanceData->timeDomain->stages->stage[parserData->stagecount]->constraints->numberOfConstraints) 
	    osilerror (NULL, osinstance, parserData, "too many constraints in this stage");
	osinstance->instanceData->timeDomain->stages->stage[parserData->stagecount]->constraints->con[parserData->stageconcount]->idx = (yyvsp[(3) - (4)].ival);
	parserData->stageconcount++;
}
    break;

  case 197:

    { /* By default, an objective belongs to every stage */
			osinstance->instanceData->timeDomain->stages->stage[parserData->stagecount]->objectives->numberOfObjectives = 
				osinstance->instanceData->objectives->numberOfObjectives;
			osinstance->instanceData->timeDomain->stages->stage[parserData->stagecount]->objectives->obj = 
				new TimeDomainStageObj*[ osinstance->instanceData->objectives->numberOfObjectives ];
			for (int i = 0; i < osinstance->instanceData->objectives->numberOfObjectives; i++) 
			{	osinstance->instanceData->timeDomain->stages->stage[parserData->stagecount]->objectives->obj[i] = new TimeDomainStageObj;
				osinstance->instanceData->timeDomain->stages->stage[parserData->stagecount]->objectives->obj[i]->idx = -(i+1); 
			}
	}
    break;

  case 198:

    {
	  parserData->stageObjectivesON = true;
	}
    break;

  case 203:

    {
	if ((yyvsp[(3) - (4)].ival) < 0) osilerror (NULL, osinstance, parserData, "number of objectives cannot be negative");
	if ((yyvsp[(3) - (4)].ival) > osinstance->instanceData->objectives->numberOfObjectives)
		osilerror (NULL, osinstance, parserData, "too many objectives in this stage");		 
	if ((yyvsp[(3) - (4)].ival) > 0) {
		if (osinstance->instanceData->timeDomain->stages->stage[parserData->stagecount]->objectives->numberOfObjectives > 0)
			osilerror( NULL, osinstance, parserData, "duplicate attribute numberOfObjectives");
		osinstance->instanceData->timeDomain->stages->stage[parserData->stagecount]->objectives->numberOfObjectives = (yyvsp[(3) - (4)].ival);
		osinstance->instanceData->timeDomain->stages->stage[parserData->stagecount]->objectives->obj = new TimeDomainStageObj*[ (yyvsp[(3) - (4)].ival) ];
		for (int i = 0; i < (yyvsp[(3) - (4)].ival); i++) 
		{	osinstance->instanceData->timeDomain->stages->stage[parserData->stagecount]->objectives->obj[i] = new TimeDomainStageObj;
			osinstance->instanceData->timeDomain->stages->stage[parserData->stagecount]->objectives->obj[i]->idx = 0; 
		}
	};
}
    break;

  case 204:

    {
	if (parserData->stageObjectivesOrdered == true) osilerror (NULL, osinstance, parserData, "duplicate attribute");
	if ((yyvsp[(3) - (4)].ival) >= 0 && (yyvsp[(3) - (4)].ival) <= -osinstance->instanceData->objectives->numberOfObjectives - 1)
		osilerror (NULL, osinstance, parserData, "objective index out of range");
	parserData->stageObjectivesOrdered = true;
	parserData->stageObjectiveStartIdx = (yyvsp[(3) - (4)].ival);
}
    break;

  case 205:

    {
	if ((parserData->stageObjectivesOrdered != true) && 
		 (osinstance->instanceData->timeDomain->stages->stage[parserData->stagecount]->objectives->numberOfObjectives > 0) ) 
		  osilerror (NULL, osinstance, parserData, "objlist missing");
	for (int i = 0; i < osinstance->instanceData->timeDomain->stages->stage[parserData->stagecount]->objectives->numberOfObjectives; i++)
		osinstance->instanceData->timeDomain->stages->stage[parserData->stagecount]->objectives->obj[i]->idx = parserData->stageObjectiveStartIdx - i;
	}
    break;

  case 206:

    {
	  if (parserData->stageobjcount < osinstance->instanceData->timeDomain->stages->stage[parserData->stagecount]->objectives->numberOfObjectives)
	      osilerror (NULL, osinstance, parserData, "too few objectives supplied");
	}
    break;

  case 211:

    {if (parserData->stageObjectivesOrdered == true) osilerror (NULL, osinstance, parserData, "no objlist expected");}
    break;

  case 213:

    {
	if ((yyvsp[(3) - (4)].ival) >= 0 && (yyvsp[(3) - (4)].ival) >= -osinstance->instanceData->objectives->numberOfObjectives - 1)
		osilerror (NULL, osinstance, parserData, "objective index out of range");		 
	if (parserData->stageobjcount >= osinstance->instanceData->timeDomain->stages->stage[parserData->stagecount]->objectives->numberOfObjectives) 
	    osilerror (NULL, osinstance, parserData, "too many objectives in this stage");
	osinstance->instanceData->timeDomain->stages->stage[parserData->stagecount]->objectives->obj[parserData->stageobjcount]->idx = (yyvsp[(3) - (4)].ival);
	parserData->stageobjcount++;
}
    break;

  case 216:

    {osinstance->instanceData->timeDomain->interval = new TimeDomainInterval();
        }
    break;

  case 217:

    {
		parserData->intervalhorizonON = false;
		parserData->intervalstartON = false;
		printf("Interval not yet supported.\n\n");
}
    break;

  case 222:

    { if(parserData->intervalhorizonON) 
       osilerror( NULL, osinstance, parserData, "too many interval horizon attributes");
		parserData->intervalhorizonON = true; }
    break;

  case 223:

    { if(parserData->intervalstartON) 
       osilerror( NULL, osinstance, parserData, "too many interval start attributes");
		parserData->intervalstartON = true; }
    break;

  case 224:

    {
		if ( *(yyvsp[(2) - (4)].sval) != *(yyvsp[(4) - (4)].sval) ) osilerror( NULL, osinstance, parserData, "start and end quotes are not the same");
		parserData->intervalhorizon = (yyvsp[(3) - (4)].dval);}
    break;

  case 225:

    {
		if ( *(yyvsp[(2) - (4)].sval) != *(yyvsp[(4) - (4)].sval) ) osilerror( NULL, osinstance, parserData, "start and end quotes are not the same");
		parserData->intervalstart = (yyvsp[(3) - (4)].dval);}
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
      yyerror (&yylloc, osinstance, parserData, YY_("syntax error"));
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
	    yyerror (&yylloc, osinstance, parserData, yymsg);
	  }
	else
	  {
	    yyerror (&yylloc, osinstance, parserData, YY_("syntax error"));
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
		      yytoken, &yylval, &yylloc, osinstance, parserData);
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
		  yystos[yystate], yyvsp, yylsp, osinstance, parserData);
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
  yyerror (&yylloc, osinstance, parserData, YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval, &yylloc, osinstance, parserData);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp, yylsp, osinstance, parserData);
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






// user defined functions

void osilerror(YYLTYPE* mytype, OSInstance *osinstance, OSiLParserData* parserData, const char* errormsg ) {
	std::ostringstream outStr;
	std::string error = errormsg;
	error = "PARSER ERROR:  Input is either not valid or well formed: "  + error;
	outStr << error << endl;
	outStr << endl; 
	outStr << "See line number: " << osilget_lineno( scanner) << endl; 
	outStr << "The offending text is: " << osilget_text ( scanner ) << endl; 
	error = outStr.str();
	//osillex_destroy(scanner);
	throw ErrorClass( error);
}//end osilerror() 


void  yygetOSInstance( const char *osil, OSInstance* osinstance, OSiLParserData *parserData) throw (ErrorClass) {
	try {
		parseInstanceHeader( &osil, osinstance, &parserData->osillineno);
		parseInstanceData( &osil, osinstance, &parserData->osillineno);	
		/** at this point here we have parsed everything through <linearConstraint coefficient>
		 *	we have done so without bison and just moved the pointer on osil to point to what is past
		 *	the linear part	
		 * call the flex scanner and start scanning the nonlinear part of the problem
		 */	
		osil_scan_string( osil, scanner );
		osilset_lineno (parserData->osillineno , scanner );
		//
		// call the Bison parser
		//
		if(  osilparse( osinstance,  parserData) != 0) {
			throw ErrorClass(  "Error parsing the OSiL");
		}
	}
	catch(const ErrorClass& eclass){
		throw ErrorClass(  eclass.errormsg); 
	}
}//end yygetOSInstance

bool isnewline(char c, int* osillineno){
	if(c != '\n') return false;
	(*osillineno)++;
	return true;
}//end isnewline()

bool parseInstanceHeader( const char **p, OSInstance *osinstance, int* osillineno){
	//
	*osillineno = 1;
	const char *pchar = *p;
	// create a char array that holds the instance header information
	const char *startInstanceHeader = "<instanceHeader";
	const char *endInstanceHeader = "</instanceHeader";
	const char *startName = "<name";
	const char *endName = "</name";
	const char *startSource = "<source";
	const char *endSource = "</source";
	const char *startDescription = "<description";
	const char *endDescription = "</description";
	const char *pinstanceHeadStart = strstr(pchar, startInstanceHeader);
	char *pelementText = NULL;
	const char *ptemp = NULL;
	int elementSize;
	if(pinstanceHeadStart == NULL) {  osilerror_wrapper( pchar,osillineno,"<instanceHeader> element missing"); return false;}
	// increment the line number counter if there are any newlines between the start of
	// the osil string and pinstanceHeadStart
	int	kount = pinstanceHeadStart - pchar;
	while( kount-- > 0) if(*(pchar++) == '\n') 	(*osillineno)++;
	// important! pchar now points to the '<' in <instanceHeader
	// that is both pinstanceHeadStart and pchar point to the same thing
 	// 
 	// move to the end of <instanceHeader
 	pchar+=15;
	// burn any whitespace
	for( ; ISWHITESPACE( *pchar) || isnewline( *pchar, osillineno); pchar++ ) ;
	// pchar better be pointing to the '>' in the <instanceHeader> element
	// or to /> if we have <instanceHeader />
	if( *pchar == '/'){
		pchar++;
		// better point to a '>'
		if(*pchar != '>') {  osilerror_wrapper( pchar,osillineno,"improperly formed <instanceHeader> element"); return false;}
		// there is no instanceHeader data
		pchar++;
		return true;
	}
	else{
		// pchar better be '>' or there is an error
		if(*pchar != '>') {  osilerror_wrapper( pchar,osillineno,"improperly formed <instanceHeader> element"); return false;}
	}
	pchar++;
	// we are pointing to the character after <instanceHeader>
	//
	//
	//
	// process the <name> element which is optional
	//
	// first burn any whitespace
	for( ; ISWHITESPACE( *pchar) || isnewline( *pchar, osillineno); pchar++ ) ;
	// if, present we should be pointing to <name element if there -- it is not required
	//remember where we are
	*p = pchar;
	while(*startName++  == *pchar) pchar++;
	if( (pchar - *p)  != 5) {
		//reset pchar
		pchar = *p;
	}
	else{
	// we have a name element, process the text
	// burn the whitespace
		for( ; ISWHITESPACE( *pchar) || isnewline( *pchar, osillineno); pchar++ ) ;	
		if( *pchar == '/'){
			pchar++;
			// better point to a '>'
			if(*pchar != '>') {  osilerror_wrapper( pchar,osillineno,"improperly formed <name> element"); return false;}
		}
		else{
			// pchar better be '>' or there is an error
			if(*pchar != '>') {  osilerror_wrapper( pchar,osillineno,"improperly formed <name> element"); return false;}
			pchar++;
			// proces <name> element text
			// there better be a </name
			ptemp = strstr( pchar, endName);
			if( ptemp == NULL) {  osilerror_wrapper( pchar,osillineno,"improperly formed </name> element"); return false;}
			elementSize = ptemp - pchar;
			pelementText = new char[ elementSize + 1];
			strncpy(pelementText, pchar, elementSize);
			pelementText[ elementSize] = '\0';
			osinstance->instanceHeader->name = pelementText;
			//garbage collection
			delete [] pelementText;
			// move pchar up to the end of </name
			while(elementSize-- > 0){
				if(*pchar++ == '\n') (*osillineno)++;
			}
			// pchar should now be pointing to the start of </name
			// move to first char after </name
			pchar += 6;
			// get rid of the whitespace
			for( ; ISWHITESPACE( *pchar) || isnewline( *pchar, osillineno); pchar++ ) ;	
			// we better have the '>' for the end of name
			if(*pchar++ != '>'){  osilerror_wrapper( pchar,osillineno,"improperly formed </name> element"); return false;}
		}
	}// end of else after discovering a name element
	//done processing name element
	//
	//
	// process the <source> element which is optional
	//
	// first burn any whitespace
	for( ; ISWHITESPACE( *pchar) || isnewline( *pchar, osillineno); pchar++ ) ;
	// if, present we should be pointing to <source element if there -- it is not required
	*p = pchar;
	while(*startSource++  == *pchar) pchar++;
	if(pchar - *p != 7) {
		//reset pchar
		pchar = *p;
	}
	else{
	// we have a source element, process the text
	// burn the whitespace
		for( ; ISWHITESPACE( *pchar) || isnewline( *pchar, osillineno); pchar++ ) ;	
		if( *pchar == '/'){
			pchar++;
			// better point to a '>'
			if(*pchar != '>') {  osilerror_wrapper( pchar,osillineno,"improperly formed <source> element"); return false;}
		}
		else{
			// pchar better be '>' or there is an error
			if(*pchar != '>') {  osilerror_wrapper( pchar,osillineno,"improperly formed <source> element"); return false;}
			pchar++;
			// proces <source> element text
			// there better be a </source
			ptemp = strstr( pchar, endSource);
			if( ptemp == NULL) {  osilerror_wrapper( pchar,osillineno,"improperly formed </source> element"); return false;}
			elementSize = ptemp - pchar;
			pelementText = new char[ elementSize + 1];
			strncpy(pelementText, pchar, elementSize);
			pelementText[ elementSize] = '\0';
			osinstance->instanceHeader->source = pelementText;
			//garbage collection
			delete [] pelementText;
			// move pchar up to the end of </source
			while(elementSize-- > 0){
				if(*pchar++ == '\n') (*osillineno)++;
			}
			// pchar should now be pointing to the start of </source
			// move to first char after </source
			pchar += 8;
			// get rid of the whitespace
			for( ; ISWHITESPACE( *pchar) || isnewline( *pchar, osillineno); pchar++ ) ;	
			// we better have the '>' for the end of source
			if(*pchar++ != '>'){  osilerror_wrapper( pchar,osillineno,"improperly formed </source> element"); return false;}
		}
	}// end of else after discovering a source element
	//done processing <source> element
	//
	//
	//process the <description> element
	//
	// first burn any whitespace
	for( ; ISWHITESPACE( *pchar) || isnewline( *pchar, osillineno); pchar++ ) ;
	// if, present we should be pointing to <description element if there -- it is not required
	*p = pchar;
	while(*startDescription++  == *pchar) pchar++;
	if( (pchar - *p) != 12) {
		//reset pchar
		pchar = *p;
	}
	else{
	// we have a description element, process the text
	// burn the whitespace
		for( ; ISWHITESPACE( *pchar) || isnewline( *pchar, osillineno); pchar++ ) ;	
		if( *pchar == '/'){
			pchar++;
			// better point to a '>'
			if(*pchar != '>') {  osilerror_wrapper( pchar,osillineno,"improperly formed <description> element"); return false;}
		}
		else{
			// pchar better be '>' or there is an error
			if(*pchar != '>') {  osilerror_wrapper( pchar,osillineno,"improperly formed <description> element"); return false;}
			pchar++;
			// proces <source> element text
			// there better be a </description
			ptemp = strstr( pchar, endDescription);
			if( ptemp == NULL) {  osilerror_wrapper( pchar,osillineno,"improperly formed </description> element"); return false;}
			elementSize = ptemp - pchar;
			pelementText = new char[ elementSize + 1];
			strncpy(pelementText, pchar, elementSize);
			pelementText[ elementSize] = '\0';
			osinstance->instanceHeader->description = pelementText;
			//garbage collection
			delete [] pelementText;
			// move pchar up to the end of </description
			while(elementSize-- > 0){
				if(*pchar++ == '\n') (*osillineno)++;
			}
			// pchar should now be pointing to the start of </description
			// move to first char after </description
			pchar += 13;
			// get rid of the whitespace
			for( ; ISWHITESPACE( *pchar) || isnewline( *pchar, osillineno); pchar++ ) ;	
			// we better have the '>' for the end of </description>
			if(*pchar++ != '>'){  osilerror_wrapper( pchar,osillineno,"improperly formed </description> element"); return false;}
		}
	}// end of else after discovering a description element
	//done processing <description> element
	//
	// if we are here there must be an </instanceHeader > element
	// burn the whitespace
	for( ; ISWHITESPACE( *pchar) || isnewline( *pchar, osillineno); pchar++ ) ;	
	// we should be pointing to </instanceHeader
	*p = pchar;
	while(*endInstanceHeader++  == *pchar) pchar++;
	if( (pchar - *p) != 16) {  osilerror_wrapper( pchar,osillineno,"improperly formed </instanceHeader> element"); return false;}	
	// pchar now points to the first character after </instanceHeader
	// get rid of white space
	for( ; ISWHITESPACE( *pchar) || isnewline( *pchar, osillineno); pchar++ ) ;	
	// pchar must point to '>' or there is an error
	if(*pchar != '>'){  osilerror_wrapper( pchar,osillineno,"improperly formed </instanceHeader> element"); return false;}	
	pchar++;
	*p = pchar;
	return true;
}//end parseInstanceHeader


bool parseInstanceData( const char **p, OSInstance *osinstance, int* osillineno){
	//
	const char *pchar = *p;
	const char *startInstanceData = "<instanceData";
	// at this point *pchar should be pointing to the first char after the > in </instanceHeader>
	// burn the white space
	for( ; ISWHITESPACE( *pchar) || isnewline( *pchar, osillineno); pchar++ ) ;	
	// pchar should be point to a '<', if not there is an error
	if(*pchar != '<'){  osilerror_wrapper( pchar,osillineno,"improperly formed <instanceData element"); return false;}
	// make sure the element is <instanceData	
	*p = pchar;
	while(*startInstanceData++  == *pchar) pchar++;
	if( (pchar - *p) != 13) {  osilerror_wrapper( pchar,osillineno,"improperly formed <instanceData> element"); return false;}	
	// now burn whitespace
	// pchar must point to '>' or there is an error
	if(*pchar != '>'){  osilerror_wrapper( pchar,osillineno,"improperly formed <instanceData> element"); return false;}	
	pchar++;
	// we are now pointing to the first char after <instanceData>
	// burn any whitespace
	for( ; ISWHITESPACE( *pchar) || isnewline( *pchar, osillineno); pchar++ ) ;	
	// we should be pointing to the '<' char in <variables>
	*p = pchar;
	if( parseVariables( p, osinstance, osillineno) != true) {throw ErrorClass("error in parse variables");}
	if( parseObjectives( p, osinstance, osillineno) != true)  throw ErrorClass("error in parse objectives");
	if( parseConstraints( p, osinstance, osillineno) != true) throw ErrorClass("error in parse Constraints");
	if( parseLinearConstraintCoefficients( p, osinstance, osillineno) != true) throw ErrorClass("error in parse ConstraintCoefficients");
	
	//
	return true;
}// end parseInstanceData


bool parseVariables( const char **p,  OSInstance *osinstance, int* osillineno){
	clock_t start, finish;
	//double duration;
	int ki, numChar;
	char *attTextEnd;
	const char *ch = *p;
	start = clock(); 
	const char *c_numberOfVariables = "numberOfVariables";
	const char *startVariables = "<variables";
	const char *endVariables = "</variables";
	const char *startVar = "<var";
	const char *endVar = "</var";
	// the attributes
	char *attText = NULL;
	const char *name = "name";
	const char *initString = "initString";
	const char *type = "type";
	const char *mult = "mult";
	// others
	int i;
	int varcount = 0;
	int numberOfVariables = 0;
// variable attribute boolean variables
	bool varlbattON  = false;
	bool varubattON = false ;
	bool vartypeattON  = false;
	bool varnameattON = false ;
	bool varinitattON = false ;
	bool varinitStringattON = false ;
	bool varmultattON = false;
	bool foundVar = false;
	//
	// start parsing
	*p = ch;
	while(*startVariables++  == *ch) ch++;
	if( (ch - *p) != 10) {  osilerror_wrapper( ch,osillineno,"incorrect <variables tag>"); return false;}
	// find numberOfVariables attribute
	// eat the white space
	for( ; ISWHITESPACE( *ch) || isnewline( *ch, osillineno); ch++ ) ;
	*p = ch;
	while(*c_numberOfVariables++  == *ch) ch++;
	if( (ch - *p) != 17) {  osilerror_wrapper( ch,osillineno,"incorrect numberOfVariables attribute in <variables tag>"); return false;}	
	// buf_index should be pointing to the first character after numberOfVariables
	GETATTRIBUTETEXT;
	ch++;
	numberOfVariables = atoimod1( osillineno, attText, attTextEnd);
	delete [] attText;
	if(numberOfVariables <= 0) {
		osilerror_wrapper( ch,osillineno,"there must be at least one variable"); return false;
	}
	osinstance->instanceData->variables->numberOfVariables = numberOfVariables;
	osinstance->instanceData->variables->var = new Variable*[ numberOfVariables];
	for(i = 0; i < numberOfVariables; i++){
		osinstance->instanceData->variables->var[ i] = new Variable();
	} 
	// get rid of white space after the numberOfVariables element
	for( ; ISWHITESPACE( *ch) || isnewline( *ch, osillineno); ch++ )                     
	// since there must be at least one variable,  this element must end with > 
	// better have an > sign or not valid
	if(*ch != '>' ) {  osilerror_wrapper( ch,osillineno,"variables element does not have a proper closing >"); return false;}
	ch++;
	// get rid of white space
	for( ; ISWHITESPACE( *ch) || isnewline( *ch, osillineno); ch++ ) ;
	// now loop over the var elements, there must be at least one var element
	*p = ch;                                            
	while(*startVar++  == *ch) ch++;
	if( (ch - *p) ==  4) foundVar = true;
		else {  osilerror_wrapper( ch,osillineno,"there must be at least one <var> element"); return false;}
	startVar -= 5;
	while(foundVar){
		varlbattON  = false;
		varubattON = false ;
		vartypeattON  = false;
		varnameattON = false ;
		varinitattON = false ; 
		varinitStringattON = false ;
		varmultattON = false;
		foundVar = false;
		// assume we are pointing to the first character after the r in <var
		// it should be whitespace
		for( ; ISWHITESPACE( *ch) || isnewline( *ch, osillineno); ch++ );
		while(*ch != '/' && *ch != '>'){
			switch (*ch) {
			case 'n':
				*p = ch;
				while(*name++  == *ch) ch++;
				if( (ch - *p) != 4 ) {  osilerror_wrapper( ch,osillineno,"error in variables name attribute"); return false;}
				name -= 5;
				if(varnameattON == true) {  osilerror_wrapper( ch,osillineno,"error too many variable name attributes"); return false;}
				varnameattON = true;
				GETATTRIBUTETEXT;
				osinstance->instanceData->variables->var[varcount]->name=attText;
				delete [] attText;
				//printf("ATTRIBUTE = %s\n", attText);
				break;
			case 'i':
				*p = ch;
				while(*initString++  == *ch) ch++;
				// if i < 4 there is an error
				// if i = 4 we matched init
				// if i = 10 we matched initString
				if( ( (ch - *p) != 4)  && ( (ch - *p) != 10)) {  osilerror_wrapper( ch,osillineno,"error in variables init or initString attribute"); return false;}
				if((ch - *p) == 4){
					if(varinitattON == true) {  osilerror_wrapper( ch,osillineno,"error too many variable init attributes"); return false;}
					varinitattON = true;
					GETATTRIBUTETEXT;
					//printf("ATTRIBUTE = %s\n", attText);
					osinstance->instanceData->variables->var[varcount]->init=atofmod1( osillineno,attText, attTextEnd);
					delete [] attText;
					initString -= 5;
				}
				else{
					if(varinitStringattON == true) {  osilerror_wrapper( ch,osillineno,"error too many variable initString attributes"); return false;}
					varinitStringattON = true;
					GETATTRIBUTETEXT;
					//printf("ATTRIBUTE = %s\n", attText);
					osinstance->instanceData->variables->var[varcount]->initString=attText;
					delete [] attText;
					initString -= 11;
				}
				break;
			case 't':
				*p = ch;
				while(*type++  == *ch) ch++;
				if( (ch - *p) != 4) {  osilerror_wrapper( ch,osillineno,"error in variables type attribute"); return false;}
				type -= 5;
				if(vartypeattON == true) {  osilerror_wrapper( ch,osillineno,"error too many variable type attributes"); return false;}
				vartypeattON = true;
				GETATTRIBUTETEXT;
				if( strchr("CBIS", attText[0]) == NULL ) {  osilerror_wrapper( ch,osillineno,"variable type not C,B,I, or S"); return false;}
				osinstance->instanceData->variables->var[varcount]->type = attText[0];
				delete [] attText;
				break;
			case 'l':
				ch++;
				if(*ch++ != 'b') {  osilerror_wrapper( ch,osillineno,"error in variables lower bound attribute"); return false;}
				if(varlbattON == true) {  osilerror_wrapper( ch,osillineno,"error too many variable lb attributes"); return false;}
				varlbattON = true;
				GETATTRIBUTETEXT;
				osinstance->instanceData->variables->var[varcount]->lb = atofmod1( osillineno,attText, attTextEnd);
				delete [] attText;
				//printf("ATTRIBUTE = %s\n", attText);
				break;
			case 'u':
				ch++;
				if(*ch++ != 'b') {  osilerror_wrapper( ch,osillineno,"error in variables upper bound attribute"); return false;}
				if(varubattON == true) {  osilerror_wrapper( ch,osillineno,"error too many variable ub attributes"); return false;}
				varubattON = true;
				GETATTRIBUTETEXT;
				osinstance->instanceData->variables->var[varcount]->ub = atofmod1( osillineno,attText, attTextEnd);
				delete [] attText;
				//printf("ATTRIBUTE = %s\n", attText);
				break;
			case 'm':
				*p = ch;
				while(*mult++  == *ch) ch++;
				if( (ch - *p) != 4) {  osilerror_wrapper( ch,osillineno,"error in variables mult attribute"); return false;}
				mult -= 5;
				if(varmultattON == true) {  osilerror_wrapper( ch,osillineno,"error too many variable mult attributes"); return false;}
				varmultattON = true;
				GETATTRIBUTETEXT;
				delete [] attText;
				//printf("ATTRIBUTE = %s\n", attText);
				break;
			case ' ':
				break;
			case '\n':
				(*osillineno)++;
				break;
			case '\t':
				break;
			case '\r':
				break;
			default:
				{  osilerror_wrapper( ch,osillineno,"invalid attribute character"); return false;}
				break;
			}
			ch++;
		}
		//
		// assume all the attributes have been processed
		// must have either /> or > and then whitespace and </var whitespace>
		if( *ch != '/' && *ch != '>') {  osilerror_wrapper( ch,osillineno,"incorrect end of <var> element"); return false;}
		if(*ch == '/'){
			ch++;
			if(*ch != '>') {  osilerror_wrapper( ch,osillineno,"incorrect end of <var> element"); return false;}
			// get rid of whitespace
			ch++;
			for(; ISWHITESPACE( *ch) || isnewline( *ch, osillineno); ch++ );
			// either have another <var> element or foundVar = false;
			*p = ch;
			while(*startVar++  == *ch) ch++;
			if( (ch - *p) == 4) {
				foundVar = true;
				startVar -= 5;
			}
			else {
				foundVar = false;
				ch = *p;
			}
		}
		else{
			// the buf_index is the > at the end of the var element 
			// double check to make sure it really is a >
			if(*ch != '>') {  osilerror_wrapper( ch,osillineno,"improper ending to a <var> element"); return false;}
			// look for </var
			// fist get rid of white space
			ch++;
			for(; ISWHITESPACE( *ch) || isnewline( *ch, osillineno); ch++ );
			// we should be at </var or there is an error
			*p = ch;
			while(*endVar++  == *ch) ch++;
			endVar -= 6;
			if( (ch - *p) != 5) {  osilerror_wrapper( ch,osillineno,"</var> element missing"); return false;}
			// burn off the whitespace
			for(; ISWHITESPACE( *ch) || isnewline( *ch, osillineno); ch++ );
			// better have an > to end </var
			if(*ch++ != '>') {  osilerror_wrapper( ch,osillineno,"</var> element missing >"); return false;}
			// look for a new <var> element
			// get rid of whitespace
			ch++;
			for(; ISWHITESPACE( *ch) || isnewline( *ch, osillineno); ch++ );
			// either have another <var> element or foundVar = false;
			*p = ch;
			while(*startVar++  == *ch) ch++;
			if( (ch - *p) == 4) {
				foundVar = true;
				startVar -= 5;
			}
			else {
				foundVar = false;
				ch = *p;
			}
		}
		if( (varcount == numberOfVariables - 1) && (foundVar == true) ) {   osilerror_wrapper( ch,osillineno,"attribute numberOfVariables is less than actual number found");  return false;}
		varcount++;
	}
	if(varcount < numberOfVariables) {  osilerror_wrapper( ch,osillineno,"attribute numberOfVariables is greater than actual number found");   return false;}
	// get the </variables> tag
	*p = ch;
	while(*endVariables++  == *ch) ch++;
	if( (ch - *p) != 11) {   osilerror_wrapper( ch,osillineno,"cannot find </varialbes> tag"); return false;}
	for(; ISWHITESPACE( *ch) || isnewline( *ch, osillineno); ch++ );	
	// better have >
	if(*ch != '>') {   osilerror_wrapper( ch,osillineno,"improperly formed </variables> tag"); return false;}
	ch++;
	finish = clock();
	//duration = (double) (finish - start) / CLOCKS_PER_SEC; 
	//printf("TIME TO PARSE VARIABLES = %f\n", duration);
	*p = ch;
	return true;
}//end parseVariables


bool parseObjectives( const char **p, OSInstance *osinstance, int* osillineno){
	clock_t start, finish;
	//double duration;
	int ki, numChar;
	char *attTextEnd;
	const char *ch = *p;
	start = clock();
	const char *c_numberOfObjectives = "numberOfObjectives";
	const char *startObjectives = "<objectives";
	const char *endObjectives = "</objectives";
	const char *startObj = "<obj";
	const char *endObj = "</obj";
	// attributes
	char *attText = NULL;
	const char *constant = "constant";
	const char *maxOrMin = "maxOrMin";
	const char *numberOfObjCoef = "numberOfObjCoeff";
	const char *weight = "weight";
	const char *name = "name";
	const char *mult = "mult";
	// others
	int i;
	// objective function attribute boolean variables
	bool objmaxOrMinattON = false;
	bool objnameattON = false;
	bool objconstantattON = false;
	bool objweightattON = false;
	bool objmultattON = false;
	bool objnumberOfObjCoefattON = false;
	int objcount = 0;
	int numberOfObjectives;
	bool foundObj;
	// start parsing
	// burn white space
	for( ; ISWHITESPACE( *ch) || isnewline( *ch, osillineno); ch++ ) ;
	// if, present we should be pointing to <objectives element if there -- it is not required
	*p = ch;
	while( *startObjectives++  == *ch) ch++;
	if( (ch - *p) != 11) {
		//  note if we are here even though ch > *p we want to return *p
		return true;
	}
	// find numberOfObjectives attribute -- it is valid for this attribute to be missing. 
	// However if the  number attribute is missing assume it is	1 
	// eat the white space
	for( ; ISWHITESPACE( *ch) || isnewline( *ch, osillineno); ch++ ) ;
	// we just ate the white space. If numberOfObjectives is missing we assume it is 1
	// we therefore must have > char
	if(*ch == '>'){
		numberOfObjectives = 1;
		//ch++;
	}
	else{
		*p = ch;
		while( *c_numberOfObjectives++  == *ch) ch++;
		if( (ch - *p) != 18) {  osilerror_wrapper( ch,osillineno,"incorrect numberOfObjectives attribute in <objectives> tag"); return false;}	
		GETATTRIBUTETEXT;
		numberOfObjectives = atoimod1( osillineno, attText, attTextEnd);
		delete [] attText;
		ch++;
	}
	if(numberOfObjectives > 0){
		// get rid of white space after the numberOfObjectives attribute
		for( ; ISWHITESPACE( *ch) || isnewline( *ch, osillineno); ch++ ) ;
		// we must have an >
		/*if(*ch == '/'){
			ch++;
			if( *ch++ != '>') {  osilerror_wrapper( ch,osillineno,"the objectives element does not have a proper closing"); return false; }
			else{
				if(numberOfObjectives > 0){   osilerror_wrapper( ch,osillineno,"numberOfObjectives positive but there are no objectives"); return false;}
				return false;
			}
		}*/
		//  we better have an > 
		if( *ch++ != '>') {  osilerror_wrapper( ch,osillineno,"the objectives element does not have a proper closing"); return false;} 
		osinstance->instanceData->objectives->numberOfObjectives = numberOfObjectives;
		osinstance->instanceData->objectives->obj = new Objective*[ numberOfObjectives];
		for(i = 0; i < numberOfObjectives; i++){
			osinstance->instanceData->objectives->obj[ i] = new Objective();
		} 	
	// get rid of white space after the <objectives> element
	for( ; ISWHITESPACE( *ch) || isnewline( *ch, osillineno); ch++ ) ;
	// now loop over the obj elements, there must be at least one obj element
	*p = ch;
	while( *startObj++  == *ch) ch++;
	if( (ch - *p) == 4) foundObj = true;
		else {  osilerror_wrapper( ch,osillineno,"there must be at least one <obj> element"); return false;}
	startObj -= 5;
	start = clock();	
	while(foundObj){
		objmaxOrMinattON = false;
		objnameattON = false;
		objconstantattON = false;
		objweightattON = false;
		objmultattON = false;
		objnumberOfObjCoefattON = false;
		// assume we are pointing to the first character after the r in <obj
		// it should be a space so let's increment ch
		ch++;
		while(*ch != '/' && *ch != '>'){
			switch (*ch) {
			case 'n':
				if( *(ch+1) == 'u'){
					*p = ch;
					while( *numberOfObjCoef++  == *ch) ch++;
					numberOfObjCoef -= 16;
					if( ( (ch - *p) != 15)  ) {  osilerror_wrapper( ch,osillineno,"error in objective numberOfObjCoef attribute"); return false;}
					else{
						if(objnumberOfObjCoefattON == true) {  osilerror_wrapper( ch,osillineno,"error too many obj numberOfObjCoefatt attributes"); return false;}
						objnumberOfObjCoefattON = true;
						GETATTRIBUTETEXT;
						//printf("ATTRIBUTE = %s\n", attText);
						osinstance->instanceData->objectives->obj[objcount]->numberOfObjCoef=atoimod1( osillineno,attText, attTextEnd);
						osinstance->instanceData->objectives->obj[objcount]->coef = new ObjCoef*[osinstance->instanceData->objectives->obj[ objcount]->numberOfObjCoef];
						for(int i = 0; i < osinstance->instanceData->objectives->obj[ objcount]->numberOfObjCoef; i++)osinstance->instanceData->objectives->obj[objcount]->coef[i] = new ObjCoef();
						delete [] attText;
					}
				}
				else{
					*p = ch;
					while( *name++  == *ch) ch++;
					name -= 5;
					if( ( (ch - *p) != 4)  ) {  osilerror_wrapper( ch,osillineno,"error in objective name attribute"); return false;}
					else{
						if(objnameattON == true) {  osilerror_wrapper( ch,osillineno,"error too many obj name attributes"); return false;}
						objnameattON = true;
						GETATTRIBUTETEXT;
						//printf("ATTRIBUTE = %s\n", attText);
						osinstance->instanceData->objectives->obj[objcount]->name=attText;
						delete [] attText;
					}
				}
				break;
			case 'c':
				*p = ch;
				while( *constant++  == *ch) ch++;
				constant -= 9;	
				if( ( (ch - *p) != 8)  ) {  osilerror_wrapper( ch,osillineno,"error in objective constant attribute"); return false;}
				else{
					if(objconstantattON == true) {  osilerror_wrapper( ch,osillineno,"error too many obj constant attributes"); return false;}
					objconstantattON = true;
					GETATTRIBUTETEXT;
					//printf("ATTRIBUTE = %s\n", attText);
					osinstance->instanceData->objectives->obj[objcount]->constant=atofmod1( osillineno,attText, attTextEnd);
					delete [] attText;
				}
				break;
			case 'w':
				*p = ch;
				while( *weight++  == *ch) ch++;
				weight -= 7;
				if( ( (ch - *p) != 6)  ) {  osilerror_wrapper( ch,osillineno,"error in objective weight attribute"); return false;}
				else{
					if(objweightattON == true) {  osilerror_wrapper( ch,osillineno,"error too many obj weight attributes"); return false;}
					objweightattON = true;
					GETATTRIBUTETEXT;
					//printf("ATTRIBUTE = %s\n", attText);
					osinstance->instanceData->objectives->obj[objcount]->weight=atofmod1( osillineno,attText, attTextEnd);
					delete [] attText;
				}
				break;
			case 'm':
				if(*(ch+1) == 'a'){
					*p = ch;
					while( *maxOrMin++  == *ch) ch++;
					maxOrMin -= 9;
					if( ( ( ch - *p)  != 8)  ) {  osilerror_wrapper( ch,osillineno,"error in objective maxOrMin attribute"); return false;}
					else{
						if(objmaxOrMinattON == true) {  osilerror_wrapper( ch,osillineno,"error too many obj maxOrMin attributes"); return false;}
						objmaxOrMinattON = true;
						GETATTRIBUTETEXT;
						//printf("ATTRIBUTE = %s\n", attText);
						if( (strcmp("max", attText) != 0 ) && (strcmp("min", attText) != 0 ) ){osilerror_wrapper( ch,osillineno,"maxOrMin attribute in objective must be a max or min"); return false;}
						osinstance->instanceData->objectives->obj[objcount]->maxOrMin = attText;
						delete [] attText;
					}
				}
				else{
					*p = ch;
					while( *mult++  == *ch) ch++;
					mult -= 5;
					if( ( (ch - *p) != 4)  ) {  osilerror_wrapper( ch,osillineno,"error in objective mult attribute"); return false;}
					else{
						if(objmultattON == true) {  osilerror_wrapper( ch,osillineno,"error too many obj mult attributes"); return false;}
						objmultattON = true;
						GETATTRIBUTETEXT;
						//printf("ATTRIBUTE = %s\n", attText);
						//osinstance->instanceData->objectives->obj[objcount]->name=attText;
						delete [] attText;
					}
				}
				break;
			// come back and do multiplicity
			case ' ':
				break;
			case '\n':
				(*osillineno)++;
				break;
			case '\t':
				break;
			case '\r':
				break;
			default:
				 
				osilerror_wrapper( ch,osillineno,"invalid attribute character");
				return false;
				break;
			}
			ch++;
		}
		//
		// assume all the attributes have been processed
		// must have either /> or > and then whitespace and </obj whitespace>
		if( *ch != '/' && *ch != '>') {   osilerror_wrapper( ch,osillineno,"incorrect end of <obj> element"); return false;}
		if(*ch == '/'){
			ch++;
			if(*ch != '>') {  osilerror_wrapper( ch,osillineno,"incorrect end of <obj> element"); return false;}
			// get rid of whitespace
			ch++;
			for(; ISWHITESPACE( *ch) || isnewline( *ch, osillineno); ch++ );
			// either have another <obj> element or foundObj = false;
			for(i = 0; startObj[i]  == *ch; i++, ch++);
			if(i == 4) foundObj = true;
				else foundObj = false;
		}
		else{
			// the ch is the > at the end of the obj element
			// double check to make sure it really is a >
			if(*ch != '>') {  osilerror_wrapper( ch,osillineno,"improper ending to a <obj> element"); return false;}
			// look for </obj
			// fist get rid of white space
			ch++;
			// first get the <coef> elements
			parseObjCoef(&ch,  objcount, osinstance, osillineno);
			for(; ISWHITESPACE( *ch) || isnewline( *ch, osillineno); ch++ );
			// we should be at </obj or there is an error
			for(i = 0; endObj[i]  == *ch; i++, ch++);
			if(i != 5) {  osilerror_wrapper( ch,osillineno,"</obj> element missing"); return false;}
			// burn off the whitespace
			for(; ISWHITESPACE( *ch) || isnewline( *ch, osillineno); ch++ );
			// better have an > to end </obj
			if(*ch++ != '>'){   osilerror_wrapper( ch,osillineno,"</obj> element missing >"); return false;}
			// look for a new <obj> element
			// get rid of whitespace
			for(; ISWHITESPACE( *ch) || isnewline( *ch, osillineno); ch++ );
			// either have another <obj> element or foundObj = false;
			for(i = 0; startObj[i]  == *ch; i++, ch++);
			if(i == 4) foundObj = true;
				else foundObj = false;
		}
		if( (objcount == numberOfObjectives - 1) && (foundObj == true)) {  osilerror_wrapper( ch,osillineno,"attribute numberOfObjectives is less than actual number found"); return false;}
		objcount++;
	}
	if(objcount < numberOfObjectives) {  osilerror_wrapper( ch,osillineno,"attribute numberOfObjectives is greater than actual number found"); return false;}
	ch -= i;
	// get the </objectives> tag
	for(i = 0; endObjectives[i]  == *ch; i++, ch++);
	if(i != 12) {  osilerror_wrapper( ch,osillineno, "cannot find </objectives> tag"); return false; }
	for(; ISWHITESPACE( *ch) || isnewline( *ch, osillineno); ch++ );	
	// better have >
	if(*ch != '>') {  osilerror_wrapper( ch,osillineno,"improperly formed </objectives> tag"); return false;}	
	ch++;
	} // finish the (if numberOfObjectives > 0)
	else{
		// error if the number is negative
		if(numberOfObjectives < 0) {  osilerror_wrapper( ch,osillineno,"cannot have a negative number of objectives"); return false;}
		// if we are here we have exactly 0 objectives 
		// must close with /> or </objectives>
		// get rid of white space
		for(; ISWHITESPACE( *ch) || isnewline( *ch, osillineno); ch++ );
		if( *ch == '/'){
			// better have a >
			ch++;
			if( *ch  != '>') {  osilerror_wrapper( ch,osillineno,"improperly closed objectives tag"); return false;}
			ch++;
		}
		else{
			// if we are here we must have an '>' and then  </objectives> tag
			if( *ch  != '>') {  osilerror_wrapper( ch,osillineno,"improperly closed objectives tag"); return false;}
			ch++;
			// burn white space
			for(; ISWHITESPACE( *ch) || isnewline( *ch, osillineno); ch++ );
			for(i = 0; endObjectives[i]  == *ch; i++, ch++);
			if(i != 12) {  osilerror_wrapper( ch,osillineno, "cannot find </objectives> tag"); return false; }
			for(; ISWHITESPACE( *ch) || isnewline( *ch, osillineno); ch++ );	
			// better have >
			if(*ch != '>') {  osilerror_wrapper( ch,osillineno,"improperly formed </objectives> tag"); return false;}	
			ch++;
		}
	}
	finish = clock();
	//duration = (double) (finish - start) / CLOCKS_PER_SEC; 
	//printf("TIME TO PARSE OBJECTIVES = %f\n", duration);
	*p = ch;
	return true;
}//end parseObjectives

bool parseConstraints( const char **p, OSInstance *osinstance, int* osillineno){
	clock_t start, finish;
	//double duration;
	int ki, numChar;
	char *attTextEnd;
	const char *ch = *p;
	start = clock();	
	const char *c_numberOfConstraints = "numberOfConstraints";
	const char *startConstraints = "<constraints";
	const char *endConstraints = "</constraints";
	const char *startCon = "<con";
	const char *endCon = "</con";
	// attributes
	char *attText = NULL;
	const char *name = "name";
	const char *constant = "constant";
	const char *mult = "mult";
	// others
	int i; 
	int concount = 0;
	int numberOfConstraints = 0;
	// constraint attribute boolean variables
	bool conlbattON = false ;
	bool conubattON  = false;
	bool connameattON = false;
	bool conconstantattON  = false;
	bool conmultattON = false;
	bool foundCon = false;
	// start parsing
	// burn white space
	for( ; ISWHITESPACE( *ch) || isnewline( *ch, osillineno); ch++ ) ;
	// if, present we should be pointing to <constraints element if there -- it is not required
	*p = ch;
	for(i = 0; startConstraints[i]  == *ch; i++, ch++);
	while( *startConstraints++  == *ch) ch++;
	if( (ch - *p) != 12) {
		//  *p is the correct value for the pointer
		return true;
	}
	// find numberOfConstraints attribute
	// eat the white space
	for( ; ISWHITESPACE( *ch) || isnewline( *ch, osillineno); ch++ ) ;
	*p = ch;
	while( *c_numberOfConstraints++  == *ch) ch++;
	if( (ch - *p) != 19) {  osilerror_wrapper( ch,osillineno,"incorrect numberOfConstraints attribute in <constraints> tag"); return false;}	
	// ch should be pointing to the first character after numberOfConstraints
	GETATTRIBUTETEXT;
	ch++;
	numberOfConstraints = atoimod1( osillineno, attText, attTextEnd);
	delete [] attText;
	// key if
	//
	if(numberOfConstraints > 0){
		osinstance->instanceData->constraints->numberOfConstraints = numberOfConstraints;
		osinstance->instanceData->constraints->con = new Constraint*[ numberOfConstraints];
		for(i = 0; i < numberOfConstraints; i++){
			osinstance->instanceData->constraints->con[ i] = new Constraint();
		} 
	// get rid of white space after the numberOfConstraints element
	for( ; ISWHITESPACE( *ch) || isnewline( *ch, osillineno); ch++ ) ;
	//  we better have an > 
	if( *ch++ != '>') {   osilerror_wrapper( ch,osillineno,"the constraints element does not have a proper closing"); return false;} 
	// get rid of white space after the <constraints> element
	for( ; ISWHITESPACE( *ch) || isnewline( *ch, osillineno); ch++ ) ;
	// now loop over the con elements, there must be at least one con element
	*p = ch;
	while( *startCon++  == *ch) ch++;
	if( (ch - *p) == 4) foundCon = true;
		else {  osilerror_wrapper( ch,osillineno,"there must be at least one <con> element"); return false;}
	startCon -= 5;
	while(foundCon){
		conlbattON = false ;
		conubattON  = false;
		connameattON = false;
		conconstantattON  = false;
		conmultattON = false;
		// assume we are pointing to the first character after the n in <con
		// it should be a space so let's increment ch
		for( ; ISWHITESPACE( *ch) || isnewline( *ch, osillineno); ch++ );
		while(*ch != '/' && *ch != '>'){
			switch (*ch) {
			case 'n':
				*p = ch;
				while( *name++  == *ch) ch++;
				if( (ch - *p) != 4) {  osilerror_wrapper( ch,osillineno,"error in constraints name attribute"); return false;}
				if(connameattON == true) {  osilerror_wrapper( ch,osillineno,"error too many con name attributes"); return false;}
				name -= 5;
				connameattON = true;
				GETATTRIBUTETEXT;
				osinstance->instanceData->constraints->con[concount]->name=attText;
				delete [] attText;
				//printf("ATTRIBUTE = %s\n", attText);
				break;
			case 'c':
				*p = ch;
				while( *constant++  == *ch) ch++;
				if( ((ch - *p)  != 8)  ) {  osilerror_wrapper( ch,osillineno,"error in constraint constant attribute"); return false;}
				if(conconstantattON == true) {  osilerror_wrapper( ch,osillineno,"error too many con constant attributes"); return false;}
				constant -= 9;
				conconstantattON = true;
				GETATTRIBUTETEXT;
				//printf("ATTRIBUTE = %s\n", attText);
				osinstance->instanceData->constraints->con[concount]->constant=atofmod1( osillineno,attText, attTextEnd);
				delete [] attText;
				break;
			case 'l':
				ch++;
				if(*ch++ != 'b') {   osilerror_wrapper( ch,osillineno,"error in constraint lb attribute"); return false;}
				if(conlbattON == true) {  osilerror_wrapper( ch,osillineno,"error too many con lb attributes"); return false;}
				conlbattON = true;
				GETATTRIBUTETEXT;
				osinstance->instanceData->constraints->con[concount]->lb = atofmod1( osillineno,attText, attTextEnd);
				delete [] attText;
				//printf("ATTRIBUTE = %s\n", attText);
				break;
			case 'u':
				ch++;
				if(*ch++ != 'b') {  osilerror_wrapper( ch,osillineno,"error in constraint ub attribute"); return false;}
				if(conubattON == true) {  osilerror_wrapper( ch,osillineno,"error too many con ub attributes"); return false;}
				conubattON = true;
				GETATTRIBUTETEXT;
				osinstance->instanceData->constraints->con[concount]->ub = atofmod1( osillineno,attText, attTextEnd);
				delete [] attText;
				//printf("ATTRIBUTE = %s\n", attText);
				break;
			case 'm':
				*p = ch;
				while( *mult++  == *ch) ch++;
				if( (ch - *p) != 4) {  osilerror_wrapper( ch,osillineno,"error in constraints mult attribute"); return false;}
				if(conmultattON == true) {  osilerror_wrapper( ch,osillineno,"error too many con mult attributes"); return false;}
				mult -= 5;
				conmultattON = true;
				GETATTRIBUTETEXT;
				delete [] attText;
				//printf("ATTRIBUTE = %s\n", attText);
				break;
			case ' ':
				break;
			case '\n':
				(*osillineno)++;
				break;
			case '\t':
				break;
			case '\r':
				break;
			default:
				 
				osilerror_wrapper( ch,osillineno,"invalid attribute character");
				return false;
				break;
			}
			ch++;
		}
		//
		// assume all the attributes have been processed
		// must have either /> or > and then whitespace and </con whitespace>
		if( *ch != '/' && *ch != '>') {  osilerror_wrapper( ch,osillineno,"incorrect end of <con> element"); return false;}
		if(*ch == '/'){
			ch++;
			if(*ch != '>') {  osilerror_wrapper( ch,osillineno,"incorrect end of <con> element"); return false;}
			// get rid of whitespace
			ch++;
			for(; ISWHITESPACE( *ch) || isnewline( *ch, osillineno); ch++ );
			// either have another <con> element or foundCon = false;
			*p = ch;
			while( *startCon++  == *ch) ch++;
			if( (ch - *p) == 4){
			 	foundCon = true;
			 	startCon -= 5;
			}
			else{
				foundCon = false;
				ch = *p;
			}
		}
		else{
			// the ch is the > at the end of the con element 
			// double check to make sure it really is a >
			if(*ch != '>') {  osilerror_wrapper( ch,osillineno,"improper ending to a <obj> element"); return false;}
			// look for </con
			// fist get rid of white space
			ch++;
			for(; ISWHITESPACE( *ch) || isnewline( *ch, osillineno); ch++ );
			// we should be at </con or there is an error
			*p = ch;
			while( *endCon++  == *ch) ch++;
			if( (ch - *p) != 5) {  osilerror_wrapper( ch,osillineno,"</con> element missing"); return false;}
			endCon -= 6;
			// burn off the whitespace
			for(; ISWHITESPACE( *ch) || isnewline( *ch, osillineno); ch++ );
			// better have an > to end </con
			if(*ch++ != '>') {  osilerror_wrapper( ch,osillineno,"</con> element missing >"); return false;}
			// look for a new <con> element
			// get rid of whitespace
			ch++;
			for(; ISWHITESPACE( *ch) || isnewline( *ch, osillineno); ch++ );
			// either have another <con> element or foundVar = false;
			*p = ch;
			while( *startCon++  == *ch) ch++;
			if( (ch - *p) == 4){
			 	foundCon = true;
			 	startCon -= 5;
			}
			else{
			 	foundCon = false;
			 	ch = *p;
			}
		}
		if( (concount == numberOfConstraints - 1) && (foundCon == true) ) {  osilerror_wrapper( ch,osillineno,"attribute numberOfConstraints is less than actual number found"); return false;}
		concount++;
	}
	if(concount < numberOfConstraints) {  osilerror_wrapper( ch,osillineno,"attribute numberOfConstraints is greater than actual number found"); return false;}
	// get the </constraints> tag
	*p = ch;
	while( *endConstraints++  == *ch) ch++;
	if( (ch - *p) != 13) {  osilerror_wrapper( ch,osillineno, "cannot find </constraints> tag"); return false;}
	for(; ISWHITESPACE( *ch) || isnewline( *ch, osillineno); ch++ );	
	// better have >
	if(*ch != '>') {  osilerror_wrapper( ch,osillineno,"improperly formed </constraints> tag");	return false;}
	ch++;
	}// end if(numberOfConstraints > 0)
	else{
		// error if the number is negative
		if(numberOfConstraints < 0) {  osilerror_wrapper( ch,osillineno,"cannot have a negative number of constraints"); return false;}
		// if we are here we have numberOfConstraints = 0
		// must close with /> or </constraints>
		// get rid of white space
		for(; ISWHITESPACE( *ch) || isnewline( *ch, osillineno); ch++ );
		if( *ch == '/'){
			// better have a >
			ch++;
			if( *ch  != '>') {  osilerror_wrapper( ch,osillineno,"improperly closed constraints tag"); return false;}
			ch++;
		}
		else{
			// if we are here we must have an '>' and then  </constraints> tag
			if( *ch  != '>') {  osilerror_wrapper( ch,osillineno,"improperly closed constraints tag"); return false;}
			ch++;
			// burn white space
			for(; ISWHITESPACE( *ch) || isnewline( *ch, osillineno); ch++ );
			*p = ch;
			while( *endConstraints++  == *ch) ch++;
			if( (ch - *p) != 13) {  osilerror_wrapper( ch,osillineno, "cannot find </constraints> tag"); return false; }
			for(; ISWHITESPACE( *ch) || isnewline( *ch, osillineno); ch++ );	
			// better have >
			if(*ch != '>') {  osilerror_wrapper( ch,osillineno,"improperly formed </constraints> tag"); return false;}	
			ch++;
		}
	}
	finish = clock();
	//duration = (double) (finish - start) / CLOCKS_PER_SEC; 
	//printf("TIME TO PARSE CONSTRAINTS = %f\n", duration);
	*p = ch;
	return true;
}//end parseConstraints

bool parseLinearConstraintCoefficients( const char **p, OSInstance *osinstance, int* osillineno){;
	int ki, numChar;
	char *attTextEnd;
	const char *ch = *p;	
	const char *c_numberOfValues = "numberOfValues";
	const char *startlinearConstraintCoefficients = "<linearConstraintCoefficients";
	const char *endlinearConstraintCoefficients = "</linearConstraintCoefficients";
	// attributes
	char *attText = NULL;
	// others
	int numberOfValues;
	// start parsing
	// burn white space
	for( ; ISWHITESPACE( *ch) || isnewline( *ch, osillineno); ch++ ) ;
	// if, present we should be pointing to <linearConstraintCoefficients element if there -- it is not required
	*p = ch;
	while( *startlinearConstraintCoefficients++  == *ch) ch++;
	if( (ch - *p) != 29) {
		//reset ch
		ch = *p;
		return true;
	}
	// find numberOfValues attribute
	// eat the white space
	for( ; ISWHITESPACE( *ch) || isnewline( *ch, osillineno); ch++ ) ;
	*p = ch;
	while( *c_numberOfValues++  == *ch) ch++;
	if( (ch - *p) != 14) {  osilerror_wrapper( ch,osillineno,"incorrect numberOfValues attribute in <linearConstraintCoefficients> tag"); return false;}
	// ch should be pointing to the first character after numberOfValues
	GETATTRIBUTETEXT;
	ch++;
	numberOfValues = atoimod1( osillineno, attText, attTextEnd);
	delete [] attText;
	if(numberOfValues <= 0) {  osilerror_wrapper( ch,osillineno,"the number of nonlinear nozeros must be positive"); return false;}
	osinstance->instanceData->linearConstraintCoefficients->numberOfValues = numberOfValues;
	// get rid of white space after the numberOfConstraints element
	for( ; ISWHITESPACE( *ch) || isnewline( *ch, osillineno); ch++ ) ;
	// we should have either an />  OR an >
	if(*ch == '/'){
		ch++;
		if( *ch++ != '>') {  osilerror_wrapper( ch,osillineno,"the linearConstraintCoefficients element does not have a proper closing"); return false;} 
		else{
			if(numberOfValues > 0) {  osilerror_wrapper( ch,osillineno,"numberOfValues positive, but there are no objectives"); return false;}
			return false;
		}		
	}
	//  we better have an > 
	if( *ch++ != '>') {  osilerror_wrapper( ch,osillineno,"the <linearConstraintCoefficients> element does not have a proper closing"); return false;}
	// get rid of white space after the <linearConstraintCoefficients> element
	for( ; ISWHITESPACE( *ch) || isnewline( *ch, osillineno); ch++ ) ;
	if( parseStart( &ch, osinstance, osillineno) != true) return false;
	if( (parseColIdx( &ch, osinstance, osillineno) != true) && ( parseRowIdx( &ch, osinstance, osillineno) != true)) return false;
	if( (parseColIdx( &ch, osinstance, osillineno) == true) && (parseRowIdx( &ch, osinstance, osillineno) == true) ){  osilerror_wrapper( ch,osillineno,"cannot store by both row and column"); return false;}
	if( parseValue( &ch, osinstance, osillineno) != true) return false;
	for( ; ISWHITESPACE( *ch) || isnewline( *ch, osillineno); ch++ ) ;
	// get the </linearConstraintCoefficients> tag
	*p = ch;
	while( *endlinearConstraintCoefficients++  == *ch) ch++;
	if( (ch - *p) != 30) {  osilerror_wrapper( ch,osillineno, "cannot find </linearConstraintCoefficients> tag"); return false;}
	for(; ISWHITESPACE( *ch) || isnewline( *ch, osillineno); ch++ );	
	// better have >
	if(*ch != '>') {  osilerror_wrapper( ch,osillineno,"improperly formed </linearConstraintCoefficients> tag"); return false;}
	ch++;	
	*p = ch;
	return true;
}//end parseLinearConstraintCoefficients

bool parseStart(const char **p, OSInstance *osinstance, int* osillineno){
	clock_t start, finish;
	//double duration;
	const char *ch = *p;
	start = clock(); 
	const char* startStart = "<start";
	const char* endStart = "</start";
	const char* startEl = "<el";
	const char* endEl = "</el";
	int kount = 0;
	int i;
	bool foundEl = false;
	for( ; ISWHITESPACE( *ch) || isnewline( *ch, osillineno); ch++ ) ;
	// if, present we should be pointing to <start element 
	*p = ch;
	while( *startStart++  == *ch) ch++;
	if( (ch - *p) != 6) {
		//reset ch
		ch = *p;
		return false;
	}
	// get rid of white space after <start
	for( ; ISWHITESPACE( *ch) || isnewline( *ch, osillineno); ch++ ) ;
	// we should have either an >
	if(*ch != '>') {  osilerror_wrapper( ch,osillineno,"improperly formed <start> element"); return false;}
	ch++;
	// get rid of white space
	for( ; ISWHITESPACE( *ch) || isnewline( *ch, osillineno); ch++ ) ;
	// look for an <el> -- if none present must have b64 data
	*p = ch;
	while( *startEl++  == *ch) ch++;
	startEl -= 4;
	if( (ch - *p) != 3) {
		//reset ch
		ch = *p;
		// call base64 parse here
		int dataSize = 0;
		char* b64string = parseBase64(&ch, &dataSize, osillineno );
		if( b64string == NULL) {  osilerror_wrapper( ch,osillineno,"<start> must have children or base64 data"); return false;}
		std::string base64decodeddata = Base64::decodeb64( b64string );
		int base64decodeddatalength = base64decodeddata.length();
		int *intvec = NULL;
		osinstance->instanceData->linearConstraintCoefficients->start->el = new int[(base64decodeddatalength/dataSize) ];
		intvec = (int*)&base64decodeddata[0];
		for(i = 0; i < (base64decodeddatalength/dataSize); i++){
			osinstance->instanceData->linearConstraintCoefficients->start->el[ i] = *(intvec++);
		}
		delete [] b64string;
	}
	else{
		foundEl = true;
		osinstance->instanceData->linearConstraintCoefficients->start->el = 
		new int[ std::max( osinstance->instanceData->constraints->numberOfConstraints,
		osinstance->instanceData->variables->numberOfVariables) + 1];
		while(foundEl){
			// start eating white space until an '>' is found,
			for(; ISWHITESPACE( *ch) || isnewline( *ch, osillineno); ch++ );
			if( *ch++ != '>') {  osilerror_wrapper( ch,osillineno,"improperly formed <el> tag"); return false;}
			// eat white space again,
			for(; ISWHITESPACE( *ch) || isnewline( *ch, osillineno); ch++ );
			// okay we better have a number, we will check later
			*p = ch;
			// find the end of the number, it better be an </el>
			// find </el
			while( *ch != '<' && *ch  != EOF){
				ch++;
			}
			// we better have a <, or not valid
			if(*ch != '<') {  osilerror_wrapper( ch,osillineno,"cannot find an </el>"); return false;}
			osinstance->instanceData->linearConstraintCoefficients->start->el[ kount++] = 
			atoimod1( osillineno, *p, ch);
			//printf("number = %s\n", *p);
			// we are pointing to <, make sure there is /el
			*p = ch;
			while( *endEl++  == *ch) ch++;
			endEl -= 5;
			if( (ch - *p) != 4 ) {  osilerror_wrapper( ch,osillineno,"cannot fine an </el>"); return false;}
			// start eating white space until an '>' is found for </el>,
			for(; ISWHITESPACE( *ch) || isnewline( *ch, osillineno); ch++ ) ;
			if( *ch++ != '>') {  osilerror_wrapper( ch,osillineno,"improperly formed </el> tag"); return false;}
			// eat white space again,
			for(; ISWHITESPACE( *ch) || isnewline( *ch, osillineno); ch++ );
			// either have another <el> element or foundEl = false;
			*p = ch;
			while( *startEl++  == *ch) ch++;
			if( (ch - *p)  == 3){
				 foundEl = true;
				 startEl -= 4;
			}
			else{
			 	foundEl = false;
			 	ch = *p;
			}
		}		
	}
	// get the </start> tag
	*p = ch;
	while( *endStart++  == *ch) ch++;
	if( (ch - *p) != 7) {  osilerror_wrapper( ch,osillineno, "cannot find </start> tag"); return false;}
	for(; ISWHITESPACE( *ch) || isnewline( *ch, osillineno); ch++ );	
	// better have >
	if(*ch != '>') {  osilerror_wrapper( ch,osillineno,"improperly formed </start> tag");	return false;}
	ch++;	
	// get the end element
	finish = clock();
	//duration = (double) (finish - start) / CLOCKS_PER_SEC; 
	//printf("TIME TO PARSE STARTS  = %f\n", duration);
	*p = ch;
	osinstance->instanceData->linearConstraintCoefficients->iNumberOfStartElements = kount;
	return true;
}//end parseSart

bool parseRowIdx( const char **p, OSInstance *osinstance, int* osillineno){
	clock_t start, finish;
	//double duration;
	const char *ch = *p;
	start = clock(); 
	const char* startRowIdx = "<rowIdx";
	const char* endRowIdx = "</rowIdx";
	const char* startEl = "<el";
	const char* endEl = "</el";
	int kount = 0;
	int i;
	bool foundEl = false;
	for( ; ISWHITESPACE( *ch) || isnewline( *ch, osillineno); ch++ ) ;
	// if, present we should be pointing to <rowIdx element 
	*p = ch;
	while( *startRowIdx++  == *ch) ch++;
	if( (ch - *p) != 7) {
		//reset ch
		ch = *p;
		return false;
	}
	// get rid of white space after <rowIdx
	for( ; ISWHITESPACE( *ch) || isnewline( *ch, osillineno); ch++ ) ;
	// we should have either an >
	if(*ch != '>') {  osilerror_wrapper( ch,osillineno,"improperly formed <rowIdx> element"); return false;}
	ch++;
	// get rid of white space
	for( ; ISWHITESPACE( *ch) || isnewline( *ch, osillineno); ch++ ) ;
	// look for an <el> -- if none present must have b64 data
	*p = ch;
	while( *startEl++  == *ch) ch++;
	startEl -= 4;
	if( (ch - *p) != 3) {
		//reset ch
		ch = *p;
		// call base64 parse here
		int dataSize = 0;
		char* b64string = parseBase64(&ch, &dataSize, osillineno );
		if( b64string == NULL)  {  osilerror_wrapper( ch,osillineno,"<rowIdx> must have children or base64 data"); return false;}
		std::string base64decodeddata = Base64::decodeb64( b64string );
		int base64decodeddatalength = base64decodeddata.length();
		int *intvec = NULL;
		osinstance->instanceData->linearConstraintCoefficients->rowIdx->el = new int[(base64decodeddatalength/dataSize) ];
		osinstance->instanceData->linearConstraintCoefficients->colIdx->el = NULL;
		intvec = (int*)&base64decodeddata[0];
		for(i = 0; i < (base64decodeddatalength/dataSize); i++){
			osinstance->instanceData->linearConstraintCoefficients->rowIdx->el[ i] = *(intvec++);
			kount++;
		}
		delete [] b64string;
	}
	else{
		foundEl = true;
		// if we are here we are storing the problem by column
		// this means the number of start elements must equal the number of columns + 1
		if( osinstance->instanceData->linearConstraintCoefficients->iNumberOfStartElements != osinstance->instanceData->variables->numberOfVariables  + 1)
		osilerror_wrapper( ch, osillineno,"we are storing in column major format, but number of start elements not equal number of variables + 1");
		osinstance->instanceData->linearConstraintCoefficients->rowIdx->el = new int[ osinstance->instanceData->linearConstraintCoefficients->numberOfValues];
		osinstance->instanceData->linearConstraintCoefficients->colIdx->el = NULL;
		while(foundEl){
			// start munging white space until an '>' is found,
			for(; ISWHITESPACE( *ch) || isnewline( *ch, osillineno); ch++ ) ;
			if( *ch++ != '>') {  osilerror_wrapper( ch,osillineno,"improperly formed <el> tag"); return false;}
			// mung white space again,
			for(; ISWHITESPACE( *ch) || isnewline( *ch, osillineno); ch++ ) ;
			// okay we better have a number, we will check later
			*p = ch;
			// find the end of the number, it better be an </el>
			// find </el
			while( *ch != '<' && *ch  != EOF){
				ch++;
			}
			// we better have a <, or not valid
			if(*ch != '<') {   osilerror_wrapper( ch,osillineno,"cannot find an </el>"); return false;}
			osinstance->instanceData->linearConstraintCoefficients->rowIdx->el[ kount++] = 
			atoimod1( osillineno, *p, ch);
			//printf("number = %s\n", *p);
			// we are pointing to <, make sure there is /el
			*p = ch;
			while( *endEl++  == *ch) ch++;
			endEl -= 5;
			if( (ch - *p)  != 4 ) {  osilerror_wrapper( ch,osillineno,"cannot find an </el>"); return false;}
			// start munging white space until an '>' is found for </el>,
			for(; ISWHITESPACE( *ch) || isnewline( *ch, osillineno); ch++ );
			if( *ch++ != '>') {  osilerror_wrapper( ch,osillineno,"improperly formed </el> tag"); return false;}
			// eat white space again,
			for(; ISWHITESPACE( *ch) || isnewline( *ch, osillineno); ch++ );
			// either have another <el> element or foundEl = false;
			*p = ch;
			while( *startEl++  == *ch) ch++;
			if( (ch - *p) == 3){
				foundEl = true;
				startEl -= 4;
			}
			else{
				foundEl = false;
				ch = *p;
			}
		}
	}
	// get the </rowIdx> tag
	*p = ch;
	while( *endRowIdx++  == *ch) ch++;
	if( (ch - *p) != 8) {  osilerror_wrapper( ch,osillineno, "cannot find </rowIdx> tag"); return false;}
	for(; ISWHITESPACE( *ch) || isnewline( *ch, osillineno); ch++ );	
	// better have >
	if(*ch != '>') {  osilerror_wrapper( ch,osillineno,"improperly formed </rowIdx> tag");}	
	ch++;	
	if(kount > osinstance->instanceData->linearConstraintCoefficients->numberOfValues) { osilerror_wrapper( ch,osillineno,"numberOfLinearCoefficients attribute less than number of row indices found"); return false;}
	if(kount < osinstance->instanceData->linearConstraintCoefficients->numberOfValues) { osilerror_wrapper( ch,osillineno,"numberOfLinearCoefficients attribute greater than number of row indices found"); return false;}
	finish = clock();
	//duration = (double) (finish - start) / CLOCKS_PER_SEC; 
	//printf("TIME TO PARSE ROW INDEXES = %f\n", duration);
	*p = ch;
 	return true;
}//end parseRowIdx


bool parseColIdx( const char **p, OSInstance *osinstance, int* osillineno){
	clock_t start, finish;
	//double duration;
	const char *ch = *p;
	start = clock(); 
	const char* startColIdx = "<colIdx";
	const char* endColIdx = "</colIdx";
	const char* startEl = "<el";
	const char* endEl = "</el";
	int kount = 0;
	int i;
	bool foundEl = false;
	for( ; ISWHITESPACE( *ch) || isnewline( *ch, osillineno); ch++ ) ;
	// if, present we should be pointing to <colIdx element 
	*p = ch;
	while( *startColIdx++  == *ch) ch++;
	if( (ch - *p) != 7) {
		//reset ch
		ch = *p;
		return false;
	}
	// get rid of white space after <colIdx
	for( ; ISWHITESPACE( *ch) || isnewline( *ch, osillineno); ch++ ) ;
	// we should have either an >
	if(*ch != '>') {  osilerror_wrapper( ch,osillineno,"improperly formed <colIdx> element"); return false;}
	ch++;
	// get rid of white space
	for( ; ISWHITESPACE( *ch) || isnewline( *ch, osillineno); ch++ ) ;
	// look for an <el> -- if none present must have b64 data
	*p = ch;
	while( *startEl++  == *ch) ch++;
	startEl -= 4;
	if( (ch - *p) != 3) {
		//reset ch
		ch = *p;
		// call base64 parse here
		int dataSize = 0;
		char* b64string = parseBase64(&ch, &dataSize, osillineno );
		if( b64string == NULL)  {  osilerror_wrapper( ch,osillineno,"<colIdx> must have children or base64 data"); return false;}
		std::string base64decodeddata = Base64::decodeb64( b64string );
		int base64decodeddatalength = base64decodeddata.length();
		int *intvec = NULL;
		osinstance->instanceData->linearConstraintCoefficients->colIdx->el = new int[(base64decodeddatalength/dataSize) ];
		osinstance->instanceData->linearConstraintCoefficients->rowIdx->el = NULL;
		intvec = (int*)&base64decodeddata[0];
		for(i = 0; i < (base64decodeddatalength/dataSize); i++){
			osinstance->instanceData->linearConstraintCoefficients->colIdx->el[ i] = *(intvec++);
			kount++;
		}
		delete [] b64string;
	}
	else{
		foundEl = true;
		// if we are here we are storing the problem by row
		// this means the number of start elements must equal the number of rows
		if(osinstance->instanceData->linearConstraintCoefficients->iNumberOfStartElements != osinstance->instanceData->constraints->numberOfConstraints  + 1)
		osilerror_wrapper( ch, osillineno,"we are storing in row major format, but number of start elements not equal number of rows + 1");
		osinstance->instanceData->linearConstraintCoefficients->colIdx->el = new int[ osinstance->instanceData->linearConstraintCoefficients->numberOfValues];
		osinstance->instanceData->linearConstraintCoefficients->rowIdx->el = NULL;
		while(foundEl){
			// start eating white space until an '>' is found,
			for(; ISWHITESPACE( *ch) || isnewline( *ch, osillineno); ch++ ) ;
			if( *ch++ != '>') {  osilerror_wrapper( ch,osillineno,"improperly formed <el> tag"); return false;}
			// eat white space again,
			for(; ISWHITESPACE( *ch) || isnewline( *ch, osillineno); ch++ ) ;
			// okay we better have a number, we will check later
			*p = ch;
			// find the end of the number, it better be an </el>
			// find </el
			while( *ch != '<' && *ch  != EOF){
				ch++;
			}
			// we better have a <, or not valid
			if(*ch != '<') {  osilerror_wrapper( ch,osillineno,"cannot find an </el>"); return false;}
			osinstance->instanceData->linearConstraintCoefficients->colIdx->el[ kount] = 
			atoimod1( osillineno, *p, ch);
			if(osinstance->instanceData->linearConstraintCoefficients->colIdx->el[ kount]  >= osinstance->instanceData->variables->numberOfVariables){
	 			osilerror_wrapper( ch, osillineno, "variable index exceeds number of variables");
	 		}
			kount++;
			//printf("number = %s\n", *p);
			// we are pointing to <, make sure there is /el
			*p = ch;
			while( *endEl++  == *ch) ch++;
			endEl -= 5;
			if( (ch - *p) != 4 ) {  osilerror_wrapper( ch,osillineno,"cannot fine an </el>"); return false;}
			// start eating white space until an '>' is found for </el>,
			for(; ISWHITESPACE( *ch) || isnewline( *ch, osillineno); ch++ );
			if( *ch++ != '>') {  osilerror_wrapper( ch,osillineno,"improperly formed </el> tag"); return false;}
			// eat white space again,
			for(; ISWHITESPACE( *ch) || isnewline( *ch, osillineno); ch++ );
			// either have another <el> element or foundEl = false;
			*p = ch;
			while( *startEl++  == *ch) ch++;
			if( (ch - *p) == 3){
			 	foundEl = true;
			 	startEl -= 4;
			}
			else{
			 	foundEl = false;
			 	ch = *p;
			}
		}
	}
	// get the </colIdx> tag
	*p = ch;
	while( *endColIdx++  == *ch) ch++;		
	if( (ch - *p) != 8) {  osilerror_wrapper( ch,osillineno, "cannot find </colIdx> tag"); return false;}
	for(; ISWHITESPACE( *ch) || isnewline( *ch, osillineno); ch++ );	
	// better have >
	if(*ch != '>') {  osilerror_wrapper( ch,osillineno,"improperly formed </colIdx> tag"); return false;}	
	ch++;	
	if(kount > osinstance->instanceData->linearConstraintCoefficients->numberOfValues) {  osilerror_wrapper( ch,osillineno,"numberOfLinearCoefficients attribute less than number of column indices found"); return false;}
	if(kount < osinstance->instanceData->linearConstraintCoefficients->numberOfValues) {  osilerror_wrapper( ch,osillineno,"numberOfLinearCoefficients attribute greater than number of column indices found"); return false;}
	finish = clock();
	//duration = (double) (finish - start) / CLOCKS_PER_SEC; 
	//printf("TIME TO PARSE COLUMN INDEXES = %f\n", duration);
	*p = ch;
 	return true;
}//end parseColIdx


bool parseValue( const char **p, OSInstance *osinstance, int* osillineno){
	clock_t start, finish;
	//double duration;
	const char *ch = *p;
	start = clock(); 
	const char* startValue = "<value";
	const char* endValue = "</value";
	const char* startEl = "<el";
	const char* endEl = "</el";
	int kount = 0;
	int i;
	bool foundEl = false;
	for( ; ISWHITESPACE( *ch) || isnewline( *ch, osillineno) ; ch++ ) ;
	// if present we should be pointing to <value element 
	*p = ch;
	while( *startValue++  == *ch) ch++;
	if( (ch - *p) != 6) {
		//reset ch
		ch = *p;
		return false;
	}
	// get rid of white space after <value
	for( ; ISWHITESPACE( *ch) || isnewline( *ch, osillineno) ; ch++ ) ;
	// we should have either an >
	if(*ch != '>') {  osilerror_wrapper( ch,osillineno,"improperly formed <value> element"); return false;}
	ch++;
	// get rid of white space
	for( ; ISWHITESPACE( *ch) || isnewline( *ch, osillineno) ; ch++ ) ;
	// look for an <el> -- if none present must have b64 data
	*p = ch;
	while( *startEl++  == *ch) ch++;
	startEl -= 4;
	if( (ch - *p) != 3) {
		//reset ch
		ch = *p;
		// call base64 parse here
		int dataSize = 0;
		char* b64string = parseBase64(&ch, &dataSize, osillineno );
		if( b64string == NULL)  {  osilerror_wrapper( ch,osillineno,"<start> must have children or base64 data"); return false;};
		std::string base64decodeddata = Base64::decodeb64( b64string );
		int base64decodeddatalength = base64decodeddata.length();
		osinstance->instanceData->linearConstraintCoefficients->value->el = new double[(base64decodeddatalength/dataSize) ];
		int kountChar = 0;
		int kj;
		/* Take care of Lou's memory alignment problem */
		/* dataSize had better equal sizeof( double) or we need to abandon ship */
		if( sizeof( double)  != dataSize ) {  
			osilerror_wrapper( ch, osillineno, 
				"base 64 encoded with a size of double different than on this machine"); 
			return false;
		}	
		union doubleBuffer{
			char memAlign[sizeof(double)];
			double dble;
		};
		doubleBuffer dbuf;
		for(i = 0; i < (base64decodeddatalength/dataSize); i++){
			for(kj = 0; kj < dataSize; kj++){
				dbuf.memAlign[ kj] = base64decodeddata[kountChar];
				kountChar++;
			}
			osinstance->instanceData->linearConstraintCoefficients->value->el[ i] = dbuf.dble;
			std::cout << dbuf.dble << std::endl;
			kount++;
		}
		delete [] b64string;
	}
	else{
		foundEl = true;
		osinstance->instanceData->linearConstraintCoefficients->value->el = 
			new double[ osinstance->instanceData->linearConstraintCoefficients->numberOfValues];
		while( foundEl){
			// start eat white space until an '>' is found,
			for(; ISWHITESPACE( *ch) || isnewline( *ch, osillineno) ; ch++ );
			if( *ch++ != '>') {  osilerror_wrapper( ch,osillineno,"improperly formed <el> tag"); return false;}
			// eat white space again,
			for(; ISWHITESPACE( *ch) || isnewline( *ch, osillineno) ; ch++ ) ;
			*p = ch;
			// find the end of the number, it better be an </el>
			// find the < which begins the </el
			while( *ch != '<' && *ch != EOF){
				ch++;
			}
			// we better have a <, or not valid
			if(*ch != '<') {  osilerror_wrapper( ch,osillineno,"cannot find an </el>"); return false;}
			osinstance->instanceData->linearConstraintCoefficients->value->el[ kount++] = 
			atofmod1( osillineno, *p, ch);
			//printf("number = %s\n", *p);
			// we are pointing to <, make sure there is /el
			*p = ch;
			while( *endEl++  == *ch) ch++;
			endEl -= 5;
			if( (ch - *p) != 4 ) {  osilerror_wrapper( ch,osillineno,"cannot fine an </el>"); return false;}
			// start eating white space until an '>' is found for </el>,
			for(; ISWHITESPACE( *ch) || isnewline( *ch, osillineno) ; ch++ );
			if( *ch++ != '>') {  osilerror_wrapper( ch,osillineno,"improperly formed </el> tag"); return false;}
			// eat white space again,
			for(; ISWHITESPACE( *ch) || isnewline( *ch, osillineno) ; ch++ );
			// either have another <el> element or foundEl = false;
			*p = ch;
			while( *startEl++  == *ch) ch++;
			if( (ch - *p) == 3){
			 	foundEl = true;
			 	startEl -= 4;
			}
			else{
				foundEl = false;
				ch = *p;
			}
		}	
	}
	// get the </value> tag
	*p = ch;
	while( *endValue++  == *ch) ch++;
	if( (ch - *p) != 7) {  osilerror_wrapper( ch,osillineno, "cannot find </value> tag"); return false;}
	for(; ISWHITESPACE( *ch) || isnewline( *ch, osillineno) ; ch++ );	
	// better have >
	if(*ch != '>') {  osilerror_wrapper( ch,osillineno,"improperly formed </value> tag");	 return false;}
	ch++;	
	if(kount < osinstance->instanceData->linearConstraintCoefficients->numberOfValues){  osilerror_wrapper( ch,osillineno,"numberOfLinearCoefficients greater than number of values found"); return false;}
	if(kount > osinstance->instanceData->linearConstraintCoefficients->numberOfValues){  osilerror_wrapper( ch,osillineno,"numberOfLinearCoefficients less than the number of values found"); return false;}
	finish = clock();
	//duration = (double) (finish - start) / CLOCKS_PER_SEC; 
	//printf("TIME TO PARSE VALUES = %f\n", duration);
	*p = ch;
	return true;
}//end parseValue

bool parseObjCoef( const char **p, int objcount, OSInstance *osinstance, int* osillineno){
	int ki, numChar;
	char *attTextEnd;
	const char *ch = *p;
	const char* startCoef = "<coef";
	const char* endCoef = "</coef";
	const char* c_idx = "idx";
	char *attText = NULL;
	int k;
	int numberOfObjCoef = 0; 
	if( osinstance->instanceData->objectives->numberOfObjectives <= 0)  {  osilerror_wrapper( ch,osillineno,"we can't have objective function coefficients without an objective function"); return false;}
	numberOfObjCoef = osinstance->instanceData->objectives->obj[objcount]->numberOfObjCoef;
	if(numberOfObjCoef > 0)	{
	for(k = 0; k < numberOfObjCoef; k++){
		for( ; ISWHITESPACE( *ch) || isnewline( *ch, osillineno); ch++ ) ;
		// if, present we should be pointing to <coef element 
		*p = ch;
		while( *startCoef++  == *ch) ch++;
		if( (ch - *p) != 5) {  osilerror_wrapper( ch,osillineno,"improper <coef> element"); return false;}
		startCoef -= 6;
		// get the idx attribute
		// eat the white space after <coef
		for( ; ISWHITESPACE( *ch) || isnewline( *ch, osillineno); ch++ ) ;
		*p = ch;
		while( *c_idx++  == *ch) ch++;
		if( (ch - *p) != 3) {  osilerror_wrapper( ch,osillineno,"incorrect idx attribute in objective function <idx> tag"); return false;}	
		c_idx -= 4;
		// ch should be pointing to the first character after idx attribute
		GETATTRIBUTETEXT;
		osinstance->instanceData->objectives->obj[objcount]->coef[ k]->idx  = atoimod1( osillineno, attText, attTextEnd);
		delete [] attText;
		ch++;	
		// eat white space
		for( ; ISWHITESPACE( *ch) || isnewline( *ch, osillineno); ch++ ) ;
		// if we don't have a > there is an error
		if(*ch++ != '>') {  osilerror_wrapper( ch,osillineno,"incorrect <coef> element")	; return false;}	
		// we should be pointing to first character after <coef>
		*p = ch;
		// eat characters until we find <
		for(; *ch != '<' && *ch != EOF; ch++); 
		// put back here

		// we should be pointing to a < in the </coef> tag	
		if(*ch != '<') {  osilerror_wrapper( ch,osillineno,"improper </coef> tag"); return false;}
		osinstance->instanceData->objectives->obj[objcount]->coef[ k]->value  = atofmod1( osillineno, *p, ch);
		*p = ch;
		while( *endCoef++  == *ch) ch++;
		if( (ch - *p) != 6)  {  osilerror_wrapper( ch,osillineno,"improper </coef> element"); return false;}
		endCoef -= 7;
		// get rid of white space after </coef
		for( ; ISWHITESPACE( *ch) || isnewline( *ch, osillineno); ch++ ) ;
		// if we don't have a > there is an error
		if(*ch++ != '>') {  osilerror_wrapper( ch,osillineno,"incorrect </coef> element")	; return false;}
	}
	}// end if(numberOfObjCoef > 0)
	*p = ch;
	return true;
}//end parseObjCoef

char *parseBase64(const char **p, int *dataSize, int* osillineno ){
	int ki, numChar;
	char *attTextEnd;
	const char *ch = *p;
	const char *sizeOf = "sizeOf";
	//char *numericType = "numericType";
	const char *startBase64BinaryData = "<base64BinaryData";
	const char *endBase64BinaryData = "</base64BinaryData";
	char *attText = NULL;
	char *b64string = NULL;
	int i;
	// start parsing
	for(i = 0; startBase64BinaryData[i]  == *ch; i++, ch++);
	if(i != 17) {
		ch -= i;
		*p = ch;
		return b64string;
	}
	// find sizeOf attribute
	// eat the white space
	for( ; ISWHITESPACE( *ch) || isnewline( *ch, osillineno); ch++ ) ;
	for(i = 0; sizeOf[i]  == *ch; i++, ch++);
	if(i != 6) {  osilerror_wrapper( ch,osillineno,"incorrect sizeOf attribute in <base64BinaryData> element"); return false;}	
	// ch should be pointing to the first character after sizeOf
	GETATTRIBUTETEXT;
	ch++;
	*dataSize = atoimod1( osillineno, attText, attTextEnd);
	delete [] attText;
	// since the element must contain b64 data,  this element must end with > 
	// eat the white space
	for( ; ISWHITESPACE( *ch) || isnewline( *ch, osillineno); ch++ ) ;
	// better have an > sign or not valid
	if(*ch != '>' ) {  osilerror_wrapper( ch,osillineno,"<base64BinaryData> element does not have a proper closing >"); return false;}
	ch++;
	// we are now pointing start of the data
	const char *b64textstart = ch;
	// eat characters until we get to the </base64BinaryData element
	for(; *ch != '<' && *ch != EOF; ch++);
	const char *b64textend = ch;
	// we should be pointing to </base64BinaryData>
	for(i = 0; endBase64BinaryData[i]  == *ch; i++, ch++);
	if(i != 18) { osilerror_wrapper( ch,osillineno," problem with <base64BinaryData> element"); return false;}
	int b64len = b64textend - b64textstart;
	b64string = new char[ b64len + 1]; 
	for(ki = 0; ki < b64len; ki++) b64string[ki] = b64textstart[ ki]; 
	b64string[ki] = '\0';	
	// burn the white space
	for( ; ISWHITESPACE( *ch) || isnewline( *ch, osillineno); ch++ ) ;
	// better have an > sign or not valid
	if(*ch != '>' ) {  osilerror_wrapper( ch,osillineno,"</base64BinaryData> element does not have a proper closing >"); return false;}
	ch++;
	for( ; ISWHITESPACE( *ch) || isnewline( *ch, osillineno); ch++ ) ;
	*p = ch;
	return b64string;
}


double atofmod1(int* osillineno, const char *number, const char *numberend){
	double val;
   	char *pEnd;
	val = os_strtod_wrap(number, &pEnd);
	// pEnd should now point to the first character after the number;
	// burn off any white space	
	for( ; ISWHITESPACE( *pEnd) || isnewline( *pEnd, osillineno); pEnd++ ) ;
	// pEnd should now point to numberend, if not we have an error
	if(pEnd != numberend) osilerror_wrapper( pEnd,   osillineno, "error in parsing an XSD:double");
	return val;
	/**
	double power;
	int i;
	int sign = 1;
	int expsign, exppower, exptest;
	int endWhiteSpace;
	// modified atof from Kernighan and Ritchie
	for(i = 0;  ISWHITESPACE( number[ i]) || isnewline( number[ i], osillineno) ; i++);
	sign = (number[ i] == '-') ? -1 : 1;
	if (number[ i] == '+' || number[ i] == '-') i++;
	endWhiteSpace = i;
	for(val = 0.0; ISDIGIT( number[ i]); i++){
		val = 10.0 *val + (number[ i] - '0') ;
	}
	if (number[ i] == '.') {
		i++;
		for (power = 1.0; ISDIGIT(number[ i]); i++){
			val = 10.0*val + (number[ i] - '0');
			power *= 10.0;
		}
		val = val/power;
	}
	if(i == endWhiteSpace) {
	// we better have INF or NaN
		switch (number[ i]){
		case 'I':
			i++;
			if(number[ i++] == 'N' && number[i++] == 'F'){
				val = OSDBL_MAX;
				break;
			}
			else{
				  
				osilerror_wrapper( number,osillineno, "error in parsing an XSD:double");
			}
		case 'N':
			i++;
			if(number[ i-2] != '+' &&  number[ i-2] != '-' && number[ i++] == 'a' && number[i++] == 'N'){
				val = OSNAN;
				break;
			}
			else{
				  
				osilerror_wrapper( number,osillineno, "error in parsing an XSD:double");
				
			}

		default:
			  
			osilerror_wrapper( number,osillineno, "error in parsing an XSD:double");
			
			break;
		}
	}
	else{
		if(number[i] == 'e' || number[i] == 'E' ){
			i++;
			// process exponential part of the term
			// we have ([eE][-+]?[0-9]+)?
			// we are not going to process a NAN or INF
			expsign = (number[ i] == '-') ? -1 : 1;
			if (number[ i] == '+' || number[ i] == '-') i++;
			// get the exponent power 
			//
			exptest = i;
			for(exppower = 0 ; ISDIGIT( number[ i]); i++){
				exppower = 10 *exppower + (number[ i] - '0') ;
			}
			if(i == exptest) {  osilerror_wrapper( number,osillineno, "error in parsing an XSD:double"); 	}
			val = val*pow(10.0, expsign*exppower);
			//printf("number = %f\n", val);
		}
	}
	// if we are here we should having nothing but white space until the end of the number
	for( ; ISWHITESPACE( number[ i]) || isnewline( number[ i], osillineno) ; i++);
	if(number[i] == *numberend){
		return sign*val;
	}
	else {  osilerror_wrapper( number,osillineno,"error in parsing an XSD:double"); 	return OSNAN;}
	*/
}//end atofmod



int atoimod1(int* osillineno, const char *number, const char *numberend){
	// modified atoi from Kernighan and Ritchie
	int ival;
	int i, sign;
	int endWhiteSpace;
	for(i = 0; ISWHITESPACE( number[ i]) || isnewline( number[ i], osillineno) ; i++);
	endWhiteSpace = i;
	sign = (number[ i] == '-') ? -1 : 1;
	if (number[ i] == '+' || number[ i] == '-') i++;
	for(ival = 0; ISDIGIT( number[ i]); i++){
		ival = 10*ival + (number[ i] - '0') ;
	}
	if(i == endWhiteSpace) {  osilerror_wrapper( number,osillineno, "error in parsing an XSD:int" ); 	}
	// if we are here we should having nothing but white space until the end of the number
	for( ; ISWHITESPACE( number[ i]) || isnewline( number[ i], osillineno) ; i++);
	if(number[i] == *numberend){
		return sign*ival;
	}
	else {  osilerror_wrapper( number,osillineno, "error in parsing an XSD:int"); return OSINT_MAX;	}
}//end atoimod1

void osilerror_wrapper( const char* ch, int* osillineno, const char* errormsg){
	const int numErrorChar = 20;
	char errorArray[100] = "";
	strncpy(errorArray, ch, numErrorChar);
	std::ostringstream outStr;
	std::string error = errormsg;
	error = "PARSER ERROR:  Input is either not valid or well formed: "  + error;
	outStr << error << endl;
	outStr << "Here are " ;
	outStr << numErrorChar ;
	outStr << " characters currently being pointed to in the input string: ";
	outStr << errorArray;
	outStr << endl;
	outStr << "See line number: " << *osillineno << endl;  
	error = outStr.str();
	//osillex_destroy(scanner);
	throw ErrorClass( error);
}//end osilerror_wrapper



