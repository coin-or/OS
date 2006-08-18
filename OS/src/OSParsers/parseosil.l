/** @file parseosil.l
 * 
 * @author  Robert Fourer,  Jun Ma, Kipp Martin, 
 * @version 1.0, 10/05/2005
 * @since   OS1.0
 *
 * \remarks
 * Copyright (C) 2005, Robert Fourer, Jun Ma, Kipp Martin,
 * Northwestern University, and the University of Chicago.
 * All Rights Reserved.
 * This software is licensed under the Common Public License. 
 * Please see the accompanying LICENSE file in root directory for terms.
 * 
 */
%{



#include <stdio.h> 
#include "lexyaccparser.h"
#include "externalvars.h"
#include <time.h>
#include "ErrorClass.h"
#include "parseosil.tab.hpp"
#include <math.h>
#include "OSConfig.h"
#ifdef PARSERDEBUG
	#define YY_PRINT  printf("%s", osiltext);
#else     
	#define YY_PRINT ;
#endif
#ifdef WIN_
#define YY_NO_UNISTD_H
#endif
#ifdef WIN_
#include <io.h>
#include <process.h>
#else
#include <unistd.h>
#endif

					 
%}

%option prefix="osil"
%option yylineno
%option noyywrap   
%x attributetext
%x startelement
%x osilattributetext
%x elementtext
%x comment
%x xmldeclaration
   
  

xmlwhitespace ([ \t\n\r])
equality ([ \t\n\r])*=([ \t\n\r])*
quote (\"|\') 
greater_than (>)
aninteger (-?[0-9]+)
adouble (-?((([0-9]+)|([0-9]*\.[0-9]+))([eE][-+]?[0-9]+)?|INF))
%% 
 
{xmlwhitespace}

{quote} {YY_PRINT; return(QUOTE);}
({xmlwhitespace}*{greater_than}) {YY_PRINT; return(GREATERTHAN);}
{aninteger}  {YY_PRINT; osillval.ival = atoi(osiltext); return(INTEGER);}
{adouble} {YY_PRINT; osillval.dval = atof(osiltext); return(DOUBLE);}
({xmlwhitespace}*\/>) {YY_PRINT;  return(ENDOFELEMENT);}



{xmlwhitespace}*\<osil{xmlwhitespace}+ {YY_PRINT; BEGIN osilattributetext;  return(OSILSTART);}
{xmlwhitespace}*\<\/osil{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(OSILEND);}
{xmlwhitespace}*\<instanceHeader{xmlwhitespace}*\/\>{xmlwhitespace}* {YY_PRINT; return(INSTANCEHEADER);}
{xmlwhitespace}*\<instanceHeader{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(INSTANCEHEADERSTART);}
{xmlwhitespace}*\<\/instanceHeader{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(INSTANCEHEADEREND);}
{xmlwhitespace}*\<name{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; BEGIN elementtext; return(NAMESTART);}
{xmlwhitespace}*\<name{xmlwhitespace}*\>\< {YY_PRINT; unput('<'); return(NAMESTART);}
{xmlwhitespace}*\<\/name{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT;  return(NAMEEND);}
{xmlwhitespace}*\<source{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; BEGIN elementtext;  return(SOURCESTART);}
{xmlwhitespace}*\<source{xmlwhitespace}*\>\< {YY_PRINT; unput('<'); return(SOURCESTART);}
{xmlwhitespace}*\<\/source{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT;   return(SOURCEEND);}
{xmlwhitespace}*\<description{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; BEGIN elementtext; return(DESCRIPTIONSTART);} 
{xmlwhitespace}*\<description{xmlwhitespace}*\>\< {YY_PRINT; unput('<'); return(DESCRIPTIONSTART);} 
{xmlwhitespace}*\<\/description{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT;  return(DESCRIPTIONEND);}
{xmlwhitespace}*\<instanceData{xmlwhitespace}*\>{xmlwhitespace}* {	return(INSTANCEDATASTART);}
({xmlwhitespace}+numberOfNonlinearExpressions{equality}{quote}{xmlwhitespace}*) {YY_PRINT; return(NUMBEROFNONLINEAREXPRESSIONS);}
{xmlwhitespace}*\<\/instanceData{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(INSTANCEDATAEND);}
{xmlwhitespace}*\<quadraticCoefficients {YY_PRINT; return(QUADRATICCOEFFICIENTSSTART);}
{xmlwhitespace}*\<\/quadraticCoefficients\>{xmlwhitespace}* {YY_PRINT; return(QUADRATICCOEFFICIENTSEND);}
{xmlwhitespace}*\<qTerm {YY_PRINT; return(QTERMSTART);}
{xmlwhitespace}*\<\/qTerm\> {YY_PRINT; return(QTERMEND);}
({xmlwhitespace}+numberOfQuadraticTerms{equality}{quote}{xmlwhitespace}*) {YY_PRINT; return(NUMBEROFQTERMSATT);}
({xmlwhitespace}+idx{equality}{quote}{xmlwhitespace}*) {YY_PRINT;   return(IDXATT);}
({xmlwhitespace}+idxOne{equality}{quote}{xmlwhitespace}*) {YY_PRINT;   return(IDXONEATT);}
({xmlwhitespace}+idxTwo{equality}{quote}{xmlwhitespace}*) {YY_PRINT;   return(IDXTWOATT);}
({xmlwhitespace}+coef{equality}{quote}{xmlwhitespace}*) {YY_PRINT;   return(COEFATT);}
({xmlwhitespace}+value{equality}{quote}{xmlwhitespace}*) {YY_PRINT;  return(VALUEATT);}
({xmlwhitespace}+id{equality}{quote}{xmlwhitespace}*) {YY_PRINT; BEGIN attributetext; return(IDATT);}
({xmlwhitespace}+id{equality}{quote}{quote}) {YY_PRINT; unput('\"'); return(IDATT);  }
({xmlwhitespace}+type{equality}{quote}{xmlwhitespace}*) {YY_PRINT; BEGIN attributetext; return(TYPEATT);}
({xmlwhitespace}+id{equality}{quote}{xmlwhitespace}*) {YY_PRINT; BEGIN attributetext; return(IDATT);}
({xmlwhitespace}+coef{equality}{quote}{xmlwhitespace}*) {YY_PRINT;   return(COEFATT);}
(\<name{xmlwhitespace}*\/>) {YY_PRINT;  return(NAMESTARTANDEND);}
(\<source{xmlwhitespace}*\/\>) {YY_PRINT;  return(SOURCESTARTANDEND);}
(\<description{xmlwhitespace}*\/\>) {YY_PRINT;  return(DESCRIPTIONSTARTANDEND);}


%{ 
// the nonlinear element tokens
%}

{xmlwhitespace}*\<nonlinearExpressions {YY_PRINT; return(NONLINEAREXPRESSIONSSTART);}
{xmlwhitespace}*\<\/nonlinearExpressions\>{xmlwhitespace}* {YY_PRINT; return(NONLINEAREXPRESSIONSEND);}
{xmlwhitespace}*\<nl {YY_PRINT; return(NLSTART);}
{xmlwhitespace}*\<\/nl\>{xmlwhitespace}* {YY_PRINT; return(NLEND);}
{xmlwhitespace}*\<times{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(TIMESSTART);}
{xmlwhitespace}*\<\/times{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(TIMESEND);}
{xmlwhitespace}*\<divide{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(DIVIDESTART);}
{xmlwhitespace}*\<\/divide{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(DIVIDEEND);}
{xmlwhitespace}*\<plus{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(PLUSSTART);}
{xmlwhitespace}*\<\/plus{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(PLUSEND);}
{xmlwhitespace}*\<minus{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(MINUSSTART);}
{xmlwhitespace}*\<\/minus{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(MINUSEND);}
{xmlwhitespace}*\<negate{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(NEGATESTART);}
{xmlwhitespace}*\<\/negate{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(NEGATEEND);}
{xmlwhitespace}*\<power{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(POWERSTART);}
{xmlwhitespace}*\<\/power{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(POWEREND);}
{xmlwhitespace}*\<ln{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(LNSTART);}
{xmlwhitespace}*\<\/ln{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(LNEND);}
{xmlwhitespace}*\<exp{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(EXPSTART);}
{xmlwhitespace}*\<\/exp{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(EXPEND);}
{xmlwhitespace}*\<abs{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(ABSSTART);}
{xmlwhitespace}*\<\/abs{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(ABSEND);}


{xmlwhitespace}*\<if{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(IFSTART);}
{xmlwhitespace}*\<\/if{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(IFEND);}

{xmlwhitespace}*\<max{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(MAXSTART);}
{xmlwhitespace}*\<\/max{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(MAXEND);}


{xmlwhitespace}*\<sum{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(SUMSTART);}
{xmlwhitespace}*\<\/sum{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(SUMEND);}
{xmlwhitespace}*\<product{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(PRODUCTSTART);}
{xmlwhitespace}*\<\/product{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(PRODUCTEND);}
{xmlwhitespace}*\<number {YY_PRINT; return(NUMBERSTART);}
{xmlwhitespace}*\<\/number{xmlwhitespace}*\> {YY_PRINT; return(NUMBEREND);}
{xmlwhitespace}*\<variable {YY_PRINT;  return(VARIABLESTART);}
{xmlwhitespace}*\<\/variable{xmlwhitespace}*\> {YY_PRINT; return(VARIABLEEND);}

 "<!--" BEGIN comment;
 <comment>. |
 <comment>\n ;
 <comment>"-->" BEGIN 0;
 
  "<?" BEGIN xmldeclaration;
 <xmldeclaration>. |
 <xmldeclaration>\n ;
 <xmldeclaration>"?>" BEGIN 0;
 
<elementtext>([^<])* {YY_PRINT;   BEGIN 0; osillval.sval = strdup(osiltext);    return(ELEMENTTEXT);}
<attributetext>([^\"\'])* {YY_PRINT;  BEGIN 0; osillval.sval = strdup(osiltext); return(ATTRIBUTETEXT);}
<osilattributetext>([^>])* {YY_PRINT;  BEGIN 0; osillval.sval = strdup(osiltext); return(OSILATTRIBUTETEXT);}

. {YY_PRINT;  printf("%s", osiltext); osilerror( "ecountered a spurious character in the lexer"); return(777777777);  }

%%

