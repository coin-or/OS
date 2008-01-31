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




void yygetOSResult( const char *ch, OSResult* m_osresult, OSrLParserData *m_parserData) throw(ErrorClass);
int osrllex_init(void** ptr_yy_globals);
int osrllex_destroy (void* scanner );
void osrlset_extra (OSrLParserData* parserData , void* yyscanner );


OSrLReader::OSrLReader( )  {	
	m_parserData = new OSrLParserData();
	m_osresult = new OSResult(); 
	// initialize the lexer and set yyextra
	osrllex_init( &(m_parserData->scanner) );
	osrlset_extra (m_parserData ,   m_parserData->scanner);						
}

OSrLReader::~OSrLReader(){
	// delete the osresult object
	if(m_osresult != NULL) delete m_osresult;
	m_osresult = NULL;
	// now delete the scanner that was initialized
	osrllex_destroy(m_parserData->scanner );
	// findally delete parser data
	if( m_parserData != NULL) delete m_parserData;
	m_parserData = NULL;
	
} 

OSResult* OSrLReader::readOSrL(const std::string& posrl) throw(ErrorClass){  	
	try{
		const char *ch = posrl.c_str();
		yygetOSResult( ch, m_osresult, m_parserData);
		return m_osresult;
	}
		catch(const ErrorClass& eclass){
		throw ErrorClass( eclass.errormsg); 
	}
}
