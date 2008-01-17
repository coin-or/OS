/**
 * @(#)nl2osil 1.0 10/05/2005
 *
 * Copyright (c) 2005
 */

/**  
 *
 * <p>The <code>OSnl2osil</code> used to convert an instance in AMPL nl format
 * to OSiL </p>
 *
 *
 * @author  Robert Fourer, Jun Ma, Kipp Martin, 
 * @version 1.0, 10/05/2005
 * @since   OS1.0
 */
/*
Using AMLP with nl2fml.  Here is the sequence of AMPL commands
with the parinc problem:
//
model parinc.mod;    
data parinc.dat;
option solver nl2osil;
option nl2osil_oopt g; 
option nl2osil_solver lindo; 
sovle;

Alternatively, if you want to name the file and not use the AMPL randomly 
generate file name, do the following:

   model hs71.mod;
   option solver OSAmplClient;
   option OSAmplClient_options "solver lindo";
   option lindo_options "<<any options for the lindo solver>>";
   write gtestfile;
   solve;
	
of course, replacing gtestfile with btestfile generates a binary nl file. 
// glpk is the default -- replace lindo with clp for that solver
// on the Mac it wants the nl file to be text and not binary 
solve;
display x;
//
you should get x1 = 540, x2 = 252
*/



#include <iostream>
#include "OSiLWriter.h"
#include "OSnl2osil.h"
#include "OSErrorClass.h"


#include "nlp.h"
#include "getstub.h"
#include "r_opn.hd" /* for N_OPS */
#include "opcode.hd"

#define R_OPS ((ASL_fg*)asl)->I.r_ops_
#define OBJ_DE ((ASL_fg*)asl)->I.obj_de_
#define CON_DE ((ASL_fg*)asl)->I.con_de_

efunc *r_ops_int[N_OPS];

#include <asl.h>

using std::cerr;
using std::cout;
using std::endl;




   

OSnl2osil::OSnl2osil(std::string nlfilename){	
	//Initialize the AMPL library
	asl = ASL_alloc(ASL_read_fg);
    	stub = &nlfilename[ 0];
	//cout << "READING FILE " << stub << endl;
	//Initialize the nl file reading
	nl = jac0dim(stub, (fint)strlen(stub));
	//Prepare *columnwise* parsing of nl file
	A_vals = (real *)Malloc(nzc*sizeof(real)); 
	//read nl file as a linear program
	#ifdef AMPLDEBUG
	cout << "number of nonzeros =   " << nzc << endl;
	cout << "number of variable =   " << n_var << endl;
	cout << "number of constraints =   " << n_con << endl;
	cout << "number of objs =   " << n_obj << endl;
	cout << "number of ranges =   " << nranges << endl;
	cout << "number of equations =   " << n_eqn << endl;
	//cout << "objective function type" << *objtype << endl;
	#endif
	#ifdef AMPLDEBUG 
		cout << "Start f_read()" << endl;
	#endif

	//fg_read(nl, 0);
	X0 = (real *)Malloc( n_var*sizeof(real));
	cout <<  "N_OPS =  " <<  N_OPS << endl;
	if(N_OPS > 0){
		for(int i = 0; i < N_OPS; i++){
			r_ops_int[i] = (efunc*)(unsigned long)i;
				
		}
		R_OPS = r_ops_int;
		want_derivs = 0;
		fg_read(nl, 0);
		R_OPS = 0;
	}
}

OSnl2osil::~OSnl2osil(){
	delete osinstance;
	osinstance = NULL;
}

OSnLNode* OSnl2osil::walkTree (expr *e){
	OSnLNode *nlNodePoint;
	OSnLNodeVariable *nlNodeVariablePoint;
	OSnLNodeNumber *nlNodeNumberPoint;
	efunc *op;
	expr **ep;
	int opnum;
	int i;
	op = e->op;
	opnum = Intcast op;
	//Printf ("op %d  optype %d  ", opnum, optype[opnum]);
	try{
		switch( opnum) {
			case OPPLUS:
				//cout << "FOUND  PLUS NODE"  << endl;
				nlNodePoint = new OSnLNodePlus();
				nlNodePoint->m_mChildren[0] = walkTree (e->L.e);
				nlNodePoint->m_mChildren[1] = walkTree (e->R.e);
				return nlNodePoint;
				
			case OPSUMLIST:
				i = 0;
				//cout << "INSIDE SUM OPERATOR" << endl;
				nlNodePoint = new OSnLNodeSum();
				nlNodePoint->inumberOfChildren = e->R.ep - e->L.ep;
				nlNodePoint->m_mChildren = new OSnLNode*[ e->R.ep - e->L.ep];
				for (ep = e->L.ep; ep < e->R.ep; *ep++) 
					nlNodePoint->m_mChildren[i++] = walkTree ( *ep);
				return nlNodePoint;
				
			case MAXLIST:
				i = 0;
				//cout << "INSIDE MAX OPERATOR" << endl;
				nlNodePoint = new OSnLNodeMax();
				nlNodePoint->inumberOfChildren = e->R.ep - e->L.ep;
				nlNodePoint->m_mChildren = new OSnLNode*[ e->R.ep - e->L.ep];
				for (ep = e->L.ep; ep < e->R.ep; *ep++) 
					nlNodePoint->m_mChildren[i++] = walkTree ( *ep);
				return nlNodePoint;
				
			case OPMINUS:
				nlNodePoint = new OSnLNodeMinus();
				nlNodePoint->m_mChildren[0] = walkTree (e->L.e);
				nlNodePoint->m_mChildren[1] = walkTree (e->R.e);
				return nlNodePoint;
				
			case OPUMINUS:
				nlNodePoint = new OSnLNodeNegate();
				nlNodePoint->m_mChildren[0] = walkTree (e->L.e);
				return nlNodePoint;
				
			case OPMULT:
				//cout << "FOUND MULT NODE"  << endl;
				nlNodePoint = new OSnLNodeTimes();
				nlNodePoint->m_mChildren[0] = walkTree (e->L.e);
				nlNodePoint->m_mChildren[1] = walkTree (e->R.e);
				return nlNodePoint;
				
			case OPDIV:
				nlNodePoint = new OSnLNodeDivide(); 
				nlNodePoint->m_mChildren[0] = walkTree (e->L.e);
				nlNodePoint->m_mChildren[1] = walkTree (e->R.e);
				return nlNodePoint;
				
			case OPPOW:
				//cout << "FOUND OPPOW NODE"  << endl;
				nlNodePoint = new OSnLNodePower();
				nlNodePoint->m_mChildren[0] = walkTree (e->L.e);
				nlNodePoint->m_mChildren[1] = walkTree (e->R.e); 
				return nlNodePoint;
				
				
			case OP1POW:
				//cout << "FOUND OP1POW NODE"  << endl;
				//cout << "OP1POW EXPONENT =  "  << e->R.en->v<<  endl;
				nlNodePoint = new OSnLNodePower();
				nlNodePoint->m_mChildren[0] = walkTree (e->L.e);
				nlNodeNumberPoint = new OSnLNodeNumber();
				nlNodeNumberPoint->value = e->R.en->v;
				nlNodePoint->m_mChildren[1] = nlNodeNumberPoint;
				return nlNodePoint;
				
			case OP2POW:
				//cout << "FOUND OP2POW NODE"  << endl;
				//nlNodePoint = new OSnLNodePower();
				//nlNodePoint->m_mChildren[0] = walkTree (e->L.e);
				//nlNodeNumberPoint = new OSnLNodeNumber();
				//nlNodeNumberPoint->value = 2;
				//nlNodePoint->m_mChildren[1] = nlNodeNumberPoint;
				nlNodePoint = new OSnLNodeSquare();
				nlNodePoint->m_mChildren[0] = walkTree (e->L.e);
				return nlNodePoint;
				
			case OPCPOW:
				//cout << "FOUND OPCPOW NODE"  << endl;
				//cout << "OPCPOW EXPONENT =  "  << e->R.en->v<<  endl;
				nlNodePoint = new OSnLNodePower();
				nlNodeNumberPoint = new OSnLNodeNumber();
				nlNodeNumberPoint->value = e->L.en->v;
				nlNodePoint->m_mChildren[0] = nlNodeNumberPoint;
				nlNodePoint->m_mChildren[1] = walkTree (e->R.e);
				return nlNodePoint;
				
			case OP_log:
				nlNodePoint = new OSnLNodeLn();
				nlNodePoint->m_mChildren[0] = walkTree (e->L.e);
				return nlNodePoint;
				
			case OP_sqrt:
				nlNodePoint = new OSnLNodeSqrt();
				nlNodePoint->m_mChildren[0] = walkTree (e->L.e);
				return nlNodePoint;
				
			case OP_cos:
				nlNodePoint = new OSnLNodeCos();
				nlNodePoint->m_mChildren[0] = walkTree (e->L.e);
				return nlNodePoint;
				
			case OP_sin:
				nlNodePoint = new OSnLNodeSin();
				nlNodePoint->m_mChildren[0] = walkTree (e->L.e);
				return nlNodePoint;
				
			case OP_exp:
				nlNodePoint = new OSnLNodeExp();
				nlNodePoint->m_mChildren[0] = walkTree (e->L.e);
				return nlNodePoint;
				
			case ABS:
				nlNodePoint = new OSnLNodeAbs();
				nlNodePoint->m_mChildren[0] = walkTree (e->L.e);
				return nlNodePoint;
				
			case OPNUM:
				//cout << "found a number node" << endl;
				nlNodeNumberPoint = new OSnLNodeNumber;
				cout << "THE NUMBER" << (double) ((expr_n*)e)->v << endl;
				nlNodeNumberPoint->value = (double) ((expr_n*)e)->v;
				return nlNodeNumberPoint;
				
			case OPVARVAL:
				//cout << "found a variable node" << endl;
				if(e->a >= osinstance->getVariableNumber() ) throw ErrorClass("OS cannot handle AMPL user defined variables, please reformulate");
				nlNodeVariablePoint = new OSnLNodeVariable;
				nlNodeVariablePoint->idx = e->a;
				nlNodeVariablePoint->coef = 1.0; 
				return nlNodeVariablePoint;
				
			default:
			std::ostringstream outStr;
			std::string error;
			outStr  << endl;
			outStr  << endl;
			error = "ERROR:  An unsupported operator found, AMPL operator number =  "  ;
			outStr << error;
			outStr << opnum;
			outStr << endl;
			error = outStr.str();
			throw ErrorClass( error );
		}//end switch	
	}//end try
	catch(const ErrorClass& eclass){
		throw;
	}
}//walkTree


bool OSnl2osil::createOSInstance(){
	osinstance = new OSInstance();  
	int i, j;
	// put in instanceHeader information 
	// 
	osinstance->setInstanceDescription("Generated from AMPL nl file");
	//
	// put in instanceData information
	//
	// get the variable information
	//
	std::string initString;
	std::string colName;
	double init = OSNAN;
	char vartype = 'C';
	osinstance->setVariableNumber( n_var);
	int firstBinaryVar = n_var - nbv - niv;
	int firstIntegerVar = n_var - niv;
	for(i = 0; i < n_var; i++){
		if(i >= firstBinaryVar) vartype = 'B';
		if(i >= firstIntegerVar) vartype = 'I';
		if(X0 != NULL) init = X0[ i];
		osinstance->addVariable(i, var_name(i), 
			LUv[2*i] > -OSDBL_MAX  ? LUv[2*i] : -OSDBL_MAX, 
			LUv[2*i+1] < OSDBL_MAX ? LUv[2*i+1] : OSDBL_MAX, 
			vartype, init, initString);
	}	
	//
	//
	//(expr_v *)e;
	//
	//
	// now create the objective function
	//	
	double objWeight = 1.0;
	//	char	*objtype;	/* object type array: 0 == min, 1 == max */
	std::string objName="";
	SparseVector* objectiveCoefficients = NULL;
	objectiveCoefficients = new SparseVector( n_var);
	for(i = 0; i < n_var; i++){
		objectiveCoefficients->indexes[i] = i;
	} 
	osinstance->setObjectiveNumber( n_obj) ;
	for(i = 0; i < n_obj; i++){
		for(j = 0; j < n_var; j++){
			objectiveCoefficients->values[j] = 0;
		}
		for(og = Ograd[i]; og; og = og->next){
			objectiveCoefficients->values[og->varno] = og->coef;
		}
		osinstance->addObjective(-n_obj + i, objName, 
		(objtype[i] == 1)?"max":"min", 
		objconst( i),  objWeight, objectiveCoefficients) ;
	}
	//delete objectiveCoefficients; // delete the temporary sparse vector
	//objectiveCoefficients = NULL;
	//
	// now fill in row information
	//
	osinstance->setConstraintNumber( n_con);
	// kipp -- important  -- figure out where the nl file stores a rhs constant
	double constant = 0.0;
	std::string rowName;
	for(i = 0; i < n_con; i++)
	{
		osinstance->addConstraint(i, con_name(i), 
		LUrhs[2*i] > -OSDBL_MAX ? LUrhs[2*i] : -OSDBL_MAX, 
		LUrhs[2*i+1] < OSDBL_MAX ? LUrhs[2*i+1] : OSDBL_MAX, 
		constant);
	}	
	int valuesBegin = 0;
	int valuesEnd = A_colstarts[ n_var] - 1;
	int startsBegin = 0;
	int indexesBegin = 0;
	int indexesEnd = A_colstarts[n_var] - 1;

	// if A_vals has only zeros don't generate a linearConstraints section
	bool bNumAvalsIsPositive = false;
	i = valuesBegin;
	while( (i < valuesEnd) && (bNumAvalsIsPositive == false) ){
		if(A_vals[ i] != 0) bNumAvalsIsPositive = true;
		i++;
	}
	if(bNumAvalsIsPositive == true){
		osinstance->setLinearConstraintCoefficients(nzc,  true, 
			A_vals, valuesBegin,  valuesEnd, 
			A_rownos,  indexesBegin,  indexesEnd,   			
			A_colstarts,  startsBegin,  n_var);
	}
		
		
	// Kipp: can AMPL identify QPs???
	//osinstance->setQuadraticTerms(numberOfQPTerms, VarOneIdx, VarTwoIdx, Coeff, begin, end);
	//loop over each row with a nonlinear term
	//
	if((nlc + nlo) > 0){
		OSnLNode* m_treeRoot;
		cout << nlc << endl;
		cout << nlo << endl;
		osinstance->instanceData->nonlinearExpressions->numberOfNonlinearExpressions = nlc + nlo;
		osinstance->instanceData->nonlinearExpressions->nl = new Nl*[ nlc + nlo ];
		int iNLidx = 0;
		//std::cout << "WALK THE TREE FOR NONLINEAR CONSTRAINT TERMS" << std::endl;
		if(nlc > 0){
			while (iNLidx < nlc) {
				m_treeRoot = walkTree ((CON_DE + iNLidx)->e);
				osinstance->instanceData->nonlinearExpressions->nl[ iNLidx] = new Nl();
				osinstance->instanceData->nonlinearExpressions->nl[ iNLidx]->idx = iNLidx;
				osinstance->instanceData->nonlinearExpressions->nl[ iNLidx]->osExpressionTree = new OSExpressionTree();
				osinstance->instanceData->nonlinearExpressions->nl[ iNLidx]->osExpressionTree->m_treeRoot = m_treeRoot;
				iNLidx++;
				//std::cout << m_treeRoot->getNonlinearExpressionInXML() << std::endl;
			}
		}
		//std::cout << "WALK THE TREE FOR NONLINEAR OBJECTIVE TERMS" << std::endl;
		if(nlo > 0){
			while ( iNLidx < nlc + nlo){
				m_treeRoot = walkTree ((OBJ_DE + iNLidx - nlc)->e);
				//std::cout << "CREATING A NEW NONLINEAR TERM IN THE OBJECTIVE" << std::endl;
				osinstance->instanceData->nonlinearExpressions->nl[ iNLidx] = new Nl();
				osinstance->instanceData->nonlinearExpressions->nl[ iNLidx]->idx = -1 - (iNLidx - nlc);
				osinstance->instanceData->nonlinearExpressions->nl[ iNLidx]->osExpressionTree = new OSExpressionTree();
				osinstance->instanceData->nonlinearExpressions->nl[ iNLidx]->osExpressionTree->m_treeRoot = m_treeRoot;
				iNLidx++;
				//std::cout << m_treeRoot->getNonlinearExpressionInXML() << std::endl;
			}
		}
		//std::cout << "DONE WALKING THE TREE FOR NONLINEAR OBJECTIVE TERMS" << std::endl;

	}
	delete objectiveCoefficients;
	objectiveCoefficients = NULL;
	//
	// end loop of nonlinear rows
	//    
	//OSiLWriter osilwriter;
	//std::cout << "WRITE THE INSTANCE" << std::endl;
	//std::cout << osilwriter.writeOSiL( osinstance) << std::endl;
	//std::cout << "DONE WRITE THE INSTANCE" << std::endl;
	return true;
}
