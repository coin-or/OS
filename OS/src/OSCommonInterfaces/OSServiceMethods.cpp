/* $Id: OSServiceMethods.cpp 4340 2011-10-15 20:08:33Z Gassmann $ */
/** @file OSServiceMethods.cpp
 *
 * @author  Horand Gassmann, Jun Ma, Kipp Martin,
 *
 * \remarks
 * Copyright (C) 2011, Horand Gassmann, Jun Ma, Kipp Martin,
 * Dalhousie University, Northwestern University, and the University of Chicago.
 * All Rights Reserved.
 * This software is licensed under the Eclipse Public License.
 * Please see the accompanying LICENSE file in root directory for terms.
 *
 */

 /**
  *  This file implements wrappers around the service methods of OS
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

#include <stdio.h>

std::string executeServiceMethod(OSCommandLine *oscommandline)
{
	return "";
}//executeServiceMethod

    try
    {
        if (oscommandline->invokeHelp == true)
        {
			std::cout << std::endl << std::endl << get_help() << std::endl;
            delete osoptions;
            osoptions = NULL;
            return 0;
        }
        if (oscommandline->writeVersion == true)
        {
			std::cout << std::endl << std::endl << OSgetVersionInfo() << std::endl;
            delete osoptions;
            osoptions = NULL;
            return 0;
        }
    }
    catch (const ErrorClass& eclass)
    {
        //cout << eclass.errormsg <<  endl;
        //cout << "try -h or --help" <<  endl;


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
            //std::cout <<  eclass.errormsg << std::endl;
            std::cout << osrl << std::endl;
        }
        //catch garbage collection
        delete osresult;
        osresult = NULL;
        delete osrlwriter;
        osrlwriter = NULL;
        // end new stuff


        delete osoptions;
        osoptions = NULL;
        delete inputFileUtil;
        inputFileUtil = NULL;
        return 1;
    }

#ifdef DEBUG_CL_INTERFACE
    cout << "HERE ARE THE OPTION VALUES:" << endl;
    if(oscommandline->configFile != "") cout << "Config file = " << oscommandline->configFile << endl;
    if(oscommandline->osilFile != "") cout << "OSiL file = " << oscommandline->osilFile << endl;
    if(oscommandline->osolFile != "") cout << "OSoL file = " << oscommandline->osolFile << endl;
    if(oscommandline->osrlFile != "") cout << "OSrL file = " << oscommandline->osrlFile << endl;
    //if(oscommandline->insListFile != "") cout << "Instruction List file = " << oscommandline->insListFile << endl;
    if(oscommandline->osplInputFile != "") cout << "OSpL Input file = " << oscommandline->osplInputFile << endl;
    if(oscommandline->serviceMethod != "") cout << "Service Method = " << oscommandline->serviceMethod << endl;
    if(oscommandline->mpsFile != "") cout << "MPS File Name = " << oscommandline->mpsFile << endl;
    if(oscommandline->nlFile != "") cout << "NL File Name = " << oscommandline->nlFile << endl;
    if(oscommandline->gamsControlFile != "") cout << "gams Control File Name = " << oscommandline->gamsControlFile << endl;
    if(oscommandline->browser != "") cout << "Browser Value = " << oscommandline->browser << endl;
    if(oscommandline->solverName != "") cout << "Selected Solver = " << oscommandline->solverName << endl;
    if(oscommandline->serviceLocation != "") cout << "Service Location = " << oscommandline->serviceLocation << endl;
    if(oscommandline->printModel) cout << "print model prior to solve/send" << endl;
    if(oscommandline->printRowNumberAsString != "") cout << "print model row " << oscommandline->printRowNumberAsString << " prior to solve/send" << endl;

#endif


    // get the data from the files
    fileUtil = new FileUtil();
    try
    {
        //if(osoptions->insListFile != "") osoptions->insList = fileUtil->getFileAsChar( (osoptions->insListFile).c_str() );
        if (osoptions->osolFile != "")
        {

            osoptions->osol = fileUtil->getFileAsString(
                                  (osoptions->osolFile).c_str());

        }

        if (osoptions->osilFile != "")
        {
            //this takes precedence over what is in the OSoL file
            osoptions->osil = fileUtil->getFileAsString(
                                  (osoptions->osilFile).c_str());
        }
        /*
         else{// we were not given an osil file
         // make sure we don't have a service URI in the file or are using mps or nl
         // if we have nl or mps assume a local solve
         if( (osoptions->osol != "") && (osoptions->nlFile == "") && (osoptions->gamsControlFile == "") && (osoptions->mpsFile == "") && (osoptions->serviceLocation == "")  &&  (getServiceURI( osoptions->osol) == "") )
         osoptions->osil = fileUtil->getFileAsString( getInstanceLocation( osoptions->osol).c_str()  );
         }
         */

        //if(osoptions->osplInputFile != "") osoptions->osplInput = fileUtil->getFileAsChar( (osoptions->osplInputFile).c_str()  );
        if (osoptions->osplInputFile != "")
            osoptions->osplInput = fileUtil->getFileAsString(
                                       (osoptions->osplInputFile).c_str());
        //if(osoptions->osplOutputFile != "") osoptions->osplOutput = fileUtil->getFileAsChar( (osoptions->osplOutputFile).c_str() );
//        if (osoptions->osplOutputFile != "")
//            osoptions->osplOutput = fileUtil->getFileAsString(
//                                        (osoptions->osplOutputFile).c_str());
    }
    catch (const ErrorClass& eclass)
    {
        //cout << eclass.errormsg <<  endl;
        //cout << "could not open file properly" << endl;
        //cout << "try -h or --help" <<  endl;


        //new stuff on April 17, 2010
        OSResult *osresult = NULL;
        OSrLWriter *osrlwriter = NULL;
        osrlwriter = new OSrLWriter();
        osresult = new OSResult();
        osresult->setGeneralMessage(eclass.errormsg);
        osresult->setGeneralStatusType("error");
        std::string osrl = osrlwriter->writeOSrL(osresult);
        if (osoptions->osrlFile != "")
        {
            //fileUtil->writeFileFromString(osoptions->osrlFile,  eclass.errormsg);
            fileUtil->writeFileFromString(osoptions->osrlFile, osrl);
            if (osoptions->browser != "")
            {
                std::string str = osoptions->browser + "  "
                                  + osoptions->osrlFile;
                const char *ch = &str[0];
                std::system(ch);
            }
        }
        else
        {
            //std::cout <<  eclass.errormsg << std::endl;
            std::cout << osrl << std::endl;
        }
        //catch garbage collection
        delete osresult;
        osresult = NULL;
        delete osrlwriter;
        osrlwriter = NULL;
        // end new stuff


        delete osoptions;
        osoptions = NULL;
        delete fileUtil;
        fileUtil = NULL;
        return 1;
    }
    // now call the correct serviceMethod
    // solve is the default
    if ((osoptions->serviceMethod == "") || (osoptions->serviceMethod[0] == 's'))
    {
        if (osoptions->printModel == true)
            doPrintModel(osoptions);
        else if (osoptions->printRowNumberAsString != "")
            doPrintRow(osoptions);
        if (osoptions->serviceMethod[1] == 'e')
            send();
        else
            solve();
    }
    else
    {
        switch (osoptions->serviceMethod[0])
        {
        case 'g':
            getJobID();
            break;
        case 'r':
            retrieve();
            break;
        case 'k':
            if (osoptions->serviceMethod[1] == 'i')
                kill();
            else
                knock();
            break;
        default:

            break;
        }
    }
    delete osoptions;
    osoptions = NULL;
    delete fileUtil;
    fileUtil = NULL;
    return 0;
}

void solve()
{
    std::string osrl = "";
    OSiLReader *osilreader = NULL;
    OSmps2osil *mps2osil = NULL;
#ifdef COIN_HAS_ASL
    OSnl2osil *nl2osil = NULL;
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
        if (osoptions->serviceLocation != "")
        {
            // call a method here to get OSiL if we have an nl or mps file
            if (osoptions->osil == "")
            {
                //we better have an nl file present or mps file or osol file
                if (osoptions->nlFile != "")
                {
                    getOSiLFromNl();
                }
                else
                {
                    if (osoptions->mpsFile != "")
                    {
                        getOSiLFromMps();
                    }
                    else
                    {
                        if (osoptions->gamsControlFile != "")
                        {

                            getOSiLFromGams();
                        }
                        else    // send an empty osil string
                        {
                            osoptions->osil = "";
                        }
                    }
                }
            }

	    if (osoptions->printModel)
		doPrintModel(osoptions);
	    else if (osoptions->printRowNumberAsString != "")
                doPrintRow(osoptions);

            // place a remote call
            osagent = new OSSolverAgent(osoptions->serviceLocation);

            if (osoptions->osol == "")  // we have no osol string
            {

                std::ostringstream outStr;
                outStr
                        << "<?xml version=\"1.0\" encoding=\"UTF-8\"?> <osol xmlns=\"os.optimizationservices.org\" xmlns:xs=\"http://www.w3.org/2001/XMLSchema\" xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\" xsi:schemaLocation=\"os.optimizationservices.org http://www.optimizationservices.org/schemas/";
                outStr << OS_SCHEMA_VERSION;
                outStr << "/OSoL.xsd\"></osol>";
                osoptions->osol = outStr.str();
            }
            osrl = osagent->solve(osoptions->osil, osoptions->osol);
            if (osoptions->osrlFile != "")
            {
                fileUtil->writeFileFromString(osoptions->osrlFile, osrl);
                //const char *ch1 = "/Applications/Firefox.app/Contents/MacOS/firefox  ";
                if (osoptions->browser != "")
                {
                    std::string str = osoptions->browser + "  "
                                      + osoptions->osrlFile;
                    const char *ch = &str[0];
                    std::system(ch);
                }
            }
            else
                cout << osrl << endl;
            delete osagent;
            osagent = NULL;

        }
        else    // solve locally
        {
            OSInstance *osinstance;
            if (osoptions->osil != "")
            {
                osilreader = new OSiLReader();                
                osinstance = osilreader->readOSiL(osoptions->osil);
            }
            else
            {
                //we better have an nl file present or mps file or osol file
                if (osoptions->nlFile != "")
                {
#ifdef COIN_HAS_ASL
                    nl2osil = new OSnl2osil( osoptions->nlFile);
                    nl2osil->createOSInstance();
                    osinstance = nl2osil->osinstance;
#else
                    throw ErrorClass(
                        "nl file specified locally but ASL not present");
#endif
                }
                else
                {
                    if (osoptions->mpsFile != "")
                    {
                        mps2osil = new OSmps2osil(osoptions->mpsFile);
                        mps2osil->createOSInstance();
                        osinstance = mps2osil->osinstance;
                    }
                    else
                    {
                        if (osoptions->gamsControlFile != "")
                        {
#ifdef COIN_HAS_GAMSUTILS
                            gams2osil = new OSgams2osil( osoptions->gamsControlFile);
                            gams2osil->createOSInstance();
                            osinstance = gams2osil->osinstance;
#else
                            throw ErrorClass(
                                "a Gams Control specified locally but GAMSIP not present");
#endif

                        }
                        else    // need an osol file with an instanceLocation specified
                        {
                            //if( osoptions->osol.find( "<instanceLocation") == std::string::npos){
                            throw ErrorClass(
                                "Error: no osil, GAMS dat, AMPL nl, or mps file given for a local solve --- \n information in the osol file is ignored for local solves.");
                            //}
                        }
                    }
                }
            }
	    if (osoptions->printModel)
                    doPrintModel(osinstance);
	    else if (osoptions->printRowNumberAsString != "")
	            doPrintRow(osinstance, osoptions->printRowNumberAsString);
                
            osrl = runSolver(osoptions->solverName, osoptions->osol, osinstance);
            

	    //delete fileUtil;
            if (osoptions->osrlFile != "")
            {

                fileUtil->writeFileFromString(osoptions->osrlFile, osrl);

                //const char *ch1 = "/Applications/Firefox.app/Contents/MacOS/firefox  ";
                if (osoptions->browser != "")
                {
                    std::string str = osoptions->browser + "  "
                                      + osoptions->osrlFile;
                    const char *ch = &str[0];
                    std::system(ch);
                }
            }
            else
                cout << osrl << endl;

        }//end of local solve


        //garbage collection
        if (osilreader != NULL)
            delete osilreader;
        osilreader = NULL;
        if (mps2osil != NULL)
            delete mps2osil;
        mps2osil = NULL;
#ifdef COIN_HAS_ASL
        if(nl2osil != NULL) delete nl2osil;
        nl2osil = NULL;
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
        if (osoptions->osrlFile != "")
        {
            //fileUtil->writeFileFromString(osoptions->osrlFile,  eclass.errormsg);
            fileUtil->writeFileFromString(osoptions->osrlFile, osrl);
            if (osoptions->browser != "")
            {
                std::string str = osoptions->browser + "  "
                                  + osoptions->osrlFile;
                const char *ch = &str[0];
                std::system(ch);
            }
        }
        else
        {
            //std::cout <<  eclass.errormsg << std::endl;
            std::cout << osrl << std::endl;
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
        if(nl2osil != NULL) delete nl2osil;
        nl2osil = NULL;
#endif
#ifdef COIN_HAS_GAMSUTILS
        if(gams2osil != NULL) delete gams2osil;
        gams2osil = NULL;
#endif
        delete fileUtil;
        fileUtil = NULL;
    }//end local catch

}//end solve

void getJobID()
{
    OSSolverAgent* osagent = NULL;
    try
    {
        if (osoptions->serviceLocation != "")
        {
            osagent = new OSSolverAgent(osoptions->serviceLocation);
            osoptions->jobID = osagent->getJobID(osoptions->osol);
            cout << osoptions->jobID << endl;
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


void knock()
{
    std::string osplOutput = "";
    OSSolverAgent* osagent = NULL;
    FileUtil *fileUtil = NULL;
    fileUtil = new FileUtil();
    try
    {
        if (osoptions->serviceLocation != "")
        {
            osagent = new OSSolverAgent(osoptions->serviceLocation);


            if (osoptions->osol == "")
            {
                // we need to construct the OSoL
                OSOption *osOption = NULL;
                osOption = new OSOption();
                //set the jobID if there is one
                if(osoptions->jobID == "") osOption->setJobID( osoptions->jobID);
                // now read the osOption object into a string
                OSoLWriter *osolWriter = NULL;
                osolWriter = new OSoLWriter();
                osoptions->osol = osolWriter->writeOSoL( osOption);
                delete osOption;
                osOption = NULL;
                delete osolWriter;
                osolWriter = NULL;
            }


            osplOutput = osagent->knock(osoptions->osplInput, osoptions->osol);
            if (osoptions->osplOutputFile != "")
                fileUtil->writeFileFromString(osoptions->osplOutputFile,
                                              osplOutput);
            else
                cout << osplOutput << endl;
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


void send()
{
    bool bSend = false;
    OSSolverAgent* osagent = NULL;
    try
    {
        // call a method here to get OSiL if we have an nl or mps file
        if (osoptions->osil == "")
        {
            //we better have an nl file present or mps file
            if (osoptions->nlFile != "")
            {
                getOSiLFromNl();
            }
            else
            {
                if (osoptions->mpsFile != "")
                {
                    getOSiLFromMps();
                }
                else    // send an empty osil string
                {
                    osoptions->osil = "";
                }
            }
        }
        if (osoptions->serviceLocation != "")
        {
            osagent = new OSSolverAgent(osoptions->serviceLocation);
            // check to see if there is an osol
            if (osoptions->osol == "")
            {
                // we need to construct the OSoL
                OSOption *osOption = NULL;
                osOption = new OSOption();
                // get a jobId if necessary
                if(osoptions->jobID == "") osoptions->jobID = osagent->getJobID("");
                //set the jobID

                osOption->setJobID( osoptions->jobID);
                // now read the osOption object into a string
                OSoLWriter *osolWriter = NULL;
                osolWriter = new OSoLWriter();
                osoptions->osol = osolWriter->writeOSoL( osOption);
                delete osOption;
                osOption = NULL;
                delete osolWriter;
                osolWriter = NULL;
            }
            bSend = osagent->send(osoptions->osil, osoptions->osol);
            std::cout << "Result of send: " << bSend << std::endl;
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


        if (osoptions->osrlFile != "")
            fileUtil->writeFileFromString(osoptions->osrlFile, osrl);
        else
            cout << osrl << endl;

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

void retrieve()
{
    FileUtil *fileUtil = NULL;
    fileUtil = new FileUtil();
    std::string osrl = "";
    OSSolverAgent* osagent = NULL;
    try
    {
        if (osoptions->serviceLocation != "")
        {
            osagent = new OSSolverAgent(osoptions->serviceLocation);


            if (osoptions->osol == "")
            {
                // we need to construct the OSoL
                OSOption *osOption = NULL;
                osOption = new OSOption();
                // get a jobId if necessary
                if(osoptions->jobID == "")throw ErrorClass("there is no JobID");
                //set the jobID
                osOption->setJobID( osoptions->jobID);
                // now read the osOption object into a string
                OSoLWriter *osolWriter = NULL;
                osolWriter = new OSoLWriter();
                osoptions->osol = osolWriter->writeOSoL( osOption);
                delete osOption;
                osOption = NULL;
                delete osolWriter;
                osolWriter = NULL;
            }

            osrl = osagent->retrieve(osoptions->osol);

            if (osoptions->osrlFile != "")
            {
                fileUtil->writeFileFromString(osoptions->osrlFile, osrl);
                if (osoptions->browser != "")
                {
                    std::string str = osoptions->browser + "  "
                                      + osoptions->osrlFile;
                    const char *ch = &str[0];
                    std::system(ch);
                }
            }
            else
                cout << osrl << endl;
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

void kill()
{
    FileUtil *fileUtil = NULL;
    fileUtil = new FileUtil();
    std::string osplOutput = "";
    OSSolverAgent* osagent = NULL;
    try
    {
        if (osoptions->serviceLocation != "")
        {
            osagent = new OSSolverAgent(osoptions->serviceLocation);

            if (osoptions->osol == "")
            {
                // we need to construct the OSoL
                OSOption *osOption = NULL;
                osOption = new OSOption();
                // get a jobId if necessary
                if(osoptions->jobID == "")throw ErrorClass("there is no JobID");
                //set the jobID
                osOption->setJobID( osoptions->jobID);
                // now read the osOption object into a string
                OSoLWriter *osolWriter = NULL;
                osolWriter = new OSoLWriter();
                osoptions->osol = osolWriter->writeOSoL( osOption);
                delete osOption;
                osOption = NULL;
                delete osolWriter;
                osolWriter = NULL;
            }

            osplOutput = osagent->kill(osoptions->osol);

            if (osoptions->osplOutputFile != "")
                fileUtil->writeFileFromString(osoptions->osplOutputFile,
                                              osplOutput);
            else
                cout << osplOutput << endl;
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


void getOSiLFromNl()
{
    try
    {
#ifdef COIN_HAS_ASL
        OSnl2osil *nl2osil = NULL;
        nl2osil = new OSnl2osil( osoptions->nlFile);
        nl2osil->createOSInstance();
        OSiLWriter *osilwriter = NULL;
        osilwriter = new OSiLWriter();
        std::string osil;
        osil = osilwriter->writeOSiL( nl2osil->osinstance);
        osoptions->osil = osil;
        delete nl2osil;
        nl2osil = NULL;
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
}//getOSiLFromNl


void getOSiLFromGams()
{
    try
    {
#ifdef COIN_HAS_GAMSIO
        OSgams2osil *gams2osil = NULL;
        gams2osil = new OSgams2osil( osoptions->gamsControlFile);
        gams2osil->createOSInstance();
        OSiLWriter *osilwriter = NULL;
        osilwriter = new OSiLWriter();
        std::string osil;
        osil = osilwriter->writeOSiL( gams2osil->osinstance);
        osoptions->osil = osil;
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
        std::cout << eclass.errormsg << std::endl;
        throw ErrorClass(eclass.errormsg);
    }
}//getOSiLFromGams


void getOSiLFromMps()
{
    try
    {
        OSmps2osil *mps2osil = NULL;
        mps2osil = new OSmps2osil(osoptions->mpsFile);
        mps2osil->createOSInstance();
        OSiLWriter *osilwriter = NULL;
        osilwriter = new OSiLWriter();
        std::string osil;
        osil = osilwriter->writeOSiL(mps2osil->osinstance);
        osoptions->osil = osil;
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
