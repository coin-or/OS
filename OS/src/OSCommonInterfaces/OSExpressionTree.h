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
#include <stdlib.h>
#include <string>
#include <vector>

using namespace std;


class OSExpressionTree{  
public:	
	
	/**
	 * m_treeRoot holds the root node (of OSnLNode type) of the expression tree.
	 */
	OSnLNode *m_treeRoot;
	
public:	
	/**
	 * default constructor.
	 */
	OSExpressionTree();

	/**
	 * default destructor.
	 */	
	~OSExpressionTree();
	
	



//std::vector<OSnLNode*> getPostfix();


};//end OSExpressionTree




#endif

