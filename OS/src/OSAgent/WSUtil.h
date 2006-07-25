/** @file WSUtil.h
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
 
#ifndef WSUTIL_H
#define WSUTIL_H

#include <iostream>


 
using namespace std;
#define RCVBUFSIZE 1024*8   /* Size of receive buffer */


/*! \class WSUtil WSUtil.h "WSUtil.h"
 *  \brief Used by OSSolverAgent client for help in invoking a remote solver..
 *
 * \remarks 
<p><b>The following key utilities invoked:</b> </p>
<ol>
<li> Open a TCP socket and send a message </li>
<li> Modify XML to use in a SOAP message </li>
<li> Modify the result of a SAOP message to be valid XML </li>
<li> Extract an OSxL from the SOAP </li>
</ol>
 *
 * 
 */
class WSUtil{

public:

	/**
	 *
	 * Default constructor. 
	 * @param solverURI is the location of remote solver or scheduler
	 */
	WSUtil();

	/**
	 *
	 * Class destructor. 
	 */		
	~WSUtil();
	
   	/**
   	 * open a socket and send a SOAP message to the solver Web Service
   	 * 
   	 * <p>
   	 * @param theSOAP is a string that SOAP message sent to the Web service
   	 * @param servIP is a string with IP address or domain name of the server
   	 * @param solverPortNumber is a string with the port number of Web server (assume 80 by default)  
   	 * @return the reply from the Web service in a SOAP message.
	 * </p> 
   	 */	
	static string sendSOAPMessage(string theSOAP, string serviceIP, unsigned int servicePortNumber);
	

   	/**
   	 * prepare XML to be put into a SOAP envelop, 
   	 * replace < with &lt; replace > with &gt; replace " and ' with &quote;
	 *
   	 * <p>
   	 * @param theXmlString is the string to modify to out in the SOAP envelop
   	 * @return the XML string that goes into the SOAP envelop.
	 * </p> 
   	 */
	static string SOAPify( string theXmlString);

   	/**
   	 * take the XML from a SOAP envelop and
   	 * replace &lt; with < replace &gt; with > replace &quot with ";
	 *
   	 * <p>
   	 * @param theXmlString is the string from the SAOP envelop to modify
   	 * @return the resulting XML string.
	 * </p> 
   	 */
	static string deSOAPify( string theXmlString);
	
   	/**
   	 * create the SOAP message that is send to the solver Web Service
	 *
   	 * <p>
   	 * @param numInputs is the number of OSxL protocols (e.g. osil, osol) in the SOAP message
	 * @param solverAddress is the address of the scheduler or solver used
	 * @param postURI is the path to the solver that follows the first
	 * / in the solverAddress
	 * @param smethod is the method invoked, e.g. solve, kill, send, etc.
	 * @param msInputs is string pointer to an array of strings are the OSxL protocols
	 * protocols that go into the message, e.g. osil, osol
	 * @param msInputNames is string pointer to an array of string names of the OSxL protocols
	 * @param sSoapAction is the name of the solver service plus the method, e.g. OSSolverService#solve
   	 * @return the resulting XML string that is the SAOP message.
	 * </p> 
   	 */	
	static string createSOAPMessage(int numInputs, string solverAddress, 
		string postURI, string smethod, string* msInputs, 
		string* msInputNames, string sSoapAction);
	
   	/**
   	 * extract the appropriate OSxL protocol from the SOAP envelop
   	 * <p>
   	 * @param soapstring the soap envelop returned from the Web service
   	 * @param serviceMethod -- extract the string between the <serviceMethodReturn> and </serviceMethodReturn> tags.
   	 * @return the resulting protocol.
	 * </p> 
   	 */
	static string getOSxL(string soapstring, string serviceMethod);
}; //class WSUtil
#endif

