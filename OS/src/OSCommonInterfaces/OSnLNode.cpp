/* $Id$ */
/** @file OSnLNode.cpp
 *c
 *
 * @author  Robert Fourer, Horand Gassmann, Jun Ma, Kipp Martin
 *
 * \remarks
 * Copyright (C) 2005-2015, Robert Fourer, Horand Gassmann, Jun Ma, Kipp Martin,
 * Northwestern University, and the University of Chicago.
 * All Rights Reserved.
 * This software is licensed under the Eclipse Public License.
 * Please see the accompanying LICENSE file in root directory for terms.
 */

#include "OSnLNode.h"
#include "OSErrorClass.h"
#include "OSParameters.h"
#include "OSMathUtil.h"
#include "OSOutput.h"
#include "OSMatrix.h"

#include <string>
#include <cstdlib>

#ifdef HAVE_CMATH
# include <cmath>
#else
# ifdef HAVE_MATH_H
#  include <math.h>
# else
#  error "don't have header file for math"
# endif
#endif


#include <iostream>
#include <sstream>


using std::ostringstream;
using std::cout;
using std::endl;

// This macro defines a code snippet that will be used repeatedly, 
// potentially in hundreds of specific methods
 
#define CLONE_CHILDREN {                                        \
        if (inumberOfChildren > 0)                              \
        {                                                       \
            if (nlNodePoint->m_mChildren == NULL)               \
                nlNodePoint->m_mChildren                        \
                    = new ExprNode*[inumberOfChildren];         \
            for (unsigned int i=0; i < inumberOfChildren; i++)  \
            {                                                   \
                nlNodePoint->m_mChildren[i]                     \
                    = this->m_mChildren[i]->cloneExprNode();    \
            }                                                   \
        }                                                       \
        nlNodePoint->inumberOfChildren = inumberOfChildren;     \
}


//==================================================================================================
// For definitions of functions, argument lists and unique IDs, see OSParameter.h and OSnL-Nodes.txt
//==================================================================================================

//
//ExprNode methods
//

ExprNode::ExprNode():
    inodeInt(-1),
    inodeKind(0),
    inumberOfChildren( 0),
    m_mChildren(NULL)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, "inside ExprNode constructor");
#endif
}//end ExprNode

ExprNode::~ExprNode()
{
#ifndef NDEBUG
    std::ostringstream outStr;
    outStr << "inside ExprNode destructor" << std::endl;
    outStr << "number of child nodes = " <<  inumberOfChildren << std::endl;
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, outStr.str());
#endif
    if (inumberOfChildren > 0 && m_mChildren != NULL)
    {
        for (unsigned int i=0; i<inumberOfChildren; i++)
        {
#ifndef NDEBUG
            outStr << "Delete memory at address " << &m_mChildren[i] << std::endl;
            osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, outStr.str());
#endif
            if (m_mChildren[i] != NULL) 
                delete m_mChildren[i];
            m_mChildren[i] = NULL;
        }
        delete [] m_mChildren;
        m_mChildren = NULL;
        inumberOfChildren = 0;
    }
    else if (inumberOfChildren > 0 || m_mChildren != NULL)
        osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_warning, "Warning: Possible memory leak");
}//end ~ExprNode


std::string ExprNode::getTokenNumber()
{
    ostringstream outStr;
    outStr << inodeInt;
    outStr << "[";
    outStr << inumberOfChildren;
    outStr << "]";
    return outStr.str();
}//getTokenNumber

std::string ExprNode::getNodeInfo(bool recurse, int indent)
{
    ostringstream outStr;
    for (int i=0; i < indent; i++)
        outStr << " ";
    outStr << "node address: " << this;
    outStr << " type: " << inodeInt << "(" << &inodeInt << ")" << " number of Children: "; 
    outStr << inumberOfChildren << "(" << &inumberOfChildren << ")" << std::endl;
    if (recurse)
        for (int i=0; i < inumberOfChildren; i++)
            outStr << m_mChildren[i]->getNodeInfo(true, indent+2);
    return outStr.str();
}//getNodeInfo

std::string ExprNode::getNonlinearExpressionInXML()
{
    ostringstream outStr, logStr;
    outStr << "<";
    outStr << this->getTokenName();
#ifndef NDEBUG
    logStr << "nonlinear node " << this->getTokenName() << endl;
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, logStr.str());
#endif
    if(inumberOfChildren == 0)
    {
        outStr << "/>";
    }
    else
    {
        outStr << ">";
        if(inumberOfChildren > 0)
        {
            for(unsigned int i = 0; i < inumberOfChildren; i++)
            {
                outStr << m_mChildren[i]->getNonlinearExpressionInXML();
            }
        }
        outStr << "</";
        outStr << this->getTokenName();
        outStr << ">";
    }
    return outStr.str();
}//getNonlinearExpressionInXML()


std::vector<ExprNode*> ExprNode::getPrefixFromExpressionTree()
{
    std::vector<ExprNode*> prefixVector;
    return preOrderOSnLNodeTraversal( &prefixVector);
}//getPrefixFromExpressionTree


std::vector<ExprNode*> ExprNode::preOrderOSnLNodeTraversal( std::vector<ExprNode*> *prefixVector)
{
    (*prefixVector).push_back( this);
    if(inumberOfChildren > 0)
    {
        for(unsigned int i = 0; i < inumberOfChildren; i++)
            m_mChildren[i]->preOrderOSnLNodeTraversal( prefixVector);
    }
    return *prefixVector;
}//end preOrderOSnLNodeTraversal

std::vector<ExprNode*> ExprNode::getPostfixFromExpressionTree()
{
    std::vector<ExprNode*> postfixVector;
std::cout << "get postfix from a generic expression node" << std::endl;
    return postOrderOSnLNodeTraversal( &postfixVector);
}//getPostfixFromExpressionTree


std::vector<ExprNode*> ExprNode::postOrderOSnLNodeTraversal( std::vector<ExprNode*> *postfixVector)
{
    if(inumberOfChildren > 0)
    {
        unsigned int i;
        for(i = 0; i < inumberOfChildren; i++)
            m_mChildren[i]->postOrderOSnLNodeTraversal( postfixVector);
    }
    (*postfixVector).push_back( this);
    return *postfixVector;
}//end postOrderOSnLNodeTraversal()


ExprNode* ExprNode::createExpressionTreeFromPrefix(std::vector<ExprNode*> nlNodeVec)
{
    std::vector<ExprNode*> stackVec;
    int kount =  nlNodeVec.size() - 1;
    while(kount >= 0)
    {
        int numkids = nlNodeVec[kount]->inumberOfChildren;

        if(numkids > 0)
        {
            for(int i = 0; i < numkids; i++)
            {
                nlNodeVec[kount]->m_mChildren[i] = stackVec.back();
                stackVec.pop_back();
            }
        }
        stackVec.push_back( nlNodeVec[kount]);
        kount--;
    }
    stackVec.clear();
    return (ExprNode*)nlNodeVec[ 0];
}//end createExpressionTreeFromPrefix

ExprNode* ExprNode::createExpressionTreeFromPostfix(std::vector<ExprNode*> nlNodeVec)
{
    std::vector<ExprNode*> stackVec;

    unsigned int kount =  0;
    while(kount <= nlNodeVec.size() - 1)
    {
        int numkids = nlNodeVec[kount]->inumberOfChildren;
        if (numkids  > 0)
        {
            for(int i = numkids - 1; i >= 0;  i--)
            {
                nlNodeVec[kount]->m_mChildren[i] = stackVec.back();
                stackVec.pop_back();
            }
        }
        stackVec.push_back( nlNodeVec[kount]);
        kount++;
    }
    stackVec.clear();
    return (ExprNode*)nlNodeVec[ kount - 1];
}//end createExpressionTreeFromPostfix


// Dummy implementations for calculate functions
double ExprNode::calculateFunction(double *x)
{
    return OSNaN();
}

std::complex<double> ExprNode::calculateFunction_C(double *x)
{
    return 0;
}

OSMatrix* ExprNode::calculateFunction_M(double *x)
{
    return NULL;
}

ADdouble ExprNode::constructADTape(std::map<int, int> *ADIdx, ADvector *XAD)
{
    return 0.0;
}

//ADdouble ExprNode::constructADTape_M(std::map<int, int> *ADIdx, ADvector *XAD){};

//ADdouble ExprNode::constructADTape_C(std::map<int, int> *ADIdx, ADvector *XAD){};

bool ExprNode::IsEqual(ExprNode *that)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, "Start comparing in ExprNode");
#endif
    if (this == NULL)
    {
        if (that == NULL)
            return true;
        else
        {
#ifndef NDEBUG
            osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, 
                "First object is NULL, second is not");
#endif
            return false;
        }
    }
    else
    {
        if (that == NULL)
        {
#ifndef NDEBUG
            osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, 
                "Second object is NULL, first is not");
#endif
            return false;
        }
        else
        {
            if (this->inodeInt != that->inodeInt)
                return false;
            if (this->inodeKind != that->inodeKind)
                return false;
            if (this->inumberOfChildren != that->inumberOfChildren)
                return false;

            for (unsigned int i = 0; i < this->inumberOfChildren; i++)
                if (!this->m_mChildren[i]->IsEqual(that->m_mChildren[i]))
                    return false;

            return true;
        }
    }
}//ExprNode::IsEqual
// End of ExprNode methods

//
//ScalarNode methods
//

ScalarNode::ScalarNode():
    ExprNode(){
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, "inside ScalarNode constructor");
#endif
}//end ScalarNode

ScalarNode::~ScalarNode()
{
#ifndef NDEBUG
    std::ostringstream outStr;
    outStr << "inside ScalarNode destructor" << std::endl;
    outStr << "number of kids = " <<  inumberOfChildren << std::endl;
#endif
}//end ~ScalarNode


std::string ScalarNode::getTokenName()
{
    return "generic scalar";
}//getTokenName


std::string ScalarNode::getTokenNumber()
{
    return "0";
}//getTokenNumber

bool ScalarNode::IsEqual(ScalarNode *that)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, "Start comparing in ScalarNode");
#endif
    if (this == NULL)
    {
        if (that == NULL)
            return true;
        else
        {
#ifndef NDEBUG
            osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, 
                "First object is NULL, second is not");
#endif
            return false;
        }
    }
    else
    {
        if (that == NULL)
        {
#ifndef NDEBUG
            osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, 
                "Second object is NULL, first is not");
#endif
            return false;
        }
        else
        {
            if (this->inodeInt != that->inodeInt)
                return false;
            if (this->inodeKind != that->inodeKind)
                return false;
            if (this->inumberOfChildren != that->inumberOfChildren)
                return false;

            for (unsigned int i = 0; i < this->inumberOfChildren; i++)
                if (!this->m_mChildren[i]->IsEqual(that->m_mChildren[i]))
                    return false;

            return true;
        }
    }
}//ScalarNode::IsEqual
// End of ScalarNode methods


//
//OSnLNode methods
//

OSnLNode::OSnLNode():
    ScalarNode(),
    m_dFunctionValue( OSNaN())
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, "inside OSnLNode constructor");
#endif
}//end OSnLNode

OSnLNode::~OSnLNode()
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, "inside OSnLNode destructor");
#endif
}//end ~OSnLNode

void OSnLNode::getVariableIndexMap(std::map<int, int> *varIdx)
{
    unsigned int i;
    if(inodeInt != OS_VARIABLE)
    {
        for(i = 0; i < inumberOfChildren; i++)
        {
            if (!m_mChildren[ i]->inodeKind == 1)
                throw ErrorClass("Can only evaluate real-valued nodes so far");
            ((OSnLNode*)m_mChildren[ i])->getVariableIndexMap( varIdx);
        }
    }
}//getVariableIndexMap


OSnLNode* OSnLNode::createExpressionTreeFromPrefix(std::vector<ExprNode*> nlNodeVec)
{
    std::vector<ExprNode*> stackVec;
    int kount =  nlNodeVec.size() - 1;
    while(kount >= 0)
    {
        int numkids = nlNodeVec[kount]->inumberOfChildren;

        if(numkids > 0)
        {
            for(int i = 0; i < numkids; i++)
            {
                nlNodeVec[kount]->m_mChildren[i] = (OSnLNode*)stackVec.back();
                stackVec.pop_back();
            }
        }
        stackVec.push_back( nlNodeVec[kount]);
        kount--;
    }
    stackVec.clear();
    return (OSnLNode*)nlNodeVec[ 0];
}//end createExpressionTreeFromPrefix

#if 0
std::vector<ExprNode*> OSnLNode::getPrefixFromExpressionTree()
{
    std::vector<ExprNode*> prefixVector;
    return preOrderOSnLNodeTraversal( &prefixVector);
}//getPrefixFromExpressionTree

std::vector<ExprNode*> OSnLNode::preOrderOSnLNodeTraversal( std::vector<ExprNode*> *prefixVector)
{
    (*prefixVector).push_back( (OSnLNode*)this);
    if(inumberOfChildren > 0)
    {
        for(unsigned int i = 0; i < inumberOfChildren; i++)
            m_mChildren[i]->preOrderOSnLNodeTraversal( prefixVector);
    }
    return *prefixVector;
}//end preOrderOSnLNodeTraversal
#endif

OSnLNode* OSnLNode::createExpressionTreeFromPostfix(std::vector<ExprNode*> nlNodeVec)
{
    std::vector<ExprNode*> stackVec;

    unsigned int kount =  0;
    while(kount <= nlNodeVec.size() - 1)
    {
        int numkids = nlNodeVec[kount]->inumberOfChildren;
        if (numkids  > 0)
        {
            for(int i = numkids - 1; i >= 0;  i--)
            {
                nlNodeVec[kount]->m_mChildren[i] = (OSnLNode*)stackVec.back();
                stackVec.pop_back();
            }
        }
        stackVec.push_back( nlNodeVec[kount]);
        kount++;
    }
    stackVec.clear();
    return (OSnLNode*)nlNodeVec[ kount - 1];
}//end createExpressionTreeFromPostfix

#if 0
std::vector<ExprNode*> OSnLNode::getPostfixFromExpressionTree( )
{
    std::vector<ExprNode*> postfixVector;
std::cout << "get postfix from an OSnLNode" << std::endl;
    return postOrderOSnLNodeTraversal( &postfixVector);
}//getPostfixFromExpressionTree

std::vector<ExprNode*> OSnLNode::postOrderOSnLNodeTraversal( std::vector<ExprNode*> *postfixVector)
{
    if(inumberOfChildren > 0)
    {
        unsigned int i;
        for(i = 0; i < inumberOfChildren; i++)
            m_mChildren[i]->postOrderOSnLNodeTraversal( postfixVector);
    }
    (*postfixVector).push_back( (OSnLNode*)this);
    return *postfixVector;
}//end postOrderOSnLNodeTraversal()
#endif

bool OSnLNode::IsEqual(OSnLNode *that)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, "Start comparing in OSnLNode");
#endif
    if (this == NULL)
    {
        if (that == NULL)
            return true;
        else
        {
#ifndef NDEBUG
            osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, 
                "First object is NULL, second is not");
#endif
            return false;
        }
    }
    else
    {
        if (that == NULL)
        {
#ifndef NDEBUG
            osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, 
                "Second object is NULL, first is not");
#endif
            return false;
        }
        else
        {
            if (this->inumberOfChildren != that->inumberOfChildren)
                return false;
            if (this->inodeInt != that->inodeInt)
                return false;
            if (this->inodeKind != that->inodeKind)
                return false;

            for (unsigned int i = 0; i < this->inumberOfChildren; i++)
                if (!this->m_mChildren[i]->IsEqual(that->m_mChildren[i]))
                    return false;

            return true;
        }
    }
}//OSnLNode::IsEqual


// OSnLNodePlus Methods
OSnLNodePlus::OSnLNodePlus()
{
    inumberOfChildren = 2;
    m_mChildren = new ExprNode*[2];
    m_mChildren[ 0] = NULL;
    m_mChildren[ 1] = NULL;
    inodeInt = OS_PLUS;
    inodeKind = 1;
}//end OSnLNodePlus


OSnLNodePlus::~OSnLNodePlus()
{
    std::ostringstream outStr;
#ifndef NDEBUG
    outStr << "inside OSnLNodePlus destructor" << endl;
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, outStr.str());
#endif
}//end ~OSnLNodePlus

std::string OSnLNodePlus::getTokenName()
{
    return "plus";
}// end OSnLNodePlus::getTokenName()

double OSnLNodePlus::calculateFunction(double *x)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSExpressionTree, 
                      ENUM_OUTPUT_LEVEL_trace, "in OSnLNodePlus::calculateFunction");
#endif
    if (!m_mChildren[0]->inodeKind == 1 || !m_mChildren[1]->inodeKind == 1)
        throw ErrorClass("Can only evaluate real-valued nodes so far");
    m_dFunctionValue = ((OSnLNode*)m_mChildren[0])->calculateFunction(x) + 
                       ((OSnLNode*)m_mChildren[1])->calculateFunction(x);
    return m_dFunctionValue;
}// end OSnLNodePlus::calculate


ADdouble OSnLNodePlus::constructADTape(std::map<int, int> *ADIdx, ADvector *XAD)
{
    if (!m_mChildren[0]->inodeKind == 1 || !m_mChildren[1]->inodeKind == 1)
        throw ErrorClass("Can only evaluate real-valued nodes so far");
    m_ADTape = ((OSnLNode*)m_mChildren[0])->constructADTape( ADIdx,  XAD) + 
               ((OSnLNode*)m_mChildren[1])->constructADTape( ADIdx,  XAD);
    return m_ADTape;
}// end OSnLNodePlus::constructADTape


ExprNode* OSnLNodePlus::cloneExprNode()
{
    std::ostringstream outStr;
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, "cloning an OSnLNodePlus");
#endif
    ExprNode *nlNodePoint;
    nlNodePoint = new OSnLNodePlus();
#ifndef NDEBUG
    outStr.str( std::string() );
    outStr.clear();
    outStr << "Allocate memory at address " << nlNodePoint << std::endl;
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, outStr.str());
#endif
//    CLONE_CHILDREN;
        if (inumberOfChildren > 0)                              
        {                                                       
            if (nlNodePoint->m_mChildren == NULL)               
                nlNodePoint->m_mChildren                        
                    = new ExprNode*[inumberOfChildren];         
            for (unsigned int i=0; i < inumberOfChildren; i++)  
            {                                                   
                nlNodePoint->m_mChildren[i]                     
                    = this->m_mChildren[i]->cloneExprNode();
            }                                                   
            nlNodePoint->inumberOfChildren = inumberOfChildren;
        }                                                     
    return nlNodePoint;
}//end OSnLNodePlus::cloneExprNode


//
// OSnLNodeSum Methods
OSnLNodeSum::OSnLNodeSum()
{
    inumberOfChildren = 0;
    inodeInt = OS_SUM;
    inodeKind = 1;
}//end OSnLNodeSum

OSnLNodeSum::~OSnLNodeSum()
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, "inside OSnLNodeSum destructor");
#endif
}//end ~OSnLNodeSum

std::string OSnLNodeSum::getTokenName()
{
    return "sum";
}// end OSnLNodeSum::getTokenName()

double OSnLNodeSum::calculateFunction(double *x)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSExpressionTree, 
                      ENUM_OUTPUT_LEVEL_trace, "in OSnLNodeSum::calculateFunction");
#endif
    m_dFunctionValue = 0.0;
    unsigned int i;
    for(i = 0; i < inumberOfChildren; i++)
    {
        m_dFunctionValue = m_dFunctionValue + m_mChildren[i]->calculateFunction(x);
    }
    return m_dFunctionValue;
}// end OSnLNodeSum::calculate


ADdouble OSnLNodeSum::constructADTape(std::map<int, int> *ADIdx, ADvector *XAD)
{
    m_ADTape = 0.0;
    unsigned int i;
    for(i = 0; i < inumberOfChildren; i++)
    {
        m_ADTape = m_ADTape + m_mChildren[i]->constructADTape( ADIdx, XAD);
    }
    return m_ADTape;
}// end OSnLNodeSum::constructADTape

ExprNode* OSnLNodeSum::cloneExprNode()
{
    std::ostringstream outStr;
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, "cloning an OSnLNodeSum");
#endif
    ExprNode *nlNodePoint;
    nlNodePoint = new OSnLNodeSum();
#ifndef NDEBUG
    outStr << "Allocate memory at address " << nlNodePoint << std::endl;
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, outStr.str());
#endif
//    CLONE_CHILDREN;
        if (inumberOfChildren > 0)                              
        {                                                       
            if (nlNodePoint->m_mChildren == NULL)               
                nlNodePoint->m_mChildren                        
                    = new ExprNode*[inumberOfChildren];         
            for (unsigned int i=0; i < inumberOfChildren; i++)  
            {                                                   
                nlNodePoint->m_mChildren[i]                     
                    = this->m_mChildren[i]->cloneExprNode();    
            }
            nlNodePoint->inumberOfChildren = inumberOfChildren;
        }                                                       
    return  nlNodePoint;
}//end OSnLNodeSum::cloneExprNode
//end OSnLNodeSum methods


//
// OSnLNodeAllDiff Methods

OSnLNodeAllDiff::OSnLNodeAllDiff()
{
    inumberOfChildren = 0;
    inodeInt = OS_ALLDIFF;
    inodeKind = 1;
}//end OSnLNodeAllDiff

OSnLNodeAllDiff::~OSnLNodeAllDiff()
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, "inside OSnLNodeAllDiff destructor");
#endif
}//end ~OSnLNodeAllDiff

std::string OSnLNodeAllDiff::getTokenName()
{
    return "allDiff";
}// end OSnLNodeAllDiff::getTokenName(


double OSnLNodeAllDiff::calculateFunction(double *x)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSExpressionTree, 
                      ENUM_OUTPUT_LEVEL_trace, "in OSnLNodeAllDiff::calculateFunction");
#endif
    m_dFunctionValue = 1;
    // return false if not all different
    unsigned int i, k;
    if(inumberOfChildren > 1)
    {
        for(i = 0; i < inumberOfChildren - 1; i++)
        {
            for(k = i + 1; k < inumberOfChildren; k++)
            {
                if(m_mChildren[i]->calculateFunction(x) ==
                        m_mChildren[k]->calculateFunction(x)) return 0 ;
            }
        }
    }

    return m_dFunctionValue;
}// end OSnLNodeAllDiff::calculate


ADdouble OSnLNodeAllDiff::constructADTape(std::map<int, int> *ADIdx, ADvector *XAD)
{
    try
    {
        throw ErrorClass("AllDifferent operator not supported by current Algorithmic Differentiation implementation");
        return m_ADTape;
    }
    catch(const ErrorClass& eclass)
    {
        throw ErrorClass( eclass.errormsg);
    }
    return m_ADTape;
}// end OSnLNodeAllDiff::constructADTape


ExprNode* OSnLNodeAllDiff::cloneExprNode()
{
    std::ostringstream outStr;
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, "cloning an OSnLNodeAllDiff");
#endif
    ExprNode *nlNodePoint;
    nlNodePoint = new OSnLNodeAllDiff();
#ifndef NDEBUG
    outStr << "Allocate memory at address " << nlNodePoint << std::endl;
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, outStr.str());
#endif
//    CLONE_CHILDREN;
        if (inumberOfChildren > 0)                              
        {                                                       
            if (nlNodePoint->m_mChildren == NULL)               
                nlNodePoint->m_mChildren                        
                    = new ExprNode*[inumberOfChildren];         
            for (unsigned int i=0; i < inumberOfChildren; i++)  
            {                                                   
                nlNodePoint->m_mChildren[i]                     
                    = this->m_mChildren[i]->cloneExprNode();    
            }                                                   
            nlNodePoint->inumberOfChildren = inumberOfChildren;
        }                                                       
    return  nlNodePoint;
}//end OSnLNodeAllDiff::cloneExprNode
//end OSnLNodeAllDiff methods


//
// OSnLNodeMax Methods
OSnLNodeMax::OSnLNodeMax()
{
    inumberOfChildren = 0;
    inodeInt = OS_MAX;
    inodeKind = 1;
}//end OSnLNodeMax

OSnLNodeMax::~OSnLNodeMax()
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, "inside OSnLNodeMax destructor");
#endif
}//end ~OSnLNodeMax

double OSnLNodeMax::calculateFunction(double *x)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSExpressionTree, 
                      ENUM_OUTPUT_LEVEL_trace, "in OSnLNodeMax::calculateFunction");
#endif
    m_dFunctionValue = -OSDBL_MAX;

    for(unsigned int i = 0; i < inumberOfChildren; i++)
    {
        if(m_mChildren[i]->calculateFunction(x) > m_dFunctionValue)
        {
            m_dFunctionValue = m_mChildren[i]->calculateFunction(x);
        }
    }
    return m_dFunctionValue;
}// end OSnLNodeMax::calculate

std::string OSnLNodeMax::getTokenName()
{
    return "max";
}// end OSnLNodeMax::getTokenName(


ADdouble OSnLNodeMax::constructADTape(std::map<int, int> *ADIdx, ADvector *XAD)
{
    //if not support in AD, throw an exception
    try
    {
        throw ErrorClass("Max operator not supported by current Algorithmic Differentiation implementation");
        return m_ADTape;
    }
    catch(const ErrorClass& eclass)
    {
        throw ErrorClass( eclass.errormsg);
    }
}// end OSnLNodeMax::constructADTape


ExprNode* OSnLNodeMax::cloneExprNode()
{
    std::ostringstream outStr;
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, "cloning an OSnLNodeMax");
#endif
    ExprNode *nlNodePoint;
    nlNodePoint = new OSnLNodeMax();
#ifndef NDEBUG
    outStr << "Allocate memory at address " << nlNodePoint << std::endl;
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, outStr.str());
#endif
//    CLONE_CHILDREN;
        if (inumberOfChildren > 0)                              
        {                                                       
            if (nlNodePoint->m_mChildren == NULL)               
                nlNodePoint->m_mChildren                        
                    = new ExprNode*[inumberOfChildren];         
            for (unsigned int i=0; i < inumberOfChildren; i++)  
            {                                                   
                nlNodePoint->m_mChildren[i]                     
                    = this->m_mChildren[i]->cloneExprNode();    
            }                                                   
            nlNodePoint->inumberOfChildren = inumberOfChildren;
        }                                                       
    return  nlNodePoint;
}//end OSnLNodeMax::cloneExprNode


//
// OSnLNodeMin Methods
OSnLNodeMin::OSnLNodeMin()
{
    inumberOfChildren = 0;
    inodeInt = OS_MIN;
    inodeKind = 1;
}//end OSnLNodeMin

OSnLNodeMin::~OSnLNodeMin()
{
#ifndef NDEBUG

    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, "inside OSnLNodeMin destructor");
#endif
}//end ~OSnLNodeMin


std::string OSnLNodeMin::getTokenName()
{
    return "min";
}// end OSnLNodeMin::getTokenName(

double OSnLNodeMin::calculateFunction(double *x)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSExpressionTree, 
                      ENUM_OUTPUT_LEVEL_trace, "in OSnLNodeMin::calculateFunction");
#endif
    m_dFunctionValue = OSDBL_MAX;

    for(unsigned int i = 0; i < inumberOfChildren; i++)
    {
        if(m_mChildren[i]->calculateFunction(x) < m_dFunctionValue)
        {
            m_dFunctionValue = m_mChildren[i]->calculateFunction(x);
        }
    }
    return m_dFunctionValue;
}// end OSnLNodeMin::calculate


ADdouble OSnLNodeMin::constructADTape(std::map<int, int> *ADIdx, ADvector *XAD)
{
    //if not support in AD, throw an exception
    try
    {
        throw ErrorClass("Min operator not supported by current Algorithmic Differentiation implementation");
        return m_ADTape;
    }
    catch(const ErrorClass& eclass)
    {
        throw ErrorClass( eclass.errormsg);
    }
}// end OSnLNodeMin::constructADTape


ExprNode* OSnLNodeMin::cloneExprNode()
{
    std::ostringstream outStr;
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, "cloning an OSnLNodeMin");
#endif
    ExprNode *nlNodePoint;
    nlNodePoint = new OSnLNodeMin();
#ifndef NDEBUG
    outStr << "Allocate memory at address " << nlNodePoint << std::endl;
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, outStr.str());
#endif
//    CLONE_CHILDREN;
        if (inumberOfChildren > 0)                              
        {                                                       
            if (nlNodePoint->m_mChildren == NULL)               
                nlNodePoint->m_mChildren                        
                    = new ExprNode*[inumberOfChildren];         
            for (unsigned int i=0; i < inumberOfChildren; i++)  
            {                                                   
                nlNodePoint->m_mChildren[i]                     
                    = this->m_mChildren[i]->cloneExprNode();    
            }                                                   
            nlNodePoint->inumberOfChildren = inumberOfChildren;
        }                                                       
    return nlNodePoint;
}//end OSnLNodeMin::cloneExprNode


//
// OSnLNodeMinus Methods
OSnLNodeMinus::OSnLNodeMinus()
{
    inumberOfChildren = 2;
    m_mChildren = new ExprNode*[2];
    m_mChildren[ 0] = NULL;
    m_mChildren[ 1] = NULL;
    inodeInt = OS_MINUS;
    inodeKind = 1;
}//end OSnLNodeMinus


OSnLNodeMinus::~OSnLNodeMinus()
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, "inside OSnLNodeMinus destructor");
#endif
}//end ~OSnLNodeMinus

std::string OSnLNodeMinus::getTokenName()
{
    return "minus";
}// end OSnLNodeMinus::getTokenName(

double OSnLNodeMinus::calculateFunction(double *x)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSExpressionTree, 
                      ENUM_OUTPUT_LEVEL_trace, "in OSnLNodeMinus::calculateFunction");
#endif
    m_dFunctionValue =  m_mChildren[0]->calculateFunction( x) - m_mChildren[1]->calculateFunction( x);
    return m_dFunctionValue;
}// end OSnLNodeMinus::calculate


ADdouble OSnLNodeMinus::constructADTape(std::map<int, int> *ADIdx, ADvector *XAD)
{
    m_ADTape = m_mChildren[0]->constructADTape( ADIdx, XAD) - m_mChildren[1]->constructADTape( ADIdx, XAD);
    return m_ADTape;
}// end OSnLNodeMinus::constructADTape


ExprNode* OSnLNodeMinus::cloneExprNode()
{
    std::ostringstream outStr;
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, "cloning an OSnLNodeMinus");
#endif
    ExprNode *nlNodePoint;
    nlNodePoint = new OSnLNodeMinus();
#ifndef NDEBUG
    outStr << "Allocate memory at address " << nlNodePoint << std::endl;
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, outStr.str());
#endif
//    CLONE_CHILDREN;
        if (inumberOfChildren > 0)                              
        {                                                       
            if (nlNodePoint->m_mChildren == NULL)               
                nlNodePoint->m_mChildren                        
                    = new ExprNode*[inumberOfChildren];         
            for (unsigned int i=0; i < inumberOfChildren; i++)  
            {                                                   
                nlNodePoint->m_mChildren[i]                     
                    = this->m_mChildren[i]->cloneExprNode();    
            }                                                   
            nlNodePoint->inumberOfChildren = inumberOfChildren;
        }                                                       
    return  nlNodePoint;
}//end OSnLNodeMinus::cloneExprNode


//
//
// OSnLNodeNegate Methods
OSnLNodeNegate::OSnLNodeNegate()
{
    inumberOfChildren = 1;
    m_mChildren = new ExprNode*[1];
    m_mChildren[ 0] = NULL;
    inodeInt = OS_NEGATE;
    inodeKind = 1;
}//end OSnLNodeNegate


OSnLNodeNegate::~OSnLNodeNegate()
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, "inside OSnLNodeNegate destructor");
#endif
}//end ~OSnLNodeNegate

std::string OSnLNodeNegate::getTokenName()
{
    return "negate";
}// end OSnLNodeNegate::getTokenName(

double OSnLNodeNegate::calculateFunction(double *x)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSExpressionTree, 
                      ENUM_OUTPUT_LEVEL_trace, "in OSnLNodeNegate::calculateFunction");
#endif
    m_dFunctionValue =  -m_mChildren[0]->calculateFunction( x) ;
    return m_dFunctionValue;
}// end OSnLNodeMinus::calculate

ADdouble OSnLNodeNegate::constructADTape(std::map<int, int> *ADIdx, ADvector *XAD)
{
    m_ADTape = -m_mChildren[0]->constructADTape( ADIdx, XAD);
    return m_ADTape;
}// end OSnLNodeNegate::constructADTape

ExprNode* OSnLNodeNegate::cloneExprNode()
{
    std::ostringstream outStr;
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, "cloning an OSnLNodeNegate");
#endif
    ExprNode *nlNodePoint;
    nlNodePoint = new OSnLNodeNegate();
#ifndef NDEBUG
    outStr << "Allocate memory at address " << nlNodePoint << std::endl;
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, outStr.str());
#endif
//    CLONE_CHILDREN;
        if (inumberOfChildren > 0)                              
        {                                                       
            if (nlNodePoint->m_mChildren == NULL)               
                nlNodePoint->m_mChildren                        
                    = new ExprNode*[inumberOfChildren];         
            for (unsigned int i=0; i < inumberOfChildren; i++)  
            {                                                   
                nlNodePoint->m_mChildren[i]                     
                    = this->m_mChildren[i]->cloneExprNode();    
            }                                                   
            nlNodePoint->inumberOfChildren = inumberOfChildren;
        }                                                       
    return  nlNodePoint;
}//end OSnLNodeNegate::cloneExprNode


// OSnLNodeTimes Methods
OSnLNodeTimes::OSnLNodeTimes()
{
    inumberOfChildren = 2;
    m_mChildren = new ExprNode*[2];
    m_mChildren[ 0] = NULL;
    m_mChildren[ 1] = NULL;
    inodeInt = OS_TIMES;
    inodeKind = 1;
}//end OSnLNodeTimes


OSnLNodeTimes::~OSnLNodeTimes()
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, "inside OSnLNodeTimes destructor");
#endif
}//end ~OSnLNodeTimes

std::string OSnLNodeTimes::getTokenName()
{
    return "times";
}// end OSnLNodeTimes::getTokenName(

double OSnLNodeTimes::calculateFunction(double *x)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSExpressionTree, 
                      ENUM_OUTPUT_LEVEL_trace, "in OSnLNodeTimes::calculateFunction");
#endif
    m_dFunctionValue = m_mChildren[0]->calculateFunction( x)*m_mChildren[1]->calculateFunction( x);
    return m_dFunctionValue;
}// end OSnLNodeTimes::calculate


ADdouble OSnLNodeTimes::constructADTape(std::map<int, int> *ADIdx, ADvector *XAD)
{
    m_ADTape = m_mChildren[0]->constructADTape( ADIdx, XAD) * m_mChildren[1]->constructADTape( ADIdx, XAD);
    return m_ADTape;
}// end OSnLNodeTimes::constructADTape

ExprNode* OSnLNodeTimes::cloneExprNode()
{
    std::ostringstream outStr;
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, "cloning an OSnLNodeTimes");
#endif
    ExprNode *nlNodePoint;
    nlNodePoint = new OSnLNodeTimes();
#ifndef NDEBUG
    outStr << "Allocate memory at address " << nlNodePoint << std::endl;
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, outStr.str());
#endif
//    CLONE_CHILDREN;
        if (inumberOfChildren > 0)                              
        {                                                       
            if (nlNodePoint->m_mChildren == NULL)               
                nlNodePoint->m_mChildren                        
                    = new ExprNode*[inumberOfChildren];         
            for (unsigned int i=0; i < inumberOfChildren; i++)  
            {                                                   
                nlNodePoint->m_mChildren[i]                     
                    = this->m_mChildren[i]->cloneExprNode();    
            }                                                   
            nlNodePoint->inumberOfChildren = inumberOfChildren;
        }                                                       
    return  nlNodePoint;
}//end OSnLNodeTimes::cloneExprNode


//
// OSnLNodeDivide Methods
OSnLNodeDivide::OSnLNodeDivide()
{
    inumberOfChildren = 2;
    m_mChildren = new ExprNode*[2];
    m_mChildren[ 0] = NULL;
    m_mChildren[ 1] = NULL;
    inodeInt = OS_DIVIDE;
    inodeKind = 1;
}//end OSnLNodeDivide


OSnLNodeDivide::~OSnLNodeDivide()
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, "inside OSnLNodeDivide destructor");
#endif
}//end ~OSnLNodeDivide

std::string OSnLNodeDivide::getTokenName()
{
    return "divide";
}// end OSnLNodeDivide::getTokenName(

double OSnLNodeDivide::calculateFunction(double *x)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSExpressionTree, 
                      ENUM_OUTPUT_LEVEL_trace, "in OSnLNodeDivide::calculateFunction");
#endif
    // kipp throw error if we divide by 0
    m_dFunctionValue = m_mChildren[0]->calculateFunction( x)/m_mChildren[1]->calculateFunction( x);
    return m_dFunctionValue;
}// end OSnLNodeDivide::calculate


ADdouble OSnLNodeDivide::constructADTape(std::map<int, int> *ADIdx, ADvector *XAD)
{
    m_ADTape = m_mChildren[0]->constructADTape( ADIdx, XAD) / m_mChildren[1]->constructADTape( ADIdx, XAD);
    return m_ADTape;
}// end OSnLNodeDivide::constructADTape


ExprNode* OSnLNodeDivide::cloneExprNode()
{
    std::ostringstream outStr;
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, "cloning an OSnLNodeDivide");
#endif
    ExprNode *nlNodePoint;
    nlNodePoint = new OSnLNodeDivide();
#ifndef NDEBUG
    outStr << "Allocate memory at address " << nlNodePoint << std::endl;
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, outStr.str());
#endif
//    CLONE_CHILDREN;
        if (inumberOfChildren > 0)                              
        {                                                       
            if (nlNodePoint->m_mChildren == NULL)               
                nlNodePoint->m_mChildren                        
                    = new ExprNode*[inumberOfChildren];         
            for (unsigned int i=0; i < inumberOfChildren; i++)  
            {                                                   
                nlNodePoint->m_mChildren[i]                     
                    = this->m_mChildren[i]->cloneExprNode();    
            }                                                   
            nlNodePoint->inumberOfChildren = inumberOfChildren;
        }                                                       
    return  nlNodePoint;
}//end OSnLNodeDivide::cloneExprNode


//
// OSnLNodePower Methods
OSnLNodePower::OSnLNodePower()
{
    inumberOfChildren = 2;
    m_mChildren = new ExprNode*[2];
    m_mChildren[ 0] = NULL;
    m_mChildren[ 1] = NULL;
    inodeInt = OS_POWER;
    inodeKind = 1;
}//end OSnLNodePower


OSnLNodePower::~OSnLNodePower()
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, "inside OSnLNodePower destructor");
#endif
}//end ~OSnLNodePower

std::string OSnLNodePower::getTokenName()
{
    return "power";
}// end OSnLNodePower::getTokenName(

double OSnLNodePower::calculateFunction(double *x)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSExpressionTree, 
                      ENUM_OUTPUT_LEVEL_trace, "in OSnLNodePower::calculateFunction");
#endif
    // kipp throw error if operation not defined
    m_dFunctionValue =  pow(m_mChildren[0]->calculateFunction( x), m_mChildren[1]->calculateFunction( x));
    return  m_dFunctionValue;
}// end OSnLNodePower::calculate

//
ADdouble OSnLNodePower::constructADTape(std::map<int, int> *ADIdx, ADvector *XAD)
{
    //if( typeid( *m_mChildren[1]) == typeid( OSnLNodeNumber) ) {
    if( this->m_mChildren[1]->inodeInt == OS_NUMBER )
    {
        OSnLNodeNumber *numberNode  =  (OSnLNodeNumber*)m_mChildren[1];
        // we have a number node see if integer
        if( (numberNode->value) == int( numberNode->value))
        {
            m_ADTape =  pow(m_mChildren[0]->constructADTape( ADIdx, XAD) ,  int( numberNode->value));
        }
        else m_ADTape = pow(m_mChildren[0]->constructADTape( ADIdx, XAD) , m_mChildren[1]->constructADTape( ADIdx, XAD) );
    }
    else
    {
        m_ADTape = pow(m_mChildren[0]->constructADTape( ADIdx, XAD) , m_mChildren[1]->constructADTape( ADIdx, XAD) );
    }
    return m_ADTape;
}// end OSnLNodePower::constructADTape


//ADdouble OSnLNodePower::constructADTape(std::map<int, int> *ADIdx, ADvector *XAD){
//        m_ADTape = AD::pow(m_mChildren[0]->constructADTape( ADIdx, XAD) , m_mChildren[1]->constructADTape( ADIdx, XAD) );
//    return m_ADTape;
//}// end OSnLNodePower::constructADTape


ExprNode* OSnLNodePower::cloneExprNode()
{
    std::ostringstream outStr;
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, "cloning an OSnLNodePower");
#endif
    ExprNode *nlNodePoint;
    nlNodePoint = new OSnLNodePower();
#ifndef NDEBUG
    outStr << "Allocate memory at address " << nlNodePoint << std::endl;
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, outStr.str());
#endif
//    CLONE_CHILDREN;
        if (inumberOfChildren > 0)                              
        {                                                       
            if (nlNodePoint->m_mChildren == NULL)               
                nlNodePoint->m_mChildren                        
                    = new ExprNode*[inumberOfChildren];         
            for (unsigned int i=0; i < inumberOfChildren; i++)  
            {                                                   
                nlNodePoint->m_mChildren[i]                     
                    = this->m_mChildren[i]->cloneExprNode();    
            }                                                   
            nlNodePoint->inumberOfChildren = inumberOfChildren;
        }                                                       
    return  nlNodePoint;
}//end OSnLNodePower::cloneExprNode


//
// OSnLNodeProduct Methods
OSnLNodeProduct::OSnLNodeProduct()
{
    inumberOfChildren = 0;
    inodeInt = OS_PRODUCT;
    inodeKind = 1;
}//end OSnLNodeProduct


OSnLNodeProduct::~OSnLNodeProduct()
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, "inside OSnLNodeProduct destructor");
#endif
}//end ~OSnLNodeProduct

std::string OSnLNodeProduct::getTokenName()
{
    return "product";
}// end OSnLNodeProduct::getTokenName(

double OSnLNodeProduct::calculateFunction(double *x)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSExpressionTree, 
                      ENUM_OUTPUT_LEVEL_trace, "in OSnLNodeProduct::calculateFunction");
#endif
    // kipp throw error if operation not defined
    m_dFunctionValue = 1.0;
    unsigned int i;
    for(i = 0; i < inumberOfChildren; i++)
    {
        m_dFunctionValue = m_dFunctionValue*m_mChildren[i]->calculateFunction(x);
    }
    return m_dFunctionValue;
}// end OSnLNodeProduct::calculate


ADdouble OSnLNodeProduct::constructADTape(std::map<int, int> *ADIdx, ADvector *XAD)
{
    m_ADTape = 1.0;
    unsigned int i;
    for(i = 0; i < inumberOfChildren; i++)
    {
        m_ADTape = m_ADTape*m_mChildren[i]->constructADTape( ADIdx, XAD);
    }
    return m_ADTape;
}// end OSnLNodeProduct::constructADTape


ExprNode* OSnLNodeProduct::cloneExprNode()
{
    std::ostringstream outStr;
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, "cloning an OSnLNodeProduct");
#endif
    ExprNode *nlNodePoint;
    nlNodePoint = new OSnLNodeProduct();
#ifndef NDEBUG
    outStr << "Allocate memory at address " << nlNodePoint << std::endl;
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, outStr.str());
#endif
//    CLONE_CHILDREN;
        if (inumberOfChildren > 0)                              
        {                                                       
            if (nlNodePoint->m_mChildren == NULL)               
                nlNodePoint->m_mChildren                        
                    = new ExprNode*[inumberOfChildren];         
            for (unsigned int i=0; i < inumberOfChildren; i++)  
            {                                                   
                nlNodePoint->m_mChildren[i]                     
                    = this->m_mChildren[i]->cloneExprNode();    
            }                                                   
            nlNodePoint->inumberOfChildren = inumberOfChildren;
        }                                                       
    return  nlNodePoint;
}//end OSnLNodeProduct::cloneExprNode


//
// OSnLNodeLn Methods
OSnLNodeLn::OSnLNodeLn()
{
    inumberOfChildren = 1;
    m_mChildren = new ExprNode*[1];
    m_mChildren[ 0] = NULL;
    inodeInt = OS_LN;
    inodeKind = 1;
}//end OSnLNodeLn


OSnLNodeLn::~OSnLNodeLn()
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, "inside OSnLNodeLn destructor");
#endif
}//end ~OSnLNodeLn

std::string OSnLNodeLn::getTokenName()
{
    return "ln";
}// end OSnLNodeLn::getTokenName(

double OSnLNodeLn::calculateFunction(double *x)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSExpressionTree, 
                      ENUM_OUTPUT_LEVEL_trace, "in OSnLNodeLn::calculateFunction");
#endif
    m_dFunctionValue = log(m_mChildren[0]->calculateFunction( x) );
    return m_dFunctionValue;
}// end OSnLNodeLn::calculate


ADdouble OSnLNodeLn::constructADTape(std::map<int, int> *ADIdx, ADvector *XAD)
{
    m_ADTape = log( m_mChildren[0]->constructADTape( ADIdx, XAD) );
    return m_ADTape;
}// end OSnLNodeLn::constructADTape

ExprNode* OSnLNodeLn::cloneExprNode()
{
    std::ostringstream outStr;
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, "cloning an OSnLNodeLn");
#endif
    ExprNode *nlNodePoint;
    nlNodePoint = new OSnLNodeLn();
#ifndef NDEBUG
    outStr << "Allocate memory at address " << nlNodePoint << std::endl;
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, outStr.str());
#endif
//    CLONE_CHILDREN;
        if (inumberOfChildren > 0)                              
        {                                                       
            if (nlNodePoint->m_mChildren == NULL)               
                nlNodePoint->m_mChildren                        
                    = new ExprNode*[inumberOfChildren];         
            for (unsigned int i=0; i < inumberOfChildren; i++)  
            {                                                   
                nlNodePoint->m_mChildren[i]                     
                    = this->m_mChildren[i]->cloneExprNode();    
            }                                                   
            nlNodePoint->inumberOfChildren = inumberOfChildren;
        }                                                       
    return  nlNodePoint;
}//end OSnLNodeLn::cloneExprNode


//
// OSnLNodeSqrt Methods
OSnLNodeSqrt::OSnLNodeSqrt()
{
    inumberOfChildren = 1;
    m_mChildren = new ExprNode*[1];
    m_mChildren[ 0] = NULL;
    inodeInt = OS_SQRT;
    inodeKind = 1;
}//end OSnLNodeSqrt


OSnLNodeSqrt::~OSnLNodeSqrt()
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, "inside OSnLNodeSqrt destructor");
#endif
}//end ~OSnLNodeSqrt

std::string OSnLNodeSqrt::getTokenName()
{
    return "sqrt";
}// end OSnLNodeSqrt::getTokenName(

double OSnLNodeSqrt::calculateFunction(double *x)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSExpressionTree, 
                      ENUM_OUTPUT_LEVEL_trace, "in OSnLNodeSqrt::calculateFunction");
#endif
    m_dFunctionValue = sqrt(m_mChildren[0]->calculateFunction( x) );
    return m_dFunctionValue;
}// end OSnLNodeSqrt::calculate


ADdouble OSnLNodeSqrt::constructADTape(std::map<int, int> *ADIdx, ADvector *XAD)
{
    m_ADTape = sqrt( m_mChildren[0]->constructADTape( ADIdx, XAD) );
    return m_ADTape;
}// end OSnLNodeSqrt::constructADTape

ExprNode* OSnLNodeSqrt::cloneExprNode()
{
    std::ostringstream outStr;
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, "cloning an OSnLNodeSqrt");
#endif
    ExprNode *nlNodePoint;
    nlNodePoint = new OSnLNodeSqrt();
#ifndef NDEBUG
    outStr << "Allocate memory at address " << nlNodePoint << std::endl;
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, outStr.str());
#endif
//    CLONE_CHILDREN;
        if (inumberOfChildren > 0)                              
        {                                                       
            if (nlNodePoint->m_mChildren == NULL)               
                nlNodePoint->m_mChildren                        
                    = new ExprNode*[inumberOfChildren];         
            for (unsigned int i=0; i < inumberOfChildren; i++)  
            {                                                   
                nlNodePoint->m_mChildren[i]                     
                    = this->m_mChildren[i]->cloneExprNode();    
            }                                                   
            nlNodePoint->inumberOfChildren = inumberOfChildren;
        }                                                       
    return  nlNodePoint;
}//end OSnLNodeSqrt::cloneExprNode


//
// OSnLNodeSquare Methods
OSnLNodeSquare::OSnLNodeSquare()
{
    inumberOfChildren = 1;
    m_mChildren = new ExprNode*[1];
    m_mChildren[ 0] = NULL;
    inodeInt = OS_SQUARE;
    inodeKind = 1;
}//end OSnLNodeSquare


OSnLNodeSquare::~OSnLNodeSquare()
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, "inside OSnLNodeSquare destructor");
#endif
}//end ~OSnLNodeSquare

std::string OSnLNodeSquare::getTokenName()
{
    return "square";
}// end OSnLNodeSquare::getTokenName(

double OSnLNodeSquare::calculateFunction(double *x)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSExpressionTree, 
                      ENUM_OUTPUT_LEVEL_trace, "in OSnLNodeSquare::calculateFunction");
#endif
    m_dFunctionValue = m_mChildren[0]->calculateFunction( x) * m_mChildren[0]->calculateFunction( x);
    return m_dFunctionValue;
}// end OSnLNodeSquare::calculate


ADdouble OSnLNodeSquare::constructADTape(std::map<int, int> *ADIdx, ADvector *XAD)
{
    m_ADTape = pow( m_mChildren[0]->constructADTape( ADIdx, XAD), int( 2) );
    return m_ADTape;
}// end OSnLNodeSquare::constructADTape

ExprNode* OSnLNodeSquare::cloneExprNode()
{
    std::ostringstream outStr;
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, "cloning an OSnLNodeSquare");
#endif
    ExprNode *nlNodePoint;
    nlNodePoint = new OSnLNodeSquare();
#ifndef NDEBUG
    outStr << "Allocate memory at address " << nlNodePoint << std::endl;
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, outStr.str());
#endif
//    CLONE_CHILDREN;
        if (inumberOfChildren > 0)                              
        {                                                       
            if (nlNodePoint->m_mChildren == NULL)               
                nlNodePoint->m_mChildren                        
                    = new ExprNode*[inumberOfChildren];         
            for (unsigned int i=0; i < inumberOfChildren; i++)  
            {                                                   
                nlNodePoint->m_mChildren[i]                     
                    = this->m_mChildren[i]->cloneExprNode();    
            }                                                   
            nlNodePoint->inumberOfChildren = inumberOfChildren;
        }                                                       
    return  nlNodePoint;
}//end OSnLNodeSquare::cloneExprNode


//
// OSnLNodeSin Methods
OSnLNodeSin::OSnLNodeSin()
{
    inumberOfChildren = 1;
    m_mChildren = new ExprNode*[1];
    m_mChildren[ 0] = NULL;
    inodeInt = OS_SIN;
    inodeKind = 1;
}//end OSnLNodeSin


OSnLNodeSin::~OSnLNodeSin()
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, "inside OSnLNodeSin destructor");
#endif
}//end ~OSnLNodeSin

std::string OSnLNodeSin::getTokenName()
{
    return "sin";
}// end OSnLNodeSin::getTokenName(

double OSnLNodeSin::calculateFunction(double *x)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSExpressionTree, 
                      ENUM_OUTPUT_LEVEL_trace, "in OSnLNodeSin::calculateFunction");
#endif
    m_dFunctionValue = sin(m_mChildren[0]->calculateFunction( x) );
    return m_dFunctionValue;
}// end OSnLNodeSin::calculate


ADdouble OSnLNodeSin::constructADTape(std::map<int, int> *ADIdx, ADvector *XAD)
{
    m_ADTape = sin( m_mChildren[0]->constructADTape( ADIdx, XAD) );
    return m_ADTape;
}// end OSnLNodeSin::constructADTape

ExprNode* OSnLNodeSin::cloneExprNode()
{
    std::ostringstream outStr;
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, "cloning an OSnLNodeSin");
#endif
    ExprNode *nlNodePoint;
    nlNodePoint = new OSnLNodeSin();
#ifndef NDEBUG
    outStr << "Allocate memory at address " << nlNodePoint << std::endl;
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, outStr.str());
#endif
//    CLONE_CHILDREN;
        if (inumberOfChildren > 0)                              
        {                                                       
            if (nlNodePoint->m_mChildren == NULL)               
                nlNodePoint->m_mChildren                        
                    = new ExprNode*[inumberOfChildren];         
            for (unsigned int i=0; i < inumberOfChildren; i++)  
            {                                                   
                nlNodePoint->m_mChildren[i]                     
                    = this->m_mChildren[i]->cloneExprNode();    
            }                                                   
            nlNodePoint->inumberOfChildren = inumberOfChildren;
        }                                                       
    return  nlNodePoint;
}//end OSnLNodeSin::cloneExprNode


//
// OSnLNodeCos Methods
OSnLNodeCos::OSnLNodeCos()
{
    inumberOfChildren = 1;
    m_mChildren = new ExprNode*[1];
    m_mChildren[ 0] = NULL;
    inodeInt = OS_COS;
    inodeKind = 1;
}//end OSnLNodeCos


OSnLNodeCos::~OSnLNodeCos()
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, "inside OSnLNodeCos destructor");
#endif
}//end ~OSnLNodeCos

std::string OSnLNodeCos::getTokenName()
{
    return "cos";
}// end OSnLNodeCos::getTokenName(

double OSnLNodeCos::calculateFunction(double *x)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSExpressionTree, 
                      ENUM_OUTPUT_LEVEL_trace, "in OSnLNodeCos::calculateFunction");
#endif
    m_dFunctionValue = cos(m_mChildren[0]->calculateFunction( x) );
    return m_dFunctionValue;
}// end OSnLNodeCos::calculate


ADdouble OSnLNodeCos::constructADTape(std::map<int, int> *ADIdx, ADvector *XAD)
{
    m_ADTape = cos( m_mChildren[0]->constructADTape( ADIdx, XAD) );
    return m_ADTape;
}// end OSnLNodeCos::constructADTape

ExprNode* OSnLNodeCos::cloneExprNode()
{
    std::ostringstream outStr;
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, "cloning an OSnLNodeCos");
#endif
    ExprNode *nlNodePoint;
    nlNodePoint = new OSnLNodeCos();
#ifndef NDEBUG
    outStr << "Allocate memory at address " << nlNodePoint << std::endl;
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, outStr.str());
#endif
//    CLONE_CHILDREN;
        if (inumberOfChildren > 0)                              
        {                                                       
            if (nlNodePoint->m_mChildren == NULL)               
                nlNodePoint->m_mChildren                        
                    = new ExprNode*[inumberOfChildren];         
            for (unsigned int i=0; i < inumberOfChildren; i++)  
            {                                                   
                nlNodePoint->m_mChildren[i]                     
                    = this->m_mChildren[i]->cloneExprNode();    
            }                                                   
            nlNodePoint->inumberOfChildren = inumberOfChildren;
        }                                                       
    return  nlNodePoint;
}//end OSnLNodeCos::cloneExprNode


//
// OSnLNodeExp Methods
OSnLNodeExp::OSnLNodeExp()
{
    inumberOfChildren = 1;
    m_mChildren = new ExprNode*[1];
    m_mChildren[ 0] = NULL;
    inodeInt = OS_EXP;
    inodeKind = 1;
}//end OSnLNodeExp


OSnLNodeExp::~OSnLNodeExp()
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, "inside OSnLNodeExp destructor");
#endif
}//end ~OSnLNodeExp

std::string OSnLNodeExp::getTokenName()
{
    return "exp";
}// end OSnLNodeExp::getTokenName(

double OSnLNodeExp::calculateFunction(double *x)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSExpressionTree, 
                      ENUM_OUTPUT_LEVEL_trace, "in OSnLNodeExp::calculateFunction");
#endif
    m_dFunctionValue = exp(m_mChildren[0]->calculateFunction( x) );
    return m_dFunctionValue;
}// end OSnLNodeExp::calculate


ADdouble OSnLNodeExp::constructADTape(std::map<int, int> *ADIdx, ADvector *XAD)
{
    m_ADTape = exp( m_mChildren[0]->constructADTape( ADIdx, XAD) );
    return m_ADTape;
}// end OSnLNodeExp::constructADTape

ExprNode* OSnLNodeExp::cloneExprNode()
{
    std::ostringstream outStr;
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, "cloning an OSnLNodeExp");
#endif
    ExprNode *nlNodePoint;
    nlNodePoint = new OSnLNodeExp();
#ifndef NDEBUG
    outStr << "Allocate memory at address " << nlNodePoint << std::endl;
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, outStr.str());
#endif
//    CLONE_CHILDREN;
        if (inumberOfChildren > 0)                              
        {                                                       
            if (nlNodePoint->m_mChildren == NULL)               
                nlNodePoint->m_mChildren                        
                    = new ExprNode*[inumberOfChildren];         
            for (unsigned int i=0; i < inumberOfChildren; i++)  
            {                                                   
                nlNodePoint->m_mChildren[i]                     
                    = this->m_mChildren[i]->cloneExprNode();    
            }                                                   
            nlNodePoint->inumberOfChildren = inumberOfChildren;
        }                                                       
    return  nlNodePoint;
}//end OSnLNodeExp::cloneExprNode


//
// OSnLNodeAbs Methods
OSnLNodeAbs::OSnLNodeAbs()
{
    inumberOfChildren = 1;
    m_mChildren = new ExprNode*[1];
    m_mChildren[ 0] = NULL;
    inodeInt = OS_ABS;
    inodeKind = 1;
}//end OSnLNodeLn


OSnLNodeAbs::~OSnLNodeAbs()
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, "inside OSnLNodeAbs destructor");
#endif
}//end ~OSnLNodeAbs

std::string OSnLNodeAbs::getTokenName()
{
    return "abs";
}// end OSnLNodeAbs::getTokenName(

double OSnLNodeAbs::calculateFunction(double *x)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSExpressionTree, 
                      ENUM_OUTPUT_LEVEL_trace, "in OSnLNodeAbs::calculateFunction");
#endif
    m_dFunctionValue = fabs(m_mChildren[0]->calculateFunction( x) );
    return m_dFunctionValue;
}// end OSnLNodeAbs::calculate


ADdouble OSnLNodeAbs::constructADTape(std::map<int, int> *ADIdx, ADvector *XAD)
{
    m_ADTape = abs( m_mChildren[0]->constructADTape( ADIdx, XAD) );
    return m_ADTape;
}// end OSnLNodeAbs::constructADTape

ExprNode* OSnLNodeAbs::cloneExprNode()
{
    std::ostringstream outStr;
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, "cloning an OSnLNodeAbs");
#endif
    ExprNode *nlNodePoint;
    nlNodePoint = new OSnLNodeAbs();
#ifndef NDEBUG
    outStr << "Allocate memory at address " << nlNodePoint << std::endl;
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, outStr.str());
#endif
//    CLONE_CHILDREN;
        if (inumberOfChildren > 0)                              
        {                                                       
            if (nlNodePoint->m_mChildren == NULL)               
                nlNodePoint->m_mChildren                        
                    = new ExprNode*[inumberOfChildren];         
            for (unsigned int i=0; i < inumberOfChildren; i++)  
            {                                                   
                nlNodePoint->m_mChildren[i]                     
                    = this->m_mChildren[i]->cloneExprNode();    
            }                                                   
            nlNodePoint->inumberOfChildren = inumberOfChildren;
        }                                                       
    return  nlNodePoint;
}//end OSnLNodeAbs::cloneExprNode
// end OSnLNodeAbs methods


//
// OSnLNodeErf Methods
OSnLNodeErf::OSnLNodeErf()
{
    inumberOfChildren = 1;
    m_mChildren = new ExprNode*[1];
    m_mChildren[ 0] = NULL;
    inodeInt = OS_ERF;
    inodeKind = 1;
}//end OSnLNodeErf


OSnLNodeErf::~OSnLNodeErf()
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, "inside OSnLNodeErf destructor");
#endif
}//end ~OSnLNodeErf

std::string OSnLNodeErf::getTokenName()
{
    return "erf";
}// end OSnLNodeErf::getTokenName(

double OSnLNodeErf::calculateFunction(double *x)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSExpressionTree, 
                      ENUM_OUTPUT_LEVEL_trace, "in OSnLNodeErf::calculateFunction");
#endif
    const double a = (993./880.);
    const double b =  (89./880.);
    m_dFunctionValue = tanh( (a + b * m_mChildren[0]->calculateFunction( x) * m_mChildren[0]->calculateFunction( x)) * m_mChildren[0]->calculateFunction( x) );
    return m_dFunctionValue;
}// end OSnLNodeErf::calculate


ADdouble OSnLNodeErf::constructADTape(std::map<int, int> *ADIdx, ADvector *XAD)
{
    /***
     * This is a fast approximation (few numerical operations)
     * with relative error bound $latex 4 \times 10^{-4}$$; see
     * Vedder, J.D., "Simple approximations for the error function and its inverse",
     * American Journal of Physics, v 55, n 8, 1987, p 762-3. I took this reference from
     * Brad Bell's erf.hpp
     *
     */
    const double a = (993./880.);
    const double b =  (89./880.);

    //tanh( (a + b * x * x) * x );
    //m_ADTape = CppAD::erf( m_mChildren[0]->constructADTape( ADIdx, XAD) );
    m_ADTape = tanh( (a + b * m_mChildren[0]->constructADTape( ADIdx, XAD) * m_mChildren[0]->constructADTape( ADIdx, XAD)) * m_mChildren[0]->constructADTape( ADIdx, XAD) );

    return m_ADTape;
}// end OSnLNodeErf::constructADTape

ExprNode* OSnLNodeErf::cloneExprNode()
{
    std::ostringstream outStr;
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, "cloning an OSnLNodeErf");
#endif
    ExprNode *nlNodePoint;
    nlNodePoint = new OSnLNodeErf();
#ifndef NDEBUG
    outStr << "Allocate memory at address " << nlNodePoint << std::endl;
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, outStr.str());
#endif
//    CLONE_CHILDREN;
        if (inumberOfChildren > 0)                              
        {                                                       
            if (nlNodePoint->m_mChildren == NULL)               
                nlNodePoint->m_mChildren                        
                    = new ExprNode*[inumberOfChildren];         
            for (unsigned int i=0; i < inumberOfChildren; i++)  
            {                                                   
                nlNodePoint->m_mChildren[i]                     
                    = this->m_mChildren[i]->cloneExprNode();    
            }                                                   
            nlNodePoint->inumberOfChildren = inumberOfChildren;
        }                                                       
    return  nlNodePoint;
}//end OSnLNodeErf::cloneExprNode
// end OSnLNodeErf methods


// OSnLNodeIf Methods
OSnLNodeIf::OSnLNodeIf()
{
    inumberOfChildren = 3;
    m_mChildren = new ExprNode*[3];
    m_mChildren[ 0] = NULL;
    m_mChildren[ 1] = NULL;
    m_mChildren[ 2] = NULL;
    inodeInt = OS_IF;
    inodeKind = 1;
}//end OSnLNodeIf


OSnLNodeIf::~OSnLNodeIf()
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, "inside OSnLNodeIf destructor");
#endif
}//end ~OSnLNodeIf

std::string OSnLNodeIf::getTokenName()
{
    return "if";
}// end OSnLNodeIf::getTokenName(

double OSnLNodeIf::calculateFunction(double *x)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSExpressionTree, 
                      ENUM_OUTPUT_LEVEL_trace, "in OSnLNodeIf::calculateFunction");
#endif
    if (m_mChildren[0]->calculateFunction( x) >= 0) 
        m_dFunctionValue = m_mChildren[ 1]->calculateFunction( x);
    else
        m_dFunctionValue = m_mChildren[ 2]->calculateFunction( x);
    return m_dFunctionValue;
}// end OSnLNodeIf::calculate

ADdouble OSnLNodeIf::constructADTape(std::map<int, int> *ADIdx, ADvector *XAD)
{
    //if not support in AD, throw an exception
    try
    {
        throw ErrorClass("if operator not supported by current Algorithmic Differentiation implementation");
        return m_ADTape;
    }
    catch(const ErrorClass& eclass)
    {
        throw ErrorClass( eclass.errormsg);
    }
}// end OSnLNodeIf::constructADTape

ExprNode* OSnLNodeIf::cloneExprNode()
{
    std::ostringstream outStr;
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, "cloning an OSnLNodeIf");
#endif
    ExprNode *nlNodePoint;
    nlNodePoint = new OSnLNodeIf();
#ifndef NDEBUG
    outStr << "Allocate memory at address " << nlNodePoint << std::endl;
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, outStr.str());
#endif
//    CLONE_CHILDREN;
        if (inumberOfChildren > 0)                              
        {                                                       
            if (nlNodePoint->m_mChildren == NULL)               
                nlNodePoint->m_mChildren                        
                    = new ExprNode*[inumberOfChildren];         
            for (unsigned int i=0; i < inumberOfChildren; i++)  
            {                                                   
                nlNodePoint->m_mChildren[i]                     
                    = this->m_mChildren[i]->cloneExprNode();    
            }                                                   
            nlNodePoint->inumberOfChildren = inumberOfChildren;
        }                                                       
    return  nlNodePoint;
}//end OSnLNodeIf::cloneExprNode
// end OSnLNodeIf methods


//
// OSnLNodeNumber Methods
OSnLNodeNumber::OSnLNodeNumber()
{
    inodeInt = OS_NUMBER;
    inumberOfChildren = 0;
    m_mChildren = NULL;
    inodeKind = 1;

    value = 0.0;
    type = "real";
    id = "";
}//end OSnLNodeNumber

OSnLNodeNumber::~OSnLNodeNumber()
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, "inside OSnLNodeNumber destructor");
#endif
}//end ~OSnLNodeNumber

std::string OSnLNodeNumber::getTokenName()
{
    return "number";
}//getTokenName

std::string OSnLNodeNumber::getTokenNumber()
{
    ostringstream outStr;
    outStr << inodeInt;
    outStr << "(number):" ;
    outStr << value ;
    if(type.length() > 0)
    {
        outStr << ":" ;
        outStr << type ;
    }

    if(id.length() > 0)
    {
        outStr << ":" ;
        outStr << id;
    }
    return outStr.str();
}//getTokenNumber

std::string OSnLNodeNumber::getNodeInfo(bool recurse, int indent)
{
    ostringstream outStr;
    for (int i=0; i < indent; i++)
        outStr << " ";
    outStr << "node address: " << this;
    outStr << " type: " << inodeInt << "(" << &inodeInt << ")" << " value = " << value << std::endl;
    return outStr.str();
}//getNodeInfo

std::string OSnLNodeNumber::getNonlinearExpressionInXML()
{
    ostringstream outStr;
    outStr << "<" ;
    outStr << this->getTokenName();
    outStr << " value=\"";
    outStr << os_dtoa_format(value);
    outStr << "\"";
    if (type != "real")
    { 
        outStr << " type=\"";
        outStr << type ;
        outStr << "\"";
    }
    if(id.length() > 0)
    {
        outStr << " id=\"";
        outStr << id ;
        outStr << "\"";
    }
    outStr << "/>";
    return outStr.str();
}//getNonlinearExpressionInXML()


double OSnLNodeNumber::calculateFunction(double *x)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSExpressionTree, 
                      ENUM_OUTPUT_LEVEL_trace, "in OSnLNodeNumber::calculateFunction");
#endif
    m_dFunctionValue = this->value;
    return m_dFunctionValue;
}// end OSnLNodeNumber::calculate

ADdouble OSnLNodeNumber::constructADTape(std::map<int, int> *ADIdx, ADvector *XAD)
{
    m_ADTape =  this->value;
    return m_ADTape;
}// end OSnLNodeNumber::constructADTape

ExprNode* OSnLNodeNumber::cloneExprNode()
{
    std::ostringstream outStr;
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, "cloning an OSnLNodeNumber");
#endif
    ExprNode *nlNodePoint;
    nlNodePoint = new OSnLNodeNumber();
#ifndef NDEBUG
    outStr << "Allocate memory at address " << nlNodePoint << std::endl;
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, outStr.str());
#endif
    ((OSnLNodeNumber*)nlNodePoint)->value = value;
    ((OSnLNodeNumber*)nlNodePoint)->type  = type;
    ((OSnLNodeNumber*)nlNodePoint)->id    = id;
//    CLONE_CHILDREN;
        if (inumberOfChildren > 0)                              
        {                                                       
            if (nlNodePoint->m_mChildren == NULL)               
                nlNodePoint->m_mChildren                        
                    = new ExprNode*[inumberOfChildren];         
            for (unsigned int i=0; i < inumberOfChildren; i++)  
            {                                                   
                nlNodePoint->m_mChildren[i]                     
                    = this->m_mChildren[i]->cloneExprNode();    
            }                                                   
            nlNodePoint->inumberOfChildren = inumberOfChildren;
        }                                                       
    return  nlNodePoint;
}//end OSnLNodeNumber::cloneExprNode


bool OSnLNodeNumber::IsEqual(OSnLNodeNumber *that)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, "Start comparing in OSnLNodeNumber");
#endif
    if (this == NULL)
    {
        if (that == NULL)
            return true;
        else
        {
#ifndef NDEBUG
            osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, 
                "First object is NULL, second is not");
#endif
            return false;
        }
    }
    else
    {
        if (that == NULL)
        {
#ifndef NDEBUG
            osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, 
                "Second object is NULL, first is not");
#endif
            return false;
        }
        else
        {
            if (this->inodeInt != that->inodeInt)
                return false;
            if (this->inodeKind != that->inodeKind)
                return false;
            if (this->inumberOfChildren != that->inumberOfChildren)
                return false;

            for (unsigned int i = 0; i < this->inumberOfChildren; i++)
                if (!this->m_mChildren[i]->IsEqual(that->m_mChildren[i]))
                    return false;

            if (this->value != that->value)
                return false;
            if (this->type != that->type)
                return false;
            if (this->id != that->id)
                return false;
            return true;
        }
    }
}//OSnLNodeNumber::IsEqual
// end OSnLNodeNumber methods


// OSnLNodeE Methods
OSnLNodeE::OSnLNodeE()
{
    inodeInt = OS_E;
    inumberOfChildren = 0;
    m_mChildren = NULL;
    inodeKind = 1;
    //value = 0.0;
    //type = "real";
    //id = "";
}//end OSnLNodeE

OSnLNodeE::~OSnLNodeE()
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, "inside OSnLNodeE destructor");
#endif
}//end ~OSnLNodeE


std::string OSnLNodeE::getTokenName()
{
    ostringstream outStr;
    outStr << "E";
    return outStr.str();
}//getTokenName

std::string OSnLNodeE::getTokenNumber()
{
    ostringstream outStr;
    outStr << inodeInt;
    return outStr.str();
}//getTokenNumber

std::string OSnLNodeE::getNonlinearExpressionInXML()
{
    ostringstream outStr;
    outStr << "<" ;
    outStr << "E";
    outStr << "/>";
    return outStr.str();
}//getNonlinearExpressionInXML()


double OSnLNodeE::calculateFunction(double *x)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSExpressionTree, 
                      ENUM_OUTPUT_LEVEL_trace, "in OSnLNodeE::calculateFunction");
#endif
    m_dFunctionValue = OS_E_VALUE;
    return m_dFunctionValue;
}// end OSnLNodeE::calculate

ADdouble OSnLNodeE::constructADTape(std::map<int, int> *ADIdx, ADvector *XAD)
{
    m_ADTape =  OS_E_VALUE;
    return m_ADTape;
}// end OSnLE::constructADTape

ExprNode* OSnLNodeE::cloneExprNode()
{
    std::ostringstream outStr;
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, "cloning an OSnLNodeE");
#endif
    ExprNode *nlNodePoint;
    nlNodePoint = new OSnLNodeE();
#ifndef NDEBUG
    outStr << "Allocate memory at address " << nlNodePoint << std::endl;
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, outStr.str());
#endif
    return  nlNodePoint;
}//end OSnLNodeE::cloneExprNode
//end OSnLNodeE


// OSnLNodePI Methods
OSnLNodePI::OSnLNodePI()
{
    inodeInt = OS_PI;
    inumberOfChildren = 0;
    m_mChildren = NULL;
    inodeKind = 1;
}//end OSnLNodePI


OSnLNodePI::~OSnLNodePI()
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, "inside OSnLNodePI destructor");
#endif
}//end ~OSnLNodePI


std::string OSnLNodePI::getTokenName()
{
    ostringstream outStr;
    outStr << "PI";
    return outStr.str();
}//getTokenName


std::string OSnLNodePI::getTokenNumber()
{
    ostringstream outStr;
    outStr << inodeInt;
    return outStr.str();
}//getTokenNumber


std::string OSnLNodePI::getNonlinearExpressionInXML()
{
    ostringstream outStr;
    outStr << "<" ;
    outStr << "PI";
    outStr << "/>";
    return outStr.str();
}//getNonlinearExpressionInXML()


double OSnLNodePI::calculateFunction(double *x)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSExpressionTree, 
                      ENUM_OUTPUT_LEVEL_trace, "in OSnLNodePI::calculateFunction");
#endif
    m_dFunctionValue = OS_PI_VALUE;
    return m_dFunctionValue;
}// end OSnLNodePI::calculate

ADdouble OSnLNodePI::constructADTape(std::map<int, int> *ADIdx, ADvector *XAD)
{
    m_ADTape =  OS_PI_VALUE;
    return m_ADTape;
}// end OSnLE::constructADTape

ExprNode* OSnLNodePI::cloneExprNode()
{
    std::ostringstream outStr;
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, "cloning an OSnLNodePI");
#endif
    ExprNode *nlNodePoint;
    nlNodePoint = new OSnLNodePI();
#ifndef NDEBUG
    outStr << "Allocate memory at address " << nlNodePoint << std::endl;
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, outStr.str());
#endif
    return  nlNodePoint;
}//end OSnLNodePI::cloneExprNode
//end OSnLNodePI methods


// OSnLNodeVariable Methods
OSnLNodeVariable::OSnLNodeVariable()
{
    inumberOfChildren = 0;
    m_mChildren = NULL;
    inodeInt = OS_VARIABLE;
    inodeKind = 1;

    coef = 1.0;
    idx = -1;
}//end OSnLNodeVariable

OSnLNodeVariable::~OSnLNodeVariable()
{
    std::ostringstream outStr;
#ifndef NDEBUG
    outStr << "inside OSnLNodeVariable destructor" << endl;
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, outStr.str());
#endif
}//end ~OSnLNodeVariable


std::string OSnLNodeVariable::getTokenName()
{
    ostringstream outStr;
    outStr << "variable";
    outStr << "[";
    outStr << inumberOfChildren ;
    outStr << "]";
    outStr << ":" ;
    outStr << idx;
    outStr << ":" ;
    outStr << coef;
    outStr << ":real:" ;
    return outStr.str();
}//getTokenName


std::string OSnLNodeVariable::getTokenNumber()
{
    ostringstream outStr;
    outStr << inodeInt;
    outStr << "[";
    outStr << inumberOfChildren ;
    outStr << "]";
    outStr << ":" ;
    outStr << idx;
    outStr << ":" ;
    outStr << coef;
    outStr << ":real:" ;
    return outStr.str();
}//getTokenNumber


std::string OSnLNodeVariable::getNodeInfo(bool recurse, int indent)
{
    ostringstream outStr;
    for (int i=0; i < indent; i++)
        outStr << " ";
    outStr << "node address: " << this;
    outStr << " type: " << inodeInt << "(" << &inodeInt << ")" << " varRef = " << idx;
    if (coef > 1 || coef < 1)
        outStr << " coef = " << coef;
    outStr << std::endl;
    return outStr.str();
}//getNodeInfo

std::string OSnLNodeVariable::getNonlinearExpressionInXML()
{
    ostringstream outStr;
    outStr << "<";
    outStr << "variable";
    outStr << " idx=\"";
    outStr << idx;
    outStr << "\"";
    if (coef < 1 || coef > 1)
    {
        outStr << " coef=\"";
        outStr << os_dtoa_format(coef);
        outStr << "\"";
    }
    if (inumberOfChildren > 0)
    {
        outStr << ">";
        for(unsigned int i = 0; i < inumberOfChildren; i++)
        {
            outStr << m_mChildren[i]->getNonlinearExpressionInXML();
        }
        outStr << "</variable>";
    }
    else
    {
        outStr << "/>";
    }
    return outStr.str();
}//getNonlinearExpressionInXML

double OSnLNodeVariable::calculateFunction(double *x)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSExpressionTree, 
                      ENUM_OUTPUT_LEVEL_trace, "in OSnLNodeVariable::calculateFunction");
#endif
    m_dFunctionValue = coef*x[idx];
    return m_dFunctionValue;
}// end OSnLNodeVariable::calculate

ADdouble OSnLNodeVariable::constructADTape(std::map<int, int> *varIdx, ADvector *XAD)
{
    m_ADTape = coef*(*XAD)[ (*varIdx)[ idx] ];
    return m_ADTape;
}// end OSnLNodeVariable::constructADTape


void OSnLNodeVariable::getVariableIndexMap(std::map<int, int> *varIdx)
{
    if( (*varIdx).find( idx) == (*varIdx).end() )  // variable to map with variable index as the key
    {
        //just put a placeholder for now to record the key.
        // The value will be added once we know the location within the sparse Jacobian
        (*varIdx)[ idx] = 1;
#ifndef NDEBUG
        ostringstream outStr;
        outStr << "add variable " << idx << " to the map" << std::endl;
        osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_detailed_trace, outStr.str());
#endif
    }
}//getVariableIndexMap

ExprNode* OSnLNodeVariable::cloneExprNode()
{
    std::ostringstream outStr;
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, "cloning an OSnLNodeVariable");
#endif
    ExprNode *nlNodePoint;
    nlNodePoint = new OSnLNodeVariable();
#ifndef NDEBUG
    outStr.str( std::string() );
    outStr.clear();
//!!    outStr << "Allocate memory at address " << nlNodePoint << std::endl;
    outStr << "Allocate memory at address ";
    outStr << nlNodePoint;
    outStr << std::endl;
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, outStr.str());
#endif
    ((OSnLNodeVariable*)nlNodePoint)->idx  = idx;
    ((OSnLNodeVariable*)nlNodePoint)->coef = coef;
//    CLONE_CHILDREN;
        if (inumberOfChildren > 0)                              
        {                                                       
            if (nlNodePoint->m_mChildren == NULL)               
                nlNodePoint->m_mChildren                        
                    = new ExprNode*[inumberOfChildren];         
            for (unsigned int i=0; i < inumberOfChildren; i++)  
            {                                                   
                nlNodePoint->m_mChildren[i]                     
                    = this->m_mChildren[i]->cloneExprNode();    
            }                                                   
            nlNodePoint->inumberOfChildren = inumberOfChildren;
        }                                                       
    return  nlNodePoint;
}//end OSnLNodeVariable::cloneExprNode


bool OSnLNodeVariable::IsEqual(OSnLNodeVariable *that)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, "Start comparing in OSnLNodeVariable");
#endif
    if (this == NULL)
    {
        if (that == NULL)
            return true;
        else
        {
#ifndef NDEBUG
            osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, 
                "First object is NULL, second is not");
#endif
            return false;
        }
    }
    else
    {
        if (that == NULL)
        {
#ifndef NDEBUG
            osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, 
                "Second object is NULL, first is not");
#endif
            return false;
        }
        else
        {
            if (this->inodeInt != that->inodeInt)
                return false;
            if (this->inodeKind != that->inodeKind)
                return false;
            if (this->inumberOfChildren != that->inumberOfChildren)
                return false;

            for (unsigned int i = 0; i < this->inumberOfChildren; i++)
                if (!this->m_mChildren[i]->IsEqual(that->m_mChildren[i]))
                    return false;

            if (this->coef != that->coef)
                return false;
            if (this->idx != that->idx)
                return false;
            return true;
        }
    }
}//OSnLNodeVariable::IsEqual



/** OSnLNode objects with matrix arguments **/

//
// OSnLNodeMatrixDeterminant Methods
OSnLNodeMatrixDeterminant::OSnLNodeMatrixDeterminant()
{
    inumberOfChildren = 1;
    m_mChildren = new ExprNode*[1];
    m_mChildren[0] = NULL;
    inodeInt = OS_MATRIX_DETERMINANT;
    inodeKind = 1;
}//end OSnLNodeMatrixDeterminant

OSnLNodeMatrixDeterminant::~OSnLNodeMatrixDeterminant()
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, 
                      ENUM_OUTPUT_LEVEL_trace, "inside OSnLNodeMatrixDeterminant destructor");
#endif
}//end ~OSnLNodeMatrixDeterminant


double OSnLNodeMatrixDeterminant::calculateFunction(double *x)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSExpressionTree, 
                      ENUM_OUTPUT_LEVEL_trace, "in OSnLNodeMatrixDeterminant::calculateFunction");
#endif
    return OSNaN();
}// end OSnLNodeMatrixDeterminant::calculate

std::string OSnLNodeMatrixDeterminant::getTokenName()
{
    return "matrixDeterminant";
}// end OSnLNodeMatrixDeterminant::getTokenName(


ADdouble OSnLNodeMatrixDeterminant::constructADTape(std::map<int, int> *ADIdx, ADvector *XAD)
{
    //if not support in AD, throw an exception
    try
    {
        throw ErrorClass("Matrix determinant operator not supported by current Algorithmic Differentiation implementation");
        return m_ADTape;
    }
    catch(const ErrorClass& eclass)
    {
        throw ErrorClass( eclass.errormsg);
    }
}// end OSnLNodeMatrixDeterminant::constructADTape


ExprNode* OSnLNodeMatrixDeterminant::cloneExprNode()
{
    std::ostringstream outStr;
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, 
                      "cloning an OSnLNodeMatrixDeterminant");
#endif
    ExprNode *nlNodePoint;
    nlNodePoint = new OSnLNodeMatrixDeterminant();
#ifndef NDEBUG
    outStr.str( std::string() );
    outStr.clear();
    outStr << "Allocate memory at address " << nlNodePoint << std::endl;
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, outStr.str());
#endif
//    CLONE_CHILDREN;
        if (inumberOfChildren > 0)                              
        {                                                       
            if (nlNodePoint->m_mChildren == NULL)               
                nlNodePoint->m_mChildren                        
                    = new ExprNode*[inumberOfChildren];         
            for (unsigned int i=0; i < inumberOfChildren; i++)  
            {                                                   
                nlNodePoint->m_mChildren[i]                     
                    = this->m_mChildren[i]->cloneExprNode();    
            }                                                   
            nlNodePoint->inumberOfChildren = inumberOfChildren;
        }                                                       
    return nlNodePoint;
}//end OSnLNodeMatrixDeterminant::cloneExprNode


// OSnLNodeMatrixTrace Methods
OSnLNodeMatrixTrace::OSnLNodeMatrixTrace()
{
    inumberOfChildren = 1;
    m_mChildren = new ExprNode*[1];
    m_mChildren[0] = NULL;
    inodeInt = OS_MATRIX_TRACE;
    inodeKind = 1;
}//end OSnLNodeMatrixTrace

OSnLNodeMatrixTrace::~OSnLNodeMatrixTrace()
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, "inside OSnLNodeMatrixTrace destructor");
#endif
}//end ~OSnLNodeMatrixTrace

double OSnLNodeMatrixTrace::calculateFunction(double *x)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSExpressionTree, 
                      ENUM_OUTPUT_LEVEL_trace, "in OSnLNodeMatrixTrace::calculateFunction");
#endif
    return 0.0;
}// end OSnLNodeMatrixTrace::calculate

std::string OSnLNodeMatrixTrace::getTokenName()
{
    return "matrixTrace";
}// end OSnLNodeMatrixTrace::getTokenName(


ADdouble OSnLNodeMatrixTrace::constructADTape(std::map<int, int> *ADIdx, ADvector *XAD)
{
    //if not support in AD, throw an exception
    try
    {
        throw ErrorClass("Matrix trace operator not supported by current Algorithmic Differentiation implementation");
        return m_ADTape;
    }
    catch(const ErrorClass& eclass)
    {
        throw ErrorClass( eclass.errormsg);
    }
}// end OSnLNodeMatrixTrace::constructADTape


ExprNode* OSnLNodeMatrixTrace::cloneExprNode()
{
    std::ostringstream outStr;
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace,
                      "cloning an OSnLNodeMatrixTrace");
#endif 
    ExprNode *nlNodePoint;
    nlNodePoint = new OSnLNodeMatrixTrace();
#ifndef NDEBUG
    outStr.str( std::string() );
    outStr.clear();
    outStr << "Allocate memory at address " << nlNodePoint << std::endl;
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, outStr.str());
#endif
//    CLONE_CHILDREN;
        if (inumberOfChildren > 0)                              
        {                                                       
            if (nlNodePoint->m_mChildren == NULL)               
                nlNodePoint->m_mChildren                        
                    = new ExprNode*[inumberOfChildren];         
            for (unsigned int i=0; i < inumberOfChildren; i++)  
            {                                                   
                nlNodePoint->m_mChildren[i]                     
                    = this->m_mChildren[i]->cloneExprNode();    
            }                                                   
            nlNodePoint->inumberOfChildren = inumberOfChildren;
        }                                                       
    return nlNodePoint;
}//end OSnLNodeMatrixTrace::cloneExprNode


//
// OSnLNodeMatrixToScalar Methods
OSnLNodeMatrixToScalar::OSnLNodeMatrixToScalar()
{
    inumberOfChildren = 1;
    m_mChildren = new ExprNode*[1];
    m_mChildren[0] = NULL;
    inodeInt = OS_MATRIX_TO_SCALAR;
    inodeKind = 1;
}//end OSnLNodeMatrixToScalar

OSnLNodeMatrixToScalar::~OSnLNodeMatrixToScalar()
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, "inside OSnLNodeMatrixToScalar destructor");
#endif
}//end ~OSnLNodeMatrixToScalar

double OSnLNodeMatrixToScalar::calculateFunction(double *x)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSExpressionTree, 
                      ENUM_OUTPUT_LEVEL_trace, "in OSnLNodeMatrixToScalar::calculateFunction");
#endif
    m_dFunctionValue = -OSDBL_MAX;

//    for(unsigned int i = 0; i < inumberOfChildren; i++)
//    {
//        if(m_mChildren[i]->calculateFunction(x) > m_dFunctionValue)
//        {
//            m_dFunctionValue =     m_mChildren[i]->calculateFunction(x);
//        }
//    }
    return m_dFunctionValue;
}// end OSnLNodeMatrixToScalar::calculate

std::string OSnLNodeMatrixToScalar::getTokenName()
{
    return "matrixToScalar";
}// end OSnLNodeMatrixToScalar::getTokenName(


ADdouble OSnLNodeMatrixToScalar::constructADTape(std::map<int, int> *ADIdx, ADvector *XAD)
{
    //if not support in AD, throw an exception
    try
    {
        throw ErrorClass("Matrix-to-scalar conversion not supported by current Algorithmic Differentiation implementation");
        return m_ADTape;
    }
    catch(const ErrorClass& eclass)
    {
        throw ErrorClass( eclass.errormsg);
    }
}// end OSnLNodeMatrixToScalar::constructADTape


ExprNode* OSnLNodeMatrixToScalar::cloneExprNode()
{
    std::ostringstream outStr;
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace,
                      "cloning an OSnLNodeMatrixToScalar");
#endif
    ExprNode *nlNodePoint;
    nlNodePoint = new OSnLNodeMatrixToScalar();
#ifndef NDEBUG
    outStr.str( std::string() );
    outStr.clear();
    outStr << "Allocate memory at address " << nlNodePoint << std::endl;
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, outStr.str());
#endif
//    CLONE_CHILDREN;
        if (inumberOfChildren > 0)                              
        {                                                       
            if (nlNodePoint->m_mChildren == NULL)               
                nlNodePoint->m_mChildren                        
                    = new ExprNode*[inumberOfChildren];         
            for (unsigned int i=0; i < inumberOfChildren; i++)  
            {                                                   
                nlNodePoint->m_mChildren[i]                     
                    = this->m_mChildren[i]->cloneExprNode();    
            }                                                   
            nlNodePoint->inumberOfChildren = inumberOfChildren;
        }                                                       
    return nlNodePoint;
}//end OSnLNodeMatrixToScalar::cloneExprNode


/***********************************************************
 *    Implementation of OSnLMNode and inheriting classes   * 
 ***********************************************************/
OSnLMNode::OSnLMNode():
    ExprNode()
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, "inside OSnLMNode constructor");
#endif
}//end OSnLMNode

OSnLMNode::~OSnLMNode()
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, "inside OSnLMNode destructor");
#endif
}//end ~OSnLNode


OSnLMNode* OSnLMNode::createExpressionTreeFromPrefix(std::vector<ExprNode*> nlNodeVec)
{
    std::vector<ExprNode*> stackVec;
    int kount =  nlNodeVec.size() - 1;
    while(kount >= 0)
    {
        int numkids = nlNodeVec[kount]->inumberOfChildren;
        if(numkids > 0)
        {
            for(int i = 0; i < numkids;  i++)
            {
                nlNodeVec[kount]->m_mChildren[i] = stackVec.back();
                stackVec.pop_back();
            }
        }
        stackVec.push_back( nlNodeVec[kount]);
        kount--;
    }
    stackVec.clear();
    return (OSnLMNode*)nlNodeVec[ 0];
}//end createExpressionTreeFromPrefix

OSnLMNode* OSnLMNode::createExpressionTreeFromPostfix(std::vector<ExprNode*> nlNodeVec)
{
    std::vector<ExprNode*> stackVec;
    int kount = 0;

    while(kount <= nlNodeVec.size() - 1)
    {
        int numkids = nlNodeVec[kount]->inumberOfChildren;
        if (numkids  > 0)
        {
            for(int i = numkids - 1; i >= 0;  i--)
            {
                nlNodeVec[kount]->m_mChildren[i] = (OSnLNode*)stackVec.back();
                stackVec.pop_back();
            }
        }

        stackVec.push_back( nlNodeVec[kount]);
        kount++;
    }
    stackVec.clear();
    return (OSnLMNode*)nlNodeVec[ kount - 1];
}//end createExpressionTreeFromPostfix

#if 0
std::vector<ExprNode*> OSnLMNode::getPrefixFromExpressionTree()
{
    std::vector<ExprNode*> prefixVector;
    return preOrderOSnLNodeTraversal( &prefixVector);
}//getPrefixFromExpressionTree

std::vector<ExprNode*> OSnLMNode::preOrderOSnLNodeTraversal( std::vector<ExprNode*> *prefixVector)
{
    (*prefixVector).push_back( (OSnLMNode*)this);
    if(inumberOfChildren > 0)
    {
        for(unsigned int i = 0; i < inumberOfChildren; i++)
            m_mChildren[i]->preOrderOSnLNodeTraversal( prefixVector);
    }
    return *prefixVector;
}//end preOrderOSnLNodeTraversal

std::vector<ExprNode*> OSnLMNode::getPostfixFromExpressionTree( )
{
    std::vector<ExprNode*> postfixVector;
std::cout << "get postfix from an OSnLMNode" << std::endl;
    return postOrderOSnLNodeTraversal( &postfixVector);
}//getPostfixFromExpressionTree


std::vector<ExprNode*> OSnLMNode::postOrderOSnLNodeTraversal( std::vector<ExprNode*> *postfixVector)
{
    if(inumberOfChildren > 0)
    {
        unsigned int i;
        for(i = 0; i < inumberOfChildren; i++)
            m_mChildren[i]->postOrderOSnLNodeTraversal( postfixVector);
    }
    (*postfixVector).push_back( (OSnLMNode*)this);
    return *postfixVector;
}//end postOrderOSnLNodeTraversal()
#endif

bool OSnLMNode::IsEqual(OSnLMNode *that)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, "Start comparing in OSnLMNode");
#endif
    if (this == NULL)
    {
        if (that == NULL)
            return true;
        else
        {
#ifndef NDEBUG
            osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, 
                "First object is NULL, second is not");
#endif
            return false;
        }
    }
    else
    {
        if (that == NULL)
        {
#ifndef NDEBUG
            osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, 
                "Second object is NULL, first is not");
#endif
            return false;
        }
        else
        {
            if (this->inumberOfChildren != that->inumberOfChildren)
                return false;
            if (this->inodeInt != that->inodeInt)
                return false;
            if (this->inodeKind != that->inodeKind)
                return false;

            for (unsigned int i = 0; i < this->inumberOfChildren; i++)
                if (!this->m_mChildren[i]->IsEqual(that->m_mChildren[i]))
                    return false;

            return true;
        }
    }
}//OSnLMNode::IsEqual


// OSnLMNodeMatrixPlus Methods
OSnLMNodeMatrixPlus::OSnLMNodeMatrixPlus()
{
    inumberOfChildren = 2;
    m_mChildren = new ExprNode*[2];
    m_mChildren[0] = NULL;
    m_mChildren[1] = NULL;
    inodeInt = OS_MATRIX_PLUS;
    inodeKind = 3;
}//end OSnLMNodeMatrixPlus

OSnLMNodeMatrixPlus::~OSnLMNodeMatrixPlus()
{
    std::ostringstream outStr;
#ifndef NDEBUG
    outStr << "inside OSnLMNodeMatrixPlus destructor" << endl;
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, outStr.str());
#endif
}//end ~OSnLMNodeMatrixPlus

std::string OSnLMNodeMatrixPlus::getTokenName()
{
    return "matrixPlus";
}// end OSnLMNodeMatrixPlus::getTokenName()

GeneralSparseMatrix*  OSnLMNodeMatrixPlus::expandNode(OSMatrix** mtxLoc, bool rowMajor_, 
                                                      ENUM_MATRIX_TYPE convertTo_, 
                                                      ENUM_MATRIX_SYMMETRY symmetry_)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace,
                      "expanding an OSnLMNodeMatrixPlus");
#endif
    throw ErrorClass("OSnLMNodeMatrixPlus: expandNode method not yet implemented");
    return NULL;
}//end OSnLMNodeMatrixPlus::expandNode()


ExprNode* OSnLMNodeMatrixPlus::cloneExprNode()
{
    std::ostringstream outStr;
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace,
                      "cloning an OSnLMNodeMatrixPlus");
#endif
    ExprNode *nlNodePoint;
    nlNodePoint = new OSnLMNodeMatrixPlus();
#ifndef NDEBUG
    outStr.str( std::string() );
    outStr.clear();
    outStr << "Allocate memory at address " << nlNodePoint << std::endl;
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, outStr.str());
#endif
//    CLONE_CHILDREN;
        if (inumberOfChildren > 0)                              
        {                                                       
            if (nlNodePoint->m_mChildren == NULL)               
                nlNodePoint->m_mChildren                        
                    = new ExprNode*[inumberOfChildren];         
            for (unsigned int i=0; i < inumberOfChildren; i++)  
            {                                                   
                nlNodePoint->m_mChildren[i]                     
                    = this->m_mChildren[i]->cloneExprNode();    
            }                                                   
            nlNodePoint->inumberOfChildren = inumberOfChildren;
        }                                                       
    return nlNodePoint;
}//end OSnLMNodeMatrixPlus::cloneExprNode


// OSnLMNodeMatrixSum Methods
OSnLMNodeMatrixSum::OSnLMNodeMatrixSum()
{
    inumberOfChildren = 0;
    m_mChildren = NULL;
    inodeInt = OS_MATRIX_SUM;
    inodeKind = 3;
}//end OSnLMNodeMatrixSum

OSnLMNodeMatrixSum::~OSnLMNodeMatrixSum()
{
    std::ostringstream outStr;
#ifndef NDEBUG
    outStr << "inside OSnLMNodeMatrixSum destructor" << endl;
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, outStr.str());
#endif
}//end ~OSnLMNodeMatrixSum

std::string OSnLMNodeMatrixSum::getTokenName()
{
    return "matrixSum";
}// end OSnLMNodeMatrixSum::getTokenName()

GeneralSparseMatrix* OSnLMNodeMatrixSum::expandNode(OSMatrix** mtxLoc, bool rowMajor_, 
                                                    ENUM_MATRIX_TYPE convertTo_, 
                                                    ENUM_MATRIX_SYMMETRY symmetry_)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace,
                      "expanding an OSnLMNodeMatrixSum");
#endif
    throw ErrorClass("OSnLMNodeMatrixSum: expandNode method not yet implemented");
    return NULL;
}//end OSnLMNodeMatrixSum::expandNode()

ExprNode* OSnLMNodeMatrixSum::cloneExprNode()
{
    std::ostringstream outStr;
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, "cloning an OSnLMNodeMatrixSum");
#endif
    ExprNode *nlNodePoint;
    nlNodePoint = new OSnLMNodeMatrixSum();
#ifndef NDEBUG
    outStr.str( std::string() );
    outStr.clear();
    outStr << "Allocate memory at address " << nlNodePoint << std::endl;
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, outStr.str());
#endif
//    CLONE_CHILDREN;
        if (inumberOfChildren > 0)                              
        {                                                       
            if (nlNodePoint->m_mChildren == NULL)               
                nlNodePoint->m_mChildren                        
                    = new ExprNode*[inumberOfChildren];         
            for (unsigned int i=0; i < inumberOfChildren; i++)  
            {                                                   
                nlNodePoint->m_mChildren[i]                     
                    = this->m_mChildren[i]->cloneExprNode();    
            }                                                   
            nlNodePoint->inumberOfChildren = inumberOfChildren;
        }                                                       
    return  nlNodePoint;
}//end OSnLMNodeMatrixSum::cloneExprNode

//
// OSnLMNodeMatrixProduct Methods
OSnLMNodeMatrixProduct::OSnLMNodeMatrixProduct()
{
    inumberOfChildren = 0;
    m_mChildren = NULL;
    inodeInt = OS_MATRIX_PRODUCT;
    inodeKind = 3;
}//end OSnLMNodeMatrixProduct


OSnLMNodeMatrixProduct::~OSnLMNodeMatrixProduct()
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, "inside OSnLMNodeMatrixProduct destructor");
#endif
}//end ~OSnLMNodeMatrixProduct

std::string OSnLMNodeMatrixProduct::getTokenName()
{
    return "matrixProduct";
}// end OSnLMNodeMatrixProduct::getTokenName(

GeneralSparseMatrix* OSnLMNodeMatrixProduct::expandNode(OSMatrix** mtxLoc, bool rowMajor_, 
                                                        ENUM_MATRIX_TYPE convertTo_, 
                                                        ENUM_MATRIX_SYMMETRY symmetry_)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace,
                      "expanding an OSnLMNodeMatrixProduct");
#endif
    throw ErrorClass("OSnLMNodeMatrixPruduct: expandNode method not yet implemented");
    return NULL;
}//end OSnLMNodeMatrixProduct::expandNode()

ExprNode* OSnLMNodeMatrixProduct::cloneExprNode()
{
    std::ostringstream outStr;
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, "cloning an OSnLMNodeMatrixProduct");
#endif
    ExprNode *nlNodePoint;
    nlNodePoint = new OSnLMNodeMatrixProduct();
#ifndef NDEBUG
    outStr.str( std::string() );
    outStr.clear();
    outStr << "Allocate memory at address " << nlNodePoint << std::endl;
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, outStr.str());
#endif
//    CLONE_CHILDREN;
        if (inumberOfChildren > 0)                              
        {                                                       
            if (nlNodePoint->m_mChildren == NULL)               
                nlNodePoint->m_mChildren                        
                    = new ExprNode*[inumberOfChildren];         
            for (unsigned int i=0; i < inumberOfChildren; i++)  
            {                                                   
                nlNodePoint->m_mChildren[i]                     
                    = this->m_mChildren[i]->cloneExprNode();    
            }                                                   
            nlNodePoint->inumberOfChildren = inumberOfChildren;
        }                                                       
    return  nlNodePoint;
}//end OSnLMNodeMatrixProduct::cloneExprNode


// OSnLMNodeMatrixMinus Methods
OSnLMNodeMatrixMinus::OSnLMNodeMatrixMinus()
{
    inumberOfChildren = 2;
    m_mChildren = new ExprNode*[2];
    m_mChildren[0] = NULL;
    m_mChildren[1] = NULL;
    inodeInt = OS_MATRIX_MINUS;
    inodeKind = 3;
}//end OSnLMNodeMatrixMinus

OSnLMNodeMatrixMinus::~OSnLMNodeMatrixMinus()
{
    std::ostringstream outStr;
#ifndef NDEBUG
    outStr << "inside OSnLMNodeMatrixMinus destructor" << endl;
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, outStr.str());
#endif
}//end ~OSnLMNodeMatrixMinus

std::string OSnLMNodeMatrixMinus::getTokenName()
{
    return "matrixMinus";
}// end OSnLMNodeMatrixMinus::getTokenName()

GeneralSparseMatrix* OSnLMNodeMatrixMinus::expandNode(OSMatrix** mtxLoc, bool rowMajor_, 
                                                      ENUM_MATRIX_TYPE convertTo_, 
                                                      ENUM_MATRIX_SYMMETRY symmetry_)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace,
                      "expanding an OSnLMNodeMatrixMinus");
#endif
    throw ErrorClass("OSnLMNodeMatrixMinus: expandNode method not yet implemented");
    return NULL;
}//end OSnLMNodeMatrixMinus::expandNode()

ExprNode* OSnLMNodeMatrixMinus::cloneExprNode()
{
    std::ostringstream outStr;
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, "cloning an OSnLMNodeMatrixMinus");
#endif
    ExprNode *nlNodePoint;
    nlNodePoint = new OSnLMNodeMatrixMinus();
#ifndef NDEBUG
    outStr.str( std::string() );
    outStr.clear();
    outStr << "Allocate memory at address " << nlNodePoint << std::endl;
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, outStr.str());
#endif
//    CLONE_CHILDREN;
        if (inumberOfChildren > 0)                              
        {                                                       
            if (nlNodePoint->m_mChildren == NULL)               
                nlNodePoint->m_mChildren                        
                    = new ExprNode*[inumberOfChildren];         
            for (unsigned int i=0; i < inumberOfChildren; i++)  
            {                                                   
                nlNodePoint->m_mChildren[i]                     
                    = this->m_mChildren[i]->cloneExprNode();    
            }                                                   
            nlNodePoint->inumberOfChildren = inumberOfChildren;
        }                                                       
    return nlNodePoint;
}//end OSnLMNodeMatrixMinus::cloneExprNode

// OSnLMNodeMatrixNegate Methods
OSnLMNodeMatrixNegate::OSnLMNodeMatrixNegate()
{
    inumberOfChildren = 1;
    m_mChildren = new ExprNode*[1];
    m_mChildren[0] = NULL;
    inodeInt = OS_MATRIX_NEGATE;
    inodeKind = 3;
}//end OSnLMNodeMatrixNegate

OSnLMNodeMatrixNegate::~OSnLMNodeMatrixNegate()
{
    std::ostringstream outStr;
#ifndef NDEBUG
    outStr << "inside OSnLMNodeMatrixNegate destructor" << endl;
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, outStr.str());
#endif
}//end ~OSnLMNodeMatrixNegate

std::string OSnLMNodeMatrixNegate::getTokenName()
{
    return "matrixNegate";
}// end OSnLMNodeMatrixNegate::getTokenName()

GeneralSparseMatrix* OSnLMNodeMatrixNegate::expandNode(OSMatrix** mtxLoc, bool rowMajor_, 
                                                       ENUM_MATRIX_TYPE convertTo_, 
                                                       ENUM_MATRIX_SYMMETRY symmetry_)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace,
                      "expanding an OSnLMNodeMatrixNegate");
#endif
    throw ErrorClass("OSnLMNodeMatrixNegate: expandNode method not yet implemented");
    return NULL;
}//end OSnLMNodeMatrixNegate::expandNode()

ExprNode* OSnLMNodeMatrixNegate::cloneExprNode()
{
    std::ostringstream outStr;
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, "cloning an OSnLMNodeMatrixNegate");
#endif
    ExprNode *nlNodePoint;
    nlNodePoint = new OSnLMNodeMatrixNegate();
#ifndef NDEBUG
    outStr.str( std::string() );
    outStr.clear();
    outStr << "Allocate memory at address " << nlNodePoint << std::endl;
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, outStr.str());
#endif
//    CLONE_CHILDREN;
        if (inumberOfChildren > 0)                              
        {                                                       
            if (nlNodePoint->m_mChildren == NULL)               
                nlNodePoint->m_mChildren                        
                    = new ExprNode*[inumberOfChildren];         
            for (unsigned int i=0; i < inumberOfChildren; i++)  
            {                                                   
                nlNodePoint->m_mChildren[i]                     
                    = this->m_mChildren[i]->cloneExprNode();    
            }                                                   
            nlNodePoint->inumberOfChildren = inumberOfChildren;
        }                                                       
    return nlNodePoint;
}//end OSnLMNodeMatrixNegate::cloneExprNode

// OSnLMNodeMatrixTimes Methods
OSnLMNodeMatrixTimes::OSnLMNodeMatrixTimes()
{
    inumberOfChildren = 2;
    m_mChildren = new ExprNode*[2];
    m_mChildren[0] = NULL;
    m_mChildren[1] = NULL;
    inodeInt = OS_MATRIX_TIMES;
    inodeKind = 3;
}//end OSnLMNodeMatrixTimes

OSnLMNodeMatrixTimes::~OSnLMNodeMatrixTimes()
{
    std::ostringstream outStr;
#ifndef NDEBUG
    outStr << "inside OSnLMNodeMatrixTimes destructor" << endl;
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, outStr.str());
#endif
}//end ~OSnLMNodeMatrixTimes

std::string OSnLMNodeMatrixTimes::getTokenName()
{
    return "matrixTimes";
}// end OSnLMNodeMatrixTimes::getTokenName()

GeneralSparseMatrix* OSnLMNodeMatrixTimes::expandNode(OSMatrix** mtxLoc, bool rowMajor_, 
                                                      ENUM_MATRIX_TYPE convertTo_, 
                                                      ENUM_MATRIX_SYMMETRY symmetry_)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace,
                      "expanding an OSnLMNodeMatrixTimes");
#endif

    GeneralSparseMatrix* returnMtx = NULL;

    try
    {
        if (rowMajor_)
            throw ErrorClass("Row-wise multiplication not implemented yet in OSnLMNodeMatrixTimes");

        GeneralSparseMatrix* factorA
            = ((OSnLMNode*)m_mChildren[0])->expandNode(mtxLoc, true,  convertTo_, symmetry_);
        GeneralSparseMatrix* factorB
            = ((OSnLMNode*)m_mChildren[1])->expandNode(mtxLoc, false, convertTo_, symmetry_);

        if (factorA->numberOfColumns != factorB->numberOfRows)
            throw ErrorClass("Incompatible matrix dimensions in OSnLMNodeMatrixTimes::expandNode()");

        returnMtx = new GeneralSparseMatrix();

        returnMtx->numberOfRows    = factorA->numberOfRows;
        returnMtx->numberOfColumns = factorB->numberOfColumns;
        returnMtx->isRowMajor      = rowMajor_;
        returnMtx->symmetry        = symmetry_;
        returnMtx->startSize       = returnMtx->numberOfColumns + 1;
        returnMtx->start           = new int[returnMtx->startSize];

        ENUM_MATRIX_TYPE rType = mergeMatrixTypeProduct(factorA->valueType, factorB->valueType);

        int i, j, k, l;

        int* loc = new int[factorB->numberOfRows];

        int nonz = 0;
        returnMtx->start[0] = 0;
        
        for (j=0; j < factorB->numberOfRows; ++j)
            loc[j] = 0;

        // in the first pass, count the nonzeroes 
        for (i=0; i < factorB->numberOfColumns; ++i)
        {
            for (j = factorB->start[i]; j < factorB->start[i+1]; ++j)
                loc[factorB->index[j]] = 1;

            for (k = 0; k < factorA->numberOfRows; ++k)
            {
                for (l = factorA->start[k]; l < factorA->start[k+1]; ++l)
                    if (loc[factorA->index[l]] == 1)
                    {
                        ++nonz;
                        break;
                    }
            }
            returnMtx->start[i+1] = nonz;

            for (j = factorB->start[i]; j < factorB->start[i+1]; ++j)
                loc[factorB->index[j]] = 0;
        }

        returnMtx->valueType = rType;
        returnMtx->valueSize = nonz;
        returnMtx->index     = new int[nonz];

        // in the second pass, store the nonzeroes. This must be done separately for each type 
        nonz = 0;
        switch (rType)
        {
            case ENUM_MATRIX_TYPE_constant:
            {
                double val;
                bool   putVal;
                double* denseCol     = new double[factorB->numberOfRows];
                returnMtx->value     = new ConstantMatrixValues();
                ((ConstantMatrixValues*)returnMtx->value)->el = new double[returnMtx->valueSize];

                for (i=0; i < factorB->numberOfColumns; ++i)
                {
                    for (j = factorB->start[i]; j < factorB->start[i+1]; ++j)
                    {
                             loc[factorB->index[j]] = 1;
                        denseCol[factorB->index[j]] = ((ConstantMatrixValues*)factorB->value)->el[j];
                    }

                    for (k = 0; k < factorA->numberOfRows; ++k)
                    {
                        val = 0.0;
                        putVal = false;
                        for (l = factorA->start[k]; l < factorA->start[k+1]; ++l)
                            if (loc[factorA->index[l]] == 1)
                            {
                                putVal = true;
                                val   += ((ConstantMatrixValues*)factorA->value)->el[l]
                                            *denseCol[factorA->index[l]];
                            }

                        if (putVal)
                        {
                            returnMtx->index[nonz] = k;
                            ((ConstantMatrixValues*)returnMtx->value)->el[nonz] = val;
                            nonz++;
                        }
                    }
    
                    for (j = factorB->start[i]; j < factorB->start[i+1]; ++j)
                    {
                             loc[factorB->index[j]] = 0;
                        denseCol[factorB->index[j]] = 0.0;
                    }
                }
                break;
            }

            default:
            {
                throw ErrorClass("Attempting to compute matrix product with unimplemented types");
                break;
            }
        }

        return returnMtx;
    }
    catch(const ErrorClass& eclass)
    {
std::cout << "error catch" << std::endl;
        if (returnMtx != NULL)
            delete returnMtx;
        returnMtx = NULL;
        throw ErrorClass( eclass.errormsg);
    }
}//end OSnLMNodeMatrixTimes::expandNode()

ExprNode* OSnLMNodeMatrixTimes::cloneExprNode()
{
    std::ostringstream outStr;
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, "cloning an OSnLMNodeMatrixTimes");
#endif
    ExprNode *nlNodePoint;
    nlNodePoint = new OSnLMNodeMatrixTimes();
#ifndef NDEBUG
    outStr.str( std::string() );
    outStr.clear();
    outStr << "Allocate memory at address " << nlNodePoint << std::endl;
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, outStr.str());
#endif
//    CLONE_CHILDREN;
        if (inumberOfChildren > 0)                              
        {                                                       
            if (nlNodePoint->m_mChildren == NULL)               
                nlNodePoint->m_mChildren                        
                    = new ExprNode*[inumberOfChildren];         
            for (unsigned int i=0; i < inumberOfChildren; i++)  
            {                                                   
                nlNodePoint->m_mChildren[i]                     
                    = this->m_mChildren[i]->cloneExprNode();    
            }                                                   
            nlNodePoint->inumberOfChildren = inumberOfChildren;
        }                                                       
    return nlNodePoint;
}//end OSnLMNodeMatrixTimes::cloneExprNode

// OSnLMNodeMatrixInverse Methods
OSnLMNodeMatrixInverse::OSnLMNodeMatrixInverse()
{
    inumberOfChildren = 1;
    m_mChildren = new ExprNode*[1];
    m_mChildren[0] = NULL;
    inodeInt = OS_MATRIX_INVERSE;
    inodeKind = 3;
}//end OSnLMNodeMatrixInverse

OSnLMNodeMatrixInverse::~OSnLMNodeMatrixInverse()
{
    std::ostringstream outStr;
#ifndef NDEBUG
    outStr << "inside OSnLMNodeMatrixInverse destructor" << endl;
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, outStr.str());
#endif
}//end ~OSnLMNodeMatrixInverse

std::string OSnLMNodeMatrixInverse::getTokenName()
{
    return "matrixInverse";
}// end OSnLMNodeMatrixInverse::getTokenName()

GeneralSparseMatrix* OSnLMNodeMatrixInverse::expandNode(OSMatrix** mtxLoc, bool rowMajor_, 
                                                        ENUM_MATRIX_TYPE convertTo_, 
                                                        ENUM_MATRIX_SYMMETRY symmetry_)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace,
                      "expanding an OSnLMNodeMatrixInverse");
#endif
    throw ErrorClass("OSnLMNodeMatrixInverse: expandNode method not yet implemented");
    return NULL;
}//end OSnLMNodeMatrixInverse::expandNode()

ExprNode* OSnLMNodeMatrixInverse::cloneExprNode()
{
    std::ostringstream outStr;
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, "cloning an OSnLMNodeMatrixInverse");
#endif
    ExprNode *nlNodePoint;
    nlNodePoint = new OSnLMNodeMatrixInverse();
#ifndef NDEBUG
    outStr.str( std::string() );
    outStr.clear();
    outStr << "Allocate memory at address " << nlNodePoint << std::endl;
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, outStr.str());
#endif
//    CLONE_CHILDREN;
        if (inumberOfChildren > 0)                              
        {                                                       
            if (nlNodePoint->m_mChildren == NULL)               
                nlNodePoint->m_mChildren                        
                    = new ExprNode*[inumberOfChildren];         
            for (unsigned int i=0; i < inumberOfChildren; i++)  
            {                                                   
                nlNodePoint->m_mChildren[i]                     
                    = this->m_mChildren[i]->cloneExprNode();    
            }                                                   
            nlNodePoint->inumberOfChildren = inumberOfChildren;
        }                                                       
    return nlNodePoint;
}//end OSnLMNodeMatrixInverse::cloneExprNode


// OSnLMNodeMatrixTranspose Methods
OSnLMNodeMatrixTranspose::OSnLMNodeMatrixTranspose()
{
    inumberOfChildren = 1;
    m_mChildren = new ExprNode*[1];
    m_mChildren[0] = NULL;
    inodeInt = OS_MATRIX_TRANSPOSE;
    inodeKind = 3;
}//end OSnLMNodeMatrixTranspose

OSnLMNodeMatrixTranspose::~OSnLMNodeMatrixTranspose()
{
    std::ostringstream outStr;
#ifndef NDEBUG
    outStr << "inside OSnLMNodeMatrixTranspose destructor" << endl;
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, outStr.str());
#endif
}//end ~OSnLMNodeMatrixTranspose

std::string OSnLMNodeMatrixTranspose::getTokenName()
{
    return "matrixTranspose";
}// end OSnLMNodeMatrixTranspose::getTokenName()

GeneralSparseMatrix* OSnLMNodeMatrixTranspose::expandNode(OSMatrix** mtxLoc, bool rowMajor_, 
                                                          ENUM_MATRIX_TYPE convertTo_, 
                                                          ENUM_MATRIX_SYMMETRY symmetry_)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace,
                      "expanding an OSnLMNodeMatrixTranspose");
#endif
    try
    {
        GeneralSparseMatrix* refMtx
            = ((OSnLMNode*)m_mChildren[0])->expandNode(mtxLoc, rowMajor_, convertTo_, symmetry_);
        GeneralSparseMatrix* returnMtx = refMtx->convertToOtherMajor(convertTo_, true);
        return returnMtx;
    }
    catch(const ErrorClass& eclass)
    {
        throw ErrorClass( eclass.errormsg);
    }
}//end OSnLMNodeMatrixTranspose::expandNode()

ExprNode* OSnLMNodeMatrixTranspose::cloneExprNode()
{
    std::ostringstream outStr;
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, "cloning an OSnLMNodeMatrixTranspose");
#endif
    ExprNode *nlNodePoint;
    nlNodePoint = new OSnLMNodeMatrixTranspose();
#ifndef NDEBUG
    outStr.str( std::string() );
    outStr.clear();
    outStr << "Allocate memory at address " << nlNodePoint << std::endl;
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, outStr.str());
#endif
//    CLONE_CHILDREN;
        if (inumberOfChildren > 0)                              
        {                                                       
            if (nlNodePoint->m_mChildren == NULL)               
                nlNodePoint->m_mChildren                        
                    = new ExprNode*[inumberOfChildren];         
            for (unsigned int i=0; i < inumberOfChildren; i++)  
            {                                                   
                nlNodePoint->m_mChildren[i]                     
                    = this->m_mChildren[i]->cloneExprNode();    
            }                                                   
            nlNodePoint->inumberOfChildren = inumberOfChildren;
        }                                                       
    return nlNodePoint;
}//end OSnLMNodeMatrixTranspose::cloneExprNode

// OSnLMNodeMatrixScalarTimes Methods
OSnLMNodeMatrixScalarTimes::OSnLMNodeMatrixScalarTimes()
{
    inumberOfChildren = 2;
    m_mChildren = new ExprNode*[2];
    m_mChildren[0] = NULL;
    m_mChildren[1] = NULL;
    inodeInt = OS_MATRIX_SCALARTIMES;
    inodeKind = 3;
}//end OSnLMNodeMatrixScalarTimes

OSnLMNodeMatrixScalarTimes::~OSnLMNodeMatrixScalarTimes()
{
    std::ostringstream outStr;
#ifndef NDEBUG
    outStr << "inside OSnLMNodeMatrixScalarTimes destructor" << endl;
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, outStr.str());
#endif
}//end ~OSnLMNodeMatrixScalarTimes

std::string OSnLMNodeMatrixScalarTimes::getTokenName()
{
    return "matrixScalarTimes";
}// end OSnLMNodeMatrixScalarTimes::getTokenName()

GeneralSparseMatrix* OSnLMNodeMatrixScalarTimes::expandNode(OSMatrix** mtxLoc, bool rowMajor_, 
                                                            ENUM_MATRIX_TYPE convertTo_, 
                                                            ENUM_MATRIX_SYMMETRY symmetry_)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace,
                      "expanding an OSnLMNodeMatrixScalarTimes");
#endif
    throw ErrorClass("OSnLMNodeMatrixScalarTimes: expandNode method not yet implemented");
    return NULL;
}//end OSnLMNodeMatrixScalarTimes::expandNode()

ExprNode* OSnLMNodeMatrixScalarTimes::cloneExprNode()
{
    std::ostringstream outStr;
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, "cloning an OSnLMNodeMatrixScalarTimes");
#endif
    ExprNode *nlNodePoint;
    nlNodePoint = new OSnLMNodeMatrixScalarTimes();
#ifndef NDEBUG
    outStr.str( std::string() );
    outStr.clear();
    outStr << "Allocate memory at address " << nlNodePoint << std::endl;
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, outStr.str());
#endif
//    CLONE_CHILDREN;
        if (inumberOfChildren > 0)                              
        {                                                       
            if (nlNodePoint->m_mChildren == NULL)               
                nlNodePoint->m_mChildren                        
                    = new ExprNode*[inumberOfChildren];         
            for (unsigned int i=0; i < inumberOfChildren; i++)  
            {                                                   
                nlNodePoint->m_mChildren[i]                     
                    = this->m_mChildren[i]->cloneExprNode();    
            }                                                   
            nlNodePoint->inumberOfChildren = inumberOfChildren;
        }                                                       
    return nlNodePoint;
}//end OSnLMNodeMatrixScalarTimes::cloneExprNode

// OSnLMNodeMatrixDotTimes Methods
OSnLMNodeMatrixDotTimes::OSnLMNodeMatrixDotTimes()
{
    inumberOfChildren = 2;
    m_mChildren = new ExprNode*[2];
    m_mChildren[0] = NULL;
    m_mChildren[1] = NULL;
    inodeInt = OS_MATRIX_DOTTIMES;
    inodeKind = 3;
}//end OSnLMNodeMatrixDotTimes

OSnLMNodeMatrixDotTimes::~OSnLMNodeMatrixDotTimes()
{
    std::ostringstream outStr;
#ifndef NDEBUG
    outStr << "inside OSnLMNodeMatrixDotTimes destructor" << endl;
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, outStr.str());
#endif
}//end ~OSnLMNodeMatrixDotTimes

std::string OSnLMNodeMatrixDotTimes::getTokenName()
{
    return "matrixDotTimes";
}// end OSnLMNodeMatrixDotTimes::getTokenName()

GeneralSparseMatrix* OSnLMNodeMatrixDotTimes::expandNode(OSMatrix** mtxLoc, bool rowMajor_, 
                                                         ENUM_MATRIX_TYPE convertTo_, 
                                                         ENUM_MATRIX_SYMMETRY symmetry_)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace,
                      "expanding an OSnLMNodeMatrixDotTimes");
#endif
    throw ErrorClass("OSnLMNodeMatrixDotTimes: expandNode method not yet implemented");
    return NULL;
}//end OSnLMNodeMatrixDotTimes::expandNode()

ExprNode* OSnLMNodeMatrixDotTimes::cloneExprNode()
{
    std::ostringstream outStr;
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, "cloning an OSnLMNodeMatrixDotTimes");
#endif
    ExprNode *nlNodePoint;
    nlNodePoint = new OSnLMNodeMatrixDotTimes();
#ifndef NDEBUG
    outStr.str( std::string() );
    outStr.clear();
    outStr << "Allocate memory at address " << nlNodePoint << std::endl;
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, outStr.str());
#endif
//    CLONE_CHILDREN;
        if (inumberOfChildren > 0)                              
        {                                                       
            if (nlNodePoint->m_mChildren == NULL)               
                nlNodePoint->m_mChildren                        
                    = new ExprNode*[inumberOfChildren];         
            for (unsigned int i=0; i < inumberOfChildren; i++)  
            {                                                   
                nlNodePoint->m_mChildren[i]                     
                    = this->m_mChildren[i]->cloneExprNode();    
            }                                                   
            nlNodePoint->inumberOfChildren = inumberOfChildren;
        }                                                       
    return nlNodePoint;
}//end OSnLMNodeMatrixDotTimes::cloneExprNode


// OSnLMNodeIdentityMatrix Methods
OSnLMNodeIdentityMatrix::OSnLMNodeIdentityMatrix()
{
    inumberOfChildren = 1;
    m_mChildren = new ExprNode*[1];
    m_mChildren[0] = NULL;
    inodeInt = OS_IDENTITY_MATRIX;
    inodeKind = 3;
}//end OSnLMNodeIdentityMatrix

OSnLMNodeIdentityMatrix::~OSnLMNodeIdentityMatrix()
{
    std::ostringstream outStr;
#ifndef NDEBUG
    outStr << "inside OSnLMNodeIdentityMatrix destructor" << endl;
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, outStr.str());
#endif
}//end ~OSnLMNodeIdentityMatrix

std::string OSnLMNodeIdentityMatrix::getTokenName()
{
    return "identityMatrix";
}// end OSnLMNodeIdentityMatrix::getTokenName()

GeneralSparseMatrix* OSnLMNodeIdentityMatrix::expandNode(OSMatrix** mtxLoc, bool rowMajor_, 
                                                         ENUM_MATRIX_TYPE convertTo_, 
                                                         ENUM_MATRIX_SYMMETRY symmetry_)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace,
                      "expanding an OSnLMNodeIdentityMatrix");
#endif
    throw ErrorClass("OSnLMNodeIdentityMatrix: expandNode method not yet implemented");
    return NULL;
}//end OSnLMNodeIdentityMatrix::expandNode()

ExprNode* OSnLMNodeIdentityMatrix::cloneExprNode()
{
    std::ostringstream outStr;
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, "cloning an OSnLMNodeIdentityMatrix");
#endif
    ExprNode *nlNodePoint;
    nlNodePoint = new OSnLMNodeIdentityMatrix();
#ifndef NDEBUG
    outStr.str( std::string() );
    outStr.clear();
    outStr << "Allocate memory at address " << nlNodePoint << std::endl;
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, outStr.str());
#endif
//    CLONE_CHILDREN;
        if (inumberOfChildren > 0)                              
        {                                                       
            if (nlNodePoint->m_mChildren == NULL)               
                nlNodePoint->m_mChildren                        
                    = new ExprNode*[inumberOfChildren];         
            for (unsigned int i=0; i < inumberOfChildren; i++)  
            {                                                   
                nlNodePoint->m_mChildren[i]                     
                    = this->m_mChildren[i]->cloneExprNode();    
            }                                                   
            nlNodePoint->inumberOfChildren = inumberOfChildren;
        }                                                       
    return nlNodePoint;
}//end OSnLMNodeIdentityMatrix::cloneExprNode


// OSnLMNodeMatrixLowerTriangle Methods
OSnLMNodeMatrixLowerTriangle::OSnLMNodeMatrixLowerTriangle()
{
    inumberOfChildren = 1;
    m_mChildren = new ExprNode*[1];
    m_mChildren[0] = NULL;
    inodeInt = OS_MATRIX_LOWERTRIANGLE;
    inodeKind = 3;
    includeDiagonal = true;
}//end OSnLMNodeMatrixLowerTriangle

OSnLMNodeMatrixLowerTriangle::~OSnLMNodeMatrixLowerTriangle()
{
    std::ostringstream outStr;
#ifndef NDEBUG
    outStr << "inside OSnLMNodeMatrixLowerTriangle destructor" << endl;
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, outStr.str());
#endif
}//end ~OSnLMNodeMatrixLowerTriangle

std::string OSnLMNodeMatrixLowerTriangle::getTokenName()
{
    return "matrixLowerTriangle";
}// end OSnLMNodeMatrixLowerTriangle::getTokenName()

GeneralSparseMatrix* OSnLMNodeMatrixLowerTriangle::expandNode(OSMatrix** mtxLoc, bool rowMajor_, 
                                                              ENUM_MATRIX_TYPE convertTo_, 
                                                              ENUM_MATRIX_SYMMETRY symmetry_)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace,
                      "expanding an OSnLMNodeMatrixLowerTriangle");
#endif
    throw ErrorClass("OSnLMNodeMatrixLowerTriangle: expandNode method not yet implemented");
    return NULL;
}//end OSnLMNodeMatrixLowerTriangle::expandNode()

ExprNode* OSnLMNodeMatrixLowerTriangle::cloneExprNode()
{
    std::ostringstream outStr;
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, "cloning an OSnLMNodeMatrixLowerTriangle");
#endif
    ExprNode *nlNodePoint;
    nlNodePoint = new OSnLMNodeMatrixLowerTriangle();
#ifndef NDEBUG
    outStr.str( std::string() );
    outStr.clear();
    outStr << "Allocate memory at address " << nlNodePoint << std::endl;
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, outStr.str());
#endif
    ((OSnLMNodeMatrixLowerTriangle*)nlNodePoint)->includeDiagonal = includeDiagonal;
//    CLONE_CHILDREN;
        if (inumberOfChildren > 0)                              
        {                                                       
            if (nlNodePoint->m_mChildren == NULL)               
                nlNodePoint->m_mChildren                        
                    = new ExprNode*[inumberOfChildren];         
            for (unsigned int i=0; i < inumberOfChildren; i++)  
            {                                                   
                nlNodePoint->m_mChildren[i]                     
                    = this->m_mChildren[i]->cloneExprNode();    
            }                                                   
            nlNodePoint->inumberOfChildren = inumberOfChildren;
        }                                                       
    return nlNodePoint;
}//end OSnLMNodeMatrixLowerTriangle::cloneExprNode


std::string OSnLMNodeMatrixLowerTriangle::getNonlinearExpressionInXML()
{
    ostringstream outStr;
    outStr << "<matrixLowerTriangle";
    if (includeDiagonal == false)
        outStr << " includeDiagonal=\"false\""; 
    outStr << ">" << std::endl;

    outStr << m_mChildren[0]->getNonlinearExpressionInXML();

    outStr << "</matrixLowerTriangle>";
    return outStr.str();
}//OSnLMNodeMatrixLowerTriangle::getNonlinearExpressionInXML

bool OSnLMNodeMatrixLowerTriangle::IsEqual(OSnLMNodeMatrixLowerTriangle *that)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, "Start comparing in OSnLMNodeMatrixLowerTriangle");
#endif
    if (this == NULL)
    {
        if (that == NULL)
            return true;
        else
        {
#ifndef NDEBUG
            osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, 
                "First object is NULL, second is not");
#endif
            return false;
        }
    }
    else
    {
        if (that == NULL)
        {
#ifndef NDEBUG
            osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, 
                "Second object is NULL, first is not");
#endif
            return false;
        }
        else
        {
            if (this->inodeInt != that->inodeInt)
                return false;
            if (this->inodeKind != that->inodeKind)
                return false;
            if (this->inumberOfChildren != that->inumberOfChildren)
                return false;

            if (this->includeDiagonal != that->includeDiagonal)
                return false;

            for (unsigned int i = 0; i < this->inumberOfChildren; i++)
                if (!this->m_mChildren[i]->IsEqual(that->m_mChildren[i]))
                    return false;

            return true;
        }
    }
}//OSnLMNodeMatrixLowerTriangle::IsEqual


// OSnLMNodeMatrixUpperTriangle Methods

OSnLMNodeMatrixUpperTriangle::OSnLMNodeMatrixUpperTriangle()
{
    inumberOfChildren = 1;
    m_mChildren = new ExprNode*[1];
    m_mChildren[0] = NULL;
    inodeInt = OS_MATRIX_UPPERTRIANGLE;
    inodeKind = 3;

    includeDiagonal = true;
}//end OSnLMNodeMatrixUpperTriangle

OSnLMNodeMatrixUpperTriangle::~OSnLMNodeMatrixUpperTriangle()
{
    std::ostringstream outStr;
#ifndef NDEBUG
    outStr << "inside OSnLMNodeMatrixUpperTriangle destructor" << endl;
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, outStr.str());
#endif
}//end ~OSnLMNodeMatrixUpperTriangle

std::string OSnLMNodeMatrixUpperTriangle::getNonlinearExpressionInXML()
{
    ostringstream outStr;
    outStr << "<matrixUpperTriangle";
    if (includeDiagonal == false)
        outStr << " includeDiagonal=\"false\""; 
    outStr << ">" << std::endl;

    outStr << m_mChildren[0]->getNonlinearExpressionInXML();

    outStr << "</matrixUpperTriangle>";
    return outStr.str();
}//OSnLMNodeMatrixUpperTriangle::getNonlinearExpressionInXML

std::string OSnLMNodeMatrixUpperTriangle::getTokenName()
{
    return "matrixUpperTriangle";
}// end OSnLMNodeMatrixUpperTriangle::getTokenName()

GeneralSparseMatrix* OSnLMNodeMatrixUpperTriangle::expandNode(OSMatrix** mtxLoc, bool rowMajor_, 
                                                              ENUM_MATRIX_TYPE convertTo_, 
                                                              ENUM_MATRIX_SYMMETRY symmetry_)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace,
                      "expanding an OSnLMNodeMatrixUpperTriangle");
#endif
    throw ErrorClass("OSnLMNodeMatrixUpperTriangle: expandNode method not yet implemented");
    return NULL;
}//end OSnLMNodeMatrixUpperTriangle::expandNode()

ExprNode* OSnLMNodeMatrixUpperTriangle::cloneExprNode()
{
    std::ostringstream outStr;
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, "cloning an OSnLMNodeMatrixUpperTriangle");
#endif
    ExprNode *nlNodePoint;
    nlNodePoint = new OSnLMNodeMatrixUpperTriangle();
#ifndef NDEBUG
    outStr.str( std::string() );
    outStr.clear();
    outStr << "Allocate memory at address " << nlNodePoint << std::endl;
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, outStr.str());
#endif
    ((OSnLMNodeMatrixUpperTriangle*)nlNodePoint)->includeDiagonal = includeDiagonal;
//    CLONE_CHILDREN;
        if (inumberOfChildren > 0)                              
        {                                                       
            if (nlNodePoint->m_mChildren == NULL)               
                nlNodePoint->m_mChildren                        
                    = new ExprNode*[inumberOfChildren];         
            for (unsigned int i=0; i < inumberOfChildren; i++)  
            {                                                   
                nlNodePoint->m_mChildren[i]                     
                    = this->m_mChildren[i]->cloneExprNode();    
            }                                                   
            nlNodePoint->inumberOfChildren = inumberOfChildren;
        }                                                       
    return nlNodePoint;
}//end OSnLMNodeMatrixUpperTriangle::cloneExprNode


bool OSnLMNodeMatrixUpperTriangle::IsEqual(OSnLMNodeMatrixUpperTriangle *that)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, "Start comparing in OSnLMNodeMatrixUpperTriangle");
#endif
    if (this == NULL)
    {
        if (that == NULL)
            return true;
        else
        {
#ifndef NDEBUG
            osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, 
                "First object is NULL, second is not");
#endif
            return false;
        }
    }
    else
    {
        if (that == NULL)
        {
#ifndef NDEBUG
            osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, 
                "Second object is NULL, first is not");
#endif
            return false;
        }
        else
        {
            if (this->inodeInt != that->inodeInt)
                return false;
            if (this->inodeKind != that->inodeKind)
                return false;
            if (this->inumberOfChildren != that->inumberOfChildren)
                return false;

            if (this->includeDiagonal != that->includeDiagonal)
                return false;

            for (unsigned int i = 0; i < this->inumberOfChildren; i++)
                if (!this->m_mChildren[i]->IsEqual(that->m_mChildren[i]))
                    return false;

            return true;
        }
    }
}//OSnLMNodeMatrixUpperTriangle::IsEqual


// OSnLMNodeMatrixDiagonal Methods
OSnLMNodeMatrixDiagonal::OSnLMNodeMatrixDiagonal()
{
    inumberOfChildren = 1;
    m_mChildren = new ExprNode*[1];
    m_mChildren[0] = NULL;
    inodeInt = OS_MATRIX_DIAGONAL;
    inodeKind = 3;
}//end OSnLMNodeMatrixDiagonal

OSnLMNodeMatrixDiagonal::~OSnLMNodeMatrixDiagonal()
{
    std::ostringstream outStr;
#ifndef NDEBUG
    outStr << "inside OSnLMNodeMatrixDiagonal destructor" << endl;
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, outStr.str());
#endif
}//end ~OSnLMNodeMatrixDiagonal

std::string OSnLMNodeMatrixDiagonal::getTokenName()
{
    return "matrixDiagonal";
}// end OSnLMNodeMatrixDiagonal::getTokenName()

GeneralSparseMatrix* OSnLMNodeMatrixDiagonal::expandNode(OSMatrix** mtxLoc, bool rowMajor_, 
                                                         ENUM_MATRIX_TYPE convertTo_, 
                                                         ENUM_MATRIX_SYMMETRY symmetry_)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace,
                      "expanding an OSnLMNodeMatrixDiagonal");
#endif
    throw ErrorClass("OSnLMNodeMatrixDiagonal: expandNode method not yet implemented");
    return NULL;
}//end OSnLMNodeMatrixDiagonal::expandNode()

ExprNode* OSnLMNodeMatrixDiagonal::cloneExprNode()
{
    std::ostringstream outStr;
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, "cloning an OSnLMNodeMatrixDiagonal");
#endif
    ExprNode *nlNodePoint;
    nlNodePoint = new OSnLMNodeMatrixDiagonal();
#ifndef NDEBUG
    outStr.str( std::string() );
    outStr.clear();
    outStr << "Allocate memory at address " << nlNodePoint << std::endl;
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, outStr.str());
#endif
//    CLONE_CHILDREN;
        if (inumberOfChildren > 0)                              
        {                                                       
            if (nlNodePoint->m_mChildren == NULL)               
                nlNodePoint->m_mChildren                        
                    = new ExprNode*[inumberOfChildren];         
            for (unsigned int i=0; i < inumberOfChildren; i++)  
            {                                                   
                nlNodePoint->m_mChildren[i]                     
                    = this->m_mChildren[i]->cloneExprNode();    
            }                                                   
            nlNodePoint->inumberOfChildren = inumberOfChildren;
        }                                                       
    return nlNodePoint;
}//end OSnLMNodeMatrixDiagonal::cloneExprNode


// OSnLMNodeDiagonalMatrixFromVector Methods
OSnLMNodeDiagonalMatrixFromVector::OSnLMNodeDiagonalMatrixFromVector()
{
    inumberOfChildren = 1;
    m_mChildren = new ExprNode*[1];
    m_mChildren[0] = NULL;
    inodeInt = OS_DIAGONAL_MATRIX_FROM_VECTOR;
    inodeKind = 3;
}//end OSnLMNodeDiagonalMatrixFromVector

OSnLMNodeDiagonalMatrixFromVector::~OSnLMNodeDiagonalMatrixFromVector()
{
    std::ostringstream outStr;
#ifndef NDEBUG
    outStr << "inside OSnLMNodeDiagonalMatrixFromVector destructor" << endl;
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, outStr.str());
#endif
}//end ~OSnLMNodeDiagonalMatrixFromVector

std::string OSnLMNodeDiagonalMatrixFromVector::getTokenName()
{
    return "diagonalMatrixFromVector";
}// end OSnLMNodeDiagonalMatrixFromVector::getTokenName()

GeneralSparseMatrix* OSnLMNodeDiagonalMatrixFromVector::expandNode(OSMatrix** mtxLoc, bool rowMajor_, 
                                                                   ENUM_MATRIX_TYPE convertTo_, 
                                                                   ENUM_MATRIX_SYMMETRY symmetry_)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace,
                      "expanding an OSnLMNodeDiagonalMatrixFromVector");
#endif
    throw ErrorClass("OSnLMNodeDiagonalMatrixFromVector: expandNode method not yet implemented");
    return NULL;
}//end OSnLMNodeDiagonalMatrixFromVector::expandNode()

ExprNode* OSnLMNodeDiagonalMatrixFromVector::cloneExprNode()
{
    std::ostringstream outStr;
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, "cloning an OSnLMNodeDiagonalMatrixFromVector");
#endif
    ExprNode *nlNodePoint;
    nlNodePoint = new OSnLMNodeDiagonalMatrixFromVector();
#ifndef NDEBUG
    outStr.str( std::string() );
    outStr.clear();
    outStr << "Allocate memory at address " << nlNodePoint << std::endl;
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, outStr.str());
#endif
//    CLONE_CHILDREN;
        if (inumberOfChildren > 0)                              
        {                                                       
            if (nlNodePoint->m_mChildren == NULL)               
                nlNodePoint->m_mChildren                        
                    = new ExprNode*[inumberOfChildren];         
            for (unsigned int i=0; i < inumberOfChildren; i++)  
            {                                                   
                nlNodePoint->m_mChildren[i]                     
                    = this->m_mChildren[i]->cloneExprNode();    
            }                                                   
            nlNodePoint->inumberOfChildren = inumberOfChildren;
        }                                                       
    return nlNodePoint;
}//end OSnLMNodeDiagonalMatrixFromVector::cloneExprNode


// OSnLMNodeMatrixSubmatrixAt Methods
OSnLMNodeMatrixSubmatrixAt::OSnLMNodeMatrixSubmatrixAt()
{
    inumberOfChildren = 5;
    m_mChildren = new ExprNode*[5];
    m_mChildren[0] = NULL;
    m_mChildren[1] = NULL;
    m_mChildren[2] = NULL;
    m_mChildren[3] = NULL;
    m_mChildren[4] = NULL;
    inodeInt = OS_MATRIX_SUBMATRIX_AT;
    inodeKind = 3;
}//end OSnLMNodeMatrixSubmatrixAt

OSnLMNodeMatrixSubmatrixAt::~OSnLMNodeMatrixSubmatrixAt()
{
    std::ostringstream outStr;
#ifndef NDEBUG
    outStr << "inside OSnLMNodeMatrixSubmatrixAt destructor" << endl;
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, outStr.str());
#endif
}//end ~OSnLMNodeMatrixSubmatrixAt

std::string OSnLMNodeMatrixSubmatrixAt::getTokenName()
{
    return "matrixSubmatrixAt";
}// end OSnLMNodeMatrixSubmatrixAt::getTokenName()

GeneralSparseMatrix* OSnLMNodeMatrixSubmatrixAt::expandNode(OSMatrix** mtxLoc, bool rowMajor_, 
                                                            ENUM_MATRIX_TYPE convertTo_, 
                                                            ENUM_MATRIX_SYMMETRY symmetry_)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace,
                      "expanding an OSnLMNodeMatrixSubmatrixAt");
#endif
    throw ErrorClass("OSnLMNodeMatrixSubmatrixAt: expandNode method not yet implemented");
    return NULL;
}//end OSnLMNodeMatrixSubmatrixAt::expandNode()

ExprNode* OSnLMNodeMatrixSubmatrixAt::cloneExprNode()
{
    std::ostringstream outStr;
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, "cloning an OSnLMNodeMatrixSubmatrixAt");
#endif
    ExprNode *nlNodePoint;
    nlNodePoint = new OSnLMNodeMatrixSubmatrixAt();
#ifndef NDEBUG
    outStr.str( std::string() );
    outStr.clear();
    outStr << "Allocate memory at address " << nlNodePoint << std::endl;
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, outStr.str());
#endif
//    CLONE_CHILDREN;
        if (inumberOfChildren > 0)                              
        {                                                       
            if (nlNodePoint->m_mChildren == NULL)               
                nlNodePoint->m_mChildren                        
                    = new ExprNode*[inumberOfChildren];         
            for (unsigned int i=0; i < inumberOfChildren; i++)  
            {                                                   
                nlNodePoint->m_mChildren[i]                     
                    = this->m_mChildren[i]->cloneExprNode();    
            }                                                   
            nlNodePoint->inumberOfChildren = inumberOfChildren;
        }                                                       
    return nlNodePoint;
}//end OSnLMNodeMatrixSubmatrixAt::cloneExprNode


// OSnLMNodeMatrixReference Methods
OSnLMNodeMatrixReference::OSnLMNodeMatrixReference():
    idx(-1),
    transpose(false)
{
    inumberOfChildren = 0;
    m_mChildren = NULL;
    inodeInt = OS_MATRIX_REFERENCE;
    inodeKind = 3;
}//end OSnLMNodeMatrixReference

OSnLMNodeMatrixReference::~OSnLMNodeMatrixReference()
{
    std::ostringstream outStr;
#ifndef NDEBUG
    outStr << "inside OSnLMNodeMatrixReference destructor" << endl;
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, outStr.str());
#endif
}//end ~OSnLMNodeMatrixReference


std::string OSnLMNodeMatrixReference::getTokenName()
{
    return "matrixReference";
}// end OSnLMNodeMatrixReference::getTokenName()

std::string OSnLMNodeMatrixReference::getTokenNumber()
{
    ostringstream outStr;
    outStr << inodeInt;
    outStr << "[";
    outStr << inumberOfChildren;
    outStr << "]";
    outStr << ":";
    outStr << idx;
    outStr << ":";
    return outStr.str();
}//getTokenNumber


std::string OSnLMNodeMatrixReference::getNodeInfo(bool recurse, int indent)
{
    ostringstream outStr;
    for (int i=0; i < indent; i++)
        outStr << " ";
    outStr << "node address: " << this;
    outStr << " type: " << inodeInt << "(" << &inodeInt << ")" << " matrixRef = " << idx;
    if (transpose)
        outStr << " (transposed)";
    outStr << std::endl;
    return outStr.str();
}//getNodeInfo

std::string OSnLMNodeMatrixReference::getNonlinearExpressionInXML()
{
    ostringstream outStr;
    outStr << "<matrixReference idx=\"" << idx << "\"/>" << std::endl;
    return outStr.str();
}//OSnLMNodeMatrixReference::getNonlinearExpressionInXML

GeneralSparseMatrix* OSnLMNodeMatrixReference::expandNode(OSMatrix** mtxLoc, bool rowMajor_, 
                                                          ENUM_MATRIX_TYPE convertTo_, 
                                                          ENUM_MATRIX_SYMMETRY symmetry_)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace,
                      "expanding an OSnLMNodeMatrixReference");
#endif
    try
    {
        GeneralSparseMatrix* refMtx;
        int i = mtxLoc[idx]->getExpandedMatrix(mtxLoc, rowMajor_, convertTo_, symmetry_);
        if (i < 0)
            throw ErrorClass("OSnLMNodeMatrixReference::expandNode(): Matrix reference failed");
        refMtx = mtxLoc[idx]->expandedMatrixByElements[i];
        return refMtx;
    }
    catch(const ErrorClass& eclass)
    {
        throw ErrorClass( eclass.errormsg);
    }
    return NULL;
}//end OSnLMNodeMatrixReference::expandNode()

ExprNode* OSnLMNodeMatrixReference::cloneExprNode()
{
    std::ostringstream outStr;
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, "cloning an OSnLMNodeMatrixReference");
#endif
    ExprNode *nlNodePoint;
    nlNodePoint = new OSnLMNodeMatrixReference();
#ifndef NDEBUG
    outStr.str( std::string() );
    outStr.clear();
    outStr << "Allocate memory at address " << nlNodePoint << std::endl;
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, outStr.str());
#endif
    ((OSnLMNodeMatrixReference*)nlNodePoint)->idx = idx;
//    CLONE_CHILDREN;
        if (inumberOfChildren > 0)                              
        {                                                       
            if (nlNodePoint->m_mChildren == NULL)               
                nlNodePoint->m_mChildren                        
                    = new ExprNode*[inumberOfChildren];         
            for (unsigned int i=0; i < inumberOfChildren; i++)  
            {                                                   
                nlNodePoint->m_mChildren[i]                     
                    = this->m_mChildren[i]->cloneExprNode();    
            }                                                   
            nlNodePoint->inumberOfChildren = inumberOfChildren;
        }                                                       
    return nlNodePoint;
}//end OSnLMNodeMatrixReference::cloneExprNode


bool OSnLMNodeMatrixReference::IsEqual(OSnLMNodeMatrixReference *that)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, "Start comparing in OSnLMNodeMatrixReference");
#endif
    if (this == NULL)
    {
        if (that == NULL)
            return true;
        else
        {
#ifndef NDEBUG
            osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, 
                "First object is NULL, second is not");
#endif
            return false;
        }
    }
    else
    {
        if (that == NULL)
        {
#ifndef NDEBUG
            osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, 
                "Second object is NULL, first is not");
#endif
            return false;
        }
        else
        {
            if (this->inodeInt != that->inodeInt)
                return false;
            if (this->inodeKind != that->inodeKind)
                return false;
            if (this->inumberOfChildren != that->inumberOfChildren)
                return false;

            if (this->idx != that->idx)
                return false;

            for (unsigned int i = 0; i < this->inumberOfChildren; i++)
                if (!this->m_mChildren[i]->IsEqual(that->m_mChildren[i]))
                    return false;

            return true;
        }
    }
}//OSnLMNodeMatrixReference::IsEqual


// OSnLMNodeMatrixVar Methods
OSnLMNodeMatrixVar::OSnLMNodeMatrixVar():
    idx(-1)
{
    inumberOfChildren = 0;
    m_mChildren = NULL;
    inodeInt = OS_MATRIX_VAR;
    inodeKind = 3;
}//end OSnLMNodeMatrixVar

OSnLMNodeMatrixVar::~OSnLMNodeMatrixVar()
{
    std::ostringstream outStr;
#ifndef NDEBUG
    outStr << "inside OSnLMNodeMatrixVar destructor" << endl;
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, outStr.str());
#endif
}//end ~OSnLMNodeMatrixVar

std::string OSnLMNodeMatrixVar::getTokenNumber()
{
    ostringstream outStr;
    outStr << inodeInt;
    outStr << "[";
    outStr << inumberOfChildren;
    outStr << "]";
    outStr << ":";
    outStr << idx;
    outStr << ":";
    return outStr.str();
}//getTokenNumber

std::string OSnLMNodeMatrixVar::getTokenName()
{
    return "matrixVar";
}// end OSnLMNodeMatrixVar::getTokenName()


std::string OSnLMNodeMatrixVar::getNonlinearExpressionInXML()
{
    ostringstream outStr;

    outStr << "<matrixVar idx=\"" << idx << "\"/>" << std::endl;
    return outStr.str();
}//OSnLMNodeMatrixVar::getNonlinearExpressionInXML


GeneralSparseMatrix* OSnLMNodeMatrixVar::expandNode(OSMatrix** mtxLoc, bool rowMajor_, 
                                                    ENUM_MATRIX_TYPE convertTo_, 
                                                    ENUM_MATRIX_SYMMETRY symmetry_)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace,
                      "expanding an OSnLMNodeMatrixVar");
#endif
    throw ErrorClass("OSnLMNodeMatrixVBar: expandNode method not yet implemented");
    return NULL;
}//end OSnLMNodeMatrixVar::expandNode()

ExprNode* OSnLMNodeMatrixVar::cloneExprNode()
{
    std::ostringstream outStr;
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, "cloning an OSnLMNodeMatrixVar");
#endif
    ExprNode *nlNodePoint;
    nlNodePoint = new OSnLMNodeMatrixVar();
#ifndef NDEBUG
    outStr.str( std::string() );
    outStr.clear();
    outStr << "Allocate memory at address " << nlNodePoint << std::endl;
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, outStr.str());
#endif
    ((OSnLMNodeMatrixVar*)nlNodePoint)->idx = idx;
//    CLONE_CHILDREN;
        if (inumberOfChildren > 0)                              
        {                                                       
            if (nlNodePoint->m_mChildren == NULL)               
                nlNodePoint->m_mChildren                        
                    = new ExprNode*[inumberOfChildren];         
            for (unsigned int i=0; i < inumberOfChildren; i++)  
            {                                                   
                nlNodePoint->m_mChildren[i]                     
                    = this->m_mChildren[i]->cloneExprNode();    
            }                                                   
            nlNodePoint->inumberOfChildren = inumberOfChildren;
        }                                                       
    return nlNodePoint;
}//end OSnLMNodeMatrixVar::cloneExprNode


bool OSnLMNodeMatrixVar::IsEqual(OSnLMNodeMatrixVar *that)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, "Start comparing in OSnLMNodeMatrixVar");
#endif
    if (this == NULL)
    {
        if (that == NULL)
            return true;
        else
        {
#ifndef NDEBUG
            osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, 
                "First object is NULL, second is not");
#endif
            return false;
        }
    }
    else
    {
        if (that == NULL)
        {
#ifndef NDEBUG
            osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, 
                "Second object is NULL, first is not");
#endif
            return false;
        }
        else
        {
            if (this->inodeInt != that->inodeInt)
                return false;
            if (this->inodeKind != that->inodeKind)
                return false;
            if (this->inumberOfChildren != that->inumberOfChildren)
                return false;

            if (this->idx != that->idx)
                return false;

            for (unsigned int i = 0; i < this->inumberOfChildren; i++)
                if (!this->m_mChildren[i]->IsEqual(that->m_mChildren[i]))
                    return false;

            return true;
        }
    }
}//OSnLMNodeMatrixVar::IsEqual


// OSnLMNodeMatrixObj Methods
OSnLMNodeMatrixObj::OSnLMNodeMatrixObj():
    idx(-1)
{
    inumberOfChildren = 0;
    m_mChildren = NULL;
    inodeInt = OS_MATRIX_OBJ;
    inodeKind = 3;
}//end OSnLMNodeMatrixObj

OSnLMNodeMatrixObj::~OSnLMNodeMatrixObj()
{
    std::ostringstream outStr;
#ifndef NDEBUG
    outStr << "inside OSnLMNodeMatrixObj destructor" << endl;
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, outStr.str());
#endif
}//end ~OSnLMNodeMatrixObj

std::string OSnLMNodeMatrixObj::getTokenNumber()
{
    ostringstream outStr;
    outStr << inodeInt;
    outStr << "[";
    outStr << inumberOfChildren;
    outStr << "]";
    outStr << ":";
    outStr << idx;
    outStr << ":";
    return outStr.str();
}//getTokenNumber

std::string OSnLMNodeMatrixObj::getTokenName()
{
    return "matrixObj";
}// end OSnLMNodeMatrixVar::getTokenName()


std::string OSnLMNodeMatrixObj::getNonlinearExpressionInXML()
{
    ostringstream outStr;
    outStr << "<matrixObj idx=\"" << idx << "\"/>" << std::endl;
    return outStr.str();
}//OSnLMNodeMatrixObj::getNonlinearExpressionInXML

GeneralSparseMatrix* OSnLMNodeMatrixObj::expandNode(OSMatrix** mtxLoc, bool rowMajor_, 
                                                    ENUM_MATRIX_TYPE convertTo_, 
                                                    ENUM_MATRIX_SYMMETRY symmetry_)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace,
                      "expanding an OSnLMNodeMatrixObj");
#endif
    throw ErrorClass("OSnLMNodeMatrixObj: expandNode method not yet implemented");
    return NULL;
}//end OSnLMNodeMatrixObj::expandNode()

ExprNode* OSnLMNodeMatrixObj::cloneExprNode()
{
    std::ostringstream outStr;
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, "cloning an OSnLMNodeMatrixObj");
#endif
    ExprNode *nlNodePoint;
    nlNodePoint = new OSnLMNodeMatrixObj();
#ifndef NDEBUG
    outStr.str( std::string() );
    outStr.clear();
    outStr << "Allocate memory at address " << nlNodePoint << std::endl;
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, outStr.str());
#endif
    ((OSnLMNodeMatrixObj*)nlNodePoint)->idx = idx;
//    CLONE_CHILDREN;
        if (inumberOfChildren > 0)                              
        {                                                       
            if (nlNodePoint->m_mChildren == NULL)               
                nlNodePoint->m_mChildren                        
                    = new ExprNode*[inumberOfChildren];         
            for (unsigned int i=0; i < inumberOfChildren; i++)  
            {                                                   
                nlNodePoint->m_mChildren[i]                     
                    = this->m_mChildren[i]->cloneExprNode();    
            }                                                   
            nlNodePoint->inumberOfChildren = inumberOfChildren;
        }                                                       
    return nlNodePoint;
}//end OSnLMNodeMatrixObj::cloneExprNode


bool OSnLMNodeMatrixObj::IsEqual(OSnLMNodeMatrixObj *that)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, "Start comparing in OSnLMNodeMatrixObj");
#endif
    if (this == NULL)
    {
        if (that == NULL)
            return true;
        else
        {
#ifndef NDEBUG
            osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, 
                "First object is NULL, second is not");
#endif
            return false;
        }
    }
    else
    {
        if (that == NULL)
        {
#ifndef NDEBUG
            osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, 
                "Second object is NULL, first is not");
#endif
            return false;
        }
        else
        {
            if (this->inodeInt != that->inodeInt)
                return false;
            if (this->inodeKind != that->inodeKind)
                return false;
            if (this->inumberOfChildren != that->inumberOfChildren)
                return false;

            if (this->idx != that->idx)
                return false;

            for (unsigned int i = 0; i < this->inumberOfChildren; i++)
                if (!this->m_mChildren[i]->IsEqual(that->m_mChildren[i]))
                    return false;

            return true;
        }
    }
}//OSnLMNodeMatrixObj::IsEqual


// OSnLMNodeMatrixCon Methods
OSnLMNodeMatrixCon::OSnLMNodeMatrixCon():
    idx(-1)
{
    inumberOfChildren = 0;
    m_mChildren = NULL;
    inodeInt = OS_MATRIX_CON;
    inodeKind = 3;
}//end OSnLMNodeMatrixCon

OSnLMNodeMatrixCon::~OSnLMNodeMatrixCon()
{
    std::ostringstream outStr;
#ifndef NDEBUG
    outStr << "inside OSnLMNodeMatrixCon destructor" << endl;
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, outStr.str());
#endif
}//end ~OSnLMNodeMatrixCon

std::string OSnLMNodeMatrixCon::getTokenNumber()
{
    ostringstream outStr;
    outStr << inodeInt;
    outStr << "[";
    outStr << inumberOfChildren;
    outStr << "]";
    outStr << ":";
    outStr << idx;
    outStr << ":";
    return outStr.str();
}//getTokenNumber

std::string OSnLMNodeMatrixCon::getTokenName()
{
    return "matrixCon";
}// end OSnLMNodeMatrixCon::getTokenName()


std::string OSnLMNodeMatrixCon::getNonlinearExpressionInXML()
{
    ostringstream outStr;
    outStr << "<matrixCon idx=\"" << idx << "\"/>" << std::endl;
    return outStr.str();
}//OSnLMNodeMatrixCon::getNonlinearExpressionInXML

GeneralSparseMatrix* OSnLMNodeMatrixCon::expandNode(OSMatrix** mtxLoc, bool rowMajor_, 
                                                    ENUM_MATRIX_TYPE convertTo_, 
                                                    ENUM_MATRIX_SYMMETRY symmetry_)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace,
                      "expanding an OSnLMNodeMatrixCon");
#endif
    throw ErrorClass("OSnLMNodeMatrixCon: expandNode method not yet implemented");
    return NULL;
}//end OSnLMNodeMatrixCon::expandNode()

ExprNode* OSnLMNodeMatrixCon::cloneExprNode()
{
    std::ostringstream outStr;
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, "cloning an OSnLMNodeMatrixCon");
#endif
    ExprNode *nlNodePoint;
    nlNodePoint = new OSnLMNodeMatrixCon();
#ifndef NDEBUG
    outStr.str( std::string() );
    outStr.clear();
    outStr << "Allocate memory at address " << nlNodePoint << std::endl;
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, outStr.str());
#endif


    ((OSnLMNodeMatrixCon*)nlNodePoint)->idx = idx;
//    CLONE_CHILDREN;
        if (inumberOfChildren > 0)                              
        {                                                       
            if (nlNodePoint->m_mChildren == NULL)               
                nlNodePoint->m_mChildren                        
                    = new ExprNode*[inumberOfChildren];         
            for (unsigned int i=0; i < inumberOfChildren; i++)  
            {                                                   
                nlNodePoint->m_mChildren[i]                     
                    = this->m_mChildren[i]->cloneExprNode();    
            }                                                   
            nlNodePoint->inumberOfChildren = inumberOfChildren;
        }                                                       
    return nlNodePoint;
}//end OSnLMNodeMatrixCon::cloneExprNode


bool OSnLMNodeMatrixCon::IsEqual(OSnLMNodeMatrixCon *that)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, "Start comparing in OSnLMNodeMatrixCon");
#endif
    if (this == NULL)
    {
        if (that == NULL)
            return true;
        else
        {
#ifndef NDEBUG
            osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, 
                "First object is NULL, second is not");
#endif
            return false;
        }
    }
    else
    {
        if (that == NULL)
        {
#ifndef NDEBUG
            osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, 
                "Second object is NULL, first is not");
#endif
            return false;
        }
        else
        {
            if (this->inodeInt != that->inodeInt)
                return false;
            if (this->inodeKind != that->inodeKind)
                return false;
            if (this->inumberOfChildren != that->inumberOfChildren)
                return false;

            if (this->idx != that->idx)
                return false;

            for (unsigned int i = 0; i < this->inumberOfChildren; i++)
                if (!this->m_mChildren[i]->IsEqual(that->m_mChildren[i]))
                    return false;

            return true;
        }
    }
}//OSnLMNodeMatrixCon::IsEqual



//
//OSnLCNode methods
//

OSnLCNode::OSnLCNode():
    ScalarNode()
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, "inside OSnLCNode constructor");
#endif
}//end OSnLCNode

OSnLCNode::~OSnLCNode()
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, "inside OSnLCNode destructor");
#endif
}//end ~OSnLCNode


OSnLCNode* OSnLCNode::createExpressionTreeFromPrefix(std::vector<ExprNode*> nlNodeVec)
{
    std::vector<ExprNode*> stackVec;
    int kount =  nlNodeVec.size() - 1;
    while(kount >= 0)
    {
        int numkids        = nlNodeVec[kount]->inumberOfChildren;

        if(numkids > 0)
        {
            for(int i = 0; i < numkids; i++)
            {
                nlNodeVec[kount]->m_mChildren[i] = stackVec.back();
                stackVec.pop_back();
            }
        }
        stackVec.push_back( nlNodeVec[kount]);
        kount--;
    }
    stackVec.clear();
    return (OSnLCNode*)nlNodeVec[ 0];
}//end createExpressionTreeFromPrefix

#if 0
OSnLCNode* OSnLCNode::createExpressionTreeFromPostfix(std::vector<ExprNode*> nlNodeVec)
{
    std::vector<ExprNode*> stackVec;

    int kount =  0;
    while(kount <= nlNodeVec.size() - 1)
    {
       int numkids = nlNodeVec[kount]->inumberOfChildren;
       if (numkids  > 0)
        {
            for(int i = numkids - 1; i >= 0;  i--)
            {
                nlNodeVec[kount]->m_mChildren[i] = (OSnLNode*)stackVec.back();
                stackVec.pop_back();
            }
        }
        stackVec.push_back( nlNodeVec[kount]);
        kount++;
    }
    stackVec.clear();
    return (OSnLCNode*)nlNodeVec[ kount - 1];
}//end createExpressionTreeFromPostfix
#endif

#if 0
std::vector<ExprNode*> OSnLCNode::getPrefixFromExpressionTree()
{
    std::vector<ExprNode*> prefixVector;
    return preOrderOSnLNodeTraversal( &prefixVector);
}//getPrefixFromExpressionTree

std::vector<ExprNode*> OSnLCNode::preOrderOSnLNodeTraversal( std::vector<ExprNode*> *prefixVector)
{
    (*prefixVector).push_back( (OSnLCNode*)this);
    if(inumberOfChildren > 0)
    {
        for(unsigned int i = 0; i < inumberOfChildren; i++)
            m_mChildren[i]->preOrderOSnLNodeTraversal( prefixVector);
    }
    return *prefixVector;
}//end preOrderOSnLNodeTraversal

std::vector<ExprNode*> OSnLCNode::getPostfixFromExpressionTree( )
{
    std::vector<ExprNode*> postfixVector;
std::cout << "get postfix from an OSnLCNode" << std::endl;
    return postOrderOSnLNodeTraversal( &postfixVector);
}//getPostfixFromExpressionTree


std::vector<ExprNode*> OSnLCNode::postOrderOSnLNodeTraversal( std::vector<ExprNode*> *postfixVector)
{
    if(inumberOfChildren > 0)
    {
        unsigned int i;
        for(i = 0; i < inumberOfChildren; i++)
            m_mChildren[i]->postOrderOSnLNodeTraversal( postfixVector);
    }
    (*postfixVector).push_back( (OSnLCNode*)this);
    return *postfixVector;
}//end postOrderOSnLNodeTraversal()
#endif

bool OSnLCNode::IsEqual(OSnLCNode *that)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, "Start comparing in OSnLCNode");
#endif
    if (this == NULL)
    {
        if (that == NULL)
            return true;
        else
        {
#ifndef NDEBUG
            osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, 
                "First object is NULL, second is not");
#endif
            return false;
        }
    }
    else
    {
        if (that == NULL)
        {
#ifndef NDEBUG
            osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, 
                "Second object is NULL, first is not");
#endif
            return false;
        }
        else
        {
            if (this->inumberOfChildren != that->inumberOfChildren)
                return false;
            if (this->inodeInt != that->inodeInt)
                return false;
            if (this->inodeKind != that->inodeKind)
                return false;

            for (unsigned int i = 0; i < this->inumberOfChildren; i++)
                if (!this->m_mChildren[i]->IsEqual(that->m_mChildren[i]))
                    return false;

            return true;
        }
    }
}//OSnLCNode::IsEqual


// OSnLCNodeCreate Methods
OSnLCNodeCreate::OSnLCNodeCreate()
{
    inumberOfChildren = 2;
    m_mChildren = new ExprNode*[2];
    m_mChildren[ 0] = NULL;
    m_mChildren[ 1] = NULL;
    inodeInt = OS_COMPLEX_CREATE;
    inodeKind = 2;
}//end OSnLCNodeCreate

OSnLCNodeCreate::~OSnLCNodeCreate()
{
    std::ostringstream outStr;
#ifndef NDEBUG
    outStr << "inside OSnLCNodeCreate destructor" << endl;
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, outStr.str());
#endif
}//end ~OSnLCNodeCreate

std::string OSnLCNodeCreate::getTokenName()
{
    return "createComplex";
}// end OSnLCNodeCreate::getTokenName()

std::complex<double> OSnLCNodeCreate::calculateFunction_C(double *x)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSExpressionTree, 
                      ENUM_OUTPUT_LEVEL_trace, "in OSnLCNodePlus::calculateFunction");
#endif

    m_mChildren[0]->calculateFunction(x);
    m_mChildren[1]->calculateFunction(x);

    std::complex<double> m_dFunctionValue   ( ((OSnLNode*) m_mChildren[0])->m_dFunctionValue, 
                                              ((OSnLNode*) m_mChildren[1])->m_dFunctionValue);

    return m_dFunctionValue;
}// end OSnLCNodeCreate::calculate

ExprNode* OSnLCNodeCreate::cloneExprNode()
{
    std::ostringstream outStr;
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, "cloning an OSnLCNodeCreate");
#endif
    ExprNode *nlNodePoint;
    nlNodePoint = new OSnLCNodeCreate();
#ifndef NDEBUG
    outStr.str( std::string() );
    outStr.clear();
    outStr << "Allocate memory at address " << nlNodePoint << std::endl;
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, outStr.str());
#endif
//    CLONE_CHILDREN;
        if (inumberOfChildren > 0)                              
        {                                                       
            if (nlNodePoint->m_mChildren == NULL)               
                nlNodePoint->m_mChildren                        
                    = new ExprNode*[inumberOfChildren];         
            for (unsigned int i=0; i < inumberOfChildren; i++)  
            {                                                   
                nlNodePoint->m_mChildren[i]                     
                    = this->m_mChildren[i]->cloneExprNode();    
            }                                                   
            nlNodePoint->inumberOfChildren = inumberOfChildren;
        }                                                       
    return nlNodePoint;
}//end OSnLCNodeCreate::cloneExprNode


// OSnLCNodePlus Methods
OSnLCNodePlus::OSnLCNodePlus()
{
    inumberOfChildren = 2;
    m_mChildren = new ExprNode*[2];
    m_mChildren[ 0] = NULL;
    m_mChildren[ 1] = NULL;
    inodeInt = OS_COMPLEX_PLUS;
    inodeKind = 2;
}//end OSnLCNodePlus


OSnLCNodePlus::~OSnLCNodePlus()
{
    std::ostringstream outStr;
#ifndef NDEBUG
    outStr << "inside OSnLCNodePlus destructor" << endl;
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, outStr.str());
#endif
}//end ~OSnLCNodePlus

std::string OSnLCNodePlus::getTokenName()
{
    return "complexPlus";
}// end OSnLNodePlus::getTokenName()

std::complex<double> OSnLCNodePlus::calculateFunction_C(double *x)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSExpressionTree, 
                      ENUM_OUTPUT_LEVEL_trace, "in OSnLCNodePlus::calculateFunction");
#endif
    m_dFunctionValue = 0;

    for (int i=0; i<2; i++)
    {
        if (m_mChildren[i]->inodeKind == 1)
        {
            m_mChildren[i]->calculateFunction(x);
            m_dFunctionValue += ((OSnLNode*)m_mChildren[i])->m_dFunctionValue;
        }
        else
        {
            m_mChildren[i]->calculateFunction_C(x);
            m_dFunctionValue += ((OSnLCNode*)m_mChildren[i])->m_dFunctionValue;
        }
    }
    return m_dFunctionValue;
}// end OSnLCNodePlus::calculate

ExprNode* OSnLCNodePlus::cloneExprNode()
{
    std::ostringstream outStr;
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, "cloning an OSnLCNodePlus");
#endif
    ExprNode *nlNodePoint;
    nlNodePoint = new OSnLCNodePlus();
#ifndef NDEBUG
    outStr.str( std::string() );
    outStr.clear();
    outStr << "Allocate memory at address " << nlNodePoint << std::endl;
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, outStr.str());
#endif
//    CLONE_CHILDREN;
        if (inumberOfChildren > 0)                              
        {                                                       
            if (nlNodePoint->m_mChildren == NULL)               
                nlNodePoint->m_mChildren                        
                    = new ExprNode*[inumberOfChildren];         
            for (unsigned int i=0; i < inumberOfChildren; i++)  
            {                                                   
                nlNodePoint->m_mChildren[i]                     
                    = this->m_mChildren[i]->cloneExprNode();    
            }                                                   
            nlNodePoint->inumberOfChildren = inumberOfChildren;
        }                                                       
    return nlNodePoint;
}//end OSnLCNodePlus::cloneExprNode


// OSnLCNodeMinus Methods
OSnLCNodeMinus::OSnLCNodeMinus()
{
    inumberOfChildren = 2;
    m_mChildren = new ExprNode*[2];
    m_mChildren[ 0] = NULL;
    m_mChildren[ 1] = NULL;
    inodeInt = OS_COMPLEX_MINUS;
    inodeKind = 2;
}//end OSnLCNodeMinus


OSnLCNodeMinus::~OSnLCNodeMinus()
{
    std::ostringstream outStr;
#ifndef NDEBUG
    outStr << "inside OSnLCNodeMinus destructor" << endl;
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, outStr.str());
#endif
}//end ~OSnLCNodeMinus

std::string OSnLCNodeMinus::getTokenName()
{
    return "complexMinus";
}// end OSnLCNodeMinus::getTokenName()

std::complex<double> OSnLCNodeMinus::calculateFunction_C(double *x)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSExpressionTree, 
                      ENUM_OUTPUT_LEVEL_trace, "in OSnLCNodeMinus::calculateFunction");
#endif
    if (m_mChildren[0]->inodeKind == 1)
    {
        m_mChildren[0]->calculateFunction(x);
        m_dFunctionValue = ((OSnLNode*)m_mChildren[0])->m_dFunctionValue;
    }
    else
    {
        m_mChildren[0]->calculateFunction_C(x);
        m_dFunctionValue = ((OSnLCNode*)m_mChildren[0])->m_dFunctionValue;
    }

    if (m_mChildren[1]->inodeKind == 1)
    {
        m_mChildren[1]->calculateFunction(x);
        m_dFunctionValue -= ((OSnLNode*)m_mChildren[1])->m_dFunctionValue;
    }
    else
    {
        m_mChildren[1]->calculateFunction_C(x);
        m_dFunctionValue -= ((OSnLCNode*)m_mChildren[1])->m_dFunctionValue;
    }

    return m_dFunctionValue;
}// end OSnLCNodeMinus::calculate

ExprNode* OSnLCNodeMinus::cloneExprNode()
{
    std::ostringstream outStr;
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, "cloning an OSnLCNodeMinus");
#endif
    ExprNode *nlNodePoint;
    nlNodePoint = new OSnLCNodeMinus();
#ifndef NDEBUG
    outStr.str( std::string() );
    outStr.clear();
    outStr << "Allocate memory at address " << nlNodePoint << std::endl;
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, outStr.str());
#endif
//    CLONE_CHILDREN;
        if (inumberOfChildren > 0)                              
        {                                                       
            if (nlNodePoint->m_mChildren == NULL)               
                nlNodePoint->m_mChildren                        
                    = new ExprNode*[inumberOfChildren];         
            for (unsigned int i=0; i < inumberOfChildren; i++)  
            {                                                   
                nlNodePoint->m_mChildren[i]                     
                    = this->m_mChildren[i]->cloneExprNode();    
            }                                                   
            nlNodePoint->inumberOfChildren = inumberOfChildren;
        }                                                       
    return nlNodePoint;
}//end OSnLCNodeMinus::cloneExprNode


// OSnLCNodeNegate Methods
OSnLCNodeNegate::OSnLCNodeNegate()
{
    inumberOfChildren = 1;
    m_mChildren = new ExprNode*[1];
    m_mChildren[ 0] = NULL;
    inodeInt = OS_COMPLEX_NEGATE;
    inodeKind = 2;
}//end OSnLCNodeNegate

OSnLCNodeNegate::~OSnLCNodeNegate()
{
    std::ostringstream outStr;
#ifndef NDEBUG
    outStr << "inside OSnLCNodeNegate destructor" << endl;
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, outStr.str());
#endif
}//end ~OSnLCNodeNegate

std::string OSnLCNodeNegate::getTokenName()
{
    return "complexNegate";
}// end OSnLCNodeNegate::getTokenName()

std::complex<double> OSnLCNodeNegate::calculateFunction_C(double *x)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSExpressionTree, 
                      ENUM_OUTPUT_LEVEL_trace, "in OSnLCNodeNegate::calculateFunction");
#endif
    if (m_mChildren[0]->inodeKind == 1)
    {
        m_mChildren[0]->calculateFunction(x);
        m_dFunctionValue = -((OSnLNode*)m_mChildren[0])->m_dFunctionValue;
    }
    else
    {
        m_mChildren[0]->calculateFunction_C(x);
        m_dFunctionValue = -((OSnLCNode*)m_mChildren[0])->m_dFunctionValue;
    }

    return m_dFunctionValue;
}// end OSnLCNodeNegate::calculate

ExprNode* OSnLCNodeNegate::cloneExprNode()
{
    std::ostringstream outStr;
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, "cloning an OSnLCNodeNegate");
#endif
    ExprNode *nlNodePoint;
    nlNodePoint = new OSnLCNodeNegate();
#ifndef NDEBUG
    outStr.str( std::string() );
    outStr.clear();
    outStr << "Allocate memory at address " << nlNodePoint << std::endl;
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, outStr.str());
#endif
//    CLONE_CHILDREN;
        if (inumberOfChildren > 0)                              
        {                                                       
            if (nlNodePoint->m_mChildren == NULL)               
                nlNodePoint->m_mChildren                        
                    = new ExprNode*[inumberOfChildren];         
            for (unsigned int i=0; i < inumberOfChildren; i++)  
            {                                                   
                nlNodePoint->m_mChildren[i]                     
                    = this->m_mChildren[i]->cloneExprNode();    
            }                                                   
            nlNodePoint->inumberOfChildren = inumberOfChildren;
        }                                                       
    return nlNodePoint;
}//end OSnLCNodeNegate::cloneExprNode


// OSnLCNodeConjugate Methods
OSnLCNodeConjugate::OSnLCNodeConjugate()
{
    inumberOfChildren = 1;
    m_mChildren = new ExprNode*[1];
    m_mChildren[ 0] = NULL;
    inodeInt = OS_COMPLEX_CONJUGATE;
    inodeKind = 2;
}//end OSnLCNodeConjugate


OSnLCNodeConjugate::~OSnLCNodeConjugate()
{
    std::ostringstream outStr;
#ifndef NDEBUG
    outStr << "inside OSnLCNodeConjugate destructor" << endl;
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, outStr.str());
#endif
}//end ~OSnLCNodeConjugate

std::string OSnLCNodeConjugate::getTokenName()
{
    return "complexConjugate";
}// end OSnLCNodeConjugate::getTokenName()

std::complex<double> OSnLCNodeConjugate::calculateFunction_C(double *x)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSExpressionTree, 
                      ENUM_OUTPUT_LEVEL_trace, "in OSnLCNodeMinus::calculateFunction");
#endif
    if (m_mChildren[0]->inodeKind == 1)
    {
        m_mChildren[0]->calculateFunction(x);
        m_dFunctionValue = ((OSnLNode*)m_mChildren[0])->m_dFunctionValue;
    }
    else
    {
        m_mChildren[0]->calculateFunction_C(x);
        m_dFunctionValue = std::conj( ((OSnLCNode*)m_mChildren[0])->m_dFunctionValue );
    }

    return m_dFunctionValue;
}// end OSnLCNodeConjugate::calculate

ExprNode* OSnLCNodeConjugate::cloneExprNode()
{
    std::ostringstream outStr;
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, "cloning an OSnLCNodeConjugate");
#endif
    ExprNode *nlNodePoint;
    nlNodePoint = new OSnLCNodeConjugate();
#ifndef NDEBUG
    outStr.str( std::string() );
    outStr.clear();
    outStr << "Allocate memory at address " << nlNodePoint << std::endl;
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, outStr.str());
#endif
//    CLONE_CHILDREN;
        if (inumberOfChildren > 0)                              
        {                                                       
            if (nlNodePoint->m_mChildren == NULL)               
                nlNodePoint->m_mChildren                        
                    = new ExprNode*[inumberOfChildren];         
            for (unsigned int i=0; i < inumberOfChildren; i++)  
            {                                                   
                nlNodePoint->m_mChildren[i]                     
                    = this->m_mChildren[i]->cloneExprNode();    
            }                                                   
            nlNodePoint->inumberOfChildren = inumberOfChildren;
        }                                                       
    return nlNodePoint;
}//end OSnLCNodeConjugate::cloneExprNode


// OSnLCNodeSum Methods
OSnLCNodeSum::OSnLCNodeSum()
{
    inumberOfChildren = 0;
    inodeInt = OS_COMPLEX_SUM;
    inodeKind = 2;
}//end OSnLCNodeSum

OSnLCNodeSum::~OSnLCNodeSum()
{
    std::ostringstream outStr;
#ifndef NDEBUG
    outStr << "inside OSnLCNodeSum destructor" << endl;
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, outStr.str());
#endif
}//end ~OSnLCNodeSum

std::string OSnLCNodeSum::getTokenName()
{
    return "complexSum";
}// end OSnLCNodeSum::getTokenName()


std::complex<double> OSnLCNodeSum::calculateFunction_C(double *x)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSExpressionTree, 
                      ENUM_OUTPUT_LEVEL_trace, "in OSnLCNodeSum::calculateFunction");
#endif
    //m_dFunctionValue[0] = m_dFunctionValue[1] = 0;
    m_dFunctionValue = 0;

    for (unsigned int i=0; i < inumberOfChildren; i++)
    {
        if (m_mChildren[i]->inodeKind == 1)
        {
            m_mChildren[i]->calculateFunction(x);
            m_dFunctionValue += ((OSnLNode*)m_mChildren[i])->m_dFunctionValue;
        }
        else
        {
            m_mChildren[i]->calculateFunction_C(x);
            m_dFunctionValue += ((OSnLCNode*)m_mChildren[i])->m_dFunctionValue;
        }
    }
    return m_dFunctionValue;
}// end OSnLCNodeSum::calculate

ExprNode* OSnLCNodeSum::cloneExprNode()
{
    std::ostringstream outStr;
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, "cloning an OSnLCNodeSum");
#endif
    ExprNode *nlNodePoint;
    nlNodePoint = new OSnLCNodeSum();
#ifndef NDEBUG
    outStr.str( std::string() );
    outStr.clear();
    outStr << "Allocate memory at address " << nlNodePoint << std::endl;
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, outStr.str());
#endif
//    CLONE_CHILDREN;
        if (inumberOfChildren > 0)                              
        {                                                       
            if (nlNodePoint->m_mChildren == NULL)               
                nlNodePoint->m_mChildren                        
                    = new ExprNode*[inumberOfChildren];         
            for (unsigned int i=0; i < inumberOfChildren; i++)  
            {                                                   
                nlNodePoint->m_mChildren[i]                     
                    = this->m_mChildren[i]->cloneExprNode();    
            }                                                   
            nlNodePoint->inumberOfChildren = inumberOfChildren;

        }                                                       
    return nlNodePoint;
}//end OSnLCNodeSum::cloneExprNode


// OSnLCNodeTimes Methods
OSnLCNodeTimes::OSnLCNodeTimes()
{
    inumberOfChildren = 2;
    m_mChildren = new ExprNode*[2];
    m_mChildren[ 0] = NULL;
    m_mChildren[ 1] = NULL;
    inodeInt = OS_COMPLEX_TIMES;
    inodeKind = 2;
}//end OSnLCNodeTimes


OSnLCNodeTimes::~OSnLCNodeTimes()
{
    std::ostringstream outStr;
#ifndef NDEBUG
    outStr << "inside OSnLCNodeTimes destructor" << endl;
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, outStr.str());
#endif
}//end ~OSnLCNodeTimes

std::string OSnLCNodeTimes::getTokenName()
{
    return "complexTimes";
}// end OSnLCNodeTimes::getTokenName()

std::complex<double> OSnLCNodeTimes::calculateFunction_C(double *x)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSExpressionTree, 
                      ENUM_OUTPUT_LEVEL_trace, "in OSnLCNodeTimes::calculateFunction");
#endif
//    m_dFunctionValue[0] = m_dFunctionValue[1] = 0;
    m_dFunctionValue = 1.0;
    std::complex <double> temp;

    for (int i=0; i < 1; i++)
    {
        if (m_mChildren[i]->inodeKind == 1)
        {
            m_mChildren[i]->calculateFunction(x);
            temp = ((OSnLNode*)m_mChildren[i])->m_dFunctionValue;
        }
        else
        {
            m_mChildren[i]->calculateFunction_C(x);
            temp = ((OSnLCNode*)m_mChildren[i])->m_dFunctionValue;
        }
        m_dFunctionValue *= temp;
    }

    return m_dFunctionValue;
}// end OSnLCNodeTimes::calculate

ExprNode* OSnLCNodeTimes::cloneExprNode()
{
    std::ostringstream outStr;
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, "cloning an OSnLCNodeTimes");
#endif
    ExprNode *nlNodePoint;
    nlNodePoint = new OSnLCNodeTimes();
#ifndef NDEBUG
    outStr.str( std::string() );
    outStr.clear();
    outStr << "Allocate memory at address " << nlNodePoint << std::endl;
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, outStr.str());
#endif
//    CLONE_CHILDREN;
        if (inumberOfChildren > 0)                              
        {                                                       
            if (nlNodePoint->m_mChildren == NULL)               
                nlNodePoint->m_mChildren                        
                    = new ExprNode*[inumberOfChildren];         
            for (unsigned int i=0; i < inumberOfChildren; i++)  
            {                                                   
                nlNodePoint->m_mChildren[i]                     
                    = this->m_mChildren[i]->cloneExprNode();    
            }                                                   
            nlNodePoint->inumberOfChildren = inumberOfChildren;
        }                                                       
    return nlNodePoint;
}//end OSnLCNodeTimes::cloneExprNode


// OSnLCNodeSquare Methods
OSnLCNodeSquare::OSnLCNodeSquare()
{
    inumberOfChildren = 1;
    m_mChildren = new ExprNode*[1];
    m_mChildren[ 0] = NULL;
    inodeInt = OS_COMPLEX_SQUARE;
    inodeKind = 2;
}//end OSnLCNodeSquare

OSnLCNodeSquare::~OSnLCNodeSquare()
{
    std::ostringstream outStr;
#ifndef NDEBUG
    outStr << "inside OSnLCNodeSquare destructor" << endl;
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, outStr.str());
#endif
}//end ~OSnLCNodeSquare

std::string OSnLCNodeSquare::getTokenName()
{
    return "complexSquare";
}// end OSnLCNodeSquare::getTokenName()

std::complex<double> OSnLCNodeSquare::calculateFunction_C(double *x)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSExpressionTree, 
                      ENUM_OUTPUT_LEVEL_trace, "in ExprNode::calculateFunction");
#endif
    std::complex <double> temp;

    if (m_mChildren[0]->inodeKind == 1)
    {
        m_mChildren[0]->calculateFunction(x);
        temp = ((OSnLNode*)m_mChildren[0])->m_dFunctionValue;
    }
    else
    {
        m_mChildren[0]->calculateFunction_C(x);
        temp = ((OSnLCNode*)m_mChildren[0])->m_dFunctionValue;
    }
    m_dFunctionValue = temp*temp;

    return m_dFunctionValue;
}// end OSnLCNodeSquare::calculate

ExprNode* OSnLCNodeSquare::cloneExprNode()
{
    std::ostringstream outStr;
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, "cloning an OSnLCNodeSquare");
#endif
    ExprNode *nlNodePoint;
    nlNodePoint = new OSnLCNodeSquare();
#ifndef NDEBUG
    outStr.str( std::string() );
    outStr.clear();
    outStr << "Allocate memory at address " << nlNodePoint << std::endl;
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, outStr.str());
#endif
//    CLONE_CHILDREN;
        if (inumberOfChildren > 0)                              
        {                                                       
            if (nlNodePoint->m_mChildren == NULL)               
                nlNodePoint->m_mChildren                        
                    = new ExprNode*[inumberOfChildren];         
            for (unsigned int i=0; i < inumberOfChildren; i++)  
            {                                                   
                nlNodePoint->m_mChildren[i]                     
                    = this->m_mChildren[i]->cloneExprNode();    
            }                                                   
            nlNodePoint->inumberOfChildren = inumberOfChildren;
        }                                                       
    return nlNodePoint;
}//end OSnLCNodeSquare::cloneExprNode


// OSnLCNodeNumber Methods
OSnLCNodeNumber::OSnLCNodeNumber() :
    value(0.0, 0.0),
    id(-1),
    realTime(ENUM_COMPLEX_NUMBER_PART_none),
    random(ENUM_COMPLEX_NUMBER_PART_none)
{
    inumberOfChildren = 0;
    inodeInt = OS_COMPLEX_NUMBER;
    inodeKind = 2;
}//end OSnLCNodeNumber

OSnLCNodeNumber::~OSnLCNodeNumber()
{
    std::ostringstream outStr;
#ifndef NDEBUG
    outStr << "inside OSnLCNodeNumber destructor" << endl;
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, outStr.str());
#endif
}//end ~OSnLCNodeNumber

std::string OSnLCNodeNumber::getTokenName()
{
    return "complexNumber";
}// end OSnLCNodeNumber::getTokenName()

std::string OSnLCNodeNumber::getNonlinearExpressionInXML()
{
    ostringstream outStr, logStr;
    outStr << "<";
    outStr << this->getTokenName();
#ifndef NDEBUG
    logStr << "nonlinear node " << this->getTokenName() << endl;
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, logStr.str());
#endif
    outStr << " Re=\"" << os_dtoa_format(value.real()) << "\""
           << " Im=\"" << os_dtoa_format(value.imag()) << "\"";
    outStr << "/>";
    return outStr.str();
}//getNonlinearExpressionInXML()

std::complex<double> OSnLCNodeNumber::calculateFunction_C(double *x)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSExpressionTree, 
                      ENUM_OUTPUT_LEVEL_trace, "in OSnLCNodeNumber::calculateFunction");
#endif
    m_dFunctionValue = value;
    return m_dFunctionValue;
}// end OSnLCNodeNumber::calculate

std::complex<double> OSnLCNodeNumber::getValue()
{
std::cout << "this value = " << this->value << std::endl;
std::cout << "value = " << value << std::endl;
    return value;
}// end of OSnLCNodeNumber::getValue

void OSnLCNodeNumber::setValue(double Re, double Im)
{
    ostringstream outStr;
#ifndef NDEBUG
    outStr << "in OSnLCNodeNumber::setValue; Re=" << Re << "; Im=" << Im;
#endif
    std::complex<double> temp(Re, Im);
    this->value = temp;
#ifndef NDEBUG
    outStr << "; temp=" << temp;
    outStr << "; value=" << value;
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSExpressionTree, 
                      ENUM_OUTPUT_LEVEL_trace, outStr.str());
#endif

}// end of OSnLCNodeNumber::setValue(double Re, double Im)

void OSnLCNodeNumber::setValue(std::complex<double> z)
{
    ostringstream outStr;
#ifndef NDEBUG
    outStr << "in OSnLCNodeNumber::setValue; z=" << z;
#endif
    std::complex<double> temp(z);
    this->value = temp;
#ifndef NDEBUG
    outStr << "; temp=" << temp;
    outStr << "; value=" << value;
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSExpressionTree, 
                      ENUM_OUTPUT_LEVEL_trace, outStr.str());
#endif
}// end of OSnLCNodeNumber::setValue(std::complex<double> z)


ExprNode* OSnLCNodeNumber::cloneExprNode()
{
    std::ostringstream outStr;
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, "cloning an OSnLCNodeNumber");
#endif
    ExprNode *nlNodePoint;
    nlNodePoint = new OSnLCNodeNumber();
#ifndef NDEBUG
    outStr.str( std::string() );
    outStr.clear();
    outStr << "Allocate memory at address " << nlNodePoint << std::endl;
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, outStr.str());
#endif
    ((OSnLCNodeNumber*)nlNodePoint)->value = value;
//    CLONE_CHILDREN;
        if (inumberOfChildren > 0)                              
        {                                                       
            if (nlNodePoint->m_mChildren == NULL)               
                nlNodePoint->m_mChildren                        
                    = new ExprNode*[inumberOfChildren];         
            for (unsigned int i=0; i < inumberOfChildren; i++)  
            {                                                   
                nlNodePoint->m_mChildren[i]                     
                    = this->m_mChildren[i]->cloneExprNode();    
            }                                                   
            nlNodePoint->inumberOfChildren = inumberOfChildren;
        }                                                       
    return nlNodePoint;

}//end OSnLCNodeNumber::cloneExprNode


