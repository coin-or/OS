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
	osinstance = NULL;
	osoption = NULL;
    configFile = "";
    osilFile = "";
    osilOutputFile = "";
    osil = "";
    osolFile = "";
    osol = "";
    osrlFile = "";
    osrl = "";
    insListFile = "";
    insList = "";
    serviceLocation = "";
    serviceMethod = "";
    osplInputFile = "";
    osplInput = "";
    osplOutputFile = "";
    osplOutput = "";
    mpsFile = "";
    mps = "";
    nlFile = "";
    nl = "";
    datFile = "";
    dat = "";
	gamsControlFile = "";
    solverName = "";
    browser = "";
    jobID = "";
    invokeHelp = false;
    writeVersion = false;
    printModel = false;
    printRowNumberAsString = "";
    quit = false;
    exit = false;
}// reset_options

OSCommandLine::OSCommandLine()
{
#ifdef DEBUG_COMMANDLINE
	std::cout << "Inside command line constructor" << std::endl;
#endif
//	reset_options();
	osinstance = NULL;
	osoption = NULL;
    configFile = "";
    osilFile = "";
    osilOutputFile = "";
    osil = "";
    osolFile = "";
    osol = "";
    osrlFile = "";
    osrl = "";
    insListFile = "";
    insList = "";
    serviceLocation = "";
    serviceMethod = "";
    osplInputFile = "";
    osplInput = "";
    osplOutputFile = "";
    osplOutput = "";
    mpsFile = "";
    mps = "";
    nlFile = "";
    nl = "";
    datFile = "";
    dat = "";
	gamsControlFile = "";
    solverName = "";
    browser = "";
    jobID = "";
    invokeHelp = false;
    writeVersion = false;
    printModel = false;
    printRowNumberAsString = "";
    quit = false;
    exit = false;
}

OSCommandLine::~OSCommandLine()
{
#ifdef DEBUG_COMMANDLINE
	std::cout << "Inside command line destructor" << std::endl;
#endif
}
