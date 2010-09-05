/* $Id: OSBlockSolver.h 3038 2009-11-07 11:43:44Z Gassmann $ */
/** @file OSBlockSolver.h
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

#ifndef OSDIPBLOCKSOLVER_H
#define OSDIPBLOCKSOLVER_H

// --------------------------------------------------------------------- //

#include<OSDataStructures.h>

// --------------------------------------------------------------------- //
/*!
 * \class 
 * OSBDiplockSolver is a virtual class for solving the 
 *    Block subproblem
 * 
 *
 */
// --------------------------------------------------------------------- //
class OSDipBlockSolver{
public:
	
	/** m_cost is the objective function
	 * of (reduced) coefficients
	 */
	double *m_cost;
	
	/**  m_sparseVec is the column found by solving the block
	 * optimization problem
	 */
	SparseVector *m_sparseVec;
	
	/** m_optVal is the optimal objective function
	 * value of the block optimization problem
	 */
	double m_optVal;
		
	/**
	 * <p>
	 * Calculate the function value given the current variable values.
	 * This is an abstract method which is required to be implemented by the concrete
	 * operator nodes that derive or extend from this OSnLNode class.
	 * </p>
	 *
	 * @param cost -- an input pointer to the objective function (reduced) coefficients.
	 * @param sv -- a return sparse vector with the optimal column
	 * @param optVal -- the optimal solution value of the subproblem
	 */
	virtual void solve(double *cost, SparseVector *sv, double optVal) = 0;
	
	/**
	 *
	 * Default Constructor. 
	 */	
	OSDipBlockSolver();
	
	/**
	 *
	 * Default destructor. 
	 */	
	~OSDipBlockSolver();	
	
	
	//
};

#endif
