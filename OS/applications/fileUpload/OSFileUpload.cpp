/** @file fileUpload.cpp
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
 * <p>
 * In the case of large OSiL files it may not be desirable 
 * to use Web Services
 * to send problem instances to the Web Server. This executable uses
 * <b>OSFileUpload</b> Java Servlet to upload large files very quickly.
 * </p>
 * 
 * <p>
 * NOTE: In this example we have hard coded in the URL of the server
 * http://128.135.130.17:8080/os/servlet/OSFileUpload
 * the user will need to change this for their server
 * </p>
 */
 

 
#include "OSResult.h"
#include "OSiLReader.h"
#include "OSiLWriter.h"
#include "OSrLReader.h"
#include "OSrLWriter.h"
#include "OSInstance.h"
#include "OSnLNode.h"
#include "OSFileUtil.h"
#include "OSErrorClass.h"
#include "OSWSUtil.h" 
#include "OSSolverAgent.h" 
#include "CoinHelperFunctions.hpp"  
//

#ifdef HAVE_CTIME
# include <ctime>
#else
# ifdef HAVE_TIME_H
#  include <time.h>
# else
#  error "don't have header file for time"
# endif
#endif


#include <sstream>
#include <vector>


int main(int argC, char* argV[])
{
	FileUtil *fileUtil = NULL;  
	try{
		if( argC != 2) throw ErrorClass( "there must be exactly one command line argument which should be the file name");
		fileUtil = new FileUtil(); 
		time_t start, finish, tmp;
		std::string osilFileNameWithPath;
		std::string osilFileName;
		std::string osil;
		std::string uploadResult;
	  	const char dirsep =  CoinFindDirSeparator();
		osilFileNameWithPath = argV[ 1];
		std::cout << "FILE NAME = " << argV[1] << std::endl;
		std::cout << "Read the file into a string" << std::endl; 
		osil = fileUtil->getFileAsString( &osilFileNameWithPath[ 0]); 
		OSSolverAgent* osagent = NULL;
		//
		// kipp-- you have changed the path name on the server
		//
		throw ErrorClass( "please go in and put in a valid server URL and recompile \n  see line 81" );
		// put in a valid URL below
		osagent = new OSSolverAgent("http://******/os/servlet/OSFileUpload");
		// put in a valid URL above
		//
		//
		// strip off just the file name
		// modify to into a file C:filename
		int index = osilFileNameWithPath.find_last_of( dirsep);
		int slength = osilFileNameWithPath.size();
		osilFileName = osilFileNameWithPath.substr( index + 1, slength - 1) ;
		std::cout << std::endl << std::endl;
		std::cout << "Place remote synchronous call" << std::endl;
		//std::cout << "osilFileName =  " << osilFileName << std::endl;
		//std::cout << "osil =  " << osil << std::endl;
		start = time( &tmp);
		uploadResult = osagent->fileUpload(osilFileName, osil);
		finish = time( &tmp);
		std::cout << "File Upload took (seconds): "<< difftime(finish, start) << std::endl;
		std::cout << uploadResult << std::endl;
		//return 0;
		// now tell solve the problem remotely with cbc
		//osagent = new OSSolverAgent("http://128.135.130.17:8080/os/OSSolverService.jws");
		// the osil comes from the remote location
		//osil = "";
		//std::string osol = "<osol><general><instanceLocation locationType=\"local\">" + remoteFileLocation + osilFileName + "</instanceLocation></general> </osol>";
		//std::string osrl = osagent->solve(osil, osol);
		//std::cout << osrl << std::endl;
		if(fileUtil != NULL) delete fileUtil;
		return 0;
	}
	catch( const ErrorClass& eclass){
		std::cout << eclass.errormsg <<  std::endl;
		if(fileUtil != NULL) delete fileUtil;
		return 0;
	}
}

