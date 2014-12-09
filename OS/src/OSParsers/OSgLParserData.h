/* $Id: OSgLParserData.h 2698 2009-06-09 04:14:07Z kmartin $ */
/** @file OSgLParserData.h
 *
 * @author  Horand Gassmann, Jun Ma, Kipp Martin
 *
 * \remarks
 * Copyright (C) 2005-2011, Horand Gassmann, Jun Ma, Kipp Martin,
 * Northwestern University, and the University of Chicago.
 * All Rights Reserved.
 * This software is licensed under the Eclipse Public License.
 * Please see the accompanying LICENSE file in root directory for terms.
 *
 */
#ifndef OSGLPARSERDATA_H
#define OSGLPARSERDATA_H

#include "OSGeneral.h"
#include "OSMatrix.h"

#include <stdio.h>
#include <string>



/*! \class OSgLParserData
 *  \brief The OSgLParserData Class.
 *
 * \remarks
 * the OSgLParserData class is used to temporarily
 * hold data found in parsing the OSgL data structures.
 * we do this so we can write reusable code.
 */
class OSgLParserData
{
public:

    /** data structure to process an IntVector and hold the data temporarily */
    bool osglMultPresent;
    bool osglIncrPresent;
    bool osglNumberOfElPresent;
    int  osglNumberOfEl;
    int* osglIntArray;
    int  osglMult;
    int  osglIncr;
    int  osglSize;
    int  osglCounter;
    int  osglTempint;

    double* osglDblArray;
    int*    osglValArray;

    /** data structure to process a GeneralFileHeader and hold the data temporarily */
    std::string fileName;
    std::string source;
    std::string description;
    std::string fileCreator;
    std::string licence;
    bool fileNamePresent;
    bool sourcePresent;
    bool descriptionPresent;
    bool fileCreatorPresent;
    bool licencePresent;

    /** the OSgLParserData class constructor */
    OSgLParserData( );

    //** the OSgLParserData class destructor */
    ~OSgLParserData() ;


    /** scanner is used to store data in a reentrant lexer
     * we use this to pass an OSoLParserData object to the parser
     */
    void* scanner;

    /**  if the parser finds invalid text it is held here and we delete
     * if the file was not valid
     */
    char *errorText;

    /** used to accumulate error message so the parser does not die
     *  on the first error encountered
     */
    std::string parser_errors;

    /** two booleans to govern the behavior after an error has been encountered */
    bool ignoreDataAfterErrors;
    bool suppressFurtherErrorMessages;

    /** We need to hold an array of <matrix> elements temporarily */
    OSMatrix** matrix;

    /** We also need to keep track locally of the number of matrices */
    int numberOfMatrices;
    int matrixCounter;

    /** This matrix constructor is needed in order to properly push the constructor vector */
    MatrixNode* tempC;

    /** Several vectors to process the matrix nodes into the right order */
    std::vector<MatrixNode*> mtxConstructorVec;
    std::vector<MatrixNode*> mtxBlocksVec;
    std::vector<MatrixNode*> mtxBlkVec;

    /** 
     *  Vectors to hold rowOffset and colOffset arrays in a place where they
     *  are easily accessible while the <block> children are processed 
     */
    std::vector<int*> rowOffsets;
    std::vector<int*> colOffsets;

    /** other data structures to temporarily hold a matrix and its subordinate elements */
    std::string symmetry;
    bool symmetryPresent;
    std::string name;
    std::string type;
    int  idx;
    bool namePresent;
    bool typePresent;
    bool  idxPresent;
    int  numberOfBlocks;
    int  numberOfColumns;
    int  numberOfRows;
    int  baseMatrixIdx;
    int  targetMatrixFirstRow;
    int  targetMatrixFirstCol;
    int  baseMatrixStartRow;
    int  baseMatrixStartCol;
    int  baseMatrixEndRow;
    int  baseMatrixEndCol;
    bool baseTranspose;
    double scalarMultiplier;
    bool baseMatrixIdxPresent;
    bool targetMatrixFirstRowPresent;
    bool targetMatrixFirstColPresent;
    bool baseMatrixStartRowPresent;
    bool baseMatrixStartColPresent;
    bool baseMatrixEndRowPresent;
    bool baseMatrixEndColPresent;
    bool baseTransposePresent;
    bool scalarMultiplierPresent;
    bool rowMajorPresent;
    bool rowMajor;
    int  blockRowIdx;
    bool blockRowIdxPresent;
    int  blockColIdx;
    bool blockColIdxPresent;
    bool osglConstantPresent;
    bool osglCoefPresent;
    double osglCoef;
    bool numberOfBlocksPresent;
    bool numberOfColumnsPresent;
    bool numberOfRowsPresent;
    bool numberOfValuesPresent;
    int  numberOfValues;
    bool numberOfVarIdxPresent;
    int  numberOfVarIdx;
    bool numberOfElPresent;
    int  numberOfEl;
    int  osglNumberOfNonzeros;
    int  osglNonzeroCounter;

    int* matrixBlockNumberOfRows;
    int* matrixBlockNumberOfCols;
    
    ENUM_NL_EXPR_SHAPE shape;
    bool shapePresent;

};//OSgLParserData

inline void osgl_empty_vectors( OSgLParserData* osglData)
{
    if (osglData->osglIntArray != NULL)
        delete[] osglData->osglIntArray;
    osglData->osglIntArray = NULL;
}//end osgl_empty_vectors


#endif /*OSGLPARSERDATA_H_*/
