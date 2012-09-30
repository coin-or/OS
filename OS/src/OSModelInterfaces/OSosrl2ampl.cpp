/* $Id: OSosrl2ampl.cpp 4210 2011-06-28 09:44:54Z Gassmann $ */
/** @file OSosrl2ampl.cpp
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
 * <p><code>OSosrl2ampl</code> is used to convert information in OSrL format
 * to a .sol file for AMPL </p>
 *
 */


#include <iostream>
#include "OSrLReader.h"
#include "OSosrl2ampl.h"
#include "OSResult.h"
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

OSosrl2ampl::OSosrl2ampl()
{
    std::cout << "in OSosrl2ampl constructor" << std::endl;
}

OSosrl2ampl::~OSosrl2ampl()
{
    std::cout << "in OSosrl2ampl destructor" << std::endl;
}

bool OSosrl2ampl::writeSolFile(std::string osrl, ASL *asl)
{
    OSrLReader *osrlreader = NULL;
    OSResult   *osresult;

    std::string solMsg = " ";
    if (osrl == "")
    {
        write_sol(  const_cast<char*>(solMsg.c_str()),  NULL, NULL , NULL);
        std::cout << "osrl is empty (error condition detected)" << std::endl;
        return true;
    }
    else
    {
        double *x;
        double *y;
        try
        {
            osrlreader = new OSrLReader();
            osresult = osrlreader->readOSrL( osrl);
            // do the following so output is not written twice
            // see page 23 of hooking solver to AMPL
            //need_nl = printf( sReport.c_str());

            //
            int i;
            int vecSize;
            int numVars = osresult->getVariableNumber();
            int numCons = osresult->getConstraintNumber();
            x = new double[ numVars];
            y = new double[ numCons];

            std::vector<IndexValuePair*> primalValPair;
            std::vector<IndexValuePair*> dualValPair;
            dualValPair = osresult->getOptimalDualVariableValues( 0);
            primalValPair = osresult->getOptimalPrimalVariableValues( 0);

            for(i = 0; i < numVars; i++)
            {
                x[ i] = 0.0;
            }
            vecSize = primalValPair.size();
            for(i = 0; i < vecSize; i++)
            {
                x[ primalValPair[i]->idx ] = primalValPair[i]->value;
                //std::cout << "index =  " <<   primalValPair[i]->idx  << std::endl;
                //std::cout << "value =  " <<   primalValPair[i]->value  << std::endl;
            }


            for(i = 0; i < numCons; i++)
            {
                y[ i] = 0.0;
            }
            vecSize = dualValPair.size();
            for(i = 0; i < vecSize; i++)
            {
                y[ dualValPair[i]->idx ] = dualValPair[i]->value;
                //std::cout << "index =  " <<   primalValPair[i]->idx  << std::endl;
                //std::cout << "value =  " <<   primalValPair[i]->value  << std::endl;
            }

            // return all solution results that are indexed over variables or constraints as suffixes

            for (int i=0; i < osresult->getNumberOfOtherVariableResults(0); i++)
            {
                if ( (osresult->optimization->solution[0]->variables->other[i]->var != NULL) || 
                     (osresult->optimization->solution[0]->variables->other[i]->enumeration != NULL) )
                {

                }
            }
// taken from Ipopt - AmplTNLP.cpp:
//    Number* z_L_sol
//            suf_rput("ipopt_zL_out", ASL_Sufkind_var,  z_L_sol_);

            write_sol(const_cast<char*>(solMsg.c_str()),  x, y , NULL);
            std::cout << "solution file has been written" << std::endl;
            if (osrlreader != NULL) delete osrlreader;
            osrlreader = NULL;
            delete [] x; x = NULL;
            delete [] y; y = NULL;
            return true;
        }
        catch(const ErrorClass& eclass)
        {
            if (x != NULL) delete [] x; x = NULL;
            if (y != NULL) delete [] y; y = NULL;
            return false;
        }
    }
}

