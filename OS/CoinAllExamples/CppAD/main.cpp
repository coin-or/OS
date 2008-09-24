/** @file osRemoteTest.cpp
 * 
 * @author  Gus Gassmann, Jun Ma, Kipp Martin, 
 * @version 1.0, 26/06/2008
 * @since   OS1.1
 *
 * \remarks
 * Copyright (C) 2008, Gus Gassmann, Jun Ma, Kipp Martin,
 * Dalhousie University, Northwestern University, and the University of Chicago.
 * All Rights Reserved.
 * This software is licensed under the Common Public License. 
 * Please see the accompanying LICENSE file in root directory for terms.
 * 
 */ 

#include<iostream> 
using std::cout;   
using std::endl;

extern bool ipopt_cppad(void);

int main( ){
	// Hello world example, replace with your own code

	//Run( ipopt_cppad,       "ipopt_cppad"      );
	ipopt_cppad();
	return 0;
}// end main

