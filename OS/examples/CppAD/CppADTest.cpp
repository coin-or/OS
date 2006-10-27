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
 
 /* --------------------------------------------------------------------------
CppAD: C++ Algorithmic Differentiation: Copyright (C) 2003-06 Bradley M. Bell

CppAD is distributed under multiple licenses. This distribution is under
the terms of the 
                    Common Public License Version 1.0.

A copy of this license is included in the COPYING file of this distribution.
Please visit http://www.coin-or.org/CppAD/ for information on other licenses.
-------------------------------------------------------------------------- */
/*
$begin StackMachine.cpp$$
$spell
$$

$section Example Differentiating a Stack Machine Interpreter$$

$index interpreter, example$$
$index example, interpreter$$
$index test, interpreter$$

$code
$verbatim%Example/StackMachine.cpp%0%// BEGIN PROGRAM%// END PROGRAM%1%$$
$$

$end
*/
// BEGIN PROGRAM

# include <cstddef>
# include <cstdlib>
# include <cctype>
# include <cassert>
# include <stack>

# include <CppAD/CppAD.h>

#include<iostream>
#include "OSInstance.h"
#include "OSiLWriter.h"
#include "OSParameters.h"
#include "OSStackMachine.h"
#include "OSnLNode.h"
#include "ErrorClass.h"
#include "FileUtil.h"  
#include "OSiLReader.h"
#include "OSInstance.h"
#include "OSExpressionTree.h"
#include "OSnLNode.h"
//#include "CoinHelperFunctions.hpp"
#include <vector>  
#include <map> 
#include <string>
 

//using std::cout;
//using std::endl;
int  main(){	
	using std::string;
	using std::stack;
	using std::cout;
	using std::endl;
	using CppAD::AD;
	using CppAD::NearEqual;
	using CppAD::vector;
	using OSAD::StackMachine;
	std::cout.precision(12);
	//
	// get the problem data
	//
 	FileUtil *fileUtil = NULL; 
	std::string osilFileName;
	std::string osil;
	// get the input files
	// dirsep in later
	// const char dirsep =  CoinFindDirSeparator();
  	// Set directory containing mps data files.
  	std::string dataDir;
    dataDir = "../../data/" ;
	osilFileName =  dataDir + "CppADTestLag.osil";
	fileUtil = new FileUtil();
	osil = fileUtil->getFileAsString( &osilFileName[0]);	
	//
	// parse the file and create an OSInstance object
	OSiLReader *osilreader = NULL;
	OSInstance *osinstance = NULL;
	OSExpressionTree *expTree = NULL;
	OSnLNode *nlNode = NULL; 
	// create reader and generate the OSInstance object
	try{
		osilreader = new OSiLReader();
		osinstance = osilreader->readOSiL( &osil);
		// get the nodes for an expression tree in postfix format
		// in this case we get the nonlinear objective function term
		//expTree = osinstance->getNonlinearExpressionTree( -1);
		expTree = osinstance->getNonlinearExpressionTree( -1);
		nlNode = expTree->m_treeRoot;
		double *zz;
		double functionValue;
		zz = new double[3];
		zz[ 0] = 0.5;
		zz[ 1] = 1000;
		zz[2] = 1;
		/*functionValue = expTree->calculateFunction(&zz[0], false);
		std::cout << "FUNCTION VALUE = " << functionValue << std::endl ;
		std::cout << "GET SPARSE JACOBIAN RESULT"   << std::endl;
		expTree->calculateGradient(&zz[0], true );
		// now get Hessian information
		std::vector<SecondPartialStruct*> secondPartialVector;
		struct SecondPartialStruct *secondPartial;
		secondPartialVector = expTree->calculateHessian(&zz[0], true);
		int kj;
		int numSparseVars = secondPartialVector.size();
		for(kj = 0; kj < numSparseVars; kj++){
			secondPartial = secondPartialVector[kj];
			std::cout << "First index = " << secondPartial->index_i << std::endl;
			std::cout << "Second index = " << secondPartial->index_j << std::endl;
			std::cout << "Second partial  = " << secondPartial->secondPartial_ij << std::endl;
		}
		//
		 * 
		 * */
		double *conVals = osinstance->calculateAllConstraintFunctionValues( &zz[0], false);

		double *objVals = osinstance->calculateAllObjectiveFunctionValues( &zz[0], false);
		int idx;
		for( idx = 0; idx < osinstance->getConstraintNumber(); idx++){
			//std::cout << "CONSTRAINT FUNCTION VALUE WITH TERM= " << osinstance->calculateFunctionValue(idx, zz, false) << std::endl;
			std::cout << "CONSTRAINT FUNCTION VALUE WITH TERM= " << *(conVals + idx) << std::endl;
		}
		for( idx = 0; idx < osinstance->getObjectiveNumber(); idx++){
			//std::cout << "OBJECTIVE FUNCTION VALUE WITH TERM= " << osinstance->calculateFunctionValue(idx, zz, false) << std::endl;
			std::cout << "OBJECTIVE FUNCTION VALUE WITH TERM= " << *(objVals + idx) << std::endl;
		}
		osinstance->calculateObjectiveFunctionGradient(-1, &zz[0], false, false);
		osinstance->calculateAllConstraintFunctionGradients(&zz[0], false, false);
		std::cout << "RETURN FROM GETTING SPARSE JACOBIAN RESULT"   << std::endl;
		std::cout << "NOW GET LAGRANGIAN HESSIAN"   << std::endl;
		osinstance->calculateLagrangianHessian( &zz[0], &zz[0], &zz[0], false, false);
		//osinstance->getHessianOfLagrangianNonz( expTree);
		delete[] zz;
		zz = NULL;
		delete osilreader;
		osilreader = NULL;
		std::cout << "OSILREADER DELETED" << std::endl;
	}
	catch(const ErrorClass& eclass){
	std::cout << eclass.errormsg << std::endl;
	} 	
	
	std::cout << "BRAD's EXAMPLE" << std::endl;
	CppAD::AD<double> Lagragian( const CppADvector< CppAD::AD<double> > &xyz );
	
	// double values corresponding to XYZ vector
	double x0, x1, x2, y0, y1, z;
	y0 = 1.;
	y1 = 1;
	z = 1.;
	// domain space vector
	size_t n = 3;
	CppADvector< AD<double> >  XYZ(n);
	XYZ[0] = x0 = 0.5;
	XYZ[1] = x1 = 1000.;
	XYZ[2] = x2 = 1.0;

	// declare X as independent variable vector and start recording
	CppAD::Independent(XYZ);

	// Add the Lagragian multipliers to XYZ
	XYZ.push_back(y0);
	XYZ.push_back(y1);
	XYZ.push_back(z);

	// range space vector
	size_t m = 1;
	CppADvector< AD<double> >  L(m);
	L[0] = Lagragian(XYZ);

	// create F: X -> L and stop tape recording
	CppAD::ADFun<double> F;
	F.Dependent(L);

	// independent variable vector
	CppADvector<double> x(n);
	x[0] = x0;
	x[1] = x1;
	x[2] = x2;
	std::cout << "L[0] = " << L[0] << std::endl;
	// second derivative of L[0] 
	CppADvector<double> hess( n * n );
	hess = F.Hessian(x, 0);
	std::cout << "second derivative " << hess[0] << std::endl;
	std::cout << "second derivative " << hess[1] << std::endl;
	std::cout << "second derivative " << hess[2] << std::endl;
	std::cout << "second derivative " << hess[3] << std::endl;
	std::cout << "second derivative " << hess[4] << std::endl;
	std::cout << "second derivative " << hess[5] << std::endl;
	std::cout << "second derivative " << hess[6] << std::endl;
	std::cout << "second derivative " << hess[7] << std::endl;
	std::cout << "second derivative " << hess[8] << std::endl;
				
	std::cout << std::endl;
	return 0;
}//end main

CppAD::AD<double> Lagragian(
	const CppADvector< CppAD::AD<double> > &xyz )
{	using CppAD::AD;

	assert( xyz.size() == 6 );
	AD<double> x0 = xyz[0];
	AD<double> x1 = xyz[1];
	AD<double> x2 = xyz[2];
	AD<double> y0 = xyz[3];
	AD<double> y1 = xyz[4];
	AD<double> z  = xyz[5];

	// compute objective function
	AD<double> f = x0 * x0;

	// compute constraint functions
	AD<double> h0 = 1. + 2.*x1 + 3.*x2;
	AD<double> h1 = log( x0 * x2 );

	// compute the Lagragian
	AD<double> L = y0 * h0 + y1 * h1 + z * f;
	std::cout << "Lagrangian in subroutine = " << xyz[ 1] << std::endl;
	std::cout << "Lagrangian in subroutine = " << x0 << std::endl;
	return L;

}

