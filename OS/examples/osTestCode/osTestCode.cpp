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
 
 
#include "OSResult.h"
#include "OSiLReader.h"
#include "OSiLWriter.h"
#include "OSrLReader.h"
#include "OSrLWriter.h"
#include "OSInstance.h"
#include "OSnLNode.h"
#include "FileUtil.h"
#include "ErrorClass.h"
#include "WSUtil.h" 
#include "OSSolverAgent.h" 
#include "CoinHelperFunctions.hpp"  
# include <cppad/cppad.hpp>
# include <cassert>

#include <iostream>
#include <sstream>
#include <string>


  


//
#include <time.h>
#include <sstream>
#include <ctype.h>
#include <vector>
#include <string>

using std::cout;
using std::endl;
using std::ostringstream; 

int main(int argC, char* argV[])
{
	try{
		cout << "Hello World" << endl;
		// a pointer to an integer which is constant
		const int* pX;
		const int k = 5;
		const int m = 11;
		pX = &k;
		// this is illegal -- change the value of what I point to
		//k = 7;
		// this is legal -- but I can change my address
		pX = &m;
		// a pointer which is constant
		int i = 1;
		int* const pY = &i;
		// this is illegal -- I can't change the value of the address
		//pY = &m;
		// this is legal -- I can change the value of what I point to
		i  = 7;
		// a pointer which is constant pointing to a constant
		int d = 1;
		const int* const pZ = &d;
		
		// let pS be non-const pointer
		//int *pS = &k; // illegal
		//int* const w = &k; also illegal -- we could put a different number in the address
		const int* q = &k;
	}
	catch( const ErrorClass& eclass){
		std::cout << eclass.errormsg <<  std::endl;
		return 0;
	}
	{  //start a CppAD test module
	// work with Brad's code
	
	//bool Usefg();
	//Usefg();
	bool ok = true;

	using CppAD::AD;
	using CppAD::NearEqual;

	// domain space vector
	size_t n  = 1;
	double x0 = 0.5;
	CppADvector< AD<double> > x(n);
	x[0]      = x0;

	// declare independent variables and start tape recording
	std::cout << "Start Taping" << std::endl;
	CppAD::Independent(x);

	// range space vector 
	size_t m = 1;
	CppADvector< AD<double> > y(m);
	//y[0] = CppAD::sqrt(x[0]);
	y[ 0] = 1.7 + x[0] + x[0]*x[0]/2.3;

	// create f: x -> y and stop tape recording
	CppAD::ADFun<double> f(x, y); 
	std::cout << "Stop Taping" << std::endl;

	// check value 
	//double check = std::sqrt(x0);
	//ok &= NearEqual(y[0] , check,  1e-10 , 1e-10);

	// forward computation of first partial w.r.t. x[0]
	std::cout << "Reverse Derivative Calculation" << std::endl;
	CppADvector<double> dx(n);
	CppADvector<double> dy(m);
	dx[0] = 1.;
	dy    = f.Reverse(1, dx);
	std::cout << "the derivative is:  " << dy << std::endl;
	} // end first test module
	{ // second test module
  // domain space vector
  	using CppAD::AD;
	using CppAD::NearEqual;
     size_t n = 2;
     CppADvector< AD<double> >  X(n);
     X[0] = 1.;
     X[1] = 2.;
     //X[2] = 5;
     // declare independent variables and starting recording
     CppAD::Independent(X);
     // a calculation between the domain and range values
     // range space vector
     size_t m = 1;
     CppADvector< AD<double> >  Y(m);
     Y[0] = CppAD::pow(X[0], 2) + X[0]*X[1] + CppAD::pow(X[1],3);
     // create f: X -> Y and stop tape recording
     CppAD::ADFun<double> f(X, Y);
     std::vector<double> w(1);
     w[ 0] = 1.0;
     // new value for the independent variable vector
     std::vector<double> x_0(n);
     std::vector<double> x_1(n);
  	 std::vector<double> x_2(n);
     x_0[0] = 1.;
     x_0[1] = 2.;
     x_1[0] = 0;
     x_1[1] = 1;
   	 x_2[0] = 0;
   	 x_2[1] = 0;
     //x[2] = 5;
     // second derivative of y[1] 
     std::vector<double> hes( n * n );
     //
     std::cout << std::endl << std::endl << std::endl << std::endl;
     std::cout << "START HESSIAN CALCULATION BY COMPOSITION" << std::endl;
    // hes = f.Hessian(x_0, 0);
   	f.Forward(0, x_0);
    f.Forward(1, x_1);
    f.Reverse(2, w);
    //f.Forward(0, x_0);
    //f.Forward(1, x_1);
    //f.Reverse(2, w);
   	std::cout << std::endl << std::endl << std::endl << std::endl;
   	std::cout << "NOW USE CPPAD HESSIAN COMMAND" << std::endl;
    //hes = f.Hessian(x_0, 0);
    
   	std::cout << "START HESSIAN CALCULATION BY FORWARD 2" << std::endl;
   	f.Forward(0, x_0);
    f.Forward(1, x_1);
   	f.Forward(2, x_2);
	}// end second test module
	return 0;
}// end main
	///	
	// now Brad's code
//namespace {
	CppAD::AD<double> Lagragian(
		const CppAD::vector< CppAD::AD<double> > &xyz )
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
		AD<double> g0 = 1. + 2.*x1 + 3.*x2;
		AD<double> g1 = log( x0 * x2 );
		// compute the Lagragian
		AD<double> L = y0 * g0 + y1 * g1 + z * f;
	
		return L;
	
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
	bool CheckHessian(
	CppAD::vector<double> H , 
	double x0, double x1, double x2, double y0, double y1, double z )
	{	using CppAD::NearEqual;
		bool ok  = true;
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
		std::cout << "check = " << check << std::endl;
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
	bool UseL()
	{	using CppAD::AD;
		using CppAD::vector;

		// double values corresponding to XYZ vector
		double x0(.5), x1(1e3), x2(1), y0(2.), y1(3.), z(4.);

		// domain space vector
		size_t n = 3;
		vector< AD<double> >  XYZ(n);
		XYZ[0] = x0;
		XYZ[1] = x1;
		XYZ[2] = x2;

		// declare X as independent variable vector and start recording
		CppAD::Independent(XYZ);

		// add the Lagragian multipliers to XYZ
		// (note that this modifies the vector XYZ)
		XYZ.push_back(y0);
		XYZ.push_back(y1);
		XYZ.push_back(z);

		// range space vector
		size_t m = 1;
		vector< AD<double> >  L(m);
		L[0] = Lagragian(XYZ);

		// create K: X -> L and stop tape recording
		// We cannot use the ADFun sequence constructor because XYZ has
		// changed between the call to Independent and here.
		CppAD::ADFun<double> K;
		K.Dependent(L);

		// Operation sequence corresponding to K does depends on 
		// value of y0, y1, and z. Must redo calculations above when 
		// y0, y1, or z changes.

		// declare independent variable vector and Hessian
		vector<double> x(n);
		vector<double> H( n * n );

		// point at which we are computing the Hessian
		// (must redo calculations below each time x changes)
		x[0] = x0;
		x[1] = x1;
		x[2] = x2;
		H = K.Hessian(x, 0);

		// check this Hessian calculation
		return CheckHessian(H, x0, x1, x2, y0, y1, z); 
	}
	bool Usefg()
	{	using CppAD::AD;
		using CppAD::vector;

		// parameters defining problem
		double x0(.5), x1(1e3), x2(1), y0(2.), y1(3.), z(4.);

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

		// Operation sequence corresponding to K does not depend on 
		// value of x0, x1, x2, y0, y1, or z. 

		// forward and reverse mode arguments and results 
		vector<double> x(n);
		vector<double> H( n * n );
		vector<double>  dx(n);
		vector<double>   w(m);
		vector<double>  dw(2*n);

		// compute Hessian at this value of x
		// (must redo calculations below each time x changes)
		x[0] = x0;
		x[1] = x1;
		x[2] = x2;
		K.Forward(0, x);

		// set weights to Lagrange multiplier values
		// (must redo calculations below each time y0, y1, or z changes)
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
		return CheckHessian(H, x0, x1, x2, y0, y1, z); 
	}
//} end namespace

bool HesLagrangian(void)
{	bool ok = true;

	// UseL is simpler, but must retape every time that y of z changes
	ok     &= UseL();

	// Usefg does not need to retape unless operation sequence changes
	ok     &= Usefg();
	return ok;
}


// END PROGRAM
	
	
	
	//
	
	//
	

