/** @file OSiLReader.cpp
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

#include "OSiLReader.h"


//bison function
void yygetOSInstance(const char *osil, OSInstance* osinstance, OSiLParserData *parserData) throw(ErrorClass);
//lex functions
int osillex_init(void** ptr_yy_globals);
int osillex_destroy (void* scanner );
void osilset_extra (OSiLParserData* parserData , void* yyscanner );


OSiLReader::OSiLReader( ) {
	m_osinstance = new OSInstance();
	m_parserData = new OSiLParserData();
	// initialize the lexer and set yyextra
	osillex_init( &(m_parserData->scanner) );
	osilset_extra (m_parserData ,   m_parserData->scanner);
}

OSiLReader::~OSiLReader(){
	if(m_osinstance != NULL) delete m_osinstance;
	m_osinstance = NULL;
	// now delete the flex scanner that was initialized
	osillex_destroy(m_parserData->scanner );
	if( m_parserData != NULL) delete m_parserData;
	m_parserData = NULL;
} 

OSInstance* OSiLReader::readOSiL(const std::string& posil) throw(ErrorClass){   
	try{
		const char *ch = posil.c_str();
		yygetOSInstance( ch, m_osinstance, m_parserData);
		return m_osinstance;
	}
		catch(const ErrorClass& eclass){
		throw ErrorClass( eclass.errormsg);
	}
}//end readOSiL




