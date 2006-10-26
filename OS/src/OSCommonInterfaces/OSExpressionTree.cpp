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

OSExpressionTree::OSExpressionTree():
	m_treeRoot( NULL),
	m_bCppADTreeBuilt( false),
	m_bIndexMapGenerated( false),
	mapVarIdx( NULL)
	{
}//end OSExpressionTree

 
OSExpressionTree::~OSExpressionTree(){
	//#ifdef DEBUG  
	cout << "Inside the OSExpressionTree Destructor" << endl;
	//#endif
	if(m_treeRoot != NULL) delete m_treeRoot;
	m_treeRoot = NULL;
	if(mapVarIdx != NULL) delete mapVarIdx;
	mapVarIdx = NULL;
	delete f;
	f = NULL;
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
		if( m_bIndexMapGenerated == false) getVariableIndiciesMap();
		m_treeRoot->getVariableIndexMap( mapVarIdx);		
		// convert the double x vector to an AD vector
		for(m_mPosVarIdx = (*mapVarIdx).begin(); m_mPosVarIdx != (*mapVarIdx).end(); ++m_mPosVarIdx){
			m_vXAD.push_back( x[ m_mPosVarIdx->first] );
		}
		CppAD::Independent( m_vXAD);
		m_CppADTree = m_treeRoot->constructCppADTree(mapVarIdx, &m_vXAD);
		m_vZ.push_back( m_CppADTree) ;
		f = new CppAD::ADFun<double>(m_vXAD, m_vZ);
		m_vY.push_back(0.0); 
		m_bCppADTreeBuilt = true;
	}
	if(functionEvaluated == true) return m_vY[ 0];
	m_vX.clear();
	for(m_mPosVarIdx = (*mapVarIdx).begin(); m_mPosVarIdx != (*mapVarIdx).end(); ++m_mPosVarIdx){
		m_vX.push_back( x[ m_mPosVarIdx->first] );
	}
	m_vY = (*f).Forward(0, m_vX) ;
	return m_vY[ 0];
}//calculateFunction

std::vector<double> OSExpressionTree::calculateGradient( double *x, bool functionEvaluated){
	// note x is a dense vector
	if( m_bCppADTreeBuilt == false){
		// map the variables
		if( m_bIndexMapGenerated == false) getVariableIndiciesMap();
		m_treeRoot->getVariableIndexMap( mapVarIdx);		
		// convert the double x vector to an AD vector
		for(m_mPosVarIdx = (*mapVarIdx).begin(); m_mPosVarIdx != (*mapVarIdx).end(); ++m_mPosVarIdx){
			m_vXAD.push_back( x[ m_mPosVarIdx->first] );
		}
		CppAD::Independent( m_vXAD);
		m_CppADTree = m_treeRoot->constructCppADTree(mapVarIdx, &m_vXAD);
		m_vZ.push_back( m_CppADTree) ;
		f = new CppAD::ADFun<double>(m_vXAD, m_vZ);
		m_bCppADTreeBuilt = true;
	}
	if( functionEvaluated == false){ 
		m_vX.clear();
		for(m_mPosVarIdx = (*mapVarIdx).begin(); m_mPosVarIdx != (*mapVarIdx).end(); ++m_mPosVarIdx){
			m_vX.push_back( x[ m_mPosVarIdx->first] );
		}
	}
 	std::vector<double> jac( (*mapVarIdx).size() ); 	// Jacobian of f 
   	jac  = (*f).Jacobian( m_vX);	// Jacobian for operation sequence
	// print the results
	for(m_mPosVarIdx = (*mapVarIdx).begin(); m_mPosVarIdx != (*mapVarIdx).end(); ++m_mPosVarIdx){
		std::cout << "Partial with respect to " <<  m_mPosVarIdx->first << "  computed by CppAD = " << jac[ m_mPosVarIdx->second] << std::endl;
	}
	return jac;
}//calculateGradient

std::vector<double>  OSExpressionTree::calculateHessian( double *x, bool functionEvaluated){
	if( m_bCppADTreeBuilt == false){
		// map the variables
		if( m_bIndexMapGenerated == false) getVariableIndiciesMap();
		m_treeRoot->getVariableIndexMap( mapVarIdx);		
		// convert the double x vector to an AD vector
		for(m_mPosVarIdx = (*mapVarIdx).begin(); m_mPosVarIdx != (*mapVarIdx).end(); ++m_mPosVarIdx){
			m_vXAD.push_back( x[ m_mPosVarIdx->first] );
		}
		CppAD::Independent( m_vXAD);
		m_CppADTree = m_treeRoot->constructCppADTree(mapVarIdx, &m_vXAD);
		m_vZ.push_back( m_CppADTree) ;
		f = new CppAD::ADFun<double>(m_vXAD, m_vZ);
		m_bCppADTreeBuilt = true;
	}
	int numSparseVars = (*mapVarIdx).size();
	if( functionEvaluated == false){
		m_vX.clear();
		for(m_mPosVarIdx = (*mapVarIdx).begin(); m_mPosVarIdx != (*mapVarIdx).end(); ++m_mPosVarIdx){
			m_vX.push_back( x[ m_mPosVarIdx->first] );
		}
	}
	// now go for second derivative
	std::vector<double> hess( numSparseVars * numSparseVars);
	hess = (*f).Hessian(m_vX, 0);
	// now get values
	std::vector<SecondPartialStruct*> secondPartialVector;
	struct SecondPartialStruct *secondPartial;
		std::cout << "HERE IS THE RESULT OF HESSIAN" << std::endl;
	for(m_mPosVarIdx = (*mapVarIdx).begin(); m_mPosVarIdx != (*mapVarIdx).end(); ++m_mPosVarIdx){
		for(m_mPosVarIdx2 = (*mapVarIdx).begin(); m_mPosVarIdx2 != (*mapVarIdx).end(); ++m_mPosVarIdx2){
			secondPartial = new SecondPartialStruct();
			secondPartial->index_i = m_mPosVarIdx->first;
			secondPartial->index_j = m_mPosVarIdx2->first;
			secondPartial->secondPartial_ij  = hess[ numSparseVars*m_mPosVarIdx->second + m_mPosVarIdx2->second];
			std::cout << secondPartial->secondPartial_ij << std::endl;
			secondPartialVector.push_back( secondPartial);
		}
	}
	return hess;
}//calculateHessian


std::vector<double>  OSExpressionTree::calculateHessianLag( double* x, int xdim, double* y, int ydim,
	double* z, int zdim, bool functionEvaluated){
	int i, hessdim;
	if( m_bCppADTreeBuilt == false){
		// map the variables
		if( m_bIndexMapGenerated == false) getVariableIndiciesMap();
		// x is a pointer to primal variables
		// y is a pointer to Lagrange multiplier on the constraints
		// z is a pointer to Lagrange multipliers on the objectives
		m_treeRoot->getVariableIndexMap( mapVarIdx);		
		// put the primal vector into m_vXAD
		for(i = 0; i < xdim; i++){
			m_vXAD.push_back( *(x + i) );
		}
		// declare the primal vectors as the independent vectors
		CppAD::Independent( m_vXAD);
		// now add in the Lagrangian variable before going to the OSExpression Tree
		for(i = 0; i < ydim; i++){
			m_vXAD.push_back( *(y + i) );	
		}
		for(i = 0; i < zdim; i++){
			m_vXAD.push_back( *(z + i) );	
		}
		m_CppADTree = m_treeRoot->constructCppADTree(mapVarIdx, &m_vXAD);
		m_vZ.push_back( m_CppADTree) ;
		f = new CppAD::ADFun<double>(m_vXAD, m_vZ);
		m_bCppADTreeBuilt = true;
	}
	if( functionEvaluated == false){
		m_vX.clear();
		for(i = 0; i < xdim; i++){
			m_vXAD.push_back( *(x + i) );	
		}
		for(i = 0; i < ydim; i++){
			m_vXAD.push_back( *(y + i) );	
		}
		for(i = 0; i < zdim; i++){
			m_vXAD.push_back( *(z + i) );	
		}
	}
	// now go for second derivative
	hessdim = xdim * xdim;
	std::vector<double> hess( hessdim);
	hess = (*f).Hessian(m_vX, 0);
	std::cout << "HERE IS THE RESULT OF HESSIANLAG"  << std::endl;
	for(i = 0; i < hessdim; i++){
		std::cout << hess[ i] << std::endl;
	}
	return hess;
}//calculateHessianLag

std::map<int, int> *OSExpressionTree::getVariableIndiciesMap(){
	if( m_bIndexMapGenerated == true) return mapVarIdx;
	mapVarIdx = new std::map<int, int>();
	m_treeRoot->getVariableIndexMap( mapVarIdx);
	std::cout << "SIZE OF MAP =  "  << (*mapVarIdx).size() << std::endl;
	int kount = 0;
	for(m_mPosVarIdx = (*mapVarIdx).begin(); m_mPosVarIdx != (*mapVarIdx).end(); ++m_mPosVarIdx){
		m_mPosVarIdx->second = kount++;
		std::cout <<  "POSITION FIRST =  "  << m_mPosVarIdx->first ;
		std::cout <<  "    POSITION SECOND = "  << m_mPosVarIdx->second << std::endl;
	}
	m_bIndexMapGenerated = true;
	return mapVarIdx;
}//getVariableIndicies

