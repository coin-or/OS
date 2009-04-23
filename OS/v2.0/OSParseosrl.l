/** @file parseosrl.l
 * 
 * @author  Robert Fourer,  Jun Ma, Kipp Martin, 
 * @version 2.0, 02/04/2009
 * @since   OS1.0
 *
 * \remarks
 * Copyright (C) 2005-2009, Robert Fourer, Horand Gassmann, Jun Ma, Kipp Martin,
 * Northwestern University, Dalhousie University, and the University of Chicago.
 * All Rights Reserved.
 * This software is licensed under the Common Public License. 
 * Please see the accompanying LICENSE file in root directory for terms.
 * 
 */
%{

#include <iostream>
#include "OSDataStructures.h"
#include "OSMathUtil.h"
#include "OSConfig.h"

#ifdef HAVE_CSTDIO
# include <cstdio>
#else
# ifdef HAVE_STDIO_H
#  include <stdio.h>
# else
#  error "don't have header file for stdio"
# endif
#endif

#ifdef HAVE_CSTRING
# include <cstring>
#else
# ifdef HAVE_STRING_H
#  include <string.h>
# else
#  error "don't have header file for string"
# endif
#endif

#ifdef HAVE_CMATH
# include <cmath>
#else
# ifdef HAVE_MATH_H
#  include <math.h>
# else
#  error "don't have header file for math"
# endif
#endif
 
#include <sstream>  
#include "OSrLParserData.h"
#include "OSErrorClass.h"
#include "OSParseosrl.tab.hpp"
#include "OSResult.h"


#define PARSERDEBUG
#ifdef PARSERDEBUG
	#define YY_PRINT  printf("%s", yytext);
#else     
	#define YY_PRINT ;
#endif


#ifdef WIN_
  #define YY_NO_UNISTD_H
  #include <io.h>
  #include <process.h>
  #ifdef USE_OLD_UNISTD
     #include<sys/unistd.h>  
  #endif
#endif

using std::cout;
using std::endl;
using std::ostringstream;
     
%}

%option prefix="osrl"
%option noyywrap  
%option reentrant
%option bison-bridge
%option bison-locations
%option yylineno   

%x osrlattributetext
%x doublequoteattributetext
%x singlequoteattributetext
%x startelement
%x elementtext
%x comment
%x xmldeclaration
   
%{
#define YY_EXTRA_TYPE OSrLParserData*
%}  

xmlwhitespace ([ \t\n\r])
equality ([ \t\n\r])*=([ \t\n]\r)*
quote (\"|\') 
greater_than (>)
aninteger (-?[0-9]+)
adouble (-?((([0-9]+)|([0-9]*\.[0-9]*))([eE][-+]?[0-9]+)?|INF))
%% 


{xmlwhitespace}* 

 /* General patterns matched in more than one element */

{quote} {YY_PRINT;  yylval->sval = yytext; return(QUOTE);}
({xmlwhitespace}*{greater_than}) {YY_PRINT;     return(GREATERTHAN);}
{aninteger}  {YY_PRINT; yylval->ival = atoi(yytext); return(INTEGER);}

{adouble} {YY_PRINT; 
char *yytextEnd;
yylval->dval = os_strtod_wrap( yytext, &yytextEnd);
	if( (unsigned)(yytextEnd - yytext) != strlen( yytext)){
		std::ostringstream outStr;
		outStr << "encountered a spurious character in the lexer" << endl;
		outStr << "The first character is: ";
		outStr <<  yytext;
		outStr << endl;
		outStr << "See line number: " << yylineno << endl;  
		throw ErrorClass( outStr.str());
	}
return(DOUBLE);}

({xmlwhitespace}*\/>) {YY_PRINT;  return(ENDOFELEMENT);}

({xmlwhitespace}+numberOfTimes{equality}) {YY_PRINT; return(NUMBEROFTIMESATT);}
({xmlwhitespace}+numberOfSolutions{equality}) {YY_PRINT; return(NUMBEROFSOLUTIONSATT);}
({xmlwhitespace}+numberOfVariables{equality}) {YY_PRINT; return(NUMBEROFVARIABLESATT);}
({xmlwhitespace}+numberOfObjectives{equality}) {YY_PRINT; return(NUMBEROFOBJECTIVESATT);}
({xmlwhitespace}+numberOfConstraints{equality}) {YY_PRINT; return(NUMBEROFCONSTRAINTSATT);}
({xmlwhitespace}+numberOfOtherVariableResults{equality}) {YY_PRINT; return(NUMBEROFOTHERVARIABLERESULTSATT);}
({xmlwhitespace}+numberOfOtherObjectiveResults{equality}) {YY_PRINT; return(NUMBEROFOTHEROBJECTIVERESULTSATT);}
({xmlwhitespace}+numberOfOtherConstraintResults{equality}) {YY_PRINT; return(NUMBEROFOTHERCONSTRAINTRESULTSATT);}
({xmlwhitespace}+numberOfVar{equality}) {YY_PRINT; return(NUMBEROFVARATT);}
({xmlwhitespace}+numberOfObj{equality}) {YY_PRINT; return(NUMBEROFOBJATT);}
({xmlwhitespace}+numberOfCon{equality}) {YY_PRINT; return(NUMBEROFCONATT);}
({xmlwhitespace}+idx{equality}{quote}{xmlwhitespace}*) {YY_PRINT; return(IDXATT);}
({xmlwhitespace}+targetObjectiveIdx{equality}) {YY_PRINT;  return(TARGETOBJECTIVEIDXATT);}

({xmlwhitespace}+name{equality}\") {YY_PRINT; BEGIN doublequoteattributetext; return(NAMEATT);}
({xmlwhitespace}+name{equality}\') {YY_PRINT; BEGIN singlequoteattributetext; return(NAMEATT);}
({xmlwhitespace}+type{equality}\") {YY_PRINT; BEGIN doublequoteattributetext; return(TYPEATT);}
({xmlwhitespace}+type{equality}\') {YY_PRINT; BEGIN singlequoteattributetext; return(TYPEATT);}
({xmlwhitespace}+category{equality}\") {YY_PRINT; BEGIN doublequoteattributetext; return(CATEGORYATT);}
({xmlwhitespace}+category{equality}\') {YY_PRINT; BEGIN singlequoteattributetext; return(CATEGORYATT);}
({xmlwhitespace}+unit{equality}\") {YY_PRINT; BEGIN doublequoteattributetext; return(UNITATT);}
({xmlwhitespace}+unit{equality}\') {YY_PRINT; BEGIN singlequoteattributetext; return(UNITATT);}
({xmlwhitespace}+value{equality}\") {YY_PRINT; BEGIN doublequoteattributetext; return(VALUEATT);}
({xmlwhitespace}+value{equality}\') {YY_PRINT; BEGIN singlequoteattributetext; return(VALUEATT);}
({xmlwhitespace}+description{equality}\") {YY_PRINT; BEGIN doublequoteattributetext; return(DESCRIPTIONATT);}
({xmlwhitespace}+description{equality}\') {YY_PRINT; BEGIN singlequoteattributetext; return(DESCRIPTIONATT);}


{xmlwhitespace}*\<osrl{xmlwhitespace}*\> {return(OSRLSTARTEMPTY);}
{xmlwhitespace}*\<osrl{xmlwhitespace}+ {YY_PRINT; BEGIN osrlattributetext;  return(OSRLSTART);}
{xmlwhitespace}*\<\/osrl{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(OSRLEND);}
{xmlwhitespace}*\<general{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(GENERALSTART);}
{xmlwhitespace}*\<\/general{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(GENERALEND);}
{xmlwhitespace}*\<system{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(SYSTEMSTART);}
{xmlwhitespace}*\<\/system{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(SYSTEMEND);}
{xmlwhitespace}*\<service{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(SERVICESTART);}
{xmlwhitespace}*\<\/service{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(SERVICEEND);}
{xmlwhitespace}*\<job{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(JOBSTART);}
{xmlwhitespace}*\<\/job{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT;  return(JOBEND);}

{xmlwhitespace}*\<serviceURI{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT;  return(SERVICEURISTART);}
{xmlwhitespace}*\<serviceURI{xmlwhitespace}*\>\< {YY_PRINT; unput('<'); return(SERVICEURISTART);}
{xmlwhitespace}*\<\/serviceURI{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT;  return(SERVICEURIEND);}
{xmlwhitespace}*\<serviceName{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT;  return(SERVICENAMESTART);}
{xmlwhitespace}*\<serviceName{xmlwhitespace}*\>\< {YY_PRINT; unput('<'); return(SERVICENAMESTART);}
{xmlwhitespace}*\<\/serviceName{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT;  return(SERVICENAMEEND);}
{xmlwhitespace}*\<instanceName{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT;  return(INSTANCENAMESTART);}
{xmlwhitespace}*\<instanceName{xmlwhitespace}*\>\< {YY_PRINT; unput('<'); return(INSTANCENAMESTART);}
{xmlwhitespace}*\<\/instanceName{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT;  return(INSTANCENAMEEND);}
{xmlwhitespace}*\<jobID{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT;  return(JOBIDSTART);}
{xmlwhitespace}*\<jobID{xmlwhitespace}*\>\< {YY_PRINT; unput('<'); return(JOBIDSTART);}
{xmlwhitespace}*\<\/jobID{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT;  return(JOBIDEND);}

{xmlwhitespace}*\<timingInformation {YY_PRINT; return(TIMINGINFORMATIONSTART);}
{xmlwhitespace}*\<\/timingInformation{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT;  return(TIMINGINFORMATIONEND);}

{xmlwhitespace}*\<time {YY_PRINT;  return(TIMESTART);}
{xmlwhitespace}*\<\/time{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT;  return(TIMEEND);}

{xmlwhitespace}*\<message{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT;  return(MESSAGESTART);}
{xmlwhitespace}*\<message{xmlwhitespace}*\>\< {YY_PRINT; unput('<'); return(MESSAGESTART);}
{xmlwhitespace}*\<\/message{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT;  return(MESSAGEEND);}

{xmlwhitespace}*\<generalStatus {YY_PRINT; return(GENERALSTATUSSTART);}
{xmlwhitespace}*\<\/generalStatus{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(GENERALSTATUSEND);}

{xmlwhitespace}*\<optimization {YY_PRINT; return(OPTIMIZATIONSTART);}
{xmlwhitespace}*\<\/optimization{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(OPTIMIZATIONEND);}

{xmlwhitespace}*\<solution {YY_PRINT; return(SOLUTIONSTART);}
{xmlwhitespace}*\<\/solution{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(SOLUTIONEND);}

{xmlwhitespace}*\<status {YY_PRINT; return(STATUSSTART);}
{xmlwhitespace}*\<\/status{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(STATUSEND);}

{xmlwhitespace}*\<values {YY_PRINT; return(VALUESSTART);}
{xmlwhitespace}*\<\/values{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(VALUESEND);}

{xmlwhitespace}*\<dualValues {YY_PRINT; return(DUALVALUESSTART);}
{xmlwhitespace}*\<\/dualValues{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(DUALVALUESEND);}

{xmlwhitespace}*\<var {YY_PRINT; return(VARSTART);}
{xmlwhitespace}*\<\/var{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(VAREND);}
{xmlwhitespace}*\<variables {YY_PRINT; return(VARIABLESSTART);}
{xmlwhitespace}*\<\/variables{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(VARIABLESEND);}

{xmlwhitespace}*\<obj {YY_PRINT; return(OBJSTART);}
{xmlwhitespace}*\<\/obj{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(OBJEND);}
{xmlwhitespace}*\<objectives {YY_PRINT; return(OBJECTIVESSTART);}
{xmlwhitespace}*\<\/objectives{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(OBJECTIVESEND);}

{xmlwhitespace}*\<con {YY_PRINT; return(CONSTART);}
{xmlwhitespace}*\<\/con{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(CONEND);}
{xmlwhitespace}*\<constraints {YY_PRINT; return(CONSTRAINTSSTART);}
{xmlwhitespace}*\<\/constraints{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(CONSTRAINTSEND);}


{xmlwhitespace}*\<other {YY_PRINT; return(OTHERSTART);}
{xmlwhitespace}*\<\/other{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(OTHEREND);}

(\<serviceURI{xmlwhitespace}*\/>) {YY_PRINT;  return(SERVICEURISTARTANDEND);}
(\<serviceName{xmlwhitespace}*\/>) {YY_PRINT;  return(SERVICENAMESTARTANDEND);}
(\<instanceName{xmlwhitespace}*\/>) {YY_PRINT;  return(INSTANCENAMESTARTANDEND);}
(\<jobID{xmlwhitespace}*\/>) {YY_PRINT;  return(JOBIDSTARTANDEND);}
(\<time{xmlwhitespace}*\/>) {YY_PRINT;  return(TIMESTARTANDEND);}
(\<message{xmlwhitespace}*\/>) {YY_PRINT;  return(MESSAGESTARTANDEND);}




[a-zA-Z0-9.:_*#$@ \n]+ { YY_PRINT;  yylval->sval = strdup( yytext);   yyextra->errorText = yylval->sval;    /*yylval->sval = yytext;*/  return (ELEMENTTEXT); }

"<!--" BEGIN comment;
 <comment>. |
 <comment>\n ;
 <comment>"-->" BEGIN 0;
 
"<?" BEGIN xmldeclaration;
 <xmldeclaration>. |
 <xmldeclaration>\n ;
  <xmldeclaration>"?>" BEGIN 0;


<doublequoteattributetext>[^\"]* {YY_PRINT;  BEGIN 0; yylval->sval = strdup(yytext);  /* yylval->sval = yytext;*/ return(ATTRIBUTETEXT);}
<singlequoteattributetext>[^\']* {YY_PRINT;  BEGIN 0; yylval->sval = strdup(yytext);   /*yylval->sval = yytext;*/ return(ATTRIBUTETEXT);}
<osrlattributetext>([^>])* {YY_PRINT;  BEGIN 0; /*yylval->sval = strdup(yytext);*/  yylval->sval = yytext; return(OSRLATTRIBUTETEXT);}


.|\n { 
	std::string error;
	std::ostringstream outStr;
	outStr << "encountered a spurious character in the lexer" << std::endl;
	outStr << "The first character is: ";
	outStr <<  yytext;
	outStr << std::endl;
	outStr << "See line number: " << yylineno << std::endl;  
	error = outStr.str();
	throw ErrorClass( error);
}




%%


