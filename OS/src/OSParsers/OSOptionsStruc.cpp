/* $Id: OSOptionsStruc.cpp 4210 2011-06-28 09:44:54Z Gassmann $ */
/** @file OSOptionsStruc.cpp
 * 
 * @author  Horand Gassmann, Jun Ma, Kipp Martin
 *
 * \remarks
 * Copyright (C) 2012, Horand Gassmann, Jun Ma, Kipp Martin,
 * and the University of Chicago.
 * All Rights Reserved.
 * This software is licensed under the Eclipse Public License. 
 * Please see the accompanying LICENSE file in root directory for terms.
 * 
 */

/**  
 *
 * <p><code>OSOptionsStruc</code> is is a data structure to hold OS
 * command line options <p>
 *
 */

#include "OSOptionsStruc.h"
#include "OSOutput.h"
#include <string>

osOptionsStruc::osOptionsStruc()
{
    resetOptions();
}

void osOptionsStruc::resetOptions()
{
    this->configFile = "";
    this->osilFile = "";
    this->osil = "";
    this->osolFile = "";
    this->osol = "";
    this->osrlFile = "";
    this->osrl = "";
    this->insListFile = "";
    this->insList = "";
    this->serviceLocation = "";
    this->serviceMethod = "";
    this->osplInputFile = "";
    this->osplInput = "";
    this->osplOutputFile = "";
    this->osplOutput = "";
    this->mpsFile = "";
    this->mps = "";
    this->nlFile = "";
    this->nl = "";
    this->datFile = "";
    this->dat = "";
    this->gamsControlFile = "";
    this->solverName = "";
    this->browser = "";
    this->printLevel = DEFAULT_OUTPUT_LEVEL;
    this->logFile = "";
    this->filePrintLevel = DEFAULT_OUTPUT_LEVEL;
    this->jobID = "";
    this->invokeHelp = false;
    this->writeVersion = false;
    this->printModel = false;
    this->printRowNumberAsString = "";
    this->quit = false;
}

