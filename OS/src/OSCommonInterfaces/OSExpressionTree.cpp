/** @file OSExpressionTree.cpp
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


#include "OSExpressionTree.h"
#include<vector>

using std::cout; 
using std::endl;

OSExpressionTree::OSExpressionTree(){
	m_treeRoot = NULL;
	m_bCppADTreeBuilt = false;
}//end OSExpressionTree

 
OSExpressionTree::~OSExpressionTree(){
	//#ifdef DEBUG  
	cout << "Inside the OSExpressionTree Destructor" << endl;
	//#endif
	delete m_treeRoot;
	m_treeRoot = NULL;
}//end ~OSExpressionTree 


std::vector<OSnLNode*> OSExpressionTree::getPostfixFromExpressionTree(){
	return m_treeRoot->getPostfixFromExpressionTree();
}//getPostfixFromExpressionTree


std::vector<OSnLNode*> OSExpressionTree::getPrefixFromExpressionTree(){
	return m_treeRoot->getPrefixFromExpressionTree();
}//getPrefixFromExpressionTree


double OSExpressionTree::calculateFunction( double *x, bool functionEvaluated){
	if( m_bCppADTreeBuilt == false){
		// map the variables
		m_treeRoot->getVariableIndexMap( &m_mVarIdx);		
		// convert the double x vector to an AD vector
		for(m_mPosVarIdx = m_mVarIdx.begin(); m_mPosVarIdx != m_mVarIdx.end(); ++m_mPosVarIdx){
			m_vXAD.push_back( x[ m_mPosVarIdx->first] );
		}
		CppAD::Independent( m_vXAD);
		m_CppADTree = m_treeRoot->constructCppADTree(&m_mVarIdx, &m_vXAD);
		m_vZ.push_back( m_CppADTree) ;
		f = new CppAD::ADFun<double>(m_vXAD, m_vZ);
		m_vY.push_back(0.0); 
		m_bCppADTreeBuilt = true;
	}
	if(functionEvaluated == true) return m_vY[ 0];
	m_vX.clear();
	for(m_mPosVarIdx = m_mVarIdx.begin(); m_mPosVarIdx != m_mVarIdx.end(); ++m_mPosVarIdx){
		m_vX.push_back( x[ m_mPosVarIdx->first] );
	}
	m_vY = (*f).Forward(0, m_vX) ;
	return m_vY[ 0];
}//calculateFunction

std::vector<FirstPartialStruct*> OSExpressionTree::calculateGradient( double *x, bool functionEvaluated){
	if( m_bCppADTreeBuilt == false){
		// map the variables
		m_treeRoot->getVariableIndexMap( &m_mVarIdx);		
		// convert the double x vector to an AD vector
		for(m_mPosVarIdx = m_mVarIdx.begin(); m_mPosVarIdx != m_mVarIdx.end(); ++m_mPosVarIdx){
			m_vXAD.push_back( x[ m_mPosVarIdx->first] );
		}
		CppAD::Independent( m_vXAD);
		m_CppADTree = m_treeRoot->constructCppADTree(&m_mVarIdx, &m_vXAD);
		m_vZ.push_back( m_CppADTree) ;
		f = new CppAD::ADFun<double>(m_vXAD, m_vZ);
		m_bCppADTreeBuilt = true;
	}
	if( functionEvaluated == false){
		m_vX.clear();
		for(m_mPosVarIdx = m_mVarIdx.begin(); m_mPosVarIdx != m_mVarIdx.end(); ++m_mPosVarIdx){
			m_vX.push_back( x[ m_mPosVarIdx->first] );
		}
	}
 	std::vector<double> jac( m_mVarIdx.size() ); 	// Jacobian of f 
   	jac  = (*f).Jacobian( m_vX);	// Jacobian for operation sequence
	// print the results
	std::vector<FirstPartialStruct*> firstPartialVector;
	struct FirstPartialStruct *firstPartial;
	for(m_mPosVarIdx = m_mVarIdx.begin(); m_mPosVarIdx != m_mVarIdx.end(); ++m_mPosVarIdx){
		firstPartial = new FirstPartialStruct();
		firstPartial->index_i = m_mPosVarIdx->first;
		firstPartial->firstPartial_i  = jac[ m_mPosVarIdx->second];
		firstPartialVector.push_back( firstPartial);
		std::cout << "Partial with respect to " <<  m_mPosVarIdx->first << "  computed by CppAD = " << jac[ m_mPosVarIdx->second] << std::endl;
	}
	return firstPartialVector;
}//calculateGradient

std::vector<SecondPartialStruct*>  OSExpressionTree::calculateHessian( double *x, bool functionEvaluated){
	if( m_bCppADTreeBuilt == false){
		// map the variables
		m_treeRoot->getVariableIndexMap( &m_mVarIdx);		
		// convert the double x vector to an AD vector
		for(m_mPosVarIdx = m_mVarIdx.begin(); m_mPosVarIdx != m_mVarIdx.end(); ++m_mPosVarIdx){
			m_vXAD.push_back( x[ m_mPosVarIdx->first] );
		}
		CppAD::Independent( m_vXAD);
		m_CppADTree = m_treeRoot->constructCppADTree(&m_mVarIdx, &m_vXAD);
		m_vZ.push_back( m_CppADTree) ;
		f = new CppAD::ADFun<double>(m_vXAD, m_vZ);
		m_bCppADTreeBuilt = true;
	}
	int numSparseVars = m_mVarIdx.size();
	if( functionEvaluated == false){
		m_vX.clear();
		for(m_mPosVarIdx = m_mVarIdx.begin(); m_mPosVarIdx != m_mVarIdx.end(); ++m_mPosVarIdx){
			m_vX.push_back( x[ m_mPosVarIdx->first] );
		}
	}
	// now go for second derivative
	std::vector<double> hess( numSparseVars * numSparseVars);
	hess = (*f).Hessian(m_vX, 0);
	// now get values
	std::vector<SecondPartialStruct*> secondPartialVector;
	struct SecondPartialStruct *secondPartial;
	for(m_mPosVarIdx = m_mVarIdx.begin(); m_mPosVarIdx != m_mVarIdx.end(); ++m_mPosVarIdx){
		for(m_mPosVarIdx2 = m_mVarIdx.begin(); m_mPosVarIdx2 != m_mVarIdx.end(); ++m_mPosVarIdx2){
			secondPartial = new SecondPartialStruct();
			secondPartial->index_i = m_mPosVarIdx->first;
			secondPartial->index_j = m_mPosVarIdx2->first;
			secondPartial->secondPartial_ij  = hess[ numSparseVars*m_mPosVarIdx->second + m_mPosVarIdx2->second];
			secondPartialVector.push_back( secondPartial);
		}
	}
	return secondPartialVector;
}//calculateGradient

std::vector<int> OSExpressionTree::getVariableIndicies(){
	m_treeRoot->getVariableIndexMap( &m_mVarIdx);
	std::vector<int> variableIndicies;
	for(m_mPosVarIdx = m_mVarIdx.begin(); m_mPosVarIdx != m_mVarIdx.end(); ++m_mPosVarIdx){
		variableIndicies.push_back(m_mPosVarIdx->first);
	}
	return variableIndicies;
}//getVariableIndicies

