/* $Id: OSnl2OS.cpp 4210 2011-06-28 09:44:54Z stefan $ */
/** @file OSnl2OS.cpp
 * 
 * @author  Horand Gassmann, Jun Ma, Kipp Martin
 *
 * \remarks
 * Copyright (C) 2012, Horand Gassmann, Jun Ma, Kipp Martin,
 * Dalhousie University, and the University of Chicago.
 * All Rights Reserved.
 * This software is licensed under the Eclipse Public License. 
 * Please see the accompanying LICENSE file in root directory for terms.
 * 
 */

/**  
 *
 * <p><code>OSnl2OS</code> is used to convert information in AMPL nl format
 * to OS objects (OSInstance and OSOption/OSoL string) </p>
 *
 */

#include <iostream>
#include "OSiLWriter.h"
#include "OSoLWriter.h"
#include "OSoLReader.h"
#include "OSnl2OS.h"
#include "OSOption.h"
#include "OSErrorClass.h"
#include "OSMathUtil.h"

#include "CoinHelperFunctions.hpp"


#include "nlp.h"
#include "getstub.h"
#include "r_opn.hd" /* for N_OPS */
#include "opcode.hd"

#ifdef HAVE_CMATH
# include <cmath>
#else
# ifdef HAVE_CMATH_H
#  include <cmath.h>
# endif
#endif

#include <sstream>


#define R_OPS  ((ASL_fg*)asl)->I.r_ops_
#define OBJ_DE ((ASL_fg*)asl)->I.obj_de_
#define VAR_E  ((ASL_fg*)asl)->I.var_e_
#define CON_DE ((ASL_fg*)asl)->I.con_de_


#include <asl.h>
//#include "sufinfo.h"

using std::cerr;
using std::cout;
using std::endl;

#ifdef HAVE_STDINT_H
#include <stdint.h>
#endif

#ifdef HAVE_STDLIB_H
#include <stdlib.h>
#endif

#define AMPLDEBUG


OSnl2OS::OSnl2OS(std::string nlfilename, std::string osol)
    : osolreader (NULL), osinstance(NULL), osoption(NULL), stub(nlfilename)
{
    efunc *r_ops_int[N_OPS];
    FILE *nl;

    //Initialize the AMPL library
    asl = cw = ASL_alloc( ASL_read_fg);

    //Initialize the nl file reading
    nl = jac0dim(const_cast<char*>(stub.c_str()), (fint)stub.length());

    //Prepare *columnwise* parsing of nl file
    A_vals = (real *)Malloc(nzc*sizeof(real));

    // allocate initial values for primal and dual variables if available
    want_xpi0 = 3;

    // allocate space for initial values
    X0 = new real[n_var];
    havex0 = new char[n_var];
    pi0 = new real[n_con];
    havepi0 = new char[n_con];

#ifdef AMPLDEBUG
    cout << "number of nonzeros    = " << nzc     << endl;
    cout << "number of variables   = " << n_var   << endl;
    cout << "number of constraints = " << n_con   << endl;
    cout << "number of objectives  = " << n_obj   << endl;
    cout << "number of ranges      = " << nranges << endl;
    cout << "number of equations   = " << n_eqn   << endl;
#endif
    if(N_OPS > 0)
    {
        for(int i = 0; i < N_OPS; i++)
        {
            r_ops_int[i] = (efunc*)(unsigned long)i;
        }
        R_OPS = r_ops_int;
        want_derivs = 0;
        fg_read(nl, ASL_keep_all_suffixes);
        R_OPS = 0;
    }

    // Now create row-wise version
    asl = rw = ASL_alloc( ASL_read_fg);
    nl = jac0dim((char*)stub.c_str(), (fint)stub.length());
    want_derivs = 0;
    qp_read(nl, 0);

    asl = cw;
    numkount = 0;

#if 0
/**
 *  Next populate a table of AMPL suffixes. At present this uses a static set of suffixes;
 *  it is hoped that in time we can set things up dynamically through querying the .nl file.
 */

  static SufDecl suftab [] = {

/* Ipopt */

#ifdef COIN_HAS_IPOPT
	OS_addAmplSuffix{ "scaling_factor", 0, ASL_Sufkind_var  | ASL_Sufkind_real },
	OS_addAmplSuffix{ "scaling_factor", 0, ASL_Sufkind_con  | ASL_Sufkind_real },
	OS_addAmplSuffix{ "scaling_factor", 0, ASL_Sufkind_obj  | ASL_Sufkind_real },
	OS_addAmplSuffix{ "ipopt_zL_out",   0, ASL_Sufkind_var  | ASL_Sufkind_real },
	OS_addAmplSuffix{ "ipopt_zU_out",   0, ASL_Sufkind_var  | ASL_Sufkind_real },
	OS_addAmplSuffix{ "ipopt_zL_in",    0, ASL_Sufkind_var  | ASL_Sufkind_real },
	OS_addAmplSuffix{ "ipopt_zU_in",    0, ASL_Sufkind_var  | ASL_Sufkind_real },
#endif

/* Couenne */

#ifdef COIN_HAS_COUENNE
	OS_addAmplSuffix{const_cast<char*>("newlb"), 0,  ASL_Sufkind_var | ASL_Sufkind_real | ASL_Sufkind_output, 0},
	OS_addAmplSuffix{const_cast<char*>("newub"), 0,  ASL_Sufkind_var | ASL_Sufkind_real | ASL_Sufkind_output, 0},
#endif

/* Cbc */

#ifdef COIN_HAS_CBC
# ifdef JJF_ZERO
    OS_addAmplSuffix{ const_cast<char*>("current"), 0, ASL_Sufkind_con | ASL_Sufkind_outonly },
    OS_addAmplSuffix{ const_cast<char*>("current"), 0, ASL_Sufkind_var | ASL_Sufkind_outonly },
    OS_addAmplSuffix{ const_cast<char*>("direction"), 0, ASL_Sufkind_var },
    OS_addAmplSuffix{ const_cast<char*>("down"), 0, ASL_Sufkind_con | ASL_Sufkind_outonly },
    OS_addAmplSuffix{ const_cast<char*>("down"), 0, ASL_Sufkind_var | ASL_Sufkind_outonly },
    OS_addAmplSuffix{ const_cast<char*>("priority"), 0, ASL_Sufkind_var },
# endif
    OS_addAmplSuffix{ const_cast<char*>("cut"), 0, ASL_Sufkind_con },
    OS_addAmplSuffix{ const_cast<char*>("direction"), 0, ASL_Sufkind_var },
    OS_addAmplSuffix{ const_cast<char*>("downPseudocost"), 0, ASL_Sufkind_var | ASL_Sufkind_real },
    OS_addAmplSuffix{ const_cast<char*>("priority"), 0, ASL_Sufkind_var },
    OS_addAmplSuffix{ const_cast<char*>("ref"), 0, ASL_Sufkind_var | ASL_Sufkind_real },
    OS_addAmplSuffix{ const_cast<char*>("sos"), 0, ASL_Sufkind_var },
    OS_addAmplSuffix{ const_cast<char*>("sos"), 0, ASL_Sufkind_con },
    OS_addAmplSuffix{ const_cast<char*>("sosno"), 0, ASL_Sufkind_var | ASL_Sufkind_real },
    OS_addAmplSuffix{ const_cast<char*>("sosref"), 0, ASL_Sufkind_var | ASL_Sufkind_real },
    OS_addAmplSuffix{ const_cast<char*>("special"), 0, ASL_Sufkind_var },
    OS_addAmplSuffix{ const_cast<char*>("special"), 0, ASL_Sufkind_con },
    OS_addAmplSuffix{ const_cast<char*>("sstatus"), 0, ASL_Sufkind_var, 0 },
    OS_addAmplSuffix{ const_cast<char*>("sstatus"), 0, ASL_Sufkind_con, 0 },
    OS_addAmplSuffix{ const_cast<char*>("upPseudocost"), 0, ASL_Sufkind_var | ASL_Sufkind_real }
# ifdef JJF_ZERO
    OS_addAmplSuffix{ const_cast<char*>("unbdd"), 0, ASL_Sufkind_var | ASL_Sufkind_outonly},
    OS_addAmplSuffix{ const_cast<char*>("up"), 0, ASL_Sufkind_con | ASL_Sufkind_outonly },
    OS_addAmplSuffix{ const_cast<char*>("up"), 0, ASL_Sufkind_var | ASL_Sufkind_outonly }
# endif
#endif

/* CPLEX */

#ifdef COIN_HAS_CPLEX
	OS_addAmplSuffix{ "absmipgap", 0, ASL_Sufkind_obj  | ASL_Sufkind_outonly },
	OS_addAmplSuffix{ "absmipgap", 0, ASL_Sufkind_prob  | ASL_Sufkind_outonly },
	OS_addAmplSuffix{ "basis_cond", 0, ASL_Sufkind_obj  | ASL_Sufkind_outonly },
	OS_addAmplSuffix{ "basis_cond", 0, ASL_Sufkind_prob  | ASL_Sufkind_outonly },
	OS_addAmplSuffix{ "bestbound", 0, ASL_Sufkind_obj  | ASL_Sufkind_outonly },
	OS_addAmplSuffix{ "bestbound", 0, ASL_Sufkind_prob | ASL_Sufkind_outonly },
	OS_addAmplSuffix{ "bestnode", 0, ASL_Sufkind_obj  | ASL_Sufkind_outonly },
	OS_addAmplSuffix{ "bestnode", 0, ASL_Sufkind_prob | ASL_Sufkind_outonly },
	OS_addAmplSuffix{ "current", 0, ASL_Sufkind_con | ASL_Sufkind_outonly },
	OS_addAmplSuffix{ "current", 0, ASL_Sufkind_var | ASL_Sufkind_outonly },
	OS_addAmplSuffix{ "direction", 0, ASL_Sufkind_var },
	OS_addAmplSuffix{ "down", 0, ASL_Sufkind_con | ASL_Sufkind_outonly },
	OS_addAmplSuffix{ "down", 0, ASL_Sufkind_var | ASL_Sufkind_outonly },
	OS_addAmplSuffix{ "dunbdd", 0, ASL_Sufkind_con | ASL_Sufkind_outonly },
	OS_addAmplSuffix{ "iis", iis_table, ASL_Sufkind_var | ASL_Sufkind_outonly },
	OS_addAmplSuffix{ "iis", 0, ASL_Sufkind_con | ASL_Sufkind_outonly },
# ifdef CPX_PARAM_FEASOPTMODE /* >= 9.2b */
	OS_addAmplSuffix{ "lazy", 0, ASL_Sufkind_con },
# endif
# ifdef CPX_PARAM_POPULATELIM
	OS_addAmplSuffix{ "npool", 0, ASL_Sufkind_prob | ASL_Sufkind_outonly},
# endif
	OS_addAmplSuffix{ "priority", 0, ASL_Sufkind_var },
	OS_addAmplSuffix{ "ref", 0, ASL_Sufkind_var | ASL_Sufkind_real },
	OS_addAmplSuffix{ "relmipgap", 0, ASL_Sufkind_obj  | ASL_Sufkind_outonly },
	OS_addAmplSuffix{ "relmipgap", 0, ASL_Sufkind_prob  | ASL_Sufkind_outonly },
	OS_addAmplSuffix{ "sos", 0, ASL_Sufkind_var },
	OS_addAmplSuffix{ "sos", 0, ASL_Sufkind_con },
	OS_addAmplSuffix{ "sosno", 0, ASL_Sufkind_var | ASL_Sufkind_real },
	OS_addAmplSuffix{ "sosref", 0, ASL_Sufkind_var | ASL_Sufkind_real },
	OS_addAmplSuffix{ "sstatus", 0, ASL_Sufkind_var, 1 },
	OS_addAmplSuffix{ "sstatus", 0, ASL_Sufkind_con, 1 },
	OS_addAmplSuffix{ "unbdd", 0, ASL_Sufkind_var | ASL_Sufkind_outonly},
	OS_addAmplSuffix{ "up", 0, ASL_Sufkind_con | ASL_Sufkind_outonly },
	OS_addAmplSuffix{ "up", 0, ASL_Sufkind_var | ASL_Sufkind_outonly }
#endif

/* Gurobi */

#ifdef COIN_HAS_GUROBI
	OS_addAmplSuffix{ "absmipgap", 0, ASL_Sufkind_obj   | ASL_Sufkind_outonly },
	OS_addAmplSuffix{ "absmipgap", 0, ASL_Sufkind_prob  | ASL_Sufkind_outonly },
	OS_addAmplSuffix{ "bestbound", 0, ASL_Sufkind_obj   | ASL_Sufkind_outonly },
	OS_addAmplSuffix{ "bestbound", 0, ASL_Sufkind_prob  | ASL_Sufkind_outonly },
# if GRB_VERSION_MAJOR >= 4 && GRB_VERSION_MINOR >= 5 /*{*/
	OS_addAmplSuffix{ "dunbdd", 0, ASL_Sufkind_con | ASL_Sufkind_outonly },
# endif /*}*/
	OS_addAmplSuffix{ "iis", iis_table, ASL_Sufkind_var | ASL_Sufkind_outonly },
	OS_addAmplSuffix{ "iis", 0, ASL_Sufkind_con | ASL_Sufkind_outonly },
	OS_addAmplSuffix{ "ref", 0, ASL_Sufkind_var | ASL_Sufkind_real },
	OS_addAmplSuffix{ "relmipgap", 0, ASL_Sufkind_obj   | ASL_Sufkind_outonly },
	OS_addAmplSuffix{ "relmipgap", 0, ASL_Sufkind_prob  | ASL_Sufkind_outonly },
	OS_addAmplSuffix{ "senslbhi",  0, ASL_Sufkind_var | ASL_Sufkind_real | ASL_Sufkind_outonly },
	OS_addAmplSuffix{ "senslblo",  0, ASL_Sufkind_var | ASL_Sufkind_real | ASL_Sufkind_outonly },
	OS_addAmplSuffix{ "sensobjhi", 0, ASL_Sufkind_var | ASL_Sufkind_real | ASL_Sufkind_outonly },
	OS_addAmplSuffix{ "sensobjlo", 0, ASL_Sufkind_var | ASL_Sufkind_real | ASL_Sufkind_outonly },
	OS_addAmplSuffix{ "sensrhshi", 0, ASL_Sufkind_con | ASL_Sufkind_real | ASL_Sufkind_outonly },
	OS_addAmplSuffix{ "sensrhslo", 0, ASL_Sufkind_con | ASL_Sufkind_real | ASL_Sufkind_outonly },
	OS_addAmplSuffix{ "sensubhi",  0, ASL_Sufkind_var | ASL_Sufkind_real | ASL_Sufkind_outonly },
	OS_addAmplSuffix{ "sensublo",  0, ASL_Sufkind_var | ASL_Sufkind_real | ASL_Sufkind_outonly },
	OS_addAmplSuffix{ "sos", 0, ASL_Sufkind_var },
	OS_addAmplSuffix{ "sos", 0, ASL_Sufkind_con },
	OS_addAmplSuffix{ "sosno", 0, ASL_Sufkind_var | ASL_Sufkind_real },
	OS_addAmplSuffix{ "sosref", 0, ASL_Sufkind_var | ASL_Sufkind_real },
	OS_addAmplSuffix{ "sstatus", 0, ASL_Sufkind_var, 1 },
	OS_addAmplSuffix{ "sstatus", 0, ASL_Sufkind_con, 1 }
# if GRB_VERSION_MAJOR >= 4 && GRB_VERSION_MINOR >= 5 /*{*/
	,{ "unbdd", 0, ASL_Sufkind_var | ASL_Sufkind_outonly }
# endif /*}*/
#endif
	};
#endif



    // store the osol string into the OSnl2OS object
    this->osol = osol;


}


OSnl2OS::~OSnl2OS()
{
    if (osinstance != NULL) delete osinstance;
    osinstance = NULL;

    if (osolreader != NULL) 
    {
        delete osolreader;
        osolreader = NULL;
    }
    else
    {    
        if (osoption != NULL) delete osoption;
        osoption = NULL;
    }

    free( A_vals);
    if (X0)      delete [] X0;      X0      = NULL;
    if (havex0)  delete [] havex0;  havex0  = NULL;
    if (pi0)     delete [] pi0;     pi0     = NULL;
    if (havepi0) delete [] havepi0; havepi0 = NULL;
    ASL_free(&cw);
    ASL_free(&rw);
}


OSnLNode* OSnl2OS::walkTree (expr *e)
{
    OSnLNode *nlNodePoint;
    OSnLNodeVariable *nlNodeVariablePoint;
    OSnLNodeNumber *nlNodeNumberPoint;
    efunc *op;
    expr **ep;
    int opnum;
    int i;
    //std::cout << "Variable Index " << varIdx << std::endl;
    int j = ((expr_v *)e - VAR_E) - osinstance->getVariableNumber() ;
    //std::cout << "GET OPERATOR NUMBER" << std::endl;
    op = e->op;
    opnum = Intcast op;
    //std::cout << "OPERATOR NUMBER = " << opnum << std::endl;
    //Printf ("op %d  optype %d  ", opnum, optype[opnum]);
    try
    {
        switch( opnum)
        {
        case OPPLUS:
            //cout << "FOUND  PLUS NODE"  << endl;
            nlNodePoint = new OSnLNodePlus();
            nlNodePoint->m_mChildren[0] = walkTree (e->L.e);
            nlNodePoint->m_mChildren[1] = walkTree (e->R.e);
            op_type.push_back( "PLUS");
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
            op_type.push_back( "MINUS");

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
            op_type.push_back( "TIMES");
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
            op_type.push_back( "POWER");
            return nlNodePoint;


        case OP1POW:
            //cout << "FOUND OP1POW NODE"  << endl;
            //cout << "OP1POW EXPONENT =  "  << e->R.en->v<<  endl;
            nlNodePoint = new OSnLNodePower();


            nlNodePoint->m_mChildren[0] = walkTree (e->L.e);
            nlNodeNumberPoint = new OSnLNodeNumber();
            nlNodeNumberPoint->value = e->R.en->v;
            nlNodePoint->m_mChildren[1] = nlNodeNumberPoint;

            op_type.push_back( "NUMBER");
            op_type.push_back( os_dtoa_format( numkount) );
            operand.push_back( e->R.en->v );
            numkount++;

            op_type.push_back( "POWER");


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
            op_type.push_back( "SQUARE");
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
            op_type.push_back( "LOG");
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
            //cout << "THE NUMBER" << (double) ((expr_n*)e)->v << endl;
            nlNodeNumberPoint->value = (double) ((expr_n*)e)->v;
            op_type.push_back( "NUMBER");
            op_type.push_back( os_dtoa_format(  numkount ) );

            operand.push_back( (double) ((expr_n*)e)->v   );
            numkount++;


            return nlNodeNumberPoint;

        case OPVARVAL:
            //cout << "found a variable node" << endl;
            // treat the common expression or defined variables
            if( j >= 0 )
            {
                // process common expression
                /*
                std::cout << "como = "  << como  << std::endl;
                std::cout << "comc = "  << comc  << std::endl;
                std::cout << "comb = "  << comb  << std::endl;
                std::cout << "como1 = "  << como1  << std::endl;
                std::cout << "comc1 = "  << comc1  << std::endl;
                std::cout << "ncom0 = "  << ncom0  << std::endl;
                std::cout << "jjjjjjjjjjjjjjjjjj = "  << j  << std::endl;
                */

                // Orban: http://www.gerad.ca/~orban/drampl/def-vars.html
                if(j < ncom0)
                {
                    struct cexp *common = ((const ASL_fg *) asl) -> I.cexps_ + j ;
                    //walk the tree for the non-linear stuff

                    // now add the linear terms
                    int nlin = common -> nlin;
                    //std::cout << "Number of linear terms in common expression " << nlin << std::endl;

                    if( nlin > 0)
                    {
                        nlNodePoint = new OSnLNodeSum();
                        nlNodePoint->inumberOfChildren = nlin + 1;
                        nlNodePoint->m_mChildren = new OSnLNode*[ nlin + 1];
                        // we have linear variables
                        // get the index and coefficient
                        linpart *L = common -> L;
                        for(int kj = 0; kj < nlin; kj++)
                        {

                            // get the coefficient
                            //std::cout << "Linear coefficient  "  << L [kj].fac << std::endl;

                            // get the index
                            //std::cout  << "Variable index  "  << ((uintptr_t) (L [kj].v.rp) - (uintptr_t) VAR_E) / sizeof (expr_v) << std::endl;
                            // add an OSnLSumNode with the linear terms
                            nlNodePoint->m_mChildren[ kj] = new OSnLNodeVariable;
                            nlNodeVariablePoint = (OSnLNodeVariable*)nlNodePoint->m_mChildren[ kj];
                            nlNodeVariablePoint->coef = L [kj]. fac;
                            nlNodeVariablePoint->idx = ((uintptr_t) (L [kj].v.rp) - (uintptr_t) VAR_E) / sizeof (expr_v);
                        }
                        nlNodePoint->m_mChildren[ nlin] = walkTree(  common->e);
                        return nlNodePoint;
                    }
                    else return walkTree(  common->e);
                }
                else
                {
                    struct cexp1 *common = ((const ASL_fg *) asl) -> I.cexps1_ + (j - ncom0);
                    //walk the tree for the non-linear stuff

                    // now add the linear terms
                    int nlin = common -> nlin;
                    //std::cout << "Number of linear terms in common expression " << nlin << std::endl;

                    if( nlin > 0)
                    {
                        nlNodePoint = new OSnLNodeSum();
                        nlNodePoint->inumberOfChildren = nlin + 1;
                        nlNodePoint->m_mChildren = new OSnLNode*[ nlin + 1];
                        // we have linear variables
                        // get the index and coefficient
                        linpart *L = common -> L;
                        for(int kj = 0; kj < nlin; kj++)
                        {

                            // get the coefficient
                            //std::cout << "Linear coefficient  "  << L [kj].fac << std::endl;

                            // get the index
                            //std::cout  << "Variable index  "  << ((uintptr_t) (L [kj].v.rp) - (uintptr_t) VAR_E) / sizeof (expr_v) << std::endl;
                            // add an OSnLSumNode with the linear terms
                            nlNodePoint->m_mChildren[ kj] = new OSnLNodeVariable;
                            nlNodeVariablePoint = (OSnLNodeVariable*)nlNodePoint->m_mChildren[ kj];
                            nlNodeVariablePoint->coef = L [kj]. fac;
                            nlNodeVariablePoint->idx = ((uintptr_t) (L [kj].v.rp) - (uintptr_t) VAR_E) / sizeof (expr_v);
                        }
                        nlNodePoint->m_mChildren[ nlin] = walkTree(  common->e);
                        return nlNodePoint;
                    }
                    else return walkTree(  common->e);
                }
            }
            //if(e->a > osinstance->getVariableNumber() ) throw ErrorClass("OS cannot handle AMPL user defined variables, please reformulate");
            nlNodeVariablePoint = new OSnLNodeVariable;
            nlNodeVariablePoint->idx = e->a;
            nlNodeVariablePoint->coef = 1.0;

            op_type.push_back( "VARIABLE");
            op_type.push_back( os_dtoa_format(  e->a  ) );


            return nlNodeVariablePoint;
            break;
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
    catch(const ErrorClass& eclass)
    {
        throw;
    }
}//walkTree

static inline char integerOrBinary(real upper, real lower)
{
    if (lower > -1.0 + OS_EPS && upper < 2.0 - OS_EPS)
        return 'B';
    return 'I';
}





bool OSnl2OS::createOSObjects()
{
    int *A_rowstarts = NULL;
    int *A_colptr = NULL;
    double *A_nzelem = NULL;
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
    std::string colName;
    char vartype = 'C';
    osinstance->setVariableNumber( n_var);

    //first the nonlinear variables
    //welcome to the world of the ASL API

    int lower;
    int upper;
    lower = 0;
    upper = nlvb - nlvbi;
#ifdef AMPLDEBUG
    std::cout << "LOWER = " << lower << std::endl;
    std::cout << "UPPER = " << upper << std::endl;
#endif
    for(i = lower; i < upper; i++)  //continuous in an objective and in a constraint
    {
        vartype = 'C';
        osinstance->addVariable(i, var_name(i),
                                LUv[2*i]   > -OSDBL_MAX ? LUv[2*i]   : -OSDBL_MAX,
                                LUv[2*i+1] <  OSDBL_MAX ? LUv[2*i+1] :  OSDBL_MAX,
                                vartype);
    }

    lower = nlvb - nlvbi;
    upper = (nlvb - nlvbi) + nlvbi;
    upper = nlvb; //
#ifdef AMPLDEBUG
    std::cout << "LOWER = " << lower << std::endl;
    std::cout << "UPPER = " << upper << std::endl;
#endif
    for(i = lower; i < upper; i++)  //integer in an objective and in a constraint
    {
        vartype = integerOrBinary(LUv[2*i], LUv[2*i+1]); // AMPL doesn't make the distinction for nonlinear variables
        osinstance->addVariable(i, var_name(i),
                                LUv[2*i]   > -OSDBL_MAX ? LUv[2*i]   : -OSDBL_MAX,
                                LUv[2*i+1] <  OSDBL_MAX ? LUv[2*i+1] :  OSDBL_MAX,
                                vartype);
    }

    lower = nlvb;
    upper = nlvb + (nlvc - (nlvb + nlvci)) ;
    upper = nlvc - nlvci;
#ifdef AMPLDEBUG
    std::cout << "LOWER = " << lower << std::endl;
    std::cout << "UPPER = " << upper << std::endl;
#endif
    for(i = lower; i < upper; i++)  //continuous just in constraints
    {
        vartype = 'C';
        osinstance->addVariable(i, var_name(i),
                                LUv[2*i]   > -OSDBL_MAX ? LUv[2*i]   : -OSDBL_MAX,
                                LUv[2*i+1] <  OSDBL_MAX ? LUv[2*i+1] :  OSDBL_MAX,
                                vartype);
    }


    lower = nlvc - nlvci;
    upper = nlvc - nlvci + nlvci;
    upper = nlvc;
#ifdef AMPLDEBUG
    std::cout << "LOWER = " << lower << std::endl;
    std::cout << "UPPER = " << upper << std::endl;
#endif
    for(i = lower; i < upper; i++)  //integer just in constraints
    {
        vartype =  integerOrBinary(LUv[2*i], LUv[2*i+1]); // AMPL doesn't make the distinction for nonlinear variables
        osinstance->addVariable(i, var_name(i),
                                LUv[2*i]   > -OSDBL_MAX ? LUv[2*i]   : -OSDBL_MAX,
                                LUv[2*i+1] <  OSDBL_MAX ? LUv[2*i+1] :  OSDBL_MAX,
                                vartype);
    }

    lower = nlvc;
    upper = nlvc + ( nlvo - (nlvc + nlvoi) );
    upper = nlvo - nlvoi;
#ifdef AMPLDEBUG
    std::cout << "LOWER = " << lower << std::endl;
    std::cout << "UPPER = " << upper << std::endl;
#endif
    for(i = lower; i < upper; i++)  //continuous just in objectives
    {
        vartype = 'C';
        osinstance->addVariable(i, var_name(i),
                                LUv[2*i]   > -OSDBL_MAX ? LUv[2*i]   : -OSDBL_MAX,
                                LUv[2*i+1] <  OSDBL_MAX ? LUv[2*i+1] :  OSDBL_MAX,
                                vartype);
    }

    lower = nlvo - nlvoi;
    upper = nlvo - nlvoi + nlvoi;
    upper = nlvo ;
#ifdef AMPLDEBUG
    std::cout << "LOWER = " << lower << std::endl;
    std::cout << "UPPER = " << upper << std::endl;
#endif
    for(i = lower; i < upper; i++)  //integer just in objectives
    {
        vartype = integerOrBinary(LUv[2*i], LUv[2*i+1]); // AMPL doesn't make the distinction for nonlinear variables
        osinstance->addVariable(i, var_name(i),
                                LUv[2*i]   > -OSDBL_MAX ? LUv[2*i]   : -OSDBL_MAX,
                                LUv[2*i+1] <  OSDBL_MAX ? LUv[2*i+1] :  OSDBL_MAX,
                                vartype);
    }


    //now the other variables

    lower = CoinMax(nlvc, nlvo);
    upper = CoinMax(nlvc, nlvo) + nwv;
#ifdef AMPLDEBUG
    std::cout << "LOWER = " << lower << std::endl;
    std::cout << "UPPER = " << upper << std::endl;
#endif
    for(i = lower; i < upper; i++)  //linear arc variables
    {
        vartype = 'C';
        osinstance->addVariable(i, var_name(i),
                                LUv[2*i]   > -OSDBL_MAX ? LUv[2*i]   : -OSDBL_MAX,
                                LUv[2*i+1] <  OSDBL_MAX ? LUv[2*i+1] :  OSDBL_MAX,
                                vartype);
    }


    lower = CoinMax(nlvc, nlvo) + nwv;
    upper = CoinMax(nlvc, nlvo) + nwv + (n_var - (CoinMax(nlvc, nlvo) + niv + nbv + nwv) );
    upper = n_var -  niv - nbv;
#ifdef AMPLDEBUG
    std::cout << "LOWER = " << lower << std::endl;
    std::cout << "UPPER = " << upper << std::endl;
#endif
    for(i = lower; i < upper; i++)  //other linear
    {
        vartype = 'C';
        osinstance->addVariable(i, var_name(i),
                                LUv[2*i]   > -OSDBL_MAX ? LUv[2*i]   : -OSDBL_MAX,
                                LUv[2*i+1] <  OSDBL_MAX ? LUv[2*i+1] :  OSDBL_MAX,
                                vartype);
    }


    lower = n_var -  niv - nbv;
    upper = n_var -  niv - nbv + nbv;
    upper = n_var -  niv ;
#ifdef AMPLDEBUG
    std::cout << "LOWER = " << lower << std::endl;
    std::cout << "UPPER = " << upper << std::endl;
#endif
    for(i = lower; i < upper; i++)  //linear binary
    {
        vartype = 'B';
        osinstance->addVariable(i, var_name(i),
                                LUv[2*i]   > -OSDBL_MAX ? LUv[2*i]   : -OSDBL_MAX,
                                LUv[2*i+1] <  OSDBL_MAX ? LUv[2*i+1] :  OSDBL_MAX,
                                vartype);
    }



    lower = n_var -  niv;
    upper = n_var -  niv  + niv;
    upper =   n_var;
#ifdef AMPLDEBUG
    std::cout << "LOWER = " << lower << std::endl;
    std::cout << "UPPER = " << upper << std::endl;
#endif
    for(i = lower; i < upper; i++)  //linear integer
    {
        vartype = 'I';
        osinstance->addVariable(i, var_name(i),
                                LUv[2*i]   > -OSDBL_MAX ? LUv[2*i]   : -OSDBL_MAX,
                                LUv[2*i+1] <  OSDBL_MAX ? LUv[2*i+1] :  OSDBL_MAX,
                                vartype);
    }


    // end of variables -- thank goodness!!!


/** Before we can process the rest of the instance, we check for QP
 *  This needs to be done here because of the possibility of expressions like (1 - x[0])^2
 *  which may modify the A matrix as well as the right-hand sides.
 *  If the A-matrix is modified, the column-wise representation
 *  is out of date and must be rebuilt from the row-wise form. 
 */ 
    std::vector<int> fidxs, v1idxs, v2idxs;
    std::vector<double> coeffs;
    std::vector<Nl> nlExprs;
    real* delsqp;
    fint* colqp;
    fint* rowqp;
    int osNLIdx; // OS n.l. function index
    int aNLIdx; // AMPL n.l. function index

    //Switch to row-wise format.
    asl = rw;

    // Iterate from -nlo to nlc-1 so that the qterms are sorted by idx

    // Process the objectives first, for which fill-in does not matter 
    for (osNLIdx = -nlo, aNLIdx = nlo-1; osNLIdx < 0; osNLIdx++, aNLIdx--)
    {
        if (nqpcheck(aNLIdx, &rowqp, &colqp, &delsqp) > 0) // quadratic
        {
            for (int v1 = 0; v1 < n_var; v1++)
            {
                for (int* psV2 = &rowqp[colqp[v1]]; psV2 < &rowqp[colqp[v1+1]]; psV2++, delsqp++)
                {
                    if (std::abs(*delsqp) > OS_EPS) // Try to exclude terms introduced by rounding
                    {
                        fidxs.push_back(osNLIdx);
                        v1idxs.push_back(v1);
                        v2idxs.push_back(*psV2);
                        coeffs.push_back(0.5 * *delsqp);
                    }
                }
            }
        }
        else // Nonlinear or error in nqpcheck
        {
            Nl nl;
            expr* e = aNLIdx < 0 ? CON_DE[osNLIdx].e : OBJ_DE[aNLIdx].e; // because osNLIdx = -aNLIdx-1
            nl.idx = osNLIdx;
            nl.osExpressionTree = new OSExpressionTree();
            nl.osExpressionTree->m_treeRoot = walkTree (e);
            nl.m_bDeleteExpressionTree = false;
            /*
             * Note: If the copy operation of the Nl class is changed from shallow
             * to deep, we will want to manage memory differently here.
             */
            nlExprs.push_back(nl);
        }
    }

    bool isQP = true;
    bool fill_in = false;
    int nqpchk;
    cgrad *cg;

    double* A_row_temp = new double[n_var];

    for (osNLIdx = 0, aNLIdx = -1; osNLIdx < nlc; osNLIdx++, aNLIdx--)
    {
        if (isQP)  // No need to identify quadratic terms once we have found a non-quadratic term
        {
            // check the nonzeroes before and after 
            if (!fill_in) // once we know there will be fill-in we can stop counting
            {
                for(cg = Cgrad[osNLIdx]; cg; cg = cg->next)
                {
                    if (cg->coef != 0) A_row_temp[cg->varno] = cg->coef;
                }
            }

            nqpchk = nqpcheck(aNLIdx, &rowqp, &colqp, &delsqp);
            if (nqpchk > 0) // quadratic
            {
                for (int v1 = 0; v1 < n_var; v1++)
                {
                    for (int* psV2 = &rowqp[colqp[v1]]; psV2 < &rowqp[colqp[v1+1]]; psV2++, delsqp++)
                    {
                        if (std::abs(*delsqp) > OS_EPS) // Try to exclude terms introduced by rounding
                        {
                            fidxs.push_back(osNLIdx);
                            v1idxs.push_back(v1);
                            v2idxs.push_back(*psV2);
                            coeffs.push_back(0.5 * *delsqp);
                        }
                    }
                }
                if (!fill_in) // once we know there will be fill-in we can stop counting
                {
                    for(cg = Cgrad[osNLIdx]; cg; cg = cg->next)
                    {
                        if (cg->coef != 0) 
                            if (cg->coef != A_row_temp[cg->varno]) 
                            {
                                fill_in = true;
                                break;
                            }
                    }
                }
                continue;
            }
            if (nqpchk < 0) isQP = false;
        }

// Nonlinear or error in nqpcheck
        {
            Nl nl;
            expr* e = aNLIdx < 0 ? CON_DE[osNLIdx].e : OBJ_DE[aNLIdx].e; // because osNLIdx = -aNLIdx-1
            nl.idx = osNLIdx;
            nl.osExpressionTree = new OSExpressionTree();
            nl.osExpressionTree->m_treeRoot = walkTree (e);
            nl.m_bDeleteExpressionTree = false;
            /*
             * Note: If the copy operation of the Nl class is changed from shallow
             * to deep, we will want to manage memory differently here.
             */
            nlExprs.push_back(nl);
        }
    }
    delete [] A_row_temp;

    if (nlExprs.size())
    {
        Nl** ppsNl = new Nl*[ nlExprs.size() ];
        for (i = 0; i < nlExprs.size(); i++)
        {
            ppsNl[i] = new Nl(nlExprs[i]); // See above note about shallow copy
            ppsNl[i]->m_bDeleteExpressionTree = true;
        }
        osinstance->instanceData->nonlinearExpressions->nl = ppsNl;
    }
    osinstance->instanceData->nonlinearExpressions->numberOfNonlinearExpressions = nlExprs.size();
    if (fidxs.size())
    {
        osinstance->setQuadraticTerms((int)fidxs.size(), &fidxs[0], &v1idxs[0], &v2idxs[0], &coeffs[0], 0, (int)fidxs.size()-1);
    }
    // Note: if we intended to call objval, conval etc with asl == rw later we must call qp_opify here.

    //
    // end loop of nonlinear rows
    //



    // now create the objective function
    // in the nl file, this is stored in dense form; convert to sparse.
    //
    double objWeight = 1.0;
    //	char	*objtype;	/* object type array: 0 == min, 1 == max */
    SparseVector* objectiveCoefficients = NULL;

    osinstance->setObjectiveNumber( n_obj) ;
    for(i = 0; i < n_obj; i++)
    {
        int n_obj_coef = 0;
        for(og = Ograd[i]; og; og = og->next)
        {
            if (og->coef != 0) n_obj_coef++;
        }
        objectiveCoefficients = new SparseVector( n_obj_coef);
        int i_obj_coef = -1;
        for(og = Ograd[i]; og; og = og->next)
        {
            if (fabs(og->coef) > OS_EPS)
            {
                i_obj_coef++;
                objectiveCoefficients->values[i_obj_coef] = og->coef;
                objectiveCoefficients->indexes[i_obj_coef] = og->varno;
            }
        }
        osinstance->addObjective(-i-1, obj_name(i),
                                 (objtype[i] == 1)?"max":"min",
                                 objconst( i),  objWeight, objectiveCoefficients) ;
        delete objectiveCoefficients; // delete the temporary sparse vector
        objectiveCoefficients = NULL;
    }


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
    //
    // Now the A-matrix
    // The treatment depends on whether there was fill-in during the QP check or not
    //
    if (fill_in) // store the matrix rowwise
    {
        int row_len;
        A_rowstarts = new int[n_con+1];
        A_rowstarts[0] = 0;
        for (int i=0; i < n_con; i++)
        {
            row_len = 0;
            for(cg = Cgrad[i]; cg; cg = cg->next)
            {
                if (cg->coef != 0) row_len++;
            }
            A_rowstarts[i+1] = A_rowstarts[i] + row_len;
        }
        A_colptr = new    int[A_rowstarts[n_con]];
        A_nzelem = new double[A_rowstarts[n_con]];
        for (int i=0; i < n_con; i++)
        {
            row_len = 0;
            for(cg = Cgrad[i]; cg; cg = cg->next)
            {
                if (cg->coef != 0) 
                {
                    A_colptr[A_rowstarts[i]+row_len] = cg->varno;
                    A_nzelem[A_rowstarts[i]+row_len] = cg->coef; 
                    row_len++;
                }
            }
        }
    
        if(A_rowstarts[ n_con] > 0)
        {
            osinstance->setLinearConstraintCoefficients(A_rowstarts[ n_con],  false,
                A_nzelem, 0,  A_rowstarts[n_con] - 1,
                A_colptr, 0,  A_rowstarts[n_con] - 1,
                A_rowstarts,  0,  n_con);
// setLinearConstraintCoefficients does a soft copy, and unlike the column-wise representation, 
// this row-wise representation is not taken care of by the ASL_free method in the destructor
            osinstance->instanceData->linearConstraintCoefficients->start->bDeleteArrays = true;
            osinstance->instanceData->linearConstraintCoefficients->colIdx->bDeleteArrays = true;
            osinstance->instanceData->linearConstraintCoefficients->value->bDeleteArrays = true;
        }


#ifdef AMPLDEBUG
        cout << "A-matrix elements: ";
        for (int i = 0; i < A_rowstarts[ n_con]; i++)
            cout << A_nzelem[i] << " ";
        cout << endl;
        cout << "A-matrix col index: ";
        for (int i = 0; i < A_rowstarts[ n_con]; i++)
            cout << A_colptr[i] << " ";
        cout << endl;
        cout << "A-matrix rowstart: ";
        for (int i = 0; i <= n_con; i++)
            cout << A_rowstarts[i] << " ";
        cout << endl;
#endif
    }

    else
    {
        asl=cw;
        int colStart, colEnd, nCoefSqueezed;
        nCoefSqueezed = 0;
    
#ifdef AMPLDEBUG
        cout << "A-matrix elements: ";
        for (int i = 0; i < A_colstarts[ n_var]; i++)
            cout << A_vals[i] << " ";
        cout << endl;
        cout << "A-matrix rowinfo: ";
        for (int i = 0; i < A_colstarts[ n_var]; i++)
            cout << A_rownos[i] << " ";
        cout << endl;
        cout << "A-matrix colstart: ";
        for (int i = 0; i <= n_var; i++)
            cout << A_colstarts[i] << " ";
        cout << endl;
#endif

        colEnd = 0;
        for (i = 0; i < n_var; i++)
        {
            colStart = colEnd;
            colEnd   = A_colstarts[i+1];
#ifdef AMPLDEBUG
            cout << "col " << i << " from " << colStart << " to " << colEnd - 1 << endl;
#endif
            for (j = colStart; j < colEnd; j++)
            {
                if (fabs(A_vals[ j]) > OS_EPS)
                {
                    A_vals[ j-nCoefSqueezed] = A_vals[ j];
                    A_rownos[ j-nCoefSqueezed] = A_rownos[j];
                }
                else
                {
#ifdef AMPLDEBUG
                    cout << "squeeze out element " << j << endl;
#endif
                    nCoefSqueezed++;
                }
            }
            A_colstarts[i+1] = A_colstarts[i+1] - nCoefSqueezed;
        }

#ifdef AMPLDEBUG
        cout << "A-matrix elements: ";
        for (i = 0; i < A_colstarts[ n_var]; i++)
            cout << A_vals[i] << " ";
        cout << endl;
        cout << "A-matrix rowinfo: ";
        for (i = 0; i < A_colstarts[ n_var]; i++)
            cout << A_rownos[i] << " ";
        cout << endl;
        cout << "A-matrix colstart: ";
        for (i = 0; i <= n_var; i++)
            cout << A_colstarts[i] << " ";
        cout << endl;
        cout << "A-matrix nonzeroes: " << A_colstarts[ n_var] << "; nsqueezed: " << nCoefSqueezed << endl;
#endif

        if(A_colstarts[ n_var] > 0)
        {
            osinstance->setLinearConstraintCoefficients(A_colstarts[ n_var],  true,
                A_vals,   0,  A_colstarts[n_var] - 1,
                A_rownos, 0,  A_colstarts[n_var] - 1,
                A_colstarts,  0,  n_var);
            osinstance->instanceData->linearConstraintCoefficients->start->bDeleteArrays = false;
            osinstance->instanceData->linearConstraintCoefficients->rowIdx->bDeleteArrays = false;
            osinstance->instanceData->linearConstraintCoefficients->value->bDeleteArrays = false;
        }
    }


	/** 
	 *  The nl file may contain options that are indexed over model entities:
	 *  variables, constraints, objectives, problems. An example would be
	 *  initial primal and dual variables. AMPL stores these as suffixes,
	 *  which are processed next. The code below is based on ideas expressed by David Gay.
	 */

	SufDesc *d;
	int suffixType, nOther, nOtherIdx;

    asl = cw;

    try
    {
        osolreader = new OSoLReader();

        // check if there are any suffixes to deal with and read options if necessary
        if ((asl->i.suffixes[ASL_Sufkind_var]  != NULL) ||
            (asl->i.suffixes[ASL_Sufkind_con]  != NULL) || 
            (asl->i.suffixes[ASL_Sufkind_obj]  != NULL) ||
            (asl->i.suffixes[ASL_Sufkind_prob] != NULL)  )
        {	
            if (osol != "")
       	        osoption = osolreader->readOSoL(osol);
            else
                osoption = new OSOption();
        }

        bool found;
        bool extend;
        int  nOther;
        std::string *otherOptionNames = NULL;

        // make a record of all <otherVariableOptions> present in the OSoL file
        if (osoption != NULL &&
            osoption->optimization != NULL &&
            osoption->optimization->variables != NULL &&
            osoption->optimization->variables->numberOfOtherVariableOptions > 0)
        {
            otherOptionNames = new std::string[osoption->optimization->variables->numberOfOtherVariableOptions];
            nOther = 0;
            for (int i=0; i < osoption->optimization->variables->numberOfOtherVariableOptions; i++)
                if (osoption->optimization->variables->other[i]->numberOfVar > 0)
                    otherOptionNames[nOther++] = osoption->optimization->variables->other[i]->name;
        }

	    // First the variable-indexed suffixes
       	suffixType = ASL_Sufkind_var;
        if ( (asl->i.suffixes[suffixType]  != NULL) )
        {
            OtherVariableOption* varopt;
        	for (d=asl->i.suffixes[suffixType]; d; d=d->next)
        	{
#ifdef AMPLDEBUG
        		std::cout << "Detected suffix " << d->sufname << "; kind = " << d->kind << std::endl;
#endif

                // allocate space
                varopt = new OtherVariableOption();

            	varopt->name = d->sufname;
		        varopt->numberOfEnumerations = 0;
        		varopt->var = new OtherVarOption*[n_var];

                // check if the option was present in the OSoL file
                found = false;
                int iopt;
                for (iopt=0; iopt < nOther; iopt++)
                {
                    if (d->sufname == otherOptionNames[iopt])
                    {
                        found = true;
                        break;
                    }
                }

                // merge values by overwriting .nl file info 
                if (found)
                {
                    OtherVariableOption* otherOption;
                    otherOption = osoption->getOtherVariableOption(iopt);
                    for (int i=0; i < otherOption->numberOfVar; i++)
                    {
        	        	if (d->kind & 4) // bit-wise mask to distinguish real from integer
                        {
                            d->u.r[otherOption->var[i]->idx] = os_strtod(otherOption->var[i]->value.c_str(), NULL);
                        }
                        else
                            d->u.i[otherOption->var[i]->idx] = (int)os_strtod(otherOption->var[i]->value.c_str(), NULL) + 0.1;
                    }
                    if (otherOption->description == "")
                        varopt->description = "combined from osol and .nl data";
                    else
                        varopt->description = otherOption->description + "; merged with .nl data";
                }
                else
                    varopt->description = "transferred from .nl file";

                // count the number of entries
	        	if (d->kind & 4) // bit-wise mask to distinguish real from integer
	        	{
                    varopt->type = "real";
                    nOtherIdx = 0;
                    for (int k=0; k < n_var; k++)
                    {
                        if (d->u.r[k] != 0)
                        {
                            varopt->var[nOtherIdx] = new OtherVarOption();
                            varopt->var[nOtherIdx]->idx = k;    
                            varopt->var[nOtherIdx]->value = os_dtoa_format(d->u.r[k]);
                            nOtherIdx++;
                        }
                    }
                }
                else             // here the suffix values are integer
                {
                    varopt->type = "integer";
                    nOtherIdx = 0;
                    for (int k=0; k < n_var; k++)
                    {
                        if (d->u.i[k] != 0)
                        {
                            varopt->var[nOtherIdx] = new OtherVarOption();
                            varopt->var[nOtherIdx]->idx = k;    
                            varopt->var[nOtherIdx]->value = os_dtoa_format((double)d->u.i[k]);
                            nOtherIdx++;
                        }    
                    }
                }

          		varopt->numberOfVar = nOtherIdx;

                if (found)
                {
                    // here we just replace the <var> element and update the numberOfVar
                    delete [] osoption->optimization->variables->other[iopt]->var;
                    osoption->optimization->variables->other[iopt]->var = varopt->var;
                    osoption->optimization->variables->other[iopt]->numberOfVar = nOtherIdx;
                    varopt->var = NULL;
                    osoption->optimization->variables->other[iopt]->description = varopt->description;
                }
                else
                {
               		if (!osoption->setAnOtherVariableOption(varopt))
                       throw ErrorClass( "OSnl2OS: Error transfering suffixes on variables" );
                }

           		delete varopt;
           		varopt = NULL;
	        }
        }

    	// suffixes indexed over constraints and objectives work the same way
       	suffixType = ASL_Sufkind_con;
        if ( (asl->i.suffixes[suffixType]  != NULL) )
        {
            OtherConstraintOption* conopt;
        	for (d=asl->i.suffixes[suffixType]; d; d=d->next)
        	{
#ifdef AMPLDEBUG
        		std::cout << "Detected suffix " << d->sufname << "; kind = " << d->kind << std::endl;
#endif

                // allocate space
                conopt = new OtherConstraintOption();

            	conopt->name = d->sufname;
		        conopt->numberOfEnumerations = 0;
        		conopt->con = new OtherConOption*[n_con];

                // check if the option was present in the OSoL file
                found = false;
                int iopt;
                for (iopt=0; iopt < nOther; iopt++)
                {
                    if (d->sufname == otherOptionNames[iopt])
                    {
                        found = true;
                        break;
                    }
                }

                // merge values by overwriting .nl file info 
                if (found)
                {
                    OtherConstraintOption* otherOption;
                    otherOption = osoption->getOtherConstraintOption(iopt);
                    for (int i=0; i < otherOption->numberOfCon; i++)
                    {
        	        	if (d->kind & 4) // bit-wise mask to distinguish real from integer
                        {
                            d->u.r[otherOption->con[i]->idx] = os_strtod(otherOption->con[i]->value.c_str(), NULL);
                        }
                        else
                            d->u.i[otherOption->con[i]->idx] = (int)os_strtod(otherOption->con[i]->value.c_str(), NULL) + 0.1;
                    }
                    if (otherOption->description == "")
                        conopt->description = "combined from osol and .nl data";
                    else
                        conopt->description = otherOption->description + "; merged with .nl data";
                }
                else
                    conopt->description = "transferred from .nl file";

                // count the number of entries
	        	if (d->kind & 4) // bit-wise mask to distinguish real from integer
	        	{
                    conopt->type = "real";
                    nOtherIdx = 0;
                    for (int k=0; k < n_con; k++)
                    {
                        if (d->u.r[k] != 0)
                        {
                            conopt->con[nOtherIdx] = new OtherConOption();
                            conopt->con[nOtherIdx]->idx = k;    
                            conopt->con[nOtherIdx]->value = os_dtoa_format(d->u.r[k]);
                            nOtherIdx++;
                        }
                    }
                }
                else             // here the suffix values are integer
                {
                    conopt->type = "integer";
                    nOtherIdx = 0;
                    for (int k=0; k < n_con; k++)
                    {
                        if (d->u.i[k] != 0)
                        {
                            conopt->con[nOtherIdx] = new OtherConOption();
                            conopt->con[nOtherIdx]->idx = k;    
                            conopt->con[nOtherIdx]->value = os_dtoa_format((double)d->u.i[k]);
                            nOtherIdx++;
                        }
                    }
                }

        		conopt->numberOfCon = nOtherIdx;

                if (found)
                {
                    // here we just replace the <con> element and update the numberOfCon
                    delete [] osoption->optimization->constraints->other[iopt]->con;
                    osoption->optimization->constraints->other[iopt]->con = conopt->con;
                    osoption->optimization->constraints->other[iopt]->numberOfCon = nOtherIdx;
                    conopt->con = NULL;
                    osoption->optimization->constraints->other[iopt]->description = conopt->description;
                }
                else
                {
               		if (!osoption->setAnOtherConstraintOption(conopt))
                       throw ErrorClass( "OSnl2OS: Error transfering suffixes on constraints" );
                }

        		delete conopt;
        		conopt = NULL;
	        }            
        }

       	suffixType = ASL_Sufkind_obj;
        if ( (asl->i.suffixes[suffixType]  != NULL) )
        {
            OtherObjectiveOption* objopt;
        	for (d=asl->i.suffixes[suffixType]; d; d=d->next)
        	{
#ifdef AMPLDEBUG
        		std::cout << "Detected suffix " << d->sufname << "; kind = " << d->kind << std::endl;
#endif

                // allocate space
                objopt = new OtherObjectiveOption();

            	objopt->name = d->sufname;
		        objopt->numberOfEnumerations = 0;
        		objopt->obj = new OtherObjOption*[n_obj];

                // check if the option was present in the OSoL file
                found = false;
                int iopt;
                for (iopt=0; iopt < nOther; iopt++)
                {
                    if (d->sufname == otherOptionNames[iopt])
                    {
                        found = true;
                        break;
                    }
                }

                // merge values by overwriting .nl file info 
                if (found)
                {
                    OtherObjectiveOption* otherOption;
                    otherOption = osoption->getOtherObjectiveOption(iopt);
                    for (int i=0; i < otherOption->numberOfObj; i++)
                    {
        	        	if (d->kind & 4) // bit-wise mask to distinguish real from integer
                        {
                            d->u.r[otherOption->obj[i]->idx] = os_strtod(otherOption->obj[i]->value.c_str(), NULL);
                        }
                        else
                            d->u.i[otherOption->obj[i]->idx] = (int)os_strtod(otherOption->obj[i]->value.c_str(), NULL) + 0.1;
                    }
                    if (otherOption->description == "")
                        objopt->description = "combined from osol and .nl data";
                    else
                        objopt->description = otherOption->description + "; merged with .nl data";
                }
                else
                    objopt->description = "transferred from .nl file";

                // count the number of entries
	        	if (d->kind & 4) // bit-wise mask to distinguish real from integer
	        	{
                    objopt->type = "real";
                    nOtherIdx = 0;
                    for (int k=0; k < n_obj; k++)
                    {
                        if (d->u.r[k] != 0)
                        {
                            objopt->obj[nOtherIdx] = new OtherObjOption();
                            objopt->obj[nOtherIdx]->idx = k;    
                            objopt->obj[nOtherIdx]->value = os_dtoa_format(d->u.r[k]);
                            nOtherIdx++;
                        }
                    }
                }
                else             // here the suffix values are integer
                {
                    objopt->type = "integer";
                    nOtherIdx = 0;
                    for (int k=0; k < n_obj; k++)
                    {
                        if (d->u.i[k] != 0)
                        {
                            objopt->obj[nOtherIdx] = new OtherObjOption();
                            objopt->obj[nOtherIdx]->idx = k;    
                            objopt->obj[nOtherIdx]->value = os_dtoa_format((double)d->u.i[k]);
                            nOtherIdx++;
                        }    
                    }
                }

        		objopt->numberOfObj = nOtherIdx;

                if (found)
                {
                    // here we just replace the <var> element and update the numberOfVar
                    delete [] osoption->optimization->objectives->other[iopt]->obj;
                    osoption->optimization->objectives->other[iopt]->obj = objopt->obj;
                    osoption->optimization->objectives->other[iopt]->numberOfObj = nOtherIdx;
                    objopt->obj = NULL;
                    osoption->optimization->objectives->other[iopt]->description = objopt->description;
                }
                else
                {
               		if (!osoption->setAnOtherObjectiveOption(objopt))
                       throw ErrorClass( "OSnl2OS: Error transfering suffixes on objectives" );
                }

        		delete objopt;
        		objopt = NULL;
	        }
        }


	//problem-indexed suffixes: is there ever more than one value in a .nl file?
       	suffixType = ASL_Sufkind_prob;
        if ( (asl->i.suffixes[suffixType]  != NULL) )
        {
            std::string opttype, optvalue, optdesc;
            optdesc = "transferred from .nl file";
        	for (d=asl->i.suffixes[suffixType]; d; d=d->next)
        	{
#ifdef AMPLDEBUG
        		std::cout << "Detected suffix " << d->sufname << "; kind = " << d->kind << std::endl;
#endif

	        	if (d->kind & 4) // bit-wise mask to distinguish real from integer
	        	{
                    opttype = "real";
                    optvalue = os_dtoa_format(d->u.r[0]);
                }
                else             // here the suffix values are integer
                {
                    opttype = "integer";
                    optvalue = os_dtoa_format((double)d->u.i[0]);
                }

           		if (!osoption->setAnotherSolverOption(d->sufname,optvalue,"","",opttype,optdesc))
                   throw ErrorClass( "OSnl2OS: Error transfering problem-indexed suffixes" );
	        }
        }

    // process initial primal values
 
std::cout << "Initial variable values:"   << std::endl;
for (int i=0; i < n_var; i++)
{
std::cout << X0[i] << "    " << (int)havex0[i] << std::endl;
}

        // process and merge data contained in OSoL file
        // .nl file has data in dense form, but we store in sparse form
        // OSoL data supersede .nl file, so we turn redundant .nl file info OFF
        if (osoption != NULL && 
            osoption->optimization != NULL &&
            osoption->optimization->variables != NULL &&
            osoption->optimization->variables->initialVariableValues != NULL &&
            osoption->optimization->variables->initialVariableValues->numberOfVar > 0)
        {
            int n_prev = osoption->optimization->variables->initialVariableValues->numberOfVar;
            for (int i=0; i < n_prev; i++)
                havex0[osoption->optimization->variables->initialVariableValues->var[i]->idx] = 0;
        }
std::cout << "Initial variable values, updated:"   << std::endl;
for (int i=0; i < n_var; i++)
{
std::cout << X0[i] << "    " << (int)havex0[i] << std::endl;
}

        // count the number of values (including those in the OSoL file)
        int n_x0 = 0;
        for (int i=0; i < n_var; i++)
            if (havex0[i] != 0) n_x0++;

        if (n_x0 > 0)
        {
            if (osoption == NULL)
            {
                if (osol != "")
           	        osoption = osolreader->readOSoL(osol);
                else
                    osoption = new OSOption();
            }

            // allocate space
            InitVarValue **x_init = new InitVarValue*[n_x0];
    
            // pull info out of ASL data structure
            n_x0 = 0;
            for (int i=0; i < n_var; i++)
            {
                if (havex0[i] != 0) 
                {
                    x_init[n_x0] = new InitVarValue();
                    x_init[n_x0]->idx   = i;
                    x_init[n_x0]->value = X0[i];
                    n_x0++;
                }
            }
                
            // store into osoption
            if (!osoption->setInitVarValuesSparse(n_x0, x_init, ENUM_COMBINE_ARRAYS_merge)) 
                throw ErrorClass( "OSnl2OS: Error merging initial primal variable values" );
        }        
 

        // process initial dual values
 
std::cout << "Initial dual variable values:"   << std::endl;
for (int i=0; i < n_con; i++)
{
std::cout << pi0[i] << "    " << (int)havepi0[i] << std::endl;
}

        // process and merge data contained in OSoL file
        // .nl file has data in dense form, but we store in sparse form
        // OSoL data supersede .nl file, so we turn redundant .nl file info OFF
        if (osoption != NULL && 
            osoption->optimization != NULL &&
            osoption->optimization->constraints != NULL &&
            osoption->optimization->constraints->initialDualValues != NULL &&
            osoption->optimization->constraints->initialDualValues->numberOfCon > 0)
        {
            int n_prev = osoption->optimization->constraints->initialDualValues->numberOfCon;
            for (int i=0; i < n_prev; i++)
                havepi0[osoption->optimization->constraints->initialDualValues->con[i]->idx] = 0;
        }

std::cout << "Initial dual variable values, updated:"   << std::endl;
for (int i=0; i < n_con; i++)
{
std::cout << pi0[i] << "    " << (int)havepi0[i] << std::endl;
}

        // count the number of values (including those in the OSoL file)
        int n_pi0 = 0;
        for (int i=0; i < n_con; i++)
            if (havepi0[i] != 0) n_pi0++;

        if (n_pi0 > 0)
        {
            if (osoption == NULL)
            {
                if (osol != "")
           	        osoption = osolreader->readOSoL(osol);
                else
                    osoption = new OSOption();
            }

            // allocate space
            InitDualVarValue **pi_init = new InitDualVarValue*[n_pi0];
    
            // pull info out of ASL data structure
            n_pi0 = 0;
            for (int i=0; i < n_con; i++)
            {
                if (havepi0[i] != 0) 
                {
                    pi_init[n_pi0] = new InitDualVarValue();
                    pi_init[n_pi0]->idx   = i;
                    pi_init[n_pi0]->lbDualValue = pi0[i];
                    pi_init[n_pi0]->ubDualValue = pi0[i];
                    n_pi0++;
                }
            }
                
            // store into osoption
            if (!osoption->setInitDualVarValuesSparse(n_pi0, pi_init, ENUM_COMBINE_ARRAYS_merge)) 
                throw ErrorClass( "OSnl2OS: Error merging initial dual variable values" );
        }        

    //still to do
    //initial basis status: .sstatus
/*
0 - none - unknown
1 - basic - basic
2 - superbasic - superbasic
3 - nonbasic at lower bound - atLower
4 - nonbasic at upper bound - atUpper
5 - nonbasic at equality bound - ?
6 - nonbasic between bounds - isFree?
*/
    //special ordered sets, branching weights, branching group weights
    //initial objective values: .val


    }// end try

    catch(const ErrorClass& eclass)
    {
        // garbage collection etc.
    }

#ifdef AMPLDEBUG
    OSiLWriter osilwriter;
    std::cout << "WRITE THE INSTANCE" << std::endl;
    osilwriter.m_bWhiteSpace = true;
    std::cout << osilwriter.writeOSiL( osinstance) << std::endl;
    std::cout << "DONE WRITE THE INSTANCE" << std::endl;

    std::cout << osinstance->printModel() << std::endl;

    OSoLWriter osolwriter;
    std::cout << "WRITE THE OPTIONS" << std::endl;
 //    osilwriter.m_bWhiteSpace = true;
    std::cout << osolwriter.writeOSoL( osoption) << std::endl;
    std::cout << "DONE WRITE THE OPTIONS" << std::endl;

#endif
   
    return true;
}
