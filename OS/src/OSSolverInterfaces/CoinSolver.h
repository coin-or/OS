/** @file CoinSolver.h
 * 
 * @author  Robert Fourer,  Jun Ma, Kipp Martin, 
 * @version 1.0, 10/05/2005
 * @since   OS1.0
 *
 * \remarks
 * Copyright (C) 2005, Robert Fourer, Jun Ma, Kipp Martin,
 * Northwestern University, and the University of Chicago.
 * All Rights Reserved.
 * This software is licensed under the Common Public License. 
 * Please see the accompanying LICENSE file in root directory for terms.
 * 
 */ 
 
#ifndef COINSOLVER_H 
#define COINSOLVER_H

#include "OSConfig.h" 
#include "DefaultSolver.h"
#include "OSrLWriter.h"
#include <CoinPackedMatrix.hpp>
#include <OsiSolverInterface.hpp>
#include <OsiClpSolverInterface.hpp> 
#include <OsiCbcSolverInterface.hpp> 


#ifdef COIN_HAS_CPX
#include <OsiCpxSolverInterface.hpp>
#endif

#ifdef COIN_HAS_GLPK
#include <OsiGlpkSolverInterface.hpp>
#endif

#include <string>


/*! \class CoinSolver class.h "CoinSolver.h"
 *  \brief Implements a solve method for the Coin solvers.
 *
 * This class implements a solve method for the Coin solvers
 * It reads an OSInstance object and puts into the Coin OSI format
 */

class CoinSolver : public DefaultSolver{  
	
public:

	/*! \fn  CoinSolver::CoinSolver() 
	 *  \brief The class contructor.
	 */ 
	CoinSolver();
	
	/*! \fn  CoinSolver::~CoinSolver() 
	 *  \brief The class destructor.
	 */ 
	~CoinSolver();
	
	/*! \fn void CoinSolver::solve() 
	 *  \brief The implementation of the virtual functions. 
	 *  \return void.
	 */	
	virtual void  solve();
	
	/*! \fn string CoinSolver::optimize() 
	 *  \brief This function calls solver->loadProblem. 
	 *  \return true if there was not an optimization error.
	 */ 
	bool optimize();
	
	/*! \fn bool CoinSolver::setCoinPackedMatrix() 
	 *  \brief  Create a CoinPackedMatrix
	 *  \return true if a CoinPackedMatrix successfully created.
	 */ 
	bool setCoinPackedMatrix();
	
	/*! \fn string CoinSolver::getCoinSolverType(string osol_)
	 *  \brief  Get the solver type, e.g. clp or glpk
	 *  \param  a string that is an instance of OSoL
	 *  \return a string which contains the value of clp or glpk.
	 */ 
	std::string getCoinSolverType(std::string osol_);
	
	/*! \fn string CoinSolver::dataEchoCheck()
	 *  \brief Print out problem parameters
	 *  \return void
	 */ 
	void dataEchoCheck();
	

	
private:



	/** 
	 * m_OsiSolver is the osi solver object -- in this case clp, glpk, cbc, or cplex	 
	 */	
 	OsiSolverInterface *m_OsiSolver;
	
	/** 
	 * m_CoinPackedMatrix is a Coin Packed Matrix ojbect
	 */
	CoinPackedMatrix *m_CoinPackedMatrix ;
	
	/** osrlwriter object used to write osrl from and OSResult object */
	OSrLWriter  *osrlwriter;

};
#endif
