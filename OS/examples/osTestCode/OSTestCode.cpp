/** @file osTestCode.cpp
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
 * This is a dummy executable that does nothing but 
 * print <I>Hello World</I>. I put in test code here when doing
 * various tests.
 * 
 */
 


#include <cppad/cppad.hpp> 
#include "OSConfig.h"

#include "OSResult.h" 
#include "OSiLReader.h"        
#include "OSiLWriter.h"   
#include "OSrLReader.h"          
#include "OSrLWriter.h"      
#include "OSInstance.h"  
#include "OSFileUtil.h"   
#include "OSDefaultSolver.h"  
#include "OSWSUtil.h" 
#include "OSSolverAgent.h"   
#include "OShL.h"     
#include "OSErrorClass.h"
#include "OSmps2osil.h"   
#include "OSBase64.h"
#include "OSCommonUtil.h"
#include "OSErrorClass.h"

#include<iostream>
using std::cout;   
using std::endl;





int main(int argC, char* argV[]){
// test OS code samples here
	FileUtil *fileUtil = NULL; 
	fileUtil = new FileUtil();
	try{
		if(argC != 2) throw ErrorClass( "there must be exactly one command line argument");
		std::string osilFileName;
		std::string osil;
		// get the input file
	    osilFileName =  argV[1];
	    osil = fileUtil->getFileAsString( osilFileName.c_str());
	    OSInstance *osinstance = NULL;
	    OSiLReader *osilreader = NULL;
	    OSiLWriter *osilwriter = NULL;
	    osilwriter = new OSiLWriter();
	    osilreader = new OSiLReader(); 
	    osinstance = osilreader->readOSiL( osil);
	    cout << osilwriter->writeOSiL( osinstance) << endl;
	    delete osilreader;
	    delete osilwriter;
	    delete fileUtil;
	   // delete osinstance;
	}
	catch(const ErrorClass& eclass){
		delete fileUtil;
		std::cout << eclass.errormsg <<  std::endl;
		return 0;
	} 
}// end main

