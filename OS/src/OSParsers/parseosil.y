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
double atofmod1(const char *ch1, const char *ch2);
int atoimod1(const char *ch1, const char *ch2);
// we distinguish a newline from other whitespace
// since we need to know when we hit a new line
bool isnewline(char c);
bool parseVariables( const char **pchar);
bool parseObjectives( const char **pchar);
bool parseObjCoef( const char **pchar, int objcount);
bool parseConstraints( const char **pchar);
bool parseLinearConstraintCoefficients( const char **pchar);
bool parseStart( const char **pchar);
bool parseRowIdx( const char **pchar);
bool parseColIdx( const char **pchar);
bool parseValue( const char **pchar);
bool parseInstanceHeader(const char **pchar);
bool parseInstanceData(const char **pchar);
char *parseBase64(const char **p, int *dataSize );

const int numErrorChar = 20;
char errorArray[100] = "there was an error";

#define GAIL printf("GAIL ANN HONDA\n")

#define	ISWHITESPACE( char_) ((char_) == ' ' || \
                     (char_) == '\t' ||  (char_) == '\r')

#define	ISDIGIT(_c) ((_c) >= '0' && (_c) <= '9')

#define GETATTRIBUTETEXT  	\
	for(; ISWHITESPACE( *ch) || isnewline( *ch); ch++ ) ; \
	if( *ch != '=') {strncpy(errorArray, ch, numErrorChar); osilerror("found an attribute not defined"); return false;}  \
	ch++; \
	for(; ISWHITESPACE( *ch) || isnewline( *ch); ch++ ) ;	\
	if(*ch != '\"'  && *ch != '\"') {strncpy(errorArray, ch, numErrorChar); osilerror("missing quote on attribute"); return false;} \
	ch++; \
	for(; ISWHITESPACE( *ch) || isnewline( *ch); ch++ ) ; \
	*p = ch; \
	for( ; *ch != '\"' &&  *ch != '\''; ch++); \
	numChar = ch - *p; \
	attText = new char[numChar + 1]; \
	for(ki = 0; ki < numChar; ki++) attText[ki] = *((*p)++); \
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





%token OSILEND INSTANCEDATAEND 
%token VALUEATT NUMBEROFNONLINEAREXPRESSIONS
%token IDXONEATT IDXTWOATT COEFATT IDATT 
%token TIMESSTART TIMESEND NUMBERSTART  NUMBEREND
%token NUMBEROFQTERMSATT IDXATT TYPEATT 
%token QTERMSTART QTERMEND QUADRATICCOEFFICIENTSSTART QUADRATICCOEFFICIENTSEND
%token NONLINEAREXPRESSIONSSTART NONLINEAREXPRESSIONSEND NLSTART NLEND
%token POWERSTART POWEREND PLUSSTART PLUSEND MINUSSTART MINUSEND
%token DIVIDESTART DIVIDEEND LNSTART LNEND SUMSTART SUMEND PRODUCTSTART PRODUCTEND ENDOFELEMENT
%token EXPSTART EXPEND NEGATESTART NEGATEEND IFSTART IFEND
%token GREATERTHAN 
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
	


qtermatt: qtermidxOneatt   quote
			{ if(qtermidxOneattON) osilerror("too many qTerm idxOne attributes"); 
			qtermidxOneattON = true;  }
		| qtermidxTwoatt  quote    
			{ if(qtermidxTwoattON) osilerror("too many qTerm idxTwo attributes"); 
			qtermidxTwoattON = true;  }
		| qtermcoefatt quote
			{ if(qtermcoefattON) osilerror("too many qTerm coef attributes"); 
			qtermcoefattON = true;  }
		| qtermidxatt quote
			{ if(qtermidxattON) osilerror("too many qTerm idx attributes"); 
			qtermidxattON = true;  }
		;


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
		outStr << "Here are " ;
		outStr << numErrorChar ;
		outStr << " characters currently being pointed to in the input string: ";
		outStr << errorArray;
		outStr << endl;
		outStr << "See line number: " << osillineno << endl;  
		error = outStr.str();
		throw ErrorClass( error);
	}
		catch(const ErrorClass& eclass){
		throw ErrorClass(  eclass.errormsg); 
	}
} // end osilerror() 

OSInstance* yygetOSInstance( const char *osil) throw (ErrorClass) {
	try {
		void yyinitialize();
		yyinitialize();
		osinstance = NULL;
		osinstance = new OSInstance();
		parseInstanceHeader( &osil);
		parseInstanceData( &osil);
		// call the flex scanner
		osil_scan_string( osil);
		// call the Bison parser
		if(  osilparse(  ) != 0) throw ErrorClass(  sparseError);
		return osinstance;
	}
	catch(const ErrorClass& eclass){
		throw ErrorClass(  eclass.errormsg); 
	}
}//end yygetOSInstance

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
	int elementSize;
	if(pinstanceHeadStart == NULL) {strncpy(errorArray, pchar, numErrorChar); osilerror("<instanceHeader> element missing"); return false;}
	// increment the line number counter if there are any newlines between the start of
	// the osil string and pinstanceHeadStart
	int	kount = pinstanceHeadStart - pchar;
	while( kount-- > 0) if(*(pchar++) == '\n') 	osillineno++;
	// important! pchar now points to the '<' in <instanceHeader
	// that is both pinstanceHeadStart and pchar point to the same thing
 	// 
 	// move to the end of <instanceHeader
 	pchar+=15;
	// burn any whitespace
	for( ; ISWHITESPACE( *pchar) || isnewline( *pchar); pchar++ ) ;
	// pchar better be pointing to the '>' in the <instanceHeader> element
	// or to /> if we have <instanceHeader />
	if( *pchar == '/'){
		pchar++;
		// better point to a '>'
		if(*pchar != '>') {strncpy(errorArray, pchar, numErrorChar); osilerror("improperly formed <instanceHeader> element"); return false;}
		// there is no instanceHeader data
		pchar++;
		return true;
	}
	else{
		// pchar better be '>' or there is an error
		if(*pchar != '>') {strncpy(errorArray, pchar, numErrorChar); osilerror("improperly formed <instanceHeader> element"); return false;}
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
			if(*pchar != '>') {strncpy(errorArray, pchar, numErrorChar); osilerror("improperly formed <name> element"); return false;}
		}
		else{
			// pchar better be '>' or there is an error
			if(*pchar != '>') {strncpy(errorArray, pchar, numErrorChar); osilerror("improperly formed <name> element"); return false;}
			pchar++;
			// proces <name> element text
			// there better be a </name
			ptemp = strstr( pchar, endName);
			if( ptemp == NULL) {strncpy(errorArray, pchar, numErrorChar); osilerror("improperly formed </name> element"); return false;}
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
			if(*pchar++ != '>'){strncpy(errorArray, pchar, numErrorChar); osilerror("improperly formed </name> element"); return false;}
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
	*p = pchar;
	while(*startSource++  == *pchar) pchar++;
	if(pchar - *p != 7) {
		//reset pchar
		pchar = *p;
	}
	else{
	// we have a source element, process the text
	// burn the whitespace
		for( ; ISWHITESPACE( *pchar) || isnewline( *pchar); pchar++ ) ;	
		if( *pchar == '/'){
			pchar++;
			// better point to a '>'
			if(*pchar != '>') {strncpy(errorArray, pchar, numErrorChar); osilerror("improperly formed <source> element"); return false;}
		}
		else{
			// pchar better be '>' or there is an error
			if(*pchar != '>') {strncpy(errorArray, pchar, numErrorChar); osilerror("improperly formed <source> element"); return false;}
			pchar++;
			// proces <source> element text
			// there better be a </source
			ptemp = strstr( pchar, endSource);
			if( ptemp == NULL) {strncpy(errorArray, pchar, numErrorChar); osilerror("improperly formed </source> element"); return false;}
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
			if(*pchar++ != '>'){strncpy(errorArray, pchar, numErrorChar); osilerror("improperly formed </source> element"); return false;}
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
	*p = pchar;
	while(*startDescription++  == *pchar) pchar++;
	if( (pchar - *p) != 12) {
		//reset pchar
		pchar = *p;
	}
	else{
	// we have a description element, process the text
	// burn the whitespace
		for( ; ISWHITESPACE( *pchar) || isnewline( *pchar); pchar++ ) ;	
		if( *pchar == '/'){
			pchar++;
			// better point to a '>'
			if(*pchar != '>') {strncpy(errorArray, pchar, numErrorChar); osilerror("improperly formed <description> element"); return false;}
		}
		else{
			// pchar better be '>' or there is an error
			if(*pchar != '>') {strncpy(errorArray, pchar, numErrorChar); osilerror("improperly formed <description> element"); return false;}
			pchar++;
			// proces <source> element text
			// there better be a </description
			ptemp = strstr( pchar, endDescription);
			if( ptemp == NULL) {strncpy(errorArray, pchar, numErrorChar); osilerror("improperly formed </description> element"); return false;}
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
			if(*pchar++ != '>'){strncpy(errorArray, pchar, numErrorChar); osilerror("improperly formed </description> element"); return false;}
		}
	}// end of else after discovering a description element
	//done processing <description> element
	//
	// if we are here there must be an </instanceHeader > element
	// burn the whitespace
	for( ; ISWHITESPACE( *pchar) || isnewline( *pchar); pchar++ ) ;	
	// we should be pointing to </instanceHeader
	*p = pchar;
	while(*endInstanceHeader++  == *pchar) pchar++;
	if( (pchar - *p) != 16) {strncpy(errorArray, pchar, numErrorChar); osilerror("improperly formed </instanceHeader> element"); return false;}	
	// pchar now points to the first character after </instanceHeader
	// get rid of white space
	for( ; ISWHITESPACE( *pchar) || isnewline( *pchar); pchar++ ) ;	
	// pchar must point to '>' or there is an error
	if(*pchar != '>'){strncpy(errorArray, pchar, numErrorChar); osilerror("improperly formed </instanceHeader> element"); return false;}	
	pchar++;
	*p = pchar;
	return true;
}//end parseInstanceHeader


bool parseInstanceData( const char **p){
	//
	const char *pchar = *p;
	const char *startInstanceData = "<instanceData";
	// at his point *pchar should be pointing to the first char after the > in </instanceHeader>
	// burn the white space
	for( ; ISWHITESPACE( *pchar) || isnewline( *pchar); pchar++ ) ;	
	// pchar should be point to a '<', if not there is an error
	if(*pchar != '<'){strncpy(errorArray, pchar, numErrorChar); osilerror("improperly formed <instanceData element"); return false;}
	// make sure the element is <instanceData	
	*p = pchar;
	while(*startInstanceData++  == *pchar) pchar++;
	if( (pchar - *p) != 13) {strncpy(errorArray, pchar, numErrorChar); osilerror("improperly formed <instanceData> element"); return false;}	
	// now burn whitespace
	// pchar must point to '>' or there is an error
	if(*pchar != '>'){strncpy(errorArray, pchar, numErrorChar); osilerror("improperly formed <instanceData> element"); return false;}	
	pchar++;
	// we are now pointing to the first char after <instanceData>
	// burn any whitespace
	for( ; ISWHITESPACE( *pchar) || isnewline( *pchar); pchar++ ) ;	
	// we should be pointing to the '<' char in <varaibles>
	*p = pchar;
	if( parseVariables( p) != true) {throw ErrorClass("error in parse variables");}
	if( parseObjectives( p) != true)  throw ErrorClass("error in parse objectives");
	if( parseConstraints( p) != true) throw ErrorClass("error in parse Constraints");
	if( parseLinearConstraintCoefficients( p) != true) throw ErrorClass("error in parse ConstraintCoefficients");	
	//
	return true;
}// end parseInstanceData


bool parseVariables( const char **p){
	const char *ch = *p;
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
	*p = ch;
	while(*startVariables++  == *ch) ch++;
	if( (ch - *p) != 10) {strncpy(errorArray, ch, numErrorChar); osilerror("incorrect <variables tag>"); return false;}
	// find numberOfVariables attribute
	// eat the white space
	for( ; ISWHITESPACE( *ch) || isnewline( *ch); ch++ ) ;
	*p = ch;
	while(*c_numberOfVariables++  == *ch) ch++;
	if( (ch - *p) != 17) {strncpy(errorArray, ch, numErrorChar); osilerror("incorrect numberOfVariables attribute in <variables tag>"); return false;}	
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
	if(*ch != '>' ) {strncpy(errorArray, ch, numErrorChar); osilerror("variables element does not have a proper closing >"); return false;}
	ch++;
	// get rid of white space
	for( ; ISWHITESPACE( *ch) || isnewline( *ch); ch++ ) ;
	// now loop over the var elements, there must be at least one var element
	*p = ch;                                            
	while(*startVar++  == *ch) ch++;
	if( (ch - *p) ==  4) foundVar = true;
		else {strncpy(errorArray, ch, numErrorChar); osilerror("there must be at least one <var> element"); return false;}
	startVar -= 5;
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
				*p = ch;
				while(*name++  == *ch) ch++;
				if( (ch - *p) != 4 ) {strncpy(errorArray, ch, numErrorChar); osilerror("error in variables name attribute"); return false;}
				name -= 5;
				if(varnameattON == true) {strncpy(errorArray, ch, numErrorChar); osilerror("error too many variable name attributes"); return false;}
				varnameattON = true;
				GETATTRIBUTETEXT;
				osinstance->instanceData->variables->var[varcount]->name=attText;
				delete [] attText;
				//printf("ATTRIBUTE = %s\n", attText);
				break;
			case 'i':
				*p = ch;
				while(*initString++  == *ch) ch++;
				// if i < 4 there is an error
				// if i = 4 we matched init
				// if i = 10 we matched initString
				if( ( (ch - *p) != 4)  && (i != 10)) {strncpy(errorArray, ch, numErrorChar); osilerror("error in variables init or initString attribute"); return false;}
				if((ch - *p) == 4){
					if(varinitattON == true) {strncpy(errorArray, ch, numErrorChar); osilerror("error too many variable init attributes"); return false;}
					varinitattON = true;
					GETATTRIBUTETEXT;
					//printf("ATTRIBUTE = %s\n", attText);
					osinstance->instanceData->variables->var[varcount]->init=atofmod1(attText, attTextEnd);
					delete [] attText;
					initString -= 5;
				}
				else{
					if(varinitStringattON == true) {strncpy(errorArray, ch, numErrorChar); osilerror("error too many variable initString attributes"); return false;}
					varinitStringattON = true;
					GETATTRIBUTETEXT;
					delete [] attText;
					//printf("ATTRIBUTE = %s\n", attText);
					osinstance->instanceData->variables->var[varcount]->initString=attText;
					initString -= 11;
				}
				break;
			case 't':
				*p = ch;
				while(*type++  == *ch) ch++;
				if( (ch - *p) != 4) {strncpy(errorArray, ch, numErrorChar); osilerror("error in variables type attribute"); return false;}
				type -= 5;
				if(vartypeattON == true) {strncpy(errorArray, ch, numErrorChar); osilerror("error too many variable type attributes"); return false;}
				vartypeattON = true;
				GETATTRIBUTETEXT;
				if( strchr("CBIS", attText[0]) == NULL ) {strncpy(errorArray, ch, numErrorChar); osilerror("variable type not C,B,I, or S"); return false;}
				osinstance->instanceData->variables->var[varcount]->type = attText[0];
				delete [] attText;
				break;
			case 'l':
				ch++;
				if(*ch++ != 'b') {strncpy(errorArray, ch, numErrorChar); osilerror("error in variables lower bound attribute"); return false;}
				if(varlbattON == true) {strncpy(errorArray, ch, numErrorChar); osilerror("error too many variable lb attributes"); return false;}
				varlbattON = true;
				GETATTRIBUTETEXT;
				osinstance->instanceData->variables->var[varcount]->lb = atofmod1(attText, attTextEnd);
				delete [] attText;
				//printf("ATTRIBUTE = %s\n", attText);
				break;
			case 'u':
				ch++;
				if(*ch++ != 'b') {strncpy(errorArray, ch, numErrorChar); osilerror("error in variables upper bound attribute"); return false;}
				if(varubattON == true) {strncpy(errorArray, ch, numErrorChar); osilerror("error too many variable ub attributes"); return false;}
				varubattON = true;
				GETATTRIBUTETEXT;
				osinstance->instanceData->variables->var[varcount]->ub = atofmod1(attText, attTextEnd);
				delete [] attText;
				//printf("ATTRIBUTE = %s\n", attText);
				break;
			case 'm':
				*p = ch;
				while(*mult++  == *ch) ch++;
				if( (ch - *p) != 4) {strncpy(errorArray, ch, numErrorChar); osilerror("error in variables mult attribute"); return false;}
				mult -= 5;
				if(varmultattON == true) {strncpy(errorArray, ch, numErrorChar); osilerror("error too many variable mult attributes"); return false;}
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
				{strncpy(errorArray, ch, numErrorChar); osilerror("invalid attribute character"); return false;}
				break;
			}
			ch++;
		}
		//
		// assume all the attributes have been processed
		// must have either /> or > and then whitespace and </var whitespace>
		if( *ch != '/' && *ch != '>') {strncpy(errorArray, ch, numErrorChar); osilerror("incorrect end of <var> element"); return false;}
		if(*ch == '/'){
			ch++;
			if(*ch != '>') {strncpy(errorArray, ch, numErrorChar); osilerror("incorrect end of <var> element"); return false;}
			// get rid of whitespace
			ch++;
			for(; ISWHITESPACE( *ch) || isnewline( *ch); ch++ );
			// either have another <var> element or foundVar = false;
			*p = ch;
			while(*startVar++  == *ch) ch++;
			if( (ch - *p) == 4) {
				foundVar = true;
				startVar -= 5;
			}
			else {
				foundVar = false;
				ch = *p;
			}
		}
		else{
			// the buf_index is the > at the end of the var element 
			// double check to make sure it really is a >
			if(*ch != '>') {strncpy(errorArray, ch, numErrorChar); osilerror("improper ending to a <var> element"); return false;}
			// look for </var
			// fist get rid of white space
			ch++;
			for(; ISWHITESPACE( *ch) || isnewline( *ch); ch++ );
			// we should be at </var or there is an error
			*p = ch;
			while(*endVar++  == *ch) ch++;
			endVar -= 6;
			if( (ch - *p) != 5) {strncpy(errorArray, ch, numErrorChar); osilerror("</var> element missing"); return false;}
			// burn off the whitespace
			for(; ISWHITESPACE( *ch) || isnewline( *ch); ch++ );
			// better have an > to end </var
			if(*ch++ != '>') {strncpy(errorArray, ch, numErrorChar); osilerror("</var> element missing >"); return false;}
			// look for a new <var> element
			// get rid of whitespace
			ch++;
			for(; ISWHITESPACE( *ch) || isnewline( *ch); ch++ );
			// either have another <var> element or foundVar = false;
			*p = ch;
			while(*startVar++  == *ch) ch++;
			if( (ch - *p) == 4) {
				foundVar = true;
				startVar -= 5;
			}
			else {
				foundVar = false;
				ch = *p;
			}
		}
		if( (varcount == numberOfVariables - 1) && (foundVar == true) ) {strncpy(errorArray, ch, numErrorChar);  osilerror("attribute numberOfVariables is less than actual number found");  return false;}
		varcount++;
	}
	if(varcount < numberOfVariables) {strncpy(errorArray, ch, numErrorChar); osilerror("attribute numberOfVariables is greater than actual number found");   return false;}
	// get the </variables> tag
	*p = ch;
	while(*endVariables++  == *ch) ch++;
	if( (ch - *p) != 11) {strncpy(errorArray, ch, numErrorChar);  osilerror("cannot find </varialbes> tag"); return false;}
	for(; ISWHITESPACE( *ch) || isnewline( *ch); ch++ );	
	// better have >
	if(*ch != '>') {strncpy(errorArray, ch, numErrorChar);  osilerror("improperly formed </variables> tag"); return false;}
	ch++;
	finish = clock();
	duration = (double) (finish - start) / CLOCKS_PER_SEC; 
	printf("TIME TO PARSE VARIABLES = %f\n", duration);
	*p = ch;
	return true;
}//end parseVariables


bool parseObjectives( const char **p){
	const char *ch = *p;
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
	*p = ch;
	while( *startObjectives++  == *ch) ch++;
	if( (ch - *p) != 11) {
		//  note if we are here even though ch > *p we want to return *p
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
		*p = ch;
		while( *c_numberOfObjectives++  == *ch) ch++;
		if( (ch - *p) != 18) {strncpy(errorArray, ch, numErrorChar); osilerror("incorrect numberOfObjectives attribute in <objectives> tag"); return false;}	
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
			if( *ch++ != '>') {strncpy(errorArray, ch, numErrorChar); osilerror("the objectives element does not have a proper closing"); return false; }
			else{
				if(numberOfObjectives > 0){strncpy(errorArray, ch, numErrorChar);  osilerror("numberOfObjectives positive but there are no objectives"); return false;}
				return false;
			}
		}*/
		//  we better have an > 
		if( *ch++ != '>') {strncpy(errorArray, ch, numErrorChar); osilerror("the objectives element does not have a proper closing"); return false;} 
		osinstance->instanceData->objectives->numberOfObjectives = numberOfObjectives;
		osinstance->instanceData->objectives->obj = new Objective*[ numberOfObjectives];
		for(i = 0; i < numberOfObjectives; i++){
			osinstance->instanceData->objectives->obj[ i] = new Objective();
		} 	
	// get rid of white space after the <objectives> element
	for( ; ISWHITESPACE( *ch) || isnewline( *ch); ch++ ) ;
	// now loop over the obj elements, there must be at least one obj element
	*p = ch;
	while( *startObj++  == *ch) ch++;
	if( (ch - *p) == 4) foundObj = true;
		else {strncpy(errorArray, ch, numErrorChar); osilerror("there must be at least one <obj> element"); return false;}
	startObj -= 5;
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
					*p = ch;
					while( *numberOfObjCoef++  == *ch) ch++;
					numberOfObjCoef -= 16;
					if( ( (ch - *p) != 15)  ) {strncpy(errorArray, ch, numErrorChar); osilerror("error in objective numberOfObjCoef attribute"); return false;}
					else{
						if(objnumberOfObjCoefattON == true) {strncpy(errorArray, ch, numErrorChar); osilerror("error too many obj numberOfObjCoefatt attributes"); return false;}
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
					*p = ch;
					while( *name++  == *ch) ch++;
					name -= 5;
					if( ( (ch - *p) != 4)  ) {strncpy(errorArray, ch, numErrorChar); osilerror("error in objective name attribute"); return false;}
					else{
						if(objnameattON == true) {strncpy(errorArray, ch, numErrorChar); osilerror("error too many obj name attributes"); return false;}
						objnameattON = true;
						GETATTRIBUTETEXT;
						//printf("ATTRIBUTE = %s\n", attText);
						osinstance->instanceData->objectives->obj[objcount]->name=attText;
						delete [] attText;
					}
				}
				break;
			case 'c':
				*p = ch;
				while( *constant++  == *ch) ch++;
				constant -= 9;	
				if( ( (ch - *p) != 8)  ) {strncpy(errorArray, ch, numErrorChar); osilerror("error in objective constant attribute"); return false;}
				else{
					if(objconstantattON == true) {strncpy(errorArray, ch, numErrorChar); osilerror("error too many obj constant attributes"); return false;}
					objconstantattON = true;
					GETATTRIBUTETEXT;
					//printf("ATTRIBUTE = %s\n", attText);
					osinstance->instanceData->objectives->obj[objcount]->constant=atofmod1(attText, attTextEnd);
					delete [] attText;
				}
				break;
			case 'w':
				*p = ch;
				while( *weight++  == *ch) ch++;
				weight -= 7;
				if( ( (ch - *p) != 6)  ) {strncpy(errorArray, ch, numErrorChar); osilerror("error in objective weight attribute"); return false;}
				else{
					if(objweightattON == true) {strncpy(errorArray, ch, numErrorChar); osilerror("error too many obj weight attributes"); return false;}
					objweightattON = true;
					GETATTRIBUTETEXT;
					//printf("ATTRIBUTE = %s\n", attText);
					osinstance->instanceData->objectives->obj[objcount]->weight=atofmod1(attText, attTextEnd);
					delete [] attText;
				}
				break;
			case 'm':
				if(*(ch+1) == 'a'){
					*p = ch;
					while( *maxOrMin++  == *ch) ch++;
					maxOrMin -= 9;
					if( ( ( ch - *p)  != 8)  ) {strncpy(errorArray, ch, numErrorChar); osilerror("error in objective maxOrMin attribute"); return false;}
					else{
						if(objmaxOrMinattON == true) {strncpy(errorArray, ch, numErrorChar); osilerror("error too many obj maxOrMin attributes"); return false;}
						objmaxOrMinattON = true;
						GETATTRIBUTETEXT;
						//printf("ATTRIBUTE = %s\n", attText);
						if( (strcmp("max", attText) != 0 ) && (strcmp("min", attText) != 0 ) ){osilerror("maxOrMin attribute in objective must be a max or min"); return false;}
						osinstance->instanceData->objectives->obj[objcount]->maxOrMin = attText;
						delete [] attText;
					}
				}
				else{
					*p = ch;
					while( *mult++  == *ch) ch++;
					mult -= 5;
					if( ( (ch - *p) != 4)  ) {strncpy(errorArray, ch, numErrorChar); osilerror("error in objective mult attribute"); return false;}
					else{
						if(objmultattON == true) {strncpy(errorArray, ch, numErrorChar); osilerror("error too many obj mult attributes"); return false;}
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
				strncpy(errorArray, ch, numErrorChar);
				osilerror("invalid attribute character");
				return false;
				break;
			}
			ch++;
		}
		//
		// assume all the attributes have been processed
		// must have either /> or > and then whitespace and </obj whitespace>
		if( *ch != '/' && *ch != '>') {strncpy(errorArray, ch, numErrorChar);  osilerror("incorrect end of <obj> element"); return false;}
		if(*ch == '/'){
			ch++;
			if(*ch != '>') {strncpy(errorArray, ch, numErrorChar); osilerror("incorrect end of <obj> element"); return false;}
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
			if(*ch != '>') {strncpy(errorArray, ch, numErrorChar); osilerror("improper ending to a <obj> element"); return false;}
			// look for </obj
			// fist get rid of white space
			ch++;
			// first get the <coef> elements
			parseObjCoef(&ch,  objcount);
			for(; ISWHITESPACE( *ch) || isnewline( *ch); ch++ );
			// we should be at </obj or there is an error
			for(i = 0; endObj[i]  == *ch; i++, ch++);
			if(i != 5) {strncpy(errorArray, ch, numErrorChar); osilerror("</obj> element missing"); return false;}
			// burn off the whitespace
			for(; ISWHITESPACE( *ch) || isnewline( *ch); ch++ );
			// better have an > to end </obj
			if(*ch++ != '>'){strncpy(errorArray, ch, numErrorChar);  osilerror("</obj> element missing >"); return false;}
			// look for a new <obj> element
			// get rid of whitespace
			for(; ISWHITESPACE( *ch) || isnewline( *ch); ch++ );
			// either have another <obj> element or foundObj = false;
			for(i = 0; startObj[i]  == *ch; i++, ch++);
			if(i == 4) foundObj = true;
				else foundObj = false;
		}
		if( (objcount == numberOfObjectives - 1) && (foundObj == true)) {strncpy(errorArray, ch, numErrorChar); osilerror("attribute numberOfObjectives is less than actual number found"); return false;}
		objcount++;
	}
	if(objcount < numberOfObjectives) {strncpy(errorArray, ch, numErrorChar); osilerror("attribute numberOfObjectives is greater than actual number found"); return false;}
	ch -= i;
	// get the </objectives> tag
	for(i = 0; endObjectives[i]  == *ch; i++, ch++);
	if(i != 12) {strncpy(errorArray, ch, numErrorChar); osilerror( "cannot find </objectives> tag"); return false; }
	for(; ISWHITESPACE( *ch) || isnewline( *ch); ch++ );	
	// better have >
	if(*ch != '>') {strncpy(errorArray, ch, numErrorChar); osilerror("improperly formed </objectives> tag"); return false;}	
	ch++;
	} // finish the (if numberOfObjectives > 0)
	else{
		// error if the number is negative
		if(numberOfObjectives < 0) {strncpy(errorArray, ch, numErrorChar); osilerror("cannot have a negative number of objectives"); return false;}
		// if we are here we have exactly 0 objectives 
		// must close with /> or </objectives>
		// get rid of white space
		for(; ISWHITESPACE( *ch) || isnewline( *ch); ch++ );
		if( *ch == '/'){
			// better have a >
			ch++;
			if( *ch  != '>') {strncpy(errorArray, ch, numErrorChar); osilerror("improperly closed objectives tag"); return false;}
			ch++;
		}
		else{
			// if we are here we must have an '>' and then  </objectives> tag
			if( *ch  != '>') {strncpy(errorArray, ch, numErrorChar); osilerror("improperly closed objectives tag"); return false;}
			ch++;
			// burn white space
			for(; ISWHITESPACE( *ch) || isnewline( *ch); ch++ );
			for(i = 0; endObjectives[i]  == *ch; i++, ch++);
			if(i != 12) {strncpy(errorArray, ch, numErrorChar); osilerror( "cannot find </objectives> tag"); return false; }
			for(; ISWHITESPACE( *ch) || isnewline( *ch); ch++ );	
			// better have >
			if(*ch != '>') {strncpy(errorArray, ch, numErrorChar); osilerror("improperly formed </objectives> tag"); return false;}	
			ch++;
		}
	}
	finish = clock();
	duration = (double) (finish - start) / CLOCKS_PER_SEC; 
	printf("TIME TO PARSE OBJECTIVES = %f\n", duration);
	*p = ch;
	return true;
}//end parseObjectives

bool parseConstraints( const char **p){
	const char *ch = *p;
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
	*p = ch;
	for(i = 0; startConstraints[i]  == *ch; i++, ch++);
	while( *startConstraints++  == *ch) ch++;
	if( (ch - *p) != 12) {
		//  *p is the correct value for the pointer
		return true;
	}
	// find numberOfConstraints attribute
	// eat the white space
	for( ; ISWHITESPACE( *ch) || isnewline( *ch); ch++ ) ;
	*p = ch;
	while( *c_numberOfConstraints++  == *ch) ch++;
	if( (ch - *p) != 19) {strncpy(errorArray, ch, numErrorChar); osilerror("incorrect numberOfConstraints attribute in <constraints> tag"); return false;}	
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
	if( *ch++ != '>') {strncpy(errorArray, ch, numErrorChar);  osilerror("the constraints element does not have a proper closing"); return false;} 
	// get rid of white space after the <constraints> element
	for( ; ISWHITESPACE( *ch) || isnewline( *ch); ch++ ) ;
	// now loop over the con elements, there must be at least one con element
	*p = ch;
	while( *startCon++  == *ch) ch++;
	if( (ch - *p) == 4) foundCon = true;
		else {strncpy(errorArray, ch, numErrorChar); osilerror("there must be at least one <con> element"); return false;}
	startCon -= 5;
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
				*p = ch;
				while( *name++  == *ch) ch++;
				if( (ch - *p) != 4) {strncpy(errorArray, ch, numErrorChar); osilerror("error in constraints name attribute"); return false;}
				if(connameattON == true) {strncpy(errorArray, ch, numErrorChar); osilerror("error too many con name attributes"); return false;}
				name -= 5;
				connameattON = true;
				GETATTRIBUTETEXT;
				osinstance->instanceData->constraints->con[concount]->name=attText;
				delete [] attText;
				//printf("ATTRIBUTE = %s\n", attText);
				break;
			case 'c':
				*p = ch;
				while( *constant++  == *ch) ch++;
				if( ((ch - *p)  != 8)  ) {strncpy(errorArray, ch, numErrorChar); osilerror("error in constraint constant attribute"); return false;}
				if(conconstantattON == true) {strncpy(errorArray, ch, numErrorChar); osilerror("error too many con constant attributes"); return false;}
				constant -= 9;
				conconstantattON = true;
				GETATTRIBUTETEXT;
				//printf("ATTRIBUTE = %s\n", attText);
				osinstance->instanceData->constraints->con[concount]->constant=atofmod1(attText, attTextEnd);
				delete [] attText;
				break;
			case 'l':
				ch++;
				if(*ch++ != 'b') { strncpy(errorArray, ch, numErrorChar); osilerror("error in constraint lb attribute"); return false;}
				if(conlbattON == true) {strncpy(errorArray, ch, numErrorChar); osilerror("error too many con lb attributes"); return false;}
				conlbattON = true;
				GETATTRIBUTETEXT;
				osinstance->instanceData->constraints->con[concount]->lb = atofmod1(attText, attTextEnd);
				delete [] attText;
				//printf("ATTRIBUTE = %s\n", attText);
				break;
			case 'u':
				ch++;
				if(*ch++ != 'b') {strncpy(errorArray, ch, numErrorChar); osilerror("error in constraint ub attribute"); return false;}
				if(conubattON == true) {strncpy(errorArray, ch, numErrorChar); osilerror("error too many con ub attributes"); return false;}
				conubattON = true;
				GETATTRIBUTETEXT;
				osinstance->instanceData->constraints->con[concount]->ub = atofmod1(attText, attTextEnd);
				delete [] attText;
				//printf("ATTRIBUTE = %s\n", attText);
				break;
			case 'm':
				*p = ch;
				while( *mult++  == *ch) ch++;
				if( (ch - *p) != 4) {strncpy(errorArray, ch, numErrorChar); osilerror("error in constraints mult attribute"); return false;}
				if(conmultattON == true) {strncpy(errorArray, ch, numErrorChar); osilerror("error too many con mult attributes"); return false;}
				mult -= 5;
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
				strncpy(errorArray, ch, numErrorChar);
				osilerror("invalid attribute character");
				return false;
				break;
			}
			ch++;
		}
		//
		// assume all the attributes have been processed
		// must have either /> or > and then whitespace and </con whitespace>
		if( *ch != '/' && *ch != '>') {strncpy(errorArray, ch, numErrorChar); osilerror("incorrect end of <con> element"); return false;}
		if(*ch == '/'){
			ch++;
			if(*ch != '>') {strncpy(errorArray, ch, numErrorChar); osilerror("incorrect end of <con> element"); return false;}
			// get rid of whitespace
			ch++;
			for(; ISWHITESPACE( *ch) || isnewline( *ch); ch++ );
			// either have another <con> element or foundCon = false;
			*p = ch;
			while( *startCon++  == *ch) ch++;
			if( (ch - *p) == 4){
			 	foundCon = true;
			 	startCon -= 5;
			}
			else{
				foundCon = false;
				ch = *p;
			}
		}
		else{
			// the ch is the > at the end of the con element 
			// double check to make sure it really is a >
			if(*ch != '>') {strncpy(errorArray, ch, numErrorChar); osilerror("improper ending to a <obj> element"); return false;}
			// look for </con
			// fist get rid of white space
			ch++;
			for(; ISWHITESPACE( *ch) || isnewline( *ch); ch++ );
			// we should be at </con or there is an error
			*p = ch;
			while( *endCon++  == *ch) ch++;
			if( (ch - *p) != 5) {strncpy(errorArray, ch, numErrorChar); osilerror("</con> element missing"); return false;}
			endCon -= 6;
			// burn off the whitespace
			for(; ISWHITESPACE( *ch) || isnewline( *ch); ch++ );
			// better have an > to end </con
			if(*ch++ != '>') {strncpy(errorArray, ch, numErrorChar); osilerror("</con> element missing >"); return false;}
			// look for a new <con> element
			// get rid of whitespace
			ch++;
			for(; ISWHITESPACE( *ch) || isnewline( *ch); ch++ );
			// either have another <con> element or foundVar = false;
			*p = ch;
			while( *startCon++  == *ch) ch++;
			if( (ch - *p) == 4){
			 	foundCon = true;
			 	startCon -= 5;
			}
			else{
			 	foundCon = false;
			 	ch = *p;
			}
		}
		if( (concount == numberOfConstraints - 1) && (foundCon == true) ) {strncpy(errorArray, ch, numErrorChar); osilerror("attribute numberOfConstraints is less than actual number found"); return false;}
		concount++;
	}
	if(concount < numberOfConstraints) {strncpy(errorArray, ch, numErrorChar); osilerror("attribute numberOfConstraints is greater than actual number found"); return false;}
	// get the </constraints> tag
	*p = ch;
	while( *endConstraints++  == *ch) ch++;
	if( (ch - *p) != 13) {strncpy(errorArray, ch, numErrorChar); osilerror( "cannot find </constraints> tag"); return false;}
	for(; ISWHITESPACE( *ch) || isnewline( *ch); ch++ );	
	// better have >
	if(*ch != '>') {strncpy(errorArray, ch, numErrorChar); osilerror("improperly formed </constraints> tag");	return false;}
	ch++;
	}// end if(numberOfConstraints > 0)
	else{
		// error if the number is negative
		if(numberOfConstraints < 0) {strncpy(errorArray, ch, numErrorChar); osilerror("cannot have a negative number of constraints"); return false;}
		// if we are here we have numberOfConstraints = 0
		// must close with /> or </constraints>
		// get rid of white space
		for(; ISWHITESPACE( *ch) || isnewline( *ch); ch++ );
		if( *ch == '/'){
			// better have a >
			ch++;
			if( *ch  != '>') {strncpy(errorArray, ch, numErrorChar); osilerror("improperly closed constraints tag"); return false;}
			ch++;
		}
		else{
			// if we are here we must have an '>' and then  </constraints> tag
			if( *ch  != '>') {strncpy(errorArray, ch, numErrorChar); osilerror("improperly closed constraints tag"); return false;}
			ch++;
			// burn white space
			for(; ISWHITESPACE( *ch) || isnewline( *ch); ch++ );
			*p = ch;
			while( *endConstraints++  == *ch) ch++;
			if( (ch - *p) != 13) {strncpy(errorArray, ch, numErrorChar); osilerror( "cannot find </constraints> tag"); return false; }
			for(; ISWHITESPACE( *ch) || isnewline( *ch); ch++ );	
			// better have >
			if(*ch != '>') {strncpy(errorArray, ch, numErrorChar); osilerror("improperly formed </constraints> tag"); return false;}	
			ch++;
		}
	}
	finish = clock();
	duration = (double) (finish - start) / CLOCKS_PER_SEC; 
	printf("TIME TO PARSE CONSTRAINTS = %f\n", duration);
	*p = ch;
	return true;
}//end parseConstraints

bool parseLinearConstraintCoefficients( const char **p){
	const char *ch = *p;
	start = clock();	
	const char *c_numberOfValues = "numberOfValues";
	const char *startlinearConstraintCoefficients = "<linearConstraintCoefficients";
	const char *endlinearConstraintCoefficients = "</linearConstraintCoefficients";
	// attributes
	char *attText = NULL;
	// others
	int numberOfValues;
	// start parsing
	// burn white space
	for( ; ISWHITESPACE( *ch) || isnewline( *ch); ch++ ) ;
	// if, present we should be pointing to <linearConstraintCoefficients element if there -- it is not required
	*p = ch;
	while( *startlinearConstraintCoefficients++  == *ch) ch++;
	if( (ch - *p) != 29) {
		//reset ch
		ch = *p;
		return false;
	}
	// find numberOfValues attribute
	// eat the white space
	for( ; ISWHITESPACE( *ch) || isnewline( *ch); ch++ ) ;
	*p = ch;
	while( *c_numberOfValues++  == *ch) ch++;
	if( (ch - *p) != 14) {strncpy(errorArray, ch, numErrorChar); osilerror("incorrect numberOfValues attribute in <linearConstraintCoefficients> tag"); return false;}
	// ch should be pointing to the first character after numberOfObjectives
	GETATTRIBUTETEXT;
	ch++;
	numberOfValues = atoimod1( attText, attTextEnd);
	delete [] attText;
	if(numberOfValues <= 0) {strncpy(errorArray, ch, numErrorChar); osilerror("the number of nonlinear nozeros must be positive"); return false;}
	osinstance->instanceData->linearConstraintCoefficients->numberOfValues = numberOfValues;
	// get rid of white space after the numberOfConstraints element
	for( ; ISWHITESPACE( *ch) || isnewline( *ch); ch++ ) ;
	// we should have either an />  OR an >
	if(*ch == '/'){
		ch++;
		if( *ch++ != '>') {strncpy(errorArray, ch, numErrorChar); osilerror("the linearConstraintCoefficients element does not have a proper closing"); return false;} 
		else{
			if(numberOfValues > 0) {strncpy(errorArray, ch, numErrorChar); osilerror("numberOfValues positive, but there are no objectives"); return false;}
			return false;
		}		
	}
	//  we better have an > 
	if( *ch++ != '>') {strncpy(errorArray, ch, numErrorChar); osilerror("the <linearConstraintCoefficients> element does not have a proper closing"); return false;}
	// get rid of white space after the <linearConstraintCoefficients> element
	for( ; ISWHITESPACE( *ch) || isnewline( *ch); ch++ ) ;
	if( parseStart( &ch) != true) return false;
	if( (parseColIdx( &ch) != true) && ( parseRowIdx( &ch) != true)) return false;
	if( (parseColIdx( &ch) != true) && (parseRowIdx( &ch) == true) ){strncpy(errorArray, ch, numErrorChar); osilerror("cannot store by both row and column"); return false;}
	if( parseValue( &ch) != true) return false;
	for( ; ISWHITESPACE( *ch) || isnewline( *ch); ch++ ) ;
	// get the </linearConstraintCoefficients> tag
	*p = ch;
	while( *endlinearConstraintCoefficients++  == *ch) ch++;
	if( (ch - *p) != 30) {strncpy(errorArray, ch, numErrorChar); osilerror( "cannot find </linearConstraintCoefficients> tag"); return false;}
	for(; ISWHITESPACE( *ch) || isnewline( *ch); ch++ );	
	// better have >
	if(*ch != '>') {strncpy(errorArray, ch, numErrorChar); osilerror("improperly formed </linearConstraintCoefficients> tag"); return false;}
	ch++;	
	*p = ch;
	return true;
}//end parseLinearConstraintCoefficients

bool parseStart(const char **p){
	const char *ch = *p;
	start = clock(); 
	const char* startStart = "<start";
	const char* endStart = "</start";
	const char* startEl = "<el";
	const char* endEl = "</el";
	int kount = 0;
	int i;
	bool foundEl = false;
	for( ; ISWHITESPACE( *ch) || isnewline( *ch); ch++ ) ;
	// if, present we should be pointing to <start element 
	*p = ch;
	while( *startStart++  == *ch) ch++;
	if( (ch - *p) != 6) {
		//reset ch
		ch = *p;
		return false;
	}
	// get rid of white space after <start
	for( ; ISWHITESPACE( *ch) || isnewline( *ch); ch++ ) ;
	// we should have either an >
	if(*ch != '>') {strncpy(errorArray, ch, numErrorChar); osilerror("improperly formed <start> element"); return false;}
	ch++;
	// get rid of white space
	for( ; ISWHITESPACE( *ch) || isnewline( *ch); ch++ ) ;
	// look for an <el> -- if none present must have b64 data
	*p = ch;
	while( *startEl++  == *ch) ch++;
	startEl -= 4;
	if( (ch - *p) != 3) {
		//reset ch
		ch = *p;
		// call base64 parse here
		int dataSize = 0;
		char* b64string = parseBase64(&ch, &dataSize );
		if( b64string == NULL) {strncpy(errorArray, ch, numErrorChar); osilerror("<start> must have children or base64 data"); return false;}
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
			if( *ch++ != '>') {strncpy(errorArray, ch, numErrorChar); osilerror("improperly formed <el> tag"); return false;}
			// eat white space again,
			for(; ISWHITESPACE( *ch) || isnewline( *ch); ch++ );
			// okay we better have a number, we will check later
			*p = ch;
			// find the end of the number, it better be an </el>
			// find </el
			while( *ch != '<' && *ch  != EOF){
				ch++;
			}
			// we better have a <, or not valid
			if(*ch != '<') {strncpy(errorArray, ch, numErrorChar); osilerror("cannot find an </el>"); return false;}
			osinstance->instanceData->linearConstraintCoefficients->start->el[ kount++] = 
			atoimod1( *p, ch);
			//printf("number = %s\n", *p);
			// we are pointing to <, make sure there is /el
			*p = ch;
			while( *endEl++  == *ch) ch++;
			endEl -= 5;
			if( (ch - *p) != 4 ) {strncpy(errorArray, ch, numErrorChar); osilerror("cannot fine an </el>"); return false;}
			// start eating white space until an '>' is found for </el>,
			for(; ISWHITESPACE( *ch) || isnewline( *ch); ch++ ) ;
			if( *ch++ != '>') {strncpy(errorArray, ch, numErrorChar); osilerror("improperly formed </el> tag"); return false;}
			// eat white space again,
			for(; ISWHITESPACE( *ch) || isnewline( *ch); ch++ );
			// either have another <el> element or foundEl = false;
			*p = ch;
			while( *startEl++  == *ch) ch++;
			if( (ch - *p)  == 3){
				 foundEl = true;
				 startEl -= 4;
			}
			else{
			 	foundEl = false;
			 	ch = *p;
			}
		}		
	}
	// get the </start> tag
	*p = ch;
	while( *endStart++  == *ch) ch++;
	if( (ch - *p) != 7) {strncpy(errorArray, ch, numErrorChar); osilerror( "cannot find </start> tag"); return false;}
	for(; ISWHITESPACE( *ch) || isnewline( *ch); ch++ );	
	// better have >
	if(*ch != '>') {strncpy(errorArray, ch, numErrorChar); osilerror("improperly formed </start> tag");	return false;}
	ch++;	
	// get the end element
	finish = clock();
	duration = (double) (finish - start) / CLOCKS_PER_SEC; 
	printf("TIME TO PARSE STARTS  = %f\n", duration);
	*p = ch;
	return true;
}//end parseSart

bool parseRowIdx( const char **p){
	const char *ch = *p;
	start = clock(); 
	const char* startRowIdx = "<rowIdx";
	const char* endRowIdx = "</rowIdx";
	const char* startEl = "<el";
	const char* endEl = "</el";
	int kount = 0;
	int i;
	bool foundEl = false;
	for( ; ISWHITESPACE( *ch) || isnewline( *ch); ch++ ) ;
	// if, present we should be pointing to <rowIdx element 
	*p = ch;
	while( *startRowIdx++  == *ch) ch++;
	if( (ch - *p) != 7) {
		//reset ch
		ch = *p;
		return false;
	}
	// get rid of white space after <rowIdx
	for( ; ISWHITESPACE( *ch) || isnewline( *ch); ch++ ) ;
	// we should have either an >
	if(*ch != '>') {strncpy(errorArray, ch, numErrorChar); osilerror("improperly formed <rowIdx> element"); return false;}
	ch++;
	// get rid of white space
	for( ; ISWHITESPACE( *ch) || isnewline( *ch); ch++ ) ;
	// look for an <el> -- if none present must have b64 data
	*p = ch;
	while( *startEl++  == *ch) ch++;
	startEl -= 4;
	if( (ch - *p) != 3) {
		//reset ch
		ch = *p;
		// call base64 parse here
		int dataSize = 0;
		char* b64string = parseBase64(&ch, &dataSize );
		if( b64string == NULL)  {strncpy(errorArray, ch, numErrorChar); osilerror("<rowIdx> must have children or base64 data"); return false;}
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
			if( *ch++ != '>') {strncpy(errorArray, ch, numErrorChar); osilerror("improperly formed <el> tag"); return false;}
			// mung white space again,
			for(; ISWHITESPACE( *ch) || isnewline( *ch); ch++ ) ;
			// okay we better have a number, we will check later
			*p = ch;
			// find the end of the number, it better be an </el>
			// find </el
			while( *ch != '<' && *ch  != EOF){
				ch++;
			}
			// we better have a <, or not valid
			if(*ch != '<') {strncpy(errorArray, ch, numErrorChar);  osilerror("cannot find an </el>"); return false;}
			osinstance->instanceData->linearConstraintCoefficients->rowIdx->el[ kount++] = 
			atoimod1( *p, ch);
			//printf("number = %s\n", *p);
			// we are pointing to <, make sure there is /el
			*p = ch;
			while( *endEl++  == *ch) ch++;
			endEl -= 5;
			if( (ch - *p)  != 4 ) {strncpy(errorArray, ch, numErrorChar); osilerror("cannot find an </el>"); return false;}
			// start munging white space until an '>' is found for </el>,
			for(; ISWHITESPACE( *ch) || isnewline( *ch); ch++ );
			if( *ch++ != '>') {strncpy(errorArray, ch, numErrorChar); osilerror("improperly formed </el> tag"); return false;}
			// eat white space again,
			for(; ISWHITESPACE( *ch) || isnewline( *ch); ch++ );
			// either have another <el> element or foundEl = false;
			*p = ch;
			while( *startEl++  == *ch) ch++;
			if( (ch - *p) == 3){
				foundEl = true;
				startEl -= 4;
			}
			else{
				foundEl = false;
				ch = *p;
			}
		}
	}
	// get the </rowIdx> tag
	*p = ch;
	while( *endRowIdx++  == *ch) ch++;
	if( (ch - *p) != 8) {strncpy(errorArray, ch, numErrorChar); osilerror( "cannot find </rowIdx> tag"); return false;}
	for(; ISWHITESPACE( *ch) || isnewline( *ch); ch++ );	
	// better have >
	if(*ch != '>') {strncpy(errorArray, ch, numErrorChar); osilerror("improperly formed </rowIdx> tag");}	
	ch++;	
	if(kount > osinstance->instanceData->linearConstraintCoefficients->numberOfValues) { osilerror("numberOfLinearCoefficients attribute less than number of row indices found"); return false;}
	if(kount < osinstance->instanceData->linearConstraintCoefficients->numberOfValues) { osilerror("numberOfLinearCoefficients attribute greater than number of row indices found"); return false;}
	finish = clock();
	duration = (double) (finish - start) / CLOCKS_PER_SEC; 
	printf("TIME TO PARSE ROW INDEXES = %f\n", duration);
	*p = ch;
 	return true;
}//end parseRowIdx


bool parseColIdx( const char **p){
	const char *ch = *p;
	start = clock(); 
	const char* startColIdx = "<colIdx";
	const char* endColIdx = "</colIdx";
	const char* startEl = "<el";
	const char* endEl = "</el";
	int kount = 0;
	int i;
	bool foundEl = false;
	for( ; ISWHITESPACE( *ch) || isnewline( *ch); ch++ ) ;
	// if, present we should be pointing to <colIdx element 
	*p = ch;
	while( *startColIdx++  == *ch) ch++;
	if( (ch - *p) != 7) {
		//reset ch
		ch = *p;
		return false;
	}
	// get rid of white space after <colIdx
	for( ; ISWHITESPACE( *ch) || isnewline( *ch); ch++ ) ;
	// we should have either an >
	if(*ch != '>') {strncpy(errorArray, ch, numErrorChar); osilerror("improperly formed <colIdx> element"); return false;}
	ch++;
	// get rid of white space
	for( ; ISWHITESPACE( *ch) || isnewline( *ch); ch++ ) ;
	// look for an <el> -- if none present must have b64 data
	*p = ch;
	while( *startEl++  == *ch) ch++;
	startEl -= 4;
	if( (ch - *p) != 3) {
		//reset ch
		ch = *p;
		// call base64 parse here
		int dataSize = 0;
		char* b64string = parseBase64(&ch, &dataSize );
		if( b64string == NULL)  {strncpy(errorArray, ch, numErrorChar); osilerror("<colIdx> must have children or base64 data"); return false;}
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
			if( *ch++ != '>') {strncpy(errorArray, ch, numErrorChar); osilerror("improperly formed <el> tag"); return false;}
			// eat white space again,
			for(; ISWHITESPACE( *ch) || isnewline( *ch); ch++ ) ;
			// okay we better have a number, we will check later
			*p = ch;
			// find the end of the number, it better be an </el>
			// find </el
			while( *ch != '<' && *ch  != EOF){
				ch++;
			}
			// we better have a <, or not valid
			if(*ch != '<') {strncpy(errorArray, ch, numErrorChar); osilerror("cannot find an </el>"); return false;}
			osinstance->instanceData->linearConstraintCoefficients->colIdx->el[ kount++] = 
			atoimod1( *p, ch);
			//printf("number = %s\n", *p);
			// we are pointing to <, make sure there is /el
			*p = ch;
			while( *endEl++  == *ch) ch++;
			endEl -= 5;
			if( (ch - *p) != 4 ) {strncpy(errorArray, ch, numErrorChar); osilerror("cannot fine an </el>"); return false;}
			// start eating white space until an '>' is found for </el>,
			for(; ISWHITESPACE( *ch) || isnewline( *ch); ch++ );
			if( *ch++ != '>') {strncpy(errorArray, ch, numErrorChar); osilerror("improperly formed </el> tag"); return false;}
			// eat white space again,
			for(; ISWHITESPACE( *ch) || isnewline( *ch); ch++ );
			// either have another <el> element or foundEl = false;
			*p = ch;
			while( *startEl++  == *ch) ch++;
			if( (ch - *p) == 3){
			 	foundEl = true;
			 	startEl -= 4;
			}
			else{
			 	foundEl = false;
			 	ch = *p;
			}
		}
	}
	// get the </colIdx> tag
	*p = ch;
	while( *endColIdx++  == *ch) ch++;		
	if( (ch - *p) != 8) {strncpy(errorArray, ch, numErrorChar); osilerror( "cannot find </colIdx> tag"); return false;}
	for(; ISWHITESPACE( *ch) || isnewline( *ch); ch++ );	
	// better have >
	if(*ch != '>') {strncpy(errorArray, ch, numErrorChar); osilerror("improperly formed </colIdx> tag"); return false;}	
	ch++;	
	if(kount > osinstance->instanceData->linearConstraintCoefficients->numberOfValues) {strncpy(errorArray, ch, numErrorChar); osilerror("numberOfLinearCoefficients attribute less than number of column indices found"); return false;}
	if(kount < osinstance->instanceData->linearConstraintCoefficients->numberOfValues) {strncpy(errorArray, ch, numErrorChar); osilerror("numberOfLinearCoefficients attribute greater than number of column indices found"); return false;}
	finish = clock();
	duration = (double) (finish - start) / CLOCKS_PER_SEC; 
	printf("TIME TO PARSE COLUMN INDEXES = %f\n", duration);
	*p = ch;
 	return true;
}//end parseColIdx


bool parseValue( const char **p){
	const char *ch = *p;
	start = clock(); 
	const char* startValue = "<value";
	const char* endValue = "</value";
	const char* startEl = "<el";
	const char* endEl = "</el";
	int kount = 0;
	int i;
	bool foundEl = false;
	for( ; ISWHITESPACE( *ch) || isnewline( *ch) ; ch++ ) ;
	// if present we should be pointing to <value element 
	*p = ch;
	while( *startValue++  == *ch) ch++;
	if( (ch - *p) != 6) {
		//reset ch
		ch = *p;
		return false;
	}
	// get rid of white space after <value
	for( ; ISWHITESPACE( *ch) || isnewline( *ch) ; ch++ ) ;
	// we should have either an >
	if(*ch != '>') {strncpy(errorArray, ch, numErrorChar); osilerror("improperly formed <value> element"); return false;}
	ch++;
	// get rid of white space
	for( ; ISWHITESPACE( *ch) || isnewline( *ch) ; ch++ ) ;
	// look for an <el> -- if none present must have b64 data
	*p = ch;
	while( *startEl++  == *ch) ch++;
	startEl -= 4;
	if( (ch - *p) != 3) {
		//reset ch
		ch = *p;
		// call base64 parse here
		int dataSize = 0;
		char* b64string = parseBase64(&ch, &dataSize );
		if( b64string == NULL)  {strncpy(errorArray, ch, numErrorChar); osilerror("<start> must have children or base64 data"); return false;};
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
			if( *ch++ != '>') {strncpy(errorArray, ch, numErrorChar); osilerror("improperly formed <el> tag"); return false;}
			// eat white space again,
			for(; ISWHITESPACE( *ch) || isnewline( *ch) ; ch++ ) ;
			*p = ch;
			// find the end of the number, it better be an </el>
			// find the < which begins the </el
			while( *ch != '<' && *ch != EOF){
				ch++;
			}
			// we better have a <, or not valid
			if(*ch != '<') {strncpy(errorArray, ch, numErrorChar); osilerror("cannot find an </el>"); return false;}
			osinstance->instanceData->linearConstraintCoefficients->value->el[ kount++] = 
			atofmod1( *p, ch);
			//printf("number = %s\n", *p);
			// we are pointing to <, make sure there is /el
			*p = ch;
			while( *endEl++  == *ch) ch++;
			endEl -= 5;
			if( (ch - *p) != 4 ) {strncpy(errorArray, ch, numErrorChar); osilerror("cannot fine an </el>"); return false;}
			// start eating white space until an '>' is found for </el>,
			for(; ISWHITESPACE( *ch) || isnewline( *ch) ; ch++ );
			if( *ch++ != '>') {strncpy(errorArray, ch, numErrorChar); osilerror("improperly formed </el> tag"); return false;}
			// eat white space again,
			for(; ISWHITESPACE( *ch) || isnewline( *ch) ; ch++ );
			// either have another <el> element or foundEl = false;
			*p = ch;
			while( *startEl++  == *ch) ch++;
			if( (ch - *p) == 3){
			 	foundEl = true;
			 	startEl -= 4;
			}
			else{
				foundEl = false;
				ch = *p;
			}
		}	
	}
	// get the </value> tag
	*p = ch;
	while( *endValue++  == *ch) ch++;
	if( (ch - *p) != 7) {strncpy(errorArray, ch, numErrorChar); osilerror( "cannot find </value> tag"); return false;}
	for(; ISWHITESPACE( *ch) || isnewline( *ch) ; ch++ );	
	// better have >
	if(*ch != '>') {strncpy(errorArray, ch, numErrorChar); osilerror("improperly formed </value> tag");	 return false;}
	ch++;	
	if(kount < osinstance->instanceData->linearConstraintCoefficients->numberOfValues){strncpy(errorArray, ch, numErrorChar); osilerror("numberOfLinearCoefficients greater than number of values found"); return false;}
	if(kount > osinstance->instanceData->linearConstraintCoefficients->numberOfValues){strncpy(errorArray, ch, numErrorChar); osilerror("numberOfLinearCoefficients less than the number of values found"); return false;}
	finish = clock();
	duration = (double) (finish - start) / CLOCKS_PER_SEC; 
	printf("TIME TO PARSE VALUES = %f\n", duration);
	*p = ch;
	return true;
}//end parseValue

bool parseObjCoef( const char **p, int objcount){
	const char *ch = *p;
	const char* startCoef = "<coef";
	const char* endCoef = "</coef";
	const char* c_idx = "idx";
	char *attText = NULL;
	int k;
	int numberOfObjCoef = 0; 
	if( osinstance->instanceData->objectives->numberOfObjectives <= 0)  {strncpy(errorArray, ch, numErrorChar); osilerror("we can't have objective function coefficients without an objective function"); return false;}
	numberOfObjCoef = osinstance->instanceData->objectives->obj[objcount]->numberOfObjCoef;
	if(numberOfObjCoef > 0)	{
	for(k = 0; k < numberOfObjCoef; k++){
		for( ; ISWHITESPACE( *ch) || isnewline( *ch); ch++ ) ;
		// if, present we should be pointing to <coef element 
		*p = ch;
		while( *startCoef++  == *ch) ch++;
		if( (ch - *p) != 5) {strncpy(errorArray, ch, numErrorChar); osilerror("improper <coef> element"); return false;}
		startCoef -= 6;
		// get the idx attribute
		// eat the white space after <coef
		for( ; ISWHITESPACE( *ch) || isnewline( *ch); ch++ ) ;
		*p = ch;
		while( *c_idx++  == *ch) ch++;
		if( (ch - *p) != 3) {strncpy(errorArray, ch, numErrorChar); osilerror("incorrect idx attribute in objective function <idx> tag"); return false;}	
		c_idx -= 4;
		// ch should be pointing to the first character after idx attribute
		GETATTRIBUTETEXT;
		osinstance->instanceData->objectives->obj[objcount]->coef[ k]->idx  = atoimod1( attText, attTextEnd);
		delete [] attText;
		ch++;	
		// eat white space
		for( ; ISWHITESPACE( *ch) || isnewline( *ch); ch++ ) ;
		// if we don't have a > there is an error
		if(*ch++ != '>') {strncpy(errorArray, ch, numErrorChar); osilerror("incorrect <coef> element")	; return false;}	
		// we should be pointing to first character after <coef>
		*p = ch;
		// eat characters until we find <
		for(; *ch != '<' && *ch != EOF; ch++); 
		// put back here

		// we should be pointing to a < in the </coef> tag	
		if(*ch != '<') {strncpy(errorArray, ch, numErrorChar); osilerror("improper </coef> tag"); return false;}
		osinstance->instanceData->objectives->obj[objcount]->coef[ k]->value  = atofmod1( *p, ch);
		*p = ch;
		while( *endCoef++  == *ch) ch++;
		if( (ch - *p) != 6)  {strncpy(errorArray, ch, numErrorChar); osilerror("improper </coef> element"); return false;}
		endCoef -= 7;
		// get rid of white space after </coef
		for( ; ISWHITESPACE( *ch) || isnewline( *ch); ch++ ) ;
		// if we don't have a > there is an error
		if(*ch++ != '>') {strncpy(errorArray, ch, numErrorChar); osilerror("incorrect </coef> element")	; return false;}
	}
	}// end if(numberOfObjCoef > 0)
	*p = ch;
	return true;
}//end parseObjCoef

char *parseBase64(const char **p, int *dataSize ){
	const char *ch = *p;
	const char *sizeOf = "sizeOf";
	//char *numericType = "numericType";
	const char *startBase64BinaryData = "<base64BinaryData";
	const char *endBase64BinaryData = "</base64BinaryData";
	char *attText = NULL;
	char *b64string = NULL;
	int i;
	// start parsing
	for(i = 0; startBase64BinaryData[i]  == *ch; i++, ch++);
	if(i != 17) {
		ch -= i;
		*p = ch;
		return b64string;
	}
	// find sizeOf attribute
	// eat the white space
	for( ; ISWHITESPACE( *ch) || isnewline( *ch); ch++ ) ;
	for(i = 0; sizeOf[i]  == *ch; i++, ch++);
	if(i != 6) {strncpy(errorArray, ch, numErrorChar); osilerror("incorrect sizeOf attribute in <base64BinaryData> element"); return false;}	
	// ch should be pointing to the first character after sizeOf
	GETATTRIBUTETEXT;
	ch++;
	*dataSize = atoimod1( attText, attTextEnd);
	delete [] attText;
	// since the element must contain b64 data,  this element must end with > 
	// eat the white space
	for( ; ISWHITESPACE( *ch) || isnewline( *ch); ch++ ) ;
	// better have an > sign or not valid
	if(*ch != '>' ) {strncpy(errorArray, ch, numErrorChar); osilerror("<base64BinaryData> element does not have a proper closing >"); return false;}
	ch++;
	// we are now pointing start of the data
	const char *b64textstart = ch;
	// eat characters until we get to the </base64BinaryData element
	for(; *ch != '<' && *ch != EOF; ch++);
	const char *b64textend = ch;
	// we should be pointing to </base64BinaryData>
	for(i = 0; endBase64BinaryData[i]  == *ch; i++, ch++);
	if(i != 18) {strncpy(errorArray, ch, numErrorChar);osilerror(" problem with <base64BinaryData> element"); return false;}
	int b64len = b64textend - b64textstart;
	b64string = new char[ b64len + 1]; 
	for(ki = 0; ki < b64len; ki++) b64string[ki] = b64textstart[ ki]; 
	b64string[ki] = '\0';	
	// burn the white space
	for( ; ISWHITESPACE( *ch) || isnewline( *ch); ch++ ) ;
	// better have an > sign or not valid
	if(*ch != '>' ) {strncpy(errorArray, ch, numErrorChar); osilerror("</base64BinaryData> element does not have a proper closing >"); return false;}
	ch++;
	for( ; ISWHITESPACE( *ch) || isnewline( *ch); ch++ ) ;
	*p = ch;
	return b64string;
}





double atofmod1(const char *number, const char *numberend){
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
				strncpy(errorArray, number, numErrorChar); 
				osilerror( "error in parsing an XSD:double");
			}
		case 'N':
			i++;
			if(number[ i-2] != '+' &&  number[ i-2] != '-' && number[ i++] == 'a' && number[i++] == 'N'){
				val = OSNAN;
				break;
			}
			else{
				strncpy(errorArray, number, numErrorChar); 
				osilerror( "error in parsing an XSD:double");
				
			}

		default:
			strncpy(errorArray, number, numErrorChar); 
			osilerror( "error in parsing an XSD:double");
			
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
			if(i == exptest) {strncpy(errorArray, number, numErrorChar); osilerror( "error in parsing an XSD:double"); 	}
			val = val*pow(10, expsign*exppower);
			//printf("number = %f\n", val);
		}
	}
	// if we are here we should having nothing but white space until the end of the number
	for( ; ISWHITESPACE( number[ i]) || isnewline( number[ i]) ; i++);
	if(number[i] == *numberend){
		return sign*val;
	}
	else {strncpy(errorArray, number, numErrorChar); osilerror("error in parsing an XSD:double"); 	return OSNAN;}
}//end atofmod



int atoimod1(const char *number, const char *numberend){
	// modidfied atoi from Kernighan and Ritchie
	int ival;
	int i, sign;
	int endWhiteSpace;
	for(i = 0; ISWHITESPACE( number[ i]) || isnewline( number[ i]) ; i++);
	endWhiteSpace = i;
	sign = (number[ i] == '-') ? -1 : 1;
	if (number[ i] == '+' || number[ i] == '-') i++;
	for(ival = 0; ISDIGIT( number[ i]); i++){
		ival = 10*ival + (number[ i] - '0') ;
	}
	if(i == endWhiteSpace) {strncpy(errorArray, number, numErrorChar); osilerror( "error in parsing an XSD:int" ); 	}
	// if we are here we should having nothing but white space until the end of the number
	for( ; ISWHITESPACE( number[ i]) || isnewline( number[ i]) ; i++);
	if(number[i] == *numberend){
		return sign*ival;
	}
	else {strncpy(errorArray, number, numErrorChar); osilerror( "error in parsing an XSD:int"); return OSINT_MAX;	}
}//end atoimod1


