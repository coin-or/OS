/** @file parseosrl.l
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
#include <string.h>
#include "OSConfig.h"
#include "lexyaccparser.h"
#include "externalvars.h"


#ifdef PARSERDEBUG
	#define YY_PRINT  printf("%s", osrltext);
#else     
	#define YY_PRINT ;
#endif
#ifdef WIN_SOCK
#define YY_NO_UNISTD_H
#endif

#include "parseosrl.tab.hpp"

     
%}
%option prefix="osrl"
%option yylineno   
%option noyywrap  
%x attributetext
%x elementtext 
%x osrlattributetext
%x comment
%x xmldeclaration
   
  

xmlwhitespace ([ \t\r\n])
equality ([ \t\r\n])*=([ \t\r\n])*
quote (\"|\') 
greater_than (>)
attname ([a-zA-Z][a-zA-Z0-9.:_]+)
startelementname (<[a-zA-Z][a-zA-Z0-9.:_]+)
endelementname (<\/[a-zA-Z][a-zA-Z0-9.:_]+)
%% 


{xmlwhitespace} 


 {quote} {YY_PRINT; return(QUOTE);}
({xmlwhitespace}*{greater_than}) {YY_PRINT; if(beginElementText == true){BEGIN elementtext; } return(GREATERTHAN);}
-?[0-9]+  {YY_PRINT; osrllval.ival = atoi(osrltext); return(INTEGER);}
-?((([0-9]+)|([0-9]*\.[0-9]+))([eE][-+]?[0-9]+)?|INF) {YY_PRINT; osrllval.dval = atof(osrltext); return(DOUBLE);}
({xmlwhitespace}*\/>) {YY_PRINT;  return(ENDOFELEMENT);}


{xmlwhitespace}*\<osrl{xmlwhitespace}+ {YY_PRINT; BEGIN osrlattributetext;  return(OSRLSTART);}
{xmlwhitespace}*\<\/osrl{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(OSRLEND);}
{xmlwhitespace}*\<resultHeader{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(RESULTHEADERSTART);}
{xmlwhitespace}*\<\/resultHeader{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(RESULTHEADEREND);}
{xmlwhitespace}*\<serviceURI{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; BEGIN elementtext; return(SERVICEURISTART);}
{xmlwhitespace}*\<serviceURI{xmlwhitespace}*\>\< {YY_PRINT; unput('<'); return(SERVICEURISTART);}
{xmlwhitespace}*\<\/serviceURI{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT;  return(SERVICEURIEND);}
{xmlwhitespace}*\<serviceName{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; BEGIN elementtext; return(SERVICENAMESTART);}
{xmlwhitespace}*\<serviceName{xmlwhitespace}*\>\< {YY_PRINT; unput('<'); return(SERVICENAMESTART);}
{xmlwhitespace}*\<\/serviceName{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT;  return(SERVICENAMEEND);}
{xmlwhitespace}*\<instanceName{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; BEGIN elementtext; return(INSTANCENAMESTART);}
{xmlwhitespace}*\<instanceName{xmlwhitespace}*\>\< {YY_PRINT; unput('<'); return(INSTANCENAMESTART);}
{xmlwhitespace}*\<\/instanceName{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT;  return(INSTANCENAMEEND);}
{xmlwhitespace}*\<jobID{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; BEGIN elementtext; return(JOBIDSTART);}
{xmlwhitespace}*\<jobID{xmlwhitespace}*\>\< {YY_PRINT; unput('<'); return(JOBIDSTART);}
{xmlwhitespace}*\<\/jobID{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT;  return(JOBIDEND);}
{xmlwhitespace}*\<message{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; BEGIN elementtext; return(HEADERMESSAGESTART);}
{xmlwhitespace}*\<message{xmlwhitespace}*\>\< {YY_PRINT; unput('<'); return(HEADERMESSAGESTART);}
{xmlwhitespace}*\<\/message{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT;  return(HEADERMESSAGEEND);}

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

{xmlwhitespace}*\<message{xmlwhitespace}*\> {YY_PRINT;  BEGIN elementtext; return(MESSAGESTART);}
{xmlwhitespace}*\<message{xmlwhitespace}*\>\< {YY_PRINT; unput('<'); return(MESSAGESTART);}
(\<\/message{xmlwhitespace}*\>) {YY_PRINT;  return(MESSAGEEND);}

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
(\<message{xmlwhitespace}*\/>) {YY_PRINT;  return(HEADERMESSAGESTARTANDEND);}
(\<resultData{xmlwhitespace}*\/>) {YY_PRINT;  return(RESULTDATASTARTANDEND);}






"<!--" BEGIN comment;
 <comment>. |
 <comment>\n ;
 <comment>"-->" BEGIN 0;
 
"<?" BEGIN xmldeclaration;
 <xmldeclaration>. |
 <xmldeclaration>\n ;
 
 <xmldeclaration>"?>" BEGIN 0;




<elementtext>([^\<])+ { YY_PRINT;  osrllval.charval = strdup(osrltext); BEGIN 0;  return(ELEMENTTEXT); }
<attributetext>([^\"\'])+ {YY_PRINT;    osrllval.charval = strdup(osrltext);
							BEGIN 0;  return(ATTRIBUTETEXT);}
							
<osrlattributetext>([^>])* {YY_PRINT;  BEGIN 0; osrllval.charval = strdup(osrltext); return(OSRLATTRIBUTETEXT);}


.|\n { osrlerror( "ecountered a spurious character in the lexer");}




%%


