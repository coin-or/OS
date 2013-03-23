//Id: OSSolverService.cpp 3561 2010-06-24 19:27:07Z kmartin $
/** @file OSSolverService.cpp
 *
 * @author  Horand Gassmann, Jun Ma, Kipp Martin
 *
 * \remarks
 * Copyright (C) 2005-2013, Horand Gassmann, Jun Ma, Kipp Martin,
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
 *          instance must be specified in the osol file)
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
 *          parameters
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

#define MPS_PTR OSmps2osil

#ifdef COIN_HAS_ASL
#include "OSnl2OS.h"
#define AMPL_PTR OSnl2OS
#else
#define AMPL_PTR void
#endif

#ifdef COIN_HAS_GAMSUTILS
#include "OSgams2osil.hpp"
#define GAMS_PTR OSgams2osil
#else
#define GAMS_PTR void
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
#include "OSCommandLineReader.h"

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
bool findInstance(OSCommandLine *oscommandline, MPS_PTR *mps2osil, AMPL_PTR *osnl2os, GAMS_PTR *gams2osil);
void makeStrings( OSCommandLine *oscommandline);
void doPrintModel(OSCommandLine *oscommandline);
void doPrintModel(OSInstance *osinstance);
void doPrintRow(OSCommandLine *oscommandline);
void doPrintRow(OSInstance *osinstance, std::string rownumberstring);
void reportResults(OSCommandLine *oscommandline, std::string osrl);
void reportErrors(OSCommandLine *oscommandline, std::string errMsg);

extern const SmartPtr</*const*/ OSOutput> osoutput;

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
    char osss[MAXCHARS] = " ";
    const char *space = " ";
    const char *quote = "\"";
    std::string configFileName = "";
    int i;

    /** Parse the command line **/
     
    // initialize the command line structure 

//    osoptions = new osOptionsStruc();
    OSCommandLine *oscommandline = new OSCommandLine();
    OSCommandLineReader *oscommandlinereader = new OSCommandLineReader();
    bool scannerActive = false;
    ostringstream echo_cl;
        
    try
    {
        
        // Assemble the command line arguments into a single string
        std::ostringstream osssStr;
        bool addQuotes;
        for (i=1; i < argC; i++)
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
                osssStr << '\"';
            osssStr << argV[i];
            if (addQuotes) 
                osssStr << '\"';
            osssStr << " ";
        }

        // this output must be held in abeyance until the command line
        // has been processed and printLevel has been set
#ifndef NDEBUG
        echo_cl.str("");
        echo_cl.clear();
        echo_cl << "Command line = " << osssStr.str() << std::endl;
#endif

        oscommandline = oscommandlinereader->readCommandLine((osssStr.str()).c_str());
    }
    catch (const ErrorClass& eclass)
    {
        reportErrors(oscommandline, eclass.errormsg);
        delete fileUtil;
        fileUtil = NULL;
        delete oscommandlinereader;
        oscommandlinereader = NULL;
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

#ifndef NDEBUG
            osoutput->OSPrint(ENUM_OUTPUT_AREA_main, ENUM_OUTPUT_LEVEL_trace, echo_cl.str());
#else
            osoutput->OSPrint(ENUM_OUTPUT_AREA_main, ENUM_OUTPUT_LEVEL_info, outStr.str());
#endif
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
                osoutput->OSPrint(ENUM_OUTPUT_AREA_main, ENUM_OUTPUT_LEVEL_info, outStr.str());
            }
#ifndef NDEBUG
            else
            {
                osoutput->OSPrint(ENUM_OUTPUT_AREA_main, ENUM_OUTPUT_LEVEL_debug, outStr.str());
            }
#endif
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
        reportErrors(oscommandline, eclass.errormsg);
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

    // read the data from the schema files
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
        reportErrors(oscommandline, outStr.str());

        delete oscommandlinereader;
        oscommandlinereader = NULL;
        delete fileUtil;
        fileUtil = NULL;
        return 1;
    }

/** We use shallow copy of the osinstance components
 *  (mostly pointers to MPS, AMPL, GAMS versions 
 *  of the linear coefficient matrix if no OSiL file)
 *  and thus must declare these pointers here so that 
 *  they are not destroyed prematurely.
 */
     MPS_PTR *mps  = NULL;
    AMPL_PTR *ampl = NULL;
    GAMS_PTR *gams = NULL;

    OSiLReader* osilreader = new OSiLReader(); 

    // the default serviceMethod is solve
    if (oscommandline->serviceMethod == "") oscommandline->serviceMethod = "solve";

    try
    {
        // for local use only the solve method is available
        if (oscommandline->serviceLocation == "")
            if (oscommandline->serviceMethod != "solve") 
                throw ErrorClass("No serviceLocation given. Only \'solve\' is available locally.");

        // now call the correct serviceMethod
        if (oscommandline->serviceMethod[0] == 's')
        {
            // for solve or send commands we must have an instance
            if (oscommandline->osil == "")
            {
                if (!findInstance(oscommandline, mps, ampl, gams))
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
                reportResults(oscommandline, osrl);
            }
    
            // remote solve or send
            else
            {
                if (oscommandline->serviceMethod[1] == 'e')
                    send(oscommandline);
                else
                    solve(oscommandline);
            }
        }

        else //call one of the other methods
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

        // garbage collection
#ifndef NDEBUG
        osoutput->OSPrint(ENUM_OUTPUT_AREA_main, ENUM_OUTPUT_LEVEL_trace, "Initiate garbage collection in main()"); 
#endif
        if (osilreader != NULL)
        {
            delete osilreader;
            oscommandline->osinstance = NULL;
        }
        osilreader = NULL;
        delete oscommandlinereader;
        oscommandlinereader = NULL;
        delete fileUtil;
        fileUtil = NULL;
        if (mps != NULL)
            delete mps;
        mps = NULL;
#ifdef COIN_HAS_ASL
        if (ampl != NULL)
            delete ampl;
        ampl = NULL;
#endif

#ifdef COIN_HAS_GAMSUTILS
        if (gams != NULL)
            delete gams;
        gams = NULL;
#endif
#ifndef NDEBUG
        osoutput->OSPrint(ENUM_OUTPUT_AREA_main, ENUM_OUTPUT_LEVEL_trace, "Garbage collection in main() completed"); 
#endif
        return 0;
    }

    catch (const ErrorClass& eclass)
    {
        reportErrors(oscommandline, eclass.errormsg);
        if (osilreader != NULL)
            delete osilreader;
            oscommandline->osinstance = NULL;
        osilreader = NULL;
        delete oscommandlinereader;
        oscommandlinereader = NULL;
        delete fileUtil;
        fileUtil = NULL;
        if (mps != NULL)
            delete mps;
        mps = NULL;
#ifdef COIN_HAS_ASL
        if (ampl != NULL)
            delete ampl;
        ampl = NULL;
#endif

#ifdef COIN_HAS_GAMSUTILS
        if (gams != NULL)
            delete gams;
        gams = NULL;
#endif
        return 1;
    }
}// end of main()


/** This method tries to find an alternate location of the instance 
 *  if an OSiL file was not given  
 *  Other formats tried (in this order):
 *  MPS file, AMPL .nl file, GAMS .dat file
 *  If no files are found, then an instance could still be given
 *  in an OSoL file --- provided that the method is a remote solve or send
 *  If no instance can be located, throw an error
 *  @param oscommandline: contains the information processed so far
 *  @return whether an instance was found or not
 */
bool findInstance(OSCommandLine *oscommandline, MPS_PTR *mps2osil, AMPL_PTR *nl2os, GAMS_PTR *gams2osil)
{
    FileUtil *fileUtil = NULL;
    fileUtil = new FileUtil();

/**
 *  OSiL files are simply read into oscommandline->osil in the calling program.
 *  Other file formats (MPS, AMPL .nl, GAMS .dat files) will be processed here 
 *  and parsed into an osinstance object.
 */
    try
    {
        if (oscommandline->osil != "" || oscommandline->osinstance != NULL)
            return true;

        // here we have MPS format
        else if (oscommandline->mpsFile != "")
        {
            mps2osil = new OSmps2osil(oscommandline->mpsFile);
            mps2osil->createOSInstance();
            oscommandline->osinstance = mps2osil->osinstance;
        }

        // here we have AMPL format
        else if (oscommandline->nlFile != "")
        {
#ifdef COIN_HAS_ASL
            nl2os = new OSnl2OS();
            if (!nl2os->readNl(oscommandline->nlFile))
                throw ErrorClass("Error reading .nl file.");
            nl2os->setOsol(oscommandline->osol);
            nl2os->setJobID(oscommandline->jobID);
            nl2os->createOSObjects() ;
            oscommandline->osinstance = nl2os->osinstance;
#else
            throw ErrorClass("nl file specified locally but ASL not present");
#endif
        }

        // here we have GAMS format
        else if (oscommandline->gamsControlFile != "")
        {
#ifdef COIN_HAS_GAMSUTILS
            gams2osil = NULL;
            gams2osil = new OSgams2osil( oscommandline->gamsControlFile);
            gams2osil->createOSInstance();
            oscommandline->osinstance = gams2osil->osinstance;
#else
        throw ErrorClass(
            "trying to convert Gams control file to osil without GAMSUTILS configured");
#endif
        }

        else // if this is a local solve, throw an error
        {
            if (oscommandline->serviceLocation == "")
                throw ErrorClass(
                    "Error: no osil, MPS, AMPL nl, or GAMS dat file given for a local solve --- \n NOTE: information in the osol file is ignored for local solves.");

            //if this is a remote solve or send, then the osol file might contain an instance
            else if (oscommandline->osol == "")
                throw ErrorClass(
                    "Error: no instance could be found.");
        }
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

void solve(OSCommandLine *oscommandline)
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

        reportResults(oscommandline, osrl);

        //garbage collection
        delete fileUtil;
        fileUtil = NULL;

    }//end try
    catch (const ErrorClass& eclass)
    {
        reportErrors(oscommandline, eclass.errormsg);

        //garbage collection
        delete fileUtil;
        fileUtil = NULL;
    }//end local catch

}//end solve 


void send(OSCommandLine *oscommandline)
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
        reportErrors(oscommandline, eclass.errormsg);
        if (osagent != NULL)
            delete osagent;
        osagent = NULL;
    }
}//end send

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
        reportErrors(oscommandline, eclass.errormsg);
        if (osagent != NULL)
            delete osagent;
        osagent = NULL;
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
         reportErrors(oscommandline, eclass.errormsg);
        if (osagent != NULL)
            delete osagent;

        osagent = NULL;

        delete fileUtil;
        fileUtil = NULL;
    }
}//end knock

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
            reportResults(oscommandline, osrl);
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
        reportErrors(oscommandline, eclass.errormsg);
        if (osagent != NULL)
            delete osagent;
        osagent = NULL;

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
        reportErrors(oscommandline, eclass.errormsg);
        if (osagent != NULL)
            delete osagent;
        osagent = NULL;

        delete fileUtil;
        fileUtil = NULL;
    }
}//end kill



/** Deal with the OSrL output generated by the call to one of the service methods
 */
void reportResults(OSCommandLine *oscommandline, std::string osrl)
{
    if (oscommandline->osrlFile != "")
    {
        FileUtil* fileUtil = new FileUtil();
        fileUtil->writeFileFromString(oscommandline->osrlFile, osrl);
        if (oscommandline->browser != "")
        {
            std::string str = oscommandline->browser + "  "
                              + oscommandline->osrlFile;
            const char *ch = &str[0];
            std::system(ch);
        }
        delete fileUtil;
        fileUtil = NULL;
    }
    else
    {
        osoutput->OSPrint(ENUM_OUTPUT_AREA_main, ENUM_OUTPUT_LEVEL_error, osrl);
    }
}// reportResults

/** Deal with any error messages generated by the call to one of the service methods
 */
void reportErrors(OSCommandLine *oscommandline, std::string errormsg)
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
        reportResults(oscommandline, osrl);
}// reportErrors



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
    std::string configFileName = "";


    OSCommandLine *oscommandline = new OSCommandLine();
    OSiLReader *osilreader = NULL;
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

    const int nOptions = 16;
    std::string optionArray[nOptions] = 
        { "osil", "osrl", "osol", "mps", "nl", "dat",
          "serviceLocation", "solver", "osplInput",  "osplOutput", 
          "printRow", "printLevel", "logFile", "fileLogLevel",
          "osilOutput", "osolOutput"
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

/** We use shallow copy of the osinstance components
 *  (mostly pointers to MPS, AMPL, GAMS versions 
 *  of the linear coefficient matrix if no OSiL file)
 *  and thus must declare these pointers here so that 
 *  they are not destroyed prematurely.
 */
     MPS_PTR *mps  = NULL;
    AMPL_PTR *ampl = NULL;
    GAMS_PTR *gams = NULL;



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

                                    if(oscommandline->osil == "")
                                    {
                                        if (!findInstance(oscommandline, mps, ampl, gams))
                                        {                                        
                                            std::cout
                                                << std::endl
                                                << "You did not specify an optimization instance!!!\n"
                                                << "Please enter file format option (osil, nl, or mps) \n"
                                                << "followed by the option value, which is the file location. \n"
                                                << std::endl;    
                                            break;
                                        }
                                    }
                                    if (oscommandline->serviceLocation == "")
                                    {   
                                        std::string osrl;
                                        if (oscommandline->osinstance != NULL)
                                            if (oscommandline->osoption != NULL)
                                                osrl = runSolver(oscommandline->solverName, 
                                                                 oscommandline->osoption, oscommandline->osinstance);
                                            else
                                                osrl = runSolver(oscommandline->solverName, 
                                                                 oscommandline->osol, oscommandline->osinstance);
                                        else
                                            if (oscommandline->osoption != NULL)
                                                osrl = runSolver(oscommandline->solverName, 
                                                                 oscommandline->osoption, oscommandline->osil);
                                            else
                                                osrl = runSolver(oscommandline->solverName,
                                                                 oscommandline->osol, oscommandline->osil);
                                        reportResults(oscommandline, osrl);
                                    }
                                    else
                                    {
                                        //makeStrings(oscommandline);
                                        solve(oscommandline);
                                    }
                                    if (oscommandline->osrlFile != "")
                                        std::cout << "\nSolve command executed. Please see " 
                                                  << oscommandline->osrlFile  << " for results." << std::endl;
                                    break;

                                case 1: // send command

                                    if(oscommandline->serviceLocation == "")
                                        getServiceLocation(oscommandline);

                                    if(oscommandline->osil == "")
                                    {
                                        if (!findInstance(oscommandline, mps, ampl, gams))
                                        {                                        
                                            std::cout
                                                << std::endl
                                                << "You did not specify an optimization instance!!!\n"
                                                << "Please enter file format option (osil, nl, or mps) \n"
                                                << "followed by the option value, which is the file location. \n"
                                                << std::endl;    
                                            break;
                                        }
                                    }
                                    //makeStrings(oscommandline);
                                    send(oscommandline);
                                    if (oscommandline->osrlFile != "")
                                        std::cout << "\nSolve command executed. Please see " 
                                                  << oscommandline->osrlFile  << " for results." << std::endl;

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
                                                << "Cannot knock -- no OSplInputFile specificed"
                                                << std::endl;
                                    }
                                    else
                                    {
                                        knock(oscommandline);
                                    }

                                    break;


                                case 6: // quit command

                                    if (osilreader != NULL)
                                        delete osilreader;
                                    return;



                                case 7: // exit command

                                    if (osilreader != NULL)
                                        delete osilreader;
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

                                    if (oscommandline->osinstance == NULL)
                                    {
                                        if (oscommandline->osil != "")
                                        {
                                            osilreader = new OSiLReader();
                                            oscommandline->osinstance = osilreader->readOSiL(oscommandline->osil);
                                        }    
                                        else
                                            if (!findInstance(oscommandline, mps, ampl, gams))
                                            {
                                                std::cout << "No instance defined. PrintModel ignored" << std::endl;
                                                break;
                                            }
                                    }
                                    doPrintModel(oscommandline->osinstance);
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

                                        case 14: //osilOutput
                                            std::cout
                                                    << "Please enter the name of an osilOutput file: ";
                                            break;

                                        case 15: //osolOutput
                                            std::cout
                                                    << "Please enter the name of an osolOutput file: ";
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

                                        if (oscommandline->osinstance == NULL)
                                        {
                                            if (oscommandline->osil != "")
                                            {
                                                osilreader = new OSiLReader();
                                                oscommandline->osinstance = osilreader->readOSiL(oscommandline->osil);
                                            }    
                                            else
                                                if (!findInstance(oscommandline, mps, ampl, gams))
                                                {
                                                    std::cout << "No instance defined. PrintRow ignored" << std::endl;
                                                    break;
                                                }
                                        }
                                        doPrintRow(oscommandline->osinstance, oscommandline->printRowNumberAsString);
                                        break;

                                    case 11: //printLevel
                                        if (oscommandline->printLevel != DEFAULT_OUTPUT_LEVEL)
                                        {
                                            osoutput->SetPrintLevel("stdout", 
                                                    (ENUM_OUTPUT_LEVEL)oscommandline->printLevel);
                                        }
                                        break;

                                    case 12: //logFile
                                        if (oscommandline->logFile != "")
                                        {
                                            int status = osoutput->AddChannel(oscommandline->logFile);
 
                                            switch(status)
                                            {
                                                case 0:
                                                    break;          
                                                case 1:
                                                    std::cout << "Output channel " << oscommandline->logFile 
                                                              << " previously defined" << std::endl;
                                                    break;
                                                default:
                                                    std::cout << "Could not add output channel " 
                                                              << oscommandline->logFile << std::endl;
                                            }//end switch
                                        }
                                        break;

                                    case 13: //filePrintLevel
                                        if (oscommandline->filePrintLevel != DEFAULT_OUTPUT_LEVEL)
                                        {
                                            osoutput->SetPrintLevel(oscommandline->logFile,
                                                    (ENUM_OUTPUT_LEVEL)oscommandline->filePrintLevel);
                                        }
                                        break;

                                    case 14: //osilOutput
                                        oscommandline->osilOutputFile = optionValue;
                                        break;

                                    case 15: //osolOutput
                                        oscommandline->osolOutputFile = optionValue;
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
        if (mps != NULL)
            delete mps;
        mps = NULL;

#ifdef COIN_HAS_ASL
        if (ampl != NULL)
            delete ampl;
        ampl = NULL;
#endif

#ifdef COIN_HAS_GAMSUTILS
        if (gams != NULL)
            delete gams;
        gams = NULL;
#endif
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
            << endl    ;
    optionMsg
            << "list -- list the current option values"
            << endl    ;
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
            << endl    ;
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
            << endl    ;
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

void doPrintModel(std::string osil)
{
    if (osil == "")
        std::cout << "no instance defined; print command ignored" << std::endl;
    else
    {
        OSiLReader *osilreader;
        osilreader = new OSiLReader();
        osoutput->OSPrint(ENUM_OUTPUT_AREA_main, ENUM_OUTPUT_LEVEL_always, 
            osilreader->readOSiL(osil)->printModel());
        delete osilreader;
        osilreader = NULL;
    }
}// doPrintModel(std::string osil)

void doPrintModel(OSInstance *osinstance)
{
    if (osinstance == NULL)
    {
        osoutput->OSPrint(ENUM_OUTPUT_AREA_main, ENUM_OUTPUT_LEVEL_always, 
            "no instance defined; print command ignored");
    }
    else
    {
        osoutput->OSPrint(ENUM_OUTPUT_AREA_main, ENUM_OUTPUT_LEVEL_always, 
            osinstance->printModel());
    }
}// doPrintModel(OSInstance *osinstance)


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

