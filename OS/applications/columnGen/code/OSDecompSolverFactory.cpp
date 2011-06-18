/* $Id: OSDecompSolverFactory.cpp 3038 2009-11-07 11:43:44Z kmartin $ */
/** @file OSDecompSolverFactory.cpp
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


// --------------------------------------------------------------------- //
#include "OSInstance.h"
#include "OSResult.h"
#include "OSDataStructures.h"
#include "OSErrorClass.h"
#include <vector>
#include <string>
#include <map>

#include "OSDecompSolverFactory.h"



std::map<std::string, OSDecompSolverFactory*> OSDecompSolverFactory::factories;

OSDecompSolver* OSDecompSolverFactory::createOSDecompSolver(const std::string &solverName) throw(ErrorClass){
	
	
	if( factories.find(solverName) != factories.end() ){
		
		return factories[ solverName]->create();
		
	}else{
		throw ErrorClass( solverName + " is not a valid OSDecompSolver");
	}
	
}//end 


/**
 *
 * Default Constructor. 
 */	
OSDecompSolverFactory::OSDecompSolverFactory(){
	
}
 
 OSDecompSolverFactory::~OSDecompSolverFactory(){
 }
 
 
