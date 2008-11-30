/** @file OSoLReader.cpp
 * 
 *
 * @author   Horand Gassmann, Jun Ma, Kipp Martin, 
 * @version 1.0, 17/07/2008
 * @since   OS1.1
 *
 * \remarks
 * Copyright (C) 2005-2008, Robert Fourer, Horand Gassmann, Jun Ma, Kipp Martin,
 * Northwestern University, Dalhousie University and the University of Chicago.
 * All Rights Reserved.
 * This software is licensed under the Common Public License. 
 * Please see the accompanying LICENSE file in root directory for terms.
 * 
 */ 

#define OSOL_READER_DEBUG
#ifdef OSOL_READER_DEBUG
#include <cstdio>
#endif

#include "OSoLReader.h"


//bison function
void yygetOSOption(const char *osil, OSOption* osoption, OSoLParserData *parserData) throw(ErrorClass);
//lex functions
int osollex_init(void** ptr_yy_globals);
int osollex_destroy (void* scanner );
void osolset_extra (OSoLParserData* parserData , void* yyscanner );


OSoLReader::OSoLReader( ) {
#ifdef OSOL_READER_DEBUG
	printf("new OSOption\n");
#endif
	m_osoption = new OSOption();
#ifdef OSOL_READER_DEBUG
	printf("new OSoLParserData\n");
#endif
	m_parserData = new OSoLParserData();
	// initialize the lexer and set yyextra
#ifdef OSOL_READER_DEBUG
	printf("call osollex_init\n");
#endif

	osollex_init( &(m_parserData->scanner) );
#ifdef OSOL_READER_DEBUG
	printf("call osollex_extra\n");
#endif
	osolset_extra (m_parserData ,   m_parserData->scanner);
#ifdef OSOL_READER_DEBUG
	printf("success\n");
#endif
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




