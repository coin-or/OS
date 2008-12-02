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
     TIMESTARTANDEND = 282,
     TIMESTART = 283,
     TIMEEND = 284,
     RESULTDATASTART = 285,
     RESULTDATAEND = 286,
     RESULTDATASTARTANDEND = 287,
     OPTIMIZATIONSTART = 288,
     OPTIMIZATIONEND = 289,
     SOLUTIONSTART = 290,
     SOLUTIONEND = 291,
     VALUESSTART = 292,
     VALUESEND = 293,
     DUALVALUESSTART = 294,
     DUALVALUESEND = 295,
     VARIABLESSTART = 296,
     VARIABLESEND = 297,
     VARSTART = 298,
     VAREND = 299,
     OBJECTIVESSTART = 300,
     OBJECTIVESEND = 301,
     OBJSTART = 302,
     OBJEND = 303,
     CONSTRAINTSSTART = 304,
     CONSTRAINTSEND = 305,
     CONSTART = 306,
     CONEND = 307,
     STATUSSTART = 308,
     STATUSEND = 309,
     GENERALSTATUSSTART = 310,
     GENERALSTATUSEND = 311,
     MESSAGESTART = 312,
     MESSAGEEND = 313,
     MESSAGESTARTANDEND = 314,
     OTHERSTART = 315,
     OTHEREND = 316,
     NUMBEROFSOLUTIONSATT = 317,
     NUMBEROFVARIABLESATT = 318,
     NUMBEROFCONSTRAINTSATT = 319,
     NUMBEROFOBJECTIVESATT = 320,
     OBJECTIVEIDXATT = 321,
     IDXATT = 322,
     TYPEATT = 323,
     DESCRIPTIONATT = 324,
     NAMEATT = 325,
     DUMMY = 326
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
#define TIMESTARTANDEND 282
#define TIMESTART 283
#define TIMEEND 284
#define RESULTDATASTART 285
#define RESULTDATAEND 286
#define RESULTDATASTARTANDEND 287
#define OPTIMIZATIONSTART 288
#define OPTIMIZATIONEND 289
#define SOLUTIONSTART 290
#define SOLUTIONEND 291
#define VALUESSTART 292
#define VALUESEND 293
#define DUALVALUESSTART 294
#define DUALVALUESEND 295
#define VARIABLESSTART 296
#define VARIABLESEND 297
#define VARSTART 298
#define VAREND 299
#define OBJECTIVESSTART 300
#define OBJECTIVESEND 301
#define OBJSTART 302
#define OBJEND 303
#define CONSTRAINTSSTART 304
#define CONSTRAINTSEND 305
#define CONSTART 306
#define CONEND 307
#define STATUSSTART 308
#define STATUSEND 309
#define GENERALSTATUSSTART 310
#define GENERALSTATUSEND 311
#define MESSAGESTART 312
#define MESSAGEEND 313
#define MESSAGESTARTANDEND 314
#define OTHERSTART 315
#define OTHEREND 316
#define NUMBEROFSOLUTIONSATT 317
#define NUMBEROFVARIABLESATT 318
#define NUMBEROFCONSTRAINTSATT 319
#define NUMBEROFOBJECTIVESATT 320
#define OBJECTIVEIDXATT 321
#define IDXATT 322
#define TYPEATT 323
#define DESCRIPTIONATT 324
#define NAMEATT 325
#define DUMMY 326




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE

{
	double dval;
	int ival;
	char* charval;
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


