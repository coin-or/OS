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
 
 
#include <cppad/cppad.hpp> 
#include "OSResult.h" 
#include "OSiLReader.h"        
#include "OSiLWriter.h" 
#include "OSrLReader.h"        
#include "OSrLWriter.h"      
#include "OSInstance.h"  
#include "FileUtil.h"  
#include "OSConfig.h" 
#include "CoinSolver.h"
#include "DefaultSolver.h"  
#include "WSUtil.h" 
#include "OSSolverAgent.h"   
#include "OShL.h"     
#include "ErrorClass.h"
#include "OSmps2osil.h"   
#include "Base64.h"
#include "CommonUtil.h"

#ifdef COIN_HAS_KNITRO    
#include "KnitroSolver.h"
#endif 



#ifdef COIN_HAS_ASL
#include "OSnl2osil.h"
#endif
#ifdef COIN_HAS_LINDO    
#include "LindoSolver.h"
#endif  
#ifdef COIN_HAS_IPOPT    
#include "IpoptSolver.h"
#endif 


#include <string>
#include <time.h>


using std::cout;   
using std::endl;
using std::ostringstream; 

int main(int argC, char* argV[])
{
	

	FileUtil *fileUtil = NULL;  
	OSInstance *osinstance = NULL;
	// end classes    
	std::string osilFileName;    
	std::string osil;
	// get the input files
	 const char dirsep =  CoinFindDirSeparator();
  	// Set directory containing mps data files.
  	std::string dataDir;
    dataDir = dirsep == '/' ? "../../data/" : "..\\..\\data\\";
	fileUtil = new FileUtil();

	try{
		cout << "Hello World" << endl;
		//put in test code for OS project
		OSiLReader *osilreader = NULL;
		osilreader = new OSiLReader(); 
		std::cout << "GET FILE AS STRING" << std::endl;
		osilFileName =  dataDir + "callBackTest.osil";
		osil = fileUtil->getFileAsString( &osilFileName[0]);
		std::cout << "GET INSTANCE" << std::endl;
		osinstance = osilreader->readOSiL( &osil);
		std::cout << "WE HAVE THE INSTANCE, GET THE ROW INDEXES" << std::endl;
		int *qRowIndexes = osinstance->getQuadraticRowIndexes();
		int i = 0;
		int n = osinstance->getNumberOfQuadraticRowIndexes();
		for(i = 0; i <  n; i++){
			std::cout << "quadratic row index = " << qRowIndexes[ i] << std::endl;
		}
		
		
		
		int *expTreeIndexes = osinstance->getNonlinearExpressionTreeIndexes();
		n = osinstance->getNumberOfNonlinearExpressionTreeIndexes();
		for(i = 0; i <  n; i++){
			std::cout << "exp tree index = " << expTreeIndexes[ i] << std::endl;
		}
	
		
//		
//		int *expTreeModIndexes = osinstance->getNonlinearExpressionTreeModIndexes();
//		n = osinstance->getNumberOfNonlinearExpressionTreeModIndexes();
//		for(i = 0; i <  n; i++){
//			std::cout << "exp tree mod index  = " << expTreeModIndexes[ i] << std::endl;
//		}
//	
		


		std::vector<OSnLNode*>  postfixVec ;
		postfixVec = osinstance->getNonlinearExpressionTreeInPrefix( 4);
		n = postfixVec.size();
		std::cout <<  "NUMBER OF TERMS =  " << n << std::endl;
		std::cout << std::endl << std::endl;
		for (i = 0 ; i < n; i++){
			std::cout << postfixVec[i]->snodeName << std::endl;
			
		}
		
		postfixVec = osinstance->getNonlinearExpressionTreeModInPrefix( 4);
		n = postfixVec.size();
		std::cout <<  "NUMBER OF TERMS =  " << n << std::endl;
		std::cout << std::endl << std::endl;
		for (i = 0 ; i < n; i++){
			std::cout << postfixVec[i]->snodeName << std::endl;
			
		}
		
		delete osilreader;	
		
		std::cout << "OSINSTANCE DELETED " << std::endl;

		return 0;
	}
	catch( const ErrorClass& eclass){
		std::cout << eclass.errormsg <<  std::endl;
		return 0;
	}
}// end main
	///	

	

