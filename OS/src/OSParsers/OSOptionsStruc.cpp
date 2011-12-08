/* $Id: OSCommandLine.cpp 4340 2011-10-15 20:08:33Z Gassmann $ */
/** @file OSCommandLine.cpp
 *
 * @author  Horand Gassmann, Jun Ma, Kipp Martin,
 *
 * \remarks
 * Copyright (C) 2005-2011, Horand Gassmann, Jun Ma, Kipp Martin,
 * Northwestern University, Dalhousie University and the University of Chicago.
 * All Rights Reserved.
 * This software is licensed under the Eclipse Public License.
 * Please see the accompanying LICENSE file in root directory for terms.
 *
 */



#include "OSOptionsStruc.h"

#include "OSCoinSolver.h"
#include "OSResult.h"
#include "OSiLReader.h"
#include "OSiLWriter.h"
#include "OSoLReader.h"
#include "OSrLReader.h"
#include "OSrLWriter.h"
#include "OSInstance.h"
#include "OSOption.h"
#include "OSoLWriter.h"
#include "OSFileUtil.h"
#include "OSConfig.h"
#include "OSDefaultSolver.h"
//#include "OSWSUtil.h"
//#include "OSSolverAgent.h"
//#include "OShL.h"
#include "OSErrorClass.h"
//#include "OSmps2osil.h"
//#include "OSBase64.h"
//#include "OSRunSolver.h"

#include <stdio.h>
#include <string>
#include <map>


using std::cout;
using std::endl;
using std::ostringstream;
using std::string;
using std::map;

#define MAXCHARS 5000


typedef struct yy_buffer_state *YY_BUFFER_STATE;
YY_BUFFER_STATE osss_scan_string(const char* osss, void* scanner);
//void osssset_extra (YY_EXTRA_TYPE user_defined ,yyscan_t yyscanner );
void setyyextra(osOptionsStruc *osoptions, void* scanner);
int ossslex(void* scanner);
int ossslex_init(void** ptr);
int ossslex_destroy(void* scanner);

osOptionsStruc::osOptionsStruc():
    configFile(""),
    osilFile(""),
    osil(""),
    osolFile(""),
    osol(""),
    osrlFile(""),
    osrl(""),
    insListFile(""),
    insList(""),
    serviceLocation(""),
    serviceMethod(""),
    osplInputFile(""),
    osplInput(""),
    osplOutputFile(""),
    osplOutput(""),
    mpsFile(""),
    mps(""),
    nlFile(""),
    nl(""),
    datFile(""),
    dat(""),
    gamsControlFile(""),
    solverName(""),
    browser(""),
    jobID(""),
    invokeHelp(false),
    writeVersion(false),
    printModel(false),
    printRowNumberAsString(""),
    quit(false),
    exit(false)
{
}//end regular osOptionsStruc constructor

osOptionsStruc::osOptionsStruc(char *osss):
    configFile(""),
    osilFile(""),
    osil(""),
    osolFile(""),
    osol(""),
    osrlFile(""),
    osrl(""),
    insListFile(""),
    insList(""),
    serviceLocation(""),
    serviceMethod(""),
    osplInputFile(""),
    osplInput(""),
    osplOutputFile(""),
    osplOutput(""),
    mpsFile(""),
    mps(""),
    nlFile(""),
    nl(""),
    datFile(""),
    dat(""),
    gamsControlFile(""),
    solverName(""),
    browser(""),
    jobID(""),
    invokeHelp(false),
    writeVersion(false),
    printModel(false),
    printRowNumberAsString(""),
    quit(false),
    exit(false)
{
    void* scanner;
    bool scannerActive = false;
    FileUtil *fileUtil = NULL;
    FileUtil *inputFileUtil = NULL;

    const char *space = " ";
    std::string configFileName = "";
    int i;

    try{
#ifdef DEBUG_CL_INTERFACE
        cout << "Input String = " << osss << endl;
#endif
        scannerActive = true;
        ossslex_init(&scanner);
        //std::cout << "Call Text Extra" << std::endl;
        setyyextra(this, scanner);
        //std::cout << "Call scan string " << std::endl;
        osss_scan_string(osss, scanner);
#ifdef DEBUG_CL_INTERFACE
        std::cout << "call ossslex" << std::endl;
#endif
        ossslex(scanner);
        ossslex_destroy(scanner);
        scannerActive = false;
#ifdef DEBUG_CL_INTERFACE
        std::cout << "done with call to ossslex" << std::endl;
#endif

        // if there is a config file, get those options, then read the command line a second time
        if (this->configFile != "")
        {
            scannerActive = true;
            ossslex_init(&scanner);
            configFileName = this->configFile;
#ifdef DEBUG_CL_INTERFACE
            cout << "configFileName = " << configFileName << endl;
#endif
            std::string configFileOptions = fileUtil->getFileAsString(
                                              configFileName.c_str());
#ifdef DEBUG_CL_INTERFACE
            std::cout << "Call Text Extra" << std::endl;
#endif
            setyyextra(this, scanner);
#ifdef DEBUG_CL_INTERFACE
            std::cout << "Done with call Text Extra" << std::endl;
#endif
            osss_scan_string(configFileOptions.c_str(), scanner);
            ossslex(scanner);
            ossslex_destroy(scanner);
            scannerActive = false;
            
            //Read the command line a second time to override information in the config file     
            
            scannerActive = true;
            ossslex_init(&scanner);
            //std::cout << "Call Text Extra" << std::endl;
            setyyextra(this, scanner);
            //std::cout << "Call scan string " << std::endl;
            osss_scan_string(osss, scanner);
    #ifdef DEBUG_CL_INTERFACE
            std::cout << "call ossslex" << std::endl;
    #endif
            ossslex(scanner);
            ossslex_destroy(scanner);
            scannerActive = false;           
            
            
        }
    }
    catch (const ErrorClass& eclass)
    {
        OSResult *osresult = NULL;
        OSrLWriter *osrlwriter = NULL;
        osrlwriter = new OSrLWriter();
        osresult = new OSResult();
        osresult->setGeneralMessage(eclass.errormsg);
        osresult->setGeneralStatusType("error");
        std::string osrl = osrlwriter->writeOSrL(osresult);
        if (this->osrlFile != "")
        {
            fileUtil->writeFileFromString(this->osrlFile, osrl);
            if (this->browser != "")
            {
                std::string str = this->browser + "  "
                                  + this->osrlFile;
                const char *ch = &str[0];
                std::system(ch);
            }
        }
        else
        {
            std::cout << osrl << std::endl;
        }
        //catch garbage collection
        delete osresult;
        osresult = NULL;
        delete osrlwriter;
        osrlwriter = NULL;

        if (scannerActive == true)
            ossslex_destroy(scanner);
        delete fileUtil;
        throw ErrorClass("Error parsing command line");
    }
}//end alternate osOptionsStruc constructor

osOptionsStruc::~osOptionsStruc()
{
}//end osOptionsStruc destructor
