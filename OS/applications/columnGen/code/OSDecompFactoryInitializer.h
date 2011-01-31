/* $Id: OSDecompFactoryInitializer.cpp 3038 2009-11-07 11:43:44Z kmartin $ */
/** @file OSDecompFactoryInitializer.cpp
 * 

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
#include "OSDecompSolverFactory.h"
#include "OSDecompSlpSolver.h"
#include "OSDecompBearcatSolver.h"
//#include "MySolver.h"


#include <string>


class OSDecompFactoryInitializer{
	
public:
	//the constructor 
	OSDecompFactoryInitializer(){
		// user edit this, e.g
		//OSDecompSolverFactory::factories["MySolver"] = new MySolver::Factory;
		//OSDecompSolverFactory::factories["OSDecompCoinSolver"] = new OSDecompCoinSolver::Factory;
		//OSDecompSolverFactory::factories["OSDecompSlpSolver"] = new OSDecompSlpSolver::Factory;
		OSDecompSolverFactory::factories["OSDecompBearcatSolver"] = new OSDecompBearcatSolver::Factory;
	}
	
	
	//the destructor 
	~OSDecompFactoryInitializer(){

		std::map<std::string, OSDecompSolverFactory*>::iterator mit ;
		for(mit = OSDecompSolverFactory::factories.begin(); 
			mit != OSDecompSolverFactory::factories.end(); mit++){
			delete mit->second;
			//std::cout << "DELETED A FACTORY " << std::endl;
		}		
	}//end destructor 
};

