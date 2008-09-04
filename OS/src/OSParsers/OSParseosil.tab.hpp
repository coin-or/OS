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


