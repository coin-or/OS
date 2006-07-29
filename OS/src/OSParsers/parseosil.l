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
#include <ctype.h>
#include <Base64.h>
#include "ErrorClass.h"
#include "parseosil.tab.hpp"
#include <math.h>
#ifdef PARSERDEBUG
	#define YY_PRINT  printf("%s", osiltext);
#else     
	#define YY_PRINT ;
#endif

extern OSInstance* osinstance;
YY_BUFFER_STATE current_buf;

//
//
// the global variables for parsing
clock_t start, finish;
double duration;
double atofmod(char *ch);
int atoimod(char *ch);
bool isnewline(char c);
char *ch = NULL;
bool parseVariables();
bool parseObjectives();
bool parseObjCoef( int objcount);
bool parseConstraints();
bool parseLinearConstraintCoefficients();
bool parseStart();
bool parseRowIdx();
bool parseColIdx();
bool parseValue();
char *parseBase64(int *dataSize );


#define GAIL printf("GAIL ANN HONDA\n")

#define	ISWHITESPACE( char_) ((char_) == ' ' || \
                     (char_) == '\t' ||  (char_) == '\r')

#define	ISDIGIT(_c) ((_c) >= '0' && (_c) <= '9')

#define GETATTRIBUTETEXT  	\
	for(; ISWHITESPACE( *ch) || isnewline( *ch); ch++ ) ; \
	if( *ch != '=') {osiltext = &ch[0]; osilerror("found an attribute not defined"); }  \
	ch++; \
	for(; ISWHITESPACE( *ch) || isnewline( *ch); ch++ ) ;	\
	if(*ch != '\"'  && *ch != '\"') {osiltext = &ch[0]; osilerror("missing quote on attribute"); } \
	ch++; \
	for(; ISWHITESPACE( *ch) || isnewline( *ch); ch++ ) ; \
	attText = &*ch; \
	for( ; *ch != '\"' &&  *ch != '\''; ch++); \
	*ch = '\0'; 
	
#define ECHOCHECK \
	GAIL; \
	printf("%c", ch[-2]); \
	printf("%c", ch[-1]); \
	printf("%c", ch[0]); \
	printf("%c", ch[1]); \
	printf("%c", ch[2]); \
	printf("%c", ch[3]); \
	printf("%c", ch[4]); \
	printf("%c", ch[5]); \
	printf("%c \n", ch[6]); \
	GAIL;
					 
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
{xmlwhitespace}*\<instanceData{xmlwhitespace}*\>{xmlwhitespace}* {
	//
	int k = strlen(current_buf->yy_buf_pos);
	//printf("k is equal to   %d\n", k);
	ch = &current_buf->yy_ch_buf[k+ 1];
	//ch = current_buf->yy_buf_pos;
	osiltext = &ch[ 0];
	//printf("starting INSTANCE DATA:\n %s\n", ch);
	parseVariables();
	parseObjectives(); 
	parseConstraints(); 
	parseLinearConstraintCoefficients();
	current_buf->yy_ch_buf = ch;
	//printf("testing \n %s\n", current_buf->yy_ch_buf);
	//osil_delete_buffer( current_buf);
	osil_scan_buffer(ch , strlen(  ch) + 2);		
	return(INSTANCEDATASTART);
	//
}

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
 
<elementtext>([^<])* {YY_PRINT;  BEGIN 0; osillval.sval = strdup(osiltext);    return(ELEMENTTEXT);}
<attributetext>([^\"\'])* {YY_PRINT;  BEGIN 0; osillval.sval = strdup(osiltext); return(ATTRIBUTETEXT);}
<osilattributetext>([^>])* {YY_PRINT;  BEGIN 0; osillval.sval = strdup(osiltext); return(OSILATTRIBUTETEXT);}

. {YY_PRINT;  osilerror( "ecountered a spurious character in the lexer");   }

%%


bool isnewline(char c){
	if(c != '\n') return false;
	osillineno++;
	return true;
}//end isnewline()

bool parseVariables(){
	start = clock(); 
	char *c_numberOfVariables = "numberOfVariables";
	char *startVariables = "variables";
	char *endVariables = "</variables";
	char *startVar = "<var";
	char *endVar = "</var";
	// the attributes
	char *attText = NULL;
	char *name = "name";
	char *initString = "initString";
	char *type = "type";
	char *mult = "mult";
	// others
	int i;
	int varcount = 0;
	int numberOfVariables = 0;
// variable attribute boolean variables
	bool varlbattON  = false;
	bool varubattON = false ;
	bool vartypeattON  = false;
	bool varnameattON = false ;
	bool varinitattON = false ;
	bool varinitStringattON = false ;
	bool varmultattON = false;
	bool foundVar = false;
	//
	// start parsing
	// the way flex works is that the ch should be pointing to variables
	for(i = 0; startVariables[i]  == *ch; i++, ch++);
	if(i != 9) {osiltext = &ch[0]; osilerror("incorrect <variables tag>");}
	// find numberOfVariables attribute
	// eat the white space
	for( ; ISWHITESPACE( *ch) || isnewline( *ch); ch++ ) ;
	for(i = 0; c_numberOfVariables[i]  == *ch; i++, ch++);
	if(i != 17) {osiltext = &ch[0]; osilerror("incorrect numberOfVariables attribute in <variables tag>");}	
	// buf_index should be pointing to the first character after numberOfVariables
	GETATTRIBUTETEXT;
	ch++;
	numberOfVariables = atoimod( attText);
	osinstance->instanceData->variables->numberOfVariables = numberOfVariables;
	osinstance->instanceData->variables->var = new Variable*[ numberOfVariables];
	for(i = 0; i < numberOfVariables; i++){
		osinstance->instanceData->variables->var[ i] = new Variable();
	} 
	// get rid of white space after the numberOfVariables element
	for( ; ISWHITESPACE( *ch) || isnewline( *ch); ch++ )
	// since there must be at least one variable,  this element must end with > 
	// better have an > sign or not valid
	if(*ch != '>' ) {osiltext = &ch[0]; osilerror("variables element does not have a proper closing >");}
	ch++;
	// get rid of white space
	for( ; ISWHITESPACE( *ch) || isnewline( *ch); ch++ ) ;
	// now loop over the var elements, there must be at least one var element
	for(i = 0; startVar[i]  == *ch; i++, ch++);
	if(i ==  4) foundVar = true;
		else {osiltext = &ch[0]; osilerror("there must be at least one <var> element");}
	while(foundVar){
		varlbattON  = false;
		varubattON = false ;
		vartypeattON  = false;
		varnameattON = false ;
		varinitattON = false ;
		varinitStringattON = false ;
		varmultattON = false;
		foundVar = false;
		// assume we are pointing to the first character after the r in <var
		// it should be whitespace
		for( ; ISWHITESPACE( *ch) || isnewline( *ch); ch++ );
		while(*ch != '/' && *ch != '>'){
			switch (*ch) {
			case 'n':
				for(i = 0; name[i]  == *ch; i++, ch++);
				if( i != 4 ) {osiltext = &ch[0]; osilerror("error in variables name attribute");}
				if(varnameattON == true) {osiltext = &ch[0]; osilerror("error too many variable name attributes");}
				varnameattON == true;
				GETATTRIBUTETEXT;
				osinstance->instanceData->variables->var[varcount]->name=attText;
				//printf("ATTRIBUTE = %s\n", attText);
				break;
			case 'i':
				for(i = 0; initString[i]  == *ch; i++, ch++);
				// if i < 4 there is an error
				// if i = 4 we matched init
				// if i = 10 we matched initString
				if( (i != 4)  && (i != 10)) {osiltext = &ch[0]; osilerror("error in variables init or initString attribute");}
				if(i == 4){
					if(varinitattON == true) {osiltext = &ch[0]; osilerror("error too many variable init attributes");}
					varinitattON = true;
					GETATTRIBUTETEXT;
					//printf("ATTRIBUTE = %s\n", attText);
					osinstance->instanceData->variables->var[varcount]->init=atofmod(attText);
				}
				else{
					if(varinitStringattON == true) {osiltext = &ch[0]; osilerror("error too many variable initString attributes");}
					varinitStringattON = true;
					GETATTRIBUTETEXT;
					//printf("ATTRIBUTE = %s\n", attText);
					osinstance->instanceData->variables->var[varcount]->initString=attText;
				}
				break;
			case 't':
				for(i = 0; type[i]  == *ch; i++, ch++);
				if(i != 4) {osiltext = &ch[0]; osilerror("error in variables type attribute");}
				if(vartypeattON == true) {osiltext = &ch[0]; osilerror("error too many variable type attributes");}
				vartypeattON = true;
				GETATTRIBUTETEXT;
				if( strchr("CBIS", attText[0]) == NULL ) {osiltext = &ch[0]; osilerror("variable type not C,B,I, or S");}
				osinstance->instanceData->variables->var[varcount]->type = attText[0];
				break;
			case 'l':
				ch++;
				if(*ch++ != 'b') {osiltext = &ch[0]; osilerror("error in variables lower bound attribute");}
				if(varlbattON == true) {osiltext = &ch[0]; osilerror("error too many variable lb attributes");}
				varlbattON = true;
				GETATTRIBUTETEXT;
				osinstance->instanceData->variables->var[varcount]->lb = atofmod(attText);
				//printf("ATTRIBUTE = %s\n", attText);
				break;
			case 'u':
				ch++;
				if(*ch++ != 'b') {osiltext = &ch[0]; osilerror("error in variables upper bound attribute");}
				if(varubattON == true) {osiltext = &ch[0]; osilerror("error too many variable ub attributes");}
				varubattON = true;
				GETATTRIBUTETEXT;
				osinstance->instanceData->variables->var[varcount]->ub = atofmod(attText);
				//printf("ATTRIBUTE = %s\n", attText);
				break;
			case 'm':
				for(i = 0; mult[i]  == *ch; i++, ch++);
				if(i != 4) {osiltext = &ch[0]; osilerror("error in variables mult attribute");}
				if(varmultattON == true) {osiltext = &ch[0]; osilerror("error too many variable mult attributes");}
				varmultattON = true;
				GETATTRIBUTETEXT;
				//printf("ATTRIBUTE = %s\n", attText);
				break;
			case ' ':
				break;
			case '\n':
				osillineno++;
				break;
			case '\t':
				break;
			case '\r':
				break;
			default:
				{osiltext = &ch[0]; osilerror("invalid attribute character");}
				break;
			}
			ch++;
		}
		//
		// assume all the attributes have been processed
		// must have either /> or > and then whitespace and </var whitespace>
		if( *ch != '/' && *ch != '>') {osiltext = &ch[0]; osilerror("incorrect end of <var> element");}
		if(*ch == '/'){
			ch++;
			if(*ch != '>') {osiltext = &ch[0]; osilerror("incorrect end of <var> element");}
			// get rid of whitespace
			ch++;
			for(; ISWHITESPACE( *ch) || isnewline( *ch); ch++ );
			// either have another <var> element or foundVar = false;
			for(i = 0; startVar[i]  == *ch; i++, ch++);
			if(i == 4) {
				foundVar = true;
			}
			else {
				foundVar = false;
			}
		}
		else{
			// the buf_index is the > at the end of the var element 
			// double check to make sure it really is a >
			if(*ch != '>') {osiltext = &ch[0]; osilerror("improper ending to a <var> element");}
			// look for </var
			// fist get rid of white space
			ch++;
			for(; ISWHITESPACE( *ch) || isnewline( *ch); ch++ );
			// we should be at </var or there is an error
			for(i = 0; endVar[i]  == *ch; i++, ch++);
			if(i != 5) {osiltext = &ch[0]; osilerror("</var> element missing");}
			// burn off the whitespace
			for(; ISWHITESPACE( *ch) || isnewline( *ch); ch++ );
			// better have an > to end </var
			if(*ch++ != '>') {osiltext = &ch[0]; osilerror("</var> element missing >");}
			// look for a new <var> element
			// get rid of whitespace
			ch++;
			for(; ISWHITESPACE( *ch) || isnewline( *ch); ch++ );
			// either have another <var> element or foundVar = false;
			for(i = 0; startVar[i]  == *ch; i++, ch++);
			if(i == 4) {
				foundVar = true;
			}
			else {
				foundVar = false;
			}
		}
		varcount++;
	}
	ch -= i;
	if(varcount > numberOfVariables) {osiltext = &ch[0];  osilerror("attribute numberOfVariables is less than actual number found");}
	if(varcount < numberOfVariables) {osiltext = &ch[0]; osilerror("attribute numberOfVariables is greater than actual number found");}
	// get the </variables> tag
	for(i = 0; endVariables[i]  == *ch; i++, ch++);
	if(i != 11) {osiltext = &ch[0];  osilerror("cannot find </varialbes> tag");}
	for(; ISWHITESPACE( *ch) || isnewline( *ch); ch++ );	
	// better have >
	if(*ch != '>') {osiltext = &ch[0];  osilerror("improperly formed </variables> tag");}
	ch++;
	finish = clock();
	duration = (double) (finish - start) / CLOCKS_PER_SEC; 
	printf("TIME TO PARSE VARIABLES = %f\n", duration);
	return true;
}//end parseVariables


bool parseObjectives(){
	start = clock();
	char *c_numberOfObjectives = "numberOfObjectives";
	char *startObjectives = "<objectives";
	char *endObjectives = "</objectives";
	char *startObj = "<obj";
	char *endObj = "</obj";
	// attributes
	char *attText = NULL;
	char *constant = "constant";
	char *maxOrMin = "maxOrMin";
	char *numberOfObjCoef = "numberOfObjCoeff";
	char *weight = "weight";
	char *name = "name";
	char *mult = "mult";
	// others
	int i;
	// objective function attribute boolean variables
	bool objmaxOrMinattON = false;
	bool objnameattON = false;
	bool objconstantattON = false;
	bool objweightattON = false;
	bool objmultattON = false;
	bool objnumberOfObjCoefattON = false;
	int objcount = 0;
	int numberOfObjectives;
	bool foundObj;
	// start parsing
	// burn white space
	for( ; ISWHITESPACE( *ch) || isnewline( *ch); ch++ ) ;
	// if, present we should be pointing to <objectives element if there -- it is not required
	for(i = 0; startObjectives[i]  == *ch; i++, ch++);
	if(i != 11) {
		//reset ch
		ch -= i;
		return false;
	}
	// find numberOfObjectives attribute -- it is valid for this attribute to be missing. If so
	// assume it is	1 in 
	// eat the white space
	for( ; ISWHITESPACE( *ch) || isnewline( *ch); ch++ ) ;
	// we just ate the white space. If numberOfObjectives is missing we should have a  > char
	if(*ch == '>'){
		numberOfObjectives = 1;
		ch++;
	}
	else{
		for(i = 0; c_numberOfObjectives[i]  == *ch; i++, ch++);
		if(i != 18) {osiltext = &ch[0]; osilerror("incorrect numberOfObjectives attribute in <objectives> tag");}	
		GETATTRIBUTETEXT;
		numberOfObjectives = atoimod( attText);
		ch++;
		// get rid of white space after the numberOfObjectives attribute
		for( ; ISWHITESPACE( *ch) || isnewline( *ch); ch++ ) ;
		// we should have either an />  OR an >
		if(*ch == '/'){
			ch++;
			if( *ch++ != '>') {osiltext = &ch[0]; osilerror("the objectives element does not have a proper closing"); }
			else{
				if(numberOfObjectives > 0){osiltext = &ch[0];  osilerror("numberOfObjectives positive but there are no objectives");}
				return false;
			}
		}
		//  we better have an > 
		if( *ch++ != '>') {osiltext = &ch[0]; osilerror("the objectives element does not have a proper closing");} 
	}
	osinstance->instanceData->objectives->numberOfObjectives = numberOfObjectives;
	osinstance->instanceData->objectives->obj = new Objective*[ numberOfObjectives];
	for(i = 0; i < numberOfObjectives; i++){
		osinstance->instanceData->objectives->obj[ i] = new Objective();
	} 	
	// get rid of white space after the <objectives> element
	for( ; ISWHITESPACE( *ch) || isnewline( *ch); ch++ ) ;
	// now loop over the obj elements, there must be at least one con element
	for(i = 0; startObj[ i] == *ch; i++, ch++);
	if( i == 4) foundObj = true;
		else {osiltext = &ch[0]; osilerror("there must be at least one <obj> element");}
	start = clock();	
	while(foundObj){
		objmaxOrMinattON = false;
		objnameattON = false;
		objconstantattON = false;
		objweightattON = false;
		objmultattON = false;
		objnumberOfObjCoefattON = false;
		// assume we are pointing to the first character after the r in <obj
		// it should be a space so let's increment ch
		ch++;
		while(*ch != '/' && *ch != '>'){
			switch (*ch) {
			case 'n':
				if( *(ch+1) == 'u'){
					for(i = 0; numberOfObjCoef[i]  == *ch; i++, ch++);
					if( (i != 15)  ) {osiltext = &ch[0]; osilerror("error in objective numberOfObjCoef attribute");}
					else{
						if(objnumberOfObjCoefattON == true) {osiltext = &ch[0]; osilerror("error too many obj numberOfObjCoefatt attributes");}
						objnumberOfObjCoefattON = true;
						GETATTRIBUTETEXT;
						//printf("ATTRIBUTE = %s\n", attText);
						osinstance->instanceData->objectives->obj[objcount]->numberOfObjCoef=atoimod(attText);
						osinstance->instanceData->objectives->obj[objcount]->coef = new ObjCoef*[osinstance->instanceData->objectives->obj[ objcount]->numberOfObjCoef];
						for(int i = 0; i < osinstance->instanceData->objectives->obj[ objcount]->numberOfObjCoef; i++)osinstance->instanceData->objectives->obj[objcount]->coef[i] = new ObjCoef();
					}
				}
				else{
					for(i = 0; name[i]  == *ch; i++, ch++);
					if( (i != 4)  ) {osiltext = &ch[0]; osilerror("error in objective name attribute");}
					else{
						if(objnameattON == true) {osiltext = &ch[0]; osilerror("error too many obj name attributes");}
						objnameattON = true;
						GETATTRIBUTETEXT;
						//printf("ATTRIBUTE = %s\n", attText);
						osinstance->instanceData->objectives->obj[objcount]->name=attText;
					}
				}
				break;
			case 'c':
				for(i = 0; constant[i]  == *ch; i++, ch++);
				if( (i != 7)  ) {osiltext = &ch[0]; osilerror("error in objective constant attribute");}
				else{
					if(objconstantattON == true) {osiltext = &ch[0]; osilerror("error too many obj constant attributes");}
					objconstantattON = true;
					GETATTRIBUTETEXT;
					//printf("ATTRIBUTE = %s\n", attText);
					osinstance->instanceData->objectives->obj[objcount]->constant=atofmod(attText);
				}
				break;
			case 'w':
				for(i = 0; weight[i]  == *ch; i++, ch++);
				if( (i != 6)  ) {osiltext = &ch[0]; osilerror("error in objective weight attribute");}
				else{
					if(objweightattON == true) {osiltext = &ch[0]; osilerror("error too many obj weight attributes");}
					objweightattON = true;
					GETATTRIBUTETEXT;
					//printf("ATTRIBUTE = %s\n", attText);
					osinstance->instanceData->objectives->obj[objcount]->weight=atofmod(attText);
				}
				break;
			case 'm':
				if(*(ch+1) == 'a'){
					for(i = 0; maxOrMin[i]  == *ch; i++, ch++);
					if( (i != 8)  ) {osiltext = &ch[0]; osilerror("error in objective maxOrMin attribute");}
					else{
						if(objmaxOrMinattON == true) {osiltext = &ch[0]; osilerror("error too many obj maxOrMin attributes");}
						objmaxOrMinattON = true;
						GETATTRIBUTETEXT;
						//printf("ATTRIBUTE = %s\n", attText);
						if( (strcmp("max", attText) != 0 ) && (strcmp("min", attText) != 0 ) )osilerror("maxOrMin attribute in objective must be a max or min");
						osinstance->instanceData->objectives->obj[objcount]->maxOrMin = attText;
					}
				}
				else{
					for(i = 0; mult[i]  == *ch; i++, ch++);
					if( (i != 4)  ) {osiltext = &ch[0]; osilerror("error in objective mult attribute");}
					else{
						if(objmultattON == true) {osiltext = &ch[0]; osilerror("error too many obj mult attributes");}
						objmultattON = true;
						GETATTRIBUTETEXT;
						//printf("ATTRIBUTE = %s\n", attText);
						//osinstance->instanceData->objectives->obj[objcount]->name=attText;
					}
				}
				break;
			// come back and do multiplicity
			case ' ':
				break;
			case '\n':
				osillineno++;
				break;
			case '\t':
				break;
			case '\r':
				break;
			default:
				osiltext = &ch[0];
				osilerror("invalid attribute character");
				break;
			}
			ch++;
		}
		//
		// assume all the attributes have been processed
		// must have either /> or > and then whitespace and </obj whitespace>
		if( *ch != '/' && *ch != '>') {osiltext = &ch[0];  osilerror("incorrect end of <obj> element");}
		if(*ch == '/'){
			ch++;
			if(*ch != '>') {osiltext = &ch[0]; osilerror("incorrect end of <obj> element");}
			// get rid of whitespace
			ch++;
			for(; ISWHITESPACE( *ch) || isnewline( *ch); ch++ );
			// either have another <obj> element or foundObj = false;
			for(i = 0; startObj[i]  == *ch; i++, ch++);
			if(i == 4) foundObj = true;
				else foundObj = false;
		}
		else{
			// the ch is the > at the end of the obj element
			// double check to make sure it really is a >
			if(*ch != '>') {osiltext = &ch[0]; osilerror("improper ending to a <obj> element");}
			// look for </obj
			// fist get rid of white space
			ch++;
			// first get the <coef> elements
			parseObjCoef( objcount);
			for(; ISWHITESPACE( *ch) || isnewline( *ch); ch++ );
			// we should be at </obj or there is an error
			for(i = 0; endObj[i]  == *ch; i++, ch++);
			if(i != 5) {osiltext = &ch[0]; osilerror("</obj> element missing");}
			// burn off the whitespace
			for(; ISWHITESPACE( *ch) || isnewline( *ch); ch++ );
			// better have an > to end </obj
			if(*ch++ != '>'){osiltext = &ch[0];  osilerror("</obj> element missing >");}
			// look for a new <obj> element
			// get rid of whitespace
			for(; ISWHITESPACE( *ch) || isnewline( *ch); ch++ );
			// either have another <obj> element or foundObj = false;
			for(i = 0; startObj[i]  == *ch; i++, ch++);
			if(i == 4) foundObj = true;
				else foundObj = false;
		}
		objcount++;
	}
	if(objcount > numberOfObjectives) {osiltext = &ch[0]; osilerror("attribute numberOfObjectives is less than actual number found");}
	if(objcount < numberOfObjectives) {osiltext = &ch[0]; osilerror("attribute numberOfObjectives is greater than actual number found");}
	ch -= i;
	// get the </objectives> tag
	for(i = 0; endObjectives[i]  == *ch; i++, ch++);
	if(i != 12) {osiltext = &ch[0]; osilerror( "cannot find </objectives> tag");}
	for(; ISWHITESPACE( *ch) || isnewline( *ch); ch++ );	
	// better have >
	if(*ch != '>') {osiltext = &ch[0]; osilerror("improperly formed </objectives> tag");}	
	ch++;
	finish = clock();
	duration = (double) (finish - start) / CLOCKS_PER_SEC; 
	printf("TIME TO PARSE OBJECTIVES = %f\n", duration);
	return true;
}//end parseObjectives

bool parseConstraints(){
	start = clock();	
	char *c_numberOfConstraints = "numberOfConstraints";
	char *startConstraints = "<constraints";
	char *endConstraints = "</constraints";
	char *startCon = "<con";
	char *endCon = "</con";
	// attributes
	char *attText = NULL;
	char *name = "name";
	char *constant = "constant";
	char *mult = "mult";
	// others
	int i;
	int concount = 0;
	int numberOfConstraints = 0;
	// constraint attribute boolean variables
	bool conlbattON = false ;
	bool conubattON  = false;
	bool connameattON = false;
	bool conconstantattON  = false;
	bool conmultattON = false;
	bool foundCon = false;
	// start parsing
	// burn white space
	for( ; ISWHITESPACE( *ch) || isnewline( *ch); ch++ ) ;
	// if, present we should be pointing to <constraints element if there -- it is not required
	for(i = 0; startConstraints[i]  == *ch; i++, ch++);
	if(i != 12) {
		//reset ch
		ch -= i;
		return false;
	}
	// find numberOfConstraints attribute
	// eat the white space
	for( ; ISWHITESPACE( *ch) || isnewline( *ch); ch++ ) ;
	for(i = 0; c_numberOfConstraints[i]  == *ch; i++, ch++);
	if(i != 19) {osiltext = &ch[0]; osilerror("incorrect numberOfConstraints attribute in <constraints> tag");}	
	// ch should be pointing to the first character after numberOfObjectives
	GETATTRIBUTETEXT;
	ch++;
	numberOfConstraints = atoimod( attText);
	osinstance->instanceData->constraints->numberOfConstraints = numberOfConstraints;
	osinstance->instanceData->constraints->con = new Constraint*[ numberOfConstraints];
	for(i = 0; i < numberOfConstraints; i++){
		osinstance->instanceData->constraints->con[ i] = new Constraint();
	} 
	// get rid of white space after the numberOfConstraints element
	for( ; ISWHITESPACE( *ch) || isnewline( *ch); ch++ ) ;
	// we should have either an />  OR an >
	if(*ch == '/'){
		ch++;
		if( *ch++ != '>') {osiltext = &ch[0]; osilerror("the constraints element does not have a proper closing"); }
		else{
			if(numberOfConstraints > 0) {osiltext = &ch[0];  osilerror("numberOfConstraints positive, but there are no objectives");}
			return false;
		}		
	}
	//  we better have an > 
	if( *ch++ != '>') {osiltext = &ch[0];  osilerror("the constraints element does not have a proper closing");} 
	// get rid of white space after the <constraints> element
	for( ; ISWHITESPACE( *ch) || isnewline( *ch); ch++ ) ;
	// now loop over the con elements, there must be at least one con element
	for(i = 0; startCon[i]  == *ch; i++, ch++);
	if( i == 4) foundCon = true;
		else {osiltext = &ch[0]; osilerror("there must be at least one <con> element");}
	while(foundCon){
		conlbattON = false ;
		conubattON  = false;
		connameattON = false;
		conconstantattON  = false;
		conmultattON = false;
		// assume we are pointing to the first character after the n in <con
		// it should be a space so let's increment ch
		for( ; ISWHITESPACE( *ch) || isnewline( *ch); ch++ );
		while(*ch != '/' && *ch != '>'){
			switch (*ch) {
			case 'n':
				for(i = 0; name[i]  == *ch; i++, ch++);
				if(i != 4) {osiltext = &ch[0]; osilerror("error in constraints name attribute");}
				if(connameattON == true) {osiltext = &ch[0]; osilerror("error too many con name attributes");}
				connameattON = true;
				GETATTRIBUTETEXT;
				osinstance->instanceData->constraints->con[concount]->name=attText;
				//printf("ATTRIBUTE = %s\n", attText);
				break;
			case 'c':
				for(i = 0; constant[i]  == *ch; i++, ch++);
				if( (i != 7)  ) {osiltext = &ch[0]; osilerror("error in constraint constant attribute");}
				if(conconstantattON == true) {osiltext = &ch[0]; osilerror("error too many con constant attributes");}
				conconstantattON = true;
				GETATTRIBUTETEXT;
				//printf("ATTRIBUTE = %s\n", attText);
				osinstance->instanceData->constraints->con[concount]->constant=atofmod(attText);
				break;
			case 'l':
				ch++;
				if(*ch++ != 'b') { osiltext = &ch[0]; osilerror("error in constraint lb attribute");}
				if(conlbattON == true) {osiltext = &ch[0]; osilerror("error too many con lb attributes");}
				conlbattON = true;
				GETATTRIBUTETEXT;
				osinstance->instanceData->constraints->con[concount]->lb = atofmod(attText);
				//printf("ATTRIBUTE = %s\n", attText);
				break;
			case 'u':
				ch++;
				if(*ch++ != 'b') {osiltext = &ch[0]; osilerror("error in constraint ub attribute");}
				if(conubattON == true) {osiltext = &ch[0]; osilerror("error too many con ub attributes");}
				conubattON = true;
				GETATTRIBUTETEXT;
				osinstance->instanceData->constraints->con[concount]->ub = atofmod(attText);
				//printf("ATTRIBUTE = %s\n", attText);
				break;
			case 'm':
				for(i = 0; mult[i]  == *ch; i++, ch++);
				if(i != 4) {osiltext = &ch[0]; osilerror("error in constraints mult attribute");}
				if(conmultattON == true) {osiltext = &ch[0]; osilerror("error too many con mult attributes");}
				conmultattON = true;
				GETATTRIBUTETEXT;
				//printf("ATTRIBUTE = %s\n", attText);
				break;
			case ' ':
				break;
			case '\n':
				osillineno++;
				break;
			case '\t':
				break;
			case '\r':
				break;
			default:
				osiltext = &ch[0];
				osilerror("invalid attribute character");
				break;
			}
			ch++;
		}
		//
		// assume all the attributes have been processed
		// must have either /> or > and then whitespace and </con whitespace>
		if( *ch != '/' && *ch != '>') {osiltext = &ch[0]; osilerror("incorrect end of <con> element");}
		if(*ch == '/'){
			ch++;
			if(*ch != '>') {osiltext = &ch[0]; osilerror("incorrect end of <con> element");}
			// get rid of whitespace
			ch++;
			for(; ISWHITESPACE( *ch) || isnewline( *ch); ch++ );
			// either have another <con> element or foundCon = false;
			for( i = 0; startCon[i]  == *ch; i++, ch++);
			if( i == 4) foundCon = true;
				else foundCon = false;
		}
		else{
			// the ch is the > at the end of the con element 
			// double check to make sure it really is a >
			if(*ch != '>') {osiltext = &ch[0]; osilerror("improper ending to a <obj> element");}
			// look for </con
			// fist get rid of white space
			ch++;
			for(; ISWHITESPACE( *ch) || isnewline( *ch); ch++ );
			// we should be at </con or there is an error
			for(i = 0; endCon[i]  == *ch; i++, ch++);
			if(i != 5) {osiltext = &ch[0]; osilerror("</con> element missing");}
			// burn off the whitespace
			for(; ISWHITESPACE( *ch) || isnewline( *ch); ch++ );
			// better have an > to end </con
			if(*ch++ != '>') {osiltext = &ch[0]; osilerror("</con> element missing >");}
			// look for a new <con> element
			// get rid of whitespace
			ch++;
			for(; ISWHITESPACE( *ch) || isnewline( *ch); ch++ );
			// either have another <con> element or foundVar = false;
			for(i = 0; startCon[i]  == *ch; i++, ch++);
			if(i == 4) foundCon = true;
				else foundCon = false;
		}
		concount++;
	}
	if(concount > numberOfConstraints) {osiltext = &ch[0]; osilerror("attribute numberOfConstraints is less than actual number found");}
	if(concount < numberOfConstraints) {osiltext = &ch[0]; osilerror("attribute numberOfConstraints is greater than actual number found");}
	ch -= i;
	// get the </constraints> tag
	for(i = 0; endConstraints[i]  == *ch; i++, ch++);
	if(i != 13) {osiltext = &ch[0]; osilerror( "cannot find </constraints> tag");}
	for(; ISWHITESPACE( *ch) || isnewline( *ch); ch++ );	
	// better have >
	if(*ch != '>') {osiltext = &ch[0]; osilerror("improperly formed </constraints> tag");	}
	ch++;
	finish = clock();
	duration = (double) (finish - start) / CLOCKS_PER_SEC; 
	printf("TIME TO PARSE CONSTRAINTS = %f\n", duration);
	return true;
}//end parseConstraints

bool parseLinearConstraintCoefficients(){
	start = clock();	
	char *c_numberOfValues = "numberOfValues";
	char *startlinearConstraintCoefficients = "<linearConstraintCoefficients";
	char *endlinearConstraintCoefficients = "</linearConstraintCoefficients";
	// attributes
	char *attText = NULL;
	// others
	int i;
	int numberOfValues;
	// start parsing
	// burn white space
	for( ; ISWHITESPACE( *ch) || isnewline( *ch); ch++ ) ;
	// if, present we should be pointing to <linearConstraintCoefficients element if there -- it is not required
	for(i = 0; startlinearConstraintCoefficients[i]  == *ch; i++, ch++);
	if(i != 29) {
		//reset ch
		ch -= i;
		return false;
	}
	// find numberOfValues attribute
	// eat the white space
	for( ; ISWHITESPACE( *ch) || isnewline( *ch); ch++ ) ;
	for(i = 0; c_numberOfValues[i]  == *ch; i++, ch++);
	if(i != 14) {osiltext = &ch[0]; osilerror("incorrect numberOfValues attribute in <linearConstraintCoefficients> tag");}
	// ch should be pointing to the first character after numberOfObjectives
	GETATTRIBUTETEXT;
	ch++;
	numberOfValues = atoimod( attText);
	osinstance->instanceData->linearConstraintCoefficients->numberOfValues = numberOfValues;
	
	// get rid of white space after the numberOfConstraints element
	for( ; ISWHITESPACE( *ch) || isnewline( *ch); ch++ ) ;
	// we should have either an />  OR an >
	if(*ch == '/'){
		ch++;
		if( *ch++ != '>') {osiltext = &ch[0]; osilerror("the linearConstraintCoefficients element does not have a proper closing");} 
		else{
			if(numberOfValues > 0) {osiltext = &ch[0]; osilerror("numberOfValues positive, but there are no objectives");}
			return false;
		}		
	}
	//  we better have an > 
	if( *ch++ != '>') {osiltext = &ch[0]; osilerror("the <linearConstraintCoefficients> element does not have a proper closing"); }
	// get rid of white space after the <linearConstraintCoefficients> element
	for( ; ISWHITESPACE( *ch) || isnewline( *ch); ch++ ) ;
	parseStart();
	parseColIdx();
	parseRowIdx();
	if( (parseColIdx() == true) && (parseRowIdx() == true) ){osiltext = &ch[0]; osilerror("cannot store by both row and column");}
	parseValue();
	for( ; ISWHITESPACE( *ch) || isnewline( *ch); ch++ ) ;	
	// get the </linearConstraintCoefficients> tag
	for(i = 0; endlinearConstraintCoefficients[ i]  == *ch; i++, ch++);
	if(i != 30) {osiltext = &ch[0]; osilerror( "cannot find </linearConstraintCoefficients> tag");}
	for(; ISWHITESPACE( *ch) || isnewline( *ch); ch++ );	
	// better have >
	if(*ch != '>') {osiltext = &ch[0]; osilerror("improperly formed </linearConstraintCoefficients> tag");}
	ch++;	
	return true;
}//end parseLinearConstraintCoefficients

bool parseStart(){
	start = clock(); 
	char* startStart = "<start";
	char* endStart = "</start";
	char* startEl = "<el";
	char* endEl = "</el";
	int kount = 0;
	char* number = NULL;
	int i;
	bool foundEl = false;
	for( ; ISWHITESPACE( *ch) || isnewline( *ch); ch++ ) ;
	// if, present we should be pointing to <start element 
	for(i = 0; startStart[i]  == *ch; i++, ch++);
	if(i != 6) {
		//reset ch
		ch -= i;
		return false;
	}
	// get rid of white space after <start
	for( ; ISWHITESPACE( *ch) || isnewline( *ch); ch++ ) ;
	// we should have either an >
	if(*ch =! '>') {osiltext = &ch[0]; osilerror("improperly formed <start> element");}
	ch++;
	// get rid of white space
	for( ; ISWHITESPACE( *ch) || isnewline( *ch); ch++ ) ;
	// look for an <el> -- if none present must have b64 data
	for(i = 0; startEl[i]  == *ch; i++, ch++);
	if(i != 3) {
		//reset ch
		ch -= i;
		// call base64 parse here
		int dataSize = 0;
		char* b64string = parseBase64(&dataSize );
		if( b64string == NULL) return false;
		std::string base64decodeddata = Base64::decodeb64( b64string );
		int base64decodeddatalength = base64decodeddata.length();
		int *intvec = NULL;
		osinstance->instanceData->linearConstraintCoefficients->start->el = new int[(base64decodeddatalength/dataSize) ];
		intvec = (int*)&base64decodeddata[0];
		for(i = 0; i < (base64decodeddatalength/dataSize); i++){
			osinstance->instanceData->linearConstraintCoefficients->start->el[ i] = *(intvec++);
		}
	}
	else{
		foundEl = true;
		osinstance->instanceData->linearConstraintCoefficients->start->el = 
		new int[ std::max( osinstance->instanceData->constraints->numberOfConstraints,
		osinstance->instanceData->variables->numberOfVariables) + 1];
		while(foundEl){
			// start eating white space until an '>' is found,
			for(; ISWHITESPACE( *ch) || isnewline( *ch); ch++ );
			if( *ch++ != '>') {osiltext = &ch[0]; osilerror("improperly formed <el> tag");}
			// eat white space again,
			for(; ISWHITESPACE( *ch) || isnewline( *ch); ch++ );
			// okay we better have a number, we will check later
			number = &*ch;
			// find the end of the number, it better be an </el>
			// find </el
			while( *ch != '<' && *ch  != EOF){
				ch++;
			}
			// we better have a <, or not valid
			if(*ch != '<') {osiltext = &ch[0]; osilerror("cannot find an </el>");}
			// terminate the number string
			*ch++ = '\0';
			osinstance->instanceData->linearConstraintCoefficients->start->el[ kount++] = 
			atoimod( number);
			//printf("number = %s\n", number);
			// we are pointing to <, make sure there is /el
			for(i = 1; endEl[ i] == *ch; i++, ch++);
			if(i != 4 ) {osiltext = &ch[0]; osilerror("cannot fine an </el>");}
			// start eating white space until an '>' is found for </el>,
			for(; ISWHITESPACE( *ch) || isnewline( *ch); ch++ ) ;
			if( *ch++ != '>') {osiltext = &ch[0]; osilerror("improperly formed </el> tag");}
			// eat white space again,
			for(; ISWHITESPACE( *ch) || isnewline( *ch); ch++ );
			// either have another <el> element or foundEl = false;
			for(i = 0; startEl[i]  == *ch; i++, ch++);
			if(i == 3) foundEl = true;
			else foundEl = false;
		}
		ch -= i;			
	}
	// get the </start> tag
	for(i = 0; endStart[i]  == *ch; i++, ch++);
	if(i != 7) {osiltext = &ch[0]; osilerror( "cannot find </start> tag");}
	for(; ISWHITESPACE( *ch) || isnewline( *ch); ch++ );	
	// better have >
	if(*ch != '>') {osiltext = &ch[0]; osilerror("improperly formed </start> tag");	}
	ch++;	
	// get the end element
	finish = clock();
	duration = (double) (finish - start) / CLOCKS_PER_SEC; 
	printf("TIME TO PARSE STARTS  = %f\n", duration);
	return true;
}//end parseSart

bool parseRowIdx(){
	start = clock(); 
	char* startRowIdx = "<rowIdx";
	char* endRowIdx = "</rowIdx";
	char* startEl = "<el";
	char* endEl = "</el";
	int kount = 0;
	char* number = NULL;
	int i;
	bool foundEl = false;
	for( ; ISWHITESPACE( *ch) || isnewline( *ch); ch++ ) ;
	// if, present we should be pointing to <rowIdx element 
	for(i = 0; startRowIdx[i]  == *ch; i++, ch++);
	if(i != 7) {
		//reset ch
		ch -= i;
		return false;
	}
	// get rid of white space after <rowIdx
	for( ; ISWHITESPACE( *ch) || isnewline( *ch); ch++ ) ;
	// we should have either an >
	if(*ch =! '>') {osiltext = &ch[0]; osilerror("improperly formed <rowIdx> element");}
	ch++;
	// get rid of white space
	for( ; ISWHITESPACE( *ch) || isnewline( *ch); ch++ ) ;
	// look for an <el> -- if none present must have b64 data
	for(i = 0; startEl[i]  == *ch; i++, ch++);
	if(i != 3) {
		//reset ch
		ch -= i;
		// call base64 parse here
		int dataSize = 0;
		char* b64string = parseBase64(&dataSize );
		if( b64string == NULL) return false;
		std::string base64decodeddata = Base64::decodeb64( b64string );
		int base64decodeddatalength = base64decodeddata.length();
		int *intvec = NULL;
		osinstance->instanceData->linearConstraintCoefficients->rowIdx->el = new int[(base64decodeddatalength/dataSize) ];
		osinstance->instanceData->linearConstraintCoefficients->colIdx->el = NULL;
		intvec = (int*)&base64decodeddata[0];
		for(i = 0; i < (base64decodeddatalength/dataSize); i++){
			osinstance->instanceData->linearConstraintCoefficients->rowIdx->el[ i] = *(intvec++);
			kount++;
		}
	}
	else{
		foundEl = true;
		osinstance->instanceData->linearConstraintCoefficients->rowIdx->el = new int[ osinstance->instanceData->linearConstraintCoefficients->numberOfValues];
		osinstance->instanceData->linearConstraintCoefficients->colIdx->el = NULL;
		while(foundEl){
			// start munging white space until an '>' is found,
			for(; ISWHITESPACE( *ch) || isnewline( *ch); ch++ ) ;
			if( *ch++ != '>') {osiltext = &ch[0]; osilerror("improperly formed <el> tag");}
			// mung white space again,
			for(; ISWHITESPACE( *ch) || isnewline( *ch); ch++ ) ;
			// okay we better have a number, we will check later
			number = &*ch;
			// find the end of the number, it better be an </el>
			// find </el
			while( *ch != '<' && *ch  != EOF){
				ch++;
			}
			// we better have a <, or not valid
			if(*ch != '<') {osiltext = &ch[0];  ;osilerror("cannot find an </el>"); }
			// terminate the number string
			*ch++ = '\0';
			osinstance->instanceData->linearConstraintCoefficients->rowIdx->el[ kount++] = 
			atoimod( number);
			//printf("number = %s\n", number);
			// we are pointing to <, make sure there is /el
			for(i = 1; endEl[ i] == *ch; i++, ch++);
			if(i != 4 ) {osiltext = &ch[0]; osilerror("cannot find an </el>");}
			// start munging white space until an '>' is found for </el>,
			for(; ISWHITESPACE( *ch) || isnewline( *ch); ch++ );
			if( *ch++ != '>') {osiltext = &ch[0]; osilerror("improperly formed </el> tag");}
			// eat white space again,
			for(; ISWHITESPACE( *ch) || isnewline( *ch); ch++ );
			// either have another <el> element or foundEl = false;
			for(i = 0; startEl[i]  == *ch; i++, ch++);
			if(i == 3) foundEl = true;
			else foundEl = false;
		}
		 
		ch -= i;
	}
	// get the </rowIdx> tag
	for(i = 0; endRowIdx[i]  == *ch; i++, ch++);
	if(i != 8) {osiltext = &ch[0]; osilerror( "cannot find </rowIdx> tag");}
	for(; ISWHITESPACE( *ch) || isnewline( *ch); ch++ );	
	// better have >
	if(*ch != '>') {osiltext = &ch[0]; osilerror("improperly formed </rowIdx> tag");}	
	ch++;	
	if(kount > osinstance->instanceData->linearConstraintCoefficients->numberOfValues)osilerror("numberOfLinearCoefficients attribute less than number of row indices found");
	if(kount < osinstance->instanceData->linearConstraintCoefficients->numberOfValues)osilerror("numberOfLinearCoefficients attribute greater than number of row indices found");
	finish = clock();
	duration = (double) (finish - start) / CLOCKS_PER_SEC; 
	printf("TIME TO PARSE ROW INDEXES = %f\n", duration);
 return true;
}//end parseRowIdx


bool parseColIdx(){
	start = clock(); 
	char* startColIdx = "<colIdx";
	char* endColIdx = "</colIdx";
	char* startEl = "<el";
	char* endEl = "</el";
	int kount = 0;
	char* number = NULL;
	int i;
	bool foundEl = false;
	for( ; ISWHITESPACE( *ch) || isnewline( *ch); ch++ ) ;
	// if, present we should be pointing to <colIdx element 
	for(i = 0; startColIdx[i]  == *ch; i++, ch++);
	if(i != 7) {
		//reset ch
		ch -= i;
		return false;
	}
	// get rid of white space after <colIdx
	for( ; ISWHITESPACE( *ch) || isnewline( *ch); ch++ ) ;
	// we should have either an >
	if(*ch =! '>') {osiltext = &ch[0]; osilerror("improperly formed <colIdx> element");}
	ch++;
	// get rid of white space
	for( ; ISWHITESPACE( *ch) || isnewline( *ch); ch++ ) ;
	// look for an <el> -- if none present must have b64 data
	for(i = 0; startEl[i]  == *ch; i++, ch++);
	if(i != 3) {
		//reset ch
		ch -= i;
		// call base64 parse here
		int dataSize = 0;
		char* b64string = parseBase64(&dataSize );
		if( b64string == NULL) return false;
		std::string base64decodeddata = Base64::decodeb64( b64string );
		int base64decodeddatalength = base64decodeddata.length();
		int *intvec = NULL;
		osinstance->instanceData->linearConstraintCoefficients->colIdx->el = new int[(base64decodeddatalength/dataSize) ];
		osinstance->instanceData->linearConstraintCoefficients->rowIdx->el = NULL;
		intvec = (int*)&base64decodeddata[0];
		for(i = 0; i < (base64decodeddatalength/dataSize); i++){
			osinstance->instanceData->linearConstraintCoefficients->colIdx->el[ i] = *(intvec++);
			kount++;
		}
	}
	else{
		foundEl = true;
		osinstance->instanceData->linearConstraintCoefficients->colIdx->el = new int[ osinstance->instanceData->linearConstraintCoefficients->numberOfValues];
		osinstance->instanceData->linearConstraintCoefficients->rowIdx->el = NULL;
		while(foundEl){
			// start eating white space until an '>' is found,
			for(; ISWHITESPACE( *ch) || isnewline( *ch); ch++ ) ;
			if( *ch++ != '>') {osiltext = &ch[0]; osilerror("improperly formed <el> tag");}
			// eat white space again,
			for(; ISWHITESPACE( *ch) || isnewline( *ch); ch++ ) ;
			// okay we better have a number, we will check later
			number = &*ch;
			// find the end of the number, it better be an </el>
			// find </el
			while( *ch != '<' && *ch  != EOF){
				ch++;
			}
			// we better have a <, or not valid
			if(*ch != '<') {osiltext = &ch[0]; osilerror("cannot find an </el>");}
			// terminate the number string
			*ch++ = '\0';
			osinstance->instanceData->linearConstraintCoefficients->colIdx->el[ kount++] = 
			atoimod( number);
			//printf("number = %s\n", number);
			// we are pointing to <, make sure there is /el
			for(i = 1; endEl[ i] == *ch; i++, ch++);
			if( i != 4 ) {osiltext = &ch[0]; osilerror("cannot fine an </el>");}
			// start eating white space until an '>' is found for </el>,
			for(; ISWHITESPACE( *ch) || isnewline( *ch); ch++ );
			if( *ch++ != '>') {osiltext = &ch[0]; osilerror("improperly formed </el> tag");}
			// eat white space again,
			for(; ISWHITESPACE( *ch) || isnewline( *ch); ch++ );
			// either have another <el> element or foundEl = false;
			for(i = 0; startEl[i]  == *ch; i++, ch++);
			if(i == 3) foundEl = true;
			else foundEl = false;
		}
		ch -= i;
	}
	// get the </colIdx> tag
	for(i = 0; endColIdx[i]  == *ch; i++, ch++);
	if(i != 8) {osiltext = &ch[0]; osilerror( "cannot find </rowIdx> tag");}
	for(; ISWHITESPACE( *ch) || isnewline( *ch); ch++ );	
	// better have >
	if(*ch != '>') {osiltext = &ch[0]; osilerror("improperly formed </colIdx> tag");}	
	ch++;	
	if(kount > osinstance->instanceData->linearConstraintCoefficients->numberOfValues) {osiltext = &ch[0]; osilerror("numberOfLinearCoefficients attribute less than number of column indices found");}
	if(kount < osinstance->instanceData->linearConstraintCoefficients->numberOfValues) {osiltext = &ch[0]; osilerror("numberOfLinearCoefficients attribute greater than number of column indices found");}
	finish = clock();
	duration = (double) (finish - start) / CLOCKS_PER_SEC; 
	printf("TIME TO PARSE COLUMN INDEXES = %f\n", duration);
 return true;
}//end parseColIdx


bool parseValue(){
	start = clock(); 
	char* startValue = "<value";
	char* endValue = "</value";
	char* startEl = "<el";
	char* endEl = "</el";
	int kount = 0;
	char* number = NULL;
	int i;
	bool foundEl = false;
	for( ; ISWHITESPACE( *ch) || isnewline( *ch); ch++ ) ;
	// if, present we should be pointing to <rowIdx element 
	for(i = 0; startValue[i]  == *ch; i++, ch++);
	if(i != 6) {
		//reset ch
		ch -= i;
		return false;
	}
	// get rid of white space after <value
	for( ; ISWHITESPACE( *ch) || isnewline( *ch); ch++ ) ;
	// we should have either an >
	if(*ch =! '>') {osiltext = &ch[0]; osilerror("improperly formed <value> element");}
	ch++;
	// get rid of white space
	for( ; ISWHITESPACE( *ch) || isnewline( *ch); ch++ ) ;
	// look for an <el> -- if none present must have b64 data
	for(i = 0; startEl[i]  == *ch; i++, ch++);
	if(i != 3) {
		//reset ch
		ch -= i;
		// call base64 parse here
		int dataSize = 0;
		char* b64string = parseBase64(&dataSize );
		if( b64string == NULL) return false;
		std::string base64decodeddata = Base64::decodeb64( b64string );
		int base64decodeddatalength = base64decodeddata.length();
		double *doublevec = NULL;
		osinstance->instanceData->linearConstraintCoefficients->value->el = new double[(base64decodeddatalength/dataSize) ];
		doublevec = (double*)&base64decodeddata[0];
		for(i = 0; i < (base64decodeddatalength/dataSize); i++){
			osinstance->instanceData->linearConstraintCoefficients->value->el[ i] = *(doublevec++);
			kount++;
		}
	}
	else{
		foundEl = true;
		osinstance->instanceData->linearConstraintCoefficients->value->el = 
			new double[ osinstance->instanceData->linearConstraintCoefficients->numberOfValues];
		while( foundEl){
			// start eat white space until an '>' is found,
			for(; ISWHITESPACE( *ch) || isnewline( *ch); ch++ );
			if( *ch++ != '>') {osiltext = &ch[0]; osilerror("improperly formed <el> tag");}
			// eat white space again,
			for(; ISWHITESPACE( *ch) || isnewline( *ch); ch++ ) ;
			number = &*ch;
			// find the end of the number, it better be an </el>
			// find the < which begins the </el
			while( *ch != '<' && *ch != EOF){
				ch++;
			}
			// we better have a <, or not valid
			if(*ch != '<') {osiltext = &ch[0]; osilerror("cannot find an </el>");}
			// terminate the number string
			*ch++ = '\0';
			osinstance->instanceData->linearConstraintCoefficients->value->el[ kount++] = 
			atofmod( number);
			//printf("number = %s\n", number);
			// we are pointing to <, make sure there is /el
			for(i = 1; endEl[ i] == *ch; i++, ch++);
			if( i != 4 ) {osiltext = &ch[0]; osilerror("cannot fine an </el>");}
			// start eating white space until an '>' is found for </el>,
			for(; ISWHITESPACE( *ch) || isnewline( *ch); ch++ );
			if( *ch++ != '>') {osiltext = &ch[0]; osilerror("improperly formed </el> tag");}
			// eat white space again,
			for(; ISWHITESPACE( *ch) || isnewline( *ch); ch++ );
			// either have another <el> element or foundEl = false;
			for(i = 0; startEl[i]  == *ch; i++, ch++);
			if(i == 3) foundEl = true;
			else foundEl = false;
		}	
		ch -= i;
	}
	// get the </value> tag
	for(i = 0; endValue[i]  == *ch; i++, ch++);
	if(i != 7) osilerror( "cannot find </value> tag");
	for(; ISWHITESPACE( *ch) || isnewline( *ch); ch++ );	
	// better have >
	if(*ch != '>') {osiltext = &ch[0]; osilerror("improperly formed </value> tag");	}
	ch++;	
	
	if(kount < osinstance->instanceData->linearConstraintCoefficients->numberOfValues){osiltext = &ch[0]; osilerror("numberOfLinearCoefficients greater than number of values found");}
	if(kount > osinstance->instanceData->linearConstraintCoefficients->numberOfValues){osiltext = &ch[0]; osilerror("numberOfLinearCoefficients less than the number of values found");}
	
	finish = clock();
	duration = (double) (finish - start) / CLOCKS_PER_SEC; 
	printf("TIME TO PARSE VALUES = %f\n", duration);
	return true;
}//end parseValue

bool parseObjCoef( int objcount){
	char* startCoef = "<coef";
	char* endCoef = "</coef";
	char* c_idx = "idx";
	int kount = 0;
	char* number = NULL;
	char* attText = NULL;
	int i, k;
	int numberOfObjCoef = 0; 
	bool foundCoef = false;
	
	numberOfObjCoef = osinstance->instanceData->objectives->obj[objcount]->numberOfObjCoef;
	if(numberOfObjCoef == 0) return false;
	
	for(k = 0; k < numberOfObjCoef; k++){
		for( ; ISWHITESPACE( *ch) || isnewline( *ch); ch++ ) ;
		// if, present we should be pointing to <coef element 
		for(i = 0; startCoef[i]  == *ch; i++, ch++);
		if(i != 5) {osiltext = &ch[0]; osilerror("improper <coef> element");}
		// get the idx attribute
		
		// find numberOfConstraints attribute
		// eat the white space after <coef
		for( ; ISWHITESPACE( *ch) || isnewline( *ch); ch++ ) ;
		for(i = 0; c_idx[i]  == *ch; i++, ch++);
		if(i != 3) {osiltext = &ch[0]; osilerror("incorrect idx attribute in objective function <idx> tag");}	
		// ch should be pointing to the first character after numberOfObjectives
		GETATTRIBUTETEXT;
		ch++;	
		// eat white space
		for( ; ISWHITESPACE( *ch) || isnewline( *ch); ch++ ) ;
		// if we don't have a > there is an error
		if(*ch++ != '>') {osiltext = &ch[0]; osilerror("incorrect <coef> element")	;}	
		// we should be pointing to first character after <coef>
		number = &*ch;
		// eat characters until we find <
		for(; *ch != '<' && *ch != EOF; ch++); 
		osinstance->instanceData->objectives->obj[objcount]->coef[ k]->idx  = atoimod( attText);
		// we should be pointing to a < in the </coef> tag	
		*ch = '\0';
		osinstance->instanceData->objectives->obj[objcount]->coef[ k]->value  = atofmod( number);
		*ch = '<';
		for(i = 0; endCoef[i]  == *ch; i++, ch++);	
		if(i != 6)  {osiltext = &ch[0]; osilerror("improper </coef> element");}
		// get rid of white space after </coef
		for( ; ISWHITESPACE( *ch) || isnewline( *ch); ch++ ) ;
		// if we don't have a > there is an error
		if(*ch++ != '>') {osiltext = &ch[0]; osilerror("incorrect </coef> element")	;}
	}
	return true;
}//end parseObjCoef

char *parseBase64(int *dataSize ){
	char *sizeOf = "sizeOf";
	//char *numericType = "numericType";
	char *startBase64BinaryData = "<base64BinaryData";
	char *endBase64BinaryData = "</base64BinaryData";
	char *attText;
	char *b64string = NULL;
	int i;
	int endpoint;

	//
	// start parsing
	// the way flex works is that the ch should be pointing to variables
	for(i = 0; startBase64BinaryData[i]  == *ch; i++, ch++);
	if(i != 17) {
		ch -= i;
		return b64string;
	}
	// find sizeOf attribute
	// eat the white space
	for( ; ISWHITESPACE( *ch) || isnewline( *ch); ch++ ) ;
	for(i = 0; sizeOf[i]  == *ch; i++, ch++);
	if(i != 6) {osiltext = &ch[0]; osilerror("incorrect sizeOf attribute in <base64BinaryData> element");}	
	// ch should be pointing to the first character after sizeOf
	GETATTRIBUTETEXT;
	ch++;
	*dataSize = atoimod( attText);
	// since the element must contain b64 data,  this element must end with > 
	// eat the white space
	for( ; ISWHITESPACE( *ch) || isnewline( *ch); ch++ ) ;
	// better have an > sign or not valid
	if(*ch != '>' ) {osiltext = &ch[0]; osilerror("<base64BinaryData> element does not have a proper closing >");}
	ch++;
	// we are now pointing start of the data
	b64string = &*ch;
	// eat characters until we get to the </base64BinaryData element
	for(; *ch != '<' && *ch != EOF; ch++);
	// we should be pointing to </base64BinaryData>
	for(i = 0; endBase64BinaryData[i]  == *ch; i++, ch++);
	if(i != 18) {osiltext = &ch[0];osilerror(" problem with <base64BinaryData> element");}
	ch[ -18] = '\0';
	// burn the white space
	for( ; ISWHITESPACE( *ch) || isnewline( *ch); ch++ ) ;
	// better have an > sign or not valid
	if(*ch != '>' ) {osiltext = &ch[0]; osilerror("</base64BinaryData> element does not have a proper closing >");}
	ch++;
	for( ; ISWHITESPACE( *ch) || isnewline( *ch); ch++ ) ;
	return b64string;
}


char parseErrorDouble[50]  =  "an invalid value for xsd:double  ";
char parseErrorInteger[50] =  "an invalid value for xsd:int  ";


double atofmod(char *number){
	double val, power;
	int i;
	int sign = 1;
	int expsign, exppower, exptest;
	int endWhiteSpace;
	// modidfied atof from Kernighan and Ritchie
	for(i = 0;  ISWHITESPACE( number[ i]) || isnewline( number[ i]) ; i++);
	sign = (number[ i] == '-') ? -1 : 1;
	if (number[ i] == '+' || number[ i] == '-') i++;
	endWhiteSpace = i;
	for(val = 0.0; ISDIGIT( number[ i]); i++){
		val = 10.0 *val + (number[ i] - '0') ;
	}
	if (number[ i] == '.') {
		i++;
		for (power = 1.0; ISDIGIT(number[ i]); i++){
			val = 10.0*val + (number[ i] - '0');
			power *= 10.0;
		}
		val = val/power;
	}
	if(i == endWhiteSpace) {
	// we better have INF or NaN
		switch (number[ i]){
		case 'I':
			i++;
			if(number[ i++] == 'N' && number[i++] == 'F'){
				val = OSINFINITY;
				break;
			}
			else{
				osiltext = number; 
				osilerror( strcat(parseErrorDouble, number));
			}
		case 'N':
			i++;
			if(number[ i-2] != '+' &&  number[ i-2] != '-' && number[ i++] == 'a' && number[i++] == 'N'){
				val = OSNAN;
				break;
			}
			else{
				osiltext = number; 
				osilerror( strcat(parseErrorDouble, number));
			}

		default:
			osiltext = number; 
			osilerror( strcat(parseErrorDouble, number));
			break;
		}
	}
	else{
		if(number[i] == 'e' || number[i] == 'E' ){
			i++;
			// process exponential part of the term
			// we have ([eE][-+]?[0-9]+)?
			// we are not going to process a NAN or INF
			expsign = (number[ i] == '-') ? -1 : 1;
			if (number[ i] == '+' || number[ i] == '-') i++;
			// get the exponent power 
			//
			exptest = i;
			for(exppower = 0 ; ISDIGIT( number[ i]); i++){
				exppower = 10 *exppower + (number[ i] - '0') ;
			}
			if(i == exptest) {osiltext = &number[0]; osilerror( strcat(parseErrorDouble, number));}
			val = val*pow(10, expsign*exppower);
			//printf("number = %f\n", val);
		}
	}
	// if we are here we should having nothing but white space until the end of the number
	for( ; ISWHITESPACE( number[ i]) || isnewline( number[ i]) ; i++);
	if(number[i] == '\0'){
		return sign*val;
	}
	else {osiltext = &number[0]; osilerror( strcat(parseErrorDouble, number));}
}//end atofmod



int atoimod(char *number){
	// modidfied atoi from Kernighan and Ritchie
	int ival, power;
	int i, sign;
	int endWhiteSpace;
	for(i = 0; ISWHITESPACE( number[ i]) || isnewline( number[ i]) ; i++);
	endWhiteSpace = i;
	sign = (number[ i] == '-') ? -1 : 1;
	if (number[ i] == '+' || number[ i] == '-') i++;
	for(ival = 0; ISDIGIT( number[ i]); i++){
		ival = 10*ival + (number[ i] - '0') ;
	}
	if(i == endWhiteSpace) {osiltext = number; osilerror( strcat(parseErrorInteger, number));}
	// if we are here we should having nothing but white space until the end of the number
	for( ; ISWHITESPACE( number[ i]) || isnewline( number[ i]) ; i++);
	if(number[i] == '\0'){
		return sign*ival;
	}
	else {osiltext = number; osilerror(strcat(parseErrorInteger, number));}
}//end atoimod
