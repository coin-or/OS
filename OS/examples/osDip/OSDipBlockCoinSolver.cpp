/* $Id: OSBlockSolver.cpp 3038 2009-11-07 11:43:44Z Gassmann $ */
/** @file OSBlockSolver.cpp
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
#include "OSDipBlockCoinSolver.h"
#include "OSErrorClass.h"


OSDipBlockCoinSolver::OSDipBlockCoinSolver():
	m_osinstance(NULL) {
}//end OSDipBlockCoinSolver

OSDipBlockCoinSolver::~OSDipBlockCoinSolver(){
}//end ~OSDipBlockCoinSolver

void OSDipBlockCoinSolver::solve(double *cost, SparseVector *sv, double optVal){
	//lets just start with Cbc
	
	try{
		m_solver = new CoinSolver();
		m_solver->sSolverName ="cbc";		
		m_solver->osinstance = m_osinstance;
		m_solver->solve();
	
	} catch (const ErrorClass& eclass) {

		throw ErrorClass(eclass.errormsg);

	}	
	
}//end solve

