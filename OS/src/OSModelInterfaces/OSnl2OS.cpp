/* $Id: OSnl2OS.cpp 4210 2011-06-28 09:44:54Z stefan $ */
/** @file OSnl2OS.cpp
 * 
 * @author  Horand Gassmann, Jun Ma, Kipp Martin
 *
 * \remarks
 * Copyright (C) 2012, Horand Gassmann, Jun Ma, Kipp Martin,
 * Northwestern University, and the University of Chicago.
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
#include "OSOutput.h"
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


OSnl2OS::OSnl2OS()
    : osolreader (NULL), osinstance(NULL), osoption(NULL), stub("")
{
    cw = ASL_alloc( ASL_read_fg);
    rw = ASL_alloc( ASL_read_fg);
    asl = cw;
}

OSnl2OS::OSnl2OS(ASL *cw, ASL *rw, ASL *asl)
    : osolreader (NULL), osinstance(NULL), osoption(NULL), stub("")
{
    this->asl = asl;
    this->cw  = cw; 
    this->rw  = rw;
} 
    
ASL* OSnl2OS::getASL(std::string name)
{
    if (name == "asl")
        return asl;
    else if (name == "cw")
        return cw;
    else if (name == "rw")
        return rw;
    else 
        return NULL;
}

void OSnl2OS::setOsol(std::string osol)
{
    this->osol = osol;
}

bool OSnl2OS::readNl(std::string stub)
{
    std::ostringstream outStr;

    try
    {
        efunc *r_ops_int[N_OPS];
        FILE *nl;

        //Initialize the AMPL library
//        asl = cw = ASL_alloc( ASL_read_fg);
        asl = cw;

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

#ifndef NDEBUG
        outStr.str("");
        outStr.clear();
        outStr << "number of nonzeros    = " << nzc     << endl;
        outStr << "number of variables   = " << n_var   << endl;
        outStr << "number of constraints = " << n_con   << endl;
        outStr << "number of objectives  = " << n_obj   << endl;
        outStr << "number of ranges      = " << nranges << endl;
        outStr << "number of equations   = " << n_eqn   << endl;
        osoutput->OSPrint(ENUM_OUTPUT_AREA_OSModelInterfaces, ENUM_OUTPUT_LEVEL_debug, outStr.str());
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
//        asl = rw = ASL_alloc( ASL_read_fg);
        asl = rw;
        nl = jac0dim((char*)stub.c_str(), (fint)stub.length());
        want_derivs = 0;
        qp_read(nl, 0);

        asl = cw;
        numkount = 0;
        return true;
    }
    catch(const ErrorClass& eclass)
    {
        return false;
    }
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
    if (cw != NULL) ASL_free(&cw);
    if (rw != NULL) ASL_free(&rw);
    cw  = NULL;
    rw  = NULL;
    asl = NULL;
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
    int i, j;
    std::ostringstream outStr;

    osinstance = new OSInstance();

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
#ifndef NDEBUG
    outStr.str("");
    outStr.clear();
    outStr << "LOWER = " << lower << std::endl;
    outStr << "UPPER = " << upper << std::endl;
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSModelInterfaces, ENUM_OUTPUT_LEVEL_debug, outStr.str());
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
    upper = nlvb;
#ifndef NDEBUG
    outStr.str("");
    outStr.clear();
    outStr << "LOWER = " << lower << std::endl;
    outStr << "UPPER = " << upper << std::endl;
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSModelInterfaces, ENUM_OUTPUT_LEVEL_debug, outStr.str());
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
#ifndef NDEBUG
    outStr.str("");
    outStr.clear();
    outStr << "LOWER = " << lower << std::endl;
    outStr << "UPPER = " << upper << std::endl;
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSModelInterfaces, ENUM_OUTPUT_LEVEL_debug, outStr.str());
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
#ifndef NDEBUG
    outStr.str("");
    outStr.clear();
    outStr << "LOWER = " << lower << std::endl;
    outStr << "UPPER = " << upper << std::endl;
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSModelInterfaces, ENUM_OUTPUT_LEVEL_debug, outStr.str());
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
#ifndef NDEBUG
    outStr.str("");
    outStr.clear();
    outStr << "LOWER = " << lower << std::endl;
    outStr << "UPPER = " << upper << std::endl;
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSModelInterfaces, ENUM_OUTPUT_LEVEL_debug, outStr.str());
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
#ifndef NDEBUG
    outStr.str("");
    outStr.clear();
    outStr << "LOWER = " << lower << std::endl;
    outStr << "UPPER = " << upper << std::endl;
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSModelInterfaces, ENUM_OUTPUT_LEVEL_debug, outStr.str());
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
#ifndef NDEBUG
    outStr.str("");
    outStr.clear();
    outStr << "LOWER = " << lower << std::endl;
    outStr << "UPPER = " << upper << std::endl;
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSModelInterfaces, ENUM_OUTPUT_LEVEL_debug, outStr.str());
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
#ifndef NDEBUG
    outStr.str("");
    outStr.clear();
    outStr << "LOWER = " << lower << std::endl;
    outStr << "UPPER = " << upper << std::endl;
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSModelInterfaces, ENUM_OUTPUT_LEVEL_debug, outStr.str());
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
#ifndef NDEBUG
    outStr.str("");
    outStr.clear();
    outStr << "LOWER = " << lower << std::endl;
    outStr << "UPPER = " << upper << std::endl;
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSModelInterfaces, ENUM_OUTPUT_LEVEL_debug, outStr.str());
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
#ifndef NDEBUG
    outStr.str("");
    outStr.clear();
    outStr << "LOWER = " << lower << std::endl;
    outStr << "UPPER = " << upper << std::endl;
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSModelInterfaces, ENUM_OUTPUT_LEVEL_debug, outStr.str());
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
        if (isQP)  // No need to continue looking for quadratic terms once we have found a non-quadratic term
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
            if (nqpchk > 0) // there is a quadratic part
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
    //    char    *objtype;    /* object type array: 0 == min, 1 == max */
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


#ifndef NDEBUG
        outStr.str("");
        outStr.clear();
        outStr << "A-matrix elements: ";
        for (int i = 0; i < A_rowstarts[ n_con]; i++)
            outStr << A_nzelem[i] << " ";
        outStr << endl;
        outStr << "A-matrix col index: ";
        for (int i = 0; i < A_rowstarts[ n_con]; i++)
            outStr << A_colptr[i] << " ";
        outStr << endl;
        outStr << "A-matrix rowstart: ";
        for (int i = 0; i <= n_con; i++)
            outStr << A_rowstarts[i] << " ";
        outStr << endl;
        osoutput->OSPrint(ENUM_OUTPUT_AREA_OSModelInterfaces, ENUM_OUTPUT_LEVEL_debug, outStr.str());
#endif
    }

    else
    {
        asl=cw;
        int colStart, colEnd, nCoefSqueezed;
        nCoefSqueezed = 0;
    
#ifndef NDEBUG
        outStr.str("");
        outStr.clear();
        outStr << "A-matrix elements: ";
        for (int i = 0; i < A_colstarts[ n_var]; i++)
            outStr << A_vals[i] << " ";
        outStr << endl;
        outStr << "A-matrix rowinfo: ";
        for (int i = 0; i < A_colstarts[ n_var]; i++)
            outStr << A_rownos[i] << " ";
        outStr << endl;
        outStr << "A-matrix colstart: ";
        for (int i = 0; i <= n_var; i++)
            outStr << A_colstarts[i] << " ";
        outStr << endl;
        osoutput->OSPrint(ENUM_OUTPUT_AREA_OSModelInterfaces, ENUM_OUTPUT_LEVEL_debug, outStr.str());
#endif

        colEnd = 0;
        for (i = 0; i < n_var; i++)
        {
            colStart = colEnd;
            colEnd   = A_colstarts[i+1];
#ifndef NDEBUG
            outStr.str("");
            outStr.clear();
            outStr << "col " << i << " from " << colStart << " to " << colEnd - 1 << endl;
            osoutput->OSPrint(ENUM_OUTPUT_AREA_OSModelInterfaces, ENUM_OUTPUT_LEVEL_debug, outStr.str());
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
#ifndef NDEBUG
                    outStr.str("");
                    outStr.clear();
                    outStr << "squeeze out element " << j << endl;
                    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSModelInterfaces, ENUM_OUTPUT_LEVEL_debug, outStr.str());
#endif
                    nCoefSqueezed++;
                }
            }
            A_colstarts[i+1] = A_colstarts[i+1] - nCoefSqueezed;
        }

#ifndef NDEBUG
        outStr.str("");
        outStr.clear();
        outStr << "A-matrix elements: ";
        for (i = 0; i < A_colstarts[ n_var]; i++)
            outStr << A_vals[i] << " ";
        outStr << endl;
        outStr << "A-matrix rowinfo: ";
        for (i = 0; i < A_colstarts[ n_var]; i++)
            outStr << A_rownos[i] << " ";
        outStr << endl;
        outStr << "A-matrix colstart: ";
        for (i = 0; i <= n_var; i++)
            outStr << A_colstarts[i] << " ";
        outStr << endl;
        outStr << "A-matrix nonzeroes: " << A_colstarts[ n_var] << "; nsqueezed: " << nCoefSqueezed << endl;
        osoutput->OSPrint(ENUM_OUTPUT_AREA_OSModelInterfaces, ENUM_OUTPUT_LEVEL_debug, outStr.str());
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
        bool have_primal = false;
        for (int i=0; i < n_var; i++)
        {
            if (havex0[i] != 0) 
            {
                have_primal = true;
                break;
            }
        }

        bool have_dual = false;
        for (int i=0; i < n_con; i++)
        {
            if (havepi0[i] != 0) 
            {
                have_dual = true;
                break;
            }
        }

        if ((asl->i.suffixes[ASL_Sufkind_var]  != NULL) ||
            (asl->i.suffixes[ASL_Sufkind_con]  != NULL) || 
            (asl->i.suffixes[ASL_Sufkind_obj]  != NULL) ||
            (asl->i.suffixes[ASL_Sufkind_prob] != NULL) ||
            ( have_primal ) || ( have_dual ) )               
        {    
            osoption = osolreader->readOSoL(osol);
        }

        bool found;
        bool extend;
        int  nOther;
        int  nIndexes;
        std::string *otherOptionNames = NULL;

        // First the variable-indexed suffixes
        suffixType = ASL_Sufkind_var;
        if ( (asl->i.suffixes[suffixType]  != NULL) )
        {
            // make a record of all <otherVariableOptions> present in the OSoL file
            nOther = 0;
            if (osoption != NULL &&
                osoption->optimization != NULL &&
                osoption->optimization->variables != NULL &&
                osoption->optimization->variables->numberOfOtherVariableOptions > 0)
            {
                otherOptionNames = new std::string[osoption->optimization->variables->numberOfOtherVariableOptions];
                for (int i=0; i < osoption->optimization->variables->numberOfOtherVariableOptions; i++)
                    if (osoption->optimization->variables->other[i]->numberOfVar > 0)
                        otherOptionNames[nOther++] = osoption->optimization->variables->other[i]->name;
            }
            OtherVariableOption* varopt;
            for (d=asl->i.suffixes[suffixType]; d; d=d->next)
            {
#ifndef NDEBUG
                outStr.str("");
                outStr.clear();
                outStr << "Detected suffix " << d->sufname << "; kind = " << d->kind << std::endl;
                osoutput->OSPrint(ENUM_OUTPUT_AREA_OSModelInterfaces, ENUM_OUTPUT_LEVEL_debug, outStr.str());
#endif

                // Deal with special cases: basis information, special ordered sets (?) and branching weights (?)
                if (strcmp(d->sufname,"sstatus") == 0) //(d->sufname == "sstatus")
                {
                    // note that AMPL uses different numeric values for representing basis status:
                    // 0 = no status assigned                       = ENUM_BASIS_STATUS_unknown
                    // 1 = basic                                    = ENUM_BASIS_STATUS_basic
                    // 2 = superbasic                               = ENUM_BASIS_STATUS_superbasic
                    // 3 = nonbasic <= (normally =) lower bound     = ENUM_BASIS_STATUS_atLower
                    // 4 = nonbasic >= (normally =) upper bound     = ENUM_BASIS_STATUS_atUpper
                    // 5 = nonbasic at equal lower and upper bounds = ENUM_BASIS_STATUS_atEquality
                    // 6 = nonbasic between bounds                  = ENUM_BASIS_STATUS_isFree

                    int  basCode[ENUM_BASIS_STATUS_NUMBER_OF_STATES] = 
                    {    ENUM_BASIS_STATUS_unknown,
                         ENUM_BASIS_STATUS_basic,
                         ENUM_BASIS_STATUS_superbasic,
                         ENUM_BASIS_STATUS_atLower,
                         ENUM_BASIS_STATUS_atUpper,
                         ENUM_BASIS_STATUS_atEquality,
                         ENUM_BASIS_STATUS_isFree      
                    };
                    // allocate space
                    int* IBS;

#ifndef NDEBUG
                    outStr.str("");
                    outStr.clear();
                    outStr << "Original basis (in AMPL codes):";
                    for (int k=0; k<n_var; k++)
                        outStr << "  " << d->u.i[k];
                    outStr << std::endl;
                    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSModelInterfaces, ENUM_OUTPUT_LEVEL_debug, outStr.str());
#endif
 
                    // if OSoL file has a basis, merge values by overwriting .nl file info 
                    if (osoption != NULL &&
                        osoption->optimization != NULL &&
                        osoption->optimization->variables != NULL &&
                        osoption->optimization->variables->initialBasisStatus != NULL)
                    {
                        // retrieve basis and store into ASL data structure
                        for (int i=0; i < ENUM_BASIS_STATUS_NUMBER_OF_STATES; i++)
                        {
                            nIndexes = osoption->getNumberOfInitialBasisElements(ENUM_PROBLEM_COMPONENT_variables, basCode[i]);
                            if (nIndexes > 0)
                            {
                                IBS = new int[nIndexes];
                                osoption->getInitialBasisElements(ENUM_PROBLEM_COMPONENT_variables, basCode[i], IBS);

                                for (int k=0; k < nIndexes; k++)
                                    d->u.i[IBS[k]] = i;
                                delete[] IBS;
                            }
#ifndef NDEBUG
                            outStr.str("");
                            outStr.clear();
                            outStr << "After processing state " << i << ":";
                            for (int k=0; k<n_var; k++)
                                outStr << "  " << d->u.i[k];
                            outStr << std::endl;
                            osoutput->OSPrint(ENUM_OUTPUT_AREA_OSModelInterfaces, ENUM_OUTPUT_LEVEL_debug, outStr.str());
#endif
                        }
                    }
#ifndef NDEBUG
                    outStr.str("");
                    outStr.clear();
                    outStr << "Merged basis (in AMPL codes):";
                    for (int k=0; k<n_var; k++)
                        outStr << "  " << d->u.i[k];
                    outStr << std::endl;
                    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSModelInterfaces, ENUM_OUTPUT_LEVEL_debug, outStr.str());
#endif

                    // count the number of entries
                    int nidx[ENUM_BASIS_STATUS_NUMBER_OF_STATES];
                    int kidx[ENUM_BASIS_STATUS_NUMBER_OF_STATES];
                    for (i=0; i<ENUM_BASIS_STATUS_NUMBER_OF_STATES; i++)
                    {
                        nidx[i] = 0;
                        kidx[i] = 0;
                    }

                    for (int k=0; k < n_var; k++)
                        nidx[d->u.i[k]]++;

                    // allocate space
                    int **IBS2;
                    IBS2 = new int*[ENUM_BASIS_STATUS_NUMBER_OF_STATES];
                    for (int i=0; i<ENUM_BASIS_STATUS_NUMBER_OF_STATES; i++)
                    {
                        IBS2[i] = new int[nidx[i]];
                    }

                    // store basis info into class-oriented arrays
                    for (int k=0; k < n_var; k++)
                    {
                        IBS2[d->u.i[k]][kidx[d->u.i[k]]++] = k;
                    }

                    // store into <initialBasisStatus> element
                    for (int i=0; i < ENUM_BASIS_STATUS_NUMBER_OF_STATES; i++)
                        if (nidx[i] > 0)
                            osoption->setInitBasisStatus(ENUM_PROBLEM_COMPONENT_variables, basCode[i], IBS2[i], nidx[i]);

                    // garbage collection
                    for (int i=0; i < ENUM_BASIS_STATUS_NUMBER_OF_STATES; i++)
                        delete [] IBS2[i];
                    delete [] IBS2;
                }
                
                else       // not one of the special cases
                {
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
                        varopt->varType = "real";
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
                        varopt->varType = "integer";
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
                        for (int k=0; k < osoption->optimization->variables->other[iopt]->numberOfVar; k++)
                            delete osoption->optimization->variables->other[iopt]->var[k];
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
            delete [] otherOptionNames;
            otherOptionNames = NULL;
        }

        // suffixes indexed over constraints and objectives work the same way
           suffixType = ASL_Sufkind_con;
        if ( (asl->i.suffixes[suffixType]  != NULL) )
        {
            // make a record of all <otherConstraintOptions> present in the OSoL file
            nOther = 0;
            if (osoption != NULL &&
                osoption->optimization != NULL &&
                osoption->optimization->constraints != NULL &&
                osoption->optimization->constraints->numberOfOtherConstraintOptions > 0)
            {
                otherOptionNames = new std::string[osoption->optimization->constraints->numberOfOtherConstraintOptions];
                for (int i=0; i < osoption->optimization->constraints->numberOfOtherConstraintOptions; i++)
                    if (osoption->optimization->constraints->other[i]->numberOfCon > 0)
                        otherOptionNames[nOther++] = osoption->optimization->constraints->other[i]->name;
            }
            OtherConstraintOption* conopt;
            for (d=asl->i.suffixes[suffixType]; d; d=d->next)
            {
#ifndef NDEBUG
                outStr.str("");
                outStr.clear();
                outStr << "Detected suffix " << d->sufname << "; kind = " << d->kind << std::endl;
                osoutput->OSPrint(ENUM_OUTPUT_AREA_OSModelInterfaces, ENUM_OUTPUT_LEVEL_debug, outStr.str());
#endif
                // Deal with special cases first: basis information and branching weights
                if (strcmp(d->sufname,"sstatus") == 0) //(d->sufname == "sstatus")
                {
                    // note that AMPL uses different numeric values for representing basis status:
                    // 0 = no status assigned                       = ENUM_BASIS_STATUS_unknown
                    // 1 = basic                                    = ENUM_BASIS_STATUS_basic
                    // 2 = superbasic                               = ENUM_BASIS_STATUS_superbasic
                    // 3 = nonbasic <= (normally =) lower bound     = ENUM_BASIS_STATUS_atLower
                    // 4 = nonbasic >= (normally =) upper bound     = ENUM_BASIS_STATUS_atUpper
                    // 5 = nonbasic at equal lower and upper bounds = ENUM_BASIS_STATUS_atEquality
                    // 6 = nonbasic between bounds                  = ENUM_BASIS_STATUS_isFree

                    int  basCode[ENUM_BASIS_STATUS_NUMBER_OF_STATES] = 
                    {    ENUM_BASIS_STATUS_unknown,
                         ENUM_BASIS_STATUS_basic,
                         ENUM_BASIS_STATUS_superbasic,
                         ENUM_BASIS_STATUS_atLower,
                         ENUM_BASIS_STATUS_atUpper,
                         ENUM_BASIS_STATUS_atEquality,
                         ENUM_BASIS_STATUS_isFree      
                    };

                    // allocate space
                    int* IBS;
 
#ifndef NDEBUG
                    outStr.str("");
                    outStr.clear();
                    outStr << "Original basis (in AMPL codes):";
                    for (int k=0; k<n_con; k++)
                        outStr << "  " << d->u.i[k];
                    outStr << std::endl;
                    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSModelInterfaces, ENUM_OUTPUT_LEVEL_debug, outStr.str());
#endif
                    // if OSoL file has a basis, merge values by overwriting .nl file info 
                    if (osoption != NULL &&
                        osoption->optimization != NULL &&
                        osoption->optimization->constraints != NULL &&
                        osoption->optimization->constraints->initialBasisStatus != NULL)
                    {

                        // retrieve basis and store into ASL data structure
                        for (int i=0; i < ENUM_BASIS_STATUS_NUMBER_OF_STATES; i++)
                        {
                            nIndexes = osoption->getNumberOfInitialBasisElements(ENUM_PROBLEM_COMPONENT_constraints, basCode[i]);
                            if (nIndexes > 0)
                            {
                                IBS = new int[nIndexes];
                                osoption->getInitialBasisElements(ENUM_PROBLEM_COMPONENT_constraints, basCode[i], IBS);

                                for (int k=0; k < nIndexes; k++)
                                    d->u.i[IBS[k]] = i;
                                delete[] IBS;
                            }
#ifndef NDEBUG
                            outStr.str("");
                            outStr.clear();
                            outStr << "After processing state " << i << ":";
                            for (int k=0; k<n_con; k++)
                                outStr << "  " << d->u.i[k];
                            outStr << std::endl;
                            osoutput->OSPrint(ENUM_OUTPUT_AREA_OSModelInterfaces, ENUM_OUTPUT_LEVEL_debug, outStr.str());
#endif
                        }
                    }
#ifndef NDEBUG
                    outStr.str("");
                    outStr.clear();
                    outStr << "Merged basis (in AMPL codes):";
                    for (int k=0; k<n_con; k++)
                        outStr << "  " << d->u.i[k];
                    outStr << std::endl;
                    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSModelInterfaces, ENUM_OUTPUT_LEVEL_debug, outStr.str());
#endif

                    // count the number of entries
                    int nidx[ENUM_BASIS_STATUS_NUMBER_OF_STATES];
                    int kidx[ENUM_BASIS_STATUS_NUMBER_OF_STATES];
                    for (i=0; i<ENUM_BASIS_STATUS_NUMBER_OF_STATES; i++)
                    {
                        nidx[i] = 0;
                        kidx[i] = 0;
                    }

                    for (int k=0; k < n_con; k++)
                        nidx[d->u.i[k]]++;

                    // allocate space
                    int **IBS2;
                    IBS2 = new int*[ENUM_BASIS_STATUS_NUMBER_OF_STATES];
                    for (int i=0; i<ENUM_BASIS_STATUS_NUMBER_OF_STATES; i++)
                    {
                        IBS2[i] = new int[nidx[i]];
                    }

                    // store basis info into class-oriented arrays
                    for (int k=0; k < n_con; k++)
                    {
                        IBS2[d->u.i[k]][kidx[d->u.i[k]]++] = k;
                    }

                    // store into <initialBasisStatus> element
                    for (int i=0; i < ENUM_BASIS_STATUS_NUMBER_OF_STATES; i++)
                        if (nidx[i] > 0)
                            osoption->setInitBasisStatus(ENUM_PROBLEM_COMPONENT_constraints, basCode[i], IBS2[i], nidx[i]);

                    // garbage collection
                    for (int i=0; i < ENUM_BASIS_STATUS_NUMBER_OF_STATES; i++)
                        delete [] IBS2[i];
                    delete [] IBS2;
                }
                
                else  // not one of the special cases
                {
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
                        conopt->conType = "real";
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
                        conopt->conType = "integer";
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
                        for (int k=0; k < osoption->optimization->constraints->other[iopt]->numberOfCon; k++)
                            delete osoption->optimization->constraints->other[iopt]->con[k];
                        delete []  osoption->optimization->constraints->other[iopt]->con;
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
            delete [] otherOptionNames;
            otherOptionNames = NULL;
        }

        // here we have suffixes indexed over objectives 
        suffixType = ASL_Sufkind_obj;
        if ( (asl->i.suffixes[suffixType]  != NULL) )
        {
            // make a record of all <otherObjectiveOptions> present in the OSoL file
            nOther = 0;
            if (osoption != NULL &&
                osoption->optimization != NULL &&
                osoption->optimization->objectives != NULL &&
                osoption->optimization->objectives->numberOfOtherObjectiveOptions > 0)
            {
                otherOptionNames = new std::string[osoption->optimization->objectives->numberOfOtherObjectiveOptions];
                for (int i=0; i < osoption->optimization->objectives->numberOfOtherObjectiveOptions; i++)
                    if (osoption->optimization->objectives->other[i]->numberOfObj > 0)
                        otherOptionNames[nOther++] = osoption->optimization->objectives->other[i]->name;
            }
            OtherObjectiveOption* objopt;
            for (d=asl->i.suffixes[suffixType]; d; d=d->next)
            {
#ifndef NDEBUG
                outStr.str("");
                outStr.clear();
                outStr << "Detected suffix " << d->sufname << "; kind = " << d->kind << std::endl;
                osoutput->OSPrint(ENUM_OUTPUT_AREA_OSModelInterfaces, ENUM_OUTPUT_LEVEL_debug, outStr.str());
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
#ifndef NDEBUG
                    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSModelInterfaces, ENUM_OUTPUT_LEVEL_debug, "Merge data\n");
#endif
                    for (int i=0; i < otherOption->numberOfObj; i++)
                    {
                        if (d->kind & 4) // bit-wise mask to distinguish real from integer
                        {
                            d->u.r[-1 - otherOption->obj[i]->idx] = os_strtod(otherOption->obj[i]->value.c_str(), NULL);
                        }
                        else
                            d->u.i[-1 - otherOption->obj[i]->idx] = atoi(otherOption->obj[i]->value.c_str());
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
                    objopt->objType = "real";
                    nOtherIdx = 0;
                    for (int k=0; k < n_obj; k++)
                    {
                        if (d->u.r[k] != 0)
                        {
                            objopt->obj[nOtherIdx] = new OtherObjOption();
                            objopt->obj[nOtherIdx]->idx = -1 - k;    
                            objopt->obj[nOtherIdx]->value = os_dtoa_format(d->u.r[k]);
                            nOtherIdx++;
                        }
                    }
                }
                else             // here the suffix values are integer
                {
                    objopt->objType = "integer";
                    nOtherIdx = 0;
                    for (int k=0; k < n_obj; k++)
                    {
                        if (d->u.i[k] != 0)
                        {
                            objopt->obj[nOtherIdx] = new OtherObjOption();
                            objopt->obj[nOtherIdx]->idx = -1 - k;    
                            objopt->obj[nOtherIdx]->value = os_dtoa_format((double)d->u.i[k]);
                            nOtherIdx++;
                        }    
                    }
                }

                objopt->numberOfObj = nOtherIdx;

                if (found)
                {
                    // here we just replace the <obj> element and update the numberOfObj
                    for (int k=0; k < osoption->optimization->objectives->other[iopt]->numberOfObj; k++)
                        delete osoption->optimization->objectives->other[iopt]->obj[k];
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
            delete [] otherOptionNames;
            otherOptionNames = NULL;
        }


        //problem-indexed suffixes: Only the currently active problem is put into the .nl file, so this must be scalar
        suffixType = ASL_Sufkind_prob;
        if ( (asl->i.suffixes[suffixType]  != NULL) )
        {
            std::string opttype, optvalue, optdesc;
            optdesc = "transferred from .nl file";
            for (d=asl->i.suffixes[suffixType]; d; d=d->next)
            {
#ifndef NDEBUG
                outStr.str("");
                outStr.clear();
                outStr << "Detected suffix " << d->sufname << "; kind = " << d->kind << std::endl;
                osoutput->OSPrint(ENUM_OUTPUT_AREA_OSModelInterfaces, ENUM_OUTPUT_LEVEL_debug, outStr.str());
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

        // process initial primal values and merge with data contained in OSoL file
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

        // count the number of values (including those in the OSoL file)
        int n_x0 = 0;
        for (int i=0; i < n_var; i++)
            if (havex0[i] != 0) n_x0++;

        if (n_x0 > 0)
        {
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

            for (int i=0; i < n_x0; i++)
                delete x_init[i];
//                x_init[i] = NULL;
            delete  [] x_init;
            x_init = NULL;
        }        
 
        // process initial dual values and merge with data contained in OSoL file
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

        // count the number of values (including those in the OSoL file)
        int n_pi0 = 0;
        for (int i=0; i < n_con; i++)
            if (havepi0[i] != 0) n_pi0++;

        if (n_pi0 > 0)
        {
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

            for (int i=0; i < n_pi0; i++)
                delete pi_init[i];
//                pi_init[i] = NULL;
            delete  [] pi_init;
            pi_init = NULL;
        }        

    //still to do
    //special ordered sets, branching weights, branching group weights
    //initial objective values: .val

#ifndef NDEBUG
        osoutput->OSPrint(ENUM_OUTPUT_AREA_OSModelInterfaces, ENUM_OUTPUT_LEVEL_trace, "At end of OSnl2OS\n");
#endif
    }// end try

    catch(const ErrorClass& eclass)
    {
        // garbage collection etc.
    }

#ifndef NDEBUG
    OSiLWriter osilwriter;
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSModelInterfaces, ENUM_OUTPUT_LEVEL_trace, "WRITE THE INSTANCE\n");
    osilwriter.m_bWhiteSpace = true;
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSModelInterfaces, ENUM_OUTPUT_LEVEL_trace, osilwriter.writeOSiL( osinstance));
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSModelInterfaces, ENUM_OUTPUT_LEVEL_trace, "DONE WRITING THE INSTANCE\n");
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSModelInterfaces, ENUM_OUTPUT_LEVEL_trace, osinstance->printModel());

    OSoLWriter osolwriter;
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSModelInterfaces, ENUM_OUTPUT_LEVEL_trace, "WRITE THE OPTIONS\n");
 //    osilwriter.m_bWhiteSpace = true;
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSModelInterfaces, ENUM_OUTPUT_LEVEL_trace, osolwriter.writeOSoL( osoption));
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSModelInterfaces, ENUM_OUTPUT_LEVEL_trace, "DONE WRITING THE OPTIONS\n");
#endif
   
    return true;
}
