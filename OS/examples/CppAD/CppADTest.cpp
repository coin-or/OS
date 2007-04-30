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

#include <cstddef>
#include <cstdlib>
#include <cctype>
#include <cassert>
#include <stack>
#include <cppad/cppad.hpp>
#include <iostream>
#include <math.h>
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
	//osilFileName =  dataDir + "HS071_NLP.osil";
	osilFileName =  dataDir + "CppADTestLag.osil";
	/*
	min x0^2 + 9*x1   -- w[0]
	s.t. 
	33 - 105 + 1.37*x1 + 2*x2 <= 10  -- y[0]
	ln(x0*x2) >= 10  -- y[1]
	Note: in the first constraint 33 is a constant term and 105 
	is part of the nl node
	*/
	fileUtil = new FileUtil();
	osil = fileUtil->getFileAsString( &osilFileName[0]);	
	//
	// create OSReader and OSInstance objects
	OSiLReader *osilreader = NULL;
	OSInstance *osinstance = NULL;
	// create reader, pare the OSiL,  and generate the OSInstance object
	try{
		// domain space vector
		size_t n  = 3; // three variables
		// range space vector
		size_t m = 3; // Lagrangian has an objective and two constraints
		osilreader = new OSiLReader();
		osinstance = osilreader->readOSiL( &osil);
		// here the values of the primal and Lagrange multipliers that we use
		double* x = new double[3]; //primal variables
		double* z = new double[2]; //Lagrange multipliers on constraints
		double* w = new double[1]; //Lagrange multiplier on objective
		x[ 0] = 1; // primal variable 0
		x[ 1] = 5;  // primal variable 1
		x[ 2] = 5;  // primal variable 2
		z[ 0] = 2;  // Lagrange multiplier on constraint 0
		z[ 1] = 1;  // Lagrange multiplier on constraint 1
		w[ 0] = 1;  // Lagrange multiplier on the objective function
		std::vector<double> funVals(3);
		std::vector<double> dfunVals(6);
		double *conVals = NULL;
		conVals = new double[ 2];
		double *objVals = NULL;
		objVals = new double[ 1];
		SparseJacobianMatrix *sparseJac;
		std::vector<double> xx(3);
		//
		//
		//testing 
		xx[0] = 1;
		xx[1] = 5;
		xx[2] = 5;
		std::cout << "CALL CppADFun" << std::endl;
		osinstance->createCppADFun( xx);
		std::cout << "DONE CALL CppADFun" << std::endl;
		std::cout << "CALL forward" << std::endl;
		funVals = osinstance->forwardAD(0, xx);
		std::cout << "Done CALL CppADFun" << std::endl;
		for(int kjl = 0; kjl < 3; kjl++){
			std::cout << "forward 0 " << funVals[ kjl] << std::endl;
		}
		xx[0] = 1;
		xx[1] = 0; 
		xx[2] = 0;
		std::cout << "NOW THE GRADIENT"  << std::endl;
		funVals = osinstance->forwardAD(1, xx);
		for(int kjl = 0; kjl < 3; kjl++){
			std::cout << "forward 0 " << funVals[ kjl] << std::endl;
		}
		
		std::vector<double> lambda(3);
		lambda[0] = 1;
		lambda[1]= 2;
		lambda[2] = 1;
		dfunVals = osinstance->reverseAD(2, lambda);
		for(int kjl = 0; kjl < 6; kjl++){
			std::cout << dfunVals[ kjl] << std::endl;
		}
		//
		//osinstance->getLagrangianHessianSparsityPattern( );
		//osinstance->calculateLagrangianHessian( x, z, w, false, false);
		xx[0] = 1;
		xx[1] = 5;
		xx[2] = 5;
		//osinstance->getIterateResults(xx, lambda);
		//for(int kjl = 0; kjl < k; kjl++){
		//	std::cout << "forward 0 " << funVals[ kjl] << std::endl;
		//}
		//return 0;
		//

		//
		//
		// first we show how to do this with CppAD
		// then we do this with OS routines -- right now the OS routines
		// do a lot of extra work

		CppADvector< AD<double> > X(n);
		CppADvector< AD<double> > Y(m);
				//
		X[1] = 5;
		X[2] = 5;
		X[0] = 0;
		// declare independent variables and start tape recording
		std::cout << "Start Taping" << std::endl;
		CppAD::Independent( X);
		// range space vector 
		Y[ 0] =  CppAD::pow(X[0], 2) + 9*X[1];
		Y[ 1] =  33 - 105 + 1.37*X[1] + 2*X[2] ;
		Y[ 2] =  log(X[0]*X[2]) ;
		// create f: x -> y and stop tape recording
		CppAD::ADFun<double> f(X, Y); 
		std::cout << "Stop Taping" << std::endl;
		// get function values
		xx.clear();
		xx.push_back( x[0]);
		xx.push_back( x[1]);
		xx.push_back( x[2]);
		funVals = f.Forward(0, xx);
		conVals[ 0] = funVals[ 1];
		std::cout << "conVals[ 0] = " << conVals[ 0] << std::endl;
		conVals[ 1] = funVals[ 2];
		std::cout << "conVals[ 1] = " << conVals[ 1] << std::endl;
		objVals[ 0] = funVals[ 0];
		std::cout << "objVals[ 0] = " << objVals[ 0] << std::endl;
		ok = CheckFunctionValues( conVals, *objVals, x[ 0], x[1], x[2], z[0], z[1], w[0] );
		if( ok == 0){
			std::cout << "FAILED CHECKING FUNCTION VALUES TEST" << std::endl;
			return 0;
		}
		else{
			std::cout << "PASSED CHECKING FUNCTION VALUES TEST" << std::endl;
		}
		// now get gradient and Hessian
		// first define and initialze unit vector vector
		sparseJac = osinstance->getJacobianSparsityPattern();
		std::vector<double> unit_col_vec( n);
		std::vector<double> lagMultipliers( m);	
		std::vector<double> gradVals( m);
		lagMultipliers[ 0] = w[ 0];
		lagMultipliers[ 1] = z[ 0];
		lagMultipliers[ 2] = z[ 1];	
		for(idx = 0; idx < n; idx++){
			unit_col_vec[ idx] = 0;
		}	
		for(idx = 0; idx < n; idx++){
			unit_col_vec[ idx] = 1;
			// calculate column i of the Jacobian matrix
			gradVals = f.Forward(1, unit_col_vec);
			unit_col_vec[ idx] = 0;
			// get the nonzero gradient values in constraint k
			for(k = 0; k < m; k++){
				std::cout << "variable " << idx << "  row " << k << "  gradient value" << std::endl;
				std::cout << "gradient value = " << gradVals[ k] << std::endl;	
				// if variable i is in (*m_mapExpressionTreesMod[ index[ k]]->mapVarIdx).find( i) put into the gradient vector
			}
			// get row i of the Lagrangian function!!!
			f.Reverse(2, lagMultipliers);
		}
		// done with CppAD test
		//
		//
		//
		// Now start using the nonlinear API
		// check function values, both objectives and constraints
		std::cout << "Call  = calculateAllConstraintFunctionValues"  << std::endl;			
		conVals = osinstance->calculateAllConstraintFunctionValues( x, false);
		// note: if you just want the value for constraint function indexed by
		// idx call the method:
		//calculateFunctionValue(int idx, double *x, bool functionEvaluated)
		std::cout << "Call  = calculateAllObjectiveFunctionValues"  << std::endl;	
		objVals = osinstance->calculateAllObjectiveFunctionValues( &x[0], false);
		// note: if you just want the value for the objective function indexed by
		// idx call the method:
		//calculateFunctionValue(int idx, double *x, bool functionEvaluated)
		for( idx = 0; idx < osinstance->getConstraintNumber(); idx++){
			std::cout << "CONSTRAINT FUNCTION INDEX = " <<  idx << " FUNCTION VALUE =  "  << *(conVals + idx) << std::endl;
		}
		for( idx = 0; idx < osinstance->getObjectiveNumber(); idx++){
			std::cout << "OBJECTIVE FUNCTION  INDEX = " << idx <<  " FUNCTION VALUE = "  << *(objVals + idx) << std::endl;
		}
		ok = CheckFunctionValues( conVals, *objVals, x[ 0], x[1], x[2], z[0], z[1], w[0] );
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
		ok = CheckGradientValues( sparseJac, objGrad, x[ 0], x[1], x[2], z[0], z[1], w[0] );
		if( ok == 0){
			std::cout << "FAILED THE GRADIENT TEST" << std::endl;
			return 0;
		}
		else{
			std::cout << "PASSED THE GRADIENT TEST" << std::endl;
		}
		//return 0;
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
		sparseHessian = osinstance->calculateLagrangianHessian( x, z, w, false, false);
		for(idx = 0; idx < sparseHessian->hessDimension; idx++){
			std::cout << "row idx = " << *(sparseHessian->hessRowIdx + idx) <<  
			"  col idx = "<< *(sparseHessian->hessColIdx + idx)
			<< " value = " << *(sparseHessian->hessValues + idx) << std::endl;
		}
		ok = CheckHessianUpper( sparseHessian, x[0],  x[1], x[2], z[0], z[1], w[0]);
		if( ok == 0){
			std::cout << "FAILED THE FIRST HESSIAN TEST" << std::endl;
			return 0; 
		}
		else{
			std::cout << "PASSED THE FIRST HESSIAN TEST" << std::endl;
		}
		//return 0;
		//second iteration
		x[0] = 5;
		std::cout << "NOW GET LAGRANGIAN HESSIAN SECOND TIME"   << std::endl;
		sparseHessian = osinstance->calculateLagrangianHessian( x, z, w, false, false);
		for(idx = 0; idx < sparseHessian->hessDimension; idx++){
			std::cout << "row idx = " << *(sparseHessian->hessRowIdx + idx) <<  
			"  col idx = "<< *(sparseHessian->hessColIdx + idx)
			<< " value = " << *(sparseHessian->hessValues + idx) << std::endl;
		}
		ok = CheckHessianUpper( sparseHessian , x[0],  x[1], x[2], z[0], z[1], w[0] );
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
	{
		// checking CppAD power
		size_t n  = 2;
     	double x0 = 4;
     	double x1 = .5;
	   	CppADvector< AD<double> > x(n);
	    x[0]      = x0;
	    x[1]      = x1;
	     // declare independent variables and start tape recording
	     CppAD::Independent(x);
	     // range space vector 
	     size_t m = 1;
	     CppADvector< AD<double> > y(m);
	     y[0] = CppAD::pow(x[0], x[1]);
	     // create f: x -> y and stop tape recording
	     CppAD::ADFun<double> f(x, y); 
	     // check value 
	     double check = std::pow(x0, x1);
	     check = CppAD::pow(x0, x1);
	     std::cout << "check " <<  y[ 0] << std::endl;
	     ok &= NearEqual(y[0] , check,  1e-10 , 1e-10);
	     // forward computation of first partial w.r.t. x[0]
	     std::vector<double> dx(n);
	     std::vector<double> dy(m);
	     dx[0] = 4.;
	     dx[1] = 1/2.;
	     dy    = f.Forward(1, dx);
	     std::cout << "dy =  " <<  dy[ 0] << std::endl;
	     check = x1 * std::pow(x0, x1-1.);
	     ok   &= NearEqual(dy[0], check, 1e-10, 1e-10);
	}
	return 0;
}// end main program

bool CheckFunctionValues( double *conVals, double objValue,
	double x0, double x1, double x2, double z0, double z1, double w ){
	using CppAD::NearEqual;
	bool ok  = true;
	double checkObj = x0*x0 + 9*x1;
	ok &= NearEqual(objValue, checkObj, 1e-10, 1e-10); 
	double checkCon0 = 33. - 105. + 1.37*x1 + 2*x2;
	ok &= NearEqual(*(conVals + 0), checkCon0, 1e-10, 1e-10);
	double checkCon1 = log(x0*x2);
	ok &= NearEqual( *(conVals + 1), checkCon1, 1e-10, 1e-10);
	return ok;
}//CheckFunctionValues
//
//
bool CheckGradientValues( SparseJacobianMatrix *sparseJac, double *objGrad,
	double x0, double x1, double x2, double y0, double y1, double w ){
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
double x0, double x1, double x2, double z0, double z1, double w ){
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
	int hessValuesIdx = 0;
	//assert( sparseHessian->hessDimension = n * (n + 1) /2)
	/*
	L  =  w*x0*x0 + z0*(1 + 1.37*x1 + 3*x2) + z1*log(x0*x2)
	the partial with respect x0
	L_0 = 2 * w * x0 + 9 + z1 / x0
	the partial with respect x1
	L_1 = w0 * 1.37 
	the partial with respect x2
	L_2 = w0 * 3 + z1 / x2 
	*/
	// L_00 = 2 * z - z1 / ( x0 * x0 )
	double check = 2. * w - z1 / (x0 * x0);
	std::cout << check << std::endl;
	std::cout << *(sparseHessian->hessValues + hessValuesIdx) << std::endl;
	ok &= NearEqual(*(sparseHessian->hessValues + hessValuesIdx++), check, 1e-10, 1e-10); 
	ok &= NearEqual(*(sparseHessian->hessValues + hessValuesIdx++), 0., 1e-10, 1e-10);
	if(ok == false) std::cout << "FAILED TWO" << std::endl;
	ok &= NearEqual(*(sparseHessian->hessValues + hessValuesIdx++), 0., 1e-10, 1e-10);
	if(ok == false) std::cout << "FAILED THREE" << std::endl;
	ok &= NearEqual(*(sparseHessian->hessValues + hessValuesIdx++), 0., 1e-10, 1e-10);
	if(ok == false) std::cout << "FAILED FOUR" << std::endl;
	ok &= NearEqual(*(sparseHessian->hessValues + hessValuesIdx++), 0., 1e-10, 1e-10);
	if(ok == false) std::cout << "FAILED FIVE" << std::endl;
	// L_22 = - z1 / (x2 * x2)
	check = - z1 / (x2 * x2);
	ok &= NearEqual(*(sparseHessian->hessValues + hessValuesIdx++), check, 1e-10, 1e-1);
	if(ok == false) std::cout << "FAILED SIX" << std::endl;
	return ok;
}//CheckHessianUpper
				//if( (m_mapExpressionTreesMod.find( index[ j]) != m_mapExpressionTreesMod.end() ) &&
				//	( (*m_mapExpressionTreesMod[ index[ j]]->mapVarIdx).find( i) != (*m_mapExpressionTreesMod[ index[ j]]->mapVarIdx).end()) ){
					// variable i is appears in the expression tree for row index[ j]
					// add the coefficient corresponding to variable i in row index[ j] to the expression tree	
