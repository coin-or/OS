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
     OSRLSTARTEMPTY = 266,
     OSRLATTRIBUTETEXT = 267,
     OSRLEND = 268,
     GENERALSTART = 269,
     GENERALEND = 270,
     SYSTEMSTART = 271,
     SYSTEMEND = 272,
     SERVICESTART = 273,
     SERVICEEND = 274,
     JOBSTART = 275,
     JOBEND = 276,
     SERVICEURISTARTANDEND = 277,
     SERVICEURISTART = 278,
     SERVICEURIEND = 279,
     SERVICENAMESTARTANDEND = 280,
     SERVICENAMESTART = 281,
     SERVICENAMEEND = 282,
     INSTANCENAMESTARTANDEND = 283,
     INSTANCENAMESTART = 284,
     INSTANCENAMEEND = 285,
     JOBIDSTARTANDEND = 286,
     JOBIDSTART = 287,
     JOBIDEND = 288,
     TIMINGINFORMATIONSTART = 289,
     TIMINGINFORMATIONEND = 290,
     TIMESTARTANDEND = 291,
     TIMESTART = 292,
     TIMEEND = 293,
     OPTIMIZATIONSTART = 294,
     OPTIMIZATIONEND = 295,
     SOLUTIONSTART = 296,
     SOLUTIONEND = 297,
     VALUESSTART = 298,
     VALUESEND = 299,
     DUALVALUESSTART = 300,
     DUALVALUESEND = 301,
     VARIABLESSTART = 302,
     VARIABLESEND = 303,
     VARSTART = 304,
     VAREND = 305,
     OBJECTIVESSTART = 306,
     OBJECTIVESEND = 307,
     OBJSTART = 308,
     OBJEND = 309,
     CONSTRAINTSSTART = 310,
     CONSTRAINTSEND = 311,
     CONSTART = 312,
     CONEND = 313,
     STATUSSTART = 314,
     STATUSEND = 315,
     GENERALSTATUSSTART = 316,
     GENERALSTATUSEND = 317,
     MESSAGESTART = 318,
     MESSAGEEND = 319,
     MESSAGESTARTANDEND = 320,
     OTHERSTART = 321,
     OTHEREND = 322,
     NUMBEROFTIMESATT = 323,
     NUMBEROFSOLUTIONSATT = 324,
     NUMBEROFVARIABLESATT = 325,
     NUMBEROFCONSTRAINTSATT = 326,
     NUMBEROFOBJECTIVESATT = 327,
     NUMBEROFOTHERVARIABLERESULTSATT = 328,
     NUMBEROFOTHEROBJECTIVERESULTSATT = 329,
     NUMBEROFOTHERCONSTRAINTRESULTSATT = 330,
     NUMBEROFVARATT = 331,
     NUMBEROFOBJATT = 332,
     NUMBEROFCONATT = 333,
     TARGETOBJECTIVEIDXATT = 334,
     IDXATT = 335,
     TYPEATT = 336,
     DESCRIPTIONATT = 337,
     NAMEATT = 338,
     CATEGORYATT = 339,
     UNITATT = 340,
     VALUEATT = 341,
     DUMMY = 342
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
#define OSRLSTARTEMPTY 266
#define OSRLATTRIBUTETEXT 267
#define OSRLEND 268
#define GENERALSTART 269
#define GENERALEND 270
#define SYSTEMSTART 271
#define SYSTEMEND 272
#define SERVICESTART 273
#define SERVICEEND 274
#define JOBSTART 275
#define JOBEND 276
#define SERVICEURISTARTANDEND 277
#define SERVICEURISTART 278
#define SERVICEURIEND 279
#define SERVICENAMESTARTANDEND 280
#define SERVICENAMESTART 281
#define SERVICENAMEEND 282
#define INSTANCENAMESTARTANDEND 283
#define INSTANCENAMESTART 284
#define INSTANCENAMEEND 285
#define JOBIDSTARTANDEND 286
#define JOBIDSTART 287
#define JOBIDEND 288
#define TIMINGINFORMATIONSTART 289
#define TIMINGINFORMATIONEND 290
#define TIMESTARTANDEND 291
#define TIMESTART 292
#define TIMEEND 293
#define OPTIMIZATIONSTART 294
#define OPTIMIZATIONEND 295
#define SOLUTIONSTART 296
#define SOLUTIONEND 297
#define VALUESSTART 298
#define VALUESEND 299
#define DUALVALUESSTART 300
#define DUALVALUESEND 301
#define VARIABLESSTART 302
#define VARIABLESEND 303
#define VARSTART 304
#define VAREND 305
#define OBJECTIVESSTART 306
#define OBJECTIVESEND 307
#define OBJSTART 308
#define OBJEND 309
#define CONSTRAINTSSTART 310
#define CONSTRAINTSEND 311
#define CONSTART 312
#define CONEND 313
#define STATUSSTART 314
#define STATUSEND 315
#define GENERALSTATUSSTART 316
#define GENERALSTATUSEND 317
#define MESSAGESTART 318
#define MESSAGEEND 319
#define MESSAGESTARTANDEND 320
#define OTHERSTART 321
#define OTHEREND 322
#define NUMBEROFTIMESATT 323
#define NUMBEROFSOLUTIONSATT 324
#define NUMBEROFVARIABLESATT 325
#define NUMBEROFCONSTRAINTSATT 326
#define NUMBEROFOBJECTIVESATT 327
#define NUMBEROFOTHERVARIABLERESULTSATT 328
#define NUMBEROFOTHEROBJECTIVERESULTSATT 329
#define NUMBEROFOTHERCONSTRAINTRESULTSATT 330
#define NUMBEROFVARATT 331
#define NUMBEROFOBJATT 332
#define NUMBEROFCONATT 333
#define TARGETOBJECTIVEIDXATT 334
#define IDXATT 335
#define TYPEATT 336
#define DESCRIPTIONATT 337
#define NAMEATT 338
#define CATEGORYATT 339
#define UNITATT 340
#define VALUEATT 341
#define DUMMY 342




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


