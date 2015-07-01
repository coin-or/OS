/* $Id$ */
/** @file OSrLWriter.cpp
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


#include "OSrLWriter.h"
#include "OSResult.h"
#include "OSgLWriter.h"
#include "OSGeneral.h"
#include "OSStringUtil.h"
#include "OSParameters.h"
#include "OSConfig.h"
#include "OSOutput.h"
#include "OSBase64.h"
#include "OSMathUtil.h"
#include <sstream>
#include <iostream>
#include <stdio.h>

using std::endl;
using std::ostringstream;

OSrLWriter::OSrLWriter( )
{
    m_bWriteBase64 = false;
    m_bWhiteSpace = false;
}

OSrLWriter::~OSrLWriter()
{
}


std::string OSrLWriter::writeOSrL( OSResult *theosresult)
{
    m_OSResult = theosresult;
    std::ostringstream outStr;
#ifdef WIN_
    const char	dirsep='\\';
#else
    const char	dirsep='/';
#endif
    // Set directory containing stylesheet files.
    // std::string xsltDir;
    // xsltDir = dirsep == '/' ? "../stylesheets/" : "..\\stylesheets\\";
    // always go with '/' -- it is a hypertext reference
    // xsltDir = "../stylesheets/";
    // xsltDir = "http://www.coin-or.org/OS/stylesheets/";

    // 31 May 2013 --- HIG
    // some browsers consider it a security risk to allow remote stylesheets
    // or even relative addresses containing "../", So we must make sure that
    // the stylesheet is located in the same directory as the OSrL file 

    int i, j;
    bool generalTagPrinted;
    bool systemTagPrinted;
    bool serviceTagPrinted;
    bool jobTagPrinted;
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSrLwriter, ENUM_OUTPUT_LEVEL_trace, "in OSrLWriter");
#endif

    if(m_OSResult == NULL)  return outStr.str();
    outStr << "<?xml version=\"1.0\" encoding=\"UTF-8\"?>" ;
    outStr << "<?xml-stylesheet type=\"text/xsl\" href=\"";
    // outStr << xsltDir;
    outStr << "OSrL.xslt\"?>";
    outStr << endl;
    outStr << "<osrl xmlns=\"os.optimizationservices.org\"   xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\" ";
    outStr << "xsi:schemaLocation=\"os.optimizationservices.org http://www.optimizationservices.org/schemas/";
    outStr << OS_SCHEMA_VERSION;
    outStr << "/OSrL.xsd\" >" ;
    outStr << endl;

#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSrLwriter, ENUM_OUTPUT_LEVEL_trace, "output <resultHeader>");
#endif
    if(m_OSResult->resultHeader != NULL)
    {
        if (m_OSResult->resultHeader->name        != "" ||
                m_OSResult->resultHeader->source      != "" ||
                m_OSResult->resultHeader->description != "" ||
                m_OSResult->resultHeader->fileCreator != "" ||
                m_OSResult->resultHeader->licence     != "" )
        {
            outStr << "<resultHeader>" << endl;
            outStr << writeGeneralFileHeader(m_OSResult->resultHeader, true);
            outStr << "</resultHeader>" << endl;
        }
    }


#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSrLwriter, ENUM_OUTPUT_LEVEL_trace, "output <general>");
#endif
    if(m_OSResult->general != NULL)
    {
        generalTagPrinted = false;
        if(m_OSResult->general->generalStatus != NULL)
        {
            if (generalTagPrinted == false)
            {
                outStr << "<general>" << endl;
                generalTagPrinted = true;
            }
            outStr << "<generalStatus";
            if(m_OSResult->general->generalStatus->type.length() > 0)
            {
                outStr << " type=\"";
                outStr << m_OSResult->general->generalStatus->type ;
                outStr << "\"";
            }
            if(m_OSResult->general->generalStatus->description.length() > 0)
            {
                outStr << " description=";
                outStr << writeStringData(m_OSResult->general->generalStatus->description);
            }
            if (m_OSResult->general->generalStatus->numberOfSubstatuses > 0)
            {
                outStr << " numberOfSubstatuses=\"";
                outStr << m_OSResult->general->generalStatus->numberOfSubstatuses;
                outStr << "\"";
            }
            outStr << ">" << endl;
            for (int i=0; i < m_OSResult->general->generalStatus->numberOfSubstatuses; i++)
            {
                outStr << "<substatus";
                if (m_OSResult->general->generalStatus->substatus[i]->name.length() > 0)
                {
                    outStr << " name=\"";
                    outStr << m_OSResult->general->generalStatus->substatus[i]->name ;
                    outStr << "\"";
                }
                if (m_OSResult->general->generalStatus->substatus[i]->description.length() > 0)
                {
                    outStr << " description=\"";
                    outStr << m_OSResult->general->generalStatus->substatus[i]->description ;
                    outStr << "\"";
                }
                outStr << "/>" << endl;
            }
            outStr << "</generalStatus>" << endl;
        }

        if(m_OSResult->general->message.length() > 0)
        {
            if (generalTagPrinted == false)
            {
                outStr << "<general>" << endl;
                generalTagPrinted = true;
            }
            outStr << "<message>" + m_OSResult->general->message  + "</message>" << endl;
        }
        if(m_OSResult->general->serviceURI.length() > 0)
        {
            if (generalTagPrinted == false)
            {
                outStr << "<general>" << endl;
                generalTagPrinted = true;
            }
            outStr << "<serviceURI>" + m_OSResult->general->serviceURI + "</serviceURI>"  << endl;
        }
        if(m_OSResult->general->serviceName.length() > 0)
        {
            if (generalTagPrinted == false)
            {
                outStr << "<general>" << endl;
                generalTagPrinted = true;
            }
            outStr << "<serviceName>" + m_OSResult->general->serviceName + "</serviceName>"  << endl;
        }
        if(m_OSResult->general->instanceName.length() > 0)
        {
            if (generalTagPrinted == false)
            {
                outStr << "<general>" << endl;
                generalTagPrinted = true;
            }
            outStr << "<instanceName>" + m_OSResult->general->instanceName  + "</instanceName>" << endl;
        }
        if(m_OSResult->general->jobID.length() > 0)
        {
            if (generalTagPrinted == false)
            {
                outStr << "<general>" << endl;
                generalTagPrinted = true;
            }
            outStr << "<jobID>" + m_OSResult->general->jobID  + "</jobID>" << endl;
        }
        if(m_OSResult->general->solverInvoked.length() > 0)
        {
            if (generalTagPrinted == false)
            {
                outStr << "<general>" << endl;
                generalTagPrinted = true;
            }
            outStr << "<solverInvoked>" + m_OSResult->general->solverInvoked  + "</solverInvoked>" << endl;
        }
        if(m_OSResult->general->timeStamp.length() > 0)
        {
            if (generalTagPrinted == false)
            {
                outStr << "<general>" << endl;
                generalTagPrinted = true;
            }
            outStr << "<timeStamp>" + m_OSResult->general->timeStamp  + "</timeStamp>" << endl;
        }

        if(m_OSResult->general->otherResults != NULL)
        {
            if(m_OSResult->general->otherResults->numberOfOtherResults > 0)
            {
                if (generalTagPrinted == false)
                {
                    outStr << "<general>" << endl;
                    generalTagPrinted = true;
                }
                outStr << "<otherResults numberOfOtherResults=\"";
                outStr << m_OSResult->general->otherResults->numberOfOtherResults;
                outStr << "\">" << endl;
                for (int i=0; i < m_OSResult->general->otherResults->numberOfOtherResults; i++)
                {
                    outStr << "<other";
                    if (m_OSResult->general->otherResults->other[i]->name.length() > 0)
                    {
                        outStr << " name=";
                        outStr << writeStringData(m_OSResult->general->otherResults->other[i]->name);
                    }
                    if (m_OSResult->general->otherResults->other[i]->value.length() > 0)
                    {
                        outStr << " value=";
                        outStr << writeStringData(m_OSResult->general->otherResults->other[i]->value);
                    }
                    if (m_OSResult->general->otherResults->other[i]->description.length() > 0)
                    {
                        outStr << " description=";
                        outStr << writeStringData(m_OSResult->general->otherResults->other[i]->description);
                    }
                    outStr << " />" << endl;
                }
                outStr << "</otherResults>" << endl;;
            }
        }
        if (generalTagPrinted == true)
            outStr << "</general>" << endl;
    }


#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSrLwriter, ENUM_OUTPUT_LEVEL_trace, "output <system>");
#endif
    if(m_OSResult->system != NULL)
    {
        systemTagPrinted = false;
        if(m_OSResult->system->systemInformation.length() > 0)
        {
            if (systemTagPrinted == false)
            {
                outStr << "<system>" << endl;
                systemTagPrinted = true;
            }
            outStr << "<systemInformation>" + m_OSResult->system->systemInformation  + "</systemInformation>" << endl;
        }

        if(m_OSResult->system->availableDiskSpace != NULL)
        {
            if (systemTagPrinted == false)
            {
                outStr << "<system>" << endl;
                systemTagPrinted = true;
            }
            outStr << "<availableDiskSpace";
            if(m_OSResult->system->availableDiskSpace->unit.length() > 0)
            {
                outStr << " unit=\"";
                outStr << m_OSResult->system->availableDiskSpace->unit;
                outStr << "\"";
            }
            if(m_OSResult->system->availableDiskSpace->description.length() > 0)
            {
                outStr << " description=";
                outStr << writeStringData(m_OSResult->system->availableDiskSpace->description);
            }
            outStr << ">";
            outStr << os_dtoa_format(m_OSResult->system->availableDiskSpace->value);
            outStr << "</availableDiskSpace>" << endl;
        }

        if(m_OSResult->system->availableMemory != NULL)
        {
            if (systemTagPrinted == false)
            {
                outStr << "<system>" << endl;
                systemTagPrinted = true;
            }
            outStr << "<availableMemory";
            if(m_OSResult->system->availableMemory->unit.length() > 0)
            {
                outStr << " unit=\"";
                outStr << m_OSResult->system->availableMemory->unit;
                outStr << "\"";
            }
            if(m_OSResult->system->availableMemory->description.length() > 0)
            {
                outStr << " description=";
                outStr << writeStringData(m_OSResult->system->availableMemory->description);
            }
            outStr << ">";
            outStr << os_dtoa_format(m_OSResult->system->availableMemory->value);
            outStr << "</availableMemory>" << endl;
        }

        if(m_OSResult->system->availableCPUSpeed != NULL)
        {
            if (systemTagPrinted == false)
            {
                outStr << "<system>" << endl;
                systemTagPrinted = true;
            }
            outStr << "<availableCPUSpeed";
            if(m_OSResult->system->availableCPUSpeed->unit.length() > 0)
            {
                outStr << " unit=\"";
                outStr << m_OSResult->system->availableCPUSpeed->unit ;
                outStr << "\"";
            }
            if(m_OSResult->system->availableCPUSpeed->description.length() > 0)
            {
                outStr << " description=";
                outStr << writeStringData(m_OSResult->system->availableCPUSpeed->description);
            }
            outStr << ">";
            outStr << os_dtoa_format(m_OSResult->system->availableCPUSpeed->value);
            outStr << "</availableCPUSpeed>" << endl;
        }

        if(m_OSResult->system->availableCPUNumber != NULL)
        {
            if (systemTagPrinted == false)
            {
                outStr << "<system>" << endl;
                systemTagPrinted = true;
            }
            outStr << "<availableCPUNumber";
            if(m_OSResult->system->availableCPUNumber->description.length() > 0)
            {
                outStr << " description=";
                outStr << writeStringData(m_OSResult->system->availableCPUNumber->description);
            }
            outStr << ">";
            outStr << m_OSResult->system->availableCPUNumber->value;
            outStr << "</availableCPUNumber>" << endl;
        }

        if(m_OSResult->system->otherResults != NULL)
        {
            if(m_OSResult->system->otherResults->numberOfOtherResults > 0)
            {
                if (systemTagPrinted == false)
                {
                    outStr << "<system>" << endl;
                    systemTagPrinted = true;
                }
                outStr << "<otherResults numberOfOtherResults=\"";
                outStr << m_OSResult->system->otherResults->numberOfOtherResults;
                outStr << "\">" << endl;
                for (int i=0; i < m_OSResult->system->otherResults->numberOfOtherResults; i++)
                {
                    outStr << "<other";
                    if (m_OSResult->system->otherResults->other[i]->name.length() > 0)
                    {
                        outStr << " name=";
                        outStr << writeStringData(m_OSResult->system->otherResults->other[i]->name);
                    }
                    if (m_OSResult->system->otherResults->other[i]->value.length() > 0)
                    {
                        outStr << " value=";
                        outStr << writeStringData(m_OSResult->system->otherResults->other[i]->value);
                    }
                    if (m_OSResult->system->otherResults->other[i]->description.length() > 0)
                    {
                        outStr << " description=";
                        outStr << writeStringData(m_OSResult->system->otherResults->other[i]->description);
                    }
                    outStr << " />" << endl;
                }
                outStr << "</otherResults>" << endl;
            }
        }
        if (systemTagPrinted == true)
            outStr << "</system>" << endl;
    }


#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSrLwriter, ENUM_OUTPUT_LEVEL_trace, "output <service>");
#endif
    if(m_OSResult->service != NULL)
    {
        serviceTagPrinted = false;
        if(m_OSResult->service->currentState.length() > 0 && m_OSResult->service->currentState != "unknown")
        {
            if (serviceTagPrinted == false)
            {
                outStr << "<service>" << endl;
                serviceTagPrinted = true;
            }
            outStr << "<currentState>" << m_OSResult->service->currentState << "</currentState>" << endl;
        }
        if(m_OSResult->service->currentJobCount >= 0)
        {
            if (serviceTagPrinted == false)
            {
                outStr << "<service>" << endl;
                serviceTagPrinted = true;
            }
            outStr << "<currentJobCount>" << m_OSResult->service->currentJobCount << "</currentJobCount>" << endl;
        }
        if(m_OSResult->service->totalJobsSoFar >= 0)
        {
            if (serviceTagPrinted == false)
            {
                outStr << "<service>" << endl;
                serviceTagPrinted = true;
            }
            outStr << "<totalJobsSoFar>" << m_OSResult->service->totalJobsSoFar << "</totalJobsSoFar>" << endl;
        }
        if(m_OSResult->service->timeServiceStarted.length() > 0 && m_OSResult->service->timeServiceStarted != "1970-01-01T00:00:00-00:00")
        {
            if (serviceTagPrinted == false)
            {
                outStr << "<service>" << endl;
                serviceTagPrinted = true;
            }
            outStr << "<timeServiceStarted>" << m_OSResult->service->timeServiceStarted << "</timeServiceStarted>" << endl;
        }
        if(m_OSResult->service->serviceUtilization != -1.0)
        {
            if (serviceTagPrinted == false)
            {
                outStr << "<service>" << endl;
                serviceTagPrinted = true;
            }
            outStr << "<serviceUtilization>" << os_dtoa_format(m_OSResult->service->serviceUtilization) << "</serviceUtilization>" << endl;
        }

        if(m_OSResult->service->otherResults != NULL)
        {
            if(m_OSResult->service->otherResults->numberOfOtherResults > 0)
            {
                if (serviceTagPrinted == false)
                {
                    outStr << "<service>" << endl;
                    serviceTagPrinted = true;
                }
                outStr << "<otherResults numberOfOtherResults=\"";
                outStr << m_OSResult->service->otherResults->numberOfOtherResults;
                outStr << "\">" << endl;
                for (int i=0; i < m_OSResult->service->otherResults->numberOfOtherResults; i++)
                {
                    outStr << "<other";
                    if (m_OSResult->service->otherResults->other[i]->name.length() > 0)
                    {
                        outStr << " name=";
                        outStr << writeStringData(m_OSResult->service->otherResults->other[i]->name);
                    }
                    if (m_OSResult->service->otherResults->other[i]->value.length() > 0)
                    {
                        outStr << " value=";
                        outStr << writeStringData(m_OSResult->service->otherResults->other[i]->value);
                    }
                    if (m_OSResult->service->otherResults->other[i]->description.length() > 0)
                    {
                        outStr << " description=";
                        outStr << writeStringData(m_OSResult->service->otherResults->other[i]->description);
                    }
                    outStr << " />" << endl;
                }
                outStr << "</otherResults>" << endl;
            }
        }
        if (serviceTagPrinted == true)
            outStr << "</service>" << endl;
    }


#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSrLwriter, ENUM_OUTPUT_LEVEL_trace, "output <job>");
#endif
    if(m_OSResult->job != NULL)
    {
        jobTagPrinted = false;

        if(m_OSResult->job->status.length() > 0 && m_OSResult->job->status != "finished")
        {
            if (jobTagPrinted == false)
            {
                outStr << "<job>" << endl;
                jobTagPrinted = true;
            }
            outStr << "<status>" + m_OSResult->job->status  + "</status>" << endl;
        }
        if(m_OSResult->job->submitTime.length() > 0 && m_OSResult->job->submitTime != "1970-01-01T00:00:00-00:00")
        {
            if (jobTagPrinted == false)
            {
                outStr << "<job>" << endl;
                jobTagPrinted = true;
            }
            outStr << "<submitTime>" + m_OSResult->job->submitTime  + "</submitTime>" << endl;
        }
        if(m_OSResult->job->scheduledStartTime.length() > 0 && m_OSResult->job->scheduledStartTime != "1970-01-01T00:00:00-00:00")
        {
            if (jobTagPrinted == false)
            {
                outStr << "<job>" << endl;
                jobTagPrinted = true;
            }
            outStr << "<scheduledStartTime>" + m_OSResult->job->scheduledStartTime  + "</scheduledStartTime>" << endl;
        }
        if(m_OSResult->job->actualStartTime.length() > 0 && m_OSResult->job->actualStartTime != "1970-01-01T00:00:00-00:00")
        {
            if (jobTagPrinted == false)
            {
                outStr << "<job>" << endl;
                jobTagPrinted = true;
            }
            outStr << "<actualStartTime>" + m_OSResult->job->actualStartTime  + "</actualStartTime>" << endl;
        }
        if(m_OSResult->job->endTime.length() > 0 && m_OSResult->job->endTime != "1970-01-01T00:00:00-00:00")
        {
            if (jobTagPrinted == false)
            {
                outStr << "<job>" << endl;
                jobTagPrinted = true;
            }
            outStr << "<endTime>" + m_OSResult->job->endTime  + "</endTime>" << endl;
        }

        if (m_OSResult->job->timingInformation != NULL)
        {
            if (jobTagPrinted == false)
            {
                outStr << "<job>" << endl;
                jobTagPrinted = true;
            }
            outStr << "<timingInformation numberOfTimes=\"";
            outStr << m_OSResult->job->timingInformation->numberOfTimes << "\">" << endl;
            for (i=0; i<m_OSResult->job->timingInformation->numberOfTimes; i++)
            {
                outStr << "<time";
                if (m_OSResult->job->timingInformation->time[i]->type != "")
                    outStr << " type=\"" << m_OSResult->job->timingInformation->time[i]->type << "\"";
                if (m_OSResult->job->timingInformation->time[i]->unit != "")
                    outStr << " unit=\"" << m_OSResult->job->timingInformation->time[i]->unit << "\"";
                if (m_OSResult->job->timingInformation->time[i]->category != "")
                    outStr << " category=\"" << m_OSResult->job->timingInformation->time[i]->category << "\"";
                if (m_OSResult->job->timingInformation->time[i]->description != "")
                    outStr << " description=" << writeStringData(m_OSResult->job->timingInformation->time[i]->description);
                outStr << ">" << endl;
                outStr << os_dtoa_format(m_OSResult->job->timingInformation->time[i]->value);
                outStr << "</time>" << endl;
            }
            outStr << "</timingInformation>" << endl;
        }

        if(m_OSResult->job->usedDiskSpace != NULL)
        {
            if (jobTagPrinted == false)
            {
                outStr << "<job>" << endl;
                jobTagPrinted = true;
            }
            outStr << "<usedDiskSpace";
            if(m_OSResult->job->usedDiskSpace->unit.length() > 0)
            {
                outStr << " unit=\"";
                outStr << m_OSResult->job->usedDiskSpace->unit ;
                outStr << "\"";
            }
            if(m_OSResult->job->usedDiskSpace->description.length() > 0)
            {
                outStr << " description=";
                outStr << writeStringData(m_OSResult->job->usedDiskSpace->description);
            }
            outStr << ">";
            outStr << os_dtoa_format(m_OSResult->job->usedDiskSpace->value);
            outStr << "</usedDiskSpace>" << endl;
        }

        if(m_OSResult->job->usedMemory != NULL)
        {
            if (jobTagPrinted == false)
            {
                outStr << "<job>" << endl;
                jobTagPrinted = true;
            }
            outStr << "<usedMemory";
            if(m_OSResult->job->usedMemory->unit.length() > 0)
            {
                outStr << " unit=\"";
                outStr << m_OSResult->job->usedMemory->unit ;
                outStr << "\"";
            }
            if(m_OSResult->job->usedMemory->description.length() > 0)
            {
                outStr << " description=";
                outStr << writeStringData(m_OSResult->job->usedMemory->description);
            }
            outStr << ">";
            outStr << os_dtoa_format(m_OSResult->job->usedMemory->value);
            outStr << "</usedMemory>" << endl;
        }

        if(m_OSResult->job->usedCPUSpeed != NULL)
        {
            if (jobTagPrinted == false)
            {
                outStr << "<job>" << endl;
                jobTagPrinted = true;
            }
            outStr << "<usedCPUSpeed";
            if(m_OSResult->job->usedCPUSpeed->unit.length() > 0)
            {
                outStr << " unit=\"";
                outStr << m_OSResult->job->usedCPUSpeed->unit ;
                outStr << "\"";
            }
            if(m_OSResult->job->usedCPUSpeed->description.length() > 0)
            {
                outStr << " description=";
                outStr << writeStringData(m_OSResult->job->usedCPUSpeed->description);
            }
            outStr << ">";
            outStr << os_dtoa_format(m_OSResult->job->usedCPUSpeed->value);
            outStr << "</usedCPUSpeed>" << endl;
        }

        if(m_OSResult->job->usedCPUNumber != NULL)
        {
            if (jobTagPrinted == false)
            {
                outStr << "<job>" << endl;
                jobTagPrinted = true;
            }
            outStr << "<usedCPUNumber";
            if(m_OSResult->job->usedCPUNumber->description.length() > 0)
            {
                outStr << " description=";
                outStr << writeStringData(m_OSResult->job->usedCPUNumber->description);
            }
            outStr << ">";
            outStr << m_OSResult->job->usedCPUNumber->value;
            outStr << "</usedCPUNumber>" << endl;
        }

        if(m_OSResult->job->otherResults != NULL)
        {
            if(m_OSResult->job->otherResults->numberOfOtherResults > 0)
            {
                if (jobTagPrinted == false)
                {
                    outStr << "<job>" << endl;
                    jobTagPrinted = true;
                }
                outStr << "<otherResults numberOfOtherResults=\"";
                outStr << m_OSResult->job->otherResults->numberOfOtherResults;
                outStr << "\">" << endl;
                for (int i=0; i < m_OSResult->job->otherResults->numberOfOtherResults; i++)
                {
                    outStr << "<other";
                    if (m_OSResult->job->otherResults->other[i]->name.length() > 0)
                    {
                        outStr << " name=";
                        outStr << writeStringData(m_OSResult->job->otherResults->other[i]->name);
                    }
                    if (m_OSResult->job->otherResults->other[i]->value.length() > 0)
                    {
                        outStr << " value=";
                        outStr << writeStringData(m_OSResult->job->otherResults->other[i]->value);
                    }
                    if (m_OSResult->job->otherResults->other[i]->description.length() > 0)
                    {
                        outStr << " description=";
                        outStr << writeStringData(m_OSResult->job->otherResults->other[i]->description);
                    }
                    outStr << " />" << endl;
                }
                outStr << "</otherResults>"  << endl;
            }
        }
        if (jobTagPrinted == true)
            outStr << "</job>" << endl;
    }


#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSrLwriter, ENUM_OUTPUT_LEVEL_trace, "output <optimization>");
#endif
    if(m_OSResult->optimization != NULL)
    {
        outStr << "<optimization " ;
        outStr << "numberOfSolutions=\"";
        outStr << m_OSResult->optimization->numberOfSolutions ;
        outStr <<  "\"";
        if (m_OSResult->optimization->numberOfVariables >= 0)
        {
            outStr << " numberOfVariables=\"";
            outStr << m_OSResult->optimization->numberOfVariables ;
            outStr <<  "\"";
        }
        if (m_OSResult->optimization->numberOfConstraints >= 0)
        {
            outStr << " numberOfConstraints=\"";
            outStr << m_OSResult->optimization->numberOfConstraints ;
            outStr <<  "\"";
        }
        if (m_OSResult->optimization->numberOfObjectives >= 0)
        {
            outStr << " numberOfObjectives=\"";
            outStr << m_OSResult->optimization->numberOfObjectives ;
            outStr << "\"" ;
        }
        outStr << ">" << endl;
        // get solution information
        for(i = 0; i < m_OSResult->optimization->numberOfSolutions; i++)
        {
            if(m_OSResult->optimization->solution[i] != NULL)
            {
                outStr << "<solution" ;
                outStr << " targetObjectiveIdx=\"";
                outStr << m_OSResult->optimization->solution[i]->targetObjectiveIdx ;
                outStr << "\"" ;
                if (m_OSResult->optimization->solution[i]->targetObjectiveName.length() > 0)
                {
                    outStr << " targetObjectiveName=";
                    outStr <<  writeStringData(m_OSResult->optimization->solution[i]->targetObjectiveName);
                }
                if (m_OSResult->optimization->solution[i]->weightedObjectives)
                    outStr << " weightedObjectives=\"true\"";
                outStr << ">" << endl;
                if(m_OSResult->optimization->solution[i]->status != NULL)
                {
                    outStr << "<status";
                    if (m_OSResult->optimization->solution[i]->status->numberOfSubstatuses > 0)
                    {
                        outStr << " numberOfSubstatuses=\"";
                        outStr << m_OSResult->optimization->solution[i]->status->numberOfSubstatuses ;
                        outStr <<  "\"";
                    }
                    if(m_OSResult->optimization->solution[i]->status->type.length() > 0)
                    {
                        outStr << " type=\"";
                        outStr << m_OSResult->optimization->solution[i]->status->type;
                        outStr <<  "\"";
                    }
                    if(m_OSResult->optimization->solution[i]->status->description.length() > 0)
                    {
                        outStr << " description=";
                        outStr <<  writeStringData(m_OSResult->optimization->solution[i]->status->description);
                    }
                    outStr << ">" << endl;
                    for (int j=0; j < m_OSResult->optimization->solution[i]->status->numberOfSubstatuses; j++)
                    {
                        outStr << "<substatus";
                        if(m_OSResult->optimization->solution[i]->status->substatus[j]->type.length() > 0)
                        {
                            outStr << " type=\"";
                            outStr << m_OSResult->optimization->solution[i]->status->substatus[j]->type;
                            outStr <<  "\"";
                        }
                        if(m_OSResult->optimization->solution[i]->status->substatus[j]->description.length() > 0)
                        {
                            outStr << " description=";
                            outStr <<  writeStringData(m_OSResult->optimization->solution[i]->status->substatus[j]->description);
                        }
                        outStr << "/>" << endl;
                    }
                    outStr << "</status>" << endl;
                }

                if(m_OSResult->optimization->solution[i]->message != "")
                {
                    outStr << "<message>";
                    outStr << m_OSResult->optimization->solution[i]->message;
                    outStr << "</message>" << endl;
                }
                if(m_OSResult->optimization->solution[i]->variables != NULL)
                {
                    outStr << "<variables ";
                    if (m_OSResult->optimization->solution[i]->variables->numberOfOtherVariableResults > 0)
                        outStr << "numberOfOtherVariableResults=\"" << m_OSResult->optimization->solution[i]->variables->numberOfOtherVariableResults << "\"";
                    outStr << ">" << endl;
                    if(m_OSResult->optimization->solution[i]->variables->values != NULL)
                    {
#ifndef NDEBUG
                        osoutput->OSPrint(ENUM_OUTPUT_AREA_OSrLwriter, ENUM_OUTPUT_LEVEL_trace, 
                            "output <variables> <values>");
#endif
                        outStr << "<values numberOfVar=\"" << m_OSResult->optimization->solution[i]->variables->values->numberOfVar << "\">" << endl;
                        for(j = 0; j < m_OSResult->optimization->solution[i]->variables->values->numberOfVar; j++)
                        {
                            if(m_OSResult->optimization->solution[i]->variables->values->var[j] != NULL)
                            {
                                outStr << "<var";
                                outStr << " idx=\"";
                                outStr << m_OSResult->optimization->solution[i]->variables->values->var[j]->idx;
                                outStr <<  "\"";
                                if (m_OSResult->optimization->solution[i]->variables->values->var[j]->name != "")
                                    outStr << " name=" << writeStringData(m_OSResult->optimization->solution[i]->variables->values->var[j]->name);
                                outStr <<  ">";
                                outStr <<  os_dtoa_format( m_OSResult->optimization->solution[i]->variables->values->var[j]->value );
                                outStr << "</var>" << endl;
                            }
                        }
                        outStr << "</values>" << endl;
                    }

                    if(m_OSResult->optimization->solution[i]->variables->valuesString != NULL)
                    {
#ifndef NDEBUG
                        osoutput->OSPrint(ENUM_OUTPUT_AREA_OSrLwriter, ENUM_OUTPUT_LEVEL_trace, 
                            "output <variables> <valuesString>");
#endif
                        outStr << "<valuesString numberOfVar=\"" << m_OSResult->optimization->solution[i]->variables->valuesString->numberOfVar << "\">" << endl;
                        for(j = 0; j < m_OSResult->optimization->solution[i]->variables->valuesString->numberOfVar; j++)
                        {
                            if(m_OSResult->optimization->solution[i]->variables->valuesString->var[j] != NULL)
                            {
                                outStr << "<var";
                                outStr << " idx=\"";
                                outStr << m_OSResult->optimization->solution[i]->variables->valuesString->var[j]->idx;
                                outStr <<  "\"";
                                if (m_OSResult->optimization->solution[i]->variables->valuesString->var[j]->name != "")
                                    outStr << " name=" << writeStringData(m_OSResult->optimization->solution[i]->variables->valuesString->var[j]->name);
                                outStr <<  ">";
                                outStr <<  m_OSResult->optimization->solution[i]->variables->valuesString->var[j]->value;
                                outStr << "</var>" << endl;
                            }
                        }
                        outStr << "</valuesString>" << endl;
                    }

                    if(m_OSResult->optimization->solution[i]->variables->basisStatus != NULL)
                    {
#ifndef NDEBUG
                        osoutput->OSPrint(ENUM_OUTPUT_AREA_OSrLwriter, ENUM_OUTPUT_LEVEL_trace,
                            "output <variables> <basisStatus>");
#endif
                        outStr << "<basisStatus>" << endl;
                        outStr << writeBasisStatus(m_OSResult->optimization->solution[i]->variables->basisStatus, m_bWhiteSpace, m_bWriteBase64);
                        outStr << "</basisStatus>" << endl;
                    }

#ifndef NDEBUG
                    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSrLwriter, ENUM_OUTPUT_LEVEL_trace, "output <variables> <other>");
#endif
                    if(m_OSResult->optimization->solution[i]->variables->other != NULL)
                    {
                        if(m_OSResult->optimization->solution[i]->variables->numberOfOtherVariableResults > 0)
                        {
                            for(int k = 0; k < m_OSResult->optimization->solution[i]->variables->numberOfOtherVariableResults; k++)
                            {
                                outStr << "<other";
                                if (m_OSResult->optimization->solution[i]->variables->other[k]->numberOfVar > 0)
                                {
                                    outStr << " numberOfVar=\"";
                                    outStr << m_OSResult->optimization->solution[i]->variables->other[k]->numberOfVar;
                                    outStr << "\"" ;
                                }
                                else if(m_OSResult->optimization->solution[i]->variables->other[k]->numberOfEnumerations > 0)
                                {
                                    outStr << " numberOfEnumerations=\"";
                                    outStr << m_OSResult->optimization->solution[i]->variables->other[k]->numberOfEnumerations;
                                    outStr << "\"" ;
                                }
                                outStr << " name=";
                                outStr << writeStringData(m_OSResult->optimization->solution[i]->variables->other[k]->name);
                                if (m_OSResult->optimization->solution[i]->variables->other[k]->value != "")
                                {
                                    outStr << " value=\"";
                                    outStr << m_OSResult->optimization->solution[i]->variables->other[k]->value;
                                    outStr << "\"" ;
                                }
                                if (m_OSResult->optimization->solution[i]->variables->other[k]->type != "")
                                {
                                    outStr << " type=\"";
                                    outStr << m_OSResult->optimization->solution[i]->variables->other[k]->type;
                                    outStr << "\"" ;
                                }
                                if (m_OSResult->optimization->solution[i]->variables->other[k]->description != "")
                                {
                                    outStr << " description=";
                                    outStr << writeStringData(m_OSResult->optimization->solution[i]->variables->other[k]->description);
                                }
                                if (m_OSResult->optimization->solution[i]->variables->other[k]->varType != "")
                                {
                                    outStr << " varType=\"";
                                    outStr << m_OSResult->optimization->solution[i]->variables->other[k]->varType;
                                    outStr << "\"" ;
                                }
                                if (m_OSResult->optimization->solution[i]->variables->other[k]->enumType != "")
                                {
                                    outStr << " enumType=\"";
                                    outStr << m_OSResult->optimization->solution[i]->variables->other[k]->enumType;
                                    outStr << "\"" ;
                                }
                                outStr << ">" << endl;
                                if(m_OSResult->optimization->solution[i]->variables->other[k]->numberOfVar > 0)
                                {
                                    for(j = 0; j < m_OSResult->optimization->solution[i]->variables->other[k]->numberOfVar; j++)
                                    {
                                        outStr << "<var";
                                        outStr << " idx=\"";
                                        outStr << m_OSResult->optimization->solution[i]->variables->other[k]->var[j]->idx ;
                                        outStr <<  "\"";
                                        if (m_OSResult->optimization->solution[i]->variables->other[k]->var[j]->name != "")
                                            outStr << " name=" << writeStringData(m_OSResult->optimization->solution[i]->variables->other[k]->var[j]->name);
                                        outStr <<  ">";
                                        outStr << m_OSResult->optimization->solution[i]->variables->other[k]->var[j]->value;
                                        outStr << "</var>" << endl;
                                    }
                                }
                                else if (m_OSResult->optimization->solution[i]->variables->other[k]->numberOfEnumerations > 0)
                                {
                                    for(j = 0; j < m_OSResult->optimization->solution[i]->variables->other[k]->numberOfEnumerations; j++)
                                    {
                                        outStr << writeOtherOptionOrResultEnumeration(m_OSResult->optimization->solution[i]->variables->other[k]->enumeration[j],
                                                                              m_bWhiteSpace, m_bWriteBase64);
                                    }
                                }
                                outStr << "</other>" << endl;
                            }
                        }
                    } // end of if on other variables
                    outStr << "</variables>" << endl;
                }
                if(m_OSResult->optimization->solution[i]->objectives != NULL)
                {
                    outStr << "<objectives ";
                    if (m_OSResult->optimization->solution[i]->objectives->numberOfOtherObjectiveResults > 0)
                        outStr << "numberOfOtherObjectiveResults=\"" << m_OSResult->optimization->solution[i]->objectives->numberOfOtherObjectiveResults << "\"";
                    outStr << ">" << endl;
#ifndef NDEBUG
                    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSrLwriter, ENUM_OUTPUT_LEVEL_trace, 
                        "output <objectives> <values>");
#endif
                    if(m_OSResult->optimization->solution[i]->objectives->values != NULL)
                    {
                        outStr << "<values numberOfObj=\"" << m_OSResult->optimization->solution[i]->objectives->values->numberOfObj << "\">" << endl;
                        for(j = 0; j < m_OSResult->optimization->solution[i]->objectives->values->numberOfObj; j++)
                        {
                            if(m_OSResult->optimization->solution[i]->objectives->values->obj[j] != NULL)
                            {
                                outStr << "<obj";
                                outStr << " idx=\"";
                                outStr << m_OSResult->optimization->solution[i]->objectives->values->obj[j]->idx; //-(1 + j) ;
                                outStr <<  "\"";
                                if (m_OSResult->optimization->solution[i]->objectives->values->obj[j]->name != "")
                                    outStr << " name=" << writeStringData(m_OSResult->optimization->solution[i]->objectives->values->obj[j]->name);
                                outStr <<  ">";
                                outStr <<  os_dtoa_format( m_OSResult->optimization->solution[i]->objectives->values->obj[j]->value);
                                outStr << "</obj>" << endl;
                            }
                        }

                        outStr << "</values>" << endl;
                    }

                    if(m_OSResult->optimization->solution[i]->objectives->basisStatus != NULL)
                    {
#ifndef NDEBUG
                        osoutput->OSPrint(ENUM_OUTPUT_AREA_OSrLwriter, ENUM_OUTPUT_LEVEL_trace,
                            "output <objectives> <basisStatus>");
#endif
                        outStr << "<basisStatus>" << endl;
                        outStr << writeBasisStatus(m_OSResult->optimization->solution[i]->objectives->basisStatus, m_bWhiteSpace, m_bWriteBase64);
                        outStr << "</basisStatus>" << endl;
                    }

#ifndef NDEBUG
                    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSrLwriter, ENUM_OUTPUT_LEVEL_trace, 
                        "output <objectives> <other>");
#endif
                    if(m_OSResult->optimization->solution[i]->objectives->other != NULL)
                    {
                        if(m_OSResult->optimization->solution[i]->objectives->numberOfOtherObjectiveResults > 0)
                        {
                            for(int k = 0; k < m_OSResult->optimization->solution[i]->objectives->numberOfOtherObjectiveResults; k++)
                            {
                                outStr << "<other" ;
                                if (m_OSResult->optimization->solution[i]->objectives->other[k]->numberOfObj > 0)
                                {
                                    outStr << " numberOfObj=\"";
                                    outStr << m_OSResult->optimization->solution[i]->objectives->other[k]->numberOfObj;
                                    outStr << "\"" ;
                                }
                                else if(m_OSResult->optimization->solution[i]->objectives->other[k]->numberOfEnumerations > 0)
                                {
                                    outStr << " numberOfEnumerations=\"";
                                    outStr << m_OSResult->optimization->solution[i]->objectives->other[k]->numberOfEnumerations;
                                    outStr << "\"" ;
                                }
                                if (m_OSResult->optimization->solution[i]->objectives->other[k]->name != "")
                                {
                                    outStr << " name=";
                                    \
                                    outStr << writeStringData(m_OSResult->optimization->solution[i]->objectives->other[k]->name);
                                };
                                if (m_OSResult->optimization->solution[i]->objectives->other[k]->value != "")
                                {
                                    outStr << " value=\"";
                                    \
                                    outStr << m_OSResult->optimization->solution[i]->objectives->other[k]->value;
                                    outStr << "\"" ;
                                };
                                if (m_OSResult->optimization->solution[i]->objectives->other[k]->type != "")
                                {
                                    outStr << " type=\"";
                                    outStr << m_OSResult->optimization->solution[i]->objectives->other[k]->type;
                                    outStr << "\"" ;
                                }
                                if (m_OSResult->optimization->solution[i]->objectives->other[k]->description != "")
                                {
                                    outStr << " description=";
                                    outStr << writeStringData(m_OSResult->optimization->solution[i]->objectives->other[k]->description);
                                };
                                if (m_OSResult->optimization->solution[i]->objectives->other[k]->objType != "")
                                {
                                    outStr << " objType=\"";
                                    outStr << m_OSResult->optimization->solution[i]->objectives->other[k]->objType;
                                    outStr << "\"" ;
                                }
                                if (m_OSResult->optimization->solution[i]->objectives->other[k]->enumType != "")
                                {
                                    outStr << " enumType=\"";
                                    outStr << m_OSResult->optimization->solution[i]->objectives->other[k]->enumType;
                                    outStr << "\"" ;
                                }
                                outStr <<  ">" << endl;
                                if(m_OSResult->optimization->solution[i]->objectives->other[k]->numberOfObj > 0)
                                {
                                    for(j = 0; j < m_OSResult->optimization->solution[i]->objectives->other[k]->numberOfObj; j++)
                                    {
                                        outStr << "<obj";
                                        outStr << " idx=\"";
                                        outStr << m_OSResult->optimization->solution[i]->objectives->other[k]->obj[j]->idx;
                                        outStr <<  "\"";
                                        if (m_OSResult->optimization->solution[i]->objectives->other[k]->obj[j]->name != "")
                                            outStr << " name=" << writeStringData(m_OSResult->optimization->solution[i]->objectives->other[k]->obj[j]->name);
                                        outStr <<  ">";
                                        outStr <<   m_OSResult->optimization->solution[i]->objectives->other[k]->obj[j]->value;
                                        outStr << "</obj>" << endl;
                                    }
                                }
                                else if (m_OSResult->optimization->solution[i]->objectives->other[k]->numberOfEnumerations > 0)
                                {
                                    for(j = 0; j < m_OSResult->optimization->solution[i]->objectives->other[k]->numberOfEnumerations; j++)
                                    {
                                        outStr << writeOtherOptionOrResultEnumeration(m_OSResult->optimization->solution[i]->objectives->other[k]->enumeration[j],
                                                                              m_bWhiteSpace, m_bWriteBase64);
                                    }
                                }
                                outStr << "</other>" << endl;
                            }
                        }
                    } // end of if on other objectives
                    outStr << "</objectives>" << endl;
                }

                if(m_OSResult->optimization->solution[i]->constraints != NULL)
                {
                    outStr << "<constraints ";
                    if (m_OSResult->optimization->solution[i]->constraints->numberOfOtherConstraintResults > 0)
                        outStr << "numberOfOtherConstraintResults=\"" << m_OSResult->optimization->solution[i]->constraints->numberOfOtherConstraintResults << "\"";
                    outStr << ">" << endl;
#ifndef NDEBUG
                    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSrLwriter, ENUM_OUTPUT_LEVEL_trace, 
                        "output <constraints> <dualValues>");
#endif
                    if(m_OSResult->optimization->solution[i]->constraints->dualValues != NULL)
                    {
                        outStr << "<dualValues numberOfCon=\"" << m_OSResult->optimization->solution[i]->constraints->dualValues->numberOfCon << "\">" << endl;
                        for(j = 0; j < m_OSResult->optimization->solution[i]->constraints->dualValues->numberOfCon; j++)
                        {
                            if(m_OSResult->optimization->solution[i]->constraints->dualValues->con[j] != NULL)
                            {
                                outStr << "<con";
                                outStr << " idx=\"";
                                outStr <<  m_OSResult->optimization->solution[i]->constraints->dualValues->con[j]->idx;
                                outStr <<  "\"";
                                if (m_OSResult->optimization->solution[i]->constraints->dualValues->con[j]->name != "")
                                    outStr << " name=" << writeStringData(m_OSResult->optimization->solution[i]->constraints->dualValues->con[j]->name);
                                outStr <<  ">";
                                outStr <<  os_dtoa_format( m_OSResult->optimization->solution[i]->constraints->dualValues->con[j]->value);
                                outStr << "</con>" << endl;
                            }
                        }
                        outStr << "</dualValues>" << endl;
                    }

                    if(m_OSResult->optimization->solution[i]->constraints->basisStatus != NULL)
                    {
#ifndef NDEBUG
                        osoutput->OSPrint(ENUM_OUTPUT_AREA_OSrLwriter, ENUM_OUTPUT_LEVEL_trace,
                            "output <constraints> <basisStatus>");
#endif
                        outStr << "<basisStatus>" << endl;
                        outStr << writeBasisStatus(m_OSResult->optimization->solution[i]->constraints->basisStatus, m_bWhiteSpace, m_bWriteBase64);
                        outStr << "</basisStatus>" << endl;
                    }

#ifndef NDEBUG
                    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSrLwriter, ENUM_OUTPUT_LEVEL_trace,
                        "output <constraints> <other>");
#endif
                    if(m_OSResult->optimization->solution[i]->constraints->other != NULL)
                    {
                        if(m_OSResult->optimization->solution[i]->constraints->numberOfOtherConstraintResults > 0)
                        {
                            for(int k = 0; k < m_OSResult->optimization->solution[i]->constraints->numberOfOtherConstraintResults; k++)
                            {
                                outStr << "<other";
                                if (m_OSResult->optimization->solution[i]->constraints->other[k]->numberOfCon > 0)
                                {
                                    outStr << " numberOfCon=\"";
                                    outStr << m_OSResult->optimization->solution[i]->constraints->other[k]->numberOfCon;
                                    outStr << "\"";
                                }
                                else if(m_OSResult->optimization->solution[i]->constraints->other[k]->numberOfEnumerations > 0)
                                {
                                    outStr << " numberOfEnumerations=\"";
                                    outStr << m_OSResult->optimization->solution[i]->constraints->other[k]->numberOfEnumerations;
                                    outStr << "\"";
                                }
                                outStr << " name=";
                                \
                                outStr << writeStringData(m_OSResult->optimization->solution[i]->constraints->other[k]->name);
                                if (m_OSResult->optimization->solution[i]->constraints->other[k]->value != "")
                                {
                                    outStr << " value=\"";
                                    \
                                    outStr << m_OSResult->optimization->solution[i]->constraints->other[k]->value;
                                    outStr << "\"" ;
                                };
                                if (m_OSResult->optimization->solution[i]->constraints->other[k]->type != "")
                                {
                                    outStr << " type=\"";
                                    outStr << m_OSResult->optimization->solution[i]->constraints->other[k]->type;
                                    outStr << "\"" ;

                                }
                                if (m_OSResult->optimization->solution[i]->constraints->other[k]->description != "")
                                {
                                    outStr << " description=";
                                    outStr << writeStringData(m_OSResult->optimization->solution[i]->constraints->other[k]->description);
                                };
                                if (m_OSResult->optimization->solution[i]->constraints->other[k]->conType != "")
                                {
                                    outStr << " conType=\"";
                                    outStr << m_OSResult->optimization->solution[i]->constraints->other[k]->conType;
                                    outStr << "\"" ;
                                }
                                if (m_OSResult->optimization->solution[i]->constraints->other[k]->enumType != "")
                                {
                                    outStr << " enumType=\"";
                                    outStr << m_OSResult->optimization->solution[i]->constraints->other[k]->enumType;
                                    outStr << "\"" ;
                                }
                                outStr <<  ">" << endl;
                                if(m_OSResult->optimization->solution[i]->constraints->other[k]->numberOfCon > 0)
                                {
                                    for(j = 0; j < m_OSResult->optimization->solution[i]->constraints->other[k]->numberOfCon; j++)
                                    {
                                        outStr << "<con";
                                        outStr << " idx=\"";
                                        outStr << m_OSResult->optimization->solution[i]->constraints->other[k]->con[j]->idx;
                                        outStr <<  "\"";
                                        if (m_OSResult->optimization->solution[i]->constraints->other[k]->con[j]->name != "")
                                            outStr << " name=" << writeStringData(m_OSResult->optimization->solution[i]->constraints->other[k]->con[j]->name);
                                        outStr <<  ">";
                                        outStr <<  m_OSResult->optimization->solution[i]->constraints->other[k]->con[j]->value;
                                        outStr << "</con>" << endl;
                                    }
                                }
                                else if (m_OSResult->optimization->solution[i]->constraints->other[k]->numberOfEnumerations > 0)
                                {
                                    for(j = 0; j < m_OSResult->optimization->solution[i]->constraints->other[k]->numberOfEnumerations; j++)
                                    {
                                        outStr << writeOtherOptionOrResultEnumeration(m_OSResult->optimization->solution[i]->constraints->other[k]->enumeration[j],
                                                                              m_bWhiteSpace, m_bWriteBase64);
                                    }
                                }
                                outStr << "</other>" << endl;
                            }
                        }
                    } // end of if on other constraints
                    outStr << "</constraints>" << endl;
                }// end of <constraints> element

                if(m_OSResult->optimization->solution[i]->matrixProgramming != NULL)
                {
#ifndef NDEBUG
                    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSrLwriter, ENUM_OUTPUT_LEVEL_trace, 
                        "output <matrixProgramming>");
#endif
                    outStr << "<matrixProgramming";
                    if (m_OSResult->optimization->solution[i]->matrixProgramming
                                  ->numberOfOtherMatrixProgrammingResults > 0)
                        outStr << " numberOfOtherMatrixProgrammingResults=\"" 
                               << m_OSResult->optimization->solution[i]->matrixProgramming
                                            ->numberOfOtherMatrixProgrammingResults << "\"";
                    outStr << ">" << endl;

                    if(m_OSResult->optimization->solution[i]->matrixProgramming->matrixVariables != NULL)
                    {
                        MatrixVariableSolution* tmpVar
                            = m_OSResult->optimization->solution[i]->matrixProgramming->matrixVariables;
#ifndef NDEBUG
                        osoutput->OSPrint(ENUM_OUTPUT_AREA_OSrLwriter, ENUM_OUTPUT_LEVEL_trace, 
                            "output <matrixVariables>");
#endif
                        outStr << "<matrixVariables";
                        if (tmpVar->numberOfOtherMatrixVariableResults > 0)
                            outStr << " numberOfOtherMatrixVariableResults=\"" 
                                   << tmpVar->numberOfOtherMatrixVariableResults << "\"";
                        outStr << ">" << endl;

                        if (tmpVar->values != NULL)
                        {
                            outStr << "<values numberOfMatrixVar=\"" 
                                   << tmpVar->values->numberOfMatrixVar << "\">" << std::endl;
                            for (int var=0; var < tmpVar->values->numberOfMatrixVar; var++)
                                outStr << tmpVar->values->matrixVar[var]->getMatrixNodeInXML();
                        }
                        outStr << "</values>" << endl;
                        if (tmpVar->numberOfOtherMatrixVariableResults > 0 &&
                            tmpVar->other != NULL)
                        {
                            for (int j=0; j < tmpVar->numberOfOtherMatrixVariableResults; j++)
                            {
                                outStr << "<other name=\"" << tmpVar->other[j]->name << "\"";
                                if (tmpVar->other[j]->description != "")
                                    outStr << " description=\"" << tmpVar->other[j]->description << "\""; 
                                if (tmpVar->other[j]->value != "")
                                    outStr << " value=\"" << tmpVar->other[j]->value << "\""; 
                                if (tmpVar->other[j]->type != "")
                                    outStr << " type=\"" << tmpVar->other[j]->type << "\""; 
                                if (tmpVar->other[j]->solver != "")
                                    outStr << " solver=\"" << tmpVar->other[j]->solver << "\""; 
                                if (tmpVar->other[j]->category != "")
                                    outStr << " category=\"" << tmpVar->other[j]->category << "\""; 
                                if (tmpVar->other[j]->numberOfMatrixVar != 0)
                                    outStr << " numberOfMatrixVar=\"" 
                                           << tmpVar->other[j]->numberOfMatrixVar << "\""; 
                                if (tmpVar->other[j]->matrixType != "")
                                    outStr << " matrixType=\"" << tmpVar->other[j]->matrixType << "\""; 
                                if (tmpVar->other[j]->numberOfEnumerations != 0)
                                    outStr << " numberOfEnumerations=\"" 
                                           << tmpVar->other[j]->numberOfEnumerations << "\""; 
                                if (tmpVar->other[j]->enumType != "")
                                    outStr << " enumType=\"" << tmpVar->other[j]->enumType << "\""; 

                                if (tmpVar->other[j]->numberOfMatrixVar == 0 &&
                                    tmpVar->other[j]->numberOfEnumerations == 0)
                                {
                                    outStr << "/>" << endl;
                                }
                                else
                                {
                                    outStr << ">" << endl;
                                    if (tmpVar->other[j]->numberOfMatrixVar > 0)
                                        for (int var=0; var < tmpVar->other[j]->numberOfMatrixVar; var++)
                                            outStr << tmpVar->other[j]->matrixVar[var]->getMatrixNodeInXML();

                                    if (tmpVar->other[j]->numberOfEnumerations > 0)
                                    for(int k = 0; k < tmpVar->other[j]->numberOfEnumerations; k++)
                                    {
                                        outStr << writeOtherOptionOrResultEnumeration(
                                                        tmpVar->other[j]->enumeration[j],
                                                        m_bWhiteSpace, m_bWriteBase64);
                                    }

                                    outStr << "</other>" << endl;
                                }
                            }
                        }
                        outStr << "</matrixVariables>" << endl;
                    }
                    outStr << "</matrixProgramming>" << endl;
                }

#ifndef NDEBUG
                osoutput->OSPrint(ENUM_OUTPUT_AREA_OSrLwriter, ENUM_OUTPUT_LEVEL_trace, "output <otherSolutionResults>");
#endif
                if (m_OSResult->optimization->solution[i]->otherSolutionResults != NULL)
                {
                    outStr << "<otherSolutionResults numberOfOtherSolutionResults=\"";
                    outStr << m_OSResult->optimization->solution[i]->otherSolutionResults->numberOfOtherSolutionResults;
                    outStr << "\">" << std::endl;
                    for(int k = 0; k < m_OSResult->optimization->solution[i]->otherSolutionResults->numberOfOtherSolutionResults; k++)
                    {
                        outStr << "<otherSolutionResult";
                        outStr << " name=";
                        outStr << writeStringData(m_OSResult->optimization->solution[i]->otherSolutionResults->otherSolutionResult[k]->name);
                        outStr << " value=";
                        outStr << writeStringData(m_OSResult->optimization->solution[i]->otherSolutionResults->otherSolutionResult[k]->value);
                        outStr << " numberOfItems=\"";
                        outStr << m_OSResult->optimization->solution[i]->otherSolutionResults->otherSolutionResult[k]->numberOfItems;
                        outStr << "\"";
                        if (m_OSResult->optimization->solution[i]->otherSolutionResults->otherSolutionResult[k]->category != "")
                            outStr << " category=\"" << m_OSResult->optimization->solution[i]->otherSolutionResults->otherSolutionResult[k]->category << "\"";
                        if (m_OSResult->optimization->solution[i]->otherSolutionResults->otherSolutionResult[k]->description != "")
                            outStr << " description=" << writeStringData(m_OSResult->optimization->solution[i]->otherSolutionResults->otherSolutionResult[k]->description);
                        outStr << ">" << std::endl;
                        for(int j = 0; j < m_OSResult->optimization->solution[i]->otherSolutionResults->otherSolutionResult[k]->numberOfItems; j++)
                            outStr << "<item>" << m_OSResult->optimization->solution[i]->otherSolutionResults->otherSolutionResult[k]->item[j] << "</item>" << std::endl;
                        outStr << "</otherSolutionResult>" << std::endl;
                    }
                    outStr << "</otherSolutionResults>" << std::endl;
                }
                outStr << "</solution>" << endl;
            } // end if solution not NULL
        } // end for loop(i=0..numberOfSolutions)


#ifndef NDEBUG
        osoutput->OSPrint(ENUM_OUTPUT_AREA_OSrLwriter, ENUM_OUTPUT_LEVEL_trace, "output <otherSolverOutput>");
#endif
        if (m_OSResult->optimization->otherSolverOutput != NULL)
//			if (m_OSResult->optimization->otherSolverOutput->numberOfSolverOutputs > 0)
        {
            outStr << "<otherSolverOutput numberOfSolverOutputs=\"";
            outStr << m_OSResult->optimization->otherSolverOutput->numberOfSolverOutputs;
            outStr << "\">" << std::endl;
            for(int k = 0; k < m_OSResult->optimization->otherSolverOutput->numberOfSolverOutputs; k++)
            {
                outStr << "<solverOutput";
                outStr << " name=\"";
                outStr << m_OSResult->optimization->otherSolverOutput->solverOutput[k]->name;
                outStr << "\"";
                outStr << " numberOfItems=\"";
                outStr << m_OSResult->optimization->otherSolverOutput->solverOutput[k]->numberOfItems;
                outStr << "\"";
                if (m_OSResult->optimization->otherSolverOutput->solverOutput[k]->category != "")
                    outStr << " category=\"" << m_OSResult->optimization->otherSolverOutput->solverOutput[k]->category << "\"";
                if (m_OSResult->optimization->otherSolverOutput->solverOutput[k]->description != "")
                    outStr << " description=" << writeStringData(m_OSResult->optimization->otherSolverOutput->solverOutput[k]->description);
                outStr << ">" << std::endl;
                for(int j = 0; j < m_OSResult->optimization->otherSolverOutput->solverOutput[k]->numberOfItems; j++)
                {
                    outStr << "<item>" << m_OSResult->optimization->otherSolverOutput->solverOutput[k]->item[j] << "</item>" << std::endl;
                }
                outStr << "</solverOutput>" << std::endl;
            }
            outStr << "</otherSolverOutput>" << std::endl;
        }

        outStr << "</optimization>" << endl;
    } // end if (optimization != NULL)
    outStr << "</osrl>" << endl ;
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSrLwriter, ENUM_OUTPUT_LEVEL_trace, "done");
#endif
    return outStr.str();
}// end writeOSrL


