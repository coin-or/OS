/* $Id$ */
/** @file OSSolverAgent.cpp
 *
 *
 * @author  Robert Fourer, Horand Gassmann, Jun Ma, Kipp Martin,
 *
 * \remarks
 * Copyright (C) 2005-2012, Robert Fourer, Horand Gassmann, Jun Ma, Kipp Martin,
 * Northwestern University, and the University of Chicago.
 * All Rights Reserved.
 * This software is licensed under the Eclipse Public License.
 * Please see the accompanying LICENSE file in root directory for terms.
 *
 */

#include "OSSolverAgent.h"
#include "OSWSUtil.h"
#include "CoinTime.hpp"
#include "OSParameters.h"
#include "OSOutput.h"

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

#include <stdio.h>
#include <sstream>

using std::string;
using std::ostringstream;
using std::cout;
using std::endl;

extern const OSSmartPtr<OSOutput> osoutput;

OSSolverAgent::OSSolverAgent(string solverURI) : OShL()
{
    string::size_type nstart = 0;
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
    if(colonlocation == string::npos)
    {
        solverAddress = solverURI.substr(0, nstart);
        solverPortNumber = 80;
    }
    else
    {
        solverPortNumber = (unsigned short) atoi( &solverURI.substr(colonlocation + 1, nstart - colonlocation - 1)[0] ) ;
        solverAddress = solverURI.substr(0, colonlocation);
    }
}

OSSolverAgent::~OSSolverAgent()
{
}

string OSSolverAgent::solve(string osil, string osol)
{
    string sOSrL;
    string theSOAP;
    string solveResult;

#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSAgent, ENUM_OUTPUT_LEVEL_trace, "Inside SolverAgent solve() method \n");

    std::ostringstream outStr;
    outStr.str("");
    outStr.clear();

    outStr << "Sending to the remote system:" << std::endl << std::endl;
    outStr << "OSiL string:" << std::endl << std::endl;
    outStr << osil << std::endl << std::endl;
    outStr << "OSoL string:" << std::endl << std::endl;
    outStr << osol << std::endl << std::endl;    

    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSAgent, ENUM_OUTPUT_LEVEL_debug, outStr.str());
#endif

    bool useCDATA = true;
    // CreateSOAPMessage inputs
    int numInputs = 2;
    string smethod = "solve";
    string msInputs[2];
    // package up the inputs
    // first run them through SAOPify, i.e. replace < with &lt; etc.

#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSAgent, ENUM_OUTPUT_LEVEL_trace, "SOAPify OSiL \n");
#endif
    msInputs[0] = WSUtil::SOAPify( osil, useCDATA) ;

#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSAgent, ENUM_OUTPUT_LEVEL_detailed_trace, msInputs[0]);
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSAgent, ENUM_OUTPUT_LEVEL_trace, "SOAPify OSoL \n");
#endif
    msInputs[1] = WSUtil::SOAPify( osol, useCDATA) ;
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSAgent, ENUM_OUTPUT_LEVEL_detailed_trace, msInputs[1]);
#endif
    string msInputNames[2] = {"osil", "osol"};
    string sSoapAction = "OSSolverService#solve";
    // create the soap
    double cpuTime;
    double startTime = 0;
    startTime = CoinCpuTime();
    theSOAP = WSUtil::createSOAPMessage(numInputs, solverAddress, postURI,
                                        smethod, msInputs, msInputNames, sSoapAction);
    // send the soap to the HTTP server
    cpuTime = CoinCpuTime() - startTime;
    startTime = CoinWallclockTime();
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSAgent, ENUM_OUTPUT_LEVEL_trace, "SEND THE SOAP\n");
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSAgent, ENUM_OUTPUT_LEVEL_detailed_trace, theSOAP);
#endif
    solveResult = WSUtil::sendSOAPMessage( theSOAP, solverAddress, solverPortNumber);
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSAgent, ENUM_OUTPUT_LEVEL_trace, "Response received\n");
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSAgent, ENUM_OUTPUT_LEVEL_detailed_trace, solveResult);
#endif
    cpuTime = CoinWallclockTime() - startTime;

    // desoapify the result -- i.e. replace &lt; with <  etc.

    solveResult = WSUtil::getOSxL(solveResult, "solve");
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSAgent, ENUM_OUTPUT_LEVEL_trace, "Result received\n");
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSAgent, ENUM_OUTPUT_LEVEL_detailed_trace, solveResult);
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSAgent, ENUM_OUTPUT_LEVEL_trace, "DeSOAPify result\n");
#endif

    useCDATA = false;
    sOSrL = WSUtil::deSOAPify( solveResult, useCDATA);
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSAgent, ENUM_OUTPUT_LEVEL_detailed_trace, sOSrL);
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSAgent, ENUM_OUTPUT_LEVEL_trace, "RETURN THE OSRL\n");
#endif

    return sOSrL;
}//end solve

string OSSolverAgent::fileUpload( string osilFileName, string theOSiLFile)
{
    string theHTTPPOST="";
    string uploadResult="";
    string boundaryName = "AaB03x";
    theHTTPPOST = WSUtil::createFormDataUpload(solverAddress, postURI,
                  osilFileName,  theOSiLFile, boundaryName);

    // send the soap to the HTTP server
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSAgent, ENUM_OUTPUT_LEVEL_trace, "Upload file in SolverAgent\n");
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSAgent, ENUM_OUTPUT_LEVEL_detailed_trace, theHTTPPOST);
#endif
    uploadResult = WSUtil::sendSOAPMessage( theHTTPPOST, solverAddress, solverPortNumber);
    return uploadResult;
}//end solve


bool OSSolverAgent::send(string osil, string osol)
{
    string theSOAP;
    string sendResult;
    bool useCDATA = true;

#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSAgent, ENUM_OUTPUT_LEVEL_trace, "Inside SolverAgent send() method \n");

    std::ostringstream outStr;
    outStr.str("");
    outStr.clear();

    outStr << "Sending to the remote system:" << std::endl << std::endl;
    outStr << "OSiL string:" << std::endl << std::endl;
    outStr << osil << std::endl << std::endl;
    outStr << "OSoL string:" << std::endl << std::endl;
    outStr << osol << std::endl << std::endl;    

    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSAgent, ENUM_OUTPUT_LEVEL_debug, outStr.str());
#endif

    // CreateSOAPMessage inputs
    int numInputs = 2;
    string smethod = "send";
    string msInputs[2];
    // package up the inputs
    // first run them through SAOPify, i.e. replace < with &lt; etc.
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSAgent, ENUM_OUTPUT_LEVEL_trace, "SOAPIFY OSIL\n");
#endif
    msInputs[0] = WSUtil::SOAPify( osil, useCDATA);
#ifndef NDEBUG

    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSAgent, ENUM_OUTPUT_LEVEL_detailed_trace, msInputs[0]);
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSAgent, ENUM_OUTPUT_LEVEL_trace, "SOAPIFY OSOL\n");
#endif
    msInputs[1] = WSUtil::SOAPify( osol, useCDATA) ;
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSAgent, ENUM_OUTPUT_LEVEL_detailed_trace, msInputs[1]);
#endif

    string msInputNames[2] = {"osil", "osol"};
    string sSoapAction = "OSSolverService#send";
    // create the soap
    theSOAP = WSUtil::createSOAPMessage(numInputs, solverAddress, postURI,
                                        smethod, msInputs, msInputNames, sSoapAction);
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSAgent, ENUM_OUTPUT_LEVEL_trace, "Send the SOAP\n");
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSAgent, ENUM_OUTPUT_LEVEL_detailed_trace, theSOAP);
#endif

    // send the soap to the HTTP server
    sendResult = WSUtil::sendSOAPMessage( theSOAP, solverAddress, solverPortNumber);
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSAgent, ENUM_OUTPUT_LEVEL_trace, "Message returned\n");
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSAgent, ENUM_OUTPUT_LEVEL_detailed_trace, sendResult);
#endif

    // strip out the OSxL that we want from the SOAP envelope
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSAgent, ENUM_OUTPUT_LEVEL_detailed_trace, "Strip out OSxL string\n");
#endif
    sendResult = WSUtil::getOSxL(sendResult, "send");
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSAgent, ENUM_OUTPUT_LEVEL_detailed_trace, sendResult);
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSAgent, ENUM_OUTPUT_LEVEL_trace, "DeSOAPify\n");
#endif
    // desoapify the result -- i.e. replace &lt; with <  etc.
    useCDATA = false;
    sendResult = WSUtil::deSOAPify( sendResult, useCDATA);
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSAgent, ENUM_OUTPUT_LEVEL_detailed_trace, sendResult);
#endif
    if( sendResult.find("true") != string::npos ) return true;
    else return false;
}//end send

string OSSolverAgent::getJobID(string osol)
{
    string sjobID = "";
    string getJobIDResult;
    string theSOAP;
    bool useCDATA = true;

#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSAgent, ENUM_OUTPUT_LEVEL_trace, "Inside SolverAgent getJobID() method \n");

    std::ostringstream outStr;
    outStr.str("");
    outStr.clear();

    outStr << "Sending to the remote system:" << std::endl << std::endl;
    outStr << "OSoL string:" << std::endl << std::endl;
    outStr << osol << std::endl << std::endl;    

    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSAgent, ENUM_OUTPUT_LEVEL_debug, outStr.str());
#endif

    // CreateSOAPMessage inputs
    int numInputs = 1;
    string smethod = "getJobID";
    string msInputs[1];
    // package up the inputs

    // first run them through SAOPify, i.e. replace < with &lt; etc.
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSAgent, ENUM_OUTPUT_LEVEL_trace, "SOAPIFY OSOL\n");
#endif
    msInputs[0] = WSUtil::SOAPify( osol, useCDATA) ;
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSAgent, ENUM_OUTPUT_LEVEL_detailed_trace, msInputs[0]);
#endif
    string msInputNames[1] = {"osol"};
    string sSoapAction = "OSSolverService#getJobID";
    // create the soap
    theSOAP = WSUtil::createSOAPMessage(numInputs, solverAddress, postURI,
                                        smethod, msInputs, msInputNames, sSoapAction);
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSAgent, ENUM_OUTPUT_LEVEL_trace, "Send the SOAP\n");
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSAgent, ENUM_OUTPUT_LEVEL_detailed_trace, theSOAP);
#endif
    // send the soap to the HTTP server
    getJobIDResult = WSUtil::sendSOAPMessage( theSOAP, solverAddress, solverPortNumber);
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSAgent, ENUM_OUTPUT_LEVEL_trace, "Message returned\n");
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSAgent, ENUM_OUTPUT_LEVEL_detailed_trace, getJobIDResult);
#endif
    // strip out the OSxL that we want from the SOAP envelope
    getJobIDResult =  WSUtil::getOSxL(getJobIDResult, "getJobID");
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSAgent, ENUM_OUTPUT_LEVEL_detailed_trace, "Strip out job ID\n");
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSAgent, ENUM_OUTPUT_LEVEL_detailed_trace, getJobIDResult);
#endif
    // desoapify the result -- i.e. replace &lt; with <  etc.
    useCDATA = false;
    sjobID = WSUtil::deSOAPify( getJobIDResult, useCDATA);
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSAgent, ENUM_OUTPUT_LEVEL_trace, "DeSOAPify\n");
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSAgent, ENUM_OUTPUT_LEVEL_detailed_trace, sjobID);
#endif

    return sjobID;
}//end getJobID


string OSSolverAgent::retrieve(string osol)
{
    string sOSrL;
    string retrieveResult;
    string theSOAP;
    bool useCDATA = true;

#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSAgent, ENUM_OUTPUT_LEVEL_trace, "Inside SolverAgent retrieve() method \n");

    std::ostringstream outStr;
    outStr.str("");
    outStr.clear();

    outStr << "Sending to the remote system:" << std::endl << std::endl;
    outStr << "OSoL string:" << std::endl << std::endl;
    outStr << osol << std::endl << std::endl;    

    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSAgent, ENUM_OUTPUT_LEVEL_debug, outStr.str());
#endif

    // CreateSOAPMessage inputs
    int numInputs = 1;
    string smethod = "retrieve";
    string msInputs[1];
    // package up the inputs
    // first run them through SAOPify, i.e. replace < with &lt; etc.
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSAgent, ENUM_OUTPUT_LEVEL_trace, "SOAPIFY OSoL\n");
#endif
    msInputs[0] = WSUtil::SOAPify( osol, useCDATA) ;
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSAgent, ENUM_OUTPUT_LEVEL_detailed_trace, msInputs[0]);
#endif
    string msInputNames[1] = {"osol"};
    string sSoapAction = "OSSolverService#retrieve";
    // create the soap
    theSOAP = WSUtil::createSOAPMessage(numInputs, solverAddress, postURI,
                                        smethod, msInputs, msInputNames, sSoapAction);
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSAgent, ENUM_OUTPUT_LEVEL_trace, "Send the SOAP\n");
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSAgent, ENUM_OUTPUT_LEVEL_detailed_trace, theSOAP);
#endif

    // send the soap to the HTTP server
    retrieveResult = WSUtil::sendSOAPMessage( theSOAP, solverAddress, solverPortNumber);
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSAgent, ENUM_OUTPUT_LEVEL_trace, "Message returned\n");
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSAgent, ENUM_OUTPUT_LEVEL_detailed_trace, retrieveResult);
#endif

    // strip out the OSxL that we want from the SOAP envelope
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSAgent, ENUM_OUTPUT_LEVEL_detailed_trace, "Strip out OSxL string\n");
#endif
    retrieveResult =  WSUtil::getOSxL(retrieveResult, "retrieve");

    // desoapify the result -- i.e. replace &lt; with <  etc.
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSAgent, ENUM_OUTPUT_LEVEL_detailed_trace, retrieveResult);
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSAgent, ENUM_OUTPUT_LEVEL_trace, "DeSOAPify\n");
#endif
    useCDATA = false;
    sOSrL = WSUtil::deSOAPify( retrieveResult, useCDATA);
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSAgent, ENUM_OUTPUT_LEVEL_detailed_trace, sOSrL);
#endif

    return sOSrL;
}//end retrieve


string OSSolverAgent::kill(string osol)
{
    string sOSpL;
    string killResult;
    string theSOAP;
    bool useCDATA = true;

#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSAgent, ENUM_OUTPUT_LEVEL_trace, "Inside SolverAgent kill() method \n");

    std::ostringstream outStr;
    outStr.str("");
    outStr.clear();

    outStr << "Sending to the remote system:" << std::endl << std::endl;
    outStr << "OSoL string:" << std::endl << std::endl;
    outStr << osol << std::endl << std::endl;    

    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSAgent, ENUM_OUTPUT_LEVEL_debug, outStr.str());
#endif

    // CreateSOAPMessage inputs
    int numInputs = 1;
    string smethod = "kill";
    string msInputs[1];
    // package up the inputs
    // first run them through SAOPify, i.e. replace < with &lt; etc.
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSAgent, ENUM_OUTPUT_LEVEL_trace, "SOAPify OSoL \n");
#endif
    msInputs[0] = WSUtil::SOAPify( osol, useCDATA) ;
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSAgent, ENUM_OUTPUT_LEVEL_detailed_trace, msInputs[0]);
#endif
    string msInputNames[1] = {"osol"};
    string sSoapAction = "OSSolverService#kill";
    // create the soap
    theSOAP = WSUtil::createSOAPMessage(numInputs, solverAddress, postURI,
                                        smethod, msInputs, msInputNames, sSoapAction);
    // send the soap to the HTTP server
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSAgent, ENUM_OUTPUT_LEVEL_trace, "SEND THE SOAP\n");
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSAgent, ENUM_OUTPUT_LEVEL_detailed_trace, theSOAP);
#endif
    killResult = WSUtil::sendSOAPMessage( theSOAP, solverAddress, solverPortNumber);
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSAgent, ENUM_OUTPUT_LEVEL_trace, "Response received\n");
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSAgent, ENUM_OUTPUT_LEVEL_detailed_trace, killResult);
#endif
    // strip out the OSxL that we want from the SOAP envelope
    killResult =  WSUtil::getOSxL( killResult, "kill");

    // desoapify the result -- i.e. replace &lt; with <  etc.
    useCDATA = false;
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSAgent, ENUM_OUTPUT_LEVEL_trace, "DeSOAPify result\n");
#endif
    sOSpL = WSUtil::deSOAPify( killResult, useCDATA);
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSAgent, ENUM_OUTPUT_LEVEL_detailed_trace, sOSpL);
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSAgent, ENUM_OUTPUT_LEVEL_trace, "RETURN THE OSpL\n");
#endif

    return sOSpL;
}//end kill

string OSSolverAgent::knock(string ospl, string osol)
{
    string sOSpL;
    string theSOAP;
    string knockResult;
    bool useCDATA = true;
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSAgent, ENUM_OUTPUT_LEVEL_trace, "Inside SolverAgent knock() method \n");

    std::ostringstream outStr;
    outStr.str("");
    outStr.clear();

    outStr << "Sending to the remote system:" << std::endl << std::endl;
    outStr << "OSpL string:" << std::endl << std::endl;
    outStr << ospl << std::endl << std::endl;
    outStr << "OSoL string:" << std::endl << std::endl;
    outStr << osol << std::endl << std::endl;    

    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSAgent, ENUM_OUTPUT_LEVEL_debug, outStr.str());
#endif

    // CreateSOAPMessage inputs
    int numInputs = 2;
    string smethod = "knock";
    string msInputs[2];
    // package up the inputs
    // first run them through SAOPify, i.e. replace < with &lt; etc.
#ifndef NDEBUG	
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSAgent, ENUM_OUTPUT_LEVEL_trace, "SOAPify OSpL \n");
#endif
    msInputs[0] = WSUtil::SOAPify( ospl, useCDATA) ;
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSAgent, ENUM_OUTPUT_LEVEL_detailed_trace, msInputs[0]);
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSAgent, ENUM_OUTPUT_LEVEL_trace, "SOAPify OSoL \n");
#endif
    msInputs[1] = WSUtil::SOAPify( osol, useCDATA) ;
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSAgent, ENUM_OUTPUT_LEVEL_detailed_trace, msInputs[1]);
#endif

    string msInputNames[2] = {"ospl", "osol"};
    string sSoapAction = "OSSolverService#knock";
    // create the soap
    theSOAP = WSUtil::createSOAPMessage(numInputs, solverAddress, postURI,
                                        smethod, msInputs, msInputNames, sSoapAction);
    // send the soap to the HTTP server
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSAgent, ENUM_OUTPUT_LEVEL_trace, "SEND THE SOAP\n");
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSAgent, ENUM_OUTPUT_LEVEL_detailed_trace, theSOAP);
#endif
    knockResult = WSUtil::sendSOAPMessage( theSOAP, solverAddress, solverPortNumber);
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSAgent, ENUM_OUTPUT_LEVEL_trace, "Response received\n");
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSAgent, ENUM_OUTPUT_LEVEL_detailed_trace, knockResult);
#endif

    // strip out the OSxL that we want from the SOAP envelope
    knockResult = WSUtil::getOSxL( knockResult, "knock");
    // desoapify the result -- i.e. replace &lt; with <  etc.
    useCDATA = false;
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSAgent, ENUM_OUTPUT_LEVEL_trace, "DeSOAPify result\n");
#endif
    sOSpL = WSUtil::deSOAPify( knockResult, useCDATA);
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSAgent, ENUM_OUTPUT_LEVEL_detailed_trace, sOSpL);
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSAgent, ENUM_OUTPUT_LEVEL_trace, "RETURN THE OSpL\n");
#endif

    return sOSpL;
}//end knock
