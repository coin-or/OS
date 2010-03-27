/* $Id$ */
/** @file osTestCode.cpp
 * 
 * @author  Horand Gassmann, Jun Ma, Kipp Martin, 
 * @version 1.0, 10/05/2005
 * @since   OS1.0
 *
 * \remarks
 * Copyright (C) 2005, Horand Gassmann, Jun Ma, Kipp Martin,
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

#ifdef HAVE_CTIME
# include <ctime>
#else
# ifdef HAVE_TIME_H
#  include <time.h>
# else
#  error "don't have header file for time"
# endif
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
    
    // temporary experimentation by Kipp 
	std::cout << "Hello World" << std::endl;
	FileUtil *fileUtil = NULL; 
	fileUtil = new FileUtil();
    std::cout << std::endl << std::endl;
    size_t i;
    size_t numberOfNonlinearExpressions;
	numberOfNonlinearExpressions = 1000000;
	/** nlarray is pointer to an array of Nl
	 * object pointers */	
    Nl **nlarray;
    nlarray = new Nl*[ numberOfNonlinearExpressions ];
  	 OSnLNodeNumber *nlNodeNumberPoint;  

    std::vector<Nl*> nlVec;
    std::cout << "Start Loop "  << std::endl;
    for(i = 0; i < numberOfNonlinearExpressions ; i++){
        	nlarray[ i] = new Nl();
        	nlarray[i]->idx = i;
    		nlarray[ i]->osExpressionTree = new OSExpressionTree();
        	nlNodeNumberPoint = new OSnLNodeNumber(); 
        	nlNodeNumberPoint->value = 77.77;
			nlarray[ i]->osExpressionTree->m_treeRoot = nlNodeNumberPoint;
       	nlVec.push_back( nlarray[ i]) ;
        
    }
    
    std::cout << "End Loop" << std::endl; 

/*
	OSnLNodeNumber *nlNodeNumberPoint;
  	std::vector<OSnLNodeNumber*> nlNodeVec;
	std::cout << "Start OSnLNumberNode loop" << std::endl;
   for(int i = 0; i <10000; i++){
        nlNodeNumberPoint = new OSnLNodeNumber(); 
        nlNodeNumberPoint->value = 77.77;
        new Nl();
    	nlNodeVec.push_back( nlNodeNumberPoint);
    }
	std::cout << "Finish OSnLNumberNode loop" << std::endl;
 */
	//garbage collection   
  
	for(i = 0; i < numberOfNonlinearExpressions; i++){
		delete nlarray[i];
		nlarray[i] = NULL;
	} 
	delete[] nlarray;
	nlarray = NULL;
    
    delete fileUtil;
    
	return 0;    
    
//	OSnl2osil *nl2osil = NULL;
//	try {
       
//        double cpuTime;
//        cpuTime = CoinCpuTime();
        //get the size of the nl string
        //std::string nlstring = fileUtil->getFileAsString("../../../../OS/data/amplFiles/blpmpec1.nl");
//         std::string nlstring = fileUtil->getFileAsString("smalltest.nl");
//         std::cout << "nl string size = " << nlstring.size() << std::endl;
//         std::cout  << "start the process " << std::endl;
// 		//nl2osil = new OSnl2osil( "../../../../OS/data/amplFiles/BLPMPEC.nl"); 
//         nl2osil = new OSnl2osil( "smalltest.nl"); 
//         std::cout  << "nl file read " << std::endl;
//         cpuTime = CoinCpuTime() - cpuTime;
//         std::cout  << "Time to read nl file: " <<   cpuTime  << std::endl;
//         nl2osil->createOSInstance() ;
//         std::cout << "Number Variable = " << nl2osil->osinstance->getVariableNumber() << std::endl;
//         std::cout << "Number Constraints = " << nl2osil->osinstance->getConstraintNumber() << std::endl;
//       
// 
//         std::cout  << "an osinstance created " << std::endl;
//         cpuTime = CoinCpuTime() - cpuTime;
//         std::cout  << "Time to create osinstance : " <<   cpuTime  << std::endl;
//         
//         std::cout << "Initialize Nonlinear Structures" << std::endl;
// 		nl2osil->osinstance->initForAlgDiff( );  
//         cpuTime = CoinCpuTime() - cpuTime;
//         std::cout  << "Time to initialize Nonlinear Structures : " <<   cpuTime  << std::endl;
        
        
//         std::cout << "Get Sparse Jacobian" << std::endl;
//         SparseJacobianMatrix *sparseJac;
// 		sparseJac = nl2osil->osinstance->getJacobianSparsityPattern();
//         cpuTime = CoinCpuTime() - cpuTime;
//         std::cout  << "Time to get Sparse Jacobian pattern : " <<   cpuTime  << std::endl;
//         
//         SparseHessianMatrix *sparseHessian = nl2osil->osinstance->getLagrangianHessianSparsityPattern();
//         cpuTime = CoinCpuTime() - cpuTime;
//        std::cout  << "Time to get Sparse Hessain pattern : " <<   cpuTime  << std::endl;
//         OSiLWriter *osilwriter = NULL;
// 		osilwriter = new OSiLWriter();
// 		std::string osil;
// 		osil = osilwriter->writeOSiL(  nl2osil->osinstance) ;
//         std::cout << "osil generated" << std::endl;
//         cpuTime = CoinCpuTime() - cpuTime;
//         std::cout  << "Time to create osil : " <<   cpuTime  << std::endl;
//         std::cout  << "Size of osil string : " <<   osil.size()  << std::endl;
        //fileUtil->writeFileFromString("tmp.osil", osil);
// 		delete nl2osil;
//         std::cout  << "nl2osil deleted " << std::endl;
//         cpuTime = CoinCpuTime() - cpuTime;
//         std::cout  << "Time to delete nl2osil : " <<   cpuTime  << std::endl;
//         delete fileUtil;
       // delete osilwriter;

//	}
//	catch(const ErrorClass& eclass){
//        std::cout << "THERE WAS AN ERROR" <<  std::endl;
//		delete fileUtil;
//		delete nl2osil;
//        std::cout << "THERE WAS AN ERROR" <<  std::endl;
//		std::cout << eclass.errormsg <<  std::endl;
//		return 0;
//	} 

	

	
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
	
}// end main

