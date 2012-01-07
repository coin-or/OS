/* $Id: OSServiceMethods.cpp 4340 2011-10-15 20:08:33Z Gassmann $ */
/** @file OSServiceMethods.cpp
 *
 * @author  Horand Gassmann, Jun Ma, Kipp Martin,
 *
 * \remarks
 * Copyright (C) 2012, Horand Gassmann, Jun Ma, Kipp Martin,
 * Dalhousie University, Northwestern University, and the University of Chicago.
 * All Rights Reserved.
 * This software is licensed under the Eclipse Public License.
 * Please see the accompanying LICENSE file in root directory for terms.
 *
 */


#include "OSConfig.h"
#include "OSCommandLine.h"
#include "OSServiceMethods.h"
#include "OSResult.h"
#include "OSiLReader.h"
#include "OSiLWriter.h"
#include "OSoLReader.h"
#include "OSrLReader.h"
#include "OSrLWriter.h"
#include "OSInstance.h"
#include "OSOption.h"
#include "OSoLWriter.h"
#include "OSFileUtil.h"
#include "OSConfig.h"
#include "OSDefaultSolver.h"
#include "OSWSUtil.h"
#include "OSSolverAgent.h"
#include "OShL.h"
#include "OSErrorClass.h"
#include "OSmps2osil.h"
#include "OSBase64.h"
#include "OSRunSolver.h"

#ifdef COIN_HAS_ASL
#include "OSnl2osil.h"
#endif

#ifdef COIN_HAS_GAMSUTILS
#include "OSgams2osil.hpp"
#endif

#ifdef COIN_HAS_IPOPT
# ifndef COIN_HAS_ASL
#  include "OSIpoptSolver.h"
#  undef COIN_HAS_ASL
# else
#  include "OSIpoptSolver.h"
# endif
#endif

#ifdef COIN_HAS_BONMIN
#include "OSBonminSolver.h"
#endif

#ifdef COIN_HAS_COUENNE
#include "OSCouenneSolver.h"
#endif

#ifdef COIN_HAS_LINDO
#include "OSLindoSolver.h"
#endif

#ifdef COIN_HAS_KNITRO
#include "OSKnitroSolver.h"
#endif

#include "OSOptionsStruc.h"

#include<stdio.h>
#include <map>


using std::cout;
using std::endl;
using std::ostringstream;
using std::string;
using std::map;

#define DEBUG_CL_INTERFACE

OSServiceMethods::OSServiceMethods(): resultString("")
{
#ifdef DEBUG_OSSERVICEMETHODS
    cout << "Inside the OSServiceMethods Constructor" << endl;
#endif
}//end default OSServiceMethods constructor


OSServiceMethods::~OSServiceMethods()
{
#ifdef DEBUG_OSSERVICEMETHODS
    cout << "Inside the OSServiceMethods Destructor" << endl;
#endif
}// end OSServiceMethods destructor


OSServiceMethods::OSServiceMethods(OSCommandLine *oscommandline): resultString("") 
{
#ifdef DEBUG_OSSERVICEMETHODS
    cout << "Inside the OSServiceMethods Constructor" << endl;
#endif

    FileUtil   *fileUtil   = NULL;
	OSiLReader *osilreader = NULL;
	OSoLReader *osolreader = NULL;
	OSiLWriter *osilwriter = NULL;
	OSoLWriter *osolwriter = NULL;
	OSmps2osil *mps2osil   = NULL;

#ifdef COIN_HAS_ASL
//    OSnl2os *nl2os = NULL;
    OSnl2osil *nl2osil = NULL;
#endif

#ifdef COIN_HAS_GAMSUTILS
    OSgams2os *gams2os = NULL;
#endif

    try
	{
	    fileUtil = new FileUtil();

		/** Prepare the OSInstance and OSOption objects if needed.
		 *  The objects are needed if
		 *  1. any output is based on the instance ((i.e, printModel, 
		 *     printRow or osilOutputFile is specified) OR
		 *  2. a solve/send command is based on input other than OSiL format
		 */
		if ( (oscommandline->printModel || oscommandline->printRowNumberAsString != "" || oscommandline->osilOutputFile != "") ||
			((oscommandline->serviceMethod[0] = 's') && (oscommandline->osilFile == "")))
		{
		/** Search for an instance in the following order
		 *  1. osil file
		 *  2. non-proprietary formats (only MPS for now)
		 *  3. proprietary formats (AMPL nl, GAMS dat, etc.)
		 */
			if (oscommandline->osilFile != "") 
			{
				osilreader = new OSiLReader();			
	            oscommandline->osil = fileUtil->getFileAsString(
                                  (oscommandline->osilFile).c_str());
				oscommandline->osinstance = osilreader->readOSiL(oscommandline->osil);
				if (oscommandline->osolFile != "") 
				{
		            oscommandline->osol = fileUtil->getFileAsString(
			                      (oscommandline->osolFile).c_str());
					osolreader = new OSoLReader();			
					oscommandline->osoption = osolreader->readOSoL(oscommandline->osol);
				}
			}
		    else if (oscommandline->mpsFile != "") 
			{
                mps2osil = new OSmps2osil(oscommandline->mpsFile);
                mps2osil->createOSInstance();
                oscommandline->osinstance = mps2osil->osinstance;
				if (oscommandline->osolFile != "") 
				{
		            oscommandline->osol = fileUtil->getFileAsString(
			                      (oscommandline->osolFile).c_str());
					osolreader = new OSoLReader();			
					oscommandline->osoption = osolreader->readOSoL(oscommandline->osol);
				}
			}
		    else if (oscommandline->nlFile != "")
			{
#ifdef COIN_HAS_ASL
//                nl2os = new OSnl2os(oscommandline);
//                nl2os->createOSObjects();
//                osinstance = nl2os->osinstance;
//                osoption   = nl2os->osoption;
                nl2osil = new OSnl2osil(oscommandline->nlFile);
                nl2osil->createOSInstance();
                oscommandline->osinstance = nl2osil->osinstance;
#else
                throw ErrorClass(
                    "nl file specified locally but ASL not present");
#endif
			}
		    else if (oscommandline->gamsControlFile != "")
			{
#ifdef COIN_HAS_GAMSUTILS
                gams2os = new OSgams2os(oscommandline);
                gams2os->createOSObjects();
                osinstance = gams2os->osinstance;
                osoption   = gams2os->osoption;
#else
                throw ErrorClass(
                    "a Gams Control specified locally but GAMSIP not present");
#endif
			}
			else
			{
				if (oscommandline->osolFile != "" && oscommandline->serviceLocation != "") 
				{
		            oscommandline->osol = fileUtil->getFileAsString(
                                  (oscommandline->osolFile).c_str());
					osolreader = new OSoLReader();			
					oscommandline->osoption = osolreader->readOSoL(oscommandline->osol);
					if (oscommandline->solverName != "")
						oscommandline->osoption->setSolverToInvoke(oscommandline->solverName);
				}
                if (oscommandline->osol.find( "<instanceLocation") == std::string::npos)
                    throw ErrorClass(
                        "Error: no optimization instance found");
			}

			// Make sure the solver name is recorded properly
			if (oscommandline->solverName != "") 
			{	
				if (oscommandline->osol == "" && oscommandline->osolFile != "") 
		            oscommandline->osol = fileUtil->getFileAsString(
                                  (oscommandline->osolFile).c_str());
				oscommandline->osoption->setSolverToInvoke(oscommandline->solverName);
			}	

			// convert OS objects to strings if necessary
			if (oscommandline->serviceLocation != "" && oscommandline->osil == "") 
			{	
				osilwriter= new OSiLWriter();
				oscommandline->osil = osilwriter->writeOSiL(oscommandline->osinstance);
			}	
			if (oscommandline->serviceLocation != "" && oscommandline->osoption != NULL) 
			{	
				osolwriter= new OSoLWriter();
				oscommandline->osol = osolwriter->writeOSoL(oscommandline->osoption);
			}	
		}

		// cleanup
	    if (fileUtil != NULL) delete fileUtil;
		fileUtil = NULL;
	    if (osilreader != NULL) delete osilreader;
		osilreader = NULL;
	    if (osolreader != NULL) delete osolreader;
		osolreader = NULL;
	    if (osilwriter != NULL) delete osilwriter;
		osilwriter = NULL;
	    if (osolwriter != NULL) delete osolwriter;
		osolwriter = NULL;
	    if (mps2osil != NULL) delete mps2osil;
		mps2osil = NULL;

#ifdef COIN_HAS_ASL
//	    if (nl2os != NULL) delete nl2os;
//	    nl2os = NULL;
	    if (nl2osil != NULL) delete nl2osil;
	    nl2osil = NULL;
#endif

#ifdef COIN_HAS_GAMSUTILS
	    if (gams2os != NULL) delete gams2os;
		gams2os = NULL;
#endif
	}
	catch(const ErrorClass& eclass)
	{
	    if (fileUtil != NULL) delete fileUtil;
		fileUtil = NULL;
	    if (osilreader != NULL) delete osilreader;
		osilreader = NULL;
	    if (osolreader != NULL) delete osolreader;
		osolreader = NULL;
	    if (osilwriter != NULL) delete osilwriter;
		osilwriter = NULL;
	    if (osolwriter != NULL) delete osolwriter;
		osolwriter = NULL;
	    if (mps2osil != NULL) delete mps2osil;
		mps2osil = NULL;

#ifdef COIN_HAS_ASL
	    if (nl2osil != NULL) delete nl2osil;
	    nl2osil = NULL;
#endif

#ifdef COIN_HAS_GAMSUTILS
	    if (gams2os != NULL) delete gams2os;
		gams2os = NULL;
#endif

		throw ErrorClass(eclass.errormsg);
	}
}//end nonstandard OSServiceMethods constructor

bool OSServiceMethods::executeServiceMethod(OSCommandLine *oscommandline)
{
    OSSolverAgent* osagent = NULL;
	/**
	 *  The required file conversions are all assumed 
	 *  to have been taken care of in the nonstandard constructor,
	 *  so this wrapper merely directs traffic
	 */
    try
    {
		/** the only local service method is solve() */
		if	(oscommandline->serviceLocation == "")
			if (oscommandline->serviceMethod == "solve")
				resultString = runSolver(oscommandline->solverName, oscommandline->osoption, oscommandline->osinstance);
			else
				throw ErrorClass("No service location (URL) specified. Only \"solve\" is available locally");

		/** Here we have a remote call --- reuse as much code as possible */
		else
		{
            osagent = new OSSolverAgent(oscommandline->serviceLocation);
//solve
			if (oscommandline->serviceMethod == "solve")
	            resultString = osagent->solve(oscommandline->osil, oscommandline->osol);
//send --- first check that there is a jobID. If not, get one
			else if (oscommandline->serviceMethod == "send")
			{
                if (oscommandline->osol.find( "<jobID") == std::string::npos)
				{
	                OSoLReader *osolreader = NULL;
		            osolreader = new OSoLReader();
	                OSoLWriter *osolwriter = NULL;
		            osolwriter = new OSoLWriter();
					try
					{

						if (oscommandline->osol != "")
							oscommandline->osoption = osolreader->readOSoL(oscommandline->osol);
			            oscommandline->osoption->setJobID(osagent->getJobID(""));

						// now write the osOption object into a string
				        oscommandline->osol = osolwriter->writeOSoL(oscommandline->osoption);

		                delete osolreader;
			            osolreader = NULL;
		                delete osolwriter;
			            osolwriter = NULL;
					}
					catch (const ErrorClass& eclass)
					{
						delete osolreader;
			            osolreader = NULL;
		                delete osolwriter;
			            osolwriter = NULL;
						throw ErrorClass(eclass.errormsg);
					}
				}
				bool sendResult;
				sendResult = osagent->send(oscommandline->osil, oscommandline->osol);
				if (sendResult == false)
					throw ErrorClass("send() method failed");
            }
//retrieve
			else if (oscommandline->serviceMethod == "retrieve")
			{
	            if (oscommandline->osol.find( "<jobID") == std::string::npos)
		            throw ErrorClass("there is no JobID to retrieve");
			    resultString = osagent->retrieve(oscommandline->osol);
			}
//getJobID
			else if (oscommandline->serviceMethod == "getJobID")
	            resultString = osagent->getJobID(oscommandline->osol);
//knock
			else if (oscommandline->serviceMethod == "knock")
	            resultString = osagent->knock(oscommandline->osplInput, oscommandline->osol);
//kill
			else if (oscommandline->serviceMethod == "kill")
			{
	            if (oscommandline->osol.find( "<jobID") == std::string::npos)
		            throw ErrorClass("there is no JobID to kill");
			    resultString = osagent->kill(oscommandline->osol);
			}
			else
		            throw ErrorClass("serviceMethod not recognized");

			delete osagent;
            osagent = NULL;
		}
		return true;
    }
    catch (const ErrorClass& eclass)
    {
        OSResult *osresult = NULL;
        OSrLWriter *osrlwriter = NULL;
        osrlwriter = new OSrLWriter();
        osresult = new OSResult();
        osresult->setGeneralMessage(eclass.errormsg);
        osresult->setGeneralStatusType("error");
        resultString = osrlwriter->writeOSrL(osresult);
        //catch garbage collection
        delete osresult;
        osresult = NULL;
        delete osrlwriter;
        osrlwriter = NULL;

		if (osagent != NULL) delete osagent;
            osagent = NULL;
        return false;
    }
}//executeServiceMethod


void getOSiLFromNl(OSCommandLine *oscommandline)
{
#if 0
    try
    {
#ifdef COIN_HAS_ASL
        OSnl2os *nl2os = NULL;
        nl2os = new OSnl2os(oscommandline);
        nl2os->createOSObjects();
        OSiLWriter *osilwriter = NULL;
        osilwriter = new OSiLWriter();
        oscommandline->osil = osilwriter->writeOSiL(nl2os->osinstance);
		if (nl2os->osoption != NULL)
		{
	        OSoLWriter *osolwriter = NULL;
		    osolwriter = new OSoLWriter();
			oscommandline->osol = osolwriter->writeOSoL(nl2os->osoption);
	        delete osolwriter;
		    osolwriter = NULL;
		}
        delete nl2os;
        nl2os = NULL;
        delete osilwriter;
        osilwriter = NULL;
#else
        throw ErrorClass(
            "trying to convert nl to osil without AMPL ASL configured");
#endif
    }
    catch (const ErrorClass& eclass)
    {
        std::cout << eclass.errormsg << std::endl;
        throw ErrorClass(eclass.errormsg);
    }
#endif
}//getOSiLFromNl


void getOSiLFromGams(OSCommandLine *oscommandline)
{
    try
    {
#ifdef COIN_HAS_GAMSIO
        OSgams2os *gams2os = NULL;
        gams2os = new OSgams2os(oscommandline);
        gams2os->createOSObjects();
        OSiLWriter *osilwriter = NULL;
        osilwriter = new OSiLWriter();
        oscommandline->osil = osilwriter->writeOSiL(gams2os->osinstance);
		if (gams2os->osoption != NULL)
		{
	        OSoLWriter *osolwriter = NULL;
		    osolwriter = new OSoLWriter();
			oscommandline->osol = osolwriter->writeOSoL(gams2os->osoption);
	        delete osolwriter;
		    osolwriter = NULL;
		}
        delete gams2os;
        gams2os = NULL;
        delete osilwriter;
        osilwriter = NULL;
#else
        throw ErrorClass(
            "trying to convert Gams control file to osil without GAMSUTILS configured");
#endif
    }
    catch (const ErrorClass& eclass)
    {
        std::cout << eclass.errormsg << std::endl;
        throw ErrorClass(eclass.errormsg);
    }
}//getOSiLFromGams


void getOSiLFromMps(OSCommandLine *oscommandline)
{
    try
    {
        OSmps2osil *mps2osil = NULL;
        mps2osil = new OSmps2osil(oscommandline->mpsFile);
        mps2osil->createOSInstance();
        OSiLWriter *osilwriter = NULL;
        osilwriter = new OSiLWriter();
        oscommandline->osil = osilwriter->writeOSiL(mps2osil->osinstance);
        delete mps2osil;
        mps2osil = NULL;
        delete osilwriter;
        osilwriter = NULL;
    }
    catch (const ErrorClass& eclass)
    {
        std::cout << eclass.errormsg << std::endl;
        throw ErrorClass(eclass.errormsg);
    }

}//getOSiLFromMps


