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
#include <sstream>
#include <string>
#include<stdlib.h>
#include "OSMatlab.h"

  

using std::cout;
using std::endl;
using std::ostringstream; 


 

OSMatlab::OSMatlab() {
	sparseMat = NULL;
}//end OSMatlab


OSMatlab::~OSMatlab() {
	
}//end ~OSMatlab

std::string OSMatlab::display() {
	ostringstream outStr;
	int i;
	outStr << "Start input of Sparse Matrix" << endl;
	if(sparseMat != NULL){
		for(i = 0 ; i < sparseMat->valueSize; i++){
			outStr << sparseMat->values[ i] << endl;	
		}
	}
	outStr << "Finish input of Sparse Matrix" << endl;
	return outStr.str();
  //using CppAD::NearEqual;
  /*
  FileUtil *fileUtil = NULL;  
	DefaultSolver *m_Solver  = NULL;
	std::string cbcFileName;
	std::string osil;
    std::string dataDir;
  	std::string osol = "<osol></osoL>";
  	// get the input files
     const char dirsep =  CoinFindDirSeparator();
  	// Set directory containing mps data files.
    dataDir = dirsep == '/' ? "../data/" : "..\\data\\";
  	try{
        std::string test = "";
		cbcFileName = dataDir + "parincLinear.osil";
		osil = fileUtil->getFileAsString( &cbcFileName[0]);
		m_Solver = new CoinSolver();
		m_Solver->m_sSolverName = "cbc";
		m_Solver->osil = osil;
		m_Solver->osol = osol;  
		m_Solver->osinstance = NULL;
		m_Solver->solve();
        test = m_Solver->osrl;
       // delete m_Solver;
		m_Solver = NULL;
		return test;
	}
	catch(const ErrorClass& eclass){
		//cout << "OSrL =  " <<  m_Solver->osrl <<  endl;
		return  m_Solver->osrl;
		*/
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

std::string OSMatlab::wierdtest() {
	return "this is weird";
}
