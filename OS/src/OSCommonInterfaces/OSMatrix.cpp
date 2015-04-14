/* $Id: OSMatrix.cpp 3186 2010-02-06 23:38:35Z Gassmann $ */
/** @file OSMatrix.cpp
 * \brief This file defines the OSMatrix class along with its supporting classes.
 *
 * @author Horand Gassmann, Jun Ma, Kipp Martin
 *
 * \remarks
 * Copyright (C) 2005-2015, Horand Gassmann, Jun Ma, Kipp Martin,
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

/** ---------- Methods for class MatrixNode ---------- */ 
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
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSMatrix, ENUM_OUTPUT_LEVEL_trace, outStr.str());
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
        osoutput->OSPrint(ENUM_OUTPUT_AREA_OSMatrix, ENUM_OUTPUT_LEVEL_warning, "Warning: Possible memory leak");
}

ENUM_MATRIX_CONSTRUCTOR_TYPE MatrixNode::getNodeType()
{
    return nType;
}// end of OSMatrix::getNodeType()

std::string MatrixNode::getMatrixNodeInXML()
{
    return "";
}// end of MatrixNode::getMatrixNodeInXML()

bool MatrixNode::alignsOnBlockBoundary(int firstRow, int firstColumn, int nRows, int nCols)
{
    return false;
}// end of MatrixNode::alignsOnBlockBoundary()

bool MatrixNode::IsEqual(MatrixNode *that)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSMatrix, ENUM_OUTPUT_LEVEL_trace, "Start comparing in MatrixNode");
#endif
    if (this == NULL)
    {
        if (that == NULL)
            return true;
        else
        {
#ifndef NDEBUG
            osoutput->OSPrint(ENUM_OUTPUT_AREA_OSMatrix, ENUM_OUTPUT_LEVEL_trace, 
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
            osoutput->OSPrint(ENUM_OUTPUT_AREA_OSMatrix, ENUM_OUTPUT_LEVEL_trace, 
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
// end of methods for MatrixNode


/** ---------- Methods for class MatrixConstructor ---------- */ 
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


/** ---------- Methods for class MatrixType ---------- */ 
// methods for MatrixType
MatrixType::MatrixType():
    MatrixNode(),
    symmetry(ENUM_MATRIX_SYMMETRY_none),
    type(ENUM_MATRIX_TYPE_unknown),
    numberOfRows(0),
    numberOfColumns(0),
    ExpandedMatrixInRowMajorForm(NULL),
    ExpandedMatrixInColumnMajorForm(NULL),
    ExpandedMatrixByBlocks(NULL),
    m_miRowPartition(NULL),
    m_iRowPartitionSize(0),
    m_miColumnPartition(NULL),
    m_iColumnPartitionSize(0),
    m_bHaveRowPartition(false),
    m_bHaveColumnPartition(false)
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

bool MatrixType::alignsOnBlockBoundary(int firstRow, int firstColumn, int nRows, int nCols)
{
    return false;
}// end of MatrixType::alignsOnBlockBoundary()

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
        if (m_mChildren[i]->nType == ENUM_MATRIX_CONSTRUCTOR_TYPE_constantElements) return true;
        if (m_mChildren[i]->nType == ENUM_MATRIX_CONSTRUCTOR_TYPE_varRefElements  ) return true;
        if (m_mChildren[i]->nType == ENUM_MATRIX_CONSTRUCTOR_TYPE_linearElements  ) return true;
        if (m_mChildren[i]->nType == ENUM_MATRIX_CONSTRUCTOR_TYPE_generalElements ) return true;
        if (m_mChildren[i]->nType == ENUM_MATRIX_CONSTRUCTOR_TYPE_objRefElements  ) return true;
        if (m_mChildren[i]->nType == ENUM_MATRIX_CONSTRUCTOR_TYPE_conRefElements  ) return true;
    }
    return false;
}// end of matrixHasElements

bool MatrixType::matrixHasTransformations()
{
    if (inumberOfChildren == 0 || m_mChildren == NULL) return false;
    for (int i=0; i < inumberOfChildren; i++)
    {
        if (m_mChildren[i]->nType == ENUM_MATRIX_CONSTRUCTOR_TYPE_transformation) return true;
    }
    return false;
}// end of matrixHasTransformations

bool MatrixType::matrixHasBlocks()
{
    if (inumberOfChildren == 0 || m_mChildren == NULL) return false;
    for (int i=0; i < inumberOfChildren; i++)
    {
        if (m_mChildren[i]->nType == ENUM_MATRIX_CONSTRUCTOR_TYPE_blocks) return true;
    }
    return false;
}// end of matrixHasBlocks

int  MatrixType::getNumberOfElementConstructors()
{
    int k = 0;
    if (inumberOfChildren == 0 || m_mChildren == NULL) return 0;
    for (int i=0; i < inumberOfChildren; i++)
    {
        if (m_mChildren[i]->nType == ENUM_MATRIX_CONSTRUCTOR_TYPE_constantElements) k++;
        if (m_mChildren[i]->nType == ENUM_MATRIX_CONSTRUCTOR_TYPE_varRefElements)   k++;
        if (m_mChildren[i]->nType == ENUM_MATRIX_CONSTRUCTOR_TYPE_linearElements)   k++;
        if (m_mChildren[i]->nType == ENUM_MATRIX_CONSTRUCTOR_TYPE_generalElements)  k++;
        if (m_mChildren[i]->nType == ENUM_MATRIX_CONSTRUCTOR_TYPE_objRefElements)   k++;
        if (m_mChildren[i]->nType == ENUM_MATRIX_CONSTRUCTOR_TYPE_conRefElements)   k++;
    }
    return k++;
}// end of getNumberOfElementConstructors

int  MatrixType::getNumberOfTransformationConstructors()
{
    int k = 0;
    if (inumberOfChildren == 0 || m_mChildren == NULL) return 0;
    for (int i=0; i < inumberOfChildren; i++)
    {
        if (m_mChildren[i]->nType == ENUM_MATRIX_CONSTRUCTOR_TYPE_transformation) k++;
    }
    return k++;
}// end of getNumberOfTransformationConstructors

int  MatrixType::getNumberOfBlocksConstructors()
{
    int k = 0;
    if (inumberOfChildren == 0 || m_mChildren == NULL) return 0;
    for (int i=0; i < inumberOfChildren; i++)
    {
        if (m_mChildren[i]->nType == ENUM_MATRIX_CONSTRUCTOR_TYPE_blocks) k++;
    }
    return k++;
}// end of getNumberOfBlocksConstructors

GeneralSparseMatrix* MatrixType::getMatrixCoefficientsInColumnMajor()
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, "Inside getMatrixCoefficientsInColumnMajor()");
#endif
    try
    {
        //Check if previous expansion available
        if (ExpandedMatrixInColumnMajorForm != NULL)
            return ExpandedMatrixInColumnMajorForm;
        if (ExpandedMatrixInRowMajorForm != NULL)
        {
            ExpandedMatrixInColumnMajorForm = convertToOtherMajor(false);
            return ExpandedMatrixInColumnMajorForm;
        }

        // The complexity increases with the number of constructors
        // Start by checking for empty matrix
        if (inumberOfChildren == 0)
        {
            ExpandedMatrixInColumnMajorForm = new GeneralSparseMatrix();
            ExpandedMatrixInColumnMajorForm->symmetry = symmetry;
            ExpandedMatrixInColumnMajorForm->valueSize = 0;
            ExpandedMatrixInColumnMajorForm->startSize = numberOfColumns + 1;
            ExpandedMatrixInColumnMajorForm->starts = new int[numberOfColumns + 1];
            for (int i=0; i <= numberOfColumns; i++)
                ExpandedMatrixInColumnMajorForm->starts[i] = 0;
            return ExpandedMatrixInColumnMajorForm;
        }

        // single constructor --- process by type 
        else if (inumberOfChildren == 1)
        {
            if (m_mChildren[0]->getNodeType() == ENUM_MATRIX_CONSTRUCTOR_TYPE_baseMatrix)
            {
                int  baseMtxIdx = ((BaseMatrix*)m_mChildren[0])->baseMatrixIdx;
                OSMatrix* baseMtxPtr = ((BaseMatrix*)m_mChildren[0])->baseMatrix;

                int iroff = ((BaseMatrix*)m_mChildren[0])->targetMatrixFirstRow;
                int icoff = ((BaseMatrix*)m_mChildren[0])->targetMatrixFirstCol;

                int base_r0, base_c0, base_rN, base_cN;

                GeneralSparseMatrix* baseMtx;
                if (((BaseMatrix*)m_mChildren[0])->baseTranspose)
                {
                    baseMtx = baseMtxPtr->getMatrixCoefficientsInRowMajor();
//                    iroff   = ((BaseMatrix*)m_mChildren[0])->targetMatrixFirstCol;
//                    icoff   = ((BaseMatrix*)m_mChildren[0])->targetMatrixFirstRow;
                    base_r0 = ((BaseMatrix*)m_mChildren[0])->baseMatrixStartCol;
                    base_c0 = ((BaseMatrix*)m_mChildren[0])->baseMatrixStartRow;
                    base_rN = ((BaseMatrix*)m_mChildren[0])->baseMatrixEndCol;
                    base_cN = ((BaseMatrix*)m_mChildren[0])->baseMatrixEndRow;
                    if (base_cN < 0)
                        base_cN = baseMtxPtr->numberOfRows - 1;
                    if (base_rN < 0)
                        base_rN = baseMtxPtr->numberOfColumns - 1;
                }
                else
                {
                    baseMtx = baseMtxPtr->getMatrixCoefficientsInColumnMajor();
//                    iroff   = ((BaseMatrix*)m_mChildren[0])->targetMatrixFirstRow;
//                    icoff   = ((BaseMatrix*)m_mChildren[0])->targetMatrixFirstCol;
                    base_r0 = ((BaseMatrix*)m_mChildren[0])->baseMatrixStartRow;
                    base_c0 = ((BaseMatrix*)m_mChildren[0])->baseMatrixStartCol;
                    base_rN = ((BaseMatrix*)m_mChildren[0])->baseMatrixEndRow;
                    base_cN = ((BaseMatrix*)m_mChildren[0])->baseMatrixEndCol;
                    if (base_rN < 0)
                        base_rN = baseMtxPtr->numberOfRows - 1;
                    if (base_cN < 0)
                        base_cN = baseMtxPtr->numberOfColumns - 1;
                }
//                base_c0 = ((BaseMatrix*)m_mChildren[0])->baseMatrixStartCol;
//                base_r0 = ((BaseMatrix*)m_mChildren[0])->baseMatrixStartRow;
//                base_cN = ((BaseMatrix*)m_mChildren[0])->baseMatrixEndCol;
//                base_rN = ((BaseMatrix*)m_mChildren[0])->baseMatrixEndRow;
//                if (base_rN < 0)
//                    base_rN = baseMtxPtr->numberOfRows - 1;
//                if (base_cN < 0)
//                    base_cN = baseMtxPtr->numberOfColumns - 1;

                double scaleMult = ((BaseMatrix*)m_mChildren[0])->scalarMultiplier;

                ExpandedMatrixInColumnMajorForm = new GeneralSparseMatrix();
                ExpandedMatrixInColumnMajorForm->symmetry  = symmetry;
                ExpandedMatrixInColumnMajorForm->startSize = numberOfColumns + 1;

                // position and other options can affect what arrays need to be duplicated
                bool isShifted = (iroff > 0 || icoff > 0);
                bool isCropped = (base_c0 > 0 || base_r0 > 0 || 
                                  base_rN < baseMtxPtr->numberOfRows - 1 ||
                                  base_cN < baseMtxPtr->numberOfColumns - 1);
                bool isClipped = (iroff + base_rN - base_r0 >= numberOfRows ||
                                  icoff + base_cN - base_c0 >= numberOfColumns);
                bool isScaled  = (scaleMult != 1);
                bool reTyped   = (getMatrixType() != baseMtx->vType);
                bool hasGap    = (icoff + base_cN - base_c0 < numberOfColumns - 1);

                //default position without cropping, scaling or retyping is easiest
                if ( !isShifted && !isCropped && !isClipped && !isScaled && !reTyped )
                {
                    ExpandedMatrixInColumnMajorForm->b_deleteStartArray = hasGap;
                    ExpandedMatrixInColumnMajorForm->b_deleteIndexArray = false;
                    ExpandedMatrixInColumnMajorForm->b_deleteValueArray = false;
                    ExpandedMatrixInColumnMajorForm->isRowMajor = false;
                    ExpandedMatrixInColumnMajorForm->valueSize = baseMtx->valueSize;
                    ExpandedMatrixInColumnMajorForm->vType     = baseMtx->vType;
                    ExpandedMatrixInColumnMajorForm->indexes   = baseMtx->indexes;
                    ExpandedMatrixInColumnMajorForm->values    = baseMtx->values;

                    // even in default layout the baseMatrix may still have different dimensions...
                    if (!hasGap)
                        ExpandedMatrixInColumnMajorForm->starts = baseMtx->starts;
                    else
                    {
                        ExpandedMatrixInColumnMajorForm->startSize = numberOfColumns + 1;
                        ExpandedMatrixInColumnMajorForm->starts =
                            new int[ExpandedMatrixInColumnMajorForm->startSize];
                        for (int i=0; i < baseMtx->startSize; i++)
                            ExpandedMatrixInColumnMajorForm->starts[i] = baseMtx->starts[i];
                        int lastStart = baseMtx->valueSize;
                        for (int i=baseMtx->startSize; 
                                 i < ExpandedMatrixInColumnMajorForm->startSize; i++)
                            ExpandedMatrixInColumnMajorForm->starts[i] = lastStart;
                    }

                    return ExpandedMatrixInColumnMajorForm; 
                }
                else
                {
                    // cropping, positioning or scaling all require a deep copy
                    if ( !isShifted && !isCropped && !isClipped )
                    {
                        // it's a bit easier if we are just scaling
                        ExpandedMatrixInColumnMajorForm->b_deleteStartArray = hasGap;
                        ExpandedMatrixInColumnMajorForm->b_deleteIndexArray = false;
                        ExpandedMatrixInColumnMajorForm->b_deleteValueArray = true;
                        ExpandedMatrixInColumnMajorForm->isRowMajor = false;
                        ExpandedMatrixInColumnMajorForm->valueSize  = baseMtx->valueSize;
                        ExpandedMatrixInColumnMajorForm->vType      = baseMtx->vType;
                        ExpandedMatrixInColumnMajorForm->indexes    = baseMtx->indexes;

                        // even in default layout the baseMatrix may still have different dimensions...
                        if (!hasGap)
                            ExpandedMatrixInColumnMajorForm->starts = baseMtx->starts;
                        else
                        {
                            ExpandedMatrixInColumnMajorForm->startSize = numberOfColumns + 1;
                            ExpandedMatrixInColumnMajorForm->starts =
                                new int[ExpandedMatrixInColumnMajorForm->startSize];
                            for (int i=0; i < baseMtx->startSize; i++)
                                ExpandedMatrixInColumnMajorForm->starts[i] = baseMtx->starts[i];
                            int lastStart = baseMtx->valueSize;
                            for (int i=baseMtx->startSize; 
                                     i < ExpandedMatrixInColumnMajorForm->startSize; i++)
                                ExpandedMatrixInColumnMajorForm->starts[i] = lastStart;
                        }

                        // the values are a bit more difficult ...
                        if ( baseMtx->vType == ENUM_MATRIX_TYPE_constant)
                        {
                            ExpandedMatrixInColumnMajorForm->values = new ConstantMatrixValues();
                            ((ConstantMatrixValues*)ExpandedMatrixInColumnMajorForm->values)->el
                                = new double[baseMtx->valueSize];
                            for (int i = 0; i < baseMtx->valueSize; i++)
                                ((ConstantMatrixValues*)ExpandedMatrixInColumnMajorForm->values)->el[i]
                                    = scaleMult*((ConstantMatrixValues*)baseMtx->values)->el[i];
                        }
                        else if (baseMtx->vType == ENUM_MATRIX_TYPE_varref)
                        {
                            // must convert to linear elements
                            LinearMatrixValues* tmpValues = new LinearMatrixValues();
                            tmpValues->el = new LinearMatrixElement*[baseMtx->valueSize];
                            for (int i = 0; i < baseMtx->valueSize; i++)
                            {
                                tmpValues->el[i] = new LinearMatrixElement();
                                tmpValues->el[i]->numberOfVarIdx = 1; 
                                tmpValues->el[i]->varIdx    = new LinearMatrixElementTerm*[1];
                                tmpValues->el[i]->varIdx[0] = new LinearMatrixElementTerm();
                                tmpValues->el[i]->varIdx[0]->coef = scaleMult;
                                tmpValues->el[i]->varIdx[0]->idx  
                                    = ((VarReferenceMatrixValues*)baseMtx->values)->el[i];
                            }
                            ExpandedMatrixInColumnMajorForm->values = tmpValues;
                        }
                        else if (baseMtx->vType == ENUM_MATRIX_TYPE_linear)
                        {
                            LinearMatrixValues* tmpValues = new LinearMatrixValues();
                            tmpValues->el = new LinearMatrixElement*[baseMtx->valueSize];
                            for (int i = 0; i < baseMtx->valueSize; i++)
                            {
                                tmpValues->el[i] = new LinearMatrixElement();
                                if (!(tmpValues->el[i]
                                        ->deepCopyFrom(((LinearMatrixValues*)baseMtx->values)->el[i])))
                                    throw ErrorClass("failed copying linear element values in method getMatrixCoefficientsInColumnMajor()");
                                for (int j=0; j<tmpValues->el[i]->numberOfVarIdx; j++)
                                    tmpValues->el[i]->varIdx[j]->coef *= scaleMult;
                            }
                            ExpandedMatrixInColumnMajorForm->values = tmpValues;
                        }
                        else if (baseMtx->vType == ENUM_MATRIX_TYPE_general)
                        {
                            // add scalar multiple as a product
                            GeneralMatrixValues* tmpValues = new GeneralMatrixValues();
                            tmpValues->el = new ScalarExpressionTree*[baseMtx->valueSize];
                            for (int i = 0; i < baseMtx->valueSize; i++)
                            {
                                tmpValues->el[i] = new ScalarExpressionTree();
                                tmpValues->el[i]->m_treeRoot = new OSnLNodeTimes();
                                tmpValues->el[i]->m_treeRoot->m_mChildren[0] = new OSnLNodeNumber();
                                ((OSnLNodeNumber*)tmpValues->el[i]->m_treeRoot->m_mChildren[0])->value = scaleMult;
                                tmpValues->el[i]->m_treeRoot->m_mChildren[1]
                                     = ((GeneralMatrixValues*)baseMtx->values)->el[i]->m_treeRoot
                                        ->copyNodeAndDescendants();
                            }
                            ExpandedMatrixInColumnMajorForm->values = tmpValues;
                        }
                        else if (baseMtx->vType == ENUM_MATRIX_TYPE_objref)
                        {
                            throw ErrorClass("scalar multiple not defined for objref elements in  getMatrixCoefficientsInColumnMajor()");
                        }
                        else if (baseMtx->vType == ENUM_MATRIX_TYPE_conref)
                        {
                            throw ErrorClass("scalar multiple not defined for conref elements in  getMatrixCoefficientsInColumnMajor()");
                        }
                        return ExpandedMatrixInColumnMajorForm; 
                    }
                    else // repositioned Basematrix with cropping
                    {
                        ExpandedMatrixInColumnMajorForm->b_deleteStartArray = true;
                        ExpandedMatrixInColumnMajorForm->b_deleteIndexArray = true;
                        ExpandedMatrixInColumnMajorForm->b_deleteValueArray = true;
                        ExpandedMatrixInColumnMajorForm->startSize = numberOfColumns + 1;
                        ExpandedMatrixInColumnMajorForm->isRowMajor = false;
                        ExpandedMatrixInColumnMajorForm->vType      = baseMtx->vType;

                        int  startSize = numberOfColumns + 1; 
                        int* tmpStarts = new int[startSize];
                        for (int i=0; i < startSize; i++)
                            tmpStarts[i] = 0;

                        int adjc = icoff - base_c0;
                        int lastcol = icoff + base_cN - base_c0 + 1;
                        if (lastcol > numberOfColumns)
                            lastcol = numberOfColumns;

                        // count elements in each column and calculate starts
                        for (int i=icoff; i<lastcol; i++)
                            for (int j=baseMtx->starts[i-adjc]; j<baseMtx->starts[i-adjc+1]; j++)
                            {
                                if (baseMtx->indexes[j] >= base_r0 &&
                                    baseMtx->indexes[j] <= base_rN &&
                                    baseMtx->indexes[j] <  numberOfRows + base_r0 - iroff)
                                tmpStarts[i+1]++; 
                            }
                        for (int i=icoff+1; i <= startSize; i++) 
                            tmpStarts[i] += tmpStarts[i-1];
 
                        int valueSize = tmpStarts[startSize-1];
                        int* tmpIndexes = new int[valueSize];

                        ExpandedMatrixInColumnMajorForm->valueSize  = valueSize;
                        ExpandedMatrixInColumnMajorForm->starts     = tmpStarts;

                        // to get the values, go through the base matrix a second time
                        if ( baseMtx->vType == ENUM_MATRIX_TYPE_constant)
                        {
                            MatrixElementValues* tmpValues = new ConstantMatrixValues();
                            ((ConstantMatrixValues*)tmpValues)->el = new double[valueSize];

                            int ival = 0;
                            for (int i=icoff; i<lastcol; i++)
                                for (int j=baseMtx->starts[i-adjc]; j<baseMtx->starts[i-adjc+1]; j++)
                                {
                                    if (baseMtx->indexes[j] >= base_r0 &&
                                        baseMtx->indexes[j] <= base_rN &&
                                        baseMtx->indexes[j] <  numberOfRows + base_r0 - iroff)
                                    {
                                        tmpIndexes[ival] = baseMtx->indexes[j] - base_r0 + iroff; 
                                        ((ConstantMatrixValues*)tmpValues)->el[ival]
                                            = scaleMult*((ConstantMatrixValues*)baseMtx->values)->el[j];
                                        ival++;
                                    }    
                                }
                            ExpandedMatrixInColumnMajorForm->indexes = tmpIndexes;
                            ExpandedMatrixInColumnMajorForm->values  = tmpValues;
                        }

                        else if (baseMtx->vType == ENUM_MATRIX_TYPE_varref)
                        {
                            if (scaleMult == 1)
                            {
                                MatrixElementValues* tmpValues = new VarReferenceMatrixValues();
                                ((VarReferenceMatrixValues*)tmpValues)->el = new int[valueSize];

                                int ival = 0;
                                for (int i=icoff; i<lastcol; i++)
                                    for (int j=baseMtx->starts[i-adjc]; j<baseMtx->starts[i-adjc+1]; j++)
                                    {
                                        if (baseMtx->indexes[j] >= base_r0 &&
                                            baseMtx->indexes[j] <  numberOfRows + base_r0 - iroff)
                                        {
                                            tmpIndexes[ival] = baseMtx->indexes[j] - base_r0 + iroff; 
                                            ((VarReferenceMatrixValues*)tmpValues)->el[ival]
                                                = ((VarReferenceMatrixValues*)baseMtx->values)->el[j];
                                            ival++;
                                        }    
                                    }
                                ExpandedMatrixInColumnMajorForm->indexes = tmpIndexes;
                                ExpandedMatrixInColumnMajorForm->values  = tmpValues;
                            }
                            else
                            {
                                // must convert to linear elements
                                MatrixElementValues* tmpValues = new LinearMatrixValues();
                                ((LinearMatrixValues*)tmpValues)->el 
                                    = new LinearMatrixElement*[valueSize];

                                int ival = 0;
                                for (int i=icoff; i<lastcol; i++)
                                    for (int j=baseMtx->starts[i-adjc]; j<baseMtx->starts[i-adjc+1]; j++)
                                    {
                                        if (baseMtx->indexes[j] >= base_r0 &&
                                            baseMtx->indexes[j] <  numberOfRows + base_r0 - iroff)
                                        {
                                            ((LinearMatrixValues*)tmpValues)->el[ival] 
                                                = new LinearMatrixElement();
                                            ((LinearMatrixValues*)tmpValues)->el[ival]->numberOfVarIdx = 1; 
                                            ((LinearMatrixValues*)tmpValues)->el[ival]->varIdx 
                                                = new LinearMatrixElementTerm*[1];
                                            ((LinearMatrixValues*)tmpValues)->el[ival]->varIdx[0] 
                                                = new LinearMatrixElementTerm();
                                            ((LinearMatrixValues*)tmpValues)->el[ival]->varIdx[0]->coef 
                                                = scaleMult;
                                            ((LinearMatrixValues*)tmpValues)->el[ival]->varIdx[0]->idx  
                                                = ((VarReferenceMatrixValues*)baseMtx->values)->el[j];
                                            ival++;
                                        }
                                    }
                                ExpandedMatrixInColumnMajorForm->indexes = tmpIndexes;
                                ExpandedMatrixInColumnMajorForm->values  = tmpValues;
                            }
                        }
                        else if (baseMtx->vType == ENUM_MATRIX_TYPE_linear)
                        {
                            LinearMatrixValues* tmpValues = new LinearMatrixValues();
                            tmpValues->el = new LinearMatrixElement*[baseMtx->valueSize];

                            int ival = 0;
                            for (int i=icoff; i<lastcol; i++)
                                for (int j=baseMtx->starts[i-adjc]; j<baseMtx->starts[i-adjc+1]; j++)
                                {
                                    if (baseMtx->indexes[j] >= base_r0 &&
                                        baseMtx->indexes[j] <  numberOfRows + base_r0 - iroff)
                                    {
                                        tmpValues->el[ival] = new LinearMatrixElement();
                                        if (!(tmpValues->el[ival]
                                                ->deepCopyFrom(((LinearMatrixValues*)baseMtx->values)->el[j])))
                                        throw ErrorClass("failed copying linear element values in method getMatrixCoefficientsInColumnMajor()");
                                    for (int k=0; k<tmpValues->el[ival]->numberOfVarIdx; k++)
                                        tmpValues->el[ival]->varIdx[k]->coef *= scaleMult;
                                    ival++;
                                    }
                                }
                            ExpandedMatrixInColumnMajorForm->indexes = tmpIndexes;
                            ExpandedMatrixInColumnMajorForm->values  = tmpValues;
                        }
                        else if (baseMtx->vType == ENUM_MATRIX_TYPE_general)
                        {
                            if (scaleMult == 1)
                            {
                                GeneralMatrixValues* tmpValues = new GeneralMatrixValues();
                                tmpValues->el = new ScalarExpressionTree*[baseMtx->valueSize];

                                int ival = 0;
                                for (int i=icoff; i<lastcol; i++)
                                    for (int j=baseMtx->starts[i-adjc]; j<baseMtx->starts[i-adjc+1]; j++)
                                    {
                                        if (baseMtx->indexes[j] >= base_r0 &&
                                            baseMtx->indexes[j] <  numberOfRows + base_r0 - iroff)
                                        {
                                            ((GeneralMatrixValues*)tmpValues)->el[ival] 
                                                = new ScalarExpressionTree();
//                                            ((GeneralMatrixValues*)tmpValues)->el[ival]->m_treeRoot 
//                                                = new OSnLNode();
                                            ((GeneralMatrixValues*)tmpValues)->el[ival]->m_treeRoot 
                                                = ((GeneralMatrixValues*)baseMtx->values)->el[j]->m_treeRoot
                                                    ->copyNodeAndDescendants();
                                            ival++;
                                        }
                                    }
                                ExpandedMatrixInColumnMajorForm->indexes = tmpIndexes;
                                ExpandedMatrixInColumnMajorForm->values  = tmpValues;
                            }
                            else
                            {
                                // add scalar multiple as a product
                                GeneralMatrixValues* tmpValues = new GeneralMatrixValues();
                                tmpValues->el = new ScalarExpressionTree*[baseMtx->valueSize];
                                int ival = 0;
                                for (int i=icoff; i<lastcol; i++)
                                    for (int j=baseMtx->starts[i-adjc]; j<baseMtx->starts[i-adjc+1]; j++)
                                    {
                                        if (baseMtx->indexes[j] >= base_r0 &&
                                            baseMtx->indexes[j] <  numberOfRows + base_r0 - iroff)
                                        {
                                            ((GeneralMatrixValues*)tmpValues)->el[ival] 
                                                = new ScalarExpressionTree();
                                            ((GeneralMatrixValues*)tmpValues)->el[ival]->m_treeRoot 
                                                = new OSnLNodeTimes();
                                            ((GeneralMatrixValues*)tmpValues)->el[ival]->m_treeRoot->m_mChildren[0] 
                                                = new OSnLNodeNumber();
                                            ((OSnLNodeNumber*)tmpValues->el[ival]->m_treeRoot->m_mChildren[0])->value = scaleMult;
                                            ((GeneralMatrixValues*)tmpValues)->el[ival]->m_treeRoot->m_mChildren[1]
                                                = ((GeneralMatrixValues*)baseMtx->values)->el[j]->m_treeRoot->copyNodeAndDescendants();
                                            ival++;

                                        }
                                    }
                                ExpandedMatrixInColumnMajorForm->indexes = tmpIndexes;
                                ExpandedMatrixInColumnMajorForm->values  = tmpValues;
                            }
                        }
                        else if (baseMtx->vType == ENUM_MATRIX_TYPE_objref)
                        {
                                    throw ErrorClass("scalar multiple not defined for objref elements in  getMatrixCoefficientsInColumnMajor()");
                        }
                        else if (baseMtx->vType == ENUM_MATRIX_TYPE_conref)
                        {
                                    throw ErrorClass("scalar multiple not defined for conref elements in  getMatrixCoefficientsInColumnMajor()");
                        }
                    }
                    return ExpandedMatrixInColumnMajorForm; 
                }
            }

            else if (m_mChildren[0]->getNodeType() == ENUM_MATRIX_CONSTRUCTOR_TYPE_blocks)
            {
                //make sure the blocks have been expanded, then retrieve them 
                if (!processBlocks(false, symmetry))
                    throw ErrorClass("error processing blocks in getMatrixCoefficientsInColumnMajor()");
                
                ExpandedMatrixBlocks* currentBlocks
                    = getBlocks(m_miRowPartition, m_iRowPartitionSize, m_miColumnPartition,
                                m_iColumnPartitionSize, false, true);
                //ExpandedMatrixByBlocks.push_back(currentBlocks);

                ExpandedMatrixInColumnMajorForm = new GeneralSparseMatrix();
                ExpandedMatrixInColumnMajorForm->b_deleteStartArray = true;
                ExpandedMatrixInColumnMajorForm->b_deleteIndexArray = true;
                ExpandedMatrixInColumnMajorForm->b_deleteValueArray = true;
                ExpandedMatrixInColumnMajorForm->vType = getMatrixType();
                ExpandedMatrixInColumnMajorForm->isRowMajor = false;
                ExpandedMatrixInColumnMajorForm->symmetry = symmetry;
                ExpandedMatrixInColumnMajorForm->startSize = numberOfColumns + 1;
                ExpandedMatrixInColumnMajorForm->starts = new int[numberOfColumns + 1];
                for (int i=0; i <= numberOfColumns; i++)
                    ExpandedMatrixInColumnMajorForm->starts[i] = 0;

                // augment column lengths block by block
                for (int i=0; i < currentBlocks->blockNumber; i++)
                {
                    int c0 = currentBlocks->colOffsets[currentBlocks->blockColumns[i]];
                    int cN = currentBlocks->colOffsets[currentBlocks->blockColumns[i]+1];
                    for (int j = c0; j < cN; j++)
                    {
                        ExpandedMatrixInColumnMajorForm->starts[j+1] += 
                            ( currentBlocks->blocks[i]->starts[j+1-c0] 
                            - currentBlocks->blocks[i]->starts[j  -c0] );
                    } 
                }

                for (int i=1; i <= numberOfColumns; i++)
                    ExpandedMatrixInColumnMajorForm->starts[i] +=
                        ExpandedMatrixInColumnMajorForm->starts[i-1];
                ExpandedMatrixInColumnMajorForm->valueSize = 
                    ExpandedMatrixInColumnMajorForm->starts[numberOfColumns];
                int* tmpIndexes = new int[ExpandedMatrixInColumnMajorForm->valueSize];

                // go through the blocks a second time to store values --- based on type
                if (currentBlocks->blocks[0]->vType == ENUM_MATRIX_TYPE_constant)
                {
                    ConstantMatrixValues* tmpValues = new ConstantMatrixValues();
                    tmpValues->el
                        = new double[ExpandedMatrixInColumnMajorForm->valueSize];

                    for (int i=0; i < currentBlocks->blockNumber; i++)
                    {
                        int c0 = currentBlocks->colOffsets[currentBlocks->blockColumns[i]];
                        int cN = currentBlocks->colOffsets[currentBlocks->blockColumns[i]+1];
                        int row_adj = currentBlocks->rowOffsets[currentBlocks->blockRows[i]];

                        for (int j = c0; j < cN; j++)
                        {
                            int loc = ExpandedMatrixInColumnMajorForm->starts[j];
                            for (int k = currentBlocks->blocks[i]->starts[j-c0];
                                     k < currentBlocks->blocks[i]->starts[j-c0+1]; k++)
                            {
                                tmpIndexes[loc] = currentBlocks->blocks[i]->indexes[k] + row_adj;
                                ((ConstantMatrixValues*)tmpValues)->el[loc] 
                                    = ((ConstantMatrixValues*)currentBlocks->blocks[i]->values)->el[k];
                                loc++;
                            }
                            ExpandedMatrixInColumnMajorForm->starts[j] = loc;
                        }
                    }
                    ExpandedMatrixInColumnMajorForm->indexes = tmpIndexes;
                    ExpandedMatrixInColumnMajorForm->values  = tmpValues;
                }
                else
                    throw ErrorClass("getMatrixCoefficientsInColumnMajor: Can only handle constant values so far in blocks");
                for (int i=numberOfColumns; i > 0; i--)
                    ExpandedMatrixInColumnMajorForm->starts[i] =
                        ExpandedMatrixInColumnMajorForm->starts[i-1];
                ExpandedMatrixInColumnMajorForm->starts[0] = 0;
            }

            else if (m_mChildren[0]->getNodeType() == ENUM_MATRIX_CONSTRUCTOR_TYPE_transformation)
            {
//              transformation: see if we can do at least AB, A'B, AB'
//              for now:
                throw ErrorClass("transformations not yet implemented in getMatrixCoefficientsInColumnMajor()");
            }
            else // some kind of elements --- if given column-wise, just copy pointers
            {
                if (!((MatrixElements*)m_mChildren[0])->rowMajor)
                {
                    ExpandedMatrixInColumnMajorForm = new GeneralSparseMatrix();
                    ExpandedMatrixInColumnMajorForm->symmetry = symmetry;
                    ExpandedMatrixInColumnMajorForm->b_deleteStartArray = false;
                    ExpandedMatrixInColumnMajorForm->b_deleteIndexArray = false;
                    ExpandedMatrixInColumnMajorForm->b_deleteValueArray = false;
                    ExpandedMatrixInColumnMajorForm->isRowMajor = false;
                    ExpandedMatrixInColumnMajorForm->startSize = numberOfColumns + 1;
                    ExpandedMatrixInColumnMajorForm->valueSize
                        = ((MatrixElements*)m_mChildren[0])->numberOfValues;
                    ExpandedMatrixInColumnMajorForm->starts
                        = ((MatrixElements*)m_mChildren[0])->start->el;
                    ExpandedMatrixInColumnMajorForm->vType     
                        = getMatrixType();
                    ExpandedMatrixInColumnMajorForm->indexes   
                        = ((MatrixElements*)m_mChildren[0])->indexes->el;
                    if (ExpandedMatrixInColumnMajorForm->vType == ENUM_MATRIX_TYPE_constant)
                        ExpandedMatrixInColumnMajorForm->values    
                            = ((ConstantMatrixElements*)m_mChildren[0])->values;
                    else if (ExpandedMatrixInColumnMajorForm->vType == ENUM_MATRIX_TYPE_varref)
                        ExpandedMatrixInColumnMajorForm->values    
                            = ((VarReferenceMatrixElements*)m_mChildren[0])->values;
                    else if (ExpandedMatrixInColumnMajorForm->vType == ENUM_MATRIX_TYPE_linear)
                        ExpandedMatrixInColumnMajorForm->values    
                            = ((LinearMatrixElements*)m_mChildren[0])->values;
                    else if (ExpandedMatrixInColumnMajorForm->vType == ENUM_MATRIX_TYPE_general)
                        ExpandedMatrixInColumnMajorForm->values    
                            = ((GeneralMatrixElements*)m_mChildren[0])->values;
                    else if (ExpandedMatrixInColumnMajorForm->vType == ENUM_MATRIX_TYPE_objref)
                        ExpandedMatrixInColumnMajorForm->values    
                            = ((ObjReferenceMatrixElements*)m_mChildren[0])->values;
                    else if (ExpandedMatrixInColumnMajorForm->vType == ENUM_MATRIX_TYPE_conref)
                        ExpandedMatrixInColumnMajorForm->values    
                            = ((ConReferenceMatrixElements*)m_mChildren[0])->values;
                    else
                        throw ErrorClass("Unknown element type in getMatrixCoefficientsInColumnMajor()");

                    return ExpandedMatrixInColumnMajorForm; 
                }
                else // elements are given row-wise and must be "turned" 
                {
                    MatrixElements* refMtx = (MatrixElements*)m_mChildren[0];

                    ExpandedMatrixInColumnMajorForm = new GeneralSparseMatrix();
                    ExpandedMatrixInColumnMajorForm->symmetry = symmetry;
                    ExpandedMatrixInColumnMajorForm->startSize = numberOfColumns + 1;
                    ExpandedMatrixInColumnMajorForm->vType = getMatrixType();
                    ExpandedMatrixInColumnMajorForm->starts = new int[numberOfColumns + 1];
                    for (int i=0; i <= numberOfColumns; i++)
                        ExpandedMatrixInColumnMajorForm->starts[i] = 0;

                    //if <values> is empty, return an empty matrix
                    if (refMtx == NULL || refMtx->numberOfValues == 0)
                    {
                        ExpandedMatrixInColumnMajorForm->valueSize = 0;
                        return ExpandedMatrixInColumnMajorForm;
                    }                        

                    ExpandedMatrixInColumnMajorForm->valueSize = refMtx->numberOfValues;
                    ExpandedMatrixInColumnMajorForm->indexes = new int[refMtx->numberOfValues];

                    int i, j, iTemp;
                    int iNumSource = numberOfRows;

                    for (i = 0; i < numberOfRows; i++)
                    {
                        for (j = refMtx->start->el[i]; j < refMtx->start->el[i + 1]; j++)
                        {
                            ExpandedMatrixInColumnMajorForm->starts[refMtx->indexes->el[j] + 1] ++;
                        }
                    }
                    ExpandedMatrixInColumnMajorForm->starts[0] = 0;

                    for (i = 1; i <= numberOfColumns; i++ )
                    {
                        ExpandedMatrixInColumnMajorForm->starts[i] 
                            += ExpandedMatrixInColumnMajorForm->starts [i - 1] ;
                    }

                    // store the elements, by type
                    if (ExpandedMatrixInColumnMajorForm->vType == ENUM_MATRIX_TYPE_constant)
                    {
                        ExpandedMatrixInColumnMajorForm->values = new ConstantMatrixValues();
                        ((ConstantMatrixValues*)ExpandedMatrixInColumnMajorForm->values)->el
                            = new double[refMtx->numberOfValues];

                        for (i = 0; i < numberOfRows; i++)
                        {
                            // get row indices and values of the matrix
                            for (j = refMtx->start->el[i]; j < refMtx->start->el[ i + 1 ]; j++)
                            {
                                iTemp = ExpandedMatrixInColumnMajorForm->starts[refMtx->indexes->el[j]];
                                ExpandedMatrixInColumnMajorForm->indexes [ iTemp] = i;
                                ((ConstantMatrixValues*)ExpandedMatrixInColumnMajorForm->values)->el[ iTemp] 
                                    = ((ConstantMatrixValues*)((ConstantMatrixElements*)refMtx)->values)->el[j];
                                ExpandedMatrixInColumnMajorForm->starts[refMtx->indexes->el[j]] ++;
                            }
                        }
                    }
                    else if (ExpandedMatrixInColumnMajorForm->vType == ENUM_MATRIX_TYPE_varref)
                    {
                        ExpandedMatrixInColumnMajorForm->values = new VarReferenceMatrixValues();
                        ((VarReferenceMatrixValues*)ExpandedMatrixInColumnMajorForm->values)->el
                            = new int[refMtx->numberOfValues];

                        for (i = 0; i < numberOfRows; i++)
                        {
                            // get row indices and values of the matrix
                            for (j = refMtx->start->el[i]; j < refMtx->start->el[ i + 1 ]; j++)
                            {
                                iTemp = ExpandedMatrixInColumnMajorForm->starts[refMtx->indexes->el[j]];
                                ExpandedMatrixInColumnMajorForm->indexes [ iTemp] = i;
                                ((VarReferenceMatrixValues*)ExpandedMatrixInColumnMajorForm->values)->el[ iTemp] 
                                    = ((VarReferenceMatrixValues*)((VarReferenceMatrixElements*)refMtx)->values)->el[j];
                                ExpandedMatrixInColumnMajorForm->starts[refMtx->indexes->el[j]] ++;
                            }
                        }
                    }
                    else if (ExpandedMatrixInColumnMajorForm->vType == ENUM_MATRIX_TYPE_linear)
                    {
                        ExpandedMatrixInColumnMajorForm->values = new LinearMatrixValues();
                        ((LinearMatrixValues*)ExpandedMatrixInColumnMajorForm->values)->el 
                            = new LinearMatrixElement*[refMtx->numberOfValues];
                        for (i = 0; i < refMtx->numberOfValues; i++)
                            ((LinearMatrixValues*)ExpandedMatrixInColumnMajorForm->values)->el[i]
                                = new LinearMatrixElement(); 

                        for (i = 0; i < numberOfRows; i++)
                        {
                            // get row indices and values of the matrix
                            for (j = refMtx->start->el[i]; j < refMtx->start->el[ i + 1 ]; j++)
                            {
                                iTemp = ExpandedMatrixInColumnMajorForm->starts[refMtx->indexes->el[j]];
                                ExpandedMatrixInColumnMajorForm->indexes [ iTemp] = i;
                                if (!((LinearMatrixValues*)ExpandedMatrixInColumnMajorForm->values)->
                                    el[ iTemp]->deepCopyFrom(((LinearMatrixValues*)
                                        ((LinearMatrixElements*)refMtx)->values)->el[j]))
                                    return NULL;
                                ExpandedMatrixInColumnMajorForm->starts[refMtx->indexes->el[j]] ++;
                            }
                        }
                    }
                    else if (ExpandedMatrixInColumnMajorForm->vType == ENUM_MATRIX_TYPE_general)
                    {
                        ExpandedMatrixInColumnMajorForm->values = new GeneralMatrixValues();
                        ((GeneralMatrixValues*)ExpandedMatrixInColumnMajorForm->values)->el 
                            = new ScalarExpressionTree*[refMtx->numberOfValues];
                        for (i = 0; i < refMtx->numberOfValues; i++)
                        {
                            ((GeneralMatrixValues*)ExpandedMatrixInColumnMajorForm->values)->el[i]
                                = new ScalarExpressionTree();
//                            ((GeneralMatrixValues*)ExpandedMatrixInColumnMajorForm->values)->el[i]->m_treeRoot
//                                = new OSnLNode(); 
                        }

                        for (i = 0; i < numberOfRows; i++)
                        {
                            // get row indices and values of the matrix
                            for (j = refMtx->start->el[i]; j < refMtx->start->el[ i + 1 ]; j++)
                            {
                                iTemp = ExpandedMatrixInColumnMajorForm->starts[refMtx->indexes->el[j]];
                                ExpandedMatrixInColumnMajorForm->indexes [ iTemp] = i;
                                ((GeneralMatrixValues*)ExpandedMatrixInColumnMajorForm->values)->el[ iTemp]->m_treeRoot
                                    = ((GeneralMatrixValues*)((GeneralMatrixElements*)refMtx)->values)->el[j]->m_treeRoot->copyNodeAndDescendants();
                                ExpandedMatrixInColumnMajorForm->starts[refMtx->indexes->el[j]] ++;
                            }
                        }
                    }
                    else if (ExpandedMatrixInColumnMajorForm->vType == ENUM_MATRIX_TYPE_objref)
                    {
                        ExpandedMatrixInColumnMajorForm->values = new ObjReferenceMatrixValues();
                        ((ObjReferenceMatrixValues*)ExpandedMatrixInColumnMajorForm->values)->el
                            = new int[refMtx->numberOfValues];

                        for (i = 0; i < numberOfRows; i++)
                        {
                            // get row indices and values of the matrix
                            for (j = refMtx->start->el[i]; j < refMtx->start->el[ i + 1 ]; j++)
                            {
                                iTemp = ExpandedMatrixInColumnMajorForm->starts[refMtx->indexes->el[j]];
                                ExpandedMatrixInColumnMajorForm->indexes [ iTemp] = i;
                                ((ObjReferenceMatrixValues*)ExpandedMatrixInColumnMajorForm->values)->el[ iTemp] 
                                    = ((ObjReferenceMatrixValues*)((ObjReferenceMatrixElements*)refMtx)->values)->el[j];
                                ExpandedMatrixInColumnMajorForm->starts[refMtx->indexes->el[j]] ++;
                            }
                        }
                    }
                    else if (ExpandedMatrixInColumnMajorForm->vType == ENUM_MATRIX_TYPE_conref)
                    {
                        ExpandedMatrixInColumnMajorForm->values = new ConReferenceMatrixValues();
                        ((ConReferenceMatrixValues*)ExpandedMatrixInColumnMajorForm->values)->el 
                            = new ConReferenceMatrixElement*[refMtx->numberOfValues];
                        for (i = 0; i < refMtx->numberOfValues; i++)
                            ((ConReferenceMatrixValues*)ExpandedMatrixInColumnMajorForm->values)->el[i]
                                = new ConReferenceMatrixElement(); 

                        for (i = 0; i < numberOfRows; i++)
                        {
                            // get row indices and values of the matrix
                            for (j = refMtx->start->el[i]; j < refMtx->start->el[ i + 1 ]; j++)
                            {
                                iTemp = ExpandedMatrixInColumnMajorForm->starts[refMtx->indexes->el[j]];
                                ExpandedMatrixInColumnMajorForm->indexes [ iTemp] = i;
                                if (!((ConReferenceMatrixValues*)ExpandedMatrixInColumnMajorForm->values)->el[ iTemp]->deepCopyFrom(((ConReferenceMatrixValues*)((ConReferenceMatrixElements*)refMtx)->values)->el[j]))
                                    return NULL;
                                ExpandedMatrixInColumnMajorForm->starts[refMtx->indexes->el[j]] ++;
                            }
                        }
                    }

                    // readjust the starts
                    for (i = numberOfColumns; i >= 1; i-- )
                    {
                        ExpandedMatrixInColumnMajorForm->starts[i]
                            = ExpandedMatrixInColumnMajorForm->starts [i - 1] ;
                    }

                    ExpandedMatrixInColumnMajorForm->starts[0] = 0;
                    return ExpandedMatrixInColumnMajorForm;
                }
            }
        }

        else // two or more constructors --- worry about overwriting and number of elements
        {
/* 
        (basematrix plus) elements should be ok
        maybe transformation (product) plus elements
        others: throw error
*/
            throw ErrorClass("Multiple constructors not yet implemented in getMatrixCoefficientsInColumnMajor()");
        }
        return NULL;
    }
    catch(const ErrorClass& eclass)
    {
        throw ErrorClass( eclass.errormsg);
    }
}// end of getMatrixCoefficientsInColumnMajor

GeneralSparseMatrix* MatrixType::getMatrixCoefficientsInRowMajor()
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, "Inside getMatrixCoefficientsInRowMajor()");
#endif
    try
    {
        //Check if previous expansion available
        if (ExpandedMatrixInRowMajorForm != NULL)
            return ExpandedMatrixInRowMajorForm;
        if (ExpandedMatrixInColumnMajorForm != NULL)
        {
            ExpandedMatrixInRowMajorForm = convertToOtherMajor(true);
            return ExpandedMatrixInRowMajorForm;
        }

        // The complexity increases with the number of constructors
        // Start by checking for empty matrix
        if (inumberOfChildren == 0)
        {
            ExpandedMatrixInRowMajorForm = new GeneralSparseMatrix();
            ExpandedMatrixInRowMajorForm->symmetry = symmetry;
            ExpandedMatrixInRowMajorForm->valueSize = 0;
            ExpandedMatrixInRowMajorForm->startSize = numberOfRows + 1;
            ExpandedMatrixInRowMajorForm->starts = new int[numberOfRows + 1];
            for (int i=0; i <= numberOfRows; i++)
                ExpandedMatrixInRowMajorForm->starts[i] = 0;
            return ExpandedMatrixInRowMajorForm;
        }

        // single constructor --- process by type 
        else if (inumberOfChildren == 1)
        {
            if (m_mChildren[0]->getNodeType() == ENUM_MATRIX_CONSTRUCTOR_TYPE_baseMatrix)
            {
                int  baseMtxIdx = ((BaseMatrix*)m_mChildren[0])->baseMatrixIdx;
                OSMatrix* baseMtxPtr = ((BaseMatrix*)m_mChildren[0])->baseMatrix;

                int iroff = ((BaseMatrix*)m_mChildren[0])->targetMatrixFirstRow;
                int icoff = ((BaseMatrix*)m_mChildren[0])->targetMatrixFirstCol;
                int base_r0, base_c0, base_rN, base_cN;

                GeneralSparseMatrix* baseMtx;
                if (((BaseMatrix*)m_mChildren[0])->baseTranspose)
                {
                    baseMtx = baseMtxPtr->getMatrixCoefficientsInColumnMajor();
//                    iroff   = ((BaseMatrix*)m_mChildren[0])->targetMatrixFirstCol;
//                    icoff   = ((BaseMatrix*)m_mChildren[0])->targetMatrixFirstRow;
                    base_c0 = ((BaseMatrix*)m_mChildren[0])->baseMatrixStartCol;
                    base_r0 = ((BaseMatrix*)m_mChildren[0])->baseMatrixStartRow;
                    base_cN = ((BaseMatrix*)m_mChildren[0])->baseMatrixEndCol;
                    base_cN = ((BaseMatrix*)m_mChildren[0])->baseMatrixEndRow;
                    if (base_cN < 0)
                        base_cN = baseMtxPtr->numberOfColumns - 1;
                    if (base_rN < 0)
                        base_rN = baseMtxPtr->numberOfRows - 1;
                }
                else
                {
                    baseMtx = baseMtxPtr->getMatrixCoefficientsInRowMajor();
//                    iroff   = ((BaseMatrix*)m_mChildren[0])->targetMatrixFirstRow;
//                    icoff   = ((BaseMatrix*)m_mChildren[0])->targetMatrixFirstCol;
                    base_c0 = ((BaseMatrix*)m_mChildren[0])->baseMatrixStartRow;
                    base_r0 = ((BaseMatrix*)m_mChildren[0])->baseMatrixStartCol;
                    base_cN = ((BaseMatrix*)m_mChildren[0])->baseMatrixEndRow;
                    base_rN = ((BaseMatrix*)m_mChildren[0])->baseMatrixEndCol;
                    if (base_cN < 0)
                        base_cN = baseMtxPtr->numberOfRows - 1;
                    if (base_rN < 0)
                        base_rN = baseMtxPtr->numberOfColumns - 1;
                }

                double scaleMult = ((BaseMatrix*)m_mChildren[0])->scalarMultiplier;

                ExpandedMatrixInRowMajorForm = new GeneralSparseMatrix();
                ExpandedMatrixInRowMajorForm->symmetry  = symmetry;
                ExpandedMatrixInRowMajorForm->startSize = numberOfRows + 1;

                // position and other options can affect what arrays need to be duplicated
                bool isShifted = (iroff > 0 || icoff > 0);
                bool isCropped = (base_c0 > 0 || base_r0 > 0 || 
                                  base_rN < baseMtxPtr->numberOfRows - 1 ||
                                  base_cN < baseMtxPtr->numberOfColumns - 1);
                bool isClipped = (iroff + base_rN - base_r0 >= numberOfRows ||
                                  icoff + base_cN - base_c0 >= numberOfColumns);
                bool isScaled  = (scaleMult != 1);
                bool reTyped   = (getMatrixType() != baseMtx->vType);
                bool hasGap    = (icoff + base_cN - base_c0 < numberOfColumns - 1);

                //default position without cropping, scaling or retyping is easiest
                if ( !isShifted && !isCropped && !isClipped && !isScaled && !reTyped )
                {
                    ExpandedMatrixInRowMajorForm->b_deleteStartArray = false;
                    ExpandedMatrixInRowMajorForm->b_deleteIndexArray = hasGap;
                    ExpandedMatrixInRowMajorForm->b_deleteValueArray = false;
                    ExpandedMatrixInRowMajorForm->isRowMajor = false;
                    ExpandedMatrixInRowMajorForm->valueSize = baseMtx->valueSize;
                    ExpandedMatrixInRowMajorForm->vType     = baseMtx->vType;
                    ExpandedMatrixInRowMajorForm->indexes   = baseMtx->indexes;
                    ExpandedMatrixInRowMajorForm->values    = baseMtx->values;

                    // even in default layout the baseMatrix may still have different dimensions...
                    if (!hasGap)
                        ExpandedMatrixInColumnMajorForm->starts = baseMtx->starts;
                    else
                    {
                        ExpandedMatrixInRowMajorForm->startSize = numberOfRows + 1;
                        ExpandedMatrixInRowMajorForm->starts =
                            new int[ExpandedMatrixInRowMajorForm->startSize];
                        for (int i=0; i < baseMtx->startSize; i++)
                            ExpandedMatrixInRowMajorForm->starts[i] = baseMtx->starts[i];
                        int lastStart = baseMtx->valueSize;
                        for (int i=baseMtx->startSize; 
                                 i < ExpandedMatrixInRowMajorForm->startSize; i++)
                            ExpandedMatrixInRowMajorForm->starts[i] = lastStart;
                    }
                    return ExpandedMatrixInRowMajorForm; 
                }
                else
                {
                    // cropping, positioning or scaling all require a deep copy
                    if ( !isShifted && !isCropped && !isClipped )
                    {
                        // it's a bit easier if we are just scaling
                        ExpandedMatrixInRowMajorForm->b_deleteStartArray = hasGap;
                        ExpandedMatrixInRowMajorForm->b_deleteIndexArray = false;
                        ExpandedMatrixInRowMajorForm->b_deleteValueArray = true;
                        ExpandedMatrixInRowMajorForm->isRowMajor = false;
                        ExpandedMatrixInRowMajorForm->valueSize  = baseMtx->valueSize;
                        ExpandedMatrixInRowMajorForm->vType      = baseMtx->vType;
                        ExpandedMatrixInRowMajorForm->indexes    = baseMtx->indexes;

                        // even in default layout the baseMatrix may still have different dimensions...
                        if (!hasGap)
                            ExpandedMatrixInRowMajorForm->starts = baseMtx->starts;
                        else
                        {
                            ExpandedMatrixInRowMajorForm->startSize = numberOfRows + 1;
                            ExpandedMatrixInRowMajorForm->starts =
                                new int[ExpandedMatrixInRowMajorForm->startSize];
                            for (int i=0; i < baseMtx->startSize; i++)
                                ExpandedMatrixInRowMajorForm->starts[i] = baseMtx->starts[i];
                            int lastStart = baseMtx->valueSize;
                            for (int i=baseMtx->startSize; 
                                     i < ExpandedMatrixInRowMajorForm->startSize; i++)
                                ExpandedMatrixInRowMajorForm->starts[i] = lastStart;
                        }

                        // the values are a bit more difficult ...
                        if ( baseMtx->vType == ENUM_MATRIX_TYPE_constant)
                        {
                            ExpandedMatrixInRowMajorForm->values = new ConstantMatrixValues();
                            ((ConstantMatrixValues*)ExpandedMatrixInRowMajorForm->values)->el
                                = new double[baseMtx->valueSize];
                            for (int i = 0; i < baseMtx->valueSize; i++)
                                ((ConstantMatrixValues*)ExpandedMatrixInRowMajorForm->values)->el[i]
                                    = scaleMult*((ConstantMatrixValues*)baseMtx->values)->el[i];
                        }
                        else if (baseMtx->vType == ENUM_MATRIX_TYPE_varref)
                        {
                            // must convert to linear elements
                            LinearMatrixValues* tmpValues = new LinearMatrixValues();
                            tmpValues->el = new LinearMatrixElement*[baseMtx->valueSize];
                            for (int i = 0; i < baseMtx->valueSize; i++)
                            {
                                tmpValues->el[i] = new LinearMatrixElement();
                                tmpValues->el[i]->numberOfVarIdx = 1; 
                                tmpValues->el[i]->varIdx    = new LinearMatrixElementTerm*[1];
                                tmpValues->el[i]->varIdx[0] = new LinearMatrixElementTerm();
                                tmpValues->el[i]->varIdx[0]->coef = scaleMult;
                                tmpValues->el[i]->varIdx[0]->idx  
                                    = ((VarReferenceMatrixValues*)baseMtx->values)->el[i];
                            }
                            ExpandedMatrixInRowMajorForm->values = tmpValues;
                        }
                        else if (baseMtx->vType == ENUM_MATRIX_TYPE_linear)
                        {
                            LinearMatrixValues* tmpValues = new LinearMatrixValues();
                            tmpValues->el = new LinearMatrixElement*[baseMtx->valueSize];
                            for (int i = 0; i < baseMtx->valueSize; i++)
                            {
                                tmpValues->el[i] = new LinearMatrixElement();
                                if (!(tmpValues->el[i]
                                        ->deepCopyFrom(((LinearMatrixValues*)baseMtx->values)->el[i])))
                                    throw ErrorClass("failed copying linear element values in method getMatrixCoefficientsInRowMajor()");
                                for (int j=0; j<tmpValues->el[i]->numberOfVarIdx; j++)
                                    tmpValues->el[i]->varIdx[j]->coef *= scaleMult;
                            }
                            ExpandedMatrixInRowMajorForm->values = tmpValues;
                        }
                        else if (baseMtx->vType == ENUM_MATRIX_TYPE_general)
                        {
                            // add scalar multiple as a product
                            GeneralMatrixValues* tmpValues = new GeneralMatrixValues();
                            tmpValues->el = new ScalarExpressionTree*[baseMtx->valueSize];
                            for (int i = 0; i < baseMtx->valueSize; i++)
                            {
                                tmpValues->el[i] = new ScalarExpressionTree();
                                tmpValues->el[i]->m_treeRoot = new OSnLNodeTimes();
                                tmpValues->el[i]->m_treeRoot->m_mChildren[0] = new OSnLNodeNumber();
                                ((OSnLNodeNumber*)tmpValues->el[i]->m_treeRoot->m_mChildren[0])->value = scaleMult;
                                tmpValues->el[i]->m_treeRoot->m_mChildren[1]
                                     = ((GeneralMatrixValues*)baseMtx->values)->el[i]->m_treeRoot
                                        ->copyNodeAndDescendants();
                            }
                            ExpandedMatrixInRowMajorForm->values = tmpValues;
                        }
                        else if (baseMtx->vType == ENUM_MATRIX_TYPE_objref)
                        {
                            throw ErrorClass("scalar multiple not defined for objref elements in  getMatrixCoefficientsInRowMajor()");
                        }
                        else if (baseMtx->vType == ENUM_MATRIX_TYPE_conref)
                        {
                            throw ErrorClass("scalar multiple not defined for conref elements in  getMatrixCoefficientsInRowMajor()");
                        }
                        return ExpandedMatrixInColumnMajorForm; 
                    }
                    else // repositioned Basematrix with cropping
                    {
                        ExpandedMatrixInRowMajorForm->b_deleteStartArray = true;
                        ExpandedMatrixInRowMajorForm->b_deleteIndexArray = true;
                        ExpandedMatrixInRowMajorForm->b_deleteValueArray = true;
                        ExpandedMatrixInRowMajorForm->startSize = numberOfRows + 1;
                        ExpandedMatrixInRowMajorForm->isRowMajor = false;
                        ExpandedMatrixInRowMajorForm->vType      = baseMtx->vType;

                        int  startSize = numberOfRows + 1; 
                        int* tmpStarts = new int[startSize];
                        for (int i=0; i < startSize; i++)
                            tmpStarts[i] = 0;

                        int adjc = icoff - base_c0;
                        int lastcol = icoff + base_cN - base_c0 + 1;
                        if (lastcol > numberOfRows)
                            lastcol = numberOfRows;

                        // count elements in each column and calculate starts
                        for (int i=icoff; i<lastcol; i++)
                            for (int j=baseMtx->starts[i-adjc]; j<baseMtx->starts[i-adjc+1]; j++)
                            {
                                if (baseMtx->indexes[j] >= base_r0 &&
                                    baseMtx->indexes[j] <= base_rN &&
                                    baseMtx->indexes[j] <  numberOfColumns + base_r0 - iroff)
                                tmpStarts[i+1]++; 
                            }
                        for (int i=icoff+1; i <= startSize; i++)
                            tmpStarts[i] += tmpStarts[i-1];
 
                        int valueSize = tmpStarts[startSize-1];
                        int* tmpIndexes = new int[valueSize];

                        ExpandedMatrixInRowMajorForm->valueSize  = valueSize;
                        ExpandedMatrixInRowMajorForm->starts     = tmpStarts;

                        // to get the values, go through the base matrix a second time
                        if ( baseMtx->vType == ENUM_MATRIX_TYPE_constant)
                        {
                            MatrixElementValues* tmpValues = new ConstantMatrixValues();
                            ((ConstantMatrixValues*)tmpValues)->el = new double[valueSize];

                            int ival = 0;
                            for (int i=icoff; i<lastcol; i++)
                                for (int j=baseMtx->starts[i-adjc]; j<baseMtx->starts[i-adjc+1]; j++)
                                {
                                    if (baseMtx->indexes[j] >= base_r0 &&
                                        baseMtx->indexes[j] <= base_rN &&
                                        baseMtx->indexes[j] <  numberOfColumns + base_r0 - iroff)
                                    {
                                        tmpIndexes[ival] = baseMtx->indexes[j] - base_r0 + iroff; 
                                        ((ConstantMatrixValues*)tmpValues)->el[ival]
                                            = scaleMult*((ConstantMatrixValues*)baseMtx->values)->el[j];
                                        ival++;
                                    }    
                                }
                            ExpandedMatrixInRowMajorForm->indexes = tmpIndexes;
                            ExpandedMatrixInRowMajorForm->values  = tmpValues;
                        }

                        else if (baseMtx->vType == ENUM_MATRIX_TYPE_varref)
                        {
                            if (scaleMult == 1)
                            {
                                MatrixElementValues* tmpValues = new VarReferenceMatrixValues();
                                ((VarReferenceMatrixValues*)tmpValues)->el = new int[valueSize];

                                int ival = 0;
                                for (int i=icoff; i<lastcol; i++)
                                    for (int j=baseMtx->starts[i-adjc]; j<baseMtx->starts[i-adjc+1]; j++)
                                    {
                                        if (baseMtx->indexes[j] >= base_r0 &&
                                            baseMtx->indexes[j] <  numberOfColumns + base_r0 - iroff)
                                        {
                                            tmpIndexes[ival] = baseMtx->indexes[j] + base_r0 - iroff; 
                                            ((ConstantMatrixValues*)ExpandedMatrixInRowMajorForm->values)->el[ival]
                                                = scaleMult*((ConstantMatrixValues*)baseMtx->values)->el[j];
                                            ival++;
                                        }    
                                    }
                                ExpandedMatrixInRowMajorForm->indexes = tmpIndexes;
                                ExpandedMatrixInRowMajorForm->values  = tmpValues;
                            }
                            else
                            {
                                // must convert to linear elements
                                MatrixElementValues* tmpValues = new LinearMatrixValues();
                                ((LinearMatrixValues*)tmpValues)->el 
                                    = new LinearMatrixElement*[valueSize];

                                int ival = 0;
                                for (int i=icoff; i<lastcol; i++)
                                    for (int j=baseMtx->starts[i-adjc]; j<baseMtx->starts[i-adjc+1]; j++)
                                    {
                                        if (baseMtx->indexes[j] >= base_r0 &&
                                            baseMtx->indexes[j] <  numberOfColumns + base_r0 - iroff)
                                        {
                                            ((LinearMatrixValues*)tmpValues)->el[ival] 
                                                = new LinearMatrixElement();
                                            ((LinearMatrixValues*)tmpValues)->el[ival]->numberOfVarIdx = 1; 
                                            ((LinearMatrixValues*)tmpValues)->el[ival]->varIdx 
                                                = new LinearMatrixElementTerm*[1];
                                            ((LinearMatrixValues*)tmpValues)->el[ival]->varIdx[0] 
                                                = new LinearMatrixElementTerm();
                                            ((LinearMatrixValues*)tmpValues)->el[ival]->varIdx[0]->coef 
                                                = scaleMult;
                                            ((LinearMatrixValues*)tmpValues)->el[ival]->varIdx[0]->idx  
                                                = ((VarReferenceMatrixValues*)baseMtx->values)->el[j];
                                            ival++;
                                        }
                                    }
                                ExpandedMatrixInRowMajorForm->indexes = tmpIndexes;
                                ExpandedMatrixInRowMajorForm->values  = tmpValues;
                            }
                        }
                        else if (baseMtx->vType == ENUM_MATRIX_TYPE_linear)
                        {
                            LinearMatrixValues* tmpValues = new LinearMatrixValues();
                            tmpValues->el = new LinearMatrixElement*[baseMtx->valueSize];

                            int ival = 0;
                            for (int i=icoff; i<lastcol; i++)
                                for (int j=baseMtx->starts[i-adjc]; j<baseMtx->starts[i-adjc+1]; j++)
                                {
                                    if (baseMtx->indexes[j] >= base_r0 &&
                                        baseMtx->indexes[j] <  numberOfColumns + base_r0 - iroff)
                                    {
                                        tmpValues->el[ival] = new LinearMatrixElement();
                                        if (!(tmpValues->el[ival]
                                                ->deepCopyFrom(((LinearMatrixValues*)baseMtx->values)->el[j])))
                                        throw ErrorClass("failed copying linear element values in method getMatrixCoefficientsInRowMajor()");
                                    for (int k=0; k<tmpValues->el[ival]->numberOfVarIdx; k++)
                                        tmpValues->el[ival]->varIdx[k]->coef *= scaleMult;
                                    ival++;
                                    }
                                }
                            ExpandedMatrixInRowMajorForm->indexes = tmpIndexes;
                            ExpandedMatrixInRowMajorForm->values  = tmpValues;
                        }
                        else if (baseMtx->vType == ENUM_MATRIX_TYPE_general)
                        {
                            if (scaleMult == 1)
                            {
                                GeneralMatrixValues* tmpValues = new GeneralMatrixValues();
                                tmpValues->el = new ScalarExpressionTree*[baseMtx->valueSize];

                                int ival = 0;
                                for (int i=icoff; i<lastcol; i++)
                                    for (int j=baseMtx->starts[i-adjc]; j<baseMtx->starts[i-adjc+1]; j++)
                                    {
                                        if (baseMtx->indexes[j] >= base_r0 &&
                                            baseMtx->indexes[j] <  numberOfColumns + base_r0 - iroff)
                                        {
                                            ((GeneralMatrixValues*)tmpValues)->el[ival] 
                                                = new ScalarExpressionTree();
//                                            ((GeneralMatrixValues*)tmpValues)->el[ival]->m_treeRoot 
//                                                = new OSnLNode();
                                            ((GeneralMatrixValues*)tmpValues)->el[ival]->m_treeRoot 
                                                = ((GeneralMatrixValues*)baseMtx->values)->el[j]->m_treeRoot
                                                    ->copyNodeAndDescendants();
                                            ival++;
                                        }
                                    }
                                ExpandedMatrixInRowMajorForm->indexes = tmpIndexes;
                                ExpandedMatrixInRowMajorForm->values  = tmpValues;
                            }
                            else
                            {
                                // add scalar multiple as a product
                                GeneralMatrixValues* tmpValues = new GeneralMatrixValues();
                                tmpValues->el = new ScalarExpressionTree*[baseMtx->valueSize];
                                int ival = 0;
                                for (int i=icoff; i<lastcol; i++)
                                    for (int j=baseMtx->starts[i-adjc]; j<baseMtx->starts[i-adjc+1]; j++)
                                    {
                                        if (baseMtx->indexes[j] >= base_r0 &&
                                            baseMtx->indexes[j] <  numberOfColumns + base_r0 - iroff)
                                        {
                                            ((GeneralMatrixValues*)tmpValues)->el[ival] 
                                                = new ScalarExpressionTree();
                                            ((GeneralMatrixValues*)tmpValues)->el[ival]->m_treeRoot 
                                                = new OSnLNodeTimes();
                                            ((GeneralMatrixValues*)tmpValues)->el[ival]->m_treeRoot->m_mChildren[0] 
                                                = new OSnLNodeNumber();
                                            ((OSnLNodeNumber*)tmpValues->el[ival]->m_treeRoot->m_mChildren[0])->value = scaleMult;
                                            ((GeneralMatrixValues*)tmpValues)->el[ival]->m_treeRoot->m_mChildren[1]
                                                = ((GeneralMatrixValues*)baseMtx->values)->el[j]->m_treeRoot->copyNodeAndDescendants();
                                            ival++;

                                        }
                                    }
                                ExpandedMatrixInRowMajorForm->indexes = tmpIndexes;
                                ExpandedMatrixInRowMajorForm->values  = tmpValues;
                            }
                        }
                        else if (baseMtx->vType == ENUM_MATRIX_TYPE_objref)
                        {
                                    throw ErrorClass("scalar multiple not defined for objref elements in  getMatrixCoefficientsInRowMajor()");
                        }
                        else if (baseMtx->vType == ENUM_MATRIX_TYPE_conref)
                        {
                                    throw ErrorClass("scalar multiple not defined for conref elements in  getMatrixCoefficientsInRowMajor()");
                        }
                    }
                    return ExpandedMatrixInRowMajorForm; 
                }
            }

            else if (m_mChildren[0]->getNodeType() == ENUM_MATRIX_CONSTRUCTOR_TYPE_blocks)
            {
                //make sure the blocks have been expanded, then retrieve them 
                if (!processBlocks(true, symmetry))
                    throw ErrorClass("error processing blocks in getMatrixCoefficientsInRowMajor()");
                
                ExpandedMatrixBlocks* currentBlocks 
                    = getBlocks(m_miRowPartition, m_iRowPartitionSize, m_miColumnPartition,
                                m_iColumnPartitionSize, true, true);
                //ExpandedMatrixByBlocks.push_back(currentBlocks);

                ExpandedMatrixInRowMajorForm = new GeneralSparseMatrix();
                ExpandedMatrixInRowMajorForm->b_deleteStartArray = true;
                ExpandedMatrixInRowMajorForm->b_deleteIndexArray = true;
                ExpandedMatrixInRowMajorForm->b_deleteValueArray = true;
                ExpandedMatrixInRowMajorForm->vType = getMatrixType();
                ExpandedMatrixInRowMajorForm->isRowMajor = false;
                ExpandedMatrixInRowMajorForm->symmetry = symmetry;
                ExpandedMatrixInRowMajorForm->startSize = numberOfRows + 1;
                ExpandedMatrixInRowMajorForm->starts = new int[numberOfRows + 1];
                for (int i=0; i <= numberOfRows; i++)
                    ExpandedMatrixInRowMajorForm->starts[i] = 0;

                // augment column lengths block by block
                for (int i=0; i < currentBlocks->blockNumber; i++)
                {
                    int c0 = currentBlocks->colOffsets[currentBlocks->blockColumns[i]];
                    int cN = currentBlocks->colOffsets[currentBlocks->blockColumns[i]+1];
                    for (int j = c0; j < cN; j++)
                    {
                        ExpandedMatrixInRowMajorForm->starts[j+1] += 
                            ( currentBlocks->blocks[i]->starts[j+1-c0] 
                            - currentBlocks->blocks[i]->starts[j  -c0] );
                    } 
                }

                for (int i=1; i <= numberOfRows; i++)
                    ExpandedMatrixInRowMajorForm->starts[i] +=
                        ExpandedMatrixInRowMajorForm->starts[i-1];
                ExpandedMatrixInRowMajorForm->valueSize = 
                    ExpandedMatrixInRowMajorForm->starts[numberOfRows];
                int* tmpIndexes = new int[ExpandedMatrixInRowMajorForm->valueSize];

                // go through the blocks a second time to store values --- based on type
                if (currentBlocks->blocks[0]->vType == ENUM_MATRIX_TYPE_constant)
                {
                    ConstantMatrixValues* tmpValues = new ConstantMatrixValues();
                    tmpValues->el
                        = new double[ExpandedMatrixInRowMajorForm->valueSize];

                    for (int i=0; i < currentBlocks->blockNumber; i++)
                    {
                        int c0 = currentBlocks->rowOffsets[currentBlocks->blockRows[i]];
                        int cN = currentBlocks->rowOffsets[currentBlocks->blockRows[i]+1];
                        int row_adj = currentBlocks->colOffsets[currentBlocks->blockColumns[i]];

                        for (int j = c0; j < cN; j++)
                        {
                            int loc = ExpandedMatrixInRowMajorForm->starts[j];
                            for (int k = currentBlocks->blocks[i]->starts[j-c0];
                                     k < currentBlocks->blocks[i]->starts[j-c0+1]; k++)
                            {
                                tmpIndexes[loc] = currentBlocks->blocks[i]->indexes[k] + row_adj;
                                ((ConstantMatrixValues*)tmpValues)->el[loc] 
                                    = ((ConstantMatrixValues*)currentBlocks->blocks[i]->values)->el[k];
                                loc++;
                            }
                            ExpandedMatrixInRowMajorForm->starts[j] = loc;
                        }
                    }
                    ExpandedMatrixInRowMajorForm->indexes = tmpIndexes;
                    ExpandedMatrixInRowMajorForm->values  = tmpValues;
                }
                else
                    throw ErrorClass("getMatrixCoefficientsInRowMajor: Can only handle constant values so far in blocks");
                for (int i=numberOfColumns; i > 0; i--)
                    ExpandedMatrixInRowMajorForm->starts[i] =
                        ExpandedMatrixInRowMajorForm->starts[i-1];
                ExpandedMatrixInRowMajorForm->starts[0] = 0;
            }

            else if (m_mChildren[0]->getNodeType() == ENUM_MATRIX_CONSTRUCTOR_TYPE_transformation)
            {
//              transformation: see if we can do at least AB, A'B, AB'
//              for now:
                throw ErrorClass("transformations not yet implemented in getMatrixCoefficientsInColumnMajor()");
            }
            else // some kind of elements --- if given row-wise, just copy pointers
            {
                if (((MatrixElements*)m_mChildren[0])->rowMajor)
                {
                    ExpandedMatrixInRowMajorForm = new GeneralSparseMatrix();
                    ExpandedMatrixInRowMajorForm->symmetry = symmetry;
                    ExpandedMatrixInRowMajorForm->b_deleteStartArray = false;
                    ExpandedMatrixInRowMajorForm->b_deleteIndexArray = false;
                    ExpandedMatrixInRowMajorForm->b_deleteValueArray = false;
                    ExpandedMatrixInRowMajorForm->isRowMajor = false;
                    ExpandedMatrixInRowMajorForm->startSize = numberOfRows + 1;
                    ExpandedMatrixInRowMajorForm->valueSize
                        = ((MatrixElements*)m_mChildren[0])->numberOfValues;
                    ExpandedMatrixInRowMajorForm->starts
                        = ((MatrixElements*)m_mChildren[0])->start->el;
                    ExpandedMatrixInRowMajorForm->vType     
                        = getMatrixType();
                    ExpandedMatrixInRowMajorForm->indexes   
                        = ((MatrixElements*)m_mChildren[0])->indexes->el;
                    if (ExpandedMatrixInRowMajorForm->vType == ENUM_MATRIX_TYPE_constant)
                        ExpandedMatrixInRowMajorForm->values    
                            = ((ConstantMatrixElements*)m_mChildren[0])->values;
                    else if (ExpandedMatrixInRowMajorForm->vType == ENUM_MATRIX_TYPE_varref)
                        ExpandedMatrixInRowMajorForm->values    
                            = ((VarReferenceMatrixElements*)m_mChildren[0])->values;
                    else if (ExpandedMatrixInRowMajorForm->vType == ENUM_MATRIX_TYPE_linear)
                        ExpandedMatrixInRowMajorForm->values    
                            = ((LinearMatrixElements*)m_mChildren[0])->values;
                    else if (ExpandedMatrixInRowMajorForm->vType == ENUM_MATRIX_TYPE_general)
                        ExpandedMatrixInRowMajorForm->values    
                            = ((GeneralMatrixElements*)m_mChildren[0])->values;
                    else if (ExpandedMatrixInRowMajorForm->vType == ENUM_MATRIX_TYPE_objref)
                        ExpandedMatrixInRowMajorForm->values    
                            = ((ObjReferenceMatrixElements*)m_mChildren[0])->values;
                    else if (ExpandedMatrixInRowMajorForm->vType == ENUM_MATRIX_TYPE_conref)
                        ExpandedMatrixInRowMajorForm->values    
                            = ((ConReferenceMatrixElements*)m_mChildren[0])->values;
                    else
                        throw ErrorClass("Unknown element type in getMatrixCoefficientsInRowMajor()");

                    return ExpandedMatrixInRowMajorForm; 
                }

                else // elements are given column-wise and must be "turned" 
                {
                    MatrixElements* refMtx = (MatrixElements*)m_mChildren[0];

                    ExpandedMatrixInRowMajorForm = new GeneralSparseMatrix();
                    ExpandedMatrixInRowMajorForm->symmetry = symmetry;
                    ExpandedMatrixInRowMajorForm->startSize = numberOfRows + 1;
                    ExpandedMatrixInRowMajorForm->vType = getMatrixType();
                    ExpandedMatrixInRowMajorForm->starts = new int[numberOfRows + 1];
                    for (int i=0; i <= numberOfRows; i++)
                        ExpandedMatrixInRowMajorForm->starts[i] = 0;

                    //if <values> is empty, return an empty matrix
                    if (refMtx == NULL || refMtx->numberOfValues == 0)
                    {
                        ExpandedMatrixInRowMajorForm->valueSize = 0;
                        return ExpandedMatrixInRowMajorForm;
                    }                        

                    ExpandedMatrixInRowMajorForm->valueSize = refMtx->numberOfValues;
                    ExpandedMatrixInRowMajorForm->indexes = new int[refMtx->numberOfValues];

                    int i, j, iTemp;
                    int iNumSource = numberOfColumns;

                    for (i = 0; i < numberOfColumns; i++)
                    {
                        for (j = refMtx->start->el[i]; j < refMtx->start->el[i + 1]; j++)
                        {
                            ExpandedMatrixInRowMajorForm->starts[refMtx->indexes->el[j] + 1] ++;
                        }
                    }
                    ExpandedMatrixInRowMajorForm->starts[0] = 0;

                    for (i = 1; i <= numberOfRows; i++ )
                    {
                        ExpandedMatrixInRowMajorForm->starts[i] 
                            += ExpandedMatrixInRowMajorForm->starts [i - 1] ;
                    }

                    // store the elements, by type
                    if (ExpandedMatrixInRowMajorForm->vType == ENUM_MATRIX_TYPE_constant)
                    {
                        ExpandedMatrixInRowMajorForm->values = new ConstantMatrixValues();
                        ((ConstantMatrixValues*)ExpandedMatrixInRowMajorForm->values)->el
                            = new double[refMtx->numberOfValues];

                        for (i = 0; i < numberOfColumns; i++)
                        {
                            // get column indices and values of the matrix
                            for (j = refMtx->start->el[i]; j < refMtx->start->el[ i + 1 ]; j++)
                            {
                                iTemp = ExpandedMatrixInRowMajorForm->starts[refMtx->indexes->el[j]];
                                ExpandedMatrixInRowMajorForm->indexes [ iTemp] = i;
                                ((ConstantMatrixValues*)ExpandedMatrixInRowMajorForm->values)->el[ iTemp] 
                                    = ((ConstantMatrixValues*)((ConstantMatrixElements*)refMtx)->values)->el[j];
                                ExpandedMatrixInRowMajorForm->starts[refMtx->indexes->el[j]] ++;
                            }
                        }
                    }
                    else if (ExpandedMatrixInRowMajorForm->vType == ENUM_MATRIX_TYPE_varref)
                    {
                        ExpandedMatrixInRowMajorForm->values = new VarReferenceMatrixValues();
                        ((VarReferenceMatrixValues*)ExpandedMatrixInRowMajorForm->values)->el
                            = new int[refMtx->numberOfValues];

                        for (i = 0; i < numberOfColumns; i++)
                        {
                            // get column indices and values of the matrix
                            for (j = refMtx->start->el[i]; j < refMtx->start->el[ i + 1 ]; j++)
                            {
                                iTemp = ExpandedMatrixInRowMajorForm->starts[refMtx->indexes->el[j]];
                                ExpandedMatrixInRowMajorForm->indexes [ iTemp] = i;
                                ((VarReferenceMatrixValues*)ExpandedMatrixInRowMajorForm->values)->el[ iTemp] 
                                    = ((VarReferenceMatrixValues*)((VarReferenceMatrixElements*)refMtx)->values)->el[j];
                                ExpandedMatrixInRowMajorForm->starts[refMtx->indexes->el[j]] ++;
                            }
                        }
                    }
                    else if (ExpandedMatrixInRowMajorForm->vType == ENUM_MATRIX_TYPE_linear)
                    {
                        ExpandedMatrixInRowMajorForm->values = new LinearMatrixValues();
                        ((LinearMatrixValues*)ExpandedMatrixInRowMajorForm->values)->el 
                            = new LinearMatrixElement*[refMtx->numberOfValues];
                        for (i = 0; i < refMtx->numberOfValues; i++)
                            ((LinearMatrixValues*)ExpandedMatrixInRowMajorForm->values)->el[i]
                                = new LinearMatrixElement(); 

                        for (i = 0; i < numberOfColumns; i++)
                        {
                            // get column indices and values of the matrix
                            for (j = refMtx->start->el[i]; j < refMtx->start->el[ i + 1 ]; j++)
                            {
                                iTemp = ExpandedMatrixInRowMajorForm->starts[refMtx->indexes->el[j]];
                                ExpandedMatrixInRowMajorForm->indexes [ iTemp] = i;
                                if (!((LinearMatrixValues*)ExpandedMatrixInRowMajorForm->values)->
                                    el[ iTemp]->deepCopyFrom(((LinearMatrixValues*)
                                        ((LinearMatrixElements*)refMtx)->values)->el[j]))
                                    return NULL;
                                ExpandedMatrixInRowMajorForm->starts[refMtx->indexes->el[j]] ++;
                            }
                        }
                    }
                    else if (ExpandedMatrixInRowMajorForm->vType == ENUM_MATRIX_TYPE_general)
                    {
                        ExpandedMatrixInRowMajorForm->values = new GeneralMatrixValues();
                        ((GeneralMatrixValues*)ExpandedMatrixInRowMajorForm->values)->el 
                            = new ScalarExpressionTree*[refMtx->numberOfValues];
                        for (i = 0; i < refMtx->numberOfValues; i++)
                        {
                            ((GeneralMatrixValues*)ExpandedMatrixInRowMajorForm->values)->el[i]
                                = new ScalarExpressionTree();
//                            ((GeneralMatrixValues*)ExpandedMatrixInRowMajorForm->values)->el[i]->m_treeRoot
//                                = new OSnLNode(); 
                        }

                        for (i = 0; i < numberOfColumns; i++)
                        {
                            // get column indices and values of the matrix
                            for (j = refMtx->start->el[i]; j < refMtx->start->el[ i + 1 ]; j++)
                            {
                                iTemp = ExpandedMatrixInRowMajorForm->starts[refMtx->indexes->el[j]];
                                ExpandedMatrixInRowMajorForm->indexes [ iTemp] = i;
                                ((GeneralMatrixValues*)ExpandedMatrixInRowMajorForm->values)->el[ iTemp]->m_treeRoot
                                    = ((GeneralMatrixValues*)((GeneralMatrixElements*)refMtx)->values)->el[j]->m_treeRoot->copyNodeAndDescendants();
                                ExpandedMatrixInRowMajorForm->starts[refMtx->indexes->el[j]] ++;
                            }
                        }
                    }
                    else if (ExpandedMatrixInRowMajorForm->vType == ENUM_MATRIX_TYPE_objref)
                    {
                        ExpandedMatrixInRowMajorForm->values = new ObjReferenceMatrixValues();
                        ((ObjReferenceMatrixValues*)ExpandedMatrixInRowMajorForm->values)->el
                            = new int[refMtx->numberOfValues];

                        for (i = 0; i < numberOfColumns; i++)
                        {
                            // get column indices and values of the matrix
                            for (j = refMtx->start->el[i]; j < refMtx->start->el[ i + 1 ]; j++)
                            {
                                iTemp = ExpandedMatrixInRowMajorForm->starts[refMtx->indexes->el[j]];
                                ExpandedMatrixInRowMajorForm->indexes [ iTemp] = i;
                                ((ObjReferenceMatrixValues*)ExpandedMatrixInRowMajorForm->values)->el[ iTemp] 
                                    = ((ObjReferenceMatrixValues*)((ObjReferenceMatrixElements*)refMtx)->values)->el[j];
                                ExpandedMatrixInRowMajorForm->starts[refMtx->indexes->el[j]] ++;
                            }
                        }
                    }
                    else if (ExpandedMatrixInRowMajorForm->vType == ENUM_MATRIX_TYPE_conref)
                    {
                        ExpandedMatrixInRowMajorForm->values = new ConReferenceMatrixValues();
                        ((ConReferenceMatrixValues*)ExpandedMatrixInRowMajorForm->values)->el 
                            = new ConReferenceMatrixElement*[refMtx->numberOfValues];
                        for (i = 0; i < refMtx->numberOfValues; i++)
                            ((ConReferenceMatrixValues*)ExpandedMatrixInRowMajorForm->values)->el[i]
                                = new ConReferenceMatrixElement(); 

                        for (i = 0; i < numberOfColumns; i++)
                        {
                            // get column indices and values of the matrix
                            for (j = refMtx->start->el[i]; j < refMtx->start->el[ i + 1 ]; j++)
                            {
                                iTemp = ExpandedMatrixInRowMajorForm->starts[refMtx->indexes->el[j]];
                                ExpandedMatrixInRowMajorForm->indexes [ iTemp] = i;
                                if (!((ConReferenceMatrixValues*)ExpandedMatrixInRowMajorForm->values)->el[ iTemp]->deepCopyFrom(((ConReferenceMatrixValues*)((ConReferenceMatrixElements*)refMtx)->values)->el[j]))
                                    return NULL;
                                ExpandedMatrixInRowMajorForm->starts[refMtx->indexes->el[j]] ++;
                            }
                        }
                    }

                    // readjust the starts
                    for (i = numberOfRows; i >= 1; i-- )
                    {
                        ExpandedMatrixInRowMajorForm->starts[i]
                            = ExpandedMatrixInRowMajorForm->starts [i - 1] ;
                    }

                    ExpandedMatrixInRowMajorForm->starts[0] = 0;
                    return ExpandedMatrixInRowMajorForm;
                }
            }
        }

        else // two or more constructors --- worry about overwriting and number of elements
        {
/* 
        (basematrix plus) elements should be ok
        maybe transformation (product) plus elements
        others: throw error
*/
            throw ErrorClass("Multiple constructors not yet implemented in getMatrixCoefficientsInRowMajor()");
        }
        return NULL;
    }
    catch(const ErrorClass& eclass)
    {
        throw ErrorClass( eclass.errormsg);
    }
}// end of getMatrixCoefficientsInRowMajor

bool MatrixType::expandElements(bool rowMajor)
{
    return NULL;
}// end of expandElements

bool MatrixType::printExpandedMatrix(bool rowMajor_)
{
    try
    {
        GeneralSparseMatrix* tmp;

        if (rowMajor_)
        {
            if (ExpandedMatrixInRowMajorForm == NULL)
                return false;
            tmp = ExpandedMatrixInRowMajorForm;
        }
        else
        {
            if (ExpandedMatrixInColumnMajorForm == NULL)
                return false;
            tmp = ExpandedMatrixInColumnMajorForm;
        }
        
        std::ostringstream outStr;
    
        ENUM_MATRIX_CONSTRUCTOR_TYPE type;

        if (getNodeType() == ENUM_MATRIX_CONSTRUCTOR_TYPE_matrix)
        {
            outStr << "matrix " << ((OSMatrix*)this)->idx;
            if (((OSMatrix*)this)->name != "")
                outStr << " ("  << ((OSMatrix*)this)->name << ")";
            outStr << std::endl;
        }
        else if (getNodeType() == ENUM_MATRIX_CONSTRUCTOR_TYPE_block)
            outStr << "matrix block" << std::endl;
        else
            throw ErrorClass("matrix type unknown or not set");

        outStr << "number of rows     " << numberOfRows << std::endl;
        outStr << "number of columns  " << numberOfColumns << std::endl;
        outStr << "number of nonzeros " << tmp->valueSize << std::endl;
        outStr << "type of nonzeros   " << returnMatrixTypeString(tmp->vType) << std::endl;
        outStr << "symmetry           " << returnMatrixSymmetryString(symmetry) << std::endl;

        outStr << std::endl << "These matrix arrays are organized ";             
        if (rowMajor_)
            outStr << "by rows" << std::endl;
        else
            outStr << "by columns" << std::endl;

        outStr << std::endl << "starts:";
        for (int i=0; i < tmp->startSize; i++)
            outStr << "  " << tmp->starts[i];
        outStr << std::endl;

        outStr << std::endl << "indexes:";
        for (int i=0; i < tmp->valueSize; i++)
            outStr << "  " << tmp->indexes[i];
        outStr << std::endl;

        outStr << std::endl << "values:";
        if (tmp->vType == ENUM_MATRIX_TYPE_constant)
        {
            for (int i=0; i < tmp->valueSize; i++)
                outStr << "  " << ((ConstantMatrixValues*)tmp->values)->el[i];
            outStr << std::endl;
        }
        else if (tmp->vType == ENUM_MATRIX_TYPE_varref)
        {
            for (int i=0; i < tmp->valueSize; i++)
                outStr << "  " << ((VarReferenceMatrixValues*)tmp->values)->el[i];
            outStr << std::endl;
        }
        else if (tmp->vType == ENUM_MATRIX_TYPE_objref) 
        {
            for (int i=0; i < tmp->valueSize; i++)
                outStr << "  " << ((ObjReferenceMatrixValues*)tmp->values)->el[i];
            outStr << std::endl;
        }
        else if (tmp->vType == ENUM_MATRIX_TYPE_conref) 
        {
            for (int i=0; i < tmp->valueSize; i++)
                outStr << "  " << ((ConReferenceMatrixValues*)tmp->values)->el[i]->conReference;
            outStr << std::endl;
        }
        else if (tmp->vType == ENUM_MATRIX_TYPE_general) 
        {
            outStr << std::endl;
            for (int i=0; i < tmp->valueSize; i++)
                outStr << "element " << i << ": (general expression; not yet implemented)" << std::endl;
            outStr << std::endl;
        }
        else if (tmp->vType == ENUM_MATRIX_TYPE_linear) 
        {
            outStr << std::endl;
            for (int i=0; i < tmp->valueSize; i++)
            {
                outStr << "element " << i << ": ";

                double c = ((LinearMatrixElement*)((LinearMatrixValues*)tmp->values)->el[i])->constant;
                int    m = ((LinearMatrixElement*)((LinearMatrixValues*)tmp->values)->el[i])->numberOfVarIdx;
                if (c != 0)
                {
                    outStr << c;
                    if (m > 0) 
                        outStr << " + ";
                }

                LinearMatrixElementTerm* temp;
                for (int j=0; j<m; j++)
                {
                    if (j > 0) 
                        outStr << " + ";
                    temp = ((LinearMatrixElement*)((LinearMatrixValues*)tmp->values)->el[i])->varIdx[j];
                    if (temp->coef != 1)
                        outStr << temp->coef << "*";
                    outStr << "x[" << temp->idx << "]";
                }
                outStr << std::endl;
            }
            outStr << std::endl;
        }
        osoutput->OSPrint(ENUM_OUTPUT_AREA_OSMatrix, ENUM_OUTPUT_LEVEL_always, outStr.str());

        return true;
    }
    catch(const ErrorClass& eclass)
    {
        throw ErrorClass( eclass.errormsg);
    }
}// end of printExpandedMatrix

GeneralSparseMatrix* MatrixType::convertToOtherMajor(bool isColumnMajor)
//    bool isColumnMajor, int startSize, int valueSize, int* start, int* index,
//    double* value, int dimension)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, "Inside convertToOtherMajor()");
#endif
    GeneralSparseMatrix* refMtx;
    if (isColumnMajor)
    {
        refMtx = ExpandedMatrixInColumnMajorForm;
        if (ExpandedMatrixInRowMajorForm != NULL) return ExpandedMatrixInRowMajorForm;
    }
    else
    {
        refMtx = ExpandedMatrixInRowMajorForm;
        if (ExpandedMatrixInColumnMajorForm != NULL) return ExpandedMatrixInColumnMajorForm;
    }
    if (refMtx == NULL ) return NULL;
    if (refMtx->starts == NULL || refMtx->startSize <= 1 ) return NULL;

    int iStartSize = isColumnMajor ? numberOfRows+1 : numberOfColumns+1;
    GeneralSparseMatrix *matrix
        = new GeneralSparseMatrix( !isColumnMajor, iStartSize, refMtx->valueSize, refMtx->vType);

    int i,j, iTemp;
    int iNumSource = refMtx->startSize - 1;

    int* miStart = matrix->starts;
    int* miIndex = matrix->indexes;

    for ( i = 1; i < iStartSize; i++)
    {
        miStart [ i ] = 0;
    }
    // for illustration assume we are converting from column to row major
    // i is indexing columns and j is indexing row numbers
    for (i = 0; i < iNumSource; i++)
    {
        for (j = refMtx->starts[i]; j < refMtx->starts[ i + 1 ]; j++)
        {
            // index[ j] is a row index, we have just found an occurance of row index[j]
            // therefore we increase by 1 (or push back) the start of the row indexed by index[j] + 1,
            // i.e. the start of the next row
            miStart[refMtx->indexes[j] + 1] ++;
        }
    }
    // at this point, miStart[ i] holds the number of columns with a nonzero in row i - 1
    // if we knew the correct starting point of row i -1, the correct starting point
    // for row i is miStart[i] + miStart [i - 1]
    miStart[0] = 0;
    for (i = 1; i < iStartSize; i++ )
    {
        miStart[i] += miStart [i - 1] ;
    }

    // now get the correct values
    // again assume we are converting column major to row major
    // loop over columns
    // this is a bit tedious, since different types of elements need to be treated differently
    if ( refMtx->vType == ENUM_MATRIX_TYPE_constant)
    {
        matrix->values = new ConstantMatrixValues();
        ((ConstantMatrixValues*)matrix->values)->el = new double[refMtx->valueSize];

        for (i = 0; i < iNumSource; i++)
        {
            // get row indices and values of the matrix
            for (j = refMtx->starts[i]; j < refMtx->starts[ i + 1 ]; j++)
            {
                iTemp = miStart[refMtx->indexes[j]];
                miIndex [ iTemp] = i;
                ((ConstantMatrixValues*)matrix->values)->el[ iTemp] 
                    = ((ConstantMatrixValues*)refMtx->values)->el[j];
                miStart[refMtx->indexes[j]] ++;
            }
        }
    }
    else if (refMtx->vType == ENUM_MATRIX_TYPE_varref)
    {
        matrix->values = new VarReferenceMatrixValues();
        ((VarReferenceMatrixValues*)matrix->values)->el = new int[refMtx->valueSize];

        for (i = 0; i < iNumSource; i++)
        {
            // get row indices and values of the matrix
            for (j = refMtx->starts[i]; j < refMtx->starts[ i + 1 ]; j++)
            {
                iTemp = miStart[refMtx->indexes[j]];
                miIndex [ iTemp] = i;
                ((VarReferenceMatrixValues*)matrix->values)->el[ iTemp] 
                    = ((VarReferenceMatrixValues*)refMtx->values)->el[j];
                miStart[refMtx->indexes[j]] ++;
            }
        }
    }
    else if (refMtx->vType == ENUM_MATRIX_TYPE_linear)
    {
        matrix->values = new LinearMatrixValues();
        ((LinearMatrixValues*)matrix->values)->el = new LinearMatrixElement*[refMtx->valueSize];
        for (i = 0; i < refMtx->valueSize; i++)
            ((LinearMatrixValues*)matrix->values)->el[i] = new LinearMatrixElement();

        for (i = 0; i < iNumSource; i++)
        {
            // get row indices and values of the matrix
            for (j = refMtx->starts[i]; j < refMtx->starts[ i + 1 ]; j++)
            {
                iTemp = miStart[refMtx->indexes[j]];
                miIndex [ iTemp] = i;
                if (!((LinearMatrixValues*)matrix->values)->el[ iTemp]->deepCopyFrom(((LinearMatrixValues*)refMtx->values)->el[j]))
                    return NULL;
                miStart[refMtx->indexes[j]] ++;
            }
        }
    }
    else if (refMtx->vType == ENUM_MATRIX_TYPE_general)
    {
        matrix->values = new GeneralMatrixValues();
        ((GeneralMatrixValues*)matrix->values)->el = new ScalarExpressionTree*[refMtx->valueSize];
        for (i = 0; i < refMtx->valueSize; i++)
        {
            ((GeneralMatrixValues*)matrix->values)->el[i] = new ScalarExpressionTree();
//            ((GeneralMatrixValues*)matrix->values)->el[i]->m_treeRoot = new OSnLNode();
        }
        for (i = 0; i < iNumSource; i++)
        {
            // get row indices and values of the matrix
            for (j = refMtx->starts[i]; j < refMtx->starts[ i + 1 ]; j++)
            {
                iTemp = miStart[refMtx->indexes[j]];
                miIndex [ iTemp] = i;
                ((GeneralMatrixValues*)matrix->values)->el[ iTemp]->m_treeRoot
                    = ((GeneralMatrixValues*)refMtx->values)->el[j]->m_treeRoot->copyNodeAndDescendants();
                miStart[refMtx->indexes[j]] ++;
            }
        }
    }
    else if (refMtx->vType == ENUM_MATRIX_TYPE_objref)
    {
        matrix->values = new ObjReferenceMatrixValues();
        ((ObjReferenceMatrixValues*)matrix->values)->el = new int[refMtx->valueSize];

        for (i = 0; i < iNumSource; i++)
        {
            // get row indices and values of the matrix
            for (j = refMtx->starts[i]; j < refMtx->starts[ i + 1 ]; j++)
            {
                iTemp = miStart[refMtx->indexes[j]];
                miIndex [ iTemp] = i;
                ((ObjReferenceMatrixValues*)matrix->values)->el[ iTemp] 
                    = ((ObjReferenceMatrixValues*)refMtx->values)->el[j];
                miStart[refMtx->indexes[j]] ++;
            }
        }
    }
    else if (refMtx->vType == ENUM_MATRIX_TYPE_conref)
    {
        matrix->values = new ConReferenceMatrixValues();
        ((ConReferenceMatrixValues*)matrix->values)->el 
            = new ConReferenceMatrixElement*[refMtx->valueSize];
        for (i = 0; i < refMtx->valueSize; i++)
            ((ConReferenceMatrixValues*)matrix->values)->el[i] = new ConReferenceMatrixElement();

        for (i = 0; i < iNumSource; i++)
        {
            // get row indices and values of the matrix
            for (j = refMtx->starts[i]; j < refMtx->starts[ i + 1 ]; j++)
            {
                iTemp = miStart[refMtx->indexes[j]];
                miIndex [ iTemp] = i;
                if (!((ConReferenceMatrixValues*)matrix->values)->el[ iTemp]->deepCopyFrom(((ConReferenceMatrixValues*)refMtx->values)->el[j]))
                    return NULL;
                miStart[refMtx->indexes[j]] ++;
            }
        }
    }

    // miStart[ i] is now equal to miStart[ i + 1], so readjust
    for (i = iStartSize - 1; i >= 1; i-- )
    {
        miStart[i] = miStart [i - 1] ;
    }

    miStart[0] = 0;
    return matrix;
}//end of MatrixType::convertToOtherMajor

int MatrixType::getRowPartitionSize()
{
    if (!m_bHaveRowPartition) 
    {
        bool OK = processBlockPartition();
        if (!OK) throw ErrorClass("Error processing blocks");
    }
    return m_iRowPartitionSize;
}// end of MatrixType::getRowPartitionSize()

int* MatrixType::getRowPartition()
{
    if (!m_bHaveRowPartition) 
    {
        bool OK = processBlockPartition();
        if (!OK) throw ErrorClass("Error processing blocks");
    }
    return m_miRowPartition;
}// end of MatrixType::getRowPartition()

int MatrixType::getColumnPartitionSize()
{
    if (!m_bHaveColumnPartition) 
    {
        bool OK = processBlockPartition();
        if (!OK) throw ErrorClass("Error processing blocks");
    }
    return m_iColumnPartitionSize;
}// end of MatrixType::getColumnPartitionSize()

int* MatrixType::getColumnPartition()
{
    if (!m_bHaveColumnPartition) 
    {
        bool OK = processBlockPartition();
        if (!OK) throw ErrorClass("Error processing blocks");
    }
    return m_miColumnPartition;
}// end of MatrixType::getColumnPartition()


bool MatrixType::processBlockPartition()
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, "Inside processBlockPartition()");
#endif
    if (matrixHasBlocks())
    {
        int nPartitions = 0;
        int imerge_R;
        int imerge_C;

        for (int i=0; i < inumberOfChildren; i++)
        {
            if (m_mChildren[i]->nType == ENUM_MATRIX_CONSTRUCTOR_TYPE_blocks)
            {
                if (nPartitions == 0)
                {
                    // first blocks constructor. Set up data structures
                    nPartitions++;
                    m_iRowPartitionSize = ((MatrixBlocks*)m_mChildren[i])->rowOffsets->numberOfEl;
                    m_miRowPartition = new int[m_iRowPartitionSize];
                    for (int j=0; j<m_iRowPartitionSize; j++)
                        m_miRowPartition[j] = ((MatrixBlocks*)m_mChildren[i])->rowOffsets->el[j];
                    m_iColumnPartitionSize = ((MatrixBlocks*)m_mChildren[i])->colOffsets->numberOfEl;
                    m_miColumnPartition = new int[m_iColumnPartitionSize];
                    for (int j=0; j<m_iColumnPartitionSize; j++)
                        m_miColumnPartition[j] = ((MatrixBlocks*)m_mChildren[i])->colOffsets->el[j];
                }
                else
                {
                    //another block constructor. merge row partitions
                    nPartitions++;
                    int i0 = 0;
                    int itemp = 0;
                    imerge_R = 0;
                    for (;;)
                    {
                        if (m_miRowPartition[i0] == ((MatrixBlocks*)m_mChildren[i])->rowOffsets->el[itemp])
                        {
                            if (imerge_R != i0) m_miRowPartition[imerge_R] = m_miRowPartition[i0];
                            i0++;
                            itemp++;
                            imerge_R++;
                        }
                        else
                        {
                            if (m_miRowPartition[i0] < 
                                    ((MatrixBlocks*)m_mChildren[i])->rowOffsets->el[itemp])
                                i0++;
                            else
                                itemp++;
                        }
                        if (i0 >= m_iRowPartitionSize || 
                                itemp >= ((MatrixBlocks*)m_mChildren[i])->rowOffsets->numberOfEl)
                            break;
                    }
                    m_iRowPartitionSize = imerge_R;

                    // merge column partitions
                    i0 = 0;
                    itemp = 0;
                    imerge_C = 0;
                    for (;;)
                    {
                        if (m_miColumnPartition[i0] == 
                                ((MatrixBlocks*)m_mChildren[i])->colOffsets->el[itemp])
                        {
                            if (imerge_C != i0) m_miColumnPartition[imerge_C] = m_miColumnPartition[i0];
                            i0++;
                            itemp++;
                            imerge_C++;
                        }
                        else
                        {
                            if (m_miColumnPartition[i0] < 
                                    ((MatrixBlocks*)m_mChildren[i])->colOffsets->el[itemp])
                                i0++;
                            else
                                itemp++;
                        }
                        if (i0 >= m_iColumnPartitionSize || 
                                itemp >= ((MatrixBlocks*)m_mChildren[i])->colOffsets->numberOfEl)
                            break;
                    }
                    m_iColumnPartitionSize = imerge_C;
                }
            }
        }
        if (nPartitions > 1)
        {
            int* tempPartition = new int[imerge_R];
            for (int i=0; i < imerge_R; i++)
                tempPartition[i] = m_miRowPartition[i];
            delete [] m_miRowPartition;
            m_miRowPartition = tempPartition;

            tempPartition = new int[imerge_C];
            for (int i=0; i < imerge_C; i++)
                tempPartition[i] = m_miColumnPartition[i];
            delete [] m_miColumnPartition;
            m_miColumnPartition = tempPartition;
        }
    }
    else
    {
        m_iRowPartitionSize = 2;
        m_miRowPartition = new int[2];
        m_miRowPartition[0] = 0;
        m_miRowPartition[1] = numberOfRows;
        m_iColumnPartitionSize = 2;
        m_miColumnPartition = new int[2];
        m_miColumnPartition[0] = 0;
        m_miColumnPartition[1] = numberOfColumns;
    }
    m_bHaveRowPartition = true;
    m_bHaveColumnPartition = true;
    return true;
}// end of processBlockPartition

GeneralSparseMatrix* MatrixType::getMatrixBlockInColumnMajorForm(int columnIdx, int rowIdx)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, "Inside getMatrixBlockInColumnMajorForm()");
#endif
    return NULL;
}// end of MatrixType::getMatrixBlockInColumnMajorForm

ExpandedMatrixBlocks* MatrixType::getBlocks(int* rowPartition, int rowPartitionSize, 
                                            int* colPartition, int colPartitionSize, 
                                            bool rowMajor, bool appendToBlockArray)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, "Inside getBlocks()");
#endif

    // Try to find a collection of blocks that matches the criteria 
    for (int kount = 0; kount < ExpandedMatrixByBlocks.size(); kount++)
    {
        if (rowPartitionSize != ExpandedMatrixByBlocks[kount]->rowOffsetSize ||       
            colPartitionSize != ExpandedMatrixByBlocks[kount]->colOffsetSize ||
            rowMajor         != ExpandedMatrixByBlocks[kount]->isRowMajor)
            continue;
        
        for (int i=0; i < rowPartitionSize; i++)
            if (rowPartition[i] != ExpandedMatrixByBlocks[kount]->rowOffsets[i])
                continue;
        for (int i=0; i < colPartitionSize; i++)
            if (colPartition[i] != ExpandedMatrixByBlocks[kount]->colOffsets[i])
                continue;

        return ExpandedMatrixByBlocks[kount];
    }

    // not found; create a new collection
    if (!appendToBlockArray) return NULL;

    if (!processBlocks(rowPartition, rowPartitionSize,
                       colPartition, colPartitionSize, false, symmetry))
       return false;
    return ExpandedMatrixByBlocks.back();
}// end of MatrixType::getBlocks

bool MatrixType::processBlocks(bool rowMajor, ENUM_MATRIX_SYMMETRY symmetry)
{
    int  cSize = getColumnPartitionSize(); 
    int  rSize = getRowPartitionSize();
    int* cPartition = getColumnPartition(); 
    int* rPartition = getRowPartition(); 
    return processBlocks(rPartition, rSize, cPartition, cSize, rowMajor, symmetry);
}// end of MatrixType::processBlocks

bool MatrixType::processBlocks(int* rowOffsets, int rowOffsetSize, int* colOffsets,
                               int colOffsetSize, bool rowMajor, ENUM_MATRIX_SYMMETRY symmetry)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, "Inside processBlocks()");
#endif
    try
    {
        ENUM_MATRIX_TYPE elType = getMatrixType();

        // check for blocks constructor with matching partition
        if (inumberOfChildren == 1)
        {
            if (m_mChildren[0]->nType == ENUM_MATRIX_CONSTRUCTOR_TYPE_blocks)
            {
                if (((MatrixBlocks*)m_mChildren[0])->rowOffsets->numberOfEl != rowOffsetSize ||
                    ((MatrixBlocks*)m_mChildren[0])->colOffsets->numberOfEl != colOffsetSize)
                    goto none_found;

                for (int j=0; j < rowOffsetSize; j++)
                    if (((MatrixBlocks*)m_mChildren[0])->rowOffsets->el[j] != rowOffsets[j])
                        goto none_found;

                for (int j=0; j < colOffsetSize; j++)
                    if (((MatrixBlocks*)m_mChildren[0])->colOffsets->el[j] != colOffsets[j])
                        goto none_found;

                // Here we have matching block partitions
                ExpandedMatrixBlocks* tmpBlocks = new ExpandedMatrixBlocks();

                tmpBlocks->bDeleteArrays = false;
                tmpBlocks->vType = elType;
                tmpBlocks->isRowMajor = rowMajor;
                tmpBlocks->rowOffsetSize = rowOffsetSize;
                tmpBlocks->colOffsetSize = colOffsetSize;
                tmpBlocks->rowOffsets = rowOffsets;
                tmpBlocks->colOffsets = colOffsets;

                // access each block; expand and convert if necessary, count (and suppress if empty)
                MatrixBlock* tmpChild;
                int tmpBlockNumber = 0;
                int tmpBlockSize;
                for (int j=0; j<((MatrixBlocks*)m_mChildren[0])->numberOfBlocks; j++)
                {
                    tmpChild = (MatrixBlock*)((MatrixBlocks*)m_mChildren[0])->m_mChildren[j];
                    if (rowMajor)
                    {
                        tmpChild->getMatrixCoefficientsInRowMajor();
                        if (tmpChild->ExpandedMatrixInRowMajorForm->valueSize > 0)
                            tmpBlockNumber++;
                    }
                    else
                    {
                        tmpChild->getMatrixCoefficientsInColumnMajor();
                        if (tmpChild->ExpandedMatrixInColumnMajorForm->valueSize > 0)
                            tmpBlockNumber++;
                    }
                }

                // We know the number of blocks; allocate memory
                tmpBlocks->blockNumber = tmpBlockNumber;
                tmpBlocks->blocks = new GeneralSparseMatrix*[tmpBlockNumber];
                tmpBlocks->blockRows = new int[tmpBlockNumber];
                tmpBlocks->blockColumns = new int[tmpBlockNumber];

                // go through blocks again and store pointers
                tmpBlockNumber = 0;
                for (int j=0; j<((MatrixBlocks*)m_mChildren[0])->numberOfBlocks; j++)
                {
                    tmpChild = (MatrixBlock*)((MatrixBlocks*)m_mChildren[0])->m_mChildren[j];
                    if (rowMajor)
                    {
                        if (tmpChild->ExpandedMatrixInRowMajorForm->valueSize == 0)
                            continue;
                        tmpBlocks->blocks[tmpBlockNumber] = tmpChild->ExpandedMatrixInRowMajorForm;
                    }
                    else
                    {
                        if (tmpChild->ExpandedMatrixInColumnMajorForm->valueSize == 0)
                            continue;
                        tmpBlocks->blocks[tmpBlockNumber] = tmpChild->ExpandedMatrixInColumnMajorForm;
                    }
                    tmpBlocks->blockRows[tmpBlockNumber]    = tmpChild->blockRowIdx;
                    tmpBlocks->blockColumns[tmpBlockNumber] = tmpChild->blockColIdx;

tmpChild->printExpandedMatrix(rowMajor);

                    tmpBlockNumber++;
                }
                ExpandedMatrixByBlocks.push_back(tmpBlocks);
                return true;
            }
        }

none_found:
        if (inumberOfChildren == 0)
        {
            // empty matrix -- return empty collection
            ExpandedMatrixBlocks* tmpBlocks = new ExpandedMatrixBlocks();

            tmpBlocks->bDeleteArrays = false;
            tmpBlocks->vType = elType;
            tmpBlocks->isRowMajor = rowMajor;
            tmpBlocks->rowOffsetSize = rowOffsetSize;
            tmpBlocks->colOffsetSize = colOffsetSize;
            tmpBlocks->rowOffsets = rowOffsets;
            tmpBlocks->colOffsets = colOffsets;
            tmpBlocks->blockNumber = 0;
            tmpBlocks->blocks = NULL;
            tmpBlocks->blockRows = NULL;
            tmpBlocks->blockColumns = NULL;
            ExpandedMatrixByBlocks.push_back(tmpBlocks);
            return true;
        }

        // unless there is a block partition already, separate the expanded matrix into blocks 
        if ( (ExpandedMatrixInColumnMajorForm != NULL && !rowMajor) ||
             (ExpandedMatrixInRowMajorForm    != NULL &&  rowMajor) ||
              ExpandedMatrixByBlocks.size() == 0)
        {
            ExpandedMatrixByBlocks.push_back(disassembleMatrix(rowOffsets, rowOffsetSize, colOffsets,
                                                               colOffsetSize, rowMajor, symmetry));
            return true;
        }

        // If a different block partition is available, it is less wasteful to disassemble it
        // rather than making a full expansion first
        // Refinements and coarser partitions are easier to handle, so check for those first

        int refinement = -1;
        int coarsening = -1;
        bool refinementCandidate;
        bool coarseningCandidate;
        int k = 0;

        for (int k = 0; k < ExpandedMatrixByBlocks.size(); k++)
        {
            refinementCandidate = true;
            int itarget = 0;
            int itest = 0;
            for (;;)
            {
                if (rowOffsets[itarget] == ExpandedMatrixByBlocks[k]->rowOffsets[itest])
                {
                    itest++;
                    itarget++;
                }
                else
                {
                    if (rowOffsets[itarget] < ExpandedMatrixByBlocks[k]->rowOffsets[itest])
                    {
                        itarget++;
                    }
                    else
                    {
                        refinementCandidate = false;
                        continue;
                    }
                }
                if (itarget >= rowOffsetSize || itest >= ExpandedMatrixByBlocks[k]->rowOffsetSize)
                    break;
            }

            if (refinementCandidate)
            {
                itarget = 0;
                itest = 0;
                for (;;)
                {
                    if (colOffsets[itarget] == ExpandedMatrixByBlocks[k]->colOffsets[itest])
                    {
                        itest++;
                        itarget++;
                    }
                    else
                    {
                        if (colOffsets[itarget] < ExpandedMatrixByBlocks[k]->colOffsets[itest])
                        {
                            itarget++;
                        }
                        else
                        {
                            refinementCandidate = false;
                            continue;
                        }
                    }
                    if (itarget >= colOffsetSize || itest >= ExpandedMatrixByBlocks[k]->colOffsetSize)
                        break;
                }
            }

            if (refinementCandidate)
            {
                refinement = k;
                break;
            }

            coarseningCandidate = false;
            itarget = 0;
            itest = 0;
            for (;;)
            {
                if (rowOffsets[itarget] == ExpandedMatrixByBlocks[k]->rowOffsets[itest])
                {
                    itest++;
                    itarget++;
                }
                else
                {
                    if (rowOffsets[itarget] < ExpandedMatrixByBlocks[k]->rowOffsets[itest])
                    {
                        itarget++;
                        continue;
                    }
                    else
                    {
                        coarseningCandidate = true;
                        itest++;
                    }
                }
                if (itarget >= rowOffsetSize || itest >= ExpandedMatrixByBlocks[k]->rowOffsetSize)
                    break;
            }

            itarget = 0;
            itest = 0;
            for (;;)
            {
                if (colOffsets[itarget] == ExpandedMatrixByBlocks[k]->colOffsets[itest])
                {
                    itest++;
                    itarget++;
                }
                else
                {
                    if (colOffsets[itarget] < ExpandedMatrixByBlocks[k]->colOffsets[itest])
                    {
                        itarget++;
                        continue;
                    }
                    else
                    {
                        coarseningCandidate = true;
                        itest++;
                    }
                }
                if (itarget >= colOffsetSize || itest >= ExpandedMatrixByBlocks[k]->colOffsetSize)
                    break;
            }

            if (coarseningCandidate)
            {
                refinement = k;
            }
        }

        if (refinement >= 0)
        {
            throw ErrorClass ("Not yet implemented: obtaining one block partition from a different one");
            return false;
        }

        if (coarsening >= 0)
        {
            throw ErrorClass ("Not yet implemented: obtaining one block partition from a different one");
            return false;
        }

        // here we have previous partitions that all overlap with the current one
        throw ErrorClass ("Not yet implemented: obtaining one block partition from a different one");


        return false;
    }
    catch(const ErrorClass& eclass)
    {
        throw ErrorClass( eclass.errormsg);
    }
}// end of alternate MatrixType::processBlocks

ExpandedMatrixBlocks* MatrixType::disassembleMatrix(int* rowPartition, int rowPartitionSize, 
                                                    int* colPartition, int colPartitionSize, 
                                                    bool rowMajor, ENUM_MATRIX_SYMMETRY symmetry)
{ 
/*
     We go through the nonzeros of the matrix to determine both the number of nonzero blocks
     and the number of elements in each block. 
     We do not know how many blocks there are, so we have to store them temporarily in a vector. 
     As each block is detected, we extend the vector.
     This keeps the blocks ordered by colIdx (assuming column major) and probably also 
     by rowIdx within each column (assuming "normal" ordering of nonzeros). 
     (This affects only the efficiency of the search routines, not the validity of the algorithm.)
     After the counts have been established, we have to go through the nonzeros again to store values.
     Finally we convert the vector to an array and return.
 */
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, "Inside disassembleMatrix()");
#endif
    int currBlockRow, currBlockCol, lastBlock, currRow;
    int blockCount, firstBlockInCol, blockTotal;
    std::vector<GeneralSparseMatrix*> tmpBlocks;
    int* tmpBlockRows; 
    int* tmpBlockColumns;
    bool found;
    int  i, j, k;
    int* elCount;
    ENUM_MATRIX_TYPE vType = getMatrixType();

    //This section is for column-wise representations --- row-wise will work analogously
    if (!rowMajor)
    {
        firstBlockInCol = -1;
        if (ExpandedMatrixInColumnMajorForm == NULL)
            getMatrixCoefficientsInColumnMajor();

        // OK. Start counting
        blockCount = 0;
        elCount = new int[rowPartitionSize-1];

        for (i=0; i < colPartitionSize-1; i++) // i indexes a block of columns
        {
//            blk0 = blockCount;
            for (j=0; j<rowPartitionSize-1; j++) 
                elCount[j] = 0;
            lastBlock = i;
            if (lastBlock >= rowPartitionSize)
                lastBlock  = rowPartitionSize - 1;

            for (j=colPartition[i]; j<colPartition[i+1]; j++) // j indexes a column within this block
            {
                for ( k = ExpandedMatrixInColumnMajorForm->starts[j]; 
                      k < ExpandedMatrixInColumnMajorForm->starts[j+1]; 
                      k++ )                                 // k indexes the elements in this column
                {
                    currRow = ExpandedMatrixInColumnMajorForm->indexes[k];
                    if (currRow < rowPartition[lastBlock] || currRow >= rowPartition[lastBlock+1])
                    {
                        found = false;
                        int n = lastBlock + 1;
                        while (!found && n < rowPartitionSize - 1)
                        {
//                            for (k=lastBlock+1; k < rowPartitionSize - 1; k++)
                            if (currRow >= rowPartition[n+1])
                                n++;
                            else
                            {
                                found = true;
                                lastBlock = n;
                                break;
                            }
                        }
                        if (!found)
                            n = lastBlock - 1;
                        while (!found && n >= 0)
                        {
//                            for (k=lastBlock-1; k >= 0; k--)
                            if (currRow < rowPartition[n])
                                n--;
                            else
                            {
                                found = true;
                                lastBlock = n;
                                break;
                            }
                        }
                        if (!found)
                            throw ErrorClass("Invalid row information detected in disassembleMatrix()");

                        elCount[lastBlock]++;
                        if (elCount[lastBlock] == 1)
                        {
                            //add a new block
                            GeneralSparseMatrix* tmpBlock = new GeneralSparseMatrix();
                            blockCount++;
                            if (firstBlockInCol < 0) 
                                firstBlockInCol = blockCount - 1;
                            tmpBlock->b_deleteStartArray = true;
                            tmpBlock->b_deleteIndexArray = true;
                            tmpBlock->b_deleteValueArray = true;
                            tmpBlock->isRowMajor = false;
                            tmpBlock->symmetry = symmetry;
                            tmpBlock->vType = vType;
                            tmpBlock->startSize = colPartition[i+1] - colPartition[i] + 1;
                            tmpBlock->starts = new int[tmpBlock->startSize];
    
                            for (int n=0; n <= j - colPartition[i]; n++)
                                tmpBlock->starts[n] = 0;

                            tmpBlocks.push_back(tmpBlock);
                            if (firstBlockInCol < 0) 
                                firstBlockInCol = blockCount - 1;
                        }
                    } // end of element
                } // end of column

                //store starts
                for (k=firstBlockInCol; k < blockCount; k++)
                    tmpBlocks[k]->starts[j-colPartition[i] + 1] = elCount[k];

            } // end of block of columns

            // allocate space for indexes, values and block location 
            for (k=firstBlockInCol; k < blockCount; k++)
            {
                tmpBlocks[k]->valueSize = elCount[k];
                tmpBlocks[k]->indexes = new int[elCount[k]];
                tmpBlocks[k]->values  = new MatrixElementValues[elCount[k]];
            }
            tmpBlockRows    = new int[blockCount]; 
            tmpBlockColumns = new int[blockCount];
            for (j=0; j<blockCount; j++)
            {
                tmpBlockRows[j]    = -1;
            } 
            
            lastBlock = i;            
//            blockCount = 

            // traverse a second time to get values
            for (j=colPartition[i]; j<colPartition[i+1]; j++) // j indexes a column within this block
            {
                for ( k = ExpandedMatrixInColumnMajorForm->starts[j]; 
                      k < ExpandedMatrixInColumnMajorForm->starts[j+1]; 
                      k++ )                                   // k indexes the elements in this column
                {
                    currRow = ExpandedMatrixInColumnMajorForm->indexes[k];
                    if (currRow < rowPartition[lastBlock] || currRow >= rowPartition[lastBlock+1])
                    {
                        found = false;
                        int n;
                        while (!found)
                        {
                            for (n=lastBlock+1; n < rowPartitionSize - 1; n++)
                                if (currRow >= rowPartition[lastBlock] && 
                                    currRow <  rowPartition[lastBlock+1])
                                {
                                    found = true;
                                    lastBlock = n;
                                    break;
                                }
                        }
                        while (!found)
                        {
                            for (n=lastBlock-1; k >= 0; k--)
                                if (currRow >= rowPartition[lastBlock] && 
                                    currRow <  rowPartition[lastBlock+1])
                                {
                                    found = true;
                                    lastBlock = n;
                                    break;
                                }
                        }
                    }
                    if (tmpBlockRows[lastBlock] == -1)
                    {
                        tmpBlockRows[lastBlock] = j;
                        tmpBlockColumns[lastBlock] = i;
                    }
                }
 
                int k0 = 0;
                tmpBlocks[lastBlock]->indexes[k-k0] 
                    = ExpandedMatrixInColumnMajorForm->indexes[k] - rowPartition[j];
                tmpBlocks[lastBlock]->values [k-k0]  = ExpandedMatrixInColumnMajorForm->values[k];
            }
        } // end of entire collection

    } // end of column major 
    else
        throw ErrorClass("Row major not yet implemented in MatrixType::disassembleMatrix()");

    ExpandedMatrixBlocks* returnArray = new ExpandedMatrixBlocks();
    returnArray->bDeleteArrays = true;
    returnArray->vType = vType;
    returnArray->isRowMajor = rowMajor;
    returnArray->blockNumber = tmpBlocks.size();
    returnArray->rowOffsets = rowPartition;
    returnArray->colOffsets = colPartition;
    returnArray->rowOffsetSize = rowPartitionSize;
    returnArray->colOffsetSize = colPartitionSize;
    returnArray->blocks = new GeneralSparseMatrix*[tmpBlocks.size()];

    for (int i=0; i<tmpBlocks.size();i++);
    {
        returnArray->blocks[i] = tmpBlocks[i];
        returnArray->blockRows[i] = tmpBlockRows[i];
        returnArray->blockColumns[i] = tmpBlockColumns[i];    
    }

    return returnArray;
}//end of MatrixType::disassembleMatrix


GeneralSparseMatrix* MatrixType::extractBlock(int firstrow, int firstcol, int nrows, int ncols,
                                              bool rowMajor, ENUM_MATRIX_SYMMETRY symmetry)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, "Inside extractBlock()");
#endif
    bool mustCopy = false;
    int n = inumberOfChildren;
    if (n > 1)
        mustCopy = true;
    else
    {

    }
    for (int i=0; i < n; i++)
        if (m_mChildren[i]->nType != ENUM_MATRIX_CONSTRUCTOR_TYPE_blocks)
        {
            
            break;
        }
        else
        {
//            for (int j=0; j < 
        }

return NULL;
}// end of MatrixType::extractBlock
// end of methods for MatrixType


/** ---------- Methods for class MatrixElements ---------- */ 
MatrixElements::MatrixElements():
    rowMajor(false),
    numberOfValues(-1),
    start(NULL),
    indexes(NULL)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, "Inside the MatrixElements Constructor");
#endif
}// end of MatrixElements::MatrixElements()

MatrixElements::~MatrixElements()
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, "Inside the MatrixElements Destructor");
#endif
    if (start != NULL)
        delete start;
    start = NULL;

    if (indexes != NULL)
        delete indexes;
    indexes = NULL;
}// end of MatrixElements::~MatrixElements()

bool MatrixElements::getRowMajor()
{
    return rowMajor;
}// end of MatrixElements::getRowMajor

#if 0
bool MatrixElements::alignsOnBlockBoundary(int firstRow, int firstColumn, int nRows, int nCols)
{
    return false;
}// end of MatrixElements::alignsOnBlockBoundary()

std::string MatrixElements::getNodeName()
{
    return "";
}// end of MatrixElements::getNodeName()
#endif

bool MatrixElements::IsEqual(MatrixElements *that)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSMatrix, ENUM_OUTPUT_LEVEL_trace, "Start comparing in MatrixElements");
#endif
    if (this == NULL)
    {
        if (that == NULL)
            return true;
        else
        {
#ifndef NDEBUG
            osoutput->OSPrint(ENUM_OUTPUT_AREA_OSMatrix, ENUM_OUTPUT_LEVEL_trace, 
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
            osoutput->OSPrint(ENUM_OUTPUT_AREA_OSMatrix, ENUM_OUTPUT_LEVEL_trace, 
                "Second object is NULL, first is not");
#endif
            return false;
        }
        else
        {
            if (this->rowMajor != that->rowMajor) return false;
            if (this->numberOfValues != that->numberOfValues) return false;

            if (!this->start->IsEqual(that->start))
                return false;

            if (!this->indexes->IsEqual(that->indexes))
                return false;

            return true;
        }
    }
}// end of MatrixElements::IsEqual()
// end of methods for MatrixElements


/** ---------- Methods for class MatrixElementValues ---------- */ 
MatrixElementValues::MatrixElementValues():
    numberOfEl(0)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, "Inside the  MatrixElementValues Constructor");
#endif
}

MatrixElementValues::~MatrixElementValues()
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, "Inside the MatrixElementValues Destructor");
#endif
}//end of MatrixElementValues::~MatrixElementValues

bool MatrixElementValues::deepCopyFrom(MatrixElementValues* that)
{
    return true;
}// end of MatrixElementValues::deepCopyFrom

// end of methods for MatrixElementValues


/** ---------- Methods for class OSMatrix ---------- */ 
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


ENUM_MATRIX_CONSTRUCTOR_TYPE OSMatrix::getNodeType()
{
    return ENUM_MATRIX_CONSTRUCTOR_TYPE_matrix;
}// end of OSMatrix::getNodeType()

std::string OSMatrix::getNodeName()
{
    return "matrix";
}// end of OSMatrix::getNodeName()

ENUM_MATRIX_TYPE OSMatrix::getMatrixType()
{
    if (matrixType == ENUM_MATRIX_TYPE_unknown)
    {
        matrixType =  ENUM_MATRIX_TYPE_zero;
        for (int i=0; i<inumberOfChildren; i++)
            matrixType = mergeMatrixType(matrixType, m_mChildren[i]->getMatrixType());
    }
    return matrixType;
}// end of OSMatrix::getMatrixType()

bool OSMatrix::expandElements(bool rowMajor)
{
#if 0
    //Check if expanded previously
    if (rowMajor)
    {
        if (ExpandedMatrixInRowMajorForm != NULL) return true;
    }
    else
    {
        if (ExpandedMatrixInColumnMajorForm != NULL) return true;
    }

    // The complexity increases with the number of constructors
    // Start by checking for empty matrix
    if (inumberOfChildren == 0)
    {
        if (rowMajor)
        {
            ExpandedMatrixInRowMajorForm = new GeneralSparseMatrix();
            ExpandedMatrixInRowMajorForm->symmetry = symmetry;
            ExpandedMatrixInRowMajorForm->valueSize = 0;
            ExpandedMatrixInRowMajorForm->startSize = numberOfRows + 1;
            ExpandedMatrixInRowMajorForm->starts = new int[numberOfRows + 1];
            for (int i=0; i <= numberOfRows; i++)
                ExpandedMatrixInRowMajorForm->starts[i] = 0;
            return true;
        }
        else
        {
            ExpandedMatrixInColumnMajorForm = new GeneralSparseMatrix();
            ExpandedMatrixInColumnMajorForm->symmetry = symmetry;
            ExpandedMatrixInColumnMajorForm->valueSize = 0;
            ExpandedMatrixInColumnMajorForm->startSize = numberOfColumns + 1;
            ExpandedMatrixInColumnMajorForm->starts = new int[numberOfColumns + 1];
            for (int i=0; i <= numberOfColumns; i++)
                ExpandedMatrixInColumnMajorForm->starts[i] = 0;
            return true;
        }
    }

    else if (inumberOfChildren == 1)
    {
        if (m_mChildren[0]->getNodeType() == ENUM_MATRIX_CONSTRUCTOR_TYPE_baseMatrix)
        {
            int  baseMtxIdx = ((BaseMatrix*)m_mChildren[0])->baseMatrixIdx;
            OSMatrix* basematrix = 
            bool haveRowForm    = (baseMtx->ExpandedMatrixInRowMajorForm != NULL);
            bool haveColumnForm = (baseMtx->ExpandedMatrixInColumnMajorForm != NULL);
// what about cropping, scaling, transpose???
            m_mChildren[0]->expandElements(rowMajor);
            if (targetMatrixFirstRow == 0 && targetMatrixFirstCol == 0 && 
                baseMatrixStartRow   == 0 && baseMatrixStartCol   == 0 &&
                baseMatrixEndRow == numberOfRows    - 1 &&
                baseMatrixEndCol == numberOfColumns - 1 &&
                scalarMultiplier == 1)
            {
                if (rowmajor)
                {
                    ExpandedMatrixInRowMajorForm = new GeneralSparseMatrix();
                    ExpandedMatrixInRowMajorForm = m_mChildren[0]->ExpandedMatrixInRowMajorForm;
                    ExpandedMatrixInRowMajorForm->symmetry = symmetry;
                    ExpandedMatrixInRowMajorForm->startSize = numberOfRows + 1;
                    ExpandedMatrixInRowMajorForm->starts = new int[numberOfRows + 1];
                }
                else
                {
                    ExpandedMatrixInColumnMajorForm = new GeneralSparseMatrix();
                    ExpandedMatrixInColumnMajorForm = m_mChildren[0]->ExpandedMatrixInColumnMajorForm;
                    ExpandedMatrixInColumnMajorForm->symmetry = symmetry;
                    ExpandedMatrixInColumnMajorForm->startSize = numberOfColumns + 1;
                    ExpandedMatrixInColumnMajorForm->starts = new int[numberOfColumns + 1];
                }
            }
            return true;
        }

        else if (m_mChildren[0]->getNodeType() == ENUM_MATRIX_CONSTRUCTOR_TYPE_blocks)
        {
            ExpandedMatrixBlocks* currentBlocks = 
                processBlocks(int* rowOffsets, int* colOffsets,
                              bool rowMajor, ENUM_MATRIX_SYMMETRY symmetry);
            ExpandedMatrixByBlocks.push_back(currentBlocks);

            if (rowmajor)
            {
                ExpandedMatrixInRowMajorForm = new GeneralSparseMatrix*();
                ExpandedMatrixInRowMajorForm->startSize = numberOfRows + 1;
                ExpandedMatrixInRowMajorForm->starts = new int[numberOfRows + 1];
                for (int i=0; i <= numberOfRows; i++)
                    ExpandedMatrixInRowMajorForm->starts[i] = 0;
            }
            else
            {
                ExpandedMatrixInColumnMajorForm = new GeneralSparseMatrix*();
                ExpandedMatrixInColumnMajorForm->startSize = numberOfColumns + 1;
                ExpandedMatrixInColumnMajorForm->starts = new int[numberOfColumns + 1];
                for (int i=0; i <= numberOfColumns; i++)
                    ExpandedMatrixInColumnMajorForm->starts[i] = 0;
        // augment column lengths block by block
                for (int j=0; j < currentBlocks->numberOfBlocks; j++)
                {
                }
                    
            }
        }

        else if (m_mChildren[0]->getNodeType() == ENUM_MATRIX_CONSTRUCTOR_TYPE_transformation)
        {
        }
    }

    else
    {
    }
#endif
/*do induction on # of constructors.
if one: blocks: expand
        transformation: see if I can do at least AB, A'B, AB'
        elements: copy
more than one: tricky
        (basematrix plus) elements should be ok
        maybe transformation (product) plus elements
        others: throw error
*/
    return false;
}// end of expandElements

#if 0
bool OSMatrix::processBlocks(int* rowOffsets, int* colOffsets,
                                      bool rowMajor, ENUM_MATRIX_SYMMETRY symmetry)
{
    /**
     *  A method to process a matrixType into a specific block structure.
     *  @param rowOffsets defines a partition of the matrix rows into the blocks
     *  @param colOffsets defines a partition of the matrix columns into the blocks
     *  @param rowMajor controls whether the blocks are stored by row or by column
     *  @param symmetry can be used to store only the upper or lower triangle, depending
     *         on the parameter value --- see OSParameters.h for definitions
     *  @return whether the operation was successful
     *
     *  @remark The blocks are stored into a std::vector of type expandedMatrixBlocks
     *          so that they can be retrieved later using extractBlock (see below).
     *          It is possible (though probably not advisable) to maintain multiple
     *          decompositions with different row and column partitions
     */
    bool haveBlocks;
    bool haveTemp;
    bool mustSynchronize;
    int* temp;
    int  tempSize;
    int  iconst;

//check for duplicates

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
#endif

bool OSMatrix::alignsOnBlockBoundary(int firstRow, int firstColumn, int nRows, int nCols)
{
    bool accumulator = true;
    for (int i=0; i < inumberOfChildren; i++)
        if (m_mChildren[i]->nType == ENUM_MATRIX_CONSTRUCTOR_TYPE_baseMatrix)
            accumulator &= m_mChildren[i]->alignsOnBlockBoundary(firstRow, firstColumn, nRows, nCols);
        else if (m_mChildren[i]->nType == ENUM_MATRIX_CONSTRUCTOR_TYPE_blocks)
            accumulator &= m_mChildren[i]->alignsOnBlockBoundary(firstRow, firstColumn, nRows, nCols);
        else if (m_mChildren[i]->nType == ENUM_MATRIX_CONSTRUCTOR_TYPE_transformation)
            return false;
        else return false;
    return accumulator;
}// end of OSMatrix::alignsOnBlockBoundary()

#if 0
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
#endif


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

    if (inumberOfChildren > 0)
    {
        outStr << ">" << std::endl;
        for (int i=0; i < inumberOfChildren; i++)
            outStr << m_mChildren[i]->getMatrixNodeInXML();
        outStr << "</matrix>" << std::endl;
    }
    else
        outStr << "/>" << std::endl;
    return outStr.str();
}// end of OSMatrix::getMatrixNodeInXML()

OSMatrix* OSMatrix::cloneMatrixNode()
{
    MatrixType *nodePtr;
    nodePtr = new OSMatrix();
    return  (OSMatrix*)nodePtr;
}// end of OSMatrix::cloneMatrixNode

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


/** ---------- Methods for class BaseMatrix ---------- */ 
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

ENUM_MATRIX_CONSTRUCTOR_TYPE BaseMatrix::getNodeType()
{
    return ENUM_MATRIX_CONSTRUCTOR_TYPE_baseMatrix;
}// end of BaseMatrix::getNodeType()

std::string BaseMatrix::getNodeName()
{
    return "baseMatrix";
}// end of BaseMatrix::getNodeName()

ENUM_MATRIX_TYPE BaseMatrix::getMatrixType()
{
    return ((OSMatrix*)baseMatrix)->getMatrixType();
}// end of BaseMatrix::getMatrixType()

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

bool BaseMatrix::IsEqual(BaseMatrix *that)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSMatrix, ENUM_OUTPUT_LEVEL_trace, "Start comparing in BaseMatrix");
#endif
    if (this == NULL)
    {
        if (that == NULL)
            return true;
        else
        {
#ifndef NDEBUG
            osoutput->OSPrint(ENUM_OUTPUT_AREA_OSMatrix, ENUM_OUTPUT_LEVEL_trace, 
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
            osoutput->OSPrint(ENUM_OUTPUT_AREA_OSMatrix, ENUM_OUTPUT_LEVEL_trace, 
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


/** ---------- Methods for class MatrixTransformation ---------- */ 
MatrixTransformation::MatrixTransformation():
    shape(ENUM_NL_EXPR_SHAPE_general), 
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

ENUM_MATRIX_CONSTRUCTOR_TYPE MatrixTransformation::getNodeType()
{
    return ENUM_MATRIX_CONSTRUCTOR_TYPE_transformation;
}// end of MatrixTransformation::getNodeType()

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

std::string MatrixTransformation::getMatrixNodeInXML()
{
    ostringstream outStr;
    outStr <<  "<transformation";
    if (shape != ENUM_NL_EXPR_SHAPE_general)
        outStr << " shape=\"" << returnExprShapeString(shape) << "\"";
    outStr <<  ">" << std::endl;
    
    outStr <<    transformation->getNonlinearExpressionInXML() << std::endl; 

    outStr << "</transformation>" << std::endl;
    return outStr.str();
}// end of MatrixTransformation::getMatrixNodeInXML()

bool MatrixTransformation::alignsOnBlockBoundary(int firstRow, int firstColumn, int nRows, int nCols)
{
    return false;
}// end of MatrixTransformation::alignsOnBlockBoundary()

MatrixTransformation* MatrixTransformation::cloneMatrixNode()
{
    MatrixTransformation *nodePtr;
    nodePtr = new MatrixTransformation();
    return  (MatrixTransformation*)nodePtr;
}// end of MatrixTransformation::cloneMatrixNode

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


/** ---------- Methods for class ConstantMatrixElements ---------- */ 
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

ENUM_MATRIX_CONSTRUCTOR_TYPE ConstantMatrixElements::getNodeType()
{
    return ENUM_MATRIX_CONSTRUCTOR_TYPE_constantElements;
}// end of ConstantMatrixElements::getNodeType()

std::string ConstantMatrixElements::getNodeName()
{
    return "constantElements";
}// end of ConstantMatrixElements::getNodeName()

ENUM_MATRIX_TYPE ConstantMatrixElements::getMatrixType()
{
    if (matrixType == ENUM_MATRIX_TYPE_unknown)
        matrixType =  ENUM_MATRIX_TYPE_constant;
    return matrixType;
}// end of ConstantMatrixElements::getMatrixType()

std::string ConstantMatrixElements::getMatrixNodeInXML()
{
    ostringstream outStr;
    outStr <<  "<constantElements";
    if (rowMajor)
        outStr << " rowMajor=\"true\"";
    outStr << " numberOfValues=\"" << numberOfValues << "\"";
    outStr << ">" << std::endl;

    outStr << "<start>" << std::endl;
    outStr << writeIntVectorData(start, true, false);
    outStr << "</start>" << std::endl;

    if (numberOfValues > 0)
    {
        outStr << "<indexes>" << std::endl;
        outStr << writeIntVectorData(indexes, true, false);
        outStr << "</indexes>" << std::endl;

        outStr << "<values>" << std::endl;

        for(int i = 0; i < numberOfValues;)
        {
            int mult = getMult(&(values->el[i]), numberOfValues - i);
            if (mult == 1)
                outStr << "<el>" ;
            else
                outStr << "<el mult=\"" << mult << "\">";
            outStr << os_dtoa_format(values->el[i]);
            outStr << "</el>" << std::endl;
            i += mult;
        }
        outStr << "</values>" << std::endl;
    }

    outStr << "</constantElements>" << std::endl;
    return outStr.str();
}// end of ConstantMatrixElements::getMatrixNodeInXML()

bool ConstantMatrixElements::alignsOnBlockBoundary(int firstRow, int firstColumn, int nRows, int nCols)
{
    return false;
}// end of ConstantMatrixElements::alignsOnBlockBoundary()

ConstantMatrixElements* ConstantMatrixElements::cloneMatrixNode()
{
    ConstantMatrixElements *nodePtr;
    nodePtr = new ConstantMatrixElements();
    return  (ConstantMatrixElements*)nodePtr;
}// end of ConstantMatrixElements::cloneMatrixNode

bool ConstantMatrixElements::IsEqual(ConstantMatrixElements *that)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSMatrix, ENUM_OUTPUT_LEVEL_trace, "Start comparing in BaseMatrix");
#endif
    if (this == NULL)
    {
        if (that == NULL)
            return true;
        else
        {
#ifndef NDEBUG
            osoutput->OSPrint(ENUM_OUTPUT_AREA_OSMatrix, ENUM_OUTPUT_LEVEL_trace, 
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
            osoutput->OSPrint(ENUM_OUTPUT_AREA_OSMatrix, ENUM_OUTPUT_LEVEL_trace, 
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

bool ConstantMatrixElements::setRandom(double density, bool conformant, int iMin, int iMax)
{
    return true;
}// end of ConstantMatrixElements::setRandom()

bool ConstantMatrixElements::deepCopyFrom(ConstantMatrixElements *that)
{
    return true;
}// end of ConstantMatrixElements::deepCopyFrom()


/** ---------- Methods for class ConstantMatrixValues ---------- */ 
ConstantMatrixValues::ConstantMatrixValues():
    el(NULL)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, "Inside the ConstantMatrixValues Constructor");
#endif
}// end of ConstantMatrixValues::ConstantMatrixValues()

ConstantMatrixValues::~ConstantMatrixValues()
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, "Inside the ConstantMatrixValues Destructor");
#endif
    if (el != NULL)
        delete [] el;
    el = NULL;
}// end of ConstantMatrixValues::~ConstantMatrixValues()

bool ConstantMatrixValues::IsEqual(ConstantMatrixValues *that)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSMatrix, ENUM_OUTPUT_LEVEL_trace, "Start comparing in ConstantMatrixValues");
#endif
    if (this == NULL)
    {
        if (that == NULL)
            return true;
        else
        {
#ifndef NDEBUG
            osoutput->OSPrint(ENUM_OUTPUT_AREA_OSMatrix, ENUM_OUTPUT_LEVEL_trace, 
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
            osoutput->OSPrint(ENUM_OUTPUT_AREA_OSMatrix, ENUM_OUTPUT_LEVEL_trace, 
                "Second object is NULL, first is not");
#endif
            return false;
        }
        else
        {
            if (this->numberOfEl != that->numberOfEl) return false;
            for (int i=0; i < numberOfEl; i++)
                if (this->el[i] != that->el[i]) return false;

            return true;
        }
    }
}// end of ConstantMatrixValues::IsEqual()

bool ConstantMatrixValues::setRandom(double density, bool conformant, int iMin, int iMax)
{
    return true;
}// end of ConstantMatrixValues::setRandom()

bool ConstantMatrixValues::deepCopyFrom(ConstantMatrixValues *that)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSGeneral, ENUM_OUTPUT_LEVEL_trace, "Make deep copy of ConstantMatrixValues");
#endif
    this->numberOfEl = that->numberOfEl;
    this->el = new double[numberOfEl];
    for (int i=0; i<numberOfEl; i++)
        this->el[i] = that->el[i];

    return true;
}// end of ConstantMatrixValues::deepCopyFrom()


/** ---------- Methods for class VarReferenceMatrixElements ---------- */
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

ENUM_MATRIX_CONSTRUCTOR_TYPE VarReferenceMatrixElements::getNodeType()
{
    return ENUM_MATRIX_CONSTRUCTOR_TYPE_varRefElements;
}// end of VarReferenceMatrixElements::getNodeType()

std::string VarReferenceMatrixElements::getNodeName()
{
    return "varReferenceElements";
}// end of VarReferenceMatrixElements::getNodeName()

ENUM_MATRIX_TYPE VarReferenceMatrixElements::getMatrixType()
{
    if (matrixType == ENUM_MATRIX_TYPE_unknown)
        matrixType =  ENUM_MATRIX_TYPE_varref;
    return matrixType;
}// end of VarReferenceMatrixElements::getMatrixType()

std::string VarReferenceMatrixElements::getMatrixNodeInXML()
{
    int mult, incr;
    ostringstream outStr;
    outStr <<  "<varReferenceElements";
    if (rowMajor)
        outStr << " rowMajor=\"true\"";
    outStr << " numberOfValues=\"" << numberOfValues << "\"";
    outStr << ">" << std::endl;

    outStr << "<start>" << std::endl;
    outStr << writeIntVectorData(start, true, false);
    outStr << "</start>" << std::endl;

    if (numberOfValues > 0)
    {
        outStr << "<indexes>" << std::endl;
        outStr << writeIntVectorData(indexes, true, false);
        outStr << "</indexes>" << std::endl;

        outStr << "<values>" << std::endl;

        for(int i = 0; i < numberOfValues;)
        {
            getMultIncr(&(values->el[i]), &mult, &incr, (values->numberOfEl) - i, 0);
            if (mult == 1)
                outStr << "<el>";
            else if (incr == 0)
                outStr << "<el mult=\"" << mult << "\">";
            else
                outStr << "<el mult=\"" << mult << "\" incr=\"" << incr << "\">";
            outStr << values->el[i];
            outStr << "</el>" << std::endl;
            i += mult;
        }
        outStr << "</values>" << std::endl;
    }

    outStr << "</varReferenceElements>" << std::endl;
    return outStr.str();
}// end of VarReferenceMatrixElements::getMatrixNodeInXML()

bool VarReferenceMatrixElements::alignsOnBlockBoundary(int firstRow, int firstColumn, int nRows, int nCols)
{
    return false;
}// end of VarReferenceMatrixElements::alignsOnBlockBoundary()

VarReferenceMatrixElements* VarReferenceMatrixElements::cloneMatrixNode()
{
    VarReferenceMatrixElements *nodePtr;
    nodePtr = new VarReferenceMatrixElements();
    return  (VarReferenceMatrixElements*)nodePtr;
}// end of VarReferenceMatrixElements::cloneMatrixNode

bool VarReferenceMatrixElements::IsEqual(VarReferenceMatrixElements *that)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSMatrix, ENUM_OUTPUT_LEVEL_trace, "Start comparing in VarReferenceMatrixElements");
#endif
    if (this == NULL)
    {
        if (that == NULL)
            return true;
        else
        {
#ifndef NDEBUG
            osoutput->OSPrint(ENUM_OUTPUT_AREA_OSMatrix, ENUM_OUTPUT_LEVEL_trace, 
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
            osoutput->OSPrint(ENUM_OUTPUT_AREA_OSMatrix, ENUM_OUTPUT_LEVEL_trace, 
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

bool VarReferenceMatrixElements::setRandom(double density, bool conformant, int iMin, int iMax)
{
    return true;
}// end of VarReferenceMatrixElements::setRandom()

bool VarReferenceMatrixElements::deepCopyFrom(VarReferenceMatrixElements *that)
{
    return true;
}// end of VarReferenceMatrixElements::deepCopyFrom()


/** ---------- Methods for class VarReferenceMatrixValues ---------- */ 
VarReferenceMatrixValues::VarReferenceMatrixValues():
    el(NULL)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, "Inside the VarReferenceMatrixValues Constructor");
#endif
}// end of VarReferenceMatrixValues::VarReferenceMatrixValues()

VarReferenceMatrixValues::~VarReferenceMatrixValues()
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, "Inside the VarReferenceMatrixValues Destructor");
#endif
    if (el != NULL)
        delete [] el;
    el = NULL;
}// end of VarReferenceMatrixValues::~VarReferenceMatrixValues()

bool VarReferenceMatrixValues::IsEqual(VarReferenceMatrixValues *that)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSMatrix, ENUM_OUTPUT_LEVEL_trace, "Start comparing in VarReferenceMatrixValues");
#endif
    if (this == NULL)
    {
        if (that == NULL)
            return true;
        else
        {
#ifndef NDEBUG
            osoutput->OSPrint(ENUM_OUTPUT_AREA_OSMatrix, ENUM_OUTPUT_LEVEL_trace, 
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
            osoutput->OSPrint(ENUM_OUTPUT_AREA_OSMatrix, ENUM_OUTPUT_LEVEL_trace, 
                "Second object is NULL, first is not");
#endif
            return false;
        }
        else
        {
            if (this->numberOfEl != that->numberOfEl) return false;
            for (int i=0; i < numberOfEl; i++)
                if (this->el[i] != that->el[i]) return false;

            return true;
        }
    }
}// end of VarReferenceMatrixValues::IsEqual()

bool VarReferenceMatrixValues::setRandom(double density, bool conformant, int iMin, int iMax)
{
    return true;
}// end of VarReferenceMatrixValues::setRandom()

bool VarReferenceMatrixValues::deepCopyFrom(VarReferenceMatrixValues *that)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSGeneral, ENUM_OUTPUT_LEVEL_trace, "Make deep copy of VarReferenceMatrixValues");
#endif
    this->numberOfEl = that->numberOfEl;
    this->el = new int[numberOfEl];
    for (int i=0; i<numberOfEl; i++)
        this->el[i] = that->el[i];

    return true;
}// end of VarReferenceMatrixValues::deepCopyFrom()


/** ---------- Methods for class LinearMatrixElements ---------- */ 
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

ENUM_MATRIX_CONSTRUCTOR_TYPE LinearMatrixElements::getNodeType()
{
    return ENUM_MATRIX_CONSTRUCTOR_TYPE_linearElements;
}// end of LinearMatrixElements::getNodeType()

std::string LinearMatrixElements::getNodeName()
{
    return "linearElements";
}// end of LinearMatrixElements::getNodeName()

ENUM_MATRIX_TYPE LinearMatrixElements::getMatrixType()
{
    if (matrixType == ENUM_MATRIX_TYPE_unknown)
        matrixType =  ENUM_MATRIX_TYPE_linear;
    return matrixType;
}// end of LinearMatrixElements::getMatrixType()

std::string LinearMatrixElements::getMatrixNodeInXML()
{
    ostringstream outStr;
    outStr <<  "<linearElements";
    if (rowMajor)
        outStr << " rowMajor=\"true\"";
    outStr << " numberOfValues=\"" << numberOfValues << "\"";
    outStr << ">" << std::endl;

    outStr << "<start>" << std::endl;
    outStr << writeIntVectorData(start, true, false);
    outStr << "</start>" << std::endl;

    if (numberOfValues > 0)
    {
        outStr << "<indexes>" << std::endl;
        outStr << writeIntVectorData(indexes, true, false);
        outStr << "</indexes>" << std::endl;

        outStr << "<values>" << std::endl;

        int i,j;
        for (i=0; i < numberOfValues; i++)
        {
            outStr << "<el";
            outStr << " numberOfVarIdx=\"" << values->el[i]->numberOfVarIdx << "\"";
            if (values->el[i]->constant != 0.0)
                outStr << " constant=\"" << values->el[i]->constant << "\"";
            outStr << ">" << std::endl;

            for (j=0; j < values->el[i]->numberOfVarIdx; j++)
            {
                outStr << "<varIdx";
                if (values->el[i]->varIdx[j]->coef != 1.0)
                    outStr << " coef=\"" << values->el[i]->varIdx[j]->coef << "\"";
                outStr << ">";
                outStr << values->el[i]->varIdx[j]->idx; 
                outStr << "</varIdx>" << std::endl;
            }

            outStr << "</el>" << std::endl;
        }
        outStr << "</values>" << std::endl;
    }
    outStr << "</linearElements>" << std::endl;
    return outStr.str();
}// end of LinearMatrixElements::getMatrixNodeInXML()

bool LinearMatrixElements::alignsOnBlockBoundary(int firstRow, int firstColumn, int nRows, int nCols)
{
    return false;
}// end of LinearMatrixElements::alignsOnBlockBoundary()

LinearMatrixElements* LinearMatrixElements::cloneMatrixNode()
{
    LinearMatrixElements *nodePtr;
    nodePtr = new LinearMatrixElements();
    return  (LinearMatrixElements*)nodePtr;
}// end of LinearMatrixElements::cloneMatrixNode

bool LinearMatrixElements::IsEqual(LinearMatrixElements *that)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSMatrix, ENUM_OUTPUT_LEVEL_trace, "Start comparing in LinearMatrixElements");
#endif
    if (this == NULL)
    {
        if (that == NULL)
            return true;
        else
        {
#ifndef NDEBUG
            osoutput->OSPrint(ENUM_OUTPUT_AREA_OSMatrix, ENUM_OUTPUT_LEVEL_trace, 
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
            osoutput->OSPrint(ENUM_OUTPUT_AREA_OSMatrix, ENUM_OUTPUT_LEVEL_trace, 
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

bool LinearMatrixElements::setRandom(double density, bool conformant, int iMin, int iMax)
{
    return true;
}// end of LinearMatrixElements::setRandom()

bool LinearMatrixElements::deepCopyFrom(LinearMatrixElements *that)
{
    return true;
}// end of LinearMatrixElements::deepCopyFrom()


/** ---------- Methods for class LinearMatrixValues ---------- */ 
LinearMatrixValues::LinearMatrixValues():
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
#endif

    if (el != NULL)
    {
        for (int i=0; i < numberOfEl; i++)
        {
            if (el[i] != NULL)
                delete el[i];
            el[i] = NULL;
        }
        delete [] el;
        el = NULL;
    }
}// end of LinearMatrixValues::~LinearMatrixValues()

bool LinearMatrixValues::IsEqual(LinearMatrixValues *that)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSMatrix, ENUM_OUTPUT_LEVEL_trace, "Start comparing in LinearMatrixValues");
#endif
    if (this == NULL)
    {
        if (that == NULL || that->numberOfEl == 0)
            return true;
        else
        {
#ifndef NDEBUG
            osoutput->OSPrint(ENUM_OUTPUT_AREA_OSMatrix, ENUM_OUTPUT_LEVEL_trace, 
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
            osoutput->OSPrint(ENUM_OUTPUT_AREA_OSMatrix, ENUM_OUTPUT_LEVEL_trace, 
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

bool LinearMatrixValues::setRandom(double density, bool conformant, int iMin, int iMax)
{
    return true;
}// end of LinearMatrixValues::setRandom()

bool LinearMatrixValues::deepCopyFrom(LinearMatrixValues *that)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSGeneral, ENUM_OUTPUT_LEVEL_trace, "Make deep copy of LinearMatrixValues");
#endif
    this->numberOfEl = that->numberOfEl;
    this->el = new LinearMatrixElement*[numberOfEl];
    for (int i=0; i<numberOfEl; i++)
    {
        this->el[i] = new LinearMatrixElement();
        ((LinearMatrixValues*)this)->el[i]->deepCopyFrom(that->el[i]);
    }
    return true;
}// end of LinearMatrixValues::deepCopyFrom()


/** ---------- Methods for class LinearMatrixElement ---------- */
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
            if (varIdx[i] != NULL)
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
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSMatrix, ENUM_OUTPUT_LEVEL_trace, "Start comparing in LinearMatrixElement");
#endif
    if (this == NULL)
    {
        if (that == NULL || that->numberOfVarIdx == 0)
            return true;
        else
        {
#ifndef NDEBUG
            osoutput->OSPrint(ENUM_OUTPUT_AREA_OSMatrix, ENUM_OUTPUT_LEVEL_trace, 
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
            osoutput->OSPrint(ENUM_OUTPUT_AREA_OSMatrix, ENUM_OUTPUT_LEVEL_trace, 
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

bool LinearMatrixElement::setRandom(double density, bool conformant, int iMin, int iMax)
{
    return true;
}// end of LinearMatrixElement::setRandom()

bool LinearMatrixElement::deepCopyFrom(LinearMatrixElement *that)
{
    this->constant = that->constant;
    this->numberOfVarIdx = that->numberOfVarIdx;
    this->varIdx = new LinearMatrixElementTerm*[numberOfVarIdx];
    for (int i=0; i<numberOfVarIdx; i++)
    {
        this->varIdx[i] = new LinearMatrixElementTerm();
        ((LinearMatrixElement*)this)->varIdx[i]->deepCopyFrom(that->varIdx[i]);
    }
    return true;
}// end of LinearMatrixElement::deepCopyFrom()


/** ---------- Methods for class LinearMatrixElementTerm ---------- */ 
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
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSMatrix, ENUM_OUTPUT_LEVEL_trace, "Start comparing in LinearMatrixElementTerm");
#endif
    if (this == NULL)
    {
        if (that == NULL)
            return true;
        else
        {
#ifndef NDEBUG
            osoutput->OSPrint(ENUM_OUTPUT_AREA_OSMatrix, ENUM_OUTPUT_LEVEL_trace, 
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
            osoutput->OSPrint(ENUM_OUTPUT_AREA_OSMatrix, ENUM_OUTPUT_LEVEL_trace, 
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

bool LinearMatrixElementTerm::setRandom(double density, bool conformant, int iMin, int iMax)
{
    return true;
}// end of LinearMatrixElementTerm::setRandom()

bool LinearMatrixElementTerm::deepCopyFrom(LinearMatrixElementTerm *that)
{
    this->coef = that->coef;
    this->idx = that->idx;
    return true;
}// end of LinearMatrixElementTerm::deepCopyFrom()


/** ---------- Methods for class GeneralMatrixElements ---------- */ 
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

ENUM_MATRIX_CONSTRUCTOR_TYPE GeneralMatrixElements::getNodeType()
{
    return ENUM_MATRIX_CONSTRUCTOR_TYPE_generalElements;
}// end of GeneralMatrixElements::getNodeType()

std::string GeneralMatrixElements::getNodeName()
{
    return "generalElements";
}// end of GeneralMatrixElements::getNodeName()

ENUM_MATRIX_TYPE GeneralMatrixElements::getMatrixType()
{
    if (matrixType == ENUM_MATRIX_TYPE_unknown)
        matrixType =  ENUM_MATRIX_TYPE_general;
    return matrixType;
}// end of GeneralMatrixElements::getMatrixType()

std::string GeneralMatrixElements::getMatrixNodeInXML()
{
    ostringstream outStr;
    outStr <<  "<generalElements";
    if (rowMajor)
        outStr << " rowMajor=\"true\"";
    outStr << " numberOfValues=\"" << numberOfValues << "\"";
    outStr << ">" << std::endl;

    outStr << "<start>" << std::endl;
    outStr << writeIntVectorData(start, true, false);
    outStr << "</start>" << std::endl;

    if (numberOfValues > 0)
    {
        outStr << "<indexes>" << std::endl;
        outStr << writeIntVectorData(indexes, true, false);
        outStr << "</indexes>" << std::endl;

        outStr << "<values>" << std::endl;

        for (int i=0; i < numberOfValues; i++)
        {
            outStr << "<el>";
            outStr << values->el[i]->m_treeRoot->getNonlinearExpressionInXML();
            outStr << "</el>" << std::endl;
        }
        outStr << "</values>" << std::endl;
    }
    outStr << "</generalElements>" << std::endl;
    return outStr.str();
}// end of GeneralMatrixElements::getMatrixNodeInXML()

bool GeneralMatrixElements::alignsOnBlockBoundary(int firstRow, int firstColumn, int nRows, int nCols)
{
    return false;
}// end of GeneralMatrixElements::alignsOnBlockBoundary()

GeneralMatrixElements* GeneralMatrixElements::cloneMatrixNode()
{
    GeneralMatrixElements *nodePtr;
    nodePtr = new GeneralMatrixElements();
    return  (GeneralMatrixElements*)nodePtr;
}// end of GeneralMatrixElements::cloneMatrixNode

bool GeneralMatrixElements::IsEqual(GeneralMatrixElements *that)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSMatrix, ENUM_OUTPUT_LEVEL_trace, "Start comparing in GeneralMatrixElements");
#endif
    if (this == NULL)
    {
        if (that == NULL)
            return true;
        else
        {
#ifndef NDEBUG
            osoutput->OSPrint(ENUM_OUTPUT_AREA_OSMatrix, ENUM_OUTPUT_LEVEL_trace, 
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
            osoutput->OSPrint(ENUM_OUTPUT_AREA_OSMatrix, ENUM_OUTPUT_LEVEL_trace, 
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

bool GeneralMatrixElements::setRandom(double density, bool conformant, int iMin, int iMax)
{
    return true;
}// end of GeneralMatrixElements::setRandom()

bool GeneralMatrixElements::deepCopyFrom(GeneralMatrixElements *that)
{
    return true;
}// end of GeneralMatrixElements::deepCopyFrom()


/** ---------- Methods for class GeneralMatrixValues ---------- */ 
GeneralMatrixValues::GeneralMatrixValues():
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
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSMatrix, ENUM_OUTPUT_LEVEL_trace, "Start comparing in GeneralMatrixValues");
#endif
    if (this == NULL)
    {
        if (that == NULL || that->numberOfEl == 0)
            return true;
        else
        {
#ifndef NDEBUG
            osoutput->OSPrint(ENUM_OUTPUT_AREA_OSMatrix, ENUM_OUTPUT_LEVEL_trace, 
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
            osoutput->OSPrint(ENUM_OUTPUT_AREA_OSMatrix, ENUM_OUTPUT_LEVEL_trace, 
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

bool GeneralMatrixValues::deepCopyFrom(GeneralMatrixValues *that)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSGeneral, ENUM_OUTPUT_LEVEL_trace, "Make deep copy of GeneralMatrixValues");
#endif
    this->numberOfEl = that->numberOfEl;
    this->el = new ScalarExpressionTree*[numberOfEl];
    for (int i=0; i<numberOfEl; i++)
    {
        this->el[i] = new ScalarExpressionTree();
//        this->el[i]->m_treeRoot = new OSnLNode();
        this->el[i]->m_treeRoot->copyNodeAndDescendants();
    }
    return true;
}// end of GeneralMatrixValues::deepCopyFrom()

/** ---------- Methods for class ObjReferenceMatrixElements ---------- */ 
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

ENUM_MATRIX_CONSTRUCTOR_TYPE ObjReferenceMatrixElements::getNodeType()
{
    return ENUM_MATRIX_CONSTRUCTOR_TYPE_objRefElements;
}// end of ObjReferenceMatrixElements::getNodeType()

std::string ObjReferenceMatrixElements::getNodeName()
{
    return "objRefElements";
}// end of ObjReferenceMatrixElements::getNodeName()

ENUM_MATRIX_TYPE ObjReferenceMatrixElements::getMatrixType()
{
    if (matrixType == ENUM_MATRIX_TYPE_unknown)
        matrixType =  ENUM_MATRIX_TYPE_objref;
    return matrixType;
}// end of ObjReferenceMatrixElements::getMatrixType()

std::string ObjReferenceMatrixElements::getMatrixNodeInXML()
{
    ostringstream outStr;
    outStr <<  "<objReferenceElements";
    if (rowMajor)
        outStr << " rowMajor=\"true\"";
    outStr << " numberOfValues=\"" << numberOfValues << "\"";
    outStr << ">" << std::endl;

    outStr << "<start>" << std::endl;
    outStr << writeIntVectorData(start, true, false);
    outStr << "</start>" << std::endl;

    int mult, incr;
    if (numberOfValues > 0)
    {
        outStr << "<indexes>" << std::endl;
        outStr << writeIntVectorData(indexes, true, false);
        outStr << "</indexes>" << std::endl;

        outStr << "<values>" << std::endl;

        for(int i = 0; i < numberOfValues;)
        {
            getMultIncr(&(values->el[i]), &mult, &incr, (values->numberOfEl) - i, 0);
            if (mult == 1)
                outStr << "<el>";
            else if (incr == 0)
                outStr << "<el mult=\"" << mult << "\">";
            else
                outStr << "<el mult=\"" << mult << "\" incr=\"" << incr << "\">";
            outStr << values->el[i];
            outStr << "</el>" << std::endl;
            i += mult;
        }
        outStr << "</values>" << std::endl;
    }

    outStr << "</objReferenceElements>" << std::endl;
    return outStr.str();
}// end of ObjReferenceMatrixElements::getMatrixNodeInXML()

bool ObjReferenceMatrixElements::alignsOnBlockBoundary(int firstRow, int firstColumn, int nRows, int nCols)
{
    return false;
}// end of ObjReferenceMatrixElements::~alignsOnBlockBoundary()

ObjReferenceMatrixElements* ObjReferenceMatrixElements::cloneMatrixNode()
{
    ObjReferenceMatrixElements *nodePtr;
    nodePtr = new ObjReferenceMatrixElements();
    return  (ObjReferenceMatrixElements*)nodePtr;
}// end of ObjReferenceMatrixElements::cloneMatrixNode

bool ObjReferenceMatrixElements::IsEqual(ObjReferenceMatrixElements *that)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSMatrix, ENUM_OUTPUT_LEVEL_trace, "Start comparing in ObjReferenceMatrixElements");
#endif
    if (this == NULL)
    {
        if (that == NULL)
            return true;
        else
        {
#ifndef NDEBUG
            osoutput->OSPrint(ENUM_OUTPUT_AREA_OSMatrix, ENUM_OUTPUT_LEVEL_trace, 
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
            osoutput->OSPrint(ENUM_OUTPUT_AREA_OSMatrix, ENUM_OUTPUT_LEVEL_trace, 
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

bool ObjReferenceMatrixElements::setRandom(double density, bool conformant, int iMin, int iMax)
{
    return true;
}// end of ObjReferenceMatrixElements::setRandom()

bool ObjReferenceMatrixElements::deepCopyFrom(ObjReferenceMatrixElements *that)
{
    return true;
}// end of ObjReferenceMatrixElements::deepCopyFrom()


/** ---------- Methods for class ObjReferenceMatrixValues ---------- */
ObjReferenceMatrixValues::ObjReferenceMatrixValues():
    el(NULL)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, "Inside the ObjReferenceMatrixValues Constructor");
#endif
}// end of ObjReferenceMatrixValues::ObjReferenceMatrixValues()

ObjReferenceMatrixValues::~ObjReferenceMatrixValues()
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, "Inside the ObjReferenceMatrixValues Destructor");
#endif
    if (el != NULL)
        delete [] el;
    el = NULL;
}// end of ObjReferenceMatrixValues::~ObjReferenceMatrixValues()

bool ObjReferenceMatrixValues::IsEqual(ObjReferenceMatrixValues *that)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSMatrix, ENUM_OUTPUT_LEVEL_trace, "Start comparing in ObjReferenceMatrixValues");
#endif
    if (this == NULL)
    {
        if (that == NULL)
            return true;
        else
        {
#ifndef NDEBUG
            osoutput->OSPrint(ENUM_OUTPUT_AREA_OSMatrix, ENUM_OUTPUT_LEVEL_trace, 
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
            osoutput->OSPrint(ENUM_OUTPUT_AREA_OSMatrix, ENUM_OUTPUT_LEVEL_trace, 
                "Second object is NULL, first is not");
#endif
            return false;
        }
        else
        {
            if (this->numberOfEl != that->numberOfEl) return false;
            for (int i=0; i < numberOfEl; i++)
                if (this->el[i] != that->el[i]) return false;

            return true;
        }
    }
}// end of ObjReferenceMatrixValues::IsEqual()

bool ObjReferenceMatrixValues::setRandom(double density, bool conformant, int iMin, int iMax)
{
    return true;
}// end of ObjReferenceMatrixValues::setRandom()

bool ObjReferenceMatrixValues::deepCopyFrom(ObjReferenceMatrixValues *that)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSGeneral, ENUM_OUTPUT_LEVEL_trace, "Make deep copy of ObjReferenceMatrixValues");
#endif
    this->numberOfEl = that->numberOfEl;
    this->el = new int[numberOfEl];
    for (int i=0; i<numberOfEl; i++)
        this->el[i] = that->el[i];
    return true;
}// end of ObjReferenceMatrixValues::deepCopyFrom()


/** ---------- Methods for class ConReferenceMatrixElements ---------- */ 
ConReferenceMatrixElements::ConReferenceMatrixElements():
    values(NULL)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, "Inside the ConReferenceMatrixElements Constructor");
#endif
}// end of ConReferenceMatrixElements::ConReferenceMatrixElements()

ConReferenceMatrixElements::~ConReferenceMatrixElements()
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, "Inside the ConReferenceMatrixElements Destructor");
#endif
    if (values != NULL)
        delete values;
    values = NULL;
}// end of ConReferenceMatrixElements::~ConReferenceMatrixElements()

ENUM_MATRIX_CONSTRUCTOR_TYPE ConReferenceMatrixElements::getNodeType()
{
    return ENUM_MATRIX_CONSTRUCTOR_TYPE_conRefElements;
}// end of ConReferenceMatrixElements::getNodeType()

std::string ConReferenceMatrixElements::getNodeName()
{
    return "conRefElements";
}// end of ConReferenceMatrixElements::getNodeName()

ENUM_MATRIX_TYPE ConReferenceMatrixElements::getMatrixType()
{
    if (matrixType == ENUM_MATRIX_TYPE_unknown)
        matrixType =  ENUM_MATRIX_TYPE_conref;
    return matrixType;
}// end of ConReferenceMatrixElements::getMatrixType()

std::string ConReferenceMatrixElements::getMatrixNodeInXML()
{
    ostringstream outStr;
    outStr <<  "<conReferenceElements";
    if (rowMajor)
        outStr << " rowMajor=\"true\"";
    outStr << " numberOfValues=\"" << numberOfValues << "\"";
    outStr << ">" << std::endl;

    outStr << "<start>" << std::endl;
    outStr << writeIntVectorData(start, true, false);
    outStr << "</start>" << std::endl;

    if (numberOfValues > 0)
    {
        outStr << "<indexes>" << std::endl;
        outStr << writeIntVectorData(indexes, true, false);
        outStr << "</indexes>" << std::endl;

        outStr << "<values>" << std::endl;

        for(int i = 0; i < numberOfValues; i++)
        {
            outStr << "<el";
            if (values->el[i]->valueType != ENUM_CONREFERENCE_VALUETYPE_value)
            {
                outStr << " valueType=\"";
                outStr << returnConReferenceValueTypeString(values->el[i]->valueType) << "\"";
            }
            outStr << ">";
            outStr << os_dtoa_format(values->el[i]->conReference);
            outStr << "</el>" << std::endl;
        }
        outStr << "</values>" << std::endl;
    }

    outStr << "</conReferenceElements>" << std::endl;
    return outStr.str();
}// end of ConReferenceMatrixElements::getMatrixNodeInXML()

bool ConReferenceMatrixElements::alignsOnBlockBoundary(int firstRow, int firstColumn, int nRows, int nCols)
{
    return false;
}// end of ConReferenceMatrixElements::~alignsOnBlockBoundary()

ConReferenceMatrixElements* ConReferenceMatrixElements::cloneMatrixNode()
{
    ConReferenceMatrixElements *nodePtr;
    nodePtr = new ConReferenceMatrixElements();
    return  (ConReferenceMatrixElements*)nodePtr;
}// end of ConReferenceMatrixElements::cloneMatrixNode

bool ConReferenceMatrixElements::IsEqual(ConReferenceMatrixElements *that)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSMatrix, ENUM_OUTPUT_LEVEL_trace, "Start comparing in ConReferenceMatrixElements");
#endif
    if (this == NULL)
    {
        if (that == NULL)
            return true;
        else
        {
#ifndef NDEBUG
            osoutput->OSPrint(ENUM_OUTPUT_AREA_OSMatrix, ENUM_OUTPUT_LEVEL_trace, 
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
            osoutput->OSPrint(ENUM_OUTPUT_AREA_OSMatrix, ENUM_OUTPUT_LEVEL_trace, 
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


bool ConReferenceMatrixElements::setRandom(double density, bool conformant, int iMin, int iMax)
{
    return true;
}// end of ConReferenceMatrixElements::setRandom()

bool ConReferenceMatrixElements::deepCopyFrom(ConReferenceMatrixElements *that)
{
    return true;
}// end of ConReferenceMatrixElements::deepCopyFrom()


/** ---------- Methods for class ConReferenceMatrixValues ---------- */ 
ConReferenceMatrixValues::ConReferenceMatrixValues():
    el(NULL)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, "Inside the ConReferenceMatrixValues Constructor");
#endif
}// end of ConReferenceMatrixValues::ConReferenceMatrixValues()

ConReferenceMatrixValues::~ConReferenceMatrixValues()
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, "Inside the ConReferenceMatrixValues Destructor");
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
}// end of ConReferenceMatrixValues::~ConReferenceMatrixValues()

bool ConReferenceMatrixValues::IsEqual(ConReferenceMatrixValues *that)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSMatrix, ENUM_OUTPUT_LEVEL_trace, "Start comparing in ConReferenceMatrixValues");
#endif
    if (this == NULL)
    {
        if (that == NULL)
            return true;
        else
        {
#ifndef NDEBUG
            osoutput->OSPrint(ENUM_OUTPUT_AREA_OSMatrix, ENUM_OUTPUT_LEVEL_trace, 
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
            osoutput->OSPrint(ENUM_OUTPUT_AREA_OSMatrix, ENUM_OUTPUT_LEVEL_trace, 
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
}// end of ConReferenceMatrixValues::IsEqual()

bool ConReferenceMatrixValues::setRandom(double density, bool conformant, int iMin, int iMax)
{
    return true;
}// end of ConReferenceMatrixValues::setRandom()

bool ConReferenceMatrixValues::deepCopyFrom(ConReferenceMatrixValues *that)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSGeneral, ENUM_OUTPUT_LEVEL_trace, "Make deep copy of ConReferenceMatrixValues");
#endif
    this->numberOfEl = that->numberOfEl;
    this->el = new ConReferenceMatrixElement*[numberOfEl];
    for (int i=0; i<numberOfEl; i++)
        ((ConReferenceMatrixValues*)this)->el[i]->deepCopyFrom(that->el[i]);
    return true;
}// end of ConReferenceMatrixValues::deepCopyFrom()


/** ---------- Methods for class ConReferenceMatrixElement ---------- */ 
ConReferenceMatrixElement::ConReferenceMatrixElement():
    conReference(-1),
    valueType(ENUM_CONREFERENCE_VALUETYPE_value)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, "Inside the ConReferenceMatrixElement Constructor");
#endif
}// end of ConReferenceMatrixElement::ConReferenceMatrixElement()

ConReferenceMatrixElement::~ConReferenceMatrixElement()
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, "Inside the ConReferenceMatrixElement Destructor");
#endif
}// end of ConReferenceMatrixElement::~ConReferenceMatrixElement()

bool ConReferenceMatrixElement::IsEqual(ConReferenceMatrixElement *that)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSMatrix, ENUM_OUTPUT_LEVEL_trace, "Start comparing in ConReferenceMatrixElement");
#endif
    if (this == NULL)
    {
        if (that == NULL)
            return true;
        else
        {
#ifndef NDEBUG
            osoutput->OSPrint(ENUM_OUTPUT_AREA_OSMatrix, ENUM_OUTPUT_LEVEL_trace, 
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
            osoutput->OSPrint(ENUM_OUTPUT_AREA_OSMatrix, ENUM_OUTPUT_LEVEL_trace, 
                "Second object is NULL, first is not");
#endif
            return false;
        }
        else
        {
            if (this->conReference != that->conReference) return false;
            if (this->valueType    != that->valueType   ) return false;

            return true;
        }
    }
}// end of ConReferenceMatrixElement::IsEqual()

bool ConReferenceMatrixElement::setRandom(double density, bool conformant, int iMin, int iMax)
{
    return true;
}// end of ConReferenceMatrixElement::setRandom()

bool ConReferenceMatrixElement::deepCopyFrom(ConReferenceMatrixElement *that)
{
    this->conReference = that->conReference;
    this->valueType    = that->valueType;
    this->value        = that->value;
    return true;
}// end of ConReferenceMatrixElement::deepCopyFrom()


/** ---------- Methods for class RowReferenceMatrixElements ---------- */ 
RowReferenceMatrixElements::RowReferenceMatrixElements():
    values(NULL)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, "Inside the RowReferenceMatrixElements Constructor");
#endif
}// end of RowReferenceMatrixElements::RowReferenceMatrixElements()

RowReferenceMatrixElements::~RowReferenceMatrixElements()
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, "Inside the RowReferenceMatrixElements Destructor");
#endif
    if (values != NULL)
        delete values;
    values = NULL;
}// end of RowReferenceMatrixElements::~RowReferenceMatrixElements()

ENUM_MATRIX_CONSTRUCTOR_TYPE RowReferenceMatrixElements::getNodeType()
{
    return ENUM_MATRIX_CONSTRUCTOR_TYPE_rowRefElements;
}// end of RowReferenceMatrixElements::getNodeType()

std::string RowReferenceMatrixElements::getNodeName()
{
    return "rowRefElements";
}// end of RowReferenceMatrixElements::getNodeName()

ENUM_MATRIX_TYPE RowReferenceMatrixElements::getMatrixType()
{
    if (matrixType == ENUM_MATRIX_TYPE_unknown)
        matrixType =  ENUM_MATRIX_TYPE_mixedref;
    return matrixType;
}// end of RowReferenceMatrixElements::getMatrixType()

std::string RowReferenceMatrixElements::getMatrixNodeInXML()
{
    /** These elements have to be printed in two passes: 
     *  objReference elements first, followed by conReference elements
     */
    ostringstream outStr;
    int tmpNum = 0;
    int i, j;
    for (i=0; i < start->numberOfEl - 1; i++)
    {
        for (j=start->el[i]; j<start->el[i+1]; j++)
        {
            if (values->el[j]->conReference < 0) tmpNum++;
        }
    }

    if (tmpNum > 0)
    {
        outStr <<  "<objReferenceElements";
        if (rowMajor)
            outStr << " rowMajor=\"true\"";
        outStr << " numberOfValues=\"" << tmpNum << "\"";
        outStr << ">" << std::endl;

        if (tmpNum < numberOfValues)
        {
            outStr << "<start>" << std::endl;
            outStr << "<el>0</el>" << std::endl;
            tmpNum = 0;
            for (i=0; i < start->numberOfEl - 1; i++)
            {
                for (j=start->el[i]; j<start->el[i+1]; j++)
                {
                    if (values->el[j]->conReference < 0) tmpNum++;
                }
                outStr << "<el>" << tmpNum << "</el>" << std::endl;
            }
            outStr << "</start>" << std::endl;

            outStr << "<indexes>" << std::endl;
            for (i=0; i < start->numberOfEl - 1; i++)
            {
                for (j=start->el[i]; j<start->el[i+1]; j++)
                {
                    if (values->el[j]->conReference < 0) 
                        outStr << "<el>" << indexes->el[j] << "</el>";
                }
            }
            outStr << "</indexes>" << std::endl;

            outStr << "<values>" << std::endl;
            for (i=0; i < start->numberOfEl - 1; i++)
            {
                for (j=start->el[i]; j<start->el[i+1]; j++)
                {
                    if (values->el[j]->conReference < 0) 
                        outStr << "<el>" << values->el[j]->conReference << "</el>";
                }
            }
            outStr << "</values>" << std::endl;
            outStr << "</objReferenceElements>" << std::endl;

            outStr <<  "<conReferenceElements";
            if (rowMajor)
                outStr << " rowMajor=\"true\"";
            outStr << " numberOfValues=\"" << numberOfValues - tmpNum << "\"";
            outStr << ">" << std::endl;

            outStr << "<start>" << std::endl;
            outStr << "<el>0</el>" << std::endl;
            tmpNum = 0;
            for (i=0; i < start->numberOfEl - 1; i++)
            {
                for (j=start->el[i]; j<start->el[i+1]; j++)
                {
                    if (values->el[j]->conReference >= 0) tmpNum++;
                }
                outStr << "<el>" << tmpNum << "</el>" << std::endl;
            }
            outStr << "</start>" << std::endl;

            outStr << "<indexes>" << std::endl;
            for (i=0; i < start->numberOfEl - 1; i++)
            {
                for (j=start->el[i]; j<start->el[i+1]; j++)
                {
                    if (values->el[j]->conReference >= 0) 
                        outStr << "<el>" << indexes->el[j] << "</el>";
                }
            }
            outStr << "</indexes>" << std::endl;

            outStr << "<values>" << std::endl;
            for (i=0; i < start->numberOfEl - 1; i++)
            {
                for (j=start->el[i]; j<start->el[i+1]; j++)
                {
                    if (values->el[j]->conReference >= 0)
                    {
                        outStr << "<el";
                        if (values->el[i]->valueType != ENUM_CONREFERENCE_VALUETYPE_value)
                        {
                            outStr << " valueType=\"";
                            outStr << returnConReferenceValueTypeString(values->el[i]->valueType) << "\"";
                        }
                        outStr << ">" << values->el[j]->conReference << "</el>";
                    }
                }
            }
            outStr << "</values>" << std::endl;
            outStr << "</conReferenceElements>" << std::endl;

        }
        else // there are only objReferenceElements
        {
            outStr << "<start>" << std::endl;
            outStr << writeIntVectorData(start, true, false);
            outStr << "</start>" << std::endl;

            if (numberOfValues > 0)
            {
                outStr << "<indexes>" << std::endl;
                outStr << writeIntVectorData(indexes, true, false);
                outStr << "</indexes>" << std::endl;

                outStr << "<values>" << std::endl;

                for(int i = 0; i < numberOfValues; i++)
                {
                    outStr << "<el";
                    //gus: work out mult and incr
                    outStr << ">";
                    outStr << os_dtoa_format(values->el[i]->conReference);
                    outStr << "</el>" << std::endl;
                }
                outStr << "</values>" << std::endl;
            }
            outStr << "</objReferenceElements>" << std::endl;
        }
    }
    else // there are only conReferenceElements
    {
        outStr <<  "<conReferenceElements";
        if (rowMajor)
            outStr << " rowMajor=\"true\"";
        outStr << " numberOfValues=\"" << numberOfValues << "\"";
        outStr << ">" << std::endl;

        outStr << "<start>" << std::endl;
        outStr << writeIntVectorData(start, true, false);
        outStr << "</start>" << std::endl;

        if (numberOfValues > 0)
        {
            outStr << "<indexes>" << std::endl;
            outStr << writeIntVectorData(indexes, true, false);
            outStr << "</indexes>" << std::endl;

            outStr << "<values>" << std::endl;

            for(int i = 0; i < numberOfValues; i++)
            {
                outStr << "<el";
                if (values->el[i]->valueType != ENUM_CONREFERENCE_VALUETYPE_value)
                {
                    outStr << " valueType=\"";
                    outStr << returnConReferenceValueTypeString(values->el[i]->valueType) << "\"";
                }
                //gus: work out mult and incr
                outStr << ">";
                outStr << os_dtoa_format(values->el[i]->conReference);
                outStr << "</el>" << std::endl;
            }
            outStr << "</values>" << std::endl;
        }
        outStr << "</conReferenceElements>" << std::endl;
    }

    return outStr.str();
}// end of RowReferenceMatrixElements::getMatrixNodeInXML()

bool RowReferenceMatrixElements::alignsOnBlockBoundary(int firstRow, int firstColumn, int nRows, int nCols)
{
    return false;
}// end of RowReferenceMatrixElements::alignsOnBlockBoundary()

RowReferenceMatrixElements* RowReferenceMatrixElements::cloneMatrixNode()
{
    RowReferenceMatrixElements *nodePtr;
    nodePtr = new RowReferenceMatrixElements();
    return  (RowReferenceMatrixElements*)nodePtr;
}// end of RowReferenceMatrixElements::cloneMatrixNode

bool RowReferenceMatrixElements::IsEqual(RowReferenceMatrixElements *that)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSMatrix, ENUM_OUTPUT_LEVEL_trace, "Start comparing in RowReferenceMatrixElements");
#endif
    if (this == NULL)
    {
        if (that == NULL)
            return true;
        else
        {
#ifndef NDEBUG
            osoutput->OSPrint(ENUM_OUTPUT_AREA_OSMatrix, ENUM_OUTPUT_LEVEL_trace, 
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
            osoutput->OSPrint(ENUM_OUTPUT_AREA_OSMatrix, ENUM_OUTPUT_LEVEL_trace, 
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
}// end of RowReferenceMatrixElements::IsEqual()

bool RowReferenceMatrixElements::setRandom(double density, bool conformant, int iMin, int iMax)
{
    return true;
}// end of RowReferenceMatrixElements::setRandom()

bool RowReferenceMatrixElements::deepCopyFrom(RowReferenceMatrixElements *that)
{
    return true;
}// end of RowReferenceMatrixElements::deepCopyFrom()


/** ---------- Methods for class MatrixBlocks ---------- */ 
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

ENUM_MATRIX_CONSTRUCTOR_TYPE MatrixBlocks::getNodeType()
{
    return ENUM_MATRIX_CONSTRUCTOR_TYPE_blocks;
}// end of MatrixBlocks::getNodeType()

std::string MatrixBlocks::getNodeName()
{
    return "blocks";
}// end of MatrixBlocks::getNodeName()

ENUM_MATRIX_TYPE MatrixBlocks::getMatrixType()
{
    if (matrixType == ENUM_MATRIX_TYPE_unknown)
    {
        matrixType =  ENUM_MATRIX_TYPE_zero;
        for (int i=0; i<inumberOfChildren; i++)
            matrixType = mergeMatrixType(matrixType, m_mChildren[i]->getMatrixType());
    }
    return matrixType;
}// end of MatrixBlocks::getMatrixType()

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

MatrixBlocks* MatrixBlocks::cloneMatrixNode()
{
    MatrixNode *nodePtr;
    nodePtr = new MatrixBlocks();
    return  (MatrixBlocks*)nodePtr;
}// end of MatrixBlocks::cloneMatrixNode

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


/** ---------- Methods for class MatrixBlock ---------- */ 
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

ENUM_MATRIX_CONSTRUCTOR_TYPE MatrixBlock::getNodeType()
{
    return ENUM_MATRIX_CONSTRUCTOR_TYPE_block;
}// end of MatrixBlock::getNodeType()

std::string MatrixBlock::getNodeName()
{
    return "block";
}// end of MatrixBlock::getNodeName()

ENUM_MATRIX_TYPE MatrixBlock::getMatrixType()
{
    if (matrixType == ENUM_MATRIX_TYPE_unknown)
    {
        matrixType =  ENUM_MATRIX_TYPE_zero;
        for (int i=0; i<inumberOfChildren; i++)
        {
            matrixType = mergeMatrixType(matrixType, m_mChildren[i]->getMatrixType());
        }
    }
    return matrixType;
}// end of MatrixBlock::getMatrixType()

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

    if (inumberOfChildren > 0)
    {
        outStr << ">" << std::endl;
        for (int i=0; i < inumberOfChildren; i++)
            outStr << m_mChildren[i]->getMatrixNodeInXML();
        outStr << "</block>" << std::endl;
    }
    else
        outStr << "/>" << std::endl;
    return outStr.str();
}// end of MatrixBlock::getMatrixNodeInXML()

bool MatrixBlock::alignsOnBlockBoundary(int firstRow, int firstColumn, int nRows, int nCols)
{
    return (firstRow == 0 && firstColumn == 0 && nRows == numberOfRows && nCols == numberOfColumns);
}// end of MatrixBlock::alignsOnBlockBoundary()

bool MatrixBlock::expandElements(bool rowMajor)
{
    return NULL;
}// end of expandElements

MatrixBlock* MatrixBlock::cloneMatrixNode()
{
    MatrixType *nodePtr;
    nodePtr = new MatrixBlock();
    return  (MatrixBlock*)nodePtr;
}// end of MatrixBlock::cloneMatrixNode

bool MatrixBlock::IsEqual(MatrixBlock *that)
{
    return true;
}// end of MatrixBlock::IsEqual()

bool MatrixBlock::setRandom(double density, bool conformant, int iMin, int iMax)
{
    return true;
}// end of MatrixBlock::setRandom()

bool MatrixBlock::deepCopyFrom(MatrixBlock *that)
{
    return true;
}// end of MatrixBlock::deepCopyFrom()
// end of methods for MatrixBlock ----------------------------------------------


/** ---------- Methods for class GeneralSparseMatrix ---------- */ 
GeneralSparseMatrix::GeneralSparseMatrix():
    b_deleteStartArray(true),
    b_deleteIndexArray(true),
    b_deleteValueArray(true),
    isRowMajor(false),
    startSize(-1),
    valueSize(-1),
    vType(ENUM_MATRIX_TYPE_unknown),
    starts(NULL),
    indexes(NULL),
    values(NULL)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, "Inside the GeneralSparseMatrix Constructor");
#endif
}// end of GeneralSparseMatrix

GeneralSparseMatrix::GeneralSparseMatrix(bool isColumnMajor_, int startSize_, int valueSize_,
                                         ENUM_MATRIX_TYPE type_):
    b_deleteStartArray(true),
    b_deleteIndexArray(true),
    b_deleteValueArray(true),
    values(NULL)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, "Inside the alternate GeneralSparseMatrix Constructor");
#endif
    isRowMajor = !(isColumnMajor_);
    startSize = startSize_;
    valueSize = valueSize_;
    vType = type_;
    starts  = new int[startSize];
    indexes = new int[valueSize];
}// end of GeneralSparseMatrix

GeneralSparseMatrix::~GeneralSparseMatrix()
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, "Inside the GeneralSparseMatrix Destructor");
#endif
    if (b_deleteStartArray)
    {
        if (starts != NULL) delete [] starts;
        starts = NULL;
    }
    if (b_deleteIndexArray)
    {
        if (indexes != NULL) delete [] indexes;
        indexes = NULL;
    }
    if (b_deleteValueArray)
    {
        if (values != NULL) delete values;
        values = NULL;
    }
}// end of ~GeneralSparseMatrix

bool GeneralSparseMatrix::display(int secondaryDim)
{
    return true;
}


/** ---------- Methods for class ExpandedMatrixBlocks ---------- */ 
ExpandedMatrixBlocks::ExpandedMatrixBlocks():
    bDeleteArrays(true),
    isRowMajor(false),
    blockNumber(0),
    blockRows(NULL),
    blockColumns(NULL),
    blocks(NULL)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, "Inside the GeneralSparseMatrix default constructor");
#endif
}// end of ExpandedMatrixBlocks

ExpandedMatrixBlocks::ExpandedMatrixBlocks(bool isRowMajor_, int startSize, int valueSize):
    bDeleteArrays(true),
    blockNumber(0),
    blockRows(NULL),
    blockColumns(NULL),
    blocks(NULL)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, "Inside the GeneralSparseMatrix default constructor");
#endif
    isRowMajor = isRowMajor_;
}// end of ExpandedMatrixBlocks

ExpandedMatrixBlocks::~ExpandedMatrixBlocks()
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, "Inside the ExpandedMatrixBlocks Destructor");
#endif
    if (bDeleteArrays)
    {
        if (blockRows != NULL) delete [] blockRows;
        blockRows = NULL;
        if (blockColumns != NULL) delete [] blockColumns;
        blockColumns = NULL;
        if (blockNumber > 0 && blocks != NULL)
        {
            for (int i=0; i < blockNumber; i++)
            {
                if (blocks[i] != NULL)
                    delete blocks[i];
                blocks[i] = NULL;
            }
        }
        if (blocks != NULL) delete [] blocks;
        blocks = NULL;
    }
}// end of ~ExpandedMatrixBlocks

bool ExpandedMatrixBlocks::display(int secondaryDim)
{
    return true;
}

