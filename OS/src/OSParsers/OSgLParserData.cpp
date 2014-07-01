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

    symmetryAttribute(""),
    symmetryAttributePresent(false),
    matrixNameAttribute(""),
    matrixNameAttributePresent(false),
    numberOfBlocks(-1),
    numberOfBlocksPresent(false),
    numberOfColumns(-1),
    numberOfColumnsPresent(false),
    numberOfRows(-1),
    numberOfRowsPresent(false),
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
    rowMajorAttribute(false)
{

}//OSgLParserData

