/* $Id: OSCommandLineReader.cpp 4263 2011-09-09 20:19:26Z Gassmann $ */
/** @file OSCommandLineReader.cpp
 *
 *
 * @author  Horand Gassmann, Jun Ma, Kipp Martin,
 *
 * \remarks
 * Copyright (C) 2011, Horand Gassmann, Jun Ma, Kipp Martin,
 * Dalhousie University, Northwestern University, and the University of Chicago.
 * All Rights Reserved.
 * This software is licensed under the Eclipse Public License.
 * Please see the accompanying LICENSE file in root directory for terms.
 *
 */

#include "OSCommandLineReader.h"
#include "OSCommandLine.h"
#include "OSFileUtil.h"
#include "OSConfig.h"



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
	// scan the command line once
        scannerActive = true;
        ossslex_init(&scanner);
        setyyextra(m_oscommandline, scanner);
        osss_scan_string(osss.c_str(), scanner);
#ifdef DEBUG_CL_INTERFACE
        std::cout << "call ossslex" << std::endl;
#endif
        ossslex(scanner);
        ossslex_destroy(scanner);
        scannerActive = false;
#ifdef DEBUG_CL_INTERFACE
        std::cout << "done with call to ossslex" << std::endl;
#endif

        // if there is a config file, get those options
        if (m_oscommandline->configFile != "")
        {
		    FileUtil *fileUtil = NULL;
            scannerActive = true;
            ossslex_init(&scanner);
#ifdef DEBUG_CL_INTERFACE
            cout << "configFileName = " << configFileName << endl;
#endif
            std::string configFileOptions = fileUtil->getFileAsString(
                             m_oscommandline->configFile.c_str());
#ifdef DEBUG_CL_INTERFACE
            std::cout << "Call Text Extra" << std::endl;
#endif
            setyyextra(m_oscommandline, scanner);
#ifdef DEBUG_CL_INTERFACE
            std::cout << "Done with call Text Extra" << std::endl;
#endif
            osss_scan_string(configFileOptions.c_str(), scanner);
            ossslex(scanner);
            ossslex_destroy(scanner);
            
        // now read the command line a second time
            ossslex_init(&scanner);
            setyyextra(m_oscommandline, scanner);
            osss_scan_string(osss.c_str(), scanner);
    #ifdef DEBUG_CL_INTERFACE
            std::cout << "call ossslex" << std::endl;
    #endif
            ossslex(scanner);
            ossslex_destroy(scanner);
            scannerActive = false;           
        }

		//convert solver name to lower case so there is no ambiguity
		unsigned int k;
	    for (k = 0; k < m_oscommandline->solverName.length(); k++)
		{
			m_oscommandline->solverName[k] = (char)tolower(m_oscommandline->solverName[k]);
		}

        return m_oscommandline;
}

OSCommandLineReader::~OSCommandLineReader()
{
    if(m_oscommandline != NULL) delete m_oscommandline;
    m_oscommandline = NULL;
}

