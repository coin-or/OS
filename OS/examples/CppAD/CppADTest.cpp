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
#include <string>
 

//using std::cout;
//using std::endl;
int  main(){	
	bool ok = true;
	using std::string;
	using std::stack;
	using std::cout;
	using std::endl;
	using CppAD::AD;
	using CppAD::NearEqual;
	using CppAD::vector;
	using OSAD::StackMachine;
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
	osilFileName =  dataDir + "CppADTest.osil";
	fileUtil = new FileUtil();
	osil = fileUtil->getFileAsString( &osilFileName[0]);	
	//
	// parse the file and create an OSInstance object
	OSiLReader *osilreader = NULL;
	OSInstance *osinstance = NULL;
	OSnLNode *nlNode = NULL;
	// create reader and generate the OSInstance object
	osilreader = new OSiLReader();
	osinstance = osilreader->readOSiL( &osil);
	// the OSnL nodes for a nonlinear expression	
	std::vector<OSnLNode*> postFixVec;
	// get the nodes for an expression tree in postfix format
	// in this case we get the nonlinear objective function term
	nlNode = osinstance->getNonlinearExpressionTree( -1);
	// do an echo check
	std::cout << nlNode->getNonlinearExpressionInXML() << std::endl;
	postFixVec = nlNode->getPostfixFromExpressionTree();
	//
	// The users program in that stack machine language
	const char *program[] = {
		"a", "a", "*", "a", "+", "b", "+"  // (a^2 + a)/7
	};
	size_t n_program = sizeof( program ) / sizeof( program[0] );
	// put the program in the token stack
	stack< string > token_stack;
	size_t i = n_program;
	while(i--)
		token_stack.push( program[i] );

	// domain space vector
	size_t n = 2;
	vector< AD<double> > X(n);
	AD<double> rootNode;
	X[0] = 1.0;
	X[1] = 1.0;

	// declare independent variables and start tape recording
	CppAD::Independent(X);
		
	// X[0] corresponds to a in the stack machine
	vector< AD<double> > variable(26);
	variable[0] = X[0];
	variable[1] = X[1];

	// calculate the resutls of the program
	rootNode = StackMachine( token_stack, variable, postFixVec);

	// range space vector
	size_t m = 1;
	vector< AD<double> > Y(m);
	Y[0] = rootNode;   // b = a + 1
	// create f : X -> Y and stop tape recording
	CppAD::ADFun<double> f(X, Y);

	// use forward mode to evaluate function at different argument value
	size_t p = 0;
	vector<double> x(n);
	vector<double> y(m);
	x[0] = 1.;
	x[1] = 107.;
	y    = f.Forward(p, x);
	cout << "VALUE =  " << y[0] << endl;
	// compute derivative using operation sequence stored in f
  	vector<double> jac(m * n); // Jacobian of f (m by n matrix)
   	jac  = f.Jacobian(x);      // Jacobian for operation sequence
	// print the results
   	std::cout << "Partial with respect to x0 computed by CppAD = " << jac[0] << std::endl;
	std::cout << "Partial with respect to x1 computed by CppAD = " << jac[1] << std::endl;
	// Use forward mode (because x is shorter than y) to calculate Jacobian
	/*p = 1;
	CppADvector<double> dx(n);
	CppADvector<double> dy(m);
	dx[0] = .5;
	dx[1] = 107.;
	dy    = f.Forward(p, dx);
	cout << "Derivative with respect to x0 " <<  dy[ 1] << endl;
	ok   &= NearEqual(dy[0], 1., 1e-10, 1e-10);
	ok   &= NearEqual(dy[1], 2., 1e-10, 1e-10);
	//ok   &= NearEqual(dy[2], 2., 1e-10, 1e-10);
	//ok   &= NearEqual(dy[3], .5, 1e-10, 1e-10);

	// Use Jacobian routine (which automatically decides which mode to use)
	dy = f.Jacobian(x);
	cout << "Derivative with respect to x0 " <<  dy[ 1] << endl;
	ok   &= NearEqual(dy[0], 1., 1e-10, 1e-10);
	ok   &= NearEqual(dy[1], 2., 1e-10, 1e-10);
	//ok   &= NearEqual(dy[2], 2., 1e-10, 1e-10);
	//ok   &= NearEqual(dy[3], .5, 1e-10, 1e-10);
	*/

	if( ok) return 0 ; 
	else return 1;
}//end main

