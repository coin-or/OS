/* $Id$ */
/** @file parseospl.l
 * 
 * @author  Robert Fourer, Horand Gassmann, Jun Ma, Kipp Martin, 
 * @version 1.0, 12/07/2008
 * @since   OS1.1
 *
 * \remarks
 * Copyright (C) 2005-2008, Robert Fourer, Horand Gassmann, Jun Ma, Kipp Martin,
 * Northwestern University, and the University of Chicago.
 * All Rights Reserved.
 * This software is licensed under the Eclipse Public License. 
 * Please see the accompanying LICENSE file in root directory for terms.
 * 
 */
%{

#include <iostream>
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




#include <sstream>  
#include "OSErrorClass.h"
#include "OSpLParserData.h"
#ifdef PARSERDEBUG
	#define YY_PRINT  printf("%s", yytext)
#else     
	#define YY_PRINT
#endif

#ifdef WIN_
  #define YY_NO_UNISTD_H
  #include <io.h>
  #include <process.h>
  #ifdef USE_OLD_UNISTD
     #include<sys/unistd.h>  
  #endif
#endif

#include "OSParseospl.tab.hpp"


     
%}

%option reentrant
%option bison-bridge
%option bison-locations


%option prefix="ospl"
%option yylineno   
%option noyywrap  
%x attributetext
%x osplattributetext
%x comment
%x xmldeclaration
   
%{
#define YY_EXTRA_TYPE OSpLParserData*
%}  

xmlwhitespace ([ \t\r\n])
equality ([ \t\r\n])*=([ \t\r\n])*
quote (\"|\') 
greater_than (>)
attname ([a-zA-Z][a-zA-Z0-9.:_]+)
startelementname (<[a-zA-Z][a-zA-Z0-9.:_]+)
endelementname (<\/[a-zA-Z][a-zA-Z0-9.:_]+)
%% 


{xmlwhitespace}* {printf("HERE IS WHITESPACE\n");}


 {quote} {YY_PRINT; return(QUOTE);}
({xmlwhitespace}*{greater_than}) {YY_PRINT;     return(GREATERTHAN);}
-?[0-9]+  {YY_PRINT; yylval->ival = atoi( yytext); return(INTEGER);}
-?((([0-9]+)|([0-9]*\.[0-9]+))([eE][-+]?[0-9]+)?|INF) {YY_PRINT; yylval->dval = atof( yytext); return(DOUBLE);}
({xmlwhitespace}*\/>) {YY_PRINT;  return(ENDOFELEMENT);}


{xmlwhitespace}*\<ospl{xmlwhitespace}+ {YY_PRINT; BEGIN osplattributetext;  return(OSPLSTART);}
{xmlwhitespace}*\<\/ospl{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(OSPLEND);}
{xmlwhitespace}*\<resultHeader{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(RESULTHEADERSTART);}
{xmlwhitespace}*\<\/resultHeader{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(RESULTHEADEREND);}
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
{xmlwhitespace}*\<message{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT;  return(MESSAGESTART);}
{xmlwhitespace}*\<message{xmlwhitespace}*\>\< {YY_PRINT; unput('<'); return(MESSAGESTART);}
{xmlwhitespace}*\<\/message{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT;  return(MESSAGEEND);}

{xmlwhitespace}*\<generalStatus {YY_PRINT; return(GENERALSTATUSSTART);}
{xmlwhitespace}*\<\/generalStatus{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(GENERALSTATUSEND);}

{xmlwhitespace}*\<resultData{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(RESULTDATASTART);}
{xmlwhitespace}*\<\/resultData{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(RESULTDATAEND);}

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
{xmlwhitespace}*\<variables {YY_PRINT; return(VARIABLESSTART);}
{xmlwhitespace}*\<\/var{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(VAREND);}
{xmlwhitespace}*\<\/variables{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(VARIABLESEND);}

{xmlwhitespace}*\<obj {YY_PRINT; return(OBJSTART);}
{xmlwhitespace}*\<objectives {YY_PRINT; return(OBJECTIVESSTART);}
{xmlwhitespace}*\<\/obj{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(OBJEND);}
{xmlwhitespace}*\<\/objectives{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(OBJECTIVESEND);}

{xmlwhitespace}*\<con {YY_PRINT; return(CONSTART);}
{xmlwhitespace}*\<constraints {YY_PRINT; return(CONSTRAINTSSTART);}
{xmlwhitespace}*\<\/con{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(CONEND);}
{xmlwhitespace}*\<\/constraints{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(CONSTRAINTSEND);}


{xmlwhitespace}*\<other {YY_PRINT; return(OTHERSTART);}
{xmlwhitespace}*\<\/other{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(OTHEREND);}

({xmlwhitespace}+numberOfSolutions{equality}{quote}{xmlwhitespace}*) {YY_PRINT; return(NUMBEROFSOLUTIONSATT);}
({xmlwhitespace}+numberOfVariables{equality}{quote}{xmlwhitespace}*) {YY_PRINT; return(NUMBEROFVARIABLESATT);}
({xmlwhitespace}+numberOfConstraints{equality}{quote}{xmlwhitespace}*) {YY_PRINT; return(NUMBEROFCONSTRAINTSATT);}
({xmlwhitespace}+numberOfObjectives{equality}{quote}{xmlwhitespace}*) {YY_PRINT; return(NUMBEROFOBJECTIVESATT);}
({xmlwhitespace}+objectiveIdx{equality}{quote}{xmlwhitespace}*) {YY_PRINT; return(OBJECTIVEIDXATT);}
({xmlwhitespace}+idx{equality}{quote}{xmlwhitespace}*) {YY_PRINT; return(IDXATT);}
({xmlwhitespace}+type{equality}{quote}{xmlwhitespace}*) {YY_PRINT; BEGIN attributetext; return(TYPEATT);}
({xmlwhitespace}+description{equality}{quote}{xmlwhitespace}*) {YY_PRINT; BEGIN attributetext; return(DESCRIPTIONATT);}
({xmlwhitespace}+name{equality}{quote}{xmlwhitespace}*) {YY_PRINT; BEGIN attributetext; return(NAMEATT);}

(\<serviceURI{xmlwhitespace}*\/>) {YY_PRINT;  return(SERVICEURISTARTANDEND);}
(\<serviceName{xmlwhitespace}*\/>) {YY_PRINT;  return(SERVICENAMESTARTANDEND);}
(\<instanceName{xmlwhitespace}*\/>) {YY_PRINT;  return(INSTANCENAMESTARTANDEND);}
(\<jobID{xmlwhitespace}*\/>) {YY_PRINT;  return(JOBIDSTARTANDEND);}
(\<message{xmlwhitespace}*\/>) {YY_PRINT;  return(MESSAGESTARTANDEND);}
(\<resultData{xmlwhitespace}*\/>) {YY_PRINT;  return(RESULTDATASTARTANDEND);}




[a-zA-X0-9.:_*#$@ \n]+ { YY_PRINT;  yylval->charval = strdup( yytext);   yyextra->errorText = yylval->charval;    /*yylval->charval = yytext;*/  return (ELEMENTTEXT); }

"<!--" BEGIN comment;
 <comment>. |
 <comment>\n ;
 <comment>"-->" BEGIN 0;
 
"<?" BEGIN xmldeclaration;
 <xmldeclaration>. |
 <xmldeclaration>\n ;
 
 <xmldeclaration>"?>" BEGIN 0;





<attributetext>([^\"\'])+ {YY_PRINT;    /*yylval->charval = strdup(yytext);*/ yylval->charval = yytext;
							BEGIN 0;  return(ATTRIBUTETEXT);}
							
<osplattributetext>([^>])* {YY_PRINT;  BEGIN 0; /*yylval->charval = strdup(yytext);*/  yylval->charval = yytext; return(OSPLATTRIBUTETEXT);}


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


