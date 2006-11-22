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
#include "OSnLNode.h"
#include "ErrorClass.h"
#include "FileUtil.h"  
#include "OSiLReader.h"
#include "OSInstance.h"
#include "OSExpressionTree.h"
#include "OSnLNode.h"
#include "OSDataStructures.h"
//#include "CoinHelperFunctions.hpp"
#include <vector>  
#include <map> 
#include <string>
 

//using std::cout;
//using std::endl;
int  main(){	
	using std::string;
	using std::cout;
	using std::endl;
	using CppAD::AD;
	using CppAD::NearEqual;
	using CppAD::vector;
	std::cout.precision(12);
	bool ok = false;
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
		zz = new double[3];
		zz[ 0] = 0.5;
		zz[ 1] = 1000;
		zz[2] = 1;
		double* xx = new double[3];
		double* yy = new double[2];
		double* ww = new double[1];
		xx[ 0] = 0.5;
		xx[ 1] = 1000;
		xx[2] = 1;
		yy[ 0] = 1;
		yy[ 1] = 1;
		ww[ 0] = 1;
		double *conVals = osinstance->calculateAllConstraintFunctionValues( &zz[0], false);
		double *objVals = osinstance->calculateAllObjectiveFunctionValues( &zz[0], false);
		int idx;
		for( idx = 0; idx < osinstance->getConstraintNumber(); idx++){
			std::cout << "CONSTRAINT FUNCTION INDEX = " <<  idx << " VALUE =  "  << *(conVals + idx) << std::endl;
		}
		for( idx = 0; idx < osinstance->getObjectiveNumber(); idx++){
	
			std::cout << "OBJECTIVE FUNCTION  INDEX = " << idx <<  " VALUE = "  << *(objVals + idx) << std::endl;
		}
		osinstance->calculateObjectiveFunctionGradient(-1, &zz[0], false, false);
		osinstance->calculateAllConstraintFunctionGradients(&zz[0], false, false);
		std::cout << "RETURN FROM GETTING SPARSE JACOBIAN RESULT"   << std::endl;
		std::cout << "NOW GET LAGRANGIAN HESSIAN"   << std::endl;
		SparseHessianMatrix *sparseHessian;
		// the Hessian test
		bool CheckHessianUpper( SparseHessianMatrix *sparseHessian , 
		double x0, double x1, double x2, double y0, double y1, double z );
		//first iteration 
		std::cout << "GET LAGRANGIAN HESSIAN FIRST TIME"   << std::endl;
		sparseHessian = osinstance->calculateLagrangianHessian( xx, yy, ww, false, false);
		for(idx = 0; idx < sparseHessian->hessDimension; idx++){
			std::cout << "row idx = " << *(sparseHessian->hessRowIdx + idx) <<  "  col idx = "<< *(sparseHessian->hessColIdx + idx)
			<< " value = " << *(sparseHessian->hessValues + idx) << std::endl;
		}
		ok = CheckHessianUpper( sparseHessian , xx[0],  xx[1], xx[2], yy[0], yy[1], ww[0] );
		if( ok == 0){
			std::cout << "FAILED THE FIRST HESSIAN TEST" << std::endl;
			return 0;
		}
		else{
			std::cout << "PASSED THE FIRST HESSIAN TEST" << std::endl;
		}
		//second iteration
		ww[ 0] = 3;
		xx[ 0] = 1.0;
		yy[ 0] = 10;
		std::cout << "NOW GET LAGRANGIAN HESSIAN SECOND TIME"   << std::endl;
		sparseHessian = osinstance->calculateLagrangianHessian( xx, yy, ww, false, false);
		for(idx = 0; idx < sparseHessian->hessDimension; idx++){
			std::cout << "row idx = " << *(sparseHessian->hessRowIdx + idx) <<  "  col idx = "<< *(sparseHessian->hessColIdx + idx)
			<< " value = " << *(sparseHessian->hessValues + idx) << std::endl;
		}
		ok = CheckHessianUpper( sparseHessian , xx[0],  xx[1], xx[2], yy[0], yy[1], ww[0] );
		if( ok == 0){
			std::cout << "FAILED THE SECOND HESSIAN TEST" << std::endl;
			return 0;
		}
		else{
			std::cout << "PASSED THE SECOND HESSIAN TEST" << std::endl;
		}
		delete[] zz;
		zz = NULL;
		delete osilreader;
		osilreader = NULL;
		std::cout << "OSILREADER DELETED" << std::endl;
	}
	catch(const ErrorClass& eclass){
	std::cout << eclass.errormsg << std::endl;
	} 	
	return 0;
	
	/*
	std::cout << "BRAD'S EXAMPLE NUMBER ONE" << std::endl;
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
	*/
	std::cout << "BRAD'S EXAMPLE NUMBER TWO" << std::endl;	
	//
	using CppAD::AD;
	using CppAD::vector;
	bool CheckHessian(
	CppAD::vector<double> H , 
	double x0, double x1, double x2, double y0, double y1, double z );
	CppAD::vector< CppAD::AD<double> > fg(
		const CppAD::vector< CppAD::AD<double> > &x );
	// parameters defining problem
	double x0(.5), x1(1e3), x2(1), y0(1.), y1(1.), z(1.);

	// domain space vector
	size_t n = 3;
	vector< AD<double> >  X(n);
	X[0] = x0;
	X[1] = x1;
	X[2] = x2;

	// declare X as independent variable vector and start recording
	CppAD::Independent(X);

	// range space vector
	size_t m = 3;
	vector< AD<double> >  FG(m);
	FG = fg(X);
	
	// create K: X -> FG and stop tape recording
	CppAD::ADFun<double> K;
	K.Dependent(FG);

	// independent variable vector
	vector<double> x(n);
	x[0] = x0;
	x[1] = x1;
	x[2] = x2;

	// compute Hessian at this value of x
	K.Forward(0, x);

	// Place to store the Hessian of the Lagragian 
	vector<double> H( n * n );

	// forward and reverse mode arguments and results 
	vector<double>  dx(n);
	vector<double>   w(m);
	vector<double>  dw(2*n);
	// set weights to Lagrange multiplier values
	w[0] = z;
	w[1] = y0;
	w[2] = y1;
	// initialize dx as zero
	size_t i, j;
	for(i = 0; i < n; i++)
		dx[i] = 0.;
	// loop over components of x
	for(i = 0; i < n; i++)
	{	dx[i] = 1.;             // dx is i-th elementary vector
		K.Forward(1, dx);       // partial w.r.t dx
		dw = K.Reverse(2, w);   // deritavtive of partial
		for(j = 0; j < n; j++)
			H[ i * n + j ] = dw[ j * 2 + 1 ];
		dx[i] = 0.;             // dx is zero vector
	}
	// check this Hessian calculation
	int hessDim = n*n;
	for(i = 0; i < hessDim; i++){
		std::cout << H[ i] << std::endl;
		
	}
	
		std::cout << "SECOND ITERATION OF HESSIAN CALCULATION" << std::endl;	
	
		// compute Hessian at this value of x
		//
		w[ 0] = 2;
		x[ 0] = 10;
	K.Forward(0, x);
	
			dx[i] = 0.;
	// loop over components of x
	for(i = 0; i < n; i++)
	{	dx[i] = 1.;             // dx is i-th elementary vector
		K.Forward(1, dx);       // partial w.r.t dx
		dw = K.Reverse(2, w);   // deritavtive of partial
		for(j = 0; j < n; j++)
			H[ i * n + j ] = dw[ j * 2 + 1 ];
		dx[i] = 0.;             // dx is zero vector
	}

	for(i = 0; i < hessDim; i++){
		std::cout << H[ i] << std::endl;
		
	}	
	std::cout << "OK == "   <<  CheckHessian(H, x0, x1, x2, y0, y1, z) << std::endl;
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

	bool CheckHessian(
	CppAD::vector<double> H , 
	double x0, double x1, double x2, double y0, double y1, double z )
	{	using CppAD::NearEqual;
		bool ok  = true;
		std::cout << "OK == " << ok << std::endl;
		size_t n = 3;
		assert( H.size() == n * n );
		/*
		L   =    z*x0*x0 + y0*(1 + 2*x1 + 3*x2) + y1*log(x0*x2)

		L_0 = 2 * z * x0 + y1 / x0
		L_1 = y0 * 2 
		L_2 = y0 * 3 + y1 / x2 
		*/
		// L_00 = 2 * z - y1 / ( x0 * x0 )
		double check = 2. * z - y1 / (x0 * x0);
		ok &= NearEqual(H[0 * n + 0], check, 1e-10, 1e-10); 
		// L_01 = L_10 = 0
		ok &= NearEqual(H[0 * n + 1], 0., 1e-10, 1e-10);
		ok &= NearEqual(H[1 * n + 0], 0., 1e-10, 1e-10);
		// L_02 = L_20 = 0
		ok &= NearEqual(H[0 * n + 2], 0., 1e-10, 1e-10);
		ok &= NearEqual(H[2 * n + 0], 0., 1e-10, 1e-10);
		// L_11 = 0
		ok &= NearEqual(H[1 * n + 1], 0., 1e-10, 1e-10);
		// L_12 = L_21 = 0
		ok &= NearEqual(H[1 * n + 2], 0., 1e-10, 1e-10);
		ok &= NearEqual(H[2 * n + 1], 0., 1e-10, 1e-10);
		// L_22 = - y1 / (x2 * x2)
		check = - y1 / (x2 * x2);
		ok &= NearEqual(H[2 * n + 2], check, 1e-10, 1e-10);

		return ok;
	}
	
	CppAD::vector< CppAD::AD<double> > fg(
		const CppAD::vector< CppAD::AD<double> > &x )
	{	using CppAD::AD;
		using CppAD::vector;
		assert( x.size() == 3 );

		vector< AD<double> > fg(3);
		fg[0] = x[0] * x[0];
		fg[1] = 1. + 2. * x[1] + 3. * x[2];
		fg[2] = log( x[0] * x[2] );

		return fg;
	}
	
	
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
		assert( sparseHessian->hessDimension = n * (n + 1) /2);
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
	}
