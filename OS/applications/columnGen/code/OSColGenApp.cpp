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
	
	
	int numCols;
	int i;

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
		//kipp -- put in check to make sure we get an integer solution
		if( ipSolver->getObjValue() < m_zUB) m_zUB = ipSolver->getObjValue() ;
		
		//kippster

		//get the solution
		numCols = m_si->getNumCols();
		
		for(i = 0; i < numCols; i++){	
			//get the LP relaxation
			
			*(m_theta + i) = model.getColSolution()[i];	
			
			if( *(m_theta + i) > m_osrouteSolver->m_eps){
				
				m_zOptIndexes.push_back( i) ;
				
				std::cout << "GAIL PUSHING BACK INDEX " << *(m_theta + i) << std::endl;
				std::cout << "GAIL PUSHING BACK INDEX " << i << std::endl;

			}
			
		}

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
		
		m_osrouteSolver->pauHana( m_zOptIndexes);
		
		
		
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
	std::map<int, int>::iterator mit;
	
	std::vector<OSNode*> nodeVec;
	std::vector<OSNode*>::iterator vit;
	
	OSNode *osnode = NULL;
	OSNode *osnodeLeftChild = NULL;
	OSNode *osnodeRightChild = NULL;
	
	int nodeLimit;
	nodeLimit = 10;

	
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
	
	
	int rowIdx;
	rowIdx = 0;
	
	bool leftNodeCreated = false;
	bool rightNodeCreated = false;
	
	int numNodesGenerated;
	
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
		//for(i = 0; i < numNonz; i++){
			
		//	std::cout <<  indexes[ i]  << "   "  << values[ i  ]  << std::endl;
		//}
		//end temp test
		
		
		//if numNonz is greater than zero:
		// 1) add add new variable to map -- at this point varConMap is empty
		// 2) add constraint then add to the formulation
		// 3) add artificial variables
		
		if( numNonz >0){
			
			
			//add the row
			//make upper and lower bound 0 and 1 first 
			m_si->addRow(numNonz, indexes, values, 0, 1) ;
			
			//add the artificial variables
			//add the artificial variable for the UB					
			rowArtVal = -1.0;
			rowIdx = m_si->getNumRows() - 1;
			
			m_si->addCol(1, &rowIdx, &rowArtVal, 0, 1.0, bigNum);
			//add the artificial variable for the LB					
			rowArtVal = 1.0;
			
			m_si->addCol(1, &rowIdx, &rowArtVal, 0, 1.0, bigNum);
			
			//insert into map -- this is the first variable
			varConMap.insert ( std::pair<int,int>(varIdx , rowIdx ) );
			
		}
		
		//m_si->writeLp("gailTest");
		
		

		
		//// start left node ////
		
		
		osnodeLeftChild = createChild(osnode, varConMap, rowIdx, 0, 0);
		if(osnodeLeftChild != NULL){
			//finally set the nodeID
			//and record parent ID
			numNodesGenerated++;
			osnodeLeftChild->nodeID = numNodesGenerated;
			osnodeLeftChild->parentID = 0;
			nodeVec.push_back( osnodeLeftChild);
		}
		
		

		//// end of left node ////
		
		
		//// start right node ////
		
		m_si->setRowUpper( rowIdx, 1);
		m_si->setRowLower( rowIdx, 1);
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
				osnodeRightChild = new OSNode(1,  thetaNumNonz );
				numNodesGenerated = 2;
				osnodeRightChild->parentID = 0;
				osnodeRightChild->nodeID = numNodesGenerated;
				osnodeRightChild->rowIdx[ 0] = rowIdx;
				osnodeRightChild->rowUB[ 0] = 1;
				osnodeRightChild->rowLB[ 0] = 1;
				
				osnodeRightChild->lpValue = m_si->getObjValue();
				
				for(i = 0; i < thetaNumNonz; i++){
					
					osnodeRightChild->thetaIdx[ i] = thetaIdx[ i];
					osnodeRightChild->theta[ i] = theta[ i];
					
				}
				nodeVec.push_back( osnodeRightChild);
			}//end else
			
		}		
		//// end of right node ////
		
		// now loop
		//kipp -- make this an option
		nodeLimit = 100;
		std::cout << "ENTERING THE WHILE IN BRANCH AND BOUND" << std::endl;
		while( (nodeVec.size() > 0) && (numNodesGenerated <= nodeLimit) ){
			
			leftNodeCreated = false;
			rightNodeCreated = false;
			//grab a node -- for now the last node, we do FIFO
			osnode =  nodeVec.back();
			
		

			
			if( osnode->lpValue < m_zUB - m_osrouteSolver->m_eps){
				//this node is worth branching on
				//get a branching variable 
				
				
				//get the branching variable
				m_osrouteSolver->getBranchingCut(osnode->thetaIdx, osnode->theta, 
						osnode->thetaNumNonz, varConMap, varIdx, numNonz, 
						indexes,  values);
					
				std::cout << "varIDX = " << varIdx << std::endl;
				std::cout << "numNonzz = " << numNonz << std::endl;	
				
				
				//for(int i = 0; i < numNonz; i++){
				//	std::cout <<  "x variables for column "  << indexes[i]  << std::endl;
				//	for(int j = m_osrouteSolver->m_thetaPnt[ indexes[ i] ];  j < m_osrouteSolver->m_thetaPnt[ indexes[ i] + 1] ;  j++){
				//		std::cout <<  m_osrouteSolver->m_variableNames[ m_osrouteSolver->m_thetaIndex[  j] ]  << " = "  << theta[ thetaNumNonz]  << std::endl;
				//	}	
				//}

			
			
				//if numNonz is greater than zero:
				// 1) add add new variable to map -- at this point varConMap is empty
				// 2) add constraint then add to the formulation
				// 3) add artificial variables
				
				if( numNonz >0){

					
					//add the row
					//make upper and lower bound 0 and 1 first 
					m_si->addRow(numNonz, indexes, values, 0, 1) ;
					
					//add the artificial variables
					//add the artificial variable for the UB					
					rowArtVal = -1.0;
					rowIdx = m_si->getNumRows() - 1;
					
					m_si->addCol(1, &rowIdx, &rowArtVal, 0, 1.0, bigNum);
					//add the artificial variable for the LB					
					rowArtVal = 1.0;
					
					m_si->addCol(1, &rowIdx, &rowArtVal, 0, 1.0, bigNum);
					
					
					//insert into map -- this is the first variable
					varConMap.insert ( std::pair<int,int>(varIdx , rowIdx) );
					
					
					
					
				} else{
					//the variable varIdx is in the map
					//get the constraint associated with this variable
					//throw and exception if varIdx not a key
					mit = varConMap.find( varIdx);
					if( mit == varConMap.end() ) throw ErrorClass("in branchAndBound getBranchingCut() returned inconsistent value for varIdx");
							else rowIdx = mit->second;
			
					//kipp -- this case should not happen correct -- we cannot be
					// branchin on a variable already branched on in the parent. 
					//throw ErrorClass("we are trying to branch on a child node variable which was fixed in parent");

				}//end if on numNonz
				//m_si->writeLp( "gailTest3" );
				//exit( 1);
				
				// create children
				
				//create the left node
				osnodeLeftChild = createChild(osnode, varConMap, rowIdx, 0, 0);
				if(osnodeLeftChild != NULL){
					//finally set the nodeID
					//and record parent ID
					numNodesGenerated++;
					osnodeLeftChild->nodeID = numNodesGenerated;
					osnodeLeftChild->parentID = osnode->nodeID;
					leftNodeCreated = true;
				}
				
				//create the right node
				osnodeRightChild = createChild(osnode, varConMap, rowIdx, 1, 1);
				if(osnodeRightChild != NULL){
					//finally set the nodeID
					//and record parent ID
					numNodesGenerated++;
					osnodeRightChild->nodeID = numNodesGenerated;
					osnodeRightChild->parentID = osnode->nodeID;
					rightNodeCreated = true;
				}
				
				
				nodeVec.erase( nodeVec.end() - 1) ;
				delete osnode;
				
				if( leftNodeCreated == true) nodeVec.push_back( osnodeLeftChild) ;
				if( rightNodeCreated == true) nodeVec.push_back( osnodeRightChild) ;

				
			}else{
				
				//fathom node by virtue of the upper bound
				std::cout << "FATHAM BY UPPER BOUND " << std::endl;
				nodeVec.erase( nodeVec.end() - 1) ;
				delete osnode;

			}//end if on lp bound check
			
			//kipp -- critical reset upper and lower bounds 
			//kipp don't forget to erase the parent node
			
		}//end the while
		
		//exit( 1);

		delete[] thetaIdx;
		thetaIdx = NULL;
		delete[] theta;
		theta = NULL;
		
		m_zLB = m_zUB;
		std::cout <<  std::endl << std::endl;
		std::cout << "NUMBER OF REMAINING DANGLING NODES  = " << nodeVec.size() << std::endl;
		for ( vit = nodeVec.begin() ; 
				vit != nodeVec.end(); vit++ ){
			
			std::cout << "NODE ID VALUE = " << (*vit)->nodeID << " " ;
			std::cout << "  NODE LP VALUE = " << (*vit)->lpValue << std::endl;
			
			for(i = 0; i < (*vit)->rowIdxNumNonz; i++){
				
				std::cout << "CONSTRAINT =  " <<(*vit)->rowIdx[ i]  ;
				std::cout << "  CONSTRAINT LB = " << (*vit)->rowLB[ i]  ;
				std::cout << "  CONSTRAINT UB = " << (*vit)->rowUB[ i]  << std::endl;
			}
				
			if( (*vit)->lpValue < m_zLB) m_zLB = (*vit)->lpValue;
			delete *vit;
			
		}
		nodeVec.clear();
		//exit( 1);
	
		return bandbWorked;

	} catch (const ErrorClass& eclass) {
		
		delete[] thetaIdx;
		thetaIdx = NULL;
		delete[] theta;
		theta = NULL;

		throw ErrorClass(eclass.errormsg);

	}		

}// end branchAndBound

OSNode* OSColGenApp::createChild(const OSNode *osnodeParent, std::map<int, int> &varConMap,
		const int rowIdx, const double rowLB, const double rowUB){
	
	OSNode *osnodeChild;
	osnodeChild = NULL;


	
	std::map<int, int>::iterator mit;
	
	int i;
	int childRowIdxNumNonz;
	childRowIdxNumNonz = 0;
	
	int numCols;

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
	
	try{

		if(osnodeParent != NULL) childRowIdxNumNonz = osnodeParent->rowIdxNumNonz + 1;
		else childRowIdxNumNonz = 1;
			
		//set upper and lower bounds correctly
		//set the parent values 
		if(osnodeParent != NULL){
			for(i = 0; i < osnodeParent->rowIdxNumNonz; i++){
				
				
				m_si->setRowLower( osnodeParent->rowIdx[ i], osnodeParent->rowLB[ i]);
				m_si->setRowUpper( osnodeParent->rowIdx[ i], osnodeParent->rowUB[ i]);
				
				
			}
		}
		//set the new value
		m_si->setRowLower( rowIdx, rowLB);
		m_si->setRowUpper( rowIdx, rowUB);
		//now solve
		
		//print out the restricted master

		//if(rowUB == 0) m_si->writeLp( "gailTest2" );
	
		//exit( 1);
		solveRestrictedMasterRelaxation();
		std::cout << std::endl << std::endl;
		std::cout << "FINISH SOLVING THE MASTER "  << std::endl;
		//now reset the upper and lower bound
		//set the parent values 
		if( osnodeParent != NULL){
			for(i = 0; i < osnodeParent->rowIdxNumNonz; i++){
				
				
				m_si->setRowLower( osnodeParent->rowIdx[ i], 0);
				m_si->setRowUpper( osnodeParent->rowIdx[ i], 1);
				
				
			}
		}
		//reset the new value
		m_si->setRowLower( rowIdx, 0);
		m_si->setRowUpper( rowIdx, 1);
		
		// let's try and fathom the node
		// if we are not as good a upper bound
		// we fathom, if we are integer we fathom
		std::cout << std::endl << std::endl;
		std::cout << "MESSAGE: START CREATION OF A CHILD NODE" << std::endl;
		std::cout << "LB " << rowLB  <<  " UB = " << rowUB << std::endl;
		std::cout << "MESSAGE: LP RELAXATION VALUE OF POTENTIAL CHILD NODE  " << m_si->getObjValue() << std::endl;
		if( m_si->getObjValue() < m_zUB - m_osrouteSolver->m_eps) {
			// okay cannot fathom based on bound try integrality
			std::cout << "MESSAGE: WE CANNOT FATHOM THE CHILD BASED ON UPPER BOUND " << std::endl;
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
				std::cout << "MESSAGE:  WE HAVE AN INTEGRALITY FATHOM " << m_zUB << std::endl;
				if( m_zUB > m_si->getObjValue() ){
					
					m_zUB = m_si->getObjValue() ;
					//clear out out solution vector
					if( m_zOptIndexes.size() > 0) m_zOptIndexes.clear();
					
					for(i = 0; i < thetaNumNonz; i++){
						m_zOptIndexes.push_back( thetaIdx[ i]) ;
					}
				}
				
			}else{
				//create the child node
				std::cout << "MESSAGE:  WE ARE CREATING A CHILD NODE " << std::endl;
				osnodeChild = new OSNode(childRowIdxNumNonz,  thetaNumNonz );
				
				
				//now set bound arrays 
				if(osnodeParent == NULL){
					osnodeChild->rowIdx[ 0] = rowIdx;
					osnodeChild->rowLB[ 0] = rowLB;
					osnodeChild->rowUB[ 0] = rowUB;
				}else{
					//set old values
					for(i = 0; i < osnodeParent->rowIdxNumNonz; i++){
						
						osnodeChild->rowIdx[ i] = osnodeParent->rowIdx[ i];
						osnodeChild->rowLB[ i] = osnodeParent->rowLB[ i];
						osnodeChild->rowUB[ i] = osnodeParent->rowUB[ i];				
						
					}
					//set new value
					
					osnodeChild->rowIdx[ childRowIdxNumNonz - 1] = rowIdx;
					osnodeChild->rowLB[ childRowIdxNumNonz - 1 ] = rowLB;
					osnodeChild->rowUB[ childRowIdxNumNonz - 1 ] = rowUB;	
					
					
				}
				//set child lp value
				osnodeChild->lpValue = m_si->getObjValue();
				//set theta
				for(i = 0; i < thetaNumNonz; i++){
					
					osnodeChild->thetaIdx[ i] = thetaIdx[ i];
					osnodeChild->theta[ i] = theta[ i];
					
					
					//std::cout <<  "x variables for column "  << thetaIdx[ i]  << std::endl;
					//for(int j = m_osrouteSolver->m_thetaPnt[ thetaIdx[ i] ];  j < m_osrouteSolver->m_thetaPnt[ thetaIdx[ i] + 1] ;  j++){
					//	std::cout <<  m_osrouteSolver->m_variableNames[ m_osrouteSolver->m_thetaIndex[  j] ]  << " = "  << theta[ i]  << std::endl;	
					//}
					
				}
			}//end else on isInteger
		}// end if on upper bound test
		
		delete[] thetaIdx;
		thetaIdx = NULL;
		delete[] theta;
		theta = NULL;
		std::cout << std::endl << std::endl;
		return osnodeChild;
	
	} catch (const ErrorClass& eclass) {
	
		delete[] thetaIdx;
		thetaIdx = NULL;
		delete[] theta;
		theta = NULL;
		throw ErrorClass(eclass.errormsg);

	}		
	
}//end createChild



