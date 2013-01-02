/* $Id$ */
/** @file OSExpressionTree.cpp
 *
 *
 * @author  Robert Fourer, Horand Gassmann, Jun Ma, Kipp Martin,
 *
 * \remarks
 * Copyright (C) 2005-2011, Robert Fourer, Horand Gassmann, Jun Ma, Kipp Martin,
 * Northwestern University, and the University of Chicago.
 * All Rights Reserved.
 * This software is licensed under the Eclipse Public License.
 * Please see the accompanying LICENSE file in root directory for terms.
 *
 */

#include "OSOutput.h"
#include "OSExpressionTree.h"
#include <vector>

using std::cout;
using std::endl;

OSExpressionTree::OSExpressionTree():
    m_treeRoot( NULL),
    mapVarIdx( NULL),
    m_bIndexMapGenerated( false),
    bADMustReTape( false),
    bDestroyNlNodes( true)
{
}//end OSExpressionTree


OSExpressionTree::~OSExpressionTree()
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSExpressionTree, ENUM_OUTPUT_LEVEL_debug, 
        "Inside the OSExpressionTree Destructor");
#endif
    if( bDestroyNlNodes == true)
    {
        if(m_treeRoot != NULL) delete m_treeRoot;
        m_treeRoot = NULL;
    }
    if(mapVarIdx != NULL)
    {
        delete mapVarIdx;
        mapVarIdx = NULL;
    }
}//end ~OSExpressionTree


std::vector<OSnLNode*> OSExpressionTree::getPostfixFromExpressionTree()
{
    return m_treeRoot->getPostfixFromExpressionTree();
}//getPostfixFromExpressionTree


std::vector<OSnLNode*> OSExpressionTree::getPrefixFromExpressionTree()
{
    return m_treeRoot->getPrefixFromExpressionTree();
}//getPrefixFromExpressionTree



double OSExpressionTree::calculateFunction( double *x, bool new_x)
{
    //calculateFunctionAD( x, functionEvaluated);
    if( new_x == false)
    {
        return m_dTreeRootValue;
    }
    else
    {
        m_dTreeRootValue = m_treeRoot->calculateFunction( x);
        return  m_dTreeRootValue;
    }
}//calculateFunction

std::map<int, int> *OSExpressionTree::getVariableIndiciesMap()     //obsolescent --- 
{
	return getVariableIndicesMap();
}

std::map<int, int> *OSExpressionTree::getVariableIndicesMap()
{
    if( m_bIndexMapGenerated == true) return mapVarIdx;
    mapVarIdx = new std::map<int, int>();
    std::map<int, int>::iterator m_mPosVarIdx;
    m_treeRoot->getVariableIndexMap( mapVarIdx);
    //std::cout << "SIZE OF MAP =  "  << (*mapVarIdx).size() << std::endl;
    //for(m_mPosVarIdx = (*mapVarIdx).begin(); m_mPosVarIdx != (*mapVarIdx).end(); ++m_mPosVarIdx){
    //	m_mPosVarIdx->second = kount++;
    //std::cout <<  "POSITION FIRST =  "  << m_mPosVarIdx->first ;
    //std::cout <<  "    POSITION SECOND = "  << m_mPosVarIdx->second << std::endl;
    //}
    m_bIndexMapGenerated = true;
    return mapVarIdx;
}//getVariableIndices

bool OSExpressionTree::IsEqual(OSExpressionTree *that)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSExpressionTree, ENUM_OUTPUT_LEVEL_trace, "Start comparing in OSExpressionTree");
#endif
    if (this == NULL)
    {
        if (that == NULL)
            return true;
        else
        {
#ifndef NDEBUG
            osoutput->OSPrint(ENUM_OUTPUT_AREA_OSExpressionTree, ENUM_OUTPUT_LEVEL_trace, "First object is NULL, second is not");
#endif
            return false;
        }
    }
    else
    {
        if (that == NULL)
        {
#ifndef NDEBUG
            osoutput->OSPrint(ENUM_OUTPUT_AREA_OSExpressionTree, ENUM_OUTPUT_LEVEL_trace, "Second object is NULL, first is not");
#endif
            return false;
        }
        else
        {
            if (!this->m_treeRoot->IsEqual(that->m_treeRoot))
                return false;

            return true;
        }
    }
}//OSExpressionTree::IsEqual


