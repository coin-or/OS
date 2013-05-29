/** @file OSAmplClient.cpp
 *
 * @author  Robert Fourer, Horand Gassmann, Jun Ma, Kipp Martin
 *
 * \remarks
 * Copyright (C) 2005-2013, Robert Fourer, Horand Gassmann, Jun Ma, Kipp Martin,
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
 * option OSAmplClient_options "-serviceLocation http://74.94.100.129:8080/OSServer/services/OSSolverService"; <br />
 *
 *
 * \item there are three possible options to specify:
 *
 * \begin{itemize}
 *
 * \item the name of the solver using the  {\bf -solver} option, valid values for this option  are {\tt clp},
 * {\tt cbc}, {\tt dylp}, {\tt ipopt}, {\tt bonmin}, {\tt couenne}, {\tt symphony}, and {\tt vol}.
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
 * bonmin is used.  All solvers can be invoked locally or remotely. 
 * See the Users Manual in the doc folder for more information.
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

#ifndef COIN_HAS_ASL
# error do not have ASL
#endif

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
#include "OSCommandLineReader.h"
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

std::string get_help();
void list_options(OSCommandLine *oscommandline);

// the serviceMethods
void    solve(OSCommandLine *oscommandline, OSnl2OS *osnl2os);
void getJobID(OSCommandLine *oscommandline, OSnl2OS *osnl2os);
void     send(OSCommandLine *oscommandline, OSnl2OS *osnl2os);
void     kill(OSCommandLine *oscommandline, OSnl2OS *osnl2os);
void retrieve(OSCommandLine *oscommandline, OSnl2OS *osnl2os);
void    knock(OSCommandLine *oscommandline, OSnl2OS *osnl2os);

// additional methods
bool findInstance(   OSCommandLine *oscommandline, OSnl2OS *osnl2os);
void makeStrings(    OSCommandLine *oscommandline);
void doPrintRow(OSInstance *osinstance, std::string rownumberstring);
void reportResults(OSCommandLine *oscommandline, std::string osrl,  OSnl2OS *osnl2OS);
void reportErrors(OSCommandLine *oscommandline, std::string errMsg, OSnl2OS *osnl2OS);

extern const OSSmartPtr<OSOutput> osoutput;


int main(int argc, char **argv)
{
    WindowsErrorPopupBlocker();
    std::ostringstream outStr;
    OSnl2OS *nl2OS = new OSnl2OS();
    OSiLReader* osilreader = new OSiLReader(); 
    FileUtil *fileUtil = NULL;
    ostringstream echo_cl;

    // initialize the command line structure 

    OSCommandLine *oscommandline = NULL; // = new OSCommandLine();
    OSCommandLineReader *oscommandlinereader = new OSCommandLineReader();

//    DefaultSolver *solverType  = NULL;
    char* stub = NULL;
    if (argc > 0) stub = argv[1];

    // getting the OSAmplClient_options into a std::string is a bit of a pain...
    char* temp = getenv("OSAmplClient_options");
    ostringstream temp2;
    std::string amplclient_options;
    if (temp != NULL)
    {
        temp2 << temp; 
        amplclient_options = temp2.str();
    }
    else
        amplclient_options = "";

    // this output must be held in abeyance  until the command line
    // has been processed and printLevel has been set...
#ifndef NDEBUG
    echo_cl << "HERE ARE THE AMPLCLIENT OPTIONS ";
    echo_cl << amplclient_options;
    echo_cl << endl << endl;

    echo_cl << "Try to open file ";
    echo_cl << stub << ".nl";
    echo_cl << endl;
#endif

    // Now read the command line
    try
    {
        oscommandline = oscommandlinereader->readCommandLine(amplclient_options);
    }

    catch (const ErrorClass& eclass)
    {
        reportErrors(oscommandline, eclass.errormsg, nl2OS);
        delete oscommandlinereader;
        oscommandlinereader = NULL;
        return 1;
    }

    if (stub) oscommandline->nlFile = stub;


    /** Deal with action items: -printLevel, -logFile, -filePrintLevel, --help, --version **/

    try
    {
        outStr.str("");
        outStr.clear();
        outStr << std::endl << "using print level " << oscommandline->printLevel << " for stdout" << std::endl;

        if (oscommandline->printLevel != DEFAULT_OUTPUT_LEVEL)
        {
            osoutput->SetPrintLevel("stdout", (ENUM_OUTPUT_LEVEL)oscommandline->printLevel);

#ifndef NDEBUG
            osoutput->OSPrint(ENUM_OUTPUT_AREA_main, ENUM_OUTPUT_LEVEL_trace, echo_cl.str());
#endif
            osoutput->OSPrint(ENUM_OUTPUT_AREA_main, ENUM_OUTPUT_LEVEL_info, outStr.str());
        }
#ifndef NDEBUG
        else
        {
            osoutput->OSPrint(ENUM_OUTPUT_AREA_main, ENUM_OUTPUT_LEVEL_trace, echo_cl.str());
            osoutput->OSPrint(ENUM_OUTPUT_AREA_main, ENUM_OUTPUT_LEVEL_debug, outStr.str());            
        }
#endif

        if (oscommandline->logFile != "")
        {
            int status = osoutput->AddChannel(oscommandline->logFile);
 
            switch(status)
            {
                case 0:
                    osoutput->OSPrint(ENUM_OUTPUT_AREA_main, ENUM_OUTPUT_LEVEL_info,
                        "Added channel " + oscommandline->logFile);
                    break;          
                case 1:
                    osoutput->OSPrint(ENUM_OUTPUT_AREA_main, ENUM_OUTPUT_LEVEL_info,
                        "Output channel " + oscommandline->logFile + " previously defined");
                    break;
                default:
                    throw ErrorClass("Could not add output channel " + oscommandline->logFile);
            }//end switch
            

            outStr.str("");
            outStr.clear();
            outStr << std::endl << "using print level " << oscommandline->filePrintLevel;
            outStr << " for " << oscommandline->logFile << std::endl;

            if (oscommandline->filePrintLevel != DEFAULT_OUTPUT_LEVEL)
            {
                osoutput->SetPrintLevel(oscommandline->logFile, (ENUM_OUTPUT_LEVEL)oscommandline->filePrintLevel);
            }
            else
            {
                osoutput->OSPrint(ENUM_OUTPUT_AREA_main, ENUM_OUTPUT_LEVEL_debug, outStr.str());            
            }
        }

        if (oscommandline->invokeHelp == true)
        {
            outStr.str("");
            outStr.clear();
            outStr << std::endl << std::endl << get_help() << std::endl;
            osoutput->OSPrint(ENUM_OUTPUT_AREA_main, ENUM_OUTPUT_LEVEL_always, outStr.str());

            delete oscommandlinereader;
            oscommandlinereader = NULL;
            return 0;
        }

        if (oscommandline->writeVersion == true)
        {
            outStr.str("");
            outStr.clear();
            outStr << std::endl << std::endl << OSgetVersionInfo() << std::endl;
            osoutput->OSPrint(ENUM_OUTPUT_AREA_main, ENUM_OUTPUT_LEVEL_always, outStr.str());

            delete oscommandlinereader;
            oscommandlinereader = NULL;
            return 0;
        }
    }
    catch (const ErrorClass& eclass)
    {
        reportErrors(oscommandline, eclass.errormsg, nl2OS);
        delete oscommandlinereader;
        oscommandlinereader = NULL;
        return 1;
    }

#ifndef NDEBUG
    outStr.str("");
    outStr.clear();
    
    outStr << "HERE ARE THE OPTION VALUES:" << endl;
    if(oscommandline->configFile != "") outStr << "Config file = " << oscommandline->configFile << endl;
    if(oscommandline->osilFile != "") outStr << "OSiL file = " << oscommandline->osilFile << endl;
    if(oscommandline->osolFile != "") outStr << "OSoL file = " << oscommandline->osolFile << endl;
    if(oscommandline->osrlFile != "") outStr << "OSrL file = " << oscommandline->osrlFile << endl;
    //if(oscommandline->insListFile != "") outStr << "Instruction List file = " << oscommandline->insListFile << endl;
    if(oscommandline->osplInputFile != "") outStr << "OSpL Input file = " << oscommandline->osplInputFile << endl;
    if(oscommandline->serviceMethod != "") outStr << "Service Method = " << oscommandline->serviceMethod << endl;
    if(oscommandline->mpsFile != "") outStr << "MPS File Name = " << oscommandline->mpsFile << endl;
    if(oscommandline->nlFile != "") outStr << "NL File Name = " << oscommandline->nlFile << endl;
    if(oscommandline->gamsControlFile != "") outStr << "gams Control File Name = " << oscommandline->gamsControlFile << endl;
    if(oscommandline->browser != "") outStr << "Browser Value = " << oscommandline->browser << endl;
    if(oscommandline->solverName != "") outStr << "Selected Solver = " << oscommandline->solverName << endl;
    if(oscommandline->serviceLocation != "") outStr << "Service Location = " << oscommandline->serviceLocation << endl;
    if(oscommandline->jobID != "") outStr << "Job ID = " << oscommandline->jobID << endl;
    if(oscommandline->printModel) outStr << "print model prior to solve/send" << endl;
    if(oscommandline->printRowNumberAsString != "") outStr << "print model row " << oscommandline->printRowNumberAsString << " prior to solve/send" << endl;
    outStr << "print level for stdout: " << oscommandline->printLevel << endl;
    if(oscommandline->logFile != "") 
    {
        outStr << "also send output to " << oscommandline->logFile << endl;
        outStr << "print level for file output: " << oscommandline->filePrintLevel << endl;
    }

    osoutput->OSPrint(ENUM_OUTPUT_AREA_main, ENUM_OUTPUT_LEVEL_debug, outStr.str());
#endif


    //convert solver name to lower case so there is no ambiguity
    unsigned int k;
    for (k = 0; k < oscommandline->solverName.length(); k++)
    {
        oscommandline->solverName[k] = (char)tolower(oscommandline->solverName[k]);
    }

    // now call the correct serviceMethod
    // solve is the default
    if (oscommandline->serviceMethod == "") oscommandline->serviceMethod = "solve";

    try
    {
        // for local use only the solve method is available
        if (oscommandline->serviceLocation == "")
            if (oscommandline->serviceMethod != "solve") 
                throw ErrorClass("No serviceLocation given. Only \'solve\' is available locally.");

        if (oscommandline->serviceMethod[0] == 's')
        {
            // for solve or send commands we must have an instance
            if (oscommandline->osil == "")
            {
                if (!findInstance(oscommandline, nl2OS))
                    throw ErrorClass("No instance could be found");
            }

            // write out the model or portion thereof, if directed by the user
            if (oscommandline->printModel == true)
            {
                if (oscommandline->osinstance == NULL)
                {
                    oscommandline->osinstance = osilreader->readOSiL(oscommandline->osil);
                }
                osoutput->OSPrint(ENUM_OUTPUT_AREA_main, ENUM_OUTPUT_LEVEL_always, 
                    oscommandline->osinstance->printModel());
            }
            else if (oscommandline->printRowNumberAsString != "")
            {
                if (oscommandline->osinstance == NULL)
                {
                    oscommandline->osinstance = osilreader->readOSiL(oscommandline->osil);
                }
                doPrintRow(oscommandline->osinstance, oscommandline->printRowNumberAsString);
            }

            // write the instance to an OSiL file, if directed by the user
            if (oscommandline->osilOutputFile != "")
            {
                fileUtil = new FileUtil();
                if (oscommandline->osil == "")
                {
                    OSiLWriter* osilwriter = new OSiLWriter(); 
                    oscommandline->osil = osilwriter->writeOSiL(oscommandline->osinstance);
                    delete osilwriter;
                    osilwriter = NULL;
                }
                fileUtil->writeFileFromString(oscommandline->osilOutputFile, oscommandline->osil);
                delete fileUtil;
                fileUtil = NULL;
            }

            // write the solver options to an OSoL file, if directed by the user
            if (oscommandline->osolOutputFile != "")
            {
                fileUtil = new FileUtil();
                if (oscommandline->osol != "" && oscommandline->osoption == NULL)
                    fileUtil->writeFileFromString(oscommandline->osolOutputFile, oscommandline->osol);
                else
                {
                    if (oscommandline->osoption == NULL)
                        oscommandline->osoption = new OSOption();
                    OSoLWriter* osolwriter = new OSoLWriter(); 
                    fileUtil->writeFileFromString(oscommandline->osolOutputFile, 
                        osolwriter->writeOSoL(oscommandline->osoption));
                    delete osolwriter;
                    osolwriter = NULL;
                }
                delete fileUtil;
                fileUtil = NULL;
            }

            // if no serviceLocation was given, do a local solve
            if (oscommandline->serviceLocation == "")
            {
                std::string osrl;
                if (oscommandline->osinstance != NULL)
                    if (oscommandline->osoption != NULL)
                        osrl = runSolver(oscommandline->solverName, oscommandline->osoption, oscommandline->osinstance);
                    else
                        osrl = runSolver(oscommandline->solverName, oscommandline->osol,     oscommandline->osinstance);
                else
                    if (oscommandline->osoption != NULL)
                        osrl = runSolver(oscommandline->solverName, oscommandline->osoption, oscommandline->osil);
                    else
                        osrl = runSolver(oscommandline->solverName, oscommandline->osol,     oscommandline->osil);
                reportResults(oscommandline, osrl, nl2OS);
            }
    
            // remote solve or send
            else
            {
                if (oscommandline->serviceMethod[1] == 'e')
                    send(oscommandline, nl2OS);
                else
                    solve(oscommandline, nl2OS);
            }
        }

        else //call one of the other methods
        {
            switch (oscommandline->serviceMethod[0])
            {
            case 'g':
                getJobID(oscommandline, nl2OS);
                break;
            case 'r':
                retrieve(oscommandline, nl2OS);
                break;
            case 'k':
                if (oscommandline->serviceMethod[1] == 'i')
                    kill(oscommandline, nl2OS);
                else
                    knock(oscommandline, nl2OS);
                break;
            default:
                break;
            }
        }

        // garbage collection
        if (osilreader != NULL)
            delete osilreader;
            oscommandline->osinstance = NULL;
        osilreader = NULL;
        delete oscommandlinereader;
        oscommandlinereader = NULL;
        delete fileUtil;
        fileUtil = NULL;

        if (nl2OS != NULL)
            delete nl2OS;
        nl2OS = NULL;

        return 0;
    }

    catch (const ErrorClass& eclass)
    {
        reportErrors(oscommandline, eclass.errormsg, nl2OS);
        if (osilreader != NULL)
            delete osilreader;
            oscommandline->osinstance = NULL;
        osilreader = NULL;
        delete oscommandlinereader;
        oscommandlinereader = NULL;
        delete fileUtil;
        fileUtil = NULL;

        if (nl2OS != NULL)
            delete nl2OS;
        nl2OS = NULL;
        return 1;
    }
}// end of main()


/** This method tries to find the instance by reading the .nl file.
 *  This is the only acceptable format, since AMPL has just written
 *  the content of the model to a temporary file. 
 *  @param oscommandline: contains the information processed so far
 *  @return whether an instance was found or not
 */
bool findInstance(OSCommandLine *oscommandline, OSnl2OS *nl2os)
{
//    FileUtil *fileUtil = NULL;
//    fileUtil = new FileUtil();

    try
    {
//        nl2os = new OSnl2OS();
        if (!nl2os->readNl(oscommandline->nlFile))
            throw ErrorClass("Error reading .nl file.");
        nl2os->setOsol(oscommandline->osol);
        nl2os->setJobID(oscommandline->jobID);
        nl2os->createOSObjects() ;
        oscommandline->osinstance = nl2os->osinstance;
        return true;
    }
    catch (const ErrorClass& eclass)
    {
        osoutput->OSPrint(ENUM_OUTPUT_AREA_main, ENUM_OUTPUT_LEVEL_error, eclass.errormsg);
        //throw ErrorClass(eclass.errormsg);
        return false;
    }
}//findInstance

void makeStrings(OSCommandLine *oscommandline)
{
    // convert the osinstance and osoption objects to strings
    if (oscommandline->osil == "")
    {
        OSiLWriter *osilwriter = new OSiLWriter();
        oscommandline->osil = osilwriter->writeOSiL(oscommandline->osinstance);
#ifndef NDEBUG
        osoutput->OSPrint(ENUM_OUTPUT_AREA_main, ENUM_OUTPUT_LEVEL_trace, oscommandline->osil);
#endif
        delete osilwriter;
        osilwriter = NULL; 
    }

/** With the options we need to be a little more careful:
 *  Options can be in osol and jobID strings (either can be missing)
 *  or in an osoption object (which would include both of the above)
 *  or missing entirely (in which case a dummy string needs to be created)
 */
    OSoLReader *osolreader = NULL;
    if (oscommandline->osoption != NULL || oscommandline->jobID != "" || oscommandline->osol == "")
    {
        if (oscommandline->osoption == NULL)
        {
            oscommandline->osoption = new OSOption();
            if (oscommandline->osol != "")
            { 
                osolreader = new OSoLReader();
                oscommandline->osoption = osolreader->readOSoL(oscommandline->osol);
            }
            if (oscommandline->jobID != "")
                oscommandline->osoption->setJobID(oscommandline->jobID);
        }

        OSoLWriter *osolwriter = new OSoLWriter();
        oscommandline->osol = osolwriter->writeOSoL(oscommandline->osoption);
#ifndef NDEBUG
        osoutput->OSPrint(ENUM_OUTPUT_AREA_main, ENUM_OUTPUT_LEVEL_trace, oscommandline->osol);
#endif
        delete osolwriter;
        osolwriter = NULL;
    }
    if (osolreader != NULL)
    {
        delete osolreader;
        oscommandline->osoption = NULL; // no longer needed, and memory may have just been freed 
    }
    osolreader = NULL;
}

/** Next we have implementations of the six remote service methods
 *  solve, send, retrieve, knock, kill, getJobID
 *  (Do not bother with local solve; use runSolver instead)
 */

void solve(OSCommandLine *oscommandline, OSnl2OS *nl2OS)
{
    std::string osrl = "";
    OSSolverAgent* osagent = NULL;
    FileUtil *fileUtil = NULL;
    fileUtil = new FileUtil();

    try
    {
        // place a remote call
        osagent = new OSSolverAgent(oscommandline->serviceLocation);

        //no need to worry about jobID, but make sure we have strings
        oscommandline->jobID = "";
        makeStrings(oscommandline);

        osrl = osagent->solve(oscommandline->osil, oscommandline->osol);
        delete osagent;
        osagent = NULL;

        reportResults(oscommandline, osrl, nl2OS);

        //garbage collection
        delete fileUtil;
        fileUtil = NULL;

    }//end try
    catch (const ErrorClass& eclass)
    {
        reportErrors(oscommandline, eclass.errormsg, nl2OS);

        //garbage collection
        delete fileUtil;
        fileUtil = NULL;
    }//end local catch

}//end solve 


void send(OSCommandLine *oscommandline, OSnl2OS *nl2OS)
{
    bool bSend = false;
    bool always_print = false;
    OSSolverAgent* osagent = NULL;
    ostringstream outStr;

    try
    {
        osagent = new OSSolverAgent(oscommandline->serviceLocation);


        // get a job ID if necessary
        if (oscommandline->jobID == "NEW")
        {
            always_print = true;
            oscommandline->jobID = osagent->getJobID("");
            if (oscommandline->osoption != NULL)
                oscommandline->osoption->setJobID(oscommandline->jobID);
        }

        makeStrings(oscommandline);

        outStr.str("");
        outStr.clear();
        outStr << "Submitting Job " << oscommandline->jobID << std::endl;
        osoutput->OSPrint(ENUM_OUTPUT_AREA_main, ENUM_OUTPUT_LEVEL_info, outStr.str());

        bSend = osagent->send(oscommandline->osil, oscommandline->osol);

        outStr.str("");
        outStr.clear();
        outStr << "Job " << oscommandline->jobID;

        if (bSend == true)
        {
            outStr << " successfully submitted." << std::endl;
            if (always_print)
                osoutput->OSPrint(ENUM_OUTPUT_AREA_main, ENUM_OUTPUT_LEVEL_always, outStr.str());
            else
                osoutput->OSPrint(ENUM_OUTPUT_AREA_main, ENUM_OUTPUT_LEVEL_info,   outStr.str());
        }
        else
        {
            outStr << ": send failed." << std::endl;
            outStr << "Check to make sure you sent a jobID not on the system." << std::endl;
            osoutput->OSPrint(ENUM_OUTPUT_AREA_main, ENUM_OUTPUT_LEVEL_error, outStr.str());
        }
          
        delete osagent;
        osagent = NULL;
    }

    catch (const ErrorClass& eclass)
    {
        reportErrors(oscommandline, eclass.errormsg, nl2OS);
        if (osagent != NULL)
            delete osagent;
        osagent = NULL;
    }
}//end send

void getJobID(OSCommandLine *oscommandline, OSnl2OS* nl2OS)
{
    OSSolverAgent* osagent = NULL;
    try
    {
        if (oscommandline->serviceLocation != "")
        {
            osagent = new OSSolverAgent(oscommandline->serviceLocation);
            oscommandline->jobID = osagent->getJobID(oscommandline->osol);
            osoutput->OSPrint(ENUM_OUTPUT_AREA_main, ENUM_OUTPUT_LEVEL_error, oscommandline->jobID);
            delete osagent;
            osagent = NULL;
        }
        else
        {
            delete osagent;
            osagent = NULL;
            throw ErrorClass("please specify service location (url)");
        }
    }

    catch (const ErrorClass& eclass)
    {
        reportErrors(oscommandline, eclass.errormsg, nl2OS);
        if (osagent != NULL)
            delete osagent;
        osagent = NULL;
    }
}//end getJobID


void knock(OSCommandLine *oscommandline, OSnl2OS* nl2OS)
{
    std::string osplOutput = "";
    OSSolverAgent* osagent = NULL;
    FileUtil *fileUtil = NULL;
    fileUtil = new FileUtil();
    try
    {
        if (oscommandline->serviceLocation != "")
        {
            osagent = new OSSolverAgent(oscommandline->serviceLocation);

            if (oscommandline->osol == "")
            {
                // we need to construct the OSoL
                OSOption *osOption = NULL;
                osOption = new OSOption();
                //set the jobID if there is one
                if(oscommandline->jobID == "") osOption->setJobID( oscommandline->jobID);
                // now read the osOption object into a string
                OSoLWriter *osolWriter = NULL;
                osolWriter = new OSoLWriter();
                oscommandline->osol = osolWriter->writeOSoL( osOption);
                delete osOption;
                osOption = NULL;
                delete osolWriter;
                osolWriter = NULL;
            }

            osplOutput = osagent->knock(oscommandline->osplInput, oscommandline->osol);
            if (oscommandline->osplOutputFile != "")
                fileUtil->writeFileFromString(oscommandline->osplOutputFile,
                                              osplOutput);
            else
                osoutput->OSPrint(ENUM_OUTPUT_AREA_main, ENUM_OUTPUT_LEVEL_error, osplOutput);
            delete osagent;
        }
        else
        {
            delete osagent;
            throw ErrorClass("please specify service location (url)");
        }
        delete fileUtil;
        fileUtil = NULL;
    }
    catch (const ErrorClass& eclass)
    {
         reportErrors(oscommandline, eclass.errormsg, nl2OS);
        if (osagent != NULL)
            delete osagent;
        osagent = NULL;

        delete fileUtil;
        fileUtil = NULL;
    }
}//end knock

void retrieve(OSCommandLine *oscommandline, OSnl2OS *nl2OS)
{
    FileUtil *fileUtil = NULL;
    fileUtil = new FileUtil();
    std::string osrl = "";
    OSSolverAgent* osagent = NULL;

    try
    {
        if (oscommandline->serviceLocation != "")
        {
            if (!nl2OS->readNl(oscommandline->nlFile))
                throw ErrorClass("Error reading .nl file.");

            osagent = new OSSolverAgent(oscommandline->serviceLocation);

            if (oscommandline->osol == "")
            {
                // we need to construct the OSoL
                OSOption *osOption = NULL;
                osOption = new OSOption();
                // get a jobId if necessary
                if (oscommandline->jobID == "") throw ErrorClass("there is no JobID");
                //set the jobID
                osOption->setJobID( oscommandline->jobID);
                // now read the osOption object into a string
                OSoLWriter *osolWriter = NULL;
                osolWriter = new OSoLWriter();
                oscommandline->osol = osolWriter->writeOSoL( osOption);
                delete osOption;
                osOption = NULL;
                delete osolWriter;
                osolWriter = NULL;
            }

            osrl = osagent->retrieve(oscommandline->osol);
            reportResults(oscommandline, osrl, nl2OS);
            delete osagent;
            osagent = NULL;
        }
        else
        {
            delete osagent;
            osagent = NULL;
            throw ErrorClass("please specify service location (url)");
        }
        delete fileUtil;
        fileUtil = NULL;
    }
    catch (const ErrorClass& eclass)
    {
        reportErrors(oscommandline, eclass.errormsg, nl2OS);
        if (osagent != NULL)
            delete osagent;
        osagent = NULL;

        delete fileUtil;
        fileUtil = NULL;
    }
}//end retrieve

void kill(OSCommandLine *oscommandline, OSnl2OS* nl2OS)
{
    FileUtil *fileUtil = NULL;
    fileUtil = new FileUtil();
    std::string osplOutput = "";
    OSSolverAgent* osagent = NULL;
    try
    {
        if (oscommandline->serviceLocation != "")
        {
            osagent = new OSSolverAgent(oscommandline->serviceLocation);

            if (oscommandline->osol == "")
            {
                // we need to construct the OSoL
                OSOption *osOption = NULL;
                osOption = new OSOption();
                // get a jobId if necessary
                if (oscommandline->jobID == "") throw ErrorClass("there is no JobID");
                //set the jobID
                osOption->setJobID( oscommandline->jobID);
                // now read the osOption object into a string
                OSoLWriter *osolWriter = NULL;
                osolWriter = new OSoLWriter();
                oscommandline->osol = osolWriter->writeOSoL( osOption);
                delete osOption;
                osOption = NULL;
                delete osolWriter;
                osolWriter = NULL;
            }

            osplOutput = osagent->kill(oscommandline->osol);

            if (oscommandline->osplOutputFile != "")
                fileUtil->writeFileFromString(oscommandline->osplOutputFile, osplOutput);
            else
                osoutput->OSPrint(ENUM_OUTPUT_AREA_main, ENUM_OUTPUT_LEVEL_summary, osplOutput);
            delete osagent;
            osagent = NULL;
        }
        else
        {
            delete osagent;
            osagent = NULL;
            throw ErrorClass("please specify service location (url)");
        }
        delete fileUtil;
        fileUtil = NULL;
    }
    catch (const ErrorClass& eclass)
    {
        reportErrors(oscommandline, eclass.errormsg, nl2OS);
        if (osagent != NULL)
            delete osagent;
        osagent = NULL;

        delete fileUtil;
        fileUtil = NULL;
    }
}//end kill



/** Deal with the OSrL output generated by the call to one of the service methods
 */
void reportResults(OSCommandLine *oscommandline, std::string osrl, OSnl2OS* nl2OS)
{
    ostringstream outStr;

    if (oscommandline->osrlFile == "")
        oscommandline->osrlFile = oscommandline->nlFile + ".osrl";
    
    FileUtil* fileUtil = new FileUtil();
    fileUtil->writeFileFromString(oscommandline->osrlFile, osrl);
    
    if (oscommandline->browser != "")
    {
        std::string str = oscommandline->browser + "  "
                          + oscommandline->osrlFile;
        const char *ch = &str[0];
        std::system(ch);
    }

    // now put solution back to ampl

    OSosrl2ampl *solWriter = new OSosrl2ampl();

    try
    {
        std::string::size_type pos1 = osrl.find( "error");
        if(pos1 == std::string::npos)
        {
//            OSrLReader *osrlreader = new OSrLReader();
//            OSResult *osresult = osrlreader->readOSrL( osrl);
            solWriter->writeSolFile(osrl, nl2OS->getASL("asl"), oscommandline->nlFile + ".sol");

//            delete osrlreader;
//            osrlreader = NULL;
        }
        else // there was an error
        {
            osoutput->OSPrint(ENUM_OUTPUT_AREA_main, ENUM_OUTPUT_LEVEL_error, osrl);
            solWriter->writeSolFile(osrl, nl2OS->getASL("asl"), oscommandline->nlFile + ".sol");
        }
        if (fileUtil != NULL)
            delete fileUtil;
        fileUtil = NULL;
    }
    catch(const ErrorClass& eclass)
    {
        outStr.str("");
        outStr.clear();
        outStr << "There was an error parsing the OSrL string" << endl << eclass.errormsg << endl << endl;
        osoutput->OSPrint(ENUM_OUTPUT_AREA_main, ENUM_OUTPUT_LEVEL_debug, outStr.str());
        if (fileUtil != NULL)
            delete fileUtil;
        fileUtil = NULL;
    }

}// reportResults

/** Deal with any error messages generated by the call to one of the service methods
 */
void reportErrors(OSCommandLine *oscommandline, std::string errormsg, OSnl2OS* nl2OS)
{
        std::string osrl = "";
        OSResult *osresult = NULL;
        OSrLWriter *osrlwriter = NULL;
        //first check to see if we already have OSrL,
        //if so don't create a new osresult object
        std::string::size_type  pos1 = errormsg.find( "<osrl");
        if(pos1 == std::string::npos)
        {
            osrlwriter = new OSrLWriter();
            osresult = new OSResult();
            osresult->setGeneralMessage(errormsg);
            osresult->setGeneralStatusType("error");
            osrl = osrlwriter->writeOSrL(osresult);
        }
        else
        {
            osrl = errormsg;
        }
        reportResults(oscommandline, osrl, nl2OS);
}// reportErrors


void doPrintRow(OSInstance *osinstance, std::string rownumberstring)
{
    ostringstream outStr;
    int rownumber;
    if (rownumberstring == "")
        osoutput->OSPrint(ENUM_OUTPUT_AREA_main, ENUM_OUTPUT_LEVEL_always, 
            "no row number given; print command ignored");
    else
    {
        try
        {
            rownumber = atoi((rownumberstring).c_str());
        }
        catch  (const ErrorClass& eclass)
        {
            osoutput->OSPrint(ENUM_OUTPUT_AREA_main, ENUM_OUTPUT_LEVEL_always, 
                "invalid row number; print command ignored");
        }

        if (osinstance == NULL)
        {
            osoutput->OSPrint(ENUM_OUTPUT_AREA_main, ENUM_OUTPUT_LEVEL_always, 
                "no instance defined; print command ignored");
        }
        else
        {
            outStr << std::endl << "Row " << rownumber << ":" << std::endl << std::endl;
            outStr << osinstance->printModel(rownumber) << std::endl;
            osoutput->OSPrint(ENUM_OUTPUT_AREA_main, ENUM_OUTPUT_LEVEL_always, outStr.str());
        }
    }
}// doPrintRow(OSInstance *osinstance, std::string rownumberstring) 


std::string get_help()
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


