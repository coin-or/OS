/* $Id: misc.cpp 3675 2010-09-12 05:36:34Z kmartin $ */
/** @file osTestCode.cpp
 * 
 * @author  Jun Ma, Kipp Martin, 
 * @version 1.0, 10/05/2005
 * @since   OS1.0
 *
 * \remarks
 * Copyright (C) 2005, Jun Ma, Kipp Martin,
 * Northwestern University, and the University of Chicago.
 * All Rights Reserved.
 * This software is licensed under the Common Public License. 
 * Please see the accompanying LICENSE file in root directory for terms.
 * 
 */ 
 
//#include <cppad/cppad.hpp> 
#include "OSConfig.h"
#include "OSCoinSolver.h"
#include "OSIpoptSolver.h"
#include "OSResult.h" 
#include "OSiLReader.h"        
#include "OSiLWriter.h"   
#include "OSrLReader.h"          
#include "OSrLWriter.h"      
#include "OSInstance.h"  
#include "OSFileUtil.h"   
#include "OSDefaultSolver.h"     
#include "OShL.h"     
#include "OSErrorClass.h"
#include "OSmps2osil.h"   
#include "OSBase64.h"
#include "OSCommonUtil.h"
#include "OSErrorClass.h"
#include "OSMathUtil.h"
#include "CoinFinite.hpp"

#include<iostream> 
#include <ostream>
#include <sstream>
#include <streambuf>

#include<stdio.h>
 
using std::cout;   
using std::endl;

/** this is demo code -- illustrate things
 * that I may wish to use
 */


int main(int argC, char* argV[]){
	/** some AMPL insanity -- the fileUtil must be built in order to avoid
	 * an ASL error - on the Mac only
	 */
	FileUtil *fileUtil = NULL; 
	fileUtil = new FileUtil();
	cout << "Start Building the Model" << endl;
	std::cout << "Hello World" << std::endl;

	std::string osilFileName =   "../../data/osilFiles/rosenbrockmod.osil";
	std::cout << "Try to read a sample file" << std::endl;
	std::cout << "The file is: " ;
	std::cout <<  osilFileName << std::endl;
	std::string osil = fileUtil->getFileAsString( osilFileName.c_str() );
	OSiLReader *osilreader = NULL;
	osilreader = new OSiLReader(); 
	OSInstance *osinstance;
	osinstance = osilreader->readOSiL( osil);	
	std::string theModel;


	#if 0
	//WRITE STDOUT  TO A FILE -- C LEVEL stuff
	//http://bytes.com/groups/cpp/133393-usage-rdbuf
	ostringstream solverOutput;
	FILE * pFile;
	FILE * pFile2;
	pFile2 = freopen("os.log", "w", stdout);
	//if (pFile==NULL) throw ErrorClass ("Error opening file for stdout");
	std::cout << "LINE 1 OUTPUT "  << std::endl;  //cout will get diverted
	printf("LINE 2 OUTPUT \n"); // printf will get diverted
	fclose( pFile2);
	pFile = fopen("os.log", "r");
	char c;
   	while (!feof( stdout)) {
		c = fgetc (stdout);
		if(c !=-1) solverOutput << c;
      }
	fileUtil->writeFileFromString("kipp.txt", solverOutput.str() );
	#endif
	
	#if  1
	//WRITE COUT TO A STRING -- this C++ stuff -- it will NOT write stdout, e.g. printf()
	ostringstream solverOutput;
	std::streambuf* save_buffer = cout.rdbuf(solverOutput.rdbuf()); //turn off cout
	std::cout << "LINE 1 OUTPUT " << std::endl ;  //this should get diverted
	printf("LINE 2 OUTPUT \n") ; //this will not get diverted
	cout.rdbuf(save_buffer); // turn cout back on
	std::cout << "LINE 3 OUTPUT " << std::endl;
	// now the string
	std::cout << solverOutput.str() << std::endl;
	#endif  
	
	//DEMO -- how to empty the string buffer
	ostringstream outStr;
	outStr << "Hello";
	outStr << " World" ;
	outStr << std::endl;
	std::cout << outStr.str() << std::endl;
	outStr.str(""); // here is where we empty the buffer
	outStr << "New" << std::endl;
	std::cout << outStr.str() << std::endl;
	

	delete fileUtil;
	fileUtil = NULL;
	return 0;
}// end main

