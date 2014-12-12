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
    m_mChildren(NULL)
{
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
}// end of MatrixNode::getNodeType()

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
// end of methods for MatrixNode


// methods for BaseMatrix ----------------------------------------
BaseMatrix::BaseMatrix():
    baseMatrixIdx(-1),
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

ENUM_MATRIX_CONSTRUCTOR_TYPE BaseMatrix::getNodeType()
{
    return ENUM_MATRIX_CONSTRUCTOR_TYPE_baseMatrix;
}// end of BaseMatrix::getNodeType()

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


ConstantMatrixElements::ConstantMatrixElements():
    rowMajor(false),
    numberOfValues(-1),
    start(NULL),
    indexes(NULL),
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
    if (start != NULL)
        delete start;
    start = NULL;
    if (indexes != NULL)
        delete indexes;
    indexes = NULL;
    if (values != NULL)
        delete values;
    values = NULL;
}// end of ConstantMatrixElements::~ConstantMatrixElements()


VarReferenceMatrixElements::VarReferenceMatrixElements():
    rowMajor(false),
    numberOfValues(-1),
    start(NULL),
    indexes(NULL),
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
    if (start != NULL)
        delete start;
    start = NULL;
    if (indexes != NULL)
        delete indexes;
    indexes = NULL;
    if (values != NULL)
        delete values;
    values = NULL;
}// end of VarReferenceMatrixElements::~VarReferenceMatrixElements()


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


LinearMatrixElements::LinearMatrixElements():
    rowMajor(false),
    numberOfValues(-1),
    start(NULL),
    indexes(NULL),
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
    if(start != NULL)
        delete start;
    start = NULL;
    if (indexes != NULL)
        delete indexes;
    indexes = NULL;
    if (values != NULL)
        delete values;
    values = NULL;
}// end of LinearMatrixElements::~LinearMatrixElements()


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

GeneralMatrixElements::GeneralMatrixElements():
    rowMajor(false),
    numberOfValues(-1),
    start(NULL),
    indexes(NULL),
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
    if (start != NULL)
        delete start;
    start = NULL;
    if (indexes != NULL)
        delete indexes;
    indexes = NULL;
    if (values != NULL)
        delete values;
    values = NULL;
}// end of GeneralMatrixElements::~GeneralMatrixElements()

ObjReferenceMatrixElements::ObjReferenceMatrixElements():
    rowMajor(false),
    numberOfValues(-1),
    start(NULL),
    indexes(NULL),
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
    if (start != NULL)
        delete start;
    start = NULL;
    if (indexes != NULL)
        delete indexes;
    indexes = NULL;
    if (values != NULL)
        delete values;
    values = NULL;
}// end of ObjReferenceMatrixElements::~ObjReferenceMatrixElements()

ConReferenceMatrixElements::ConReferenceMatrixElements():
    rowMajor(false),
    numberOfValues(-1),
    start(NULL),
    indexes(NULL),
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
    if (start != NULL)
        delete start;
    start = NULL;
    if (indexes != NULL)
        delete indexes;
    indexes = NULL;
    if (values != NULL)
        delete values;
    values = NULL;
}// end of ConReferenceMatrixElements::~ConReferenceMatrixElements()


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

std::string MatrixElements::getNodeName()
{
    return "elements";
}// end of MatrixElements::getNodeName()

ENUM_MATRIX_CONSTRUCTOR_TYPE MatrixElements::getNodeType()
{
    return ENUM_MATRIX_CONSTRUCTOR_TYPE_elements;
}// end of MatrixElements::getNodeType()

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

std::string MatrixTransformation::getNodeName()
{
    return "transformation";
}// end of MatrixTransformation::getNodeName()

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

std::string MatrixBlocks::getNodeName()
{
    return "blocks";
}// end of MatrixBlocks::getNodeName()

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
// end of methods for MatrixType


// methods for OSMatrix ------------------------------------------------
OSMatrix::OSMatrix():
    MatrixType(),
    idx(-1),
    name("")
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
