/** @file OSnLNode.cpp
 * 
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
#define DEBUGOSNLNODE
#include "OSnLNode.h"
#include "OSErrorClass.h"
#include "OSParameters.h"

#include<string>

#ifdef HAVE_CMATH
# include <cmath>
#else
# ifdef HAVE_MATH_H
#  include <math.h>
# else
#  error "don't have header file for math"
# endif
#endif


#include <iostream>
#include <sstream>  


using std::ostringstream;
using std::cout;
using std::endl;
  

 
//
//const std::string msnodeNames[] = {
//	/*1--*/"plus", "sum", "minus", "negate", "times", "divide",
//	"quotient", "rem", "power", "product",
//	/*2--*/"abs", "floor", "ceiling", "percent", "square", "squareRoot", "ln", "log", "log10", "exp",
//	"factorial", "combination", "permutation", "gcd", "lcm", "roundToInt", "round", "truncate", "sign", "rand","gammaFn", "gammaLn",
//	/*3--*/"sin", "cos", "tan", "arcsin", "arccos", "arctan", "sinh", "cosh", "tanh", "arcsinh", "arccosh", "arctanh",
//	"cot", "coth", "arccot", "arccoth", "sec", "sech", "arcsec", "arcsech", "csc", "csch", "arccsc", "arccsch",
//	/*4--*/"mean", "geometricMean", "harmonicMean", "trimMean", "count", "median", "firstQuartile", "thirdQuartile", "mode", "min", "max",
//	"percentile", "large", "small", "range", "interQuantileRange", "absdev", "stddev", "variance", "cv", "skewness", "kurtosis",
//	"covariance", "correlation", "pearsonCorrelation", "rankCorrelation", "autoCorrelation1", "autoCorrelation", "npv", "irr", 
//	/*"empiricalDiscreteDist", "empiricalDiscreteCum", */"discreteUniformDist", "discreteUniformCum", "discreteUniformInv",
//	"bernoulliDist", "bernoulliCum", "bernoulliInv", "binomialDist", "binomialCum", "binomialInv", "multinomialDist", "multinomialCum", "multinomialInv",
//	"hypergeometricDist", "hypergeometricCum", "hypergeometricInv", "poissonDist", "poissonCum", "poissonInv",
//	"geometricDist", "geometricCum", "geometricInv", "negativeBinomialDist", "negativeBinomialCum", "negativeBinomialInv",
//	/*"empiricalContinousDist", "empiricalContinuousCum",*/ "uniformDist", "uniformCum", "uniformInv",
//	"normalDist", "normalCum", "normalInv", "stdNormalDist", "stdNormalCum", "stdNormalInv", "bivariateNormalDist", "bivariateNormalCum",
//	"exponentialDist", "exponentialCum", "exponentialInv", "weibullDist", "weibullCum", "weibullInv", "erlangDist", "erlangCum", "erlangInv",
//	"gammaDist", "gammaCum", "gammaInv", "betaDist", "betaCum", "betaInv", "betaGeneralDist", "betaGeneralCum", "betaGeneralInv",
//	"lognormalDist", "lognormalCum", "lognormalInv", "cauchyDist", "cauchyCum", "cauchyInv", "tDist", "tCum", "tInv",
//	"chiSquareDist", "chiSquareCum", "chiSquareInv", "fDist", "fCum", "fInv", "logisticDist", "logisticCum", "logisticInv",
//	"logLogisticDist", "logLogisticCum", "logLogisticInv", "logarithmicDist", "logarithmicCum", "logarithmicInv",
//	"paretoDist", "paretoCum", "paretoDist", "rayleighDist", "rayleighCum", "rayleighInv", "pertDist", "pertCum", "pertDist",
//	"triangularDist", "triangularCum", "triangularInv", "unitNormalLinearLoss",
//	/*5--*/"number", "identifier", "PI", "E", "INF", "EPS", "TRUE", "FALSE", "EULERGAMMA", "NAN",
//	/*6--*/"variable", "objective", "constraint", "parameter",
//	/*7--*/"if", "lt", "leq", "gt", "geq", "eq", "neq", "and", "or", "xor", "implies", "not",
//	"forAll", "exists", "logicCount", "allDiff", /*"allDisjoint",*/ "atMost", "atLeast", "exactly", 
//	"inSet", "inRealSet", "inPositiveRealSet", "inNonnegativeRealSet", "inIntegerSet", "inPositiveIntegerSet","inNonnegativeIntegerSet",
//	/*8--*/
//	/*9--*/"qTerm", "quadratic", "sim", "simInput", "simOutput", "userF", "arg", "xPath", "xPathIndex",
//	"nodeRef", "arcRef", "complements", /*"prob",*/
//};



 
//const int m_miNodeIndexes[] = {
//	/*1--*/1001, 1002, 1003, 1004, 1005, 1006,
//	1007, 1008, 1009, 1010,
//	/*2--*/2001, 2002, 2003, 2004, 2005, 2006, 2007, 2008, 2009, 2010,
//	2011, 2012, 2013, 2014, 2015, 2016, 2017, 2018, 2019, 2020, 2021, 2022,
//	/*3--*/3001, 3002, 3003, 3004, 3005, 3006, 3007, 3008, 3009, 3010, 3011, 3012,
//	3013, 3014, 3015, 3016, 3017, 3018, 3019, 3020, 3021, 3022, 3023, 3024,
//	/*4--*/4001, 4002, 4003, 4004, 4005, 4006, 4007, 4008, 4009, 4010, 4011,
//	4012, 4013, 4014, 4015, 4016, 4017, 4018, 4019, 4020, 4021, 4022,
//	4023, 4024, 4025, 4026, 4027, 4028, 4029, 4030,
//	/*4101, 4102, */4111, 4112, 4113,
//	4121, 4122, 4123, 4131, 4132, 4133, 4141, 4142, 4143,
//	4151, 4152, 4153, 4161, 4162, 4163,
//	4171, 4172, 4173, 4181, 4182, 4183,
//	/*4401, 4402,*/ 4411, 4412, 4413,
//	4421, 4422, 4423, 4431, 4432, 4433, 4441, 4442,
//	4451, 4452, 4453, 4461, 4462, 4463, 4471, 4472, 4473,
//	4481, 4482, 4483, 4491, 4492, 4493, 4501, 4502, 4503,
//	4511, 4512, 4513, 4521, 4522, 4523, 4531, 4532, 4533,
//	4541, 4542, 4543, 4551, 4552, 4553, 4561, 4562, 4563,
//	4571, 4572, 4573, 4581, 4582, 4583,
//	4591, 4592, 4593, 4601, 4602, 4603, 4611, 4612, 4613,
//	4621, 4622, 4623, 4624,
//	/*5--*/5001, 5002, 5003, 5004, 5005, 5006, 5007, 5008, 5009, 5010,
//	/*6--*/6001, 6002, 6003, 6004,
//	/*7--*/7001, 7002, 7003, 7004, 7005, 7006, 7007, 7008, 7009, 7010, 7011, 7012,
//	7013, 7014, 7015, 7016, /*7017,*/ 7018, 7019, 7020, 
//	7021, 7022, 7023, 7024, 7025, 7026, 7027,
//	/*8--*/
//	/*9--*/9001, 9002, 9003, 9004, 9005, 9006, 9007, 9008, 9009,
//	9010, 9011, 9012, /*9013,*/
//};

//const int m_miNodeTypes[] = {
//	/*1--*/2, -1, 2, 1, 2, 2,
//	2, 2, 2, -1,
//	/*2--*/1, 1, 1, 1, 1, 1, 1, 2, 1, 1,
//	1, 2, 2, -1, -1, 1, 2, 2, 1, 1, 1, 1,
//	/*3--*/1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
//	1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
//	/*4--*/-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
//	-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
//	-1, -1, -1, -1, -1, -1, -1, -1,
//	/*-1, -1, */2, 2, 2,
//	2, 2, 2, 3, 3, 3, -1, -1, -1,
//	4, 4, 4, 2, 2, 2,
//	2, 2, 2, 3, 3, 3,
//	/*-1, -1,*/ 3, 3, 3,
//	3, 3, 3, 1, 1, 1, 7, 7,
//	2, 2, 2, 4, 4, 4, 3, 3, 3,
//	3, 3, 3, 3, 3, 3, 5, 5, 5,
//	3, 3, 3, 3, 3, 3, 2, 2, 2,
//	2, 2, 2, 3, 3, 3, 3, 3, 3,
//	3, 3, 3, 3, 3, 3,
//	3, 3, 3, 2, 2, 2, 4, 4, 4,
//	4, 4, 4, 1,
//	/*5--*/0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
//	/*6--*/-1, -1, -1, 0,
//	/*7--*/3, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1,
//	-1, -1, -1, -1, /*-1,*/ -1, -1, -1, 
//	-1, 1, 1, 1, 1, 1, 1
//	/*8--*/
//	/*9--*/-1, -1, -1, -1, -1, -1, 0, -1, -1,
//	-1, -1, 2, /*1,*/
//};




//
//OSnLNode methods
//

OSnLNode::OSnLNode():
	snodeName(""),
	m_mChildren(NULL),
	m_dFunctionValue( OSNAN)
	//inumberOfChildren( 0)
{
}//end OSnLNode

OSnLNode::~OSnLNode(){
	#ifdef DEBUGOSNLNODE
	cout << "inside OSnLNode destructor" << endl;
	#endif
}//end ~OSnLNode


OSnLNode* OSnLNode::createExpressionTreeFromPostfix(std::vector<OSnLNode*> nlNodeVec){
	std::vector<OSnLNode*> stackVec ;
	unsigned int kount =  0;
	while(kount <= nlNodeVec.size() - 1){
		int numkids = nlNodeVec[kount]->inumberOfChildren;
		if(numkids  > 0){
			for(int i = numkids - 1; i >= 0;  i--){
				nlNodeVec[kount]->m_mChildren[i] = stackVec.back()	;
				stackVec.pop_back();
			}
		}
		stackVec.push_back( nlNodeVec[kount]);
		kount++;
	}
	stackVec.clear();
	return nlNodeVec[ kount - 1];
}//end createExpressionTreeFromPostfix

std::vector<OSnLNode*> OSnLNode::getPostfixFromExpressionTree( ){
	std::vector<OSnLNode*> postfixVector;
	return postOrderOSnLNodeTraversal( &postfixVector);
}//getPostfixFromExpressionTree

std::vector<OSnLNode*> OSnLNode::postOrderOSnLNodeTraversal( std::vector<OSnLNode*> *postfixVector){
	if(inumberOfChildren > 0){
		int i;
		for(i = 0; i < inumberOfChildren; i++) 
			m_mChildren[i]->postOrderOSnLNodeTraversal( postfixVector);
	}
	(*postfixVector).push_back( this);
	return *postfixVector;
}//end postOrderOSnLNodeTraversal()

OSnLNode* OSnLNode::createExpressionTreeFromPrefix(std::vector<OSnLNode*> nlNodeVec){
	std::vector<OSnLNode*> stackVec;
	int kount =  nlNodeVec.size() - 1;
	while(kount >= 0){
		int numkids = nlNodeVec[kount]->inumberOfChildren;
		if(numkids > 0){
			for(int i = 0; i < numkids;  i++){
				nlNodeVec[kount]->m_mChildren[i] = stackVec.back()	;
				stackVec.pop_back();
			}
		}
		stackVec.push_back( nlNodeVec[kount]);
		kount--;
	}
	stackVec.clear();
	return nlNodeVec[ 0];
}//end createExpressionTreeFromPrefix

std::vector<OSnLNode*> OSnLNode::getPrefixFromExpressionTree(){
	std::vector<OSnLNode*> prefixVector;
	return preOrderOSnLNodeTraversal( &prefixVector);
}//getPrefixFromExpressionTree

std::vector<OSnLNode*> OSnLNode::preOrderOSnLNodeTraversal( std::vector<OSnLNode*> *prefixVector){
	(*prefixVector).push_back( this);
	if(inumberOfChildren > 0){
		for(int i = 0; i < inumberOfChildren; i++)
			m_mChildren[i]->preOrderOSnLNodeTraversal( prefixVector);
	}
	return *prefixVector;
}//end preOrderOSnLNodeTraversal


std::string OSnLNode::getTokenNumber(){
	ostringstream outStr;
	outStr << inodeInt;
	// when I creat an OSnLNode from a token number, I need to know how many children there are
	if(inodeType == -1){
		outStr << "[";
		outStr << inumberOfChildren ;
		outStr << "]";
	}
	return outStr.str();
}//getTokenNumber


std::string OSnLNode::getTokenName(){
	ostringstream outStr;
	outStr << this->snodeName;
	if(inodeType == -1){
		outStr << "[";
		outStr << inumberOfChildren ;
		outStr << "]";
	}
	return outStr.str();
}//getTokenNumber


/*
OSnLNode* OSnLNode::getOSnLNodeFromToken(std::string sToken){
// kipp possibly make this a static method or put it somewhere else
	OSnLNode *nlNodePoint;
	int nodeID ;
	int pos1, pos2;
	std::string str1, str2;
	// convert the std::string tokens into the appropriate objects
		// kipp -- put in error check -- make sure > 0 and < 10001
	nodeID = atoi(  &sToken.substr(0, 4)[0]);
	switch (nodeID){
		case OS_SUM:  // the sum token
			pos1 = sToken.find('[');
			pos2 = sToken.find(']');
			if((pos1 == std::string::npos) || (pos2 == std::string::npos)){
				// throw error
			}
			OSnLNodeSum *nlNodePointSum;
			nlNodePointSum = new OSnLNodeSum();
			nlNodePointSum->inumberOfChildren = atoi(  &sToken.substr(pos1 + 1, pos2 - pos1 - 1)[0]);
			nlNodePointSum->m_mChildren = new OSnLNode*[ nlNodePointSum->inumberOfChildren];
			return nlNodePointSum;
		break;
		case OS_MAX:  // the max token
			pos1 = sToken.find('[');
			pos2 = sToken.find(']');
			if((pos1 == std::string::npos) || (pos2 == std::string::npos)){
				// throw error
			}
			OSnLNodeMax *nlNodePointMax;
			nlNodePointMax = new OSnLNodeMax();
			nlNodePointMax->inumberOfChildren = atoi(  &sToken.substr(pos1 + 1, pos2 - pos1 - 1)[0]);
			nlNodePointMax->m_mChildren = new OSnLNode*[ nlNodePointMax->inumberOfChildren];
			return nlNodePointMax;
		break;
		case OS_PRODUCT:  // the product token
			pos1 = sToken.find('[');
			pos2 = sToken.find(']');
			if((pos1 == std::string::npos) || (pos2 == std::string::npos)){
				// throw error
			}
			OSnLNodeProduct *nlNodePointProduct;
			nlNodePointProduct = new OSnLNodeProduct();
			nlNodePointProduct->inumberOfChildren = atoi(  &sToken.substr(pos1 + 1, pos2 - pos1 - 1)[0]);
			nlNodePointProduct->m_mChildren = new OSnLNode*[ nlNodePointProduct->inumberOfChildren];
			return nlNodePointProduct;
		break;
		case OS_NUMBER:  // the number token
			pos1 = sToken.find(':');
			if(pos1 != 4){
				//throw error
			}
			// now get the second semicolon, the one that should be after value				
			pos2 = sToken.find(':', pos1 + 1);
			if(pos2 != std::string::npos) {
			}
			else{
				//throw error
			}
			OSnLNodeNumber *nlNodePointNumber; 
			nlNodePointNumber = new OSnLNodeNumber();
			nlNodePointNumber->value = atof(  &sToken.substr(pos1 + 1, pos2 - pos1 - 1)[0]);
			return nlNodePointNumber;
		break;
		case OS_VARIABLE:  // the variable token
			pos1 = sToken.find('[');
			pos2 = sToken.find(']');
			if((pos1 == std::string::npos) || (pos2 == std::string::npos)){
				// throw error
			}
			OSnLNodeVariable *nlNodePointVariable;
			nlNodePointVariable = new OSnLNodeVariable();
			nlNodePointVariable->inumberOfChildren = atoi(  &sToken.substr(pos1 + 1, pos2 - pos1 - 1)[0]);
			nlNodePointVariable->m_mChildren = new OSnLNode*[ nlNodePointVariable->inumberOfChildren];
			// throw error if there is more than one child
			// now get the index and the coefficient
			pos1 = sToken.find(':');
			if(pos1 != 4){
				//throw error
			}
			// now get the second semicolon, the one that should be after idx				
			pos2 = sToken.find(':', pos1 + 1);
			if(pos2 == std::string::npos) {
				//throw error
			}
			nlNodePointVariable->idx = atoi(  &sToken.substr(pos1 + 1, pos2 - pos1 - 1)[0]);
			// now get the coefficient
			str1 = sToken;
			str2 = sToken.substr(pos2 + 1, str1.length() - pos2 - 1);
			nlNodePointVariable->coef = atof(&str2[0]);
			return nlNodePointVariable;
		break;
		default:
			nlNodePoint = nlNodeArray[ nlNodeIdxMap[ nodeID]]->cloneOSnLNode();
		
		break;
	}
	return nlNodePoint;
}//end getOSnLNodeFromToken
*/



std::string OSnLNode::getNonlinearExpressionInXML(){
	ostringstream outStr;
	outStr << "<" ;
	outStr << snodeName;
	if(inumberOfChildren > 0) {
		outStr << ">";
	}
	else{
		outStr << "/>";
	}
	if(inumberOfChildren > 0){
		for(int i = 0; i < inumberOfChildren; i++){
			outStr << m_mChildren[i]->getNonlinearExpressionInXML();
		}
	}
	if(inumberOfChildren > 0) {
		outStr << "</" ;
		outStr << snodeName ;
		outStr << ">" ;
	}
	return outStr.str();
}//getNonlinearExpressionInXML()
//
//


void OSnLNode::getVariableIndexMap(std::map<int, int> *varIdx){
	int i;
	if(inodeInt != OS_VARIABLE){
		for(i = 0; i < inumberOfChildren; i++){
			m_mChildren[ i]->getVariableIndexMap( varIdx);
		}
	}
}//getVariableIndexMap
	
// OSnLNodePlus Methods	
OSnLNodePlus::OSnLNodePlus()
{
	snodeName = "plus";
	inumberOfChildren = 2;
	m_mChildren = new OSnLNode*[2];
	m_mChildren[ 0] = NULL;
	m_mChildren[ 1] = NULL;
	inodeInt = 1001;
	inodeType = 2;
}//end OSnLNodePlus

OSnLNodePlus::~OSnLNodePlus(){
	#ifdef DEBUGOSNLNODE
	cout << "inside OSnLNodePlus destructor" << endl;
	#endif
	for(int i = 0; i < inumberOfChildren; i++){
		if( m_mChildren[ i] != NULL) delete m_mChildren[ i];
		m_mChildren[i] = NULL;
	}
	m_mChildren = NULL;
}//end ~OSnLNodePlus


double OSnLNodePlus::calculateFunction(double *x){
	m_dFunctionValue = m_mChildren[0]->calculateFunction(x) + m_mChildren[1]->calculateFunction(x);
	return m_dFunctionValue;
}// end OSnLNodePlus::calculate


AD<double> OSnLNodePlus::constructCppADTape(std::map<int, int> *cppADIdx, CppAD::vector< AD<double> > *XAD){
	m_CppADTape = m_mChildren[0]->constructCppADTape( cppADIdx,  XAD) + m_mChildren[1]->constructCppADTape( cppADIdx,  XAD);
	return m_CppADTape;
}// end OSnLNodePlus::constructCppADTape


OSnLNode* OSnLNodePlus::cloneOSnLNode(){
	OSnLNode *nlNodePoint;
	nlNodePoint = new OSnLNodePlus();
	return  nlNodePoint;
}//end OSnLNodePlus::cloneOSnLNode

//
// OSnLNodeSum Methods	
OSnLNodeSum::OSnLNodeSum()
{
	inumberOfChildren = 0;
	snodeName = "sum";
	inodeInt = 1002;
	inodeType = -1;
}//end OSnLNodeSum

OSnLNodeSum::~OSnLNodeSum(){
	#ifdef DEBUGOSNLNODE
	cout << "inside OSnLNodeSum destructor" << endl;
	#endif
	if(inumberOfChildren > 0){
		for(int i = 0; i < inumberOfChildren; i++){
			delete m_mChildren[ i];
			m_mChildren[i] = NULL;
		}
	}
	m_mChildren = NULL;
}//end ~OSnLNodeSum

double OSnLNodeSum::calculateFunction(double *x){
	m_dFunctionValue = 0.0;
	int i;
	for(i = 0; i < inumberOfChildren; i++){
		m_dFunctionValue = m_dFunctionValue + m_mChildren[i]->calculateFunction(x);
	}
	return m_dFunctionValue;
}// end OSnLNodeSum::calculate


AD<double> OSnLNodeSum::constructCppADTape(std::map<int, int> *cppADIdx, CppAD::vector< AD<double> > *XAD){
	m_CppADTape = 0.0;
	int i;
	for(i = 0; i < inumberOfChildren; i++){
			m_CppADTape = m_CppADTape + m_mChildren[i]->constructCppADTape( cppADIdx, XAD);
	}
	return m_CppADTape;
}// end OSnLNodeSum::constructCppADTape

OSnLNode* OSnLNodeSum::cloneOSnLNode(){
	OSnLNode *nlNodePoint;
	nlNodePoint = new OSnLNodeSum();
	return  nlNodePoint;
}//end OSnLNodeSum::cloneOSnLNode
//end OSnLNodeSum methods


//
// OSnLNodeAllDiff Methods	
OSnLNodeAllDiff::OSnLNodeAllDiff()
{
	inumberOfChildren = 0;
	snodeName = "allDiff";
	inodeInt = 7016;
	inodeType = -1;
}//end OSnLNodeAllDiff

OSnLNodeAllDiff::~OSnLNodeAllDiff(){
	#ifdef DEBUGOSNLNODE
	cout << "inside OSnLNodeAllDiff destructor" << endl;
	#endif
	if(inumberOfChildren > 0){
		for(int i = 0; i < inumberOfChildren; i++){
			delete m_mChildren[ i];
			m_mChildren[i] = NULL;
		}
	}
	m_mChildren = NULL;
}//end ~OSnLNodeAllDiff

double OSnLNodeAllDiff::calculateFunction(double *x){
	m_dFunctionValue = 1;
	// return a false if not all all different
	int i, k;
	if(inumberOfChildren > 1){
		for(i = 0; i < inumberOfChildren - 1; i++){
			for(k = i + 1; k < inumberOfChildren; k++){
				if(m_mChildren[i]->calculateFunction(x) ==  
				  	m_mChildren[k]->calculateFunction(x)) return 0 ;
			}
		}
	}
	return m_dFunctionValue;
}// end OSnLNodeAllDiff::calculate


AD<double> OSnLNodeAllDiff::constructCppADTape(std::map<int, int> *cppADIdx, CppAD::vector< AD<double> > *XAD){
	try{
		throw ErrorClass("AllDifferent operator not supported by current Algorithmic Differentiation implementation");
		return m_CppADTape;
	}
	catch(const ErrorClass& eclass){
		throw ErrorClass( eclass.errormsg);
	}
	return m_CppADTape;
}// end OSnLNodeAllDiff::constructCppADTape

OSnLNode* OSnLNodeAllDiff::cloneOSnLNode(){
	OSnLNode *nlNodePoint;
	nlNodePoint = new OSnLNodeAllDiff();
	return  nlNodePoint;
}//end OSnLNodeAllDiff::cloneOSnLNode
//end OSnLNodeAllDiff methods



//
// OSnLNodeMax Methods	
OSnLNodeMax::OSnLNodeMax()
{
	inumberOfChildren = 0;
	snodeName = "max";
	inodeInt = 4011;
	inodeType = -1;
}//end OSnLNodeMax

OSnLNodeMax::~OSnLNodeMax(){
	#ifdef DEBUGOSNLNODE
	cout << "inside OSnLNodeMax destructor" << endl;
	#endif
	if(inumberOfChildren > 0){
		for(int i = 0; i < inumberOfChildren; i++){
			delete m_mChildren[ i];
			m_mChildren[i] = NULL;
		}
	}
	m_mChildren = NULL;
}//end ~OSnLNodeMax

double OSnLNodeMax::calculateFunction(double *x){
	m_dFunctionValue = m_mChildren[0]->calculateFunction(x);
	if(inumberOfChildren > 1){
		for(int i = 1; i < inumberOfChildren; i++){
			if(m_mChildren[i]->calculateFunction(x) > m_dFunctionValue){
				m_dFunctionValue = 	m_mChildren[i]->calculateFunction(x);
			}
		}
	}
	return m_dFunctionValue;
}// end OSnLNodeMax::calculate


AD<double> OSnLNodeMax::constructCppADTape(std::map<int, int> *cppADIdx, CppAD::vector< AD<double> > *XAD){
	//if not support in CppAD, throw an exception
	try{
		throw ErrorClass("Max operator not supported by current Algorithmic Differentiation implementation");
		return m_CppADTape;
	}
	catch(const ErrorClass& eclass){
		throw ErrorClass( eclass.errormsg);
	}
}// end OSnLNodeMax::constructCppADTape


OSnLNode* OSnLNodeMax::cloneOSnLNode(){
	OSnLNode *nlNodePoint;
	nlNodePoint = new OSnLNodeMax();
	return  nlNodePoint;
}//end OSnLNodeMax::cloneOSnLNode
//



//
// OSnLNodeMin Methods	
OSnLNodeMin::OSnLNodeMin()
{
	inumberOfChildren = 0;
	snodeName = "min";
	inodeInt = 4010;
	inodeType = -1;
}//end OSnLNodeMin

OSnLNodeMin::~OSnLNodeMin(){
	#ifdef DEBUGOSNLNODE
	cout << "inside OSnLNodeMin destructor" << endl;
	#endif
	if(inumberOfChildren > 0){
		for(int i = 0; i < inumberOfChildren; i++){
			delete m_mChildren[ i];
			m_mChildren[i] = NULL;
		}
	}
	m_mChildren = NULL;
}//end ~OSnLNodeMin

double OSnLNodeMin::calculateFunction(double *x){
	m_dFunctionValue = m_mChildren[0]->calculateFunction(x);
	if(inumberOfChildren > 1){
		for(int i = 1; i < inumberOfChildren; i++){
			if(m_mChildren[i]->calculateFunction(x) < m_dFunctionValue){
				m_dFunctionValue = 	m_mChildren[i]->calculateFunction(x);
			}
		}
	}
	return m_dFunctionValue;
}// end OSnLNodeMin::calculate


AD<double> OSnLNodeMin::constructCppADTape(std::map<int, int> *cppADIdx, CppAD::vector< AD<double> > *XAD){
	//if not support in CppAD, throw an exception
	try{
		throw ErrorClass("Min operator not supported by current Algorithmic Differentiation implementation");
		return m_CppADTape;
	}
	catch(const ErrorClass& eclass){
		throw ErrorClass( eclass.errormsg);
	}
}// end OSnLNodeMin::constructCppADTape


OSnLNode* OSnLNodeMin::cloneOSnLNode(){
	OSnLNode *nlNodePoint;
	nlNodePoint = new OSnLNodeMin();
	return  nlNodePoint;
}//end OSnLNodeMin::cloneOSnLNode
//


//
//
// OSnLNodeMinus Methods	
OSnLNodeMinus::OSnLNodeMinus()
{
	inumberOfChildren = 2;
	m_mChildren = new OSnLNode*[2];
	m_mChildren[ 0] = NULL;
	m_mChildren[ 1] = NULL;
	snodeName = "minus";
	inodeInt = 1003;
	inodeType = 2;
}//end OSnLNodeMinus

 
OSnLNodeMinus::~OSnLNodeMinus(){
	#ifdef DEBUGOSNLNODE
	cout << "inside OSnLNodeMinus destructor" << endl;
	#endif
	for(int i = 0; i < inumberOfChildren; i++){
		delete m_mChildren[ i];
		m_mChildren[i] = NULL;
	}
	m_mChildren = NULL;
}//end ~OSnLNodeMinus

double OSnLNodeMinus::calculateFunction(double *x){
	m_dFunctionValue =  m_mChildren[0]->calculateFunction( x) - m_mChildren[1]->calculateFunction( x);
	return m_dFunctionValue;
}// end OSnLNodeMinus::calculate


AD<double> OSnLNodeMinus::constructCppADTape(std::map<int, int> *cppADIdx, CppAD::vector< AD<double> > *XAD){
	m_CppADTape = m_mChildren[0]->constructCppADTape( cppADIdx, XAD) - m_mChildren[1]->constructCppADTape( cppADIdx, XAD);
	return m_CppADTape;
}// end OSnLNodeMinus::constructCppADTape


OSnLNode* OSnLNodeMinus::cloneOSnLNode(){
	OSnLNode *nlNodePoint;
	nlNodePoint = new OSnLNodeMinus();
	return  nlNodePoint;
}//end OSnLNodeMinus::cloneOSnLNode
//
//


//
//
// OSnLNodeNegate Methods	
OSnLNodeNegate::OSnLNodeNegate()
{
	inumberOfChildren = 1;
	m_mChildren = new OSnLNode*[1];
	m_mChildren[ 0] = NULL;
	snodeName = "negate";
	inodeInt = 1004;
	inodeType = 1;
}//end OSnLNodeNegate

 
OSnLNodeNegate::~OSnLNodeNegate(){
	#ifdef DEBUGOSNLNODE
	cout << "inside OSnLNodeNegate destructor" << endl;
	#endif
	for(int i = 0; i < inumberOfChildren; i++){
		delete m_mChildren[ i];
		m_mChildren[i] = NULL;
	}
	m_mChildren = NULL;
}//end ~OSnLNodeNegate

double OSnLNodeNegate::calculateFunction(double *x){
	m_dFunctionValue =  -m_mChildren[0]->calculateFunction( x) ;
	return m_dFunctionValue;
}// end OSnLNodeMinus::calculate

AD<double> OSnLNodeNegate::constructCppADTape(std::map<int, int> *cppADIdx, CppAD::vector< AD<double> > *XAD){
	m_CppADTape = -m_mChildren[0]->constructCppADTape( cppADIdx, XAD);
	return m_CppADTape;
}// end OSnLNodeNegate::constructCppADTape


OSnLNode* OSnLNodeNegate::cloneOSnLNode(){
	OSnLNode *nlNodePoint;
	nlNodePoint = new OSnLNodeNegate();
	return  nlNodePoint;
}//end OSnLNodeNegate::cloneOSnLNode
//
//

// OSnLNodeTimes Methods	
OSnLNodeTimes::OSnLNodeTimes()
{
	inumberOfChildren = 2;
	m_mChildren = new OSnLNode*[2];
	m_mChildren[ 0] = NULL;
	m_mChildren[ 1] = NULL;
	snodeName = "times";
	inodeInt = 1005;
	inodeType = 2;
}//end OSnLNodeTimes

 
OSnLNodeTimes::~OSnLNodeTimes(){
	#ifdef DEBUGOSNLNODE
	cout << "inside OSnLNodeTimes destructor" << endl;
	#endif
	for(int i = 0; i < inumberOfChildren; i++){
		delete m_mChildren[ i];
		m_mChildren[i] = NULL;
	}
	m_mChildren = NULL;
}//end ~OSnLNodeTimes

double OSnLNodeTimes::calculateFunction(double *x){
	m_dFunctionValue = m_mChildren[0]->calculateFunction( x)*m_mChildren[1]->calculateFunction( x);
	return m_dFunctionValue;
}// end OSnLNodeTimes::calculate


AD<double> OSnLNodeTimes::constructCppADTape(std::map<int, int> *cppADIdx, CppAD::vector< AD<double> > *XAD){
	m_CppADTape = m_mChildren[0]->constructCppADTape( cppADIdx, XAD) * m_mChildren[1]->constructCppADTape( cppADIdx, XAD);
	return m_CppADTape;
}// end OSnLNodeTimes::constructCppADTape

OSnLNode* OSnLNodeTimes::cloneOSnLNode(){
	OSnLNode *nlNodePoint;
	nlNodePoint = new OSnLNodeTimes();
	return  nlNodePoint;
}//end OSnLNodeTimes::cloneOSnLNode

//
//
// OSnLNodeDivide Methods	
OSnLNodeDivide::OSnLNodeDivide()
{
	inumberOfChildren = 2;
	m_mChildren = new OSnLNode*[2];
	m_mChildren[ 0] = NULL;
	m_mChildren[ 1] = NULL;
	snodeName = "divide";
	inodeInt = 1006;
	inodeType = 2;
}//end OSnLNodeDivide

 
OSnLNodeDivide::~OSnLNodeDivide(){
	#ifdef DEBUGOSNLNODE
	cout << "inside OSnLNodeDivide destructor" << endl;
	#endif
	for(int i = 0; i < inumberOfChildren; i++){
		delete m_mChildren[ i];
		m_mChildren[i] = NULL;
	}
	m_mChildren = NULL;
}//end ~OSnLNodeDivide

double OSnLNodeDivide::calculateFunction(double *x){
	// kipp throw error if we divide by 0
	m_dFunctionValue = m_mChildren[0]->calculateFunction( x)/m_mChildren[1]->calculateFunction( x);
	return m_dFunctionValue;
}// end OSnLNodeDivide::calculate


AD<double> OSnLNodeDivide::constructCppADTape(std::map<int, int> *cppADIdx, CppAD::vector< AD<double> > *XAD){
	m_CppADTape = m_mChildren[0]->constructCppADTape( cppADIdx, XAD) / m_mChildren[1]->constructCppADTape( cppADIdx, XAD);
	return m_CppADTape;
}// end OSnLNodeDivide::constructCppADTape


OSnLNode* OSnLNodeDivide::cloneOSnLNode(){
	OSnLNode *nlNodePoint;
	nlNodePoint = new OSnLNodeDivide();
	return  nlNodePoint;
}//end OSnLNodeDivide::cloneOSnLNode


//
// OSnLNodePower Methods	
OSnLNodePower::OSnLNodePower()
{
	inumberOfChildren = 2;
	m_mChildren = new OSnLNode*[2];
	m_mChildren[ 0] = NULL;
	m_mChildren[ 1] = NULL;
	snodeName = "power";
	inodeInt = 1009;
	inodeType = 2;
}//end OSnLNodePower

 
OSnLNodePower::~OSnLNodePower(){
	#ifdef DEBUGOSNLNODE
	cout << "inside OSnLNodePower destructor" << endl;
	#endif
	for(int i = 0; i < inumberOfChildren; i++){
		delete m_mChildren[ i];
		m_mChildren[i] = NULL;
	}
	m_mChildren = NULL;
}//end ~OSnLNodePower 

double OSnLNodePower::calculateFunction(double *x){
	// kipp throw error if operation not defined
	m_dFunctionValue =  pow(m_mChildren[0]->calculateFunction( x), m_mChildren[1]->calculateFunction( x));
	return  m_dFunctionValue;
}// end OSnLNodePower::calculate

//
AD<double> OSnLNodePower::constructCppADTape(std::map<int, int> *cppADIdx, CppAD::vector< AD<double> > *XAD){
	//if( typeid( *m_mChildren[1]) == typeid( OSnLNodeNumber) ) {
	if( this->m_mChildren[1]->inodeInt == 5001 ) {
		OSnLNodeNumber *numberNode  =  (OSnLNodeNumber*)m_mChildren[1];
		// we have a number node see if interger
		if( (numberNode->value) == int( numberNode->value)){
			m_CppADTape =  CppAD::pow(m_mChildren[0]->constructCppADTape( cppADIdx, XAD) ,  int( numberNode->value));
		}	
		else m_CppADTape = CppAD::pow(m_mChildren[0]->constructCppADTape( cppADIdx, XAD) , m_mChildren[1]->constructCppADTape( cppADIdx, XAD) );	
	}
	else{
		m_CppADTape = CppAD::pow(m_mChildren[0]->constructCppADTape( cppADIdx, XAD) , m_mChildren[1]->constructCppADTape( cppADIdx, XAD) );	
	}
	return m_CppADTape;
}// end OSnLNodePower::constructCppADTape



//AD<double> OSnLNodePower::constructCppADTape(std::map<int, int> *cppADIdx, CppAD::vector< AD<double> > *XAD){	
//		m_CppADTape = CppAD::pow(m_mChildren[0]->constructCppADTape( cppADIdx, XAD) , m_mChildren[1]->constructCppADTape( cppADIdx, XAD) );	
//	return m_CppADTape;
//}// end OSnLNodePower::constructCppADTape





OSnLNode* OSnLNodePower::cloneOSnLNode(){
	OSnLNode *nlNodePoint;
	nlNodePoint = new OSnLNodePower();
	return  nlNodePoint;
}//end OSnLNodePower::cloneOSnLNode
//
//


//
// OSnLNodePower Methods	
OSnLNodeProduct::OSnLNodeProduct()
{
	inumberOfChildren = 0;
	snodeName = "product";
	inodeInt = 1010;
	inodeType = -1;
}//end OSnLNodeProduct

 
OSnLNodeProduct::~OSnLNodeProduct(){
	#ifdef DEBUGOSNLNODE
	cout << "inside OSnLNodeProduct destructor" << endl;
	#endif
	if(inumberOfChildren > 0){
		for(int i = 0; i < inumberOfChildren; i++){
			delete m_mChildren[ i];
			m_mChildren[i] = NULL;
		}
	}
	m_mChildren = NULL;
}//end ~OSnLNodeProduct

double OSnLNodeProduct::calculateFunction(double *x){
	// kipp throw error if operation not defined
	m_dFunctionValue = 1.0;
	int i;
	for(i = 0; i < inumberOfChildren; i++){
		m_dFunctionValue = m_dFunctionValue*m_mChildren[i]->calculateFunction(x);
	}
	return m_dFunctionValue;
}// end OSnLNodeProduct::calculate


AD<double> OSnLNodeProduct::constructCppADTape(std::map<int, int> *cppADIdx, CppAD::vector< AD<double> > *XAD){
	m_CppADTape = 1.0;
	int i;
	for(i = 0; i < inumberOfChildren; i++){
		m_CppADTape = m_CppADTape*m_mChildren[i]->constructCppADTape( cppADIdx, XAD);
	}
	return m_CppADTape;
}// end OSnLNodeProduct::constructCppADTape


OSnLNode* OSnLNodeProduct::cloneOSnLNode(){
	OSnLNode *nlNodePoint;
	nlNodePoint = new OSnLNodeProduct();
	return  nlNodePoint;
}//end OSnLNodeProduct::cloneOSnLNode
//
//


//
// OSnLNodeLn Methods	
OSnLNodeLn::OSnLNodeLn()
{
	inumberOfChildren = 1;
	m_mChildren = new OSnLNode*[1];
	m_mChildren[ 0] = NULL;
	snodeName = "ln";
	inodeInt = 2007;
	inodeType = 1;
	std::cout << "CREATING OSNLNDOE LN LN LNL LNLNLNLNLNLNLN" << std::endl;
}//end OSnLNodeLn

 
OSnLNodeLn::~OSnLNodeLn(){
	#ifdef DEBUGOSNLNODE
	cout << "inside OSnLNodeLn destructor" << endl;
	#endif
	for(int i = 0; i < inumberOfChildren; i++){
		delete m_mChildren[ i];
		m_mChildren[i] = NULL;
	}
	m_mChildren = NULL;
}//end ~OSnLNodeLn

double OSnLNodeLn::calculateFunction(double *x){
	m_dFunctionValue = log(m_mChildren[0]->calculateFunction( x) );
	return m_dFunctionValue;
}// end OSnLNodeLn::calculate


AD<double> OSnLNodeLn::constructCppADTape(std::map<int, int> *cppADIdx, CppAD::vector< AD<double> > *XAD){
	m_CppADTape = CppAD::log( m_mChildren[0]->constructCppADTape( cppADIdx, XAD) );
	return m_CppADTape;
}// end OSnLNodeLn::constructCppADTape

OSnLNode* OSnLNodeLn::cloneOSnLNode(){
	OSnLNode *nlNodePoint;
	nlNodePoint = new OSnLNodeLn();
	return  nlNodePoint;
}//end OSnLNodeLn::cloneOSnLNode





//
// OSnLNodeSqrt Methods	
OSnLNodeSqrt::OSnLNodeSqrt()
{
	inumberOfChildren = 1;
	m_mChildren = new OSnLNode*[1];
	m_mChildren[ 0] = NULL;
	snodeName = "sqrt";
	inodeInt = 2006;
	inodeType = 1;
}//end OSnLNodeSqrt

 
OSnLNodeSqrt::~OSnLNodeSqrt(){
	#ifdef DEBUGOSNLNODE
	cout << "inside OSnLNodeSqrt destructor" << endl;
	#endif
	for(int i = 0; i < inumberOfChildren; i++){
		delete m_mChildren[ i];
		m_mChildren[i] = NULL;
	}
	m_mChildren = NULL;
}//end ~OSnLNodeSqrt

double OSnLNodeSqrt::calculateFunction(double *x){
	m_dFunctionValue = sqrt(m_mChildren[0]->calculateFunction( x) );
	return m_dFunctionValue;
}// end OSnLNodeSqrt::calculate


AD<double> OSnLNodeSqrt::constructCppADTape(std::map<int, int> *cppADIdx, CppAD::vector< AD<double> > *XAD){
	m_CppADTape = CppAD::sqrt( m_mChildren[0]->constructCppADTape( cppADIdx, XAD) );
	return m_CppADTape;
}// end OSnLNodeSqrt::constructCppADTape

OSnLNode* OSnLNodeSqrt::cloneOSnLNode(){
	OSnLNode *nlNodePoint;
	nlNodePoint = new OSnLNodeSqrt();
	return  nlNodePoint;
}//end OSnLNodeSqrt::cloneOSnLNode



//
//
// OSnLNodeSquare Methods	
OSnLNodeSquare::OSnLNodeSquare()
{
	inumberOfChildren = 1;
	m_mChildren = new OSnLNode*[1];
	m_mChildren[ 0] = NULL;
	snodeName = "square";
	inodeInt = 2005;
	inodeType = 1;
}//end OSnLNodeSquare

 
OSnLNodeSquare::~OSnLNodeSquare(){
	#ifdef DEBUGOSNLNODE
	cout << "inside OSnLNodeSquare destructor" << endl;
	#endif
	for(int i = 0; i < inumberOfChildren; i++){
		delete m_mChildren[ i];
		m_mChildren[i] = NULL;
	}
	m_mChildren = NULL;
}//end ~OSnLNodeSquare

double OSnLNodeSquare::calculateFunction(double *x){
	m_dFunctionValue = pow( (m_mChildren[0]->calculateFunction( x) ), 2);
	return m_dFunctionValue;
}// end OSnLNodeSquare::calculate


AD<double> OSnLNodeSquare::constructCppADTape(std::map<int, int> *cppADIdx, CppAD::vector< AD<double> > *XAD){
	m_CppADTape = CppAD::pow( m_mChildren[0]->constructCppADTape( cppADIdx, XAD), int( 2) );
	return m_CppADTape;
}// end OSnLNodeSquare::constructCppADTape

OSnLNode* OSnLNodeSquare::cloneOSnLNode(){
	OSnLNode *nlNodePoint;
	nlNodePoint = new OSnLNodeSquare();
	return  nlNodePoint;
}//end OSnLNodeSquare::cloneOSnLNode

//
//
// OSnLNodeSin Methods	
OSnLNodeSin::OSnLNodeSin()
{
	inumberOfChildren = 1;
	m_mChildren = new OSnLNode*[1];
	m_mChildren[ 0] = NULL;
	snodeName = "sin";
	inodeInt = 3001;
	inodeType = 1;
}//end OSnLNodeSin

 
OSnLNodeSin::~OSnLNodeSin(){
	#ifdef DEBUGOSNLNODE
	cout << "inside OSnLNodeSin destructor" << endl;
	#endif
	for(int i = 0; i < inumberOfChildren; i++){
		delete m_mChildren[ i];
		m_mChildren[i] = NULL;
	}
	m_mChildren = NULL;
}//end ~OSnLNodeSin

double OSnLNodeSin::calculateFunction(double *x){
	m_dFunctionValue = sin(m_mChildren[0]->calculateFunction( x) );
	return m_dFunctionValue;
}// end OSnLNodeSin::calculate


AD<double> OSnLNodeSin::constructCppADTape(std::map<int, int> *cppADIdx, CppAD::vector< AD<double> > *XAD){
	m_CppADTape = CppAD::sin( m_mChildren[0]->constructCppADTape( cppADIdx, XAD) );
	return m_CppADTape;
}// end OSnLNodeSin::constructCppADTape

OSnLNode* OSnLNodeSin::cloneOSnLNode(){
	OSnLNode *nlNodePoint;
	nlNodePoint = new OSnLNodeSin();
	return  nlNodePoint;
}//end OSnLNodeSin::cloneOSnLNode


//
//
// OSnLNodeCos Methods	
OSnLNodeCos::OSnLNodeCos()
{
	inumberOfChildren = 1;
	m_mChildren = new OSnLNode*[1];
	m_mChildren[ 0] = NULL;
	snodeName = "cos";
	inodeInt = 3002;
	inodeType = 1;
}//end OSnLNodeCos

 
OSnLNodeCos::~OSnLNodeCos(){
	#ifdef DEBUGOSNLNODE
	cout << "inside OSnLNodeCos destructor" << endl;
	#endif
	for(int i = 0; i < inumberOfChildren; i++){
		delete m_mChildren[ i];
		m_mChildren[i] = NULL;
	}
	m_mChildren = NULL;
}//end ~OSnLNodeCos

double OSnLNodeCos::calculateFunction(double *x){
	m_dFunctionValue = cos(m_mChildren[0]->calculateFunction( x) );
	return m_dFunctionValue;
}// end OSnLNodeCos::calculate


AD<double> OSnLNodeCos::constructCppADTape(std::map<int, int> *cppADIdx, CppAD::vector< AD<double> > *XAD){
	m_CppADTape = CppAD::cos( m_mChildren[0]->constructCppADTape( cppADIdx, XAD) );
	return m_CppADTape;
}// end OSnLNodeCos::constructCppADTape

OSnLNode* OSnLNodeCos::cloneOSnLNode(){
	OSnLNode *nlNodePoint;
	nlNodePoint = new OSnLNodeCos();
	return  nlNodePoint;
}//end OSnLNodeCos::cloneOSnLNode




//
//
// OSnLNodeExp Methods	
OSnLNodeExp::OSnLNodeExp()
{
	inumberOfChildren = 1;
	m_mChildren = new OSnLNode*[1];
	m_mChildren[ 0] = NULL;
	snodeName = "exp";
	inodeInt = 2010;
	inodeType = 1;
}//end OSnLNodeExp

 
OSnLNodeExp::~OSnLNodeExp(){
	#ifdef DEBUGOSNLNODE
	cout << "inside OSnLNodeExp destructor" << endl;
	#endif
	for(int i = 0; i < inumberOfChildren; i++){
		delete m_mChildren[ i];
		m_mChildren[i] = NULL;
	}
	m_mChildren = NULL;
}//end ~OSnLNodeExp

double OSnLNodeExp::calculateFunction(double *x){
	m_dFunctionValue = exp(m_mChildren[0]->calculateFunction( x) );
	return m_dFunctionValue;
}// end OSnLNodeExp::calculate


AD<double> OSnLNodeExp::constructCppADTape(std::map<int, int> *cppADIdx, CppAD::vector< AD<double> > *XAD){
	m_CppADTape = CppAD::exp( m_mChildren[0]->constructCppADTape( cppADIdx, XAD) );
	return m_CppADTape;
}// end OSnLNodeExp::constructCppADTape

OSnLNode* OSnLNodeExp::cloneOSnLNode(){
	OSnLNode *nlNodePoint;
	nlNodePoint = new OSnLNodeExp();
	return  nlNodePoint;
}//end OSnLNodeExp::cloneOSnLNode
//
//



//
// OSnLNodeAbs Methods	
OSnLNodeAbs::OSnLNodeAbs()
{
	inumberOfChildren = 1;
	m_mChildren = new OSnLNode*[1];
	m_mChildren[ 0] = NULL;
	snodeName = "abs";
	inodeInt = 2001;
	inodeType = 1;
}//end OSnLNodeLn

 
OSnLNodeAbs::~OSnLNodeAbs(){
	#ifdef DEBUGOSNLNODE
	cout << "inside OSnLNodeAbs destructor" << endl;
	#endif
	for(int i = 0; i < inumberOfChildren; i++){
		delete m_mChildren[ i];
		m_mChildren[i] = NULL;
	}
	m_mChildren = NULL;
}//end ~OSnLNodeAbs

double OSnLNodeAbs::calculateFunction(double *x){
	m_dFunctionValue = fabs(m_mChildren[0]->calculateFunction( x) );
	return m_dFunctionValue;
}// end OSnLNodeAbs::calculate


AD<double> OSnLNodeAbs::constructCppADTape(std::map<int, int> *cppADIdx, CppAD::vector< AD<double> > *XAD){
	m_CppADTape = CppAD::abs( m_mChildren[0]->constructCppADTape( cppADIdx, XAD) );
	return m_CppADTape;
}// end OSnLNodeAbs::constructCppADTape

OSnLNode* OSnLNodeAbs::cloneOSnLNode(){
	OSnLNode *nlNodePoint;
	nlNodePoint = new OSnLNodeAbs();
	return  nlNodePoint;
}//end OSnLNodeAbs::cloneOSnLNode
//
//


//
// OSnLNodeIf Methods	
OSnLNodeIf::OSnLNodeIf()
{
	inumberOfChildren = 3;
	m_mChildren = new OSnLNode*[3];
	m_mChildren[ 0] = NULL;
	m_mChildren[ 1] = NULL;
	m_mChildren[ 2] = NULL;
	snodeName = "if";
	inodeInt = 7001;
	inodeType = 3;
}//end OSnLNodeIf

 
OSnLNodeIf::~OSnLNodeIf(){
	#ifdef DEBUGOSNLNODE
	cout << "inside OSnLNodeIf destructor" << endl;
	#endif 
	for(int i = 0; i < inumberOfChildren; i++){
		delete m_mChildren[ i];
		m_mChildren[i] = NULL;
	}
	m_mChildren = NULL;
}//end ~OSnLNodeIf

double OSnLNodeIf::calculateFunction(double *x){
	if(m_mChildren[0]->calculateFunction( x)  >= 0) m_dFunctionValue = m_mChildren[ 1]->calculateFunction( x);
		else m_dFunctionValue = m_mChildren[ 2]->calculateFunction( x);
	return m_dFunctionValue;
}// end OSnLNodeIf::calculate

AD<double> OSnLNodeIf::constructCppADTape(std::map<int, int> *cppADIdx, CppAD::vector< AD<double> > *XAD){
	//if not support in CppAD, throw an exception
	try{
		throw ErrorClass("if operator not supported by current Algorithmic Differentiation implementation");
		return m_CppADTape;
	}
	catch(const ErrorClass& eclass){
		throw ErrorClass( eclass.errormsg);
	}
}// end OSnLNodeIf::constructCppADTape

OSnLNode* OSnLNodeIf::cloneOSnLNode(){
	OSnLNode *nlNodePoint;
	nlNodePoint = new OSnLNodeIf();
	return  nlNodePoint;
}//end OSnLNodeIf::cloneOSnLNode
//
//


// OSnLNodeNumber Methods	
OSnLNodeNumber::OSnLNodeNumber()
{
	inodeInt = 5001;
	inumberOfChildren = 0;
	m_mChildren = NULL;
	snodeName = "number";
	inodeType = 0;  
	value = 0.0;
	type = "real";
	id = "";

}//end OSnLNodeNumber

OSnLNodeNumber::~OSnLNodeNumber(){
	#ifdef DEBUGOSNLNODE
	cout << "inside OSnLNodeNumber destructor" << endl;
	#endif
	m_mChildren = NULL;
}//end ~OSnLNodeNumber


std::string OSnLNodeNumber::getTokenNumber(){
	ostringstream outStr;
	outStr << inodeInt;
	outStr << ":" ;
	outStr << value ;
	//if(type.length() > 0){
		outStr << ":" ;
		outStr << type ;
	//}
	//if(id.length() > 0){
		outStr << ":" ;
		outStr << id;
	//}
	return outStr.str();
}//getTokenNumber


std::string OSnLNodeNumber::getTokenName(){
	ostringstream outStr;
	outStr << snodeName;
	outStr << ":" ;
	outStr << value ;
	//if(type.length() > 0){
		outStr << ":" ;
		outStr << type ;
	//}
	//if(id.length() > 0){
		outStr << ":" ;
		outStr << id;
	//}
	return outStr.str();
}//getTokenNumber


std::string OSnLNodeNumber::getNonlinearExpressionInXML(){
	ostringstream outStr;
	outStr << "<" ;
	outStr << snodeName;
		outStr << "  value=\"";
		outStr << value ;
		outStr << "\"";
		outStr << " type=\"";
		outStr << type ;
		outStr << "\"";
		if(id.length() > 0){
			outStr << "  id=\"";
			outStr << id ;
			outStr << "\"";
		}
		outStr << "/>";
	return outStr.str();
}//getNonlinearExpressionInXML()


double OSnLNodeNumber::calculateFunction(double *x){
	m_dFunctionValue = this->value;
	return m_dFunctionValue;
}// end OSnLNodeNumber::calculate

AD<double> OSnLNodeNumber::constructCppADTape(std::map<int, int> *cppADIdx, CppAD::vector< AD<double> > *XAD){
	m_CppADTape =  this->value;
	return m_CppADTape;
}// end OSnLNodeNumber::constructCppADTape

OSnLNode* OSnLNodeNumber::cloneOSnLNode(){
	OSnLNode *nlNodePoint;
	nlNodePoint = new OSnLNodeNumber();
	return  nlNodePoint;
}//end OSnLNodeNumber::cloneOSnLNode
// edn OSnLNodeNumber methods


// OSnLNodeE Methods	
OSnLNodeE::OSnLNodeE()
{
	inodeInt = 5004;
	inumberOfChildren = 0;
	m_mChildren = NULL;
	snodeName = "E";
	inodeType = 0;  
	//value = 0.0;
	//type = "real";
	//id = "";

}//end OSnLNodeE

OSnLNodeE::~OSnLNodeE(){
	#ifdef DEBUGOSNLNODE
	cout << "inside OSnLNodeE destructor" << endl;
	#endif
	m_mChildren = NULL;
}//end ~OSnLNodeE


std::string OSnLNodeE::getTokenNumber(){
	ostringstream outStr;
	outStr << inodeInt;
	//outStr << ":" ;
	//outStr << value ;
	//if(type.length() > 0){
	//	outStr << ":" ;
	//	outStr << type ;
	//}
	//if(id.length() > 0){
	//	outStr << ":" ;
	//	outStr << id;
	//}
	return outStr.str();
}//getTokenNumber


std::string OSnLNodeE::getTokenName(){
	ostringstream outStr;
	outStr << snodeName;
	//outStr << ":" ;
	//outStr << value ;
	//if(type.length() > 0){
	//	outStr << ":" ;
	//	outStr << type ;
	//}
	//if(id.length() > 0){
	//	outStr << ":" ;
	//	outStr << id;
	//}
	return outStr.str();
}//getTokenName


std::string OSnLNodeE::getNonlinearExpressionInXML(){
	ostringstream outStr;
	outStr << "<" ;
	outStr << snodeName;
//		outStr << "  value=\"";
//		outStr << value ;
//		outStr << "\"";
//		outStr << " type=\"";
//		outStr << type ;
//		outStr << "\"";
//		if(id.length() > 0){
//			outStr << "  id=\"";
//			outStr << id ;
//			outStr << "\"";
//		}
		outStr << "/>";
	return outStr.str();
}//getNonlinearExpressionInXML()


double OSnLNodeE::calculateFunction(double *x){
	m_dFunctionValue = OS_E_VALUE;
	return m_dFunctionValue;
}// end OSnLNodeE::calculate

AD<double> OSnLNodeE::constructCppADTape(std::map<int, int> *cppADIdx, CppAD::vector< AD<double> > *XAD){
	m_CppADTape =  OS_E_VALUE;
	return m_CppADTape;
}// end OSnLE::constructCppADTape

OSnLNode* OSnLNodeE::cloneOSnLNode(){
	OSnLNode *nlNodePoint;
	nlNodePoint = new OSnLNodeE();
	return  nlNodePoint;
}//end OSnLNodeE::cloneOSnLNode

//end OSnLNodeE


// OSnLNodePI Methods	
OSnLNodePI::OSnLNodePI()
{
	inodeInt = 5003;
	inumberOfChildren = 0;
	m_mChildren = NULL;
	snodeName = "PI";
	inodeType = 0;  


}//end OSnLNodePI


OSnLNodePI::~OSnLNodePI(){
	#ifdef DEBUGOSNLNODE
	cout << "inside OSnLNodePI destructor" << endl;
	#endif
	m_mChildren = NULL;
}//end ~OSnLNodePI


std::string OSnLNodePI::getTokenNumber(){
	ostringstream outStr;
	outStr << inodeInt;
	//outStr << ":" ;
	//outStr << value ;
	//if(type.length() > 0){
	//	outStr << ":" ;
	//	outStr << type ;
	//}
	//if(id.length() > 0){
	//	outStr << ":" ;
	//	outStr << id;
	//}
	return outStr.str();
}//getTokenNumber


std::string OSnLNodePI::getTokenName(){
	ostringstream outStr;
	outStr << snodeName;
	//outStr << ":" ;
	//outStr << value ;
	//if(type.length() > 0){
		//outStr << ":" ;
		//outStr << type ;
	//}
	//if(id.length() > 0){
		//outStr << ":" ;
		//outStr << id;
	//}
	return outStr.str();
}//getTokenName


std::string OSnLNodePI::getNonlinearExpressionInXML(){
	ostringstream outStr;
	outStr << "<" ;
	outStr << snodeName;
//		outStr << "  value=\"";
//		outStr << value ;
//		outStr << "\"";
//		outStr << " type=\"";
//		outStr << type ;
//		outStr << "\"";
//		if(id.length() > 0){
//			outStr << "  id=\"";
//			outStr << id ;
//			outStr << "\"";
//		}
		outStr << "/>";
	return outStr.str();
}//getNonlinearExpressionInXML()


double OSnLNodePI::calculateFunction(double *x){
	m_dFunctionValue = OS_PI_VALUE;
	return m_dFunctionValue;
}// end OSnLNodePI::calculate

AD<double> OSnLNodePI::constructCppADTape(std::map<int, int> *cppADIdx, CppAD::vector< AD<double> > *XAD){
	m_CppADTape =  OS_PI_VALUE;
	return m_CppADTape;
}// end OSnLE::constructCppADTape

OSnLNode* OSnLNodePI::cloneOSnLNode(){
	OSnLNode *nlNodePoint;
	nlNodePoint = new OSnLNodePI();
	return  nlNodePoint;
}//end OSnLNodePI::cloneOSnLNode

//end OSnLNodePI methods

// OSnLNodeVariable Methods	
OSnLNodeVariable::OSnLNodeVariable()
{
	inumberOfChildren = 0;
	m_mChildren = NULL;
	snodeName = "variable";
	inodeInt = 6001;
	inodeType = -1;
	coef = 1.0;
	idx = -1;
}//end OSnLNodeVariable

OSnLNodeVariable::~OSnLNodeVariable(){
	#ifdef DEBUGOSNLNODE
	cout << "inside OSnLNodeVariable destructor" << endl;
	cout << "number kids = " <<  inumberOfChildren << endl;
	#endif
	if(inumberOfChildren > 0){
		for(int i = 0; i < inumberOfChildren; i++){
			delete m_mChildren[ i];
			m_mChildren[i] = NULL;
		}
	}
	m_mChildren = NULL;
}//end ~OSnLNodeVariable


std::string OSnLNodeVariable::getTokenNumber(){
	ostringstream outStr;
	// put in an error if inodeInt is not 6001
	outStr << inodeInt;
	outStr << "[";
	outStr << inumberOfChildren ;
	outStr << "]";
	outStr << ":" ;
	outStr << idx;
	outStr << ":" ;
	outStr << coef;
	outStr << ":real:" ;
	return outStr.str();
}//getTokenNumber


std::string OSnLNodeVariable::getTokenName(){
	ostringstream outStr;
	// put in an error if inodeInt is not 6001
	outStr << snodeName;
	outStr << "[";
	outStr << inumberOfChildren ;
	outStr << "]";
	outStr << ":" ;
	outStr << idx;
	outStr << ":" ;
	outStr << coef;
	outStr << ":real:" ;
	return outStr.str();
}//getTokenNumber


std::string OSnLNodeVariable::getNonlinearExpressionInXML(){
	ostringstream outStr;
	outStr << "<" ;
	outStr << snodeName;
		outStr << "  idx=\"";
		outStr << idx ;
		outStr << "\"";
		outStr << "  coef=\"";
		outStr << coef ;
		outStr << "\"";
	if(inumberOfChildren > 0) {
		outStr << ">";
	}
	else{
		outStr << "/>";
	}
	if(inumberOfChildren > 0){
		for(int i = 0; i < inumberOfChildren; i++){
			outStr << m_mChildren[i]->getNonlinearExpressionInXML();
		}
	}
	if(inumberOfChildren > 0) {
		outStr << "</" ;
		outStr << snodeName ;
		outStr << ">" ;
	}
	return outStr.str();
}//getPrefix

double OSnLNodeVariable::calculateFunction(double *x){
	m_dFunctionValue = coef*x[idx];
	return m_dFunctionValue;
}// end OSnLNodeVariable::calculate

AD<double> OSnLNodeVariable::constructCppADTape(std::map<int, int> *varIdx, CppAD::vector< AD<double> > *XAD){
	m_CppADTape = coef;
	//std::cout << "Inside OSnLNodeVariable "<<  std::endl;
	//std::cout << "Value of OSiL index = " << idx << std::endl;
	//std::cout << "Value of CppAD index = " << (*varIdx)[ idx] << std::endl;
	//std::cout << "Value of CppAD variable = " << (*XAD)[ (*varIdx)[ idx] ] << std::endl;
	m_CppADTape = coef*(*XAD)[ (*varIdx)[ idx] ];
	return m_CppADTape;
}// end OSnLNodeVariable::constructCppADTape


void OSnLNodeVariable::getVariableIndexMap(std::map<int, int> *varIdx){
	int numVars;
	if( (*varIdx).find( idx) != (*varIdx).end() ){
		//std::cout  << "Index already in the map " << idx <<  std::endl;
	}
	else{ // variable to map with variable index as the key
		//std::cout << "Found a new index to add to the map " << idx << std::endl;
		numVars = (*varIdx).size();
		//std::cout << "numVars =  " << numVars << std::endl;
		(*varIdx)[ idx] = numVars;
	}
	//std::cout << "Value of index = " << (*varIdx)[ idx] << std::endl;
}//getVariableIndexMap


OSnLNode* OSnLNodeVariable::cloneOSnLNode(){
	OSnLNode *nlNodePoint;
	nlNodePoint = new OSnLNodeVariable();
	return  nlNodePoint;
}//end OSnLNodeVariable::cloneOSnLNode
           






