/* $Id$ */
/** @file OSiLReader.cpp
 *
 *
 * @author  Robert Fourer, Horand Gassmann, Jun Ma, Kipp Martin,
 *
 * \remarks
 * Copyright (C) 2005-2011, Robert Fourer, Horand Gassmann, Jun Ma, Kipp Martin,
 * Northwestern University, and the University of Chicago.
 * All Rights Reserved.
 * This software is licensed under the Eclipse Public License.
 * Please see the accompanying LICENSE file in root directory for terms.
 *
 */

#include "OSiLReader.h"


//bison function
void yygetOSInstance(const char *osil, OSInstance* osinstance, OSiLParserData *parserData, OSgLParserData *osglData, OSnLParserData *osnlData) throw(ErrorClass);
//lex functions
int osillex_init(void** ptr_yy_globals);
int osillex_destroy (void* scanner );
void osilset_extra (OSiLParserData* parserData , void* yyscanner );


OSiLReader::OSiLReader( )
{
    m_osinstance = new OSInstance();
    m_parserData = new OSiLParserData();
    m_osglData = new OSgLParserData();
    m_osnlData = new OSnLParserData();

    // initialize the lexer and set yyextra
    osillex_init( &(m_parserData->scanner) );
    osilset_extra (m_parserData ,   m_parserData->scanner);
}

OSiLReader::~OSiLReader()
{
    if(m_osinstance != NULL) delete m_osinstance;
    m_osinstance = NULL;
    // now delete the flex scanner that was initialized
    osillex_destroy(m_parserData->scanner );
    if( m_parserData != NULL) delete m_parserData;
    m_parserData = NULL;
    if( m_osglData != NULL) delete m_osglData;
    m_osglData = NULL;
    if( m_osnlData != NULL) delete m_osnlData;
    m_osnlData = NULL;
}

OSInstance* OSiLReader::readOSiL(const std::string& posil)
#if __cplusplus < 201100  
    throw(ErrorClass)
#endif
{
    try
    {
        const char *ch = posil.c_str();
        yygetOSInstance( ch, m_osinstance, m_parserData, m_osglData, m_osnlData);
        return m_osinstance;
    }
    catch(const ErrorClass& eclass)
    {
        throw ErrorClass( eclass.errormsg);
    }
}//end readOSiL




