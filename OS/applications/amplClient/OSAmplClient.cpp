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
 * to solve a problem locally, start AMPL. Let's assume that the model is
 * hs71.mod. Execute the following sequence of commands:
 *
 * model hs71.mod;  <br />
 * option solver OSAmplClient; <br />
 * option OSAmplClient_options "-solver bonmin"; <br />
 * write gtestfile; <br />
 * solve; <br />
 * display x1; <br />
 * you should get:
 *
 * x1 = 1
 *
 * display x2;  <br />
 * you should get:
 *
 * x2 = 4.743
 *
 * in general, specify options to the OSAmplClient solver by using the AMPL command OSAmplClient_options
 * as another example, if you wanted to solve hs71.mod on a remote server you would do:
 * model hs71.mod;  <br />
 * option solver OSAmplClient; <br />
 * option OSAmplClient_options "-serviceLocation http://gsbkip.chicagogsb.edu/os/OSSolverService.jws"; <br />
 *
 *
 * \item there are three possible options to specify:
 *
 * \begin{itemize}
 *
 * \item the name of the solver using the  {\bf -solver} option, valid values for this option  are {\tt clp},
 * {\tt cbc},  {\tt dylp},  {\tt ipopt}, {\tt bonmin},   {\tt couenne},  {\tt symphony}, and {\tt vol}.
 *
 *
 * \item the location of the remote server using the {\bf -serviceLocation} option
 *
 * \item the location of the option file using  the {\bf -osol} option
 *
 * \end{itemize}
 *
 * if no options are specified using {\bf OSAmplClient\_options},   by default,for continuous
 * linear models  clp is used. For continuous nonlinear models ipopt is used.
 * For mixed-integer linear models (MIP), cbc is used. For mixed-integer nonlinear models
 * bonmin is used.  All solvers are invoked locally. See the Users Manual in the doc folder
 * for more information
 *
 */

#include "OSCoinSolver.h"
#include "OSConfig.h"
#include "OSnl2OS.h"
#include "OSiLReader.h"
#include "OSrLReader.h"
#include "OSiLWriter.h"
#include "OSrLWriter.h"
#include "OSInstance.h"
#include "OSResult.h"
#include "OSOption.h"
#include "OSoLReader.h"
#include "OSoLWriter.h"

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
#include "OSOptionsStruc.h"
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




#define MAXCHARS 5000

typedef struct yy_buffer_state *YY_BUFFER_STATE;
YY_BUFFER_STATE osss_scan_string(const char* osss, void* scanner );
//void osssset_extra (YY_EXTRA_TYPE user_defined ,yyscan_t yyscanner );
void setyyextra(osOptionsStruc *osoptions, void* scanner);
int ossslex(void* scanner );
int ossslex_init(void** ptr);
int ossslex_destroy (void* scanner );


using std::cerr;
using std::cout;
using std::endl;
using std::ostringstream;

void getAmplClientOptions(char *options, std::string *solverName,
                          std::string *optionFile, std::string *serviceLocation);





int main(int argc, char **argv)
{
    WindowsErrorPopupBlocker();
    char *stub;

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
    std::string osol = "";
    std::string serviceLocation = "";
    std::string nlfile = "";

//    cout << "Here is the command line:";
//    for (int i=0; i<argc; i++) cout << " " << argv[i];
//    cout << endl;

    amplclient_options = getenv("OSAmplClient_options");
    if( amplclient_options != NULL)
    {
        cout << "HERE ARE THE AMPLCLIENT OPTIONS " <<   amplclient_options << endl;
        getAmplClientOptions(amplclient_options, &sSolverName, &osolFileName, &serviceLocation);
    }

    // set AMPL structures
    ASL *asl;
    asl = ASL_alloc(ASL_read_fg);
    stub = argv[1];
    jac0dim((char*)stub, (fint)strlen(stub));


    //convert solver name to lower case for testing purposes

    unsigned int k;
    for(k = 0; k < sSolverName.length(); k++)
    {
        sSolverName[ k] = tolower( sSolverName[ k]);
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


    OSnl2OS *nl2OS = NULL;
    //initialize object with stub -- the nl file --- and the OSoL file --- if any
    nl2OS = new OSnl2OS( stub, osol);
    std::cout << " call nl2OS" << std::endl;

    /*	Parse the .nl file to create an in-memory representation
    	in form of an OSInstance object
     */
    try
    {
        nl2OS->createOSObjects() ;
    }
    catch(const ErrorClass& eclass)
    {
        std::cout << eclass.errormsg << std::endl;
        return 0;
    }
    std::cout << " return from  nl2OS" << std::endl;

    // create OS objects
    OSInstance *osinstance;
    OSOption   *osoption;

    osinstance = nl2OS->osinstance;
    std::cout << " osinstance created" << std::endl;

    //write out the instance
    OSiLWriter *osilwriter = NULL;
    osilwriter = new OSiLWriter();
    osilwriter->m_bWhiteSpace = true;
    std::string sModelInstanceName = "modelInstance.osil";
    FileUtil *fileUtil;
    fileUtil = new FileUtil();
    fileUtil->writeFileFromString(sModelInstanceName,  osilwriter->writeOSiL( osinstance) );
    delete fileUtil;
    fileUtil = NULL;
    delete  osilwriter;
    osilwriter = NULL;
    //

    if (nl2OS->osoption != NULL)
    {
        osoption   = nl2OS->osoption;
        //write out the options
        OSoLWriter *osolwriter = NULL;
        osolwriter = new OSoLWriter();
        //osolwriter->m_bWhiteSpace = true;
        std::string sModelOptionName = "modelOptions.osol";
        fileUtil = new FileUtil();
        fileUtil->writeFileFromString(sModelOptionName,  osolwriter->writeOSoL( osoption) );
        delete fileUtil;
        fileUtil = NULL;
        delete  osolwriter;
        osolwriter = NULL;
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

            // return all solution results that are indexed over variables or constraints as suffixes
// taken from Ipopt - AmplTNLP.cpp:
//    Number* z_L_sol_;
//            suf_rput("ipopt_zL_out", ASL_Sufkind_var,  z_L_sol_);

            write_sol(  const_cast<char*>(sReport.c_str()),  x, y , NULL);

            delete osrlreader;
            osrlreader = NULL;
            //delete[] x;
            //x = NULL;
            //delete y;
            //y = NULL;
        }
        else // there was an error
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
    delete nl2OS;
    //cout << "nl2osil JUST DELETED" <<endl;
    nl2OS = NULL;
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
