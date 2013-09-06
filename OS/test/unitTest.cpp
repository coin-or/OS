/* $Id$ */
/** @file unitTest.cpp
 * 
 * \brief This file runs the OS unit test.
 *
 * @author  Horand Gassmann, Jun Ma, Kipp Martin, 
 *
 * \remarks
 * Copyright (C) 2005-2011, Horand Gassmann, Jun Ma, Kipp Martin,
 * Northwestern University, and the University of Chicago.
 * All Rights Reserved.
 * This software is licensed under the Eclipse Public License. 
 * Please see the accompanying LICENSE file in root directory for terms.
 * 
 * 
 * This is the OS unit test. It runs a large number of tests of most aspects of the 
 * Optimization Services suite. The tests fall into different categories and can be 
 * switched on and off selectively by setting appropriate boolean variables
 * from the command line interface.
 *
 *   BASIC_TESTS;  // minimal functionality tests
 *   SOLVER_TESTS; // at least one problem for each solver
 *   THOROUGH;     // multiple problems for some solvers
 *   PARSER_TESTS; // test parser logic
 *   OTHER_TESTS;  // other input formats, automatic differentiation, etc.
 *
 * Specifically, the following tests are run
 *
 * Basic tests (if BASIC_TESTS == TRUE)
 *   File handling: open and read a file
 *   Lossless I/O: read/write several floating point numbers and check for equality
 *   nonlinear operators and automatic differentiation
 * 
 * Parser tests (if PARSER_TESTS == TRUE)
 *   Parse an osil, osol and osrl file
 *   Test convenience methods, reader and writer routines
 *
 * Solver tests (if SOLVER_TESTS == TRUE and the solver in question is available)
 *  
 *   COIN-Clp tested on parincLinearByRow.osil
 * 
 *   COIN-Cbc tested on:
 *   <ol>
 *   <li> p0033.osil  </li>
 *   <li> p0033MULT.osil  </li>
 *   <li> p0033.osil with a node limit set (solver option) </li>
 *   <li> p0201.osil  </li>
 *   <li> parincInteger.osil  </li>
 * 
 *   COIN-SYMPHONY tested on p0033.osil
 * 
 *   COIN-DyLP tested on parincLinear.osil
 * 
 *   COIN-Vol tested on volumeTest.osil
 * 
 *   GLPK tested on p0033.osil
 * 
 *   Cplex tested on p0033.osil
 * 
 *   Gurobi tested on p0033.osil
 * 
 *   Mosek tested on p0033.osil
 * 
 *   Soplex tested on p0033.osil
 * 
 *   Xpress tested on p0033.osil
 * 
 *   COIN-Ipopt tested on:
 *   <ol>
 *   <li> avion2.osil  </li>
 *   <li> HS071_NLPMod.osil </li>
 *   <li> rosenbrockmod.osil </li>
 *   <li> parincQuadratic.osil </li>
 *   <li> parincLinear.osil  </li>
 *   <li> callBackTest.osil </li>
 *   <li> callBackTestRowMajor.osil </li>
 *   <li> rosenbrockorig.osil </li>
 *   <li> HS071_feas.osil </li>
 *   </ol>
 *
 *   COIN-BONMIN tested on 
 *   <ol>
 *   <li> bonminEx1.osil  </li>
 *   <li> wayneQuadratic.osil (two different option settings) </li>
 *   <li> rosenbrockorig.osil </li>
 *   <li> rosenbrockorigInt.osil </li>
 *
 *   COIN-COUENNE tested on 
 *   <ol>
 *   <li> bonminEx1.osil  </li>
 *   <li> bonminEx1_Nonlinear.osil  </li>
 *   <li> nonconvex.osil </li>
 *   <li> rosenbrockorig.osil </li>
 *   <li> wayneQuadratic.osil (two different option settings) </li>
 *
 *   Lindo tested on:
 *   <ol>
 *   <li> lindoapiaddins.osil </li>
 *   <li> rosenbrockmod.osil </li>
 *   <li> parincquadratic.osil </li>
 *   <li> wayneQuadratic.osil  </li>
 *   </ol>
 * 
 * Additional tests (if OTHER_TESTS == TRUE)
 *
 *   We test the mps to osil converter program
 *   OSmps2osil on parincLinear.mps and solve with Cbc.
 * 
 *   We test the AMPL nl file format to osil converter
 *   program OSnl2osil on parinc.nl and solve with Cbc.
 * 
 *   We test the base 64 format on problem parinc.  
 *   We first read the parinc.mps file into an
 *   osil string and then set m_bWriteBase64 = true. We then
 *   write a new instance in base 64 format and solve it with Cbc.
 * 
 *   Finally we test the prefix and postfix routines. For the test problem
 *   rosenbrockmod.osil we create an <b>OSExpressionTree</b> from
 *   the objective function. Then we invoke the <b>getPostfix()</b> method
 *   and get a postfix vector representation of the expression tree. 
 *   We use <b>createExpressionTreeFromPostfix</b> to create another expression tree,
 *   then use <b>getPrefix()</b> to get a prefix vector from this expression tree.
 *   Then we use <b>createExpressionTreeFromPrefix</b> to create an expression. 
 *   We use <b>getPostfix()</b> to get the postfix vector back and compare with the 
 *   very first postfix vector and make sure they are the same. 
 * 
 */ 

//#define DEBUG
//#define GUS_DEBUG

#include "OSConfig.h"
#ifdef OS_HAS_CPPAD
#include <cppad/cppad.hpp> 
#endif
//#include "CoinUtilsConfig.h"
#include "OSCoinSolver.h"
#include "OSmps2osil.h" 
#include "OSResult.h" 
#include "OSOption.h"
#include "OSiLReader.h"        
#include "OSiLWriter.h" 
#include "OSoLReader.h"        
#include "OSoLWriter.h" 
#include "OSrLReader.h"          
#include "OSrLWriter.h"      
#include "OSInstance.h"  
#include "OSFileUtil.h"  
#include "CoinError.hpp"

#include "OSDefaultSolver.h"  
#include "OSWSUtil.h" 
#include "OSSolverAgent.h"   
#include "OShL.h"     
#include "OSErrorClass.h"
#include "OSBase64.h"
#include "OSMathUtil.h"


#include <CoinMpsIO.hpp>
#include <CoinPackedMatrix.hpp>
#include "CoinError.hpp"
#include "CoinHelperFunctions.hpp"
#include "OsiSolverInterface.hpp"



#ifdef COIN_HAS_GLPK
#include <OsiGlpkSolverInterface.hpp>
#endif

#ifdef COIN_HAS_COUENNE    
#include "OSCouenneSolver.h"
#endif

#ifdef COIN_HAS_ASL
#include "OSnl2OS.h"
#include "OSosrl2ampl.h"
#endif

#ifdef COIN_HAS_LINDO    
#include "OSLindoSolver.h"
#endif  

#ifdef COIN_HAS_IPOPT    
#include "OSIpoptSolver.h"
#endif 

#ifdef COIN_HAS_BONMIN    
#include "OSBonminSolver.h"
#endif 

#ifdef COIN_HAS_CPX
#include "OsiCpxSolverInterface.hpp"
#endif

#ifdef COIN_HAS_GRB
#include "OsiGrbSolverInterface.hpp"
#endif

#ifdef COIN_HAS_MSK
#include "OsiMskSolverInterface.hpp"
#endif

#ifdef COIN_HAS_SOPLEX
#include "OsiSpxSolverInterface.hpp"
#endif

#ifdef COIN_HAS_XPR
#include "OsiXprSolverInterface.hpp"
#endif

#ifdef COIN_HAS_GAMSUTILS
#include "OSgams2osil.hpp"
#endif

#ifdef HAVE_CTIME
# include <ctime>
#else
# ifdef HAVE_TIME_H
#  include <time.h>
# else
#  error "don't have header file for time"
# endif
#endif

#ifdef HAVE_CMATH
# include <cmath>
#else
# ifdef HAVE_CMATH_H
#  include <cmath.h>
# endif
#endif

#ifdef HAVE_CSTDIO
# include <cstdio>
#else
# ifdef HAVE_STDIO_H
#  include <stdio.h>
# else
#  error "don't have header file for stdio"
# endif
#endif

//#ifdef HAVE_WINDOWS_H
//#include <windows.h>
//#endif

#ifdef COIN_HAS_ASL
#include <asl.h>
#endif


using std::cout;   
using std::endl;
using std::ostringstream;
using std::string;


int main(int argC, char* argV[])
{
//#ifdef HAVE_WINDOWS_H
//   SetErrorMode(SEM_FAILCRITICALERRORS | SEM_NOGPFAULTERRORBOX);
//#endif 
    WindowsErrorPopupBlocker();
    double getObjVal(std::string osrl);
    int   getItCount(std::string osrl);
    void tempPrintArrays(OSResult* os); //  OSrl parser development only
    //using CppAD::NearEqual;
    bool ok;
    double check;

    
    bool BASIC_TESTS;  // minimal functionality tests
    bool SOLVER_TESTS; // at least one problem for each solver
    bool THOROUGH;     // multiple problems for some solvers
    bool PARSER_TESTS; // test parser logic
    bool OTHER_TESTS;  // other input formats, b64 conversion, etc.
    
    //set level of testing
      
    std::string testConfig = "install";
    int testLevel = 1;
    if( argC > 2){
        std::cout << "Too Many Input Parameters" << std::endl;
        return 1;
    }
    if(argC == 2){
        testConfig = argV[ 1];
        std::cout << "test configuration = \'" <<  testConfig << "\'"<< std::endl;
    }

#ifdef GUS_DEBUG
    testConfig = "parser";
#endif

    if (testConfig == "install") testLevel = 1;
    if (testConfig == "parser" ) testLevel = 2;
    if (testConfig == "parsers") testLevel = 2;
    if (testConfig == "solver" ) testLevel = 3;
    if (testConfig == "solvers") testLevel = 3;
    if (testConfig == "release") testLevel = 4;
    if (testConfig == "nightlyBuild") testLevel = 4;
    if (testConfig == "all") testLevel = 4;
    if (testConfig == "NB") testLevel = 4;
    if (testConfig == "nb") testLevel = 4;

    switch (testLevel){
    case 1:
        BASIC_TESTS  = true;  
        SOLVER_TESTS = true; 
        THOROUGH     = false;     
        PARSER_TESTS = false; 
        OTHER_TESTS  = false;  
        break;
    case 2:
        BASIC_TESTS  = false;  
        SOLVER_TESTS = false; 
        THOROUGH     = false;     
        PARSER_TESTS = true; 
        OTHER_TESTS  = false;  
        break;
    case 3:
        BASIC_TESTS  = false;  
        SOLVER_TESTS = true; 
        THOROUGH     = true;     
        PARSER_TESTS = false; 
        OTHER_TESTS  = false;  
        break;
    case 4:
    default:
        BASIC_TESTS  = true;  
        SOLVER_TESTS = true; 
        THOROUGH     = true;     
        PARSER_TESTS = true; 
        OTHER_TESTS  = true;  
        break;
    }
    
    if (BASIC_TESTS) std::cout << "Perform basic tests" << std::endl;
    if (SOLVER_TESTS) {
        if (THOROUGH)
            std::cout << "Perform thorough solver tests" << std::endl;
        else
            std::cout << "Perform simple solver tests" << std::endl;
    }
    if (PARSER_TESTS) std::cout << "Perform parser tests" << std::endl;
    if (OTHER_TESTS) std::cout << "Perform other tests" << std::endl;
    std::cout << std::endl << std::endl;

    // end level of testing    
    
    cout << "START UNIT TEST" << endl;
    int nOfTest = 0;

    /**
     *  define commonly used objects and arrays
     *  Unless explicitly stated otherwise,
     *  each test is responsible for its own 
     *  memory management (i.e., new and delete)
     */
    FileUtil *fileUtil = NULL;  
#ifdef COIN_HAS_ASL
    OSnl2OS *nl2osil = NULL;
#endif 
    OSmps2osil *mps2osil = NULL;
    DefaultSolver *solver  = NULL;
    OSiLReader *osilreader = NULL;
    OSiLWriter *osilwriter = NULL;
    OSoLReader *osolreader = NULL;
    OSoLReader *osolreader2 = NULL;
    OSoLWriter *osolwriter = NULL;
    OSrLReader *osrlreader = NULL;
    OSrLWriter *osrlwriter = NULL;
    OSInstance *osinstance = NULL;
    OSOption *osoption = NULL;
    OSOption *osoption2 = NULL;
    OSOption *osoption3 = NULL;
    OSResult *osresult = NULL;
    OSResult *osresult1 = NULL;
    OSResult *osresult2 = NULL;
    OSResult *osresult3 = NULL;


    //common arrays
    std::string *nodeNames1 = NULL;
    std::string *nodeNames2 = NULL;
    double *x = NULL;

    //other common variables
    std::string osilFileName;
    std::string osolFileName;
    std::string osrlFileName;
    std::string nlFileName; 
    std::string mpsFileName;     
    std::string osil;
    std::string osol; 
    ostringstream unitTestResult;
    ostringstream unitTestResultFailure;

    // get the input files
     const char dirsep =  CoinFindDirSeparator();
      // Set directory containing data files.
      std::string dataDir;
    dataDir = dirsep == '/' ? "../data/" : "..\\data\\";
#ifdef GUS_DEBUG
    dataDir = "C:\\datafiles\\research\\OS\\OS-trunk-work\\OS\\data\\";
#endif



if(BASIC_TESTS == true){

    //first make sure we can read files
    try{
        std::cout << endl << "TEST " << ++nOfTest << ": Try to read a sample file" << endl << endl;

        fileUtil = new FileUtil();
        osilreader = new OSiLReader(); 
        osilwriter = new OSiLWriter();

        osilFileName =  dataDir  + "osilFiles" + dirsep +  "parincLinearByRow.osil";
        //osilFileName =  dataDir  + "osilFiles" + dirsep +  "parincLinear.osil";
        std::cout << "The file is: " ;
        std::cout <<  osilFileName << std::endl;
        osil = fileUtil->getFileAsString( osilFileName.c_str() );
        std::cout << "Done reading the test file" << std::endl;
        osinstance = osilreader->readOSiL( osil);
        //osinstance->initForAlgDiff();
        unitTestResult << "TEST " << nOfTest << ": Reading files successfully" << std::endl;
        cout << endl << "TEST " << nOfTest << ": Completed successfully" << endl << endl;
        osilwriter->m_bWhiteSpace = true;
        std::cout << osilwriter->writeOSiL( osinstance) << std::endl;

        delete fileUtil;
        fileUtil = NULL;
        delete osilreader;
        osilreader = NULL;
        delete osilwriter;
        osilwriter = NULL;
    }
    catch(const ErrorClass& eclass){
        unitTestResultFailure << "Sorry Unit Test Failed Reading a file: "  + eclass.errormsg<< endl; 
        //no point continuing -- we can't even read a file
        unitTestResultFailure << "Since we can't read files we are terminating"  << endl; 
        cout << unitTestResultFailure.str() << endl << endl;
        cout << "Conclusion: FAILURE" << endl;
        if (fileUtil != NULL)
        {
            delete fileUtil;
            fileUtil = NULL;
        }
        if (osilreader != NULL)
        {
            delete osilreader;
            osilreader = NULL;
        }
        if (osilwriter != NULL)
        {
            delete osilwriter;
            osilwriter = NULL;
        }
        return 1;
    }    
        
// Make sure we can read and write without loss of precision
    try{
        cout << endl << "TEST " << ++nOfTest << ": Lossless I/O" << endl << endl;

        osilwriter = new OSiLWriter();
        osilreader = new OSiLReader();

        //mpsFileName =  dataDir + "mpsFiles" + dirsep + "testfile2.mps";
        mpsFileName =  dataDir + "mpsFiles" + dirsep + "parinc.mps";
        mps2osil = new OSmps2osil( mpsFileName);

        // create the first in-memory OSInstance
        mps2osil->createOSInstance() ;
        // write the instance to a string
        OSInstance *osinstance1 = mps2osil->osinstance;
        std::string sOSiL = osilwriter->writeOSiL( osinstance1  );
#ifdef DEBUG
        cout << sOSiL << endl;
#endif

        // now create a second object
        OSInstance *osinstance2 = osilreader->readOSiL( sOSiL);
        // now compare the elements in the A matrix for the two instances
        int nvals = osinstance1->instanceData->linearConstraintCoefficients->numberOfValues;
        double theDiff, theMax;
        int theIndex = -1;
        theMax = 0;
        for(int i = 0; i < nvals; i++){
            theDiff = fabs(osinstance1->instanceData->linearConstraintCoefficients->value->el[ i] -
                osinstance2->instanceData->linearConstraintCoefficients->value->el[ i])/ fabs(osinstance1->instanceData->linearConstraintCoefficients->value->el[ i]);
            if(theDiff > theMax){
                theMax = theDiff;
                theIndex = i;
            }
            //std::cout << theDiff << std::endl;
        }
        std::cout << "MAXIMUM DIFF = " << theMax << std::endl;
        if(theMax > 0) 
        {
            std::cout << "MAXIMUM DIFF INDEX  = " << theIndex << std::endl;
            unitTestResult << "WARNING:  you do not have lossless IO" << std::endl;
        }
        else 
        {
            unitTestResult << "TEST " << nOfTest << ": Passed lossless IO test" << std::endl;
            cout << endl << "TEST " << nOfTest << ": Completed successfully" << endl << endl;
        }
        delete mps2osil;
        mps2osil = NULL;
        delete osilreader;
        osilreader = NULL;
        delete osilwriter;
        osilwriter = NULL;

    }
    catch(const ErrorClass& eclass){
        unitTestResultFailure << "Unit Test Failed Lossless I/O test: "  + eclass.errormsg<< endl; 
        if (mps2osil != NULL)
            delete mps2osil;
        mps2osil = NULL;
        if (osilreader != NULL)
            delete osilreader;
        osilreader = NULL;
        if (osilwriter != NULL)
            delete osilwriter;
        osilwriter = NULL;
    }    

    // now test the nonlinear operators    
    try{
        cout << endl << "TEST " << ++nOfTest << ": nonlinear operators" << endl << endl;

        osilreader = new OSiLReader();
        osilwriter = new OSiLWriter();
        fileUtil = new FileUtil();

        ok = true;
        std::string operatorTest =  dataDir  + "osilFiles" + dirsep + "testOperators.osil";
        osil = fileUtil->getFileAsString( operatorTest.c_str() );
//        cout << "Read testOperators.osil...";
        osinstance = osilreader->readOSiL( osil);
        
        cout << "Done" << endl;
        OSExpressionTree* expTree = osinstance->getNonlinearExpressionTree( -1);
        std::vector<OSnLNode*> postfixVec;
        postfixVec = expTree->m_treeRoot->getPostfixFromExpressionTree();
        int n = postfixVec.size();
        nodeNames1 = new std::string[ n];
        for (int i = 0 ; i < n; i++){
        //    std::cout << postfixVec[i]->getTokenName() << std::endl;
            nodeNames1[i] = postfixVec[i]->getTokenName();
        }
//        std::cout << std::endl << std::endl;
//        std::cout << osilwriter->writeOSiL( osinstance) << std::endl;
        // now test value
        x = new double[2];
        x[0] = 1;
        x[1] = 2;
//        double parserTestVal = expTree->m_treeRoot->calculateFunction( x);
//        std::cout << "ParserTest Val = " << parserTestVal << std::endl;
        check = 11;
        ok = ( fabs(check -  expTree->m_treeRoot->calculateFunction( x))/(fabs( check) + OS_NEAR_EQUAL) <= OS_NEAR_EQUAL) ? true : false;
        delete[] x;
        x = NULL;
        delete[] nodeNames1;
        nodeNames1 = NULL;
        delete osilreader;
        osilreader = NULL;
        delete osilwriter;
        osilwriter = NULL;
        delete fileUtil;
        fileUtil = NULL;

        if (ok == false) throw ErrorClass(" Problem evaluating expression tree");
        unitTestResult << "TEST " << nOfTest << ": Successful test of nonlinear operators using file testOperators.osil" << std::endl;
        cout << endl << "TEST " << nOfTest << ": Completed successfully" << endl << endl;
    }
    catch(const ErrorClass& eclass){
        cout << endl << endl << endl;
        unitTestResultFailure << eclass.errormsg << endl;
        if (x != NULL)
            delete[] x;
        x = NULL;
        if (nodeNames1 != NULL)
            delete[] nodeNames1;
        nodeNames1 = NULL;
        if (osilreader != NULL)
            delete osilreader;
        osilreader = NULL;
        if (osilwriter != NULL)
            delete osilwriter;
        osilwriter = NULL;
        if (fileUtil != NULL)
            delete fileUtil;
        fileUtil = NULL;
    }

    
    // Automatic differentiation
    try{
        cout << endl << "TEST " << ++nOfTest << ": Automatic differentiation" << endl << endl;

        fileUtil = new FileUtil();
        osilreader = new OSiLReader();

        std::string expTreeTest =  dataDir  + "osilFiles" + dirsep + "CppADTestLag.osil";
        /*
        min x0^2 + 9*x1   -- w[0]
        s.t. 
        33 - 105 + 1.37*x1 + 2*x3 + 5*x1 <= 10  -- y[0]
        ln(x0*x3)  + 7*x2 >= 10  -- y[1]
        Note: in the first constraint 33 is a constant term and 105 
        is part of the nl node
        */
        osil = fileUtil->getFileAsString( expTreeTest.c_str() );
        //OSInstance *osinstance = NULL;
        //osinstance = new OSInstance();
        //OSiLReader *osilreader = NULL;
        //create an osinstance
        osinstance = osilreader->readOSiL( osil);
        double *x;
        x = new double[ 4];
        x[0] = 1;
        x[1] = 5;
        x[2] = 10;
        x[3] = 5;
        SparseVector *sp;
        // get the gradient for constraint 1
        osinstance->getJacobianSparsityPattern();
        sp = osinstance->calculateConstraintFunctionGradient(x, 1, true);
//        for(int i = 0; i < sp->number; i++){
//            std::cout << "gradient value " << sp->values[i] << std::endl;
//        }
        ok = true;
        //check gradient for constraint with index 1
        double checkPartial2Con1 = 7.0 ;
        //ok &= NearEqual( sp->values[ 0], checkPartial2Con1, 1e-10, 1e-10); 
        ok = ( fabs(checkPartial2Con1 - sp->values[ 0] )/(fabs( checkPartial2Con1) + OS_NEAR_EQUAL) <= OS_NEAR_EQUAL) ? true : false;
        if(ok == false) throw ErrorClass(" Fail testing gradient calculation");
        double checkPartial0Con1 = (1./x[0])  ;
        //ok &= NearEqual(sp->values[ 1], checkPartial0Con1, 1e-10, 1e-10); 
        ok = ( fabs(checkPartial0Con1 - sp->values[ 1] )/(fabs( checkPartial0Con1) + OS_NEAR_EQUAL) <= OS_NEAR_EQUAL) ? true : false;
        if(ok == false) throw ErrorClass(" Fail testing gradient calculation");
        double checkPartial3Con1 = (1./x[3]) ;
        //ok &= NearEqual( sp->values[ 2], checkPartial3Con1, 1e-10, 1e-10); 
        ok = ( fabs(checkPartial3Con1 - sp->values[ 2] )/(fabs( checkPartial3Con1) + OS_NEAR_EQUAL) <= OS_NEAR_EQUAL) ? true : false;
        if(ok == false) throw ErrorClass(" Fail testing gradient calculation");
        delete sp;
        sp = NULL;
        SparseHessianMatrix *sh;
        // calcuate Hessian of objective function (index = -1)
        osinstance->getLagrangianHessianSparsityPattern( );
        sh = osinstance->calculateHessian(x, -1, true);
//        for(int i = 0; i < sh->hessDimension; i++){
//            std::cout << "Hessian value " << sh->hessValues[i] << std::endl;
//        }
        //ok &= NearEqual( sh->hessValues[ 0], 2., 1e-10, 1e-10);
        ok = ( fabs(2. - sh->hessValues[0] )/(2. + OS_NEAR_EQUAL) <= OS_NEAR_EQUAL) ? true : false;
        if(ok == false) throw ErrorClass(" Fail testing Hessian calculation"); 
        //ok &= NearEqual( sh->hessValues[ 1], 0., 1e-10, 1e-10);
        ok = ( fabs(0. - sh->hessValues[ 1] )/(0. + OS_NEAR_EQUAL) <= OS_NEAR_EQUAL) ? true : false;
        if(ok == false) throw ErrorClass(" Fail testing Hessian calculation");
        //ok &= NearEqual( sh->hessValues[ 2], 0., 1e-10, 1e-10);
        ok = ( fabs(0. - sh->hessValues[2] )/(0. + OS_NEAR_EQUAL) <= OS_NEAR_EQUAL) ? true : false;
        if(ok == false) throw ErrorClass(" Fail testing Hessian calculation");
        delete[] x; 
        x = NULL;
        delete osilreader;
        osilreader = NULL;
        delete fileUtil;
        fileUtil = NULL;
        unitTestResult << "TEST " << nOfTest << ": Successful test of AD gradient and Hessian calculations" << std::endl;
        cout << endl << "TEST " << nOfTest << ": Completed successfully" << endl << endl;
    }    
    catch(const ErrorClass& eclass){
        cout << endl << endl << endl;
        unitTestResultFailure << eclass.errormsg << endl;
        if (x != NULL)
            delete[] x;
        x = NULL;
        if (osilreader != NULL)
            delete osilreader;
        osilreader = NULL;
        if (fileUtil != NULL)
            delete fileUtil;
        fileUtil = NULL;
    }
} // end of if (BASIC_TESTS)


    //
    // Now test the parsers --- OSiL parser first
if (PARSER_TESTS){

//#if 0   //!!!  OSrL parser development
    try{ 
        cout << endl << "TEST " << ++nOfTest << ": Test parsing an OSiL file (parincLinear.osil)" << endl << endl;

        fileUtil = new FileUtil();
        osilreader = new OSiLReader(); 
        osilwriter = new OSiLWriter();

        clock_t start, finish;
        double duration;
        cout << "Test parsing a model" << endl;
        cout << "First read the file into a string" << endl;
        start = clock();
        osilFileName = dataDir  + "osilFiles" + dirsep + "parincLinear.osil";
        osil = fileUtil->getFileAsString( osilFileName.c_str());
        finish = clock();
        duration = (double) (finish - start) / CLOCKS_PER_SEC;
        cout << "Reading the file into a string took (seconds): "<< duration << endl;
        start = clock();
        cout << "PARSE THE OSIL STRING INTO AN OSINSTANCE OBJECT" << endl;
        osilreader->readOSiL( osil);
        //cout << osilwriter->writeOSiL( osilreader->readOSiL( osil)) << endl;

        delete osilreader;
        osilreader = NULL;
        delete osilwriter;
        osilwriter = NULL;
        delete fileUtil;
        fileUtil = NULL;

        finish = clock();
        duration = (double) (finish - start) / CLOCKS_PER_SEC;
        cout << "Parsing took (seconds): "<< duration << endl;
        unitTestResult << "TEST " << nOfTest << ": Successful test of OSiL parser on problem parincLinear.osil" << std::endl;
        cout << endl << "TEST " << nOfTest << ": Completed successfully" << endl << endl;
    }    
    catch(const ErrorClass& eclass){
        cout << endl << endl << endl;
        cout << eclass.errormsg << endl;
        unitTestResultFailure << "Sorry Unit Test Failed Testing An OSiL Parser" << endl;

        if (osilreader != NULL)
            delete osilreader;
        osilreader = NULL;
        if (osilwriter != NULL)
            delete osilwriter;
        osilwriter = NULL;
        if (fileUtil != NULL)
            delete fileUtil;
        fileUtil = NULL;
    }    

    // now test the get() and set() methods in OSInstance
    // use get() and set() methods to create a second OSInstance object (deep copy)
    OSInstance *osinstance2 = new OSInstance();

    try{
        cout << endl << "TEST " << ++nOfTest << ": OSInstance get() and set() methods" << endl << endl;

        fileUtil = new FileUtil();
        osilreader = new OSiLReader(); 

        osilFileName =  dataDir  + "osilFiles" + dirsep +  "rosenbrockmod.osil";
        osil = fileUtil->getFileAsString( osilFileName.c_str() );
        osinstance = osilreader->readOSiL( osil);


        // first copy header information
        std::string name, source, description, fileCreator, licence;

        name        = osinstance->getInstanceName();
        source      = osinstance->getInstanceSource();
        description = osinstance->getInstanceDescription();
        fileCreator = osinstance->getInstanceCreator();
        licence     = osinstance->getInstanceLicence();

        if (!osinstance2->setInstanceName(name)) throw ErrorClass("Error duplicating header information");
        if (!osinstance2->setInstanceSource(source)) throw ErrorClass("Error duplicating header information");
        if (!osinstance2->setInstanceDescription(description)) throw ErrorClass("Error duplicating header information");
        if (!osinstance2->setInstanceCreator(fileCreator)) throw ErrorClass("Error duplicating header information");
        if (!osinstance2->setInstanceLicence(licence)) throw ErrorClass("Error duplicating header information");

        // copy variables
        if (osinstance->instanceData->variables != NULL)
        {
            int nvar = osinstance->getVariableNumber();
    
            std::string *varname = osinstance->getVariableNames();
            char *vartype = osinstance->getVariableTypes();
            double *varlb = osinstance->getVariableLowerBounds();
            double *varub = osinstance->getVariableUpperBounds();

//            osinstance2->instanceData->variables = new Variables();
            osinstance2->instanceData->variables->numberOfVariables = nvar;
            osinstance2->instanceData->variables->var = new Variable*[nvar];

            if (!osinstance2->setVariables(nvar, varname, varlb, varub, vartype)) throw ErrorClass("Error duplicating variable information");
        }

        // copy objectives
        if (osinstance->instanceData->objectives != NULL)
        {
            int nobj = osinstance->getObjectiveNumber();

            std::string *objname    = osinstance->getObjectiveNames();
            std::string *objdir     = osinstance->getObjectiveMaxOrMins();
            double *objconst        = osinstance->getObjectiveConstants();
            double *objweight       = osinstance->getObjectiveWeights();
            SparseVector **objcoeff = osinstance->getObjectiveCoefficients();

//            osinstance2->instanceData->objectives = new Objectives();
            osinstance2->instanceData->objectives->numberOfObjectives = nobj;
            osinstance2->instanceData->objectives->obj = new Objective*[nobj];

            if (!osinstance2->setObjectives(nobj, objname, objdir, objconst, objweight, objcoeff)) throw ErrorClass("Error duplicating objective information");
        }

        // copy constraints
        if (osinstance->instanceData->constraints != NULL)
        {
            int ncon = osinstance->getConstraintNumber();

            std::string *conname = osinstance->getConstraintNames();
            double *conlb = osinstance->getConstraintLowerBounds();
            double *conub = osinstance->getConstraintUpperBounds();
            double *con_c = osinstance->getConstraintConstants();

//            osinstance2->instanceData->constraints = new Constraints();
            osinstance2->instanceData->constraints->numberOfConstraints = ncon;
            osinstance2->instanceData->constraints->con = new Constraint*[ncon];

            if (!osinstance2->setConstraints(ncon, conname, conlb, conub, con_c)) throw ErrorClass("Error duplicating constraint information");
        }

        // copy linear constraint coefficient matrix
        if (osinstance->instanceData->linearConstraintCoefficients != NULL)
        {
            int ncoef = osinstance->getLinearConstraintCoefficientNumber();
            bool isColMajor = osinstance->getLinearConstraintCoefficientMajor();
            int nstart;
            SparseMatrix* coeff;

        // getLinearConstraintCoefficients returns a pointer to a sparse matrix structure
            if (isColMajor)
            {
                nstart = osinstance->getVariableNumber();
                coeff = osinstance->getLinearConstraintCoefficientsInColumnMajor();
            }
            else
            {
                nstart = osinstance->getConstraintNumber();
                coeff = osinstance->getLinearConstraintCoefficientsInRowMajor();
            }

            if (!osinstance2->copyLinearConstraintCoefficients(ncoef, isColMajor,
                                coeff->values,  0, ncoef-1,
                                coeff->indexes, 0, ncoef-1,
                                coeff->starts,  0, nstart)) 
                            throw ErrorClass("Error duplicating linear constraint coefficients");
        }

        // copy quadratic terms
        if (osinstance->instanceData->quadraticCoefficients != NULL)
        {
            int nquad = osinstance->getNumberOfQuadraticTerms();
            QuadraticTerms* qcoef = osinstance->getQuadraticTerms();
        
            if (!osinstance2->setQuadraticTerms(nquad,
                                   qcoef->rowIndexes, qcoef->varOneIndexes, 
                                   qcoef->varTwoIndexes, qcoef->coefficients,
                                   0, nquad-1)) 
                throw ErrorClass("Error duplicating quadratic coefficients");
        }

        // copy nonlinear expressions
        Nl** root = NULL;

        if (osinstance->instanceData->nonlinearExpressions != NULL)
        {
            int nexpr = osinstance->getNumberOfNonlinearExpressions();
//            root = osinstance->getNonlinearExpressions();
            root = new Nl*[osinstance->getNumberOfNonlinearExpressions()];
            for (int i=0; i < osinstance->getNumberOfNonlinearExpressions(); i++)
            {
                root[i] = osinstance->instanceData->nonlinearExpressions->nl[i];
            }

            if (!osinstance2->setNonlinearExpressions(nexpr, root))
                throw ErrorClass("Error duplicating nonlinear expressions");
        }

        // remaining elements have not yet been finalized, so ignore

        // now compare the two instances
        if (!osinstance2->IsEqual(osinstance)) throw ErrorClass("Loss of data during duplication");

        delete osinstance2;
        osinstance2 = NULL;

        unitTestResult << "TEST " << nOfTest << ": Passed OSInstance get() and set() methods" << std::endl;
        cout << endl << "TEST " << nOfTest << ": Completed successfully" << endl << endl;

        delete osilreader;
        osilreader = NULL;
        delete osilwriter;
        osilwriter = NULL;
        delete fileUtil;
        fileUtil = NULL;

        if (root != NULL)
        {
//            for (int i=0; i < osinstance->getNumberOfNonlinearExpressions(); i++)
//                if (root[i] != NULL) delete root[i];
            delete [] root;
            root = NULL;
        }
    }
    catch(const ErrorClass& eclass){
        unitTestResultFailure << "Unit Test Failed OSInstance get() and set() methods: "  + eclass.errormsg<< endl; 
        if (osinstance2 != NULL)
            delete osinstance2;
        osinstance2 = NULL;
        if (osilreader != NULL)
            delete osilreader;
        osilreader = NULL;
        if (osilwriter != NULL)
            delete osilwriter;
        osilwriter = NULL;
        if (fileUtil != NULL)
            delete fileUtil;
        fileUtil = NULL;
    }    


#if 0
    //
    // Now test the extensions to the OSiL format: <timeDomain>, etc.

    // some pointer declarations
    std::string *sncheck = new std::string[6];
    int *nvcheck = new int[6];
    int *nccheck = new int[6];
    int *nocheck = new int[6];
    int **lvcheck = new int*[6];
    int **lccheck = new int*[6];
    int **locheck = new int*[6];
    std::string *sn1 = new std::string[6];
    int *nv1= new int[6];
    int *nc1 = new int[6];
    int *no1 = new int[6];
    int **lv1 = new int*[6];
    int **lc1 = new int*[6];
    int **lo1 = new int*[6];
    int *nelem = new int[4];
    int *startIdx = new int[4];
    int **VI = new int*[4];

    try{ 
        cout << endl << "TEST " << ++nOfTest << ": Stochastic extensions to OSiL" << endl << endl;

        osilreader = new OSiLReader(); 
        fileUtil = new FileUtil();

        clock_t start, finish;
        double duration;
        cout << "\nTest parsing a stochastic model" << endl;
        cout << "First read the file into a string" << endl;
        start = clock();
        osilFileName = dataDir  + "osilFiles" + dirsep + "finplan1.osil";
        osil = fileUtil->getFileAsString( &osilFileName[0]);
        finish = clock();
        duration = (double) (finish - start) / CLOCKS_PER_SEC;
        cout << "Reading the file into a string took (seconds): "<< duration << endl;
        start = clock();
        cout << "PARSE THE OSIL STRING INTO AN OSINSTANCE OBJECT" << endl;
        osilreader->readOSiL( osil);
        finish = clock();
        duration = (double) (finish - start) / CLOCKS_PER_SEC;
        cout << "Parsing took (seconds): "<< duration << endl;
        unitTestResult << "TEST " << nOfTest << ": Successful test of OSiL parser on problem finplan1.osil" << std::endl;
        cout << endl << "TEST " << nOfTest << ": Completed successfully" << endl << endl;
        delete osilreader;
        osilreader = NULL;
        delete fileUtil;
        fileUtil = NULL;
    }    
    catch(const ErrorClass& eclass){
        cout << endl << endl << endl;
        cout << eclass.errormsg << endl;
        unitTestResultFailure << "Error parsing an osil file with time domain information" << endl;        

        if (osilreader != NULL)
            delete osilreader;
        osilreader = NULL;
        if (fileUtil != NULL)
            delete fileUtil;
        fileUtil = NULL;
    }    
/** --------------------------------
 *  Test the get() and set() methods
 *  --------------------------------**/
    try{ 
        cout << endl << "TEST " << ++nOfTest << ": GET() AND SET() METHODS FOR TimeDomain OBJECT" << endl << endl;

        osilreader = new OSiLReader();

        //create an osinstance
        osinstance = osilreader->readOSiL( osil);
        std::string f = osinstance->getTimeDomainFormat();
        ok = (f == "stages");
        int n = osinstance->getTimeDomainStageNumber();
        ok &= (n == 6);

        sncheck[0] = "";
        sncheck[1] = "";
        sncheck[2] = "";
        sncheck[3] = "test";
        sncheck[4] = "Wha'zzup?";
        sncheck[5] = "";

        std::string* sn = osinstance->getTimeDomainStageNames();

        for (int i = 0; i < 6; i++)
            ok &= (sn[i] == sncheck[i]);

        int* nv = osinstance->getTimeDomainStageNumberOfVariables();

        nvcheck[0] = 2;
        nvcheck[1] = 2;
        nvcheck[2] = 0;
        nvcheck[3] = 0;
        nvcheck[4] = 2;
        nvcheck[5] = 2;

        for (int i = 0; i < 6; i++)
            ok &= (nv[i] == nvcheck[i]);

        int* nc = osinstance->getTimeDomainStageNumberOfConstraints();

        nccheck[0] = 1;
        nccheck[1] = 1;
        nccheck[2] = 0;
        nccheck[3] = 0;
        nccheck[4] = 1;
        nccheck[5] = 1;

        for (int i = 0; i < 6; i++)
            ok &= (nc[i] == nccheck[i]);

        int* no = osinstance->getTimeDomainStageNumberOfObjectives();

        nocheck[0] = 1;
        nocheck[1] = 1;
        nocheck[2] = 1;
        nocheck[3] = 0;
        nocheck[4] = 1;
        nocheck[5] = 1;

        for (int i = 0; i < 6; i++)
            ok &= (no[i] == nocheck[i]);

        int** lv = osinstance->getTimeDomainStageVarList();
        int** lc = osinstance->getTimeDomainStageConList();
        int** lo = osinstance->getTimeDomainStageObjList();

        for (int i = 0; i < 6; i++)
        {
            lvcheck[i] = new int[2];
            lccheck[i] = new int[2];
            locheck[i] = new int[2];
        };
        lvcheck[0][0] = 0;
        lvcheck[0][1] = 1;
        lvcheck[1][0] = 2;
        lvcheck[1][1] = 3;
        lvcheck[4][0] = 4;
        lvcheck[4][1] = 5;
        lvcheck[5][0] = 6;
        lvcheck[5][1] = 7;
        lccheck[0][0] = 0;
        lccheck[1][0] = 1;
        lccheck[4][0] = 2;
        lccheck[5][0] = 3;
        locheck[0][0] = -1;
        locheck[1][0] = -1;
        locheck[2][0] = -1;
        locheck[4][0] = -1;
        locheck[5][0] = -1;

        for (int i = 0; i < 6; i++) {
            for (int j = 0; j < nv[i]; j++) 
                ok &= (lvcheck[i][j] == lv[i][j]);
            for (int j = 0; j < nc[i]; j++) 
                ok &= (lccheck[i][j] == lc[i][j]);
            for (int j = 0; j < no[i]; j++) 
                ok &= (locheck[i][j] == lo[i][j]);
        };


        for (int i = 0; i < 6; i++) {
            sn1[i] = sn[i];
            nv1[i] = nv[i];
            nc1[i] = nc[i];
            no1[i] = no[i];
            lv1[i] = new int[2];
            lc1[i] = new int[2];
            lo1[i] = new int[2];
            for (int j = 0; j < nv[i]; j++) {
                lv1[i][j] = lv[i][j];
            };
            for (int j = 0; j < nc[i]; j++) {
                lc1[i][j] = lc[i][j];
            };
            for (int j = 0; j < no[i]; j++) {
                lo1[i][j] = lo[i][j];
            };
        };

        ok &= osinstance->setTimeDomain("none");
        n = 0;
        ok &= osinstance->setTimeDomainStages(n,NULL);
        ok &= osinstance->setTimeDomainStages(4,NULL);

        n = osinstance->getTimeDomainStageNumber();
        ok &= (n == 4);

        for (int i = 0; i < 4; i++)
        {    nelem[i] = 2;
            startIdx[i] = 2*i;
            VI[i] = new int[2];
            VI[i][0] = 2*i;
            VI[i][1] = 2*i + 1;
        };
        ok &= osinstance->setTimeDomainStageVariablesUnordered(4,nelem,VI);

        for (int i = 0; i < 4; i++)
        {    nelem[i] = 1;
            startIdx[i] = i;
        };
        ok &= osinstance->setTimeDomainStageConstraintsOrdered(4,nelem,startIdx);

        for (int i = 0; i < 4; i++)
        {    nelem[i] = 1;
            startIdx[i] = -1;
        };
        ok &= osinstance->setTimeDomainStageObjectivesOrdered(4,nelem,startIdx);

        ok &= osinstance->setTimeDomain("none");

        ok &= osinstance->setTimeDomain("interval");

        ok &= osinstance->setTimeDomainInterval(0.0, 1.0);
        double lower = osinstance->getTimeDomainIntervalStart();
        ok &= (lower == 0.0);
        double upper = osinstance->getTimeDomainIntervalHorizon();
        ok &= (upper == 1.0);

        ok &= osinstance->setTimeDomain("none");

        ok &= osinstance->setTimeDomainStages(6,sncheck);
        ok &= osinstance->setTimeDomainStageVariablesUnordered(6,nvcheck,lvcheck);
        ok &= osinstance->setTimeDomainStageObjectivesUnordered(6,nocheck,locheck);
        ok &= osinstance->setTimeDomainStageConstraintsUnordered(6,nccheck,lccheck);
        int n2 = osinstance->getTimeDomainStageNumber();
        ok &= (n2 == 6);
        std::string* sn2 = osinstance->getTimeDomainStageNames();
        int* nv2 = osinstance->getTimeDomainStageNumberOfVariables();
        int* nc2 = osinstance->getTimeDomainStageNumberOfConstraints();
        int* no2 = osinstance->getTimeDomainStageNumberOfObjectives();
        int** lv2 = osinstance->getTimeDomainStageVarList();
        int** lc2 = osinstance->getTimeDomainStageConList();
        int** lo2 = osinstance->getTimeDomainStageObjList();
        for (int i = 0; i < n2; i++)
        {    ok &= (sn2[i] == sncheck[i]);
            ok &= (nv2[i] == nvcheck[i]);
            ok &= (nc2[i] == nccheck[i]);
            ok &= (no2[i] == nocheck[i]);
            for (int j = 0; j < nv2[i]; j++)
                ok &= (lv2[i][j] == lvcheck[i][j]);
            for (int j = 0; j < nc2[i]; j++)
                ok &= (lc2[i][j] == lccheck[i][j]);
            for (int j = 0; j < no2[i]; j++)
                ok &= (lo2[i][j] == locheck[i][j]);
        };
        // Garbage Collection
        if (sncheck != NULL)
            delete [] sncheck;
        sncheck = NULL;
        if (nvcheck != NULL)
            delete [] nvcheck;
        nvcheck = NULL;
        if (nccheck != NULL)
            delete [] nccheck;
        nccheck = NULL;
        if (nocheck != NULL)
            delete [] nocheck;
        nocheck = NULL;
    
        for (int i = 0; i < 6; i++) {
            if (lvcheck[i] != NULL)
                delete [] lvcheck[i];
            if (lccheck[i] != NULL)
                delete [] lccheck[i];
            if (locheck[i] != NULL)
                delete [] locheck[i];
            if (lv1[i] != NULL)
                delete [] lv1[i];
            if (lc1[i] != NULL)
                delete [] lc1[i];
            if (lo1[i] != NULL)
                delete [] lo1[i];
            };
        if (lvcheck != NULL)
            delete [] lvcheck;
        lvcheck = NULL;
        if (lccheck != NULL)
            delete [] lccheck;
        lccheck = NULL;
        if (locheck != NULL)
            delete [] locheck;
        locheck = NULL;
        if (lv1 != NULL)
            delete [] lv1;
        lv1 = NULL;
        if (lc1 != NULL)
            delete [] lc1;
        lc1 = NULL;
        if (lo1 != NULL)
            delete [] lo1;
        lo1 = NULL;
        if (sn1 != NULL)
            delete [] sn1;
        sn1 = NULL;
        if (nv1 != NULL)
            delete[] nv1;
        nv1 = NULL;
        if (nc1    != NULL)
            delete[] nc1;
        nc1 = NULL;
        if (no1 != NULL)
            delete[] no1;
        no1 = NULL;
        if (nelem != NULL)
            delete [] nelem;
        nelem = NULL;
        if (startIdx != NULL)
            delete [] startIdx;
        startIdx = NULL;
        if (VI != NULL)
        {
            for (int i = 0; i < 4; i++) {
                if (VI[i] != NULL)
                    delete [] VI[i];
            };
            delete [] VI;
            VI = NULL;
        }    

        if (osilreader != NULL)
            delete osilreader;
        osilreader = NULL;
        unitTestResult << "TEST " << nOfTest << ": Successful test of osinstance get() and set() methods" << std::endl;
        cout << endl << "TEST " << nOfTest << ": Completed successfully" << endl << endl;
    }    
    catch(const ErrorClass& eclass){
        cout << endl << endl << endl;
        cout << eclass.errormsg << endl;
        unitTestResultFailure << "Sorry Unit Test Failed osinstance get() and set() Methods" << endl;        
        // Garbage Collection
        if (sncheck != NULL)
            delete [] sncheck;
        sncheck = NULL;
        if (nvcheck != NULL)
            delete [] nvcheck;
        nvcheck = NULL;
        if (nccheck != NULL)
            delete [] nccheck;
        nccheck = NULL;
        if (nocheck != NULL)
            delete [] nocheck;
        nocheck = NULL;

        for (int i = 0; i < 6; i++) {
            if (lvcheck[i] != NULL)
                delete [] lvcheck[i];
            if (lccheck[i] != NULL)
                delete [] lccheck[i];
            if (locheck[i] != NULL)
                delete [] locheck[i];
            if (lv1[i] != NULL)
                delete [] lv1[i];
            if (lc1[i] != NULL)
                delete [] lc1[i];
            if (lo1[i] != NULL)
                delete [] lo1[i];
            };
        if (lvcheck != NULL)
            delete [] lvcheck;
        lvcheck = NULL;
        if (lccheck != NULL)
            delete [] lccheck;
        lccheck = NULL;
        if (locheck != NULL)
            delete [] locheck;
        locheck = NULL;
        if (lv1 != NULL)
            delete [] lv1;
        lv1 = NULL;
        if (lc1 != NULL)
            delete [] lc1;
        lc1 = NULL;
        if (lo1 != NULL)
            delete [] lo1;
        lo1 = NULL;
        if (sn1 != NULL)
            delete [] sn1;
        sn1 = NULL;
        if (nv1 != NULL)
            delete[] nv1;
        nv1 = NULL;
        if (nc1 != NULL)
            delete[] nc1;
        nc1 = NULL;
        if (no1 != NULL)
            delete[] no1;
        no1 = NULL;
        if (nelem != NULL)
            delete [] nelem;
        nelem = NULL;
        if (startIdx != NULL)
            delete [] startIdx;
        startIdx = NULL;
        if (VI != NULL)
        {
            for (int i = 0; i < 4; i++) {
                if (VI[i] != NULL)
                    delete [] VI[i];
            };
            delete [] VI;
            VI = NULL;
        }    

        if (osilreader != NULL)
            delete osilreader;
        osilreader = NULL;
    }    
#endif // test of <timeDomain> and various set() and get) methods

    //
    // Now test the OSoL parser

    try{ 
        /**
         * in this part of the unitTest we
         * 1) read an OSoL string from a file
         * 2) create an OSOption object from the string
         * 3) add options to various array-valued elements
         * 4) retrieve pieces of the OSOption object with get() methods
         * 5) insert these pieces into a second OSOption object with set() methods
         * 6) compare the two OSOption objects to make sure they are equal
         * 7) write a new OSoL string from the in-memory OSOption object
         * 8) read the string back again into a third OSOption object
         * 9) compare to the original OSOption object
         *10) read two more OSoL strings from different files
         *11) test the deep copy
         */
        cout << endl << "TEST " << ++nOfTest << ": OSoL parser" << endl << endl;

        fileUtil = new FileUtil();
        osolwriter = new OSoLWriter();
        osolreader = new OSoLReader();

        std::string tmpOSoL;
        clock_t start, finish;
        double duration;
        cout << "Test parsing an OSoL file" << endl;
        cout << "First read the OSoL file into a string" << endl;
        osolFileName = dataDir  + "osolFiles" + dirsep + "parsertest.osol"; 
        cout << osolFileName << endl;
        start = clock();
        std::string osol = fileUtil->getFileAsString( osolFileName.c_str() );
        finish = clock();
        duration = (double) (finish - start) / CLOCKS_PER_SEC;
        cout << "Reading the file into a string took (seconds): "<< duration << endl;
        start = clock();
        cout << "PARSE THE OSOL STRING INTO AN OSOPTION OBJECT" << endl;
        osoption = osolreader->readOSoL( osol);

        //Pad all the arrays
        cout << endl << "Test the add() methods" << endl;
        
        ok = osoption->setAnOtherGeneralOption("testing","one","two  three");
        ok = osoption->setOtherSystemOptions(0,NULL) && ok; 
        ok = osoption->setAnOtherSystemOption("Ho Ho Ho","","") && ok;
        ok = osoption->setAnOtherServiceOption("OneMore","Option","To Go") && ok;
        ok = osoption->setAnotherJobDependency("DoReMi") && ok;
        ok = osoption->setAnotherRequiredDirectory("C:\\MSYS") && ok;
        ok = osoption->setAnotherRequiredFile("C:\\MSYS\\junk.tmp") && ok;
        ok = osoption->setAnotherDirectoryToMake("C:\\tempdir") && ok;
        ok = osoption->setAnotherFileToMake("C:\\tempdir\\temp.tmp") && ok;
        ok = osoption->setAnotherInputDirectoryToMove("C:\\tempdir","C:\\OS\\calc",true) && ok;
        ok = osoption->setAnotherInputFileToMove("C:\\OS\\parinc.osil","C:\\OS\\calc\\input.osil",true) && ok;
        ok = osoption->setAnotherOutputFileToMove("C:\\OS\\calc\\putput.osrl","C:\\OS\\parinc.osol",false) && ok;
        ok = osoption->setAnotherOutputDirectoryToMove("C:\\OS\\calc","C:\\OS\\save",false) && ok;
        ok = osoption->setAnotherFileToDelete("C:\\OS\\calc\\input.osil") && ok;
        ok = osoption->setAnotherDirectoryToDelete("C:\\tempdir") && ok;
        ok = osoption->setAnotherProcessToKill("ABC123") && ok;
        ok = osoption->setAnOtherJobOption("DoReMi","ABC","One Two Three") && ok;
        ok = osoption->setAnotherInitVarValue(5,12.3) && ok;
        ok = osoption->setAnotherInitVarValueString(6,"BLUE") && ok;
        ok = osoption->setAnotherInitBasisStatus(ENUM_PROBLEM_COMPONENT_variables,6,ENUM_BASIS_STATUS_unknown) && ok;
        ok = osoption->setAnotherInitBasisStatus(ENUM_PROBLEM_COMPONENT_objectives,-1,ENUM_BASIS_STATUS_basic) && ok;
        ok = osoption->setAnotherInitBasisStatus(ENUM_PROBLEM_COMPONENT_constraints,3,ENUM_BASIS_STATUS_superbasic) && ok;
        ok = osoption->setAnotherIntegerVariableBranchingWeight(5,100.) && ok;

        int SOS3idx[2];
        double SOS3val[2];
        std::string SOS3nam[2];
        SOS3idx[0] = 3;
        SOS3idx[1] = 6;
        SOS3val[0] = 1.0;
        SOS3val[1] = 2.0;
        SOS3nam[0] = "a name";
        SOS3nam[1] = "another";
        int tnvar;
        tnvar = osoption->getNumberOfSOS(); 
        ok = osoption->setAnotherSOSVariableBranchingWeight(3,2,1.0,SOS3idx,SOS3val,SOS3nam) && ok;
        assert (osoption->getNumberOfSOS() == (tnvar + 1));
        assert (osoption->optimization->variables->sosVariableBranchingWeights->sos[tnvar]->var[0]->idx == 3);
        assert (osoption->optimization->variables->sosVariableBranchingWeights->sos[tnvar]->var[1]->idx == 6);
        assert (osoption->optimization->variables->sosVariableBranchingWeights->sos[tnvar]->var[0]->value == 1.0);
        assert (osoption->optimization->variables->sosVariableBranchingWeights->sos[tnvar]->var[1]->value == 2.0);
        assert (osoption->optimization->variables->sosVariableBranchingWeights->sos[tnvar]->var[0]->name == "a name");
        assert (osoption->optimization->variables->sosVariableBranchingWeights->sos[tnvar]->var[1]->name == "another");
#ifdef DEBUG
        cout << endl << "another SOS has been added" << endl << endl;
#endif

        OtherVariableOption *varopt;
        varopt = new OtherVariableOption();
        varopt->name = "testVarOpt";
        varopt->numberOfVar = 2;
        varopt->numberOfEnumerations = 0;
        varopt->var = new OtherVarOption*[2];
        varopt->var[0] = new OtherVarOption();
        varopt->var[0]->idx = 0;
        varopt->var[0]->value = "3.0";
        varopt->var[1] = new OtherVarOption();
        varopt->var[1]->idx = 1;
        varopt->var[1]->lbValue = "0.0";
        varopt->var[1]->ubValue = "10.0";
        ok = osoption->setAnOtherVariableOption(varopt) && ok;
        delete varopt;
        varopt = NULL;
#ifdef DEBUG
        cout << endl << "another variable option has been added" << endl << endl;
#endif

        OtherObjectiveOption *objopt;
        objopt = new OtherObjectiveOption();
        objopt->name = "testObjOpt";
        objopt->numberOfObj = 0;
        objopt->numberOfEnumerations = 0;
        ok = osoption->setAnOtherObjectiveOption(objopt) && ok;
        delete objopt;
        objopt = NULL;
#ifdef DEBUG
        cout << endl << "another objective option has been added" << endl << endl;
#endif

        ok = osoption->setAnotherInitConValue(2,17.0) && ok;
        ok = osoption->setAnotherInitDualVarValue(2,0.0,DBL_MAX) && ok;

        OtherConstraintOption *conopt;
        conopt = new OtherConstraintOption();
        conopt->name = "testConOpt";

        conopt->numberOfCon = 0;
        conopt->numberOfEnumerations = 1;

        conopt->enumeration = new OtherOptionEnumeration*[1];
        conopt->enumeration[0] = new OtherOptionEnumeration();
        conopt->enumeration[0]->numberOfEl = 3;
        conopt->enumeration[0]->value = "test";
        conopt->enumeration[0]->description = "this is not a test";
        conopt->enumeration[0]->numberOfEl = 3;
        conopt->enumeration[0]->el = new int[3];
        conopt->enumeration[0]->el[0] = 1;
        conopt->enumeration[0]->el[1] = 3;
        conopt->enumeration[0]->el[2] = 5;

        ok = osoption->setAnOtherConstraintOption(conopt) && ok;
        delete conopt;
        conopt = NULL;
#ifdef DEBUG
        cout << endl << "another constraint option has been added" << endl << endl;
#endif

        ok = osoption->setAnotherSolverOption("HoHum","gus","PhoNY","","test","") && ok;

        if (!ok)
            throw ErrorClass(" Could not add to osoption data structure");

        //Now transfer to another osoption using get() and set() methods
        std::string optionstring, fileName, fileSource, fileDescription, fileCreator, fileLicence;
        int option_i;
        double option_d;
//        OSOption* osoption2;
        osoption2= new OSOption();

        cout << endl << "transfer osoption to another OSOption object" << endl;
        
        fileName        = osoption->getFileName();
        fileSource      = osoption->getFileSource();
        fileDescription = osoption->getFileDescription();
        fileCreator     = osoption->getFileCreator();
        fileLicence     = osoption->getFileLicence();
        ok = osoption2->setOptionHeader(fileName, fileSource, fileDescription, fileCreator, fileLicence);
#ifdef DEBUG
        if (!ok)
            throw ErrorClass(" error in get/set option header");
#endif


        optionstring = osoption->getServiceURI();
        ok = osoption2->setServiceURI(optionstring);
#ifdef DEBUG
        if (!ok)
            throw ErrorClass(" error in get/set ServiceURI");
#endif

        optionstring = osoption->getServiceName();
        ok = osoption2->setServiceName(optionstring) && ok;
#ifdef DEBUG
        if (!ok)
            throw ErrorClass(" error in get/set ServiceName");
#endif

        optionstring = osoption->getInstanceName();
        ok = osoption2->setInstanceName(optionstring) && ok;
#ifdef DEBUG
        if (!ok)
            throw ErrorClass(" error in get/set InstanceName");
#endif

        optionstring = osoption->getInstanceLocation();
        ok = osoption2->setInstanceLocation(optionstring) && ok;
#ifdef DEBUG
        if (!ok)
            throw ErrorClass(" error in get/set InstanceLocation");
#endif

        optionstring = osoption->getInstanceLocationType();
        ok = osoption2->setInstanceLocationType(optionstring) && ok;
#ifdef DEBUG
        if (!ok)
            throw ErrorClass(" error in get/set InstanceLocationtype");
#endif

        optionstring = osoption->getJobID();
        ok = osoption2->setJobID(optionstring) && ok;
#ifdef DEBUG
        if (!ok)
            throw ErrorClass(" error in get/set JobID");
#endif

        optionstring = osoption->getSolverToInvoke();
        ok = osoption2->setSolverToInvoke(optionstring) && ok;
#ifdef DEBUG
        if (!ok)
            throw ErrorClass(" error in get/set SolverToInvoke");
#endif

        optionstring = osoption->getInstanceLocationType();
        ok = osoption2->setInstanceLocationType(optionstring) && ok;
#ifdef DEBUG
        if (!ok)





            throw ErrorClass(" error in get/set InstanceLocationType");
#endif

        optionstring = osoption->getUserName();
        ok = osoption2->setUserName(optionstring) && ok;
#ifdef DEBUG
        if (!ok)
            throw ErrorClass(" error in get/set UserName");
#endif

        optionstring = osoption->getPassword();
#ifdef DEBUG
        if (!ok)
            throw ErrorClass(" error in get/set Password");
#endif
        ok = osoption2->setPassword(optionstring) && ok;

        optionstring = osoption->getContact();
        ok = osoption2->setContact(optionstring) && ok;
#ifdef DEBUG
        if (!ok)
            throw ErrorClass(" error in get/set Contact");
#endif
        
        optionstring = osoption->getContactTransportType();
        ok = osoption2->setContactTransportType(optionstring) && ok;
#ifdef DEBUG
        if (!ok)
            throw ErrorClass(" error in get/set TransportType");
#endif

        int nopt;
        OtherOption** otherOpt;
        nopt = osoption->getNumberOfOtherGeneralOptions();
        otherOpt = osoption->getOtherGeneralOptions();
        ok = osoption2->setOtherGeneralOptions(nopt, otherOpt) && ok;
#ifdef DEBUG
        if (!ok)
            throw ErrorClass(" error in get/set OtherGeneralOption");
#endif
        
        std::string tempDescription;

        optionstring = osoption->getMinDiskSpaceUnit();
        tempDescription = osoption->getMinDiskSpaceDescription();
        option_d = osoption->getMinDiskSpace();
        ok = osoption2->setMinDiskSpace(optionstring,tempDescription,option_d) && ok;
#ifdef DEBUG
        if (!ok)
            throw ErrorClass(" error in get/set MinDiskSpace");
#endif

        optionstring = osoption->getMinMemoryUnit();
        tempDescription = osoption->getMinMemoryDescription();
        option_d = osoption->getMinMemorySize();
        ok = osoption2->setMinMemorySize(optionstring,tempDescription,option_d) && ok;
#ifdef DEBUG
        if (!ok)
            throw ErrorClass(" error in get/set MinMemorySize");
#endif

        optionstring = osoption->getMinCPUSpeedUnit();
        tempDescription = osoption->getMinCPUSpeedDescription();
        option_d = osoption->getMinCPUSpeed();
        ok = osoption2->setMinCPUSpeed(optionstring,tempDescription,option_d) && ok;
#ifdef DEBUG
        if (!ok)
            throw ErrorClass(" error in get/set MinCPUSpeed");
#endif

        option_i = osoption->getMinCPUNumber();
        optionstring = osoption->getMinCPUNumberDescription();
        ok = osoption2->setMinCPUNumber(option_i, optionstring) && ok;
#ifdef DEBUG
        if (!ok)
            throw ErrorClass(" error in get/set MinCPUNumber");
#endif

        OtherOption** otherOpt2;
        nopt = osoption->getNumberOfOtherSystemOptions();
        otherOpt2 = osoption->getOtherSystemOptions();
        ok = osoption2->setOtherSystemOptions(nopt, otherOpt2) && ok;
#ifdef DEBUG
        if (!ok)
            throw ErrorClass(" error in get/set OtherSystemOptions");
#endif


        optionstring = osoption->getServiceType();
        ok = osoption2->setServiceType(optionstring) && ok;
#ifdef DEBUG
        if (!ok)
            throw ErrorClass(" error in get/set ServiceType");
#endif

        OtherOption** otherOpt3;
        nopt = osoption->getNumberOfOtherServiceOptions();
        otherOpt3 = osoption->getOtherServiceOptions();
        ok = osoption2->setOtherServiceOptions(nopt, otherOpt3) && ok;
#ifdef DEBUG
        if (!ok)
            throw ErrorClass(" error in get/set OtherServiceOptions");
#endif


        option_d = osoption->getMaxTime();
        ok = osoption2->setMaxTime(option_d) && ok;
#ifdef DEBUG
        if (!ok)
            throw ErrorClass(" error in get/set MaxTime");
#endif

        optionstring = osoption->getMaxTimeUnit();
        ok = osoption2->setMaxTimeUnit(optionstring) && ok;
#ifdef DEBUG
        if (!ok)
            throw ErrorClass(" error in get/set MaxTimeUnit");
#endif

        optionstring = osoption->getRequestedStartTime();
        ok = osoption2->setRequestedStartTime(optionstring) && ok;
#ifdef DEBUG
        if (!ok)
            throw ErrorClass(" error in get/set RequestedStartTime");
#endif

        nopt = osoption->getNumberOfJobDependencies();
        std::string* tJobID = osoption->getJobDependencies();
        ok = osoption2->setJobDependencies(nopt, tJobID) && ok;
#ifdef DEBUG
        if (!ok)
            throw ErrorClass(" error in get/set JobDependencies");
#endif

        nopt = osoption->getNumberOfRequiredDirectories();
        std::string* reqDir = osoption->getRequiredDirectories();
        ok = osoption2->setRequiredDirectories(nopt, reqDir) && ok;
#ifdef DEBUG
        if (!ok)
            throw ErrorClass(" error in get/set RequiredDirectories");
#endif

        nopt = osoption->getNumberOfRequiredFiles();
        std::string* reqFil = osoption->getRequiredFiles();
        ok = osoption2->setRequiredFiles(nopt, reqFil) && ok;
#ifdef DEBUG
        if (!ok)
            throw ErrorClass(" error in get/set RequiredFiles");
#endif

        nopt = osoption->getNumberOfDirectoriesToMake();
        std::string* mkDir = osoption->getDirectoriesToMake();
        ok = osoption2->setDirectoriesToMake(nopt, mkDir) && ok;
#ifdef DEBUG
        if (!ok)
            throw ErrorClass(" error in get/set DirectoriesToMake");
#endif

        nopt = osoption->getNumberOfFilesToMake();
        std::string* mkFil = osoption->getFilesToMake();
        ok = osoption2->setFilesToMake(nopt, mkFil) && ok;
#ifdef DEBUG
        if (!ok)
            throw ErrorClass(" error in get/set FilesToMake");
#endif

        nopt = osoption->getNumberOfInputDirectoriesToMove();
        PathPair** inDMv = osoption->getInputDirectoriesToMove();
        ok = osoption2->setInputDirectoriesToMove(nopt, inDMv) && ok;
#ifdef DEBUG
        if (!ok)
            throw ErrorClass(" error in get/set InputDirectoriesToMove");
#endif

        nopt = osoption->getNumberOfInputFilesToMove();
        PathPair** inFMv = osoption->getInputFilesToMove();
        ok = osoption2->setInputFilesToMove(nopt, inFMv) && ok;
#ifdef DEBUG
        if (!ok)
            throw ErrorClass(" error in get/set InputFilesToMove");
#endif

        nopt = osoption->getNumberOfOutputFilesToMove();
        PathPair** outFMv = osoption->getOutputFilesToMove();
        ok = osoption2->setOutputFilesToMove(nopt, outFMv) && ok;
#ifdef DEBUG
        if (!ok)
            throw ErrorClass(" error in get/set OutputFilesToMove");
#endif

        nopt = osoption->getNumberOfOutputDirectoriesToMove();
        PathPair** outDMv = osoption->getOutputDirectoriesToMove();
        ok = osoption2->setOutputDirectoriesToMove(nopt, outDMv) && ok;
#ifdef DEBUG
        if (!ok)
            throw ErrorClass(" error in get/set OutputDirectoriesToMove");
#endif

        nopt = osoption->getNumberOfFilesToDelete();
        std::string* rmFil = osoption->getFilesToDelete();
        ok = osoption2->setFilesToDelete(nopt, rmFil) && ok;
#ifdef DEBUG
        if (!ok)
            throw ErrorClass(" error in get/set FilesToDelete");
#endif

        nopt = osoption->getNumberOfDirectoriesToDelete();
        std::string* rmDir = osoption->getDirectoriesToDelete();
        ok = osoption2->setDirectoriesToDelete(nopt, rmDir) && ok;
#ifdef DEBUG
        if (!ok)
            throw ErrorClass(" error in get/set DirectoriesToDelete");
#endif

        nopt = osoption->getNumberOfProcessesToKill();
        std::string* rmProc = osoption->getProcessesToKill();
        ok = osoption2->setProcessesToKill(nopt, rmProc) && ok;
#ifdef DEBUG
        if (!ok)
            throw ErrorClass(" error in get/set ProcessesToKill");
#endif

        OtherOption** otherOpt4;
        nopt = osoption->getNumberOfOtherJobOptions();
        otherOpt4 = osoption->getOtherJobOptions();
        ok = osoption2->setOtherJobOptions(nopt, otherOpt4) && ok;
#ifdef DEBUG
        if (!ok)
            throw ErrorClass(" error in get/set OtherJobOptions");
#endif

        int nvar, nobj, ncon;
        nvar = osoption->getOptionInt("numberOfVariables");
        ok = osoption2->setNumberOfVariables(nvar) && ok;
        nobj = osoption->getOptionInt("numberOfObjectives");
        ok = osoption2->setNumberOfObjectives(nobj) && ok;
        ncon = osoption->getOptionInt("numberOfConstraints");
        ok = osoption2->setNumberOfConstraints(ncon) && ok;
        // eliminate references to numberOfVariables
        nvar = 10; 
        nobj = 2; 
        ncon = 8; 
#ifdef DEBUG
        if (!ok)
            throw ErrorClass(" error in get/set problem dimensions");
#endif
 
// use sparse methods only because some schema elements allow NaN
        nopt = osoption->getNumberOfInitVarValues();
        InitVarValue** IVV;
        IVV = osoption->getInitVarValuesSparse();
        ok = osoption2->setInitVarValuesSparse(nopt, IVV) && ok;
#ifdef DEBUG
        if (!ok)
            throw ErrorClass(" error in get/set InitVarValues");
#endif

        nopt = osoption->getNumberOfInitVarValuesString();

        InitVarValueString** IVV2;
        IVV2 = osoption->getInitVarValuesStringSparse();
        ok = osoption2->setInitVarValuesStringSparse(nopt, IVV2) && ok;        
#ifdef DEBUG
        if (!ok)
            throw ErrorClass(" error in get/set InitVarValuesString");
#endif

        int*  IBS;

        nvar = osoption->getNumberOfInitialBasisElements(ENUM_PROBLEM_COMPONENT_variables,ENUM_BASIS_STATUS_basic);
        if (nvar > 0)
        {
            IBS = new int[nvar];
            ok = osoption->getInitialBasisElements(ENUM_PROBLEM_COMPONENT_variables,ENUM_BASIS_STATUS_basic,IBS);
            ok = osoption2->setInitBasisStatus(ENUM_PROBLEM_COMPONENT_variables,ENUM_BASIS_STATUS_basic, IBS, nvar) && ok;
            delete[] IBS;
#ifdef DEBUG
            if (!ok)
                throw ErrorClass(" error in get/set InitBasisStatus");
#endif
        }

        nvar = osoption->getNumberOfInitialBasisElements(ENUM_PROBLEM_COMPONENT_variables,ENUM_BASIS_STATUS_atLower);
        if (nvar > 0)
        {
            IBS = new int[nvar];

            ok = osoption->getInitialBasisElements(ENUM_PROBLEM_COMPONENT_variables,ENUM_BASIS_STATUS_atLower,IBS);
            ok = osoption2->setInitBasisStatus(ENUM_PROBLEM_COMPONENT_variables,ENUM_BASIS_STATUS_atLower, IBS, nvar) && ok;
            delete[] IBS;
#ifdef DEBUG
            if (!ok)
                throw ErrorClass(" error in get/set InitBasisStatus");
#endif
        }

        nvar = osoption->getNumberOfInitialBasisElements(ENUM_PROBLEM_COMPONENT_variables,ENUM_BASIS_STATUS_atUpper);
        if (nvar > 0)
        {
            IBS = new int[nvar];
            ok = osoption->getInitialBasisElements(ENUM_PROBLEM_COMPONENT_variables,ENUM_BASIS_STATUS_atUpper,IBS);
            ok = osoption2->setInitBasisStatus(ENUM_PROBLEM_COMPONENT_variables,ENUM_BASIS_STATUS_atUpper, IBS, nvar) && ok;
            delete[] IBS;
#ifdef DEBUG
            if (!ok)
                throw ErrorClass(" error in get/set InitBasisStatus");
#endif
        }

        nvar = osoption->getNumberOfInitialBasisElements(ENUM_PROBLEM_COMPONENT_variables,ENUM_BASIS_STATUS_atEquality);
        if (nvar > 0)
        {
            IBS = new int[nvar];
            ok = osoption->getInitialBasisElements(ENUM_PROBLEM_COMPONENT_variables,ENUM_BASIS_STATUS_atEquality,IBS);
            ok = osoption2->setInitBasisStatus(ENUM_PROBLEM_COMPONENT_variables,ENUM_BASIS_STATUS_atEquality, IBS, nvar) && ok;
            delete[] IBS;
#ifdef DEBUG
            if (!ok)
                throw ErrorClass(" error in get/set InitBasisStatus");
#endif
        }

        nvar = osoption->getNumberOfInitialBasisElements(ENUM_PROBLEM_COMPONENT_variables,ENUM_BASIS_STATUS_isFree);
        if (nvar > 0)
        {
            IBS = new int[nvar];
            ok = osoption->getInitialBasisElements(ENUM_PROBLEM_COMPONENT_variables,ENUM_BASIS_STATUS_isFree,IBS);
            ok = osoption2->setInitBasisStatus(ENUM_PROBLEM_COMPONENT_variables,ENUM_BASIS_STATUS_isFree, IBS, nvar) && ok;
            delete[] IBS;
#ifdef DEBUG
            if (!ok)
                throw ErrorClass(" error in get/set InitBasisStatus");
#endif
        }

        nvar = osoption->getNumberOfInitialBasisElements(ENUM_PROBLEM_COMPONENT_variables,ENUM_BASIS_STATUS_superbasic);
        if (nvar > 0)
        {
            IBS = new int[nvar];
            ok = osoption->getInitialBasisElements(ENUM_PROBLEM_COMPONENT_variables,ENUM_BASIS_STATUS_superbasic,IBS);
            ok = osoption2->setInitBasisStatus(ENUM_PROBLEM_COMPONENT_variables,ENUM_BASIS_STATUS_superbasic, IBS, nvar) && ok;
            delete[] IBS;
#ifdef DEBUG
            if (!ok)
                throw ErrorClass(" error in get/set InitBasisStatus");
#endif
        }

        nvar = osoption->getNumberOfInitialBasisElements(ENUM_PROBLEM_COMPONENT_variables,ENUM_BASIS_STATUS_unknown);
        if (nvar > 0)
        {
            IBS = new int[nvar];
            ok = osoption->getInitialBasisElements(ENUM_PROBLEM_COMPONENT_variables,ENUM_BASIS_STATUS_unknown,IBS);
            ok = osoption2->setInitBasisStatus(ENUM_PROBLEM_COMPONENT_variables,ENUM_BASIS_STATUS_unknown, IBS, nvar) && ok;
            delete[] IBS;
#ifdef DEBUG
            if (!ok)
                throw ErrorClass(" error in get/set InitBasisStatus");
#endif
        }


        BranchingWeight** BW;
        BW = osoption->getIntegerVariableBranchingWeightsSparse();
        nopt = osoption->getNumberOfIntegerVariableBranchingWeights();
        ok = osoption2->setIntegerVariableBranchingWeightsSparse(nopt, BW) && ok;
#ifdef DEBUG
        if (!ok)
            throw ErrorClass(" error in get/set IntegerVariableBranchingWeights");
#endif

        SOSWeights** sos;
        sos = osoption->getSOSVariableBranchingWeightsSparse();
        nopt = osoption->getNumberOfSOS();
        ok = osoption2->setSOSVariableBranchingWeights(nopt, sos) && ok;
#ifdef DEBUG
        if (!ok)
            throw ErrorClass(" error in get/set SOSVariableBranchingWeights");
#endif

        OtherVariableOption** otherV;
        otherV = osoption->getAllOtherVariableOptions();
        nopt = osoption->getNumberOfOtherVariableOptions();
        ok = osoption2->setOtherVariableOptions(nopt, otherV) && ok;
#ifdef DEBUG
        if (!ok)
            throw ErrorClass(" error in get/set OtherVariableOptions");
#endif

        nopt = osoption->getNumberOfInitObjValues();
        InitObjValue** IOV;
        IOV = osoption->getInitObjValuesSparse();
        for (int lmn=0; lmn < nobj; lmn++)

        ok = osoption2->setInitObjValuesSparse(nopt, IOV) && ok;        
#ifdef DEBUG
        if (!ok)
            throw ErrorClass(" error in get/set InitObjValues");
#endif

        nopt = osoption->getNumberOfInitObjBounds();
        InitObjBound** IOB;
        IOB = osoption->getInitObjBoundsSparse();
        ok = osoption2->setInitObjBoundsSparse(nopt, IOB) && ok;        
#ifdef DEBUG
        if (!ok)
            throw ErrorClass(" error in get/set InitObjBounds");
#endif

        nvar = osoption->getNumberOfInitialBasisElements(ENUM_PROBLEM_COMPONENT_objectives,ENUM_BASIS_STATUS_basic);
        if (nvar > 0)
        {
            IBS = new int[nvar];
            ok = osoption->getInitialBasisElements(ENUM_PROBLEM_COMPONENT_objectives,ENUM_BASIS_STATUS_basic,IBS);
            ok = osoption2->setInitBasisStatus(ENUM_PROBLEM_COMPONENT_objectives,ENUM_BASIS_STATUS_basic, IBS, nvar) && ok;
            delete[] IBS;
#ifdef DEBUG
            if (!ok)
                throw ErrorClass(" error in get/set InitBasisStatus");
#endif
        }

        nvar = osoption->getNumberOfInitialBasisElements(ENUM_PROBLEM_COMPONENT_objectives,ENUM_BASIS_STATUS_atLower);
        if (nvar > 0)
        {
            IBS = new int[nvar];
            ok = osoption->getInitialBasisElements(ENUM_PROBLEM_COMPONENT_objectives,ENUM_BASIS_STATUS_atLower,IBS);
            ok = osoption2->setInitBasisStatus(ENUM_PROBLEM_COMPONENT_objectives,ENUM_BASIS_STATUS_atLower, IBS, nvar) && ok;
            delete[] IBS;
#ifdef DEBUG
            if (!ok)
                throw ErrorClass(" error in get/set InitBasisStatus");
#endif
        }

        nvar = osoption->getNumberOfInitialBasisElements(ENUM_PROBLEM_COMPONENT_objectives,ENUM_BASIS_STATUS_atUpper);
        if (nvar > 0)
        {
            IBS = new int[nvar];
            ok = osoption->getInitialBasisElements(ENUM_PROBLEM_COMPONENT_objectives,ENUM_BASIS_STATUS_atUpper,IBS);
            ok = osoption2->setInitBasisStatus(ENUM_PROBLEM_COMPONENT_objectives,ENUM_BASIS_STATUS_atUpper, IBS, nvar) && ok;
            delete[] IBS;
#ifdef DEBUG
            if (!ok)
                throw ErrorClass(" error in get/set InitBasisStatus");
#endif
        }

        nvar = osoption->getNumberOfInitialBasisElements(ENUM_PROBLEM_COMPONENT_objectives,ENUM_BASIS_STATUS_atEquality);
        if (nvar > 0)
        {
            IBS = new int[nvar];
            ok = osoption->getInitialBasisElements(ENUM_PROBLEM_COMPONENT_objectives,ENUM_BASIS_STATUS_atEquality,IBS);
            ok = osoption2->setInitBasisStatus(ENUM_PROBLEM_COMPONENT_objectives,ENUM_BASIS_STATUS_atEquality, IBS, nvar) && ok;
            delete[] IBS;
#ifdef DEBUG
            if (!ok)
                throw ErrorClass(" error in get/set InitBasisStatus");
#endif
        }

        nvar = osoption->getNumberOfInitialBasisElements(ENUM_PROBLEM_COMPONENT_objectives,ENUM_BASIS_STATUS_isFree);
        if (nvar > 0)
        {
            IBS = new int[nvar];
            ok = osoption->getInitialBasisElements(ENUM_PROBLEM_COMPONENT_objectives,ENUM_BASIS_STATUS_isFree,IBS);
            ok = osoption2->setInitBasisStatus(ENUM_PROBLEM_COMPONENT_objectives,ENUM_BASIS_STATUS_isFree, IBS, nvar) && ok;
            delete[] IBS;
#ifdef DEBUG
            if (!ok)
                throw ErrorClass(" error in get/set InitBasisStatus");
#endif
        }

        nvar = osoption->getNumberOfInitialBasisElements(ENUM_PROBLEM_COMPONENT_objectives,ENUM_BASIS_STATUS_superbasic);
        if (nvar > 0)
        {
            IBS = new int[nvar];
            ok = osoption->getInitialBasisElements(ENUM_PROBLEM_COMPONENT_objectives,ENUM_BASIS_STATUS_superbasic,IBS);
            ok = osoption2->setInitBasisStatus(ENUM_PROBLEM_COMPONENT_objectives,ENUM_BASIS_STATUS_superbasic, IBS, nvar) && ok;
            delete[] IBS;
#ifdef DEBUG
            if (!ok)
                throw ErrorClass(" error in get/set InitBasisStatus");
#endif
        }

        nvar = osoption->getNumberOfInitialBasisElements(ENUM_PROBLEM_COMPONENT_objectives,ENUM_BASIS_STATUS_unknown);
        if (nvar > 0)
        {
            IBS = new int[nvar];
            ok = osoption->getInitialBasisElements(ENUM_PROBLEM_COMPONENT_objectives,ENUM_BASIS_STATUS_unknown,IBS);
            ok = osoption2->setInitBasisStatus(ENUM_PROBLEM_COMPONENT_objectives,ENUM_BASIS_STATUS_unknown, IBS, nvar) && ok;
            delete[] IBS;
#ifdef DEBUG
            if (!ok)
                throw ErrorClass(" error in get/set InitBasisStatus");
#endif
        }

        OtherObjectiveOption** otherO;
        otherO = osoption->getAllOtherObjectiveOptions();
        nopt = osoption->getNumberOfOtherObjectiveOptions();
        ok = osoption2->setOtherObjectiveOptions(nopt, otherO) && ok;
#ifdef DEBUG
        if (!ok)
            throw ErrorClass(" error in get/set OtherObjectiveOptions");
#endif

        
        nopt = osoption->getNumberOfInitConValues();
        InitConValue** ICV;
        ICV = osoption->getInitConValuesSparse();
        ok = osoption2->setInitConValuesSparse(nopt, ICV) && ok;        
#ifdef DEBUG
        if (!ok)
            throw ErrorClass(" error in get/set InitConValues");
#endif

        nopt = osoption->getNumberOfInitDualVarValues();
        InitDualVarValue** IDV;
        IDV = osoption->getInitDualVarValuesSparse();
        ok = osoption2->setInitDualVarValuesSparse(nopt, IDV) && ok;        
#ifdef DEBUG
        if (!ok)
            throw ErrorClass(" error in get/set InitDualVarValues");
#endif

        nvar = osoption->getNumberOfInitialBasisElements(ENUM_PROBLEM_COMPONENT_constraints,ENUM_BASIS_STATUS_basic);
        if (nvar > 0)
        {
            IBS = new int[nvar];
            ok = osoption->getInitialBasisElements(ENUM_PROBLEM_COMPONENT_constraints,ENUM_BASIS_STATUS_basic,IBS);
            ok = osoption2->setInitBasisStatus(ENUM_PROBLEM_COMPONENT_constraints,ENUM_BASIS_STATUS_basic, IBS, nvar) && ok;
            delete[] IBS;
#ifdef DEBUG
            if (!ok)
                throw ErrorClass(" error in get/set InitBasisStatus");
#endif
        }

        nvar = osoption->getNumberOfInitialBasisElements(ENUM_PROBLEM_COMPONENT_constraints,ENUM_BASIS_STATUS_atLower);
        if (nvar > 0)
        {
            IBS = new int[nvar];
            ok = osoption->getInitialBasisElements(ENUM_PROBLEM_COMPONENT_constraints,ENUM_BASIS_STATUS_atLower,IBS);
            ok = osoption2->setInitBasisStatus(ENUM_PROBLEM_COMPONENT_constraints,ENUM_BASIS_STATUS_atLower, IBS, nvar) && ok;
            delete[] IBS;
#ifdef DEBUG
            if (!ok)
                throw ErrorClass(" error in get/set InitBasisStatus");
#endif
        }

        nvar = osoption->getNumberOfInitialBasisElements(ENUM_PROBLEM_COMPONENT_constraints,ENUM_BASIS_STATUS_atUpper);
        if (nvar > 0)
        {
            IBS = new int[nvar];
            ok = osoption->getInitialBasisElements(ENUM_PROBLEM_COMPONENT_constraints,ENUM_BASIS_STATUS_atUpper,IBS);
            ok = osoption2->setInitBasisStatus(ENUM_PROBLEM_COMPONENT_constraints,ENUM_BASIS_STATUS_atUpper, IBS, nvar) && ok;
            delete[] IBS;
#ifdef DEBUG
            if (!ok)
                throw ErrorClass(" error in get/set InitBasisStatus");
#endif
        }

        nvar = osoption->getNumberOfInitialBasisElements(ENUM_PROBLEM_COMPONENT_constraints,ENUM_BASIS_STATUS_atEquality);
        if (nvar > 0)
        {
            IBS = new int[nvar];
            ok = osoption->getInitialBasisElements(ENUM_PROBLEM_COMPONENT_constraints,ENUM_BASIS_STATUS_atEquality,IBS);
            ok = osoption2->setInitBasisStatus(ENUM_PROBLEM_COMPONENT_constraints,ENUM_BASIS_STATUS_atEquality, IBS, nvar) && ok;
            delete[] IBS;
#ifdef DEBUG
            if (!ok)
                throw ErrorClass(" error in get/set InitBasisStatus");
#endif
        }

        nvar = osoption->getNumberOfInitialBasisElements(ENUM_PROBLEM_COMPONENT_constraints,ENUM_BASIS_STATUS_isFree);
        if (nvar > 0)
        {
            IBS = new int[nvar];
            ok = osoption->getInitialBasisElements(ENUM_PROBLEM_COMPONENT_constraints,ENUM_BASIS_STATUS_isFree,IBS);
            ok = osoption2->setInitBasisStatus(ENUM_PROBLEM_COMPONENT_constraints,ENUM_BASIS_STATUS_isFree, IBS, nvar) && ok;
            delete[] IBS;
#ifdef DEBUG
            if (!ok)
                throw ErrorClass(" error in get/set InitBasisStatus");
#endif
        }

        nvar = osoption->getNumberOfInitialBasisElements(ENUM_PROBLEM_COMPONENT_constraints,ENUM_BASIS_STATUS_superbasic);
        if (nvar > 0)
        {
            IBS = new int[nvar];
            ok = osoption->getInitialBasisElements(ENUM_PROBLEM_COMPONENT_constraints,ENUM_BASIS_STATUS_superbasic,IBS);
            ok = osoption2->setInitBasisStatus(ENUM_PROBLEM_COMPONENT_constraints,ENUM_BASIS_STATUS_superbasic, IBS, nvar) && ok;
            delete[] IBS;
#ifdef DEBUG
            if (!ok)
                throw ErrorClass(" error in get/set InitBasisStatus");
#endif
        }

        nvar = osoption->getNumberOfInitialBasisElements(ENUM_PROBLEM_COMPONENT_constraints,ENUM_BASIS_STATUS_unknown);
        if (nvar > 0)
        {
            IBS = new int[nvar];
            ok = osoption->getInitialBasisElements(ENUM_PROBLEM_COMPONENT_constraints,ENUM_BASIS_STATUS_unknown,IBS);
            ok = osoption2->setInitBasisStatus(ENUM_PROBLEM_COMPONENT_constraints,ENUM_BASIS_STATUS_unknown, IBS, nvar) && ok;
            delete[] IBS;
#ifdef DEBUG
            if (!ok)
                throw ErrorClass(" error in get/set InitBasisStatus");
#endif
        }

        OtherConstraintOption** otherC;
        otherC = osoption->getAllOtherConstraintOptions();
        nopt = osoption->getNumberOfOtherConstraintOptions();
        ok = osoption2->setOtherConstraintOptions(nopt, otherC) && ok;
#ifdef DEBUG
        if (!ok)
            throw ErrorClass(" error in get/set OtherConstraintOptions");




#endif

        SolverOption** SO;

        SO = osoption->getAllSolverOptions();
        nopt = osoption->getNumberOfSolverOptions();
        ok = osoption2->setSolverOptions(nopt, SO) && ok;


#ifdef DEBUG
        if (!ok)
            throw ErrorClass(" error in get/set SolverOptions");
#endif

        ok = osoption->IsEqual(osoption2) && ok;
        if (!ok)
            throw ErrorClass("OSOption get() and  set() methods do not work correctly");

        cout << "Write the content to a new file" << endl;        
        tmpOSoL = osolwriter->writeOSoL( osoption);
        cout << endl << "Here is tmpOSoL:" <<endl;
        cout << endl << endl << tmpOSoL << endl;
        cout << "-----------------------------------------" << endl << endl;

        // make sure we can parse without error
        osolreader2 = new OSoLReader();
        cout << "Read the string back" << endl;

        osoption3 = osolreader2->readOSoL( tmpOSoL);

        ok = osoption->IsEqual(osoption3);
        if (!ok)
            throw ErrorClass(" Loss of information in OSoL write/read");

        delete osoption2;
        osoption2 = NULL;
        delete osolreader2;
        osolreader2 = NULL;
        delete osolwriter;
        osolwriter = NULL;
        delete osolreader;
        osolreader = NULL;
        delete fileUtil;
        fileUtil = NULL;

        unitTestResult << 
             "TEST " << nOfTest << ": Successful test of OSoL set() and get() methods" 
              << std::endl;
        cout << endl << "TEST " << nOfTest << ": Completed successfully" << endl << endl;
    }    
    catch(const ErrorClass& eclass){
        cout << endl << endl << endl;
        cout << eclass.errormsg << endl;
        unitTestResultFailure << "Sorry Unit Test Failed OSoL set() and get() methods" << endl;        

        if (osoption2 != NULL)
            delete osoption2;
        osoption2 = NULL;

        if (osolreader2 != NULL)
            delete osolreader2;
        osolreader2 = NULL;

        if (osolwriter != NULL)
            delete osolwriter;
        osolwriter = NULL;

        if (osolreader != NULL)
            delete osolreader;
        osolreader = NULL;

        if (fileUtil != NULL)
            delete fileUtil;
        fileUtil = NULL;
    }    

    // a few more smaller examples
    try{ 
        cout << endl << "TEST " << ++nOfTest << ": Parse another .osol file" << endl << endl;

        fileUtil = new FileUtil();
        osolwriter = new OSoLWriter();
        osolreader = new OSoLReader();

        std::string tmpOSoL;
        clock_t start, finish;
        double duration;

        start = clock();

        cout << "First read the OSoL file into a string" << endl;
        osolFileName = dataDir  + "osolFiles" + dirsep + "parsertest2.osol"; 
        osol = fileUtil->getFileAsString( osolFileName.c_str() );
        finish = clock();
        duration = (double) (finish - start) / CLOCKS_PER_SEC;
        cout << "Reading the file into a string took (seconds): "<< duration << endl;
        cout << endl << osol << endl;
        cout << "Parse the OSoL string into an OSOption object" << endl;
        osoption = osolreader->readOSoL( osol);

        std::cout << "string read; now write again" << std::endl;
        tmpOSoL = osolwriter->writeOSoL( osoption) ;

        std::cout << "object written; delete osolreader" << std::endl;

        delete osolreader;
        osolreader = NULL;
        osolreader = new OSoLReader();
        osolreader->readOSoL( tmpOSoL);
        delete osolwriter;
        osolwriter = NULL;
        delete osolreader;
        osolreader = NULL;
        delete fileUtil;
        fileUtil = NULL;

        // a third example
        cout << "Test parsing another OSoL file" << endl;

        osolwriter = new OSoLWriter();
        osolreader = new OSoLReader();
        fileUtil = new FileUtil();

        cout << "First read the OSoL file into a string" << endl;
        osolFileName = dataDir  + "osolFiles" + dirsep + "parsertest3.osol"; 
        osol = fileUtil->getFileAsString( osolFileName.c_str() );
        finish = clock();
        duration = (double) (finish - start) / CLOCKS_PER_SEC;
        cout << "Reading the file into a string took (seconds): "<< duration << endl;
        cout << "Parse the OSoL string into an OSOption object" << endl;
        osoption = osolreader->readOSoL( osol);
        tmpOSoL = osolwriter->writeOSoL( osoption) ;
        delete osolreader;
        osolreader = NULL;
        osolreader = new OSoLReader();
        osolreader->readOSoL( tmpOSoL);
        delete osolwriter;
        osolwriter = NULL;
        delete osolreader;
        osolreader = NULL;
        delete fileUtil;
        fileUtil = NULL;


        // a trivial string
        cout << "Test parsing a trivial string" << endl;

        osolreader = new OSoLReader();

        osol = "<osol></osol>";
        cout << "Parse the OSoL string into an OSOption object" << endl;
        osoption = osolreader->readOSoL( osol);
        delete osolreader;
        osolreader = NULL;

        unitTestResult << "TEST " << nOfTest << ": Successful test of OSoL parser" << std::endl;
        cout << endl << "TEST " << nOfTest << ": Completed successfully" << endl << endl;
    }    
    
    catch(const ErrorClass& eclass){

        std::cout << "Content of error msg:" << std::endl << "-------------------------------" << std::endl;
        std::cout << eclass.errormsg << endl;
        std::cout << "-------------------------------" << std::endl;

        unitTestResultFailure << eclass.errormsg << endl;
        unitTestResultFailure << "There was a failure in the test for reading OSoL" << endl;

        if(osolwriter != NULL) 
            delete osolwriter;
        osolwriter = NULL;
        if(osolreader != NULL) 
            delete osolreader;
        osolreader = NULL;
        if (fileUtil != NULL)
            delete fileUtil;
        fileUtil = NULL;
    }


    // Finally a .osol file that has a number of semantic errors (not catchable by the schema)
    try{ 
        cout << endl << "TEST " << ++nOfTest << ": Parse faulty .osol file" << endl << endl;

        fileUtil = new FileUtil();
        osolwriter = new OSoLWriter();
        osolreader = new OSoLReader();

        std::string tmpOSoL;

        cout << "First read the OSoL file into a string" << endl;
        osolFileName = dataDir  + "osolFiles" + dirsep + "parsertestWithErrors.osol"; 
        osol = fileUtil->getFileAsString( osolFileName.c_str() );

        cout << "Parse the OSoL string into an OSOption object" << endl;
        osoption = osolreader->readOSoL( osol);


        delete osolreader;
        osolreader = NULL;
        osolreader = new OSoLReader();
        osolreader->readOSoL( tmpOSoL);
        delete osolwriter;
        osolwriter = NULL;
        delete osolreader;
        osolreader = NULL;
        delete fileUtil;
        fileUtil = NULL;

        unitTestResultFailure << "OSoL parser cannot find errors in faulty OSoL file" << endl;
    }    
    
    catch(const ErrorClass& eclass)
    {
        std::string resultFileName, resultFileContent;
        resultFileName    = dataDir  + "osolFiles" + dirsep + "parsertestWithErrors.result"; 
        resultFileContent = fileUtil->getFileAsString( resultFileName.c_str() );

  std::cout << std::endl << std::endl << "error message should be:" << resultFileContent << std::endl;      
  std::cout << std::endl << std::endl << "error message now reads:" << eclass.errormsg   << std::endl;

        if (resultFileContent == eclass.errormsg)
        {
            unitTestResult << "TEST " << nOfTest << ": Successful error handling of faulty OSoL input" << std::endl;
            cout << endl << "TEST " << nOfTest << ": Completed successfully" << endl << endl;
        }
        else
        {
            int i,j,ni,nj;
            i = 0;
            j = 0;
            ni = resultFileContent.size() - 1;
            nj =   eclass.errormsg.size() - 1;
            ok = true;
            for (;;)
            {
                if (i >= ni || j >= nj) break;
                for (;;) 
                {               
                    if (resultFileContent[i] != '\n' && resultFileContent[i] != '\r' &&
                        resultFileContent[i] != '\t' && resultFileContent[i] != ' ' ) break;
                    if (i >= ni) break;
                    i++;
                }
                for (;;) 
                {               
                    if (eclass.errormsg[j] != '\n' && eclass.errormsg[j] != '\r' &&
                        eclass.errormsg[j] != '\t' && eclass.errormsg[j] != ' ' ) break;
                    if (j >= nj) break;
                    j++;
                }

                ok &= (resultFileContent[i] == eclass.errormsg[j]);
                if (!ok) break;
                i++;
                j++;
            }

            if (ok)
            {
                unitTestResult << "TEST " << nOfTest << ": Successful error handling of faulty OSoL input" << std::endl;
                cout << endl << "TEST " << nOfTest << ": Completed successfully" << endl << endl;
            }
            else
                unitTestResultFailure << "There was a failure in the error handling of the OSoL parser" << endl;
        }

        if(osolwriter != NULL) 
            delete osolwriter;
        osolwriter = NULL;
        if(osolreader != NULL) 
            delete osolreader;
        osolreader = NULL;
        if (fileUtil != NULL)
            delete fileUtil;
        fileUtil = NULL;
    }

    // Now test the deep copy of an OSOption object

    OSOption *osoption2 = NULL;

    try{ 
        cout << endl << "TEST " << ++nOfTest << ": Test deep copy of OSOption object" << endl << endl;

        fileUtil = new FileUtil();
        osolreader = new OSoLReader();

        osolFileName = dataDir  + "osolFiles" + dirsep + "parsertest.osol"; 
        std::string osol = fileUtil->getFileAsString( osolFileName.c_str() );
        osoption = osolreader->readOSoL( osol);
        osoption2 = new OSOption();
        osoption2->deepCopyFrom(osoption);
        ok = (osoption->IsEqual(osoption2));

        delete osolreader;
        osolreader = NULL;
        delete osoption2;
        osoption2 = NULL;
        delete fileUtil;
        fileUtil = NULL;

        if (ok)
        {
            unitTestResult << "TEST " << nOfTest << ": Successful test of OSOption deep copy methods" << std::endl;
            cout << endl << "TEST " << nOfTest << ": Completed successfully" << endl << endl;
        }
        else
            unitTestResultFailure << "OSOption deep copy method is not working" << endl;
    }    
    
    catch(const ErrorClass& eclass)
    {

        if(osolreader != NULL) 
            delete osolreader;
        osolreader = NULL;
        if (fileUtil != NULL)
            delete fileUtil;
        fileUtil = NULL;
        if(osoption2 != NULL) 
            delete osoption2;
        osoption2 = NULL;
    }



//#endif //!!!  end of #if 0: OSrL parser development

/** Now test the utility methods for the OSrL parser, in three steps. 
 *
 *  The first test just ensures that the set() and IsEqual() methods work correctly.
 *  Two OSResult objects are built one element and attribute at a time.
 *  After every call to the appropriate set() method the two objects are compared:
 *  After the first object has been modified, the objects should compare NOT equal; 
 *  after the second object has been updated in the same way, the objects should 
 *  again be equal.
 */
    int* intArray;
    intArray = new int[3];
    int* tempArray = new int[3];

    try{ 
        cout << endl << "TEST " << ++nOfTest << ": OSrL set() tools" << endl << endl;

        osresult1 = new OSResult();
        osresult2 = new OSResult();

        ok = true;
        ok &= (osresult1->IsEqual(osresult2));
        if (!ok) 
            throw ErrorClass("Empty osresult objects do not compare equal!");

//    <general> element
        ok &= osresult1->setGeneralStatusType("warning");
        if (!ok) 
            throw ErrorClass("Error during setGeneralStatusType!");
        ok &= (!osresult1->IsEqual(osresult2));
        if (!ok) 
            throw ErrorClass("setGeneralStatusType: osresult objects falsely compare equal!");
        ok &= osresult2->setGeneralStatusType("warning");
        if (!ok) 
            throw ErrorClass("Error during setGeneralStatusType!");
        ok &= (osresult1->IsEqual(osresult2));
        if (!ok) 
            throw ErrorClass("setGeneralStatusType: osresult objects falsely compare unequal!");

        ok &= osresult1->setGeneralStatusDescription("some nonempty string");
        if (!ok) 
            throw ErrorClass("Error during setGeneralStatusDescription!");
        ok &= (!osresult1->IsEqual(osresult2));
        if (!ok) 
            throw ErrorClass("setGeneralStatusDescription: osresult objects falsely compare equal!");
        ok &= osresult2->setGeneralStatusDescription("some nonempty string");
        if (!ok) 
            throw ErrorClass("Error during setGeneralStatusDescription!");
        ok &= (osresult1->IsEqual(osresult2));
        if (!ok) 
            throw ErrorClass("setGeneralStatusDescription: osresult objects falsely compare unequal!");

        ok &= osresult1->setNumberOfGeneralSubstatuses(3);
        if (!ok) 
            throw ErrorClass("Error during setNumberOfGeneralSubstatuses!");
        ok &= (!osresult1->IsEqual(osresult2));
        if (!ok) 
            throw ErrorClass("setNumberOfGeneralSubstatuses: osresult objects falsely compare equal!");
        ok &= osresult2->setNumberOfGeneralSubstatuses(3);
        if (!ok) 
            throw ErrorClass("Error during setNumberOfGeneralSubstatuses!");
        ok &= (osresult1->IsEqual(osresult2));
        if (!ok) 
            throw ErrorClass("setNumberOfGeneralSubstatuses: osresult objects falsely compare unequal!");

        for (int i=0; i < 3; ++i)
        {
            ok &= osresult1->setGeneralSubstatusName(i,"some name");
            if (!ok) 
                throw ErrorClass("Error during setGeneralSubstatusName!");
            ok &= (!osresult1->IsEqual(osresult2));
            if (!ok) 
                throw ErrorClass("setGeneralSubstatusName: osresult objects falsely compare equal!");
            ok &= osresult2->setGeneralSubstatusName(i,"some name");
            if (!ok) 
                throw ErrorClass("Error during setGeneralSubstatusName!");
            ok &= (osresult1->IsEqual(osresult2));
            if (!ok) 
                throw ErrorClass("setGeneralSubstatusName: osresult objects falsely compare unequal!");

            ok &= osresult1->setGeneralSubstatusDescription(i,"ABC 123");
            if (!ok) 
                throw ErrorClass("Error during setGeneralSubstatusDescription!");
            ok &= (!osresult1->IsEqual(osresult2));
            if (!ok) 
                throw ErrorClass("setGeneralSubstatusDescription: osresult objects falsely compare equal!");
            ok &= osresult2->setGeneralSubstatusDescription(i,"ABC 123");
            if (!ok) 
                throw ErrorClass("Error during setGeneralSubstatusDescription!");
            ok &= (osresult1->IsEqual(osresult2));
            if (!ok) 
                throw ErrorClass("setGeneralSubstatusDescription: osresult objects falsely compare unequal!");
        }

        ok &= osresult1->setGeneralMessage("testing 123");
        if (!ok) 
            throw ErrorClass("Error during setGeneralMessage!");
        ok &= (!osresult1->IsEqual(osresult2));
        if (!ok) 
            throw ErrorClass("setGeneralMessage: osresult objects falsely compare equal!");
        ok &= osresult2->setGeneralMessage("testing 123");
        if (!ok) 
            throw ErrorClass("Error during setGeneralMessage!");
        ok &= (osresult1->IsEqual(osresult2));
        if (!ok) 
            throw ErrorClass("setGeneralMessage: osresult objects falsely compare unequal!");

        ok &= osresult1->setServiceName("testing 123");
        if (!ok) 
            throw ErrorClass("Error during setServiceName!");
        ok &= (!osresult1->IsEqual(osresult2));
        if (!ok) 
            throw ErrorClass("setServiceName: osresult objects falsely compare equal!");
        ok &= osresult2->setServiceName("testing 123");
        if (!ok) 
            throw ErrorClass("Error during setServiceName!");
        ok &= (osresult1->IsEqual(osresult2));
        if (!ok) 
            throw ErrorClass("setServiceName: osresult objects falsely compare unequal!");

        ok &= osresult1->setServiceURI("testing 123");
        if (!ok) 
            throw ErrorClass("Error during setServiceURI!");
        ok &= (!osresult1->IsEqual(osresult2));
        if (!ok) 
            throw ErrorClass("setServiceURI: osresult objects falsely compare equal!");
        ok &= osresult2->setServiceURI("testing 123");
        if (!ok) 
            throw ErrorClass("Error during setServiceURI!");
        ok &= (osresult1->IsEqual(osresult2));
        if (!ok) 
            throw ErrorClass("setServiceURI: osresult objects falsely compare unequal!");

        ok &= osresult1->setInstanceName("testing 123");
        if (!ok) 
            throw ErrorClass("Error during setInstanceName!");
        ok &= (!osresult1->IsEqual(osresult2));
        if (!ok) 
            throw ErrorClass("setInstanceName: osresult objects falsely compare equal!");
        ok &= osresult2->setInstanceName("testing 123");
        if (!ok) 
            throw ErrorClass("Error during setInstanceName!");
        ok &= (osresult1->IsEqual(osresult2));
        if (!ok) 
            throw ErrorClass("setInstanceName: osresult objects falsely compare unequal!");

        ok &= osresult1->setJobID("testing 123");
        if (!ok) 
            throw ErrorClass("Error during setJobID!");
        ok &= (!osresult1->IsEqual(osresult2));
        if (!ok) 
            throw ErrorClass("setJobID: osresult objects falsely compare equal!");
        ok &= osresult2->setJobID("testing 123");
        if (!ok) 
            throw ErrorClass("Error during setJobID!");
        ok &= (osresult1->IsEqual(osresult2));
        if (!ok) 
            throw ErrorClass("setJobID: osresult objects falsely compare unequal!");

        ok &= osresult1->setSolverInvoked("testing 123");
        if (!ok) 
            throw ErrorClass("Error during setSolverInvoked!");
        ok &= (!osresult1->IsEqual(osresult2));
        if (!ok) 
            throw ErrorClass("setSolverInvoked: osresult objects falsely compare equal!");
        ok &= osresult2->setSolverInvoked("testing 123");
        if (!ok) 
            throw ErrorClass("Error during setSolverInvoked!");
        ok &= (osresult1->IsEqual(osresult2));
        if (!ok) 
            throw ErrorClass("setSolverInvoked: osresult objects falsely compare unequal!");

        ok &= osresult1->setTimeStamp("2001-12-17T09:30:47.0Z");
        if (!ok) 
            throw ErrorClass("Error during setTimeStamp!");
        ok &= (!osresult1->IsEqual(osresult2));
        if (!ok) 
            throw ErrorClass("setTimeStamp: osresult objects falsely compare equal!");
        ok &= osresult2->setTimeStamp("2001-12-17T09:30:47.0Z");
        if (!ok) 
            throw ErrorClass("Error during setTimeStamp!");
        ok &= (osresult1->IsEqual(osresult2));
        if (!ok) 
            throw ErrorClass("setTimeStamp: osresult objects falsely compare unequal!");

        ok &= osresult1->setNumberOfOtherGeneralResults(3);
        if (!ok) 
            throw ErrorClass("Error during setNumberOfOtherGeneralResults!");
        ok &= (!osresult1->IsEqual(osresult2));
        if (!ok) 
            throw ErrorClass("setNumberOfOtherGeneralResults: osresult objects falsely compare equal!");
        ok &= osresult2->setNumberOfOtherGeneralResults(3);
        if (!ok) 
            throw ErrorClass("Error during setNumberOfOtherGeneralResults!");
        ok &= (osresult1->IsEqual(osresult2));
        if (!ok) 
            throw ErrorClass("setNumberOfOtherGeneralResults: osresult objects falsely compare unequal!");

        for (int i=0; i < 3; ++i)
        {
            ok &= osresult1->setOtherGeneralResultName(i,"some name");
            if (!ok) 
                throw ErrorClass("Error during setOtherGeneralResultName!");
            ok &= (!osresult1->IsEqual(osresult2));
            if (!ok) 
                throw ErrorClass("setOtherGeneralResultName: osresult objects falsely compare equal!");
            ok &= osresult2->setOtherGeneralResultName(i,"some name");
            if (!ok) 
                throw ErrorClass("Error during setOtherGeneralResultName!");
            ok &= (osresult1->IsEqual(osresult2));
            if (!ok) 
                throw ErrorClass("setOtherGeneralResultName: osresult objects falsely compare unequal!");

            ok &= osresult1->setOtherGeneralResultValue(i,"some value");
            if (!ok) 
                throw ErrorClass("Error during setOtherGeneralResultValue!");
            ok &= (!osresult1->IsEqual(osresult2));
            if (!ok) 
                throw ErrorClass("setOtherGeneralResultValue: osresult objects falsely compare equal!");
            ok &= osresult2->setOtherGeneralResultValue(i,"some value");
            if (!ok) 
                throw ErrorClass("Error during setOtherGeneralResultValue!");
            ok &= (osresult1->IsEqual(osresult2));
            if (!ok) 
                throw ErrorClass("setOtherGeneralResultValue: osresult objects falsely compare unequal!");

            ok &= osresult1->setOtherGeneralResultDescription(i,"ABC 123");
            if (!ok) 
                throw ErrorClass("Error during setOtherGeneralResultDescription!");
            ok &= (!osresult1->IsEqual(osresult2));
            if (!ok) 
                throw ErrorClass("setOtherGeneralResultDescription: osresult objects falsely compare equal!");
            ok &= osresult2->setOtherGeneralResultDescription(i,"ABC 123");
            if (!ok) 
                throw ErrorClass("Error during setOtherGeneralResultDescription!");
            ok &= (osresult1->IsEqual(osresult2));
            if (!ok) 
                throw ErrorClass("setOtherGeneralResultDescription: osresult objects falsely compare unequal!");
        }

// <system> element
        ok &= osresult1->setSystemInformation("testing 123");
        if (!ok) 
            throw ErrorClass("Error during setSystemInformation!");
        ok &= (!osresult1->IsEqual(osresult2));
        if (!ok) 
            throw ErrorClass("setSystemInformation: osresult objects falsely compare equal!");
        ok &= osresult2->setSystemInformation("testing 123");
        if (!ok) 
            throw ErrorClass("Error during setSystemInformation!");
        ok &= (osresult1->IsEqual(osresult2));
        if (!ok) 
            throw ErrorClass("setSystemInformation: osresult objects falsely compare unequal!");

        ok &= osresult1->setAvailableDiskSpaceUnit("megabyte");
        if (!ok) 
            throw ErrorClass("Error during setAvailableDiskSpaceUnit!");
        ok &= (!osresult1->IsEqual(osresult2));
        if (!ok) 
            throw ErrorClass("setAvailableDiskSpaceUnit: osresult objects falsely compare equal!");
        ok &= osresult2->setAvailableDiskSpaceUnit("megabyte");
        if (!ok) 
            throw ErrorClass("Error during setAvailableDiskSpaceUnit!");
        ok &= (osresult1->IsEqual(osresult2));
        if (!ok) 
            throw ErrorClass("setAvailableDiskSpaceUnit: osresult objects falsely compare unequal!");

        ok &= osresult1->setAvailableDiskSpaceDescription("testing 123");
        if (!ok) 
            throw ErrorClass("Error during setAvailableDiskSpaceDescription!");
        ok &= (!osresult1->IsEqual(osresult2));
        if (!ok) 
            throw ErrorClass("setAvailableDiskSpaceDescription: osresult objects falsely compare equal!");
        ok &= osresult2->setAvailableDiskSpaceDescription("testing 123");
        if (!ok) 
            throw ErrorClass("Error during setAvailableDiskSpaceDescription!");
        ok &= (osresult1->IsEqual(osresult2));
        if (!ok) 
            throw ErrorClass("setAvailableDiskSpaceDescription: osresult objects falsely compare unequal!");

        ok &= osresult1->setAvailableDiskSpaceValue(100.0);
        if (!ok) 
            throw ErrorClass("Error during setAvailableDiskSpaceValue!");
        ok &= (!osresult1->IsEqual(osresult2));
        if (!ok) 
            throw ErrorClass("setAvailableDiskSpaceValue: osresult objects falsely compare equal!");
        ok &= osresult2->setAvailableDiskSpaceValue(100.0);
        if (!ok) 
            throw ErrorClass("Error during setAvailableDiskSpaceValue!");
        ok &= (osresult1->IsEqual(osresult2));
        if (!ok) 
            throw ErrorClass("setAvailableDiskSpaceValue: osresult objects falsely compare unequal!");

        ok &= osresult1->setAvailableMemoryUnit("megabyte");
        if (!ok) 
            throw ErrorClass("Error during setAvailableMemoryUnit!");
        ok &= (!osresult1->IsEqual(osresult2));
        if (!ok) 
            throw ErrorClass("setAvailableMemoryUnit: osresult objects falsely compare equal!");
        ok &= osresult2->setAvailableMemoryUnit("megabyte");
        if (!ok) 
            throw ErrorClass("Error during setAvailableMemoryUnit!");
        ok &= (osresult1->IsEqual(osresult2));

        if (!ok) 
            throw ErrorClass("setAvailableMemoryUnit: osresult objects falsely compare unequal!");

        ok &= osresult1->setAvailableMemoryDescription("testing 123");
        if (!ok) 
            throw ErrorClass("Error during setAvailableMemoryDescription!");
        ok &= (!osresult1->IsEqual(osresult2));
        if (!ok) 
            throw ErrorClass("setAvailableMemoryDescription: osresult objects falsely compare equal!");
        ok &= osresult2->setAvailableMemoryDescription("testing 123");
        if (!ok) 
            throw ErrorClass("Error during setAvailableMemoryDescription!");
        ok &= (osresult1->IsEqual(osresult2));
        if (!ok) 
            throw ErrorClass("setAvailableMemoryDescription: osresult objects falsely compare unequal!");

        ok &= osresult1->setAvailableMemoryValue(100.0);
        if (!ok) 
            throw ErrorClass("Error during setAvailableMemoryValue!");
        ok &= (!osresult1->IsEqual(osresult2));
        if (!ok) 
            throw ErrorClass("setAvailableMemoryValue: osresult objects falsely compare equal!");
        ok &= osresult2->setAvailableMemoryValue(100.0);
        if (!ok) 
            throw ErrorClass("Error during setAvailableMemoryValue!");
        ok &= (osresult1->IsEqual(osresult2));
        if (!ok) 
            throw ErrorClass("setAvailableMemoryValue: osresult objects falsely compare unequal!");

        ok &= osresult1->setAvailableCPUSpeedUnit("megahertz");
        if (!ok) 
            throw ErrorClass("Error during setAvailableCPUSpeedUnit!");
        ok &= (!osresult1->IsEqual(osresult2));
        if (!ok) 
            throw ErrorClass("setAvailableCPUSpeedUnit: osresult objects falsely compare equal!");
        ok &= osresult2->setAvailableCPUSpeedUnit("megahertz");
        if (!ok) 
            throw ErrorClass("Error during setAvailableCPUSpeedUnit!");
        ok &= (osresult1->IsEqual(osresult2));
        if (!ok) 
            throw ErrorClass("setAvailableCPUSpeedUnit: osresult objects falsely compare unequal!");

        ok &= osresult1->setAvailableCPUSpeedDescription("testing 123");
        if (!ok) 
            throw ErrorClass("Error during setAvailableCPUSpeedDescription!");
        ok &= (!osresult1->IsEqual(osresult2));
        if (!ok) 
            throw ErrorClass("setAvailableCPUSpeedDescription: osresult objects falsely compare equal!");
        ok &= osresult2->setAvailableCPUSpeedDescription("testing 123");
        if (!ok) 
            throw ErrorClass("Error during setAvailableCPUSpeedDescription!");
        ok &= (osresult1->IsEqual(osresult2));
        if (!ok) 
            throw ErrorClass("setAvailableCPUSpeedDescription: osresult objects falsely compare unequal!");

        ok &= osresult1->setAvailableCPUSpeedValue(100.0);
        if (!ok) 
            throw ErrorClass("Error during setAvailableCPUSpeedValue!");
        ok &= (!osresult1->IsEqual(osresult2));
        if (!ok) 
            throw ErrorClass("setAvailableCPUSpeedValue: osresult objects falsely compare equal!");
        ok &= osresult2->setAvailableCPUSpeedValue(100.0);
        if (!ok) 
            throw ErrorClass("Error during setAvailableCPUSpeedValue!");
        ok &= (osresult1->IsEqual(osresult2));
        if (!ok) 
            throw ErrorClass("setAvailableCPUSpeedValue: osresult objects falsely compare unequal!");

        ok &= osresult1->setAvailableCPUNumberDescription("testing 123");
        if (!ok) 
            throw ErrorClass("Error during setAvailableCPUNumberDescription!");
        ok &= (!osresult1->IsEqual(osresult2));
        if (!ok) 
            throw ErrorClass("setAvailableCPUNumberDescription: osresult objects falsely compare equal!");
        ok &= osresult2->setAvailableCPUNumberDescription("testing 123");
        if (!ok) 
            throw ErrorClass("Error during setAvailableCPUNumberDescription!");
        ok &= (osresult1->IsEqual(osresult2));
        if (!ok) 
            throw ErrorClass("setAvailableCPUNumberDescription: osresult objects falsely compare unequal!");

        ok &= osresult1->setAvailableCPUNumberValue(100);
        if (!ok) 
            throw ErrorClass("Error during setAvailableCPUNumberValue!");
        ok &= (!osresult1->IsEqual(osresult2));
        if (!ok) 
            throw ErrorClass("setAvailableCPUNumberValue: osresult objects falsely compare equal!");
        ok &= osresult2->setAvailableCPUNumberValue(100);
        if (!ok) 
            throw ErrorClass("Error during setAvailableCPUNumberValue!");
        ok &= (osresult1->IsEqual(osresult2));
        if (!ok) 
            throw ErrorClass("setAvailableCPUNumberValue: osresult objects falsely compare unequal!");

        ok &= osresult1->setNumberOfOtherSystemResults(3);
        if (!ok) 
            throw ErrorClass("Error during setNumberOfOtherSystemResults!");
        ok &= (!osresult1->IsEqual(osresult2));
        if (!ok) 
            throw ErrorClass("setNumberOfOtherSystemResults: osresult objects falsely compare equal!");
        ok &= osresult2->setNumberOfOtherSystemResults(3);
        if (!ok) 
            throw ErrorClass("Error during setNumberOfOtherSystemResults!");
        ok &= (osresult1->IsEqual(osresult2));
        if (!ok) 
            throw ErrorClass("setNumberOfOtherSystemResults: osresult objects falsely compare unequal!");

        for (int i=0; i < 3; ++i)
        {
            ok &= osresult1->setOtherSystemResultName(i,"some name");
            if (!ok) 
                throw ErrorClass("Error during setOtherSystemResultName!");
            ok &= (!osresult1->IsEqual(osresult2));
            if (!ok) 
                throw ErrorClass("setOtherSystemResultName: osresult objects falsely compare equal!");
            ok &= osresult2->setOtherSystemResultName(i,"some name");
            if (!ok) 
                throw ErrorClass("Error during setOtherSystemResultName!");
            ok &= (osresult1->IsEqual(osresult2));
            if (!ok) 
                throw ErrorClass("setOtherSystemResultName: osresult objects falsely compare unequal!");

            ok &= osresult1->setOtherSystemResultValue(i,"some value");
            if (!ok) 
                throw ErrorClass("Error during setOtherSystemResultValue!");
            ok &= (!osresult1->IsEqual(osresult2));
            if (!ok) 
                throw ErrorClass("setOtherSystemResultValue: osresult objects falsely compare equal!");
            ok &= osresult2->setOtherSystemResultValue(i,"some value");
            if (!ok) 
                throw ErrorClass("Error during setOtherSystemResultValue!");
            ok &= (osresult1->IsEqual(osresult2));
            if (!ok) 
                throw ErrorClass("setOtherSystemResultValue: osresult objects falsely compare unequal!");

            ok &= osresult1->setOtherSystemResultDescription(i,"ABC 123");
            if (!ok) 
                throw ErrorClass("Error during setSOtherSystemResultDescription!");
            ok &= (!osresult1->IsEqual(osresult2));
            if (!ok) 
                throw ErrorClass("setOtherSystemResultDescription: osresult objects falsely compare equal!");
            ok &= osresult2->setOtherSystemResultDescription(i,"ABC 123");
            if (!ok) 
                throw ErrorClass("Error during setOtherSystemResultDescription!");
            ok &= (osresult1->IsEqual(osresult2));
            if (!ok) 
                throw ErrorClass("setOtherSystemResultDescription: osresult objects falsely compare unequal!");
        }

//  <service> element
        ok &= osresult1->setCurrentState("busy");
        if (!ok) 
            throw ErrorClass("Error during setCurrentState!");
        ok &= (!osresult1->IsEqual(osresult2));
        if (!ok) 
            throw ErrorClass("setCurrentState: osresult objects falsely compare equal!");
        ok &= osresult2->setCurrentState("busy");
        if (!ok) 
            throw ErrorClass("Error during setCurrentState!");
        ok &= (osresult1->IsEqual(osresult2));
        if (!ok) 
            throw ErrorClass("setCurrentState: osresult objects falsely compare unequal!");

        ok &= osresult1->setCurrentJobCount(123);
        if (!ok) 
            throw ErrorClass("Error during setCurrentJobCount!");
        ok &= (!osresult1->IsEqual(osresult2));
        if (!ok) 
            throw ErrorClass("setCurrentJobCount: osresult objects falsely compare equal!");
        ok &= osresult2->setCurrentJobCount(123);
        if (!ok) 
            throw ErrorClass("Error during setCurrentJobCount!");
        ok &= (osresult1->IsEqual(osresult2));
        if (!ok) 
            throw ErrorClass("setCurrentJobCount: osresult objects falsely compare unequal!");

        ok &= osresult1->setTotalJobsSoFar(123);
        if (!ok) 
            throw ErrorClass("Error during setTotalJobsSoFar!");
        ok &= (!osresult1->IsEqual(osresult2));
        if (!ok) 
            throw ErrorClass("setTotalJobsSoFar: osresult objects falsely compare equal!");
        ok &= osresult2->setTotalJobsSoFar(123);
        if (!ok) 
            throw ErrorClass("Error during setTotalJobsSoFar!");
        ok &= (osresult1->IsEqual(osresult2));
        if (!ok) 
            throw ErrorClass("setTotalJobsSoFar: osresult objects falsely compare unequal!");

        ok &= osresult1->setTimeServiceStarted("2001-12-17T09:30:47.0Z");
        if (!ok) 
            throw ErrorClass("Error during setTimeServiceStarted!");
        ok &= (!osresult1->IsEqual(osresult2));
        if (!ok) 
            throw ErrorClass("setTimeServiceStarted: osresult objects falsely compare equal!");
        ok &= osresult2->setTimeServiceStarted("2001-12-17T09:30:47.0Z");
        if (!ok) 
            throw ErrorClass("Error during setTimeServiceStarted!");
        ok &= (osresult1->IsEqual(osresult2));
        if (!ok) 
            throw ErrorClass("setTimeServiceStarted: osresult objects falsely compare unequal!");

        ok &= osresult1->setServiceUtilization(0.8);
        if (!ok) 
            throw ErrorClass("Error during setServiceUtilization!");
        ok &= (!osresult1->IsEqual(osresult2));
        if (!ok) 
            throw ErrorClass("setServiceUtilization: osresult objects falsely compare equal!");
        ok &= osresult2->setServiceUtilization(0.8);
        if (!ok) 
            throw ErrorClass("Error during setServiceUtilization!");
        ok &= (osresult1->IsEqual(osresult2));
        if (!ok) 
            throw ErrorClass("setServiceUtilization: osresult objects falsely compare unequal!");

        ok &= osresult1->setNumberOfOtherServiceResults(3);
        if (!ok) 
            throw ErrorClass("Error during setNumberOfOtherServiceResults!");
        ok &= (!osresult1->IsEqual(osresult2));
        if (!ok) 
            throw ErrorClass("setNumberOfOtherServiceResults: osresult objects falsely compare equal!");
        ok &= osresult2->setNumberOfOtherServiceResults(3);
        if (!ok) 
            throw ErrorClass("Error during setNumberOfOtherServiceResults!");
        ok &= (osresult1->IsEqual(osresult2));
        if (!ok) 
            throw ErrorClass("setNumberOfOtherServiceResults: osresult objects falsely compare unequal!");

        for (int i=0; i < 3; ++i)
        {
            ok &= osresult1->setOtherServiceResultName(i,"some name");
            if (!ok) 
                throw ErrorClass("Error during setOtherServiceResultName!");
            ok &= (!osresult1->IsEqual(osresult2));
            if (!ok) 
                throw ErrorClass("setOtherServiceResultName: osresult objects falsely compare equal!");
            ok &= osresult2->setOtherServiceResultName(i,"some name");
            if (!ok) 
                throw ErrorClass("Error during setOtherServiceResultName!");
            ok &= (osresult1->IsEqual(osresult2));
            if (!ok) 
                throw ErrorClass("setOtherServiceResultName: osresult objects falsely compare unequal!");

            ok &= osresult1->setOtherServiceResultValue(i,"some value");
            if (!ok) 
                throw ErrorClass("Error during setOtherServiceResultValue!");
            ok &= (!osresult1->IsEqual(osresult2));
            if (!ok) 
                throw ErrorClass("setOtherServiceResultValue: osresult objects falsely compare equal!");
            ok &= osresult2->setOtherServiceResultValue(i,"some value");
            if (!ok) 
                throw ErrorClass("Error during setOtherServiceResultValue!");
            ok &= (osresult1->IsEqual(osresult2));
            if (!ok) 
                throw ErrorClass("setOtherServiceResultValue: osresult objects falsely compare unequal!");


            ok &= osresult1->setOtherServiceResultDescription(i,"ABC 123");
            if (!ok) 
                throw ErrorClass("Error during setOtherServiceResultDescription!");
            ok &= (!osresult1->IsEqual(osresult2));
            if (!ok) 
                throw ErrorClass("setOtherServiceResultDescription: osresult objects falsely compare equal!");
            ok &= osresult2->setOtherServiceResultDescription(i,"ABC 123");
            if (!ok) 
                throw ErrorClass("Error during setOtherServiceResultDescription!");
            ok &= (osresult1->IsEqual(osresult2));
            if (!ok) 
                throw ErrorClass("setOtherServiceResultDescription: osresult objects falsely compare unequal!");
        }
//======================
//    <job> element
        ok &= osresult1->setJobStatus("waiting");
        if (!ok) 
            throw ErrorClass("Error during setJobStatus!");
        ok &= (!osresult1->IsEqual(osresult2));
        if (!ok) 
            throw ErrorClass("setJobStatus: osresult objects falsely compare equal!");
        ok &= osresult2->setJobStatus("waiting");
        if (!ok) 
            throw ErrorClass("Error during setJobStatus!");
        ok &= (osresult1->IsEqual(osresult2));
        if (!ok) 
            throw ErrorClass("setJobStatus: osresult objects falsely compare unequal!");

        ok &= osresult1->setJobSubmitTime("2001-12-17T09:30:47.0Z");
        if (!ok) 
            throw ErrorClass("Error during setJobSubmitTime!");
        ok &= (!osresult1->IsEqual(osresult2));
        if (!ok) 
            throw ErrorClass("setJobSubmitTime: osresult objects falsely compare equal!");
        ok &= osresult2->setJobSubmitTime("2001-12-17T09:30:47.0Z");
        if (!ok) 
            throw ErrorClass("Error during setJobSubmitTime!");
        ok &= (osresult1->IsEqual(osresult2));
        if (!ok) 
            throw ErrorClass("setJobSubmitTime: osresult objects falsely compare unequal!");

        ok &= osresult1->setScheduledStartTime("2001-12-17T09:30:47.0Z");
        if (!ok) 
            throw ErrorClass("Error during setScheduledStartTime!");
        ok &= (!osresult1->IsEqual(osresult2));
        if (!ok) 
            throw ErrorClass("setScheduledStartTime: osresult objects falsely compare equal!");
        ok &= osresult2->setScheduledStartTime("2001-12-17T09:30:47.0Z");
        if (!ok) 
            throw ErrorClass("Error during setScheduledStartTime!");
        ok &= (osresult1->IsEqual(osresult2));
        if (!ok) 
            throw ErrorClass("setScheduledStartTime: osresult objects falsely compare unequal!");

        ok &= osresult1->setActualStartTime("2001-12-17T09:30:47.0Z");
        if (!ok) 
            throw ErrorClass("Error during setActualStartTime!");
        ok &= (!osresult1->IsEqual(osresult2));
        if (!ok) 
            throw ErrorClass("setActualStartTime: osresult objects falsely compare equal!");
        ok &= osresult2->setActualStartTime("2001-12-17T09:30:47.0Z");
        if (!ok) 
            throw ErrorClass("Error during setActualStartTime!");
        ok &= (osresult1->IsEqual(osresult2));
        if (!ok) 
            throw ErrorClass("setActualStartTime: osresult objects falsely compare unequal!");

        ok &= osresult1->setJobEndTime("2001-12-17T09:30:47.0Z");
        if (!ok) 
            throw ErrorClass("Error during setJobEndTime!");
        ok &= (!osresult1->IsEqual(osresult2));
        if (!ok) 
            throw ErrorClass("setJobEndTime: osresult objects falsely compare equal!");
        ok &= osresult2->setJobEndTime("2001-12-17T09:30:47.0Z");
        if (!ok) 
            throw ErrorClass("Error during setJobEndTime!");
        ok &= (osresult1->IsEqual(osresult2));
        if (!ok) 
            throw ErrorClass("setJobEndTime: osresult objects falsely compare unequal!");

        ok &= osresult1->setNumberOfTimes(3);
        if (!ok) 
            throw ErrorClass("Error during setNumberOfTimes!");
        ok &= (!osresult1->IsEqual(osresult2));
        if (!ok) 
            throw ErrorClass("setNumberOfTimes: osresult objects falsely compare equal!");
        ok &= osresult2->setNumberOfTimes(3);
        if (!ok) 
            throw ErrorClass("Error during setNumberOfTimes!");
        ok &= (osresult1->IsEqual(osresult2));
        if (!ok) 
            throw ErrorClass("setNumberOfTimes: osresult objects falsely compare unequal!");

        for (int i=0; i < 3; ++i)
        {
            ok &= osresult1->setTimingInformation(i,"cpuTime","other",/*"tick",*/"second","blabla",3.14);
            if (!ok) 
                throw ErrorClass("Error during setTimingInformation!");
            ok &= (!osresult1->IsEqual(osresult2));
            if (!ok) 
                throw ErrorClass("setTimingInformation: osresult objects falsely compare equal!");
            ok &= osresult2->setTimingInformation(i,"cpuTime","other",/*"tick",*/"second","blabla",3.14);
            if (!ok) 
                throw ErrorClass("Error during setTimingInformation!");
            ok &= (osresult1->IsEqual(osresult2));
            if (!ok) 
                throw ErrorClass("setTimingInformation: osresult objects falsely compare unequal!");

        }

        ok &= osresult1->setUsedDiskSpaceUnit("megabyte");
        if (!ok) 
            throw ErrorClass("Error during setUsedDiskSpaceUnit!");
        ok &= (!osresult1->IsEqual(osresult2));
        if (!ok) 
            throw ErrorClass("setUsedDiskSpaceUnit: osresult objects falsely compare equal!");
        ok &= osresult2->setUsedDiskSpaceUnit("megabyte");
        if (!ok) 
            throw ErrorClass("Error during setUsedDiskSpaceUnit!");
        ok &= (osresult1->IsEqual(osresult2));
        if (!ok) 
            throw ErrorClass("setUsedDiskSpaceUnit: osresult objects falsely compare unequal!");

        ok &= osresult1->setUsedDiskSpaceDescription("testing 123");
        if (!ok) 
            throw ErrorClass("Error during setUsedDiskSpaceDescription!");
        ok &= (!osresult1->IsEqual(osresult2));
        if (!ok) 
            throw ErrorClass("setUsedDiskSpaceDescription: osresult objects falsely compare equal!");
        ok &= osresult2->setUsedDiskSpaceDescription("testing 123");
        if (!ok) 
            throw ErrorClass("Error during setUsedDiskSpaceDescription!");
        ok &= (osresult1->IsEqual(osresult2));
        if (!ok) 
            throw ErrorClass("setUsedDiskSpaceDescription: osresult objects falsely compare unequal!");

        ok &= osresult1->setUsedDiskSpaceValue(100.0);
        if (!ok) 
            throw ErrorClass("Error during setUsedDiskSpaceValue!");
        ok &= (!osresult1->IsEqual(osresult2));
        if (!ok) 
            throw ErrorClass("setUsedDiskSpaceValue: osresult objects falsely compare equal!");
        ok &= osresult2->setUsedDiskSpaceValue(100.0);
        if (!ok) 
            throw ErrorClass("Error during setUsedDiskSpaceValue!");
        ok &= (osresult1->IsEqual(osresult2));
        if (!ok) 
            throw ErrorClass("setUsedDiskSpaceValue: osresult objects falsely compare unequal!");

        ok &= osresult1->setUsedMemoryUnit("megabyte");
        if (!ok) 
            throw ErrorClass("Error during setUsedMemoryUnit!");
        ok &= (!osresult1->IsEqual(osresult2));
        if (!ok) 
            throw ErrorClass("setUsedMemoryUnit: osresult objects falsely compare equal!");
        ok &= osresult2->setUsedMemoryUnit("megabyte");
        if (!ok) 
            throw ErrorClass("Error during setUsedMemoryUnit!");
        ok &= (osresult1->IsEqual(osresult2));
        if (!ok) 
            throw ErrorClass("setUsedMemoryUnit: osresult objects falsely compare unequal!");

        ok &= osresult1->setUsedMemoryDescription("testing 123");
        if (!ok) 
            throw ErrorClass("Error during setUsedMemoryDescription!");
        ok &= (!osresult1->IsEqual(osresult2));
        if (!ok) 
            throw ErrorClass("setUsedMemoryDescription: osresult objects falsely compare equal!");
        ok &= osresult2->setUsedMemoryDescription("testing 123");
        if (!ok) 
            throw ErrorClass("Error during setUsedMemoryDescription!");
        ok &= (osresult1->IsEqual(osresult2));
        if (!ok) 
            throw ErrorClass("setUsedMemoryDescription: osresult objects falsely compare unequal!");

        ok &= osresult1->setUsedMemoryValue(100.0);
        if (!ok) 
            throw ErrorClass("Error during setUsedMemoryValue!");
        ok &= (!osresult1->IsEqual(osresult2));
        if (!ok) 
            throw ErrorClass("setUsedMemoryValue: osresult objects falsely compare equal!");
        ok &= osresult2->setUsedMemoryValue(100.0);
        if (!ok) 
            throw ErrorClass("Error during setUsedMemoryValue!");
        ok &= (osresult1->IsEqual(osresult2));
        if (!ok) 
            throw ErrorClass("setUsedMemoryValue: osresult objects falsely compare unequal!");

        ok &= osresult1->setUsedCPUSpeedUnit("megahertz");
        if (!ok) 
            throw ErrorClass("Error during setUsedCPUSpeedUnit!");
        ok &= (!osresult1->IsEqual(osresult2));
        if (!ok) 
            throw ErrorClass("setUsedCPUSpeedUnit: osresult objects falsely compare equal!");
        ok &= osresult2->setUsedCPUSpeedUnit("megahertz");
        if (!ok) 
            throw ErrorClass("Error during setUsedCPUSpeedUnit!");
        ok &= (osresult1->IsEqual(osresult2));
        if (!ok) 
            throw ErrorClass("setUsedCPUSpeedUnit: osresult objects falsely compare unequal!");

        ok &= osresult1->setUsedCPUSpeedDescription("testing 123");
        if (!ok) 
            throw ErrorClass("Error during setUsedCPUSpeedDescription!");
        ok &= (!osresult1->IsEqual(osresult2));
        if (!ok) 
            throw ErrorClass("setUsedCPUSpeedDescription: osresult objects falsely compare equal!");
        ok &= osresult2->setUsedCPUSpeedDescription("testing 123");
        if (!ok) 
            throw ErrorClass("Error during setUsedCPUSpeedDescription!");
        ok &= (osresult1->IsEqual(osresult2));
        if (!ok) 
            throw ErrorClass("setUsedCPUSpeedDescription: osresult objects falsely compare unequal!");

        ok &= osresult1->setUsedCPUSpeedValue(100.0);
        if (!ok) 
            throw ErrorClass("Error during setUsedCPUSpeedValue!");
        ok &= (!osresult1->IsEqual(osresult2));
        if (!ok) 
            throw ErrorClass("setUsedCPUSpeedValue: osresult objects falsely compare equal!");
        ok &= osresult2->setUsedCPUSpeedValue(100.0);
        if (!ok) 
            throw ErrorClass("Error during setUsedCPUSpeedValue!");
        ok &= (osresult1->IsEqual(osresult2));
        if (!ok) 
            throw ErrorClass("setUsedCPUSpeedValue: osresult objects falsely compare unequal!");

        ok &= osresult1->setUsedCPUNumberDescription("testing 123");
        if (!ok) 
            throw ErrorClass("Error during setUsedCPUNumberDescription!");
        ok &= (!osresult1->IsEqual(osresult2));
        if (!ok) 
            throw ErrorClass("setUsedCPUNumberDescription: osresult objects falsely compare equal!");
        ok &= osresult2->setUsedCPUNumberDescription("testing 123");
        if (!ok) 
            throw ErrorClass("Error during setUsedCPUNumberDescription!");
        ok &= (osresult1->IsEqual(osresult2));
        if (!ok) 
            throw ErrorClass("setUsedCPUNumberDescription: osresult objects falsely compare unequal!");

        ok &= osresult1->setUsedCPUNumberValue(100);
        if (!ok) 
            throw ErrorClass("Error during setUsedCPUNumberValue!");
        ok &= (!osresult1->IsEqual(osresult2));
        if (!ok) 
            throw ErrorClass("setUsedCPUNumberValue: osresult objects falsely compare equal!");
        ok &= osresult2->setUsedCPUNumberValue(100);
        if (!ok) 
            throw ErrorClass("Error during setUsedCPUNumberValue!");
        ok &= (osresult1->IsEqual(osresult2));
        if (!ok) 
            throw ErrorClass("setUsedCPUNumberValue: osresult objects falsely compare unequal!");

        ok &= osresult1->setNumberOfOtherJobResults(3);
        if (!ok) 
            throw ErrorClass("Error during setNumberOfOtherJobResults!");
        ok &= (!osresult1->IsEqual(osresult2));
        if (!ok) 
            throw ErrorClass("setNumberOfOtherJobResults: osresult objects falsely compare equal!");
        ok &= osresult2->setNumberOfOtherJobResults(3);
        if (!ok) 
            throw ErrorClass("Error during setNumberOfOtherJobResults!");
        ok &= (osresult1->IsEqual(osresult2));
        if (!ok) 
            throw ErrorClass("setNumberOfOtherJobResults: osresult objects falsely compare unequal!");

        for (int i=0; i < 3; ++i)
        {
            ok &= osresult1->setOtherJobResultName(i,"some name");
            if (!ok) 
                throw ErrorClass("Error during setOtherJobResultName!");
            ok &= (!osresult1->IsEqual(osresult2));
            if (!ok) 
                throw ErrorClass("setOtherJobResultName: osresult objects falsely compare equal!");
            ok &= osresult2->setOtherJobResultName(i,"some name");
            if (!ok) 
                throw ErrorClass("Error during setOtherJobResultName!");
            ok &= (osresult1->IsEqual(osresult2));
            if (!ok) 
                throw ErrorClass("setOtherJobResultName: osresult objects falsely compare unequal!");

            ok &= osresult1->setOtherJobResultValue(i,"some value");
            if (!ok) 
                throw ErrorClass("Error during setOtherJobResultValue!");
            ok &= (!osresult1->IsEqual(osresult2));
            if (!ok) 
                throw ErrorClass("setOtherJobResultValue: osresult objects falsely compare equal!");
            ok &= osresult2->setOtherJobResultValue(i,"some value");
            if (!ok) 
                throw ErrorClass("Error during setOtherJobResultValue!");
            ok &= (osresult1->IsEqual(osresult2));
            if (!ok) 
                throw ErrorClass("setOtherJobResultValue: osresult objects falsely compare unequal!");

            ok &= osresult1->setOtherJobResultDescription(i,"ABC 123");
            if (!ok) 
                throw ErrorClass("Error during setOtherJobResultDescription!");
            ok &= (!osresult1->IsEqual(osresult2));
            if (!ok) 
                throw ErrorClass("setOtherJobResultDescription: osresult objects falsely compare equal!");
            ok &= osresult2->setOtherJobResultDescription(i,"ABC 123");
            if (!ok) 
                throw ErrorClass("Error during setOtherJobResultDescription!");
            ok &= (osresult1->IsEqual(osresult2));
            if (!ok) 
                throw ErrorClass("setOtherJobResultDescription: osresult objects falsely compare unequal!");
        }

        ok &= osresult1->setSolutionNumber(2);
        if (!ok) 
            throw ErrorClass("Error during setSolutionNumber!");
        ok &= (!osresult1->IsEqual(osresult2));
        if (!ok) 
            throw ErrorClass("setSolutionNumber: osresult objects falsely compare equal!");
        ok &= osresult2->setSolutionNumber(2);
        if (!ok) 
            throw ErrorClass("Error during setSolutionNumber!");
        ok &= (osresult1->IsEqual(osresult2));
        if (!ok) 
            throw ErrorClass("setSolutionNumber: osresult objects falsely compare unequal!");

        ok &= osresult1->setVariableNumber(4);
        if (!ok) 
            throw ErrorClass("Error during setVariableNumber!");
        ok &= (!osresult1->IsEqual(osresult2));
        if (!ok) 
            throw ErrorClass("setVariableNumber: osresult objects falsely compare equal!");
        ok &= osresult2->setVariableNumber(4);
        if (!ok) 
            throw ErrorClass("Error during setVariableNumber!");
        ok &= (osresult1->IsEqual(osresult2));
        if (!ok) 
            throw ErrorClass("setVariableNumber: osresult objects falsely compare unequal!");

        ok &= osresult1->setObjectiveNumber(2);
        if (!ok) 
            throw ErrorClass("Error during setObjectiveNumber!");
        ok &= (!osresult1->IsEqual(osresult2));
        if (!ok) 
            throw ErrorClass("setObjectiveNumber: osresult objects falsely compare equal!");
        ok &= osresult2->setObjectiveNumber(2);
        if (!ok) 
            throw ErrorClass("Error during setObjectiveNumber!");
        ok &= (osresult1->IsEqual(osresult2));
        if (!ok) 
            throw ErrorClass("setObjectiveNumber: osresult objects falsely compare unequal!");

        ok &= osresult1->setConstraintNumber(3);
        if (!ok) 
            throw ErrorClass("Error during setConstraintNumber!");
        ok &= (!osresult1->IsEqual(osresult2));
        if (!ok) 
            throw ErrorClass("setConstraintNumber: osresult objects falsely compare equal!");
        ok &= osresult2->setConstraintNumber(3);
        if (!ok) 
            throw ErrorClass("Error during setConstraintNumber!");
        ok &= (osresult1->IsEqual(osresult2));
        if (!ok) 
            throw ErrorClass("setConstraintNumber: osresult objects falsely compare unequal!");

        for (int i=0; i < 2; ++i)
        {
            ok &= osresult1->setSolutionTargetObjectiveIdx(i,-2);
            if (!ok) 
                throw ErrorClass("Error during setSolutionTargetObjectiveIdx!");
            ok &= (!osresult1->IsEqual(osresult2));
            if (!ok) 
                throw ErrorClass("setSolutionTargetObjectiveIdx: osresult objects falsely compare equal!");
            ok &= osresult2->setSolutionTargetObjectiveIdx(i,-2);
            if (!ok) 
                throw ErrorClass("Error during setSolutionTargetObjectiveIdx!");
            ok &= (osresult1->IsEqual(osresult2));
            if (!ok) 
                throw ErrorClass("setSolutionTargetObjectiveIdx: osresult objects falsely compare unequal!");

            ok &= osresult1->setSolutionTargetObjectiveName(i,"a.n.other");
            if (!ok) 
                throw ErrorClass("Error during setSolutionTargetObjectiveName!");
            ok &= (!osresult1->IsEqual(osresult2));
            if (!ok) 
                throw ErrorClass("setSolutionTargetObjectiveName: osresult objects falsely compare equal!");
            ok &= osresult2->setSolutionTargetObjectiveName(i,"a.n.other");
            if (!ok) 
                throw ErrorClass("Error during setSolutionTargetObjectiveName!");
            ok &= (osresult1->IsEqual(osresult2));
            if (!ok) 
                throw ErrorClass("setSolutionTargetObjectiveName: osresult objects falsely compare unequal!");

            ok &= osresult1->setSolutionWeightedObjectives(i,"true");
            if (!ok) 
                throw ErrorClass("Error during setSolutionWeightedObjectives!");
            ok &= (!osresult1->IsEqual(osresult2));
            if (!ok) 
                throw ErrorClass("setSolutionWeightedObjectives: osresult objects falsely compare equal!");
            ok &= osresult2->setSolutionWeightedObjectives(i,"true");
            if (!ok) 
                throw ErrorClass("Error during setSolutionWeightedObjectives!");
            ok &= (osresult1->IsEqual(osresult2));
            if (!ok) 
                throw ErrorClass("setSolutionWeightedObjectives: osresult objects falsely compare unequal!");

            ok &= osresult1->setSolutionStatusType(i,"locallyOptimal");
            if (!ok) 
                throw ErrorClass("Error during setSolutionStatusType!");
            ok &= (!osresult1->IsEqual(osresult2));
            if (!ok) 
                throw ErrorClass("setSolutionStatusType: osresult objects falsely compare equal!");
            ok &= osresult2->setSolutionStatusType(i,"locallyOptimal");
            if (!ok) 
                throw ErrorClass("Error during setSolutionStatusType!");
            ok &= (osresult1->IsEqual(osresult2));
            if (!ok) 
                throw ErrorClass("setSolutionStatusType: osresult objects falsely compare unequal!");

            ok &= osresult1->setSolutionStatusDescription(i,"ABC 123");
            if (!ok) 
                throw ErrorClass("Error during setSolutionStatusDescription!");
            ok &= (!osresult1->IsEqual(osresult2));
            if (!ok) 
                throw ErrorClass("setSolutionStatusDescription: osresult objects falsely compare equal!");
            ok &= osresult2->setSolutionStatusDescription(i,"ABC 123");
            if (!ok) 
                throw ErrorClass("Error during setSolutionStatusDescription!");
            ok &= (osresult1->IsEqual(osresult2));
            if (!ok) 
                throw ErrorClass("setSolutionStatusDescription: osresult objects falsely compare unequal!");

            ok &= osresult1->setNumberOfSolutionSubstatuses(i,3);
            if (!ok) 
                throw ErrorClass("Error during setNumberOfSolutionSubstatuses!");
            ok &= (!osresult1->IsEqual(osresult2));
            if (!ok) 
                throw ErrorClass("setNumberOfSolutionSubstatuses: osresult objects falsely compare equal!");
            ok &= osresult2->setNumberOfSolutionSubstatuses(i,3);
            if (!ok) 
                throw ErrorClass("Error during setNumberOfSolutionSubstatuses!");
            ok &= (osresult1->IsEqual(osresult2));
            if (!ok) 
                throw ErrorClass("setNumberOfSolutionSubstatuses: osresult objects falsely compare unequal!");

            for (int j=0; j < 3; ++j)
            {
                ok &= osresult1->setSolutionSubstatusType(i,j,"other");
                if (!ok) 
                    throw ErrorClass("Error during setSolutionSubstatusType!");
                ok &= (!osresult1->IsEqual(osresult2));
                if (!ok) 
                    throw ErrorClass("setSolutionSubstatusType: osresult objects falsely compare equal!");
                ok &= osresult2->setSolutionSubstatusType(i,j,"other");
                if (!ok) 
                    throw ErrorClass("Error during setSolutionSubstatusType!");
                ok &= (osresult1->IsEqual(osresult2));
                if (!ok) 
                    throw ErrorClass("setSolutionSubstatusType: osresult objects falsely compare unequal!");

                ok &= osresult1->setSolutionSubstatusDescription(i,j,"whatever");
                if (!ok) 
                    throw ErrorClass("Error during setSolutionSubstatusDescription!");
                ok &= (!osresult1->IsEqual(osresult2));
                if (!ok) 
                    throw ErrorClass("setSolutionSubstatusDescription: osresult objects falsely compare equal!");
                ok &= osresult2->setSolutionSubstatusDescription(i,j,"whatever");
                if (!ok) 
                    throw ErrorClass("Error during setSolutionSubstatusDescription!");
                ok &= (osresult1->IsEqual(osresult2));
                if (!ok) 
                    throw ErrorClass("setSolutionSubstatusDescription: osresult objects falsely compare unequal!");
            }

            ok &= osresult1->setSolutionMessage(i,"ABC 123");
            if (!ok) 
                throw ErrorClass("Error during setSolutionMessage!");
            ok &= (!osresult1->IsEqual(osresult2));
            if (!ok) 
                throw ErrorClass("setSolutionMessage: osresult objects falsely compare equal!");
            ok &= osresult2->setSolutionMessage(i,"ABC 123");
            if (!ok) 
                throw ErrorClass("Error during setSolutionMessage!");
            ok &= (osresult1->IsEqual(osresult2));
            if (!ok) 
                throw ErrorClass("setSolutionMessage: osresult objects falsely compare unequal!");

            ok &= osresult1->setNumberOfVarValues(i,3);
            if (!ok) 
                throw ErrorClass("Error during setNumberOfVarValues!");
            ok &= (!osresult1->IsEqual(osresult2));
            if (!ok) 
                throw ErrorClass("setNumberOfVarValues: osresult objects falsely compare equal!");
            ok &= osresult2->setNumberOfVarValues(i,3);
            if (!ok) 
                throw ErrorClass("Error during setNumberOfVarValues!");
            ok &= (osresult1->IsEqual(osresult2));
            if (!ok) 
                throw ErrorClass("setNumberOfVarValues: osresult objects falsely compare unequal!");

            for (int j=0; j < 3; ++j)
            {
                ok &= osresult1->setVarValue(i,j,j,"varname",3.14);
                if (!ok) 
                    throw ErrorClass("Error during setVarValue!");
                ok &= (!osresult1->IsEqual(osresult2));
                if (!ok) 
                    throw ErrorClass("setVarValue: osresult objects falsely compare equal!");
                ok &= osresult2->setVarValue(i,j,j,"varname",3.14);
                if (!ok) 
                    throw ErrorClass("Error during setVarValue!");
                ok &= (osresult1->IsEqual(osresult2));
                if (!ok) 
                    throw ErrorClass("setVarValue: osresult objects falsely compare unequal!");
            }

            ok &= osresult1->setNumberOfVarValuesString(i,3);
            if (!ok) 
                throw ErrorClass("Error during setNumberOfVarValuesString!");
            ok &= (!osresult1->IsEqual(osresult2));
            if (!ok) 
                throw ErrorClass("setNumberOfVarValuesString: osresult objects falsely compare equal!");

            ok &= osresult2->setNumberOfVarValuesString(i,3);
            if (!ok) 
                throw ErrorClass("Error during setNumberOfVarValuesString!");
            ok &= (osresult1->IsEqual(osresult2));
            if (!ok) 
                throw ErrorClass("setNumberOfVarValuesString: osresult objects falsely compare unequal!");

            for (int j=0; j < 3; ++j)
            {
                ok &= osresult1->setVarValueString(i,j,j,"varname","one");
                if (!ok) 
                    throw ErrorClass("Error during setVarValueString!");
                ok &= (!osresult1->IsEqual(osresult2));
                if (!ok) 
                    throw ErrorClass("setVarValueString: osresult objects falsely compare equal!");
                ok &= osresult2->setVarValueString(i,j,j,"varname","one");
                if (!ok) 
                    throw ErrorClass("Error during setVarValueString!");
                ok &= (osresult1->IsEqual(osresult2));
                if (!ok) 
                    throw ErrorClass("setVarValueString: osresult objects falsely compare unequal!");
            }

            intArray[0]=1000*i + 1100 + 10 + 1;
            intArray[1]=1000*i + 1100 + 10 + 2;
            intArray[2]=1000*i + 1100 + 10 + 3;

            ok &= osresult1->setBasisStatus(i, ENUM_PROBLEM_COMPONENT_variables, ENUM_BASIS_STATUS_basic, intArray, 3);
            if (!ok) 
                throw ErrorClass("Error during setBasisStatus (variables basic)!");
            ok &= (!osresult1->IsEqual(osresult2));
            if (!ok) 
                throw ErrorClass("setBasisStatus (variables basic): osresult objects falsely compare equal!");
            ok &= osresult2->setBasisStatus(i, ENUM_PROBLEM_COMPONENT_variables, ENUM_BASIS_STATUS_basic, intArray, 3);
            if (!ok) 
                throw ErrorClass("Error during setBasisStatus (variables basic)!");
            ok &= (osresult1->IsEqual(osresult2));
            if (!ok) 
                throw ErrorClass("setBasisStatus (variables basic): osresult objects falsely compare unequal!");

            intArray[0] = intArray[0] + 10;
            intArray[1] = intArray[1] + 10;
            intArray[2] = intArray[2] + 10;


            ok &= osresult1->setBasisStatus(i, ENUM_PROBLEM_COMPONENT_variables, ENUM_BASIS_STATUS_atLower, intArray, 3);
            if (!ok) 
                throw ErrorClass("Error during setBasisStatus (variables atLower)!");
            ok &= (!osresult1->IsEqual(osresult2));
            if (!ok) 
                throw ErrorClass("setBasisStatus (variables atLower): osresult objects falsely compare equal!");
            ok &= osresult2->setBasisStatus(i, ENUM_PROBLEM_COMPONENT_variables, ENUM_BASIS_STATUS_atLower, intArray, 3);
            if (!ok) 
                throw ErrorClass("Error during setBasisStatus (variables atLower)!");
            ok &= (osresult1->IsEqual(osresult2));
            if (!ok) 
                throw ErrorClass("setBasisStatus (variables atLower): osresult objects falsely compare unequal!");
            intArray[0] = intArray[0] + 10;
            intArray[1] = intArray[1] + 10;

            intArray[2] = intArray[2] + 10;


            ok &= osresult1->setBasisStatus(i, ENUM_PROBLEM_COMPONENT_variables, ENUM_BASIS_STATUS_atUpper, intArray, 3);
            if (!ok) 
                throw ErrorClass("Error during setBasisStatus (variables atUpper)!");
            ok &= (!osresult1->IsEqual(osresult2));
            if (!ok) 
                throw ErrorClass("setBasisStatus (variables atUpper): osresult objects falsely compare equal!");
            ok &= osresult2->setBasisStatus(i, ENUM_PROBLEM_COMPONENT_variables, ENUM_BASIS_STATUS_atUpper, intArray, 3);
            if (!ok) 
                throw ErrorClass("Error during setBasisStatus (variables atUpper)!");
            ok &= (osresult1->IsEqual(osresult2));
            if (!ok) 
                throw ErrorClass("setBasisStatus (variables atUpper): osresult objects falsely compare unequal!");
            intArray[0] = intArray[0] + 10;
            intArray[1] = intArray[1] + 10;

            intArray[2] = intArray[2] + 10;


            ok &= osresult1->setBasisStatus(i, ENUM_PROBLEM_COMPONENT_variables, ENUM_BASIS_STATUS_atEquality, intArray, 3);
            if (!ok) 
                throw ErrorClass("Error during setBasisStatus (variables atEquality)!");
            ok &= (!osresult1->IsEqual(osresult2));
            if (!ok) 
                throw ErrorClass("setBasisStatus (variables atEquality): osresult objects falsely compare equal!");
            ok &= osresult2->setBasisStatus(i, ENUM_PROBLEM_COMPONENT_variables, ENUM_BASIS_STATUS_atEquality, intArray, 3);
            if (!ok) 
                throw ErrorClass("Error during setBasisStatus (variables atEquality)!");
            ok &= (osresult1->IsEqual(osresult2));
            if (!ok) 
                throw ErrorClass("setBasisStatus (variables atEquality): osresult objects falsely compare unequal!");

            intArray[0] = intArray[0] + 10;
            intArray[1] = intArray[1] + 10;
            intArray[2] = intArray[2] + 10;

            ok &= osresult1->setBasisStatus(i, ENUM_PROBLEM_COMPONENT_variables, ENUM_BASIS_STATUS_isFree, intArray, 3);
            if (!ok) 
                throw ErrorClass("Error during setBasisStatus (variables isFree)!");
            ok &= (!osresult1->IsEqual(osresult2));
            if (!ok) 
                throw ErrorClass("setBasisStatus (variables isFree): osresult objects falsely compare equal!");
            ok &= osresult2->setBasisStatus(i, ENUM_PROBLEM_COMPONENT_variables, ENUM_BASIS_STATUS_isFree, intArray, 3);
            if (!ok) 
                throw ErrorClass("Error during setBasisStatus (variables isFree)!");
            ok &= (osresult1->IsEqual(osresult2));
            if (!ok) 
                throw ErrorClass("setBasisStatus (variables isFree): osresult objects falsely compare unequal!");

            intArray[0] = intArray[0] + 10;
            intArray[1] = intArray[1] + 10;
            intArray[2] = intArray[2] + 10;

            ok &= osresult1->setBasisStatus(i, ENUM_PROBLEM_COMPONENT_variables, ENUM_BASIS_STATUS_superbasic, intArray, 3);
            if (!ok) 
                throw ErrorClass("Error during setBasisStatus (variables superbasic)!");
            ok &= (!osresult1->IsEqual(osresult2));
            if (!ok) 
                throw ErrorClass("setBasisStatus (variables superbasic): osresult objects falsely compare equal!");
            ok &= osresult2->setBasisStatus(i, ENUM_PROBLEM_COMPONENT_variables, ENUM_BASIS_STATUS_superbasic, intArray, 3);
            if (!ok) 
                throw ErrorClass("Error during setBasisStatus (variables superbasic)!");
            ok &= (osresult1->IsEqual(osresult2));
            if (!ok) 
                throw ErrorClass("setBasisStatus (variables superbasic): osresult objects falsely compare unequal!");

            intArray[0] = intArray[0] + 10;
            intArray[1] = intArray[1] + 10;
            intArray[2] = intArray[2] + 10;

            ok &= osresult1->setBasisStatus(i, ENUM_PROBLEM_COMPONENT_variables, ENUM_BASIS_STATUS_unknown, intArray, 3);
            if (!ok) 
                throw ErrorClass("Error during setBasisStatus (variables unknown)!");
            ok &= (!osresult1->IsEqual(osresult2));
            if (!ok) 
                throw ErrorClass("setBasisStatus (variables unknown): osresult objects falsely compare equal!");
            ok &= osresult2->setBasisStatus(i, ENUM_PROBLEM_COMPONENT_variables, ENUM_BASIS_STATUS_unknown, intArray, 3);
            if (!ok) 
                throw ErrorClass("Error during setBasisStatus (variables unknown)!");
            ok &= (osresult1->IsEqual(osresult2));
            if (!ok) 
                throw ErrorClass("setBasisStatus (variables unknown): osresult objects falsely compare unequal!");
            
            ok &= osresult1->setNumberOfOtherVariableResults(i,3);
            if (!ok) 
                throw ErrorClass("Error during setNumberOfOtherVariableResults!");
            ok &= (!osresult1->IsEqual(osresult2));
            if (!ok) 
                throw ErrorClass("setNumberOfOtherVariableResults: osresult objects falsely compare equal!");
            ok &= osresult2->setNumberOfOtherVariableResults(i,3);
            if (!ok) 
                throw ErrorClass("Error during setNumberOfOtherVariableResults!");
            ok &= (osresult1->IsEqual(osresult2));
            if (!ok) 
                throw ErrorClass("setNumberOfOtherVariableResults: osresult objects falsely compare unequal!");

            for (int j=0; j < 2; ++j)
            {
                ok &= osresult1->setOtherVariableResultName(i,j,"other");
                if (!ok) 
                    throw ErrorClass("Error during setOtherVariableResultName!");
                ok &= (!osresult1->IsEqual(osresult2));
                if (!ok) 
                    throw ErrorClass("setOtherVariableResultName: osresult objects falsely compare equal!");
                ok &= osresult2->setOtherVariableResultName(i,j,"other");
                if (!ok) 
                    throw ErrorClass("Error during setOtherVariableResultName!");
                ok &= (osresult1->IsEqual(osresult2));
                if (!ok) 
                    throw ErrorClass("setOtherVariableResultName: osresult objects falsely compare unequal!");

                ok &= osresult1->setOtherVariableResultDescription(i,j,"other");
                if (!ok) 
                    throw ErrorClass("Error during setOtherVariableResultDescription!");
                ok &= (!osresult1->IsEqual(osresult2));
                if (!ok) 
                    throw ErrorClass("setOtherVariableResultDescription: osresult objects falsely compare equal!");
                ok &= osresult2->setOtherVariableResultDescription(i,j,"other");
                if (!ok) 
                    throw ErrorClass("Error during setOtherVariableResultDescription!");
                ok &= (osresult1->IsEqual(osresult2));
                if (!ok) 
                    throw ErrorClass("setOtherVariableResultDescription: osresult objects falsely compare unequal!");

                ok &= osresult1->setOtherVariableResultValue(i,j,"other");
                if (!ok) 
                    throw ErrorClass("Error during setOtherVariableResultValue!");
                ok &= (!osresult1->IsEqual(osresult2));
                if (!ok) 
                    throw ErrorClass("setOtherVariableResultValue: osresult objects falsely compare equal!");
                ok &= osresult2->setOtherVariableResultValue(i,j,"other");
                if (!ok) 
                    throw ErrorClass("Error during setOtherVariableResultValue!");
                ok &= (osresult1->IsEqual(osresult2));
                if (!ok) 
                    throw ErrorClass("setOtherVariableResultValue: osresult objects falsely compare unequal!");

                ok &= osresult1->setOtherVariableResultNumberOfVar(i,j,3);
                if (!ok) 
                    throw ErrorClass("Error during setOtherVariableResultNumberOfVar!");
                ok &= (!osresult1->IsEqual(osresult2));
                if (!ok) 
                    throw ErrorClass("setOtherVariableResultNumberOfVar: osresult objects falsely compare equal!");
                ok &= osresult2->setOtherVariableResultNumberOfVar(i,j,3);
                if (!ok) 
                    throw ErrorClass("Error during setOtherVariableResultNumberOfVar!");
                ok &= (osresult1->IsEqual(osresult2));
                if (!ok) 
                    throw ErrorClass("setOtherVariableResultNumberOfVar: osresult objects falsely compare unequal!");

                for (int k=0; k < 3; ++k)
                {
                    ok &= osresult1->setOtherVariableResultVarIdx(i,j,k,k);
                    if (!ok) 
                        throw ErrorClass("Error during setOtherVariableResultVarIdx!");
                    ok &= (!osresult1->IsEqual(osresult2));
                    if (!ok) 
                        throw ErrorClass("setOtherVariableResultVarIdx: osresult objects falsely compare equal!");
                    ok &= osresult2->setOtherVariableResultVarIdx(i,j,k,k);
                    if (!ok) 
                        throw ErrorClass("Error during setOtherVariableResultVarIdx!");
                    ok &= (osresult1->IsEqual(osresult2));
                    if (!ok) 
                        throw ErrorClass("setOtherVariableResultVarIdx: osresult objects falsely compare unequal!");

                    ok &= osresult1->setOtherVariableResultVar(i,j,k,"value");
                    if (!ok) 
                        throw ErrorClass("Error during setOtherVariableResultVar!");
                    ok &= (!osresult1->IsEqual(osresult2));
                    if (!ok) 
                        throw ErrorClass("setOtherVariableResultVar: osresult objects falsely compare equal!");
                    ok &= osresult2->setOtherVariableResultVar(i,j,k,"value");
                    if (!ok) 
                        throw ErrorClass("Error during setOtherVariableResultVar!");
                    ok &= (osresult1->IsEqual(osresult2));
                    if (!ok) 
                        throw ErrorClass("setOtherVariableResultVar: osresult objects falsely compare unequal!");
                }
            }

// The third <other> result uses enumerations

            ok &= osresult1->setOtherVariableResultName(i,2,"other");
            if (!ok) 
                throw ErrorClass("Error during setOtherVariableResultName!");
            ok &= (!osresult1->IsEqual(osresult2));
            if (!ok) 
                throw ErrorClass("setOtherVariableResultName: osresult objects falsely compare equal!");
            ok &= osresult2->setOtherVariableResultName(i,2,"other");
            if (!ok) 
                throw ErrorClass("Error during setOtherVariableResultName!");

            ok &= (osresult1->IsEqual(osresult2));
            if (!ok) 
                throw ErrorClass("setOtherVariableResultName: osresult objects falsely compare unequal!");

            ok &= osresult1->setOtherVariableResultDescription(i,2,"other");
            if (!ok) 
                throw ErrorClass("Error during setOtherVariableResultDescription!");
            ok &= (!osresult1->IsEqual(osresult2));
            if (!ok) 
                throw ErrorClass("setOtherVariableResultDescription: osresult objects falsely compare equal!");
            ok &= osresult2->setOtherVariableResultDescription(i,2,"other");
            if (!ok) 
                throw ErrorClass("Error during setOtherVariableResultDescription!");
            ok &= (osresult1->IsEqual(osresult2));
            if (!ok) 
                throw ErrorClass("setOtherVariableResultDescription: osresult objects falsely compare unequal!");

            ok &= osresult1->setOtherVariableResultValue(i,2,"other");
            if (!ok) 
                throw ErrorClass("Error during setOtherVariableResultValue!");
            ok &= (!osresult1->IsEqual(osresult2));
            if (!ok) 
                throw ErrorClass("setOtherVariableResultValue: osresult objects falsely compare equal!");
            ok &= osresult2->setOtherVariableResultValue(i,2,"other");
            if (!ok) 
                throw ErrorClass("Error during setOtherVariableResultValue!");
            ok &= (osresult1->IsEqual(osresult2));
            if (!ok) 
                throw ErrorClass("setOtherVariableResultValue: osresult objects falsely compare unequal!");


            ok &= osresult1->setOtherVariableResultNumberOfEnumerations(i,2,2);
            if (!ok) 
                throw ErrorClass("Error during setOtherVariableResultNumberOfEnumerations!");
            ok &= (!osresult1->IsEqual(osresult2));
            if (!ok) 
                throw ErrorClass("setOtherVariableResultNumberOfEnumerations: osresult objects falsely compare equal!");
            ok &= osresult2->setOtherVariableResultNumberOfEnumerations(i,2,2);
            if (!ok) 
                throw ErrorClass("Error during setOtherVariableResultNumberOfEnumerations!");
            ok &= (osresult1->IsEqual(osresult2));
            if (!ok) 
                throw ErrorClass("setOtherVariableResultNumberOfEnumerations: osresult objects falsely compare unequal!");

            for (int k=0; k < 2; ++k)
            {
            intArray[0] = 1000*i + 1130 + 10*k + 1;
            intArray[1] = 1000*i + 1130 + 10*k + 2;
            intArray[2] = 1000*i + 1130 + 10*k + 3;


                ok &= osresult1->setOtherOptionEnumeration(i,2,ENUM_PROBLEM_COMPONENT_variables,k,"value","description",intArray,3);
                if (!ok) 
                    throw ErrorClass("Error during setOtherOptionEnumeration!");
                ok &= (!osresult1->IsEqual(osresult2));
                if (!ok) 
                    throw ErrorClass("setOtherOptionEnumeration: osresult objects falsely compare equal!");
                ok &= osresult2->setOtherOptionEnumeration(i,2,ENUM_PROBLEM_COMPONENT_variables,k,"value","description",intArray,3);
                if (!ok) 
                    throw ErrorClass("Error during setOtherOptionEnumeration!");
                ok &= (osresult1->IsEqual(osresult2));
                if (!ok) 
                    throw ErrorClass("setOtherOptionEnumeration: osresult objects falsely compare unequal!");
            }


            ok &= osresult1->setNumberOfObjValues(i,2);
            if (!ok) 
                throw ErrorClass("Error during setNumberOfObjValues!");
            ok &= (!osresult1->IsEqual(osresult2));
            if (!ok) 
                throw ErrorClass("setNumberOfObjValues: osresult objects falsely compare equal!");
            ok &= osresult2->setNumberOfObjValues(i,2);
            if (!ok) 
                throw ErrorClass("Error during setNumberOfObjValues!");
            ok &= (osresult1->IsEqual(osresult2));
            if (!ok) 
                throw ErrorClass("setNumberOfObjValues: osresult objects falsely compare unequal!");

            for (int j=0; j < 2; ++j)
            {
                ok &= osresult1->setObjValue(i,j,-2,"objname",3.14);
                if (!ok) 
                    throw ErrorClass("Error during setObjValue!");
                ok &= (!osresult1->IsEqual(osresult2));
                if (!ok) 
                    throw ErrorClass("setObjValue: osresult objects falsely compare equal!");
                ok &= osresult2->setObjValue(i,j,-2,"objname",3.14);
                if (!ok) 
                    throw ErrorClass("Error during setObjValue!");
                ok &= (osresult1->IsEqual(osresult2));
                if (!ok) 
                    throw ErrorClass("setObjValue: osresult objects falsely compare unequal!");
            }
            intArray[0] = -1000*i - 1200 - 10 - 1;
            intArray[1] = -1000*i - 1200 - 10 - 2;
            intArray[2] = -1000*i - 1200 - 10 - 3;

            ok &= osresult1->setBasisStatus(i, ENUM_PROBLEM_COMPONENT_objectives, ENUM_BASIS_STATUS_basic, intArray, 3);
            if (!ok) 
                throw ErrorClass("Error during setBasisStatus (objectives basic)!");
            ok &= (!osresult1->IsEqual(osresult2));
            if (!ok) 
                throw ErrorClass("setBasisStatus (objectives basic): osresult objects falsely compare equal!");
            ok &= osresult2->setBasisStatus(i, ENUM_PROBLEM_COMPONENT_objectives, ENUM_BASIS_STATUS_basic, intArray, 3);
            if (!ok) 
                throw ErrorClass("Error during setBasisStatus (objectives basic)!");
            ok &= (osresult1->IsEqual(osresult2));
            if (!ok) 
                throw ErrorClass("setBasisStatus (objectives basic): osresult objects falsely compare unequal!");

            intArray[0] = intArray[0] - 10;
            intArray[1] = intArray[1] - 10;
            intArray[2] = intArray[2] - 10;

            ok &= osresult1->setBasisStatus(i, ENUM_PROBLEM_COMPONENT_objectives, ENUM_BASIS_STATUS_atLower, intArray, 3);
            if (!ok) 
                throw ErrorClass("Error during setBasisStatus (objectives atLower)!");
            ok &= (!osresult1->IsEqual(osresult2));
            if (!ok) 
                throw ErrorClass("setBasisStatus (objectives atLower): osresult objects falsely compare equal!");
            ok &= osresult2->setBasisStatus(i, ENUM_PROBLEM_COMPONENT_objectives, ENUM_BASIS_STATUS_atLower, intArray, 3);
            if (!ok) 
                throw ErrorClass("Error during setBasisStatus (objectives atLower)!");
            ok &= (osresult1->IsEqual(osresult2));
            if (!ok) 
                throw ErrorClass("setBasisStatus (objectives atLower): osresult objects falsely compare unequal!");

            intArray[0] = intArray[0] - 10;
            intArray[1] = intArray[1] - 10;
            intArray[2] = intArray[2] - 10;

            ok &= osresult1->setBasisStatus(i, ENUM_PROBLEM_COMPONENT_objectives, ENUM_BASIS_STATUS_atUpper, intArray, 3);

            if (!ok) 
                throw ErrorClass("Error during setBasisStatus (objectives atUpper)!");
            ok &= (!osresult1->IsEqual(osresult2));
            if (!ok) 
                throw ErrorClass("setBasisStatus (objectives atUpper): osresult objects falsely compare equal!");
            ok &= osresult2->setBasisStatus(i, ENUM_PROBLEM_COMPONENT_objectives, ENUM_BASIS_STATUS_atUpper, intArray, 3);
            if (!ok) 
                throw ErrorClass("Error during setBasisStatus (objectives atUpper)!");
            ok &= (osresult1->IsEqual(osresult2));
            if (!ok) 
                throw ErrorClass("setBasisStatus (objectives atUpper): osresult objects falsely compare unequal!");

            intArray[0] = intArray[0] - 10;
            intArray[1] = intArray[1] - 10;
            intArray[2] = intArray[2] - 10;

            ok &= osresult1->setBasisStatus(i, ENUM_PROBLEM_COMPONENT_objectives, ENUM_BASIS_STATUS_atEquality, intArray, 3);

            if (!ok) 
                throw ErrorClass("Error during setBasisStatus (objectives atEquality)!");
            ok &= (!osresult1->IsEqual(osresult2));
            if (!ok) 
                throw ErrorClass("setBasisStatus (objectives atEquality): osresult objects falsely compare equal!");
            ok &= osresult2->setBasisStatus(i, ENUM_PROBLEM_COMPONENT_objectives, ENUM_BASIS_STATUS_atEquality, intArray, 3);
            if (!ok) 
                throw ErrorClass("Error during setBasisStatus (objectives atEquality)!");
            ok &= (osresult1->IsEqual(osresult2));
            if (!ok) 
                throw ErrorClass("setBasisStatus (objectives atEquality): osresult objects falsely compare unequal!");


            intArray[0] = intArray[0] - 10;
            intArray[1] = intArray[1] - 10;
            intArray[2] = intArray[2] - 10;

            ok &= osresult1->setBasisStatus(i, ENUM_PROBLEM_COMPONENT_objectives, ENUM_BASIS_STATUS_isFree, intArray, 3);
            if (!ok) 
                throw ErrorClass("Error during setBasisStatus (objectives isFree)!");
            ok &= (!osresult1->IsEqual(osresult2));
            if (!ok) 
                throw ErrorClass("setBasisStatus (objectives isFree): osresult objects falsely compare equal!");
            ok &= osresult2->setBasisStatus(i, ENUM_PROBLEM_COMPONENT_objectives, ENUM_BASIS_STATUS_isFree, intArray, 3);
            if (!ok) 
                throw ErrorClass("Error during setBasisStatus (objectives isFree)!");
            ok &= (osresult1->IsEqual(osresult2));
            if (!ok) 
                throw ErrorClass("setBasisStatus (objectives isFree): osresult objects falsely compare unequal!");


            intArray[0] = intArray[0] - 10;
            intArray[1] = intArray[1] - 10;
            intArray[2] = intArray[2] - 10;

            ok &= osresult1->setBasisStatus(i, ENUM_PROBLEM_COMPONENT_objectives, ENUM_BASIS_STATUS_superbasic, intArray, 3);
            if (!ok) 
                throw ErrorClass("Error during setBasisStatus (objectives superbasic)!");
            ok &= (!osresult1->IsEqual(osresult2));
            if (!ok) 
                throw ErrorClass("setBasisStatus (objectives superbasic): osresult objects falsely compare equal!");
            ok &= osresult2->setBasisStatus(i, ENUM_PROBLEM_COMPONENT_objectives, ENUM_BASIS_STATUS_superbasic, intArray, 3);
            if (!ok) 
                throw ErrorClass("Error during setBasisStatus (objectives superbasic)!");

            ok &= (osresult1->IsEqual(osresult2));
            if (!ok) 
                throw ErrorClass("setBasisStatus (objectives superbasic): osresult objects falsely compare unequal!");


            intArray[0] = intArray[0] - 10;
            intArray[1] = intArray[1] - 10;
            intArray[2] = intArray[2] - 10;

            ok &= osresult1->setBasisStatus(i, ENUM_PROBLEM_COMPONENT_objectives, ENUM_BASIS_STATUS_unknown, intArray, 3);
            if (!ok) 
                throw ErrorClass("Error during setBasisStatus (objectives unknown)!");
            ok &= (!osresult1->IsEqual(osresult2));
            if (!ok) 
                throw ErrorClass("setBasisStatus (objectives unknown): osresult objects falsely compare equal!");
            ok &= osresult2->setBasisStatus(i, ENUM_PROBLEM_COMPONENT_objectives, ENUM_BASIS_STATUS_unknown, intArray, 3);
            if (!ok) 
                throw ErrorClass("Error during setBasisStatus (objectives unknown)!");
            ok &= (osresult1->IsEqual(osresult2));
            if (!ok) 
                throw ErrorClass("setBasisStatus (objectives unknown): osresult objects falsely compare unequal!");

            ok &= osresult1->setNumberOfOtherObjectiveResults(i,3);
            if (!ok) 
                throw ErrorClass("Error during setNumberOfOtherObjectiveResults!");
            ok &= (!osresult1->IsEqual(osresult2));
            if (!ok) 
                throw ErrorClass("setNumberOfOtherObjectiveResults: osresult objects falsely compare equal!");
            ok &= osresult2->setNumberOfOtherObjectiveResults(i,3);
            if (!ok) 
                throw ErrorClass("Error during setNumberOfOtherObjectiveResults!");
            ok &= (osresult1->IsEqual(osresult2));
            if (!ok) 
                throw ErrorClass("setNumberOfOtherObjectiveResults: osresult objects falsely compare unequal!");

            for (int j=0; j < 2; ++j)
            {
                ok &= osresult1->setOtherObjectiveResultName(i,j,"other");
                if (!ok) 
                    throw ErrorClass("Error during setOtherObjectiveResultName!");
                ok &= (!osresult1->IsEqual(osresult2));
                if (!ok) 
                    throw ErrorClass("setOtherObjectiveResultName: osresult objects falsely compare equal!");
                ok &= osresult2->setOtherObjectiveResultName(i,j,"other");
                if (!ok) 
                    throw ErrorClass("Error during setOtherObjectiveResultName!");
                ok &= (osresult1->IsEqual(osresult2));
                if (!ok) 
                    throw ErrorClass("setOtherObjectiveResultName: osresult objects falsely compare unequal!");

                ok &= osresult1->setOtherObjectiveResultDescription(i,j,"other");
                if (!ok) 
                    throw ErrorClass("Error during setOtherObjectiveResultDescription!");
                ok &= (!osresult1->IsEqual(osresult2));
                if (!ok) 
                    throw ErrorClass("setOtherObjectiveResultDescription: osresult objects falsely compare equal!");
                ok &= osresult2->setOtherObjectiveResultDescription(i,j,"other");
                if (!ok) 
                    throw ErrorClass("Error during setOtherObjectiveResultDescription!");
                ok &= (osresult1->IsEqual(osresult2));
                if (!ok) 
                    throw ErrorClass("setOtherObjectiveResultDescription: osresult objects falsely compare unequal!");

                ok &= osresult1->setOtherObjectiveResultValue(i,j,"other");
                if (!ok) 
                    throw ErrorClass("Error during setOtherObjectiveResultValue!");
                ok &= (!osresult1->IsEqual(osresult2));
                if (!ok) 
                    throw ErrorClass("setOtherObjectiveResultValue: osresult objects falsely compare equal!");
                ok &= osresult2->setOtherObjectiveResultValue(i,j,"other");
                if (!ok) 
                    throw ErrorClass("Error during setOtherObjectiveResultValue!");
                ok &= (osresult1->IsEqual(osresult2));
                if (!ok) 
                    throw ErrorClass("setOtherObjectiveResultValue: osresult objects falsely compare unequal!");

                ok &= osresult1->setOtherObjectiveResultNumberOfObj(i,j,2);
                if (!ok) 
                    throw ErrorClass("Error during setOtherObjectiveResultNumberOfObj!");
                ok &= (!osresult1->IsEqual(osresult2));
                if (!ok) 
                    throw ErrorClass("setOtherObjectiveResultNumberOfObj: osresult objects falsely compare equal!");

                ok &= osresult2->setOtherObjectiveResultNumberOfObj(i,j,2);
                if (!ok) 
                    throw ErrorClass("Error during setOtherObjectiveResultNumberOfObj!");
                ok &= (osresult1->IsEqual(osresult2));
                if (!ok) 
                    throw ErrorClass("setOtherObjectiveResultNumberOfObj: osresult objects falsely compare unequal!");

                for (int k=0; k < 2; ++k)
                {
                    ok &= osresult1->setOtherObjectiveResultObjIdx(i,j,k,-2);
                    if (!ok) 
                        throw ErrorClass("Error during setOtherObjectiveResultObjIdx!");
                    ok &= (!osresult1->IsEqual(osresult2));
                    if (!ok) 
                        throw ErrorClass("setOtherObjectiveResultObjIdx: osresult objects falsely compare equal!");
                    ok &= osresult2->setOtherObjectiveResultObjIdx(i,j,k,-2);
                    if (!ok) 
                        throw ErrorClass("Error during setOtherObjectiveResultObjIdx!");
                    ok &= (osresult1->IsEqual(osresult2));
                    if (!ok) 
                        throw ErrorClass("setOtherObjectiveResultObjIdx: osresult objects falsely compare unequal!");

                    ok &= osresult1->setOtherObjectiveResultObj(i,j,k,"value");
                    if (!ok) 
                        throw ErrorClass("Error during setOtherObjectiveResultObj!");
                    ok &= (!osresult1->IsEqual(osresult2));
                    if (!ok) 
                        throw ErrorClass("setOtherObjectiveResultObj: osresult objects falsely compare equal!");
                    ok &= osresult2->setOtherObjectiveResultObj(i,j,k,"value");
                    if (!ok) 
                        throw ErrorClass("Error during setOtherObjectiveResultObj!");
                    ok &= (osresult1->IsEqual(osresult2));
                    if (!ok) 
                        throw ErrorClass("setOtherObjectiveResultObj: osresult objects falsely compare unequal!");
                }
            }
// The third <other> result uses enumerations

            ok &= osresult1->setOtherObjectiveResultName(i,2,"other");
            if (!ok) 
                throw ErrorClass("Error during setOtherObjectiveResultName!");
            ok &= (!osresult1->IsEqual(osresult2));
            if (!ok) 
                throw ErrorClass("setOtherObjectiveResultName: osresult objects falsely compare equal!");
            ok &= osresult2->setOtherObjectiveResultName(i,2,"other");
            if (!ok) 
                throw ErrorClass("Error during setOtherObjectiveResultName!");
            ok &= (osresult1->IsEqual(osresult2));
            if (!ok) 
                throw ErrorClass("setOtherObjectiveResultName: osresult objects falsely compare unequal!");

            ok &= osresult1->setOtherObjectiveResultDescription(i,2,"other");
            if (!ok) 
                throw ErrorClass("Error during setOtherObjectiveResultDescription!");
            ok &= (!osresult1->IsEqual(osresult2));
            if (!ok) 
                throw ErrorClass("setOtherObjectiveResultDescription: osresult objects falsely compare equal!");
            ok &= osresult2->setOtherObjectiveResultDescription(i,2,"other");
            if (!ok) 
                throw ErrorClass("Error during setOtherObjectiveResultDescription!");
            ok &= (osresult1->IsEqual(osresult2));
            if (!ok) 
                throw ErrorClass("setOtherObjectiveResultDescription: osresult objects falsely compare unequal!");

            ok &= osresult1->setOtherObjectiveResultValue(i,2,"other");
            if (!ok) 
                throw ErrorClass("Error during setOtherObjectiveResultValue!");
            ok &= (!osresult1->IsEqual(osresult2));
            if (!ok) 
                throw ErrorClass("setOtherObjectiveResultValue: osresult objects falsely compare equal!");
            ok &= osresult2->setOtherObjectiveResultValue(i,2,"other");
            if (!ok) 
                throw ErrorClass("Error during setOtherObjectiveResultValue!");
            ok &= (osresult1->IsEqual(osresult2));
            if (!ok) 
                throw ErrorClass("setOtherObjectiveResultValue: osresult objects falsely compare unequal!");

            ok &= osresult1->setOtherObjectiveResultNumberOfEnumerations(i,2,2);
            if (!ok) 
                throw ErrorClass("Error during setOtherObjectiveResultNumberOfEnumerations!");
            ok &= (!osresult1->IsEqual(osresult2));
            if (!ok) 
                throw ErrorClass("setOtherObjectiveResultNumberOfEnumerations: osresult objects falsely compare equal!");
            ok &= osresult2->setOtherObjectiveResultNumberOfEnumerations(i,2,2);
            if (!ok) 
                throw ErrorClass("Error during setOtherObjectiveResultNumberOfEnumerations!");
            ok &= (osresult1->IsEqual(osresult2));
            if (!ok) 
                throw ErrorClass("setOtherObjectiveResultNumberOfEnumerations: osresult objects falsely compare unequal!");

            for (int k=0; k < 2; ++k)
            {

            intArray[0] = -(1000*i + 1230 + 10*k + 1);
            intArray[1] = -(1000*i + 1230 + 10*k + 2);
            intArray[2] = -(1000*i + 1230 + 10*k + 3);

                ok &= osresult1->setOtherOptionEnumeration(i,2,ENUM_PROBLEM_COMPONENT_objectives,k,"value","description",intArray,3);
                if (!ok) 
                    throw ErrorClass("Error during setOtherOptionEnumeration (objective)!");
                ok &= (!osresult1->IsEqual(osresult2));
                if (!ok) 
                    throw ErrorClass("setOtherOptionEnumeration: osresult objects falsely compare equal!");
                ok &= osresult2->setOtherOptionEnumeration(i,2,ENUM_PROBLEM_COMPONENT_objectives,k,"value","description",intArray,3);
                if (!ok) 
                    throw ErrorClass("Error during setOtherOptionEnumeration (objective)!");
                ok &= (osresult1->IsEqual(osresult2));
                if (!ok) 
                    throw ErrorClass("setOtherOptionEnumeration: osresult objects falsely compare unequal!");
            }


            ok &= osresult1->setNumberOfDualValues(i,3);
            if (!ok) 
                throw ErrorClass("Error during setNumberOfDualValues!");
            ok &= (!osresult1->IsEqual(osresult2));
            if (!ok) 
                throw ErrorClass("setNumberOfDualValues: osresult objects falsely compare equal!");
            ok &= osresult2->setNumberOfDualValues(i,3);
            if (!ok) 
                throw ErrorClass("Error during setNumberOfDualValues!");
            ok &= (osresult1->IsEqual(osresult2));
            if (!ok) 
                throw ErrorClass("setNumberOfDualValues: osresult objects falsely compare unequal!");

            for (int j=0; j < 3; ++j)
            {
                ok &= osresult1->setDualValue(i,j,j,"conname",3.14);
                if (!ok) 
                    throw ErrorClass("Error during setDualValue!");
                ok &= (!osresult1->IsEqual(osresult2));
                if (!ok) 
                    throw ErrorClass("setDualValue: osresult objects falsely compare equal!");
                ok &= osresult2->setDualValue(i,j,j,"conname",3.14);
                if (!ok) 
                    throw ErrorClass("Error during setDualValue!");
                ok &= (osresult1->IsEqual(osresult2));
                if (!ok) 
                    throw ErrorClass("setDualValue: osresult objects falsely compare unequal!");
            }

            intArray[0] = 1000*i + 1300 + 10 + 1;
            intArray[1] = 1000*i + 1300 + 10 + 2;
            intArray[2] = 1000*i + 1300 + 10 + 3;

            ok &= osresult1->setBasisStatus(i, ENUM_PROBLEM_COMPONENT_constraints, ENUM_BASIS_STATUS_basic, intArray, 3);
            if (!ok) 
                throw ErrorClass("Error during setBasisStatus (constraints basic)!");
            ok &= (!osresult1->IsEqual(osresult2));
            if (!ok) 
                throw ErrorClass("setBasisStatus (constraints basic): osresult objects falsely compare equal!");
            ok &= osresult2->setBasisStatus(i, ENUM_PROBLEM_COMPONENT_constraints, ENUM_BASIS_STATUS_basic, intArray, 3);
            if (!ok) 
                throw ErrorClass("Error during setBasisStatus (constraints basic)!");
            ok &= (osresult1->IsEqual(osresult2));
            if (!ok) 
                throw ErrorClass("setBasisStatus (constraints basic): osresult objects falsely compare unequal!");

            intArray[0] = intArray[0] + 10;
            intArray[1] = intArray[1] + 10;
            intArray[2] = intArray[2] + 10;

            ok &= osresult1->setBasisStatus(i, ENUM_PROBLEM_COMPONENT_constraints, ENUM_BASIS_STATUS_atLower, intArray, 3);
            if (!ok) 
                throw ErrorClass("Error during setBasisStatus (constraints atLower)!");
            ok &= (!osresult1->IsEqual(osresult2));
            if (!ok) 
                throw ErrorClass("setBasisStatus (constraints atLower): osresult objects falsely compare equal!");
            ok &= osresult2->setBasisStatus(i, ENUM_PROBLEM_COMPONENT_constraints, ENUM_BASIS_STATUS_atLower, intArray, 3);
            if (!ok) 
                throw ErrorClass("Error during setBasisStatus (constraints atLower)!");
            ok &= (osresult1->IsEqual(osresult2));
            if (!ok) 
                throw ErrorClass("setBasisStatus (constraints atLower): osresult objects falsely compare unequal!");

            intArray[0] = intArray[0] + 10;
            intArray[1] = intArray[1] + 10;
            intArray[2] = intArray[2] + 10;


            ok &= osresult1->setBasisStatus(i, ENUM_PROBLEM_COMPONENT_constraints, ENUM_BASIS_STATUS_atUpper, intArray, 3);
            if (!ok) 
                throw ErrorClass("Error during setBasisStatus (constraints atUpper)!");
            ok &= (!osresult1->IsEqual(osresult2));
            if (!ok) 
                throw ErrorClass("setBasisStatus (constraints atUpper): osresult objects falsely compare equal!");
            ok &= osresult2->setBasisStatus(i, ENUM_PROBLEM_COMPONENT_constraints, ENUM_BASIS_STATUS_atUpper, intArray, 3);
            if (!ok) 
                throw ErrorClass("Error during setBasisStatus (constraints atUpper)!");
            ok &= (osresult1->IsEqual(osresult2));
            if (!ok) 
                throw ErrorClass("setBasisStatus (constraints atUpper): osresult objects falsely compare unequal!");

            intArray[0] = intArray[0] + 10;
            intArray[1] = intArray[1] + 10;
            intArray[2] = intArray[2] + 10;


            ok &= osresult1->setBasisStatus(i, ENUM_PROBLEM_COMPONENT_constraints, ENUM_BASIS_STATUS_atEquality, intArray, 3);
            if (!ok) 
                throw ErrorClass("Error during setBasisStatus (constraints atEquality)!");
            ok &= (!osresult1->IsEqual(osresult2));
            if (!ok) 
                throw ErrorClass("setBasisStatus (constraints atEquality): osresult objects falsely compare equal!");
            ok &= osresult2->setBasisStatus(i, ENUM_PROBLEM_COMPONENT_constraints, ENUM_BASIS_STATUS_atEquality, intArray, 3);
            if (!ok) 
                throw ErrorClass("Error during setBasisStatus (constraints atEquality)!");
            ok &= (osresult1->IsEqual(osresult2));
            if (!ok) 
                throw ErrorClass("setBasisStatus (constraints atEquality): osresult objects falsely compare unequal!");


            intArray[0] = intArray[0] + 10;
            intArray[1] = intArray[1] + 10;
            intArray[2] = intArray[2] + 10;

            ok &= osresult1->setBasisStatus(i, ENUM_PROBLEM_COMPONENT_constraints, ENUM_BASIS_STATUS_isFree, intArray, 3);
            if (!ok) 
                throw ErrorClass("Error during setBasisStatus (constraints isFree)!");
            ok &= (!osresult1->IsEqual(osresult2));
            if (!ok) 
                throw ErrorClass("setBasisStatus (constraints isFree): osresult objects falsely compare equal!");
            ok &= osresult2->setBasisStatus(i, ENUM_PROBLEM_COMPONENT_constraints, ENUM_BASIS_STATUS_isFree, intArray, 3);
            if (!ok) 
                throw ErrorClass("Error during setBasisStatus (constraints isFree)!");
            ok &= (osresult1->IsEqual(osresult2));
            if (!ok) 
                throw ErrorClass("setBasisStatus (constraints isFree): osresult objects falsely compare unequal!");


            intArray[0] = intArray[0] + 10;
            intArray[1] = intArray[1] + 10;
            intArray[2] = intArray[2] + 10;

            ok &= osresult1->setBasisStatus(i, ENUM_PROBLEM_COMPONENT_constraints, ENUM_BASIS_STATUS_superbasic, intArray, 3);
            if (!ok) 
                throw ErrorClass("Error during setBasisStatus (constraints superbasic)!");
            ok &= (!osresult1->IsEqual(osresult2));
            if (!ok) 
                throw ErrorClass("setBasisStatus (constraints superbasic): osresult objects falsely compare equal!");
            ok &= osresult2->setBasisStatus(i, ENUM_PROBLEM_COMPONENT_constraints, ENUM_BASIS_STATUS_superbasic, intArray, 3);
            if (!ok) 
                throw ErrorClass("Error during setBasisStatus (constraints superbasic)!");
            ok &= (osresult1->IsEqual(osresult2));
            if (!ok) 
                throw ErrorClass("setBasisStatus (constraints superbasic): osresult objects falsely compare unequal!");

            intArray[0] = intArray[0] + 10;
            intArray[1] = intArray[1] + 10;
            intArray[2] = intArray[2] + 10;


            ok &= osresult1->setBasisStatus(i, ENUM_PROBLEM_COMPONENT_constraints, ENUM_BASIS_STATUS_unknown, intArray, 3);
            if (!ok) 
                throw ErrorClass("Error during setBasisStatus (constraints unknown)!");
            ok &= (!osresult1->IsEqual(osresult2));
            if (!ok) 
                throw ErrorClass("setBasisStatus (constraints unknown): osresult objects falsely compare equal!");
            ok &= osresult2->setBasisStatus(i, ENUM_PROBLEM_COMPONENT_constraints, ENUM_BASIS_STATUS_unknown, intArray, 3);
            if (!ok) 
                throw ErrorClass("Error during setBasisStatus (constraints unknown)!");
            ok &= (osresult1->IsEqual(osresult2));
            if (!ok) 
                throw ErrorClass("setBasisStatus (constraints unknown): osresult objects falsely compare unequal!");

            ok &= osresult1->setNumberOfOtherConstraintResults(i,3);
            if (!ok) 
                throw ErrorClass("Error during setNumberOfOtherConstraintResults!");
            ok &= (!osresult1->IsEqual(osresult2));
            if (!ok) 
                throw ErrorClass("setNumberOfOtherConstraintResults: osresult objects falsely compare equal!");
            ok &= osresult2->setNumberOfOtherConstraintResults(i,3);
            if (!ok) 
                throw ErrorClass("Error during setNumberOfOtherConstraintResults!");
            ok &= (osresult1->IsEqual(osresult2));
            if (!ok) 
                throw ErrorClass("setNumberOfOtherConstraintResults: osresult objects falsely compare unequal!");

            for (int j=0; j < 2; ++j)
            {
                ok &= osresult1->setOtherConstraintResultName(i,j,"other");
                if (!ok) 
                    throw ErrorClass("Error during setOtherConstraintResultName!");
                ok &= (!osresult1->IsEqual(osresult2));
                if (!ok) 
                    throw ErrorClass("setOtherConstraintResultName: osresult objects falsely compare equal!");
                ok &= osresult2->setOtherConstraintResultName(i,j,"other");
                if (!ok) 
                    throw ErrorClass("Error during setOtherConstraintResultName!");
                ok &= (osresult1->IsEqual(osresult2));
                if (!ok) 
                    throw ErrorClass("setOtherConstraintResultName: osresult objects falsely compare unequal!");

                ok &= osresult1->setOtherConstraintResultDescription(i,j,"other");
                if (!ok) 
                    throw ErrorClass("Error during setOtherConstraintResultDescription!");
                ok &= (!osresult1->IsEqual(osresult2));
                if (!ok) 
                    throw ErrorClass("setOtherConstraintResultDescription: osresult objects falsely compare equal!");
                ok &= osresult2->setOtherConstraintResultDescription(i,j,"other");
                if (!ok) 
                    throw ErrorClass("Error during setOtherConstraintResultDescription!");
                ok &= (osresult1->IsEqual(osresult2));
                if (!ok) 
                    throw ErrorClass("setOtherConstraintResultDescription: osresult objects falsely compare unequal!");

                ok &= osresult1->setOtherConstraintResultValue(i,j,"other");
                if (!ok) 
                    throw ErrorClass("Error during setOtherConstraintResultValue!");
                ok &= (!osresult1->IsEqual(osresult2));
                if (!ok) 
                    throw ErrorClass("setOtherConstraintResultValue: osresult objects falsely compare equal!");
                ok &= osresult2->setOtherConstraintResultValue(i,j,"other");
                if (!ok) 
                    throw ErrorClass("Error during setOtherConstraintResultValue!");
                ok &= (osresult1->IsEqual(osresult2));
                if (!ok) 
                    throw ErrorClass("setOtherConstraintResultValue: osresult objects falsely compare unequal!");

                ok &= osresult1->setOtherConstraintResultNumberOfCon(i,j,3);
                if (!ok) 
                    throw ErrorClass("Error during setOtherConstraintResultNumberOfCon!");
                ok &= (!osresult1->IsEqual(osresult2));
                if (!ok) 
                    throw ErrorClass("setOtherConstraintResultNumberOfCon: osresult objects falsely compare equal!");
                ok &= osresult2->setOtherConstraintResultNumberOfCon(i,j,3);
                if (!ok) 
                    throw ErrorClass("Error during setOtherConstraintResultNumberOfCon!");
                ok &= (osresult1->IsEqual(osresult2));
                if (!ok) 
                    throw ErrorClass("setOtherConstraintResultNumberOfCon: osresult objects falsely compare unequal!");

                for (int k=0; k < 3; ++k)
                {
                    ok &= osresult1->setOtherConstraintResultConIdx(i,j,k,k);
                    if (!ok) 
                        throw ErrorClass("Error during setOtherConstraintResultConIdx!");
                    ok &= (!osresult1->IsEqual(osresult2));
                    if (!ok) 
                        throw ErrorClass("setOtherConstraintResultConIdx: osresult objects falsely compare equal!");
                    ok &= osresult2->setOtherConstraintResultConIdx(i,j,k,k);
                    if (!ok) 
                        throw ErrorClass("Error during setOtherConstraintResultConIdx!");
                    ok &= (osresult1->IsEqual(osresult2));
                    if (!ok) 
                        throw ErrorClass("setOtherConstraintResultConIdx: osresult objects falsely compare unequal!");

                    ok &= osresult1->setOtherConstraintResultCon(i,j,k,"value");
                    if (!ok) 
                        throw ErrorClass("Error during setOtherConstraintResultCon!");
                    ok &= (!osresult1->IsEqual(osresult2));
                    if (!ok) 
                        throw ErrorClass("setOtherConstraintResultCon: osresult objects falsely compare equal!");
                    ok &= osresult2->setOtherConstraintResultCon(i,j,k,"value");
                    if (!ok) 
                        throw ErrorClass("Error during setOtherConstraintResultCon!");
                    ok &= (osresult1->IsEqual(osresult2));
                    if (!ok) 
                        throw ErrorClass("setOtherConstraintResultCon: osresult objects falsely compare unequal!");
                }
            }


// The third <other> result uses enumerations

            ok &= osresult1->setOtherConstraintResultName(i,2,"other");
            if (!ok) 
                throw ErrorClass("Error during setOtherConstraintResultName!");
            ok &= (!osresult1->IsEqual(osresult2));
            if (!ok) 
                throw ErrorClass("setOtherConstraintResultName: osresult objects falsely compare equal!");
            ok &= osresult2->setOtherConstraintResultName(i,2,"other");
            if (!ok) 
                throw ErrorClass("Error during setOtherConstraintResultName!");
            ok &= (osresult1->IsEqual(osresult2));
            if (!ok) 
                throw ErrorClass("setOtherConstraintResultName: osresult objects falsely compare unequal!");

            ok &= osresult1->setOtherConstraintResultDescription(i,2,"other");
            if (!ok) 
                throw ErrorClass("Error during setOtherConstraintResultDescription!");
            ok &= (!osresult1->IsEqual(osresult2));
            if (!ok) 
                throw ErrorClass("setOtherConstraintResultDescription: osresult objects falsely compare equal!");
            ok &= osresult2->setOtherConstraintResultDescription(i,2,"other");
            if (!ok) 
                throw ErrorClass("Error during setOtherConstraintResultDescription!");
            ok &= (osresult1->IsEqual(osresult2));
            if (!ok) 
                throw ErrorClass("setOtherConstraintResultDescription: osresult objects falsely compare unequal!");

            ok &= osresult1->setOtherConstraintResultValue(i,2,"other");
            if (!ok) 
                throw ErrorClass("Error during setOtherConstraintResultValue!");
            ok &= (!osresult1->IsEqual(osresult2));
            if (!ok) 
                throw ErrorClass("setOtherConstraintResultValue: osresult objects falsely compare equal!");
            ok &= osresult2->setOtherConstraintResultValue(i,2,"other");
            if (!ok) 
                throw ErrorClass("Error during setOtherConstraintResultValue!");
            ok &= (osresult1->IsEqual(osresult2));
            if (!ok) 
                throw ErrorClass("setOtherConstraintResultValue: osresult objects falsely compare unequal!");

            ok &= osresult1->setOtherConstraintResultNumberOfEnumerations(i,2,2);
            if (!ok) 
                throw ErrorClass("Error during setOtherConstraintResultNumberOfEnumerations!");
            ok &= (!osresult1->IsEqual(osresult2));
            if (!ok) 
                throw ErrorClass("setOtherConstraintResultNumberOfEnumerations: osresult objects falsely compare equal!");
            ok &= osresult2->setOtherConstraintResultNumberOfEnumerations(i,2,2);
            if (!ok) 
                throw ErrorClass("Error during setOtherConstraintResultNumberOfEnumerations!");
            ok &= (osresult1->IsEqual(osresult2));
            if (!ok) 
                throw ErrorClass("setOtherConstraintResultNumberOfEnumerations: osresult objects falsely compare unequal!");

            for (int k=0; k < 2; ++k)
            {
            intArray[0] = 1000*i + 1330 + 10*k + 1;
            intArray[1] = 1000*i + 1330 + 10*k + 2;
            intArray[2] = 1000*i + 1330 + 10*k + 3;

                ok &= osresult1->setOtherOptionEnumeration(i,2,ENUM_PROBLEM_COMPONENT_constraints,k,"value","description",intArray,3);
                if (!ok) 
                    throw ErrorClass("Error during setOtherOptionEnumeration (constraint)!");
                ok &= (!osresult1->IsEqual(osresult2));
                if (!ok) 
                    throw ErrorClass("setOtherOptionEnumeration: osresult objects falsely compare equal!");
                ok &= osresult2->setOtherOptionEnumeration(i,2,ENUM_PROBLEM_COMPONENT_constraints,k,"value","description",intArray,3);
                if (!ok) 
                    throw ErrorClass("Error during setOtherOptionEnumeration (constraint)!");
                ok &= (osresult1->IsEqual(osresult2));
                if (!ok) 
                    throw ErrorClass("setOtherOptionEnumeration: osresult objects falsely compare unequal!");
            }


            ok &= osresult1->setNumberOfOtherSolutionResults(i,3);
            if (!ok) 
                throw ErrorClass("Error during setNumberOfOtherSolutionResults!");
            ok &= (!osresult1->IsEqual(osresult2));
            if (!ok) 
                throw ErrorClass("setNumberOfOtherSolutionResults: osresult objects falsely compare equal!");
            ok &= osresult2->setNumberOfOtherSolutionResults(i,3);
            if (!ok) 
                throw ErrorClass("Error during setNumberOfOtherSolutionResults!");
            ok &= (osresult1->IsEqual(osresult2));
            if (!ok) 
                throw ErrorClass("setNumberOfOtherSolutionResults: osresult objects falsely compare unequal!");

            for (int j=0; j < 3; ++j)
            {
                ok &= osresult1->setOtherSolutionResultName(i,j,"other");
                if (!ok) 
                    throw ErrorClass("Error during setOtherSolutionResultName!");
                ok &= (!osresult1->IsEqual(osresult2));
                if (!ok) 
                    throw ErrorClass("setOtherSolutionResultName: osresult objects falsely compare equal!");
                ok &= osresult2->setOtherSolutionResultName(i,j,"other");
                if (!ok) 
                    throw ErrorClass("Error during setOtherSolutionResultName!");
                ok &= (osresult1->IsEqual(osresult2));
                if (!ok) 
                    throw ErrorClass("setOtherSolutionResultName: osresult objects falsely compare unequal!");

                ok &= osresult1->setOtherSolutionResultCategory(i,j,"other");
                if (!ok) 
                    throw ErrorClass("Error during setOtherSolutionResultCategory!");
                ok &= (!osresult1->IsEqual(osresult2));
                if (!ok) 
                    throw ErrorClass("setOtherSolutionResultCategory: osresult objects falsely compare equal!");
                ok &= osresult2->setOtherSolutionResultCategory(i,j,"other");
                if (!ok) 
                    throw ErrorClass("Error during setOtherSolutionResultCategory!");
                ok &= (osresult1->IsEqual(osresult2));
                if (!ok) 
                    throw ErrorClass("setOtherSolutionResultCategory: osresult objects falsely compare unequal!");

                ok &= osresult1->setOtherSolutionResultDescription(i,j,"other");
                if (!ok) 
                    throw ErrorClass("Error during setOtherSolutionResultDescription!");
                ok &= (!osresult1->IsEqual(osresult2));
                if (!ok) 
                    throw ErrorClass("setOtherSolutionResultDescription: osresult objects falsely compare equal!");
                ok &= osresult2->setOtherSolutionResultDescription(i,j,"other");
                if (!ok) 
                    throw ErrorClass("Error during setOtherSolutionResultDescription!");
                ok &= (osresult1->IsEqual(osresult2));
                if (!ok) 
                    throw ErrorClass("setOtherSolutionResultDescription: osresult objects falsely compare unequal!");

                ok &= osresult1->setOtherSolutionResultNumberOfItems(i,j,3);
                if (!ok) 
                    throw ErrorClass("Error during setOtherSolutionResultNumberOfItems!");
                ok &= (!osresult1->IsEqual(osresult2));
                if (!ok) 
                    throw ErrorClass("setOtherSolutionResultNumberOfItems: osresult objects falsely compare equal!");
                ok &= osresult2->setOtherSolutionResultNumberOfItems(i,j,3);
                if (!ok) 
                    throw ErrorClass("Error during setOtherSolutionResultNumberOfItems!");
                ok &= (osresult1->IsEqual(osresult2));
                if (!ok) 
                    throw ErrorClass("setOtherSolutionResultNumberOfItems: osresult objects falsely compare unequal!");

                for (int k=0; k < 3; ++k)
                {
                    ok &= osresult1->setOtherSolutionResultItem(i,j,k,"blabla");
                    if (!ok) 
                        throw ErrorClass("Error during setOtherSolutionResultItem!");
                    ok &= (!osresult1->IsEqual(osresult2));
                    if (!ok) 
                        throw ErrorClass("setOtherSolutionResultItem: osresult objects falsely compare equal!");
                    ok &= osresult2->setOtherSolutionResultItem(i,j,k,"blabla");
                    if (!ok) 
                        throw ErrorClass("Error during setOtherSolutionResultItem!");
                    ok &= (osresult1->IsEqual(osresult2));
                    if (!ok) 
                        throw ErrorClass("setOtherSolutionResultItem: osresult objects falsely compare unequal!");
                }
            }
        }

        ok &= osresult1->setNumberOfSolverOutputs(3);
        if (!ok) 
            throw ErrorClass("Error during setNumberOfSolverOutputs!");
        ok &= (!osresult1->IsEqual(osresult2));
        if (!ok) 
            throw ErrorClass("setNumberOfSolverOutputs: osresult objects falsely compare equal!");
        ok &= osresult2->setNumberOfSolverOutputs(3);
        if (!ok) 
            throw ErrorClass("Error during setNumberOfSolverOutputs!");
        ok &= (osresult1->IsEqual(osresult2));
        if (!ok) 
            throw ErrorClass("setNumberOfSolverOutputs: osresult objects falsely compare unequal!");

        for (int i=0; i < 3; ++i)
        {
            ok &= osresult1->setSolverOutputName(i,"some name");
            if (!ok) 
                throw ErrorClass("Error during setSolverOutputName!");
            ok &= (!osresult1->IsEqual(osresult2));
            if (!ok) 
                throw ErrorClass("setSolverOutputName: osresult objects falsely compare equal!");
            ok &= osresult2->setSolverOutputName(i,"some name");
            if (!ok) 
                throw ErrorClass("Error during setSolverOutputName!");
            ok &= (osresult1->IsEqual(osresult2));
            if (!ok) 
                throw ErrorClass("setSolverOutputName: osresult objects falsely compare unequal!");

            ok &= osresult1->setSolverOutputCategory(i,"some name");
            if (!ok) 
                throw ErrorClass("Error during setSolverOutputCategory!");
            ok &= (!osresult1->IsEqual(osresult2));
            if (!ok) 
                throw ErrorClass("setSolverOutputCategory: osresult objects falsely compare equal!");
            ok &= osresult2->setSolverOutputCategory(i,"some name");
            if (!ok) 
                throw ErrorClass("Error during setSolverOutputCategory!");
            ok &= (osresult1->IsEqual(osresult2));
            if (!ok) 
                throw ErrorClass("setSolverOutputCategory: osresult objects falsely compare unequal!");

            ok &= osresult1->setSolverOutputDescription(i,"some name");
            if (!ok) 
                throw ErrorClass("Error during setSolverOutputDescription!");
            ok &= (!osresult1->IsEqual(osresult2));
            if (!ok) 
                throw ErrorClass("setSolverOutputDescription: osresult objects falsely compare equal!");
            ok &= osresult2->setSolverOutputDescription(i,"some name");
            if (!ok) 
                throw ErrorClass("Error during setSolverOutputDescription!");
            ok &= (osresult1->IsEqual(osresult2));
            if (!ok) 
                throw ErrorClass("setSolverOutputDescription: osresult objects falsely compare unequal!");

            ok &= osresult1->setSolverOutputNumberOfItems(i,3);
            if (!ok) 
                throw ErrorClass("Error during setSolverOutputNumberOfItems!");
            ok &= (!osresult1->IsEqual(osresult2));
            if (!ok) 
                throw ErrorClass("setSolverOutputNumberOfItems: osresult objects falsely compare equal!");
            ok &= osresult2->setSolverOutputNumberOfItems(i,3);
            if (!ok) 
                throw ErrorClass("Error during setSolverOutputNumberOfItems!");
            ok &= (osresult1->IsEqual(osresult2));
            if (!ok) 
                throw ErrorClass("setSolverOutputNumberOfItems: osresult objects falsely compare unequal!");

            for (int j=0; j < 3; ++j)
            {
                ok &= osresult1->setSolverOutputItem(i,j,"other");
                if (!ok) 
                    throw ErrorClass("Error during setSolverOutputItem!");
                ok &= (!osresult1->IsEqual(osresult2));
                if (!ok) 
                    throw ErrorClass("setSolverOutputItem: osresult objects falsely compare equal!");
                ok &= osresult2->setSolverOutputItem(i,j,"other");
                if (!ok) 
                    throw ErrorClass("Error during setSolverOutputItem!");
                ok &= (osresult1->IsEqual(osresult2));
                if (!ok) 
                    throw ErrorClass("setSolverOutputItem: osresult objects falsely compare unequal!");
            }
        }

        if (!ok)
            throw ErrorClass("Unspecified error while testing set() methods");

        unitTestResult << "TEST " << nOfTest << ": Successful test of OSrL set() tools" << std::endl;
        cout << endl << "TEST " << nOfTest << ": Completed successfully" << endl << endl;

        cout << endl << "TEST " << ++nOfTest << ": OSrLWriter and OSrLReader " << endl << endl;


        osrlwriter = new OSrLWriter();
        osrlreader = new OSrLReader();
        std::string tempOSrL;

        tempOSrL = osrlwriter->writeOSrL( osresult1);

        std::cout << "Here is the temporary OSrL string produced from OSrLWriter" << std::endl << tempOSrL << std::endl;

        osresult3 = osrlreader->readOSrL( tempOSrL);

        tempOSrL = osrlwriter->writeOSrL( osresult3);

        std::cout << "Here is the temporary OSrL string produced from OSrLReader" << std::endl << tempOSrL << std::endl;


        ok &= (osresult1->IsEqual(osresult3));
        if (!ok) 
            throw ErrorClass("Writing an osresult then reading leads to loss of data");

        unitTestResult << "TEST " << nOfTest << ": Successful test of OSrLWriter and OSrLReader" << std::endl;
        cout << endl << "TEST " << nOfTest << ": Completed successfully" << endl << endl;

/** The second test verifies the get() methods.
 *  The OSResult object just created is duplicated using get() and set() methods.
 *  At the end, the duplicated object is compared to the original. 
 *  The test requires both to be equal.
 */
        cout << endl << "TEST " << ++nOfTest << ": OSrL get() methods" << endl << endl;
//#ifdef TEMP   //---------------------------for the time being----------------------------------

        if (osresult2  != NULL) delete osresult2;
        osresult2 = new OSResult();

        std::string tempStr;
        double tempDbl;
        int tempInt;

        tempStr = osresult1->getGeneralStatusType();
        ok &= osresult2->setGeneralStatusType(tempStr);
        if (!ok) 
            throw ErrorClass("Error during setGeneralStatusType!");
        tempStr = osresult1->getGeneralStatusDescription();
        ok &= osresult2->setGeneralStatusDescription(tempStr);
        if (!ok) 
            throw ErrorClass("Error during setGeneralStatusDescription!");

        tempInt = osresult1->getNumberOfGeneralSubstatuses();
        ok &= osresult2->setNumberOfGeneralSubstatuses(tempInt);
        if (!ok) 
            throw ErrorClass("Error during setNumberOfGeneralSubstatuses!");
        for (int i=0; i < tempInt; i++)
        {
            tempStr = osresult1->getGeneralSubstatusName(i);
            ok &= osresult2->setGeneralSubstatusName(i,tempStr);
            if (!ok) 
                throw ErrorClass("Error during setGeneralSubstatusName!");
            tempStr = osresult1->getGeneralSubstatusDescription(i);
            ok &= osresult2->setGeneralSubstatusDescription(i,tempStr);
            if (!ok) 
                throw ErrorClass("Error during setGeneralSubstatusDescription!");
        }

        tempStr = osresult1->getGeneralMessage();
        ok &= osresult2->setGeneralMessage(tempStr);
        if (!ok) 
            throw ErrorClass("Error during setGeneralMessage!");
        tempStr = osresult1->getServiceURI();
        ok &= osresult2->setServiceURI(tempStr);
        if (!ok) 
            throw ErrorClass("Error during setServiceURI!");
        tempStr = osresult1->getServiceName();
        ok &= osresult2->setServiceName(tempStr);
        if (!ok) 
            throw ErrorClass("Error during setServiceName!");
        tempStr = osresult1->getInstanceName();
        ok &= osresult2->setInstanceName(tempStr);
        if (!ok) 
            throw ErrorClass("Error during setInstanceName!");
        tempStr = osresult1->getJobID();
        ok &= osresult2->setJobID(tempStr);
        if (!ok) 
            throw ErrorClass("Error during setJobID!");
        tempStr = osresult1->getSolverInvoked();
        ok &= osresult2->setSolverInvoked(tempStr);
        if (!ok) 
            throw ErrorClass("Error during setSolverInvoked!");
        tempStr = osresult1->getTimeStamp();
        ok &= osresult2->setTimeStamp(tempStr);
        if (!ok) 
            throw ErrorClass("Error during setTimeStamp!");

        tempInt = osresult1->getNumberOfOtherGeneralResults();
        ok &= osresult2->setNumberOfOtherGeneralResults(tempInt);
        if (!ok) 
            throw ErrorClass("Error during setNumberOfOtherGeneralResults!");
        for (int i=0; i < tempInt; i++)
        {
            tempStr = osresult1->getOtherGeneralResultName(i);
            ok &= osresult2->setOtherGeneralResultName(i,tempStr);
            if (!ok) 
                throw ErrorClass("Error during setOtherGeneralResultName!");
            tempStr = osresult1->getOtherGeneralResultValue(i);
            ok &= osresult2->setOtherGeneralResultValue(i,tempStr);
            if (!ok) 
                throw ErrorClass("Error during setOtherGeneralResultValue!");
            tempStr = osresult1->getOtherGeneralResultDescription(i);
            ok &= osresult2->setOtherGeneralResultDescription(i,tempStr);
            if (!ok) 
                throw ErrorClass("Error during setOtherGeneralResultDescription!");
        }

        tempStr = osresult1->getSystemInformation();
        ok &= osresult2->setSystemInformation(tempStr);
        if (!ok) 
            throw ErrorClass("Error during setSystemInformation!");
        tempStr = osresult1->getAvailableDiskSpaceUnit();
        ok &= osresult2->setAvailableDiskSpaceUnit(tempStr);
        if (!ok) 
            throw ErrorClass("Error during setAvailableDiskSpaceUnit!");
        tempStr = osresult1->getAvailableDiskSpaceDescription();
        ok &= osresult2->setAvailableDiskSpaceDescription(tempStr);
        if (!ok) 
            throw ErrorClass("Error during setAvailableDiskSpaceDescription!");
        tempDbl = osresult1->getAvailableDiskSpaceValue();
        ok &= osresult2->setAvailableDiskSpaceValue(tempDbl);
        if (!ok) 
            throw ErrorClass("Error during setAvailableDiskSpaceValue!");
        tempStr = osresult1->getAvailableMemoryUnit();
        ok &= osresult2->setAvailableMemoryUnit(tempStr);
        if (!ok) 
            throw ErrorClass("Error during setAvailableMemoryUnit!");
        tempStr = osresult1->getAvailableMemoryDescription();
        ok &= osresult2->setAvailableMemoryDescription(tempStr);
        if (!ok) 
            throw ErrorClass("Error during setAvailableMemoryDescription!");
        tempDbl = osresult1->getAvailableMemoryValue();
        ok &= osresult2->setAvailableMemoryValue(tempDbl);
        if (!ok) 
            throw ErrorClass("Error during setAvailableMemoryValue!");
        tempStr = osresult1->getAvailableCPUSpeedUnit();
        ok &= osresult2->setAvailableCPUSpeedUnit(tempStr);
        if (!ok) 
            throw ErrorClass("Error during setAvailableCPUSpeedUnit!");
        tempStr = osresult1->getAvailableCPUSpeedDescription();
        ok &= osresult2->setAvailableCPUSpeedDescription(tempStr);
        if (!ok) 
            throw ErrorClass("Error during setAvailableCPUSpeedDescription!");
        tempDbl = osresult1->getAvailableCPUSpeedValue();
        ok &= osresult2->setAvailableCPUSpeedValue(tempDbl);
        if (!ok) 
            throw ErrorClass("Error during setAvailableCPUSpeedValue!");
        tempStr = osresult1->getAvailableCPUNumberDescription();
        ok &= osresult2->setAvailableCPUNumberDescription(tempStr);
        if (!ok) 
            throw ErrorClass("Error during setAvailableCPUNumberDescription!");
        tempInt = osresult1->getAvailableCPUNumberValue();
        ok &= osresult2->setAvailableCPUNumberValue(tempInt);
        if (!ok) 
            throw ErrorClass("Error during setAvailableCPUNumberValue!");

        tempInt = osresult1->getNumberOfOtherSystemResults();
        ok &= osresult2->setNumberOfOtherSystemResults(tempInt);
        if (!ok) 
            throw ErrorClass("Error during setNumberOfOtherSystemResults!");
        for (int i=0; i < tempInt; i++)
        {
            tempStr = osresult1->getOtherSystemResultName(i);
            ok &= osresult2->setOtherSystemResultName(i,tempStr);
            if (!ok) 
                throw ErrorClass("Error during setOtherSystemResultName!");
            tempStr = osresult1->getOtherSystemResultValue(i);
            ok &= osresult2->setOtherSystemResultValue(i,tempStr);
            if (!ok) 
                throw ErrorClass("Error during setOtherSystemResultValue!");
            tempStr = osresult1->getOtherSystemResultDescription(i);
            ok &= osresult2->setOtherSystemResultDescription(i,tempStr);
            if (!ok) 
                throw ErrorClass("Error during setOtherSystemResultDescription!");
        }

        tempStr = osresult1->getCurrentState();
        ok &= osresult2->setCurrentState(tempStr);
        if (!ok) 
            throw ErrorClass("Error during setCurrentState!");
        tempInt = osresult1->getCurrentJobCount();
        ok &= osresult2->setCurrentJobCount(tempInt);
        if (!ok) 
            throw ErrorClass("Error during setCurrentJobCount!");
        tempInt = osresult1->getTotalJobsSoFar();
        ok &= osresult2->setTotalJobsSoFar(tempInt);
        if (!ok) 
            throw ErrorClass("Error during setTotalJobsSoFar!");
        tempStr = osresult1->getTimeServiceStarted();
        ok &= osresult2->setTimeServiceStarted(tempStr);
        if (!ok) 
            throw ErrorClass("Error during setTimeServiceStarted!");
        tempDbl = osresult1->getServiceUtilization();
        ok &= osresult2->setServiceUtilization(tempDbl);
        if (!ok) 
            throw ErrorClass("Error during setServiceUtilization!");

        tempInt = osresult1->getNumberOfOtherServiceResults();
        ok &= osresult2->setNumberOfOtherServiceResults(tempInt);
        if (!ok) 
            throw ErrorClass("Error during setNumberOfOtherServiceResults!");
        for (int i=0; i < tempInt; i++)
        {
            tempStr = osresult1->getOtherServiceResultName(i);
            ok &= osresult2->setOtherServiceResultName(i,tempStr);
            if (!ok) 
                throw ErrorClass("Error during setOtherServiceResultName!");
            tempStr = osresult1->getOtherServiceResultValue(i);
            ok &= osresult2->setOtherServiceResultValue(i,tempStr);
            if (!ok) 
                throw ErrorClass("Error during setOtherServiceResultValue!");
            tempStr = osresult1->getOtherServiceResultDescription(i);
            ok &= osresult2->setOtherServiceResultDescription(i,tempStr);
            if (!ok) 
                throw ErrorClass("Error during setOtherServiceResultDescription!");
        }

        tempStr = osresult1->getJobStatus();
        ok &= osresult2->setJobStatus(tempStr);
        if (!ok) 
            throw ErrorClass("Error during setJobStatus!");
        tempStr = osresult1->getJobSubmitTime();
        ok &= osresult2->setJobSubmitTime(tempStr);
        if (!ok) 
            throw ErrorClass("Error during setJobSubmitTime!");
        tempStr = osresult1->getScheduledStartTime();
        ok &= osresult2->setScheduledStartTime(tempStr);
        if (!ok) 
            throw ErrorClass("Error during setScheduledStartTime!");
        tempStr = osresult1->getActualStartTime();
        ok &= osresult2->setActualStartTime(tempStr);
        if (!ok) 
            throw ErrorClass("Error during setActualStartTime!");
        tempStr = osresult1->getJobEndTime();
        ok &= osresult2->setJobEndTime(tempStr);
        if (!ok) 
            throw ErrorClass("Error during setJobEndTime!");

        tempInt = osresult1->getNumberOfTimes();
        ok &= osresult2->setNumberOfTimes(tempInt);
        if (!ok) 
            throw ErrorClass("Error during setNumberOfTimes!");
        for (int i=0; i < tempInt; i++)
        {
            string tempStr1,tempStr2,tempStr3,tempStr4;
            tempStr1 = osresult1->getTimingInfoType(i);
            tempStr2 = osresult1->getTimingInfoCategory(i);
            tempStr3 = osresult1->getTimingInfoUnit(i);
            tempStr4 = osresult1->getTimingInfoDescription(i);
            tempDbl  = osresult1->getTimingInfoValue(i);
            ok &= osresult2->setTimingInformation(i,tempStr1,tempStr2,tempStr3,tempStr4,tempDbl);
            if (!ok) 
                throw ErrorClass("Error during setTimingInformation!");
        }

        tempStr = osresult1->getUsedDiskSpaceUnit();
        ok &= osresult2->setUsedDiskSpaceUnit(tempStr);
        if (!ok) 
            throw ErrorClass("Error during setUsedDiskSpaceUnit!");
        tempStr = osresult1->getUsedDiskSpaceDescription();
        ok &= osresult2->setUsedDiskSpaceDescription(tempStr);
        if (!ok) 
            throw ErrorClass("Error during setUsedDiskSpaceDescription!");
        tempDbl = osresult1->getUsedDiskSpaceValue();
        ok &= osresult2->setUsedDiskSpaceValue(tempDbl);
        if (!ok) 
            throw ErrorClass("Error during setUsedDiskSpaceValue!");
        tempStr = osresult1->getUsedMemoryUnit();
        ok &= osresult2->setUsedMemoryUnit(tempStr);
        if (!ok) 
            throw ErrorClass("Error during setUsedMemoryUnit!");
        tempStr = osresult1->getUsedMemoryDescription();
        ok &= osresult2->setUsedMemoryDescription(tempStr);
        if (!ok) 
            throw ErrorClass("Error during setUsedMemoryDescription!");
        tempDbl = osresult1->getUsedMemoryValue();
        ok &= osresult2->setUsedMemoryValue(tempDbl);
        if (!ok) 
            throw ErrorClass("Error during setUsedMemoryValue!");
        tempStr = osresult1->getUsedCPUSpeedUnit();
        ok &= osresult2->setUsedCPUSpeedUnit(tempStr);
        if (!ok) 
            throw ErrorClass("Error during setUsedCPUSpeedUnit!");
        tempStr = osresult1->getUsedCPUSpeedDescription();
        ok &= osresult2->setUsedCPUSpeedDescription(tempStr);
        if (!ok) 
            throw ErrorClass("Error during setUsedCPUSpeedDescription!");
        tempDbl = osresult1->getUsedCPUSpeedValue();
        ok &= osresult2->setUsedCPUSpeedValue(tempDbl);
        if (!ok) 
            throw ErrorClass("Error during setUsedCPUSpeedValue!");
        tempStr = osresult1->getUsedCPUNumberDescription();
        ok &= osresult2->setUsedCPUNumberDescription(tempStr);
        if (!ok) 
            throw ErrorClass("Error during setUsedCPUNumberDescription!");
        tempInt = osresult1->getUsedCPUNumberValue();
        ok &= osresult2->setUsedCPUNumberValue(tempInt);
        if (!ok) 
            throw ErrorClass("Error during setUsedCPUNumberValue!");

        tempInt = osresult1->getNumberOfOtherJobResults();
        ok &= osresult2->setNumberOfOtherJobResults(tempInt);
        if (!ok) 
            throw ErrorClass("Error during setNumberOfOtherJobResults!");
        for (int i=0; i < tempInt; i++)
        {
            tempStr = osresult1->getOtherJobResultName(i);
            ok &= osresult2->setOtherJobResultName(i,tempStr);
            if (!ok) 
                throw ErrorClass("Error during setOtherJobResultName!");
            tempStr = osresult1->getOtherJobResultValue(i);
            ok &= osresult2->setOtherJobResultValue(i,tempStr);
            if (!ok) 
                throw ErrorClass("Error during setOtherJobResultValue!");
            tempStr = osresult1->getOtherJobResultDescription(i);
            ok &= osresult2->setOtherJobResultDescription(i,tempStr);
            if (!ok) 
                throw ErrorClass("Error during setOtherJobResultDescription!");
        }

        tempInt = osresult1->getSolutionNumber();
        ok &= osresult2->setSolutionNumber(tempInt);
        if (!ok) 
            throw ErrorClass("Error during setSolutionNumber!");
        int nSoln = tempInt;
        int nVar, nObj, nCon, nOther, nItem;

        tempInt = osresult1->getVariableNumber();
        ok &= osresult2->setVariableNumber(tempInt);
        if (!ok) 
            throw ErrorClass("Error during setVariableNumber!");
        tempInt = osresult1->getObjectiveNumber();
        ok &= osresult2->setObjectiveNumber(tempInt);
        if (!ok) 
            throw ErrorClass("Error during setObjectiveNumber!");
        tempInt = osresult1->getConstraintNumber();
        ok &= osresult2->setConstraintNumber(tempInt);
        if (!ok) 
            throw ErrorClass("Error during setConstraintNumber!");

        for (int i=0; i < nSoln; ++i)
        {
            tempInt = osresult1->getSolutionTargetObjectiveIdx(i);
            ok &= osresult2->setSolutionTargetObjectiveIdx(i,tempInt);
            if (!ok) 
                throw ErrorClass("Error during setSolutionTargetObjectiveIdx!");
            tempStr = osresult1->getSolutionTargetObjectiveName(i);
            ok &= osresult2->setSolutionTargetObjectiveName(i,tempStr);
            if (!ok) 
                throw ErrorClass("Error during getSolutionTargetObjectiveName!");
            bool tempLog = osresult1->getSolutionWeightedObjectives(i);
            ok &= osresult2->setSolutionWeightedObjectives(i,tempLog);
            if (!ok) 
                throw ErrorClass("Error during setSolutionWeightedObjectives!");
            tempStr = osresult1->getSolutionStatusType(i);
            ok &= osresult2->setSolutionStatusType(i,tempStr);
            if (!ok) 
                throw ErrorClass("Error during setSolutionStatusType!");
            tempStr = osresult1->getSolutionStatusDescription(i);
            ok &= osresult2->setSolutionStatusDescription(i,tempStr);
            if (!ok) 
                throw ErrorClass("Error during setSolutionStatusDescription!");
            
            tempInt = osresult1->getNumberOfSolutionSubstatuses(i);
            ok &= osresult2->setNumberOfSolutionSubstatuses(i,tempInt);
            if (!ok) 
                throw ErrorClass("Error during setNumberOfSolutionSubstatuses!");

            for (int j=0; j < tempInt; ++j)
            {
                tempStr = osresult1->getSolutionSubstatusType(i,j);
                ok &= osresult2->setSolutionSubstatusType(i,j,tempStr);
                if (!ok) 
                    throw ErrorClass("Error during setSolutionSubstatusType!");
                tempStr = osresult1->getSolutionSubstatusDescription(i,j);
                ok &= osresult2->setSolutionSubstatusDescription(i,j,tempStr);
                if (!ok) 
                    throw ErrorClass("Error during setSolutionSubstatusDescription!");
            }

            tempStr = osresult1->getSolutionMessage(i);
            ok &= osresult2->setSolutionMessage(i,tempStr);
            if (!ok) 
                throw ErrorClass("Error during setSolutionMessage!");

            tempInt = osresult1->getNumberOfVarValues(i);
            ok &= osresult2->setNumberOfVarValues(i,tempInt);
            if (!ok) 
                throw ErrorClass("Error during setNumberOfVarValues!");
            nVar = tempInt;

            for (int j=0; j < nVar; ++j)
            {
                tempInt = osresult1->getVarValueIdx(i,j);
                tempStr = osresult1->getVarValueName(i,j);
                tempDbl = osresult1->getVarValue(i,j);
                ok &= osresult2->setVarValue(i,j,tempInt,tempStr,tempDbl);
                if (!ok) 
                    throw ErrorClass("Error during setVarValue!");
            }

            tempInt = osresult1->getNumberOfVarValuesString(i);
            ok &= osresult2->setNumberOfVarValuesString(i,tempInt);
            if (!ok) 
                throw ErrorClass("Error during setNumberOfVarValuesString!");
            nVar = tempInt;

            std::string tempStr1, tempStr2;

            for (int j=0; j < nVar; ++j)
            {
                tempInt  = osresult1->getVarValueStringIdx(i,j);
                tempStr1 = osresult1->getVarValueStringName(i,j);
                tempStr2 = osresult1->getVarValueString(i,j);
                ok &= osresult2->setVarValueString(i,j,tempInt,tempStr1,tempStr2);
                if (!ok) 
                    throw ErrorClass("Error during setVarValueString!");
            }

//            int* tempArray = new int[3];
            tempInt = osresult1->getBasisStatusNumberOfEl(i,ENUM_PROBLEM_COMPONENT_variables,ENUM_BASIS_STATUS_basic);
            for (int j=0; j<tempInt; ++j)
                tempArray[j] = osresult1->getBasisStatusEl(i,ENUM_PROBLEM_COMPONENT_variables,ENUM_BASIS_STATUS_basic,j);
            ok &= osresult2->setBasisStatus(i,ENUM_PROBLEM_COMPONENT_variables,ENUM_BASIS_STATUS_basic,tempArray,tempInt);
            if (!ok) 
                throw ErrorClass("Error during setBasisStatus (variables basic)!");

            tempInt = osresult1->getBasisStatusNumberOfEl(i,ENUM_PROBLEM_COMPONENT_variables,ENUM_BASIS_STATUS_atLower);
            for (int j=0; j<tempInt; ++j)
                tempArray[j] = osresult1->getBasisStatusEl(i,ENUM_PROBLEM_COMPONENT_variables,ENUM_BASIS_STATUS_atLower,j);
            ok &= osresult2->setBasisStatus(i,ENUM_PROBLEM_COMPONENT_variables,ENUM_BASIS_STATUS_atLower,tempArray,tempInt);
            if (!ok) 
                throw ErrorClass("Error during setBasisStatus (variables atLower)!");

            tempInt = osresult1->getBasisStatusNumberOfEl(i,ENUM_PROBLEM_COMPONENT_variables,ENUM_BASIS_STATUS_atUpper);
            for (int j=0; j<tempInt; ++j)
                tempArray[j] = osresult1->getBasisStatusEl(i,ENUM_PROBLEM_COMPONENT_variables,ENUM_BASIS_STATUS_atUpper,j);
            ok &= osresult2->setBasisStatus(i,ENUM_PROBLEM_COMPONENT_variables,ENUM_BASIS_STATUS_atUpper,tempArray,tempInt);
            if (!ok) 
                throw ErrorClass("Error during setBasisStatus (variables atUpper)!");

            tempInt = osresult1->getBasisStatusNumberOfEl(i,ENUM_PROBLEM_COMPONENT_variables,ENUM_BASIS_STATUS_atEquality);
            for (int j=0; j<tempInt; ++j)
                tempArray[j] = osresult1->getBasisStatusEl(i,ENUM_PROBLEM_COMPONENT_variables,ENUM_BASIS_STATUS_atEquality,j);
            ok &= osresult2->setBasisStatus(i,ENUM_PROBLEM_COMPONENT_variables,ENUM_BASIS_STATUS_atEquality,tempArray,tempInt);
            if (!ok) 
                throw ErrorClass("Error during setBasisStatus (variables atEquality)!");

            tempInt = osresult1->getBasisStatusNumberOfEl(i,ENUM_PROBLEM_COMPONENT_variables,ENUM_BASIS_STATUS_isFree);
            for (int j=0; j<tempInt; ++j)
                tempArray[j] = osresult1->getBasisStatusEl(i,ENUM_PROBLEM_COMPONENT_variables,ENUM_BASIS_STATUS_isFree,j);
            ok &= osresult2->setBasisStatus(i,ENUM_PROBLEM_COMPONENT_variables,ENUM_BASIS_STATUS_isFree,tempArray,tempInt);
            if (!ok) 
                throw ErrorClass("Error during setBasisStatus (variables isFree)!");

            tempInt = osresult1->getBasisStatusNumberOfEl(i,ENUM_PROBLEM_COMPONENT_variables,ENUM_BASIS_STATUS_superbasic);
            for (int j=0; j<tempInt; ++j)
                tempArray[j] = osresult1->getBasisStatusEl(i,ENUM_PROBLEM_COMPONENT_variables,ENUM_BASIS_STATUS_superbasic,j);
            ok &= osresult2->setBasisStatus(i,ENUM_PROBLEM_COMPONENT_variables,ENUM_BASIS_STATUS_superbasic,tempArray,tempInt);
            if (!ok) 
                throw ErrorClass("Error during setBasisStatus (variables superbasic)!");

            tempInt = osresult1->getBasisStatusNumberOfEl(i,ENUM_PROBLEM_COMPONENT_variables,ENUM_BASIS_STATUS_unknown);
            for (int j=0; j<tempInt; ++j)
                tempArray[j] = osresult1->getBasisStatusEl(i,ENUM_PROBLEM_COMPONENT_variables,ENUM_BASIS_STATUS_unknown,j);
            ok &= osresult2->setBasisStatus(i,ENUM_PROBLEM_COMPONENT_variables,ENUM_BASIS_STATUS_unknown,tempArray,tempInt);
            if (!ok) 
                throw ErrorClass("Error during setBasisStatus (variables unknown)!");


            tempInt = osresult1->getNumberOfOtherVariableResults(i);
            ok &= osresult2->setNumberOfOtherVariableResults(i,tempInt);
            if (!ok) 
                throw ErrorClass("Error during setNumberOfOtherVariableResults!");
            nOther = tempInt;
            for (int j=0; j < nOther; ++j)
            {
                tempStr = osresult1->getOtherVariableResultName(i,j);
                ok &= osresult2->setOtherVariableResultName(i,j,tempStr);
                if (!ok) 
                    throw ErrorClass("Error during setOtherVariableResultName!");
                tempStr = osresult1->getOtherVariableResultDescription(i,j);
                ok &= osresult2->setOtherVariableResultDescription(i,j,tempStr);
                if (!ok) 
                    throw ErrorClass("Error during setOtherVariableResultDescription!");
                tempStr = osresult1->getOtherVariableResultValue(i,j);
                ok &= osresult2->setOtherVariableResultValue(i,j,tempStr);
                if (!ok) 
                    throw ErrorClass("Error during setOtherVariableResultValue!");

                tempInt = osresult1->getOtherVariableResultNumberOfVar(i,j);
                ok &= osresult2->setOtherVariableResultNumberOfVar(i,j,tempInt);
                if (!ok) 
                    throw ErrorClass("Error during setOtherVariableResultNumberOfVar!");

                int nVar = tempInt;
                for (int k=0; k < nVar; ++k)
                {
                    tempInt = osresult1->getOtherVariableResultVarIdx(i,j,k);
                    ok &= osresult2->setOtherVariableResultVarIdx(i,j,k,tempInt);
                    if (!ok) 
                        throw ErrorClass("Error during setOtherVariableResultVarIdx!");
                    tempStr = osresult1->getOtherVariableResultVar(i,j,k);
                    ok &= osresult2->setOtherVariableResultVar(i,j,k,tempStr);
                    if (!ok) 
                        throw ErrorClass("Error during setOtherVariableResultVar!");
                }

                int nEnum = osresult1->getOtherVariableResultNumberOfEnumerations(i,j);
                ok &= osresult2->setOtherVariableResultNumberOfEnumerations(i,j,nEnum);
                if (!ok) 
                    throw ErrorClass("Error during setOtherVariableResultNumberOfEnumerations!");

                for (int k=0; k < nEnum; ++k)
                {
//                    if (tempArray != NULL) delete[] tempArray;
                    tempStr1  = osresult1->getOtherVariableResultEnumerationValue(i,j,k);
                    tempStr2  = osresult1->getOtherVariableResultEnumerationDescription(i,j,k);
                    tempInt   = osresult1->getOtherVariableResultEnumerationNumberOfEl(i,j,k);
                    for (int l=0; l<tempInt; ++l)
                        tempArray[l] = osresult1->getOtherVariableResultEnumerationEl(i,j,k,l);
                    ok &= osresult2->setOtherOptionEnumeration(i,j,ENUM_PROBLEM_COMPONENT_variables,k,tempStr1,tempStr2,tempArray,tempInt);
                    if (!ok) 
                        throw ErrorClass("Error during setOtherVariableResultEnumeration!");
                }
            }

            tempInt = osresult1->getNumberOfObjValues(i);
            ok &= osresult2->setNumberOfObjValues(i,tempInt);
            if (!ok) 
                throw ErrorClass("Error during setNumberOfObjValues!");
            nObj = tempInt;
            for (int j=0; j < nObj; ++j)
            {
                tempInt = osresult1->getObjValueIdx(i,j);
                tempStr = osresult1->getObjValueName(i,j);
                tempDbl = osresult1->getObjValue(i,j);
                ok &= osresult2->setObjValue(i,j,tempInt,tempStr,tempDbl);
                if (!ok) 
                    throw ErrorClass("Error during setObjValue!");
            }


            tempInt = osresult1->getBasisStatusNumberOfEl(i,ENUM_PROBLEM_COMPONENT_objectives,ENUM_BASIS_STATUS_basic);
            for (int j=0; j<tempInt; ++j)
                tempArray[j] = osresult1->getBasisStatusEl(i,ENUM_PROBLEM_COMPONENT_objectives,ENUM_BASIS_STATUS_basic,j);
            ok &= osresult2->setBasisStatus(i,ENUM_PROBLEM_COMPONENT_objectives,ENUM_BASIS_STATUS_basic,tempArray,tempInt);
            if (!ok) 
                throw ErrorClass("Error during setBasisStatus (objectives basic)!");

            tempInt = osresult1->getBasisStatusNumberOfEl(i,ENUM_PROBLEM_COMPONENT_objectives,ENUM_BASIS_STATUS_atLower);
            for (int j=0; j<tempInt; ++j)
                tempArray[j] = osresult1->getBasisStatusEl(i,ENUM_PROBLEM_COMPONENT_objectives,ENUM_BASIS_STATUS_atLower,j);
            ok &= osresult2->setBasisStatus(i,ENUM_PROBLEM_COMPONENT_objectives,ENUM_BASIS_STATUS_atLower,tempArray,tempInt);
            if (!ok) 
                throw ErrorClass("Error during setBasisStatus (objectives atLower)!");

            tempInt = osresult1->getBasisStatusNumberOfEl(i,ENUM_PROBLEM_COMPONENT_objectives,ENUM_BASIS_STATUS_atUpper);
            for (int j=0; j<tempInt; ++j)
                tempArray[j] = osresult1->getBasisStatusEl(i,ENUM_PROBLEM_COMPONENT_objectives,ENUM_BASIS_STATUS_atUpper,j);
            ok &= osresult2->setBasisStatus(i,ENUM_PROBLEM_COMPONENT_objectives,ENUM_BASIS_STATUS_atUpper,tempArray,tempInt);
            if (!ok) 
                throw ErrorClass("Error during setBasisStatus (objectives atUpper)!");

            tempInt = osresult1->getBasisStatusNumberOfEl(i,ENUM_PROBLEM_COMPONENT_objectives,ENUM_BASIS_STATUS_atEquality);
            for (int j=0; j<tempInt; ++j)
                tempArray[j] = osresult1->getBasisStatusEl(i,ENUM_PROBLEM_COMPONENT_objectives,ENUM_BASIS_STATUS_atEquality,j);
            ok &= osresult2->setBasisStatus(i,ENUM_PROBLEM_COMPONENT_objectives,ENUM_BASIS_STATUS_atEquality,tempArray,tempInt);
            if (!ok) 
                throw ErrorClass("Error during setBasisStatus (objectives atEquality)!");

            tempInt = osresult1->getBasisStatusNumberOfEl(i,ENUM_PROBLEM_COMPONENT_objectives,ENUM_BASIS_STATUS_isFree);
            for (int j=0; j<tempInt; ++j)
                tempArray[j] = osresult1->getBasisStatusEl(i,ENUM_PROBLEM_COMPONENT_objectives,ENUM_BASIS_STATUS_isFree,j);
            ok &= osresult2->setBasisStatus(i,ENUM_PROBLEM_COMPONENT_objectives,ENUM_BASIS_STATUS_isFree,tempArray,tempInt);
            if (!ok) 
                throw ErrorClass("Error during setBasisStatus (objectives isFree)!");

            tempInt = osresult1->getBasisStatusNumberOfEl(i,ENUM_PROBLEM_COMPONENT_objectives,ENUM_BASIS_STATUS_superbasic);
            for (int j=0; j<tempInt; ++j)
                tempArray[j] = osresult1->getBasisStatusEl(i,ENUM_PROBLEM_COMPONENT_objectives,ENUM_BASIS_STATUS_superbasic,j);
            ok &= osresult2->setBasisStatus(i,ENUM_PROBLEM_COMPONENT_objectives,ENUM_BASIS_STATUS_superbasic,tempArray,tempInt);
            if (!ok) 
                throw ErrorClass("Error during setBasisStatus (objectives superbasic)!");

            tempInt = osresult1->getBasisStatusNumberOfEl(i,ENUM_PROBLEM_COMPONENT_objectives,ENUM_BASIS_STATUS_unknown);
            for (int j=0; j<tempInt; ++j)
                tempArray[j] = osresult1->getBasisStatusEl(i,ENUM_PROBLEM_COMPONENT_objectives,ENUM_BASIS_STATUS_unknown,j);
            ok &= osresult2->setBasisStatus(i,ENUM_PROBLEM_COMPONENT_objectives,ENUM_BASIS_STATUS_unknown,tempArray,tempInt);
            if (!ok) 
                throw ErrorClass("Error during setBasisStatus (objectives unknown)!");



            tempInt = osresult1->getNumberOfOtherObjectiveResults(i);
            ok &= osresult2->setNumberOfOtherObjectiveResults(i,tempInt);
            if (!ok) 
                throw ErrorClass("Error during setNumberOfOtherObjectiveResults!");
            nOther = tempInt;
            for (int j=0; j < nOther; ++j)
            {
                tempStr = osresult1->getOtherObjectiveResultName(i,j);
                ok &= osresult2->setOtherObjectiveResultName(i,j,tempStr);
                if (!ok) 
                    throw ErrorClass("Error during setOtherObjectiveResultName!");
                tempStr = osresult1->getOtherObjectiveResultDescription(i,j);
                ok &= osresult2->setOtherObjectiveResultDescription(i,j,tempStr);
                if (!ok) 
                    throw ErrorClass("Error during setOtherObjectiveResultDescription!");
                tempStr = osresult1->getOtherObjectiveResultValue(i,j);
                ok &= osresult2->setOtherObjectiveResultValue(i,j,tempStr);
                if (!ok) 
                    throw ErrorClass("Error during setOtherObjectiveResultValue!");

                tempInt = osresult1->getOtherObjectiveResultNumberOfObj(i,j);
                ok &= osresult2->setOtherObjectiveResultNumberOfObj(i,j,tempInt);
                if (!ok) 
                    throw ErrorClass("Error during setOtherObjectiveResultNumberOfObj!");

                nObj = tempInt;
                for (int k=0; k < nObj; ++k)
                {
                    tempInt = osresult1->getOtherObjectiveResultObjIdx(i,j,k);
                    ok &= osresult2->setOtherObjectiveResultObjIdx(i,j,k,tempInt);
                    if (!ok) 
                        throw ErrorClass("Error during setOtherObjectiveResultObjIdx!");
                    tempStr = osresult1->getOtherObjectiveResultObj(i,j,k);
                    ok &= osresult2->setOtherObjectiveResultObj(i,j,k,tempStr);
                    if (!ok) 
                        throw ErrorClass("Error during setOtherObjectiveResultObj!");
                }

                int nEnum = osresult1->getOtherObjectiveResultNumberOfEnumerations(i,j);
                ok &= osresult2->setOtherObjectiveResultNumberOfEnumerations(i,j,nEnum);
                if (!ok) 
                    throw ErrorClass("Error during setOtherObjectiveResultNumberOfEnumerations!");
                std::string tempStr1, tempStr2;

                for (int k=0; k < nEnum; ++k)
                {
//                    if (tempArray != NULL) delete[] tempArray;
                    tempStr1  = osresult1->getOtherObjectiveResultEnumerationValue(i,j,k);
                    tempStr2  = osresult1->getOtherObjectiveResultEnumerationDescription(i,j,k);
                    tempInt   = osresult1->getOtherObjectiveResultEnumerationNumberOfEl(i,j,k);
                    for (int l=0; l<tempInt; ++l)
                        tempArray[l] = osresult1->getOtherObjectiveResultEnumerationEl(i,j,k,l);
                    ok &= osresult2->setOtherOptionEnumeration(i,j,ENUM_PROBLEM_COMPONENT_objectives,k,tempStr1,tempStr2,tempArray,tempInt);
                    if (!ok) 
                        throw ErrorClass("Error during setOtherObjectiveResultEnumeration!");
                }
            }


            tempInt = osresult1->getNumberOfDualValues(i);
            ok &= osresult2->setNumberOfDualValues(i,tempInt);
            if (!ok) 
                throw ErrorClass("Error during setNumberOfDualValues!");
            nCon = tempInt;
            for (int j=0; j < nCon; ++j)
            {
                tempInt = osresult1->getDualValueIdx(i,j);
                tempStr = osresult1->getDualValueName(i,j);
                tempDbl = osresult1->getDualValue(i,j);
                ok &= osresult2->setDualValue(i,j,tempInt,tempStr,tempDbl);
                if (!ok) 
                    throw ErrorClass("Error during setDualValue!");
            }


            tempInt = osresult1->getBasisStatusNumberOfEl(i,ENUM_PROBLEM_COMPONENT_constraints,ENUM_BASIS_STATUS_basic);
            for (int j=0; j<tempInt; ++j)
                tempArray[j] = osresult1->getBasisStatusEl(i,ENUM_PROBLEM_COMPONENT_constraints,ENUM_BASIS_STATUS_basic,j);
            ok &= osresult2->setBasisStatus(i,ENUM_PROBLEM_COMPONENT_constraints,ENUM_BASIS_STATUS_basic,tempArray,tempInt);
            if (!ok) 
                throw ErrorClass("Error during setBasisStatus (constraints basic)!");

            tempInt = osresult1->getBasisStatusNumberOfEl(i,ENUM_PROBLEM_COMPONENT_constraints,ENUM_BASIS_STATUS_atLower);
            for (int j=0; j<tempInt; ++j)
                tempArray[j] = osresult1->getBasisStatusEl(i,ENUM_PROBLEM_COMPONENT_constraints,ENUM_BASIS_STATUS_atLower,j);
            ok &= osresult2->setBasisStatus(i,ENUM_PROBLEM_COMPONENT_constraints,ENUM_BASIS_STATUS_atLower,tempArray,tempInt);
            if (!ok) 
                throw ErrorClass("Error during setBasisStatus (constraints atLower)!");

            tempInt = osresult1->getBasisStatusNumberOfEl(i,ENUM_PROBLEM_COMPONENT_constraints,ENUM_BASIS_STATUS_atUpper);
            for (int j=0; j<tempInt; ++j)
                tempArray[j] = osresult1->getBasisStatusEl(i,ENUM_PROBLEM_COMPONENT_constraints,ENUM_BASIS_STATUS_atUpper,j);
            ok &= osresult2->setBasisStatus(i,ENUM_PROBLEM_COMPONENT_constraints,ENUM_BASIS_STATUS_atUpper,tempArray,tempInt);
            if (!ok) 
                throw ErrorClass("Error during setBasisStatus (constraints atUpper)!");

            tempInt = osresult1->getBasisStatusNumberOfEl(i,ENUM_PROBLEM_COMPONENT_constraints,ENUM_BASIS_STATUS_atEquality);
            for (int j=0; j<tempInt; ++j)
                tempArray[j] = osresult1->getBasisStatusEl(i,ENUM_PROBLEM_COMPONENT_constraints,ENUM_BASIS_STATUS_atEquality,j);
            ok &= osresult2->setBasisStatus(i,ENUM_PROBLEM_COMPONENT_constraints,ENUM_BASIS_STATUS_atEquality,tempArray,tempInt);
            if (!ok) 
                throw ErrorClass("Error during setBasisStatus (constraints atEquality)!");

            tempInt = osresult1->getBasisStatusNumberOfEl(i,ENUM_PROBLEM_COMPONENT_constraints,ENUM_BASIS_STATUS_isFree);
            for (int j=0; j<tempInt; ++j)
                tempArray[j] = osresult1->getBasisStatusEl(i,ENUM_PROBLEM_COMPONENT_constraints,ENUM_BASIS_STATUS_isFree,j);
            ok &= osresult2->setBasisStatus(i,ENUM_PROBLEM_COMPONENT_constraints,ENUM_BASIS_STATUS_isFree,tempArray,tempInt);
            if (!ok) 
                throw ErrorClass("Error during setBasisStatus (constraints isFree)!");

            tempInt = osresult1->getBasisStatusNumberOfEl(i,ENUM_PROBLEM_COMPONENT_constraints,ENUM_BASIS_STATUS_superbasic);
            for (int j=0; j<tempInt; ++j)
                tempArray[j] = osresult1->getBasisStatusEl(i,ENUM_PROBLEM_COMPONENT_constraints,ENUM_BASIS_STATUS_superbasic,j);
            ok &= osresult2->setBasisStatus(i,ENUM_PROBLEM_COMPONENT_constraints,ENUM_BASIS_STATUS_superbasic,tempArray,tempInt);
            if (!ok) 
                throw ErrorClass("Error during setBasisStatus (constraints superbasic)!");

            tempInt = osresult1->getBasisStatusNumberOfEl(i,ENUM_PROBLEM_COMPONENT_constraints,ENUM_BASIS_STATUS_unknown);
            for (int j=0; j<tempInt; ++j)
                tempArray[j] = osresult1->getBasisStatusEl(i,ENUM_PROBLEM_COMPONENT_constraints,ENUM_BASIS_STATUS_unknown,j);
            ok &= osresult2->setBasisStatus(i,ENUM_PROBLEM_COMPONENT_constraints,ENUM_BASIS_STATUS_unknown,tempArray,tempInt);
            if (!ok) 
                throw ErrorClass("Error during setBasisStatus (constraints unknown)!");




            tempInt = osresult1->getNumberOfOtherConstraintResults(i);
            ok &= osresult2->setNumberOfOtherConstraintResults(i,tempInt);
            if (!ok) 
                throw ErrorClass("Error during setNumberOfOtherConstraintResults!");
            nOther = tempInt;
            for (int j=0; j < nOther; ++j)
            {
                tempStr = osresult1->getOtherConstraintResultName(i,j);
                ok &= osresult2->setOtherConstraintResultName(i,j,tempStr);
                if (!ok) 
                    throw ErrorClass("Error during setOtherConstraintResultName!");
                tempStr = osresult1->getOtherConstraintResultDescription(i,j);
                ok &= osresult2->setOtherConstraintResultDescription(i,j,tempStr);
                if (!ok) 
                    throw ErrorClass("Error during setOtherConstraintResultDescription!");
                tempStr = osresult1->getOtherConstraintResultValue(i,j);
                ok &= osresult2->setOtherConstraintResultValue(i,j,tempStr);
                if (!ok) 
                    throw ErrorClass("Error during setOtherConstraintResultValue!");
                tempInt = osresult1->getOtherConstraintResultNumberOfCon(i,j);
                ok &= osresult2->setOtherConstraintResultNumberOfCon(i,j,tempInt);
                if (!ok) 
                    throw ErrorClass("Error during setOtherConstraintResultNumberOfCon!");

                nCon = tempInt;
                for (int k=0; k < nCon; ++k)
                {
                    tempInt = osresult1->getOtherConstraintResultConIdx(i,j,k);
                    ok &= osresult2->setOtherConstraintResultConIdx(i,j,k,tempInt);
                    if (!ok) 
                        throw ErrorClass("Error during setOtherConstraintResultConIdx!");
                    tempStr = osresult1->getOtherConstraintResultCon(i,j,k);
                    ok &= osresult2->setOtherConstraintResultCon(i,j,k,tempStr);
                    if (!ok) 
                        throw ErrorClass("Error during setOtherConstraintResultCon!");
                }



                int nEnum = osresult1->getOtherConstraintResultNumberOfEnumerations(i,j);
                ok &= osresult2->setOtherConstraintResultNumberOfEnumerations(i,j,nEnum);
                if (!ok) 
                    throw ErrorClass("Error during setOtherConstraintResultNumberOfEnumerations!");
                std::string tempStr1, tempStr2;

                for (int k=0; k < nEnum; ++k)
                {
                    tempStr1  = osresult1->getOtherConstraintResultEnumerationValue(i,j,k);
                    tempStr2  = osresult1->getOtherConstraintResultEnumerationDescription(i,j,k);
                    tempInt   = osresult1->getOtherConstraintResultEnumerationNumberOfEl(i,j,k);
                    for (int l=0; l<tempInt; ++l)
                        tempArray[l] = osresult1->getOtherConstraintResultEnumerationEl(i,j,k,l);
                    ok &= osresult2->setOtherOptionEnumeration(i,j,ENUM_PROBLEM_COMPONENT_constraints,k,tempStr1,tempStr2,tempArray,tempInt);

                    if (!ok) 
                        throw ErrorClass("Error during setOtherConstraintResultEnumeration!");
                }
            }


            tempInt = osresult1->getNumberOfOtherSolutionResults(i);
            ok &= osresult2->setNumberOfOtherSolutionResults(i,tempInt);
            if (!ok) 
                throw ErrorClass("Error during setNumberOfOtherSolutionResults!");
            nOther = tempInt;
            for (int j=0; j < nOther; ++j)
            {
                tempStr = osresult1->getOtherSolutionResultName(i,j);
                ok &= osresult2->setOtherSolutionResultName(i,j,tempStr);
                if (!ok) 
                    throw ErrorClass("Error during setOtherSolutionResultName!");
                tempStr = osresult1->getOtherSolutionResultCategory(i,j);
                ok &= osresult2->setOtherSolutionResultCategory(i,j,tempStr);
                if (!ok) 
                    throw ErrorClass("Error during setOtherSolutionResultCategory!");
                tempStr = osresult1->getOtherSolutionResultDescription(i,j);
                ok &= osresult2->setOtherSolutionResultDescription(i,j,tempStr);
                if (!ok) 
                    throw ErrorClass("Error during setOtherSolutionResultDescription!");
                tempInt = osresult1->getOtherSolutionResultNumberOfItems(i,j);
                ok &= osresult2->setOtherSolutionResultNumberOfItems(i,j,tempInt);
                if (!ok) 
                    throw ErrorClass("Error during setOtherSolutionResultNumberOfItems!");

                nItem = tempInt;
                for (int k=0; k < nItem; ++k)
                {
                    tempStr = osresult1->getOtherSolutionResultItem(i,j,k);
                    ok &= osresult2->setOtherSolutionResultItem(i,j,k,tempStr);
                    if (!ok) 
                        throw ErrorClass("Error during setSolutionResultItem!");
                }
            }
        }

        tempInt = osresult1->getNumberOfSolverOutputs();
        ok &= osresult2->setNumberOfSolverOutputs(tempInt);
        if (!ok) 
            throw ErrorClass("Error during setNumberOfSolverOutputs!");
        nOther = tempInt;
        for (int i=0; i < nOther; ++i)
        {
            tempStr = osresult1->getSolverOutputName(i);
            ok &= osresult2->setSolverOutputName(i,tempStr);
            if (!ok) 
                throw ErrorClass("Error during setSolverOutputName!");
            tempStr = osresult1->getSolverOutputCategory(i);
            ok &= osresult2->setSolverOutputCategory(i,tempStr);
            if (!ok) 
                throw ErrorClass("Error during setSolverOutputCategory!");
            tempStr = osresult1->getSolverOutputDescription(i);
            ok &= osresult2->setSolverOutputDescription(i,tempStr);
            if (!ok) 
                throw ErrorClass("Error during setSolverOutputDescription!");
            tempInt = osresult1->getSolverOutputNumberOfItems(i);
            ok &= osresult2->setSolverOutputNumberOfItems(i,tempInt);
            if (!ok) 
                throw ErrorClass("Error during setSolverOutputNumberOfItems!");
            for (int j=0; j < tempInt; ++j)
            {
                tempStr = osresult1->getSolverOutputItem(i,j);
                ok &= osresult2->setSolverOutputItem(i,j,tempStr);
                if (!ok) 
                    throw ErrorClass("Error during setSolverOutputItem!");
            }
        }


        ok &= osresult1->IsEqual(osresult2);
        if (!ok)
            throw ErrorClass("Error duplicating OSResult object using get() and set() methods");

        if (osrlwriter != NULL) delete osrlwriter;
        osrlwriter = NULL;
        if (osrlreader != NULL) delete osrlreader;
        osrlreader = NULL;
        if (osresult1  != NULL) delete osresult1;
        osresult1 = NULL;
        if (osresult2  != NULL) delete osresult2;
        osresult2 = NULL;
//        if (osresult   != NULL) delete osresult;
//        osresult = NULL;
        if (tempArray  != NULL) delete[] tempArray;
        tempArray = NULL;

        unitTestResult << "TEST " << nOfTest << ": Successful test of OSrL tools" << std::endl;
        cout << endl << "TEST " << nOfTest << ": Completed successfully" << endl << endl;
    }    
    
    catch(const ErrorClass& eclass){
        cout << endl << endl << endl;
        if (osrlwriter != NULL) delete osrlwriter;
        osrlwriter = NULL;
        if (osrlreader != NULL) delete osrlreader;
        osrlreader = NULL;
        if (osresult1  != NULL) delete osresult1;
        osresult1 = NULL;
        if (osresult2  != NULL) delete osresult2;

        osresult2 = NULL;
//        if (osresult   != NULL) delete osresult;
//        osresult = NULL;
        if (tempArray  != NULL) delete[] tempArray;
        tempArray = NULL;
        // " Problem with the test reading OSoL data";
        unitTestResultFailure << eclass.errormsg << endl;
        unitTestResultFailure << "There was a failure in the test of OSrL get() methods" << endl;
    }

    // Now test the OSrL parser
    try{ 
        /**
         * in this part of the unitTest we
         * 1) read an OSrL string from a file
         * 2) create an OSResult object from the string
         * 3) write a new OSrL string from the in-memory OSResult object
         * 4) read the string back again to make sure nothing was lost
         *    in translation
         * This sequence of steps is repeated for files of different sparsity
         * to make sure empty elements are handled properly. 
         */
        cout << endl << "TEST " << ++nOfTest << ": OSrL parser" << endl << endl;

        osrlwriter = new OSrLWriter();
        osrlreader = new OSrLReader();
        fileUtil   = new FileUtil();

        std::string tmpOSrL;
        clock_t start, finish;
        double duration;
        std::string osrl;
        cout << "Test parsing an OSrL file" << endl;
        cout << "First read the OSrL file into a string" << endl;
        osrlFileName = dataDir  + "osrlFiles" + dirsep + "parserTest.osrl"; 
        start = clock();
        osrl = fileUtil->getFileAsString( osrlFileName.c_str() );
        finish = clock();
        duration = (double) (finish - start) / CLOCKS_PER_SEC;
        cout << "Reading the file into a string took (seconds): "<< duration << endl;
        cout << osrl << endl;
        start = clock();
        cout << "PARSE THE OSRL STRING INTO AN OSRESULT OBJECT" << endl;
        osresult = osrlreader->readOSrL( osrl);
        cout << "Finished read; write OSResult object to temporary string" << endl;

        tmpOSrL = osrlwriter->writeOSrL( osresult);

        cout << tmpOSrL << endl;


        // make sure we can parse without error
        delete osrlreader;
        osrlreader = new OSrLReader();
        osrlreader->readOSrL( tmpOSrL);

        delete osrlwriter;
        osrlwriter = NULL;
        delete osrlreader;
        osrlreader = NULL;
        delete fileUtil;
        fileUtil = NULL;


/*        // now a second example
        cout << endl << "Test parsing another OSrL file" << endl;
        osrlwriter = new OSrLWriter();
        osrlreader = new OSrLReader();
        cout << "FIRST READ THE OSrL FILE INTO A STRING" << endl;
        //errorExample.osrl -- check to see if we read an error message correctly;
        osrlFileName = dataDir  + "osrlFiles" + dirsep + "errorExample.osrl"; 
        osrl = fileUtil->getFileAsString( osrlFileName.c_str() );
        finish = clock();
        duration = (double) (finish - start) / CLOCKS_PER_SEC;
        cout << "Reading the file into a string took (seconds): "<< duration << endl;
        cout << "PARSE THE OSRL STRING INTO AN OSRESULT OBJECT" << endl;
        osresult = osrlreader->readOSrL( osrl);
        tmpOSrL = osrlwriter->writeOSrL( osresult) ;
        delete osrlreader;
        osrlreader = new OSrLReader();
        osrlreader->readOSrL( tmpOSrL);
        delete osrlwriter;
        osrlwriter = NULL;
        delete osrlreader;
        osrlreader = NULL;

        // ... and another
        cout << endl << "parserTest1.osrl" << endl;
        osrlwriter = new OSrLWriter();
        osrlreader = new OSrLReader();
        cout << "FIRST READ THE OSrL FILE INTO A STRING" << endl;
        //errorExample.osrl -- check to see if we read an error message correctly;
        osrlFileName = dataDir  + "osrlFiles" + dirsep + "parserTest1.osrl"; 
        osrl = fileUtil->getFileAsString( osrlFileName.c_str() );
        finish = clock();
        duration = (double) (finish - start) / CLOCKS_PER_SEC;
        cout << "Reading the file into a string took (seconds): "<< duration << endl;
        cout << "PARSE THE OSRL STRING INTO AN OSRESULT OBJECT" << endl;
        osresult = osrlreader->readOSrL( osrl);
        tmpOSrL = osrlwriter->writeOSrL( osresult) ;
        delete osrlreader;
        osrlreader = new OSrLReader();
        osrlreader->readOSrL( tmpOSrL);
        delete osrlwriter;
        osrlwriter = NULL;
        delete osrlreader;
        osrlreader = NULL;

        // ... and another
        cout << endl << "parserTest2.osrl" << endl;
        osrlwriter = new OSrLWriter();
        osrlreader = new OSrLReader();
        cout << "FIRST READ THE OSrL FILE INTO A STRING" << endl;
        //errorExample.osrl -- check to see if we read an error message correctly;
        osrlFileName = dataDir  + "osrlFiles" + dirsep + "parserTest2.osrl"; 
        osrl = fileUtil->getFileAsString( osrlFileName.c_str() );

        finish = clock();
        duration = (double) (finish - start) / CLOCKS_PER_SEC;
        cout << "Reading the file into a string took (seconds): "<< duration << endl;
        cout << "PARSE THE OSRL STRING INTO AN OSRESULT OBJECT" << endl;
        osresult = osrlreader->readOSrL( osrl);
        cout << "WRITE THE OSRESULT OBJECT INTO A NEW OSRL STRING" << endl;
        tmpOSrL = osrlwriter->writeOSrL( osresult) ;
        delete osrlreader;
        osrlreader = new OSrLReader();
        cout << "PARSE THE NEW OSRL STRING INTO AN OSRESULT OBJECT" << endl;
        osrlreader->readOSrL( tmpOSrL);
        delete osrlwriter;
        osrlwriter = NULL;
        delete osrlreader;
        osrlreader = NULL;

        // ... and another
        cout << endl << "parserTest3.osrl" << endl;
        osrlwriter = new OSrLWriter();
        osrlreader = new OSrLReader();
        cout << "FIRST READ THE OSrL FILE INTO A STRING" << endl;
        //errorExample.osrl -- check to see if we read an error message correctly;
        osrlFileName = dataDir  + "osrlFiles" + dirsep + "parserTest3.osrl"; 
        osrl = fileUtil->getFileAsString( osrlFileName.c_str() );
        finish = clock();
        duration = (double) (finish - start) / CLOCKS_PER_SEC;
        cout << "Reading the file into a string took (seconds): "<< duration << endl;
        cout << "PARSE THE OSRL STRING INTO AN OSRESULT OBJECT" << endl;
        osresult = osrlreader->readOSrL( osrl);
        cout << "WRITE THE OSRESULT OBJECT INTO A NEW OSRL STRING" << endl;
        tmpOSrL = osrlwriter->writeOSrL( osresult) ;
        delete osrlreader;
        osrlreader = new OSrLReader();
        cout << "PARSE THE NEW OSRL STRING INTO AN OSRESULT OBJECT" << endl;
        osrlreader->readOSrL( tmpOSrL);
        delete osrlwriter;
        osrlwriter = NULL;
        delete osrlreader;
        osrlreader = NULL;

        // ... and another
        cout << endl << "parserTest4.osrl" << endl;
        osrlwriter = new OSrLWriter();
        osrlreader = new OSrLReader();
        cout << "FIRST READ THE OSrL FILE INTO A STRING" << endl;
        //errorExample.osrl -- check to see if we read an error message correctly;
        osrlFileName = dataDir  + "osrlFiles" + dirsep + "parserTest4.osrl"; 
        start = clock();
        osrl = fileUtil->getFileAsString( osrlFileName.c_str() );
        finish = clock();
        duration = (double) (finish - start) / CLOCKS_PER_SEC;
        cout << "Reading the file into a string took (seconds): "<< duration << endl;
        cout << "PARSE THE OSRL STRING INTO AN OSRESULT OBJECT" << endl;
        osresult = osrlreader->readOSrL( osrl);
        cout << "WRITE THE OSRESULT OBJECT INTO A NEW OSRL STRING" << endl;
        tmpOSrL = osrlwriter->writeOSrL( osresult) ;
        delete osrlreader;
        osrlreader = new OSrLReader();
        cout << "PARSE THE NEW OSRL STRING INTO AN OSRESULT OBJECT" << endl;
        osrlreader->readOSrL( tmpOSrL);
        delete osrlwriter;
        osrlwriter = NULL;
        delete osrlreader;
        osrlreader = NULL;

        // ... and another
        cout << endl << "parserTest5.osrl" << endl;
        osrlwriter = new OSrLWriter();
        osrlreader = new OSrLReader();
        cout << "FIRST READ THE OSrL FILE INTO A STRING" << endl;
        //errorExample.osrl -- check to see if we read an error message correctly;
        osrlFileName = dataDir  + "osrlFiles" + dirsep + "parserTest5.osrl"; 
        osrl = fileUtil->getFileAsString( osrlFileName.c_str() );
        finish = clock();
        duration = (double) (finish - start) / CLOCKS_PER_SEC;
        cout << "Reading the file into a string took (seconds): "<< duration << endl;
        cout << "PARSE THE OSRL STRING INTO AN OSRESULT OBJECT" << endl;
        osresult = osrlreader->readOSrL( osrl);
        cout << "WRITE THE OSRESULT OBJECT INTO A NEW OSRL STRING" << endl;
        tmpOSrL = osrlwriter->writeOSrL( osresult) ;
        delete osrlreader;
        osrlreader = new OSrLReader();
        cout << "PARSE THE NEW OSRL STRING INTO AN OSRESULT OBJECT" << endl;
        osrlreader->readOSrL( tmpOSrL);
        delete osrlwriter;
        osrlwriter = NULL;
        delete osrlreader;
        osrlreader = NULL;

        // ... and another
        cout << endl << "parserTest6.osrl" << endl;
        osrlwriter = new OSrLWriter();
        osrlreader = new OSrLReader();
        cout << "FIRST READ THE OSrL FILE INTO A STRING" << endl;
        //errorExample.osrl -- check to see if we read an error message correctly;
        osrlFileName = dataDir  + "osrlFiles" + dirsep + "parserTest6.osrl"; 
        osrl = fileUtil->getFileAsString( osrlFileName.c_str() );
        finish = clock();
        duration = (double) (finish - start) / CLOCKS_PER_SEC;
        cout << "Reading the file into a string took (seconds): "<< duration << endl;
        cout << "PARSE THE OSRL STRING INTO AN OSRESULT OBJECT" << endl;
        osresult = osrlreader->readOSrL( osrl);
        cout << "WRITE THE OSRESULT OBJECT INTO A NEW OSRL STRING" << endl;
        tmpOSrL = osrlwriter->writeOSrL( osresult) ;
        delete osrlreader;
        osrlreader = new OSrLReader();
        cout << "PARSE THE NEW OSRL STRING INTO AN OSRESULT OBJECT" << endl;
        osrlreader->readOSrL( tmpOSrL);
        delete osrlwriter;
        osrlwriter = NULL;
        delete osrlreader;
        osrlreader = NULL;

        // ... and another
        cout << endl << "parserTest7.osrl" << endl;
        osrlwriter = new OSrLWriter();
        osrlreader = new OSrLReader();
        cout << "FIRST READ THE OSrL FILE INTO A STRING" << endl;
        //errorExample.osrl -- check to see if we read an error message correctly;
        osrlFileName = dataDir  + "osrlFiles" + dirsep + "parserTest7.osrl"; 
        osrl = fileUtil->getFileAsString( osrlFileName.c_str() );
        finish = clock();
        duration = (double) (finish - start) / CLOCKS_PER_SEC;
        cout << "Reading the file into a string took (seconds): "<< duration << endl;
        cout << "PARSE THE OSRL STRING INTO AN OSRESULT OBJECT" << endl;
        osresult = osrlreader->readOSrL( osrl);
        cout << "WRITE THE OSRESULT OBJECT INTO A NEW OSRL STRING" << endl;
        tmpOSrL = osrlwriter->writeOSrL( osresult) ;
        delete osrlreader;
        osrlreader = new OSrLReader();
        cout << "PARSE THE NEW OSRL STRING INTO AN OSRESULT OBJECT" << endl;
        osrlreader->readOSrL( tmpOSrL);
        delete osrlwriter;
        osrlwriter = NULL;
        delete osrlreader;
        osrlreader = NULL;

        // ... and another
        cout << endl << "parserTest8.osrl" << endl;
        osrlwriter = new OSrLWriter();
        osrlreader = new OSrLReader();
        cout << "FIRST READ THE OSrL FILE INTO A STRING" << endl;
        //errorExample.osrl -- check to see if we read an error message correctly;
        osrlFileName = dataDir  + "osrlFiles" + dirsep + "parserTest8.osrl"; 
        osrl = fileUtil->getFileAsString( osrlFileName.c_str() );
        finish = clock();
        duration = (double) (finish - start) / CLOCKS_PER_SEC;
        cout << "Reading the file into a string took (seconds): "<< duration << endl;
        cout << "PARSE THE OSRL STRING INTO AN OSRESULT OBJECT" << endl;
        osresult = osrlreader->readOSrL( osrl);
        cout << "WRITE THE OSRESULT OBJECT INTO A NEW OSRL STRING" << endl;
        tmpOSrL = osrlwriter->writeOSrL( osresult) ;
        delete osrlreader;
        osrlreader = new OSrLReader();
        cout << "PARSE THE NEW OSRL STRING INTO AN OSRESULT OBJECT" << endl;
        osrlreader->readOSrL( tmpOSrL);
        delete osrlwriter;
        osrlwriter = NULL;
        delete osrlreader;
        osrlreader = NULL;

        // ... and another
        cout << endl << "parserTest9.osrl" << endl;
        osrlwriter = new OSrLWriter();
        osrlreader = new OSrLReader();
        cout << "FIRST READ THE OSrL FILE INTO A STRING" << endl;
        //errorExample.osrl -- check to see if we read an error message correctly;
        osrlFileName = dataDir  + "osrlFiles" + dirsep + "parserTest9.osrl"; 
        osrl = fileUtil->getFileAsString( osrlFileName.c_str() );
        finish = clock();
        duration = (double) (finish - start) / CLOCKS_PER_SEC;
        cout << "Reading the file into a string took (seconds): "<< duration << endl;
        cout << "PARSE THE OSRL STRING INTO AN OSRESULT OBJECT" << endl;
        osresult = osrlreader->readOSrL( osrl);
        cout << "WRITE THE OSRESULT OBJECT INTO A NEW OSRL STRING" << endl;
        tmpOSrL = osrlwriter->writeOSrL( osresult) ;
        delete osrlreader;
        osrlreader = new OSrLReader();
        cout << "PARSE THE NEW OSRL STRING INTO AN OSRESULT OBJECT" << endl;
        osrlreader->readOSrL( tmpOSrL);
        delete osrlwriter;
        osrlwriter = NULL;
        delete osrlreader;
        osrlreader = NULL;




        // ... last file...
        cout << endl << "parserTest10.osrl" << endl;
        osrlwriter = new OSrLWriter();
        osrlreader = new OSrLReader();
        cout << "FIRST READ THE OSrL FILE INTO A STRING" << endl;
        //errorExample.osrl -- check to see if we read an error message correctly;
        osrlFileName = dataDir  + "osrlFiles" + dirsep + "parserTest10.osrl"; 
        osrl = fileUtil->getFileAsString( osrlFileName.c_str() );
        finish = clock();
        duration = (double) (finish - start) / CLOCKS_PER_SEC;
        cout << "Reading the file into a string took (seconds): "<< duration << endl;
        cout << "PARSE THE OSRL STRING INTO AN OSRESULT OBJECT" << endl;
        osresult = osrlreader->readOSrL( osrl);
        cout << "WRITE THE OSRESULT OBJECT INTO A NEW OSRL STRING" << endl;
        tmpOSrL = osrlwriter->writeOSrL( osresult) ;
        delete osrlreader;
        osrlreader = new OSrLReader();
        cout << "PARSE THE NEW OSRL STRING INTO AN OSRESULT OBJECT" << endl;
        osrlreader->readOSrL( tmpOSrL);
        delete osrlwriter;
        osrlwriter = NULL;
        delete osrlreader;
        osrlreader = NULL;
*/
        unitTestResult << 
             "TEST " << nOfTest << ": Successful test of OSrL parser on file parserTest.osrl" 
              << std::endl;
        cout << endl << "TEST " << nOfTest << ": Completed successfully" << endl << endl;
    }    
    catch(const ErrorClass& eclass)
    {
        unitTestResultFailure << eclass.errormsg << endl;
        unitTestResultFailure << "There was a failure in the test for reading OSrL" << endl;

        if(osrlwriter != NULL) delete osrlwriter;
        osrlwriter = NULL;
        if(osrlreader != NULL) delete osrlreader;
        osrlreader = NULL;
        if (fileUtil != NULL)
            delete fileUtil;
        fileUtil = NULL;
    }

    if (intArray !=NULL) 
    {
        delete[] intArray;
        intArray = NULL;
    }

} // end  #if PARSER_TESTS


if (SOLVER_TESTS){
    try{
        cout << endl << "TEST " << ++nOfTest << ": Clp solver on parincLinearByRow.osil" << endl << endl;

        osilreader = new OSiLReader(); 
        osolreader = new OSoLReader(); 
        solver = new CoinSolver();
        osilwriter = new OSiLWriter();
        osrlreader =  new OSrLReader();
        fileUtil = new FileUtil();

        ok = true; 
        std::cout << "create a new COIN Clp for OSiL string solution" << std::endl;
        osilFileName = dataDir  + "osilFiles" + dirsep + "parincLinearByRow.osil";
        osolFileName = dataDir  + "osolFiles" + dirsep + "parincLinearByRow_clp.osol";
        osil = fileUtil->getFileAsString( osilFileName.c_str());
        osol = fileUtil->getFileAsString( osolFileName.c_str());

        solver->sSolverName = "clp";
        solver->osinstance = osilreader->readOSiL( osil);
        std::cout << " Done reading the OSiL" << std::endl;
        // now write it again as a string
        osilwriter->m_bWhiteSpace = true;
        std::cout << " Write the OSiL" << std::endl;
        osil = osilwriter->writeOSiL( solver->osinstance) ;
        //std::cout <<  osil  << std::endl;
        std::cout << " Done writing the OSiL" << std::endl;
        solver->osoption   = osolreader->readOSoL( osol);
        cout << "call the COIN - clp Solver for parincLinearbyRow" << endl;
        //solver->buildSolverInstance();
        std::cout << "call solver" << std::endl;
        solver->solve();
        std::cout << "returned from solver" << std::endl;
        check = 7668;
        ok = ( fabs(check - getObjVal( solver->osrl) )/(fabs( check) + OS_NEAR_EQUAL) <= OS_NEAR_EQUAL) ? true : false;
        if (ok)
        {    
#ifdef DEBUG
            cout << solver->osrl << endl;
#endif
            cout << "COIN clp solver solution for parincLinearByRow checks." << endl;        
        }
        else
        {    cout << "COIN clp solver solution for parincLinearByRow in error:" << endl;
            cout << solver->osrl << endl;
        }
        if(ok == false) throw ErrorClass(" Fail unit test with clp on parincLinearByRow.osil");
        // parse the osrl file
#ifdef DEBUG
        cout << "\nThe osrl file:\n" << solver->osrl << endl;
        cout << "Start parsing the file" << endl;
#endif
        osrlreader->readOSrL( solver->osrl);
#ifdef DEBUG
        cout << "read successfully" << endl;
#endif
        delete osilreader;
        osilreader = NULL;    
#ifdef DEBUG
        cout << "osilreader successfully deleted" << endl;
#endif
        delete osolreader;
        osolreader = NULL;    
#ifdef DEBUG
        cout << "osolreader successfully deleted" << endl;
#endif
        delete solver;
        solver = NULL;
#ifdef DEBUG
        cout << "solver successfully deleted" << endl;
#endif
        delete osilwriter;
        osilwriter = NULL;
#ifdef DEBUG
        cout << "osilwriter successfully deleted" << endl;
#endif
        delete osrlreader;
        osrlreader = NULL;
#ifdef DEBUG
        cout << "osrlreader successfully deleted" << endl;
#endif        
        delete fileUtil;
        fileUtil = NULL;

        unitTestResult << "TEST " << nOfTest << ": Solved problem parincLinearByRow.osil with Clp" << std::endl;
        cout << endl << "TEST " << nOfTest << ": Completed successfully" << endl << endl;
    }
    catch(const ErrorClass& eclass){
        unitTestResultFailure << "Sorry Unit Test Failed Testing Clp Solver:"  + eclass.errormsg<< endl;

        if (osilreader != NULL)
            delete osilreader;
        osilreader = NULL;    
        if (osolreader != NULL)
            delete osolreader;
        osolreader = NULL;   
        if (solver != NULL)
            delete solver;
        solver = NULL;
        if (osilwriter != NULL)
            delete osilwriter;
        osilwriter = NULL;
        if (osrlreader != NULL)
            delete osrlreader;
        osrlreader = NULL;
        if (fileUtil != NULL)
            delete fileUtil;
        fileUtil = NULL;
    }

    CoinSolver *cSolver = new CoinSolver();
    try
    {
        cout << endl << "TEST " << ++nOfTest << ": Clp warmstart tests with parincLinear.osil" << endl << endl;

/* we test
 * 1. simply sizing the warmstart
 * 2. putting a complete advanced basis
 * 3. putting a partial basis
 * 4. giving unusual statuses
 * 5. over-saturating the basis
 * 6. retrieving the optimal basis and using it as a start
 */
        fileUtil = new FileUtil();
        int* bv;
        int* bc;

        ok = true; 



        std::cout << "simply size the warmstart" << std::endl;
        osilFileName = dataDir  + "osilFiles" + dirsep + "parincLinear.osil";

        cSolver->sSolverName = "clp";
        cSolver->osil = fileUtil->getFileAsString( osilFileName.c_str());
        cSolver->osoption = new OSOption();
        cSolver->osoption->optimization = new OptimizationOption();
        cSolver->osoption->optimization->variables = new VariableOption();
        cSolver->osoption->optimization->variables->initialBasisStatus = new BasisStatus();
        cSolver->osoption->optimization->constraints = new ConstraintOption();
        cSolver->osoption->optimization->constraints->initialBasisStatus = new BasisStatus();
        ok &= cSolver->osoption->setAnotherSolverOption("primalSimplex", "true", "osi", "", "bool", "");

        std::cout << "call the COIN - clp Solver for parincLinear" << std::endl;
        cSolver->solve();
        std::cout << "returned from solver" << std::endl;
        check = 7668;
        ok &= ( fabs(check - getObjVal( cSolver->osrl) )/(fabs( check) + OS_NEAR_EQUAL) <= OS_NEAR_EQUAL);
        ok &= ( getItCount(cSolver->osrl) == 3);
        if (ok)
        {    
            cout << "COIN clp solver interface passes initial warmstart test." << endl;        
        }
        else
        {
            cout << "COIN clp solver interface warmstart error:" << endl;
            cout << cSolver->osrl << endl;
        }

        if(ok == false) throw ErrorClass(" Fail unit test with clp warmstarts on parincLinear.osil");
        delete cSolver;



        std::cout << "put a complete advanced basis" << std::endl;
        cSolver = new CoinSolver();
        cSolver->sSolverName = "clp";
        cSolver->osil = fileUtil->getFileAsString( osilFileName.c_str());
        cSolver->osoption = new OSOption();
        cSolver->osoption->optimization = new OptimizationOption();
        cSolver->osoption->optimization->variables = new VariableOption();
        cSolver->osoption->optimization->variables->initialBasisStatus = new BasisStatus();
        cSolver->osoption->optimization->constraints = new ConstraintOption();
        cSolver->osoption->optimization->constraints->initialBasisStatus = new BasisStatus();


        bv = new int[2];
        bv[0] = 0;
        bv[1] = 1;
        ok &= cSolver->osoption->setInitBasisStatus(ENUM_PROBLEM_COMPONENT_variables,  ENUM_BASIS_STATUS_basic, bv, 2); 
        ok &= cSolver->osoption->setInitBasisStatus(ENUM_PROBLEM_COMPONENT_constraints,ENUM_BASIS_STATUS_basic, bv, 2); 
        delete [] bv;

        bc = new int[1];
        bc[0] = 2;
        ok &= cSolver->osoption->setInitBasisStatus(ENUM_PROBLEM_COMPONENT_constraints,ENUM_BASIS_STATUS_atUpper, bc, 1); 
        bc[0] = 3;
        ok &= cSolver->osoption->setInitBasisStatus(ENUM_PROBLEM_COMPONENT_constraints,ENUM_BASIS_STATUS_atLower, bc, 1); 
        delete [] bc;

        if(ok == false) throw ErrorClass(" Fail setting warmstart advanced basis for clp");

        std::cout << "call the COIN - clp Solver" << std::endl;
        cSolver->solve();
        std::cout << "returned from solver" << std::endl;
        check = 7668;
        ok &= ( fabs(check - getObjVal( cSolver->osrl) )/(fabs( check) + OS_NEAR_EQUAL) <= OS_NEAR_EQUAL);
        ok &= ( getItCount(cSolver->osrl) == 3);

        if (ok)
        {    
            cout << "COIN clp solver interface passes complete basis warmstart test." << endl;        
        }
        else
        {
            cout << "COIN clp solver interface warmstart error:" << endl;
            cout << cSolver->osrl << endl;
        }

        if(ok == false) throw ErrorClass(" Fail unit test with clp warmstarts on parincLinear.osil");
        delete cSolver;



        std::cout << "put a partial basis" << std::endl;
        cSolver = new CoinSolver();
        cSolver->sSolverName = "clp";
        cSolver->osil = fileUtil->getFileAsString( osilFileName.c_str());
        cSolver->osoption = new OSOption();
        cSolver->osoption->optimization = new OptimizationOption();
        cSolver->osoption->optimization->variables = new VariableOption();
        cSolver->osoption->optimization->variables->initialBasisStatus = new BasisStatus();
        cSolver->osoption->optimization->constraints = new ConstraintOption();
        cSolver->osoption->optimization->constraints->initialBasisStatus = new BasisStatus();

        bv = new int[1];
        bv[0] = 1;
        ok &= cSolver->osoption->setInitBasisStatus(ENUM_PROBLEM_COMPONENT_variables,  ENUM_BASIS_STATUS_basic, bv, 1); 
        bv[0] = 2;
        ok &= cSolver->osoption->setInitBasisStatus(ENUM_PROBLEM_COMPONENT_constraints,ENUM_BASIS_STATUS_basic, bv, 1); 
        delete [] bv;

        if(ok == false) throw ErrorClass(" Fail setting warmstart partial basis for clp");
        std::cout << "call the COIN - clp Solver" << std::endl;
        cSolver->solve();
        std::cout << "returned from solver" << std::endl;
        check = 7668;
        ok &= ( fabs(check - getObjVal( cSolver->osrl) )/(fabs( check) + OS_NEAR_EQUAL) <= OS_NEAR_EQUAL);
        ok &= ( getItCount(cSolver->osrl) == 4);
        if (ok)
        {    
            cout << "COIN clp solver interface passes partial basis warmstart test." << endl;        
        }
        else
        {
            cout << "COIN clp solver interface warmstart error:" << endl;
            cout << cSolver->osrl << endl;
        }

        if(ok == false) throw ErrorClass(" Fail unit test with clp warmstarts on parincLinear.osil");
        delete cSolver;



        std::cout << "test unusual basis statuses" << std::endl;
        cSolver = new CoinSolver();
        cSolver->sSolverName = "clp";
        cSolver->osil = fileUtil->getFileAsString( osilFileName.c_str());
        cSolver->osoption = new OSOption();
        cSolver->osoption->optimization = new OptimizationOption();
        cSolver->osoption->optimization->variables = new VariableOption();
        cSolver->osoption->optimization->variables->initialBasisStatus = new BasisStatus();
        cSolver->osoption->optimization->constraints = new ConstraintOption();
        cSolver->osoption->optimization->constraints->initialBasisStatus = new BasisStatus();

        bv = new int[2];
        bv[0] = 0;
        bv[1] = 1;
        ok &= cSolver->osoption->setInitBasisStatus(ENUM_PROBLEM_COMPONENT_variables,  ENUM_BASIS_STATUS_superbasic, bv, 2); 
        ok &= cSolver->osoption->setInitBasisStatus(ENUM_PROBLEM_COMPONENT_constraints,ENUM_BASIS_STATUS_superbasic, bv, 2); 
        delete [] bv;

        bc = new int[1];
        bc[0] = 2;
        ok &= cSolver->osoption->setInitBasisStatus(ENUM_PROBLEM_COMPONENT_constraints,ENUM_BASIS_STATUS_atEquality, bc, 1); 
        bc[0] = 3;
        ok &= cSolver->osoption->setInitBasisStatus(ENUM_PROBLEM_COMPONENT_constraints,ENUM_BASIS_STATUS_unknown, bc, 1); 
        delete [] bc;

        if(ok == false) throw ErrorClass(" Fail setting unusual basis statuses for clp");
        std::cout << "call the COIN - clp Solver" << std::endl;
        cSolver->solve();
        std::cout << "returned from solver" << std::endl;
        check = 7668;
        ok &= ( fabs(check - getObjVal( cSolver->osrl) )/(fabs( check) + OS_NEAR_EQUAL) <= OS_NEAR_EQUAL);
        ok &= ( getItCount(cSolver->osrl) == 3);
        if (ok)
        {    
            cout << "COIN clp solver interface passes unusual basis warmstart test." << endl;        
        }
        else
        {
            cout << "COIN clp solver interface warmstart error:" << endl;
            cout << cSolver->osrl << endl;
        }

        if(ok == false) throw ErrorClass(" Fail unit test with clp warmstarts on parincLinear.osil");
        delete cSolver;



        std::cout << "test over-saturated basis" << std::endl;
        cSolver = new CoinSolver();
        cSolver->sSolverName = "clp";
        cSolver->osil = fileUtil->getFileAsString( osilFileName.c_str());
        cSolver->osoption = new OSOption();
        cSolver->osoption->optimization = new OptimizationOption();
        cSolver->osoption->optimization->variables = new VariableOption();
        cSolver->osoption->optimization->variables->initialBasisStatus = new BasisStatus();
        cSolver->osoption->optimization->constraints = new ConstraintOption();
        cSolver->osoption->optimization->constraints->initialBasisStatus = new BasisStatus();

        bv = new int[2];
        bv[0] = 0;
        bv[1] = 1;
        bc = new int[4];
        bc[0] = 3;
        bc[1] = 1;
        bc[2] = 0;
        bc[3] = 2;
        ok &= cSolver->osoption->setInitBasisStatus(ENUM_PROBLEM_COMPONENT_variables,  ENUM_BASIS_STATUS_basic, bv, 2); 
        ok &= cSolver->osoption->setInitBasisStatus(ENUM_PROBLEM_COMPONENT_constraints,ENUM_BASIS_STATUS_basic, bc, 4); 
        delete [] bv;
        delete [] bc;

        if(ok == false) throw ErrorClass(" Fail setting over-saturated basis for clp");
        std::cout << "call the COIN - clp Solver" << std::endl;
        cSolver->solve();
        std::cout << "returned from solver" << std::endl;
        check = 7668;
        ok &= ( fabs(check - getObjVal( cSolver->osrl) )/(fabs( check) + OS_NEAR_EQUAL) <= OS_NEAR_EQUAL);
        ok &= ( getItCount(cSolver->osrl) == 3);
        if (ok)
        {    
            cout << "COIN clp solver interface passes over-saturated basis warmstart test." << endl;        
        }
        else
        {
            cout << "COIN clp solver interface warmstart error:" << endl;
            cout << cSolver->osrl << endl;
        }
        cout << cSolver->osrl << endl;
        if(ok == false) throw ErrorClass(" Fail unit test with clp warmstarts on parincLinear.osil");
        delete cSolver;



        std::cout << "test using optimal basis" << std::endl;
        cSolver = new CoinSolver();
        cSolver->sSolverName = "clp";
        cSolver->osil = fileUtil->getFileAsString( osilFileName.c_str());
        cSolver->osoption = new OSOption();
        cSolver->osoption->optimization = new OptimizationOption();
        cSolver->osoption->optimization->variables = new VariableOption();
        cSolver->osoption->optimization->variables->initialBasisStatus = new BasisStatus();
        cSolver->osoption->optimization->constraints = new ConstraintOption();
        cSolver->osoption->optimization->constraints->initialBasisStatus = new BasisStatus();

        int* vbasis;
        int retCode;

        bv = new int[2];
        bv[0] = 0;
        bv[1] = 1;
        ok &= cSolver->osoption->setInitBasisStatus(ENUM_PROBLEM_COMPONENT_variables,  ENUM_BASIS_STATUS_basic, bv, 2); 
        bv[0] = 1;
        bv[1] = 3;
        ok &= cSolver->osoption->setInitBasisStatus(ENUM_PROBLEM_COMPONENT_constraints,ENUM_BASIS_STATUS_basic, bv, 2); 
        bv[0] = 0;
        bv[1] = 2;
        ok &= cSolver->osoption->setInitBasisStatus(ENUM_PROBLEM_COMPONENT_constraints,ENUM_BASIS_STATUS_atLower, bv, 2); 
        delete [] bv;

        double* iv = new double[2];
        iv[0] = 539.9999999999999;
        iv[1] = 252.0000000000001;
        ok &= cSolver->osoption->setInitVarValuesDense(2,iv);
        if (!ok) throw ErrorClass(" Fail setting starting values during warmstart tests");
        delete [] iv;

        std::cout << "call the COIN - clp Solver" << std::endl;
        cSolver->solve();
        std::cout << "returned from solver" << std::endl;
        check = 7668;
        ok &= ( fabs(check - getObjVal( cSolver->osrl) )/(fabs( check) + OS_NEAR_EQUAL) <= OS_NEAR_EQUAL);
        ok &= ( getItCount(cSolver->osrl) == 0);

        if (ok)
        {    
            cout << "COIN clp solver interface passes warmstart from optimal basis." << endl;        
        }
        else
        {
            cout << "COIN clp solver interface warmstart error:" << endl;
            cout << cSolver->osrl << endl;
        }

        cout << cSolver->osrl << endl;
        if(ok == false) throw ErrorClass(" Fail unit test with clp warmstarts on parincLinear.osil");





        delete cSolver;
        cSolver = NULL;
#ifdef DEBUG
        cout << "solver successfully deleted" << endl;
#endif
        delete fileUtil;
        fileUtil = NULL;

        unitTestResult << "TEST " << nOfTest << ": Warmstarts for problem parincLinear.osil with Clp" << std::endl;
        cout << endl << "TEST " << nOfTest << ": Completed successfully" << endl << endl;
    }
    catch(const ErrorClass& eclass){
        unitTestResultFailure << "Sorry Unit Test Failed Testing Clp Solver Warmstarts:"  + eclass.errormsg<< endl;

        if (cSolver != NULL)
            delete cSolver;
        cSolver = NULL;
        if (fileUtil != NULL)
            delete fileUtil;
        fileUtil = NULL;
    }


    // now solve another problem -- try an integer program
    try{
        cout << endl << "TEST " << ++nOfTest << ": Cbc solver on p0033.osil" << endl << endl;

        fileUtil = new FileUtil();
        osilreader = new OSiLReader(); 
        osolreader = new OSoLReader(); 
        solver = new CoinSolver();

        std::cout << "create a new COIN Cbc for OSiL string solution" << std::endl;
        ok = true;
        osilFileName = dataDir  + "osilFiles" + dirsep + "p0033.osil";
        //osolFileName = dataDir  + "osolFiles" + dirsep + "p0033_cbc.osol";
        osil = fileUtil->getFileAsString( osilFileName.c_str());
        //osol = fileUtil->getFileAsString( osolFileName.c_str());
        osol = "";
        solver->sSolverName ="cbc";
        solver->osil = osil;
        solver->osol = osol;  
        solver->osinstance = NULL; 
        solver->osoption   = NULL;
        cout << "call the COIN - Cbc Solver for p0033" << endl;
        solver->buildSolverInstance();
        solver->solve();
        check = 3089;
        ok = ( fabs(check - getObjVal( solver->osrl) )/(fabs( check) + OS_NEAR_EQUAL) <= OS_NEAR_EQUAL) ? true : false;
        if (ok)
        {    
#ifdef DEBUG
            cout << solver->osrl << endl;
#endif
            cout << "Coin cbc solution for p0033 checks" << endl;
        }
        else
        {    cout << "Coin cbc solution for p0033 in error:" << endl;
            cout << solver->osrl << endl;
        }
        if (ok == false) throw ErrorClass(" Fail unit test with Cbc on p0033.osil");
        delete solver;
        solver = NULL;

        delete osilreader;
        osilreader = NULL;
        delete osolreader;
        osolreader = NULL;
        delete fileUtil;
        fileUtil = NULL;
        unitTestResult << "TEST " << nOfTest << ": Solved problem p0033.osil with Cbc" << std::endl;
        cout << endl << "TEST " << nOfTest << ": Completed successfully" << endl << endl;
    }
    catch(const ErrorClass& eclass){
        unitTestResultFailure << "Sorry Unit Test Failed Testing Cbc Solver:"  + eclass.errormsg<< endl;
        if (solver != NULL)
            delete solver;
        solver = NULL;
        if (osilreader != NULL)
            delete osilreader;
        osilreader = NULL;
        if (osolreader != NULL)
            delete osolreader;
        osolreader = NULL;
        if (fileUtil != NULL)
            delete fileUtil;
        fileUtil = NULL;
    }

if( THOROUGH == true){

    // now solve the same problem with a different instance representation --- using mult and incr
    try{
        cout << endl << "TEST " << ++nOfTest << ": Cbc solver on p0033MULT.osil" << endl << endl;

        osilreader = new OSiLReader(); 
        osolreader = new OSoLReader(); 
        solver = new CoinSolver();
        fileUtil = new FileUtil();

        std::cout << "create a new COIN Cbc for OSiL string solution" << std::endl;
        ok = true;
        osilFileName = dataDir  + "osilFiles" + dirsep + "p0033MULT.osil";
        //osolFileName = dataDir  + "osolFiles" + dirsep + "p0033_cbc.osol";
        osil = fileUtil->getFileAsString( osilFileName.c_str());
        //osol = fileUtil->getFileAsString( osolFileName.c_str());
        osol = "";
        solver->sSolverName ="cbc";
        solver->osil = osil;
        solver->osol = osol;  
        solver->osinstance = NULL; 
        solver->osoption   = NULL;
        cout << "call the COIN - Cbc Solver for p0033MULT" << endl;
        solver->buildSolverInstance();
        solver->solve();
        check = 3089;
        ok = ( fabs(check - getObjVal( solver->osrl) )/(fabs( check) + OS_NEAR_EQUAL) <= OS_NEAR_EQUAL) ? true : false;
        if (ok)
        {    
#ifdef DEBUG
            cout << solver->osrl << endl;
#endif
            cout << "Coin cbc solution for p0033MULT checks" << endl;
        }
        else
        {    cout << "Coin cbc solution for p0033MULT in error:" << endl;
            cout << solver->osrl << endl;
        }
        if (ok == false) throw ErrorClass(" Fail unit test with Cbc on p0033MULT.osil");
        delete solver;
        solver = NULL;
        delete osilreader;
        osilreader = NULL;
        delete osolreader;
        osolreader = NULL;
        delete fileUtil;
        fileUtil = NULL;
        unitTestResult << "TEST " << nOfTest << ": Solved problem p0033MULT.osil with Cbc" << std::endl;
        cout << endl << "TEST " << nOfTest << ": Completed successfully" << endl << endl;
    }
    catch(const ErrorClass& eclass){
        unitTestResultFailure << "Sorry Unit Test Failed Testing Cbc Solver:"  + eclass.errormsg<< endl;
        if (solver != NULL)
            delete solver;
        solver = NULL;
        if (osilreader != NULL)
            delete osilreader;
        osilreader = NULL;
        if (osolreader != NULL)
            delete osolreader;
        osolreader = NULL;
        if (fileUtil != NULL)
            delete fileUtil;
        fileUtil = NULL;
    }


    // now test p0201.osil
    try{
        cout << endl << "TEST " << ++nOfTest << ": Cbc solver on p0033.osil - node limit set" << endl << endl;

        fileUtil = new FileUtil();
        osilreader = new OSiLReader(); 
        osolreader = new OSoLReader(); 
        solver = new CoinSolver();

        ok = true;
        osilFileName = dataDir  + "osilFiles" + dirsep + "p0033.osil";
        osolFileName = dataDir  + "osolFiles" + dirsep + "p0033_cbc.osol";
        osil = fileUtil->getFileAsString( osilFileName.c_str());
        osol = fileUtil->getFileAsString( osolFileName.c_str());
        solver->sSolverName ="cbc";
        solver->osil = osil;
        solver->osol = osol;  
        solver->osinstance = NULL; 
        solver->osoption   = NULL;
        cout << "call the COIN - Cbc Solver for p0033" << endl;
        solver->buildSolverInstance();
        solver->solve();
        //cout << "Here is the COIN Cbc solver solution for p0033" << endl;
        //cout << solver->osrl << endl;
        if( solver->osrl.find("node limit reached") != std::string::npos)
            ok = true;
        else
            ok = false;
        if (ok == false) throw ErrorClass(" node limit option on p0033.osil not processed properly");
        delete solver;
        solver = NULL;
        delete osilreader;
        osilreader = NULL;
        delete osolreader;
        osolreader = NULL;
        delete fileUtil;
        fileUtil = NULL;
        unitTestResult << "TEST " << nOfTest << ": Solved problem p0033.osil with Cbc node limit" << std::endl;
        cout << endl << "TEST " << nOfTest << ": Completed successfully" << endl << endl;
    }
    catch(const ErrorClass& eclass){
        unitTestResultFailure << "Sorry Unit Test Failed Testing Cbc Solver:"  + eclass.errormsg<< endl;
        if (solver != NULL)
            delete solver;
        solver = NULL;
        if (osilreader != NULL)
            delete osilreader;
        osilreader = NULL;
        if (osolreader != NULL)
            delete osolreader;
        osolreader = NULL;
        if (fileUtil != NULL)
            delete fileUtil;
        fileUtil = NULL;
    }


    try{
        cout << endl << "TEST " << ++nOfTest << ": Cbc solver on p0201.osil" << endl << endl;

        fileUtil = new FileUtil();
        osilreader = new OSiLReader(); 
        osolreader = new OSoLReader(); 
        solver = new CoinSolver();

        ok = true;
        osilFileName = dataDir  + "osilFiles" + dirsep + "p0201.osil";
        osolFileName = dataDir  + "osolFiles" + dirsep + "p0201_cbc.osol";
        osil = fileUtil->getFileAsString( osilFileName.c_str());
        osol = fileUtil->getFileAsString( osolFileName.c_str());
        solver->sSolverName ="cbc";
        solver->osil = osil;
        solver->osol = osol;  
        solver->osinstance = NULL; 
        solver->osoption   = NULL;
        cout << "call the COIN - Cbc Solver for p0201" << endl;
        solver->solve();
        cout << "Here is the COIN Cbc solver solution for p0201" << endl;
        std::cout << solver->osrl << std::endl;
        check = 7615;
        // we put a node limit in, so we should not find 7615
        // check that the node limit was found
        string::size_type pos;
        pos = solver->osrl.find( "node limit");
        if(pos == std::string::npos)  throw ErrorClass(" Error with p0201 on Cbc");
        //ok &= NearEqual(getObjVal( solver->osrl) , check,  1e-10 , 1e-10);
        //ok = ( fabs(check - getObjVal( solver->osrl) )/(fabs( check) + OS_NEAR_EQUAL) <= OS_NEAR_EQUAL) ? true : false;
        //if(ok == false) throw ErrorClass(" Fail unit test with Cbc on p0201.osil");
        delete solver;
        solver = NULL;
        delete osilreader;
        osilreader = NULL;
        delete osolreader;
        osolreader = NULL;
        delete fileUtil;
        fileUtil = NULL;
        unitTestResult << "TEST " << nOfTest << ": Solved problem p0201.osil with Cbc" << std::endl;
        cout << endl << "TEST " << nOfTest << ": Completed successfully" << endl << endl;
    }
    catch(const ErrorClass& eclass){
        unitTestResultFailure << "Sorry Unit Test Failed Testing Cbc Solver:"  + eclass.errormsg<< endl;
        if (solver != NULL)
            delete solver;
        solver = NULL;
        if (osilreader != NULL)
            delete osilreader;
        osilreader = NULL;
        if (osolreader != NULL)
            delete osolreader;
        osolreader = NULL;
        if (fileUtil != NULL)
            delete fileUtil;
        fileUtil = NULL;
    }

    try{
        cout << endl << "TEST " << ++nOfTest << ": Cbc solver on parincInteger.osil" << endl << endl;

        fileUtil = new FileUtil();
        osilreader = new OSiLReader(); 
        osolreader = new OSoLReader(); 
        solver = new CoinSolver();

        ok = true;
        osilFileName = dataDir  + "osilFiles" + dirsep + "parincInteger.osil";
        osolFileName = dataDir  + "osolFiles" + dirsep + "parincInteger_cbc.osol";
        osil = fileUtil->getFileAsString( osilFileName.c_str());
        osol = fileUtil->getFileAsString( osolFileName.c_str());
        solver->sSolverName ="cbc";
        cout << "parse OSiL file" << endl;
        solver->osinstance = osilreader->readOSiL( osil);
        solver->osol = osol; 
        cout << "call the COIN - Cbc Solver for parincInteger" << endl;
//        solver->buildSolverInstance();
        solver->solve();
        check = 7668;
        ok = ( fabs(check - getObjVal( solver->osrl) )/(fabs( check) + OS_NEAR_EQUAL) <= OS_NEAR_EQUAL) ? true : false;
        if (ok)
        {    
#ifdef DEBUG
            cout << solver->osrl << endl;
#endif
            cout << "COIN cbc solver solution for parincInteger checks." << endl;


        }
        else
        {    cout << "COIN cbc solver solution for parincInteger in error:" << endl;
            cout << solver->osrl << endl;
        }
        if(ok == false) throw ErrorClass(" Fail unit test with Cbc on parincInteger.osil");
        delete osilreader;
        osilreader = NULL;    
        delete osolreader;
        osolreader = NULL;    
        delete solver;
        solver = NULL;
        delete fileUtil;
        fileUtil = NULL;
        unitTestResult << "TEST " << nOfTest << ": Solved problem parincInteger.osil with Cbc" << std::endl;
        cout << endl << "TEST " << nOfTest << ": Completed successfully" << endl << endl;
    }
    catch(const ErrorClass& eclass){
        unitTestResultFailure << "Sorry Unit Test Failed Testing Cbc Solver:"  + eclass.errormsg<< endl;
        if (solver != NULL)
            delete solver;
        solver = NULL;
        if (osilreader != NULL)
            delete osilreader;
        osilreader = NULL;
        if (osolreader != NULL)
            delete osolreader;
        osolreader = NULL;
        if (fileUtil != NULL)
            delete fileUtil;
        fileUtil = NULL;
    }
}    // end of if(THOROUGH)

#ifdef COIN_HAS_SYMPHONY
    try{
        cout << endl << "TEST " << ++nOfTest << ": SYMPHONY solver on p0033.osil" << endl << endl;

        fileUtil = new FileUtil();
        osolreader = new OSoLReader(); 
        solver = new CoinSolver();

        ok = true; 
        osilFileName = dataDir  + "osilFiles" + dirsep + "p0033.osil";
        osolFileName = dataDir  + "osolFiles" + dirsep + "p0033_sym.osol";
        osil = fileUtil->getFileAsString( osilFileName.c_str());
        osol = fileUtil->getFileAsString( osolFileName.c_str());
        solver->sSolverName = "symphony";
        solver->osil = osil;
        solver->osinstance = NULL; 
        solver->osoption   = osolreader->readOSoL( osol);
        cout << "build the solver instance for COIN - SYMPHONY" << endl;
        solver->buildSolverInstance();
//        cout << "call the COIN - SYMPHONY Solver for p0033" << endl;
        solver->solve();
        check = 3089;
        //ok &= NearEqual(getObjVal( solver->osrl) , check,  1e-10 , 1e-10);
        ok = ( fabs(check - getObjVal( solver->osrl) )/(fabs( check) + OS_NEAR_EQUAL) <= OS_NEAR_EQUAL) ? true : false;
        if (ok)
        {    
#ifdef DEBUG
            cout << solver->osrl << endl;
#endif
            cout << "COIN SYMPHONY solver solution for p0033 checks." << endl;
        }
        else
        {    cout << "COIN SYMPHONY solver solution for p0033 in error:" << endl;
            cout << solver->osrl << endl;
        }
        if(ok == false) throw ErrorClass(" Fail unit test with SYMPHONY on p0033.osil");
        delete solver;
        solver = NULL;
        delete osolreader;
        osolreader = NULL;    
        delete fileUtil;
        fileUtil = NULL;
        unitTestResult << "TEST " << nOfTest << ": Solved problem p0033.osil with SYMPHONY" << std::endl;
        cout << endl << "TEST " << nOfTest << ": Completed successfully" << endl << endl;
    }
    catch(const ErrorClass& eclass){
        unitTestResultFailure  << "Sorry Unit Test Failed Testing the SYMPHONY Solver:"  + eclass.errormsg << endl;
        if (solver != NULL)
            delete solver;
        solver = NULL;
        if (osolreader != NULL)
            delete osolreader;
        osolreader = NULL;
        if (fileUtil != NULL)
            delete fileUtil;
        fileUtil = NULL;
    }    
#endif
    


#ifdef COIN_HAS_DYLP
    try{
        cout << endl << "TEST " << ++nOfTest << ": DyLP solver on parincLinear.osil" << endl << endl;

        fileUtil = new FileUtil();
        osilreader = new OSiLReader(); 
        solver = new CoinSolver();

        ok = true; 
        osilFileName = dataDir  + "osilFiles" + dirsep + "parincLinear.osil";
        osolFileName = dataDir  + "osolFiles" + dirsep + "parincLinear_dylp.osol";
        osil = fileUtil->getFileAsString( osilFileName.c_str());
        osol = fileUtil->getFileAsString( osolFileName.c_str());
        solver->sSolverName = "dylp";
        solver->osol = osol;   
        solver->osinstance = osilreader->readOSiL( osil);
        cout << "call the COIN - DyLP solver for parincLinear" << endl;
        solver->buildSolverInstance();
        solver->solve();
        check = 7668;
        //ok &= NearEqual(getObjVal( solver->osrl) , check,  1e-1 , 1e-1);
        ok = ( fabs(check - getObjVal( solver->osrl) )/(fabs( check) + OS_NEAR_EQUAL) <= OS_NEAR_EQUAL) ? true : false;
        if (ok)
        {    
#ifdef DEBUG
            cout << solver->osrl << endl;
#endif
            cout << "COIN DyLP solver solution for parincLinear checks." << endl;
        }
        else
        {    cout << "COIN DyLP solver solution for parincLinear in error:" << endl;
            cout << solver->osrl << endl;
        }
        if(ok == false) throw ErrorClass(" Fail unit test with DyLP on parincLinear.osil");
        delete solver;
        solver = NULL;
        delete osilreader;
        osilreader = NULL;    
        delete fileUtil;
        fileUtil = NULL;
        unitTestResult << "TEST " << nOfTest << ": Solved problem parincLinear.osil with DyLP" << std::endl;
        cout << endl << "TEST " << nOfTest << ": Completed successfully" << endl << endl;
    }
    catch(const ErrorClass& eclass){
        cout << "OSrL =  " <<  solver->osrl <<  endl;
        cout << endl << endl << endl;
        unitTestResultFailure  <<"Sorry Unit Test Failed Testing the DyLP Solver:"  + eclass.errormsg << endl;
        if (solver != NULL)
            delete solver;
        solver = NULL;
        if (osilreader != NULL)
            delete osilreader;
        osilreader = NULL;
        if (fileUtil != NULL)
            delete fileUtil;
        fileUtil = NULL;
    }    
#endif
    

#ifdef COIN_HAS_VOL
    try{
        cout << endl << "TEST " << ++nOfTest << ": Vol solver on volumeTest.osil" << endl << endl;

        fileUtil = new FileUtil();
        osolreader = new OSoLReader(); 
        solver = new CoinSolver();

        ok = true; 
        osilFileName = dataDir  + "osilFiles" + dirsep + "volumeTest.osil";
        osolFileName = dataDir  + "osolFiles" + dirsep + "volumeTest_vol.osol";
        osil = fileUtil->getFileAsString( osilFileName.c_str());
        osol = fileUtil->getFileAsString( osolFileName.c_str());
        solver->sSolverName = "vol";
        solver->osil = osil;
        solver->osinstance = NULL; 
        solver->osoption = osolreader->readOSoL( osol);
        cout << "call the COIN - Vol solver for volumeTest" << endl;
        solver->buildSolverInstance();
        solver->solve();
        check = 7;
        //ok &= NearEqual(getObjVal( solver->osrl) , check,  1e-1 , 1e-1);
        ok = ( fabs(check - getObjVal( solver->osrl) )/(fabs( check) + OS_NEAR_EQUAL) <= OS_NEAR_EQUAL) ? true : false;
        if (ok)
        {    
#ifdef DEBUG
            cout << solver->osrl << endl;
#endif
            cout << "COIN Vol solver solution for volumeTest checks." << endl;
        }
        else
        {    cout << "COIN Vol solver solution for volumeTest in error:" << endl;
            cout << solver->osrl << endl;
        }
        if(ok == false) throw ErrorClass(" Fail unit test with Vol on volumeTest.osil");
        delete solver;
        solver = NULL;
        delete osolreader;
        osolreader = NULL;    
        delete fileUtil;
        fileUtil = NULL;
        unitTestResult << "TEST " << nOfTest << ": Solved problem volumeTest.osil with Vol" << std::endl;
        cout << endl << "TEST " << nOfTest << ": Completed successfully" << endl << endl;
    }
    catch(const ErrorClass& eclass){
        cout << "OSrL =  " <<  solver->osrl <<  endl;
        cout << endl << endl << endl;
        unitTestResultFailure  <<"Sorry Unit Test Failed Testing the Vol Solver:"  + eclass.errormsg << endl;
        if (solver != NULL)
            delete solver;
        solver = NULL;
        if (osolreader != NULL)
            delete osolreader;
        osolreader = NULL;
        if (fileUtil != NULL)
            delete fileUtil;
        fileUtil = NULL;
    }    
#endif
    
#ifdef COIN_HAS_GLPK
    try{
        cout << endl << "TEST " << ++nOfTest << ": GLPK solver on p0033.osil" << endl << endl;

        fileUtil = new FileUtil();
        osilreader = new OSiLReader(); 
        osolreader = new OSoLReader(); 
        solver = new CoinSolver();

        ok = true; 
        osilFileName = dataDir  + "osilFiles" + dirsep + "p0033.osil";
        osolFileName = dataDir  + "osolFiles" + dirsep + "p0033_glpk.osol";
        osil = fileUtil->getFileAsString( osilFileName.c_str());
        osol = fileUtil->getFileAsString( osolFileName.c_str());
        solver->sSolverName = "glpk";
        solver->osinstance = osilreader->readOSiL( osil);
        solver->osoption   = osolreader->readOSoL( osol);
        cout << "call the GLPK Solver for p0033" << endl;
        solver->buildSolverInstance();
        solver->solve();
        check = 3089;
        //ok &= NearEqual(getObjVal( solver->osrl) , check,  1e-10 , 1e-10);
        ok = ( fabs(check - getObjVal( solver->osrl) )/(fabs( check) + OS_NEAR_EQUAL) <= OS_NEAR_EQUAL) ? true : false;
        if (ok)
        {    
#ifdef DEBUG
            cout << solver->osrl << endl;
#endif
            cout << "GLPK solver solution for p0033 checks." << endl;
        }
        else
        {    cout << "GLPK solver solution for p0033 in error:" << endl;
            cout << solver->osrl << endl;
        }
        if(ok == false) throw ErrorClass(" Fail unit test with GLPK on p0033.osil");
        delete solver;
        solver = NULL;
        delete osilreader;
        osilreader = NULL;    
        delete osolreader;
        osolreader = NULL;    
        delete fileUtil;
        fileUtil = NULL;
        unitTestResult << "TEST " << nOfTest << ": Solved problem p0033.osil with GLPK" << std::endl;
        cout << endl << "TEST " << nOfTest << ": Completed successfully" << endl << endl;
    }
    catch(const ErrorClass& eclass){
        cout << "OSrL =  " <<  solver->osrl <<  endl;
        cout << endl << endl << endl;
        unitTestResultFailure  <<"Sorry Unit Test Failed Testing the Glpk Solver:"  + eclass.errormsg << endl;
        if (solver != NULL)
            delete solver;
        solver = NULL;
        if (osilreader != NULL)
            delete osilreader;
        osilreader = NULL;
        if (osolreader != NULL)
            delete osolreader;
        osolreader = NULL;
        if (fileUtil != NULL)
            delete fileUtil;
        fileUtil = NULL;
    }    
#endif

#ifdef COIN_HAS_CPX
    try{
        cout << endl << "TEST " << ++nOfTest << ": Cplex solver on p0033.osil" << endl << endl;

        fileUtil = new FileUtil();
        solver = new CoinSolver();

        ok = true; 
        osilFileName = dataDir  + "osilFiles" + dirsep + "p0033.osil";
        osolFileName = dataDir  + "osolFiles" + dirsep + "p0033_cpx.osol";
        osil = fileUtil->getFileAsString( osilFileName.c_str());
        osol = fileUtil->getFileAsString( osolFileName.c_str());
        solver->sSolverName = "cplex";
        solver->osil = osil;
        solver->osol = osol;  
        solver->osinstance = NULL; 
        cout << "call the CPLEX Solver for p0033" << endl;
        solver->buildSolverInstance();
        solver->solve();
        check = 3089;
        //ok &= NearEqual(getObjVal( solver->osrl) , check,  1e-10 , 1e-10);
        ok = ( fabs(check - getObjVal( solver->osrl) )/(fabs( check) + OS_NEAR_EQUAL) <= OS_NEAR_EQUAL) ? true : false;
        if (ok)
        {    
#ifdef DEBUG
            cout << solver->osrl << endl;
#endif
            cout << "CPLEX solver solution for p0033 checks." << endl;
        }
        else
        {    cout << "CPLEX solver solution for p0033 in error:" << endl;
            cout << solver->osrl << endl;
        }
        if(ok == false) throw ErrorClass(" Fail unit test with CPLEX on p0033.osil");
        delete solver;
        solver = NULL;
        delete fileUtil;
        fileUtil = NULL;
        unitTestResult << "TEST " << nOfTest << ": Solved problem p0033.osil with CPLEX" << std::endl;
        cout << endl << "TEST " << nOfTest << ": Completed successfully" << endl << endl;
    }
    catch(const ErrorClass& eclass){
        cout << "OSrL =  " <<  solver->osrl <<  endl;
        cout << endl << endl << endl;
        unitTestResultFailure  <<"Sorry Unit Test Failed Testing the Cplex Solver:"  + eclass.errormsg << endl;
        if (solver != NULL)
            delete solver;
        solver = NULL;
        if (fileUtil != NULL)
            delete fileUtil;
        fileUtil = NULL;
    }    
#endif
    

#ifdef COIN_HAS_GRB
    try{
        cout << endl << "TEST " << ++nOfTest << ": Gurobi solver on p0033.osil" << endl << endl;

        fileUtil = new FileUtil();
        solver = new CoinSolver();

        ok = true; 
        osilFileName = dataDir  + "osilFiles" + dirsep + "p0033.osil";
        osolFileName = dataDir  + "osolFiles" + dirsep + "p0033_cpx.osol";
        osil = fileUtil->getFileAsString( osilFileName.c_str());
        osol = fileUtil->getFileAsString( osolFileName.c_str());
        solver->sSolverName = "gurobi";
        solver->osil = osil;
        solver->osol = osol;  
        solver->osinstance = NULL; 
        cout << "call the Gurobi Solver for p0033" << endl;
        solver->buildSolverInstance();
        solver->solve();
        check = 3089;
        //ok &= NearEqual(getObjVal( solver->osrl) , check,  1e-10 , 1e-10);
        ok = ( fabs(check - getObjVal( solver->osrl) )/(fabs( check) + OS_NEAR_EQUAL) <= OS_NEAR_EQUAL) ? true : false;
        if (ok)
        {    
#ifdef DEBUG
            cout << solver->osrl << endl;
#endif
            cout << "Gurobi solver solution for p0033 checks." << endl;
        }
        else
        {    cout << "Gurobi solver solution for p0033 in error:" << endl;
            cout << solver->osrl << endl;
        }
        if(ok == false) throw ErrorClass(" Fail unit test with Gurobi on p0033.osil");
        delete solver;
        solver = NULL;
        delete fileUtil;
        fileUtil = NULL;
        unitTestResult << "TEST " << nOfTest << ": Solved problem p0033.osil with Gurobi" << std::endl;
        cout << endl << "TEST " << nOfTest << ": Completed successfully" << endl << endl;
    }
    catch(const ErrorClass& eclass){
        cout << "OSrL =  " <<  solver->osrl <<  endl;
        cout << endl << endl << endl;
        unitTestResultFailure  <<"Sorry Unit Test Failed Testing the Gurobi Solver:"  + eclass.errormsg << endl;
        if (solver != NULL)
            delete solver;
        solver = NULL;
        if (fileUtil != NULL)
            delete fileUtil;
        fileUtil = NULL;
    }    
#endif

#ifdef COIN_HAS_MSK
    try{
        cout << endl << "TEST " << ++nOfTest << ": MOSEK solver on p0033.osil" << endl << endl;

        fileUtil = new FileUtil();
        solver = new CoinSolver();

        ok = true; 
        osilFileName = dataDir  + "osilFiles" + dirsep + "p0033.osil";
        osolFileName = dataDir  + "osolFiles" + dirsep + "p0033_cpx.osol";
        osil = fileUtil->getFileAsString( osilFileName.c_str());
        osol = fileUtil->getFileAsString( osolFileName.c_str());
        solver->sSolverName = "mosek";
        solver->osil = osil;
        solver->osol = osol;  
        solver->osinstance = NULL; 
        cout << "call the MOSEK Solver for p0033" << endl;
        solver->buildSolverInstance();
        solver->solve();
        check = 3089;
        //ok &= NearEqual(getObjVal( solver->osrl) , check,  1e-10 , 1e-10);
        ok = ( fabs(check - getObjVal( solver->osrl) )/(fabs( check) + OS_NEAR_EQUAL) <= OS_NEAR_EQUAL) ? true : false;
        if (ok)
        {    
#ifdef DEBUG
            cout << solver->osrl << endl;
#endif
            cout << "MOSEK solver solution for p0033 checks." << endl;
        }
        else
        {    cout << "MOSEK solver solution for p0033 in error:" << endl;
            cout << solver->osrl << endl;
        }
        if(ok == false) throw ErrorClass(" Fail unit test with MOSEK on p0033.osil");
        delete solver;
        solver = NULL;
        delete fileUtil;
        fileUtil = NULL;
        unitTestResult << "TEST " << nOfTest << ": Solved problem p0033.osil with MOSEK" << std::endl;
        cout << endl << "TEST " << nOfTest << ": Completed successfully" << endl << endl;
    }
    catch(const ErrorClass& eclass){
        cout << "OSrL =  " <<  solver->osrl <<  endl;
        cout << endl << endl << endl;
        unitTestResultFailure  <<"Sorry Unit Test Failed Testing the MOSEK Solver:"  + eclass.errormsg << endl;
        if (solver != NULL)
            delete solver;
        solver = NULL;
        if (fileUtil != NULL)
            delete fileUtil;
        fileUtil = NULL;
    }    
#endif
std::cout << "now try soplex" << std::endl;
#ifdef COIN_HAS_SOPLEX
    try{
        cout << endl << "TEST " << ++nOfTest << ": SoPlex solver on parincLinear.osil" << endl << endl;

        fileUtil = new FileUtil();
        solver = new CoinSolver();

        ok = true; 
        osilFileName = dataDir  + "osilFiles" + dirsep + "parincLinear.osil";
        osil = fileUtil->getFileAsString( osilFileName.c_str());
        solver->sSolverName = "soplex";
        solver->osil = osil;
        solver->osinstance = NULL; 
        cout << "call the SoPlex Solver for parincLinear" << endl;
        solver->buildSolverInstance();
        solver->solve();
        check = 7668;
        //ok &= NearEqual(getObjVal( solver->osrl) , check,  1e-10 , 1e-10);
        ok = ( fabs(check - getObjVal( solver->osrl) )/(fabs( check) + OS_NEAR_EQUAL) <= OS_NEAR_EQUAL) ? true : false;
        if (ok)
        {    
#ifdef DEBUG
            cout << solver->osrl << endl;
#endif
            cout << "SoPlex solver solution for parincLinear checks." << endl;
        }
        else
        {   
            cout << "SoPlex solver solution for parincLinear in error:" << endl;
            cout << solver->osrl << endl;
        }
        if(ok == false) throw ErrorClass(" Fail unit test with Soplex on parincLinear.osil");
        delete solver;
        solver = NULL;
        delete fileUtil;
        fileUtil = NULL;
        unitTestResult << "TEST " << nOfTest << ": Solved problem parincLinear.osil with SoPlex" << std::endl;
        cout << endl << "TEST " << nOfTest << ": Completed successfully" << endl << endl;
    }
    catch(const ErrorClass& eclass){
        cout << "OSrL =  " <<  solver->osrl <<  endl;
        cout << endl << endl << endl;
        unitTestResultFailure  <<"Sorry Unit Test Failed Testing the SoPlex Solver:"  + eclass.errormsg << endl;
        if (solver != NULL)
            delete solver;
        solver = NULL;
        if (fileUtil != NULL)
            delete fileUtil;
        fileUtil = NULL;
    }    
#endif

#ifdef COIN_HAS_XPR
    try{
        cout << endl << "TEST " << ++nOfTest << ": XPRESS solver on p0033.osil" << endl << endl;

        fileUtil = new FileUtil();
        solver = new CoinSolver();

        ok = true; 
        osilFileName = dataDir  + "osilFiles" + dirsep + "p0033.osil";
        osolFileName = dataDir  + "osolFiles" + dirsep + "p0033_cpx.osol";
        osil = fileUtil->getFileAsString( osilFileName.c_str());
        osol = fileUtil->getFileAsString( osolFileName.c_str());
        solver->sSolverName = "xpress";
        solver->osil = osil;
        solver->osol = osol;  
        solver->osinstance = NULL; 
        cout << "call the XPRESS Solver for p0033" << endl;
        solver->buildSolverInstance();
        solver->solve();
        check = 3089;
        //ok &= NearEqual(getObjVal( solver->osrl) , check,  1e-10 , 1e-10);
        ok = ( fabs(check - getObjVal( solver->osrl) )/(fabs( check) + OS_NEAR_EQUAL) <= OS_NEAR_EQUAL) ? true : false;
        if (ok)
        {    
#ifdef DEBUG
            cout << solver->osrl << endl;
#endif
            cout << "XPRESS solver solution for p0033 checks." << endl;
        }
        else
        {    cout << "XPRESS solver solution for p0033 in error:" << endl;
            cout << solver->osrl << endl;
        }
        if(ok == false) throw ErrorClass(" Fail unit test with XPRESS on p0033.osil");
        delete solver;
        solver = NULL;
        delete fileUtil;
        fileUtil = NULL;
        unitTestResult << "TEST " << nOfTest << ": Solved problem p0033.osil with XPRESS" << std::endl;
        cout << endl << "TEST " << nOfTest << ": Completed successfully" << endl << endl;
    }
    catch(const ErrorClass& eclass){
        cout << "OSrL =  " <<  solver->osrl <<  endl;
        cout << endl << endl << endl;
        unitTestResultFailure  <<"Sorry Unit Test Failed Testing the XPRESS Solver:"  + eclass.errormsg << endl;
        if (solver != NULL)
            delete solver;
        solver = NULL;
        if (fileUtil != NULL)
            delete fileUtil;
        fileUtil = NULL;
    }    
#endif


#ifdef COIN_HAS_IPOPT
    IpoptSolver *ipoptSolver  =  NULL;    
    try{
        cout << endl << "TEST " << ++nOfTest << ": Ipopt solver with avion2.osil" << endl << endl;

        fileUtil = new FileUtil();
        osilreader = new OSiLReader(); 
        osolreader = new OSoLReader(); 
        ipoptSolver  = new IpoptSolver();

        cout << "create a new IPOPT Solver for OSiL string solution" << endl;
        ok = true;
        // avion does not work with Mumps on AIX xlC compiler
#ifndef XLC_
        osilFileName =  dataDir  + "osilFiles" + dirsep +  "avion2.osil";
        osolFileName = dataDir  + "osolFiles" + dirsep + "avion2_ipopt.osol";
        osil = fileUtil->getFileAsString( osilFileName.c_str());
        osol = fileUtil->getFileAsString( osolFileName.c_str());
        cout << "IPOPT Solver created for OSiL string solution" << endl;
        ipoptSolver->osol = osol;
        ipoptSolver->osinstance = osilreader->readOSiL( osil);
        ipoptSolver->osol = osol;
        cout << "call the IPOPT Solver" << endl;    
        ipoptSolver->buildSolverInstance();
        ipoptSolver->solve();
        check = 9.46801e+07;
        //ok &= NearEqual(getObjVal( ipoptSolver->osrl) , check,  1e-10 , 1e-10);
        ok = ( fabs(check - getObjVal( ipoptSolver->osrl) )/(fabs( check) + OS_NEAR_EQUAL) <= OS_NEAR_EQUAL) ? true : false;
        if (ok)
        {    
#ifdef DEBUG
            cout << ipoptSolver->osrl << endl;
#endif
            cout << "IPOPT solver solution for avion2 checks." << endl;
        }
        else
        {    cout << "IPOPT solver solution for avion2 in error:" << endl;
            cout << ipoptSolver->osrl << endl;
        }
        if(ok == false) throw ErrorClass(" Fail unit test with Ipopt on avion2.osil");
        delete osilreader;
        osilreader = NULL;
        delete osolreader;
        osolreader = NULL;
        delete ipoptSolver;
        ipoptSolver = NULL;
        delete fileUtil;
        fileUtil = NULL;
        unitTestResult << "TEST " << nOfTest << ": Solved problem avion2.osil with Ipopt" << std::endl;
        cout << endl << "TEST " << nOfTest << ": Completed successfully" << endl << endl;
#endif
    }
    catch(const ErrorClass& eclass){
        unitTestResultFailure << "Sorry Unit Test Failed Testing the Ipopt Solver:"  + eclass.errormsg<< endl; 
        if (osilreader != NULL)
            delete osilreader;
        osilreader = NULL;
        if (osolreader != NULL)
            delete osolreader;
        osolreader = NULL;
        if (ipoptSolver != NULL)
            delete ipoptSolver;
        ipoptSolver = NULL;
        if (fileUtil != NULL)
            delete fileUtil;
        fileUtil = NULL;
    }

if(THOROUGH == true){
    // solve another problem
    try{
        cout << endl << "TEST " << ++nOfTest << ": Ipopt solver with HS071_NLPMod.osil" << endl << endl;
        cout << "create a new IPOPT Solver for OSiL string solution" << endl;

        fileUtil = new FileUtil();
        osilreader = new OSiLReader(); 
        osolreader = new OSoLReader(); 
        ipoptSolver  = new IpoptSolver();

        // a problem with all nonlinear terms, no linear terms
        osilFileName = dataDir  + "osilFiles" + dirsep + "HS071_NLPMod.osil";
        osolFileName = dataDir  + "osolFiles" + dirsep + "HS071_NLPMod_ipopt.osol";
        osil = fileUtil->getFileAsString( osilFileName.c_str());
        osol = fileUtil->getFileAsString( osolFileName.c_str());
        cout << "IPOPT Solver created for OSiL string solution" << endl;
//        osol = "<osol></osol>";
        ipoptSolver->osinstance = osilreader->readOSiL( osil);
        ipoptSolver->osoption   = osolreader->readOSoL( osol);
        ipoptSolver->osol = osol;
        ipoptSolver->buildSolverInstance();
        ipoptSolver->solve();
        cout << "Here is the IPOPT solver solution for HS071_NLP" << endl;
        check = 17.014;
        //ok &= NearEqual(getObjVal( ipoptSolver->osrl) , check,  1e-10 , 1e-10);
        ok = ( fabs(check - getObjVal( ipoptSolver->osrl) )/(fabs( check) + OS_NEAR_EQUAL) <= OS_NEAR_EQUAL) ? true : false;
        if (ok)
        {    
#ifdef DEBUG
            cout << ipoptSolver->osrl << endl;
#endif
            cout << "IPOPT solver solution for HS071_NLP checks." << endl;
        }
        else
        {    cout << "IPOPT solver solution for HS071_NLP in error:" << endl;
            cout << ipoptSolver->osrl << endl;
        }
        delete osilreader;
        osilreader = NULL;
        delete osolreader;
        osolreader = NULL;
        delete ipoptSolver;
        ipoptSolver = NULL;
        delete fileUtil;
        fileUtil = NULL;
        if(ok == false) throw ErrorClass(" Fail unit test with Ipopt on HS071_NLP.osil");
        unitTestResult << "TEST " << nOfTest << ": Solved problem HS071.osil with Ipopt" << std::endl;
        cout << endl << "TEST " << nOfTest << ": Completed successfully" << endl << endl;
    }
    catch(const ErrorClass& eclass){
        unitTestResultFailure << "Sorry Unit Test Failed Testing the Ipopt Solver:"  + eclass.errormsg<< endl; 
        if (osilreader != NULL)
            delete osilreader;
        osilreader = NULL;
        if (osolreader != NULL)
            delete osolreader;
        osolreader = NULL;
        if (ipoptSolver != NULL)
            delete ipoptSolver;
        ipoptSolver = NULL;
        if (fileUtil != NULL)
            delete fileUtil;
        fileUtil = NULL;
    }

    try{
        // solve another problem
        // a problem with both quadratic terms and general nonlinear terms
        cout << endl << "TEST " << ++nOfTest << ": Ipopt solver on rosenbrockmod.osil" << endl << endl;
        cout << "create a new IPOPT Solver for OSiL string solution" << endl;

        fileUtil = new FileUtil();
        osilreader = new OSiLReader(); 
        osolreader = new OSoLReader(); 
        ipoptSolver  = new IpoptSolver();

        osilFileName = dataDir  + "osilFiles" + dirsep + "rosenbrockmod.osil";
        osolFileName = dataDir  + "osolFiles" + dirsep + "rosenbrockmod_ipopt.osol";
        osil = fileUtil->getFileAsString( osilFileName.c_str());
        osol = fileUtil->getFileAsString( osolFileName.c_str());
        cout << "IPOPT Solver created for OSiL string solution" << endl;
        ipoptSolver->osil     = osil;
        ipoptSolver->osoption = osolreader->readOSoL( osol);
        cout << "call the IPOPT Solver" << endl;
        ipoptSolver->buildSolverInstance();
        ipoptSolver->solve();
        check = 6.7279;
        //ok &= NearEqual(getObjVal( ipoptSolver->osrl) , check,  1e-10 , 1e-10);
        ok = ( fabs(check - getObjVal( ipoptSolver->osrl) )/(fabs( check) + OS_NEAR_EQUAL) <= OS_NEAR_EQUAL) ? true : false;
        if (ok)
        {    
#ifdef DEBUG
            cout << ipoptSolver->osrl << endl;
#endif
            cout << "Ipopt solver solution for rosenbrockmod checks." << endl;
        }
        else
        {    cout << "Ipopt solver solution for rosenbrockmod in error:" << endl;
            cout << ipoptSolver->osrl << endl;
        }
        if(ok == false) 
            throw ErrorClass(" Fail unit test with Ipopt on rosenbrockmod.osil");
        delete osilreader;
        osilreader = NULL;
        delete osolreader;
        osolreader = NULL;
        delete ipoptSolver;
        ipoptSolver = NULL;
        delete fileUtil;
        fileUtil = NULL;
        unitTestResult << "TEST " << nOfTest << ": Solved problem rosenbrockmod.osil with Ipopt" << std::endl;
        cout << endl << "TEST " << nOfTest << ": Completed successfully" << endl << endl;
        //return 0;
    }
    catch(const ErrorClass& eclass){
        unitTestResultFailure << "Sorry Unit Test Failed Testing the Ipopt Solver:"  + eclass.errormsg<< endl; 
        if (osilreader != NULL)
            delete osilreader;
        osilreader = NULL;
        if (osolreader != NULL)
            delete osolreader;
        osolreader = NULL;
        if (ipoptSolver != NULL)
            delete ipoptSolver;
        ipoptSolver = NULL;
        if (fileUtil != NULL)
            delete fileUtil;
        fileUtil = NULL;
    }

    try{
        // solve another problem
        // a problem that is a pure quadratic
        cout << endl << "TEST " << ++nOfTest << ": Ipopt solver on parincQuadratic.osil" << endl << endl;
        cout << "create a new IPOPT Solver for OSiL string solution" << endl;

        fileUtil = new FileUtil();
        osilreader = new OSiLReader(); 
        osolreader = new OSoLReader(); 
        ipoptSolver  = new IpoptSolver();

        osilFileName = dataDir  + "osilFiles" + dirsep + "parincQuadratic.osil";
        osolFileName = dataDir  + "osolFiles" + dirsep + "parincQuadratic_ipopt.osol";
        osil = fileUtil->getFileAsString( osilFileName.c_str());
        osol = fileUtil->getFileAsString( osolFileName.c_str());
        cout << "IPOPT Solver created for OSiL string solution" << endl;
        ipoptSolver->osinstance = osilreader->readOSiL( osil);
        ipoptSolver->osil = osil;
        ipoptSolver->osol = osol;
        cout << "call the IPOPT Solver" << endl;
        ipoptSolver->buildSolverInstance();
        ipoptSolver->solve();
        check = 49920.5;
        //ok &= NearEqual(getObjVal( ipoptSolver->osrl) , check,  1e-10 , 1e-10);
        ok = ( fabs(check - getObjVal( ipoptSolver->osrl) )/(fabs( check) + OS_NEAR_EQUAL) <= OS_NEAR_EQUAL) ? true : false;
        if (ok)
        {    
#ifdef DEBUG
            cout << ipoptSolver->osrl << endl;
#endif
            cout << "IPOPT solver solution for parincQuadratic checks." << endl;
        }
        else
        {    cout << "IPOPT solver solution for parincQuadratic in error:" << endl;
            cout << ipoptSolver->osrl << endl;
        }
        if(ok == false) throw ErrorClass(" Fail unit test with Ipopt on parincQuadradic.osil");
        delete osilreader;
        osilreader = NULL;    
        delete osolreader;
        osolreader = NULL;    
        delete ipoptSolver;
        ipoptSolver = NULL;
        delete fileUtil;
        fileUtil = NULL;
        unitTestResult << "TEST " << nOfTest << ": Solved problem parincQuadratic.osil with Ipopt" << std::endl;
        cout << endl << "TEST " << nOfTest << ": Completed successfully" << endl << endl;
    }
    catch(const ErrorClass& eclass){
        unitTestResultFailure << "Sorry Unit Test Failed Testing the Ipopt Solver:"  + eclass.errormsg<< endl; 
        if (osilreader != NULL)
            delete osilreader;
        osilreader = NULL;
        if (osolreader != NULL)
            delete osolreader;
        osolreader = NULL;
        if (ipoptSolver != NULL)
            delete ipoptSolver;
        ipoptSolver = NULL;
        if (fileUtil != NULL)
            delete fileUtil;
        fileUtil = NULL;
    }

    // solve another problem
    // try a pure linear program
    try{
        cout << endl << "TEST " << ++nOfTest << ": Ipopt solver on parincLinear.osil" << endl << endl;
        cout << "create a new IPOPT Solver for OSiL string solution" << endl;

        fileUtil = new FileUtil();
        osilreader = new OSiLReader(); 
        osolreader = new OSoLReader(); 
        ipoptSolver  = new IpoptSolver();

        osilFileName = dataDir  + "osilFiles" + dirsep + "parincLinear.osil";
        osolFileName = dataDir  + "osolFiles" + dirsep + "parincLinear_ipopt.osol";
        osil = fileUtil->getFileAsString( osilFileName.c_str());
        osol = fileUtil->getFileAsString( osolFileName.c_str());
        cout << "IPOPT Solver created for OSiL string solution" << endl;
        ipoptSolver->osinstance = osilreader->readOSiL( osil);
        ipoptSolver->osoption   = NULL;
        ipoptSolver->osol = ""; 
        cout << "call the IPOPT Solver" << endl;
        ipoptSolver->buildSolverInstance();
        ipoptSolver->solve();
        check = 7668;
        //ok &= NearEqual(getObjVal( ipoptSolver->osrl) , check,  1e-1 , 1e-1);
        ok = ( fabs(check - getObjVal( ipoptSolver->osrl) )/(fabs( check) + OS_NEAR_EQUAL) <= OS_NEAR_EQUAL) ? true : false;
        if (ok)
        {    
#ifdef DEBUG
            cout << ipoptSolver->osrl << endl;
#endif
            cout << "IPOPT solver solution for parincLinear checks." << endl;
        }
        else
        {    cout << "IPOPT solver solution for parincLinear in error:" << endl;
            cout << ipoptSolver->osrl << endl;
        }
        if(ok == false) throw ErrorClass(" Fail unit test with Ipopt on parincLinear.osil");
        delete osilreader;
        osilreader = NULL;    
        delete osolreader;
        osolreader = NULL;    
        delete ipoptSolver;
        ipoptSolver = NULL;
        delete fileUtil;
        fileUtil = NULL;
        unitTestResult << "TEST " << nOfTest << ": Solved problem parincLinear.osil with Ipopt" << std::endl;
        cout << endl << "TEST " << nOfTest << ": Completed successfully" << endl << endl;
    }
    catch(const ErrorClass& eclass){
        unitTestResultFailure << "Sorry Unit Test Failed Testing the Ipopt Solver:"  + eclass.errormsg<< endl; 
        if (osilreader != NULL)
            delete osilreader;
        osilreader = NULL;
        if (osolreader != NULL)
            delete osolreader;
        osolreader = NULL;
        if (ipoptSolver != NULL)
            delete ipoptSolver;
        ipoptSolver = NULL;
        if (fileUtil != NULL)
            delete fileUtil;
        fileUtil = NULL;
    }

        // solve another problem
        // callBackTest.osil
    try{
        cout << endl << "TEST " << ++nOfTest << ": Ipopt solver on callBackTest.osil" << endl << endl;
        cout << "create a new IPOPT Solver for OSiL string solution" << endl;

        fileUtil = new FileUtil();
        osilreader = new OSiLReader(); 
        osolreader = new OSoLReader(); 
        ipoptSolver  = new IpoptSolver();

        osilFileName = dataDir  + "osilFiles" + dirsep + "callBackTest.osil";
        osolFileName = dataDir  + "osolFiles" + dirsep + "callBackTest_ipopt.osol";
        osil = fileUtil->getFileAsString( osilFileName.c_str());
        osol = fileUtil->getFileAsString( osolFileName.c_str());
        cout << "IPOPT Solver created for OSiL string solution" << endl;
        ipoptSolver->osinstance = osilreader->readOSiL( osil);
        ipoptSolver->osoption   = osolreader->readOSoL( osol);
        ipoptSolver->osol = osol;
        cout << "call the IPOPT Solver" << endl;
        ipoptSolver->buildSolverInstance();
        ipoptSolver->solve();
        check = 1.00045e+06;
        //ok &= NearEqual(getObjVal( ipoptSolver->osrl) , check,  1e-10 , 1e-10);
        ok = ( fabs(check - getObjVal( ipoptSolver->osrl) )/(fabs( check) + OS_NEAR_EQUAL) <= OS_NEAR_EQUAL) ? true : false;
        if (ok)
        {    
#ifdef DEBUG
            cout << ipoptSolver->osrl << endl;
#endif
            cout << "IPOPT solver solution for callBackTest checks." << endl;
        }
        else
        {    cout << "IPOPT solver solution for callBackTest in error:" << endl;
            cout << ipoptSolver->osrl << endl;
        }
        if(ok == false) throw ErrorClass(" Fail unit test with Ipopt on callBackTest.osil");
        delete osilreader;
        osilreader = NULL;    
        delete osolreader;
        osolreader = NULL;    
        delete ipoptSolver;
        ipoptSolver = NULL;
        delete fileUtil;
        fileUtil = NULL;
        unitTestResult << "TEST " << nOfTest << ": Solved problem callBackTest.osil with Ipopt" << std::endl;    
        cout << endl << "TEST " << nOfTest << ": Completed successfully" << endl << endl;
    }
    catch(const ErrorClass& eclass){
        unitTestResultFailure << "Sorry Unit Test Failed Testing the Ipopt Solver:"  + eclass.errormsg<< endl; 
        if (osilreader != NULL)
            delete osilreader;
        osilreader = NULL;
        if (osolreader != NULL)
            delete osolreader;
        osolreader = NULL;
        if (ipoptSolver != NULL)
            delete ipoptSolver;
        ipoptSolver = NULL;
        if (fileUtil != NULL)
            delete fileUtil;
        fileUtil = NULL;
    }

    // solve another problem
    // callBackTest.osil
    try{
        cout << endl << "TEST " << ++nOfTest << ": Ipopt solver on callBackTestRowMajor.osil" << endl << endl;
        cout << "create a new IPOPT Solver for OSiL string solution" << endl;

        fileUtil = new FileUtil();
        osilreader = new OSiLReader(); 
        osolreader = new OSoLReader(); 
        ipoptSolver  = new IpoptSolver();

        osilFileName =  dataDir  + "osilFiles" + dirsep + "callBackTestRowMajor.osil";
        osolFileName = dataDir  + "osolFiles" + dirsep + "callBackTestRowMajor_ipopt.osol";
        osil = fileUtil->getFileAsString( osilFileName.c_str());
        osol = fileUtil->getFileAsString( osolFileName.c_str());
        cout << "IPOPT Solver created for OSiL string solution" << endl;
        ipoptSolver->osinstance = NULL;
        ipoptSolver->osoption   = NULL;
        ipoptSolver->osil = osil;
        ipoptSolver->osol = osol;
        cout << "call the IPOPT Solver" << endl;
//        ipoptSolver->buildSolverInstance();
        ipoptSolver->solve();
        check = 1.00045e+06;
        //ok &= NearEqual(getObjVal( ipoptSolver->osrl) , check,  1e-10 , 1e-10);
        ok = ( fabs(check - getObjVal( ipoptSolver->osrl) )/(fabs( check) + OS_NEAR_EQUAL) <= OS_NEAR_EQUAL) ? true : false;
        if (ok)
        {    
#ifdef DEBUG
            cout << ipoptSolver->osrl << endl;
#endif
            cout << "IPOPT solver solution for callBackTestRowMajor checks." << endl;
        }
        else
        {    cout << "IPOPT solver solution for callBackTestRowMajor in error:" << endl;
            cout << ipoptSolver->osrl << endl;
        }
        if(ok == false) throw ErrorClass(" Fail unit test with Ipopt on callBackTestRowMajor.osil");
        delete osilreader;
        osilreader = NULL;    
        delete osolreader;
        osolreader = NULL;    
        delete ipoptSolver;
        ipoptSolver = NULL;    
        delete fileUtil;
        fileUtil = NULL;
        unitTestResult << "TEST " << nOfTest << ": Solved problem callBackRowMajor.osil with Ipopt" << std::endl;
        cout << endl << "TEST " << nOfTest << ": Completed successfully" << endl << endl;
    }
    catch(const ErrorClass& eclass){
        unitTestResultFailure << "Sorry Unit Test Failed Testing the Ipopt Solver:"  + eclass.errormsg<< endl; 
        if (osilreader != NULL)
            delete osilreader;
        osilreader = NULL;

        if (osolreader != NULL)
            delete osolreader;
        osolreader = NULL;
        if (ipoptSolver != NULL)
            delete ipoptSolver;
        ipoptSolver = NULL;
        if (fileUtil != NULL)
            delete fileUtil;
        fileUtil = NULL;
    }

    try{
        cout << endl << "TEST " << ++nOfTest << ": Ipopt solver on rosenbrockorig.osil" << endl << endl;

        fileUtil = new FileUtil();
        osilreader = new OSiLReader(); 
        osolreader = new OSoLReader(); 
        ipoptSolver = new IpoptSolver();

        ok = true; 
        osilFileName = dataDir  + "osilFiles" + dirsep + "rosenbrockorig.osil";
//        osolFileName = dataDir  + "osolFiles" + dirsep + "rosenbrockorig_Ipopt.osol";
        osil = fileUtil->getFileAsString( osilFileName.c_str());
//        osol = fileUtil->getFileAsString( osolFileName.c_str());
        osol = "";
        ipoptSolver->sSolverName = "ipopt";
        ipoptSolver->osil = osil;
        ipoptSolver->osol = osol; 
//        ipoptSolver->osinstance = osilreader->readOSiL( osil);
//        ipoptSolver->osoption   = osolreader->readOSoL( osol);
        cout << "call the COIN - Ipopt Solver for rosenbrockorig" << endl;
        cout << endl << endl << osil << endl << endl;
        ipoptSolver->buildSolverInstance();

        cout << ipoptSolver->osinstance->printModel() << endl << endl;
        //cout << osilreader->m_osinstance->printModel() << endl << endl;
    
        std::cout << " CALL SOLVE " << std::endl;
        ipoptSolver->solve();
        check = 0;
        ok = ( fabs(check - getObjVal( ipoptSolver->osrl) )/(fabs( check) + OS_NEAR_EQUAL) <= OS_NEAR_EQUAL) ? true : false;
        if (ok)
        {    
#ifdef DEBUG
            cout << ipoptSolver->osrl << endl;
#endif
            cout << "Ipopt solver solution for rosenbrockorig checks." << endl;
        }
        else
        {    cout << "Ipopt solver solution for rosenbrockorig in error:" << endl;
            cout << ipoptSolver->osrl << endl;
        }
        if(ok == false) throw ErrorClass(" Fail unit test with Ipopt on rosenbrockorig.osil");

        delete ipoptSolver;
        ipoptSolver = NULL;
        delete osilreader;
        osilreader = NULL;
        delete osolreader;
        osolreader = NULL;
        delete fileUtil;
        fileUtil = NULL;
        unitTestResult << "TEST " << nOfTest << ": Solved problem rosenbrockorig.osil with Ipopt" << std::endl;
        cout << endl << "TEST " << nOfTest << ": Completed successfully" << endl << endl;
    }
    catch(const ErrorClass& eclass){
        unitTestResultFailure << "Sorry Unit Test Failed Testing the Ipopt Solver:"  + eclass.errormsg<< endl; 
        if (osilreader != NULL)
            delete osilreader;
        osilreader = NULL;
        if (osolreader != NULL)
            delete osolreader;
        osolreader = NULL;
        if (ipoptSolver != NULL)
            delete ipoptSolver;
        ipoptSolver = NULL;
        if (fileUtil != NULL)
            delete fileUtil;
        fileUtil = NULL;
    }

    try{
        cout << endl << "TEST " << ++nOfTest << ": Ipopt solver on HS071_feas.osil" << endl << endl;

        fileUtil = new FileUtil();
        ipoptSolver = new IpoptSolver();

        ok = true; 
        osilFileName = dataDir  + "osilFiles" + dirsep + "HS071_feas.osil";
//        osolFileName = dataDir  + "osolFiles" + dirsep + "HS071_feas_Ipopt.osol";
        osil = fileUtil->getFileAsString( osilFileName.c_str());
//        osol = fileUtil->getFileAsString( osolFileName.c_str());
        osol = "";
        ipoptSolver->sSolverName = "ipopt";
        ipoptSolver->osil = osil;
        ipoptSolver->osol = osol; 
//        ipoptSolver->osinstance = osilreader->readOSiL( osil);
//        ipoptSolver->osoption   = osolreader->readOSoL( osol);
        ipoptSolver->buildSolverInstance();
    
        cout << "call the COIN - Ipopt Solver for HS071_feas.osil" << endl;
        ipoptSolver->solve();

//      osresult = new OSResult();
        osrlreader = new OSrLReader();
        osresult = osrlreader->readOSrL(ipoptSolver->osrl);

        check = 3.162277659974328;
        ok  = ( fabs(check - osresult->getVarValue(0,0) )/(fabs( check) + OS_NEAR_EQUAL) <= OS_NEAR_EQUAL) ? true : false;
        check = 3.1622776613181367;
        ok &= ( fabs(check - osresult->getVarValue(0,0) )/(fabs( check) + OS_NEAR_EQUAL) <= OS_NEAR_EQUAL) ? true : false;
        check = 3.1622776594067235;
        ok &= ( fabs(check - osresult->getVarValue(0,0) )/(fabs( check) + OS_NEAR_EQUAL) <= OS_NEAR_EQUAL) ? true : false;
        check = 3.162277659974329;
        ok &= ( fabs(check - osresult->getVarValue(0,0) )/(fabs( check) + OS_NEAR_EQUAL) <= OS_NEAR_EQUAL) ? true : false;
    
        if (ok)
        {    
#ifdef DEBUG
            cout << ipoptSolver->osrl << endl;
#endif
            cout << "Ipopt feasible point for HS071_feas checks." << endl;
        }
        else
        {    cout << "Ipopt feasible point for HS071_feas in error:" << endl;
            cout << ipoptSolver->osrl << endl;
        }
        if(ok == false) throw ErrorClass(" Fail unit test with Ipopt on HS071_feas.osil");
    
        delete ipoptSolver;
        ipoptSolver = NULL;
        delete fileUtil;
        fileUtil = NULL;
        delete osrlreader;
        osrlreader = NULL;

        unitTestResult << "TEST " << nOfTest << ": Correctly solved problem HS071_feas with Ipopt" << std::endl;
        cout << endl << "TEST " << nOfTest << ": Completed successfully" << endl << endl;
    }
    catch(const ErrorClass& eclass){
        unitTestResultFailure << "Sorry Unit Test Failed Testing the Ipopt Solver:"  + eclass.errormsg<< endl; 
        if (osilreader != NULL)
            delete osilreader;
        osilreader = NULL;
        if (osolreader != NULL)
            delete osolreader;
        osolreader = NULL;
        if (osrlreader != NULL)
            delete osrlreader;
        osrlreader = NULL;
        if (ipoptSolver != NULL)
            delete ipoptSolver;
        ipoptSolver = NULL;
        if (fileUtil != NULL)
            delete fileUtil;
        fileUtil = NULL;
    }

    try{
        cout << endl << "TEST " << ++nOfTest << ": Ipopt solver on HS071_no-obj.osil" << endl << endl;
        try {

            fileUtil = new FileUtil();
            ipoptSolver = new IpoptSolver();

            ok = true; 
            osilFileName = dataDir  + "osilFiles" + dirsep + "HS071_no-obj.osil";
            osil = fileUtil->getFileAsString( osilFileName.c_str());
            osol = "";
            ipoptSolver->sSolverName = "ipopt";
            ipoptSolver->osil = osil;
            ipoptSolver->osol = osol; 
//            ipoptSolver->osinstance = osilreader->readOSiL( osil);
//            ipoptSolver->osoption   = osolreader->readOSoL( osol);
            ipoptSolver->buildSolverInstance();
    
            cout << "call the COIN - Ipopt Solver for HS071_no-obj.osil" << endl;
            ipoptSolver->solve();
        }
        catch(const ErrorClass& eclass)
        {
            ok = (ipoptSolver->osresult->getGeneralMessage() == 
                "Ipopt NEEDS AN OBJECTIVE FUNCTION\n(For pure feasibility problems, use zero function.)");
            if(ok == false) 
            {    cout << "Ipopt solver returns:" << endl;
                cout << ipoptSolver->osrl << endl;
                throw ErrorClass(" Fail unit test with Ipopt on HS071_no-obj.osil");
            }
        }
    
        cout << "Received error message from Ipopt: \"Ipopt NEEDS AN OBJECTIVE FUNCTION\"" << endl;
    
        delete ipoptSolver;
        ipoptSolver = NULL;
        delete fileUtil;
        fileUtil = NULL;

        unitTestResult << "TEST " << nOfTest << ": Correctly diagnosed problem HS071_no-obj with Ipopt" << std::endl;
        cout << endl << "TEST " << nOfTest << ": Completed successfully" << endl << endl;
    }
    catch(const ErrorClass& eclass){
        unitTestResultFailure << "Sorry Unit Test Failed Testing the Ipopt Solver:"  + eclass.errormsg<< endl; 
        if (osilreader != NULL)
            delete osilreader;
        osilreader = NULL;
        if (osolreader != NULL)
            delete osolreader;
        osolreader = NULL;
        if (ipoptSolver != NULL)
            delete ipoptSolver;
        ipoptSolver = NULL;
        if (fileUtil != NULL)
            delete fileUtil;
        fileUtil = NULL;
    }


} // end  if (THOROUGH)
#endif // end  #ifdef COIN_HAS_IPOPT


#ifdef COIN_HAS_BONMIN
    try{
        cout << endl << "TEST " << ++nOfTest << ": Bonmin solver on bonminEx1.osil" << endl << endl;

        fileUtil = new FileUtil();
        osilreader = new OSiLReader(); 
        osolreader = new OSoLReader(); 
        solver = new BonminSolver();

        ok = true; 
        osilFileName = dataDir  + "osilFiles" + dirsep + "bonminEx1.osil";
        osolFileName = dataDir  + "osolFiles" + dirsep + "bonminEx1_Bonmin.osol";
        osil = fileUtil->getFileAsString( osilFileName.c_str());
        osol = fileUtil->getFileAsString( osolFileName.c_str());
        //solver->sSolverName = "bonmin";
//        solver->osinstance = osilreader->readOSiL( osil);
        solver->osil = osil;
        solver->osoption = osolreader->readOSoL( osol);
        cout << "call the COIN - Bonmin Solver for bonminEx1" << endl;
//        solver->buildSolverInstance();
        solver->solve();
        check = -17.07106795327683;
        //ok &= NearEqual(getObjVal( solver->osrl) , check,  1e-10 , 1e-10);
        ok = ( fabs(check - getObjVal( solver->osrl) )/(fabs( check) + OS_NEAR_EQUAL) <= OS_NEAR_EQUAL) ? true : false;
        if (ok)
        {    
#ifdef DEBUG
            cout << solver->osrl << endl;
#endif
            cout << "Bonmin solver solution for bonminEx1 checks." << endl;
        }
        else
        {    cout << "Bonmin solver solution for bonminEx1 in error:" << endl;
            cout << solver->osrl << endl;
        }
        if(ok == false) throw ErrorClass(" Fail unit test with Bonmin on bonminEx1.osil");
        delete solver;
        solver = NULL;
        delete osilreader;
        osilreader = NULL;
        delete osolreader;
        osolreader = NULL;
        delete fileUtil;
        fileUtil = NULL;
        unitTestResult << "TEST " << nOfTest << ": Solved problem bonminEx1.osil with Bonmin" << std::endl;
        cout << endl << "TEST " << nOfTest << ": Completed successfully" << endl << endl;
    }
    catch(const ErrorClass& eclass){
        unitTestResultFailure  << "Sorry Unit Test Failed Testing the Bonmin Solver:"  + eclass.errormsg << endl;
        if (solver != NULL)
            delete solver;
        solver = NULL;
        if (osilreader != NULL)
            delete osilreader;
        osilreader = NULL;
        if (osolreader != NULL)
            delete osolreader;
        osolreader = NULL;
        if (fileUtil != NULL)
            delete fileUtil;
        fileUtil = NULL;
    }    

if (THOROUGH == true){
    try{
        cout << endl << "TEST " << ++nOfTest << ": Bonmin solver on wayneQuadratic.osil" << endl << endl;

        fileUtil = new FileUtil();
        osilreader = new OSiLReader(); 
        solver = new BonminSolver();    

        ok = true;
        osilFileName = dataDir  + "osilFiles" + dirsep + "wayneQuadratic.osil";
        osolFileName = dataDir  + "osolFiles" + dirsep + "wayneQuadratic_Bonmin1.osol";
        osil = fileUtil->getFileAsString( osilFileName.c_str());
        osol = fileUtil->getFileAsString( osolFileName.c_str());
        solver->osol = osol;
        solver->osinstance = osilreader->readOSiL( osil);
        cout << "call the Bonmin Solver for wayneQuadratic" << endl;
        solver->buildSolverInstance();
        // Do this one with two different osol files!!!
        solver->solve();
        check = 2.925;
        //ok &= NearEqual(getObjVal( solver->osrl) , check,  1e-10 , 1e-10);
        ok = ( fabs(check - getObjVal( solver->osrl) )/(fabs( check) + OS_NEAR_EQUAL) <= OS_NEAR_EQUAL) ? true : false;
        if (ok)
        {    
#ifdef DEBUG
            cout << solver->osrl << endl;
#endif
            cout << "Bonmin solver solution for wayneQuadratic checks." << endl;
        }
        else
        {    cout << "Bonmin solver solution for wayneQuadratic in error:" << endl;
            cout << solver->osrl << endl;
        }
        if(ok == false) throw ErrorClass(" Fail unit test with Bonmin on wayneQuadratic.osil");
        delete solver;
        solver = NULL;
        delete osilreader;
        osilreader = NULL;
        delete fileUtil;
        fileUtil = NULL;
        unitTestResult << "TEST " << nOfTest << ": Solved problem wayneQuadratic.osil with Bonmin" << std::endl;
        cout << endl << "TEST " << nOfTest << ": Completed successfully" << endl << endl;
    }
    catch(const ErrorClass& eclass){
        unitTestResultFailure  << "Sorry Unit Test Failed Testing the Bonmin Solver:"  + eclass.errormsg << endl;
        if (solver != NULL)
            delete solver;
        solver = NULL;
        if (osilreader != NULL)
            delete osilreader;
        osilreader = NULL;
        if (fileUtil != NULL)
            delete fileUtil;
        fileUtil = NULL;
    }    

    try{
        cout << endl << "TEST " << ++nOfTest << ": Bonmin solver on wayneQuadratic.osil" << endl << endl;

        fileUtil = new FileUtil();
        osilreader = new OSiLReader(); 
        osolreader = new OSoLReader(); 
        solver = new BonminSolver();    

        ok = true;
        osilFileName = dataDir  + "osilFiles" + dirsep + "wayneQuadratic.osil";
        osolFileName = dataDir  + "osolFiles" + dirsep + "wayneQuadratic_Bonmin2.osol";
        osil = fileUtil->getFileAsString( osilFileName.c_str());
        osol = fileUtil->getFileAsString( osolFileName.c_str());
        solver->osol = osol;
        solver->osinstance = osilreader->readOSiL( osil);
        solver->osoption   = osolreader->readOSoL( osol);
        cout << "call the Bonmin Solver for wayneQuadratic" << endl;
        solver->buildSolverInstance();
        // Do this one with two different osol files!!!
        solver->solve();
        check = 2.925;
        //ok &= NearEqual(getObjVal( solver->osrl) , check,  1e-10 , 1e-10);
        ok = ( fabs(check - getObjVal( solver->osrl) )/(fabs( check) + OS_NEAR_EQUAL) <= OS_NEAR_EQUAL) ? true : false;
        if (ok)
        {    
#ifdef DEBUG
            cout << solver->osrl << endl;
#endif
            cout << "Bonmin solver solution for wayneQuadratic checks." << endl;
        }
        else
        {    cout << "Bonmin solver solution for wayneQuadratic in error:" << endl;
            cout << solver->osrl << endl;
        }
        if(ok == false) throw ErrorClass(" Fail unit test with Bonmin on wayneQuadratic.osil");
        delete solver;
        solver = NULL;
        delete osilreader;
        osilreader = NULL;    
        delete osolreader;
        osolreader = NULL;    
        delete fileUtil;
        fileUtil = NULL;
        unitTestResult << "TEST " << nOfTest << ": Solved problem wayneQuadratic.osil with Bonmin" << std::endl;
        cout << endl << "TEST " << nOfTest << ": Completed successfully" << endl << endl;
    }
    catch(const ErrorClass& eclass){
        unitTestResultFailure  << "Sorry Unit Test Failed Testing the Bonmin Solver:"  + eclass.errormsg << endl;
        if (solver != NULL)
            delete solver;
        solver = NULL;
        if (osilreader != NULL)
            delete osilreader;
        osilreader = NULL;
        if (osolreader != NULL)
            delete osolreader;
        osolreader = NULL;
        if (fileUtil != NULL)
            delete fileUtil;
        fileUtil = NULL;
    }    

    try{
        cout << endl << "TEST " << ++nOfTest << ": Bonmin solver on rosenbrockorig.osil" << endl << endl;

        fileUtil = new FileUtil();
        osilreader = new OSiLReader(); 
        solver = new BonminSolver();    

        ok = true;
        osilFileName = dataDir  + "osilFiles" + dirsep + "rosenbrockorig.osil";
        osil = fileUtil->getFileAsString( osilFileName.c_str());
        solver->osol = "";
        solver->osinstance = osilreader->readOSiL( osil);
        cout << "build solver instance" << endl;
        solver->buildSolverInstance();
        cout << "call the Bonmin Solver for rosenbrockorig" << endl;
        solver->solve();
        check = 0;
        cout << "Verify solution" <<endl;
        //ok &= NearEqual(getObjVal( solver->osrl) , check,  1e-10 , 1e-10);
        ok = ( fabs(check - getObjVal( solver->osrl) )/(fabs( check) + OS_NEAR_EQUAL) <= OS_NEAR_EQUAL) ? true : false;
        if (ok)
        {    
#ifdef DEBUG
            cout << solver->osrl << endl;
#endif
            cout << "Bonmin solver solution for rosenbrockorig checks." << endl;
        }
        else
        {    cout << "Bonmin solver solution for rosenbrockorig in error:" << endl;
            cout << solver->osrl << endl;
        }
        if(ok == false) throw ErrorClass(" Fail unit test with Bonmin on rosenbrockorig.osil");
        delete solver;
        solver = NULL;
        delete osilreader;
        osilreader = NULL;    
        delete fileUtil;
        fileUtil = NULL;
        unitTestResult << "TEST " << nOfTest << ": Solved problem rosenbrockorig.osil with Bonmin" << std::endl;
        cout << endl << "TEST " << nOfTest << ": Completed successfully" << endl << endl;
    }
    catch(const ErrorClass& eclass){
        unitTestResultFailure  << "Sorry Unit Test Failed Testing the Bonmin Solver:"  + eclass.errormsg << endl;
        if (solver != NULL)
            delete solver;
        solver = NULL;
        if (osilreader != NULL)
            delete osilreader;
        osilreader = NULL;
        if (fileUtil != NULL)
            delete fileUtil;
        fileUtil = NULL;
    }    

    try{
        cout << endl << "TEST " << ++nOfTest << ": Bonmin solver on rosenbrockorigInt.osil" << endl << endl;

        fileUtil = new FileUtil();
        osilreader = new OSiLReader(); 
        solver = new BonminSolver();    

        ok = true;
        osilFileName = dataDir  + "osilFiles" + dirsep + "rosenbrockorigInt.osil";
        osil = fileUtil->getFileAsString( osilFileName.c_str());
        solver->osol = "";
        solver->osinstance = osilreader->readOSiL( osil);
        cout << "call the Bonmin Solver for rosenbrockinteger" << endl;
        solver->buildSolverInstance();
        solver->solve();
        check = 0;
        ok = ( fabs(check - getObjVal( solver->osrl) )/(fabs( check) + OS_NEAR_EQUAL) <= OS_NEAR_EQUAL) ? true : false;
        if (ok)
        {    
#ifdef DEBUG
            cout << solver->osrl << endl;
#endif
            cout << "Bonmin solver solution for rosenbrockorigInt checks." << endl;
        }
        else
        {    cout << "Bonmin solver solution for rosenbrockorigInt in error:" << endl;
            cout << solver->osrl << endl;
        }
        if(ok == false) throw ErrorClass(" Fail unit test with Bonmin on rosenbrockorigInt.osil");
        delete solver;
        solver = NULL;
        delete osilreader;
        osilreader = NULL;    
        delete fileUtil;
        fileUtil = NULL;
        unitTestResult << "TEST " << nOfTest << ": Solved problem rosenbrockorigInt.osil with Bonmin" << std::endl;
        cout << endl << "TEST " << nOfTest << ": Completed successfully" << endl << endl;
    }
    catch(const ErrorClass& eclass){
        unitTestResultFailure  << "Sorry Unit Test Failed Testing the Bonmin Solver:"  + eclass.errormsg << endl;
        if (solver != NULL)
            delete solver;
        solver = NULL;
        if (osilreader != NULL)
            delete osilreader;
        osilreader = NULL;
        if (fileUtil != NULL)
            delete fileUtil;
        fileUtil = NULL;
    }
}   // end of if( THOROUGH )
#endif   // end of #ifdef COIN_HAS_BONMIN


//#if 0 //for the time being --- Couenne stable 0.4 creates a segfault
#ifdef COIN_HAS_COUENNE
    CouenneSolver *solver = NULL;
    try{
        cout << endl << "TEST " << ++nOfTest << ": Couenne solver on bonminEx1.osil" << endl << endl;

        fileUtil = new FileUtil();
        solver = new CouenneSolver();
        osilreader = new OSiLReader(); 
        osolreader = new OSoLReader();

        ok = true; 
        osilFileName = dataDir  + "osilFiles" + dirsep + "bonminEx1.osil";
        osolFileName = dataDir  + "osolFiles" + dirsep + "bonminEx1_Couenne.osol";
        osil = fileUtil->getFileAsString( osilFileName.c_str());
        osol = fileUtil->getFileAsString( osolFileName.c_str());
        solver->sSolverName = "couenne";
        solver->osil = osil;
        solver->osol = osol; 
//        solver->osinstance = osilreader->readOSiL( osil);
//        solver->osoption   = osolreader->readOSoL( osol);
        cout << "call the COIN - Couenne Solver for bonminEx1" << endl;
        solver->buildSolverInstance();
    
        std::cout << " CALL SOLVE " << std::endl;
        solver->solve();
    
        check = -17.07106795327683;
        //ok &= NearEqual(getObjVal( solver->osrl) , check,  1e-10 , 1e-10);
        ok = ( fabs(check - getObjVal( solver->osrl) )/(fabs( check) + OS_NEAR_EQUAL) <= OS_NEAR_EQUAL) ? true : false;
        if (ok)
        {    
#ifdef DEBUG
            cout << solver->osrl << endl;
#endif
            cout << "Couenne solver solution for bonminEx1 checks." << endl;
        }
        else
        {    cout << "Couenne solver solution for bonminEx1 in error:" << endl;
            cout << solver->osrl << endl;
        }
        if(ok == false) throw ErrorClass(" Fail unit test with Couenne on bonminEx1.osil");

        delete solver;
        solver = NULL;
        delete osilreader;
        osilreader = NULL;
        delete osolreader;
        osolreader = NULL;
        delete fileUtil;
        fileUtil = NULL;
        unitTestResult << "TEST " << nOfTest << ": Solved problem bonminEx1.osil with Couenne" << std::endl;
        cout << endl << "TEST " << nOfTest << ": Completed successfully" << endl << endl;
    }
    catch(const ErrorClass& eclass){
        cout << "OSrL =  " <<  solver->osrl <<  endl;
        cout << endl << endl << endl;
        unitTestResultFailure  << "Sorry Unit Test Failed Testing the Couenne Solver:"  + eclass.errormsg << endl;
        if (solver != NULL)
            delete solver;
        solver = NULL;
        if (osilreader != NULL)
            delete osilreader;
        osilreader = NULL;
        if (osolreader != NULL)
            delete osolreader;
        osolreader = NULL;
        if (fileUtil != NULL)
            delete fileUtil;
        fileUtil = NULL;
    }    
    
if( THOROUGH == true){
    try{
        cout << endl << "TEST " << ++nOfTest << ": Couenne solver on bonminEx1_Nonlinear.osil" << endl << endl;

        fileUtil = new FileUtil();
        osilreader = new OSiLReader(); 
        osolreader = new OSoLReader(); 
        solver = new CouenneSolver();

        ok = true; 
        osilFileName = dataDir  + "osilFiles" + dirsep + "bonminEx1_Nonlinear.osil";
//        osolFileName = dataDir  + "osolFiles" + dirsep + "bonminEx1_Couenne.osol";
        osil = fileUtil->getFileAsString( osilFileName.c_str());
//        osol = fileUtil->getFileAsString( osolFileName.c_str());
        osol = "";
        solver->osil = osil;
        solver->osol = osol; 

//        solver->osinstance = osilreader->readOSiL( osil);
//        solver->osoption   = osolreader->readOSoL( osol);
        cout << "call the COIN - Couenne Solver for bonminEx1_Nonlinear" << endl;
        solver->buildSolverInstance();
    
        std::cout << " CALL SOLVE " << std::endl;
        solver->solve();
    
        check = -1.707107;
        //ok &= NearEqual(getObjVal( solver->osrl) , check,  1e-10 , 1e-10);
        ok = ( fabs(check - getObjVal( solver->osrl) )/(fabs( check) + OS_NEAR_EQUAL) <= OS_NEAR_EQUAL) ? true : false;
        if (ok)
        {    
#ifdef DEBUG
            cout << solver->osrl << endl;
#endif
            cout << "Couenne solver solution for bonminEx1_Nonlinear checks." << endl;
        }
        else
        {    cout << "Couenne solver solution for bonminEx1_Nonlinear in error:" << endl;
            cout << solver->osrl << endl;
        }
        if(ok == false) throw ErrorClass(" Fail unit test with Couenne on bonminEx1_Nonlinear.osil");

        delete solver;
        solver = NULL;
        delete osilreader;
        osilreader = NULL;
        delete osolreader;
        osolreader = NULL;
        delete fileUtil;
        fileUtil = NULL;
        unitTestResult << "TEST " << nOfTest << ": Solved problem bonminEx1_Nonlinear with Couenne" << std::endl;
        cout << endl << "TEST " << nOfTest << ": Completed successfully" << endl << endl;
    }
    catch(const ErrorClass& eclass){
        unitTestResultFailure  << "Sorry Unit Test Failed Testing the Couenne Solver:"  + eclass.errormsg << endl;
        if (solver != NULL)
            delete solver;
        solver = NULL;
        if (osilreader != NULL)
            delete osilreader;
        osilreader = NULL;
        if (osolreader != NULL)
            delete osolreader;
        osolreader = NULL;
        if (fileUtil != NULL)
            delete fileUtil;
        fileUtil = NULL;
    }    

    try{
        cout << endl << "TEST " << ++nOfTest << ": Couenne solver on nonconvex.osil" << endl << endl;

        fileUtil = new FileUtil();
        osilreader = new OSiLReader(); 
        osolreader = new OSoLReader(); 
        solver = new CouenneSolver();

        ok = true; 
        osilFileName = dataDir  + "osilFiles" + dirsep + "nonconvex.osil";
//        osolFileName = dataDir  + "osolFiles" + dirsep + "bonminEx1_Couenne.osol";
        osil = fileUtil->getFileAsString( osilFileName.c_str());
//        osol = fileUtil->getFileAsString( osolFileName.c_str());
        osol = "";
        solver->osil = osil;
        solver->osol = osol; 
//        solver->osinstance = osilreader->readOSiL( osil);
//        solver->osoption   = osolreader->readOSoL( osol);
        cout << "call the COIN - Couenne Solver for nonconvex.osil" << endl;
        solver->buildSolverInstance();
    
        std::cout << " CALL SOLVE " << std::endl;
        solver->solve();
    
        check = -6.551133;
        //ok &= NearEqual(getObjVal( solver->osrl) , check,  1e-10 , 1e-10);
        ok = ( fabs(check - getObjVal( solver->osrl) )/(fabs( check) + OS_NEAR_EQUAL) <= OS_NEAR_EQUAL) ? true : false;
        if (ok)
        {    
#ifdef DEBUG
            cout << solver->osrl << endl;
#endif
            cout << "Couenne solver solution for nonconvex.osil checks." << endl;
        }
        else
        {    cout << "Couenne solver solution for nonconvex.osil in error:" << endl;
            cout << solver->osrl << endl;
        }
        if(ok == false) throw ErrorClass(" Fail unit test with Couenne on nonconvex.osil");

        delete solver;
        solver = NULL;
        delete osilreader;
        osilreader = NULL;
        delete osolreader;
        osolreader = NULL;
        delete fileUtil;
        fileUtil = NULL;
        unitTestResult << "TEST " << nOfTest << ": Solved problem nonconvex.osil with Couenne" << std::endl;
        cout << endl << "TEST " << nOfTest << ": Completed successfully" << endl << endl;
    }
    catch(const ErrorClass& eclass){
        unitTestResultFailure  << "Sorry Unit Test Failed Testing the Couenne Solver:"  + eclass.errormsg << endl;
        if (solver != NULL)
            delete solver;
        solver = NULL;
        if (osilreader != NULL)
            delete osilreader;
        osilreader = NULL;
        if (osolreader != NULL)
            delete osolreader;
        osolreader = NULL;
        if (fileUtil != NULL)
            delete fileUtil;
        fileUtil = NULL;
    }    

    try{
        cout << endl << "TEST " << ++nOfTest << ": Couenne solver on rosenbrockorig.osil" << endl << endl;

        fileUtil = new FileUtil();
        osilreader = new OSiLReader(); 
        osolreader = new OSoLReader(); 
        solver = new CouenneSolver();

        ok = true; 
        osilFileName = dataDir  + "osilFiles" + dirsep + "rosenbrockorig.osil";
//        osolFileName = dataDir  + "osolFiles" + dirsep + "rosenbrockorig_Couenne.osol";
        osil = fileUtil->getFileAsString( osilFileName.c_str());
//        osol = fileUtil->getFileAsString( osolFileName.c_str());
        osol = "";
        solver->osil = osil;
        solver->osol = osol; 
//        solver->osinstance = osilreader->readOSiL( osil);
//        solver->osoption   = osolreader->readOSoL( osol);
        cout << "call the COIN - Couenne Solver for rosenbrockorig" << endl;
        solver->buildSolverInstance();
    
        std::cout << " CALL SOLVE " << std::endl;
        solver->solve();
    
        check = 0;
        //ok &= NearEqual(getObjVal( solver->osrl) , check,  1e-10 , 1e-10);
        ok = ( fabs(check - getObjVal( solver->osrl) )/(fabs( check) + OS_NEAR_EQUAL) <= OS_NEAR_EQUAL) ? true : false;
        if (ok)
        {    
#ifdef DEBUG
            cout << solver->osrl << endl;
#endif
            cout << "Couenne solver solution for rosenbrockorig checks." << endl;
        }
        else
        {    cout << "Couenne solver solution for rosenbrockorig in error:" << endl;

            cout << solver->osrl << endl;
        }
        if(ok == false) throw ErrorClass(" Fail unit test with Couenne on rosenbrockorig.osil");

        delete solver;
        solver = NULL;
        delete osilreader;
        osilreader = NULL;
        delete osolreader;
        osolreader = NULL;
        delete fileUtil;
        fileUtil = NULL;
        unitTestResult << "TEST " << nOfTest << ": Solved problem rosenbrockorig.osil with Couenne" << std::endl;
        cout << endl << "TEST " << nOfTest << ": Completed successfully" << endl << endl;
    }
    catch(const ErrorClass& eclass){
        unitTestResultFailure  << "Sorry Unit Test Failed Testing the Couenne Solver:"  + eclass.errormsg << endl;
        if (solver != NULL)
            delete solver;
        solver = NULL;
        if (osilreader != NULL)
            delete osilreader;
        osilreader = NULL;
        if (osolreader != NULL)
            delete osolreader;
        osolreader = NULL;
        if (fileUtil != NULL)
            delete fileUtil;
        fileUtil = NULL;
    }    

    try{
        cout << endl << "TEST " << ++nOfTest << ": Couenne solver on wayneQuadratic.osil" << endl << endl;

        fileUtil = new FileUtil();
        osilreader = new OSiLReader(); 
        osolreader = new OSoLReader(); 
        solver = new CouenneSolver();

        ok = true; 
        osilFileName = dataDir  + "osilFiles" + dirsep + "wayneQuadratic.osil";
        
//        osolFileName = dataDir  + "osolFiles" + dirsep + "rosenbrockinteger_Couenne.osol";
        osil = fileUtil->getFileAsString( osilFileName.c_str());
//        osol = fileUtil->getFileAsString( osolFileName.c_str());
        osol = "";
        solver->osinstance = NULL;
        solver->osil = osil;
        solver->osol = osol; 
//        solver->osinstance = osilreader->readOSiL( osil);
//        solver->osoption   = osolreader->readOSoL( osol);
        cout << "call the COIN - Couenne Solver for wayneQuadraticr" << endl;
        //solver->buildSolverInstance();
        std::cout << " CALL SOLVE " << std::endl;
        solver->buildSolverInstance();
        solver->setSolverOptions();
        solver->solve();
        check = 2.925;
        //ok &= NearEqual(getObjVal( solver->osrl) , check,  1e-10 , 1e-10);
        ok = ( fabs(check - getObjVal( solver->osrl) )/(fabs( check) + OS_NEAR_EQUAL) <= OS_NEAR_EQUAL) ? true : false;
        if (ok)
        {    
#ifdef DEBUG
            cout << solver->osrl << endl;
#endif
            cout << "Couenne solver solution for wayneQuadratic checks." << endl;
        }
        else
        {    cout << "Couenne solver solution for wayneQuadratic in error:" << endl;
            cout << solver->osrl << endl;
        }
        if(ok == false) throw ErrorClass(" Fail unit test with Couenne on wayneQuadratic.osil");

        delete solver;
        solver = NULL;
        delete osilreader;
        osilreader = NULL;
        delete osolreader;
        osolreader = NULL;
        delete fileUtil;
        fileUtil = NULL;
        unitTestResult << "TEST " << nOfTest << ": Solved problem wayneQuadratic.osil with Couenne (default settings)" << std::endl;
        cout << endl << "TEST " << nOfTest << ": Completed successfully" << endl << endl;
    }
    catch(const ErrorClass& eclass){
        unitTestResultFailure  << "Sorry Unit Test Failed Testing the Couenne Solver:"  + eclass.errormsg << endl;
        if (solver != NULL)
            delete solver;
        solver = NULL;
        if (osilreader != NULL)
            delete osilreader;
        osilreader = NULL;
        if (osolreader != NULL)
            delete osolreader;
        osolreader = NULL;
        if (fileUtil != NULL)
            delete fileUtil;
        fileUtil = NULL;
    }    

    OSrLWriter *tmp_writer = NULL;
    try{

        cout << endl << "TEST " << ++nOfTest << ": Couenne solver on wayneQuadratic.osil" << endl << endl;

        fileUtil = new FileUtil();
        osilreader = new OSiLReader(); 
        osolreader = new OSoLReader(); 
        solver = new CouenneSolver();

        ok = true; 
        osilFileName = dataDir  + "osilFiles" + dirsep + "wayneQuadratic.osil";
        osolFileName = dataDir  + "osolFiles" + dirsep + "wayneQuadratic_Couenne.osol";
        osil = fileUtil->getFileAsString( osilFileName.c_str());
        osol = fileUtil->getFileAsString( osolFileName.c_str());
        solver->osil = osil;
        solver->osol = osol; 
        cout << "call the COIN - Couenne Solver for wayneQuadratic.osil" << endl;
        solver->buildSolverInstance();
    
        std::cout << " CALL SOLVE " << std::endl;
        solver->solve();
    
        cout << "Here is the Couenne solver solution for wayneQuadratic" << endl;

        tmp_writer = new OSrLWriter();
        solver->osrl = tmp_writer->writeOSrL(solver->osresult);
        delete tmp_writer;
        tmp_writer = NULL;
        
        string::size_type pos;
        pos = solver->osrl.find( "LIMIT_EXCEEDED[COUENNE]");
        if(pos == std::string::npos)  
        {
            cout << solver->osrl << endl << endl;
            throw ErrorClass(" Error with wayneQuadratic.osil running on Couenne (incorrect diagnostics)");
        }
#ifdef DEBUG
        else
        {
            cout << solver->osrl << endl << endl;
        }
#endif
        delete solver;
        solver = NULL;
        delete osilreader;
        osilreader = NULL;
        delete osolreader;
        osolreader = NULL;
        delete fileUtil;
        fileUtil = NULL;
        unitTestResult << "TEST " << nOfTest << ": Correctly diagnosed wayneQuadratic.osil with Couenne (limit exceeded)" << std::endl;
        cout << endl << "TEST " << nOfTest << ": Completed successfully" << endl << endl;
    }
    catch(const ErrorClass& eclass){
        unitTestResultFailure  << "Sorry Unit Test Failed Testing the Couenne Solver:"  + eclass.errormsg << endl;
        if (solver != NULL)
            delete solver;
        solver = NULL;
        if (osilreader != NULL)
            delete osilreader;
        osilreader = NULL;
        if (osolreader != NULL)
            delete osolreader;
        osolreader = NULL;
        if (fileUtil != NULL)
            delete fileUtil;
        fileUtil = NULL;
    }    
} //end of if (THOROUGH)
#endif // end of #ifdef COIN_HAS_COUENNE
//#endif // #if 0 //for the time being --- Couenne stable 0.4 creates a segfault


    
#ifdef COIN_HAS_LINDO
    try{
        cout << endl << "TEST " << ++nOfTest << ": Lindo solver on lindoapiaddins.osil" << endl << endl;

        fileUtil = new FileUtil();
        osilreader = new OSiLReader(); 
        solver = new LindoSolver();    

        ok = true;
        osilFileName = dataDir  + "osilFiles" + dirsep + "lindoapiaddins.osil";
        osolFileName = dataDir  + "osolFiles" + dirsep + "lindoapiaddins_lindo.osol";
        osil = fileUtil->getFileAsString( osilFileName.c_str());
        osol = fileUtil->getFileAsString( osolFileName.c_str());
        cout << "create a new LINDO Solver for OSiL string solution" << endl;
        solver->osinstance = osilreader->readOSiL( osil);
        solver->osol = osol;
        cout << "call the LINDO Solver" << endl;
        solver->buildSolverInstance();
        solver->solve();
        check = 99;
        //ok &= NearEqual(getObjVal( solver->osrl) , check,  1e-10 , 1e-10);
        ok = ( fabs(check - getObjVal( solver->osrl) )/(fabs( check) + OS_NEAR_EQUAL) <= OS_NEAR_EQUAL) ? true : false;
        if (ok)
        {    
#ifdef DEBUG
            cout << solver->osrl << endl;
#endif
            cout << "LINDO solver solution for lindoapiaddins checks." << endl;
        }
        else
        {    cout << "LINDO solver solution for lindoapiaddins in error:" << endl;
            cout << solver->osrl << endl;
        }
        if(ok == false) throw ErrorClass(" Fail unit test with LINDO on lindoapiaddins.osil");
        solver->osinstance = NULL;
        delete solver;
        solver = NULL;
        delete osilreader;
        osilreader = NULL;    
        delete fileUtil;
        fileUtil = NULL;
        unitTestResult << "TEST " << nOfTest << ": Solved problem lindoapiaddins.osil with Lindo" << std::endl;
        cout << endl << "TEST " << nOfTest << ": Completed successfully" << endl << endl;
    }
    catch(const ErrorClass& eclass){
        //cout << "OSrL =  " <<  solver->osrl <<  endl;
        cout << endl << endl << endl;
        unitTestResultFailure  <<"Sorry Unit Test Failed Testing the LINDO Solver:"  + eclass.errormsg << endl << endl;
        if (solver != NULL)
            delete solver;
        solver = NULL;
        if (osilreader != NULL)
            delete osilreader;
        osilreader = NULL;
        if (fileUtil != NULL)
            delete fileUtil;
        fileUtil = NULL;
    }

if (THOROUGH == true){
    try{
        // now solve the rosenbrock problem from the OSiL paper
        cout << endl << "TEST " << ++nOfTest << ": Lindo solver on rosenbrockmod.osil" << endl << endl;

        fileUtil = new FileUtil();
        solver = new LindoSolver();    

        osilFileName = dataDir  + "osilFiles" + dirsep + "rosenbrockmod.osil";
        osolFileName = dataDir  + "osolFiles" + dirsep + "rosenbrockmod_lindo.osol";
        osil = fileUtil->getFileAsString( osilFileName.c_str());
        osol = fileUtil->getFileAsString( osolFileName.c_str());
        solver->osil = osil;
        solver->osol = osol;
        solver->osinstance = NULL;
        cout << "call the LINDO Solver" << endl;
        solver->buildSolverInstance();
        solver->solve();
        check = 6.7279;
        //ok &= NearEqual(getObjVal( solver->osrl) , check,  1e-10 , 1e-10);
        ok = ( fabs(check - getObjVal( solver->osrl) )/(fabs( check) + OS_NEAR_EQUAL) <= OS_NEAR_EQUAL) ? true : false;
        if (ok)
        {    
#ifdef DEBUG
            cout << solver->osrl << endl;
#endif
            cout << "LINDO solver solution for rosenbrockmod checks." << endl;
        }
        else
        {    cout << "LINDO solver solution for rosenbrockmod in error:" << endl;
            cout << solver->osrl << endl;
        }
        if(ok == false) throw ErrorClass(" Fail unit test with LINDO on rosenbrockmod.osil");
        solver->osinstance = NULL;
        delete solver;
        solver = NULL;
        delete fileUtil;
        fileUtil = NULL;
        unitTestResult << "TEST " << nOfTest << ": Solved problem rosenbrockmod.osil with Lindo" << std::endl;
        cout << endl << "TEST " << nOfTest << ": Completed successfully" << endl << endl;
    }
    catch(const ErrorClass& eclass){
        unitTestResultFailure  << "Sorry Unit Test Failed Testing the Lindo Solver:"  + eclass.errormsg << endl;
        if (solver != NULL)
            delete solver;
        solver = NULL;
        if (fileUtil != NULL)
            delete fileUtil;
        fileUtil = NULL;
    }    

    try{
        // now solve a pure quadratic
        cout << endl << "TEST " << ++nOfTest << ": Lindo solver on parincQuadratic.osil" << endl << endl;

        fileUtil = new FileUtil();
        osolreader = new OSoLReader(); 
        solver = new LindoSolver();    

        osilFileName = dataDir  + "osilFiles" + dirsep + "parincQuadratic.osil";
        osolFileName = dataDir  + "osolFiles" + dirsep + "parincQuadratic_lindo.osol";
        osil = fileUtil->getFileAsString( osilFileName.c_str());
        osol = fileUtil->getFileAsString( osolFileName.c_str());
        solver->osil = osil;
        solver->osol = osol;
        solver->osinstance = NULL;
        solver->osoption   = osolreader->readOSoL( osol);
        cout << "call the LINDO Solver" << endl;
        solver->buildSolverInstance();
        solver->solve();
        check = 49920.5;
        //ok &= NearEqual(getObjVal( solver->osrl) , check,  1e-10 , 1e-10);
        ok = ( fabs(check - getObjVal( solver->osrl) )/(fabs( check) + OS_NEAR_EQUAL) <= OS_NEAR_EQUAL) ? true : false;
        if (ok)
        {    
#ifdef DEBUG
            cout << solver->osrl << endl;
#endif
            cout << "LINDO solver solution for parincQuadratic checks." << endl;
        }
        else
        {    cout << "LINDO solver solution for parincQuadratic in error:" << endl;
            cout << solver->osrl << endl;
        }
        if(ok == false) throw ErrorClass(" Fail unit test with LINDO on parincQuadratic.osil");
        delete solver;
        solver = NULL;
        delete osolreader;
        osolreader = NULL;    
        delete fileUtil;
        fileUtil = NULL;
        unitTestResult << "TEST " << nOfTest << ": Solved problem parincQuadratic.osil with Lindo" << std::endl;
        cout << endl << "TEST " << nOfTest << ": Completed successfully" << endl << endl;
    }
    catch(const ErrorClass& eclass){
        unitTestResultFailure  << "Sorry Unit Test Failed Testing the LINDO Solver:"  + eclass.errormsg << endl;
        if (solver != NULL)
            delete solver;
        solver = NULL;
        if (osolreader != NULL)
            delete osolreader;
        osolreader = NULL;
        if (fileUtil != NULL)
            delete fileUtil;
        fileUtil = NULL;
    }    

    try{
        // now solve a quadratic binary problem
        // wayneQuadratic.osil
        /*
        cout << endl << "TEST " << ++nOfTest << ": Lindo solver on wayneQuadratic.osil" << endl << endl;
        osilFileName = dataDir  + "osilFiles" + dirsep + "wayneQuadratic.osil";
        osolFileName = dataDir  + "osolFiles" + dirsep + "wayneQuadratic_lindo.osol";
        osil = fileUtil->getFileAsString( osilFileName.c_str());
        osol = fileUtil->getFileAsString( osolFileName.c_str());
        osilreader = new OSiLReader(); 
        solver = new LindoSolver();    
        solver->osil = osil;
        solver->osol = osol;
        solver->osinstance = osilreader->readOSiL( osil);
        cout << "call the LINDO Solver" << endl;
        solver->buildSolverInstance();
        solver->solve();
        check = 2.925;
        //ok &= NearEqual(getObjVal( solver->osrl) , check,  1e-10 , 1e-10);
        ok = ( fabs(check - getObjVal( solver->osrl) )/(fabs( check) + OS_NEAR_EQUAL) <= OS_NEAR_EQUAL) ? true : false;
        if (ok)
        {    
#ifdef DEBUG
            cout << solver->osrl << endl;
#endif
            cout << "LINDO solver solution for wayneQuadratic checks." << endl;
        }
        else
        {    cout << "LINDO solver solution for wayneQuadratic in error:" << endl;
            cout << solver->osrl << endl;
        }
        if(ok == false) throw ErrorClass(" Fail unit test with LINDO on wayneQuadratic.osil");
        delete solver;
        solver = NULL;
        delete osolreader;
        osolreader = NULL;    
        unitTestResult << "TEST " << nOfTest << ": Solved problem wayneQuadratic.osil with Lindo" << std::endl;
        cout << endl << "TEST " << nOfTest << ": Completed successfully" << endl << endl;
    }
    catch(const ErrorClass& eclass){
        unitTestResultFailure  << "Sorry Unit Test Failed Testing the LINDO Solver:"  + eclass.errormsg << endl;
        if (solver != NULL)
            delete solver;
        solver = NULL;
        if (osilreader != NULL)
            delete osilreader;
        osilreader = NULL;
        if (osolreader != NULL)
            delete osolreader;
        osolreader = NULL;
    }    
        */
} // end of if( THOROUGH)
#endif // end of #ifdef COIN_HAS_LINDO
} // end of if(SOLVER_TESTS)



// now solve with an OSInstance created from an MPS file
if (OTHER_TESTS){
    try{
        cout << endl << "TEST " << ++nOfTest << ": Cbc solver using MPS file" << endl << endl;

        mpsFileName = dataDir +  "mpsFiles" + dirsep + "parinc.mps";
        mps2osil = new OSmps2osil( mpsFileName);
        solver = new CoinSolver();

        ok = true;
//        cout << endl;
//        cout << "Start testing MPS file conversion" << endl << endl;
        cout << "create a COIN Solver for MPS - OSInstance solution" << endl;
        solver->sSolverName = "cbc";
        mps2osil->createOSInstance() ;
        solver->osinstance = mps2osil->osinstance;
        osol = "<osol></osol>";
        solver->osol = osol;
        cout << "call COIN Solve" << endl;
        solver->buildSolverInstance();
        solver->solve();
        check = -7668;
        //ok &= NearEqual(getObjVal( solver->osrl) , check,  1e-1 , 1e-1);
        ok = ( fabs(check - getObjVal( solver->osrl) )/(fabs( check) + OS_NEAR_EQUAL) <= OS_NEAR_EQUAL) ? true : false;
        if (ok)
        {    
#ifdef DEBUG
            cout << solver->osrl << endl;
#endif
            cout << "COIN solver solution for parinc.mps checks." << endl;
        }
        else
        {    cout << "COIN solver solution for parinc.mps in error:" << endl;
            cout << solver->osrl << endl;
        }
        if(ok == false) throw ErrorClass(" Fail unit test with COIN Solver on MPS test problem parincLinear.mps");
        delete solver;
        solver = NULL;
        delete mps2osil; 
        mps2osil = NULL;
//        cout << endl;
//        cout << "Done with MPS testing" << endl;
        unitTestResult << "TEST " << nOfTest << ": Test the MPS -> OSiL converter on parinc.mps using Cbc" << std::endl;
        cout << endl << "TEST " << nOfTest << ": Completed successfully" << endl << endl;
    }
    catch(const ErrorClass& eclass){
        cout << "OSrL =  " <<  solver->osrl <<  endl;
        cout << endl << endl << endl;
        unitTestResultFailure  <<"Sorry Unit Test Failed Testing the MPS converter:"  + eclass.errormsg << endl;

        if (solver != NULL)
            delete solver;
        solver = NULL;
        if (mps2osil != NULL)
            delete mps2osil; 
        mps2osil = NULL;
    }
    
    
// test reading a GAMS file

#if  0
#ifdef COIN_HAS_GAMSUTILS
    OSgams2osil *gams2osil;
    try{
        std::cout  << "Working with GAMSIO " << std::endl;

        //std::string gmsControlFile = "/home/kmartin/bin/gams/23.2/225a/gamscntr.dat";
        std::string gmsControlFile = dataDir + "gamsFiles" + dirsep + "225a" + dirsep + "gamscntr.dat";
        gams2osil = new OSgams2osil( gmsControlFile);
     
        gams2osil->createOSInstance();
        std::cout << gams2osil->osinstance->printModel() << std::endl;
        std::cout  << "Done Working with GAMSIO " << std::endl;
        delete gams2osil;
        gams2osil = NULL;
    }
    catch(const ErrorClass& eclass){
        unitTestResultFailure  << "Sorry Unit Test Failed Testing the GAMS interface:"  + eclass.errormsg << endl;

        if (gams2osil != NULL)
            delete gams2osil;
        gams2osil = NULL;
    }    
#endif
#endif

// now solve with an OSInstance created from an AMPL nl file
#ifdef COIN_HAS_ASL
    try{
        cout << endl << "TEST " << ++nOfTest << ": AMPL solver interface" << endl << endl;

        nlFileName  = dataDir + "amplFiles" + dirsep + "parinc.nl";

        ASL *cw, *rw, *asl;
        cw = ASL_alloc(ASL_read_fg);
        rw = ASL_alloc(ASL_read_fg);
        asl = cw;

        jac0dim((char*)nlFileName.c_str(), (fint)strlen(nlFileName.c_str()));

        OSnl2OS *nl2osil = new OSnl2OS(cw, rw, asl);

        nl2osil->readNl(nlFileName) ;
 
        solver = new CoinSolver();

        cout << "create a cbc Solver for AMPL nl - OSInstance solution" << endl;
        solver->sSolverName = "cbc";
        nl2osil->createOSObjects() ;
        solver->osinstance = nl2osil->osinstance;    
        solver->osoption   = nl2osil->osoption;    

        OSiLWriter tmp_osil_writer;
        tmp_osil_writer.m_bWhiteSpace = true;
        //std::cout << tmp_osil_writer.writeOSiL( solver->osinstance) << std::endl;

//        osol = "";  //<osol></osol>";
//        solver->osol = osol;
        cout << "call Cbc Solve" << endl;
        solver->buildSolverInstance();
        solver->solve();
        check = 7668;

        ok = ( fabs(check - getObjVal( solver->osrl) )/(fabs( check) + OS_NEAR_EQUAL) <= OS_NEAR_EQUAL) ? true : false;
        if (ok)
        {    
#ifdef DEBUG
            cout << solver->osrl << endl;
#endif
            cout << "COIN cbc solver solution for parinc.nl checks." << endl;
        }
        else
        {
            cout << "COIN cbc solver solution for parinc.nl in error:" << endl;
            cout << solver->osrl << endl;
            throw ErrorClass(" Fail unit test with OSnl2osil on problem parinc.nl");
        }

        solver->osinstance = NULL;
        delete solver;
        solver = NULL;
        delete nl2osil;
        nl2osil = NULL;    
        unitTestResult << "TEST " << nOfTest << ": Test the AMPL nl -> OSiL converter on parinc.nl using Cbc" << std::endl; 
        cout << endl << "TEST " << nOfTest << ": Completed successfully" << endl << endl;
    }    
    catch(const ErrorClass& eclass){
        cout << "OSrL =  " <<  solver->osrl <<  endl;
        cout << endl << endl << endl;
        unitTestResultFailure << "Sorry Unit Test Failed Testing AMPL:" + eclass.errormsg << endl;

        if (solver != NULL)
            delete solver;
        solver = NULL;
        if (nl2osil != NULL)
            delete nl2osil; 
        nl2osil = NULL;
    }

// test the AMPL solution writer and suffix handling
    try
    {
        cout << endl << "TEST " << ++nOfTest << ": AMPL suffix handler and solution writer" << endl << endl;

        nlFileName  = dataDir + "amplFiles" + dirsep + "suffixTest.nl";

        ASL *cw, *rw, *asl;
        cw = ASL_alloc(ASL_read_fg);
        rw = ASL_alloc(ASL_read_fg);
        asl = cw;

        jac0dim((char*)nlFileName.c_str(), (fint)strlen(nlFileName.c_str()));

        OSnl2OS *nl2osil = new OSnl2OS(cw, rw, asl);

        nl2osil->readNl(nlFileName);

        fileUtil = new FileUtil();
        osolFileName = dataDir  + "osolFiles" + dirsep + "suffixTest.osol";
        nl2osil->osol = fileUtil->getFileAsString( osolFileName.c_str());
        delete fileUtil;
        fileUtil = NULL;

        std::cout << std::endl << "Create OS objects" << std::endl << std::endl;

        nl2osil->createOSObjects();

// transfer suffix information from osol to osrl
 
        std::cout << std::endl << "transfer suffix information from osol to osrl" << std::endl << std::endl;


        OSResult *osresult = new OSResult();

        int nVars = nl2osil->osinstance->getVariableNumber();
        int nObjs = nl2osil->osinstance->getObjectiveNumber();
        int nCons = nl2osil->osinstance->getConstraintNumber();

        osresult->setSolutionNumber(1);
        osresult->setVariableNumber(nVars);
        osresult->setObjectiveNumber(nObjs);
        osresult->setConstraintNumber(nCons);

        double *xval = new double[nVars];
        for (int i=0; i < nVars; i++)
            xval[i] = 1.2345;

        double *zval = new double[nCons];
        for (int i=0; i < nCons; i++)
            zval[i] = 1.3131;

        if (!osresult->setPrimalVariableValuesDense(0, xval))
            throw ErrorClass(" Fail setting primal variables in AMPL suffix handler");
        if (!osresult->setDualVariableValuesDense(0, zval))
            throw ErrorClass(" Fail setting dual variables in AMPL suffix handler");

        int* IBS;

        for (int status=0; status < ENUM_BASIS_STATUS_NUMBER_OF_STATES; status++)
        {
            int nvar = nl2osil->osoption->getNumberOfInitialBasisElements(ENUM_PROBLEM_COMPONENT_variables, status);
            if (nvar > 0)
            {
 
        std::cout << std::endl << "transfer basis info for variables" << std::endl << std::endl;

                IBS = new int[nvar];
                if (!nl2osil->osoption->getInitialBasisElements(ENUM_PROBLEM_COMPONENT_variables, status, IBS) )
                    throw ErrorClass(" Fail basis retrieval in AMPL suffix handler");
                if (!osresult->setBasisStatus(0, ENUM_PROBLEM_COMPONENT_variables, status, IBS, nvar) )
                    throw ErrorClass(" Fail basis transfer in AMPL suffix handler");
                delete[] IBS;
            }
        }

        for (int status=0; status < ENUM_BASIS_STATUS_NUMBER_OF_STATES; status++)
        {
            int ncon = nl2osil->osoption->getNumberOfInitialBasisElements(ENUM_PROBLEM_COMPONENT_constraints, status);
            if (ncon > 0)
            {
 
        std::cout << std::endl << "transfer basis info for slacks" << std::endl << std::endl;

                IBS = new int[ncon];
                if (!nl2osil->osoption->getInitialBasisElements(ENUM_PROBLEM_COMPONENT_constraints, status, IBS) )
                    throw ErrorClass(" Fail basis retrieval in AMPL suffix handler");
                if (!osresult->setBasisStatus(0, ENUM_PROBLEM_COMPONENT_constraints, status, IBS, ncon) )
                    throw ErrorClass(" Fail basis transfer in AMPL suffix handler");
                delete[] IBS;
            }
        }

        // now transfer other variable information

        int nOther = nl2osil->osoption->getNumberOfOtherVariableOptions();
        if (!osresult->setNumberOfOtherVariableResults(0, nOther + 3))
            throw ErrorClass(" Fail setting numberOfOtherVariableResults in AMPL suffix handler");
        for (int i=0; i<nOther; i++)
        {
            OtherVariableOption *otherVar = nl2osil->osoption->getOtherVariableOption(i);

 
        std::cout << std::endl << "transfer variable suffix " << otherVar->name << std::endl << std::endl;


            if (!osresult->setOtherVariableResultNumberOfVar(0, i, otherVar->numberOfVar))
                throw ErrorClass(" Fail setting OtherVariableResult in AMPL suffix handler");
            if (!osresult->setOtherVariableResultNumberOfEnumerations(0, i, otherVar->numberOfEnumerations))
                throw ErrorClass(" Fail setting OtherVariableResult in AMPL suffix handler");
            if (!osresult->setOtherVariableResultName(0, i, otherVar->name))
                throw ErrorClass(" Fail setting OtherVariableResult in AMPL suffix handler");
            if (!osresult->setOtherVariableResultType(0, i, otherVar->type))
                throw ErrorClass(" Fail setting OtherVariableResult in AMPL suffix handler");
            if (!osresult->setOtherVariableResultVarType(0, i, otherVar->varType))
                throw ErrorClass(" Fail setting OtherVariableResult in AMPL suffix handler");
            if (!osresult->setOtherVariableResultEnumType(0, i, otherVar->enumType))
                throw ErrorClass(" Fail setting OtherVariableResult in AMPL suffix handler");
            if (!osresult->setOtherVariableResultValue(0, i, otherVar->value))
                throw ErrorClass(" Fail setting OtherVariableResult in AMPL suffix handler");
            if (!osresult->setOtherVariableResultDescription(0, i, otherVar->description))
                throw ErrorClass(" Fail setting OtherVariableResult in AMPL suffix handler");

            if (otherVar->var != NULL)
            {
                for (int j=0; j < otherVar->numberOfVar; j++)
                {
                    if (!osresult->setOtherVariableResultVar(0, i, j, otherVar->var[j]->value))
                        throw ErrorClass(" Fail setting OtherVariableResult <var> array in AMPL suffix handler");
                    if (!osresult->setOtherVariableResultVarIdx(0, i, j, otherVar->var[j]->idx))
                        throw ErrorClass(" Fail setting OtherVariableResult <var> array in AMPL suffix handler");
                }
            }

            if (otherVar->enumeration != NULL)
            {
                for (int j=0; j < otherVar->numberOfEnumerations; j++)
                {
                    if (!osresult->setOtherOptionEnumeration(0, i, ENUM_PROBLEM_COMPONENT_variables, j, 
                                otherVar->enumeration[j]->value, otherVar->enumeration[j]->description, 
                                otherVar->enumeration[j]->el,    otherVar->enumeration[j]->numberOfEl)  )
                        throw ErrorClass(" Fail setting OtherVariableResult enumeration in AMPL suffix handler");
                }
            }
        }

        // add three special results. The first is "morevarinteger", mentioned in the .mod file with kind=OUT 

        std::cout << std::endl << "add variable suffix morevarinteger" << std::endl << std::endl;


        if (!osresult->setOtherVariableResultNumberOfVar(0, nOther, nVars))
            throw ErrorClass(" Fail adding OtherVariableResult in AMPL suffix handler");
        if (!osresult->setOtherVariableResultNumberOfEnumerations(0, nOther, 0))
            throw ErrorClass(" Fail adding OtherVariableResult in AMPL suffix handler");
        if (!osresult->setOtherVariableResultName(0, nOther, "morevarinteger"))
            throw ErrorClass(" Fail adding OtherVariableResult in AMPL suffix handler");
        if (!osresult->setOtherVariableResultType(0, nOther, "none"))
            throw ErrorClass(" Fail adding OtherVariableResult in AMPL suffix handler");
        if (!osresult->setOtherVariableResultVarType(0, nOther, "integer"))
            throw ErrorClass(" Fail adding OtherVariableResult in AMPL suffix handler");
        if (!osresult->setOtherVariableResultEnumType(0, nOther, "integer"))
            throw ErrorClass(" Fail adding OtherVariableResult in AMPL suffix handler");
        if (!osresult->setOtherVariableResultValue(0, nOther, ""))
            throw ErrorClass(" Fail adding OtherVariableResult in AMPL suffix handler");
        if (!osresult->setOtherVariableResultDescription(0, nOther, "to test suffixes of kind=OUT that do not show up in the .nl file"))
            throw ErrorClass(" Fail adding OtherVariableResult in AMPL suffix handler");

        for (int j=0; j < nVars; j++)
        {
            if (!osresult->setOtherVariableResultVar(0, nOther, j, 
                    static_cast<ostringstream*>( &(ostringstream() << (2*j - 2)) )->str()))
                throw ErrorClass(" Fail setting OtherVariableResult <var> array in AMPL suffix handler");
            if (!osresult->setOtherVariableResultVarIdx(0, nOther, j, j))
                throw ErrorClass(" Fail setting OtherVariableResult <var> array in AMPL suffix handler");
        }



        // add one more result, this time with an enumeration, just to be sure...

        std::cout << std::endl << "add variable suffix with enumeration" << std::endl << std::endl;


        if (!osresult->setOtherVariableResultNumberOfVar(0, nOther + 1, 0))
            throw ErrorClass(" Fail adding OtherVariableResult in AMPL suffix handler");
        if (!osresult->setOtherVariableResultNumberOfEnumerations(0, nOther + 1, 2))
            throw ErrorClass(" Fail adding OtherVariableResult in AMPL suffix handler");
        if (!osresult->setOtherVariableResultName(0, nOther + 1, "TestVarEnum"))
            throw ErrorClass(" Fail adding OtherVariableResult in AMPL suffix handler");
        if (!osresult->setOtherVariableResultType(0, nOther + 1, "none"))
            throw ErrorClass(" Fail adding OtherVariableResult in AMPL suffix handler");
        if (!osresult->setOtherVariableResultVarType(0, nOther + 1, "triple"))
            throw ErrorClass(" Fail adding OtherVariableResult in AMPL suffix handler");
        if (!osresult->setOtherVariableResultEnumType(0, nOther + 1, "integer"))
            throw ErrorClass(" Fail adding OtherVariableResult in AMPL suffix handler");
        if (!osresult->setOtherVariableResultValue(0, nOther + 1, ""))
            throw ErrorClass(" Fail adding OtherVariableResult in AMPL suffix handler");
        if (!osresult->setOtherVariableResultDescription(0, nOther + 1, "To make sure that at least one of the options has an enumeration"))
            throw ErrorClass(" Fail adding OtherVariableResult in AMPL suffix handler");

        int enumArray[2];

        enumArray[0] = 1;
        enumArray[1] = 2;
        if (!osresult->setOtherOptionEnumeration(0, nOther + 1, ENUM_PROBLEM_COMPONENT_variables, 0, "11", "First value", 
                    enumArray, 2)  )
            throw ErrorClass(" Fail adding OtherVariableResult enumeration in AMPL suffix handler");

        enumArray[0] = 3;
        enumArray[1] = 0;
        if (!osresult->setOtherOptionEnumeration(0, nOther + 1, ENUM_PROBLEM_COMPONENT_variables, 1, "12", "Last value",
                    enumArray, 2)  )
            throw ErrorClass(" Fail adding OtherVariableResult enumeration in AMPL suffix handler");

        // ...and another with just a single value

        std::cout << std::endl << "add variable suffix with value only" << std::endl << std::endl;


            if (!osresult->setOtherVariableResultNumberOfVar(0, nOther + 2, 0))
                throw ErrorClass(" Fail adding OtherVariableResult in AMPL suffix handler");
            if (!osresult->setOtherVariableResultNumberOfEnumerations(0, nOther + 2, 0))
                throw ErrorClass(" Fail adding OtherVariableResult in AMPL suffix handler");
            if (!osresult->setOtherVariableResultName(0, nOther + 2, "TestVarValue"))
                throw ErrorClass(" Fail adding OtherVariableResult in AMPL suffix handler");
            if (!osresult->setOtherVariableResultType(0, nOther + 2, "real"))
                throw ErrorClass(" Fail adding OtherVariableResult in AMPL suffix handler");
            if (!osresult->setOtherVariableResultVarType(0, nOther + 2, "double"))
                throw ErrorClass(" Fail adding OtherVariableResult in AMPL suffix handler");
            if (!osresult->setOtherVariableResultEnumType(0, nOther + 2, "none"))
                throw ErrorClass(" Fail adding OtherVariableResult in AMPL suffix handler");
            if (!osresult->setOtherVariableResultValue(0, nOther + 2, "3.14"))
                throw ErrorClass(" Fail adding OtherVariableResult in AMPL suffix handler");
            if (!osresult->setOtherVariableResultDescription(0, nOther + 2, "To make sure that at least one of the options has no array"))
                throw ErrorClass(" Fail adding OtherVariableResult in AMPL suffix handler");

        // next: transfer constraint/dual information

        nOther = nl2osil->osoption->getNumberOfOtherConstraintOptions();
        if (!osresult->setNumberOfOtherConstraintResults(0, nOther + 3))
            throw ErrorClass(" Fail setting numberOfOtherConstraintResults in AMPL suffix handler");
        for (int i=0; i<nOther; i++)
        {
            OtherConstraintOption *otherCon = nl2osil->osoption->getOtherConstraintOption(i);

        std::cout << std::endl << "transfer constraint suffix " << otherCon->name  << std::endl << std::endl;


            if (!osresult->setOtherConstraintResultNumberOfCon(0, i, otherCon->numberOfCon))
                throw ErrorClass(" Fail setting OtherConstraintResult in AMPL suffix handler");
            if (!osresult->setOtherConstraintResultNumberOfEnumerations(0, i, otherCon->numberOfEnumerations))
                throw ErrorClass(" Fail setting OtherConstraintResult in AMPL suffix handler");
            if (!osresult->setOtherConstraintResultName(0, i, otherCon->name))
                throw ErrorClass(" Fail setting OtherConstraintResult in AMPL suffix handler");
            if (!osresult->setOtherConstraintResultType(0, i, otherCon->type))
                throw ErrorClass(" Fail setting OtherConstraintResult in AMPL suffix handler");
            if (!osresult->setOtherConstraintResultConType(0, i, otherCon->conType))
                throw ErrorClass(" Fail setting OtherConstraintResult in AMPL suffix handler");
            if (!osresult->setOtherConstraintResultEnumType(0, i, otherCon->enumType))
                throw ErrorClass(" Fail setting OtherConstraintResult in AMPL suffix handler");
            if (!osresult->setOtherConstraintResultValue(0, i, otherCon->value))
                throw ErrorClass(" Fail setting OtherConstraintResult in AMPL suffix handler");
            if (!osresult->setOtherConstraintResultDescription(0, i, otherCon->description))
                throw ErrorClass(" Fail setting OtherConstraintResult in AMPL suffix handler");

            if (otherCon->con != NULL)
            {
                for (int j=0; j < otherCon->numberOfCon; j++)
                {
                    if (!osresult->setOtherConstraintResultCon(0, i, j, otherCon->con[j]->value))
                        throw ErrorClass(" Fail setting OtherConstraintResult <con> array in AMPL suffix handler");
                    if (!osresult->setOtherConstraintResultConIdx(0, i, j, otherCon->con[j]->idx))
                        throw ErrorClass(" Fail setting OtherConstraintResult <con> array in AMPL suffix handler");
                }
            }

            if (otherCon->enumeration != NULL)
            {
                for (int j=0; j < otherCon->numberOfEnumerations; j++)
                {
                    if (!osresult->setOtherOptionEnumeration(0, i, ENUM_PROBLEM_COMPONENT_constraints, j, 
                                otherCon->enumeration[j]->value, otherCon->enumeration[j]->description, 
                                otherCon->enumeration[j]->el,    otherCon->enumeration[j]->numberOfEl)  )
                        throw ErrorClass(" Fail setting OtherConstraintResult enumeration in AMPL suffix handler");
                }
            }
        }

        // add three special results. The first is "moreconinteger", mentioned in the .mod file with kind=OUT 

        std::cout << std::endl << "add variable suffix moreconinteger" << std::endl << std::endl;


        if (!osresult->setOtherConstraintResultNumberOfCon(0, nOther, nCons))
            throw ErrorClass(" Fail adding OtherConstraintResult in AMPL suffix handler");
        if (!osresult->setOtherConstraintResultNumberOfEnumerations(0, nOther, 0))
            throw ErrorClass(" Fail adding OtherConstraintResult in AMPL suffix handler");
        if (!osresult->setOtherConstraintResultName(0, nOther, "moreconinteger"))
            throw ErrorClass(" Fail adding OtherConstraintResult in AMPL suffix handler");
        if (!osresult->setOtherConstraintResultType(0, nOther, "none"))
            throw ErrorClass(" Fail adding OtherConstraintResult in AMPL suffix handler");
        if (!osresult->setOtherConstraintResultConType(0, nOther, "integer"))
            throw ErrorClass(" Fail adding OtherConstraintResult in AMPL suffix handler");
        if (!osresult->setOtherConstraintResultEnumType(0, nOther, "integer"))
            throw ErrorClass(" Fail adding OtherConstraintResult in AMPL suffix handler");
        if (!osresult->setOtherConstraintResultValue(0, nOther, ""))
            throw ErrorClass(" Fail adding OtherConstraintResult in AMPL suffix handler");
        if (!osresult->setOtherConstraintResultDescription(0, nOther, "to test suffixes of kind=OUT that do not show up in the .nl file"))
            throw ErrorClass(" Fail adding OtherConstraintResult in AMPL suffix handler");

        for (int j=0; j < nCons; j++)
        {
            if (!osresult->setOtherConstraintResultCon(0, nOther, j, "23"))
                throw ErrorClass(" Fail setting OtherConstraintResult <con> array in AMPL suffix handler");
            if (!osresult->setOtherConstraintResultConIdx(0, nOther, j, j))
                throw ErrorClass(" Fail setting OtherConstraintResult <con> array in AMPL suffix handler");
        }


        // add one more result, this time with an enumeration, just to be sure...

        std::cout << std::endl << "add constraint suffix with enumeration"  << std::endl << std::endl;


            if (!osresult->setOtherConstraintResultNumberOfCon(0, nOther+1, 0))
                throw ErrorClass(" Fail adding OtherConstraintResult in AMPL suffix handler");
            if (!osresult->setOtherConstraintResultNumberOfEnumerations(0, nOther+1, 2))
                throw ErrorClass(" Fail adding OtherConstraintResult in AMPL suffix handler");
            if (!osresult->setOtherConstraintResultName(0, nOther+1, "TestConEnum"))
                throw ErrorClass(" Fail adding OtherConstraintResult in AMPL suffix handler");
            if (!osresult->setOtherConstraintResultType(0, nOther+1, "none"))
                throw ErrorClass(" Fail adding OtherConstraintResult in AMPL suffix handler");
            if (!osresult->setOtherConstraintResultConType(0, nOther+1, "triple"))
                throw ErrorClass(" Fail adding OtherConstraintResult in AMPL suffix handler");
            if (!osresult->setOtherConstraintResultEnumType(0, nOther+1, "integer"))
                throw ErrorClass(" Fail adding OtherConstraintResult in AMPL suffix handler");
            if (!osresult->setOtherConstraintResultValue(0, nOther+1, ""))
                throw ErrorClass(" Fail adding OtherConstraintResult in AMPL suffix handler");
            if (!osresult->setOtherConstraintResultDescription(0, nOther+1, "To make sure that at least one of the options has an enumeration"))
                throw ErrorClass(" Fail adding OtherConstraintResult in AMPL suffix handler");

        enumArray[0] = 2;
        enumArray[1] = 3;
        if (!osresult->setOtherOptionEnumeration(0, nOther+1, ENUM_PROBLEM_COMPONENT_constraints, 0, "21", "First value", 
                    enumArray, 2)  )
            throw ErrorClass(" Fail adding OtherConstraintResult enumeration in AMPL suffix handler");

        enumArray[0] = 1;
        enumArray[1] = 0;
        if (!osresult->setOtherOptionEnumeration(0, nOther+1, ENUM_PROBLEM_COMPONENT_constraints, 1, "22", "Last value",
                    enumArray, 2)  )
            throw ErrorClass(" Fail adding OtherConstraintResult enumeration in AMPL suffix handler");

        // ...and another with just a single value

        std::cout << std::endl << "add constraint suffix with value only"  << std::endl << std::endl;


            if (!osresult->setOtherConstraintResultNumberOfCon(0, nOther + 2, 0))
                throw ErrorClass(" Fail adding OtherConstraintResult in AMPL suffix handler");
            if (!osresult->setOtherConstraintResultNumberOfEnumerations(0, nOther + 2, 0))
                throw ErrorClass(" Fail adding OtherConstraintResult in AMPL suffix handler");
            if (!osresult->setOtherConstraintResultName(0, nOther + 2, "TestConValue"))
                throw ErrorClass(" Fail adding OtherConstraintResult in AMPL suffix handler");
            if (!osresult->setOtherConstraintResultType(0, nOther + 2, "real"))
                throw ErrorClass(" Fail adding OtherConstraintResult in AMPL suffix handler");
            if (!osresult->setOtherConstraintResultConType(0, nOther + 2, "double"))
                throw ErrorClass(" Fail adding OtherConstraintResult in AMPL suffix handler");
            if (!osresult->setOtherConstraintResultEnumType(0, nOther + 2, "none"))
                throw ErrorClass(" Fail adding OtherConstraintResult in AMPL suffix handler");
            if (!osresult->setOtherConstraintResultValue(0, nOther + 2, "2.71828"))
                throw ErrorClass(" Fail adding OtherConstraintResult in AMPL suffix handler");
            if (!osresult->setOtherConstraintResultDescription(0, nOther + 2, "To make sure that at least one of the options has no array"))
                throw ErrorClass(" Fail adding OtherConstraintResult in AMPL suffix handler");


        // next: transfer objective information

        nOther = nl2osil->osoption->getNumberOfOtherObjectiveOptions();
        if (!osresult->setNumberOfOtherObjectiveResults(0, nOther + 3))
            throw ErrorClass(" Fail setting numberOfOtherVariableResults in AMPL suffix handler");
        for (int i=0; i<nOther; i++)
        {
            OtherObjectiveOption *otherObj = nl2osil->osoption->getOtherObjectiveOption(i);

            std::cout << std::endl << "transfer objective suffix " << otherObj->name << std::endl << std::endl;


            if (!osresult->setOtherObjectiveResultNumberOfObj(0, i, otherObj->numberOfObj))
                throw ErrorClass(" Fail setting OtherObjectiveResult in AMPL suffix handler");
            if (!osresult->setOtherObjectiveResultNumberOfEnumerations(0, i, otherObj->numberOfEnumerations))
                throw ErrorClass(" Fail setting OtherObjectiveResult in AMPL suffix handler");
            if (!osresult->setOtherObjectiveResultName(0, i, otherObj->name))
                throw ErrorClass(" Fail setting OtherObjectiveResult in AMPL suffix handler");
            if (!osresult->setOtherObjectiveResultType(0, i, otherObj->type))
                throw ErrorClass(" Fail setting OtherObjectiveResult in AMPL suffix handler");
            if (!osresult->setOtherObjectiveResultObjType(0, i, otherObj->objType))
                throw ErrorClass(" Fail setting OtherObjectiveResult in AMPL suffix handler");
            if (!osresult->setOtherObjectiveResultEnumType(0, i, otherObj->enumType))
                throw ErrorClass(" Fail setting OtherObjectiveResult in AMPL suffix handler");
            if (!osresult->setOtherObjectiveResultValue(0, i, otherObj->value))
                throw ErrorClass(" Fail setting OtherObjectiveResult in AMPL suffix handler");
            if (!osresult->setOtherObjectiveResultDescription(0, i, otherObj->description))
                throw ErrorClass(" Fail setting OtherObjectiveResult in AMPL suffix handler");

            if (otherObj->obj != NULL)
            {
                for (int j=0; j < otherObj->numberOfObj; j++)
                {
                    if (!osresult->setOtherObjectiveResultObj(0, i, j, otherObj->obj[j]->value))
                        throw ErrorClass(" Fail setting OtherObjectiveResult <obj> array in AMPL suffix handler");
                    if (!osresult->setOtherObjectiveResultObjIdx(0, i, j, otherObj->obj[j]->idx))
                        throw ErrorClass(" Fail setting OtherObjectiveResult <obj> array in AMPL suffix handler");
                }
            }

            if (otherObj->enumeration != NULL)
            {
                for (int j=0; j < otherObj->numberOfEnumerations; j++)
                {
                    if (!osresult->setOtherOptionEnumeration(0, i, ENUM_PROBLEM_COMPONENT_objectives, j, 
                                otherObj->enumeration[j]->value, otherObj->enumeration[j]->description, 
                                otherObj->enumeration[j]->el,    otherObj->enumeration[j]->numberOfEl)  )
                        throw ErrorClass(" Fail setting OtherObjectiveResult enumeration in AMPL suffix handler");
                }
            }
        }


        // add three special results. The first is "moreobjinteger", mentioned in the .mod file with kind=OUT 

        std::cout << std::endl << "add variable suffix moreobjinteger" << std::endl << std::endl;


        if (!osresult->setOtherObjectiveResultNumberOfObj(0, nOther, nObjs))
            throw ErrorClass(" Fail adding OtherObjectiveResult in AMPL suffix handler");
        if (!osresult->setOtherObjectiveResultNumberOfEnumerations(0, nOther, 0))
            throw ErrorClass(" Fail adding OtherObjectiveResult in AMPL suffix handler");
        if (!osresult->setOtherObjectiveResultName(0, nOther, "moreobjinteger"))
            throw ErrorClass(" Fail adding OtherObjectiveResult in AMPL suffix handler");
        if (!osresult->setOtherObjectiveResultType(0, nOther, "none"))
            throw ErrorClass(" Fail adding OtherObjectiveResult in AMPL suffix handler");
        if (!osresult->setOtherObjectiveResultObjType(0, nOther, "integer"))
            throw ErrorClass(" Fail adding OtherObjectiveResult in AMPL suffix handler");
        if (!osresult->setOtherObjectiveResultEnumType(0, nOther, "integer"))
            throw ErrorClass(" Fail adding OtherObjectiveResult in AMPL suffix handler");
        if (!osresult->setOtherObjectiveResultValue(0, nOther, ""))
            throw ErrorClass(" Fail adding OtherObjectiveResult in AMPL suffix handler");
        if (!osresult->setOtherObjectiveResultDescription(0, nOther, "to test suffixes of kind=OUT that do not show up in the .nl file"))
            throw ErrorClass(" Fail adding OtherObjectiveResult in AMPL suffix handler");

        for (int j=0; j < nObjs; j++)
        {
            if (!osresult->setOtherObjectiveResultObj(0, nOther, j, "8"))
                throw ErrorClass(" Fail setting OtherObjectiveResult <obj> array in AMPL suffix handler");
            if (!osresult->setOtherObjectiveResultObjIdx(0, nOther, j, -1 - j))
                throw ErrorClass(" Fail setting OtherObjectiveResult <obj> array in AMPL suffix handler");
        }

        // add one more result, this time with an enumeration, just to be sure...

        std::cout << std::endl << "add objective suffix with enumeration" << std::endl << std::endl;


            if (!osresult->setOtherObjectiveResultNumberOfObj(0, nOther + 1, 0))
                throw ErrorClass(" Fail adding OtherObjectiveResult in AMPL suffix handler");
            if (!osresult->setOtherObjectiveResultNumberOfEnumerations(0, nOther + 1, 1))
                throw ErrorClass(" Fail adding OtherObjectiveResult in AMPL suffix handler");
            if (!osresult->setOtherObjectiveResultName(0, nOther + 1, "TestObjEnum"))
                throw ErrorClass(" Fail adding OtherObjectiveResult in AMPL suffix handler");
            if (!osresult->setOtherObjectiveResultType(0, nOther + 1, "none"))
                throw ErrorClass(" Fail adding OtherObjectiveResult in AMPL suffix handler");
            if (!osresult->setOtherObjectiveResultObjType(0, nOther + 1, "triple"))
                throw ErrorClass(" Fail adding OtherObjectiveResult in AMPL suffix handler");
            if (!osresult->setOtherObjectiveResultEnumType(0, nOther + 1, "integer"))
                throw ErrorClass(" Fail adding OtherObjectiveResult in AMPL suffix handler");
            if (!osresult->setOtherObjectiveResultValue(0, nOther + 1, ""))
                throw ErrorClass(" Fail adding OtherObjectiveResult in AMPL suffix handler");
            if (!osresult->setOtherObjectiveResultDescription(0, nOther + 1, "To make sure that at least one of the options has an enumeration"))
                throw ErrorClass(" Fail adding OtherObjectiveResult in AMPL suffix handler");

        int objArray[1];
        objArray[0] = -1;
        if (!osresult->setOtherOptionEnumeration(0, nOther + 1, ENUM_PROBLEM_COMPONENT_objectives, 0, "31", "Only value", 
                    objArray, 1)  )
            throw ErrorClass(" Fail adding OtherObjectiveResult enumeration in AMPL suffix handler");

        // ...and another with just a single value

        std::cout << std::endl << "add objective suffix with value only" << std::endl << std::endl;


            if (!osresult->setOtherObjectiveResultNumberOfObj(0, nOther + 2, 0))
                throw ErrorClass(" Fail adding OtherObjectiveResult in AMPL suffix handler");
            if (!osresult->setOtherObjectiveResultNumberOfEnumerations(0, nOther + 2, 0))
                throw ErrorClass(" Fail adding OtherObjectiveResult in AMPL suffix handler");
            if (!osresult->setOtherObjectiveResultName(0, nOther + 2, "TestObjValue"))
                throw ErrorClass(" Fail adding OtherObjectiveResult in AMPL suffix handler");
            if (!osresult->setOtherObjectiveResultType(0, nOther + 2, "real"))
                throw ErrorClass(" Fail adding OtherObjectiveResult in AMPL suffix handler");
            if (!osresult->setOtherObjectiveResultObjType(0, nOther + 2, "double"))
                throw ErrorClass(" Fail adding OtherObjectiveResult in AMPL suffix handler");
            if (!osresult->setOtherObjectiveResultEnumType(0, nOther + 2, "none"))
                throw ErrorClass(" Fail adding OtherObjectiveResult in AMPL suffix handler");
            if (!osresult->setOtherObjectiveResultValue(0, nOther + 2, "2.71828"))
                throw ErrorClass(" Fail adding OtherObjectiveResult in AMPL suffix handler");
            if (!osresult->setOtherObjectiveResultDescription(0, nOther + 2, "To make sure that at least one of the options has no array"))
                throw ErrorClass(" Fail adding OtherObjectiveResult in AMPL suffix handler");

        // make sure to add a solution status for schema conformance...

        if (!osresult->setSolutionStatus(0, "optimal", "") )
                throw ErrorClass(" Fail setting solution status in AMPL suffix handler");


        // write osrl to suffixtest.sol

        std::cout << std::endl << "convert OSResult to string" << std::endl << std::endl;

        OSrLWriter *temp_writer = new OSrLWriter();

        std::string osrl = temp_writer->writeOSrL( osresult);
        std::cout  << osrl << std::endl;

        bool writeOK;
        OSosrl2ampl *solWriter = new OSosrl2ampl();

        std::cout << std::endl << "write AMPL solution file" << std::endl << std::endl;

        writeOK = solWriter->writeSolFile(osrl, nl2osil->getASL("asl"), dataDir +  "amplFiles" + dirsep + "suffixTest.sol");

        delete solWriter;
        solWriter = NULL;

        delete osresult;
        osresult = NULL;

// compare suffixtest.sol to suffixtest.cmp

        std::cout << std::endl << "compare results" << std::endl << std::endl;

        std::string osrl1FileName = dataDir +  "amplFiles" + dirsep + "suffixTest.sol";
        std::string osrl2FileName = dataDir +  "amplFiles" + dirsep + "suffixTest.cmp";

        fileUtil = new FileUtil();
        std::string osrl1 = fileUtil->getFileAsString( osrl1FileName.c_str());
        std::string osrl2 = fileUtil->getFileAsString( osrl2FileName.c_str());

        if (osrl1 == osrl2)
        {    
#ifdef DEBUG
            cout << osrl1 << endl;
#endif
            cout << "AMPL .sol file writer creates consistent output" << endl;
        }
        else
        {   
            cout << "AMPL .sol file writer creates incorrect output" << endl;
            cout << osrl1 << endl;
            throw ErrorClass(" Fail unit test with AMPL .sol writer");
        } 

        delete nl2osil;
        nl2osil = NULL;
        delete fileUtil;
        fileUtil = NULL;    
        unitTestResult << "TEST " << nOfTest << ": Test the AMPL .sol writer" << std::endl; 
        cout << endl << "TEST " << nOfTest << ": Completed successfully" << endl << endl;
    }    
    catch(const ErrorClass& eclass)
    {
        unitTestResultFailure << "Sorry Unit Test Failed Testing AMPL .sol writer:" + eclass.errormsg << endl;

        if (nl2osil != NULL)
            delete nl2osil; 
        nl2osil = NULL;
    }

#endif

    //
    // Now read an mps file and write in b64 format to test the b64 feature 
    //
    try{
        cout << endl << "TEST " << ++nOfTest << ": b64 operations" << endl << endl;

        mpsFileName = dataDir +  "mpsFiles" + dirsep + "parinc.mps";
        mps2osil = new OSmps2osil( mpsFileName);
        solver = new CoinSolver();

        ok = true;
        OSiLWriter osilwriter;
        osilwriter.m_bWriteBase64 = true;
        solver->sSolverName = "cbc";
        solver->osinstance = NULL;
        osol = "<osol></osol>";
        solver->osol = osol;
        mps2osil->createOSInstance();
        solver->osil = osilwriter.writeOSiL( mps2osil->osinstance);
        //std::cout << solver->osil << std::endl;
        solver->buildSolverInstance();
        solver->solve();
        cout << endl << endl;
        check = -7668;
        //ok &= NearEqual(getObjVal( solver->osrl) , check,  1e-1 , 1e-1);
        ok = ( fabs(check - getObjVal( solver->osrl) )/(fabs( check) + OS_NEAR_EQUAL) <= OS_NEAR_EQUAL) ? true : false;
        if (ok)
        {    cout << "COIN solution of an OSiL string in b64 format." << endl;
#ifdef DEBUG
            cout << solver->osrl << endl;
#endif            
        }
        else
        {    cout << "COIN solution of a OSiL string in b64 format:" << endl;
            cout << solver->osrl << endl;
        }
        if(ok == false) throw ErrorClass(" Fail unit test with COIN Cbc Solver on b64 test problem parincLinear.mps");
        solver->osinstance = NULL;
        delete solver;
        solver = NULL;
        delete mps2osil;
        mps2osil = NULL;
        unitTestResult << "TEST " << nOfTest << ": Test a problem written in b64 and then converted to OSInstance" << std::endl;
        cout << endl << "TEST " << nOfTest << ": Completed successfully" << endl << endl;
    }    
    catch(const ErrorClass& eclass){
        cout << endl << endl;
        cout << eclass.errormsg <<  endl << endl;
        cout << "OSrL =  " <<  solver->osrl <<  endl;
        cout << endl << endl << endl;
        unitTestResultFailure   << "Sorry Unit Test Failed Testing Use of Base 64" << endl;

        if (solver != NULL)
            delete solver;
        solver = NULL;
        if (mps2osil != NULL)
            delete mps2osil; 
        mps2osil = NULL;
    }  


    // now test postfix and prefix routines
    try{
        cout << endl << "TEST " << ++nOfTest << ": postfix and prefix routines" << endl << endl;

        fileUtil = new FileUtil();
        osilreader = new OSiLReader();

        std::string expTreeTest =  dataDir  + "osilFiles" + dirsep + "rosenbrockmod.osil";
        osil = fileUtil->getFileAsString( expTreeTest.c_str() ) ;
        //create an osinstance
        osinstance = osilreader->readOSiL( osil);
        OSExpressionTree* expTree = osinstance->getNonlinearExpressionTree( -1);
        if(expTree == NULL) throw ErrorClass(" Null expression tree when testing prefix and postfix routines");
        std::vector<OSnLNode*> postfixVec;
        //postfixVec = expTree->m_treeRoot->getPostfixFromExpressionTree();
        postfixVec = osinstance->getNonlinearExpressionTreeInPostfix( -1);
    
        unsigned int n = postfixVec.size();
        unsigned int i;
        nodeNames1 = new std::string[ n];
        nodeNames2 = new std::string[ n];
        for (i = 0 ; i < n; i++){
            //std::cout << postfixVec[i]->getTokenName() << std::endl;
            nodeNames1[i] = postfixVec[i]->getTokenName();
        }
        
        // now create back the expression tree 
        expTree->m_treeRoot = postfixVec[ n - 1]->createExpressionTreeFromPostfix( postfixVec);
    
        // now get in prefix
        std::vector<OSnLNode*> prefixVec;
        //prefixVec = expTree->m_treeRoot->getPrefixFromExpressionTree();
        prefixVec = osinstance->getNonlinearExpressionTreeInPrefix( -1);
        
        // now create back the expression tree
        expTree->m_treeRoot = prefixVec[ 0]->createExpressionTreeFromPrefix( prefixVec);
        
        // now get postfix vector again and compare with original
        postfixVec = expTree->m_treeRoot->getPostfixFromExpressionTree();
        //postfixVec = osinstance->getNonlinearExpressionTreeInPostfix( -1);
        if(postfixVec.size() != n) throw ErrorClass(" Problem with creating expression trees");
        //std::cout << std::endl << std::endl;
        for (i = 0 ; i < n; i++){
            //std::cout << postfixVec[i]->getTokenName() << std::endl;
            nodeNames2[i] = postfixVec[i]->getTokenName();
            if( nodeNames1[i] != nodeNames2[ i]) throw ErrorClass(" Problem with creating expression trees");
        }    
        
        delete[] nodeNames1;
        nodeNames1 = NULL;
        delete[] nodeNames2; 
        nodeNames2 = NULL;
        delete osilreader;
        osilreader = NULL;
        delete fileUtil;
        fileUtil = NULL;
        unitTestResult << "TEST " << nOfTest << ": Successful test of prefix and postfix conversion routines" << std::endl;
        cout << endl << "TEST " << nOfTest << ": Completed successfully" << endl << endl;        
    }
    catch(const ErrorClass& eclass){
        cout << endl << endl << endl;
        unitTestResultFailure << eclass.errormsg << endl;
        if (osilreader != NULL)
            delete osilreader;
        osilreader = NULL;
        if (nodeNames1 != NULL)
            delete[] nodeNames1;
        nodeNames1 = NULL;
        if (nodeNames2 != NULL)
            delete[] nodeNames2; 
        nodeNames2 = NULL;
        if (fileUtil != NULL)
            delete fileUtil;
        fileUtil = NULL;
    }

} //end of if (OTHER_TESTS)
  
    if(unitTestResultFailure.str().length() > 0){
        cout << endl << "THE UNIT TEST PASSED THE FOLLOWING:" << endl << endl;
        cout << unitTestResult.str() << endl << endl;
        cout << "UNFORTUNATELY, YOU FAILED ON THE FOLLOWING:" << endl << endl;
        cout << unitTestResultFailure.str() << endl << endl;
        cout << "Conclusion: FAILURE" << endl;
        return 1;
    }
    else{
        cout << endl << "THE UNIT TEST PASSED THE FOLLOWING:" << endl << endl;
        cout << unitTestResult.str() << endl << endl;
        cout << "All tests completed successfully" <<  endl <<  endl;
#ifdef GUS_DEBUG
        cout << "Make sure to #undef GUS_DEBUG before committing!!!" <<  endl <<  endl;
#endif
        return 0;
    }

}//end main

double getObjVal( std::string osrl){
    std::string sObjVal;
    double dObjVal;
    string::size_type pos2;
    string::size_type pos1 = osrl.find( "<obj ");
    if(pos1 != std::string::npos){
        // get the end of the obj start tag
        pos1 = osrl.find(">", pos1 + 1);
        if(pos1 != std::string::npos){
            // get the start of obj end tag

            pos2 = osrl.find( "</obj", pos1 + 1);
            if( pos2 != std::string::npos){
                // get the substring
                sObjVal = osrl.substr( pos1 + 1, pos2 - pos1 - 1);
                //std::cout << "HERE IS THE OBJECTIVE FUNCTION VALUE SUBSTRING  " << sObjVal<< std::endl; 
                // return dObjVal = strtod(sObjVal.c_str(), NULL);
                return dObjVal = os_strtod(sObjVal.c_str(), NULL); 
            }
        }
    }
    return OSNaN();
}

//#if 0
int getItCount( std::string osrl)
{
    OSrLReader *osrlreader = NULL;
    try
    {
        OSResult *osresult = NULL;
        osrlreader = new OSrLReader();
        osresult =  osrlreader->readOSrL(osrl);
        int nIter;

        std::string temp = osresult->getOtherSolutionResultValue(0, 0);

        nIter = atoi(temp.c_str());
        if (osrlreader != NULL) delete osrlreader;
        osrlreader = NULL;
        return nIter; 
    }
    catch(const ErrorClass& eclass)
    {
        if (osrlreader != NULL) delete osrlreader;
        osrlreader = NULL;
        return -1;
    }
}
//#endif


void tempPrintArrays(OSResult* os)
{
    std::cout << "Print out array content" << std::endl;
    for (int i=0; i < os->optimization->numberOfSolutions; ++i)
    {
        std::cout << "solution " << i << std::endl << std::endl;
        std::cout << "variables   basic      ";
        std::cout << os->optimization->solution[i]->variables->basisStatus->basic->el[0] << "  ";
        std::cout << os->optimization->solution[i]->variables->basisStatus->basic->el[1] << "  ";
        std::cout << os->optimization->solution[i]->variables->basisStatus->basic->el[2] << endl;
        std::cout << "variables   atLower    ";
        std::cout << os->optimization->solution[i]->variables->basisStatus->atLower->el[0] << "  ";
        std::cout << os->optimization->solution[i]->variables->basisStatus->atLower->el[1] << "  ";
        std::cout << os->optimization->solution[i]->variables->basisStatus->atLower->el[2] << endl;
        std::cout << "variables   atUpper    ";
        std::cout << os->optimization->solution[i]->variables->basisStatus->atUpper->el[0] << "  ";
        std::cout << os->optimization->solution[i]->variables->basisStatus->atUpper->el[1] << "  ";
        std::cout << os->optimization->solution[i]->variables->basisStatus->atUpper->el[2] << endl;
        std::cout << "variables   atEquality ";
        std::cout << os->optimization->solution[i]->variables->basisStatus->atEquality->el[0] << "  ";
        std::cout << os->optimization->solution[i]->variables->basisStatus->atEquality->el[1] << "  ";
        std::cout << os->optimization->solution[i]->variables->basisStatus->atEquality->el[2] << endl;
        std::cout << "variables   isFree     ";
        std::cout << os->optimization->solution[i]->variables->basisStatus->isFree->el[0] << "  ";
        std::cout << os->optimization->solution[i]->variables->basisStatus->isFree->el[1] << "  ";
        std::cout << os->optimization->solution[i]->variables->basisStatus->isFree->el[2] << endl;
        std::cout << "variables   superbasic ";
        std::cout << os->optimization->solution[i]->variables->basisStatus->superbasic->el[0] << "  ";
        std::cout << os->optimization->solution[i]->variables->basisStatus->superbasic->el[1] << "  ";
        std::cout << os->optimization->solution[i]->variables->basisStatus->superbasic->el[2] << endl;
        std::cout << "variables   unknown    ";
        std::cout << os->optimization->solution[i]->variables->basisStatus->unknown->el[0] << "  ";
        std::cout << os->optimization->solution[i]->variables->basisStatus->unknown->el[1] << "  ";
        std::cout << os->optimization->solution[i]->variables->basisStatus->unknown->el[2] << endl;

        std::cout << std::endl;


        std::cout << "objectives  basic      ";
        std::cout << os->optimization->solution[i]->objectives->basisStatus->basic->el[0] << "  ";
        std::cout << os->optimization->solution[i]->objectives->basisStatus->basic->el[1] << "  ";
        std::cout << os->optimization->solution[i]->objectives->basisStatus->basic->el[2] << endl;
        std::cout << "objectives  atLower    ";
        std::cout << os->optimization->solution[i]->objectives->basisStatus->atLower->el[0] << "  ";
        std::cout << os->optimization->solution[i]->objectives->basisStatus->atLower->el[1] << "  ";
        std::cout << os->optimization->solution[i]->objectives->basisStatus->atLower->el[2] << endl;
        std::cout << "objectives  atUpper    ";
        std::cout << os->optimization->solution[i]->objectives->basisStatus->atUpper->el[0] << "  ";
        std::cout << os->optimization->solution[i]->objectives->basisStatus->atUpper->el[1] << "  ";
        std::cout << os->optimization->solution[i]->objectives->basisStatus->atUpper->el[2] << endl;
        std::cout << "objectives  atEquality ";
        std::cout << os->optimization->solution[i]->objectives->basisStatus->atEquality->el[0] << "  ";
        std::cout << os->optimization->solution[i]->objectives->basisStatus->atEquality->el[1] << "  ";
        std::cout << os->optimization->solution[i]->objectives->basisStatus->atEquality->el[2] << endl;
        std::cout << "objectives  isFree     ";
        std::cout << os->optimization->solution[i]->objectives->basisStatus->isFree->el[0] << "  ";
        std::cout << os->optimization->solution[i]->objectives->basisStatus->isFree->el[1] << "  ";
        std::cout << os->optimization->solution[i]->objectives->basisStatus->isFree->el[2] << endl;
        std::cout << "objectives  superbasic ";
        std::cout << os->optimization->solution[i]->objectives->basisStatus->superbasic->el[0] << "  ";
        std::cout << os->optimization->solution[i]->objectives->basisStatus->superbasic->el[1] << "  ";
        std::cout << os->optimization->solution[i]->objectives->basisStatus->superbasic->el[2] << endl;
        std::cout << "objectives  unknown    ";
        std::cout << os->optimization->solution[i]->objectives->basisStatus->unknown->el[0] << "  ";
        std::cout << os->optimization->solution[i]->objectives->basisStatus->unknown->el[1] << "  ";
        std::cout << os->optimization->solution[i]->objectives->basisStatus->unknown->el[2] << endl;

        std::cout << std::endl;

        std::cout << "constraints basic      ";
        std::cout << os->optimization->solution[i]->constraints->basisStatus->basic->el[0] << "  ";
        std::cout << os->optimization->solution[i]->constraints->basisStatus->basic->el[1] << "  ";
        std::cout << os->optimization->solution[i]->constraints->basisStatus->basic->el[2] << endl;
        std::cout << "constraints atLower    ";
        std::cout << os->optimization->solution[i]->constraints->basisStatus->atLower->el[0] << "  ";
        std::cout << os->optimization->solution[i]->constraints->basisStatus->atLower->el[1] << "  ";
        std::cout << os->optimization->solution[i]->constraints->basisStatus->atLower->el[2] << endl;
        std::cout << "constraints atUpper    ";
        std::cout << os->optimization->solution[i]->constraints->basisStatus->atUpper->el[0] << "  ";
        std::cout << os->optimization->solution[i]->constraints->basisStatus->atUpper->el[1] << "  ";
        std::cout << os->optimization->solution[i]->constraints->basisStatus->atUpper->el[2] << endl;
        std::cout << "constraints atEquality ";
        std::cout << os->optimization->solution[i]->constraints->basisStatus->atEquality->el[0] << "  ";
        std::cout << os->optimization->solution[i]->constraints->basisStatus->atEquality->el[1] << "  ";
        std::cout << os->optimization->solution[i]->constraints->basisStatus->atEquality->el[2] << endl;
        std::cout << "constraints isFree     ";
        std::cout << os->optimization->solution[i]->constraints->basisStatus->isFree->el[0] << "  ";
        std::cout << os->optimization->solution[i]->constraints->basisStatus->isFree->el[1] << "  ";
        std::cout << os->optimization->solution[i]->constraints->basisStatus->isFree->el[2] << endl;
        std::cout << "constraints superbasic ";
        std::cout << os->optimization->solution[i]->constraints->basisStatus->superbasic->el[0] << "  ";
        std::cout << os->optimization->solution[i]->constraints->basisStatus->superbasic->el[1] << "  ";
        std::cout << os->optimization->solution[i]->constraints->basisStatus->superbasic->el[2] << endl;
        std::cout << "constraints unknown    ";
        std::cout << os->optimization->solution[i]->constraints->basisStatus->unknown->el[0] << "  ";
        std::cout << os->optimization->solution[i]->constraints->basisStatus->unknown->el[1] << "  ";
        std::cout << os->optimization->solution[i]->constraints->basisStatus->unknown->el[2] << endl;

        std::cout << std::endl;

        for (int k=0; k < os->optimization->solution[i]->variables->other[2]->numberOfEnumerations; k++)
        {

            std::cout << "other variable results --- enum " << k;
            std::cout << "  " << os->optimization->solution[i]->variables->other[2]->enumeration[k]->el[0];
            std::cout << "  " << os->optimization->solution[i]->variables->other[2]->enumeration[k]->el[1];
            std::cout << "  " << os->optimization->solution[i]->variables->other[2]->enumeration[k]->el[2];

            std::cout << std::endl;
        }

        std::cout << std::endl;

        for (int k=0; k < os->optimization->solution[i]->objectives->other[2]->numberOfEnumerations; k++)
        {
            std::cout << "other objective results --- enum " << k;
            std::cout << "  " << os->optimization->solution[i]->objectives->other[2]->enumeration[k]->el[0];
            std::cout << "  " << os->optimization->solution[i]->objectives->other[2]->enumeration[k]->el[1];
            std::cout << "  " << os->optimization->solution[i]->objectives->other[2]->enumeration[k]->el[2];

            std::cout << std::endl;
        }

        std::cout << std::endl;

        for (int k=0; k < os->optimization->solution[i]->constraints->other[2]->numberOfEnumerations; k++)
        {
            std::cout << "other constraint results --- enum " << k;
            std::cout << "  " << os->optimization->solution[i]->constraints->other[2]->enumeration[k]->el[0];
            std::cout << "  " << os->optimization->solution[i]->constraints->other[2]->enumeration[k]->el[1];
            std::cout << "  " << os->optimization->solution[i]->constraints->other[2]->enumeration[k]->el[2];

            std::cout << std::endl;
        }
        return;
    }
}

