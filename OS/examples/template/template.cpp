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

	std::string osilFileName =   "../../data/osilFiles/rbrockerror.osil";
	std::cout << "Try to read a sample file" << std::endl;
	std::cout << "The file is: " ;
	std::cout <<  osilFileName << std::endl;
	std::string osil = fileUtil->getFileAsString( osilFileName.c_str() );
	OSiLReader *osilreader = NULL;
	osilreader = new OSiLReader(); 
	OSInstance *osinstance;
	osinstance = osilreader->readOSiL( osil);	
	std::string theModel;
	
	//osinstance->initForAlgDiff( );
	//OSExpressionTree* exptree = osinstance->getNonlinearExpressionTree( 0);
	//std::cout << osinstance->printModel( 0) << std::endl;
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

