/* $Id: OSParseosgl.y.inc 4806 2014-06-07 11:37:46Z Gassmann $ */
/** @file OSParseosgl.y.inc
 *
 * @author  Horand Gassmann, Jun Ma, Kipp Martin 
 *
 * \remarks
 * Copyright (C) 2005-2014, Horand Gassmann, Jun Ma, Kipp Martin,
 * Northwestern University, and the University of Chicago.
 * All Rights Reserved.
 * This software is licensed under the Common Public License.
 * Please see the accompanying LICENSE file in root directory for terms.
 *
 * This file contains parser elements that are contained in the OSgL schema
 * and are shared between several of the main schemas, OSiL, OSoL and OSrL.
 *
 * The code is mainained in such a way that it can be inserted into any parser
 * by a makefile with minimal changes. The only change required is to change
 * every occurrence of the placeholder "targetObject" to the appropriate
 * reference ("osinstance" for OSiL files, "osobject" for OSoL files and
 * "osresult" for OSrL files). The makefile accomplishes this through 
 * maintaining each parser in two parts and to copy this include file 
 * between the parts to make the final OSParseosxl.y file.
 * 
 */

/** ==========================================================================
 *    This portion parses a header object used in OSoL and OSrL schema files
 *  ==========================================================================
 */
osglFileHeader: headerElementStart headerElementContent;
 
headerElementStart: HEADERSTART
{
    osglData->fileName    = "";
    osglData->source      = "";
    osglData->description = "";
    osglData->fileCreator = "";
    osglData->licence     = "";
    osglData->fileNamePresent    = false;
    osglData->sourcePresent      = false;
    osglData->descriptionPresent = false;
    osglData->fileCreatorPresent = false;
    osglData->licencePresent     = false;
};

headerElementContent: headerElementEmpty | headerElementLaden;

headerElementEmpty: GREATERTHAN HEADEREND | ENDOFELEMENT;

headerElementLaden: GREATERTHAN headerElementBody HEADEREND; 

headerElementBody: headerElementList;

headerElementList: headerChild | headerElementList headerChild;

headerChild:
    fileName 
  | fileSource 
  | fileDescription 
  | fileCreator 
  | fileLicence;

fileName: | fileNameContent
{
    if (osglData->fileNamePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, targetObject, parserData, osglData, "Repeated header information: file name");
    else
        osglData->fileNamePresent = true;
};

fileNameContent: fileNameEmpty | fileNameLaden;

fileNameEmpty: FILENAMESTARTANDEND | FILENAMEEMPTY;

fileNameLaden: FILENAMESTART ITEMTEXT FILENAMEEND
{
    osglData->fileName = $2;
    free($2);
};

fileSource: | fileSourceContent
{
    if (osglData->sourcePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, targetObject, parserData, osglData, "Repeated header information: source");
    else
        osglData->sourcePresent = true;
};

fileSourceContent: fileSourceEmpty | fileSourceLaden;

fileSourceEmpty: FILESOURCESTARTANDEND | FILESOURCEEMPTY;

fileSourceLaden: FILESOURCESTART ITEMTEXT FILESOURCEEND
{
    osglData->source = $2;
    free($2);
};

fileDescription: | fileDescriptionContent
{
    if (osglData->descriptionPresent == true)
        parserData->parser_errors += addErrorMsg( NULL, targetObject, parserData, osglData, "Repeated header information: description");
    else
        osglData->descriptionPresent = true;
};

fileDescriptionContent: fileDescriptionEmpty | fileDescriptionLaden;

fileDescriptionEmpty: FILEDESCRIPTIONSTARTANDEND | FILEDESCRIPTIONEMPTY;

fileDescriptionLaden: FILEDESCRIPTIONSTART ITEMTEXT FILEDESCRIPTIONEND
{
    osglData->description = $2;
    free($2);
};

fileCreator: | fileCreatorContent
{
    if (osglData->fileCreatorPresent == true)
        parserData->parser_errors += addErrorMsg( NULL, targetObject, parserData, osglData, "Repeated header information: file creator");
    else
        osglData->fileCreatorPresent = true;
};

fileCreatorContent: fileCreatorEmpty | fileCreatorLaden;

fileCreatorEmpty: FILECREATORSTARTANDEND | FILECREATOREMPTY;

fileCreatorLaden: FILECREATORSTART ITEMTEXT FILECREATOREND
{
    osglData->fileCreator = $2;
    free($2);
};

fileLicence: | fileLicenceContent
{
    if (osglData->licencePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, targetObject, parserData, osglData, "Repeated header information: licence");
    else
        osglData->licencePresent = true;
};

fileLicenceContent: fileLicenceEmpty | fileLicenceLaden;

fileLicenceEmpty: FILELICENCESTARTANDEND | FILELICENCEEMPTY;

fileLicenceLaden: FILELICENCESTART ITEMTEXT FILELICENCEEND
{
    osglData->licence = $2;
    free($2);
};

/** ==========================================================================
 *              This portion parses the content of an IntVector object
 *  ==========================================================================
 */

osglIntArrayData: 
    osglIntVectorElArray 
    {
         if (osglData->osglCounter < osglData->osglNumberOfEl)
        {
            parserData->parser_errors += addErrorMsg( NULL, targetObject, parserData, osglData, "fewer data elements than specified");
            parserData->ignoreDataAfterErrors = true;
        }
    }
 | osglIntVectorBase64;

osglIntVectorElArray: | osglIntVectorElArray osglIntVectorEl;

osglIntVectorEl: osglIntVectorElStart osglIntVectorElAttributes osglIntVectorElContent;

osglIntVectorElStart: ELSTART
{    
    osglData->osglMultPresent = false;
    osglData->osglIncrPresent = false;
    osglData->osglMult = 1;
    osglData->osglIncr = 0;
};


osglIntVectorElAttributes: osglIntVectorElAttList;

osglIntVectorElAttList: | osglIntVectorElAttList osglIntVectorElAtt;

osglIntVectorElAtt: osglMultAttribute | osglIncrAttribute;

osglIntVectorElContent: GREATERTHAN INTEGER ELEND
{
    if (osglData->osglCounter + osglData->osglMult > osglData->osglNumberOfEl)
    {
        if (!parserData->suppressFurtherErrorMessages)
        {
            parserData->parser_errors += addErrorMsg( NULL, targetObject, parserData, osglData, "more data elements than specified");
            parserData->suppressFurtherErrorMessages = true;
            parserData->ignoreDataAfterErrors = true;
        }
    }
    else
        for (int i=0; i<osglData->osglMult; i++)
            osglData->osglIntArray[osglData->osglCounter++] = $2 + i*osglData->osglIncr;    
};

osglIntVectorBase64: BASE64START Base64SizeAttribute Base64Content;

Base64SizeAttribute: SIZEOFATT quote INTEGER quote
{
    osglData->osglSize = $3;
};

Base64Content: Base64Empty | Base64Laden;

Base64Empty: GREATERTHAN BASE64END | ENDOFELEMENT;


Base64Laden: GREATERTHAN ELEMENTTEXT BASE64END
{
    char* b64string = $2;
    if( b64string == NULL) 
        parserData->parser_errors += addErrorMsg( NULL, targetObject, parserData, osglData, "base 64 data expected"); 
    if (osglData->osglSize != sizeof(int))
        parserData->parser_errors += addErrorMsg( NULL, targetObject, parserData, osglData, "base 64 encoded with a size of int different than on this machine"); 

    std::string base64decodeddata = Base64::decodeb64( b64string );
    int base64decodeddatalength = base64decodeddata.length();
    int *intvec = NULL;
    if ( parserData->numberOf != (base64decodeddatalength/osglData->osglSize) )
        parserData->parser_errors += addErrorMsg( NULL, targetObject, parserData, osglData, "base 64 data length does not match numberOfEl"); 
    else
    {
        intvec = (int*)&base64decodeddata[0];
        for(int i = 0; i < (base64decodeddatalength/osglData->osglSize); i++)
        {
            osglData->osglIntArray[i] = *(intvec++);
        }
    }
    //delete[] b64string;
    free($2);
};


osglIncrAttribute: INCRATT quote INTEGER quote 
{    
    if (osglData->osglIncrPresent) 
        parserData->parser_errors += addErrorMsg( NULL, targetObject, parserData, osglData, "only one incr attribute allowed");
    osglData->osglIncrPresent = true;
    osglData->osglIncr = $3;
};

osglMultAttribute: MULTATT quote INTEGER quote 
{    
    if (osglData->osglMultPresent) 
        parserData->parser_errors += addErrorMsg( NULL, targetObject, parserData, osglData, "only one mult attribute allowed");
    if ($3 <= 0) parserData->parser_errors += addErrorMsg( NULL, targetObject, parserData, osglData, "mult must be positive");
    osglData->osglMultPresent = true;
    osglData->osglMult = $3;
};


/** ===================================================================================
 *    This portion parses an OSMatrix object used in OSiL, OSoL and OSrL schema files
 *  ===================================================================================
 */
osglMatrix: matrixStart matrixAttributes matrixContent;
 
matrixStart: MATRIXSTART
{
    //osglData->...;
};

matrixAttributes: 
    | symmetryAttribute
    | numberOfRowsAttribute
    | numberOfColumnsAttribute
    | matrixNameAttribute
    {
        if (verifySymmetry(osglData->symmetryAttribute) == false)
            parserData->parser_errors += addErrorMsg( NULL, targetObject, parserData, osglData, "symmetry type not recognized");
        parserData->errorText = NULL;
    };

symmetryAttribute: SYMMETRYATT ATTRIBUTETEXT QUOTE 
{ 
    if (osglData->symmetryAttributePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, targetObject, parserData, osglData, "more than one symmetry attribute in <matrix> element");
    osglData->symmetryAttributePresent = true;   
    osglData->symmetryAttribute = $2; 
    free($2);
};


matrixNameAttribute: NAMEATT ATTRIBUTETEXT QUOTE 
{ 
    if (osglData->matrixNameAttributePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, targetObject, parserData, osglData, "more than one name attribute in <matrix> element");
    osglData->matrixNameAttributePresent = true;   
    osglData->matrixNameAttribute = $2; 
    free($2);
};

matrixContent: matrixEmpty | matrixLaden;

matrixEmpty: GREATERTHAN MATRIXEND | ENDOFELEMENT;

matrixLaden: GREATERTHAN matrixBody MATRIXEND; 

matrixBody: baseMatrix matrixConstructorList;

baseMatrix: | baseMatrixStart baseMatrixAttributes baseMatrixEnd;

baseMatrixStart: BASEMATRIXSTART;

baseMatrixAttributes: baseMatrixAttList;

baseMatrixAttList: | baseMatrixAttList baseMatrixAtt;

baseMatrixAtt:
      baseMatrixIdxAttribute
    | targetMatrixFirstRowAttribute
    | targetMatrixFirstColAttribute
    | baseMatrixStartRowAttribute
    | baseMatrixStartColAttribute
    | baseMatrixEndRowAttribute
    | baseMatrixEndColAttribute
    | baseTransposeAttribute
    | scalarMultiplierAttribute;

baseMatrixIdxAttribute: BASEMATRIXIDXATT QUOTE INTEGER QUOTE 
{ 
    if (osglData->baseMatrixIdxAttributePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, targetObject, parserData, osglData, "more than one baseMatrixIdx attribute in <baseMatrix> element");
    if ($3 < 0)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "baseMatrix idx cannot be negative");
    osglData->baseMatrixIdxAttributePresent = true;   
    osglData->baseMatrixIdxAttribute = $3; 
};

targetMatrixFirstRowAttribute: TARGETMATRIXFIRSTROWATT QUOTE INTEGER QUOTE 
{ 
    if (osglData->targetMatrixFirstRowAttributePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, targetObject, parserData, osglData, "more than one targetMatrixFirstRow attribute in <baseMatrix> element");
    if ($3 < 0)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "targetMatrix first row cannot be negative");
    osglData->targetMatrixFirstRowAttributePresent = true;   
    osglData->targetMatrixFirstRowAttribute = $3; 
};

targetMatrixFirstColAttribute: TARGETMATRIXFIRSTCOLATT QUOTE INTEGER QUOTE
{ 
    if (osglData->targetMatrixFirstColAttributePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, targetObject, parserData, osglData, "more than one targetMatrixFirstCol attribute in <baseMatrix> element");
    if ($3 < 0)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "targetMatrix first col cannot be negative");
    osglData->targetMatrixFirstColAttributePresent = true;   
    osglData->targetMatrixFirstColAttribute = $3; 
};

baseMatrixStartRowAttribute: BASEMATRIXSTARTROWATT QUOTE INTEGER QUOTE
{ 
    if (osglData->baseMatrixStartRowAttributePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, targetObject, parserData, osglData, "more than one baseMatrixStartRow attribute in <baseMatrix> element");
    if ($3 < 0)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "baseMatrix first row cannot be negative");
    osglData->baseMatrixStartRowAttributePresent = true;   
    osglData->baseMatrixStartRowAttribute = $3; 
};

baseMatrixStartColAttribute: BASEMATRIXSTARTCOLATT QUOTE INTEGER QUOTE
{ 
    if (osglData->baseMatrixStartColAttributePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, targetObject, parserData, osglData, "more than one baseMatrixStartCol attribute in <baseMatrix> element");
    if ($3 < 0)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "baseMatrix first col cannot be negative");
    osglData->baseMatrixStartColAttributePresent = true;   
    osglData->baseMatrixStartColAttribute = $3; 
};

baseMatrixEndRowAttribute: BASEMATRIXENDROWATT QUOTE INTEGER QUOTE
{ 
    if (osglData->baseMatrixEndRowAttributePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, targetObject, parserData, osglData, "more than one baseMatrixEndRow attribute in <baseMatrix> element");
    if ($3 < 0)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "baseMatrix last row cannot be negative");
    osglData->baseMatrixEndRowAttributePresent = true;   
    osglData->baseMatrixEndRowAttribute = $3; 
};

baseMatrixEndColAttribute: BASEMATRIXENDCOLATT QUOTE INTEGER QUOTE
{ 
    if (osglData->baseMatrixEndColAttributePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, targetObject, parserData, osglData, "more than one baseMatrixEndCol attribute in <baseMatrix> element");
    if ($3 < 0)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "baseMatrix last col cannot be negative");
    osglData->baseMatrixEndColAttributePresent = true;   
    osglData->baseMatrixEndColAttribute = $3; 
};

baseTransposeAttribute: baseTransposeAtt
{ 
    if (osglData->baseTransposeAttributePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, targetObject, parserData, osglData, "more than one baseTranspose attribute in <baseMatrix> element");
    osglData->baseTransposeAttributePresent = true;   
};

baseTransposeAtt: baseTransposeAttEmpty | baseTransposeAttContent;

baseTransposeAttEmpty: EMPTYBASETRANSPOSEATT
{
    osglData->baseTransposeAttribute = false;
};

baseTransposeAttContent: BASETRANSPOSEATT ATTRIBUTETEXT quote 
{ 
    if ($2 == "true") osglData->baseTransposeAttribute = true;
        else          osglData->baseTransposeAttribute = false;
    free($2);
};

scalarMultiplierAttribute: SCALARMULTIPLIERATT QUOTE aNumber QUOTE
{
    if (osglData->scalarMultiplierAttributePresent == true)
        parserData->parser_errors += addErrorMsg( NULL, targetObject, parserData, osglData, "more than one scalar multiplier attribute in <baseMatrix> element");
    osglData->scalarMultiplierAttributePresent = true;   
    osglData->scalarMultiplierAttribute = parserData->tempVal;
};

baseMatrixEnd: GREATERTHAN BASEMATRIXEND | ENDOFELEMENT;

matrixConstructorList: | matrixConstructorList matrixConstructor;

matrixConstructor: matrixElements | matrixTransformation | matrixBlocks;

matrixElements: matrixElementsStart MatrixElementsAttributes MatrixElementsContent;

matrixElementsStart: ;

MatrixElementsAttributes: ; 

MatrixElementsContent: ;

matrixTransformation: OSnLMNode;

matrixBlocks: matrixBlocksStart matrixBlocksAttributes matrixBlocksContent;

matrixBlocksStart: BLOCKSSTART; 

matrixBlocksAttributes: numberOfBlocksAttribute;

matrixBlocksContent: colOffsets rowOffsets blockList;

colOffsets: 

rowOffsets:

blockList: | blockList matrixBlock;

matrixBlock: matrixBlockStart matrixBlockAttributes matrixBlockContent;

matrixBlockStart: BLOCKSTART; 

matrixBlockAttributes: matrixBlockAttList;

matrixBlockAttList: matrixBlockAtt | matrixBlockAttList matrixBlockAtt;

matrixBlockAtt:
      blockRowIdxAtt 
    | blockColIdxAtt 
    | symmetryAttribute
    {
        if (verifySymmetry(parserData->symmetryAttribute) == false)
            parserData->parser_errors += addErrorMsg( NULL, targetObject, parserData, osglData, "symmetry type not recognized");
        parserData->errorText = NULL;
    };

blockRowIdxAtt: ;

blockColIdxAtt: ;

matrixBlockContent: blockEmpty | blockLaden;

blockEmpty: GREATERTHAN BLOCKEND | ENDOFELEMENT;

blockLaden: GREATERTHAN blockBody BLOCKEND; 

blockBody: baseMatrix matrixConstructorList;


OSnLMNode: matrixReference
         | matrixDiagonal
         | matrixDotTimes
         | matrixIdentity
         | matrixInverse
         | matrixMerge
         | matrixMinus
         | matrixPlus
         | matrixTimes
         | matrixScalarTimes
         | matrixSubMatrixAt
         | matrixTranspose;

matrixReference: ;
matrixDiagonal: ;
matrixDotTimes: ;
matrixIdentity: ;
matrixInverse: ;
matrixMerge: ;
matrixMinus: ;
matrixPlus: ;
matrixTimes: ;
matrixScalarTimes: ;
matrixSubMatrixAt: ;
matrixTranspose: ;

numberOfBlocksAttribute: NUMBEROFBLOCKSATT quote INTEGER quote
{
    if (osglData->numberOfBlocksAttributePresent)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "numberOfBlocks attribute previously set");
    if ($3 < 0) parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "number of <blocks> cannot be negative");
    osglData->numberOfBlocksAttributePresent = true;        
    osglData->numberOfBlocks = $3;
};

numberOfColumnsAttribute: NUMBEROFCOLUMNSATT quote INTEGER quote
{
    if (osglData->numberOfColumnsAttributePresent)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "numberOfColumns attribute previously set");
    if ($3 < 0) parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "number of <blocks> cannot be negative");
    osglData->numberOfColumnsAttributePresent = true;        
    osglData->numberOfColumns = $3;
};

numberOfRowsAttribute: NUMBEROFROWSATT quote INTEGER quote
{
    if (osglData->numberOfRowsAttributePresent)
        parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "numberOfRows attribute previously set");
    if ($3 < 0) parserData->parser_errors += addErrorMsg( NULL, osoption, parserData, osglData, "number of <rows> cannot be negative");
    osglData->numberOfRowsAttributePresent = true;        
    osglData->numberOfRows = $3;
};


