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

efunc *r_ops_int[N_OPS];

#include <asl.h>

using std::cerr;
using std::cout;
using std::endl;

#ifdef HAVE_STDINT_H
#include <stdint.h>
#endif



//#define AMPLDEBUG

OSnl2osil::OSnl2osil(std::string nlfilename)
{
    //Initialize the AMPL library
    asl = ASL_alloc( ASL_read_fg);
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
    //X0 = (real *)Malloc( n_var*sizeof(real));
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
    numkount = 0;
}

OSnl2osil::~OSnl2osil()
{
    osinstance->instanceData->linearConstraintCoefficients->start->bDeleteArrays = false;
    osinstance->instanceData->linearConstraintCoefficients->rowIdx->bDeleteArrays = false;
    osinstance->instanceData->linearConstraintCoefficients->value->bDeleteArrays = false;
    delete osinstance;
    osinstance = NULL;
 //   free( X0);
    free( A_vals);
    ASL_free(&asl);

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


bool OSnl2osil::createOSInstance()
{
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
        vartype = 'I';
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
        vartype = 'I';
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
        vartype = 'I';
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
    upper =  CoinMax(nlvc, nlvo) + nwv + (n_var - (CoinMax(nlvc, nlvo) + niv + nbv + nwv) );
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




    //
    //
    //(expr_v *)e;
    //
    //
    // now create the objective function
    // in the nl file, this is stored in dense form; convert to sparse.
    //
    double objWeight = 1.0;
    //	char	*objtype;	/* object type array: 0 == min, 1 == max */
    std::string objName="";
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
        osinstance->addObjective(-n_obj + i, objName,
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
    //
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
    }
    /*	int valuesBegin = 0;
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
    */

    // Kipp: can AMPL identify QPs???
    //osinstance->setQuadraticTerms(numberOfQPTerms, VarOneIdx, VarTwoIdx, Coeff, begin, end);
    //loop over each row with a nonlinear term
    //
    if((nlc + nlo) > 0)
    {
        OSnLNode* m_treeRoot;
        //cout << nlc << endl;
        //cout << nlo << endl;
        osinstance->instanceData->nonlinearExpressions->numberOfNonlinearExpressions = nlc + nlo;
        osinstance->instanceData->nonlinearExpressions->nl = new Nl*[ nlc + nlo ];
        int iNLidx = 0;
        std::cout << "WALK THE TREE FOR NONLINEAR CONSTRAINT TERMS:  " << nlc << std::endl;


        if(nlc > 0)
        {
            while (iNLidx < nlc)
            {
                m_treeRoot = walkTree ((CON_DE + iNLidx)->e);
                osinstance->instanceData->nonlinearExpressions->nl[ iNLidx] = new Nl();
                osinstance->instanceData->nonlinearExpressions->nl[ iNLidx]->idx = iNLidx;
                osinstance->instanceData->nonlinearExpressions->nl[ iNLidx]->osExpressionTree = new OSExpressionTree();
                osinstance->instanceData->nonlinearExpressions->nl[ iNLidx]->osExpressionTree->m_treeRoot = m_treeRoot;
                iNLidx++;
                //std::cout << m_treeRoot->getNonlinearExpressionInXML() << std::endl;
            }
        }

        std::cout << "WALK THE TREE FOR NONLINEAR OBJECTIVE TERMS  " << nlo  << std::endl;
        if(nlo > 0)
        {
            while ( iNLidx < nlc + nlo)
            {
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
//	delete objectiveCoefficients;
//	objectiveCoefficients = NULL;
    //
    // end loop of nonlinear rows
    //
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
