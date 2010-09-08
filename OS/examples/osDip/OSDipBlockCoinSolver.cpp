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


OSDipBlockCoinSolver::OSDipBlockCoinSolver( OSInstance *osinstance) {
	
	try{
		m_osinstance = osinstance;
		//initialize the solver
		m_solver = NULL;
		m_solver = new CoinSolver();
		//lets just start with Cbc
		m_solver->sSolverName ="cbc";		
		m_solver->osinstance = m_osinstance;
		m_solver->buildSolverInstance();
		m_osrlreader = NULL;
		m_osrlreader = new OSrLReader();
	
	} catch (const ErrorClass& eclass) {

		throw ErrorClass(eclass.errormsg);

	}	

}//end OSDipBlockCoinSolver

OSDipBlockCoinSolver::~OSDipBlockCoinSolver(){
	
	if(m_solver != NULL) delete m_solver;
	if(m_osrlreader != NULL) delete m_osrlreader;
}//end ~OSDipBlockCoinSolver

void OSDipBlockCoinSolver::solve(double *cost, SparseVector *sv, double optVal){

	
	try{
		//set the objective function
		m_solver->osiSolver->setObjective( cost);
		//solve the model
		m_solver->solve();
		//get the solution
		m_osresult  = m_osrlreader->readOSrL( m_solver->osrl );
		
		std::string solStatus;
		// the argument is the solution index
		solStatus = m_osresult->getSolutionStatusType( 0 );
		// if solStatus is optimal get the optimal solution value
		if( solStatus.find("ptimal") != string::npos ){
		//first index is objIdx, second is solution index
			optVal = m_osresult->getOptimalObjValue( -1, 0);
		}else{
			throw ErrorClass("problem -- did not optimize a subproblem");
		}	
		
		
		
	
	} catch (const ErrorClass& eclass) {

		throw ErrorClass(eclass.errormsg);

	}	
	
}//end solve

