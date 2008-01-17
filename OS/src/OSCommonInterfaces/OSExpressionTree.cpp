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

//#define DEBUG
#include "OSExpressionTree.h"
#include<vector>

using std::cout; 
using std::endl;

OSExpressionTree::OSExpressionTree():
	m_treeRoot( NULL),
	mapVarIdx( NULL),
	bDestroyNlNodes( true),
	m_bIndexMapGenerated( false),
	bCppADMustReTape( false){
}//end OSExpressionTree

 
OSExpressionTree::~OSExpressionTree(){
	#ifdef DEBUG  
	cout << "Inside the OSExpressionTree Destructor" << endl;
	#endif
	if( bDestroyNlNodes == true){
		if(m_treeRoot != NULL){
			std::vector<OSnLNode*> postfixVec;
			postfixVec = m_treeRoot->getPostfixFromExpressionTree();
			unsigned int n = postfixVec.size();
			unsigned int i;
			for (i = 0 ; i < n; i++){
				//std::cout << postfixVec[i]->snodeName << std::endl;
				if( postfixVec[ i] !=  NULL){
					// note m_treeRoot is getting deleted here
					delete postfixVec[ i];
					postfixVec[ i] == NULL;
				}
			}
		}	
	}
	if(mapVarIdx != NULL) delete mapVarIdx;
	mapVarIdx = NULL;
}//end ~OSExpressionTree 


std::vector<OSnLNode*> OSExpressionTree::getPostfixFromExpressionTree(){
	return m_treeRoot->getPostfixFromExpressionTree();
}//getPostfixFromExpressionTree


std::vector<OSnLNode*> OSExpressionTree::getPrefixFromExpressionTree(){
	return m_treeRoot->getPrefixFromExpressionTree();
}//getPrefixFromExpressionTree



double OSExpressionTree::calculateFunction( double *x, bool new_x){
	//calculateFunctionCppAD( x, functionEvaluated);
	if( new_x == false){
		return m_dTreeRootValue; 
	}
	else{
		m_dTreeRootValue = m_treeRoot->calculateFunction( x);
		return  m_dTreeRootValue;
	}
}//calculateFunction

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

