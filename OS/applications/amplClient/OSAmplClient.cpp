/** @file OSAmplClient.cpp
 *
 * @author  Robert Fourer, Horand Gassmann, Jun Ma, Kipp Martin
 *
 * \remarks
 * Copyright (C) 2005-2012, Robert Fourer, Horand Gassmann, Jun Ma, Kipp Martin,
 * Northwestern University, and the University of Chicago.
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

#include "OSConfig.h"
#include "OSnl2OS.h"
#include "OSosrl2ampl.h"
#include "OSiLReader.h"
#include "OSiLWriter.h"
#include "OSoLReader.h"
#include "OSoLWriter.h"
#include "OSrLReader.h"
#include "OSrLWriter.h"
#include "OSInstance.h"
#include "OSOption.h"
#include "OSResult.h"
#include "OSOutput.h"

#include "OSDefaultSolver.h"
#include "OSCoinSolver.h"

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
#include "OSSolverAgent.h"
#include "OShL.h"
#include "OSErrorClass.h"
#include "CoinError.hpp"
#include "OSCommandLine.h"
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
void setyyextra(OSCommandLine *oscommandline, void* scanner);
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
    std::ostringstream outStr;

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

#ifndef NDEBUG
    outStr.str("");
    outStr.clear();
    outStr << "Here is the command line:";
    for (int i=0; i<argc; i++) outStr << " " << argv[i];
    outStr << endl;
    osoutput->OSPrint(ENUM_OUTPUT_AREA_main, ENUM_OUTPUT_LEVEL_debug, outStr.str());
#endif

    stub = argv[1];

    amplclient_options = getenv("OSAmplClient_options");
    if( amplclient_options != NULL)
    {
        outStr.str("");
        outStr.clear();
        outStr << "HERE ARE THE AMPLCLIENT OPTIONS " <<   amplclient_options << endl;
        osoutput->OSPrint(ENUM_OUTPUT_AREA_main, ENUM_OUTPUT_LEVEL_info, outStr.str());
        getAmplClientOptions(amplclient_options, &sSolverName, &osolFileName, &serviceLocation);
    }

    //convert solver name to lower case for testing purposes

    unsigned int k;
    for(k = 0; k < sSolverName.length(); k++)
    {
        sSolverName[ k] = tolower( sSolverName[ k]);
    }
    //std::cout << " solver Name = " << sSolverName << std::endl;

    /* If an OSoL file was given, read it into a string (don't parse)  */
    if(osolFileName.size() > 0)
    {
        FileUtil *fileUtil;
        fileUtil = new FileUtil();
        osol = fileUtil->getFileAsString( osolFileName.c_str() );
        delete fileUtil;
    }
    //std::cout << " solver Options = " << osol << std::endl;

    // set AMPL structures: cw for column-wise representation, rw for row-wise; asl to switch between them
    ASL *cw, *rw, *asl;
    cw = ASL_alloc(ASL_read_fg);
    rw = ASL_alloc(ASL_read_fg);
    asl = cw;

    jac0dim((char*)stub, (fint)strlen(stub));

    OSnl2OS *nl2OS = new OSnl2OS(cw, rw, asl);
    //std::cout << " call nl2OS" << std::endl;


    /** Read and parse the .nl file and the osol string
     *  to create an in-memory representation
     *  in form of an OSInstance and an OSOption object
     */
    try
    {
        nl2OS->readNl(stub);
        nl2OS->setOsol(osol);
        nl2OS->createOSObjects() ;
    }
    catch(const ErrorClass& eclass)
    {
        outStr.str("");
        outStr.clear();
        outStr << "Error detected: " << eclass.errormsg << std::endl;
        osoutput->OSPrint(ENUM_OUTPUT_AREA_main, ENUM_OUTPUT_LEVEL_error, outStr.str());
        return 0;
    }
    //std::cout << " return from  nl2OS" << std::endl;

    // create OS objects
    OSInstance *osinstance;
    OSOption   *osoption;

    osinstance = nl2OS->osinstance;
    //std::cout << " osinstance created" << std::endl;

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

    bool writeOK;
    OSosrl2ampl *solWriter = new OSosrl2ampl();

    try
    {
        if(serviceLocation.size() == 0 )
        {
            //determine the solver and do a local solve
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
            outStr.str("");
            outStr.clear();
            outStr << "Place remote synchronous call: " << serviceLocation << endl << endl << endl;
            osoutput->OSPrint(ENUM_OUTPUT_AREA_main, ENUM_OUTPUT_LEVEL_info, outStr.str());

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
        osoutput->OSPrint(ENUM_OUTPUT_AREA_main, ENUM_OUTPUT_LEVEL_error, osrl);
//        osrl = " ";
//        write_sol(const_cast<char*>(osrl.c_str()), NULL, NULL, NULL);

        writeOK = solWriter->writeSolFile(osrl, nl2OS->getASL("asl"));

        delete solWriter;
        solWriter = NULL;

        delete osresult;
        osresult = NULL;
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
        std::string::size_type pos1 = osrl.find( "error");
        if(pos1 == std::string::npos)
        {
            std::string sReport = "model was solved";
            osrlreader = new OSrLReader();
            osresult = osrlreader->readOSrL( osrl);

            writeOK = solWriter->writeSolFile(osrl, nl2OS->getASL("asl"));

            delete osrlreader;
            osrlreader = NULL;
        }
        else // there was an error
        {
            osoutput->OSPrint(ENUM_OUTPUT_AREA_main, ENUM_OUTPUT_LEVEL_error, osrl);
            writeOK = solWriter->writeSolFile(osrl, nl2OS->getASL("asl"));
        }
    }
    catch(const ErrorClass& eclass)
    {
        outStr.str("");
        outStr.clear();
        outStr << "There was an error parsing the OSrL string" << endl << eclass.errormsg << endl << endl;
        osoutput->OSPrint(ENUM_OUTPUT_AREA_main, ENUM_OUTPUT_LEVEL_debug, outStr.str());
    }

    if (solverType != NULL)
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
    //cout << "nl2OS JUST DELETED" <<endl;
    nl2OS = NULL;
//    ASL_free(&asl);
    if (solWriter != NULL) delete solWriter;
    solWriter = NULL;
    return 0;
} // end main




void getAmplClientOptions(char *amplclient_options, std::string *solverName,
                          std::string *solverOptions, std::string *serviceLocation)
{
    std::ostringstream outStr;

    // initialize the OS command line structure
    OSCommandLine *oscommandline = new OSCommandLine();

    void* scanner;

    try
    {
        //cout << "Input String = "  << amplclient_options << endl;
        ossslex_init( &scanner);
        //std::cout << "Call Text Extra" << std::endl;
        setyyextra( oscommandline, scanner);
        //std::cout << "Call scan string " << std::endl;
        osss_scan_string( amplclient_options, scanner);
        //std::cout << "call ossslex" << std::endl;
        ossslex( scanner);
        ossslex_destroy( scanner);
        //std::cout << "done with call to ossslex" << std::endl;

        *solverName = oscommandline->solverName;
        *solverOptions = oscommandline->osolFile;
        *serviceLocation = oscommandline->serviceLocation;

    }//end try
    catch(const ErrorClass& eclass)
    {
        outStr.str("");
        outStr.clear();
        outStr << "There was an error processing OSAmplClient options: " << endl << eclass.errormsg << endl << endl;
        osoutput->OSPrint(ENUM_OUTPUT_AREA_main, ENUM_OUTPUT_LEVEL_debug, outStr.str());
        throw ErrorClass( eclass.errormsg) ;
    }
}//getAmplClientOptions
