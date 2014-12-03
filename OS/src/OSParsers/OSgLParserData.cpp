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
    symmetry(""),
    symmetryPresent(false),
    name(""),
    type(""),
    idx(-1),
    namePresent(false),
    typePresent(false),
    idxPresent(false),
    numberOfBlocks(-1),
    numberOfColumns(-1),
    numberOfRows(-1),
    baseMatrixIdx(-1),
    targetMatrixFirstRow(0),
    targetMatrixFirstCol(0),
    baseMatrixStartRow(0),
    baseMatrixStartCol(0),
    baseMatrixEndRow(-1),
    baseMatrixEndCol(-1),
    baseTranspose(false),
    scalarMultiplier(0.0),
    baseMatrixIdxPresent(false),
    targetMatrixFirstRowPresent(false),
    targetMatrixFirstColPresent(false),
    baseMatrixStartRowPresent(false),
    baseMatrixStartColPresent(false),
    baseMatrixEndRowPresent(false),
    baseMatrixEndColPresent(false),
    baseTransposePresent(false),
    scalarMultiplierPresent(false),
    rowMajorPresent(false),
    rowMajor(false),
    blockRowIdx(-1),
    blockRowIdxPresent(false),
    blockColIdx(-1),
    blockColIdxPresent(false),
    osglConstantPresent(false),
    osglCoefPresent(false),
    osglCoef(0.0),
    numberOfBlocksPresent(false),
    numberOfColumnsPresent(false),
    numberOfRowsPresent(false),
    numberOfValuesPresent(false),
    numberOfValues(0),
    numberOfVarIdxPresent(false),
    numberOfVarIdx(0),
    numberOfElPresent(false),
    numberOfEl(0),
    osglNumberOfNonzeros(0),
    osglNonzeroCounter(0),
    matrixBlockNumberOfRows(NULL),
    matrixBlockNumberOfCols(NULL),
    shape(ENUM_NL_EXPR_SHAPE_general),
    shapePresent(false)

{

}//OSgLParserData

