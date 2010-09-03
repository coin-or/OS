//===========================================================================//
// This file is part of the Decomp Solver Framework.                         //
//                                                                           //
// Decomp is distributed under the Common Public License as part of the      //
// COIN-OR repository (http://www.coin-or.org).                              //
//                                                                           //
// Author: Matthew Galati, Lehigh University   
// Modified by Kipp Martin
//
//                                                                           //
// Copyright (C) 2002-2009, Lehigh University, Matthew Galati, and Ted Ralphs//
// All Rights Reserved.                                                      //
//===========================================================================//

//===========================================================================//
#include "UtilParameters.h"
//===========================================================================//
#include "OSDipApp.h"
//===========================================================================//
#include "AlpsDecompModel.h"
//===========================================================================//
#include "DecompAlgoC.h"
#include "DecompAlgoPC.h"
#include "DecompAlgoRC.h"
//===========================================================================//
#include "UtilTimer.h"
#include<map>

//===========================================================================//
int main(int argc, char ** argv){
   try{

      //---
      //--- create the utility class for parsing parameters
      //---
      UtilParameters utilParam(argc, argv);  

      bool doCut          = utilParam.GetSetting("doCut",          false);
      bool doPriceCut     = utilParam.GetSetting("doPriceCut",     true);
      bool doDirect       = utilParam.GetSetting("doDirect",       false);

   
      UtilTimer timer;
      double    timeSetupReal = 0.0;
      double    timeSetupCpu  = 0.0;
      double    timeSolveReal = 0.0;
      double    timeSolveCpu  = 0.0;
   
      //---
      //--- start overall timer
      //---
      timer.start();
      
      //---
      //--- create the user application (a DecompApp)
      //---  
      
      OSDipApp osdip( utilParam); 
      
      //return 0;
      
     
      //---
      //--- create the algorithm (a DecompAlgo)
      //---
      DecompAlgo *algo = NULL;
      assert(doCut + doPriceCut == 1);

      //---
      //--- create the CPM algorithm object
      //---      
      if(doCut)
         algo = new DecompAlgoC(&osdip, &utilParam);
   
      //---
      //--- create the PC algorithm object
      //---
      if(doPriceCut){
         algo = new DecompAlgoPC(&osdip, &utilParam);

      }
   
      if(doCut && doDirect){
         timer.stop();
         timeSetupCpu  = timer.getCpuTime();
         timeSetupReal = timer.getRealTime();
      
         //---
         //--- solve
         //---
         timer.start();      
        // algo->solveDirect(timeLimit);
         algo->solveDirect();
         timer.stop();
         timeSolveCpu  = timer.getCpuTime();
         timeSolveReal = timer.getRealTime();
      }
      else{
         timer.stop();
         timeSetupCpu  = timer.getCpuTime();
         timeSetupReal = timer.getRealTime();
      
         //---
         //--- create the driver AlpsDecomp model
         //---
         int             status = 0;
         AlpsDecompModel alpsModel(utilParam, algo);
      
         //---
         //--- solve
         //---
         timer.start();     
         std::cout << "START SOLVE" << std::endl;
         status = alpsModel.solve();
         std::cout << "FINISH SOLVE" << std::endl;
         timer.stop();
         timeSolveCpu  = timer.getCpuTime();
         timeSolveReal = timer.getRealTime();
         
         //---
         //--- sanity check
         //---
         cout << setiosflags(ios::fixed|ios::showpoint);
         cout << "Status= " << status 
              << " BestLB= " << setw(10) 
              << UtilDblToStr(alpsModel.getGlobalLB(),5)
              << " BestUB= " << setw(10)
              << UtilDblToStr(alpsModel.getGlobalUB(),5)        
              << " Nodes= " << setw(6) 
              << alpsModel.getNumNodesProcessed()
              << " SetupCPU= "  << timeSetupCpu
              << " SolveCPU= "  << timeSolveCpu 
              << " TotalCPU= "  << timeSetupCpu + timeSolveCpu
              << " SetupReal= " << timeSetupReal
              << " SetupReal= " << timeSolveReal
              << " TotalReal= " << timeSetupReal + timeSetupReal
              << endl;  
         
         
         const DecompSolution * solution = alpsModel.getBestSolution();
         cout << "Optimal Solution" << endl;
         solution->print();
         //print final solution
         algo->getMasterOSI()->writeLp("finalRestrictedMaster", "lp", 1e-30, 5, 10);
      
      }	 
      //---
      //--- free local memory
      //---
      delete algo;

   }
	catch(const ErrorClass& eclass){
		std::cout << "Something went wrong:" << std::endl;
		std::cout << eclass.errormsg << std::endl;
		
      return 1;
   }
   return 0;
}

