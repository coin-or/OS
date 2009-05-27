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

	//http://bytes.com/groups/cpp/133393-usage-rdbuf
	//std::stringstream outStr (std::stringstream::in | std::stringstream::out);
	ostringstream solverOutput;
	//std::streambuf* save_buffer = cout.rdbuf(solverOutput.rdbuf());
	FILE * pFile;
	FILE * pFile2;
//	pFile2 = freopen("gail.txt", "w", stdout);
	//if (pFile==NULL) perror ("Error opening file");

	std::cout << "HOWDY WORLD NOW " ;
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
//	fclose( pFile2);
//	pFile = fopen("gail.txt", "r");
	char c;
	
	long size;
	size=ftell ( stdout);
	cout << "size = " << size << endl;
	return 0;

   	while (!feof( stdout)) {
		c = fgetc (stdout);
		if(c !=-1) solverOutput << c;
      }
	
	//while (!feof( pFile)) {
	//	c = fgetc (pFile);
	//	if(c !=-1) solverOutput << c;
    //  }
	solverOutput << "\n";
   // fclose (pFile);
	
	
	//fileUtil->writeFileFromString("kipp.txt", solverOutput.str() );
	std::cout << "HOWDY WORLD NOW 123" ;
	std::cout << solverOutput.str() ;


	//cout.rdbuf(save_buffer); //

	//outStr << "GAIL HONDA";
	//std::cout << outStr.str() << std::endl;
	
	return 0;

	//cout.rdbuf(outStr);

	double x = 100000000000001.;
	std::cout  << os_dtoa_format(x) ;


	
	//osinstance->initForAlgDiff( );
	//OSExpressionTree* exptree = osinstance->getNonlinearExpressionTree( 0);
	std::cout << osinstance->getNonlinearExpressionTreeInInfix( 0) << std::endl;
	std::cout << osinstance->printModel( 0) << std::endl;
	try{
		//osinstance->getNonlinearExpressionTreeInInfix( -1);
		theModel = osinstance->printModel( );
		std::cout << theModel << std::endl;
	}
	catch(const ErrorClass& eclass){
		std::cout <<  eclass.errormsg << std::endl;
	} 	


	delete fileUtil;
	fileUtil = NULL;
	return 0;
}// end main

