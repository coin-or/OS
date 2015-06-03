/* $Id$ */
/** @file OSoLWriter.cpp
 *
 *
 * @author  Horand Gassmann, Jun Ma, Kipp Martin
 *
 * \remarks
 * Copyright (C) 2005-2011, Horand Gassmann, Jun Ma, Kipp Martin,
 * Northwestern University, and the University of Chicago.
 * All Rights Reserved.
 * This software is licensed under the Eclipse Public License.
 * Please see the accompanying LICENSE file in root directory for terms.
 *
 */


#include "OSoLWriter.h"
#include "OSOption.h"
#include "OSgLWriter.h"
#include "OSGeneral.h"
#include "OSStringUtil.h"
#include "OSParameters.h"
#include "OSConfig.h"
#include "OSBase64.h"
#include "OSMathUtil.h"
#include "OSOutput.h"
#include <sstream>
#include <iostream>
#include <stdio.h>

using std::endl;
using std::ostringstream;

OSoLWriter::OSoLWriter( )
{
    m_bWriteBase64 = false;
    m_bWhiteSpace = false;
}

OSoLWriter::~OSoLWriter()
{
}


std::string OSoLWriter::writeOSoL( OSOption *theosoption)
{
    m_OSOption = theosoption;
    std::ostringstream osolStr, outStr;
#ifdef WIN_
    const char	dirsep='\\';
#else
    const char	dirsep='/';
#endif
    // Set directory containing stylesheet files.
    std::string xsltDir;
    xsltDir = dirsep == '/' ? "../stylesheets/" : "..\\stylesheets\\";
    // always go with '/' -- it is a hypertext reference
    xsltDir = "http://www.coin-or.org/OS/stylesheets/";

    bool generalTagPrinted;
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSoLwriter, ENUM_OUTPUT_LEVEL_trace, "in OSoLWriter");
#endif

    if(m_OSOption == NULL)  return osolStr.str();
    osolStr << "<?xml version=\"1.0\" encoding=\"UTF-8\"?>" ;
    osolStr << "<?xml-stylesheet type=\"text/xsl\" href=\"";
    osolStr << xsltDir;
    osolStr << "OSoL.xslt\"?>";
    osolStr << endl;
    osolStr << "<osol xmlns=\"os.optimizationservices.org\"   xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\" ";
    osolStr << "xsi:schemaLocation=\"os.optimizationservices.org http://www.optimizationservices.org/schemas/";
    osolStr << OS_SCHEMA_VERSION;
    osolStr << "/OSoL.xsd\" >" ;
    osolStr << endl;

#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSoLwriter, ENUM_OUTPUT_LEVEL_trace, "output <optionHeader>");
#endif
    if(m_OSOption->optionHeader != NULL)
    {
        osolStr << "<optionHeader>" << endl;
        osolStr << writeGeneralFileHeader(m_OSOption->optionHeader, true);
        osolStr << "</optionHeader>" << endl;
    }

#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSoLwriter, ENUM_OUTPUT_LEVEL_trace, "output <general>");
#endif
    if(m_OSOption->general != NULL)
    {
        generalTagPrinted = false;
        if (m_OSOption->general->serviceURI != "")
        {
            if (generalTagPrinted == false)
            {
                osolStr << "<general>" << endl;
                generalTagPrinted = true;
            }
            osolStr << "<serviceURI>" << m_OSOption->general->serviceURI << "</serviceURI>" << endl;
        }
        if (m_OSOption->general->serviceName != "")
        {
            if (generalTagPrinted == false)
            {
                osolStr << "<general>" << endl;
                generalTagPrinted = true;
            }
            osolStr << "<serviceName>" << m_OSOption->general->serviceName << "</serviceName>" << endl;
        }
        if (m_OSOption->general->instanceName != "")
        {
            if (generalTagPrinted == false)
            {
                osolStr << "<general>" << endl;
                generalTagPrinted = true;
            }
            osolStr << "<instanceName>" << m_OSOption->general->instanceName << "</instanceName>" << endl;
        }
        if (m_OSOption->general->instanceLocation != NULL)
        {
            if (generalTagPrinted == false)
            {
                osolStr << "<general>" << endl;
                generalTagPrinted = true;
            }
            if (m_OSOption->general->instanceLocation->locationType == "")
            {
                osolStr << "<instanceLocation>";
            }
            else
            {
                osolStr << "<instanceLocation locationType=\"" << m_OSOption->general->instanceLocation->locationType << "\">";
            };
            osolStr << m_OSOption->general->instanceLocation->value << "</instanceLocation>" << endl;
        }
        if (m_OSOption->general->jobID != "")
        {
            if (generalTagPrinted == false)
            {
                osolStr << "<general>" << endl;
                generalTagPrinted = true;
            }
            osolStr << "<jobID>" << m_OSOption->general->jobID << "</jobID>" << endl;
        }
        if (m_OSOption->general->solverToInvoke != "")
        {
            if (generalTagPrinted == false)
            {
                osolStr << "<general>" << endl;
                generalTagPrinted = true;
            }
            osolStr << "<solverToInvoke>" << m_OSOption->general->solverToInvoke << "</solverToInvoke>" << endl;
        }
        if (m_OSOption->general->license != "")
        {
            if (generalTagPrinted == false)
            {
                osolStr << "<general>" << endl;
                generalTagPrinted = true;
            }
            osolStr << "<license>" << m_OSOption->general->license << "</license>" << endl;
        }
        if (m_OSOption->general->userName != "")
        {
            if (generalTagPrinted == false)
            {
                osolStr << "<general>" << endl;
                generalTagPrinted = true;
            }
            osolStr << "<userName>" << m_OSOption->general->userName << "</userName>" << endl;
        }
        if (m_OSOption->general->password != "")
        {
            if (generalTagPrinted == false)
            {
                osolStr << "<general>" << endl;
                generalTagPrinted = true;
            }
            osolStr << "<password>" << m_OSOption->general->password << "</password>" << endl;
        }
        if (m_OSOption->general->contact != NULL)
        {
            if (generalTagPrinted == false)
            {
                osolStr << "<general>" << endl;
                generalTagPrinted = true;
            }
            if (m_OSOption->general->contact->transportType == "")
            {
                osolStr << "<contact>";
            }
            else
            {
                osolStr << "<contact transportType=\"" << m_OSOption->general->contact->transportType << "\">";
            };
            osolStr << m_OSOption->general->contact->value << "</contact>" << endl;
        }
        if (m_OSOption->general->otherOptions != NULL)
        {
            if (generalTagPrinted == false)
            {
                osolStr << "<general>" << endl;
                generalTagPrinted = true;
            }
            osolStr << "<otherOptions numberOfOtherOptions=\"";
            osolStr << m_OSOption->general->otherOptions->numberOfOtherOptions << "\">" << endl;
            for (int i=0; i < m_OSOption->general->otherOptions->numberOfOtherOptions; i++)
            {
                osolStr << "<other name=\"" << m_OSOption->general->otherOptions->other[i]->name << "\"";
                if (m_OSOption->general->otherOptions->other[i]->value != "")
                    osolStr << " value=\"" << m_OSOption->general->otherOptions->other[i]->value << "\"";
                if (m_OSOption->general->otherOptions->other[i]->description != "")
                    osolStr << " description=" << writeStringData(m_OSOption->general->otherOptions->other[i]->description);
                osolStr << "/>" << endl;
            }
            osolStr << "</otherOptions>" << endl;
        }
        if (generalTagPrinted == false)
            osolStr << "<general>" << endl;

        osolStr << "</general>" << endl;
#ifndef NDEBUG
        osoutput->OSPrint(ENUM_OUTPUT_AREA_OSoLwriter, ENUM_OUTPUT_LEVEL_trace, "Done with <general> element");
#endif
    };

    /**
     * 	Put the <system> element
     */
    if(m_OSOption->system != NULL)
    {

        osolStr << "<system>" << endl;
        if (m_OSOption->system->minDiskSpace != NULL)
        {
            osolStr << "<minDiskSpace";
            if (m_OSOption->system->minDiskSpace->unit != "byte")
                osolStr << " unit=\"" << m_OSOption->system->minDiskSpace->unit << "\"";
            if (m_OSOption->system->minDiskSpace->description != "")
                osolStr << " description=" << writeStringData(m_OSOption->system->minDiskSpace->description);
            osolStr << ">";
            if (!OSIsnan(m_OSOption->system->minDiskSpace->value))
                osolStr << os_dtoa_format(m_OSOption->system->minDiskSpace->value);
            else
                osolStr << "NaN";
            osolStr << "</minDiskSpace>" << endl;
        }
        if (m_OSOption->system->minMemorySize != NULL)
        {
            osolStr << "<minMemorySize";
            if (m_OSOption->system->minMemorySize->unit != "byte")
                osolStr << " unit=\"" << m_OSOption->system->minMemorySize->unit << "\"";
            if (m_OSOption->system->minMemorySize->description != "")
                osolStr << " description=" << writeStringData(m_OSOption->system->minMemorySize->description);
            osolStr << ">";
            if (!OSIsnan(m_OSOption->system->minMemorySize->value))
                osolStr << os_dtoa_format(m_OSOption->system->minMemorySize->value);
            else
                osolStr << "NaN";
            osolStr << "</minMemorySize>" << endl;
        }
        if (m_OSOption->system->minCPUSpeed != NULL)
        {
            osolStr << "<minCPUSpeed";
            if (m_OSOption->system->minCPUSpeed->unit != "hertz")
                osolStr << " unit=\"" << m_OSOption->system->minCPUSpeed->unit << "\"";
            if (m_OSOption->system->minCPUSpeed->description != "")
                osolStr << " description=" << writeStringData(m_OSOption->system->minCPUSpeed->description);
            osolStr << ">";
            if (!OSIsnan(m_OSOption->system->minCPUSpeed->value))
                osolStr << os_dtoa_format(m_OSOption->system->minCPUSpeed->value);
            else
                osolStr << "NaN";
            osolStr << "</minCPUSpeed>" << endl;
        }
        if (m_OSOption->system->minCPUNumber != NULL)
        {
            osolStr << "<minCPUNumber";
            if (m_OSOption->system->minCPUNumber->description != "")
                osolStr << " description=" << writeStringData(m_OSOption->system->minCPUNumber->description);
            osolStr << ">";
            osolStr << m_OSOption->system->minCPUNumber->value << "</minCPUNumber>" << endl;
        };
        if (m_OSOption->system->otherOptions != NULL)
        {
            osolStr << "<otherOptions numberOfOtherOptions=\"";
            osolStr << m_OSOption->system->otherOptions->numberOfOtherOptions << "\">" << endl;
            for (int i=0; i < m_OSOption->system->otherOptions->numberOfOtherOptions; i++)
            {
                osolStr << "<other name=\"" << m_OSOption->system->otherOptions->other[i]->name << "\"";
                if (m_OSOption->system->otherOptions->other[i]->value != "")
                    osolStr << " value=\"" << m_OSOption->system->otherOptions->other[i]->value << "\"";
                if (m_OSOption->system->otherOptions->other[i]->description != "")
                    osolStr << " description=" << writeStringData(m_OSOption->system->otherOptions->other[i]->description);
                osolStr << "/>" << endl;
            }
            osolStr << "</otherOptions>" << endl;
        }
        osolStr << "</system>" << endl;
#ifndef NDEBUG
        osoutput->OSPrint(ENUM_OUTPUT_AREA_OSoLwriter, ENUM_OUTPUT_LEVEL_trace, "Done with <system> element");
#endif
    }

    /**
     * 	Put the <service> element
     */
    if(m_OSOption->service != NULL)
    {
        osolStr << "<service>" << endl;
        if (m_OSOption->service->type != "")
        {
            osolStr << "<type>" << m_OSOption->service->type << "</type>" << endl;
        }
        if (m_OSOption->service->otherOptions != NULL)
        {
            osolStr << "<otherOptions numberOfOtherOptions=\"";
            osolStr << m_OSOption->service->otherOptions->numberOfOtherOptions << "\">" << endl;
            for (int i=0; i < m_OSOption->service->otherOptions->numberOfOtherOptions; i++)
            {
                osolStr << "<other name=\"" << m_OSOption->service->otherOptions->other[i]->name << "\"";
                if (m_OSOption->service->otherOptions->other[i]->value != "")
                    osolStr << " value=\"" << m_OSOption->service->otherOptions->other[i]->value << "\"";
                if (m_OSOption->service->otherOptions->other[i]->description != "")
                    osolStr << " description=" << writeStringData(m_OSOption->service->otherOptions->other[i]->description);
                osolStr << "/>" << endl;
            }
            osolStr << "</otherOptions>" << endl;
        }
        osolStr << "</service>" << endl;
#ifndef NDEBUG
        osoutput->OSPrint(ENUM_OUTPUT_AREA_OSoLwriter, ENUM_OUTPUT_LEVEL_trace, "Done with <service> element");
#endif
    };

    /**
     * 	Put the <job> element
     */
    if(m_OSOption->job != NULL)
    {
        osolStr << "<job>" << endl;
        if (m_OSOption->job->maxTime != NULL)
        {
            if (m_OSOption->job->maxTime->unit == "")
                m_OSOption->job->maxTime->unit = "second";
            osolStr << "<maxTime unit=\"" << m_OSOption->job->maxTime->unit << "\">";
            if (!OSIsnan(m_OSOption->job->maxTime->value))
                osolStr << os_dtoa_format(m_OSOption->job->maxTime->value);
            else
                osolStr << "NaN";
            osolStr << "</maxTime>" << endl;
        }
        if (m_OSOption->job->requestedStartTime != "")
            osolStr << "<requestedStartTime>" << m_OSOption->job->requestedStartTime << "</requestedStartTime>" << endl;
        if (m_OSOption->job->dependencies != NULL)
        {
            osolStr << "<dependencies numberOfJobIDs=\"";
            osolStr << m_OSOption->job->dependencies->numberOfJobIDs << "\">" << endl;
            for (int i=0; i < m_OSOption->job->dependencies->numberOfJobIDs; i++)
                osolStr << "<jobID>" << m_OSOption->job->dependencies->jobID[i] << "</jobID>" << endl;
            osolStr << "</dependencies>" << endl;
        }
        if (m_OSOption->job->requiredDirectories != NULL)
        {
            osolStr << "<requiredDirectories numberOfPaths=\"";
            osolStr << m_OSOption->job->requiredDirectories->numberOfPaths << "\">" << endl;
            for (int i=0; i < m_OSOption->job->requiredDirectories->numberOfPaths; i++)
                osolStr << "<path>" << m_OSOption->job->requiredDirectories->path[i] << "</path>" << endl;
            osolStr << "</requiredDirectories>" << endl;
        }
        if (m_OSOption->job->requiredFiles != NULL)
        {
            osolStr << "<requiredFiles numberOfPaths=\"";
            osolStr << m_OSOption->job->requiredFiles->numberOfPaths << "\">" << endl;
            for (int i=0; i < m_OSOption->job->requiredFiles->numberOfPaths; i++)
                osolStr << "<path>" << m_OSOption->job->requiredFiles->path[i] << "</path>" << endl;
            osolStr << "</requiredFiles>" << endl;
        }
        if (m_OSOption->job->directoriesToMake != NULL)
        {
            osolStr << "<directoriesToMake numberOfPaths=\"";
            osolStr << m_OSOption->job->directoriesToMake->numberOfPaths << "\">" << endl;
            for (int i=0; i < m_OSOption->job->directoriesToMake->numberOfPaths; i++)
                osolStr << "<path>" << m_OSOption->job->directoriesToMake->path[i] << "</path>" << endl;

            osolStr << "</directoriesToMake>" << endl;
        }
        if (m_OSOption->job->filesToMake != NULL)
        {
            osolStr << "<filesToMake numberOfPaths=\"";
            osolStr << m_OSOption->job->filesToMake->numberOfPaths << "\">" << endl;
            for (int i=0; i < m_OSOption->job->filesToMake->numberOfPaths; i++)
                osolStr << "<path>" << m_OSOption->job->filesToMake->path[i] << "</path>" << endl;
            osolStr << "</filesToMake>" << endl;
        }
        if (m_OSOption->job->inputDirectoriesToMove != NULL)
        {
            osolStr << "<inputDirectoriesToMove numberOfPathPairs=\"";
            osolStr << m_OSOption->job->inputDirectoriesToMove->numberOfPathPairs << "\">" << endl;
            for (int i=0; i < m_OSOption->job->inputDirectoriesToMove->numberOfPathPairs; i++)
            {
                osolStr << "<pathPair";
                osolStr << " from=\"" << m_OSOption->job->inputDirectoriesToMove->pathPair[i]->from << "\"";
                osolStr << " to=\"" << m_OSOption->job->inputDirectoriesToMove->pathPair[i]->to << "\"";
                if (m_OSOption->job->inputDirectoriesToMove->pathPair[i]->makeCopy)
                    osolStr << " makeCopy=\"true\"";
                osolStr << "/>" << endl;
            }
            osolStr << "</inputDirectoriesToMove>" << endl;
        }
        if (m_OSOption->job->inputFilesToMove != NULL)
        {
            osolStr << "<inputFilesToMove numberOfPathPairs=\"";
            osolStr << m_OSOption->job->inputFilesToMove->numberOfPathPairs << "\">" << endl;
            for (int i=0; i < m_OSOption->job->inputFilesToMove->numberOfPathPairs; i++)
            {
                osolStr << "<pathPair";
                osolStr << " from=\"" << m_OSOption->job->inputFilesToMove->pathPair[i]->from << "\"";
                osolStr << " to=\"" << m_OSOption->job->inputFilesToMove->pathPair[i]->to << "\"";
                if (m_OSOption->job->inputFilesToMove->pathPair[i]->makeCopy)
                    osolStr << " makeCopy=\"true\"";
                osolStr << "/>" << endl;
            }
            osolStr << "</inputFilesToMove>" << endl;
        }
        if (m_OSOption->job->outputFilesToMove != NULL)
        {
            osolStr << "<outputFilesToMove numberOfPathPairs=\"";
            osolStr << m_OSOption->job->outputFilesToMove->numberOfPathPairs << "\">" << endl;
            for (int i=0; i < m_OSOption->job->outputFilesToMove->numberOfPathPairs; i++)
            {
                osolStr << "<pathPair";
                osolStr << " from=\"" << m_OSOption->job->outputFilesToMove->pathPair[i]->from << "\"";
                osolStr << " to=\"" << m_OSOption->job->outputFilesToMove->pathPair[i]->to << "\"";
                if (m_OSOption->job->outputFilesToMove->pathPair[i]->makeCopy)
                    osolStr << " makeCopy=\"true\"";
                osolStr << "/>" << endl;
            }
            osolStr << "</outputFilesToMove>" << endl;
        }
        if (m_OSOption->job->outputDirectoriesToMove != NULL)
        {
            osolStr << "<outputDirectoriesToMove numberOfPathPairs=\"";
            osolStr << m_OSOption->job->outputDirectoriesToMove->numberOfPathPairs << "\">" << endl;
            for (int i=0; i < m_OSOption->job->outputDirectoriesToMove->numberOfPathPairs; i++)
            {
                osolStr << "<pathPair";
                osolStr << " from=\"" << m_OSOption->job->outputDirectoriesToMove->pathPair[i]->from << "\"";
                osolStr << " to=\"" << m_OSOption->job->outputDirectoriesToMove->pathPair[i]->to << "\"";
                if (m_OSOption->job->outputDirectoriesToMove->pathPair[i]->makeCopy)
                    osolStr << " makeCopy=\"true\"";
                osolStr << "/>" << endl;
            }
            osolStr << "</outputDirectoriesToMove>" << endl;
        }
        if (m_OSOption->job->filesToDelete != NULL)
        {
            osolStr << "<filesToDelete numberOfPaths=\"";
            osolStr << m_OSOption->job->filesToDelete->numberOfPaths << "\">" << endl;
            for (int i=0; i < m_OSOption->job->filesToDelete->numberOfPaths; i++)
                osolStr << "<path>" << m_OSOption->job->filesToDelete->path[i] << "</path>" << endl;
            osolStr << "</filesToDelete>" << endl;
        }
        if (m_OSOption->job->directoriesToDelete != NULL)
        {
            osolStr << "<directoriesToDelete numberOfPaths=\"";
            osolStr << m_OSOption->job->directoriesToDelete->numberOfPaths << "\">" << endl;
            for (int i=0; i < m_OSOption->job->directoriesToDelete->numberOfPaths; i++)
                osolStr << "<path>" << m_OSOption->job->directoriesToDelete->path[i] << "</path>" << endl;
            osolStr << "</directoriesToDelete>" << endl;
        }
        if (m_OSOption->job->processesToKill != NULL)
        {
            osolStr << "<processesToKill numberOfProcesses=\"";
            osolStr << m_OSOption->job->processesToKill->numberOfProcesses << "\">" << endl;
            for (int i=0; i < m_OSOption->job->processesToKill->numberOfProcesses; i++)
                osolStr << "<process>" << m_OSOption->job->processesToKill->process[i] << "</process>" << endl;
            osolStr << "</processesToKill>" << endl;
        }
        if (m_OSOption->job->otherOptions != NULL)
        {
            osolStr << "<otherOptions numberOfOtherOptions=\"";
            osolStr << m_OSOption->job->otherOptions->numberOfOtherOptions << "\">" << endl;
            for (int i=0; i < m_OSOption->job->otherOptions->numberOfOtherOptions; i++)
            {
                osolStr << "<other name=\"" << m_OSOption->job->otherOptions->other[i]->name << "\"";
                if (m_OSOption->job->otherOptions->other[i]->value != "")
                    osolStr << " value=\"" << m_OSOption->job->otherOptions->other[i]->value << "\"";
                if (m_OSOption->job->otherOptions->other[i]->description != "")
                    osolStr << " description=" << writeStringData(m_OSOption->job->otherOptions->other[i]->description);
                osolStr << "/>" << endl;
            }
            osolStr << "</otherOptions>" << endl;
        }
        osolStr << "</job>" << endl;
#ifndef NDEBUG
        osoutput->OSPrint(ENUM_OUTPUT_AREA_OSoLwriter, ENUM_OUTPUT_LEVEL_trace, "Done with <job> element");
#endif
    };

    /**
     * 	Put the <optimization> element
     */
    if (m_OSOption->optimization != NULL)
    {
        osolStr << "<optimization";
        if (m_OSOption->optimization->numberOfVariables >= 0)
            osolStr << " numberOfVariables=\"" << m_OSOption->optimization->numberOfVariables << "\" ";
        if (m_OSOption->optimization->numberOfObjectives >= 0)
            osolStr << " numberOfObjectives=\"" << m_OSOption->optimization->numberOfObjectives << "\" ";
        if (m_OSOption->optimization->numberOfConstraints >= 0)
            osolStr << " numberOfConstraints=\"" << m_OSOption->optimization->numberOfConstraints << "\" ";
        osolStr << ">" << endl;
        if (m_OSOption->optimization->variables != NULL)
        {
            osolStr << "<variables";
            if (m_OSOption->optimization->variables->numberOfOtherVariableOptions > 0)
                osolStr << " numberOfOtherVariableOptions=\"" << m_OSOption->optimization->variables->numberOfOtherVariableOptions << "\"";
            osolStr << ">" << endl;
#ifndef NDEBUG
            outStr.str("");
            outStr.clear();
            outStr << "initialVariableValues: " 
                   << (m_OSOption->optimization->variables->initialVariableValues != NULL) << endl;
            osoutput->OSPrint(ENUM_OUTPUT_AREA_OSoLwriter, ENUM_OUTPUT_LEVEL_trace, outStr.str());
#endif
            if (m_OSOption->optimization->variables->initialVariableValues != NULL)
            {
                osolStr << "<initialVariableValues numberOfVar=\"";
                osolStr << m_OSOption->optimization->variables->initialVariableValues->numberOfVar << "\">" << endl;
                for (int i=0; i < m_OSOption->optimization->variables->initialVariableValues->numberOfVar; i++)
                {
                    osolStr << "<var";
                    osolStr << " idx=\"" << m_OSOption->optimization->variables->initialVariableValues->var[i]->idx << "\"";
                    if (m_OSOption->optimization->variables->initialVariableValues->var[i]->name != "")
                        osolStr << " name=" << writeStringData(m_OSOption->optimization->variables->initialVariableValues->var[i]->name);
                    if (!OSIsnan(m_OSOption->optimization->variables->initialVariableValues->var[i]->value))
                    {
                        osolStr << " value=\"";
                        osolStr << os_dtoa_format(m_OSOption->optimization->variables->initialVariableValues->var[i]->value);
                        osolStr << "\"";
                    }
                    osolStr << "/>" << endl;
                }
                osolStr << "</initialVariableValues>" << endl;
            }
#ifndef NDEBUG
            outStr.str("");
            outStr.clear();
            outStr << "initialVariableValuesString: " 
                   << (m_OSOption->optimization->variables->initialVariableValuesString != NULL) << endl;
            osoutput->OSPrint(ENUM_OUTPUT_AREA_OSoLwriter, ENUM_OUTPUT_LEVEL_trace, "in OSoLWriter");
#endif
            if (m_OSOption->optimization->variables->initialVariableValuesString != NULL)
            {
                osolStr << "<initialVariableValuesString numberOfVar=\"";
                osolStr << m_OSOption->optimization->variables->initialVariableValuesString->numberOfVar << "\">" << endl;
                for (int i=0; i < m_OSOption->optimization->variables->initialVariableValuesString->numberOfVar; i++)
                {
                    osolStr << "<var";
                    osolStr << " idx=\"" << m_OSOption->optimization->variables->initialVariableValuesString->var[i]->idx << "\"";
                    if (m_OSOption->optimization->variables->initialVariableValuesString->var[i]->name != "")
                        osolStr << " name=" << writeStringData(m_OSOption->optimization->variables->initialVariableValuesString->var[i]->name);
                    osolStr << " value=\"" << m_OSOption->optimization->variables->initialVariableValuesString->var[i]->value << "\"";
                    osolStr << "/>" << endl;
                }
                osolStr << "</initialVariableValuesString>" << endl;
            }

            if (m_OSOption->optimization->variables->initialBasisStatus != NULL)
            {
#ifndef NDEBUG
                osoutput->OSPrint(ENUM_OUTPUT_AREA_OSoLwriter, ENUM_OUTPUT_LEVEL_trace, 
                    "output <variables> <basisStatus>");
#endif
                osolStr << "<initialBasisStatus>" << endl;
                osolStr << writeBasisStatus(m_OSOption->optimization->variables->initialBasisStatus, m_bWhiteSpace, m_bWriteBase64);
                osolStr << "</initialBasisStatus>" << endl;
            }

#ifndef NDEBUG
            outStr.str("");
            outStr.clear();
            outStr << "integerVariableBranchingWeights: " 
                   << (m_OSOption->optimization->variables->integerVariableBranchingWeights != NULL) << endl;
            osoutput->OSPrint(ENUM_OUTPUT_AREA_OSoLwriter, ENUM_OUTPUT_LEVEL_trace, outStr.str());
#endif
            if (m_OSOption->optimization->variables->integerVariableBranchingWeights != NULL)
            {
                osolStr << "<integerVariableBranchingWeights numberOfVar=\"";
                osolStr << m_OSOption->optimization->variables->integerVariableBranchingWeights->numberOfVar << "\">" << endl;
                for (int i=0; i < m_OSOption->optimization->variables->integerVariableBranchingWeights->numberOfVar; i++)
                {
                    osolStr << "<var";
                    osolStr << " idx=\"" << m_OSOption->optimization->variables->integerVariableBranchingWeights->var[i]->idx << "\"";
                    if (m_OSOption->optimization->variables->integerVariableBranchingWeights->var[i]->name != "")
                        osolStr << " name=" << writeStringData(m_OSOption->optimization->variables->integerVariableBranchingWeights->var[i]->name);
                    if (!OSIsnan(m_OSOption->optimization->variables->integerVariableBranchingWeights->var[i]->value))
                    {
                        osolStr << " value=\"";
                        osolStr << os_dtoa_format(m_OSOption->optimization->variables->integerVariableBranchingWeights->var[i]->value);
                        osolStr << "\"";
                    }
                    osolStr << "/>" << endl;
                }
                osolStr << "</integerVariableBranchingWeights>" << endl;
            }
#ifndef NDEBUG
            outStr.str("");
            outStr.clear();
            outStr << "sosVariableBranchingWeights: "
                   << (m_OSOption->optimization->variables->sosVariableBranchingWeights != NULL) << endl;
            osoutput->OSPrint(ENUM_OUTPUT_AREA_OSoLwriter, ENUM_OUTPUT_LEVEL_trace, outStr.str());
#endif
            if (m_OSOption->optimization->variables->sosVariableBranchingWeights != NULL)
            {
                osolStr << "<sosVariableBranchingWeights numberOfSOS=\"";
#ifndef NDEBUG
                osoutput->OSPrint(ENUM_OUTPUT_AREA_OSoLwriter, ENUM_OUTPUT_LEVEL_trace, "start: numberOfSOS");
#endif
                osolStr << m_OSOption->optimization->variables->sosVariableBranchingWeights->numberOfSOS << "\">" << endl;
                for (int i=0; i < m_OSOption->optimization->variables->sosVariableBranchingWeights->numberOfSOS; i++)
                {
                    osolStr << "<sos";
#ifndef NDEBUG
                    outStr.str("");
                    outStr.clear();
                    outStr << "sosIdx - nvar: " 
                           << m_OSOption->optimization->variables->sosVariableBranchingWeights->sos[i]->numberOfVar
                           << endl;
                    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSoLwriter, ENUM_OUTPUT_LEVEL_detailed_trace, outStr.str());
#endif
                    osolStr << " sosIdx=\"" << m_OSOption->optimization->variables->sosVariableBranchingWeights->sos[i]->sosIdx << "\"";
                    osolStr << " numberOfVar=\"" << m_OSOption->optimization->variables->sosVariableBranchingWeights->sos[i]->numberOfVar << "\"";
                    if (!OSIsnan(m_OSOption->optimization->variables->sosVariableBranchingWeights->sos[i]->groupWeight))
                    {
                        osolStr << " groupWeight=\"";
                        osolStr << os_dtoa_format(m_OSOption->optimization->variables->sosVariableBranchingWeights->sos[i]->groupWeight);
                        osolStr << "\">" << endl;
                    }
                    for (int j=0; j < m_OSOption->optimization->variables->sosVariableBranchingWeights->sos[i]->numberOfVar; j++)
                    {
                        osolStr << "<var";
#ifndef NDEBUG
                        osoutput->OSPrint(ENUM_OUTPUT_AREA_OSoLwriter, ENUM_OUTPUT_LEVEL_detailed_trace, "idx");
#endif
                        osolStr << " idx=\"" << m_OSOption->optimization->variables->sosVariableBranchingWeights->sos[i]->var[j]->idx << "\"";
                        if (m_OSOption->optimization->variables->sosVariableBranchingWeights->sos[i]->var[j]->name != "")
                            osolStr << " name=" << writeStringData(m_OSOption->optimization->variables->sosVariableBranchingWeights->sos[i]->var[j]->name);
                        if (!OSIsnan(m_OSOption->optimization->variables->sosVariableBranchingWeights->sos[i]->var[j]->value))
                        {
                            osolStr << " value=\"";
                            osolStr << os_dtoa_format(m_OSOption->optimization->variables->sosVariableBranchingWeights->sos[i]->var[j]->value);
                            osolStr << "\"";
                        }
                        osolStr << "/>" << endl;
                    }
                    osolStr << "</sos>" << endl;
                }
                osolStr << "</sosVariableBranchingWeights>" << endl;
            }
#ifndef NDEBUG
            outStr.str("");
            outStr.clear();
            outStr << "Number of other variable options: " 
                   << m_OSOption->optimization->variables->numberOfOtherVariableOptions 
                   << std::endl;
            osoutput->OSPrint(ENUM_OUTPUT_AREA_OSoLwriter, ENUM_OUTPUT_LEVEL_debug, outStr.str());
#endif
//			if (m_OSOption->optimization->variables->numberOfOtherVariableOptions > 0)
            for (int i=0; i < m_OSOption->optimization->variables->numberOfOtherVariableOptions; i++)
            {
                osolStr << "<other name=\"" << m_OSOption->optimization->variables->other[i]->name << "\"";
//					if (m_OSOption->optimization->variables->other[i]->numberOfVar > 0)
                osolStr << " numberOfVar=\"" << m_OSOption->optimization->variables->other[i]->numberOfVar << "\"";
//					if (m_OSOption->optimization->variables->other[i]->numberOfEnumerations > 0)
                osolStr << " numberOfEnumerations=\"" << m_OSOption->optimization->variables->other[i]->numberOfEnumerations << "\"";
                if (m_OSOption->optimization->variables->other[i]->value != "")
                    osolStr << " value=\"" << m_OSOption->optimization->variables->other[i]->value << "\"";
                if (m_OSOption->optimization->variables->other[i]->solver != "")
                    osolStr << " solver=\"" << m_OSOption->optimization->variables->other[i]->solver << "\"";
                if (m_OSOption->optimization->variables->other[i]->category != "")
                    osolStr << " category=\"" << m_OSOption->optimization->variables->other[i]->category << "\"";
                if (m_OSOption->optimization->variables->other[i]->type != "")
                    osolStr << " type=\"" << m_OSOption->optimization->variables->other[i]->type << "\"";
                if (m_OSOption->optimization->variables->other[i]->description != "")
                    osolStr << " description=" << writeStringData(m_OSOption->optimization->variables->other[i]->description);
                if (m_OSOption->optimization->variables->other[i]->varType != "")
                    osolStr << " varType=\"" << m_OSOption->optimization->variables->other[i]->varType << "\"";
                if (m_OSOption->optimization->variables->other[i]->enumType != "")
                    osolStr << " enumType=\"" << m_OSOption->optimization->variables->other[i]->enumType << "\"";
                osolStr << ">" << endl;
//					if (m_OSOption->optimization->variables->other[i]->numberOfVar > 0)
                for (int j=0; j < m_OSOption->optimization->variables->other[i]->numberOfVar; j++)
                {
                    osolStr << "<var idx=\"" << m_OSOption->optimization->variables->other[i]->var[j]->idx << "\"";
                    if (m_OSOption->optimization->variables->other[i]->var[j]->name != "")
                        osolStr << " name=" << writeStringData(m_OSOption->optimization->variables->other[i]->var[j]->name);
                    if (m_OSOption->optimization->variables->other[i]->var[j]->value != "")
                        osolStr << " value=\"" << m_OSOption->optimization->variables->other[i]->var[j]->value << "\"";
                    if (m_OSOption->optimization->variables->other[i]->var[j]->lbValue != "")
                        osolStr << " lbValue=\"" << m_OSOption->optimization->variables->other[i]->var[j]->lbValue << "\"";
                    if (m_OSOption->optimization->variables->other[i]->var[j]->ubValue != "")
                        osolStr << " ubValue=\"" << m_OSOption->optimization->variables->other[i]->var[j]->ubValue << "\"";
                    osolStr << "/>" << endl;
                }
//					else
                {
//						if (m_OSOption->optimization->variables->other[i]->numberOfEnumerations > 0)
                    for (int j=0; j < m_OSOption->optimization->variables->other[i]->numberOfEnumerations; j++)
                        osolStr << writeOtherOptionOrResultEnumeration(m_OSOption->optimization->variables->other[i]->enumeration[j], m_bWhiteSpace, m_bWriteBase64);
                }
                osolStr << "</other>" << endl;
            }
            osolStr << "</variables>" << endl;
        }
        if (m_OSOption->optimization->objectives != NULL)
        {
            osolStr << "<objectives";
//			if (m_OSOption->optimization->objectives->numberOfOtherObjectiveOptions > 0)
            osolStr << " numberOfOtherObjectiveOptions=\"" << m_OSOption->optimization->objectives->numberOfOtherObjectiveOptions << "\"";
            osolStr << ">" << endl;
            if (m_OSOption->optimization->objectives->initialObjectiveValues != NULL)
            {
                osolStr << "<initialObjectiveValues numberOfObj=\"";
                osolStr << m_OSOption->optimization->objectives->initialObjectiveValues->numberOfObj << "\">" << endl;
                for (int i=0; i < m_OSOption->optimization->objectives->initialObjectiveValues->numberOfObj; i++)
                {
                    osolStr << "<obj";
                    osolStr << " idx=\"" << m_OSOption->optimization->objectives->initialObjectiveValues->obj[i]->idx << "\"";
                    if (m_OSOption->optimization->objectives->initialObjectiveValues->obj[i]->name != "")
                        osolStr << " name=" << writeStringData(m_OSOption->optimization->objectives->initialObjectiveValues->obj[i]->name);
                    if (!OSIsnan(m_OSOption->optimization->objectives->initialObjectiveValues->obj[i]->value))
                    {
                        osolStr << " value=\"";
                        osolStr << os_dtoa_format(m_OSOption->optimization->objectives->initialObjectiveValues->obj[i]->value);
                        osolStr << "\"";
                    }
                    osolStr << "/>" << endl;
                }
                osolStr << "</initialObjectiveValues>" << endl;
            }
            if (m_OSOption->optimization->objectives->initialObjectiveBounds != NULL)
            {
                osolStr << "<initialObjectiveBounds numberOfObj=\"";
                osolStr << m_OSOption->optimization->objectives->initialObjectiveBounds->numberOfObj << "\">" << endl;
                for (int i=0; i < m_OSOption->optimization->objectives->initialObjectiveBounds->numberOfObj; i++)
                {
                    osolStr << "<obj";
                    osolStr << " idx=\"" << m_OSOption->optimization->objectives->initialObjectiveBounds->obj[i]->idx << "\"";
                    if (m_OSOption->optimization->objectives->initialObjectiveBounds->obj[i]->name != "")
                        osolStr << " name=" << writeStringData(m_OSOption->optimization->objectives->initialObjectiveBounds->obj[i]->name);
                    if (!OSIsnan(m_OSOption->optimization->objectives->initialObjectiveBounds->obj[i]->lbValue))
                    {
                        osolStr << " lbValue=\"";
                        osolStr << os_dtoa_format(m_OSOption->optimization->objectives->initialObjectiveBounds->obj[i]->lbValue);
                        osolStr << "\"";
                    }
                    if (!OSIsnan(m_OSOption->optimization->objectives->initialObjectiveBounds->obj[i]->ubValue))
                    {
                        osolStr << " ubValue=\"";
                        osolStr << os_dtoa_format(m_OSOption->optimization->objectives->initialObjectiveBounds->obj[i]->ubValue);
                        osolStr << "\"";
                    }
                    osolStr << "/>" << endl;
                }
                osolStr << "</initialObjectiveBounds>" << endl;
            }

            if (m_OSOption->optimization->objectives->initialBasisStatus != NULL)
            {
#ifndef NDEBUG
                osoutput->OSPrint(ENUM_OUTPUT_AREA_OSoLwriter, ENUM_OUTPUT_LEVEL_trace,
                    "output <objectives> <basisStatus>");
#endif
                osolStr << "<initialBasisStatus>" << endl;
                osolStr << writeBasisStatus(m_OSOption->optimization->objectives->initialBasisStatus, m_bWhiteSpace, m_bWriteBase64);
                osolStr << "</initialBasisStatus>" << endl;
            }

#ifndef NDEBUG
            outStr.str("");
            outStr.clear();
            outStr << "Number of other objective options: " 
                   << m_OSOption->optimization->objectives->numberOfOtherObjectiveOptions << std::endl;
            osoutput->OSPrint(ENUM_OUTPUT_AREA_OSoLwriter, ENUM_OUTPUT_LEVEL_trace, outStr.str());
#endif
//			if (m_OSOption->optimization->objectives->numberOfOtherObjectiveOptions > 0)
            for (int i=0; i < m_OSOption->optimization->objectives->numberOfOtherObjectiveOptions; i++)
            {
                osolStr << "<other name=\"" << m_OSOption->optimization->objectives->other[i]->name << "\"";
//					if (m_OSOption->optimization->objectives->other[i]->numberOfObj > 0)
                osolStr << " numberOfObj=\"" << m_OSOption->optimization->objectives->other[i]->numberOfObj << "\"";
//					if (m_OSOption->optimization->objectives->other[i]->numberOfEnumerations > 0)
                osolStr << " numberOfEnumerations=\"" << m_OSOption->optimization->objectives->other[i]->numberOfEnumerations << "\"";
                if (m_OSOption->optimization->objectives->other[i]->value != "")
                    osolStr << " value=\"" << m_OSOption->optimization->objectives->other[i]->value << "\"";
                if (m_OSOption->optimization->objectives->other[i]->solver != "")
                    osolStr << " solver=\"" << m_OSOption->optimization->objectives->other[i]->solver << "\"";
                if (m_OSOption->optimization->objectives->other[i]->category != "")
                    osolStr << " category=\"" << m_OSOption->optimization->objectives->other[i]->category << "\"";
                if (m_OSOption->optimization->objectives->other[i]->type != "")
                    osolStr << " type=\"" << m_OSOption->optimization->objectives->other[i]->type << "\"";
                if (m_OSOption->optimization->objectives->other[i]->description != "")
                    osolStr << " description=" << writeStringData(m_OSOption->optimization->objectives->other[i]->description);
                if (m_OSOption->optimization->objectives->other[i]->objType != "")
                    osolStr << " objType=\"" << m_OSOption->optimization->objectives->other[i]->objType << "\"";
                if (m_OSOption->optimization->objectives->other[i]->enumType != "")
                    osolStr << " enumType=\"" << m_OSOption->optimization->objectives->other[i]->enumType << "\"";
                osolStr << ">" << endl;
//					if (m_OSOption->optimization->objectives->other[i]->numberOfObj > 0)
                for (int j=0; j < m_OSOption->optimization->objectives->other[i]->numberOfObj; j++)
                {
                    osolStr << "<obj idx=\"" << m_OSOption->optimization->objectives->other[i]->obj[j]->idx << "\"";
                    if (m_OSOption->optimization->objectives->other[i]->obj[j]->name != "")
                        osolStr << " name=" << writeStringData(m_OSOption->optimization->objectives->other[i]->obj[j]->name);
                    if (m_OSOption->optimization->objectives->other[i]->obj[j]->value != "")
                        osolStr << " value=\"" << m_OSOption->optimization->objectives->other[i]->obj[j]->value << "\"";
                    osolStr << "/>" << endl;
                }
//					else if (m_OSOption->optimization->objectives->other[i]->numberOfEnumerations > 0)
                for (int j=0; j < m_OSOption->optimization->objectives->other[i]->numberOfEnumerations; j++)
                    osolStr << writeOtherOptionOrResultEnumeration(m_OSOption->optimization->objectives->other[i]->enumeration[j], m_bWhiteSpace, m_bWriteBase64);

                osolStr << "</other>" << endl;
            }
            osolStr << "</objectives>" << endl;
        }
#ifndef NDEBUG
        osoutput->OSPrint(ENUM_OUTPUT_AREA_OSoLwriter, ENUM_OUTPUT_LEVEL_trace, "Done with <objectives> element");
#endif
        if (m_OSOption->optimization->constraints != NULL)
        {
            osolStr << "<constraints";
//			if (m_OSOption->optimization->constraints->numberOfOtherConstraintOptions > 0)
            osolStr << " numberOfOtherConstraintOptions=\"" << m_OSOption->optimization->constraints->numberOfOtherConstraintOptions << "\"";
            osolStr << ">" << endl;
            if (m_OSOption->optimization->constraints->initialConstraintValues != NULL)
            {
                osolStr << "<initialConstraintValues numberOfCon=\"";
                osolStr << m_OSOption->optimization->constraints->initialConstraintValues->numberOfCon << "\">" << endl;
                for (int i=0; i < m_OSOption->optimization->constraints->initialConstraintValues->numberOfCon; i++)
                {
                    osolStr << "<con";
                    osolStr << " idx=\"" << m_OSOption->optimization->constraints->initialConstraintValues->con[i]->idx << "\"";
                    if (m_OSOption->optimization->constraints->initialConstraintValues->con[i]->name != "")
                        osolStr << " name=" << writeStringData(m_OSOption->optimization->constraints->initialConstraintValues->con[i]->name);
                    if (!OSIsnan(m_OSOption->optimization->constraints->initialConstraintValues->con[i]->value))
                    {
                        osolStr << " value=\"";
                        osolStr << os_dtoa_format(m_OSOption->optimization->constraints->initialConstraintValues->con[i]->value);
                        osolStr << "\"";
                    }
                    osolStr << "/>" << endl;
                }
                osolStr << "</initialConstraintValues>" << endl;
            }

            if (m_OSOption->optimization->constraints->initialDualValues != NULL)
            {
                osolStr << "<initialDualValues numberOfCon=\"";
                osolStr << m_OSOption->optimization->constraints->initialDualValues->numberOfCon << "\">" << endl;
                for (int i=0; i < m_OSOption->optimization->constraints->initialDualValues->numberOfCon; i++)
                {
                    osolStr << "<con";
                    osolStr << " idx=\"" << m_OSOption->optimization->constraints->initialDualValues->con[i]->idx << "\"";
                    if (m_OSOption->optimization->constraints->initialDualValues->con[i]->name != "")
                        osolStr << " name=" << writeStringData(m_OSOption->optimization->constraints->initialDualValues->con[i]->name);
                    if (!OSIsnan(m_OSOption->optimization->constraints->initialDualValues->con[i]->lbDualValue))
                    {
                        osolStr << " lbDualValue=\"";
                        osolStr << os_dtoa_format(m_OSOption->optimization->constraints->initialDualValues->con[i]->lbDualValue);
                        osolStr << "\"";
                    }
                    if (!OSIsnan(m_OSOption->optimization->constraints->initialDualValues->con[i]->ubDualValue))
                    {
                        osolStr << " ubDualValue=\"";
                        osolStr << os_dtoa_format(m_OSOption->optimization->constraints->initialDualValues->con[i]->ubDualValue);
                        osolStr << "\"";
                    }
                    osolStr << "/>" << endl;
                }
                osolStr << "</initialDualValues>" << endl;
            }

            if (m_OSOption->optimization->constraints->initialBasisStatus != NULL)
            {
#ifndef NDEBUG
                osoutput->OSPrint(ENUM_OUTPUT_AREA_OSoLwriter, ENUM_OUTPUT_LEVEL_trace,
                    "output <constraints> <basisStatus>");
#endif
                osolStr << "<initialBasisStatus>" << endl;
                osolStr << writeBasisStatus(m_OSOption->optimization->constraints->initialBasisStatus, m_bWhiteSpace, m_bWriteBase64);
                osolStr << "</initialBasisStatus>" << endl;
            }

#ifndef NDEBUG
            outStr.str("");
            outStr.clear();
            outStr << "Number of other constraint options: "
                   << m_OSOption->optimization->constraints->numberOfOtherConstraintOptions
                   << std::endl;
            osoutput->OSPrint(ENUM_OUTPUT_AREA_OSoLwriter, ENUM_OUTPUT_LEVEL_trace, outStr.str());
#endif
//			if (m_OSOption->optimization->constraints->numberOfOtherConstraintOptions > 0)
            for (int i=0; i < m_OSOption->optimization->constraints->numberOfOtherConstraintOptions; i++)
            {
                osolStr << "<other name=\"" << m_OSOption->optimization->constraints->other[i]->name << "\"";

//					if (m_OSOption->optimization->constraints->other[i]->numberOfCon > 0)
                osolStr << " numberOfCon=\"" << m_OSOption->optimization->constraints->other[i]->numberOfCon << "\"";
//					if (m_OSOption->optimization->constraints->other[i]->numberOfEnumerations > 0)
                osolStr << " numberOfEnumerations=\"" << m_OSOption->optimization->constraints->other[i]->numberOfEnumerations << "\"";
                if (m_OSOption->optimization->constraints->other[i]->value != "")
                    osolStr << " value=\"" << m_OSOption->optimization->constraints->other[i]->value << "\"";
                if (m_OSOption->optimization->constraints->other[i]->solver != "")
                    osolStr << " solver=\"" << m_OSOption->optimization->constraints->other[i]->solver << "\"";
                if (m_OSOption->optimization->constraints->other[i]->category != "")
                    osolStr << " category=\"" << m_OSOption->optimization->constraints->other[i]->category << "\"";
                if (m_OSOption->optimization->constraints->other[i]->type != "")
                    osolStr << " type=\"" << m_OSOption->optimization->constraints->other[i]->type << "\"";
                if (m_OSOption->optimization->constraints->other[i]->description != "")
                    osolStr << " description=" << writeStringData(m_OSOption->optimization->constraints->other[i]->description);
                if (m_OSOption->optimization->constraints->other[i]->conType != "")
                    osolStr << " conType=\"" << m_OSOption->optimization->constraints->other[i]->conType << "\"";
                if (m_OSOption->optimization->constraints->other[i]->enumType != "")
                    osolStr << " enumType=\"" << m_OSOption->optimization->constraints->other[i]->enumType << "\"";
                osolStr << ">" << endl;
//					if (m_OSOption->optimization->constraints->other[i]->numberOfCon > 0)
                for (int j=0; j < m_OSOption->optimization->constraints->other[i]->numberOfCon; j++)
                {
                    osolStr << "<con idx=\"" << m_OSOption->optimization->constraints->other[i]->con[j]->idx << "\"";
                    if (m_OSOption->optimization->constraints->other[i]->con[j]->name != "")
                        osolStr << " name=" << writeStringData(m_OSOption->optimization->constraints->other[i]->con[j]->name);
                    if (m_OSOption->optimization->constraints->other[i]->con[j]->value != "")
                        osolStr << " value=\"" << m_OSOption->optimization->constraints->other[i]->con[j]->value << "\"";
                    if (m_OSOption->optimization->constraints->other[i]->con[j]->lbValue != "")
                        osolStr << " lbValue=\"" << m_OSOption->optimization->constraints->other[i]->con[j]->lbValue << "\"";
                    if (m_OSOption->optimization->constraints->other[i]->con[j]->ubValue != "")
                        osolStr << " ubValue=\"" << m_OSOption->optimization->constraints->other[i]->con[j]->ubValue << "\"";
                    osolStr << "/>" << endl;
                }
//					else if (m_OSOption->optimization->constraints->other[i]->numberOfEnumerations > 0)
                for (int j=0; j < m_OSOption->optimization->constraints->other[i]->numberOfEnumerations; j++)
                    osolStr << writeOtherOptionOrResultEnumeration(m_OSOption->optimization->constraints->other[i]->enumeration[j], m_bWhiteSpace, m_bWriteBase64);

                osolStr << "</other>" << endl;
            }
            osolStr << "</constraints>" << endl;
        }
#ifndef NDEBUG
        osoutput->OSPrint(ENUM_OUTPUT_AREA_OSoLwriter, ENUM_OUTPUT_LEVEL_trace, "Done with <constraint> element");
#endif
        if (m_OSOption->optimization->solverOptions != NULL)
        {
//			if (m_OSOption->optimization->solverOptions->numberOfSolverOptions > 0)
            {
                osolStr << "<solverOptions numberOfSolverOptions=\"";
                osolStr << m_OSOption->optimization->solverOptions->numberOfSolverOptions << "\">" << endl;
                for (int i=0; i < m_OSOption->optimization->solverOptions->numberOfSolverOptions; i++)
                {
                    osolStr << "<solverOption name=\"" << m_OSOption->optimization->solverOptions->solverOption[i]->name << "\"";
                    if (m_OSOption->optimization->solverOptions->solverOption[i]->value != "")
                        osolStr << " value=\"" << m_OSOption->optimization->solverOptions->solverOption[i]->value << "\"";
                    if (m_OSOption->optimization->solverOptions->solverOption[i]->solver != "")
                        osolStr << " solver=\"" << m_OSOption->optimization->solverOptions->solverOption[i]->solver << "\"";
                    if (m_OSOption->optimization->solverOptions->solverOption[i]->category != "")
                        osolStr << " category=\"" << m_OSOption->optimization->solverOptions->solverOption[i]->category << "\"";
                    if (m_OSOption->optimization->solverOptions->solverOption[i]->type != "")
                        osolStr << " type=\"" << m_OSOption->optimization->solverOptions->solverOption[i]->type << "\"";
                    if (m_OSOption->optimization->solverOptions->solverOption[i]->description != "")
                        osolStr << " description=" << writeStringData(m_OSOption->optimization->solverOptions->solverOption[i]->description);
                    if (m_OSOption->optimization->solverOptions->solverOption[i]->numberOfItems == 0)
                        osolStr << "/>" << endl;
                    else
                    {
                        osolStr << " numberOfItems=\"" << m_OSOption->optimization->solverOptions->solverOption[i]->numberOfItems << "\">";
                        for (int k=0; k<m_OSOption->optimization->solverOptions->solverOption[i]->numberOfItems; k++)
                            osolStr << "<item>" << m_OSOption->optimization->solverOptions->solverOption[i]->item[k] << "</item>" << endl;
                        osolStr << "</solverOption>" << endl;
                    }
                }
                osolStr << "</solverOptions>" << endl;
            }
        }
        osolStr << "</optimization>" << endl;
    };
    osolStr << "</osol>" << endl;
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSoLwriter, ENUM_OUTPUT_LEVEL_trace, "Done with <optimization> element");
#endif
    return osolStr.str();
}// end writeOSoL



