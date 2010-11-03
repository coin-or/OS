/* $Id$ */
/** @file parseosrl.l
 * 
 * @author  Horand Gassmann, Jun Ma, Kipp Martin, 
 * @version 2.0, 19/07/2009
 * @since   OS1.0
 *
 * \remarks
 * Copyright (C) 2005-2009, Horand Gassmann, Jun Ma, Kipp Martin,
 * Northwestern University, Dalhousie University and the University of Chicago.
 * All Rights Reserved.
 * This software is licensed under the Common Public License. 
 * Please see the accompanying LICENSE file in root directory for terms.
 * 
 */
%{

#include <iostream>
#include "OSGeneral.h"
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


//#define PARSERDEBUG

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
%option nounput
%x osrlattributetext
%x doublequoteattributetext
%x singlequoteattributetext
%x startelement
%x elementtext
%x itemtext
%x comment
%x xmldeclaration


   
%{
#define YY_EXTRA_TYPE OSrLParserData*
%}  

xmlwhitespace ([ \t\n\r])
equality ([ \t\n\r])*=([ \t\n\r])*
quote (\"|\') 
twoquotes (\"\"|\'\')
greater_than (>)
aninteger (-?[0-9]+)
adouble (-?((([0-9]+)|([0-9]*\.[0-9]*))([eE][-+]?[0-9]+)?|INF))
%% 


{xmlwhitespace}* 

 /* General patterns matched in more than one element */

{quote} {YY_PRINT;  yylval->sval = yytext; return(QUOTE);}
{twoquotes} {YY_PRINT;  yylval->sval = yytext; return(TWOQUOTES);}
({xmlwhitespace}*{greater_than}{xmlwhitespace}*) { YY_PRINT;     return(GREATERTHAN);}
({xmlwhitespace}*{aninteger}{xmlwhitespace}*)  {YY_PRINT; yylval->ival = atoi(yytext); return(INTEGER);}

({xmlwhitespace}*{adouble}{xmlwhitespace}*) {YY_PRINT; 
char *yytextEnd;
yylval->dval = os_strtod_wrap( yytext, &yytextEnd);
	/*
	if( (unsigned)(yytextEnd - yytext) != strlen( yytext)){
		std::ostringstream outStr;
		outStr << "encountered a spurious character in the lexer" << endl;
		outStr << "The first character is: ";
		outStr <<  yytext;
		outStr << endl;
		outStr << "See line number: " << yylineno << endl;  
		throw ErrorClass( outStr.str());
	}
	*/
return(DOUBLE);}

({xmlwhitespace}*\/>) {YY_PRINT;  return(ENDOFELEMENT);}

 /* attributes returning numeric values*/

({xmlwhitespace}+numberOfCon{equality}) {YY_PRINT; return(NUMBEROFCONATT);}
({xmlwhitespace}+numberOfConstraints{equality}) {YY_PRINT; return(NUMBEROFCONSTRAINTSATT);}
({xmlwhitespace}+numberOfEl{equality}) {YY_PRINT;  return(NUMBEROFELATT);}
({xmlwhitespace}+numberOfEnumerations{equality}) {YY_PRINT;  return(NUMBEROFENUMERATIONSATT);}
({xmlwhitespace}+numberOfIdx{equality}) {YY_PRINT;  return(NUMBEROFIDXATT);}
({xmlwhitespace}+numberOfItems{equality}) {YY_PRINT;  return(NUMBEROFITEMSATT);}
({xmlwhitespace}+numberOfObj{equality}) {YY_PRINT; return(NUMBEROFOBJATT);}
({xmlwhitespace}+numberOfObjectives{equality}) {YY_PRINT; return(NUMBEROFOBJECTIVESATT);}
({xmlwhitespace}+numberOfOtherConstraintResults{equality}) {YY_PRINT; return(NUMBEROFOTHERCONSTRAINTRESULTSATT);}
({xmlwhitespace}+numberOfOtherObjectiveResults{equality}) {YY_PRINT; return(NUMBEROFOTHEROBJECTIVERESULTSATT);}
({xmlwhitespace}+numberOfOtherResults{equality}) {YY_PRINT; return(NUMBEROFOTHERRESULTSATT);}
({xmlwhitespace}+numberOfOtherSolutionResults{equality}) {YY_PRINT; return(NUMBEROFOTHERSOLUTIONRESULTSATT);}
({xmlwhitespace}+numberOfOtherVariableResults{equality}) {YY_PRINT; return(NUMBEROFOTHERVARIABLERESULTSATT);}
({xmlwhitespace}+numberOfSolutions{equality}) {YY_PRINT; return(NUMBEROFSOLUTIONSATT);}
({xmlwhitespace}+numberOfSolverOutputs{equality}) {YY_PRINT; return(NUMBEROFSOLVEROUTPUTSATT);}
({xmlwhitespace}+numberOfSubstatuses{equality}) {YY_PRINT; return(NUMBEROFSUBSTATUSESATT);}
({xmlwhitespace}+numberOfTimes{equality}) {YY_PRINT; return(NUMBEROFTIMESATT);}
({xmlwhitespace}+numberOfVar{equality}) {YY_PRINT; return(NUMBEROFVARATT);}
({xmlwhitespace}+numberOfVariables{equality}) {YY_PRINT; return(NUMBEROFVARIABLESATT);}
({xmlwhitespace}+numberOfVarIdx{equality}) {YY_PRINT; return(NUMBEROFVARIDXATT);}

({xmlwhitespace}+idx{equality}) {YY_PRINT; return(IDXATT);}
({xmlwhitespace}+incr{equality}) {YY_PRINT; return(INCRATT);}
({xmlwhitespace}+mult{equality}) {YY_PRINT; return(MULTATT);}
({xmlwhitespace}+sizeOf{equality}) {YY_PRINT; return(SIZEOFATT);}
({xmlwhitespace}+targetObjectiveIdx{equality}) {YY_PRINT; return(TARGETOBJECTIVEIDXATT);}

 /* attributes returning strings (that are potentially empty)*/

({xmlwhitespace}+category{equality}\"\") {YY_PRINT; return(EMPTYCATEGORYATT);}
({xmlwhitespace}+category{equality}\'\') {YY_PRINT; return(EMPTYCATEGORYATT);}
({xmlwhitespace}+category{equality}\") {YY_PRINT; BEGIN doublequoteattributetext; return(CATEGORYATT);}
({xmlwhitespace}+category{equality}\') {YY_PRINT; BEGIN singlequoteattributetext; return(CATEGORYATT);}
({xmlwhitespace}+description{equality}\"\") {YY_PRINT; return(EMPTYDESCRIPTIONATT);}
({xmlwhitespace}+description{equality}\'\') {YY_PRINT; return(EMPTYDESCRIPTIONATT);}
({xmlwhitespace}+description{equality}\") {YY_PRINT; BEGIN doublequoteattributetext; return(DESCRIPTIONATT);}
({xmlwhitespace}+description{equality}\') {YY_PRINT; BEGIN singlequoteattributetext; return(DESCRIPTIONATT);}
({xmlwhitespace}+name{equality}\"\") {YY_PRINT; return(EMPTYNAMEATT);}
({xmlwhitespace}+name{equality}\'\') {YY_PRINT; return(EMPTYNAMEATT);}
({xmlwhitespace}+name{equality}\") {YY_PRINT; BEGIN doublequoteattributetext; return(NAMEATT);}
({xmlwhitespace}+name{equality}\') {YY_PRINT; BEGIN singlequoteattributetext; return(NAMEATT);}
({xmlwhitespace}+type{equality}\"\") {YY_PRINT; return(EMPTYTYPEATT);}
({xmlwhitespace}+type{equality}\'\') {YY_PRINT; return(EMPTYTYPEATT);}
({xmlwhitespace}+type{equality}\") {YY_PRINT; BEGIN doublequoteattributetext; return(TYPEATT);}
({xmlwhitespace}+type{equality}\') {YY_PRINT; BEGIN singlequoteattributetext; return(TYPEATT);}
({xmlwhitespace}+unit{equality}\"\") {YY_PRINT; return(EMPTYUNITATT);}
({xmlwhitespace}+unit{equality}\'\') {YY_PRINT; return(EMPTYUNITATT);}
({xmlwhitespace}+unit{equality}\") {YY_PRINT; BEGIN doublequoteattributetext; return(UNITATT);}
({xmlwhitespace}+unit{equality}\') {YY_PRINT; BEGIN singlequoteattributetext; return(UNITATT);}
({xmlwhitespace}+value{equality}\"\") {YY_PRINT; return(EMPTYVALUEATT);}
({xmlwhitespace}+value{equality}\'\') {YY_PRINT; return(EMPTYVALUEATT);}
({xmlwhitespace}+value{equality}\") {YY_PRINT; BEGIN doublequoteattributetext; return(VALUEATT);}
({xmlwhitespace}+value{equality}\') {YY_PRINT; BEGIN singlequoteattributetext; return(VALUEATT);}
({xmlwhitespace}+weightedObjectives{equality}\"\") {YY_PRINT; return(EMPTYWEIGHTEDOBJECTIVESATT);}
({xmlwhitespace}+weightedObjectives{equality}\'\') {YY_PRINT; return(EMPTYWEIGHTEDOBJECTIVESATT);}
({xmlwhitespace}+weightedObjectives{equality}\") {YY_PRINT; BEGIN doublequoteattributetext; return(WEIGHTEDOBJECTIVESATT);}
({xmlwhitespace}+weightedObjectives{equality}\') {YY_PRINT; BEGIN singlequoteattributetext; return(WEIGHTEDOBJECTIVESATT);}

 /* top level elements */

{xmlwhitespace}*\<osrl{xmlwhitespace}*\> {return(OSRLSTARTEMPTY);}
{xmlwhitespace}*\<osrl{xmlwhitespace}+ {YY_PRINT; BEGIN osrlattributetext;  return(OSRLSTART);}
{xmlwhitespace}*\<\/osrl{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(OSRLEND);}

{xmlwhitespace}*\<general{xmlwhitespace}* {YY_PRINT; return(GENERALSTART);}
{xmlwhitespace}*\<\/general{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(GENERALEND);}

{xmlwhitespace}*\<system{xmlwhitespace}* {YY_PRINT; return(SYSTEMSTART);}
{xmlwhitespace}*\<\/system{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(SYSTEMEND);}

{xmlwhitespace}*\<service{xmlwhitespace}* {YY_PRINT; return(SERVICESTART);}
{xmlwhitespace}*\<\/service{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(SERVICEEND);}

{xmlwhitespace}*\<job{xmlwhitespace}* {YY_PRINT; return(JOBSTART);}
{xmlwhitespace}*\<\/job{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(JOBEND);}

{xmlwhitespace}*\<optimization {YY_PRINT; return(OPTIMIZATIONSTART);}
{xmlwhitespace}*\<\/optimization{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(OPTIMIZATIONEND);}


 /* The <item> element is treated specially because it may legitimately contain special characters */

{xmlwhitespace}*\<item{xmlwhitespace}*\>{xmlwhitespace}*\<\/item{xmlwhitespace}*\>{xmlwhitespace}* {  YY_PRINT;  return(ITEMEMPTY);}
{xmlwhitespace}*\<item{xmlwhitespace}*\>{xmlwhitespace}* { YY_PRINT; BEGIN itemtext; return(ITEMSTART);}
{xmlwhitespace}*\<\/item{xmlwhitespace}*>{xmlwhitespace}* { YY_PRINT; return(ITEMEND);}
{xmlwhitespace}*\<item{xmlwhitespace}*\/>{xmlwhitespace}* { YY_PRINT; return(ITEMSTARTANDEND);}

 /* Remaining elements, sorted alpabetically. */
 
{xmlwhitespace}*\<actualStartTime {YY_PRINT;  return(ACTUALSTARTTIMESTART);}
{xmlwhitespace}*\<\/actualStartTime{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT;  return(ACTUALSTARTTIMEEND);}
{xmlwhitespace}*\<atLower {YY_PRINT; return(ATLOWERSTART);}
{xmlwhitespace}*\<\/atLower{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(ATLOWEREND);}
{xmlwhitespace}*\<atUpper {YY_PRINT; return(ATUPPERSTART);}
{xmlwhitespace}*\<\/atUpper{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(ATUPPEREND);}
{xmlwhitespace}*\<availableCPUNumber {YY_PRINT;  return(AVAILABLECPUNUMBERSTART);}
{xmlwhitespace}*\<\/availableCPUNumber{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(AVAILABLECPUNUMBEREND);}
{xmlwhitespace}*\<availableCPUSpeed {YY_PRINT;  return(AVAILABLECPUSPEEDSTART);}
{xmlwhitespace}*\<\/availableCPUSpeed{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(AVAILABLECPUSPEEDEND);}
{xmlwhitespace}*\<availableDiskSpace {YY_PRINT;  return(AVAILABLEDISKSPACESTART);}
{xmlwhitespace}*\<\/availableDiskSpace{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(AVAILABLEDISKSPACEEND);}
{xmlwhitespace}*\<availableMemory {YY_PRINT;  return(AVAILABLEMEMORYSTART);}
{xmlwhitespace}*\<\/availableMemory{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(AVAILABLEMEMORYEND);}
{xmlwhitespace}*\<base64BinaryData {YY_PRINT; return(BASE64START);}
{xmlwhitespace}*\<\/base64BinaryData{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(BASE64END);}
{xmlwhitespace}*\<basic {YY_PRINT; return(BASICSTART);}
{xmlwhitespace}*\<\/basic{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(BASICEND);}
{xmlwhitespace}*\<basisStatus {YY_PRINT;  return(BASISSTATUSSTART);}
{xmlwhitespace}*\<\/basisStatus{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(BASISSTATUSEND);}
{xmlwhitespace}*\<basStatus {YY_PRINT;  return(BASSTATUSSTART);}
{xmlwhitespace}*\<\/basStatus{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(BASSTATUSEND);}
{xmlwhitespace}*\<con {YY_PRINT; return(CONSTART);}
{xmlwhitespace}*\<\/con{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(CONEND);}
{xmlwhitespace}*\<constraints {YY_PRINT; return(CONSTRAINTSSTART);}
{xmlwhitespace}*\<\/constraints{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(CONSTRAINTSEND);}
{xmlwhitespace}*\<currentJobCount {YY_PRINT;  return(CURRENTJOBCOUNTSTART);}
{xmlwhitespace}*\<\/currentJobCount{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT;  return(CURRENTJOBCOUNTEND);}
{xmlwhitespace}*\<currentState {YY_PRINT;  return(CURRENTSTATESTART);}
{xmlwhitespace}*\<\/currentState{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT;  return(CURRENTSTATEEND);}
{xmlwhitespace}*\<dualValues {YY_PRINT; return(DUALVALUESSTART);}
{xmlwhitespace}*\<\/dualValues{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(DUALVALUESEND);}
{xmlwhitespace}*\<el {YY_PRINT;  return(ELSTART);}
{xmlwhitespace}*\<\/el{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT;  return(ELEND);}
{xmlwhitespace}*\<endTime {YY_PRINT;  return(ENDTIMESTART);}
{xmlwhitespace}*\<\/endTime{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT;  return(ENDTIMEEND);}
{xmlwhitespace}*\<enumeration {YY_PRINT;  return(ENUMERATIONSTART);}
{xmlwhitespace}*\<\/enumeration{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT;  return(ENUMERATIONEND);}
{xmlwhitespace}*\<generalStatus {YY_PRINT; return(GENERALSTATUSSTART);}
{xmlwhitespace}*\<\/generalStatus{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(GENERALSTATUSEND);}
{xmlwhitespace}*\<instanceName {YY_PRINT;  return(INSTANCENAMESTART);}
{xmlwhitespace}*\<\/instanceName{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT;  return(INSTANCENAMEEND);}
{xmlwhitespace}*\<idx {YY_PRINT; return(IDXSTART);}
{xmlwhitespace}*\<\/idx{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(IDXEND);}
{xmlwhitespace}*\<isFree {YY_PRINT; return(ISFREESTART);}
{xmlwhitespace}*\<\/isFree{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(ISFREEEND);}
{xmlwhitespace}*\<jobID {YY_PRINT;  return(JOBIDSTART);}
{xmlwhitespace}*\<\/jobID{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT;  return(JOBIDEND);}
{xmlwhitespace}*\<message {YY_PRINT;  return(MESSAGESTART);}
{xmlwhitespace}*\<\/message{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT;  return(MESSAGEEND);}
{xmlwhitespace}*\<obj {YY_PRINT; return(OBJSTART);}
{xmlwhitespace}*\<\/obj{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(OBJEND);}
{xmlwhitespace}*\<objectives {YY_PRINT; return(OBJECTIVESSTART);}
{xmlwhitespace}*\<\/objectives{xmlwhitespace}*\>{xmlwhitespace}*  {YY_PRINT; return(OBJECTIVESEND);}
{xmlwhitespace}*\<optimizationSolutionStatus {YY_PRINT;  return(OPTIMIZATIONSOLUTIONSTATUSSTART);}
{xmlwhitespace}*\<\/optimizationSolutionStatus{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(OPTIMIZATIONSOLUTIONSTATUSEND);}
{xmlwhitespace}*\<other {YY_PRINT; return(OTHERSTART);}
{xmlwhitespace}*\<\/other{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(OTHEREND);}
{xmlwhitespace}*\<otherResults {YY_PRINT;  return(OTHERRESULTSSTART);}
{xmlwhitespace}*\<\/otherResults{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT;  return(OTHERRESULTSEND);}
{xmlwhitespace}*\<otherSolutionResult {YY_PRINT; return(OTHERSOLUTIONRESULTSTART);}
{xmlwhitespace}*\<\/otherSolutionResult{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT;  return(OTHERSOLUTIONRESULTEND);}
{xmlwhitespace}*\<otherSolutionResults {YY_PRINT; return(OTHERSOLUTIONRESULTSSTART);}
{xmlwhitespace}*\<\/otherSolutionResults{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(OTHERSOLUTIONRESULTSEND);}
{xmlwhitespace}*\<otherSolverOutput {YY_PRINT;  return(OTHERSOLVEROUTPUTSTART);}
{xmlwhitespace}*\<\/otherSolverOutput{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT;  return(OTHERSOLVEROUTPUTEND);}
{xmlwhitespace}*\<scheduledStartTime {YY_PRINT;  return(SCHEDULEDSTARTTIMESTART);}
{xmlwhitespace}*\<\/scheduledStartTime{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT;  return(SCHEDULEDSTARTTIMEEND);}
{xmlwhitespace}*\<serviceName {YY_PRINT;  return(SERVICENAMESTART);}
{xmlwhitespace}*\<\/serviceName{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT;  return(SERVICENAMEEND);}
{xmlwhitespace}*\<serviceURI {YY_PRINT;  return(SERVICEURISTART);}
{xmlwhitespace}*\<\/serviceURI{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT;  return(SERVICEURIEND);}
{xmlwhitespace}*\<serviceUtilization {YY_PRINT;  return(SERVICEUTILIZATIONSTART);}
{xmlwhitespace}*\<\/serviceUtilization{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT;  return(SERVICEUTILIZATIONEND);}
{xmlwhitespace}*\<solution {YY_PRINT; return(SOLUTIONSTART);}
{xmlwhitespace}*\<\/solution{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(SOLUTIONEND);}
{xmlwhitespace}*\<solverInvoked {YY_PRINT;  return(SOLVERINVOKEDSTART);}
{xmlwhitespace}*\<\/solverInvoked{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT;  return(SOLVERINVOKEDEND);}
{xmlwhitespace}*\<solverOutput {YY_PRINT;  return(SOLVEROUTPUTSTART);}
{xmlwhitespace}*\<\/solverOutput{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT;  return(SOLVEROUTPUTEND);}
{xmlwhitespace}*\<status {YY_PRINT; return(STATUSSTART);}
{xmlwhitespace}*\<\/status{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(STATUSEND);}
{xmlwhitespace}*\<submitTime {YY_PRINT;  return(SUBMITTIMESTART);}
{xmlwhitespace}*\<\/submitTime{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT;  return(SUBMITTIMEEND);}
{xmlwhitespace}*\<substatus {YY_PRINT;  return(SUBSTATUSSTART);}
{xmlwhitespace}*\<\/substatus{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT;  return(SUBSTATUSEND);}
{xmlwhitespace}*\<superBasic {YY_PRINT; return(SUPERBASICSTART);}
{xmlwhitespace}*\<\/superBasic{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(SUPERBASICEND);}
{xmlwhitespace}*\<systemInformation {YY_PRINT;  return(SYSTEMINFORMATIONSTART);}
{xmlwhitespace}*\<\/systemInformation{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT;  return(SYSTEMINFORMATIONEND);}
{xmlwhitespace}*\<time {YY_PRINT;  return(TIMESTART);}
{xmlwhitespace}*\<\/time{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT;  return(TIMEEND);}
{xmlwhitespace}*\<timeServiceStarted {YY_PRINT;  return(TIMESERVICESTARTEDSTART);}
{xmlwhitespace}*\<\/timeServiceStarted{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT;  return(TIMESERVICESTARTEDEND);}
{xmlwhitespace}*\<timeStamp {YY_PRINT;  return(TIMESTAMPSTART);}
{xmlwhitespace}*\<\/timeStamp{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT;  return(TIMESTAMPEND);}
{xmlwhitespace}*\<timingInformation {YY_PRINT; return(TIMINGINFORMATIONSTART);}
{xmlwhitespace}*\<\/timingInformation{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT;  return(TIMINGINFORMATIONEND);}
{xmlwhitespace}*\<totalJobsSoFar {YY_PRINT;  return(TOTALJOBSSOFARSTART);}
{xmlwhitespace}*\<\/totalJobsSoFar{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT;  return(TOTALJOBSSOFAREND);}
{xmlwhitespace}*\<unknown {YY_PRINT; return(UNKNOWNSTART);}
{xmlwhitespace}*\<\/unknown{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(UNKNOWNEND);}
{xmlwhitespace}*\<usedCPUNumber {YY_PRINT;  return(USEDCPUNUMBERSTART);}
{xmlwhitespace}*\<\/usedCPUNumber{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT;  return(USEDCPUNUMBEREND);}
{xmlwhitespace}*\<usedCPUSpeed {YY_PRINT;  return(USEDCPUSPEEDSTART);}
{xmlwhitespace}*\<\/usedCPUSpeed{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT;  return(USEDCPUSPEEDEND);} 
{xmlwhitespace}*\<usedDiskSpace {YY_PRINT;  return(USEDDISKSPACESTART);}
{xmlwhitespace}*\<\/usedDiskSpace{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT;  return(USEDDISKSPACEEND);}
{xmlwhitespace}*\<usedMemory {YY_PRINT;  return(USEDMEMORYSTART);}
{xmlwhitespace}*\<\/usedMemory{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT;  return(USEDMEMORYEND);}
{xmlwhitespace}*\<values {YY_PRINT; return(VALUESSTART);}
{xmlwhitespace}*\<\/values{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(VALUESEND);}
{xmlwhitespace}*\<valuesString {YY_PRINT;  return(VALUESSTRINGSTART);}
{xmlwhitespace}*\<\/valuesString{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT;  return(VALUESSTRINGEND);}
{xmlwhitespace}*\<var {YY_PRINT; return(VARSTART);}
{xmlwhitespace}*\<\/var{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(VAREND);}
{xmlwhitespace}*\<variables {YY_PRINT; return(VARIABLESSTART);}
{xmlwhitespace}*\<\/variables{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(VARIABLESEND);}
{xmlwhitespace}*\<varIdx {YY_PRINT; return(VARIDXSTART);}
{xmlwhitespace}*\<\/varIdx{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(VARIDXEND);}


 /* environments and comments */

[a-zA-Z0-9.:_*#$@, \t\r\n\/\-\+\=]+ { YY_PRINT;  yylval->sval = strdup( yytext);   yyextra->errorText = yylval->sval;    /*yylval->sval = yytext;*/  return (ELEMENTTEXT); }
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
<singlequoteattributetext>[^\']* {YY_PRINT;  BEGIN 0; yylval->sval = strdup(yytext);   /*yylval->sval = yytext;*/ return(ATTRIBUTETEXT);}
<osrlattributetext>([^>])* {YY_PRINT;  BEGIN 0; /*yylval->sval = strdup(yytext);*/  yylval->sval = yytext; return(OSRLATTRIBUTETEXT);}

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


