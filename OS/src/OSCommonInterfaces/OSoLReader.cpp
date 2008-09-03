/** @file OSoLReader.cpp
 * 
 *
 * @author  Robert Fourer, Horand Gassmann, Jun Ma, Kipp Martin, 
 * @version 1.0, 17/07/2008
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

#include "OSoLReader.h"


//bison function
void yygetOSOption(const char *osil, OSOption* osoption, OSoLParserData *parserData) throw(ErrorClass);
//lex functions
int osollex_init(void** ptr_yy_globals);
int osollex_destroy (void* scanner );
void osolset_extra (OSoLParserData* parserData , void* yyscanner );


OSoLReader::OSoLReader( ) {
	m_osoption = new OSOption();
	m_parserData = new OSoLParserData();
	// initialize the lexer and set yyextra
	osollex_init( &(m_parserData->scanner) );
	osolset_extra (m_parserData ,   m_parserData->scanner);
}

OSoLReader::~OSoLReader(){
	if(m_osoption != NULL) delete m_osoption;
	m_osoption = NULL;
	// now delete the flex scanner that was initialized
	osollex_destroy(m_parserData->scanner );
	if( m_parserData != NULL) delete m_parserData;
	m_parserData = NULL;
} 

OSOption* OSoLReader::readOSoL(const std::string& posol) throw(ErrorClass){   
	try{
		const char *ch = posol.c_str();
		yygetOSOption( ch, m_osoption, m_parserData);
		return m_osoption;
	}
		catch(const ErrorClass& eclass){
		throw ErrorClass( eclass.errormsg);
	}
}//end readOSoL




