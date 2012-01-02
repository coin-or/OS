//Id: OSSolverService.cpp 3561 2010-06-24 19:27:07Z kmartin $
/** @file OSSolverService.cpp
 *
 * @author  Horand Gassmann, Jun Ma, Kipp Martin
 *
 * \remarks
 * Copyright (C) 2005-2011, Horand Gassmann, Jun Ma, Kipp Martin,
 * Dalhousie University, Northwestern University, and the University of Chicago.
 * All Rights Reserved.
 * This software is licensed under the Eclipse Public License.
 * Please see the accompanying LICENSE file in root directory for terms.
 *
 * <b>INPUTS:</b>
 * <ul>
 * <li>
 * <b>-osil</b> xxx.osil (file name on local machine of optimization instance,
 *       this is NULL by default, however if this remains NULL a problem
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
 * <b>-serviceLocation</b> location URL (the URL  of the server that is called
 *       remotely if the problem not solved locally, default is NULL)
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
#include "OSConfig.h"
#include "OSDefaultSolver.h"
#include "OSWSUtil.h"
#include "OSSolverAgent.h"
#include "OShL.h"
#include "OSErrorClass.h"
#include "OSmps2osil.h"
#include "OSBase64.h"
#include "OSRunSolver.h"
#include "OSCommandLine.h"
#include "OSCommandLineReader.h"
#include "OSServiceMethods.h"

#ifdef COIN_HAS_KNITRO
#include "OSKnitroSolver.h"
#endif

#ifdef COIN_HAS_LINDO
#include "OSLindoSolver.h"
#endif

#ifdef COIN_HAS_ASL
#include "OSnl2osil.h"
#endif

#ifdef COIN_HAS_GAMSUTILS
#include "OSgams2osil.hpp"
#endif

//#ifdef COIN_HAS_IPOPT
//#include "OSIpoptSolver.h"
//#endif

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

#include "OSOptionsStruc.h"

#include<stdio.h>
#include <map>


using std::cout;
using std::endl;
using std::ostringstream;
using std::string;
using std::map;

//#define DEBUG_CL_INTERFACE

void interactiveShell();

std::string get_help();
std::string get_version();
std::string get_options();
void reset_options();



void listOptions(osOptionsStruc *osoptions);
void doPrintModel(osOptionsStruc *osoptions);
void doPrintModel(OSInstance *osinstance);
void doPrintRow(osOptionsStruc *osoptions);
void doPrintRow(OSInstance *osinstance, std::string rownumberstring);

  
int main(int argC, const char* argV[])
{
    WindowsErrorPopupBlocker();

	
	
	std::cout << OSgetVersionInfo();
	std::string osss;

    if (argC < 2)
    {
        interactiveShell();
        return 0;
    }

	// store the command line items into a single string
	ostringstream outStr;
	outStr << argV[1];
	for (int i=2; i < argC; i++)
		outStr << " " << argV[i];
	osss = outStr.str();

#ifdef DEBUG_CL_INTERFACE
    cout << "Input String = " << outStr << endl;
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
        delete fileUtil;
        fileUtil = NULL;
        delete oscommandline;
        oscommandline = NULL;
        delete clreader;
        clreader = NULL;
        return 1;
    }

#ifdef DEBUG_CL_INTERFACE
	std::cout << oscommandline->list_options() << std::endl;
#endif

	// deal with "action items": help, quit, listOptions, etc.
	if (oscommandline->quit || oscommandline->invokeHelp || oscommandline->writeVersion || oscommandline->listOptions)
	{
		if (oscommandline->invokeHelp) 
			std::cout << std::endl << std::endl << get_help() << std::endl;
		if (oscommandline->listOptions) 
			std::cout << std::endl << std::endl << oscommandline->list_options() << std::endl;
        delete oscommandline;
        oscommandline = NULL;
        return 0;
	}

	// call service method
	try
    {
		std::string result;
		OSServiceMethods *osservicemethods;
		osservicemethods = new OSServiceMethods(oscommandline);

		if (oscommandline->printModel) 
			oscommandline->osinstance->printModel();
		if (oscommandline->printRowNumberAsString != "")
			oscommandline->osinstance->printModel(atoi((oscommandline->printRowNumberAsString).c_str()));

		result = osservicemethods->executeServiceMethod(oscommandline);
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

	OSCommandLine *oscommandline = NULL;
    oscommandline = new OSCommandLine();

	bool scannerActive = false;

    //this is the interactive shell
    scannerActive = true;
    ossslex_init(&scanner);
    setyyextra(osoptions, scanner);
    std::string lineText;
    //use a blank to separate words
    std::string wordSep = " ";
    std::string optionName = "";
    std::string optionValue = "";
    std::string::size_type indexStart;
    std::string::size_type indexEnd;
    unsigned int k;


	std::string commandArray[6] = { "solve", "send", "getJobID", "retrieve", "kill", "knock"};

    std::string   actionItem[9] = { "quit", "exit",  "reset", "list", "?", "help", "version", 
					  			    "printModel", "printRow"
                                  };

    std::string optionArray[11] = { "osil", "osrl", "osol", "mps", "nl", "dat", "osilOutput",
                                    "serviceLocation", "solver", "osplInput",  "osplOutput"
                                  };


    size_t size_of_commandArray = (sizeof commandArray)
                                  / (sizeof commandArray[0]);

    size_t size_of_actionItem = (sizeof actionItem)
                                  / (sizeof actionItem[0]);

    size_t size_of_optionArray = (sizeof optionArray)
                                 / (sizeof optionArray[0]);


    //fill in the command array into a map
	std::map<string, int> commandMap;

    for (k = 0; k < size_of_commandArray; k++)
    {
        commandMap[ commandArray[ k] ] = k;
    }

    //fill in the action items array into a map
    std::map<string, int> actionItemMap;

    for (k = 0; k < size_of_actionItem; k++)
    {
        actionItemMap[ actionItem[ k] ] = k;
    }

    //fill in the option array into a map
	std::map<string, int> optionMap;

    for (k = 0; k < size_of_optionArray; k++)
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
            std::cout << "You did not enter a valid option."
                      << std::endl;
        }
        else
        {
            indexEnd = lineText.find_first_of(wordSep, indexStart + 1);
            optionName = lineText.substr(indexStart, indexEnd
                                         - indexStart);

            if ( (commandMap.find(optionName) == commandMap.end() ) &&
                    (optionMap.find(optionName) == optionMap.end() ) )
            {
                std::cout << std::endl;
                std::cout << "You did not enter a valid option."
                          << std::endl;
            }
            else
            {
			// get the option value
                indexStart = lineText.find_first_not_of(wordSep,indexEnd + 1);
                indexEnd = lineText.find_first_of(wordSep, indexStart
                                                          + 1);
                if (indexStart != std::string::npos && indexEnd != std::string::npos)
                {
                    optionValue = lineText.substr(indexStart, indexEnd - indexStart);
                }
                else
                {
                    optionValue = "";
                }

#ifdef DEBUG_CL_INTERFACE
                std::cout << "Option Value = " << optionValue << std::endl;
#endif

                        try
                        {
                            //first we process the commands
                            if( commandMap.find(optionName) != commandMap.end()  )
                            {
                                switch (commandMap[ optionName] )
                                {

                                case 0: // solve command

                                    if(osoptions->osil == "" && osoptions->mps == "" &&  osoptions->nl == "")
                                    {
                                        std::cout
                                                << std::endl
                                                << "You did not specify an optimization instance!!!\n"
                                                << "Please enter file format option (osil, nl, or mps) \n"
                                                << "followed by the option value which is the file location. \n"
                                                << std::endl;
                                        //std::cout
                                        //	<< "Please enter the path and optimization instance file name: ";
                                        //getline(std::cin, osoptions->osilFile);
                                        //osoptions->osil
                                        //	= fileUtil->getFileAsString(
                                        //			(osoptions->osilFile).c_str());
                                    }
                                    else
                                    {
                                        solve();
                                        if (osoptions->osrlFile != "")
                                            std::cout <<  "\nSolve command executed. Please see " << osoptions->osrlFile  << " for results." << std::endl;
                                    }
                                    break;

                                case 1: // send command

                                    if(osoptions->serviceLocation == "")
                                        getServiceLocation();
                                    send();
                                    break;


                                case 2: // getJobID command

                                    if(osoptions->serviceLocation == "")
                                        getServiceLocation();
                                    getJobID();
                                    break;


                                case 3: // retrieve command

                                    if(osoptions->serviceLocation == "")
                                        getServiceLocation();

                                    if( (osoptions->osolFile == "") && (osoptions->jobID == "") )
                                    {
                                        std::cout
                                                << std::endl
                                                << "Cannot retrieve: no JobID and no OSoL file"
                                                << std::endl;
                                    }
                                    else
                                    {
                                        retrieve();
                                    }

                                    break;

                                case 4: // kill command


                                    if(osoptions->serviceLocation == "")
                                        getServiceLocation();

									if( (osoptions->osolFile == "") && (osoptions->jobID == "") )
                                    {
                                        std::cout
                                                << std::endl
                                                << "Cannot kill: no JobID and no OSoL file"
                                                << std::endl;
                                    }
                                    else
                                    {
                                        kill();
                                    }


                                    break;


                                case 5: // knock command

                                    //note -- can have empty OSoL for knock
                                    //however we do need an OSpL file

                                    if(osoptions->serviceLocation == "")
                                        getServiceLocation();

                                    if( osoptions->osplInputFile == "")
                                    {
                                        std::cout
                                                << std::endl
                                                << "Cannot knock -- no OSplInputFile specificed"
                                                << std::endl;
                                    }
                                    else
                                    {
                                        knock();
                                    }

                                    break;


                                case 6: // quit command

                                    return;



                                case 7: // exit command

                                    return;



                                case 8: // reset command

                                    reset_options();
                                    std::cout << "\nAll options reset.\n";
                                    break;



                                case 9: // list command

                                    listOptions( osoptions);
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

                                    doPrintModel(osoptions);
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


                                        }// end switch
                                        // now get the option value
                                        getline(std::cin, optionValue);
                                    }// end if on finding an element in the optionMap

                                } // end if on whether or not option value is null

                                lineText = optionName + " "
                                           + optionValue + " ";
                                osss_scan_string(lineText.c_str(),
                                                 scanner);
                                ossslex(scanner);
                                listOptions( osoptions);

                                if(optionMap.find(optionName) != optionMap.end() )
                                {

									switch (optionMap[ optionName] )
                                    {

                                    case 0: //osil

                                        osoptions->osil
                                            = fileUtil->getFileAsString(
                                                  (osoptions->osilFile).c_str());
                                        break;


                                    case 1: //osrl

                                        break;

                                    case 2: //osol

                                        osoptions->osol
                                            = fileUtil->getFileAsString(
                                                  (osoptions->osolFile).c_str());
                                        break;

                                    case 3: //mps

                                        osoptions->mps
                                            = fileUtil->getFileAsString(
                                                  (osoptions->mpsFile).c_str());
                                        break;

                                    case 4: //nl

                                        osoptions->nl
                                            = fileUtil->getFileAsString(
                                                  (osoptions->nlFile).c_str());
                                        break;

                                    case 5: //dat

                                        osoptions->dat
                                            = fileUtil->getFileAsString(
                                                  (osoptions->datFile).c_str());
                                        break;

                                    case 6: //service location

                                        break;

                                    case 7: //solver

                                        //make solver name lower case 
                                        for (k = 0; k
                                                < osoptions->solverName.length(); k++)
                                        {
                                            osoptions->solverName[k] = 
                                                (char)tolower(osoptions->solverName[k]);
                                        }
                                        break;

                                    case 8: //osplInput

                                        osoptions->osplInput
                                            = fileUtil->getFileAsString(
                                                  (osoptions->osplInputFile).c_str());
                                        break;

                                    case 9: //osplOutput

                                        break;

                                    case 10: //printRow

					                    doPrintRow(osoptions);
                                        break;



                                    }// end switch

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
            delete osoptions;
            osoptions = NULL;
            delete fileUtil;
            fileUtil = NULL;
}

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


void reset_options()
{
    osoptions->configFile = "";
    osoptions->osilFile = "";
    osoptions->osil = "";
    osoptions->osolFile = "";
    osoptions->osol = "";
    osoptions->osrlFile = "";
    osoptions->osrl = "";
    osoptions->insListFile = "";
    osoptions->insList = "";
    osoptions->serviceLocation = "";
    osoptions->serviceMethod = "";
    osoptions->osplInputFile = "";
    osoptions->osplInput = "";
    osoptions->osplOutputFile = "";
    osoptions->osplOutput = "";
    osoptions->mpsFile = "";
    osoptions->mps = "";
    osoptions->nlFile = "";
    osoptions->nl = "";
    osoptions->gamsControlFile = "";
    osoptions->solverName = "";
    osoptions->browser = "";
    osoptions->jobID = "";
    osoptions->invokeHelp = false;
    osoptions->writeVersion = false;
    osoptions->printModel = false;
    osoptions->printRowNumberAsString = "";
    osoptions->quit = false;
    osoptions->exit = false;
}//reset_options



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
            << endl << endl;

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


void listOptions(osOptionsStruc *osoptions)
{
    cout
            << "HERE ARE THE OPTION VALUES SO FAR:"
            << endl;
    if (osoptions->configFile != "")
        cout << "Config file = "
             << osoptions->configFile
             << endl;
    if (osoptions->osilFile != "")
        cout << "OSiL file = "
             << osoptions->osilFile
             << endl;
    if (osoptions->osolFile != "")
        cout << "OSoL file = "
             << osoptions->osolFile
             << endl;
    if (osoptions->osrlFile != "")
        cout << "OSrL file = "
             << osoptions->osrlFile
             << endl;
//if(osoptions->insListFile != "") cout << "Instruction List file = " << osoptions->insListFile << endl;
    if (osoptions->osplInputFile != "")
        cout << "OSpL Input file = "
             << osoptions->osplInputFile
             << endl;
    if (osoptions->serviceMethod != "")
        cout << "Service Method = "
             << osoptions->serviceMethod
             << endl;
    if (osoptions->mpsFile != "")
        cout << "MPS File Name = "
             << osoptions->mpsFile
             << endl;
    if (osoptions->nlFile != "")
        cout << "NL File Name = "
             << osoptions->nlFile
             << endl;
    if (osoptions->solverName != "")
        cout << "Selected Solver = "
             << osoptions->solverName
             << endl;
    if (osoptions->serviceLocation != "")
        cout << "Service Location = "
             << osoptions->serviceLocation
             << endl;

    if (osoptions->jobID != "")
        cout << "Job ID = "
             << osoptions->jobID
             << endl;
}// listOptions

void doPrintModel(osOptionsStruc *osoptions)
{
	if (osoptions->osil == "" && osoptions->mps == "" &&  osoptions->nl == "")
	{
		std::cout
			<< "no instance defined; print command ignored" << std::endl;
	}
	else
	{
		if (osoptions->osil != "")
		{
			OSiLReader *osilreader;
			osilreader = new OSiLReader();
			std::cout << osilreader->readOSiL(osoptions->osil)->printModel() << std::endl;
			delete osilreader;
			osilreader = NULL;
		}
		else if (osoptions->nl != "")
		{
#ifdef COIN_HAS_ASL
			OSnl2osil *nl2osil;	
			nl2osil = new OSnl2osil( osoptions->nlFile);
			nl2osil->createOSInstance();
			std::cout << nl2osil->osinstance->printModel() << std::endl;
			delete nl2osil;
			nl2osil = NULL;
#else
			std::cout << "no ASL present to read nl file; print command ignored" << std::endl; 
#endif
		}
		else if (osoptions->mps != "")
		{
			OSmps2osil *mps2osil;
			mps2osil = new OSmps2osil(osoptions->mpsFile);
			mps2osil->createOSInstance();
			std::cout << mps2osil->osinstance->printModel() << std::endl;
			delete mps2osil;
			mps2osil = NULL;
		}
	}
}// doPrintModel(osOptionsStruc *osoptions)

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
}// doPrintModel(osOptionsStruc *osoptions)

void doPrintRow(osOptionsStruc *osoptions)
{
	int rownumber;
	if (osoptions->printRowNumberAsString == "")
		std::cout << "no line number given; print command ignored" << std::endl;
	else
	{
		try
		{
			rownumber = atoi((osoptions->printRowNumberAsString).c_str());
		}
		catch  (const ErrorClass& eclass)
		{
	                std::cout << "invalid row number; print command ignored" << std::endl;
		}

		if (osoptions->osil == "" && osoptions->mps == "" &&  osoptions->nl == "")
                {
                        std::cout
	                        << "no instance defined; print command ignored" << std::endl;
		}
		else
		{
			std::cout << std::endl << "Row " << rownumber << ":" << std::endl << std::endl;
			if (osoptions->osil != "")
			{
				OSiLReader *osilreader;
				osilreader = new OSiLReader();
		    		std::cout << osilreader->readOSiL(osoptions->osil)->printModel(rownumber) << std::endl;
				delete osilreader;
				osilreader = NULL;
			}
			else if (osoptions->nl != "")
			{
#ifdef COIN_HAS_ASL
				OSnl2osil *nl2osil;	
				nl2osil = new OSnl2osil( osoptions->nlFile);
				nl2osil->createOSInstance();
				std::cout << nl2osil->osinstance->printModel(rownumber) << std::endl;
				delete nl2osil;
				nl2osil = NULL;
#else
				std::cout << "no ASL present to read nl file; print command ignored" << std::endl; 
#endif
			}
			else if (osoptions->mps != "")
			{
				OSmps2osil *mps2osil;
				mps2osil = new OSmps2osil(osoptions->mpsFile);
				mps2osil->createOSInstance();
				std::cout << mps2osil->osinstance->printModel(rownumber) << std::endl;
				delete mps2osil;
				mps2osil = NULL;
			}
		}
	}
}// doPrintRow(osOptionsStruc *osoptions)

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

