//Id: OSSolverService.cpp 3561 2010-06-24 19:27:07Z kmartin $
/** @file OSSolverService.cpp
 *
 * @author  Horand Gassmann, Jun Ma, Kipp Martin
 *
 * \remarks
 * Copyright (C) 2005-2012, Horand Gassmann, Jun Ma, Kipp Martin,
 * Northwestern University, and the University of Chicago.
 * All Rights Reserved.
 * This software is licensed under the Eclipse Public License.
 * Please see the accompanying LICENSE file in root directory for terms.
 *
 * <b>INPUTS:</b>
 * <ul>
 * <li>
 * <b>-osil</b> xxx.osil (file name on local machine of optimization instance,
 *       this is NULL by default; however, if this remains NULL a problem
 * 		 instance must be specified in the osol file)
 * </li>
 * <li>
 * <b>-osol</b> xxx.osol (file name on local machine of solver options,
 *       default value is NULL)
 * </li>
 * <li>
 * <b>-osrl</b> xxx.osrl (file name on local machine where the optimization
 *       result is put, default is NULL)
 * </li>
 * <li>
 * <b>-serviceLocation</b> location URL (the URL of the server that is called
 *       remotely if the problem is not solved locally, default is NULL)
 * </li>
 * <li>
 * <b>-serviceMethod</b>  (send, solve, kill, knock, getJobID, retrieve,
 *       default value is solve)
 * </li>
 * <li>
 * <b>-os</b> (Not used for now -- ignore)
 * </li>
 * <li>
 * <b>-osplInput</b> xxx.ospl name of file with input in OS Process Language
 * </li>
 * <li>
 * <b>-osplOutput</b> xxx.ospl name of output file in OS Process Language
 * </li>
 * <li>
 * <b>-mps</b> xxxx.mps (converts mps format to osil and has same effect as -osil)
 * </li>
 * <li>
 * <b>-nl</b> xxxx.nl (converts nl format to osil and has same effect as -osil)
 * </li>
 * <li>
 * <b>-solver</b> solverName (the name of the solver to be invoked)
 * </li>
 * <li>
 * <b>-browser</b> path location to browser e.g.
 *       /Applications/Firefox.app/Contents/MacOS/firefox (default is NULL)
 * </li>
 * <li>
 * <b>-config</b> pathToConfigFile is the path to a configure file with the problem
 * 	     parameters
 * </li>
 * <li>
 * <b>-insList</b> xxx.dat (used only for LINDO, file location on local
 *       machine of LINDO instruction list)
 * </li>
 * </ul>
 */

#include "OSCoinSolver.h"
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
#include "OSOutput.h"
#include "OSConfig.h"
#include "OSDefaultSolver.h"
#include "OSWSUtil.h"
#include "OSSolverAgent.h"
#include "OShL.h"
#include "OSErrorClass.h"
#include "OSmps2osil.h"
#include "OSBase64.h"
#include "OSRunSolver.h"

#ifdef COIN_HAS_KNITRO
#include "OSKnitroSolver.h"
#endif

#ifdef COIN_HAS_LINDO
#include "OSLindoSolver.h"
#endif

#ifdef COIN_HAS_ASL
#include "OSnl2OS.h"
#endif

#ifdef COIN_HAS_GAMSUTILS
#include "OSgams2osil.hpp"
#endif

#ifdef COIN_HAS_IPOPT
#ifndef COIN_HAS_ASL
#include "OSIpoptSolver.h"
#undef COIN_HAS_ASL
#else
#include "OSIpoptSolver.h"
#endif
#endif

#ifdef COIN_HAS_BONMIN
#include "OSBonminSolver.h"
#endif

#ifdef COIN_HAS_COUENNE
#include "OSCouenneSolver.h"
#endif

#include "OSCommandLine.h"

#include <stdio.h>
#include <map>

using std::cout;
using std::endl;
using std::ostringstream;
using std::string;
using std::map;


#define MAXCHARS 5000

typedef struct yy_buffer_state *YY_BUFFER_STATE;
YY_BUFFER_STATE osss_scan_string(const char* osss, void* scanner);
//void osssset_extra (YY_EXTRA_TYPE user_defined ,yyscan_t yyscanner );
void setyyextra(OSCommandLine *oscommandline, void* scanner);
int ossslex(void* scanner);
int ossslex_init(void** ptr);
int ossslex_destroy(void* scanner);

void interactiveShell();

std::string get_help();
std::string get_version();
std::string get_options();
void list_options(OSCommandLine *oscommandline);

// the serviceMethods
void    solve(OSCommandLine *oscommandline);
void getJobID(OSCommandLine *oscommandline);
void     send(OSCommandLine *oscommandline);
void     kill(OSCommandLine *oscommandline);
void retrieve(OSCommandLine *oscommandline);
void    knock(OSCommandLine *oscommandline);

// additional methods
void getOSiLFromNl(  OSCommandLine *oscommandline);
void getOSiLFromMps( OSCommandLine *oscommandline);
void getOSiLFromGams(OSCommandLine *oscommandline);
void doPrintModel(OSCommandLine *oscommandline);
void doPrintModel(OSInstance *osinstance);
void doPrintRow(OSCommandLine *oscommandline);
void doPrintRow(OSInstance *osinstance, std::string rownumberstring);

extern const OSSmartPtr<OSOutput> osoutput;

int main(int argC, const char* argV[])
{
    WindowsErrorPopupBlocker();
    std::ostringstream outStr;

    std::string versionInfo = OSgetVersionInfo();
    osoutput->OSPrint(ENUM_OUTPUT_AREA_main, ENUM_OUTPUT_LEVEL_always, versionInfo);

    if (argC < 2)
    {
        interactiveShell();
        return 0;
    }

    void* scanner;
    FileUtil *fileUtil = NULL;
    FileUtil *inputFileUtil = NULL;
    std::ostringstream osss;
    const char *space = " ";
    const char *quote = "\"";
    //char *config = "-config";
    std::string configFileName = "";
    int i;

    /** Parse the command line **/
     
    // initialize the command line structure 

//    osoptions = new osOptionsStruc();
	OSCommandLine *oscommandline = new OSCommandLine();
    bool scannerActive = false;
		
    try
    {

	// put the command line arguments into a string for parsing		
        bool addQuotes;
		osss << space; // needed to avoid segfault in case command line is empty

        for (i = 1; i < argC; i++)
        {
            addQuotes = false;
            if (argV[i][0] != '\"')
                for (int k=0; k<strlen(argV[i]); k++)
                {
                    if (argV[i][k] == ' ')
                    {
                        addQuotes = true;
                        break;
                    }
                }
            if (addQuotes)
            {
                osss << quote;
                osss << argV[i];
                osss << quote;
                osss << space;
            }
            else
            {
                osss << argV[i];
                osss << space;
            }
        }

#ifndef NDEBUG
        outStr.str("");
        outStr.clear();
        outStr << "Input String = " << osss.str() << std::endl;
        osoutput->OSPrint(ENUM_OUTPUT_AREA_main, ENUM_OUTPUT_LEVEL_trace, outStr.str());
#endif

        scannerActive = true;
        ossslex_init(&scanner);

#ifndef NDEBUG
        osoutput->OSPrint(ENUM_OUTPUT_AREA_main, ENUM_OUTPUT_LEVEL_trace, "Call Text Extra\n");
#endif

        setyyextra(oscommandline, scanner);

#ifndef NDEBUG
        osoutput->OSPrint(ENUM_OUTPUT_AREA_main, ENUM_OUTPUT_LEVEL_trace, "Call scan string\n");
#endif

        osss_scan_string((osss.str()).c_str(), scanner);

#ifndef NDEBUG
        osoutput->OSPrint(ENUM_OUTPUT_AREA_main, ENUM_OUTPUT_LEVEL_trace, "Call ossslex\n");
#endif

        ossslex(scanner);
        ossslex_destroy(scanner);
        scannerActive = false;

#ifndef NDEBUG
        osoutput->OSPrint(ENUM_OUTPUT_AREA_main, ENUM_OUTPUT_LEVEL_trace, "Done with call to ossslex\n");
#endif

        // if there is a config file, get those options
        if (oscommandline->configFile != "")
        {
            scannerActive = true;
            ossslex_init(&scanner);
            configFileName = oscommandline->configFile;

#ifndef NDEBUG
            outStr.str("");
            outStr.clear();
            outStr << "configFileName = " << configFileName << std::endl;
            osoutput->OSPrint(ENUM_OUTPUT_AREA_main, ENUM_OUTPUT_LEVEL_trace, outStr.str());
#endif

            std::string configFileOptions = fileUtil->getFileAsString(
                                              configFileName.c_str());
#ifndef NDEBUG
            osoutput->OSPrint(ENUM_OUTPUT_AREA_main, ENUM_OUTPUT_LEVEL_trace, "Call Text Extra\n");
#endif

            setyyextra(oscommandline, scanner);

#ifndef NDEBUG
            osoutput->OSPrint(ENUM_OUTPUT_AREA_main, ENUM_OUTPUT_LEVEL_trace, "Done with call Text Extra\n");
#endif

            osss_scan_string(configFileOptions.c_str(), scanner);
            ossslex(scanner);
            ossslex_destroy(scanner);
            scannerActive = false;
            
            
            /** new -- added on September 19, 2011
             * If we are here, then the command line had a configure file.
             * Command line options should override the config file so go
             * back and get these options again
             */
            
            scannerActive = true;
            ossslex_init(&scanner);

#ifndef NDEBUG
            osoutput->OSPrint(ENUM_OUTPUT_AREA_main, ENUM_OUTPUT_LEVEL_trace, "Call Text Extra\n");
#endif

            setyyextra(oscommandline, scanner);

#ifndef NDEBUG
            osoutput->OSPrint(ENUM_OUTPUT_AREA_main, ENUM_OUTPUT_LEVEL_trace, "Call scan string\n");
#endif

            osss_scan_string((osss.str()).c_str(), scanner);

#ifndef NDEBUG
            osoutput->OSPrint(ENUM_OUTPUT_AREA_main, ENUM_OUTPUT_LEVEL_trace, "call ossslex\n");
#endif

            ossslex(scanner);
            ossslex_destroy(scanner);
            scannerActive = false;           
            
            
            /** end of new code added on September 19, 2011 */
        }
    }
    catch (const ErrorClass& eclass)
    {
#ifndef NDEBUG
            osoutput->OSPrint(ENUM_OUTPUT_AREA_main, ENUM_OUTPUT_LEVEL_debug, eclass.errormsg);
#endif

        //new stuff on April 17, 2010
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
#ifndef NDEBUG
            osoutput->OSPrint(ENUM_OUTPUT_AREA_main, ENUM_OUTPUT_LEVEL_debug, eclass.errormsg);
#endif
            osoutput->OSPrint(ENUM_OUTPUT_AREA_main, ENUM_OUTPUT_LEVEL_error, osrl);
        }
        //catch garbage collection
        delete osresult;
        osresult = NULL;
        delete osrlwriter;
        osrlwriter = NULL;
        // end new stuff

        delete fileUtil;
        delete oscommandline;
        return 1;
    }

    /** Deal with action items: -printLevel, -logFile, -filePrintLevel, --help, --version **/

    try
    {
        outStr.str("");
        outStr.clear();
        outStr << std::endl << "using print level " << oscommandline->printLevel << " for stdout" << std::endl;

        if (oscommandline->printLevel != DEFAULT_OUTPUT_LEVEL)
        {
            osoutput->SetPrintLevel("stdout", (ENUM_OUTPUT_LEVEL)oscommandline->printLevel);
            osoutput->OSPrint(ENUM_OUTPUT_AREA_main, ENUM_OUTPUT_LEVEL_info, outStr.str());
        }
#ifndef NDEBUG
        else
        {
            osoutput->OSPrint(ENUM_OUTPUT_AREA_main, ENUM_OUTPUT_LEVEL_debug, outStr.str());            
        }
#endif

        if (oscommandline->logFile != "")
        {
            int status = osoutput->AddChannel(oscommandline->logFile);
 
            switch(status)
            {
                case 0:
                    osoutput->OSPrint(ENUM_OUTPUT_AREA_main, ENUM_OUTPUT_LEVEL_debug,
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

            delete oscommandline;
            oscommandline = NULL;
            return 0;
        }

        if (oscommandline->writeVersion == true)
        {
            outStr.str("");
            outStr.clear();
            outStr << std::endl << std::endl << OSgetVersionInfo() << std::endl;
            osoutput->OSPrint(ENUM_OUTPUT_AREA_main, ENUM_OUTPUT_LEVEL_always, outStr.str());

            delete oscommandline;
            oscommandline = NULL;
            return 0;
        }
    }
    catch (const ErrorClass& eclass)
    {
#ifndef NDEBUG
            osoutput->OSPrint(ENUM_OUTPUT_AREA_main, ENUM_OUTPUT_LEVEL_debug, eclass.errormsg);
#endif

        //new stuff on April 17, 2010
        OSResult *osresult = NULL;
        OSrLWriter *osrlwriter = NULL;
        osrlwriter = new OSrLWriter();
        osresult = new OSResult();
        osresult->setGeneralMessage(eclass.errormsg);
        osresult->setGeneralStatusType("error");
        std::string osrl = osrlwriter->writeOSrL(osresult);
        if (oscommandline->osrlFile != "")
        {
            //fileUtil->writeFileFromString(oscommandline->osrlFile,  eclass.errormsg);
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
#ifndef NDEBUG
            osoutput->OSPrint(ENUM_OUTPUT_AREA_main, ENUM_OUTPUT_LEVEL_debug, eclass.errormsg);
#endif
            osoutput->OSPrint(ENUM_OUTPUT_AREA_main, ENUM_OUTPUT_LEVEL_error, osrl);
        }
        //catch garbage collection
        delete osresult;
        osresult = NULL;
        delete osrlwriter;
        osrlwriter = NULL;
        // end new stuff


        delete oscommandline;
        oscommandline = NULL;
        delete inputFileUtil;
        inputFileUtil = NULL;
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

    // get the data from the files
    fileUtil = new FileUtil();
    try
    {
        if (oscommandline->osolFile != "")
        {
            oscommandline->osol = fileUtil->getFileAsString(
                                  (oscommandline->osolFile).c_str());
        }

        if (oscommandline->osilFile != "")
        {
            //this takes precedence over what is in the OSoL file
            oscommandline->osil = fileUtil->getFileAsString(
                                  (oscommandline->osilFile).c_str());
        }
        /*
         else{// we were not given an osil file
         // make sure we don't have a service URI in the file or are using mps or nl
         // if we have nl or mps assume a local solve
         if( (oscommandline->osol != "") && (oscommandline->nlFile == "") && (oscommandline->gamsControlFile == "") && (oscommandline->mpsFile == "") && (oscommandline->serviceLocation == "")  &&  (getServiceURI( oscommandline->osol) == "") )
         oscommandline->osil = fileUtil->getFileAsString( getInstanceLocation( oscommandline->osol).c_str()  );
         }
         */

        if (oscommandline->osplInputFile != "")
            oscommandline->osplInput = fileUtil->getFileAsString(
                                       (oscommandline->osplInputFile).c_str());
    }
    catch (const ErrorClass& eclass)
    {
        outStr.str("");
        outStr.clear();
        outStr << eclass.errormsg <<  endl;
        outStr << "could not open file properly" << endl;
        osoutput->OSPrint(ENUM_OUTPUT_AREA_main, ENUM_OUTPUT_LEVEL_error, outStr.str());
 

        //new stuff on April 17, 2010
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
            osoutput->OSPrint(ENUM_OUTPUT_AREA_main, ENUM_OUTPUT_LEVEL_error, osrl);
        }
        //catch garbage collection
        delete osresult;
        osresult = NULL;
        delete osrlwriter;
        osrlwriter = NULL;
        // end new stuff


        delete oscommandline;
        oscommandline = NULL;
        delete fileUtil;
        fileUtil = NULL;
        return 1;
    }
    // now call the correct serviceMethod
    // solve is the default
    if (oscommandline->serviceMethod == "") oscommandline->serviceMethod = "solve";
	if (oscommandline->serviceMethod[0] == 's')
    {
        if (oscommandline->printModel == true)
            doPrintModel(oscommandline);
        else if (oscommandline->printRowNumberAsString != "")
            doPrintRow(oscommandline);
        if (oscommandline->serviceMethod[1] == 'e')
            send(oscommandline);
        else
            solve(oscommandline);
    }
    else
    {
        switch (oscommandline->serviceMethod[0])
        {
        case 'g':
            getJobID(oscommandline);
            break;
        case 'r':
            retrieve(oscommandline);
            break;
        case 'k':
            if (oscommandline->serviceMethod[1] == 'i')
                kill(oscommandline);
            else
                knock(oscommandline);
            break;
        default:

            break;
        }
    }
    delete oscommandline;
    oscommandline = NULL;
    delete fileUtil;
    fileUtil = NULL;
    return 0;
}// end of main()


/** Next we have implementations of the six service methods
 *  solve, send, retrieve, knock, kill, getJobID
 */

void solve(OSCommandLine *oscommandline)
{
    std::string osrl = "";
    OSiLReader *osilreader = NULL;
    OSmps2osil *mps2osil = NULL;
#ifdef COIN_HAS_ASL
    OSnl2OS *nl2os = NULL;
#endif
#ifdef COIN_HAS_GAMSUTILS
    OSgams2osil *gams2osil = NULL;
#endif
    OSSolverAgent* osagent = NULL;
    FileUtil *fileUtil = NULL;
    fileUtil = new FileUtil();
    // now solve either remotely or locally
    try
    {
        if (oscommandline->serviceLocation != "") // remote call
        {
            // call a method here to get OSiL if we have an nl or mps file
            if (oscommandline->osil == "")
            {
                //we better have an nl file present or mps file or osol file
                if (oscommandline->nlFile != "")
                {
                    getOSiLFromNl(oscommandline);
                }
                else
                {
                    if (oscommandline->mpsFile != "")
                    {
                        getOSiLFromMps(oscommandline);
                    }
                    else
                    {
                        if (oscommandline->gamsControlFile != "")
                        {

                            getOSiLFromGams(oscommandline);
                        }
                        else    // send an empty osil string
                        {
                            oscommandline->osil = "";
                        }
                    }
                }
            }

	        if (oscommandline->printModel)
		        doPrintModel(oscommandline);
	        else if (oscommandline->printRowNumberAsString != "")
                doPrintRow(oscommandline);

            // place a remote call
            osagent = new OSSolverAgent(oscommandline->serviceLocation);

            if (oscommandline->osol == "")  // we have no osol string; create a dummy
            {
                std::ostringstream outStr;
                outStr
                        << "<?xml version=\"1.0\" encoding=\"UTF-8\"?> <osol xmlns=\"os.optimizationservices.org\" xmlns:xs=\"http://www.w3.org/2001/XMLSchema\" xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\" xsi:schemaLocation=\"os.optimizationservices.org http://www.optimizationservices.org/schemas/";
                outStr << OS_SCHEMA_VERSION;
                outStr << "/OSoL.xsd\"></osol>";
                oscommandline->osol = outStr.str();
            }
            osrl = osagent->solve(oscommandline->osil, oscommandline->osol);
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
                osoutput->OSPrint(ENUM_OUTPUT_AREA_main, ENUM_OUTPUT_LEVEL_error, osrl);
            delete osagent;
            osagent = NULL;
        }
        else    // solve locally
        {
            OSInstance *osinstance;
            OSOption   *osoption = NULL;
            if (oscommandline->osil != "")
            {
                osilreader = new OSiLReader();                
                osinstance = osilreader->readOSiL(oscommandline->osil);
            }
            else
            {
                //we better have an nl file present or mps file or osol file
                if (oscommandline->nlFile != "")
                {
#ifdef COIN_HAS_ASL
                    //nl2os = new OSnl2OS( oscommandline->nlFile, oscommandline->osol);
                    nl2os = new OSnl2OS();
                    nl2os->readNl(oscommandline->nlFile);
                    nl2os->setOsol(oscommandline->osol);
                    nl2os->createOSObjects() ;
                    osinstance = nl2os->osinstance;
                    if (nl2os->osoption != NULL)
                    {
                        osoption   = nl2os->osoption;
                        //write out the options
                        OSoLWriter *osolwriter = NULL;
                        osolwriter = new OSoLWriter();
                        //osolwriter->m_bWhiteSpace = true;
                        std::string sModelOptionName = "modelOptions.osol";
                        if (fileUtil == NULL) fileUtil = new FileUtil();
                        fileUtil->writeFileFromString(sModelOptionName,  osolwriter->writeOSoL( osoption) );
                        delete fileUtil;
                        fileUtil = NULL;
                        delete  osolwriter;
                        osolwriter = NULL;
                    }

#else
                    throw ErrorClass(
                        "nl file specified locally but ASL not present");
#endif
                }
                else
                {
                    if (oscommandline->mpsFile != "")
                    {
                        mps2osil = new OSmps2osil(oscommandline->mpsFile);
                        mps2osil->createOSInstance();
                        osinstance = mps2osil->osinstance;
                    }
                    else
                    {
                        if (oscommandline->gamsControlFile != "")
                        {
#ifdef COIN_HAS_GAMSUTILS
                            gams2osil = new OSgams2osil( oscommandline->gamsControlFile);
                            gams2osil->createOSInstance();
                            osinstance = gams2osil->osinstance;
#else
                            throw ErrorClass(
                                "a Gams Control specified locally but GAMSIP not present");
#endif

                        }
                        else    // need an osol file with an instanceLocation specified
                        {
                            throw ErrorClass(
                                "Error: no osil, GAMS dat, AMPL nl, or mps file given for a local solve --- \n NOTE: information in the osol file is ignored for local solves.");
                        }
                    }
                }
            }
    	    if (oscommandline->printModel)
                doPrintModel(osinstance);
    	    else if (oscommandline->printRowNumberAsString != "")
    	        doPrintRow(osinstance, oscommandline->printRowNumberAsString);
                
            osrl = runSolver(oscommandline->solverName, oscommandline->osol, osinstance);            

            if (oscommandline->osrlFile != "")
            {
                fileUtil->writeFileFromString(oscommandline->osrlFile, osrl);

                //const char *ch1 = "/Applications/Firefox.app/Contents/MacOS/firefox  ";
                if (oscommandline->browser != "")
                {
                    std::string str = oscommandline->browser + "  "
                                      + oscommandline->osrlFile;
                    const char *ch = &str[0];
                    std::system(ch);
                }
            }
            else
                osoutput->OSPrint(ENUM_OUTPUT_AREA_main, ENUM_OUTPUT_LEVEL_error, osrl);

        }//end of local solve


        //garbage collection
        if (osilreader != NULL)
            delete osilreader;
        osilreader = NULL;
        if (mps2osil != NULL)
            delete mps2osil;
        mps2osil = NULL;
#ifdef COIN_HAS_ASL
        if(nl2os != NULL) delete nl2os;
        nl2os = NULL;
#endif
#ifdef COIN_HAS_GAMSUTILS
        if(gams2osil != NULL) delete gams2osil;
        gams2osil = NULL;
#endif
        delete fileUtil;
        fileUtil = NULL;

    }//end try
    catch (const ErrorClass& eclass)
    {
        std::string osrl = "";
        OSResult *osresult = NULL;
        OSrLWriter *osrlwriter = NULL;
        //first check to see if we already have OSrL,
        //if so don't create a new osresult object
        std::string::size_type  pos1 = eclass.errormsg.find( "<osrl");
        if(pos1 == std::string::npos)
        {
            osrlwriter = new OSrLWriter();
            osresult = new OSResult();
            osresult->setGeneralMessage(eclass.errormsg);
            osresult->setGeneralStatusType("error");
            osrl = osrlwriter->writeOSrL(osresult);
        }
        else
        {
            osrl = eclass.errormsg;
        }
        if (oscommandline->osrlFile != "")
        {
            //fileUtil->writeFileFromString(oscommandline->osrlFile,  eclass.errormsg);
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
            osoutput->OSPrint(ENUM_OUTPUT_AREA_main, ENUM_OUTPUT_LEVEL_error, osrl);
        }
        //catch garbage collection
        if(osresult != NULL)
        {
            delete osresult;
            osresult = NULL;
        }
        if(osrlwriter != NULL)
        {
            delete osrlwriter;
            osrlwriter = NULL;
        }

        //regular garbage collection
        if (osilreader != NULL)
            delete osilreader;
        osilreader = NULL;
        if (mps2osil != NULL)
            delete mps2osil;
        mps2osil = NULL;
#ifdef COIN_HAS_ASL
        if(nl2os != NULL) delete nl2os;
        nl2os = NULL;
#endif
#ifdef COIN_HAS_GAMSUTILS
        if(gams2osil != NULL) delete gams2osil;
        gams2osil = NULL;
#endif
        delete fileUtil;
        fileUtil = NULL;
    }//end local catch

}//end solve 

void getJobID(OSCommandLine *oscommandline)
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
        FileUtil *fileUtil = NULL;
        fileUtil = new FileUtil();


        std::string osrl = "";
        OSResult *osresult = NULL;
        OSrLWriter *osrlwriter = NULL;
        //first check to see if we already have OSrL,
        //if so don't create a new osresult object
        string::size_type  pos1 = eclass.errormsg.find( "<osrl");
        if(pos1 == std::string::npos)
        {
            osrlwriter = new OSrLWriter();
            osresult = new OSResult();
            osresult->setGeneralMessage(eclass.errormsg);
            osresult->setGeneralStatusType("error");
            osrl = osrlwriter->writeOSrL(osresult);
        }
        else
        {
            osrl = eclass.errormsg;
        }


        //catch garbage collection
        if(osresult != NULL)
        {
            delete osresult;
            osresult = NULL;
        }
        if(osrlwriter != NULL)
        {
            delete osrlwriter;
            osrlwriter = NULL;
        }


        delete fileUtil;
        fileUtil = NULL;
    }
}//end getJobID


void knock(OSCommandLine *oscommandline)
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
        std::string osrl = "";
        OSResult *osresult = NULL;
        OSrLWriter *osrlwriter = NULL;
        //first check to see if we already have OSrL,
        //if so don't create a new osresult object
        string::size_type  pos1 = eclass.errormsg.find( "<osrl");
        if(pos1 == std::string::npos)
        {
            osrlwriter = new OSrLWriter();
            osresult = new OSResult();
            osresult->setGeneralMessage(eclass.errormsg);
            osresult->setGeneralStatusType("error");
            std::string osrl = osrlwriter->writeOSrL(osresult);
        }
        else
        {
            osrl = eclass.errormsg;
        }

        if(osresult != NULL)
        {
            delete osresult;
            osresult = NULL;
        }
        if(osrlwriter != NULL)
        {
            delete osrlwriter;
            osrlwriter = NULL;
        }


        delete fileUtil;
        fileUtil = NULL;
    }
}//end knock


void send(OSCommandLine *oscommandline)
{
    bool bSend = false;


    OSSolverAgent* osagent = NULL;
    try
    {
        // call a method here to get OSiL if we have an nl or mps file
        if (oscommandline->osil == "")
        {
            //we better have an nl file present or mps file
            if (oscommandline->nlFile != "")
            {
                getOSiLFromNl(oscommandline);
            }
            else
            {
                if (oscommandline->mpsFile != "")
                {
                    getOSiLFromMps(oscommandline);
                }
                else    // send an empty osil string
                {
                    oscommandline->osil = "";
                }
            }
        }
        if (oscommandline->serviceLocation != "")
        {
            osagent = new OSSolverAgent(oscommandline->serviceLocation);
            // check to see if there is an osol
            if (oscommandline->osol == "")
            {
                // we need to construct the OSoL
                OSOption *osOption = NULL;
                osOption = new OSOption();
                // get a jobId if necessary
                if(oscommandline->jobID == "") oscommandline->jobID = osagent->getJobID("");
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
            bSend = osagent->send(oscommandline->osil, oscommandline->osol);
            if(bSend == true)
                osoutput->OSPrint(ENUM_OUTPUT_AREA_main, ENUM_OUTPUT_LEVEL_info, "Successful send");
            else
                osoutput->OSPrint(ENUM_OUTPUT_AREA_main, ENUM_OUTPUT_LEVEL_error, 
                    "Send failed, check to make sure you sent a jobID not on the system.");
          
            delete osagent;
        }
        else
        {
            delete osagent;
            throw ErrorClass("please specify service location (url)");
        }
    }
    catch (const ErrorClass& eclass)
    {
        std::string osrl = "";
        FileUtil *fileUtil = NULL;
        fileUtil = new FileUtil();
        OSResult *osresult = NULL;
        OSrLWriter *osrlwriter = NULL;
        //first check to see if we already have OSrL,
        //if so don't create a new osresult object
        string::size_type  pos1 = eclass.errormsg.find( "<osrl");
        if(pos1 == std::string::npos)
        {
            osrlwriter = new OSrLWriter();
            osresult = new OSResult();
            osresult->setGeneralMessage(eclass.errormsg);
            osresult->setGeneralStatusType("error");
            osrl = osrlwriter->writeOSrL(osresult);
        }
        else
        {
            osrl = eclass.errormsg;
        }


        if (oscommandline->osrlFile != "")
            fileUtil->writeFileFromString(oscommandline->osrlFile, osrl);
        else
            osoutput->OSPrint(ENUM_OUTPUT_AREA_main, ENUM_OUTPUT_LEVEL_error, osrl);

        if(osresult != NULL)
        {
            delete osresult;
            osresult = NULL;
        }
        if(osrlwriter != NULL)
        {
            delete osrlwriter;
            osrlwriter = NULL;
        }
        delete fileUtil;
        fileUtil = NULL;
    }
}//end send

void retrieve(OSCommandLine *oscommandline)
{
    FileUtil *fileUtil = NULL;
    fileUtil = new FileUtil();
    std::string osrl = "";
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
                if(oscommandline->jobID == "")throw ErrorClass("there is no JobID");
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

            if (oscommandline->osrlFile != "")
            {
                fileUtil->writeFileFromString(oscommandline->osrlFile, osrl);

                std::ostringstream outStr;

                outStr.str("");
                outStr.clear();
                outStr << "Solver Result Written to File: " << oscommandline->osrlFile << endl;
                osoutput->OSPrint(ENUM_OUTPUT_AREA_main, ENUM_OUTPUT_LEVEL_info, outStr.str());
                if (oscommandline->browser != "")
                {
                    std::string str = oscommandline->browser + "  "
                                      + oscommandline->osrlFile;
                    const char *ch = &str[0];
                    std::system(ch);
                }
            }
            else
                osoutput->OSPrint(ENUM_OUTPUT_AREA_main, ENUM_OUTPUT_LEVEL_error, osrl);
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

        std::string osrl = "";
        OSResult *osresult = NULL;
        OSrLWriter *osrlwriter = NULL;
        //first check to see if we already have OSrL,
        //if so don't create a new osresult object
        string::size_type  pos1 = eclass.errormsg.find( "<osrl");
        if(pos1 == std::string::npos)
        {
            osrlwriter = new OSrLWriter();
            osresult = new OSResult();
            osresult->setGeneralMessage(eclass.errormsg);
            osresult->setGeneralStatusType("error");
            osrl = osrlwriter->writeOSrL(osresult);
        }
        else
        {
            osrl = eclass.errormsg;
        }

        if(osresult != NULL)
        {
            delete osresult;
            osresult = NULL;
        }
        if(osrlwriter != NULL)
        {
            delete osrlwriter;
            osrlwriter = NULL;
        }


        delete fileUtil;
        fileUtil = NULL;
    }
}//end retrieve

void kill(OSCommandLine *oscommandline)
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
                if(oscommandline->jobID == "")throw ErrorClass("there is no JobID");
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
                fileUtil->writeFileFromString(oscommandline->osplOutputFile,
                                              osplOutput);
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

        std::string osrl = "";
        OSResult *osresult = NULL;
        OSrLWriter *osrlwriter = NULL;
        //first check to see if we already have OSrL,
        //if so don't create a new osresult object
        string::size_type  pos1 = eclass.errormsg.find( "<osrl");
        if(pos1 == std::string::npos)
        {
            osrlwriter = new OSrLWriter();
            osresult = new OSResult();
            osresult->setGeneralMessage(eclass.errormsg);
            osresult->setGeneralStatusType("error");
            osrl = osrlwriter->writeOSrL(osresult);
        }
        else
        {
            osrl = eclass.errormsg;
        }


        if(osresult != NULL)
        {
            delete osresult;
            osresult = NULL;
        }
        if(osrlwriter != NULL)
        {
            delete osrlwriter;
            osrlwriter = NULL;
        }


        delete fileUtil;
        fileUtil = NULL;
    }
}//end kill

/** Some wrappers around routines that allow getting problem instances in other formats:
 *  .nl (from AMPL), GAMS, MPS format
 */

void getOSiLFromNl(OSCommandLine *oscommandline)
{
    try
    {
#ifdef COIN_HAS_ASL
        OSnl2OS *nl2os = NULL;
        nl2os = new OSnl2OS();
        nl2os->readNl(oscommandline->nlFile);
        nl2os->setOsol(oscommandline->osol);
        nl2os->createOSObjects();
        OSiLWriter *osilwriter = NULL;
        osilwriter = new OSiLWriter();
        std::string osil;
        osil = osilwriter->writeOSiL( nl2os->osinstance);
        oscommandline->osil = osil;
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
        osoutput->OSPrint(ENUM_OUTPUT_AREA_main, ENUM_OUTPUT_LEVEL_error, eclass.errormsg);
        throw ErrorClass(eclass.errormsg);
    }
}//getOSiLFromNl


void getOSiLFromGams(OSCommandLine *oscommandline)
{
    try
    {
#ifdef COIN_HAS_GAMSIO
        OSgams2osil *gams2osil = NULL;
        gams2osil = new OSgams2osil( oscommandline->gamsControlFile);
        gams2osil->createOSInstance();
        OSiLWriter *osilwriter = NULL;
        osilwriter = new OSiLWriter();
        std::string osil;
        osil = osilwriter->writeOSiL( gams2osil->osinstance);
        oscommandline->osil = osil;
        delete gams2osil;
        gams2osil = NULL;
        delete osilwriter;
        osilwriter = NULL;
#else
        throw ErrorClass(
            "trying to convert Gams control file to osil without GAMSUTILS configured");
#endif
    }
    catch (const ErrorClass& eclass)
    {
        osoutput->OSPrint(ENUM_OUTPUT_AREA_main, ENUM_OUTPUT_LEVEL_error, eclass.errormsg);
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
        std::string osil;
        osil = osilwriter->writeOSiL(mps2osil->osinstance);
        oscommandline->osil = osil;
        delete mps2osil;
        mps2osil = NULL;
        delete osilwriter;
        osilwriter = NULL;
    }
    catch (const ErrorClass& eclass)
    {
        osoutput->OSPrint(ENUM_OUTPUT_AREA_main, ENUM_OUTPUT_LEVEL_error, eclass.errormsg);
        throw ErrorClass(eclass.errormsg);
    }

}//getOSiLFromMps


/** ======================== Interactive shell ========================= **/

inline void getServiceLocation(OSCommandLine *oscommandline)
{
    std::cout
            << std::endl
            << "A service location is required"
            << std::endl;
    std::cout
            << "Please type the URL of the remote service: ";
    getline(std::cin, oscommandline->serviceLocation);
}
  
void interactiveShell()
{
    void* scanner;
    FileUtil *fileUtil = NULL;
    //char *config = "-config";
    std::string configFileName = "";


    OSCommandLine *oscommandline = new OSCommandLine();
    bool scannerActive = false;

    //this is the interactive shell
    scannerActive = true;
    ossslex_init(&scanner);
    setyyextra(oscommandline, scanner);
    std::string lineText;
    //use a blank to separate words
    std::string wordSep = " ";
    std::string dblQuote = "\"";
    std::string optionName = "";
    std::string optionValue = "";
    std::string::size_type indexStart;
    std::string::size_type indexEnd;
    unsigned int k;

    const int nCommands = 14;
    std::string commandArray[nCommands] = 
        { "solve", "send", "getJobID", "retrieve", "kill", "knock",
          "quit", "exit",  "reset", "list", "?", "help", "version", 
          "printModel"
        };

    const int nOptions = 14;
    std::string optionArray[nOptions] = 
        { "osil", "osrl", "osol", "mps", "nl", "dat",
          "serviceLocation", "solver", "osplInput",  "osplOutput", 
          "printRow", "printLevel", "logFile", "fileLogLevel"
        };

    //fill in the command array into a map

    std::map<string, int> commandMap;

    for(k = 0; k < nCommands; k++)
    {
        commandMap[ commandArray[ k] ] = k;
    }

    //fill in the option array into a map

    std::map<string, int> optionMap;

    for(k = 0; k < nOptions; k++)
    {
        optionMap[ optionArray[ k] ] = k;
    }

    std::cout << "At the prompt enter a valid command or option value pair.\n";
    std::cout << "Enter the \"solve\" command to optimize.\n";
    std::cout << "Type \"quit\" or \"exit\" to leave the application. \n";
    std::cout << "Type \"help\" or \"?\" for a list of valid options.\n\n";

    while (oscommandline->quit != true)
    {
        std::cout <<  "Please enter a command, or an option followed by an option value: ";
        getline(std::cin, lineText);
        lineText = " " + lineText + " ";
        //get the name of the option
        indexStart = lineText.find_first_not_of(wordSep);
        if (indexStart == string::npos)
        {
            std::cout << std::endl;
            std::cout << "You did not enter a valid option. "
                      << "Type \"help\" or \"?\" for a list of valid options."
                      << std::endl;
        }
        else
        {
            indexEnd = lineText.find_first_of(wordSep, indexStart + 1);
            optionName = lineText.substr(indexStart, indexEnd - indexStart);
            //std::cout << "Option Name = " << optionName << std::endl;

            if( (commandMap.find(optionName) == commandMap.end() ) &&
                 (optionMap.find(optionName) == optionMap.end() ) )
            {
                std::cout << std::endl;
                std::cout << "You did not enter a valid option. "
                          << "Type \"help\" or \"?\" for a list of valid options."
                          << std::endl;
            }
            else
            {
                int skipChars;
                // get the option value
                        
                indexStart = lineText.find_first_not_of(wordSep, indexEnd + 1);
                if (indexStart != std::string::npos && lineText[indexStart] == '\"')
                {
                    indexEnd = lineText.find_first_of(dblQuote, indexStart + 1);
                    skipChars = 1;
                }
                else
                {
                    indexEnd = lineText.find_first_of(wordSep, indexStart + 1);
                    skipChars = 0;
                }
                if (indexStart != std::string::npos && indexEnd != std::string::npos)
                {
                    optionValue = lineText.substr(indexStart + skipChars, 
                                                  indexEnd - indexStart - skipChars);
                }
                else
                {
                    optionValue = "";
                }

                //std::cout << "Option Value = " << optionValue << std::endl;

                try
                {
                    // first we process the commands
                    if( commandMap.find(optionName) != commandMap.end()  )
                    {
                        switch (commandMap[ optionName] )
                        {

                                case 0: // solve command

                                    if(oscommandline->osil == "" && oscommandline->mps == "" &&  oscommandline->nl == "")
                                    {
                                        std::cout
                                                << std::endl
                                                << "You did not specify an optimization instance!!!\n"
                                                << "Please enter file format option (osil, nl, or mps) \n"
                                                << "followed by the option value which is the file location. \n"
                                                << std::endl;
                                    }
                                    else
                                    {
                                        solve(oscommandline);
                                        if (oscommandline->osrlFile != "")
                                            std::cout <<  "\nSolve command executed. Please see " << oscommandline->osrlFile  << " for results." << std::endl;
                                    }
                                    break;

                                case 1: // send command

                                    if(oscommandline->serviceLocation == "")
                                        getServiceLocation(oscommandline);
                                    send(oscommandline);
                                    break;


                                case 2: // getJobID command

                                    if(oscommandline->serviceLocation == "")
                                        getServiceLocation(oscommandline);
                                    getJobID(oscommandline);
                                    break;


                                case 3: // retrieve command

                                    if(oscommandline->serviceLocation == "")
                                        getServiceLocation(oscommandline);

                                    if( (oscommandline->osolFile == "") && (oscommandline->jobID == "") )
                                    {
                                        std::cout
                                                << std::endl
                                                << "Cannot retrieve: no JobID and no OSoL file"
                                                << std::endl;
                                    }
                                    else
                                    {
                                        retrieve(oscommandline);
                                    }

                                    break;

                                case 4: // kill command


                                    if(oscommandline->serviceLocation == "")
                                        getServiceLocation(oscommandline);

									if( (oscommandline->osolFile == "") && (oscommandline->jobID == "") )
                                    {
                                        std::cout
                                                << std::endl
                                                << "Cannot kill: no JobID and no OSoL file"
                                                << std::endl;
                                    }
                                    else
                                    {
                                        kill(oscommandline);
                                    }


                                    break;


                                case 5: // knock command

                                    //note -- can have empty OSoL for knock
                                    //however we do need an OSpL file

                                    if(oscommandline->serviceLocation == "")
                                        getServiceLocation(oscommandline);

                                    if( oscommandline->osplInputFile == "")
                                    {
                                        std::cout
                                                << std::endl
                                                << "Cannot knock -- no OSplInputFile specified"
                                                << std::endl;
                                    }
                                    else
                                    {
                                        knock(oscommandline);
                                    }

                                    break;


                                case 6: // quit command

                                    return;



                                case 7: // exit command

                                    return;



                                case 8: // reset command

                                    oscommandline->reset_options();
                                    std::cout << "\nAll options reset.\n";
                                    break;



                                case 9: // list command

                                    list_options(oscommandline);
                                    break;


                                case 10: // ? command

                                    std::cout << get_options() << std::endl;
                                    break;


                                case 11: // help command

                                    std::cout << get_options() << std::endl;
                                    break;


                                case 12: // version command

                                    std::cout << OSgetVersionInfo() << std::endl;
                                    break;

									
								case 13: // printModel

                                    doPrintModel(oscommandline);
                                    break;


                                default:
                                    throw ErrorClass("we don't have a valid command");


                        } //end switch

                    }
                    else     // now in the case where we require option values
                    {

                        if (optionValue == "")
                        {

                            if(optionMap.find(optionName) != optionMap.end() )
                            {

                                switch (optionMap[ optionName] )
                                {

                                        case 0: //osil
                                            std::cout
                                                    << "Please enter the name of an osil file: ";
                                            break;


                                        case 1: //osrl
                                            std::cout
                                                    << "Please enter the name of an osrl file: ";
                                            break;

                                        case 2: //osol
                                            std::cout
                                                    << "Please enter the name of an osol file: ";
                                            break;

                                        case 3: //mps
                                            std::cout
                                                    << "Please enter the name of an mps file: ";
                                            break;

                                        case 4: //nl
                                            std::cout
                                                    << "Please enter the name of an AMPL nl file: ";
                                            break;

                                        case 5: //dat
                                            std::cout
                                                    << "Please enter the name of a dat file: ";
                                            break;

                                        case 6: //service location
                                            std::cout
                                                    << "Please enter the serviceLocation: ";
                                            break;

                                        case 7: //solver
                                            std::cout
                                                    << "Please enter the name of the solver: ";
                                            break;

                                        case 8: //osplInput
                                            std::cout
                                                    << "Please enter the name of an osplInput file: ";
                                            break;

                                        case 9: //osplOutput
                                            std::cout
                                                    << "Please enter the name of an osplOutput file: ";
                                            break;

                                        case 10: //printRow
                                            std::cout
                                                    << "Please enter the number of a constraint (>=0) or objective (<0): ";
                                            break;

                                        case 11: //printLevel
                                            std::cout
                                                    << "Please enter the print level (0-" 
                                                    << ENUM_OUTPUT_LEVEL_NUMBER_OF_LEVELS << "): ";
                                            break;

                                        case 12: //logFile
                                            std::cout
                                                    << "Please enter the name of the log file: ";
                                            break;

                                        case 13: //filePrintLevel
                                            std::cout
                                                    << "Please enter the print level (0-" 
                                                    << ENUM_OUTPUT_LEVEL_NUMBER_OF_LEVELS << "): ";
                                            break;


                                }// end switch
                                
                                // now get the option value
                                getline(std::cin, lineText);

                                int skipChars;

                                indexStart = lineText.find_first_not_of(wordSep, 0);
                                if (lineText[indexStart] == '\"')
                                {
                                    indexEnd = lineText.find_first_of(dblQuote, indexStart + 1);
                                    skipChars = 1;
                                }
                                else
                                {
                                    indexEnd = lineText.find_first_of(wordSep, indexStart + 1);
                                    skipChars = 0;
                                }
                                if (indexStart != std::string::npos && indexEnd != std::string::npos)
                                {
                                    optionValue = lineText.substr(indexStart + skipChars, 
                                                                  indexEnd - indexStart - skipChars);
                                }
                                else
                                {
                                    optionValue = "";
                                }


                            }// end if on finding an element in the optionMap

                        } // end if on whether or not option value is null


                        if(optionMap.find(optionName) != optionMap.end() )
                        {
 				            switch (optionMap[ optionName] )
                            {

                                    case 0: //osil
                                        oscommandline->osilFile = optionValue;
                                        oscommandline->osil
                                            = fileUtil->getFileAsString(
                                                  (oscommandline->osilFile).c_str());
                                        break;


                                    case 1: //osrl
                                        oscommandline->osrlFile = optionValue;
                                        break;

                                    case 2: //osol
                                        oscommandline->osolFile = optionValue;
                                        oscommandline->osol
                                            = fileUtil->getFileAsString(
                                                  (oscommandline->osolFile).c_str());
                                        break;

                                    case 3: //mps
                                        oscommandline->mpsFile = optionValue;
                                        oscommandline->mps
                                            = fileUtil->getFileAsString(
                                                  (oscommandline->mpsFile).c_str());
                                        break;

                                    case 4: //nl
                                        oscommandline->nlFile = optionValue;
                                        oscommandline->nl
                                            = fileUtil->getFileAsString(
                                                  (oscommandline->nlFile).c_str());
                                        break;

                                    case 5: //dat
                                        oscommandline->datFile = optionValue;
                                        oscommandline->dat
                                            = fileUtil->getFileAsString(
                                                  (oscommandline->datFile).c_str());
                                        break;

                                    case 6: //service location
                                        oscommandline->serviceLocation = optionValue;
                                        break;

                                    case 7: //solver

                                        //make solver name lower case 
                                        for (k = 0; k
                                                < oscommandline->solverName.length(); k++)
                                        {
                                            oscommandline->solverName[k] = 
                                                (char)tolower(oscommandline->solverName[k]);
                                        }
                                        oscommandline->solverName = optionValue;
                                        break;

                                    case 8: //osplInput
                                        oscommandline->osplInputFile = optionValue;
                                        oscommandline->osplInput
                                            = fileUtil->getFileAsString(
                                                  (oscommandline->osplInputFile).c_str());
                                        break;

                                    case 9: //osplOutput
                                        oscommandline->osplOutputFile = optionValue;
                                        break;

                                    case 10: //printRow
                                        oscommandline->printRowNumberAsString = optionValue;
                    					doPrintRow(oscommandline);
                                        break;

                                    case 11: //printLevel
                                        std::cout
                                                << "Please enter the print level (0-" 
                                                << ENUM_OUTPUT_LEVEL_NUMBER_OF_LEVELS << "): ";
                                        break;

                                    case 12: //logFile
                                        std::cout
                                                << "Please enter the name of the log file: ";
                                        break;

                                    case 13: //filePrintLevel
                                            std::cout
                                                    << "Please enter the print level (0-" 
                                                    << ENUM_OUTPUT_LEVEL_NUMBER_OF_LEVELS << "): ";
                                            break;

                            }// end switch
                            list_options( oscommandline);

                        }// end if on finding an element in the optionMap

                    } // end if on options that require a value

                    std::cout << std::endl;
                }//end try
                catch (const ErrorClass& eclass)
                {
                    std::cout << eclass.errormsg << std::endl;
                }
            }
        }
    }//end while loop
    ossslex_destroy(scanner);
    scannerActive = false;
    delete oscommandline;
    oscommandline = NULL;
    delete fileUtil;
    fileUtil = NULL;
} // end of interactiveShell

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


std::string get_version()
{
    std::ostringstream versionMsg;
    versionMsg << "In order to find the version of this project " << endl;
    versionMsg << "connect to the directory where you downloaded " << endl;
    versionMsg << "and do: " << endl;
    versionMsg << "svn info " << endl;

    return versionMsg.str();
}// get version

std::string get_options()
{
    std::ostringstream optionMsg;

    optionMsg << endl;

    optionMsg
            << "***************** VALID COMMANDS AND OPTIONS ********************"
            << endl ;
    optionMsg
            << "COMMANDS:"
            << endl;
    optionMsg
            << "quit/exit -- terminate the executable"
            << endl;
    optionMsg
            << "help/? -- produce this list of options"
            << endl;
    optionMsg
            << "reset -- erase all previous option settings"
            << endl	;
    optionMsg
            << "list -- list the current option values"
            << endl	;
    optionMsg
            << "solve -- call the solver synchronously"
            << endl ;
    optionMsg
            << "send -- call the solver asynchronously"
            << endl ;
    optionMsg
            << "kill -- end a job on the remote server"
            << endl ;
    optionMsg
            << "retrieve -- get job result on the remote server"
            << endl ;
    optionMsg
            << "knock -- get job information on the remote server"
            << endl ;
    optionMsg
            << "getJobID -- get a job ID from the remote server"
            << endl << endl;


    optionMsg
            << "OPTIONS (THESE REQUIRE A VALUE):"
            << endl;
    optionMsg
            << "osil -- the location of the model instance in OSiL format"
            << endl;
    optionMsg
            << "mps  -- the location of the model instance in MPS format"
            << endl	;
    optionMsg
            << "nl -- the location of the model instance in AMPL nl format"
            << endl;
    optionMsg
            << "osol -- the location of the solver option file in OSoL format"
            << endl;
    optionMsg
            << "osrl -- the location of the solver result file in OSrL format"
            << endl;
    optionMsg
            << "osplInput -- the name of an input file in OSpL format"
            << endl;
    optionMsg
            << "osplOutput --  the name of an output file in the OSpL format"
            << endl	;
    optionMsg
            << "serviceLocation -- the  URL of a remote solver service"
            << endl;
    optionMsg
            << "solver -- specify the solver to invoke"
            << endl <<endl;
    optionMsg
            << "See  http://www.coin-or.org/OS/"
            << endl;
    optionMsg
            << "for more detail on how to use the OS project."
            << endl << endl;

	optionMsg
            << "PRINT OPTIONS:"
            << endl;
	optionMsg
            << "printModel -- print the currently defined model"
            << endl;
	optionMsg
            << "printRow nnn -- print row n of the currently defined model"
            << endl;
	optionMsg
            << "   if nnn >= 0, prints a constraint, otherwise prints an objective row"
            << endl;
	optionMsg
            << "printLevel nnn -- control the amount of output sent to stdout"
            << endl;
    optionMsg 
            << "   valid values are 0..";
#ifdef NDEBUG
    optionMsg << ENUM_OUTPUT_LEVEL_info << endl; 
#else
    optionMsg << ENUM_OUTPUT_LEVEL_detailed_trace << endl; 
#endif
	optionMsg
            << "logFile --- a secondary output device"
            << endl;
	optionMsg
            << "filePrintLevel nnn -- control the amount of output sent to the secondary output device"
            << endl;
    optionMsg 
            << "   valid values are 0..";
#ifdef NDEBUG
    optionMsg << ENUM_OUTPUT_LEVEL_info << endl; 
#else
    optionMsg << ENUM_OUTPUT_LEVEL_detailed_trace << endl; 
#endif
    optionMsg << endl;

    optionMsg
            << "*****************************************************************"
            << endl << endl;
    optionMsg
            << "At the prompt enter a valid command or option value pair."
            << endl;
    optionMsg
            << "Enter the \"solve\" command to optimize."
            << endl;
    optionMsg
            << "Type \"quit/exit\" to leave the application."
            << endl;
    optionMsg
            << "Type \"help\" or \"?\" for a list of valid options."
            << endl;


    return optionMsg.str();
}// get_options


void list_options(OSCommandLine *oscommandline)
{
    cout
            << "HERE ARE THE OPTION VALUES SO FAR:"
            << endl;
    if (oscommandline->configFile != "")
        cout << "Config file = "
             << oscommandline->configFile
             << endl;
    if (oscommandline->osilFile != "")
        cout << "OSiL file = "
             << oscommandline->osilFile
             << endl;
    if (oscommandline->osolFile != "")
        cout << "OSoL file = "
             << oscommandline->osolFile
             << endl;
    if (oscommandline->osrlFile != "")
        cout << "OSrL file = "
             << oscommandline->osrlFile
             << endl;
//if(oscommandline->insListFile != "") cout << "Instruction List file = " << oscommandline->insListFile << endl;
    if (oscommandline->osplInputFile != "")
        cout << "OSpL Input file = "
             << oscommandline->osplInputFile
             << endl;
    if (oscommandline->serviceMethod != "")
        cout << "Service Method = "
             << oscommandline->serviceMethod
             << endl;
    if (oscommandline->mpsFile != "")
        cout << "MPS File Name = "
             << oscommandline->mpsFile
             << endl;
    if (oscommandline->nlFile != "")
        cout << "NL File Name = "
             << oscommandline->nlFile
             << endl;
    if (oscommandline->solverName != "")
        cout << "Selected Solver = "
             << oscommandline->solverName
             << endl;
    if (oscommandline->serviceLocation != "")
        cout << "Service Location = "
             << oscommandline->serviceLocation
             << endl;

    if (oscommandline->jobID != "")
        cout << "Job ID = "
             << oscommandline->jobID
             << endl;
}// list_options

void doPrintModel(OSCommandLine *oscommandline)
{
	if (oscommandline->osil == "" && oscommandline->mps == "" &&  oscommandline->nl == "")
	{
		std::cout
			<< "no instance defined; print command ignored" << std::endl;
	}
	else
	{
		if (oscommandline->osil != "")
		{
			OSiLReader *osilreader;
			osilreader = new OSiLReader();
			std::cout << osilreader->readOSiL(oscommandline->osil)->printModel() << std::endl;
			delete osilreader;
			osilreader = NULL;
		}
		else if (oscommandline->nl != "")
		{
#ifdef COIN_HAS_ASL
			OSnl2OS *nl2os;	
//			nl2os = new OSnl2OS( oscommandline->nlFile, oscommandline->osol);
			nl2os = new OSnl2OS();
            nl2os->readNl(oscommandline->nlFile);
            nl2os->setOsol(oscommandline->osol);
			nl2os->createOSObjects();
			std::cout << nl2os->osinstance->printModel() << std::endl;
			delete nl2os;
			nl2os = NULL;
#else
			std::cout << "no ASL present to read nl file; print command ignored" << std::endl; 
#endif
		}
		else if (oscommandline->mps != "")
		{
			OSmps2osil *mps2osil;
			mps2osil = new OSmps2osil(oscommandline->mpsFile);
			mps2osil->createOSInstance();
			std::cout << mps2osil->osinstance->printModel() << std::endl;
			delete mps2osil;
			mps2osil = NULL;
		}
	}
}// doPrintModel(OSCommandLine *oscommandline)

void doPrintModel(OSInstance *osinstance)
{
	if (osinstance == NULL)
	{
		std::cout
			<< "no instance defined; print command ignored" << std::endl;
	}
	else
	{
		std::cout << osinstance->printModel() << std::endl;
	}
}// doPrintModel(OSInstance *osinstance)

void doPrintRow(OSCommandLine *oscommandline)
{
	int rownumber;
	if (oscommandline->printRowNumberAsString == "")
		std::cout << "no line number given; print command ignored" << std::endl;
	else
	{
		try
		{
			rownumber = atoi((oscommandline->printRowNumberAsString).c_str());
		}
		catch  (const ErrorClass& eclass)
		{
	                std::cout << "invalid row number; print command ignored" << std::endl;
		}

		if (oscommandline->osil == "" && oscommandline->mps == "" &&  oscommandline->nl == "")
                {
                        std::cout
	                        << "no instance defined; print command ignored" << std::endl;
		}
		else
		{
			std::cout << std::endl << "Row " << rownumber << ":" << std::endl << std::endl;
			if (oscommandline->osil != "")
			{
				OSiLReader *osilreader;
				osilreader = new OSiLReader();
		    		std::cout << osilreader->readOSiL(oscommandline->osil)->printModel(rownumber) << std::endl;
				delete osilreader;
				osilreader = NULL;
			}
			else if (oscommandline->nl != "")
			{
#ifdef COIN_HAS_ASL
				OSnl2OS *nl2os;	
//				nl2os = new OSnl2OS(oscommandline->nlFile, oscommandline->osol);
				nl2os = new OSnl2OS();
                nl2os->readNl(oscommandline->nlFile);
                nl2os->setOsol(oscommandline->osol);
				nl2os->createOSObjects();
				std::cout << nl2os->osinstance->printModel(rownumber) << std::endl;
				delete nl2os;
				nl2os = NULL;
#else
				std::cout << "no ASL present to read nl file; print command ignored" << std::endl; 
#endif
			}
			else if (oscommandline->mps != "")
			{
				OSmps2osil *mps2osil;
				mps2osil = new OSmps2osil(oscommandline->mpsFile);
				mps2osil->createOSInstance();
				std::cout << mps2osil->osinstance->printModel(rownumber) << std::endl;
				delete mps2osil;
				mps2osil = NULL;
			}
		}
	}
}// doPrintRow(OSCommandLine *oscommandline)

void doPrintRow(OSInstance *osinstance, std::string rownumberstring)
{
	int rownumber;
	if (rownumberstring == "")
		std::cout << "no line number given; print command ignored" << std::endl;
	else
	{
		try
		{
			rownumber = atoi((rownumberstring).c_str());
		}
		catch  (const ErrorClass& eclass)
		{
	                std::cout << "invalid row number; print command ignored" << std::endl;
		}

		if (osinstance == NULL)
                {
                        std::cout
	                        << "no instance defined; print command ignored" << std::endl;
		}
		else
		{
			std::cout << std::endl << "Row " << rownumber << ":" << std::endl << std::endl;
	    		std::cout << osinstance->printModel(rownumber) << std::endl;
		}
	}
}// doPrintRow(OSInstance *osinstance, std::string rownumberstring)

