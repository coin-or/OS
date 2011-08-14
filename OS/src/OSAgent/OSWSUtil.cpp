/* $Id$ */
/** @file WSUtil.cpp
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

//#define DEBUG 
#include "OSConfig.h"
#ifdef WIN_
	#ifndef _SYS_UNISTD_H
		#define _SYS_UNISTD_H
	#endif
   	#include <winsock.h>
#else
	#include <sys/socket.h>
	#include <arpa/inet.h>   
	#include <unistd.h>  
	#include <netdb.h>  
#endif

// need to include OSParameters.h after winsock.h, because it may include unistd.h, which needs to know that winsock.h has already been included
// unfortunately, the windows stuff defines a macro named "max", and maybe also "min"? so undefine these first
#ifdef min
#undef min
#endif
#ifdef max
#undef max
#endif 

#include "OSParameters.h"
#include "OSWSUtil.h"
#include <cstring> 
#include <iostream>
#include <sstream> 
#include "OSErrorClass.h"
#include "OSResult.h"
#include "OSrLWriter.h"

using std::string;
using std::cout;
using std::endl;
using std::ostringstream;


WSUtil::WSUtil(){
}

WSUtil::~WSUtil(){
}



string WSUtil::sendSOAPMessage(string theSOAP, string serviceIP, unsigned int servicePortNumber)
{
	try{
		/* code taken from "TCP/IP Sockets in C" by Donahoo and Calvert */
		unsigned long ResolveName(char *name);
		ostringstream ret_message;
		int sock;                        
		struct sockaddr_in httpServAddr; 
		unsigned short httpServPort = servicePortNumber;     
		char *servIP = &serviceIP[0];      
		char httpBuffer[RCVBUFSIZE] = "";    
		int httpStringLen;     
		char* message = &theSOAP[0];       
		#ifdef WIN_
		WSADATA wsaData;
		if( WSAStartup(MAKEWORD(2, 0), &wsaData) != 0 ) throw ErrorClass( "WSAStartup failed");
		#endif
		/* Create a reliable, stream socket using TCP */
		if ((sock = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP)) < 0) throw ErrorClass( "failure creating socket");
		/* Construct the server address structure */
		memset(&httpServAddr, 0, sizeof(httpServAddr));     /* Zero out structure */
		httpServAddr.sin_family      = AF_INET;             /* Internet address family */
		httpServAddr.sin_addr.s_addr = ResolveName( servIP);   /* Server IP address */
		httpServAddr.sin_port        = htons(httpServPort); /* Server port */
		/* Establish the connection to the http server */
		if (connect(sock, (struct sockaddr *) &httpServAddr, sizeof(httpServAddr)) < 0){
			string sipadd = &serviceIP[0];
			string errormsg = "failure connecting with remote socket at address: " + sipadd  ;
			throw ErrorClass( errormsg );
		}
		#ifdef DEBUG
		cout << "Connection Established"  << endl;
		#endif
		httpStringLen = strlen( message);   
		#ifdef DEBUG
		cout << "HERE IS WHAT WE SEND" << endl;
		cout << message << endl;
		#endif
		/* Send the string to the server */	
		if (send(sock, message, httpStringLen, 0) != httpStringLen)
			throw ErrorClass("send() sent a different number of bytes than expected");
		#ifdef DEBUG
		cout << "OSiL sent to server" << endl;
		#endif
		int recvMsgSize = 1;
		int n;
		#ifdef DEBUG
		int char_val;
		#endif
		httpBuffer[ RCVBUFSIZE - 1] = '\0';
		while (recvMsgSize > 0) {
			#ifdef DEBUG
			cout << "start to receive" << endl;
			#endif
			if ((recvMsgSize = recv(sock, httpBuffer, RCVBUFSIZE-1, 0)) < 0)
				throw ErrorClass( "socket error receiving data");
			#ifdef DEBUG
				cout << "Message size =  " << recvMsgSize << endl;
				printf("%s\n", httpBuffer);
				if(recvMsgSize < (RCVBUFSIZE - 1) ){
					for(n = 0; n < recvMsgSize; n++){
						char_val = httpBuffer[ n];
						//cout << "char_val = " << char_val << endl;
					}
				}
			#endif
			//httpBuffer[ recvMsgSize ] = '\0';
			ret_message << httpBuffer;
			// clear the buffer
			for(n = 0; n < RCVBUFSIZE; n++){
				httpBuffer[ n] = 0;
			}
		}
		#ifdef WIN_
		closesocket( sock);
		WSACleanup();
		#else
		close( sock);
		#endif	
		return ret_message.str();  
	}
	catch(const ErrorClass& eclass){
//		OSResult osresult;
//		OSrLWriter osrlwriter;
//		string osrl;
//		osresult.setGeneralMessage( eclass.errormsg);
//		osresult.setGeneralStatusType( "error");
//		osrl = osrlwriter.writeOSrL( &osresult);
//		throw ErrorClass( osrl);
		throw ErrorClass( eclass.errormsg);
	}
}

std::string WSUtil::createSOAPMessage(int numInputs,  string solverAddress, string postURI, string smethod, 
	string* msInputs, string* msInputNames, string sSoapAction){
	ostringstream request, body, msg;
	int i;
	string mynamespace = "xmlns:ns1=\"http://www.optimizationservices.org\"";
	#ifdef DEBUG
	cout << "Solver address = " <<  solverAddress << endl;
	cout << "SOAP action = " <<  sSoapAction << endl;
	cout << "postURI = " <<  postURI << endl;
	#endif
	//request << "POST "  <<  postURI << " HTTP/1.0" <<  "\r";
	request << "POST "  <<  postURI << " HTTP/1.0" << endl ;
	request << "Content-Type: text/xml; charset=UTF-8" << endl;
	request << "Host: " ;
	request << solverAddress << endl;
	request << "Connection: close" << endl;
	request << "Accept: application/soap+xml, application/dime, multipart/related, text/*" << endl;
	request << "Cache-Control: no-cache" << endl;
	request << "Pragma: no-cache" << endl;
	request << "SOAPAction: ";
	request << "\"" << sSoapAction << "\"" << endl;
	//body << "<?xml version='1.0' encoding='utf-8' ?>" << endl;
	body << "<SOAP-ENV:Envelope xmlns:SOAP-ENV=\"http://schemas.xmlsoap.org/soap/envelope/\" xmlns:xsd=\"http://www.w3.org/2001/XMLSchema\" xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\">" << endl;
	body << "<SOAP-ENV:Body>" << endl;
	body << "<ns1:" << smethod << " " << mynamespace << ">" << endl;
	for(i = 0; i < numInputs; i++){
		body << "<" << msInputNames[ i] << " xsi:type=\"xsd:string\"" << ">" ;
		body << msInputs[ i] ;
		body << "</" << msInputNames[ i] << ">" << endl;
	}
	body << "</ns1:" << smethod << ">" << endl;
	body << "</SOAP-ENV:Body>" << endl;
	body << "</SOAP-ENV:Envelope>" << endl;
	body << "\n";
	request << "Content-Length: " << body.str().length();
	request << endl << endl;

	request << body.str();
	return request.str();
}// end createSOAPMessage

std::string WSUtil::createFormDataUpload(std::string solverAddress, std::string postURI, 
		std::string fileName,  std::string theFile, std::string boundaryName){
	ostringstream request, body;
	std::cout << "Solver address = " <<  solverAddress << std::endl;
	std::cout << "postURI = " <<  postURI << std::endl;
	request << "POST "  <<  postURI << " HTTP/1.0" <<  "\r\n";
	request << "Host: " ;
	request << solverAddress << "\r\n";
	request << "Content-Type: multipart/form-data; boundary=" ;
	request << boundaryName << "\r\n";
	request << "Connection: keep-alive" << "\r\n";
	//request << "Referer: /servlets-examples/fileupload.html" << endl;
	body << "--" ;
	body << boundaryName  ;
	body << "\r\n";
	body << "Content-Disposition: form-data; name=\"";
	body << "myfile";
	body << "\"";
	body << ";";
	body << " filename=\"";
	body << fileName;
	body << "\"" << "\r\n";
	
	body << "Content-Type: text/plain" ;
	body << "\r\n" ;
	body << "\r\n";
	body << theFile ;
	body << "\r\n";
	body << "--" ;
	body << boundaryName;
	body << "--" ;
	body << "\r\n" ;
	
	
	request << "Content-Length: " << body.str().length();
	request << "\r\n";
	request << "\r\n";
	request << body.str();
	return request.str();
	//return theFile;
}// end createFromDataUpload


string WSUtil::SOAPify(std::string inputstring, bool useCDATA){
	/* replace all occurances of "<" with "&lt;"  all 
	occurances of ">" with "&gt;" and all occurances of " or ' with &quote;
	*/
	#ifdef DEBUG
	cout << "prepare the XML for a SOAP envelope" << endl;
	#endif
	ostringstream body;
	int i = 0;
	int loopsize = inputstring.length();
	if(useCDATA == true){
		body << "<![CDATA[";
		body << inputstring;
		body << "]]>";
	}else{
		while (i < loopsize){
			switch( inputstring[i]){
				case '<':
					body << "&lt;";
					break;
				case '>':
					body << "&gt;";
					break;
				case '\"':
					body << "&quot;";
					break;
				case '\'':
					body << "&quot;";
					break;
				default:
				body << inputstring[i];
			}
			i++;
		}//end while
	}
	return body.str();
}

string WSUtil::deSOAPify(std::string inputstring, bool useCDATA){
	/* replace all occurances of "&lt;" with "<"  all 
	occurances of "&gt;" with ">" and all occurances of "&quote;" with "
	*/
	ostringstream body;
	int i = 0;
	int loopsize = inputstring.length();
	if(useCDATA == true){
		
		string::size_type pos1 = inputstring.find( "<![CDATA[" );	
		string::size_type pos2 = inputstring.find( "]]>" );
		body << inputstring.substr( pos1 + 1, pos2 - pos1 - 1);
		
		//kipp -- put in error checking
	
	}else{
		while (i < loopsize){
			//i = inputstring.find('&', i);
			//if (i == string::npos)  return ostringstream.str();
			if(inputstring[i] == '&'){
				switch (inputstring[i+1]) {
				case 'l':
					if (inputstring[i + 2] == 't' && inputstring[i + 3] == ';') {
						body << "<";
					}
					i = i + 4;
					break;
				case 'g':
					if (inputstring[i + 2] == 't' && inputstring[i + 3] == ';') {
						body << ">";
					}
					i = i + 4;
					break;
				case 'q':
					if (inputstring[i + 2] == 'u' && inputstring[i + 3] == 'o' && inputstring[i + 4] == 't' && inputstring[i + 5] == ';') {
						body << "\"";
					}
					i = i + 6;
					break;
				default:
					body << inputstring[i];
					i++;
					break;
				} //end switch
			} // end if'&"
			else{
				body << inputstring[i];
				i++;
			}
		}// end while
	}
	return body.str();
}

unsigned long ResolveName(char *name){
	struct hostent *host;
	try{
		if ((host = gethostbyname(name)) == NULL){
			string s1 = &name[0];
			string errormsg = "cannot resolve the domain name:  " + s1;
			throw ErrorClass( errormsg);
		}
		return *((unsigned long *) host->h_addr_list[0]);
	}
	catch(const ErrorClass& eclass){
		throw eclass;
	}
}

//void DieWithError(char *errorMessage)
//{
//	#ifdef DEBUG
//    cout << errorMessage << endl;
//	#endif
//    exit(1);
//}

string WSUtil::getOSxL(string soapstring, string serviceMethod){
	/*  get the string that starts with <osxl
	 * inside the soap envelope
	 */
	//string start = "";
	//string end = "";
	string result = "";
	//start = "<" + serviceMethod + "Return";
	//end = "</"+serviceMethod + "Return";
	// strip off the return header information 
	// find start of XML information
	string::size_type startxml = soapstring.find(serviceMethod+"Return" , 1);
	string::size_type pos;
	if (startxml == string::npos){
		//something went wrong, perhaps we had an error in service location
	
		OSResult *osresult = NULL;
		OSrLWriter *osrlwriter = NULL;
		osrlwriter = new OSrLWriter();
		osresult = new OSResult();
		// see if the SOAP contains <faultstring> -- if so use it
		startxml = soapstring.find("<faultstring>" , 1);
		if(startxml == string::npos) {
			osresult->setGeneralMessage( "we had a problem contacting the server which we cannot figure out -- check address of server");
		}
			else {
				pos = soapstring.find("</faultstring>" , startxml  + 1);
				std::string tmpString = soapstring.substr(startxml + 13 , pos - startxml - 13);
				osresult->setGeneralMessage( "There was a communication problem with server, SOAP error message: "  + tmpString);
		}

		osresult->setGeneralStatusType( "error");
		result = osrlwriter->writeOSrL( osresult);	
		delete osresult;
		osresult = NULL;
		delete osrlwriter;
		osrlwriter = NULL;	
	//
		return result;	
	}    
	else{
		startxml = soapstring.find(">", startxml + 1);
		if(startxml == string::npos) return result;
		// find the end of the string
		string::size_type endxml = soapstring.find( "</", startxml);
		// now go back for the </
		
		if(endxml == string::npos){
			return result;
		}
		else{
			// get the > that ends </osxl
			//endxml = soapstring.find(">", endxml - 1);
			// now get the substring
			startxml++;
			result = soapstring.substr(startxml, endxml - startxml);
			return result;
		}
	}
	return result;
}
