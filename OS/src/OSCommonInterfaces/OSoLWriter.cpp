/** @file OSoLWriter.cpp
 * 
 *
 * @author  Robert Fourer, Gus Gassmann, Jun Ma, Kipp Martin, 
 * @version 1.0, 17/July/2008
 * @since   OS1.1
 *
 * \remarks
 * Copyright (C) 2005, Gus Gassmann, Jun Ma, Kipp Martin,
 * Northwestern University, Dalhousie University and the University of Chicago.
 * All Rights Reserved.
 * This software is licensed under the Common Public License. 
 * Please see the accompanying LICENSE file in root directory for terms.
 * 
 */
 
 
#include "OSoLWriter.h"
#include "OSOption.h"
#include "OSParameters.h"
#include "OSCommonUtil.h"
#include "OSConfig.h"
#include <sstream>   
#include <iostream>  
#include <stdio.h>

using std::cout;
using std::endl;
using std::ostringstream;

OSoLWriter::OSoLWriter( ) {	 
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
	xsltDir = "../stylesheets/";
	if(m_OSOption == NULL)  return outStr.str(); 
	outStr << "<?xml version=\"1.0\" encoding=\"UTF-8\"?>" ; 
	outStr << "<?xml-stylesheet type = \"text/xsl\" href = \"";
	outStr << xsltDir;
	outStr << "OSoL.xslt\"?>";
	outStr << "<osol xmlns=\"os.optimizationservices.org\"   xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\" xsi:schemaLocation=\"os.optimizationservices.org http://www.optimizationservices.org/schemas/OSoL.xsd\" >" ;
	outStr << endl;

/**
 * 	Put the <general> element
 */
	if(m_OSOption->general != NULL)
	{	outStr << "<general>" << endl;
		if (m_OSOption->general->serviceURI != "")
			outStr << "<serviceURI>" << m_OSOption->general->serviceURI << "</serviceURI>" << endl;
		if (m_OSOption->general->serviceName != "")
			outStr << "<serviceName>" << m_OSOption->general->serviceName << "</serviceName>" << endl;
		if (m_OSOption->general->instanceName != "")
			outStr << "<instanceName>" << m_OSOption->general->instanceName << "</instanceName>" << endl;
		if (m_OSOption->general->instanceLocation != NULL)
		{	if (m_OSOption->general->instanceLocation->locationType == "")
			{	outStr << "<instanceLocation>";
			}
			else 
			{	outStr << "<instanceLocation locationType=\"" << m_OSOption->general->instanceLocation->locationType << "\">";
			};
			outStr << m_OSOption->general->instanceLocation->value << "</instanceLocation>" << endl;
		};
		if (m_OSOption->general->jobID != "")
		{	outStr << "<jobID>" << m_OSOption->general->jobID << "</jobID>" << endl;
		};
		if (m_OSOption->general->license != "")
		{	outStr << "<license>" << m_OSOption->general->license << "</license>" << endl;
		};
		if (m_OSOption->general->userName != "")
		{	outStr << "<userName>" << m_OSOption->general->userName << "</userName>" << endl;
		};
		if (m_OSOption->general->password != "")
		{	outStr << "<password>" << m_OSOption->general->password << "</password>" << endl;
		};
		if (m_OSOption->general->contact != NULL)
		{	if (m_OSOption->general->contact->transportType == "")
			{	outStr << "<contact>";
			}
			else 
			{	outStr << "<contact transportType=\"" << m_OSOption->general->contact->transportType << "\">";
			};
			outStr << m_OSOption->general->contact->value << "</contact>" << endl;
		};
		if (m_OSOption->general->otherOptions != NULL)
		{	if (m_OSOption->general->otherOptions->numberOfOtherOptions > 0)
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
		cout << "Done with <general> element" << endl;
	};

/**
 * 	Put the <system> element
 */
	if(m_OSOption->system != NULL)
	{	outStr << "<system>" << endl;
		if (m_OSOption->system->minDiskSpace != NULL)
		{	if (m_OSOption->system->minDiskSpace->unit == "")
				m_OSOption->system->minDiskSpace->unit = "byte";
			outStr << "<minDiskSpace unit=\"" << m_OSOption->system->minDiskSpace->unit << "\">";
			outStr << m_OSOption->system->minDiskSpace->value << "</minDiskSpace>" << endl;
		}
		if (m_OSOption->system->minMemorySize != NULL)
		{	if (m_OSOption->system->minMemorySize->unit == "")
				m_OSOption->system->minMemorySize->unit = "byte";
			outStr << "<minMemorySize unit=\"" << m_OSOption->system->minMemorySize->unit << "\">";
			outStr << m_OSOption->system->minMemorySize->value << "</minMemorySize>" << endl;
		}
		if (m_OSOption->system->minCPUSpeed != NULL)
		{	if (m_OSOption->system->minCPUSpeed->unit == "")
				m_OSOption->system->minCPUSpeed->unit = "hertz";
			outStr << "<minCPUSpeed unit=\"" << m_OSOption->system->minCPUSpeed->unit << "\">";
			outStr << m_OSOption->system->minCPUSpeed->value << "</minCPUSpeed>" << endl;
		}
		if (m_OSOption->system->minCPUNumber > 0.0)
		{	outStr << "<minCPUNumber>" << m_OSOption->system->minCPUNumber << "</minCPUNumber>";
		};
		if (m_OSOption->system->otherOptions != NULL)
		{	if (m_OSOption->system->otherOptions->numberOfOtherOptions > 0)
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
		cout << "Done with <system> element" << endl;
	};

/**
 * 	Put the <service> element
 */
	if(m_OSOption->service != NULL)
	{	outStr << "<service>" << endl;
		if (m_OSOption->service->type != "")
		{	outStr << "<type>" << m_OSOption->service->type << "</type>" << endl;
		};
		if (m_OSOption->service->otherOptions != NULL)
		{	if (m_OSOption->service->otherOptions->numberOfOtherOptions > 0)
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
		cout << "Done with <service> element" << endl;
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
				outStr << m_OSOption->job->maxTime->value << "</maxTime>" << endl;
		}
		if (m_OSOption->job->scheduledStartTime != "")
			outStr << "<scheduledStartTime>" << m_OSOption->job->scheduledStartTime << "</scheduledStartTime>" << endl;
		cout << "Before <dependencies>" << endl;
		if (m_OSOption->job->dependencies != NULL)
		{	cout << "Starting <dependencies>" << endl;
			if (m_OSOption->job->dependencies->numberOfJobIDs > 0)
			{	outStr << "<dependencies numberOfJobIDs=\"";
				outStr << m_OSOption->job->dependencies->numberOfJobIDs << "\">" << endl; 
				cout << "<dependencies numberOfJobIDs=\"";
				cout << m_OSOption->job->dependencies->numberOfJobIDs << "\">" << endl; 
				cout << "Put <dependencies> job list" << endl;
				for (int i=0; i < m_OSOption->job->dependencies->numberOfJobIDs; i++)
				{	cout << "job " << i << endl;
					outStr << "<jobID>" << m_OSOption->job->dependencies->jobID[i] << "</jobID>" << endl;
				}
				outStr << "</dependencies>" << endl;
		cout << "Done with <dependencies>" << endl;
			}
		}
		if (m_OSOption->job->requiredDirectories != NULL)
		{	if (m_OSOption->job->requiredDirectories->numberOfPaths > 0)
			{	outStr << "<requiredDirectories numberOfPaths=\"";
				outStr << m_OSOption->job->requiredDirectories->numberOfPaths << "\">" << endl; 
				for (int i=0; i < m_OSOption->job->requiredDirectories->numberOfPaths; i++)
					outStr << "<path>" << m_OSOption->job->requiredDirectories->path[i] << "</path>" << endl;
				outStr << "</requiredDirectories>" << endl;
			}
		}
		if (m_OSOption->job->requiredFiles != NULL)
		{	if (m_OSOption->job->requiredFiles->numberOfPaths > 0)
			{	outStr << "<requiredFiles numberOfPaths=\"";
				outStr << m_OSOption->job->requiredFiles->numberOfPaths << "\">" << endl; 
				for (int i=0; i < m_OSOption->job->requiredFiles->numberOfPaths; i++)
					outStr << "<path>" << m_OSOption->job->requiredFiles->path[i] << "</path>" << endl;
				outStr << "</requiredFiles>" << endl;
			}
		}
		if (m_OSOption->job->directoriesToMake != NULL)
		{	if (m_OSOption->job->directoriesToMake->numberOfPaths > 0)
			{	outStr << "<directoriesToMake numberOfPaths=\"";
				outStr << m_OSOption->job->directoriesToMake->numberOfPaths << "\">" << endl; 
				for (int i=0; i < m_OSOption->job->directoriesToMake->numberOfPaths; i++)
					outStr << "<path>" << m_OSOption->job->directoriesToMake->path[i] << "</path>" << endl;
				outStr << "</directoriesToMake>" << endl;
			}
		}
		if (m_OSOption->job->filesToMake != NULL)
		{	if (m_OSOption->job->filesToMake->numberOfPaths > 0)
			{	outStr << "<filesToMake numberOfPaths=\"";
				outStr << m_OSOption->job->filesToMake->numberOfPaths << "\">" << endl; 
				for (int i=0; i < m_OSOption->job->filesToMake->numberOfPaths; i++)
					outStr << "<path>" << m_OSOption->job->filesToMake->path[i] << "</path>" << endl;
				outStr << "</filesToMake>" << endl;
			}
		}
		if (m_OSOption->job->inputDirectoriesToMove != NULL)
		{	if (m_OSOption->job->inputDirectoriesToMove->numberOfPathPairs > 0)
			{	outStr << "<inputDirectoriesToMove numberOfPathPairs=\"";
				outStr << m_OSOption->job->inputDirectoriesToMove->numberOfPathPairs << "\">" << endl; 
				for (int i=0; i < m_OSOption->job->inputDirectoriesToMove->numberOfPathPairs; i++)
				{	outStr << "<pathPair";
					outStr << " from=\"" << m_OSOption->job->inputDirectoriesToMove->pathPair[i]->from << "\"";
					outStr << " to=\"" << m_OSOption->job->inputDirectoriesToMove->pathPair[i]->to << "\"";
					outStr << " makeCopy=\"" << m_OSOption->job->inputDirectoriesToMove->pathPair[i]->makeCopy << "\"/>";
				}
				outStr << "</inputDirectoriesToMove>" << endl;
			}
		}
		if (m_OSOption->job->inputFilesToMove != NULL)
		{	if (m_OSOption->job->inputFilesToMove->numberOfPathPairs > 0)
			{	outStr << "<inputFilesToMove numberOfPathPairs=\"";
				outStr << m_OSOption->job->inputFilesToMove->numberOfPathPairs << "\">" << endl; 
				for (int i=0; i < m_OSOption->job->inputFilesToMove->numberOfPathPairs; i++)
				{	outStr << "<pathPair";
					outStr << " from=\"" << m_OSOption->job->inputFilesToMove->pathPair[i]->from << "\"";
					outStr << " to=\"" << m_OSOption->job->inputFilesToMove->pathPair[i]->to << "\"";
					outStr << " makeCopy=\"" << m_OSOption->job->inputFilesToMove->pathPair[i]->makeCopy << "\"/>";
				}
				outStr << "</inputFilesToMove>" << endl;
			}
		}
		if (m_OSOption->job->outputFilesToMove != NULL)
		{	if (m_OSOption->job->outputFilesToMove->numberOfPathPairs > 0)
			{	outStr << "<outputFilesToMove numberOfPathPairs=\"";
				outStr << m_OSOption->job->outputFilesToMove->numberOfPathPairs << "\">" << endl; 
				for (int i=0; i < m_OSOption->job->outputFilesToMove->numberOfPathPairs; i++)
				{	outStr << "<pathPair";
					outStr << " from=\"" << m_OSOption->job->outputFilesToMove->pathPair[i]->from << "\"";
					outStr << " to=\"" << m_OSOption->job->outputFilesToMove->pathPair[i]->to << "\"";
					outStr << " makeCopy=\"" << m_OSOption->job->outputFilesToMove->pathPair[i]->makeCopy << "\"/>";
				}
				outStr << "</outputFilesToMove>" << endl;
			}
		}
		if (m_OSOption->job->outputDirectoriesToMove != NULL)
		{	if (m_OSOption->job->outputDirectoriesToMove->numberOfPathPairs > 0)
			{	outStr << "<outputDirectoriesToMove numberOfPathPairs=\"";
				outStr << m_OSOption->job->outputDirectoriesToMove->numberOfPathPairs << "\">" << endl; 
				for (int i=0; i < m_OSOption->job->outputDirectoriesToMove->numberOfPathPairs; i++)
				{	outStr << "<pathPair";
					outStr << " from=\"" << m_OSOption->job->outputDirectoriesToMove->pathPair[i]->from << "\"";
					outStr << " to=\"" << m_OSOption->job->outputDirectoriesToMove->pathPair[i]->to << "\"";
					outStr << " makeCopy=\"" << m_OSOption->job->outputDirectoriesToMove->pathPair[i]->makeCopy << "\"/>";
				}
				outStr << "</outputDirectoriesToMove>" << endl;
			}
		}
		if (m_OSOption->job->filesToDelete != NULL)
		{	if (m_OSOption->job->filesToDelete->numberOfPaths > 0)
			{	outStr << "<filesToDelete numberOfPaths=\"";
				outStr << m_OSOption->job->filesToDelete->numberOfPaths << "\">" << endl; 
				for (int i=0; i < m_OSOption->job->filesToDelete->numberOfPaths; i++)
					outStr << "<path>" << m_OSOption->job->filesToDelete->path[i] << "</path>" << endl;
				outStr << "</filesToDelete>" << endl;
			}
		}
		if (m_OSOption->job->directoriesToDelete != NULL)
		{	if (m_OSOption->job->directoriesToDelete->numberOfPaths > 0)
			{	outStr << "<directoriesToDelete numberOfPaths=\"";
				outStr << m_OSOption->job->directoriesToDelete->numberOfPaths << "\">" << endl; 
				for (int i=0; i < m_OSOption->job->directoriesToDelete->numberOfPaths; i++)
					outStr << "<path>" << m_OSOption->job->directoriesToDelete->path[i] << "</path>" << endl;
				outStr << "</directoriesToDelete>" << endl;
			}
		}
		if (m_OSOption->job->processesToKill != NULL)
		{	if (m_OSOption->job->processesToKill->numberOfProcesses > 0)
			{	outStr << "<processesToKill numberOfProcesses=\"";
				outStr << m_OSOption->job->processesToKill->numberOfProcesses << "\">" << endl; 
				for (int i=0; i < m_OSOption->job->processesToKill->numberOfProcesses; i++)
					outStr << "<process>" << m_OSOption->job->processesToKill->process[i] << "</process>" << endl;
				outStr << "</processesToKill>" << endl;
			}
		}
		if (m_OSOption->job->otherOptions != NULL)
		{	if (m_OSOption->job->otherOptions->numberOfOtherOptions > 0)
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
		cout << "Done with <job> element" << endl;
	};

/**
 * 	Put the <optimization> element
 */
	if(m_OSOption->optimization != NULL)
	{	outStr << "<optimization";
		outStr << " numberOfVariables=\"" << m_OSOption->optimization->numberOfVariables << "\" ";
		outStr << " numberOfObjectives=\"" << m_OSOption->optimization->numberOfObjectives << "\" ";
		outStr << " numberOfConstraints=\"" << m_OSOption->optimization->numberOfConstraints << "\" ";
		outStr << ">" << endl;
		if (m_OSOption->optimization->variables != NULL)
		{	outStr << "<variables";
			if (m_OSOption->optimization->variables->numberOfOtherVariableOptions > 0)
				outStr << " numberOfOtherVariableOptions=\"" << m_OSOption->optimization->variables->numberOfOtherVariableOptions << "\"";
			outStr << ">" << endl;
			if (m_OSOption->optimization->variables->initialVariableValues != NULL)
			{	outStr << "<initialVariableValues numberOfVar=\"";
				outStr << m_OSOption->optimization->variables->initialVariableValues->numberOfVar << "\">" << endl;
				for (int i=0; i < m_OSOption->optimization->variables->initialVariableValues->numberOfVar; i++)
				{	outStr << "<var";
					outStr << " idx=\"" << m_OSOption->optimization->variables->initialVariableValues->var[i]->idx << "\"";
					outStr << " value=\"";
					if (m_OSOption->optimization->variables->initialVariableValues->var[i]->value == OSDBL_MAX)
						outStr << "INF";
					else if (m_OSOption->optimization->variables->initialVariableValues->var[i]->value == -OSDBL_MAX)
						outStr << "-INF";
					else
						outStr << m_OSOption->optimization->variables->initialVariableValues->var[i]->value;
					outStr << "\"/>" << endl;
				}
				outStr << "</initialVariableValues>" << endl;
			}
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
	printf("\n%s%d\n","Number of other variable options: ",m_OSOption->optimization->variables->numberOfOtherVariableOptions);
			if (m_OSOption->optimization->variables->numberOfOtherVariableOptions > 0)
				for (int i=0; i < m_OSOption->optimization->variables->numberOfOtherVariableOptions; i++)
				{	outStr << "<other name=\"" << m_OSOption->optimization->variables->other[i]->name << "\"";
					if (m_OSOption->optimization->variables->other[i]->numberOfVar > 0)
						outStr << " numberOfVar=\"" << m_OSOption->optimization->variables->other[i]->numberOfVar << "\"";
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
					if (m_OSOption->optimization->variables->other[i]->numberOfVar > 0)
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
					outStr << "</other>" << endl;
				}

			outStr << "</variables>" << endl;
		}
		if (m_OSOption->optimization->objectives != NULL)
		{	outStr << "<objectives";
			if (m_OSOption->optimization->objectives->numberOfOtherObjectiveOptions > 0)
				outStr << " numberOfOtherObjectiveOptions=\"" << m_OSOption->optimization->objectives->numberOfOtherObjectiveOptions << "\"";
			outStr << ">" << endl;
			if (m_OSOption->optimization->objectives->initialObjectiveValues != NULL)
			{	outStr << "<initialObjectiveValues numberOfObj=\"";
				outStr << m_OSOption->optimization->objectives->initialObjectiveValues->numberOfObj << "\">" << endl;
				for (int i=0; i < m_OSOption->optimization->objectives->initialObjectiveValues->numberOfObj; i++)
				{	outStr << "<obj";
					outStr << " idx=\"" << m_OSOption->optimization->objectives->initialObjectiveValues->obj[i]->idx << "\"";
					outStr << " value=\"";
					if (m_OSOption->optimization->objectives->initialObjectiveValues->obj[i]->value == OSDBL_MAX)
						outStr << "INF";
					else if (m_OSOption->optimization->objectives->initialObjectiveValues->obj[i]->value == -OSDBL_MAX)
						outStr << "-INF";
					else
						outStr << m_OSOption->optimization->objectives->initialObjectiveValues->obj[i]->value;
					outStr << "\"/>" << endl;
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
						outStr << m_OSOption->optimization->objectives->initialObjectiveBounds->obj[i]->lbValue;
					outStr << "\" ubValue=\"";
					if (m_OSOption->optimization->objectives->initialObjectiveBounds->obj[i]->ubValue == OSDBL_MAX)
						outStr << "INF";
					else if (m_OSOption->optimization->objectives->initialObjectiveBounds->obj[i]->ubValue == -OSDBL_MAX)
						outStr << "-INF";
					else
						outStr << m_OSOption->optimization->objectives->initialObjectiveBounds->obj[i]->ubValue;
					outStr << "\"/>" << endl;
				}
				outStr << "</initialObjectiveBounds>" << endl;
			}
			if (m_OSOption->optimization->objectives->numberOfOtherObjectiveOptions > 0)
				for (int i=0; i < m_OSOption->optimization->objectives->numberOfOtherObjectiveOptions; i++)
				{	outStr << "<other name=\"" << m_OSOption->optimization->objectives->other[i]->name << "\"";
					if (m_OSOption->optimization->objectives->other[i]->numberOfObj > 0)
						outStr << " numberOfObj=\"" << m_OSOption->optimization->objectives->other[i]->numberOfObj << "\"";
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
					if (m_OSOption->optimization->objectives->other[i]->numberOfObj > 0)
						for (int j=0; j < m_OSOption->optimization->objectives->other[i]->numberOfObj; j++)
						{	outStr << "<var idx=\"" << m_OSOption->optimization->objectives->other[i]->obj[j]->idx << "\"";
							if (m_OSOption->optimization->objectives->other[i]->obj[j]->value != "")
								outStr << " value=\"" << m_OSOption->optimization->objectives->other[i]->obj[j]->value << "\"";
							outStr << "/>" << endl;
						}
					outStr << "</other>" << endl;
				}
			outStr << "</objectives>" << endl;
		}
		if (m_OSOption->optimization->constraints != NULL)
		{	outStr << "<constraints";
			if (m_OSOption->optimization->constraints->numberOfOtherConstraintOptions > 0)
				outStr << " numberOfOtherConstraintOptions=\"" << m_OSOption->optimization->constraints->numberOfOtherConstraintOptions << "\"";
			outStr << ">" << endl;
			if (m_OSOption->optimization->constraints->initialConstraintValues != NULL)
			{	outStr << "<initialConstraintValues numberOfCon=\"";
				outStr << m_OSOption->optimization->constraints->initialConstraintValues->numberOfCon << "\">" << endl;
				for (int i=0; i < m_OSOption->optimization->constraints->initialConstraintValues->numberOfCon; i++)
				{	outStr << "<con";
					outStr << " idx=\"" << m_OSOption->optimization->constraints->initialConstraintValues->con[i]->idx << "\"";
					outStr << " value=\"";
					if (m_OSOption->optimization->constraints->initialConstraintValues->con[i]->value == OSDBL_MAX)
						outStr << "INF";
					else if (m_OSOption->optimization->constraints->initialConstraintValues->con[i]->value == -OSDBL_MAX)
						outStr << "-INF";
					else
						outStr << m_OSOption->optimization->constraints->initialConstraintValues->con[i]->value;
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
					outStr << " lbValue=\"";
					if (m_OSOption->optimization->constraints->initialDualValues->con[i]->lbValue == OSDBL_MAX)
						outStr << "INF";
					else if (m_OSOption->optimization->constraints->initialDualValues->con[i]->lbValue == -OSDBL_MAX)
						outStr << "-INF";
					else
						outStr << m_OSOption->optimization->constraints->initialDualValues->con[i]->lbValue;
					outStr << "\" ubValue=\"";
					if (m_OSOption->optimization->constraints->initialDualValues->con[i]->ubValue == OSDBL_MAX)
						outStr << "INF";
					else if (m_OSOption->optimization->constraints->initialDualValues->con[i]->ubValue == -OSDBL_MAX)
						outStr << "-INF";
					else
						outStr << m_OSOption->optimization->constraints->initialDualValues->con[i]->ubValue;
					outStr << "\"/>" << endl;
				}
				outStr << "</initialDualValues>" << endl;
			}
			if (m_OSOption->optimization->constraints->numberOfOtherConstraintOptions > 0)
				for (int i=0; i < m_OSOption->optimization->constraints->numberOfOtherConstraintOptions; i++)
				{	outStr << "<other name=\"" << m_OSOption->optimization->constraints->other[i]->name << "\"";
					if (m_OSOption->optimization->constraints->other[i]->numberOfCon > 0)
						outStr << " numberOfCon=\"" << m_OSOption->optimization->constraints->other[i]->numberOfCon << "\"";
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
					if (m_OSOption->optimization->constraints->other[i]->numberOfCon > 0)
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
					outStr << "</other>" << endl;
				}
			outStr << "</constraints>" << endl;
		}
		if (m_OSOption->optimization->solverOptions != NULL)
		{	if (m_OSOption->optimization->solverOptions->numberOfSolverOptions > 0)
			{	outStr << "<solverOptions numberOfSolverOptions=\""; 
				outStr << m_OSOption->optimization->solverOptions->numberOfSolverOptions << "\">" << endl;
				for (int i=0; i < m_OSOption->optimization->solverOptions->numberOfSolverOptions; i++)
				{	outStr << "<solverOption name=\"" << m_OSOption->optimization->solverOptions->solverOption[i]->name << "\"";
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
					outStr << "/>" << endl;
				}
				outStr << "</solverOptions>" << endl;
			}
		}
		outStr << "</optimization>" << endl;
	};
	outStr << "</osol>" << endl;
	return outStr.str();
}// end writeOSoL



