/* $Id: OSCommandLine.cpp 4340 2011-10-15 20:08:33Z Gassmann $ */
/** @file OSCommandLine.cpp
 *
 * @author  Horand Gassmann, Jun Ma, Kipp Martin,
 *
 * \remarks
 * Copyright (C) 2011, Horand Gassmann, Jun Ma, Kipp Martin,
 * Northwestern University, Dalhousie University and the University of Chicago.
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
#include "OSCommandLine.h"
#include <stdio.h>

//#define DEBUG_COMMANDLINE


void OSCommandLine::reset_options()
{
	if (osinstance != NULL) delete osinstance;
	osinstance = NULL;
	if (osoption != NULL) delete osoption;
	osoption = NULL;
	osinstance = NULL;
	osoption = NULL;
    serviceLocation = "";
    serviceMethod = "";
    solverName = "";
    configFile = "";
    osilFile = "";
    osilOutputFile = "";
    osil = "";
    osolFile = "";
    osol = "";
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
	resultString = "";
    invokeHelp = false;
    listOptions = false;
    writeVersion = false;
    printModel = false;
    printRowNumberAsString = "";
    quit = false;
}// reset_options

OSCommandLine::OSCommandLine():
	osinstance(NULL),
	osoption(NULL)
{
#ifdef DEBUG_COMMANDLINE
	std::cout << "Inside command line constructor" << std::endl;
#endif
	reset_options();
}

OSCommandLine::~OSCommandLine()
{
#ifdef DEBUG_COMMANDLINE
	std::cout << "Inside command line destructor" << std::endl;
#endif
	if (osinstance != NULL) delete osinstance;
	osinstance = NULL;
	if (osoption != NULL) delete osoption;
	osoption = NULL;
}

void OSCommandLine::convertSolverNametoLowerCase()
{
    unsigned int k;
    for (k = 0; k < solverName.length(); k++)
    {
        solverName[k] = (char)tolower(solverName[k]);
    }
}

void OSCommandLine::convertSolverNametoUpperCase()
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
    outStr
            << "The following command line options and values have been read:"
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

	if (printModel)
        outStr << "Print model = true"
             << std::endl;
	if (printRowNumberAsString != "")
        outStr << "Print row "
             << printRowNumberAsString
             << std::endl;
	return outStr.str();
}// list_options
