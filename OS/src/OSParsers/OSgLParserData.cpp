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
    if (osglValArray != NULL)
        delete[] osglValArray;
    osglValArray = NULL;
}//~OSgLParserData


OSgLParserData::OSgLParserData() :
    osglIntArray(NULL),
    osglCounter(0),
    osglTempint(0),
    osglDblArray(NULL),
    osglValArray(NULL),
    osglStrArray(NULL),

    fileName(""),
    source(""),
    fileCreator(""),
    licence(""),
    fileNamePresent(false),
    sourcePresent(false),
    fileCreatorPresent(false),
    licencePresent(false),

    parser_errors(""),
    ignoreDataAfterErrors(false),
    suppressFurtherErrorMessages(false),
    otherMatrixVarOptionOrResultArray(NULL),
    otherMatrixObjOptionOrResultArray(NULL),
    otherMatrixConOptionOrResultArray(NULL),
    matrix(NULL),
    matrixWithMatrixVarIdx(NULL),
    matrixWithMatrixObjIdx(NULL),
    matrixWithMatrixConIdx(NULL),
    matrixVarIndexes(NULL),
    matrixObjIndexes(NULL),
    matrixConIndexes(NULL),
    matrixCounter(0),
    enumCounter(0),
    tempC(NULL),

    numberOfBlocksPresent(false),
    numberOfColumnsPresent(false),
    numberOfConPresent(false),
    numberOfConIdxPresent(false),
    numberOfConstraintsPresent(false),
    numberOfElPresent(false),
    numberOfEnumerationsPresent(false),
    numberOfItemsPresent(false),
    numberOfMatricesPresent(false),
    numberOfMatrixConPresent(false),
    numberOfMatrixObjPresent(false),
    numberOfMatrixVarPresent(false),
    numberOfObjPresent(false),
    numberOfObjIdxPresent(false),
    numberOfObjectivesPresent(false),
    numberOfRowsPresent(false),
    numberOfValuesPresent(false),
    numberOfVarPresent(false),
    numberOfVarIdxPresent(false),
    numberOfVariablesPresent(false),

    base64SizePresent(false),
    baseMatrixIdxPresent(false),
    baseMatrixStartRowPresent(false),
    baseMatrixStartColPresent(false),
    baseMatrixEndRowPresent(false),
    baseMatrixEndColPresent(false),
    blockRowIdxPresent(false),
    blockColIdxPresent(false),
    coefPresent(false),
    constantPresent(false),
    idxPresent(false),
    incrPresent(false),
    matrixConIdxPresent(false),
    matrixObjIdxPresent(false),
    matrixVarIdxPresent(false),
    multPresent(false),
    scalarMultiplierPresent(false),
    scalarImaginaryPartPresent(false),
    targetMatrixFirstRowPresent(false),
    targetMatrixFirstColPresent(false),

    numberOfBlocks(-1),
    numberOfColumns(-1),
    numberOfCon(-1),
    numberOfConIdx(-1),
    numberOfConstraints(-1),
    numberOfEl(-1),
    numberOfEnumerations(-1),
    numberOfItems(-1),
    numberOfMatrices(-1),
    numberOfMatrixCon(-1),
    numberOfMatrixObj(1),
    numberOfMatrixVar(-1),
    numberOfObj(1),
    numberOfObjIdx(-1),
    numberOfObjectives(-1),
    numberOfRows(-1),
    numberOfValues(-1),
    numberOfVar(-1),
    numberOfVarIdx(-1),
    numberOfVariables(-1),

    base64Size(0),
    baseMatrixIdx(-1),
    baseMatrixStartRow(0),
    baseMatrixStartCol(0),
    baseMatrixEndRow(-1),
    baseMatrixEndCol(-1),
    blockRowIdx(-1),
    blockColIdx(-1),
    coef(0.0),
    constant(0.0),
    idx(0),
    incr(1),
    matrixConIdx(0),
    matrixObjIdx(-1),
    matrixVarIdx(0),
    mult(1),
    scalarMultiplier(1.),
    scalarImaginaryPart(0.),
    targetMatrixFirstRow(0),
    targetMatrixFirstCol(0),

    baseTransposePresent(false),
    categoryPresent(false),
    conTypePresent(false),
    descriptionPresent(false),
    enumTypePresent(false),
    matrixConTypePresent(false),
    matrixNamePresent(false),
    matrixObjTypePresent(false),
    matrixTypePresent(false),
    matrixVarTypePresent(false),
    namePresent(false),
    objTypePresent(false),
    rowMajorPresent(false),
    shapePresent(false),
    solverPresent(false),
    symmetryPresent(false),
    typePresent(false),
    unitPresent(false),
    valuePresent(false),
    valueTypePresent(false),
    varTypePresent(false),
    realPartPresent(false),
    imagPartPresent(false),

    baseTranspose(""),
    category(""),
    conType(""),
    description(""),
    enumType(""),
    matrixConType(""),
    matrixName(""),
    matrixObjType(""),
    matrixType(""),
    matrixVarType(""),
    name(""),
    objType(""),
    rowMajor(""),
    shape(""),
    solver(""),
    symmetry(""),
    type(""),
    unit(""),
    value(""),
    valueType(""),
    varType(""),
    realPart(0.0),
    imagPart(0.0)
{
}//OSgLParserData

