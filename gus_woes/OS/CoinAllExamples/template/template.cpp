/** @file osTestCode.cpp
 * 
 * @author  Jun Ma, Kipp Martin, 
 * @version 1.0, 10/05/2005
 * @since   OS1.0
 *
 * \remarks
 * Copyright (C) 2005, Jun Ma, Kipp Martin,
 * Northwestern University, and the University of Chicago.
 * All Rights Reserved.
 * This software is licensed under the Common Public License. 
 * Please see the accompanying LICENSE file in root directory for terms.
 * 
 */ 
 


#include <cppad/cppad.hpp> 
#include "OSConfig.h"
#include "OSCoinSolver.h"

#ifdef COIN_HAS_IPOPT  
	#ifndef COIN_HAS_ASL
		#include "OSIpoptSolver.h"
		#undef COIN_HAS_ASL
	#else
		#include "OSIpoptSolver.h"
	#endif
#endif

#include "OSResult.h" 
#include "OSiLReader.h"        
#include "OSiLWriter.h"   
#include "OSrLReader.h"          
#include "OSrLWriter.h"      
#include "OSInstance.h"  
#include "OSFileUtil.h"   
#include "OSDefaultSolver.h"  
#include "OSWSUtil.h" 
#include "OSSolverAgent.h"   
#include "OShL.h"     
#include "OSErrorClass.h"
#include "OSmps2osil.h"   
#include "OSBase64.h"
#include "OSCommonUtil.h"
#include "OSErrorClass.h"
#include "OSMathUtil.h"



#include<iostream> 
using std::cout;   
using std::endl;

//int main(int argC, char* argV[]){
int main( ){
	std::cout << "Hello World" << std::endl;

}// end main

