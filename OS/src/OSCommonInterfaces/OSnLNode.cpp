/* $Id$ */
/** @file OSnLNode.cpp
 *
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

#include "OSnLNode.h"
#include "OSErrorClass.h"
#include "OSParameters.h"
#include "OSMathUtil.h"
#include "OSOutput.h"

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



//
//const std::string msnodeNames[] = {
//    /*1--*/"plus", "sum", "minus", "negate", "times", "divide",
//    "quotient", "rem", "power", "product",
//    /*2--*/"abs", "floor", "ceiling", "percent", "square", "squareRoot", "ln", "log", "log10", "exp",
//    "factorial", "combination", "permutation", "gcd", "lcm", "roundToInt", "round", "truncate", "sign", "rand","gammaFn", "gammaLn",
//    /*3--*/"sin", "cos", "tan", "arcsin", "arccos", "arctan", "sinh", "cosh", "tanh", "arcsinh", "arccosh", "arctanh",
//    "cot", "coth", "arccot", "arccoth", "sec", "sech", "arcsec", "arcsech", "csc", "csch", "arccsc", "arccsch",
//    /*4--*/"mean", "geometricMean", "harmonicMean", "trimMean", "count", "median", "firstQuartile", "thirdQuartile", "mode", "min", "max",
//    "percentile", "large", "small", "range", "interQuantileRange", "absdev", "stddev", "variance", "cv", "skewness", "kurtosis",
//    "covariance", "correlation", "pearsonCorrelation", "rankCorrelation", "autoCorrelation1", "autoCorrelation", "npv", "irr",
//    /*"empiricalDiscreteDist", "empiricalDiscreteCum", */"discreteUniformDist", "discreteUniformCum", "discreteUniformInv",
//    "bernoulliDist", "bernoulliCum", "bernoulliInv", "binomialDist", "binomialCum", "binomialInv", "multinomialDist", "multinomialCum", "multinomialInv",
//    "hypergeometricDist", "hypergeometricCum", "hypergeometricInv", "poissonDist", "poissonCum", "poissonInv",
//    "geometricDist", "geometricCum", "geometricInv", "negativeBinomialDist", "negativeBinomialCum", "negativeBinomialInv",
//    /*"empiricalContinousDist", "empiricalContinuousCum",*/ "uniformDist", "uniformCum", "uniformInv",
//    "normalDist", "normalCum", "normalInv", "stdNormalDist", "stdNormalCum", "stdNormalInv", "bivariateNormalDist", "bivariateNormalCum",
//    "exponentialDist", "exponentialCum", "exponentialInv", "weibullDist", "weibullCum", "weibullInv", "erlangDist", "erlangCum", "erlangInv",
//    "gammaDist", "gammaCum", "gammaInv", "betaDist", "betaCum", "betaInv", "betaGeneralDist", "betaGeneralCum", "betaGeneralInv",
//    "lognormalDist", "lognormalCum", "lognormalInv", "cauchyDist", "cauchyCum", "cauchyInv", "tDist", "tCum", "tInv",
//    "chiSquareDist", "chiSquareCum", "chiSquareInv", "fDist", "fCum", "fInv", "logisticDist", "logisticCum", "logisticInv",
//    "logLogisticDist", "logLogisticCum", "logLogisticInv", "logarithmicDist", "logarithmicCum", "logarithmicInv",
//    "paretoDist", "paretoCum", "paretoDist", "rayleighDist", "rayleighCum", "rayleighInv", "pertDist", "pertCum", "pertDist",
//    "triangularDist", "triangularCum", "triangularInv", "unitNormalLinearLoss", erf
//    /*5--*/"number", "identifier", "PI", "E", "INF", "EPS", "TRUE", "FALSE", "EULERGAMMA", "NAN",
//    /*6--*/"variable", "objective", "constraint", "parameter",
//    /*7--*/"if", "lt", "leq", "gt", "geq", "eq", "neq", "and", "or", "xor", "implies", "not",
//    "forAll", "exists", "logicCount", "allDiff", /*"allDisjoint",*/ "atMost", "atLeast", "exactly",
//    "inSet", "inRealSet", "inPositiveRealSet", "inNonnegativeRealSet", "inIntegerSet", "inPositiveIntegerSet","inNonnegativeIntegerSet",
//    /*8--*/
//    /*9--*/"qTerm", "quadratic", "sim", "simInput", "simOutput", "userF", "arg", "xPath", "xPathIndex",
//    "nodeRef", "arcRef", "complements", /*"prob",*/
//};




//const int m_miNodeIndexes[] = {
//    /*1--*/1001, 1002, 1003, 1004, 1005, 1006,
//    1007, 1008, 1009, 1010,
//    /*2--*/2001, 2002, 2003, 2004, 2005, 2006, 2007, 2008, 2009, 2010,
//    2011, 2012, 2013, 2014, 2015, 2016, 2017, 2018, 2019, 2020, 2021, 2022,
//    /*3--*/3001, 3002, 3003, 3004, 3005, 3006, 3007, 3008, 3009, 3010, 3011, 3012,
//    3013, 3014, 3015, 3016, 3017, 3018, 3019, 3020, 3021, 3022, 3023, 3024,
//    /*4--*/4001, 4002, 4003, 4004, 4005, 4006, 4007, 4008, 4009, 4010, 4011,
//    4012, 4013, 4014, 4015, 4016, 4017, 4018, 4019, 4020, 4021, 4022,
//    4023, 4024, 4025, 4026, 4027, 4028, 4029, 4030,
//    /*4101, 4102, */4111, 4112, 4113,
//    4121, 4122, 4123, 4131, 4132, 4133, 4141, 4142, 4143,
//    4151, 4152, 4153, 4161, 4162, 4163,
//    4171, 4172, 4173, 4181, 4182, 4183,
//    /*4401, 4402,*/ 4411, 4412, 4413,
//    4421, 4422, 4423, 4431, 4432, 4433, 4441, 4442,
//    4451, 4452, 4453, 4461, 4462, 4463, 4471, 4472, 4473,
//    4481, 4482, 4483, 4491, 4492, 4493, 4501, 4502, 4503,
//    4511, 4512, 4513, 4521, 4522, 4523, 4531, 4532, 4533,
//    4541, 4542, 4543, 4551, 4552, 4553, 4561, 4562, 4563,
//    4571, 4572, 4573, 4581, 4582, 4583,
//    4591, 4592, 4593, 4601, 4602, 4603, 4611, 4612, 4613,
//    4621, 4622, 4623, 4624,4625
//    /*5--*/5001, 5002, 5003, 5004, 5005, 5006, 5007, 5008, 5009, 5010,
//    /*6--*/6001, 6002, 6003, 6004,
//    /*7--*/7001, 7002, 7003, 7004, 7005, 7006, 7007, 7008, 7009, 7010, 7011, 7012,
//    7013, 7014, 7015, 7016, /*7017,*/ 7018, 7019, 7020,
//    7021, 7022, 7023, 7024, 7025, 7026, 7027,
//    /*8--*/
//    /*9--*/9001, 9002, 9003, 9004, 9005, 9006, 9007, 9008, 9009,
//    9010, 9011, 9012, /*9013,*/
//};

//const int m_miNodeTypes[] = {
//    /*1--*/2, -1, 2, 1, 2, 2,
//    2, 2, 2, -1,
//    /*2--*/1, 1, 1, 1, 1, 1, 1, 2, 1, 1,
//    1, 2, 2, -1, -1, 1, 2, 2, 1, 1, 1, 1,
//    /*3--*/1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
//    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
//    /*4--*/-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
//    -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
//    -1, -1, -1, -1, -1, -1, -1, -1,
//    /*-1, -1, */2, 2, 2,
//    2, 2, 2, 3, 3, 3, -1, -1, -1,
//    4, 4, 4, 2, 2, 2,
//    2, 2, 2, 3, 3, 3,
//    /*-1, -1,*/ 3, 3, 3,
//    3, 3, 3, 1, 1, 1, 7, 7,
//    2, 2, 2, 4, 4, 4, 3, 3, 3,
//    3, 3, 3, 3, 3, 3, 5, 5, 5,
//    3, 3, 3, 3, 3, 3, 2, 2, 2,
//    2, 2, 2, 3, 3, 3, 3, 3, 3,
//    3, 3, 3, 3, 3, 3,
//    3, 3, 3, 2, 2, 2, 4, 4, 4,
//    4, 4, 4, 1,
//    /*5--*/0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
//    /*6--*/-1, -1, -1, 0,
//    /*7--*/3, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1,
//    -1, -1, -1, -1, /*-1,*/ -1, -1, -1,
//    -1, 1, 1, 1, 1, 1, 1
//    /*8--*/
//    /*9--*/-1, -1, -1, -1, -1, -1, 0, -1, -1,
//    -1, -1, 2, /*1,*/
//};


//
//ExprNode methods
//

ExprNode::ExprNode():
    inodeInt(-1),
    inodeType(0),
    inumberOfChildren( 0),
    inumberOfMatrixChildren( 0),
    m_mChildren(NULL),
    m_mMatrixChildren(NULL)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSExpressionTree, ENUM_OUTPUT_LEVEL_trace, "inside ExprNode constructor");
#endif
}//end ExprNode

ExprNode::~ExprNode()
{
#ifndef NDEBUG
    std::ostringstream outStr;
    outStr << "inside ExprNode destructor" << std::endl;
    outStr << "scalar kids = " <<  inumberOfChildren << std::endl;
    outStr << "matrix kids = " <<  inumberOfMatrixChildren << std::endl;
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSExpressionTree, ENUM_OUTPUT_LEVEL_trace, outStr.str());
#endif
    if (inumberOfChildren > 0 && m_mChildren != NULL)
    {
        for (int i=0; i<inumberOfChildren; i++)
        {
            if (m_mChildren[i] != NULL) 
                delete m_mChildren[i];
            m_mChildren[i] = NULL;
        }
        delete [] m_mChildren;
        m_mChildren = NULL;
        inumberOfChildren = 0;
    }
    else if (inumberOfChildren > 0 || m_mChildren != NULL)
        osoutput->OSPrint(ENUM_OUTPUT_AREA_OSExpressionTree, ENUM_OUTPUT_LEVEL_warning, "Warning: Possible memory leak");
        
    if (inumberOfMatrixChildren > 0 && m_mMatrixChildren != NULL)
    {
        for (int i=0; i<inumberOfMatrixChildren; i++)
        {
            if (m_mMatrixChildren[i] != NULL) 
                delete m_mMatrixChildren[i];
            m_mMatrixChildren[i] = NULL;
        }
        delete [] m_mMatrixChildren;
        m_mMatrixChildren = NULL;
        inumberOfMatrixChildren = 0;
    }
    else if (inumberOfMatrixChildren > 0 || m_mMatrixChildren != NULL)
        osoutput->OSPrint(ENUM_OUTPUT_AREA_OSExpressionTree, ENUM_OUTPUT_LEVEL_warning, "Warning: Possible memory leak");
}//end ~ExprNode


std::string ExprNode::getTokenNumber()
{
    ostringstream outStr;
    outStr << inodeInt;
    outStr << "[";
    outStr << inumberOfChildren;
    outStr << ",";
    outStr << inumberOfMatrixChildren;
    outStr << "]";
    return outStr.str();
}//getTokenNumber


std::string ExprNode::getNonlinearExpressionInXML()
{
    ostringstream outStr, logStr;
    outStr << "<";
    outStr << this->getTokenName();
#ifndef NDEBUG
    logStr << "nonlinear node " << this->getTokenName() << endl;
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSExpressionTree, ENUM_OUTPUT_LEVEL_trace, logStr.str());
#endif
    if(inumberOfChildren == 0 && inumberOfMatrixChildren == 0)
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
        if(inumberOfMatrixChildren > 0)
        {
            for(unsigned int i = 0; i < inumberOfMatrixChildren; i++)
            {
                outStr << m_mMatrixChildren[i]->getNonlinearExpressionInXML();
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
            m_mChildren[i]->ExprNode::preOrderOSnLNodeTraversal( prefixVector);
    }
    if(inumberOfMatrixChildren > 0)
    {
        for(unsigned int i = 0; i < inumberOfMatrixChildren; i++)
            m_mMatrixChildren[i]->ExprNode::preOrderOSnLNodeTraversal( prefixVector);
    }
    return *prefixVector;
}//end preOrderOSnLNodeTraversal

std::vector<ExprNode*> ExprNode::getPostfixFromExpressionTree( )
{
    std::vector<ExprNode*> postfixVector;
    return postOrderOSnLNodeTraversal( &postfixVector);
}//getPostfixFromExpressionTree


std::vector<ExprNode*> ExprNode::postOrderOSnLNodeTraversal( std::vector<ExprNode*> *postfixVector)
{
    if(inumberOfChildren > 0)
    {
        unsigned int i;
        for(i = 0; i < inumberOfChildren; i++)
            m_mChildren[i]->ExprNode::postOrderOSnLNodeTraversal( postfixVector);
    }
    if(inumberOfMatrixChildren > 0)
    {
        unsigned int i;
        for(i = 0; i < inumberOfMatrixChildren; i++)
            m_mMatrixChildren[i]->ExprNode::postOrderOSnLNodeTraversal( postfixVector);
    }
    (*postfixVector).push_back( this);
    return *postfixVector;
}//end postOrderOSnLNodeTraversal()


bool ExprNode::IsEqual(ExprNode *that)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSExpressionTree, ENUM_OUTPUT_LEVEL_trace, "Start comparing in ExprNode");
#endif
    if (this == NULL)
    {
        if (that == NULL)
            return true;
        else
        {
#ifndef NDEBUG
            osoutput->OSPrint(ENUM_OUTPUT_AREA_OSExpressionTree, ENUM_OUTPUT_LEVEL_trace, 
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
            osoutput->OSPrint(ENUM_OUTPUT_AREA_OSExpressionTree, ENUM_OUTPUT_LEVEL_trace, 
                "Second object is NULL, first is not");
#endif
            return false;
        }
        else
        {
            if (this->inodeInt != that->inodeInt)
                return false;
            if (this->inodeType != that->inodeType)
                return false;
            if (this->inumberOfChildren != that->inumberOfChildren)
                return false;
            if (this->inumberOfMatrixChildren != that->inumberOfMatrixChildren)
                return false;

            for (unsigned int i = 0; i < this->inumberOfChildren; i++)
                if (!this->m_mChildren[i]->IsEqual(that->m_mChildren[i]))
                    return false;

            for (unsigned int i = 0; i < this->inumberOfMatrixChildren; i++)
                if (!this->m_mMatrixChildren[i]->IsEqual(that->m_mMatrixChildren[i]))
                    return false;

            return true;
        }
    }
}//ExprNode::IsEqual
// End of ExprNode methods

//
//OSnLNode methods
//

OSnLNode::OSnLNode():
    ExprNode(),
    m_dFunctionValue( OSNaN())
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSExpressionTree, ENUM_OUTPUT_LEVEL_trace, "inside OSnLNode constructor");
#endif
}//end OSnLNode

OSnLNode::~OSnLNode()
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSExpressionTree, ENUM_OUTPUT_LEVEL_trace, "inside OSnLNode destructor");
#endif
}//end ~OSnLNode

OSnLNode* OSnLNode::createExpressionTreeFromPrefix(std::vector<ExprNode*> nlNodeVec)
{
    std::vector<ExprNode*> stackVec;
    int kount =  nlNodeVec.size() - 1;
    while(kount >= 0)
    {
        int numMtxKids = nlNodeVec[kount]->inumberOfMatrixChildren;
        int numkids    = nlNodeVec[kount]->inumberOfChildren;
        if(numkids > 0)
        {
            for(int i = 0; i < numkids; i++)
            {
                nlNodeVec[kount]->m_mChildren[i] = (OSnLNode*)stackVec.back();
                stackVec.pop_back();
            }
        }

        if(numMtxKids > 0)
        {
            for(int i = 0; i < numMtxKids; i++)
            {
                nlNodeVec[kount]->m_mMatrixChildren[i] = (OSnLMNode*)stackVec.back();
                stackVec.pop_back();
            }
        }
        stackVec.push_back( nlNodeVec[kount]);
        kount--;
    }
    stackVec.clear();
    return (OSnLNode*)nlNodeVec[ 0];
}//end createExpressionTreeFromPrefix

OSnLNode* OSnLNode::createExpressionTreeFromPostfix(std::vector<ExprNode*> nlNodeVec)
{
    std::vector<ExprNode*> stackVec;

    int kount =  0;
    while(kount <= nlNodeVec.size() - 1)
    {
        int numMtxKids = nlNodeVec[kount]->inumberOfMatrixChildren;
        if (numMtxKids > 0)
        {
            for(int i = numMtxKids - 1; i >= 0;  i--)
            {
                nlNodeVec[kount]->m_mMatrixChildren[i] = (OSnLMNode*)stackVec.back();
                stackVec.pop_back();
            }
        }
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
            m_mChildren[i]->OSnLNode::preOrderOSnLNodeTraversal( prefixVector);
    }
    if(inumberOfMatrixChildren > 0)
    {
        for(unsigned int i = 0; i < inumberOfMatrixChildren; i++)
            m_mMatrixChildren[i]->OSnLMNode::preOrderOSnLNodeTraversal( prefixVector);
    }
    return *prefixVector;
}//end preOrderOSnLNodeTraversal

std::vector<ExprNode*> OSnLNode::getPostfixFromExpressionTree( )
{
    std::vector<ExprNode*> postfixVector;
    return postOrderOSnLNodeTraversal( &postfixVector);
}//getPostfixFromExpressionTree


std::vector<ExprNode*> OSnLNode::postOrderOSnLNodeTraversal( std::vector<ExprNode*> *postfixVector)
{
    if(inumberOfChildren > 0)
    {
        unsigned int i;
        for(i = 0; i < inumberOfChildren; i++)
            m_mChildren[i]->OSnLNode::postOrderOSnLNodeTraversal( postfixVector);
    }
    if(inumberOfMatrixChildren > 0)
    {
        unsigned int i;
        for(i = 0; i < inumberOfMatrixChildren; i++)
            m_mMatrixChildren[i]->OSnLMNode::postOrderOSnLNodeTraversal( postfixVector);
    }
    (*postfixVector).push_back( (OSnLNode*)this);
    return *postfixVector;
}//end postOrderOSnLNodeTraversal()

void OSnLNode::getVariableIndexMap(std::map<int, int> *varIdx)
{
    unsigned int i;
    if(inodeInt != OS_VARIABLE)
    {
        for(i = 0; i < inumberOfChildren; i++)
        {
            m_mChildren[ i]->getVariableIndexMap( varIdx);
        }
    }
}//getVariableIndexMap

OSnLNode* OSnLNode::copyNodeAndDescendants()
{
    OSnLNode* ndcopy = (OSnLNode*)cloneExprNode();
    ndcopy->inumberOfChildren = inumberOfChildren;
    ndcopy->inumberOfMatrixChildren = inumberOfMatrixChildren;
    ndcopy->inodeInt = inodeInt;
    ndcopy->inodeType = inodeType;
    
    if (inumberOfChildren > 0)
    {
        //ndcopy->m_mChildren = new OSnLNode*[inumberOfChildren];
        for (int i=0; i < inumberOfChildren; i++)
        {
            ndcopy->m_mChildren[i] = /*(OSnLNode)*/m_mChildren[i]->copyNodeAndDescendants();
        }
    }

    if (inumberOfMatrixChildren > 0)
    {
        //ndcopy->m_mChildren = new OSnLNode*[inumberOfChildren];
        for (int i=0; i < inumberOfMatrixChildren; i++)
        {
            ndcopy->m_mMatrixChildren[i] = m_mMatrixChildren[i]->copyNodeAndDescendants();
        }
    }

    return ndcopy;
}// end OSnLNode::copyNodeAndDescendants

bool OSnLNode::IsEqual(OSnLNode *that)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSExpressionTree, ENUM_OUTPUT_LEVEL_trace, "Start comparing in OSnLNode");
#endif
    if (this == NULL)
    {
        if (that == NULL)
            return true;
        else
        {
#ifndef NDEBUG
            osoutput->OSPrint(ENUM_OUTPUT_AREA_OSExpressionTree, ENUM_OUTPUT_LEVEL_trace, 
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
            osoutput->OSPrint(ENUM_OUTPUT_AREA_OSExpressionTree, ENUM_OUTPUT_LEVEL_trace, 
                "Second object is NULL, first is not");
#endif
            return false;
        }
        else
        {
            if (this->inumberOfChildren != that->inumberOfChildren)
                return false;
            if (this->inumberOfMatrixChildren != that->inumberOfMatrixChildren)
                return false;
            if (this->inodeInt != that->inodeInt)
                return false;
            if (this->inodeType != that->inodeType)
                return false;

            for (unsigned int i = 0; i < this->inumberOfChildren; i++)
                if (!this->m_mChildren[i]->IsEqual(that->m_mChildren[i]))
                    return false;

            for (unsigned int i = 0; i < this->inumberOfMatrixChildren; i++)
                if (!this->m_mMatrixChildren[i]->IsEqual(that->m_mMatrixChildren[i]))
                    return false;

            return true;
        }
    }
}//OSnLNode::IsEqual


// OSnLNodePlus Methods
OSnLNodePlus::OSnLNodePlus()
{
    inumberOfChildren = 2;
    inumberOfMatrixChildren = 0;
    m_mChildren = new OSnLNode*[2];
    m_mChildren[ 0] = NULL;
    m_mChildren[ 1] = NULL;
    inodeInt = OS_PLUS;
    inodeType = 2;
}//end OSnLNodePlus


OSnLNodePlus::~OSnLNodePlus()
{
    std::ostringstream outStr;
#ifndef NDEBUG
    outStr << "inside OSnLNodePlus destructor" << endl;
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSExpressionTree, ENUM_OUTPUT_LEVEL_trace, outStr.str());
#endif
}//end ~OSnLNodePlus

std::string OSnLNodePlus::getTokenName()
{
    return "plus";
}// end OSnLNodePlus::getTokenName()

double OSnLNodePlus::calculateFunction(double *x)
{
    m_dFunctionValue = m_mChildren[0]->calculateFunction(x) + m_mChildren[1]->calculateFunction(x);
    return m_dFunctionValue;
}// end OSnLNodePlus::calculate


ADdouble OSnLNodePlus::constructADTape(std::map<int, int> *ADIdx, ADvector *XAD)
{
    m_ADTape = m_mChildren[0]->constructADTape( ADIdx,  XAD) + m_mChildren[1]->constructADTape( ADIdx,  XAD);
    return m_ADTape;
}// end OSnLNodePlus::constructADTape

OSnLNode* OSnLNodePlus::cloneExprNode()
{
    OSnLNode *nlNodePoint;
    nlNodePoint = new OSnLNodePlus();
    return  nlNodePoint;
}//end OSnLNodePlus::cloneExprNode


//
// OSnLNodeSum Methods
OSnLNodeSum::OSnLNodeSum()
{
    inumberOfChildren = 0;
    inumberOfMatrixChildren = 0;
    inodeInt = OS_SUM;
    inodeType = -1;
}//end OSnLNodeSum

OSnLNodeSum::~OSnLNodeSum()
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSExpressionTree, ENUM_OUTPUT_LEVEL_trace, "inside OSnLNodeSum destructor");
#endif
}//end ~OSnLNodeSum

std::string OSnLNodeSum::getTokenName()
{
    return "sum";
}// end OSnLNodeSum::getTokenName()

double OSnLNodeSum::calculateFunction(double *x)
{
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

OSnLNode* OSnLNodeSum::cloneExprNode()
{
    OSnLNode *nlNodePoint;
    nlNodePoint = new OSnLNodeSum();
    return  nlNodePoint;
}//end OSnLNodeSum::cloneExprNode
//end OSnLNodeSum methods


//
// OSnLNodeAllDiff Methods

OSnLNodeAllDiff::OSnLNodeAllDiff()
{
    inumberOfChildren = 0;
    inumberOfMatrixChildren = 0;
    inodeInt = OS_ALLDIFF;
    inodeType = -1;
}//end OSnLNodeAllDiff

OSnLNodeAllDiff::~OSnLNodeAllDiff()
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSExpressionTree, ENUM_OUTPUT_LEVEL_trace, "inside OSnLNodeAllDiff destructor");
#endif
}//end ~OSnLNodeAllDiff

std::string OSnLNodeAllDiff::getTokenName()
{
    return "allDiff";
}// end OSnLNodeAllDiff::getTokenName(


double OSnLNodeAllDiff::calculateFunction(double *x)
{
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


OSnLNode* OSnLNodeAllDiff::cloneExprNode()
{
    OSnLNode *nlNodePoint;
    nlNodePoint = new OSnLNodeAllDiff();
    return  nlNodePoint;
}//end OSnLNodeAllDiff::cloneExprNode
//end OSnLNodeAllDiff methods


//
// OSnLNodeMax Methods
OSnLNodeMax::OSnLNodeMax()
{
    inumberOfChildren = 0;
    inumberOfMatrixChildren = 0;
    inodeInt = OS_MAX;
    inodeType = -1;
}//end OSnLNodeMax

OSnLNodeMax::~OSnLNodeMax()
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSExpressionTree, ENUM_OUTPUT_LEVEL_trace, "inside OSnLNodeMax destructor");
#endif
}//end ~OSnLNodeMax

double OSnLNodeMax::calculateFunction(double *x)
{
    m_dFunctionValue = -OSDBL_MAX;

    for(unsigned int i = 0; i < inumberOfChildren; i++)
    {
        if(m_mChildren[i]->calculateFunction(x) > m_dFunctionValue)
        {
            m_dFunctionValue =     m_mChildren[i]->calculateFunction(x);
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


OSnLNode* OSnLNodeMax::cloneExprNode()
{
    OSnLNode *nlNodePoint;
    nlNodePoint = new OSnLNodeMax();
    return  nlNodePoint;
}//end OSnLNodeMax::cloneExprNode


//
// OSnLNodeMin Methods
OSnLNodeMin::OSnLNodeMin()
{
    inumberOfChildren = 0;
    inumberOfMatrixChildren = 0;
    inodeInt = OS_MIN;
    inodeType = -1;
}//end OSnLNodeMin

OSnLNodeMin::~OSnLNodeMin()
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSExpressionTree, ENUM_OUTPUT_LEVEL_trace, "inside OSnLNodeMin destructor");
#endif
}//end ~OSnLNodeMin


std::string OSnLNodeMin::getTokenName()
{
    return "min";
}// end OSnLNodeMin::getTokenName(

double OSnLNodeMin::calculateFunction(double *x)
{
    m_dFunctionValue = OSDBL_MAX;

    for(unsigned int i = 0; i < inumberOfChildren; i++)
    {
        if(m_mChildren[i]->calculateFunction(x) < m_dFunctionValue)
        {
            m_dFunctionValue =     m_mChildren[i]->calculateFunction(x);
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


OSnLNode* OSnLNodeMin::cloneExprNode()
{
    OSnLNode *nlNodePoint;
    nlNodePoint = new OSnLNodeMin();
    return  nlNodePoint;
}//end OSnLNodeMin::cloneExprNode


//
// OSnLNodeMinus Methods
OSnLNodeMinus::OSnLNodeMinus()
{
    inumberOfChildren = 2;
    inumberOfMatrixChildren = 0;
    m_mChildren = new OSnLNode*[2];
    m_mChildren[ 0] = NULL;
    m_mChildren[ 1] = NULL;
    inodeInt = OS_MINUS;
    inodeType = 2;
}//end OSnLNodeMinus


OSnLNodeMinus::~OSnLNodeMinus()
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSExpressionTree, ENUM_OUTPUT_LEVEL_trace, "inside OSnLNodeMinus destructor");
#endif
}//end ~OSnLNodeMinus

std::string OSnLNodeMinus::getTokenName()
{
    return "minus";
}// end OSnLNodeSum::getTokenName(

double OSnLNodeMinus::calculateFunction(double *x)
{
    m_dFunctionValue =  m_mChildren[0]->calculateFunction( x) - m_mChildren[1]->calculateFunction( x);
    return m_dFunctionValue;
}// end OSnLNodeMinus::calculate


ADdouble OSnLNodeMinus::constructADTape(std::map<int, int> *ADIdx, ADvector *XAD)
{
    m_ADTape = m_mChildren[0]->constructADTape( ADIdx, XAD) - m_mChildren[1]->constructADTape( ADIdx, XAD);
    return m_ADTape;
}// end OSnLNodeMinus::constructADTape


OSnLNode* OSnLNodeMinus::cloneExprNode()
{
    OSnLNode *nlNodePoint;
    nlNodePoint = new OSnLNodeMinus();
    return  nlNodePoint;
}//end OSnLNodeMinus::cloneExprNode


//
//
// OSnLNodeNegate Methods
OSnLNodeNegate::OSnLNodeNegate()
{
    inumberOfChildren = 1;
    inumberOfMatrixChildren = 0;
    m_mChildren = new OSnLNode*[1];
    m_mChildren[ 0] = NULL;
    inodeInt = OS_NEGATE;
    inodeType = 1;
}//end OSnLNodeNegate


OSnLNodeNegate::~OSnLNodeNegate()
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSExpressionTree, ENUM_OUTPUT_LEVEL_trace, "inside OSnLNodeNegate destructor");
#endif
}//end ~OSnLNodeNegate

std::string OSnLNodeNegate::getTokenName()
{
    return "negate";
}// end OSnLNodeNegate::getTokenName(

double OSnLNodeNegate::calculateFunction(double *x)
{
    m_dFunctionValue =  -m_mChildren[0]->calculateFunction( x) ;
    return m_dFunctionValue;
}// end OSnLNodeMinus::calculate

ADdouble OSnLNodeNegate::constructADTape(std::map<int, int> *ADIdx, ADvector *XAD)
{
    m_ADTape = -m_mChildren[0]->constructADTape( ADIdx, XAD);
    return m_ADTape;
}// end OSnLNodeNegate::constructADTape

OSnLNode* OSnLNodeNegate::cloneExprNode()
{
    OSnLNode *nlNodePoint;
    nlNodePoint = new OSnLNodeNegate();
    return  nlNodePoint;
}//end OSnLNodeNegate::cloneExprNode


// OSnLNodeTimes Methods
OSnLNodeTimes::OSnLNodeTimes()
{
    inumberOfChildren = 2;
    inumberOfMatrixChildren = 0;
    m_mChildren = new OSnLNode*[2];
    m_mChildren[ 0] = NULL;
    m_mChildren[ 1] = NULL;
    inodeInt = OS_TIMES;
    inodeType = 2;
}//end OSnLNodeTimes


OSnLNodeTimes::~OSnLNodeTimes()
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSExpressionTree, ENUM_OUTPUT_LEVEL_trace, "inside OSnLNodeTimes destructor");
#endif
}//end ~OSnLNodeTimes

std::string OSnLNodeTimes::getTokenName()
{
    return "times";
}// end OSnLNodeTimes::getTokenName(

double OSnLNodeTimes::calculateFunction(double *x)
{
    m_dFunctionValue = m_mChildren[0]->calculateFunction( x)*m_mChildren[1]->calculateFunction( x);
    return m_dFunctionValue;
}// end OSnLNodeTimes::calculate


ADdouble OSnLNodeTimes::constructADTape(std::map<int, int> *ADIdx, ADvector *XAD)
{
    m_ADTape = m_mChildren[0]->constructADTape( ADIdx, XAD) * m_mChildren[1]->constructADTape( ADIdx, XAD);
    return m_ADTape;
}// end OSnLNodeTimes::constructADTape

OSnLNode* OSnLNodeTimes::cloneExprNode()
{
    OSnLNode *nlNodePoint;
    nlNodePoint = new OSnLNodeTimes();
    return  nlNodePoint;
}//end OSnLNodeTimes::cloneExprNode


//
// OSnLNodeDivide Methods
OSnLNodeDivide::OSnLNodeDivide()
{
    inumberOfChildren = 2;
    inumberOfMatrixChildren = 0;
    m_mChildren = new OSnLNode*[2];
    m_mChildren[ 0] = NULL;
    m_mChildren[ 1] = NULL;
    inodeInt = OS_DIVIDE;
    inodeType = 2;
}//end OSnLNodeDivide


OSnLNodeDivide::~OSnLNodeDivide()
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSExpressionTree, ENUM_OUTPUT_LEVEL_trace, "inside OSnLNodeDivide destructor");
#endif
}//end ~OSnLNodeDivide

std::string OSnLNodeDivide::getTokenName()
{
    return "divide";
}// end OSnLNodeDivide::getTokenName(

double OSnLNodeDivide::calculateFunction(double *x)
{
    // kipp throw error if we divide by 0
    m_dFunctionValue = m_mChildren[0]->calculateFunction( x)/m_mChildren[1]->calculateFunction( x);
    return m_dFunctionValue;
}// end OSnLNodeDivide::calculate


ADdouble OSnLNodeDivide::constructADTape(std::map<int, int> *ADIdx, ADvector *XAD)
{
    m_ADTape = m_mChildren[0]->constructADTape( ADIdx, XAD) / m_mChildren[1]->constructADTape( ADIdx, XAD);
    return m_ADTape;
}// end OSnLNodeDivide::constructADTape


OSnLNode* OSnLNodeDivide::cloneExprNode()
{
    OSnLNode *nlNodePoint;
    nlNodePoint = new OSnLNodeDivide();
    return  nlNodePoint;
}//end OSnLNodeDivide::cloneExprNode


//
// OSnLNodePower Methods
OSnLNodePower::OSnLNodePower()
{
    inumberOfChildren = 2;
    inumberOfMatrixChildren = 0;
    m_mChildren = new OSnLNode*[2];
    m_mChildren[ 0] = NULL;
    m_mChildren[ 1] = NULL;
    inodeInt = OS_POWER;
    inodeType = 2;
}//end OSnLNodePower


OSnLNodePower::~OSnLNodePower()
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSExpressionTree, ENUM_OUTPUT_LEVEL_trace, "inside OSnLNodePower destructor");
#endif
}//end ~OSnLNodePower

std::string OSnLNodePower::getTokenName()
{
    return "power";
}// end OSnLNodePower::getTokenName(

double OSnLNodePower::calculateFunction(double *x)
{
    // kipp throw error if operation not defined
    m_dFunctionValue =  pow(m_mChildren[0]->calculateFunction( x), m_mChildren[1]->calculateFunction( x));
    return  m_dFunctionValue;
}// end OSnLNodePower::calculate

//
ADdouble OSnLNodePower::constructADTape(std::map<int, int> *ADIdx, ADvector *XAD)
{
    //if( typeid( *m_mChildren[1]) == typeid( OSnLNodeNumber) ) {
    if( this->m_mChildren[1]->inodeInt == 5001 )
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


OSnLNode* OSnLNodePower::cloneExprNode()
{
    OSnLNode *nlNodePoint;
    nlNodePoint = new OSnLNodePower();
    return  nlNodePoint;
}//end OSnLNodePower::cloneExprNode


//
// OSnLNodeProduct Methods
OSnLNodeProduct::OSnLNodeProduct()
{
    inumberOfChildren = 0;
    inumberOfMatrixChildren = 0;
    inodeInt = OS_PRODUCT;
    inodeType = -1;
}//end OSnLNodeProduct


OSnLNodeProduct::~OSnLNodeProduct()
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSExpressionTree, ENUM_OUTPUT_LEVEL_trace, "inside OSnLNodeProduct destructor");
#endif
}//end ~OSnLNodeProduct

std::string OSnLNodeProduct::getTokenName()
{
    return "product";
}// end OSnLNodeProduct::getTokenName(

double OSnLNodeProduct::calculateFunction(double *x)
{
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


OSnLNode* OSnLNodeProduct::cloneExprNode()
{
    OSnLNode *nlNodePoint;
    nlNodePoint = new OSnLNodeProduct();
    return  nlNodePoint;
}//end OSnLNodeProduct::cloneExprNode


//
// OSnLNodeLn Methods
OSnLNodeLn::OSnLNodeLn()
{
    inumberOfChildren = 1;
    inumberOfMatrixChildren = 0;
    m_mChildren = new OSnLNode*[1];
    m_mChildren[ 0] = NULL;
    inodeInt = OS_LN;
    inodeType = 1;
}//end OSnLNodeLn


OSnLNodeLn::~OSnLNodeLn()
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSExpressionTree, ENUM_OUTPUT_LEVEL_trace, "inside OSnLNodeLn destructor");
#endif
}//end ~OSnLNodeLn

std::string OSnLNodeLn::getTokenName()
{
    return "ln";
}// end OSnLNodeLn::getTokenName(

double OSnLNodeLn::calculateFunction(double *x)
{
    m_dFunctionValue = log(m_mChildren[0]->calculateFunction( x) );
    return m_dFunctionValue;
}// end OSnLNodeLn::calculate


ADdouble OSnLNodeLn::constructADTape(std::map<int, int> *ADIdx, ADvector *XAD)
{
    m_ADTape = log( m_mChildren[0]->constructADTape( ADIdx, XAD) );
    return m_ADTape;
}// end OSnLNodeLn::constructADTape

OSnLNode* OSnLNodeLn::cloneExprNode()
{
    OSnLNode *nlNodePoint;
    nlNodePoint = new OSnLNodeLn();
    return  nlNodePoint;
}//end OSnLNodeLn::cloneExprNode


//
// OSnLNodeSqrt Methods
OSnLNodeSqrt::OSnLNodeSqrt()
{
    inumberOfChildren = 1;
    inumberOfMatrixChildren = 0;
    m_mChildren = new OSnLNode*[1];
    m_mChildren[ 0] = NULL;
    inodeInt = OS_SQRT;
    inodeType = 1;
}//end OSnLNodeSqrt


OSnLNodeSqrt::~OSnLNodeSqrt()
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSExpressionTree, ENUM_OUTPUT_LEVEL_trace, "inside OSnLNodeSqrt destructor");
#endif
}//end ~OSnLNodeSqrt

std::string OSnLNodeSqrt::getTokenName()
{
    return "sqrt";
}// end OSnLNodeSqrt::getTokenName(

double OSnLNodeSqrt::calculateFunction(double *x)
{
    m_dFunctionValue = sqrt(m_mChildren[0]->calculateFunction( x) );
    return m_dFunctionValue;
}// end OSnLNodeSqrt::calculate


ADdouble OSnLNodeSqrt::constructADTape(std::map<int, int> *ADIdx, ADvector *XAD)
{
    m_ADTape = sqrt( m_mChildren[0]->constructADTape( ADIdx, XAD) );
    return m_ADTape;
}// end OSnLNodeSqrt::constructADTape

OSnLNode* OSnLNodeSqrt::cloneExprNode()
{
    OSnLNode *nlNodePoint;
    nlNodePoint = new OSnLNodeSqrt();
    return  nlNodePoint;
}//end OSnLNodeSqrt::cloneExprNode


//
// OSnLNodeSquare Methods
OSnLNodeSquare::OSnLNodeSquare()
{
    inumberOfChildren = 1;
    inumberOfMatrixChildren = 0;
    m_mChildren = new OSnLNode*[1];
    m_mChildren[ 0] = NULL;
    inodeInt = OS_SQUARE;
    inodeType = 1;
}//end OSnLNodeSquare


OSnLNodeSquare::~OSnLNodeSquare()
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSExpressionTree, ENUM_OUTPUT_LEVEL_trace, "inside OSnLNodeSquare destructor");
#endif
}//end ~OSnLNodeSquare

std::string OSnLNodeSquare::getTokenName()
{
    return "square";
}// end OSnLNodeSquare::getTokenName(

double OSnLNodeSquare::calculateFunction(double *x)
{
    m_dFunctionValue = pow( (m_mChildren[0]->calculateFunction( x) ), 2);
    return m_dFunctionValue;
}// end OSnLNodeSquare::calculate


ADdouble OSnLNodeSquare::constructADTape(std::map<int, int> *ADIdx, ADvector *XAD)
{
    m_ADTape = pow( m_mChildren[0]->constructADTape( ADIdx, XAD), int( 2) );
    return m_ADTape;
}// end OSnLNodeSquare::constructADTape

OSnLNode* OSnLNodeSquare::cloneExprNode()
{
    OSnLNode *nlNodePoint;
    nlNodePoint = new OSnLNodeSquare();
    return  nlNodePoint;
}//end OSnLNodeSquare::cloneExprNode


//
// OSnLNodeSin Methods
OSnLNodeSin::OSnLNodeSin()
{
    inumberOfChildren = 1;
    inumberOfMatrixChildren = 0;
    m_mChildren = new OSnLNode*[1];
    m_mChildren[ 0] = NULL;
    inodeInt = OS_SIN;
    inodeType = 1;
}//end OSnLNodeSin


OSnLNodeSin::~OSnLNodeSin()
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSExpressionTree, ENUM_OUTPUT_LEVEL_trace, "inside OSnLNodeSin destructor");
#endif
}//end ~OSnLNodeSin

std::string OSnLNodeSin::getTokenName()
{
    return "sin";
}// end OSnLNodeSin::getTokenName(

double OSnLNodeSin::calculateFunction(double *x)
{
    m_dFunctionValue = sin(m_mChildren[0]->calculateFunction( x) );
    return m_dFunctionValue;
}// end OSnLNodeSin::calculate


ADdouble OSnLNodeSin::constructADTape(std::map<int, int> *ADIdx, ADvector *XAD)
{
    m_ADTape = sin( m_mChildren[0]->constructADTape( ADIdx, XAD) );
    return m_ADTape;
}// end OSnLNodeSin::constructADTape

OSnLNode* OSnLNodeSin::cloneExprNode()
{
    OSnLNode *nlNodePoint;
    nlNodePoint = new OSnLNodeSin();
    return  nlNodePoint;
}//end OSnLNodeSin::cloneExprNode


//
// OSnLNodeCos Methods
OSnLNodeCos::OSnLNodeCos()
{
    inumberOfChildren = 1;
    inumberOfMatrixChildren = 0;
    m_mChildren = new OSnLNode*[1];
    m_mChildren[ 0] = NULL;
    inodeInt = OS_COS;
    inodeType = 1;
}//end OSnLNodeCos


OSnLNodeCos::~OSnLNodeCos()
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSExpressionTree, ENUM_OUTPUT_LEVEL_trace, "inside OSnLNodeCos destructor");
#endif
}//end ~OSnLNodeCos

std::string OSnLNodeCos::getTokenName()
{
    return "cos";
}// end OSnLNodeCos::getTokenName(

double OSnLNodeCos::calculateFunction(double *x)
{
    m_dFunctionValue = cos(m_mChildren[0]->calculateFunction( x) );
    return m_dFunctionValue;
}// end OSnLNodeCos::calculate


ADdouble OSnLNodeCos::constructADTape(std::map<int, int> *ADIdx, ADvector *XAD)
{
    m_ADTape = cos( m_mChildren[0]->constructADTape( ADIdx, XAD) );
    return m_ADTape;
}// end OSnLNodeCos::constructADTape

OSnLNode* OSnLNodeCos::cloneExprNode()
{
    OSnLNode *nlNodePoint;
    nlNodePoint = new OSnLNodeCos();
    return  nlNodePoint;
}//end OSnLNodeCos::cloneExprNode


//
// OSnLNodeExp Methods
OSnLNodeExp::OSnLNodeExp()
{
    inumberOfChildren = 1;
    inumberOfMatrixChildren = 0;
    m_mChildren = new OSnLNode*[1];
    m_mChildren[ 0] = NULL;
    inodeInt = OS_EXP;
    inodeType = 1;
}//end OSnLNodeExp


OSnLNodeExp::~OSnLNodeExp()
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSExpressionTree, ENUM_OUTPUT_LEVEL_trace, "inside OSnLNodeExp destructor");
#endif
}//end ~OSnLNodeExp

std::string OSnLNodeExp::getTokenName()
{
    return "exp";
}// end OSnLNodeExp::getTokenName(

double OSnLNodeExp::calculateFunction(double *x)
{
    m_dFunctionValue = exp(m_mChildren[0]->calculateFunction( x) );
    return m_dFunctionValue;
}// end OSnLNodeExp::calculate


ADdouble OSnLNodeExp::constructADTape(std::map<int, int> *ADIdx, ADvector *XAD)
{
    m_ADTape = exp( m_mChildren[0]->constructADTape( ADIdx, XAD) );
    return m_ADTape;
}// end OSnLNodeExp::constructADTape

OSnLNode* OSnLNodeExp::cloneExprNode()
{
    OSnLNode *nlNodePoint;
    nlNodePoint = new OSnLNodeExp();
    return  nlNodePoint;
}//end OSnLNodeExp::cloneExprNode


//
// OSnLNodeAbs Methods
OSnLNodeAbs::OSnLNodeAbs()
{
    inumberOfChildren = 1;
    inumberOfMatrixChildren = 0;
    m_mChildren = new OSnLNode*[1];
    m_mChildren[ 0] = NULL;
    inodeInt = OS_ABS;
    inodeType = 1;
}//end OSnLNodeLn


OSnLNodeAbs::~OSnLNodeAbs()
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSExpressionTree, ENUM_OUTPUT_LEVEL_trace, "inside OSnLNodeAbs destructor");
#endif
}//end ~OSnLNodeAbs

std::string OSnLNodeAbs::getTokenName()
{
    return "abs";
}// end OSnLNodeAbs::getTokenName(

double OSnLNodeAbs::calculateFunction(double *x)
{
    m_dFunctionValue = fabs(m_mChildren[0]->calculateFunction( x) );
    return m_dFunctionValue;
}// end OSnLNodeAbs::calculate


ADdouble OSnLNodeAbs::constructADTape(std::map<int, int> *ADIdx, ADvector *XAD)
{
    m_ADTape = abs( m_mChildren[0]->constructADTape( ADIdx, XAD) );
    return m_ADTape;
}// end OSnLNodeAbs::constructADTape

OSnLNode* OSnLNodeAbs::cloneExprNode()
{
    OSnLNode *nlNodePoint;
    nlNodePoint = new OSnLNodeAbs();
    return  nlNodePoint;
}//end OSnLNodeAbs::cloneExprNode
// end OSnLNodeAbs methods


//
// OSnLNodeErf Methods
OSnLNodeErf::OSnLNodeErf()
{
    inumberOfChildren = 1;
    inumberOfMatrixChildren = 0;
    m_mChildren = new OSnLNode*[1];
    m_mChildren[ 0] = NULL;
    inodeInt = OS_ERF;
    inodeType = 1;
}//end OSnLNodeErf


OSnLNodeErf::~OSnLNodeErf()
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSExpressionTree, ENUM_OUTPUT_LEVEL_trace, "inside OSnLNodeErf destructor");
#endif
}//end ~OSnLNodeErf

std::string OSnLNodeErf::getTokenName()
{
    return "erf";
}// end OSnLNodeErf::getTokenName(

double OSnLNodeErf::calculateFunction(double *x)
{
    const double a = (993./880.);
    const double b =  (89./880.);
    //m_dFunctionValue = fabs(m_mChildren[0]->calculateFunction( x) );
    m_dFunctionValue = tanh( (a + b * m_mChildren[0]->calculateFunction( x) * m_mChildren[0]->calculateFunction( x)) * m_mChildren[0]->calculateFunction( x) );
    //std::cout << "function value =   " << m_dFunctionValue << std::endl;
    return m_dFunctionValue;
}// end OSnLNodeErf::calculate


ADdouble OSnLNodeErf::constructADTape(std::map<int, int> *ADIdx, ADvector *XAD)
{
    /***
     *
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

OSnLNode* OSnLNodeErf::cloneExprNode()
{
    OSnLNode *nlNodePoint;
    nlNodePoint = new OSnLNodeErf();
    return  nlNodePoint;
}//end OSnLNodeErf::cloneExprNode
// end OSnLNodeErf methods


// OSnLNodeIf Methods
OSnLNodeIf::OSnLNodeIf()
{
    inumberOfChildren = 3;
    inumberOfMatrixChildren = 0;
    m_mChildren = new OSnLNode*[3];
    m_mChildren[ 0] = NULL;
    m_mChildren[ 1] = NULL;
    m_mChildren[ 2] = NULL;
    inodeInt = OS_IF;
    inodeType = 3;
}//end OSnLNodeIf


OSnLNodeIf::~OSnLNodeIf()
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSExpressionTree, ENUM_OUTPUT_LEVEL_trace, "inside OSnLNodeIf destructor");
#endif
}//end ~OSnLNodeIf

std::string OSnLNodeIf::getTokenName()
{
    return "if";
}// end OSnLNodeIf::getTokenName(

double OSnLNodeIf::calculateFunction(double *x)
{
    if(m_mChildren[0]->calculateFunction( x)  >= 0) m_dFunctionValue = m_mChildren[ 1]->calculateFunction( x);
    else m_dFunctionValue = m_mChildren[ 2]->calculateFunction( x);
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

OSnLNode* OSnLNodeIf::cloneExprNode()
{
    OSnLNode *nlNodePoint;
    nlNodePoint = new OSnLNodeIf();
    return  nlNodePoint;
}//end OSnLNodeIf::cloneExprNode
// end OSnLNodeIf methods


//
// OSnLNodeNumber Methods
OSnLNodeNumber::OSnLNodeNumber()
{
    inodeInt = OS_NUMBER;
    inumberOfChildren = 0;
    inumberOfMatrixChildren = 0;
    m_mChildren = NULL;
    m_mMatrixChildren = NULL;
    inodeType = 0;
    value = 0.0;

    type = "real";
    id = "";

}//end OSnLNodeNumber

OSnLNodeNumber::~OSnLNodeNumber()
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSExpressionTree, ENUM_OUTPUT_LEVEL_trace, "inside OSnLNodeNumber destructor");
#endif
}//end ~OSnLNodeNumber

std::string OSnLNodeNumber::getTokenNumber()
{
    ostringstream outStr;
    outStr << inodeInt;
    outStr << ":" ;
    outStr << value ;
//    //if(type.length() > 0){
//        outStr << ":" ;
//        outStr << type ;
//    //}
//    //if(id.length() > 0){
//        outStr << ":" ;
//        outStr << id;
//    //}
    return outStr.str();
}//getTokenNumber


std::string OSnLNodeNumber::getTokenName()
{
    return "number";
}//getTokenName


std::string OSnLNodeNumber::getNonlinearExpressionInXML()
{
    ostringstream outStr;
    outStr << "<" ;
    outStr << this->getTokenName();
    outStr << "  value=\"";
    outStr << os_dtoa_format(value);
    outStr << "\"";
    outStr << " type=\"";
    outStr << type ;
    outStr << "\"";
    if(id.length() > 0)
    {
        outStr << "  id=\"";
        outStr << id ;
        outStr << "\"";
    }
    outStr << "/>";
    return outStr.str();
}//getNonlinearExpressionInXML()


double OSnLNodeNumber::calculateFunction(double *x)
{
    m_dFunctionValue = this->value;
    return m_dFunctionValue;
}// end OSnLNodeNumber::calculate

ADdouble OSnLNodeNumber::constructADTape(std::map<int, int> *ADIdx, ADvector *XAD)
{
    m_ADTape =  this->value;
    return m_ADTape;
}// end OSnLNodeNumber::constructADTape

OSnLNode* OSnLNodeNumber::cloneExprNode()
{
    OSnLNode *nlNodePoint;
    nlNodePoint = new OSnLNodeNumber();
    return  nlNodePoint;
}//end OSnLNodeNumber::cloneExprNode
// end OSnLNodeNumber methods


// OSnLNodeE Methods
OSnLNodeE::OSnLNodeE()
{
    inodeInt = OS_E;
    inumberOfChildren = 0;
    inumberOfMatrixChildren = 0;
    m_mChildren = NULL;
    m_mMatrixChildren = NULL;
    inodeType = 0;
    //value = 0.0;
    //type = "real";
    //id = "";
}//end OSnLNodeE

OSnLNodeE::~OSnLNodeE()
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSExpressionTree, ENUM_OUTPUT_LEVEL_trace, "inside OSnLNodeE destructor");
#endif
}//end ~OSnLNodeE


std::string OSnLNodeE::getTokenNumber()
{
    ostringstream outStr;
    outStr << inodeInt;
    return outStr.str();
}//getTokenNumber


std::string OSnLNodeE::getTokenName()
{
    ostringstream outStr;
    outStr << "E";
    return outStr.str();
}//getTokenName


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
    m_dFunctionValue = OS_E_VALUE;
    return m_dFunctionValue;
}// end OSnLNodeE::calculate

ADdouble OSnLNodeE::constructADTape(std::map<int, int> *ADIdx, ADvector *XAD)
{
    m_ADTape =  OS_E_VALUE;
    return m_ADTape;
}// end OSnLE::constructADTape

OSnLNode* OSnLNodeE::cloneExprNode()
{
    OSnLNode *nlNodePoint;
    nlNodePoint = new OSnLNodeE();
    return  nlNodePoint;
}//end OSnLNodeE::cloneExprNode
//end OSnLNodeE


// OSnLNodePI Methods
OSnLNodePI::OSnLNodePI()
{
    inodeInt = OS_PI;
    inumberOfChildren = 0;
    inumberOfMatrixChildren = 0;
    m_mChildren = NULL;
    m_mMatrixChildren = NULL;
    inodeType = 0;
}//end OSnLNodePI


OSnLNodePI::~OSnLNodePI()
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSExpressionTree, ENUM_OUTPUT_LEVEL_trace, "inside OSnLNodePI destructor");
#endif
}//end ~OSnLNodePI


std::string OSnLNodePI::getTokenNumber()
{
    ostringstream outStr;
    outStr << inodeInt;
    return outStr.str();
}//getTokenNumber


std::string OSnLNodePI::getTokenName()
{
    ostringstream outStr;
    outStr << "PI";
    return outStr.str();
}//getTokenName


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
    m_dFunctionValue = OS_PI_VALUE;
    return m_dFunctionValue;
}// end OSnLNodePI::calculate

ADdouble OSnLNodePI::constructADTape(std::map<int, int> *ADIdx, ADvector *XAD)
{
    m_ADTape =  OS_PI_VALUE;
    return m_ADTape;
}// end OSnLE::constructADTape

OSnLNode* OSnLNodePI::cloneExprNode()
{
    OSnLNode *nlNodePoint;
    nlNodePoint = new OSnLNodePI();
    return  nlNodePoint;
}//end OSnLNodePI::cloneExprNode
//end OSnLNodePI methods


// OSnLNodeVariable Methods
OSnLNodeVariable::OSnLNodeVariable()
{
    inumberOfChildren = 0;
    inumberOfMatrixChildren = 0;
    m_mChildren = NULL;
    m_mMatrixChildren = NULL;
    inodeInt = OS_VARIABLE;
    inodeType = -1;
    coef = 1.0;
    idx = -1;
}//end OSnLNodeVariable

OSnLNodeVariable::~OSnLNodeVariable()
{
    std::ostringstream outStr;
#ifndef NDEBUG
    outStr << "inside OSnLNodeVariable destructor" << endl;
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSExpressionTree, ENUM_OUTPUT_LEVEL_trace, outStr.str());
#endif
}//end ~OSnLNodeVariable


std::string OSnLNodeVariable::getTokenNumber()
{
    ostringstream outStr;
    // put in an error if inodeInt is not 6001
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


std::string OSnLNodeVariable::getTokenName()
{
    ostringstream outStr;
    // put in an error if inodeInt is not 6001
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
}//getTokenNumber


std::string OSnLNodeVariable::getNonlinearExpressionInXML()
{
    ostringstream outStr;
    outStr << "<" ;
    outStr << "variable";
    outStr << "  idx=\"";
    outStr << idx ;
    outStr << "\"";
    outStr << "  coef=\"";
    outStr << os_dtoa_format(coef);
    outStr << "\"";
    if(inumberOfChildren > 0)
    {
        outStr << ">";
    }
    else
    {
        outStr << "/>";
    }
    if(inumberOfChildren > 0)
    {
        for(unsigned int i = 0; i < inumberOfChildren; i++)
        {
            outStr << m_mChildren[i]->getNonlinearExpressionInXML();
        }

        outStr << "</" ;
        outStr << "variable" ;
        outStr << ">" ;
    }
    return outStr.str();
}//getPrefix

double OSnLNodeVariable::calculateFunction(double *x)
{
    m_dFunctionValue = coef*x[idx];
    return m_dFunctionValue;
}// end OSnLNodeVariable::calculate

ADdouble OSnLNodeVariable::constructADTape(std::map<int, int> *varIdx, ADvector *XAD)
{
    m_ADTape = coef;
    //std::cout << "Inside OSnLNodeVariable "<<  std::endl;
    //std::cout << "Value of OSiL index = " << idx << std::endl;
    //std::cout << "Value of AD index = " << (*varIdx)[ idx] << std::endl;
    //std::cout << "Value of AD variable = " << (*XAD)[ (*varIdx)[ idx] ] << std::endl;
    m_ADTape = coef*(*XAD)[ (*varIdx)[ idx] ];
    return m_ADTape;
}// end OSnLNodeVariable::constructADTape


void OSnLNodeVariable::getVariableIndexMap(std::map<int, int> *varIdx)
{
    int numVars;
    if( (*varIdx).find( idx) != (*varIdx).end() )
    {
        //std::cout  << "Index already in the map " << idx <<  std::endl;
    }
    else  // variable to map with variable index as the key
    {
        //std::cout << "Found a new index to add to the map " << idx << std::endl;
        numVars = (*varIdx).size();
        //std::cout << "numVars =  " << numVars << std::endl;
        (*varIdx)[ idx] = numVars;
    }
    //std::cout << "Value of index = " << (*varIdx)[ idx] << std::endl;
}//getVariableIndexMap


OSnLNode* OSnLNodeVariable::cloneExprNode()
{
    OSnLNode *nlNodePoint;
    nlNodePoint = new OSnLNodeVariable();
    return  nlNodePoint;
}//end OSnLNodeVariable::cloneExprNode


/** OSnLNode objects with matrix arguments **/

//
// OSnLNodeMatrixDeterminant Methods
OSnLNodeMatrixDeterminant::OSnLNodeMatrixDeterminant()
{
    inumberOfChildren = 0;
    inumberOfMatrixChildren = 1;
    m_mMatrixChildren = new OSnLMNode*[1];
    inodeInt = OS_MATRIX_DETERMINANT;
    inodeType = 0;
}//end OSnLNodeMatrixDeterminant

OSnLNodeMatrixDeterminant::~OSnLNodeMatrixDeterminant()
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSExpressionTree, ENUM_OUTPUT_LEVEL_trace, "inside OSnLNodeMatrixDeterminant destructor");
#endif
}//end ~OSnLNodeMatrixDeterminant

double OSnLNodeMatrixDeterminant::calculateFunction(double *x)
{
    m_dFunctionValue = -OSDBL_MAX;

    for(unsigned int i = 0; i < inumberOfChildren; i++)
    {
        if(m_mChildren[i]->calculateFunction(x) > m_dFunctionValue)
        {
            m_dFunctionValue =     m_mChildren[i]->calculateFunction(x);
        }
    }
    return m_dFunctionValue;
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


OSnLNode* OSnLNodeMatrixDeterminant::cloneExprNode()
{
    OSnLNode *nlNodePoint;
    nlNodePoint = new OSnLNodeMatrixDeterminant();
    return  nlNodePoint;
}//end OSnLNodeMatrixDeterminant::cloneExprNode


// OSnLNodeMatrixTrace Methods
OSnLNodeMatrixTrace::OSnLNodeMatrixTrace()
{
    inumberOfChildren = 0;
    inumberOfMatrixChildren = 1;
    m_mMatrixChildren = new OSnLMNode*[1];
    inodeInt = OS_MATRIX_TRACE;
    inodeType = 0;
}//end OSnLNodeMatrixTrace

OSnLNodeMatrixTrace::~OSnLNodeMatrixTrace()
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSExpressionTree, ENUM_OUTPUT_LEVEL_trace, "inside OSnLNodeMatrixTrace destructor");
#endif
}//end ~OSnLNodeMatrixDeterminant

double OSnLNodeMatrixTrace::calculateFunction(double *x)
{
#if 0
    m_dFunctionValue = -OSDBL_MAX;

    for(unsigned int i = 0; i < inumberOfChildren; i++)
    {
        if(m_mChildren[i]->calculateFunction(x) > m_dFunctionValue)
        {
            m_dFunctionValue =     m_mChildren[i]->calculateFunction(x);
        }
    }
    return m_dFunctionValue;
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


OSnLNode* OSnLNodeMatrixTrace::cloneExprNode()
{
    OSnLNode *nlNodePoint;
    nlNodePoint = new OSnLNodeMatrixTrace();
    return  nlNodePoint;
}//end OSnLNodeMatrixTrace::cloneExprNode


//
// OSnLNodeMatrixToScalar Methods
OSnLNodeMatrixToScalar::OSnLNodeMatrixToScalar()
{
    inumberOfChildren = 0;
    inumberOfMatrixChildren = 1;
    m_mMatrixChildren = new OSnLMNode*[1];
    inodeInt = OS_MATRIX_TO_SCALAR;
    inodeType = 0;
}//end OSnLNodeMatrixToScalar

OSnLNodeMatrixToScalar::~OSnLNodeMatrixToScalar()
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSExpressionTree, ENUM_OUTPUT_LEVEL_trace, "inside OSnLNodeMatrixToScalar destructor");
#endif
}//end ~OSnLNodeMatrixToScalar

double OSnLNodeMatrixToScalar::calculateFunction(double *x)
{
    m_dFunctionValue = -OSDBL_MAX;

    for(unsigned int i = 0; i < inumberOfChildren; i++)
    {
        if(m_mChildren[i]->calculateFunction(x) > m_dFunctionValue)
        {
            m_dFunctionValue =     m_mChildren[i]->calculateFunction(x);
        }
    }
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


OSnLNode* OSnLNodeMatrixToScalar::cloneExprNode()
{
    OSnLNode *nlNodePoint;
    nlNodePoint = new OSnLNodeMatrixToScalar();
    return  nlNodePoint;
}//end OSnLNodeMatrixToScalar::cloneExprNode


/***********************************************************
 *    Implementation of OSnLMNode and inheriting classes   * 
 ***********************************************************/
OSnLMNode::OSnLMNode():
    ExprNode()
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSExpressionTree, ENUM_OUTPUT_LEVEL_trace, "inside OSnLMNode constructor");
#endif
}//end OSnLMNode

OSnLMNode::~OSnLMNode()
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSExpressionTree, ENUM_OUTPUT_LEVEL_trace, "inside OSnLMNode destructor");
#endif
}//end ~OSnLNode

OSnLMNode* OSnLMNode::copyNodeAndDescendants()
{
    OSnLMNode* ndcopy = (OSnLMNode*)cloneExprNode();
    ndcopy->inumberOfChildren = inumberOfChildren;
    ndcopy->inumberOfMatrixChildren = inumberOfMatrixChildren;
    ndcopy->inodeInt = inodeInt;
    ndcopy->inodeType = inodeType;
    
    if (inumberOfChildren > 0)
    {
        //ndcopy->m_mChildren = new OSnLNode*[inumberOfChildren];
        for (int i=0; i < inumberOfChildren; i++)
        {
            ndcopy->m_mChildren[i] = m_mChildren[i]->copyNodeAndDescendants();
        }
    }

    if (inumberOfMatrixChildren > 0)
    {
        //ndcopy->m_mChildren = new OSnLNode*[inumberOfChildren];
        for (int i=0; i < inumberOfMatrixChildren; i++)
        {
            ndcopy->m_mMatrixChildren[i] = m_mMatrixChildren[i]->copyNodeAndDescendants();
        }
    }

    return ndcopy;
}// end copyNodeAndDescendants

#if 0
OSnLMNode* OSnLMNode::createExpressionTreeFromPostfix(std::vector<OSnLMNode*> nlMNodeVec)
{
    std::vector<OSnLMNode*> stackVec ;
    unsigned int kount =  0;
    while(kount <= nlMNodeVec.size() - 1)
    {
        int numkids = nlMNodeVec[kount]->inumberOfMatrixChildren;
        if(numkids  > 0)
        {
            for(int i = numkids - 1; i >= 0;  i--)
            {
                nlMNodeVec[kount]->m_mMatrixChildren[i] = stackVec.back()    ;
                stackVec.pop_back();
            }
        }
        stackVec.push_back( nlMNodeVec[kount]);
        kount++;
    }
    stackVec.clear();
    return nlMNodeVec[ kount - 1];
}//end createExpressionTreeFromPostfix

std::vector<OSnLMNode*> OSnLMNode::getPostfixFromExpressionTree( )
{
//    std::vector<OSnLMNode*> postfixVector;
//    return postOrderOSnLNodeTraversal( &postfixVector);
    return 0;
}//getPostfixFromExpressionTree

std::vector<OSnLNode*> OSnLNode::postOrderOSnLNodeTraversal( std::vector<OSnLNode*> *postfixVector)
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
#endif

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
                nlNodeVec[kount]->m_mChildren[i] = (OSnLNode*)stackVec.back();
                stackVec.pop_back();
            }
        }
        int mtxkids = nlNodeVec[kount]->inumberOfMatrixChildren;
        if(mtxkids > 0)
        {
            for(int i = 0; i < mtxkids;  i++)
            {
                nlNodeVec[kount]->m_mMatrixChildren[i] = (OSnLMNode*)stackVec.back();
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
        int numMtxKids = nlNodeVec[kount]->inumberOfMatrixChildren;
        if (numMtxKids  > 0)
        {
            for(int i = numMtxKids - 1; i >= 0;  i--)
            {
                nlNodeVec[kount]->m_mMatrixChildren[i] = (OSnLMNode*)stackVec.back();
                stackVec.pop_back();
            }
        }
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
            m_mChildren[i]->OSnLNode::preOrderOSnLNodeTraversal( prefixVector);
    }
    if(inumberOfMatrixChildren > 0)
    {
        for(unsigned int i = 0; i < inumberOfMatrixChildren; i++)
            m_mMatrixChildren[i]->OSnLMNode::preOrderOSnLNodeTraversal( prefixVector);
    }
    return *prefixVector;
}//end preOrderOSnLNodeTraversal

std::vector<ExprNode*> OSnLMNode::getPostfixFromExpressionTree( )
{
    std::vector<ExprNode*> postfixVector;
    return postOrderOSnLNodeTraversal( &postfixVector);
}//getPostfixFromExpressionTree


std::vector<ExprNode*> OSnLMNode::postOrderOSnLNodeTraversal( std::vector<ExprNode*> *postfixVector)
{
    if(inumberOfChildren > 0)
    {
        unsigned int i;
        for(i = 0; i < inumberOfChildren; i++)
            m_mChildren[i]->OSnLNode::postOrderOSnLNodeTraversal( postfixVector);
    }
    if(inumberOfMatrixChildren > 0)
    {
        unsigned int i;
        for(i = 0; i < inumberOfMatrixChildren; i++)
            m_mMatrixChildren[i]->OSnLMNode::postOrderOSnLNodeTraversal( postfixVector);
    }
    (*postfixVector).push_back( (OSnLMNode*)this);
    return *postfixVector;
}//end postOrderOSnLNodeTraversal()

#if 0
std::string OSnLMNode::getTokenNumber()
{
    ostringstream outStr;
    outStr << inodeInt;

    // when I create an OSnLNode from a token number, I need to know how many children there are
//    if(inodeType == -1){
    outStr << "[";
    outStr << inumberOfChildren ;
    outStr << "]";
//    }
    return outStr.str();
}//getTokenNumber


/*
OSnLNode* OSnLNode::getOSnLNodeFromToken(std::string sToken){
// kipp possibly make this a static method or put it somewhere else
    OSnLNode *nlNodePoint;
    int nodeID ;
    int pos1, pos2;
    std::string str1, str2;
    // convert the std::string tokens into the appropriate objects
        // kipp -- put in error check -- make sure > 0 and < 10001
    nodeID = atoi(  &sToken.substr(0, 4)[0]);
    switch (nodeID){
        case OS_SUM:  // the sum token
            pos1 = sToken.find('[');
            pos2 = sToken.find(']');
            if((pos1 == std::string::npos) || (pos2 == std::string::npos)){
                // throw error
            }
            OSnLNodeSum *nlNodePointSum;
            nlNodePointSum = new OSnLNodeSum();
            nlNodePointSum->inumberOfChildren = atoi(  &sToken.substr(pos1 + 1, pos2 - pos1 - 1)[0]);
            nlNodePointSum->m_mChildren = new OSnLNode*[ nlNodePointSum->inumberOfChildren];
            return nlNodePointSum;
        break;
        case OS_MAX:  // the max token
            pos1 = sToken.find('[');
            pos2 = sToken.find(']');
            if((pos1 == std::string::npos) || (pos2 == std::string::npos)){
                // throw error
            }
            OSnLNodeMax *nlNodePointMax;
            nlNodePointMax = new OSnLNodeMax();
            nlNodePointMax->inumberOfChildren = atoi(  &sToken.substr(pos1 + 1, pos2 - pos1 - 1)[0]);
            nlNodePointMax->m_mChildren = new OSnLNode*[ nlNodePointMax->inumberOfChildren];
            return nlNodePointMax;
        break;
        case OS_PRODUCT:  // the product token
            pos1 = sToken.find('[');
            pos2 = sToken.find(']');
            if((pos1 == std::string::npos) || (pos2 == std::string::npos)){
                // throw error
            }
            OSnLNodeProduct *nlNodePointProduct;
            nlNodePointProduct = new OSnLNodeProduct();
            nlNodePointProduct->inumberOfChildren = atoi(  &sToken.substr(pos1 + 1, pos2 - pos1 - 1)[0]);
            nlNodePointProduct->m_mChildren = new OSnLNode*[ nlNodePointProduct->inumberOfChildren];
            return nlNodePointProduct;
        break;
        case OS_NUMBER:  // the number token
            pos1 = sToken.find(':');
            if(pos1 != 4){
                //throw error
            }
            // now get the second semicolon, the one that should be after value
            pos2 = sToken.find(':', pos1 + 1);
            if(pos2 != std::string::npos) {
            }
            else{
                //throw error
            }
            OSnLNodeNumber *nlNodePointNumber;
            nlNodePointNumber = new OSnLNodeNumber();
            nlNodePointNumber->value = atof(  &sToken.substr(pos1 + 1, pos2 - pos1 - 1)[0]);
            return nlNodePointNumber;
        break;
        case OS_VARIABLE:  // the variable token
            pos1 = sToken.find('[');
            pos2 = sToken.find(']');
            if((pos1 == std::string::npos) || (pos2 == std::string::npos)){
                // throw error
            }
            OSnLNodeVariable *nlNodePointVariable;
            nlNodePointVariable = new OSnLNodeVariable();
            nlNodePointVariable->inumberOfChildren = atoi(  &sToken.substr(pos1 + 1, pos2 - pos1 - 1)[0]);
            nlNodePointVariable->m_mChildren = new OSnLNode*[ nlNodePointVariable->inumberOfChildren];
            // throw error if there is more than one child
            // now get the index and the coefficient
            pos1 = sToken.find(':');
            if(pos1 != 4){
                //throw error
            }
            // now get the second semicolon, the one that should be after idx
            pos2 = sToken.find(':', pos1 + 1);
            if(pos2 == std::string::npos) {
                //throw error
            }
            nlNodePointVariable->idx = atoi(  &sToken.substr(pos1 + 1, pos2 - pos1 - 1)[0]);
            // now get the coefficient
            str1 = sToken;
            str2 = sToken.substr(pos2 + 1, str1.length() - pos2 - 1);
            nlNodePointVariable->coef = atof(&str2[0]);
            return nlNodePointVariable;
        break;
        default:
            nlNodePoint = nlNodeArray[ nlNodeIdxMap[ nodeID]]->cloneExprNode();
        break;
    }
    return nlNodePoint;
}//end getOSnLNodeFromToken
*/



std::string OSnLMNode::getNonlinearExpressionInXML()
{
    ostringstream outStr, logStr;
    outStr << "<" ;
    outStr << this->getTokenName();
#ifndef NDEBUG
    logStr << "nonlinear node " << this->getTokenName() << endl;
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSExpressionTree, ENUM_OUTPUT_LEVEL_trace, logStr.str());
#endif
    if(inumberOfChildren > 0)
    {
        outStr << ">";
    }
    else
    {
        outStr << "/>";
    }
    if(inumberOfChildren > 0)
    {
        for(unsigned int i = 0; i < inumberOfChildren; i++)
        {
            outStr << m_mChildren[i]->getNonlinearExpressionInXML();
        }
    }
    if(inumberOfChildren > 0)

    {
        outStr << "</" ;
        outStr << this->getTokenName() ;
        outStr << ">" ;
    }
    return outStr.str();
}//getNonlinearExpressionInXML()
//
//

void OSnLNode::getVariableIndexMap(std::map<int, int> *varIdx)
{
    unsigned int i;
    if(inodeInt != OS_VARIABLE)
    {
        for(i = 0; i < inumberOfChildren; i++)
        {
            m_mChildren[ i]->getVariableIndexMap( varIdx);
        }


    }
}//getVariableIndexMap
#endif

bool OSnLMNode::IsEqual(OSnLMNode *that)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSExpressionTree, ENUM_OUTPUT_LEVEL_trace, "Start comparing in OSnLMNode");
#endif
    if (this == NULL)
    {
        if (that == NULL)
            return true;
        else
        {
#ifndef NDEBUG
            osoutput->OSPrint(ENUM_OUTPUT_AREA_OSExpressionTree, ENUM_OUTPUT_LEVEL_trace, 
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
            osoutput->OSPrint(ENUM_OUTPUT_AREA_OSExpressionTree, ENUM_OUTPUT_LEVEL_trace, 
                "Second object is NULL, first is not");
#endif
            return false;
        }
        else
        {
            if (this->inumberOfChildren != that->inumberOfChildren)
                return false;
            if (this->inumberOfMatrixChildren != that->inumberOfMatrixChildren)
                return false;
            if (this->inodeInt != that->inodeInt)
                return false;
            if (this->inodeType != that->inodeType)
                return false;

            for (unsigned int i = 0; i < this->inumberOfChildren; i++)
                if (!this->m_mChildren[i]->IsEqual(that->m_mChildren[i]))
                    return false;

            for (unsigned int i = 0; i < this->inumberOfMatrixChildren; i++)
                if (!this->m_mMatrixChildren[i]->IsEqual(that->m_mMatrixChildren[i]))
                    return false;

            return true;
        }
    }
}//OSnLMNode::IsEqual

#if 0
OSnLMNode* OSnLMNode::copyNodeAndDescendants()
{
    OSnLMNode* ndcopy = cloneExprNode();

    ndcopy->inumberOfChildren = inumberOfChildren;
    ndcopy->inumberOfMatrixChildren = inumberOfMatrixChildren;
    ndcopy->inodeInt = inodeInt;
    ndcopy->inodeType = inodeType;
    
    if (inumberOfChildren > 0)
    {
        //ndcopy->m_mChildren = new OSnLNode*[inumberOfChildren];
        for (int i=0; i < inumberOfChildren; i++)
        {
            ndcopy->m_mChildren[i] = m_mChildren[i]->(OSnLNode)copyNodeAndDescendants();
        }
    }

    if (inumberOfMatrixChildren > 0)
    {
        //ndcopy->m_mChildren = new OSnLNode*[inumberOfChildren];
        for (int i=0; i < inumberOfMatrixChildren; i++)
        {
            ndcopy->m_mMatrixChildren[i] = m_mMatrixChildren[i]->(OSnLMNode)copyNodeAndDescendants();
        }
    }

    return ndcopy;
}// end OSnLNode::copyNodeAndDescendants
#endif

// OSnLMNodeMatrixPlus Methods
OSnLMNodeMatrixPlus::OSnLMNodeMatrixPlus()
{
    inumberOfChildren = 0;
    inumberOfMatrixChildren = 2;
    m_mChildren = NULL;
    m_mMatrixChildren = new OSnLMNode*[2];
    inodeInt = OS_MATRIX_PLUS;
    inodeType = 2;
}//end OSnLMNodeMatrixPlus

OSnLMNodeMatrixPlus::~OSnLMNodeMatrixPlus()
{
    std::ostringstream outStr;
#ifndef NDEBUG
    outStr << "inside OSnLMNodeMatrixPlus destructor" << endl;
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSExpressionTree, ENUM_OUTPUT_LEVEL_trace, outStr.str());
#endif
}//end ~OSnLMNodeMatrixPlus

std::string OSnLMNodeMatrixPlus::getTokenName()
{
    return "matrixPlus";
}// end OSnLMNodeMatrixPlus::getTokenName()

OSnLMNode* OSnLMNodeMatrixPlus::cloneExprNode()
{
    OSnLMNode *nlMNodePoint;
    nlMNodePoint = new OSnLMNodeMatrixPlus();
    return  nlMNodePoint;
}//end OSnLMNodeMatrixPlus::cloneExprNode


// OSnLMNodeMatrixSum Methods
OSnLMNodeMatrixSum::OSnLMNodeMatrixSum()
{
    inumberOfChildren = 0;
    inumberOfMatrixChildren = 0;
    m_mChildren = NULL;
    m_mMatrixChildren = NULL;
    inodeInt = OS_MATRIX_SUM;
    inodeType = -1;
}//end OSnLMNodeMatrixSum

OSnLMNodeMatrixSum::~OSnLMNodeMatrixSum()
{
    std::ostringstream outStr;
#ifndef NDEBUG
    outStr << "inside OSnLMNodeMatrixSum destructor" << endl;
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSExpressionTree, ENUM_OUTPUT_LEVEL_trace, outStr.str());
#endif
}//end ~OSnLMNodeMatrixSum

std::string OSnLMNodeMatrixSum::getTokenName()
{
    return "matrixSum";
}// end OSnLMNodeMatrixSum::getTokenName()

OSnLMNode* OSnLMNodeMatrixSum::cloneExprNode()
{
    OSnLMNode *nlMNodePoint;
    nlMNodePoint = new OSnLMNodeMatrixSum();
    return  nlMNodePoint;
}//end OSnLMNodeMatrixSum::cloneExprNode

//
// OSnLMNodeMatrixProduct Methods
OSnLMNodeMatrixProduct::OSnLMNodeMatrixProduct()
{
    inumberOfChildren = 0;
    inumberOfMatrixChildren = 0;
    m_mChildren = NULL;
    m_mMatrixChildren = NULL;
    inodeInt = OS_MATRIX_PRODUCT;
    inodeType = -1;
}//end OSnLMNodeMatrixProduct


OSnLMNodeMatrixProduct::~OSnLMNodeMatrixProduct()
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSExpressionTree, ENUM_OUTPUT_LEVEL_trace, "inside OSnLMNodeMatrixProduct destructor");
#endif
}//end ~OSnLMNodeMatrixProduct

std::string OSnLMNodeMatrixProduct::getTokenName()
{
    return "matrixProduct";
}// end OSnLMNodeMatrixProduct::getTokenName(

#if 0
double OSnLMNodeMatrixProduct::calculateFunction(double *x)
{
    // kipp throw error if operation not defined
    m_dFunctionValue = 1.0;
    unsigned int i;
    for(i = 0; i < inumberOfChildren; i++)
    {
        m_dFunctionValue = m_dFunctionValue*m_mChildren[i]->calculateFunction(x);
    }
    return m_dFunctionValue;
}// end OSnLMNodeMatrixProduct::calculate


ADdouble OSnLMNodeMatrixProduct::constructADTape(std::map<int, int> *ADIdx, ADvector *XAD)
{
    m_ADTape = 1.0;
    unsigned int i;
    for(i = 0; i < inumberOfChildren; i++)
    {
        m_ADTape = m_ADTape*m_mChildren[i]->constructADTape( ADIdx, XAD);
    }
    return m_ADTape;
}// end OSnLMNodeMatrixProduct::constructADTape
#endif

OSnLMNode* OSnLMNodeMatrixProduct::cloneExprNode()
{
    OSnLMNode *nlMNodePoint;
    nlMNodePoint = new OSnLMNodeMatrixProduct();
    return  nlMNodePoint;
}//end OSnLMNodeMatrixProduct::cloneExprNode


// OSnLMNodeMatrixMinus Methods
OSnLMNodeMatrixMinus::OSnLMNodeMatrixMinus()
{
    inumberOfChildren = 0;
    inumberOfMatrixChildren = 2;
    m_mChildren = NULL;
    m_mMatrixChildren = new OSnLMNode*[2];
    inodeInt = OS_MATRIX_MINUS;
    inodeType = 2;
}//end OSnLMNodeMatrixMinus

OSnLMNodeMatrixMinus::~OSnLMNodeMatrixMinus()
{
    std::ostringstream outStr;
#ifndef NDEBUG
    outStr << "inside OSnLMNodeMatrixMinus destructor" << endl;
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSExpressionTree, ENUM_OUTPUT_LEVEL_trace, outStr.str());
#endif
}//end ~OSnLMNodeMatrixMinus

std::string OSnLMNodeMatrixMinus::getTokenName()
{
    return "matrixMinus";
}// end OSnLMNodeMatrixMinus::getTokenName()

OSnLMNode* OSnLMNodeMatrixMinus::cloneExprNode()
{
    OSnLMNode *nlMNodePoint;
    nlMNodePoint = new OSnLMNodeMatrixMinus();
    return  nlMNodePoint;
}//end OSnLMNodeMatrixMinus::cloneExprNode

// OSnLMNodeMatrixNegate Methods
OSnLMNodeMatrixNegate::OSnLMNodeMatrixNegate()
{
    inumberOfChildren = 0;
    inumberOfMatrixChildren = 1;
    m_mChildren = NULL;
    m_mMatrixChildren = new OSnLMNode*[1];
    inodeInt = OS_MATRIX_NEGATE;
    inodeType = 1;
}//end OSnLMNodeMatrixNegate

OSnLMNodeMatrixNegate::~OSnLMNodeMatrixNegate()
{
    std::ostringstream outStr;
#ifndef NDEBUG
    outStr << "inside OSnLMNodeMatrixNegate destructor" << endl;
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSExpressionTree, ENUM_OUTPUT_LEVEL_trace, outStr.str());
#endif
}//end ~OSnLMNodeMatrixNegate

std::string OSnLMNodeMatrixNegate::getTokenName()
{
    return "matrixNegate";
}// end OSnLMNodeMatrixNegate::getTokenName()

OSnLMNode* OSnLMNodeMatrixNegate::cloneExprNode()
{
    OSnLMNode *nlMNodePoint;
    nlMNodePoint = new OSnLMNodeMatrixNegate();
    return  nlMNodePoint;
}//end OSnLMNodeMatrixNegate::cloneExprNode

// OSnLMNodeMatrixTimes Methods
OSnLMNodeMatrixTimes::OSnLMNodeMatrixTimes()
{
    inumberOfChildren = 0;
    inumberOfMatrixChildren = 2;
    m_mChildren = NULL;
    m_mMatrixChildren = new OSnLMNode*[2];
    inodeInt = OS_MATRIX_TIMES;
    inodeType = 2;
}//end OSnLMNodeMatrixTimes

OSnLMNodeMatrixTimes::~OSnLMNodeMatrixTimes()
{
    std::ostringstream outStr;
#ifndef NDEBUG
    outStr << "inside OSnLMNodeMatrixTimes destructor" << endl;
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSExpressionTree, ENUM_OUTPUT_LEVEL_trace, outStr.str());
#endif
}//end ~OSnLMNodeMatrixTimes

std::string OSnLMNodeMatrixTimes::getTokenName()
{
    return "matrixTimes";
}// end OSnLMNodeMatrixTimes::getTokenName()

OSnLMNode* OSnLMNodeMatrixTimes::cloneExprNode()
{
    OSnLMNode *nlMNodePoint;
    nlMNodePoint = new OSnLMNodeMatrixTimes();
    return  nlMNodePoint;
}//end OSnLMNodeMatrixTimes::cloneExprNode

// OSnLMNodeMatrixInverse Methods
OSnLMNodeMatrixInverse::OSnLMNodeMatrixInverse()
{
    inumberOfChildren = 0;
    inumberOfMatrixChildren = 1;
    m_mChildren = NULL;
    m_mMatrixChildren = new OSnLMNode*[1];
    inodeInt = OS_MATRIX_INVERSE;
    inodeType = 1;
}//end OSnLMNodeMatrixInverse

OSnLMNodeMatrixInverse::~OSnLMNodeMatrixInverse()
{
    std::ostringstream outStr;
#ifndef NDEBUG
    outStr << "inside OSnLMNodeMatrixInverse destructor" << endl;
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSExpressionTree, ENUM_OUTPUT_LEVEL_trace, outStr.str());
#endif
}//end ~OSnLMNodeMatrixInverse

std::string OSnLMNodeMatrixInverse::getTokenName()
{
    return "matrixInverse";
}// end OSnLMNodeMatrixInverse::getTokenName()

OSnLMNode* OSnLMNodeMatrixInverse::cloneExprNode()
{
    OSnLMNode *nlMNodePoint;
    nlMNodePoint = new OSnLMNodeMatrixInverse();
    return  nlMNodePoint;
}//end OSnLMNodeMatrixInverse::cloneExprNode


// OSnLMNodeMatrixTranspose Methods
OSnLMNodeMatrixTranspose::OSnLMNodeMatrixTranspose()
{
    inumberOfChildren = 0;
    inumberOfMatrixChildren = 1;
    m_mChildren = NULL;
    m_mMatrixChildren = new OSnLMNode*[1];
    inodeInt = OS_MATRIX_TRANSPOSE;
    inodeType = 1;
}//end OSnLMNodeMatrixTranspose

OSnLMNodeMatrixTranspose::~OSnLMNodeMatrixTranspose()
{
    std::ostringstream outStr;
#ifndef NDEBUG
    outStr << "inside OSnLMNodeMatrixTranspose destructor" << endl;
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSExpressionTree, ENUM_OUTPUT_LEVEL_trace, outStr.str());
#endif
}//end ~OSnLMNodeMatrixTranspose

std::string OSnLMNodeMatrixTranspose::getTokenName()
{
    return "matrixTranspose";
}// end OSnLMNodeMatrixTranspose::getTokenName()

OSnLMNode* OSnLMNodeMatrixTranspose::cloneExprNode()
{
    OSnLMNode *nlMNodePoint;
    nlMNodePoint = new OSnLMNodeMatrixTranspose();
    return  nlMNodePoint;
}//end OSnLMNodeMatrixTranspose::cloneExprNode

// OSnLMNodeMatrixScalarTimes Methods
OSnLMNodeMatrixScalarTimes::OSnLMNodeMatrixScalarTimes()
{
    inumberOfChildren = 1;
    inumberOfMatrixChildren = 1;
    m_mChildren = new OSnLNode*[1];
    m_mMatrixChildren = new OSnLMNode*[1];
    inodeInt = OS_MATRIX_SCALARTIMES;
    inodeType = 1;
}//end OSnLMNodeMatrixScalarTimes

OSnLMNodeMatrixScalarTimes::~OSnLMNodeMatrixScalarTimes()
{
    std::ostringstream outStr;
#ifndef NDEBUG
    outStr << "inside OSnLMNodeMatrixScalarTimes destructor" << endl;
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSExpressionTree, ENUM_OUTPUT_LEVEL_trace, outStr.str());
#endif
}//end ~OSnLMNodeMatrixScalarTimes

std::string OSnLMNodeMatrixScalarTimes::getTokenName()
{
    return "matrixScalarTimes";
}// end OSnLMNodeMatrixScalarTimes::getTokenName()

OSnLMNode* OSnLMNodeMatrixScalarTimes::cloneExprNode()
{
    OSnLMNode *nlMNodePoint;
    nlMNodePoint = new OSnLMNodeMatrixScalarTimes();
    return  nlMNodePoint;
}//end OSnLMNodeMatrixScalarTimes::cloneExprNode

// OSnLMNodeMatrixDotTimes Methods
OSnLMNodeMatrixDotTimes::OSnLMNodeMatrixDotTimes()
{
    inumberOfChildren = 0;
    inumberOfMatrixChildren = 2;
    m_mChildren = NULL;
    m_mMatrixChildren = new OSnLMNode*[2];
    inodeInt = OS_MATRIX_DOTTIMES;
    inodeType = 2;
}//end OSnLMNodeMatrixDotTimes

OSnLMNodeMatrixDotTimes::~OSnLMNodeMatrixDotTimes()
{
    std::ostringstream outStr;
#ifndef NDEBUG
    outStr << "inside OSnLMNodeMatrixDotTimes destructor" << endl;
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSExpressionTree, ENUM_OUTPUT_LEVEL_trace, outStr.str());
#endif
}//end ~OSnLMNodeMatrixDotTimes

std::string OSnLMNodeMatrixDotTimes::getTokenName()
{
    return "matrixDotTimes";
}// end OSnLMNodeMatrixDotTimes::getTokenName()

OSnLMNode* OSnLMNodeMatrixDotTimes::cloneExprNode()
{
    OSnLMNode *nlMNodePoint;
    nlMNodePoint = new OSnLMNodeMatrixDotTimes();
    return  nlMNodePoint;
}//end OSnLMNodeMatrixDotTimes::cloneExprNode


// OSnLMNodeIdentityMatrix Methods
OSnLMNodeIdentityMatrix::OSnLMNodeIdentityMatrix()
{
    inumberOfChildren = 1;
    inumberOfMatrixChildren = 0;
    m_mChildren = new OSnLNode*[1];
    m_mMatrixChildren = NULL;
    inodeInt = OS_IDENTITY_MATRIX;
    inodeType = -1;
}//end OSnLMNodeIdentityMatrix

OSnLMNodeIdentityMatrix::~OSnLMNodeIdentityMatrix()
{
    std::ostringstream outStr;
#ifndef NDEBUG
    outStr << "inside OSnLMNodeIdentityMatrix destructor" << endl;
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSExpressionTree, ENUM_OUTPUT_LEVEL_trace, outStr.str());
#endif
}//end ~OSnLMNodeIdentityMatrix

std::string OSnLMNodeIdentityMatrix::getTokenName()
{
    return "identityMatrix";
}// end OSnLMNodeIdentityMatrix::getTokenName()

OSnLMNode* OSnLMNodeIdentityMatrix::cloneExprNode()
{
    OSnLMNode *nlMNodePoint;
    nlMNodePoint = new OSnLMNodeIdentityMatrix();
    return  nlMNodePoint;
}//end OSnLMNodeIdentityMatrix::cloneExprNode


// OSnLMNodeMatrixLowerTriangle Methods
OSnLMNodeMatrixLowerTriangle::OSnLMNodeMatrixLowerTriangle()
{
    inumberOfChildren = 0;
    inumberOfMatrixChildren = 1;
    m_mChildren = NULL;
    m_mMatrixChildren = new OSnLMNode*[1];
    inodeInt = OS_MATRIX_LOWERTRIANGLE;
    inodeType = 1;
    includeDiagonal = true;
}//end OSnLMNodeMatrixLowerTriangle

OSnLMNodeMatrixLowerTriangle::~OSnLMNodeMatrixLowerTriangle()
{
    std::ostringstream outStr;
#ifndef NDEBUG
    outStr << "inside OSnLMNodeMatrixLowerTriangle destructor" << endl;
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSExpressionTree, ENUM_OUTPUT_LEVEL_trace, outStr.str());
#endif
}//end ~OSnLMNodeMatrixLowerTriangle

std::string OSnLMNodeMatrixLowerTriangle::getTokenName()
{
    return "matrixLowerTriangle";
}// end OSnLMNodeMatrixLowerTriangle::getTokenName()

OSnLMNode* OSnLMNodeMatrixLowerTriangle::cloneExprNode()
{
    OSnLMNode *nlMNodePoint;
    nlMNodePoint = new OSnLMNodeMatrixLowerTriangle();
    return  nlMNodePoint;
}//end OSnLMNodeMatrixLowerTriangle::cloneExprNode

std::string OSnLMNodeMatrixLowerTriangle::getNonlinearExpressionInXML()
{
    ostringstream outStr;
    outStr << "<matrixLowerTriangle";
    if (includeDiagonal == false)
        outStr << " includeDiagonal=\"false\""; 
    outStr << ">" << std::endl;

    outStr << m_mMatrixChildren[0]->getNonlinearExpressionInXML();

    outStr << "</matrixLowerTriangle>";
    return outStr.str();
}//OSnLMNodeMatrixLowerTriangle::getNonlinearExpressionInXML


// OSnLMNodeMatrixUpperTriangle Methods
OSnLMNodeMatrixUpperTriangle::OSnLMNodeMatrixUpperTriangle()
{
    inumberOfChildren = 0;
    inumberOfMatrixChildren = 1;
    m_mChildren = NULL;
    m_mMatrixChildren = new OSnLMNode*[1];
    inodeInt = OS_MATRIX_UPPERTRIANGLE;
    inodeType = 1;

    includeDiagonal = true;
}//end OSnLMNodeMatrixUpperTriangle

OSnLMNodeMatrixUpperTriangle::~OSnLMNodeMatrixUpperTriangle()
{
    std::ostringstream outStr;
#ifndef NDEBUG
    outStr << "inside OSnLMNodeMatrixUpperTriangle destructor" << endl;
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSExpressionTree, ENUM_OUTPUT_LEVEL_trace, outStr.str());
#endif
}//end ~OSnLMNodeMatrixUpperTriangle

std::string OSnLMNodeMatrixUpperTriangle::getTokenName()
{
    return "matrixUpperTriangle";
}// end OSnLMNodeMatrixUpperTriangle::getTokenName()

OSnLMNode* OSnLMNodeMatrixUpperTriangle::cloneExprNode()
{
    OSnLMNode *nlMNodePoint;
    nlMNodePoint = new OSnLMNodeMatrixUpperTriangle();
    return  nlMNodePoint;
}//end OSnLMNodeMatrixUpperTriangle::cloneExprNode

std::string OSnLMNodeMatrixUpperTriangle::getNonlinearExpressionInXML()
{
    ostringstream outStr;
    outStr << "<matrixUpperTriangle";
    if (includeDiagonal == false)
        outStr << " includeDiagonal=\"false\""; 
    outStr << ">" << std::endl;

    outStr << m_mMatrixChildren[0]->getNonlinearExpressionInXML();

    outStr << "</matrixUpperTriangle>";
    return outStr.str();
}//OSnLMNodeMatrixUpperTriangle::getNonlinearExpressionInXML


// OSnLMNodeMatrixDiagonal Methods
OSnLMNodeMatrixDiagonal::OSnLMNodeMatrixDiagonal()
{
    inumberOfChildren = 0;
    inumberOfMatrixChildren = 1;
    m_mChildren = NULL;
    m_mMatrixChildren = new OSnLMNode*[1];
    inodeInt = OS_MATRIX_DIAGONAL;
    inodeType = 1;
}//end OSnLMNodeMatrixDiagonal

OSnLMNodeMatrixDiagonal::~OSnLMNodeMatrixDiagonal()
{
    std::ostringstream outStr;
#ifndef NDEBUG
    outStr << "inside OSnLMNodeMatrixDiagonal destructor" << endl;
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSExpressionTree, ENUM_OUTPUT_LEVEL_trace, outStr.str());
#endif
}//end ~OSnLMNodeMatrixDiagonal

std::string OSnLMNodeMatrixDiagonal::getTokenName()
{
    return "matrixDiagonal";
}// end OSnLMNodeMatrixDiagonal::getTokenName()

OSnLMNode* OSnLMNodeMatrixDiagonal::cloneExprNode()
{
    OSnLMNode *nlMNodePoint;
    nlMNodePoint = new OSnLMNodeMatrixDiagonal();
    return  nlMNodePoint;
}//end OSnLMNodeMatrixDiagonal::cloneExprNode


// OSnLMNodeDiagonalMatrixFromVector Methods
OSnLMNodeDiagonalMatrixFromVector::OSnLMNodeDiagonalMatrixFromVector()
{
    inumberOfChildren = 0;
    inumberOfMatrixChildren = 1;
    m_mChildren = NULL;
    m_mMatrixChildren = new OSnLMNode*[1];
    inodeInt = OS_DIAGONAL_MATRIX_FROM_VECTOR;
    inodeType = -1;
}//end OSnLMNodeDiagonalMatrixFromVector

OSnLMNodeDiagonalMatrixFromVector::~OSnLMNodeDiagonalMatrixFromVector()
{
    std::ostringstream outStr;
#ifndef NDEBUG
    outStr << "inside OSnLMNodeDiagonalMatrixFromVector destructor" << endl;
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSExpressionTree, ENUM_OUTPUT_LEVEL_trace, outStr.str());
#endif
}//end ~OSnLMNodeDiagonalMatrixFromVector

std::string OSnLMNodeDiagonalMatrixFromVector::getTokenName()
{
    return "diagonalMatrixFromVector";
}// end OSnLMNodeDiagonalMatrixFromVector::getTokenName()

OSnLMNode* OSnLMNodeDiagonalMatrixFromVector::cloneExprNode()
{
    OSnLMNode *nlMNodePoint;
    nlMNodePoint = new OSnLMNodeDiagonalMatrixFromVector();
    return  nlMNodePoint;
}//end OSnLMNodeDiagonalMatrixFromVector::cloneExprNode


// OSnLMNodeMatrixSubmatrixAt Methods
OSnLMNodeMatrixSubmatrixAt::OSnLMNodeMatrixSubmatrixAt()
{
    inumberOfChildren = 4;
    inumberOfMatrixChildren = 1;
    m_mChildren = new OSnLNode*[4];
    m_mMatrixChildren = new OSnLMNode*[1];
    inodeInt = OS_MATRIX_SUBMATRIX_AT;
    inodeType = 1;
}//end OSnLMNodeMatrixSubmatrixAt

OSnLMNodeMatrixSubmatrixAt::~OSnLMNodeMatrixSubmatrixAt()
{
    std::ostringstream outStr;
#ifndef NDEBUG
    outStr << "inside OSnLMNodeMatrixSubmatrixAt destructor" << endl;
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSExpressionTree, ENUM_OUTPUT_LEVEL_trace, outStr.str());
#endif
}//end ~OSnLMNodeMatrixSubmatrixAt

std::string OSnLMNodeMatrixSubmatrixAt::getTokenName()
{
    return "matrixSubmatrixAt";
}// end OSnLMNodeMatrixSubmatrixAt::getTokenName()

OSnLMNode* OSnLMNodeMatrixSubmatrixAt::cloneExprNode()
{
    OSnLMNode *nlMNodePoint;
    nlMNodePoint = new OSnLMNodeMatrixSubmatrixAt();
    return  nlMNodePoint;
}//end OSnLMNodeMatrixSubmatrixAt::cloneExprNode


// OSnLMNodeMatrixReference Methods
OSnLMNodeMatrixReference::OSnLMNodeMatrixReference():
    idx(-1)
{
    inumberOfChildren = 0;
    inumberOfMatrixChildren = 0;
    m_mChildren = NULL;
    m_mMatrixChildren = NULL;
    inodeInt = OS_MATRIX_REFERENCE;
    inodeType = -1;
}//end OSnLMNodeMatrixReference

OSnLMNodeMatrixReference::~OSnLMNodeMatrixReference()
{
    std::ostringstream outStr;
#ifndef NDEBUG
    outStr << "inside OSnLMNodeMatrixReference destructor" << endl;
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSExpressionTree, ENUM_OUTPUT_LEVEL_trace, outStr.str());
#endif
}//end ~OSnLMNodeMatrixReference

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

std::string OSnLMNodeMatrixReference::getTokenName()
{
    return "matrixReference";
}// end OSnLMNodeMatrixReference::getTokenName()


std::string OSnLMNodeMatrixReference::getNonlinearExpressionInXML()
{
    ostringstream outStr;
    outStr << "<matrixReference idx=\"" << idx << "\"/>" << std::endl;
    return outStr.str();
}//OSnLMNodeMatrixReference::getNonlinearExpressionInXML

#if 0
double OSnLMNodeMatrixReference::calculateFunction(double *x)
{
    m_dFunctionValue = coef*x[idx];
    return m_dFunctionValue;
}// end OSnLMNodeMatrixReference::calculate

ADdouble OSnLMNodeMatrixReference::constructADTape(std::map<int, int> *varIdx, ADvector *XAD)
{
    m_ADTape = coef;
    m_ADTape = coef*(*XAD)[ (*varIdx)[ idx] ];
    return m_ADTape;
}// end OSnLMNodeMatrixReference::constructADTape


void OSnLMNodeMatrixReference::getVariableIndexMap(std::map<int, int> *varIdx)
{
    int numVars;
    if( (*varIdx).find( idx) != (*varIdx).end() )
    {
        //std::cout  << "Index already in the map " << idx <<  std::endl;
    }
    else  // variable to map with variable index as the key
    {
        //std::cout << "Found a new index to add to the map " << idx << std::endl;
        numVars = (*varIdx).size();
        //std::cout << "numVars =  " << numVars << std::endl;
        (*varIdx)[ idx] = numVars;
    }
    //std::cout << "Value of index = " << (*varIdx)[ idx] << std::endl;
}//getVariableIndexMap
#endif

OSnLMNode* OSnLMNodeMatrixReference::cloneExprNode()
{
    OSnLMNode *nlMNodePoint;
    nlMNodePoint = new OSnLMNodeMatrixReference();
    return  nlMNodePoint;
}//end OSnLMNodeMatrixReference::cloneExprNode

bool OSnLMNodeMatrixReference::IsEqual(OSnLMNodeMatrixReference* that)
{
    if (this->idx != that->idx) return false;
    return (this->OSnLMNode::IsEqual(that));
}//end OSnLMNodeMatrixReference::IsEqual


// OSnLMNodeMatrixVar Methods
OSnLMNodeMatrixVar::OSnLMNodeMatrixVar():
    idx(-1)
{
    inumberOfChildren = 0;
    inumberOfMatrixChildren = 0;
    m_mChildren = NULL;
    m_mMatrixChildren = NULL;
    inodeInt = OS_MATRIX_VAR;
    inodeType = -1;
}//end OSnLMNodeMatrixVar

OSnLMNodeMatrixVar::~OSnLMNodeMatrixVar()
{
    std::ostringstream outStr;
#ifndef NDEBUG
    outStr << "inside OSnLMNodeMatrixVar destructor" << endl;
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSExpressionTree, ENUM_OUTPUT_LEVEL_trace, outStr.str());
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

#if 0
double OSnLMNodeMatrixVar::calculateFunction(double *x)
{
    m_dFunctionValue = coef*x[idx];
    return m_dFunctionValue;
}// end OSnLMNodeMatrixVar::calculate

ADdouble OSnLMNodeMatrixVar::constructADTape(std::map<int, int> *varIdx, ADvector *XAD)
{
    m_ADTape = coef;
    m_ADTape = coef*(*XAD)[ (*varIdx)[ idx] ];
    return m_ADTape;
}// end OSnLMNodeMatrixVar::constructADTape


void OSnLMNodeMatrixVar::getVariableIndexMap(std::map<int, int> *varIdx)
{
    int numVars;
    if( (*varIdx).find( idx) != (*varIdx).end() )
    {
        //std::cout  << "Index already in the map " << idx <<  std::endl;
    }
    else  // variable to map with variable index as the key
    {
        //std::cout << "Found a new index to add to the map " << idx << std::endl;
        numVars = (*varIdx).size();
        //std::cout << "numVars =  " << numVars << std::endl;
        (*varIdx)[ idx] = numVars;
    }
    //std::cout << "Value of index = " << (*varIdx)[ idx] << std::endl;
}//getVariableIndexMap
#endif


OSnLMNode* OSnLMNodeMatrixVar::cloneExprNode()
{
    OSnLMNode *nlMNodePoint;
    nlMNodePoint = new OSnLMNodeMatrixVar();
    return  nlMNodePoint;
}//end OSnLMNodeMatrixVar::cloneExprNode

bool OSnLMNodeMatrixVar::IsEqual(OSnLMNodeMatrixVar* that)
{
    if (this->idx != that->idx) return false;
    return (this->OSnLMNode::IsEqual(that));
}//end OSnLMNodeMatrixVar::IsEqual


// OSnLMNodeMatrixObj Methods
OSnLMNodeMatrixObj::OSnLMNodeMatrixObj():
    idx(-1)
{
    inumberOfChildren = 0;
    inumberOfMatrixChildren = 0;
    m_mChildren = NULL;
    m_mMatrixChildren = NULL;
    inodeInt = OS_MATRIX_OBJ;
    inodeType = -1;
}//end OSnLMNodeMatrixObj

OSnLMNodeMatrixObj::~OSnLMNodeMatrixObj()
{
    std::ostringstream outStr;
#ifndef NDEBUG
    outStr << "inside OSnLMNodeMatrixObj destructor" << endl;
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSExpressionTree, ENUM_OUTPUT_LEVEL_trace, outStr.str());
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

#if 0
double OSnLMNodeMatrixObj::calculateFunction(double *x)
{
    m_dFunctionValue = coef*x[idx];
    return m_dFunctionValue;
}// end OSnLMNodeMatrixObj::calculate

ADdouble OSnLMNodeMatrixObj::constructADTape(std::map<int, int> *varIdx, ADvector *XAD)
{
    m_ADTape = coef;
    m_ADTape = coef*(*XAD)[ (*varIdx)[ idx] ];
    return m_ADTape;
}// end OSnLMNodeMatrixObj::constructADTape

void OSnLMNodeMatrixObj::getVariableIndexMap(std::map<int, int> *varIdx)
{
    int numVars;
    if( (*varIdx).find( idx) != (*varIdx).end() )
    {
        //std::cout  << "Index already in the map " << idx <<  std::endl;
    }
    else  // variable to map with variable index as the key
    {
        //std::cout << "Found a new index to add to the map " << idx << std::endl;
        numVars = (*varIdx).size();
        //std::cout << "numVars =  " << numVars << std::endl;
        (*varIdx)[ idx] = numVars;
    }
    //std::cout << "Value of index = " << (*varIdx)[ idx] << std::endl;
}//getVariableIndexMap
#endif

OSnLMNode* OSnLMNodeMatrixObj::cloneExprNode()
{
    OSnLMNode *nlMNodePoint;
    nlMNodePoint = new OSnLMNodeMatrixObj();
    return  nlMNodePoint;
}//end OSnLMNodeMatrixObj::cloneExprNode

bool OSnLMNodeMatrixObj::IsEqual(OSnLMNodeMatrixObj* that)
{
    if (this->idx != that->idx) return false;
    return (this->OSnLMNode::IsEqual(that));
}//end OSnLMNodeMatrixObj::IsEqual


// OSnLMNodeMatrixCon Methods
OSnLMNodeMatrixCon::OSnLMNodeMatrixCon():
    idx(-1)
{
    inumberOfChildren = 0;
    inumberOfMatrixChildren = 0;
    m_mChildren = NULL;
    m_mMatrixChildren = NULL;
    inodeInt = OS_MATRIX_CON;
    inodeType = -1;
}//end OSnLMNodeMatrixCon

OSnLMNodeMatrixCon::~OSnLMNodeMatrixCon()
{
    std::ostringstream outStr;
#ifndef NDEBUG
    outStr << "inside OSnLMNodeMatrixCon destructor" << endl;
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSExpressionTree, ENUM_OUTPUT_LEVEL_trace, outStr.str());
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

#if 0
double OSnLMNodeMatrixCon::calculateFunction(double *x)
{
    m_dFunctionValue = coef*x[idx];
    return m_dFunctionValue;
}// end OSnLMNodeMatrixCon::calculate

ADdouble OSnLMNodeMatrixCon::constructADTape(std::map<int, int> *varIdx, ADvector *XAD)
{
    m_ADTape = coef;
    m_ADTape = coef*(*XAD)[ (*varIdx)[ idx] ];
    return m_ADTape;
}// end OSnLMNodeMatrixCon::constructADTape


void OSnLMNodeMatrixCon::getVariableIndexMap(std::map<int, int> *varIdx)
{
    int numVars;
    if( (*varIdx).find( idx) != (*varIdx).end() )
    {
        //std::cout  << "Index already in the map " << idx <<  std::endl;
    }
    else  // variable to map with variable index as the key
    {
        //std::cout << "Found a new index to add to the map " << idx << std::endl;
        numVars = (*varIdx).size();
        //std::cout << "numVars =  " << numVars << std::endl;
        (*varIdx)[ idx] = numVars;
    }
    //std::cout << "Value of index = " << (*varIdx)[ idx] << std::endl;
}//getVariableIndexMap
#endif


OSnLMNode* OSnLMNodeMatrixCon::cloneExprNode()
{
    OSnLMNode *nlMNodePoint;
    nlMNodePoint = new OSnLMNodeMatrixCon();
    return  nlMNodePoint;
}//end OSnLMNodeMatrixCon::cloneExprNode

bool OSnLMNodeMatrixCon::IsEqual(OSnLMNodeMatrixCon* that)
{
    if (this->idx != that->idx) return false;
    return (this->OSnLMNode::IsEqual(that));
}//end OSnLMNodeMatrixVar::IsEqual

