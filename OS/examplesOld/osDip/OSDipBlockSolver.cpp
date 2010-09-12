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
#include "OSDipBlockSolver.h"


OSDipBlockSolver::OSDipBlockSolver():
	m_cost(NULL),
	m_sparseVec( NULL),
	m_optVal( 0) {
}//end OSDipBlockSolver

OSDipBlockSolver::~OSDipBlockSolver(){

	//cout << "inside OSDipBlockSolver destructor" << endl;

}//end ~OSDipBlockSolver


//OSDipBlockSolver* OSDipBlockSolver::classFactory(const std::string &type, OSInstance *osinstance) {
	
//	if(type == "OSDipBlockCoinSolver") return new OSDipBlockCoinSolver( osinstance);

	
//}//end factory

std::map<std::string, OSDipBlockSolverFactory*> OSDipBlockSolverFactory::factories;

OSDipBlockSolver* OSDipBlockSolverFactory::createOSDipBlockSolver(const string &solverName) throw(ErrorClass){
	
	
	if( factories.find(solverName) != factories.end() ){
		
		return factories[ solverName]->create();
		
	}else{
		throw ErrorClass( solverName + " is not a valid OSDipBlockSolver");
	}
	
}//end 