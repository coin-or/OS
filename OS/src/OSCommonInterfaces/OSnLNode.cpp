/* $Id$ */
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
//#define DEBUGOSNLNODE

#include "OSnLNode.h"
#include "OSErrorClass.h"
#include "OSParameters.h"
#include "OSMathUtil.h"


#ifdef COIN_HAS_CPPAD  
#include<cppad/cppad.hpp>
using CppAD::vector;
typedef AD<double>  ADdouble;
#else
using std::vector;
#endif


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
//	"triangularDist", "triangularCum", "triangularInv", "unitNormalLinearLoss", erf
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
//	4621, 4622, 4623, 4624,4625
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
		unsigned int i;
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
		for(unsigned int i = 0; i < inumberOfChildren; i++)
			m_mChildren[i]->preOrderOSnLNodeTraversal( prefixVector);
	}
	return *prefixVector;
}//end preOrderOSnLNodeTraversal


std::string OSnLNode::getTokenNumber(){
	ostringstream outStr;
	outStr << inodeInt;
	// when I creat an OSnLNode from a token number, I need to know how many children there are
//	if(inodeType == -1){
		outStr << "[";
		outStr << inumberOfChildren ;
		outStr << "]";
//	}
	return outStr.str();
}//getTokenNumber


//std::string OSnLNode::getTokenName(){
//	ostringstream outStr;
//	outStr << this->snodeName;
//	if(inodeType == -1){
//		outStr << "[";
//		outStr << inumberOfChildren ;
//		outStr << "]";
//	}
//	return outStr.str();
//}//getTokenNumber


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
	outStr << this->getTokenName();
#ifdef DEBUGOSNLNODE
	cout << "nonlinear node " << this->getTokenName() << endl;
#endif
	if(inumberOfChildren > 0) {
		outStr << ">";
	}
	else{
		outStr << "/>";
	}
	if(inumberOfChildren > 0){
		for(unsigned int i = 0; i < inumberOfChildren; i++){
			outStr << m_mChildren[i]->getNonlinearExpressionInXML();
		}
	}
	if(inumberOfChildren > 0) {
		outStr << "</" ;
		outStr << this->getTokenName() ;
		outStr << ">" ;
	}
	return outStr.str();
}//getNonlinearExpressionInXML()
//
//


void OSnLNode::getVariableIndexMap(std::map<int, int> *varIdx){
	unsigned int i;
	if(inodeInt != OS_VARIABLE){
		for(i = 0; i < inumberOfChildren; i++){
			m_mChildren[ i]->getVariableIndexMap( varIdx);
		}
	}
}//getVariableIndexMap

bool OSnLNode::IsEqual(OSnLNode *that)
{
	#ifdef DEBUG_ISEQUAL_ROUTINES
		cout << "Start comparing in OSnLNode" << endl;
	#endif
	if (this == NULL)
	{	if (that == NULL)
			return true;
		else
		{
			#ifdef DEBUG_ISEQUAL_ROUTINES
				cout << "First object is NULL, second is not" << endl;
			#endif
			return false;
		}
	}
	else 
	{	if (that == NULL)
		{
			#ifdef DEBUG_ISEQUAL_ROUTINES
				cout << "Second object is NULL, first is not" << endl;
			#endif
			return false;
		}
		else	
		{
			if (this->inumberOfChildren != that->inumberOfChildren)
				return false;
			if (this->inodeInt != that->inodeInt)
				return false;
			if (this->inodeType != that->inodeType)
				return false;

			for (int i=0; i<this->inumberOfChildren; i++)
				if (!this->m_mChildren[i]->IsEqual(that->m_mChildren[i]))
					return false;

			return true;
		}
	}
}//OSnLNode::IsEqual


// OSnLNodePlus Methods	
OSnLNodePlus::OSnLNodePlus()
{

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
	for(unsigned int i = 0; i < inumberOfChildren; i++){
		if( m_mChildren[ i] != NULL) delete m_mChildren[ i];
		m_mChildren[i] = NULL;
	}
	//m_mChildren = NULL;
	if(inumberOfChildren > 0 && m_mChildren != NULL) delete[]  m_mChildren;
}//end ~OSnLNodePlus

std::string OSnLNodePlus::getTokenName(){
	return "plus";
}// end OSnLNodePlus::getTokenName()


double OSnLNodePlus::calculateFunction(double *x){
	m_dFunctionValue = m_mChildren[0]->calculateFunction(x) + m_mChildren[1]->calculateFunction(x);
	return m_dFunctionValue;
}// end OSnLNodePlus::calculate


ADdouble OSnLNodePlus::constructADTape(std::map<int, int> *ADIdx, vector< ADdouble > *XAD){
	m_ADTape = m_mChildren[0]->constructADTape( ADIdx,  XAD) + m_mChildren[1]->constructADTape( ADIdx,  XAD);
	return m_ADTape;
}// end OSnLNodePlus::constructADTape


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
	inodeInt = 1002;
	inodeType = -1;
}//end OSnLNodeSum

OSnLNodeSum::~OSnLNodeSum(){
	#ifdef DEBUGOSNLNODE
	cout << "inside OSnLNodeSum destructor" << endl;
	#endif
	if(inumberOfChildren > 0){
		for(unsigned int i = 0; i < inumberOfChildren; i++){
			delete m_mChildren[ i];
			m_mChildren[i] = NULL;
		}
	}
	//m_mChildren = NULL; 
	if(inumberOfChildren > 0 && m_mChildren != NULL) delete[]  m_mChildren;
}//end ~OSnLNodeSum

std::string OSnLNodeSum::getTokenName(){
	return "sum";
}// end OSnLNodeSum::getTokenName()

double OSnLNodeSum::calculateFunction(double *x){
	m_dFunctionValue = 0.0;  
	unsigned int i;
	for(i = 0; i < inumberOfChildren; i++){
		m_dFunctionValue = m_dFunctionValue + m_mChildren[i]->calculateFunction(x);
	}
	return m_dFunctionValue;
}// end OSnLNodeSum::calculate


ADdouble OSnLNodeSum::constructADTape(std::map<int, int> *ADIdx, vector< ADdouble > *XAD){
	m_ADTape = 0.0;
	unsigned int i;
	for(i = 0; i < inumberOfChildren; i++){
			m_ADTape = m_ADTape + m_mChildren[i]->constructADTape( ADIdx, XAD);
	}
	return m_ADTape;
}// end OSnLNodeSum::constructADTape

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
	inodeInt = 7016;
	inodeType = -1;
}//end OSnLNodeAllDiff


OSnLNodeAllDiff::~OSnLNodeAllDiff(){
	#ifdef DEBUGOSNLNODE
	cout << "inside OSnLNodeAllDiff destructor" << endl;
	#endif
	if(inumberOfChildren > 0){
		for(unsigned int i = 0; i < inumberOfChildren; i++){
			delete m_mChildren[ i];
			m_mChildren[i] = NULL;
		}
	}
	//m_mChildren = NULL;
	if(inumberOfChildren > 0 && m_mChildren != NULL) delete[]  m_mChildren;
}//end ~OSnLNodeAllDiff

std::string OSnLNodeAllDiff::getTokenName(){
	return "allDiff";
}// end OSnLNodeAllDiff::getTokenName(


double OSnLNodeAllDiff::calculateFunction(double *x){
	m_dFunctionValue = 1;
	// return a false if not all all different
	unsigned int i, k;
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


ADdouble OSnLNodeAllDiff::constructADTape(std::map<int, int> *ADIdx, vector< ADdouble > *XAD){
	try{
		throw ErrorClass("AllDifferent operator not supported by current Algorithmic Differentiation implementation");
		return m_ADTape;
	}
	catch(const ErrorClass& eclass){
		throw ErrorClass( eclass.errormsg);
	}
	return m_ADTape;
}// end OSnLNodeAllDiff::constructADTape


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
	inodeInt = 4011;
	inodeType = -1;
}//end OSnLNodeMax

OSnLNodeMax::~OSnLNodeMax(){
	#ifdef DEBUGOSNLNODE
	cout << "inside OSnLNodeMax destructor" << endl;
	#endif
	if(inumberOfChildren > 0){
		for(unsigned int i = 0; i < inumberOfChildren; i++){
			delete m_mChildren[ i];
			m_mChildren[i] = NULL;
		}
	}
	//m_mChildren = NULL;
	if(inumberOfChildren > 0 && m_mChildren != NULL) delete[]  m_mChildren;
}//end ~OSnLNodeMax

double OSnLNodeMax::calculateFunction(double *x){
	m_dFunctionValue = m_mChildren[0]->calculateFunction(x);
	if(inumberOfChildren > 1){
		for(unsigned int i = 1; i < inumberOfChildren; i++){
			if(m_mChildren[i]->calculateFunction(x) > m_dFunctionValue){
				m_dFunctionValue = 	m_mChildren[i]->calculateFunction(x);
			}
		}
	}
	return m_dFunctionValue;
}// end OSnLNodeMax::calculate

std::string OSnLNodeMax::getTokenName(){
	return "max";
}// end OSnLNodeMax::getTokenName(


ADdouble OSnLNodeMax::constructADTape(std::map<int, int> *ADIdx, vector< ADdouble > *XAD){
	//if not support in AD, throw an exception
	try{
		throw ErrorClass("Max operator not supported by current Algorithmic Differentiation implementation");
		return m_ADTape;
	}
	catch(const ErrorClass& eclass){
		throw ErrorClass( eclass.errormsg);
	}
}// end OSnLNodeMax::constructADTape


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
	inodeInt = 4010;
	inodeType = -1;
}//end OSnLNodeMin

OSnLNodeMin::~OSnLNodeMin(){
	#ifdef DEBUGOSNLNODE
	cout << "inside OSnLNodeMin destructor" << endl;
	#endif
	if(inumberOfChildren > 0){
		for(unsigned int i = 0; i < inumberOfChildren; i++){
			delete m_mChildren[ i];
			m_mChildren[i] = NULL;
		}
	}
	if(inumberOfChildren > 0 && m_mChildren != NULL) delete[]  m_mChildren;
	//m_mChildren = NULL;
}//end ~OSnLNodeMin


std::string OSnLNodeMin::getTokenName(){
	return "min";
}// end OSnLNodeMin::getTokenName(

double OSnLNodeMin::calculateFunction(double *x){
	m_dFunctionValue = m_mChildren[0]->calculateFunction(x);
	if(inumberOfChildren > 1){
		for(unsigned int i = 1; i < inumberOfChildren; i++){
			if(m_mChildren[i]->calculateFunction(x) < m_dFunctionValue){
				m_dFunctionValue = 	m_mChildren[i]->calculateFunction(x);
			}
		}
	}
	return m_dFunctionValue;
}// end OSnLNodeMin::calculate


ADdouble OSnLNodeMin::constructADTape(std::map<int, int> *ADIdx, vector< ADdouble > *XAD){
	//if not support in AD, throw an exception
	try{
		throw ErrorClass("Min operator not supported by current Algorithmic Differentiation implementation");
		return m_ADTape;
	}
	catch(const ErrorClass& eclass){
		throw ErrorClass( eclass.errormsg);
	}
}// end OSnLNodeMin::constructADTape


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
	inodeInt = 1003;
	inodeType = 2;
}//end OSnLNodeMinus

 
OSnLNodeMinus::~OSnLNodeMinus(){
	#ifdef DEBUGOSNLNODE
	cout << "inside OSnLNodeMinus destructor" << endl;
	#endif
	for(unsigned int i = 0; i < inumberOfChildren; i++){
		delete m_mChildren[ i];
		m_mChildren[i] = NULL;
	}
	//m_mChildren = NULL;
	if(inumberOfChildren > 0 && m_mChildren != NULL) delete[]  m_mChildren;
}//end ~OSnLNodeMinus

std::string OSnLNodeMinus::getTokenName(){
	return "minus";
}// end OSnLNodeSum::getTokenName(

double OSnLNodeMinus::calculateFunction(double *x){
	m_dFunctionValue =  m_mChildren[0]->calculateFunction( x) - m_mChildren[1]->calculateFunction( x);
	return m_dFunctionValue;
}// end OSnLNodeMinus::calculate


ADdouble OSnLNodeMinus::constructADTape(std::map<int, int> *ADIdx, vector< ADdouble > *XAD){
	m_ADTape = m_mChildren[0]->constructADTape( ADIdx, XAD) - m_mChildren[1]->constructADTape( ADIdx, XAD);
	return m_ADTape;
}// end OSnLNodeMinus::constructADTape


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
	inodeInt = 1004;
	inodeType = 1;
}//end OSnLNodeNegate

 
OSnLNodeNegate::~OSnLNodeNegate(){
	#ifdef DEBUGOSNLNODE
	cout << "inside OSnLNodeNegate destructor" << endl;
	#endif
	for(unsigned int i = 0; i < inumberOfChildren; i++){
		delete m_mChildren[ i];
		m_mChildren[i] = NULL;
	}
	//m_mChildren = NULL;
	if(inumberOfChildren > 0 && m_mChildren != NULL) delete[]  m_mChildren;
}//end ~OSnLNodeNegate

std::string OSnLNodeNegate::getTokenName(){
	return "negate";
}// end OSnLNodeNegate::getTokenName(

double OSnLNodeNegate::calculateFunction(double *x){
	m_dFunctionValue =  -m_mChildren[0]->calculateFunction( x) ;
	return m_dFunctionValue;
}// end OSnLNodeMinus::calculate

ADdouble OSnLNodeNegate::constructADTape(std::map<int, int> *ADIdx, vector< ADdouble > *XAD){
	m_ADTape = -m_mChildren[0]->constructADTape( ADIdx, XAD);
	return m_ADTape;
}// end OSnLNodeNegate::constructADTape


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
	inodeInt = 1005;
	inodeType = 2;
}//end OSnLNodeTimes

 
OSnLNodeTimes::~OSnLNodeTimes(){
	#ifdef DEBUGOSNLNODE
	cout << "inside OSnLNodeTimes destructor" << endl;
	#endif
	for(unsigned int i = 0; i < inumberOfChildren; i++){
		delete m_mChildren[ i];
		m_mChildren[i] = NULL;
	}
	//m_mChildren = NULL;
	if(inumberOfChildren > 0 && m_mChildren != NULL) delete[]  m_mChildren;
}//end ~OSnLNodeTimes

std::string OSnLNodeTimes::getTokenName(){
	return "times";
}// end OSnLNodeTimes::getTokenName(

double OSnLNodeTimes::calculateFunction(double *x){
	m_dFunctionValue = m_mChildren[0]->calculateFunction( x)*m_mChildren[1]->calculateFunction( x);
	return m_dFunctionValue;
}// end OSnLNodeTimes::calculate


ADdouble OSnLNodeTimes::constructADTape(std::map<int, int> *ADIdx, vector< ADdouble > *XAD){
	m_ADTape = m_mChildren[0]->constructADTape( ADIdx, XAD) * m_mChildren[1]->constructADTape( ADIdx, XAD);
	return m_ADTape;
}// end OSnLNodeTimes::constructADTape

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
	inodeInt = 1006;
	inodeType = 2;
}//end OSnLNodeDivide

 
OSnLNodeDivide::~OSnLNodeDivide(){
	#ifdef DEBUGOSNLNODE
	cout << "inside OSnLNodeDivide destructor" << endl;
	#endif
	for(unsigned int i = 0; i < inumberOfChildren; i++){
		delete m_mChildren[ i];
		m_mChildren[i] = NULL;
	}
	//m_mChildren = NULL;
	if(inumberOfChildren > 0 && m_mChildren != NULL) delete[]  m_mChildren;
}//end ~OSnLNodeDivide

std::string OSnLNodeDivide::getTokenName(){
	return "divide";
}// end OSnLNodeDivide::getTokenName(

double OSnLNodeDivide::calculateFunction(double *x){
	// kipp throw error if we divide by 0
	m_dFunctionValue = m_mChildren[0]->calculateFunction( x)/m_mChildren[1]->calculateFunction( x);
	return m_dFunctionValue;
}// end OSnLNodeDivide::calculate


ADdouble OSnLNodeDivide::constructADTape(std::map<int, int> *ADIdx, vector< ADdouble > *XAD){
	m_ADTape = m_mChildren[0]->constructADTape( ADIdx, XAD) / m_mChildren[1]->constructADTape( ADIdx, XAD);
	return m_ADTape;
}// end OSnLNodeDivide::constructADTape


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
	inodeInt = 1009;
	inodeType = 2;
}//end OSnLNodePower

 
OSnLNodePower::~OSnLNodePower(){
	#ifdef DEBUGOSNLNODE
	cout << "inside OSnLNodePower destructor" << endl;
	#endif
	for(unsigned int i = 0; i < inumberOfChildren; i++){
		delete m_mChildren[ i];
		m_mChildren[i] = NULL;
	}
	//m_mChildren = NULL;
	if(inumberOfChildren > 0 && m_mChildren != NULL) delete[]  m_mChildren;
}//end ~OSnLNodePower 

std::string OSnLNodePower::getTokenName(){
	return "power";
}// end OSnLNodePower::getTokenName(

double OSnLNodePower::calculateFunction(double *x){
	// kipp throw error if operation not defined
	m_dFunctionValue =  pow(m_mChildren[0]->calculateFunction( x), m_mChildren[1]->calculateFunction( x));
	return  m_dFunctionValue;
}// end OSnLNodePower::calculate

//
ADdouble OSnLNodePower::constructADTape(std::map<int, int> *ADIdx, vector< ADdouble > *XAD){
	//if( typeid( *m_mChildren[1]) == typeid( OSnLNodeNumber) ) {
	if( this->m_mChildren[1]->inodeInt == 5001 ) {
		OSnLNodeNumber *numberNode  =  (OSnLNodeNumber*)m_mChildren[1];
		// we have a number node see if interger
		if( (numberNode->value) == int( numberNode->value)){
			m_ADTape =  pow(m_mChildren[0]->constructADTape( ADIdx, XAD) ,  int( numberNode->value));
		}	
		else m_ADTape = pow(m_mChildren[0]->constructADTape( ADIdx, XAD) , m_mChildren[1]->constructADTape( ADIdx, XAD) );	
	}
	else{
		m_ADTape = pow(m_mChildren[0]->constructADTape( ADIdx, XAD) , m_mChildren[1]->constructADTape( ADIdx, XAD) );	
	}
	return m_ADTape;
}// end OSnLNodePower::constructADTape



//ADdouble OSnLNodePower::constructADTape(std::map<int, int> *ADIdx, vector< ADdouble > *XAD){	
//		m_ADTape = AD::pow(m_mChildren[0]->constructADTape( ADIdx, XAD) , m_mChildren[1]->constructADTape( ADIdx, XAD) );	
//	return m_ADTape;
//}// end OSnLNodePower::constructADTape





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
	inodeInt = 1010;
	inodeType = -1;
}//end OSnLNodeProduct

 
OSnLNodeProduct::~OSnLNodeProduct(){
	#ifdef DEBUGOSNLNODE
	cout << "inside OSnLNodeProduct destructor" << endl;
	#endif
	if(inumberOfChildren > 0){
		for(unsigned int i = 0; i < inumberOfChildren; i++){
			delete m_mChildren[ i];
			m_mChildren[i] = NULL;
		}
	}
	//m_mChildren = NULL;
	if(inumberOfChildren > 0 && m_mChildren != NULL) delete[]  m_mChildren;
}//end ~OSnLNodeProduct

std::string OSnLNodeProduct::getTokenName(){
	return "product";
}// end OSnLNodeProduct::getTokenName(

double OSnLNodeProduct::calculateFunction(double *x){
	// kipp throw error if operation not defined
	m_dFunctionValue = 1.0;
	unsigned int i;
	for(i = 0; i < inumberOfChildren; i++){
		m_dFunctionValue = m_dFunctionValue*m_mChildren[i]->calculateFunction(x);
	}
	return m_dFunctionValue;
}// end OSnLNodeProduct::calculate


ADdouble OSnLNodeProduct::constructADTape(std::map<int, int> *ADIdx, vector< ADdouble > *XAD){
	m_ADTape = 1.0;
	unsigned int i;
	for(i = 0; i < inumberOfChildren; i++){
		m_ADTape = m_ADTape*m_mChildren[i]->constructADTape( ADIdx, XAD);
	}
	return m_ADTape;
}// end OSnLNodeProduct::constructADTape


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
	inodeInt = 2007;
	inodeType = 1;
}//end OSnLNodeLn

 
OSnLNodeLn::~OSnLNodeLn(){
	#ifdef DEBUGOSNLNODE
	cout << "inside OSnLNodeLn destructor" << endl;
	#endif
	for(unsigned int i = 0; i < inumberOfChildren; i++){
		delete m_mChildren[ i];
		m_mChildren[i] = NULL;
	}
	//m_mChildren = NULL;
	if(inumberOfChildren > 0 && m_mChildren != NULL) delete[]  m_mChildren;
}//end ~OSnLNodeLn

std::string OSnLNodeLn::getTokenName(){
	return "ln";
}// end OSnLNodeLn::getTokenName(

double OSnLNodeLn::calculateFunction(double *x){
	m_dFunctionValue = log(m_mChildren[0]->calculateFunction( x) );
	return m_dFunctionValue;
}// end OSnLNodeLn::calculate


ADdouble OSnLNodeLn::constructADTape(std::map<int, int> *ADIdx, vector< ADdouble > *XAD){
	m_ADTape = log( m_mChildren[0]->constructADTape( ADIdx, XAD) );
	return m_ADTape;
}// end OSnLNodeLn::constructADTape

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
	inodeInt = 2006;
	inodeType = 1;
}//end OSnLNodeSqrt

 
OSnLNodeSqrt::~OSnLNodeSqrt(){
	#ifdef DEBUGOSNLNODE
	cout << "inside OSnLNodeSqrt destructor" << endl;
	#endif
	for(unsigned int i = 0; i < inumberOfChildren; i++){
		delete m_mChildren[ i];
		m_mChildren[i] = NULL;
	}
	//m_mChildren = NULL;
	if(inumberOfChildren > 0 && m_mChildren != NULL) delete[]  m_mChildren;
}//end ~OSnLNodeSqrt

std::string OSnLNodeSqrt::getTokenName(){
	return "sqrt";
}// end OSnLNodeSqrt::getTokenName(

double OSnLNodeSqrt::calculateFunction(double *x){
	m_dFunctionValue = sqrt(m_mChildren[0]->calculateFunction( x) );
	return m_dFunctionValue;
}// end OSnLNodeSqrt::calculate


ADdouble OSnLNodeSqrt::constructADTape(std::map<int, int> *ADIdx, vector< ADdouble > *XAD){
	m_ADTape = sqrt( m_mChildren[0]->constructADTape( ADIdx, XAD) );
	return m_ADTape;
}// end OSnLNodeSqrt::constructADTape

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
	inodeInt = 2005;
	inodeType = 1;
}//end OSnLNodeSquare

 
OSnLNodeSquare::~OSnLNodeSquare(){
	#ifdef DEBUGOSNLNODE
	cout << "inside OSnLNodeSquare destructor" << endl;
	#endif
	for(unsigned int i = 0; i < inumberOfChildren; i++){
		delete m_mChildren[ i];
		m_mChildren[i] = NULL;
	}
	//m_mChildren = NULL;
	if(inumberOfChildren > 0 && m_mChildren != NULL) delete[]  m_mChildren;
}//end ~OSnLNodeSquare

std::string OSnLNodeSquare::getTokenName(){
	return "square";
}// end OSnLNodeSquare::getTokenName(

double OSnLNodeSquare::calculateFunction(double *x){
	m_dFunctionValue = pow( (m_mChildren[0]->calculateFunction( x) ), 2);
	return m_dFunctionValue;
}// end OSnLNodeSquare::calculate


ADdouble OSnLNodeSquare::constructADTape(std::map<int, int> *ADIdx, vector< ADdouble > *XAD){
	m_ADTape = pow( m_mChildren[0]->constructADTape( ADIdx, XAD), int( 2) );
	return m_ADTape;
}// end OSnLNodeSquare::constructADTape

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
	inodeInt = 3001;
	inodeType = 1;
}//end OSnLNodeSin

 
OSnLNodeSin::~OSnLNodeSin(){
	#ifdef DEBUGOSNLNODE
	cout << "inside OSnLNodeSin destructor" << endl;
	#endif
	for(unsigned int i = 0; i < inumberOfChildren; i++){
		delete m_mChildren[ i];
		m_mChildren[i] = NULL;
	}
	//m_mChildren = NULL;
	if(inumberOfChildren > 0 && m_mChildren != NULL) delete[]  m_mChildren;
}//end ~OSnLNodeSin

std::string OSnLNodeSin::getTokenName(){
	return "sin";
}// end OSnLNodeSin::getTokenName(

double OSnLNodeSin::calculateFunction(double *x){
	m_dFunctionValue = sin(m_mChildren[0]->calculateFunction( x) );
	return m_dFunctionValue;
}// end OSnLNodeSin::calculate


ADdouble OSnLNodeSin::constructADTape(std::map<int, int> *ADIdx, vector< ADdouble > *XAD){
	m_ADTape = sin( m_mChildren[0]->constructADTape( ADIdx, XAD) );
	return m_ADTape;
}// end OSnLNodeSin::constructADTape

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
	inodeInt = 3002;
	inodeType = 1;
}//end OSnLNodeCos

 
OSnLNodeCos::~OSnLNodeCos(){
	#ifdef DEBUGOSNLNODE
	cout << "inside OSnLNodeCos destructor" << endl;
	#endif
	for(unsigned int i = 0; i < inumberOfChildren; i++){
		delete m_mChildren[ i];
		m_mChildren[i] = NULL;
	}
	//m_mChildren = NULL;
	if(inumberOfChildren > 0 && m_mChildren != NULL) delete[]  m_mChildren;
}//end ~OSnLNodeCos

std::string OSnLNodeCos::getTokenName(){
	return "cos";
}// end OSnLNodeCos::getTokenName(

double OSnLNodeCos::calculateFunction(double *x){
	m_dFunctionValue = cos(m_mChildren[0]->calculateFunction( x) );
	return m_dFunctionValue;
}// end OSnLNodeCos::calculate


ADdouble OSnLNodeCos::constructADTape(std::map<int, int> *ADIdx, vector< ADdouble > *XAD){
	m_ADTape = cos( m_mChildren[0]->constructADTape( ADIdx, XAD) );
	return m_ADTape;
}// end OSnLNodeCos::constructADTape

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
	inodeInt = 2010;
	inodeType = 1;
}//end OSnLNodeExp

 
OSnLNodeExp::~OSnLNodeExp(){
	#ifdef DEBUGOSNLNODE
	cout << "inside OSnLNodeExp destructor" << endl;
	#endif
	for(unsigned int i = 0; i < inumberOfChildren; i++){
		delete m_mChildren[ i];
		m_mChildren[i] = NULL;
	}
	//m_mChildren = NULL;
	if(inumberOfChildren > 0 && m_mChildren != NULL) delete[]  m_mChildren;
}//end ~OSnLNodeExp

std::string OSnLNodeExp::getTokenName(){
	return "exp";
}// end OSnLNodeExp::getTokenName(

double OSnLNodeExp::calculateFunction(double *x){
	m_dFunctionValue = exp(m_mChildren[0]->calculateFunction( x) );
	return m_dFunctionValue;
}// end OSnLNodeExp::calculate


ADdouble OSnLNodeExp::constructADTape(std::map<int, int> *ADIdx, vector< ADdouble > *XAD){
	m_ADTape = exp( m_mChildren[0]->constructADTape( ADIdx, XAD) );
	return m_ADTape;
}// end OSnLNodeExp::constructADTape

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
	inodeInt = 2001;
	inodeType = 1;
}//end OSnLNodeLn

 
OSnLNodeAbs::~OSnLNodeAbs(){
	#ifdef DEBUGOSNLNODE
	cout << "inside OSnLNodeAbs destructor" << endl;
	#endif
	for(unsigned int i = 0; i < inumberOfChildren; i++){
		delete m_mChildren[ i];
		m_mChildren[i] = NULL;
	}
	//m_mChildren = NULL;
	if(inumberOfChildren > 0 && m_mChildren != NULL) delete[]  m_mChildren;
}//end ~OSnLNodeAbs

std::string OSnLNodeAbs::getTokenName(){
	return "abs";
}// end OSnLNodeAbs::getTokenName(

double OSnLNodeAbs::calculateFunction(double *x){
	m_dFunctionValue = fabs(m_mChildren[0]->calculateFunction( x) );
	return m_dFunctionValue;
}// end OSnLNodeAbs::calculate


ADdouble OSnLNodeAbs::constructADTape(std::map<int, int> *ADIdx, vector< ADdouble > *XAD){
	m_ADTape = abs( m_mChildren[0]->constructADTape( ADIdx, XAD) );
	return m_ADTape;
}// end OSnLNodeAbs::constructADTape

OSnLNode* OSnLNodeAbs::cloneOSnLNode(){
	OSnLNode *nlNodePoint;
	nlNodePoint = new OSnLNodeAbs();
	return  nlNodePoint;
}//end OSnLNodeAbs::cloneOSnLNode
//
//




//
// OSnLNodeErf Methods	
OSnLNodeErf::OSnLNodeErf()
{
	inumberOfChildren = 1;
	m_mChildren = new OSnLNode*[1];
	m_mChildren[ 0] = NULL;
	inodeInt = 4625;
	inodeType = 1;
}//end OSnLNodeErf

 
OSnLNodeErf::~OSnLNodeErf(){
	#ifdef DEBUGOSNLNODE
	cout << "inside OSnLNodeErf destructor" << endl;
	#endif
	for(unsigned int i = 0; i < inumberOfChildren; i++){
		delete m_mChildren[ i];
		m_mChildren[i] = NULL;
	}
	//m_mChildren = NULL;
	if(inumberOfChildren > 0 && m_mChildren != NULL) delete[]  m_mChildren;
}//end ~OSnLNodeErf

std::string OSnLNodeErf::getTokenName(){
	return "erf";
}// end OSnLNodeErf::getTokenName(

double OSnLNodeErf::calculateFunction(double *x){
	const double a = (993./880.);
	const double b =  (89./880.); 
	//m_dFunctionValue = fabs(m_mChildren[0]->calculateFunction( x) );
	m_dFunctionValue = tanh( (a + b * m_mChildren[0]->calculateFunction( x) * m_mChildren[0]->calculateFunction( x)) * m_mChildren[0]->calculateFunction( x) );
	//std::cout << "function value =   " << m_dFunctionValue << std::endl;
	return m_dFunctionValue;
}// end OSnLNodeErf::calculate


ADdouble OSnLNodeErf::constructADTape(std::map<int, int> *ADIdx, vector< ADdouble > *XAD){
/***
 * 
 * This is a fast approximation (few numerical operations) 
 * with relative error bound $latex 4 \times 10^{-4}$$; see 
 * Vedder, J.D., "Simple approximations for the error function and its inverse",
 * American Journal of Physics, v 55, n 8, 1987, p 762-3. I took this reference from 
 * Brad Bell's erf.hpp
 * 
 */
	const double a = (993./880.);
	const double b =  (89./880.); 

	//tanh( (a + b * x * x) * x );
	//m_ADTape = CppAD::erf( m_mChildren[0]->constructADTape( ADIdx, XAD) );
	m_ADTape = tanh( (a + b * m_mChildren[0]->constructADTape( ADIdx, XAD) * m_mChildren[0]->constructADTape( ADIdx, XAD)) * m_mChildren[0]->constructADTape( ADIdx, XAD) );

	return m_ADTape;
}// end OSnLNodeErf::constructADTape

OSnLNode* OSnLNodeErf::cloneOSnLNode(){
	OSnLNode *nlNodePoint;
	nlNodePoint = new OSnLNodeErf();
	return  nlNodePoint;
}//end OSnLNodeErf::cloneOSnLNode
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
	inodeInt = 7001;
	inodeType = 3;
}//end OSnLNodeIf

 
OSnLNodeIf::~OSnLNodeIf(){
	#ifdef DEBUGOSNLNODE
	cout << "inside OSnLNodeIf destructor" << endl;
	#endif 
	for(unsigned int i = 0; i < inumberOfChildren; i++){
		delete m_mChildren[ i];
		m_mChildren[i] = NULL;
	}
	//m_mChildren = NULL;
	if(inumberOfChildren > 0 && m_mChildren != NULL) delete[]  m_mChildren;
}//end ~OSnLNodeIf

std::string OSnLNodeIf::getTokenName(){
	return "if";
}// end OSnLNodeIf::getTokenName(

double OSnLNodeIf::calculateFunction(double *x){
	if(m_mChildren[0]->calculateFunction( x)  >= 0) m_dFunctionValue = m_mChildren[ 1]->calculateFunction( x);
		else m_dFunctionValue = m_mChildren[ 2]->calculateFunction( x);
	return m_dFunctionValue;
}// end OSnLNodeIf::calculate

ADdouble OSnLNodeIf::constructADTape(std::map<int, int> *ADIdx, vector< ADdouble > *XAD){
	//if not support in AD, throw an exception
	try{
		throw ErrorClass("if operator not supported by current Algorithmic Differentiation implementation");
		return m_ADTape;
	}
	catch(const ErrorClass& eclass){
		throw ErrorClass( eclass.errormsg);
	}
}// end OSnLNodeIf::constructADTape

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
	outStr << "number";
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
}//getTokenName


std::string OSnLNodeNumber::getNonlinearExpressionInXML(){
	ostringstream outStr;
	outStr << "<" ;
	outStr << this->getTokenName();
		outStr << "  value=\"";
		outStr << os_dtoa_format(value); 
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

ADdouble OSnLNodeNumber::constructADTape(std::map<int, int> *ADIdx, vector< ADdouble > *XAD){
	m_ADTape =  this->value;
	return m_ADTape;
}// end OSnLNodeNumber::constructADTape

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
	outStr << "E";
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
	outStr << "E";
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

ADdouble OSnLNodeE::constructADTape(std::map<int, int> *ADIdx, vector< ADdouble > *XAD){
	m_ADTape =  OS_E_VALUE;
	return m_ADTape;
}// end OSnLE::constructADTape

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
	outStr << "PI";
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
	outStr << "PI";
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

ADdouble OSnLNodePI::constructADTape(std::map<int, int> *ADIdx, vector< ADdouble > *XAD){
	m_ADTape =  OS_PI_VALUE;
	return m_ADTape;
}// end OSnLE::constructADTape

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
		for(unsigned int i = 0; i < inumberOfChildren; i++){
			delete m_mChildren[ i];
			m_mChildren[i] = NULL;
		}
	}
	//m_mChildren = NULL;
	if(inumberOfChildren > 0 && m_mChildren != NULL) delete[]  m_mChildren;
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
	outStr << "variable";
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
	outStr << "variable";
		outStr << "  idx=\"";
		outStr << idx ;
		outStr << "\"";
		outStr << "  coef=\"";
		outStr << os_dtoa_format(coef);
		outStr << "\"";
	if(inumberOfChildren > 0) {
		outStr << ">";
	}
	else{
		outStr << "/>";
	}
	if(inumberOfChildren > 0){
		for(unsigned int i = 0; i < inumberOfChildren; i++){
			outStr << m_mChildren[i]->getNonlinearExpressionInXML();
		}
	}
	if(inumberOfChildren > 0) {
		outStr << "</" ;
		outStr << "variable" ;
		outStr << ">" ;
	}
	return outStr.str();
}//getPrefix

double OSnLNodeVariable::calculateFunction(double *x){
	m_dFunctionValue = coef*x[idx];
	return m_dFunctionValue;
}// end OSnLNodeVariable::calculate

ADdouble OSnLNodeVariable::constructADTape(std::map<int, int> *varIdx, vector< ADdouble > *XAD){
	m_ADTape = coef;
	//std::cout << "Inside OSnLNodeVariable "<<  std::endl;
	//std::cout << "Value of OSiL index = " << idx << std::endl;
	//std::cout << "Value of AD index = " << (*varIdx)[ idx] << std::endl;
	//std::cout << "Value of AD variable = " << (*XAD)[ (*varIdx)[ idx] ] << std::endl;
	m_ADTape = coef*(*XAD)[ (*varIdx)[ idx] ];
	return m_ADTape;
}// end OSnLNodeVariable::constructADTape


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
           






