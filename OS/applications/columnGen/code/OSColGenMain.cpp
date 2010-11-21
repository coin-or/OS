//===========================================================================//
//Id: OSColGenMain.cpp 3561 2010-06-24 19:27:07Z kmartin $
/** @file OSColGenMain.cpp
 * 
 * @author  Horand Gassmann, Jun Ma, Kipp Martin, 

 * 
 * \remarks
 * Copyright (C) 2010, Horand Gassmann, Jun Ma, Kipp Martin,
 * Northwestern University, Dalhousie University and the University of Chicago.
 * All Rights Reserved.
 * This software is licensed under the Common Public License. 
 * Please see the accompanying LICENSE file in root directory for terms.
 * */                                               //
//===========================================================================//


//===========================================================================//
#include "OSColGenApp.h"
#include "OSFileUtil.h" 
#include "CoinTime.hpp"


#ifdef HAVE_CTIME
# include <ctime>
#else
# ifdef HAVE_TIME_H
#  include <time.h>
# else
#  error "don't have header file for time"
# endif
#endif 
//===========================================================================//

//===========================================================================//
int main(int argc, char ** argv){
   try{
	   OSColGenApp *colgenApp;
	   OSOption *osoption = NULL;
	   OSoLReader *osolreader = NULL;
	   
	   FileUtil *fileUtil = NULL;
	   std::string osolFileName;
	   std::string osol;

	   //there should be 1 argument which is the option file
		if (argc > 2) {
			std::cout << "Too Many Input Parameters" << std::endl;
			return 1;
		}

		if (argc < 2) {
			std::cout << "usage: parsingtest <filename> " << std::endl;
			return 1;
		}
		
		
		// define the classes
		double cpuTime;
		double start = CoinCpuTime();
		fileUtil = new FileUtil();
		osolFileName = argv[1];
		osol = fileUtil->getFileAsString( osolFileName.c_str());
		
		// get the option object
		osolreader = new OSoLReader();
		osoption = osolreader->readOSoL( osol) ;
		
		
		//now create the column generation object
		colgenApp = new OSColGenApp( osoption);
		
		
		//now generate the restriced master
		colgenApp->getInitialRestrictedMaster2( );
		
		exit( 1);
		
		//now generate the restriced master
		colgenApp->getInitialRestrictedMaster( );
		//now solve the master
		colgenApp->solveRestrictedMasterRelaxation();
		
		//garbage collection
		delete fileUtil;
		delete osolreader;
		delete colgenApp;
		
		cpuTime = CoinCpuTime() - start;
		
		std::cout << "CPU TIME  " << cpuTime << std::endl;
   }
	catch(const ErrorClass& eclass){
		std::cout << "Something went wrong:" << std::endl;
		std::cout << eclass.errormsg << std::endl;
		
      return 1;
   }
   return 0;
}

