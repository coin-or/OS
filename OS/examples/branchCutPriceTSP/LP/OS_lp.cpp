// Last edit: 6/23/06
//
// Name:     OS_lp.cpp
// Author:   Francois Margot
//           Tepper School of Business
//           Carnegie Mellon University, Pittsburgh, PA 15213
//           email: fmargot@andrew.cmu.edu
// Date:     12/28/03
//-----------------------------------------------------------------------------
// Copyright (C) 2003, Francois Margot, International Business Machines
// Corporation and others.  All Rights Reserved.

#undef HEUR_SOL

#include <vector>

#include "OS_lp.hpp"
#include "OS_cut.hpp"
#include "OS_var.hpp"
#include "OsiClpSolverInterface.hpp"
#include "CglSimpleRounding.hpp"
#include "CglKnapsackCover.hpp"
#include "CglGomory.hpp"

#include "BCP_math.hpp"
#include "BCP_lp.hpp"
#include "BCP_problem_core.hpp"
#include "BCP_lp_param.hpp"

#include <map>
#include "OSConfig.h" 
#include "OSInstance.h"
#include "OSiLWriter.h"
#include "OSParameters.h"
#include "OSnLNode.h"
#include "OSErrorClass.h"
#include "OSCoinSolver.h"
#include "OSrLReader.h" 
#include <iostream>
#include <fstream>
#include <string>



int locs;
int routes;
int hubloc; 
//int rootnde = 0;



using namespace std;
/************************************************************************/ 

void OS_lp::unpack_module_data(BCP_buffer& buf) {
  buf.unpack( os_prob);
  EPS = os_prob->EPSILON;
  /**
   * we also have access to the osinstance object that was created in OS_tm
   * the OS_tm tree manager sent us a pointer to this -- the osinstance is
   * actually a memeber of OS_prob -- put in this class information we want access to
   */
  
  // just a simple test
  
  std::cout << "number of variables " << os_prob->osinstance->getVariableNumber() << std::endl;
  

  
}



/************************************************************************/
OsiSolverInterface * OS_lp::initialize_solver_interface(){

	OsiClpSolverInterface * clp = new OsiClpSolverInterface;
	clp->messageHandler()->setLogLevel(0);
	return clp;
}

/************************************************************************/
void OS_lp::initialize_new_search_tree_node(const BCP_vec<BCP_var*>& vars,
				       const BCP_vec<BCP_cut*>& cuts,
				       const BCP_vec<BCP_obj_status>& vstatus,
				       const BCP_vec<BCP_obj_status>& cstatus,
				       BCP_vec<int>& var_changed_pos,
				       BCP_vec<double>& var_new_bd,
				       BCP_vec<int>& cut_changed_pos,
				       BCP_vec<double>& cut_new_bd)

  // Called at the beginning of the optimization of a node. 
  // The node LP is not yet solved.

{

  in_strong = 0;
  
  	//BCP_lp_param.hpp for a list of parameters
  	//lets get a parameter -- should be true by default
  	bool relSol = BCP_lp_user::get_param(BCP_lp_par::LpVerb_RelaxedSolution) ;
  	std::cout  << relSol << std::endl;
  	
  	// now reset the value
  	if(relSol == true){
  		BCP_lp_user::set_param( BCP_lp_par::LpVerb_RelaxedSolution, false);
  	}else{
  		BCP_lp_user::set_param( BCP_lp_par::LpVerb_RelaxedSolution, true);
  	}
  	 
  	// see if it got reset
  	relSol = BCP_lp_user::get_param(BCP_lp_par::LpVerb_RelaxedSolution) ;
  	std::cout  <<  relSol << std::endl;
  	

  	//set another way
	//keep all constraints
	this->getLpProblemPointer()->par.set_entry(BCP_lp_par::IneffectiveConstraints, 0);
  	// number of cuts to keep in the pool
	this->getLpProblemPointer()->par.set_entry(BCP_lp_par::IneffectiveBeforeDelete, 10000); 
  	
  	// turn off strong branching
  	this->getLpProblemPointer()->par.set_entry(BCP_lp_par::MaxPresolveIter, -1);
  	

#ifdef USER_DATA
  MY_user_data *curr_ud = dynamic_cast<MY_user_data*> (get_user_data());
  curr_ud->is_processed = 1;
#endif

}

/************************************************************************/
void OS_lp::modify_lp_parameters(OsiSolverInterface* lp, bool in_strong_branching){

  // Called each time the node LP is solved
	
	
	/****
	 * 
	 *  BCP_lp_param.hpp for param doc. 
	 *  BCP_lp_param.cpp for default values.
	 *  to change a param in your user class: getLpProblemPointer()->par.set_entry(LpVerb_RelaxedSolution, false);
	 *  to change a param in bb.par:  BCP_LpVerb_RelaxedSolution 0
	 * 
	 */
	
	

  // if (in_strong_branching) {
  //   in_strong = 1;
  //   lp->setIntParam(OsiMaxNumIterationHotStart, 50);
  // }

   // write the current LP in file lpnode.lp
   //lp->writeLp("lpnode", "lp");
   //cout << "LP node written in file lpnode.lp" << endl;

   // to write the current LP file in file lpnode.mps use the following:
   // lp->writeMps("lpnode", "mps", 0.0);
   // cout << "LP node written in file lpnode.mps" << endl;

}



/************************************************************************/
BCP_solution* OS_lp::generate_heuristic_solution(const BCP_lp_result& lpres,
			    const BCP_vec<BCP_var*>& vars,
			    const BCP_vec<BCP_cut*>& cuts)  {
	//not implemented
	return NULL;
}


/********************************************************************/
BCP_branching_decision OS_lp::select_branching_candidates(const BCP_lp_result& lpres,
                                 const BCP_vec<BCP_var*>& vars,
                                   const BCP_vec<BCP_cut*>& cuts,
                                   const BCP_lp_var_pool& local_var_pool,
                                   const BCP_lp_cut_pool& local_cut_pool,
                                   BCP_vec<BCP_lp_branching_object*>& cands,
                                   bool force_branch) {
	
	
	  // Called at the end of each iteration. Possible return values are:
	  // BCP_DoNotBranch_Fathomed : The node should be fathomed without branching
	  // BCP_DoNotBranch :          BCP should continue to work on this node
	  // BCP_DoBranch :             Branching must be done. In this case the 
	  //                            method returns the branching object candidates 
	  //                            in one of the arguments	


   // unsigned int vecSize = vars.size();
  //  unsigned int vecIter;
 //  for(vecIter = 0; vecIter < vecSize; vecIter++){
  //      std::cout << vars[ vecIter]->obj() << std::endl;
   // } 
    
	std::cout << "INSIDE BRANCHING DECISION: TESTING VARIABLE TYPES " << std::endl;
	std::cout << "SIZE OF CUTS  =  " <<  cuts.size()  << std::endl;
	std::cout << "SIZE OF LOCAL CUTS POOL  =  " << local_cut_pool.size()   << std::endl;


//	locs = os_prob->locs;
//	routes = os_prob->routes;
//	hubloc = os_prob->hubloc;

	// Don't branch if cutting planes have been generated
	if( local_cut_pool.size() > 0 ) {
		
		cout << "select_branching_candidates() returns BCP_DoNotBranch"  << endl;
		return(BCP_DoNotBranch);

  	}else{
		os_prob->haveBranched = true;
		return BCP_lp_user::select_branching_candidates( lpres,
      	vars, cuts, local_var_pool, local_cut_pool,
         cands, force_branch);
  	}
}// end OS_lp::select_branching_candidates


/**************************************************************************/
void OS_lp::set_user_data_for_children(BCP_presolved_lp_brobj* best, 
                                  const int selected)

  // Given the branching decision (parameter "best"; "selected" is the
  // index of the chosen branching decision in the candidate list), 
  // set the user data for the children.

{
#ifdef USER_DATA
  BCP_lp_branching_object *cand = best->candidate();
  MY_user_data *curr_ud = dynamic_cast<MY_user_data*> (get_user_data());
  real_user_data *curr_rud = curr_ud->p_rud;

  for(int i=0; i<cand->child_num; i++) {
    MY_user_data *ud = new MY_user_data(curr_rud->max_card_set_zero);
    real_user_data *rud = ud->p_rud;

    rud->card_set_zero = curr_rud->card_set_zero;

    for(int j=0; j<curr_rud->card_set_zero; j++) {
      rud->set_zero[j] = curr_rud->set_zero[j];
    }

    int ind_br = (*(cand->forced_var_pos))[0];

    if((*(cand->forced_var_bd))[2*i + 1] < EPS) {
      rud->set_zero[curr_rud->card_set_zero] = ind_br;
      (rud->card_set_zero)++;
    }
    best->user_data()[i] = ud;
  }
#endif /* USER_DATA */
} /* set_user_data_for_children */





/************************************************************************/


void  OS_lp::cuts_to_rows(const BCP_vec<BCP_var*>& vars, // on what to expand
                    BCP_vec<BCP_cut*>& cuts,       // what to expand
                    BCP_vec<BCP_row*>& rows,       // the expanded rows
                    // things that the user can use for lifting cuts if allowed
                    const BCP_lp_result& lpres,
                    BCP_object_origin origin, bool allow_multiple) {

    //return;
  // Required function when indexed or algorithmic cuts are used.
  // Describes how to get a row of the matrix from the representation of the
  // cut.
	std::cout << "Execute cuts_to_rows" << std::endl;
	const int cutnum = cuts.size();
	for (int i=0; i<cutnum; ++i) {
		const OsiRowCut* bcut = dynamic_cast<const OS_cut*>(cuts[i]);
		if (bcut) {
    
			rows.push_back(new BCP_row(bcut->row(), bcut->lb(), bcut->ub()));
			continue;
		}
		throw BCP_fatal_error("Unknown cut type in cuts_to_rows.\n");
	}
}

/************************************************************************/

void OS_lp::vars_to_cols(const BCP_vec<BCP_cut*>& cuts,
		     BCP_vec<BCP_var*>& vars,
		     BCP_vec<BCP_col*>& cols,
		     const BCP_lp_result& lpres,
		     BCP_object_origin origin, bool allow_multiple)
{

	std::cout << "EXECUTE vars_to_cols  **************" << std::endl;
    static const CoinPackedVector emptyVector(false);
    const int numvars = vars.size();
    int i;
    for (i = 0; i < numvars; ++i) {
	const OS_var* v = dynamic_cast<const OS_var*>(vars[i]);
	    // Since we do not generate cuts, we can just disregard the "cuts"
	    // argument, since the column corresponding to the var is exactly
	    // the flow (plus the entry in the appropriate convexity
	    // constraint)
	    BCP_col* col = new BCP_col(v->coinPackedVec, v->weight, 0.0, 1.0);
	    //col->insert(data.numarcs + v->commodity, 1.0);
	    
	    cols.push_back( col);
	    // Excercise: if we had generated cuts, then the coefficients for
	    // those rows would be appended to the end of each column
    }
}


/************************************************************************/
void OS_lp::process_lp_result(const BCP_lp_result& lpres,
		      const BCP_vec<BCP_var*>& vars,
		      const BCP_vec<BCP_cut*>& cuts,
		      const double old_lower_bound,
		      double& true_lower_bound,
		      BCP_solution*& sol,
		      BCP_vec<BCP_cut*>& new_cuts,
		      BCP_vec<BCP_row*>& new_rows,
		      BCP_vec<BCP_var*>& new_vars,
		      BCP_vec<BCP_col*>& new_cols){
	// only process if LP relaxation is optimal
	if(getLpProblemPointer()->lp_solver->isAbandoned() ||
    	getLpProblemPointer()->lp_solver->isProvenPrimalInfeasible() ||
      getLpProblemPointer()->lp_solver->isDualObjectiveLimitReached() ||
      getLpProblemPointer()->lp_solver->isIterationLimitReached() )  {
      true_lower_bound = old_lower_bound;
		getLpProblemPointer()->user_has_lp_result_processing = false;
		return;
   }
	new_cuts.clear();
	new_rows.clear();
	int i;
	if((os_prob->haveBranched == false || isIntSolution(lpres.x(),  vars,  BCP_lp_user::get_param(BCP_lp_par::IntegerTolerance)) == true) ) 
		createcutsforbearcat(lpres,  new_cuts);  // call the tour-breaking cut procedure
    //int cutnum = algo_cuts.size();
	createCglCuts(lpres,  new_cuts);
	int cutnum = new_cuts.size();
	std::cout << "NUMBER CUTS GENERATED = " << os_prob->ttlcuts << std::endl;
	os_prob->ttlcuts = os_prob->ttlcuts + cutnum;	
	// if no cuts or vars were found  call the old method   
    if(  cutnum == 0 ){
		//true_lower_bound =  old_lower_bound;
    	BCP_lp_user::process_lp_result(lpres, vars, cuts, 
    			old_lower_bound, true_lower_bound, sol, new_cuts,
    			new_rows, new_vars, new_cols);    	
    	return;
    }
	cout<< " new_cuts() size" << new_cuts.size() << std::endl;
	for (i = 0; i < cutnum; ++i) {
		const OsiRowCut* bcut = dynamic_cast<const OS_cut*>(new_cuts[i]);
	   if (bcut) {
	   	new_rows.push_back(new BCP_row(bcut->row(), bcut->lb(), bcut->ub()));
	 		}else{
	   		throw BCP_fatal_error("Unknown cut type in cuts_to_rows.\n");
	    }
	}
	//new_cuts.clear();
	true_lower_bound =  lpres.objval();
	std::cout << "TRUE LOWER BOUND **************   "  << true_lower_bound << std::endl;
}//end process_lp_result



/************************************************************************/


	void  OS_lp::display_lp_solution(const BCP_lp_result& lpres,
 				 const BCP_vec<BCP_var*>& vars,
 				 const BCP_vec<BCP_cut*>& cuts,
 				 const bool final_lp_solution){
		
	
		//BCP_lp_user::display_lp_solution( lpres, vars, cuts,final_lp_solution);
		return;
// kipp write OSrL here?
// if final_lp_solution is true print out some osrl.
}

/************************************************************************************************/
	void  OS_lp::createcutsforbearcat(const BCP_lp_result& lpres,
									  BCP_vec<BCP_cut*>& new_cuts){
						  
//os_prob->addtxtstr << " INSIDE CUT ADDITION SCOPE \n";
		int i,j,ii,jj;
		//int num_vars = vars.size();
		const double *x = lpres.x();
		

		locs = os_prob->locs;
		routes = os_prob->routes;
		hubloc = os_prob->hubloc;
		// CREATE VALUES, INDEXES & STARTS ARRAYS		
		
		int LocInRt; // total number of locs included in each route
		map<int, int> SubProbLocs;// mapping master space to sub space
		int rt;
		

				

for(rt=0; rt < routes; rt++)// ROUTE LOOP starts 
    {       LocInRt =0;
			ii=0;
			for(i=0; i < locs; i++)// to fill the values in alllocs; 1 - if a location is assigned to a route
				{if ( x[routes*i + rt ] > 0 )
						{
						 SubProbLocs.insert (pair <int,int>(ii,i));
						 LocInRt++;
						 ii++;
						}

				 }


		// OUTPUT - THE ROUTE ASSIGMENT

		OSInstance *osinstance;
		osinstance = new OSInstance();
		
		double *values = NULL; // values pointer  
		int *indexes = NULL; //indexes pointer  
		int *starts = NULL; // starts pointer
		values = new double[4*(LocInRt-1)*LocInRt];// declare the array
		indexes = new int[4*(LocInRt-1)*LocInRt];
		starts = new int[2*(LocInRt-1)*LocInRt + 1];

		ii=0;
		jj=0;
		for(i=0; i < LocInRt; i++)//creating alphas(i,j) for all combinations of i, j & thetas (i)
		   {for(j=0; j <LocInRt; j++)
			 { if( i!=j)
				{ 
		          values[ii]= 1;
				  values[ii+1]= -1;
				  values[ii+2]= 1;
				  values[ii+3]= -1;

				  starts[jj] = 2 * jj;
				  starts[jj + 1] = 2 * (jj + 1);
				  jj = jj + 2; 
				  if (i<j)
					{	indexes[ii] =   (LocInRt-1)*i+(j-1);
						indexes[ii+1] = (LocInRt-1)*LocInRt+ i;
						indexes[ii+2] = (LocInRt-1)*i+(j-1);
					    indexes[ii+3] = (LocInRt-1)*LocInRt+ j;
						ii= ii + 4;
					}
				  else
					{	indexes[ii] =   (LocInRt-1)*i+j;
						indexes[ii+1] = (LocInRt-1)*LocInRt+ i;
						indexes[ii+2] = (LocInRt-1)*i+j;
						indexes[ii+3] = (LocInRt-1)*LocInRt+ j;
						ii= ii + 4;
					}

			     }
			 }
		  }        
									  
	    starts[jj] = 2 * jj;	
		
		// CREATE CONSTRAINTS
		//for each LocInRt there are (LocInRt-1)*2 constraints; total cons = LocInRt*(LocInRt-1)*2;

		osinstance->setConstraintNumber(LocInRt*(LocInRt-1)*2);
		for (i=0; i<LocInRt*(LocInRt-1)*2;i++)
			{osinstance->addConstraint(i,"",-OSDBL_MAX,0,0);}
		
		osinstance->setLinearConstraintCoefficients(4*(LocInRt-1)*LocInRt,false,values,0,(4*(LocInRt-1)*LocInRt)-1,
					indexes,0,(4*(LocInRt-1)*LocInRt)-1,starts,0,2*(LocInRt-1)*LocInRt);
		

		//os_prob->addtxtstr<< " \n";
		

		// DEFINE VARIABLES; count the number locations assigned in a given route ; 
		// LocInRt*(LocInRt-1) for alphas, LocInRt for thetas => LocInRt*LocInRt;
		osinstance->setVariableNumber(LocInRt*LocInRt);
		for ( i = 0; i<LocInRt*LocInRt; i++)
				{if (i < LocInRt* (LocInRt - 1) )// for alphas
					  osinstance->addVariable(i,"",-OSDBL_MAX,OSDBL_MAX,'C');
			    else                           // for thetas
					  osinstance->addVariable(i,"",0,1,'C');
				}
		//os_prob->addtxtstr<<" \n";
		
		// ***** CHANGE IS FROM HERE****////
		// DEFINE sparse vector for OBJECTIVE FUNCTION coefficients
				
		osinstance->setObjectiveNumber(1);// we always assume one objective function
		SparseVector*objcoeff = new SparseVector(LocInRt*LocInRt);
		for(i=0;i<LocInRt*LocInRt; i++)// initialize the vector ( creating dense vector )
			{objcoeff->values[i] = 0;
			objcoeff->indexes[i]= i;}
		osinstance->addObjective(-1, "objfunction", "max",0.0, 1.0, objcoeff);// now, add the objective function
		
		
		jj=0;
		
		// after creating dense objcoeffs, copying values from x vector ( xbar*alpha - copyin values for xbar)
		for(map<int,int>::iterator iti = SubProbLocs.begin(); iti != SubProbLocs.end(); ++iti)
			{for(map<int,int>::iterator itj = SubProbLocs.begin(); itj != SubProbLocs.end(); ++itj)
					{if ( iti->second != itj->second )
						  { if ( iti->second < itj->second )
								{if ( x[ locs*routes + (locs-1)*routes*iti->second + rt + routes*(itj->second - 1)] > 0 )
								         { osinstance->bObjectivesModified = true;
										   osinstance->instanceData->objectives->obj[0]->coef[jj]->value = x[ locs*routes + (locs-1)*routes*iti->second + rt + routes*(itj->second - 1)];
										  }
								 					      
								}
								
						   else
						       {if (x[locs*routes + (locs-1)*routes*iti->second + rt + routes*(itj->second)] > 0 )
								           { osinstance->bObjectivesModified = true;
											 osinstance->instanceData->objectives->obj[0]->coef[jj]->value = x[locs*routes + (locs-1)*routes*iti->second + rt + routes*(itj->second)];										  
										   }
						        }
		                   
						   if ( iti->second == hubloc-1 || itj->second == hubloc-1)// making alphas that incident to hub to zero
								{ osinstance->bVariablesModified = true;
								  osinstance->instanceData->variables->var[jj]->ub = 0;
								  //os_prob->addtxtstr << " IT IS WORKING \n";
								}
						   jj++;
						}
					 }
		       }
		
		
		for (i=0;i<LocInRt;i++)// adding -1s in for thetas as ObjCoeffs
		    { osinstance->bObjectivesModified = true;
			  osinstance->instanceData->objectives->obj[0]->coef[LocInRt*(LocInRt-1)+i]->value = -1;
			 }
		
		int CutsWereAdded = 0;
		int rhsVal = 0;
		i=0;
		
		while (i<LocInRt && CutsWereAdded == 0 ) //SEPERATION PROBLEM loop starts
		    {					                 //with in each route, seperation problem need to be solved for each node in that route
			//os_prob->addtxtstr << " SEPERATION PROBLEM LOOP FOR i =  " << i+1 << " \n";
			if (i == 0)
			  {//osinstance->bVariablesModified = true; 
			   //osinstance->instanceData->variables->var[LocInRt*(LocInRt-1)+i]->ub = 0;
			   osinstance->bObjectivesModified = true;
			   osinstance->instanceData->objectives->obj[0]->coef[LocInRt*(LocInRt-1)+i]->value = 0;
			   }
			else
			  { //osinstance->bVariablesModified = true;
			    //osinstance->instanceData->variables->var[LocInRt*(LocInRt-1)+i]->ub = 0;//make the theta variable upper bound zero for the ith node;
			    //osinstance->instanceData->variables->var[LocInRt*(LocInRt-1)+i-1]->ub = 1;// reset the UB of the previous theta variable to one;
				 osinstance->bObjectivesModified = true;
			     osinstance->instanceData->objectives->obj[0]->coef[LocInRt*(LocInRt-1)+i]->value = 0;  
				 osinstance->instanceData->objectives->obj[0]->coef[LocInRt*(LocInRt-1)+i-1]->value = -1;  
			   }
			
			// solve the separation problem
						
			// create SOLVER class and assign the instance to its data member
			CoinSolver *solver;
			solver = new CoinSolver();
			solver->osinstance = osinstance;
			solver->sSolverName ="clp";
			solver->buildSolverInstance();
			solver->solve();
			//os_prob->addtxtstr << "\n";
			//os_prob->addtxtstr << "\n";
			//os_prob->addtxtstr << " PRINT THE MODEL \n "; 
			//os_prob->addtxtstr << osinstance->printModel();
			// first read the result in OSResult object
			// creat an OSResult object from the string
			OSrLReader *osrlreader = NULL;
			OSResult *osresult = NULL;
			osrlreader = new OSrLReader();
			osresult  = osrlreader->readOSrL( solver->osrl);
			
			// check the solution status
			std::string solStatus;
			double optSolValue;
			solStatus = osresult->getSolutionStatusType(0); // the argument is the solution index
			optSolValue = osresult->getOptimalObjValue( -1, 0); //first index is objIdx, second is solution index
			//os_prob->addtxtstr<< "optSolValue = " << optSolValue << "\n";
			if ( optSolValue > 0.01) // if the opt.sol > 0 STARTS
			       {// now get the primal solution
				    //os_prob->addtxtstr<< " ADDING CUTS \n";
					int vecSize;
					std::vector<IndexValuePair*> primalValPair;
					primalValPair = osresult->getOptimalPrimalVariableValues( 0);
					vecSize = primalValPair.size();
			 	
					//os_prob->addtxtstr<<"THETA VARIABLES \n";
					for(map<int,int>::iterator iti = SubProbLocs.begin(); iti != SubProbLocs.end(); ++iti)
					   { //os_prob->addtxtstr<< "" << primalValPair[LocInRt*(LocInRt - 1)+ iti ->first]->value << " ";
						 if ( primalValPair[LocInRt*(LocInRt - 1)+ iti ->first]->value > 0)
							   { ++rhsVal; }// count the theta variables which has value of 1
					   }

					for(map<int,int>::iterator delj = SubProbLocs.begin(); delj != SubProbLocs.end();)
					   { //cout<< "" << primalValPair[LocInRt*(LocInRt - 1)+ delj ->first]->value << " ";
					     //cout<< "" << delj ->first << " ";
						 if ( primalValPair[LocInRt*(LocInRt - 1)+ delj ->first]->value == 0)
							 { SubProbLocs.erase(delj++);
								}// delete the zero valued theta variables
						 else
								++delj;
						}

					CutsWereAdded = 1;
					primalValPair.clear();
					
					}  // if the opt.sol > 0 ENDS
		
			// garbage collection
			
			delete solver;
			solver = NULL;
			delete osrlreader;
			osrlreader = NULL;
			++i;
				
		    } // SEPERATION PROBLEM LOOP ends
		 
		 
		 if (CutsWereAdded ==1) // ADDING CUT starts
		   {OsiRowCut* rcut = new OsiRowCut();// rhsVal give you number of elements in the cutset;
			int *cutind = new int[rhsVal*(rhsVal-1)]; // the cut column indexes
			double *cutcoef = new double[ rhsVal*(rhsVal-1)];// the cut coefficients
		    int cut_nz = rhsVal*(rhsVal-1);// number of nonzeros in the cut
			double cutrhs = rhsVal -1;// rhs value
			
			//os_prob->addtxtstr<< " \n";
			//os_prob->addtxtstr<< " cut_nz = " << cut_nz << "\n";
			//os_prob->addtxtstr<< " cutrhs = " << cutrhs << "\n";
						
			//os_prob->addtxtstr<< "ConsA"<<os_prob->conscount<<".. ";
			ii = 0;
			os_prob->conscount++;
			for(map<int,int>::iterator iti = SubProbLocs.begin(); iti != SubProbLocs.end(); ++iti)
				{for(map<int,int>::iterator itj = SubProbLocs.begin(); itj != SubProbLocs.end(); ++itj)
					{ //cout<< " iti->second " << iti->second << " itj->second "<< itj->second <<"\n";
					  if ( iti->second != itj->second )
						{ if ( iti->second < itj->second )	
							{	cutind[ii]	= locs*routes + (locs-1)*routes*iti->second + rt + routes*(itj->second - 1);}
						  else
							{  cutind[ii] =    locs*routes + (locs-1)*routes*iti->second + rt + routes*(itj->second);}
														
						cutcoef[ii]= 1;
						//os_prob->addtxtstr<<" cutcoeff = " <<cutcoef[ii]<<" cutind = "<<cutind[ii]<< "\n";
						++ii;
						//os_prob->addtxtstr<<"X('"<< iti->second+1<<"',"<<"'"<<itj->second+1<<"',"<<"'"<<rt+1<<"' )" << "+";
						
					    }
					}
				}
			
			
			
			rcut->setLb(-BCP_DBL_MAX);
	    	rcut->setUb(cutrhs);
	    	rcut->setRow( cut_nz, cutind, cutcoef);
	    	OS_cut* cut = new OS_cut( *rcut);
	    	//algo_cuts.push_back( cut);
			//os_prob->addtxtstr<< " algo_cuts = " << algo_cuts.size() << "\n";
			new_cuts.push_back(cut);
			

			delete rcut;
			rcut = NULL;
			//delete cut;
			//cut = NULL;
			delete[] cutind;
			cutind = NULL;
			delete[] cutcoef;
			cutcoef = NULL;
			
			 
					
			  } // ADDING CUT ends
						   
			
		 
		// garbage collection


		//os_prob->addtxtstr<< " clearing SubProbLocs " << "\n";
		SubProbLocs.clear();
		//os_prob->addtxtstr<< " cleared SubProbLocs " << "\n";

	    //os_prob->addtxtstr<< " deleting osinstance " << "\n";
		delete osinstance;
		osinstance = NULL;	
		//os_prob->addtxtstr<< " deleted osinstance " << "\n";

		//os_prob->addtxtstr<< " deleting values " << "\n";
		//delete[] values;
		values =  NULL;
		//os_prob->addtxtstr<< " deleted values " << "\n";
		
		//os_prob->addtxtstr<< " deleting indexes " << "\n";
		//delete[] indexes;
		indexes = NULL;
		//os_prob->addtxtstr<< " deleted indexes " << "\n";
		
		//os_prob->addtxtstr<< " deleting starts " << "\n";
		//delete[] starts;
		//os_prob->addtxtstr<< " deleted starts " << "\n";
		starts =  NULL;
		

		//os_prob->addtxtstr<< " deleting objcoeff " << "\n";
		delete objcoeff;
		objcoeff = NULL;
		//os_prob->addtxtstr<< " deleted osinstance " << "\n";

		
					
	}// ROUTE LOOP ends 	  

}

bool OS_lp::isIntSolution(const double *x, const BCP_vec<BCP_var*>& vars, const double intTol){
	int num_vars = vars.size();
	int i;
	
   for(i = 0; i < num_vars; i++) {  

   	if( vars[ i]->var_type() < 2)	{
    		if((x[i] -floor( x[i])  > intTol) && (ceil( x[i]) - x[i] > intTol)) {
    			// we have a fractional integer variable
				return false;
    		}
    	}
    }
	return  true;
}// end isIntSolution

void OS_lp::createCglCuts(const BCP_lp_result& lpres,BCP_vec<BCP_cut*>& new_cuts){

	OsiClpSolverInterface* my_lp_solver;
	my_lp_solver =  dynamic_cast<OsiClpSolverInterface *>(getLpProblemPointer()->lp_solver);
	CglGomory  gomory;
	OsiSolverInterface::ApplyCutsReturnCode acRc;
	OsiCuts my_cuts;
	double epsilon = .01;
	int i, k;
	// generate the Gomory constraints
	gomory.generateCuts(*my_lp_solver, my_cuts);  
	const double *x = lpres.x();
	CoinPackedVector pv;
	int *pvIndexes = NULL;
	double *pvElements = NULL;
	int numElem;
	double lhs = 0;
   OS_cut* cut;
	int ncuts = my_cuts.sizeRowCuts();
	
	const OsiRowCut **newRowCuts = new const OsiRowCut * [ncuts];
	std::cout <<  "sizeRowCuts() =    " << ncuts  << std::endl;
	for(i = 0; i < ncuts; i++) {
		newRowCuts[i] = &my_cuts.rowCut(i); 
	   cut = new OS_cut( *newRowCuts[i]);
	   pv = newRowCuts[i]->row();
	   pvIndexes = pv.getIndices();
	   pvElements =  pv.getElements();
	   numElem = pv.getNumElements();
	  	lhs = 0;
	   for(k = 0; k < numElem; k++){
	   	lhs += pvElements[ k]*x[ pvIndexes[k] ];
	    	  //std::cout << pvElements[ k] << std::endl;
	   }
	 	if( (newRowCuts[i]->sense() == 'L')  && (lhs > newRowCuts[i]->rhs() +epsilon )  ){
	   	new_cuts.push_back( cut);  
	   }
	}	   
	generated_cuts = (new_cuts.size() > 0);
	for(i = 0; i < ncuts; i++){
			//delete newRowCuts[ i];
	}
	delete[] newRowCuts;
} // end createCglCuts

