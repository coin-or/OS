/** @file OSrLReader.cpp
 * 
 * 
 * @author  Robert Fourer,  Jun Ma, Kipp Martin, 
 * @version 1.0, 10/05/2005
 * @since   OS1.0
 *
 * \remarks
 * Copyright (C) 2005, Robert Fourer, Jun Ma, Kipp Martin,
 * Northwestern University, and the University of Chicago.
 * All Rights Reserved.
 * This software is licensed under the Common Public License. 
 * Please see the accompanying LICENSE file in root directory for terms.
 * 
 */ 

#include "OSrLReader.h"
#include "OSErrorClass.h" 



OSResult *yygetOSResult( std::string parsestring) ;


OSrLReader::OSrLReader( ) {								
}

OSrLReader::~OSrLReader(){
	
} 

OSResult* OSrLReader::readOSrL(std::string osrl){   
	try{
		m_parserDataOSrL = new OSrLParserData();
		return yygetOSResult( osrl);
	}
		catch(const ErrorClass& eclass){
		throw ErrorClass( eclass.errormsg); 
	}
}
