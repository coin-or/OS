/** @file OSrLWriter.cpp
 * 
 *
 * @author  Robert Fourer,  Jun Ma, Kipp Martin, 
 * @version 1.0, 10/05/2005
 * @since   OS1.0
 *
 * \remarks
 * Copyright (C) 2005, Robert Fourer, Jun Ma, Kipp Martin,
 * Northwestern University, and the University of Chicago.
 * All Rights Reserved.
 * This software is licensed under the Common Public License. 
 * Please see the accompanying LICENSE file in root directory for terms.
 * 
 */
 
 
 




#include "OSrLWriter.h"
#include "OSResult.h"
#include "OSParameters.h"
#include "CommonUtil.h"
#include "OSConfig.h"
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
	const char dirsep =  '/';
	#ifdef WIN_
		dirsep='\';
	#endif
  	// Set directory containing mps data files.
  	std::string xsltDir;
    xsltDir = dirsep == '/' ? "/stylesheets/" : "\\stylesheets\\";
	int i, j;
	if(m_OSResult == NULL)  return outStr.str(); 
	outStr << "<?xml version=\"1.0\" encoding=\"UTF-8\"?>" ; 
	outStr << "<?xml-stylesheet type = \"text/xsl\" href = \"";
	outStr << OSROOT_DIR;
	outStr << xsltDir;
	outStr << "OSrL.xslt\"?>";
	outStr << "<osrl xmlns:os=\"os.optimizationservices.org\"   xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\" xsi:schemaLocation=\"os.optimizationservices.org http://www.optimizationservices.org/schemas/OSrL.xsd\" >" ;
	outStr << endl;
	outStr << "<resultHeader>" << endl;
	if(m_OSResult->resultHeader != NULL){
		if(m_OSResult->resultHeader->generalStatus != NULL){
			outStr << "<generalStatus "    ;
			if(m_OSResult->resultHeader->generalStatus->type.length() > 0){
				outStr << "type=\"";
				outStr << m_OSResult->resultHeader->generalStatus->type ;
				outStr << "\"";
			}
			if(m_OSResult->resultHeader->generalStatus->description.length() > 0){
				outStr << "type=\"";
				outStr << m_OSResult->resultHeader->generalStatus->description ;
				outStr << "\"";
			}
			outStr << "/>" << endl;
		}		
		
		if(m_OSResult->resultHeader->serviceURI.length() > 0){
			outStr << "<serviceURI>" + m_OSResult->resultHeader->serviceURI + "</serviceURI>"  << endl;
		}

		if(m_OSResult->resultHeader->serviceName.length() > 0){
			outStr << "<serviceName>" + m_OSResult->resultHeader->serviceName + "</serviceName>"  << endl;
		}
		if(m_OSResult->resultHeader->instanceName.length() > 0){
			outStr << "<instanceName>" + m_OSResult->resultHeader->instanceName  + "</instanceName>" << endl;
		}
		if(m_OSResult->resultHeader->jobID.length() > 0){
			outStr << "<jobID>" + m_OSResult->resultHeader->jobID  + "</jobID>" << endl;
		}
		if(m_OSResult->resultHeader->time.length() > 0){
			outStr << "<time>" + m_OSResult->resultHeader->time  + "</time>" << endl;
		}
		if(m_OSResult->resultHeader->message.length() > 0){
			outStr << "<message>" + m_OSResult->resultHeader->message  + "</message>" << endl;
		}
	}
	outStr << "</resultHeader>" << endl;
	if(m_OSResult->resultData != NULL){
		outStr << "<resultData>" << endl;
		if(m_OSResult->resultData->optimization != NULL && m_OSResult->resultData->optimization->numberOfSolutions > 0){
			outStr << "<optimization " ;
			outStr << "numberOfSolutions=\"";
			outStr << m_OSResult->resultData->optimization->numberOfSolutions ;
			outStr <<  "\"";
			outStr << " numberOfVariables=\"";
			outStr << m_OSResult->resultData->optimization->numberOfVariables ;
			outStr <<  "\"";
			outStr << " numberOfConstraints=\"";
			outStr << m_OSResult->resultData->optimization->numberOfConstraints ;
			outStr <<  "\"";
			outStr << " numberOfObjectives=\"";
			outStr << m_OSResult->resultData->optimization->numberOfObjectives ;
			outStr << "\"" ;
			outStr << ">" << endl;
			// get solution information
			for(i = 0; i < m_OSResult->resultData->optimization->numberOfSolutions; i++){
				if(m_OSResult->resultData->optimization->solution[i] != NULL){
					outStr << "<solution" ;
					outStr << " objectiveIdx=\"";
					outStr << m_OSResult->resultData->optimization->solution[i]->objectiveIdx ;
					outStr << "\"" ;
					outStr << ">" << endl;
					if(m_OSResult->resultData->optimization->solution[i]->status != NULL){
						outStr << "<status";
						if(m_OSResult->resultData->optimization->solution[i]->status->type.length() > 0){
							outStr << " type=\"";
							outStr << m_OSResult->resultData->optimization->solution[i]->status->type;
							outStr <<  "\"";
						}
						if(m_OSResult->resultData->optimization->solution[i]->status->description.length() > 0){
							outStr << " description=\"";
							outStr <<  m_OSResult->resultData->optimization->solution[i]->status->description;
							outStr << "\"" ;
						}
						outStr << "/>" << endl;
					}
					if(m_OSResult->resultData->optimization->solution[i]->message != ""){
						outStr << "<message>" << endl;
						outStr << m_OSResult->resultData->optimization->solution[i]->message  << endl;
						outStr << "</message>" << endl;
					}
					if(m_OSResult->resultData->optimization->solution[i]->variables != NULL){
						outStr << "<variables>" << endl;
						if(m_OSResult->resultData->optimization->solution[i]->variables->values != NULL){
							outStr << "<values>" << endl;
							for(j = 0; j < m_OSResult->resultData->optimization->numberOfVariables; j++){
								if(m_OSResult->resultData->optimization->solution[i]->variables->values->var[j] != NULL){
									outStr << "<var";
									outStr << " idx=\"";
									outStr << j ;
									outStr <<  "\">";
									outStr <<  m_OSResult->resultData->optimization->solution[i]->variables->values->var[j]->value;
									outStr << "</var>" << endl;
								}
							}
							outStr << "</values>" << endl;
						}
						if(m_OSResult->resultData->optimization->solution[i]->variables->other != NULL){
							if(m_OSResult->resultData->optimization->solution[i]->variables->numberOfOtherVariableResult > 0){
								for(int k = 0; k < m_OSResult->resultData->optimization->solution[i]->variables->numberOfOtherVariableResult; k++){
									outStr << "<other" ;
									outStr << " name=\"";\
									outStr << m_OSResult->resultData->optimization->solution[i]->variables->other[k]->name;
									outStr << "\"" ;
									outStr << " description=\"";
									outStr << m_OSResult->resultData->optimization->solution[i]->variables->other[k]->description;
									outStr << "\"" ;
									outStr <<  ">" << endl;
									if(m_OSResult->resultData->optimization->solution[i]->variables->other[k]->var.size() > 0){
										for(j = 0; j < m_OSResult->resultData->optimization->numberOfVariables; j++){
											if(m_OSResult->resultData->optimization->solution[i]->variables->other[k]->var.size() > 0){
												outStr << "<var";
												outStr << " idx=\"";
												outStr << j ;
												outStr <<  "\">";
												outStr <<  m_OSResult->resultData->optimization->solution[i]->variables->other[k]->var[j]->value;
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
					if(m_OSResult->resultData->optimization->solution[i]->objectives != NULL){
						outStr << "<objectives>" << endl;
						if(m_OSResult->resultData->optimization->solution[i]->objectives->values != NULL){
							outStr << "<values>" << endl;
							for(j = 0; j < m_OSResult->resultData->optimization->numberOfObjectives; j++){
								if(m_OSResult->resultData->optimization->solution[i]->objectives->values->obj[j] != NULL){
									outStr << "<obj";
									outStr << " idx=\"";
									outStr << -(1 + j) ;
									outStr <<  "\">";
									outStr <<  m_OSResult->resultData->optimization->solution[i]->objectives->values->obj[j]->value;
									outStr << "</obj>" << endl;
								}
							}
							outStr << "</values>" << endl;
						}
						if(m_OSResult->resultData->optimization->solution[i]->objectives->other != NULL){
							if(m_OSResult->resultData->optimization->solution[i]->objectives->numberOfOtherObjectiveResult > 0){
								for(int k = 0; k < m_OSResult->resultData->optimization->solution[i]->objectives->numberOfOtherObjectiveResult; k++){
									outStr << "<other" ;
									outStr << " name=\"";\
									outStr << m_OSResult->resultData->optimization->solution[i]->objectives->other[k]->name;
									outStr << "\"" ;
									outStr << " description=\"";
									outStr << m_OSResult->resultData->optimization->solution[i]->objectives->other[k]->description;
									outStr << "\"" ;
									outStr <<  ">" << endl;
									if(m_OSResult->resultData->optimization->solution[i]->objectives->other[k]->obj.size() > 0){
										for(j = 0; j < m_OSResult->resultData->optimization->numberOfObjectives; j++){
											if(m_OSResult->resultData->optimization->solution[i]->objectives->other[k]->obj.size() > 0){
												outStr << "<obj";
												outStr << " idx=\"";
												outStr << j ;
												outStr <<  "\">";
												outStr <<  m_OSResult->resultData->optimization->solution[i]->objectives->other[k]->obj[j]->value;
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
					if(m_OSResult->resultData->optimization->solution[i]->constraints != NULL){
						outStr << "<constraints>" << endl;
						if(m_OSResult->resultData->optimization->solution[i]->constraints->values != NULL){
							outStr << "<values>" << endl;
							for(j = 0; j < m_OSResult->resultData->optimization->numberOfConstraints; j++){
								if(m_OSResult->resultData->optimization->solution[i]->constraints->values->con[j] != NULL){
									outStr << "<con";
									outStr << " idx=\"";
									outStr <<  j ;
									outStr <<  "\">";
									outStr <<  m_OSResult->resultData->optimization->solution[i]->constraints->values->con[j]->value;
									outStr << "</con>" << endl;
								}
							}
							outStr << "</values>" << endl;
						}
						if(m_OSResult->resultData->optimization->solution[i]->constraints->dualValues != NULL){
							outStr << "<dualValues>" << endl;
							for(j = 0; j < m_OSResult->resultData->optimization->numberOfConstraints; j++){
								if(m_OSResult->resultData->optimization->solution[i]->constraints->dualValues->con[j] != NULL){
									outStr << "<con";
									outStr << " idx=\"";
									outStr <<  j ;
									outStr <<  "\">";
									outStr <<  m_OSResult->resultData->optimization->solution[i]->constraints->dualValues->con[j]->value;
									outStr << "</con>" << endl;
								}
							}
							outStr << "</dualValues>" << endl;
						}
						if(m_OSResult->resultData->optimization->solution[i]->constraints->other != NULL){
							if(m_OSResult->resultData->optimization->solution[i]->constraints->numberOfOtherConstraintResult > 0){
								for(int k = 0; k < m_OSResult->resultData->optimization->solution[i]->constraints->numberOfOtherConstraintResult; k++){
									outStr << "<other" ;
									outStr << " name=\"";\
									outStr << m_OSResult->resultData->optimization->solution[i]->constraints->other[k]->name;
									outStr << "\"" ;
									outStr << " description=\"";
									outStr << m_OSResult->resultData->optimization->solution[i]->constraints->other[k]->description;
									outStr << "\"" ;
									outStr <<  ">" << endl;
									if(m_OSResult->resultData->optimization->solution[i]->constraints->other[k]->con.size() > 0){
										for(j = 0; j < m_OSResult->resultData->optimization->numberOfConstraints; j++){
											if(m_OSResult->resultData->optimization->solution[i]->constraints->other[k]->con.size() > 0){
												outStr << "<con";
												outStr << " idx=\"";
												outStr << j ;
												outStr <<  "\">";
												outStr <<  m_OSResult->resultData->optimization->solution[i]->constraints->other[k]->con[j]->value;
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
		}
		outStr << "</resultData>" << endl ;
	} // end instanceData if
	outStr << "</osrl>" << endl;
	return outStr.str();
}// end writeOSrL

//the following is copied from CoinHelperFunctions


