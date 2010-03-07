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
 
#include "OSCoinSolver.h"
#include "OSResult.h" 
#include "OSiLReader.h"        
#include "OSiLWriter.h" 
#include "OSoLReader.h"
#include "OSrLReader.h"        
#include "OSrLWriter.h"      
#include "OSInstance.h"  
#include "OSOption.h"
#include "OSoLWriter.h"
#include "OSFileUtil.h"  
#include "OSConfig.h"  
#include "OSDefaultSolver.h"  
#include "OSWSUtil.h" 
#include "OSSolverAgent.h"   
#include "OShL.h"     
#include "OSErrorClass.h"
#include "OSmps2osil.h"   
#include "OSBase64.h"




using std::ostringstream;


#ifdef COIN_HAS_KNITRO    
#include "OSKnitroSolver.h"
#endif 





#ifdef COIN_HAS_LINDO    
#include "OSLindoSolver.h"
#endif 

/*
#ifdef COIN_HAS_IPOPT  
	#ifndef COIN_HAS_ASL
		#include "OSIpoptSolver.h"
		#undef COIN_HAS_ASL
	#else
		#include "OSIpoptSolver.h"
#endif
#endif 
*/

#ifdef COIN_HAS_ASL
#include "OSnl2osil.h"
#endif



//#ifdef COIN_HAS_IPOPT  
//#include "OSIpoptSolver.h"
//#endif

#ifdef COIN_HAS_IPOPT  
	#ifndef COIN_HAS_ASL
		#include "OSIpoptSolver.h"
		#undef COIN_HAS_ASL
	#else
		#include "OSIpoptSolver.h"
	#endif
#endif



#ifdef COIN_HAS_BONMIN   
#include "OSBonminSolver.h"
#endif 

#ifdef COIN_HAS_COUENNE
#include "OSCouenneSolver.h"
#endif 


#include "OSOptionsStruc.h"  


using std::cout;
using std::endl;
using std::ostringstream;
using std::string;





int main(int argC, char* argV[]){
	
	// template -- add your code here -- //
	std::cout << "Hello World" << std::endl;
	FileUtil *fileUtil = NULL; 
	fileUtil = new FileUtil();
    std::cout << std::endl << std::endl;
	OSnl2osil *nl2osil = NULL;


	try {	
		nl2osil = new OSnl2osil( "test.nl"); 
        nl2osil->createOSInstance() ;
        OSiLWriter *osilwriter = NULL;
		osilwriter = new OSiLWriter();
		std::string osil;
		osil = osilwriter->writeOSiL(  nl2osil->osinstance) ;
        //std::cout << osil << std::endl;
        fileUtil->writeFileFromString("tmp.osil", osil);
		delete fileUtil;
		delete nl2osil;
        delete osilwriter;

	}
	catch(const ErrorClass& eclass){
        std::cout << "THERE WAS AN ERROR" <<  std::endl;
		delete fileUtil;
		delete nl2osil;
        std::cout << "THERE WAS AN ERROR" <<  std::endl;
		std::cout << eclass.errormsg <<  std::endl;
		return 0;
	} 

	
	return 0;
	
// 	time_t rawtime;
// 	struct tm * timeinfo;
// 	int year, month ,day;
// 	char * weekday[] = { "Sunday", "Monday",
// 		"Tuesday", "Wednesday",
// 		"Thursday", "Friday", "Saturday"};
// 	int days_per_month[] = {31, 28, 31, 30,
// 	31, 30, 31, 31, 30, 31, 30, 31};
// 	
// 
// 	
// 	/* prompt user for date */
// 	printf ("Enter year: "); scanf ("%d",&year);
// 	printf ("Enter month: "); scanf ("%d",&month);
// 	
// 	// adjust for leap year
// 	if ( ((year % 4 == 0) && (year % 100 != 0))  || (year % 400 == 0)) {
// 		days_per_month[ 1] = 29;
// 	}
// 	std::cout << "GAIL = " << year % 4 << std::endl;
// 	/* get current timeinfo and modify it to the user's choice */
// 	time ( &rawtime );
// 	timeinfo = localtime ( &rawtime );
// 	timeinfo->tm_year = year - 1900;
// 	timeinfo->tm_mon = month - 1;
// 	timeinfo->tm_mday = 1;
// 	
// 	/* call mktime: timeinfo->tm_wday will be set */
// 	mktime ( timeinfo );
// 	
// 	printf ("That day is a %s.\n", weekday[timeinfo->tm_wday]);
// 	std::cout << "Days in this month = " << days_per_month[ month-1] << std::endl;
	
	return 0;
}// end main

