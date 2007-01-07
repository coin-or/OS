/** @file OSSolverService.cpp
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
 
 // this is test code, e.g. test the parser or a solver, etc. 
 // this is just for playing around, do not confuse it with the unitTest
 
 
#include "OSResult.h"
#include "OSiLReader.h"
#include "OSiLWriter.h"
#include "OSrLReader.h"
#include "OSrLWriter.h"
#include "OSInstance.h"
#include "OSnLNode.h"
#include "FileUtil.h"
#include "ErrorClass.h"
#include "WSUtil.h" 
#include "OSSolverAgent.h" 
#include "CoinHelperFunctions.hpp"  
//
#include <time.h>
#include <sstream>
#include <ctype.h>
#include <vector>
#include <string>

using std::cout;
using std::endl;

int main(int argC, char* argV[])
{
	FileUtil *fileUtil = NULL;  
	fileUtil = new FileUtil(); 
	time_t start, finish, tmp;
	std::string osilFileName;
	std::string osil;
	std::string uploadResult;
  	std::string dataDir;
  	const char dirsep =  CoinFindDirSeparator();
    dataDir = dirsep == '/' ? "../../data/" : ".\\..\\data\\";
	osilFileName =  dataDir + "parincLinear.osil";
	//osilFileName =  "/Users/kmartin/Documents/files/code/OSRepository/linear/continuous/osa-60.osil";
	std::cout << "Read the file into a string" << std::endl;
	osil = fileUtil->getFileAsString( &osilFileName[0]);
	OSSolverAgent* osagent = NULL;
	osagent = new OSSolverAgent("http://128.135.130.17:8080/fileupload/servlet/B36104FileUpload");
	std::cout << std::endl << std::endl;
	std::cout << "Place remote synchronous call" << std::endl;
	start = time( &tmp);
	uploadResult = osagent->fileUpload("osa-60.osil", osil);
	finish = time( &tmp);
	std::cout << "File Upload took (seconds): "<< difftime(finish, start) << std::endl;
	std::cout << uploadResult << std::endl;
	return 0;
	// now tell solve the problem remotely with cbc
	osagent = new OSSolverAgent("http://128.135.130.17:8080/cbc/CBCSolverService.jws");
	//osil = "";
	std::string osol = "<osol> </osol>";
	std::string osrl = osagent->solve(osil, osol);
	std::cout << osrl << std::endl;
	return 0;
}

