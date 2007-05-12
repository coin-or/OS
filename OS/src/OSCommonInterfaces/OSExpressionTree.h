/** @file OSExpressionTree.h
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
 
#ifndef EXPRESSIONTREE_H
#define EXPRESSIONTREE_H 

#include "OSnLNode.h"
#include <vector>
#include <map>
#include<cppad/cppad.hpp>
using CppAD::Parameter;

class OSExpressionTree{  

public:	
	
	/**
	 * m_treeRoot holds the root node (of OSnLNode type) of the expression tree.
	 */
	OSnLNode *m_treeRoot;
	
	/**
	 * default constructor.
	 */
	OSExpressionTree();

	/**
	 * default destructor.
	 */	
	~OSExpressionTree();
	
	/**
	 * Calculate the expression tree function value given the current variable
	 * values using the calculateFunciton method of OSnLNode. 
	 * If the function has been calculated, the
	 * method will retrieve it.
	 * 
	 * </p>
	 * 
	 * @param x holds the values of the variables in a double array.
 	 * @param new_x is false if any evaluation method was previously called for the current x
	 * @return the expression tree function value given the current variable values.
	 */
	double calculateFunction( double *x, bool new_x);
	
	/**
	 * Calculate the expression tree function value given the current variable
	 * values using CppAD. If the function has been calculated, the
	 * method will retrieve it.
	 * 
	 * </p>
	 * 
	 * @param x holds the values of the variables in a double array.
	 * @param functionEvaluated is set to true if the function has already been evaluated.
	 * @return the expression tree function value given the current variable values.
	 */
	double calculateFunctionCppAD( double *x, bool functionEvaluated);
	
	
	/**
	 * Calculate the gradient of the expression tree function given the current variable
	 * values. In this case we always retape the CppAD expression tree
	 * 
	 * </p>
	 * 
	 * @param x holds the values of the variables in a double array.
	 * @param functionEvaluated is set to true if the function has already been evaluated.
	 * @return the expression tree gradient given the current variable values.
	 */
	std::vector<double> calculateGradientReTape( double *x, bool functionEvaluated);
	
	
	/**
	 * Calculate the gradient of the expression tree function given the current variable
	 * values. If the CppAD expression tree has been calculated, the
	 * method will retrieve it.
	 * 
	 * </p>
	 * 
	 * @param x holds the values of the variables in a double array.
	 * @param functionEvaluated is set to true if the function has already been evaluated.
	 * @return the expression tree gradient given the current variable values.
	 */
	std::vector<double> calculateGradient( double *x, bool functionEvaluated);
	
	
	/**
	 * Calculate the Hessian of the expression tree function given the current variable
	 * values. If the CppAD expression tree has been calculated, the
	 * method will retrieve it.
	 * 
	 * </p>
	 * 
	 * @param x holds the values of the variables in a double array.
	 * @param functionEvaluated is set to true if the function has already been evaluated.
	 * @return the expression tree Hessian given the current variable values.
	 */
	std::vector<double> calculateHessian( double *x, bool functionEvaluated);

	/**
	 * Get a vector of pointers to OSnLNodes that correspond to
	 * the OSExpressionTree in prefix format
	 * 
	 * </p>
	 * 
	 * @return the expression tree as a vector of OSnLNodes in prefix.
	 */
	std::vector<OSnLNode*> getPrefixFromExpressionTree();
	
	/**
	 * Get a vector of pointers to OSnLNodes that correspond to
	 * the OSExpressionTree in postfix format
	 * 
	 * </p>
	 * 
	 * @return the expression tree as a vector of OSnLNodes in postfix.
	 */
	std::vector<OSnLNode*> getPostfixFromExpressionTree();
	

	
	/**
	 * m_mvarIdx is a map used by
	 * constructCppADTape(std::map<int, int> *varIdx, CppAD::vector< AD<double> > *XAD)
	 * to generate the infix expression for CPPAD -- the key is idx a variable number, the  
	 * value of the map is the corresponding variable count in sparse representation
	 */	
	std::map<int, int> *mapVarIdx;
	
	/**
	 * Retrieve a map of the indicies of the variables
	 * that are in the expression tree
	 * 
	 * </p>
	 * 
	 * @return a map of the variables in the current expression tree.
	 */
	std::map<int, int> *getVariableIndiciesMap();
	/**
	 * m_bIndexMapGenerated is set to true if getVariableIndiciesMap() has been called
	 */	
	bool  m_bIndexMapGenerated;
	
	/**
	 * is true if a CppAD Expresion Tree has an expression that can change depending on
	 * the value of the input, e.g. an if statement -- false by default
	 */
	bool bCppADMustReTape;

	
private:


	/**
	 * XAD is a vector of AD doubles used by
	 * constructCppADTape(std::map<int, int> *cppADIdx, CppAD::vector< AD<double> > *XAD)
	 * to generate the infix expression for CPPAD -- it will hold the vector of doubles from 
	 * the solver
	 */	
	CppAD::vector< AD<double> > m_vXAD;
	

	
	/**
	 * posVarIdx is a map iterator used by the map varIdx
	 */	
	std::map<int, int>::iterator m_mPosVarIdx; 
	
	/**
	 * posVarIdx2 is a second map iterator used by the map varIdx for Hessian calculation
	 */	
	std::map<int, int>::iterator m_mPosVarIdx2;
	
	/**
	 * m_CppADTape stores the espression tree for m_treeRoot as an AD<double>.
	 */
	CppAD::AD<double> m_CppADTape;
	
	/**
	 *  CppAD requires a vector for the independent variable, store the expression tree
	 * in Z
	 */
	CppAD::vector< AD<double> > m_vZ;
	
	
	/**
	 * f is a function of X the independent variables and Y the dependent variable. 
	 */	
	CppAD::ADFun<double> *f;

	/**  
	 * m_vY is a one-dimensional vector that holds the value of the f function evalued by CppAD. 
	 */	
	std::vector<double> m_vY;
	
	/**
	 * m_vX is a vector that holds the independent values of the f function evalued by CppAD. 
	 */		
	std::vector<double> m_vX;
	
	/**
	 * m_bCppADTapeBuilt is a boolean that holds whether or not the CppAD expression tree has been built. 
	 */		
	bool m_bCppADTapeBuilt;
	
	/**
	 * m_dTreeRootValue is the function value of the root node
	 */		
	double m_dTreeRootValue;
	
	
	


};//end OSExpressionTree




#endif

