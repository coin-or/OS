/* $Id: OSCommandLine.cpp 4340 2011-10-15 20:08:33Z Gassmann $ */
/** @file OSCommandLine.cpp
 *
 * @author  Horand Gassmann, Jun Ma, Kipp Martin,
 *
 * \remarks
 * Copyright (C) 2011-2012, Horand Gassmann, Jun Ma, Kipp Martin,
 * Northwestern University, and the University of Chicago.
 * All Rights Reserved.
 * This software is licensed under the Eclipse Public License.
 * Please see the accompanying LICENSE file in root directory for terms.
 *
 */

 /**
  *  This class implements methods that process command line options
  *  and holds the options in an internal data structure
  *
  */

#include "OSConfig.h"
#include "OSInstance.h"
#include "OSOption.h"
#include "OSOutput.h"
#include "OSCommandLine.h"
#include <stdio.h>

using std::string;

extern const SmartPtr</*const*/ OSOutput> osoutput;

void OSCommandLine::reset_options()
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_main, ENUM_OUTPUT_LEVEL_trace, "Reset command line options\n");
#endif
    if (osinstance != NULL) delete osinstance;
    osinstance = NULL;
    if (osoption != NULL) delete osoption;
    osoption = NULL;
    serviceLocation = "";
    serviceMethod = "";
    solverName = "";
    configFile = "";
    osilFile = "";
    osil = "";
    osilOutputFile = "";
    osolFile = "";
    osol = "";
    osolOutputFile = "";
    osrlFile = "";
    insListFile = "";
    insList = "";
    osplInputFile = "";
    osplInput = "";
    osplOutputFile = "";
    mpsFile = "";
    mps = "";
    nlFile = "";
    nl = "";
    datFile = "";
    dat = "";
    gamsControlFile = "";
    browser = "";
    printLevel = DEFAULT_OUTPUT_LEVEL;
    logFile = "";
    filePrintLevel = DEFAULT_OUTPUT_LEVEL;
    jobID = "";
    invokeHelp = false;
    listOptions = false;
    writeVersion = false;
    printModel = false;
    printRowNumberAsString = "";
    quit = false;
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_main, ENUM_OUTPUT_LEVEL_trace, "Done resetting command line options\n");
#endif
}// reset_options

OSCommandLine::OSCommandLine():
    osinstance(NULL),
    osoption(NULL)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_main, ENUM_OUTPUT_LEVEL_trace, "Inside command line constructor\n");
#endif
    reset_options();
}

OSCommandLine::~OSCommandLine()
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_main, ENUM_OUTPUT_LEVEL_trace, "Inside command line destructor\n");
#endif
    if (osinstance != NULL) delete osinstance;
    osinstance = NULL;
    if (osoption != NULL) delete osoption;
    osoption = NULL;
}

void OSCommandLine::convertSolverNameToLowerCase()
{
    unsigned int k;
    for (k = 0; k < solverName.length(); k++)
    {
        solverName[k] = (char)tolower(solverName[k]);
    }
}

void OSCommandLine::convertSolverNameToUpperCase()
{
    unsigned int k;
    for (k = 0; k < solverName.length(); k++)
    {
        solverName[k] = (char)toupper(solverName[k]);
    }
}

std::string OSCommandLine::list_options()
{
    std::ostringstream outStr;
    outStr     << "The following command line options and values have been read:"
               << std::endl;
    if (serviceLocation != "")
        outStr << "Service Location = "
               << serviceLocation
               << std::endl;
    if (serviceMethod != "")
        outStr << "Service Method = "
               << serviceMethod
               << std::endl;
    if ( solverName != "")
        outStr << "Selected Solver = "
               << solverName
               << std::endl;

    if (configFile != "")
        outStr << "Config file = "
               << configFile
               << std::endl;
    if (osilFile != "")
        outStr << "OSiL file = "
               << osilFile
               << std::endl;
    if (osilOutputFile != "")
        outStr << "OSiL output file = "
               << osilOutputFile
               << std::endl;
    if (osolFile != "")
        outStr << "OSoL file = "
               << osolFile
               << std::endl;
    if (osolOutputFile != "")
        outStr << "OSoL output file = "
               << osolOutputFile
               << std::endl;
    if (osrlFile != "")
        outStr << "OSrL file = "
               << osrlFile
               << std::endl;
    if (insListFile != "") 
        outStr << "Instruction List file = " 
               << insListFile 
               << std::endl;
    if (osplInputFile != "")
        outStr << "OSpL Input file = "
               << osplInputFile
               << std::endl;
    if (osplOutputFile != "")
        outStr << "OSpL Output file = "
               << osplOutputFile
               << std::endl;
    if (mpsFile != "")
        outStr << "MPS File Name = "
               << mpsFile
               << std::endl;
    if (nlFile != "")
        outStr << "NL File Name = "
               << nlFile
               << std::endl;
    if (datFile != "")
        outStr << "GAMS dat file = "
               << mpsFile
               << std::endl;
    if (gamsControlFile != "")
        outStr << "GAMS control file = "
               << gamsControlFile
               << std::endl;

    if (browser != "")
        outStr << "Result browser = "
               << browser
               << std::endl;
        outStr << "Print level for stdout: " 
               << printLevel
               << std::endl;

    if (logFile != "")
        outStr << "Secondary log to "
               << logFile 
               << std::endl;
        outStr << "Print level for " << logFile << ": " 
               << printLevel
               << std::endl;

    if (jobID != "")
        outStr << "job ID = "
               << jobID
               << std::endl;

    if (printModel)
        outStr << "Print model = true"
               << std::endl;
    if (printRowNumberAsString != "")
        outStr << "Print row "
               << printRowNumberAsString
               << std::endl;
    return outStr.str();
}// list_options
