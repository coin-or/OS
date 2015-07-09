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

#include "OSExpressionTree.h"
#include "OSMathUtil.h"
#include "OSOutput.h"

#include <iostream>
#include <sstream>
#include <vector>
#include <stack>


using namespace std;
using std::ostringstream;
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
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_debug, 
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
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, "Start comparing in OSExpressionTree");
#endif
    if (this == NULL)
    {
        if (that == NULL)
            return true;
        else
        {
#ifndef NDEBUG
            osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, "First object is NULL, second is not");
#endif
            return false;
        }
    }
    else
    {
        if (that == NULL)
        {
#ifndef NDEBUG
            osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, "Second object is NULL, first is not");
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
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_debug, 
        "Inside the ScalarExpressionTree Constructor");
#endif
}//end ScalarExpressionTree


ScalarExpressionTree::~ScalarExpressionTree()
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_debug, 
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
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, "Start comparing in ScalarExpressionTree");
#endif
    if (this == NULL)
    {
        if (that == NULL)
            return true;
        else
        {
#ifndef NDEBUG
            osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, "First object is NULL, second is not");
#endif
            return false;
        }
    }
    else
    {
        if (that == NULL)
        {
#ifndef NDEBUG
            osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, "Second object is NULL, first is not");
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
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_debug, 
        "Inside the MatrixExpressionTree Constructor");
#endif
}//end MatrixExpressionTree


MatrixExpressionTree::~MatrixExpressionTree()
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_debug, 
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
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, "Start comparing in MatrixExpressionTree");
#endif
    if (this == NULL)
    {
        if (that == NULL)
            return true;
        else
        {
#ifndef NDEBUG
            osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, "First object is NULL, second is not");
#endif
            return false;
        }
    }
    else
    {
        if (that == NULL)
        {
#ifndef NDEBUG
            osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, "Second object is NULL, first is not");
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


std::string getExpressionTreeAsInfixString(std::vector<ExprNode*> postfixVec)
{
    std::string resultString;
    resultString = "";
    unsigned int i;
    unsigned int j;
    unsigned int n;
    ostringstream outStr;
//    std::vector<ExprNode*> postfixVec;

//    int rowIdx = rowIdx_;
    ExprNode *nlnode = NULL;
    OSnLNodeNumber *nlnodeNum = NULL;
    OSnLNodeVariable *nlnodeVar = NULL;
    OSnLNodeSum *nlnodeSum = NULL;
    OSnLNodeProduct *nlnodeProduct = NULL;
    OSnLNodeMin *nlnodeMin = NULL;
    OSnLNodeMax *nlnodeMax = NULL;
    std::string tmp1 = "";
    std::string tmp2 = "";
    std::string tmp3 = "";
    std::stack<ExprNode*> opStack;
    std::stack<std::string> tmpStack;
    std::stack<std::string> sumStack;
    std::stack<std::string> productStack;
    std::stack<std::string> minStack;
    std::stack<std::string> maxStack;

    try
    {
                n  = postfixVec.size();
                //put vector in reverse order
                for (i = 0 ; i < n; i++)
                {
                    nlnode =  postfixVec[ n - 1 - i];
                    opStack.push( nlnode);
                }

                n = opStack.size();
                for(i = 0; i < n; i++)
                {
                    nlnode = opStack.top();
                    switch (nlnode->inodeInt)
                    {
                    case OS_NUMBER:
                        nlnodeNum = (OSnLNodeNumber*)nlnode;
                        tmpStack.push( os_dtoa_format(nlnodeNum->value) );
                        break;

                    case OS_PI:
                        tmpStack.push( "PI" );
                        break;

                    case OS_E:
                        tmpStack.push( "E" );
                        break;

                    case OS_VARIABLE:
                        outStr.str("");
                        // handle a variable
                        nlnodeVar = (OSnLNodeVariable*)nlnode;
                        // see if the coefficient is specified
                        if( (nlnodeVar->coef > 1.0) ||  (nlnodeVar->coef < 1.0) )
                        {
                            outStr << "(";
                            outStr <<  os_dtoa_format(nlnodeVar->coef);
                            outStr << "*x_";
                            outStr << nlnodeVar->idx;
                            outStr << ")";
                            tmpStack.push(outStr.str() );
                        }
                        else
                        {
                            outStr << "x_";
                            outStr << nlnodeVar->idx;
                            tmpStack.push(outStr.str() );
                        }
                        break;

                    case OS_PLUS :
                        if( tmpStack.size() < nlnode->inumberOfChildren) throw  ErrorClass("There is an error in the OSExpression Tree -- Problem writing plus operator");
                        tmp1 = tmpStack.top();
                        tmpStack.pop();
                        tmp2 = tmpStack.top();
                        tmpStack.pop();
                        tmpStack.push("(" + tmp2 +  " + "  + tmp1 + ")");
                        break;

                    case OS_SUM :
                        if( tmpStack.size() < nlnode->inumberOfChildren) throw  ErrorClass("There is an error in the OSExpression Tree -- Problem writing sum operator");
                        //std::cout << "INSIDE SUM NODE " << std::endl;
                        nlnodeSum = (OSnLNodeSum*)nlnode;
                        outStr.str("");
                        for(j = 0; j < nlnodeSum->inumberOfChildren; j++)
                        {
                            sumStack.push( tmpStack.top() );
                            tmpStack.pop();
                        }
                        outStr << "(";
                        for(j = 0; j < nlnodeSum->inumberOfChildren; j++)
                        {
                            outStr << sumStack.top();
                            if (j < nlnodeSum->inumberOfChildren - 1) outStr << " + ";
                            sumStack.pop();
                        }
                        outStr << ")";
                        tmpStack.push( outStr.str() );
                        //std::cout << outStr.str() << std::endl;
                        break;

                    case OS_MINUS :
                        if( tmpStack.size() < nlnode->inumberOfChildren) throw  ErrorClass("There is an error in the OSExpression Tree -- Problem writing minus operator");
                        tmp1 = tmpStack.top();
                        tmpStack.pop();
                        tmp2 = tmpStack.top();
                        tmpStack.pop();
                        tmpStack.push("(" + tmp2 +  " - "  + tmp1 + ")");
                        break;

                    case OS_NEGATE :
                        if( tmpStack.size() < nlnode->inumberOfChildren) throw  ErrorClass("There is an error in the OSExpression Tree -- -- Problem writing negate operator");
                        tmp1 = tmpStack.top();
                        tmpStack.pop();
                        tmpStack.push( "-"+ tmp1 );


                        break;

                    case OS_TIMES :
                        if( tmpStack.size() < nlnode->inumberOfChildren) throw  ErrorClass("There is an error in the OSExpression Tree -- Problem writing times operator");
                        tmp1 = tmpStack.top();
                        tmpStack.pop();
                        tmp2 = tmpStack.top();
                        tmpStack.pop();
                        tmpStack.push("(" + tmp2 +  "*"  + tmp1 + ")");
                        break;

                    case OS_DIVIDE :
                        if( tmpStack.size() < nlnode->inumberOfChildren) throw  ErrorClass("There is an error in the OSExpression Tree -- Problem writing divide operator");
                        tmp1 = tmpStack.top();
                        tmpStack.pop();
                        tmp2 = tmpStack.top();
                        tmpStack.pop();
                        tmpStack.push("(" + tmp2 +  " / "  + tmp1 + ")");
                        break;

                    case OS_POWER :
                        if( tmpStack.size() < nlnode->inumberOfChildren) throw  ErrorClass("There is an error in the OSExpression Tree -- Problem writing power operator");
                        tmp1 = tmpStack.top();
                        tmpStack.pop();
                        tmp2 = tmpStack.top();
                        tmpStack.pop();
                        tmpStack.push("(" + tmp2 +  " ^ "  + tmp1 + ")");
                        break;


                    case OS_ABS :
                        if( tmpStack.size() < nlnode->inumberOfChildren) throw  ErrorClass("There is an error in the OSExpression Tree -- Problem writing abs operator");
                        tmp1 = tmpStack.top();
                        tmpStack.pop();
                        tmpStack.push( "abs( "+ tmp1  + ")");
                        break;

                    case OS_ERF :
                        if( tmpStack.size() < nlnode->inumberOfChildren) throw  ErrorClass("There is an error in the OSExpression Tree -- Problem writing erf operator");
                        tmp1 = tmpStack.top();
                        tmpStack.pop();
                        tmpStack.push( "erf( "+ tmp1  + ")");
                        break;


                    case OS_SQUARE :
                        if( tmpStack.size() < nlnode->inumberOfChildren) throw  ErrorClass("There is an error in the OSExpression Tree -- Problem writing square operator ");
                        tmp1 = tmpStack.top();
                        tmpStack.pop();
                        tmpStack.push( "("+ tmp1  + ")^2");
                        break;

                    case OS_LN :
                        if( tmpStack.size() < nlnode->inumberOfChildren) throw  ErrorClass("There is an error in the OSExpression Tree -- Problem writing ln operator");
                        tmp1 = tmpStack.top();
                        tmpStack.pop();
                        tmpStack.push( "ln( "+ tmp1  + ")");
                        break;

                    case OS_EXP :
                        if( tmpStack.size() < nlnode->inumberOfChildren) throw  ErrorClass("There is an error in the OSExpression Tree -- Problem writing exp operator");
                        tmp1 = tmpStack.top();
                        tmpStack.pop();
                        tmpStack.push( "exp( "+ tmp1  + ")");
                        break;

                    case OS_SIN :
                        if( tmpStack.size() < nlnode->inumberOfChildren) throw  ErrorClass("There is an error in the OSExpression Tree -- Problem writing sin operator");
                        tmp1 = tmpStack.top();
                        tmpStack.pop();
                        tmpStack.push( "sin( "+ tmp1  + ")");
                        break;

                    case OS_COS :
                        if( tmpStack.size() < nlnode->inumberOfChildren) throw  ErrorClass("There is an error in the OSExpression Tree -- Problem writing cos operator ");
                        tmp1 = tmpStack.top();
                        tmpStack.pop();
                        tmpStack.push( "cos( "+ tmp1  + ")");
                        break;

                    case OS_SQRT :
                        if( tmpStack.size() < nlnode->inumberOfChildren) throw  ErrorClass("There is an error in the OSExpression Tree -- Problem writing sqrt operator ");
                        tmp1 = tmpStack.top();
                        tmpStack.pop();
                        tmpStack.push( "sqrt( "+ tmp1  + ")");
                        break;

                    case OS_MIN :
                        if( tmpStack.size() < nlnode->inumberOfChildren) throw  ErrorClass("There is an error in the OSExpression Tree -- Problem writing min operator");
                        //std::cout << "INSIDE Min NODE " << std::endl;
                        nlnodeMin = (OSnLNodeMin*)nlnode;
                        outStr.str("");
                        for(j = 0; j < nlnodeMin->inumberOfChildren; j++)
                        {
                            minStack.push( tmpStack.top() );
                            tmpStack.pop();
                        }
                        outStr << "min(";
                        for(j = 0; j < nlnodeMin->inumberOfChildren; j++)
                        {
                            outStr << minStack.top();
                            if (j < nlnodeMin->inumberOfChildren - 1) outStr << " , ";
                            minStack.pop();
                        }
                        outStr << ")";
                        tmpStack.push( outStr.str() );
                        break;


                    case OS_MAX :
                        if( tmpStack.size() < nlnode->inumberOfChildren) throw  ErrorClass("There is an error in the OSExpression Tree -- Problem writing max operator");
                        //std::cout << "INSIDE Max NODE " << std::endl;
                        nlnodeMax = (OSnLNodeMax*)nlnode;
                        outStr.str("");
                        for(j = 0; j < nlnodeMax->inumberOfChildren; j++)
                        {
                            maxStack.push( tmpStack.top() );
                            tmpStack.pop();
                        }
                        outStr << "max(";
                        for(j = 0; j < nlnodeMax->inumberOfChildren; j++)
                        {
                            outStr << maxStack.top();
                            if (j < nlnodeMax->inumberOfChildren - 1) outStr << " , ";
                            maxStack.pop();
                        }
                        outStr << ")";
                        tmpStack.push( outStr.str() );
                        break;

                    case OS_IF :

                        if( tmpStack.size() < nlnode->inumberOfChildren) throw  ErrorClass("There is an error in the OSExpression Tree -- Problem writing if operator ");
                        if(nlnode->inumberOfChildren != 3)throw  ErrorClass("The if node must have three children");
                        tmp1 = tmpStack.top();
                        tmpStack.pop();
                        tmp2 = tmpStack.top();
                        tmpStack.pop();
                        tmp3 = tmpStack.top();
                        tmpStack.pop();
                        tmpStack.push( "if(" + tmp3 + "," + tmp2 + "," + tmp1 +")" );
                        break;


                    case OS_PRODUCT :
                        if( tmpStack.size() < nlnode->inumberOfChildren) throw  ErrorClass("There is an error in the OSExpression Tree -- Problem writing product operator");
                        //std::cout << "INSIDE Product NODE " << std::endl;
                        nlnodeProduct = (OSnLNodeProduct*)nlnode;
                        outStr.str("");
                        for(j = 0; j < nlnodeProduct->inumberOfChildren; j++)
                        {
                            productStack.push( tmpStack.top() );
                            tmpStack.pop();
                        }
                        outStr << "(";
                        for(j = 0; j < nlnodeProduct->inumberOfChildren; j++)
                        {
                            outStr << productStack.top();
                            if (j < nlnodeProduct->inumberOfChildren - 1) outStr << " * ";
                            productStack.pop();
                        }
                        outStr << ")";
                        tmpStack.push( outStr.str() );
                        //std::cout << outStr.str() << std::endl;
                        break;

                    default:
                        throw  ErrorClass("operator " + nlnode->getTokenName() + " not supported");
                        break;
                    }
                    opStack.pop();
                }
                postfixVec.clear();
                if(tmpStack.size() != 1) throw ErrorClass( "There is an error in the OSExpression Tree -- stack size should be 1 at end");
                resultString = tmpStack.top();
                //std::cout << resultString << std::endl;
                tmpStack.pop();

                return resultString;
    }
    catch(const ErrorClass& eclass)
    {
        throw ErrorClass( eclass.errormsg);
    }
}//getExpressionTreeAsInfixString

