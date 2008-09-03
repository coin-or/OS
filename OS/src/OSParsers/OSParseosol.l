/** @file parseosol.l
 * 
 * @author  Robert Fourer, Gus Gassmann, Jun Ma, Kipp Martin, 
 * @version 1.1, 10/07/2008
 * @since   OS1.1
 *
 * \remarks
 * Copyright (C) 2005-2008, Robert Fourer, Gus Gassmann, Jun Ma, Kipp Martin,
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

 
#include <sstream>  
#include "OSoLParserData.h"
#include "OSErrorClass.h"
#include "OSParseosol.tab.hpp"
#include "OSOption.h"
    
#ifdef PARSERDEBUG
	#define YY_PRINT  printf("%s", osoltext);
#else     
	#define YY_PRINT  ;
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

%option prefix="osol"
%option noyywrap
%option reentrant
%option bison-bridge
%option bison-locations
%option yylineno   

%x osolattributetext
%x doublequoteattributetext
%x singlequoteattributetext
%x startelement
%x elementtext
%x comment
%x xmldeclaration
  


%{
#define YY_EXTRA_TYPE OSoLParserData*
%} 
 
xmlwhitespace ([ \t\n\r])
equality ([ \t\n\r])*=([ \t\n\r])*
quote [\" | \']  
greater_than (>)
aninteger (-?[0-9]+)
adouble (-?((([0-9]+)|([0-9]*\.[0-9]*))([eE][-+]?[0-9]+)?|INF))

%%

 
{xmlwhitespace}

 /* General patterns matched in more than one element */


{quote} {YY_PRINT;  yylval->sval = yytext; return(QUOTE);}
({xmlwhitespace}*{greater_than}) {YY_PRINT; return(GREATERTHAN);}
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


({xmlwhitespace}+locationType{equality}\") {YY_PRINT; BEGIN doublequoteattributetext; return(LOCATIONTYPEATT);}
({xmlwhitespace}+locationType{equality}\') {YY_PRINT; BEGIN singlequoteattributetext; return(LOCATIONTYPEATT);}
({xmlwhitespace}+transportType{equality}\") {YY_PRINT; BEGIN doublequoteattributetext; return(TRANSPORTTYPEATT);}
({xmlwhitespace}+transportType{equality}\') {YY_PRINT; BEGIN singlequoteattributetext; return(TRANSPORTTYPEATT);}
({xmlwhitespace}+name{equality}\") {YY_PRINT; BEGIN doublequoteattributetext; return(NAMEATT);}
({xmlwhitespace}+name{equality}\') {YY_PRINT; BEGIN singlequoteattributetext; return(NAMEATT);}
({xmlwhitespace}+numberOfJobIDs{equality}\') {YY_PRINT; BEGIN doublequoteattributetext; return(NUMBEROFJOBIDSATT);}
({xmlwhitespace}+numberOfJobIDs{equality}\') {YY_PRINT; BEGIN singlequoteattributetext; return(NUMBEROFJOBIDSATT);}
({xmlwhitespace}+numberOfPaths{equality}\') {YY_PRINT; BEGIN doublequoteattributetext; return(NUMBEROFPATHSATT);}
({xmlwhitespace}+numberOfPaths{equality}\') {YY_PRINT; BEGIN singlequoteattributetext; return(NUMBEROFPATHSATT);}
({xmlwhitespace}+numberOfProcesses{equality}\') {YY_PRINT; BEGIN doublequoteattributetext; return(NUMBEROFPROCESSESATT);}
({xmlwhitespace}+numberOfProcesses{equality}\') {YY_PRINT; BEGIN singlequoteattributetext; return(NUMBEROFPROCESSESATT);}
({xmlwhitespace}+numberOfVariables{equality}\') {YY_PRINT; BEGIN doublequoteattributetext; return(NUMBEROFVARIABLESATT);}
({xmlwhitespace}+numberOfVariables{equality}\') {YY_PRINT; BEGIN singlequoteattributetext; return(NUMBEROFVARIABLESATT);}
({xmlwhitespace}+numberOfObjectives{equality}\') {YY_PRINT; BEGIN doublequoteattributetext; return(NUMBEROFOBJECTIVESATT);}
({xmlwhitespace}+numberOfObjectives{equality}\') {YY_PRINT; BEGIN singlequoteattributetext; return(NUMBEROFOBJECTIVESATT);}
({xmlwhitespace}+numberOfConstraints{equality}\') {YY_PRINT; BEGIN doublequoteattributetext; return(NUMBEROFCONSTRAINTSATT);}
({xmlwhitespace}+numberOfConstraints{equality}\') {YY_PRINT; BEGIN singlequoteattributetext; return(NUMBEROFCONSTRAINTSATT);}
({xmlwhitespace}+numberOfOtherOptions{equality}\') {YY_PRINT; BEGIN doublequoteattributetext; return(NUMBEROFOTHEROPTIONSATT);}
({xmlwhitespace}+numberOfOtherOptions{equality}\') {YY_PRINT; BEGIN singlequoteattributetext; return(NUMBEROFOTHEROPTIONSATT);}
({xmlwhitespace}+numberOfOtherVariableOptions{equality}\') {YY_PRINT; BEGIN doublequoteattributetext; return(NUMBEROFOTHERVARIABLEOPTIONSATT);}
({xmlwhitespace}+numberOfOtherVariableOptions{equality}\') {YY_PRINT; BEGIN singlequoteattributetext; return(NUMBEROFOTHERVARIABLEOPTIONSATT);}
({xmlwhitespace}+numberOfVar{equality}\') {YY_PRINT; BEGIN doublequoteattributetext; return(NUMBEROFVARATT);}
({xmlwhitespace}+numberOfVar{equality}\') {YY_PRINT; BEGIN singlequoteattributetext; return(NUMBEROFVARATT);}
({xmlwhitespace}+idx{equality}\') {YY_PRINT; BEGIN doublequoteattributetext; return(IDXATT);}
({xmlwhitespace}+idx{equality}\') {YY_PRINT; BEGIN singlequoteattributetext; return(IDXATT);}
({xmlwhitespace}+value{equality}\') {YY_PRINT; BEGIN doublequoteattributetext; return(VALUEATT);}
({xmlwhitespace}+value{equality}\') {YY_PRINT; BEGIN singlequoteattributetext; return(VALUEATT);}
({xmlwhitespace}+description{equality}\") {YY_PRINT; BEGIN doublequoteattributetext; return(DESCRIPTIONATT);}
({xmlwhitespace}+description{equality}\') {YY_PRINT; BEGIN singlequoteattributetext; return(DESCRIPTIONATT);}
({xmlwhitespace}+lbValue{equality}\') {YY_PRINT; BEGIN doublequoteattributetext; return(LBVALUEATT);}
({xmlwhitespace}+lbValue{equality}\') {YY_PRINT; BEGIN singlequoteattributetext; return(LBVALUEATT);}
({xmlwhitespace}+ubValue{equality}\') {YY_PRINT; BEGIN doublequoteattributetext; return(UBVALUEATT);}
({xmlwhitespace}+ubValue{equality}\') {YY_PRINT; BEGIN singlequoteattributetext; return(UBVALUEATT);}
({xmlwhitespace}+numberOfOtherObjectiveOptions{equality}\') {YY_PRINT; BEGIN doublequoteattributetext; return(NUMBEROFOTHEROBJECTIVEOPTIONSATT);}
({xmlwhitespace}+numberOfOtherObjectiveOptions{equality}\') {YY_PRINT; BEGIN singlequoteattributetext; return(NUMBEROFOTHEROBJECTIVEOPTIONSATT);}
({xmlwhitespace}+numberOfObj{equality}\') {YY_PRINT; BEGIN doublequoteattributetext; return(NUMBEROFOBJATT);}
({xmlwhitespace}+numberOfObj{equality}\') {YY_PRINT; BEGIN singlequoteattributetext; return(NUMBEROFOBJATT);}
({xmlwhitespace}+numberOfOtherConstraintOptions{equality}\') {YY_PRINT; BEGIN doublequoteattributetext; return(NUMBEROFOTHERCONSTRAINTOPTIONSATT);}
({xmlwhitespace}+numberOfOtherConstraintOptions{equality}\') {YY_PRINT; BEGIN singlequoteattributetext; return(NUMBEROFOTHERCONSTRAINTOPTIONSATT);}
({xmlwhitespace}+numberOfCon{equality}\') {YY_PRINT; BEGIN doublequoteattributetext; return(NUMBEROFCONATT);}
({xmlwhitespace}+numberOfCon{equality}\') {YY_PRINT; BEGIN singlequoteattributetext; return(NUMBEROFCONATT);}


{xmlwhitespace}*\<osol{xmlwhitespace}+ {YY_PRINT; BEGIN osolattributetext;  return(OSOLSTART);}
{xmlwhitespace}*\<\/osol{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(OSOLEND);}
{xmlwhitespace}*\<general {YY_PRINT; return(GENERALSTART);}
{xmlwhitespace}*\<\/general{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(GENERALEND);}
{xmlwhitespace}*\<system {YY_PRINT; return(SYSTEMSTART);}
{xmlwhitespace}*\<\/system{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(SYSTEMEND);}
{xmlwhitespace}*\<service {YY_PRINT; return(SERVICESTART);}
{xmlwhitespace}*\<\/service{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(SERVICEEND);}
{xmlwhitespace}*\<job {YY_PRINT; return(JOBSTART);}
{xmlwhitespace}*\<\/job{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(JOBEND);}
{xmlwhitespace}*\<optimization {YY_PRINT; return(OPTIMIZATIONSTART);}
{xmlwhitespace}*\<\/optimization{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(OPTIMIZATIONEND);}
{xmlwhitespace}*\<other {YY_PRINT; return(OTHERSTART);}
{xmlwhitespace}*\<\/other{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(OTHEREND);}

{xmlwhitespace}*\<serviceURI {YY_PRINT; return(SERVICEURISTART);}
{xmlwhitespace}*\<\/serviceURI{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(SERVICEURIEND);}
{xmlwhitespace}*\<serviceName {YY_PRINT; return(SERVICENAMESTART);}
{xmlwhitespace}*\<\/serviceName{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(SERVICENAMEEND);}
{xmlwhitespace}*\<instanceName {YY_PRINT; return(INSTANCENAMESTART);}
{xmlwhitespace}*\<\/instanceName{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(INSTANCENAMEEND);}
{xmlwhitespace}*\<instanceLocation {YY_PRINT; return(INSTANCELOCATIONSTART);}
{xmlwhitespace}*\<\/instanceLocation{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(INSTANCELOCATIONEND);}
{xmlwhitespace}*\<jobID {YY_PRINT; return(JOBIDSTART);}
{xmlwhitespace}*\<\/jobID{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(JOBIDEND);}
{xmlwhitespace}*\<license {YY_PRINT; return(LICENSESTART);}
{xmlwhitespace}*\<\/license{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(LICENSEEND);}
{xmlwhitespace}*\<userName {YY_PRINT; return(USERNAMESTART);}
{xmlwhitespace}*\<\/userName{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(USERNAMEEND);}
{xmlwhitespace}*\<password {YY_PRINT; return(PASSWORDSTART);}
{xmlwhitespace}*\<\/password{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(PASSWORDEND);}
{xmlwhitespace}*\<contact {YY_PRINT; return(CONTACTSTART);}
{xmlwhitespace}*\<\/contact{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(CONTACTEND);}

{xmlwhitespace}*\<minDiskSpace {YY_PRINT; return(MINDISKSPACESTART);}
{xmlwhitespace}*\<\/minDiskSpace{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(MINDISKSPACEEND);}
{xmlwhitespace}*\<minMemorySize {YY_PRINT; return(MINMEMORYSIZESTART);}
{xmlwhitespace}*\<\/minMemorySize{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(MINMEMORYSIZEEND);}
{xmlwhitespace}*\<minCPUSpeed {YY_PRINT; return(MINCPUSPEEDSTART);}
{xmlwhitespace}*\<\/minCPUSpeed{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(MINCPUSPEEDEND);}

{xmlwhitespace}*\<type {YY_PRINT; return(SERVICETYPESTART);}
{xmlwhitespace}*\<\/type{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(SERVICETYPEEND);}

{xmlwhitespace}*\<maxTime {YY_PRINT; return(MAXTIMESTART);}
{xmlwhitespace}*\<\/maxTime{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(MAXTIMEEND);}
{xmlwhitespace}*\<scheduledStartTime {YY_PRINT; return(SCHEDULEDSTARTTIMESTART);}
{xmlwhitespace}*\<\/scheduledStartTime{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(SCHEDULEDSTARTTIMEEND);}
{xmlwhitespace}*\<dependencies {YY_PRINT; return(DEPENDENCIESSTART);}
{xmlwhitespace}*\<\/dependencies{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(DEPENDENCIESEND);}
{xmlwhitespace}*\<jobID {YY_PRINT; return(JOBIDSTART);}
{xmlwhitespace}*\<\/jobID{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(JOBIDEND);}
{xmlwhitespace}*\<requiredDirectoriesAndFiles {YY_PRINT; return(REQDIRSTART);}
{xmlwhitespace}*\<\/requiredDirectoriesAndFiles{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(REQDIREND);}
{xmlwhitespace}*\<path {YY_PRINT; return(PATHSTART);}
{xmlwhitespace}*\<\/path{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(PATHEND);}
{xmlwhitespace}*\<directoriesToMake {YY_PRINT; return(MAKEDIRSTART);}
{xmlwhitespace}*\<\/directoriesToMake{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(MAKEDIREND);}
{xmlwhitespace}*\<filesToCreate {YY_PRINT; return(MAKEFILESTART);}
{xmlwhitespace}*\<\/filesToCreate{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(MAKEFILEEND);}
{xmlwhitespace}*\<inputFilesToCopyFrom {YY_PRINT; return(INPUTCOPYFROMSTART);}
{xmlwhitespace}*\<\/inputFilesToCopyFrom{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(INPUTCOPYFROMEND);}
{xmlwhitespace}*\<inputFilesToCopyTo {YY_PRINT; return(INPUTCOPYTOSTART);}
{xmlwhitespace}*\<\/inputFilesToCopyTo{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(INPUTCOPYTOEND);}
{xmlwhitespace}*\<inputFilesToMoveFrom {YY_PRINT; return(INPUTMOVEFROMSTART);}
{xmlwhitespace}*\<\/inputFilesToMoveFrom{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(INPUTMOVEFROMEND);}
{xmlwhitespace}*\<inputFilesToMoveTo {YY_PRINT; return(INPUTMOVETOSTART);}
{xmlwhitespace}*\<\/inputFilesToMoveTo{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(INPUTMOVETOEND);}
{xmlwhitespace}*\<outputFilesToCopyFrom {YY_PRINT; return(OUTPUTCOPYFROMSTART);}
{xmlwhitespace}*\<\/outputFilesToCopyFrom{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(OUTPUTCOPYFROMEND);}
{xmlwhitespace}*\<outputFilesToCopyTo {YY_PRINT; return(OUTPUTCOPYTOSTART);}
{xmlwhitespace}*\<\/outputFilesToCopyTo{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(OUTPUTCOPYTOEND);}
{xmlwhitespace}*\<outputFilesToMoveFrom {YY_PRINT; return(OUTPUTMOVEFROMSTART);}
{xmlwhitespace}*\<\/outputFilesToMoveFrom{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(OUTPUTMOVEFROMEND);}
{xmlwhitespace}*\<outputFilesToMoveTo {YY_PRINT; return(OUTPUTMOVETOSTART);}
{xmlwhitespace}*\<\/outputFilesToMoveTo{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(OUTPUTMOVETOEND);}
{xmlwhitespace}*\<directoriesToDelete {YY_PRINT; return(DELDIRSTART);}
{xmlwhitespace}*\<\/directoriesToDelete{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(DELDIREND);}
{xmlwhitespace}*\<filesToDelete {YY_PRINT; return(DELFILESTART);}
{xmlwhitespace}*\<\/filesToDelete{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(DELFILEEND);}
{xmlwhitespace}*\<processesToKill {YY_PRINT; return(PROCESSESTOKILLSTART);}
{xmlwhitespace}*\<\/processesToKill{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(PROCESSESTOKILLEND);}
{xmlwhitespace}*\<process {YY_PRINT; return(PROCESSSTART);}
{xmlwhitespace}*\<\/process{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(PROCESSEND);}


{xmlwhitespace}*\<variables {YY_PRINT; return(OPTIMIZATIONVARIABLESSTART);}
{xmlwhitespace}*\<\/variables{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(OPTIMIZATIONVARIABLESEND);}
{xmlwhitespace}*\<initialVariableValues {YY_PRINT; return(INITIALVARIABLESSTART);}
{xmlwhitespace}*\<\/initialVariableValues{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(INITIALVARIABLESEND);}
{xmlwhitespace}*\<var {YY_PRINT; return(INITIALVARSTART);}
{xmlwhitespace}*\<\/var{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(INITIALVAREND);}
{xmlwhitespace}*\<objectives {YY_PRINT; return(OPTIMIZATIONOBJECTIVESSTART);}
{xmlwhitespace}*\<\/objectives{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(OPTIMIZATIONOBJECTIVESEND);}
{xmlwhitespace}*\<initialObjectiveValues {YY_PRINT; return(INITIALOBJVALUESSTART);}
{xmlwhitespace}*\<\/initialObjectiveValues{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(INITIALOBJVALUESEND);}
{xmlwhitespace}*\<obj {YY_PRINT; return(OPTIMIZATIONINITIALOBJSTART);}
{xmlwhitespace}*\<\/obj{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(OPTIMIZATIONINITIALOBJEND);}
{xmlwhitespace}*\<initialObjectiveBounds {YY_PRINT; return(INITIALOBJBOUNDSSTART);}
{xmlwhitespace}*\<\/initialObjectiveBounds{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(INITIALOBJBOUNDSEND);}
{xmlwhitespace}*\<constraints {YY_PRINT; return(OPTIMIZATIONCONSTRAINTSSTART);}
{xmlwhitespace}*\<\/constraints{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(OPTIMIZATIONCONSTRAINTSEND);}
{xmlwhitespace}*\<initialConstraintValues {YY_PRINT; return(INITIALCONSTRAINTSSTART);}
{xmlwhitespace}*\<\/initialConstraintValues{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(INITIALCONSTRAINTSEND);}
{xmlwhitespace}*\<con {YY_PRINT; return(INITIALCONSTART);}
{xmlwhitespace}*\<\/con{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(INITIALCONEND);}
{xmlwhitespace}*\<initialDualValues {YY_PRINT; return(INITIALDUALSSTART);}
{xmlwhitespace}*\<\/initialDualValues{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(INITIALDUALSEND);}


[a-zA-X0-9.:_*#$@ \n]+ { YY_PRINT;  yylval->sval = strdup( yytext);   yyextra->errorText = yylval->sval;    /*yylval->sval = yytext;*/  return (ELEMENTTEXT); }


 "<!--" BEGIN comment;
 <comment>. |
 <comment>\n ;
 <comment>"-->" BEGIN 0;
 
  "<?" BEGIN xmldeclaration;
 <xmldeclaration>. |
 <xmldeclaration>\n ;
 <xmldeclaration>"?>" BEGIN 0;
 

<doublequoteattributetext>[^\"]* {YY_PRINT;  BEGIN 0; /*yylval->sval = strdup(yytext);*/ yylval->sval = yytext; return(ATTRIBUTETEXT);}
<singlequoteattributetext>[^\']* {YY_PRINT;  BEGIN 0; /*yylval->sval = strdup(yytext);*/ yylval->sval = yytext; return(ATTRIBUTETEXT);}
<osolattributetext>([^>])* {YY_PRINT;  BEGIN 0; /*yylval->sval = strdup(yytext);*/  yylval->sval = yytext; return(OSOLATTRIBUTETEXT);}

. {  
	std::string error;
	std::ostringstream outStr;
	outStr << "encountered a spurious character in the lexer" << endl;
	outStr << "The first character is: ";
	outStr <<  yytext;
	outStr << endl;
	outStr << "See line number: " << yylineno << endl;  
	error = outStr.str();
	throw ErrorClass( error);
}

%%


