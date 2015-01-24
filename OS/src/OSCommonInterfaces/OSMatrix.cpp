/* $Id: OSMatrix.cpp 3186 2010-02-06 23:38:35Z Gassmann $ */
/** @file OSMatrix.cpp
 *
 * @author Horand Gassmann, Jun Ma, Kipp Martin
 *
 * \remarks
 * Copyright (C) 2005-2014, Horand Gassmann, Jun Ma, Kipp Martin,
 * Northwestern University, and the University of Chicago.
 * All Rights Reserved.
 * This software is licensed under the Eclipse Public License.
 * Please see the accompanying LICENSE file in root directory for terms.
 *
 */

#include "OSMatrix.h"
#include "OSGeneral.h"
#include "OSParameters.h"
#include "OSErrorClass.h"
#include "OSMathUtil.h"
#include "OSBase64.h"
#include "OSOutput.h"
#include "OSgLWriter.h"

#include <iostream>
#include <sstream>


using namespace std;
using std::endl;


/***************************************************************
 *                                                             *
 * Implementations of methods for various matrix classes       *
 *                                                             *
 ***************************************************************/
 
MatrixNode::MatrixNode():
    matrixType(ENUM_MATRIX_TYPE_unknown), 
    nType(ENUM_MATRIX_CONSTRUCTOR_TYPE_unknown),
    inumberOfChildren(),
    m_mChildren(NULL){
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSGeneral, ENUM_OUTPUT_LEVEL_trace, "in MatrixNode constructor");
#endif
}

MatrixNode::~MatrixNode()
{
#ifndef NDEBUG
    std::ostringstream outStr;
    outStr << "inside MatrixNode destructor" << std::endl;
    outStr << "number of kids = " <<  inumberOfChildren << std::endl;
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
}


ENUM_MATRIX_CONSTRUCTOR_TYPE MatrixNode::getNodeType()
{
    return nType;
}// end of OSMatrix::getNodeType()

bool MatrixNode::IsEqual(MatrixNode *that)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSExpressionTree, ENUM_OUTPUT_LEVEL_trace, "Start comparing in MatrixNode");
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
            if (this->inumberOfChildren != that->inumberOfChildren) return false;
            if (this->matrixType        != that->matrixType)        return false;
            if (this->nType             != that->nType)             return false;

            for (int i=0; i < inumberOfChildren; i++)
                if (!this->m_mChildren[i]->IsEqual(that->m_mChildren[i]))
                    return false;

            return true;
        }
    }
}// end of MatrixNode::IsEqual()

std::string MatrixNode::getMatrixNodeInXML()
{
    return "";
}// end of MatrixNode::getMatrixNodeInXML()

bool MatrixNode::alignsOnBlockBoundary(int firstRow, int firstColumn, int nRows, int nCols)
{
    return false;
}// end of MatrixNode::alignsOnBlockBoundary()
// end of methods for MatrixNode


// methods for BaseMatrix ----------------------------------------
BaseMatrix::BaseMatrix():
    baseMatrixIdx(-1),
    baseMatrix(NULL),
    targetMatrixFirstRow(0),
    targetMatrixFirstCol(0),
    baseMatrixStartRow(0),
    baseMatrixStartCol(0),
    baseMatrixEndRow(-1),
    baseMatrixEndCol(-1),
    baseTranspose(false),
    scalarMultiplier(1.0)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, "Inside the BaseMatrix Constructor");
#endif
     nType = ENUM_MATRIX_CONSTRUCTOR_TYPE_baseMatrix;
} // end of BaseMatrix

BaseMatrix::~BaseMatrix()
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, "Inside the BaseMatrix Destructor");
#endif
} // end of ~BaseMatrix

std::string BaseMatrix::getNodeName()
{
    return "baseMatrix";
}// end of BaseMatrix::getNodeName()

ENUM_MATRIX_TYPE BaseMatrix::getMatrixType()
{
    return ((OSMatrix*)baseMatrix)->getMatrixType();
}// end of BaseMatrix::getMatrixType()

ENUM_MATRIX_CONSTRUCTOR_TYPE BaseMatrix::getNodeType()
{
    return ENUM_MATRIX_CONSTRUCTOR_TYPE_baseMatrix;
}// end of BaseMatrix::getNodeType()

bool BaseMatrix::alignsOnBlockBoundary(int firstRow, int firstColumn, int nRows, int nCols)
{
    return ((OSMatrix*)baseMatrix)->alignsOnBlockBoundary(firstRow, firstColumn, nRows, nCols);
}// end of BaseMatrix::alignsOnBlockBoundary()

BaseMatrix* BaseMatrix::cloneMatrixNode()
{
    MatrixNode *nodePtr;
    nodePtr = new BaseMatrix();
    return  (BaseMatrix*)nodePtr;
}// end of BaseMatrix::cloneMatrixNode

std::string BaseMatrix::getMatrixNodeInXML()
{
    ostringstream outStr;
    outStr << "<baseMatrix";
    outStr << " baseMatrixIdx=\"" << baseMatrixIdx << "\"";
    if (baseMatrixStartRow != 0)
        outStr << " baseMatrixStartRow=\"" << baseMatrixStartRow << "\"";
    if (baseMatrixStartCol != 0)
        outStr << " baseMatrixStartCol=\"" << baseMatrixStartCol << "\"";
    if (baseMatrixEndRow >= 0)
        outStr << " baseMatrixEndRow=\"" << baseMatrixEndRow << "\"";
    if (baseMatrixEndCol >= 0)
        outStr << " baseMatrixEndCol=\"" << baseMatrixEndCol << "\"";
    if (baseTranspose)
        outStr << " baseTranspose=\"true\"";
    if (scalarMultiplier != 1)
        outStr << " scalarMultiplier=\"" << scalarMultiplier << "\"";
    if (targetMatrixFirstRow != 0)
        outStr << " targetMatrixFirstRow=\"" << targetMatrixFirstRow << "\"";
    if (targetMatrixFirstCol != 0)
        outStr << " targetMatrixFirstCol=\"" << targetMatrixFirstCol << "\"";
    outStr << "/>" << std::endl;
    return outStr.str();
}// end of BaseMatrix::getMatrixNodeInXML()

bool BaseMatrix::IsEqual(BaseMatrix *that)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSExpressionTree, ENUM_OUTPUT_LEVEL_trace, "Start comparing in BaseMatrix");
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
            if (this->baseMatrixIdx        != that->baseMatrixIdx)        return false;
            if (this->targetMatrixFirstRow != that->targetMatrixFirstRow) return false;
            if (this->targetMatrixFirstCol != that->targetMatrixFirstCol) return false;
            if (this->baseMatrixStartRow   != that->baseMatrixStartRow)   return false;
            if (this->baseMatrixStartCol   != that->baseMatrixStartCol)   return false;
            if (this->baseMatrixEndRow     != that->baseMatrixEndRow)     return false;
            if (this->baseMatrixEndCol     != that->baseMatrixEndCol)     return false;
            if (this->baseTranspose        != that->baseTranspose)        return false;
            if (this->scalarMultiplier     != that->scalarMultiplier)     return false;

            return true;
        }
    }
}// end of BaseMatrix::IsEqual()
// end of methods for BaseMatrix

MatrixElementValues::MatrixElementValues():
    rowMajor(false),
    numberOfValues(-1),
    start(NULL),
    indexes(NULL)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, "Inside the MatrixElementValues Constructor");
#endif
}// end of MatrixElementValues::MatrixElementValues()

MatrixElementValues::~MatrixElementValues()
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, "Inside the MatrixElementValues Destructor");
#endif
    if (start != NULL)
        delete start;
    start = NULL;
    if (indexes != NULL)
        delete indexes;
    indexes = NULL;
}// end of MatrixElementValues::~MatrixElementValues()


ConstantMatrixElements::ConstantMatrixElements():
    values(NULL)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, "Inside the ConstantMatrixElements Constructor");
#endif
}// end of ConstantMatrixElements::ConstantMatrixElements()

ConstantMatrixElements::~ConstantMatrixElements()
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, "Inside the ConstantMatrixElements Destructor");
#endif
    if (values != NULL)
        delete values;
    values = NULL;
}// end of ConstantMatrixElements::~ConstantMatrixElements()


bool ConstantMatrixElements::IsEqual(ConstantMatrixElements *that)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSExpressionTree, ENUM_OUTPUT_LEVEL_trace, "Start comparing in BaseMatrix");
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
            if (this->rowMajor       != that->rowMajor)       return false;
            if (this->numberOfValues != that->numberOfValues) return false;

            if (!this->start->IsEqual(that->start))     return false;
            if (!this->indexes->IsEqual(that->indexes)) return false;
            if (!this->values->IsEqual(that->values))   return false;

            return true;
        }
    }
}// end of ConstantMatrixElements::IsEqual()


VarReferenceMatrixElements::VarReferenceMatrixElements():
    values(NULL)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, "Inside the VarReferenceMatrixElements Constructor");
#endif
}// end of VarReferenceMatrixElements::VarReferenceMatrixElements()

VarReferenceMatrixElements::~VarReferenceMatrixElements()
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, "Inside the VarReferenceMatrixElements Destructor");
#endif
    if (values != NULL)
        delete values;
    values = NULL;
}// end of VarReferenceMatrixElements::~VarReferenceMatrixElements()

bool VarReferenceMatrixElements::IsEqual(VarReferenceMatrixElements *that)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSExpressionTree, ENUM_OUTPUT_LEVEL_trace, "Start comparing in VarReferenceMatrixElements");
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
            if (this->rowMajor       != that->rowMajor)       return false;
            if (this->numberOfValues != that->numberOfValues) return false;

            if (!this->start->IsEqual(that->start))     return false;
            if (!this->indexes->IsEqual(that->indexes)) return false;
            if (!this->values->IsEqual(that->values))   return false;

            return true;
        }
    }
}// end of VarReferenceMatrixElements::IsEqual()


LinearMatrixElementTerm::LinearMatrixElementTerm():
    idx(-1),
    coef(1.0)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, "Inside the LinearMatrixElementTerm Constructor");
#endif
}// end of LinearMatrixElementTerm::LinearMatrixElementTerm()

LinearMatrixElementTerm::~LinearMatrixElementTerm()
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, "Inside the LinearMatrixElementTerm Destructor");
#endif
}// end of LinearMatrixElementTerm::~LinearMatrixElementTerm()

bool LinearMatrixElementTerm::IsEqual(LinearMatrixElementTerm *that)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSExpressionTree, ENUM_OUTPUT_LEVEL_trace, "Start comparing in LinearMatrixElementTerm");
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
            if (this->idx  != that->idx)  return false;
            if (this->coef != that->coef) return false;

            return true;
        }
    }
}// end of LinearMatrixElementTerm::IsEqual()


LinearMatrixElement::LinearMatrixElement():
    numberOfVarIdx(0),
    constant(0.0),
    varIdx(NULL)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, "Inside the LinearMatrixElement Constructor");
#endif
}// end of LinearMatrixElement::LinearMatrixElement()

LinearMatrixElement::~LinearMatrixElement()
{
    std::ostringstream outStr;

#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, "Inside the LinearMatrixElement Destructor");
    outStr.str("");
    outStr.clear();
    outStr << "NUMBER OF VARIDX = " << numberOfVarIdx << endl;
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_detailed_trace, outStr.str());
#endif
    if (varIdx != NULL)
    {
        for (int i=0; i < numberOfVarIdx; i++)
        {
#ifndef NDEBUG
            outStr.str("");
            outStr.clear();
            outStr << "DESTROYING VARIDX " << i << endl;
            osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_detailed_trace, outStr.str());
#endif
            if (varIdx[i] != NULL) //valgrind: jump depends on uninitialised value
                delete varIdx[i];
            varIdx[i] = NULL;
        }
        delete [] varIdx;
        varIdx = NULL;
    }
}// end of LinearMatrixElement::~LinearMatrixElement()

bool LinearMatrixElement::IsEqual(LinearMatrixElement *that)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSExpressionTree, ENUM_OUTPUT_LEVEL_trace, "Start comparing in LinearMatrixElement");
#endif
    if (this == NULL)
    {
        if (that == NULL || that->numberOfVarIdx == 0)
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
        if (that == NULL || that->numberOfVarIdx == 0)
        {
#ifndef NDEBUG
            osoutput->OSPrint(ENUM_OUTPUT_AREA_OSExpressionTree, ENUM_OUTPUT_LEVEL_trace, 
                "Second object is NULL, first is not");
#endif
            return false;
        }
        else
        {
            if (this->numberOfVarIdx != that->numberOfVarIdx) return false;
            if (this->constant       != that->constant)       return false;

            for (int i=0; i < numberOfVarIdx; i++)
                if (!this->varIdx[i]->IsEqual(that->varIdx[i])) return false;

            return true;
        }
    }
}// end of LinearMatrixElement::IsEqual()


LinearMatrixValues::LinearMatrixValues():
    numberOfEl(0),
    el(NULL)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, "Inside the LinearMatrixValues Constructor");

#endif

}// end of LinearMatrixValues::LinearMatrixValues()


LinearMatrixValues::~LinearMatrixValues()
{
    std::ostringstream outStr;
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, "Inside the LinearMatrixValues Destructor");
//    outStr.str("");
//    outStr.clear();
//    outStr << "NUMBER OF VALUES = " << numberOfEl << endl;
//    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_detailed_trace, outStr.str());
#endif

    if (el != NULL)
    {
        for (int i=0; i < numberOfEl; i++)
        {
            if (el[i] != NULL)
                delete el[i];
            el[i] = NULL;
        }
    }
    if (el != NULL)
        delete [] el;
    el = NULL;
}// end of LinearMatrixValues::~LinearMatrixValues()

bool LinearMatrixValues::IsEqual(LinearMatrixValues *that)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSExpressionTree, ENUM_OUTPUT_LEVEL_trace, "Start comparing in LinearMatrixValues");
#endif
    if (this == NULL)
    {
        if (that == NULL || that->numberOfEl == 0)
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
        if (that == NULL || that->numberOfEl == 0)
        {
#ifndef NDEBUG
            osoutput->OSPrint(ENUM_OUTPUT_AREA_OSExpressionTree, ENUM_OUTPUT_LEVEL_trace, 
                "Second object is NULL, first is not");
#endif
            return false;
        }
        else
        {
            if (this->numberOfEl != that->numberOfEl) return false;

            for (int i=0; i < numberOfEl; i++)
                if (!this->el[i]->IsEqual(that->el[i])) return false;

            return true;
        }
    }
}// end of LinearMatrixValues::IsEqual()

#if 0
LinearMatrixNonzeros::LinearMatrixNonzeros():
    indexes(NULL),
    values(NULL)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, "Inside the LinearMatrixNonzeros Constructor");
#endif
}// end of LinearMatrixNonzeros::LinearMatrixNonzeros()


LinearMatrixNonzeros::~LinearMatrixNonzeros()
{
    std::ostringstream outStr;
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, "Inside the LinearMatrixNonzeros Destructor");
#endif
    if (indexes != NULL)
        delete indexes;
    indexes = NULL;

    if (values != NULL)
        delete values;
    values = NULL;
}// end of LinearMatrixNonzeros::~LinearMatrixNonzeros()
#endif

LinearMatrixElements::LinearMatrixElements():
    values(NULL)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, "Inside the LinearMatrixElements Constructor");
#endif
}// end of LinearMatrixElements::LinearMatrixElements()

LinearMatrixElements::~LinearMatrixElements()
{
    std::ostringstream outStr;
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, "Inside the LinearMatrixElements Destructor");
#endif
    if (values != NULL)
        delete values;
    values = NULL;
}// end of LinearMatrixElements::~LinearMatrixElements()

bool LinearMatrixElements::IsEqual(LinearMatrixElements *that)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSExpressionTree, ENUM_OUTPUT_LEVEL_trace, "Start comparing in LinearMatrixElements");
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
            if (this->rowMajor       != that->rowMajor)       return false;
            if (this->numberOfValues != that->numberOfValues) return false;

            if (!this->start->IsEqual(that->start))     return false;
            if (!this->indexes->IsEqual(that->indexes)) return false;
            if (!this->values->IsEqual(that->values))   return false;

            return true;
        }
    }
}// end of LinearMatrixElements::IsEqual()


GeneralMatrixValues::GeneralMatrixValues():
    numberOfEl(0),
    el(NULL)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, "Inside the GeneralMatrixValues Constructor");
#endif
}// end of GeneralMatrixValues::GeneralMatrixValues()

GeneralMatrixValues::~GeneralMatrixValues()
{
    std::ostringstream outStr;

#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, "Inside the GeneralMatrixValues Destructor");
    outStr.str("");
    outStr.clear();
    outStr << "NUMBER OF VALUES = " << numberOfEl << endl;
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_detailed_trace, outStr.str());
#endif
    if (numberOfEl > 0 && el != NULL)
    {
        for (int i=0; i < numberOfEl; i++)
        {
            if (el[i] != NULL)
                delete el[i];
            el[i] = NULL;
        }
    }
    if (el != NULL)
        delete [] el;
    el = NULL;
}// end of GeneralMatrixValues::~GeneralMatrixValues()

bool GeneralMatrixValues::IsEqual(GeneralMatrixValues *that)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSExpressionTree, ENUM_OUTPUT_LEVEL_trace, "Start comparing in GeneralMatrixValues");
#endif
    if (this == NULL)
    {
        if (that == NULL || that->numberOfEl == 0)
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
        if (that == NULL || that->numberOfEl == 0)
        {
#ifndef NDEBUG
            osoutput->OSPrint(ENUM_OUTPUT_AREA_OSExpressionTree, ENUM_OUTPUT_LEVEL_trace, 
                "Second object is NULL, first is not");
#endif
            return false;
        }
        else
        {
            if (this->numberOfEl != that->numberOfEl) return false;

            for (int i=0; i < numberOfEl; i++)
                if (!this->el[i]->IsEqual(that->el[i])) return false;

            return true;
        }
    }
}// end of GeneralMatrixValues::IsEqual()

GeneralMatrixElements::GeneralMatrixElements():
    values(NULL)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, "Inside the GeneralMatrixElements Constructor");
#endif
}// end of GeneralMatrixElements::GeneralMatrixElements()

GeneralMatrixElements::~GeneralMatrixElements()
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, "Inside the GeneralMatrixElements Destructor");
#endif
    if (values != NULL)
        delete values;
    values = NULL;
}// end of GeneralMatrixElements::~GeneralMatrixElements()

bool GeneralMatrixElements::IsEqual(GeneralMatrixElements *that)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSExpressionTree, ENUM_OUTPUT_LEVEL_trace, "Start comparing in GeneralMatrixElements");
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
            if (this->rowMajor       != that->rowMajor)       return false;
            if (this->numberOfValues != that->numberOfValues) return false;

            if (!this->start->IsEqual(that->start))     return false;
            if (!this->indexes->IsEqual(that->indexes)) return false;
            if (!this->values->IsEqual(that->values))   return false;

            return true;
        }
    }
}// end of GeneralMatrixElements::IsEqual()


ObjReferenceMatrixElements::ObjReferenceMatrixElements():
    values(NULL)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, "Inside the ObjReferenceMatrixElements Constructor");
#endif
}// end of ObjReferenceMatrixElements::ObjReferenceMatrixElements()

ObjReferenceMatrixElements::~ObjReferenceMatrixElements()
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, "Inside the ObjReferenceMatrixElements Destructor");
#endif
    if (values != NULL)
        delete values;
    values = NULL;
}// end of ObjReferenceMatrixElements::~ObjReferenceMatrixElements()

bool ObjReferenceMatrixElements::IsEqual(ObjReferenceMatrixElements *that)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSExpressionTree, ENUM_OUTPUT_LEVEL_trace, "Start comparing in ObjReferenceMatrixElements");
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
            if (this->rowMajor       != that->rowMajor)       return false;
            if (this->numberOfValues != that->numberOfValues) return false;

            if (!this->start->IsEqual(that->start))     return false;
            if (!this->indexes->IsEqual(that->indexes)) return false;
            if (!this->values->IsEqual(that->values))   return false;

            return true;
        }
    }
}// end of ObjReferenceMatrixElements::IsEqual()


ConReferenceMatrixElements::ConReferenceMatrixElements():
    values(NULL)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, "Inside the ConReferenceMatrixElements Constructor");
#endif
}// end of ObjReferenceMatrixElements::ObjReferenceMatrixElements()

ConReferenceMatrixElements::~ConReferenceMatrixElements()
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, "Inside the ConReferenceMatrixElements Destructor");
#endif
    if (values != NULL)
        delete values;
    values = NULL;
}// end of ConReferenceMatrixElements::~ConReferenceMatrixElements()

bool ConReferenceMatrixElements::IsEqual(ConReferenceMatrixElements *that)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSExpressionTree, ENUM_OUTPUT_LEVEL_trace, "Start comparing in ConReferenceMatrixElements");
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
            if (this->rowMajor       != that->rowMajor)       return false;
            if (this->numberOfValues != that->numberOfValues) return false;

            if (!this->start->IsEqual(that->start))     return false;
            if (!this->indexes->IsEqual(that->indexes)) return false;
            if (!this->values->IsEqual(that->values))   return false;

            return true;
        }
    }
}// end of ConReferenceMatrixElements::IsEqual()


MatrixElements::MatrixElements():
    constantElements(NULL),
    varReferenceElements(NULL),
    linearElements(NULL),
    generalElements(NULL),
    objReferenceElements(NULL),
    conReferenceElements(NULL)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, "Inside the MatrixElements Constructor");
#endif
    nType = ENUM_MATRIX_CONSTRUCTOR_TYPE_elements;
}// end of MatrixElements::MatrixElements()

MatrixElements::~MatrixElements()
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, "Inside the MatrixElements Destructor");
#endif
    if (constantElements != NULL)
        delete constantElements;
    constantElements = NULL;

    if (varReferenceElements != NULL)
        delete varReferenceElements;
    varReferenceElements = NULL;

    if (linearElements != NULL)
        delete linearElements;
    linearElements = NULL;

    if (generalElements != NULL)
        delete generalElements;
    generalElements = NULL;

    if (objReferenceElements != NULL)
        delete objReferenceElements;
    objReferenceElements = NULL;

    if (conReferenceElements != NULL)
        delete conReferenceElements;
    conReferenceElements = NULL;
}// end of MatrixElements::~MatrixElements()

bool MatrixElements::alignsOnBlockBoundary(int firstRow, int firstColumn, int nRows, int nCols)
{
    return false;
}// end of MatrixElements::alignsOnBlockBoundary()

std::string MatrixElements::getNodeName()
{
    return "elements";
}// end of MatrixElements::getNodeName()

ENUM_MATRIX_TYPE MatrixElements::getMatrixType()
{
    if (matrixType == ENUM_MATRIX_TYPE_unknown)
    {
        matrixType = ENUM_MATRIX_TYPE_zero;
        if (constantElements != NULL && constantElements->numberOfValues > 0)
            matrixType = mergeMatrixType(matrixType, ENUM_MATRIX_TYPE_constant);
        if (varReferenceElements != NULL && varReferenceElements->numberOfValues > 0)
            matrixType = mergeMatrixType(matrixType, ENUM_MATRIX_TYPE_varref);
        if (linearElements != NULL && linearElements->numberOfValues > 0)
            matrixType = mergeMatrixType(matrixType, ENUM_MATRIX_TYPE_linear);
        if (generalElements != NULL && constantElements->numberOfValues > 0)
            matrixType = mergeMatrixType(matrixType, ENUM_MATRIX_TYPE_general);
        if (objReferenceElements != NULL && objReferenceElements->numberOfValues > 0)
            matrixType = mergeMatrixType(matrixType, ENUM_MATRIX_TYPE_objref);
        if (conReferenceElements != NULL && conReferenceElements->numberOfValues > 0)
            matrixType = mergeMatrixType(matrixType, ENUM_MATRIX_TYPE_conref);
    }
    return matrixType;
}// end of MatrixElements::getMatrixType()

ENUM_MATRIX_CONSTRUCTOR_TYPE MatrixElements::getNodeType()
{
    return ENUM_MATRIX_CONSTRUCTOR_TYPE_elements;
}// end of MatrixElements::getNodeType()

bool OSMatrix::processBlocks()
{
    bool haveBlocks;
    bool haveTemp;
    bool mustSynchronize;
    int* temp;
    int  tempSize;
    int  iconst;

    // check if empty
    if (inumberOfChildren == 0)
    {
        m_miRowPartition = new int[2];
        m_miColumnPartition = new int[2];
        m_iRowPartitionSize = 2;
        m_iColumnPartitionSize = 2;
        m_miRowPartition[0] = 0;
        m_miRowPartition[1] = numberOfRows;
        m_miColumnPartition[0] = 0;
        m_miColumnPartition[1] = numberOfColumns;
        m_bBlockPartitionProcessed = true;
        return true;
    }

    // initialize for row partition
    haveBlocks = false;
    haveTemp = false;
    mustSynchronize = false;

    if (m_mChildren[0]->getNodeType() == ENUM_MATRIX_CONSTRUCTOR_TYPE_baseMatrix)
    {
        tempSize = ((BaseMatrix*)m_mChildren[0])->baseMatrix->getRowPartitionSize();
        if (tempSize > 2)
        {
            m_miRowPartition = ((BaseMatrix*)m_mChildren[0])->baseMatrix->getRowPartition();            
            m_iRowPartitionSize = tempSize;
            mustSynchronize = true;
            haveBlocks = true;
        }
        iconst = 1;
    }
    else
        iconst = 0;

    // process remaining constructors
    int jproc;
    int jcand;
    int nsync;

    for (int i=iconst; i < inumberOfChildren; i++)
    {
        if (m_mChildren[i]->getNodeType() == ENUM_MATRIX_CONSTRUCTOR_TYPE_blocks)
        {
            if (((MatrixBlocks*)m_mChildren[i])->rowOffsets->el[0] != 0)
                return false;

            if (haveBlocks == false)
            {
                m_miRowPartition    = ((MatrixBlocks*)m_mChildren[i])->rowOffsets->el;            
                m_iRowPartitionSize = ((MatrixBlocks*)m_mChildren[i])->rowOffsets->numberOfEl;
                mustSynchronize = true;
                haveBlocks = true;
            }
            else
            {
                // check if we have to synchronize
                jproc = 0;
                jcand = 0;
                nsync = 0;
                for (;;)
                {
                    if (m_miRowPartition[jproc] == ((MatrixBlocks*)m_mChildren[i])->rowOffsets->el[jcand])
                    {
                        if (haveTemp)
                            temp[nsync] = m_miRowPartition[jproc];
                        jproc++;
                        jcand++;
                        nsync++;
                    }
                    else
                    {
                        if (!haveTemp)
                        {
                            haveTemp = true;
                            tempSize = min (((MatrixBlocks*)m_mChildren[i])->rowOffsets->numberOfEl,
                                            m_iRowPartitionSize);
                            temp = new int[tempSize];
                            for (int l=0; l < nsync; l++)
                                temp[l] = m_miRowPartition[l];
                        }
                        if (m_miRowPartition[jproc] < 
                                ((MatrixBlocks*)m_mChildren[i])->rowOffsets->el[jcand])
                            jproc++;
                        else
                            jcand++;
                    }
                    if (jproc >= m_iRowPartitionSize || 
                        jcand >= ((MatrixBlocks*)m_mChildren[i])->rowOffsets->numberOfEl)
                        break;
                }
            }

            if (haveTemp && temp[nsync-1] < numberOfRows)
            {
                temp[nsync] = numberOfRows;
                nsync++;
            }
        }

        if (haveTemp)
        {
            if (m_miRowPartition != NULL) delete m_miRowPartition;
            m_miRowPartition = new int[nsync];
            for (int l=0; l<nsync; l++)
                m_miRowPartition[l] = temp[l];
            delete [] temp;
            m_iRowPartitionSize = nsync;
            if (nsync == 2) break;
        }
    }

    if (haveBlocks == false)
    {
        m_miRowPartition = new int[2];
        m_iRowPartitionSize = 2;
        m_miRowPartition[0] = 0;
        m_miRowPartition[1] = numberOfRows;
    }

    // here we do the same thing for the columns
    haveBlocks = false;
    haveTemp = false;
    mustSynchronize = false;

    if (m_mChildren[0]->getNodeType() == ENUM_MATRIX_CONSTRUCTOR_TYPE_baseMatrix)
    {
        tempSize = ((BaseMatrix*)m_mChildren[0])->baseMatrix->getColumnPartitionSize();
        if (tempSize > 2)
        {
            m_miColumnPartition = ((BaseMatrix*)m_mChildren[0])->baseMatrix->getColumnPartition();            
            m_iColumnPartitionSize = tempSize;
            mustSynchronize = true;
            haveBlocks = true;
        }
        iconst = 1;
    }
    else
        iconst = 0;

    // process remaining constructors
    for (int i=iconst; i < inumberOfChildren; i++)
    {
        if (m_mChildren[i]->getNodeType() == ENUM_MATRIX_CONSTRUCTOR_TYPE_blocks)
        {
            if (((MatrixBlocks*)m_mChildren[i])->colOffsets->el[0] != 0)
                return false;

            if (haveBlocks == false)
            {
                m_miColumnPartition    = ((MatrixBlocks*)m_mChildren[i])->colOffsets->el;            
                m_iColumnPartitionSize = ((MatrixBlocks*)m_mChildren[i])->colOffsets->numberOfEl;
                mustSynchronize = true;
                haveBlocks = true;
            }
            else
            {
                // check if we have to synchronize
                jproc = 0;
                jcand = 0;
                nsync = 0;
                for (;;)
                {
                    if (m_miColumnPartition[jproc] == ((MatrixBlocks*)m_mChildren[i])->colOffsets->el[jcand])
                    {
                        if (haveTemp)
                            temp[nsync] = m_miColumnPartition[jproc];
                        jproc++;
                        jcand++;
                        nsync++;
                    }
                    else
                    {
                        if (!haveTemp)
                        {
                            haveTemp = true;
                            tempSize = min (((MatrixBlocks*)m_mChildren[i])->colOffsets->numberOfEl,
                                            m_iColumnPartitionSize);
                            temp = new int[tempSize];
                            for (int l=0; l < nsync; l++)
                                temp[l] = m_miColumnPartition[l];
                        }
                        if (m_miColumnPartition[jproc] < 
                                ((MatrixBlocks*)m_mChildren[i])->colOffsets->el[jcand])
                            jproc++;
                        else
                            jcand++;
                    }
                    if (jproc >= m_iColumnPartitionSize || 
                        jcand >= ((MatrixBlocks*)m_mChildren[i])->colOffsets->numberOfEl)
                        break;
                }
            }

            if (haveTemp && temp[nsync-1] < numberOfColumns)
            {
                temp[nsync] = numberOfColumns;
                nsync++;
            }
        }

        if (haveTemp)
        {
            if (m_miColumnPartition != NULL) delete m_miColumnPartition;
            m_miColumnPartition = new int[nsync];
            for (int l=0; l<nsync; l++)
                m_miColumnPartition[l] = temp[l];
            delete [] temp;
            m_iColumnPartitionSize = nsync;
            if (nsync == 2) break;
        }
    }

    if (haveBlocks == false)
    {
        m_miColumnPartition = new int[2];
        m_iColumnPartitionSize = 2;
        m_miColumnPartition[0] = 0;
        m_miColumnPartition[1] = numberOfRows;
    }

    return true;
}// end of OSMatrix::processBlocks()

bool OSMatrix::isBlockDiagonal()
{
    bool isDiagonal;
    int  haveBaseBlocks = false;
    int  nBlocks;
    int  iconst;

    // check if empty
    if (inumberOfChildren == 0)
        return true;

    // check for blocks in baseMatrix --- if any
    if (m_mChildren[0]->getNodeType() == ENUM_MATRIX_CONSTRUCTOR_TYPE_baseMatrix)
    {
        int tempSize = ((BaseMatrix*)m_mChildren[0])->baseMatrix->getRowPartitionSize();
        if (tempSize > 2)
        {
            haveBaseBlocks = true;
            isDiagonal = ((BaseMatrix*)m_mChildren[0])->baseMatrix->isBlockDiagonal();
            if (!isDiagonal) return false;
        }
        else
            isDiagonal = true; 
        iconst = 1;
    }
    else
        iconst = 0;

    // process remaining constructors
    int  jproc;
    int  jcand;
    int  nsync;
    int* rowPartition     = getRowPartition();
    int  rowPartitionSize = getRowPartitionSize();
    int* colPartition     = getColumnPartition();
    int  colPartitionSize = getColumnPartitionSize();

    for (int i=iconst; i < inumberOfChildren; i++)
        if (m_mChildren[i]->getNodeType() == ENUM_MATRIX_CONSTRUCTOR_TYPE_blocks)
            for (int j=0; j < ((MatrixBlocks*)m_mChildren[i])->numberOfBlocks; j++)
                if ( ((MatrixBlock*)((MatrixBlocks*)m_mChildren[i])->m_mChildren[j])->blockRowIdx !=
                     ((MatrixBlock*)((MatrixBlocks*)m_mChildren[i])->m_mChildren[j])->blockColIdx)
                    return false;

    // Now check if there are other constructors that might introduce elements outside the block diagonal
    if (iconst == 1 && !haveBaseBlocks) return false;
    for (int i=iconst; i < inumberOfChildren; i++)
        if (m_mChildren[i]->getNodeType() == ENUM_MATRIX_CONSTRUCTOR_TYPE_elements)
        {
            if (((MatrixElements*)m_mChildren[i])->constantElements != NULL)
            {
                if (((MatrixElements*)m_mChildren[i])->constantElements->rowMajor)
                {
                    for (int j=1; j < colPartitionSize; j++)
                        for (int  k = colPartition[j-1]; k < colPartition[j]; j++)
                           for (int l = ((MatrixElements*)m_mChildren[i])->constantElements->start->el[k];
                                    l < ((MatrixElements*)m_mChildren[i])->constantElements->start->el[k+1];
                                    l++)
                            if ( ((MatrixElements*)m_mChildren[i])->constantElements->indexes->el[l]
                                     <  rowPartition[j-1] ||
                                 ((MatrixElements*)m_mChildren[i])->constantElements->indexes->el[l]
                                     >= rowPartition[j] )
                                return false;
                }
                else
                {
                    for (int j=1; j < rowPartitionSize; j++)
                        for (int  k = rowPartition[j-1]; k < rowPartition[j]; j++)
                           for (int l = ((MatrixElements*)m_mChildren[i])->constantElements->start->el[k];
                                    l < ((MatrixElements*)m_mChildren[i])->constantElements->start->el[k+1];
                                    l++)
                            if ( ((MatrixElements*)m_mChildren[i])->constantElements->indexes->el[l]
                                     <  colPartition[j-1] ||
                                 ((MatrixElements*)m_mChildren[i])->constantElements->indexes->el[l]
                                     >= colPartition[j] )
                                return false;
                }
            }


            if (((MatrixElements*)m_mChildren[i])->varReferenceElements != NULL)
            {
                if (((MatrixElements*)m_mChildren[i])->varReferenceElements->rowMajor)
                {
                    for (int j=1; j < colPartitionSize; j++)
                        for (int  k = colPartition[j-1]; k < colPartition[j]; j++)
                           for (int l = ((MatrixElements*)m_mChildren[i])->varReferenceElements->start->el[k];
                                    l < ((MatrixElements*)m_mChildren[i])->varReferenceElements->start->el[k+1];
                                    l++)
                            if ( ((MatrixElements*)m_mChildren[i])->varReferenceElements->indexes->el[l]
                                     <  rowPartition[j-1] ||
                                 ((MatrixElements*)m_mChildren[i])->varReferenceElements->indexes->el[l]
                                     >= rowPartition[j] )
                                return false;
                }
                else
                {
                    for (int j=1; j < rowPartitionSize; j++)
                        for (int  k = rowPartition[j-1]; k < rowPartition[j]; j++)
                           for (int l = ((MatrixElements*)m_mChildren[i])->varReferenceElements->start->el[k];
                                    l < ((MatrixElements*)m_mChildren[i])->varReferenceElements->start->el[k+1];
                                    l++)
                            if ( ((MatrixElements*)m_mChildren[i])->varReferenceElements->indexes->el[l]
                                     <  colPartition[j-1] ||
                                 ((MatrixElements*)m_mChildren[i])->varReferenceElements->indexes->el[l]
                                     >= colPartition[j] )
                                return false;
                }
            }


            if (((MatrixElements*)m_mChildren[i])->linearElements != NULL)
            {
                if (((MatrixElements*)m_mChildren[i])->linearElements->rowMajor)
                {
                    for (int j=1; j < colPartitionSize; j++)
                        for (int  k = colPartition[j-1]; k < colPartition[j]; j++)
                           for (int l = ((MatrixElements*)m_mChildren[i])->linearElements->start->el[k];
                                    l < ((MatrixElements*)m_mChildren[i])->linearElements->start->el[k+1];
                                    l++)
                            if ( ((MatrixElements*)m_mChildren[i])->linearElements->indexes->el[l]
                                     <  rowPartition[j-1] ||
                                 ((MatrixElements*)m_mChildren[i])->linearElements->indexes->el[l]
                                     >= rowPartition[j] )
                                return false;
                }
                else
                {
                    for (int j=1; j < rowPartitionSize; j++)
                        for (int  k = rowPartition[j-1]; k < rowPartition[j]; j++)
                           for (int l = ((MatrixElements*)m_mChildren[i])->linearElements->start->el[k];
                                    l < ((MatrixElements*)m_mChildren[i])->linearElements->start->el[k+1];
                                    l++)
                            if ( ((MatrixElements*)m_mChildren[i])->linearElements->indexes->el[l]
                                     <  colPartition[j-1] ||
                                 ((MatrixElements*)m_mChildren[i])->linearElements->indexes->el[l]
                                     >= colPartition[j] )
                                return false;
                }
            }


            if (((MatrixElements*)m_mChildren[i])->generalElements != NULL)
            {
                if (((MatrixElements*)m_mChildren[i])->generalElements->rowMajor)
                {
                    for (int j=1; j < colPartitionSize; j++)
                        for (int  k = colPartition[j-1]; k < colPartition[j]; j++)
                           for (int l = ((MatrixElements*)m_mChildren[i])->generalElements->start->el[k];
                                    l < ((MatrixElements*)m_mChildren[i])->generalElements->start->el[k+1];
                                    l++)
                            if ( ((MatrixElements*)m_mChildren[i])->generalElements->indexes->el[l]
                                     <  rowPartition[j-1] ||
                                 ((MatrixElements*)m_mChildren[i])->generalElements->indexes->el[l]
                                     >= rowPartition[j] )
                                return false;
                }
                else
                {
                    for (int j=1; j < rowPartitionSize; j++)
                        for (int  k = rowPartition[j-1]; k < rowPartition[j]; j++)
                           for (int l = ((MatrixElements*)m_mChildren[i])->generalElements->start->el[k];
                                    l < ((MatrixElements*)m_mChildren[i])->generalElements->start->el[k+1];
                                    l++)
                            if ( ((MatrixElements*)m_mChildren[i])->generalElements->indexes->el[l]
                                     <  colPartition[j-1] ||
                                 ((MatrixElements*)m_mChildren[i])->generalElements->indexes->el[l]
                                     >= colPartition[j] )
                                return false;
                }
            }


            if (((MatrixElements*)m_mChildren[i])->objReferenceElements != NULL)
            {
                if (((MatrixElements*)m_mChildren[i])->objReferenceElements->rowMajor)
                {
                    for (int j=1; j < colPartitionSize; j++)
                        for (int  k = colPartition[j-1]; k < colPartition[j]; j++)
                           for (int l = ((MatrixElements*)m_mChildren[i])->objReferenceElements->start->el[k];
                                    l < ((MatrixElements*)m_mChildren[i])->objReferenceElements->start->el[k+1];
                                    l++)
                            if ( ((MatrixElements*)m_mChildren[i])->objReferenceElements->indexes->el[l]
                                     <  rowPartition[j-1] ||
                                 ((MatrixElements*)m_mChildren[i])->objReferenceElements->indexes->el[l]
                                     >= rowPartition[j] )
                                return false;
                }
                else
                {
                    for (int j=1; j < rowPartitionSize; j++)
                        for (int  k = rowPartition[j-1]; k < rowPartition[j]; j++)
                           for (int l = ((MatrixElements*)m_mChildren[i])->objReferenceElements->start->el[k];
                                    l < ((MatrixElements*)m_mChildren[i])->objReferenceElements->start->el[k+1];
                                    l++)
                            if ( ((MatrixElements*)m_mChildren[i])->objReferenceElements->indexes->el[l]
                                     <  colPartition[j-1] ||
                                 ((MatrixElements*)m_mChildren[i])->objReferenceElements->indexes->el[l]
                                     >= colPartition[j] )
                                return false;
                }
            }


            if (((MatrixElements*)m_mChildren[i])->conReferenceElements != NULL)
            {
                if (((MatrixElements*)m_mChildren[i])->conReferenceElements->rowMajor)
                {
                    for (int j=1; j < colPartitionSize; j++)
                        for (int  k = colPartition[j-1]; k < colPartition[j]; j++)
                           for (int l = ((MatrixElements*)m_mChildren[i])->conReferenceElements->start->el[k];
                                    l < ((MatrixElements*)m_mChildren[i])->conReferenceElements->start->el[k+1];
                                    l++)
                            if ( ((MatrixElements*)m_mChildren[i])->conReferenceElements->indexes->el[l]
                                     <  rowPartition[j-1] ||
                                 ((MatrixElements*)m_mChildren[i])->conReferenceElements->indexes->el[l]
                                     >= rowPartition[j] )
                                return false;
                }
                else
                {
                    for (int j=1; j < rowPartitionSize; j++)
                        for (int  k = rowPartition[j-1]; k < rowPartition[j]; j++)
                           for (int l = ((MatrixElements*)m_mChildren[i])->conReferenceElements->start->el[k];
                                    l < ((MatrixElements*)m_mChildren[i])->conReferenceElements->start->el[k+1];
                                    l++)
                            if ( ((MatrixElements*)m_mChildren[i])->conReferenceElements->indexes->el[l]
                                     <  colPartition[j-1] ||
                                 ((MatrixElements*)m_mChildren[i])->conReferenceElements->indexes->el[l]
                                     >= colPartition[j] )
                                return false;
                }
            }
        }
        else if  (m_mChildren[i]->getNodeType() == ENUM_MATRIX_CONSTRUCTOR_TYPE_transformation)
            return false;

    return true;
}// end of OSMatrix::isBlockDiagonal()

bool OSMatrix::alignsOnBlockBoundary(int firstRow, int firstColumn, int nRows, int nCols)
{
    bool accumulator = true;
    for (int i=0; i < inumberOfChildren; i++)
        if (m_mChildren[i]->nType == ENUM_MATRIX_CONSTRUCTOR_TYPE_baseMatrix)
            accumulator &= m_mChildren[i]->alignsOnBlockBoundary(firstRow, firstColumn, nRows, nCols);
        else if (m_mChildren[i]->nType == ENUM_MATRIX_CONSTRUCTOR_TYPE_elements)
            return false;
        else if (m_mChildren[i]->nType == ENUM_MATRIX_CONSTRUCTOR_TYPE_transformation)
            return false;
        else if (m_mChildren[i]->nType == ENUM_MATRIX_CONSTRUCTOR_TYPE_blocks)
            accumulator &= m_mChildren[i]->alignsOnBlockBoundary(firstRow, firstColumn, nRows, nCols);
    return accumulator;
}// end of OSMatrix::alignsOnBlockBoundary()

int OSMatrix::getRowPartitionSize()
{
    if (!m_bBlockPartitionProcessed) 
    {
        bool OK = processBlocks();
        if (!OK) throw ErrorClass("Error processing blocks");
    }
    return m_iRowPartitionSize;
}// end of OSMatrix::getRowPartitionSize()

int* OSMatrix::getRowPartition()
{
    if (!m_bBlockPartitionProcessed) 
    {
        bool OK = processBlocks();
        if (!OK) throw ErrorClass("Error processing blocks");
    }
    return m_miRowPartition;
}// end of OSMatrix::getRowPartition()

int OSMatrix::getColumnPartitionSize()
{
    if (!m_bBlockPartitionProcessed) 
    {
        bool OK = processBlocks();
        if (!OK) throw ErrorClass("Error processing blocks");
    }
    return m_iColumnPartitionSize;
}// end of OSMatrix::getColumnPartitionSize()

int* OSMatrix::getColumnPartition()
{
    if (!m_bBlockPartitionProcessed) 
    {
        bool OK = processBlocks();
        if (!OK) throw ErrorClass("Error processing blocks");
    }
    return m_miColumnPartition;
}// end of OSMatrix::getColumnPartition()


MatrixElements* MatrixElements::cloneMatrixNode()
{
    MatrixElements *nodePtr;
    nodePtr = new MatrixElements();
    return  (MatrixElements*)nodePtr;
}// end of MatrixElements::cloneMatrixNode

std::string MatrixElements::getMatrixNodeInXML()
{
    ostringstream outStr;
    outStr << "<elements>" << std::endl;

    // write <constantElements> (if present)
    if (constantElements != NULL)
    {
        outStr << "<constantElements";
        if (constantElements->rowMajor)
            outStr << " rowMajor=\"true\"";
        outStr << " numberOfValues=\"" << constantElements->numberOfValues << "\"";
        outStr << ">" << std::endl;

        outStr << "<start>" << std::endl;
        outStr << writeIntVectorData(constantElements->start, true, false);
        outStr << "</start>" << std::endl;

        if (constantElements->numberOfValues > 0)
        {
            outStr << "<indexes>" << std::endl;
            outStr << writeIntVectorData(constantElements->indexes, true, false);
            outStr << "</indexes>" << std::endl;

            outStr << "<values>" << std::endl;
            outStr << writeDblVectorData(constantElements->values, true, false);
            outStr << "</values>" << std::endl;
        }

        outStr << "</constantElements>" << std::endl;
    }

    if (varReferenceElements != NULL)
    {
        outStr << "<varReferenceElements";
        if (varReferenceElements->rowMajor)
            outStr << " rowMajor=\"true\"";
        outStr << " numberOfValues=\"" << varReferenceElements->numberOfValues << "\"";
        outStr << ">" << std::endl;

        outStr << "<start>" << std::endl;
        outStr << writeIntVectorData(varReferenceElements->start, true, false);
        outStr << "</start>" << std::endl;

        if (varReferenceElements->numberOfValues > 0)
        {
            outStr << "<indexes>" << std::endl;
            outStr << writeIntVectorData(varReferenceElements->indexes, true, false);
            outStr << "</indexes>" << std::endl;

            outStr << "<values>" << std::endl;
            outStr << writeIntVectorData(varReferenceElements->values, true, false);
            outStr << "</values>" << std::endl;
        }

        outStr << "</varReferenceElements>" << std::endl;
    }

    if (linearElements != NULL)
    {
        outStr << "<linearElements";
        if (linearElements->rowMajor)
            outStr << " rowMajor=\"true\"";
        outStr << " numberOfValues=\"" << linearElements->numberOfValues << "\"";
        outStr << ">" << std::endl;
 
        outStr << "<start>" << std::endl;
        outStr << writeIntVectorData(linearElements->start, true, false);
        outStr << "</start>" << std::endl;

        if (linearElements->numberOfValues > 0)
        {
            outStr << "<indexes>" << std::endl;
            outStr << writeIntVectorData(linearElements->indexes, true, false);
            outStr << "</indexes>" << std::endl;

            int i,j;
            outStr << "<values>" << std::endl;
            for (i=0; i < linearElements->numberOfValues; i++)
            {
                outStr << "<el";
                outStr << " numberOfVarIdx=\"" << linearElements->values->el[i]->numberOfVarIdx << "\"";
                if (linearElements->values->el[i]->constant != 0.0)
                    outStr << " constant=\"" << linearElements->values->el[i]->constant << "\"";
                outStr << ">" << std::endl;

                for (j=0; j < linearElements->values->el[i]->numberOfVarIdx; j++)
                {
                    outStr << "<varIdx";
                    if (linearElements->values->el[i]->varIdx[j]->coef != 1.0)
                        outStr << " coef=\"" << linearElements->values->el[i]->varIdx[j]->coef << "\"";
                    outStr << ">";
                    outStr << linearElements->values->el[i]->varIdx[j]->idx; 
                    outStr << "</varIdx>" << std::endl;
                }

                outStr << "</el>" << std::endl;
            }
            outStr << "</values>" << std::endl;
        }
        outStr << "</linearElements>" << std::endl;
    }

    if (generalElements != NULL)
    {
        outStr << "<generalElements";
        if (generalElements->rowMajor)
            outStr << " rowMajor=\"true\"";
        outStr << " numberOfValues=\"" << generalElements->numberOfValues << "\"";
        outStr << ">" << std::endl;
 
        outStr << "<start>" << std::endl;
        outStr << writeIntVectorData(generalElements->start, true, false);
        outStr << "</start>" << std::endl;

        if (generalElements->numberOfValues > 0)
        {
            outStr << "<indexes>" << std::endl;
            outStr << writeIntVectorData(generalElements->indexes, true, false);
            outStr << "</indexes>" << std::endl;

            outStr << "<values>" << std::endl;
            for (int i=0; i < generalElements->numberOfValues; i++)
            {
                outStr << "<el>";
                outStr << generalElements->values->el[i]->m_treeRoot->getNonlinearExpressionInXML();
                outStr << "</el>" << std::endl;
            }
            outStr << "</values>" << std::endl;
        }

        outStr << "</generalElements>" << std::endl;
    }
    if (objReferenceElements != NULL)
    {
        outStr << "<objReferenceElements";
        if (objReferenceElements->rowMajor)
            outStr << " rowMajor=\"true\"";
        outStr << " numberOfValues=\"" << objReferenceElements->numberOfValues << "\"";
        outStr << ">" << std::endl;

        outStr << "<start>" << std::endl;
        outStr << writeIntVectorData(objReferenceElements->start, true, false);
        outStr << "</start>" << std::endl;

        if (objReferenceElements->numberOfValues > 0)
        {
            outStr << "<indexes>" << std::endl;
            outStr << writeIntVectorData(objReferenceElements->indexes, true, false);
            outStr << "</indexes>" << std::endl;

            outStr << "<values>" << std::endl;
            outStr << writeIntVectorData(objReferenceElements->values, true, false);
            outStr << "</values>" << std::endl;
        }

        outStr << "</objReferenceElements>" << std::endl;
    }
    if (conReferenceElements != NULL)
    {
        outStr << "<conReferenceElements";
        if (conReferenceElements->rowMajor)
            outStr << " rowMajor=\"true\"";
        outStr << " numberOfValues=\"" << conReferenceElements->numberOfValues << "\"";
        outStr << ">" << std::endl;

        outStr << "<start>" << std::endl;
        outStr << writeIntVectorData(conReferenceElements->start, true, false);
        outStr << "</start>" << std::endl;

        if (conReferenceElements->numberOfValues > 0)
        {
            outStr << "<indexes>" << std::endl;
            outStr << writeIntVectorData(conReferenceElements->indexes, true, false);
            outStr << "</indexes>" << std::endl;

            outStr << "<values>" << std::endl;
            outStr << writeIntVectorData(conReferenceElements->values, true, false);
            outStr << "</values>" << std::endl;
        }

        outStr << "</conReferenceElements>" << std::endl;
    }

    outStr << "</elements>" << std::endl;
    return outStr.str();
}// end of MatrixElements::getMatrixNodeInXML()

bool MatrixElements::IsEqual(MatrixElements *that)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSExpressionTree, ENUM_OUTPUT_LEVEL_trace, "Start comparing in BaseMatrix");
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
            if (!this->constantElements->IsEqual(that->constantElements)) return false;
            if (!this->varReferenceElements->IsEqual(that->varReferenceElements)) return false;
            if (!this->linearElements->IsEqual(that->linearElements)) return false;
            if (!this->generalElements->IsEqual(that->generalElements)) return false;
            if (!this->objReferenceElements->IsEqual(that->objReferenceElements)) return false;
            if (!this->conReferenceElements->IsEqual(that->conReferenceElements)) return false;

            return true;
        }
    }
}// end of MatrixElements::IsEqual()
// end of methods for MatrixElements


// methods for MatrixTransformation --------------------------------------------
MatrixTransformation::MatrixTransformation():
    transformation(NULL)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, "Inside the MatrixTransformation Constructor");
#endif
    nType = ENUM_MATRIX_CONSTRUCTOR_TYPE_transformation;
}// end of MatrixTransformation::MatrixTransformation()

MatrixTransformation::~MatrixTransformation()
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, "Inside the MatrixTransformation Destructor");
#endif
    if (transformation != NULL)
        delete transformation;
    transformation = NULL;
}// end of MatrixTransformation::~MatrixTransformation()

bool MatrixTransformation::alignsOnBlockBoundary(int firstRow, int firstColumn, int nRows, int nCols)
{
    return false;
}// end of MatrixTransformation::~alignsOnBlockBoundary()

std::string MatrixTransformation::getNodeName()
{
    return "transformation";
}// end of MatrixTransformation::getNodeName()

ENUM_MATRIX_TYPE MatrixTransformation::getMatrixType()
{
    if (matrixType == ENUM_MATRIX_TYPE_unknown)
        matrixType =  ENUM_MATRIX_TYPE_general;
    return matrixType;
}// end of MatrixTransformation::getMatrixType()

ENUM_MATRIX_CONSTRUCTOR_TYPE MatrixTransformation::getNodeType()
{
    return ENUM_MATRIX_CONSTRUCTOR_TYPE_transformation;
}// end of MatrixTransformation::getNodeType()

MatrixTransformation* MatrixTransformation::cloneMatrixNode()
{
    MatrixTransformation *nodePtr;
    nodePtr = new MatrixTransformation();
    return  (MatrixTransformation*)nodePtr;
}// end of MatrixTransformation::cloneMatrixNode

std::string MatrixTransformation::getMatrixNodeInXML()
{
    ostringstream outStr;
    outStr <<  "<transformation>" << std::endl;
    
    outStr <<    transformation->getNonlinearExpressionInXML() << std::endl; 

    outStr << "</transformation>" << std::endl;
    return outStr.str();
}// end of MatrixTransformation::getMatrixNodeInXML()

bool MatrixTransformation::IsEqual(MatrixTransformation *that)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_debug, "Start comparing in MatrixTransformation");
#endif
    if (this == NULL)
    {
        if (that == NULL)
            return true;
        else
        {
#ifndef NDEBUG
            osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_debug, 
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
            osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_debug, 
                "Second object is NULL, first is not");
#endif
            return false;
        }
        else
        {
            if (!this->transformation->IsEqual(that->transformation))
                return false;

            return true;
        }
    }
}// end of MatrixTransformation::IsEqual()
//end of methods for MatrixTransformation

// methods for MatrixBlocks -----------------------------------------------
MatrixBlocks::MatrixBlocks():
    numberOfBlocks(0),
    colOffsets(NULL),
    rowOffsets(NULL),
    block(NULL)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, "Inside the MatrixBlocks Constructor");
#endif
    nType = ENUM_MATRIX_CONSTRUCTOR_TYPE_blocks;
}// end of MatrixBlocks::MatrixBlocks()

MatrixBlocks::~MatrixBlocks()
{
    std::ostringstream outStr;

#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, "Inside the MatrixBlocks Destructor");
    outStr.str("");
    outStr.clear();
    outStr << "NUMBER OF BLOCKS = " << numberOfBlocks << endl;
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_detailed_trace, outStr.str());
#endif
    if (colOffsets != NULL)
        delete colOffsets;
    colOffsets = NULL;
    if (rowOffsets != NULL)
        delete rowOffsets;
    rowOffsets = NULL;

    if(numberOfBlocks > 0 && block != NULL)
    {
        for (int i=0; i < numberOfBlocks; i++)
        {
            if (block[i] != NULL)
                delete block[i];
            block[i] = NULL;
        }
    }
    if (block != NULL)
        delete [] block;
    block = NULL;
}// end of MatrixBlocks::~MatrixBlocks()

bool MatrixBlocks::alignsOnBlockBoundary(int firstRow, int firstColumn, int nRows, int nCols)
{
    bool accumulator = false;
    int  nrBlocks = rowOffsets->numberOfEl - 1;
    int  ncBlocks = colOffsets->numberOfEl - 1;
    for (int i=0; i < nrBlocks; i++)
        if ( (rowOffsets->el[i] == firstRow) && ((firstRow+nRows) == rowOffsets->el[i+1]) )
        {
            accumulator = true;
            break;
        }
    if (!accumulator) return false;
    for (int i=0; i < ncBlocks; i++)
        if ( (colOffsets->el[i] == firstColumn) && ((firstColumn+nCols) == colOffsets->el[i+1]) )
        {
            accumulator = true;
            break;
        }
    return accumulator;
}// end of MatrixTransformation::~alignsOnBlockBoundary()

std::string MatrixBlocks::getNodeName()
{
    return "blocks";
}// end of MatrixBlocks::getNodeName()

ENUM_MATRIX_TYPE MatrixBlocks::getMatrixType()
{
    if (matrixType == ENUM_MATRIX_TYPE_unknown)
    {
        matrixType == ENUM_MATRIX_TYPE_zero;
        for (int i=0; i<inumberOfChildren; i++)
            matrixType = mergeMatrixType(matrixType, m_mChildren[i]->getMatrixType());
    }
    return matrixType;
}// end of MatrixBlocks::getMatrixType()

ENUM_MATRIX_CONSTRUCTOR_TYPE MatrixBlocks::getNodeType()
{
    return ENUM_MATRIX_CONSTRUCTOR_TYPE_blocks;
}// end of MatrixBlocks::getNodeType()

MatrixBlocks* MatrixBlocks::cloneMatrixNode()
{
    MatrixNode *nodePtr;
    nodePtr = new MatrixBlocks();
    return  (MatrixBlocks*)nodePtr;
}// end of MatrixBlocks::cloneMatrixNode

std::string MatrixBlocks::getMatrixNodeInXML()
{
    ostringstream outStr;
    outStr << "<blocks numberOfBlocks=\"" << numberOfBlocks << "\">" << std::endl;
    outStr << "<colOffsets numberOfEl=\"" << colOffsets->numberOfEl << "\">" << std::endl;
    outStr << writeIntVectorData(colOffsets, true, false);
    outStr << "</colOffsets>" << std::endl;
    outStr << "<rowOffsets numberOfEl=\"" << rowOffsets->numberOfEl << "\">" << std::endl; 
    outStr << writeIntVectorData(rowOffsets, true, false);
    outStr << "</rowOffsets>" << std::endl;

    for (int i=0; i < numberOfBlocks; i++)
        outStr << m_mChildren[i]->getMatrixNodeInXML();

    outStr << "</blocks>" << std::endl;
    return outStr.str();
}// end of MatrixBlocks::getMatrixNodeInXML()

bool MatrixBlocks::IsEqual(MatrixBlocks *that)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_debug, "Start comparing in MatrixBlocks");
#endif
    if (this == NULL)
    {
        if (that == NULL || that->numberOfBlocks == 0)
            return true;
        else
        {
#ifndef NDEBUG
            osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_debug, 
                "First object is NULL, second is not");
#endif
            return false;
        }
    }
    else
    {
        if (that == NULL || this->numberOfBlocks == 0)
        {
#ifndef NDEBUG
            osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_debug, 
                "Second object is NULL, first is not");
#endif
            return false;
        }
        else
        {
            if (this->numberOfBlocks != this->numberOfBlocks) return false; 
            if (!this->colOffsets->IsEqual(that->colOffsets))
                return false;
            if (!this->rowOffsets->IsEqual(that->rowOffsets))
                return false;

            for (int i = 0; i < this->numberOfBlocks; i++)
                if (!this->block[i]->IsEqual(that->block[i]))
                    return false;

            return true;
        }
    }
}// end of MatrixBlocks::IsEqual()
// end of methods for MatrixBlocks

// methods for MatrixConstructor ----------------------------------------------
MatrixConstructor::MatrixConstructor()
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, "Inside the  MatrixConstructor Constructor");
#endif
}

MatrixConstructor::~MatrixConstructor()
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, "Inside the MatrixConstructor Destructor");
#endif
}//end of MatrixConstructor::~MatrixConstructor
// end of methods for MatrixConstructor




// methods for MatrixType
MatrixType::MatrixType():
    MatrixNode(),
    numberOfRows(0),
    numberOfColumns(0),
    symmetry(ENUM_MATRIX_SYMMETRY_none)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, "Inside the MatrixType Constructor");
#endif
} // end of MatrixType

MatrixType::~MatrixType()
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, "Inside the MatrixType Destructor");
#endif
}// end of ~MatrixType

bool MatrixType::matrixHasBase()
{
    return (inumberOfChildren > 0 && m_mChildren != NULL 
                                  && m_mChildren[0]->nType == ENUM_MATRIX_CONSTRUCTOR_TYPE_baseMatrix);
}// end of matrixHasBase

bool MatrixType::matrixHasElements()
{
    if (inumberOfChildren == 0 || m_mChildren == NULL) return false;
    for (int i=0; i < inumberOfChildren; i++)
    {
        if (m_mChildren[0]->nType == ENUM_MATRIX_CONSTRUCTOR_TYPE_elements) return true;
    }
    return false;
}// end of matrixHasElements

bool MatrixType::matrixHasTransformations()
{
    if (inumberOfChildren == 0 || m_mChildren == NULL) return false;
    for (int i=0; i < inumberOfChildren; i++)
    {
        if (m_mChildren[0]->nType == ENUM_MATRIX_CONSTRUCTOR_TYPE_transformation) return true;
    }
    return false;
}// end of matrixHasTransformations

bool MatrixType::matrixHasBlocks()
{
    if (inumberOfChildren == 0 || m_mChildren == NULL) return false;
    for (int i=0; i < inumberOfChildren; i++)
    {
        if (m_mChildren[0]->nType == ENUM_MATRIX_CONSTRUCTOR_TYPE_blocks) return true;
    }
    return false;
}// end of matrixHasBlocks

int  MatrixType::getNumberOfElementConstructors()
{
    int k = 0;
    if (inumberOfChildren == 0 || m_mChildren == NULL) return 0;
    for (int i=0; i < inumberOfChildren; i++)
    {
        if (m_mChildren[0]->nType == ENUM_MATRIX_CONSTRUCTOR_TYPE_elements) k++;
    }
    return k++;
}// end of getNumberOfElementConstructors

int  MatrixType::getNumberOfTransformationConstructors()
{
    int k = 0;
    if (inumberOfChildren == 0 || m_mChildren == NULL) return 0;
    for (int i=0; i < inumberOfChildren; i++)
    {
        if (m_mChildren[0]->nType == ENUM_MATRIX_CONSTRUCTOR_TYPE_transformation) k++;
    }
    return k++;
}// end of getNumberOfTransformationConstructors

int  MatrixType::getNumberOfBlocksConstructors()
{
    int k = 0;
    if (inumberOfChildren == 0 || m_mChildren == NULL) return 0;
    for (int i=0; i < inumberOfChildren; i++)
    {
        if (m_mChildren[0]->nType == ENUM_MATRIX_CONSTRUCTOR_TYPE_blocks) k++;
    }
    return k++;
}// end of getNumberOfBlocksConstructors

GeneralSparseMatrix* MatrixType::getMatrixInColumnMajorForm()
{
}// end of getMatrixInColumnMajorForm

GeneralSparseMatrix* MatrixType::getMatrixInRowMajorForm()
{
}// end of getMatrixInRowMajorForm

GeneralSparseMatrix* MatrixType::getMatrixBlockInColumnMajorForm(int columnIdx, int rowIdx)
{
}// end of getMatrixBlockInColumnMajorForm

bool MatrixType::extractBlock(int firstrow, int firstcol, int nrows, int ncols, bool rowMajor,
                      ENUM_MATRIX_SYMMETRY symmetry)
{
    bool mustCopy = false;
    int n = inumberOfChildren;
    for (int i=0; i < n; i++)
        if (m_mChildren[i]->nType != ENUM_MATRIX_CONSTRUCTOR_TYPE_blocks)
        {
            mustCopy = true;
            break;
        }
        else
        {
//            for (int j=0; j < 
        }

return NULL;
}// end of MatrixType::extractBlock

bool MatrixType::alignsOnBlockBoundary(int firstRow, int firstColumn, int nRows, int nCols)
{
    return false;
}// end of MatrixType::alignsOnBlockBoundary()



// end of methods for MatrixType


// methods for OSMatrix ------------------------------------------------
OSMatrix::OSMatrix():
    MatrixType(),
    idx(-1),
    name(""),
    m_miRowPartition(NULL),
    m_iRowPartitionSize(0),
    m_miColumnPartition(NULL),
    m_iColumnPartitionSize(0),
    m_bBlockPartitionProcessed(false) 

{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, "Inside the OSMatrix Constructor");
#endif
    nType = ENUM_MATRIX_CONSTRUCTOR_TYPE_matrix;
}// end of OSMatrix

OSMatrix::~OSMatrix()
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, "Inside the OSMatrix Destructor");
#endif
}// end of ~OSMatrix

std::string OSMatrix::getNodeName()
{
    return "matrix";
}// end of OSMatrix::getNodeName()

ENUM_MATRIX_TYPE OSMatrix::getMatrixType()
{
    if (matrixType == ENUM_MATRIX_TYPE_unknown)
    {
        matrixType == ENUM_MATRIX_TYPE_zero;
        for (int i=0; i<inumberOfChildren; i++)
            matrixType = mergeMatrixType(matrixType, m_mChildren[i]->getMatrixType());
    }
    return matrixType;
}// end of OSMatrix::getMatrixType()


bool OSMatrix::setMatrix(std::string name, int numberOfRows, int numberOfColumns, 
                         ENUM_MATRIX_SYMMETRY symmetry, ENUM_MATRIX_TYPE matrixType, 
                         unsigned int inumberOfChildren, MatrixNode **m_mChildren)
{
    this->name              = name;
    this->numberOfRows      = numberOfRows;
    this->numberOfColumns   = numberOfColumns;
    this->symmetry          = symmetry;
    this->matrixType        = matrixType;
    this->inumberOfChildren = inumberOfChildren;
    this->m_mChildren       = m_mChildren;
    return true;
}//setMatrix


ENUM_MATRIX_CONSTRUCTOR_TYPE OSMatrix::getNodeType()
{
    return ENUM_MATRIX_CONSTRUCTOR_TYPE_matrix;
}// end of OSMatrix::getNodeType()

OSMatrix* OSMatrix::cloneMatrixNode()
{
    MatrixType *nodePtr;
    nodePtr = new OSMatrix();
    return  (OSMatrix*)nodePtr;
}// end of OSMatrix::cloneMatrixNode

OSMatrix* OSMatrix::createConstructorTreeFromPrefix(std::vector<MatrixNode*> mtxConstructorVec)
{
    std::vector<MatrixNode*> stackVec;
    int kount =  mtxConstructorVec.size() - 1;
    while(kount >= 0)
    {
        int numkids = mtxConstructorVec[kount]->inumberOfChildren;
        if(numkids > 0)
        {
            for(int i = 0; i < numkids;  i++)
            {
                mtxConstructorVec[kount]->m_mChildren[i] = stackVec.back();
#if 0
                switch ( stackVec.back()->nType )
                {
                    case ENUM_MATRIX_CONSTRUCTOR_TYPE_baseMatrix:
                        mtxConstructorVec[kount]->m_mChildren[i] = (BaseMatrix*)stackVec.back();
                        break;
                    case ENUM_MATRIX_CONSTRUCTOR_TYPE_elements:
                        mtxConstructorVec[kount]->m_mChildren[i] = (MatrixElements*)stackVec.back();
                        break;
                    case ENUM_MATRIX_CONSTRUCTOR_TYPE_transformation:
                        mtxConstructorVec[kount]->m_mChildren[i] = (MatrixTransformation*)stackVec.back();
                        break;
                    case ENUM_MATRIX_CONSTRUCTOR_TYPE_blocks:
                        mtxConstructorVec[kount]->m_mChildren[i] = (MatrixBlocks*)stackVec.back();
                        break;
                    case ENUM_MATRIX_CONSTRUCTOR_TYPE_block:
                        mtxConstructorVec[kount]->m_mChildren[i] = (MatrixBlock*)stackVec.back();
                        break;
                    case ENUM_MATRIX_CONSTRUCTOR_TYPE_matrix:
                        mtxConstructorVec[kount]->m_mChildren[i] = (OSMatrix*)stackVec.back();
                        break;
                    default:
                        mtxConstructorVec[kount]->m_mChildren[i] = (MatrixNode*)stackVec.back();
                        break;
                }
#endif
                stackVec.pop_back();
            }
        }
        stackVec.push_back( mtxConstructorVec[kount]);
        kount--;
    }
    stackVec.clear();
    return (OSMatrix*)mtxConstructorVec[ 0];
}//end OSMatrix::createExpressionTreeFromPrefix

std::string OSMatrix::getMatrixNodeInXML()
{
    ostringstream outStr;
    outStr << "<matrix";
    outStr << " numberOfRows=\""    << numberOfRows    << "\"";
    outStr << " numberOfColumns=\"" << numberOfColumns << "\"";
    if (symmetry != ENUM_MATRIX_SYMMETRY_none)
        outStr << " symmetry=\"" << returnMatrixSymmetryString(symmetry) << "\"";
    if (name != "") 
        outStr << " name=\"" << name << "\"";
    if (matrixType != ENUM_MATRIX_TYPE_unknown) 
        outStr << " type=\"" << returnMatrixTypeString(matrixType) << "\"";
    outStr << ">" << std::endl;

    for (int i=0; i < inumberOfChildren; i++)
        outStr << m_mChildren[i]->getMatrixNodeInXML();

    outStr << "</matrix>" << std::endl;
    return outStr.str();
}// end of OSMatrix::getMatrixNodeInXML()

bool OSMatrix::IsEqual(OSMatrix *that)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_debug, "Start comparing in OSMatrix");
#endif
    if (this == NULL)
    {
        if (that == NULL)
            return true;
        else
        {
#ifndef NDEBUG
            osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_debug, 
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
            osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_debug, 
                "Second object is NULL, first is not");
#endif
            return false;
        }
        else
        {
            if (this->idx  != this->idx)  return false; 
            if (this->name != this->name) return false; 
            if (!this->MatrixNode::IsEqual(that)) return false;

            return true;
        }
    }
}// end of OSMatrix::IsEqual()
// end of methods for OSMatrix


// methods for MatrixBlock --------------------------------------
MatrixBlock::MatrixBlock():
    blockRowIdx(-1),
    blockColIdx(-1)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, "Inside the MatrixBlock Constructor");
#endif
    nType = ENUM_MATRIX_CONSTRUCTOR_TYPE_block;
}// end of MatrixBlock

MatrixBlock::~MatrixBlock()
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, "Inside the MatrixBlock Destructor");
#endif
}// end of ~MatrixBlock

std::string MatrixBlock::getNodeName()
{
    return "block";
}// end of MatrixBlock::getNodeName()

ENUM_MATRIX_TYPE MatrixBlock::getMatrixType()
{
    if (matrixType == ENUM_MATRIX_TYPE_unknown)
    {
        ENUM_MATRIX_TYPE temp;
        matrixType == ENUM_MATRIX_TYPE_zero;
        for (int i=0; i<inumberOfChildren; i++)
        {
            temp = m_mChildren[i]->getMatrixType();
            matrixType = mergeMatrixType(matrixType, temp);
//            matrixType = mergeMatrixType(matrixType, m_mChildren[i]->getMatrixType());
        }
    }
    return matrixType;
}// end of MatrixBlock::getMatrixType()

bool MatrixBlock::alignsOnBlockBoundary(int firstRow, int firstColumn, int nRows, int nCols)
{
    return (firstRow == 0 && firstColumn == 0 && nRows == numberOfRows && nCols == numberOfColumns);
}// end of MatrixBlock::alignsOnBlockBoundary()


ENUM_MATRIX_CONSTRUCTOR_TYPE MatrixBlock::getNodeType()
{
    return ENUM_MATRIX_CONSTRUCTOR_TYPE_block;
}// end of MatrixBlock::getNodeType()

MatrixBlock* MatrixBlock::cloneMatrixNode()
{
    MatrixType *nodePtr;
    nodePtr = new MatrixBlock();
    return  (MatrixBlock*)nodePtr;
}// end of MatrixBlock::cloneMatrixNode

std::string MatrixBlock::getMatrixNodeInXML()
{
    ostringstream outStr;
    outStr << "<block";
    outStr << " blockRowIdx=\"" << blockRowIdx << "\"";
    outStr << " blockColIdx=\"" << blockColIdx << "\"";
    if (symmetry != ENUM_MATRIX_SYMMETRY_none)
        outStr << " symmetry=\"" << returnMatrixSymmetryString(symmetry) << "\"";
    if (matrixType != ENUM_MATRIX_TYPE_unknown) 
        outStr << " type=\"" << returnMatrixTypeString(matrixType) << "\"";
    outStr << ">" << std::endl;

    for (int i=0; i < inumberOfChildren; i++)
        outStr << m_mChildren[i]->getMatrixNodeInXML();

    outStr << "</block>" << std::endl;
    return outStr.str();
}// end of MatrixBlock::getMatrixNodeInXML()

bool MatrixBlock::IsEqual(MatrixBlock *that)
{
    return true;
}// end of MatrixBlock::IsEqual()
// end of methods for MatrixBlock ----------------------------------------------
