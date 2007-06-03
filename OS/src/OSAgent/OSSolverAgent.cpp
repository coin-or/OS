/** @file OSSolverAgent.cpp
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
 
#include "OSSolverAgent.h"
#include "WSUtil.h"

//#define DEBUG

using std::string;
using std::cout; 
using std::endl;

OSSolverAgent::OSSolverAgent(string solverURI) : OShL() {
	int nstart = 0;
	// parse the solverURI
	// get rid of http:// if it is there
	if (solverURI.find("http://") != string::npos) solverURI = solverURI.substr(7);
	// now find the first "/" and put in nstart
	nstart = solverURI.find("/", nstart);
	postURI = solverURI.substr(nstart, solverURI.size() - 1);
	// Do we have a port number
	unsigned int colonlocation = solverURI.find(":");
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
	// CreateSOAPMessage inputs
	int numInputs = 2;
	string smethod = "solve";
	string msInputs[2];
	// package up the inputs
	// first run them through SAOPify, e.g. replace < with &lt; etc.
	msInputs[0] = WSUtil::SOAPify( osil) ;
	msInputs[1] = WSUtil::SOAPify( osol) ;
	string msInputNames[2] = {"osil", "osol"};
	string sSoapAction = "OSSolverService#solve";
	// create the soap
	theSOAP = WSUtil::createSOAPMessage(numInputs, solverAddress, postURI, 
				smethod, msInputs, msInputNames, sSoapAction);
	// send the soap to the HTTP server
	//std::cout << "SEND THE SOAP " << std::endl;
	solveResult = WSUtil::sendSOAPMessage( theSOAP, solverAddress, solverPortNumber);
	// desoapify the result -- i.e. replace &lt; with <  etc.
	//std::cout << "CALL DESOAP WITH THE FOLLOWING " << std::endl;
	//std::cout << solveResult << std::endl;
	solveResult = WSUtil::deSOAPify( solveResult);
	// strip out the OSxL that we want from the SOAP envelope
	//std::cout << "DONE WITH DESOAP " << std::endl;
	//std::cout << solveResult << std::endl;
	sOSrL = WSUtil::getOSxL(solveResult, "solve");
	//std::cout << "RETURN THE OSRL " << std::endl;
	//std::cout << sOSrL << std::endl;
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
	// CreateSOAPMessage inputs
	int numInputs = 2;
	string smethod = "send";
	string msInputs[2];
	// package up the inputs
	// first run them through SAOPify, e.g. replace < with &lt; etc.
	msInputs[0] = WSUtil::SOAPify( osil) ;
	msInputs[1] = WSUtil::SOAPify( osol) ;
	string msInputNames[2] = {"osil", "osol"};
	string sSoapAction = "OSSolverService#send";
	// create the soap
	theSOAP = WSUtil::createSOAPMessage(numInputs, solverAddress, postURI, 
				smethod, msInputs, msInputNames, sSoapAction);
	// send the soap to the HTTP server
	sendResult = WSUtil::sendSOAPMessage( theSOAP, solverAddress, solverPortNumber);
	// desoapify the result -- i.e. replace &lt; with <  etc.
	sendResult = WSUtil::deSOAPify( sendResult);
	// strip out the OSxL that we want from the SOAP envelope
	sendResult = WSUtil::getOSxL(sendResult, "send");
	if( sendResult.find("true") != string::npos ) return true;
	else return false;
}//end send

string OSSolverAgent::getJobID(string osol){
	string sjobID = "";
	string getJobIDResult; 
	string theSOAP;
	// CreateSOAPMessage inputs
	int numInputs = 1;
	string smethod = "getJobID";
	string msInputs[1];
	// package up the inputs
	// first run them through SAOPify, e.g. replace < with &lt; etc.
	msInputs[0] = WSUtil::SOAPify( osol) ;
	string msInputNames[1] = {"osol"};
	string sSoapAction = "OSSolverService#getJobID";
	// create the soap
	theSOAP = WSUtil::createSOAPMessage(numInputs, solverAddress, postURI, 
				smethod, msInputs, msInputNames, sSoapAction);
	// send the soap to the HTTP server
	getJobIDResult = WSUtil::sendSOAPMessage( theSOAP, solverAddress, solverPortNumber);
	// desoapify the result -- i.e. replace &lt; with <  etc.
	getJobIDResult = WSUtil::deSOAPify( getJobIDResult);
	// strip out the OSxL that we want from the SOAP envelope
	sjobID =  WSUtil::getOSxL(getJobIDResult, "getJobID");
	return sjobID;
}//end getJobID

string OSSolverAgent::retrieve(string osol){
	string sOSrL;
	string retrieveResult; 
	string theSOAP;
	// CreateSOAPMessage inputs
	int numInputs = 1;
	string smethod = "retrieve";
	string msInputs[1];
	// package up the inputs
	// first run them through SAOPify, e.g. replace < with &lt; etc.
	msInputs[0] = WSUtil::SOAPify( osol) ;
	string msInputNames[1] = {"osol"};
	string sSoapAction = "OSSolverService#retrieve";
	// create the soap
	theSOAP = WSUtil::createSOAPMessage(numInputs, solverAddress, postURI, 
				smethod, msInputs, msInputNames, sSoapAction);
	// send the soap to the HTTP server
	retrieveResult = WSUtil::sendSOAPMessage( theSOAP, solverAddress, solverPortNumber);
	// desoapify the result -- i.e. replace &lt; with <  etc.
	retrieveResult = WSUtil::deSOAPify( retrieveResult);
	// strip out the OSxL that we want from the SOAP envelope
	sOSrL =  WSUtil::getOSxL(retrieveResult, "retrieve");
	return sOSrL;	
}//end retrieve

string OSSolverAgent::kill(string osol){
	string sOSpL;
	string killResult; 
	string theSOAP;
	// CreateSOAPMessage inputs
	int numInputs = 1;
	string smethod = "kill";
	string msInputs[1];
	// package up the inputs
	// first run them through SAOPify, e.g. replace < with &lt; etc.
	msInputs[0] = WSUtil::SOAPify( osol) ;
	string msInputNames[1] = {"osol"};
	string sSoapAction = "OSSolverService#kill";
	// create the soap
	theSOAP = WSUtil::createSOAPMessage(numInputs, solverAddress, postURI, 
				smethod, msInputs, msInputNames, sSoapAction);
	// send the soap to the HTTP server
	killResult = WSUtil::sendSOAPMessage( theSOAP, solverAddress, solverPortNumber);
	// desoapify the result -- i.e. replace &lt; with <  etc.
	killResult = WSUtil::deSOAPify( killResult);
	// strip out the OSxL that we want from the SOAP envelope
	sOSpL =  WSUtil::getOSxL( killResult, "kill");
	return sOSpL;
}//end kill

string OSSolverAgent::knock(string ospl, string osol){
	string sOSpL; 
	string theSOAP;
	string knockResult;
	// CreateSOAPMessage inputs
	int numInputs = 2;
	string smethod = "knock";
	string msInputs[2];
	// package up the inputs
	// first run them through SAOPify, e.g. replace < with &lt; etc.
	msInputs[0] = WSUtil::SOAPify( ospl) ;
	msInputs[1] = WSUtil::SOAPify( osol) ;
	string msInputNames[2] = {"ospl", "osol"};
	string sSoapAction = "OSSolverService#knock";
	// create the soap
	theSOAP = WSUtil::createSOAPMessage(numInputs, solverAddress, postURI, 
				smethod, msInputs, msInputNames, sSoapAction);
	// send the soap to the HTTP server
	knockResult = WSUtil::sendSOAPMessage( theSOAP, solverAddress, solverPortNumber);
	// desoapify the result -- i.e. replace &lt; with <  etc.
	knockResult = WSUtil::deSOAPify( knockResult);
	// strip out the OSxL that we want from the SOAP envelope
	sOSpL = WSUtil::getOSxL( knockResult, "knock");
	return sOSpL;
}//end knock
