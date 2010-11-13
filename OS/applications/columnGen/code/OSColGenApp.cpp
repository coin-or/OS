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
	
	
	double rowlb;
	rowlb = 0.0;
	double rowub;
	int numRowEls;
	int tmpKount;

	int* cutColIndexes;
	double* cutColValues;
	int* tmpScatterArray;
	int scatterArraySize;
	scatterArraySize = m_osrouteSolver->m_numNodes*(m_osrouteSolver->m_numNodes - 1);
	//kippster -- make this dimension a parameter
	cutColIndexes = new int[ 100000];
	cutColValues = new double [ 100000];
	tmpScatterArray = new int[ scatterArraySize ];
	//zero out the scatter array
	
	for(i = 0; i < scatterArraySize; i++){
		
		tmpScatterArray[ i] = 0;
		
	}
	
	

	
	
	//now for the row

	
	try{
		numRows = m_osinstanceMaster->getConstraintNumber();
		
		CoinSolver *solver = NULL;
		solver = new CoinSolver();
		//kipp -- later have clp be an option
		//I guess for now it must be an Osi solver
		solver->sSolverName ="clp";
		//std::cout << m_osinstanceMaster->printModel(  ) << std::endl;
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
		
		
		//kipp -- really dangerous what happens when we add rows to si, these don't get added to 
		//m_osinstanceMaster
		// dimension y to number of nodes
		if( numRows > 0 ) y = new double[m_osinstanceMaster->getConstraintNumber() ];
		
		if(si->getRowPrice() == NULL  ) 
			throw ErrorClass("problem getting dual values in solveRestrictedMasterRelaxation");
		
		
		for(i = 0; i <  numRows; i++){
			
			*(y + i) = si->getRowPrice()[ i];
			
		}
		
		lowerBound = -1;
		int loopKount = 0;
		
		
		while(lowerBound < -.01 && loopKount < 1000){
			loopKount++;
			//kipp here is where the while loop goes
			//start while loop
			getColumns(y, numRows, numColumns, numNonz, 
					cost, rcost, rowIdx, values,  lowerBound);
			
			std::cout << "LOWER BOUND = " <<  lowerBound   << std::endl;
			
			numNonz = m_osrouteSolver->m_nonzVec; 
			cost =  m_osrouteSolver->m_costVec; 
			rcost = m_osrouteSolver->m_optValHub;
			rowIdx = m_osrouteSolver->m_newColumnRowIdx; 
			values = m_osrouteSolver->m_newColumnRowValue;
			//add columns
			
			for(k = 0; k < numColumns; k++){
				
				si->addCol(numNonz[ k], rowIdx[k], values[k],
						collb, colub,   cost[ k]) ;			
				
			}
		
			std::cout << std::endl  << std::endl << std::endl;
			std::cout << "CALL Solve  " << std::endl;
			solver->solve();
			std::cout << "Solution Status =  " << solver->osresult->getSolutionStatusType( 0 ) << std::endl;
			std::cout << "Number of solver interface columns =  " <<  si->getNumCols()  << std::endl;
			
			if(si->getNumCols() != m_osrouteSolver->m_numThetaVar - 1) throw ErrorClass("number variables in solver not consistent with master");
			
			for(i = 0; i <  numRows; i++){
				
				*(y + i) = si->getRowPrice()[ i];
				
			}
			
		}//end while
		
		
		
		//get a primal solution
		int numCols = 0;
		double* theta = NULL;
		numCols = si->getNumCols();
		theta = new double[ numCols];
		
		for(i=0; i < numCols; i++){
			*(theta + i) = si->getColSolution()[i];
		}
	
		m_osrouteSolver->pauHana( theta);
	
		
		//add the cuts
		// virtual void addRow(int numberElements,
		//		const int *columns, const double *element,
		//		const double rowlb, const double rowub) ;		
		
		numRowEls = 0;
		
		if(m_osrouteSolver->getCuts( theta,  numCols ) == true){
			
			rowub = m_osrouteSolver->m_BmatrixRhs[ m_osrouteSolver->m_numTourBreakCon  - 1];
			
	
			//scatter the constraint in the x - variables
			
			for(i = m_osrouteSolver->m_pntBmatrix[  m_osrouteSolver->m_numTourBreakCon  - 2] ; 
					i <  m_osrouteSolver->m_pntBmatrix[  m_osrouteSolver->m_numTourBreakCon  - 1] ; i++){
				
				tmpScatterArray[ m_osrouteSolver->m_Bmatrix[ i] ] = 1;
				
				
				
			}
			
			//multiply by the transformation matrix
			//tmpScatterArray contains the indexes of xij 
			//variables in the tour-breaking cut
			//int* m_thetaPnt;
			//int* m_thetaIndex;
			//int m_numThetaVar;
			//int m_numThetaNonz;
			//cutColIndexes 
			//cutColValues 
			
			for(i = 0; i < m_osrouteSolver->m_numThetaVar - 1; i++){
				
				//get the xij indexes in this colum 
				tmpKount = 0;
				for(j = m_osrouteSolver->m_thetaPnt[i]; j < m_osrouteSolver->m_thetaPnt[i + 1] ;  j++){
					
					if(tmpScatterArray[ m_osrouteSolver->m_thetaIndex[ j] ] > 0 ){ //count number of xij for theta_i
						
						tmpKount++;
						
					}
					
				}//end loop on j
				
				if(tmpKount > 0){
					//theta_i has a nonzero coefficient in this row
					cutColIndexes[ numRowEls] = i;
					cutColValues[ numRowEls++] = tmpKount;
					
					//std::cout << " INDEX = " << i <<  " VALUE = " << tmpKount << std::endl;
					
				}
				
			}//end loop on i
			

			std::cout << " RHS = " <<  rowub << std::endl;
			si->addRow(numRowEls, cutColIndexes, cutColValues,
					rowlb, rowub ) ;	
			
			
			
			
			//zero out the scatter array again
			
			for(i = m_osrouteSolver->m_pntBmatrix[  m_osrouteSolver->m_numTourBreakCon  - 2] ; 
					i <  m_osrouteSolver->m_pntBmatrix[  m_osrouteSolver->m_numTourBreakCon  - 1] ; i++){
				
				tmpScatterArray[ m_osrouteSolver->m_Bmatrix[ i] ] = 0;
				
				
				
			}		
			
		}
		
		
		solver->solve();
		
		for(i=0; i < numCols; i++){
			*(theta + i) = si->getColSolution()[i];
		}
	
		
		
		
		std::cout << "NUMBER OF ROWS =  " << si->getNumRows() << std::endl;
	
		
		if(numRows > 0) delete[] y;
		y = NULL;
		
		if(numCols > 0) delete[] theta;
		theta = NULL;
		
		
		delete[]  cutColIndexes;
		cutColIndexes = NULL;
		
		delete[]  cutColValues;
		cutColValues = NULL;
		
		delete[]  tmpScatterArray;
		tmpScatterArray = NULL;
		
		
		delete solver;
	

		
		
	} catch (const ErrorClass& eclass) {

		throw ErrorClass(eclass.errormsg);

	}		
	
	
}// end solveRelaxation



