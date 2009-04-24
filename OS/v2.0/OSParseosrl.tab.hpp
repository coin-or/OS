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
     TWOQUOTES = 263,
     GREATERTHAN = 264,
     ENDOFELEMENT = 265,
     OSRLSTART = 266,
     OSRLSTARTEMPTY = 267,
     OSRLATTRIBUTETEXT = 268,
     OSRLEND = 269,
     GENERALSTART = 270,
     GENERALEND = 271,
     SYSTEMSTART = 272,
     SYSTEMEND = 273,
     SERVICESTART = 274,
     SERVICEEND = 275,
     JOBSTART = 276,
     JOBEND = 277,
     SERVICEURISTARTANDEND = 278,
     SERVICEURISTART = 279,
     SERVICEURIEND = 280,
     SERVICENAMESTARTANDEND = 281,
     SERVICENAMESTART = 282,
     SERVICENAMEEND = 283,
     INSTANCENAMESTARTANDEND = 284,
     INSTANCENAMESTART = 285,
     INSTANCENAMEEND = 286,
     JOBIDSTARTANDEND = 287,
     JOBIDSTART = 288,
     JOBIDEND = 289,
     TIMINGINFORMATIONSTART = 290,
     TIMINGINFORMATIONEND = 291,
     TIMESTARTANDEND = 292,
     TIMESTART = 293,
     TIMEEND = 294,
     OPTIMIZATIONSTART = 295,
     OPTIMIZATIONEND = 296,
     SOLUTIONSTART = 297,
     SOLUTIONEND = 298,
     VALUESSTART = 299,
     VALUESEND = 300,
     DUALVALUESSTART = 301,
     DUALVALUESEND = 302,
     VARIABLESSTART = 303,
     VARIABLESEND = 304,
     VARSTART = 305,
     VAREND = 306,
     OBJECTIVESSTART = 307,
     OBJECTIVESEND = 308,
     OBJSTART = 309,
     OBJEND = 310,
     CONSTRAINTSSTART = 311,
     CONSTRAINTSEND = 312,
     CONSTART = 313,
     CONEND = 314,
     STATUSSTART = 315,
     STATUSEND = 316,
     GENERALSTATUSSTART = 317,
     GENERALSTATUSEND = 318,
     MESSAGESTART = 319,
     MESSAGEEND = 320,
     MESSAGESTARTANDEND = 321,
     OTHERSTART = 322,
     OTHEREND = 323,
     NUMBEROFTIMESATT = 324,
     NUMBEROFSOLUTIONSATT = 325,
     NUMBEROFVARIABLESATT = 326,
     NUMBEROFCONSTRAINTSATT = 327,
     NUMBEROFOBJECTIVESATT = 328,
     NUMBEROFOTHERVARIABLERESULTSATT = 329,
     NUMBEROFOTHEROBJECTIVERESULTSATT = 330,
     NUMBEROFOTHERCONSTRAINTRESULTSATT = 331,
     NUMBEROFVARATT = 332,
     NUMBEROFOBJATT = 333,
     NUMBEROFCONATT = 334,
     TARGETOBJECTIVEIDXATT = 335,
     IDXATT = 336,
     TYPEATT = 337,
     DESCRIPTIONATT = 338,
     NAMEATT = 339,
     CATEGORYATT = 340,
     UNITATT = 341,
     VALUEATT = 342,
     EMPTYVALUEATT = 343,
     DUMMY = 344
   };
#endif
/* Tokens.  */
#define ATTRIBUTETEXT 258
#define ELEMENTTEXT 259
#define INTEGER 260
#define DOUBLE 261
#define QUOTE 262
#define TWOQUOTES 263
#define GREATERTHAN 264
#define ENDOFELEMENT 265
#define OSRLSTART 266
#define OSRLSTARTEMPTY 267
#define OSRLATTRIBUTETEXT 268
#define OSRLEND 269
#define GENERALSTART 270
#define GENERALEND 271
#define SYSTEMSTART 272
#define SYSTEMEND 273
#define SERVICESTART 274
#define SERVICEEND 275
#define JOBSTART 276
#define JOBEND 277
#define SERVICEURISTARTANDEND 278
#define SERVICEURISTART 279
#define SERVICEURIEND 280
#define SERVICENAMESTARTANDEND 281
#define SERVICENAMESTART 282
#define SERVICENAMEEND 283
#define INSTANCENAMESTARTANDEND 284
#define INSTANCENAMESTART 285
#define INSTANCENAMEEND 286
#define JOBIDSTARTANDEND 287
#define JOBIDSTART 288
#define JOBIDEND 289
#define TIMINGINFORMATIONSTART 290
#define TIMINGINFORMATIONEND 291
#define TIMESTARTANDEND 292
#define TIMESTART 293
#define TIMEEND 294
#define OPTIMIZATIONSTART 295
#define OPTIMIZATIONEND 296
#define SOLUTIONSTART 297
#define SOLUTIONEND 298
#define VALUESSTART 299
#define VALUESEND 300
#define DUALVALUESSTART 301
#define DUALVALUESEND 302
#define VARIABLESSTART 303
#define VARIABLESEND 304
#define VARSTART 305
#define VAREND 306
#define OBJECTIVESSTART 307
#define OBJECTIVESEND 308
#define OBJSTART 309
#define OBJEND 310
#define CONSTRAINTSSTART 311
#define CONSTRAINTSEND 312
#define CONSTART 313
#define CONEND 314
#define STATUSSTART 315
#define STATUSEND 316
#define GENERALSTATUSSTART 317
#define GENERALSTATUSEND 318
#define MESSAGESTART 319
#define MESSAGEEND 320
#define MESSAGESTARTANDEND 321
#define OTHERSTART 322
#define OTHEREND 323
#define NUMBEROFTIMESATT 324
#define NUMBEROFSOLUTIONSATT 325
#define NUMBEROFVARIABLESATT 326
#define NUMBEROFCONSTRAINTSATT 327
#define NUMBEROFOBJECTIVESATT 328
#define NUMBEROFOTHERVARIABLERESULTSATT 329
#define NUMBEROFOTHEROBJECTIVERESULTSATT 330
#define NUMBEROFOTHERCONSTRAINTRESULTSATT 331
#define NUMBEROFVARATT 332
#define NUMBEROFOBJATT 333
#define NUMBEROFCONATT 334
#define TARGETOBJECTIVEIDXATT 335
#define IDXATT 336
#define TYPEATT 337
#define DESCRIPTIONATT 338
#define NAMEATT 339
#define CATEGORYATT 340
#define UNITATT 341
#define VALUEATT 342
#define EMPTYVALUEATT 343
#define DUMMY 344




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


