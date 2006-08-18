/** @file parseosil.y
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

 
#include <iostream>
#include <sstream>  
#include <time.h>   
#include "lexyaccparser.h"
#include "externalvars.h"
#include "OSInstance.h" 
#include "OSnLNode.h"
#include "ErrorClass.h"
#include "OSParameters.h"
#include "osilparservariables.h"
#include "Base64.h"



//
//
// the global variables for parsing
clock_t start, finish;
double duration;
double atofmod1(char *ch1, char *ch2);
int atoimod1(char *ch1, char *ch2);
// we distinguish a newline from other whitespace
// since we need to know when we hit a new line
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
bool parseInstanceHeader(const char **pchar);
char *parseBase64(int *dataSize );




#define GAIL printf("GAIL ANN HONDA\n")

#define	ISWHITESPACE( char_) ((char_) == ' ' || \
                     (char_) == '\t' ||  (char_) == '\r')

#define	ISDIGIT(_c) ((_c) >= '0' && (_c) <= '9')

#define GETATTRIBUTETEXT  	\
	for(; ISWHITESPACE( *ch) || isnewline( *ch); ch++ ) ; \
	if( *ch != '=') {osiltext = &ch[0]; osilerror("found an attribute not defined"); return false;}  \
	ch++; \
	for(; ISWHITESPACE( *ch) || isnewline( *ch); ch++ ) ;	\
	if(*ch != '\"'  && *ch != '\"') {osiltext = &ch[0]; osilerror("missing quote on attribute"); return false;} \
	ch++; \
	for(; ISWHITESPACE( *ch) || isnewline( *ch); ch++ ) ; \
	attTextStart = ch; \
	for( ; *ch != '\"' &&  *ch != '\''; ch++); \
	numChar = ch - attTextStart; \
	attText = new char[numChar + 1]; \
	for(ki = 0; ki < numChar; ki++) attText[ki] = attTextStart[ ki]; \
	attText[ki] = '\0'; \
	attTextEnd = &attText[ki]; 
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
 

/* %name-prefix="osil" 
this fails on in Mac OS X
*/

%union {
	double dval;
	int ival;
	char* sval;
}



%token QUOTE
%token <sval> ATTRIBUTETEXT 
%token <ival> INTEGER  
%token  <dval> DOUBLE 
%token <sval> ELEMENTTEXT




%token OSILSTART OSILEND NAMESTART NAMEEND DESCRIPTIONSTART DESCRIPTIONEND
%token SOURCESTART SOURCEEND INSTANCEHEADER INSTANCEHEADERSTART INSTANCEHEADEREND
%token INSTANCEDATASTART INSTANCEDATAEND 
%token VALUEATT NUMBEROFNONLINEAREXPRESSIONS
%token IDXONEATT IDXTWOATT COEFATT IDATT 
%token TIMESSTART TIMESEND NUMBERSTART  NUMBEREND
%token NUMBEROFQTERMSATT IDXATT TYPEATT IDATT
%token QTERMSTART QTERMEND QUADRATICCOEFFICIENTSSTART QUADRATICCOEFFICIENTSEND
%token NONLINEAREXPRESSIONSSTART NONLINEAREXPRESSIONSEND NLSTART NLEND
%token TIMESSTART TIMESEND POWERSTART POWEREND PLUSSTART PLUSEND MINUSSTART MINUSEND
%token DIVIDESTART DIVIDEEND LNSTART LNEND SUMSTART SUMEND PRODUCTSTART PRODUCTEND ENDOFELEMENT
%token EXPSTART EXPEND NEGATESTART NEGATEEND IFSTART IFEND
%token GREATERTHAN  OSILATTRIBUTETEXT
%token NAMESTARTANDEND SOURCESTARTANDEND DESCRIPTIONSTARTANDEND
%token VARIABLESTART VARIABLEEND ABSSTART ABSEND MAXSTART MAXEND


      
   
%%



osildoc: quadraticcoefficients  nonlinearExpressions INSTANCEDATAEND  OSILEND;





quadraticcoefficients: 
	| QUADRATICCOEFFICIENTSSTART quadnumberatt qTermlist  QUADRATICCOEFFICIENTSEND
{if(osinstance->instanceData->quadraticCoefficients->numberOfQuadraticTerms > qtermcount ) osilerror("actual number of qterms less than numberOfQuadraticTerms");};
   

quadnumberatt: NUMBEROFQTERMSATT INTEGER quote GREATERTHAN  {
osinstance->instanceData->quadraticCoefficients->numberOfQuadraticTerms = $2;  
if(osinstance->instanceData->quadraticCoefficients->numberOfQuadraticTerms > 0 ) osinstance->instanceData->quadraticCoefficients->qTerm = new QuadraticTerm*[ $2 ];
for(int i = 0; i < $2; i++) osinstance->instanceData->quadraticCoefficients->qTerm[i] = new QuadraticTerm();} ;

qTermlist:  
		| qTermlist qterm ;
		   
qterm: {if(osinstance->instanceData->quadraticCoefficients->numberOfQuadraticTerms <= qtermcount ) osilerror("too many QuadraticTerms");} 
QTERMSTART  anotherqTermATT  qtermend {qtermcount++; 
if(!qtermidxattON)  osilerror("the qTerm attribute idx is required"); 
if(!qtermidxOneattON)  osilerror("the qTerm attribute idxOne is required"); 
if(!qtermidxTwoattON)  osilerror("the qTerm attribute idxTwo is required"); 
qtermidattON = false; 
qtermidxattON = false; 
qtermidxOneattON = false; 
qtermidxTwoattON = false;
qtermcoefattON = false;} ;
				
qtermend:  ENDOFELEMENT
		| GREATERTHAN  QTERMEND;    
	

anotherqTermATT: 
	| anotherqTermATT qtermatt  ;
	


qtermatt:  qtermidatt  quote
			{ if(qtermidattON) osilerror("too many qTerm id attributes"); 
			qtermidattON = true;  }
		| qtermidxOneatt   quote
			{ if(qtermidxOneattON) osilerror("too many qTerm id attributes"); 
			qtermidxOneattON = true;  }
		| qtermidxTwoatt  quote    
			{ if(qtermidxTwoattON) osilerror("too many qTerm id attributes"); 
			qtermidxTwoattON = true;  }
		| qtermcoefatt quote
			{ if(qtermcoefattON) osilerror("too many qTerm id attributes"); 
			qtermcoefattON = true;  }
		| qtermidxatt quote
			{ if(qtermidxattON) osilerror("too many qTerm id attributes"); 
			qtermidxattON = true;  }
		;


qtermidatt: IDATT ATTRIBUTETEXT   {  
osinstance->instanceData->quadraticCoefficients->qTerm[qtermcount]->id = $2;} 
| IDATT;
qtermidxOneatt: IDXONEATT INTEGER   {  
osinstance->instanceData->quadraticCoefficients->qTerm[qtermcount]->idxOne = $2;} ;
qtermidxTwoatt: IDXTWOATT INTEGER   { 
osinstance->instanceData->quadraticCoefficients->qTerm[qtermcount]->idxTwo = $2;} ;
qtermcoefatt: COEFATT DOUBLE   {
osinstance->instanceData->quadraticCoefficients->qTerm[qtermcount]->coef = $2;} 
| COEFATT INTEGER   { 
osinstance->instanceData->quadraticCoefficients->qTerm[qtermcount]->coef = $2;}  ;
qtermidxatt: IDXATT INTEGER   {  
osinstance->instanceData->quadraticCoefficients->qTerm[qtermcount]->idx = $2;} ;




nonlinearExpressions:  
				| NONLINEAREXPRESSIONSSTART  nlnumberatt nlnodes NONLINEAREXPRESSIONSEND
				{if(nlnodecount <  tmpnlcount)  osilerror("actual number of nl terms less than number attribute"); };
				

nlnumberatt: NUMBEROFNONLINEAREXPRESSIONS INTEGER quote  GREATERTHAN {tmpnlcount = $2;
osinstance->instanceData->nonlinearExpressions->numberOfNonlinearExpressions = $2;  
if(osinstance->instanceData->nonlinearExpressions->numberOfNonlinearExpressions > 0 ) osinstance->instanceData->nonlinearExpressions->nl = new Nl*[ $2 ];
};
				
nlnodes: 
		| nlnodes NLSTART 
		nlIdxATT  GREATERTHAN nlnode {
	// IMPORTANT -- HERE IS WHERE WE DEFINE THE EXPRESSION TREE
	osinstance->instanceData->nonlinearExpressions->nl[ nlnodecount]->osExpressionTree->m_treeRoot = 
	//osinstance->instanceData->nonlinearExpressions->nl[ nlnodecount]->osExpressionTree->createExpressionTreeFromPrefix( nlNodeVec);
	//createExpressionTreeFromPrefix( nlNodeVec);
	nlNodeVec[ 0]->createExpressionTreeFromPrefix( nlNodeVec);
	nlnodecount++;
}  NLEND;

nlIdxATT:  IDXATT INTEGER quote {
osinstance->instanceData->nonlinearExpressions->nl[ nlnodecount] = new Nl();
osinstance->instanceData->nonlinearExpressions->nl[ nlnodecount]->idx = $2;
osinstance->instanceData->nonlinearExpressions->nl[ nlnodecount]->osExpressionTree = new OSExpressionTree();
if(nlnodecount > tmpnlcount) osilerror("actual number of nl terms greater than number attribute");
// clear the vectors of pointers
nlNodeVec.clear();
sumVec.clear();
maxVec.clear();
productVec.clear();
};
		
		
nlnode: number
		| variable 
		| times 
		| plus 
		| sum 
		| minus 
		| negate
		| divide 
		| power 
		| product
		| ln 
		| exp
		| if
		| abs
		| max;


times: TIMESSTART {
	nlNodePoint = new OSnLNodeTimes();
	nlNodeVec.push_back( nlNodePoint);
} nlnode nlnode TIMESEND;

plus: PLUSSTART {
	nlNodePoint = new OSnLNodePlus();
	nlNodeVec.push_back( nlNodePoint);
} nlnode nlnode PLUSEND;

minus: MINUSSTART {
	nlNodePoint = new OSnLNodeMinus();
	nlNodeVec.push_back( nlNodePoint);
} nlnode nlnode MINUSEND;

negate: NEGATESTART {
	nlNodePoint = new OSnLNodeNegate();
	nlNodeVec.push_back( nlNodePoint);
} nlnode  NEGATEEND;

divide: DIVIDESTART { 
	nlNodePoint = new OSnLNodeDivide();
	nlNodeVec.push_back( nlNodePoint);
} nlnode nlnode DIVIDEEND;

power: POWERSTART {
	nlNodePoint = new OSnLNodePower();
	nlNodeVec.push_back( nlNodePoint);
} nlnode nlnode POWEREND;

sum: SUMSTART {
	nlNodePoint = new OSnLNodeSum();
	nlNodeVec.push_back( nlNodePoint);
	sumVec.push_back( nlNodePoint);
}
anothersumnlnode SUMEND {
	sumVec.back()->m_mChildren = new OSnLNode*[ sumVec.back()->inumberOfChildren];
	sumVec.pop_back();
};

anothersumnlnode: nlnode {	sumVec.back()->inumberOfChildren++; }
			| anothersumnlnode nlnode {	sumVec.back()->inumberOfChildren++; };
			
			
max: MAXSTART {
	nlNodePoint = new OSnLNodeMax();
	nlNodeVec.push_back( nlNodePoint);
	maxVec.push_back( nlNodePoint);
}
anothermaxnlnode MAXEND {
	maxVec.back()->m_mChildren = new OSnLNode*[ maxVec.back()->inumberOfChildren];
	maxVec.pop_back();
};

anothermaxnlnode: nlnode {	maxVec.back()->inumberOfChildren++; }
			| anothermaxnlnode nlnode {	maxVec.back()->inumberOfChildren++; };
			
			
product: PRODUCTSTART {
	nlNodePoint = new OSnLNodeProduct();
	nlNodeVec.push_back( nlNodePoint);
	productVec.push_back( nlNodePoint);
}
anotherproductnlnode PRODUCTEND {
	productVec.back()->m_mChildren = new OSnLNode*[ productVec.back()->inumberOfChildren];
	productVec.pop_back();
};

anotherproductnlnode: nlnode {	productVec.back()->inumberOfChildren++; }
			| anotherproductnlnode nlnode {	productVec.back()->inumberOfChildren++; };


ln: LNSTART {
	nlNodePoint = new OSnLNodeLn();
	nlNodeVec.push_back( nlNodePoint);
} nlnode LNEND;


exp: EXPSTART {
	nlNodePoint = new OSnLNodeExp();
	nlNodeVec.push_back( nlNodePoint);
} nlnode EXPEND;

abs: ABSSTART {
	nlNodePoint = new OSnLNodeAbs();
	nlNodeVec.push_back( nlNodePoint);
} nlnode ABSEND;


if: IFSTART {
	nlNodePoint = new OSnLNodeIf();
	nlNodeVec.push_back( nlNodePoint);
} nlnode nlnode nlnode IFEND;

number: NUMBERSTART {
	nlNodeNumberPoint = new OSnLNodeNumber();
	nlNodeVec.push_back( nlNodeNumberPoint);
} anotherNumberATT  numberend {numbervalueattON = false; numbertypeattON = false; numberidattON = false;};

variable: VARIABLESTART {
	nlNodeVariablePoint = new OSnLNodeVariable();
	nlNodeVec.push_back( nlNodeVariablePoint);
} anotherVariableATT  variableend {variablecoefattON = false; variableidxattON = false;} ;
		      
numberend: ENDOFELEMENT
			| NUMBEREND;
			
variableend: ENDOFELEMENT
			| GREATERTHAN nlnode {
	//sumVec.back()->inumberOfChildren = 1;
	//sumVec.back()->m_mChildren = new OSnLNode*[ 1];
	// kipp -- fix the above doesnt seem right
	nlNodeVariablePoint->inumberOfChildren = 1;
	nlNodeVariablePoint->m_mChildren = new OSnLNode*[ 1];
}
VARIABLEEND;
			

anotherNumberATT:
			|anotherNumberATT numberATT ;
			
numberATT: numbertypeATT quote {if(numbertypeattON) osilerror("too many number type attributes"); 
			numbertypeattON = true; }
		| numbervalueATT quote {if(numbervalueattON) osilerror("too many number value attributes"); 
			numbervalueattON = true; }
		| numberidATT quote {if(numberidattON) osilerror("too many number id attributes"); 
			numberidattON = true; }			
			;
			
numbertypeATT: TYPEATT  ATTRIBUTETEXT {
	nlNodeNumberPoint->type = $2;
} ;

numberidATT: IDATT  ATTRIBUTETEXT {
	nlNodeNumberPoint->id = $2;
} ;



numbervalueATT: VALUEATT  DOUBLE {
	nlNodeNumberPoint->value = $2;
}
		| VALUEATT INTEGER{
	nlNodeNumberPoint->value = $2;
};

anotherVariableATT:
			|anotherVariableATT variableATT ;
			
variableATT: variablecoefATT quote {if(variablecoefattON) osilerror("too many variable coef attributes"); 
			variablecoefattON = true; }
		| variableidxATT quote {if(variableidxattON) osilerror("too many variable idx attributes"); 
			variableidxattON = true; };
			
variablecoefATT: COEFATT  DOUBLE {
	nlNodeVariablePoint->coef = $2;
}
				| COEFATT  INTEGER {
	nlNodeVariablePoint->coef = $2;		
};
				
variableidxATT: IDXATT  INTEGER {
	nlNodeVariablePoint->idx = $2;
} ; 


xmlWhiteSpaceChar: ' '
				| '\t'
				| '\r'
				| '\n' ;
				
xmlWhiteSpace: 
			| xmlWhiteSpace xmlWhiteSpaceChar ;
		
quote: xmlWhiteSpace QUOTE;




		
%%




// user defined functions


void osilerror(const char* errormsg) {
	try{
		std::ostringstream outStr;
		std::string error = errormsg;
		error = "PARSER ERROR:  Input is either not valid or well formed: "  + error;
		outStr << error << endl;
		outStr << "Here are the last 5 and next 15 characters currently being pointed to in the input string: ";
		for(int i = -5; i < 15; i++){ 
			if(osiltext[ i] != '\0' ) outStr << osiltext[ i];
		}
		outStr << endl;
		outStr << "See line number: " << osillineno << endl;  
		error = outStr.str();
		throw ErrorClass( error);
	}
		catch(const ErrorClass& eclass){
		throw ErrorClass(  eclass.errormsg); 
	}
} // end osilerror() 

OSInstance* yygetOSInstance( const char *osil) throw (ErrorClass)
try {
		void yyinitialize();
		yyinitialize();
		ch = NULL;
		osinstance = NULL;
		osinstance = new OSInstance();
		parseInstanceHeader( &osil);
		const char *varel = "<variables";
		ch = strstr(osil, varel);
		if(ch == NULL) throw ErrorClass("variables element required");
		if( parseVariables() != true) {throw ErrorClass("error in parse variables");}
		if( parseObjectives() != true)  throw ErrorClass("error in parse objectives");
		if( parseConstraints() != true) throw ErrorClass("error in parse Constraints");
		if( parseLinearConstraintCoefficients() != true) throw ErrorClass("error in parse ConstraintCoefficients");	
		osil_scan_string( ch);
		if(  osilparse( ) != 0) throw ErrorClass(  sparseError);
		return osinstance;
}//end yygetOSInstance
		catch(const ErrorClass& eclass){
		throw ErrorClass(  eclass.errormsg); 
	}

void osilClearMemory(){
	delete osinstance;
	osinstance = NULL;
} // end osilClearMemory

void yyinitialize(){
	osillineno = 1; 
	qtermcount = 0;
	nlnodecount = 0;
	// qterm attribute boolean variables
	qtermidxOneattON = false;
	qtermidxTwoattON = false;
	qtermidxattON = false;
	qtermidattON = false;
	qtermcoefattON = false;
	// number attribute boolean variables 
	numbertypeattON = false;
	numbervalueattON = false;
	// variable attribute boolean variables
	variableidxattON = false;
	variablecoefattON = false;
	// kipp -- change later when nonlinear added to OSInstnace
	tmpnlcount = 0;
	sparseError = "";
} // end yyInitialize()


bool isnewline(char c){
	if(c != '\n') return false;
	osillineno++;
	return true;
}//end isnewline()

bool parseInstanceHeader( const char **p){
	//
	const char *pchar = *p;
	// create a char array that holds the instance header information
	const char *startInstanceHeader = "<instanceHeader";
	const char *endInstanceHeader = "</instanceHeader";
	const char *startName = "<name";
	const char *endName = "</name";
	const char *startSource = "<source";
	const char *endSource = "</source";
	const char *startDescription = "<description";
	const char *endDescription = "</description";
	const char *pinstanceHeadStart = strstr(pchar, startInstanceHeader);
	char *pelementText = NULL;
	char *ptemp = NULL;
	int i, elementSize;
	if(pinstanceHeadStart == NULL) {osiltext = (char*)*p; osilerror("<instanceHeader> element missing"); return false;}
	// increment the line number counter if there are any newlines between the start of
	// the osil string and pinstanceHeadStart
	int	kount = pinstanceHeadStart - pchar;
	while( kount-- > 0) if(*(pchar++) == '\n') 	osillineno++;
	// important! pchar now points to the '<' in <instanceHeader
	// that is both pinstanceHeadStart and pchar point to the same thing
 	// 
 	// move to the end of <instanceHeader
 	pchar+=15;
 	// remember where we are
 	
 	//
	// burn any whitespace
	for( ; ISWHITESPACE( *pchar) || isnewline( *pchar); pchar++ ) ;
	// pchar better be pointing to the '>' in the <instanceHeader> element
	// or to /> if we have <instanceHeader />
	if( *pchar == '/'){
		pchar++;
		// better point to a '>'
		if(*pchar != '>') {osiltext = (char*)*p; osilerror("improperly formed <instanceHeader> element"); return false;}
		// there is no instanceHeader data
		pchar++;
		return true;
	}
	else{
		// pchar better be '>' or there is an error
		if(*pchar != '>') {osiltext = (char*)*p; osilerror("improperly formed <instanceHeader> element"); return false;}
	}
	pchar++;
	// we are pointing to the character after <instanceHeader>
	//
	//
	//
	// process the <name> element which is optional
	//
	// first burn any whitespace
	for( ; ISWHITESPACE( *pchar) || isnewline( *pchar); pchar++ ) ;
	// if, present we should be pointing to <name element if there -- it is not required
	//remember where we are
	*p = pchar;
	//for(i = 0; *(startName + i)  == *pchar; i++, pchar++);
	while(*startName++  == *pchar) pchar++;
	if( (pchar - *p)  != 5) {
		//reset pchar
		pchar = *p;
	}
	else{
	// we have a name element, process the text
	// burn the whitespace
		for( ; ISWHITESPACE( *pchar) || isnewline( *pchar); pchar++ ) ;	
		if( *pchar == '/'){
			pchar++;
			// better point to a '>'
			if(*pchar != '>') {osiltext = (char*)*p; osilerror("improperly formed <name> element"); return false;}
		}
		else{
			// pchar better be '>' or there is an error
			if(*pchar != '>') {osiltext = (char*)*p; osilerror("improperly formed <name> element"); return false;}
			pchar++;
			// proces <name> element text
			// there better be a </name
			ptemp = strstr( pchar, endName);
			if( ptemp == NULL) {osiltext = (char*)*p; osilerror("improperly formed </name> element"); return false;}
			elementSize = ptemp - pchar;
			pelementText = new char[ elementSize + 1];
			strncpy(pelementText, pchar, elementSize);
			pelementText[ elementSize] = '\0';
			osinstance->instanceHeader->name = pelementText;
			//garbage collection
			delete [] pelementText;
			// move pchar up to the end of </name
			while(elementSize-- > 0){
				if(*pchar++ == '\n') osillineno++;
			}
			// pchar should now be pointing to the start of </name
			// move to first char after </name
			pchar += 6;
			// get rid of the whitespace
			for( ; ISWHITESPACE( *pchar) || isnewline( *pchar); pchar++ ) ;	
			// we better have the '>' for the end of name
			if(*pchar++ != '>'){osiltext = (char*)*p; osilerror("improperly formed </name> element"); return false;}
		}
	}// end of else after discovering a name element
	//done processing name element
	//
	//
	// process the <source> element which is optional
	//
	// first burn any whitespace
	for( ; ISWHITESPACE( *pchar) || isnewline( *pchar); pchar++ ) ;
	// if, present we should be pointing to <source element if there -- it is not required
	for(i = 0; *(startSource + i)  == *pchar; i++, pchar++);
	if(i != 7) {
		//reset pchar
		pchar -= i;
	}
	else{
	// we have a source element, process the text
	// burn the whitespace
		for( ; ISWHITESPACE( *pchar) || isnewline( *pchar); pchar++ ) ;	
		if( *pchar == '/'){
			pchar++;
			// better point to a '>'
			if(*pchar != '>') {osiltext = (char*)*p; osilerror("improperly formed <source> element"); return false;}
		}
		else{
			// pchar better be '>' or there is an error
			if(*pchar != '>') {osiltext = (char*)*p; osilerror("improperly formed <source> element"); return false;}
			pchar++;
			// proces <source> element text
			// there better be a </source
			ptemp = strstr( pchar, endSource);
			if( ptemp == NULL) {osiltext = (char*)*p; osilerror("improperly formed </source> element"); return false;}
			elementSize = ptemp - pchar;
			pelementText = new char[ elementSize + 1];
			strncpy(pelementText, pchar, elementSize);
			pelementText[ elementSize] = '\0';
			osinstance->instanceHeader->source = pelementText;
			//garbage collection
			delete [] pelementText;
			// move pchar up to the end of </source
			while(elementSize-- > 0){
				if(*pchar++ == '\n') osillineno++;
			}
			// pchar should now be pointing to the start of </source
			// move to first char after </source
			pchar += 8;
			// get rid of the whitespace
			for( ; ISWHITESPACE( *pchar) || isnewline( *pchar); pchar++ ) ;	
			// we better have the '>' for the end of source
			if(*pchar++ != '>'){osiltext = (char*)*p; osilerror("improperly formed </source> element"); return false;}
		}
	}// end of else after discovering a source element
	//done processing <source> element
	//
	//
	//process the <description> element
	//
	// first burn any whitespace
	for( ; ISWHITESPACE( *pchar) || isnewline( *pchar); pchar++ ) ;
	// if, present we should be pointing to <description element if there -- it is not required
	for(i = 0; *(startDescription + i)  == *pchar; i++, pchar++);
	if(i != 12) {
		//reset pchar
		pchar -= i;
	}
	else{
	// we have a description element, process the text
	// burn the whitespace
		for( ; ISWHITESPACE( *pchar) || isnewline( *pchar); pchar++ ) ;	
		if( *pchar == '/'){
			pchar++;
			// better point to a '>'
			if(*pchar != '>') {osiltext = (char*)*p; osilerror("improperly formed <description> element"); return false;}
		}
		else{
			// pchar better be '>' or there is an error
			if(*pchar != '>') {osiltext = (char*)*p; osilerror("improperly formed <description> element"); return false;}
			pchar++;
			// proces <source> element text
			// there better be a </description
			ptemp = strstr( pchar, endDescription);
			if( ptemp == NULL) {osiltext = (char*)*p; osilerror("improperly formed </description> element"); return false;}
			elementSize = ptemp - pchar;
			pelementText = new char[ elementSize + 1];
			strncpy(pelementText, pchar, elementSize);
			pelementText[ elementSize] = '\0';
			osinstance->instanceHeader->description = pelementText;
			//garbage collection
			delete [] pelementText;
			// move pchar up to the end of </description
			while(elementSize-- > 0){
				if(*pchar++ == '\n') osillineno++;
			}
			// pchar should now be pointing to the start of </description
			// move to first char after </description
			pchar += 13;
			// get rid of the whitespace
			for( ; ISWHITESPACE( *pchar) || isnewline( *pchar); pchar++ ) ;	
			// we better have the '>' for the end of </description>
			if(*pchar++ != '>'){osiltext = (char*)*p; osilerror("improperly formed </description> element"); return false;}
		}
	}// end of else after discovering a description element
	//done processing <description> element
	//
	// if we are here there must be an </instanceHeader > element
	// burn the whitespace
	for( ; ISWHITESPACE( *pchar) || isnewline( *pchar); pchar++ ) ;	
	// we should be pointing to </instanceHeader
	for(i = 0; *(endInstanceHeader + i)  == *pchar; i++, pchar++);
	if(i != 16) {osiltext = (char*)*p; osilerror("improperly formed </instanceHeader> element"); return false;}	
	// pchar now points to the first character after </instanceHeader
	// get rid of white space
	for( ; ISWHITESPACE( *pchar) || isnewline( *pchar); pchar++ ) ;	
	// pchar must point to '>' or there is an error
	if(*pchar != '>'){osiltext = (char*)*p; osilerror("improperly formed </instanceHeader> element"); return false;}	
	pchar++;
	*p = pchar;
	return true;
}//end parseInstanceHeader


bool parseVariables(){
	start = clock(); 
	const char *c_numberOfVariables = "numberOfVariables";
	const char *startVariables = "<variables";
	const char *endVariables = "</variables";
	const char *startVar = "<var";
	const char *endVar = "</var";
	// the attributes
	char *attText = NULL;
	const char *name = "name";
	const char *initString = "initString";
	const char *type = "type";
	const char *mult = "mult";
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
	for(i = 0; startVariables[i]  == *ch; i++, ch++);
	if(i != 10) {osiltext = &ch[0]; osilerror("incorrect <variables tag>"); return false;}
	// find numberOfVariables attribute
	// eat the white space
	for( ; ISWHITESPACE( *ch) || isnewline( *ch); ch++ ) ;
	for(i = 0; c_numberOfVariables[i]  == *ch; i++, ch++);
	if(i != 17) {osiltext = &ch[0]; osilerror("incorrect numberOfVariables attribute in <variables tag>"); return false;}	
	// buf_index should be pointing to the first character after numberOfVariables
	GETATTRIBUTETEXT;
	ch++;
	numberOfVariables = atoimod1( attText, attTextEnd);
	delete [] attText;
	if(numberOfVariables <= 0) {
		osilerror("there must be at least one variable"); return false;
	}
	osinstance->instanceData->variables->numberOfVariables = numberOfVariables;
	osinstance->instanceData->variables->var = new Variable*[ numberOfVariables];
	for(i = 0; i < numberOfVariables; i++){
		osinstance->instanceData->variables->var[ i] = new Variable();
	} 
	// get rid of white space after the numberOfVariables element
	for( ; ISWHITESPACE( *ch) || isnewline( *ch); ch++ )
	// since there must be at least one variable,  this element must end with > 
	// better have an > sign or not valid
	if(*ch != '>' ) {osiltext = &ch[0]; osilerror("variables element does not have a proper closing >"); return false;}
	ch++;
	// get rid of white space
	for( ; ISWHITESPACE( *ch) || isnewline( *ch); ch++ ) ;
	// now loop over the var elements, there must be at least one var element
	for(i = 0; startVar[i]  == *ch; i++, ch++);
	if(i ==  4) foundVar = true;
		else {osiltext = &ch[0]; osilerror("there must be at least one <var> element"); return false;}
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
				if( i != 4 ) {osiltext = &ch[0]; osilerror("error in variables name attribute"); return false;}
				if(varnameattON == true) {osiltext = &ch[0]; osilerror("error too many variable name attributes"); return false;}
				varnameattON == true;
				GETATTRIBUTETEXT;
				osinstance->instanceData->variables->var[varcount]->name=attText;
				delete [] attText;
				//printf("ATTRIBUTE = %s\n", attText);
				break;
			case 'i':
				for(i = 0; initString[i]  == *ch; i++, ch++);
				// if i < 4 there is an error
				// if i = 4 we matched init
				// if i = 10 we matched initString
				if( (i != 4)  && (i != 10)) {osiltext = &ch[0]; osilerror("error in variables init or initString attribute"); return false;}
				if(i == 4){
					if(varinitattON == true) {osiltext = &ch[0]; osilerror("error too many variable init attributes"); return false;}
					varinitattON = true;
					GETATTRIBUTETEXT;
					//printf("ATTRIBUTE = %s\n", attText);
					osinstance->instanceData->variables->var[varcount]->init=atofmod1(attText, attTextEnd);
					delete [] attText;
				}
				else{
					if(varinitStringattON == true) {osiltext = &ch[0]; osilerror("error too many variable initString attributes"); return false;}
					varinitStringattON = true;
					GETATTRIBUTETEXT;
					delete [] attText;
					//printf("ATTRIBUTE = %s\n", attText);
					osinstance->instanceData->variables->var[varcount]->initString=attText;
				}
				break;
			case 't':
				for(i = 0; type[i]  == *ch; i++, ch++);
				if(i != 4) {osiltext = &ch[0]; osilerror("error in variables type attribute"); return false;}
				if(vartypeattON == true) {osiltext = &ch[0]; osilerror("error too many variable type attributes"); return false;}
				vartypeattON = true;
				GETATTRIBUTETEXT;
				if( strchr("CBIS", attText[0]) == NULL ) {osiltext = &ch[0]; osilerror("variable type not C,B,I, or S"); return false;}
				osinstance->instanceData->variables->var[varcount]->type = attText[0];
				delete [] attText;
				break;
			case 'l':
				ch++;
				if(*ch++ != 'b') {osiltext = &ch[0]; osilerror("error in variables lower bound attribute"); return false;}
				if(varlbattON == true) {osiltext = &ch[0]; osilerror("error too many variable lb attributes"); return false;}
				varlbattON = true;
				GETATTRIBUTETEXT;
				osinstance->instanceData->variables->var[varcount]->lb = atofmod1(attText, attTextEnd);
				delete [] attText;
				//printf("ATTRIBUTE = %s\n", attText);
				break;
			case 'u':
				ch++;
				if(*ch++ != 'b') {osiltext = &ch[0]; osilerror("error in variables upper bound attribute"); return false;}
				if(varubattON == true) {osiltext = &ch[0]; osilerror("error too many variable ub attributes"); return false;}
				varubattON = true;
				GETATTRIBUTETEXT;
				osinstance->instanceData->variables->var[varcount]->ub = atofmod1(attText, attTextEnd);
				delete [] attText;
				//printf("ATTRIBUTE = %s\n", attText);
				break;
			case 'm':
				for(i = 0; mult[i]  == *ch; i++, ch++);
				if(i != 4) {osiltext = &ch[0]; osilerror("error in variables mult attribute"); return false;}
				if(varmultattON == true) {osiltext = &ch[0]; osilerror("error too many variable mult attributes"); return false;}
				varmultattON = true;
				GETATTRIBUTETEXT;
				delete [] attText;
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
				{osiltext = &ch[0]; osilerror("invalid attribute character"); return false;}
				break;
			}
			ch++;
		}
		//
		// assume all the attributes have been processed
		// must have either /> or > and then whitespace and </var whitespace>
		if( *ch != '/' && *ch != '>') {osiltext = &ch[0]; osilerror("incorrect end of <var> element"); return false;}
		if(*ch == '/'){
			ch++;
			if(*ch != '>') {osiltext = &ch[0]; osilerror("incorrect end of <var> element"); return false;}
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
			if(*ch != '>') {osiltext = &ch[0]; osilerror("improper ending to a <var> element"); return false;}
			// look for </var
			// fist get rid of white space
			ch++;
			for(; ISWHITESPACE( *ch) || isnewline( *ch); ch++ );
			// we should be at </var or there is an error
			for(i = 0; endVar[i]  == *ch; i++, ch++);
			if(i != 5) {osiltext = &ch[0]; osilerror("</var> element missing"); return false;}
			// burn off the whitespace
			for(; ISWHITESPACE( *ch) || isnewline( *ch); ch++ );
			// better have an > to end </var
			if(*ch++ != '>') {osiltext = &ch[0]; osilerror("</var> element missing >"); return false;}
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
		if( (varcount == numberOfVariables - 1) && (foundVar == true) ) {osiltext = &ch[0];  osilerror("attribute numberOfVariables is less than actual number found");  return false;}
		varcount++;
	}
	ch -= i;
	if(varcount < numberOfVariables) {osiltext = &ch[0]; osilerror("attribute numberOfVariables is greater than actual number found");   return false;}
	// get the </variables> tag
	for(i = 0; endVariables[i]  == *ch; i++, ch++);
	if(i != 11) {osiltext = &ch[0];  osilerror("cannot find </varialbes> tag"); return false;}
	for(; ISWHITESPACE( *ch) || isnewline( *ch); ch++ );	
	// better have >
	if(*ch != '>') {osiltext = &ch[0];  osilerror("improperly formed </variables> tag"); return false;}
	ch++;
	finish = clock();
	duration = (double) (finish - start) / CLOCKS_PER_SEC; 
	printf("TIME TO PARSE VARIABLES = %f\n", duration);
	return true;
}//end parseVariables


bool parseObjectives(){
	start = clock();
	const char *c_numberOfObjectives = "numberOfObjectives";
	const char *startObjectives = "<objectives";
	const char *endObjectives = "</objectives";
	const char *startObj = "<obj";
	const char *endObj = "</obj";
	// attributes
	char *attText = NULL;
	const char *constant = "constant";
	const char *maxOrMin = "maxOrMin";
	const char *numberOfObjCoef = "numberOfObjCoeff";
	const char *weight = "weight";
	const char *name = "name";
	const char *mult = "mult";
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
		// we return true because it is okay to not have objectives
		return true;
	}
	// find numberOfObjectives attribute -- it is valid for this attribute to be missing. 
	// However if the  number attribute is missing assume it is	1 
	// eat the white space
	for( ; ISWHITESPACE( *ch) || isnewline( *ch); ch++ ) ;
	// we just ate the white space. If numberOfObjectives is missing we assume it is 1
	// we therefore must have > char
	if(*ch == '>'){
		numberOfObjectives = 1;
		//ch++;
	}
	else{
		for(i = 0; c_numberOfObjectives[i]  == *ch; i++, ch++);
		if(i != 18) {osiltext = &ch[0]; osilerror("incorrect numberOfObjectives attribute in <objectives> tag"); return false;}	
		GETATTRIBUTETEXT;
		numberOfObjectives = atoimod1( attText, attTextEnd);
		delete [] attText;
		ch++;
	}
	if(numberOfObjectives > 0){
		// get rid of white space after the numberOfObjectives attribute
		for( ; ISWHITESPACE( *ch) || isnewline( *ch); ch++ ) ;
		// we must have an >
		/*if(*ch == '/'){
			ch++;
			if( *ch++ != '>') {osiltext = &ch[0]; osilerror("the objectives element does not have a proper closing"); return false; }
			else{
				if(numberOfObjectives > 0){osiltext = &ch[0];  osilerror("numberOfObjectives positive but there are no objectives"); return false;}
				return false;
			}
		}*/
		//  we better have an > 
		if( *ch++ != '>') {osiltext = &ch[0]; osilerror("the objectives element does not have a proper closing"); return false;} 
		osinstance->instanceData->objectives->numberOfObjectives = numberOfObjectives;
		osinstance->instanceData->objectives->obj = new Objective*[ numberOfObjectives];
		for(i = 0; i < numberOfObjectives; i++){
			osinstance->instanceData->objectives->obj[ i] = new Objective();
		} 	
	// get rid of white space after the <objectives> element
	for( ; ISWHITESPACE( *ch) || isnewline( *ch); ch++ ) ;
	// now loop over the obj elements, there must be at least one obj element
	for(i = 0; startObj[ i] == *ch; i++, ch++);
	if( i == 4) foundObj = true;
		else {osiltext = &ch[0]; osilerror("there must be at least one <obj> element"); return false;}
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
					if( (i != 15)  ) {osiltext = &ch[0]; osilerror("error in objective numberOfObjCoef attribute"); return false;}
					else{
						if(objnumberOfObjCoefattON == true) {osiltext = &ch[0]; osilerror("error too many obj numberOfObjCoefatt attributes"); return false;}
						objnumberOfObjCoefattON = true;
						GETATTRIBUTETEXT;
						//printf("ATTRIBUTE = %s\n", attText);
						osinstance->instanceData->objectives->obj[objcount]->numberOfObjCoef=atoimod1(attText, attTextEnd);
						osinstance->instanceData->objectives->obj[objcount]->coef = new ObjCoef*[osinstance->instanceData->objectives->obj[ objcount]->numberOfObjCoef];
						for(int i = 0; i < osinstance->instanceData->objectives->obj[ objcount]->numberOfObjCoef; i++)osinstance->instanceData->objectives->obj[objcount]->coef[i] = new ObjCoef();
						delete [] attText;
					}
				}
				else{
					for(i = 0; name[i]  == *ch; i++, ch++);
					if( (i != 4)  ) {osiltext = &ch[0]; osilerror("error in objective name attribute"); return false;}
					else{
						if(objnameattON == true) {osiltext = &ch[0]; osilerror("error too many obj name attributes"); return false;}
						objnameattON = true;
						GETATTRIBUTETEXT;
						//printf("ATTRIBUTE = %s\n", attText);
						osinstance->instanceData->objectives->obj[objcount]->name=attText;
						delete [] attText;
					}
				}
				break;
			case 'c':
				for(i = 0; constant[i]  == *ch; i++, ch++);
				if( (i != 7)  ) {osiltext = &ch[0]; osilerror("error in objective constant attribute"); return false;}
				else{
					if(objconstantattON == true) {osiltext = &ch[0]; osilerror("error too many obj constant attributes"); return false;}
					objconstantattON = true;
					GETATTRIBUTETEXT;
					//printf("ATTRIBUTE = %s\n", attText);
					osinstance->instanceData->objectives->obj[objcount]->constant=atofmod1(attText, attTextEnd);
					delete [] attText;
				}
				break;
			case 'w':
				for(i = 0; weight[i]  == *ch; i++, ch++);
				if( (i != 6)  ) {osiltext = &ch[0]; osilerror("error in objective weight attribute"); return false;}
				else{
					if(objweightattON == true) {osiltext = &ch[0]; osilerror("error too many obj weight attributes"); return false;}
					objweightattON = true;
					GETATTRIBUTETEXT;
					//printf("ATTRIBUTE = %s\n", attText);
					osinstance->instanceData->objectives->obj[objcount]->weight=atofmod1(attText, attTextEnd);
					delete [] attText;
				}
				break;
			case 'm':
				if(*(ch+1) == 'a'){
					for(i = 0; maxOrMin[i]  == *ch; i++, ch++);
					if( (i != 8)  ) {osiltext = &ch[0]; osilerror("error in objective maxOrMin attribute"); return false;}
					else{
						if(objmaxOrMinattON == true) {osiltext = &ch[0]; osilerror("error too many obj maxOrMin attributes"); return false;}
						objmaxOrMinattON = true;
						GETATTRIBUTETEXT;
						//printf("ATTRIBUTE = %s\n", attText);
						if( (strcmp("max", attText) != 0 ) && (strcmp("min", attText) != 0 ) ){osilerror("maxOrMin attribute in objective must be a max or min"); return false;}
						osinstance->instanceData->objectives->obj[objcount]->maxOrMin = attText;
						delete [] attText;
					}
				}
				else{
					for(i = 0; mult[i]  == *ch; i++, ch++);
					if( (i != 4)  ) {osiltext = &ch[0]; osilerror("error in objective mult attribute"); return false;}
					else{
						if(objmultattON == true) {osiltext = &ch[0]; osilerror("error too many obj mult attributes"); return false;}
						objmultattON = true;
						GETATTRIBUTETEXT;
						//printf("ATTRIBUTE = %s\n", attText);
						//osinstance->instanceData->objectives->obj[objcount]->name=attText;
						delete [] attText;
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
				return false;
				break;
			}
			ch++;
		}
		//
		// assume all the attributes have been processed
		// must have either /> or > and then whitespace and </obj whitespace>
		if( *ch != '/' && *ch != '>') {osiltext = &ch[0];  osilerror("incorrect end of <obj> element"); return false;}
		if(*ch == '/'){
			ch++;
			if(*ch != '>') {osiltext = &ch[0]; osilerror("incorrect end of <obj> element"); return false;}
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
			if(*ch != '>') {osiltext = &ch[0]; osilerror("improper ending to a <obj> element"); return false;}
			// look for </obj
			// fist get rid of white space
			ch++;
			// first get the <coef> elements
			parseObjCoef( objcount);
			for(; ISWHITESPACE( *ch) || isnewline( *ch); ch++ );
			// we should be at </obj or there is an error
			for(i = 0; endObj[i]  == *ch; i++, ch++);
			if(i != 5) {osiltext = &ch[0]; osilerror("</obj> element missing"); return false;}
			// burn off the whitespace
			for(; ISWHITESPACE( *ch) || isnewline( *ch); ch++ );
			// better have an > to end </obj
			if(*ch++ != '>'){osiltext = &ch[0];  osilerror("</obj> element missing >"); return false;}
			// look for a new <obj> element
			// get rid of whitespace
			for(; ISWHITESPACE( *ch) || isnewline( *ch); ch++ );
			// either have another <obj> element or foundObj = false;
			for(i = 0; startObj[i]  == *ch; i++, ch++);
			if(i == 4) foundObj = true;
				else foundObj = false;
		}
		if( (objcount == numberOfObjectives - 1) && (foundObj == true)) {osiltext = &ch[0]; osilerror("attribute numberOfObjectives is less than actual number found"); return false;}
		objcount++;
	}
	if(objcount < numberOfObjectives) {osiltext = &ch[0]; osilerror("attribute numberOfObjectives is greater than actual number found"); return false;}
	ch -= i;
	// get the </objectives> tag
	for(i = 0; endObjectives[i]  == *ch; i++, ch++);
	if(i != 12) {osiltext = &ch[0]; osilerror( "cannot find </objectives> tag"); return false; }
	for(; ISWHITESPACE( *ch) || isnewline( *ch); ch++ );	
	// better have >
	if(*ch != '>') {osiltext = &ch[0]; osilerror("improperly formed </objectives> tag"); return false;}	
	ch++;
	} // finish the (if numberOfObjectives > 0)
	else{
		// error if the number is negative
		if(numberOfObjectives < 0) {osiltext = &ch[0]; osilerror("cannot have a negative number of objectives"); return false;}
		// if we are here we have exactly 0 objectives 
		// must close with /> or </objectives>
		// get rid of white space
		for(; ISWHITESPACE( *ch) || isnewline( *ch); ch++ );
		if( *ch == '/'){
			// better have a >
			ch++;
			if( *ch  != '>') {osiltext = &ch[0]; osilerror("improperly closed objectives tag"); return false;}
			ch++;
		}
		else{
			// if we are here we must have an '>' and then  </objectives> tag
			if( *ch  != '>') {osiltext = &ch[0]; osilerror("improperly closed objectives tag"); return false;}
			ch++;
			// burn white space
			for(; ISWHITESPACE( *ch) || isnewline( *ch); ch++ );
			for(i = 0; endObjectives[i]  == *ch; i++, ch++);
			if(i != 12) {osiltext = &ch[0]; osilerror( "cannot find </objectives> tag"); return false; }
			for(; ISWHITESPACE( *ch) || isnewline( *ch); ch++ );	
			// better have >
			if(*ch != '>') {osiltext = &ch[0]; osilerror("improperly formed </objectives> tag"); return false;}	
			ch++;
		}
	}
	finish = clock();
	duration = (double) (finish - start) / CLOCKS_PER_SEC; 
	printf("TIME TO PARSE OBJECTIVES = %f\n", duration);
	return true;
}//end parseObjectives

bool parseConstraints(){
	start = clock();	
	const char *c_numberOfConstraints = "numberOfConstraints";
	const char *startConstraints = "<constraints";
	const char *endConstraints = "</constraints";
	const char *startCon = "<con";
	const char *endCon = "</con";
	// attributes
	char *attText = NULL;
	const char *name = "name";
	const char *constant = "constant";
	const char *mult = "mult";
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
		return true;
	}
	// find numberOfConstraints attribute
	// eat the white space
	for( ; ISWHITESPACE( *ch) || isnewline( *ch); ch++ ) ;
	for(i = 0; c_numberOfConstraints[i]  == *ch; i++, ch++);
	if(i != 19) {osiltext = &ch[0]; osilerror("incorrect numberOfConstraints attribute in <constraints> tag"); return false;}	
	// ch should be pointing to the first character after numberOfObjectives
	GETATTRIBUTETEXT;
	ch++;
	numberOfConstraints = atoimod1( attText, attTextEnd);
	delete [] attText;
	// key if
	//
	if(numberOfConstraints > 0){
		osinstance->instanceData->constraints->numberOfConstraints = numberOfConstraints;
		osinstance->instanceData->constraints->con = new Constraint*[ numberOfConstraints];
		for(i = 0; i < numberOfConstraints; i++){
			osinstance->instanceData->constraints->con[ i] = new Constraint();
		} 
	// get rid of white space after the numberOfConstraints element
	for( ; ISWHITESPACE( *ch) || isnewline( *ch); ch++ ) ;
	//  we better have an > 
	if( *ch++ != '>') {osiltext = &ch[0];  osilerror("the constraints element does not have a proper closing"); return false;} 
	// get rid of white space after the <constraints> element
	for( ; ISWHITESPACE( *ch) || isnewline( *ch); ch++ ) ;
	// now loop over the con elements, there must be at least one con element
	for(i = 0; startCon[i]  == *ch; i++, ch++);
	if( i == 4) foundCon = true;
		else {osiltext = &ch[0]; osilerror("there must be at least one <con> element"); return false;}
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
				if(i != 4) {osiltext = &ch[0]; osilerror("error in constraints name attribute"); return false;}
				if(connameattON == true) {osiltext = &ch[0]; osilerror("error too many con name attributes"); return false;}
				connameattON = true;
				GETATTRIBUTETEXT;
				osinstance->instanceData->constraints->con[concount]->name=attText;
				delete [] attText;
				//printf("ATTRIBUTE = %s\n", attText);
				break;
			case 'c':
				for(i = 0; constant[i]  == *ch; i++, ch++);
				if( (i != 7)  ) {osiltext = &ch[0]; osilerror("error in constraint constant attribute"); return false;}
				if(conconstantattON == true) {osiltext = &ch[0]; osilerror("error too many con constant attributes"); return false;}
				conconstantattON = true;
				GETATTRIBUTETEXT;
				//printf("ATTRIBUTE = %s\n", attText);
				osinstance->instanceData->constraints->con[concount]->constant=atofmod1(attText, attTextEnd);
				delete [] attText;
				break;
			case 'l':
				ch++;
				if(*ch++ != 'b') { osiltext = &ch[0]; osilerror("error in constraint lb attribute"); return false;}
				if(conlbattON == true) {osiltext = &ch[0]; osilerror("error too many con lb attributes"); return false;}
				conlbattON = true;
				GETATTRIBUTETEXT;
				osinstance->instanceData->constraints->con[concount]->lb = atofmod1(attText, attTextEnd);
				delete [] attText;
				//printf("ATTRIBUTE = %s\n", attText);
				break;
			case 'u':
				ch++;
				if(*ch++ != 'b') {osiltext = &ch[0]; osilerror("error in constraint ub attribute"); return false;}
				if(conubattON == true) {osiltext = &ch[0]; osilerror("error too many con ub attributes"); return false;}
				conubattON = true;
				GETATTRIBUTETEXT;
				osinstance->instanceData->constraints->con[concount]->ub = atofmod1(attText, attTextEnd);
				delete [] attText;
				//printf("ATTRIBUTE = %s\n", attText);
				break;
			case 'm':
				for(i = 0; mult[i]  == *ch; i++, ch++);
				if(i != 4) {osiltext = &ch[0]; osilerror("error in constraints mult attribute"); return false;}
				if(conmultattON == true) {osiltext = &ch[0]; osilerror("error too many con mult attributes"); return false;}
				conmultattON = true;
				GETATTRIBUTETEXT;
				delete [] attText;
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
				return false;
				break;
			}
			ch++;
		}
		//
		// assume all the attributes have been processed
		// must have either /> or > and then whitespace and </con whitespace>
		if( *ch != '/' && *ch != '>') {osiltext = &ch[0]; osilerror("incorrect end of <con> element"); return false;}
		if(*ch == '/'){
			ch++;
			if(*ch != '>') {osiltext = &ch[0]; osilerror("incorrect end of <con> element"); return false;}
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
			if(*ch != '>') {osiltext = &ch[0]; osilerror("improper ending to a <obj> element"); return false;}
			// look for </con
			// fist get rid of white space
			ch++;
			for(; ISWHITESPACE( *ch) || isnewline( *ch); ch++ );
			// we should be at </con or there is an error
			for(i = 0; endCon[i]  == *ch; i++, ch++);
			if(i != 5) {osiltext = &ch[0]; osilerror("</con> element missing"); return false;}
			// burn off the whitespace
			for(; ISWHITESPACE( *ch) || isnewline( *ch); ch++ );
			// better have an > to end </con
			if(*ch++ != '>') {osiltext = &ch[0]; osilerror("</con> element missing >"); return false;}
			// look for a new <con> element
			// get rid of whitespace
			ch++;
			for(; ISWHITESPACE( *ch) || isnewline( *ch); ch++ );
			// either have another <con> element or foundVar = false;
			for(i = 0; startCon[i]  == *ch; i++, ch++);
			if(i == 4) foundCon = true;
				else foundCon = false;
		}
		if( (concount == numberOfConstraints - 1) && (foundCon == true) ) {osiltext = &ch[0]; osilerror("attribute numberOfConstraints is less than actual number found"); return false;}
		concount++;
	}
	if(concount < numberOfConstraints) {osiltext = &ch[0]; osilerror("attribute numberOfConstraints is greater than actual number found"); return false;}
	ch -= i;
	// get the </constraints> tag
	for(i = 0; endConstraints[i]  == *ch; i++, ch++);
	if(i != 13) {osiltext = &ch[0]; osilerror( "cannot find </constraints> tag"); return false;}
	for(; ISWHITESPACE( *ch) || isnewline( *ch); ch++ );	
	// better have >
	if(*ch != '>') {osiltext = &ch[0]; osilerror("improperly formed </constraints> tag");	return false;}
	ch++;
	}// end if(numberOfConstraints > 0)
	else{
		// error if the number is negative
		if(numberOfConstraints < 0) {osiltext = &ch[0]; osilerror("cannot have a negative number of constraints"); return false;}
		// if we are here we have numberOfConstraints = 0
		// must close with /> or </constraints>
		// get rid of white space
		for(; ISWHITESPACE( *ch) || isnewline( *ch); ch++ );
		if( *ch == '/'){
			// better have a >
			ch++;
			if( *ch  != '>') {osiltext = &ch[0]; osilerror("improperly closed constraints tag"); return false;}
			ch++;
		}
		else{
			// if we are here we must have an '>' and then  </constraints> tag
			if( *ch  != '>') {osiltext = &ch[0]; osilerror("improperly closed constraints tag"); return false;}
			ch++;
			// burn white space
			for(; ISWHITESPACE( *ch) || isnewline( *ch); ch++ );
			for(i = 0; endConstraints[i]  == *ch; i++, ch++);
			if(i != 13) {osiltext = &ch[0]; osilerror( "cannot find </constraints> tag"); return false; }
			for(; ISWHITESPACE( *ch) || isnewline( *ch); ch++ );	
			// better have >
			if(*ch != '>') {osiltext = &ch[0]; osilerror("improperly formed </constraints> tag"); return false;}	
			ch++;
		}
	}
	finish = clock();
	duration = (double) (finish - start) / CLOCKS_PER_SEC; 
	printf("TIME TO PARSE CONSTRAINTS = %f\n", duration);
	return true;
}//end parseConstraints

bool parseLinearConstraintCoefficients(){
	start = clock();	
	const char *c_numberOfValues = "numberOfValues";
	const char *startlinearConstraintCoefficients = "<linearConstraintCoefficients";
	const char *endlinearConstraintCoefficients = "</linearConstraintCoefficients";
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
	if(i != 14) {osiltext = &ch[0]; osilerror("incorrect numberOfValues attribute in <linearConstraintCoefficients> tag"); return false;}
	// ch should be pointing to the first character after numberOfObjectives
	GETATTRIBUTETEXT;
	ch++;
	numberOfValues = atoimod1( attText, attTextEnd);
	delete [] attText;
	if(numberOfValues <= 0) {osiltext = &ch[0]; osilerror("the number of nonlinear nozeros must be positive"); return false;}
	osinstance->instanceData->linearConstraintCoefficients->numberOfValues = numberOfValues;
	// get rid of white space after the numberOfConstraints element
	for( ; ISWHITESPACE( *ch) || isnewline( *ch); ch++ ) ;
	// we should have either an />  OR an >
	if(*ch == '/'){
		ch++;
		if( *ch++ != '>') {osiltext = &ch[0]; osilerror("the linearConstraintCoefficients element does not have a proper closing"); return false;} 
		else{
			if(numberOfValues > 0) {osiltext = &ch[0]; osilerror("numberOfValues positive, but there are no objectives"); return false;}
			return false;
		}		
	}
	//  we better have an > 
	if( *ch++ != '>') {osiltext = &ch[0]; osilerror("the <linearConstraintCoefficients> element does not have a proper closing"); return false;}
	// get rid of white space after the <linearConstraintCoefficients> element
	for( ; ISWHITESPACE( *ch) || isnewline( *ch); ch++ ) ;
	if( parseStart() != true) return false;
	if( (parseColIdx() != true) && ( parseRowIdx() != true)) return false;
	if( (parseColIdx() != true) && (parseRowIdx() == true) ){osiltext = &ch[0]; osilerror("cannot store by both row and column"); return false;}
	if( parseValue() != true) return false;
	for( ; ISWHITESPACE( *ch) || isnewline( *ch); ch++ ) ;
	// get the </linearConstraintCoefficients> tag
	for(i = 0; endlinearConstraintCoefficients[ i]  == *ch; i++, ch++);
	if(i != 30) {osiltext = &ch[0]; osilerror( "cannot find </linearConstraintCoefficients> tag"); return false;}
	for(; ISWHITESPACE( *ch) || isnewline( *ch); ch++ );	
	// better have >
	if(*ch != '>') {osiltext = &ch[0]; osilerror("improperly formed </linearConstraintCoefficients> tag"); return false;}
	ch++;	
	return true;
}//end parseLinearConstraintCoefficients

bool parseStart(){
	start = clock(); 
	const char* startStart = "<start";
	const char* endStart = "</start";
	const char* startEl = "<el";
	const char* endEl = "</el";
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
	if(*ch != '>') {osiltext = &ch[0]; osilerror("improperly formed <start> element"); return false;}
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
		if( b64string == NULL) {osiltext = &ch[0]; osilerror("<start> must have children or base64 data"); return false;}
		std::string base64decodeddata = Base64::decodeb64( b64string );
		int base64decodeddatalength = base64decodeddata.length();
		int *intvec = NULL;
		osinstance->instanceData->linearConstraintCoefficients->start->el = new int[(base64decodeddatalength/dataSize) ];
		intvec = (int*)&base64decodeddata[0];
		for(i = 0; i < (base64decodeddatalength/dataSize); i++){
			osinstance->instanceData->linearConstraintCoefficients->start->el[ i] = *(intvec++);
		}
		delete [] b64string;
	}
	else{
		foundEl = true;
		osinstance->instanceData->linearConstraintCoefficients->start->el = 
		new int[ std::max( osinstance->instanceData->constraints->numberOfConstraints,
		osinstance->instanceData->variables->numberOfVariables) + 1];
		while(foundEl){
			// start eating white space until an '>' is found,
			for(; ISWHITESPACE( *ch) || isnewline( *ch); ch++ );
			if( *ch++ != '>') {osiltext = &ch[0]; osilerror("improperly formed <el> tag"); return false;}
			// eat white space again,
			for(; ISWHITESPACE( *ch) || isnewline( *ch); ch++ );
			// okay we better have a number, we will check later
			number = ch;
			// find the end of the number, it better be an </el>
			// find </el
			while( *ch != '<' && *ch  != EOF){
				ch++;
			}
			// we better have a <, or not valid
			if(*ch != '<') {osiltext = &ch[0]; osilerror("cannot find an </el>"); return false;}
			osinstance->instanceData->linearConstraintCoefficients->start->el[ kount++] = 
			atoimod1( number, ch);
			ch++;
			//printf("number = %s\n", number);
			// we are pointing to <, make sure there is /el
			for(i = 1; endEl[ i] == *ch; i++, ch++);
			if(i != 4 ) {osiltext = &ch[0]; osilerror("cannot fine an </el>"); return false;}
			// start eating white space until an '>' is found for </el>,
			for(; ISWHITESPACE( *ch) || isnewline( *ch); ch++ ) ;
			if( *ch++ != '>') {osiltext = &ch[0]; osilerror("improperly formed </el> tag"); return false;}
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
	if(i != 7) {osiltext = &ch[0]; osilerror( "cannot find </start> tag"); return false;}
	for(; ISWHITESPACE( *ch) || isnewline( *ch); ch++ );	
	// better have >
	if(*ch != '>') {osiltext = &ch[0]; osilerror("improperly formed </start> tag");	return false;}
	ch++;	
	// get the end element
	finish = clock();
	duration = (double) (finish - start) / CLOCKS_PER_SEC; 
	printf("TIME TO PARSE STARTS  = %f\n", duration);
	return true;
}//end parseSart

bool parseRowIdx(){
	start = clock(); 
	const char* startRowIdx = "<rowIdx";
	const char* endRowIdx = "</rowIdx";
	const char* startEl = "<el";
	const char* endEl = "</el";
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
	if(*ch != '>') {osiltext = &ch[0]; osilerror("improperly formed <rowIdx> element"); return false;}
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
		if( b64string == NULL)  {osiltext = &ch[0]; osilerror("<rowIdx> must have children or base64 data"); return false;}
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
		delete [] b64string;
	}
	else{
		foundEl = true;
		osinstance->instanceData->linearConstraintCoefficients->rowIdx->el = new int[ osinstance->instanceData->linearConstraintCoefficients->numberOfValues];
		osinstance->instanceData->linearConstraintCoefficients->colIdx->el = NULL;
		while(foundEl){
			// start munging white space until an '>' is found,
			for(; ISWHITESPACE( *ch) || isnewline( *ch); ch++ ) ;
			if( *ch++ != '>') {osiltext = &ch[0]; osilerror("improperly formed <el> tag"); return false;}
			// mung white space again,
			for(; ISWHITESPACE( *ch) || isnewline( *ch); ch++ ) ;
			// okay we better have a number, we will check later
			number = ch;
			// find the end of the number, it better be an </el>
			// find </el
			while( *ch != '<' && *ch  != EOF){
				ch++;
			}
			// we better have a <, or not valid
			if(*ch != '<') {osiltext = &ch[0];  osilerror("cannot find an </el>"); return false;}
			osinstance->instanceData->linearConstraintCoefficients->rowIdx->el[ kount++] = 
			atoimod1( number, ch);
			ch++;
			//printf("number = %s\n", number);
			// we are pointing to <, make sure there is /el
			for(i = 1; endEl[ i] == *ch; i++, ch++);
			if(i != 4 ) {osiltext = &ch[0]; osilerror("cannot find an </el>"); return false;}
			// start munging white space until an '>' is found for </el>,
			for(; ISWHITESPACE( *ch) || isnewline( *ch); ch++ );
			if( *ch++ != '>') {osiltext = &ch[0]; osilerror("improperly formed </el> tag"); return false;}
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
	if(i != 8) {osiltext = &ch[0]; osilerror( "cannot find </rowIdx> tag"); return false;}
	for(; ISWHITESPACE( *ch) || isnewline( *ch); ch++ );	
	// better have >
	if(*ch != '>') {osiltext = &ch[0]; osilerror("improperly formed </rowIdx> tag");}	
	ch++;	
	if(kount > osinstance->instanceData->linearConstraintCoefficients->numberOfValues) { osilerror("numberOfLinearCoefficients attribute less than number of row indices found"); return false;}
	if(kount < osinstance->instanceData->linearConstraintCoefficients->numberOfValues) { osilerror("numberOfLinearCoefficients attribute greater than number of row indices found"); return false;}
	finish = clock();
	duration = (double) (finish - start) / CLOCKS_PER_SEC; 
	printf("TIME TO PARSE ROW INDEXES = %f\n", duration);
 return true;
}//end parseRowIdx


bool parseColIdx(){
	start = clock(); 
	const char* startColIdx = "<colIdx";
	const char* endColIdx = "</colIdx";
	const char* startEl = "<el";
	const char* endEl = "</el";
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
	if(*ch != '>') {osiltext = &ch[0]; osilerror("improperly formed <colIdx> element"); return false;}
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
		if( b64string == NULL)  {osiltext = &ch[0]; osilerror("<colIdx> must have children or base64 data"); return false;}
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
		delete [] b64string;
	}
	else{
		foundEl = true;
		osinstance->instanceData->linearConstraintCoefficients->colIdx->el = new int[ osinstance->instanceData->linearConstraintCoefficients->numberOfValues];
		osinstance->instanceData->linearConstraintCoefficients->rowIdx->el = NULL;
		while(foundEl){
			// start eating white space until an '>' is found,
			for(; ISWHITESPACE( *ch) || isnewline( *ch); ch++ ) ;
			if( *ch++ != '>') {osiltext = &ch[0]; osilerror("improperly formed <el> tag"); return false;}
			// eat white space again,
			for(; ISWHITESPACE( *ch) || isnewline( *ch); ch++ ) ;
			// okay we better have a number, we will check later
			number = ch;
			// find the end of the number, it better be an </el>
			// find </el
			while( *ch != '<' && *ch  != EOF){
				ch++;
			}
			// we better have a <, or not valid
			if(*ch != '<') {osiltext = &ch[0]; osilerror("cannot find an </el>"); return false;}
			osinstance->instanceData->linearConstraintCoefficients->colIdx->el[ kount++] = 
			atoimod1( number, ch);
			ch++;
			//printf("number = %s\n", number);
			// we are pointing to <, make sure there is /el
			for(i = 1; endEl[ i] == *ch; i++, ch++);
			if( i != 4 ) {osiltext = &ch[0]; osilerror("cannot fine an </el>"); return false;}
			// start eating white space until an '>' is found for </el>,
			for(; ISWHITESPACE( *ch) || isnewline( *ch); ch++ );
			if( *ch++ != '>') {osiltext = &ch[0]; osilerror("improperly formed </el> tag"); return false;}
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
	if(i != 8) {osiltext = &ch[0]; osilerror( "cannot find </rowIdx> tag"); return false;}
	for(; ISWHITESPACE( *ch) || isnewline( *ch); ch++ );	
	// better have >
	if(*ch != '>') {osiltext = &ch[0]; osilerror("improperly formed </colIdx> tag"); return false;}	
	ch++;	
	if(kount > osinstance->instanceData->linearConstraintCoefficients->numberOfValues) {osiltext = &ch[0]; osilerror("numberOfLinearCoefficients attribute less than number of column indices found"); return false;}
	if(kount < osinstance->instanceData->linearConstraintCoefficients->numberOfValues) {osiltext = &ch[0]; osilerror("numberOfLinearCoefficients attribute greater than number of column indices found"); return false;}
	finish = clock();
	duration = (double) (finish - start) / CLOCKS_PER_SEC; 
	printf("TIME TO PARSE COLUMN INDEXES = %f\n", duration);
 return true;
}//end parseColIdx


bool parseValue(){
	start = clock(); 
	const char* startValue = "<value";
	const char* endValue = "</value";
	const char* startEl = "<el";
	const char* endEl = "</el";
	int kount = 0;
	char* number = NULL;
	int i;
	bool foundEl = false;
	for( ; ISWHITESPACE( *ch) || isnewline( *ch) ; ch++ ) ;
	// if, present we should be pointing to <rowIdx element 
	for(i = 0; startValue[i]  == *ch; i++, ch++){
		//cout << ch* ;
	}
	if(i != 6) {
		//reset ch
		ch -= i;
		return false;
	}
	// get rid of white space after <value
	for( ; ISWHITESPACE( *ch) || isnewline( *ch) ; ch++ ) ;
	// we should have either an >
	if(*ch != '>') {osiltext = &ch[0]; osilerror("improperly formed <value> element"); return false;}
	ch++;
	// get rid of white space
	for( ; ISWHITESPACE( *ch) || isnewline( *ch) ; ch++ ) ;
	// look for an <el> -- if none present must have b64 data
	for(i = 0; startEl[i]  == *ch; i++, ch++);
	if(i != 3) {
		//reset ch
		ch -= i;
		// call base64 parse here
		int dataSize = 0;
		char* b64string = parseBase64(&dataSize );
		if( b64string == NULL)  {osiltext = &ch[0]; osilerror("<start> must have children or base64 data"); return false;};
		std::string base64decodeddata = Base64::decodeb64( b64string );
		int base64decodeddatalength = base64decodeddata.length();
		double *doublevec = NULL;
		osinstance->instanceData->linearConstraintCoefficients->value->el = new double[(base64decodeddatalength/dataSize) ];
		doublevec = (double*)&base64decodeddata[0];
		for(i = 0; i < (base64decodeddatalength/dataSize); i++){
			osinstance->instanceData->linearConstraintCoefficients->value->el[ i] = *(doublevec++);
			kount++;
		}
		delete [] b64string;
	}
	else{
		foundEl = true;
		osinstance->instanceData->linearConstraintCoefficients->value->el = 
			new double[ osinstance->instanceData->linearConstraintCoefficients->numberOfValues];
		while( foundEl){
			// start eat white space until an '>' is found,
			for(; ISWHITESPACE( *ch) || isnewline( *ch) ; ch++ );
			if( *ch++ != '>') {osiltext = &ch[0]; osilerror("improperly formed <el> tag"); return false;}
			// eat white space again,
			for(; ISWHITESPACE( *ch) || isnewline( *ch) ; ch++ ) ;
			number = ch;
			// find the end of the number, it better be an </el>
			// find the < which begins the </el
			while( *ch != '<' && *ch != EOF){
				ch++;
			}
			// we better have a <, or not valid
			if(*ch != '<') {osiltext = &ch[0]; osilerror("cannot find an </el>"); return false;}
			osinstance->instanceData->linearConstraintCoefficients->value->el[ kount++] = 
			atofmod1( number, ch);
			ch++;
			//printf("number = %s\n", number);
			// we are pointing to <, make sure there is /el
			for(i = 1; endEl[ i] == *ch; i++, ch++);
			if( i != 4 ) {osiltext = &ch[0]; osilerror("cannot fine an </el>"); return false;}
			// start eating white space until an '>' is found for </el>,
			for(; ISWHITESPACE( *ch) || isnewline( *ch) ; ch++ );
			if( *ch++ != '>') {osiltext = &ch[0]; osilerror("improperly formed </el> tag"); return false;}
			// eat white space again,
			for(; ISWHITESPACE( *ch) || isnewline( *ch) ; ch++ );
			// either have another <el> element or foundEl = false;
			for(i = 0; startEl[i]  == *ch; i++, ch++);
			if(i == 3) foundEl = true;
			else foundEl = false;
		}	
		ch -= i;
	}
	// get the </value> tag
	for(i = 0; endValue[i]  == *ch; i++, ch++);
	if(i != 7) {osiltext = &ch[0]; osilerror( "cannot find </value> tag"); return false;}
	for(; ISWHITESPACE( *ch) || isnewline( *ch) ; ch++ );	
	// better have >
	if(*ch != '>') {osiltext = &ch[0]; osilerror("improperly formed </value> tag");	 return false;}
	ch++;	
	if(kount < osinstance->instanceData->linearConstraintCoefficients->numberOfValues){osiltext = &ch[0]; osilerror("numberOfLinearCoefficients greater than number of values found"); return false;}
	if(kount > osinstance->instanceData->linearConstraintCoefficients->numberOfValues){osiltext = &ch[0]; osilerror("numberOfLinearCoefficients less than the number of values found"); return false;}
	finish = clock();
	duration = (double) (finish - start) / CLOCKS_PER_SEC; 
	printf("TIME TO PARSE VALUES = %f\n", duration);
	return true;
}//end parseValue

bool parseObjCoef( int objcount){
	const char* startCoef = "<coef";
	const char* endCoef = "</coef";
	const char* c_idx = "idx";
	int kount = 0;
	char* number = NULL;
	char *attText = NULL;
	int i, k;
	int numberOfObjCoef = 0; 
	bool foundCoef = false;
	cout << "NUMBER OF OBJECTIVE FUNCTIONS = " << osinstance->instanceData->objectives->numberOfObjectives << endl;
	if( osinstance->instanceData->objectives->numberOfObjectives <= 0)  {osiltext = &ch[0]; osilerror("we can't have objective function coefficients without an objective function"); return false;}
	numberOfObjCoef = osinstance->instanceData->objectives->obj[objcount]->numberOfObjCoef;
	if(numberOfObjCoef > 0)	{
	for(k = 0; k < numberOfObjCoef; k++){
		for( ; ISWHITESPACE( *ch) || isnewline( *ch); ch++ ) ;
		// if, present we should be pointing to <coef element 
		for(i = 0; startCoef[i]  == *ch; i++, ch++);
		if(i != 5) {osiltext = &ch[0]; osilerror("improper <coef> element"); return false;}
		// get the idx attribute
		// eat the white space after <coef
		for( ; ISWHITESPACE( *ch) || isnewline( *ch); ch++ ) ;
		for(i = 0; c_idx[i]  == *ch; i++, ch++);
		if(i != 3) {osiltext = &ch[0]; osilerror("incorrect idx attribute in objective function <idx> tag"); return false;}	
		// ch should be pointing to the first character after idx attribute
		GETATTRIBUTETEXT;
		osinstance->instanceData->objectives->obj[objcount]->coef[ k]->idx  = atoimod1( attText, attTextEnd);
		delete [] attText;
		ch++;	
		// eat white space
		for( ; ISWHITESPACE( *ch) || isnewline( *ch); ch++ ) ;
		// if we don't have a > there is an error
		if(*ch++ != '>') {osiltext = &ch[0]; osilerror("incorrect <coef> element")	; return false;}	
		// we should be pointing to first character after <coef>
		number = ch;
		// eat characters until we find <
		for(; *ch != '<' && *ch != EOF; ch++); 
		// put back here

		// we should be pointing to a < in the </coef> tag	
		if(*ch != '<') {osiltext = &ch[0]; osilerror("improper </coef> tag"); return false;}
		osinstance->instanceData->objectives->obj[objcount]->coef[ k]->value  = atofmod1( number, ch);
		for(i = 0; endCoef[i]  == *ch; i++, ch++);	
		if(i != 6)  {osiltext = &ch[0]; osilerror("improper </coef> element"); return false;}
		// get rid of white space after </coef
		for( ; ISWHITESPACE( *ch) || isnewline( *ch); ch++ ) ;
		// if we don't have a > there is an error
		if(*ch++ != '>') {osiltext = &ch[0]; osilerror("incorrect </coef> element")	; return false;}
	}
	}// end if(numberOfObjCoef > 0)
	return true;
}//end parseObjCoef

char *parseBase64(int *dataSize ){
	const char *sizeOf = "sizeOf";
	//char *numericType = "numericType";
	const char *startBase64BinaryData = "<base64BinaryData";
	const char *endBase64BinaryData = "</base64BinaryData";
	char *attText = NULL;
	char *b64string = NULL;
	int i;
	int endpoint;
	// start parsing
	for(i = 0; startBase64BinaryData[i]  == *ch; i++, ch++);
	if(i != 17) {
		ch -= i;
		return b64string;
	}
	// find sizeOf attribute
	// eat the white space
	for( ; ISWHITESPACE( *ch) || isnewline( *ch); ch++ ) ;
	for(i = 0; sizeOf[i]  == *ch; i++, ch++);
	if(i != 6) {osiltext = &ch[0]; osilerror("incorrect sizeOf attribute in <base64BinaryData> element"); return false;}	
	// ch should be pointing to the first character after sizeOf
	GETATTRIBUTETEXT;
	ch++;
	*dataSize = atoimod1( attText, attTextEnd);
	delete [] attText;
	// since the element must contain b64 data,  this element must end with > 
	// eat the white space
	for( ; ISWHITESPACE( *ch) || isnewline( *ch); ch++ ) ;
	// better have an > sign or not valid
	if(*ch != '>' ) {osiltext = &ch[0]; osilerror("<base64BinaryData> element does not have a proper closing >"); return false;}
	ch++;
	// we are now pointing start of the data
	char *b64textstart;
	char *b64textend;
	b64textstart = ch;
	// eat characters until we get to the </base64BinaryData element
	for(; *ch != '<' && *ch != EOF; ch++);
	b64textend = ch;
	// we should be pointing to </base64BinaryData>
	for(i = 0; endBase64BinaryData[i]  == *ch; i++, ch++);
	if(i != 18) {osiltext = &ch[0];osilerror(" problem with <base64BinaryData> element"); return false;}
	int b64len = b64textend - b64textstart;
	b64string = new char[ b64len + 1]; 
	for(ki = 0; ki < b64len; ki++) b64string[ki] = b64textstart[ ki]; 
	b64string[ki] = '\0';	
	// burn the white space
	for( ; ISWHITESPACE( *ch) || isnewline( *ch); ch++ ) ;
	// better have an > sign or not valid
	if(*ch != '>' ) {osiltext = &ch[0]; osilerror("</base64BinaryData> element does not have a proper closing >"); return false;}
	ch++;
	for( ; ISWHITESPACE( *ch) || isnewline( *ch); ch++ ) ;
	return b64string;
}


char parseErrorDouble[50]  =  "an invalid value for xsd:double  ";
char parseErrorInteger[50] =  "an invalid value for xsd:int  ";



double atofmod1(char *number, char *numberend){
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
			if(i == exptest) {osiltext = &number[0]; osilerror( strcat(parseErrorDouble, number)); 	}
			val = val*pow(10, expsign*exppower);
			//printf("number = %f\n", val);
		}
	}
	// if we are here we should having nothing but white space until the end of the number
	for( ; ISWHITESPACE( number[ i]) || isnewline( number[ i]) ; i++);
	if(number[i] == *numberend){
		return sign*val;
	}
	else {osiltext = &number[0]; osilerror( strcat(parseErrorDouble, number)); 	return OSNAN;}
}//end atofmod



int atoimod1(char *number, char *numberend){
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
	if(i == endWhiteSpace) {osiltext = number; osilerror( strcat(parseErrorInteger, number)); 	}
	// if we are here we should having nothing but white space until the end of the number
	for( ; ISWHITESPACE( number[ i]) || isnewline( number[ i]) ; i++);
	if(number[i] == *numberend){
		return sign*ival;
	}
	else {osiltext = number; osilerror(strcat(parseErrorInteger, number)); return OSNAN;	}
}//end atoimod1


