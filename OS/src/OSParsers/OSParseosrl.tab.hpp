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
     ATTRIBUTETEXT = 258,
     ELEMENTTEXT = 259,
     INTEGER = 260,
     DOUBLE = 261,
     QUOTE = 262,
     GREATERTHAN = 263,
     ENDOFELEMENT = 264,
     OSRLSTART = 265,
     OSRLATTRIBUTETEXT = 266,
     OSRLEND = 267,
     RESULTHEADERSTART = 268,
     RESULTHEADEREND = 269,
     SERVICEURISTARTANDEND = 270,
     SERVICEURISTART = 271,
     SERVICEURIEND = 272,
     SERVICENAMESTARTANDEND = 273,
     SERVICENAMESTART = 274,
     SERVICENAMEEND = 275,
     INSTANCENAMESTARTANDEND = 276,
     INSTANCENAMESTART = 277,
     INSTANCENAMEEND = 278,
     JOBIDSTARTANDEND = 279,
     JOBIDSTART = 280,
     JOBIDEND = 281,
     RESULTDATASTART = 282,
     RESULTDATAEND = 283,
     RESULTDATASTARTANDEND = 284,
     OPTIMIZATIONSTART = 285,
     OPTIMIZATIONEND = 286,
     SOLUTIONSTART = 287,
     SOLUTIONEND = 288,
     VALUESSTART = 289,
     VALUESEND = 290,
     DUALVALUESSTART = 291,
     DUALVALUESEND = 292,
     VARIABLESSTART = 293,
     VARIABLESEND = 294,
     VARSTART = 295,
     VAREND = 296,
     OBJECTIVESSTART = 297,
     OBJECTIVESEND = 298,
     OBJSTART = 299,
     OBJEND = 300,
     CONSTRAINTSSTART = 301,
     CONSTRAINTSEND = 302,
     CONSTART = 303,
     CONEND = 304,
     STATUSSTART = 305,
     STATUSEND = 306,
     GENERALSTATUSSTART = 307,
     GENERALSTATUSEND = 308,
     MESSAGESTART = 309,
     MESSAGEEND = 310,
     MESSAGESTARTANDEND = 311,
     OTHERSTART = 312,
     OTHEREND = 313,
     NUMBEROFSOLUTIONSATT = 314,
     NUMBEROFVARIABLESATT = 315,
     NUMBEROFCONSTRAINTSATT = 316,
     NUMBEROFOBJECTIVESATT = 317,
     OBJECTIVEIDXATT = 318,
     IDXATT = 319,
     TYPEATT = 320,
     DESCRIPTIONATT = 321,
     NAMEATT = 322,
     DUMMY = 323
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
#define OSRLSTART 265
#define OSRLATTRIBUTETEXT 266
#define OSRLEND 267
#define RESULTHEADERSTART 268
#define RESULTHEADEREND 269
#define SERVICEURISTARTANDEND 270
#define SERVICEURISTART 271
#define SERVICEURIEND 272
#define SERVICENAMESTARTANDEND 273
#define SERVICENAMESTART 274
#define SERVICENAMEEND 275
#define INSTANCENAMESTARTANDEND 276
#define INSTANCENAMESTART 277
#define INSTANCENAMEEND 278
#define JOBIDSTARTANDEND 279
#define JOBIDSTART 280
#define JOBIDEND 281
#define RESULTDATASTART 282
#define RESULTDATAEND 283
#define RESULTDATASTARTANDEND 284
#define OPTIMIZATIONSTART 285
#define OPTIMIZATIONEND 286
#define SOLUTIONSTART 287
#define SOLUTIONEND 288
#define VALUESSTART 289
#define VALUESEND 290
#define DUALVALUESSTART 291
#define DUALVALUESEND 292
#define VARIABLESSTART 293
#define VARIABLESEND 294
#define VARSTART 295
#define VAREND 296
#define OBJECTIVESSTART 297
#define OBJECTIVESEND 298
#define OBJSTART 299
#define OBJEND 300
#define CONSTRAINTSSTART 301
#define CONSTRAINTSEND 302
#define CONSTART 303
#define CONEND 304
#define STATUSSTART 305
#define STATUSEND 306
#define GENERALSTATUSSTART 307
#define GENERALSTATUSEND 308
#define MESSAGESTART 309
#define MESSAGEEND 310
#define MESSAGESTARTANDEND 311
#define OTHERSTART 312
#define OTHEREND 313
#define NUMBEROFSOLUTIONSATT 314
#define NUMBEROFVARIABLESATT 315
#define NUMBEROFCONSTRAINTSATT 316
#define NUMBEROFOBJECTIVESATT 317
#define OBJECTIVEIDXATT 318
#define IDXATT 319
#define TYPEATT 320
#define DESCRIPTIONATT 321
#define NAMEATT 322
#define DUMMY 323




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE

{
	double dval;
	int ival;
	char* charval;
}
/* Line 1489 of yacc.c.  */

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


