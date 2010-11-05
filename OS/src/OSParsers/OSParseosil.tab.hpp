/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton interface for Bison's Yacc-like parsers in C

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
     INSTANCEDATASTARTEND = 264,
     VALUEATT = 265,
     NUMBEROFNONLINEAREXPRESSIONS = 266,
     IDXONEATT = 267,
     IDXTWOATT = 268,
     COEFATT = 269,
     IDATT = 270,
     TIMESSTART = 271,
     TIMESEND = 272,
     NUMBERSTART = 273,
     NUMBEREND = 274,
     NUMBEROFQTERMSATT = 275,
     IDXATT = 276,
     TYPEATT = 277,
     QTERMSTART = 278,
     QTERMEND = 279,
     QUADRATICCOEFFICIENTSSTART = 280,
     QUADRATICCOEFFICIENTSEND = 281,
     NONLINEAREXPRESSIONSSTART = 282,
     NONLINEAREXPRESSIONSEND = 283,
     NLSTART = 284,
     NLEND = 285,
     POWERSTART = 286,
     POWEREND = 287,
     PLUSSTART = 288,
     PLUSEND = 289,
     MINUSSTART = 290,
     MINUSEND = 291,
     DIVIDESTART = 292,
     DIVIDEEND = 293,
     LNSTART = 294,
     LNEND = 295,
     SQRTSTART = 296,
     SQRTEND = 297,
     SUMSTART = 298,
     SUMEND = 299,
     PRODUCTSTART = 300,
     PRODUCTEND = 301,
     ENDOFELEMENT = 302,
     EXPSTART = 303,
     EXPEND = 304,
     NEGATESTART = 305,
     NEGATEEND = 306,
     IFSTART = 307,
     IFEND = 308,
     SQUARESTART = 309,
     SQUAREEND = 310,
     COSSTART = 311,
     COSEND = 312,
     SINSTART = 313,
     SINEND = 314,
     GREATERTHAN = 315,
     VARIABLESTART = 316,
     VARIABLEEND = 317,
     ABSSTART = 318,
     ABSEND = 319,
     ERFSTART = 320,
     ERFEND = 321,
     MAXSTART = 322,
     MAXEND = 323,
     ALLDIFFSTART = 324,
     ALLDIFFEND = 325,
     MINSTART = 326,
     MINEND = 327,
     ESTART = 328,
     EEND = 329,
     PISTART = 330,
     PIEND = 331,
     TIMEDOMAINSTART = 332,
     TIMEDOMAINEND = 333,
     STAGESSTART = 334,
     STAGESEND = 335,
     STAGESTART = 336,
     STAGEEND = 337,
     NAMEATT = 338,
     NUMBEROFSTAGESATT = 339,
     HORIZONATT = 340,
     STARTATT = 341,
     VARIABLESSTART = 342,
     CONSTRAINTSSTART = 343,
     OBJECTIVESSTART = 344,
     VARIABLESEND = 345,
     CONSTRAINTSEND = 346,
     OBJECTIVESEND = 347,
     NUMBEROFVARIABLESATT = 348,
     NUMBEROFCONSTRAINTSATT = 349,
     NUMBEROFOBJECTIVESATT = 350,
     STARTIDXATT = 351,
     VARSTART = 352,
     VAREND = 353,
     CONSTART = 354,
     CONEND = 355,
     OBJSTART = 356,
     OBJEND = 357,
     INTERVALSTART = 358,
     INTERVALEND = 359
   };
#endif
/* Tokens.  */
#define QUOTE 258
#define ATTRIBUTETEXT 259
#define INTEGER 260
#define DOUBLE 261
#define OSILEND 262
#define INSTANCEDATAEND 263
#define INSTANCEDATASTARTEND 264
#define VALUEATT 265
#define NUMBEROFNONLINEAREXPRESSIONS 266
#define IDXONEATT 267
#define IDXTWOATT 268
#define COEFATT 269
#define IDATT 270
#define TIMESSTART 271
#define TIMESEND 272
#define NUMBERSTART 273
#define NUMBEREND 274
#define NUMBEROFQTERMSATT 275
#define IDXATT 276
#define TYPEATT 277
#define QTERMSTART 278
#define QTERMEND 279
#define QUADRATICCOEFFICIENTSSTART 280
#define QUADRATICCOEFFICIENTSEND 281
#define NONLINEAREXPRESSIONSSTART 282
#define NONLINEAREXPRESSIONSEND 283
#define NLSTART 284
#define NLEND 285
#define POWERSTART 286
#define POWEREND 287
#define PLUSSTART 288
#define PLUSEND 289
#define MINUSSTART 290
#define MINUSEND 291
#define DIVIDESTART 292
#define DIVIDEEND 293
#define LNSTART 294
#define LNEND 295
#define SQRTSTART 296
#define SQRTEND 297
#define SUMSTART 298
#define SUMEND 299
#define PRODUCTSTART 300
#define PRODUCTEND 301
#define ENDOFELEMENT 302
#define EXPSTART 303
#define EXPEND 304
#define NEGATESTART 305
#define NEGATEEND 306
#define IFSTART 307
#define IFEND 308
#define SQUARESTART 309
#define SQUAREEND 310
#define COSSTART 311
#define COSEND 312
#define SINSTART 313
#define SINEND 314
#define GREATERTHAN 315
#define VARIABLESTART 316
#define VARIABLEEND 317
#define ABSSTART 318
#define ABSEND 319
#define ERFSTART 320
#define ERFEND 321
#define MAXSTART 322
#define MAXEND 323
#define ALLDIFFSTART 324
#define ALLDIFFEND 325
#define MINSTART 326
#define MINEND 327
#define ESTART 328
#define EEND 329
#define PISTART 330
#define PIEND 331
#define TIMEDOMAINSTART 332
#define TIMEDOMAINEND 333
#define STAGESSTART 334
#define STAGESEND 335
#define STAGESTART 336
#define STAGEEND 337
#define NAMEATT 338
#define NUMBEROFSTAGESATT 339
#define HORIZONATT 340
#define STARTATT 341
#define VARIABLESSTART 342
#define CONSTRAINTSSTART 343
#define OBJECTIVESSTART 344
#define VARIABLESEND 345
#define CONSTRAINTSEND 346
#define OBJECTIVESEND 347
#define NUMBEROFVARIABLESATT 348
#define NUMBEROFCONSTRAINTSATT 349
#define NUMBEROFOBJECTIVESATT 350
#define STARTIDXATT 351
#define VARSTART 352
#define VAREND 353
#define CONSTART 354
#define CONEND 355
#define OBJSTART 356
#define OBJEND 357
#define INTERVALSTART 358
#define INTERVALEND 359




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE

{
	double dval;
	int ival;
	char* sval;
	
}
/* Line 1529 of yacc.c.  */

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


