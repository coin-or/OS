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
#include "FileUtil.h"   
//#include "CoinSolver.h"
#include "DefaultSolver.h"  
#include "WSUtil.h" 
#include "OSSolverAgent.h"   
#include "OShL.h"     
#include "ErrorClass.h"
#include "OSmps2osil.h"   
#include "Base64.h"
#include "CommonUtil.h"
#include "ErrorClass.h"

#include<iostream>
using std::cout;   
using std::endl;





int main(int argC, char* argV[]){
// test OS code samples here
	try{
		if(argC != 2) throw ErrorClass( "there must be exactly one command line argument");
		std::string osilFileName;
		std::string osil;
		FileUtil *fileUtil = NULL; 
		fileUtil = new FileUtil();
		// get the input file
	    osilFileName =  argV[1];
	    osil = fileUtil->getFileAsString( &osilFileName[0]);
	    OSInstance *osinstance = NULL;
	    OSiLReader *osilreader = NULL;
	    OSiLWriter *osilwriter = NULL;
	    osilwriter = new OSiLWriter();
	    osilreader = new OSiLReader(); 
	    osinstance = osilreader->readOSiL( &osil);
	    cout << osilwriter->writeOSiL( osinstance) << endl;
	    delete osilreader;
	    delete osilwriter;
	   // delete osinstance;
	}
	catch(const ErrorClass& eclass){
		std::cout << eclass.errormsg <<  std::endl;
		return 0;
	} 
}// end main

