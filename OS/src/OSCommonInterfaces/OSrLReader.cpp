/* $Id$ */
/** @file OSrLReader.cpp
 *
 *
 * @author  Horand Gassmann, Jun Ma, Kipp Martin,
 *
 * \remarks
 * Copyright (C) 2005-2011, Horand Gassmann, Jun Ma, Kipp Martin,
 * Northwestern University, and the University of Chicago.
 * All Rights Reserved.
 * This software is licensed under the Eclipse Public License.
 * Please see the accompanying LICENSE file in root directory for terms.
 *
 */


#include "OSrLReader.h"
#include "OSOutput.h"




void yygetOSResult( const char *ch, OSResult* m_osresult, OSrLParserData *m_parserData, OSgLParserData *osglData) throw(ErrorClass);
int osrllex_init(void** ptr_yy_globals);
int osrllex_destroy (void* scanner );
void osrlset_extra (OSrLParserData* parserData , void* yyscanner );


OSrLReader::OSrLReader( )
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSrL_parser, ENUM_OUTPUT_LEVEL_trace, "new OSrLParserData()");
#endif
    m_parserData = new OSrLParserData();
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSrL_parser, ENUM_OUTPUT_LEVEL_trace, "new OSgLParserData()");
#endif
    m_osglData = new OSgLParserData();
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSrL_parser, ENUM_OUTPUT_LEVEL_trace, "new OSResult()");
#endif
    m_osresult = new OSResult();
    // initialize the lexer and set yyextra
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSrL_parser, ENUM_OUTPUT_LEVEL_trace, "initialize the lexer");
#endif
    osrllex_init( &(m_parserData->scanner) );
    osrlset_extra (m_parserData ,   m_parserData->scanner);
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSrL_parser, ENUM_OUTPUT_LEVEL_trace, "done");
#endif
}

OSrLReader::~OSrLReader()
{
    // delete the osresult object
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSrL_parser, ENUM_OUTPUT_LEVEL_trace, "delete m_osresult");
#endif
    if(m_osresult != NULL) delete m_osresult;
    m_osresult = NULL;

    // now delete the scanner that was initialized
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSrL_parser, ENUM_OUTPUT_LEVEL_trace, "delete scanner");
#endif
    osrllex_destroy(m_parserData->scanner );

    // finally delete parser data
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSrL_parser, ENUM_OUTPUT_LEVEL_trace, "delete parser data");
#endif
    if( m_parserData != NULL) delete m_parserData;
    m_parserData = NULL;

#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSrL_parser, ENUM_OUTPUT_LEVEL_trace, "delete osglData");
#endif
    if( m_osglData != NULL) delete m_osglData;
    m_osglData = NULL;

#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSrL_parser, ENUM_OUTPUT_LEVEL_trace, "success!");
#endif
}

OSResult* OSrLReader::readOSrL(const std::string& posrl) throw(ErrorClass)
{
    if (posrl.length() > 0)
    {
        const char *ch = posrl.c_str();
        yygetOSResult( ch, m_osresult, m_parserData, m_osglData);
    }
    return m_osresult;
}
