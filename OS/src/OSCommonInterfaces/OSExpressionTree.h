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
#include<CppAD/CppAD.h>


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
	 * values. If the function has been evaluated over the current x values, the
	 * method will retrieve it.
	 * 
	 * </p>
	 * 
	 * @param x holds the values of the variables in a double array.
	 * @param functionEvaluated holds whether the function has been evaluated.
	 * @return the expression function value given the current variable values.
	 */
	double calculateFunction(double *x, bool functionEvaluated);
	
private:

	/**
	 * XAD is a vector of AD doubles used by
	 * constructCppADTree(std::map<int, int> *cppADIdx, CppAD::vector< AD<double> > *XAD)
	 * to generate the infix expression for CPPAD -- it will hold the vector of doubles from 
	 * the solver
	 */	
	CppAD::vector< AD<double> > XAD;
	
	/**
	 * cppADIdx is a map used by
	 * constructCppADTree(std::map<int, int> *cppADIdx, CppAD::vector< AD<double> > *XAD)
	 * to generate the infix expression for CPPAD -- the key is idx a variable number, the  
	 * value of the map is the corresponding count in terms of nonzero elements
	 * we need to preserve the sparsity of the calculation
	 */	
	std::map<int, int> cppADIdx; 
	
	/**
	 * m_CppADTree stores the espression tree for m_treeRoot as an AD<double>.
	 */
	AD<double> m_CppADTree;
	
	/**
	 *  CppAD requires a vector for the independent variable, store the expression tree
	 * in Z
	 */
	vector< AD<double> > Z;
	
	/**
	 * functionValue stores the value of m_treeRoot as a double.
	 */
	double m_dfunctionValue;
	
	



};//end OSExpressionTree




#endif

