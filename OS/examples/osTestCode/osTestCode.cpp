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
	std::string osilFileName;
	std::string osil;
	std::string uploadResult;
  	std::string dataDir;
  	const char dirsep =  CoinFindDirSeparator();
    dataDir = dirsep == '/' ? "../../data/" : ".\\..\\data\\";
	osilFileName =  dataDir + "parincLinear.osil";
	osil = fileUtil->getFileAsString( &osilFileName[0]);
	OSSolverAgent* osagent = NULL;
	osagent = new OSSolverAgent("http://127.0.0.1:8181/fileupload/servlet/B36104FileUpload");
	std::cout << "Place remote synchronous call" << std::endl;
	uploadResult = osagent->fileUpload("parincLinear.osil", osil);
	std::cout << uploadResult << std::endl;
	return 0;
}

