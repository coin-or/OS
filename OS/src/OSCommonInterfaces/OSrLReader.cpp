/* $Id$ */
/** @file OSrLReader.cpp
 *
 *
 * @author  Horand Gassmann, Jun Ma, Kipp Martin,
 *
 * \remarks
 * Copyright (C) 2005-2011, Horand Gassmann, Jun Ma, Kipp Martin,
 * Dalhousie University, Northwestern University, and the University of Chicago.
 * All Rights Reserved.
 * This software is licensed under the Eclipse Public License.
 * Please see the accompanying LICENSE file in root directory for terms.
 *
 */
//#define OSRLREADER_DEBUG

#include "OSrLReader.h"




void yygetOSResult( const char *ch, OSResult* m_osresult, OSrLParserData *m_parserData, OSgLParserData *osglData) throw(ErrorClass);
int osrllex_init(void** ptr_yy_globals);
int osrllex_destroy (void* scanner );
void osrlset_extra (OSrLParserData* parserData , void* yyscanner );


OSrLReader::OSrLReader( )
{
#ifdef OSRLREADER_DEBUG
    std::cout << "new OSrLParserData()" << std::endl;
#endif
    m_parserData = new OSrLParserData();
#ifdef OSRLREADER_DEBUG
    std::cout << "new OSgLParserData()" << std::endl;
#endif
    m_osglData = new OSgLParserData();
#ifdef OSRLREADER_DEBUG
    std::cout << "new OSResult()" << std::endl;
#endif
    m_osresult = new OSResult();
    // initialize the lexer and set yyextra
#ifdef OSRLREADER_DEBUG
    std::cout << "initialize the lexer" << std::endl;
#endif
    osrllex_init( &(m_parserData->scanner) );
    osrlset_extra (m_parserData ,   m_parserData->scanner);
#ifdef OSRLREADER_DEBUG
    std::cout << "done" << std::endl;
#endif
}

OSrLReader::~OSrLReader()
{
    // delete the osresult object
#ifdef OSRLREADER_DEBUG
    std::cout << "delete m_osresult" << std::endl;
#endif
    if(m_osresult != NULL) delete m_osresult;
    m_osresult = NULL;

    // now delete the scanner that was initialized
#ifdef OSRLREADER_DEBUG
    std::cout << "delete scanner" << std::endl;
#endif
    osrllex_destroy(m_parserData->scanner );

    // finally delete parser data
#ifdef OSRLREADER_DEBUG
    std::cout << "delete parser data" << std::endl;
#endif
    if( m_parserData != NULL) delete m_parserData;
    m_parserData = NULL;

#ifdef OSRLREADER_DEBUG
    std::cout << "delete osglData" << std::endl;
#endif
    if( m_osglData != NULL) delete m_osglData;
    m_osglData = NULL;

#ifdef OSRLREADER_DEBUG
    std::cout << "success!" << std::endl;
#endif
}

OSResult* OSrLReader::readOSrL(const std::string& posrl) throw(ErrorClass)
{
    try
    {
        const char *ch = posrl.c_str();
        yygetOSResult( ch, m_osresult, m_parserData, m_osglData);
        return m_osresult;
    }
    catch(const ErrorClass& eclass)
    {
        throw ErrorClass( eclass.errormsg);
    }
}
