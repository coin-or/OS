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
   option solver amplclient;
   option amplclient_options "solver lindo";
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





static std::string msnodeNames[] = {
	/*1--*/"plus", "sum", "minus", "negate", "times", "divide",
	"quotient", "rem", "power", "product",
	/*2--*/"abs", "floor", "ceiling", "percent", "square", "squareRoot", "ln", "log", "log10", "exp",
	"factorial", "combination", "permutation", "gcd", "lcm", "roundToInt", "round", "truncate", "sign", "rand","gammaFn", "gammaLn",
	/*3--*/"sin", "cos", "tan", "arcsin", "arccos", "arctan", "sinh", "cosh", "tanh", "arcsinh", "arccosh", "arctanh",
	"cot", "coth", "arccot", "arccoth", "sec", "sech", "arcsec", "arcsech", "csc", "csch", "arccsc", "arccsch",
	/*4--*/"mean", "geometricMean", "harmonicMean", "trimMean", "count", "median", "firstQuartile", "thirdQuartile", "mode", "min", "max",
	"percentile", "large", "small", "range", "interQuantileRange", "absdev", "stddev", "variance", "cv", "skewness", "kurtosis",
	"covariance", "correlation", "pearsonCorrelation", "rankCorrelation", "autoCorrelation1", "autoCorrelation", "npv", "irr", 
	/*"empiricalDiscreteDist", "empiricalDiscreteCum", */"discreteUniformDist", "discreteUniformCum", "discreteUniformInv",
	"bernoulliDist", "bernoulliCum", "bernoulliInv", "binomialDist", "binomialCum", "binomialInv", "multinomialDist", "multinomialCum", "multinomialInv",
	"hypergeometricDist", "hypergeometricCum", "hypergeometricInv", "poissonDist", "poissonCum", "poissonInv",
	"geometricDist", "geometricCum", "geometricInv", "negativeBinomialDist", "negativeBinomialCum", "negativeBinomialInv",
	/*"empiricalContinousDist", "empiricalContinuousCum",*/ "uniformDist", "uniformCum", "uniformInv",
	"normalDist", "normalCum", "normalInv", "stdNormalDist", "stdNormalCum", "stdNormalInv", "bivariateNormalDist", "bivariateNormalCum",
	"exponentialDist", "exponentialCum", "exponentialInv", "weibullDist", "weibullCum", "weibullInv", "erlangDist", "erlangCum", "erlangInv",
	"gammaDist", "gammaCum", "gammaInv", "betaDist", "betaCum", "betaInv", "betaGeneralDist", "betaGeneralCum", "betaGeneralInv",
	"lognormalDist", "lognormalCum", "lognormalInv", "cauchyDist", "cauchyCum", "cauchyInv", "tDist", "tCum", "tInv",
	"chiSquareDist", "chiSquareCum", "chiSquareInv", "fDist", "fCum", "fInv", "logisticDist", "logisticCum", "logisticInv",
	"logLogisticDist", "logLogisticCum", "logLogisticInv", "logarithmicDist", "logarithmicCum", "logarithmicInv",
	"paretoDist", "paretoCum", "paretoDist", "rayleighDist", "rayleighCum", "rayleighInv", "pertDist", "pertCum", "pertDist",
	"triangularDist", "triangularCum", "triangularInv",
	/*5--*/"number", "identifier", "PI", "E", "INF", "EPS", "TRUE", "FALSE", "EULERGAMMA", "NAN",
	/*6--*/"variable", "objective", "constraint",
	/*7--*/"if", "lt", "leq", "gt", "geq", "eq", "neq", "and", "or", "xor", "implies", "not",
	"forAll", "exists", "logicCount", "allDiff", /*"allDisjoint",*/ "atMost", "atLeast", "exactly", 
	"inSet", "inRealSet", "inPositiveRealSet", "inNonnegativeRealSet", "inIntegerSet", "inPositiveIntegerSet","inNonnegativeIntegerSet",
	/*8--*/
	/*9--*/"qTerm", "quadratic", "sim", "simInput", "simOutput", "userF", "arg", "xPath", "xPathIndex",
	"nodeRef", "arcRef", "complements", /*"prob",*/
};



static int m_miNodeIndexes[] = {
	/*1--*/1001, 1002, 1003, 1004, 1005, 1006,
	1007, 1008, 1009, 1010,
	/*2--*/2001, 2002, 2003, 2004, 2005, 2006, 2007, 2008, 2009, 2010,
	2011, 2012, 2013, 2014, 2015, 2016, 2017, 2018, 2019, 2020, 2021, 2022,
	/*3--*/3001, 3002, 3003, 3004, 3005, 3006, 3007, 3008, 3009, 3010, 3011, 3012,
	3013, 3014, 3015, 3016, 3017, 3018, 3019, 3020, 3021, 3022, 3023, 3024,
	/*4--*/4001, 4002, 4003, 4004, 4005, 4006, 4007, 4008, 4009, 4010, 4011,
	4012, 4013, 4014, 4015, 4016, 4017, 4018, 4019, 4020, 4021, 4022,
	4023, 4024, 4025, 4026, 4027, 4028, 4029, 4030,
	/*4101, 4102, */4111, 4112, 4113,
	4121, 4122, 4123, 4131, 4132, 4133, 4141, 4142, 4143,
	4151, 4152, 4153, 4161, 4162, 4163,
	4171, 4172, 4173, 4181, 4182, 4183,
	/*4401, 4402,*/ 4411, 4412, 4413,
	4421, 4422, 4423, 4431, 4432, 4433, 4441, 4442,
	4451, 4452, 4453, 4461, 4462, 4463, 4471, 4472, 4473,
	4481, 4482, 4483, 4491, 4492, 4493, 4501, 4502, 4503,
	4511, 4512, 4513, 4521, 4522, 4523, 4531, 4532, 4533,
	4541, 4542, 4543, 4551, 4552, 4553, 4561, 4562, 4563,
	4571, 4572, 4573, 4581, 4582, 4583,
	4591, 4592, 4593, 4601, 4602, 4603, 4611, 4612, 4613,
	4621, 4622, 4623,
	/*5--*/5001, 5002, 5003, 5004, 5005, 5006, 5007, 5008, 5009, 5010,
	/*6--*/6001, 6002, 6003,
	/*7--*/7001, 7002, 7003, 7004, 7005, 7006, 7007, 7008, 7009, 7010, 7011, 7012,
	7013, 7014, 7015, 7016, /*7017,*/ 7018, 7019, 7020, 
	7021, 7022, 7023, 7024, 7025, 7026, 7027,
	/*8--*/
	/*9--*/9001, 9002, 9003, 9004, 9005, 9006, 9007, 9008, 9009,
	9010, 9011, 9012, /*9013,*/
};

static int m_miNodeTypes[] = {
	/*1--*/2, -1, 2, 1, 2, 2,
	2, 2, 2, -1,
	/*2--*/1, 1, 1, 1, 1, 1, 1, 2, 1, 1,
	1, 2, 2, -1, -1, 1, 2, 2, 1, 1, 1, 1,
	/*3--*/1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
	1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
	/*4--*/-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
	-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
	-1, -1, -1, -1, -1, -1, -1, -1,
	/*-1, -1, */2, 2, 2,
	2, 2, 2, 3, 3, 3, -1, -1, -1,
	4, 4, 4, 2, 2, 2,
	2, 2, 2, 3, 3, 3,
	/*-1, -1,*/ 3, 3, 3,
	3, 3, 3, 1, 1, 1, 7, 7,
	2, 2, 2, 4, 4, 4, 3, 3, 3,
	3, 3, 3, 3, 3, 3, 5, 5, 5,
	3, 3, 3, 3, 3, 3, 2, 2, 2,
	2, 2, 2, 3, 3, 3, 3, 3, 3,
	3, 3, 3, 3, 3, 3,
	3, 3, 3, 2, 2, 2, 4, 4, 4,
	4, 4, 4,
	/*5--*/0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	/*6--*/-1, -1, -1,
	/*7--*/3, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1,
	-1, -1, -1, -1, /*-1,*/ -1, -1, -1, 
	-1, 1, 1, 1, 1, 1, 1
	/*8--*/
	/*9--*/-1, -1, -1, -1, -1, -1, 0, -1, -1,
	-1, -1, 2, /*1,*/
};

   

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
	Printf ("op %d  optype %d  ", opnum, optype[opnum]);
	switch(opnum) {
		case OPPLUS:
			cout << "FOUND  PLUS NODE"  << endl;
			nlNodePoint = new OSnLNodePlus();
			nlNodePoint->m_mChildren[0] = walkTree (e->L.e);
			nlNodePoint->m_mChildren[1] = walkTree (e->R.e);
			return nlNodePoint;
			
		case OPSUMLIST:
			i = 0;
			cout << "INSIDE SUM OPERATOR" << endl;
			nlNodePoint = new OSnLNodeSum();
			nlNodePoint->inumberOfChildren = e->R.ep - e->L.ep;
			nlNodePoint->m_mChildren = new OSnLNode*[ e->R.ep - e->L.ep];
			for (ep = e->L.ep; ep < e->R.ep; *ep++) 
				nlNodePoint->m_mChildren[i++] = walkTree ( *ep);
			return nlNodePoint;
			
		case MAXLIST:
			i = 0;
			cout << "INSIDE MAX OPERATOR" << endl;
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
			cout << "FOUND MULT NODE"  << endl;
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
			nlNodePoint = new OSnLNodePower();
			nlNodePoint->m_mChildren[0] = walkTree (e->L.e);
			nlNodePoint->m_mChildren[1] = walkTree (e->R.e); 
			return nlNodePoint;
			
			
		case OP1POW:
			nlNodePoint = new OSnLNodePower();
			nlNodePoint->m_mChildren[0] = walkTree (e->L.e);
			nlNodeNumberPoint = new OSnLNodeNumber();
			nlNodeNumberPoint->value = e->R.en->v;
			nlNodePoint->m_mChildren[1] = nlNodeNumberPoint;
			return nlNodePoint;
			
		case OP2POW:
			nlNodePoint = new OSnLNodePower();
			nlNodePoint->m_mChildren[0] = walkTree (e->L.e);
			nlNodeNumberPoint = new OSnLNodeNumber();
			nlNodeNumberPoint->value = 2;
			nlNodePoint->m_mChildren[1] = nlNodeNumberPoint;
			return nlNodePoint;
			
		case OPCPOW:
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
			
		case OP_exp:
			nlNodePoint = new OSnLNodeExp();
			nlNodePoint->m_mChildren[0] = walkTree (e->L.e);
			return nlNodePoint;
			
		case ABS:
			nlNodePoint = new OSnLNodeAbs();
			nlNodePoint->m_mChildren[0] = walkTree (e->L.e);
			return nlNodePoint;
			
		case OPNUM:
			cout << "found a number node" << endl;
			nlNodeNumberPoint = new OSnLNodeNumber;
			cout << "THE NUMBER" << (double) ((expr_n*)e)->v << endl;
			nlNodeNumberPoint->value = (double) ((expr_n*)e)->v;
			return nlNodeNumberPoint;
			
		case OPVARVAL:
			cout << "found a variable node" << endl;
			nlNodeVariablePoint = new OSnLNodeVariable;
			nlNodeVariablePoint->idx = e->a;
			nlNodeVariablePoint->coef = 1.0; 
			return nlNodeVariablePoint;
			
		default:
			cout << "operator number not implemented  " <<  opnum  << endl;
			// exit(1);
	}
}


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
		osinstance->addVariable(i, var_name(i), 
			LUv[2*i] > -OSINFINITY  ? LUv[2*i] : -OSINFINITY, 
			LUv[2*i+1] < OSINFINITY ? LUv[2*i+1] : OSINFINITY, 
			vartype, init, initString);
	}	
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
	delete objectiveCoefficients; // delete the temporary sparse vector
	objectiveCoefficients = NULL;
	//
	// now fill in row information
	//
	osinstance->setConstraintNumber( n_con);
	double constant = OSNAN;
	std::string rowName;
	for(i = 0; i < n_con; i++)
	{
		osinstance->addConstraint(i, con_name(i), 
		LUrhs[2*i] > -OSINFINITY ? LUrhs[2*i] : -OSINFINITY, 
		LUrhs[2*i+1] < OSINFINITY ? LUrhs[2*i+1] : OSINFINITY, 
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
		if(nlc > 0){
			while (iNLidx < nlc) {
				m_treeRoot = walkTree ((CON_DE + iNLidx)->e);
				osinstance->instanceData->nonlinearExpressions->nl[ iNLidx] = new Nl();
				osinstance->instanceData->nonlinearExpressions->nl[ iNLidx]->idx = iNLidx;
				osinstance->instanceData->nonlinearExpressions->nl[ iNLidx]->osExpressionTree = new OSExpressionTree();
				osinstance->instanceData->nonlinearExpressions->nl[ iNLidx]->osExpressionTree->m_treeRoot = m_treeRoot;
				iNLidx++;
				//cout << m_treeRoot->getNonlinearExpressionInXML() << endl;
			}
		}
		if(nlo > 0){
			while ( iNLidx < nlc + nlo){
				m_treeRoot = walkTree ((OBJ_DE + iNLidx - nlc)->e);
				osinstance->instanceData->nonlinearExpressions->nl[ iNLidx] = new Nl();
				osinstance->instanceData->nonlinearExpressions->nl[ iNLidx]->idx = -1 - (iNLidx - nlc);
				osinstance->instanceData->nonlinearExpressions->nl[ iNLidx]->osExpressionTree = new OSExpressionTree();
				osinstance->instanceData->nonlinearExpressions->nl[ iNLidx]->osExpressionTree->m_treeRoot = m_treeRoot;
				iNLidx++;
				//cout << m_treeRoot->getNonlinearExpressionInXML() << endl;
			}
		}

	}
	//
	// end loop of nonlinear rows
	//    
	OSiLWriter osilwriter;
	cout << osilwriter.writeOSiL( osinstance);
	cout << "DONE WITH OSIL2NL" << endl;
	return true;
}
