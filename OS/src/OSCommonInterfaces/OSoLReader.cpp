/* $Id$ */
/** @file OSoLReader.cpp
 *
 *
 * @author   Horand Gassmann, Jun Ma, Kipp Martin
 *
 * \remarks
 * Copyright (C) 2005-2011, Horand Gassmann, Jun Ma, Kipp Martin,
 * Northwestern University, and the University of Chicago.
 * All Rights Reserved.
 * This software is licensed under the Eclipse Public License.
 * Please see the accompanying LICENSE file in root directory for terms.
 *
 */


#ifndef NDEBUG
#include <cstdio>
#endif

#include "OSoLReader.h"
#include "OSOutput.h"


//bison function
void yygetOSOption(const char *osil, OSOption* osoption, OSoLParserData *parserData, OSgLParserData *osglData) throw(ErrorClass);
//lex functions
int osollex_init(void** ptr_yy_globals);
int osollex_destroy (void* scanner );
void osolset_extra (OSoLParserData* parserData , void* yyscanner );


OSoLReader::OSoLReader( )
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSoL_parser, ENUM_OUTPUT_LEVEL_trace, "new OSOption()");
#endif
    m_osoption = new OSOption();
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSoL_parser, ENUM_OUTPUT_LEVEL_trace, "new OSoLParserData()");
#endif
    m_parserData = new OSoLParserData();
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSoL_parser, ENUM_OUTPUT_LEVEL_trace, "new OSgLParserData()");
#endif
    m_osglData = new OSgLParserData();
    // initialize the lexer and set yyextra
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSoL_parser, ENUM_OUTPUT_LEVEL_trace, "initialize the lexer");
#endif
    osollex_init( &(m_parserData->scanner) );
    osolset_extra (m_parserData ,   m_parserData->scanner);
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSoL_parser, ENUM_OUTPUT_LEVEL_trace, "done");
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




