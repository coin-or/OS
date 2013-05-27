/* $Id: OSOutput.cpp 3172 2012-11-12 04:59:24Z Gassmann $ */
/** @file OSOutput.spp
 *
 *
 * @author  Horand Gassmann, Jun Ma, Kipp Martin
 *
 * \remarks
 * Copyright (C) 2012, Horand Gassmann, Jun Ma,  Kipp Martin,
 * Northwestern University, and the University of Chicago.
 * All Rights Reserved.
 * This software is licensed under the Eclipse Public License.
 * Please see the accompanying LICENSE file in root directory for terms.
 *
 */

#include "OSConfig.h"
#include "OSErrorClass.h"
#include "OSParameters.h"
#include "OSOutput.h"

#include <string>
#include <vector>
#include <iostream>
#include <sstream>

#ifdef HAVE_CSTDIO
# include <cstdio>
#else
# ifdef HAVE_STDIO_H
#  include <stdio.h>
# else
#  error "don't have header file for stdio"
# endif
#endif


// define the osoutput instance that takes care of all output (see ticket 14)
// It is declared here as a global variable so as to minimize the changes to the API
const OSSmartPtr</*const*/ OSOutput> osoutput = new OSOutput();


OSOutputChannel::OSOutputChannel(std::string name)
{
    this->name = name;
    for (int i=0; i<ENUM_OUTPUT_AREA_NUMBER_OF_AREAS; i++)
        this->printLevel[i] = DEFAULT_OUTPUT_LEVEL; 
    if (this->name != "stderr" && this->name != "stdout")
    {
        this->file = fopen (this->name.c_str(), "w+" );
        std::string temp = ("Could not open file " + this->name);
        if (this->file == NULL) throw ErrorClass(temp);
//        if (this->file == NULL) throw ErrorClass("Could not open file " + this->name);
    }
}

OSOutputChannel::~OSOutputChannel()
{
}

std::string OSOutputChannel::Name()
{
    return name;
}

bool OSOutputChannel::setPrintLevel(ENUM_OUTPUT_AREA area, ENUM_OUTPUT_LEVEL level)
{
#ifdef NDEBUG
    if (level > ENUM_OUTPUT_LEVEL_debug)
        throw ErrorClass("Encountered print level not supported in production code.\n Recompile with debug enabled."); 
#endif
    printLevel[area] = level;
    return true;
}

bool OSOutputChannel::setAllPrintLevels(ENUM_OUTPUT_LEVEL level)
{
#ifdef NDEBUG
    if (level > ENUM_OUTPUT_LEVEL_debug)
        throw ErrorClass("Encountered print level not supported in production code.\n Recompile with debug enabled."); 
#endif
    for (int i=0; i < ENUM_OUTPUT_AREA_NUMBER_OF_AREAS; i++)
        printLevel[i] = level;
    return true;

}

    /** Set different print levels for all areas 
     *  @param level holds an array of valid print levels
     *  @param dim holds the number of entries in the array level
     *  @return whether the set() was successful
     */
bool OSOutputChannel::setAllPrintLevels(ENUM_OUTPUT_LEVEL* level, int dim)
{
    if (dim < 0)
        throw ErrorClass("Array of output levels must have nonnegative size."); 
    int n = (dim < ENUM_OUTPUT_AREA_NUMBER_OF_AREAS ? dim : ENUM_OUTPUT_AREA_NUMBER_OF_AREAS);
    for (int i=0; i < n; i++)
    {
#ifdef NDEBUG
        if (level[i] > ENUM_OUTPUT_LEVEL_debug)
            throw ErrorClass("Encountered print level not supported in production code.\n Recompile with debug enabled."); 
#endif
        printLevel[i] = level[i];
    }
    for (int i=n+1; i < ENUM_OUTPUT_AREA_NUMBER_OF_AREAS; i++)
        printLevel[i] = ENUM_OUTPUT_LEVEL_error;
    return true;
 }

bool OSOutputChannel::isAccepted(ENUM_OUTPUT_AREA area, ENUM_OUTPUT_LEVEL level)
{
    return (level <= printLevel[area]);
}

void OSOutputChannel::OSPrintf(ENUM_OUTPUT_AREA area, ENUM_OUTPUT_LEVEL level, std::string str)
{
    if (isAccepted(area,level))
    {
        if (this->name == "stderr")
                fprintf(stderr, "%s\n", str.c_str());
        else if (this->name == "stdout")
                printf("%s\n", str.c_str());
        else
            if (this->file != NULL)
                fprintf(file, "%s\n", str.c_str());
            else
                throw ErrorClass("File not open for output");
        return;
    }
}

void OSOutputChannel::flushBuffer()
{
    if (file != NULL) 
        fflush(file);
    else
        throw ErrorClass("File not open for output");
    return;
}

bool OSOutputChannel::Open()
{
    if (name == "stdout")
    {
        file = stdout;
        return true;
    }
    if (name == "stderr")
    {
        file = stderr;
        return true;
    }
    if (file != NULL)
        throw ErrorClass ("File previously opened.");
    file = fopen(name.c_str(), "w");
    if (file != NULL) 
        return true;
    return false;
}


OSOutput::OSOutput()
{
    std::string temp = "stdout";
    nOfOutputs = 1;
    outputChannel = new OSOutputChannel*[1];
    outputChannel[0] = new OSOutputChannel(temp);
}

OSOutput::~OSOutput()
{
    for (int i=0; i < nOfOutputs; i++)
        delete outputChannel[i];
    delete  [] outputChannel;
    outputChannel = NULL;
    nOfOutputs = 0;
}
    
bool OSOutput::OSPrint(ENUM_OUTPUT_AREA area, ENUM_OUTPUT_LEVEL level, std::string outStr)
{
    for (int i=0; i < nOfOutputs; i++)
    {
        if (outputChannel[i]->isAccepted(area,level))
            outputChannel[i]->OSPrintf(area, level, outStr);
    }
    return true;
}

void OSOutput::FlushAllBuffers()
{
    for (int i=0; i < nOfOutputs; i++)
        outputChannel[i]->flushBuffer();
}

bool OSOutput::SetPrintLevel(std::string name, ENUM_OUTPUT_LEVEL* level, int dim)
{
    int k = FindChannel(name);
    if (k < 0)
        throw ErrorClass("Device was not defined before");
    for (int i=1; i<dim; i++)
    {
        if (level[i] < 0)
            throw ErrorClass("printLevel must be nonnegative");
        else if (level[i] >= ENUM_OUTPUT_LEVEL_NUMBER_OF_LEVELS)
            throw ErrorClass("illegal printLevel specified");
    }
    return (outputChannel[k]->setAllPrintLevels(level, dim));
}

bool OSOutput::SetPrintLevel(std::string name, ENUM_OUTPUT_LEVEL level)
{
    int aLevel, area;
    int k = FindChannel(name);
    if (k < 0)
        throw ErrorClass("Device was not defined before");
    if (level < 0)
        throw ErrorClass("printLevel must be nonnegative");
    if (level < 100)
        if (level >= ENUM_OUTPUT_LEVEL_NUMBER_OF_LEVELS)
            throw ErrorClass("illegal printLevel specified");
        else
            return (outputChannel[k]->setAllPrintLevels((ENUM_OUTPUT_LEVEL)level));
    else
    {
        aLevel = level % 100;
        area =  (level / 100) - 1;
        if (aLevel >= ENUM_OUTPUT_LEVEL_NUMBER_OF_LEVELS || area >= ENUM_OUTPUT_AREA_NUMBER_OF_AREAS)
            throw ErrorClass("illegal printLevel specified");
        else
            return (outputChannel[k]->setPrintLevel((ENUM_OUTPUT_AREA)area,level));
    }
}

int OSOutput::AddChannel(std::string name)
{
    if (FindChannel(name) >= 0)
    {
        if (name == "stdout") 
            return 0;
        else
            return 1;
    }

    bool noMem = false;

    try
    {
        int ndev;
        int i;

        if (this->outputChannel == NULL)
            ndev = 0;
        else
            ndev = this->nOfOutputs;

        noMem = true;
        OSOutputChannel** temp = new OSOutputChannel*[ndev+1];  //Allocate the new pointers
        noMem = false;
        for (i = 0; i < ndev; i++)
            temp[i] = this->outputChannel[i];  //copy the pointers

        delete[] this->outputChannel; //delete old pointers

//	add in the new element
        noMem = true;
        temp[ndev] = new OSOutputChannel(name);
        noMem = false;

        this->outputChannel = temp;   //hook the new pointers into the data structure
        this->nOfOutputs = ++ndev;
        return 0;
    }
    catch(const ErrorClass& eclass)
    {
        if (noMem)
            return 2;
        return 3;
    }
}// AddChannel

bool OSOutput::DeleteChannel(std::string name)
{
    int k = FindChannel(name);
    if (k < 0)
        return false;
    delete this->outputChannel[k];

    int ndev = this->nOfOutputs;
    int i;

    if (ndev == 1)
    {
        delete[] this->outputChannel;
        this->outputChannel = NULL; 
    }
    else 
    {
        OSOutputChannel** temp = new OSOutputChannel*[ndev-1];  //Allocate the new pointers
        for (i = 0; i < k; i++)
            temp[i] = this->outputChannel[i];  //copy the pointers
        for (i = k+1; i < ndev; i++)
            temp[i] = this->outputChannel[i+1];  //skip the deleted channel

        delete[] this->outputChannel; //delete old pointers

        this->outputChannel = temp;   //hook the new pointers into the data structure
    }

    this->nOfOutputs = ++ndev;
    return true;
}// DeleteChannel

int OSOutput::FindChannel(std::string name)
{
    for (int i=0; i < nOfOutputs; i++)
        if (outputChannel[i]->Name() == name) return i;
    return -1;
}

