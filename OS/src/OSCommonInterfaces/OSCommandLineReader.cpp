/* $Id: OSCommandLineReader.cpp 4263 2011-09-09 20:19:26Z Gassmann $ */
/** @file OSCommandLineReader.cpp
 *
 *
 * @author  Horand Gassmann, Jun Ma, Kipp Martin,
 *
 * \remarks
 * Copyright (C) 2011, Horand Gassmann, Jun Ma, Kipp Martin,
 * Northwestern University, and the University of Chicago.
 * All Rights Reserved.
 * This software is licensed under the Eclipse Public License.
 * Please see the accompanying LICENSE file in root directory for terms.
 *
 */

#include "OSCommandLineReader.h"
#include "OSCommandLine.h"
#include "OSFileUtil.h"
#include "OSConfig.h"
#include "OSOutput.h"



typedef struct yy_buffer_state *YY_BUFFER_STATE;
YY_BUFFER_STATE osss_scan_string(const char* osss, void* scanner);
void setyyextra(OSCommandLine *oscommandline, void* scanner);
int ossslex(void* scanner);
int ossslex_init(void** ptr);
int ossslex_destroy(void* scanner);


OSCommandLineReader::OSCommandLineReader( )
{
		m_oscommandline = new OSCommandLine();
}

OSCommandLine* OSCommandLineReader::readCommandLine(const std::string& osss) throw(ErrorClass)
{
	void* scanner;
	bool scannerActive;
    std::ostringstream outStr;

	// scan the command line once
        scannerActive = true;
        ossslex_init(&scanner);
        setyyextra(m_oscommandline, scanner);
        osss_scan_string(osss.c_str(), scanner);
#ifndef NDEBUG
        osoutput->OSPrint(ENUM_OUTPUT_AREA_Command_line_parser, ENUM_OUTPUT_LEVEL_trace, "call ossslex");
#endif
        ossslex(scanner);
        ossslex_destroy(scanner);
        scannerActive = false;
#ifndef NDEBUG
        osoutput->OSPrint(ENUM_OUTPUT_AREA_Command_line_parser, ENUM_OUTPUT_LEVEL_trace, "done with call to ossslex");
#endif

        // if there is a config file, get those options
        if (m_oscommandline->configFile != "")
        {
		    FileUtil *fileUtil = NULL;
            scannerActive = true;
            ossslex_init(&scanner);
#ifndef NDEBUG
            outStr << "configFileName = " << configFileName << endl;
            osoutput->OSPrint(ENUM_OUTPUT_AREA_Command_line_parser, ENUM_OUTPUT_LEVEL_debug, outStr.str());
#endif
            std::string configFileOptions = fileUtil->getFileAsString(
                             m_oscommandline->configFile.c_str());
#ifndef NDEBUG
            osoutput->OSPrint(ENUM_OUTPUT_AREA_Command_line_parser, ENUM_OUTPUT_LEVEL_trace, "Call Text Extra");
#endif
            setyyextra(m_oscommandline, scanner);
#ifndef NDEBUG
            osoutput->OSPrint(ENUM_OUTPUT_AREA_Command_line_parser, ENUM_OUTPUT_LEVEL_trace, "Done with call Text Extra");
#endif
            osss_scan_string(configFileOptions.c_str(), scanner);
            ossslex(scanner);
            ossslex_destroy(scanner);
            
        // now read the command line a second time
            ossslex_init(&scanner);
            setyyextra(m_oscommandline, scanner);
            osss_scan_string(osss.c_str(), scanner);
#ifndef NDEBUG
            osoutput->OSPrint(ENUM_OUTPUT_AREA_Command_line_parser, ENUM_OUTPUT_LEVEL_trace, "call ossslex");
#endif
            ossslex(scanner);
            ossslex_destroy(scanner);
            scannerActive = false;           
#ifndef NDEBUG
            osoutput->OSPrint(ENUM_OUTPUT_AREA_Command_line_parser, ENUM_OUTPUT_LEVEL_trace, "done with call to ossslex");

#endif
        }


        return m_oscommandline;
}

OSCommandLineReader::~OSCommandLineReader()
{
    if(m_oscommandline != NULL) delete m_oscommandline;
    m_oscommandline = NULL;
}

