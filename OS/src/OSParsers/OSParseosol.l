/* $Id$ */
/** @file OSparseosol.l.1
 * 
 * @author  Horand Gassmann, Jun Ma, Kipp Martin 
 *
 * \remarks
 * Copyright (C) 2005-2013, Horand Gassmann, Jun Ma, Kipp Martin,
 * Northwestern University, and the University of Chicago.
 * All Rights Reserved.
 * This software is licensed under the Eclipse Public License. 
 * Please see the accompanying LICENSE file in root directory for terms.
 * 
 * Like the grammar rules in OSParseosol.y, this file is maintained in several pieces 
 * in order to avoid duplication when parsing elements of auxiliary schemas,
 * such as OSgL, OSnL, etc. This is the first part of OSparseosol.l.   
 */
%{

#include <iostream>
#include <sstream>  

#include "OSConfig.h"
#include "OSDataStructures.h"
#include "OSErrorClass.h"
#include "OSMathUtil.h"
#include "OSoLParserData.h"
#include "OSParseosol.tab.hpp"
#include "OSOption.h"
#include "OSGeneral.h"

#ifdef HAVE_CSTDIO
# include <cstdio>
#else
# ifdef HAVE_STDIO_H
#  include <stdio.h>
# else
#  error "don't have header file for stdio"
# endif
#endif

#ifdef HAVE_CTIME
# include <ctime>
#else
# ifdef HAVE_TIME_H
#  include <time.h>
# else
#  error "don't have header file for time"
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

#ifdef HAVE_CSTRING
# include <cstring>
#else
# ifdef HAVE_STRING_H
#  include <string.h>
# else
#  error "don't have header file for string"
# endif
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
 
//#define OSOLPARSERDEBUG

#ifdef OSOLPARSERDEBUG
	#define YY_PRINT  printf("%s", yytext);
#else     
	#define YY_PRINT;
#endif

%}

%option prefix="osol"
%option noyywrap
%option reentrant
%option bison-bridge
%option bison-locations
%option yylineno   
%option nounput

%x osolattributetext
%x doublequoteattributetext
%x singlequoteattributetext
%x startelement
%x elementtext
%x itemtext
%x comment
%x xmldeclaration
  
%{
#define YY_EXTRA_TYPE OSoLParserData*
%} 
 
xmlwhitespace ([ \t\n\r])
equality ([ \t\n\r])*=([ \t\n\r])*
quote [\"|\']  
twoquotes (\"\"|\'\')
greater_than (>)
aninteger ([ \t\n\r]*-?[0-9]+[ \t\n\r]*)
adouble ([ \t\n\r]*(-?(([0-9]+|[0-9]*\.[0-9]*)([eE][-+]?[0-9]+)?|INF)|NaN)[ \t\n\r]*)
%%
 
{xmlwhitespace}*

 /* General patterns matched in more than one element */

{quote} {YY_PRINT;  yylval->sval = yytext; return(QUOTE);}
{twoquotes} {YY_PRINT;  yylval->sval = yytext; return(TWOQUOTES);}
({xmlwhitespace}*{greater_than}) {YY_PRINT; return(GREATERTHAN);}
{aninteger} {YY_PRINT; yylval->ival = atoi(yytext); return(INTEGER);}

{adouble} {YY_PRINT; 
char *yytextEnd;
yylval->dval = os_strtod_wrap( yytext, &yytextEnd);
/*
	if( (unsigned)(yytextEnd - yytext) != strlen( yytext)){
		std::ostringstream outStr;
		outStr << "encountered a spurious character in the lexer" << endl;
		outStr << "The first character is: \'";
		outStr <<  yytext << "\'";
		outStr << endl;
		outStr << "See line number: " << yylineno << endl;  
		throw ErrorClass( outStr.str());
	}
*/
return(DOUBLE);}

({xmlwhitespace}*\/>) {YY_PRINT;  return(ENDOFELEMENT);}

 /* attributes returning numeric values*/

({xmlwhitespace}+numberOfOtherOptions{equality}) {YY_PRINT; return(NUMBEROFOTHEROPTIONSATT);}
({xmlwhitespace}+numberOfJobIDs{equality}) {YY_PRINT; return(NUMBEROFJOBIDSATT);}
({xmlwhitespace}+numberOfEl{equality}) {YY_PRINT;  return(NUMBEROFELATT);}
({xmlwhitespace}+numberOfEnumerations{equality}) {YY_PRINT;  return(NUMBEROFENUMERATIONSATT);}
({xmlwhitespace}+numberOfPaths{equality}) {YY_PRINT; return(NUMBEROFPATHSATT);}
({xmlwhitespace}+numberOfItems{equality}) {YY_PRINT; return(NUMBEROFITEMSATT);}
({xmlwhitespace}+numberOfPathPairs{equality}) {YY_PRINT; return(NUMBEROFPATHPAIRSATT);}
({xmlwhitespace}+numberOfProcesses{equality}) {YY_PRINT; return(NUMBEROFPROCESSESATT);}
({xmlwhitespace}+numberOfVariables{equality}) {YY_PRINT; return(NUMBEROFVARIABLESATT);}
({xmlwhitespace}+numberOfObjectives{equality}) {YY_PRINT; return(NUMBEROFOBJECTIVESATT);}
({xmlwhitespace}+numberOfConstraints{equality}) {YY_PRINT; return(NUMBEROFCONSTRAINTSATT);}
({xmlwhitespace}+numberOfOtherVariableOptions{equality}) {YY_PRINT; return(NUMBEROFOTHERVARIABLEOPTIONSATT);}
({xmlwhitespace}+numberOfVar{equality}) {YY_PRINT; return(NUMBEROFVARATT);}
({xmlwhitespace}+numberOfSOS{equality}) {YY_PRINT; return(NUMBEROFSOSATT);}
({xmlwhitespace}+numberOfOtherObjectiveOptions{equality}) {YY_PRINT; return(NUMBEROFOTHEROBJECTIVEOPTIONSATT);}
({xmlwhitespace}+numberOfObj{equality}) {YY_PRINT; return(NUMBEROFOBJATT);}
({xmlwhitespace}+numberOfOtherConstraintOptions{equality}) {YY_PRINT; return(NUMBEROFOTHERCONSTRAINTOPTIONSATT);}
({xmlwhitespace}+numberOfCon{equality}) {YY_PRINT; return(NUMBEROFCONATT);}
({xmlwhitespace}+numberOfSolverOptions{equality}) {YY_PRINT; return(NUMBEROFSOLVEROPTIONSATT);}

({xmlwhitespace}+numberOfCon{equality}) {YY_PRINT; return(NUMBEROFROWSATT);}
({xmlwhitespace}+numberOfCon{equality}) {YY_PRINT; return(NUMBEROFCOLUMNSATT);}

({xmlwhitespace}+idx{equality}) {YY_PRINT; return(IDXATT);}
({xmlwhitespace}+incr{equality}) {YY_PRINT; return(INCRATT);}
({xmlwhitespace}+mult{equality}) {YY_PRINT; return(MULTATT);}
({xmlwhitespace}+sizeOf{equality}) {YY_PRINT; return(SIZEOFATT);}
({xmlwhitespace}+sosIdx{equality}) {YY_PRINT; return(SOSIDXATT);}
({xmlwhitespace}+groupWeight{equality}) {YY_PRINT; return(GROUPWEIGHTATT);}
({xmlwhitespace}+lbDualValue{equality}) {YY_PRINT; return(LBDUALVALUEATT);}
({xmlwhitespace}+ubDualValue{equality}) {YY_PRINT; return(UBDUALVALUEATT);}

 /* attributes returning strings (that are potentially empty)*/

({xmlwhitespace}+category{equality}\"\") {YY_PRINT; return(EMPTYCATEGORYATT);}
({xmlwhitespace}+category{equality}\'\') {YY_PRINT; return(EMPTYCATEGORYATT);}
({xmlwhitespace}+category{equality}\") {YY_PRINT; BEGIN doublequoteattributetext; return(CATEGORYATT);}
({xmlwhitespace}+category{equality}\') {YY_PRINT; BEGIN singlequoteattributetext; return(CATEGORYATT);}
({xmlwhitespace}+conType{equality}\"\") {YY_PRINT; return(EMPTYCONTYPEATT);}
({xmlwhitespace}+conType{equality}\'\') {YY_PRINT; return(EMPTYCONTYPEATT);}
({xmlwhitespace}+conType{equality}\") {YY_PRINT; BEGIN doublequoteattributetext; return(CONTYPEATT);}
({xmlwhitespace}+conType{equality}\') {YY_PRINT; BEGIN singlequoteattributetext; return(CONTYPEATT);}
({xmlwhitespace}+description{equality}\"\") {YY_PRINT; return(EMPTYDESCRIPTIONATT);}
({xmlwhitespace}+description{equality}\'\') {YY_PRINT; return(EMPTYDESCRIPTIONATT);}
({xmlwhitespace}+description{equality}\") {YY_PRINT; BEGIN doublequoteattributetext; return(DESCRIPTIONATT);}
({xmlwhitespace}+description{equality}\') {YY_PRINT; BEGIN singlequoteattributetext; return(DESCRIPTIONATT);}
({xmlwhitespace}+enumType{equality}\"\") {YY_PRINT; return(EMPTYENUMTYPEATT);}
({xmlwhitespace}+enumType{equality}\'\') {YY_PRINT; return(EMPTYENUMTYPEATT);}
({xmlwhitespace}+enumType{equality}\") {YY_PRINT; BEGIN doublequoteattributetext; return(ENUMTYPEATT);}
({xmlwhitespace}+enumType{equality}\') {YY_PRINT; BEGIN singlequoteattributetext; return(ENUMTYPEATT);}
({xmlwhitespace}+lbValue{equality}\"\") {YY_PRINT; return(EMPTYLBVALUEATT);}
({xmlwhitespace}+lbValue{equality}\'\') {YY_PRINT; return(EMPTYLBVALUEATT);}
({xmlwhitespace}+lbValue{equality}\") {YY_PRINT; BEGIN doublequoteattributetext; return(LBVALUEATT);}
({xmlwhitespace}+lbValue{equality}\') {YY_PRINT; BEGIN singlequoteattributetext; return(LBVALUEATT);}
({xmlwhitespace}+locationType{equality}\') {YY_PRINT; BEGIN singlequoteattributetext; return(LOCATIONTYPEATT);}
({xmlwhitespace}+locationType{equality}\") {YY_PRINT; BEGIN doublequoteattributetext; return(LOCATIONTYPEATT);}
({xmlwhitespace}+name{equality}\"\") {YY_PRINT; return(EMPTYNAMEATT);}
({xmlwhitespace}+name{equality}\'\') {YY_PRINT; return(EMPTYNAMEATT);}
({xmlwhitespace}+name{equality}\") {YY_PRINT; BEGIN doublequoteattributetext; return(NAMEATT);}
({xmlwhitespace}+name{equality}\') {YY_PRINT; BEGIN singlequoteattributetext; return(NAMEATT);}
({xmlwhitespace}+objType{equality}\"\") {YY_PRINT; return(EMPTYOBJTYPEATT);}
({xmlwhitespace}+objType{equality}\'\') {YY_PRINT; return(EMPTYOBJTYPEATT);}
({xmlwhitespace}+objType{equality}\") {YY_PRINT; BEGIN doublequoteattributetext; return(OBJTYPEATT);}
({xmlwhitespace}+objType{equality}\') {YY_PRINT; BEGIN singlequoteattributetext; return(OBJTYPEATT);}
({xmlwhitespace}+solver{equality}\"\") {YY_PRINT; return(EMPTYSOLVERATT);}
({xmlwhitespace}+solver{equality}\'\') {YY_PRINT; return(EMPTYSOLVERATT);}
({xmlwhitespace}+solver{equality}\") {YY_PRINT; BEGIN doublequoteattributetext; return(SOLVERATT);}
({xmlwhitespace}+solver{equality}\') {YY_PRINT; BEGIN singlequoteattributetext; return(SOLVERATT);}
({xmlwhitespace}+type{equality}\"\") {YY_PRINT; return(EMPTYTYPEATT);}
({xmlwhitespace}+type{equality}\'\') {YY_PRINT; return(EMPTYTYPEATT);}
({xmlwhitespace}+type{equality}\") {YY_PRINT; BEGIN doublequoteattributetext; return(TYPEATT);}
({xmlwhitespace}+type{equality}\') {YY_PRINT; BEGIN singlequoteattributetext; return(TYPEATT);}
({xmlwhitespace}+transportType{equality}\') {YY_PRINT; BEGIN singlequoteattributetext; return(TRANSPORTTYPEATT);}
({xmlwhitespace}+transportType{equality}\") {YY_PRINT; BEGIN doublequoteattributetext; return(TRANSPORTTYPEATT);}
({xmlwhitespace}+ubValue{equality}\"\") {YY_PRINT; return(EMPTYUBVALUEATT);}
({xmlwhitespace}+ubValue{equality}\'\') {YY_PRINT; return(EMPTYUBVALUEATT);}
({xmlwhitespace}+ubValue{equality}\") {YY_PRINT; BEGIN doublequoteattributetext; return(UBVALUEATT);}
({xmlwhitespace}+ubValue{equality}\') {YY_PRINT; BEGIN singlequoteattributetext; return(UBVALUEATT);}
({xmlwhitespace}+unit{equality}\"\") {YY_PRINT; return(EMPTYUNITATT);}
({xmlwhitespace}+unit{equality}\'\') {YY_PRINT; return(EMPTYUNITATT);}
({xmlwhitespace}+unit{equality}\") {YY_PRINT; BEGIN doublequoteattributetext; return(UNITATT);}
({xmlwhitespace}+unit{equality}\') {YY_PRINT; BEGIN singlequoteattributetext; return(UNITATT);}
({xmlwhitespace}+value{equality}\"\") {YY_PRINT; return(EMPTYVALUEATT);}
({xmlwhitespace}+value{equality}\'\') {YY_PRINT; return(EMPTYVALUEATT);}
({xmlwhitespace}+value{equality}\") {YY_PRINT; BEGIN doublequoteattributetext; return(VALUEATT);}
({xmlwhitespace}+value{equality}\') {YY_PRINT; BEGIN singlequoteattributetext; return(VALUEATT);}
({xmlwhitespace}+varType{equality}\"\") {YY_PRINT; return(EMPTYVARTYPEATT);}
({xmlwhitespace}+varType{equality}\'\') {YY_PRINT; return(EMPTYVARTYPEATT);}
({xmlwhitespace}+varType{equality}\") {YY_PRINT; BEGIN doublequoteattributetext; return(VARTYPEATT);}
({xmlwhitespace}+varType{equality}\') {YY_PRINT; BEGIN singlequoteattributetext; return(VARTYPEATT);}
({xmlwhitespace}+weight{equality}\"\") {YY_PRINT; return(EMPTYWEIGHTATT);}
({xmlwhitespace}+weight{equality}\'\') {YY_PRINT; return(EMPTYWEIGHTATT);}
({xmlwhitespace}+weight{equality}\") {YY_PRINT; BEGIN doublequoteattributetext; return(WEIGHTATT);}
({xmlwhitespace}+weight{equality}\') {YY_PRINT; BEGIN singlequoteattributetext; return(WEIGHTATT);}

({xmlwhitespace}+from{equality}\") {YY_PRINT; BEGIN doublequoteattributetext; return(FROMATT);}
({xmlwhitespace}+from{equality}\') {YY_PRINT; BEGIN singlequoteattributetext; return(FROMATT);}
({xmlwhitespace}+to{equality}\") {YY_PRINT; BEGIN doublequoteattributetext; return(TOATT);}
({xmlwhitespace}+to{equality}\') {YY_PRINT; BEGIN singlequoteattributetext; return(TOATT);}
({xmlwhitespace}+makeCopy{equality}\") {YY_PRINT; BEGIN doublequoteattributetext; return(MAKECOPYATT);}
({xmlwhitespace}+makeCopy{equality}\') {YY_PRINT; BEGIN singlequoteattributetext; return(MAKECOPYATT);}

{xmlwhitespace}*\<osol{xmlwhitespace}*\> {return(OSOLSTARTEMPTY);}
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
{xmlwhitespace}*\<solverToInvoke {YY_PRINT; return(SOLVERTOINVOKESTART);}
{xmlwhitespace}*\<\/solverToInvoke{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(SOLVERTOINVOKEEND);}
{xmlwhitespace}*\<license {YY_PRINT; return(LICENSESTART);}
{xmlwhitespace}*\<\/license{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(LICENSEEND);}
{xmlwhitespace}*\<userName {YY_PRINT; return(USERNAMESTART);}
{xmlwhitespace}*\<\/userName{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(USERNAMEEND);}
{xmlwhitespace}*\<password {YY_PRINT; return(PASSWORDSTART);}
{xmlwhitespace}*\<\/password{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(PASSWORDEND);}
{xmlwhitespace}*\<contact {YY_PRINT; return(CONTACTSTART);}
{xmlwhitespace}*\<\/contact{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(CONTACTEND);}

{xmlwhitespace}*\<otherOptions {YY_PRINT; return(OTHEROPTIONSSTART);}
{xmlwhitespace}*\<\/otherOptions{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(OTHEROPTIONSEND);}
{xmlwhitespace}*\<other {YY_PRINT; return(OTHERSTART);}
{xmlwhitespace}*\<\/other{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(OTHEREND);}

{xmlwhitespace}*\<minDiskSpace {YY_PRINT; return(MINDISKSPACESTART);}
{xmlwhitespace}*\<\/minDiskSpace{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(MINDISKSPACEEND);}
{xmlwhitespace}*\<minMemorySize {YY_PRINT; return(MINMEMORYSTART);}
{xmlwhitespace}*\<\/minMemorySize{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(MINMEMORYEND);}
{xmlwhitespace}*\<minCPUSpeed {YY_PRINT; return(MINCPUSPEEDSTART);}
{xmlwhitespace}*\<\/minCPUSpeed{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(MINCPUSPEEDEND);}
{xmlwhitespace}*\<minCPUNumber {YY_PRINT; return(MINCPUNUMBERSTART);}
{xmlwhitespace}*\<\/minCPUNumber{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(MINCPUNUMBEREND);}
{xmlwhitespace}*\<base64BinaryData {YY_PRINT; return(BASE64START);}
{xmlwhitespace}*\<\/base64BinaryData{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(BASE64END);}
{xmlwhitespace}*\<el {YY_PRINT;  return(ELSTART);}
{xmlwhitespace}*\<\/el{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT;  return(ELEND);}

{xmlwhitespace}*\<type {YY_PRINT; return(SERVICETYPESTART);}
{xmlwhitespace}*\<\/type{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(SERVICETYPEEND);}

{xmlwhitespace}*\<maxTime {YY_PRINT; return(MAXTIMESTART);}
{xmlwhitespace}*\<\/maxTime{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(MAXTIMEEND);}
{xmlwhitespace}*\<requestedStartTime {YY_PRINT; return(REQUESTEDSTARTTIMESTART);}
{xmlwhitespace}*\<\/requestedStartTime{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(REQUESTEDSTARTTIMEEND);}
{xmlwhitespace}*\<dependencies {YY_PRINT; return(DEPENDENCIESSTART);}
{xmlwhitespace}*\<\/dependencies{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(DEPENDENCIESEND);}
{xmlwhitespace}*\<requiredDirectories {YY_PRINT; return(REQUIREDDIRECTORIESSTART);}
{xmlwhitespace}*\<\/requiredDirectories{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(REQUIREDDIRECTORIESEND);}
{xmlwhitespace}*\<path {YY_PRINT; return(PATHSTART);}
{xmlwhitespace}*\<\/path{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(PATHEND);}
{xmlwhitespace}*\<requiredFiles {YY_PRINT; return(REQUIREDFILESSTART);}
{xmlwhitespace}*\<\/requiredFiles{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(REQUIREDFILESEND);}
{xmlwhitespace}*\<directoriesToMake {YY_PRINT; return(DIRECTORIESTOMAKESTART);}
{xmlwhitespace}*\<\/directoriesToMake{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(DIRECTORIESTOMAKEEND);}
{xmlwhitespace}*\<filesToMake {YY_PRINT; return(FILESTOMAKESTART);}
{xmlwhitespace}*\<\/filesToMake{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(FILESTOMAKEEND);}
{xmlwhitespace}*\<inputDirectoriesToMove {YY_PRINT; return(INPUTDIRECTORIESTOMOVESTART);}
{xmlwhitespace}*\<\/inputDirectoriesToMove{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(INPUTDIRECTORIESTOMOVEEND);}
{xmlwhitespace}*\<inputFilesToMove {YY_PRINT; return(INPUTFILESTOMOVESTART);}
{xmlwhitespace}*\<\/inputFilesToMove{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(INPUTFILESTOMOVEEND);}
{xmlwhitespace}*\<pathPair {YY_PRINT; return(PATHPAIRSTART);}
{xmlwhitespace}*\<\/pathPair{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(PATHPAIREND);}
{xmlwhitespace}*\<outputDirectoriesToMove {YY_PRINT; return(OUTPUTDIRECTORIESTOMOVESTART);}
{xmlwhitespace}*\<\/outputDirectoriesToMove{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(OUTPUTDIRECTORIESTOMOVEEND);}
{xmlwhitespace}*\<outputFilesToMove {YY_PRINT; return(OUTPUTFILESTOMOVESTART);}
{xmlwhitespace}*\<\/outputFilesToMove{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(OUTPUTFILESTOMOVEEND);}
{xmlwhitespace}*\<directoriesToDelete {YY_PRINT; return(DIRECTORIESTODELETESTART);}
{xmlwhitespace}*\<\/directoriesToDelete{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(DIRECTORIESTODELETEEND);}
{xmlwhitespace}*\<filesToDelete {YY_PRINT; return(FILESTODELETESTART);}
{xmlwhitespace}*\<\/filesToDelete{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(FILESTODELETEEND);}
{xmlwhitespace}*\<processesToKill {YY_PRINT; return(PROCESSESTOKILLSTART);}
{xmlwhitespace}*\<\/processesToKill{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(PROCESSESTOKILLEND);}
{xmlwhitespace}*\<process {YY_PRINT; return(PROCESSSTART);}
{xmlwhitespace}*\<\/process{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(PROCESSEND);}


{xmlwhitespace}*\<variables {YY_PRINT; return(VARIABLESSTART);}
{xmlwhitespace}*\<\/variables{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(VARIABLESEND);}
{xmlwhitespace}*\<initialVariableValues {YY_PRINT; return(INITIALVARIABLEVALUESSTART);}
{xmlwhitespace}*\<\/initialVariableValues{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(INITIALVARIABLEVALUESEND);}
{xmlwhitespace}*\<initialVariableValuesString {YY_PRINT; return(INITIALVARIABLEVALUESSTRINGSTART);}
{xmlwhitespace}*\<\/initialVariableValuesString{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(INITIALVARIABLEVALUESSTRINGEND);}
{xmlwhitespace}*\<initialBasisStatus {YY_PRINT; return(INITIALBASISSTATUSSTART);}
{xmlwhitespace}*\<\/initialBasisStatus{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(INITIALBASISSTATUSEND);}
{xmlwhitespace}*\<basic {YY_PRINT; return(BASICSTART);}
{xmlwhitespace}*\<\/basic{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(BASICEND);}
{xmlwhitespace}*\<atLower {YY_PRINT; return(ATLOWERSTART);}
{xmlwhitespace}*\<\/atLower{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(ATLOWEREND);}
{xmlwhitespace}*\<atUpper {YY_PRINT; return(ATUPPERSTART);}
{xmlwhitespace}*\<\/atUpper{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(ATUPPEREND);}
{xmlwhitespace}*\<atEquality {YY_PRINT; return(ATEQUALITYSTART);}
{xmlwhitespace}*\<\/atEquality{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(ATEQUALITYEND);}
{xmlwhitespace}*\<isFree {YY_PRINT; return(ISFREESTART);}
{xmlwhitespace}*\<\/isFree{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(ISFREEEND);}
{xmlwhitespace}*\<superbasic {YY_PRINT; return(SUPERBASICSTART);}
{xmlwhitespace}*\<\/superbasic{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(SUPERBASICEND);}
{xmlwhitespace}*\<unknown {YY_PRINT; return(UNKNOWNSTART);}
{xmlwhitespace}*\<\/unknown{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(UNKNOWNEND);}
{xmlwhitespace}*\<integerVariableBranchingWeights {YY_PRINT; return(INTEGERVARIABLEBRANCHINGWEIGHTSSTART);}
{xmlwhitespace}*\<\/integerVariableBranchingWeights{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(INTEGERVARIABLEBRANCHINGWEIGHTSEND);}
{xmlwhitespace}*\<sosVariableBranchingWeights {YY_PRINT; return(SOSVARIABLEBRANCHINGWEIGHTSSTART);}
{xmlwhitespace}*\<\/sosVariableBranchingWeights{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(SOSVARIABLEBRANCHINGWEIGHTSEND);}
{xmlwhitespace}*\<sos {YY_PRINT; return(SOSSTART);}
{xmlwhitespace}*\<\/sos{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(SOSEND);}
{xmlwhitespace}*\<var {YY_PRINT; return(VARSTART);}
{xmlwhitespace}*\<\/var{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(VAREND);}
{xmlwhitespace}*\<objectives {YY_PRINT; return(OBJECTIVESSTART);}
{xmlwhitespace}*\<\/objectives{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(OBJECTIVESEND);}
{xmlwhitespace}*\<initialObjectiveValues {YY_PRINT; return(INITIALOBJECTIVEVALUESSTART);}
{xmlwhitespace}*\<\/initialObjectiveValues{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(INITIALOBJECTIVEVALUESEND);}
{xmlwhitespace}*\<obj {YY_PRINT; return(OBJSTART);}
{xmlwhitespace}*\<\/obj{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(OBJEND);}
{xmlwhitespace}*\<initialObjectiveBounds {YY_PRINT; return(INITIALOBJECTIVEBOUNDSSTART);}
{xmlwhitespace}*\<\/initialObjectiveBounds{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(INITIALOBJECTIVEBOUNDSEND);}
{xmlwhitespace}*\<constraints {YY_PRINT; return(CONSTRAINTSSTART);}
{xmlwhitespace}*\<\/constraints{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(CONSTRAINTSEND);}
{xmlwhitespace}*\<initialConstraintValues {YY_PRINT; return(INITIALCONSTRAINTVALUESSTART);}
{xmlwhitespace}*\<\/initialConstraintValues{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(INITIALCONSTRAINTVALUESEND);}
{xmlwhitespace}*\<con {YY_PRINT; return(CONSTART);}
{xmlwhitespace}*\<\/con{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(CONEND);}
{xmlwhitespace}*\<initialDualValues {YY_PRINT; return(INITIALDUALVALUESSTART);}
{xmlwhitespace}*\<\/initialDualValues{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(INITIALDUALVALUESEND);}
{xmlwhitespace}*\<solverOptions {YY_PRINT; return(SOLVEROPTIONSSTART);}
{xmlwhitespace}*\<\/solverOptions{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(SOLVEROPTIONSEND);}
{xmlwhitespace}*\<solverOption {YY_PRINT; return(SOLVEROPTIONSTART);}
{xmlwhitespace}*\<\/solverOption{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(SOLVEROPTIONEND);}
{xmlwhitespace}*\<enumeration {YY_PRINT;  return(ENUMERATIONSTART);}
{xmlwhitespace}*\<\/enumeration{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT;  return(ENUMERATIONEND);}


 /* include file OSParseosgl.l.patterns --- patterns for OSgL schema elements */

 /* The <item> element and the children of the file header are treated specially because they may legitimately contain special characters */

{xmlwhitespace}*\<item{xmlwhitespace}*\>{xmlwhitespace}*\<\/item{xmlwhitespace}*\>{xmlwhitespace}* {  YY_PRINT;  return(ITEMEMPTY);}
{xmlwhitespace}*\<item{xmlwhitespace}*\>{xmlwhitespace}* { YY_PRINT; BEGIN itemtext; return(ITEMSTART);}
{xmlwhitespace}*\<\/item{xmlwhitespace}*>{xmlwhitespace}* { YY_PRINT; return(ITEMEND);}
{xmlwhitespace}*\<item{xmlwhitespace}*\/>{xmlwhitespace}* { YY_PRINT; return(ITEMSTARTANDEND);}

{xmlwhitespace}*\<optionHeader {YY_PRINT; return(HEADERSTART);}
{xmlwhitespace}*\<\/optionHeader{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(HEADEREND);}

{xmlwhitespace}*\<name{xmlwhitespace}*\>{xmlwhitespace}*\<\/name{xmlwhitespace}*\>{xmlwhitespace}* {  YY_PRINT;  return(FILENAMEEMPTY);}
{xmlwhitespace}*\<name{xmlwhitespace}*\>{xmlwhitespace}* { YY_PRINT; BEGIN itemtext; return(FILENAMESTART);}
{xmlwhitespace}*\<\/name{xmlwhitespace}*>{xmlwhitespace}* { YY_PRINT; return(FILENAMEEND);}
{xmlwhitespace}*\<name{xmlwhitespace}*\/>{xmlwhitespace}* { YY_PRINT; return(FILENAMESTARTANDEND);}

{xmlwhitespace}*\<source{xmlwhitespace}*\>{xmlwhitespace}*\<\/source{xmlwhitespace}*\>{xmlwhitespace}* {  YY_PRINT;  return(FILESOURCEEMPTY);}
{xmlwhitespace}*\<source{xmlwhitespace}*\>{xmlwhitespace}* { YY_PRINT; BEGIN itemtext; return(FILESOURCESTART);}
{xmlwhitespace}*\<\/source{xmlwhitespace}*>{xmlwhitespace}* { YY_PRINT; return(FILESOURCEEND);}
{xmlwhitespace}*\<source{xmlwhitespace}*\/>{xmlwhitespace}* { YY_PRINT; return(FILESOURCESTARTANDEND);}

{xmlwhitespace}*\<description{xmlwhitespace}*\>{xmlwhitespace}*\<\/description{xmlwhitespace}*\>{xmlwhitespace}* {  YY_PRINT;  return(FILEDESCRIPTIONEMPTY);}
{xmlwhitespace}*\<description{xmlwhitespace}*\>{xmlwhitespace}* { YY_PRINT; BEGIN itemtext; return(FILEDESCRIPTIONSTART);}
{xmlwhitespace}*\<\/description{xmlwhitespace}*>{xmlwhitespace}* { YY_PRINT; return(FILEDESCRIPTIONEND);}
{xmlwhitespace}*\<description{xmlwhitespace}*\/>{xmlwhitespace}* { YY_PRINT; return(FILEDESCRIPTIONSTARTANDEND);}

{xmlwhitespace}*\<fileCreator{xmlwhitespace}*\>{xmlwhitespace}*\<\/fileCreator{xmlwhitespace}*\>{xmlwhitespace}* {  YY_PRINT;  return(FILECREATOREMPTY);}
{xmlwhitespace}*\<fileCreator{xmlwhitespace}*\>{xmlwhitespace}* { YY_PRINT; BEGIN itemtext; return(FILECREATORSTART);}
{xmlwhitespace}*\<\/fileCreator{xmlwhitespace}*>{xmlwhitespace}* { YY_PRINT; return(FILECREATOREND);}
{xmlwhitespace}*\<fileCreator{xmlwhitespace}*\/>{xmlwhitespace}* { YY_PRINT; return(FILECREATORSTARTANDEND);}

{xmlwhitespace}*\<licence{xmlwhitespace}*\>{xmlwhitespace}*\<\/licence{xmlwhitespace}*\>{xmlwhitespace}* {  YY_PRINT;  return(FILELICENCEEMPTY);}
{xmlwhitespace}*\<licence{xmlwhitespace}*\>{xmlwhitespace}* { YY_PRINT; BEGIN itemtext; return(FILELICENCESTART);}
{xmlwhitespace}*\<\/licence{xmlwhitespace}*>{xmlwhitespace}* { YY_PRINT; return(FILELICENCEEND);}
{xmlwhitespace}*\<licence{xmlwhitespace}*\/>{xmlwhitespace}* { YY_PRINT; return(FILELICENCESTARTANDEND);}


({xmlwhitespace}+baseMatrixIdx{equality}) {YY_PRINT; return(BASEMATRIXIDXATT);}
({xmlwhitespace}+targetMatrixFirstRow{equality}) {YY_PRINT; return(TARGETMATRIXFIRSTROWATT);}
({xmlwhitespace}+targetMatrixFirstCol{equality}) {YY_PRINT; return(TARGETMATRIXFIRSTCOLATT);}
({xmlwhitespace}+baseMatrixStartRow{equality}) {YY_PRINT; return(BASEMATRIXSTARTROWATT);}
({xmlwhitespace}+baseMatrixStartCol{equality}) {YY_PRINT; return(BASEMATRIXSTARTCOLATT);}
({xmlwhitespace}+baseMatrixEndRow{equality}) {YY_PRINT; return(BASEMATRIXENDROWATT);}
({xmlwhitespace}+baseMatrixEndCol{equality}) {YY_PRINT; return(BASEMATRIXENDCOLATT);}
({xmlwhitespace}+scalarMultiplier{equality}) {YY_PRINT; return(SCALARMULTIPLIERATT);}
({xmlwhitespace}+baseMatrixIdx{equality}) {YY_PRINT; return(BLOCKROWIDXATT);}
({xmlwhitespace}+baseMatrixIdx{equality}) {YY_PRINT; return(BLOCKCOLIDXATT);}
({xmlwhitespace}+numberOfVarIdx{equality}) {YY_PRINT; return(NUMBEROFVARIDXATT);}
({xmlwhitespace}+constant{equality}) {YY_PRINT; return(CONSTANTATT);}

 /* attributes returning strings (that are potentially empty)*/

({xmlwhitespace}+excludeElementIfSet{equality}\"\") {YY_PRINT; return(EMPTYEXCLUDEATT);}
({xmlwhitespace}+excludeElementIfSet{equality}\'\') {YY_PRINT; return(EMPTYEXCLUDEATT);}
({xmlwhitespace}+excludeElementIfSet{equality}\") {YY_PRINT; BEGIN doublequoteattributetext; return(EXCLUDEATT);}
({xmlwhitespace}+excludeElementIfSet{equality}\') {YY_PRINT; BEGIN singlequoteattributetext; return(EXCLUDEATT);}

 /* tokens for the <matrix> element */

{xmlwhitespace}*\<matrix {YY_PRINT;  return(MATRIXSTART);}
{xmlwhitespace}*\<\/matrix{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT;  return(MATRIXEND);}
{xmlwhitespace}*\<baseMatrix {YY_PRINT;  return(BASEMATRIXSTART);}
{xmlwhitespace}*\<\/baseMatrix{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT;  return(BASEMATRIXEND);}
{xmlwhitespace}*\<blocks {YY_PRINT;  return(BLOCKSSTART);}
{xmlwhitespace}*\<\/blocks{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT;  return(BLOCKSEND);}
{xmlwhitespace}*\<block {YY_PRINT;  return(BLOCKSTART);}
{xmlwhitespace}*\<\/block{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT;  return(BLOCKEND);}
{xmlwhitespace}*\<elements {YY_PRINT;  return(ELEMENTSSTART);}
{xmlwhitespace}*\<\/elements{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT;  return(ELEMENTSEND);}
{xmlwhitespace}*\<constantElements {YY_PRINT;  return(CONSTANTELEMENTSSTART);}
{xmlwhitespace}*\<\/constantElements{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT;  return(CONSTANTELEMENTSEND);}
{xmlwhitespace}*\<varReferenceElements {YY_PRINT;  return(VARREFERENCEELEMENTSSTART);}
{xmlwhitespace}*\<\/varReferenceElements{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT;  return(VARREFERENCEELEMENTSEND);}
{xmlwhitespace}*\<varReferenceElements {YY_PRINT;  return(OBJREFERENCEELEMENTSSTART);}
{xmlwhitespace}*\<\/varReferenceElements{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT;  return(OBJREFERENCEELEMENTSEND);}
{xmlwhitespace}*\<varReferenceElements {YY_PRINT;  return(CONREFERENCEELEMENTSSTART);}
{xmlwhitespace}*\<\/varReferenceElements{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT;  return(CONREFERENCEELEMENTSEND);}
{xmlwhitespace}*\<linearElements {YY_PRINT;  return(LINEARELEMENTSSTART);}
{xmlwhitespace}*\<\/linearElements{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT;  return(LINEARELEMENTSEND);}
{xmlwhitespace}*\<generalElements {YY_PRINT;  return(GENERALELEMENTSSTART);}
{xmlwhitespace}*\<\/generalElements{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT;  return(GENERALELEMENTSEND);}
{xmlwhitespace}*\<generalElements {YY_PRINT;  return(PATTERNELEMENTSSTART);}
{xmlwhitespace}*\<\/generalElements{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT;  return(PATTERNELEMENTSEND);}
{xmlwhitespace}*\<start {YY_PRINT;  return(STARTVECTORSTART);}
{xmlwhitespace}*\<\/start{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT;  return(STARTVECTOREND);}
{xmlwhitespace}*\<nonzeros {YY_PRINT;  return(NONZEROSSTART);}
{xmlwhitespace}*\<\/nonzeros{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT;  return(NONZEROSEND);}
{xmlwhitespace}*\<indexes {YY_PRINT;  return(INDEXESSTART);}
{xmlwhitespace}*\<\/indexes{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT;  return(INDEXESEND);}
{xmlwhitespace}*\<nonzeros {YY_PRINT;  return(VALUESSTART);}
{xmlwhitespace}*\<\/nonzeros{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT;  return(VALUESEND);}
{xmlwhitespace}*\<colOffsets {YY_PRINT;  return(COLOFFSETSSTART);}
{xmlwhitespace}*\<\/colOffsets{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT;  return(COLOFFSETSEND);}
{xmlwhitespace}*\<rowOffsets {YY_PRINT;  return(ROWOFFSETSSTART);}
{xmlwhitespace}*\<\/rowOffsets{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT;  return(ROWOFFSETSEND);}
{xmlwhitespace}*\<varIdx {YY_PRINT;  return(VARIDXSTART);}
{xmlwhitespace}*\<\/varIDX{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT;  return(VARIDXEND);}
{xmlwhitespace}*\<transformation {YY_PRINT;  return(TRANSFORMATIONSTART);}
{xmlwhitespace}*\<\/transformation{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT;  return(INDEXESEND);}

 /* include file OSParseosnl.l.patterns --- patterns for OSnL schema elements */

 /* patterns for <nonlinearExpressions> */

({xmlwhitespace}+numberOfNonlinearExpressions{equality}) {YY_PRINT; return(NUMBEROFNONLINEAREXPRESSIONS);}

({xmlwhitespace}+coef{equality}) {YY_PRINT;   return(COEFATT);}

{xmlwhitespace}*\<nonlinearExpressions {YY_PRINT;  return(NONLINEAREXPRESSIONSSTART);}
{xmlwhitespace}*\<\/nonlinearExpressions{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(NONLINEAREXPRESSIONSEND);}
{xmlwhitespace}*\<nl {YY_PRINT; return(NLSTART);}
{xmlwhitespace}*\<\/nl{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(NLEND);}
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
{xmlwhitespace}*\<squareRoot{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(SQRTSTART);}
{xmlwhitespace}*\<\/squareRoot{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(SQRTEND);}
{xmlwhitespace}*\<square{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(SQUARESTART);}
{xmlwhitespace}*\<\/square{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(SQUAREEND);}
{xmlwhitespace}*\<sin{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(SINSTART);}
{xmlwhitespace}*\<\/sin{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(SINEND);}
{xmlwhitespace}*\<cos{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(COSSTART);}
{xmlwhitespace}*\<\/cos{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(COSEND);}
{xmlwhitespace}*\<exp{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(EXPSTART);}
{xmlwhitespace}*\<\/exp{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(EXPEND);}
{xmlwhitespace}*\<abs{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(ABSSTART);}
{xmlwhitespace}*\<\/abs{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(ABSEND);}
{xmlwhitespace}*\<erf{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(ERFSTART);}
{xmlwhitespace}*\<\/erf{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(ERFEND);}
{xmlwhitespace}*\<if{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(IFSTART);}
{xmlwhitespace}*\<\/if{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(IFEND);}
{xmlwhitespace}*\<max{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(MAXSTART);}
{xmlwhitespace}*\<\/max{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(MAXEND);}
{xmlwhitespace}*\<min{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(MINSTART);}
{xmlwhitespace}*\<\/min{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(MINEND);}
{xmlwhitespace}*\<sum{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(SUMSTART);}
{xmlwhitespace}*\<\/sum{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(SUMEND);}
{xmlwhitespace}*\<allDiff{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(ALLDIFFSTART);}
{xmlwhitespace}*\<\/allDiff{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(ALLDIFFEND);}
{xmlwhitespace}*\<product{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(PRODUCTSTART);}
{xmlwhitespace}*\<\/product{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(PRODUCTEND);}
{xmlwhitespace}*\<number {YY_PRINT; return(NUMBERSTART);}
{xmlwhitespace}*\<\/number{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(NUMBEREND);}
{xmlwhitespace}*\<E {YY_PRINT; return(ESTART);}
{xmlwhitespace}*\<\/E{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(EEND);}
{xmlwhitespace}*\<PI {YY_PRINT; return(PISTART);}
{xmlwhitespace}*\<\/PI{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(PIEND);}
{xmlwhitespace}*\<variable {YY_PRINT;  return(VARIABLESTART);}
{xmlwhitespace}*\<\/variable{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(VARIABLEEND);}

{xmlwhitespace}*\<matrixTrace {YY_PRINT; return(MATRIXTRACESTART);}
{xmlwhitespace}*\<\/matrixTrace{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(MATRIXTRACEEND);}
{xmlwhitespace}*\<matrixToScalar {YY_PRINT; return(MATRIXTOSCALARSTART);}
{xmlwhitespace}*\<\/matrixToScalar{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(MATRIXTOSCALAREND);}

{xmlwhitespace}*\<matrixDiagonal {YY_PRINT; return(MATRIXDIAGONALSTART);}
{xmlwhitespace}*\<\/matrixDiagonal{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(MATRIXDIAGONALEND);}
{xmlwhitespace}*\<matrixDotTimes {YY_PRINT; return(MATRIXDOTTIMESSTART);}
{xmlwhitespace}*\<\/matrixDotTimes{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(MATRIXDOTTIMESEND);}
{xmlwhitespace}*\<matrixIdentity {YY_PRINT; return(MATRIXIDENTITYSTART);}
{xmlwhitespace}*\<\/matrixIdentity{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(MATRIXIDENTITYEND);}
{xmlwhitespace}*\<matrixInverse {YY_PRINT; return(MATRIXINVERSESTART);}
{xmlwhitespace}*\<\/matrixInverse{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(MATRIXINVERSEEND);}
{xmlwhitespace}*\<matrixLowerTriangle {YY_PRINT; return(MATRIXLOWERTRIANGLESTART);}
{xmlwhitespace}*\<\/matrixLowerTriangle{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(MATRIXLOWERTRIANGLEEND);}
{xmlwhitespace}*\<matrixUpperTriangle {YY_PRINT; return(MATRIXUPPERTRIANGLESTART);}
{xmlwhitespace}*\<\/matrixUpperTriangle{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(MATRIXUPPERTRIANGLEEND);}
{xmlwhitespace}*\<matrixMerge {YY_PRINT; return(MATRIXMERGESTART);}
{xmlwhitespace}*\<\/matrixMerge{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(MATRIXMERGEEND);}
{xmlwhitespace}*\<matrixMinus {YY_PRINT; return(MATRIXMINUSSTART);}
{xmlwhitespace}*\<\/matrixMinus{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(MATRIXMINUSEND);}
{xmlwhitespace}*\<matrixPlus {YY_PRINT; return(MATRIXPLUSSTART);}
{xmlwhitespace}*\<\/matrixPlus{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(MATRIXPLUSEND);}
{xmlwhitespace}*\<matrixTimes {YY_PRINT; return(MATRIXTIMESSTART);}
{xmlwhitespace}*\<\/matrixTimes{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(MATRIXTIMESEND);}
{xmlwhitespace}*\<matrixScalarTimes {YY_PRINT; return(MATRIXSCALARTIMESSTART);}
{xmlwhitespace}*\<\/matrixScalarTimes{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(MATRIXSCALARTIMESEND);}
{xmlwhitespace}*\<matrixSubMatrixAt {YY_PRINT; return(MATRIXSUBMATRIXATSTART);}
{xmlwhitespace}*\<\/matrixSubMatrixAt{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(MATRIXSUBMATRIXATEND);}
{xmlwhitespace}*\<matrixTranspose {YY_PRINT; return(MATRIXTRANSPOSESTART);}
{xmlwhitespace}*\<\/matrixTranspose{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(MATRIXTRANSPOSEEND);}

 /* attributes returning strings (that are potentially empty)*/

({xmlwhitespace}+includeDiagonal{equality}\"\") {YY_PRINT; return(EMPTYINCLUDEDIAGONALATT);}
({xmlwhitespace}+includeDiagonal{equality}\'\') {YY_PRINT; return(EMPTYINCLUDEDIAGONALATT);}
({xmlwhitespace}+includeDiagonal{equality}\") {YY_PRINT; BEGIN doublequoteattributetext; return(INCLUDEDIAGONALATT);}
({xmlwhitespace}+includeDiagonal{equality}\') {YY_PRINT; BEGIN singlequoteattributetext; return(INCLUDEDIAGONALATT);}

 /* last section of OSParseosol.l */

 /* environments and comments */
[a-zA-Z0-9.:_*#$@(), \n\t\r\/\\\-\+\=\&\%]+ { YY_PRINT; yylval->sval = strdup( yytext);  yyextra->errorText = yylval->sval;  /*  yylval->sval = yytext;*/  return (ELEMENTTEXT); }
<itemtext>[^\<]+ { YY_PRINT;  yylval->sval = strdup( yytext); BEGIN 0;  yyextra->errorText = yylval->sval;    /*yylval->sval = yytext;*/  return (ITEMTEXT); }

 "<!--" BEGIN comment;
 <comment>. |
 <comment>\n ;
 <comment>"-->" BEGIN 0;
 
 "<?" BEGIN xmldeclaration;
 <xmldeclaration>. |
 <xmldeclaration>\n ;
 <xmldeclaration>"?>" BEGIN 0;
 

<doublequoteattributetext>[^\"]* {YY_PRINT;  BEGIN 0; yylval->sval = strdup(yytext);  /*yylval->sval = yytext;*/ return(ATTRIBUTETEXT);}
<singlequoteattributetext>[^\']* {YY_PRINT;  BEGIN 0; yylval->sval = strdup(yytext);  /*yylval->sval = yytext;*/ return(ATTRIBUTETEXT);}
<osolattributetext>([^>])* {YY_PRINT;  BEGIN 0;  /*yylval->sval = strdup(yytext);*/   yylval->sval = yytext;   return(OSOLATTRIBUTETEXT);}

 /* error trap */

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


