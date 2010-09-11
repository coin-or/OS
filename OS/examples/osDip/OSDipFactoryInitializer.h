/* $Id: OSDipFactoryInitializer.cpp 3038 2009-11-07 11:43:44Z Gassmann $ */
/** @file OSDipFactoryInitializer.cpp
 * 
 *
 * @author  Gus Gassmann, Jun Ma, Kipp Martin, 
 * @version 1.0, 21/July/2008
 * @since   OS1.1
 *
 * \remarks
 * Copyright (C) 2005-2008, Gus Gassmann, Jun Ma, Kipp Martin,
 * Dalhousie University,  Northwestern University, and the University of Chicago.
 * All Rights Reserved.
 * This software is licensed under the Common Public License. 
 * Please see the accompanying LICENSE file in root directory for terms.
 * 
 */
#include<map>
#include "OSDipBlockCoinSolver.h"
//#include "MyBlockSolver.h"
#include <string>


class OSDipFactoryInitializer{
	
public:
	//the constructor 
	OSDipFactoryInitializer(){
		// user edit this, e.g
		//OSDipBlockSolverFactory::factories["MyBlockSolver"] = new MyBlockSolver::Factory;
		OSDipBlockSolverFactory::factories["OSDipBlockCoinSolver"] = new OSDipBlockCoinSolver::Factory;
	}
	
	
	//the destructor 
	~OSDipFactoryInitializer(){
		std::map<std::string, OSDipBlockSolverFactory*>::iterator mit ;
		for(mit = OSDipBlockSolverFactory::factories.begin(); 
			mit != OSDipBlockSolverFactory::factories.begin(); mit++){
			delete mit->second;
		}		
	}//end destructor 
};

