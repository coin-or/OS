/* $Id: OSgLParserData.h 2698 2009-06-09 04:14:07Z kmartin $ */
/** @file OSgLParserData.h
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
#ifndef OSGLPARSERDATA_H
#define OSGLPARSERDATA_H

#include "OSGeneral.h"

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

    /** We need to hold a <matrix> element temporarily */
    OSMatrix* matrix;

    /** We also need to keep track locally of the number of matrices */
    int numberOfMatrices;

    /** data structures to temporarily hold a matrix and its subordinate elements */
    std::string  symmetryAttribute;
    bool symmetryAttributePresent;
    std::string  matrixNameAttribute;
    std::string  matrixTypeAttribute;
    bool matrixNameAttributePresent;
    bool matrixTypeAttributePresent;
    int  numberOfBlocks;
    bool numberOfBlocksPresent;
    int  numberOfColumns;
    bool numberOfColumnsPresent;
    int  numberOfRows;
    bool numberOfRowsPresent;
    int  baseMatrixIdxAttribute;
    int  targetMatrixFirstRowAttribute;
    int  targetMatrixFirstColAttribute;
    int  baseMatrixStartRowAttribute;
    int  baseMatrixStartColAttribute;
    int  baseMatrixEndRowAttribute;
    int  baseMatrixEndColAttribute;
    bool baseTransposeAttribute;
    double scalarMultiplierAttribute;
    bool baseMatrixIdxAttributePresent;
    bool targetMatrixFirstRowAttributePresent;
    bool targetMatrixFirstColAttributePresent;
    bool baseMatrixStartRowAttributePresent;
    bool baseMatrixStartColAttributePresent;
    bool baseMatrixEndRowAttributePresent;
    bool baseMatrixEndColAttributePresent;
    bool baseTransposeAttributePresent;
    bool scalarMultiplierAttributePresent;
    bool rowMajorAttribute;
    bool excludeIfSetAttribute;
    int  blockRowIdx;
    bool blockRowIdxAttributePresent;
    int  blockColIdx;
    bool blockColIdxAttributePresent;
    bool osglNumberOfVarIdxPresent;
    bool osglConstantPresent;
    bool osglCoefPresent;
    double osglCoef;
    bool numberOfBlocksAttributePresent;
    bool numberOfColumnsAttributePresent;
    bool numberOfRowsAttributePresent;
    bool numberOfVarIdxAttributePresent;
    int  numberOfVarIdx;
    bool numberOfElAttributePresent;
    int  numberOfEl;

    

};//OSgLParserData

inline void osgl_empty_vectors( OSgLParserData* osglData)
{
    if (osglData->osglIntArray != NULL)
        delete[] osglData->osglIntArray;
    osglData->osglIntArray = NULL;
}//end osgl_empty_vectors


#endif /*OSGLPARSERDATA_H_*/
