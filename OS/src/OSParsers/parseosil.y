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
#include "lexyaccparser.h"
#include "externalvars.h"
#include "OSInstance.h" 
#include "OSnLNode.h"
#include "ErrorClass.h"
#include "OSParameters.h"
#include "osilparservariables.h"
#include "Base64.h"


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



osildoc: osilstart instanceHeader instanceData  OSILEND;

osilstart:	OSILSTART  GREATERTHAN 
			| OSILSTART OSILATTRIBUTETEXT GREATERTHAN;



instanceHeader: INSTANCEHEADERSTART name source description  INSTANCEHEADEREND  
				| INSTANCEHEADER ;
   

name: 
| NAMESTARTANDEND
| NAMESTART ELEMENTTEXT NAMEEND {osinstance->instanceHeader->name = $2;}
| NAMESTART NAMEEND ;

source: 
| SOURCESTARTANDEND
| SOURCESTART ELEMENTTEXT SOURCEEND  {osinstance->instanceHeader->source = $2; } 
| SOURCESTART  SOURCEEND ;

description: 
| DESCRIPTIONSTARTANDEND
| DESCRIPTIONSTART ELEMENTTEXT DESCRIPTIONEND  {osinstance->instanceHeader->description = $2;}
| DESCRIPTIONSTART  DESCRIPTIONEND;

instanceData: INSTANCEDATASTART quadraticcoefficients  nonlinearExpressions INSTANCEDATAEND;


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
				| NONLINEAREXPRESSIONSSTART nlnumberatt nlnodes NONLINEAREXPRESSIONSEND
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
cout << "NLNODE INDEX =   " << osinstance->instanceData->nonlinearExpressions->nl[ nlnodecount]->idx << endl;
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


void osilerror(char* errormsg) {
	try{
		ostringstream outStr;
		string error = errormsg;
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

OSInstance* yygetOSInstance( string osil){
		void yyinitialize();
		yyinitialize();
		osil = osil+"00";
		char *ch = NULL;
		ch = &osil[ 0];
		int size = strlen( ch);
		ch[ size - 1] = 0;
		ch[ size - 2] = 0;
		YY_BUFFER_STATE current_buf;
		current_buf = osil_scan_buffer( ch, size );
		//yy_scan_string( osil.c_str());
		osinstance = NULL;
		osinstance = new OSInstance();
		osilparse();
		osil_delete_buffer( current_buf);
		return osinstance;
} // end yygetOSInstance

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
} // end yyInitialize()






