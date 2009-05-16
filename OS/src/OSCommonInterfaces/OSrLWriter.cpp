/** @file OSrLWriter.cpp
 * 
 *
 * @author  Robert Fourer, Horand Gassmann, Jun Ma, Kipp Martin, 
 * @version 1.0, 10/05/2005
 * @since   OS1.0
 *
 * \remarks
 * Copyright (C) 2005-2009, Robert Fourer, Horand Gassmann, Jun Ma, Kipp Martin,
 * Northwestern University, Dalhousie University and the University of Chicago.
 * All Rights Reserved.
 * This software is licensed under the Common Public License. 
 * Please see the accompanying LICENSE file in root directory for terms.
 * 
 */
 
 
//#define DEBUG




#include "OSrLWriter.h"
#include "OSResult.h"

#include "OSDataStructures.h"
#include "OSParameters.h" 
#include "OSCommonUtil.h"
#include "OSMathUtil.h"

  


#include <sstream>   
#include <iostream>  

using std::cout;
using std::endl;
using std::ostringstream;

OSrLWriter::OSrLWriter( ) {	 
}

OSrLWriter::~OSrLWriter(){
}


/*char* OSrLWriter::writeOSrLWrap( OSResult *theosresult){
	std::string sTmp = writeOSrL( theosresult);
	char *ch;
    ch = new char[sTmp.size() + 1];
    strcpy(ch, sTmp.c_str());
	return ch;
}
*/




 
std::string OSrLWriter::writeOSrL( OSResult *theosresult){
	m_OSResult = theosresult;
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
	int i, j;
#ifdef DEBUG
	cout << "in OSrLWriter" << endl;
#endif
	if(m_OSResult == NULL)  return outStr.str(); 
	outStr << "<?xml version=\"1.0\" encoding=\"UTF-8\"?>" ; 
	outStr << "<?xml-stylesheet type=\"text/xsl\" href=\"";
	outStr << xsltDir;
	outStr << "OSrL.xslt\"?>";
	outStr << endl;
	outStr << "<osrl xmlns=\"os.optimizationservices.org\"   xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\" ";
	outStr << "xsi:schemaLocation=\"os.optimizationservices.org http://www.optimizationservices.org/schemas/";
	outStr << OS_SCHEMA_VERSION;
	outStr << "/OSrL.xsd\" >" ;
	outStr << endl;
#ifdef DEBUG
	cout << "output <general>" << endl;
#endif
	if(m_OSResult->general != NULL){
		outStr << "<general>" << endl;
		if(m_OSResult->general->generalStatus != NULL){
			outStr << "<generalStatus "    ;
			if(m_OSResult->general->generalStatus->type.length() > 0){
				outStr << "type=\"";
				outStr << m_OSResult->general->generalStatus->type ;
				outStr << "\"";
			}
			if(m_OSResult->general->generalStatus->description.length() > 0){
				outStr << "type=\"";
				outStr << m_OSResult->general->generalStatus->description ;
				outStr << "\"";
			}
			outStr << "/>" << endl;
		}		
		
		if(m_OSResult->general->serviceURI.length() > 0){
			outStr << "<serviceURI>" + m_OSResult->general->serviceURI + "</serviceURI>"  << endl;
		}

		if(m_OSResult->general->serviceName.length() > 0){
			outStr << "<serviceName>" + m_OSResult->general->serviceName + "</serviceName>"  << endl;
		}
		if(m_OSResult->general->instanceName.length() > 0){
			outStr << "<instanceName>" + m_OSResult->general->instanceName  + "</instanceName>" << endl;
		}
		if(m_OSResult->general->jobID.length() > 0){
			outStr << "<jobID>" + m_OSResult->general->jobID  + "</jobID>" << endl;
		}
		if(m_OSResult->general->message.length() > 0){
			outStr << "<message>" + m_OSResult->general->message  + "</message>" << endl;
		}
		outStr << "</general>" << endl;
	}
#ifdef DEBUG
	cout << "output <system>" << endl;
#endif
	if(m_OSResult->system != NULL){
	}
#ifdef DEBUG
	cout << "output <service>" << endl;
#endif
	if(m_OSResult->service != NULL){
	}
#ifdef DEBUG
	cout << "output <job>" << endl;
#endif
	if(m_OSResult->job != NULL){
		outStr << "<job>" << endl;
		if (m_OSResult->job->timingInformation != NULL)
			if (m_OSResult->job->timingInformation->numberOfTimes > 0)
			{	outStr << "<timingInformation numberOfTimes=\"";
				outStr << m_OSResult->job->timingInformation->numberOfTimes << "\">" << endl;
				for (i=0; i<m_OSResult->job->timingInformation->numberOfTimes; i++)
				{	outStr << "<time ";
					if (m_OSResult->job->timingInformation->time[i]->type != "")
						outStr << "type=\"" << m_OSResult->job->timingInformation->time[i]->type << "\" ";
					if (m_OSResult->job->timingInformation->time[i]->unit != "")
						outStr << "unit=\"" << m_OSResult->job->timingInformation->time[i]->unit << "\" ";
					if (m_OSResult->job->timingInformation->time[i]->category != "")
						outStr << "category=\"" << m_OSResult->job->timingInformation->time[i]->category << "\" ";
					if (m_OSResult->job->timingInformation->time[i]->description != "")
						outStr << "description=\"" << m_OSResult->job->timingInformation->time[i]->description << "\" ";
					outStr << ">" << endl;
					outStr << os_dtoa_format(m_OSResult->job->timingInformation->time[i]->value);
					outStr << "</time>" << endl; 
				}
				outStr << "</timingInformation>" << endl;
			}
		outStr << "</job>" << endl;
	}
#ifdef DEBUG
	cout << "output <optimization>" << endl;
#endif
	if(m_OSResult->optimization != NULL && m_OSResult->optimization->numberOfSolutions > 0){
		outStr << "<optimization " ;
		outStr << "numberOfSolutions=\"";
		outStr << m_OSResult->optimization->numberOfSolutions ;
		outStr <<  "\"";
		outStr << " numberOfVariables=\"";
		outStr << m_OSResult->optimization->numberOfVariables ;
		outStr <<  "\"";
		outStr << " numberOfConstraints=\"";
		outStr << m_OSResult->optimization->numberOfConstraints ;
		outStr <<  "\"";
		outStr << " numberOfObjectives=\"";
		outStr << m_OSResult->optimization->numberOfObjectives ;
		outStr << "\"" ;
		outStr << ">" << endl;
		// get solution information
		for(i = 0; i < m_OSResult->optimization->numberOfSolutions; i++){
			if(m_OSResult->optimization->solution[i] != NULL){
				outStr << "<solution" ;
				outStr << " targetObjectiveIdx=\"";
				outStr << m_OSResult->optimization->solution[i]->targetObjectiveIdx ;
				outStr << "\"" ;
				outStr << ">" << endl;
				if(m_OSResult->optimization->solution[i]->status != NULL){
					outStr << "<status";
					if(m_OSResult->optimization->solution[i]->status->type.length() > 0){
						outStr << " type=\"";
						outStr << m_OSResult->optimization->solution[i]->status->type;
						outStr <<  "\"";
					}
					if(m_OSResult->optimization->solution[i]->status->description.length() > 0){
						outStr << " description=\"";
						outStr <<  m_OSResult->optimization->solution[i]->status->description;
						outStr << "\"" ;
					}
					outStr << "/>" << endl;
				}
				if(m_OSResult->optimization->solution[i]->message != ""){
					outStr << "<message>" << endl;
					outStr << m_OSResult->optimization->solution[i]->message  << endl;
					outStr << "</message>" << endl;
				}
				if(m_OSResult->optimization->solution[i]->variables != NULL){
					outStr << "<variables ";
					if (m_OSResult->optimization->solution[i]->variables->numberOfOtherVariableResults > 0)
						outStr << "numberOfOtherVariableResults=\"" << m_OSResult->optimization->solution[i]->variables->numberOfOtherVariableResults << "\""; 
					outStr << ">" << endl;
					if(m_OSResult->optimization->solution[i]->variables->values != NULL){
#ifdef DEBUG
	cout << "output <variables> <values>" << endl;
#endif
						outStr << "<values numberOfVar=\"" << m_OSResult->optimization->solution[i]->variables->values->numberOfVar << "\">" << endl;
						for(j = 0; j < m_OSResult->optimization->solution[i]->variables->values->numberOfVar; j++){
							if(m_OSResult->optimization->solution[i]->variables->values->var[j] != NULL){
								outStr << "<var";
								outStr << " idx=\"";
								outStr << j ;
								outStr <<  "\">";
								outStr <<  os_dtoa_format( m_OSResult->optimization->solution[i]->variables->values->var[j]->value );
								outStr << "</var>" << endl;
							}
						}
						outStr << "</values>" << endl;
					}
#ifdef DEBUG
	cout << "output <variables> <other>" << endl;
#endif
					if(m_OSResult->optimization->solution[i]->variables->other != NULL){
						if(m_OSResult->optimization->solution[i]->variables->numberOfOtherVariableResults > 0){
							for(int k = 0; k < m_OSResult->optimization->solution[i]->variables->numberOfOtherVariableResults; k++){

								outStr << "<other" ;
								outStr << " numberOfVar=\"";
								outStr << m_OSResult->optimization->solution[i]->variables->other[k]->numberOfVar;
								outStr << "\"" ;
								if (m_OSResult->optimization->solution[i]->variables->other[k]->name != "")
								{
									outStr << " name=\"";
									outStr << m_OSResult->optimization->solution[i]->variables->other[k]->name;
									outStr << "\"" ;
								}
								if (m_OSResult->optimization->solution[i]->variables->other[k]->value != "")
								{
									outStr << " value=\"";
									outStr << m_OSResult->optimization->solution[i]->variables->other[k]->value;
									outStr << "\"" ;
								}
								if (m_OSResult->optimization->solution[i]->variables->other[k]->description != "")
								{
									outStr << " description=\"";
									outStr << m_OSResult->optimization->solution[i]->variables->other[k]->description;
									outStr << "\"" ;
								}
								outStr <<  ">" << endl;
								if(m_OSResult->optimization->solution[i]->variables->other[k]->var.size() > 0){
									for(j = 0; j < m_OSResult->optimization->solution[i]->variables->other[k]->numberOfVar; j++){
										if(m_OSResult->optimization->solution[i]->variables->other[k]->var.size() > 0){
											outStr << "<var";
											outStr << " idx=\"";
											outStr << m_OSResult->optimization->solution[i]->variables->other[k]->var[j]->idx ;
											outStr <<  "\">";
											outStr << m_OSResult->optimization->solution[i]->variables->other[k]->var[j]->value;
											outStr << "</var>" << endl;
										}
									}
								}
								outStr << "</other>" << endl;
							}
						}
					} // end of if on other variables
					outStr << "</variables>" << endl;
				}
				//
				//
				//
				if(m_OSResult->optimization->solution[i]->objectives != NULL){
					outStr << "<objectives ";
					if (m_OSResult->optimization->solution[i]->objectives->numberOfOtherObjectiveResults > 0)
						outStr << "numberOfOtherObjectiveResults=\"" << m_OSResult->optimization->solution[i]->objectives->numberOfOtherObjectiveResults << "\""; 
					outStr << ">" << endl;
#ifdef DEBUG
	cout << "output <objectives> <values>" << endl;
#endif
					if(m_OSResult->optimization->solution[i]->objectives->values != NULL){
						outStr << "<values numberOfObj=\"" << m_OSResult->optimization->solution[i]->objectives->values->numberOfObj << "\">" << endl;
						for(j = 0; j < m_OSResult->optimization->solution[i]->objectives->values->numberOfObj; j++){
							if(m_OSResult->optimization->solution[i]->objectives->values->obj[j] != NULL){
								outStr << "<obj";
								outStr << " idx=\"";
								outStr << m_OSResult->optimization->solution[i]->objectives->values->obj[j]->idx; //-(1 + j) ;
								outStr <<  "\">";
								outStr <<  os_dtoa_format( m_OSResult->optimization->solution[i]->objectives->values->obj[j]->value);
								outStr << "</obj>" << endl;
							}
						}

						outStr << "</values>" << endl;
					}
#ifdef DEBUG
	cout << "output <objectives> <other>" << endl;
#endif
					if(m_OSResult->optimization->solution[i]->objectives->other != NULL){
						if(m_OSResult->optimization->solution[i]->objectives->numberOfOtherObjectiveResults > 0){
							for(int k = 0; k < m_OSResult->optimization->solution[i]->objectives->numberOfOtherObjectiveResults; k++){
								outStr << "<other" ;
								outStr << " name=\"";\
								outStr << m_OSResult->optimization->solution[i]->objectives->other[k]->name;
								outStr << "\"" ;
								outStr << " description=\"";
								outStr << m_OSResult->optimization->solution[i]->objectives->other[k]->description;
								outStr << "\"" ;
								outStr <<  ">" << endl;
								if(m_OSResult->optimization->solution[i]->objectives->other[k]->obj.size() > 0){
									for(j = 0; j < m_OSResult->optimization->solution[i]->objectives->other[k]->numberOfObj; j++){
										if(m_OSResult->optimization->solution[i]->objectives->other[k]->obj.size() > 0){
											outStr << "<obj";
											outStr << " idx=\"";
											outStr << j ;
											outStr <<  "\">";
											outStr <<   m_OSResult->optimization->solution[i]->objectives->other[k]->obj[j]->value;
											outStr << "</obj>" << endl;
										}
									}
								}
								outStr << "</other>" << endl;
							}
						}
					} // end of if on other objectives
					outStr << "</objectives>" << endl;
				}
				if(m_OSResult->optimization->solution[i]->constraints != NULL){
					outStr << "<constraints ";
					if (m_OSResult->optimization->solution[i]->constraints->numberOfOtherConstraintResults > 0)
						outStr << "numberOfOtherConstraintResults=\"" << m_OSResult->optimization->solution[i]->constraints->numberOfOtherConstraintResults << "\""; 
					outStr << ">" << endl;
#ifdef DEBUG
	cout << "output <constraints> <dualValues>" << endl;
#endif
					if(m_OSResult->optimization->solution[i]->constraints->dualValues != NULL){
						outStr << "<dualValues numberOfCon=\"" << m_OSResult->optimization->solution[i]->constraints->dualValues->numberOfCon << "\">" << endl;
						for(j = 0; j < m_OSResult->optimization->solution[i]->constraints->dualValues->numberOfCon; j++){
							if(m_OSResult->optimization->solution[i]->constraints->dualValues->con[j] != NULL){
								outStr << "<con";
								outStr << " idx=\"";
								outStr <<  j ;
								outStr <<  "\">";
								outStr <<  os_dtoa_format( m_OSResult->optimization->solution[i]->constraints->dualValues->con[j]->value);
								outStr << "</con>" << endl;
							}
						}
						outStr << "</dualValues>" << endl;
					}
#ifdef DEBUG
	cout << "output <constraints> <other>" << endl;
#endif
					if(m_OSResult->optimization->solution[i]->constraints->other != NULL){
						if(m_OSResult->optimization->solution[i]->constraints->numberOfOtherConstraintResults > 0){
							for(int k = 0; k < m_OSResult->optimization->solution[i]->constraints->numberOfOtherConstraintResults; k++){
								outStr << "<other" ;
								outStr << " name=\"";\
								outStr << m_OSResult->optimization->solution[i]->constraints->other[k]->name;
								outStr << "\"" ;
								outStr << " description=\"";
								outStr << m_OSResult->optimization->solution[i]->constraints->other[k]->description;
								outStr << "\"" ;
								outStr <<  ">" << endl;
								if(m_OSResult->optimization->solution[i]->constraints->other[k]->con.size() > 0){
									for(j = 0; j < m_OSResult->optimization->solution[i]->constraints->other[k]->numberOfCon; j++){
										if(m_OSResult->optimization->solution[i]->constraints->other[k]->con.size() > 0){
											outStr << "<con";
											outStr << " idx=\"";
											outStr << j ;
											outStr <<  "\">";
											outStr <<  m_OSResult->optimization->solution[i]->constraints->other[k]->con[j]->value;
											outStr << "</con>" << endl;
										}
									}
								}
								outStr << "</other>" << endl;
							}
						}
					} // end of if on other constraints
					outStr << "</constraints>" << endl;
				}
				outStr << "</solution>" << endl;
			}
		} // end the solution for loop
		outStr << "</optimization>" << endl;
	} // end if (optimization != NULL)
#ifdef DEBUG
	cout << "done" << endl;
#endif
	outStr << "</osrl>" << endl ;
	return outStr.str();
}// end writeOSrL


