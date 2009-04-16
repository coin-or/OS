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
     GENERALSTART = 268,
     GENERALEND = 269,
     SYSTEMSTART = 270,
     SYSTEMEND = 271,
     SERVICESTART = 272,
     SERVICEEND = 273,
     JOBSTART = 274,
     JOBEND = 275,
     SERVICEURISTARTANDEND = 276,
     SERVICEURISTART = 277,
     SERVICEURIEND = 278,
     SERVICENAMESTARTANDEND = 279,
     SERVICENAMESTART = 280,
     SERVICENAMEEND = 281,
     INSTANCENAMESTARTANDEND = 282,
     INSTANCENAMESTART = 283,
     INSTANCENAMEEND = 284,
     JOBIDSTARTANDEND = 285,
     JOBIDSTART = 286,
     JOBIDEND = 287,
     TIMINGINFORMATIONSTART = 288,
     TIMINGINFORMATIONEND = 289,
     TIMESTARTANDEND = 290,
     TIMESTART = 291,
     TIMEEND = 292,
     OPTIMIZATIONSTART = 293,
     OPTIMIZATIONEND = 294,
     SOLUTIONSTART = 295,
     SOLUTIONEND = 296,
     VALUESSTART = 297,
     VALUESEND = 298,
     DUALVALUESSTART = 299,
     DUALVALUESEND = 300,
     VARIABLESSTART = 301,
     VARIABLESEND = 302,
     VARSTART = 303,
     VAREND = 304,
     OBJECTIVESSTART = 305,
     OBJECTIVESEND = 306,
     OBJSTART = 307,
     OBJEND = 308,
     CONSTRAINTSSTART = 309,
     CONSTRAINTSEND = 310,
     CONSTART = 311,
     CONEND = 312,
     STATUSSTART = 313,
     STATUSEND = 314,
     GENERALSTATUSSTART = 315,
     GENERALSTATUSEND = 316,
     MESSAGESTART = 317,
     MESSAGEEND = 318,
     MESSAGESTARTANDEND = 319,
     OTHERSTART = 320,
     OTHEREND = 321,
     NUMBEROFTIMESATT = 322,
     NUMBEROFSOLUTIONSATT = 323,
     NUMBEROFVARIABLESATT = 324,
     NUMBEROFCONSTRAINTSATT = 325,
     NUMBEROFOBJECTIVESATT = 326,
     NUMBEROFVARATT = 327,
     NUMBEROFOBJATT = 328,
     NUMBEROFCONATT = 329,
     TARGETOBJECTIVEIDXATT = 330,
     IDXATT = 331,
     TYPEATT = 332,
     DESCRIPTIONATT = 333,
     NAMEATT = 334,
     DUMMY = 335
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
#define GENERALSTART 268
#define GENERALEND 269
#define SYSTEMSTART 270
#define SYSTEMEND 271
#define SERVICESTART 272
#define SERVICEEND 273
#define JOBSTART 274
#define JOBEND 275
#define SERVICEURISTARTANDEND 276
#define SERVICEURISTART 277
#define SERVICEURIEND 278
#define SERVICENAMESTARTANDEND 279
#define SERVICENAMESTART 280
#define SERVICENAMEEND 281
#define INSTANCENAMESTARTANDEND 282
#define INSTANCENAMESTART 283
#define INSTANCENAMEEND 284
#define JOBIDSTARTANDEND 285
#define JOBIDSTART 286
#define JOBIDEND 287
#define TIMINGINFORMATIONSTART 288
#define TIMINGINFORMATIONEND 289
#define TIMESTARTANDEND 290
#define TIMESTART 291
#define TIMEEND 292
#define OPTIMIZATIONSTART 293
#define OPTIMIZATIONEND 294
#define SOLUTIONSTART 295
#define SOLUTIONEND 296
#define VALUESSTART 297
#define VALUESEND 298
#define DUALVALUESSTART 299
#define DUALVALUESEND 300
#define VARIABLESSTART 301
#define VARIABLESEND 302
#define VARSTART 303
#define VAREND 304
#define OBJECTIVESSTART 305
#define OBJECTIVESEND 306
#define OBJSTART 307
#define OBJEND 308
#define CONSTRAINTSSTART 309
#define CONSTRAINTSEND 310
#define CONSTART 311
#define CONEND 312
#define STATUSSTART 313
#define STATUSEND 314
#define GENERALSTATUSSTART 315
#define GENERALSTATUSEND 316
#define MESSAGESTART 317
#define MESSAGEEND 318
#define MESSAGESTARTANDEND 319
#define OTHERSTART 320
#define OTHEREND 321
#define NUMBEROFTIMESATT 322
#define NUMBEROFSOLUTIONSATT 323
#define NUMBEROFVARIABLESATT 324
#define NUMBEROFCONSTRAINTSATT 325
#define NUMBEROFOBJECTIVESATT 326
#define NUMBEROFVARATT 327
#define NUMBEROFOBJATT 328
#define NUMBEROFCONATT 329
#define TARGETOBJECTIVEIDXATT 330
#define IDXATT 331
#define TYPEATT 332
#define DESCRIPTIONATT 333
#define NAMEATT 334
#define DUMMY 335




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


