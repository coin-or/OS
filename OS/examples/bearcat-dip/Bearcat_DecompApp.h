//===========================================================================//
// This file is part of the Decomp Solver Framework.                         //
//                                                                           //
// Decomp is distributed under the Common Public License as part of the      //
// COIN-OR repository (http://www.coin-or.org).                              //
//                                                                           //
// Author: Matthew Galati, Lehigh University                                 //
//                                                                           //
// Copyright (C) 2002-2008, Lehigh University, Matthew Galati, and Ted Ralphs//
// All Rights Reserved.                                                      //
//===========================================================================//

#ifndef BEARCAT_DECOMPAPP_INCLUDED
#define BEARCAT_DECOMPAPP_INCLUDED

// --------------------------------------------------------------------- //
#include "DecompApp.h"
#include "DecompParam.h"

// --------------------------------------------------------------------- //
#include "OS_DipInterface.h"
#include "Bearcat_DecompParam.h"


// --------------------------------------------------------------------- //
/*!
 * \class Bearcat_DecompApp
 * A DecompApp for solving the 
 *     Bearcat Problem.
 * 
 * \see
 * DecompApp
 *
 */
// --------------------------------------------------------------------- //
class Bearcat_DecompApp: public DecompApp {
public:
	/** Class id tag (for log / debugging). */
	const string m_classTag;

	/** Bearcat problem instance data */
	OS_DipInterface m_osInterface;

	/** Application specific parameters. */
	Bearcat_Param m_appParam;

	/** The model objective coefficients (original space). */
	double * m_objective;
	
	   /** The model constraint systems used for different algos. */
	   DecompConstraintSet *          m_modelC;
	   map<int, DecompConstraintSet*> m_modelR;

	/** The various model constraint systems used for different 
	 algorithms, keyed by a unique string (model name). */
	map<string, DecompConstraintSet*> m_models;
	
	/** number of block. */
	int  m_numBlocks;

public:
	/* @name Inherited (from virtual) methods. */
	/** Solve the relaxed problem. */
	//DecompSolverStatus solveRelaxed(const int   whichBlock,
	// const double        * redCostX,
	//				   const double          convexDual,
	//				   list<DecompVar*>    & vars);   

	/** Print an original column (format for this app). */
	//void printOriginalColumn(const int index, ostream * os = &cout) const;

public:
	/** @name Helper functions (public). */
	
	
	/** Find the active columns for some block. */
	void findActiveColumns(const vector<int> & rowsPart,
		set<int> & activeColsSet);
	   

	/** Initialize application. */
	void initializeApp(UtilParameters & utilParam);

	/** Create model parts. */
	void createModels();
	
	DecompConstraintSet * createModelPart(const int nRowsPart,
			const int * rowsPart);
	
	void createModelPart(DecompConstraintSet * model, const int nRowsPart,
			const int * rowsPart);
	
	void createModelPartSparse(DecompConstraintSet * model,
			const int nRowsPart, const int * rowsPart);

	//void createModelMasterOnlys2(vector<int> & masterOnlyCols);

	//void readInitSolutionFile(DecompVarList & initVars);
	
	/* @name Inherited (from virtual) methods. */
	int generateInitVars(DecompVarList & initVars); 
	
	
	void createModelMasterOnlys2(vector<int> & masterOnlyCols);


	/** @name Constructor and Destructor */

	/** Default constructor. Takes an instance of UtilParameters */
	Bearcat_DecompApp(UtilParameters & utilParam) :
		DecompApp(utilParam), m_classTag("Bearcat-APP"), m_objective(NULL) {
		initializeApp(utilParam);
	}

	virtual ~Bearcat_DecompApp() {
		std::cout << "GAIL IS IN BEARCAT DECOMP DESTRUCTOR" << std::endl;
		UTIL_DELARR(m_objective);
		UTIL_DELPTR(m_modelC);
		UtilDeleteMapPtr(m_modelR);
	}
	
	

	   
};

#endif
