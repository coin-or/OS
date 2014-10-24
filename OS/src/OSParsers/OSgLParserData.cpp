/* $Id: OSgLParserData.cpp 3710 2010-10-04 03:39:42Z Gassmann $ */
/** @file OSgLParserData.cpp
 *
 * @author  Horand Gassmann, Jun Ma, Kipp Martin,
 *
 * \remarks
 * Copyright (C) 2005-2011, Horand Gassmann, Jun Ma, Kipp Martin,
 * Northwestern University, and the University of Chicago.
 * All Rights Reserved.
 * This software is licensed under the Eclipse Public License.
 * Please see the accompanying LICENSE file in root directory for terms.
 *
 */
#include "OSgLParserData.h"
#include <stdio.h>


OSgLParserData::~OSgLParserData()
{
    if (osglIntArray != NULL)
        delete[] osglIntArray;
    osglIntArray = NULL;
    if (osglDblArray != NULL)
        delete[] osglDblArray;
    osglDblArray = NULL;
}//~OSgLParserData


OSgLParserData::OSgLParserData() :
    osglMultPresent(false),
    osglIncrPresent(false),
    osglNumberOfElPresent(false),
    osglNumberOfEl(-1),
    osglIntArray(NULL),
    osglMult(1),
    osglIncr(1),
    osglSize(0),
    osglCounter(0),
    osglTempint(0),
    osglDblArray(NULL),
    osglValArray(NULL),

    fileName(""),
    source(""),
    description(""),
    fileCreator(""),
    licence(""),
    fileNamePresent(false),
    sourcePresent(false),
    descriptionPresent(false),
    fileCreatorPresent(false),
    licencePresent(false),
    parser_errors(""),
    ignoreDataAfterErrors(false),
    suppressFurtherErrorMessages(false),
    matrix(NULL),
    numberOfMatrices(0),
    matrixCounter(0),
    tempC(NULL),
    symmetryAttribute(""),
    symmetryAttributePresent(false),
    matrixNameAttribute(""),
    matrixTypeAttribute(""),
    matrixNameAttributePresent(false),
    matrixTypeAttributePresent(false),
    numberOfBlocks(-1),
    numberOfColumns(-1),
    numberOfRows(-1),
    baseMatrixIdxAttribute(-1),
    targetMatrixFirstRowAttribute(0),
    targetMatrixFirstColAttribute(0),
    baseMatrixStartRowAttribute(0),
    baseMatrixStartColAttribute(0),
    baseMatrixEndRowAttribute(-1),
    baseMatrixEndColAttribute(-1),
    baseTransposeAttribute(false),
    scalarMultiplierAttribute(0.0),
    baseMatrixIdxAttributePresent(false),
    targetMatrixFirstRowAttributePresent(false),
    targetMatrixFirstColAttributePresent(false),
    baseMatrixStartRowAttributePresent(false),
    baseMatrixStartColAttributePresent(false),
    baseMatrixEndRowAttributePresent(false),
    baseMatrixEndColAttributePresent(false),
    baseTransposeAttributePresent(false),
    scalarMultiplierAttributePresent(false),
    rowMajorAttributePresent(false),
    rowMajorAttribute(false),
    negativePatternAttribute(false),
    blockRowIdx(-1),
    blockRowIdxAttributePresent(false),
    blockColIdx(-1),
    blockColIdxAttributePresent(false),
    osglConstantPresent(false),
    osglCoefPresent(false),
    osglCoef(0.0),
    numberOfBlocksAttributePresent(false),
    numberOfColumnsAttributePresent(false),
    numberOfRowsAttributePresent(false),
    numberOfValuesAttributePresent(false),
    numberOfValues(0),
    numberOfVarIdxAttributePresent(false),
    numberOfVarIdx(0),
    numberOfElAttributePresent(false),
    numberOfEl(0),
    osglNumberOfNonzeros(0),
    osglNonzeroCounter(0),
    matrixBlockNumberOfRows(NULL),
    matrixBlockNumberOfCols(NULL)
{

}//OSgLParserData

