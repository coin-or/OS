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

#ifdef _DEBUG
# define DEBUG_OSRL2AMPL
#endif


OSosrl2ampl::OSosrl2ampl()
{
}

OSosrl2ampl::~OSosrl2ampl()
{
}

bool OSosrl2ampl::writeSolFile(std::string osrl, ASL *asl)
{
    OSrLReader *osrlreader = NULL;
    OSResult   *osresult;

#ifdef _DEBUG
std::cout << "_DEBUG is defined" << std::endl << std::endl;
#else
std::cout << "_DEBUG NOT defined" << std::endl << std::endl;
#endif

#ifdef DEBUG_OSRL2AMPL
std::cout << "DEBUG_OSRL2AMPL is defined" << std::endl << std::endl;
#else
std::cout << "DEBUG_OSRL2AMPL NOT defined" << std::endl << std::endl;
#endif

    if (osrl == "")
    {
        write_sol('\0',  NULL, NULL , NULL);
        return true;
    }
    else
    {
        std::cout << std::endl << osrl << std::endl << std::endl << std::endl;

        double *x;
        double *y;
        std::string *otherVar;
        std::string *otherObj;
        std::string *otherCon;
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
            int numObjs = osresult->getObjectiveNumber();
            int numCons = osresult->getConstraintNumber();
            x = new double[ numVars];
            y = new double[ numCons];
            otherVar = new std::string[numVars];
            otherObj = new std::string[numObjs];
            otherCon = new std::string[numCons];

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

            // return all solution results that are indexed over variables, objectives or constraints as suffixes

            int n;
            double* rvalues = NULL;
            int*    ivalues = NULL;
            int     nSuffixes = 0;
            bool    have_basic_var = false;
            bool    have_basic_con = false;
            SufDecl *suftab = NULL;

            //  First determine the number of suffixes that need to be handled 

            n = osresult->getNumberOfOtherVariableResults(0);
            if (n > 0) nSuffixes += n;
            n = osresult->getNumberOfOtherObjectiveResults(0);
            if (n > 0) nSuffixes += n;
            n = osresult->getNumberOfOtherConstraintResults(0);
            if (n > 0) nSuffixes += n;

            if (   (osresult->optimization != NULL)
                && (osresult->optimization->solution[0] != NULL)
                && (osresult->optimization->solution[0]->variables != NULL)
                && (osresult->optimization->solution[0]->variables->basisStatus != NULL) )
            {
                have_basic_var = true;
                nSuffixes++;
            }
            if (   (osresult->optimization != NULL)
                && (osresult->optimization->solution[0] != NULL)
                && (osresult->optimization->solution[0]->constraints != NULL)
                && (osresult->optimization->solution[0]->constraints->basisStatus != NULL) )
            {
                have_basic_con = true;
                nSuffixes++;
            }

            // Create a suffix table

            int k = 0;
            suftab = new SufDecl[nSuffixes];
            SufDecl temp;
            std::string s;
            char* p;

            for (i=0; i < osresult->getNumberOfOtherVariableResults(0); i++, k++)
            {
                s = osresult->getOtherVariableResultName(0, i);
                suftab[k].name = new char[s.size()+1];
                s.copy(suftab[k].name, s.size(), 0);
                suftab[k].name[s.size()] = '\0';

#ifdef DEBUG_OSRL2AMPL
                std::cout << s << " has length " << s.size() << " p = " << suftab[k].name << std::endl;
#endif

                suftab[k].table  = NULL;
                suftab[k].kind   = ASL_Sufkind_var;
                suftab[k].nextra = 1;
            }
            for (i=0; i < osresult->getNumberOfOtherObjectiveResults(0); i++, k++)
            {
                s = osresult->getOtherObjectiveResultName(0, i);
                suftab[k].name = new char[s.size()+1];
                s.copy(suftab[k].name, s.size(), 0);
                suftab[k].name[s.size()] = '\0';

#ifdef DEBUG_OSRL2AMPL
                std::cout << s << " has length " << s.size() << " p = " << suftab[k].name << std::endl;
#endif

                suftab[k].table  = NULL;
                suftab[k].kind   = ASL_Sufkind_obj;
                suftab[k].nextra = 1;
            }
            for (i=0; i < osresult->getNumberOfOtherConstraintResults(0); i++, k++)
            {
                s = osresult->getOtherConstraintResultName(0, i);
                suftab[k].name = new char[s.size()+1];
                s.copy(suftab[k].name, s.size(), 0);
                suftab[k].name[s.size()] = '\0';

#ifdef DEBUG_OSRL2AMPL
                std::cout << s << " has length " << s.size() << " p = " << suftab[k].name << std::endl;
#endif

                suftab[k].table  = NULL;
                suftab[k].kind   = ASL_Sufkind_con;
                suftab[k].nextra = 1;
            }
            if (have_basic_var)
            {
                s = "sstatus";
                suftab[k].name = new char[s.size()+1];
                s.copy(suftab[k].name, s.size(), 0);
                suftab[k].name[s.size()] = '\0';

#ifdef DEBUG_OSRL2AMPL
                std::cout << s << " has length " << s.size() << " p = " << suftab[k].name << std::endl;
#endif

                suftab[k].table  = NULL;
                suftab[k].kind   = ASL_Sufkind_var;
                suftab[k].nextra = 1;
                k++;
            }
            if (have_basic_con)
            {
                s = "sstatus";
                suftab[k].name = new char[s.size()+1];
                s.copy(suftab[k].name, s.size(), 0);
                suftab[k].name[s.size()] = '\0';

#ifdef DEBUG_OSRL2AMPL
                std::cout << s << " has length " << s.size() << " p = " << suftab[k].name << std::endl;
#endif

                suftab[k].table  = NULL;
                suftab[k].kind   = ASL_Sufkind_con;
                suftab[k].nextra = 1;
            }

#ifdef DEBUG_OSRL2AMPL
            for (i=0; i < nSuffixes; i++)
                std::cout << i << ": suffix " << suftab[i].name << " of kind " << suftab[i].kind << std::endl; 
#endif

            // make sure to inform AMPL of the suffixes you want to send back

            suf_declare(suftab, nSuffixes);

/*          Now go through the suffixes again and prepare the data for writing
 *
 *          ASL suf_iput and suf_rput do not actually produce any output; rather
 *          they store pointers to the material that is to be printed in a later
 *          call to routine write_sol. For that reason it is necessary to copy
 *          *all* the array-indexed results. Since ASL only handles real and integer
 *          values, this is done in two pointer arrays.
 */
            double **rData = new double*[nSuffixes];
            int    **iData = new    int*[nSuffixes];

            for (int i=0; i<nSuffixes; i++)
            {
                rData[i] = NULL;
                iData[i] = NULL;
            }

            int iSuf = 0;

            for (i=0; i < osresult->getNumberOfOtherVariableResults(0); i++, iSuf++)
            {
                if ( (osresult->optimization->solution[0]->variables->other[i]->var != NULL) || 
                     (osresult->optimization->solution[0]->variables->other[i]->enumeration != NULL) )
                {
                    n = osresult->getOtherVariableResultArrayDense(0, i, otherVar, numVars);
                    if (n < 0) 
                        throw ErrorClass("unspecified error in routine getOtherVariableResultArrayDense()");
                    else if (n > 0)
                    {

#ifdef DEBUG_OSRL2AMPL
                        std::cout << "found variable suffix " << osresult->getOtherVariableResultName(0, i) 
                                  << " of type " << osresult->getOtherVariableResultArrayType(0, i) << std::endl;
#endif

                        if ( (osresult->getOtherVariableResultArrayType(0, i) == "real")    || 
                             (osresult->getOtherVariableResultArrayType(0, i) == "double")  || 
                             (osresult->getOtherVariableResultArrayType(0, i) == "numeric") )
                        {
                            rData[iSuf] = new double[n];
                            for (int k=0; k<n; k++)
                                rData[iSuf][k] = os_strtod(otherVar[k].c_str(), NULL);
#ifdef DEBUG_OSRL2AMPL
                            std::cout << "values (real): ";
                            for (int k=0; k < n; k++)
                                std::cout << rData[iSuf][k] << " ";
                            std::cout << std::endl << std::endl;
#endif 

                            suf_rput((osresult->getOtherVariableResultName(0, i)).c_str(), ASL_Sufkind_var, rData[iSuf]);
                        }
                        else if (osresult->getOtherVariableResultArrayType(0, i) == "integer")
                        {
                            iData[iSuf] = new int[n];
                            for (int k=0; k<n; k++)
                                iData[iSuf][k] = atoi(otherVar[k].c_str());
#ifdef DEBUG_OSRL2AMPL
                            std::cout << "values (integer): ";
                            for (int k=0; k < n; k++)
                                std::cout << iData[iSuf][k] << " ";
                            std::cout << std::endl << std::endl;
#endif 
                            suf_iput((osresult->getOtherVariableResultName(0, i)).c_str(), ASL_Sufkind_var, iData[iSuf]);
//                            delete[] ivalues; ivalues = NULL;                            
                        }
                        else
                            throw ErrorClass("otherVariableResult has unsupported type in OSosrl2ampl()");
                    } 
                }
            }

            // Suffixes associated with the objectives

            for (i=0; i < osresult->getNumberOfOtherObjectiveResults(0); i++, k++)
            {
                if ( (osresult->optimization->solution[0]->objectives->other[i]->obj != NULL) || 
                     (osresult->optimization->solution[0]->objectives->other[i]->enumeration != NULL) )
                {
                    n = osresult->getOtherObjectiveResultArrayDense(0, i, otherObj, numObjs);
                    if (n < 0) 
                        throw ErrorClass("unspecified error in routine getOtherObjectiveResultArrayDense()");
                    else if (n > 0)
                    {
#ifdef DEBUG_OSRL2AMPL
                        std::cout << "found objective suffix " << osresult->getOtherObjectiveResultName(0, i) 
                                  << " of type " << osresult->getOtherObjectiveResultArrayType(0, i) << std::endl;
                        std::cout << "retrieved these values:";
                        for (int k=0; k<n; k++)
                            std::cout << " " << otherObj[k];
                        std::cout << std::endl; 
#endif

                        if ( (osresult->getOtherObjectiveResultArrayType(0, i) == "real")    || 
                             (osresult->getOtherObjectiveResultArrayType(0, i) == "double")  || 
                             (osresult->getOtherObjectiveResultArrayType(0, i) == "numeric") )
                        {
                            rData[iSuf] = new double[n];
                            for (int k=0; k<n; k++)
                                rData[iSuf][k] = os_strtod(otherObj[k].c_str(), NULL);
#ifdef DEBUG_OSRL2AMPL
                            std::cout << "values (real): ";
                            for (int k=0; k < n; k++)
                                std::cout << rData[iSuf][k] << " ";
                            std::cout << std::endl << std::endl;
#endif 
                            suf_rput((osresult->getOtherObjectiveResultName(0, i)).c_str(), ASL_Sufkind_obj, rData[iSuf]);
//                            delete[] rvalues; rvalues = NULL;                            
                        }
                        else if (osresult->getOtherObjectiveResultArrayType(0, i) == "integer")
                        {
                            iData[iSuf] = new int[n];
                            for (int k=0; k<n; k++)
                                iData[iSuf][k] = atoi(otherObj[k].c_str());
#ifdef DEBUG_OSRL2AMPL
                            std::cout << "values (integer): ";
                            for (int k=0; k < n; k++)
                                std::cout << iData[iSuf][k] << " ";
                            std::cout << std::endl << std::endl;
#endif 
                            suf_iput((osresult->getOtherObjectiveResultName(0, i)).c_str(), ASL_Sufkind_obj, iData[iSuf]);
//                            delete[] ivalues; ivalues = NULL;                            
                        }
                        else
                            throw ErrorClass("otherObjectiveResult has unsupported type in OSosrl2ampl()");
                    }
                }
            }

            // Suffixes associated with constraints

            for (i=0; i < osresult->getNumberOfOtherConstraintResults(0); i++, k++)
            {
                if ( (osresult->optimization->solution[0]->constraints->other[i]->con != NULL) || 
                     (osresult->optimization->solution[0]->constraints->other[i]->enumeration != NULL) )
                {
                    n = osresult->getOtherConstraintResultArrayDense(0, i, otherCon, numCons);
                    if (n < 0) 
                        throw ErrorClass("unspecified error in routine getOtherConstraintResultArrayDense()");
                    else if (n > 0)
                    {
#ifdef DEBUG_OSRL2AMPL
                        std::cout << "found constraint suffix " << osresult->getOtherConstraintResultName(0, i)
                                  << " of type " << osresult->getOtherConstraintResultArrayType(0, i) << std::endl;
#endif
                        if ( (osresult->getOtherConstraintResultArrayType(0, i) == "real")    || 
                             (osresult->getOtherConstraintResultArrayType(0, i) == "double")  || 
                             (osresult->getOtherConstraintResultArrayType(0, i) == "numeric") )
                        {
                            rData[iSuf] = new double[n];
                            for (int k=0; k<n; k++)
                                rData[iSuf][k] = os_strtod(otherCon[k].c_str(), NULL);
#ifdef DEBUG_OSRL2AMPL
                            std::cout << "values (real): ";
                            for (int k=0; k < n; k++)
                                std::cout << rData[iSuf][k] << " ";
                            std::cout << std::endl << std::endl;
#endif 
                            suf_rput((osresult->getOtherConstraintResultName(0, i)).c_str(), ASL_Sufkind_con, rData[iSuf]);
//                            delete[] rvalues; rvalues = NULL;                            
                        }
                        else if (osresult->getOtherConstraintResultArrayType(0, i) == "integer")
                        {
                            iData[iSuf] = new int[n];
                            for (int k=0; k<n; k++)
                                iData[iSuf][k] = atoi(otherCon[k].c_str());
#ifdef DEBUG_OSRL2AMPL
                            std::cout << "values (integer): ";
                            for (int k=0; k < n; k++)
                                std::cout << iData[iSuf][k] << " ";
                            std::cout << std::endl << std::endl;
#endif 
                            suf_iput((osresult->getOtherConstraintResultName(0, i)).c_str(), ASL_Sufkind_con, iData[iSuf]);
//                            delete[] ivalues; ivalues = NULL;                            
                        }
                        else
                            throw ErrorClass("otherConstraintResult has unsupported type in OSosrl2ampl()");
                    }
                }
            }

            // Basis information associated with the variables


            // note that AMPL uses different numeric values for representing basis status:
            // 1 = basic                                    = ENUM_BASIS_STATUS_basic
            // 3 = nonbasic <= (normally =) lower bound     = ENUM_BASIS_STATUS_atLower
            // 4 = nonbasic >= (normally =) upper bound     = ENUM_BASIS_STATUS_atUpper
            // 5 = nonbasic at equal lower and upper bounds = ENUM_BASIS_STATUS_atEquality
            // 6 = nonbasic between bounds                  = ENUM_BASIS_STATUS_isFree
            // 2 = superbasic                               = ENUM_BASIS_STATUS_superbasic
            // 0 = no status assigned                       = ENUM_BASIS_STATUS_unknown

            int  basCode[ENUM_BASIS_STATUS_NUMBER_OF_STATES] = {1,3,4,5,6,2,0};
            if (have_basic_var)
            {
                iData[iSuf] = new int[numVars];
                n = osresult->getBasisInformationDense(0, ENUM_PROBLEM_COMPONENT_variables, iData[iSuf], numVars);
                if (n < 0) 
                    throw ErrorClass("unspecified error in routine getBasisInformationDense()");
                else if (n > 0)
                {
                    for (i=0; i<numVars; i++)
                        iData[iSuf][i] = basCode[iData[iSuf][i]];
#ifdef DEBUG_OSRL2AMPL
                            std::cout << "primal basic: ";
                            for (int k=0; k < numVars; k++)
                                std::cout << iData[iSuf][k] << " ";
                            std::cout << std::endl << std::endl;
#endif 
                    suf_iput("sstatus", ASL_Sufkind_var, iData[iSuf]);
                }
                iSuf++;
            }
            if (have_basic_con)
            {
                iData[iSuf] = new int[numCons];
                n = osresult->getBasisInformationDense(0, ENUM_PROBLEM_COMPONENT_constraints, iData[iSuf], numCons);
                if (n < 0) 
                    throw ErrorClass("unspecified error in routine getBasisInformationDense()");
                else if (n > 0)
                {
                    for (i=0; i<numCons; i++)
                        iData[iSuf][i] = basCode[iData[iSuf][i]];
#ifdef DEBUG_OSRL2AMPL
                            std::cout << "dual basic: ";
                            for (int k=0; k < numCons; k++)
                                std::cout << iData[iSuf][k] << " ";
                            std::cout << std::endl << std::endl;
#endif 
                    suf_iput("sstatus", ASL_Sufkind_con, iData[iSuf]);
                }
            }

            // finally set the solution status 
            
            int OS_solve_result = returnSolutionStatus(osresult->getSolutionStatusType(0));
            switch (OS_solve_result)
            {
                case (ENUM_SOLUTION_STATUS_globallyOptimal): 
                {
                    solve_result_num = 90;
                    break;
                } 
                case (ENUM_SOLUTION_STATUS_locallyOptimal): 
                {
                    solve_result_num = 50;
                    break;
                } 
                case (ENUM_SOLUTION_STATUS_optimal): 
                {
                    solve_result_num = 10;
                    break;
                } 
                case (ENUM_SOLUTION_STATUS_bestSoFar): 
                {
                    solve_result_num = 110;
                    break;
                } 
                case (ENUM_SOLUTION_STATUS_feasible): 
                {
                    solve_result_num = 120;
                    break;
                } 
                case (ENUM_SOLUTION_STATUS_infeasible): 
                {
                    solve_result_num = 200;
                    break;
                } 
                case (ENUM_SOLUTION_STATUS_unbounded): 
                {
                    solve_result_num = 300;
                    break;
                } 
                case (ENUM_SOLUTION_STATUS_error): 
                {
                    solve_result_num = 500;
                    break;
                } 
                case (ENUM_SOLUTION_STATUS_unsure): 
                {
                    solve_result_num = 520;
                    break;
                } 
                case (ENUM_SOLUTION_STATUS_other): 
                {
                    solve_result_num = 550;
                    break;
                } 
                default:
                    throw ErrorClass("Unknown solution status detected");
            } //end of switch statement

            // Produce a message to send back to AMPL

            std::string solMsg;
            std::string tmpStr;
            tmpStr = osresult->getSolutionMessage(0);
            if (tmpStr != "") 
                solMsg = tmpStr;
            else
            {
                std::ostringstream outStr;
                try
                {
                    outStr << "Solution status: " << osresult->getSolutionStatusType(0) << std::endl;
                    tmpStr = osresult->getSolutionStatusDescription(0);
                    if (tmpStr != "")
                        outStr << "Description:     " << tmpStr << std::endl;
                }
                catch (const ErrorClass& eclass)
                {
                    outStr << "Solution status: " << "unknown" << std::endl;
                }
                try
                {
                    int objIdx = osresult->getSolutionTargetObjectiveIdx(0);
                    if (objIdx == 0) objIdx = -1;
                    double objVal = osresult-> getOptimalObjValue(objIdx,0);
                    outStr << "Objective value: " << objVal << std::endl;
                    outStr << "Objective index: " << objIdx << std::endl;
                }
                catch (const ErrorClass& eclass)
                {
                    outStr << "Objective info:  " << "not returned" << std::endl;
                }
                solMsg = outStr.str();
            }

            amplflag = 1; // to suppress a second writing of the solMsg

/* 
  If we ever want to send back a non-null option info pointer (last argument of write_sol), 
  we should do this (according to David Gay):

            oi->wantsol = 9;

  after suitably declaring and populating

    Option_Info *oi; 
 */

            write_sol(const_cast<char*>(solMsg.c_str()),  x, y , NULL);

            if (osrlreader != NULL) delete osrlreader;
            osrlreader = NULL;
            delete [] x; x = NULL;
            delete [] y; y = NULL;
            delete [] otherVar; otherVar = NULL;
            delete [] otherObj; otherObj = NULL;
            delete [] otherCon; otherCon = NULL;
            for (i=0; i<nSuffixes; i++)
            {
                if (rData[i] != NULL) delete [] rData[i]; 
                if (iData[i] != NULL) delete [] iData[i];
            }
            delete [] rData; rData = NULL;
            delete [] iData; iData = NULL;

            return true;
        }
        catch(const ErrorClass& eclass)
        {
            std::cout << "There was an error: " + eclass.errormsg << std::endl;
            if (x != NULL) delete [] x; x = NULL;
            if (y != NULL) delete [] y; y = NULL;
            if (otherVar != NULL) delete [] otherVar; otherVar = NULL;
            if (otherObj != NULL) delete [] otherObj; otherObj = NULL;
            if (otherCon != NULL) delete [] otherCon; otherCon = NULL;
            if (osrlreader != NULL) delete osrlreader;
            osrlreader = NULL;
            return false;
        }
    }
}

