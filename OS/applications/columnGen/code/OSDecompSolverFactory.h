/* $Id: OSDecompSolverFactory.h 3038 2009-11-07 11:43:44Z kmartin $ */
/** @file OSDecompSolverFactory.h
 * 
 * \remarks
 * Copyright (C) 2005-2008, Gus Gassmann, Jun Ma, Kipp Martin,
 * Dalhousie University,  Northwestern University, and the University of Chicago.
 * All Rights Reserved.
 * This software is licensed under the Common Public License. 
 * Please see the accompanying LICENSE file in root directory for terms.
 * 
 */

#ifndef OSDECOMPSOLVERFACTORY_H
#define OSDECOMPSOLVERFACTORY_H

// --------------------------------------------------------------------- //
#include "OSInstance.h"
#include "OSOption.h"
#include "OSResult.h"
#include "OSDataStructures.h"
#include "OSErrorClass.h"
#include <vector>
#include <string>
#include <map>
#include "OSDecompSolver.h"

// --------------------------------------------------------------------- //
/*!
 * \class 
 * OSDecompSolverFactory is a virtual class for a solver factory
 * 
 *
 */
// --------------------------------------------------------------------- //



class OSDecompSolverFactory{
	
public:
	OSInstance *osinstance;
	OSOption *osoption;
	
	virtual  OSDecompSolver* create() = 0;
	static  std::map<std::string, OSDecompSolverFactory*> factories;
	static 	OSDecompSolver* createOSDecompSolver(const std::string &solverName) throw(ErrorClass);

	/**
	 *
	 * Default Constructor. 
	 */	
	OSDecompSolverFactory();
	
	/**
	 *
	 * Default destructor. 
	 */	
	virtual ~OSDecompSolverFactory() = 0;
	
};

#endif
