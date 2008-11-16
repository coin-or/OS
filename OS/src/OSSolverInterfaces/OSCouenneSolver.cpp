/** @file CouenneSolver.cpp
 * 
 * \brief This file defines the Couenne Solver class.
 * \detail Read an OSInstance object and convert in Ipopt data structures
 *
 * @author  Jun Ma, Horand Gassmann, Kipp Martin, 
 * @version 1.1, 11/04/2008
 * @since   OS1.0
 *
 * \remarks
 * Copyright (C) 2008, Jun Ma, Horand Gassmann, Kipp Martin,
 * Northwestern University, Dalhousie University and the University of Chicago.
 * All Rights Reserved.
 * This software is licensed under the Common Public License. 
 * Please see the accompanying LICENSE file in root directory for terms.
 * 
 */
#include <iostream>



#include "OSDataStructures.h"
#include "OSParameters.h" 
#include "OSCommonUtil.h"
#include "OSMathUtil.h"

//#include "BonOsiTMINLPInterface.hpp"
//#include "BonCbc.hpp"

#include "OSCouenneSolver.h"

using namespace Bonmin;


#include "BonminConfig.h"
#include "BonCouenneInterface.hpp"
#include "BonIpoptSolver.hpp"

#include "BonCouenneSetup.hpp"




using std::cout; 
using std::endl; 
using std::ostringstream;


CouenneSolver::CouenneSolver() {
using namespace  Ipopt;
	osrlwriter = new OSrLWriter();
	osresult = new OSResult();
	m_osilreader = NULL;
	couenneErrorMsg = "";
	Bab bb;
	bb.setUsingCouenne (true);
	CouenneSetup bonmin;


} 

CouenneSolver::~CouenneSolver() {
	#ifdef DEBUG
	cout << "inside BonminSolver destructor" << endl;
	#endif
	if(m_osilreader != NULL) delete m_osilreader;
	m_osilreader = NULL;
	delete osresult;
	osresult = NULL;
	delete osrlwriter;
	osrlwriter = NULL;
	//delete osinstance;
	//osinstance = NULL;
	#ifdef DEBUG
	cout << "leaving BonminSolver destructor" << endl;
	#endif
}











void CouenneSolver::buildSolverInstance() throw (ErrorClass) {
	try{
	/*		
		if(osil.length() == 0 && osinstance == NULL) throw ErrorClass("there is no instance");
		if(osinstance == NULL){
			m_osilreader = new OSiLReader();
			osinstance = m_osilreader->readOSiL( osil);
		}
		// Create a new instance of your nlp 
		tminlp = new BonminProblem( osinstance, osoption, osresult);
		this->bCallbuildSolverInstance = true;
		//Now initialize from tminlp
		bonmin.initialize( GetRawPtr(tminlp) );
		*/
	}
	catch(const ErrorClass& eclass){
		std::cout << "THERE IS AN ERROR" << std::endl;
		osresult->setGeneralMessage( eclass.errormsg);
		osresult->setGeneralStatusType( "error");
		osrl = osrlwriter->writeOSrL( osresult);
		throw ErrorClass( osrl) ;
	}				
}//end buildSolverInstance() 



void CouenneSolver::setSolverOptions() throw (ErrorClass) {
	try{
		
	}
	
	catch(const ErrorClass& eclass){
		std::cout << "THERE IS AN ERROR" << std::endl;
		osresult->setGeneralMessage( eclass.errormsg);
		osresult->setGeneralStatusType( "error");
		osrl = osrlwriter->writeOSrL( osresult);
		throw ErrorClass( osrl) ;
	}				
}//end setSolverOptions() 



void CouenneSolver::solve() throw (ErrorClass) {
	if( this->bCallbuildSolverInstance == false) buildSolverInstance();
	if( this->bSetSolverOptions == false) setSolverOptions();
	try{
		}
	catch(const ErrorClass& eclass){
		osresult->setGeneralMessage( eclass.errormsg);
		osresult->setGeneralStatusType( "error");
		osrl = osrlwriter->writeOSrL( osresult);
		throw ErrorClass( osrl) ;
	}
}//solve




/*
BonminProblem::BonminProblem(OSInstance *osinstance_,  OSOption *osoption_, OSResult *osresult_) {
	osinstance = osinstance_;
	osoption = osoption_;
	osresult = osresult_;
	printSol_ = false;
}

BonminProblem::~BonminProblem() {

}
*/


