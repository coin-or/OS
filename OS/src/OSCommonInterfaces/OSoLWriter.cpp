/* $Id$ */
/** @file OSoLWriter.cpp
 * 
 *
 * @author  Horand Gassmann, Jun Ma, Kipp Martin, 
 *
 * \remarks
 * Copyright (C) 2005-2011, Horand Gassmann, Jun Ma, Kipp Martin,
 * Dalhousie University, Northwestern University, and the University of Chicago.
 * All Rights Reserved.
 * This software is licensed under the Eclipse Public License. 
 * Please see the accompanying LICENSE file in root directory for terms.
 * 
 */

//#define DEBUG
 
#include "OSoLWriter.h"
#include "OSOption.h"
#include "OSgLWriter.h"
#include "OSGeneral.h"
#include "OSParameters.h"
#include "OSConfig.h"
#include "OSBase64.h"
#include "OSMathUtil.h"
#include <sstream>   
#include <iostream>  
#include <stdio.h>

using std::cout;
using std::endl;
using std::ostringstream;

OSoLWriter::OSoLWriter( ) {	 
	m_bWriteBase64 = false;
	m_bWhiteSpace = false;
}

OSoLWriter::~OSoLWriter(){
}


/*char* OSoLWriter::writeOSoLWrap( OSOption *theosoption){
	std::string sTmp = writeOSoL( theosoption);
	char *ch;
    ch = new char[sTmp.size() + 1];
    strcpy(ch, sTmp.c_str());
	return ch;
}
*/

 
std::string OSoLWriter::writeOSoL( OSOption *theosoption)
{	m_OSOption = theosoption;
	std::ostringstream outStr;  
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

	int i, j;
	bool generalTagPrinted;
	bool systemTagPrinted;
	bool serviceTagPrinted;
	bool jobTagPrinted;
#ifdef DEBUG
	cout << "in OSoLWriter" << endl;
#endif

	if(m_OSOption == NULL)  return outStr.str(); 
	outStr << "<?xml version=\"1.0\" encoding=\"UTF-8\"?>" ; 
	outStr << "<?xml-stylesheet type=\"text/xsl\" href=\"";
	outStr << xsltDir;
	outStr << "OSoL.xslt\"?>";
	outStr << endl;
	outStr << "<osol xmlns=\"os.optimizationservices.org\"   xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\" ";
	outStr << "xsi:schemaLocation=\"os.optimizationservices.org http://www.optimizationservices.org/schemas/";
	outStr << OS_SCHEMA_VERSION;
	outStr << "/OSoL.xsd\" >" ;
	outStr << endl;

#ifdef DEBUG
	cout << "output <optionHeader>" << endl;
#endif
	if(m_OSOption->optionHeader != NULL)
	{
		if (m_OSOption->optionHeader->name        != "" ||
			m_OSOption->optionHeader->source      != "" ||
			m_OSOption->optionHeader->description != "" ||
			m_OSOption->optionHeader->fileCreator != "" ||
			m_OSOption->optionHeader->licence     != "" )
		{
			outStr << "<optionHeader>" << endl;
			outStr << writeGeneralFileHeader(m_OSOption->optionHeader, true);
			outStr << "</optionHeader>" << endl;
		}
	}

#ifdef DEBUG
	cout << "output <general>" << endl;
#endif
	if(m_OSOption->general != NULL)
	{	
		generalTagPrinted = false;
		if (m_OSOption->general->serviceURI != "")
		{
			if (generalTagPrinted == false)
			{	
				outStr << "<general>" << endl;
				generalTagPrinted = true;
			}
			outStr << "<serviceURI>" << m_OSOption->general->serviceURI << "</serviceURI>" << endl;
		}
		if (m_OSOption->general->serviceName != "")
		{
			if (generalTagPrinted == false)
			{	
				outStr << "<general>" << endl;
				generalTagPrinted = true;
			}
			outStr << "<serviceName>" << m_OSOption->general->serviceName << "</serviceName>" << endl;
		}
		if (m_OSOption->general->instanceName != "")
		{
			if (generalTagPrinted == false)
			{	
				outStr << "<general>" << endl;
				generalTagPrinted = true;
			}
			outStr << "<instanceName>" << m_OSOption->general->instanceName << "</instanceName>" << endl;
		}
		if (m_OSOption->general->instanceLocation != NULL)
		{
			if (generalTagPrinted == false)
			{	
				outStr << "<general>" << endl;
				generalTagPrinted = true;
			}
			if (m_OSOption->general->instanceLocation->locationType == "")
			{	outStr << "<instanceLocation>";
			}
			else 
			{	outStr << "<instanceLocation locationType=\"" << m_OSOption->general->instanceLocation->locationType << "\">";
			};
			outStr << m_OSOption->general->instanceLocation->value << "</instanceLocation>" << endl;
		}
		if (m_OSOption->general->jobID != "")
		{
			if (generalTagPrinted == false)
			{	
				outStr << "<general>" << endl;
				generalTagPrinted = true;
			}
			outStr << "<jobID>" << m_OSOption->general->jobID << "</jobID>" << endl;
		}
		if (m_OSOption->general->solverToInvoke != "")
		{
			if (generalTagPrinted == false)
			{	
				outStr << "<general>" << endl;
				generalTagPrinted = true;
			}
			outStr << "<solverToInvoke>" << m_OSOption->general->solverToInvoke << "</solverToInvoke>" << endl;
		}
		if (m_OSOption->general->license != "")
		{
			if (generalTagPrinted == false)
			{	
				outStr << "<general>" << endl;
				generalTagPrinted = true;
			}
			outStr << "<license>" << m_OSOption->general->license << "</license>" << endl;
		}
		if (m_OSOption->general->userName != "")
		{
			if (generalTagPrinted == false)
			{	
				outStr << "<general>" << endl;
				generalTagPrinted = true;
			}
			outStr << "<userName>" << m_OSOption->general->userName << "</userName>" << endl;
		}
		if (m_OSOption->general->password != "")
		{
			if (generalTagPrinted == false)
			{	
				outStr << "<general>" << endl;
				generalTagPrinted = true;
			}
			outStr << "<password>" << m_OSOption->general->password << "</password>" << endl;
		}
		if (m_OSOption->general->contact != NULL)
		{
			if (generalTagPrinted == false)
			{	
				outStr << "<general>" << endl;
				generalTagPrinted = true;
			}
			if (m_OSOption->general->contact->transportType == "")
			{	outStr << "<contact>";
			}
			else 
			{	outStr << "<contact transportType=\"" << m_OSOption->general->contact->transportType << "\">";
			};
			outStr << m_OSOption->general->contact->value << "</contact>" << endl;
		}
		if (m_OSOption->general->otherOptions != NULL)
		{
			if (generalTagPrinted == false)
			{	
				outStr << "<general>" << endl;
				generalTagPrinted = true;
			}
//			if (m_OSOption->general->otherOptions->numberOfOtherOptions > 0)
			{	outStr << "<otherOptions numberOfOtherOptions=\""; 
				outStr << m_OSOption->general->otherOptions->numberOfOtherOptions << "\">" << endl;
				for (int i=0; i < m_OSOption->general->otherOptions->numberOfOtherOptions; i++)
				{	outStr << "<other name=\"" << m_OSOption->general->otherOptions->other[i]->name << "\"";
					if (m_OSOption->general->otherOptions->other[i]->value != "")
						outStr << " value=\"" << m_OSOption->general->otherOptions->other[i]->value << "\"";
					if (m_OSOption->general->otherOptions->other[i]->description != "")
						outStr << " description=\"" << m_OSOption->general->otherOptions->other[i]->description << "\"";
					outStr << "/>" << endl;
				}
				outStr << "</otherOptions>" << endl;
			}
		}
		outStr << "</general>" << endl;
#ifdef DEBUG
		cout << "Done with <general> element" << endl;
#endif
	};

/**
 * 	Put the <system> element
 */
	if(m_OSOption->system != NULL)
	{
		outStr << "<system>" << endl;
		if (m_OSOption->system->minDiskSpace != NULL)
		{
			outStr << "<minDiskSpace";
			if (m_OSOption->system->minDiskSpace->unit != "byte")
				outStr << " unit=\"" << m_OSOption->system->minDiskSpace->unit << "\"";
			if (m_OSOption->system->minDiskSpace->description != "")
				outStr << " description=\"" << m_OSOption->system->minDiskSpace->description << "\"";
			outStr << ">";
			outStr << os_dtoa_format(m_OSOption->system->minDiskSpace->value) << "</minDiskSpace>" << endl;
		}
		if (m_OSOption->system->minMemorySize != NULL)
		{
			outStr << "<minMemorySize";
			if (m_OSOption->system->minMemorySize->unit != "byte")
				outStr << " unit=\"" << m_OSOption->system->minMemorySize->unit << "\"";
			if (m_OSOption->system->minMemorySize->description != "")
				outStr << " description=\"" << m_OSOption->system->minMemorySize->description << "\"";
			outStr << ">";
			outStr << os_dtoa_format(m_OSOption->system->minMemorySize->value) << "</minMemorySize>" << endl;
		}
		if (m_OSOption->system->minCPUSpeed != NULL)
		{
			outStr << "<minCPUSpeed";
			if (m_OSOption->system->minCPUSpeed->unit != "hertz")
				outStr << " unit=\"" << m_OSOption->system->minCPUSpeed->unit << "\"";
			if (m_OSOption->system->minCPUSpeed->description != "")
				outStr << " description=\"" << m_OSOption->system->minCPUSpeed->description << "\"";
			outStr << ">";
			outStr << os_dtoa_format(m_OSOption->system->minCPUSpeed->value) << "</minCPUSpeed>" << endl;
		}
		if (m_OSOption->system->minCPUNumber != NULL)
		{
			outStr << "<minCPUNumber";
			if (m_OSOption->system->minCPUNumber->description != "")
				outStr << " description=\"" << m_OSOption->system->minCPUNumber->description << "\"";
			outStr << ">";
			outStr << m_OSOption->system->minCPUNumber->value << "</minCPUNumber>" << endl;
		};
		if (m_OSOption->system->otherOptions != NULL)
		{
//			if (m_OSOption->system->otherOptions->numberOfOtherOptions > 0)
			{	outStr << "<otherOptions numberOfOtherOptions=\""; 
				outStr << m_OSOption->system->otherOptions->numberOfOtherOptions << "\">" << endl;
				for (int i=0; i < m_OSOption->system->otherOptions->numberOfOtherOptions; i++)
				{	outStr << "<other name=\"" << m_OSOption->system->otherOptions->other[i]->name << "\"";
					if (m_OSOption->system->otherOptions->other[i]->value != "")
						outStr << " value=\"" << m_OSOption->system->otherOptions->other[i]->value << "\"";
					if (m_OSOption->system->otherOptions->other[i]->description != "")
						outStr << " description=\"" << m_OSOption->system->otherOptions->other[i]->description << "\"";
					outStr << "/>" << endl;
				}
				outStr << "</otherOptions>" << endl;
			}
		}
		outStr << "</system>" << endl;
#ifdef DEBUG
		cout << "Done with <system> element" << endl;
#endif
	}

/**
 * 	Put the <service> element
 */
	if(m_OSOption->service != NULL)
	{	outStr << "<service>" << endl;
		if (m_OSOption->service->type != "")
		{	outStr << "<type>" << m_OSOption->service->type << "</type>" << endl;
		}
		if (m_OSOption->service->otherOptions != NULL)
		{
//			if (m_OSOption->service->otherOptions->numberOfOtherOptions > 0)
			{	outStr << "<otherOptions numberOfOtherOptions=\""; 
				outStr << m_OSOption->service->otherOptions->numberOfOtherOptions << "\">" << endl;
				for (int i=0; i < m_OSOption->service->otherOptions->numberOfOtherOptions; i++)
				{	outStr << "<other name=\"" << m_OSOption->service->otherOptions->other[i]->name << "\"";
					if (m_OSOption->service->otherOptions->other[i]->value != "")
						outStr << " value=\"" << m_OSOption->service->otherOptions->other[i]->value << "\"";
					if (m_OSOption->service->otherOptions->other[i]->description != "")
						outStr << " description=\"" << m_OSOption->service->otherOptions->other[i]->description << "\"";
					outStr << "/>" << endl;
				}
				outStr << "</otherOptions>" << endl;
			}
		}
		outStr << "</service>" << endl;
#ifdef DEBUG
		cout << "Done with <service> element" << endl;
#endif
	};

/**
 * 	Put the <job> element
 */
	if(m_OSOption->job != NULL)
	{	outStr << "<job>" << endl;
		if (m_OSOption->job->maxTime != NULL)
		{	if (m_OSOption->job->maxTime->unit == "")
				m_OSOption->job->maxTime->unit = "second";
			outStr << "<maxTime unit=\"" << m_OSOption->job->maxTime->unit << "\">";
			if (m_OSOption->job->maxTime->value == OSDBL_MAX)
				outStr << "INF" << "</maxTime>" << endl;
			else
				outStr << os_dtoa_format(m_OSOption->job->maxTime->value) << "</maxTime>" << endl;
		}
		if (m_OSOption->job->requestedStartTime != "")
			outStr << "<requestedStartTime>" << m_OSOption->job->requestedStartTime << "</requestedStartTime>" << endl;
		if (m_OSOption->job->dependencies != NULL)
		{
//			if (m_OSOption->job->dependencies->numberOfJobIDs > 0)
			{	outStr << "<dependencies numberOfJobIDs=\"";
				outStr << m_OSOption->job->dependencies->numberOfJobIDs << "\">" << endl; 
				for (int i=0; i < m_OSOption->job->dependencies->numberOfJobIDs; i++)
				{	outStr << "<jobID>" << m_OSOption->job->dependencies->jobID[i] << "</jobID>" << endl;
				}
				outStr << "</dependencies>" << endl;
			}
		}
		if (m_OSOption->job->requiredDirectories != NULL)
		{
//			if (m_OSOption->job->requiredDirectories->numberOfPaths > 0)
			{	outStr << "<requiredDirectories numberOfPaths=\"";
				outStr << m_OSOption->job->requiredDirectories->numberOfPaths << "\">" << endl; 
				for (int i=0; i < m_OSOption->job->requiredDirectories->numberOfPaths; i++)
					outStr << "<path>" << m_OSOption->job->requiredDirectories->path[i] << "</path>" << endl;
				outStr << "</requiredDirectories>" << endl;
			}
		}
		if (m_OSOption->job->requiredFiles != NULL)
		{
//			if (m_OSOption->job->requiredFiles->numberOfPaths > 0)
			{	outStr << "<requiredFiles numberOfPaths=\"";
				outStr << m_OSOption->job->requiredFiles->numberOfPaths << "\">" << endl; 
				for (int i=0; i < m_OSOption->job->requiredFiles->numberOfPaths; i++)
					outStr << "<path>" << m_OSOption->job->requiredFiles->path[i] << "</path>" << endl;
				outStr << "</requiredFiles>" << endl;
			}
		}
		if (m_OSOption->job->directoriesToMake != NULL)
		{
//			if (m_OSOption->job->directoriesToMake->numberOfPaths > 0)
			{	outStr << "<directoriesToMake numberOfPaths=\"";
				outStr << m_OSOption->job->directoriesToMake->numberOfPaths << "\">" << endl; 
				for (int i=0; i < m_OSOption->job->directoriesToMake->numberOfPaths; i++)
					outStr << "<path>" << m_OSOption->job->directoriesToMake->path[i] << "</path>" << endl;
				outStr << "</directoriesToMake>" << endl;
			}
		}
		if (m_OSOption->job->filesToMake != NULL)
		{
//			if (m_OSOption->job->filesToMake->numberOfPaths > 0)
			{	outStr << "<filesToMake numberOfPaths=\"";
				outStr << m_OSOption->job->filesToMake->numberOfPaths << "\">" << endl; 
				for (int i=0; i < m_OSOption->job->filesToMake->numberOfPaths; i++)
					outStr << "<path>" << m_OSOption->job->filesToMake->path[i] << "</path>" << endl;
				outStr << "</filesToMake>" << endl;
			}
		}
		if (m_OSOption->job->inputDirectoriesToMove != NULL)
		{
//			if (m_OSOption->job->inputDirectoriesToMove->numberOfPathPairs > 0)
			{	outStr << "<inputDirectoriesToMove numberOfPathPairs=\"";
				outStr << m_OSOption->job->inputDirectoriesToMove->numberOfPathPairs << "\">" << endl; 
				for (int i=0; i < m_OSOption->job->inputDirectoriesToMove->numberOfPathPairs; i++)
				{	outStr << "<pathPair";
					outStr << " from=\"" << m_OSOption->job->inputDirectoriesToMove->pathPair[i]->from << "\"";
					outStr << " to=\"" << m_OSOption->job->inputDirectoriesToMove->pathPair[i]->to << "\"";
					if (m_OSOption->job->inputDirectoriesToMove->pathPair[i]->makeCopy)
						outStr << " makeCopy=\"true\""; 
					outStr << "/>" << endl;
				}
				outStr << "</inputDirectoriesToMove>" << endl;
			}
		}
		if (m_OSOption->job->inputFilesToMove != NULL)
		{
//			if (m_OSOption->job->inputFilesToMove->numberOfPathPairs > 0)
			{	outStr << "<inputFilesToMove numberOfPathPairs=\"";
				outStr << m_OSOption->job->inputFilesToMove->numberOfPathPairs << "\">" << endl; 
				for (int i=0; i < m_OSOption->job->inputFilesToMove->numberOfPathPairs; i++)
				{	outStr << "<pathPair";
					outStr << " from=\"" << m_OSOption->job->inputFilesToMove->pathPair[i]->from << "\"";
					outStr << " to=\"" << m_OSOption->job->inputFilesToMove->pathPair[i]->to << "\"";
					if (m_OSOption->job->inputFilesToMove->pathPair[i]->makeCopy)
						outStr << " makeCopy=\"true\""; 
					outStr << "/>" << endl;
				}
				outStr << "</inputFilesToMove>" << endl;
			}
		}
		if (m_OSOption->job->outputFilesToMove != NULL)
		{
//			if (m_OSOption->job->outputFilesToMove->numberOfPathPairs > 0)
			{	outStr << "<outputFilesToMove numberOfPathPairs=\"";
				outStr << m_OSOption->job->outputFilesToMove->numberOfPathPairs << "\">" << endl; 
				for (int i=0; i < m_OSOption->job->outputFilesToMove->numberOfPathPairs; i++)
				{	outStr << "<pathPair";
					outStr << " from=\"" << m_OSOption->job->outputFilesToMove->pathPair[i]->from << "\"";
					outStr << " to=\"" << m_OSOption->job->outputFilesToMove->pathPair[i]->to << "\"";
					if (m_OSOption->job->outputFilesToMove->pathPair[i]->makeCopy)
						outStr << " makeCopy=\"true\""; 
					outStr << "/>" << endl;
				}
				outStr << "</outputFilesToMove>" << endl;
			}
		}
		if (m_OSOption->job->outputDirectoriesToMove != NULL)
		{
//			if (m_OSOption->job->outputDirectoriesToMove->numberOfPathPairs > 0)
			{	outStr << "<outputDirectoriesToMove numberOfPathPairs=\"";
				outStr << m_OSOption->job->outputDirectoriesToMove->numberOfPathPairs << "\">" << endl; 
				for (int i=0; i < m_OSOption->job->outputDirectoriesToMove->numberOfPathPairs; i++)
				{	outStr << "<pathPair";
					outStr << " from=\"" << m_OSOption->job->outputDirectoriesToMove->pathPair[i]->from << "\"";
					outStr << " to=\"" << m_OSOption->job->outputDirectoriesToMove->pathPair[i]->to << "\"";
					if (m_OSOption->job->outputDirectoriesToMove->pathPair[i]->makeCopy)
						outStr << " makeCopy=\"true\""; 
					outStr << "/>" << endl;
				}
				outStr << "</outputDirectoriesToMove>" << endl;
			}
		}
		if (m_OSOption->job->filesToDelete != NULL)
		{
//			if (m_OSOption->job->filesToDelete->numberOfPaths > 0)
			{	outStr << "<filesToDelete numberOfPaths=\"";
				outStr << m_OSOption->job->filesToDelete->numberOfPaths << "\">" << endl; 
				for (int i=0; i < m_OSOption->job->filesToDelete->numberOfPaths; i++)
					outStr << "<path>" << m_OSOption->job->filesToDelete->path[i] << "</path>" << endl;
				outStr << "</filesToDelete>" << endl;
			}
		}
		if (m_OSOption->job->directoriesToDelete != NULL)
		{
//			if (m_OSOption->job->directoriesToDelete->numberOfPaths > 0)
			{	outStr << "<directoriesToDelete numberOfPaths=\"";
				outStr << m_OSOption->job->directoriesToDelete->numberOfPaths << "\">" << endl; 
				for (int i=0; i < m_OSOption->job->directoriesToDelete->numberOfPaths; i++)
					outStr << "<path>" << m_OSOption->job->directoriesToDelete->path[i] << "</path>" << endl;
				outStr << "</directoriesToDelete>" << endl;
			}
		}
		if (m_OSOption->job->processesToKill != NULL)
		{
//			if (m_OSOption->job->processesToKill->numberOfProcesses > 0)
			{	outStr << "<processesToKill numberOfProcesses=\"";
				outStr << m_OSOption->job->processesToKill->numberOfProcesses << "\">" << endl; 
				for (int i=0; i < m_OSOption->job->processesToKill->numberOfProcesses; i++)
					outStr << "<process>" << m_OSOption->job->processesToKill->process[i] << "</process>" << endl;
				outStr << "</processesToKill>" << endl;
			}
		}
		if (m_OSOption->job->otherOptions != NULL)
		{
//			if (m_OSOption->job->otherOptions->numberOfOtherOptions > 0)
			{	outStr << "<otherOptions numberOfOtherOptions=\""; 
				outStr << m_OSOption->job->otherOptions->numberOfOtherOptions << "\">" << endl;
				for (int i=0; i < m_OSOption->job->otherOptions->numberOfOtherOptions; i++)
				{	outStr << "<other name=\"" << m_OSOption->job->otherOptions->other[i]->name << "\"";
					if (m_OSOption->job->otherOptions->other[i]->value != "")
						outStr << " value=\"" << m_OSOption->job->otherOptions->other[i]->value << "\"";
					if (m_OSOption->job->otherOptions->other[i]->description != "")
						outStr << " description=\"" << m_OSOption->job->otherOptions->other[i]->description << "\"";
					outStr << "/>" << endl;
				}
				outStr << "</otherOptions>" << endl;
			}
		}
		outStr << "</job>" << endl;
#ifdef DEBUG
		cout << "Done with <job> element" << endl;
#endif
	};

/**
 * 	Put the <optimization> element
 */
	if (m_OSOption->optimization != NULL)
	{	outStr << "<optimization";
		if (m_OSOption->optimization->numberOfVariables >= 0)
			outStr << " numberOfVariables=\"" << m_OSOption->optimization->numberOfVariables << "\" ";
		if (m_OSOption->optimization->numberOfObjectives >= 0)
			outStr << " numberOfObjectives=\"" << m_OSOption->optimization->numberOfObjectives << "\" ";
		if (m_OSOption->optimization->numberOfConstraints >= 0)
			outStr << " numberOfConstraints=\"" << m_OSOption->optimization->numberOfConstraints << "\" ";
		outStr << ">" << endl;
		if (m_OSOption->optimization->variables != NULL)
		{	outStr << "<variables";
//			if (m_OSOption->optimization->variables->numberOfOtherVariableOptions > 0)
				outStr << " numberOfOtherVariableOptions=\"" << m_OSOption->optimization->variables->numberOfOtherVariableOptions << "\"";
			outStr << ">" << endl;
#ifdef DEBUG
			cout << "initialVariableValues: " << (m_OSOption->optimization->variables->initialVariableValues != NULL) << endl;
#endif
			if (m_OSOption->optimization->variables->initialVariableValues != NULL)
			{	outStr << "<initialVariableValues numberOfVar=\"";
				outStr << m_OSOption->optimization->variables->initialVariableValues->numberOfVar << "\">" << endl;
				for (int i=0; i < m_OSOption->optimization->variables->initialVariableValues->numberOfVar; i++)
				{	outStr << "<var";
					outStr << " idx=\"" << m_OSOption->optimization->variables->initialVariableValues->var[i]->idx << "\"";
					if (m_OSOption->optimization->variables->initialVariableValues->var[i]->value != OSNAN)
					{	outStr << " value=\"";
						if (m_OSOption->optimization->variables->initialVariableValues->var[i]->value == OSDBL_MAX)
							outStr << "INF";
						else if (m_OSOption->optimization->variables->initialVariableValues->var[i]->value == -OSDBL_MAX)
							outStr << "-INF";
						else
							outStr << os_dtoa_format(m_OSOption->optimization->variables->initialVariableValues->var[i]->value);
					}
					outStr << "\"/>" << endl;
				}
				outStr << "</initialVariableValues>" << endl;
			}
#ifdef DEBUG
			cout << "initialVariableValuesString: " << (m_OSOption->optimization->variables->initialVariableValuesString != NULL) << endl;
#endif
			if (m_OSOption->optimization->variables->initialVariableValuesString != NULL)
			{	outStr << "<initialVariableValuesString numberOfVar=\"";
				outStr << m_OSOption->optimization->variables->initialVariableValuesString->numberOfVar << "\">" << endl;
				for (int i=0; i < m_OSOption->optimization->variables->initialVariableValuesString->numberOfVar; i++)
				{	outStr << "<var";
					outStr << " idx=\"" << m_OSOption->optimization->variables->initialVariableValuesString->var[i]->idx << "\"";
					outStr << " value=\"" << m_OSOption->optimization->variables->initialVariableValuesString->var[i]->value << "\"";
					outStr << "/>" << endl;
				}
				outStr << "</initialVariableValuesString>" << endl;
			}

			if (m_OSOption->optimization->variables->initialBasisStatus != NULL)
			{
#ifdef DEBUG
	cout << "output <variables> <basisStatus>" << endl;
#endif
				outStr << "<initialBasisStatus>" << endl;
				outStr << writeBasisStatus(m_OSOption->optimization->variables->initialBasisStatus, m_bWhiteSpace, m_bWriteBase64);
				outStr << "</initialBasisStatus>" << endl;
			}

#ifdef DEBUG
			cout << "integerVariableBranchingWeights: " << (m_OSOption->optimization->variables->integerVariableBranchingWeights != NULL) << endl;
#endif
			if (m_OSOption->optimization->variables->integerVariableBranchingWeights != NULL)
			{	outStr << "<integerVariableBranchingWeights numberOfVar=\"";
				outStr << m_OSOption->optimization->variables->integerVariableBranchingWeights->numberOfVar << "\">" << endl;
				for (int i=0; i < m_OSOption->optimization->variables->integerVariableBranchingWeights->numberOfVar; i++)
				{	outStr << "<var";
					outStr << " idx=\"" << m_OSOption->optimization->variables->integerVariableBranchingWeights->var[i]->idx << "\"";
					outStr << " value=\"" << os_dtoa_format(m_OSOption->optimization->variables->integerVariableBranchingWeights->var[i]->value) << "\"";
					outStr << "/>" << endl;
				}
				outStr << "</integerVariableBranchingWeights>" << endl;
			}
#ifdef DEBUG
			cout << "sosVariableBranchingWeights: " << (m_OSOption->optimization->variables->sosVariableBranchingWeights != NULL) << endl;
#endif
			if (m_OSOption->optimization->variables->sosVariableBranchingWeights != NULL)
			{	outStr << "<sosVariableBranchingWeights numberOfSOS=\"";
#ifdef DEBUG
				cout << "start: numberOfSOS" << endl;
#endif
				outStr << m_OSOption->optimization->variables->sosVariableBranchingWeights->numberOfSOS << "\">" << endl;
				for (int i=0; i < m_OSOption->optimization->variables->sosVariableBranchingWeights->numberOfSOS; i++)
				{	outStr << "<sos";
#ifdef DEBUG
				cout << "sosIdx - nvar: " << m_OSOption->optimization->variables->sosVariableBranchingWeights->sos[i]->numberOfVar << endl;
#endif
					outStr << " sosIdx=\"" << m_OSOption->optimization->variables->sosVariableBranchingWeights->sos[i]->sosIdx << "\"";
					outStr << " numberOfVar=\"" << m_OSOption->optimization->variables->sosVariableBranchingWeights->sos[i]->numberOfVar << "\"";
					outStr << " groupWeight=\"" << os_dtoa_format(m_OSOption->optimization->variables->sosVariableBranchingWeights->sos[i]->groupWeight) << "\">" << endl;
					for (int j=0; j < m_OSOption->optimization->variables->sosVariableBranchingWeights->sos[i]->numberOfVar; j++)
					{	outStr << "<var";
#ifdef DEBUG
				cout << "idx" << endl;
#endif
						outStr << " idx=\"" << m_OSOption->optimization->variables->sosVariableBranchingWeights->sos[i]->var[j]->idx << "\"";
						outStr << " value=\"" << os_dtoa_format(m_OSOption->optimization->variables->sosVariableBranchingWeights->sos[i]->var[j]->value) << "\"";
						outStr << "/>" << endl;
					}
					outStr << "</sos>" << endl;
				}
				outStr << "</sosVariableBranchingWeights>" << endl;
			}
#ifdef DEBUG
			printf("\n%s%d\n","Number of other variable options: ",m_OSOption->optimization->variables->numberOfOtherVariableOptions);
#endif
//			if (m_OSOption->optimization->variables->numberOfOtherVariableOptions > 0)
				for (int i=0; i < m_OSOption->optimization->variables->numberOfOtherVariableOptions; i++)
				{	outStr << "<other name=\"" << m_OSOption->optimization->variables->other[i]->name << "\"";
//					if (m_OSOption->optimization->variables->other[i]->numberOfVar > 0)
						outStr << " numberOfVar=\"" << m_OSOption->optimization->variables->other[i]->numberOfVar << "\"";
//					if (m_OSOption->optimization->variables->other[i]->numberOfEnumerations > 0)
						outStr << " numberOfEnumerations=\"" << m_OSOption->optimization->variables->other[i]->numberOfEnumerations << "\"";
					if (m_OSOption->optimization->variables->other[i]->value != "")
						outStr << " value=\"" << m_OSOption->optimization->variables->other[i]->value << "\"";
					if (m_OSOption->optimization->variables->other[i]->solver != "")
						outStr << " solver=\"" << m_OSOption->optimization->variables->other[i]->solver << "\"";
					if (m_OSOption->optimization->variables->other[i]->category != "")
						outStr << " category=\"" << m_OSOption->optimization->variables->other[i]->category << "\"";
					if (m_OSOption->optimization->variables->other[i]->type != "")
						outStr << " type=\"" << m_OSOption->optimization->variables->other[i]->type << "\"";
					if (m_OSOption->optimization->variables->other[i]->description != "")
						outStr << " description=\"" << m_OSOption->optimization->variables->other[i]->description << "\"";
					outStr << ">" << endl;
//					if (m_OSOption->optimization->variables->other[i]->numberOfVar > 0)
						for (int j=0; j < m_OSOption->optimization->variables->other[i]->numberOfVar; j++)
						{	outStr << "<var idx=\"" << m_OSOption->optimization->variables->other[i]->var[j]->idx << "\"";
							if (m_OSOption->optimization->variables->other[i]->var[j]->value != "")
								outStr << " value=\"" << m_OSOption->optimization->variables->other[i]->var[j]->value << "\"";
							if (m_OSOption->optimization->variables->other[i]->var[j]->lbValue != "")
								outStr << " lbValue=\"" << m_OSOption->optimization->variables->other[i]->var[j]->lbValue << "\"";
							if (m_OSOption->optimization->variables->other[i]->var[j]->ubValue != "")
								outStr << " ubValue=\"" << m_OSOption->optimization->variables->other[i]->var[j]->ubValue << "\"";
							outStr << "/>" << endl;
						}
//					else 
					{
//						if (m_OSOption->optimization->variables->other[i]->numberOfEnumerations > 0)
						for (int j=0; j < m_OSOption->optimization->variables->other[i]->numberOfEnumerations; j++)
							outStr << writeOtherOptionEnumeration(m_OSOption->optimization->variables->other[i]->enumeration[j], m_bWhiteSpace, m_bWriteBase64);
					}
					outStr << "</other>" << endl;
				}
			outStr << "</variables>" << endl;
		}
		if (m_OSOption->optimization->objectives != NULL)
		{	outStr << "<objectives";
//			if (m_OSOption->optimization->objectives->numberOfOtherObjectiveOptions > 0)
				outStr << " numberOfOtherObjectiveOptions=\"" << m_OSOption->optimization->objectives->numberOfOtherObjectiveOptions << "\"";
			outStr << ">" << endl;
			if (m_OSOption->optimization->objectives->initialObjectiveValues != NULL)
			{	outStr << "<initialObjectiveValues numberOfObj=\"";
				outStr << m_OSOption->optimization->objectives->initialObjectiveValues->numberOfObj << "\">" << endl;
				for (int i=0; i < m_OSOption->optimization->objectives->initialObjectiveValues->numberOfObj; i++)
				{	outStr << "<obj";
					outStr << " idx=\"" << m_OSOption->optimization->objectives->initialObjectiveValues->obj[i]->idx << "\"";
					if (m_OSOption->optimization->objectives->initialObjectiveValues->obj[i]->value != OSNAN)
					{	outStr << " value=\"";
						if (m_OSOption->optimization->objectives->initialObjectiveValues->obj[i]->value == OSDBL_MAX)
							outStr << "INF";
						else if (m_OSOption->optimization->objectives->initialObjectiveValues->obj[i]->value == -OSDBL_MAX)
							outStr << "-INF";
						else
							outStr << os_dtoa_format(m_OSOption->optimization->objectives->initialObjectiveValues->obj[i]->value);
						outStr << "\"" << endl;
					}
					outStr << "/>" << endl;
				}
				outStr << "</initialObjectiveValues>" << endl;
			}
			if (m_OSOption->optimization->objectives->initialObjectiveBounds != NULL)
			{	outStr << "<initialObjectiveBounds numberOfObj=\"";
				outStr << m_OSOption->optimization->objectives->initialObjectiveBounds->numberOfObj << "\">" << endl;
				for (int i=0; i < m_OSOption->optimization->objectives->initialObjectiveBounds->numberOfObj; i++)
				{	outStr << "<obj";
					outStr << " idx=\"" << m_OSOption->optimization->objectives->initialObjectiveBounds->obj[i]->idx << "\"";
					outStr << " lbValue=\"";
					if (m_OSOption->optimization->objectives->initialObjectiveBounds->obj[i]->lbValue == OSDBL_MAX)
						outStr << "INF";
					else if (m_OSOption->optimization->objectives->initialObjectiveBounds->obj[i]->lbValue == -OSDBL_MAX)
						outStr << "-INF";
					else
						outStr << os_dtoa_format(m_OSOption->optimization->objectives->initialObjectiveBounds->obj[i]->lbValue);
					outStr << "\" ubValue=\"";
					if (m_OSOption->optimization->objectives->initialObjectiveBounds->obj[i]->ubValue == OSDBL_MAX)
						outStr << "INF";
					else if (m_OSOption->optimization->objectives->initialObjectiveBounds->obj[i]->ubValue == -OSDBL_MAX)
						outStr << "-INF";
					else
						outStr << os_dtoa_format(m_OSOption->optimization->objectives->initialObjectiveBounds->obj[i]->ubValue);
					outStr << "\"/>" << endl;
				}
				outStr << "</initialObjectiveBounds>" << endl;
			}

			if (m_OSOption->optimization->objectives->initialBasisStatus != NULL)
			{
#ifdef DEBUG
	cout << "output <objectives> <basisStatus>" << endl;
#endif
				outStr << "<initialBasisStatus>" << endl;
				outStr << writeBasisStatus(m_OSOption->optimization->objectives->initialBasisStatus, m_bWhiteSpace, m_bWriteBase64);
				outStr << "</initialBasisStatus>" << endl;
			}

#ifdef DEBUG
			printf("\n%s%d\n","Number of other objective options: ",m_OSOption->optimization->objectives->numberOfOtherObjectiveOptions);
#endif
//			if (m_OSOption->optimization->objectives->numberOfOtherObjectiveOptions > 0)
				for (int i=0; i < m_OSOption->optimization->objectives->numberOfOtherObjectiveOptions; i++)
				{
					outStr << "<other name=\"" << m_OSOption->optimization->objectives->other[i]->name << "\"";
//					if (m_OSOption->optimization->objectives->other[i]->numberOfObj > 0)
						outStr << " numberOfObj=\"" << m_OSOption->optimization->objectives->other[i]->numberOfObj << "\"";
//					if (m_OSOption->optimization->objectives->other[i]->numberOfEnumerations > 0)
						outStr << " numberOfEnumerations=\"" << m_OSOption->optimization->objectives->other[i]->numberOfEnumerations << "\"";
					if (m_OSOption->optimization->objectives->other[i]->value != "")
						outStr << " value=\"" << m_OSOption->optimization->objectives->other[i]->value << "\"";
					if (m_OSOption->optimization->objectives->other[i]->solver != "")
						outStr << " solver=\"" << m_OSOption->optimization->objectives->other[i]->solver << "\"";
					if (m_OSOption->optimization->objectives->other[i]->category != "")
						outStr << " category=\"" << m_OSOption->optimization->objectives->other[i]->category << "\"";
					if (m_OSOption->optimization->objectives->other[i]->type != "")
						outStr << " type=\"" << m_OSOption->optimization->objectives->other[i]->type << "\"";
					if (m_OSOption->optimization->objectives->other[i]->description != "")
						outStr << " description=\"" << m_OSOption->optimization->objectives->other[i]->description << "\"";
					outStr << ">" << endl;
//					if (m_OSOption->optimization->objectives->other[i]->numberOfObj > 0)
						for (int j=0; j < m_OSOption->optimization->objectives->other[i]->numberOfObj; j++)
						{	outStr << "<var idx=\"" << m_OSOption->optimization->objectives->other[i]->obj[j]->idx << "\"";
							if (m_OSOption->optimization->objectives->other[i]->obj[j]->value != "")
								outStr << " value=\"" << m_OSOption->optimization->objectives->other[i]->obj[j]->value << "\"";
							outStr << "/>" << endl;
						}
//					else if (m_OSOption->optimization->objectives->other[i]->numberOfEnumerations > 0)
						for (int j=0; j < m_OSOption->optimization->objectives->other[i]->numberOfEnumerations; j++)
							outStr << writeOtherOptionEnumeration(m_OSOption->optimization->objectives->other[i]->enumeration[j], m_bWhiteSpace, m_bWriteBase64);

					outStr << "</other>" << endl;
				}
			outStr << "</objectives>" << endl;
		}
#ifdef DEBUG
	cout << "Done with <objectives> element" << endl;
#endif
		if (m_OSOption->optimization->constraints != NULL)
		{	outStr << "<constraints";
//			if (m_OSOption->optimization->constraints->numberOfOtherConstraintOptions > 0)
				outStr << " numberOfOtherConstraintOptions=\"" << m_OSOption->optimization->constraints->numberOfOtherConstraintOptions << "\"";
			outStr << ">" << endl;
			if (m_OSOption->optimization->constraints->initialConstraintValues != NULL)
			{	outStr << "<initialConstraintValues numberOfCon=\"";
				outStr << m_OSOption->optimization->constraints->initialConstraintValues->numberOfCon << "\">" << endl;
				for (int i=0; i < m_OSOption->optimization->constraints->initialConstraintValues->numberOfCon; i++)
				{	outStr << "<con";
					outStr << " idx=\"" << m_OSOption->optimization->constraints->initialConstraintValues->con[i]->idx << "\"";
					if (m_OSOption->optimization->constraints->initialConstraintValues->con[i]->value != OSNAN)
					{	outStr << " value=\"";
						if (m_OSOption->optimization->constraints->initialConstraintValues->con[i]->value == OSDBL_MAX)
							outStr << "INF";
						else if (m_OSOption->optimization->constraints->initialConstraintValues->con[i]->value == -OSDBL_MAX)
							outStr << "-INF";
						else
							outStr << os_dtoa_format(m_OSOption->optimization->constraints->initialConstraintValues->con[i]->value);
					}
					outStr << "\"/>" << endl;
				}
				outStr << "</initialConstraintValues>" << endl;
			}

			if (m_OSOption->optimization->constraints->initialDualValues != NULL)
			{	outStr << "<initialDualValues numberOfCon=\"";
				outStr << m_OSOption->optimization->constraints->initialDualValues->numberOfCon << "\">" << endl;
				for (int i=0; i < m_OSOption->optimization->constraints->initialDualValues->numberOfCon; i++)
				{	outStr << "<con";
					outStr << " idx=\"" << m_OSOption->optimization->constraints->initialDualValues->con[i]->idx << "\"";
					outStr << " lbDualValue=\"";
					if (m_OSOption->optimization->constraints->initialDualValues->con[i]->lbDualValue == OSDBL_MAX)
						outStr << "INF";
					else if (m_OSOption->optimization->constraints->initialDualValues->con[i]->lbDualValue == -OSDBL_MAX)
						outStr << "-INF";
					else
						outStr << os_dtoa_format(m_OSOption->optimization->constraints->initialDualValues->con[i]->lbDualValue);
					outStr << "\" ubDualValue=\"";
					if (m_OSOption->optimization->constraints->initialDualValues->con[i]->ubDualValue == OSDBL_MAX)
						outStr << "INF";
					else if (m_OSOption->optimization->constraints->initialDualValues->con[i]->ubDualValue == -OSDBL_MAX)
						outStr << "-INF";
					else
						outStr << os_dtoa_format(m_OSOption->optimization->constraints->initialDualValues->con[i]->ubDualValue);
					outStr << "\"/>" << endl;
				}
				outStr << "</initialDualValues>" << endl;
			}

			if (m_OSOption->optimization->constraints->initialBasisStatus != NULL)
			{
#ifdef DEBUG
	cout << "output <constraints> <basisStatus>" << endl;
#endif
				outStr << "<initialBasisStatus>" << endl;
				outStr << writeBasisStatus(m_OSOption->optimization->constraints->initialBasisStatus, m_bWhiteSpace, m_bWriteBase64);
				outStr << "</initialBasisStatus>" << endl;
			}

#ifdef DEBUG
			printf("\n%s%d\n","Number of other constraint options: ",m_OSOption->optimization->constraints->numberOfOtherConstraintOptions);
#endif
//			if (m_OSOption->optimization->constraints->numberOfOtherConstraintOptions > 0)
				for (int i=0; i < m_OSOption->optimization->constraints->numberOfOtherConstraintOptions; i++)
				{	outStr << "<other name=\"" << m_OSOption->optimization->constraints->other[i]->name << "\"";

//					if (m_OSOption->optimization->constraints->other[i]->numberOfCon > 0)
						outStr << " numberOfCon=\"" << m_OSOption->optimization->constraints->other[i]->numberOfCon << "\"";
//					if (m_OSOption->optimization->constraints->other[i]->numberOfEnumerations > 0)
						outStr << " numberOfEnumerations=\"" << m_OSOption->optimization->constraints->other[i]->numberOfEnumerations << "\"";
					if (m_OSOption->optimization->constraints->other[i]->value != "")
						outStr << " value=\"" << m_OSOption->optimization->constraints->other[i]->value << "\"";
					if (m_OSOption->optimization->constraints->other[i]->solver != "")
						outStr << " solver=\"" << m_OSOption->optimization->constraints->other[i]->solver << "\"";
					if (m_OSOption->optimization->constraints->other[i]->category != "")
						outStr << " category=\"" << m_OSOption->optimization->constraints->other[i]->category << "\"";
					if (m_OSOption->optimization->constraints->other[i]->type != "")
						outStr << " type=\"" << m_OSOption->optimization->constraints->other[i]->type << "\"";
					if (m_OSOption->optimization->constraints->other[i]->description != "")
						outStr << " description=\"" << m_OSOption->optimization->constraints->other[i]->description << "\"";
					outStr << ">" << endl;
//					if (m_OSOption->optimization->constraints->other[i]->numberOfCon > 0)
						for (int j=0; j < m_OSOption->optimization->constraints->other[i]->numberOfCon; j++)
						{	outStr << "<con idx=\"" << m_OSOption->optimization->constraints->other[i]->con[j]->idx << "\"";
							if (m_OSOption->optimization->constraints->other[i]->con[j]->value != "")
								outStr << " value=\"" << m_OSOption->optimization->constraints->other[i]->con[j]->value << "\"";
							if (m_OSOption->optimization->constraints->other[i]->con[j]->lbValue != "")
								outStr << " lbValue=\"" << m_OSOption->optimization->constraints->other[i]->con[j]->lbValue << "\"";
							if (m_OSOption->optimization->constraints->other[i]->con[j]->ubValue != "")
								outStr << " ubValue=\"" << m_OSOption->optimization->constraints->other[i]->con[j]->ubValue << "\"";
							outStr << "/>" << endl;
						}
//					else if (m_OSOption->optimization->constraints->other[i]->numberOfEnumerations > 0)
						for (int j=0; j < m_OSOption->optimization->constraints->other[i]->numberOfEnumerations; j++)
							outStr << writeOtherOptionEnumeration(m_OSOption->optimization->constraints->other[i]->enumeration[j], m_bWhiteSpace, m_bWriteBase64);

					outStr << "</other>" << endl;
				}
			outStr << "</constraints>" << endl;
		}
#ifdef DEBUG
		cout << "Done with <constraint> element" << endl;
#endif
		if (m_OSOption->optimization->solverOptions != NULL)
		{
//			if (m_OSOption->optimization->solverOptions->numberOfSolverOptions > 0)
			{	outStr << "<solverOptions numberOfSolverOptions=\""; 
				outStr << m_OSOption->optimization->solverOptions->numberOfSolverOptions << "\">" << endl;
				for (int i=0; i < m_OSOption->optimization->solverOptions->numberOfSolverOptions; i++)
				{
					outStr << "<solverOption name=\"" << m_OSOption->optimization->solverOptions->solverOption[i]->name << "\"";
					if (m_OSOption->optimization->solverOptions->solverOption[i]->value != "")
						outStr << " value=\"" << m_OSOption->optimization->solverOptions->solverOption[i]->value << "\"";
					if (m_OSOption->optimization->solverOptions->solverOption[i]->solver != "")
						outStr << " solver=\"" << m_OSOption->optimization->solverOptions->solverOption[i]->solver << "\"";
					if (m_OSOption->optimization->solverOptions->solverOption[i]->category != "")
						outStr << " category=\"" << m_OSOption->optimization->solverOptions->solverOption[i]->category << "\"";
					if (m_OSOption->optimization->solverOptions->solverOption[i]->type != "")
						outStr << " type=\"" << m_OSOption->optimization->solverOptions->solverOption[i]->type << "\"";
					if (m_OSOption->optimization->solverOptions->solverOption[i]->description != "")
						outStr << " description=\"" << m_OSOption->optimization->solverOptions->solverOption[i]->description << "\"";
					if (m_OSOption->optimization->solverOptions->solverOption[i]->numberOfItems == 0)
						outStr << "/>" << endl;
					else
					{
						outStr << " numberOfItems=\"" << m_OSOption->optimization->solverOptions->solverOption[i]->numberOfItems << "\">";
						for (int k=0; k<m_OSOption->optimization->solverOptions->solverOption[i]->numberOfItems; k++)
							outStr << "<item>" << m_OSOption->optimization->solverOptions->solverOption[i]->item[k] << "</item>" << endl;
						outStr << "</solverOption>" << endl;
				}
				}
				outStr << "</solverOptions>" << endl;
			}
		}
		outStr << "</optimization>" << endl;
	};
	outStr << "</osol>" << endl;
#ifdef DEBUG
	cout << "Done with <optimization> element" << endl;
#endif
	return outStr.str();
}// end writeOSoL



