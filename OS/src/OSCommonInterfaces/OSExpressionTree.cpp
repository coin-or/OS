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
	mapVarIdx( NULL),
	f(NULL)
	{
}//end OSExpressionTree

 
OSExpressionTree::~OSExpressionTree(){
	#ifdef DEBUG  
	cout << "Inside the OSExpressionTree Destructor" << endl;
	#endif
	if(m_treeRoot != NULL) delete m_treeRoot;
	m_treeRoot = NULL;
	if(mapVarIdx != NULL) delete mapVarIdx;
	mapVarIdx = NULL;
	if(f != NULL) delete f;
	f = NULL;
}//end ~OSExpressionTree 


std::vector<OSnLNode*> OSExpressionTree::getPostfixFromExpressionTree(){
	return m_treeRoot->getPostfixFromExpressionTree();
}//getPostfixFromExpressionTree


std::vector<OSnLNode*> OSExpressionTree::getPrefixFromExpressionTree(){
	return m_treeRoot->getPrefixFromExpressionTree();
}//getPrefixFromExpressionTree


double OSExpressionTree::calculateFunctionCppAD( double *x, bool functionEvaluated){
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
}//calculateFunctionCppAD

double OSExpressionTree::calculateFunction( double *x, bool functionEvaluated){
	//calculateFunctionCppAD( x, functionEvaluated);
	if(functionEvaluated == true){
		return m_dTreeRootValue; 
	}
	else{
		m_dTreeRootValue = m_treeRoot->calculateFunction( x);
		return  m_dTreeRootValue;
	}
}//calculateFunction

std::vector<double> OSExpressionTree::calculateGradient( double *x, bool functionEvaluated){
	// note x is a dense vector
	// = false;
	//CppAD::vector< AD<double> > XAD;
	//CppAD::vector< AD<double> > vZ;
	//CppAD::AD<double> CppADTree;
	if( m_bCppADTreeBuilt == false){
		// map the variables
		if( m_bIndexMapGenerated == false) getVariableIndiciesMap();
		m_treeRoot->getVariableIndexMap( mapVarIdx);		
		// convert the double x vector to an AD vector
		for(m_mPosVarIdx = (*mapVarIdx).begin(); m_mPosVarIdx != (*mapVarIdx).end(); ++m_mPosVarIdx){
			m_vXAD.push_back( x[ m_mPosVarIdx->first] );
			//XAD.push_back( x[ m_mPosVarIdx->first] );
		}
		CppAD::Independent( m_vXAD);
		//CppAD::Independent( XAD);
		m_CppADTree = m_treeRoot->constructCppADTree(mapVarIdx, &m_vXAD);
		//CppADTree = m_treeRoot->constructCppADTree(mapVarIdx, &XAD);
		m_vZ.push_back( m_CppADTree) ;
		//vZ.push_back(CppADTree) ;
		f = new CppAD::ADFun<double>(m_vXAD, m_vZ);
		//f = new CppAD::ADFun<double>(XAD, vZ);
		m_bCppADTreeBuilt = true;
	}
	//std::vector<double> X;
	if( functionEvaluated == false){ 
		m_vX.clear();
		for(m_mPosVarIdx = (*mapVarIdx).begin(); m_mPosVarIdx != (*mapVarIdx).end(); ++m_mPosVarIdx){
			m_vX.push_back( x[ m_mPosVarIdx->first] );
		}
	}
 	std::vector<double> jac( (*mapVarIdx).size() ); 	// Jacobian of f 
 	//m_vY = (*f).Forward(0, m_vX);
   	jac  = (*f).Jacobian( m_vX);	
   	// Jacobian for operation sequence
	//for(m_mPosVarIdx = (*mapVarIdx).begin(); m_mPosVarIdx != (*mapVarIdx).end(); ++m_mPosVarIdx){
	//	std::cout << "INDEX OF JACOBIANN   " <<  m_mPosVarIdx->second << endl;
	//	std::cout << "Partial with respect to  " <<  
	//	m_mPosVarIdx->first << "  computed by CppAD = " << jac[ m_mPosVarIdx->second] << std::endl;
	//}
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
	return hess;
}//calculateHessian

std::map<int, int> *OSExpressionTree::getVariableIndiciesMap(){
	if( m_bIndexMapGenerated == true) return mapVarIdx;
	mapVarIdx = new std::map<int, int>();
	m_treeRoot->getVariableIndexMap( mapVarIdx);
	//std::cout << "SIZE OF MAP =  "  << (*mapVarIdx).size() << std::endl;
	int kount = 0;
	for(m_mPosVarIdx = (*mapVarIdx).begin(); m_mPosVarIdx != (*mapVarIdx).end(); ++m_mPosVarIdx){
		m_mPosVarIdx->second = kount++;
		//std::cout <<  "POSITION FIRST =  "  << m_mPosVarIdx->first ;
		//std::cout <<  "    POSITION SECOND = "  << m_mPosVarIdx->second << std::endl;
	}
	m_bIndexMapGenerated = true;
	return mapVarIdx;
}//getVariableIndicies

