/* $Id: OSParseIntVector.y.inc 3711 2010-10-05 23:29:09Z Gassmann $ */
/** @file OSParseIntVector.y.inc
 * 
 * @author  Horand Gassmann, Jun Ma, Kipp Martin, 
 * @version 2.1, 19/05/2010
 * @since   OS1.0
 *
 * \remarks
 * Copyright (C) 2005-2010, Horand Gassmann, Jun Ma, Kipp Martin,
 * Dalhousie University, Northwestern University and the University of Chicago.
 * All Rights Reserved.
 * This software is licensed under the Common Public License. 
 * Please see the accompanying LICENSE file in root directory for terms.
 * 
 */
 
/** This is an include file to read and process the general data structure IntVector.
 *  IntVector is set up in OSgL and is shared in several schemas such as OSoL, OSrL and OSiL.
 *  By providing this include file, the same code can be shared between different parsers
 *  without the complication of rolling all parses into the same file.
 *
 *  The IntVector data are stored temporarily into OSgLParserData, 
 *  from where they can be moved to permanent positions in OSOption, OSResult, etc.
 */
     
 
osglIntVectorData: osglIntVectorElArray | osglIntVectorBase64;

osglIntVectorElArray: | osglIntVectorElArray osglIntVectorEl;

osglIntVectorEl: osglIntVectorElStart osglIntVectorElAttributes osglIntVectorElContent;

osglIntVectorElStart: ELSTART
{	
	osglData->osglMultPresent = false;
	osglData->osglIncrPresent = false;
	osglData->osglMult = 1;
	osglData->osglIncr = 1;
};


osglIntVectorElAttributes: osglIntVectorElAttList;

osglIntVectorElAttList: | osglIntVectorElAttList osglIntVectorElAtt;

osglIntVectorElAtt: osglMultAttribute | osglIncrAttribute;

osglIntVectorElContent: GREATERTHAN INTEGER ELEND
{
	if (osglData->osglCounter + osglData->osglMult > osglData->osglNumberOfEl)
		osrlerror(NULL, NULL, parserData, "more data elements than specified");
	for (int i=0; i<osglData->osglMult; i++)
		osglData->osglIntVector[osglData->osglCounter++] = $2 + i*osglIncr;	
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
		osrlerror(NULL, NULL, parserData, "base 64 data expected"); 
	if (osglData->osglSize != sizeof(int))
		osrlerror(NULL, NULL, parserData, "base 64 encoded with a size of int different than on this machine"); 

	std::string base64decodeddata = Base64::decodeb64( b64string );
	int base64decodeddatalength = base64decodeddata.length();
	int *intvec = NULL;
	osglData->osglIntVector = new int[(base64decodeddatalength/dataSize) ];
	intvec = (int*)&base64decodeddata[0];
	for(i = 0; i < (base64decodeddatalength/dataSize); i++)
	{
		osglData->osglIntVector[i] = *(intvec++);
	}
	delete [] b64string;
};


osglIncrAttribute: INCRATT quote INTEGER quote 
{	
	if (osglData->osglIncrPresent) 
        osrlerror(NULL, NULL, parserData, "only one incr attribute allowed");
	osglData->osglIncrPresent = true;
	osglData->osglIncr = $3;
};

osglMultAttribute: MULTATT quote INTEGER quote 
{	
	if (osglData->osglMultPresent) 
        osrlerror(NULL, NULL, parserData, "only one mult attribute allowed");
	if ($3 <= 0) osrlerror(NULL, NULL, parserData, "mult must be positive");
	osglData->osglMultPresent = true;
	osglData->osglMult = $3;
};
