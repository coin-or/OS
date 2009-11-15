/* $Id$ */
/** @file unitTest.cpp
 * 
 * \brief This file runs the OS unitTest.
  
 *
 * @author  Robert Fourer, Horand Gassmann, Jun Ma, Kipp Martin, 
 * @version 1.1, 05/Feb/2008
 * @since   OS1.0
 *
 * \remarks
 * Copyright (C) 2005-2008, Robert Fourer, Horand Gassmann, Jun Ma, Kipp Martin,
 * Northwestern University, Dalhousie University, and the University of Chicago.
 * All Rights Reserved.
 * This software is licensed under the Common Public License. 
 * Please see the accompanying LICENSE file in root directory for terms.
 * 
 * 
 * This is the OS unitTest. It currently runs the following tests.
 * 
 * Solvers:
 * 
 * COIN-Clp tested on parincLinearByRow.osil
 * 
 * COIN-Cbc tested on p0033.osil
 * 
 * COIN-Ipopt tested on:
 * <ol>
 * <li> avion2.osil  </li>
 * <li> HS071_NLP.osil </li>
 * <li> rosenbrockmod.osil </li>
 * <li> parincQuadratic.osil </li>
 * <li> parincLinear.osil  </li>
 * <li> callBackTest.osil </li>
 * <li> callBackTestRowMajor.osil </li>
 * </ol>
 *
 * COIN-SYMPHONY test on p0033.osil
 * COIN-BONMIN test on bonminEx1.osil and wayneQuadratic
 * 
 * COIN-DyLP tested onparincLinear.osil
 * 
 * COIN-Volume tested on volumeTest.osil
 * 
 * GLPK tested on p0033.osil
 * 
 * Cplex tested on p0033.osil
 * 
 * Lindo tested on:
 * <ol>
 * <li> lindoapiaddins.osil </li>
 * <li> rosenbrockmode.osil </li>
 * <li> parincquadratic.osil </li>
 * <li> wayneQuadratic.osil  </li>
 * </ol>
 * 
 * We test the mps to osil converter
 * progam OSmps2osil on parincLinear.mps. Solve with
 * Cbc.
 * 
 * We test the AMPL nl file format to osil converter
 * program OSnl2osil on hs71.nl. Solve with Lindo.
 * 
 * We test the base 64 format on problem parincLinear.  
 * We first read in the parinc.mps file into an
 * osil string and then set m_bWriteBase64 = true. We then
 * write a new instance in base 64 format and solve it.
 * 
 * In addition there are a number of tests concerning th logic of many
 * of the components of the OS project. These tests have little in common
 * with the installation and functionality tests, but they are useful for
 * debugging and to give a thorough workout to the program logic.
 * These tests can be added selectively using several conditional variables:
 * <ol>
 * <li> INSTALLATION_TEST. This turns the installation and solver tests on and off </li>
 * <li> THOROUGH.          To test more than one test problem for each solver </li>
 * <li> COMPONENT_DEBUG.   This turns the tests of the program logic an and off </li>
 * </ol>
 *
 * The first logic test concerns the prefix and postfix routines. For the
 * test problem rosenbrockmod.osil create an <b>OSExpressionTree</b>
 * from the objective function. Then invoke the <b>getPostfix()</b> method
 * and get a postfix vector representation of the expression tree. Then
 * use  <b>createExpressionTreeFromPostfix</b> to create an expression tree back.
 * Then use <b>getPrefix()</b> to get a prefix vector from this expression tree.
 * Then use createExpressionTreeFromPrefix to create and expression. Then
 * use <b>getPostfix()</b> to get the postfix vector back and compare with the very
 * first postfix vector and make sure they are the same. 
 * 
 * Next test all of the nonlinear operators. The file testOperators.osil uses
 * every nonlinear operator currently defined. Parse this file to make sure
 * the parser works on every operator and then use 
 * <b>expTree->m_treeRoot->calculateFunction</b> to make sure the operators are 
 * evaluated correctly.
 * 
 * Next test CppAD. Read in CppADTestLag.osil and make sure gradient
 * and Hessian calculations are working correctly.
 *
 * We next test the parsers. We test parsing the osil file
 * parincLinear.osil, finplan1.osil, the osrl file parincLinear.osrl
 * and the osol file osolTest.osol.
 * We test the get() and set() methods for osinstance.
 */ 

//#define DEBUG
//#define GUS_DEBUG

#include <cppad/cppad.hpp> 
//#include "CoinUtilsConfig.h"
#include "OSCoinSolver.h"
#include "OSConfig.h"
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



#ifdef COIN_HAS_GLPK
#include <OsiGlpkSolverInterface.hpp>
#endif

#ifdef COIN_HAS_COUENNE    
#include "OSCouenneSolver.h"
#endif

#ifdef COIN_HAS_ASL
#include "OSnl2osil.h"
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

using std::cout;   
using std::endl;
using std::ostringstream; 




int main(int argC, char* argV[])
{
//#ifdef HAVE_WINDOWS_H
//   SetErrorMode(SEM_FAILCRITICALERRORS | SEM_NOGPFAULTERRORBOX);
//#endif 
	WindowsErrorPopupBlocker();
	double getObjVal(std::string osrl);
	//using CppAD::NearEqual;
	bool ok;
	double check;
	
	
	bool BASIC_TESTS;  // minimal functionality tests
	bool SOLVER_TESTS; // at least one problem for each solver
	bool THOROUGH;     // multiple problems for some solvers
	bool PARSER_TESTS; // test parser logic
	bool OTHER_TESTS;  // other input formats, automatic differentiation, etc.
	
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
	
	//return 0;
	cout << "START UNIT TEST" << endl;
	int nOfTest = 0;
	// define the classes
	FileUtil *fileUtil = NULL;  
#ifdef COIN_HAS_ASL
	OSnl2osil *nl2osil = NULL;
#endif 
	OSmps2osil *mps2osil = NULL;
	DefaultSolver *solver  = NULL;
	OSiLReader *osilreader = NULL;
	OSoLReader *osolreader = NULL;
	OSrLReader *osrlreader = NULL;
	OSrLWriter *osrlwriter = NULL;
	OSrLWriter *tmp_writer = NULL;
	// end classes    
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
  	// Set directory containing mps data files.
  	std::string dataDir;
    dataDir = dirsep == '/' ? "../data/" : "..\\data\\";
#ifdef GUS_DEBUG
	dataDir = "C:\\datafiles\\research\\OS\\OS-trunk-work\\OS\\data\\";
#endif
	nlFileName =  dataDir  + "amplFiles" + dirsep + "parinc.nl";
	mpsFileName =  dataDir + "mpsFiles" + dirsep + "parinc.mps";
	fileUtil = new FileUtil();
	// 
//	unitTestResult << "HERE ARE THE UNIT TEST RESULTS:" << std::endl << std::endl;

if(BASIC_TESTS == true){

	//first make sure we can read files
	try{
		std::cout << endl << "TEST " << ++nOfTest << ": Try to read a sample file" << endl << endl;
		osilFileName =  dataDir  + "osilFiles" + dirsep +  "parincLinearByRow.osil";
		//osilFileName =  dataDir  + "osilFiles" + dirsep +  "parincLinear.osil";
		std::cout << "The file is: " ;
		std::cout <<  osilFileName << std::endl;
		osil = fileUtil->getFileAsString( osilFileName.c_str() );
		std::cout << "Done reading the test file" << std::endl;
		osilreader = new OSiLReader(); 
		//OSInstance *osinstance = osilreader->readOSiL( osil);
		//osinstance->initForAlgDiff();
		unitTestResult << "TEST " << nOfTest << ": Reading files successfully" << std::endl;
		cout << endl << "TEST " << nOfTest << ": Completed successfully" << endl << endl;
		OSiLWriter osilwriter;
		osilwriter.m_bWhiteSpace = true;
		//std::cout << osilwriter.writeOSiL( osinstance) << std::endl;
		delete osilreader;
		osilreader = NULL;
		//cout << "The unitTest passed the following" << endl << endl;
		//cout << unitTestResult.str() << endl << endl;
		/*
		// below is just a bunch of misc. stuff kipp is testing
		//
		// Create a problem pointer.  We use the base class here.
		OsiSolverInterface *si, *si2;
		// When we instantiate the object, we need a specific derived class.
		si = new OsiCbcSolverInterface;
		// Read in an mps file.  This one's from the MIPLIB library.
		si->readMps( mpsFileName.c_str());
		// get the problem
		// variable upper and lower bounds
		 const double *collb = si->getColLower();
		 const double *colub = si->getColUpper();		
		// constraint upper and lower bound	
		const  double *rowlb = si->getRowLower();
		const  double *rowub = si->getRowUpper();		
		//the Coin packed matrix
		const CoinPackedMatrix *m_CoinPackedMatrix =  si->getMatrixByCol();		
		//finally the objective function coefficieCnts		
		const double *objcoef = si->getObjCoefficients();
		//delete si;
		si2 = new OsiCbcSolverInterface;
		std::cout << objcoef[ 0] << std::endl;
		// now load the problem
		si2->loadProblem(*m_CoinPackedMatrix, collb, colub,  objcoef, rowlb, rowub);		
		// Solve the (relaxation of the) problem
		//si2->branchAndBound();	
		delete si;
		delete si2;
		*/
		
		
		cout << endl << "TEST " << ++nOfTest << ": Lossless I/O" << endl << endl;
		//mpsFileName =  dataDir + "mpsFiles" + dirsep + "testfile2.mps";
		mpsFileName =  dataDir + "mpsFiles" + dirsep + "parinc.mps";
		mps2osil = new OSmps2osil( mpsFileName);
		// create the first in-memory OSInstance
		mps2osil->createOSInstance() ;
		// write the instance to a string
		OSInstance *osinstance1 = mps2osil->osinstance;
		std::string sOSiL = osilwriter.writeOSiL( osinstance1  );
#ifdef DEBUG
		cout << sOSiL << endl;
#endif
		///fileUtil->writeFileFromString("p0201.osil", sOSiL);
		// now create a second object
		osilreader = new OSiLReader();
		OSInstance *osinstance2 = osilreader->readOSiL( sOSiL);
		// now compare the elements in the A matrix for the two intances
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
		{	std::cout << "MAXIMUM DIFF INDEX  = " << theIndex << std::endl;
			unitTestResult << "WARNING:  you do not have lossless IO" << std::endl;
		}
		else 
		{	unitTestResult << "TEST " << nOfTest << ": Passed lossless IO test" << std::endl;
			cout << endl << "TEST " << nOfTest << ": Completed successfully" << endl << endl;
		}
		delete mps2osil;
		delete osilreader;
		osilreader = NULL;


		//nl2osil = new OSnl2osil( nlFileName);
	    //return 0;	
		/*
		//using os_dtoa_format
		MathUtil *mathUtil = new MathUtil();
	    int decimalPoint; // where the decimal point goes
	    int sign; // 1 if negative, 0 if positive
	    double d ;
	    d = -2./3.;
	    //d = 123.4567;
	    d = 1.23456589e-2;
	    d = .00001123;
	    char *result = os_dtoa(d, 0, 0, &decimalPoint, &sign, NULL);
	    for(int kj = 5; kj < 9; kj++){
	    	d = pow(10. ,kj) + pow(10., (kj-1));
	    	//d = 57.7;
	    	result =os_dtoa(d, 0, 0, &decimalPoint, &sign, NULL);
	    	printf("HERE IS THE RESULT  %s\n\n", result);
	    	printf("HERE IS THE RESULT of sign  %d\n\n", sign);
	    	printf("HERE IS THE RESULT decimal point  %i\n\n", decimalPoint);
	    	printf("HERE IS THE LENGTH OF THE RESULT  %d\n\n",  strlen(result));
	    	std::cout << "HERE IS THE RESULT OF OS os_dtoa_format: " << os_dtoa_format( d) << std::endl;
	    }
	    d = .00001123;
	    d = -2./3.;
	    d = 100;
	    result = os_dtoa(DBL_MAX, 0, 0, &decimalPoint, &sign, NULL);
    	printf("HERE IS THE RESULT  %s\n\n", result);
    	printf("HERE IS THE RESULT of sign  %d\n\n", sign);
    	printf("HERE IS THE RESULT decimal point  %i\n\n", decimalPoint);
    	printf("HERE IS THE LENGTH OF THE RESULT  %d\n\n",  strlen(result));
    	std::cout << "HERE IS THE RESULT OF OS os_dtoa_format: " << os_dtoa_format( OSDBL_MAX) << std::endl;  	
    	d = .000234;
	    result = os_dtoa(d, 0, 0, &decimalPoint, &sign, NULL);
    	printf("HERE IS THE RESULT  %s\n\n", result);
    	printf("HERE IS THE RESULT of sign  %d\n\n", sign);
    	printf("HERE IS THE RESULT decimal point  %i\n\n", decimalPoint);
    	printf("HERE IS THE LENGTH OF THE RESULT  %d\n\n",  strlen(result));
    	std::cout << "HERE IS THE RESULT OF OS os_dtoa_format: " << os_dtoa_format( d) << std::endl;
    	//
    	char sInput[] = "77.77 99.99";
    	char *pEnd;
    	double d1, d2;
    	d1 = os_strtod (sInput,  &pEnd);
    	d2 = os_strtod (pEnd,NULL);
    	std::cout << d1 << std::endl;
    	std::cout << d2 << std::endl;
    	
    	std::cout << "HERE IS THE RESULT OF OS os_dtoa_format OSDBL_MAX: " << os_dtoa_format( OSDBL_MAX) << std::endl;
    	std::cout << "HERE IS THE RESULT OF OS os_dtoa_format OSDBL_MAX: " << OSDBL_MAX << std::endl;
    	std::cout << "HERE IS THE RESULT OF OS os_dtoa_format DBL_MAX: " << os_dtoa_format( DBL_MAX) << std::endl;
    	std::cout << "HERE IS THE RESULT OF OS os_dtoa_format DBL_MAX: " <<  DBL_MAX << std::endl;
    	d1 = os_strtod(os_dtoa_format( OSDBL_MAX).c_str(),     NULL);
    	if(d1 == DBL_MAX )std::cout <<  "SUCCESS" << endl;
    	else std::cout <<  "FAILURE" << endl;
    	*/
	}
	catch(const ErrorClass& eclass){
		unitTestResultFailure << "Sorry Unit Test Failed Reading a file: "  + eclass.errormsg<< endl; 
		//no point continuing we can't even read a file
		unitTestResultFailure << "Since we can't read files we are terminating"  << endl; 
		cout << unitTestResultFailure.str() << endl << endl;
		cout << "Conclusion: FAILURE" << endl;
		return 1;
	}	
} // end of if (BASIC_TESTS)

if (SOLVER_TESTS){
	try{
		cout << endl << "TEST " << ++nOfTest << ": Clp solver on parincLinearByRow.osil" << endl << endl;
		ok = true; 
		std::cout << "create a new COIN Clp for OSiL string solution" << std::endl;
		osilFileName = dataDir  + "osilFiles" + dirsep + "parincLinearByRow.osil";
		osolFileName = dataDir  + "osolFiles" + dirsep + "parincLinearByRow_clp.osol";
		osil = fileUtil->getFileAsString( osilFileName.c_str());
		osol = fileUtil->getFileAsString( osolFileName.c_str());

		std::cout << "create a new Solver object" << std::endl;
		osilreader = new OSiLReader(); 
		osolreader = new OSoLReader(); 
		solver = new CoinSolver();
		solver->sSolverName = "clp";
		solver->osinstance = osilreader->readOSiL( osil);
		std::cout << " Done reading the OSiL" << std::endl;
		// now write it again as a string
		OSiLWriter *osilwriter;
		osilwriter = new OSiLWriter();
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
		{	cout << "COIN clp solver solution for parincLinearByRow in error:" << endl;
			cout << solver->osrl << endl;
		}
		if(ok == false) throw ErrorClass(" Fail unit test with clp on parincLinearByRow.osil");
		// parse the osrl file
		osrlreader =  new OSrLReader();
#ifdef DEBUG
		cout << "\nThe osrl file:\n" << solver->osrl << endl;
		cout << "Start parsing the file" << endl;
#endif
		osrlreader->readOSrL( solver->osrl);
#ifdef DEBUG
		cout << "read successfully" << endl;
#endif
		delete osilreader;
#ifdef DEBUG
		cout << "osilreader successfully deleted" << endl;
#endif
		osilreader = NULL;	
		delete osolreader;
#ifdef DEBUG
		cout << "osolreader successfully deleted" << endl;
#endif
		osolreader = NULL;	
		delete solver;
#ifdef DEBUG
		cout << "solver successfully deleted" << endl;
#endif
		solver = NULL;
		delete osilwriter;
#ifdef DEBUG
		cout << "osilwriter successfully deleted" << endl;
#endif
		osilwriter = NULL;
		delete osrlreader;
#ifdef DEBUG
		cout << "osrlreader successfully deleted" << endl;
#endif		
		osrlreader = NULL;
		unitTestResult << "TEST " << nOfTest << ": Solved problem parincLinearByRow.osil with Clp" << std::endl;
		cout << endl << "TEST " << nOfTest << ": Completed successfully" << endl << endl;
	}
	catch(const ErrorClass& eclass){
		unitTestResultFailure << "Sorry Unit Test Failed Testing Clp Solver:"  + eclass.errormsg<< endl;
	}

	// now solve another problem -- try an integer program
	try{
		cout << endl << "TEST " << ++nOfTest << ": Cbc solver on p0033.osil" << endl << endl;
		std::cout << "create a new COIN Cbc for OSiL string solution" << std::endl;
		ok = true;
		osilFileName = dataDir  + "osilFiles" + dirsep + "p0033.osil";
		//osolFileName = dataDir  + "osolFiles" + dirsep + "p0033_cbc.osol";
		osil = fileUtil->getFileAsString( osilFileName.c_str());
		//osol = fileUtil->getFileAsString( osolFileName.c_str());
		osol = "";
		osilreader = new OSiLReader(); 
		osolreader = new OSoLReader(); 
		solver = new CoinSolver();
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
		{	cout << "Coin cbc solution for p0033 in error:" << endl;
			cout << solver->osrl << endl;
		}
		if (ok == false) throw ErrorClass(" Fail unit test with Cbc on p0033.osil");
		delete solver;
		solver = NULL;
		delete osilreader;
		osilreader = NULL;
		delete osolreader;
		osolreader = NULL;
		unitTestResult << "TEST " << nOfTest << ": Solved problem p0033.osil with Cbc" << std::endl;
		cout << endl << "TEST " << nOfTest << ": Completed successfully" << endl << endl;
	}
	catch(const ErrorClass& eclass){
		unitTestResultFailure << "Sorry Unit Test Failed Testing Cbc Solver:"  + eclass.errormsg<< endl;
	}

if( THOROUGH == true){
	// now test p0201.osil
	try{
		cout << endl << "TEST " << ++nOfTest << ": Cbc solver on p0033.osil - node limit set" << endl << endl;
		//std::cout << "create a new COIN Cbc for OSiL string solution" << std::endl;
		ok = true;
		osilFileName = dataDir  + "osilFiles" + dirsep + "p0033.osil";
		osolFileName = dataDir  + "osolFiles" + dirsep + "p0033_cbc.osol";
		osil = fileUtil->getFileAsString( osilFileName.c_str());
		osol = fileUtil->getFileAsString( osolFileName.c_str());
		osilreader = new OSiLReader(); 
		osolreader = new OSoLReader(); 
		solver = new CoinSolver();
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
		unitTestResult << "TEST " << nOfTest << ": Solved problem p0033.osil with Cbc node limit" << std::endl;
		cout << endl << "TEST " << nOfTest << ": Completed successfully" << endl << endl;
	}
	catch(const ErrorClass& eclass){
		unitTestResultFailure << "Sorry Unit Test Failed Testing Cbc Solver:"  + eclass.errormsg<< endl;
	}


	try{
		cout << endl << "TEST " << ++nOfTest << ": Cbc solver on p0201.osil" << endl << endl;
		ok = true;
		osilFileName = dataDir  + "osilFiles" + dirsep + "p0201.osil";
		osolFileName = dataDir  + "osolFiles" + dirsep + "p0201_cbc.osol";
		osil = fileUtil->getFileAsString( osilFileName.c_str());
		osol = fileUtil->getFileAsString( osolFileName.c_str());
		solver = new CoinSolver();
		solver->sSolverName ="cbc";
		solver->osil = osil;
		osilreader = new OSiLReader(); 
		osolreader = new OSoLReader(); 
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
		unitTestResult << "TEST " << nOfTest << ": Solved problem p0201.osil with Cbc" << std::endl;
		cout << endl << "TEST " << nOfTest << ": Completed successfully" << endl << endl;
	}
	catch(const ErrorClass& eclass){
		unitTestResultFailure << "Sorry Unit Test Failed Testing Cbc Solver:"  + eclass.errormsg<< endl;
	}

		cout << endl << "TEST " << ++nOfTest << ": Cbc solver on parincInteger.osil" << endl << endl;
		ok = true;
		osilFileName = dataDir  + "osilFiles" + dirsep + "parincInteger.osil";
		osolFileName = dataDir  + "osolFiles" + dirsep + "parincInteger_cbc.osol";
		osil = fileUtil->getFileAsString( osilFileName.c_str());
		osol = fileUtil->getFileAsString( osolFileName.c_str());
		osilreader = new OSiLReader(); 
		osolreader = new OSoLReader(); 

		solver = new CoinSolver();
		solver->sSolverName ="cbc";
		solver->osinstance = osilreader->readOSiL( osil);
		solver->osol = osol; 
		cout << "call the COIN - Cbc Solver for parincInteger" << endl;
//		solver->buildSolverInstance();
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
		{	cout << "COIN cbc solver solution for parincInteger in error:" << endl;
			cout << solver->osrl << endl;
		}
		if(ok == false) throw ErrorClass(" Fail unit test with Cbc on parincInteger.osil");
		delete osilreader;
		osilreader = NULL;	
		delete osolreader;
		osolreader = NULL;	
		delete solver;
		solver = NULL;
		unitTestResult << "TEST " << nOfTest << ": Solved problem parincInteger.osil with Cbc" << std::endl;
		cout << endl << "TEST " << nOfTest << ": Completed successfully" << endl << endl;
}	// end of if(THOROUGH)

#ifdef COIN_HAS_SYMPHONY
	try{
		cout << endl << "TEST " << ++nOfTest << ": SYMPHONY solver on p0033.osil" << endl << endl;
		ok = true; 
		osilFileName = dataDir  + "osilFiles" + dirsep + "p0033.osil";
		osolFileName = dataDir  + "osolFiles" + dirsep + "p0033_sym.osol";
		osil = fileUtil->getFileAsString( osilFileName.c_str());
		osol = fileUtil->getFileAsString( osolFileName.c_str());
		osolreader = new OSoLReader(); 
		solver = new CoinSolver();
		solver->sSolverName = "symphony";
		solver->osil = osil;
		solver->osinstance = NULL; 
		solver->osoption   = osolreader->readOSoL( osol);
		cout << "build the solver instance for COIN - SYMPHONY" << endl;
		solver->buildSolverInstance();
//		cout << "call the COIN - SYMPHONY Solver for p0033" << endl;
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
		{	cout << "COIN SYMPHONY solver solution for p0033 in error:" << endl;
			cout << solver->osrl << endl;
		}
		if(ok == false) throw ErrorClass(" Fail unit test with SYMPHONY on p0033.osil");
		delete solver;
		solver = NULL;
		delete osolreader;
		osolreader = NULL;	
		unitTestResult << "TEST " << nOfTest << ": Solved problem p0033.osil with SYMPHONY" << std::endl;
		cout << endl << "TEST " << nOfTest << ": Completed successfully" << endl << endl;
	}
	catch(const ErrorClass& eclass){
		unitTestResultFailure  << "Sorry Unit Test Failed Testing the SYMPHONY Solver:"  + eclass.errormsg << endl;
	}	
#endif
	


#ifdef COIN_HAS_DYLP
	try{
		cout << endl << "TEST " << ++nOfTest << ": DyLP solver on parincLinear.osil" << endl << endl;
		ok = true; 
		osilFileName = dataDir  + "osilFiles" + dirsep + "parincLinear.osil";
		osolFileName = dataDir  + "osolFiles" + dirsep + "parincLinear_dylp.osol";
		osil = fileUtil->getFileAsString( osilFileName.c_str());
		osol = fileUtil->getFileAsString( osolFileName.c_str());
		osilreader = new OSiLReader(); 
		solver = new CoinSolver();
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
		{	cout << "COIN DyLP solver solution for parincLinear in error:" << endl;
			cout << solver->osrl << endl;
		}
		if(ok == false) throw ErrorClass(" Fail unit test with DyLP on parincLinear.osil");
		delete solver;
		solver = NULL;
		delete osilreader;
		osilreader = NULL;	
		unitTestResult << "TEST " << nOfTest << ": Solved problem parincLinear.osil with DyLP" << std::endl;
		cout << endl << "TEST " << nOfTest << ": Completed successfully" << endl << endl;
	}
	catch(const ErrorClass& eclass){
		cout << "OSrL =  " <<  solver->osrl <<  endl;
		cout << endl << endl << endl;
		unitTestResultFailure  <<"Sorry Unit Test Failed Testing the DyLP Solver:"  + eclass.errormsg << endl;
	}	
#endif
	

#ifdef COIN_HAS_VOL
	try{
		cout << endl << "TEST " << ++nOfTest << ": Vol solver on volumeTest.osil" << endl << endl;
		ok = true; 
		osilFileName = dataDir  + "osilFiles" + dirsep + "volumeTest.osil";
		osolFileName = dataDir  + "osolFiles" + dirsep + "volumeTest_vol.osol";
		osil = fileUtil->getFileAsString( osilFileName.c_str());
		osol = fileUtil->getFileAsString( osolFileName.c_str());
		osolreader = new OSoLReader(); 
		solver = new CoinSolver();
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
			cout << "COIN Vol solver solution for parincLinear checks." << endl;
		}
		else
		{	cout << "COIN Vol solver solution for parincLinear in error:" << endl;
			cout << solver->osrl << endl;
		}
		if(ok == false) throw ErrorClass(" Fail unit test with Vol on volumeTest.osil");
		delete solver;
		solver = NULL;
		delete osolreader;
		osolreader = NULL;	
		unitTestResult << "TEST " << nOfTest << ": Solved problem volumeTest.osil with Vol" << std::endl;
		cout << endl << "TEST " << nOfTest << ": Completed successfully" << endl << endl;
	}
	catch(const ErrorClass& eclass){
		cout << "OSrL =  " <<  solver->osrl <<  endl;
		cout << endl << endl << endl;
		unitTestResultFailure  <<"Sorry Unit Test Failed Testing the Vol Solver:"  + eclass.errormsg << endl;
	}	
#endif
	
#ifdef COIN_HAS_GLPK
	try{
		cout << endl << "TEST " << ++nOfTest << ": GLPK solver on p0033.osil" << endl << endl;
		ok = true; 
		osilFileName = dataDir  + "osilFiles" + dirsep + "p0033.osil";
		osolFileName = dataDir  + "osolFiles" + dirsep + "p0033_glpk.osol";
		osil = fileUtil->getFileAsString( osilFileName.c_str());
		osol = fileUtil->getFileAsString( osolFileName.c_str());
		osilreader = new OSiLReader(); 
		osolreader = new OSoLReader(); 
		solver = new CoinSolver();
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
		{	cout << "GLPK solver solution for p0033 in error:" << endl;
			cout << solver->osrl << endl;
		}
		if(ok == false) throw ErrorClass(" Fail unit test with GLPK on p0033.osil");
		delete solver;
		solver = NULL;
		delete osilreader;
		osilreader = NULL;	
		delete osolreader;
		osolreader = NULL;	
		unitTestResult << "TEST " << nOfTest << ": Solved problem p0033.osil with GLPK" << std::endl;
		cout << endl << "TEST " << nOfTest << ": Completed successfully" << endl << endl;
	}
	catch(const ErrorClass& eclass){
		cout << "OSrL =  " <<  solver->osrl <<  endl;
		cout << endl << endl << endl;
		unitTestResultFailure  <<"Sorry Unit Test Failed Testing the Glpk Solver:"  + eclass.errormsg << endl;
	}	
#endif
	


#ifdef COIN_HAS_CPX
	try{
		cout << endl << "TEST " << ++nOfTest << ": Cplex solver on p0033.osil" << endl << endl;
		ok = true; 
		osilFileName = dataDir  + "osilFiles" + dirsep + "p0033.osil";
		osolFileName = dataDir  + "osolFiles" + dirsep + "p0033_cpx.osol";
		osil = fileUtil->getFileAsString( osilFileName.c_str());
		osol = fileUtil->getFileAsString( osolFileName.c_str());
		solver = new CoinSolver();
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
		{	cout << "CPLEX solver solution for p0033 in error:" << endl;
			cout << solver->osrl << endl;
		}
		if(ok == false) throw ErrorClass(" Fail unit test with CPLEX on p0033.osil");
		delete solver;
		solver = NULL;
		unitTestResult << "TEST " << nOfTest << ": Solved problem p0033.osil with CPLEX" << std::endl;
		cout << endl << "TEST " << nOfTest << ": Completed successfully" << endl << endl;
	}
	catch(const ErrorClass& eclass){
		cout << "OSrL =  " <<  solver->osrl <<  endl;
		cout << endl << endl << endl;
		unitTestResultFailure  <<"Sorry Unit Test Failed Testing the Cplex Solver:"  + eclass.errormsg << endl;
	}	
#endif
	


#ifdef COIN_HAS_IPOPT
	IpoptSolver *ipoptSolver  =  NULL;	
	try{
		cout << endl << "TEST " << ++nOfTest << ": Ipopt solver with avion2.osil" << endl << endl;
	    ipoptSolver  = new IpoptSolver();
		cout << "create a new IPOPT Solver for OSiL string solution" << endl;
		ok = true;
//		OSiLReader *osilreader = NULL;
//		OSoLReader *osolreader = NULL;
		// avion does not work with Mumps on AIX xlC compiler
#ifndef XLC_
		osilFileName =  dataDir  + "osilFiles" + dirsep +  "avion2.osil";
		osolFileName = dataDir  + "osolFiles" + dirsep + "avion2_ipopt.osol";
		osil = fileUtil->getFileAsString( osilFileName.c_str());
		osol = fileUtil->getFileAsString( osolFileName.c_str());
		cout << "IPOPT Solver created for OSiL string solution" << endl;
		ipoptSolver->osol = osol;
		osilreader = new OSiLReader(); 
		osolreader = new OSoLReader(); 
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
		{	cout << "IPOPT solver solution for avion2 in error:" << endl;
			cout << ipoptSolver->osrl << endl;
		}
		if(ok == false) throw ErrorClass(" Fail unit test with Ipopt on avion2.osil");
		delete osilreader;
		osilreader = NULL;
		delete osolreader;
		osolreader = NULL;
		delete ipoptSolver;
		ipoptSolver = NULL;
		unitTestResult << "TEST " << nOfTest << ": Solved problem avion2.osil with Ipopt" << std::endl;
		cout << endl << "TEST " << nOfTest << ": Completed successfully" << endl << endl;
#endif

if(THOROUGH == true){
		// solve another problem
		cout << endl << "TEST " << ++nOfTest << ": Ipopt solver with HS071_NLPMod.osil" << endl << endl;
		cout << "create a new IPOPT Solver for OSiL string solution" << endl;
		ipoptSolver  = new IpoptSolver();
		// a problem with all nonlinear terms no linear terms
		osilFileName = dataDir  + "osilFiles" + dirsep + "HS071_NLPMod.osil";
		osolFileName = dataDir  + "osolFiles" + dirsep + "HS071_NLPMod_ipopt.osol";
		osil = fileUtil->getFileAsString( osilFileName.c_str());
		osol = fileUtil->getFileAsString( osolFileName.c_str());
		cout << "IPOPT Solver created for OSiL string solution" << endl;
//		osol = "<osol></osol>";
		osilreader = new OSiLReader(); 
		osolreader = new OSoLReader(); 
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
		{	cout << "IPOPT solver solution for HS071_NLP in error:" << endl;
			cout << ipoptSolver->osrl << endl;
		}
		delete osilreader;
		osilreader = NULL;
		delete osolreader;
		osolreader = NULL;
		delete ipoptSolver;
		ipoptSolver = NULL;
		if(ok == false) throw ErrorClass(" Fail unit test with Ipopt on HS071_NLP.osil");
		unitTestResult << "TEST " << nOfTest << ": Solved problem HS071.osil with Ipopt" << std::endl;
		cout << endl << "TEST " << nOfTest << ": Completed successfully" << endl << endl;

		cout << endl << "TEST " << ++nOfTest << ": Ipopt solver on rosenbrockmod.osil" << endl << endl;
		cout << "create a new IPOPT Solver for OSiL string solution" << endl;
		ipoptSolver  = new IpoptSolver();
		// solve another problem
		// a problem with both quadratic terms and general nonlinear terms
		osilFileName = dataDir  + "osilFiles" + dirsep + "rosenbrockmod.osil";
		osolFileName = dataDir  + "osolFiles" + dirsep + "rosenbrockmod_ipopt.osol";
		osil = fileUtil->getFileAsString( osilFileName.c_str());
		osol = fileUtil->getFileAsString( osolFileName.c_str());
		cout << "IPOPT Solver created for OSiL string solution" << endl;
		osilreader = new OSiLReader(); 
		osolreader = new OSoLReader(); 
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
		{	cout << "Ipopt solver solution for rosenbrockmod in error:" << endl;
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
		unitTestResult << "TEST " << nOfTest << ": Solved problem rosenbrockmod.osil with Ipopt" << std::endl;
		cout << endl << "TEST " << nOfTest << ": Completed successfully" << endl << endl;
		//return 0;

		cout << endl << "TEST " << ++nOfTest << ": Ipopt solver on parincQuadratic.osil" << endl << endl;
		cout << "create a new IPOPT Solver for OSiL string solution" << endl;
		ipoptSolver  = new IpoptSolver();
		// solve another problem
		// a problem that is a pure quadratic
		osilFileName = dataDir  + "osilFiles" + dirsep + "parincQuadratic.osil";
		osolFileName = dataDir  + "osolFiles" + dirsep + "parincQuadratic_ipopt.osol";
		osil = fileUtil->getFileAsString( osilFileName.c_str());
		osol = fileUtil->getFileAsString( osolFileName.c_str());
		cout << "IPOPT Solver created for OSiL string solution" << endl;
		osilreader = new OSiLReader(); 
		osolreader = new OSoLReader(); 
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
		{	cout << "IPOPT solver solution for parincQuadratic in error:" << endl;
			cout << ipoptSolver->osrl << endl;
		}
		if(ok == false) throw ErrorClass(" Fail unit test with Ipopt on parincQuadradic.osil");
		delete osilreader;
		osilreader = NULL;	
		delete osolreader;
		osolreader = NULL;	
		delete ipoptSolver;
		ipoptSolver = NULL;
		unitTestResult << "TEST " << nOfTest << ": Solved problem parincQuadratic.osil with Ipopt" << std::endl;
		cout << endl << "TEST " << nOfTest << ": Completed successfully" << endl << endl;

		cout << endl << "TEST " << ++nOfTest << ": Ipopt solver on parincLinear.osil" << endl << endl;
		cout << "create a new IPOPT Solver for OSiL string solution" << endl;
		ipoptSolver  = new IpoptSolver();
		// solve another problem
		// try a pure linear program
		osilFileName = dataDir  + "osilFiles" + dirsep + "parincLinear.osil";
		osolFileName = dataDir  + "osolFiles" + dirsep + "parincLinear_ipopt.osol";
		osil = fileUtil->getFileAsString( osilFileName.c_str());
		osol = fileUtil->getFileAsString( osolFileName.c_str());
		cout << "IPOPT Solver created for OSiL string solution" << endl;
		osilreader = new OSiLReader(); 
		osolreader = new OSoLReader(); 
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
		{	cout << "IPOPT solver solution for parincLinear in error:" << endl;
			cout << ipoptSolver->osrl << endl;
		}
		if(ok == false) throw ErrorClass(" Fail unit test with Ipopt on parincLinear.osil");
		delete osilreader;
		osilreader = NULL;	
		delete osolreader;
		osolreader = NULL;	
		delete ipoptSolver;
		ipoptSolver = NULL;
		unitTestResult << "TEST " << nOfTest << ": Solved problem parincLinear.osil with Ipopt" << std::endl;
		cout << endl << "TEST " << nOfTest << ": Completed successfully" << endl << endl;

		cout << endl << "TEST " << ++nOfTest << ": Ipopt solver on callBackTest.osil" << endl << endl;
		cout << "create a new IPOPT Solver for OSiL string solution" << endl;
		ipoptSolver  = new IpoptSolver();
		// solve another problem
		// callBackTest.osil
		osilFileName = dataDir  + "osilFiles" + dirsep + "callBackTest.osil";
		osolFileName = dataDir  + "osolFiles" + dirsep + "callBackTest_ipopt.osol";
		osil = fileUtil->getFileAsString( osilFileName.c_str());
		osol = fileUtil->getFileAsString( osolFileName.c_str());
		cout << "IPOPT Solver created for OSiL string solution" << endl;
		osilreader = new OSiLReader(); 
		osolreader = new OSoLReader(); 
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
		{	cout << "IPOPT solver solution for callBackTest in error:" << endl;
			cout << ipoptSolver->osrl << endl;
		}
		if(ok == false) throw ErrorClass(" Fail unit test with Ipopt on callBackTest.osil");
		delete osilreader;
		osilreader = NULL;	
		delete osolreader;
		osolreader = NULL;	
		delete ipoptSolver;
		ipoptSolver = NULL;
		unitTestResult << "TEST " << nOfTest << ": Solved problem callBackTest.osil with Ipopt" << std::endl;	
		cout << endl << "TEST " << nOfTest << ": Completed successfully" << endl << endl;

		cout << endl << "TEST " << ++nOfTest << ": Ipopt solver on callBackTestRowMajor.osil" << endl << endl;
		cout << "create a new IPOPT Solver for OSiL string solution" << endl;
		ipoptSolver  = new IpoptSolver();
		// solve another problem
		// callBackTest.osil
		osilFileName =  dataDir  + "osilFiles" + dirsep + "callBackTestRowMajor.osil";
		osolFileName = dataDir  + "osolFiles" + dirsep + "callBackTestRowMajor_ipopt.osol";
		osil = fileUtil->getFileAsString( osilFileName.c_str());
		osol = fileUtil->getFileAsString( osolFileName.c_str());
		cout << "IPOPT Solver created for OSiL string solution" << endl;
		osilreader = new OSiLReader(); 
		osolreader = new OSoLReader(); 
		ipoptSolver->osinstance = NULL;
		ipoptSolver->osoption   = NULL;
		ipoptSolver->osil = osil;
		ipoptSolver->osol = osol;
		cout << "call the IPOPT Solver" << endl;
//		ipoptSolver->buildSolverInstance();
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
		{	cout << "IPOPT solver solution for callBackTestRowMajor in error:" << endl;
			cout << ipoptSolver->osrl << endl;
		}
		if(ok == false) throw ErrorClass(" Fail unit test with Ipopt on callBackTestRowMajor.osil");
		delete osilreader;
		osilreader = NULL;	
		delete osolreader;
		osolreader = NULL;	
		delete ipoptSolver;
		ipoptSolver = NULL;	
		unitTestResult << "TEST " << nOfTest << ": Solved problem callBackRowMajor.osil with Ipopt" << std::endl;
		cout << endl << "TEST " << nOfTest << ": Completed successfully" << endl << endl;

		//this is integer, skip it
		/*
		cout << endl << "TEST " << ++nOfTest << ": Ipopt solver on nonconvex.osil" << endl << endl;
//		OSiLReader *osilreader = NULL;
		osilreader = new OSiLReader(); 
		osolreader = new OSoLReader(); 
		ok = true; 
		osilFileName = dataDir  + "osilFiles" + dirsep + "nonconvex.osil";
//		osolFileName = dataDir  + "osolFiles" + dirsep + "bonminEx1_Couenne.osol";
		osil = fileUtil->getFileAsString( osilFileName.c_str());
//		osol = fileUtil->getFileAsString( osolFileName.c_str());
		osol = "";
		solver = new IpoptSolver();
		solver->sSolverName = "ipopt";
		solver->osil = osil;
		solver->osol = osol; 
//		solver->osinstance = osilreader->readOSiL( osil);
//		solver->osoption   = osolreader->readOSoL( osol);
		cout << "call the COIN - Ipopt Solver for nonconvex.osil" << endl;
		solver->buildSolverInstance();
	
		std::cout << " CALL SOLVE " << std::endl;
		solver->solve();
	
		cout << "Here is the Ipopt solver solution for nonconvex.osil" << endl;

//		OSrLWriter *tmp_writer;
		tmp_writer = new OSrLWriter();
		solver->osrl = tmp_writer->writeOSrL(solver->osresult);
		delete tmp_writer;
		tmp_writer = NULL;

		cout << solver->osrl << endl << endl;

//		check = -1.70711;
//		//ok &= NearEqual(getObjVal( solver->osrl) , check,  1e-10 , 1e-10);
//		ok = ( fabs(check - getObjVal( solver->osrl) )/(fabs( check) + OS_NEAR_EQUAL) <= OS_NEAR_EQUAL) ? true : false;
//		if(ok == false) throw ErrorClass(" Fail unit test with Ipopt on nonconvex.osil");
	
		delete solver;
		solver = NULL;
		delete osilreader;
		osilreader = NULL;
		delete osolreader;
		osolreader = NULL;
		unitTestResult << "TEST " << nOfTest << ": Solved problem nonconvex.osil with Ipopt" << std::endl;
		cout << endl << "TEST " << nOfTest << ": Completed successfully" << endl << endl;
		*/
		cout << endl << "TEST " << ++nOfTest << ": Ipopt solver on rosenbrockorig.osil" << endl << endl;
//		OSiLReader *osilreader = NULL;
		osilreader = new OSiLReader(); 
		osolreader = new OSoLReader(); 
		ok = true; 
		osilFileName = dataDir  + "osilFiles" + dirsep + "rosenbrockorig.osil";
//		osolFileName = dataDir  + "osolFiles" + dirsep + "rosenbrockorig_Ipopt.osol";
		osil = fileUtil->getFileAsString( osilFileName.c_str());
//		osol = fileUtil->getFileAsString( osolFileName.c_str());
		osol = "";
		solver = new IpoptSolver();
		solver->sSolverName = "ipopt";
		solver->osil = osil;
		solver->osol = osol; 
//		solver->osinstance = osilreader->readOSiL( osil);
//		solver->osoption   = osolreader->readOSoL( osol);
		cout << "call the COIN - Ipopt Solver for rosenbrockorig" << endl;
		solver->buildSolverInstance();
	
		std::cout << " CALL SOLVE " << std::endl;
		solver->solve();
		check = 0;
		ok = ( fabs(check - getObjVal( solver->osrl) )/(fabs( check) + OS_NEAR_EQUAL) <= OS_NEAR_EQUAL) ? true : false;
		if (ok)
		{	
#ifdef DEBUG
			cout << solver->osrl << endl;
#endif
			cout << "Ipopt solver solution for rosenbrockorig checks." << endl;
		}
		else
		{	cout << "Ipopt solver solution for rosenbrockorig in error:" << endl;
			cout << solver->osrl << endl;
		}
		if(ok == false) throw ErrorClass(" Fail unit test with Ipopt on rosenbrockorig.osil");

		delete solver;
		solver = NULL;
	
	
		delete osilreader;
		osilreader = NULL;
		delete osolreader;
		osolreader = NULL;
		unitTestResult << "TEST " << nOfTest << ": Solved problem rosenbrockorig.osil with Ipopt" << std::endl;
		cout << endl << "TEST " << nOfTest << ": Completed successfully" << endl << endl;

		cout << endl << "TEST " << ++nOfTest << ": Ipopt solver on HS071_feas.osil" << endl << endl;
		try {
			osilreader = new OSiLReader(); 
			osolreader = new OSoLReader(); 
			ok = true; 
			osilFileName = dataDir  + "osilFiles" + dirsep + "HS071_feas.osil";
//			osolFileName = dataDir  + "osolFiles" + dirsep + "HS071_feas_Ipopt.osol";
			osil = fileUtil->getFileAsString( osilFileName.c_str());
//			osol = fileUtil->getFileAsString( osolFileName.c_str());
			osol = "";
			solver = new IpoptSolver();
			solver->sSolverName = "ipopt";
			solver->osil = osil;
			solver->osol = osol; 
//			solver->osinstance = osilreader->readOSiL( osil);
//			solver->osoption   = osolreader->readOSoL( osol);
			solver->buildSolverInstance();
	
			cout << "call the COIN - Ipopt Solver for HS071_feas.osil" << endl;
			solver->solve();
		}
		catch(const ErrorClass& eclass)
		{
			ok = (solver->osresult->getGeneralMessage() == "Ipopt NEEDS AN OBJECTIVE FUNCTION");
			if(ok == false) 
			{	cout << "Ipopt solver returns:" << endl;
				cout << solver->osrl << endl;
				throw ErrorClass(" Fail unit test with Ipopt on HS071_feas.osil");
			}
		}
	
		cout << "Received error message from Ipopt: \"Ipopt NEEDS AN OBJECTIVE FUNCTION\"" << endl;
	
		delete solver;
		solver = NULL;
		delete osilreader;
		osilreader = NULL;
		delete osolreader;
		osolreader = NULL;

		unitTestResult << "TEST " << nOfTest << ": Correctly diagnosed problem HS071_feas with Ipopt" << std::endl;
		cout << endl << "TEST " << nOfTest << ": Completed successfully" << endl << endl;

} // end of if( THOROUGH)
	}
	catch(const ErrorClass& eclass){
		unitTestResultFailure << "Sorry Unit Test Failed Testing the Ipopt Solver:"  + eclass.errormsg<< endl; 
	}
#endif // end of #ifdef COIN_HAS_IPOPT


#ifdef COIN_HAS_BONMIN
	try{
		cout << endl << "TEST " << ++nOfTest << ": Bonmin solver on bonminEx1.osil" << endl << endl;
//		OSiLReader *osilreader = NULL;
		osilreader = new OSiLReader(); 
		osolreader = new OSoLReader(); 
		ok = true; 
		osilFileName = dataDir  + "osilFiles" + dirsep + "bonminEx1.osil";
		osolFileName = dataDir  + "osolFiles" + dirsep + "bonminEx1_Bonmin.osol";
		osil = fileUtil->getFileAsString( osilFileName.c_str());
		osol = fileUtil->getFileAsString( osolFileName.c_str());
		solver = new BonminSolver();
		//solver->sSolverName = "bonmin";
//		solver->osinstance = osilreader->readOSiL( osil);
		solver->osil = osil;
		solver->osoption = osolreader->readOSoL( osol);
		cout << "call the COIN - Bonmin Solver for bonminEx1" << endl;
//		solver->buildSolverInstance();
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
		{	cout << "Bonmin solver solution for bonminEx1 in error:" << endl;
			cout << solver->osrl << endl;
		}
		if(ok == false) throw ErrorClass(" Fail unit test with Bonmin on bonminEx1.osil");
		delete solver;
		solver = NULL;
		delete osilreader;
		osilreader = NULL;
		delete osolreader;
		osolreader = NULL;
		unitTestResult << "TEST " << nOfTest << ": Solved problem bonminEx1.osil with Bonmin" << std::endl;
		cout << endl << "TEST " << nOfTest << ": Completed successfully" << endl << endl;

if (THOROUGH == true){
		cout << endl << "TEST " << ++nOfTest << ": Bonmin solver on wayneQuadratic.osil" << endl << endl;
		ok = true;
		osilFileName = dataDir  + "osilFiles" + dirsep + "wayneQuadratic.osil";
		osolFileName = dataDir  + "osolFiles" + dirsep + "wayneQuadratic_Bonmin1.osol";
		osil = fileUtil->getFileAsString( osilFileName.c_str());
		osol = fileUtil->getFileAsString( osolFileName.c_str());
		osilreader = new OSiLReader(); 
		solver = new BonminSolver();	
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
		{	cout << "Bonmin solver solution for wayneQuadratic in error:" << endl;
			cout << solver->osrl << endl;
		}
		if(ok == false) throw ErrorClass(" Fail unit test with Bonmin on wayneQuadratic.osil");
		delete solver;
		solver = NULL;
		delete osilreader;
		osilreader = NULL;
		unitTestResult << "TEST " << nOfTest << ": Solved problem wayneQuadratic.osil with Bonmin" << std::endl;
		cout << endl << "TEST " << nOfTest << ": Completed successfully" << endl << endl;

		cout << endl << "TEST " << ++nOfTest << ": Bonmin solver on wayneQuadratic.osil" << endl << endl;
		ok = true;
		osilFileName = dataDir  + "osilFiles" + dirsep + "wayneQuadratic.osil";
		osolFileName = dataDir  + "osolFiles" + dirsep + "wayneQuadratic_Bonmin2.osol";
		osil = fileUtil->getFileAsString( osilFileName.c_str());
		osol = fileUtil->getFileAsString( osolFileName.c_str());
		osilreader = new OSiLReader(); 
		osolreader = new OSoLReader(); 
		solver = new BonminSolver();	
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
		{	cout << "Bonmin solver solution for wayneQuadratic in error:" << endl;
			cout << solver->osrl << endl;
		}
		if(ok == false) throw ErrorClass(" Fail unit test with Bonmin on wayneQuadratic.osil");
		delete solver;
		solver = NULL;
		delete osilreader;
		osilreader = NULL;	
		delete osolreader;
		osolreader = NULL;	
		unitTestResult << "TEST " << nOfTest << ": Solved problem wayneQuadratic.osil with Bonmin" << std::endl;
		cout << endl << "TEST " << nOfTest << ": Completed successfully" << endl << endl;

//#if 1   // this does not work with the current version of Bonmin due to uninitialed variables
		cout << endl << "TEST " << ++nOfTest << ": Bonmin solver on rosenbrockorig.osil" << endl << endl;
		ok = true;
		osilFileName = dataDir  + "osilFiles" + dirsep + "rosenbrockorig.osil";
//		osolFileName = dataDir  + "osolFiles" + dirsep + "wayneQuadratic_Bonmin2.osol";
		osil = fileUtil->getFileAsString( osilFileName.c_str());
//		osol = fileUtil->getFileAsString( osolFileName.c_str());
		osilreader = new OSiLReader(); 
//		osolreader = new OSoLReader(); 
		solver = new BonminSolver();	
		solver->osol = "";
		solver->osinstance = osilreader->readOSiL( osil);
//		solver->osoption   = osolreader->readOSoL( osol);
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
		{	cout << "Bonmin solver solution for rosenbrockorig in error:" << endl;
			cout << solver->osrl << endl;
		}
		if(ok == false) throw ErrorClass(" Fail unit test with Bonmin on rosenbrockorig.osil");
		delete solver;
		solver = NULL;
		delete osilreader;
		osilreader = NULL;	
		delete osolreader;
		osolreader = NULL;	
		unitTestResult << "TEST " << nOfTest << ": Solved problem rosenbrockorig.osil with Bonmin" << std::endl;
		cout << endl << "TEST " << nOfTest << ": Completed successfully" << endl << endl;

		cout << endl << "TEST " << ++nOfTest << ": Bonmin solver on rosenbrockorigInt.osil" << endl << endl;
		ok = true;
		osilFileName = dataDir  + "osilFiles" + dirsep + "rosenbrockorigInt.osil";
//		osolFileName = dataDir  + "osolFiles" + dirsep + "wayneQuadratic_Bonmin2.osol";
		osil = fileUtil->getFileAsString( osilFileName.c_str());
//		osol = fileUtil->getFileAsString( osolFileName.c_str());
		osilreader = new OSiLReader(); 
//		osolreader = new OSoLReader(); 
		solver = new BonminSolver();	
		solver->osol = "";
		solver->osinstance = osilreader->readOSiL( osil);
//		solver->osoption   = osolreader->readOSoL( osol);
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
		{	cout << "Bonmin solver solution for rosenbrockorigInt in error:" << endl;
			cout << solver->osrl << endl;
		}
		if(ok == false) throw ErrorClass(" Fail unit test with Bonmin on rosenbrockorigInt.osil");
		delete solver;
		solver = NULL;
		delete osilreader;
		osilreader = NULL;	
		delete osolreader;
		osolreader = NULL;	
		unitTestResult << "TEST " << nOfTest << ": Solved problem rosenbrockorigInt.osil with Bonmin" << std::endl;
		cout << endl << "TEST " << nOfTest << ": Completed successfully" << endl << endl;
//#endif // ---- end of #if 1

}   // end of if( THOROUGH )
	}
	catch(const ErrorClass& eclass){
		unitTestResultFailure  << "Sorry Unit Test Failed Testing the Bonmin Solver:"  + eclass.errormsg << endl;
	}	
#endif   // end of #ifdef COIN_HAS_BONMIN



#ifdef COIN_HAS_COUENNE
	try{
		cout << endl << "TEST " << ++nOfTest << ": Couenne solver on bonminEx1.osil" << endl << endl;
		CouenneSolver *solver = NULL;

//		OSiLReader *osilreader = NULL;
		osilreader = new OSiLReader(); 
		osolreader = new OSoLReader(); 
		ok = true; 
		osilFileName = dataDir  + "osilFiles" + dirsep + "bonminEx1.osil";
		osolFileName = dataDir  + "osolFiles" + dirsep + "bonminEx1_Couenne.osol";
		osil = fileUtil->getFileAsString( osilFileName.c_str());
		osol = fileUtil->getFileAsString( osolFileName.c_str());
		solver = new CouenneSolver();
		solver->sSolverName = "bonmin";
		solver->osil = osil;
		solver->osol = osol; 
//		solver->osinstance = osilreader->readOSiL( osil);
//		solver->osoption   = osolreader->readOSoL( osol);
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
		{	cout << "Couenne solver solution for bonminEx1 in error:" << endl;
			cout << solver->osrl << endl;
		}
		if(ok == false) throw ErrorClass(" Fail unit test with Couenne on bonminEx1.osil");

		delete solver;
		solver = NULL;
	
	
		delete osilreader;
		osilreader = NULL;
		delete osolreader;
		osolreader = NULL;
		unitTestResult << "TEST " << nOfTest << ": Solved problem bonminEx1.osil with Couenne" << std::endl;
		cout << endl << "TEST " << nOfTest << ": Completed successfully" << endl << endl;

if( THOROUGH == true){
		cout << endl << "TEST " << ++nOfTest << ": Couenne solver on bonminEx1_Nonlinear.osil" << endl << endl;
//		OSiLReader *osilreader = NULL;
		osilreader = new OSiLReader(); 
		osolreader = new OSoLReader(); 
		ok = true; 
		osilFileName = dataDir  + "osilFiles" + dirsep + "bonminEx1_Nonlinear.osil";
//		osolFileName = dataDir  + "osolFiles" + dirsep + "bonminEx1_Couenne.osol";
		osil = fileUtil->getFileAsString( osilFileName.c_str());
//		osol = fileUtil->getFileAsString( osolFileName.c_str());
		osol = "";
		solver = new CouenneSolver();
		solver->osil = osil;
		solver->osol = osol; 
//		solver->osinstance = osilreader->readOSiL( osil);
//		solver->osoption   = osolreader->readOSoL( osol);
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
		{	cout << "Couenne solver solution for bonminEx1_Nonlinear in error:" << endl;
			cout << solver->osrl << endl;
		}
		if(ok == false) throw ErrorClass(" Fail unit test with Couenne on bonminEx1_Nonlinear.osil");

		delete solver;
		solver = NULL;
	
	
		delete osilreader;
		osilreader = NULL;
		delete osolreader;
		osolreader = NULL;
		unitTestResult << "TEST " << nOfTest << ": Solved problem bonminEx1_Nonlinear with Couenne" << std::endl;
		cout << endl << "TEST " << nOfTest << ": Completed successfully" << endl << endl;


		cout << endl << "TEST " << ++nOfTest << ": Couenne solver on nonconvex.osil" << endl << endl;
//		OSiLReader *osilreader = NULL;
		osilreader = new OSiLReader(); 
		osolreader = new OSoLReader(); 
		ok = true; 
		osilFileName = dataDir  + "osilFiles" + dirsep + "nonconvex.osil";
//		osolFileName = dataDir  + "osolFiles" + dirsep + "bonminEx1_Couenne.osol";
		osil = fileUtil->getFileAsString( osilFileName.c_str());
//		osol = fileUtil->getFileAsString( osolFileName.c_str());
		osol = "";
		solver = new CouenneSolver();
		solver->osil = osil;
		solver->osol = osol; 
//		solver->osinstance = osilreader->readOSiL( osil);
//		solver->osoption   = osolreader->readOSoL( osol);
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
		{	cout << "Couenne solver solution for nonconvex.osil in error:" << endl;
			cout << solver->osrl << endl;
		}
		if(ok == false) throw ErrorClass(" Fail unit test with Couenne on nonconvex.osil");

		delete solver;
		solver = NULL;
	
	
		delete osilreader;
		osilreader = NULL;
		delete osolreader;
		osolreader = NULL;
		unitTestResult << "TEST " << nOfTest << ": Solved problem nonconvex.osil with Couenne" << std::endl;
		cout << endl << "TEST " << nOfTest << ": Completed successfully" << endl << endl;

		cout << endl << "TEST " << ++nOfTest << ": Couenne solver on rosenbrockorig.osil" << endl << endl;
//		OSiLReader *osilreader = NULL;
		osilreader = new OSiLReader(); 
		osolreader = new OSoLReader(); 
		ok = true; 
		osilFileName = dataDir  + "osilFiles" + dirsep + "rosenbrockorig.osil";
//		osolFileName = dataDir  + "osolFiles" + dirsep + "rosenbrockorig_Couenne.osol";
		osil = fileUtil->getFileAsString( osilFileName.c_str());
//		osol = fileUtil->getFileAsString( osolFileName.c_str());
		osol = "";
		solver = new CouenneSolver();
		solver->osil = osil;
		solver->osol = osol; 
//		solver->osinstance = osilreader->readOSiL( osil);
//		solver->osoption   = osolreader->readOSoL( osol);
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
		{	cout << "Couenne solver solution for rosenbrockorig in error:" << endl;
			cout << solver->osrl << endl;
		}
		if(ok == false) throw ErrorClass(" Fail unit test with Couenne on rosenbrockorig.osil");

		delete solver;
		solver = NULL;
	
	
		delete osilreader;
		osilreader = NULL;
		delete osolreader;
		osolreader = NULL;
		unitTestResult << "TEST " << nOfTest << ": Solved problem rosenbrockorig.osil with Couenne" << std::endl;
		cout << endl << "TEST " << nOfTest << ": Completed successfully" << endl << endl;



		cout << endl << "TEST " << ++nOfTest << ": Couenne solver on wayneQuadratic.osil" << endl << endl;
//		OSiLReader *osilreader = NULL;
		osilreader = new OSiLReader(); 
		osolreader = new OSoLReader(); 
		ok = true; 
		osilFileName = dataDir  + "osilFiles" + dirsep + "wayneQuadratic.osil";
		
//		osolFileName = dataDir  + "osolFiles" + dirsep + "rosenbrockinteger_Couenne.osol";
		osil = fileUtil->getFileAsString( osilFileName.c_str());
//		osol = fileUtil->getFileAsString( osolFileName.c_str());
		osol = "";
		solver = new CouenneSolver();
		solver->osinstance = NULL;
		solver->osil = osil;
		solver->osol = osol; 
//		solver->osinstance = osilreader->readOSiL( osil);
//		solver->osoption   = osolreader->readOSoL( osol);
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
		{	cout << "Couenne solver solution for wayneQuadratic in error:" << endl;
			cout << solver->osrl << endl;
		}
		if(ok == false) throw ErrorClass(" Fail unit test with Couenne on rosenbrockinteger.osil");

		delete solver;
		solver = NULL;
	
	
		delete osilreader;
		osilreader = NULL;
		delete osolreader;
		osolreader = NULL;
		unitTestResult << "TEST " << nOfTest << ": Solved problem wayneQuadratic.osil with Couenne" << std::endl;
		cout << endl << "TEST " << nOfTest << ": Completed successfully" << endl << endl;
		

		
		cout << endl << "TEST " << ++nOfTest << ": Couenne solver on wayneQuadratic.osil" << endl << endl;
//		OSiLReader *osilreader = NULL;
		osilreader = new OSiLReader(); 
		osolreader = new OSoLReader(); 
		ok = true; 
		osilFileName = dataDir  + "osilFiles" + dirsep + "wayneQuadratic.osil";
		osolFileName = dataDir  + "osolFiles" + dirsep + "wayneQuadratic_Couenne.osol";
		osil = fileUtil->getFileAsString( osilFileName.c_str());
		osol = fileUtil->getFileAsString( osolFileName.c_str());
		solver = new CouenneSolver();
		solver->osil = osil;
		solver->osol = osol; 
		cout << "call the COIN - Couenne Solver for wayneQuadratic.osil" << endl;
		solver->buildSolverInstance();
	
		std::cout << " CALL SOLVE " << std::endl;
		solver->solve();
	
		cout << "Here is the Couenne solver solution for wayneQuadratic" << endl;

//		OSrLWriter *tmp_writer;
		tmp_writer = new OSrLWriter();
		solver->osrl = tmp_writer->writeOSrL(solver->osresult);
		delete tmp_writer;
		tmp_writer = NULL;
		
		string::size_type pos;
		pos = solver->osrl.find( "LIMIT_EXCEEDED[COUENNE]");
		if(pos == std::string::npos)  
		{	cout << solver->osrl << endl << endl;
			throw ErrorClass(" Error with wayneQuadratic running on Couenne");
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
		unitTestResult << "TEST " << nOfTest << ": Solved problem wayneQuadratic with Couenne" << std::endl;
		cout << endl << "TEST " << nOfTest << ": Completed successfully" << endl << endl;
		

} //end of if (THOROUGH)

	}
	catch(const ErrorClass& eclass){
		cout << "OSrL =  " <<  solver->osrl <<  endl;
		cout << endl << endl << endl;
		unitTestResultFailure  << "Sorry Unit Test Failed Testing the Couenne Solver:"  + eclass.errormsg << endl;
	
	}	
#endif // end of #ifdef COIN_HAS_COUENNE


	
#ifdef COIN_HAS_LINDO
	try{
		cout << endl << "TEST " << ++nOfTest << ": Lindo solver on lindoapiaddins.osil" << endl << endl;
		ok = true;
		osilFileName = dataDir  + "osilFiles" + dirsep + "lindoapiaddins.osil";
		osolFileName = dataDir  + "osolFiles" + dirsep + "lindoapiaddins_lindo.osol";
		osil = fileUtil->getFileAsString( osilFileName.c_str());
		osol = fileUtil->getFileAsString( osolFileName.c_str());
		osilreader = new OSiLReader(); 
		cout << "create a new LINDO Solver for OSiL string solution" << endl;
		solver = new LindoSolver();	
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
		{	cout << "LINDO solver solution for lindoapiaddins in error:" << endl;
			cout << solver->osrl << endl;
		}
		if(ok == false) throw ErrorClass(" Fail unit test with LINDO on lindoapiaddins.osil");
		solver->osinstance = NULL;
		delete solver;
		solver = NULL;
		osilreader = NULL;	
		delete osolreader;
		unitTestResult << "TEST " << nOfTest << ": Solved problem lindoapiaddins.osil with Lindo" << std::endl;
		cout << endl << "TEST " << nOfTest << ": Completed successfully" << endl << endl;

#ifdef THOUROUGH
		// now solve the rosenbrock problem from the OSiL paper
		cout << endl << "TEST " << ++nOfTest << ": Lindo solver on rosenbrockmod.osil" << endl << endl;
		osilFileName = dataDir  + "osilFiles" + dirsep + "rosenbrockmod.osil";
		osolFileName = dataDir  + "osolFiles" + dirsep + "rosenbrockmod_lindo.osol";
		osil = fileUtil->getFileAsString( osilFileName.c_str());
		osol = fileUtil->getFileAsString( osolFileName.c_str());
		solver = new LindoSolver();	
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
		{	cout << "LINDO solver solution for rosenbrockmod in error:" << endl;
			cout << solver->osrl << endl;
		}
		if(ok == false) throw ErrorClass(" Fail unit test with LINDO on rosenbrockmod.osil");
		solver->osinstance = NULL;
		delete solver;
		solver = NULL;
		unitTestResult << "TEST " << nOfTest << ": Solved problem rosenbrockmod.osil with Lindo" << std::endl;
		cout << endl << "TEST " << nOfTest << ": Completed successfully" << endl << endl;

		// now solve a pure quadratic
		cout << endl << "TEST " << ++nOfTest << ": Lindo solver on parincQuadratic.osil" << endl << endl;
		osilFileName = dataDir  + "osilFiles" + dirsep + "parincQuadratic.osil";
		osolFileName = dataDir  + "osolFiles" + dirsep + "parincQuadratic_lindo.osol";
		osil = fileUtil->getFileAsString( osilFileName.c_str());
		osol = fileUtil->getFileAsString( osolFileName.c_str());
		osolreader = new OSoLReader(); 
		solver = new LindoSolver();	
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
		{	cout << "LINDO solver solution for parincQuadratic in error:" << endl;
			cout << solver->osrl << endl;
		}
		if(ok == false) throw ErrorClass(" Fail unit test with LINDO on parincQuadratic.osil");
		delete solver;
		solver = NULL;
		delete osolreader;
		osolreader = NULL;	
		unitTestResult << "TEST " << nOfTest << ": Solved problem parincQuadratic.osil with Lindo" << std::endl;
		cout << endl << "TEST " << nOfTest << ": Completed successfully" << endl << endl;

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
		{	cout << "LINDO solver solution for wayneQuadratic in error:" << endl;
			cout << solver->osrl << endl;
		}
		if(ok == false) throw ErrorClass(" Fail unit test with LINDO on wayneQuadratic.osil");
		delete solver;
		solver = NULL;
		osilreader = NULL;	
		delete osolreader;
		unitTestResult << "TEST " << nOfTest << ": Solved problem wayneQuadratic.osil with Lindo" << std::endl;
		cout << endl << "TEST " << nOfTest << ": Completed successfully" << endl << endl;
		*/
#endif		
	}
	catch(const ErrorClass& eclass){
		//cout << "OSrL =  " <<  solver->osrl <<  endl;
		cout << endl << endl << endl;
		unitTestResultFailure  <<"Sorry Unit Test Failed Testing the LINDO Solver:"  + eclass.errormsg << endl << endl;
	}
#endif
} // end of if(SOLVER_TESTS)



// now solve with an OSInstance created from an MPS file
if (OTHER_TESTS){
	try{
		cout << endl << "TEST " << ++nOfTest << ": Cbc solver using MPS file" << endl << endl;
		ok = true;
//		cout << endl;
//		cout << "START MPS TESTING" << endl << endl;
		cout << "create a COIN Solver for MPS - OSInstance solution" << endl;
		solver = new CoinSolver();
		solver->sSolverName = "cbc";
		mps2osil = new OSmps2osil( mpsFileName);
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
		{	cout << "COIN solver solution for parinc.mps in error:" << endl;
			cout << solver->osrl << endl;
		}
		if(ok == false) throw ErrorClass(" Fail unit test with COIN Solver on MPS test problem parincLinear.mps");
		delete solver;
		solver = NULL;
		delete mps2osil; 
		mps2osil = NULL;
//		cout << endl;
//		cout << "DONE WITH MPS TESTING" << endl;
		unitTestResult << "TEST " << nOfTest << ": Test the MPS -> OSiL converter on parinc.mps using Cbc" << std::endl;
		cout << endl << "TEST " << nOfTest << ": Completed successfully" << endl << endl;
	}
	catch(const ErrorClass& eclass){
		cout << "OSrL =  " <<  solver->osrl <<  endl;
		cout << endl << endl << endl;
		unitTestResultFailure  <<"Sorry Unit Test Failed Testing the MPS converter:"  + eclass.errormsg << endl;
	}
	
	
// test reading a GAMS file

#if  0
#ifdef COIN_HAS_GAMSUTILS
	std::cout  << "Working with GAMSIO " << std::endl;

	std::string gmsControlFile = "/home/kmartin/bin/gams/23.2/225a/gamscntr.dat";

  	
	OSgams2osil *gams2osil;
	gams2osil = new OSgams2osil( gmsControlFile);
	gams2osil->createOSInstance();
	std::cout << gams2osil->osinstance->printModel() << std::endl;
	std::cout  << "Done Working with GAMSIO " << std::endl;
	delete gams2osil;
	exit( 1);
#endif
#endif

// now solve with an OSInstance created from an AMPL nl file
	try{
#ifdef COIN_HAS_ASL
		cout << endl << "TEST " << ++nOfTest << ": AMPL solver interface" << endl << endl;
		ok = true;
		cout << "create a cbc Solver for AMPL nl - OSInstance solution" << endl;
		solver = new CoinSolver();
		solver->sSolverName = "cbc";
		nl2osil = new OSnl2osil( nlFileName); 
		nl2osil->createOSInstance() ;
		solver->osinstance = nl2osil->osinstance;	

		OSiLWriter tmp_osil_writer;
		tmp_osil_writer.m_bWhiteSpace = true;
		std::cout << tmp_osil_writer.writeOSiL( solver->osinstance) << std::endl;

		osol = "";  //<osol></osol>";
		solver->osol = osol;
		cout << "call Cbc Solve" << endl;
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
			cout << "COIN cbc solver solution for parinc.nl checks." << endl;
		}
		else
		{	cout << "COIN cbc solver solution for parinc.nl in error:" << endl;
			cout << solver->osrl << endl;
		}
		if(ok == false) throw ErrorClass(" Fail unit test with OSnl2osil on problem parinc.nl");
		solver->osinstance = NULL;
		delete solver;
		solver = NULL;
		cout << "call delete nl2osil" << endl;
		delete nl2osil;
		nl2osil = NULL;	
		unitTestResult << "TEST " << nOfTest << ": Test the AMPL nl -> OSiL converter on parinc.nl using Cbc" << std::endl; 
		cout << endl << "TEST " << nOfTest << ": Completed successfully" << endl << endl;
#endif
	}	
	catch(const ErrorClass& eclass){
		cout << "OSrL =  " <<  solver->osrl <<  endl;
		cout << endl << endl << endl;
		unitTestResultFailure  <<"Sorry Unit Test Failed Testing AMPL:"  + eclass.errormsg << endl;
	}

	//
	// Now test the mps feature
	//
	try{
		cout << endl << "TEST " << ++nOfTest << ": b64 operations" << endl << endl;
		ok = true;
		OSiLWriter osilwriter;
		osilwriter.m_bWriteBase64 = true;
		solver = new CoinSolver();
		solver->sSolverName = "cbc";
		mps2osil = new OSmps2osil( mpsFileName);
		solver->osinstance = NULL;
		osol = "<osol></osol>";
		solver->osol = osol;
		mps2osil->createOSInstance() ;
		solver->osil = osilwriter.writeOSiL( mps2osil->osinstance) ;
		std::cout << solver->osil << std::endl;
		solver->buildSolverInstance();
		solver->solve();
		cout << endl << endl;
		check = -7668;
		//ok &= NearEqual(getObjVal( solver->osrl) , check,  1e-1 , 1e-1);
		ok = ( fabs(check - getObjVal( solver->osrl) )/(fabs( check) + OS_NEAR_EQUAL) <= OS_NEAR_EQUAL) ? true : false;
		if (ok)
		{	cout << "COIN solution of a OSiL string in b64 format." << endl;
#ifdef DEBUG
			cout << solver->osrl << endl;
#endif			
		}
		else
		{	cout << "COIN solution of a OSiL string in b64 format:" << endl;
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

	}  


	// now test postfix and prefix routines
	try{
		cout << endl << "TEST " << ++nOfTest << ": postfix and prefix routines" << endl << endl;
		std::string expTreeTest =  dataDir  + "osilFiles" + dirsep + "rosenbrockmod.osil";
		osil = fileUtil->getFileAsString( expTreeTest.c_str() ) ;
		OSInstance *osinstance = NULL;
		//osinstance = new OSInstance();
		OSiLReader *osilreader = NULL;
		osilreader = new OSiLReader();
		//create an osinstance
		osinstance = osilreader->readOSiL( osil);
		OSExpressionTree* expTree = osinstance->getNonlinearExpressionTree( -1);
		if(expTree == NULL) throw ErrorClass(" Null expression tree when testing prefix and postfix routines");
		std::vector<OSnLNode*> postfixVec;
		//postfixVec = expTree->m_treeRoot->getPostfixFromExpressionTree();
		postfixVec = osinstance->getNonlinearExpressionTreeInPostfix( -1);
	
		unsigned int n = postfixVec.size();
		unsigned int i;
		std::string *nodeNames1 = new std::string[ n];
		std::string *nodeNames2 = new std::string[ n];
		for (i = 0 ; i < n; i++){
			std::cout << postfixVec[i]->snodeName << std::endl;
			nodeNames1[i] = postfixVec[i]->snodeName;
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
		std::cout << std::endl << std::endl;
		for (i = 0 ; i < n; i++){
			//std::cout << postfixVec[i]->snodeName << std::endl;
			nodeNames2[i] = postfixVec[i]->snodeName;
			if( nodeNames1[i] != nodeNames2[ i]) throw ErrorClass(" Problem with creating expression trees");
		}	
		
		//delete osinstance;
		delete[] nodeNames1;
		delete[] nodeNames2; 

		delete osilreader;
		osilreader = NULL;
		osinstance = NULL;		
		unitTestResult << "TEST " << nOfTest << ": Successful test of prefix and postfix conversion routines" << std::endl;
		cout << endl << "TEST " << nOfTest << ": Completed successfully" << endl << endl;
		
	}
	catch(const ErrorClass& eclass){
		cout << endl << endl << endl;
		unitTestResultFailure << eclass.errormsg << endl;
	}
	// now test the nonlinear operators	
	try{
		cout << endl << "TEST " << ++nOfTest << ": nonlinear operators" << endl << endl;
		ok = true;
		std::string operatorTest =  dataDir  + "osilFiles" + dirsep + "testOperators.osil";
		osil = fileUtil->getFileAsString( operatorTest.c_str() );
		OSInstance *osinstance = NULL;
		//osinstance = new OSInstance();
		OSiLReader *osilreader = NULL;
		osilreader = new OSiLReader();
		OSiLWriter *osilwriter = NULL;
		osilwriter = new OSiLWriter();
//		cout << "Read testOperators.osil...";
		osinstance = osilreader->readOSiL( osil);
		
		cout << "Done" << endl;
		OSExpressionTree* expTree = osinstance->getNonlinearExpressionTree( -1);
		std::vector<OSnLNode*> postfixVec;
		postfixVec = expTree->m_treeRoot->getPostfixFromExpressionTree();
		int n = postfixVec.size();
		std::string *nodeNames1 = new std::string[ n];
		for (int i = 0 ; i < n; i++){
			std::cout << postfixVec[i]->snodeName << std::endl;
			nodeNames1[i] = postfixVec[i]->snodeName;
		}
		std::cout << std::endl << std::endl;
		std::cout << osilwriter->writeOSiL( osinstance) << std::endl;
		// now test value
		double *x = NULL;
		x = new double[2];
		x[0] = 1;
		x[1] = 2;
		double parserTestVal = expTree->m_treeRoot->calculateFunction( x);
		std::cout << "ParserTest Val = " << parserTestVal << std::endl;
		check = 11;
		//ok &= NearEqual(expTree->m_treeRoot->calculateFunction( x) , check,  1e-10 , 1e-10);
		ok = ( fabs(check -  expTree->m_treeRoot->calculateFunction( x))/(fabs( check) + OS_NEAR_EQUAL) <= OS_NEAR_EQUAL) ? true : false;
		if(ok == false) throw ErrorClass(" Problem evaluating expression tree");
		delete[] x;
		delete[] nodeNames1;
		delete osilreader;
		osilreader = NULL;
		delete osilwriter;
		osilwriter = NULL;
		osinstance = NULL;
		//create an osinstance
		unitTestResult << "TEST " << nOfTest << ": Successful test of nonlinear operators using file testOperators.osil" << std::endl;
		cout << endl << "TEST " << nOfTest << ": Completed successfully" << endl << endl;
	}
	catch(const ErrorClass& eclass){
		cout << endl << endl << endl;
		unitTestResultFailure << eclass.errormsg << endl;
	}
// Automatic differentiation
	try{
		cout << endl << "TEST " << ++nOfTest << ": Automatic differentiation" << endl << endl;
//		std::cout << std::endl << std::endl;
//		std::cout << "Testing AD Features " << std::endl;
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
		OSInstance *osinstance = NULL;
		//osinstance = new OSInstance();
		OSiLReader *osilreader = NULL;
		osilreader = new OSiLReader();
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
		for(int i = 0; i < sp->number; i++){
			std::cout << "gradient value " << sp->values[i] << std::endl;
		}
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
		SparseHessianMatrix *sh;
		// calcuate Hessian of objective function (index = -1)
		osinstance->getLagrangianHessianSparsityPattern( );
		sh = osinstance->calculateHessian(x, -1, true);
		for(int i = 0; i < sh->hessDimension; i++){
			std::cout << "Hessian value " << sh->hessValues[i] << std::endl;
		}
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
		delete osilreader;
		osilreader = NULL;
		unitTestResult << "TEST " << nOfTest << ": Successful test of AD gradient and Hessian calculations" << std::endl;
		cout << endl << "TEST " << nOfTest << ": Completed successfully" << endl << endl;
	}	
	catch(const ErrorClass& eclass){
		cout << endl << endl << endl;
		unitTestResultFailure << eclass.errormsg << endl;
	}
} //end of if (OTHER_TESTS)

	//
	// Now test the parsers --- OSiL parser first
if (PARSER_TESTS){

//#if 0   //!!!  OSrL parser development
	try{ 
		cout << endl << "TEST " << ++nOfTest << ":  OSiL parser" << endl << endl;
		clock_t start, finish;
		double duration;
		OSiLWriter *osilwriter = NULL;
		osilwriter = new OSiLWriter();
		//delete fileUtil;
		//fileUtil = NULL;
		//fileUtil = new FileUtil();
		cout << "TEST PARSING A MODEL" << endl;
		cout << "FIRST READ THE FILE INTO A STRING" << endl;
		start = clock();
		osilFileName = dataDir  + "osilFiles" + dirsep + "parincLinear.osil";
		osil = fileUtil->getFileAsString( osilFileName.c_str());
		finish = clock();
		duration = (double) (finish - start) / CLOCKS_PER_SEC;
		cout << "Reading the file into a string took (seconds): "<< duration << endl;
		OSiLReader *osilreader = NULL;
		osilreader = new OSiLReader(); 
		start = clock();
		cout << "PARSE THE OSIL STRING INTO AN OSINSTANCE OBJECT" << endl;
		osilreader->readOSiL( osil);
		//cout << osilwriter->writeOSiL( osilreader->readOSiL( osil)) << endl;
		delete osilreader;
		osilreader = 0;
		delete osilwriter;
		osilwriter = NULL;
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
		
	}	

	//
	// Now test the extensions to the OSiL format: <timeDomain>, etc.

	try{ 
		cout << endl << "TEST " << ++nOfTest << ": Stochastic extensions to OSiL" << endl << endl;
		clock_t start, finish;
		double duration;
		OSiLWriter *osilwriter = NULL;
		osilwriter = new OSiLWriter();
		//delete fileUtil;
		//fileUtil = NULL;
		//fileUtil = new FileUtil();
		cout << "\nTEST PARSING A STOCHASTIC MODEL" << endl;
		cout << "FIRST READ THE FILE INTO A STRING" << endl;
		start = clock();
		osilFileName = dataDir  + "osilFiles" + dirsep + "finplan1.osil";
		osil = fileUtil->getFileAsString( &osilFileName[0]);
		finish = clock();
		duration = (double) (finish - start) / CLOCKS_PER_SEC;
		cout << "Reading the file into a string took (seconds): "<< duration << endl;
		OSiLReader *osilreader = NULL;
		osilreader = new OSiLReader(); 
		start = clock();
		cout << "PARSE THE OSIL STRING INTO AN OSINSTANCE OBJECT" << endl;
		osilreader->readOSiL( osil);
		//cout << osilwriter->writeOSiL( osilreader->readOSiL( &osil)) << endl;
		delete osilreader;
		osilreader = 0;
		delete osilwriter;
		osilwriter = NULL;
		finish = clock();
		duration = (double) (finish - start) / CLOCKS_PER_SEC;
		cout << "Parsing took (seconds): "<< duration << endl;
		unitTestResult << "TEST " << nOfTest << ": Successful test of OSiL parser on problem finplan1.osil" << std::endl;
		cout << endl << "TEST " << nOfTest << ": Completed successfully" << endl << endl;
	}	
	catch(const ErrorClass& eclass){
		cout << endl << endl << endl;
		cout << eclass.errormsg << endl;
		unitTestResultFailure << "Error parsing an osil file with time domain information" << endl;		
	}	
/** --------------------------------
 *  Test the get() and set() methods
 *  --------------------------------**/
	try{ 
		cout << endl << "TEST " << ++nOfTest << ": GET() AND SET() METHODS FOR TimeDomain OBJECT" << endl << endl;
		OSInstance *osinstance = NULL;
		//osinstance = new OSInstance();
		//OSiLReader *osilreader = NULL;
		osilreader = new OSiLReader();
		//create an osinstance
		osinstance = osilreader->readOSiL( osil);
		std::string f = osinstance->getTimeDomainFormat();
		ok = (f == "stages");
		int n = osinstance->getTimeDomainStageNumber();
		ok &= (n == 6);

		std::string* sncheck = new std::string[6];
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

		int* nvcheck = new int[6];
		nvcheck[0] = 2;
		nvcheck[1] = 2;
		nvcheck[2] = 0;
		nvcheck[3] = 0;
		nvcheck[4] = 2;
		nvcheck[5] = 2;

		for (int i = 0; i < 6; i++)
			ok &= (nv[i] == nvcheck[i]);

		int* nc = osinstance->getTimeDomainStageNumberOfConstraints();

		int* nccheck = new int[6];
		nccheck[0] = 1;
		nccheck[1] = 1;
		nccheck[2] = 0;
		nccheck[3] = 0;
		nccheck[4] = 1;
		nccheck[5] = 1;

		for (int i = 0; i < 6; i++)
			ok &= (nc[i] == nccheck[i]);

		int* no = osinstance->getTimeDomainStageNumberOfObjectives();

		int* nocheck = new int[6];
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

		int** lvcheck = new int*[6];
		int** lccheck = new int*[6];
		int** locheck = new int*[6];
		for (int i = 0; i < 6; i++) {
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

		std::string* sn1 = new std::string[6];
		int* nv1 = new int[6];
		int* nc1 = new int[6];
		int* no1 = new int[6];
		int** lv1 = new int*[6];
		int** lc1 = new int*[6];
		int** lo1 = new int*[6];
		for (int i = 0; i < 6; i++) {
			lv1[i] = new int[2];
			lc1[i] = new int[2];
			lo1[i] = new int[2];
		};
		for (int i = 0; i < 6; i++) {
			sn1[i] = sn[i];
			nv1[i] = nv[i];
			nc1[i] = nc[i];
			no1[i] = no[i];
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

		int *nelem, *startIdx, **VI;
		nelem = new int[4];
		startIdx = new int[4];
		VI = new int*[4];
		for (int i = 0; i < 4; i++)
		{	nelem[i] = 2;
			startIdx[i] = 2*i;
			VI[i] = new int[2];
			VI[i][0] = 2*i;
			VI[i][1] = 2*i + 1;
		};
		ok &= osinstance->setTimeDomainStageVariablesUnordered(4,nelem,VI);

		for (int i = 0; i < 4; i++)
		{	nelem[i] = 1;
			startIdx[i] = i;
		};
		ok &= osinstance->setTimeDomainStageConstraintsOrdered(4,nelem,startIdx);

		for (int i = 0; i < 4; i++)
		{	nelem[i] = 1;
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
		{	ok &= (sn2[i] == sncheck[i]);
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
		delete [] sncheck;
		sncheck = NULL;
		delete [] nvcheck;
		nvcheck = NULL;
		delete [] nccheck;
		nccheck = NULL;
		delete [] nocheck;
		nocheck = NULL;
		for (int i = 0; i < 6; i++) {
			delete [] lvcheck[i];
			delete [] lccheck[i];
			delete [] locheck[i];
			delete [] lv1[i];
			delete [] lc1[i];
			delete [] lo1[i];
		};
		delete [] lvcheck;
		lvcheck = NULL;
		delete [] lccheck;
		lccheck = NULL;
		delete [] locheck;
		locheck = NULL;
		delete [] lv1;
		lv1 = NULL;
		delete [] lc1;
		lc1 = NULL;
		delete [] lo1;
		lo1 = NULL;
		delete [] sn1;
		sn1 = NULL;
		delete[] nv1;
		nv1 = NULL;
		delete[] nc1;
		nc1 = NULL;
		delete[] no1;
		no1 = NULL;
		delete [] nelem;
		nelem = NULL;
		delete [] startIdx;
		startIdx = NULL;
		for (int i = 0; i < 4; i++) {
			delete [] VI[i];
		};
		delete [] VI;
		VI = NULL;
		delete osilreader;
		unitTestResult << "TEST " << nOfTest << ": Successful test of osinstance get() and set() methods" << std::endl;
		cout << endl << "TEST " << nOfTest << ": Completed successfully" << endl << endl;
	}	
	catch(const ErrorClass& eclass){
		cout << endl << endl << endl;
		cout << eclass.errormsg << endl;
		unitTestResultFailure << "Sorry Unit Test Failed osinstance get() and set() Methods" << endl;		
	}	

	//
	// Now test the OSoL parser
	OSoLWriter *osolwriter = NULL;
//	OSoLReader *osolreader = NULL;
	//osolwriter = new OSoLWriter();
	//osolreader = new OSoLReader();

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
		 */
		cout << endl << "TEST " << ++nOfTest << ": OSoL parser" << endl << endl;
		std::string tmpOSoL;
		clock_t start, finish;
		double duration;
		osolwriter = new OSoLWriter();
		osolreader = new OSoLReader();
		OSOption *osoption = NULL;
		//osoption = new OSOption(); 
		cout << "TEST PARSING AN OSoL FILE" << endl;
		cout << "FIRST READ THE OSoL FILE INTO A STRING" << endl;
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
		ok = osoption->setAnotherInitBasisStatus(6,"unknown") && ok;
		ok = osoption->setAnotherIntegerVariableBranchingWeight(5,100.) && ok;

		int SOS3idx[2];
		double SOS3val[2];
		SOS3idx[0] = 3;
		SOS3idx[1] = 6;
		SOS3val[0] = 1.0;
		SOS3val[1] = 2.0;
		int tnvar;
		tnvar = osoption->getNumberOfSOS(); 
		ok = osoption->setAnotherSOSVariableBranchingWeight(3,2,1.0,SOS3idx,SOS3val) && ok;
		assert (osoption->getNumberOfSOS() == (tnvar + 1));
		assert (osoption->optimization->variables->sosVariableBranchingWeights->sos[tnvar]->var[0]->idx == 3);
		assert (osoption->optimization->variables->sosVariableBranchingWeights->sos[tnvar]->var[1]->idx == 6);
		assert (osoption->optimization->variables->sosVariableBranchingWeights->sos[tnvar]->var[0]->value == 1.0);
		assert (osoption->optimization->variables->sosVariableBranchingWeights->sos[tnvar]->var[1]->value == 2.0);
#ifdef DEBUG
		cout << endl << "another SOS has been added" << endl << endl;
#endif

		OtherVariableOption *varopt;
		varopt = new OtherVariableOption();
		varopt->name = "testVarOpt";
		varopt->numberOfVar = 0;
		ok = osoption->setAnOtherVariableOption(varopt) && ok;
		delete varopt;
		varopt = NULL;

		OtherObjectiveOption *objopt;
		objopt = new OtherObjectiveOption();
		objopt->name = "testObjOpt";
		objopt->numberOfObj = 0;
		ok = osoption->setAnOtherObjectiveOption(objopt) && ok;
		delete objopt;
		objopt = NULL;

		ok = osoption->setAnotherInitConValue(2,17.0) && ok;
		ok = osoption->setAnotherInitDualVarValue(2,0.0,DBL_MAX) && ok;

		OtherConstraintOption *conopt;
		conopt = new OtherConstraintOption();
		conopt->name = "testObjOpt";
		conopt->numberOfCon = 2;
		conopt->con = new OtherConOption*[2];
		conopt->con[0] = new OtherConOption();
		conopt->con[0]->idx = 0;
		conopt->con[0]->value = "3.0";
		conopt->con[1] = new OtherConOption();
		conopt->con[1]->idx = 1;
		conopt->con[1]->lbValue = "0.0";
		conopt->con[1]->ubValue = "10.0";
		ok = osoption->setAnOtherConstraintOption(conopt) && ok;
		delete conopt;
		conopt = NULL;

		ok = osoption->setAnotherSolverOption("HoHum","gus","PhoNY","","test","") && ok;

		if (!ok)
			throw ErrorClass(" Could not add to osoption data structure");

		//Now transfer to another osoption using get() and set() methods
		std::string optionstring;
		int option_i;
		double option_d;
		OSOption* osoption2 = new OSOption();

		cout << endl << "transfer osoption to another OSOption object" << endl;

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

		option_d = osoption->getMinDiskSpace();
		ok = osoption2->setMinDiskSpace(option_d) && ok;
#ifdef DEBUG
		if (!ok)
			throw ErrorClass(" error in get/set MinDiskSpace");
#endif

		optionstring = osoption->getMinDiskSpaceUnit();
		ok = osoption2->setMinDiskSpaceUnit(optionstring) && ok;
#ifdef DEBUG
		if (!ok)
			throw ErrorClass(" error in get/set MinDiskSpaceUnit");
#endif

		option_d = osoption->getMinMemorySize();
		ok = osoption2->setMinMemorySize(option_d) && ok;
#ifdef DEBUG
		if (!ok)
			throw ErrorClass(" error in get/set MinMemorySize");
#endif

		optionstring = osoption->getMinMemoryUnit();
		ok = osoption2->setMinMemoryUnit(optionstring) && ok;
#ifdef DEBUG
		if (!ok)
			throw ErrorClass(" error in get/set MinMemoryUnit");
#endif

		option_d = osoption->getMinCPUSpeed();
		ok = osoption2->setMinCPUSpeed(option_d) && ok;
#ifdef DEBUG
		if (!ok)
			throw ErrorClass(" error in get/set MinCPUSpeed");
#endif

		optionstring = osoption->getMinCPUSpeedUnit();
		ok = osoption2->setMinCPUSpeedUnit(optionstring) && ok;
#ifdef DEBUG
		if (!ok)
			throw ErrorClass(" error in get/set MinCPUSpeedUnit");
#endif

		option_i = osoption->getMinCPUNumber();
		ok = osoption2->setMinCPUNumber(option_i) && ok;
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
		//nvar = osoption->getOptionInt("numberOfVariables");
		//ok = osoption2->setNumberOfVariables(nvar) && ok;
		//nobj = osoption->getOptionInt("numberOfObjectives");
		//ok = osoption2->setNumberOfObjectives(nobj) && ok;
		//ncon = osoption->getOptionInt("numberOfConstraints");
		//ok = osoption2->setNumberOfConstraints(ncon) && ok;
		// eliminate references to numberOfVariables
		nvar = 10; 
		nobj = 1; 
		ncon = 4; 
#ifdef DEBUG
		if (!ok)
			throw ErrorClass(" error in get/set problem dimensions");
#endif
 
// for the variables, objectives and constraints use a mixture of dense and sparse methods
		double* IVV;
		IVV = osoption->getInitVarValuesDense(nvar);
		ok = osoption2->setInitVarValuesDense(nvar, IVV) && ok;
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

		std::string*  IBS;
		IBS = osoption->getInitBasisStatusDense(nvar);
		ok = osoption2->setInitBasisStatusDense(nvar, IBS) && ok;		
#ifdef DEBUG
		if (!ok)
			throw ErrorClass(" error in get/set InitBasisStatus");
#endif

		double* IVBW;
		IVBW = osoption->getIntegerVariableBranchingWeightsDense(nvar);
		ok = osoption2->setIntegerVariableBranchingWeightsDense(nvar, IVBW) && ok;		
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

		double* IOV;
		IOV = osoption->getInitObjValuesDense(nobj);
		ok = osoption2->setInitObjValuesDense(nobj, IOV) && ok;		
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

		OtherObjectiveOption** otherO;
		otherO = osoption->getAllOtherObjectiveOptions();
		nopt = osoption->getNumberOfOtherObjectiveOptions();
		ok = osoption2->setOtherObjectiveOptions(nopt, otherO) && ok;
#ifdef DEBUG
		if (!ok)
			throw ErrorClass(" error in get/set OtherObjectiveOptions");
#endif

		
		double* ICV;
		ICV = osoption->getInitConValuesDense(ncon);
		ok = osoption2->setInitConValuesDense(ncon, ICV) && ok;		
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
			throw ErrorClass(" OSOption get() and  set() methods do not work correctly");

		delete osoption2;
		osoption2 = NULL;

		cout << "Write the content to a new file" << endl;		
		tmpOSoL = osolwriter->writeOSoL( osoption);
		cout << endl << "Here is tmpOSoL:" <<endl;
		cout << endl << endl << tmpOSoL << endl;
		cout << "-----------------------------------------" << endl << endl;
//		delete osolreader;
//		osolreader = NULL;

		// make sure we can parse without error
		OSoLReader *osolreader2;
		osolreader2 = new OSoLReader();
		cout << "Read the string back" << endl;

		OSOption *osoption3 = NULL;
		osoption3 = osolreader2->readOSoL( tmpOSoL);

		ok = osoption->IsEqual(osoption3);
		if (!ok)
			throw ErrorClass(" Loss of information in OSoL write/read");
		delete osolreader2;
		osolreader2 = NULL;


		delete osolwriter;
		osolwriter = NULL;
		delete osolreader;
		osolreader = NULL;
		unitTestResult << 
		     "TEST " << nOfTest << ": Successful test of OSoL parser on file parsertest.osol" 
		      << std::endl;
		cout << endl << "TEST " << nOfTest << ": Completed successfully" << endl << endl;


		// now a second example
		cout << endl << "TEST " << ++nOfTest << ": Parse another .osol file" << endl << endl;
		osolwriter = new OSoLWriter();
		osolreader = new OSoLReader();
		cout << "First read the OSoL file into a string" << endl;
		osolFileName = dataDir  + "osolFiles" + dirsep + "parsertest2.osol"; 
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

		// and a third example
		cout << "Test parsing another OSoL file" << endl;
		osolwriter = new OSoLWriter();
		osolreader = new OSoLReader();
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
		cout << endl << endl << endl;
		if(osolwriter != NULL) delete osolwriter;
		if(osolreader != NULL) delete osolreader;
		// " Problem with the test reading OSoL data";
		unitTestResultFailure << eclass.errormsg << endl;
		unitTestResultFailure << "There was a failure in the test for reading OSoL" << endl;
	}

//#endif //!!!  end of #if 0: OSrL parser development

/** The first test makes sure that the set() and IsEqual() methods work correctly.
 *  Two OSResult objects are built one element and attribute at a time.
 *  After every call to the appropriate set() method the two objects are compared:
 *  After the first object has been modified, the objects should compare NOT equal; 
 *  after the second object has been updated in the same way, the objects should be equal.
 */
	OSResult *osresult1 = new OSResult();
	OSResult *osresult2 = new OSResult();
	OSResult *osresult3 = NULL;
	try{ 
		cout << endl << "TEST " << ++nOfTest << ": OSrL tools" << endl << endl;
		ok = true;
		ok &= (osresult1->IsEqual(osresult2));
		if (!ok) 
			throw ErrorClass("Empty osresult objects do not compare equal!");

//	<general> element
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
			ok &= osresult1->setGeneralOtherResultName(i,"some name");
			if (!ok) 
				throw ErrorClass("Error during setGeneralOtherResultName!");
			ok &= (!osresult1->IsEqual(osresult2));
			if (!ok) 
				throw ErrorClass("setGeneralOtherResultName: osresult objects falsely compare equal!");
			ok &= osresult2->setGeneralOtherResultName(i,"some name");
			if (!ok) 
				throw ErrorClass("Error during setGeneralOtherResultName!");
			ok &= (osresult1->IsEqual(osresult2));
			if (!ok) 
				throw ErrorClass("setGeneralOtherResultName: osresult objects falsely compare unequal!");

			ok &= osresult1->setGeneralOtherResultValue(i,"some value");
			if (!ok) 
				throw ErrorClass("Error during setGeneralOtherResultValue!");
			ok &= (!osresult1->IsEqual(osresult2));
			if (!ok) 
				throw ErrorClass("setGeneralOtherResultValue: osresult objects falsely compare equal!");
			ok &= osresult2->setGeneralOtherResultValue(i,"some value");
			if (!ok) 
				throw ErrorClass("Error during setGeneralOtherResultValue!");
			ok &= (osresult1->IsEqual(osresult2));
			if (!ok) 
				throw ErrorClass("setGeneralOtherResultValue: osresult objects falsely compare unequal!");

			ok &= osresult1->setGeneralOtherResultDescription(i,"ABC 123");
			if (!ok) 
				throw ErrorClass("Error during setGeneralOtherResultDescription!");
			ok &= (!osresult1->IsEqual(osresult2));
			if (!ok) 
				throw ErrorClass("setGeneralOtherResultDescription: osresult objects falsely compare equal!");
			ok &= osresult2->setGeneralOtherResultDescription(i,"ABC 123");
			if (!ok) 
				throw ErrorClass("Error during setGeneralOtherResultDescription!");
			ok &= (osresult1->IsEqual(osresult2));
			if (!ok) 
				throw ErrorClass("setGeneralOtherResultDescription: osresult objects falsely compare unequal!");
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
			ok &= osresult1->setSystemOtherResultName(i,"some name");
			if (!ok) 
				throw ErrorClass("Error during setSystemOtherResultName!");
			ok &= (!osresult1->IsEqual(osresult2));
			if (!ok) 
				throw ErrorClass("setSystemOtherResultName: osresult objects falsely compare equal!");
			ok &= osresult2->setSystemOtherResultName(i,"some name");
			if (!ok) 
				throw ErrorClass("Error during setSystemOtherResultName!");
			ok &= (osresult1->IsEqual(osresult2));
			if (!ok) 
				throw ErrorClass("setSystemOtherResultName: osresult objects falsely compare unequal!");

			ok &= osresult1->setSystemOtherResultValue(i,"some value");
			if (!ok) 
				throw ErrorClass("Error during setSystemOtherResultValue!");
			ok &= (!osresult1->IsEqual(osresult2));
			if (!ok) 
				throw ErrorClass("setSystemOtherResultValue: osresult objects falsely compare equal!");
			ok &= osresult2->setSystemOtherResultValue(i,"some value");
			if (!ok) 
				throw ErrorClass("Error during setSystemOtherResultValue!");
			ok &= (osresult1->IsEqual(osresult2));
			if (!ok) 
				throw ErrorClass("setSystemOtherResultValue: osresult objects falsely compare unequal!");

			ok &= osresult1->setSystemOtherResultDescription(i,"ABC 123");
			if (!ok) 
				throw ErrorClass("Error during setSystemOtherResultDescription!");
			ok &= (!osresult1->IsEqual(osresult2));
			if (!ok) 
				throw ErrorClass("setSystemOtherResultDescription: osresult objects falsely compare equal!");
			ok &= osresult2->setSystemOtherResultDescription(i,"ABC 123");
			if (!ok) 
				throw ErrorClass("Error during setSystemOtherResultDescription!");
			ok &= (osresult1->IsEqual(osresult2));
			if (!ok) 
				throw ErrorClass("setSystemOtherResultDescription: osresult objects falsely compare unequal!");
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
			ok &= osresult1->setServiceOtherResultName(i,"some name");
			if (!ok) 
				throw ErrorClass("Error during setServiceOtherResultName!");
			ok &= (!osresult1->IsEqual(osresult2));
			if (!ok) 
				throw ErrorClass("setServiceOtherResultName: osresult objects falsely compare equal!");
			ok &= osresult2->setServiceOtherResultName(i,"some name");
			if (!ok) 
				throw ErrorClass("Error during setServiceOtherResultName!");
			ok &= (osresult1->IsEqual(osresult2));
			if (!ok) 
				throw ErrorClass("setServiceOtherResultName: osresult objects falsely compare unequal!");

			ok &= osresult1->setServiceOtherResultValue(i,"some value");
			if (!ok) 
				throw ErrorClass("Error during setServiceOtherResultValue!");
			ok &= (!osresult1->IsEqual(osresult2));
			if (!ok) 
				throw ErrorClass("setServiceOtherResultValue: osresult objects falsely compare equal!");
			ok &= osresult2->setServiceOtherResultValue(i,"some value");
			if (!ok) 
				throw ErrorClass("Error during setServiceOtherResultValue!");
			ok &= (osresult1->IsEqual(osresult2));
			if (!ok) 
				throw ErrorClass("setServiceOtherResultValue: osresult objects falsely compare unequal!");

			ok &= osresult1->setServiceOtherResultDescription(i,"ABC 123");
			if (!ok) 
				throw ErrorClass("Error during setServiceOtherResultDescription!");
			ok &= (!osresult1->IsEqual(osresult2));
			if (!ok) 
				throw ErrorClass("setServiceOtherResultDescription: osresult objects falsely compare equal!");
			ok &= osresult2->setServiceOtherResultDescription(i,"ABC 123");
			if (!ok) 
				throw ErrorClass("Error during setServiceOtherResultDescription!");
			ok &= (osresult1->IsEqual(osresult2));
			if (!ok) 
				throw ErrorClass("setServiceOtherResultDescription: osresult objects falsely compare unequal!");
		}
//======================
//	<job> element
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
			ok &= osresult1->setTimingInformation(i,"cpuTime","other","tick","blabla",3.14);
			if (!ok) 
				throw ErrorClass("Error during setTimingInformation!");
			ok &= (!osresult1->IsEqual(osresult2));
			if (!ok) 
				throw ErrorClass("setTimingInformation: osresult objects falsely compare equal!");
			ok &= osresult2->setTimingInformation(i,"cpuTime","other","tick","blabla",3.14);
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
			ok &= osresult1->setJobOtherResultName(i,"some name");
			if (!ok) 
				throw ErrorClass("Error during setJobOtherResultName!");
			ok &= (!osresult1->IsEqual(osresult2));
			if (!ok) 
				throw ErrorClass("setJobOtherResultName: osresult objects falsely compare equal!");
			ok &= osresult2->setJobOtherResultName(i,"some name");
			if (!ok) 
				throw ErrorClass("Error during setJobOtherResultName!");
			ok &= (osresult1->IsEqual(osresult2));
			if (!ok) 
				throw ErrorClass("setJobOtherResultName: osresult objects falsely compare unequal!");

			ok &= osresult1->setJobOtherResultValue(i,"some value");
			if (!ok) 
				throw ErrorClass("Error during setJobOtherResultValue!");
			ok &= (!osresult1->IsEqual(osresult2));
			if (!ok) 
				throw ErrorClass("setJobOtherResultValue: osresult objects falsely compare equal!");
			ok &= osresult2->setJobOtherResultValue(i,"some value");
			if (!ok) 
				throw ErrorClass("Error during setJobOtherResultValue!");
			ok &= (osresult1->IsEqual(osresult2));
			if (!ok) 
				throw ErrorClass("setJobOtherResultValue: osresult objects falsely compare unequal!");

			ok &= osresult1->setJobOtherResultDescription(i,"ABC 123");
			if (!ok) 
				throw ErrorClass("Error during setJobOtherResultDescription!");
			ok &= (!osresult1->IsEqual(osresult2));
			if (!ok) 
				throw ErrorClass("setJobOtherResultDescription: osresult objects falsely compare equal!");
			ok &= osresult2->setJobOtherResultDescription(i,"ABC 123");
			if (!ok) 
				throw ErrorClass("Error during setJobOtherResultDescription!");
			ok &= (osresult1->IsEqual(osresult2));
			if (!ok) 
				throw ErrorClass("setJobOtherResultDescription: osresult objects falsely compare unequal!");
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

			for (int j=0; j < 3; ++j)
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
				ok &= osresult1->setVarValue(i,j,j,3.14);
				if (!ok) 
					throw ErrorClass("Error during setVarValue!");
				ok &= (!osresult1->IsEqual(osresult2));
				if (!ok) 
					throw ErrorClass("setVarValue: osresult objects falsely compare equal!");
				ok &= osresult2->setVarValue(i,j,j,3.14);
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
				ok &= osresult1->setVarValueString(i,j,j,"one");
				if (!ok) 
					throw ErrorClass("Error during setVarValueString!");
				ok &= (!osresult1->IsEqual(osresult2));
				if (!ok) 
					throw ErrorClass("setVarValueString: osresult objects falsely compare equal!");
				ok &= osresult2->setVarValueString(i,j,j,"one");
				if (!ok) 
					throw ErrorClass("Error during setVarValueString!");
				ok &= (osresult1->IsEqual(osresult2));
				if (!ok) 
					throw ErrorClass("setVarValueString: osresult objects falsely compare unequal!");
			}

			ok &= osresult1->setNumberOfBasisVar(i,3);
			if (!ok) 
				throw ErrorClass("Error during setNumberOfBasisVar!");
			ok &= (!osresult1->IsEqual(osresult2));
			if (!ok) 
				throw ErrorClass("setNumberOfBasisVar: osresult objects falsely compare equal!");
			ok &= osresult2->setNumberOfBasisVar(i,3);
			if (!ok) 
				throw ErrorClass("Error during setNumberOfBasisVar!");
			ok &= (osresult1->IsEqual(osresult2));
			if (!ok) 
				throw ErrorClass("setNumberOfBasisVar: osresult objects falsely compare unequal!");

			for (int j=0; j < 3; ++j)
			{
				ok &= osresult1->setBasisVar(i,j,j,"superBasic");
				if (!ok) 
					throw ErrorClass("Error during setBasisVar!");
				ok &= (!osresult1->IsEqual(osresult2));
				if (!ok) 
					throw ErrorClass("setBasisVar: osresult objects falsely compare equal!");
				ok &= osresult2->setBasisVar(i,j,j,"superBasic");
				if (!ok) 
					throw ErrorClass("Error during setBasisVar!");
				ok &= (osresult1->IsEqual(osresult2));
				if (!ok) 
					throw ErrorClass("setBasisVar: osresult objects falsely compare unequal!");
			}

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

			for (int j=0; j < 3; ++j)
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
				ok &= osresult1->setObjValue(i,j,-2,3.14);
				if (!ok) 
					throw ErrorClass("Error during setObjValue!");
				ok &= (!osresult1->IsEqual(osresult2));
				if (!ok) 
					throw ErrorClass("setObjValue: osresult objects falsely compare equal!");
				ok &= osresult2->setObjValue(i,j,-2,3.14);
				if (!ok) 
					throw ErrorClass("Error during setObjValue!");
				ok &= (osresult1->IsEqual(osresult2));
				if (!ok) 
					throw ErrorClass("setObjValue: osresult objects falsely compare unequal!");
			}

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

			for (int j=0; j < 3; ++j)
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
				ok &= osresult1->setDualValue(i,j,j,3.14);
				if (!ok) 
					throw ErrorClass("Error during setDualValue!");
				ok &= (!osresult1->IsEqual(osresult2));
				if (!ok) 
					throw ErrorClass("setDualValue: osresult objects falsely compare equal!");
				ok &= osresult2->setDualValue(i,j,j,3.14);
				if (!ok) 
					throw ErrorClass("Error during setDualValue!");
				ok &= (osresult1->IsEqual(osresult2));
				if (!ok) 
					throw ErrorClass("setDualValue: osresult objects falsely compare unequal!");
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

		std::cout << "Two copies of osresult built correctly" << std::endl;
		osrlwriter = new OSrLWriter();
		osrlreader = new OSrLReader();
		std::string tempOSrL;

		std::cout << "Write osresult to temporary string" << std::endl;
		tempOSrL = osrlwriter->writeOSrL( osresult1) ;
		std::cout << tempOSrL << std::endl;
		std::cout << "Read string into a new copy of osresult" << std::endl;
		osresult3 = osrlreader->readOSrL( tempOSrL);
		std::cout << "Compare the two copies of osresult" << std::endl;
		ok &= (osresult1->IsEqual(osresult3));
		if (!ok) 
			throw ErrorClass("Writing an osresult then reading leads to loss of data");

//=================

		std::cout << std::endl << "done" << std::endl;

		if (osrlwriter != NULL) delete osrlwriter;
		if (osrlreader != NULL) delete osrlreader;
		if (osresult1  != NULL) delete osresult1;
		if (osresult2  != NULL) delete osresult2;
		if (osresult3  != NULL) delete osresult3;

		unitTestResult << "TEST " << nOfTest << ": Successful test of OSrL tools" << std::endl;
		cout << endl << "TEST " << nOfTest << ": Completed successfully" << endl << endl;
	}	
	
	catch(const ErrorClass& eclass){
		cout << endl << endl << endl;
		if (osrlwriter != NULL) delete osrlwriter;
		if (osrlreader != NULL) delete osrlreader;
		if (osresult1  != NULL) delete osresult1;
		if (osresult2  != NULL) delete osresult2;
		if (osresult3  != NULL) delete osresult3;
		// " Problem with the test reading OSoL data";
		unitTestResultFailure << eclass.errormsg << endl;
		unitTestResultFailure << "There was a failure in the test of OSrL tools" << endl;
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
		 */
		cout << endl << "TEST " << ++nOfTest << ": OSrL parser" << endl << endl;
		std::string tmpOSrL;
		clock_t start, finish;
		double duration;
		std::string osrl;
		OSResult *osresult = NULL;
		osrlwriter = new OSrLWriter();
		osrlreader = new OSrLReader();
		//osresult = new OSResult(); 
		cout << "TEST PARSING AN OSrL FILE" << endl;
		cout << "FIRST READ THE OSrL FILE INTO A STRING" << endl;
		osrlFileName = dataDir  + "osrlFiles" + dirsep + "parserTest.osrl"; 
//		osrlFileName = dataDir  + "osrlFiles" + dirsep + "rosenbrockmod.osrl"; 
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

		tmpOSrL = osrlwriter->writeOSrL( osresult) ;
		cout << tmpOSrL << endl;


		// make sure we can parse without error
		delete osrlreader;
		osrlreader = NULL;
		osrlreader = new OSrLReader();
		cout << "Parse temporary string" << endl;
		osrlreader->readOSrL( tmpOSrL);
		delete osrlwriter;
		osrlwriter = NULL;
		delete osrlreader;
		osrlreader = NULL;


/*		// now a second example
		cout << endl << "TEST PARSING ANOTHER OSrL FILE" << endl;
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
		osrlreader = NULL;
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
		osrlreader = NULL;
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
		osrlreader = NULL;
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
		osrlreader = NULL;
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
		osrlreader = NULL;
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
		osrlreader = NULL;
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
		osrlreader = NULL;
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
		osrlreader = NULL;
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
		osrlreader = NULL;
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
		osrlreader = NULL;
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
		osrlreader = NULL;
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
	catch(const ErrorClass& eclass){

		cout << endl << endl << endl;
		if(osrlwriter != NULL) delete osrlwriter;
		if(osrlreader != NULL) delete osrlreader;
		// " Problem with the test reading OSrL data";
		unitTestResultFailure << eclass.errormsg << endl;
		unitTestResultFailure << "There was a failure in the test for reading OSrL" << endl;
	}

}       // PARSER_TESTS

	delete fileUtil;
	fileUtil = NULL;
	    
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
			else return OSNAN;
		}
		else return OSNAN;
	}
	else return OSNAN;
}
