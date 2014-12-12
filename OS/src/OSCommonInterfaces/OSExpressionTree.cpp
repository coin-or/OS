/* $Id$ */
/** @file OSExpressionTree.cpp
 *
 * @author  Robert Fourer, Horand Gassmann, Jun Ma, Kipp Martin
 *
 * \remarks
 * Copyright (C) 2005-2014, Robert Fourer, Horand Gassmann, Jun Ma, Kipp Martin,
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
//    m_treeRoot( NULL),
//    m_bIsVectorValued(false),
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
//    if( bDestroyNlNodes == true)
//    {
//        if(m_treeRoot != NULL) delete m_treeRoot;
//        m_treeRoot = NULL;
//    }
    if(mapVarIdx != NULL)
    {
        delete mapVarIdx;
        mapVarIdx = NULL;
    }
}//end ~OSExpressionTree

#if 0
std::vector<ExprNode*> OSExpressionTree::getPrefixFromExpressionTree()
{
    return m_treeRoot->getPrefixFromExpressionTree();
}//getPrefixFromExpressionTree


std::vector<ExprNode*> OSExpressionTree::getPostfixFromExpressionTree()
{
    return m_treeRoot->getPostfixFromExpressionTree();
}//getPostfixFromExpressionTree
#endif

#if 0
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
#endif

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
            if (this->m_bIndexMapGenerated != that->m_bIndexMapGenerated)
                return false;
            if (this->bADMustReTape        != that->bADMustReTape)
                return false;
            if (this->bDestroyNlNodes      != that->bDestroyNlNodes)
                return false;
            return true;
        }
    }
}//OSExpressionTree::IsEqual


ScalarExpressionTree::ScalarExpressionTree():
    m_treeRoot( NULL)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSExpressionTree, ENUM_OUTPUT_LEVEL_debug, 
        "Inside the ScalarExpressionTree Constructor");
#endif
}//end ScalarExpressionTree


ScalarExpressionTree::~ScalarExpressionTree()
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSExpressionTree, ENUM_OUTPUT_LEVEL_debug, 
        "Inside the ScalarExpressionTree Destructor");
#endif
    if( bDestroyNlNodes == true)
    {
        if(m_treeRoot != NULL) delete m_treeRoot;
        m_treeRoot = NULL;
    }
}//end ~ScalarExpressionTree

std::vector<ExprNode*> ScalarExpressionTree::getPrefixFromExpressionTree()
{
    return m_treeRoot->getPrefixFromExpressionTree();
}//getPrefixFromExpressionTree


std::vector<ExprNode*> ScalarExpressionTree::getPostfixFromExpressionTree()
{
    return m_treeRoot->getPostfixFromExpressionTree();
}//getPostfixFromExpressionTree


std::map<int, int> *ScalarExpressionTree::getVariableIndicesMap()
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
}//getVariableIndicesMap


double ScalarExpressionTree::calculateFunction( double *x, bool new_x)
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


bool ScalarExpressionTree::IsEqual(ScalarExpressionTree *that)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSExpressionTree, ENUM_OUTPUT_LEVEL_trace, "Start comparing in ScalarExpressionTree");
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

            return this->OSExpressionTree::IsEqual(that);
        }
    }
}//ScalarExpressionTree::IsEqual


MatrixExpressionTree::MatrixExpressionTree():
    m_treeRoot( NULL)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSExpressionTree, ENUM_OUTPUT_LEVEL_debug, 
        "Inside the MatrixExpressionTree Constructor");
#endif
}//end MatrixExpressionTree


MatrixExpressionTree::~MatrixExpressionTree()
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSExpressionTree, ENUM_OUTPUT_LEVEL_debug, 
        "Inside the MatrixExpressionTree Destructor");
#endif
    if( bDestroyNlNodes == true)
    {
        if(m_treeRoot != NULL) delete m_treeRoot;
        m_treeRoot = NULL;
    }
}//end ~MatrixExpressionTree


std::vector<ExprNode*> MatrixExpressionTree::getPrefixFromExpressionTree()
{
    return m_treeRoot->/*OSnLMNode::*/getPrefixFromExpressionTree();
}//getPrefixFromExpressionTree


std::vector<ExprNode*> MatrixExpressionTree::getPostfixFromExpressionTree()
{
    return m_treeRoot->/*OSnLMNode::*/getPostfixFromExpressionTree();
}//getPostfixFromExpressionTree


bool MatrixExpressionTree::IsEqual(MatrixExpressionTree *that)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSExpressionTree, ENUM_OUTPUT_LEVEL_trace, "Start comparing in MatrixExpressionTree");
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

            return this->OSExpressionTree::IsEqual(that);
        }
    }
}//MatrixExpressionTree::IsEqual

