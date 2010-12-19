/* $Id: OSColGenApp.h 3038 2009-11-07 11:43:44Z kmartin $ */
/** @file OSColGenApp.h
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
#include "OSCoinSolver.h"
#include "OSRouteSolver.h"



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
	
	OSRouteSolver *m_osrouteSolver;
	
	CoinSolver *m_solver;

	OsiSolverInterface *m_si;
	
	
	/** m_zUB is the upper bound */
	double m_zUB;
	
	/** m_zLB is the lower bound */
	double m_zLB;
	
	
	/** m_yA is the dual values for the initial restricted constraints */
	double *m_yA;
	
	/** m_yB is the dual for the cuts that get added */
	double *m_yB;
	
	/** m_theta is the primal values in the  master */
	double* m_theta;
	
	/** m_maxCols is the maximum number of columns we can have */
	int m_maxCols;
	
	/** kipp -- document */
	void solveRestrictedMasterRelaxation();
	
	void getInitialRestrictedMaster( );
	
	void getInitialRestrictedMaster2( );
	
	void getOptions( OSOption *osoption);
	
	/** the method that invokes and controls
	 * branch and bound
	 */
	
	
	/** return true if nothing goes wrong */
	bool branchAndBound();
	
	void solve();
	
	/**
	 * 
	 * INPUT:
	 * double* thetaVar -- the vector of primal master values
	 * int numThetaVar -- size of master primal vector
	 * tol -- is the tolerance on 0/1
	 * 
	 * return true if the solution is integer
	 */
	bool isInteger( const double *thetaVar, const int numThetaVar, 
			const double tol);
	
	/**
	 * RETURN VALUES: 
	 * int numNewRows -- number of new rows generated
	 * int* numNonz -- number of nonzeros in each row
	 * double** colIdx -- vectors column indexes of new rows
	 * double** values -- vectors of matrix coefficient values of new rows
	 * double* rowLB -- vector of row lower bounds
	 * double* rowUB -- vector of row upper bounds
	 * 
	 * INPUT:
	 * double* thetaVar -- the vector of primal master values
	 * int numThetaVar -- size of master primal vector
	 */
	void getCuts(const  double* thetaVar, const int numThetaVar,
			int &numNewRows, int*  &numNonz, int** &colIdx,
			double** &values, double* &rowLB, double* &rowUB) ;	
	
	/**
	 * RETURN VALUES: 
	 * int numNewColumns -- number of new columns generated
	 * int* numNonz -- number of nonzeros in each column
	 * double* cost -- the objective function coefficient on each new column
	 * double** rowIdx -- vectors row indexes of new columns
	 * double** values -- vectors of matrix coefficient values of new columns
	 * double lowerBound -- the lowerBound
	 * 
	 * INPUT:
	 * double* yA -- the vector of dual values on the coupling constraints
	 * int numARows -- size of the yA dual vector
	 * double* yB -- the vector of dual values on the tour breaking constaints
	 * int numBRows -- size of the yA dual vector
	 */
	void getColumns(const  double* yA, const int numARows,
			const  double* yB, const int numBRows,
			int &numNewColumns, int* &numNonz, double* &cost, 
			int** &rowIdx, double** &values, double &lowerBound) ;
	
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

