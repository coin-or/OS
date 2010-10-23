/* $Id: OSColGenApp.h 3038 2009-11-07 11:43:44Z kmartin $ */
/** @file OSBlockBearcatSolver.h
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

#ifndef OSCOLGENAPP_H
#define OSCOLGENAPP_H

// --------------------------------------------------------------------- //
#include "OSDataStructures.h"
#include "OSDefaultSolver.h" 
#include "OSrLReader.h"
#include "OSOption.h"
#include "OSInstance.h"
#include "OSoLReader.h"


#include<map>
// --------------------------------------------------------------------- //
/*!
 * \class 
 * OSColGenApp
 * 
 *
 */
// --------------------------------------------------------------------- //
class OSColGenApp {
public:
	

	OSInstance *m_osinstanceMaster;
	OSOption *m_osoption;
	OSResult *m_osresult;
	
	//variables for the q-route dynamic programming solution
	int m_numberOfVar;
	int m_numHubs;
	int m_numNodes;
	int m_routeCapacity;
	int m_minDemand;
	int* m_demand;
	

	double** m_u; 
	double** m_v;
	int** m_px;
	int** m_tx;
	double** m_g;
	
	int* m_varIdx;
	//end variables for the q-route  dynamic programming solution
	
	//variables for the outer dynamic program 
	//get the optimal l value for each route
	int* m_optL; //size is number of routes
	int* m_optD; //size is number of routes
	double** m_vv;
	int** m_vvpnt;
	int m_totalDemand;
	
	int m_upperBoundL;
	
	int m_numberOfSolutions;
	
	//file name of the osil instance of the problem used to 
	//generate the initial restricted master
	std::string m_initOSiLFile;
	
	//kipp get rid of this
	
	int m_whichBlock;
	
	double m_trueMin;
	//variables for the outer dynamic program 
	
	std::vector<IndexValuePair*>  m_primalVals;
	
	std::map<int, std::map<int, std::vector<int> > > m_initSolMap;
	
	/** kipp -- document */
	// note -- this c vector is only for hub k
	double qrouteCost(const int& k, const int& l, const double* c, int* kountVar) ;
	
	//this c vector is for the entire cost vector
	void getOptL(const  double* c) ;
	
	void generateInitialRestrictedMaster( );
	
	void getOptions( OSOption *osoption);
	
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
	void solveMaster(const double *cost, std::vector<IndexValuePair*> *solIndexValPair, 
			double *optVal, const double& convexDual) ;
	
	
	
	void generateCuts(const  double* x) ;
	
	void generateColumns(const  double* u) ;
	


	/**
	 *
	 * Default Constructor. 
	 */	
	OSColGenApp();
	
	/**
	 *
	 * Second Constructor. 
	 */	
	OSColGenApp( OSOption *osption);
	

	/**
	 *
	 * Default destructor. 
	 */	
	~OSColGenApp();	

	//
};//end class OSColGenApp

#endif

