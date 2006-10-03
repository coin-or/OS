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


double OSExpressionTree::calculateFunction(double *x,  bool functionEvaluated){
	if( functionEvaluated == false){
		// map the variables
		m_treeRoot->getVariableIndexMap( &m_mVarIdx);		
		// convert the double x vector to an AD vector
		for(m_mPosVarIdx = m_mVarIdx.begin(); m_mPosVarIdx != m_mVarIdx.end(); ++m_mPosVarIdx){
			m_vXAD.push_back( x[ m_mPosVarIdx->first] );
		}
		CppAD::Independent( m_vXAD);
		m_CppADTree = m_treeRoot->constructCppADTree(&m_mVarIdx, &m_vXAD);
		std::cout << "VALUE =  " << m_CppADTree << std::endl;
		m_vZ.push_back( m_CppADTree) ;
		f(m_vXAD, m_vZ);
	}
	vector<double> Y( 1);
	vector<double> X;
	for(m_mPosVarIdx = m_mVarIdx.begin(); m_mPosVarIdx != m_mVarIdx.end(); ++m_mPosVarIdx){
		X.push_back( x[ m_mPosVarIdx->first] );
	}
	Y = f.Forward(0, X);
	std::cout << "VALUE =  " << Y[0] << std::endl;
	//
	//
	size_t m = 1;
	size_t n = 2;
 	vector<double> jac(m * n); // Jacobian of f (m by n matrix)
   	jac  = f.Jacobian(X);      // Jacobian for operation sequence
	// print the results
   	std::cout << "Partial with respect to x0 computed by CppAD = " << jac[0] << std::endl;
	std::cout << "Partial with respect to x1 computed by CppAD = " << jac[1] << std::endl;
	// now go for second derivative
	vector<double> hess(n * n);
	hess = f.Hessian(X, 0);
	std::cout << "second derivative " << hess[0] << std::endl;
	std::cout << "second derivative " << hess[1] << std::endl;
	std::cout << "second derivative " << hess[2] << std::endl;
	std::cout << "second derivative " << hess[3] << std::endl;
	//
	//
	return m_dfunctionValue;
}//calculateFunction

