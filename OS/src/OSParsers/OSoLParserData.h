/** @file OSoLParserData.h
 * 
 * @author  Robert Fourer, Horand Gassmann, Jun Ma, Kipp Martin, 
 * @version 1.0, 29/08/2008
 * @since   OS1.1
 *
 * \remarks
 * Copyright (C) 2005, Robert Fourer, Horand Gassmann, Jun Ma, Kipp Martin,
 * Northwestern University, Dalhousie University and the University of Chicago.
 * All Rights Reserved.
 * This software is licensed under the Common Public License. 
 * Please see the accompanying LICENSE file in root directory for terms.
 * 
 */
#ifndef OSOLPARSERDATA_H
#define OSOLPARSERDATA_H

#include "OSnLNode.h"
#include <vector> 





/*! \class OSoLParserData
 *  \brief The OSoLParserData  Class.
 * 
 * @author Robert Fourer, Horand Gassmann, Jun Ma, Kipp Martin
 * @version 1.0, 08/29/2008
 * @since OS 1.1
 * 
 * \remarks
 * the OSoLParserData class is used to temporarily 
 * hold data found in parsing the OSoL instance
 * we do this so we can have a reentrant parser.
 */
class OSoLParserData{
public:
	
	/** the OSoLParserData class constructor */
	OSoLParserData( );
	
	//** the OSoLParserData class destructor */
	~OSoLParserData() ;
	
	
	/**  the status type of the result */ 
	std::string statusType;
	
	/** the status Description of the solution */
	std::string statusDescription;

	/** scanner is used to store data in a reentrant lexer 
	 * we use this to pass an OSoLParserData object to the parser*/
	void* scanner;
	
	
	/**  if the parser finds invalid text it is held here and we delete
	 * if the file was not valid
	 */
	char *errorText;
};

#endif /*OSOLPARSERDATA_H_*/
