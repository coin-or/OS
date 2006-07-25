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


//std::vector<OSnLNode*> OSExpressionTree::getPostfix(){
//	return m_treeRoot->getPostfixFromExpressionTree();
//}//end getPostfix

