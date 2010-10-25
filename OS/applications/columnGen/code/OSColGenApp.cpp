/* $Id: OSColGenApp.cpp 3038 2009-11-07 11:43:44Z kmartin $ */
/** @file OSColGenApp.cpp
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
#include "OSColGenApp.h"
#include "OSErrorClass.h" 
#include "OSDataStructures.h"

#include "OSInstance.h"
#include "OSCoinSolver.h"
#include "OSConfig.h"
#include "OSResult.h" 
#include "OSOption.h"
#include "OSiLReader.h"        
#include "OSiLWriter.h" 
#include "OSoLReader.h"        
#include "OSoLWriter.h" 
#include "OSrLReader.h"          
#include "OSrLWriter.h"      
#include "OSInstance.h"  
#include "OSFileUtil.h"  

#ifdef COIN_HAS_COUENNE    
#include "OSCouenneSolver.h"
#endif

#ifdef COIN_HAS_IPOPT    
#include "OSIpoptSolver.h"
#endif



#include <sstream>
using std::ostringstream;




OSColGenApp::OSColGenApp():
	m_osinstanceMaster(NULL) {
	std::cout << "INSIDE OSColGenApp CONSTRUCTOR" << std::endl;
}//end OSColGenApp Constructor


OSColGenApp::OSColGenApp(   OSOption *osoption) {
	  std::cout << "INSIDE OSColGenApp CONSTRUCTOR" << std::endl;
	  //std::cout << "the contructor things whichBlock = " << m_whichBlock<< std::endl;
	  m_osinstanceMaster = NULL;
	  m_osrouteSolver = NULL;
	  m_osoption = osoption;
	  m_osrouteSolver = new OSRouteSolver( m_osoption);
	  getOptions( m_osoption);
	  

} //end OSColGenApp Constructor


OSColGenApp::~OSColGenApp(){
	
	std::cout << "INSIDE ~OSColGenApp DESTRUCTOR" << std::endl;

	if( m_osinstanceMaster != NULL) delete  m_osinstanceMaster;
	if( m_osrouteSolver != NULL) delete  m_osrouteSolver;

}//end ~OSColGenApp() destructor


void OSColGenApp::getInitialRestrictedMaster( ){

	m_osinstanceMaster = m_osrouteSolver->getInitialRestrictedMaster( );
	//std::cout << m_osinstanceMaster->printModel(  ) << std::endl;
	
}//end generateInitialRestrictedMaster


void OSColGenApp::getCuts(const  double* x) {
	
	
}//end generateCuts

void OSColGenApp::getColumns( const double* y,  int const numRows ) {

	m_osrouteSolver->getColumns(y, numRows);
	
}//end generateColumns

void OSColGenApp::getOptions(OSOption *osoption) {
	
	
	//get any options relevant to OSColGenApp
	
	try{

	
	} catch (const ErrorClass& eclass) {

		throw ErrorClass(eclass.errormsg);

	}		
	
}//end getOptions


void OSColGenApp::solveRestrictedMasterRelaxation(){
	
	int i;
	int numRows;
	
	try{
		numRows = m_osinstanceMaster->getConstraintNumber();
		
		CoinSolver *solver = NULL;
		solver = new CoinSolver();
		//kipp -- later have clp be an option
		//I guess for now it must be an Osi solver
		solver->sSolverName ="clp";
		std::cout << m_osinstanceMaster->printModel(  ) << std::endl;
		solver->osinstance = m_osinstanceMaster;
		solver->osoption = m_osoption;	
		std::cout << "CALL Solve  " << std::endl;
		solver->solve();
		std::cout << "Solution Status =  " << solver->osresult->getSolutionStatusType( 0 ) << std::endl;
		//std::cout <<  solver->osrl << std::endl;
		
		//get the solver interface
		OsiSolverInterface *si = solver->osiSolver;
		//get the dual solution 
		// y holds the dual values
		double *y = NULL;
		
		
		if(si->getNumRows() != numRows ) 
			throw ErrorClass("detect a row number inconsistency in solveRestrictedMasterRelaxation");
		
		if( numRows > 0 ) y = new double[m_osinstanceMaster->getConstraintNumber() ];
		
		if(si->getRowPrice() == NULL  ) 
			throw ErrorClass("problem getting dual values in solveRestrictedMasterRelaxation");
		
		
		for(i = 0; i <  numRows; i++){
			
			*(y + i) = si->getRowPrice()[ i];
			
		}
		
		
		
		//kipp here is where the while loop goes
		//start while loop
		getColumns(y, numRows);
		
		//end while loop
		
		
		if(numRows > 0) delete[] y;
		y = NULL;
		
		delete solver;
		
		/** Add a column (primal variable) to the problem. */
		
		///just testing
	   // virtual void addCol(int numberElements,
		//		const int* rows, const double* elements,
		////		const double collb, const double colub,   
		//		const double obj) ;	
		/*
		int numberElements = 5;
		double obj = -1;
		
		int* rows = NULL;
		double* values = NULL;
		
		double collb = 0.0;
		double colub = 1.0;
		
		rows = new int[ 5];
		rows[0] =  5;
		rows[1] =  6;
		rows[2] =  7;
		rows[3] =  9;
		rows[4] =  11;
		
		values = new double[ 5];
		values[0] =  1.0;
		values[1] =  1.0;
		values[2] =  1.0;
		values[3] =  1.0;
		values[4] =  1.0;
		
		*/
		//OsiClpSolverInterface * si =
		//dynamic_cast<OsiClpSolverInterface *>(solver->osiSolver) ;
		/*
		si->addCol(numberElements, rows, values,
				collb, colub,   obj) ;	
		
		
		std::cout << std::endl  << std::endl << std::endl;
		std::cout << "CALL Solve  " << std::endl;
		
		solver->solve();
		std::cout << "Solution Status =  " << solver->osresult->getSolutionStatusType( 0 ) << std::endl;
		//std::cout <<  solver->osrl << std::endl;
		*/
	} catch (const ErrorClass& eclass) {

		throw ErrorClass(eclass.errormsg);

	}		
	
	
}// end solveRelaxation



