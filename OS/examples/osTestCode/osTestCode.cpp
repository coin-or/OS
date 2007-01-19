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
		ostringstream outStr;
		cout << "Hello World" << endl;
		outStr << "x";
		outStr << "" ;
		outStr.str("");
		outStr << "y";
		cout << outStr.str() << endl;
		return 0;
	}
	catch( const ErrorClass& eclass){
		std::cout << eclass.errormsg <<  std::endl;
		return 0;
	}
}

