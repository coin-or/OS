/* $Id$ */
/** @file OSParseosil.l.1
 * 
 * @author  Robert Fourer, Horand Gassmann, Jun Ma, Kipp Martin, 
 *
 * \remarks
 * Copyright (C) 2005-2014, Robert Fourer, Horand Gassmann, Jun Ma, Kipp Martin,
 * Northwestern University, and the University of Chicago.
 * All Rights Reserved.
 * This software is licensed under the Eclipse Public License. 
 * Please see the accompanying LICENSE file in root directory for terms.
 * 
 * Like the grammar rules in OSParseosil.y, this file is maintained in several pieces 
 * in order to avoid duplication when parsing elements of auxiliary schemas,
 * such as OSgL, OSnL, etc. This is the first part of OSparseosil.l.
 *
 * IMPORTANT! Convention regarding common patterns, such as "name", etc.:
 * Commonly occuring patterns must be kept in one place in order to avoid ambiguity in the parser.
 * Maintenance is easier if they are placed into the OSgL section. At any rate, it is important
 * to place temporary data into the correct parser data object.
 */
%{ 

#define OSILPARSERDEBUG

#ifdef OSILPARSERDEBUG
	#define YY_PRINT  printf("matched %i characters: %s\n", yyleng, yytext);
#else     
	#define YY_PRINT;
#endif

#include <iostream>
#include <sstream>  

#include "OSConfig.h"
#include "OSDataStructures.h"
#include "OSErrorClass.h"
#include "OSMathUtil.h"
#include "OSiLParserData.h"
#include "OSParseosil.tab.hpp"
#include "OSInstance.h"
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

%option prefix="osil"
%option noyywrap
%option reentrant
%option bison-bridge
%option bison-locations
%option yylineno
%option nounput
%option debug

%x osilattributetext
%x doublequoteattributetext
%x singlequoteattributetext
%x startelement
%x elementtext
%x itemtext
%x comment
%x xmldeclaration

%{
#define YY_EXTRA_TYPE OSiLParserData*
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

({xmlwhitespace}+numberOfVariables{equality}) {YY_PRINT; return(NUMBEROFVARIABLESATT);}
({xmlwhitespace}+numberOfConstraints{equality}) {YY_PRINT; return(NUMBEROFCONSTRAINTSATT);}
({xmlwhitespace}+numberOfObjectives{equality}) {YY_PRINT; return(NUMBEROFOBJECTIVESATT);}
({xmlwhitespace}+numberOfQuadraticTerms{equality}) {YY_PRINT; return(NUMBEROFQTERMSATT);}
({xmlwhitespace}+numberOfStages{equality}) {YY_PRINT; return(NUMBEROFSTAGESATT);}
({xmlwhitespace}+numberOfMatrices{equality}) {YY_PRINT; return(NUMBEROFMATRICESATT);}
({xmlwhitespace}+numberOfCones{equality}) {YY_PRINT; return(NUMBEROFCONESATT);}
({xmlwhitespace}+numberOfMatrixVar{equality}) {YY_PRINT; return(NUMBEROFMATRIXVARATT);}
({xmlwhitespace}+numberOfMatrixObj{equality}) {YY_PRINT; return(NUMBEROFMATRIXOBJATT);}
({xmlwhitespace}+numberOfMatrixCon{equality}) {YY_PRINT; return(NUMBEROFMATRIXCONATT);}

({xmlwhitespace}+idxOne{equality}) {YY_PRINT;   return(IDXONEATT);}
({xmlwhitespace}+idxTwo{equality}) {YY_PRINT;   return(IDXTWOATT);}
({xmlwhitespace}+startIdx{equality}) {YY_PRINT; return(STARTIDXATT);}
({xmlwhitespace}+horizon{equality}) {YY_PRINT; return(HORIZONATT);}
({xmlwhitespace}+start{equality}) {YY_PRINT; return(STARTATT);}
({xmlwhitespace}+value{equality}) {YY_PRINT;  return(VALUEATT);}

({xmlwhitespace}+matrixIdx{equality}) {YY_PRINT;  return(MATRIXIDXATT);}
({xmlwhitespace}+lbMatrixIdx{equality}) {YY_PRINT;  return(LBMATRIXIDXATT);}
({xmlwhitespace}+lbConeIdx{equality}) {YY_PRINT;  return(LBCONEIDXATT);}
({xmlwhitespace}+ubMatrixIdx{equality}) {YY_PRINT;  return(UBMATRIXIDXATT);}
({xmlwhitespace}+ubConeIdx{equality}) {YY_PRINT;  return(UBCONEIDXATT);}
({xmlwhitespace}+templateMatrixIdx{equality}) {YY_PRINT;  return(TEMPLATEMATRIXIDXATT);}
({xmlwhitespace}+referenceMatrixIdx{equality}) {YY_PRINT;  return(REFERENCEMATRIXIDXATT);}
({xmlwhitespace}+varReferenceMatrixIdx{equality}) {YY_PRINT;  return(VARREFERENCEMATRIXIDXATT);}
({xmlwhitespace}+objReferenceMatrixIdx{equality}) {YY_PRINT;  return(OBJREFERENCEMATRIXIDXATT);}
({xmlwhitespace}+conReferenceMatrixIdx{equality}) {YY_PRINT;  return(CONREFERENCEMATRIXIDXATT);}

({xmlwhitespace}+orderConeIdx{equality}) {YY_PRINT;  return(ORDERCONEIDXATT);}
({xmlwhitespace}+constantMatrixIdx{equality}) {YY_PRINT;  return(CONSTANTMATRIXIDXATT);}

({xmlwhitespace}+normScaleFactor{equality}) {YY_PRINT;  return(NORMSCALEFACTORATT);}
({xmlwhitespace}+distortionMatrixIdx{equality}) {YY_PRINT;  return(DISTORTIONMATRIXIDXATT);}
({xmlwhitespace}+axisDirection{equality}) {YY_PRINT;  return(AXISDIRECTIONATT);}
({xmlwhitespace}+firstAxisDirection{equality}) {YY_PRINT;  return(FIRSTAXISDIRECTIONATT);}
({xmlwhitespace}+secondAxisDirection{equality}) {YY_PRINT;  return(SECONDAXISDIRECTIONATT);}


 /* attributes returning strings (that are potentially empty)*/

({xmlwhitespace}+id{equality}\"\") {YY_PRINT; return(EMPTYIDATT);}
({xmlwhitespace}+id{equality}\'\') {YY_PRINT; return(EMPTYIDATT);}
({xmlwhitespace}+id{equality}\") {YY_PRINT; BEGIN doublequoteattributetext; return(IDATT);}
({xmlwhitespace}+id{equality}\') {YY_PRINT; BEGIN singlequoteattributetext; return(IDATT);}
({xmlwhitespace}+varType{equality}\") {YY_PRINT; BEGIN doublequoteattributetext; return(VARTYPEATT);}
({xmlwhitespace}+varType{equality}\') {YY_PRINT; BEGIN singlequoteattributetext; return(VARTYPEATT);}


({xmlwhitespace}+semidefiniteness{equality}\"\") {YY_PRINT; return(EMPTYSEMIDEFINITENESSATT);}
({xmlwhitespace}+semidefiniteness{equality}\'\') {YY_PRINT; return(EMPTYSEMIDEFINITENESSATT);}
({xmlwhitespace}+semidefiniteness{equality}\") {YY_PRINT; BEGIN doublequoteattributetext; return(SEMIDEFINITENESSATT);}
({xmlwhitespace}+semidefiniteness{equality}\') {YY_PRINT; BEGIN singlequoteattributetext; return(SEMIDEFINITENESSATT);}


 /* patterns for <quadraticCoefficients> */
{xmlwhitespace}*\<\/osil{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(OSILEND);}
{xmlwhitespace}*\<\/instanceData{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(INSTANCEDATAEND);}
{xmlwhitespace}*\<instanceData{xmlwhitespace}*\/\>{xmlwhitespace}* {YY_PRINT; return(INSTANCEDATASTARTEND);}
{xmlwhitespace}*\<quadraticCoefficients {YY_PRINT; return(QUADRATICCOEFFICIENTSSTART);}
{xmlwhitespace}*\<\/quadraticCoefficients{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(QUADRATICCOEFFICIENTSEND);}
{xmlwhitespace}*\<qTerm {YY_PRINT; return(QTERMSTART);}
{xmlwhitespace}*\<\/qTerm{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(QTERMEND);}

 /* patterns for <matrices> and <cones> */
{xmlwhitespace}*\<matrices {YY_PRINT;  return(MATRICESSTART);}
{xmlwhitespace}*\<\/matrices{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT;  return(MATRICESEND);}
{xmlwhitespace}*\<cones {YY_PRINT;  return(CONESSTART);}
{xmlwhitespace}*\<\/cones{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT;  return(CONESEND);}

{xmlwhitespace}*\<nonnegativeCone {YY_PRINT;  return(NONNEGATIVECONESTART);}
{xmlwhitespace}*\<\/nonnegativeCone{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT;  return(NONNEGATIVECONEEND);}
{xmlwhitespace}*\<nonpositiveCone {YY_PRINT;  return(NONPOSITIVECONESTART);}
{xmlwhitespace}*\<\/nonpositiveCone{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT;  return(NONPOSITIVECONEEND);}
{xmlwhitespace}*\<generalOrthantCone {YY_PRINT;  return(ORTHANTCONESTART);}
{xmlwhitespace}*\<\/generalOrthantCone{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT;  return(ORTHANTCONEEND);}
{xmlwhitespace}*\<polyhedralCone {YY_PRINT;  return(POLYHEDRALCONESTART);}
{xmlwhitespace}*\<\/polyhedralCone{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT;  return(POLYHEDRALCONEEND);}
{xmlwhitespace}*\<quadraticCone {YY_PRINT;  return(QUADRATICCONESTART);}
{xmlwhitespace}*\<\/quadraticCone{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT;  return(QUADRATICCONEEND);}
{xmlwhitespace}*\<rotatedQuadraticCone {YY_PRINT;  return(ROTATEDQUADRATICCONESTART);}
{xmlwhitespace}*\<\/rotatedQuadraticCone{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT;  return(ROTATEDQUADRATICCONEEND);}
{xmlwhitespace}*\<semidefiniteCone {YY_PRINT;  return(SEMIDEFINITECONESTART);}
{xmlwhitespace}*\<\/semidefiniteCone{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT;  return(SEMIDEFINITECONEEND);}
{xmlwhitespace}*\<productCone {YY_PRINT;  return(PRODUCTCONESTART);}
{xmlwhitespace}*\<\/productCone{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT;  return(PRODUCTCONEEND);}
{xmlwhitespace}*\<intersectionCone {YY_PRINT;  return(INTERSECTIONCONESTART);}
{xmlwhitespace}*\<\/intersectionCone{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT;  return(INTERSECTIONCONEEND);}
{xmlwhitespace}*\<dualCone {YY_PRINT;  return(DUALCONESTART);}
{xmlwhitespace}*\<\/dualCone{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT;  return(DUALCONEEND);}
{xmlwhitespace}*\<polarCone {YY_PRINT;  return(POLARCONESTART);}
{xmlwhitespace}*\<\/polarCone{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT;  return(POLARCONEEND);}
{xmlwhitespace}*\<direction {YY_PRINT;  return(DIRECTIONSTART);}
{xmlwhitespace}*\<\/direction{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT;  return(DIRECTIONEND);}
{xmlwhitespace}*\<factors {YY_PRINT;  return(FACTORSSTART);}
{xmlwhitespace}*\<\/factors{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT;  return(FACTORSEND);}
{xmlwhitespace}*\<components {YY_PRINT;  return(COMPONENTSSTART);}
{xmlwhitespace}*\<\/components{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT;  return(COMPONENTSEND);}

 /* patterns for <matrixProgramming> */
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

 /* patterns for <timeDomain> element */
{xmlwhitespace}*\<timeDomain {YY_PRINT; return(TIMEDOMAINSTART);}
{xmlwhitespace}*\<\/timeDomain{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(TIMEDOMAINEND);}
{xmlwhitespace}*\<stages {YY_PRINT; return(STAGESSTART);}
{xmlwhitespace}*\<\/stages{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(STAGESEND);}
{xmlwhitespace}*\<stage {YY_PRINT; return(STAGESTART);}
{xmlwhitespace}*\<\/stage{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(STAGEEND);}
{xmlwhitespace}*\<variables {YY_PRINT; return(VARIABLESSTART);}
{xmlwhitespace}*\<\/variables{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(VARIABLESEND);}
{xmlwhitespace}*\<constraints {YY_PRINT; return(CONSTRAINTSSTART);}
{xmlwhitespace}*\<\/constraints{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(CONSTRAINTSEND);}
{xmlwhitespace}*\<objectives {YY_PRINT; return(OBJECTIVESSTART);}
{xmlwhitespace}*\<\/objectives{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(OBJECTIVESEND);}
{xmlwhitespace}*\<var {YY_PRINT; return(VARSTART);}
{xmlwhitespace}*\<\/var{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(VAREND);}
{xmlwhitespace}*\<con {YY_PRINT; return(CONSTART);}
{xmlwhitespace}*\<\/con{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(CONEND);}
{xmlwhitespace}*\<obj {YY_PRINT; return(OBJSTART);}
{xmlwhitespace}*\<\/obj{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(OBJEND);}
{xmlwhitespace}*\<interval {YY_PRINT; return(INTERVALSTART);}
{xmlwhitespace}*\<\/interval{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(INTERVALEND);}

 /* patterns for <parametersAndStochasticElements> */
 /*
{xmlwhitespace}*\<parametersAndStochasticElements {YY_PRINT; return(PARAMETERSSTART);}
{xmlwhitespace}*\<\/parametersAndStochasticElements{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(PARAMETERSEND);}
{xmlwhitespace}*\<param {YY_PRINT; return(PARAMSTART);}
{xmlwhitespace}*\<\/param{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(PARAMEND);}
*/


 /* include file OSParseosgl.l.patterns --- patterns for OSgL schema elements */

{xmlwhitespace}*\<base64BinaryData {YY_PRINT; return(BASE64START);}
{xmlwhitespace}*\<\/base64BinaryData{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT; return(BASE64END);}
{xmlwhitespace}*\<el {YY_PRINT;  return(ELSTART);}
{xmlwhitespace}*\<\/el{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT;  return(ELEND);}


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

({xmlwhitespace}+numberOfEl{equality}) {YY_PRINT; return(NUMBEROFELATT);}
({xmlwhitespace}+numberOfRows{equality}) {YY_PRINT; return(NUMBEROFROWSATT);}
({xmlwhitespace}+numberOfColumns{equality}) {YY_PRINT; return(NUMBEROFCOLUMNSATT);}
({xmlwhitespace}+numberOfBlocks{equality}) {YY_PRINT; return(NUMBEROFBLOCKSATT);}
({xmlwhitespace}+numberOfValues{equality}) {YY_PRINT; return(NUMBEROFVALUESATT);}
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

({xmlwhitespace}+idx{equality})  {YY_PRINT;  return(IDXATT);}
({xmlwhitespace}+incr{equality}) {YY_PRINT; return(INCRATT);}
({xmlwhitespace}+mult{equality}) {YY_PRINT; return(MULTATT);}
({xmlwhitespace}+coef{equality}) {YY_PRINT; return(COEFATT);}


 /* attributes returning strings (that are potentially empty)*/

({xmlwhitespace}+baseTranspose{equality}\"\") {YY_PRINT; return(EMPTYBASETRANSPOSEATT);}
({xmlwhitespace}+baseTranspose{equality}\'\') {YY_PRINT; return(EMPTYBASETRANSPOSEATT);}
({xmlwhitespace}+baseTranspose{equality}\") {YY_PRINT; BEGIN doublequoteattributetext; return(BASETRANSPOSEATT);}
({xmlwhitespace}+baseTranspose{equality}\') {YY_PRINT; BEGIN singlequoteattributetext; return(BASETRANSPOSEATT);}

({xmlwhitespace}+name{equality}\"\") {YY_PRINT; return(EMPTYNAMEATT);}
({xmlwhitespace}+name{equality}\'\') {YY_PRINT; return(EMPTYNAMEATT);}
({xmlwhitespace}+name{equality}\") {YY_PRINT; BEGIN doublequoteattributetext; return(NAMEATT);}
({xmlwhitespace}+name{equality}\') {YY_PRINT; BEGIN singlequoteattributetext; return(NAMEATT);}

({xmlwhitespace}+rowMajor{equality}\"\") {YY_PRINT; return(EMPTYROWMAJORATT);}
({xmlwhitespace}+rowMajor{equality}\'\') {YY_PRINT; return(EMPTYROWMAJORATT);}
({xmlwhitespace}+rowMajor{equality}\") {YY_PRINT; BEGIN doublequoteattributetext; return(ROWMAJORATT);}
({xmlwhitespace}+rowMajor{equality}\') {YY_PRINT; BEGIN singlequoteattributetext; return(ROWMAJORATT);}

({xmlwhitespace}+shape{equality}\"\") {YY_PRINT; return(EMPTYSHAPEATT);}
({xmlwhitespace}+shape{equality}\'\') {YY_PRINT; return(EMPTYSHAPEATT);}
({xmlwhitespace}+shape{equality}\") {YY_PRINT; BEGIN doublequoteattributetext; return(SHAPEATT);}
({xmlwhitespace}+shape{equality}\') {YY_PRINT; BEGIN singlequoteattributetext; return(SHAPEATT);}

({xmlwhitespace}+symmetry{equality}\"\") {YY_PRINT; return(EMPTYSYMMETRYATT);}
({xmlwhitespace}+symmetry{equality}\'\') {YY_PRINT; return(EMPTYSYMMETRYATT);}
({xmlwhitespace}+symmetry{equality}\") {YY_PRINT; BEGIN doublequoteattributetext; return(SYMMETRYATT);}
({xmlwhitespace}+symmetry{equality}\') {YY_PRINT; BEGIN singlequoteattributetext; return(SYMMETRYATT);}

({xmlwhitespace}+type{equality}\"\") {YY_PRINT; return(EMPTYTYPEATT);}
({xmlwhitespace}+type{equality}\'\') {YY_PRINT; return(EMPTYTYPEATT);}
({xmlwhitespace}+type{equality}\") {YY_PRINT; BEGIN doublequoteattributetext; return(TYPEATT);}
({xmlwhitespace}+type{equality}\') {YY_PRINT; BEGIN singlequoteattributetext; return(TYPEATT);}

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
{xmlwhitespace}*\<objReferenceElements {YY_PRINT;  return(OBJREFERENCEELEMENTSSTART);}
{xmlwhitespace}*\<\/objReferenceElements{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT;  return(OBJREFERENCEELEMENTSEND);}
{xmlwhitespace}*\<conReferenceElements {YY_PRINT;  return(CONREFERENCEELEMENTSSTART);}
{xmlwhitespace}*\<\/conReferenceElements{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT;  return(CONREFERENCEELEMENTSEND);}
{xmlwhitespace}*\<linearElements {YY_PRINT;  return(LINEARELEMENTSSTART);}
{xmlwhitespace}*\<\/linearElements{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT;  return(LINEARELEMENTSEND);}
{xmlwhitespace}*\<generalElements {YY_PRINT;  return(GENERALELEMENTSSTART);}
{xmlwhitespace}*\<\/generalElements{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT;  return(GENERALELEMENTSEND);}
{xmlwhitespace}*\<patternElements {YY_PRINT;  return(PATTERNELEMENTSSTART);}
{xmlwhitespace}*\<\/patternElements{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT;  return(PATTERNELEMENTSEND);}
{xmlwhitespace}*\<start {YY_PRINT;  return(STARTVECTORSTART);}

{xmlwhitespace}*\<\/start{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT;  return(STARTVECTOREND);}
{xmlwhitespace}*\<nonzeros {YY_PRINT;  return(NONZEROSSTART);}
{xmlwhitespace}*\<\/nonzeros{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT;  return(NONZEROSEND);}
{xmlwhitespace}*\<indexes {YY_PRINT;  return(INDEXESSTART);}
{xmlwhitespace}*\<\/indexes{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT;  return(INDEXESEND);}
{xmlwhitespace}*\<values {YY_PRINT;  return(VALUESSTART);}
{xmlwhitespace}*\<\/values{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT;  return(VALUESEND);}
{xmlwhitespace}*\<colOffsets {YY_PRINT;  return(COLOFFSETSSTART);}
{xmlwhitespace}*\<\/colOffsets{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT;  return(COLOFFSETSEND);}
{xmlwhitespace}*\<rowOffsets {YY_PRINT;  return(ROWOFFSETSSTART);}
{xmlwhitespace}*\<\/rowOffsets{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT;  return(ROWOFFSETSEND);}
{xmlwhitespace}*\<varIdx {YY_PRINT;  return(VARIDXSTART);}
{xmlwhitespace}*\<\/varIdx{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT;  return(VARIDXEND);}
{xmlwhitespace}*\<transformation {YY_PRINT;  return(TRANSFORMATIONSTART);}
{xmlwhitespace}*\<\/transformation{xmlwhitespace}*\>{xmlwhitespace}* {YY_PRINT;  return(TRANSFORMATIONEND);}

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

({xmlwhitespace}+includeDiagonal{equality}\"\") {YY_PRINT; return(EMPTYINCLUDEDIAGONALATT);}
({xmlwhitespace}+includeDiagonal{equality}\'\') {YY_PRINT; return(EMPTYINCLUDEDIAGONALATT);}
({xmlwhitespace}+includeDiagonal{equality}\") {YY_PRINT; BEGIN doublequoteattributetext; return(INCLUDEDIAGONALATT);}
({xmlwhitespace}+includeDiagonal{equality}\') {YY_PRINT; BEGIN singlequoteattributetext; return(INCLUDEDIAGONALATT);}

 /* last section of OSParseosil.l */

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

<doublequoteattributetext>[^\"]* {YY_PRINT;  BEGIN 0; yylval->sval = strdup(yytext); return(ATTRIBUTETEXT);}
<singlequoteattributetext>[^\']* {YY_PRINT;  BEGIN 0; yylval->sval = strdup(yytext); return(ATTRIBUTETEXT);}

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

