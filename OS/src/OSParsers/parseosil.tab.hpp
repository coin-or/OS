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
     ELEMENTTEXT = 262,
     OSILSTART = 263,
     OSILEND = 264,
     NAMESTART = 265,
     NAMEEND = 266,
     DESCRIPTIONSTART = 267,
     DESCRIPTIONEND = 268,
     SOURCESTART = 269,
     SOURCEEND = 270,
     INSTANCEHEADER = 271,
     INSTANCEHEADERSTART = 272,
     INSTANCEHEADEREND = 273,
     INSTANCEDATASTART = 274,
     INSTANCEDATAEND = 275,
     VALUEATT = 276,
     NUMBEROFNONLINEAREXPRESSIONS = 277,
     IDXONEATT = 278,
     IDXTWOATT = 279,
     COEFATT = 280,
     IDATT = 281,
     TIMESSTART = 282,
     TIMESEND = 283,
     NUMBERSTART = 284,
     NUMBEREND = 285,
     NUMBEROFQTERMSATT = 286,
     IDXATT = 287,
     TYPEATT = 288,
     QTERMSTART = 289,
     QTERMEND = 290,
     QUADRATICCOEFFICIENTSSTART = 291,
     QUADRATICCOEFFICIENTSEND = 292,
     NONLINEAREXPRESSIONSSTART = 293,
     NONLINEAREXPRESSIONSEND = 294,
     NLSTART = 295,
     NLEND = 296,
     POWERSTART = 297,
     POWEREND = 298,
     PLUSSTART = 299,
     PLUSEND = 300,
     MINUSSTART = 301,
     MINUSEND = 302,
     DIVIDESTART = 303,
     DIVIDEEND = 304,
     LNSTART = 305,
     LNEND = 306,
     SUMSTART = 307,
     SUMEND = 308,
     PRODUCTSTART = 309,
     PRODUCTEND = 310,
     ENDOFELEMENT = 311,
     EXPSTART = 312,
     EXPEND = 313,
     NEGATESTART = 314,
     NEGATEEND = 315,
     IFSTART = 316,
     IFEND = 317,
     GREATERTHAN = 318,
     OSILATTRIBUTETEXT = 319,
     NAMESTARTANDEND = 320,
     SOURCESTARTANDEND = 321,
     DESCRIPTIONSTARTANDEND = 322,
     VARIABLESTART = 323,
     VARIABLEEND = 324,
     ABSSTART = 325,
     ABSEND = 326,
     MAXSTART = 327,
     MAXEND = 328
   };
#endif
/* Tokens.  */
#define QUOTE 258
#define ATTRIBUTETEXT 259
#define INTEGER 260
#define DOUBLE 261
#define ELEMENTTEXT 262
#define OSILSTART 263
#define OSILEND 264
#define NAMESTART 265
#define NAMEEND 266
#define DESCRIPTIONSTART 267
#define DESCRIPTIONEND 268
#define SOURCESTART 269
#define SOURCEEND 270
#define INSTANCEHEADER 271
#define INSTANCEHEADERSTART 272
#define INSTANCEHEADEREND 273
#define INSTANCEDATASTART 274
#define INSTANCEDATAEND 275
#define VALUEATT 276
#define NUMBEROFNONLINEAREXPRESSIONS 277
#define IDXONEATT 278
#define IDXTWOATT 279
#define COEFATT 280
#define IDATT 281
#define TIMESSTART 282
#define TIMESEND 283
#define NUMBERSTART 284
#define NUMBEREND 285
#define NUMBEROFQTERMSATT 286
#define IDXATT 287
#define TYPEATT 288
#define QTERMSTART 289
#define QTERMEND 290
#define QUADRATICCOEFFICIENTSSTART 291
#define QUADRATICCOEFFICIENTSEND 292
#define NONLINEAREXPRESSIONSSTART 293
#define NONLINEAREXPRESSIONSEND 294
#define NLSTART 295
#define NLEND 296
#define POWERSTART 297
#define POWEREND 298
#define PLUSSTART 299
#define PLUSEND 300
#define MINUSSTART 301
#define MINUSEND 302
#define DIVIDESTART 303
#define DIVIDEEND 304
#define LNSTART 305
#define LNEND 306
#define SUMSTART 307
#define SUMEND 308
#define PRODUCTSTART 309
#define PRODUCTEND 310
#define ENDOFELEMENT 311
#define EXPSTART 312
#define EXPEND 313
#define NEGATESTART 314
#define NEGATEEND 315
#define IFSTART 316
#define IFEND 317
#define GREATERTHAN 318
#define OSILATTRIBUTETEXT 319
#define NAMESTARTANDEND 320
#define SOURCESTARTANDEND 321
#define DESCRIPTIONSTARTANDEND 322
#define VARIABLESTART 323
#define VARIABLEEND 324
#define ABSSTART 325
#define ABSEND 326
#define MAXSTART 327
#define MAXEND 328




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

extern YYSTYPE osillval;

