/* $Id$ */
/** @file OSExpressionTree.h
 *
 *
 * @author  Robert Fourer, Horand Gassmann, Jun Ma, Kipp Martin,
 *
 * \remarks
 * Copyright (C) 2005-2011, Robert Fourer, Horand Gassmann, Jun Ma, Kipp Martin,
 * Dalhousie University, Northwestern University, and the University of Chicago.
 * All Rights Reserved.
 * This software is licensed under the Eclipse Public License.
 * Please see the accompanying LICENSE file in root directory for terms.
 *
 */

#ifndef EXPRESSIONTREE_H
#define EXPRESSIONTREE_H

#include "OSnLNode.h"
#include <vector>
#include <map>


/*! \class OSExpressionTree
 *  \brief Used to hold the instance in memory.
 *
 * \remarks
 * This class stores the OSiL instance in memory as
 * an expression tree.
 *
 */

class OSExpressionTree
{

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
     * A function to check for the equality of two objects
     */
    bool IsEqual(OSExpressionTree *that);

    /**
     * Calculate the expression tree function value given the current variable
     * values using the calculateFunction method of OSnLNode.
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
     * constructADTape(std::map<int, int> *varIdx, AD::vector< AD<double> > *XAD)
     * to generate the infix expression for AD -- the key is idx a variable number, the
     * value of the map is the corresponding variable count in sparse representation
     */
    std::map<int, int> *mapVarIdx;

    /**
     * Retrieve a map of the indices of the variables
     * that are in the expression tree
     *
     * </p>
     *
     * @return a map of the variables in the current expression tree.
	 * \remark This method is obsolescent due to the typo in the name 
	 * and has been replaced by getVariableIndicesMap(); 
     */
    std::map<int, int> *getVariableIndiciesMap();

	/**
     * Retrieve a map of the indices of the variables
     * that are in the expression tree
     *
     * </p>
     *
     * @return a map of the variables in the current expression tree.
     */
    std::map<int, int> *getVariableIndicesMap();

	/**
     * m_bIndexMapGenerated is set to true if getVariableIndicesMap() has been called
     */
    bool  m_bIndexMapGenerated;

    /**
     * is true if a AD Expresion Tree has an expression that can change depending on
     * the value of the input, e.g. an if statement -- false by default
     */
    bool bADMustReTape;

    /**
     * m_bDestroyNlNodes if the destructor deletes the OSnLNodes in the Expression tree
     */
    bool bDestroyNlNodes;


private:


    /**
     * m_dTreeRootValue is the function value of the root node
     */
    double m_dTreeRootValue;



};//end OSExpressionTree




#endif

