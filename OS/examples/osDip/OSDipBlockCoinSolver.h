/* $Id: OSBlockCoinSolver.h 3038 2009-11-07 11:43:44Z Gassmann $ */
/** @file OSBlockCoinSolver.h
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

#ifndef OSDIPBLOCKCOINSOLVER_H
#define OSDIPBLOCKCOINSOLVER_H

// --------------------------------------------------------------------- //
#include "OSDipBlockSolver.h"
#include "OSInstance.h"
#include "OSDataStructures.h"
#include "OSDefaultSolver.h" 
#include "OSCoinSolver.h"
#include "OSResult.h"
#include "OSrLReader.h"

// --------------------------------------------------------------------- //
/*!
 * \class 
 * OSDipBlockCoinSolver solves the block subproblem 
 *	using a COIN-OR solver
 * 
 *
 */
// --------------------------------------------------------------------- //
class OSDipBlockCoinSolver : public OSDipBlockSolver {
public:
	

	OSInstance *m_osinstance;
	OSResult *m_osresult;
	//OSrLReader *m_osrlreader;
	// first declare a generic solver
	CoinSolver *m_solver ;
	
	/**
	 * <p>
	 * Calculate the function value given the current variable values.
	 * This is an abstract method which is required to be implemented by the concrete
	 * operator nodes that derive or extend from this OSnLNode class.
	 * </p>
	 *
	 * @param cost -- an input value: pointer to the objective function (reduced) coefficients.
	 * @param sv -- a return value: sparse vector with the optimal column
	 * @param optVal -- a return value: the optimal solution value of the subproblem
	 */
	virtual void solve(double *cost, std::vector<IndexValuePair*> *solIndexValPair, double *optVal) ;
	
	
	/**
	 * <p>
	 * Calculate the function value given the current variable values.
	 * This is an abstract method which is required to be implemented by the concrete
	 * operator nodes that derive or extend from this OSnLNode class.
	 * </p>
	 *
	 * @param cost -- an input value: pointer to the objective function (reduced) coefficients.
	 * @param osrl -- a return value: an osrl string
	 */
	virtual void solve(double *cost, std::string *osrl) ;
		
	/**
	 *
	 * Default Constructor. 
	 */	
	OSDipBlockCoinSolver();
	
	
	/**
	 *
	 * Create the solver with the instance. 
	 */	
	OSDipBlockCoinSolver( OSInstance *osinstance);
	
	/**
	 *
	 * Default destructor. 
	 */	
	~OSDipBlockCoinSolver();	
	
	
	//
};

#endif
