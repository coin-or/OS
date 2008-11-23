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
	Ipopt::Journalist* jnlst = new Ipopt::Journalist();
	jnlst->AddFileJournal("console", "stdout", J_STRONGWARNING);
	couenne = new CouenneProblem(NULL, NULL, jnlst);

  // create room for problem's variables and bounds
  CouNumber
    *x_ = (CouNumber *) malloc ((n_allvars) * sizeof (CouNumber)),
    *lb = (CouNumber *) malloc ((n_allvars) * sizeof (CouNumber)),
    *ub = (CouNumber *) malloc ((n_allvars) * sizeof (CouNumber));
	for (int i = 0; i < n_allvars; ++i)
	{
		couenne->addVariable(SCIPvarGetType(allvars[i]) <
SCIP_VARTYPE_CONTINUOUS, couenne->domain());
		x_[i] = 0.;
		lb[i] = -COUENNE_INFINITY;
    ub[i] =  COUENNE_INFINITY;
	}

  couenne->domain()->push(n_allvars, x_, lb, ub);

  free(x_); free(lb); free(ub);
	
	couenne->addObjective(new exprConst(0.), "min"); // dummy objective
	
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


