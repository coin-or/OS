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


double OSExpressionTree::calculateFunction(double *x, bool functionEvaluated){
	if( functionEvaluated == true) return m_dfunctionValue;
	else{
		// convert the double x vector to an AD vector
		int numVars = sizeof x/sizeof x[0];
		numVars = 2;
		std::cout << "NUMBER OF VARIABLES = " << numVars << endl;
		int i;
		for(i = 0; i < numVars; i++){
			XAD.push_back( x[i] );
		}
		CppAD::Independent( XAD);
		m_CppADTree = m_treeRoot->constructCppADTree(&cppADIdx, &XAD);
		Z.push_back( m_CppADTree);
	}
	CppAD::ADFun<double> f(XAD, Z);
	vector<double> Y( 1);
	vector<double> X( 2);
	X[0] = .5;
	X[1] = 1.; 
	Y    = f.Forward(0, X);
	std::cout << "VALUE =  " << Y[0] << std::endl;
	return m_dfunctionValue;

}//calculateFunction

