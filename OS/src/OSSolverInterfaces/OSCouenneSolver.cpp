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


//OS stuff
#include "OSDataStructures.h"
#include "OSParameters.h" 
#include "OSCommonUtil.h"
#include "OSMathUtil.h"
#include "OSCouenneSolver.h"
# include <cppad/cppad.hpp>
//end OS stuff


// Couenne stuff

#include "CouenneTypes.hpp"
#include "exprSum.hpp"
#include "exprMul.hpp"
#include "exprClone.hpp"
#include "exprGroup.hpp"
#include "CouenneJournalist.hpp"
// end Couenne stuff


# include <cstddef>
# include <cstdlib>
# include <cctype>
# include <cassert>
# include <stack>
#include <string>
#include<iostream>



using namespace Bonmin;
using std::cout; 
using std::endl; 
using std::ostringstream;


CouenneSolver::CouenneSolver() {
using namespace  Ipopt;
	osrlwriter = new OSrLWriter();
	osresult = new OSResult();
	m_osilreader = NULL;
	couenneErrorMsg = "";
	couenne = NULL;


} 

CouenneSolver::~CouenneSolver() {
	#ifdef DEBUG
	cout << "inside CouenneSolver destructor" << endl;
	#endif
	cout << "inside CouenneSolver destructor" << endl;
	if(couenne != NULL){
		cout << "BEFORE DELETE COUENNE" << endl;
		//delete couenne;
		cout << "AFTER DELETE COUENNE" << endl;
	}
	if(m_osilreader != NULL) delete m_osilreader;
	m_osilreader = NULL;
	delete osresult;
	osresult = NULL;
	delete osrlwriter;
	osrlwriter = NULL;
	//delete osinstance;
	//osinstance = NULL;
	#ifdef DEBUG
	cout << "leaving CouenneSolver destructor" << endl;
	#endif
}


void CouenneSolver::buildSolverInstance() throw (ErrorClass) {
	// Much of the following is taken from Stefan Vigerske
	try{
		int i, j;
		
		if(osil.length() == 0 && osinstance == NULL) throw ErrorClass("there is no instance");
		if(osinstance == NULL){
			m_osilreader = new OSiLReader();
			osinstance = m_osilreader->readOSiL( osil);
		}	
		

		Ipopt::Journalist* jnlst = new Ipopt::Journalist();
		jnlst->AddFileJournal("console", "stdout", J_STRONGWARNING);
		couenne = new CouenneProblem(NULL, NULL, jnlst);
		int n_allvars = osinstance->getVariableNumber();
		if( n_allvars <= 0 )throw ErrorClass("Couenne solver Needs Variables");
		std::cout << "NUMBER OF VARIABLES = " <<  n_allvars <<  std::endl;
	
		// create room for problem's variables and bounds
		CouNumber *x_ = (CouNumber *) malloc ((n_allvars) * sizeof (CouNumber));
		CouNumber	*lb = NULL, *ub = NULL;
	
		// now get variable upper and lower bounds
		ub = osinstance->getVariableUpperBounds();
		lb = osinstance->getVariableLowerBounds();
		
		//declare the variable types
		char *varType;
		varType = osinstance->getVariableTypes();
		for (i = 0; i < n_allvars; ++i) {
			if( (varType[i] == 'B') || (varType[i]) == 'I' ) {
				couenne->addVariable(true, couenne->domain() );
			}
			else{
				
				couenne->addVariable(false, couenne->domain() );
				
			}

			x_[i] = 0.;
		}
		
		couenne->domain()->push(n_allvars, x_, lb, ub);
  		free(x_);
	
		// now for the objective function -- assume just one for now
		//just worry about linear coefficients
	
		expression *body = NULL;
		
		SparseVector* sv = osinstance->getObjectiveCoefficients()[ 0];
		
		int nterms = sv->number;
		
		exprGroup::lincoeff lin( nterms);
		
		
		for ( i = 0; i < nterms; ++i){
	
			lin[i].first = couenne->Var( sv->indexes[ i] );
			lin[i].second = sv->values[ i];

		}
		
		expression** nl = new expression*[1];
		nl[0] = body;
		body = new exprGroup(0., lin, nl, 1);	 
	
		couenne->addObjective(body, "min"); 
		
		// get the constraints in row format
		
		SparseMatrix* sm =  osinstance->getLinearConstraintCoefficientsInRowMajor();
		
		sm->isColumnMajor = false;		
		
		int nconss = osinstance->getConstraintNumber();		
		int row_nonz = 0;
		int kount = 0;
		
		double *rowlb = osinstance->getConstraintLowerBounds();
		double *rowub = osinstance->getConstraintUpperBounds();
		
		for (i = 0; i < nconss; ++i) {
			body = NULL;
			row_nonz = sm->starts[ i +1] - sm->starts[ i];
			if ( row_nonz  > 0){  // test for nonzeros in row i
				exprGroup::lincoeff lin( row_nonz);
				for (j = 0; j  <  row_nonz;  ++j){
					
					lin[j].first = couenne->Var( sm->indexes[ kount] );
					lin[j].second = sm->values[ kount];
					
					kount++;
					
				}
			expression** nl = new expression*[1];
			nl[0] = body;
			body = new exprGroup(0., lin, nl, 1);
		}
		
		if (rowlb[ i] == rowub[ i])
		{
			couenne->addEQConstraint(body, new exprConst( rowub[ i] ));
		}
		else if (rowlb[ i]  ==  -OSDBL_MAX)
		{
			assert(rowub[ i]  !=  -OSDBL_MAX);
			couenne->addLEConstraint(body, new exprConst( rowub[ i] ));
		}
		else if (rowub[ i] ==  OSDBL_MAX)
		{
			assert(rowlb[ i]  != OSDBL_MAX);
			couenne->addGEConstraint(body, new exprConst( rowlb[ i] ));			
		}
		else
			couenne->addRNGConstraint(body, new exprConst( rowlb[ i]), new
				exprConst( rowub[ i] ));		
			
	}


	//couenne->print();

	//couenne->AuxSet() = new std::set <exprAux *, compExpr>;

  	// reformulation
  	//couenne->standardize();

  	// give a value to all auxiliary variables
  	//couenne->initAuxs();

  	// clear all spurious variables pointers not referring to the
	//variables_ vector
	//  couenne->realign ();

	//couenne->print();

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


