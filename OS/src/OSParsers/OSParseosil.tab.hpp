
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton interface for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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
     ENDOFELEMENT = 262,
     GREATERTHAN = 263,
     OSILEND = 264,
     INSTANCEDATAEND = 265,
     INSTANCEDATASTARTEND = 266,
     QUADRATICCOEFFICIENTSSTART = 267,
     QUADRATICCOEFFICIENTSEND = 268,
     NUMBEROFQTERMSATT = 269,
     QTERMSTART = 270,
     QTERMEND = 271,
     IDXATT = 272,
     IDXONEATT = 273,
     IDXTWOATT = 274,
     TYPEATT = 275,
     VALUEATT = 276,
     TIMEDOMAINSTART = 277,
     TIMEDOMAINEND = 278,
     STAGESSTART = 279,
     STAGESEND = 280,
     STAGESTART = 281,
     STAGEEND = 282,
     NAMEATT = 283,
     NUMBEROFSTAGESATT = 284,
     HORIZONATT = 285,
     STARTATT = 286,
     VARIABLESSTART = 287,
     CONSTRAINTSSTART = 288,
     OBJECTIVESSTART = 289,
     VARIABLESEND = 290,
     CONSTRAINTSEND = 291,
     OBJECTIVESEND = 292,
     NUMBEROFVARIABLESATT = 293,
     NUMBEROFCONSTRAINTSATT = 294,
     NUMBEROFOBJECTIVESATT = 295,
     STARTIDXATT = 296,
     VARSTART = 297,
     VAREND = 298,
     CONSTART = 299,
     CONEND = 300,
     OBJSTART = 301,
     OBJEND = 302,
     INTERVALSTART = 303,
     INTERVALEND = 304,
     NONLINEAREXPRESSIONSSTART = 305,
     NONLINEAREXPRESSIONSEND = 306,
     NUMBEROFNONLINEAREXPRESSIONS = 307,
     NLSTART = 308,
     NLEND = 309,
     POWERSTART = 310,
     POWEREND = 311,
     PLUSSTART = 312,
     PLUSEND = 313,
     MINUSSTART = 314,
     MINUSEND = 315,
     DIVIDESTART = 316,
     DIVIDEEND = 317,
     LNSTART = 318,
     LNEND = 319,
     SQRTSTART = 320,
     SQRTEND = 321,
     SUMSTART = 322,
     SUMEND = 323,
     PRODUCTSTART = 324,
     PRODUCTEND = 325,
     EXPSTART = 326,
     EXPEND = 327,
     NEGATESTART = 328,
     NEGATEEND = 329,
     IFSTART = 330,
     IFEND = 331,
     SQUARESTART = 332,
     SQUAREEND = 333,
     COSSTART = 334,
     COSEND = 335,
     SINSTART = 336,
     SINEND = 337,
     VARIABLESTART = 338,
     VARIABLEEND = 339,
     ABSSTART = 340,
     ABSEND = 341,
     ERFSTART = 342,
     ERFEND = 343,
     MAXSTART = 344,
     MAXEND = 345,
     ALLDIFFSTART = 346,
     ALLDIFFEND = 347,
     MINSTART = 348,
     MINEND = 349,
     ESTART = 350,
     EEND = 351,
     PISTART = 352,
     PIEND = 353,
     TIMESSTART = 354,
     TIMESEND = 355,
     NUMBERSTART = 356,
     NUMBEREND = 357,
     IDATT = 358,
     COEFATT = 359
   };
#endif
/* Tokens.  */
#define QUOTE 258
#define ATTRIBUTETEXT 259
#define INTEGER 260
#define DOUBLE 261
#define ENDOFELEMENT 262
#define GREATERTHAN 263
#define OSILEND 264
#define INSTANCEDATAEND 265
#define INSTANCEDATASTARTEND 266
#define QUADRATICCOEFFICIENTSSTART 267
#define QUADRATICCOEFFICIENTSEND 268
#define NUMBEROFQTERMSATT 269
#define QTERMSTART 270
#define QTERMEND 271
#define IDXATT 272
#define IDXONEATT 273
#define IDXTWOATT 274
#define TYPEATT 275
#define VALUEATT 276
#define TIMEDOMAINSTART 277
#define TIMEDOMAINEND 278
#define STAGESSTART 279
#define STAGESEND 280
#define STAGESTART 281
#define STAGEEND 282
#define NAMEATT 283
#define NUMBEROFSTAGESATT 284
#define HORIZONATT 285
#define STARTATT 286
#define VARIABLESSTART 287
#define CONSTRAINTSSTART 288
#define OBJECTIVESSTART 289
#define VARIABLESEND 290
#define CONSTRAINTSEND 291
#define OBJECTIVESEND 292
#define NUMBEROFVARIABLESATT 293
#define NUMBEROFCONSTRAINTSATT 294
#define NUMBEROFOBJECTIVESATT 295
#define STARTIDXATT 296
#define VARSTART 297
#define VAREND 298
#define CONSTART 299
#define CONEND 300
#define OBJSTART 301
#define OBJEND 302
#define INTERVALSTART 303
#define INTERVALEND 304
#define NONLINEAREXPRESSIONSSTART 305
#define NONLINEAREXPRESSIONSEND 306
#define NUMBEROFNONLINEAREXPRESSIONS 307
#define NLSTART 308
#define NLEND 309
#define POWERSTART 310
#define POWEREND 311
#define PLUSSTART 312
#define PLUSEND 313
#define MINUSSTART 314
#define MINUSEND 315
#define DIVIDESTART 316
#define DIVIDEEND 317
#define LNSTART 318
#define LNEND 319
#define SQRTSTART 320
#define SQRTEND 321
#define SUMSTART 322
#define SUMEND 323
#define PRODUCTSTART 324
#define PRODUCTEND 325
#define EXPSTART 326
#define EXPEND 327
#define NEGATESTART 328
#define NEGATEEND 329
#define IFSTART 330
#define IFEND 331
#define SQUARESTART 332
#define SQUAREEND 333
#define COSSTART 334
#define COSEND 335
#define SINSTART 336
#define SINEND 337
#define VARIABLESTART 338
#define VARIABLEEND 339
#define ABSSTART 340
#define ABSEND 341
#define ERFSTART 342
#define ERFEND 343
#define MAXSTART 344
#define MAXEND 345
#define ALLDIFFSTART 346
#define ALLDIFFEND 347
#define MINSTART 348
#define MINEND 349
#define ESTART 350
#define EEND 351
#define PISTART 352
#define PIEND 353
#define TIMESSTART 354
#define TIMESEND 355
#define NUMBERSTART 356
#define NUMBEREND 357
#define IDATT 358
#define COEFATT 359




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{


	double dval;
	int ival;
	char* sval;
	



} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
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



