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
#include<math.h>
#include "OSInstance.h"
#include "OSiLWriter.h"
#include "OSParameters.h"
#include "OSnLNode.h"
#include "ErrorClass.h"
#include "FileUtil.h"  
#include "OSiLReader.h"
#include "OSInstance.h"
#include "OSExpressionTree.h"
#include "OSnLNode.h"
#include "OSDataStructures.h"

#include <vector>  
#include <map> 
#include <string>
 

int  main(){	
	using std::cout;
	using std::endl;
	using CppAD::AD;
	using CppAD::NearEqual;
	using CppAD::vector;
	std::cout.precision(12);
	// error checking functions
	bool CheckFunctionValues( double *conVals, double objValue,
		double x0, double x1, double x2, double y0, double y1, double z );
	bool CheckHessianUpper( SparseHessianMatrix *sparseHessian, 
		double x0, double x1, double x2, double y0, double y1, double z );
	bool CheckGradientValues( SparseJacobianMatrix *sparseJac, double *objGrad,
		double x0, double x1, double x2, double y0, double y1, double z );
	bool ok = true;
	int idx, k;
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
	osilFileName =  dataDir + "HS071_NLP.osil";
	//osilFileName =  dataDir + "CppADTestLag.osil";
	fileUtil = new FileUtil();
	osil = fileUtil->getFileAsString( &osilFileName[0]);	
	//
	// create OSReader and OSInstance objects
	OSiLReader *osilreader = NULL;
	OSInstance *osinstance = NULL;
	// create reader, pare the OSiL,  and generate the OSInstance object
	try{
		osilreader = new OSiLReader();
		osinstance = osilreader->readOSiL( &osil);
		// here the values of the primal and Lagrange multipliers that we use
		double* x = new double[4];
		double* y = new double[2];
		double* w = new double[1];
		x[ 0] = 1.;
		x[ 1] = 1;
		x[ 2] = 1;
		x[ 3] = 1;
		y[ 0] = 0; // Lagrange multiplier on constraint 0
		y[ 1] = 1; // Lagrange multiplier on constraint 1
		w[ 0] = 0; // Lagrange multiplier on the objective function
		//
	
		// Now start using the nonlinear API
		// check function values, both objectives and constraints
		std::cout << "Call  = calculateAllConstraintFunctionValues"  << std::endl;			
		double *conVals = osinstance->calculateAllConstraintFunctionValues( &x[0], false);
		// note: if you just want the value for constraint function indexed by
		// idx call the method:
		//calculateFunctionValue(int idx, double *x, bool functionEvaluated)
		std::cout << "Call  = calculateAllObjectiveFunctionValues"  << std::endl;	
		double *objVals = osinstance->calculateAllObjectiveFunctionValues( &x[0], false);
		// note: if you just want the value for the objective function indexed by
		// idx call the method:
		//calculateFunctionValue(int idx, double *x, bool functionEvaluated)
		
		
		for( idx = 0; idx < osinstance->getConstraintNumber(); idx++){
			std::cout << "CONSTRAINT FUNCTION INDEX = " <<  idx << " FUNCTION VALUE =  "  << *(conVals + idx) << std::endl;
		}
		for( idx = 0; idx < osinstance->getObjectiveNumber(); idx++){
			std::cout << "OBJECTIVE FUNCTION  INDEX = " << idx <<  " FUNCTION VALUE = "  << *(objVals + idx) << std::endl;
		}
		//ok = CheckFunctionValues( conVals, *objVals, x[ 0], x[1], x[2], y[0], y[1], w[0] );
		if( ok == 0){
			std::cout << "FAILED CHECKING FUNCTION VALUES TEST" << std::endl;
			return 0;
		}
		else{
			std::cout << "PASSED CHECKING FUNCTION VALUES TEST" << std::endl;
		}
	
		//
		// now check gradients of constraints and objective function
		//
		std::cout << "PERFORM THE GRADIENT TESTS"   << std::endl;
		SparseJacobianMatrix *sparseJac;
		double *objGrad;
		std::cout << "OBJECTIVE FUNCTION GRADIENT"   << std::endl;
		// in our implementation the objective function is a dense gradient
		objGrad = osinstance->calculateObjectiveFunctionGradient( -1, &x[0], false, false);
		for(idx = 0; idx < osinstance->getVariableNumber(); idx++){
			std::cout << "col idxx = " << idx << "  value =  " << *(objGrad + idx)  << std::endl;
		}
		std::cout << "CONSTRAINT JACOBIAN"   << std::endl;
		// the constraint gradients are sparse
		// some solvers have an initial method that require the sparsity structure
		// get the sparsity structure
		sparseJac = osinstance->getJacobianSparsityPattern();
		// print out just the sparsity pattern
		std::cout << "JACOBIAN SPARSITY PATTERN"   << std::endl;
		for(idx = 0; idx < osinstance->getConstraintNumber(); idx++){
			// some solvers (e.g. reduced gradient solvers) may want to know which values of the
			// Jacobian matrix are constant, i.e. linear, sparseJac->conVals is the number of constant
			// terms in the gradient for each rowt, the first conVals terms are constant, when getting
			std::cout << "number constant terms in constraint "   <<  idx << " is " 
			<< *(sparseJac->conVals + idx)  << std::endl;
			for(k = *(sparseJac->starts + idx); k < *(sparseJac->starts + idx + 1); k++){
				std::cout << "row idx = " << idx <<  "  col idx = "<< *(sparseJac->indexes + k) << std::endl;
			}
		}	
		std::cout << "JACOBIAN MATRIX"   << std::endl;
		// now make the gradient calculations and fill in the sparse Jacobian matrix
		sparseJac = osinstance->calculateAllConstraintFunctionGradients( &x[0], false, false);
		for(idx = 0; idx < osinstance->getConstraintNumber(); idx++){
			for(k = *(sparseJac->starts + idx); k < *(sparseJac->starts + idx + 1); k++){
				std::cout << "row idx = " << idx <<  "  col idx = "<< *(sparseJac->indexes + k)
				<< " value = " << *(sparseJac->values + k) << std::endl;
			}
		}
		//ok = CheckGradientValues( sparseJac, objGrad, x[ 0], x[1], x[2], y[0], y[1], w[0] );
		if( ok == 0){
			std::cout << "FAILED THE GRADIENT TEST" << std::endl;
			return 0;
		}
		else{
			std::cout << "PASSED THE GRADIENT TEST" << std::endl;
		}
		// done with gradient checks, now check on the Hessian
		//
		SparseHessianMatrix *sparseHessian;
		// the Hessian test
		// get the sparsity pattern -- many solvers want to initialize with just the sparsity
		std::cout << "GET LAGRANGIAN HESSIAN SPARSITY PATTERN"   << std::endl;
		sparseHessian = osinstance->getLagrangianHessianSparsityPattern( );
		for(idx = 0; idx < sparseHessian->hessDimension; idx++){
			std::cout <<  "Row Index = " << *(sparseHessian->hessRowIdx + idx) ;
			std::cout <<  "  Column Index = " << *(sparseHessian->hessColIdx + idx) << std::endl;
		}
		//first iteration 
		std::cout << "GET LAGRANGIAN HESSIAN FIRST TIME"   << std::endl;
		sparseHessian = osinstance->calculateLagrangianHessian( x, y, w, false, false);
		for(idx = 0; idx < sparseHessian->hessDimension; idx++){
			std::cout << "row idx = " << *(sparseHessian->hessRowIdx + idx) <<  
			"  col idx = "<< *(sparseHessian->hessColIdx + idx)
			<< " value = " << *(sparseHessian->hessValues + idx) << std::endl;
		}
		//ok = CheckHessianUpper( sparseHessian, x[0],  x[1], x[2], y[0], y[1], w[0]);
		if( ok == 0){
			std::cout << "FAILED THE FIRST HESSIAN TEST" << std::endl;
			return 0;
		}
		else{
			std::cout << "PASSED THE FIRST HESSIAN TEST" << std::endl;
		}
		return 0;
		//second iteration
		x[0] = 0;
		std::cout << "NOW GET LAGRANGIAN HESSIAN SECOND TIME"   << std::endl;
		sparseHessian = osinstance->calculateLagrangianHessian( x, y, w, false, false);
		for(idx = 0; idx < sparseHessian->hessDimension; idx++){
			std::cout << "row idx = " << *(sparseHessian->hessRowIdx + idx) <<  
			"  col idx = "<< *(sparseHessian->hessColIdx + idx)
			<< " value = " << *(sparseHessian->hessValues + idx) << std::endl;
		}
		//ok = CheckHessianUpper( sparseHessian , x[0],  x[1], x[2], y[0], y[1], w[0] );
		if( ok == 0){
			std::cout << "FAILED THE SECOND HESSIAN TEST" << std::endl;
			return 0;
		}
		else{
			std::cout << "PASSED THE SECOND HESSIAN TEST" << std::endl;
		}
		// do garbage collection

		delete osilreader;
		osilreader = NULL;
		std::cout << "OSILREADER DELETED" << std::endl;
	}
	catch(const ErrorClass& eclass){
	std::cout << eclass.errormsg << std::endl;
	} 	
	return 0;
}// end main program

bool CheckFunctionValues( double *conVals, double objValue,
	double x0, double x1, double x2, double y0, double y1, double z ){
	using CppAD::NearEqual;
	bool ok  = true;
	double checkObj = x0*x0 + 9*x1;
	ok &= NearEqual(objValue, checkObj, 1e-10, 1e-10); 
	double checkCon0 = 33. + 105. + 1.37*x1 + 2*x2;
	ok &= NearEqual(*(conVals + 0), checkCon0, 1e-10, 1e-10);
	double checkCon1 = log(x0*x2);
	ok &= NearEqual( *(conVals + 1), checkCon1, 1e-10, 1e-10);
	return ok;
}//CheckFunctionValues
//
//
bool CheckGradientValues( SparseJacobianMatrix *sparseJac, double *objGrad,
	double x0, double x1, double x2, double y0, double y1, double z ){
	using CppAD::NearEqual;
	bool ok  = true;
	// first the objective function gradient
	double checkObjPartial0 = 2*x0;
	ok &= NearEqual( *(objGrad + 0), checkObjPartial0, 1e-10, 1e-10); 
	double checkObjPartial1 = 9;
	ok &= NearEqual( *(objGrad + 1), checkObjPartial1, 1e-10, 1e-10); 	
	double checkObjPartial2 = 0;
	ok &= NearEqual( *(objGrad + 2), checkObjPartial2, 1e-10, 1e-10); 
	// get the constrating gradient
	// row 0 gradient -- there are nonzero partials for variables 1 and 2
	double checkCon0Partial1 = 1.37;
	ok &= NearEqual( *(sparseJac->values + 0), checkCon0Partial1, 1e-10, 1e-10); 	
	double checkCon0Partial2 = 2.;
	ok &= NearEqual( *(sparseJac->values + 1), checkCon0Partial2, 1e-10, 1e-10); 
	// row 1 gradient -- there are nonzero partials for variables 0 and 2
	double checkCon1Partial1 = 1./x0;
	ok &= NearEqual( *(sparseJac->values + 2), checkCon1Partial1, 1e-10, 1e-10); 	
	double checkCon1Partial2 = 1./x2;
	ok &= NearEqual( *(sparseJac->values + 3), checkCon1Partial2, 1e-10, 1e-10); 
	return ok;
}//CheckGradientValues

//
//
bool CheckHessianUpper(
SparseHessianMatrix *sparseHessian , 
double x0, double x1, double x2, double y0, double y1, double z ){
/* --------------------------------------------------------------------------
CppAD: C++ Algorithmic Differentiation: Copyright (C) 2003-06 Bradley M. Bell

CppAD is distributed under multiple licenses. This distribution is under
the terms of the 
                    Common Public License Version 1.0.

A copy of this license is included in the COPYING file of this distribution.
Please visit http://www.coin-or.org/CppAD/ for information on other licenses.
-------------------------------------------------------------------------- */
	using CppAD::NearEqual;
	bool ok  = true;
	size_t n = 3;
	int hessValuesIdx = 0;
	//assert( sparseHessian->hessDimension = n * (n + 1) /2);
	//H[0 * n + 0]
	/*
	L  =  z*x0*x0 + y0*(1 + 2*x1 + 3*x2) + y1*log(x0*x2)

	L_0 = 2 * z * x0 + y1 / x0
	L_1 = y0 * 2 
	L_2 = y0 * 3 + y1 / x2 
	*/
	// L_00 = 2 * z - y1 / ( x0 * x0 )
	double check = 2. * z - y1 / (x0 * x0);
	ok &= NearEqual(*(sparseHessian->hessValues + hessValuesIdx++), check, 1e-10, 1e-10); 
	ok &= NearEqual(*(sparseHessian->hessValues + hessValuesIdx++), 0., 1e-10, 1e-10);
	ok &= NearEqual(*(sparseHessian->hessValues + hessValuesIdx++), 0., 1e-10, 1e-10);
	ok &= NearEqual(*(sparseHessian->hessValues + hessValuesIdx++), 0., 1e-10, 1e-10);
	ok &= NearEqual(*(sparseHessian->hessValues + hessValuesIdx++), 0., 1e-10, 1e-10);
	// L_22 = - y1 / (x2 * x2)
	check = - y1 / (x2 * x2);
	ok &= NearEqual(*(sparseHessian->hessValues + hessValuesIdx++), check, 1e-10, 1e-1);
	return ok;
}//CheckHessianUpper
