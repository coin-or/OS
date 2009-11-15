/* $Id$ */
/** @file osTestCode.cpp
 * 
 * @author  Horand Gassmann, Jun Ma, Kipp Martin, 
 * @version 1.0, 10/05/2005
 * @since   OS1.0
 *
 * \remarks
 * Copyright (C) 2005, Jun Ma, Kipp Martin,
 * Northwestern University, and the University of Chicago.
 * All Rights Reserved.
 * This software is licensed under the Common Public License. 
 * Please see the accompanying LICENSE file in root directory for terms.
 * 
 */ 
 
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


#include<iostream> 
#include <ostream>
#include <sstream>
#include <streambuf>

#include<stdio.h>
 
using std::cout;   
using std::endl;




int main(int argC, char* argV[]){

	// template -- add your code here -- //
	std::cout << "Hello World" << std::endl;
	int nOfTest;
	bool ok;
	nOfTest = 0;
	OSrLReader *osrlreader = NULL;
	OSrLWriter *osrlwriter = NULL;
	ostringstream unitTestResultFailure;
	ostringstream unitTestResult;
/** The first test makes sure that the set() and IsEqual() methods work correctly.
 *  Two OSResult objects are built one element and attribute at a time.
 *  After every call to the appropriate set() method the two objects are compared:
 *  After the first object has been modified, the objects should compare NOT equal; 
 *  after the second object has been updated in the same way, the objects should be equal.
 */
	OSResult *osresult1 = new OSResult();
	OSResult *osresult2 = new OSResult();
	//OSResult *osresult3 = new OSResult();
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
		//std::cout << tempOSrL << std::endl;
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
	std::cout << "GAIL IS DELETING RESULT 1" << std::endl;
		if (osresult2  != NULL) delete osresult2;
		if (osresult3  != NULL) delete osresult3;
		//delete osrlreader;

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

	return 0;
}// end main

