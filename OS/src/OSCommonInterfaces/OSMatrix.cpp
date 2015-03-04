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
    numberOfRows(0),
    numberOfColumns(0),
    symmetry(ENUM_MATRIX_SYMMETRY_none),
    type(ENUM_MATRIX_TYPE_unknown)
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
        if (m_mChildren[0]->nType == ENUM_MATRIX_CONSTRUCTOR_TYPE_constantElements) return true;
        if (m_mChildren[0]->nType == ENUM_MATRIX_CONSTRUCTOR_TYPE_varRefElements  ) return true;
        if (m_mChildren[0]->nType == ENUM_MATRIX_CONSTRUCTOR_TYPE_linearElements  ) return true;
        if (m_mChildren[0]->nType == ENUM_MATRIX_CONSTRUCTOR_TYPE_generalElements ) return true;
        if (m_mChildren[0]->nType == ENUM_MATRIX_CONSTRUCTOR_TYPE_objRefElements  ) return true;
        if (m_mChildren[0]->nType == ENUM_MATRIX_CONSTRUCTOR_TYPE_conRefElements  ) return true;
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
        if (m_mChildren[0]->nType == ENUM_MATRIX_CONSTRUCTOR_TYPE_constantElements) k++;
        if (m_mChildren[0]->nType == ENUM_MATRIX_CONSTRUCTOR_TYPE_varRefElements)   k++;
        if (m_mChildren[0]->nType == ENUM_MATRIX_CONSTRUCTOR_TYPE_linearElements)   k++;
        if (m_mChildren[0]->nType == ENUM_MATRIX_CONSTRUCTOR_TYPE_generalElements)  k++;
        if (m_mChildren[0]->nType == ENUM_MATRIX_CONSTRUCTOR_TYPE_objRefElements)   k++;
        if (m_mChildren[0]->nType == ENUM_MATRIX_CONSTRUCTOR_TYPE_conRefElements)   k++;
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

GeneralSparseMatrix* MatrixType::extractBlock(int firstrow, int firstcol, int nrows, int ncols,
                                              bool rowMajor, ENUM_MATRIX_SYMMETRY symmetry)
{
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
// end of methods for MatrixElementValues


/** ---------- Methods for class OSMatrix ---------- */ 
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
        matrixType == ENUM_MATRIX_TYPE_zero;
        for (int i=0; i<inumberOfChildren; i++)
            matrixType = mergeMatrixType(matrixType, m_mChildren[i]->getMatrixType());
    }
    return matrixType;
}// end of OSMatrix::getMatrixType()


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
    outStr << ">" << std::endl;

    for (int i=0; i < inumberOfChildren; i++)
        outStr << m_mChildren[i]->getMatrixNodeInXML();

    outStr << "</matrix>" << std::endl;
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
        matrixType == ENUM_MATRIX_TYPE_zero;
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
        ENUM_MATRIX_TYPE temp;
        matrixType == ENUM_MATRIX_TYPE_zero;
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
    outStr << ">" << std::endl;

    for (int i=0; i < inumberOfChildren; i++)
        outStr << m_mChildren[i]->getMatrixNodeInXML();

    outStr << "</block>" << std::endl;
    return outStr.str();
}// end of MatrixBlock::getMatrixNodeInXML()

bool MatrixBlock::alignsOnBlockBoundary(int firstRow, int firstColumn, int nRows, int nCols)
{
    return (firstRow == 0 && firstColumn == 0 && nRows == numberOfRows && nCols == numberOfColumns);
}// end of MatrixBlock::alignsOnBlockBoundary()

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
    bDeleteArrays(true),
    isColumnMajor(true),
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

GeneralSparseMatrix::GeneralSparseMatrix(bool isColumnMajor_, int startSize, int valueSize,
                                         ENUM_MATRIX_TYPE type)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, "Inside the alternate GeneralSparseMatrix Constructor");
#endif
}// end of GeneralSparseMatrix

GeneralSparseMatrix::~GeneralSparseMatrix()
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, "Inside the GeneralSparseMatrix Destructor");
#endif
    if (bDeleteArrays)
    {
        if (starts != NULL) delete [] starts;
        starts = NULL;
        if (indexes != NULL) delete [] indexes;
        indexes = NULL;
        if (values != NULL)
            if (vType == ENUM_MATRIX_TYPE_linear || vType == ENUM_MATRIX_TYPE_general)
            {
                for (int i=0; i < valueSize; i++)
                    delete values[i];
                delete [] values;
                values = NULL;
            }
    }
}// end of ~GeneralSparseMatrix

bool GeneralSparseMatrix::display(int secondaryDim)
{
    return true;
}


/** ---------- Methods for class ExpandedMatrixBlocks ---------- */ 
ExpandedMatrixBlocks::ExpandedMatrixBlocks():
    bDeleteArrays(true),
    isColumnMajor(true),
    blockNumber(0),
    blockRows(NULL),
    blockColumns(NULL),
    blocks(NULL)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, "Inside the GeneralSparseMatrix default constructor");
#endif
}// end of ExpandedMatrixBlocks

ExpandedMatrixBlocks::ExpandedMatrixBlocks(bool isColumnMajor_, int startSize, int valueSize):
    bDeleteArrays(true),
    blockNumber(0),
    blockRows(NULL),
    blockColumns(NULL),
    blocks(NULL)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_trace, "Inside the GeneralSparseMatrix default constructor");
#endif
    isColumnMajor = isColumnMajor_;
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

