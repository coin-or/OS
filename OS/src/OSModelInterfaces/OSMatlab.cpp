/** @file TestOS.cpp
 * 
 * @author  Robert Fourer,  Jun Ma, Kipp Martin, 
 * @version 1.0, 10/05/2005
 * @since   OS1.0
 *
 * \remarks
 * Copyright (C) 2005, Robert Fourer, Jun Ma, Kipp Martin, Huanyuan Sheng
 * Northwestern University, and the University of Chicago.
 * All Rights Reserved.
 * This software is licensed under the Common Public License. 
 * Please see the accompanying LICENSE file in root directory for terms.
 * 
 */


#include <iostream>
#include <string>
#include<stdlib.h>
#include "OSMatlab.h"
using namespace std;
using std::cout;   
using std::endl;

 

OSMatlab::OSMatlab() {
  val1 = 0;
  val2 = 0;
}//end OSMatlab


OSMatlab::~OSMatlab() {
}//end OSMatlab

std::string OSMatlab::display() {
  //using CppAD::NearEqual;
  FileUtil *fileUtil = NULL;  
	DefaultSolver *m_Solver  = NULL;
 	std::string osilFileName;
	std::string ipOptFileName; 
	std::string nlFileName; 
	std::string lindoFileName;
	std::string cbcFileName;
	std::string mpsFileName;     
	std::string parserTestOSiLFileName;
	std::string osil;
    std::string dataDir;
  	std::string osol = "<osol></osoL>";
    double check; 
  	// get the input files
     const char dirsep =  CoinFindDirSeparator();
  	// Set directory containing mps data files.
    dataDir = dirsep == '/' ? "../data/" : "..\\data\\";
  bool ok;
  	try{
        ok = true;
		cbcFileName = dataDir + "parincLinear.osil";
		osil = fileUtil->getFileAsString( &cbcFileName[0]);
		m_Solver = new CoinSolver();
		m_Solver->m_sSolverName = "cbc";
		m_Solver->osil = osil;
		m_Solver->osol = osol;  
		m_Solver->osinstance = NULL;
		m_Solver->solve();
        std::string test = m_Solver->osrl;
		check = 7668;
		//ok &= NearEqual(getObjVal( m_Solver->osrl) , check,  1e-1 , 1e-1);
		//if(ok == false) throw ErrorClass(" Fail unit test with Cbc on parincLinear");
		//delete m_Solver;
		m_Solver = NULL;
		return m_Solver->osrl;
	}
	catch(const ErrorClass& eclass){
		//cout << "OSrL =  " <<  m_Solver->osrl <<  endl;
		return  m_Solver->osrl;
	}
	/*
    	try{
       lindoFileName = dataDir + "parincLinear.osil"; 
		osil = fileUtil->getFileAsString( &lindoFileName[0]);
		mexPrintf("Got file lindoapiaddins:\n");
		m_Solver = new LindoSolver();	
		m_Solver->osil = osil;
		m_Solver->osol = osol;
		m_Solver->osinstance = NULL;
		mexPrintf("Call the Lindo Solver:\n");
		m_Solver->solve();
        mexPrintf("Done solving in LIndo\n");
        std::string test = m_Solver->osrl;
        mexPrintf( &test[0]);
		m_Solver->osinstance = NULL;
		//delete m_Solver;
		m_Solver = NULL;
  
	}
	catch(const ErrorClass& eclass){
	}
	*/
  //end OS stuff
}//end display

void OSMatlab::set_data(double v1, double v2) { val1 = v1; val2 = v2; }
