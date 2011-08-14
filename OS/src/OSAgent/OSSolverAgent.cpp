/* $Id$ */
/** @file OSSolverAgent.cpp
 * 
 *
 * @author  Robert Fourer, Horand Gassmann, Jun Ma, Kipp Martin, 
 *
 * \remarks
 * Copyright (C) 2005-2011, Robert Fourer, Horand Gassmann, Jun Ma, Kipp Martin,
 * Dalhousie University, Northwestern University, and the University of Chicago.
 * All Rights Reserved.
 * This software is licensed under the Eclipse Public License. 
 * Please see the accompanying LICENSE file in root directory for terms.
 * 
 */ 
 
#include "OSSolverAgent.h"
#include "OSWSUtil.h"
#include "CoinTime.hpp"
#include "OSParameters.h" 

#include <cstdlib>

#ifdef HAVE_CTIME
# include <ctime>
#else
# ifdef HAVE_TIME_H
#  include <time.h>
# else
#  error "don't have header file for time"
# endif
#endif 

//#define DEBUG

using std::string;
using std::cout; 
using std::endl;

OSSolverAgent::OSSolverAgent(string solverURI) : OShL() {
	int nstart = 0;
	string::size_type posSlash;
	// parse the solverURI
	// get rid of http:// if it is there
	if (solverURI.find("http://") != string::npos) solverURI = solverURI.substr(7);
	// now find the first "/" and put in nstart
	posSlash = solverURI.find("/", nstart);
	if(posSlash != std::string::npos) nstart = posSlash;
	postURI = solverURI.substr(nstart, solverURI.size() - 1);
	// Do we have a port number
	string::size_type colonlocation = solverURI.find(":");
	if(colonlocation == string::npos) {
		solverAddress = solverURI.substr(0, nstart);
		solverPortNumber = 80;
	}
	else{
		solverPortNumber = atoi( &solverURI.substr(colonlocation + 1, nstart - colonlocation - 1)[0] ) ;
		solverAddress = solverURI.substr(0, colonlocation);
	}
}

OSSolverAgent::~OSSolverAgent() {
}

string OSSolverAgent::solve(string osil, string osol){
	string sOSrL ; 
	string theSOAP; 
	string solveResult;
	bool useCDATA = true;
	// CreateSOAPMessage inputs
	int numInputs = 2;
	string smethod = "solve";
	string msInputs[2];
	// package up the inputs
	// first run them through SAOPify, e.g. replace < with &lt; etc.
	msInputs[0] = WSUtil::SOAPify( osil, useCDATA) ;
	msInputs[1] = WSUtil::SOAPify( osol, useCDATA) ;
	string msInputNames[2] = {"osil", "osol"};
	string sSoapAction = "OSSolverService#solve";
	// create the soap
	double cpuTime =0;
	double startTime = 0;
	startTime = CoinCpuTime();
	theSOAP = WSUtil::createSOAPMessage(numInputs, solverAddress, postURI, 
				smethod, msInputs, msInputNames, sSoapAction);
	// send the soap to the HTTP server
	//std::cout << "SEND THE SOAP " << std::endl;
	cpuTime = CoinCpuTime() - startTime;
	//std::cout << "Soapify Cpu Time = "  << cpuTime <<  std::endl;
	startTime = CoinWallclockTime();
	solveResult = WSUtil::sendSOAPMessage( theSOAP, solverAddress, solverPortNumber);
	cpuTime = CoinWallclockTime() - startTime;
	//std::cout << "Send Cpu Time = "  << cpuTime <<  std::endl;
	// desoapify the result -- i.e. replace &lt; with <  etc.
	//std::cout << "CALL DESOAP WITH THE FOLLOWING " << std::endl;
	//std::cout << solveResult << std::endl;
	solveResult = WSUtil::getOSxL(solveResult, "solve");
	//std::cout << "RETURN THE OSRL " << std::endl;
	//std::cout << solveResult << std::endl;
	useCDATA = false;
	sOSrL = WSUtil::deSOAPify( solveResult, useCDATA);
	//std::cout << "RETURN THE OSRL " << std::endl;
	//std::cout << sOSrL << std::endl;
	// strip out the OSxL that we want from the SOAP envelope
	//std::cout << "DONE WITH DESOAP " << std::endl;
	//std::cout << solveResult << std::endl;
	return sOSrL;
}//end solve

string OSSolverAgent::fileUpload( string osilFileName, string theOSiLFile){ 
	string theHTTPPOST=""; 
	string uploadResult="";
	string boundaryName = "AaB03x";
	theHTTPPOST = WSUtil::createFormDataUpload(solverAddress, postURI, 
		osilFileName,  theOSiLFile, boundaryName);
	// send the soap to the HTTP server
	std::cout << "SEND THE FILE " << std::endl;
	//std::cout << theHTTPPOST << std::endl;
	uploadResult = WSUtil::sendSOAPMessage( theHTTPPOST, solverAddress, solverPortNumber);
	return uploadResult;
}//end solve


bool OSSolverAgent::send(string osil, string osol){
	string theSOAP;
	string sendResult;
	bool useCDATA = true;
	// CreateSOAPMessage inputs
	int numInputs = 2;
	string smethod = "send";
	string msInputs[2];
	// package up the inputs
	// first run them through SAOPify, e.g. replace < with &lt; etc.
	msInputs[0] = WSUtil::SOAPify( osil, useCDATA) ;
	msInputs[1] = WSUtil::SOAPify( osol, useCDATA) ;
	string msInputNames[2] = {"osil", "osol"};
	string sSoapAction = "OSSolverService#send";
	// create the soap
	theSOAP = WSUtil::createSOAPMessage(numInputs, solverAddress, postURI, 
				smethod, msInputs, msInputNames, sSoapAction);
	// send the soap to the HTTP server
	sendResult = WSUtil::sendSOAPMessage( theSOAP, solverAddress, solverPortNumber);
	// strip out the OSxL that we want from the SOAP envelope
	sendResult = WSUtil::getOSxL(sendResult, "send");
	// desoapify the result -- i.e. replace &lt; with <  etc.
	useCDATA = false;
	sendResult = WSUtil::deSOAPify( sendResult, useCDATA);
	if( sendResult.find("true") != string::npos ) return true;
	else return false;
}//end send

string OSSolverAgent::getJobID(string osol){
	string sjobID = "";
	string getJobIDResult; 
	string theSOAP;
	bool useCDATA = true;
	// CreateSOAPMessage inputs
	int numInputs = 1;
	string smethod = "getJobID";
	string msInputs[1];
	// package up the inputs
	// first run them through SAOPify, e.g. replace < with &lt; etc.
	msInputs[0] = WSUtil::SOAPify( osol, useCDATA) ;
	string msInputNames[1] = {"osol"};
	string sSoapAction = "OSSolverService#getJobID";
	// create the soap
	theSOAP = WSUtil::createSOAPMessage(numInputs, solverAddress, postURI, 
				smethod, msInputs, msInputNames, sSoapAction);
	// send the soap to the HTTP server
	getJobIDResult = WSUtil::sendSOAPMessage( theSOAP, solverAddress, solverPortNumber);
	// strip out the OSxL that we want from the SOAP envelope
	getJobIDResult =  WSUtil::getOSxL(getJobIDResult, "getJobID");
	// desoapify the result -- i.e. replace &lt; with <  etc.
	useCDATA = false;
	sjobID = WSUtil::deSOAPify( getJobIDResult, useCDATA);

	return sjobID;
}//end getJobID

string OSSolverAgent::retrieve(string osol){
	string sOSrL;
	string retrieveResult; 
	string theSOAP;
	bool useCDATA = true;
	// CreateSOAPMessage inputs
	int numInputs = 1;
	string smethod = "retrieve";
	string msInputs[1];
	// package up the inputs
	// first run them through SAOPify, e.g. replace < with &lt; etc.
	msInputs[0] = WSUtil::SOAPify( osol, useCDATA) ;
	string msInputNames[1] = {"osol"};
	string sSoapAction = "OSSolverService#retrieve";
	// create the soap
	theSOAP = WSUtil::createSOAPMessage(numInputs, solverAddress, postURI, 
				smethod, msInputs, msInputNames, sSoapAction);
	// send the soap to the HTTP server
	retrieveResult = WSUtil::sendSOAPMessage( theSOAP, solverAddress, solverPortNumber);
	// strip out the OSxL that we want from the SOAP envelope
	retrieveResult =  WSUtil::getOSxL(retrieveResult, "retrieve");
	// desoapify the result -- i.e. replace &lt; with <  etc.
	useCDATA = false;
	sOSrL = WSUtil::deSOAPify( retrieveResult, useCDATA);
	return sOSrL;	
}//end retrieve

string OSSolverAgent::kill(string osol){
	string sOSpL;
	string killResult; 
	string theSOAP;
	bool useCDATA = true;
	// CreateSOAPMessage inputs
	int numInputs = 1;
	string smethod = "kill";
	string msInputs[1];
	// package up the inputs
	// first run them through SAOPify, e.g. replace < with &lt; etc.
	msInputs[0] = WSUtil::SOAPify( osol, useCDATA) ;
	string msInputNames[1] = {"osol"};
	string sSoapAction = "OSSolverService#kill";
	// create the soap
	theSOAP = WSUtil::createSOAPMessage(numInputs, solverAddress, postURI, 
				smethod, msInputs, msInputNames, sSoapAction);
	// send the soap to the HTTP server
	killResult = WSUtil::sendSOAPMessage( theSOAP, solverAddress, solverPortNumber);
	// strip out the OSxL that we want from the SOAP envelope
	 killResult =  WSUtil::getOSxL( killResult, "kill");
	// desoapify the result -- i.e. replace &lt; with <  etc.
	useCDATA = false;
	sOSpL = WSUtil::deSOAPify( killResult, useCDATA);
	return sOSpL;
}//end kill

string OSSolverAgent::knock(string ospl, string osol){
	string sOSpL; 
	string theSOAP;
	string knockResult;
	bool useCDATA = true;
	// CreateSOAPMessage inputs
	int numInputs = 2;
	string smethod = "knock";
	string msInputs[2];
	// package up the inputs
	// first run them through SAOPify, e.g. replace < with &lt; etc.
	msInputs[0] = WSUtil::SOAPify( ospl, useCDATA) ;
	msInputs[1] = WSUtil::SOAPify( osol, useCDATA) ;
	string msInputNames[2] = {"ospl", "osol"};
	string sSoapAction = "OSSolverService#knock";
	// create the soap
	theSOAP = WSUtil::createSOAPMessage(numInputs, solverAddress, postURI, 
				smethod, msInputs, msInputNames, sSoapAction);
	// send the soap to the HTTP server
	knockResult = WSUtil::sendSOAPMessage( theSOAP, solverAddress, solverPortNumber);

	// strip out the OSxL that we want from the SOAP envelope
	knockResult = WSUtil::getOSxL( knockResult, "knock");
	// desoapify the result -- i.e. replace &lt; with <  etc.
	useCDATA = false;
	sOSpL = WSUtil::deSOAPify( knockResult, useCDATA);
	return sOSpL;
}//end knock
