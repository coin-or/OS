/** @file fileUpload.cpp
 * 
 * @author  Horand Gassmann, Jun Ma, Kipp Martin
 * @version 2.2, 01/Sep/2010
 * @since   OS1.0
 *
 * \remarks
 * Copyright (C) 2005-2010, Robert Fourer, Gus Gassmann, Jun Ma, Kipp Martin,
 * Northwestern University, Dalhousie University and the University of Chicago.
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
 * http://128.135.130.17:8080/os/servlet/OSFileUpload.
 * The user will need to change this for their own needs.
 * </p>
 */

//#include "OSResult.h"
//#include "OSiLReader.h"
//#include "OSiLWriter.h"
//#include "OSrLReader.h"
//#include "OSrLWriter.h"
//#include "OSInstance.h"
//#include "OSnLNode.h"

#include "OSConfig.h"
#include "OSParameters.h"
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
//#include <asl.h>

int main(int argC, char* argV[])
{
	WindowsErrorPopupBlocker();
	FileUtil *fileUtil = NULL;  
  	const char dirsep =  CoinFindDirSeparator();
	std::string osilFileNameWithPath;
	std::string osilFileName;
	std::string osil;
	std::string uploadResult;
	std::string actualServer;

	/* Replace this URL as needed */
	std::string defaultServer = "http://128.135.130.17:8080/os/servlet/OSFileUpload";

	try{
		if( argC == 1 || argC > 3 || argV[1] == "-?") 
			throw ErrorClass( "usage: OSFileUpload <filename> [<serverURL>]");
		fileUtil = new FileUtil(); 
		time_t start, finish, tmp;
		osilFileNameWithPath = argV[ 1];
		std::cout << "FILE NAME = " << argV[1] << std::endl;
		std::cout << "Read the file into a string" << std::endl; 
		osil = fileUtil->getFileAsString( osilFileNameWithPath.c_str() ); 
		OSSolverAgent* osagent = NULL;
		if (argC == 2)
			actualServer = defaultServer;
		else
			actualServer = argV[2];
		osagent = new OSSolverAgent(actualServer);

		// strip off just the file name
		// modify to into a file C:filename
		int index = osilFileNameWithPath.find_last_of( dirsep);
		int slength = osilFileNameWithPath.size();
		osilFileName = osilFileNameWithPath.substr( index + 1, slength) ;
		std::cout << std::endl << std::endl;
		std::cout << "Place remote synchronous call" << std::endl;

		start = time( &tmp);
		uploadResult = osagent->fileUpload(osilFileName, osil);
		finish = time( &tmp);
		std::cout << "File Upload took (seconds): "<< difftime(finish, start) << std::endl;
		std::cout << uploadResult << std::endl;

		if(fileUtil != NULL) delete fileUtil;
		return 0;
	}
	catch( const ErrorClass& eclass){
		std::cout << eclass.errormsg <<  std::endl;
		if(fileUtil != NULL) delete fileUtil;
		return 0;
	}
}

