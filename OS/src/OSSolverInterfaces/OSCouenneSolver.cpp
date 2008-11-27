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
#include "BonCouenneInterface.hpp"
#include "BonCouenneSetup.hpp"
#include "BonCbc.hpp"
#include "CouenneProblem.hpp"
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
		int i;
		
		if(osil.length() == 0 && osinstance == NULL) throw ErrorClass("there is no instance");
		if(osinstance == NULL){
			m_osilreader = new OSiLReader();
			osinstance = m_osilreader->readOSiL( osil);
		}	
		
		CouenneProblem *couenne;
		Ipopt::Journalist* jnlst = new Ipopt::Journalist();
		jnlst->AddFileJournal("console", "stdout", J_STRONGWARNING);
		couenne = new CouenneProblem(NULL, NULL, jnlst);
		int n_allvars = osinstance->getConstraintNumber();
		if( n_allvars <= 0 )throw ErrorClass("Couenne solver Needs Constraints");
		
		//if(osinstance->getVariableNumber() <= 0)throw ErrorClass("Couenne solver requires decision variables");
		//if(osinstance->getObjectiveNumber() <= 0) throw ErrorClass("Couenne solver needs an objective function");

		// create room for problem's variables and bounds
		CouNumber
			*x_ = (CouNumber *) malloc ((n_allvars) * sizeof (CouNumber)),
			*lb = (CouNumber *) malloc ((n_allvars) * sizeof (CouNumber)),
			*ub = (CouNumber *) malloc ((n_allvars) * sizeof (CouNumber));
	
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
				couenne->addVariable(true, couenne->domain() );
			}

			x_[i] = 0.;
		}

		couenne->domain()->push(n_allvars, x_, lb, ub);

		
  

		// now for the objective function -- assume just one for now
		//just worry about linear coefficients
	
		expression *body = NULL;
		
		SparseVector** sv = osinstance->getObjectiveCoefficients();
		
		int nterms = sv[ 0]->number;
		
		int *indexL = new int [nterms+1];
		CouNumber *coeff  = new CouNumber [nterms];

		
		exprGroup::lincoeff lin( nterms);
		
		
		for ( i = 0; i < nterms; ++i){
	
			lin[i].first = couenne->Var( indexL[ i] );
			lin[i].second = coeff[ i];

		}
		
		
		expression** nl = new expression*[1];
		nl[0] = body;
		body = new exprGroup(0., lin, nl, 1);	 
	
		couenne->addObjective(body, "min"); 
		
		//free(x_); free(lb); free(ub);
		/*


	SCIP_CONSDATA* consdata;
	for (int i = 0; i < nconss; ++i)
	{
		consdata = SCIPconsGetData(conss[i]);
		LaGO::MINLPData::Constraint&
con(lagodata->getConstraint(consdata->lagoindex));
		G2DFunction* g2dfunc = (G2DFunction*)GetRawPtr(con.origfuncNL);
		expression* body =
g2dfunc->getAsCouenneExpression(couenne->Variables(), couenne->domain());
		assert(body);
		
		if (consdata->n_lincoeff)
		{
			exprGroup::lincoeff lin(consdata->n_lincoeff);
			for (int i = 0; i < consdata->n_lincoeff; ++i)
			{
				lin[i].second = consdata->lincoeff[i];
				lin[i].first = couenne->Var(var2index[consdata->linvar[i]]);
			}
			
			expression** nl = new expression*[1];
			nl[0] = body;
			body = new exprGroup(0., lin, nl, 1);
		}
		
		if (con.lower == con.upper)
		{
			couenne->addEQConstraint(body, new exprConst(con.upper));
		}
		else if (con.lower == -LaGO::getInfinity())
		{
			assert(con.upper != LaGO::getInfinity());
			couenne->addLEConstraint(body, new exprConst(con.upper));
		}
		else if (con.upper == LaGO::getInfinity())
		{
			assert(con.lower != LaGO::getInfinity());
			couenne->addGEConstraint(body, new exprConst(con.lower));			
		}
		else
			couenne->addRNGConstraint(body, new exprConst(con.lower), new
exprConst(con.upper));			
	}
	
	for (int i = 0; i < n_allvars; ++i)
	{
		couenne->Var(i)->linkDomain(couenne->domain());
		couenne->Lb(i) = SCIPisInfinity(scip, -SCIPvarGetLbGlobal(allvars[i]))
? -COUENNE_INFINITY : SCIPvarGetLbGlobal(allvars[i]);
		couenne->Ub(i) = SCIPisInfinity(scip,  SCIPvarGetUbGlobal(allvars[i]))
?  COUENNE_INFINITY : SCIPvarGetUbGlobal(allvars[i]);
	}
	couenne->print();

	couenne->AuxSet() = new std::set <exprAux *, compExpr>;

  // reformulation
  couenne->standardize();

  // give a value to all auxiliary variables
  couenne->initAuxs();

  // clear all spurious variables pointers not referring to the
variables_ vector
//  couenne->realign ();

	couenne->print();
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


