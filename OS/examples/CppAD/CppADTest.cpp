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
#include "CoinHelperFunctions.hpp"

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
		double x0, double x1, double x2, double x3, double y0, double y1, double z );
	bool CheckHessianUpper( SparseHessianMatrix *sparseHessian, 
		double x0, double x1, double x2, double y0, double y1, double z );
	bool CheckGradientValues( SparseJacobianMatrix *sparseJac, double *objGrad,
		double x0, double x1, double x2, double y0, double y1, double z );
	bool ok = true;
	int k, idx;
	//
	// get the problem data
	//
 	FileUtil *fileUtil = NULL; 
	std::string osilFileName;
	std::string osil;
	// get the input file
	const char dirsep =  CoinFindDirSeparator();
  	// Set directory containing mps data files.
  	std::string dataDir;
    dataDir = dirsep == '/' ? "../../data/" : "..\\..\\data\\";
	//osilFileName =  dataDir + "HS071_NLP.osil";
	osilFileName =  dataDir + "osilFiles" + dirsep  + "CppADTestLag.osil";
	std::cout  << "osilFileName  =  " << osilFileName << std::endl;
	/**
	 * here is the test problem CppADTestLag.osil:
	 * min x0^2 + 9*x1   -- w[0]
	 * s.t. 
	 * 33 - 105 + 1.37*x1 + 2*x2  + 5*x1 <= 10  -- y[0]
	 * ln(x0*x2) + 7*x3 >= 10  -- y[1]
	 * Note: in the first constraint 33 is a constant term and 105 
	 * is part of the nl node
	 * the Jacobian is:
	 * 
	 * 2*x0   9       0      0
	 * 0      6.37    2      0
	 * 1/x0   0       1/x2   0
	 * 
	 * now set x0 = 1, x1 = 5,  x2 = 5, x3 = 7
	 * the Jacobian is
	 * 
	 * 2   9       0    0
	 * 0   6.37    2    0
	 * 1   0      .2    7
	 * 
	 * Now form a Lagrangian with multipliers of w on the objective
	 * z0 the multiplier on the first constraint and z1 on the second
	 * the Lagrangain is then:
	 * 
	 * 	L = w*(x0^2 + 9*x1) + z0*(1 + 1.37*x1 + 2*x2 + 5*x1) + z1*(log(x0*x2) + 7*x3)
	 * 
	 * the partial with respect x0
	 * L_0 = 2 * w * x0  + z1 / x0
	 * 
	 * the partial with respect x1
	 * L_1 = w * 9 + z0*1.37 + z0*5
	 * 
	 * the partial with respect x2
	 * L_2 = z0 * 2 + z1 / x2 
	 * 
	 * the partial with respect x3
	 * L_3 = z1*7 
	 * 
	 * in the Hessian there are only two nonzero terms
	 * L_00 = 2 * w - z1 / ( x0 * x0 )
	 * L_22 = - z1 / (x2 * x2)
	 * 
	*/
	fileUtil = new FileUtil();
	osil = fileUtil->getFileAsString( &osilFileName[0]);	
	//
	// create OSReader and OSInstance objects
	OSiLReader *osilreader = NULL;
	OSInstance *osinstance = NULL;
	// create reader, parse the OSiL, and generate the OSInstance object
	try{
		// a counter
		int kjl;
		// domain space vector
		size_t n  = 3; // three variables
		// range space vector
		size_t m = 3; // Lagrangian has an objective and two constraints
		osilreader = new OSiLReader();
		osinstance = osilreader->readOSiL( &osil);
		std::vector<double> funVals(3);
		std::vector<double> dfunVals(6);
		double *conVals = NULL;
		conVals = new double[ 2];
		double *objVals = NULL;
		objVals = new double[ 1];
		std::vector<double> vx(3);
		//test forward and reverse sweeps 
		vx[0] = 1;
		vx[1] = 5;
		vx[2] = 5;
		/**
		 * 
		 * create function with domain the variables and range
		 * objective function plus constraint values
		 * IMPORTANT: the forwardAD and reverseAD calls ONLY apply
		 * to the nonlinear part of the problem. The 9*x1 term
		 * in the objective is not part of the AD
		 * calculation nor are any terms in <linearConstraintCoefficients>
		 * that DO NOT appear in any nl nodes, for example the 7*x3 term
		 * in constraint with index 1. Note also, that there are only three
		 * variables that appear in nl nodes, x3 does not
		 * 
		 */
		std::cout << "CALL createCppADFun" << std::endl;
		osinstance->createCppADFun( vx);
		std::cout << "DONE CALL CppADFun" << std::endl;
		//osinstance->initForCallBack();
		std::cout << "CALL forward" << std::endl;
		funVals = osinstance->forwardAD(0, vx);
		for( kjl = 0; kjl < 3; kjl++){
			std::cout << "forward 0 " << funVals[ kjl] << std::endl;
		}
		// get the third column of the Jacobian from a forward sweep
		std::vector<double> e(3);
		e[0] = 0;
		e[1] = 0;
		e[2] = 1;
		std::cout << "Now get the third column of the Jacobian forwardAD(1, e)"  << std::endl;
		funVals = osinstance->forwardAD(1, e);
		for( kjl = 0; kjl < 3; kjl++){
			std::cout << "forward 1 " << funVals[ kjl] << std::endl;
		}
		// get the third row of the Jacobian using a reverse sweep
		std::vector<double> vlambda(3);
		vlambda[0] = 0;
		vlambda[1] = 0;
		vlambda[2] = 1;
		// reverse sweep to get third row of Jacobian 
		std::cout << "Now get the third row of the Jacobian reverseAD(1, vlambda)"  << std::endl;
		funVals = osinstance->reverseAD(1, vlambda);
		for( kjl = 0; kjl < 3; kjl++){
			std::cout << "reverse 1 " << funVals[ kjl] << std::endl;
		}
		// now get the Hessian of the Lagrangian of objective and 
		// with the following multipliers
		vlambda[0] = 1;
		vlambda[1] = 2;
		vlambda[2] = 1;
		/**
		 * 
		 * reverseAD(2, vlambda) will produce a vector
		 * of  size  2*n, the terms 0, 2, 4,  2*n - 2 will be
		 * the first partials of the Lagrangian formed using vlambda
		 * the terms 1, 3, ..., 2*n - 1 will be column (row) row i
		 * of the Hessian of Lagrangian assuming we did a forwardAD(1, e^{i})
		 * where e^{i} is the i'th unit vector
		 * 
		 */		 
		dfunVals = osinstance->reverseAD(2, vlambda);
		// get the first partials of the Lagrangian
		std::cout << "Here are the first partials of the Lagrangain" << std::endl;
		for(int kjl = 0; kjl <= 4; kjl+=2){
			std::cout << dfunVals[ kjl] << std::endl;
		}
		/**
		 * get the third row (column) of the Lagrangian
		 * of the Hessian matrix, it the third row because
		 * we did a  forwardAD(1, e^{3})
		 */
		std::cout << "Here is the third row (column) of Hessian of Lagrangian" << std::endl;
		for(int kjl = 1; kjl <= 5; kjl+=2){
			std::cout << dfunVals[ kjl] << std::endl;
		}
		/**
		 * most solver APIs work with pointers and not vectors so
		 * the OS API works with pointers
		 * here the values of the primal and Lagrange multipliers 
		 * that we use
		 * NOTE: the metods that we illustrate below have all the
		 * constant terms included, in this 9*x1
		 */
		double* x = new double[4]; //primal variables
		double* z = new double[2]; //Lagrange multipliers on constraints
		double* w = new double[1]; //Lagrange multiplier on objective
		x[ 0] = 1;  // primal variable 0
		x[ 1] = 5;  // primal variable 1
		x[ 2] = 5;  // primal variable 2
		x[ 3] = 10;  // primal variable 3
		z[ 0] = 2;  // Lagrange multiplier on constraint 0
		z[ 1] = 1;  // Lagrange multiplier on constraint 1
		w[ 0] = 1;  // Lagrange multiplier on the objective function
		
		/**  
		 * first we show different calls to get constraint and objective 
		 * function values, many of this function calls are overloaded, 
		 * for example, to evaluate all of the constraints at the
		 * current value of x use
		 * 
		 * calculateAllConstraintFunctionValues(double* x, double *objLambda, 
		 * double *conLambda, bool new_x, int highestOrder)
		 * 
		 * if you want the functions values calculated using the algorithmic
		 * differentiation package. This may be desirable if you are also going 
		 * to calculate derivatives at the same time. However, use
		 * 
		 * calculateAllConstraintFunctionValues(double* x, bool new_x)
		 * 
		 * if you are going to do a lot of function evaluations without derivative
		 * calculations, this way you do not need to use operator overloading
		 * 
		 * Similar remarks apply to the objective functions
		 * 
		 * if you want to get a function value by index here that signature
		 * 
		 * double calculateFunctionValue(int idx, double* x, bool new_x);
		 * 
		 * for example, use calculateFunctionValue(-1, x,  true)
		 * to get the first objective function value
		 * 
		 */
		 
		osinstance->bUseExpTreeForFunEval = false;
		std::cout << "Calculate objective, idx = -1"  << std::endl;			
		std::cout << "obj value = " << osinstance->calculateFunctionValue(-1, x,  true) << std::endl;
		
		std::cout << "Calculate  first constraint, idx = 0"  << std::endl;			
		std::cout << "constraint index 0 value = " << osinstance->calculateFunctionValue(0, x,  true) << std::endl;
		 
		std::cout << "Now use calculateAllConstraintFunctionValues"  << std::endl;			
		conVals = osinstance->calculateAllConstraintFunctionValues(x, true);
		for( idx = 0; idx < osinstance->getConstraintNumber(); idx++){
			std::cout << "CONSTRAINT FUNCTION INDEX = " <<  idx << "  CONSTRAINT FUNCTION VALUE =  "  << *(conVals + idx) << std::endl;
		}
		//
		std::cout << "Now use calculateAllObjectiveFunctionValues"  << std::endl;	
		objVals = osinstance->calculateAllObjectiveFunctionValues( x, NULL, NULL, true, 0);
		for( idx = 0; idx < osinstance->getObjectiveNumber(); idx++){
			std::cout << "OBJECTIVE FUNCTION  INDEX = " << idx <<  "  OBJECTIVE FUNCTION VALUE = "  << *(objVals + idx) << std::endl;
		}
		ok = CheckFunctionValues( conVals, *objVals, x[ 0], x[1], x[2], x[3],  z[0], z[1], w[0] );
		if( ok == 0){
			std::cout << "FAILED CHECKING FUNCTION VALUES TEST" << std::endl;
			return 0;
		}
		else{
			std::cout << "PASSED CHECKING FUNCTION VALUES TEST" << std::endl;
		}
		
		/**  
		 * Most solvers that provide call backs want sparsity pattern. 
		 * Jacobian and Hessain sparsity patters are provided by the 
		 * OSInstance API
		 * 
		 */
		
		SparseJacobianMatrix *sparseJac;
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
		
		SparseHessianMatrix *sparseHessian;
		// the Hessian test
		// get the sparsity pattern -- many solvers want to initialize with just the sparsity
		std::cout << "GET LAGRANGIAN HESSIAN SPARSITY PATTERN"   << std::endl;
		sparseHessian = osinstance->getLagrangianHessianSparsityPattern( );
		for(idx = 0; idx < sparseHessian->hessDimension; idx++){
			std::cout <<  "Row Index = " << *(sparseHessian->hessRowIdx + idx) ;
			std::cout <<  "  Column Index = " << *(sparseHessian->hessColIdx + idx) << std::endl;
		}		 
		
		/**  
		 * Most solvers that provide call backs want Jacobian calculation. 
		 * Constraint Jacobians and objective function gradients are 
		 * provided OSInstance API 
		 * the basic signature for these functions is 
		 * 
		 * calculateAllConstraintFunctionGradients(double* x, double *objLambda, 
		 *    double *conLambda, bool new_x, int highestOrder)
		 * 
		 * If we have already calculated function values using the AD routine, then
		 * highestOrder = 0, if we calculated function values using the OS expression 
		 * tree then highestOrder = -1. Then if new_x = false and highestOrder = 0
		 * and we make a gradient calcuation, then forwardAD(0, x) WILL NOT be called
		 * and there is a savings
		 */
		double *objGrad;
		std::cout << "OBJECTIVE FUNCTION GRADIENT"   << std::endl;
		// in our implementation the objective function is a dense gradient
		objGrad = osinstance->calculateObjectiveFunctionGradient( &x[0], NULL, NULL,  -1, false, 1);
		for(idx = 0; idx < osinstance->getVariableNumber(); idx++){
			std::cout << "col idxx = " << idx << "  value =  " << *(objGrad + idx)  << std::endl;
		}
		std::cout << "CONSTRAINT JACOBIAN MATRIX"   << std::endl;
		// now make the gradient calculations and fill in the sparse Jacobian matrix
		sparseJac = osinstance->calculateAllConstraintFunctionGradients( &x[0], NULL, NULL,  false, 1);
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
		/**  
		 * Some solvers that provide call backs want the Hessian of 
		 * the Lagrangian function. This is provided by the OSInstance
		 * API
		 * 
		 * Since we have already made the gradient calcualations we set 
		 * new_x  = false. 
		 * 
		 */
		//first iteration 
		std::cout << "GET LAGRANGIAN HESSIAN FIRST TIME"   << std::endl;
		sparseHessian = osinstance->calculateLagrangianHessian( x, w,  z,  false, 2);
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
		// now change an x value, we don't rebuild the tree, however new_x 
		// must be set to true
		x[0] = 5;
		std::cout << "NOW GET LAGRANGIAN HESSIAN SECOND TIME"   << std::endl;
		sparseHessian = osinstance->calculateLagrangianHessian(  x, w,  z,   true, 2);
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
		// we also have the Jacobian for the new value of x
		idx = 1;
		for(k = *(sparseJac->starts + idx); k < *(sparseJac->starts + idx + 1); k++){
			std::cout << "row idx = " << idx <<  "  col idx = "<< *(sparseJac->indexes + k)
				<< " value = " << *(sparseJac->values + k) << std::endl;
		}
		return 0;
		//set value back
		x[ 0] = 1;	
		//return 0;
		//
		//
		// now work directly with the CppAD package instead of OSInstance API
		//
		n = 4;
		m = 3;
		CppADvector< AD<double> > X(n);
		CppADvector< AD<double> > Y(m);
		X[0] = 5;
		X[1] = 5;
		X[2] = 0;
		X[3] = 1;
		// declare independent variables and start tape recording
		std::cout << "Start Taping" << std::endl;
		CppAD::Independent( X);
		// range space vector 
		// we include the constant terms in the CppAD functions
		Y[ 0] =  CppAD::pow(X[0], 2) + 9*X[1];
		Y[ 1] =  33 - 105 + 1.37*X[1] + 2*X[2] + 5*X[1] ;
		Y[ 2] =  log(X[0]*X[2]) + 7*X[3] ;
		// create f: x -> y and stop tape recording
		CppAD::ADFun<double> f(X, Y); 
		std::cout << "Stop Taping" << std::endl;
		// get function values
		std::vector<double> x_vec( n);
		x_vec[ 0] = x[ 0];
		x_vec[ 1] = x[ 1];
		x_vec[ 2] = x[ 2];
		x_vec[ 3] = x[ 3];
		funVals = f.Forward(0, x_vec);
		conVals[ 0] = funVals[ 1];
		std::cout << "conVals[ 0] = " << conVals[ 0] << std::endl;
		conVals[ 1] = funVals[ 2];
		std::cout << "conVals[ 1] = " << conVals[ 1] << std::endl;
		objVals[ 0] = funVals[ 0];
		std::cout << "objVals[ 0] = " << objVals[ 0] << std::endl;
		ok = CheckFunctionValues( conVals, funVals[ 0], x[ 0], x[1], x[2], x[3], z[0], z[1], w[0] );
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
		unsigned int index, kj;
		return 0;
		for(index = 0; index < n; index++){
			unit_col_vec[ index] = 0;
		}	
		for(index = 0; index < n; index++){
			unit_col_vec[ index] = 1;
			// calculate column i of the Jacobian matrix
			gradVals = f.Forward(1, unit_col_vec);
			unit_col_vec[ index] = 0;
			// get the nonzero gradient values in constraint k
			for(kj = 0; kj < m; kj++){
				std::cout << "variable " << index << "  row " << kj << "  gradient value" << std::endl;
				std::cout << "gradient value = " << gradVals[ kj] << std::endl;	
			}
			// get row i of the Lagrangian function!!!
			f.Reverse(2, lagMultipliers);
		}
		// done with CppAD test	
		// do garbage collection
		delete osilreader;
		osilreader = NULL;
		std::cout << "OSILREADER DELETED" << std::endl;	
		delete[] conVals;
		delete[] objVals;		
	}
	catch(const ErrorClass& eclass){
		std::cout << eclass.errormsg << std::endl;
	} 

	//
	{
		//checking CppAD power, another illustration of CppAD
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
	double x0, double x1, double x2, double x3, double z0, double z1, double w ){
	using CppAD::NearEqual;
	bool ok  = true;
	double checkObj = x0*x0 + 9*x1;
	std::cout  << "checkObj = " << checkObj << std::endl;
	ok &= NearEqual(objValue, checkObj, 1e-10, 1e-10); 
	double checkCon0 = 33. - 105. + 1.37*x1 + 2*x2 + 5*x1;
	std::cout  << "checkCon0 = " << checkCon0 << std::endl;
	ok &= NearEqual(*(conVals + 0), checkCon0, 1e-10, 1e-10);
	double checkCon1 = log(x0*x2) + 7*x3;
	std::cout  << "checkCon1 = " << checkCon1 << std::endl;
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
	double checkCon0Partial1 = 1.37 + 5.0;
	ok &= NearEqual( *(sparseJac->values + 0), checkCon0Partial1, 1e-10, 1e-10); 	
	double checkCon0Partial2 = 2.;
	ok &= NearEqual( *(sparseJac->values + 1), checkCon0Partial2, 1e-10, 1e-10); 
	// row 1 gradient -- there are nonzero partials for variables 0 and 2
	double checkCon1Partial1 = 1./x0;
	ok &= NearEqual( *(sparseJac->values + 3), checkCon1Partial1, 1e-10, 1e-10); 	
	double checkCon1Partial2 = 1./x2;
	ok &= NearEqual( *(sparseJac->values + 4), checkCon1Partial2, 1e-10, 1e-10); 
	return ok;
}//CheckGradientValues
//
bool CheckHessianUpper( SparseHessianMatrix *sparseHessian , 
	double x0, double x1, double x2, double z0, double z1, double w ){
	using CppAD::NearEqual;
	bool ok  = true;
	int hessValuesIdx = 0;
	//assert( sparseHessian->hessDimension = n * (n + 1) /2)
	// L_00 = 2 * w - z1 / ( x0 * x0 )
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
