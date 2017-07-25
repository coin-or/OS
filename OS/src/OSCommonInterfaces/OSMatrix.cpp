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
    declaredMatrixType(ENUM_MATRIX_TYPE_unknown), 
    inferredMatrixType(ENUM_MATRIX_TYPE_unknown), 
    nType (ENUM_MATRIX_CONSTRUCTOR_TYPE_unknown),
    inumberOfChildren(),
    m_mChildren(NULL){
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSMatrix, ENUM_OUTPUT_LEVEL_trace, "in MatrixNode constructor");
    std::ostringstream outStr;
    outStr << "Allocate MatrixNode at address" << this;
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSMatrix, ENUM_OUTPUT_LEVEL_detailed_trace, outStr.str());
#endif
}

MatrixNode::~MatrixNode()
{
#ifndef NDEBUG
    std::ostringstream outStr;
    outStr << "inside MatrixNode destructor" << std::endl;
    outStr << "number of kids = " <<  inumberOfChildren << std::endl;
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSMatrix, ENUM_OUTPUT_LEVEL_trace, outStr.str());
    outStr.str("");
    outStr.clear();
    outStr << "deleting MatrixNode at address" << this << std::endl;
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSMatrix, ENUM_OUTPUT_LEVEL_detailed_trace, outStr.str());
#endif
    if (inumberOfChildren > 0 && m_mChildren != NULL)
    {
        for (unsigned int i=0; i<inumberOfChildren; i++)
        {
            if (m_mChildren[i] != NULL)
            {
#ifndef NDEBUG
                outStr.str("");
                outStr.clear();
                outStr << "deleting MatrixNode->m_mChildren[" << i << "] at " 
                                                              << &m_mChildren[i] << std::endl;
                osoutput->OSPrint(ENUM_OUTPUT_AREA_OSMatrix, 
                    ENUM_OUTPUT_LEVEL_detailed_trace, outStr.str());
#endif
                delete m_mChildren[i];
            }
            m_mChildren[i] = NULL;
        }
        delete [] m_mChildren;
        m_mChildren = NULL;
        inumberOfChildren = 0;
    }
    else if (inumberOfChildren > 0 || m_mChildren != NULL)
        osoutput->OSPrint(ENUM_OUTPUT_AREA_OSMatrix, ENUM_OUTPUT_LEVEL_warning, "Warning: Possible memory leak");
}

ENUM_MATRIX_TYPE MatrixNode::getDeclaredMatrixType()
{
    return declaredMatrixType;
}// end of MatrixNode::getDeclaredMatrixType()


ENUM_MATRIX_TYPE MatrixNode::getInferredMatrixType()
{
    if (inferredMatrixType == ENUM_MATRIX_TYPE_unknown)
    {
        for (unsigned int i=0; i<inumberOfChildren; i++)
        {
            inferredMatrixType = mergeMatrixType(inferredMatrixType,
                                                 m_mChildren[i]->getInferredMatrixType());
        }
    }
    return inferredMatrixType;
}// end of MatrixNode::getInferredMatrixType()


ENUM_MATRIX_TYPE MatrixNode::getMatrixType()
{
    inferredMatrixType = getInferredMatrixType();
    if (declaredMatrixType == ENUM_MATRIX_TYPE_unknown)
        return inferredMatrixType;

    if (declaredMatrixType == mergeMatrixType(declaredMatrixType, inferredMatrixType))
        return declaredMatrixType;

    else throw ErrorClass("Declared matrix type conflicts with inferred type");
}// end of MatrixNode::getMatrixType()


ENUM_MATRIX_CONSTRUCTOR_TYPE MatrixNode::getNodeType()
{
    return nType;
}// end of MatrixNode::getNodeType()


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
            if (this->inumberOfChildren  != that->inumberOfChildren)  return false;
            if (this->declaredMatrixType != that->declaredMatrixType) return false;
            if (this->inferredMatrixType != that->inferredMatrixType) return false;
            if (this->nType              != that->nType)              return false;

            for (unsigned int i=0; i < inumberOfChildren; i++)
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
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSMatrix, ENUM_OUTPUT_LEVEL_trace, 
        "Inside the  MatrixConstructor Constructor");
    std::ostringstream outStr;
    outStr << "Allocate MatrixConstructor at address" << this;
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSMatrix, ENUM_OUTPUT_LEVEL_detailed_trace, outStr.str());
#endif
}

MatrixConstructor::~MatrixConstructor()
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSMatrix, ENUM_OUTPUT_LEVEL_trace, 
        "Inside the MatrixConstructor Destructor");
    std::ostringstream outStr;
    outStr << "deleting MatrixConstructor at address" << this << std::endl;
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSMatrix, ENUM_OUTPUT_LEVEL_detailed_trace, outStr.str());
#endif
}//end of MatrixConstructor::~MatrixConstructor
// end of methods for MatrixConstructor


/** ---------- Methods for class MatrixType ---------- */
// methods for MatrixType
MatrixType::MatrixType():
    MatrixNode(),
//    symmetry(ENUM_MATRIX_SYMMETRY_none),
    numberOfRows(0),
    numberOfColumns(0),
    m_bHaveRowPartition(false),
    m_iRowPartitionSize(0),
    m_miRowPartition(NULL),
    m_bHaveColumnPartition(false),
    m_iColumnPartitionSize(0),
    m_miColumnPartition(NULL)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSMatrix, ENUM_OUTPUT_LEVEL_trace, 
        "Inside the MatrixType Constructor");
    std::ostringstream outStr;
    outStr << "Allocate MatrixType at address" << this;
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSMatrix, ENUM_OUTPUT_LEVEL_detailed_trace, outStr.str());
#endif
}// end of MatrixType


MatrixType::~MatrixType()
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSMatrix, ENUM_OUTPUT_LEVEL_trace, 
        "Inside the MatrixType Destructor");
    std::ostringstream outStr;
    outStr << "deleting MatrixType at address" << this << std::endl;
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSMatrix, ENUM_OUTPUT_LEVEL_detailed_trace, outStr.str());
#endif
    if (m_miRowPartition != NULL)
        delete[] m_miRowPartition;
    m_miRowPartition = NULL;

    if (m_miColumnPartition != NULL)
        delete[] m_miColumnPartition;
    m_miColumnPartition = NULL;

    for(size_t i = 0; i < expandedMatrixByElements.size(); ++i)
    {
        delete expandedMatrixByElements[i];
    }
    expandedMatrixByElements.clear();

    for(size_t i = 0; i < expandedMatrixByBlocks.size(); ++i)
    {
        delete expandedMatrixByBlocks[i];
    }
    expandedMatrixByBlocks.clear();
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
    for (unsigned int i=0; i < inumberOfChildren; i++)
    {
        if (m_mChildren[i]->nType == ENUM_MATRIX_CONSTRUCTOR_TYPE_constantElements        ) return true;
        if (m_mChildren[i]->nType == ENUM_MATRIX_CONSTRUCTOR_TYPE_complexElements         ) return true;
        if (m_mChildren[i]->nType == ENUM_MATRIX_CONSTRUCTOR_TYPE_varRefElements          ) return true;
        if (m_mChildren[i]->nType == ENUM_MATRIX_CONSTRUCTOR_TYPE_linearElements          ) return true;
        if (m_mChildren[i]->nType == ENUM_MATRIX_CONSTRUCTOR_TYPE_realValuedExpressions   ) return true;
        if (m_mChildren[i]->nType == ENUM_MATRIX_CONSTRUCTOR_TYPE_complexValuedExpressions) return true;
        if (m_mChildren[i]->nType == ENUM_MATRIX_CONSTRUCTOR_TYPE_objRefElements          ) return true;
        if (m_mChildren[i]->nType == ENUM_MATRIX_CONSTRUCTOR_TYPE_conRefElements          ) return true;
    }
    return false;
}// end of matrixHasElements


bool MatrixType::matrixHasTransformations()
{
    if (inumberOfChildren == 0 || m_mChildren == NULL) return false;
    for (unsigned int i=0; i < inumberOfChildren; i++)
    {
        if (m_mChildren[i]->nType == ENUM_MATRIX_CONSTRUCTOR_TYPE_transformation) return true;
    }
    return false;
}// end of matrixHasTransformations


bool MatrixType::matrixHasBlocks()
{
    if (inumberOfChildren == 0 || m_mChildren == NULL) return false;
    for (unsigned int i=0; i < inumberOfChildren; i++)
    {
        if (m_mChildren[i]->nType == ENUM_MATRIX_CONSTRUCTOR_TYPE_blocks) return true;
    }
    return false;
}// end of matrixHasBlocks


int  MatrixType::getNumberOfElementConstructors()
{
    int k = 0;
    if (inumberOfChildren == 0 || m_mChildren == NULL) return 0;
    for (unsigned int i=0; i < inumberOfChildren; i++)
    {
        if (m_mChildren[i]->nType == ENUM_MATRIX_CONSTRUCTOR_TYPE_constantElements)         k++;
        if (m_mChildren[i]->nType == ENUM_MATRIX_CONSTRUCTOR_TYPE_complexElements)          k++;
        if (m_mChildren[i]->nType == ENUM_MATRIX_CONSTRUCTOR_TYPE_varRefElements)           k++;
        if (m_mChildren[i]->nType == ENUM_MATRIX_CONSTRUCTOR_TYPE_linearElements)           k++;
        if (m_mChildren[i]->nType == ENUM_MATRIX_CONSTRUCTOR_TYPE_realValuedExpressions)    k++;
        if (m_mChildren[i]->nType == ENUM_MATRIX_CONSTRUCTOR_TYPE_complexValuedExpressions) k++;
        if (m_mChildren[i]->nType == ENUM_MATRIX_CONSTRUCTOR_TYPE_objRefElements)           k++;
        if (m_mChildren[i]->nType == ENUM_MATRIX_CONSTRUCTOR_TYPE_conRefElements)           k++;
    }
    return k;
}// end of getNumberOfElementConstructors


int  MatrixType::getNumberOfTransformationConstructors()
{
    int k = 0;
    if (inumberOfChildren == 0 || m_mChildren == NULL) return 0;
    for (unsigned int i=0; i < inumberOfChildren; i++)
    {
        if (m_mChildren[i]->nType == ENUM_MATRIX_CONSTRUCTOR_TYPE_transformation) k++;
    }
    return k;
}// end of getNumberOfTransformationConstructors


int  MatrixType::getNumberOfBlocksConstructors()
{
    int k = 0;
    if (inumberOfChildren == 0 || m_mChildren == NULL) return 0;
    for (unsigned int i=0; i < inumberOfChildren; i++)
    {
        if (m_mChildren[i]->nType == ENUM_MATRIX_CONSTRUCTOR_TYPE_blocks) k++;
    }
    return k;
}// end of getNumberOfBlocksConstructors


GeneralSparseMatrix* MatrixType::processBaseMatrix( OSMatrix** mtxIdx, bool rowMajor_, 
                                                    ENUM_MATRIX_TYPE convertTo_, 
                                                    ENUM_MATRIX_SYMMETRY symmetry_)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSMatrix, ENUM_OUTPUT_LEVEL_trace, "Inside processBaseMatrix()");
#endif
    try
    {
        ENUM_MATRIX_SYMMETRY symmetry = symmetry_;

        if (symmetry == ENUM_MATRIX_SYMMETRY_default)
            symmetry  = this->symmetry;
        if (symmetry != this->symmetry)
        {
            if (this->symmetry == ENUM_MATRIX_SYMMETRY_default)
                this->symmetry  = symmetry;
            else
                throw ErrorClass("Symmetry changes not yet implemented in processBaseMatrix()");
        }

        // Note: base matrix is always the first child
        OSMatrix* baseMtxPtr = ((BaseMatrix*)m_mChildren[0])->baseMatrix;
        m_mChildren[0]->inferredMatrixType = baseMtxPtr->getMatrixType();

        int iroff = ((BaseMatrix*)m_mChildren[0])->targetMatrixFirstRow;
        int icoff = ((BaseMatrix*)m_mChildren[0])->targetMatrixFirstCol;

        int base_r0, base_c0, base_rN, base_cN;

        GeneralSparseMatrix* baseMtx;

        // expand into row or column major format, depending on how the base matrix is used 
        if (((BaseMatrix*)m_mChildren[0])->baseTranspose != rowMajor_)
        {
            int i = baseMtxPtr->getExpandedMatrix(mtxIdx, true, convertTo_, symmetry);
            if (i < 0) 
                throw ErrorClass("Base matrix could not be expanded");
            baseMtx = baseMtxPtr->expandedMatrixByElements[i];
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
            int i = baseMtxPtr->getExpandedMatrix(mtxIdx, false, convertTo_, symmetry);
            if (i < 0) 
                throw ErrorClass("Base matrix could not be expanded");
            baseMtx = baseMtxPtr->expandedMatrixByElements[i];
            base_r0 = ((BaseMatrix*)m_mChildren[0])->baseMatrixStartRow;
            base_c0 = ((BaseMatrix*)m_mChildren[0])->baseMatrixStartCol;
            base_rN = ((BaseMatrix*)m_mChildren[0])->baseMatrixEndRow;
            base_cN = ((BaseMatrix*)m_mChildren[0])->baseMatrixEndCol;
            if (base_rN < 0)
                base_rN = baseMtxPtr->numberOfRows - 1;
            if (base_cN < 0)
                base_cN = baseMtxPtr->numberOfColumns - 1;
        }

        double scaleMult = ((BaseMatrix*)m_mChildren[0])->scalarMultiplier;
        double scaleImag = ((BaseMatrix*)m_mChildren[0])->scalarImaginaryPart;

        GeneralSparseMatrix* tempMtx = new GeneralSparseMatrix();
        tempMtx->symmetry        = symmetry;
        tempMtx->startSize       = numberOfColumns + 1;
        tempMtx->numberOfRows    = numberOfRows;
        tempMtx->numberOfColumns = numberOfColumns;

        // position and other options can affect how arrays need to be duplicated
        bool isShifted = (iroff > 0 || icoff > 0);
        bool isCropped = (base_c0 > 0 || base_r0 > 0 || 
                          base_rN < baseMtxPtr->numberOfRows - 1 ||
                          base_cN < baseMtxPtr->numberOfColumns - 1);
        bool isClipped = (iroff + base_rN - base_r0 >= numberOfRows ||
                          icoff + base_cN - base_c0 >= numberOfColumns);
        bool hasGap    = (icoff + base_cN - base_c0 <  numberOfColumns - 1);
        bool isScaled  = (scaleMult < 1 || scaleMult > 1 || scaleImag < 0 || scaleImag > 0);
        bool reTyped   = (getMatrixType() != m_mChildren[0]->getMatrixType());

        //default position without cropping is easiest (retyping and scaling is handled here)
        if ( !isShifted && !isCropped && !isClipped )
        {
            tempMtx->b_deleteStartArray = true;
            tempMtx->b_deleteIndexArray = true;
            tempMtx->b_deleteValueArray = true;
            tempMtx->isRowMajor = rowMajor_;
            tempMtx->valueSize  = baseMtx->valueSize;

            ENUM_MATRIX_TYPE convertTo = convertTo_;
            ENUM_MATRIX_TYPE inferredType = m_mChildren[0]->getMatrixType();
            if (convertTo == ENUM_MATRIX_TYPE_unknown) 
                convertTo  = inferredType;
            if (convertTo != mergeMatrixType(convertTo, inferredType))
               throw ErrorClass("Requested improper conversion of element values");

            tempMtx->valueType = convertTo;

            if (scaleImag < 0 || scaleImag > 0)
                tempMtx->valueType = mergeMatrixType(tempMtx->valueType, ENUM_MATRIX_TYPE_complexConstant);
            else if (scaleMult < 1 || scaleMult > 1)
                tempMtx->valueType = mergeMatrixType(tempMtx->valueType, ENUM_MATRIX_TYPE_constant);

            tempMtx->startSize = numberOfColumns + 1;
            tempMtx->start =
                new int[tempMtx->startSize];
            for (int i=0; i < baseMtx->startSize; i++)
                tempMtx->start[i] = baseMtx->start[i];

            // even in default layout the baseMatrix may still have different (i.e., smaller)
            // dimensions. This may leave a gap of empty columns on the right.
            if (hasGap)
            {
                int lastStart = baseMtx->valueSize;
                for (int i=baseMtx->startSize;
                         i < tempMtx->startSize; i++)
                    tempMtx->start[i] = lastStart;
            }

            tempMtx->index = new int[baseMtx->valueSize];
            for (int i=0; i < baseMtx->valueSize; i++)
                tempMtx->index[i] = baseMtx->index[i];

            // allocate space and store value array
            if (!tempMtx->allocateValueArray(baseMtx->valueSize))
                throw ErrorClass("Error allocating value array of a GeneralSparseMatrix");

            for (int i = 0; i < baseMtx->valueSize; i++)
                if (!tempMtx->copyValue(baseMtx, i, i, scaleMult, scaleImag))
                    throw ErrorClass("Matrix expansion failed while copying element values");
        }
        else // repositioned Basematrix with cropping
        {
            tempMtx->b_deleteStartArray = true;
            tempMtx->b_deleteIndexArray = true;
            tempMtx->b_deleteValueArray = true;
            tempMtx->isRowMajor = false;
            tempMtx->startSize  = numberOfColumns + 1;
            tempMtx->valueType  = baseMtx->valueType;

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
                for (int j=baseMtx->start[i-adjc]; j<baseMtx->start[i-adjc+1]; j++)
                {
                    if (baseMtx->index[j] >= base_r0 &&
                        baseMtx->index[j] <= base_rN &&
                        baseMtx->index[j] <  numberOfRows + base_r0 - iroff)
                        tmpStarts[i+1]++; 
                }
            for (int i=icoff+1; i < startSize; i++) 
                tmpStarts[i] += tmpStarts[i-1];

            int valueSize      = tmpStarts[startSize-1];
            tempMtx->valueSize = valueSize;
            tempMtx->start     = tmpStarts;
            tempMtx->index     = new int[valueSize];

            // to get the values, go through the base matrix a second time
            // allocate space and store value array
            if (!tempMtx->allocateValueArray(valueSize))
                throw ErrorClass("Error allocating value array of a GeneralSparseMatrix");

            int ival = 0;
            for (int i=icoff; i<lastcol; i++)
                for (int j=baseMtx->start[i-adjc]; j<baseMtx->start[i-adjc+1]; j++)
                {
                    if (baseMtx->index[j] >= base_r0 &&
                        baseMtx->index[j] <= base_rN &&
                        baseMtx->index[j] <  numberOfRows + base_r0 - iroff)
                    {
                        tempMtx->index[ival] = baseMtx->index[j] - base_r0 + iroff; 
                        if (!tempMtx->copyValue(baseMtx, j, ival, scaleMult, scaleImag))
                            throw ErrorClass("Matrix expansion failed while copying element values");
                        ival++;
                    }    
                }
        }
        tempMtx->printMatrix();
        return tempMtx; 
    }
    catch(const ErrorClass& eclass)
    {
        throw ErrorClass( eclass.errormsg);
    }
}// end of processBaseMatrix


GeneralSparseMatrix* MatrixType::expandBlocks( ExpandedMatrixBlocks* currentBlocks,
                                               OSMatrix** mtxIdx, bool rowMajor_, 
                                               ENUM_MATRIX_TYPE convertTo_, 
                                               ENUM_MATRIX_SYMMETRY symmetry_)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSMatrix, ENUM_OUTPUT_LEVEL_trace, "Inside expandBlocks()");
#endif
    GeneralSparseMatrix* tempMtx = NULL;

    try
    {
        tempMtx = new GeneralSparseMatrix();

        ENUM_MATRIX_TYPE convertTo = convertTo_;
        ENUM_MATRIX_TYPE inferredType = getMatrixType();
        if (convertTo == ENUM_MATRIX_TYPE_unknown) 
            convertTo  = inferredType;
        if (convertTo != mergeMatrixType(convertTo, inferredType))
           throw ErrorClass("Requested improper conversion of element values");

        ENUM_MATRIX_SYMMETRY symmetry = symmetry_;

        if (symmetry == ENUM_MATRIX_SYMMETRY_default)
            symmetry  = this->symmetry;
        {
            if (this->symmetry == ENUM_MATRIX_SYMMETRY_default)
                this->symmetry  = symmetry;
            if (this->symmetry != symmetry)
                throw ErrorClass("Symmetry changes not yet implemented in expandBlocks()");
        }

        tempMtx->b_deleteStartArray  = true;
        tempMtx->b_deleteIndexArray  = true;
        tempMtx->b_deleteValueArray  = true;
        tempMtx->isRowMajor          = rowMajor_;
        tempMtx->symmetry            = symmetry;
        tempMtx->numberOfRows        = numberOfRows;
        tempMtx->numberOfColumns     = numberOfColumns;
        tempMtx->startSize           = numberOfColumns + 1;
        tempMtx->start               = new int[numberOfColumns + 1];
        tempMtx->valueType           = convertTo;
        for (int i=0; i <= numberOfColumns; i++)
            tempMtx->start[i] = 0;

        // augment column lengths block by block
        for (int i=0; i < currentBlocks->blockNumber; i++)
        {
            int c0 = currentBlocks->colOffset[currentBlocks->blockColumns[i]];
            int cN = currentBlocks->colOffset[currentBlocks->blockColumns[i]+1];
            for (int j = c0; j < cN; j++)
            {
                tempMtx->start[j+1] += ( currentBlocks->blocks[i]->start[j+1-c0] 
                                       - currentBlocks->blocks[i]->start[j  -c0] );
            }
        }

        for (int i=1; i <= numberOfColumns; i++)
            tempMtx->start[i] += tempMtx->start[i-1];
        tempMtx->valueSize = tempMtx->start[numberOfColumns];
        if (tempMtx->valueSize > 0)
            tempMtx->index = new int[tempMtx->valueSize];

        // allocate space to store value array
        if (!tempMtx->allocateValueArray(tempMtx->valueSize))
            throw ErrorClass("Error while allocating value array for expanded baseMatrix");

        // go through the blocks a second time to store values
        for (int i=0; i < currentBlocks->blockNumber; i++)
        {
            int c0 = currentBlocks->colOffset[currentBlocks->blockColumns[i]];
            int cN = currentBlocks->colOffset[currentBlocks->blockColumns[i]+1];
            int row_adj = currentBlocks->rowOffset[currentBlocks->blockRows[i]];

            for (int j = c0; j < cN; j++)
            {
                int loc = tempMtx->start[j];
                for (int k = currentBlocks->blocks[i]->start[j-c0];
                         k < currentBlocks->blocks[i]->start[j-c0+1]; k++)
                {
                    tempMtx->index[loc] = currentBlocks->blocks[i]->index[k] + row_adj;
                    if (!tempMtx->copyValue(currentBlocks->blocks[i], k, loc))
                        throw ErrorClass("Matrix expansion failed while copying element values");
                    loc++;
                }
                tempMtx->start[j] = loc;
            }
        }

        for (int i=numberOfColumns; i > 0; i--)
            tempMtx->start[i] =
                tempMtx->start[i-1];

        tempMtx->start[0] = 0;
        tempMtx->printMatrix();
        return tempMtx;
    }
    catch(const ErrorClass& eclass)
    {
        if (tempMtx != NULL)
            delete tempMtx;
        tempMtx = NULL;
        throw ErrorClass( eclass.errormsg);
    }
}// end of expandBlocks

GeneralSparseMatrix* MatrixType::expandBlocks( int nConst, OSMatrix** mtxIdx, bool rowMajor_,
                                               ENUM_MATRIX_TYPE convertTo_, 
                                               ENUM_MATRIX_SYMMETRY symmetry_)
{
    GeneralSparseMatrix* tempMtx = new GeneralSparseMatrix();
    try
    {
#ifndef NDEBUG
        osoutput->OSPrint(ENUM_OUTPUT_AREA_OSMatrix, ENUM_OUTPUT_LEVEL_trace, "Inside expandBlocks()");
#endif
        if (m_mChildren[nConst]->nType != ENUM_MATRIX_CONSTRUCTOR_TYPE_blocks)
            throw ErrorClass("expandBlocks(): Constructor does not have <blocks> type");

        // Here we have matching block partitions
        ExpandedMatrixBlocks* tmpBlocks = new ExpandedMatrixBlocks();

        ENUM_MATRIX_TYPE convertTo = convertTo_;
        ENUM_MATRIX_TYPE inferredType = getMatrixType();
        if (convertTo == ENUM_MATRIX_TYPE_unknown) 
            convertTo  = inferredType;
        if (convertTo != mergeMatrixType(convertTo, inferredType))
           throw ErrorClass("Requested improper conversion of element values");

        ENUM_MATRIX_SYMMETRY symmetry = symmetry_;

        if (symmetry == ENUM_MATRIX_SYMMETRY_default)
            symmetry  = this->symmetry;
        if (symmetry != this->symmetry)
        {
            if (this->symmetry == ENUM_MATRIX_SYMMETRY_default)
                this->symmetry  = symmetry;
            else
                throw ErrorClass("Cannot handle symmetry properly in expandBlocks()");
        }

        tmpBlocks->bDeleteArrays = false;
        tmpBlocks->valueType     = convertTo;
        tmpBlocks->isRowMajor    = rowMajor_;
        tmpBlocks->rowOffsetSize = sizeof(((MatrixBlocks*)m_mChildren[nConst])->rowOffset)/sizeof(int);
        tmpBlocks->colOffsetSize = sizeof(((MatrixBlocks*)m_mChildren[nConst])->colOffset)/sizeof(int);
        tmpBlocks->rowOffset     = new int[tmpBlocks->rowOffsetSize];
        tmpBlocks->colOffset     = new int[tmpBlocks->colOffsetSize];
        for (int kr=0; kr < tmpBlocks->rowOffsetSize; kr++)
            tmpBlocks->rowOffset[kr] = ((MatrixBlocks*)m_mChildren[nConst])->rowOffset->el[kr];
        for (int kc=0; kc < tmpBlocks->rowOffsetSize; kc++)
            tmpBlocks->colOffset[kc] = ((MatrixBlocks*)m_mChildren[nConst])->colOffset->el[kc];

        // Allocate memory
        tmpBlocks->blockNumber  = ((MatrixBlocks*)m_mChildren[nConst])->inumberOfChildren;
        tmpBlocks->blocks       = new GeneralSparseMatrix*[tmpBlocks->blockNumber];
        tmpBlocks->blockRows    = new int[tmpBlocks->blockNumber];
        tmpBlocks->blockColumns = new int[tmpBlocks->blockNumber];

        // access each block; expand and store pointers
        MatrixBlock* tmpChild;
        int tmpBlockNumber = 0;
        for (unsigned int j=0; j<((MatrixBlocks*)m_mChildren[nConst])->inumberOfChildren; j++)
        {
            tmpChild = (MatrixBlock*)((MatrixBlocks*)m_mChildren[nConst])->m_mChildren[j];
            int iBlock = tmpChild->getExpandedMatrix(mtxIdx, rowMajor_, convertTo, symmetry);
            if (iBlock < 0) 
                throw ErrorClass("One or more blocks could not be expanded");
            tmpBlocks->blocks[tmpBlockNumber] = tmpChild->expandedMatrixByElements[iBlock];
            tmpBlocks->blockRows[tmpBlockNumber]    = tmpChild->blockRowIdx;
            tmpBlocks->blockColumns[tmpBlockNumber] = tmpChild->blockColIdx;

#ifndef NDEBUG
            ((GeneralSparseMatrix*)tmpBlocks->blocks[tmpBlockNumber])->printMatrix();
#endif

            tmpBlockNumber++;
        }

        tempMtx->b_deleteStartArray  = true;
        tempMtx->b_deleteIndexArray  = true;
        tempMtx->b_deleteValueArray  = true;
        tempMtx->isRowMajor          = rowMajor_;
        tempMtx->symmetry            = symmetry;
        tempMtx->numberOfRows        = numberOfRows;
        tempMtx->numberOfColumns     = numberOfColumns;
        tempMtx->startSize           = numberOfColumns + 1;
        tempMtx->start               = new int[numberOfColumns + 1];
        tempMtx->valueType           = convertTo;
        for (int i=0; i <= numberOfColumns; i++)
            tempMtx->start[i] = 0;

        // augment column lengths block by block
        for (int i=0; i < tmpBlockNumber; i++)
        {
            int c0 = tmpBlocks->colOffset[tmpBlocks->blockColumns[i]];
            int cN = tmpBlocks->colOffset[tmpBlocks->blockColumns[i]+1];
            for (int j = c0; j < cN; j++)
            {
                tempMtx->start[j+1] += ( tmpBlocks->blocks[i]->start[j+1-c0] 
                                       - tmpBlocks->blocks[i]->start[j  -c0] );
            }
        }

        for (int i=1; i <= numberOfColumns; i++)
            tempMtx->start[i] += tempMtx->start[i-1];
        tempMtx->valueSize = tempMtx->start[numberOfColumns];
        if (tempMtx->valueSize > 0)
            tempMtx->index = new int[tempMtx->valueSize];

        // allocate space to store value array
        if (!tempMtx->allocateValueArray(tempMtx->valueSize))
            throw ErrorClass("Error while allocating value array for expanded baseMatrix");

        // go through the blocks a second time to store values
        for (int i=0; i < tmpBlockNumber; i++)
        {
            int c0      = tmpBlocks->colOffset[tmpBlocks->blockColumns[i]];
            int cN      = tmpBlocks->colOffset[tmpBlocks->blockColumns[i]+1];
            int row_adj = tmpBlocks->rowOffset[tmpBlocks->blockRows[i]];
    
            for (int j = c0; j < cN; j++)
            {
                int loc = tempMtx->start[j];
                for (int k = tmpBlocks->blocks[i]->start[j-c0];
                         k < tmpBlocks->blocks[i]->start[j-c0+1]; k++)
                {
                    tempMtx->index[loc] = tmpBlocks->blocks[i]->index[k] + row_adj;
                    tempMtx->copyValue(tmpBlocks->blocks[i],tmpBlocks->blocks[i]->index[k],loc);
                }
            }
        }
    
        for (int i=numberOfColumns; i > 0; i--)
            tempMtx->start[i] =
                tempMtx->start[i-1];
        tempMtx->start[0] = 0;

        tempMtx->printMatrix();

        return tempMtx;
    }
    catch(const ErrorClass& eclass)
    {
        // clear memory if already allocated
        if (tempMtx != NULL)
            delete tempMtx;
        tempMtx = NULL;
        throw ErrorClass( eclass.errormsg);
    }
}// end of expandBlocks


GeneralSparseMatrix* MatrixType::extractElements(int nConst, bool rowMajor, 
                                                 ENUM_MATRIX_SYMMETRY symmetry_)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSMatrix, ENUM_OUTPUT_LEVEL_trace, "Inside extractElements()");
#endif

    GeneralSparseMatrix* tempMtx = new GeneralSparseMatrix();

    try
    {
        if (!((MatrixElements*)m_mChildren[nConst])->rowMajor)
        {
            ENUM_MATRIX_SYMMETRY symmetry = symmetry_;

            if (symmetry == ENUM_MATRIX_SYMMETRY_default)
                symmetry  = this->symmetry;
            else
            {
                if (this->symmetry == ENUM_MATRIX_SYMMETRY_default)
                    this->symmetry  = symmetry;
                if (this->symmetry != symmetry)
                    throw ErrorClass("Cannot handle symmetry properly in extractElements()");
            }

            tempMtx->symmetry = symmetry;
            tempMtx->b_deleteStartArray = false;
            tempMtx->b_deleteIndexArray = false;
            tempMtx->b_deleteValueArray = false;
            tempMtx->isRowMajor = false;
            tempMtx->valueType  = m_mChildren[nConst]->getMatrixType();
            tempMtx->numberOfRows    = numberOfRows;
            tempMtx->numberOfColumns = numberOfColumns;
            tempMtx->startSize  = numberOfColumns + 1;
            tempMtx->valueSize  = ((MatrixElements*)m_mChildren[nConst])->numberOfValues;
            tempMtx->start      = ((MatrixElements*)m_mChildren[nConst])->start->el;
            tempMtx->index      = ((MatrixElements*)m_mChildren[nConst])->index->el;

            if (tempMtx->valueType == ENUM_MATRIX_TYPE_constant)
                tempMtx->value  = ((ConstantMatrixElements*)m_mChildren[nConst])->value;

            else if (tempMtx->valueType == ENUM_MATRIX_TYPE_varReference)
                tempMtx->value  = ((VarReferenceMatrixElements*)m_mChildren[nConst])->value;

            else if (tempMtx->valueType == ENUM_MATRIX_TYPE_linear)
                tempMtx->value  = ((LinearMatrixElements*)m_mChildren[nConst])->value;

            else if (tempMtx->valueType 
                    == ENUM_MATRIX_TYPE_realValuedExpressions)
                tempMtx->value  = ((RealValuedExpressions*)m_mChildren[nConst])->value;

            else if (tempMtx->valueType 
                    == ENUM_MATRIX_TYPE_complexValuedExpressions)
                tempMtx->value  = ((ComplexValuedExpressions*)m_mChildren[nConst])->value;

            else if (tempMtx->valueType == ENUM_MATRIX_TYPE_objReference)
                tempMtx->value  = ((ObjReferenceMatrixElements*)m_mChildren[nConst])->value;

            else if (tempMtx->valueType == ENUM_MATRIX_TYPE_conReference)
                tempMtx->value  = ((ConReferenceMatrixElements*)m_mChildren[nConst])->value;

            else if (tempMtx->valueType == ENUM_MATRIX_TYPE_string)
                tempMtx->value  = ((StringValuedMatrixElements*)m_mChildren[nConst])->value;

            else
                throw ErrorClass("Unknown element type in extractElements()");

            tempMtx->printMatrix();
            return tempMtx;
        }
        else // elements are given row-wise and must be "turned" 
        {

            if (symmetry != ENUM_MATRIX_SYMMETRY_none  && 
                symmetry != ENUM_MATRIX_SYMMETRY_default )
                throw ErrorClass("Cannot handle symmetry and transposition in extractElements()");

            MatrixElements* refMtx = (MatrixElements*)m_mChildren[nConst];

            tempMtx = new GeneralSparseMatrix();
            tempMtx->symmetry = symmetry;
            tempMtx->start = new int[numberOfColumns + 1];
            tempMtx->startSize = numberOfColumns + 1;
            tempMtx->valueType = m_mChildren[nConst]->getMatrixType();
            tempMtx->numberOfRows    = numberOfRows;
            tempMtx->numberOfColumns = numberOfColumns;

            for (int i=0; i <= numberOfColumns; i++)
                tempMtx->start[i] = 0;

            //if <value> is empty, return an empty matrix
            if (refMtx == NULL || refMtx->numberOfValues == 0)
            {
                tempMtx->valueSize = 0;
                tempMtx->printMatrix();
                return tempMtx;
            }

            tempMtx->valueSize = refMtx->numberOfValues;
            tempMtx->index = new int[refMtx->numberOfValues];

            int i, j, iTemp;

            for (i = 0; i < numberOfRows; i++)
            {
                for (j = refMtx->start->el[i]; j < refMtx->start->el[i + 1]; j++)
                {
                    tempMtx->start[refMtx->index->el[j] + 1] ++;
                }
            }
            tempMtx->start[0] = 0;

            for (i = 1; i <= numberOfColumns; i++ )
            {
                tempMtx->start[i] 
                    += tempMtx->start[i-1] ;
            }

            // store the elements, by type
            if (tempMtx->valueType == ENUM_MATRIX_TYPE_constant)
            {
                tempMtx->value = new ConstantMatrixValues();
                ((ConstantMatrixValues*)tempMtx->value)->el = new double[refMtx->numberOfValues];

                for (i = 0; i < numberOfRows; i++)
                {
                    // get row indices and values of the matrix
                    for (j = refMtx->start->el[i]; j < refMtx->start->el[ i + 1 ]; j++)
                    {
                        iTemp = tempMtx->start[refMtx->index->el[j]];
                        tempMtx->index[ iTemp] = i;
                        ((ConstantMatrixValues*)tempMtx->value)->el[ iTemp] 
                            = ((ConstantMatrixValues*)((ConstantMatrixElements*)refMtx)->value)->el[j];
                        tempMtx->start[refMtx->index->el[j]] ++;
                    }
                }
            }
            else if (tempMtx->valueType == ENUM_MATRIX_TYPE_varReference)
            {
                tempMtx->value = new VarReferenceMatrixValues();
                ((VarReferenceMatrixValues*)tempMtx->value)->el = new int[refMtx->numberOfValues];

                for (i = 0; i < numberOfRows; i++)
                {
                    // get row indices and values of the matrix
                    for (j = refMtx->start->el[i]; j < refMtx->start->el[ i + 1 ]; j++)
                    {
                        iTemp = tempMtx->start[refMtx->index->el[j]];
                        tempMtx->index[ iTemp] = i;
                        ((VarReferenceMatrixValues*)tempMtx->value)->el[ iTemp] 
                            = ((VarReferenceMatrixValues*)
                                ((VarReferenceMatrixElements*)refMtx)->value)->el[j];
                        tempMtx->start[refMtx->index->el[j]] ++;
                    }
                }
            }
            else if (tempMtx->valueType == ENUM_MATRIX_TYPE_linear)
            {
                tempMtx->value = new LinearMatrixValues();
                ((LinearMatrixValues*)tempMtx->value)->el 
                    = new LinearMatrixElement*[refMtx->numberOfValues];
                for (i = 0; i < refMtx->numberOfValues; i++)
                    ((LinearMatrixValues*)tempMtx->value)->el[i] = new LinearMatrixElement(); 

                for (i = 0; i < numberOfRows; i++)
                {
                    // get row indices and values of the matrix
                    for (j = refMtx->start->el[i]; j < refMtx->start->el[ i + 1 ]; j++)
                    {
                        iTemp = tempMtx->start[refMtx->index->el[j]];
                        tempMtx->index[ iTemp] = i;
                        if (!((LinearMatrixValues*)tempMtx->value)->
                                el[ iTemp]->deepCopyFrom(((LinearMatrixValues*)
                                    ((LinearMatrixElements*)refMtx)->value)->el[j]))
                            return NULL;
                        tempMtx->start[refMtx->index->el[j]] ++;
                    }
                }
            }
            else if (tempMtx->valueType == ENUM_MATRIX_TYPE_realValuedExpressions)
            {
                tempMtx->value = new RealValuedExpressionArray();
                ((RealValuedExpressionArray*)tempMtx->value)->el 
                    = new RealValuedExpressionTree*[refMtx->numberOfValues];
                for (i = 0; i < refMtx->numberOfValues; i++)
                {
                    ((RealValuedExpressionArray*)tempMtx->value)->el[i] = new RealValuedExpressionTree();
                }

                for (i = 0; i < numberOfRows; i++)
                {
                    // get row indices and values of the matrix
                    for (j = refMtx->start->el[i]; j < refMtx->start->el[ i + 1 ]; j++)
                    {
                        iTemp = tempMtx->start[refMtx->index->el[j]];
                        tempMtx->index[ iTemp] = i;

                        ((RealValuedExpressionArray*)tempMtx->value)->el[ iTemp]->m_treeRoot
                            = ((OSnLNode*)((RealValuedExpressionArray*)((RealValuedExpressions*)
                                refMtx)->value)->el[j]->m_treeRoot->cloneExprNode());

                        tempMtx->start[refMtx->index->el[j]] ++;
                    }
                }
            }

            else if (tempMtx->valueType == ENUM_MATRIX_TYPE_complexValuedExpressions)
            {
                tempMtx->value = new ComplexValuedExpressionArray();
                ((ComplexValuedExpressionArray*)tempMtx->value)->el 
                    = new ComplexValuedExpressionTree*[refMtx->numberOfValues];
                for (i = 0; i < refMtx->numberOfValues; i++)
                {
                    ((ComplexValuedExpressionArray*)tempMtx->value)->el[i]
                        = new ComplexValuedExpressionTree();
                }

                for (i = 0; i < numberOfRows; i++)
                {
                    // get row indices and values of the matrix
                    for (j = refMtx->start->el[i]; j < refMtx->start->el[ i + 1 ]; j++)
                    {
                        iTemp = tempMtx->start[refMtx->index->el[j]];
                        tempMtx->index[ iTemp] = i;
                        ((ComplexValuedExpressionArray*)tempMtx->value)->el[ iTemp]->m_treeRoot
                            = ((OSnLNode*)((ComplexValuedExpressionArray*)((ComplexValuedExpressions*)
                                refMtx)->value)->el[j]->m_treeRoot->cloneExprNode());
                        tempMtx->start[refMtx->index->el[j]] ++;
                    }
                }
            }

            else if (tempMtx->valueType == ENUM_MATRIX_TYPE_objReference)
            {
                tempMtx->value = new ObjReferenceMatrixValues();
                ((ObjReferenceMatrixValues*)tempMtx->value)->el = new int[refMtx->numberOfValues];

                for (i = 0; i < numberOfRows; i++)
                {
                    // get row indices and values of the matrix
                    for (j = refMtx->start->el[i]; j < refMtx->start->el[ i + 1 ]; j++)
                    {
                        iTemp = tempMtx->start[refMtx->index->el[j]];
                        tempMtx->index[ iTemp] = i;
                        ((ObjReferenceMatrixValues*)tempMtx->value)->el[ iTemp] 
                            = ((ObjReferenceMatrixValues*)
                                ((ObjReferenceMatrixElements*)refMtx)->value)->el[j];
                        tempMtx->start[refMtx->index->el[j]] ++;
                    }
                }
            }
            else if (tempMtx->valueType == ENUM_MATRIX_TYPE_conReference)
            {
                tempMtx->value = new ConReferenceMatrixValues();
                ((ConReferenceMatrixValues*)tempMtx->value)->el 
                    = new ConReferenceMatrixElement*[refMtx->numberOfValues];
                for (i = 0; i < refMtx->numberOfValues; i++)
                    ((ConReferenceMatrixValues*)tempMtx->value)->el[i] = new ConReferenceMatrixElement(); 

                for (i = 0; i < numberOfRows; i++)
                {
                    // get row indices and values of the matrix
                    for (j = refMtx->start->el[i]; j < refMtx->start->el[ i + 1 ]; j++)
                    {
                        iTemp = tempMtx->start[refMtx->index->el[j]];
                        tempMtx->index[ iTemp] = i;
                        if (!((ConReferenceMatrixValues*)tempMtx->value)->el[ iTemp]->
                                deepCopyFrom(((ConReferenceMatrixValues*)
                                             ((ConReferenceMatrixElements*)refMtx)->value)->el[j]))
                            return NULL;
                        tempMtx->start[refMtx->index->el[j]] ++;
                    }
                }
            }

            // readjust the starts
            for (i = numberOfColumns; i >= 1; i--)
            {
               tempMtx->start[i]
                    = tempMtx->start[i - 1];
            }

            tempMtx->start[0] = 0;
        }
        tempMtx->printMatrix();
        return tempMtx;
    }
    catch(const ErrorClass& eclass)
    {
        // clear memory if already allocated
        if (tempMtx != NULL)
            delete tempMtx;
        tempMtx = NULL;
        throw ErrorClass( eclass.errormsg);
    }
}// end of extractElements


GeneralSparseMatrix* MatrixType::expandTransformation(int nConst, OSMatrix** mtxIdx, bool rowMajor_, 
                                                      ENUM_MATRIX_TYPE convertTo_, 
                                                      ENUM_MATRIX_SYMMETRY symmetry_)
{
    ostringstream outStr;
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSMatrix,
                      ENUM_OUTPUT_LEVEL_trace, "Inside expandTransformation()");
    if (rowMajor_)
        outStr << "return matrix transformation in row major form" << std::endl;
    else    
        outStr << "return matrix transformation in column major form" << std::endl;
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSMatrix, ENUM_OUTPUT_LEVEL_trace, outStr.str());
#endif

    GeneralSparseMatrix* tempMtx = NULL;

    try
    {
        ENUM_MATRIX_TYPE convertTo = convertTo_;
        ENUM_MATRIX_TYPE inferredType = getMatrixType();
        if (convertTo == ENUM_MATRIX_TYPE_unknown) 
            convertTo  = inferredType;
        if (convertTo != mergeMatrixType(convertTo, inferredType))
           throw ErrorClass("Requested improper conversion of element values");

        ENUM_MATRIX_SYMMETRY symmetry = symmetry_;

        if (symmetry == ENUM_MATRIX_SYMMETRY_default)
            symmetry  = this->symmetry;
        if (symmetry != this->symmetry)
        {
            if (this->symmetry == ENUM_MATRIX_SYMMETRY_default)
                this->symmetry  = symmetry;
            else
                throw ErrorClass("Cannot handle symmetry properly in expandTransformation()");
        }

        tempMtx = ((MatrixTransformation*)
                    m_mChildren[nConst])->transformation->expandNode(mtxIdx, rowMajor_, 
                                                                     convertTo, symmetry);

        if (tempMtx == NULL)
            throw ErrorClass("Error while expanding a matrix transformation");

        if ( (tempMtx->numberOfRows    > numberOfRows)   || 
             (tempMtx->numberOfColumns > numberOfColumns) )
            throw ErrorClass("Matrix transformation exceeds allocated dimensions");

        if (  tempMtx->numberOfColumns < numberOfColumns  )
        // pad start array --- for now throw an error
            throw ErrorClass("Matrix transformation does not cover allocated dimensions");

        tempMtx->b_deleteStartArray = false;
        tempMtx->b_deleteIndexArray = false;
        tempMtx->b_deleteValueArray = false;
        tempMtx->isRowMajor         = false;
        tempMtx->symmetry           = symmetry;
        tempMtx->numberOfRows       = numberOfRows;
        tempMtx->numberOfColumns    = numberOfColumns;

        return tempMtx;
    }
    catch(const ErrorClass& eclass)
    {
        // clear memory if already allocated
        if (tempMtx != NULL)
            delete tempMtx;
        tempMtx = NULL;
        throw ErrorClass( eclass.errormsg);
    }
}// end of expandTransformation


int MatrixType::getExpandedMatrix(OSMatrix** mtxIdx, bool rowMajor_, 
                                  ENUM_MATRIX_TYPE convertTo_,
                                  ENUM_MATRIX_SYMMETRY symmetry_)
{
    ostringstream outStr;
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSMatrix, ENUM_OUTPUT_LEVEL_debug, "Inside getExpandedMatrix()");
    if (rowMajor_)
        outStr << "return matrix elements in row major form" << std::endl;
    else    
        outStr << "return matrix elements in column major form" << std::endl;
    if (convertTo_ != ENUM_MATRIX_TYPE_unknown)
        outStr << " - convert to " << returnMatrixTypeString(convertTo_);
    outStr << std::endl;
    outStr << "expand an object of kind " << returnMatrixConstructorTypeString(nType);
    outStr << " - declared type " << returnMatrixTypeString(getDeclaredMatrixType());
    outStr << " - inferred type " << returnMatrixTypeString(getInferredMatrixType());
    outStr << std::endl << std::endl;
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSMatrix, ENUM_OUTPUT_LEVEL_trace, outStr.str());
#endif

    GeneralSparseMatrix* tempMtx = NULL;

    // these two dense columns track the locations of elements durng the merge
    int* ctorNbr  = NULL;
    int* location = NULL;

    try
    {
        ENUM_MATRIX_TYPE convertTo = convertTo_;
        ENUM_MATRIX_TYPE inferredType = getMatrixType();
        if (convertTo == ENUM_MATRIX_TYPE_unknown) 
            convertTo  = inferredType;
        if (convertTo != mergeMatrixType(convertTo, inferredType))
           throw ErrorClass("Requested improper conversion of element values");

        ENUM_MATRIX_SYMMETRY symmetry = symmetry_;

        if (symmetry == ENUM_MATRIX_SYMMETRY_default)
            symmetry  = this->symmetry;
        if (symmetry != this->symmetry)
        {
            if (this->symmetry == ENUM_MATRIX_SYMMETRY_default)
                this->symmetry  = symmetry;
            else
                throw ErrorClass("Cannot handle symmetry properly in getExpandedMatrix()");
        }

        //Check if previous expansion available
        int bestMatch = 0;
        int thisMatch;
        int bestMatch_index = -1;
        for (int i=0; i<expandedMatrixByElements.size(); i++)
        {
            thisMatch = 0;
            if (expandedMatrixByElements[i]->valueType == convertTo)
            {
                thisMatch += 1; 
            }
            if (expandedMatrixByElements[i]->isRowMajor == rowMajor_)
            {
                thisMatch += 2; 
            }
            if (expandedMatrixByElements[i]->symmetry == symmetry)
            {
                thisMatch += 4;
            }
            if (thisMatch > bestMatch)
            {
                if (thisMatch == 7) // a previous expansion meets all criteria; just use it
                    return /*expandedMatrixByElements[*/i/*]*/;

                bestMatch = thisMatch;
                bestMatch_index = i;
            }
        }

        // Here we need to create a new expansion and add it to the collection

        tempMtx = new GeneralSparseMatrix(); // leaks memory
        tempMtx->numberOfRows    = numberOfRows;
        tempMtx->numberOfColumns = numberOfColumns;

        if (bestMatch > 0) // base the expansion on previous work
        {
            switch (bestMatch)
            {
// cases 1-3 will rely on    GeneralSparseMatrix* convertSymmetry(ENUM_MATRIX_SYMMETRY symmetry_);
                case 1: //Transpose, then apply symmetry --- Can this be done in one operation?
                    throw ErrorClass("Requested conversion not yet implemented");
                    break;
                case 2: //Convert type and apply symmetry --- this should be doable in one operation
                    throw ErrorClass("Requested conversion not yet implemented");
                    break;
                case 3: //Just apply symmetry --- this is a simple copy operation
                    throw ErrorClass("Requested conversion not yet implemented");
                    break;
                case 4: //Transpose and convert
                case 5: //Transpose only
                    tempMtx = expandedMatrixByElements[bestMatch_index]
                                        ->convertToOtherMajor(convertTo,false);
                    break;
                case 6: //Just convert type
                    tempMtx = expandedMatrixByElements[bestMatch_index]->convertType(convertTo);
                    break;
            }

            tempMtx->valueType  = convertTo;
            tempMtx->symmetry   = symmetry;
            tempMtx->isRowMajor = rowMajor_;
            expandedMatrixByElements.push_back(tempMtx);
            return expandedMatrixByElements.size() - 1; //tempMtx;

        }

        // Here we need to expand from scratch

        // The complexity increases with the number and diversity of constructors

        // Start by checking for empty matrix
        if (inumberOfChildren == 0)
        {
            if (rowMajor_)
                tempMtx->startSize   = numberOfRows + 1;
            else
                tempMtx->startSize   = numberOfColumns + 1;
            tempMtx->symmetry        = symmetry;
            tempMtx->start           = new int[tempMtx->startSize];
            tempMtx->valueSize       = 0;
            tempMtx->valueType       = ENUM_MATRIX_TYPE_empty;
            this->inferredMatrixType = ENUM_MATRIX_TYPE_empty;
            for (int i=0; i < tempMtx->startSize; i++)
                tempMtx->start[i] = 0;
        }

        // single constructor --- process by type
        else if (inumberOfChildren == 1)
        {
            if (m_mChildren[0]->getNodeType() == ENUM_MATRIX_CONSTRUCTOR_TYPE_baseMatrix)
            {
                tempMtx = this->processBaseMatrix(mtxIdx, rowMajor_, ENUM_MATRIX_TYPE_unknown, symmetry);
                tempMtx->valueType       = m_mChildren[0]->getMatrixType();
                this->inferredMatrixType = m_mChildren[0]->getMatrixType();
            }

            else if (m_mChildren[0]->getNodeType() == ENUM_MATRIX_CONSTRUCTOR_TYPE_blocks)
            {
                //make sure the blocks have been expanded, then retrieve them 
                if (!processBlocks(mtxIdx, rowMajor_, tempMtx->valueType, symmetry))
                    throw ErrorClass("error processing blocks in getExpandedMatrix()");

                ExpandedMatrixBlocks* currentBlocks
                    = getBlocks(m_miRowPartition, m_iRowPartitionSize, m_miColumnPartition,
                                m_iColumnPartitionSize, mtxIdx, true, rowMajor_, convertTo, symmetry);

                tempMtx = expandBlocks(currentBlocks, mtxIdx, rowMajor_, convertTo, symmetry);
            }

            else if (m_mChildren[0]->getNodeType() == ENUM_MATRIX_CONSTRUCTOR_TYPE_transformation)
            {
//              transformation: see if we can do at least AB, A'B, AB'
                tempMtx = expandTransformation(0, mtxIdx, rowMajor_, convertTo, symmetry);
            }
            else // some kind of elements 
            {
                tempMtx = this->extractElements(0,rowMajor_,symmetry);
                this->inferredMatrixType = tempMtx->valueType;
//                expandedMatrixInColumnMajorForm->printMatrix();
            }
        }
        else // two or more constructors --- worry about overwriting and number of elements
        {
            // Here we have (base matrix plus) elements
//            if (!matrixHasTransformations() && !matrixHasBlocks() )
//            {
//            expandedMatrixInColumnMajorForm = new GeneralSparseMatrix();
            tempMtx->symmetry = symmetry;
            if (rowMajor_)
                tempMtx->startSize = numberOfRows + 1;
            else
                tempMtx->startSize = numberOfColumns + 1;
            tempMtx->start = new int[tempMtx->startSize];

            GeneralSparseMatrix** tempExpansion = new GeneralSparseMatrix*[inumberOfChildren];

            //estimate number of elements --- assume all different
            int  nv = 0;
            int  i0 = 0;
            bool haveBase = false;
            ENUM_MATRIX_TYPE inferredType = getMatrixType(); //ENUM_MATRIX_TYPE_unknown;

            if (m_mChildren[0]->getNodeType() == ENUM_MATRIX_CONSTRUCTOR_TYPE_baseMatrix)
            {
                OSMatrix* baseMtxPtr = ((BaseMatrix*)m_mChildren[0])->baseMatrix;
                tempExpansion[0]
                    = this->processBaseMatrix(mtxIdx, true, ENUM_MATRIX_TYPE_unknown, symmetry);
                if (tempExpansion[0] != NULL)
                {
                    nv = tempExpansion[0]->valueSize;
                    haveBase = true;
                }
                i0 = 1;
            }

            for (unsigned int i=i0; i < inumberOfChildren; i++)
            {
                if (m_mChildren[i]->getNodeType() == ENUM_MATRIX_CONSTRUCTOR_TYPE_transformation)
                {
                    tempExpansion[i] = expandTransformation(i, mtxIdx, rowMajor_, convertTo, symmetry);
                }
                else if (m_mChildren[i]->getNodeType() == ENUM_MATRIX_CONSTRUCTOR_TYPE_blocks)
                {
                    //make sure the blocks have been expanded, then retrieve them 
                    if (!processBlocks(mtxIdx, rowMajor_, tempMtx->valueType, symmetry))
                        throw ErrorClass("error processing blocks in getExpandedMatrix()");

                    ExpandedMatrixBlocks* currentBlocks
                        = getBlocks(m_miRowPartition, m_iRowPartitionSize, m_miColumnPartition,
                                    m_iColumnPartitionSize, mtxIdx, true, rowMajor_, convertTo, symmetry);

                    tempExpansion[i] = expandBlocks(currentBlocks, mtxIdx, rowMajor_, convertTo, symmetry);
                }
                else
                {
                    tempExpansion[i] = this->extractElements(i,rowMajor_, symmetry);
                    tempExpansion[i]->valueType = m_mChildren[i]->getMatrixType();
                }

#ifndef NDEBUG
                tempExpansion[i]->printMatrix();
#endif
                nv += tempExpansion[i]->valueSize;;
            }

            if (nv > numberOfRows*numberOfColumns) nv = numberOfRows*numberOfColumns;

            if (convertTo == ENUM_MATRIX_TYPE_unknown) 
                convertTo  = inferredType;
            if (convertTo != mergeMatrixType(convertTo, inferredType))
               throw ErrorClass("Requested improper conversion of element values");
            inferredType = convertTo;
            tempMtx->valueType = inferredType;
                
            // allocate space for elements (nv is an overestimate --- don't worry about cancelations)
            // should use vectors eventually...

            tempMtx->index = new int[nv];
            if (!tempMtx->allocateValueArray(nv))
                throw ErrorClass("Error allocating value array of a GeneralSparseMatrix");

            // allocate and initial two dense columns of locations of elements 
            // If the merged matrix has a nonzero in row i of the current column,
            // ctorNbr[i] gives the number of the constructor whose value is used
            // location[i] gives the location of the nonzero within this constructor 
            ctorNbr  = new int[numberOfRows];
            location = new int[numberOfRows];

            for (int i=0; i < numberOfRows; i++)
            {
                 ctorNbr[i] = -1;
                location[i] = -1;
            }

            int nz = 0;
            tempMtx->start[0] = 0;

            // Access nonzeros column by column
            for (int j=0; j < tempMtx->startSize-1; j++)
            {
                // First pass --- record nonzeros
                for (unsigned int i=0; i < inumberOfChildren; i++)
                {
                    // if constructor i has a nonzero, it overrides previous information
                    for (int k = tempExpansion[i]->start[j]; 
                             k < tempExpansion[i]->start[j+1]; k++)
                    {
                        location[tempExpansion[i]->index[k]] = k;
                         ctorNbr[tempExpansion[i]->index[k]] = i;
                    }
                }

#ifndef NDEBUG
                outStr.str("");
                outStr.clear();
                outStr << "Locations   for column " << j << ":";
                for (int i=0; i < numberOfRows; i++)
                    outStr << "  "  << location[i];
                outStr << std::endl << std::endl;
                outStr << "Constructor for column " << j << ":";
                for (int i=0; i < numberOfRows; i++)
                    outStr << "  "  << ctorNbr[i];
                outStr << std::endl << std::endl;
                osoutput->OSPrint(ENUM_OUTPUT_AREA_OSMatrix, 
                    ENUM_OUTPUT_LEVEL_detailed_trace, outStr.str());
#endif
                // Second pass --- retrieve nonzeros and store --- Note: Deep copy!
                int l, n;

                for (int i=0; i < numberOfRows; i++)
                {
                    if (location[i] >= 0)
                    {
                        l = location[i];
                        n =  ctorNbr[i];
                        tempMtx->index[nz] = tempExpansion[n]->index[l];

                        if (!tempMtx->copyValue(tempExpansion[n], l, nz))
                            throw ErrorClass("Matrix expansion failed while copying element values");

                        nz++;

                        // "turn out the lights" for the next column
                        location[i] = -1;
                         ctorNbr[i] = -1;
                    }// end if (location[i] >= 0)
                }// end for (int i=0; i < numberOfRows; i++)

                tempMtx->start[j+1] = nz;
            }

            tempMtx->valueSize = nz;

            delete [] location;
            delete []  ctorNbr;

/*
        blocks should be doable --- but worry about cancellations
        maybe transformation (product) plus elements
        others: throw error
*/
//            else
//                throw ErrorClass(
//                    "Multiple constructors with transformations and blocks not yet implemented in getExpandedMatrix()");
        }
#ifndef NDEBUG
        tempMtx->printMatrix();
#endif
        expandedMatrixByElements.push_back(tempMtx);
        return expandedMatrixByElements.size() - 1;
    }//end try
    catch(const ErrorClass& eclass)
    {
        // clear memory if already allocated
        if (tempMtx != NULL)
            delete tempMtx;
        tempMtx = NULL;
        if (location != NULL)
            delete [] location;
        location = NULL;
        if (ctorNbr != NULL)
            delete []  ctorNbr;
        ctorNbr = NULL;
//        throw ErrorClass( eclass.errormsg);
        osoutput->OSPrint(ENUM_OUTPUT_AREA_OSMatrix, ENUM_OUTPUT_LEVEL_error, eclass.errormsg);
        return -1;
    }
}// end of getExpandedMatrix


bool MatrixType::expandElements(OSMatrix** mtxIdx, bool rowMajor)
{
    return NULL;
}// end of expandElements


bool MatrixType::printExpandedMatrix(int idx)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSMatrix, ENUM_OUTPUT_LEVEL_trace,
        "Inside printExpandedMatrix()");
#endif
    std::ostringstream outStr;
    try
    {
        if (idx < 0 || idx >= expandedMatrixByElements.size())
            throw ErrorClass("Invalid index value for printExpandedMatrix()");

        GeneralSparseMatrix* tmp = expandedMatrixByElements[idx];

        outStr << std::endl;

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
        outStr << "type of nonzeros   " << returnMatrixTypeString(tmp->valueType) << std::endl;
        outStr << "symmetry           " << returnMatrixSymmetryString(symmetry) << std::endl;

        outStr << std::endl << "These matrix arrays are organized ";             
        if (tmp->isRowMajor)
            outStr << "by rows" << std::endl;
        else
            outStr << "by columns" << std::endl;

        outStr << std::endl << "starts: ";
        for (int i=0; i < tmp->startSize; i++)
            outStr << "  " << tmp->start[i];
        outStr << std::endl;

        outStr << std::endl << "indexes:";
        for (int i=0; i < tmp->valueSize; i++)
            outStr << "  " << tmp->index[i];
        outStr << std::endl;

        outStr << std::endl << "values: ";
        if (tmp->valueType == ENUM_MATRIX_TYPE_constant)
        {
            for (int i=0; i < tmp->valueSize; i++)
                outStr << "  " << ((ConstantMatrixValues*)tmp->value)->el[i];
            outStr << std::endl;
        }
        else if (tmp->valueType == ENUM_MATRIX_TYPE_varReference)
        {
            for (int i=0; i < tmp->valueSize; i++)
                outStr << "  " << ((VarReferenceMatrixValues*)tmp->value)->el[i];
            outStr << std::endl;
        }
        else if (tmp->valueType == ENUM_MATRIX_TYPE_objReference) 
        {
            for (int i=0; i < tmp->valueSize; i++)
                outStr << "  " << ((ObjReferenceMatrixValues*)tmp->value)->el[i];
            outStr << std::endl;
        }
        else if (tmp->valueType == ENUM_MATRIX_TYPE_conReference) 
        {
            for (int i=0; i < tmp->valueSize; i++)
                outStr << "  " << ((ConReferenceMatrixValues*)tmp->value)->el[i]->conReference;
            outStr << std::endl;
        }
        else if (tmp->valueType == ENUM_MATRIX_TYPE_realValuedExpressions) 
        {
            std::vector<ExprNode*> postfixVec;
            outStr << std::endl;
            for (int i=0; i < tmp->valueSize; i++)
            {
                if (((RealValuedExpressionArray*)tmp->value)->el[i] != NULL)
                {
                    postfixVec = 
                        ((RealValuedExpressionArray*)tmp->value)->el[i]->getPostfixFromExpressionTree();
                    outStr << "element " << i << ": " 
                           << getExpressionTreeAsInfixString(postfixVec) << std::endl;
                }
            }
            outStr << std::endl;
        }
        else if (tmp->valueType == ENUM_MATRIX_TYPE_complexValuedExpressions) 
        {
            std::vector<ExprNode*> postfixVec;
            outStr << std::endl;
            for (int i=0; i < tmp->valueSize; i++)
            {
                if (((ComplexValuedExpressionArray*)tmp->value)->el[i] != NULL)
                {
                    postfixVec = 
                        ((ComplexValuedExpressionArray*)tmp->value)->el[i]->getPostfixFromExpressionTree();
                    outStr << "element " << i << ": " 
                           << getExpressionTreeAsInfixString(postfixVec) << std::endl;
                }
            }
            outStr << std::endl;
        }
        else if (tmp->valueType == ENUM_MATRIX_TYPE_linear) 
        {
            outStr << std::endl;
            for (int i=0; i < tmp->valueSize; i++)
            {
                outStr << "element " << i << ": ";

                double c = ((LinearMatrixElement*)((LinearMatrixValues*)tmp->value)->el[i])->constant;
                int    m = ((LinearMatrixElement*)((LinearMatrixValues*)tmp->value)->el[i])->numberOfVarIdx;
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
                    temp = ((LinearMatrixElement*)((LinearMatrixValues*)tmp->value)->el[i])->varIdx[j];
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
}// end of printExpandedMatrix(int idx)

#if 0
GeneralSparseMatrix* MatrixType::convertToOtherMajor(bool isColumnMajor)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSMatrix, ENUM_OUTPUT_LEVEL_trace, "Inside convertToOtherMajor()");
#endif
    GeneralSparseMatrix* refMtx;
    if (isColumnMajor)
    {
        refMtx = expandedMatrixInColumnMajorForm;
        if (expandedMatrixInRowMajorForm != NULL) return expandedMatrixInRowMajorForm;
    }
    else
    {
        refMtx = expandedMatrixInRowMajorForm;
        if (expandedMatrixInColumnMajorForm != NULL) return expandedMatrixInColumnMajorForm;
    }
    if (refMtx == NULL ) return NULL;
    if (refMtx->start == NULL || refMtx->startSize <= 1 ) return NULL;

    int iStartSize = isColumnMajor ? numberOfRows+1 : numberOfColumns+1;
    GeneralSparseMatrix *matrix
        = new GeneralSparseMatrix( !isColumnMajor, numberOfRows, numberOfColumns, 
                                   iStartSize, refMtx->valueSize, refMtx->valueType);

    int i,j, iTemp;
    int iNumSource = refMtx->startSize - 1;

    int* miStart = matrix->start;
    int* miIndex = matrix->index;

    for ( i = 1; i < iStartSize; i++)
    {
        miStart [ i ] = 0;
    }
    // for illustration assume we are converting from column to row major
    // i is indexing columns and j is indexing row numbers
    for (i = 0; i < iNumSource; i++)
    {
        for (j = refMtx->start[i]; j < refMtx->start[ i + 1 ]; j++)
        {
            // index[ j] is a row index, we have just found an occurrence of row index[j]
            // therefore we increase by 1 (or push back) the start of the row indexed by index[j] + 1,
            // i.e. the start of the next row
            miStart[refMtx->index[j] + 1] ++;
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
    if ( refMtx->valueType == ENUM_MATRIX_TYPE_constant)
    {
        matrix->value = new ConstantMatrixValues();
        ((ConstantMatrixValues*)matrix->value)->el = new double[refMtx->valueSize];

        for (i = 0; i < iNumSource; i++)
        {
            // get row indices and values of the matrix
            for (j = refMtx->start[i]; j < refMtx->start[ i + 1 ]; j++)
            {
                iTemp = miStart[refMtx->index[j]];
                miIndex [ iTemp] = i;
                ((ConstantMatrixValues*)matrix->value)->el[ iTemp] 
                    = ((ConstantMatrixValues*)refMtx->value)->el[j];
                miStart[refMtx->index[j]] ++;
            }
        }
    }
    else if (refMtx->valueType == ENUM_MATRIX_TYPE_varReference)
    {
        matrix->value = new VarReferenceMatrixValues();
        ((VarReferenceMatrixValues*)matrix->value)->el = new int[refMtx->valueSize];

        for (i = 0; i < iNumSource; i++)
        {
            // get row indices and values of the matrix
            for (j = refMtx->start[i]; j < refMtx->start[ i + 1 ]; j++)
            {
                iTemp = miStart[refMtx->index[j]];
                miIndex [ iTemp] = i;
                ((VarReferenceMatrixValues*)matrix->value)->el[ iTemp] 
                    = ((VarReferenceMatrixValues*)refMtx->value)->el[j];
                miStart[refMtx->index[j]] ++;
            }
        }
    }
    else if (refMtx->valueType == ENUM_MATRIX_TYPE_linear)
    {
        matrix->value = new LinearMatrixValues();
        ((LinearMatrixValues*)matrix->value)->el = new LinearMatrixElement*[refMtx->valueSize];
        for (i = 0; i < refMtx->valueSize; i++)
            ((LinearMatrixValues*)matrix->value)->el[i] = new LinearMatrixElement();

        for (i = 0; i < iNumSource; i++)
        {
            // get row indices and values of the matrix
            for (j = refMtx->start[i]; j < refMtx->start[ i + 1 ]; j++)
            {
                iTemp = miStart[refMtx->index[j]];
                miIndex [ iTemp] = i;
                if (!((LinearMatrixValues*)matrix->value)->el[ iTemp]->deepCopyFrom(((LinearMatrixValues*)refMtx->value)->el[j]))
                    return NULL;
                miStart[refMtx->index[j]] ++;
            }
        }
    }
    else if (refMtx->valueType == ENUM_MATRIX_TYPE_realValuedExpressions)
    {
        matrix->value = new RealValuedExpressionArray();
        ((RealValuedExpressionArray*)matrix->value)->el = new RealValuedExpressionTree*[refMtx->valueSize];
        for (i = 0; i < refMtx->valueSize; i++)
        {
            ((RealValuedExpressionArray*)matrix->value)->el[i] = new RealValuedExpressionTree();
        }
        for (i = 0; i < iNumSource; i++)
        {
            // get row indices and values of the matrix
            for (j = refMtx->start[i]; j < refMtx->start[ i + 1 ]; j++)
            {
                iTemp = miStart[refMtx->index[j]];
                miIndex [ iTemp] = i;
                ((RealValuedExpressionArray*)matrix->value)->el[ iTemp]->m_treeRoot
                    = ((OSnLNode*)((RealValuedExpressionArray*)refMtx->value)->el[j]->m_treeRoot->cloneExprNode());
                miStart[refMtx->index[j]] ++;
            }
        }
    }
    else if (refMtx->valueType == ENUM_MATRIX_TYPE_complexValuedExpressions)
    {
        matrix->value = new ComplexValuedExpressionArray();
        ((ComplexValuedExpressionArray*)matrix->value)->el = new ComplexValuedExpressionTree*[refMtx->valueSize];
        for (i = 0; i < refMtx->valueSize; i++)
        {
            ((ComplexValuedExpressionArray*)matrix->value)->el[i] = new ComplexValuedExpressionTree();
        }
        for (i = 0; i < iNumSource; i++)
        {
            // get row indices and values of the matrix
            for (j = refMtx->start[i]; j < refMtx->start[ i + 1 ]; j++)
            {
                iTemp = miStart[refMtx->index[j]];
                miIndex [ iTemp] = i;
                ((ComplexValuedExpressionArray*)matrix->value)->el[ iTemp]->m_treeRoot
                    = ((OSnLNode*)((ComplexValuedExpressionArray*)refMtx->value)->el[j]->m_treeRoot->cloneExprNode());
                miStart[refMtx->index[j]] ++;
            }
        }
    }
    else if (refMtx->valueType == ENUM_MATRIX_TYPE_objReference)
    {
        matrix->value = new ObjReferenceMatrixValues();
        ((ObjReferenceMatrixValues*)matrix->value)->el = new int[refMtx->valueSize];

        for (i = 0; i < iNumSource; i++)
        {
            // get row indices and values of the matrix
            for (j = refMtx->start[i]; j < refMtx->start[ i + 1 ]; j++)
            {
                iTemp = miStart[refMtx->index[j]];
                miIndex [ iTemp] = i;
                ((ObjReferenceMatrixValues*)matrix->value)->el[ iTemp] 
                    = ((ObjReferenceMatrixValues*)refMtx->value)->el[j];
                miStart[refMtx->index[j]] ++;
            }
        }
    }
    else if (refMtx->valueType == ENUM_MATRIX_TYPE_conReference)
    {
        matrix->value = new ConReferenceMatrixValues();
        ((ConReferenceMatrixValues*)matrix->value)->el 
            = new ConReferenceMatrixElement*[refMtx->valueSize];
        for (i = 0; i < refMtx->valueSize; i++)
            ((ConReferenceMatrixValues*)matrix->value)->el[i] = new ConReferenceMatrixElement();

        for (i = 0; i < iNumSource; i++)
        {
            // get row indices and values of the matrix
            for (j = refMtx->start[i]; j < refMtx->start[ i + 1 ]; j++)
            {
                iTemp = miStart[refMtx->index[j]];
                miIndex [ iTemp] = i;
                if (!((ConReferenceMatrixValues*)matrix->value)->el[ iTemp]->deepCopyFrom(((ConReferenceMatrixValues*)refMtx->value)->el[j]))
                    return NULL;
                miStart[refMtx->index[j]] ++;
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
#endif

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
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSMatrix, ENUM_OUTPUT_LEVEL_trace, "Inside processBlockPartition()");
#endif
    if (matrixHasBlocks())
    {
        int nPartitions = 0;
        int imerge_R;
        int imerge_C;

        for (unsigned int i=0; i < inumberOfChildren; i++)
        {
            if (m_mChildren[i]->nType == ENUM_MATRIX_CONSTRUCTOR_TYPE_blocks)
            {
std::cout << "child node " << i << " has kind " << returnMatrixConstructorTypeString(m_mChildren[i]->nType);
std::cout  << " - declared type " << returnMatrixTypeString(m_mChildren[i]->getDeclaredMatrixType());
std::cout  << " - inferred type " << returnMatrixTypeString(m_mChildren[i]->getInferredMatrixType());
std::cout  << std::endl << std::endl;
                if (nPartitions == 0)
                {
                    // first blocks constructor. Set up data structures
                    nPartitions++;
                    m_iRowPartitionSize = ((MatrixBlocks*)m_mChildren[i])->rowOffset->numberOfEl;
                    m_miRowPartition = new int[m_iRowPartitionSize];
                    for (int j=0; j<m_iRowPartitionSize; j++)
                        m_miRowPartition[j] = ((MatrixBlocks*)m_mChildren[i])->rowOffset->el[j];
                    m_iColumnPartitionSize = ((MatrixBlocks*)m_mChildren[i])->colOffset->numberOfEl;
                    m_miColumnPartition = new int[m_iColumnPartitionSize];
                    for (int j=0; j<m_iColumnPartitionSize; j++)
                        m_miColumnPartition[j] = ((MatrixBlocks*)m_mChildren[i])->colOffset->el[j];
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
                        if (m_miRowPartition[i0] == ((MatrixBlocks*)m_mChildren[i])->rowOffset->el[itemp])
                        {
                            if (imerge_R != i0) m_miRowPartition[imerge_R] = m_miRowPartition[i0];
                            i0++;
                            itemp++;
                            imerge_R++;
                        }
                        else
                        {
                            if (m_miRowPartition[i0] < 
                                    ((MatrixBlocks*)m_mChildren[i])->rowOffset->el[itemp])
                                i0++;
                            else
                                itemp++;
                        }
                        if (i0 >= m_iRowPartitionSize || 
                                itemp >= ((MatrixBlocks*)m_mChildren[i])->rowOffset->numberOfEl)
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
                                ((MatrixBlocks*)m_mChildren[i])->colOffset->el[itemp])
                        {
                            if (imerge_C != i0) m_miColumnPartition[imerge_C] = m_miColumnPartition[i0];
                            i0++;
                            itemp++;
                            imerge_C++;
                        }
                        else
                        {
                            if (m_miColumnPartition[i0] < 
                                    ((MatrixBlocks*)m_mChildren[i])->colOffset->el[itemp])
                                i0++;
                            else
                                itemp++;
                        }
                        if (i0 >= m_iColumnPartitionSize || 
                                itemp >= ((MatrixBlocks*)m_mChildren[i])->colOffset->numberOfEl)
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

GeneralSparseMatrix* 
    MatrixType::getMatrixBlockInColumnMajorForm(int columnIdx, int rowIdx, ENUM_MATRIX_TYPE convertTo)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSMatrix, ENUM_OUTPUT_LEVEL_trace,
        "Inside getMatrixBlockInColumnMajorForm()");
#endif
    return NULL;
}// end of MatrixType::getMatrixBlockInColumnMajorForm

ExpandedMatrixBlocks* MatrixType::getBlocks(int* rowPartition, int rowPartitionSize, 
                                            int* colPartition, int colPartitionSize, 
                                            OSMatrix** mtxIdx, bool appendToBlockArray, bool rowMajor,
                                            ENUM_MATRIX_TYPE convertTo_, ENUM_MATRIX_SYMMETRY symmetry_)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSMatrix, ENUM_OUTPUT_LEVEL_trace, "Inside getBlocks()");
#endif

    // Try to find a collection of blocks that matches the criteria 
    for (unsigned int kount = 0; kount < expandedMatrixByBlocks.size(); kount++)
    {
        if (rowPartitionSize != expandedMatrixByBlocks[kount]->rowOffsetSize ||       
            colPartitionSize != expandedMatrixByBlocks[kount]->colOffsetSize ||
            rowMajor         != expandedMatrixByBlocks[kount]->isRowMajor)
            continue;
        
        for (int i=0; i < rowPartitionSize; i++)
            if (rowPartition[i] != expandedMatrixByBlocks[kount]->rowOffset[i])
                continue;
        for (int i=0; i < colPartitionSize; i++)
            if (colPartition[i] != expandedMatrixByBlocks[kount]->colOffset[i])
                continue;

        return expandedMatrixByBlocks[kount];
    }

    // not found; create a new collection
    if (!appendToBlockArray)
        throw ErrorClass("getBlocks(): Cannot determine a suitable collection");

    if (!processBlocks(mtxIdx, rowPartition, rowPartitionSize,
                               colPartition, colPartitionSize, rowMajor, convertTo_, symmetry_) )
       return NULL;
    return expandedMatrixByBlocks.back();
}// end of MatrixType::getBlocks

/*
ExpandedMatrixBlocks* getBlocks(int i, bool appendToBlockArray, bool rowMajor, 
                                    ENUM_MATRIX_TYPE convertTo_ = ENUM_MATRIX_TYPE_unknown,
                                    ENUM_MATRIX_SYMMETRY symmetry_ = ENUM_MATRIX_SYMMETRY_none)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSMatrix, ENUM_OUTPUT_LEVEL_trace, "Inside getBlocks()");
#endif

    // Try to find a collection of blocks that matches the criteria 
    for (unsigned int kount = 0; kount < expandedMatrixByBlocks.size(); kount++)
    {
        if (rowPartitionSize != expandedMatrixByBlocks[kount]->rowOffsetSize ||       
            colPartitionSize != expandedMatrixByBlocks[kount]->colOffsetSize ||
            rowMajor         != expandedMatrixByBlocks[kount]->isRowMajor)
            continue;
        
        for (int i=0; i < rowPartitionSize; i++)
            if (rowPartition[i] != expandedMatrixByBlocks[kount]->rowOffset[i])
                continue;
        for (int i=0; i < colPartitionSize; i++)
            if (colPartition[i] != expandedMatrixByBlocks[kount]->colOffset[i])
                continue;

        return expandedMatrixByBlocks[kount];
    }

    // not found; create a new collection
    if (!appendToBlockArray) 
        throw ErrorClass("getBlocks(): Cannot determine a suitable collection");

    if (!processBlocks(mtxIdx, rowPartition, rowPartitionSize,
                               colPartition, colPartitionSize, rowMajor, convertTo_, symmetry_)
       return false;
    return expandedMatrixByBlocks.back();
}// end of MatrixType::getBlocks
*/

bool MatrixType::processBlocks(OSMatrix** mtxIdx, bool rowMajor_, 
                               ENUM_MATRIX_TYPE convertTo_, ENUM_MATRIX_SYMMETRY symmetry_)
{
    int  cSize = getColumnPartitionSize(); 
    int  rSize = getRowPartitionSize();
    int* cPartition = getColumnPartition(); 
    int* rPartition = getRowPartition(); 
    return processBlocks(mtxIdx, rPartition, rSize, cPartition, cSize, rowMajor_, convertTo_, symmetry_);
}// end of MatrixType::processBlocks


bool MatrixType::processBlocks(OSMatrix** mtxIdx, int* rowOffset, int rowOffsetSize,
                               int* colOffset, int colOffsetSize, bool rowMajor_,
                               ENUM_MATRIX_TYPE convertTo_, ENUM_MATRIX_SYMMETRY symmetry_)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSMatrix, ENUM_OUTPUT_LEVEL_debug, "Inside processBlocks()");
std::cout << "called from an object of kind " << returnMatrixConstructorTypeString(nType)
          << " with " << inumberOfChildren << " children" << std::endl;
std::cout << "declared matrix type: "   << returnMatrixTypeString(getDeclaredMatrixType()) << std::endl; 
std::cout << "inferred matrix type: "   << returnMatrixTypeString(getInferredMatrixType()) << std::endl;
std::cout << "declared type of child: " << returnMatrixTypeString(getDeclaredMatrixType()) << std::endl; 
std::cout << "inferred matrix type: "   << returnMatrixTypeString(getInferredMatrixType()) << std::endl; 
#endif

    ExpandedMatrixBlocks* tmpBlocks = NULL;

    int* tmpBlockIdx = NULL;

    try
    {
        ENUM_MATRIX_TYPE convertTo = convertTo_;
        ENUM_MATRIX_TYPE inferredType = getMatrixType();
        if (convertTo == ENUM_MATRIX_TYPE_unknown) 
            convertTo  = inferredType;
        if (convertTo != mergeMatrixType(convertTo, inferredType))
           throw ErrorClass("Requested improper conversion of element values");

        ENUM_MATRIX_SYMMETRY symmetry = symmetry_;

        if (symmetry == ENUM_MATRIX_SYMMETRY_default)
            symmetry  = this->symmetry;
        else
        {
            if (this->symmetry == ENUM_MATRIX_SYMMETRY_default)
                this->symmetry  = symmetry;
            if (this->symmetry != symmetry)
                throw ErrorClass("Symmetry changes not yet implemented in processBlocks()");
        }

        bool blockSym = (rowOffsetSize == colOffsetSize);

        int ioff = 0;
        while (blockSym && ioff < rowOffsetSize)
        {
            if (rowOffset[ioff] != colOffset[ioff])
            {
                blockSym = false;
                break;
            }
            ioff++; 
        }
        if (//symmetry != ENUM_MATRIX_SYMMETRY_none    &&
            //symmetry != ENUM_MATRIX_SYMMETRY_default && 
            !blockSym)
            throw ErrorClass("Requested symmetry conversion not implemented yet");
        
        if (inumberOfChildren == 1)
        {
            if (m_mChildren[0]->nType == ENUM_MATRIX_CONSTRUCTOR_TYPE_blocks)
            {
                if (((MatrixBlocks*)m_mChildren[0])->rowOffset->numberOfEl != rowOffsetSize ||
                    ((MatrixBlocks*)m_mChildren[0])->colOffset->numberOfEl != colOffsetSize)
                    goto must_expand;

                for (int j=0; j < rowOffsetSize; j++)
                    if (((MatrixBlocks*)m_mChildren[0])->rowOffset->el[j] != rowOffset[j])
                        goto must_expand;

                for (int j=0; j < colOffsetSize; j++)
                    if (((MatrixBlocks*)m_mChildren[0])->colOffset->el[j] != colOffset[j])
                        goto must_expand;

                // here the block structure fits the partition, so we can copy blocks
                tmpBlocks = new ExpandedMatrixBlocks();

                tmpBlocks->bDeleteArrays = false;
                tmpBlocks->valueType     = convertTo;
                tmpBlocks->isRowMajor    = rowMajor_;
                tmpBlocks->symmetry      = symmetry;
                tmpBlocks->rowOffsetSize = rowOffsetSize;
                tmpBlocks->colOffsetSize = colOffsetSize;
                tmpBlocks->rowOffset     = rowOffset;
                tmpBlocks->colOffset     = colOffset;

                tmpBlocks->blockNumber   = ((MatrixBlocks*)m_mChildren[0])->inumberOfChildren;
                tmpBlocks->blocks        = new GeneralSparseMatrix*[tmpBlocks->blockNumber]; //leaks memory
                tmpBlocks->blockRows     = new int[tmpBlocks->blockNumber]; //apparently clean!
                tmpBlocks->blockColumns  = new int[tmpBlocks->blockNumber]; //leaks memory
                tmpBlockIdx              = new int[tmpBlocks->blockNumber];

                for (int i=0; i < tmpBlocks->blockNumber; i++)
                {
                    tmpBlocks->blocks[i]        = NULL;
                    tmpBlocks->blockRows[i]     = -1;
                    tmpBlocks->blockColumns[i]  = -1;
                    tmpBlockIdx[i]              = -1;
                }

                // access the blocks; expand and convert if necessary
                MatrixBlock* tmpChild;

                for (unsigned int j=0; j < tmpBlocks->blockNumber; j++)
                {
                    tmpChild = (MatrixBlock*)((MatrixBlocks*)m_mChildren[0])->m_mChildren[j];
std::cout << "expand a block in row " << tmpChild->blockRowIdx << ", col " << tmpChild->blockColIdx
          << std::endl;  
                    if (tmpChild->blockRowIdx == tmpChild->blockColIdx)
                        tmpBlockIdx[j] 
                            = tmpChild->getExpandedMatrix(mtxIdx, rowMajor_, convertTo, symmetry);
                    else
                        tmpBlockIdx[j]
                            = tmpChild->getExpandedMatrix(mtxIdx, rowMajor_, convertTo,
                                                          ENUM_MATRIX_SYMMETRY_none);
                    if (tmpBlockIdx[j] < 0)
                        throw ErrorClass("expansion of matrix block failed in processBlocks()");

                    tmpBlocks->blocks[j]       = tmpChild->expandedMatrixByElements[tmpBlockIdx[j]];
                    tmpBlocks->blockRows[j]    = tmpChild->blockRowIdx;
                    tmpBlocks->blockColumns[j] = tmpChild->blockColIdx;

#ifndef NDEBUG
                    ((GeneralSparseMatrix*)tmpBlocks->blocks[j])->printMatrix();
#endif
                }
                expandedMatrixByBlocks.push_back(tmpBlocks);
                delete [] tmpBlockIdx;
                tmpBlockIdx = NULL;
                return true;
            }

            // here we do not have blocks fitting the partition, so we must expand
must_expand:
            int iTmp = this->getExpandedMatrix(mtxIdx, rowMajor_, convertTo, symmetry);
            if (iTmp < 0) 
                throw ErrorClass("matrix expansion failed in processBlocks()");
            tmpBlocks = this->disassembleMatrix(rowOffset, rowOffsetSize, 
                                                colOffset, colOffsetSize, 
                                                mtxIdx, rowMajor_, convertTo, symmetry);
            expandedMatrixByBlocks.push_back(tmpBlocks);
            return true;
        }
        else if (inumberOfChildren == 0)
        {
            // here we have a zero matrix: numberOfBlocks = 0, etc.
            tmpBlocks = new ExpandedMatrixBlocks();

            tmpBlocks->bDeleteArrays = false;
            tmpBlocks->valueType     = convertTo;
            tmpBlocks->isRowMajor    = rowMajor_;
            tmpBlocks->rowOffsetSize = rowOffsetSize;
            tmpBlocks->colOffsetSize = colOffsetSize;
            tmpBlocks->rowOffset     = rowOffset;
            tmpBlocks->colOffset     = colOffset;

            tmpBlocks->blockNumber   = 0;
            tmpBlocks->blocks        = NULL;
            tmpBlocks->blockRows     = NULL;
            tmpBlocks->blockColumns  = NULL;
            expandedMatrixByBlocks.push_back(tmpBlocks);
        }

        else
        {
            // Shortcuts might be possible if all constructors are blocks 
            // that are conformal with the desired structure.
            // However, the easy out is to expand the matrix, then disassemble it. 
            int i = this->getExpandedMatrix(mtxIdx, tmpBlocks->isRowMajor,
                                            tmpBlocks->valueType, tmpBlocks->symmetry);
            if (i < 0)
                throw ErrorClass("Matrix expansion failed in processBlocks()");
            tmpBlocks = this->disassembleMatrix(rowOffset, rowOffsetSize, 
                                                colOffset, colOffsetSize, 
                                                mtxIdx, rowMajor_, convertTo, symmetry);
            expandedMatrixByBlocks.push_back(tmpBlocks);
        }
        return true;
    }
    catch(const ErrorClass& eclass)
    {
        if (tmpBlockIdx != NULL)
            delete [] tmpBlockIdx;
        tmpBlockIdx = NULL;
        if (tmpBlocks != NULL)
        {
//            for (int i=0; i < tmpBlocks->blockNumber; i++)
//                delete tmpBlocks[i];
//            delete [] tmpBlocks;
            delete tmpBlocks;
            tmpBlocks = NULL;
        }
        throw ErrorClass( eclass.errormsg);
    }
}// end of alternate MatrixType::processBlocks

ExpandedMatrixBlocks* MatrixType::disassembleMatrix(int* rowPartition, int rowPartitionSize, 
                                                    int* colPartition, int colPartitionSize, 
                                                    OSMatrix** mtxIdx, bool rowMajor, 
                                                    ENUM_MATRIX_TYPE valueType,
                                                    ENUM_MATRIX_SYMMETRY symmetry_)
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
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSMatrix, ENUM_OUTPUT_LEVEL_trace, "Inside disassembleMatrix()");
#endif
    int lastBlock, currRow;
    int blockCount, firstBlockInCol;
    std::vector<GeneralSparseMatrix*> tmpBlocks;
    int* tmpBlockRows; 
    int* tmpBlockColumns;
    bool found;
    int  i, j, k;
    int* elCount;
    ENUM_MATRIX_TYPE matrixType = getMatrixType();

    ENUM_MATRIX_SYMMETRY symmetry = symmetry_;

    if (symmetry == ENUM_MATRIX_SYMMETRY_default)
//        symmetry  = this->symmetry;
//    if (symmetry != this->symmetry)
        throw ErrorClass("Cannot handle symmetry properly in expandBlocks()");

    //This section is for column-wise representations --- row-wise will work analogously
    if (!rowMajor)
    {
        firstBlockInCol = -1;
//        if (expandedMatrixInColumnMajorForm == NULL)
//            getExpandedMatrix(false);
        int iMtx = getExpandedMatrix(mtxIdx, rowMajor, valueType, symmetry);
        GeneralSparseMatrix* tmpMatrix = expandedMatrixByElements[i];

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
                for ( k = tmpMatrix->start[j]; 
                      k < tmpMatrix->start[j+1]; 
                      k++ )                                 // k indexes the elements in this column
                {
                    currRow = tmpMatrix->index[k];
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
                            tmpBlock->isRowMajor         = false;
                            tmpBlock->symmetry           = symmetry;
                            tmpBlock->numberOfRows       = numberOfRows;
                            tmpBlock->numberOfColumns    = numberOfColumns;
                            tmpBlock->valueType          = matrixType;
                            tmpBlock->startSize          = colPartition[i+1] - colPartition[i] + 1;
                            tmpBlock->start              = new int[tmpBlock->startSize];
    
                            for (int n=0; n <= j - colPartition[i]; n++)
                                tmpBlock->start[n] = 0;

                            tmpBlocks.push_back(tmpBlock);
                            if (firstBlockInCol < 0) 
                                firstBlockInCol = blockCount - 1;
                        }
                    } // end of element
                } // end of column

                //store starts
                for (k=firstBlockInCol; k < blockCount; k++)
                    tmpBlocks[k]->start[j-colPartition[i] + 1] = elCount[k];

            } // end of block of columns

            // allocate space for indexes, values and block location 
            for (k=firstBlockInCol; k < blockCount; k++)
            {
                tmpBlocks[k]->valueSize = elCount[k];
                tmpBlocks[k]->index = new int[elCount[k]];
                tmpBlocks[k]->value = new MatrixElementValues[elCount[k]];
            }
            tmpBlockRows    = new int[blockCount]; 
            tmpBlockColumns = new int[blockCount];
            for (j=0; j<blockCount; j++)
            {
                tmpBlockRows[j]    = -1;
            } 
            
            lastBlock = i;            

            // traverse a second time to get values
            for (j=colPartition[i]; j<colPartition[i+1]; j++) // j indexes a column within this block
            {
                for ( k = tmpMatrix->start[j]; 
                      k < tmpMatrix->start[j+1]; 
                      k++ )                                   // k indexes the elements in this column
                {
                    currRow = tmpMatrix->index[k];
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
                tmpBlocks[lastBlock]->index[k-k0] = tmpMatrix->index[k] - rowPartition[j];
                tmpBlocks[lastBlock]->value[k-k0] = tmpMatrix->value[k];
            }
        } // end of entire collection

    } // end of column major 
    else
        throw ErrorClass("Row major not yet implemented in MatrixType::disassembleMatrix()");

    ExpandedMatrixBlocks* returnArray = new ExpandedMatrixBlocks();
/*
    returnArray->bDeleteArrays = true;
    returnArray->valueType     = matrixType;
    returnArray->isRowMajor    = rowMajor;
    returnArray->blockNumber   = tmpBlocks.size();
    returnArray->rowOffset     = rowPartition;
    returnArray->colOffset     = colPartition;
    returnArray->rowOffsetSize = rowPartitionSize;
    returnArray->colOffsetSize = colPartitionSize;
    returnArray->blocks        = new GeneralSparseMatrix*[tmpBlocks.size()];

    for (unsigned int i=0; i<tmpBlocks.size();i++);
    {
        returnArray->blocks[i] = tmpBlocks[i];
        returnArray->blockRows[i] = tmpBlockRows[i];
        returnArray->blockColumns[i] = tmpBlockColumns[i];    
    }
*/
    return returnArray;
}//end of MatrixType::disassembleMatrix


GeneralSparseMatrix* MatrixType::extractBlock(int firstrow, int firstcol, int nrows, int ncols,
                                              bool rowMajor, ENUM_MATRIX_SYMMETRY symmetry_)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSMatrix, ENUM_OUTPUT_LEVEL_trace, "Inside extractBlock()");
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
    index(NULL)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSMatrix, ENUM_OUTPUT_LEVEL_trace, 
        "Inside the MatrixElements Constructor");
    std::ostringstream outStr;
    outStr << "Allocate MatrixElements at address" << this;
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSMatrix, ENUM_OUTPUT_LEVEL_detailed_trace, outStr.str());
#endif
}// end of MatrixElements::MatrixElements()

MatrixElements::~MatrixElements()
{
    ostringstream outStr;
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSMatrix, ENUM_OUTPUT_LEVEL_trace, 
        "Inside the MatrixElements Destructor");
    outStr << "deleting MatrixElements at address" << this << std::endl;
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSMatrix, ENUM_OUTPUT_LEVEL_detailed_trace, outStr.str());
#endif
    if (start != NULL)
    {
#ifndef NDEBUG
        outStr.str("");
        outStr.clear();
        outStr << "deleting MatrixElements->start at " << &start << std::endl;
        osoutput->OSPrint(ENUM_OUTPUT_AREA_OSMatrix, ENUM_OUTPUT_LEVEL_detailed_trace, outStr.str());
#endif
        delete start;
        start = NULL;
    }

    if (index != NULL)
    {
#ifndef NDEBUG
        outStr.str("");
        outStr.clear();
        outStr << "deleting MatrixElements->index at " << &index << std::endl;
        osoutput->OSPrint(ENUM_OUTPUT_AREA_OSMatrix, ENUM_OUTPUT_LEVEL_detailed_trace, outStr.str());
#endif
        delete index;
        index = NULL;
    }
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

            if (!this->index->IsEqual(that->index))
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
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSMatrix, ENUM_OUTPUT_LEVEL_trace,
        "Inside the MatrixElementValues Constructor");
    std::ostringstream outStr;
    outStr << "Allocate MatrixElementValues at address" << this;
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSMatrix, ENUM_OUTPUT_LEVEL_detailed_trace, outStr.str());
#endif
}

MatrixElementValues::~MatrixElementValues()
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSMatrix, ENUM_OUTPUT_LEVEL_trace,
        "Inside the MatrixElementValues Destructor");
    std::ostringstream outStr;
    outStr << "deleting MatrixElementValues at address" << this << std::endl;
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSMatrix, ENUM_OUTPUT_LEVEL_detailed_trace, outStr.str());
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
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSMatrix, ENUM_OUTPUT_LEVEL_trace,
        "Inside the OSMatrix Constructor");
    std::ostringstream outStr;
    outStr << "Allocate OSMatrix at address" << this;
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSMatrix, ENUM_OUTPUT_LEVEL_detailed_trace, outStr.str());
#endif
    nType    = ENUM_MATRIX_CONSTRUCTOR_TYPE_matrix;
    symmetry = ENUM_MATRIX_SYMMETRY_none;
}// end of OSMatrix

OSMatrix::~OSMatrix()
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSMatrix, ENUM_OUTPUT_LEVEL_trace,
        "Inside the OSMatrix Destructor");
    std::ostringstream outStr;
    outStr << "deleting OSMatrix at address" << this << std::endl;
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSMatrix, ENUM_OUTPUT_LEVEL_detailed_trace, outStr.str());
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
}//end OSMatrix::createConstructorTreeFromPrefix


ENUM_MATRIX_CONSTRUCTOR_TYPE OSMatrix::getNodeType()
{
    return ENUM_MATRIX_CONSTRUCTOR_TYPE_matrix;
}// end of OSMatrix::getNodeType()

std::string OSMatrix::getNodeName()
{
    return "matrix";
}// end of OSMatrix::getNodeName()

#if 0
ENUM_MATRIX_TYPE OSMatrix::getDeclaredMatrixType()
{
    return declaredMatrixType;
}// end of OSMatrix::getDeclaredMatrixType()

ENUM_MATRIX_TYPE OSMatrix::getInferredMatrixType()
{
    if (inferredMatrixType == ENUM_MATRIX_TYPE_unknown)
    {
        for (unsigned int i=0; i<inumberOfChildren; i++)
            inferredMatrixType = mergeMatrixType(inferredMatrixType,
                                                 m_mChildren[i]->getInferredMatrixType());
    }
    return inferredMatrixType;
}// end of OSMatrix::getInferredMatrixType()

ENUM_MATRIX_TYPE OSMatrix::getMatrixType()
{
    inferredMatrixType = getInferredMatrixType();
    if (declaredMatrixType == ENUM_MATRIX_TYPE_unknown)
        return inferredMatrixType;

    if (declaredMatrixType == mergeMatrixType(declaredMatrixType, inferredMatrixType))
        return declaredMatrixType;

    else throw ErrorClass("Declared matrix type conflicts with inferred type");
}// end of OSMatrix::getMatrixType()
#endif

bool OSMatrix::expandElements(OSMatrix** mtxIdx, bool rowMajor)
{
#if 0
    //Check if expanded previously
    if (rowMajor)
    {
        if (expandedMatrixInRowMajorForm != NULL) return true;
    }
    else
    {
        if (epandedMatrixInColumnMajorForm != NULL) return true;
    }

    // The complexity increases with the number of constructors
    // Start by checking for empty matrix
    if (inumberOfChildren == 0)
    {
        if (rowMajor)
        {
            expandedMatrixInRowMajorForm = new GeneralSparseMatrix();
            expandedMatrixInRowMajorForm->symmetry = symmetry;
            expandedMatrixInRowMajorForm->valueSize = 0;
            expandedMatrixInRowMajorForm->startSize = numberOfRows + 1;
            expandedMatrixInRowMajorForm->starts = new int[numberOfRows + 1];
            for (int i=0; i <= numberOfRows; i++)
                expandedMatrixInRowMajorForm->starts[i] = 0;
            return true;
        }
        else
        {
            expandedMatrixInColumnMajorForm = new GeneralSparseMatrix();
            expandedMatrixInColumnMajorForm->symmetry = symmetry;
            expandedMatrixInColumnMajorForm->valueSize = 0;
            expandedMatrixInColumnMajorForm->startSize = numberOfColumns + 1;
            expandedMatrixInColumnMajorForm->starts = new int[numberOfColumns + 1];
            for (int i=0; i <= numberOfColumns; i++)
                expandedMatrixInColumnMajorForm->starts[i] = 0;
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
                processBlocks(mtxIdx, int* rowOffsets, int* colOffsets,
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
    for (unsigned int i=0; i < inumberOfChildren; i++)
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


            if (((MatrixElements*)m_mChildren[i])->realValuedExpressions != NULL)
            {
                if (((MatrixElements*)m_mChildren[i])->realValuedExpressions->rowMajor)
                {
                    for (int j=1; j < colPartitionSize; j++)
                        for (int  k = colPartition[j-1]; k < colPartition[j]; j++)
                           for (int l = ((MatrixElements*)m_mChildren[i])->realValuedExpressions->start->el[k];
                                    l < ((MatrixElements*)m_mChildren[i])->realValuedExpressions->start->el[k+1];
                                    l++)
                            if ( ((MatrixElements*)m_mChildren[i])->realValuedExpressions->indexes->el[l]
                                     <  rowPartition[j-1] ||
                                 ((MatrixElements*)m_mChildren[i])->realValuedExpressions->indexes->el[l]
                                     >= rowPartition[j] )
                                return false;
                }
                else
                {
                    for (int j=1; j < rowPartitionSize; j++)
                        for (int  k = rowPartition[j-1]; k < rowPartition[j]; j++)
                           for (int l = ((MatrixElements*)m_mChildren[i])->realValuedExpressions->start->el[k];
                                    l < ((MatrixElements*)m_mChildren[i])->realValuedExpressions->start->el[k+1];
                                    l++)
                            if ( ((MatrixElements*)m_mChildren[i])->realValuedExpressions->indexes->el[l]
                                     <  colPartition[j-1] ||
                                 ((MatrixElements*)m_mChildren[i])->realValuedExpressions->indexes->el[l]
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
                         ENUM_MATRIX_SYMMETRY symmetry, ENUM_MATRIX_TYPE declaredMatrixType, 
                         ENUM_MATRIX_TYPE inferredMatrixType, unsigned int inumberOfChildren, 
                         MatrixNode **m_mChildren)
{
    this->name               = name;
    this->numberOfRows       = numberOfRows;
    this->numberOfColumns    = numberOfColumns;
    this->symmetry           = symmetry;
    this->declaredMatrixType = declaredMatrixType;
    this->inferredMatrixType = inferredMatrixType;
    this->inumberOfChildren  = inumberOfChildren;
    this->m_mChildren        = m_mChildren;
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
    if (declaredMatrixType != ENUM_MATRIX_TYPE_unknown) 
        outStr << " type=\"" << returnMatrixTypeString(declaredMatrixType) << "\"";

    if (inumberOfChildren > 0)
    {
        outStr << ">" << std::endl;
        for (unsigned int i=0; i < inumberOfChildren; i++)
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
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSMatrix, ENUM_OUTPUT_LEVEL_debug, "Start comparing in OSMatrix");
#endif
    if (this == NULL)
    {
        if (that == NULL)
            return true;
        else
        {
#ifndef NDEBUG
            osoutput->OSPrint(ENUM_OUTPUT_AREA_OSMatrix, ENUM_OUTPUT_LEVEL_debug, 
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
            osoutput->OSPrint(ENUM_OUTPUT_AREA_OSMatrix, ENUM_OUTPUT_LEVEL_debug, 
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


/** ---------- Methods for class OSMatrixWithMatrixVarIdx ---------- */
OSMatrixWithMatrixVarIdx::OSMatrixWithMatrixVarIdx():
    OSMatrix(),
    matrixVarIdx(-1)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSMatrix, ENUM_OUTPUT_LEVEL_trace,
        "Inside the OSMatrixWithMatrixVarIdx Constructor");
    std::ostringstream outStr;
    outStr << "Allocate OSMatrixWithMatrixVarIdx at address" << this;
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSMatrix, ENUM_OUTPUT_LEVEL_detailed_trace, outStr.str());
#endif
}// end of OSMatrixWithMatrixVarIdx

OSMatrixWithMatrixVarIdx::~OSMatrixWithMatrixVarIdx()
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSMatrix, ENUM_OUTPUT_LEVEL_trace,
        "Inside the OSMatrixWithMatrixVarIdx Destructor");
    std::ostringstream outStr;
    outStr << "deleting OSMatrixWithMatrixVarIdx at address" << this << std::endl;
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSMatrix, ENUM_OUTPUT_LEVEL_detailed_trace, outStr.str());
#endif
}// end of ~OSMatrixWithMatrixVarIdx


std::string OSMatrixWithMatrixVarIdx::getMatrixNodeInXML()
{
    ostringstream outStr;
    outStr << "<matrixVar";
    outStr << " numberOfRows=\""    << numberOfRows    << "\"";
    outStr << " numberOfColumns=\"" << numberOfColumns << "\"";
    outStr << " matrixVarIdx=\""    << matrixVarIdx    << "\"";
    if (symmetry != ENUM_MATRIX_SYMMETRY_none)
        outStr << " symmetry=\"" << returnMatrixSymmetryString(symmetry) << "\"";
    if (name != "") 
        outStr << " name=\"" << name << "\"";
    if (declaredMatrixType != ENUM_MATRIX_TYPE_unknown) 
        outStr << " type=\"" << returnMatrixTypeString(declaredMatrixType) << "\"";

    if (inumberOfChildren > 0)
    {
        outStr << ">" << std::endl;
        for (unsigned int i=0; i < inumberOfChildren; i++)
            outStr << m_mChildren[i]->getMatrixNodeInXML();
        outStr << "</matrixVar>" << std::endl;
    }
    else
        outStr << "/>" << std::endl;
    return outStr.str();
}// end of OSMatrixWithMatrixVarIdx::getMatrixNodeInXML()

OSMatrixWithMatrixVarIdx* OSMatrixWithMatrixVarIdx::cloneMatrixNode()
{
    MatrixType *nodePtr;
    nodePtr = new OSMatrixWithMatrixVarIdx();
    return  (OSMatrixWithMatrixVarIdx*)nodePtr;
}// end of OSMatrixWithMatrixVarIdx::cloneMatrixNode


bool OSMatrixWithMatrixVarIdx::setRandom( double density, bool conformant, int iMin, int Imax )
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_trace,
        "Set random OSMatrixWithMatrixVarIdx");
#endif
    this->numberOfRows    = (int)(4*OSRand());
    this->numberOfColumns = (int)(4*OSRand());
    this->matrixVarIdx    = (int)(4*OSRand());
    if (OSRand() <= density) this->name = "random string";
    if (OSRand() <= density) this->declaredMatrixType
        = /*returnMatrixTypeString(*/(ENUM_MATRIX_TYPE)(12*OSRand()+1)/*)*/;
    if (OSRand() <= density) this->symmetry
        = /*returnMatrixSymmetryString(*/(ENUM_MATRIX_SYMMETRY)(9*OSRand()+1/*)*/);
    return true;
}//OSMatrixWithMatrixVarIdx::setRandom

bool OSMatrixWithMatrixVarIdx::IsEqual(OSMatrixWithMatrixVarIdx *that)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSMatrix, ENUM_OUTPUT_LEVEL_debug,
        "Start comparing in OSMatrixWithMatrixVarIdx");
#endif
    if (this == NULL)
    {
        if (that == NULL)
            return true;
        else
        {
#ifndef NDEBUG
            osoutput->OSPrint(ENUM_OUTPUT_AREA_OSMatrix, ENUM_OUTPUT_LEVEL_debug, 
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
            osoutput->OSPrint(ENUM_OUTPUT_AREA_OSMatrix, ENUM_OUTPUT_LEVEL_debug, 
                "Second object is NULL, first is not");
#endif
            return false;
        }
        else
        {
            if (this->idx  != this->idx)  return false; 
            if (this->name != this->name) return false; 
            if (!this->OSMatrix::IsEqual(that)) return false;

            return true;
        }
    }
}// end of OSMatrixWithMatrixVarIdx::IsEqual()

/** ---------- Methods for class OSMatrixWithMatrixObjIdx ---------- */
OSMatrixWithMatrixObjIdx::OSMatrixWithMatrixObjIdx():
    OSMatrix(),
    matrixObjIdx(-1)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSMatrix, ENUM_OUTPUT_LEVEL_trace,
        "Inside the OSMatrixWithMatrixObjIdx Constructor");
    std::ostringstream outStr;
    outStr << "Allocate OSMatrixWithMatrixObjIdx at address" << this;
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSMatrix, ENUM_OUTPUT_LEVEL_detailed_trace, outStr.str());
#endif
}// end of OSMatrixWithMatrixObjIdx

OSMatrixWithMatrixObjIdx::~OSMatrixWithMatrixObjIdx()
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSMatrix, ENUM_OUTPUT_LEVEL_trace,
        "Inside the OSMatrixWithMatrixObjIdx Destructor");
    std::ostringstream outStr;
    outStr << "deleting OSMatrixWithMatrixObjIdx at address" << this << std::endl;
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSMatrix, ENUM_OUTPUT_LEVEL_detailed_trace, outStr.str());
#endif
}// end of ~OSMatrixWithMatrixObjIdx


std::string OSMatrixWithMatrixObjIdx::getMatrixNodeInXML()
{
    ostringstream outStr;
    outStr << "<matrixObj";
    outStr << " numberOfRows=\""    << numberOfRows    << "\"";
    outStr << " numberOfColumns=\"" << numberOfColumns << "\"";
    outStr << " matrixObjIdx=\""    << matrixObjIdx    << "\"";
    if (symmetry != ENUM_MATRIX_SYMMETRY_none)
        outStr << " symmetry=\"" << returnMatrixSymmetryString(symmetry) << "\"";
    if (name != "") 
        outStr << " name=\"" << name << "\"";
    if (declaredMatrixType != ENUM_MATRIX_TYPE_unknown) 
        outStr << " type=\"" << returnMatrixTypeString(declaredMatrixType) << "\"";

    if (inumberOfChildren > 0)
    {
        outStr << ">" << std::endl;
        for (unsigned int i=0; i < inumberOfChildren; i++)
            outStr << m_mChildren[i]->getMatrixNodeInXML();
        outStr << "</matrixObj>" << std::endl;
    }
    else
        outStr << "/>" << std::endl;
    return outStr.str();
}// end of OSMatrixWithMatrixObjIdx::getMatrixNodeInXML()

OSMatrixWithMatrixObjIdx* OSMatrixWithMatrixObjIdx::cloneMatrixNode()
{
    MatrixType *nodePtr;
    nodePtr = new OSMatrixWithMatrixObjIdx();
    return  (OSMatrixWithMatrixObjIdx*)nodePtr;
}// end of OSMatrixWithMatrixObjIdx::cloneMatrixNode

bool OSMatrixWithMatrixObjIdx::setRandom( double density, bool conformant, int iMin, int Imax )
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_trace,
        "Set random OSMatrixWithMatrixObjIdx");
#endif
    this->numberOfRows    = (int)(4*OSRand());
    this->numberOfColumns = (int)(4*OSRand());
    this->matrixObjIdx    = -1 - (int)(4*OSRand());
    if (OSRand() <= density) this->name = "random string";
    if (OSRand() <= density) this->declaredMatrixType
        = /*returnMatrixTypeString(*/(ENUM_MATRIX_TYPE)(12*OSRand()+1)/*)*/;
    if (OSRand() <= density) this->symmetry
        = /*returnMatrixSymmetryString(*/(ENUM_MATRIX_SYMMETRY)(9*OSRand()+1/*)*/);
    return true;
}//OSMatrixWithMatrixObjIdx::setRandom

bool OSMatrixWithMatrixObjIdx::IsEqual(OSMatrixWithMatrixObjIdx *that)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSMatrix, ENUM_OUTPUT_LEVEL_debug,
        "Start comparing in OSMatrixWithMatrixObjIdx");
#endif
    if (this == NULL)
    {
        if (that == NULL)
            return true;
        else
        {
#ifndef NDEBUG
            osoutput->OSPrint(ENUM_OUTPUT_AREA_OSMatrix, ENUM_OUTPUT_LEVEL_debug, 
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
            osoutput->OSPrint(ENUM_OUTPUT_AREA_OSMatrix, ENUM_OUTPUT_LEVEL_debug, 
                "Second object is NULL, first is not");
#endif
            return false;
        }
        else
        {
            if (this->idx  != this->idx)  return false; 
            if (this->name != this->name) return false; 
            if (!this->OSMatrix::IsEqual(that)) return false;

            return true;
        }
    }
}// end of OSMatrixWithMatrixObjIdx::IsEqual()


/** ---------- Methods for class OSMatrixWithMatrixConIdx ---------- */
OSMatrixWithMatrixConIdx::OSMatrixWithMatrixConIdx():
    OSMatrix(),
    matrixConIdx(-1)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSMatrix, ENUM_OUTPUT_LEVEL_trace,
        "Inside the OSMatrixWithMatrixConIdx Constructor");
    std::ostringstream outStr;
    outStr << "Allocate OSMatrixWithMatrixConIdx at address" << this;
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSMatrix, ENUM_OUTPUT_LEVEL_detailed_trace, outStr.str());
#endif
}// end of OSMatrixWithMatrixConIdx

OSMatrixWithMatrixConIdx::~OSMatrixWithMatrixConIdx()
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSMatrix, ENUM_OUTPUT_LEVEL_trace,
        "Inside the OSMatrixWithMatrixConIdx Destructor");
    std::ostringstream outStr;
    outStr << "deleting OSMatrixWithMatrixConIdx at address" << this << std::endl;
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSMatrix, ENUM_OUTPUT_LEVEL_detailed_trace, outStr.str());
#endif
}// end of ~OSMatrixWithMatrixConIdx

std::string OSMatrixWithMatrixConIdx::getMatrixNodeInXML()
{
    ostringstream outStr;
    outStr << "<matrixCon";
    outStr << " numberOfRows=\""    << numberOfRows    << "\"";
    outStr << " numberOfColumns=\"" << numberOfColumns << "\"";
    outStr << " matrixConIdx=\""    << matrixConIdx    << "\"";
    if (symmetry != ENUM_MATRIX_SYMMETRY_none)
        outStr << " symmetry=\"" << returnMatrixSymmetryString(symmetry) << "\"";
    if (name != "") 
        outStr << " name=\"" << name << "\"";
    if (declaredMatrixType != ENUM_MATRIX_TYPE_unknown) 
        outStr << " type=\"" << returnMatrixTypeString(declaredMatrixType) << "\"";

    if (inumberOfChildren > 0)
    {
        outStr << ">" << std::endl;
        for (unsigned int i=0; i < inumberOfChildren; i++)
            outStr << m_mChildren[i]->getMatrixNodeInXML();
        outStr << "</matrixCon>" << std::endl;
    }
    else
        outStr << "/>" << std::endl;
    return outStr.str();
}// end of OSMatrixWithMatrixConIdx::getMatrixNodeInXML()

OSMatrixWithMatrixConIdx* OSMatrixWithMatrixConIdx::cloneMatrixNode()
{
    MatrixType *nodePtr;
    nodePtr = new OSMatrixWithMatrixConIdx();
    return  (OSMatrixWithMatrixConIdx*)nodePtr;
}// end of OSMatrixWithMatrixConIdx::cloneMatrixNode

bool OSMatrixWithMatrixConIdx::setRandom( double density, bool conformant, int iMin, int Imax )
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_trace,
        "Set random OSMatrixWithMatrixConIdx");
#endif
    this->numberOfRows    = (int)(4*OSRand());
    this->numberOfColumns = (int)(4*OSRand());
    this->matrixConIdx    = (int)(4*OSRand());
    if (OSRand() <= density) this->name = "random string";
    if (OSRand() <= density) this->declaredMatrixType
        = /*returnMatrixTypeString(*/(ENUM_MATRIX_TYPE)(12*OSRand()+1)/*)*/;
    if (OSRand() <= density) this->symmetry
        = /*returnMatrixSymmetryString(*/(ENUM_MATRIX_SYMMETRY)(9*OSRand()+1/*)*/);
    return true;
}//OSMatrixWithMatrixConIdx::setRandom


bool OSMatrixWithMatrixConIdx::IsEqual(OSMatrixWithMatrixConIdx *that)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSMatrix, ENUM_OUTPUT_LEVEL_debug,
        "Start comparing in OSMatrixWithMatrixConIdx");
#endif
    if (this == NULL)
    {
        if (that == NULL)
            return true;
        else
        {
#ifndef NDEBUG
            osoutput->OSPrint(ENUM_OUTPUT_AREA_OSMatrix, ENUM_OUTPUT_LEVEL_debug, 
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
            osoutput->OSPrint(ENUM_OUTPUT_AREA_OSMatrix, ENUM_OUTPUT_LEVEL_debug, 
                "Second object is NULL, first is not");
#endif
            return false;
        }
        else
        {
            if (this->idx  != this->idx)  return false; 
            if (this->name != this->name) return false; 
            if (!this->OSMatrix::IsEqual(that)) return false;

            return true;
        }
    }
}// end of OSMatrixWithMatrixConIdx::IsEqual()

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
    scalarMultiplier(1.0),
    scalarImaginaryPart(0.0)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSMatrix, ENUM_OUTPUT_LEVEL_trace,
        "Inside the BaseMatrix Constructor");
    std::ostringstream outStr;
    outStr << "Allocate BaseMatrix at address" << this;
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSMatrix, ENUM_OUTPUT_LEVEL_detailed_trace, outStr.str());
#endif
     nType = ENUM_MATRIX_CONSTRUCTOR_TYPE_baseMatrix;
} // end of BaseMatrix

BaseMatrix::~BaseMatrix()
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSMatrix, ENUM_OUTPUT_LEVEL_trace,
        "Inside the BaseMatrix Destructor");
    std::ostringstream outStr;
    outStr << "deleting BaseMatrix at address" << this << std::endl;
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSMatrix, ENUM_OUTPUT_LEVEL_detailed_trace, outStr.str());
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


ENUM_MATRIX_TYPE BaseMatrix::getDeclaredMatrixType()
{
    return ((OSMatrix*)baseMatrix)->getDeclaredMatrixType();
}// end of BaseMatrix::getMatrixType()


ENUM_MATRIX_TYPE BaseMatrix::getInferredMatrixType()
{
    if (inferredMatrixType == ENUM_MATRIX_TYPE_unknown)
        inferredMatrixType = ((OSMatrix*)baseMatrix)->getInferredMatrixType();
    return inferredMatrixType;
}// end of BaseMatrix::getMatrixType()


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
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSMatrix, ENUM_OUTPUT_LEVEL_trace,
        "Inside the MatrixTransformation Constructor");
    std::ostringstream outStr;
    outStr << "Allocate MatrixTransformation at address" << this;
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSMatrix, ENUM_OUTPUT_LEVEL_detailed_trace, outStr.str());
#endif
    nType = ENUM_MATRIX_CONSTRUCTOR_TYPE_transformation;
}// end of MatrixTransformation::MatrixTransformation()

MatrixTransformation::~MatrixTransformation()
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSMatrix, ENUM_OUTPUT_LEVEL_trace,
        "Inside the MatrixTransformation Destructor");
    std::ostringstream outStr;
    outStr << "deleting MatrixTransformation at address" << this << std::endl;
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSMatrix, ENUM_OUTPUT_LEVEL_detailed_trace, outStr.str());
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

#if 0
ENUM_MATRIX_TYPE MatrixTransformation::getMatrixType()
{
    if (matrixType == ENUM_MATRIX_TYPE_unknown)
        matrixType =  ENUM_MATRIX_TYPE_realValuedExpressions;
    return matrixType;
}// end of MatrixTransformation::getMatrixType()
#endif

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
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSMatrix, ENUM_OUTPUT_LEVEL_debug, "Start comparing in MatrixTransformation");
#endif
    if (this == NULL)
    {
        if (that == NULL)
            return true;
        else
        {
#ifndef NDEBUG
            osoutput->OSPrint(ENUM_OUTPUT_AREA_OSMatrix, ENUM_OUTPUT_LEVEL_debug, 
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
            osoutput->OSPrint(ENUM_OUTPUT_AREA_OSMatrix, ENUM_OUTPUT_LEVEL_debug, 
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
    value(NULL)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSMatrix, ENUM_OUTPUT_LEVEL_trace,
        "Inside the ConstantMatrixElements Constructor");
    std::ostringstream outStr;
    outStr << "Allocate ConstantMatrixElements at address" << this;
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSMatrix, ENUM_OUTPUT_LEVEL_detailed_trace, outStr.str());
#endif
}// end of ConstantMatrixElements::ConstantMatrixElements()

ConstantMatrixElements::~ConstantMatrixElements()
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSMatrix, ENUM_OUTPUT_LEVEL_trace, 
    "Inside the ConstantMatrixElements Destructor");

    std::ostringstream outStr;
    outStr << "deleting ConstantMatrixElements at address" << this << std::endl;
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSMatrix, ENUM_OUTPUT_LEVEL_detailed_trace, outStr.str());

    outStr.str("");
    outStr.clear();
    outStr << "deleting ConstantMatrixElements->value at " << &value << std::endl;
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSMatrix, 
       ENUM_OUTPUT_LEVEL_detailed_trace, outStr.str());
#endif
    if (value != NULL)
        delete value;
    value = NULL;
}// end of ConstantMatrixElements::~ConstantMatrixElements()

ENUM_MATRIX_CONSTRUCTOR_TYPE ConstantMatrixElements::getNodeType()
{
    return ENUM_MATRIX_CONSTRUCTOR_TYPE_constantElements;
}// end of ConstantMatrixElements::getNodeType()

std::string ConstantMatrixElements::getNodeName()
{
    return "constantElements";
}// end of ConstantMatrixElements::getNodeName()


ENUM_MATRIX_TYPE ConstantMatrixElements::getInferredMatrixType()
{
std::cout << "at start of ConstantMatrixElements::getInferredMatrixType()" << std::endl;
    inferredMatrixType = ENUM_MATRIX_TYPE_constant;
std::cout << "matrix constructor has inferred matrixType "
          << returnMatrixTypeString(inferredMatrixType) << std::endl;
    return inferredMatrixType;
}// end of ConstantMatrixElements::getInferredMatrixType()


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
        outStr << "<index>" << std::endl;
        outStr << writeIntVectorData(index, true, false);
        outStr << "</index>" << std::endl;

        outStr << "<value>" << std::endl;

        for(int i = 0; i < numberOfValues;)
        {
            int mult = getMult(&(value->el[i]), numberOfValues - i);
            if (mult == 1)
                outStr << "<el>" ;
            else
                outStr << "<el mult=\"" << mult << "\">";
            outStr << os_dtoa_format(value->el[i]);
            outStr << "</el>" << std::endl;
            i += mult;
        }
        outStr << "</value>" << std::endl;
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
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSMatrix, ENUM_OUTPUT_LEVEL_trace,
        "Start comparing in ConstantMatrixElements");
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

            if (!this->start->IsEqual(that->start)) return false;
            if (!this->index->IsEqual(that->index)) return false;
            if (!this->value->IsEqual(that->value)) return false;

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
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSMatrix, ENUM_OUTPUT_LEVEL_trace,
        "Inside the ConstantMatrixValues Constructor");
    std::ostringstream outStr;
    outStr << "Allocate ConstantMatrixValues at address" << this;
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSMatrix, ENUM_OUTPUT_LEVEL_detailed_trace, outStr.str());
#endif
}// end of ConstantMatrixValues::ConstantMatrixValues()

ConstantMatrixValues::~ConstantMatrixValues()
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSMatrix, ENUM_OUTPUT_LEVEL_trace,
        "Inside the ConstantMatrixValues Destructor");
    std::ostringstream outStr;
    outStr << "deleting ConstantMatrixValues at address" << this << std::endl;
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSMatrix, ENUM_OUTPUT_LEVEL_detailed_trace, outStr.str());
    outStr.str("");
    outStr.clear();
    outStr << "deleting ConstantMatrixValues->el at " << &el << std::endl;
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSMatrix, 
       ENUM_OUTPUT_LEVEL_detailed_trace, outStr.str());
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
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSMatrix, ENUM_OUTPUT_LEVEL_trace, "Make deep copy of ConstantMatrixValues");
#endif
    this->numberOfEl = that->numberOfEl;
    this->el = new double[numberOfEl];
    for (int i=0; i<numberOfEl; i++)
        this->el[i] = that->el[i];

    return true;
}// end of ConstantMatrixValues::deepCopyFrom()


/** ---------- Methods for class ComplexMatrixElements ---------- */
ComplexMatrixElements::ComplexMatrixElements():
    value(NULL)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSMatrix, ENUM_OUTPUT_LEVEL_trace,
        "Inside the ComplexMatrixElements Constructor");
    std::ostringstream outStr;
    outStr << "Allocate ComplexMatrixElements at address" << this;
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSMatrix, ENUM_OUTPUT_LEVEL_detailed_trace, outStr.str());
#endif
}// end of ComplexMatrixElements::ComplexMatrixElements()

ComplexMatrixElements::~ComplexMatrixElements()
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSMatrix, ENUM_OUTPUT_LEVEL_trace, 
    "Inside the ComplexMatrixElements Destructor");

    ostringstream outStr;
    outStr << "deleting ComplexMatrixElements at address" << this << std::endl;
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSMatrix, ENUM_OUTPUT_LEVEL_detailed_trace, outStr.str());
    outStr.str("");
    outStr.clear();
    outStr << "deleting ComplexMatrixElements->value at " << &value << std::endl;
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSMatrix, 
       ENUM_OUTPUT_LEVEL_detailed_trace, outStr.str());
#endif
    if (value != NULL)
        delete value;
    value = NULL;
}// end of ComplexMatrixElements::~ComplexMatrixElements()

ENUM_MATRIX_CONSTRUCTOR_TYPE ComplexMatrixElements::getNodeType()
{
    return ENUM_MATRIX_CONSTRUCTOR_TYPE_complexElements;
}// end of ComplexMatrixElements::getNodeType()

std::string ComplexMatrixElements::getNodeName()
{
    return "complexElements";
}// end of ComplexMatrixElements::getNodeName()


ENUM_MATRIX_TYPE ComplexMatrixElements::getInferredMatrixType()
{
std::cout << "at start of ComplexMatrixElements::getInferredMatrixType()" << std::endl;
    inferredMatrixType = ENUM_MATRIX_TYPE_complexConstant;
std::cout << "matrix constructor has inferred matrixType "
          << returnMatrixTypeString(inferredMatrixType) << std::endl;
    return inferredMatrixType;
}// end of ComplexMatrixElements::getInferredMatrixType()

std::string ComplexMatrixElements::getMatrixNodeInXML()
{
    ostringstream outStr;
    outStr <<  "<complexElements";
    if (rowMajor)
        outStr << " rowMajor=\"true\"";
    outStr << " numberOfValues=\"" << numberOfValues << "\"";
    outStr << ">" << std::endl;

    outStr << "<start>" << std::endl;
    outStr << writeIntVectorData(start, true, false);
    outStr << "</start>" << std::endl;

    if (numberOfValues > 0)
    {
        outStr << "<index>" << std::endl;
        outStr << writeIntVectorData(index, true, false);
        outStr << "</index>" << std::endl;

        outStr << "<value>" << std::endl;

        for(int i = 0; i < numberOfValues;)
        {
            int mult = getMult(&(value->el[i]), numberOfValues - i);
            outStr  << "<el"
                    << " Re=\"" << os_dtoa_format((value->el[i]).real()) << "\""
                    << " Im=\"" << os_dtoa_format((value->el[i]).imag()) << "\"";
            if (mult > 1)
                outStr << " mult=\"" << mult;
            outStr << "/>" << std::endl;
            i += mult;
        }
        outStr << "</value>" << std::endl;
    }

    outStr << "</complexElements>" << std::endl;
    return outStr.str();
}// end of ComplexMatrixElements::getMatrixNodeInXML()

bool ComplexMatrixElements::alignsOnBlockBoundary(int firstRow, int firstColumn, int nRows, int nCols)
{
    return false;
}// end of ComplexMatrixElements::alignsOnBlockBoundary()

ComplexMatrixElements* ComplexMatrixElements::cloneMatrixNode()
{
    ComplexMatrixElements *nodePtr;
    nodePtr = new ComplexMatrixElements();
    return  (ComplexMatrixElements*)nodePtr;
}// end of ComplexMatrixElements::cloneMatrixNode

bool ComplexMatrixElements::IsEqual(ComplexMatrixElements *that)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSMatrix, ENUM_OUTPUT_LEVEL_trace, "Start comparing in ComplexMatrixElements");
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

            if (!this->start->IsEqual(that->start)) return false;
            if (!this->index->IsEqual(that->index)) return false;
            if (!this->value->IsEqual(that->value)) return false;

            return true;
        }
    }
}// end of ComplexMatrixElements::IsEqual()

bool ComplexMatrixElements::setRandom(double density, bool conformant, int iMin, int iMax)
{
    return true;
}// end of ComplexMatrixElements::setRandom()

bool ComplexMatrixElements::deepCopyFrom(ComplexMatrixElements *that)
{
    return true;
}// end of ComplexMatrixElements::deepCopyFrom()


/** ---------- Methods for class ComplexMatrixValues ---------- */
ComplexMatrixValues::ComplexMatrixValues():
    el(NULL)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSMatrix, ENUM_OUTPUT_LEVEL_trace,
        "Inside the ComplexMatrixValues Constructor");
    std::ostringstream outStr;
    outStr << "Allocate ComplexMatrixValues at address" << this;
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSMatrix, ENUM_OUTPUT_LEVEL_detailed_trace, outStr.str());
#endif
}// end of ComplexMatrixValues::ComplexMatrixValues()

ComplexMatrixValues::~ComplexMatrixValues()
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSMatrix, ENUM_OUTPUT_LEVEL_trace,
        "Inside the ComplexMatrixValues Destructor");
    ostringstream outStr;
    outStr << "deleting ComplexMatrixValues at address" << this << std::endl;
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSMatrix, ENUM_OUTPUT_LEVEL_detailed_trace, outStr.str());
    outStr.str("");
    outStr.clear();
    outStr << "deleting ComplexMatrixValues->el at " << &el << std::endl;
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSMatrix, 
       ENUM_OUTPUT_LEVEL_detailed_trace, outStr.str());
#endif
    if (el != NULL)
        delete [] el;
    el = NULL;
}// end of ComplexMatrixValues::~ComplexMatrixValues()

bool ComplexMatrixValues::IsEqual(ComplexMatrixValues *that)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSMatrix, ENUM_OUTPUT_LEVEL_trace,
        "Start comparing in ComplexMatrixValues");
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
}// end of ComplexMatrixValues::IsEqual()

bool ComplexMatrixValues::setRandom(double density, bool conformant, int iMin, int iMax)
{
    return true;
}// end of ComplexMatrixValues::setRandom()

bool ComplexMatrixValues::deepCopyFrom(ComplexMatrixValues *that)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSMatrix, ENUM_OUTPUT_LEVEL_trace,
        "Make deep copy of ComplexMatrixValues");
#endif
    this->numberOfEl = that->numberOfEl;
    this->el = new std::complex<double>[numberOfEl];
    for (int i=0; i<numberOfEl; i++)
        this->el[i] = that->el[i];

    return true;
}// end of ComplexMatrixValues::deepCopyFrom()


/** ---------- Methods for class VarReferenceMatrixElements ---------- */
VarReferenceMatrixElements::VarReferenceMatrixElements():
    value(NULL)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSMatrix, ENUM_OUTPUT_LEVEL_trace,
        "Inside the VarReferenceMatrixElements Constructor");
    std::ostringstream outStr;
    outStr << "Allocate VarReferenceMatrixElements at address" << this;
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSMatrix, ENUM_OUTPUT_LEVEL_detailed_trace, outStr.str());
#endif
}// end of VarReferenceMatrixElements::VarReferenceMatrixElements()

VarReferenceMatrixElements::~VarReferenceMatrixElements()
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSMatrix, ENUM_OUTPUT_LEVEL_trace, 
        "Inside the VarReferenceMatrixElements Destructor");

    ostringstream outStr;
    outStr << "deleting VarReferenceMatrixElements at address" << this << std::endl;
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSMatrix, ENUM_OUTPUT_LEVEL_detailed_trace, outStr.str());
    outStr.str("");
    outStr.clear();
    outStr << "deleting VarReferenceMatrixElements->value at " << &value << std::endl;
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSMatrix, 
       ENUM_OUTPUT_LEVEL_detailed_trace, outStr.str());
#endif
    if (value != NULL)
        delete value;
    value = NULL;
}// end of VarReferenceMatrixElements::~VarReferenceMatrixElements()

ENUM_MATRIX_CONSTRUCTOR_TYPE VarReferenceMatrixElements::getNodeType()
{
    return ENUM_MATRIX_CONSTRUCTOR_TYPE_varRefElements;
}// end of VarReferenceMatrixElements::getNodeType()

std::string VarReferenceMatrixElements::getNodeName()
{
    return "varReferenceElements";
}// end of VarReferenceMatrixElements::getNodeName()


ENUM_MATRIX_TYPE VarReferenceMatrixElements::getInferredMatrixType()
{
std::cout << "at start of VarReferenceMatrixElements::getInferredMatrixType()" << std::endl;
    inferredMatrixType = ENUM_MATRIX_TYPE_varReference;
std::cout << "matrix constructor has inferred matrixType "
          << returnMatrixTypeString(inferredMatrixType) << std::endl;
    return inferredMatrixType;
}// end of VarReferenceMatrixElements::getInferredMatrixType()

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
        outStr << "<index>" << std::endl;
        outStr << writeIntVectorData(index, true, false);
        outStr << "</index>" << std::endl;

        outStr << "<value>" << std::endl;

        for(int i = 0; i < numberOfValues;)
        {
            getMultIncr(&(value->el[i]), &mult, &incr, (value->numberOfEl) - i, 0);
            if (mult == 1)
                outStr << "<el>";
            else if (incr == 0)
                outStr << "<el mult=\"" << mult << "\">";
            else
                outStr << "<el mult=\"" << mult << "\" incr=\"" << incr << "\">";
            outStr << value->el[i];
            outStr << "</el>" << std::endl;
            i += mult;
        }
        outStr << "</value>" << std::endl;
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

            if (!this->start->IsEqual(that->start)) return false;
            if (!this->index->IsEqual(that->index)) return false;
            if (!this->value->IsEqual(that->value)) return false;

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
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSMatrix, ENUM_OUTPUT_LEVEL_trace, "Inside the VarReferenceMatrixValues Constructor");
#endif
}// end of VarReferenceMatrixValues::VarReferenceMatrixValues()

VarReferenceMatrixValues::~VarReferenceMatrixValues()
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSMatrix, ENUM_OUTPUT_LEVEL_trace, 
        "Inside the VarReferenceMatrixValues Destructor");
    ostringstream outStr;
    outStr.str("");
    outStr.clear();
    outStr << "deleting VarReferenceMatrixValues->el at " << &el << std::endl;
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSMatrix, 
       ENUM_OUTPUT_LEVEL_detailed_trace, outStr.str());
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
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSMatrix, ENUM_OUTPUT_LEVEL_trace,
        "Make deep copy of VarReferenceMatrixValues");
#endif
    this->numberOfEl = that->numberOfEl;
    this->el = new int[numberOfEl];
    for (int i=0; i<numberOfEl; i++)
        this->el[i] = that->el[i];

    return true;
}// end of VarReferenceMatrixValues::deepCopyFrom()


/** ---------- Methods for class LinearMatrixElements ---------- */ 
LinearMatrixElements::LinearMatrixElements():
    value(NULL)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSMatrix, ENUM_OUTPUT_LEVEL_trace,
        "Inside the LinearMatrixElements Constructor");
    std::ostringstream outStr;
    outStr << "Allocate LinearMatrixElements at address" << this;
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSMatrix, ENUM_OUTPUT_LEVEL_detailed_trace, outStr.str());
#endif
}// end of LinearMatrixElements::LinearMatrixElements()

LinearMatrixElements::~LinearMatrixElements()
{
    std::ostringstream outStr;
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSMatrix, ENUM_OUTPUT_LEVEL_trace, 
        "Inside the LinearMatrixElements Destructor");
    outStr << "deleting LinearMatrixElements at address" << this << std::endl;
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSMatrix, ENUM_OUTPUT_LEVEL_detailed_trace, outStr.str());

    outStr.str("");
    outStr.clear();
    outStr << "deleting LinearMatrixElements->value at " << &value << std::endl;
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSMatrix, 
       ENUM_OUTPUT_LEVEL_detailed_trace, outStr.str());
#endif
    if (value != NULL)
        delete value;
    value = NULL;
}// end of LinearMatrixElements::~LinearMatrixElements()

ENUM_MATRIX_CONSTRUCTOR_TYPE LinearMatrixElements::getNodeType()
{
    return ENUM_MATRIX_CONSTRUCTOR_TYPE_linearElements;
}// end of LinearMatrixElements::getNodeType()

std::string LinearMatrixElements::getNodeName()
{
    return "linearElements";
}// end of LinearMatrixElements::getNodeName()


ENUM_MATRIX_TYPE LinearMatrixElements::getInferredMatrixType()
{
std::cout << "at start of LinearMatrixElements::getInferredMatrixType()" << std::endl;
    inferredMatrixType = ENUM_MATRIX_TYPE_linear;
std::cout << "matrix constructor has inferred matrixType "
          << returnMatrixTypeString(inferredMatrixType) << std::endl;
    return inferredMatrixType;
}// end of LinearMatrixElements::getInferredMatrixType()

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
        outStr << "<index>" << std::endl;
        outStr << writeIntVectorData(index, true, false);
        outStr << "</index>" << std::endl;

        outStr << "<value>" << std::endl;

        int i,j;
        for (i=0; i < numberOfValues; i++)
        {
            outStr << "<el";
            outStr << " numberOfVarIdx=\"" << value->el[i]->numberOfVarIdx << "\"";
            if (value->el[i]->constant != 0.0)
                outStr << " constant=\"" << value->el[i]->constant << "\"";
            outStr << ">" << std::endl;

            for (j=0; j < value->el[i]->numberOfVarIdx; j++)
            {
                outStr << "<varIdx";
                if (value->el[i]->varIdx[j]->coef != 1.0)
                    outStr << " coef=\"" << value->el[i]->varIdx[j]->coef << "\"";
                outStr << ">";
                outStr << value->el[i]->varIdx[j]->idx; 
                outStr << "</varIdx>" << std::endl;
            }

            outStr << "</el>" << std::endl;
        }
        outStr << "</value>" << std::endl;
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

            if (!this->start->IsEqual(that->start)) return false;
            if (!this->index->IsEqual(that->index)) return false;
            if (!this->value->IsEqual(that->value)) return false;

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

#if 0
/**
 *  Some methods to convert one type of matrix elements into another
 */
bool LinearMatrixElements::convertFromConstant(ConstantMatrixValues* _values, int nvalues)
{
    try
    {
        if (numberOfValues != nvalues)
            throw ErrorClass("ConvertFromConstantToLinear: number of values does not match ");

        if (this->value->el != NULL)
            delete this->value->el;

        this->value->el =  new LinearMatrixElement*[nvalues];

        for (int i=0; i<nvalues; i++)
        {
            this->value->el[i] =  new LinearMatrixElement();
            this->value->el[i]->constant = _values->el[i];
            this->value->el[i]->numberOfVarIdx = 0;
        }
        return true;
    }
    catch(const ErrorClass& eclass)
    {
        throw ErrorClass( eclass.errormsg);
    }
}// end of LinearMatrixElements::convertFromConstant

bool LinearMatrixElements::convertFromVarRef(VarReferenceMatrixValues* _values, int nvalues)
{
    try
    {
        if (numberOfValues != nvalues)
            throw ErrorClass("ConvertFromVarRefToLinear: number of values does not match ");

        if (this->value->el != NULL)
            delete this->value->el;

        this->value->el =  new LinearMatrixElement*[nvalues];

        for (int i=0; i<nvalues; i++)
        {
            this->value->el[i] =  new LinearMatrixElement();
            this->value->el[i]->constant = 0;
            this->value->el[i]->numberOfVarIdx = 1;
            this->value->el[i]->varIdx    = new LinearMatrixElementTerm*[1];
            this->value->el[i]->varIdx[0] = new LinearMatrixElementTerm();
            this->value->el[i]->varIdx[0]->idx  = _values->el[i];
            this->value->el[i]->varIdx[0]->coef = 0;
        }
        return true;
    }
    catch(const ErrorClass& eclass)
    {
        throw ErrorClass( eclass.errormsg);
    }
}// end of LinearMatrixElements::convertFromVarRef
#endif

/** ---------- Methods for class LinearMatrixValues ---------- */ 
LinearMatrixValues::LinearMatrixValues():
    el(NULL)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSMatrix, ENUM_OUTPUT_LEVEL_trace, 
        "Inside the LinearMatrixValues Constructor");

#endif
}// end of LinearMatrixValues::LinearMatrixValues()

LinearMatrixValues::~LinearMatrixValues()
{
    std::ostringstream outStr;
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSMatrix, ENUM_OUTPUT_LEVEL_trace, 
        "Inside the LinearMatrixValues Destructor");

    outStr.str("");
    outStr.clear();
    outStr << "deleting LinearMatrixValues->el at " << &el << std::endl;
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSMatrix, 
       ENUM_OUTPUT_LEVEL_detailed_trace, outStr.str());
#endif

    if (el != NULL)
    {
        for (int i=0; i < numberOfEl; i++)
        {
            if (el[i] != NULL)
            {
#ifndef NDEBUG
                outStr.str("");
                outStr.clear();
                outStr << "deleting LinearMatrixValues->el [" << i << "] at " << &el[i] << std::endl;
                osoutput->OSPrint(ENUM_OUTPUT_AREA_OSMatrix, 
                   ENUM_OUTPUT_LEVEL_detailed_trace, outStr.str());
#endif
                delete el[i];
                el[i] = NULL;
            }
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
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSMatrix, ENUM_OUTPUT_LEVEL_trace, "Make deep copy of LinearMatrixValues");
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
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSMatrix, 
                      ENUM_OUTPUT_LEVEL_trace, "Inside the LinearMatrixElement Constructor");
#endif
}// end of LinearMatrixElement::LinearMatrixElement()

LinearMatrixElement::~LinearMatrixElement()
{
    std::ostringstream outStr;
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSMatrix, 
                      ENUM_OUTPUT_LEVEL_trace, "Inside the LinearMatrixElement Destructor");
    outStr.str("");
    outStr.clear();
    outStr << "NUMBER OF VARIDX = " << numberOfVarIdx << endl;
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSMatrix, ENUM_OUTPUT_LEVEL_detailed_trace, outStr.str());
#endif
    if (varIdx != NULL)
    {
        for (int i=0; i < numberOfVarIdx; i++)
        {
#ifndef NDEBUG
            outStr.str("");
            outStr.clear();
            outStr << "DESTROYING VARIDX " << i << " at " << &varIdx[i] << std::endl;
            osoutput->OSPrint(ENUM_OUTPUT_AREA_OSMatrix, ENUM_OUTPUT_LEVEL_detailed_trace, outStr.str());
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
    try
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
    }
    catch(const ErrorClass& eclass)
    {
        throw ErrorClass( eclass.errormsg);
    }
}// end of LinearMatrixElement::deepCopyFrom()


/** ---------- Methods for class LinearMatrixElementTerm ---------- */ 
LinearMatrixElementTerm::LinearMatrixElementTerm():
    idx(-1),
    coef(1.0)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSMatrix, ENUM_OUTPUT_LEVEL_trace,
        "Inside the LinearMatrixElementTerm Constructor");
#endif
}// end of LinearMatrixElementTerm::LinearMatrixElementTerm()

LinearMatrixElementTerm::~LinearMatrixElementTerm()
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSMatrix, ENUM_OUTPUT_LEVEL_trace,
        "Inside the LinearMatrixElementTerm Destructor");
#endif
}// end of LinearMatrixElementTerm::~LinearMatrixElementTerm()

bool LinearMatrixElementTerm::IsEqual(LinearMatrixElementTerm *that)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSMatrix, ENUM_OUTPUT_LEVEL_trace,
        "Start comparing in LinearMatrixElementTerm");
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


/** ---------- Methods for class RealValuedExpressions ---------- */ 
RealValuedExpressions::RealValuedExpressions():
    value(NULL)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSMatrix, ENUM_OUTPUT_LEVEL_trace,
        "Inside the RealValuedExpressions Constructor");
    std::ostringstream outStr;
    outStr << "Allocate RealValuedExpressions at address" << this;
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSMatrix, ENUM_OUTPUT_LEVEL_detailed_trace, outStr.str());
#endif
}// end of RealValuedExpressions::RealValuedExpressions()

RealValuedExpressions::~RealValuedExpressions()
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSMatrix, ENUM_OUTPUT_LEVEL_trace,
        "Inside the RealValuedExpressions Destructor");

    ostringstream outStr;
    outStr << "deleting RealValuedExpressions at address" << this << std::endl;
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSMatrix, ENUM_OUTPUT_LEVEL_detailed_trace, outStr.str());
    outStr.str("");
    outStr.clear();
    outStr << "deleting RealValuedExpressions->value at " << &value << std::endl;
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSMatrix, ENUM_OUTPUT_LEVEL_detailed_trace, outStr.str());
#endif
    if (value != NULL)
        delete value;
    value = NULL;
}// end of RealValuedExpressions::~RealValuedExpressions()

ENUM_MATRIX_CONSTRUCTOR_TYPE RealValuedExpressions::getNodeType()
{
    return ENUM_MATRIX_CONSTRUCTOR_TYPE_realValuedExpressions;
}// end of RealValuedExpressions::getNodeType()

std::string RealValuedExpressions::getNodeName()
{
    return "realValuedExpressions";
}// end of RealValuedExpressions::getNodeName()


ENUM_MATRIX_TYPE RealValuedExpressions::getInferredMatrixType()
{
    inferredMatrixType = ENUM_MATRIX_TYPE_realValuedExpressions;
    return inferredMatrixType;
}// end of RealValuedExpressions::getInferredMatrixType()

std::string RealValuedExpressions::getMatrixNodeInXML()
{
    ostringstream outStr;
    outStr <<  "<realValuedExpressions";
    if (rowMajor)
        outStr << " rowMajor=\"true\"";
    outStr << " numberOfValues=\"" << numberOfValues << "\"";
    outStr << ">" << std::endl;

    outStr << "<start>" << std::endl;
    outStr << writeIntVectorData(start, true, false);
    outStr << "</start>" << std::endl;

    if (numberOfValues > 0)
    {
        outStr << "<index>" << std::endl;
        outStr << writeIntVectorData(index, true, false);
        outStr << "</index>" << std::endl;

        outStr << "<value>" << std::endl;

        for (int i=0; i < numberOfValues; i++)
        {
            outStr << "<el>";
            outStr << value->el[i]->m_treeRoot->getNonlinearExpressionInXML();
            outStr << "</el>" << std::endl;
        }
        outStr << "</value>" << std::endl;
    }
    outStr << "</realValuedExpressions>" << std::endl;
    return outStr.str();
}// end of RealValuedExpressions::getMatrixNodeInXML()

bool RealValuedExpressions::alignsOnBlockBoundary(int firstRow, int firstColumn, int nRows, int nCols)
{
    return false;
}// end of RealValuedExpressions::alignsOnBlockBoundary()

RealValuedExpressions* RealValuedExpressions::cloneMatrixNode()
{
    RealValuedExpressions *nodePtr;
    nodePtr = new RealValuedExpressions();
    return  (RealValuedExpressions*)nodePtr;
}// end of RealValuedExpressions::cloneMatrixNode

bool RealValuedExpressions::IsEqual(RealValuedExpressions *that)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSMatrix, ENUM_OUTPUT_LEVEL_trace, "Start comparing in RealValuedExpressions");
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

            if (!this->start->IsEqual(that->start)) return false;
            if (!this->index->IsEqual(that->index)) return false;
            if (!this->value->IsEqual(that->value)) return false;

            return true;
        }
    }
}// end of RealValuedExpressions::IsEqual()

bool RealValuedExpressions::setRandom(double density, bool conformant, int iMin, int iMax)
{
    return true;
}// end of RealValuedExpressions::setRandom()

bool RealValuedExpressions::deepCopyFrom(RealValuedExpressions *that)
{
    return true;
}// end of RealValuedExpressions::deepCopyFrom()


/** ---------- Methods for class RealValuedExpressionArray ---------- */ 
RealValuedExpressionArray::RealValuedExpressionArray():
    el(NULL)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSMatrix, ENUM_OUTPUT_LEVEL_trace, "Inside the RealValuedExpressionArray Constructor");
#endif
}// end of RealValuedExpressionArray::RealValuedExpressionArray()

RealValuedExpressionArray::~RealValuedExpressionArray()
{
    std::ostringstream outStr;

#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSMatrix, 
                      ENUM_OUTPUT_LEVEL_trace, "Inside the RealValuedExpressionArray Destructor");
    outStr.str("");
    outStr.clear();
    outStr << "NUMBER OF VALUES = " << numberOfEl << endl;
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSMatrix, ENUM_OUTPUT_LEVEL_detailed_trace, outStr.str());
#endif
    if (numberOfEl > 0 && el != NULL)
    {
        for (int i=0; i < numberOfEl; i++)
        {
            if (el[i] != NULL)
            {
#ifndef NDEBUG
                outStr.str("");
                outStr.clear();
                outStr << "deleting ConstantMatrixValues->el [" << i << "] at " << &el[i] << std::endl;
                osoutput->OSPrint(ENUM_OUTPUT_AREA_OSMatrix, 
                   ENUM_OUTPUT_LEVEL_detailed_trace, outStr.str());
#endif
                delete el[i];
                el[i] = NULL;
            }            
        }
    }
    if (el != NULL)
        delete [] el;
    el = NULL;
}// end of RealValuedExpressionArray::~RealValuedExpressionArray()

bool RealValuedExpressionArray::IsEqual(RealValuedExpressionArray *that)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSMatrix, 
        ENUM_OUTPUT_LEVEL_trace, "Start comparing in RealValuedExpressionArray");
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
}// end of RealValuedExpressionArray::IsEqual()

bool RealValuedExpressionArray::deepCopyFrom(RealValuedExpressionArray *that)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSMatrix, ENUM_OUTPUT_LEVEL_trace, "Make deep copy of RealValuedExpressionArray");
#endif
    this->numberOfEl = that->numberOfEl;
    this->el = new RealValuedExpressionTree*[numberOfEl];
    for (int i=0; i<numberOfEl; i++)
    {
        this->el[i] = new RealValuedExpressionTree();
//        this->el[i]->m_treeRoot = new OSnLNode();
        ((OSnLNode*)this->el[i]->m_treeRoot->cloneExprNode());
    }
    return true;
}// end of RealValuedExpressionArray::deepCopyFrom()


/** ---------- Methods for class ComplexValuedExpressions ---------- */ 
ComplexValuedExpressions::ComplexValuedExpressions():
    value(NULL)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSMatrix, ENUM_OUTPUT_LEVEL_trace,
        "Inside the ComplexValuedExpressions Constructor");
    std::ostringstream outStr;
    outStr << "Allocate ComplexValuedExpressions at address" << this;
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSMatrix, ENUM_OUTPUT_LEVEL_detailed_trace, outStr.str());
#endif
}// end of ComplexValuedExpressions::ComplexValuedExpressions()

ComplexValuedExpressions::~ComplexValuedExpressions()
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSMatrix, ENUM_OUTPUT_LEVEL_trace,
        "Inside the ComplexValuedExpressions Destructor");

    ostringstream outStr;
    outStr << "deleting ComplexValuedExpressions at address" << this << std::endl;
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSMatrix, ENUM_OUTPUT_LEVEL_detailed_trace, outStr.str());
    outStr.str("");
    outStr.clear();
    outStr << "deleting ComplexValuedExpressions->value at " << &value << std::endl;
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSMatrix, 
       ENUM_OUTPUT_LEVEL_detailed_trace, outStr.str());
#endif
    if (value != NULL)
        delete value;
    value = NULL;
}// end of ComplexValuedExpressions::~ComplexValuedExpressions()

ENUM_MATRIX_CONSTRUCTOR_TYPE ComplexValuedExpressions::getNodeType()
{
    return ENUM_MATRIX_CONSTRUCTOR_TYPE_complexValuedExpressions;
}// end of ComplexValuedExpressions::getNodeType()

std::string ComplexValuedExpressions::getNodeName()
{
    return "complexValuedExpressions";
}// end of ComplexValuedExpressions::getNodeName()


ENUM_MATRIX_TYPE ComplexValuedExpressions::getInferredMatrixType()
{
std::cout << "at start of ComplexValuedExpressions::getInferredMatrixType()" << std::endl;
    inferredMatrixType = ENUM_MATRIX_TYPE_complexValuedExpressions;
std::cout << "matrix constructor has inferred matrixType "
          << returnMatrixTypeString(inferredMatrixType) << std::endl;
    return inferredMatrixType;
}// end of ComplexValuedExpressions::getInferredMatrixType()

std::string ComplexValuedExpressions::getMatrixNodeInXML()
{
    ostringstream outStr;
    outStr <<  "<complexValuedExpressions";
    if (rowMajor)
        outStr << " rowMajor=\"true\"";
    outStr << " numberOfValues=\"" << numberOfValues << "\"";
    outStr << ">" << std::endl;

    outStr << "<start>" << std::endl;
    outStr << writeIntVectorData(start, true, false);
    outStr << "</start>" << std::endl;

    if (numberOfValues > 0)
    {
        outStr << "<index>" << std::endl;
        outStr << writeIntVectorData(index, true, false);
        outStr << "</index>" << std::endl;

        outStr << "<value>" << std::endl;

        for (int i=0; i < numberOfValues; i++)
        {
            outStr << "<el>";
            outStr << value->el[i]->m_treeRoot->getNonlinearExpressionInXML();
            outStr << "</el>" << std::endl;
        }
        outStr << "</value>" << std::endl;
    }
    outStr << "</complexValuedExpressions>" << std::endl;
    return outStr.str();
}// end of ComplexValuedExpressions::getMatrixNodeInXML()

bool ComplexValuedExpressions::alignsOnBlockBoundary(int firstRow, int firstColumn, int nRows, int nCols)
{
    return false;
}// end of ComplexValuedExpressions::alignsOnBlockBoundary()

ComplexValuedExpressions* ComplexValuedExpressions::cloneMatrixNode()
{
    ComplexValuedExpressions *nodePtr;
    nodePtr = new ComplexValuedExpressions();
    return  (ComplexValuedExpressions*)nodePtr;
}// end of ComplexValuedExpressions::cloneMatrixNode

bool ComplexValuedExpressions::IsEqual(ComplexValuedExpressions *that)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSMatrix, ENUM_OUTPUT_LEVEL_trace, "Start comparing in ComplexValuedExpressions");
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

            if (!this->start->IsEqual(that->start)) return false;
            if (!this->index->IsEqual(that->index)) return false;
            if (!this->value->IsEqual(that->value)) return false;

            return true;
        }
    }
}// end of ComplexValuedExpressions::IsEqual()

bool ComplexValuedExpressions::setRandom(double density, bool conformant, int iMin, int iMax)
{
    return true;
}// end of ComplexValuedExpressions::setRandom()

bool ComplexValuedExpressions::deepCopyFrom(ComplexValuedExpressions *that)
{
    return true;
}// end of ComplexValuedExpressions::deepCopyFrom()


/** ---------- Methods for class ComplexValuedExpressionArray ---------- */
ComplexValuedExpressionArray::ComplexValuedExpressionArray():
    el(NULL)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSMatrix, ENUM_OUTPUT_LEVEL_trace, "Inside the ComplexValuedExpressionArray Constructor");
#endif
}// end of ComplexValuedExpressionArray::ComplexValuedExpressionArray()

ComplexValuedExpressionArray::~ComplexValuedExpressionArray()
{
    std::ostringstream outStr;

#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSMatrix, 
                      ENUM_OUTPUT_LEVEL_trace, "Inside the ComplexValuedExpressionArray Destructor");
    outStr.str("");
    outStr.clear();
    outStr << "NUMBER OF VALUES = " << numberOfEl << endl;
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSMatrix, ENUM_OUTPUT_LEVEL_detailed_trace, outStr.str());
#endif
    if (numberOfEl > 0 && el != NULL)
    {
        for (int i=0; i < numberOfEl; i++)
        {
            if (el[i] != NULL)
            {
#ifndef NDEBUG
                outStr.str("");
                outStr.clear();
                outStr << "deleting ComplexValuedExpressions->el [" << i << "] at " << &el[i] << std::endl;
                osoutput->OSPrint(ENUM_OUTPUT_AREA_OSMatrix, 
                   ENUM_OUTPUT_LEVEL_detailed_trace, outStr.str());
#endif
                delete el[i];
                el[i] = NULL;
            }            
        }
    }
    if (el != NULL)
        delete [] el;
    el = NULL;
}// end of ComplexValuedExpressionArray::~ComplexValuedExpressionArray()

bool ComplexValuedExpressionArray::IsEqual(ComplexValuedExpressionArray *that)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSMatrix, 
        ENUM_OUTPUT_LEVEL_trace, "Start comparing in ComplexValuedExpressionArray");
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
}// end of ComplexValuedExpressionArray::IsEqual()

bool ComplexValuedExpressionArray::deepCopyFrom(ComplexValuedExpressionArray *that)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSMatrix, ENUM_OUTPUT_LEVEL_trace, "Make deep copy of ComplexValuedExpressionArray");
#endif
    this->numberOfEl = that->numberOfEl;
    this->el = new ComplexValuedExpressionTree*[numberOfEl];
    for (int i=0; i<numberOfEl; i++)
    {
        this->el[i] = new ComplexValuedExpressionTree();
//        this->el[i]->m_treeRoot = new OSnLNode();
        ((OSnLNode*)this->el[i]->m_treeRoot->cloneExprNode());
    }
    return true;
}// end of ComplexValuedExpressionArray::deepCopyFrom()

/**
 *  Some methods to convert one type of matrix element into another
 */
/*------------------------------------------------------
RealValuedExpressionTree* RealValuedExpressionArray::convertFromConstant(double val)
{
    ostringstream outStr;
    outStr << os_dtoa_format(val);
    return outStr.str();
}// end of RealValuedExpressionArray::convertFromConstant

RealValuedExpressionTree* RealValuedExpressionArray::convertFromVarRef(int varref)
{
    ostringstream outStr;
    outStr << "x_" << varref;
    return outStr.str();
}// end of RealValuedExpressionArray::convertFromVarRef

RealValuedExpressionTree* RealValuedExpressionArray::convertFromLinear(LinearMatrixElement* val)
{//a0 + a1x1 + a2x2 + ...
    ostringstream outStr;
    if (val->constant != 0.0)
    {
        outStr << os_dtoa_format(val->constant);
    }
    if (val->numberOfVarIdx > 0)
    {
        if (val->varIdx[0]->coef >= 0)
        {
            if (val->constant != 0.0)
                outStr << " + ";
            else
                outStr << " - ";
        }
        else
            outStr << "-";
        if (val->varIdx[0]->coef != 1)
            outStr << os_dtoa_format(abs(val->varIdx[0]->coef)) << "*";
        outStr << "x_" << val->varIdx[0]->idx;
    }
    for (int i=1; i<val->numberOfVarIdx; i++)
    {
        if (val->varIdx[i]->coef >= 0)
           outStr << " + ";
        else
           outStr << " - ";
        if (val->varIdx[i]->coef != 1)
            outStr << os_dtoa_format(abs(val->varIdx[i]->coef)) << "*";
        outStr << "x_" << val->varIdx[i]->idx;
    }
    return outStr.str();
}// end of RealValuedExpressionArray::convertFromLinear

RealValuedExpressionTree* RealValuedExpressionArray::convertFromObjRef(int objRef)
{
    ostringstream outStr;
    outStr << "o_" << objRef;
    return outStr.str();
}// end of RealValuedExpressionArray::convertFromObjRef

RealValuedExpressionTree* RealValuedExpressionArray::convertFromConRef(ConReferenceMatrixElement* val)
{
    ostringstream outStr;
    outStr << "c_" << val->conReference << "." << returnConReferenceValueTypeString(val->valueType);
    return outStr.str();
}// end of RealValuedExpressionArray::convertFromConRef
=======================================*/

/** ---------- Methods for class ObjReferenceMatrixElements ---------- */
ObjReferenceMatrixElements::ObjReferenceMatrixElements():
    value(NULL)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSMatrix, ENUM_OUTPUT_LEVEL_trace,
        "Inside the ObjReferenceMatrixElements Constructor");
    std::ostringstream outStr;
    outStr << "Allocate ObjReferenceMatrixElements at address" << this;
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSMatrix, ENUM_OUTPUT_LEVEL_detailed_trace, outStr.str());
#endif
}// end of ObjReferenceMatrixElements::ObjReferenceMatrixElements()

ObjReferenceMatrixElements::~ObjReferenceMatrixElements()
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSMatrix, ENUM_OUTPUT_LEVEL_trace,
        "Inside the ObjReferenceMatrixElements Destructor");

    ostringstream outStr;
    outStr << "deleting ObjReferenceMatrixElements at address" << this << std::endl;
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSMatrix, ENUM_OUTPUT_LEVEL_detailed_trace, outStr.str());
    outStr.str("");
    outStr.clear();
    outStr << "deleting ObjReferenceMatrixElements->value at " << &value << std::endl;
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSMatrix, 
       ENUM_OUTPUT_LEVEL_detailed_trace, outStr.str());
#endif
    if (value != NULL)
        delete value;
    value = NULL;
}// end of ObjReferenceMatrixElements::~ObjReferenceMatrixElements()

ENUM_MATRIX_CONSTRUCTOR_TYPE ObjReferenceMatrixElements::getNodeType()
{
    return ENUM_MATRIX_CONSTRUCTOR_TYPE_objRefElements;
}// end of ObjReferenceMatrixElements::getNodeType()

std::string ObjReferenceMatrixElements::getNodeName()
{
    return "objRefElements";
}// end of ObjReferenceMatrixElements::getNodeName()


ENUM_MATRIX_TYPE ObjReferenceMatrixElements::getInferredMatrixType()
{
std::cout << "at start of ObjReferenceMatrixElements::getInferredMatrixType()" << std::endl;
    inferredMatrixType = ENUM_MATRIX_TYPE_objReference;
std::cout << "matrix constructor has inferred matrixType "
          << returnMatrixTypeString(inferredMatrixType) << std::endl;
    return inferredMatrixType;
}// end of ObjReferenceMatrixElements::getInferredMatrixType()

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
        outStr << "<index>" << std::endl;
        outStr << writeIntVectorData(index, true, false);
        outStr << "</index>" << std::endl;

        outStr << "<value>" << std::endl;

        for(int i = 0; i < numberOfValues;)
        {
            getMultIncr(&(value->el[i]), &mult, &incr, (value->numberOfEl) - i, 0);
            if (mult == 1)
                outStr << "<el>";
            else if (incr == 0)
                outStr << "<el mult=\"" << mult << "\">";
            else
                outStr << "<el mult=\"" << mult << "\" incr=\"" << incr << "\">";
            outStr << value->el[i];
            outStr << "</el>" << std::endl;
            i += mult;
        }
        outStr << "</value>" << std::endl;
    }

    outStr << "</objReferenceElements>" << std::endl;
    return outStr.str();
}// end of ObjReferenceMatrixElements::getMatrixNodeInXML()

bool ObjReferenceMatrixElements::alignsOnBlockBoundary(int firstRow, int firstColumn, int nRows, int nCols)
{
    return false;
}// end of ObjReferenceMatrixElements::alignsOnBlockBoundary()

ObjReferenceMatrixElements* ObjReferenceMatrixElements::cloneMatrixNode()
{
    ObjReferenceMatrixElements *nodePtr;
    nodePtr = new ObjReferenceMatrixElements();
    return  (ObjReferenceMatrixElements*)nodePtr;
}// end of ObjReferenceMatrixElements::cloneMatrixNode

bool ObjReferenceMatrixElements::IsEqual(ObjReferenceMatrixElements *that)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSMatrix, ENUM_OUTPUT_LEVEL_trace,
        "Start comparing in ObjReferenceMatrixElements");
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

            if (!this->start->IsEqual(that->start)) return false;
            if (!this->index->IsEqual(that->index)) return false;
            if (!this->value->IsEqual(that->value)) return false;

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
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSMatrix, ENUM_OUTPUT_LEVEL_trace,
        "Inside the ObjReferenceMatrixValues Constructor");
#endif
}// end of ObjReferenceMatrixValues::ObjReferenceMatrixValues()

ObjReferenceMatrixValues::~ObjReferenceMatrixValues()
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSMatrix, ENUM_OUTPUT_LEVEL_trace,
        "Inside the ObjReferenceMatrixValues Destructor");

    ostringstream outStr;
    outStr.str("");
    outStr.clear();
    outStr << "deleting ObjReferenceMatrixValues->el at " << &el << std::endl;
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSMatrix, 
       ENUM_OUTPUT_LEVEL_detailed_trace, outStr.str());
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
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSMatrix, ENUM_OUTPUT_LEVEL_trace, "Make deep copy of ObjReferenceMatrixValues");
#endif
    this->numberOfEl = that->numberOfEl;
    this->el = new int[numberOfEl];
    for (int i=0; i<numberOfEl; i++)
        this->el[i] = that->el[i];
    return true;
}// end of ObjReferenceMatrixValues::deepCopyFrom()


/** ---------- Methods for class ConReferenceMatrixElements ---------- */
ConReferenceMatrixElements::ConReferenceMatrixElements():
    value(NULL)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSMatrix, ENUM_OUTPUT_LEVEL_trace,
        "Inside the ConReferenceMatrixElements Constructor");
    std::ostringstream outStr;
    outStr << "Allocate ConReferenceMatrixElements at address" << this;
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSMatrix, ENUM_OUTPUT_LEVEL_detailed_trace, outStr.str());
#endif
}// end of ConReferenceMatrixElements::ConReferenceMatrixElements()

ConReferenceMatrixElements::~ConReferenceMatrixElements()
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSMatrix, ENUM_OUTPUT_LEVEL_trace,
        "Inside the ConReferenceMatrixElements Destructor");

    ostringstream outStr;
    outStr << "deleting ConReferenceMatrixElements at address" << this << std::endl;
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSMatrix, ENUM_OUTPUT_LEVEL_detailed_trace, outStr.str());
    outStr.str("");
    outStr.clear();
    outStr << "deleting ConReferenceMatrixElements->value at " << &value << std::endl;
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSMatrix, 
       ENUM_OUTPUT_LEVEL_detailed_trace, outStr.str());
#endif
    if (value != NULL)
        delete value;
    value = NULL;
}// end of ConReferenceMatrixElements::~ConReferenceMatrixElements()

ENUM_MATRIX_CONSTRUCTOR_TYPE ConReferenceMatrixElements::getNodeType()
{
    return ENUM_MATRIX_CONSTRUCTOR_TYPE_conRefElements;
}// end of ConReferenceMatrixElements::getNodeType()

std::string ConReferenceMatrixElements::getNodeName()
{
    return "conRefElements";
}// end of ConReferenceMatrixElements::getNodeName()


ENUM_MATRIX_TYPE ConReferenceMatrixElements::getInferredMatrixType()
{
std::cout << "at start of ConReferenceMatrixElements::getInferredMatrixType()" << std::endl;
    inferredMatrixType = ENUM_MATRIX_TYPE_conReference;
std::cout << "matrix constructor has inferred matrixType "
          << returnMatrixTypeString(inferredMatrixType) << std::endl;
    return inferredMatrixType;
}// end of ConReferenceMatrixElements::getInferredMatrixType()

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
        outStr << "<index>" << std::endl;
        outStr << writeIntVectorData(index, true, false);
        outStr << "</index>" << std::endl;

        outStr << "<value>" << std::endl;

        for(int i = 0; i < numberOfValues; i++)
        {
            outStr << "<el";
            if (value->el[i]->valueType != ENUM_CONREFERENCE_VALUETYPE_value)
            {
                outStr << " valueType=\"";
                outStr << returnConReferenceValueTypeString(value->el[i]->valueType) << "\"";
            }
            outStr << ">";
            outStr << os_dtoa_format(value->el[i]->conReference);
            outStr << "</el>" << std::endl;
        }
        outStr << "</value>" << std::endl;
    }

    outStr << "</conReferenceElements>" << std::endl;
    return outStr.str();
}// end of ConReferenceMatrixElements::getMatrixNodeInXML()

bool ConReferenceMatrixElements::alignsOnBlockBoundary(int firstRow, int firstColumn, int nRows, int nCols)
{
    return false;
}// end of ConReferenceMatrixElements::alignsOnBlockBoundary()

ConReferenceMatrixElements* ConReferenceMatrixElements::cloneMatrixNode()
{
    ConReferenceMatrixElements *nodePtr;
    nodePtr = new ConReferenceMatrixElements();
    return  (ConReferenceMatrixElements*)nodePtr;
}// end of ConReferenceMatrixElements::cloneMatrixNode

bool ConReferenceMatrixElements::IsEqual(ConReferenceMatrixElements *that)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSMatrix, ENUM_OUTPUT_LEVEL_trace,
        "Start comparing in ConReferenceMatrixElements");
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

            if (!this->start->IsEqual(that->start)) return false;
            if (!this->index->IsEqual(that->index)) return false;
            if (!this->value->IsEqual(that->value)) return false;

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

#if 0
bool ConReferenceMatrixElements::convertFromObjRef(ObjReferenceMatrixValues* _values, int nvalues)
{
    try
    {
        ostringstream outStr;

        if (numberOfValues != nvalues)
            throw ErrorClass("ConvertFromObjRefToVarRef: number of values does not match ");

        if (this->value->el == NULL)
            this->value->el =  new ConReferenceMatrixElement*[nvalues];

        for (int i=0; i<nvalues; i++)
        {
            if (this->value->el[i] == NULL)
                this->value->el[i] =  new ConReferenceMatrixElement();

            this->value->el[i]->conReference = _values->el[i];
            this->value->el[i]->valueType = ENUM_CONREFERENCE_VALUETYPE_value;
        }
        return true;
    }
    catch(const ErrorClass& eclass)
    {
        throw ErrorClass( eclass.errormsg);
    }
}// end of ConReferenceMatrixElements::convertFromObjRef
#endif

/** ---------- Methods for class ConReferenceMatrixValues ---------- */
ConReferenceMatrixValues::ConReferenceMatrixValues():
    el(NULL)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSMatrix, ENUM_OUTPUT_LEVEL_trace, "Inside the ConReferenceMatrixValues Constructor");
#endif
}// end of ConReferenceMatrixValues::ConReferenceMatrixValues()

ConReferenceMatrixValues::~ConReferenceMatrixValues()
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSMatrix, ENUM_OUTPUT_LEVEL_trace, "Inside the ConReferenceMatrixValues Destructor");
#endif
    if (numberOfEl > 0 && el != NULL)
    {
        for (int i=0; i < numberOfEl; i++)
        {
            if (el[i] != NULL)
            {
#ifndef NDEBUG
                ostringstream outStr;
                outStr.str("");
                outStr.clear();
                outStr << "deleting ConstantMatrixValues->el [" << i << "] at " << &el[i] << std::endl;
                osoutput->OSPrint(ENUM_OUTPUT_AREA_OSMatrix, 
                   ENUM_OUTPUT_LEVEL_detailed_trace, outStr.str());
#endif
                delete el[i];
                el[i] = NULL;
            }
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
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSMatrix, ENUM_OUTPUT_LEVEL_trace, "Make deep copy of ConReferenceMatrixValues");
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
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSMatrix, ENUM_OUTPUT_LEVEL_trace, "Inside the ConReferenceMatrixElement Constructor");
#endif
}// end of ConReferenceMatrixElement::ConReferenceMatrixElement()

ConReferenceMatrixElement::~ConReferenceMatrixElement()
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSMatrix, ENUM_OUTPUT_LEVEL_trace, "Inside the ConReferenceMatrixElement Destructor");
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

/** ---------- Methods for class MixedRowReferenceMatrixElements ---------- */
MixedRowReferenceMatrixElements::MixedRowReferenceMatrixElements():
    value(NULL)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSMatrix, ENUM_OUTPUT_LEVEL_trace,
        "Inside the MixedRowReferenceMatrixElements Constructor");
#endif
}// end of MixedRowReferenceMatrixElements::MixedRowReferenceMatrixElements()

MixedRowReferenceMatrixElements::~MixedRowReferenceMatrixElements()
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSMatrix, ENUM_OUTPUT_LEVEL_trace,
        "Inside the MixedRowReferenceMatrixElements Destructor");
#endif
    if (value != NULL)
        delete value;
    value = NULL;
}// end of MixedRowReferenceMatrixElements::~MixedRowReferenceMatrixElements()

ENUM_MATRIX_CONSTRUCTOR_TYPE MixedRowReferenceMatrixElements::getNodeType()
{
    return ENUM_MATRIX_CONSTRUCTOR_TYPE_mixedRowRefElements;
}// end of MixedRowReferenceMatrixElements::getNodeType()

std::string MixedRowReferenceMatrixElements::getNodeName()
{
    return "mixedRowRefElements";
}// end of MixedRowReferenceMatrixElements::getNodeName()


ENUM_MATRIX_TYPE MixedRowReferenceMatrixElements::getInferredMatrixType()
{
std::cout << "at start of MixedRowReferenceMatrixElements::getInferredMatrixType()" << std::endl;
    inferredMatrixType = ENUM_MATRIX_TYPE_mixedRowReference;
std::cout << "matrix constructor has inferred matrixType "
          << returnMatrixTypeString(inferredMatrixType) << std::endl;
    return inferredMatrixType;
}// end of MixedRowReferenceMatrixElements::getInferredMatrixType()

std::string MixedRowReferenceMatrixElements::getMatrixNodeInXML()
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
            if (value->el[j]->conReference < 0) tmpNum++;
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
                    if (value->el[j]->conReference < 0) tmpNum++;
                }
                outStr << "<el>" << tmpNum << "</el>" << std::endl;
            }
            outStr << "</start>" << std::endl;

            outStr << "<index>" << std::endl;
            for (i=0; i < start->numberOfEl - 1; i++)
            {
                for (j=start->el[i]; j<start->el[i+1]; j++)
                {
                    if (value->el[j]->conReference < 0) 
                        outStr << "<el>" << index->el[j] << "</el>";
                }
            }
            outStr << "</index>" << std::endl;

            outStr << "<value>" << std::endl;
            for (i=0; i < start->numberOfEl - 1; i++)
            {
                for (j=start->el[i]; j<start->el[i+1]; j++)
                {
                    if (value->el[j]->conReference < 0) 
                        outStr << "<el>" << value->el[j]->conReference << "</el>";
                }
            }
            outStr << "</value>" << std::endl;
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
                    if (value->el[j]->conReference >= 0) tmpNum++;
                }
                outStr << "<el>" << tmpNum << "</el>" << std::endl;
            }
            outStr << "</start>" << std::endl;

            outStr << "<index>" << std::endl;
            for (i=0; i < start->numberOfEl - 1; i++)
            {
                for (j=start->el[i]; j<start->el[i+1]; j++)
                {
                    if (value->el[j]->conReference >= 0) 
                        outStr << "<el>" << index->el[j] << "</el>";
                }
            }
            outStr << "</index>" << std::endl;

            outStr << "<value>" << std::endl;
            for (i=0; i < start->numberOfEl - 1; i++)
            {
                for (j=start->el[i]; j<start->el[i+1]; j++)
                {
                    if (value->el[j]->conReference >= 0)
                    {
                        outStr << "<el";
                        if (value->el[i]->valueType != ENUM_CONREFERENCE_VALUETYPE_value)
                        {
                            outStr << " valueType=\"";
                            outStr << returnConReferenceValueTypeString(value->el[i]->valueType) << "\"";
                        }
                        outStr << ">" << value->el[j]->conReference << "</el>";
                    }
                }
            }
            outStr << "</value>" << std::endl;
            outStr << "</conReferenceElements>" << std::endl;

        }
        else // there are only objReferenceElements
        {
            outStr << "<start>" << std::endl;
            outStr << writeIntVectorData(start, true, false);
            outStr << "</start>" << std::endl;

            if (numberOfValues > 0)
            {
                outStr << "<index>" << std::endl;
                outStr << writeIntVectorData(index, true, false);
                outStr << "</index>" << std::endl;

                outStr << "<value>" << std::endl;

                for(int i = 0; i < numberOfValues; i++)
                {
                    outStr << "<el";
                    //gus: work out mult and incr
                    outStr << ">";
                    outStr << os_dtoa_format(value->el[i]->conReference);
                    outStr << "</el>" << std::endl;
                }
                outStr << "</value>" << std::endl;
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
            outStr << "<index>" << std::endl;
            outStr << writeIntVectorData(index, true, false);
            outStr << "</index>" << std::endl;

            outStr << "<value>" << std::endl;

            for(int i = 0; i < numberOfValues; i++)
            {
                outStr << "<el";
                if (value->el[i]->valueType != ENUM_CONREFERENCE_VALUETYPE_value)
                {
                    outStr << " valueType=\"";
                    outStr << returnConReferenceValueTypeString(value->el[i]->valueType) << "\"";
                }
                //gus: work out mult and incr
                outStr << ">";
                outStr << os_dtoa_format(value->el[i]->conReference);
                outStr << "</el>" << std::endl;
            }
            outStr << "</value>" << std::endl;
        }
        outStr << "</conReferenceElements>" << std::endl;
    }

    return outStr.str();
}// end of MixedRowReferenceMatrixElements::getMatrixNodeInXML()

bool MixedRowReferenceMatrixElements::alignsOnBlockBoundary(int firstRow, int firstColumn, int nRows, int nCols)
{
    return false;
}// end of MixedRowReferenceMatrixElements::alignsOnBlockBoundary()

MixedRowReferenceMatrixElements* MixedRowReferenceMatrixElements::cloneMatrixNode()
{
    MixedRowReferenceMatrixElements *nodePtr;
    nodePtr = new MixedRowReferenceMatrixElements();
    return  (MixedRowReferenceMatrixElements*)nodePtr;
}// end of MixedRowReferenceMatrixElements::cloneMatrixNode

bool MixedRowReferenceMatrixElements::IsEqual(MixedRowReferenceMatrixElements *that)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSMatrix, ENUM_OUTPUT_LEVEL_trace,
        "Start comparing in MixedRowReferenceMatrixElements");
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

            if (!this->start->IsEqual(that->start)) return false;
            if (!this->index->IsEqual(that->index)) return false;
            if (!this->value->IsEqual(that->value)) return false;

            return true;
        }
    }
}// end of MixedRowReferenceMatrixElements::IsEqual()

bool MixedRowReferenceMatrixElements::setRandom(double density, bool conformant, int iMin, int iMax)
{
    return true;
}// end of MixedRowReferenceMatrixElements::setRandom()

bool MixedRowReferenceMatrixElements::deepCopyFrom(MixedRowReferenceMatrixElements *that)
{
    return true;
}// end of MixedRowReferenceMatrixElements::deepCopyFrom()

/** ---------- Methods for class StringValuedMatrixElements ---------- */
StringValuedMatrixElements::StringValuedMatrixElements():
    value(NULL)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSMatrix, ENUM_OUTPUT_LEVEL_trace,
        "Inside the StringValuedMatrixElements Constructor");
    std::ostringstream outStr;
    outStr << "Allocate StringValuedMatrixElements at address" << this;
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSMatrix, ENUM_OUTPUT_LEVEL_detailed_trace, outStr.str());
#endif
}// end of StringValuedMatrixElements::StringValuedMatrixElements()

StringValuedMatrixElements::~StringValuedMatrixElements()
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSMatrix, ENUM_OUTPUT_LEVEL_trace, 
        "Inside the StringValuedMatrixElements Destructor");

    ostringstream outStr;
    outStr << "deleting StringValuedMatrixElements at address" << this << std::endl;
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSMatrix, ENUM_OUTPUT_LEVEL_detailed_trace, outStr.str());
    outStr.str("");
    outStr.clear();
    outStr << "deleting StringValuedMatrixElements->value at " << &value << std::endl;
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSMatrix, 
       ENUM_OUTPUT_LEVEL_detailed_trace, outStr.str());
#endif
    if (value != NULL)
        delete value;
    value = NULL;
}// end of StringValuedMatrixElements::~StringValuedMatrixElements()

ENUM_MATRIX_CONSTRUCTOR_TYPE StringValuedMatrixElements::getNodeType()
{
    return ENUM_MATRIX_CONSTRUCTOR_TYPE_stringValuedElements;
}// end of StringValuedMatrixElements::getNodeType()

std::string StringValuedMatrixElements::getNodeName()
{
    return "stringValuedElements";
}// end of StringValuedMatrixElements::getNodeName()


ENUM_MATRIX_TYPE StringValuedMatrixElements::getInferredMatrixType()
{
std::cout << "at start of StringValuedMatrixElements::getInferredMatrixType()" << std::endl;
    inferredMatrixType = ENUM_MATRIX_TYPE_string;
std::cout << "matrix constructor has inferred matrixType "
          << returnMatrixTypeString(inferredMatrixType) << std::endl;
    return inferredMatrixType;
}// end of StringValuedMatrixElements::getInferredMatrixType()

std::string StringValuedMatrixElements::getMatrixNodeInXML()
{
    ostringstream outStr;
    outStr <<  "<stringValuedElements";
    if (rowMajor)
        outStr << " rowMajor=\"true\"";
    outStr << " numberOfValues=\"" << numberOfValues << "\"";
    outStr << ">" << std::endl;

    outStr << "<start>" << std::endl;
    outStr << writeIntVectorData(start, true, false);
    outStr << "</start>" << std::endl;

    if (numberOfValues > 0)
    {
        outStr << "<index>" << std::endl;
        outStr << writeIntVectorData(index, true, false);
        outStr << "</index>" << std::endl;

        outStr << "<value>" << std::endl;

        for(int i = 0; i < numberOfValues;)
        {
            int mult = getMult(&(value->el[i]), numberOfValues - i);
            if (mult == 1)
                outStr << "<el>" ;
            else
                outStr << "<el mult=\"" << mult << "\">";
            outStr << value->el[i];
            outStr << "</el>" << std::endl;
            i += mult;
        }
        outStr << "</value>" << std::endl;
    }

    outStr << "</stringValuedElements>" << std::endl;
    return outStr.str();
}// end of StringValuedMatrixElements::getMatrixNodeInXML()

bool StringValuedMatrixElements::alignsOnBlockBoundary(int firstRow, int firstColumn, int nRows, int nCols)
{
    return false;
}// end of StringValuedMatrixElements::alignsOnBlockBoundary()

StringValuedMatrixElements* StringValuedMatrixElements::cloneMatrixNode()
{
    StringValuedMatrixElements *nodePtr;
    nodePtr = new StringValuedMatrixElements();
    return  (StringValuedMatrixElements*)nodePtr;
}// end of StringValuedMatrixElements::cloneMatrixNode

bool StringValuedMatrixElements::IsEqual(StringValuedMatrixElements *that)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSMatrix, ENUM_OUTPUT_LEVEL_trace, "Start comparing in StringValuedMatrixElements");
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

            if (!this->start->IsEqual(that->start)) return false;
            if (!this->index->IsEqual(that->index)) return false;
            if (!this->value->IsEqual(that->value)) return false;

            return true;
        }
    }
}// end of StringValuedMatrixElements::IsEqual()

bool StringValuedMatrixElements::setRandom(double density, bool conformant, int iMin, int iMax)
{
    return true;
}// end of StringValuedMatrixElements::setRandom()

bool StringValuedMatrixElements::deepCopyFrom(StringValuedMatrixElements *that)
{
    return true;
}// end of StringValuedMatrixElements::deepCopyFrom()


#if 0
/**
 *  Some methods to convert one type of matrix elements into another
 */
bool StringValuedMatrixElements::convertFromConstant(ConstantMatrixValues* _values, int nvalues)
{
    try
    {
        if (numberOfValues != nvalues)
            throw ErrorClass("ConvertFromConstantToString: number of values does not match ");

        if (this->value->el == NULL)
            this->value->el =  new std::string[nvalues];

        for (int i=0; i<nvalues; i++)
            this->value->el[i] = os_dtoa_format(_values->el[i]);
        return true;
    }
    catch(const ErrorClass& eclass)
    {
        throw ErrorClass( eclass.errormsg);
    }
}// end of StringValuedMatrixElements::convertFromConstant

bool StringValuedMatrixElements::convertFromVarRef(VarReferenceMatrixValues* _values, int nvalues)
{
    try
    {
        ostringstream outStr;

        if (numberOfValues != nvalues)
            throw ErrorClass("ConvertFromVarRefToString: number of values does not match ");

        if (this->value->el == NULL)
            this->value->el =  new std::string[nvalues];

        for (int i=0; i<nvalues; i++)
        {
            outStr.str("");
            outStr.clear();
            outStr << "x_" << _values->el[i];
            this->value->el[i] = outStr.str();
        }
        return true;
    }
    catch(const ErrorClass& eclass)
    {
        throw ErrorClass( eclass.errormsg);
    }
}// end of StringValuedMatrixElements::convertFromVarRef

bool StringValuedMatrixElements::convertFromLinear(LinearMatrixValues* _values, int nvalues)
{//a0 + a1x1 + a2x2 + ...
    try
    {
        ostringstream outStr;

        if (numberOfValues != nvalues)
            throw ErrorClass("ConvertFromLinearToString: number of values does not match ");

        if (this->value->el == NULL)
            this->value->el =  new std::string[nvalues];

        for (int i=0; i<nvalues; i++)
        {
            outStr.str("");
            outStr.clear();

            if (_values->el[i]->constant < 0.0 || _values->el[i]->constant > 0.0)
            {
                outStr << os_dtoa_format(_values->el[i]->constant);
            }
            if (_values->el[i]->numberOfVarIdx > 0)
            {
                if (_values->el[i]->varIdx[0]->coef >= 0)
                {
                    if (_values->el[i]->constant < 0.0 || _values->el[i]->constant > 0.0)
                        outStr << " + ";
                    else
                        outStr << " - ";
                }
                else
                    outStr << "-";
                if (_values->el[i]->varIdx[0]->coef < 1 || _values->el[i]->varIdx[0]->coef > 1 )
                    outStr << os_dtoa_format(abs(_values->el[i]->varIdx[0]->coef)) << "*";
                outStr << "x_" << _values->el[i]->varIdx[0]->idx;
            }
            for (int j=1; j<_values->el[i]->numberOfVarIdx; i++)
            {
                if (_values->el[i]->varIdx[j]->coef >= 0)
                   outStr << " + ";
                else
                   outStr << " - ";
                if (_values->el[i]->varIdx[j]->coef < 1 || _values->el[i]->varIdx[j]->coef > 1 )
                    outStr << os_dtoa_format(abs(_values->el[i]->varIdx[j]->coef)) << "*";
                outStr << "x_" << _values->el[i]->varIdx[j]->idx;
            }
            this->value->el[i] = outStr.str();
        }
        return true;
    }
    catch(const ErrorClass& eclass)
    {
        throw ErrorClass( eclass.errormsg);
    }
}// end of StringValuedMatrixElements::convertFromLinear

bool StringValuedMatrixElements::convertFromObjRef(ObjReferenceMatrixValues* _values, int nvalues)
{
    try
    {
        ostringstream outStr;

        if (numberOfValues != nvalues)
            throw ErrorClass("ConvertFromObjRefToString: number of values does not match ");

        if (this->value->el == NULL)
            this->value->el =  new std::string[nvalues];

        for (int i=0; i<nvalues; i++)
        {
            outStr.str("");
            outStr.clear();
            outStr << "o_" << _values->el[i];
            this->value->el[i] = outStr.str();
        }
        return true;
    }
    catch(const ErrorClass& eclass)
    {
        throw ErrorClass( eclass.errormsg);
    }
}// end of StringValuedMatrixElements::convertFromObjRef

bool StringValuedMatrixElements::convertFromConRef(ConReferenceMatrixValues* _values, int nvalues)
{
    try
    {
        ostringstream outStr;

        if (numberOfValues != nvalues)
            throw ErrorClass("ConvertFromConRefToString: number of values does not match ");

        if (this->value->el == NULL)
            this->value->el =  new std::string[nvalues];

        for (int i=0; i<nvalues; i++)
        {
            outStr.str("");
            outStr.clear();
            outStr << "c_" << _values->el[i]->conReference << "." 
                   << returnConReferenceValueTypeString(_values->el[i]->valueType);
            this->value->el[i] = outStr.str();
        }
        return true;
    }
    catch(const ErrorClass& eclass)
    {
        throw ErrorClass( eclass.errormsg);
    }
}// end of StringValuedMatrixElements::convertFromConRef

bool StringValuedMatrixElements::convertFromGeneral(RealValuedExpressionArray* _values, int nvalues)
{
    try
    {
        std::vector<ExprNode*> postfixVec;
        ostringstream outStr;

        if (numberOfValues != nvalues)
            throw ErrorClass("ConvertFromGeneralToString: number of values does not match ");

        if (this->value->el == NULL)
            this->value->el =  new std::string[nvalues];

        for (int i=0; i<nvalues; i++)
        {
            if (_values->el[i] != NULL)
            {
                postfixVec = _values->el[i]->getPostfixFromExpressionTree();
                this->value->el[i] = getExpressionTreeAsInfixString(postfixVec);
            }
            else
                this->value->el[i] = "";
        }
        return true;
    }
    catch(const ErrorClass& eclass)
    {
        throw ErrorClass( eclass.errormsg);
    }
}// end of StringValuedMatrixElements::convertFromGeneral
#endif

/** ---------- Methods for class StringValuedMatrixValues ---------- */
StringValuedMatrixValues::StringValuedMatrixValues():
    el(NULL)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSMatrix, ENUM_OUTPUT_LEVEL_trace, "Inside the StringValuedMatrixValues Constructor");
#endif
}// end of StringValuedMatrixValues::StringValuedMatrixValues()

StringValuedMatrixValues::~StringValuedMatrixValues()
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSMatrix, ENUM_OUTPUT_LEVEL_trace, "Inside the StringValuedMatrixValues Destructor");
    ostringstream outStr;
    outStr.str("");
    outStr.clear();
    outStr << "deleting StringValuedMatrixValues->el at " << &el << std::endl;
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSMatrix, 
       ENUM_OUTPUT_LEVEL_detailed_trace, outStr.str());
#endif
    if (el != NULL)
        delete [] el;
    el = NULL;
}// end of StringValuedMatrixValues::~StringValuedMatrixValues()

bool StringValuedMatrixValues::IsEqual(StringValuedMatrixValues *that)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSMatrix, ENUM_OUTPUT_LEVEL_trace, "Start comparing in StringValuedMatrixValues");
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
}// end of StringValuedMatrixValues::IsEqual()

bool StringValuedMatrixValues::setRandom(double density, bool conformant, int iMin, int iMax)
{
    return true;
}// end of StringValuedMatrixValues::setRandom()

bool StringValuedMatrixValues::deepCopyFrom(StringValuedMatrixValues *that)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSMatrix, ENUM_OUTPUT_LEVEL_trace, "Make deep copy of StringValuedMatrixValues");
#endif
    this->numberOfEl = that->numberOfEl;
    this->el = new std::string[numberOfEl];
    for (int i=0; i<numberOfEl; i++)
        this->el[i] = that->el[i];

    return true;
}// end of StringValuedMatrixValues::deepCopyFrom()



/** ---------- Methods for class MatrixBlocks ---------- */
MatrixBlocks::MatrixBlocks():
    colOffset(NULL),
    rowOffset(NULL)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSMatrix, ENUM_OUTPUT_LEVEL_trace,
        "Inside the MatrixBlocks Constructor");
    std::ostringstream outStr;
    outStr << "Allocate MatrixBlocks at address" << this;
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSMatrix, ENUM_OUTPUT_LEVEL_detailed_trace, outStr.str());
#endif
    nType = ENUM_MATRIX_CONSTRUCTOR_TYPE_blocks;
}// end of MatrixBlocks::MatrixBlocks()

MatrixBlocks::~MatrixBlocks()
{
    std::ostringstream outStr;

#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSMatrix, ENUM_OUTPUT_LEVEL_trace,
        "Inside the MatrixBlocks Destructor");
    outStr << "deleting MatrixBlocks at address" << this << std::endl;
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSMatrix, ENUM_OUTPUT_LEVEL_detailed_trace, outStr.str());
    outStr.str("");
    outStr.clear();
    outStr << "NUMBER OF BLOCKS = " << inumberOfChildren << endl;
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSMatrix, ENUM_OUTPUT_LEVEL_detailed_trace, outStr.str());

    outStr.str("");
    outStr.clear();
    outStr << "deleting MatrixBlocks->colOffset at " << &colOffset << std::endl;
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSMatrix, 
       ENUM_OUTPUT_LEVEL_detailed_trace, outStr.str());

    outStr.str("");
    outStr.clear();
    outStr << "deleting MatrixBlocks->rowOffset at " << &rowOffset << std::endl;
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSMatrix, 
       ENUM_OUTPUT_LEVEL_detailed_trace, outStr.str());
#endif
    if (colOffset != NULL)
        delete colOffset;
    colOffset = NULL;

    if (rowOffset != NULL)
        delete rowOffset;
    rowOffset = NULL;

#if 0
    if(inumberOfChildren > 0 && block != NULL)
    {
        for (int i=0; i < numberOfBlocks; i++)
        {
            if (block[i] != NULL)
            {
#ifndef NDEBUG
                outStr.str("");
                outStr.clear();
                outStr << "deleting MatrixBlocks->block [" << i << "] at " << &block[i] << std::endl;
                osoutput->OSPrint(ENUM_OUTPUT_AREA_OSMatrix, 
                   ENUM_OUTPUT_LEVEL_detailed_trace, outStr.str());
#endif
                delete block[i];
                block[i] = NULL;
            }
        }
    }
    if (block != NULL)
        delete [] block;
    block = NULL;
#endif
}// end of MatrixBlocks::~MatrixBlocks()

ENUM_MATRIX_CONSTRUCTOR_TYPE MatrixBlocks::getNodeType()
{
    return ENUM_MATRIX_CONSTRUCTOR_TYPE_blocks;
}// end of MatrixBlocks::getNodeType()

std::string MatrixBlocks::getNodeName()
{
    return "blocks";
}// end of MatrixBlocks::getNodeName()

#if 0
ENUM_MATRIX_TYPE MatrixBlocks::getMatrixType()
{
    if (matrixType == ENUM_MATRIX_TYPE_unknown)
    {
        matrixType =  ENUM_MATRIX_TYPE_empty;
        for (unsigned int i=0; i<inumberOfChildren; i++)
            matrixType = mergeMatrixType(matrixType, m_mChildren[i]->getMatrixType());
    }
    return matrixType;
}// end of MatrixBlocks::getMatrixType()
#endif

std::string MatrixBlocks::getMatrixNodeInXML()
{
    ostringstream outStr;
    outStr << "<blocks numberOfBlocks=\"" << inumberOfChildren << "\">" << std::endl;
    outStr << "<colOffset numberOfEl=\"" << colOffset->numberOfEl << "\">" << std::endl;
    outStr << writeIntVectorData(colOffset, true, false);
    outStr << "</colOffset>" << std::endl;
    outStr << "<rowOffset numberOfEl=\"" << rowOffset->numberOfEl << "\">" << std::endl; 
    outStr << writeIntVectorData(rowOffset, true, false);
    outStr << "</rowOffset>" << std::endl;

    for (unsigned int i=0; i < inumberOfChildren; i++)
        outStr << m_mChildren[i]->getMatrixNodeInXML();

    outStr << "</blocks>" << std::endl;
    return outStr.str();
}// end of MatrixBlocks::getMatrixNodeInXML()

bool MatrixBlocks::alignsOnBlockBoundary(int firstRow, int firstColumn, int nRows, int nCols)
{
    bool accumulator = false;
    int  nrBlocks = rowOffset->numberOfEl - 1;
    int  ncBlocks = colOffset->numberOfEl - 1;
    for (int i=0; i < nrBlocks; i++)
        if ( (rowOffset->el[i] == firstRow) && ((firstRow+nRows) == rowOffset->el[i+1]) )
        {
            accumulator = true;
            break;
        }
    if (!accumulator) return false;
    for (int i=0; i < ncBlocks; i++)
        if ( (colOffset->el[i] == firstColumn) && ((firstColumn+nCols) == colOffset->el[i+1]) )
        {
            accumulator = true;
            break;
        }
    return accumulator;
}// end of MatrixTransformation::alignsOnBlockBoundary()

MatrixBlocks* MatrixBlocks::cloneMatrixNode()
{
    MatrixNode *nodePtr;
    nodePtr = new MatrixBlocks();
    return  (MatrixBlocks*)nodePtr;
}// end of MatrixBlocks::cloneMatrixNode

bool MatrixBlocks::IsEqual(MatrixBlocks *that)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSMatrix, ENUM_OUTPUT_LEVEL_debug, "Start comparing in MatrixBlocks");
#endif
    if (this == NULL)
    {
        if (that == NULL)
            return true;
        else
        {
#ifndef NDEBUG
            osoutput->OSPrint(ENUM_OUTPUT_AREA_OSMatrix, ENUM_OUTPUT_LEVEL_debug, 
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
            osoutput->OSPrint(ENUM_OUTPUT_AREA_OSMatrix, ENUM_OUTPUT_LEVEL_debug, 
                "Second object is NULL, first is not");
#endif
            return false;
        }
        else
        {
            if (!this->colOffset->IsEqual(that->colOffset))
                return false;
            if (!this->rowOffset->IsEqual(that->rowOffset))
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
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSMatrix, ENUM_OUTPUT_LEVEL_trace,
        "Inside the MatrixBlock Constructor");
    std::ostringstream outStr;
    outStr << "Allocate MatrixBlock at address" << this;
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSMatrix, ENUM_OUTPUT_LEVEL_detailed_trace, outStr.str());
#endif
    nType    = ENUM_MATRIX_CONSTRUCTOR_TYPE_block;
    symmetry = ENUM_MATRIX_SYMMETRY_default;
}// end of MatrixBlock

MatrixBlock::~MatrixBlock()
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSMatrix, ENUM_OUTPUT_LEVEL_trace,
        "Inside the MatrixBlock Destructor");
    std::ostringstream outStr;
    outStr << "deleting MatrixBlock at address" << this << std::endl;
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSMatrix, ENUM_OUTPUT_LEVEL_detailed_trace, outStr.str());
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

#if 0
ENUM_MATRIX_TYPE MatrixBlock::getMatrixType()
{
    if (matrixType == ENUM_MATRIX_TYPE_unknown)
    {
        matrixType =  ENUM_MATRIX_TYPE_empty;
        for (unsigned int i=0; i<inumberOfChildren; i++)
        {
            matrixType = mergeMatrixType(matrixType, m_mChildren[i]->getMatrixType());
        }
    }
    return matrixType;
}// end of MatrixBlock::getMatrixType()
#endif

std::string MatrixBlock::getMatrixNodeInXML()
{
    ostringstream outStr;
    outStr << "<block";
    outStr << " blockRowIdx=\"" << blockRowIdx << "\"";
    outStr << " blockColIdx=\"" << blockColIdx << "\"";
    if (symmetry != ENUM_MATRIX_SYMMETRY_none)
        outStr << " symmetry=\"" << returnMatrixSymmetryString(symmetry) << "\"";
    if (declaredMatrixType != ENUM_MATRIX_TYPE_unknown) 
        outStr << " type=\"" << returnMatrixTypeString(declaredMatrixType) << "\"";

    if (inumberOfChildren > 0)
    {
        outStr << ">" << std::endl;
        for (unsigned int i=0; i < inumberOfChildren; i++)
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

bool MatrixBlock::expandElements(OSMatrix** mtxIdx, bool rowMajor)
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
    numberOfRows(-1),
    numberOfColumns(-1),
    valueType(ENUM_MATRIX_TYPE_unknown),
    isRowMajor(false),
    symmetry(ENUM_MATRIX_SYMMETRY_none),
    startSize(-1),
    valueSize(-1),
    start(NULL),
    index(NULL),
    value(NULL),
    b_deleteStartArray(true),
    b_deleteIndexArray(true),
    b_deleteValueArray(true)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSMatrix, ENUM_OUTPUT_LEVEL_trace,
        "Inside the GeneralSparseMatrix Constructor");
    std::ostringstream outStr;
    outStr << "Allocate GeneralSparseMatrix at address" << this;
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSMatrix, ENUM_OUTPUT_LEVEL_detailed_trace, outStr.str());
#endif
}// end of GeneralSparseMatrix default constructor

GeneralSparseMatrix::GeneralSparseMatrix(bool isRowMajor_, int numberOfRows_, int numberOfColumns_,
                                         int startSize_, int valueSize_, ENUM_MATRIX_TYPE type_):
    b_deleteStartArray(true),
    b_deleteIndexArray(true),
    b_deleteValueArray(true),
    value(NULL)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSMatrix, ENUM_OUTPUT_LEVEL_trace,
        "Inside the alternate GeneralSparseMatrix Constructor");
    std::ostringstream outStr;
    outStr << "Allocate GeneralSparseMatrix at address" << this;
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSMatrix, ENUM_OUTPUT_LEVEL_detailed_trace, outStr.str());
#endif
    numberOfRows    = numberOfRows_;
    numberOfColumns = numberOfColumns_;
    isRowMajor      = isRowMajor_;
    startSize       = startSize_;
    valueSize       = valueSize_;
    valueType       = type_;
    start = new int[startSize];
    index = new int[valueSize];
    if (!allocateValueArray(valueSize))
        throw ErrorClass("In GeneralSparseMatrix constructor: error allocating value array");
}// end of GeneralSparseMatrix special constructor

GeneralSparseMatrix::~GeneralSparseMatrix()
{
#ifndef NDEBUG
    ostringstream outStr;

    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSMatrix, ENUM_OUTPUT_LEVEL_trace,
        "Inside the GeneralSparseMatrix Destructor");
    outStr << "deleting GeneralSparseMatrix at address" << this << std::endl;
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSMatrix, ENUM_OUTPUT_LEVEL_detailed_trace, outStr.str());
#endif
    if (b_deleteStartArray)
    {
        if (start != NULL) 
        {
#ifndef NDEBUG
            outStr.str("");
            outStr.clear();
            outStr << "deleting GeneralSparseMatrix->start at " << &start << std::endl;
            osoutput->OSPrint(ENUM_OUTPUT_AREA_OSMatrix, 
                              ENUM_OUTPUT_LEVEL_detailed_trace, outStr.str());
#endif
            delete [] start;
            start = NULL;
        }        
    }
    if (b_deleteIndexArray)
    {
        if (index != NULL)
        {
#ifndef NDEBUG
            outStr.str("");
            outStr.clear();
            outStr << "deleting GeneralSparseMatrix->index at " << &index << std::endl;
            osoutput->OSPrint(ENUM_OUTPUT_AREA_OSMatrix, 
               ENUM_OUTPUT_LEVEL_detailed_trace, outStr.str());
#endif
            delete [] index;
            index = NULL;
        }
    }
    if (b_deleteValueArray)
    {
        if (value != NULL) 
        {
#ifndef NDEBUG
            outStr.str("");
            outStr.clear();
            outStr << "deleting GeneralSparseMatrix->value at " << &value << std::endl;
            osoutput->OSPrint(ENUM_OUTPUT_AREA_OSMatrix, 
               ENUM_OUTPUT_LEVEL_detailed_trace, outStr.str());
#endif
            delete value;
            value = NULL;
        }
    }
}// end of ~GeneralSparseMatrix

bool GeneralSparseMatrix::isDiagonal()
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSMatrix, ENUM_OUTPUT_LEVEL_trace, 
        "Inside GeneralSparseMatrix::isDiagonal()");
#endif
    if (valueSize == 0)
        return true;
    if (valueSize >= startSize)
        return false;

    for (int i=1; i < startSize; i++)
    {
        if (start[i] - start[i-1] > 1)
            return false;
        for (int j=start[i-1]; j<start[i]; j++)
            if (index[j] != i-1)
                return false;
    }

    return true;
}// end of GeneralSparseMatrix::isDiagonal

bool GeneralSparseMatrix::printMatrix()
{
    std::ostringstream outStr;
    try
    {
        if (isRowMajor)
        {
            outStr << "Matrix is in row major form" << std::endl;
            outStr << "Number of rows: " << startSize-1 << std::endl;
        }
        else
        {
            outStr << "Matrix is in column major form" << std::endl;
            outStr << "Number of columns: " << startSize-1 << std::endl;
        }

        outStr << "number of nonzeros " << valueSize << std::endl;
        outStr << "type of nonzeros   " << returnMatrixTypeString(valueType)    << std::endl;
        outStr << "symmetry           " << returnMatrixSymmetryString(symmetry) << std::endl;

        outStr << std::endl << "starts: ";
        for (int i=0; i < startSize; i++)
            outStr << "  " << start[i];
        outStr << std::endl;

        outStr << std::endl << "indexes:";
        for (int i=0; i < valueSize; i++)
            outStr << "  " << index[i];
        outStr << std::endl;

        outStr << std::endl << "values: ";
        if (valueType == ENUM_MATRIX_TYPE_constant)
        {
            for (int i=0; i < valueSize; i++)
                outStr << "  " << ((ConstantMatrixValues*)value)->el[i];
            outStr << std::endl;
        }
        else if (valueType == ENUM_MATRIX_TYPE_varReference)
        {
            for (int i=0; i < valueSize; i++)
                outStr << "  " << ((VarReferenceMatrixValues*)value)->el[i];
            outStr << std::endl;
        }
        else if (valueType == ENUM_MATRIX_TYPE_objReference) 
        {
            for (int i=0; i < valueSize; i++)
                outStr << "  " << ((ObjReferenceMatrixValues*)value)->el[i];
            outStr << std::endl;
        }
        else if (valueType == ENUM_MATRIX_TYPE_conReference) 
        {
            for (int i=0; i < valueSize; i++)
                outStr << "  " << ((ConReferenceMatrixValues*)value)->el[i]->conReference;
            outStr << std::endl;
        }
        else if (valueType == ENUM_MATRIX_TYPE_realValuedExpressions) 
        {
            std::vector<ExprNode*> postfixVec;
            outStr << std::endl;
            for (int i=0; i < valueSize; i++)
            {
                if (((RealValuedExpressionArray*)value)->el[i] != NULL)
                {
                    postfixVec = 
                        ((RealValuedExpressionArray*)value)->el[i]->getPostfixFromExpressionTree();
                    outStr << "element " << i << ": " 
                           << getExpressionTreeAsInfixString(postfixVec) << std::endl;
                }
            }
            outStr << std::endl;
        }
        else if (valueType == ENUM_MATRIX_TYPE_complexValuedExpressions) 
        {
            std::vector<ExprNode*> postfixVec;
            ComplexValuedExpressionTree* tmpTree;

            outStr << std::endl;
            for (int i=0; i < valueSize; i++)
            {
                if (((ComplexValuedExpressionArray*)value)->el[i] != NULL)
                {
                    postfixVec = 
                        ((ComplexValuedExpressionArray*)value)->el[i]->getPostfixFromExpressionTree();
                    outStr << "element " << i << ": " 
                           << getExpressionTreeAsInfixString(postfixVec) << std::endl;
                }
            }
            outStr << std::endl;
        }
        else if (valueType == ENUM_MATRIX_TYPE_linear) 
        {
            outStr << std::endl;
            for (int i=0; i < valueSize; i++)
            {
                outStr << "element " << i << ": ";

                double c = ((LinearMatrixElement*)((LinearMatrixValues*)value)->el[i])->constant;
                int    m = ((LinearMatrixElement*)((LinearMatrixValues*)value)->el[i])->numberOfVarIdx;
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
                    temp = ((LinearMatrixElement*)((LinearMatrixValues*)value)->el[i])->varIdx[j];
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
}// end of printMatrix

bool GeneralSparseMatrix::allocateValueArray(int nValues)
{
    try
    {
        if (nValues < 0)
            throw ErrorClass("Attempting to allocate an array of negative size!");  
        switch (this->valueType)
        {
            case ENUM_MATRIX_TYPE_empty:
            {
                if (nValues != 0)
                    throw ErrorClass("Matrix should be empty, but is not!!!");
                break;
            }

            case ENUM_MATRIX_TYPE_constant:
            {
                this->value = new ConstantMatrixValues();
                ((ConstantMatrixValues*)this->value)->el = new double[nValues];
                break;
            }

            case ENUM_MATRIX_TYPE_complexConstant:
            {
                this->value = new ComplexMatrixValues();
                ((ComplexMatrixValues*)this->value)->el = new std::complex<double>[nValues];
                break;
            }

            case ENUM_MATRIX_TYPE_varReference:
            {
                this->value = new VarReferenceMatrixValues();
                ((VarReferenceMatrixValues*)this->value)->el = new int[nValues];
                break;
            }

            case ENUM_MATRIX_TYPE_linear:
            {
                this->value = new LinearMatrixValues();
                ((LinearMatrixValues*)this->value)->el = new LinearMatrixElement*[nValues];
                break;
            }

            case ENUM_MATRIX_TYPE_objReference:
            {
                this->value = new ObjReferenceMatrixValues();
                ((ObjReferenceMatrixValues*)this->value)->el = new int[nValues];
                break;
            }

            case ENUM_MATRIX_TYPE_mixedRowReference:
            case ENUM_MATRIX_TYPE_conReference:
            {
                this->value = new ConReferenceMatrixValues();
                ((ConReferenceMatrixValues*)this->value)->el = new ConReferenceMatrixElement*[nValues];
                break;
            }

            case ENUM_MATRIX_TYPE_realValuedExpressions:
            {
                this->value = new RealValuedExpressionArray();
                ((RealValuedExpressionArray*)this->value)->el = new RealValuedExpressionTree*[nValues];
                break;
            }
    
            case ENUM_MATRIX_TYPE_complexValuedExpressions:
            {
                this->value = new ComplexValuedExpressionArray();
                ((ComplexValuedExpressionArray*)this->value)->el
                    = new ComplexValuedExpressionTree*[nValues];
                for (int i=0; i < nValues; i++)
                    ((ComplexValuedExpressionArray*)this->value)->el[i] = NULL;
                break;
            }
    
            case ENUM_MATRIX_TYPE_string:
            {
                this->value = new StringValuedMatrixValues();
                ((StringValuedMatrixValues*)this->value)->el = new std::string[nValues];
                break;
            }

            default :
                throw ErrorClass("Unsupported matrix type");
                break;
        }
        return true;
    }
    catch(const ErrorClass& eclass)
    {
        throw ErrorClass( eclass.errormsg);
    }
}//end of allocateValueArray

bool GeneralSparseMatrix::copyValue(GeneralSparseMatrix* sourceMtx, int sourceIndex, int targetIndex,
                                                                double scalarMult, double scalarImag) 
{
    ComplexValuedExpressionTree* temp = NULL;

    try
    {
        if (this->value == NULL)
            throw ErrorClass("in copyValue: value array of target matrix was never allocated!");

        int scaleType = 0;
        if (scalarImag < 0 || scalarImag >0)
        {
            if (this->valueType != mergeMatrixType(this->valueType, ENUM_MATRIX_TYPE_complexConstant))
                throw ErrorClass("in copyValue(): value array not properly allocated");
            scaleType = 2;
        }
        else if (scalarMult < 1 || scalarMult > 1)
        {
            if (this->valueType != mergeMatrixType(this->valueType, ENUM_MATRIX_TYPE_constant))
                throw ErrorClass("in copyValue(): value array not properly allocated");
            scaleType = 1;
        }

        std::complex <double> complexScalar (scalarMult, scalarImag);

        // copy element and convert as indicated in matrixType of target and source matrices
        switch (this->valueType)
        {
            // the first three types are minimal types, so no conversion is necessary,
            // and copying is much simpler as well
            case ENUM_MATRIX_TYPE_constant:
                ((ConstantMatrixValues*)this->value)->el[targetIndex]
                    = scalarMult*((ConstantMatrixValues*)sourceMtx->value)->el[sourceIndex];
                break;

            // if type is varReference, the scalar multiplier must be absent (i.e., 1.0)
            case ENUM_MATRIX_TYPE_varReference:
                ((VarReferenceMatrixValues*)this->value)->el[targetIndex] 
                    = ((VarReferenceMatrixValues*)sourceMtx->value)->el[sourceIndex];
                break;

            // scalar multiplier must be 1.0 
            case ENUM_MATRIX_TYPE_objReference:
                ((ObjReferenceMatrixValues*)this->value)->el[targetIndex]
                    = ((ObjReferenceMatrixValues*)sourceMtx->value)->el[sourceIndex];
                break;

            // conReference is minimal, but the copying is a little more complicated
            // the scalar multiplier must again be 1
            case ENUM_MATRIX_TYPE_conReference:
                ((ConReferenceMatrixValues*)this->value)->el[targetIndex] = new ConReferenceMatrixElement();
                if (sourceMtx->valueType == ENUM_MATRIX_TYPE_conReference)
                {
                    ((ConReferenceMatrixValues*)this->value)->el[targetIndex]
                            ->deepCopyFrom(((ConReferenceMatrixValues*)sourceMtx->value)->el[sourceIndex]);
                }
                else 
                    throw ErrorClass ("undefined matrix element conversion");
                break;

            // The other types may require conversion and more elaborate copying
            // First, complexConstant. The only legal conversion is from (real) constant
            case ENUM_MATRIX_TYPE_complexConstant:
                if (sourceMtx->valueType == ENUM_MATRIX_TYPE_complexConstant)
                {
                     std::complex<double> (((ComplexMatrixValues*)this->value)->el[targetIndex])
                                         = ((ComplexMatrixValues*)sourceMtx->value)->el[sourceIndex];  
                }
                else if (sourceMtx->valueType == ENUM_MATRIX_TYPE_constant)
                {
                    std::complex<double> (((ComplexMatrixValues*)this->value)->el[targetIndex])
                        = convertToComplexMatrixElement(
                                  ((ConstantMatrixValues*)sourceMtx->value)->el[sourceIndex]);  
                }
                else 
                    throw ErrorClass ("undefined matrix element conversion");
                break;

                // deal with any scalar multiples
                if (scaleType == 1)
                    ((ComplexMatrixValues*)this->value)->el[targetIndex] *= scalarMult;
                else if (scaleType == 2)
                    ((ComplexMatrixValues*)this->value)->el[targetIndex] *= complexScalar;

            case ENUM_MATRIX_TYPE_linear:
                ((LinearMatrixValues*)this->value)->el[targetIndex] = new LinearMatrixElement();
                switch (sourceMtx->valueType)
                {
                    // linear elements do not have to be converted
                    case ENUM_MATRIX_TYPE_linear:
                        ((LinearMatrixValues*)this->value)->el[targetIndex]
                            = ((LinearMatrixValues*)sourceMtx->value)->el[sourceIndex];

                        // there may be a real-valued scalar, however
                        if (scaleType == 1)
                        {
                            LinearMatrixElement* tempLin
                                = ((LinearMatrixValues*)this->value)->el[targetIndex];
                            tempLin->constant *= scalarMult;
                            for (int vi=0; vi < tempLin->numberOfVarIdx; vi++)
                                tempLin->varIdx[vi]->coef *= scalarMult;
                        }
                        break;

                    // legal conversions: constant, varReference
                    case ENUM_MATRIX_TYPE_constant:
                        ((LinearMatrixValues*)this->value)->el[targetIndex]->constant
                            = scalarMult*((ConstantMatrixValues*)sourceMtx->value)->el[sourceIndex];
                        break;

                    case ENUM_MATRIX_TYPE_varReference:
                        ((LinearMatrixValues*)this->value)->el[targetIndex]->numberOfVarIdx = 1; 
                        ((LinearMatrixValues*)this->value)->el[targetIndex]->varIdx 
                            = new LinearMatrixElementTerm*[1]; 
                        ((LinearMatrixValues*)this->value)->el[targetIndex]->varIdx[0]
                            = new LinearMatrixElementTerm();
                        ((LinearMatrixValues*)this->value)->el[targetIndex]->varIdx[0]->idx 
                            = ((VarReferenceMatrixValues*)sourceMtx->value)->el[sourceIndex];
                        ((LinearMatrixValues*)this->value)->el[targetIndex]->varIdx[0]->coef = scalarMult; 
                        break;

                    // other conversion are illegal
                    default: throw ErrorClass ("undefined matrix element conversion");
                        break;
                }//end switch (sourceMtx->valueType)
                break;

            case ENUM_MATRIX_TYPE_mixedRowReference:
                ((ConReferenceMatrixValues*)
                    this->value)->el[targetIndex] = new ConReferenceMatrixElement();
                switch (sourceMtx->valueType)
                {
                    // elements with constraint references do not have to be converted
                    case ENUM_MATRIX_TYPE_mixedRowReference:
                    case ENUM_MATRIX_TYPE_conReference:
                        ((ConReferenceMatrixValues*)this->value)->el[targetIndex]->deepCopyFrom(
                             ((ConReferenceMatrixValues*)sourceMtx->value)->el[sourceIndex]);
                        break;

                    // only other legal possibility: objective references
                    case ENUM_MATRIX_TYPE_objReference:
                        ((ConReferenceMatrixValues*)
                            this->value)->el[targetIndex] = new ConReferenceMatrixElement();
                        ((ConReferenceMatrixValues*)this->value)->el[targetIndex]->conReference
                            = ((ObjReferenceMatrixValues*)sourceMtx->value)->el[sourceIndex];
                        break;

                    default:
                        throw ErrorClass ("undefined matrix element conversion");
                        break;
                }//end switch (sourceMtx->valueType)
                break;

            case ENUM_MATRIX_TYPE_realValuedExpressions:
            {
                switch (sourceMtx->valueType)
                {
                    case ENUM_MATRIX_TYPE_constant:
                        ((RealValuedExpressionArray*)this->value)->el[targetIndex]
                            = convertToRealExpressionTree(
                                        ((ConstantMatrixValues*)sourceMtx->value)->el[sourceIndex]);  
                        break;

                    case ENUM_MATRIX_TYPE_varReference:
                        ((RealValuedExpressionArray*)this->value)->el[targetIndex]
                            = convertToRealExpressionTree(
                                ((VarReferenceMatrixValues*)sourceMtx->value)->el[sourceIndex], true);
                        break;

                    case ENUM_MATRIX_TYPE_realValuedExpressions:
                    {
                        ((RealValuedExpressionArray*)this->value)->el[targetIndex]
                            = ((RealValuedExpressionArray*)
                                     sourceMtx->value)->el[sourceIndex]->cloneExpressionTree();
                        break;
                    }

                    case ENUM_MATRIX_TYPE_linear:
                        ((RealValuedExpressionArray*)this->value)->el[targetIndex]
                            = convertToRealExpressionTree(
                                             ((LinearMatrixValues*)sourceMtx->value)->el[sourceIndex]);  
                        break;

                    case ENUM_MATRIX_TYPE_objReference:
                        throw ErrorClass("OSnLNodeObjective not implemented yet");
                        break;

                    case ENUM_MATRIX_TYPE_conReference:
                        throw ErrorClass("OSnLNodeConstraint not implemented yet");
                        break;

                    case ENUM_MATRIX_TYPE_mixedRowReference:
                        throw ErrorClass("relevant OSnLNodes not implemented yet");
                        break;

                    case ENUM_MATRIX_TYPE_complexConstant:
                    case ENUM_MATRIX_TYPE_complexValuedExpressions:
                        throw ErrorClass("improper conversion of complex-valued elements");
                        break;

                    default:
                        throw ErrorClass ("undefined matrix element conversion");
                        break;
                }
                break;

                //Deal with any real scale factor
                if (scaleType == 1)
                {
                    OSnLNode* newRoot;
                    OSnLNode* newNum;
    
                    newRoot = new OSnLNodeTimes();
                    newNum  = new OSnLNodeNumber();
                    ((OSnLNodeNumber*)newNum)->value = scalarMult;
                    newRoot->m_mChildren[0] = newNum; 
                    newRoot->m_mChildren[1] 
                        = ((RealValuedExpressionArray*)this->value)->el[targetIndex]->m_treeRoot;
                    ((RealValuedExpressionArray*)this->value)->el[targetIndex]->m_treeRoot = newRoot;
                }
            }// end case realValuedExpressions

            case ENUM_MATRIX_TYPE_complexValuedExpressions:
            {
                temp = new ComplexValuedExpressionTree();

                switch (sourceMtx->valueType)
                {
                    case ENUM_MATRIX_TYPE_complexValuedExpressions:
                    {
                        temp->m_treeRoot 
                            = ((ComplexValuedExpressionArray*)
                                sourceMtx->value)->el[sourceIndex]->m_treeRoot->cloneExprNode();
                        break;
                    }

                    case ENUM_MATRIX_TYPE_constant:
                    {
                        temp->m_treeRoot = new OSnLCNodeNumber();
                        double tempVal = ((ConstantMatrixValues*)sourceMtx->value)->el[sourceIndex];
                        if (scaleType == 2)
                        {
                            ((OSnLCNodeNumber*) 
                                temp->m_treeRoot)->setValue(scalarMult*tempVal, scalarImag*tempVal);
                        }
                        else
                        {
                            ((OSnLCNodeNumber*) 
                                temp->m_treeRoot)->setValue(scalarMult*tempVal, 0.0);
                        }
                        break;
                    }

                    case ENUM_MATRIX_TYPE_complexConstant:
                    {
                        temp->m_treeRoot = new OSnLCNodeNumber();
                        std::complex<double> tempVal
                            = complexScalar*((ComplexMatrixValues*)sourceMtx->value)->el[sourceIndex];
                        ((OSnLCNodeNumber*)temp->m_treeRoot)->setValue(tempVal);
                        break;
                    }

                    case ENUM_MATRIX_TYPE_varReference:
                    {
                        temp->m_treeRoot = new OSnLCNodeCreate();
                        temp->m_treeRoot->m_mChildren[0] = new OSnLNodeVariable();
                        temp->m_treeRoot->m_mChildren[1] = new OSnLNodeNumber();
                        ((OSnLNodeVariable*)temp->m_treeRoot->m_mChildren[0])->idx
                            = ((VarReferenceMatrixValues*)sourceMtx->value)->el[sourceIndex];
                        ((OSnLNodeNumber*)temp->m_treeRoot->m_mChildren[1])->value  = 0.0;
                        break;
                    }

                    case ENUM_MATRIX_TYPE_realValuedExpressions:
                    {
                        temp->m_treeRoot = new OSnLCNodeCreate();
                        temp->m_treeRoot->m_mChildren[1] = new OSnLNodeNumber();
                        ((OSnLNodeNumber*)temp->m_treeRoot->m_mChildren[1])->value  = 0.0;
                        temp->m_treeRoot->m_mChildren[0] 
                            = ((RealValuedExpressionArray*)sourceMtx
                                ->value)->el[sourceIndex]->m_treeRoot->cloneExprNode();
                        break;
                    }

                    // the hardest conversion: linear expressions
                    case ENUM_MATRIX_TYPE_linear:
                    {
                        temp->m_treeRoot = new OSnLCNodeCreate();
                        temp->m_treeRoot->m_mChildren[1] = new OSnLNodeNumber();
                        ((OSnLNodeNumber*)temp->m_treeRoot->m_mChildren[1])->value = 0.0;

                        int nn = ((LinearMatrixValues*)
                                  sourceMtx->value)->el[sourceIndex]->numberOfVarIdx;
                        bool haveConstant;

                        if (nn == 0) 
                        {
                            temp->m_treeRoot->m_mChildren[0] = new OSnLNodeNumber();
                            ((OSnLNodeNumber*)temp->m_treeRoot->m_mChildren[0])->value
                                = ((LinearMatrixValues*)sourceMtx->value)->el[sourceIndex]->constant;
                        }
                        else
                        {
                            if (((LinearMatrixValues*)sourceMtx->value)->el[sourceIndex]->constant == 0)
                            {
                                haveConstant = false;
                                temp->m_treeRoot->m_mChildren[0] = new OSnLNodeSum();
                                temp->m_treeRoot->m_mChildren[0]->m_mChildren = new ExprNode*[nn];
                                temp->m_treeRoot->m_mChildren[0]->inumberOfChildren = nn; 
                            }
                            else
                            {
                                haveConstant = true;
                                temp->m_treeRoot->m_mChildren[0] = new OSnLNodeSum();
                                temp->m_treeRoot->m_mChildren[0]->m_mChildren = new ExprNode*[nn+1];
                                temp->m_treeRoot->m_mChildren[0]->inumberOfChildren = nn+1; 
                            }

                            for (int ii=0; ii<nn; ii++)
                            {
                                temp->m_treeRoot->m_mChildren[0]->m_mChildren[ii] = new OSnLNodeVariable();
                                ((OSnLNodeVariable*)
                                    temp->m_treeRoot->m_mChildren[0]->m_mChildren[ii])->idx 
                                        = ((LinearMatrixValues*)
                                            sourceMtx->value)->el[sourceIndex]->varIdx[ii]->idx;
                                ((OSnLNodeVariable*)
                                    temp->m_treeRoot->m_mChildren[0]->m_mChildren[ii])->coef
                                        = ((LinearMatrixValues*)
                                            sourceMtx->value)->el[sourceIndex]->varIdx[ii]->coef;
                            }

                            if (haveConstant)
                            {
                                temp->m_treeRoot->m_mChildren[0]->m_mChildren[nn] = new OSnLNodeNumber();
                                ((OSnLNodeNumber*)
                                    temp->m_treeRoot->m_mChildren[0]->m_mChildren[nn])->value
                                        = ((LinearMatrixValues*)
                                            sourceMtx->value)->el[sourceIndex]->constant;
                            }
                        }
                        ((ComplexValuedExpressionArray*)this->value)->el[targetIndex] = temp;
                        break;
                    }

                    case ENUM_MATRIX_TYPE_objReference:
                        delete temp; temp = NULL;
                        throw ErrorClass("OSnLNodeObjective not implemented yet");
                        break;

                    case ENUM_MATRIX_TYPE_conReference:
                        delete temp; temp = NULL;
                        throw ErrorClass("OSnLNodeConstraint not implemented yet");
                        break;

                    case ENUM_MATRIX_TYPE_mixedRowReference:
                        delete temp; temp = NULL;
                        throw ErrorClass("relevant OSnLNodes not implemented yet");
                        break;

                    default:
                        delete temp; temp = NULL;
                        throw ErrorClass("undefined matrix element conversion");
                        break;

                }// end of switch (sourceMtx->valueType)

                ((ComplexValuedExpressionArray*)this->value)->el[targetIndex] = temp;

                //Deal with any scale factor
                if (sourceMtx->valueType != ENUM_MATRIX_TYPE_constant   &&
                    sourceMtx->valueType != ENUM_MATRIX_TYPE_complexConstant)
                {
                    if (scalarMult < 1 || scalarMult > 1 ||
                        scalarImag < 0 || scalarImag > 0 )
                    {
                        OSnLCNode* newRoot;
                        OSnLCNode* newNum;
    
                        newRoot = new OSnLCNodeTimes();
                        newNum  = new OSnLCNodeNumber();
                        ((OSnLCNodeNumber*)newNum)->setValue(scalarMult, scalarImag);
                        newRoot->m_mChildren[0] = newNum; 
                        newRoot->m_mChildren[1] 
                            = ((ComplexValuedExpressionArray*)this->value)->el[targetIndex]->m_treeRoot;
                        ((ComplexValuedExpressionArray*)this->value)->el[targetIndex]->m_treeRoot = newRoot;
                    }
                }
                break;
            }// end case complexValuedExpressions

            case ENUM_MATRIX_TYPE_string:
            {
                ostringstream outStr;

                outStr.str("");
                outStr.clear();

                switch (sourceMtx->valueType)
                {
                    case ENUM_MATRIX_TYPE_constant:
                        outStr << os_dtoa_format(((ConstantMatrixValues*)
                                                        sourceMtx->value)->el[sourceIndex]);
                        break;

                    case ENUM_MATRIX_TYPE_complexConstant:
                        outStr << "(" << os_dtoa_format(((ComplexMatrixValues*)
                                                        sourceMtx->value)->el[sourceIndex].real());
                        outStr << "," << os_dtoa_format(((ComplexMatrixValues*)
                                                        sourceMtx->value)->el[sourceIndex].imag()) << ")";
                        break;

                    case ENUM_MATRIX_TYPE_varReference:
                        outStr << "x_" 
                               << ((VarReferenceMatrixValues*)sourceMtx->value)->el[sourceIndex];
                        break;

                    case ENUM_MATRIX_TYPE_objReference:
                        outStr << "o_" 
                               << ((ObjReferenceMatrixValues*)sourceMtx->value)->el[sourceIndex];
                        break;

                    case ENUM_MATRIX_TYPE_conReference:
                        outStr << "c_"
                               << ((ConReferenceMatrixValues*)
                                            sourceMtx->value)->el[sourceIndex]->conReference
                               << "." 
                               << returnConReferenceValueTypeString(
                                    ((ConReferenceMatrixValues*)
                                            sourceMtx->value)->el[sourceIndex]->valueType);
                        break;

                    case ENUM_MATRIX_TYPE_mixedRowReference:
                    {
                        int tempi = ((ConReferenceMatrixValues*)
                                            sourceMtx->value)->el[sourceIndex]->conReference;
                        if (tempi < 0)
                            outStr << "o_" 
                                   << tempi;
                            else
                            outStr << "c_"
                                   << tempi
                                   << "." 
                                   << returnConReferenceValueTypeString(
                                        ((ConReferenceMatrixValues*)
                                            sourceMtx->value)->el[sourceIndex]->valueType);
                        break;
                    }

                    case ENUM_MATRIX_TYPE_string:
                        outStr << ((StringValuedMatrixValues*)sourceMtx->value)->el[sourceIndex];
                        break;

                    case ENUM_MATRIX_TYPE_linear:
                    {
                        LinearMatrixElement*  
                            tempLin = ((LinearMatrixValues*)sourceMtx->value)->el[sourceIndex];

                        if (tempLin->constant < 0.0 || tempLin->constant > 0.0)
                            outStr <<   os_dtoa_format(tempLin->constant);

                        if (tempLin->numberOfVarIdx > 0)
                        {
                            if (tempLin->varIdx[0]->coef >= 0)
                            {
                                if (tempLin->constant < 0.0 || tempLin->constant > 0.0)
                                    outStr << " + ";
                                else
                                    outStr << " - ";
                            }
                            else
                                    outStr << "-";
                            if (tempLin->varIdx[0]->coef < 1  || tempLin->varIdx[0]->coef > 1 )
                                    outStr << os_dtoa_format(abs(tempLin->varIdx[0]->coef)) << "*";
                            outStr << "x_" << tempLin->varIdx[0]->idx;
                        }

                        for (int j=1; j<tempLin->numberOfVarIdx; j++)
                        {
                            if (tempLin->varIdx[j]->coef >= 0)
                                outStr << " + ";
                            else
                                outStr << " - ";
                            if (tempLin->varIdx[j]->coef < 1 || tempLin->varIdx[j]->coef > 1 )
                                outStr <<    os_dtoa_format(abs(tempLin->varIdx[j]->coef)) << "*";
                            outStr << "x_" << tempLin->varIdx[j]->idx;
                        }
                        break;
                    }

                    case ENUM_MATRIX_TYPE_realValuedExpressions:
                    {
                        std::vector<ExprNode*> postfixVec;
                        if ( ((RealValuedExpressionArray*)sourceMtx->value)->el[sourceIndex] != NULL)
                        {
                            postfixVec
                                = ((RealValuedExpressionArray*) sourceMtx->value)
                                        ->el[sourceIndex]->getPostfixFromExpressionTree();
                            outStr << getExpressionTreeAsInfixString(postfixVec);
                        }
                        else
                            outStr.str() = "";
                        break;
                    }

                    case ENUM_MATRIX_TYPE_complexValuedExpressions:
                    {
                        std::vector<ExprNode*> postfixVec;
                        if ( ((ComplexValuedExpressionArray*)sourceMtx->value)->el[sourceIndex] != NULL)
                        {
                            postfixVec
                                = ((ComplexValuedExpressionArray*) sourceMtx->value)
                                        ->el[sourceIndex]->getPostfixFromExpressionTree();
                            outStr << getExpressionTreeAsInfixString(postfixVec);
                        }
                        else
                            outStr.str() = "";
                        break;
                    }

                    default:
                        throw ErrorClass("undefined matrix element conversion");
                        break;

                }// end switch (sourceMtx->valueType) 

                if (scaleType != 0)
                    throw ErrorClass("Scalar multiple not defined for string-valued elements");

                ((StringValuedMatrixValues*)this->value)->el[targetIndex] = outStr.str();
                break;
            }

            case ENUM_MATRIX_TYPE_empty:
                throw ErrorClass("Matrix should be empty, but is not!!!");
                break;

            default :
                throw ErrorClass("Unsupported matrix type");
                break;
        }// end switch (inferredType)
        return true;
    }
    catch(const ErrorClass& eclass)
    {
//        if (temp != NULL)
//            delete temp;
//        temp = NULL;
        throw ErrorClass( eclass.errormsg);
    }
}//end of GeneralSparseMatrix::copyValue


GeneralSparseMatrix* GeneralSparseMatrix::convertToOtherMajor(ENUM_MATRIX_TYPE convertTo_, bool transpose_)
{
    ostringstream outStr;
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSMatrix, ENUM_OUTPUT_LEVEL_debug,
        "Inside GeneralSparseMatrix::convertToOtherMajor()");
    if (this->isRowMajor)
        outStr << "source matrix elements are in row major form" << std::endl;
    else
        outStr << "source matrix elements are in column major form" << std::endl;
    if (transpose_)
        outStr << "transpose the result" << std::endl;
    if (this->isRowMajor == transpose_)
        outStr << "result matrix is in row major form";
    else
        outStr << "result matrix is in column major form";
    if (convertTo_ != ENUM_MATRIX_TYPE_unknown)
        outStr << " - convert to " << returnMatrixTypeString(convertTo_);
    outStr << std::endl;
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSMatrix, ENUM_OUTPUT_LEVEL_trace, outStr.str());
#endif

    GeneralSparseMatrix* tempMtx = NULL;

    try
    {
        if (this->start == NULL || this->startSize <= 1 ) return NULL;
    
        ENUM_MATRIX_TYPE convertTo = convertTo_;
        ENUM_MATRIX_TYPE inferredType = this->valueType;
        if (convertTo == ENUM_MATRIX_TYPE_unknown) 
            convertTo  = inferredType;
        if (convertTo != mergeMatrixType(convertTo, inferredType))
           throw ErrorClass("Requested improper conversion of element values");
        inferredType = convertTo;

        tempMtx = new GeneralSparseMatrix();

        tempMtx->valueType       = convertTo;
        tempMtx->symmetry        = symmetry;
//        tempMtx->isRowMajor      = (this->isRowMajor == transpose_);
//        tempMtx->numberOfRows    = ;
//        tempMtx->numberOfColumns = numberOfColumns;

        if (transpose_)
        {
            tempMtx->isRowMajor      = this->isRowMajor;
            tempMtx->numberOfRows    = numberOfColumns;
            tempMtx->numberOfColumns = numberOfRows;
        }
        else
        {
            tempMtx->isRowMajor      = !(this->isRowMajor);
            tempMtx->numberOfRows    = numberOfRows;
            tempMtx->numberOfColumns = numberOfColumns;
        }

        tempMtx->startSize = (this->isRowMajor) ? numberOfColumns+1 : numberOfRows+1;
        tempMtx->valueSize =  this->valueSize;

        tempMtx->start = new int[tempMtx->startSize]; 
        tempMtx->index = new int[tempMtx->valueSize];

        if (!tempMtx->allocateValueArray(tempMtx->valueSize))
            throw ErrorClass("Error allocating value array in GeneralSparseMatrix::convertType()");

        int i,j, iTemp;
        int iNumSource = this->startSize - 1;

        int* miStart = tempMtx->start;
        int* miIndex = tempMtx->index;
    
        for ( i = 1; i < tempMtx->startSize; i++)
        {
            miStart [ i ] = 0;
        }
        // for illustration assume we are converting from column to row major
        // i is indexing columns and j is indexing row numbers
        for (i = 0; i < iNumSource; i++)
        {
            for (j = this->start[i]; j < this->start[ i + 1 ]; j++)
            {
                // index[ j] is a row index, we have just found an occurrence of row index[j]
                // therefore we increase by 1 (or push back) the start of the row indexed by index[j] + 1,
                // i.e. the start of the next row
                miStart[this->index[j] + 1] ++;
            }
        }
        // at this point, miStart[ i] holds the number of columns with a nonzero in row i - 1
        // if we knew the correct starting point of row i -1, the correct starting point
        // for row i is miStart[i] + miStart [i - 1]
        miStart[0] = 0;
        for (i = 1; i < tempMtx->startSize; i++ )
        {
            miStart[i] += miStart [i - 1] ;
        }

        // now get the correct values
        // again assume we are converting column major to row major
        // loop over columns and maintain miStart as the _insertion point_ of the current nonzero
        // (that is, miStart points at the *current end* of each row)
        for (i = 0; i < iNumSource; i++)
        {
            // get row indices and values of the matrix
            for (j = this->start[i]; j < this->start[ i + 1 ]; j++)
            {
                iTemp = miStart[this->index[j]];
                miIndex [ iTemp] = i;
                if (!tempMtx->copyValue(this, j, iTemp))
                    throw ErrorClass("Error copying a value in GeneralSparseMatrix::convertType()");
                miStart[this->index[j]] ++;
            }
        }

        // miStart[ i] is now equal to miStart[ i + 1], so readjust
        for (i = tempMtx->startSize - 1; i >= 1; i-- )
        {
            miStart[i] = miStart [i - 1] ;
        }

        miStart[0] = 0;
        return tempMtx;
    }
    catch(const ErrorClass& eclass)
    {
        if (tempMtx != NULL)
            delete tempMtx;
        tempMtx = NULL;
        throw ErrorClass( eclass.errormsg);
    }
}//end of GeneralSparseMatrix::convertToOtherMajor

GeneralSparseMatrix* GeneralSparseMatrix::convertType(ENUM_MATRIX_TYPE convertTo_)
{
    ostringstream outStr;
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSMatrix, ENUM_OUTPUT_LEVEL_debug,
        "Inside GeneralSparseMatrix::convertType()");
    if (convertTo_ != ENUM_MATRIX_TYPE_unknown)
        outStr << "convert GeneralSparseMatrix to " << returnMatrixTypeString(convertTo_);
    outStr << std::endl << std::endl;
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSMatrix, ENUM_OUTPUT_LEVEL_trace, outStr.str());
#endif

    try
    {
        if (this->start == NULL || this->startSize <= 1 ) return NULL;

        GeneralSparseMatrix* tempMtx = new GeneralSparseMatrix();
    
        ENUM_MATRIX_TYPE convertTo = convertTo_;
        ENUM_MATRIX_TYPE inferredType = this->valueType;
        if (convertTo == ENUM_MATRIX_TYPE_unknown) 
            convertTo  = inferredType;
        if (convertTo != mergeMatrixType(convertTo, inferredType))
           throw ErrorClass("Requested improper conversion of element values");
        inferredType = convertTo;

        tempMtx->valueType  = convertTo;
        tempMtx->symmetry   = this->symmetry;
        tempMtx->isRowMajor = this->isRowMajor;

        tempMtx->numberOfRows     = numberOfRows;
        tempMtx->numberOfColumns  = numberOfColumns;

        tempMtx->startSize  = this->startSize;
        tempMtx->valueSize  = this->valueSize;

        tempMtx->start = new int[tempMtx->startSize]; 
        tempMtx->index = new int[tempMtx->valueSize];

        for (int i=0; i < tempMtx->startSize; i++)
            tempMtx->start[i] = this->start[i];

        for (int i=0; i < tempMtx->valueSize; i++)
            tempMtx->index[i] = this->index[i];

        if (!tempMtx->allocateValueArray(tempMtx->valueSize))
            throw ErrorClass("Error allocating value array in GeneralSparseMatrix::convertType()");

        for (int i=0; i < tempMtx->valueSize; i++)
            if (!tempMtx->copyValue(this, i, i))
                throw ErrorClass("Error copying a value in GeneralSparseMatrix::convertType()");

       return tempMtx;
    }
    catch(const ErrorClass& eclass)
    {
        throw ErrorClass( eclass.errormsg);
    }
}//end of GeneralSparseMatrix::convertType


GeneralSparseMatrix* GeneralSparseMatrix::convertSymmetry(ENUM_MATRIX_SYMMETRY symmetry_)
{
    ostringstream outStr;
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSMatrix, ENUM_OUTPUT_LEVEL_debug,
        "Inside GeneralSparseMatrix::convertSymmetry()");
    outStr << "change from  symmetry type " << returnMatrixSymmetryString(this->symmetry)
           << "and store as symmetry type " << returnMatrixSymmetryString(symmetry_);
    outStr << std::endl << std::endl;
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSMatrix, ENUM_OUTPUT_LEVEL_trace, outStr.str());
#endif

    try
    {
        if (this->start == NULL || this->startSize <= 1 ) return NULL;

        ENUM_MATRIX_SYMMETRY symmetry = symmetry_;

        if (symmetry == ENUM_MATRIX_SYMMETRY_default)
            symmetry  = ENUM_MATRIX_SYMMETRY_none;
    
        //Check that symmetry conversion is compatible
        if (this->symmetry != ENUM_MATRIX_SYMMETRY_none &&
                  symmetry != ENUM_MATRIX_SYMMETRY_none)
        {
            if       (symmetry == ENUM_MATRIX_SYMMETRY_upper          &&
                this->symmetry != ENUM_MATRIX_SYMMETRY_lower             )
                    throw ErrorClass("Illegal symmetry conversion requested");               
            else  if (symmetry == ENUM_MATRIX_SYMMETRY_lower          &&
                this->symmetry != ENUM_MATRIX_SYMMETRY_upper             )
                    throw ErrorClass("Illegal symmetry conversion requested");               
            else  if (symmetry == ENUM_MATRIX_SYMMETRY_skewUpper      &&
                this->symmetry != ENUM_MATRIX_SYMMETRY_skewLower         )
                    throw ErrorClass("Illegal symmetry conversion requested");               
            else  if (symmetry == ENUM_MATRIX_SYMMETRY_skewLower      &&
                this->symmetry != ENUM_MATRIX_SYMMETRY_skewUpper         )
                    throw ErrorClass("Illegal symmetry conversion requested");               
            else  if (symmetry == ENUM_MATRIX_SYMMETRY_HermitianUpper &&
                this->symmetry != ENUM_MATRIX_SYMMETRY_HermitianLower    )
                    throw ErrorClass("Illegal symmetry conversion requested");               
            else  if (symmetry == ENUM_MATRIX_SYMMETRY_HermitianLower &&
                this->symmetry != ENUM_MATRIX_SYMMETRY_HermitianUpper    )
                    throw ErrorClass("Illegal symmetry conversion requested");               
            else
                    throw ErrorClass("Unknown symmetry conversion requested");               
        }

        GeneralSparseMatrix* tempMtx = new GeneralSparseMatrix();

        tempMtx->valueType       = valueType;
        tempMtx->symmetry        = symmetry_;
        tempMtx->isRowMajor      = this->isRowMajor;
        tempMtx->numberOfRows    = numberOfRows;
        tempMtx->numberOfColumns = numberOfColumns;
        tempMtx->startSize       = this->startSize;
        tempMtx->start           = new int[tempMtx->startSize]; 

        if (this->symmetry == ENUM_MATRIX_SYMMETRY_none)
        {
        //here we impose symmetry by eliminating elements below or above the diagonal
        //depending on the value of symmetry_

            if (symmetry_ == ENUM_MATRIX_SYMMETRY_upper         || 
                symmetry_ == ENUM_MATRIX_SYMMETRY_skewUpper     || 
                symmetry_ == ENUM_MATRIX_SYMMETRY_HermitianUpper )
            {
                int i, j, tmpVal = 0;
                for (i = 0; i<this->startSize-1; i++)
                    for (j=start[i]; j<start[i+1]; j++)
                        if (index[j] >= i) 
                            tmpVal++;

                tempMtx->valueSize = tmpVal;
                tempMtx->index     = new int[tmpVal];
    
                if (!tempMtx->allocateValueArray(tmpVal))
                    throw ErrorClass(
                        "Error allocating value array in GeneralSparseMatrix::convertSymmetry()");

                tmpVal = 0;
                tempMtx->start[0] = 0;
                for (i = 0; i<this->startSize-1; i++)
                {
                    for (j=start[i]; j<start[i+1]; j++)
                        if (index[j] >= i)
                        {
                            tempMtx->index[tmpVal] = this->index[j];
                            if (!tempMtx->copyValue(this, j, tmpVal)) 
                                throw ErrorClass(
                                    "Error copying a value in GeneralSparseMatrix::convertSymmetry()");
                            tmpVal++;
                        }
                    tempMtx->start[i+1] = tmpVal;
                }
            }
            else if (symmetry_ == ENUM_MATRIX_SYMMETRY_upper         || 
                     symmetry_ == ENUM_MATRIX_SYMMETRY_skewUpper     || 
                     symmetry_ == ENUM_MATRIX_SYMMETRY_HermitianUpper )
            {
                int i, j, tmpVal = 0;
                for (i = 0; i<this->startSize-1; i++)
                    for (j=start[i]; j<start[i+1]; j++)
                        if (index[j] <= i) 
                            tmpVal++;

                tempMtx->valueSize = tmpVal;
                tempMtx->index     = new int[tmpVal];
    
                if (!tempMtx->allocateValueArray(tmpVal))
                    throw ErrorClass(
                        "Error allocating value array in GeneralSparseMatrix::convertSymmetry()");

                tmpVal = 0;
                tempMtx->start[0] = 0;
                for (i = 0; i<this->startSize-1; i++)
                {
                    for (j=start[i]; j<start[i+1]; j++)
                        if (index[j] <= i)
                        {
                            tempMtx->index[tmpVal] = this->index[j];
                            if (!tempMtx->copyValue(this, j, tmpVal)) 
                                throw ErrorClass(
                                    "Error copying a value in GeneralSparseMatrix::convertSymmetry()");
                            tmpVal++;
                        }
                    tempMtx->start[i+1] = tmpVal;
                }
            }
            else
                throw ErrorClass("Unknown or illegal symmetry conversion requested");
        }// end of if (this->symmetry == none)
        else if (symmetry == ENUM_MATRIX_SYMMETRY_none)
        {
        }
        else
        {
            if (this->symmetry == ENUM_MATRIX_SYMMETRY_upper        || 
                this->symmetry == ENUM_MATRIX_SYMMETRY_skewUpper    || 
                this->symmetry == ENUM_MATRIX_SYMMETRY_HermitianUpper )
            {
            } 
            else if (this->symmetry == ENUM_MATRIX_SYMMETRY_lower        || 
                     this->symmetry == ENUM_MATRIX_SYMMETRY_skewLower    || 
                     this->symmetry == ENUM_MATRIX_SYMMETRY_HermitianLower )
            {
            } 
        }
        return tempMtx;
    }
    catch(const ErrorClass& eclass)
    {
        throw ErrorClass( eclass.errormsg);
    }
}//end of GeneralSparseMatrix::convertSymmetry

/** ---------- Methods for class ExpandedMatrixBlocks ---------- */
ExpandedMatrixBlocks::ExpandedMatrixBlocks():
    valueType(ENUM_MATRIX_TYPE_unknown),
    isRowMajor(false),
    symmetry(ENUM_MATRIX_SYMMETRY_none),
    rowOffset(NULL),
    colOffset(NULL),
    rowOffsetSize(0),
    colOffsetSize(0),
    blockNumber(0),
    blockRows(NULL),
    blockColumns(NULL),
    blocks(NULL),
    bDeleteArrays(true)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSMatrix, ENUM_OUTPUT_LEVEL_trace,
        "Inside the ExpandedMatrixBlocks default constructor");
    std::ostringstream outStr;
    outStr << "Allocate ExpandedMatrixBlocks at address" << this;
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSMatrix, ENUM_OUTPUT_LEVEL_detailed_trace, outStr.str());
#endif
}// end of ExpandedMatrixBlocks


ExpandedMatrixBlocks::~ExpandedMatrixBlocks()
{
    std::ostringstream outStr;
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSMatrix, ENUM_OUTPUT_LEVEL_trace,
        "Inside the ExpandedMatrixBlocks Destructor");
    outStr << "deleting ExpandedMatrixBlocks at address" << this << std::endl;
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSMatrix, ENUM_OUTPUT_LEVEL_detailed_trace, outStr.str());
#endif
    if (bDeleteArrays)
    {
        if (blockRows != NULL)
        {
#ifndef NDEBUG
            outStr.str("");
            outStr.clear();
            outStr << "deleting ExpandedMatrixBlocks->blockRows at " << &blockRows << std::endl;
            osoutput->OSPrint(ENUM_OUTPUT_AREA_OSMatrix, 
               ENUM_OUTPUT_LEVEL_detailed_trace, outStr.str());
#endif
            delete [] blockRows;
            blockRows = NULL;
        }
        if (blockColumns != NULL)
        {
#ifndef NDEBUG
            outStr.str("");
            outStr.clear();
            outStr << "deleting ExpandedMatrixBlocks->blockColumns at " << &blockColumns << std::endl;
            osoutput->OSPrint(ENUM_OUTPUT_AREA_OSMatrix, 
               ENUM_OUTPUT_LEVEL_detailed_trace, outStr.str());
#endif
            delete [] blockColumns;
            blockColumns = NULL;
        }
        if (blockNumber > 0 && blocks != NULL)
        {
            for (int i=0; i < blockNumber; i++)
            {
                if (blocks[i] != NULL)
                {
#ifndef NDEBUG
                    outStr.str("");
                    outStr.clear();
                    outStr << "deleting ExpandedMatrixBlocks->blocks[" << i << "] at " 
                           << &blocks[i] << std::endl;
                    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSMatrix, 
                        ENUM_OUTPUT_LEVEL_detailed_trace, outStr.str());
#endif          
                    delete blocks[i];
                    blocks[i] = NULL;
                }
            }
        }
        if (blocks != NULL) delete [] blocks;
        blocks = NULL;
    }
}// end of ~ExpandedMatrixBlocks

GeneralSparseMatrix* ExpandedMatrixBlocks::getBlock(int rowIdx, int colIdx)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSMatrix, ENUM_OUTPUT_LEVEL_trace, 
        "Inside ExpandedMatrixBlocks::getBlock()");
#endif
    for (int i=0; i < blockNumber; i++)
        if (blockRows[i] == rowIdx && blockColumns[i] == colIdx)
            return blocks[i];

    return NULL;
}// end of ExpandedMatrixBlocks::getBlock

bool ExpandedMatrixBlocks::isBlockDiagonal()
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSMatrix, ENUM_OUTPUT_LEVEL_trace, 
        "Inside ExpandedMatrixBlocks::isBlockDiagonal()");
#endif
    if (blockNumber >= rowOffsetSize || blockNumber >= colOffsetSize || rowOffsetSize != colOffsetSize)
        return false;

    for (int i=0; i < blockNumber; i++)
        if (blockRows[i] != blockColumns[i])
            return false;

    return true;
}// end of ExpandedMatrixBlocks::isBlockDiagonal



//-------------------------------------
/**
 *  Some methods to convert one type of matrix element into another
 */
LinearMatrixElement* convertToLinearMatrixElement(double val)
{
    try
    {
        LinearMatrixElement* tmp = new LinearMatrixElement();
        tmp->constant = val;
        tmp->numberOfVarIdx = 0;
        tmp->varIdx = NULL;
        return tmp;
    }
    catch(const ErrorClass& eclass)
    {
        throw ErrorClass( eclass.errormsg);
    }
}// end of convertToLinearMatrixElement(double val)

LinearMatrixElement* convertToLinearMatrixElement(int varref)
{
    try
    {
        LinearMatrixElement* tmp = new LinearMatrixElement();
        tmp->constant = 0.0;
        tmp->numberOfVarIdx = 1;
        tmp->varIdx    = new LinearMatrixElementTerm*[1];
        tmp->varIdx[0] = new LinearMatrixElementTerm();
        tmp->varIdx[0]->coef = 1.0;
        tmp->varIdx[0]->idx  = varref;
        return tmp;
    }
    catch(const ErrorClass& eclass)
    {
        throw ErrorClass( eclass.errormsg);
    }
}//end of convertToLinearMatrixElement(int varref)


RealValuedExpressionTree* convertToRealExpressionTree(double val)
{
    try
    {
        std::vector<ExprNode*> nlNodeVec;
        RealValuedExpressionTree* tmp = new RealValuedExpressionTree();

        OSnLNodeNumber* tmpNum = new OSnLNodeNumber();
        tmpNum->value = val;
        nlNodeVec.push_back(tmpNum);

        tmp->m_treeRoot =
            /*((OSnLNode*)*/nlNodeVec[ 0]/*)*/->createExpressionTreeFromPostfix(nlNodeVec);
        nlNodeVec.clear();
        return tmp;
    }
    catch(const ErrorClass& eclass)
    {
        throw ErrorClass( eclass.errormsg);
    }
}//end of convertToRealExpressionTree(double val)

RealValuedExpressionTree* convertToRealExpressionTree(int refIdx, bool varRef) // varref or objref
{
    try
    {
        std::vector<ExprNode*> nlNodeVec;
        RealValuedExpressionTree* tmp = new RealValuedExpressionTree();

        OSnLNode* tmpRef;

        if (varRef)
        {
            tmpRef = new OSnLNodeVariable();
            ((OSnLNodeVariable*)tmpRef)->idx = refIdx;
        }
        else
            throw ErrorClass("OSnLNodeObjective not yet implemented");
        nlNodeVec.push_back(tmpRef);

        tmp->m_treeRoot =
            ((OSnLNode*)nlNodeVec[ 0])->createExpressionTreeFromPostfix(nlNodeVec);
        nlNodeVec.clear();
        return tmp;
    }
    catch(const ErrorClass& eclass)
    {
        throw ErrorClass( eclass.errormsg);
    }
}//end of convertToRealExpressionTree(int refIdx, bool varRef)

RealValuedExpressionTree* convertToRealExpressionTree(LinearMatrixElement* linearExpr)
{
    try
    {
        std::vector<ExprNode*> nlNodeVec;
        RealValuedExpressionTree* tmp = new RealValuedExpressionTree();

        //push this back as a sum node : [c_1*] x_1 + [c_2*] x_2 + ... (+ c_0)
        OSnLNodeSum*      tmpSum = new OSnLNodeSum();
        OSnLNodeNumber*   tmpNum;
        OSnLNodeVariable* tmpVar;
        OSnLNodeTimes*    tmpTimes;

        for (int i=0; i < linearExpr->numberOfVarIdx; i++)
        {
            tmpVar = new OSnLNodeVariable();
            tmpVar->idx = linearExpr->varIdx[i]->idx;
            nlNodeVec.push_back(tmpVar);
            if (linearExpr->varIdx[i]->coef != 1.0)
            {
                tmpNum = new OSnLNodeNumber();
                tmpNum->value = linearExpr->varIdx[i]->coef;
                nlNodeVec.push_back(tmpNum);

                tmpTimes = new OSnLNodeTimes();
                nlNodeVec.push_back(tmpTimes);
            }
        }
        tmpSum->inumberOfChildren = linearExpr->numberOfVarIdx;

        if (linearExpr->constant != 0.0)
        {
            tmpNum = new OSnLNodeNumber();
            tmpNum->value = linearExpr->constant;
            nlNodeVec.push_back(tmpNum);
            tmpSum->inumberOfChildren++;
        }

        if (tmpSum->inumberOfChildren > 0)
            tmpSum->m_mChildren = new ExprNode*[tmpSum->inumberOfChildren];

        nlNodeVec.push_back(tmpSum);

        tmp->m_treeRoot =
            ((OSnLNode*)nlNodeVec[ 0])->createExpressionTreeFromPostfix(nlNodeVec);
        nlNodeVec.clear();
        return tmp;
    }
    catch(const ErrorClass& eclass)
    {
        throw ErrorClass( eclass.errormsg);
    }
}//end of convertToRealExpressionTree(LinearMatrixElement* linearExpr)

RealValuedExpressionTree* convertToRealExpressionTree(ConReferenceMatrixElement* val)
{
    try
    {
        throw ErrorClass("In convertToRealExpressionTree: OSnLNodeConstraint not yet implemented");
        return NULL;
    }
    catch(const ErrorClass& eclass)
    {
        throw ErrorClass( eclass.errormsg);
    }
}//end of convertToRealExpressionTree(ConReferenceMatrixElement* val)

ConReferenceMatrixElement* convertToConReferenceMatrixElement(int objref)
{
    try
    {
        throw ErrorClass("In convertToConReferenceMatrixElement: OSnLNodeConstraint not yet implemented");
        return NULL;
    }
    catch(const ErrorClass& eclass)
    {
        throw ErrorClass( eclass.errormsg);
    }
}//end of convertToConReferenceMatrixElement(int objref)

std::complex<double> convertToComplexMatrixElement(double val)
{
    std::complex<double> tmp = val;
    return tmp;
}//end of convertToComplexMatrixElement(double val)

ComplexValuedExpressionTree* convertToComplexExpressionTree(double val)
{
    try
    {
        ComplexValuedExpressionTree* tmp = new ComplexValuedExpressionTree();

        tmp->m_treeRoot = new OSnLCNodeNumber();
        ((OSnLCNodeNumber*)tmp->m_treeRoot)->setValue(val, 0.0);
        return tmp;
    }
    catch(const ErrorClass& eclass)
    {
        throw ErrorClass( eclass.errormsg);
    }
}//end of convertToComplexExpressionTree(double val)

ComplexValuedExpressionTree* convertToComplexExpressionTree(int idx, bool varref) // for varref and objref
{
    try
    {
        ComplexValuedExpressionTree* tmp = new ComplexValuedExpressionTree();

        if (varref)
        {
            tmp->m_treeRoot = new OSnLCNodeCreate();
            tmp->m_treeRoot->m_mChildren[0] = new OSnLNodeVariable();
            tmp->m_treeRoot->m_mChildren[1] = new OSnLNodeNumber();
            ((OSnLNodeVariable*)tmp->m_treeRoot->m_mChildren[0])->idx   = idx;
            ((OSnLNodeNumber*)  tmp->m_treeRoot->m_mChildren[1])->value = 0.0;
        }
        else
            throw ErrorClass("OSnLNodeObjective not yet implemented");
        return tmp;
    }
    catch(const ErrorClass& eclass)
    {
        throw ErrorClass( eclass.errormsg);
    }
}//end of convertToComplexExpressionTree(int varref)

ComplexValuedExpressionTree* convertToComplexExpressionTree(LinearMatrixElement* val)
{
    try
    {
        std::vector<ExprNode*> nlNodeVec;
        ComplexValuedExpressionTree* tmp = new ComplexValuedExpressionTree();

        //push this back as a sum node : [c_1*] x_1 + [c_2*] x_2 + ... (+ c_0)
        OSnLNodeSum*      tmpSum = new OSnLNodeSum();
        OSnLNodeNumber*   tmpNum;
        OSnLNodeVariable* tmpVar;
        OSnLNodeTimes*    tmpTimes;
        OSnLCNodeCreate*  tmpCreate;

        for (int i=0; i < val->numberOfVarIdx; i++)
        {
            tmpVar = new OSnLNodeVariable();
            tmpVar->idx = val->varIdx[i]->idx;
            nlNodeVec.push_back(tmpVar);
            if (val->varIdx[i]->coef != 1.0)
            {
                tmpNum = new OSnLNodeNumber();
                tmpNum->value = val->varIdx[i]->coef;
                nlNodeVec.push_back(tmpNum);

                tmpTimes = new OSnLNodeTimes();
                nlNodeVec.push_back(tmpTimes);
            }
        }
        tmpSum->inumberOfChildren = val->numberOfVarIdx;

        if (val->constant != 0.0)
        {
            tmpNum = new OSnLNodeNumber();
            tmpNum->value = val->constant;
            nlNodeVec.push_back(tmpNum);
            tmpSum->inumberOfChildren++;
        }

        if (tmpSum->inumberOfChildren > 0)
            tmpSum->m_mChildren = new ExprNode*[tmpSum->inumberOfChildren];

        nlNodeVec.push_back(tmpSum);

        tmpNum = new OSnLNodeNumber();
        tmpNum->value = 0.0;
        nlNodeVec.push_back(tmpNum);

        tmpCreate = new OSnLCNodeCreate();
        nlNodeVec.push_back(tmpCreate);

        tmp->m_treeRoot =
            ((OSnLNode*)nlNodeVec[ 0])->createExpressionTreeFromPostfix(nlNodeVec);
        nlNodeVec.clear();
        return tmp;
    }
    catch(const ErrorClass& eclass)
    {
        throw ErrorClass( eclass.errormsg);
    }
}//end of convertToComplexExpressionTree(LinearMatrixElement* val)

ComplexValuedExpressionTree* convertToComplexExpressionTree(ConReferenceMatrixElement* val)
{
    try
    {
        throw ErrorClass("In convertToRealExpressionTree: OSnLNodeConstraint not yet implemented");
        return NULL;
    }
    catch(const ErrorClass& eclass)
    {
        throw ErrorClass( eclass.errormsg);
    }
}//end of convertToComplexExpressionTree(ConReferenceMatrixElement* val)

ComplexValuedExpressionTree* convertToComplexExpressionTree(std::complex<double> val)
{
    try
    {
        ComplexValuedExpressionTree* tmp = new ComplexValuedExpressionTree();

        tmp->m_treeRoot = new OSnLCNodeNumber();
        ((OSnLCNodeNumber*)tmp->m_treeRoot)->setValue(val);
        return tmp;

        return tmp;
    }
    catch(const ErrorClass& eclass)
    {
        throw ErrorClass( eclass.errormsg);
    }
}//end of convertToComplexExpressionTree(std::complex<double> val)

ComplexValuedExpressionTree* convertToComplexExpressionTree(RealValuedExpressionTree* val)
{
    try
    {
        std::vector<ExprNode*> nlNodeVec;
        ComplexValuedExpressionTree* tmp = new ComplexValuedExpressionTree();

        nlNodeVec = val->getPostfixFromExpressionTree();

        OSnLCNodeCreate* tmpCreate = new OSnLCNodeCreate();
        nlNodeVec.push_back(tmpCreate);

        tmp->m_treeRoot =
            ((OSnLNode*)nlNodeVec[ 0])->createExpressionTreeFromPostfix(nlNodeVec);
        nlNodeVec.clear();
        return tmp;
    }
    catch(const ErrorClass& eclass)
    {
        throw ErrorClass( eclass.errormsg);
    }
}//end of convertToComplexExpressionTree(RealValuedExpressionTree* val)

std::string convertToString(double val)
{
    ostringstream outStr; 
    outStr << os_dtoa_format(val);
    return outStr.str();
}//end of convertToString(double val)

std::string convertToString(int idx, bool varref) // used for varref and objref
{
    ostringstream outStr;
    if (varref)
        outStr << "x_" << idx;
    else
        outStr << "o_" << idx;
    return outStr.str();
}//end of convertToString(int varref)

std::string convertToString(LinearMatrixElement* val)
{
    ostringstream outStr;

    if (val->constant < 0.0 || val->constant > 0.0)
        outStr << os_dtoa_format(val->constant);
    
    if (val->numberOfVarIdx > 0)
    {
        if (val->varIdx[0]->coef >= 0)
        {
            if (val->constant < 0.0 || val->constant > 0.0)
                outStr << " + ";
        }
        else
        {
            if (val->constant < 0.0 || val->constant > 0.0)
                outStr << " - ";
            else
                outStr << " -";
        }
        if (val->varIdx[0]->coef < 1 ||  val->varIdx[0]->coef > 1 )
            outStr << os_dtoa_format(abs(val->varIdx[0]->coef)) << "*";
         outStr << "x_" << val->varIdx[0]->idx;
    }

    for (int j=1; j<val->numberOfVarIdx; j++)
    {
        if (val->varIdx[j]->coef >= 0)
            outStr << " + ";
        else
            outStr << " - ";
        if (val->varIdx[j]->coef < 1 ||  val->varIdx[j]->coef > 1 )
            outStr << os_dtoa_format(abs(val->varIdx[j]->coef)) << "*";
        outStr << "x_" << val->varIdx[j]->idx;
    }
    return outStr.str();
}//end of convertToString(LinearMatrixElement* val)

std::string convertToString(ConReferenceMatrixElement* val)
{
    ostringstream outStr; 
    outStr << "c_" << val->conReference
           <<  "." << returnConReferenceValueTypeString(val->valueType);
    return outStr.str();
}//end of convertToString(ConReferenceMatrixElement* val)

std::string convertToString(std::complex<double> val)
{
    ostringstream outStr;
    outStr << "(" << os_dtoa_format(val.real());
    outStr << "," << os_dtoa_format(val.imag()) << ")";
    return outStr.str();
}//end of convertToString(std::complex<double> val)

std::string convertToString(RealValuedExpressionTree* val)
{
    ostringstream outStr;
    std::vector<ExprNode*> postfixVec;
    if (val != NULL)
    {
        postfixVec = val->getPostfixFromExpressionTree();
        outStr << getExpressionTreeAsInfixString(postfixVec);
    }
    else
        outStr.str() = "";
    return outStr.str();
}//end of convertToString(RealValuedExpressionTree* val)

std::string convertToString(ComplexValuedExpressionTree* val)
{
    ostringstream outStr; 
    std::vector<ExprNode*> postfixVec;
    if (val != NULL)
    {
        postfixVec = val->getPostfixFromExpressionTree();
        outStr << getExpressionTreeAsInfixString(postfixVec);
    }
    else
        outStr.str() = "";
    return outStr.str();
}//end of convertToString(ComplexValuedExpressionTree* val)

