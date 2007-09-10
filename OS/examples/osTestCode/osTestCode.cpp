/** @file osTestCode.cpp
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
 * This is a dummy executable that does nothing but 
 * print <I>Hello World</I>. I put in test code here when doing
 * various tests.
 * 
 */
 


#include <iostream>
#include "ErrorClass.h"
#include <string>


using std::string;
using std::cout;
using std::endl;


int main(int argC, char* argV[]){
// test OS code samples here
	cout << "Hello World " << endl;	
	int k = 1;
	try{
		if(k == 1) throw ErrorClass("you can't do that");
	}
	catch(const ErrorClass& eclass){
	std::cout << eclass.errormsg <<  std::endl;
	return 0;
	} 
}// end main

