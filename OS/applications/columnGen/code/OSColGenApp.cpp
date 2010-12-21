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

#include "OSNode.h"

#include<map>
#include<vector>
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
	
	  m_osrouteSolver = new OSRouteSolver( osoption);
	  m_osoption = osoption;
	  getOptions( m_osoption);
	  
	  //initialize the bounds
	  m_zUB = OSDBL_MAX;
	  m_zLB = -OSDBL_MAX;
	    
	  	  
	  //now the arrays

} //end OSColGenApp Constructor


OSColGenApp::~OSColGenApp(){
	
	std::cout << "INSIDE ~OSColGenApp DESTRUCTOR" << std::endl;

	//kipp -- why doesn't m_osrouteSolver delete the 
	//m_osinstanceMaster object
	
	if( m_osinstanceMaster != NULL) delete  m_osinstanceMaster;

	if( m_osrouteSolver != NULL) delete  m_osrouteSolver;

}//end ~OSColGenApp() destructor


void OSColGenApp::getInitialRestrictedMaster( ){

	m_osinstanceMaster = m_osrouteSolver->getInitialRestrictedMaster( );
	//std::cout << m_osinstanceMaster->printModel(  ) << std::endl;
	
}//end generateInitialRestrictedMaster


void OSColGenApp::getInitialRestrictedMaster2( ){

	m_osinstanceMaster = m_osrouteSolver->getInitialRestrictedMaster2( );
	//std::cout << m_osinstanceMaster->printModel(  ) << std::endl;
	
}//end generateInitialRestrictedMaster2


void OSColGenApp::getCuts(const  double* thetaVar, const int numThetaVar,
		int &numNewRows, int*  &numNonz, int** &colIdx,
		double** &values, double* &rowLB, double* &rowUB) {
	
	m_osrouteSolver->getCutsTheta( thetaVar, numThetaVar,
			numNewRows, numNonz, colIdx, values, rowLB, rowUB);
	
}//end getCuts


void OSColGenApp::getColumns(const  double* yA, const int numARows,
			const  double* yB, const int numBRows,
			int &numNewColumns, int* &numNonz, double* &cost, 
			int** &rowIdx, double** &values, double &lowerBound) {

	m_osrouteSolver->getColumns(yA, numARows,
			yB, numBRows, numNewColumns, numNonz, 
			cost, rowIdx, values,  lowerBound);
	

	
	
}//end generateColumns

void OSColGenApp::getOptions(OSOption *osoption) {
	
	
	//get any options relevant to OSColGenApp
	
	try{

	
	} catch (const ErrorClass& eclass) {

		throw ErrorClass(eclass.errormsg);

	}		
	
}//end getOptions


void OSColGenApp::solve(){

	std::set<std::pair<int, double> >::iterator sit;	

	//initialize upper bound
	m_zUB = m_osrouteSolver->m_bestIPValue;
	
	std::cout << " m_zUB  " << m_zUB  << std::endl;
	
	try{
		  
		// the solver
		  
		m_solver = new CoinSolver();
		
		// the solver interface
		
		//kipp -- later have clp be an option
		//I guess for now it must be an Osi solver
		m_solver->sSolverName ="cbc";
		//std::cout << m_osinstanceMaster->printModel(  ) << std::endl;
		m_solver->osinstance = m_osinstanceMaster;
		m_solver->osoption = m_osoption;	
		m_solver->buildSolverInstance();

		
		//get the solver interface
		m_si = m_solver->osiSolver;
		
		m_yA = new double[m_osinstanceMaster->getConstraintNumber() ];
		//kipp -- hard coding, come back and fix with option
		//kipp -- do all of the newing in a separate routine
		m_yB = new double[ 10000];
		
		//kipp again hard coding -- remove later
		m_maxCols = 100000;
		m_theta = new double[ m_maxCols];
		
		
		//get initial LP relaxation of master
		solveRestrictedMasterRelaxation();
		m_zLB =  m_si->getObjValue();
		
		

		//now get the upper bound
		//solve as an integer program to get initial upper bound
		
		for ( sit = m_osrouteSolver->intVarSet.begin() ; 
				sit != m_osrouteSolver->intVarSet.end(); sit++ ){
			
			m_si->setInteger( sit->first);
			
			
		}
		
		
		CbcModel model(  *m_si);
		OsiSolverInterface *ipSolver = model.solver();

		ipSolver->branchAndBound();
		//CbcMain0(  model);	
		//CbcMain1( 0, 0, model);
		if( ipSolver->getObjValue() < m_zUB) m_zUB = ipSolver->getObjValue() ;
			

		for ( sit = m_osrouteSolver->intVarSet.begin() ; 
				sit != m_osrouteSolver->intVarSet.end(); sit++ ){
			
			m_si->setContinuous( sit->first);
			m_si->setColUpper( sit->first, sit->second);
			
		}
		

		
		std::cout << "OPTIMAL LP VALUE = " << m_zLB << std::endl;
		std::cout << "CURRENT BEST IP VALUE = " << m_zUB << std::endl;

		
		
		branchAndBound();
		
		m_osrouteSolver->m_bestLPValue = m_zLB;
		m_osrouteSolver->m_bestIPValue = m_zUB;
		
		m_osrouteSolver->pauHana( m_theta);
		
		
		
		delete m_solver;
		
		delete[] m_yA;
		m_yA = NULL;
		
		delete[] m_yB;
		m_yB = NULL;
		
		delete[] m_theta;
		m_theta = NULL;
	

	} catch (const ErrorClass& eclass) {
		
		delete m_solver;
		
		delete[] m_yA;
		m_yA = NULL;
		
		delete[] m_yB;
		m_yB = NULL;
		
		delete[] m_theta;
		m_theta = NULL;		

		throw ErrorClass(eclass.errormsg);

}
	
}//end solve


void OSColGenApp::solveRestrictedMasterRelaxation(){
	
	int i;
	int k;
	//we include convexity constraints in this number
	int numARows;
	// dimension y to number of nodes
	int numBRows;
	int numCols;
	
	//getColumns function call return parameters
	int numNewColumns;
	int* numNonz = NULL;
	double* cost = NULL; 
	int** rowIdx = NULL; 
	double** values = NULL ; 
	double lowerBound;
	//end of getColumns function call return parameters
	
	double collb; // kipp -- put in getColumns
	double colub; // kipp -- put in getColumns
	//all of our m_theta columns have a lower bound of 0 and upper bound of 1
	collb = 0.0;
	colub = 1.0;
	//kipp -- I would like to use OSDBL_MAX but Clp likes this better
	//double bigNum = 1.0e24;
	double bigNum  = 1000000;
	//getRows function call return parameters
	int numNewRows;
	int* numRowNonz = NULL;
	int** colIdx = NULL; 
	double** rowValues = NULL ; 
	double* rowLB;
	double* rowUB;
	//end of getRows function call return parameters	
	//art variables

	int rowArtIdx;
	double rowArtVal;
	
	bool isCutAdded;

	try{
		numARows = m_osrouteSolver->m_numNodes;
		


		//get the dual solution 
		
		isCutAdded = true;
		
		while(isCutAdded == true && m_osrouteSolver->m_numBmatrixCon <= 100){
			
			isCutAdded = false;
			//start out loop on if cuts found
			std::cout << "CALL Solve  " << std::endl;
			m_solver->solve();
			std::cout << "Solution Status =  " << m_solver->osresult->getSolutionStatusType( 0 ) << std::endl;
			//std::cout <<  m_solver->osrl << std::endl;
	
			if(m_si->getNumRows() != numARows + m_osrouteSolver->m_numBmatrixCon ) {
				std::cout << "m_si->getNumRows() = " << m_si->getNumRows() << std::endl;
				std::cout << "numARows = " << numARows << std::endl;
				std::cout << "m_numBmatrixCon = " << m_osrouteSolver->m_numBmatrixCon << std::endl;
				throw ErrorClass("detect a row number inconsistency in solveRestrictedMasterRelaxation");
			}
			
			
			
			if(m_si->getRowPrice() == NULL  ) 
				throw ErrorClass("problem getting dual values in solveRestrictedMasterRelaxation");
			
			
			numBRows = m_osrouteSolver->m_numBmatrixCon;
			
			for(i = 0; i <  numARows; i++){
				
				*(m_yA + i) = m_si->getRowPrice()[ i];
				
			}
			
			for(i = numARows; i <  numARows + numBRows; i++){
				
				*(m_yB + i - numARows) = m_si->getRowPrice()[ i];
				
			}
			
			lowerBound = -1;
			int loopKount = 0;
			
			//kipp -- hard coding in the .0001  and loopKount
			while(lowerBound < -.0001 && loopKount < 10000){
				loopKount++;
				
				//kipp here is where the while loop goes
				//start while loop
				getColumns(m_yA, numARows, m_yB, numBRows, numNewColumns, 
						numNonz, cost,  rowIdx, values,  lowerBound);
				
				std::cout << "Lower Bound = " <<  lowerBound   << std::endl;
			
				for(k = 0; k < numNewColumns; k++){
					
					m_si->addCol( numNonz[ k], rowIdx[k], values[k],
							collb, colub,  cost[ k]) ;	
					
				}
			
				std::cout << std::endl  << std::endl << std::endl;
				std::cout << "CALL Solve  " << std::endl;
				m_solver->solve();
				std::cout << "Solution Status =  " << m_solver->osresult->getSolutionStatusType( 0 ) << std::endl;
				std::cout << "Number of solver interface columns =  " <<  m_si->getNumCols()  << std::endl;
				//m_numNodes is number of artificial variables
				if(m_si->getNumCols() != m_osrouteSolver->m_numThetaVar ) throw ErrorClass("number variables in solver not consistent with master");
				
				for(i = 0; i <  numARows; i++){
					
					*(m_yA + i) = m_si->getRowPrice()[ i];
					
				}
							
				for(i = numARows; i <  numARows + numBRows; i++){
					
					*(m_yB + i - numARows) = m_si->getRowPrice()[ i];
					
				}
				
			}//end while on column generation
			
			//get a primal solution
			numCols = m_si->getNumCols();
			if(numCols + m_osrouteSolver->m_numHubs >= m_maxCols) throw ErrorClass("we ran out of columns");
			
			for(i=0; i < numCols; i++){
				*(m_theta + i) = m_si->getColSolution()[i];
			}
	
			
			numNewRows = 0;
			
			//do not get cuts if LP relaxation worse than upper bound
			if(m_si->getObjValue() < m_zUB) getCuts(m_theta, numCols, numNewRows, numRowNonz, 
					colIdx,rowValues, rowLB, rowUB);
		
			
			if( numNewRows >= 1 ){
				
				isCutAdded = true;
				
				for(i = 0; i < numNewRows; i++){
					
					m_si->addRow(numRowNonz[ i], colIdx[ i], rowValues[ i], rowLB[ i], rowUB[ i] ) ;
					
					//add two artificial variables for this row so we can never be infeasible
					//m_si->addCol( numNonz, rowIdx[k], values[k],
					//		collb, colub,  cost[ k]) ;
					
					//add the artificial variable for the UB					
					rowArtVal = -1.0;
					rowArtIdx = m_si->getNumRows() - 1;
					//m_si->addCol(1, &rowArtIdx, &rowArtVal, 0, bigNum, bigNum);
					m_si->addCol(1, &rowArtIdx, &rowArtVal, 0, 1, bigNum);
					//add the artificial variable for the LB					
					rowArtVal = 1.0;
					
					//m_si->addCol(1, &rowArtIdx, &rowArtVal, 0, bigNum, bigNum);
					m_si->addCol(1, &rowArtIdx, &rowArtVal, 0, 1, bigNum);
							
				}
				
				std::cout << std::endl;
				std::cout << "CUTS WERE ADDED CALL SOLVE" << std::endl;
				m_solver->solve();
				
			} // end if on whether or not we added cuts
			


		
		}//end while on isCutAdded

		
		
	} catch (const ErrorClass& eclass) {

		throw ErrorClass(eclass.errormsg);

	}		
	
	
}//end solveRestrictedMasterRelaxation


bool OSColGenApp::isInteger( const double *thetaVar, const int numThetaVar, 
		const double tol){
	
	
	bool isInt;
	isInt = true;
	int i;
	
	try{	
		
		for(i = 0; i < numThetaVar; i++){
			
			if( (thetaVar[ i] > tol) && (thetaVar[ i] < 1 -  tol) ){
				
				isInt = false;
				break;
			}
			
		}
		
		return isInt;
		
	} catch (const ErrorClass& eclass) {
	
		throw ErrorClass(eclass.errormsg);
	
	}		

	
	
}//end isInteger


void OSColGenApp::printDebugInfo( ){
	
	int numCols;
	int numRows;
	std::set<std::pair<int, double> >::iterator sit;
	int i;
	
	numCols = m_si->getNumCols();	
	
	
	for(i = 0;  i < numCols; i++){
		
		std::cout << "PROCESSING THETA COLUMN " << i <<  "  value =  " <<  m_si->getColSolution()[i] << std::endl;
		
		for(int j = m_osrouteSolver->m_thetaPnt[ i]; j <  m_osrouteSolver->m_thetaPnt[ i + 1]; j++ ){
			
			//std::cout << m_osrouteSolver->m_variableNames[ m_osrouteSolver->m_thetaIndex[ j] ] << std::endl;
			
		}
	}

	numRows = m_si->getNumRows();
	
	for(i = m_osrouteSolver->m_numNodes;  i < numRows; i++){
		
		std::cout << "PROCESSING ROW " << i  << std::endl;
		
		for(int j = m_osrouteSolver->m_pntBmatrix[ i  -   m_osrouteSolver->m_numNodes]; j <  m_osrouteSolver->m_pntBmatrix[ i + 1 -  m_osrouteSolver->m_numNodes]; j++ ){
			
			//std::cout << m_osrouteSolver->m_variableNames[ m_osrouteSolver->m_Bmatrix[ j] ] << std::endl;
			
		}
	}
	//check integer variables and upper bounds -- loop over integer variable set

	//
	for ( sit = m_osrouteSolver->intVarSet.begin() ; 
			sit != m_osrouteSolver->intVarSet.end(); sit++ ){
		
		//std::cout << "Integer variable  " << sit->first << " Upper Bound = "  << sit->second  << std::endl;	
		
	}	
}//end printDebugInfo


bool OSColGenApp::branchAndBound(){
	
	/** varConMap is a map that maps the index
	 * of an x_{ij} variable to the corresponding
	 * branching constraint number in the master
	 */
	std::map<int, int> varConMap;
	
	std::vector<OSNode*> nodeVec;
	std::vector<OSNode*>::iterator vit;
	
	OSNode *osnode = NULL;
	
	int nodeLimit;
	nodeLimit = 10;
	
	int nodesCreated;
	
	
	bool bandbWorked;
	
	bandbWorked = true;
	
	int numCols;
	int varIdx;
	int numNonz;
	int* indexes;
	double* values;	
	int i;
	
	//we want to store the solution vector (theta space)
	//in sparse format
	int thetaNumNonz;
	int *thetaIdx;
	double *theta;
	//kipp -- hard coding -- change
	thetaIdx = new int[ 10000];
	theta = new double[ 10000];
	//
	//
	
	//kipp -- I would like to use OSDBL_MAX but Clp likes this better
	//double bigNum  = 1.0e24;
	double bigNum  = 1000000;
	double rowArtVal ;
	int rowArtIdx ;
	
	try{
		
		//get the solution
		numCols = m_si->getNumCols();	
		for(i = 0; i < numCols; i++){	
			//get the LP relaxation
			*(m_theta + i) = m_si->getColSolution()[i];	
		}
		
		//get the initial branching variable
		m_osrouteSolver->getBranchingCut(m_theta, numCols, 
				varConMap, varIdx, numNonz, indexes,  values);
			
		std::cout << "varIDX = " << varIdx << std::endl;
		std::cout << "numNonz = " << numNonz << std::endl;			
		for(i = 0; i < numNonz; i++){
			
			std::cout <<  indexes[ i]  << "   "  << values[ i  ]  << std::endl;
		}
		//end temp test
		
		
		//if numNonz is greater than zero:
		// 1) add add new variable to map -- at this point varConMap is empty
		// 2) add constraint then add to the formulation
		// 3) add artificial variables
		
		if( numNonz >0){
			
			//insert into map -- this is the first variable
			varConMap.insert ( std::pair<int,int>(varIdx , m_si->getNumRows() + 1) );
			
			//add the row
			//make upper and lower bound 0 and 1 first 
			m_si->addRow(numNonz, indexes, values, 0, 1) ;
			
			//add the artificial variables
			//add the artificial variable for the UB					
			rowArtVal = -1.0;
			rowArtIdx = m_si->getNumRows() - 1;
			
			m_si->addCol(1, &rowArtIdx, &rowArtVal, 0, 1.0, bigNum);
			//add the artificial variable for the LB					
			rowArtVal = 1.0;
			
			m_si->addCol(1, &rowArtIdx, &rowArtVal, 0, 1.0, bigNum);			
			
		}
		
		//m_si->writeLp("gailTest");
		
		
		//// start left node ////
		//now create two nodes, an up and down node
		//first set upper and lower bound to zero
		//we are working with row rowArtIdx
		m_si->setRowUpper( rowArtIdx, 0);
		m_si->setRowLower( rowArtIdx, 0);
		//solve the new problem
		solveRestrictedMasterRelaxation();
		// let's try and fathom the node
		// if we are not as good a upper bound
		// we fathom, if we are integer we fathom
		std::cout << "GAIL HONDA 1 LEFT" << std::endl;
		if( m_si->getObjValue() < m_zUB) {
			// okay cannot fathom based on bound try integrality
			std::cout << "GAIL HONDA 2 LEFT " << std::endl;
			numCols = m_si->getNumCols();
			thetaNumNonz = 0;
			for(i = 0; i < numCols; i++){	
				//get the LP relaxation
				*(m_theta + i) = m_si->getColSolution()[i];	
				if( *(m_theta + i) > m_osrouteSolver->m_eps){
					
					thetaIdx[ thetaNumNonz] = i;
					theta[ thetaNumNonz] = *(m_theta + i);
					thetaNumNonz++;
					
				}
				
			}
			
			
			if( isInteger( m_theta, numCols, m_osrouteSolver->m_eps) == true){
				//fathom by integrality
				m_zUB = m_si->getObjValue();
				std::cout << "GAIL HONDA 3 LEFT " << m_zUB << std::endl;
				
			}else{
				
				//create node 1
				std::cout << "GAIL HONDA 4 LEFT " << std::endl;
				osnode = new OSNode(1,  thetaNumNonz );
				//kipp inefficient we are doing this a second time. 
				osnode->rowIdx[ 0] = rowArtIdx;
				osnode->rowUB[ 0] = 0;
				osnode->rowLB[ 0] = 0;
				
				osnode->lpValue = m_si->getObjValue();
				
				for(i = 0; i < thetaNumNonz; i++){
					
					osnode->thetaIdx[ i] = thetaIdx[ i];
					osnode->theta[ i] = theta[ i];
					
				}
				nodeVec.push_back( osnode);
			}//end else
		}
		
		//// end of left node ////
		
		
		//// start right node ////
		
		m_si->setRowUpper( rowArtIdx, 1);
		m_si->setRowLower( rowArtIdx, 1);
		//solve the new problem
		solveRestrictedMasterRelaxation();
		// let's try and fathom the node
		// if we are not as good a upper bound
		// we fathom, if we are integer we fathom
		std::cout << "GAIL HONDA 1 RIGHT " << std::endl;
		if( m_si->getObjValue() < m_zUB) {
			// okay cannot fathom based on bound try integrality
			std::cout << "GAIL HONDA 2 RIGHT" << std::endl;
			numCols = m_si->getNumCols();
			thetaNumNonz = 0;
			for(i = 0; i < numCols; i++){	
				//get the LP relaxation
				*(m_theta + i) = m_si->getColSolution()[i];	
				if( *(m_theta + i) > m_osrouteSolver->m_eps){
					
					thetaIdx[ thetaNumNonz] = i;
					theta[ thetaNumNonz] = *(m_theta + i);
					thetaNumNonz++;
					
				}
				
			}
			
			
			if( isInteger( m_theta, numCols, m_osrouteSolver->m_eps) == true){
				//fathom by integrality
				m_zUB = m_si->getObjValue();
				std::cout << "GAIL HONDA 3 RIGHT " << m_zUB << std::endl;
				
			}else{
				
				//create node 1
				std::cout << "GAIL HONDA 4 RIGHT " << std::endl;
				osnode = new OSNode(1,  thetaNumNonz );
				//kipp inefficient we are doing this a second time. 
				osnode->rowIdx[ 0] = rowArtIdx;
				osnode->rowUB[ 0] = 0;
				osnode->rowLB[ 0] = 0;
				
				osnode->lpValue = m_si->getObjValue();
				
				for(i = 0; i < thetaNumNonz; i++){
					
					osnode->thetaIdx[ i] = thetaIdx[ i];
					osnode->theta[ i] = theta[ i];
					
				}
				nodeVec.push_back( osnode);
			}//end else
			
		}		
		//// end of right node ////
		
		// now loop
		nodesCreated = 0;
		while( (nodeVec.size() > 0) && (nodesCreated <= nodeLimit) ){
			
			nodesCreated++;
			
			
		}
		
		if(nodeVec.size() == 0) m_zLB = m_zUB;

		delete[] thetaIdx;
		thetaIdx = NULL;
		delete[] theta;
		theta = NULL;
		
		for ( vit = nodeVec.begin() ; 
				vit != nodeVec.end(); vit++ ){
			std::cout << "NODE LP VALUE = " << (*vit)->lpValue << std::endl;
			delete *vit;
			
		}
		nodeVec.clear();
		
		return bandbWorked;

	} catch (const ErrorClass& eclass) {
		
		delete[] thetaIdx;
		thetaIdx = NULL;
		delete[] theta;
		theta = NULL;

		throw ErrorClass(eclass.errormsg);

	}		

}// end branchAndBound



