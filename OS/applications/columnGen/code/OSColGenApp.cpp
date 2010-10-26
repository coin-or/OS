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

void OSColGenApp::getColumns(const  double* y, const int numRows,
		int &numColumns, int* numNonz, double* cost, double* rcost,
		int** rowIdx, double** values, double &lowerBound) 
 {


	m_osrouteSolver->getColumns(y, numRows,
			numColumns, numNonz, cost, rcost,
			rowIdx, values,  lowerBound);
	
	
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
	int j;
	int k;
	int numRows;
	// y holds the dual values
	double *y = NULL;
	int numColumns;
	int* numNonz = NULL;
	double* cost = NULL; 
	double* rcost;
	int** rowIdx = NULL; 
	double** values = NULL ; 
	double lowerBound;
	double collb;
	double colub;
	collb = 0.0;
	colub = 1.0;

	
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
		std::cout << "CALL Solveee  " << std::endl;
		solver->solve();
		std::cout << "Solution Status =  " << solver->osresult->getSolutionStatusType( 0 ) << std::endl;
		//std::cout <<  solver->osrl << std::endl;
		
		//get the solver interface
		OsiSolverInterface *si = solver->osiSolver;
		//get the dual solution 

		
		
		if(si->getNumRows() != numRows ) 
			throw ErrorClass("detect a row number inconsistency in solveRestrictedMasterRelaxation");
		
		if( numRows > 0 ) y = new double[m_osinstanceMaster->getConstraintNumber() ];
		
		if(si->getRowPrice() == NULL  ) 
			throw ErrorClass("problem getting dual values in solveRestrictedMasterRelaxation");
		
		
		for(i = 0; i <  numRows; i++){
			
			*(y + i) = si->getRowPrice()[ i];
			
		}
		lowerBound = -1;
		
		int loopKount = 0;
		while(lowerBound < -.01 && loopKount < 70){
			loopKount++;
		
			//kipp here is where the while loop goes
			//start while loop
			getColumns(y, numRows, numColumns, numNonz, 
					cost, rcost, rowIdx, values,  lowerBound);
			
			std::cout << "LOWER BOUND = " <<  lowerBound << std::endl;
			
			
			numNonz = m_osrouteSolver->m_nonzVec; 
			cost =  m_osrouteSolver->m_costVec; 
			rcost = m_osrouteSolver->m_optValHub;
			rowIdx = m_osrouteSolver->m_newColumnRowIdx; 
			values = m_osrouteSolver->m_newColumnRowValue;
	
		
			/*
			double tmpVal;
			
			for(i = 0; i < numColumns; i++){
				
				tmpVal = cost[ i];
				
				//std::cout << "OBJ  COST = " << cost[ i] << std::endl;
				
				for(j = 0; j < numNonz[i] ; j++){
					
					tmpVal = tmpVal -  y[ rowIdx[i][j] ]*values[i][j];
					
					//std::cout << "NODE INDEX  = "  << rowIdx[i][j] + numColumns << std::endl;
					//std::cout << "row value = "  << values[i][j] << std::endl;
					
				}
				
		
				
				
				//if(rcost[ i] > tmpVal + .1 || rcost[ i] < tmpVal - .1) exit( 1);
				std::cout << "Kipp REDUCED COST = " << rcost[ i] << std::endl;
				std::cout << "Clp REDUCED COST = " << tmpVal << std::endl;
				
				
			}
			*/
			
		
			//add columns
			
			for(k = 0; k < numColumns; k++){
				
				si->addCol(numNonz[ k], rowIdx[k], values[k],
						collb, colub,   cost[ k]) ;		
				
				
				
			}
		
			std::cout << std::endl  << std::endl << std::endl;
			std::cout << "CALL Solve  " << std::endl;
			
			solver->solve();
			std::cout << "Solution Status =  " << solver->osresult->getSolutionStatusType( 0 ) << std::endl;
			std::cout << "Number of columns =  " <<  si->getNumCols()  << std::endl;
			
			for(i = 0; i < si->getNumCols(); i++){
				
				//std::cout << "REDUCED COST  =  " <<  si->getReducedCost()[ i]  << std::endl;
				
				
				
			}
			
			
			for(i = 0; i <  numRows; i++){
				
				*(y + i) = si->getRowPrice()[ i];
				
				//std::cout << "DUAL VALUE " << *(y + i) << std::endl;
				
			}
			
			
		}//end while
		
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



