/** @file OSAmplClient.cpp
 *
 * @author  Robert Fourer, Horand Gassmann, Jun Ma, Kipp Martin
 *
 * \remarks
 * Copyright (C) 2005-2012, Robert Fourer, Horand Gassmann, Jun Ma, Kipp Martin,
 * Northwestern University, Dalhousie University and the University of Chicago.
 * All Rights Reserved.
 * This software is licensed under the Eclipse Public License.
 * Please see the accompanying LICENSE file in OS root directory for terms.
 *
 * This executable is designed to act as a "solver" for AMPL. It can be
 * used to solve problems locally or on a remote server.  For example,
 * to solve a problem locally, start AMPL. We assume that the model is
 * hs71.mod. Execute the following sequence of commands:
 *
 * model hs71.mod; 
 * option solver OSAmplClient; 
 * option OSAmplClient_options "-solver bonmin"; 
 * write gtestfile; 
 * solve; 
 * display x1; 
 *
 * you should get:
 *
 * x1 = 1
 *
 * display x2;  
 *
 * you should get:
 *
 * x2 = 4.743
 *
 * in general, specify options to the OSAmplclient solver
 * by using the AMPL command OSAmplClient_options
 * 
 * as another example, if you wanted to solve hs71.mod
 * on a remote server you would do:
 * 
 * model hs71.mod;
 * option solver OSAmplClient;
 * option OSAmplClient_options "-serviceLocation http://gsbkip.chicagogsb.edu/os/OSSolverService.jws";
 *
 *
 * there are three possible options to specify:
 *
 *    the name of the solver using the  -solver option, 
 *       valid values for this option normally include
 *       clp, cbc, dylp, ipopt, bonmin, couenne, symphony, and vol.
 *
 *    the location of the remote server using the -serviceLocation option
 *
 *    the location of the option file using  the -osol option
 *
 * if no options are specified using OSAmplClient_options,   
 * the default for continuous linear models is clp;
 * for continuous nonlinear models ipopt is used;
 * for mixed-integer linear models (MIP), cbc is used;
 * for mixed-integer nonlinear models bonmin is used.  
 * All solvers are invoked locally. 
 * See the Users Manual in the doc folder for more information
 *
 */

#include "OSCoinSolver.h"
#include "OSConfig.h"
#include "OSnl2osil.h"
#include "OSiLReader.h"
#include "OSrLReader.h"
#include "OSiLWriter.h"
#include "OSrLWriter.h"
#include "OSInstance.h"
#include "OSResult.h"
#include "OSOption.h"
#include "OSoLReader.h"
#include "OSoLWriter.h"
#include "OSCommandLine.h"
#include "OSCommandLineReader.h"
#include "OSServiceMethods.h"

#ifdef COIN_HAS_LINDO
# include "OSLindoSolver.h"
#endif

#ifdef COIN_HAS_IPOPT
# include "OSIpoptSolver.h"
#endif

#ifdef COIN_HAS_BONMIN
# include "OSBonminSolver.h"
#endif

#ifdef COIN_HAS_COUENNE
# include "OSCouenneSolver.h"
#endif

#include "OSFileUtil.h"
#include "OSDefaultSolver.h"
#include "OSSolverAgent.h"
#include "OShL.h"
#include "OSErrorClass.h"
#include "CoinError.hpp"
#include "OSOption.h"
//#include "OSOptionsStruc.h"
#include "OSRunSolver.h"
#include <sstream>

#ifdef HAVE_CSTRING
# include <cstring>
#else
# ifdef HAVE_STRING_H
#  include <string.h>
# else
#  error "don't have header file for string"
# endif
#endif

#include "CoinError.hpp"
#include "CoinHelperFunctions.hpp"


#include <iostream>

//AMPL includes must be last.
#include <asl.h>


//#define DEBUG_AMPL_CLIENT


using std::cerr;
using std::cout;
using std::endl;
using std::ostringstream;

std::string OSAmplClientVersionInfo();
std::string get_AmplClient_help();
bool callServiceMethod(OSCommandLine* oscommandline);

int main(int argc, char **argv)
{
    WindowsErrorPopupBlocker();
    char *stub;
    // set AMPL structures
    ASL *asl;
    asl = ASL_alloc(ASL_read_fg);
    stub = argv[1];
    jac0dim((char*)stub, (fint)strlen(stub));
    OSnl2osil *nl2osil = NULL;

    std::ostringstream outStr;
	std::cout << OSAmplClientVersionInfo();
	std::string osss;

	outStr << stub << " " << getenv("OSAmplClient_options");
    osss = outStr.str();

#ifdef DEBUG_AMPL_CLIENT
    std::cout << "Input String = " << osss << std::endl;
#endif

	FileUtil *fileUtil = NULL;
	OSCommandLine *oscommandline;
	oscommandline = new OSCommandLine();
	OSCommandLineReader *clreader;
	clreader = new OSCommandLineReader();

	//parse the command line items into a CommandLine object
    try
    {		
		oscommandline = clreader->readCommandLine(osss);
		if (oscommandline->serviceMethod == "")
			oscommandline->serviceMethod = "solve";
		oscommandline->convertSolverNametoLowerCase();

	}
    catch (const ErrorClass& eclass)
    {
        OSResult *osresult = NULL;
        osresult = new OSResult();
        osresult->setGeneralMessage(eclass.errormsg);
        osresult->setGeneralStatusType("error");
        OSrLWriter *osrlwriter = NULL;
        osrlwriter = new OSrLWriter();
        std::string osrl = osrlwriter->writeOSrL(osresult);
        if (oscommandline->osrlFile != "")
        {
            fileUtil->writeFileFromString(oscommandline->osrlFile, osrl);
            if (oscommandline->browser != "")
            {
                std::string str = oscommandline->browser + "  "
                                  + oscommandline->osrlFile;
                const char *ch = &str[0];
                std::system(ch);
            }
        }
        else
        {
            std::cout << osrl << std::endl;
        }
        //catch garbage collection
        delete osresult;
        osresult = NULL;
        delete osrlwriter;
        osrlwriter = NULL;
        delete fileUtil;
        fileUtil = NULL;
        delete oscommandline;
        oscommandline = NULL;
        delete clreader;
        clreader = NULL;
        return 1;
    }

#ifdef DEBUG_AMPL_CLIENT
	std::cout << oscommandline->list_options() << std::endl;
#endif

	// deal with "action items": help, quit, listOptions
	if (oscommandline->quit || oscommandline->invokeHelp || oscommandline->writeVersion || oscommandline->listOptions)
	{
		if (oscommandline->invokeHelp) 
			std::cout << std::endl << std::endl << get_AmplClient_help() << std::endl;
		if (oscommandline->listOptions) 
			std::cout << std::endl << std::endl << oscommandline->list_options() << std::endl;
        delete oscommandline;
        oscommandline = NULL;
        return 0;
	}

	// call service method
	bool result = callServiceMethod(oscommandline);
	if (result == true)
		return 0;
	else
		return 1;
}

bool callServiceMethod(OSCommandLine* oscommandline)
{
	FileUtil *fileUtil = new FileUtil();
	try
    {
		bool result;
		OSServiceMethods *osservicemethods;
		osservicemethods = new OSServiceMethods(oscommandline);

		if (oscommandline->printModel) 
			oscommandline->osinstance->printModel();
		if (oscommandline->printRowNumberAsString != "")
			oscommandline->osinstance->printModel(atoi((oscommandline->printRowNumberAsString).c_str()));

		result = osservicemethods->executeServiceMethod(oscommandline);

		// deal with the output
		if (result == false) 
			throw ErrorClass(osservicemethods->resultString);
		else
		{
			if (oscommandline->serviceMethod == "getJobID")
			{
				std::cout << "The job ID generated by the system is:" << std::endl << std::endl;
				std::cout << osservicemethods->resultString << std::endl << std::endl;
				std::cout << "Be sure to make a record of this job ID for later." << std::endl;
				std::cout << "You will need it to retrieve the job or inquire into its status." << std::endl;
			}
			else if (oscommandline->serviceMethod == "solve" || oscommandline->serviceMethod == "retrieve")
			{
		        if (oscommandline->osrlFile != "")
				{
		            fileUtil->writeFileFromString(oscommandline->osrlFile, osservicemethods->resultString);
					if (oscommandline->browser != "")
					{
			            std::string str = oscommandline->browser + "  "
					                      + oscommandline->osrlFile;
		                const char *ch = &str[0];
				        std::system(ch);
		            }
                    std::cout <<  "\nSolve command executed. Please see " << oscommandline->osrlFile  << " for results." << std::endl;
				}
		        else
				{
		            std::cout << osservicemethods->resultString << std::endl;
				}
			}
			else if (oscommandline->serviceMethod == "kill" || oscommandline->serviceMethod == "knock")
			{
		        if (oscommandline->osplOutputFile != "")
				{
		            fileUtil->writeFileFromString(oscommandline->osplOutputFile, osservicemethods->resultString);
				}
		        else
				{
		            std::cout << osservicemethods->resultString << std::endl;
				}
			}
		}
		return 0;
    }
    catch (const ErrorClass& eclass)
    {
        OSResult *osresult = NULL;
        OSrLWriter *osrlwriter = NULL;
        osrlwriter = new OSrLWriter();
        osresult = new OSResult();
        osresult->setGeneralMessage(eclass.errormsg);
        osresult->setGeneralStatusType("error");
        std::string osrl = osrlwriter->writeOSrL(osresult);
        if (oscommandline->osrlFile != "")
        {
            fileUtil->writeFileFromString(oscommandline->osrlFile, osrl);
            if (oscommandline->browser != "")
            {
                std::string str = oscommandline->browser + "  "
                                  + oscommandline->osrlFile;
                const char *ch = &str[0];
                std::system(ch);
            }
        }
        else
        {
            std::cout << osrl << std::endl;
        }
        //catch garbage collection
        delete osresult;
        osresult = NULL;
        delete osrlwriter;
        osrlwriter = NULL;

        delete oscommandline;
        oscommandline = NULL;
        delete fileUtil;
        fileUtil = NULL;
        return 1;
    }
}

std::string get_AmplClient_help()
{

    std::ostringstream helpMsg;

    helpMsg << "************************* HELP *************************"
            << endl << endl;
    helpMsg
            << "In this HELP file we assume that the solve service method is used and "
            << endl;
    helpMsg
            << "that we are solving problems locally, that is the solver is on the "
            << endl;
    helpMsg
            << "machine running this OSSolverService.  See Section 10.3 of the User\'s  "
            << endl;
    helpMsg
            << "Manual for other service methods or calling a server remotely. "
            << endl;
    helpMsg << "The OSSolverService takes the parameters listed below.  "
            << endl;
    helpMsg
            << "The order of the parameters is irrelevant.  Not all the parameters  "
            << endl;
    helpMsg << "are required.  However, the location of an instance file is  "
            << endl;
    helpMsg
            << "required when using the solve service method. The location of the "
            << endl;
    helpMsg << "instance file is specified using the osil option. " << endl;

    helpMsg << endl;

    helpMsg
            << "-osil xxx.osil this is the name of the file that contains the  "
            << endl;
    helpMsg << "optimization instance in OSiL format.  This option may be  "
            << endl;
    helpMsg << "specified in the OSoL solver options file. " << endl;

    helpMsg << endl;

    helpMsg
            << "-osol xxx.osol  this is the name of the file that contains the solver options.   "
            << endl;
    helpMsg << "It is not necessary to specify this option. " << endl;

    helpMsg << endl;

    helpMsg
            << "-osrl xxx.osrl  this is the name of the file to which the solver solution is written.  "
            << endl;
    helpMsg
            << "It is not necessary to specify this option. If this option is not specified,  "
            << endl;
    helpMsg << "the result will be printed to standard out.  " << endl;

    helpMsg << endl;

    helpMsg
            << "-osplInput xxx.ospl  this is the name of an input file in the OS Process"
            << endl;
    helpMsg << " Language (OSpL), this is used as input  to the knock method."
            << endl;

    helpMsg << endl;

    helpMsg
            << "-osplOutput xxx.ospl this is the name of an output file in the  OS Process"
            << endl;
    helpMsg
            << "Language (OSpL), this the output string from the knock and kill methods."
            << endl;

    helpMsg << endl;

    helpMsg << "-serviceLocation url is the URL of the solver service.  "
            << endl;
    helpMsg
            << "This is not required, and if not specified it is assumed that   "
            << endl;
    helpMsg << "the problem is solved locally.  " << endl;

    helpMsg << endl;

    helpMsg
            << "-serviceMethod  methodName this is the method on the solver service to be invoked.  "
            << endl;
    helpMsg
            << "The options are  solve,  send,  kill,  knock,  getJobID, and retrieve.   "
            << endl;
    helpMsg
            << "This option is not required, and the default value is  solve.  "
            << endl;

    helpMsg << endl;

    helpMsg
            << "-mps  xxx.mps  this is the name of the mps file if the problem instance  "
            << endl;
    helpMsg
            << "is in mps format. The default file format is OSiL so this option is not required.  "
            << endl;

    helpMsg << endl;

    helpMsg
            << "-nl  xxx.nl  this is the name of the AMPL nl file if the problem  "
            << endl;
    helpMsg
            << "instance is in AMPL nl  format. The default file format is OSiL  "
            << endl;
    helpMsg << "so this option is not required.  " << endl;

    helpMsg << endl;

    helpMsg
            << "-solver  solverName  Possible values for default OS installation  "
            << endl;
    helpMsg
            << "are  bonmin(COIN-OR Bonmin), couenne (COIN-OR Couenne), clp (COIN-OR Clp),"
            << endl;
    helpMsg << "cbc (COIN-OR Cbc), dylp (COIN-OR DyLP), ipopt (COIN-OR Ipopt),"
            << endl;
    helpMsg << "and symphony (COIN-OR SYMPHONY). Other solvers supported"
            << endl;
    helpMsg
            << "(if the necessary libraries are present) are cplex (Cplex through COIN-OR Osi),"
            << endl;
    helpMsg
            << "glpk (glpk through COIN-OR Osi), knitro (Knitro), and lindo (LINDO)."
            << endl;
    helpMsg << "If no value is specified for this parameter," << endl;
    helpMsg << "then cbc is the default value of this parameter." << endl;

    helpMsg << endl;

    helpMsg
            << "-browser  browserName this paramater is a path to the browser on the  "
            << endl;
    helpMsg
            << "local machine. If this optional parameter is specified then the  "
            << endl;
    helpMsg << "solver result in OSrL format is transformed using XSLT into  "
            << endl;
    helpMsg << "HTML and displayed in the browser.  " << endl;

    helpMsg << endl;

    helpMsg
            << "-config pathToConfigureFile this parameter specifies a path on  "
            << endl;
    helpMsg
            << "the local machine to a text file containing values for the input parameters.  "
            << endl;
    helpMsg
            << "This is convenient for the user not wishing to constantly retype parameter values.  "
            << endl;
    helpMsg
            << "This configure file can contain values for all of the other parameters. "
            << endl;

    helpMsg << endl;

    helpMsg << "--version or -v get the current version of this executable  "
            << endl;

    helpMsg << endl;

    helpMsg << "--help or -h  to get this help file " << endl;

    helpMsg << endl;

    helpMsg
            << "Note: If you specify a configure file by using the -config option, you can  "
            << endl;
    helpMsg
            << "override the values of the options in the configure file by putting them in   "
            << endl;
    helpMsg << "at the command line. " << endl << endl;

    helpMsg
            << "See the OS User\' Manual: http://www.coin-or.org/OS/doc/osUsersManual.pdf"
            << endl;
    helpMsg << "for more detail on how to use the OS project. " << endl;

    helpMsg << endl;
    helpMsg << "********************************************************"
            << endl << endl;

    return helpMsg.str();
}// get help


std::string OSAmplClientVersionInfo()
{
    std::ostringstream versionMsg;
    versionMsg << "In order to find the version of this project " << endl;
    versionMsg << "connect to the directory where you downloaded " << endl;
    versionMsg << "and do: " << endl;
    versionMsg << "svn info " << endl;

    return versionMsg.str();
}// get OSAmplClientVersionInfo

#if 0
    //initialize object with stub -- the nl file
    nl2osil = new OSnl2osil( stub);
    // create an osinstance object
    OSInstance *osinstance;
    std::cout << " call nl2osil" << std::endl;

    /*	Parse the .nl file to create an in-memory representation
    	in form of an OSInstance object
     */
    try
    {
        nl2osil->createOSInstance() ;
    }
    catch(const ErrorClass& eclass)
    {
        std::cout << eclass.errormsg << std::endl;
        return 0;
    }
    std::cout << " return from  nl2osil" << std::endl;
    osinstance = nl2osil->osinstance;
    std::cout << " osinstance created" << std::endl;
    //write out the instance
    //kippster
    OSiLWriter *osilwriter = NULL;
    osilwriter = new OSiLWriter();
    osilwriter->m_bWhiteSpace = true;
    std::string sModeInstanceName = "modelInstance.osil";
    FileUtil *fileUtil;
    fileUtil = new FileUtil();
    fileUtil->writeFileFromString(sModeInstanceName,  osilwriter->writeOSiL( osinstance) );
    delete fileUtil;
    fileUtil = NULL;
    delete  osilwriter;
    osilwriter = NULL;
    //

    /*	Parse the options (passed through ASL as the string OSAmplClient_options)
     *
     *	There are three possible options:
     *	1. solver:
     *		possible values - name of a supported solver (installation-dependent)
     *  2. serviceLocation:
     *		possible values - NULL (empty) or URL of the solver service
     *	3. optionFile:
     *		specify the location of the OSoL file (on the local system)
     *
     */
    char *amplclient_options = NULL;
    DefaultSolver *solverType  = NULL;
    std::string sSolverName = "";
    std::string osolFileName = "";
    std::string osol ="";
    std::string serviceLocation = "";
    osOptionsStruc *osoptions;

    amplclient_options = getenv("OSAmplClient_options");
    if( amplclient_options != NULL)
    {
        cout << "HERE ARE THE AMPLCLIENT OPTIONS " <<   amplclient_options << endl;
        //getAmplClientOptions(amplclient_options, &sSolverName, &osolFileName, &serviceLocation);
        osoptions = new osOptionsStruc(amplclient_options);
    }

    /* If an OSoL file was given, read it into a string (don't parse)
     */
    if(osolFileName.size() > 0)
    {
        FileUtil *fileUtil;
        fileUtil = new FileUtil();
        osol = fileUtil->getFileAsString( osolFileName.c_str() );
        delete fileUtil;
    }
    //std::cout << " solver Name = " << sSolverName << std::endl;
    //std::cout << " solver Options = " << osol << std::endl;

    //convert solver name to lower case for testing purposes

    unsigned int k;
    for(k = 0; k < sSolverName.length(); k++)
    {
        sSolverName[ k] = tolower( sSolverName[ k]);
    }


    OSrLReader *osrlreader = NULL;
    OSrLWriter *osrlwriter;
    osrlwriter = new OSrLWriter();
    OSResult *osresult = NULL;
    std::string osrl = "";


    try
    {
        if(serviceLocation.size() == 0 )
        {
            //determine the solver
            osrl = runSolver(sSolverName, osol, osinstance);
        }// end if serviceLocation.size() == 0

        /* ------------------------------------------------------- */
        else // do a remote solve
        {
            OSSolverAgent* osagent = NULL;
            OSiLWriter *osilwriter = NULL;
            osilwriter = new OSiLWriter();
            std::string  osil = osilwriter->writeOSiL( osinstance);
            ////

            //agent_address = strstr(solver_option, "service");
            //agent_address += 7;
            //URL = strtok( agent_address, delims );
            //std::string sURL = URL;
            ///
            // we should be pointing to the start of the address
            osagent = new OSSolverAgent( serviceLocation);
            cout << "Place remote synchronous call: " + serviceLocation << endl << endl << endl;
            //cout << osol << endl;
            osrl = osagent->solve(osil, osol);
            if (osrl.size() == 0) throw ErrorClass("Nothing was returned from the server, please check service address");
            delete osilwriter;
            delete osagent;
        }
    }//end try
    catch(const ErrorClass& eclass)
    {
        osresult = new OSResult();
        osresult->setGeneralMessage( eclass.errormsg);
        osresult->setGeneralStatusType( "error");
        osrl = osrlwriter->writeOSrL( osresult);
        std::cout  << osrl << std::endl;
        osrl = " ";
        write_sol(const_cast<char*>(osrl.c_str()), NULL, NULL, NULL);
        delete osresult;
        return 0;
    }

    try  // now put solution back to ampl
    {
        //need_nl = 0;
        std::string sResultFileName = "solutionResult.osrl";
        FileUtil *fileUtil;
        fileUtil = new FileUtil();
        fileUtil->writeFileFromString(sResultFileName, osrl);
        delete fileUtil;
        //cout << "WRITE THE SOLUTION BACK INTO AMPL" <<endl;
        std::string::size_type pos1 = osrl.find( "error");
        if(pos1 == std::string::npos)
        {
            std::string sReport = "model was solved";
            std::cout << sReport << std::endl;
            //std::cout << osrl << std::endl;
            osrlreader = new OSrLReader();
            osresult = osrlreader->readOSrL( osrl);
            // do the following so output is not written twice
            // see page 23 of hooking solver to AMPL
            //need_nl = printf( sReport.c_str());

            //
            sReport = " ";
            int i;
            int vecSize;
            double *x;
            double *y;
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



            write_sol(  const_cast<char*>(sReport.c_str()),  x, y , NULL);

            delete osrlreader;
            osrlreader = NULL;
            //delete[] x;
            //x = NULL;
            //delete y;
            //y = NULL;
        }
        else
        {
            // do the following so output is not written twice
            // see page 23 of hooking solver to AMPL
            std::cout  << osrl << std::endl;
            osrl = " ";
            //
            write_sol(  const_cast<char*>(osrl.c_str()), NULL, NULL, NULL);
            need_nl = 0;
        }
        //cout << "DONE WRITING THE SOLUTION BACK INTO AMPL" <<endl;
    }
    catch(const ErrorClass& eclass)
    {
        cout << "There was an error parsing the OSrL" << endl << eclass.errormsg << endl << endl;
    }
    if(  solverType != NULL )
    {
        //cout << "TRY TO DELETE solverType" <<endl;
        delete solverType;
        //cout << "solverType JUST DELETED" <<endl;
        solverType = NULL;
    }
    delete osrlwriter;
    //cout << "osrlwriter JUST DELETED" <<endl;
    osrlwriter = NULL;
    delete nl2osil;
    //cout << "nl2osil JUST DELETED" <<endl;
    nl2osil = NULL;
    ASL_free(&asl);
    return 0;
} // end main




void getAmplClientOptions(char *amplclient_options, std::string *solverName,
                          std::string *solverOptions, std::string *serviceLocation)
{

    osOptionsStruc *osoptions;

    void* scanner;
    // initialize the OS options structure

    osoptions = new osOptionsStruc();
    osoptions->configFile = "";
    osoptions->osilFile = "";
    osoptions->osil = "";
    osoptions->osolFile = "";
    osoptions->osol = "";
    osoptions->osrlFile = "";
    osoptions->osrl = "";
    //osoptions->insListFile = "";
    osoptions->insList = "";
    osoptions->serviceLocation = "";
    osoptions->serviceMethod = "";
    osoptions->osplInputFile = "";
    osoptions->osplOutputFile = "";
    osoptions->mpsFile = "";
    osoptions->nlFile = "";
    osoptions->gamsControlFile = "";
    osoptions->solverName = "";
    osoptions->browser = "";
    osoptions->invokeHelp = false;
    osoptions->writeVersion = false;
    try
    {
        //cout << "Input String = "  << amplclient_options << endl;
        ossslex_init( &scanner);
        //std::cout << "Call Text Extra" << std::endl;
        setyyextra( osoptions, scanner);
        //std::cout << "Call scan string " << std::endl;
        osss_scan_string( amplclient_options, scanner);
        //std::cout << "call ossslex" << std::endl;
        ossslex( scanner);
        ossslex_destroy( scanner);
        //std::cout << "done with call to ossslex" << std::endl;
//
//		cout << "HERE ARE THE OPTION VALUES:" << endl;
//		if(osoptions->configFile != "") cout << "Config file = " << osoptions->configFile << endl;
//		if(osoptions->osilFile != "") cout << "OSiL file = " << osoptions->osilFile << endl;
//		if(osoptions->osolFile != "") cout << "OSoL file = " << osoptions->osolFile << endl;
//		if(osoptions->osrlFile != "") cout << "OSrL file = " << osoptions->osrlFile << endl;
//		//if(osoptions->insListFile != "") cout << "Instruction List file = " << osoptions->insListFile << endl;
//		if(osoptions->osplInputFile != "") cout << "OSpL Input file = " << osoptions->osplInputFile << endl;
//		if(osoptions->serviceMethod != "") cout << "Service Method = " << osoptions->serviceMethod << endl;
//		if(osoptions->mpsFile != "") cout << "MPS File Name = " << osoptions->mpsFile << endl;
//		if(osoptions->nlFile != "") cout << "NL File Name = " << osoptions->nlFile << endl;
//		if(osoptions->gamsControlFile != "") cout << "gams Control File Name = " << osoptions->gamsControlFile << endl;
//		if(osoptions->browser != "") cout << "Browser Value = " << osoptions->browser << endl;
//		if(osoptions->solverName != "") cout << "Selected Solver = " << osoptions->solverName << endl;
//		if(osoptions->serviceLocation != "") cout << "Service Location = " << osoptions->serviceLocation << endl;
//

        *solverName = osoptions->solverName;
        *solverOptions = osoptions->osolFile;

        *serviceLocation = osoptions->serviceLocation;

    }//end try
    catch(const ErrorClass& eclass)
    {
        cout << "There was an error processing OSAmplClient options: " << endl << eclass.errormsg << endl << endl;
        throw ErrorClass( eclass.errormsg) ;
    }
}//getAmplClientOptions
#endif
