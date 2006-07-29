/** @file DefaultSolver.h
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


 
#ifndef DEFAULTSOLVER
#define DEFAULTSOLVER


#include "OSInstance.h"
#include "OSResult.h"

#include <string>

/*! \class DefaultSolver DefaultSolver.h "DefaultSolver.h"
 *  \brief The Defalut Solver Class.
 *
 * @author  Robert Fourer, Jun Ma, Kipp Martin, 
 * @version 1.0, 10/05/2005
 * @since   OS1.0
 * 
 */


class DefaultSolver{  

public:	


	
	/** osil holds the problem instance as a std::string */
	std::string osil;
	
	/** osinstance holds the problem instance in-memory as an OSInstance object */
	OSInstance *osinstance;
	
	/** osol holds the options for the solver */
	std::string osol;
	
	/** osoption holds the solver options in-memory as an OSOption object */
	//OSOption  *osoption;
	
	/** osinsList holds the solution or result of the model */
	std::string insList;
	
	
	/** osrl holds the solution or result of the model */
	std::string osrl;
	
	/** osresult holds the solution or result of the model in-memory as an OSResult object */
	OSResult  *osresult;
	
	/** 
	 * m_sSolverName is the name of the Coin solver used, e.g. glpk, or clp 	 
	 */
	std::string m_sSolverName;
	

	/** solve is a virtual function -- the actual solvers will
	 * implement their own solve method 
	 */ 
	virtual void solve() = 0;	
	
	/**
	 * default constructor.
	 */
	DefaultSolver();

	/**
	 * default destructor.
	 */	
	virtual	~DefaultSolver() = 0;
	
	
	
};


#endif
