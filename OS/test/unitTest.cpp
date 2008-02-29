/** @file unitTest.cpp
 * 
 * \brief This file runs the OS unitTest.
 
 *
 * @author  Robert Fourer,  Jun Ma, Kipp Martin, 
 * @version 1.0, 10/05/2005
 * @since   OS1.0
 *
 * \remarks
 * Copyright (C) 2005, Robert Fourer, Jun Ma, Kipp Martin,
 * Northwestern University, and the University of Chicago.
 * All Rights Reserved.
 * This software is licensed under the Common Public License. 
 * Please see the accompanying LICENSE file in root directory for terms.
 * 
 * 
 * This is the OS unitTest. It currently runs the following tests.
 * 
 * Solvers:
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
 * COIN-Clp tested on parincLinearByRow.osil
 * 
 * COIN-Cbc tested on p0033.osil
 * 
 * Knitro tested on:
 * <ol>
 * <li> rosenbrockmod.osil </li>
 * <li> callBackTest.osil </li>
 * <li> parincQuadratic.osil </li>
 * <li> HS071_NLP </li>
 * </ol>
 * 
 * COIN-SYMPHONY test on p0033.osil
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
 * <li> wayneQuadratic.osil -- the only nonlinear integer problem in unitTest </li>
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
 * We next test the parsers. We test parsing the osil file
 * parincLinear.osil and the osrl file parincLinear.osrl.
 * 
 * Next we test the prefix and postfix routines. For the
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
 * Finally test CppAD. Read in CppADTestLag.osil and make sure gradient
 * and Hessian calculations are working correctly.
 */ 


#include <cppad/cppad.hpp> 
//#include "CoinUtilsConfig.h"
#include "OSCoinSolver.h"
#include "OSConfig.h"
#include "OSmps2osil.h" 
#include "OSResult.h" 
#include "OSiLReader.h"        
#include "OSiLWriter.h" 
#include "OSrLReader.h"          
#include "OSrLWriter.h"      
#include "OSInstance.h"  
#include "OSFileUtil.h"  
#include "OSConfig.h" 

#include "OSDefaultSolver.h"  
#include "OSWSUtil.h" 
#include "OSSolverAgent.h"   
#include "OShL.h"     
#include "OSErrorClass.h"
#include "OSmps2osil.h"   
#include "OSBase64.h"
#include "OSCommonUtil.h"


#include <CoinMpsIO.hpp>
#include <CoinPackedMatrix.hpp>
    
 
#ifdef COIN_HAS_KNITRO    
#include "OSKnitroSolver.h"
#endif 

#include "OSMathUtil.h"

#ifdef COIN_HAS_GLPK
#include <OsiGlpkSolverInterface.hpp>
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

using std::cout;   
using std::endl;
using std::ostringstream; 

int main(int argC, char* argV[])
{
	double getObjVal(std::string osrl);
	//using CppAD::NearEqual;
	bool ok;
	double check;
	
	
	//return 0;
	cout << "START UNIT TEST" << endl;
	// define the classes
	FileUtil *fileUtil = NULL;  
	#ifdef COIN_HAS_ASL
	OSnl2osil *nl2osil = NULL;
	#endif 
	OSmps2osil *mps2osil = NULL;
	DefaultSolver *solver  = NULL;
	OSrLWriter *osrlwriter = NULL;
	OSrLReader *osrlreader = NULL;
	// end classes    
	std::string osilFileName;
	std::string osrlFileName;
	std::string nlFileName; 
	std::string mpsFileName;     
	std::string osil;
	ostringstream unitTestResult;
	ostringstream unitTestResultFailure;
	// get the input files
	 const char dirsep =  CoinFindDirSeparator();
  	// Set directory containing mps data files.
  	std::string dataDir;
    dataDir = dirsep == '/' ? "../data/" : "..\\data\\";
	std::string osol = "<osol></osol>";
	nlFileName =  dataDir  + "amplFiles" + dirsep + "parinc.nl";
	mpsFileName =  dataDir + "mpsFiles" + dirsep + "parinc.mps";
	fileUtil = new FileUtil();
	// 
	unitTestResult << "HERE ARE THE UNIT TEST RESULTS:" << std::endl << std::endl;
	
	//first make sure we can read files
	try{
		osilFileName =  dataDir  + "osilFiles" + dirsep +  "parincLinearByRow.osil";
		//osilFileName =  dataDir  + "osilFiles" + dirsep +  "parincLinear.osil";
		std::cout << "Try to read a sample file" << std::endl;
		std::cout << "The file is: " ;
		std::cout <<  osilFileName << std::endl;
		osil = fileUtil->getFileAsString( osilFileName.c_str() );
		std::cout << "Done reading the test file" << std::endl;
		OSiLReader *osilreader = NULL;
		osilreader = new OSiLReader(); 
		//OSInstance *osinstance = osilreader->readOSiL( osil);
		//osinstance->initForAlgDiff();
		unitTestResult << "Reading files successfully" << std::endl;
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
		//finally the objective function coefficients		
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
		
		
		
		//mpsFileName =  dataDir + "mpsFiles" + dirsep + "testfile2.mps";
		mpsFileName =  dataDir + "mpsFiles" + dirsep + "parinc.mps";
		mps2osil = new OSmps2osil( mpsFileName);
		// create the first in-memory OSInstance
		mps2osil->createOSInstance() ;
		// write the instance to a string
		OSInstance *osinstance1 = mps2osil->osinstance;
		std::string sOSiL = osilwriter.writeOSiL( osinstance1  );
		//cout << sOSiL << endl;
		//fileUtil->writeFileFromString("p0201.osil", sOSiL);
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
		std::cout << "MAXIMUM DIFF INDEX  = " << theIndex << std::endl;
		if(theMax > 0) unitTestResult << "WARNING:  you do not have lossless IO" << std::endl;
		else unitTestResult << "passed lossless IO test" << std::endl;
		delete mps2osil;
		delete osilreader;
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
    	//nl2osil = new OSnl2osil( nlFileName);
		//cout << "All tests completed successfully" <<  endl <<  endl;
	    //return 0;
    
	}
	catch(const ErrorClass& eclass){
		unitTestResultFailure << "Sorry Unit Test Failed Reading a file: "  + eclass.errormsg<< endl; 
		//no point continuing we can't even read a file
		unitTestResultFailure << "Since we can't read files we are terminating"  << endl; 
		cout << unitTestResultFailure.str() << endl << endl;
		cout << "Conclusion: FAILURE" << endl;
		return 1;
	}	
	// solve using using the osil file
	#ifdef COIN_HAS_IPOPT
	IpoptSolver *ipoptSolver  =  NULL;	
	try{
	    ipoptSolver  = new IpoptSolver();
		cout << "create a new IPOPT Solver for OSiL string solution" << endl;
		ok = true;
		OSiLReader *osilreader = NULL;
		osilFileName =  dataDir  + "osilFiles" + dirsep +  "avion2.osil";
		osil = fileUtil->getFileAsString(  osilFileName.c_str() );
		cout << "IPOPT Solver created for OSiL string solution" << endl;
		ipoptSolver->osol = osol;
		osilreader = new OSiLReader(); 
		ipoptSolver->osinstance = osilreader->readOSiL( osil);
		cout << "call the IPOPT Solver" << endl;	
		ipoptSolver->buildSolverInstance();
		ipoptSolver->solve();
		cout << "Here is the IPOPT solver solution for avion2" << endl;
		check = 9.46801e+07;
		//ok &= NearEqual(getObjVal( ipoptSolver->osrl) , check,  1e-10 , 1e-10);
		ok = ( fabs(check - getObjVal( ipoptSolver->osrl) )/(fabs( check) + OS_NEAR_EQUAL) <= OS_NEAR_EQUAL) ? true : false;
		if(ok == false) throw ErrorClass(" Fail unit test with Ipopt on avion2");
		delete osilreader;
		osilreader = NULL;
		delete ipoptSolver;
		ipoptSolver = NULL;
		unitTestResult << "Solved problem avion2.osil with Ipopt" << std::endl;
		// solve another problem
		cout << "create a new IPOPT Solver for OSiL string solution" << endl;
		ipoptSolver  = new IpoptSolver();
		// a problem with all nonlinear terms no linear terms
		osilFileName =  dataDir  + "osilFiles" + dirsep + "HS071_NLPMod.osil";
		osil = fileUtil->getFileAsString( osilFileName.c_str());
		cout << "IPOPT Solver created for OSiL string solution" << endl;
		ipoptSolver->osol = osol;
		osilreader = new OSiLReader(); 
		ipoptSolver->osinstance = osilreader->readOSiL( osil);
		ipoptSolver->buildSolverInstance();
		ipoptSolver->solve();
		cout << "Here is the IPOPT solver solution for HS071_NLP" << endl;
		check = 17.014;
		//ok &= NearEqual(getObjVal( ipoptSolver->osrl) , check,  1e-10 , 1e-10);
		ok = ( fabs(check - getObjVal( ipoptSolver->osrl) )/(fabs( check) + OS_NEAR_EQUAL) <= OS_NEAR_EQUAL) ? true : false;
		if(ok == false) throw ErrorClass(" Fail unit test with Ipopt on HS071_NLP");
		delete osilreader;
		osilreader = NULL;
		unitTestResult << "Solved problem HS071.osil with Ipopt" << std::endl;
		delete ipoptSolver;
		ipoptSolver = NULL;
		cout << "create a new IPOPT Solver for OSiL string solution" << endl;
		ipoptSolver  = new IpoptSolver();
		// solve another problem
		// a problem with both quadratic terms and general nonlinear terms
		osilFileName =  dataDir  + "osilFiles" + dirsep + "rosenbrockmod.osil";
		osil = fileUtil->getFileAsString( osilFileName.c_str());
		cout << "IPOPT Solver created for OSiL string solution" << endl;
		ipoptSolver->osol = osol;
		osilreader = new OSiLReader(); 
		ipoptSolver->osinstance = osilreader->readOSiL( osil);
		cout << "call the IPOPT Solver" << endl;
		ipoptSolver->buildSolverInstance();
		ipoptSolver->solve();
		check = 6.7279;
		//ok &= NearEqual(getObjVal( ipoptSolver->osrl) , check,  1e-10 , 1e-10);
		ok = ( fabs(check - getObjVal( ipoptSolver->osrl) )/(fabs( check) + OS_NEAR_EQUAL) <= OS_NEAR_EQUAL) ? true : false;
		if(ok == false) throw ErrorClass(" Fail unit test with Ipopt on rosenbrock");
		delete osilreader;
		osilreader = NULL;
		unitTestResult << "Solved problem rosenbrockmod.osil with Ipopt" << std::endl;
		delete ipoptSolver;
		ipoptSolver = NULL;
		cout << "create a new IPOPT Solver for OSiL string solution" << endl;
		ipoptSolver  = new IpoptSolver();
		// solve another problem
		// a problem that is a pure quadratic
		osilFileName =  dataDir  + "osilFiles" + dirsep + "parincQuadratic.osil";
		osil = fileUtil->getFileAsString( osilFileName.c_str());
		cout << "IPOPT Solver created for OSiL string solution" << endl;
		ipoptSolver->osol = osol;
		osilreader = new OSiLReader(); 
		ipoptSolver->osinstance = osilreader->readOSiL( osil);
		cout << "call the IPOPT Solver" << endl;
		ipoptSolver->buildSolverInstance();
		ipoptSolver->solve();
		cout << "Here is the IPOPT solver solution for parincQuadratic" << endl;
		check = 49920.5;
		//ok &= NearEqual(getObjVal( ipoptSolver->osrl) , check,  1e-10 , 1e-10);
		ok = ( fabs(check - getObjVal( ipoptSolver->osrl) )/(fabs( check) + OS_NEAR_EQUAL) <= OS_NEAR_EQUAL) ? true : false;
		if(ok == false) throw ErrorClass(" Fail unit test with Ipopt on parincQuadradic");
		delete osilreader;
		osilreader = NULL;	
		unitTestResult << "Solved problem parincQuadratic.osil with Ipopt" << std::endl;
		delete ipoptSolver;
		ipoptSolver = NULL;
		cout << "create a new IPOPT Solver for OSiL string solution" << endl;
		ipoptSolver  = new IpoptSolver();
		// solve another problem
		// try a pure linear program
		osilFileName =  dataDir  + "osilFiles" + dirsep + "parincLinear.osil";
		osil = fileUtil->getFileAsString( osilFileName.c_str());
		cout << "IPOPT Solver created for OSiL string solution" << endl;
		ipoptSolver->osol = osol; 
		osilreader = new OSiLReader(); 
		ipoptSolver->osinstance = osilreader->readOSiL( osil);
		cout << "call the IPOPT Solver" << endl;
		ipoptSolver->buildSolverInstance();
		ipoptSolver->solve();
		cout << "Here is the IPOPT solver solution for parincLinear" << endl;
		check = 7668;
		//ok &= NearEqual(getObjVal( ipoptSolver->osrl) , check,  1e-1 , 1e-1);
		ok = ( fabs(check - getObjVal( ipoptSolver->osrl) )/(fabs( check) + OS_NEAR_EQUAL) <= OS_NEAR_EQUAL) ? true : false;
		if(ok == false) throw ErrorClass(" Fail unit test with Ipopt on parincLinear");
		delete osilreader;
		osilreader = NULL;	
		unitTestResult << "Solved problem parincLinear.osil with Ipopt" << std::endl;
		delete ipoptSolver;
		ipoptSolver = NULL;
		cout << "create a new IPOPT Solver for OSiL string solution" << endl;
		ipoptSolver  = new IpoptSolver();
		// solve another problem
		// callBackTest.osil
		osilFileName =  dataDir  + "osilFiles" + dirsep + "callBackTest.osil";
		osil = fileUtil->getFileAsString( osilFileName.c_str());
		cout << "IPOPT Solver created for OSiL string solution" << endl;
		ipoptSolver->osol = osol;
		osilreader = new OSiLReader(); 
		ipoptSolver->osinstance = osilreader->readOSiL( osil);
		//OSiLWriter osilwriter;
		//cout << osilwriter.writeOSiL( ipoptSolver->osinstance) << endl;
		//return 0;
		cout << "call the IPOPT Solver" << endl;
		ipoptSolver->buildSolverInstance();
		ipoptSolver->solve();
		cout << "Here is the IPOPT solver solution for callBackTest" << endl;
		check = 1.00045e+06;
		//ok &= NearEqual(getObjVal( ipoptSolver->osrl) , check,  1e-10 , 1e-10);
		ok = ( fabs(check - getObjVal( ipoptSolver->osrl) )/(fabs( check) + OS_NEAR_EQUAL) <= OS_NEAR_EQUAL) ? true : false;
		if(ok == false) throw ErrorClass(" Fail unit test with Ipopt on parincLinear");
		delete osilreader;
		osilreader = NULL;	
		unitTestResult << "Solved problem callBack.osil with Ipopt" << std::endl;	
		delete ipoptSolver;
		ipoptSolver = NULL;
		cout << "create a new IPOPT Solver for OSiL string solution" << endl;
		ipoptSolver  = new IpoptSolver();
		// solve another problem
		// callBackTest.osil
		osilFileName =  dataDir  + "osilFiles" + dirsep + "callBackTestRowMajor.osil";
		osil = fileUtil->getFileAsString( osilFileName.c_str());
		cout << "IPOPT Solver created for OSiL string solution" << endl;
		ipoptSolver->osol = osol;
		osilreader = new OSiLReader(); 
		ipoptSolver->osinstance = osilreader->readOSiL( osil);
		//OSiLWriter osilwriter;
		//cout << osilwriter.writeOSiL( ipoptSolver->osinstance) << endl;
		//return 0;
		cout << "call the IPOPT Solver" << endl;
		ipoptSolver->buildSolverInstance();
		ipoptSolver->solve();
		cout << "Here is the IPOPT solver solution for callBackTestRowMajor" << endl;
		check = 1.00045e+06;
		//ok &= NearEqual(getObjVal( ipoptSolver->osrl) , check,  1e-10 , 1e-10);
		ok = ( fabs(check - getObjVal( ipoptSolver->osrl) )/(fabs( check) + OS_NEAR_EQUAL) <= OS_NEAR_EQUAL) ? true : false;
		if(ok == false) throw ErrorClass(" Fail unit test with Ipopt on parincLinear");
		delete osilreader;
		osilreader = NULL;	
		delete ipoptSolver;
		ipoptSolver = NULL;	
		unitTestResult << "Solved problem callBackRowMajor.osil with Ipopt" << std::endl;
	}
	catch(const ErrorClass& eclass){
		unitTestResultFailure << "Sorry Unit Test Failed Testing the Ipopt Solver:"  + eclass.errormsg<< endl; 
	}
	#endif
	try{
		ok = true; 
		std::cout << "create a new COIN Clp for OSiL string solution" << std::endl;
		osilFileName = dataDir  + "osilFiles" + dirsep + "parincLinearByRow.osil";
		osil = fileUtil->getFileAsString( osilFileName.c_str());
		std::cout << "create a new Solver object" << std::endl;
		OSiLReader *osilreader = NULL;
		osilreader = new OSiLReader(); 
		//std::cout <<  osil  << std::endl;
		OSInstance *osinstance = osilreader->readOSiL( osil);
		std::cout << " Done reading the OSiL" << std::endl;
		// now write it again as a string
		OSiLWriter *osilwriter;
		osilwriter = new OSiLWriter();
		osilwriter->m_bWhiteSpace = true;
		std::cout << " Write the OSiL" << std::endl;
		osil = osilwriter->writeOSiL( osinstance) ;
		//std::cout <<  osil  << std::endl;
		std::cout << " Done writing the OSiL" << std::endl;
		solver = new CoinSolver();
		solver->sSolverName = "clp";
		solver->osil = osil;
		solver->osol = osol;  
		solver->osinstance = NULL; 
		cout << "call the COIN - clp Solver for parincLinearbyRow" << endl;
		//solver->buildSolverInstance();
		solver->solve();
		cout << "Here is the COIN clp solver solution for parincLinearByRow" << endl;
		cout << solver->osrl << endl;
		check = 7668;
		ok = ( fabs(check - getObjVal( solver->osrl) )/(fabs( check) + OS_NEAR_EQUAL) <= OS_NEAR_EQUAL) ? true : false;
		//ok &= NearEqual(getObjVal( solver->osrl) , check,  1e-1 , 1e-1);
		if(ok == false) throw ErrorClass(" Fail unit test with clp on parincLinear");
		// parse the osrl file
		osrlreader =  new OSrLReader();
		osrlreader->readOSrL( solver->osrl);
		delete osilreader;
		osilreader = NULL;	
		delete solver;
		solver = NULL;
		delete osilwriter;
		osilwriter = NULL;
		delete osrlreader;
		osrlreader = NULL;
		unitTestResult << "Solved problem parincLinearByRow.osil with Clp" << std::endl;
		// now solve another problem -- try an integer program
		// this problem is also stored in base64 binary
	}
	catch(const ErrorClass& eclass){
		unitTestResultFailure << "Sorry Unit Test Failed Testing Clp Solver:"  + eclass.errormsg<< endl;
	}
	try{
		std::cout << "create a new COIN Cbc for OSiL string solution" << std::endl;
		ok = true;
		osilFileName = dataDir  + "osilFiles" + dirsep + "p0033.osil";
		osil = fileUtil->getFileAsString( osilFileName.c_str());
		solver = new CoinSolver();
		solver->sSolverName ="cbc";
		solver->osil = osil;
		solver->osol = osol;  
		solver->osinstance = NULL; 
		cout << "call the COIN - Cbc Solver for p0033" << endl;
		solver->buildSolverInstance();
		solver->solve();
		cout << "Here is the COIN Cbc solver solution for p0033" << endl;
		//cout << solver->osrl << endl;
		check = 3089;
		//ok &= NearEqual(getObjVal( solver->osrl) , check,  1e-10 , 1e-10);
		ok = ( fabs(check - getObjVal( solver->osrl) )/(fabs( check) + OS_NEAR_EQUAL) <= OS_NEAR_EQUAL) ? true : false;
		if(ok == false) throw ErrorClass(" Fail unit test with Cbc on p0033");
		delete solver;
		solver = NULL;
		unitTestResult << "Solved problem p0033.osil with Cbc" << std::endl;
		// now test p0201.osil
		/*
		ok = true;
		osilFileName = dataDir  + "osilFiles" + dirsep + "p0201.osil";
		osil = fileUtil->getFileAsString( osilFileName.c_str());
		solver = new CoinSolver();
		solver->sSolverName ="cbc";
		solver->osil = osil;
		solver->osol = osol;  
		solver->osinstance = NULL; 
		cout << "call the COIN - Cbc Solver for p0201" << endl;
		solver->solve();
		cout << "Here is the COIN Cbc solver solution for p0201" << endl;
		check = 7615;
		//ok &= NearEqual(getObjVal( solver->osrl) , check,  1e-10 , 1e-10);
		ok = ( fabs(check - getObjVal( solver->osrl) )/(fabs( check) + OS_NEAR_EQUAL) <= OS_NEAR_EQUAL) ? true : false;
		if(ok == false) throw ErrorClass(" Fail unit test with Cbc on p0548");
		delete solver;
		solver = NULL;
		unitTestResult << "Solved problem p0201.osil with Cbc" << std::endl;
		*/
	}
	catch(const ErrorClass& eclass){
		unitTestResultFailure << "Sorry Unit Test Failed Testing Cbc Solver:"  + eclass.errormsg<< endl;
	}
	
	//
	//
	#ifdef COIN_HAS_KNITRO
	try{
		ok = true; 
		osilFileName = dataDir  + "osilFiles" + dirsep + "rosenbrockmod.osil";
		osil = fileUtil->getFileAsString( osilFileName.c_str());
		solver = new KnitroSolver();
		solver->osrl = "";	
		solver->osil = osil;
		solver->osol = osol;
		solver->osinstance = NULL;
		cout << "call the KNITRO Solver" << endl;
		solver->solve();
		cout << "Here is the KNITRO solver solution" << endl;	
		check = 6.7279;
		cout << solver->osrl << endl;
		//ok &= NearEqual(getObjVal( solver->osrl) , check,  1e-10 , 1e-10);
		ok = ( fabs(check - getObjVal( solver->osrl) )/(fabs( check) + OS_NEAR_EQUAL) <= OS_NEAR_EQUAL) ? true : false;
		if(ok == false) throw ErrorClass(" Fail unit test with Knitro on rosenbrockmod");
		delete solver;
		solver = NULL;
		unitTestResult << "Solved problem rosenbrockmod.osil with Knitro" << std::endl;
		//
		// now solve callBackTest.osil
		osilFileName = dataDir  + "osilFiles" + dirsep + "callBackTest.osil";
		osil = fileUtil->getFileAsString( osilFileName.c_str());
		solver = new KnitroSolver();
		solver->osrl = "";		
		solver->osil = osil;		
		solver->osol = osol;
		cout << "call the KNITRO Solver" << endl;
		solver->solve();
		cout << "Here is the KNITRO solver solution" << endl;
		check = 1.00045e+06; 
		cout << solver->osrl << endl;
		//ok &= NearEqual(getObjVal( solver->osrl) , check,  1e-10 , 1e-10);
		ok = ( fabs(check - getObjVal( solver->osrl) )/(fabs( check) + OS_NEAR_EQUAL) <= OS_NEAR_EQUAL) ? true : false;
		if(ok == false) throw ErrorClass(" Fail unit test with Knitro callBackTest.osil");
		delete solver;
		solver = NULL;  
		unitTestResult << "Solved problem callBackTest.osil with Knitro" << std::endl;		
		//
		// now solve a pure quadratic
		osilFileName = dataDir  + "osilFiles" + dirsep + "parincQuadratic.osil";
		osil = fileUtil->getFileAsString( osilFileName.c_str());
		solver = new KnitroSolver();	
		solver->osil = osil;
		solver->osol = osol;
		solver->osinstance = NULL;
		cout << "call the Knitro Solver" << endl;
		solver->solve();
		cout << "Here is the Knitro solver solution" << endl;
		cout << solver->osrl << endl;
		check = 49920.5;
		//ok &= NearEqual(getObjVal( solver->osrl) , check,  1e-10 , 1e-10);
		ok = ( fabs(check - getObjVal( solver->osrl) )/(fabs( check) + OS_NEAR_EQUAL) <= OS_NEAR_EQUAL) ? true : false;
		if(ok == false) throw ErrorClass(" Fail unit test with Knitro on parincQuadratic");
		delete solver;
		solver = NULL;
		unitTestResult << "Solved problem parincQuadratic.osil with Knitro" << std::endl;
		//
		// now solve a HS071_NLP.osil
		osilFileName = dataDir  + "osilFiles" + dirsep + "HS071_NLP.osil";
		osil = fileUtil->getFileAsString( osilFileName.c_str());
		solver = new KnitroSolver();	
		solver->osil = osil;
		solver->osol = osol;
		solver->osinstance = NULL;
		cout << "call the Knitro Solver" << endl;
		solver->solve();		
		cout << "Here is the Knitro solver solution" << endl;
		cout << solver->osrl << endl;
		check = 17.014;
		//ok &= NearEqual(getObjVal( solver->osrl) , check,  1e-10 , 1e-10);
		ok = ( fabs(check - getObjVal( solver->osrl) )/(fabs( check) + OS_NEAR_EQUAL) <= OS_NEAR_EQUAL) ? true : false;
		if(ok == false) throw ErrorClass(" Fail unit test with Knitro on HS071_NLP");
		delete solver;
		solver = NULL;
		unitTestResult << "Solved problem HS071_NLP.osil with Knitro" << std::endl;
	}
	catch(const ErrorClass& eclass){
		cout << "OSrL =  " <<  solver->osrl <<  endl;		
		cout << endl << endl << endl;
		unitTestResultFailure  << "Sorry Unit Test Failed Testing the Knitro Solver: "  + eclass.errormsg << endl;
	}	
	#endif
	//
	//
	
	//
	//
	#ifdef COIN_HAS_SYMPHONY
	try{
		ok = true; 
		osilFileName = dataDir  + "osilFiles" + dirsep + "p0033.osil";
		osil = fileUtil->getFileAsString( osilFileName.c_str());
		solver = new CoinSolver();
		solver->sSolverName = "symphony";
		solver->osil = osil;
		solver->osol = osol;  
		solver->osinstance = NULL; 
		cout << "call the COIN - SYMPHONY Solver for p0033" << endl;
		solver->buildSolverInstance();
		solver->solve();
		cout << "Here is the COIN SYMPHONY solver solution for p0033" << endl;
		cout << solver->osrl << endl;
		check = 3089;
		//ok &= NearEqual(getObjVal( solver->osrl) , check,  1e-10 , 1e-10);
		ok = ( fabs(check - getObjVal( solver->osrl) )/(fabs( check) + OS_NEAR_EQUAL) <= OS_NEAR_EQUAL) ? true : false;
		if(ok == false) throw ErrorClass(" Fail unit test with SYMPHONY on p0033.osil");
		delete solver;
		solver = NULL;
		unitTestResult << "Solved problem p0033.osil with SYMPHONY" << std::endl;
	}
	catch(const ErrorClass& eclass){
		cout << "OSrL =  " <<  solver->osrl <<  endl;
		cout << endl << endl << endl;
		unitTestResultFailure  << "Sorry Unit Test Failed Testing the SYMPHONY Solver:"  + eclass.errormsg << endl;
	}	
	#endif
	//
	//
	//
	//
	#ifdef COIN_HAS_DYLP
	try{
		ok = true; 
		osilFileName = dataDir  + "osilFiles" + dirsep + "parincLinear.osil";
		osil = fileUtil->getFileAsString( osilFileName.c_str());
		solver = new CoinSolver();
		solver->sSolverName = "dylp";
		solver->osil = osil;
		solver->osol = osol;   
		solver->osinstance = NULL; 
		cout << "call the COIN - DyLP solver for parincLinear" << endl;
		solver->buildSolverInstance();
		solver->solve();
		cout << "Here is the COIN - DyLP solver solution for parincLinear" << endl;
		cout << solver->osrl << endl;
		check = 7668;
		//ok &= NearEqual(getObjVal( solver->osrl) , check,  1e-1 , 1e-1);
		ok = ( fabs(check - getObjVal( solver->osrl) )/(fabs( check) + OS_NEAR_EQUAL) <= OS_NEAR_EQUAL) ? true : false;
		if(ok == false) throw ErrorClass(" Fail unit test with DyLP on parincLinear.osil");
		delete solver;
		solver = NULL;
		unitTestResult << "Solved problem parincLinear.osil with DyLP" << std::endl;
	}
	catch(const ErrorClass& eclass){
		cout << "OSrL =  " <<  solver->osrl <<  endl;
		cout << endl << endl << endl;
		unitTestResultFailure  <<"Sorry Unit Test Failed Testing the DyLP Solver:"  + eclass.errormsg << endl;
	}	
	#endif
	//
	//
	//
	
	#ifdef COIN_HAS_VOL
	try{
		ok = true; 
		osilFileName = dataDir  + "osilFiles" + dirsep + "volumeTest.osil";
		osil = fileUtil->getFileAsString( osilFileName.c_str());
		solver = new CoinSolver();
		solver->sSolverName = "vol";
		solver->osil = osil;
		solver->osol = osol;  
		solver->osinstance = NULL; 
		cout << "call the COIN - Vol solver for parincLinear" << endl;
		solver->buildSolverInstance();
		solver->solve();
		cout << "Here is the COIN - Vol solver solution for parincLinear" << endl;
		cout << solver->osrl << endl;
		check = 7;
		//ok &= NearEqual(getObjVal( solver->osrl) , check,  1e-1 , 1e-1);
		ok = ( fabs(check - getObjVal( solver->osrl) )/(fabs( check) + OS_NEAR_EQUAL) <= OS_NEAR_EQUAL) ? true : false;
		if(ok == false) throw ErrorClass(" Fail unit test with Vol on volumeTest.osil");
		delete solver;
		solver = NULL;
		unitTestResult << "Solved problem volumeTest.osil with Vol" << std::endl;
	}
	catch(const ErrorClass& eclass){
		cout << "OSrL =  " <<  solver->osrl <<  endl;
		cout << endl << endl << endl;
		unitTestResultFailure  <<"Sorry Unit Test Failed Testing the Vol Solver:"  + eclass.errormsg << endl;
	}	
	#endif
	//
	//
	//
	//
	#ifdef COIN_HAS_GLPK
	try{
		ok = true; 
		osilFileName = dataDir  + "osilFiles" + dirsep + "p0033.osil";
		osil = fileUtil->getFileAsString( osilFileName.c_str());
		solver = new CoinSolver();
		solver->sSolverName = "glpk";
		solver->osil = osil;
		solver->osol = osol;  
		solver->osinstance = NULL; 
		cout << "call the GLPK Solver for p0033" << endl;
		solver->buildSolverInstance();
		solver->solve();
		cout << "Here is the GLPK solver solution for p0033" << endl;
		cout << solver->osrl << endl;
		check = 3089;
		//ok &= NearEqual(getObjVal( solver->osrl) , check,  1e-10 , 1e-10);
		ok = ( fabs(check - getObjVal( solver->osrl) )/(fabs( check) + OS_NEAR_EQUAL) <= OS_NEAR_EQUAL) ? true : false;
		if(ok == false) throw ErrorClass(" Fail unit test with GLPK on p0033.osil");
		delete solver;
		solver = NULL;
		unitTestResult << "Solved problem p0033.osil with GLPK" << std::endl;
	}
	catch(const ErrorClass& eclass){
		cout << "OSrL =  " <<  solver->osrl <<  endl;
		cout << endl << endl << endl;
		unitTestResultFailure  <<"Sorry Unit Test Failed Testing the Glpk Solver:"  + eclass.errormsg << endl;
	}	
	#endif
	//
	//
	//
	#ifdef COIN_HAS_CPX
	try{
		ok = true; 
		osilFileName = dataDir  + "osilFiles" + dirsep + "p0033.osil";
		osil = fileUtil->getFileAsString( osilFileName.c_str());
		solver = new CoinSolver();
		solver->sSolverName = "cplex";
		solver->osil = osil;
		solver->osol = osol;  
		solver->osinstance = NULL; 
		cout << "call the CPLEX Solver for p0033" << endl;
		solver->buildSolverInstance();
		solver->solve();
		cout << "Here is the CPLEX solver solution for p0033" << endl;
		cout << solver->osrl << endl;
		check = 3089;
		//ok &= NearEqual(getObjVal( solver->osrl) , check,  1e-10 , 1e-10);
		ok = ( fabs(check - getObjVal( solver->osrl) )/(fabs( check) + OS_NEAR_EQUAL) <= OS_NEAR_EQUAL) ? true : false;
		if(ok == false) throw ErrorClass(" Fail unit test with CPLEX on p0033.osil");
		delete solver;
		solver = NULL;
		unitTestResult << "Solved problem p0033.osil with CPLEX" << std::endl;
	}
	catch(const ErrorClass& eclass){
		cout << "OSrL =  " <<  solver->osrl <<  endl;
		cout << endl << endl << endl;
		unitTestResultFailure  <<"Sorry Unit Test Failed Testing the Cplex Solver:"  + eclass.errormsg << endl;
	}	
	#endif
	
	//
	#ifdef COIN_HAS_LINDO
	try{
		ok = true;
		osilFileName = dataDir  + "osilFiles" + dirsep + "lindoapiaddins.osil";
		osil = fileUtil->getFileAsString( osilFileName.c_str());
		cout << "create a new LINDO Solver for OSiL string solution" << endl;
		solver = new LindoSolver();	
		solver->osil = osil;
		solver->osol = osol;
		solver->osinstance = NULL;
		cout << "call the LINDO Solver" << endl;
		solver->buildSolverInstance();
		solver->solve();
		cout << "Here is the LINDO solver solution" << endl;
		cout << solver->osrl << endl;
		check = 99;
		//ok &= NearEqual(getObjVal( solver->osrl) , check,  1e-10 , 1e-10);
		ok = ( fabs(check - getObjVal( solver->osrl) )/(fabs( check) + OS_NEAR_EQUAL) <= OS_NEAR_EQUAL) ? true : false;
		if(ok == false) throw ErrorClass(" Fail unit test with LINDO on lindoapiaddins");
		solver->osinstance = NULL;
		delete solver;
		solver = NULL;
		unitTestResult << "Solved problem lindoapiaddins.osil with Lindo" << std::endl;
		// now solve the rosenbrock problem from the OSiL paper
		osilFileName = dataDir  + "osilFiles" + dirsep + "rosenbrockmod.osil";
		osil = fileUtil->getFileAsString( osilFileName.c_str());
		solver = new LindoSolver();	
		solver->osil = osil;
		solver->osol = osol;
		solver->osinstance = NULL;
		cout << "call the LINDO Solver" << endl;
		solver->buildSolverInstance();
		solver->solve();
		cout << "Here is the LINDO solver solution" << endl;
		cout << solver->osrl << endl;
		check = 6.7279;
		//ok &= NearEqual(getObjVal( solver->osrl) , check,  1e-10 , 1e-10);
		ok = ( fabs(check - getObjVal( solver->osrl) )/(fabs( check) + OS_NEAR_EQUAL) <= OS_NEAR_EQUAL) ? true : false;
		if(ok == false) throw ErrorClass(" Fail unit test with LINDO on rosenbrockmod");
		solver->osinstance = NULL;
		delete solver;
		solver = NULL;
		unitTestResult << "Solved problem rosenbrockmod.osil with Lindo" << std::endl;
		// now solve a pure quadratic
		osilFileName = dataDir  + "osilFiles" + dirsep + "parincQuadratic.osil";
		osil = fileUtil->getFileAsString( osilFileName.c_str());
		solver = new LindoSolver();	
		solver->osil = osil;
		solver->osol = osol;
		solver->osinstance = NULL;
		cout << "call the LINDO Solver" << endl;
		solver->buildSolverInstance();
		solver->solve();
		cout << "Here is the LINDO solver solution" << endl;
		cout << solver->osrl << endl;
		check = 49920.5;
		//ok &= NearEqual(getObjVal( solver->osrl) , check,  1e-10 , 1e-10);
		ok = ( fabs(check - getObjVal( solver->osrl) )/(fabs( check) + OS_NEAR_EQUAL) <= OS_NEAR_EQUAL) ? true : false;
		if(ok == false) throw ErrorClass(" Fail unit test with LINDO on parincQuadratic");
		delete solver;
		solver = NULL;
		unitTestResult << "Solved problem parincQuadratic.osil with Lindo" << std::endl;
		// now solve a quadratic binary problem
		// wayneQuadratic.osil
		/*
		osilFileName = dataDir  + "osilFiles" + dirsep + "wayneQuadratic.osil";
		osil = fileUtil->getFileAsString( osilFileName.c_str());
		solver = new LindoSolver();	
		solver->osil = osil;
		solver->osol = osol;
		solver->osinstance = NULL;
		cout << "call the LINDO Solver" << endl;
		solver->buildSolverInstance();
		solver->solve();
		cout << "Here is the LINDO solver solution" << endl;
		cout << solver->osrl << endl;
		check = 2.925;
		std::cout << "CALL NEAR_EQUSL" << std::endl;
		//ok &= NearEqual(getObjVal( solver->osrl) , check,  1e-10 , 1e-10);
		ok = ( fabs(check - getObjVal( solver->osrl) )/(fabs( check) + OS_NEAR_EQUAL) <= OS_NEAR_EQUAL) ? true : false;
		std::cout << "CALL NEAR_EQUSL" << std::endl;
		if(ok == false) throw ErrorClass(" Fail unit test with LINDO on wayneQuadratic");
		delete solver;
		solver = NULL;
		unitTestResult << "Solved problem wayneQuadratic.osil with Lindo" << std::endl;
		*/
		
	}
	catch(const ErrorClass& eclass){
		//cout << "OSrL =  " <<  solver->osrl <<  endl;
		cout << endl << endl << endl;
		unitTestResultFailure  <<"Sorry Unit Test Failed Testing the LINDO Solver:"  + eclass.errormsg << endl << endl;
	}
	#endif
	// end solving using the osil file
	// now solve with an OSInstance created from an MPS file
	try{
		ok = true;
		cout << endl;
		cout << "START MPS TESTING" << endl << endl;
		cout << "create a COIN Solver for MPS - OSInstance solution" << endl;
		solver = new CoinSolver();
		solver->sSolverName = "cbc";
		mps2osil = new OSmps2osil( mpsFileName);
		mps2osil->createOSInstance() ;
		solver->osinstance = mps2osil->osinstance;
		solver->osol = osol;
		cout << "call COIN Solve" << endl;
		solver->buildSolverInstance();
		solver->solve();
		cout << "Here is the COIN solver solution" << endl;
		cout << solver->osrl << endl;
		check = -7668;
		//ok &= NearEqual(getObjVal( solver->osrl) , check,  1e-1 , 1e-1);
		ok = ( fabs(check - getObjVal( solver->osrl) )/(fabs( check) + OS_NEAR_EQUAL) <= OS_NEAR_EQUAL) ? true : false;
		if(ok == false) throw ErrorClass(" Fail unit test with COIN Solver on MPS test problem parincLinear.mps");
		delete solver;
		solver = NULL;
		delete mps2osil; 
		mps2osil = NULL;
		cout << endl;
		cout << "DONE WITH MPS TESTING" << endl;
		unitTestResult << "Test the MPS -> OSiL converter on parinc.mps using Cbc" << std::endl;
	}
	catch(const ErrorClass& eclass){
		cout << "OSrL =  " <<  solver->osrl <<  endl;
		cout << endl << endl << endl;
		unitTestResultFailure  <<"Sorry Unit Test Failed Testing the MPS converter:"  + eclass.errormsg << endl;
	}
	// now solve with an OSInstance created from an AMPL nl file
	try{
		ok = true;
		cout << endl;
		cout << "START AMPL TESTING" << endl << endl;
#ifdef COIN_HAS_ASL
		cout << "create a cbc Solver for AMPL nl - OSInstance solution" << endl;
		solver = new CoinSolver();
		solver->sSolverName = "cbc";
		nl2osil = new OSnl2osil( nlFileName); 
		nl2osil->createOSInstance() ;
		solver->osinstance = nl2osil->osinstance;	
		solver->osol = osol;
		cout << "call Cbc Solve" << endl;
		solver->buildSolverInstance();
		solver->solve();
		cout << "Here is the Cbc solver solution" << endl;
		cout << solver->osrl << endl;
		check = 7668;
		//ok &= NearEqual(getObjVal( solver->osrl) , check,  1e-1 , 1e-1);
		ok = ( fabs(check - getObjVal( solver->osrl) )/(fabs( check) + OS_NEAR_EQUAL) <= OS_NEAR_EQUAL) ? true : false;
		if(ok == false) throw ErrorClass(" Fail unit test with OSnl2osil on problem parinc.nl");
		solver->osinstance = NULL;
		delete solver;
		solver = NULL;
		cout << "call delete nl2osil" << endl;
		delete nl2osil;
		nl2osil = NULL;	
		unitTestResult << "Test the AMPL nl -> OSiL converter on parinc.nl using Cbc" << std::endl; 
#endif
		cout << "END AMPL TESTING" << endl << endl;
	}	
		catch(const ErrorClass& eclass){
		cout << "OSrL =  " <<  solver->osrl <<  endl;
		cout << endl << endl << endl;
		unitTestResultFailure  <<"Sorry Unit Test Failed Testing AMPL:"  + eclass.errormsg << endl;
	}
	//
	// Now test the b64 feature
	//
	try{
		ok = true;
		cout << endl;
		cout << endl;
		cout << "TESTING BASE 64 WITH A COIN SOLVER"<< endl;
		cout << endl;
		OSiLWriter osilwriter;
		osilwriter.m_bWriteBase64 = true;
		solver = new CoinSolver();
		solver->sSolverName = "cbc";
		mps2osil = new OSmps2osil( mpsFileName);
		solver->osinstance = NULL;
		solver->osol = osol;
		mps2osil->createOSInstance() ;
		solver->osil = osilwriter.writeOSiL( mps2osil->osinstance) ;
		std::cout << solver->osil << std::endl;
		solver->buildSolverInstance();
		solver->solve();
		cout << endl << endl;
		cout << "COIN solution of a OSiL string in b64 format" << endl;
		cout << solver->osrl;
		check = -7668;
		//ok &= NearEqual(getObjVal( solver->osrl) , check,  1e-1 , 1e-1);
		ok = ( fabs(check - getObjVal( solver->osrl) )/(fabs( check) + OS_NEAR_EQUAL) <= OS_NEAR_EQUAL) ? true : false;
		if(ok == false) throw ErrorClass(" Fail unit test with COIN Cbc cSolver on b64 test problem parincLinear.mps");
		solver->osinstance = NULL;
		delete solver;
		solver = NULL;
		delete mps2osil;
		mps2osil = NULL;
		unitTestResult << "Test a problem written in b64 and then converted to OSInstance" << std::endl;
	}	
	catch(const ErrorClass& eclass){
		cout << endl << endl;
		cout << eclass.errormsg <<  endl << endl;
		cout << "OSrL =  " <<  solver->osrl <<  endl;
		cout << endl << endl << endl;
		unitTestResultFailure   << "Sorry Unit Test Failed Testing Use of Base 64" << endl;

	}  
	//
	// Now just test the OSiL parser
	try{ 
		cout << endl;
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
		unitTestResult << "Successful test of OSiL parser on problem parincLinear.osil" << std::endl;

	}	
		catch(const ErrorClass& eclass){
		cout << endl << endl << endl;
		cout << eclass.errormsg << endl;
		unitTestResultFailure << "Sorry Unit Test Failed Testing An OSiL Parser" << endl;
		
	}	
	
	//
	// Now just test the OSrL parser
	try{ 
		cout << endl;
		clock_t start, finish;
		double duration;
		osrlwriter = new OSrLWriter();
		osrlreader = new OSrLReader();
		OSResult *osresult = NULL;
		//osresult = new OSResult(); 
		cout << "TEST PARSING AN OSrL FILE" << endl;
		cout << "FIRST READ THE OSrL FILE INTO A STRING" << endl;
		osrlFileName = dataDir  + "osrlFiles" + dirsep + "parincLinear.osrl"; 
		start = clock();
		std::string osrl = fileUtil->getFileAsString( osrlFileName.c_str() );
		finish = clock();
		duration = (double) (finish - start) / CLOCKS_PER_SEC;
		cout << "Reading the file into a string took (seconds): "<< duration << endl;
		start = clock();
		cout << "PARSE THE OSRL STRING INTO AN OSRESULT OBJECT" << endl;
		osresult = osrlreader->readOSrL( osrl);
		cout << osrlwriter->writeOSrL( osresult) << endl;
		delete osrlwriter;
		osrlwriter = NULL;
		delete osrlreader;
		osrlreader = NULL;
		finish = clock();
		duration = (double) (finish - start) / CLOCKS_PER_SEC;
		cout << "Parsing took (seconds): "<< duration << endl;
		unitTestResult << "Successful test of OSrL parser on problem parincLinear.osrl" << std::endl;

	}	
		catch(const ErrorClass& eclass){
		cout << endl << endl << endl;
		if(osrlwriter != NULL) delete osrlwriter;
		if(osrlreader != NULL) delete osrlreader;
		// " Problem with the test reading OSrL data";
		unitTestResultFailure << eclass.errormsg << endl;
		unitTestResultFailure << "There was a failure in the test for reading OSrL" << endl;
	}
	// now test postfix and prefix routines
	try{
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
		unitTestResult << "Successful test of prefix and postfix conversion routines on problem rosenbrockmod.osil" << std::endl;
		
	}
	catch(const ErrorClass& eclass){
		cout << endl << endl << endl;
		unitTestResultFailure << eclass.errormsg << endl;
	}
	// now test the nonlinear operators	
	try{
		ok = true;
		std::cout << "Test nonlinear operators" << std::endl;
		std::string operatorTest =  dataDir  + "osilFiles" + dirsep + "testOperators.osil";
		osil = fileUtil->getFileAsString( operatorTest.c_str() );
		OSInstance *osinstance = NULL;
		//osinstance = new OSInstance();
		OSiLReader *osilreader = NULL;
		osilreader = new OSiLReader();
		OSiLWriter *osilwriter = NULL;
		osilwriter = new OSiLWriter();
		osinstance = osilreader->readOSiL( osil);
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
		unitTestResult << "Successful test of all of the nonlinear operators on file testOperators.osil" << std::endl;
	}
	catch(const ErrorClass& eclass){
		cout << endl << endl << endl;
		unitTestResultFailure << eclass.errormsg << endl;
	}
	// 
	// now solve on a remote server
	/*
	try{
		//return 0;
		OSSolverAgent* osagent = NULL;
		//osagent = new OSSolverAgent("128.135.130.17/axis/OSSolverService");
		//osagent = new OSSolverAgent("gsbkip.chicagogsb.edu:80/os/ossolver/COINSolverService.jws");
		//osagent = new OSSolverAgent("localhost/os/ossolver/COINSolverService.jws");
		//osagent = new OSSolverAgent("localhost/axis/OSSolverService");
		osagent = new OSSolverAgent("http://127.0.0.1:8080/os/ossolver/CoinSolverService.jws");
		//osagent = new OSSolverAgent("128.135.130.17:8080/os/ossolver/CoinSolverService.jws");
		//osagent = new OSSolverAgent("127.0.0.1:8080/web-services-examples/ted/VrptsSolverService.jws");
		cout << "Place remote synchronous call" << endl;
		nl2osil = new OSnl2osil( nlFileName);
		nl2osil->createOSInstance() ;
		OSiLWriter *osilwriter = NULL;
		osilwriter = new OSiLWriter();
		osil = osilwriter->writeOSiL( nl2osil->osinstance) ;
		string osrl = osagent->solve(osil, osol);
		cout << "READ THE OSrL and WRITE IT AGAIN" << endl;
		cout << osrl  << endl;
		OSrLReader *osrlreader = NULL;
		OSResult *osresult = NULL;
		osrlreader = new OSrLReader();
		osresult = osrlreader->readOSrL( osrl);
		OSrLWriter *osrlwriter;
		if(osresult != NULL){
			osrlwriter = new OSrLWriter();
			osrl = osrlwriter->writeOSrL( osresult);
		}
		cout << osrl << endl;
		//
		delete nl2osil;
		nl2osil = NULL;
		delete osilwriter;
		osilwriter = NULL;
	}	
		catch(const ErrorClass& eclass){
		cout <<  eclass.errormsg <<  endl;
	}	
	*/
	try{
		std::cout << std::endl << std::endl;
		std::cout << "Testing AD Features " << std::endl;
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
		int i;
		for(i = 0; i < sp->number; i++){
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
		for(i = 0; i < sh->hessDimension; i++){
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
		unitTestResult << "Successful test of AD gradient and Hessian calculations on problem CppADTestLag.osil" << std::endl;
		delete[] x;
		delete osilreader;
		osilreader = NULL;
	}	
	catch(const ErrorClass& eclass){
		cout << endl << endl << endl;
		unitTestResultFailure << eclass.errormsg << endl;
	}
	delete fileUtil;
	fileUtil = NULL;
	    
	if(unitTestResultFailure.str().length() > 0){
		cout << "The unitTest passed the following" << endl << endl;
		cout << unitTestResult.str() << endl << endl;
		cout << "Unfortunately, you failed on the following:" << endl << endl;
		cout << unitTestResultFailure.str() << endl << endl;
		cout << "Conclusion: FAILURE" << endl;
		return 1;
	}
	else{
		cout << "The unitTest passed the following" << endl << endl;
		cout << unitTestResult.str() << endl << endl;
		cout << "All tests completed successfully" <<  endl <<  endl;
		return 0;
	}
}//ennd main

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

				return dObjVal = os_strtod( sObjVal.c_str(), NULL); 
			}
			else return OSNAN;
		}
		else return OSNAN;
	}
	else return OSNAN;
}
