/* $Id: OSgLParserData.h 2698 2009-06-09 04:14:07Z kmartin $ */
/** @file OSgLParserData.h
 * 
 * @author  Horand Gassmann, Jun Ma, Kipp Martin, 
 *
 * \remarks
 * Copyright (C) 2005-2011, Horand Gassmann, Jun Ma, Kipp Martin,
 * Dalhousie University Northwestern University, ,and the University of Chicago.
 * All Rights Reserved.
 * This software is licensed under the Eclipse Public License. 
 * Please see the accompanying LICENSE file in root directory for terms.
 * 
 */
#ifndef OSGLPARSERDATA_H
#define OSGLPARSERDATA_H

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
class OSgLParserData{
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

	/** data structure to process a GeneralFileHeader and hold the data temporarily */
	std::string fileName;
	std::string source;
	std::string description;
	std::string fileCreatedBy;
	std::string licence;

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
};//OSgLParserData

inline void osgl_empty_vectors( OSgLParserData* osglData)
{
	if (osglData->osglIntArray != NULL)
		delete[] osglData->osglIntArray;
}//end osgl_empty_vectors


#endif /*OSGLPARSERDATA_H_*/
