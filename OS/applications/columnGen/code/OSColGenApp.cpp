/* $Id: OSColGenApp.cpp 3038 2009-11-07 11:43:44Z kmartin $ */
/** @file OSColGenApp.cpp
 * 
 * \remarks
 * Copyright (C) 2005-2010, Horand Gassmann, Jun Ma, Kipp Martin,
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
#include<map>
#include <sstream>
using std::ostringstream;




OSColGenApp::OSColGenApp():
	m_osinstanceMaster(NULL) {
	std::cout << "INSIDE OSColGenApp CONSTRUCTOR" << std::endl;
	
}//end OSColGenApp Constructor


OSColGenApp::OSColGenApp(   OSOption *osoption) {
	  std::cout << "INSIDE OSColGenApp CONSTRUCTOR" << std::endl;
	  //std::cout << "the contructor things whichBlock = " << m_whichBlock<< std::endl;
	  
	  //get parameters-options
	  //set default values:
	  
	  m_osDecompParam.nodeLimit = 1000;
	  m_osDecompParam.columnLimit = 20000;
	  m_osDecompParam.masterColumnResetValue = 5000;
	  m_osDecompParam.zeroTol = .0001;
	  m_osDecompParam.artVarCoeff = 1000000;
	  m_osDecompParam.optTolPerCent = 0;
	  
	  m_osoption = osoption;
	  //get the options for the OSDecompSolver
	  getOptions( m_osoption);
	  
	  
	  m_osinstanceMaster = NULL;
	  m_osrouteSolver = NULL;
	  m_osrouteSolver = new OSRouteSolver( osoption);
	  //share the common parameters
	  m_osrouteSolver->m_osDecompParam = m_osDecompParam;
	  m_osrouteSolver->initializeDataStructures();
	  
	  //initialize the bounds
	  m_zUB = OSDBL_MAX;
	  m_zLB = -OSDBL_MAX;
	    


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
	
	//exit( 1);
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

		std::vector<SolverOption*> solverOptions;
		std::vector<SolverOption*>::iterator vit;
		
		solverOptions = osoption->getSolverOptions("OSDecompSolver");
		if (solverOptions.size() == 0) throw ErrorClass( "options for OSDecompSolver not available");
		
		
		for (vit = solverOptions.begin(); vit != solverOptions.end(); vit++) {
			
			if((*vit)->name.find("columnLimit") !=  std::string::npos){
				
				
				std::istringstream columnLimitBuffer( (*vit)->value);
				columnLimitBuffer >> m_osDecompParam.columnLimit;
				std::cout << "columnLimit = " <<  m_osDecompParam.columnLimit <<  std::endl;
				
			}else{
				
				if( (*vit)->name.find("artVarCoeff") !=  std::string::npos ){
					
					std::istringstream artVarCoeffBuffer( (*vit)->value);
					artVarCoeffBuffer >> m_osDecompParam.artVarCoeff;
					std::cout << "artVarCoeff = " <<  m_osDecompParam.artVarCoeff <<  std::endl;
					
				}else{
					
					if( (*vit)->name.find("zeroTol") !=  std::string::npos){
						
						std::istringstream zeroTolBuffer( (*vit)->value);
						zeroTolBuffer >> m_osDecompParam.zeroTol;
						std::cout << "zeroTol = " <<  m_osDecompParam.zeroTol <<  std::endl;
						
					}else{
						
						
						if( (*vit)->name.find("nodeLimit") !=  std::string::npos){
							
							std::istringstream nodeLimitBuffer( (*vit)->value);
							nodeLimitBuffer >> m_osDecompParam.nodeLimit;
							std::cout << "nodeLimit = " <<  m_osDecompParam.nodeLimit <<  std::endl;
							
						}else{
							
							if( (*vit)->name.find("masterColumnResetValue") !=  std::string::npos){
								
								std::istringstream masterColumnResetValueBuffer( (*vit)->value);
								masterColumnResetValueBuffer >> m_osDecompParam.masterColumnResetValue;
								std::cout << "masterColumnResetValue = " <<  m_osDecompParam.masterColumnResetValue <<  std::endl;
							}else{
								
								if( (*vit)->name.find("optTolPerCent") !=  std::string::npos){
									
									std::istringstream optTolPerCentBuffer( (*vit)->value);
									optTolPerCentBuffer >> m_osDecompParam.optTolPerCent;
									std::cout << "masterColumnResetValue = " <<  m_osDecompParam.optTolPerCent<<  std::endl;
								}
							}
						}
					}
				}
			}
		}
	
	} catch (const ErrorClass& eclass) {

		throw ErrorClass(eclass.errormsg);

	}		
	
}//end getOptions


void OSColGenApp::solve(){

	int *cbasis = NULL;
	int *rbasis = NULL;
	int *new_cbasis = NULL;
	
	
	
	std::set<std::pair<int, double> >::iterator sit;
	std::vector<int>::iterator vit;
	std::map<int, int>::iterator mit;
	
	int numCols;
	int numRows;
	int i;
	int j;
	
	

	//initialize upper bound
	m_zUB = m_osrouteSolver->m_bestIPValue;
	
	//initialize number of columns generated
	
	m_numColumnsGenerated = 0;
	
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
		
		//pass options
		m_solver->osoption = m_osoption;	
		m_solver->buildSolverInstance();

		
		//get the solver interface
		m_si = m_solver->osiSolver;
		
		m_yA = new double[m_osinstanceMaster->getConstraintNumber() ];
		//kipp -- hard coding, come back and fix with option
		//kipp -- do all of the newing in a separate routine
		m_yB = new double[  m_osrouteSolver->m_maxBmatrixCon];
		
		
		m_maxCols = m_osrouteSolver->m_maxMasterColumns;
		m_maxRows = m_osrouteSolver->m_maxMasterRows;
		
		m_theta = new double[ m_maxCols];

		
		//get initial LP relaxation of master
		solveRestrictedMasterRelaxation(cbasis, rbasis);
		//get the solution vector
		numCols = m_si->getNumCols();
		numRows = m_si->getNumRows();
		
		//kipp -- just testing
		cbasis = new int[ numCols];
		rbasis = new int[ numRows ];
		m_si->getBasisStatus( cbasis, rbasis);
		
		for(i = 0; i < numCols; i++){
			//get the basic primal variables
			if(cbasis[ i] == 1) m_zOptRootLP.push_back( i);
			//get the LP relaxation
			*(m_theta + i) = m_si->getColSolution()[i];	
			///optionally print out the corresponding x columns
			if( *(m_theta + i) > m_osDecompParam.zeroTol){
				
				
				std::cout <<  "x variables for column "  << i  << std::endl;
				
					
				for(j = m_osrouteSolver->m_thetaPnt[ i];  j < m_osrouteSolver->m_thetaPnt[ i + 1] ;  j++){
					
						
					std::cout <<  m_osrouteSolver->m_variableNames[ m_osrouteSolver->m_thetaIndex[  j] ]  << " = "  <<  *(m_theta + i)  << std::endl;
						
				}	
			}			
			///end of optionally print out
		}
		
		m_zLB =  m_si->getObjValue();

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
		
		//get the solution
		numCols = m_si->getNumCols();
		
		for(i = 0; i < numCols; i++){	
			
			//get the indexes of integer variables
			if( model.getColSolution()[i] > m_osDecompParam.zeroTol){
				
				m_zOptIndexes.push_back( i) ;

			}
			
		}

		for ( sit = m_osrouteSolver->intVarSet.begin() ; 
				sit != m_osrouteSolver->intVarSet.end(); sit++ ){
			
			m_si->setContinuous( sit->first);
			m_si->setColUpper( sit->first, sit->second);
			
		}
	
		std::cout << "OPTIMAL LP VALUE = " << m_zLB << std::endl;
		std::cout << "CURRENT BEST IP VALUE = " << m_zUB << std::endl;
		
		/////////////
		//start reset
		/*
		int tmpCols =  m_numColumnsGenerated;
		resetMaster();
		numCols = m_si->getNumCols();
		new_cbasis = new int[ numCols  ];
		for(i = 0; i < numCols; i++) new_cbasis[ i] = 3;
		for (vit = m_zOptRootLP.begin(); vit != m_zOptRootLP.end(); vit++ ) new_cbasis[  *vit ] = 1;
		solveRestrictedMasterRelaxation(new_cbasis, rbasis);
		//m_si->setBasisStatus( new_cbasis, rbasis);
		//m_si->initialSolve();
		for(i = 0; i < numCols; i++) *(m_theta + i) = m_si->getColSolution()[i];	
		std::cout << "NUMBER OF NEW GENERATED COLUMNS =  "  << m_numColumnsGenerated - tmpCols << std::endl;
		*/
		//end reset
		/////////////////////////
		
		
		//go into branch and bound
		std::cout << "START BRANCH AND BOUND =  "   << std::endl;
		branchAndBound();
		m_osrouteSolver->m_bestLPValue = m_zLB;
		m_osrouteSolver->m_bestIPValue = m_zUB;	
		m_osrouteSolver->pauHana( m_zOptIndexes, m_numNodesGenerated, m_numColumnsGenerated);
		
		
		delete m_solver;
		
		delete[] m_yA;
		m_yA = NULL;
		
		delete[] m_yB;
		m_yB = NULL;
		
		delete[] m_theta;
		m_theta = NULL;

		
		delete[] cbasis;
		cbasis = NULL;
		if(new_cbasis != NULL) delete[] new_cbasis;
		new_cbasis = NULL;
		delete[] rbasis;
		rbasis = NULL;
	

	} catch (const ErrorClass& eclass) {
		
		delete m_solver;
		
		delete[] m_yA;
		m_yA = NULL;
		
		delete[] m_yB;
		m_yB = NULL;
		
		delete[] m_theta;
		m_theta = NULL;	
		

	
		delete[] cbasis;
		cbasis = NULL;
		if(new_cbasis != NULL) delete[] new_cbasis;
		new_cbasis = NULL;
		delete[] rbasis;
		rbasis = NULL;

		throw ErrorClass(eclass.errormsg);

}
	
}//end solve


void OSColGenApp::solveRestrictedMasterRelaxation(const int *colBasisStatus,  
		const int *rowBasisStatus){
	
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
	//double bigM = 1.0e24;
	double bigM  = m_osDecompParam.artVarCoeff;
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
		
		
		isCutAdded = true;
		
		while(isCutAdded == true ){
			
			isCutAdded = false;
			//start out loop on if cuts found
			std::cout << "CALL Solve  " << " Number of columns =  " <<  m_si->getNumCols() <<  std::endl;
			//kippster -- key problem
			//we are going through OS here, m_solver is a CoinSolver object

			//if( (colBasisStatus != NULL)  && (rowBasisStatus != NULL) )  {
			//	std::cout << "CALL  setBasisStatus " <<  std::endl;
			//	m_si->setBasisStatus( colBasisStatus, rowBasisStatus);
			//	std::cout << "FINISH CALL  setBasisStatus " <<  std::endl;
				
			//}
				
			
			//now solve
			m_solver->solve();
			//m_si->initialSolve();
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
			
			//////////////////////
			while(lowerBound < -m_osDecompParam.zeroTol && loopKount < m_osDecompParam.columnLimit){
				loopKount++;
				
				//kipp here is where the while loop goes
				//start while loop
				getColumns(m_yA, numARows, m_yB, numBRows, numNewColumns, 
						numNonz, cost,  rowIdx, values,  lowerBound);
				
				std::cout << "Lower Bound = " <<  lowerBound   << std::endl;

				
			
				for(k = 0; k < numNewColumns; k++){
					
					m_si->addCol( numNonz[ k], rowIdx[k], values[k],
							collb, colub,  cost[ k]) ;
					
					
					m_numColumnsGenerated++;
					
				}
			
				std::cout << " OBJ VALUE = " << m_si->getObjValue() << std::endl;
				
				std::cout << "m_zUB  = " <<  m_zUB << std::endl;
				
				if(lowerBound + m_si->getObjValue() > (1 - m_osDecompParam.optTolPerCent)*m_zUB) break;
			
				std::cout << std::endl  << std::endl << std::endl;
				std::cout << "CALL Solve  " << " Number of columns =  " <<  m_si->getNumCols() <<  std::endl;
				m_solver->solve();
				//m_si->initialSolve();
				std::cout << "Solution Status =  " << m_solver->osresult->getSolutionStatusType( 0 ) << std::endl;
				std::cout << "Number of solver interface columns =  " <<  m_si->getNumCols()  << std::endl;
				//m_numNodes is number of artificial variables
				
				numCols = m_si->getNumCols();
				
				if( numCols != m_osrouteSolver->m_numThetaVar ) throw ErrorClass("number variables in solver not consistent with master");
				if( numCols + m_osrouteSolver->m_numHubs >= m_maxCols) throw ErrorClass("we ran out of columns");
				
				for(i = 0; i <  numARows; i++){
					
					*(m_yA + i) = m_si->getRowPrice()[ i];
					
				}
							
				for(i = numARows; i <  numARows + numBRows; i++){
					
					*(m_yB + i - numARows) = m_si->getRowPrice()[ i];
					
				}
				
			}//end while on column generation
			//////////////////////////////////
			
			if( loopKount >=  m_osDecompParam.columnLimit)throw ErrorClass("we exceeded loop kount in column generation");
			
			//get a primal solution
			numCols = m_si->getNumCols();
			for(i=0; i < numCols; i++){
				*(m_theta + i) = m_si->getColSolution()[i];
			}
	
			
			numNewRows = 0;
			
			//do not get cuts if LP relaxation worse than upper bound
			if(m_si->getObjValue() < (1 - m_osDecompParam.optTolPerCent)*m_zUB) 
				getCuts(m_theta, numCols, numNewRows, numRowNonz, 
					colIdx,rowValues, rowLB, rowUB);
		
			
			if( numNewRows >= 1 ){
				
				isCutAdded = true;
				
				for(i = 0; i < numNewRows; i++){
					
					m_si->addRow(numRowNonz[ i], colIdx[ i], rowValues[ i], rowLB[ i], rowUB[ i] ) ;
					
					//add two  variables for this row so we can never be infeasible
					//m_si->addCol( numNonz, rowIdx[k], values[k],
					//		collb, colub,  cost[ k]) ;
					
					//add the artificial variable for the UB					
					rowArtVal = -1.0;
					rowArtIdx = m_si->getNumRows() - 1;
					//m_si->addCol(1, &rowArtIdx, &rowArtVal, 0, OSDBL_MAX, bigM);
					//m_si->addCol(1, &rowArtIdx, &rowArtVal, 0, 1, bigM);
					//add the artificial variable for the LB					
					rowArtVal = 1.0;
					//m_si->addCol(1, &rowArtIdx, &rowArtVal, 0, OSDBL_MAX, bigM);
					m_si->addCol(1, &rowArtIdx, &rowArtVal, 0, 1, bigM);
					m_numColumnsGenerated++;
							
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


bool OSColGenApp::branchAndBound( ){
	
	/** varConMap is a map that maps the index
	 * of an x_{ij} variable to the corresponding
	 * branching constraint number in the master
	 */
	std::map<int, int> varConMap;
	
	std::vector<OSNode*> nodeVec;
	std::vector<OSNode*>::iterator vit;
	
	
	std::map<int, OSNode*>::iterator mit;
	int bestNodeID;
	double bestNodeBound;

	
	OSNode *osnode = NULL;
	OSNode *osnodeLeftChild = NULL;
	OSNode *osnodeRightChild = NULL;
	
	bool bandbWorked;
	bandbWorked = true;
	int numCols;
	int i;
	int rowIdx;
	rowIdx = 0;
	
	bool leftNodeCreated = false;
	bool rightNodeCreated = false;
	

	m_numNodesGenerated = 0;
	try{
		
		//get the solution
		numCols = m_si->getNumCols();	
		//kipp -- imporant this is now found earliear.
		//for(i = 0; i < numCols; i++){	
		//	//get the LP relaxation
		//	std::cout  << "theta = " <<   *(m_theta + i) << std::endl; 
		//}
		
		//NOTE -- we must know theta here
		
		//create a branching cut 
		createBranchingCut(m_theta, numCols, varConMap, rowIdx);
		

		//// start left node ////
			
		osnodeLeftChild = createChild(osnode, varConMap, rowIdx, 1, 1);
		if(osnodeLeftChild != NULL){
			//finally set the nodeID
			//and record parent ID
			m_numNodesGenerated++;
			osnodeLeftChild->nodeID = m_numNodesGenerated;
			osnodeLeftChild->parentID = 0;
			//nodeVec.push_back( osnodeLeftChild);
			m_nodeMap.insert ( std::pair<int, OSNode*>(osnodeLeftChild->nodeID, osnodeLeftChild) );

		}
		
		//// end of left node ////
		
		//// start right node ////
		
		osnodeRightChild = createChild(osnode, varConMap, rowIdx, 0, 0);
		if(osnodeRightChild != NULL){
			//finally set the nodeID
			//and record parent ID
			m_numNodesGenerated++;
			osnodeRightChild->nodeID = m_numNodesGenerated;
			osnodeRightChild->parentID = 0;
			//nodeVec.push_back( osnodeRightChild);
			m_nodeMap.insert ( std::pair<int, OSNode*>(osnodeRightChild->nodeID, osnodeRightChild) );
		}
			
		//// end of right node ////
		
		// now loop
		//kipp -- make this an option

		std::cout << "ENTERING THE WHILE IN BRANCH AND BOUND" << std::endl;
		std::cout << "m_numNodesGenerated = " <<  m_numNodesGenerated  << std::endl;
		//while( (nodeVec.size() > 0) && (m_numNodesGenerated <= nodeLimit) ){
		while( (m_nodeMap.size() > 0) && (m_numNodesGenerated <= m_osDecompParam.nodeLimit) ){
			
			//kipp -- experimental
			
			if( m_si->getNumCols() > 100000) {
				std::cout << "DOING A MASTER RESET IN BRANCH AND BOUND" << std::endl;
				std::cout << "NUMBER OF COLUMNS BEFORE RESET = " << m_si->getNumCols() << std::endl;
				//resetMaster();
				std::cout << "NUMBER OF COLUMNS AFTER RESET = " << m_si->getNumCols() << std::endl;
			}
			
			leftNodeCreated = false;
			rightNodeCreated = false;
			//grab a node -- for now the last node, we do FIFO
			//osnode =  nodeVec.back();
			
			//let's loop and find node with the largest nodeID -- this will
			//corespond to fifo
			
			bestNodeID = 0;
			bestNodeBound = OSDBL_MAX;
			//mit->first is the the OSNode nodeID
			//mit->second is an OSNode
			for (mit = m_nodeMap.begin(); mit != m_nodeMap.end(); mit++ ){
				
				//FIFO criterions
				//if( mit->second->nodeID > bestNodeID) bestNodeID =  mit->second->nodeID;
				
				//Best Bound criterion
				if( mit->second->lpValue < bestNodeBound) {
					
					bestNodeBound = mit->second->lpValue;
					bestNodeID =  mit->first;
					//note same as:
					//bestNodeID =  mit->second->nodeID;
					
					
				}
				
			}

			//get the node
			mit = m_nodeMap.find( bestNodeID );
			if(mit == m_nodeMap.end() ) throw ErrorClass("a node selection problem in branch and bound");
			osnode = mit->second;
			
			if( osnode->lpValue < (1 - m_osDecompParam.optTolPerCent)*m_zUB - m_osDecompParam.zeroTol){
			
				
				//create a branching cut 
				createBranchingCut(osnode->thetaIdx, osnode->theta, osnode->thetaNumNonz, 
						varConMap, rowIdx);
				
				// create children
				//create the left node
				osnodeLeftChild = createChild(osnode, varConMap, rowIdx, 1, 1);
				if(osnodeLeftChild != NULL){
					//finally set the nodeID
					//and record parent ID
					m_numNodesGenerated++;
					osnodeLeftChild->nodeID = m_numNodesGenerated;
					osnodeLeftChild->parentID = osnode->nodeID;
					leftNodeCreated = true;
				}
				
				//create the right node
				osnodeRightChild = createChild(osnode, varConMap, rowIdx, 0, 0);
				if(osnodeRightChild != NULL){
					//finally set the nodeID
					//and record parent ID
					m_numNodesGenerated++;
					osnodeRightChild->nodeID = m_numNodesGenerated;
					osnodeRightChild->parentID = osnode->nodeID;
					rightNodeCreated = true;
				}
				
				
				//nodeVec.erase( nodeVec.end() - 1) ;
				m_nodeMap.erase( mit);
				delete osnode;
				
				//if( leftNodeCreated == true) nodeVec.push_back( osnodeLeftChild) ;
				//if( rightNodeCreated == true) nodeVec.push_back( osnodeRightChild) ;
				
				if( leftNodeCreated == true) 
					m_nodeMap.insert ( std::pair<int, OSNode*>(osnodeLeftChild->nodeID, osnodeLeftChild) ) ;
				
				if( rightNodeCreated == true) 
					m_nodeMap.insert ( std::pair<int, OSNode*>(osnodeRightChild->nodeID, osnodeRightChild) ) ;

				 
			}else{
				
				//fathom node by virtue of the upper bound
				std::cout << "FATHAM BY UPPER BOUND " << std::endl;
				//nodeVec.erase( nodeVec.end() - 1) ;
				m_nodeMap.erase( mit);
				delete osnode;

			}//end if on lp bound check
			
			//kipp -- critical reset upper and lower bounds 
			//kipp don't forget to erase the parent node
			
		}//end the while
		

		
		if(m_numNodesGenerated > 0){
			
			m_zLB = (1 - m_osDecompParam.optTolPerCent)*m_zUB;
		}else{
			
			m_zLB = m_zUB;
		}
		
		std::cout <<  std::endl << std::endl;
		
		std::cout << "NUMBER OF REMAINING DANGLING NODES  = " << m_nodeMap.size() << std::endl;
		
		/*
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
		*/
		
		
		
		
		for ( mit = m_nodeMap.begin() ; 
				mit != m_nodeMap.end(); mit++ ){
			
			std::cout << "NODE ID VALUE = " << mit->second->nodeID << " " ;
			std::cout << "  NODE LP VALUE = " << mit->second->lpValue << std::endl;
			
			for(i = 0; i < mit->second->rowIdxNumNonz; i++){
				
				std::cout << "CONSTRAINT =  " << mit->second->rowIdx[ i]  ;
				std::cout << "  CONSTRAINT LB = " <<  mit->second->rowLB[ i]  ;
				std::cout << "  CONSTRAINT UB = " <<  mit->second->rowUB[ i]  << std::endl;
			}
				
			if(  mit->second->lpValue < m_zLB) m_zLB =  mit->second->lpValue;
	
			
		}
		m_nodeMap.clear();
		
		//exit( 1);
	
		return bandbWorked;

	} catch (const ErrorClass& eclass) {
		
		throw ErrorClass(eclass.errormsg);

	}		

}// end branchAndBound

OSNode* OSColGenApp::createChild(const OSNode *osnodeParent, std::map<int, int> &varConMap,
		const int rowIdx, const double rowLB, const double rowUB){
	
	OSNode *osnodeChild;
	osnodeChild = NULL;
	int numRows;
	int numCols;
	
	int tmpColNum ;
	int tmpRowNum  ;
	
	std::map<int, int>::iterator mit;
	std::vector<std::pair<int, int> >::iterator vit;

	
	int i;
	int k;
	int childRowIdxNumNonz;
	childRowIdxNumNonz = 0;
	


	//we want to store the solution vector (theta space)
	//in sparse format
	int thetaNumNonz;

	
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
		std::cout << "CALL SOLVE FROM CREATE CHILD "  << std::endl;
		//kipp -- important, you really need to verify that an optimal solution was obtained!!!
		if(osnodeParent != NULL){
			
			tmpColNum = m_si->getNumCols() ;
			tmpRowNum = m_si->getNumRows() ;
			int *tmpColParent = new int[ tmpColNum];
			int *tmpRowParent = new int[ tmpRowNum ];
			
			for(k = 0; k < tmpColNum; k++){
				
				tmpColParent[ k] = 0;
			}
			
			for(k = 0; k < tmpRowNum; k++){
				
				tmpRowParent[ k] = 0;
			}
			
			//for(vit = osnodeParent->colBasisStatus.begin(); 
			//		vit != osnodeParent->colBasisStatus.end(); vit++){
				
				
			//	tmpColParent[ (*vit).first ] = 5;
				
				
			//}
			for(k = 0; k < osnodeParent->colBasisStatus.size(); k++){
				
				tmpColParent[osnodeParent->colBasisStatus[k].first  ] = osnodeParent->colBasisStatus[k].second;
			}
			
			m_si->setBasisStatus(tmpColParent, tmpRowParent);
			//m_si->initialSolve();
			//std::cout << "DONE WITH INITIAL SOLVE" << std::endl;
			//solveRestrictedMasterRelaxation(NULL, NULL);
			solveRestrictedMasterRelaxation(tmpColParent, tmpRowParent);
			
			delete[] tmpColParent;
			tmpColParent = NULL;
			delete[] tmpRowParent;
			tmpRowParent = NULL;
			
			//solveRestrictedMasterRelaxation( osnodeParent->colBasisStatus, 
			//		osnodeParent->rowBasisStatus);
		} else { 
			
			solveRestrictedMasterRelaxation(NULL, NULL);
		}
		
		
		std::cout << std::endl << std::endl;
		std::cout << "FINISH SOLVING THE MASTER "  << std::endl;
		

		//
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
		if( m_si->getObjValue() < (1 - m_osDecompParam.optTolPerCent)*m_zUB - m_osDecompParam.zeroTol) {
			// okay cannot fathom based on bound try integrality
			std::cout << "MESSAGE: WE CANNOT FATHOM THE CHILD BASED ON UPPER BOUND " << std::endl;
			numCols = m_si->getNumCols();
			numRows = m_si->getNumRows();
			thetaNumNonz = 0;
			
			for(i = 0; i < numCols; i++){	
				//get the LP relaxation
				*(m_theta + i) = m_si->getColSolution()[i];	
				if( *(m_theta + i) > m_osDecompParam.zeroTol) thetaNumNonz++;
				
			}
			if( isInteger( m_theta, numCols, m_osDecompParam.zeroTol) == true){
				//fathom by integrality
				std::cout << "MESSAGE:  WE HAVE AN INTEGRALITY FATHOM " << m_zUB << std::endl;
				if( m_zUB > m_si->getObjValue() ){
					
					m_zUB = m_si->getObjValue() ;
					//clear out out solution vector
					if( m_zOptIndexes.size() > 0) m_zOptIndexes.clear();
					
					for(i = 0; i < numCols; i++){
						
						if( *(m_theta + i) > m_osDecompParam.zeroTol) m_zOptIndexes.push_back( i) ;
						
					}
				}
				
			}else{
				//create the child node
				std::cout << "MESSAGE:  WE ARE CREATING A CHILD NODE WITH NUMBER COLUMNS = "<<  numCols << std::endl;
				osnodeChild = new OSNode(childRowIdxNumNonz,  thetaNumNonz );
				
				
				//set the basis
				tmpColNum = m_si->getNumCols() ;
				tmpRowNum = m_si->getNumRows() ;
				int *tmpColChild = new int[ tmpColNum];
				int *tmpRowChild = new int[ tmpRowNum ];
				
				m_si->getBasisStatus(tmpColChild, tmpRowChild);
				
				for(k = 0; k < tmpColNum; k++){
					
					osnodeChild->colBasisStatus.push_back(std::make_pair(k, tmpColChild[ k]) );
					
				}
				
				for(k = 0; k < tmpRowNum; k++){
					
					osnodeChild->rowBasisStatus.push_back(std::make_pair(k, tmpRowChild[ k]) );
					
				}
				
				delete[] tmpColChild;
				tmpColChild = NULL;

				delete[] tmpRowChild;
				tmpRowChild = NULL;
				
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
				thetaNumNonz = 0;
				for(i = 0; i < numCols; i++){
					
					if( *(m_theta + i) > m_osDecompParam.zeroTol){
						
						osnodeChild->thetaIdx[ thetaNumNonz] = i;
						osnodeChild->theta[ thetaNumNonz] = *(m_theta + i);
						
						thetaNumNonz++;
						//std::cout <<  "x variables for column "  << i  << std::endl;
						//for(int j = m_osrouteSolver->m_thetaPnt[ i ];  j < m_osrouteSolver->m_thetaPnt[ i + 1] ;  j++){
						//	std::cout <<  m_osrouteSolver->m_variableNames[ m_osrouteSolver->m_thetaIndex[  j] ]  << " = "  <<  *(m_theta + i) << std::endl;	
						//}
					}
					
					
					
				}
			}//end else on isInteger
		}// end if on upper bound test

		std::cout << std::endl << std::endl;
		return osnodeChild;
	
	} catch (const ErrorClass& eclass) {
	

		throw ErrorClass(eclass.errormsg);

	}		
	
}//end createChild


void OSColGenApp::createBranchingCut(const int* thetaIdx, const double* theta, 
		const int numThetaVar, std::map<int, int> &varConMap, int &rowIdx){
	
	int varIdx;
	int numNonz;
	int* indexes;
	double* values;	
	

	
	
	//kipp -- I would like to use OSDBL_MAX but Clp likes this better
	//double bigM  = 1.0e24;
	double bigM  = m_osDecompParam.artVarCoeff;
	double rowArtVal ;
	
	std::map<int, int>::iterator mit;
	
	//get the branching cut information
	
	//
	for(int i = 0; i < numThetaVar; i++ ){
		
		std::cout << "theta idx = " << thetaIdx[ i] << "  theta = " << theta[ i] << std::endl;
	}
	
	m_osrouteSolver->getBranchingCut(thetaIdx, theta, numThetaVar, 
			varConMap, varIdx, numNonz, indexes,  values);
	
	
		
	std::cout << "varIDX = " << varIdx << std::endl;
	std::cout << "numNonz1 = " << numNonz << std::endl;	
	
	
	//for(int i = 0; i < numNonz; i++){
	//	std::cout <<  "x variables for column "  << indexes[i]  << std::endl;
	//	for(int j = m_osrouteSolver->m_thetaPnt[ indexes[ i] ];  j < m_osrouteSolver->m_thetaPnt[ indexes[ i] + 1] ;  j++){
	//		std::cout <<  m_osrouteSolver->m_variableNames[ m_osrouteSolver->m_thetaIndex[  j] ]  << " = "  << theta[ thetaNumNonz]  << std::endl;
	//	}	
	//}

	//if numNonz is greater than zero:
	// 1) add add new variable to map -- at this point varConMap is empty
	// 2) add constraint then add to the formulation
	// 3) add  variables
	
	if( numNonz >0){

		
		//add the row
		//make upper and lower bound 0 and 1 first 
		m_si->addRow(numNonz, indexes, values, 0, 1) ;
		
		//add the artificial variables
		//add the artificial variable for the UB					
		rowArtVal = -1.0;
		rowIdx = m_si->getNumRows() - 1;
		
		//m_si->addCol(1, &rowIdx, &rowArtVal, 0, 1.0, bigM);
		//m_si->addCol(1, &rowIdx, &rowArtVal, 0, OSDBL_MAX, bigM);
		//add the artificial variable for the LB					
		rowArtVal = 1.0;
		m_si->addCol(1, &rowIdx, &rowArtVal, 0, 1.0, bigM);
		//m_si->addCol(1, &rowIdx, &rowArtVal, 0, OSDBL_MAX, bigM);
		m_numColumnsGenerated++;
		
		//insert into map -- this is the first variable
		varConMap.insert ( std::pair<int, int>(varIdx , rowIdx) );
		
		
		
		
	} else{
		//the variable varIdx is in the map
		//get the constraint associated with this variable
		//throw and exception if varIdx not a key
	
		mit = varConMap.find( varIdx);
		if( mit == varConMap.end() ) throw ErrorClass("in branchAndBound getBranchingCut() returned inconsistent value for varIdx");
				else rowIdx = mit->second;


	}//end if on numNonz
	
	
	
}//end createBranchingCut Sparse



void OSColGenApp::createBranchingCut(const double* theta, 
		const int numThetaVar, std::map<int, int> &varConMap, int &rowIdx){
	
	int varIdx;
	int numNonz;
	int* indexes;
	double* values;	
	
	//kipp -- I would like to use OSDBL_MAX but Clp likes this better
	//double bigM  = 1.0e24;
	double bigM  = m_osDecompParam.artVarCoeff;
	double rowArtVal ;
	
	std::map<int, int>::iterator mit;
	
	//get the branching cut information
	m_osrouteSolver->getBranchingCut( theta, numThetaVar, 
			varConMap, varIdx, numNonz, indexes,  values);

		
	std::cout << "varIDX2 = " << varIdx << std::endl;
	std::cout << "numNonz2 = " << numNonz << std::endl;	
	
	
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
		
		//m_si->addCol(1, &rowIdx, &rowArtVal, 0, 1.0, bigM);
		//m_si->addCol(1, &rowIdx, &rowArtVal, 0, OSDBL_MAX, bigM);
		//add the artificial variable for the LB					
		rowArtVal = 1.0;
		
		m_si->addCol(1, &rowIdx, &rowArtVal, 0, 1.0, bigM);
		//m_si->addCol(1, &rowIdx, &rowArtVal, 0, OSDBL_MAX, bigM);
		m_numColumnsGenerated++;
		
		//insert into map -- this is the first variable
		varConMap.insert ( std::pair<int,int>(varIdx , rowIdx) );
		
		
		
		
	} else{
		//the variable varIdx is in the map
		//get the constraint associated with this variable
		//throw and exception if varIdx not a key
	
		mit = varConMap.find( varIdx);
		if( mit == varConMap.end() ) throw ErrorClass("in branchAndBound getBranchingCut() returned inconsistent value for varIdx");
				else rowIdx = mit->second;


	}//end if on numNonz
	
	
	
}//end createBranchingCut Dense


void  OSColGenApp::resetMaster(){
	
	//kipp -- temp stuff here delete later
	//////
	
	//std::map<int, int> inVars;
	std::map<int, int>::iterator mit;
	std::vector<int>::iterator vit;
	std::map<int, OSNode*>::iterator mit2;
	int i;
	int kount = 0;
	
	try{

		//first add the columns corresponding to the root node solution
		
		//for(i = 0; i < m_si->getNumCols(); i++){
			
			//if( m_si->getColSolution()[i] > m_osDecompParam.zeroTol) inVars.insert( std::pair<int, int>(i, kount++) );
			//if( m_si->getObjCoefficients()[i] < 10000) inVars.insert( std::pair<int, int>(i, kount++) );
		//}	

		for(vit = m_zOptRootLP.begin() ; vit != m_zOptRootLP.end(); vit++){
			
			inVars.insert( std::pair<int, int>(*vit, kount++) );
			
		}
		
		

		//next add the integer varaibles
		for(vit = m_zOptIndexes.begin() ; vit != m_zOptIndexes.end(); vit++){
			
			if( inVars.find( *vit ) == inVars.end() ) inVars.insert( std::pair<int, int>(*vit, kount++) );
			
			//std::cout << "VARIABLE INDEX =  " << *vit << std::endl;
			
			//for(int k = m_osrouteSolver->m_thetaPnt[*vit]; k <  m_osrouteSolver->m_thetaPnt[*vit + 1]; k++){
				
				//std::cout << m_osrouteSolver-> m_variableNames[ m_osrouteSolver->m_thetaIndex[ k] ] <<  std::endl;
				
			//}

		}
		
		

		
		//now loop over the nodes in the branch and bound tree
	
		for(mit2 = m_nodeMap.begin(); mit2 !=m_nodeMap.end(); mit2++){
			

			for(i = 0; i < mit2->second->thetaNumNonz; i++){
				
				if( inVars.find( mit2->second->thetaIdx[ i] ) == inVars.end() ) 
					inVars.insert( std::pair<int, int>(mit2->second->thetaIdx[ i], kount++) );
				
			}
		}

		
		
		//for(mit = inVars.begin();  mit != inVars.end(); mit++)  std::cout << "mit->first " <<   mit->first << "  mit->second   " << mit->second   << std::endl;	
		m_osrouteSolver->resetMaster( inVars, m_si );
		//for(mit = inVars.begin();  mit != inVars.end(); mit++)  std::cout << "mit->first " <<   mit->first << "  mit->second   " << mit->second   << std::endl;
			
		int numVars =   m_osrouteSolver->m_osinstanceMaster->getVariableNumber();
		double *tmpVals = NULL;
		tmpVals = new double[ numVars];
		
		for(i = 0;  i < numVars; i++)  tmpVals[ i ] = 0;
			
		for(mit = inVars.begin(); mit != inVars.end(); mit++){
			//tmpVals now point to old index values
			tmpVals[ mit->second] = m_theta[ mit->first] ;
		}
		
		
		for(i = 0; i  < numVars; i++) m_theta[ i] = tmpVals[ i] ;
		
		//reset the nodes in the branch and bound tree
		
		for(mit2 = m_nodeMap.begin(); mit2 !=m_nodeMap.end(); mit2++){

			
			for(i = 0; i < mit2->second->thetaNumNonz; i++){
				
				//inVars[mit2->second->thetaIdx[ i] ]
				if( inVars.find( mit2->second->thetaIdx[ i] ) == inVars.end() ) throw ErrorClass("index problem in resetMaster");

				//kipp check to make sure we do not index an aritifical variable
				mit2->second->thetaIdx[ i] =  inVars[ mit2->second->thetaIdx[ i] ] ;
				//if( inVars.find( mit2->second->thetaIdx[ i] ) != inVars.end() ) 
				//	inVars.insert( std::pair<int, int>(mit2->second->thetaIdx[ i], kount++) );
				
			}
			

		}
		
		//reset the indexes of variables in the current integer incumbent
		for(vit = m_zOptIndexes.begin() ; vit != m_zOptIndexes.end(); vit++) *vit = inVars[ *vit ];
		
		
		//reset the indexes of variables in the root LP
		for(vit = m_zOptRootLP.begin() ; vit != m_zOptRootLP.end(); vit++) *vit = inVars[ *vit ];

		///now delete stuff and reset
		
		delete m_solver;
		m_osinstanceMaster = m_osrouteSolver->m_osinstanceMaster;
		m_solver = new CoinSolver();

		//kipp -- later have clp be an option
		//I guess for now it must be an Osi solver
		m_solver->sSolverName ="cbc";
		//std::cout << m_osinstanceMaster->printModel(  ) << std::endl;
		m_solver->osinstance = m_osrouteSolver->m_osinstanceMaster;
		m_solver->osoption = m_osoption;
		
		m_solver->buildSolverInstance();
	
		//get the solver interface
		m_si = m_solver->osiSolver;
		
		if(m_si->getNumCols() !=  numVars) throw ErrorClass("there is an inconsistency in the the model rebuid in resetMaster");
		
		std::cout << "OSINTANCE NUMBER OF COLUMNS = "  << m_osrouteSolver->m_osinstanceMaster->getVariableNumber() << std::endl;
		std::cout << "OSINTANCE NUMBER OF ROWS = "  << m_osrouteSolver->m_osinstanceMaster->getConstraintNumber() << std::endl;
		std::cout << "SOLVER INTERFACE NUMBER OF COLUMNS = "  << m_si->getNumCols() << std::endl;
		std::cout << "SOLVER INTERFACE NUMBER OF ROWS = "  <<m_si->getNumRows() << std::endl;
		
		
		//kipp this is a check, DO NOT do in production run
		
		
		
		double lpVal;
		
		for(mit2 = m_nodeMap.begin(); mit2 !=m_nodeMap.end(); mit2++){

			lpVal = 0;
			
			for(i = 0; i < mit2->second->thetaNumNonz; i++){
				
				lpVal +=  m_si->getObjCoefficients()[  mit2->second->thetaIdx[ i] ]*mit2->second->theta[ i];
				
				
			}
			
			if( ( lpVal - mit2->second->lpValue > m_osDecompParam.zeroTol )  ||   
					(mit2->second->lpValue - lpVal > m_osDecompParam.zeroTol )	) throw ErrorClass( "uh oh, problem with node lp value" );
			
			//std::cout << "lpVal = " << lpVal <<  "  lpValue = " << mit2->second->lpValue << std::endl ;
		}		
		
		
		//end check
		
		//m_si->writeLp( "gailTest2" );
		
		delete[] tmpVals;
		tmpVals = NULL;
	
	} catch (const ErrorClass& eclass) {

		throw ErrorClass(eclass.errormsg);

	}	

	
}//end resetMaster




