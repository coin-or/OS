/* $Id: OSosrl2ampl.cpp 4210 2011-06-28 09:44:54Z Gassmann $ */
/** @file OSosrl2ampl.cpp
 * 
 * @author  Horand Gassmann, Jun Ma, Kipp Martin
 *
 * \remarks
 * Copyright (C) 2012, Horand Gassmann, Jun Ma, Kipp Martin,
 * and the University of Chicago.
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
#include "OSOutput.h"

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

using std::endl;

#ifdef HAVE_STDINT_H
#include <stdint.h>
#endif

#ifdef HAVE_STDLIB_H
#include <stdlib.h>
#endif


OSosrl2ampl::OSosrl2ampl()
{
}

OSosrl2ampl::~OSosrl2ampl()
{
}

bool OSosrl2ampl::writeSolFile(std::string osrl, ASL *asl, std::string solfile)
{
    OSrLReader *osrlreader = NULL;
    OSResult   *osresult;
    std::ostringstream outStr;

    if (osrl == "")
    {
//        std::string solMsg = "No solution returned!";
        std::string solMsg = " ";
        solve_result_num = 550;
        write_sol(const_cast<char*>(solMsg.c_str()),  NULL, NULL , NULL);
        return true;
    }
    else
    {
#ifndef NDEBUG
        outStr.str("");
        outStr.clear();
        outStr << std::endl << osrl << std::endl << std::endl << std::endl;
        osoutput->OSPrint(ENUM_OUTPUT_AREA_OSModelInterfaces, ENUM_OUTPUT_LEVEL_debug, outStr.str());
#endif

        double *x = NULL;
        double *y = NULL;
        std::string *otherVar = NULL;
        std::string *otherObj = NULL;
        std::string *otherCon = NULL;

        double **rData = NULL;
        int    **iData = NULL;
        double* rvalues = NULL;
        int*    ivalues = NULL;
        int     nSuffixes = 0;

        try
        {
            osrlreader = new OSrLReader();
            osresult = osrlreader->readOSrL( osrl);
            // do the following so output is not written twice
            // see page 23 of hooking solver to AMPL
            // need_nl = printf( sReport.c_str());

/** First check if there is a solution
 *  (There might not be if some error condition was set)
 */
            int numSols = osresult->getSolutionNumber();

            if (numSols == 0)
            {
//                std::string solMsg = "No solution returned!";
                std::string solMsg = " ";
                solve_result_num = 550;
                write_sol(const_cast<char*>(solMsg.c_str()),  NULL, NULL , NULL);
                return true;
            }    

            //
            int i;
            int vecSize;
            int numVars = osresult->getVariableNumber();
            int numObjs = osresult->getObjectiveNumber();
            int numCons = osresult->getConstraintNumber();

            if (numVars > 0)
            {
                x = new double[ numVars];
                otherVar = new std::string[numVars];
            }
            if (numCons > 0)
            {
                y = new double[ numCons];
                otherCon = new std::string[numCons];
            }
            if (numObjs > 0)
            {
                otherObj = new std::string[numObjs];
            }

            std::vector<IndexValuePair*> primalValPair;
            std::vector<IndexValuePair*> dualValPair;
            dualValPair = osresult->getOptimalDualVariableValues( 0);
            primalValPair = osresult->getOptimalPrimalVariableValues( 0);

            for (i = 0; i < numVars; i++)
            {
                x[i] = 0.0;
            }
            vecSize = primalValPair.size();
            for (i = 0; i < vecSize; i++)
            {
                x[ primalValPair[i]->idx ] = primalValPair[i]->value;
#ifndef NDEBUG
                outStr.str("");
                outStr.clear();
                outStr << "index =  " << primalValPair[i]->idx   << std::endl;
                outStr << "value =  " << primalValPair[i]->value << std::endl;
                osoutput->OSPrint(ENUM_OUTPUT_AREA_OSModelInterfaces, ENUM_OUTPUT_LEVEL_debug, outStr.str());
#endif
            }

            for (i = 0; i < numCons; i++)
            {
                y[i] = 0.0;
            }
            vecSize = dualValPair.size();
            for (i = 0; i < vecSize; i++)
            {
                y[ dualValPair[i]->idx ] = dualValPair[i]->value;
#ifndef NDEBUG
                outStr.str("");
                outStr.clear();
                outStr << "index =  " << dualValPair[i]->idx   << std::endl;
                outStr << "value =  " << dualValPair[i]->value << std::endl;
                osoutput->OSPrint(ENUM_OUTPUT_AREA_OSModelInterfaces, ENUM_OUTPUT_LEVEL_debug, outStr.str());
#endif
            }

            // return all solution results that are indexed over variables, objectives or constraints as suffixes

            int n;
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

            if (nSuffixes > 0)
            {
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

#ifndef NDEBUG
                    outStr.str("");
                    outStr.clear();
                    outStr << s << " has length " << s.size() << " p = " << suftab[k].name << std::endl;
                    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSModelInterfaces, ENUM_OUTPUT_LEVEL_debug, outStr.str());
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

#ifndef NDEBUG
                    outStr.str("");
                    outStr.clear();
                    outStr << s << " has length " << s.size() << " p = " << suftab[k].name << std::endl;
                    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSModelInterfaces, ENUM_OUTPUT_LEVEL_debug, outStr.str());
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

#ifndef NDEBUG
                    outStr.str("");
                    outStr.clear();
                    outStr << s << " has length " << s.size() << " p = " << suftab[k].name << std::endl;
                    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSModelInterfaces, ENUM_OUTPUT_LEVEL_debug, outStr.str());
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

#ifndef NDEBUG
                    outStr.str("");
                    outStr.clear();
                    outStr << s << " has length " << s.size() << " p = " << suftab[k].name << std::endl;
                    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSModelInterfaces, ENUM_OUTPUT_LEVEL_debug, outStr.str());
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

#ifndef NDEBUG
                    outStr.str("");
                    outStr.clear();
                    outStr << s << " has length " << s.size() << " p = " << suftab[k].name << std::endl;
                    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSModelInterfaces, ENUM_OUTPUT_LEVEL_debug, outStr.str());
#endif

                    suftab[k].table  = NULL;
                    suftab[k].kind   = ASL_Sufkind_con;
                    suftab[k].nextra = 1;
                }

#ifndef NDEBUG
                outStr.str("");
                outStr.clear();
                for (i=0; i < nSuffixes; i++)
                    outStr << i << ": suffix " << suftab[i].name << " of kind " << suftab[i].kind << std::endl; 
                osoutput->OSPrint(ENUM_OUTPUT_AREA_OSModelInterfaces, ENUM_OUTPUT_LEVEL_debug, outStr.str());
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
                rData = new double*[nSuffixes];
                iData = new    int*[nSuffixes];

                std::string resultType;
                std::string resultName;

                for (i=0; i<nSuffixes; i++)
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
                        if (numVars > 0)
                            n = osresult->getOtherVariableResultArrayDense(0, i, otherVar, numVars);
                        else
                            n = 0;
                        if (n < 0) 
                            throw ErrorClass("unspecified error in routine getOtherVariableResultArrayDense()");
                        else if (n > 0)
                        {
                            resultType = osresult->getOtherVariableResultArrayType(0, i);
                            resultName = osresult->getOtherVariableResultName(0, i);

#ifndef NDEBUG
                            outStr.str("");
                            outStr.clear();
                            outStr << "found variable suffix " << resultName 
                                   << " of type " << resultType << std::endl;
                            osoutput->OSPrint(ENUM_OUTPUT_AREA_OSModelInterfaces, ENUM_OUTPUT_LEVEL_debug, outStr.str());

                            outStr.str("");
                            outStr.clear();
                            outStr << "retrieved these values:";
                            for (int m=0; m<n; m++)
                                outStr << " " << otherVar[m];
                            outStr << std::endl;
                            osoutput->OSPrint(ENUM_OUTPUT_AREA_OSModelInterfaces, ENUM_OUTPUT_LEVEL_trace, outStr.str());
#endif

                            if (    (resultType == "real")     
                                 || (resultType == "double")   
                                 || (resultType == "numeric") 
//                             || (resultType == "")        // some versions of OSSolverService may not return a type
                               )
                            {
                                rData[iSuf] = new double[n];
                                for (int m=0; m<n; m++)
                                    rData[iSuf][m] = os_strtod(otherVar[m].c_str(), NULL);
#ifndef NDEBUG
                                outStr.str("");
                                outStr.clear();
                                outStr << "values (real): ";
                                for (int m=0; m<n; m++)
                                    outStr << rData[iSuf][m] << " ";
                                outStr << std::endl << std::endl;
                                osoutput->OSPrint(ENUM_OUTPUT_AREA_OSModelInterfaces, ENUM_OUTPUT_LEVEL_debug, outStr.str());
#endif 

                                suf_rput(resultName.c_str(), ASL_Sufkind_var, rData[iSuf]);
                            }
                            else if (resultType == "integer")
                            {
                                iData[iSuf] = new int[n];
                                for (int m=0; m<n; m++)
                                    iData[iSuf][m] = atoi(otherVar[m].c_str());
#ifndef NDEBUG
                                outStr.str("");
                                outStr.clear();
                                outStr << "values (integer): ";
                                for (int m=0; m<n; m++)
                                    outStr << iData[iSuf][m] << " ";
                                outStr << std::endl << std::endl;
                                osoutput->OSPrint(ENUM_OUTPUT_AREA_OSModelInterfaces, ENUM_OUTPUT_LEVEL_debug, outStr.str());
#endif 
                                suf_iput(resultName.c_str(), ASL_Sufkind_var, iData[iSuf]);
                            }
                            else
                            {
                                outStr.str("");
                                outStr.clear();
                                outStr << "otherVariableResult " << i << " (" << resultName << ")" << " has unsupported type " << resultType<< " in OSosrl2ampl()" << std::endl;
                                throw ErrorClass(outStr.str());
                            }
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
                            resultType = osresult->getOtherObjectiveResultArrayType(0, i);
                            resultName = osresult->getOtherObjectiveResultName(0, i);
#ifndef NDEBUG
                            outStr.str("");
                            outStr.clear();
                            outStr << "found objective suffix " << resultName 
                                   << " of type " << resultType << std::endl;
                            osoutput->OSPrint(ENUM_OUTPUT_AREA_OSModelInterfaces, ENUM_OUTPUT_LEVEL_debug, outStr.str());

                            outStr.str("");
                            outStr.clear();
                            outStr << "retrieved these values:";
                            for (int m=0; m<n; m++)
                                outStr << " " << otherObj[m];
                            outStr << std::endl;
                            osoutput->OSPrint(ENUM_OUTPUT_AREA_OSModelInterfaces, ENUM_OUTPUT_LEVEL_trace, outStr.str());
#endif

                            if (    (resultType == "real")     
                                 || (resultType == "double")   
                                 || (resultType == "numeric") 
//                             || (resultType == "")        // some versions of OSSolverService may not return a type
                               )
                            {
                                rData[iSuf] = new double[n];
                                for (int m=0; m<n; m++)
                                    rData[iSuf][m] = os_strtod(otherObj[m].c_str(), NULL);
#ifndef NDEBUG
                                outStr.str("");
                                outStr.clear();
                                outStr << "values (real): ";
                                for (int m=0; m<n; m++)
                                    outStr << rData[iSuf][m] << " ";
                                outStr << std::endl << std::endl;
                                osoutput->OSPrint(ENUM_OUTPUT_AREA_OSModelInterfaces, ENUM_OUTPUT_LEVEL_debug, outStr.str());
#endif 
                                suf_rput(resultName.c_str(), ASL_Sufkind_obj, rData[iSuf]);
//                                delete [] rData; //creates a segfault...
                            }
                            else if (resultType == "integer")
                            {
                                iData[iSuf] = new int[n];
                                for (int m=0; m<n; m++)
                                    iData[iSuf][m] = atoi(otherObj[m].c_str());
#ifndef NDEBUG
                                outStr.str("");
                                outStr.clear();
                                outStr << "values (integer): ";
                                for (int m=0; m<n; m++)
                                    outStr << iData[iSuf][m] << " ";
                                outStr << std::endl << std::endl;
                                osoutput->OSPrint(ENUM_OUTPUT_AREA_OSModelInterfaces, ENUM_OUTPUT_LEVEL_debug, outStr.str());
#endif 
                                suf_iput(resultName.c_str(), ASL_Sufkind_obj, iData[iSuf]);
//                                delete [] iData; //creates a segfault...
                            }
                            else
                            {
                                outStr.str("");
                                outStr.clear();
                                outStr << "otherObjectiveResult " << i << " (" << resultName << ")" << " has unsupported type " << resultType<< " in OSosrl2ampl()" << std::endl;
                                throw ErrorClass(outStr.str());
                            }
                        }
                    }
                }

                // Suffixes associated with constraints

                for (i=0; i < osresult->getNumberOfOtherConstraintResults(0); i++, k++)
                {
                    if ( (osresult->optimization->solution[0]->constraints->other[i]->con != NULL) || 
                         (osresult->optimization->solution[0]->constraints->other[i]->enumeration != NULL) )
                    {
                        if (numCons > 0)
                            n = osresult->getOtherConstraintResultArrayDense(0, i, otherCon, numCons);
                        else
                            n = 0;
                        if (n < 0) 
                            throw ErrorClass("unspecified error in routine getOtherConstraintResultArrayDense()");
                        else if (n > 0)
                        {
                            resultType = osresult->getOtherConstraintResultArrayType(0, i);
                            resultName = osresult->getOtherConstraintResultName(0, i);
#ifndef NDEBUG
                            outStr.str("");
                            outStr.clear();
                            outStr << "found constraint suffix " << resultName
                                   << " of type " << resultType << std::endl;
                            osoutput->OSPrint(ENUM_OUTPUT_AREA_OSModelInterfaces, ENUM_OUTPUT_LEVEL_debug, outStr.str());
    
                            outStr.str("");
                            outStr.clear();
                            outStr << "retrieved these values:";
                            for (int m=0; m<n; m++)
                                outStr << " " << otherCon[m];
                            outStr << std::endl;
                            osoutput->OSPrint(ENUM_OUTPUT_AREA_OSModelInterfaces, ENUM_OUTPUT_LEVEL_trace, outStr.str());
#endif

                            if (    (resultType == "real")     
                                 || (resultType == "double")   
                                 || (resultType == "numeric") 
//                             || (resultType == "")        // some versions of OSSolverService may not return a type
                               )
                            {
                                rData[iSuf] = new double[n];
                                for (int m=0; m<n; m++)
                                    rData[iSuf][m] = os_strtod(otherCon[m].c_str(), NULL);
#ifndef NDEBUG
                                outStr.str("");
                                outStr.clear();
                                outStr << "values (real): ";
                                for (int m=0; m < n; m++)
                                    outStr << rData[iSuf][m] << " ";
                                outStr << std::endl << std::endl;
                                osoutput->OSPrint(ENUM_OUTPUT_AREA_OSModelInterfaces, ENUM_OUTPUT_LEVEL_debug, outStr.str());
#endif 
                                suf_rput(resultName.c_str(), ASL_Sufkind_con, rData[iSuf]);
//                                delete [] rData; //creates a segfault...
                            }
                            else if (resultType == "integer")
                            {
                                iData[iSuf] = new int[n];
                                for (int m=0; m<n; m++)
                                    iData[iSuf][m] = atoi(otherCon[m].c_str());
#ifndef NDEBUG
                                outStr.str("");
                                outStr.clear();
                                outStr << "values (integer): ";
                                for (int m=0; m < n; m++)
                                    outStr << iData[iSuf][m] << " ";
                                outStr << std::endl << std::endl;
                                osoutput->OSPrint(ENUM_OUTPUT_AREA_OSModelInterfaces, ENUM_OUTPUT_LEVEL_debug, outStr.str());
#endif 
                                suf_iput(resultName.c_str(), ASL_Sufkind_con, iData[iSuf]);
//                                delete [] iData; //creates a segfault...
                            }
                            else
                            {
                                outStr.str("");
                                outStr.clear();
                                outStr << "otherConstraintResult " << i << " (" << resultName << ")" << " has unsupported type " << resultType<< " in OSosrl2ampl()" << std::endl;
                                throw ErrorClass(outStr.str());
                            }
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
                if (have_basic_var && numVars > 0)
                {
                    iData[iSuf] = new int[numVars];
                    n = osresult->getBasisInformationDense(0, ENUM_PROBLEM_COMPONENT_variables, iData[iSuf], numVars);
                    if (n < 0) 
                        throw ErrorClass("unspecified error in routine getBasisInformationDense()");
                    else if (n > 0)
                    {
                        for (i=0; i<numVars; i++)
                            iData[iSuf][i] = basCode[iData[iSuf][i]];
#ifndef NDEBUG
                        outStr.str("");
                        outStr.clear();
                        outStr << "primal basic: ";
                        for (int k=0; k < numVars; k++)
                            outStr << iData[iSuf][k] << " ";
                        outStr << std::endl << std::endl;
                        osoutput->OSPrint(ENUM_OUTPUT_AREA_OSModelInterfaces, ENUM_OUTPUT_LEVEL_debug, outStr.str());
#endif 
                        suf_iput("sstatus", ASL_Sufkind_var, iData[iSuf]);
                    }
                    iSuf++;
//                    delete [] iData; //creates a segfault...
                }
                if (have_basic_con && numCons > 0)
                {
                    iData[iSuf] = new int[numCons];
                    n = osresult->getBasisInformationDense(0, ENUM_PROBLEM_COMPONENT_constraints, iData[iSuf], numCons);
                    if (n < 0) 
                        throw ErrorClass("unspecified error in routine getBasisInformationDense()");
                    else if (n > 0)
                    {
                        for (i=0; i<numCons; i++)
                            iData[iSuf][i] = basCode[iData[iSuf][i]];
#ifndef NDEBUG
                        outStr.str("");
                        outStr.clear();
                        outStr << "dual basic: ";
                        for (int k=0; k < numCons; k++)
                            outStr << iData[iSuf][k] << " ";
                        outStr << std::endl << std::endl;
                        osoutput->OSPrint(ENUM_OUTPUT_AREA_OSModelInterfaces, ENUM_OUTPUT_LEVEL_debug, outStr.str());
#endif 
                        suf_iput("sstatus", ASL_Sufkind_con, iData[iSuf]);
                        iSuf++;
//                        delete [] iData; //creates a segfault...
                    }
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

            try
            {
#ifndef NDEBUG
                osoutput->OSPrint(ENUM_OUTPUT_AREA_OSModelInterfaces, ENUM_OUTPUT_LEVEL_debug, "Calling ASL");
#endif 
                write_solf_ASL(asl, const_cast<char*>(solMsg.c_str()),  x, y , NULL, solfile.c_str());

#ifndef NDEBUG
                osoutput->OSPrint(ENUM_OUTPUT_AREA_OSModelInterfaces, ENUM_OUTPUT_LEVEL_debug, "Returned from ASL");
#endif 
            }
            catch(const ErrorClass& eclass)
            {
#ifndef NDEBUG
                osoutput->OSPrint(ENUM_OUTPUT_AREA_OSModelInterfaces, ENUM_OUTPUT_LEVEL_debug, "Error in ASL");
#endif 
            }
            // garbage collection
            if (osrlreader != NULL) delete osrlreader;
            osrlreader = NULL;
            if (x != NULL) 
                delete [] x; 
            x = NULL;
            if (y != NULL)
                delete [] y; 
            y = NULL;
            if (otherVar != NULL)
                delete [] otherVar; 
            otherVar = NULL;
            if (otherObj != NULL)
                delete [] otherObj; 
            otherObj = NULL;
            if (otherCon != NULL)
                delete [] otherCon; 
            otherCon = NULL;
            if (rData != NULL)
            {
                for (i=0; i<nSuffixes; i++)
                {
                    if (rData[i] != NULL) delete [] rData[i];
                }
                delete [] rData; 
                rData = NULL;
            }
            if (iData != NULL)
            {
                for (i=0; i<nSuffixes; i++)
                {
                    if (iData[i] != NULL) delete [] iData[i];
                }
                delete [] iData; 
                iData = NULL;
            }
            return true;
        }
        catch(const ErrorClass& eclass)
        {
            outStr.str("");
            outStr.clear();
            outStr << "There was an error: " + eclass.errormsg << std::endl;
            osoutput->OSPrint(ENUM_OUTPUT_AREA_OSModelInterfaces, ENUM_OUTPUT_LEVEL_error, outStr.str());
            if (osrlreader != NULL) delete osrlreader;
            osrlreader = NULL;
            if (x != NULL) 
                delete [] x; 
            x = NULL;
            if (y != NULL)
                delete [] y; 
            y = NULL;
            if (otherVar != NULL)
                delete [] otherVar; 
            otherVar = NULL;
            if (otherObj != NULL)
                delete [] otherObj; 
            otherObj = NULL;
            if (otherCon != NULL)
                delete [] otherCon; 
            otherCon = NULL;
            if (rData != NULL)
            {
                for (int i=0; i<nSuffixes; i++)
                {
                    if (rData[i] != NULL) delete [] rData[i];
                }
                delete [] rData; 
                rData = NULL;
            }
            if (iData != NULL)
            {
                for (int i=0; i<nSuffixes; i++)
                {
                    if (iData[i] != NULL) delete [] iData[i];
                }
                delete [] iData; 
                iData = NULL;
            }
            return false;
        }
    }
}

