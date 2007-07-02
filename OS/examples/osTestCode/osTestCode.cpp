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
			bool ret = true;
    OsiVolSolverInterface *s;
    s = new OsiVolSolverInterface();
	double inf = s->getInfinity();

	CoinPackedMatrix m;

	m.transpose();

	CoinPackedVector r0;
	r0.insert(0, 1);
	r0.insert(1, 0);
	m.appendRow(r0);

	CoinPackedVector r1;
	r1.insert(0, 0);
	r1.insert(1, 1);
	m.appendRow(r1);

	int numcol = 2;

	double *obj = new double[numcol];
	obj[0] = 3;
	obj[1] = 4;

	double *collb = new double[numcol];
	collb[0] = -1000;
	collb[1] = -1000;

	double *colub = new double[numcol];
	colub[0] = 1000;
	colub[1] = 1000;

	int numrow = 2;

	double *rowlb = new double[numrow];
	rowlb[0] = 1;
	rowlb[1] = 1;

	double *rowub = new double[numrow];
	rowub[0] = 1;
	rowub[1] = 1;

	s->loadProblem(m, collb, colub, obj, rowlb, rowub);

	delete [] obj;
	delete [] collb;
	delete [] colub;

	delete [] rowlb;
	delete [] rowub;

	s->setObjSense(-1);

	s->initialSolve();

//	ret = ret && s->isProvenOptimal();
//	ret = ret && !s->isProvenPrimalInfeasible();
//	ret = ret && !s->isProvenDualInfeasible();
//
//	const double solution1[] = {5, 0};
//	ret = ret && equivalentVectors(s,s,0.0001, s->getColSolution(), solution1, 2);
//
//	const double activity1[] = {10, 5};
//	ret = ret && equivalentVectors(s,s,0.0001, s->getRowActivity(), activity1, 2);
//
//	s->setObjCoeff(0, 1);
//	s->setObjCoeff(1, 1);
//
//	s->resolve();
//
//	ret = ret && s->isProvenOptimal();
//	ret = ret && !s->isProvenPrimalInfeasible();
//	ret = ret && !s->isProvenDualInfeasible();
//
//	const double solution2[] = {3, 4};
//	ret = ret && equivalentVectors(s,s,0.0001, s->getColSolution(), solution2, 2);
//
//	const double activity2[] = {10, 15};
//	ret = ret && equivalentVectors(s,s,0.0001, s->getRowActivity(), activity2, 2);
//
//	return ret;
		return 0;
	}
	catch( CoinError e){
		std::cout << e.message() <<  std::endl;
		return 0;
	}
}// end main
	///	

	

