/* $Id$ */
/** @file OSparseosrl.l.1
 * 
 * @author  Horand Gassmann, Jun Ma, Kipp Martin 
 *
 * \remarks
 * Copyright (C) 2005-2014, Horand Gassmann, Jun Ma, Kipp Martin,
 * Northwestern University, and the University of Chicago.
 * All Rights Reserved.
 * This software is licensed under the Eclipse Public License. 
 * Please see the accompanying LICENSE file in root directory for terms.
 *
 * Like the grammar rules in OSParseosrl.y, this file is maintained in several pieces 
 * in order to avoid duplication when parsing elements of auxiliary schemas,
 * such as OSgL, OSnL, etc. This is the first part of OSparseosrl.l.   
 *
 * IMPORTANT! Convention regarding common patterns, such as "name", etc.:
 * Commonly occuring patterns must be kept in one place in order to avoid ambiguity in the parser.
 * Maintenance is easier if they are placed into the OSgL section. At any rate, it is important
 * to place temporary data into the correct parser data object.
 */
%{
//#define OSRLPARSERDEBUG

#ifdef OSRLPARSERDEBUG
	#define YY_PRINT  printf("%s", yytext)
#else     
	#define YY_PRINT
#endif
     
#include <iostream>
#include <sstream>  

#include "OSConfig.h"
#include "OSDataStructures.h"
#include "OSErrorClass.h"
#include "OSMathUtil.h"
#include "OSrLParserData.h"
#include "OSParseosrl.tab.hpp"
#include "OSResult.h"
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
return(DOUBLE);}

({xmlwhitespace}*\/>) {YY_PRINT; return(ENDOFELEMENT);}

 /* Patterns for attributes returning strings (that are potentially empty)*/

({xmlwhitespace}+targetObjectiveName{equality}\"\") {YY_PRINT; return(EMPTYTARGETOBJECTIVENAMEATT);}
({xmlwhitespace}+targetObjectiveName{equality}\'\') {YY_PRINT; return(EMPTYTARGETOBJECTIVENAMEATT);}
({xmlwhitespace}+targetObjectiveName{equality}\") {YY_PRINT; BEGIN doublequoteattributetext; return(TARGETOBJECTIVENAMEATT);}
({xmlwhitespace}+targetObjectiveName{equality}\') {YY_PRINT; BEGIN singlequoteattributetext; return(TARGETOBJECTIVENAMEATT);}

({xmlwhitespace}+weightedObjectives{equality}\"\") {YY_PRINT; return(EMPTYWEIGHTEDOBJECTIVESATT);}
({xmlwhitespace}+weightedObjectives{equality}\'\') {YY_PRINT; return(EMPTYWEIGHTEDOBJECTIVESATT);}
({xmlwhitespace}+weightedObjectives{equality}\") {YY_PRINT; BEGIN doublequoteattributetext; return(WEIGHTEDOBJECTIVESATT);}
({xmlwhitespace}+weightedObjectives{equality}\') {YY_PRINT; BEGIN singlequoteattributetext; return(WEIGHTEDOBJECTIVESATT);}

 /* Patterns for attributes returning numeric values*/

({xmlwhitespace}+numberOfOtherConstraintResults{equality}) {YY_PRINT; return(NUMBEROFOTHERCONSTRAINTRESULTSATT);}
({xmlwhitespace}+numberOfOtherMatrixProgrammingResults{equality}) {YY_PRINT; return(NUMBEROFOTHERMATRIXPROGRAMMINGRESULTSATT);}
({xmlwhitespace}+numberOfOtherMatrixConstraintResults{equality}) {YY_PRINT; return(NUMBEROFOTHERMATRIXCONSTRAINTRESULTSATT);}
({xmlwhitespace}+numberOfOtherMatrixObjectiveResults{equality}) {YY_PRINT; return(NUMBEROFOTHERMATRIXOBJECTIVERESULTSATT);}
({xmlwhitespace}+numberOfOtherMatrixVariableResults{equality}) {YY_PRINT; return(NUMBEROFOTHERMATRIXVARIABLERESULTSATT);}
({xmlwhitespace}+numberOfOtherObjectiveResults{equality}) {YY_PRINT; return(NUMBEROFOTHEROBJECTIVERESULTSATT);}
({xmlwhitespace}+numberOfOtherResults{equality}) {YY_PRINT; return(NUMBEROFOTHERRESULTSATT);}
({xmlwhitespace}+numberOfOtherSolutionResults{equality}) {YY_PRINT; return(NUMBEROFOTHERSOLUTIONRESULTSATT);}
({xmlwhitespace}+numberOfOtherVariableResults{equality}) {YY_PRINT; return(NUMBEROFOTHERVARIABLERESULTSATT);}
({xmlwhitespace}+numberOfSolutions{equality}) {YY_PRINT; return(NUMBEROFSOLUTIONSATT);}
({xmlwhitespace}+numberOfSolverOutputs{equality}) {YY_PRINT; return(NUMBEROFSOLVEROUTPUTSATT);}
({xmlwhitespace}+numberOfSubstatuses{equality}) {YY_PRINT; return(NUMBEROFSUBSTATUSESATT);}
({xmlwhitespace}+numberOfTimes{equality}) {YY_PRINT; return(NUMBEROFTIMESATT);}

({xmlwhitespace}+targetObjectiveIdx{equality}) {YY_PRINT; return(TARGETOBJECTIVEIDXATT);}

 /* Generic patterns matched in more than one element */

{xmlwhitespace}*\<status {YY_PRINT; return(STATUSSTART);}
{xmlwhitespace}*\<\/status{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(STATUSEND);}
{xmlwhitespace}*\<substatus {YY_PRINT;  return(SUBSTATUSSTART);}
{xmlwhitespace}*\<\/substatus{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT;  return(SUBSTATUSEND);}

 /* Patterns for top level elements */

{xmlwhitespace}*\<osrl{xmlwhitespace}*\> {return(OSRLSTARTEMPTY);}
{xmlwhitespace}*\<osrl{xmlwhitespace}+ {YY_PRINT; BEGIN osrlattributetext;  return(OSRLSTART);}
{xmlwhitespace}*\<\/osrl{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(OSRLEND);}
{xmlwhitespace}*\<resultHeader {YY_PRINT; return(HEADERSTART);}
{xmlwhitespace}*\<\/resultHeader{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(HEADEREND);}
{xmlwhitespace}*\<message {YY_PRINT;  return(MESSAGESTART);}
{xmlwhitespace}*\<\/message{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT;  return(MESSAGEEND);}

 /* Patterns for the <general> element */

{xmlwhitespace}*\<generalStatus {YY_PRINT; return(GENERALSTATUSSTART);}
{xmlwhitespace}*\<\/generalStatus{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(GENERALSTATUSEND);}
{xmlwhitespace}*\<solverInvoked {YY_PRINT;  return(SOLVERINVOKEDSTART);}
{xmlwhitespace}*\<\/solverInvoked{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT;  return(SOLVERINVOKEDEND);}
{xmlwhitespace}*\<timeStamp {YY_PRINT;  return(TIMESTAMPSTART);}
{xmlwhitespace}*\<\/timeStamp{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT;  return(TIMESTAMPEND);}

 /* Patterns for the <system> element */

{xmlwhitespace}*\<systemInformation {YY_PRINT;  return(SYSTEMINFORMATIONSTART);}
{xmlwhitespace}*\<\/systemInformation{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT;  return(SYSTEMINFORMATIONEND);}
{xmlwhitespace}*\<availableDiskSpace {YY_PRINT;  return(AVAILABLEDISKSPACESTART);}
{xmlwhitespace}*\<\/availableDiskSpace{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(AVAILABLEDISKSPACEEND);}
{xmlwhitespace}*\<availableMemory {YY_PRINT;  return(AVAILABLEMEMORYSTART);}
{xmlwhitespace}*\<\/availableMemory{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(AVAILABLEMEMORYEND);}
{xmlwhitespace}*\<availableCPUSpeed {YY_PRINT;  return(AVAILABLECPUSPEEDSTART);}
{xmlwhitespace}*\<\/availableCPUSpeed{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(AVAILABLECPUSPEEDEND);}
{xmlwhitespace}*\<availableCPUNumber {YY_PRINT;  return(AVAILABLECPUNUMBERSTART);}
{xmlwhitespace}*\<\/availableCPUNumber{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(AVAILABLECPUNUMBEREND);}
 
 /* Patterns for the <service> element */

{xmlwhitespace}*\<currentState {YY_PRINT;  return(CURRENTSTATESTART);}
{xmlwhitespace}*\<\/currentState{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT;  return(CURRENTSTATEEND);}
{xmlwhitespace}*\<currentJobCount {YY_PRINT;  return(CURRENTJOBCOUNTSTART);}
{xmlwhitespace}*\<\/currentJobCount{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT;  return(CURRENTJOBCOUNTEND);}
{xmlwhitespace}*\<totalJobsSoFar {YY_PRINT;  return(TOTALJOBSSOFARSTART);}
{xmlwhitespace}*\<\/totalJobsSoFar{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT;  return(TOTALJOBSSOFAREND);}
{xmlwhitespace}*\<timeServiceStarted {YY_PRINT;  return(TIMESERVICESTARTEDSTART);}
{xmlwhitespace}*\<\/timeServiceStarted{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT;  return(TIMESERVICESTARTEDEND);}
{xmlwhitespace}*\<serviceUtilization {YY_PRINT;  return(SERVICEUTILIZATIONSTART);}
{xmlwhitespace}*\<\/serviceUtilization{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT;  return(SERVICEUTILIZATIONEND);}
 
 /* Patterns for the <job> element */

{xmlwhitespace}*\<submitTime {YY_PRINT;  return(SUBMITTIMESTART);}
{xmlwhitespace}*\<\/submitTime{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT;  return(SUBMITTIMEEND);}
{xmlwhitespace}*\<scheduledStartTime {YY_PRINT;  return(SCHEDULEDSTARTTIMESTART);}
{xmlwhitespace}*\<\/scheduledStartTime{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT;  return(SCHEDULEDSTARTTIMEEND);}
{xmlwhitespace}*\<actualStartTime {YY_PRINT;  return(ACTUALSTARTTIMESTART);}
{xmlwhitespace}*\<\/actualStartTime{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT;  return(ACTUALSTARTTIMEEND);}
{xmlwhitespace}*\<endTime {YY_PRINT;  return(ENDTIMESTART);}
{xmlwhitespace}*\<\/endTime{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT;  return(ENDTIMEEND);}
{xmlwhitespace}*\<time {YY_PRINT;  return(TIMESTART);}
{xmlwhitespace}*\<\/time{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT;  return(TIMEEND);}
{xmlwhitespace}*\<timingInformation {YY_PRINT; return(TIMINGINFORMATIONSTART);}
{xmlwhitespace}*\<\/timingInformation{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT;  return(TIMINGINFORMATIONEND);}
{xmlwhitespace}*\<usedDiskSpace {YY_PRINT;  return(USEDDISKSPACESTART);}
{xmlwhitespace}*\<\/usedDiskSpace{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT;  return(USEDDISKSPACEEND);}
{xmlwhitespace}*\<usedMemory {YY_PRINT;  return(USEDMEMORYSTART);}
{xmlwhitespace}*\<\/usedMemory{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT;  return(USEDMEMORYEND);}
{xmlwhitespace}*\<usedCPUSpeed {YY_PRINT;  return(USEDCPUSPEEDSTART);}
{xmlwhitespace}*\<\/usedCPUSpeed{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT;  return(USEDCPUSPEEDEND);} 
{xmlwhitespace}*\<usedCPUNumber {YY_PRINT;  return(USEDCPUNUMBERSTART);}
{xmlwhitespace}*\<\/usedCPUNumber{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT;  return(USEDCPUNUMBEREND);}

 /* General patterns for the <optimization> element */

{xmlwhitespace}*\<solution {YY_PRINT; return(SOLUTIONSTART);}
{xmlwhitespace}*\<\/solution{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(SOLUTIONEND);}
{xmlwhitespace}*\<values {YY_PRINT; return(VALUESSTART);}
{xmlwhitespace}*\<\/values{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(VALUESEND);}
{xmlwhitespace}*\<basisStatus {YY_PRINT;  return(BASISSTATUSSTART);}
{xmlwhitespace}*\<\/basisStatus{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(BASISSTATUSEND);}
{xmlwhitespace}*\<idx {YY_PRINT; return(IDXSTART);}
{xmlwhitespace}*\<\/idx{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(IDXEND);}

 /* Patterns for the <variables> element */

{xmlwhitespace}*\<valuesString {YY_PRINT;  return(VALUESSTRINGSTART);}
{xmlwhitespace}*\<\/valuesString{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT;  return(VALUESSTRINGEND);}

 /* Patterns for the <constraints> element */
{xmlwhitespace}*\<dualValues {YY_PRINT; return(DUALVALUESSTART);}
{xmlwhitespace}*\<\/dualValues{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(DUALVALUESEND);}

 /* Patterns for <matrixProgramming> */

{xmlwhitespace}*\<otherMatrixVariableResult {YY_PRINT;  return(OTHERMATRIXVARIABLERESULTSTART);}
{xmlwhitespace}*\<\/otherMatrixVariableResult{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT;  return(OTHERMATRIXVARIABLERESULTEND);}
{xmlwhitespace}*\<otherMatrixProgrammingResult {YY_PRINT;  return(OTHERMATRIXPROGRAMMINGRESULTSTART);}
{xmlwhitespace}*\<\/otherMatrixProgrammingResult{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT;  return(OTHERMATRIXPROGRAMMINGRESULTEND);}

 /* Other patterns */

{xmlwhitespace}*\<otherResults {YY_PRINT;  return(OTHERRESULTSSTART);}
{xmlwhitespace}*\<\/otherResults{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT;  return(OTHERRESULTSEND);}
{xmlwhitespace}*\<otherSolutionResult {YY_PRINT; return(OTHERSOLUTIONRESULTSTART);}
{xmlwhitespace}*\<\/otherSolutionResult{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT;  return(OTHERSOLUTIONRESULTEND);}
{xmlwhitespace}*\<otherSolutionResults {YY_PRINT; return(OTHERSOLUTIONRESULTSSTART);}
{xmlwhitespace}*\<\/otherSolutionResults{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(OTHERSOLUTIONRESULTSEND);}
{xmlwhitespace}*\<otherSolverOutput {YY_PRINT;  return(OTHERSOLVEROUTPUTSTART);}
{xmlwhitespace}*\<\/otherSolverOutput{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT;  return(OTHERSOLVEROUTPUTEND);}
{xmlwhitespace}*\<solverOutput {YY_PRINT;  return(SOLVEROUTPUTSTART);}
{xmlwhitespace}*\<\/solverOutput{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT;  return(SOLVEROUTPUTEND);}

 /* include file OSParseosgl.l.patterns --- patterns for OSgL schema elements */

{xmlwhitespace}*\<base64BinaryData {YY_PRINT; return(BASE64START);}
{xmlwhitespace}*\<\/base64BinaryData{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(BASE64END);}
{xmlwhitespace}*\<el {YY_PRINT; return(ELSTART);}
{xmlwhitespace}*\<\/el{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT;  return(ELEND);}

 /* The <item> element and the children of the file header element are treated specially 
    because they may legitimately contain special characters */

{xmlwhitespace}*\<item{xmlwhitespace}*\>{xmlwhitespace}*\<\/item{xmlwhitespace}*\>{xmlwhitespace}* {  YY_PRINT;  return(ITEMEMPTY);}
{xmlwhitespace}*\<item{xmlwhitespace}*\>{xmlwhitespace}* { YY_PRINT; BEGIN itemtext; return(ITEMSTART);}
{xmlwhitespace}*\<\/item{xmlwhitespace}*>{xmlwhitespace}* { YY_PRINT; return(ITEMEND);}
{xmlwhitespace}*\<item{xmlwhitespace}*\/>{xmlwhitespace}* { YY_PRINT; return(ITEMSTARTANDEND);}

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

 /* Patterns for attributes returning strings (that are potentially empty)*/

({xmlwhitespace}+baseTranspose{equality}\"\") {YY_PRINT; return(EMPTYBASETRANSPOSEATT);}
({xmlwhitespace}+baseTranspose{equality}\'\') {YY_PRINT; return(EMPTYBASETRANSPOSEATT);}
({xmlwhitespace}+baseTranspose{equality}\") {YY_PRINT; BEGIN doublequoteattributetext; return(BASETRANSPOSEATT);}
({xmlwhitespace}+baseTranspose{equality}\') {YY_PRINT; BEGIN singlequoteattributetext; return(BASETRANSPOSEATT);}

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

({xmlwhitespace}+matrixConType{equality}\"\") {YY_PRINT; return(EMPTYMATRIXCONTYPEATT);}
({xmlwhitespace}+matrixConType{equality}\'\') {YY_PRINT; return(EMPTYMATRIXCONTYPEATT);}
({xmlwhitespace}+matrixConType{equality}\") {YY_PRINT; BEGIN doublequoteattributetext; return(MATRIXCONTYPEATT);}
({xmlwhitespace}+matrixConType{equality}\') {YY_PRINT; BEGIN singlequoteattributetext; return(MATRIXCONTYPEATT);}

({xmlwhitespace}+matrixObjType{equality}\"\") {YY_PRINT; return(EMPTYMATRIXOBJTYPEATT);}
({xmlwhitespace}+matrixObjType{equality}\'\') {YY_PRINT; return(EMPTYMATRIXOBJTYPEATT);}
({xmlwhitespace}+matrixObjType{equality}\") {YY_PRINT; BEGIN doublequoteattributetext; return(MATRIXOBJTYPEATT);}
({xmlwhitespace}+matrixObjType{equality}\') {YY_PRINT; BEGIN singlequoteattributetext; return(MATRIXOBJTYPEATT);}

({xmlwhitespace}+matrixType{equality}\"\") {YY_PRINT; return(EMPTYMATRIXTYPEATT);}
({xmlwhitespace}+matrixType{equality}\'\') {YY_PRINT; return(EMPTYMATRIXTYPEATT);}
({xmlwhitespace}+matrixType{equality}\") {YY_PRINT; BEGIN doublequoteattributetext; return(MATRIXTYPEATT);}
({xmlwhitespace}+matrixType{equality}\') {YY_PRINT; BEGIN singlequoteattributetext; return(MATRIXTYPEATT);}

({xmlwhitespace}+matrixVarType{equality}\"\") {YY_PRINT; return(EMPTYMATRIXVARTYPEATT);}
({xmlwhitespace}+matrixVarType{equality}\'\') {YY_PRINT; return(EMPTYMATRIXVARTYPEATT);}
({xmlwhitespace}+matrixVarType{equality}\") {YY_PRINT; BEGIN doublequoteattributetext; return(MATRIXVARTYPEATT);}
({xmlwhitespace}+matrixVarType{equality}\') {YY_PRINT; BEGIN singlequoteattributetext; return(MATRIXVARTYPEATT);}

({xmlwhitespace}+name{equality}\"\") {YY_PRINT; return(EMPTYNAMEATT);}
({xmlwhitespace}+name{equality}\'\') {YY_PRINT; return(EMPTYNAMEATT);}
({xmlwhitespace}+name{equality}\") {YY_PRINT; BEGIN doublequoteattributetext; return(NAMEATT);}
({xmlwhitespace}+name{equality}\') {YY_PRINT; BEGIN singlequoteattributetext; return(NAMEATT);}

({xmlwhitespace}+objType{equality}\"\") {YY_PRINT; return(EMPTYOBJTYPEATT);}
({xmlwhitespace}+objType{equality}\'\') {YY_PRINT; return(EMPTYOBJTYPEATT);}
({xmlwhitespace}+objType{equality}\") {YY_PRINT; BEGIN doublequoteattributetext; return(OBJTYPEATT);}
({xmlwhitespace}+objType{equality}\') {YY_PRINT; BEGIN singlequoteattributetext; return(OBJTYPEATT);}

({xmlwhitespace}+rowMajor{equality}\"\") {YY_PRINT; return(EMPTYROWMAJORATT);}
({xmlwhitespace}+rowMajor{equality}\'\') {YY_PRINT; return(EMPTYROWMAJORATT);}
({xmlwhitespace}+rowMajor{equality}\") {YY_PRINT; BEGIN doublequoteattributetext; return(ROWMAJORATT);}
({xmlwhitespace}+rowMajor{equality}\') {YY_PRINT; BEGIN singlequoteattributetext; return(ROWMAJORATT);}

({xmlwhitespace}+shape{equality}\"\") {YY_PRINT; return(EMPTYSHAPEATT);}
({xmlwhitespace}+shape{equality}\'\') {YY_PRINT; return(EMPTYSHAPEATT);}
({xmlwhitespace}+shape{equality}\") {YY_PRINT; BEGIN doublequoteattributetext; return(SHAPEATT);}
({xmlwhitespace}+shape{equality}\') {YY_PRINT; BEGIN singlequoteattributetext; return(SHAPEATT);}

({xmlwhitespace}+solver{equality}\"\") {YY_PRINT; return(EMPTYSOLVERATT);}
({xmlwhitespace}+solver{equality}\'\') {YY_PRINT; return(EMPTYSOLVERATT);}
({xmlwhitespace}+solver{equality}\") {YY_PRINT; BEGIN doublequoteattributetext; return(SOLVERATT);}
({xmlwhitespace}+solver{equality}\') {YY_PRINT; BEGIN singlequoteattributetext; return(SOLVERATT);}

({xmlwhitespace}+symmetry{equality}\"\") {YY_PRINT; return(EMPTYSYMMETRYATT);}
({xmlwhitespace}+symmetry{equality}\'\') {YY_PRINT; return(EMPTYSYMMETRYATT);}
({xmlwhitespace}+symmetry{equality}\") {YY_PRINT; BEGIN doublequoteattributetext; return(SYMMETRYATT);}
({xmlwhitespace}+symmetry{equality}\') {YY_PRINT; BEGIN singlequoteattributetext; return(SYMMETRYATT);}

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

({xmlwhitespace}+varType{equality}\"\") {YY_PRINT; return(EMPTYVARTYPEATT);}
({xmlwhitespace}+varType{equality}\'\') {YY_PRINT; return(EMPTYVARTYPEATT);}
({xmlwhitespace}+varType{equality}\") {YY_PRINT; BEGIN doublequoteattributetext; return(VARTYPEATT);}
({xmlwhitespace}+varType{equality}\') {YY_PRINT; BEGIN singlequoteattributetext; return(VARTYPEATT);}

({xmlwhitespace}+valueType{equality}\"\") {YY_PRINT; return(EMPTYVALUETYPEATT);}
({xmlwhitespace}+valueType{equality}\'\') {YY_PRINT; return(EMPTYVALUETYPEATT);}
({xmlwhitespace}+valueType{equality}\") {YY_PRINT; BEGIN doublequoteattributetext; return(VALUETYPEATT);}
({xmlwhitespace}+valueType{equality}\') {YY_PRINT; BEGIN singlequoteattributetext; return(VALUETYPEATT);}

 /* Patterns for attributes returning numeric values*/

({xmlwhitespace}+numberOfBlocks{equality}) {YY_PRINT; return(NUMBEROFBLOCKSATT);}
({xmlwhitespace}+numberOfColumns{equality}) {YY_PRINT; return(NUMBEROFCOLUMNSATT);}
({xmlwhitespace}+numberOfCon{equality}) {YY_PRINT; return(NUMBEROFCONATT);}
({xmlwhitespace}+numberOfConstraints{equality}) {YY_PRINT; return(NUMBEROFCONSTRAINTSATT);}
({xmlwhitespace}+numberOfEl{equality}) {YY_PRINT;  return(NUMBEROFELATT);}
({xmlwhitespace}+numberOfEnumerations{equality}) {YY_PRINT;  return(NUMBEROFENUMERATIONSATT);}
({xmlwhitespace}+numberOfItems{equality}) {YY_PRINT;  return(NUMBEROFITEMSATT);}
({xmlwhitespace}+numberOfMatrices{equality}) {YY_PRINT; return(NUMBEROFMATRICESATT);}
({xmlwhitespace}+numberOfMatrixCon{equality}) {YY_PRINT; return(NUMBEROFMATRIXCONATT);}
({xmlwhitespace}+numberOfMatrixObj{equality}) {YY_PRINT; return(NUMBEROFMATRIXOBJATT);}
({xmlwhitespace}+numberOfMatrixVar{equality}) {YY_PRINT; return(NUMBEROFMATRIXVARATT);}
({xmlwhitespace}+numberOfObj{equality}) {YY_PRINT; return(NUMBEROFOBJATT);}
({xmlwhitespace}+numberOfObjectives{equality}) {YY_PRINT; return(NUMBEROFOBJECTIVESATT);}
({xmlwhitespace}+numberOfRows{equality}) {YY_PRINT; return(NUMBEROFROWSATT);}
({xmlwhitespace}+numberOfValues{equality}) {YY_PRINT; return(NUMBEROFVALUESATT);}
({xmlwhitespace}+numberOfVar{equality}) {YY_PRINT; return(NUMBEROFVARATT);}
({xmlwhitespace}+numberOfVariables{equality}) {YY_PRINT; return(NUMBEROFVARIABLESATT);}
({xmlwhitespace}+numberOfVarIdx{equality}) {YY_PRINT; return(NUMBEROFVARIDXATT);}

({xmlwhitespace}+baseMatrixIdx{equality}) {YY_PRINT; return(BASEMATRIXIDXATT);}
({xmlwhitespace}+targetMatrixFirstRow{equality}) {YY_PRINT; return(TARGETMATRIXFIRSTROWATT);}
({xmlwhitespace}+targetMatrixFirstCol{equality}) {YY_PRINT; return(TARGETMATRIXFIRSTCOLATT);}
({xmlwhitespace}+baseMatrixStartRow{equality}) {YY_PRINT; return(BASEMATRIXSTARTROWATT);}
({xmlwhitespace}+baseMatrixStartCol{equality}) {YY_PRINT; return(BASEMATRIXSTARTCOLATT);}
({xmlwhitespace}+baseMatrixEndRow{equality}) {YY_PRINT; return(BASEMATRIXENDROWATT);}
({xmlwhitespace}+baseMatrixEndCol{equality}) {YY_PRINT; return(BASEMATRIXENDCOLATT);}
({xmlwhitespace}+scalarMultiplier{equality}) {YY_PRINT; return(SCALARMULTIPLIERATT);}
({xmlwhitespace}+blockRowIdx{equality}) {YY_PRINT; return(BLOCKROWIDXATT);}
({xmlwhitespace}+blockColIdx{equality}) {YY_PRINT; return(BLOCKCOLIDXATT);}
({xmlwhitespace}+constant{equality}) {YY_PRINT; return(CONSTANTATT);}

({xmlwhitespace}+matrixVarIdx{equality}) {YY_PRINT; return(MATRIXVARIDXATT);}
({xmlwhitespace}+matrixObjIdx{equality}) {YY_PRINT; return(MATRIXOBJIDXATT);}
({xmlwhitespace}+matrixConIdx{equality}) {YY_PRINT; return(MATRIXCONIDXATT);}

({xmlwhitespace}+idx{equality})  {YY_PRINT;  return(IDXATT);}
({xmlwhitespace}+incr{equality}) {YY_PRINT; return(INCRATT);}
({xmlwhitespace}+mult{equality}) {YY_PRINT; return(MULTATT);}
({xmlwhitespace}+coef{equality}) {YY_PRINT; return(COEFATT);}
({xmlwhitespace}+sizeOf{equality}) {YY_PRINT; return(SIZEOFATT);}

 /* Patterns for the <matrices> element */

{xmlwhitespace}*\<matrices {YY_PRINT;  return(MATRICESSTART);}
{xmlwhitespace}*\<\/matrices{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT;  return(MATRICESEND);}
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
{xmlwhitespace}*\<objReferenceElements {YY_PRINT;  return(OBJREFERENCEELEMENTSSTART);}
{xmlwhitespace}*\<\/objReferenceElements{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT;  return(OBJREFERENCEELEMENTSEND);}
{xmlwhitespace}*\<conReferenceElements {YY_PRINT;  return(CONREFERENCEELEMENTSSTART);}
{xmlwhitespace}*\<\/conReferenceElements{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT;  return(CONREFERENCEELEMENTSEND);}
{xmlwhitespace}*\<linearElements {YY_PRINT;  return(LINEARELEMENTSSTART);}
{xmlwhitespace}*\<\/linearElements{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT;  return(LINEARELEMENTSEND);}
{xmlwhitespace}*\<generalElements {YY_PRINT;  return(GENERALELEMENTSSTART);}
{xmlwhitespace}*\<\/generalElements{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT;  return(GENERALELEMENTSEND);}
{xmlwhitespace}*\<stringValuedElements {YY_PRINT;  return(STRINGVALUEDELEMENTSSTART);}
{xmlwhitespace}*\<\/stringValuedElements{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT;  return(STRINGVALUEDELEMENTSEND);}

{xmlwhitespace}*\<start {YY_PRINT;  return(STARTVECTORSTART);}
{xmlwhitespace}*\<\/start{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT;  return(STARTVECTOREND);}
{xmlwhitespace}*\<index {YY_PRINT;  return(INDEXSTART);}
{xmlwhitespace}*\<\/index{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT;  return(INDEXEND);}
{xmlwhitespace}*\<value {YY_PRINT;  return(VALUESTART);}
{xmlwhitespace}*\<\/value{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT;  return(VALUEEND);}
{xmlwhitespace}*\<nonzeros {YY_PRINT;  return(NONZEROSSTART);}
{xmlwhitespace}*\<\/nonzeros{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT;  return(NONZEROSEND);}
{xmlwhitespace}*\<indexes {YY_PRINT;  return(INDEXESSTART);}
{xmlwhitespace}*\<\/indexes{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT;  return(INDEXESEND);}
{xmlwhitespace}*\<values {YY_PRINT;  return(VALUESSTART);}
{xmlwhitespace}*\<\/values{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT;  return(VALUESEND);}
{xmlwhitespace}*\<colOffset {YY_PRINT;  return(COLOFFSETSTART);}
{xmlwhitespace}*\<\/colOffset{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT;  return(COLOFFSETEND);}
{xmlwhitespace}*\<rowOffset {YY_PRINT;  return(ROWOFFSETSTART);}
{xmlwhitespace}*\<\/rowOffset{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT;  return(ROWOFFSETEND);}
{xmlwhitespace}*\<varIdx {YY_PRINT;  return(VARIDXSTART);}
{xmlwhitespace}*\<\/varIdx{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT;  return(VARIDXEND);}
{xmlwhitespace}*\<transformation {YY_PRINT;  return(TRANSFORMATIONSTART);}
{xmlwhitespace}*\<\/transformation{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT;  return(TRANSFORMATIONEND);}


 /* Patterns for <matrices> element */

{xmlwhitespace}*\<matrixProgramming {YY_PRINT;  return(MATRIXPROGRAMMINGSTART);}
{xmlwhitespace}*\<\/matrixProgramming{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT;  return(MATRIXPROGRAMMINGEND);}
{xmlwhitespace}*\<matrixVariables {YY_PRINT;  return(MATRIXVARIABLESSTART);}
{xmlwhitespace}*\<\/matrixVariables{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT;  return(MATRIXVARIABLESEND);}
{xmlwhitespace}*\<matrixVar {YY_PRINT;  return(MATRIXVARSTART);}
{xmlwhitespace}*\<\/matrixVar{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT;  return(MATRIXVAREND);}
{xmlwhitespace}*\<matrixObjectives {YY_PRINT;  return(MATRIXOBJECTIVESSTART);}
{xmlwhitespace}*\<\/matrixObjectives{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT;  return(MATRIXOBJECTIVESEND);}
{xmlwhitespace}*\<matrixObj {YY_PRINT;  return(MATRIXOBJSTART);}
{xmlwhitespace}*\<\/matrixObj{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT;  return(MATRIXOBJEND);}
{xmlwhitespace}*\<matrixConstraints {YY_PRINT;  return(MATRIXCONSTRAINTSSTART);}
{xmlwhitespace}*\<\/matrixConstraints{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT;  return(MATRIXCONSTRAINTSEND);}
{xmlwhitespace}*\<matrixCon {YY_PRINT;  return(MATRIXCONSTART);}
{xmlwhitespace}*\<\/matrixCon{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT;  return(MATRIXCONEND);}

 /* Other patterns shared among all three major schemas */

{xmlwhitespace}*\<con {YY_PRINT; return(CONSTART);}
{xmlwhitespace}*\<\/con{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(CONEND);}
{xmlwhitespace}*\<constraints {YY_PRINT; return(CONSTRAINTSSTART);}
{xmlwhitespace}*\<\/constraints{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(CONSTRAINTSEND);}
{xmlwhitespace}*\<obj {YY_PRINT; return(OBJSTART);}
{xmlwhitespace}*\<\/obj{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(OBJEND);}
{xmlwhitespace}*\<objectives {YY_PRINT; return(OBJECTIVESSTART);}
{xmlwhitespace}*\<\/objectives{xmlwhitespace}*\>{xmlwhitespace}*  {YY_PRINT; return(OBJECTIVESEND);}
{xmlwhitespace}*\<var {YY_PRINT; return(VARSTART);}
{xmlwhitespace}*\<\/var{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(VAREND);}
{xmlwhitespace}*\<variables {YY_PRINT; return(VARIABLESSTART);}
{xmlwhitespace}*\<\/variables{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(VARIABLESEND);}


 /* The remaining patterns are shared between OSoL and OSrL. 
    Since they have similar structure, the patterns are grouped by schema elements */

 /* Patterns for major headings in OSoL and OSrL */

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

 /* Patterns for representing a basis in LP */

{xmlwhitespace}*\<atEquality {YY_PRINT; return(ATEQUALITYSTART);}
{xmlwhitespace}*\<\/atEquality{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(ATEQUALITYEND);}
{xmlwhitespace}*\<atLower {YY_PRINT; return(ATLOWERSTART);}
{xmlwhitespace}*\<\/atLower{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(ATLOWEREND);}
{xmlwhitespace}*\<atUpper {YY_PRINT; return(ATUPPERSTART);}
{xmlwhitespace}*\<\/atUpper{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(ATUPPEREND);}
{xmlwhitespace}*\<basic {YY_PRINT; return(BASICSTART);}
{xmlwhitespace}*\<\/basic{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(BASICEND);}
{xmlwhitespace}*\<isFree {YY_PRINT; return(ISFREESTART);}
{xmlwhitespace}*\<\/isFree{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(ISFREEEND);}
{xmlwhitespace}*\<superbasic {YY_PRINT; return(SUPERBASICSTART);}
{xmlwhitespace}*\<\/superbasic{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(SUPERBASICEND);}
{xmlwhitespace}*\<unknown {YY_PRINT; return(UNKNOWNSTART);}
{xmlwhitespace}*\<\/unknown{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(UNKNOWNEND);}

 /* Patterns for the <general> element */

{xmlwhitespace}*\<serviceURI {YY_PRINT;  return(SERVICEURISTART);}
{xmlwhitespace}*\<\/serviceURI{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT;  return(SERVICEURIEND);}
{xmlwhitespace}*\<serviceName {YY_PRINT;  return(SERVICENAMESTART);}
{xmlwhitespace}*\<\/serviceName{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT;  return(SERVICENAMEEND);}
{xmlwhitespace}*\<instanceName {YY_PRINT;  return(INSTANCENAMESTART);}
{xmlwhitespace}*\<\/instanceName{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT;  return(INSTANCENAMEEND);}
{xmlwhitespace}*\<jobID {YY_PRINT;  return(JOBIDSTART);}
{xmlwhitespace}*\<\/jobID{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT;  return(JOBIDEND);}

 /* Other patterns */

{xmlwhitespace}*\<enumeration {YY_PRINT;  return(ENUMERATIONSTART);}
{xmlwhitespace}*\<\/enumeration{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT;  return(ENUMERATIONEND);}
{xmlwhitespace}*\<other {YY_PRINT; return(OTHERSTART);}
{xmlwhitespace}*\<\/other{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(OTHEREND);}

 /* include file OSParseosnl.l.patterns --- patterns for OSnL schema elements */

 /* patterns for <nonlinearExpressions> */

{xmlwhitespace}*\<nonlinearExpressions {YY_PRINT;  return(NONLINEAREXPRESSIONSSTART);}
{xmlwhitespace}*\<\/nonlinearExpressions{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(NONLINEAREXPRESSIONSEND);}
({xmlwhitespace}+numberOfNonlinearExpressions{equality}) {YY_PRINT; return(NUMBEROFNONLINEAREXPRESSIONS);}
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
{xmlwhitespace}*\<sqrt{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(SQRTSTART);}
{xmlwhitespace}*\<\/sqrt{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(SQRTEND);}
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

 /* patterns for <matrixExpressions> */

{xmlwhitespace}*\<matrixExpressions {YY_PRINT;  return(MATRIXEXPRESSIONSSTART);}
{xmlwhitespace}*\<\/matrixExpressions{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(MATRIXEXPRESSIONSEND);}
({xmlwhitespace}+numberOfExpr{equality}) {YY_PRINT; return(NUMBEROFEXPR);}
{xmlwhitespace}*\<expr {YY_PRINT; return(EXPRSTART);}
{xmlwhitespace}*\<\/expr{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(EXPREND);}

{xmlwhitespace}*\<matrixDeterminant{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(MATRIXDETERMINANTSTART);}
{xmlwhitespace}*\<\/matrixDeterminant{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(MATRIXDETERMINANTEND);}
{xmlwhitespace}*\<matrixTrace{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(MATRIXTRACESTART);}
{xmlwhitespace}*\<\/matrixTrace{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(MATRIXTRACEEND);}
{xmlwhitespace}*\<matrixToScalar{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(MATRIXTOSCALARSTART);}
{xmlwhitespace}*\<\/matrixToScalar{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(MATRIXTOSCALAREND);}

 /* patterns for <matrixTerms> in <matrixConstraints> and <matrixObjectives>*/

({xmlwhitespace}+numberOfMatrixTerms{equality}) {YY_PRINT; return(NUMBEROFMATRIXTERMSATT);}
{xmlwhitespace}*\<matrixTerm {YY_PRINT;  return(MATRIXTERMSTART);}
{xmlwhitespace}*\<\/matrixTerm{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT;  return(MATRIXTERMEND);}

{xmlwhitespace}*\<matrixReference {YY_PRINT;  return(MATRIXREFERENCESTART);}
{xmlwhitespace}*\<\/matrixReference{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(MATRIXREFERENCEEND);}
{xmlwhitespace}*\<matrixDiagonal{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(MATRIXDIAGONALSTART);}
{xmlwhitespace}*\<\/matrixDiagonal{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(MATRIXDIAGONALEND);}
{xmlwhitespace}*\<matrixDotTimes{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(MATRIXDOTTIMESSTART);}
{xmlwhitespace}*\<\/matrixDotTimes{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(MATRIXDOTTIMESEND);}
{xmlwhitespace}*\<matrixInverse{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(MATRIXINVERSESTART);}
{xmlwhitespace}*\<\/matrixInverse{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(MATRIXINVERSEEND);}
{xmlwhitespace}*\<matrixLowerTriangle {YY_PRINT; return(MATRIXLOWERTRIANGLESTART);}
{xmlwhitespace}*\<\/matrixLowerTriangle{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(MATRIXLOWERTRIANGLEEND);}
{xmlwhitespace}*\<matrixUpperTriangle {YY_PRINT; return(MATRIXUPPERTRIANGLESTART);}
{xmlwhitespace}*\<\/matrixUpperTriangle{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(MATRIXUPPERTRIANGLEEND);}
{xmlwhitespace}*\<matrixMerge {YY_PRINT; return(MATRIXMERGESTART);}
{xmlwhitespace}*\<\/matrixMerge{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(MATRIXMERGEEND);}
{xmlwhitespace}*\<matrixMinus{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(MATRIXMINUSSTART);}
{xmlwhitespace}*\<\/matrixMinus{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(MATRIXMINUSEND);}
{xmlwhitespace}*\<matrixNegate{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(MATRIXNEGATESTART);}
{xmlwhitespace}*\<\/matrixNegate{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(MATRIXNEGATEEND);}
{xmlwhitespace}*\<matrixPlus{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(MATRIXPLUSSTART);}
{xmlwhitespace}*\<\/matrixPlus{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(MATRIXPLUSEND);}
{xmlwhitespace}*\<matrixTimes{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(MATRIXTIMESSTART);}
{xmlwhitespace}*\<\/matrixTimes{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(MATRIXTIMESEND);}
{xmlwhitespace}*\<matrixProduct{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(MATRIXPRODUCTSTART);}
{xmlwhitespace}*\<\/matrixProduct{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(MATRIXPRODUCTEND);}
{xmlwhitespace}*\<matrixScalarTimes{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(MATRIXSCALARTIMESSTART);}
{xmlwhitespace}*\<\/matrixScalarTimes{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(MATRIXSCALARTIMESEND);}
{xmlwhitespace}*\<matrixSubmatrixAt{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(MATRIXSUBMATRIXATSTART);}
{xmlwhitespace}*\<\/matrixSubmatrixAt{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(MATRIXSUBMATRIXATEND);}
{xmlwhitespace}*\<matrixTranspose{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(MATRIXTRANSPOSESTART);}
{xmlwhitespace}*\<\/matrixTranspose{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(MATRIXTRANSPOSEEND);}
{xmlwhitespace}*\<identityMatrix{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(IDENTITYMATRIXSTART);}
{xmlwhitespace}*\<\/identityMatrix{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(IDENTITYMATRIXEND);}

 /* attributes returning strings (that are potentially empty)*/

({xmlwhitespace}+id{equality}\"\") {YY_PRINT; return(EMPTYIDATT);}
({xmlwhitespace}+id{equality}\'\') {YY_PRINT; return(EMPTYIDATT);}
({xmlwhitespace}+id{equality}\") {YY_PRINT; BEGIN doublequoteattributetext; return(IDATT);}
({xmlwhitespace}+id{equality}\') {YY_PRINT; BEGIN singlequoteattributetext; return(IDATT);}

({xmlwhitespace}+includeDiagonal{equality}\"\") {YY_PRINT; return(EMPTYINCLUDEDIAGONALATT);}
({xmlwhitespace}+includeDiagonal{equality}\'\') {YY_PRINT; return(EMPTYINCLUDEDIAGONALATT);}
({xmlwhitespace}+includeDiagonal{equality}\") {YY_PRINT; BEGIN doublequoteattributetext; return(INCLUDEDIAGONALATT);}
({xmlwhitespace}+includeDiagonal{equality}\') {YY_PRINT; BEGIN singlequoteattributetext; return(INCLUDEDIAGONALATT);}

 /* last section of OSParseosrl.l */

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
<osrlattributetext>([^>])* {YY_PRINT;  BEGIN 0;  /*yylval->sval = strdup(yytext);*/  yylval->sval = yytext; return(OSRLATTRIBUTETEXT);}

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


