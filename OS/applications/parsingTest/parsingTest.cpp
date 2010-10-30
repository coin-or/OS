/* $Id: parsingTest.cpp 3583 2010-07-13 20:39:42Z kmartin $ */
/** @file parsingTest.cpp
 * 
 * \brief This file tests the validity of an OSiL, OSoL or OSrL file.
  
 *
 * @author  Horand Gassmann, Jun Ma, Kipp Martin, 
 * @version 1.0, 18/Sep/2010
 * @since   OS2.2
 *
 * \remarks
 * Copyright (C) 2010, Horand Gassmann, Jun Ma, Kipp Martin,
 * Dalhousie University, Northwestern University, and the University of Chicago.
 * All Rights Reserved.
 * This software is licensed under the Common Public License. 
 * Please see the accompanying LICENSE file in root directory for terms.
 * 
 * 
 */ 

#include <cppad/cppad.hpp> 
#include "OSConfig.h"
#include "OSInstance.h"  
#include "OSOption.h"
#include "OSResult.h" 
#include "OSiLReader.h"        
#include "OSoLReader.h"        
#include "OSrLReader.h"          
#include "OSFileUtil.h"  
#include "CoinError.hpp"

#include "OSWSUtil.h" 
#include "OShL.h"     
#include "OSErrorClass.h"
#include "OSBase64.h"
#include "OSMathUtil.h"


#include <CoinMpsIO.hpp>
#include <CoinPackedMatrix.hpp>


#include "CoinError.hpp"
#include "CoinHelperFunctions.hpp"

#ifdef HAVE_CTIME
# include <ctime>
#else
# ifdef HAVE_TIME_H
#  include <time.h>
# else
#  error "don't have header file for time"
# endif
#endif


#ifdef HAVE_CMATH
# include <cmath>
#else
# ifdef HAVE_CMATH_H
#  include <cmath.h>
# endif
#endif



#ifdef HAVE_CSTDIO
# include <cstdio>
#else
# ifdef HAVE_STDIO_H
#  include <stdio.h>
# else
#  error "don't have header file for stdio"
# endif
#endif

//#ifdef HAVE_WINDOWS_H
//#include <windows.h>
//#endif

using std::cout;   
using std::endl;
using std::ostringstream; 

//#define MY_DEBUG

int main(int argC, char* argV[])
{
	WindowsErrorPopupBlocker();
	bool ok;
	double check;
	
	if( argC > 3){
		std::cout << "Too Many Input Parameters" << std::endl;
		return 1;
	}

	if (argC < 3 || ((strcmp(argV[2],"osil") != 0) && (strcmp(argV[2],"osol") != 0) && (strcmp(argV[2],"osrl") != 0)))
	{
		std::cout << "usage: parsingtest <filename> osil|osol|osrl"<< std::endl;
		return 1;
	}

	// define the classes
	FileUtil *fileUtil = NULL;  
	OSiLReader *osilreader = NULL;
	OSoLReader *osolreader = NULL;
	OSrLReader *osrlreader = NULL;
	// end classes    

	std::string testFileName;
	std::string osxl;
	std::string schema;
	ostringstream parsingTestResult;
	ostringstream parsingTestResultFailure;


	fileUtil = new FileUtil();

	try{
		testFileName =  argV[1];
		schema = argV[2];

#ifdef MY_DEBUG
		std::cout << "Processing file: " ;
		std::cout <<  testFileName << std::endl;
#endif

		osxl = fileUtil->getFileAsString( testFileName.c_str() );

#ifdef MY_DEBUG
		std::cout << "Done reading the file" << std::endl;
#endif

		if (schema == "osil")
		{
			osilreader = new OSiLReader(); 

#ifdef MY_DEBUG
			parsingTestResult << "Reading files successfully" << std::endl;
#endif

			osilreader->readOSiL( osxl);
			delete osilreader;
			osilreader = NULL;
		}
		else if (schema == "osol")
		{
			osolreader = new OSoLReader(); 

#ifdef MY_DEBUG
			parsingTestResult << "Reading files successfully" << std::endl;
#endif

			osolreader->readOSoL( osxl);
			delete osolreader;
			osolreader = NULL;
		}
		else if (schema == "osrl")
		{
			osrlreader = new OSrLReader(); 

#ifdef MY_DEBUG
			parsingTestResult << "Reading files successfully" << std::endl;
#endif

			osrlreader->readOSrL( osxl);
			delete osrlreader;
			osrlreader = NULL;
		};

	}	
	catch(const ErrorClass& eclass)
	{
		cout << endl << endl << endl;
		if(osilreader != NULL) delete osilreader;
		if(osolreader != NULL) delete osolreader;
		if(osrlreader != NULL) delete osrlreader;
		//  Problem with the parser
		parsingTestResultFailure << eclass.errormsg << endl;
		parsingTestResultFailure << "There was a failure in the " + schema + " parser; ";
		parsingTestResultFailure << "file " << testFileName << " not processed." << endl;
	}

	delete fileUtil;
	fileUtil = NULL;
	    
	if(parsingTestResultFailure.str().length() > 0){
		cout << "PARSING FAILED ON THE FOLLOWING:" << endl << endl;
		cout << parsingTestResultFailure.str() << endl << endl;
		return 1;
	}
	else{

#ifdef MY_DEBUG
		std::cout << "PARSING SUCCEEDED" << std::endl;
#endif

		return 0;
	}
}//end main
