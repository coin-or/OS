/* $Id$ */
/** @file OSoLReader.cpp
 *
 *
 * @author   Horand Gassmann, Jun Ma, Kipp Martin
 *
 * \remarks
 * Copyright (C) 2005-2011, Horand Gassmann, Jun Ma, Kipp Martin,
 * Northwestern University, Dalhousie University and the University of Chicago.
 * All Rights Reserved.
 * This software is licensed under the Eclipse Public License.
 * Please see the accompanying LICENSE file in root directory for terms.
 *
 */

//#define OSOL_READER_DEBUG
#ifdef OSOL_READER_DEBUG
#include <cstdio>
#endif

#include "OSoLReader.h"


//bison function
void yygetOSOption(const char *osil, OSOption* osoption, OSoLParserData *parserData, OSgLParserData *osglData) throw(ErrorClass);
//lex functions
int osollex_init(void** ptr_yy_globals);
int osollex_destroy (void* scanner );
void osolset_extra (OSoLParserData* parserData , void* yyscanner );


OSoLReader::OSoLReader( )
{
#ifdef OSOL_READER_DEBUG
    std::cout << "new OSOption()" << std::endl;
#endif
    m_osoption = new OSOption();
#ifdef OSOL_READER_DEBUG
    std::cout << "new OSoLParserData()" << std::endl;
#endif
    m_parserData = new OSoLParserData();
#ifdef OSOL_READER_DEBUG
    std::cout << "new OSgLParserData()" << std::endl;
#endif
    m_osglData = new OSgLParserData();
    // initialize the lexer and set yyextra
#ifdef OSOL_READER_DEBUG
    std::cout << "initialize the lexer" << std::endl;
#endif
    osollex_init( &(m_parserData->scanner) );
    osolset_extra (m_parserData ,   m_parserData->scanner);
#ifdef OSOL_READER_DEBUG
    std::cout << "done" << std::endl;
#endif
}

OSoLReader::~OSoLReader()
{
    if(m_osoption != NULL) delete m_osoption;
    m_osoption = NULL;
    // now delete the flex scanner that was initialized
    osollex_destroy(m_parserData->scanner );
    if( m_parserData != NULL) delete m_parserData;
    m_parserData = NULL;
    if( m_osglData != NULL) delete m_osglData;
    m_osglData = NULL;
}

OSOption* OSoLReader::readOSoL(const std::string& posol) throw(ErrorClass)
{
    if (posol.length() > 0)
    {
        const char *ch = posol.c_str();
        yygetOSOption( ch, m_osoption, m_parserData, m_osglData);
    }
    return m_osoption;
}//end readOSoL




