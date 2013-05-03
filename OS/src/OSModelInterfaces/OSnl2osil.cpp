/* $Id$ */
/** @file OSnl2osil.cpp
 *
 * @author  Robert Fourer, Horand Gassmann, Jun Ma, Kipp Martin
 *
 * \remarks
 * Copyright (C) 2005-2011, Robert Fourer, Horand Gassmann, Jun Ma, Kipp Martin,
 * Dalhousie University, Northwestern University, and the University of Chicago.
 * All Rights Reserved.
 * This software is licensed under the Eclipse Public License.
 * Please see the accompanying LICENSE file in root directory for terms.
 *
 */

/**
 *
 * <p>The <code>OSnl2osil</code> used to convert an instance in AMPL nl format
 * to OSiL </p>
 *
 */

#include <iostream>
#include "OSiLWriter.h"
#include "OSnl2osil.h"
#include "OSErrorClass.h"

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

using std::cerr;
using std::cout;
using std::endl;

#ifdef HAVE_STDINT_H
#include <stdint.h>
#endif

struct cgrad;

//#define AMPLDEBUG

OSnl2osil::OSnl2osil(std::string nlfilename)
    : osinstance(0), stub(nlfilename)
{
    efunc *r_ops_int[N_OPS];
    FILE *nl;

    //Initialize the AMPL library
    asl = cw = ASL_alloc( ASL_read_fg);

    //Initialize the nl file reading
    nl = jac0dim(const_cast<char*>(stub.c_str()), (fint)stub.length());

    //Prepare *columnwise* parsing of nl file
    A_vals = (real *)Malloc(nzc*sizeof(real));

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
        fg_read(nl, 0);
        R_OPS = 0;
    }

    // Now create row-wise version
    asl = rw = ASL_alloc( ASL_read_fg);
    nl = jac0dim((char*)stub.c_str(), (fint)stub.length());
    want_derivs = 0;
    qp_read(nl, 0);

    asl = cw;
    numkount = 0;
}

OSnl2osil::~OSnl2osil()
{
    delete osinstance;
    osinstance = NULL;

    free( A_vals);
    ASL_free(&cw);
    ASL_free(&rw);
}

OSnLNode* OSnl2osil::walkTree (expr *e)
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

bool OSnl2osil::createOSInstance()
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


/** Before we can process the rows, we check for QP
 *  This needs to be done here because of the possibility of expressions like (1 - x[0])^2
 *  which may modify the A matrix as well as the right-hand sides
 *  In particular, there may be fill-in in the A-matrix, 
 *  in which case the column-wise representation of the A-matrix
 *  is out of date and needs to rebuilt from the row-wise form. 
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
    int n_prev_A_coef, n_curr_A_coef;


    for (osNLIdx = 0, aNLIdx = -1; osNLIdx < nlc; osNLIdx++, aNLIdx--)
    {
        if (isQP)  // No need to identify quadratic terms once we have found a non-quadratic term
        {
            // count the nonzeroes before and after to check for fillin
            if (!fill_in) // once we know there will be fill-in we can stop counting
            {
                n_prev_A_coef = 0;
                for(cg = Cgrad[osNLIdx]; cg; cg = cg->next)
                {
                    if (cg->coef != 0) n_prev_A_coef++;
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
                    n_curr_A_coef = 0;
                    for(cg = Cgrad[osNLIdx]; cg; cg = cg->next)
                    {
                        if (cg->coef != 0) n_curr_A_coef++;
                    }
                    if (n_prev_A_coef != n_curr_A_coef) fill_in = true;
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
            osinstance->instanceData->linearConstraintCoefficients->start->bDeleteArrays = false;
            osinstance->instanceData->linearConstraintCoefficients->colIdx->bDeleteArrays = false;
            osinstance->instanceData->linearConstraintCoefficients->value->bDeleteArrays = false;
        }

#ifdef AMPLDEBUG
        cout << "A-matrix elements: ";
        for (i = 0; i < A_rowstarts[ n_con]; i++)
            cout << A_nzelem[i] << " ";
        cout << endl;
        cout << "A-matrix col index: ";
        for (i = 0; i < A_rowstarts[ n_con]; i++)
            cout << A_colptr[i] << " ";
        cout << endl;
        cout << "A-matrix rowstart: ";
        for (i = 0; i <= n_con; i++)
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

#ifdef AMPLDEBUG
    OSiLWriter osilwriter;
    std::cout << "WRITE THE INSTANCE" << std::endl;
    osilwriter.m_bWhiteSpace = true;
    std::cout << osilwriter.writeOSiL( osinstance) << std::endl;
    std::cout << "DONE WRITE THE INSTANCE" << std::endl;

    std::cout << osinstance->printModel() << std::endl;

#endif
   
    return true;
}
