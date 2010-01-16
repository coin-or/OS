/* $Id$ */
/** @file osTestCode.cpp
 * 
 * @author  Horand Gassmann, Jun Ma, Kipp Martin, 
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
 
#include <cppad/cppad.hpp> 
//#include "CoinUtilsConfig.h"
#include "OSCoinSolver.h"
#include "OSConfig.h"
#include "OSmps2osil.h" 
#include "OSResult.h" 
#include "OSOption.h"
#include "OSiLReader.h"        
#include "OSiLWriter.h" 
#include "OSoLReader.h"        
#include "OSoLWriter.h" 
#include "OSrLReader.h"          
#include "OSrLWriter.h"      
#include "OSInstance.h"  
#include "OSFileUtil.h"  
#include "CoinError.hpp"

#include "OSDefaultSolver.h"  
#include "OSWSUtil.h" 
#include "OSSolverAgent.h"   
#include "OShL.h"     
#include "OSErrorClass.h"
#include "OSBase64.h"
#include "OSMathUtil.h"


#include <CoinMpsIO.hpp>
#include <CoinPackedMatrix.hpp>


#include "CoinError.hpp"
#include "CoinHelperFunctions.hpp"


#ifdef COIN_HAS_IPOPT    
#include "OSIpoptSolver.h"
#endif 


#include<iostream> 
#include <ostream>
#include <sstream>
#include <streambuf>

#include<stdio.h>
 
using std::cout;   
using std::endl;




int main(int argC, char* argV[]){
	
	// template -- add your code here -- //
	std::cout << "Hello World" << std::endl;
	FileUtil *fileUtil = NULL; 
	fileUtil = new FileUtil();
	try {
	
		std::string osrl = fileUtil->getFileAsString( "solutionResult.xml" );	
		OSrLReader *osrlreader = NULL;
		osrlreader = new OSrLReader();
		osrlreader->readOSrL( osrl);
		delete fileUtil;
		std::cout << osrl.size() << std::endl;
		delete osrlreader;
	}
	catch(const ErrorClass& eclass){
		delete fileUtil;
		std::cout << eclass.errormsg <<  std::endl;
		return 0;
	} 

	
	return 0;
	
	time_t rawtime;
	struct tm * timeinfo;
	int year, month ,day;
	char * weekday[] = { "Sunday", "Monday",
		"Tuesday", "Wednesday",
		"Thursday", "Friday", "Saturday"};
	int days_per_month[] = {31, 28, 31, 30,
	31, 30, 31, 31, 30, 31, 30, 31};
	

	
	/* prompt user for date */
	printf ("Enter year: "); scanf ("%d",&year);
	printf ("Enter month: "); scanf ("%d",&month);
	
	// adjust for leap year
	if ( ((year % 4 == 0) && (year % 100 != 0))  || (year % 400 == 0)) {
		days_per_month[ 1] = 29;
	}
	std::cout << "GAIL = " << year % 4 << std::endl;
	/* get current timeinfo and modify it to the user's choice */
	time ( &rawtime );
	timeinfo = localtime ( &rawtime );
	timeinfo->tm_year = year - 1900;
	timeinfo->tm_mon = month - 1;
	timeinfo->tm_mday = 1;
	
	/* call mktime: timeinfo->tm_wday will be set */
	mktime ( timeinfo );
	
	printf ("That day is a %s.\n", weekday[timeinfo->tm_wday]);
	std::cout << "Days in this month = " << days_per_month[ month-1] << std::endl;
	
	return 0;
}// end main

