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
}//end OSExpressionTree

 
OSExpressionTree::~OSExpressionTree(){
	//#ifdef DEBUG  
	cout << "Inside the OSExpressionTree Destructor" << endl;
	//#endif
	delete m_treeRoot;
	m_treeRoot = NULL;
}//end ~OSExpressionTree 


std::vector<OSnLNode*> OSExpressionTree::getPostfixFromExpressionTree(){
	m_treeRoot->getPostfixFromExpressionTree();
}//getPostfixFromExpressionTree


std::vector<OSnLNode*> OSExpressionTree::getPrefixFromExpressionTree(){
	m_treeRoot->getPrefixFromExpressionTree();
}//getPrefixFromExpressionTree


double OSExpressionTree::calculateFunction(double *x,  bool treeBuilt){
	if( treeBuilt == false){
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
	}
	else{
		for(m_mPosVarIdx = m_mVarIdx.begin(); m_mPosVarIdx != m_mVarIdx.end(); ++m_mPosVarIdx){
			m_vX.push_back( x[ m_mPosVarIdx->first] );
		}
	} 
	m_vY = (*f).Forward(0, m_vX) ;
	m_vX.clear();
	return m_vY[ 0];
}//calculateFunction

double *OSExpressionTree::calculateGradient(double *x, int numVar,  bool treeBuilt){
	if( treeBuilt == false){
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
	}
	for(m_mPosVarIdx = m_mVarIdx.begin(); m_mPosVarIdx != m_mVarIdx.end(); ++m_mPosVarIdx){
		m_vX.push_back( x[ m_mPosVarIdx->first] );
	}
 	std::vector<double> jac( m_mVarIdx.size() ); 	// Jacobian of f 
   	jac  = (*f).Jacobian( m_vX);	// Jacobian for operation sequence
	// print the results
	int i;
	double *returnVec;
	returnVec = new double[ numVar];
	for(i = 0; i < numVar; i++){
		// kipp -- don't zero this out here every time -- maybe make global
		returnVec[ i] = 0.0;
	}
	for(m_mPosVarIdx = m_mVarIdx.begin(); m_mPosVarIdx != m_mVarIdx.end(); ++m_mPosVarIdx){
			returnVec[ m_mPosVarIdx->first]  = jac[ m_mPosVarIdx->second];
			std::cout << "Partial with respect to " <<  m_mPosVarIdx->first << "  computed by CppAD = " << returnVec[ m_mPosVarIdx->first] << std::endl;
	}
	m_vX.clear();
	return returnVec;
}//calculateGradient

std::vector<SecondPartialStruct*>  OSExpressionTree::calculateHessian(double *x,  bool treeBuilt){
	if( treeBuilt == false){
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
	}
	// declare an array to hold the indicies
	int *hessianIdx;
	int numSparseVars = m_mVarIdx.size();
	hessianIdx = new int[ numSparseVars];
	int kount = 0;
	for(m_mPosVarIdx = m_mVarIdx.begin(); m_mPosVarIdx != m_mVarIdx.end(); ++m_mPosVarIdx){
		m_vX.push_back( x[ m_mPosVarIdx->first] );
		hessianIdx[ kount++] = m_mPosVarIdx->first;
	}
	// now go for second derivative
	std::vector<double> hess( numSparseVars * numSparseVars);
	hess = (*f).Hessian(m_vX, 0);
	// now get values
	std::vector<SecondPartialStruct*> secondPartialVector;
	struct SecondPartialStruct *secondPartial;
	int index_i, index_j;
	for(index_i = 0; index_i < numSparseVars; index_i++){
		for(index_j = 0; index_j < numSparseVars; index_j++){
			secondPartial = new SecondPartialStruct();
			secondPartial->index_i = hessianIdx[ index_i];
			secondPartial->index_j = hessianIdx[ index_j];
			secondPartial->secondPartial_ij = hess[ numSparseVars*index_i + index_j];
			secondPartialVector.push_back( secondPartial);
		}
	}
	m_vX.clear();
	return secondPartialVector;
}//calculateGradient

