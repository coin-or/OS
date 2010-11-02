/* $Id: OSgLParserData.h 2698 2009-06-09 04:14:07Z kmartin $ */
/** @file OSgLParserData.h
 * 
 * @author  Robert Fourer, Horand Gassmann, Jun Ma, Kipp Martin, 
 * @version 1.0, 20/Oct/2010
 * @since   OS2.2
 *
 * \remarks
 * Copyright (C) 2005-2010, Robert Fourer, Horand Gassmann, Jun Ma, Kipp Martin,
 * Northwestern University, Dalhousie University and the University of Chicago.
 * All Rights Reserved.
 * This software is licensed under the Common Public License. 
 * Please see the accompanying LICENSE file in root directory for terms.
 * 
 */
#ifndef OSGLPARSERDATA_H
#define OSGLPARSERDATA_H




/*! \class OSgLParserData
 *  \brief The OSgLParserData Class.
 * 
 * @author Robert Fourer, Horand Gassmann, Jun Ma, Kipp Martin
 * @version 1.0, 20/Oct/2010
 * @since   OS2.2
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

#endif /*OSGLPARSERDATA_H_*/
