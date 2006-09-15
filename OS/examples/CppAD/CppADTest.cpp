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
#include <vector>  
#include <string>
 

//using std::cout;
//using std::endl;
int  main(){	
	bool ok = true;

	using std::string;
	using std::stack;
	using CppAD::AD;
	using CppAD::NearEqual;
	using CppAD::vector;
	using kipp::StackMachine;

	// The users program in that stack machine language
	char *program[] = {
		"1.0", "a", "+", "=", "b",  // b = a + 1
		"2.0", "b", "*", "=", "c",  // c = b * 2
		"3.0", "c", "-", "=", "d",  // d = c - 3
		"4.0", "d", "/", "=", "e"   // e = d / 4
	};
	size_t n_program = sizeof( program ) / sizeof( program[0] );

	// put the program in the token stack
	stack< string > token_stack;
	size_t i = n_program;
	while(i--)
		token_stack.push( program[i] );

	// domain space vector
	size_t n = 1;
	vector< AD<double> > X(n);
	X[0] = 0.;

	// declare independent variables and start tape recording
	CppAD::Independent(X);
		
	// x[0] corresponds to a in the stack machine
	vector< AD<double> > variable(26);
	variable[0] = X[0];

	// calculate the resutls of the program
	StackMachine( token_stack , variable);

	// range space vector
	size_t m = 4;
	vector< AD<double> > Y(m);
	Y[0] = variable[1];   // b = a + 1
	Y[1] = variable[2];   // c = (a + 1) * 2
	Y[2] = variable[3];   // d = (a + 1) * 2 - 3
	Y[3] = variable[4];   // e = ( (a + 1) * 2 - 3 ) / 4 
	
	// create f : X -> Y and stop tape recording
	CppAD::ADFun<double> f(X, Y);

	// use forward mode to evaluate function at different argument value
	size_t p = 0;
	vector<double> x(n);
	vector<double> y(m);
	x[0] = 1.;
	y    = f.Forward(p, x);

	// check function values
	ok &= (y[0] == x[0] + 1.);
	ok &= (y[1] == (x[0] + 1.) * 2.);
	ok &= (y[2] == (x[0] + 1.) * 2. - 3.);
	ok &= (y[3] == ( (x[0] + 1.) * 2. - 3.) / 4.);

	// Use forward mode (because x is shorter than y) to calculate Jacobian
	p = 1;
	vector<double> dx(n);
	vector<double> dy(m);
	dx[0] = 1.;
	dy    = f.Forward(p, dx);
	ok   &= NearEqual(dy[0], 1., 1e-10, 1e-10);
	ok   &= NearEqual(dy[1], 2., 1e-10, 1e-10);
	ok   &= NearEqual(dy[2], 2., 1e-10, 1e-10);
	ok   &= NearEqual(dy[3], .5, 1e-10, 1e-10);

	// Use Jacobian routine (which automatically decides which mode to use)
	dy = f.Jacobian(x);
	ok   &= NearEqual(dy[0], 1., 1e-10, 1e-10);
	ok   &= NearEqual(dy[1], 2., 1e-10, 1e-10);
	ok   &= NearEqual(dy[2], 2., 1e-10, 1e-10);
	ok   &= NearEqual(dy[3], .5, 1e-10, 1e-10);

	if( ok) return 0 ; else return 1;
	return 1;
}//end main
