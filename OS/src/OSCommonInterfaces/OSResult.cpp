/* $Id$ */
/** @file OSResult.cpp
 *
 *
 * @author  Horand Gassmann, Jun Ma, Kipp Martin
 *
 * \remarks
 * Copyright (C) 2005-2012, Horand Gassmann, Jun Ma, Kipp Martin,
 * Dalhousie University, Northwestern University, and the University of Chicago.
 * All Rights Reserved.
 * This software is licensed under the Eclipse Public License.
 * Please see the accompanying LICENSE file in root directory for terms.
 *
 */

#include "OSResult.h"
#include "OSParameters.h"
#include "OSErrorClass.h"
#include "OSGeneral.h"
#include "OSParameters.h"
#include "OSMathUtil.h"
#include "OSOutput.h"

#include<iostream>
#include<sstream>

using namespace std;

/**
 * ======== Constructor and destructor functions ========
 * (in the same order in which they appear in OSResult.h)
 */

GeneralSubstatus::GeneralSubstatus():
    name( ""),
    description( "")
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSResult, ENUM_OUTPUT_LEVEL_trace, "Inside the GeneralSubstatus Constructor");
#endif
}// end GeneralSubstatus constructor

GeneralSubstatus::~GeneralSubstatus()
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSResult, ENUM_OUTPUT_LEVEL_trace, "Inside the GeneralSubstatus Destructor");
#endif
}//end GeneralSubstatus destructor


GeneralStatus::GeneralStatus():
    numberOfSubstatuses (0),
    type( ""),
    description( ""),
    substatus (NULL)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSResult, ENUM_OUTPUT_LEVEL_trace, "Inside the GeneralStatus Constructor");
#endif
}// end GeneralStatus constructor

GeneralStatus::~GeneralStatus()
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSResult, ENUM_OUTPUT_LEVEL_trace, "Inside the GeneralStatus Destructor");
#endif
    if (substatus != NULL)
    {
        for (int i = 0; i < numberOfSubstatuses; i++)
        {
            delete substatus[i];
            substatus[i] = NULL;
        }
        delete[] substatus;
        substatus = NULL;
    }
}//end GeneralStatus destructor

#if 0
OtherResult::OtherResult():
    name( ""),
    value( ""),
    description( "")
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSResult, ENUM_OUTPUT_LEVEL_trace, "Inside the OtherResult Constructor");
#endif
}// end OtherResult constructor


OtherResult::~OtherResult()
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSResult, ENUM_OUTPUT_LEVEL_trace, "Inside the OtherResult Destructor");
#endif
}// end OtherResult destructor
#endif

OtherResults::OtherResults():
    numberOfOtherResults( 0),
    other( NULL)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSResult, ENUM_OUTPUT_LEVEL_trace, "Inside the OtherResults Constructor");
#endif
}// end OtherResults constructor

OtherResults::~OtherResults()
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSResult, ENUM_OUTPUT_LEVEL_trace, "Inside the OtherResults Destructor");
#endif
    if (other != NULL)
    {
        for (int i = 0; i < numberOfOtherResults; i++)
        {
            delete other[i];
            other[i] = NULL;
        }
        delete[] other;
        other = NULL;
    }
}// end OtherResults destructor


GeneralResult::GeneralResult():
    generalStatus(NULL),
    message(""),
    serviceURI(""),
    serviceName(""),
    instanceName(""),
    jobID(""),
    solverInvoked(""),
    timeStamp(""),
    otherResults(NULL)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSResult, ENUM_OUTPUT_LEVEL_trace, "Inside the GeneralResult Constructor");
#endif
}//end GeneralResult constructor


GeneralResult::~GeneralResult()
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSResult, ENUM_OUTPUT_LEVEL_trace, "Inside the GeneralResult Destructor");
#endif
    if (generalStatus != NULL)
    {
        delete generalStatus;
        generalStatus = NULL;
    }
    if (otherResults != NULL)
    {
        delete otherResults;
        otherResults = NULL;
    }
}// end GeneralResult destructor

SystemResult::SystemResult():
    systemInformation(""),
    availableDiskSpace(NULL),
    availableMemory(NULL),
    availableCPUSpeed(NULL),
    availableCPUNumber(NULL),
    otherResults(NULL)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSResult, ENUM_OUTPUT_LEVEL_trace, "Inside the SystemResult Constructor");
#endif
}//end SystemResult constructor


SystemResult::~SystemResult()
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSResult, ENUM_OUTPUT_LEVEL_trace, "Inside the SystemResult Destructor");
#endif
    if (availableDiskSpace != NULL)
    {
        delete availableDiskSpace;
        availableDiskSpace = NULL;
    }
    if (availableMemory != NULL)
    {
        delete availableMemory;
        availableMemory = NULL;
    }
    if (availableCPUSpeed != NULL)
    {
        delete availableCPUSpeed;
        availableCPUSpeed = NULL;
    }
    if (availableCPUNumber != NULL)
    {
        delete availableCPUNumber;
        availableCPUNumber = NULL;
    }
    if (otherResults != NULL)
    {
        delete otherResults;
        otherResults = NULL;
    }
}// end SystemResult destructor


ServiceResult::ServiceResult():
    currentState("unknown"),
    currentJobCount(-1),
    totalJobsSoFar(-1),
    timeServiceStarted("1970-01-01T00:00:00-00:00"),
    serviceUtilization(-1.0),
    otherResults(NULL)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSResult, ENUM_OUTPUT_LEVEL_trace, "Inside the ServiceResult Constructor");
#endif
}//end ServiceResult constructor


ServiceResult::~ServiceResult()
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSResult, ENUM_OUTPUT_LEVEL_trace, "Inside the ServiceResult Destructor");
#endif
    if (otherResults != NULL)
    {
        delete otherResults;
        otherResults = NULL;
    }
}// end ServiceResult destructor

#if 0
Time::Time():
    type("elapsedTime"),
    category("total"),
    unit("second"),
    description(""),
    value(0.0)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSResult, ENUM_OUTPUT_LEVEL_trace, "Inside the Time Constructor");
#endif
}//end Time constructor


Time::~Time()
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSResult, ENUM_OUTPUT_LEVEL_trace, "Inside the Time Destructor");
#endif

}// end Time destructor
#endif

TimeMeasurement::TimeMeasurement():
    TimeSpan(),
    type("elapsedTime"),
    category("total"),
    description("")
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSResult, ENUM_OUTPUT_LEVEL_trace, "Inside the TimeMeasurement Constructor");
#endif
}//end TimeMeasurement constructor


TimeMeasurement::~TimeMeasurement()
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSResult, ENUM_OUTPUT_LEVEL_trace, "Inside the TimeMeasurement Destructor");
#endif

}// end TimeMeasurement destructor

TimingInformation::TimingInformation():
    numberOfTimes(0),
    time(NULL)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSResult, ENUM_OUTPUT_LEVEL_trace, "Inside the TimingInformation Constructor");
#endif
}//end TimingInformation constructor


TimingInformation::~TimingInformation()
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSResult, ENUM_OUTPUT_LEVEL_trace, "Inside the TimingInformation Destructor");
#endif
    if (time != NULL)
    {
        for (int i = 0; i < numberOfTimes; i++)
        {
            delete time[i];
            time[i] = NULL;
        }
        delete[] time;
        time = NULL;
    }
}// end TimingInformation destructor

JobResult::JobResult():
    status("finished"),
    submitTime("1970-01-01T00:00:00-00:00"),
    scheduledStartTime("1970-01-01T00:00:00-00:00"),
    actualStartTime("1970-01-01T00:00:00-00:00"),
    endTime("1970-01-01T00:00:00-00:00"),
    timingInformation(NULL),
    usedDiskSpace(NULL),
    usedMemory(NULL),
    usedCPUSpeed(NULL),
    usedCPUNumber(NULL),
    otherResults(NULL)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSResult, ENUM_OUTPUT_LEVEL_trace, "Inside the JobResult Constructor");
#endif
    timingInformation = NULL;
}//end JobResult constructor


JobResult::~JobResult()
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSResult, ENUM_OUTPUT_LEVEL_trace, "Inside the JobResult Destructor");
#endif
    if (timingInformation != NULL)
    {
        delete timingInformation;
        timingInformation = NULL;
    }
    if (usedDiskSpace != NULL)
    {
        delete usedDiskSpace;
        usedDiskSpace = NULL;
    }
    if (usedMemory != NULL)
    {
        delete usedMemory;
        usedMemory = NULL;
    }
    if (usedCPUSpeed != NULL)
    {
        delete usedCPUSpeed;
        usedCPUSpeed = NULL;
    }
    if (usedCPUNumber != NULL)
    {
        delete usedCPUNumber;
        usedCPUNumber = NULL;
    }
    if (otherResults != NULL)
    {
        delete otherResults;
        otherResults = NULL;
    }
}// end JobResult destructor


OptimizationSolutionSubstatus::OptimizationSolutionSubstatus():
    type(""),
    description("")
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSResult, ENUM_OUTPUT_LEVEL_trace, "Inside the OptimizationSolutionSubstatus Constructor");
#endif
}//end OptimizationSolutionSubstatus constructor


OptimizationSolutionSubstatus::~OptimizationSolutionSubstatus()
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSResult, ENUM_OUTPUT_LEVEL_trace, "Inside the OptimizationSolutionSubstatus Destructor");
#endif
}// end OptimizationSolutionSubstatus destructor


OptimizationSolutionStatus::OptimizationSolutionStatus():
    numberOfSubstatuses(0),
    type(""),
    description(""),
    substatus(NULL)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSResult, ENUM_OUTPUT_LEVEL_trace, "Inside the OptimizationSolutionStatus Constructor");
#endif
}//end OptimizationSolutionStatus constructor


OptimizationSolutionStatus::~OptimizationSolutionStatus()
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSResult, ENUM_OUTPUT_LEVEL_trace, "Inside the OptimizationSolutionStatus Destructor");
#endif
    if (substatus != NULL)
    {
        for (int i = 0; i < numberOfSubstatuses; i++)
        {
            delete substatus[i];
            substatus[i] = NULL;
        }
        delete[] substatus;
        substatus = NULL;
    }
}// end OptimizationSolutionStatus destructor


VarValue::VarValue():
    idx( -1),
    name(""),
    value( 0)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSResult, ENUM_OUTPUT_LEVEL_trace, "Inside the VarValue Constructor");
#endif
}//end VarValue constructor


VarValue::~VarValue()
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSResult, ENUM_OUTPUT_LEVEL_trace, "Inside the VarValue Destructor");
#endif
}// end VarValue destructor



VariableValues::VariableValues():
    numberOfVar(0),
    var(NULL)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSResult, ENUM_OUTPUT_LEVEL_trace, "Inside the VariableValues Constructor");
#endif
}//end VariableValues constructor


VariableValues::~VariableValues()
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSResult, ENUM_OUTPUT_LEVEL_trace, "Inside the VariableValues Destructor");
#endif
    if(var != NULL)
    {
        for(int i = 0; i < numberOfVar; i++)
        {
            delete var[i];
            var[i] = NULL;
        }
        delete[] var;
        var = NULL;
    }
}// end VariableValues destructor


VarValueString::VarValueString():
    idx( -1),
    name(""),
    value( "")
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSResult, ENUM_OUTPUT_LEVEL_trace, "Inside the VarValueString Constructor");
#endif
}//end VarValueString constructor


VarValueString::~VarValueString()
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSResult, ENUM_OUTPUT_LEVEL_trace, "Inside the VarValueString Destructor");
#endif
}// end VarValueString destructor



VariableValuesString::VariableValuesString():
    numberOfVar(0),
    var(NULL)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSResult, ENUM_OUTPUT_LEVEL_trace, "Inside the VariableValuesString Constructor");
#endif
}//end VariableValuesString constructor


VariableValuesString::~VariableValuesString()
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSResult, ENUM_OUTPUT_LEVEL_trace, "Inside the VariableValuesString Destructor");
#endif
    if(var != NULL)
    {
        for(int i = 0; i < numberOfVar; i++)
        {
            delete var[i];
            var[i] = NULL;
        }
        delete[] var;
        var = NULL;
    }
}// end VariableValuesString destructor


OtherVarResult::OtherVarResult():
    idx( -1),
    name(""),
    value( "")
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSResult, ENUM_OUTPUT_LEVEL_trace, "Inside the OtherVarResult Constructor");
#endif
}//end OtherVarResult constructor


OtherVarResult::~OtherVarResult()
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSResult, ENUM_OUTPUT_LEVEL_trace, "Inside the OtherVarResult Destructor");
#endif
}// end OtherVarResult destructor



OtherVariableResult::OtherVariableResult():
    numberOfVar(0),
    numberOfEnumerations(0),
    name(""),
    value(""),
    type(""),
    description(""),
    var(NULL),
    varType(""),    
    enumeration(NULL),
    enumType("")
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSResult, ENUM_OUTPUT_LEVEL_trace, "Inside the OtherVariableResult Constructor");
#endif

}//end OtherVariableResult constructor


OtherVariableResult::~OtherVariableResult()
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSResult, ENUM_OUTPUT_LEVEL_trace, "Inside the OtherVariableResult Destructor");
#endif
    if (var != NULL)
    {
        for(int i = 0; i < numberOfVar; i++)
        {
            delete var[i];
            var[i] = NULL;
        }
        delete[] var;
        var = NULL;
    }
    if (enumeration != NULL)
    {
        for(int i = 0; i < numberOfEnumerations; i++)
        {
            delete enumeration[i];
            enumeration[i] = NULL;
        }
        delete[] enumeration;
        enumeration = NULL;
    }
}// end OtherVariableResult destructor


VariableSolution::VariableSolution():
    numberOfOtherVariableResults( 0),
    values( NULL),
    valuesString( NULL),
    basisStatus(NULL),
    other( NULL)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSResult, ENUM_OUTPUT_LEVEL_trace, "Inside the VariableSolution Constructor");
#endif
}//end VariableSolution constructor


VariableSolution::~VariableSolution()
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSResult, ENUM_OUTPUT_LEVEL_trace, "Inside the VariableSolution Destructor");
#endif
    if (values != NULL)
    {
        delete values;
        values = NULL;
    }
    if (valuesString != NULL)
    {
        delete valuesString;
        valuesString = NULL;
    }
    if (basisStatus != NULL)
    {
        delete basisStatus;
        basisStatus = NULL;
    }
    if(numberOfOtherVariableResults > 0 && other != NULL)
    {
        for(int i = 0; i < numberOfOtherVariableResults; i++)
        {
            delete other[i];
            other[i] = NULL;
        }
        delete[] other;
        other = NULL;
    }
}// end VariableSolution destructor



ObjValue::ObjValue():
    idx( -1),
    name(""),
    value(0.0)
//	value( OSNaN())
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSResult, ENUM_OUTPUT_LEVEL_trace, "Inside the ObjValue Constructor");
#endif
}//end ObjValue constructor

ObjValue::~ObjValue()
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSResult, ENUM_OUTPUT_LEVEL_trace, "Inside the ObjValue Destructor");
#endif
}// end ObjValue destructor



ObjectiveValues::ObjectiveValues():
    numberOfObj(0),
    obj(NULL)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSResult, ENUM_OUTPUT_LEVEL_trace, "Inside the ObjectiveValues Constructor");
#endif

}//end ObjectiveValues constructor


ObjectiveValues::~ObjectiveValues()
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSResult, ENUM_OUTPUT_LEVEL_trace, "Inside the ObjectiveValues Destructor");
#endif
    if((obj != NULL) && (numberOfObj > 0) )
    {
        for(int i = 0; i < numberOfObj; i++)
        {
            delete obj[i];
            obj[i] = NULL;
        }
        delete[] obj;
        obj = NULL;
    }
}// end ObjectiveValues destructor


OtherObjResult::OtherObjResult():
    idx(-1),
    name(""),
    value( "")
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSResult, ENUM_OUTPUT_LEVEL_trace, "Inside the OtherObjResult Constructor");
#endif
}//end OtherObjResult constructor


OtherObjResult::~OtherObjResult()
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSResult, ENUM_OUTPUT_LEVEL_trace, "Inside the OtherObjResult Destructor");
#endif
}//end OtherObjResult destructor


OtherObjectiveResult::OtherObjectiveResult():
    numberOfObj(0),
    numberOfEnumerations(0),
    name(""),
    value(""),
    type(""),
    description(""),
    obj(NULL),
    objType(""),    
    enumeration(NULL),
    enumType("")
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSResult, ENUM_OUTPUT_LEVEL_trace, "Inside the OtherObjectiveResult Constructor");
#endif
}//end OtherObjectiveResult constructor


OtherObjectiveResult::~OtherObjectiveResult()
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSResult, ENUM_OUTPUT_LEVEL_trace, "Inside the OtherObjectiveResult Destructor");
#endif
    if(obj != NULL)
    {
        for(int i = 0; i < numberOfObj; i++)
        {
            delete obj[i];
            obj[i] = NULL;
        }
        delete[] obj;
        obj = NULL;
    }
    if (enumeration != NULL)
    {
        for(int i = 0; i < numberOfEnumerations; i++)
        {
            delete enumeration[i];
            enumeration[i] = NULL;
        }
        delete[] enumeration;
        enumeration = NULL;
    }
}// end OtherObjectiveResult destructor


ObjectiveSolution::ObjectiveSolution():
    numberOfOtherObjectiveResults( 0),
    values( NULL),
    basisStatus(NULL),
    other( NULL)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSResult, ENUM_OUTPUT_LEVEL_trace, "Inside the ObjectiveSolution Constructor");
#endif
}//end ObjectiveSolution constructor


ObjectiveSolution::~ObjectiveSolution()
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSResult, ENUM_OUTPUT_LEVEL_trace, "Inside the ObjectiveSolution Destructor");
#endif
    if (values != NULL)
    {
        delete values;
        values = NULL;
    }
    if (basisStatus != NULL)
    {
        delete basisStatus;
        basisStatus = NULL;
    }
    if(numberOfOtherObjectiveResults > 0 && other != NULL)
    {
        for(int i = 0; i < numberOfOtherObjectiveResults; i++)
        {
            delete other[i];
            other[i] = NULL;
        }
        delete[] other;
        other = NULL;
    }
}// end ObjectiveSolution destructor


DualVarValue::DualVarValue():
    idx( -1),
    name(""),
    //lbValue( 0),
    //ubValue( 0),
    value( 0)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSResult, ENUM_OUTPUT_LEVEL_trace, "Inside the DualVarValue Constructor");
#endif
}//end DualVarValue constructor


DualVarValue::~DualVarValue()
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSResult, ENUM_OUTPUT_LEVEL_trace, "Inside the DualVarValue Destructor");
#endif
}// end DualVarValue destructor


DualVariableValues::DualVariableValues():
    numberOfCon(0),
    con(NULL)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSResult, ENUM_OUTPUT_LEVEL_trace, "Inside the DualVariableValues Constructor");
#endif

}//end DualVariableValues constructor


DualVariableValues::~DualVariableValues()
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSResult, ENUM_OUTPUT_LEVEL_trace, "Inside the DualVariableValues Destructor");
#endif
    if (con != NULL)
    {
        for(int i = 0; i < numberOfCon; i++)
        {
            delete con[i];
            con[i] = NULL;
        }
        delete[] con;
        con = NULL;
    }
}// end DualVariableValues destructor


OtherConResult::OtherConResult():
    idx( -1),
    name(""),
    value( "")
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSResult, ENUM_OUTPUT_LEVEL_trace, "Inside the OtherConResult Constructor");
#endif
}//end OtherConResult constructor


OtherConResult::~OtherConResult()
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSResult, ENUM_OUTPUT_LEVEL_trace, "Inside the OtherConResult Destructor");
#endif
}//end OtherConResult destructor



OtherConstraintResult::OtherConstraintResult():
    numberOfCon(0),
    numberOfEnumerations(0),
    name(""),
    value(""),
    type(""),
    description(""),
    con(NULL),
    conType(""),    
    enumeration(NULL),
    enumType("")
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSResult, ENUM_OUTPUT_LEVEL_trace, "Inside the OtherConstraintResult Constructor");
#endif
}//end OtherConstraintResult constructor


OtherConstraintResult::~OtherConstraintResult()
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSResult, ENUM_OUTPUT_LEVEL_trace, "Inside the OtherConstraintResult Destructor");
#endif
    if (con != NULL)
    {
        for(int i = 0; i < numberOfCon; i++)
        {
            delete con[i];
            con[i] = NULL;
        }
        delete[] con;
        con = NULL;
    }
    if (enumeration != NULL)
    {
        for(int i = 0; i < numberOfEnumerations; i++)
        {
            delete enumeration[i];
            enumeration[i] = NULL;
        }
        delete[] enumeration;
        enumeration = NULL;
    }
}// end OtherConstraintResult destructor


ConstraintSolution::ConstraintSolution():
    numberOfOtherConstraintResults( 0),
    dualValues( NULL),
    basisStatus(NULL),
    other( NULL)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSResult, ENUM_OUTPUT_LEVEL_trace, "Inside the ConstraintSolution Constructor");
#endif
}//end ConstraintSolution constructor


ConstraintSolution::~ConstraintSolution()
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSResult, ENUM_OUTPUT_LEVEL_trace, "Inside the ConstraintSolution Destructor");
#endif
    if (dualValues != NULL)
    {
        delete dualValues;
        dualValues = NULL;
    }
    if (basisStatus != NULL)
    {
        delete basisStatus;
        basisStatus = NULL;
    }
    if(numberOfOtherConstraintResults > 0 && other != NULL)
    {
        for(int i = 0; i < numberOfOtherConstraintResults; i++)
        {
            delete other[i];
            other[i] = NULL;
        }
        delete[] other;
        other = NULL;
    }
}// end ConstraintSolution destructor


MatrixVariableValues::MatrixVariableValues():
    numberOfMatrixVar(0),
    matrixVar(NULL)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSResult, ENUM_OUTPUT_LEVEL_trace, "Inside the MatrixVariableValues Constructor");
#endif
}//end MatrixVariableValues constructor


MatrixVariableValues::~MatrixVariableValues()
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSResult, ENUM_OUTPUT_LEVEL_trace, "Inside the MatrixVariableValues Destructor");
#endif
    if(numberOfMatrixVar > 0 && matrixVar != NULL)
    {
        for(int i = 0; i < numberOfMatrixVar; i++)
        {
            delete matrixVar[i];
            matrixVar[i] = NULL;
        }
        delete[] matrixVar;
        matrixVar = NULL;
    }
}// end MatrixVariableValues destructor


MatrixVariableSolution::MatrixVariableSolution():
    numberOfOtherMatrixVariableResults(0),
    values(NULL),
    other(NULL)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSResult, ENUM_OUTPUT_LEVEL_trace, "Inside the MatrixVariableSolution Constructor");
#endif
}//end MatrixVariableSolution constructor


MatrixVariableSolution::~MatrixVariableSolution()
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSResult, ENUM_OUTPUT_LEVEL_trace, "Inside the MatrixVariableSolution Destructor");
#endif
	if (values != NULL)
        delete values;
    values = NULL;

    if (numberOfOtherMatrixVariableResults > 0 && other != NULL)
    {
        for(int i = 0; i < numberOfOtherMatrixVariableResults; i++)
        {
            delete other[i];
            other[i] = NULL;
        }
        delete[] other;
        other = NULL;
    }

#if 0
    if(numberOfOtherMatrixVariableResults > 0 && matrixVar != NULL)
    {
        for(int i = 0; i < numberOfMatrixVar; i++)
        {
            delete matrixVar[i];
            matrixVar[i] = NULL;
        }
        delete[] matrixVar;
        matrixVar = NULL;
    }
#endif
}// end MatrixVariableValues destructor


OtherMatrixVariableResult::OtherMatrixVariableResult():
    name(""),
    description(""),
    value(""),
    type(""),
    solver(""),
    category(""),
    numberOfMatrixVar(0),
    matrixType(""),
    matrixVar(NULL),
    numberOfEnumerations(0),
    enumType(""),
    enumeration(NULL)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSResult, ENUM_OUTPUT_LEVEL_trace, "Inside the OtherMatrixVariableResult Constructor");
#endif
}//end OtherMatrixVariableResult constructor


OtherMatrixVariableResult::OtherMatrixVariableResult(std::string name_):
    description(""),
    value(""),
    type(""),
    solver(""),
    category(""),
    numberOfMatrixVar(0),
    matrixVar(NULL),
    numberOfEnumerations(0),
    enumeration(NULL)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSResult, ENUM_OUTPUT_LEVEL_trace, "Inside the OtherMatrixVariableResult Constructor");
#endif
    name = name_;
}//end alternate OtherMatrixVariableResult constructor

OtherMatrixVariableResult::~OtherMatrixVariableResult()
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSResult, ENUM_OUTPUT_LEVEL_trace, "Inside the OtherMatrixVariableResult Destructor");
#endif
    if (numberOfMatrixVar > 0 && matrixVar != NULL)
    {
        for(int i = 0; i < numberOfMatrixVar; i++)
        {
            delete matrixVar[i];
            matrixVar[i] = NULL;
        }
        delete[] matrixVar;
        matrixVar = NULL;
    }

    if (numberOfEnumerations > 0 && enumeration != NULL)
    {
        for(int i = 0; i < numberOfEnumerations; i++)
        {
            delete enumeration[i];
            enumeration[i] = NULL;
        }
        delete[] enumeration;
        enumeration = NULL;
    }
}// end OtherMatrixVariableResult destructor


MatrixObjectiveSolution::MatrixObjectiveSolution() //:
//    numberOfOtherMatrixVariableResults(0),
//    values(NULL)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSResult, ENUM_OUTPUT_LEVEL_trace, "Inside the MatrixObjectiveSolution Constructor");
#endif
}//end MatrixObjectiveSolution constructor


MatrixObjectiveSolution::~MatrixObjectiveSolution()
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSResult, ENUM_OUTPUT_LEVEL_trace, "Inside the MatrixObjectiveSolution Destructor");
#endif
#if 0
	if (values != NULL)
        delete values;
    values = NULL;
    if(numberOfOtherMatrixVariableResults > 0 && matrixVar != NULL)
    {
        for(int i = 0; i < numberOfMatrixVar; i++)
        {
            delete matrixVar[i];
            matrixVar[i] = NULL;
        }
        delete[] matrixVar;
        matrixVar = NULL;
    }
#endif
}// end MatrixObjectiveSolution destructor


MatrixConstraintSolution::MatrixConstraintSolution() //:
//    numberOfOtherMatrixVariableResults(0),
//    values(NULL)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSResult, ENUM_OUTPUT_LEVEL_trace, "Inside the MatrixConstraintSolution Constructor");
#endif
}//end MatrixConstraintSolution constructor


MatrixConstraintSolution::~MatrixConstraintSolution()
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSResult, ENUM_OUTPUT_LEVEL_trace, "Inside the MatrixConstraintSolution Destructor");
#endif
#if 0
	if (values != NULL)
        delete values;
    values = NULL;
    if(numberOfOtherMatrixVariableResults > 0 && matrixVar != NULL)
    {
        for(int i = 0; i < numberOfMatrixVar; i++)
        {
            delete matrixVar[i];
            matrixVar[i] = NULL;
        }
        delete[] matrixVar;
        matrixVar = NULL;
    }
#endif
}// end MatrixConstraintSolution destructor

MatrixProgrammingSolution::MatrixProgrammingSolution():
    numberOfOtherMatrixProgrammingResults(0),
    matrixVariables(NULL),
    matrixObjectives(NULL),
    matrixConstraints(NULL),
    other(NULL)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSResult, ENUM_OUTPUT_LEVEL_trace, "Inside the MatrixProgrammingSolution Constructor");
#endif
}//end MatrixProgrammingSolution constructor


MatrixProgrammingSolution::~MatrixProgrammingSolution()
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSResult, ENUM_OUTPUT_LEVEL_trace, "Inside the MatrixProgrammingSolution Destructor");
#endif
    if (matrixVariables != NULL)
        delete matrixVariables;
    matrixVariables = NULL;

    if (matrixObjectives != NULL)
        delete matrixObjectives;
    matrixObjectives = NULL;

    if (matrixConstraints != NULL)
        delete matrixConstraints;
    matrixConstraints = NULL;

    if(numberOfOtherMatrixProgrammingResults > 0 && other != NULL)
    {
        for(int i = 0; i < numberOfOtherMatrixProgrammingResults; i++)
        {
            delete other[i];
            other[i] = NULL;
        }
        delete[] other;
        other = NULL;
    }
}// end MatrixProgrammingSolution destructor


OtherSolutionResult::OtherSolutionResult():
    name(""),
    value(""),
    category (""),
    description (""),
    numberOfItems (0),
    item( NULL)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSResult, ENUM_OUTPUT_LEVEL_trace, "Inside the OtherSolutionResult Constructor");
#endif
}//end OtherSolutionResult constructor


OtherSolutionResult::~OtherSolutionResult()
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSResult, ENUM_OUTPUT_LEVEL_trace, "Inside the OtherSolutionResult Destructor");
#endif
    if (item != NULL)
        delete[] item;
    item = NULL;
}// end OtherSolutionResult destructor


OtherSolutionResults::OtherSolutionResults():
    numberOfOtherSolutionResults( 0),
    otherSolutionResult( NULL)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSResult, ENUM_OUTPUT_LEVEL_trace, "Inside the OtherSolutionResults Constructor");
#endif
}//end OtherSolutionResults constructor


OtherSolutionResults::~OtherSolutionResults()
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSResult, ENUM_OUTPUT_LEVEL_trace, "Inside the OtherSolutionResults Destructor");
#endif
    if(numberOfOtherSolutionResults > 0 && otherSolutionResult != NULL)
    {
        for(int i = 0; i < numberOfOtherSolutionResults; i++)
        {
            delete otherSolutionResult[i];
            otherSolutionResult[i] = NULL;
        }
        delete[] otherSolutionResult;
        otherSolutionResult = NULL;
    }
}// end OtherSolutionResults destructor


OptimizationSolution::OptimizationSolution():
    targetObjectiveIdx( -1),
    targetObjectiveName(""),
    weightedObjectives(false),
    status(NULL),
    message( ""),
    variables( NULL),
    objectives( NULL),
    constraints( NULL),
    matrixProgramming(NULL),
    otherSolutionResults( NULL)
    //other(NULL)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSResult, ENUM_OUTPUT_LEVEL_trace, "Inside the OptimizationSolution Constructor");
#endif
}//end OptimizationSolution constructor


OptimizationSolution::~OptimizationSolution()
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSResult, ENUM_OUTPUT_LEVEL_trace, "Inside the OptimizationSolution Destructor");
#endif
    if (status != NULL)
    {
        delete status;
        status = NULL;
    }
    if (variables != NULL)
    {
        delete variables;
        variables = NULL;
    }
    if (objectives != NULL)
    {
        delete objectives;
        objectives = NULL;
    }
    if (constraints != NULL)
    {
        delete constraints;
        constraints = NULL;
    }
    if (matrixProgramming != NULL)
    {
        delete matrixProgramming;
        matrixProgramming = NULL;
    }
    if (otherSolutionResults != NULL)
    {
        delete otherSolutionResults;
        otherSolutionResults = NULL;
    }
}// end OptimizationSolution destructor


SolverOutput::SolverOutput():
    name( ""),
    category (""),
    description (""),
    numberOfItems (0),
    item( NULL)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSResult, ENUM_OUTPUT_LEVEL_trace, "Inside the SolverOutput Constructor");
#endif
}//end SolverOutput constructor


SolverOutput::~SolverOutput()
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSResult, ENUM_OUTPUT_LEVEL_trace, "Inside the SolverOutput Destructor");
#endif
    if (item != NULL)
    {
        //for (int i=0; i < numberOfItems; i++)
        //{	delete item[i];
        //	item[i] = NULL;
        //}
        delete[] item;
        item = NULL;
    }
}// end SolverOutput destructor


OtherSolverOutput::OtherSolverOutput():
    numberOfSolverOutputs(0),
    solverOutput(NULL)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSResult, ENUM_OUTPUT_LEVEL_trace, "Inside the OtherSolverOutput Constructor");
#endif

}//end OtherSolverOutput constructor


OtherSolverOutput::~OtherSolverOutput()
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSResult, ENUM_OUTPUT_LEVEL_trace, "Inside the OtherSolverOutput Destructor");
#endif
    if (solverOutput != NULL)
    {
        for(int i = 0; i < numberOfSolverOutputs; i++)
        {
            delete solverOutput[i];
            solverOutput[i] = NULL;
        }
        delete[] solverOutput;
        solverOutput = NULL;
    }
}// end OtherSolverOutput destructor


OptimizationResult::OptimizationResult():
    numberOfSolutions(0),
    numberOfVariables(0),
    numberOfObjectives(0),
    numberOfConstraints(0),
    solution(NULL),
    otherSolverOutput(NULL)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSResult, ENUM_OUTPUT_LEVEL_trace, "Inside the OptimizationResult Constructor");
#endif
}//end OptimizationResult constructor


OptimizationResult::~OptimizationResult()
{
    std::ostringstream outStr;

#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSResult, ENUM_OUTPUT_LEVEL_trace, "Inside the OptimizationResult Destructor");
#endif
    if( solution != NULL)
    {
        for(int i = 0; i < this->numberOfSolutions; i++)
        {
            delete solution[i];
            solution[i] = NULL;
#ifndef NDEBUG
            outStr.str("");
            outStr.clear();
            outStr << "Deleting Solution: " << i << endl;
            osoutput->OSPrint(ENUM_OUTPUT_AREA_OSResult, ENUM_OUTPUT_LEVEL_trace, outStr.str());
#endif
        }
        delete[] solution;
        solution = NULL;
        if( otherSolverOutput != NULL)
        {
            delete otherSolverOutput;
            otherSolverOutput = NULL;
        }
    }
}// end OptimizationResult destructor


OSResult::OSResult():
    m_iVariableNumber( -1),
    m_iObjectiveNumber( -1),
    m_iConstraintNumber( -1),
    m_iNumberOfOtherVariableResults( -1),
    m_mdPrimalValues( NULL),
    m_mdDualValues( NULL)

{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSResult, ENUM_OUTPUT_LEVEL_trace, "Inside the OSResult Constructor");
#endif
    resultHeader = NULL;
    general = NULL;
    system = NULL;
    service = NULL;
    job = NULL;
    optimization = NULL;
}// end OSResult constructor

OSResult::~OSResult()
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSResult, ENUM_OUTPUT_LEVEL_trace, "Inside the OSResult Destructor");
#endif
    // delete the children of OSResult
    // delete resultHeader object
    if (resultHeader != NULL)
    {
        delete resultHeader;
        resultHeader = NULL;
    }
    // delete general object
    if (general != NULL)
    {
        delete general;
        general = NULL;
    }
    //delete system object
    if (system != NULL)
    {
        delete system;
        system = NULL;
    }
    //delete service object
    if (service != NULL)
    {
        delete service;
        service = NULL;
    }
    //delete job object
    if (job != NULL)
    {
        delete job;
        job = NULL;
    }
    //delete optimization object
    if (optimization != NULL)
    {
        delete optimization;
        optimization = NULL;
    }

    int k;

    if (m_mdPrimalValues != NULL) delete[] m_mdPrimalValues;
    m_mdPrimalValues = 0;

    if (m_mdDualValues != NULL) delete[] m_mdDualValues;
    m_mdDualValues = 0;

    int numPrimalVals =  this->primalVals.size();
    for (k = 0; k < numPrimalVals; k++)
    {
        if (this->primalVals[ k]  != NULL  )
            delete this->primalVals[ k];
    }
    this->primalVals.clear();

    int numDualVals =  this->dualVals.size();
    for (k = 0; k < numDualVals; k++)
    {
        if (this->dualVals[ k]  != NULL  )
            delete this->dualVals[ k];
    }
    this->dualVals.clear();
}//end OSResult destructor

// =============================================================
// get methods

GeneralStatus* OSResult::getGeneralStatus()
{
    if (general == NULL) return NULL;
    return general->generalStatus;
}//getGeneralStatus

string OSResult::getGeneralStatusType()
{
    if (general == NULL) return "";
    if (general->generalStatus == NULL) return "";
    return general->generalStatus->type;
}//getGeneralStatusType

string OSResult::getGeneralStatusDescription()
{
    if (general == NULL) return "";
    if (general->generalStatus == NULL) return "";
    return general->generalStatus->description;
}//getGeneralStatusDescription

int OSResult::getNumberOfGeneralSubstatuses()
{
    if (general == NULL) return -1;
    if (general->generalStatus == NULL) return -1;
    return general->generalStatus->numberOfSubstatuses;
}//getGeneralStatusDescription

string OSResult::getGeneralSubstatusName(int i)
{
    if (general == NULL) return "";
    if (general->generalStatus == NULL) return "";
    if (i < 0 || i >= general->generalStatus->numberOfSubstatuses)
        throw ErrorClass("idx is outside of range in routine getGeneralSubstatusName()");
    if (general->generalStatus->substatus[i] == NULL) return "";
    return general->generalStatus->substatus[i]->name;
}//getGeneralSubstatusName

string OSResult::getGeneralSubstatusDescription(int i)
{
    if (general == NULL) return "";
    if (general->generalStatus == NULL) return "";
    if (i < 0 || i >= general->generalStatus->numberOfSubstatuses)
        throw ErrorClass("idx is outside of range in routine getGeneralSubstatusDescription()");
    if (general->generalStatus->substatus[i] == NULL) return "";
    return general->generalStatus->substatus[i]->description;
}//getGeneralSubstatusDescription

string OSResult::getGeneralMessage()
{
    if (general == NULL) return "";
    return general->message;
}//getServiceName

string OSResult::getServiceName()
{
    if (general == NULL) return "";
    return general->serviceName;
}//getServiceName

string OSResult::getServiceURI()
{
    if (general == NULL) return "";
    return general->serviceURI;
}//getServiceURI

string OSResult::getInstanceName()
{
    if (general == NULL) return "";
    return general->instanceName;
}//getInstanceName

string OSResult::getJobID()
{
    if (general == NULL) return "";
    return general->jobID;
}//getJobID

string OSResult::getSolverInvoked()
{
    if (general == NULL) return "";
    return general->solverInvoked;
}//getSolverInvoked

string OSResult::getTimeStamp()
{
    if (general == NULL) return "";
    return general->timeStamp;
}//getTimeStamp

int OSResult::getNumberOfOtherGeneralResults()
{
    if (general == NULL) return -1;
    if (general->otherResults == NULL) return -1;
    return 	general->otherResults->numberOfOtherResults;
}//getNumberOfOtherGeneralResults

string OSResult::getOtherGeneralResultName(int idx)
{
    if (general == NULL) return "";
    if (general->otherResults == NULL) return "";
    if (idx < 0 || idx >= general->otherResults->numberOfOtherResults)
        throw ErrorClass("idx is outside of range in routine getOtherGeneralResultName()");
    if (general->otherResults->other[idx] == NULL) return "";
    return general->otherResults->other[idx]->name;
}//getOtherGeneralResultName

string OSResult::getOtherGeneralResultValue(int idx)
{
    if (general == NULL) return "";
    if (general->otherResults == NULL) return "";
    if (idx < 0 || idx >= general->otherResults->numberOfOtherResults)
        throw ErrorClass("idx is outside of range in routine getOtherGeneralResultValue()");
    if (general->otherResults->other[idx] == NULL) return "";
    return general->otherResults->other[idx]->value;
}//getOtherGeneralResultValue

string OSResult::getOtherGeneralResultDescription(int idx)
{
    if (general == NULL) return "";
    if (general->otherResults == NULL) return "";
    if (idx < 0 || idx >= general->otherResults->numberOfOtherResults)
        throw ErrorClass("idx is outside of range in routine getOtherGeneralResultDescription()");
    if (general->otherResults->other[idx] == NULL) return "";
    return general->otherResults->other[idx]->description;
}//getOtherGeneralResultDescription

string OSResult::getSystemInformation()
{
    if (system == NULL) return "";
    return system->systemInformation;
}//getSystemInformation

string OSResult::getAvailableDiskSpaceUnit()
{
    if (system == NULL) return "";
    if (system->availableDiskSpace == NULL) return "";
    return system->availableDiskSpace->unit;
}//getAvailableDiskSpaceUnit

string OSResult::getAvailableDiskSpaceDescription()
{
    if (system == NULL) return "";
    if (system->availableDiskSpace == NULL) return "";
    return system->availableDiskSpace->description;
}//getAvailableDiskSpaceDescription

double OSResult::getAvailableDiskSpaceValue()
{
    if (system == NULL) return -1.;
    if (system->availableDiskSpace == NULL) return -1.;
    return system->availableDiskSpace->value;
}//getAvailableDiskSpaceValue

string OSResult::getAvailableMemoryUnit()
{
    if (system == NULL) return "";
    if (system->availableMemory == NULL) return "";
    return system->availableMemory->unit;
}//getAvailableMemoryUnit

string OSResult::getAvailableMemoryDescription()
{
    if (system == NULL) return "";
    if (system->availableMemory == NULL) return "";
    return system->availableMemory->description;
}//getAvailableMemoryDescription

double OSResult::getAvailableMemoryValue()
{
    if (system == NULL) return -1.;
    if (system->availableMemory == NULL) return -1.;
    return system->availableMemory->value;
}//getAvailableMemoryValue

string OSResult::getAvailableCPUSpeedUnit()
{
    if (system == NULL) return "";
    if (system->availableCPUSpeed == NULL) return "";
    return system->availableCPUSpeed->unit;
}//getAvailableCPUSpeedUnit

string OSResult::getAvailableCPUSpeedDescription()
{
    if (system == NULL) return "";
    if (system->availableCPUSpeed == NULL) return "";
    return system->availableCPUSpeed->description;
}//getAvailableCPUSpeedDescription

double OSResult::getAvailableCPUSpeedValue()
{
    if (system == NULL) return -1.;
    if (system->availableCPUSpeed == NULL) return -1.;
    return system->availableCPUSpeed->value;
}//getAvailableCPUSpeedValue

string OSResult::getAvailableCPUNumberDescription()
{
    if (system == NULL) return "";
    if (system->availableCPUNumber == NULL) return "";
    return system->availableCPUNumber->description;
}//getAvailableCPUNumberDescription

int OSResult::getAvailableCPUNumberValue()
{
    if (system == NULL) return -1;
    if (system->availableCPUNumber == NULL) return -1;
    return system->availableCPUNumber->value;
}//getAvailableCPUNumberValue

int OSResult::getNumberOfOtherSystemResults()
{
    if (system == NULL) return -1;
    if (system->otherResults == NULL) return -1;
    return system->otherResults->numberOfOtherResults;
}//getNumberOfOtherSystemResults

string OSResult::getOtherSystemResultName(int idx)
{
    if (system == NULL) return "";
    if (system->otherResults == NULL) return "";
    if (idx < 0 || idx >= system->otherResults->numberOfOtherResults)
        throw ErrorClass("idx is outside of range in routine getOtherSystemResultName()");
    if (system->otherResults->other[idx] == NULL) return "";
    return system->otherResults->other[idx]->name;
}//getOtherSystemResultName

string OSResult::getOtherSystemResultValue(int idx)
{
    if (system == NULL) return "";
    if (system->otherResults == NULL) return "";
    if (idx < 0 || idx >= system->otherResults->numberOfOtherResults)
        throw ErrorClass("idx is outside of range in routine getOtherSystemResultValue()");
    if (system->otherResults->other[idx] == NULL) return "";
    return system->otherResults->other[idx]->value;
}//getOtherSystemResultValue

string OSResult::getOtherSystemResultDescription(int idx)
{
    if (system == NULL) return "";
    if (system->otherResults == NULL) return "";
    if (idx < 0 || idx >= system->otherResults->numberOfOtherResults)
        throw ErrorClass("idx is outside of range in routine getOtherSystemResultDescription()");
    if (system->otherResults->other[idx] == NULL) return "";
    return system->otherResults->other[idx]->description;
}//getOtherSystemResultDescription

string OSResult::getCurrentState()
{
    if (service == NULL) return "";
    return service->currentState;
}//getCurrentState

int OSResult::getCurrentJobCount()
{
    if (service == NULL) return -1;
    return service->currentJobCount;
}//getCurrentJobCount

int OSResult::getTotalJobsSoFar()
{
    if (service == NULL) return -1;
    return service->totalJobsSoFar;
}//getTotalJobsSoFar

string OSResult::getTimeServiceStarted()
{
    if (service == NULL) return "";
    return service->timeServiceStarted;
}//getTimeServiceStarted

double OSResult::getServiceUtilization()
{
    if (service == NULL) return -1.;
    return service->serviceUtilization;
}//getServiceUtilization

int OSResult::getNumberOfOtherServiceResults()
{
    if (service == NULL) return -1;
    if (service->otherResults == NULL) return -1;
    return service->otherResults->numberOfOtherResults;
}//getNumberOfOtherServiceResults

string OSResult::getOtherServiceResultName(int idx)
{
    if (service == NULL) return "";
    if (service->otherResults == NULL) return "";
    if (idx < 0 || idx >= service->otherResults->numberOfOtherResults)
        throw ErrorClass("idx is outside of range in routine getOtherServiceResultName()");
    if (service->otherResults->other[idx] == NULL) return "";
    return service->otherResults->other[idx]->name;
}//getOtherServiceResultName

string OSResult::getOtherServiceResultValue(int idx)
{
    if (service == NULL) return "";
    if (service->otherResults == NULL) return "";
    if (idx < 0 || idx >= service->otherResults->numberOfOtherResults)
        throw ErrorClass("idx is outside of range in routine getOtherServiceResultValue()");
    if (service->otherResults->other[idx] == NULL) return "";
    return service->otherResults->other[idx]->value;
}//getOtherServiceResultValue

string OSResult::getOtherServiceResultDescription(int idx)
{
    if (service == NULL) return "";
    if (service->otherResults == NULL) return "";
    if (idx < 0 || idx >= service->otherResults->numberOfOtherResults)
        throw ErrorClass("idx is outside of range in routine getOtherServiceResultDescription()");
    if (service->otherResults->other[idx] == NULL) return "";
    return service->otherResults->other[idx]->description;
}//getOtherServiceResultDescription

string OSResult::getJobStatus()
{
    if (job == NULL) return "";
    return job->status;
}//getJobStatus

string OSResult::getJobSubmitTime()
{
    if (job == NULL) return "";
    return job->submitTime;
}//getJobSubmitTime

string OSResult::getScheduledStartTime()
{
    if (job == NULL) return "";
    return job->scheduledStartTime;
}//getScheduledStartTime

string OSResult::getActualStartTime()
{
    if (job == NULL) return "";
    return job->actualStartTime;
}//getActualStartTime

string OSResult::getJobEndTime()
{
    if (job == NULL) return "";
    return job->endTime;
}//getJobEndTime

int OSResult::getNumberOfTimes()
{
    if (job == NULL) return -1;
    if (job->timingInformation == NULL) return -1;
    return job->timingInformation->numberOfTimes;
}//getNumberOfTimes

string OSResult::getTimingInfoUnit(int idx)
{
    if (job == NULL) return "";
    if (job->timingInformation == NULL) return "";
    if (idx < 0 || idx >= job->timingInformation->numberOfTimes)
        throw ErrorClass("idx is outside of range in routine getTimingInfoUnit()");
    if (job->timingInformation->time[idx] == NULL) return "";
    return job->timingInformation->time[idx]->unit;
}//getTimingInfoUnit

string OSResult::getTimingInfoType(int idx)
{
    if (job == NULL) return "";
    if (job->timingInformation == NULL) return "";
    if (idx < 0 || idx >= job->timingInformation->numberOfTimes)
        throw ErrorClass("idx is outside of range in routine getTimingInfoType()");
    if (job->timingInformation->time[idx] == NULL) return "";
    return job->timingInformation->time[idx]->type;
}//getTimingInfoType

string OSResult::getTimingInfoCategory(int idx)
{
    if (job == NULL) return "";
    if (job->timingInformation == NULL) return "";
    if (idx < 0 || idx >= job->timingInformation->numberOfTimes)
        throw ErrorClass("idx is outside of range in routine getTimingInfoCategory()");
    if (job->timingInformation->time[idx] == NULL) return "";
    return job->timingInformation->time[idx]->category;
}//getTimingInfoCategory

string OSResult::getTimingInfoDescription(int idx)
{
    if (job == NULL) return "";
    if (job->timingInformation == NULL) return "";
    if (idx < 0 || idx >= job->timingInformation->numberOfTimes)
        throw ErrorClass("idx is outside of range in routine getTimingInfoDescription()");
    if (job->timingInformation->time[idx] == NULL) return "";
    return job->timingInformation->time[idx]->description;
}//getTimingInfoDescription

double OSResult::getTimingInfoValue(int idx)
{
    if (job == NULL) return OSNaN();
    if (job->timingInformation == NULL) return OSNaN();
    if (idx < 0 || idx >= job->timingInformation->numberOfTimes)
        throw ErrorClass("idx is outside of range in routine getTimingInfoValue()");
    if (job->timingInformation->time[idx] == NULL) return OSNaN();
    return job->timingInformation->time[idx]->value;
}//getTimingInfoValue

string OSResult::getUsedDiskSpaceUnit()
{
    if (job == NULL) return "";
    if (job->usedDiskSpace == NULL) return "";
    return job->usedDiskSpace->unit;
}//getUsedDiskSpaceUnit

string OSResult::getUsedDiskSpaceDescription()
{
    if (job == NULL) return "";
    if (job->usedDiskSpace == NULL) return "";
    return job->usedDiskSpace->description;
}//getUsedDiskSpaceDescription

double OSResult::getUsedDiskSpaceValue()
{
    if (job == NULL) return -1.;
    if (job->usedDiskSpace == NULL) return -1.;
    return job->usedDiskSpace->value;
}//getUsedDiskSpaceValue

string OSResult::getUsedMemoryUnit()
{
    if (job == NULL) return "";
    if (job->usedMemory == NULL) return "";
    return job->usedMemory->unit;
}//getUsedMemoryUnit

string OSResult::getUsedMemoryDescription()
{
    if (job == NULL) return "";
    if (job->usedMemory == NULL) return "";
    return job->usedMemory->description;
}//getUsedMemoryDescription

double OSResult::getUsedMemoryValue()
{
    if (job == NULL) return -1.;
    if (job->usedMemory == NULL) return -1.;
    return job->usedMemory->value;
}//getUsedMemoryValue

string OSResult::getUsedCPUSpeedUnit()
{
    if (job == NULL) return "";
    if (job->usedCPUSpeed == NULL) return "";
    return job->usedCPUSpeed->unit;
}//getUsedCPUSpeedUnit

string OSResult::getUsedCPUSpeedDescription()
{
    if (job == NULL) return "";
    if (job->usedCPUSpeed == NULL) return "";
    return job->usedCPUSpeed->description;
}//getUsedCPUSpeedDescription

double OSResult::getUsedCPUSpeedValue()
{
    if (job == NULL) return -1.;
    if (job->usedCPUSpeed == NULL) return -1.;
    return job->usedCPUSpeed->value;
}//getUsedCPUSpeedValue

string OSResult::getUsedCPUNumberDescription()
{
    if (job == NULL) return "";
    if (job->usedCPUNumber == NULL) return "";
    return job->usedCPUNumber->description;
}//getUsedCPUNumberDescription

int OSResult::getUsedCPUNumberValue()
{
    if (job == NULL) return -1;
    if (job->usedCPUNumber == NULL) return -1;
    return job->usedCPUNumber->value;
}//getUsedCPUNumberValue

int OSResult::getNumberOfOtherJobResults()
{
    if (job == NULL) return -1;
    if (job->otherResults == NULL) return -1;
    return job->otherResults->numberOfOtherResults;
}//getNumberOfOtherJobResults

string OSResult::getOtherJobResultName(int idx)
{
    if (job == NULL) return "";
    if (job->otherResults == NULL) return "";
    if (idx < 0 || idx >= job->otherResults->numberOfOtherResults)
        throw ErrorClass("idx is outside of range in routine getOtherJobResultName()");
    if (job->otherResults->other[idx] == NULL) return "";
    return job->otherResults->other[idx]->name;
}//getOtherJobResultName

string OSResult::getOtherJobResultValue(int idx)
{
    if (job == NULL) return "";
    if (job->otherResults == NULL) return "";
    if (idx < 0 || idx >= job->otherResults->numberOfOtherResults)
        throw ErrorClass("idx is outside of range in routine getOtherJobResultValue()");
    if (job->otherResults->other[idx] == NULL) return "";
    return job->otherResults->other[idx]->value;
}//getOtherJobResultValue

string OSResult::getOtherJobResultDescription(int idx)
{
    if (job == NULL) return "";
    if (job->otherResults == NULL) return "";
    if (idx < 0 || idx >= job->otherResults->numberOfOtherResults)
        throw ErrorClass("idx is outside of range in routine getOtherJobResultDescription()");
    if (job->otherResults->other[idx] == NULL) return "";
    return job->otherResults->other[idx]->description;
}//getOtherJobResultDescription

double OSResult::getTimeValue()
{
    if (job == NULL) return 0.0;
    if (job->timingInformation == NULL) return 0.0;
    if (job->timingInformation->numberOfTimes <= 0) return 0.0;
    return job->timingInformation->time[0]->value;
}//getTimeValue

int OSResult::getTimeNumber()
{
    if (job == NULL) return -1;
    if (job->timingInformation == NULL) return -1;
    return job->timingInformation->numberOfTimes;
}//getTimeNumber


int OSResult::getVariableNumber()
{
    if(m_iVariableNumber == -1)
    {
        if(optimization == NULL) return -1;
        m_iVariableNumber = optimization->numberOfVariables;
    }
    return m_iVariableNumber;
}//getVariableNumber

int OSResult::getObjectiveNumber()
{
    if(m_iObjectiveNumber == -1)
    {
        if(optimization == NULL) return -1;
        m_iObjectiveNumber = optimization->numberOfObjectives;
    }
    return m_iObjectiveNumber;
}//getObjectiveNumber

int OSResult::getConstraintNumber()
{
    if(m_iConstraintNumber == -1)
    {
        if(optimization == NULL) return -1;
        m_iConstraintNumber = optimization->numberOfConstraints;
    }
    return m_iConstraintNumber;
}//getConstraintNumber

int OSResult::getSolutionNumber()
{
    if(optimization == NULL) return 0;
    if(optimization->solution == NULL) return 0;
    return optimization->numberOfSolutions;
}//getSolutionNumber


OptimizationSolutionStatus* OSResult::getSolutionStatus( int solIdx)
{
    if (optimization == NULL || optimization->solution == NULL)
        throw ErrorClass("No solution defined");
    if (solIdx < 0 || solIdx >= optimization->numberOfSolutions)
        throw ErrorClass("solIdx is outside of range in routine getSolutionStatus()");
    if(optimization->solution[solIdx] == NULL) return NULL;
    return optimization->solution[solIdx]->status;
}//getSolutionStatus

string OSResult::getSolutionStatusType(int solIdx)
{
    if (optimization == NULL || optimization->solution == NULL)
        throw ErrorClass("No solution defined");
    if (solIdx < 0 || solIdx >= optimization->numberOfSolutions)
        throw ErrorClass("solIdx is outside of range in routine getSolutionStatusType()");
    if (optimization->solution[solIdx] == NULL) return "";
    if (optimization->solution[solIdx]->status == NULL) return "";
    return optimization->solution[solIdx]->status->type;
}//getSolutionStatusType

string OSResult::getSolutionStatusDescription(int solIdx)
{
    if (optimization == NULL || optimization->solution == NULL)
        throw ErrorClass("No solution defined");
    if (solIdx < 0 || solIdx >= optimization->numberOfSolutions)
        throw ErrorClass("solIdx is outside of range in routine getSolutionStatusDescription()");
    if (optimization->solution[solIdx] == NULL) return "";
    if (optimization->solution[solIdx]->status == NULL) return "";
    return optimization->solution[solIdx]->status->description;
}//getSolutionStatusDescription

int OSResult::getNumberOfSolutionSubstatuses(int solIdx)
{
    if (optimization == NULL || optimization->solution == NULL)
        throw ErrorClass("No solution defined");
    if (solIdx < 0 || solIdx >= optimization->numberOfSolutions)
        throw ErrorClass("solIdx is outside of range in routine getNumberOfSolutionSubstatuses()");
    if (optimization->solution[solIdx] == NULL) return -1;
    if (optimization->solution[solIdx]->status == NULL) return -1;
    return optimization->solution[solIdx]->status->numberOfSubstatuses;
}//getNumberOfSolutionSubstatuses

string OSResult::getSolutionSubstatusType(int solIdx, int substatusIdx)
{
    if (optimization == NULL || optimization->solution == NULL)
        throw ErrorClass("No solution defined");
    if (solIdx < 0 || solIdx >= optimization->numberOfSolutions)
        throw ErrorClass("solIdx is outside of range in routine getSolutionSubstatusType()");
    if (optimization->solution[solIdx] == NULL) return "";
    if (optimization->solution[solIdx]->status == NULL) return "";
    if (substatusIdx < 0 || substatusIdx >= optimization->solution[solIdx]->status->numberOfSubstatuses)
        throw ErrorClass("solution substatus index is outside of range in routine getSolutionSubstatusType()");
    return optimization->solution[solIdx]->status->substatus[substatusIdx]->type;
}//getSolutionSubstatusType

string OSResult::getSolutionSubstatusDescription(int solIdx, int substatusIdx)
{
    if (optimization == NULL || optimization->solution == NULL)
        throw ErrorClass("No solution defined");
    if (solIdx < 0 || solIdx >= optimization->numberOfSolutions)
        throw ErrorClass("solIdx is outside of range in routine getSolutionSubstatusDescription()");
    if (optimization->solution[solIdx] == NULL) return "";
    if (optimization->solution[solIdx]->status == NULL) return "";
    if (substatusIdx < 0 || substatusIdx >= optimization->solution[solIdx]->status->numberOfSubstatuses)
        return "";
    return optimization->solution[solIdx]->status->substatus[substatusIdx]->description;
}//getSolutionSubstatusDescription

int OSResult::getSolutionTargetObjectiveIdx(int solIdx)
{
    if (optimization == NULL || optimization->solution == NULL)
        throw ErrorClass("No solution defined");
    if (solIdx < 0 || solIdx >=  optimization->numberOfSolutions)
        throw ErrorClass("solIdx is outside of range in routine getSolutionTargetObjectiveIdx()");
    if (optimization->solution[solIdx] == NULL) return 0;
    return optimization->solution[solIdx]->targetObjectiveIdx;
}//getSolutionTargetObjectiveIdx

std::string OSResult::getSolutionTargetObjectiveName(int solIdx)
{
    if (optimization == NULL || optimization->solution == NULL)
        throw ErrorClass("No solution defined");
    if (solIdx < 0 || solIdx >=  optimization->numberOfSolutions)
        throw ErrorClass("solIdx is outside of range in routine getSolutionTargetObjectiveName()");
    if (optimization->solution[solIdx] == NULL) return 0;
    return optimization->solution[solIdx]->targetObjectiveName;
}//getSolutionTargetObjectiveName

bool OSResult::getSolutionWeightedObjectives(int solIdx)
{
    if (optimization == NULL || optimization->solution == NULL)
        throw ErrorClass("No solution defined");
    if (solIdx < 0 || solIdx >= optimization->numberOfSolutions)
        throw ErrorClass("solIdx is outside of range in routine getSolutionWeightedObjectives()");
    if (optimization->solution[solIdx] == NULL) return false;
    return optimization->solution[solIdx]->weightedObjectives;
}//getSolutionWeightedObjectives

string OSResult::getSolutionMessage(int solIdx)
{
    if(optimization == NULL) return "there is no solution";
    if(optimization->solution == NULL ||
            solIdx < 0 || solIdx >=  optimization->numberOfSolutions) return "there is no solution";
    if(optimization->solution[solIdx] == NULL) return "there is no solution";
    return optimization->solution[solIdx]->message;
}//getSolutionMessage

int OSResult::getNumberOfPrimalVariableValues(int solIdx)
{
    if (optimization == NULL || optimization->solution == NULL)
        throw ErrorClass("No solution defined");
    if (solIdx < 0 || solIdx >= optimization->numberOfSolutions)
        throw ErrorClass("solIdx is outside of range in routine getNumberOfPrimalVariableValues()");
    if (optimization->solution[solIdx] == NULL) return -1;
    if (optimization->solution[solIdx]->variables == NULL) return -1;
    if (optimization->solution[solIdx]->variables->values == NULL) return -1;
    return optimization->solution[solIdx]->variables->values->numberOfVar;
}//getNumberOfPrimalVariableValues

int OSResult::getNumberOfVarValues(int solIdx)
{
    if (optimization == NULL || optimization->solution == NULL)
        throw ErrorClass("No solution defined");
    if (solIdx < 0 || solIdx >= optimization->numberOfSolutions)
        throw ErrorClass("solIdx is outside of range in routine getNumberOfVarValues()");
    if (optimization->solution[solIdx] == NULL) return -1;
    if (optimization->solution[solIdx]->variables == NULL) return -1;
    if (optimization->solution[solIdx]->variables->values == NULL) return -1;
    return optimization->solution[solIdx]->variables->values->numberOfVar;
}//getNumberOfVarValues

int OSResult::getVarValueIdx(int solIdx, int varIdx)
{
    if (optimization == NULL || optimization->solution == NULL)
        throw ErrorClass("No solution defined");
    if (solIdx < 0 || solIdx >= optimization->numberOfSolutions)
        throw ErrorClass("solIdx is outside of range in routine getVarValueIdx()");
    if (optimization->solution[solIdx] == NULL) return -1;
    if (optimization->solution[solIdx]->variables == NULL) return -1;
    if (optimization->solution[solIdx]->variables->values == NULL) return -1;
    if (varIdx < 0 || varIdx >= optimization->solution[solIdx]->variables->values->numberOfVar)
        throw ErrorClass("varIdx is outside of range in routine getVarValueIdx()");
    return optimization->solution[solIdx]->variables->values->var[varIdx]->idx;
}//getVarValueIdx

std::string OSResult::getVarValueName(int solIdx, int varIdx)
{
    if (optimization == NULL || optimization->solution == NULL)
        throw ErrorClass("No solution defined");
    if (solIdx < 0 || solIdx >= optimization->numberOfSolutions)
        throw ErrorClass("solIdx is outside of range in routine getVarValueIdx()");
    if (optimization->solution[solIdx] == NULL) return "";
    if (optimization->solution[solIdx]->variables == NULL) return "";
    if (optimization->solution[solIdx]->variables->values == NULL) return "";
    if (varIdx < 0 || varIdx >= optimization->solution[solIdx]->variables->values->numberOfVar)
        throw ErrorClass("varIdx is outside of range in routine getVarValueIdx()");
    return optimization->solution[solIdx]->variables->values->var[varIdx]->name;
}//getVarValueName

double OSResult::getVarValue(int solIdx, int varIdx)
{
    if (optimization == NULL || optimization->solution == NULL)
        throw ErrorClass("No solution defined");
    if (solIdx < 0 || solIdx >= optimization->numberOfSolutions)
        throw ErrorClass("solIdx is outside of range in routine getVarValue()");
    if (optimization->solution[solIdx] == NULL) return OSNaN();
    if (optimization->solution[solIdx]->variables == NULL) return OSNaN();
    if (optimization->solution[solIdx]->variables->values == NULL) return OSNaN();
    if (varIdx < 0 || varIdx >= optimization->solution[solIdx]->variables->values->numberOfVar)
        throw ErrorClass("varIdx is outside of range in routine getVarValue()");
    return optimization->solution[solIdx]->variables->values->var[varIdx]->value;
}//getVarValue

std::vector<IndexValuePair*> OSResult::getOptimalPrimalVariableValues(int solIdx)
{
    int numberOfVar;
    struct IndexValuePair *primalValPair;
    int iSolutions = this->getSolutionNumber();
    for(int i = 0; i < iSolutions; i++)
    {
        if( i != solIdx) continue;
        if(optimization->solution[i] == NULL) continue;
        if(optimization->solution[i]->variables == NULL) continue;
        if(optimization->solution[i]->variables->values == NULL) continue;
        if((optimization->solution[i]->status->type.find("ptimal") != string::npos && m_mdPrimalValues == NULL) ||
                optimization->solution[i]->status->type.compare("globallyOptimal") == 0)
        {
            numberOfVar = optimization->solution[i]->variables->values->numberOfVar;
            for(int j = 0; j < numberOfVar; j++)
            {
                primalValPair = new IndexValuePair();
                primalValPair->value = optimization->solution[i]->variables->values->var[j]->value;
                primalValPair->idx = optimization->solution[i]->variables->values->var[j]->idx;
                primalVals.push_back( primalValPair);
            }
        }
        if(optimization->solution[i]->status->type.compare("globallyOptimal") == 0)
        {
            return primalVals;
        }
    }
    return primalVals;
}//getOptimalPrimalVariableValues


int OSResult::getNumberOfVarValuesString(int solIdx)
{
    if (optimization == NULL || optimization->solution == NULL)
        throw ErrorClass("No solution defined");
    if (solIdx < 0 || solIdx >= optimization->numberOfSolutions)
        throw ErrorClass("solIdx is outside of range in routine getNumberOfVarValuesString()");
    if (optimization->solution[solIdx] == NULL) return -1;
    if (optimization->solution[solIdx]->variables == NULL) return -1;
    if (optimization->solution[solIdx]->variables->valuesString == NULL) return -1;
    return optimization->solution[solIdx]->variables->valuesString->numberOfVar;
}//getNumberOfVarValuesString

int OSResult::getVarValueStringIdx(int solIdx, int varIdx)
{
    if (optimization == NULL || optimization->solution == NULL)
        throw ErrorClass("No solution defined");
    if (solIdx < 0 || solIdx >= optimization->numberOfSolutions)
        throw ErrorClass("solIdx is outside of range in routine getVarValueStringIdx()");
    if (optimization->solution[solIdx] == NULL) return -1;
    if (optimization->solution[solIdx]->variables == NULL) return -1;
    if (optimization->solution[solIdx]->variables->valuesString == NULL) return -1;
    if (varIdx < 0 || varIdx >= optimization->solution[solIdx]->variables->valuesString->numberOfVar)
        throw ErrorClass("varIdx is outside of range in routine getVarValueStringIdx()");
    return optimization->solution[solIdx]->variables->valuesString->var[varIdx]->idx;
}//getVarValueStringIdx

std::string OSResult::getVarValueStringName(int solIdx, int varIdx)
{
    if (optimization == NULL || optimization->solution == NULL)
        throw ErrorClass("No solution defined");
    if (solIdx < 0 || solIdx >= optimization->numberOfSolutions)
        throw ErrorClass("solIdx is outside of range in routine getVarValueStringIdx()");
    if (optimization->solution[solIdx] == NULL) return "";
    if (optimization->solution[solIdx]->variables == NULL) return "";
    if (optimization->solution[solIdx]->variables->valuesString == NULL) return "";
    if (varIdx < 0 || varIdx >= optimization->solution[solIdx]->variables->valuesString->numberOfVar)
        throw ErrorClass("varIdx is outside of range in routine getVarValueStringIdx()");
    return optimization->solution[solIdx]->variables->valuesString->var[varIdx]->name;
}//getVarValueStringName

std::string OSResult::getVarValueString(int solIdx, int varIdx)
{
    if (optimization == NULL || optimization->solution == NULL)
        throw ErrorClass("No solution defined");
    if (solIdx < 0 || solIdx >= optimization->numberOfSolutions)
        throw ErrorClass("solIdx is outside of range in routine getVarValueString()");
    if (optimization->solution[solIdx] == NULL) return NULL;
    if (optimization->solution[solIdx]->variables == NULL) return NULL;
    if (optimization->solution[solIdx]->variables->valuesString == NULL) return NULL;
    if (varIdx < 0 || varIdx >= optimization->solution[solIdx]->variables->valuesString->numberOfVar)
        throw ErrorClass("varIdx is outside of range in routine getVarValueString()");
    return optimization->solution[solIdx]->variables->valuesString->var[varIdx]->value;
}//getVarValueString

int OSResult::getBasisStatusNumberOfEl(int solIdx, int object, int status)
{
    if (optimization == NULL || optimization->solution == NULL)
        throw ErrorClass("No solution defined");
    if (solIdx < 0 || solIdx >= optimization->numberOfSolutions)
        throw ErrorClass("solIdx is outside of range in routine getBasisStatusNumberOfEl()");
    if (optimization->solution[solIdx] == NULL) return -1;

    switch (object)
    {
    case ENUM_PROBLEM_COMPONENT_variables:
    {
        if (optimization->solution[solIdx]->variables == NULL) return -1;
        if (optimization->solution[solIdx]->variables->basisStatus == NULL) return -1;
        return optimization->solution[solIdx]->variables->basisStatus->getNumberOfEl(status);
    }
    case ENUM_PROBLEM_COMPONENT_objectives:
    {
        if (optimization->solution[solIdx]->objectives == NULL) return -1;
        if (optimization->solution[solIdx]->objectives->basisStatus == NULL) return -1;
        return optimization->solution[solIdx]->objectives->basisStatus->getNumberOfEl(status);
    }
    case ENUM_PROBLEM_COMPONENT_constraints:
    {
        if (optimization->solution[solIdx]->constraints == NULL) return -1;
        if (optimization->solution[solIdx]->constraints->basisStatus == NULL) return -1;
        return optimization->solution[solIdx]->constraints->basisStatus->getNumberOfEl(status);
    }
    default:
        throw ErrorClass("target object not implemented in getBasisStatusNumberOfEl");
    }
}//getBasisStatusNumberOfEl

int OSResult::getBasisStatusEl(int solIdx, int object, int status, int j)
{
    if (optimization == NULL || optimization->solution == NULL)
        throw ErrorClass("No solution defined");
    if (solIdx < 0 || solIdx >= optimization->numberOfSolutions)
        throw ErrorClass("solIdx is outside of range in routine getBasisStatusEl()");
    if (optimization->solution[solIdx] == NULL)
        throw ErrorClass("solution never defined in routine getBasisStatusEl()");

    switch (object)
    {
    case ENUM_PROBLEM_COMPONENT_variables:
    {
        if (optimization->solution[solIdx]->variables == NULL)
            throw ErrorClass("variables result never defined in routine getBasisStatusEl()");
        if (optimization->solution[solIdx]->variables->basisStatus == NULL)
            throw ErrorClass("basis status never defined in routine getBasisStatusEl()");
        return optimization->solution[solIdx]->variables->basisStatus->getEl(status, j);
    }
    case ENUM_PROBLEM_COMPONENT_objectives:
    {
        if (optimization->solution[solIdx]->objectives == NULL)
            throw ErrorClass("objectives result never defined in routine getBasisStatusEl()");
        if (optimization->solution[solIdx]->objectives->basisStatus == NULL)
            throw ErrorClass("basis status never defined in routine getBasisStatusEl()");
        return optimization->solution[solIdx]->objectives->basisStatus->getEl(status, j);
    }
    case ENUM_PROBLEM_COMPONENT_constraints:
    {
        if (optimization->solution[solIdx]->constraints == NULL)
            throw ErrorClass("constraints result never defined in routine getBasisStatusEl()");
        if (optimization->solution[solIdx]->constraints->basisStatus == NULL)
            throw ErrorClass("basis status never defined in routine getBasisStatusEl()");
        return optimization->solution[solIdx]->constraints->basisStatus->getEl(status, j);
    }
    default:
        throw ErrorClass("target object not implemented in getBasisStatusEl");
    }
}//getBasisStatusEl

int OSResult::getBasisInformationDense(int solIdx, int object, int* resultArray, int dim)
{
    if (optimization == NULL || optimization->solution == NULL)
        throw ErrorClass("No solution defined");
    if (solIdx < 0 || solIdx >= optimization->numberOfSolutions)
        throw ErrorClass("solIdx is outside of range in routine getBasisInformationDense()");
    if (optimization->solution[solIdx] == NULL)
        throw ErrorClass("solution never defined in routine getBasisInformationDense()");

    for (int i=0; i<dim; i++)
        resultArray[i] = 0;

    switch (object)
    {
    case ENUM_PROBLEM_COMPONENT_variables:
    {
        if (optimization->solution[solIdx]->variables == NULL)
            throw ErrorClass("variables result never defined in routine getBasisInformationDense()");
        if (optimization->solution[solIdx]->variables->basisStatus == NULL)
            throw ErrorClass("basis status never defined in routine getBasisInformationDense()");
        return optimization->solution[solIdx]->variables->basisStatus->getBasisDense(resultArray, dim, false);
    }
    case ENUM_PROBLEM_COMPONENT_objectives:
    {
        if (optimization->solution[solIdx]->objectives == NULL)
            throw ErrorClass("objectives result never defined in routine getBasisInformationDense()");
        if (optimization->solution[solIdx]->objectives->basisStatus == NULL)
            throw ErrorClass("basis status never defined in routine getBasisInformationDense()");
        return optimization->solution[solIdx]->objectives->basisStatus->getBasisDense(resultArray, dim, true);
    }
    case ENUM_PROBLEM_COMPONENT_constraints:
    {
        if (optimization->solution[solIdx]->constraints == NULL)
            throw ErrorClass("constraints result never defined in routine getBasisInformationDense()");
        if (optimization->solution[solIdx]->constraints->basisStatus == NULL)
            throw ErrorClass("basis status never defined in routine getBasisInformationDense()");
        return optimization->solution[solIdx]->constraints->basisStatus->getBasisDense(resultArray, dim, false);
    }
    default:
        throw ErrorClass("target object not implemented in getBasisInformationDense");
    }
}//getBasisInformationDense

/*
int OSResult::getNumberOfBasisVar(int solIdx){
	if (optimization == NULL || optimization->solution == NULL)
		throw ErrorClass("No solution defined");
	if (solIdx < 0 || solIdx >= optimization->numberOfSolutions)
		throw ErrorClass("solIdx is outside of range in routine getNumberOfBasisVar()");
	if (optimization->solution[solIdx] == NULL) return -1;
	if (optimization->solution[solIdx]->variables == NULL) return -1;
	if (optimization->solution[solIdx]->variables->basisStatus == NULL) return -1;
	return optimization->solution[solIdx]->variables->basisStatus->numberOfVar;
}//getNumberOfBasisVar

int OSResult::getBasisVarIdx(int solIdx, int varIdx){
	if (optimization == NULL || optimization->solution == NULL)
		throw ErrorClass("No solution defined");
	if (solIdx < 0 || solIdx >= optimization->numberOfSolutions)
		throw ErrorClass("solIdx is outside of range in routine getBasisVarIdx()");
	if (optimization->solution[solIdx] == NULL) return -1;
	if (optimization->solution[solIdx]->variables == NULL) return -1;
	if (optimization->solution[solIdx]->variables->valuesString == NULL) return -1;
	if (varIdx < 0 || varIdx >= optimization->solution[solIdx]->variables->basisStatus->numberOfVar)
		throw ErrorClass("varIdx is outside of range in routine getBasisVarIdx()");
	return optimization->solution[solIdx]->variables->basisStatus->var[varIdx]->idx;
}//getBasisVarIdx

std::string OSResult::getBasisVar(int solIdx, int varIdx){
	if (optimization == NULL || optimization->solution == NULL)
		throw ErrorClass("No solution defined");
	if (solIdx < 0 || solIdx >= optimization->numberOfSolutions)
		throw ErrorClass("solIdx is outside of range in routine getBasisVar()");
	if (optimization->solution[solIdx] == NULL) return "";
	if (optimization->solution[solIdx]->variables == NULL) return "";
	if (optimization->solution[solIdx]->variables->valuesString == NULL) return "";
	if (varIdx < 0 || varIdx >= optimization->solution[solIdx]->variables->basisStatus->numberOfVar)
		throw ErrorClass("varIdx is outside of range in routine getBasisVar()");
	return optimization->solution[solIdx]->variables->basisStatus->var[varIdx]->value;
}//getBasisVar
*/

int OSResult::getNumberOfOtherVariableResults(int solIdx)
{
    if(m_iNumberOfOtherVariableResults == -1)
    {
        if (optimization == NULL || optimization->solution == NULL)
            throw ErrorClass("No solution defined");
        if (solIdx < 0 || solIdx >= optimization->numberOfSolutions)
            throw ErrorClass("solIdx is outside of range in routine getNumberOfOtherVariableResults()");
        if(optimization->solution[solIdx] == NULL) 
            throw ErrorClass("solution was never defined in routine getNumberOfOtherVariableResults()");
        if(optimization->solution[solIdx]->variables == NULL) return 0;
        if(optimization->solution[solIdx]->variables->other == NULL) return 0;
        m_iNumberOfOtherVariableResults = optimization->solution[solIdx]->variables->numberOfOtherVariableResults;
    }
    return m_iNumberOfOtherVariableResults;
}//getNumberOfOtherVariableResults

int OSResult::getAnOtherVariableResultNumberOfVar(int solIdx, int iOther)
{
    if (optimization == NULL || optimization->solution == NULL)
        throw ErrorClass("No solution defined");
    int iSolutions = this->getSolutionNumber();
    if (solIdx < 0 || solIdx >= iSolutions)
        throw ErrorClass("solIdx is outside of range in routine getAnOtherVariableResultNumberOfVar()");
    if (optimization->solution[solIdx] == NULL) return -1;
    if (optimization->solution[solIdx]->variables == NULL) return -1;
    if (optimization->solution[solIdx]->variables->other == NULL) return -1;
    if (iOther < 0 || iOther >= optimization->solution[solIdx]->variables->numberOfOtherVariableResults)
        throw ErrorClass("other variables result index is outside of range in routine getAnOtherVariableResultNumberOfVar()");
    return optimization->solution[solIdx]->variables->other[iOther]->numberOfVar;
}//getAnOtherVariableResultNumberOfVar

string OSResult::getOtherVariableResultName(int solIdx, int otherIdx)
{
    if (optimization == NULL || optimization->solution == NULL)
        throw ErrorClass("No solution defined");
    int iSolutions = this->getSolutionNumber();
    if (solIdx < 0 || solIdx >= iSolutions)
        throw ErrorClass("solIdx is outside of range in routine getOtherVariableResultName()");
    if (optimization->solution[solIdx] == NULL) return "";
    if (optimization->solution[solIdx]->variables == NULL) return "";
    if (optimization->solution[solIdx]->variables->other == NULL) return "";
    if (otherIdx < 0 || otherIdx >= optimization->solution[solIdx]->variables->numberOfOtherVariableResults)
        throw ErrorClass("otherIdx is outside of range in routine getOtherVariableResultName()");
    if (optimization->solution[solIdx]->variables->other[ otherIdx] == NULL) return "";
    return optimization->solution[solIdx]->variables->other[ otherIdx]->name;
}//getOtherVariableResultName

string OSResult::getOtherVariableResultType(int solIdx, int otherIdx)
{
    if (optimization == NULL || optimization->solution == NULL)
        throw ErrorClass("No solution defined");
    int iSolutions = this->getSolutionNumber();
    if (solIdx < 0 || solIdx >= iSolutions)
        throw ErrorClass("solIdx is outside of range in routine getOtherVariableResultType()");
    if (optimization->solution[solIdx] == NULL) return "";
    if (optimization->solution[solIdx]->variables == NULL) return "";
    if (optimization->solution[solIdx]->variables->other == NULL) return "";
    if (otherIdx < 0 || otherIdx >= optimization->solution[solIdx]->variables->numberOfOtherVariableResults)
        throw ErrorClass("otherIdx is outside of range in routine getOtherVariableResultType()");
    if (optimization->solution[solIdx]->variables->other[ otherIdx] == NULL) return "";
    return optimization->solution[solIdx]->variables->other[ otherIdx]->type;
}//getOtherVariableResultType

string OSResult::getOtherVariableResultValue(int solIdx, int otherIdx)
{
    if (optimization == NULL || optimization->solution == NULL)
        throw ErrorClass("No solution defined");
    int iSolutions = this->getSolutionNumber();
    if (solIdx < 0 || solIdx >= iSolutions)
        throw ErrorClass("solIdx is outside of range in routine getOtherVariableResultValue()");
    if (optimization->solution[solIdx] == NULL) return "";
    if (optimization->solution[solIdx]->variables == NULL) return "";
    if (optimization->solution[solIdx]->variables->other == NULL) return "";
    if (otherIdx < 0 || otherIdx >= optimization->solution[solIdx]->variables->numberOfOtherVariableResults)
        throw ErrorClass("otherIdx is outside of range in routine getOtherVariableResultValue()");
    if (optimization->solution[solIdx]->variables->other[ otherIdx] == NULL) return "";
    return optimization->solution[solIdx]->variables->other[ otherIdx]->value;
}//getOtherVariableResultValue

string OSResult::getOtherVariableResultDescription(int solIdx, int otherIdx)
{
    if (optimization == NULL || optimization->solution == NULL)
        throw ErrorClass("No solution defined");
    int iSolutions = this->getSolutionNumber();
    if (solIdx < 0 || solIdx >= iSolutions)
        throw ErrorClass("solIdx is outside of range in routine getOtherVariableResultDescription()");
    if (optimization->solution[solIdx] == NULL) return "";
    if (optimization->solution[solIdx]->variables == NULL) return "";
    if (optimization->solution[solIdx]->variables->other == NULL) return "";
    if (otherIdx < 0 || otherIdx >= optimization->solution[solIdx]->variables->numberOfOtherVariableResults)
        throw ErrorClass("otherIdx is outside of range in routine getOtherVariableResultDescription()");
    if (optimization->solution[solIdx]->variables->other[ otherIdx] == NULL) return "";
    return optimization->solution[solIdx]->variables->other[ otherIdx]->description;
}//getOtherVariableResultDescription

int OSResult::getOtherVariableResultNumberOfVar(int solIdx, int otherIdx)
{
    if (optimization == NULL || optimization->solution == NULL)
        throw ErrorClass("No solution defined");
    int iSolutions = this->getSolutionNumber();
    if (solIdx < 0 || solIdx >= iSolutions)
        throw ErrorClass("solIdx is outside of range in routine getOtherVariableResultNumberOfVar()");
    if (optimization->solution[solIdx] == NULL) return -1;
    if (optimization->solution[solIdx]->variables == NULL) return -1;
    if (optimization->solution[solIdx]->variables->other == NULL) return -1;
    if (otherIdx < 0 || otherIdx >= optimization->solution[solIdx]->variables->numberOfOtherVariableResults)
        throw ErrorClass("otherIdx is outside of range in routine getOtherVariableResultNumberOfVar()");
    if (optimization->solution[solIdx]->variables->other[ otherIdx] == NULL) return -1;
    return optimization->solution[solIdx]->variables->other[ otherIdx]->numberOfVar;
}//getOtherVariableResultNumberOfVar

int OSResult::getOtherVariableResultVarIdx(int solIdx, int otherIdx, int varIdx)
{
    if (optimization == NULL || optimization->solution == NULL)
        throw ErrorClass("No solution defined");
    int iSolutions = this->getSolutionNumber();
    if (solIdx < 0 || solIdx >= iSolutions)
        throw ErrorClass("solIdx is outside of range in routine getOtherVariableResultVarIdx()");
    if (optimization->solution[solIdx] == NULL) return -1;
    if (optimization->solution[solIdx]->variables == NULL) return -1;
    if (optimization->solution[solIdx]->variables->other == NULL) return -1;
    if (otherIdx < 0 || otherIdx >= optimization->solution[solIdx]->variables->numberOfOtherVariableResults)
        throw ErrorClass("otherIdx is outside of range in routine getOtherVariableResultVarIdx()");
    if (optimization->solution[solIdx]->variables->other[ otherIdx] == NULL) return -1;
    if (optimization->solution[solIdx]->variables->other[ otherIdx]->var == NULL) return -1;
    if (varIdx < 0 || varIdx >= optimization->solution[solIdx]->variables->other[ otherIdx]->numberOfVar)
        throw ErrorClass("varIdx is outside of range in routine getOtherVariableResultVarIdx()");
    return optimization->solution[solIdx]->variables->other[otherIdx]->var[varIdx]->idx;
}//getOtherVariableResultVarIdx

string OSResult::getOtherVariableResultVar(int solIdx, int otherIdx, int varIdx)
{
    if (optimization == NULL || optimization->solution == NULL)
        throw ErrorClass("No solution defined");
    int iSolutions = this->getSolutionNumber();
    if (solIdx < 0 || solIdx >= iSolutions)
        throw ErrorClass("solIdx is outside of range in routine getOtherVariableResultVar()");
    if (optimization->solution[solIdx] == NULL) return "";
    if (optimization->solution[solIdx]->variables == NULL) return "";
    if (optimization->solution[solIdx]->variables->other == NULL) return "";
    if (otherIdx < 0 || otherIdx >= optimization->solution[solIdx]->variables->numberOfOtherVariableResults)
        throw ErrorClass("otherIdx is outside of range in routine getOtherVariableResultVar()");
    if (optimization->solution[solIdx]->variables->other[ otherIdx] == NULL) return "";
    if (optimization->solution[solIdx]->variables->other[ otherIdx]->var == NULL) return "";
    if (varIdx < 0 || varIdx >= optimization->solution[solIdx]->variables->other[ otherIdx]->numberOfVar)
        throw ErrorClass("varIdx is outside of range in routine getOtherVariableResultVar()");
    return optimization->solution[solIdx]->variables->other[otherIdx]->var[varIdx]->value;
}//getOtherVariableResultVar


int OSResult::getOtherVariableResultNumberOfEnumerations(int solIdx, int otherIdx)
{
    if (optimization == NULL || optimization->solution == NULL)
        throw ErrorClass("No solution defined");
    int iSolutions = this->getSolutionNumber();
    if (solIdx < 0 || solIdx >= iSolutions)
        throw ErrorClass("solIdx is outside of range in routine getOtherVariableResultNumberOfEnumerations()");
    if (optimization->solution[solIdx] == NULL) return -1;
    if (optimization->solution[solIdx]->variables == NULL) return -1;
    if (optimization->solution[solIdx]->variables->other == NULL) return -1;
    if (otherIdx < 0 || otherIdx >= optimization->solution[solIdx]->variables->numberOfOtherVariableResults)
        throw ErrorClass("otherIdx is outside of range in routine getOtherVariableResultNumberOfEnumerations()");
    if (optimization->solution[solIdx]->variables->other[ otherIdx] == NULL) return -1;
    return optimization->solution[solIdx]->variables->other[ otherIdx]->numberOfEnumerations;
}//getOtherVariableResultNumberOfEnumerations

std::string OSResult::getOtherVariableResultArrayType(int solIdx,int otherIdx)
{
    if (optimization == NULL || optimization->solution == NULL)
        throw ErrorClass("No solution defined");
    int iSolutions = this->getSolutionNumber();
    if (solIdx < 0 || solIdx >= iSolutions)
        throw ErrorClass("solIdx is outside of range in routine getOtherVariableResultNumberOfEnumerations()");
    if (optimization->solution[solIdx] == NULL) return "";
    if (optimization->solution[solIdx]->variables == NULL) return "";
    if (optimization->solution[solIdx]->variables->other == NULL) return "";
    if (otherIdx < 0 || otherIdx >= optimization->solution[solIdx]->variables->numberOfOtherVariableResults)
        throw ErrorClass("otherIdx is outside of range in routine getOtherVariableResultNumberOfEnumerations()");
    if (optimization->solution[solIdx]->variables->other[ otherIdx] == NULL) return "";

    if (optimization->solution[solIdx]->variables->other[ otherIdx]->var != NULL) 
        return optimization->solution[solIdx]->variables->other[ otherIdx]->varType;
    else if (optimization->solution[solIdx]->variables->other[ otherIdx]->enumeration != NULL) 
        return optimization->solution[solIdx]->variables->other[ otherIdx]->enumType;
    else
        return "";
}//getOtherVariableResultArrayType


std::string OSResult::getOtherVariableResultEnumerationValue(int solIdx,int otherIdx, int enumIdx)
{
    if (optimization == NULL || optimization->solution == NULL)
        throw ErrorClass("No solution defined");
    if (solIdx < 0 || solIdx >= optimization->numberOfSolutions)
        throw ErrorClass("solIdx is outside of range in routine getOtherVariableResultEnumerationValue()");
    if (optimization->solution[solIdx] == NULL)
        throw ErrorClass("solution never defined in routine getOtherVariableResultEnumerationValue()");

    if (optimization->solution[solIdx]->variables == NULL)
        throw ErrorClass("variables result never defined in routine getOtherVariableResultEnumerationValue()");
    if (otherIdx < 0 || otherIdx >= optimization->solution[solIdx]->variables->numberOfOtherVariableResults)
        throw ErrorClass("otherIdx is outside of range in routine getOtherVariableResultEnumerationValue()");
    if (optimization->solution[solIdx]->variables->other == NULL)
        throw ErrorClass("other variable array never defined in routine getOtherVariableResultEnumerationValue()");
    if (optimization->solution[solIdx]->variables->other[otherIdx] == NULL)
        throw ErrorClass("other variable result never defined in routine getOtherVariableResultEnumerationValue()");
    if (optimization->solution[solIdx]->variables->other[otherIdx]->enumeration == NULL)
        throw ErrorClass("enumerations array never defined in routine getOtherVariableResultEnumerationValue()");
    if (enumIdx < 0 || enumIdx >= optimization->solution[solIdx]->variables->other[otherIdx]->numberOfEnumerations)
        throw ErrorClass("enumIdx is outside of range in routine getOtherVariableResultEnumerationValue()");
    if (optimization->solution[solIdx]->variables->other[otherIdx]->enumeration[enumIdx] == NULL)
        throw ErrorClass("enumeration never defined in routine getOtherVariableResultEnumerationValue()");

    return optimization->solution[solIdx]->variables->other[otherIdx]->enumeration[enumIdx]->value;
}//getOtherVariableResultEnumerationValue

std::string OSResult::getOtherVariableResultEnumerationDescription(int solIdx,int otherIdx, int enumIdx)
{
    if (optimization == NULL || optimization->solution == NULL)
        throw ErrorClass("No solution defined");
    if (solIdx < 0 || solIdx >= optimization->numberOfSolutions)
        throw ErrorClass("solIdx is outside of range in routine getOtherVariableResultEnumerationDescription()");
    if (optimization->solution[solIdx] == NULL)
        throw ErrorClass("solution never defined in routine getOtherVariableResultEnumerationDescription()");

    if (optimization->solution[solIdx]->variables == NULL)
        throw ErrorClass("variables result never defined in routine getOtherVariableResultEnumerationDescription()");
    if (otherIdx < 0 || otherIdx >= optimization->solution[solIdx]->variables->numberOfOtherVariableResults)
        throw ErrorClass("otherIdx is outside of range in routine getOtherVariableResultEnumerationDescription()");
    if (optimization->solution[solIdx]->variables->other == NULL)
        throw ErrorClass("other variable array never defined in routine getOtherVariableResultEnumerationDescription()");
    if (optimization->solution[solIdx]->variables->other[otherIdx] == NULL)
        throw ErrorClass("other variable result never defined in routine getOtherVariableResultEnumerationDescription()");
    if (optimization->solution[solIdx]->variables->other[otherIdx]->enumeration == NULL)
        throw ErrorClass("enumerations array never defined in routine getOtherVariableResultEnumerationDescription()");
    if (enumIdx < 0 || enumIdx >= optimization->solution[solIdx]->variables->other[otherIdx]->numberOfEnumerations)
        throw ErrorClass("enumIdx is outside of range in routine getOtherVariableResultEnumerationDescription()");
    if (optimization->solution[solIdx]->variables->other[otherIdx]->enumeration[enumIdx] == NULL)
        throw ErrorClass("enumeration never defined in routine getOtherVariableResultEnumerationDescription()");

    return optimization->solution[solIdx]->variables->other[otherIdx]->enumeration[enumIdx]->description;
}//getOtherVariableResultEnumerationDescription

int OSResult::getOtherVariableResultEnumerationNumberOfEl(int solIdx,int otherIdx, int enumIdx)
{
    if (optimization == NULL || optimization->solution == NULL)
        throw ErrorClass("No solution defined");
    if (solIdx < 0 || solIdx >= optimization->numberOfSolutions)
        throw ErrorClass("solIdx is outside of range in routine getOtherVariableResultEnumerationNumberOfEl()");
    if (optimization->solution[solIdx] == NULL)
        throw ErrorClass("solution never defined in routine getOtherVariableResultEnumerationNumberOfEl()");

    if (optimization->solution[solIdx]->variables == NULL)
        throw ErrorClass("variables result never defined in routine getOtherVariableResultEnumerationNumberOfEl()");
    if (otherIdx < 0 || otherIdx >= optimization->solution[solIdx]->variables->numberOfOtherVariableResults)
        throw ErrorClass("otherIdx is outside of range in routine getOtherVariableResultEnumerationNumberOfEl()");
    if (optimization->solution[solIdx]->variables->other == NULL)
        throw ErrorClass("other variable array never defined in routine getOtherVariableResultEnumerationNumberOfEl()");
    if (optimization->solution[solIdx]->variables->other[otherIdx] == NULL)
        throw ErrorClass("other variable result never defined in routine getOtherVariableResultEnumerationNumberOfEl()");
    if (optimization->solution[solIdx]->variables->other[otherIdx]->enumeration == NULL)
        throw ErrorClass("enumerations array never defined in routine getOtherVariableResultEnumerationNumberOfEl()");
    if (enumIdx < 0 || enumIdx >= optimization->solution[solIdx]->variables->other[otherIdx]->numberOfEnumerations)
        throw ErrorClass("enumIdx is outside of range in routine getOtherVariableResultEnumerationNumberOfEl()");
    if (optimization->solution[solIdx]->variables->other[otherIdx]->enumeration[enumIdx] == NULL)
        throw ErrorClass("enumeration never defined in routine getOtherVariableResultEnumerationNumberOfEl()");

    return optimization->solution[solIdx]->variables->other[otherIdx]->enumeration[enumIdx]->numberOfEl;
}//getOtherVariableResultEnumerationNumberOfEl

int OSResult::getOtherVariableResultEnumerationEl(int solIdx,int otherIdx, int enumIdx, int j)
{
    if (optimization == NULL || optimization->solution == NULL)
        throw ErrorClass("No solution defined");
    if (solIdx < 0 || solIdx >= optimization->numberOfSolutions)
        throw ErrorClass("solIdx is outside of range in routine getOtherVariableResultEnumerationEl()");
    if (optimization->solution[solIdx] == NULL)
        throw ErrorClass("solution never defined in routine getOtherVariableResultEnumerationEl()");

    if (optimization->solution[solIdx]->variables == NULL)
        throw ErrorClass("variables result never defined in routine getOtherVariableResultEnumerationEl()");
    if (otherIdx < 0 || otherIdx >= optimization->solution[solIdx]->variables->numberOfOtherVariableResults)
        throw ErrorClass("otherIdx is outside of range in routine getOtherVariableResultEnumerationEl()");
    if (optimization->solution[solIdx]->variables->other == NULL)
        throw ErrorClass("other variable array never defined in routine getOtherVariableResultEnumerationEl()");
    if (optimization->solution[solIdx]->variables->other[otherIdx] == NULL)
        throw ErrorClass("other variable result never defined in routine getOtherVariableResultEnumerationEl()");
    if (optimization->solution[solIdx]->variables->other[otherIdx]->enumeration == NULL)
        throw ErrorClass("enumerations array never defined in routine getOtherVariableResultEnumerationEl()");
    if (enumIdx < 0 || enumIdx >= optimization->solution[solIdx]->variables->other[otherIdx]->numberOfEnumerations)
        throw ErrorClass("enumIdx is outside of range in routine getOtherVariableResultEnumerationEl()");
    if (optimization->solution[solIdx]->variables->other[otherIdx]->enumeration[enumIdx] == NULL)
        throw ErrorClass("enumeration never defined in routine getOtherVariableResultEnumerationEl()");

    return optimization->solution[solIdx]->variables->other[otherIdx]->enumeration[enumIdx]->getEl(j);
}//getOtherVariableResultEnumerationEl


int OSResult::getOtherVariableResultArrayDense(int solIdx, int otherIdx, std::string* resultArray, int dim)
{
    int i, j;
    if (optimization == NULL || optimization->solution == NULL)
        throw ErrorClass("No solution defined");
    if (solIdx < 0 || solIdx >= optimization->numberOfSolutions)
        throw ErrorClass("solIdx is outside of range in routine getOtherVariableResultArrayDense()");
    if (optimization->solution[solIdx] == NULL)
        throw ErrorClass("solution never defined in routine getOtherVariableResultArrayDense()");
    if (optimization->solution[solIdx]->variables == NULL)
        throw ErrorClass("variables result never defined in routine getOtherVariableResultArrayDense()");
    if (otherIdx < 0 || otherIdx >= optimization->solution[solIdx]->variables->numberOfOtherVariableResults)
        throw ErrorClass("otherIdx is outside of range in routine getOtherVariableResultArrayDense()");
    if (optimization->solution[solIdx]->variables->other == NULL)
        throw ErrorClass("other variable array never defined in routine getOtherVariableResultArrayDense()");
    if (optimization->solution[solIdx]->variables->other[otherIdx] == NULL)
        throw ErrorClass("other variable result never defined in routine getOtherVariableResultArrayDense()");

    if (optimization->solution[solIdx]->variables->other[otherIdx]->enumeration == NULL)
	{
        if (optimization->solution[solIdx]->variables->other[otherIdx]->var == NULL)
            return 0; // neither <var> nor <enumeration>
        else // there is a <var> array
        {
            for (i=0; i<dim; i++)
                resultArray[i] = "";
            for (i=0; i<optimization->solution[solIdx]->variables->other[otherIdx]->numberOfVar; i++)
            {
                j = optimization->solution[solIdx]->variables->other[otherIdx]->var[i]->idx;
                if (j >= 0 && j < dim)
                    resultArray[j] = optimization->solution[solIdx]->variables->other[otherIdx]->var[i]->value;
                else
                    throw ErrorClass("variable index out of range in routine getOtherVariableResultArrayDense()");
            }
            return dim;
        }
    }
    else // there is an <enumeration> array
    {
        std::string val;
        int n,k;

        for (j=0; j<dim; j++)
            resultArray[j] = "";

        for (i=0; i<optimization->solution[solIdx]->variables->other[otherIdx]->numberOfEnumerations; i++)
        {
            val = optimization->solution[solIdx]->variables->other[otherIdx]->enumeration[i]->value;
            n   = optimization->solution[solIdx]->variables->other[otherIdx]->enumeration[i]->numberOfEl;
            for (j=0; j<n; j++)
            {
                k = optimization->solution[solIdx]->variables->other[otherIdx]->enumeration[i]->el[j];
                if (j >= 0 && j < dim)
                    resultArray[k] = val;
                else
                    throw ErrorClass("variable index out of range in routine getOtherVariableResultArrayDense()");
            }
        }
        return dim;
    }
    return -1;
}//getOtherVariableResultArrayDense

/*
int* OSResult::getOtherOptionResultName(int solIdx, int otherIdx, char object, int status)
{
	if (optimization == NULL || optimization->solution == NULL)
		throw ErrorClass("No solution defined");
	if (solIdx < 0 || solIdx >= optimization->numberOfSolutions)
		throw ErrorClass("solIdx is outside of range in routine getOtherOptionResultEl()");
	if (optimization->solution[solIdx] == NULL)
		throw ErrorClass("solution never defined in routine getOtherOptionResultEl()");

	switch (object)
	{
		case ENUM_PROBLEM_COMPONENT_variables:
		{
			if (optimization->solution[solIdx]->variables == NULL)
				throw ErrorClass("variables result never defined in routine getOtherOptionResultEl()");
			if (optimization->solution[solIdx]->variables->other == NULL)
				throw ErrorClass("other variable array never defined in routine getOtherOptionResultEl()");
			if (otherIdx < 0 || otherIdx >= optimization->solution[solIdx]->variables->numberOfOtherVariableResults)
				throw ErrorClass("otherIdx is outside of range in routine getOtherOptionResultEl()");
			return optimization->solution[solIdx]->variables->other[otherIdx]->getEl(status);
		}
		case ENUM_PROBLEM_COMPONENT_objectives:
		{
			if (optimization->solution[solIdx]->objectives == NULL)
				throw ErrorClass("objectives result never defined in routine getOtherOptionResultEl()");
			if (optimization->solution[solIdx]->objectives->other == NULL)
				throw ErrorClass("other objective array never defined in routine getOtherOptionResultEl()");
			if (otherIdx < 0 || otherIdx >= optimization->solution[solIdx]->objectives->numberOfOtherObjectiveResults)
				throw ErrorClass("otherIdx is outside of range in routine getOtherOptionResultEl()");
			return optimization->solution[solIdx]->objectives->other[otherIdx]->getEl(status);
		}
		case ENUM_PROBLEM_COMPONENT_constraints:
		{
			if (optimization->solution[solIdx]->constraints == NULL)
				throw ErrorClass("constraints result never defined in routine getOtherOptionResultEl()");
			if (optimization->solution[solIdx]->constraints->other == NULL)
				throw ErrorClass("other constraint array never defined in routine getOtherOptionResultEl()");
			if (otherIdx < 0 || otherIdx >= optimization->solution[solIdx]->constraints->numberOfOtherConstraintResults)
				throw ErrorClass("otherIdx is outside of range in routine getOtherOptionResultEl()");
			return optimization->solution[solIdx]->constraints->other[otherIdx]->getEl(status);
		}
		default:
			throw ErrorClass("target object not implemented in getOtherOptionResultEl");
	}
}//getOtherOptionResultEl


int* OSResult::getOtherOptionResultEl(int solIdx, int otherIdx, char object, int status)
{
	if (optimization == NULL || optimization->solution == NULL)
		throw ErrorClass("No solution defined");
	if (solIdx < 0 || solIdx >= optimization->numberOfSolutions)
		throw ErrorClass("solIdx is outside of range in routine getOtherOptionResultEl()");
	if (optimization->solution[solIdx] == NULL)
		throw ErrorClass("solution never defined in routine getOtherOptionResultEl()");

	switch (object)
	{
		case ENUM_PROBLEM_COMPONENT_variables:
		{
			if (optimization->solution[solIdx]->variables == NULL)
				throw ErrorClass("variables result never defined in routine getOtherOptionResultEl()");
			if (optimization->solution[solIdx]->variables->other == NULL)
				throw ErrorClass("other variable array never defined in routine getOtherOptionResultEl()");
			if (otherIdx < 0 || otherIdx >= optimization->solution[solIdx]->variables->numberOfOtherVariableResults)
				throw ErrorClass("otherIdx is outside of range in routine getOtherOptionResultEl()");
			return optimization->solution[solIdx]->variables->other[otherIdx]->getEl(status);
		}
		case ENUM_PROBLEM_COMPONENT_objectives:
		{
			if (optimization->solution[solIdx]->objectives == NULL)
				throw ErrorClass("objectives result never defined in routine getOtherOptionResultEl()");
			if (optimization->solution[solIdx]->objectives->other == NULL)
				throw ErrorClass("other objective array never defined in routine getOtherOptionResultEl()");
			if (otherIdx < 0 || otherIdx >= optimization->solution[solIdx]->objectives->numberOfOtherObjectiveResults)
				throw ErrorClass("otherIdx is outside of range in routine getOtherOptionResultEl()");
			return optimization->solution[solIdx]->objectives->other[otherIdx]->getEl(status);
		}
		case ENUM_PROBLEM_COMPONENT_constraints:
		{
			if (optimization->solution[solIdx]->constraints == NULL)
				throw ErrorClass("constraints result never defined in routine getOtherOptionResultEl()");
			if (optimization->solution[solIdx]->constraints->other == NULL)
				throw ErrorClass("other constraint array never defined in routine getOtherOptionResultEl()");
			if (otherIdx < 0 || otherIdx >= optimization->solution[solIdx]->constraints->numberOfOtherConstraintResults)
				throw ErrorClass("otherIdx is outside of range in routine getOtherOptionResultEl()");
			return optimization->solution[solIdx]->constraints->other[otherIdx]->getEl(status);
		}
		default:
			throw ErrorClass("target object not implemented in getOtherOptionResultEl");
	}
}//getOtherOptionResultEl


int* OSResult::getOtherOptionResultEl(int solIdx, int otherIdx, char object, int status)
{
	if (optimization == NULL || optimization->solution == NULL)
		throw ErrorClass("No solution defined");
	if (solIdx < 0 || solIdx >= optimization->numberOfSolutions)
		throw ErrorClass("solIdx is outside of range in routine getOtherOptionResultEl()");
	if (optimization->solution[solIdx] == NULL)
		throw ErrorClass("solution never defined in routine getOtherOptionResultEl()");

	switch (object)
	{
		case ENUM_PROBLEM_COMPONENT_variables:
		{
			if (optimization->solution[solIdx]->variables == NULL)
				throw ErrorClass("variables result never defined in routine getOtherOptionResultEl()");
			if (optimization->solution[solIdx]->variables->other == NULL)
				throw ErrorClass("other variable array never defined in routine getOtherOptionResultEl()");
			if (otherIdx < 0 || otherIdx >= optimization->solution[solIdx]->variables->numberOfOtherVariableResults)
				throw ErrorClass("otherIdx is outside of range in routine getOtherOptionResultEl()");
			return optimization->solution[solIdx]->variables->other[otherIdx]->getEl(status);
		}
		case ENUM_PROBLEM_COMPONENT_objectives:
		{
			if (optimization->solution[solIdx]->objectives == NULL)
				throw ErrorClass("objectives result never defined in routine getOtherOptionResultEl()");
			if (optimization->solution[solIdx]->objectives->other == NULL)
				throw ErrorClass("other objective array never defined in routine getOtherOptionResultEl()");
			if (otherIdx < 0 || otherIdx >= optimization->solution[solIdx]->objectives->numberOfOtherObjectiveResults)
				throw ErrorClass("otherIdx is outside of range in routine getOtherOptionResultEl()");
			return optimization->solution[solIdx]->objectives->other[otherIdx]->getEl(status);
		}
		case ENUM_PROBLEM_COMPONENT_constraints:
		{
			if (optimization->solution[solIdx]->constraints == NULL)
				throw ErrorClass("constraints result never defined in routine getOtherOptionResultEl()");
			if (optimization->solution[solIdx]->constraints->other == NULL)
				throw ErrorClass("other constraint array never defined in routine getOtherOptionResultEl()");
			if (otherIdx < 0 || otherIdx >= optimization->solution[solIdx]->constraints->numberOfOtherConstraintResults)
				throw ErrorClass("otherIdx is outside of range in routine getOtherOptionResultEl()");
			return optimization->solution[solIdx]->constraints->other[otherIdx]->getEl(status);
		}
		default:
			throw ErrorClass("target object not implemented in getOtherOptionResultEl");
	}
}//getOtherOptionResultEl


int* OSResult::getOtherOptionResultEl(int solIdx, int otherIdx, char object, int status)
{
	if (optimization == NULL || optimization->solution == NULL)
		throw ErrorClass("No solution defined");
	if (solIdx < 0 || solIdx >= optimization->numberOfSolutions)
		throw ErrorClass("solIdx is outside of range in routine getOtherOptionResultEl()");
	if (optimization->solution[solIdx] == NULL)
		throw ErrorClass("solution never defined in routine getOtherOptionResultEl()");

	switch (object)
	{
		case ENUM_PROBLEM_COMPONENT_variables:
		{
			if (optimization->solution[solIdx]->variables == NULL)
				throw ErrorClass("variables result never defined in routine getOtherOptionResultEl()");
			if (optimization->solution[solIdx]->variables->other == NULL)
				throw ErrorClass("other variable array never defined in routine getOtherOptionResultEl()");
			if (otherIdx < 0 || otherIdx >= optimization->solution[solIdx]->variables->numberOfOtherVariableResults)
				throw ErrorClass("otherIdx is outside of range in routine getOtherOptionResultEl()");
			return optimization->solution[solIdx]->variables->other[otherIdx]->getEl(status);
		}
		case ENUM_PROBLEM_COMPONENT_objectives:
		{
			if (optimization->solution[solIdx]->objectives == NULL)
				throw ErrorClass("objectives result never defined in routine getOtherOptionResultEl()");
			if (optimization->solution[solIdx]->objectives->other == NULL)
				throw ErrorClass("other objective array never defined in routine getOtherOptionResultEl()");
			if (otherIdx < 0 || otherIdx >= optimization->solution[solIdx]->objectives->numberOfOtherObjectiveResults)
				throw ErrorClass("otherIdx is outside of range in routine getOtherOptionResultEl()");
			return optimization->solution[solIdx]->objectives->other[otherIdx]->getEl(status);
		}
		case ENUM_PROBLEM_COMPONENT_constraints:
		{
			if (optimization->solution[solIdx]->constraints == NULL)
				throw ErrorClass("constraints result never defined in routine getOtherOptionResultEl()");
			if (optimization->solution[solIdx]->constraints->other == NULL)
				throw ErrorClass("other constraint array never defined in routine getOtherOptionResultEl()");
			if (otherIdx < 0 || otherIdx >= optimization->solution[solIdx]->constraints->numberOfOtherConstraintResults)
				throw ErrorClass("otherIdx is outside of range in routine getOtherOptionResultEl()");
			return optimization->solution[solIdx]->constraints->other[otherIdx]->getEl(status);
		}
		default:
			throw ErrorClass("target object not implemented in getOtherOptionResultEl");
	}
}//getOtherOptionResultEl
*/

int OSResult::getNumberOfObjValues(int solIdx)
{
    if (optimization == NULL || optimization->solution == NULL)
        throw ErrorClass("No solution defined");
    int iSolutions = this->getSolutionNumber();
    if (solIdx < 0 || solIdx >= iSolutions)
        throw ErrorClass("solIdx is outside of range in routine getNumberOfObjValues()");
    if (optimization->solution[solIdx] == NULL) return -1;
    if (optimization->solution[solIdx]->objectives == NULL) return -1;
    if (optimization->solution[solIdx]->objectives->values == NULL) return -1;
    return optimization->solution[solIdx]->objectives->values->numberOfObj;
}//getNumberOfObjValues

int OSResult::getObjValueIdx(int solIdx, int objIdx)
{
    if (optimization == NULL || optimization->solution == NULL)
        throw ErrorClass("No solution defined");
    int iSolutions = this->getSolutionNumber();
    if (solIdx < 0 || solIdx >= iSolutions)
        throw ErrorClass("solIdx is outside of range in routine getObjValueIdx()");
    if (optimization->solution[solIdx] == NULL) return 0;
    if (optimization->solution[solIdx]->objectives == NULL) return 0;
    if (optimization->solution[solIdx]->objectives->values == NULL) return 0;
    if (objIdx < 0 || objIdx >= optimization->solution[solIdx]->objectives->values->numberOfObj)
        throw ErrorClass("objIdx is outside of range in routine getObjValueIdx()");
    return optimization->solution[solIdx]->objectives->values->obj[objIdx]->idx;
}//getObjValueIdx

std::string OSResult::getObjValueName(int solIdx, int objIdx)
{
    if (optimization == NULL || optimization->solution == NULL)
        throw ErrorClass("No solution defined");
    int iSolutions = this->getSolutionNumber();
    if (solIdx < 0 || solIdx >= iSolutions)
        throw ErrorClass("solIdx is outside of range in routine getObjValueIdx()");
    if (optimization->solution[solIdx] == NULL) return "";
    if (optimization->solution[solIdx]->objectives == NULL) return "";
    if (optimization->solution[solIdx]->objectives->values == NULL) return "";
    if (objIdx < 0 || objIdx >= optimization->solution[solIdx]->objectives->values->numberOfObj)
        throw ErrorClass("objIdx is outside of range in routine getObjValueIdx()");
    return optimization->solution[solIdx]->objectives->values->obj[objIdx]->name;
}//getObjValueName

double OSResult::getObjValue(int solIdx, int objIdx)
{
    if (optimization == NULL || optimization->solution == NULL)
        throw ErrorClass("No solution defined");
    int iSolutions = this->getSolutionNumber();
    if (solIdx < 0 || solIdx >= iSolutions)
        throw ErrorClass("solIdx is outside of range in routine getObjValue()");
    if (optimization->solution[solIdx] == NULL) return OSNaN();
    if (optimization->solution[solIdx]->objectives == NULL) return OSNaN();
    if (optimization->solution[solIdx]->objectives->values == NULL) return OSNaN();
    if (objIdx < 0 || objIdx >= optimization->solution[solIdx]->objectives->values->numberOfObj)
        throw ErrorClass("objIdx is outside of range in routine getObjValue()");
    return optimization->solution[solIdx]->objectives->values->obj[objIdx]->value;
}//getObjValue

double OSResult::getOptimalObjValue(int objIdx, int solIdx)
{
    if (this->optimization == NULL || this->optimization->solution == NULL)
        throw ErrorClass("No optimization or solution object defined");
    int iSolutions = this->getSolutionNumber();
    for (int i = 0; i < iSolutions; i++)
    {
        if(i != solIdx) continue;
        if(this->optimization->solution[i]->targetObjectiveIdx != objIdx) continue;
        if((this->optimization->solution[i]->status->type.find("ptimal") != string::npos ) ||
                this->optimization->solution[i]->status->type.compare("globallyOptimal") == 0)
        {
            if ((this->optimization->solution[i]->objectives != NULL) && 
                (this->optimization->solution[i]->objectives->values != NULL) && 
                (this->optimization->solution[i]->objectives->values->obj != NULL) ) 
                return this->optimization->solution[i]->objectives->values->obj[ (objIdx >= 0 ? objIdx : -objIdx -1) ]->value;
            else
            {
                throw ErrorClass("There is no optimal solution");
            }
        }
        else
        {
            throw ErrorClass("There is no optimal solution");
        }
    }
    throw ErrorClass("There is no optimal solution");
}//getOptimalObjValue

int OSResult::getNumberOfOtherObjectiveResults(int solIdx)
{
    if (optimization == NULL || optimization->solution == NULL)
        throw ErrorClass("No solution defined");
    int iSolutions = this->getSolutionNumber();
    if (solIdx < 0 || solIdx >= iSolutions)
        throw ErrorClass("solIdx is outside of range in routine getNumberOfOtherObjectiveResults()");
    if (optimization->solution[solIdx] == NULL)
        throw ErrorClass("solution was never defined in routine getNumberOfOtherObjectiveResults()");
    if (optimization->solution[solIdx]->objectives == NULL) return 0;
    if (optimization->solution[solIdx]->objectives->other == NULL) return 0;
    return optimization->solution[solIdx]->objectives->numberOfOtherObjectiveResults;
}//getNumberOfOtherObjectiveResults


string OSResult::getOtherObjectiveResultName(int solIdx, int otherIdx)
{
    if (optimization == NULL || optimization->solution == NULL)
        throw ErrorClass("No solution defined");
    int iSolutions = this->getSolutionNumber();
    if (solIdx < 0 || solIdx >= iSolutions)
        throw ErrorClass("solIdx is outside of range in routine getOtherObjectiveResultName()");
    if (optimization->solution[solIdx] == NULL) return "";
    if (optimization->solution[solIdx]->objectives == NULL) return "";
    if (optimization->solution[solIdx]->objectives->other == NULL) return "";
    if (otherIdx < 0 || otherIdx >= optimization->solution[solIdx]->objectives->numberOfOtherObjectiveResults)
        throw ErrorClass("otherIdx is outside of range in routine getOtherObjectiveResultName()");
    if (optimization->solution[solIdx]->objectives->other[ otherIdx] == NULL) return "";
    return optimization->solution[solIdx]->objectives->other[ otherIdx]->name;
}//getOtherObjectiveResultName

string OSResult::getOtherObjectiveResultType(int solIdx, int otherIdx)
{
    if (optimization == NULL || optimization->solution == NULL)
        throw ErrorClass("No solution defined");
    int iSolutions = this->getSolutionNumber();
    if (solIdx < 0 || solIdx >= iSolutions)
        throw ErrorClass("solIdx is outside of range in routine getOtherObjectiveResultType()");
    if (optimization->solution[solIdx] == NULL) return "";
    if (optimization->solution[solIdx]->objectives == NULL) return "";
    if (optimization->solution[solIdx]->objectives->other == NULL) return "";
    if (otherIdx < 0 || otherIdx >= optimization->solution[solIdx]->objectives->numberOfOtherObjectiveResults)
        throw ErrorClass("otherIdx is outside of range in routine getOtherObjectiveResultType()");
    if (optimization->solution[solIdx]->objectives->other[ otherIdx] == NULL) return "";
    return optimization->solution[solIdx]->objectives->other[ otherIdx]->type;
}//getOtherObjectiveResultType

string OSResult::getOtherObjectiveResultValue(int solIdx, int otherIdx)
{
    if (optimization == NULL || optimization->solution == NULL)
        throw ErrorClass("No solution defined");
    int iSolutions = this->getSolutionNumber();
    if (solIdx < 0 || solIdx >= iSolutions)
        throw ErrorClass("solIdx is outside of range in routine getOtherObjectiveResultValue()");
    if (optimization->solution[solIdx] == NULL) return "";
    if (optimization->solution[solIdx]->objectives == NULL) return "";
    if (optimization->solution[solIdx]->objectives->other == NULL) return "";
    if (otherIdx < 0 || otherIdx >= optimization->solution[solIdx]->objectives->numberOfOtherObjectiveResults)
        throw ErrorClass("otherIdx is outside of range in routine getOtherObjectiveResultValue()");
    if (optimization->solution[solIdx]->objectives->other[ otherIdx] == NULL) return "";
    return optimization->solution[solIdx]->objectives->other[ otherIdx]->value;
}//getOtherObjectiveResultValue

string OSResult::getOtherObjectiveResultDescription(int solIdx, int otherIdx)
{
    if (optimization == NULL || optimization->solution == NULL)
        throw ErrorClass("No solution defined");
    int iSolutions = this->getSolutionNumber();
    if (solIdx < 0 || solIdx >= iSolutions)
        throw ErrorClass("solIdx is outside of range in routine getOtherObjectiveResultDescription()");
    if (optimization->solution[solIdx] == NULL) return "";
    if (optimization->solution[solIdx]->objectives == NULL) return "";
    if (optimization->solution[solIdx]->objectives->other == NULL) return "";
    if (otherIdx < 0 || otherIdx >= optimization->solution[solIdx]->objectives->numberOfOtherObjectiveResults)
        throw ErrorClass("otherIdx is outside of range in routine getOtherObjectiveResultDescription()");
    if (optimization->solution[solIdx]->objectives->other[ otherIdx] == NULL) return "";
    return optimization->solution[solIdx]->objectives->other[ otherIdx]->description;
}//getOtherObjectiveResultDescription

int OSResult::getOtherObjectiveResultNumberOfObj(int solIdx, int otherIdx)
{
    if (optimization == NULL || optimization->solution == NULL)
        throw ErrorClass("No solution defined");
    int iSolutions = this->getSolutionNumber();
    if (solIdx < 0 || solIdx >= iSolutions)
        throw ErrorClass("solIdx is outside of range in routine getOtherObjectiveResultNumberOfObj()");
    if (optimization->solution[solIdx] == NULL) return -1;
    if (optimization->solution[solIdx]->objectives == NULL) return -1;
    if (optimization->solution[solIdx]->objectives->other == NULL) return -1;
    if (otherIdx < 0 || otherIdx >= optimization->solution[solIdx]->objectives->numberOfOtherObjectiveResults)
        throw ErrorClass("otherIdx is outside of range in routine getOtherObjectiveResultNumberOfObj()");
    if (optimization->solution[solIdx]->objectives->other[ otherIdx] == NULL) return -1;
    return optimization->solution[solIdx]->objectives->other[ otherIdx]->numberOfObj;
}//getOtherObjectiveResultNumberOfObj

int OSResult::getOtherObjectiveResultObjIdx(int solIdx, int otherIdx, int objIdx)
{
    if (optimization == NULL || optimization->solution == NULL)
        throw ErrorClass("No solution defined");
    int iSolutions = this->getSolutionNumber();
    if (solIdx < 0 || solIdx >= iSolutions)
        throw ErrorClass("solIdx is outside of range in routine getOtherObjectiveResultObjIdx()");
    if (optimization->solution[solIdx] == NULL) return 0;
    if (optimization->solution[solIdx]->objectives == NULL) return 0;
    if (optimization->solution[solIdx]->objectives->other == NULL) return 0;
    if (otherIdx < 0 || otherIdx >= optimization->solution[solIdx]->objectives->numberOfOtherObjectiveResults)
        throw ErrorClass("otherIdx is outside of range in routine getOtherObjectiveResultObjIdx()");
    if (optimization->solution[solIdx]->objectives->other[ otherIdx] == NULL) return -1;
    if (optimization->solution[solIdx]->objectives->other[ otherIdx]->obj == NULL) return -1;
    if (objIdx < 0 || objIdx >= optimization->solution[solIdx]->objectives->other[ otherIdx]->numberOfObj)
        throw ErrorClass("objIdx is outside of range in routine getOtherObjectiveResultObjIdx()");
    return optimization->solution[solIdx]->objectives->other[otherIdx]->obj[objIdx]->idx;
}//getOtherObjectiveResultObjIdx

string OSResult::getOtherObjectiveResultObj(int solIdx, int otherIdx, int objIdx)
{
    if (optimization == NULL || optimization->solution == NULL)
        throw ErrorClass("No solution defined");
    int iSolutions = this->getSolutionNumber();

    if (solIdx < 0 || solIdx >= iSolutions)
        throw ErrorClass("solIdx is outside of range in routine getOtherObjectiveResultObj()");
    if (optimization->solution[solIdx] == NULL) return "";
    if (optimization->solution[solIdx]->objectives == NULL) return "";
    if (optimization->solution[solIdx]->objectives->other == NULL) return "";
    if (otherIdx < 0 || otherIdx >= optimization->solution[solIdx]->objectives->numberOfOtherObjectiveResults)
        throw ErrorClass("otherIdx is outside of range in routine getOtherObjectiveResultObj()");
    if (optimization->solution[solIdx]->objectives->other[ otherIdx] == NULL) return "";
    if (optimization->solution[solIdx]->objectives->other[ otherIdx]->obj == NULL) return "";
    if (objIdx < 0 || objIdx >= optimization->solution[solIdx]->objectives->other[ otherIdx]->numberOfObj)
        throw ErrorClass("otherIdx is outside of range in routine getOtherObjectiveResultObj()");
    return optimization->solution[solIdx]->objectives->other[otherIdx]->obj[objIdx]->value;
}//getOtherObjectiveResultObj


int OSResult::getOtherObjectiveResultNumberOfEnumerations(int solIdx, int otherIdx)
{
    if (optimization == NULL || optimization->solution == NULL)
        throw ErrorClass("No solution defined");
    int iSolutions = this->getSolutionNumber();
    if (solIdx < 0 || solIdx >= iSolutions)
        throw ErrorClass("solIdx is outside of range in routine getOtherObjectiveResultNumberOfEnumerations()");
    if (optimization->solution[solIdx] == NULL) return -1;
    if (optimization->solution[solIdx]->objectives == NULL) return -1;
    if (optimization->solution[solIdx]->objectives->other == NULL) return -1;
    if (otherIdx < 0 || otherIdx >= optimization->solution[solIdx]->objectives->numberOfOtherObjectiveResults)
        throw ErrorClass("otherIdx is outside of range in routine getOtherObjectiveResultNumberOfEnumerations()");
    if (optimization->solution[solIdx]->objectives->other[ otherIdx] == NULL) return -1;
    return optimization->solution[solIdx]->objectives->other[ otherIdx]->numberOfEnumerations;
}//getOtherObjectiveResultNumberOfEnumerations


std::string OSResult::getOtherObjectiveResultArrayType(int solIdx, int otherIdx)
{
    if (optimization == NULL || optimization->solution == NULL)
        throw ErrorClass("No solution defined");
    int iSolutions = this->getSolutionNumber();
    if (solIdx < 0 || solIdx >= iSolutions)
        throw ErrorClass("solIdx is outside of range in routine getOtherObjectiveResultArrayType()");
    if (optimization->solution[solIdx] == NULL) return "";
    if (optimization->solution[solIdx]->objectives == NULL) return "";
    if (optimization->solution[solIdx]->objectives->other == NULL) return "";
    if (otherIdx < 0 || otherIdx >= optimization->solution[solIdx]->objectives->numberOfOtherObjectiveResults)
        throw ErrorClass("otherIdx is outside of range in routine getOtherObjectiveResultArrayType()");
    if (optimization->solution[solIdx]->objectives->other[ otherIdx] == NULL) return "";

    if (optimization->solution[solIdx]->objectives->other[ otherIdx]->obj != NULL) 
        return optimization->solution[solIdx]->objectives->other[ otherIdx]->objType;
    else if (optimization->solution[solIdx]->objectives->other[ otherIdx]->enumeration != NULL) 
        return optimization->solution[solIdx]->objectives->other[ otherIdx]->enumType;
    else
        return "";
}//getOtherObjectiveResultArrayType


std::string OSResult::getOtherObjectiveResultEnumerationValue(int solIdx,int otherIdx, int enumIdx)
{
    if (optimization == NULL || optimization->solution == NULL)
        throw ErrorClass("No solution defined");
    if (solIdx < 0 || solIdx >= optimization->numberOfSolutions)
        throw ErrorClass("solIdx is outside of range in routine getOtherObjectiveResultEnumerationValue()");
    if (optimization->solution[solIdx] == NULL)
        throw ErrorClass("solution never defined in routine getOtherObjectiveResultEnumerationValue()");

    if (optimization->solution[solIdx]->objectives == NULL)
        throw ErrorClass("variables result never defined in routine getOtherObjectiveResultEnumerationValue()");
    if (otherIdx < 0 || otherIdx >= optimization->solution[solIdx]->objectives->numberOfOtherObjectiveResults)
        throw ErrorClass("otherIdx is outside of range in routine getOtherObjectiveResultEnumerationValue()");
    if (optimization->solution[solIdx]->objectives->other == NULL)
        throw ErrorClass("other variable array never defined in routine getOtherObjectiveResultEnumerationValue()");
    if (optimization->solution[solIdx]->objectives->other[otherIdx] == NULL)
        throw ErrorClass("other variable result never defined in routine getOtherObjectiveResultEnumerationValue()");
    if (optimization->solution[solIdx]->objectives->other[otherIdx]->enumeration == NULL)
        throw ErrorClass("enumerations array never defined in routine getOtherObjectiveResultEnumerationValue()");
    if (enumIdx < 0 || enumIdx >= optimization->solution[solIdx]->objectives->other[otherIdx]->numberOfEnumerations)
        throw ErrorClass("enumIdx is outside of range in routine getOtherObjectiveResultEnumerationValue()");
    if (optimization->solution[solIdx]->objectives->other[otherIdx]->enumeration[enumIdx] == NULL)
        throw ErrorClass("enumeration never defined in routine getOtherObjectiveResultEnumerationValue()");

    return optimization->solution[solIdx]->objectives->other[otherIdx]->enumeration[enumIdx]->value;
}//getOtherObjectiveResultEnumerationValue


std::string OSResult::getOtherObjectiveResultEnumerationDescription(int solIdx,int otherIdx, int enumIdx)
{
    if (optimization == NULL || optimization->solution == NULL)
        throw ErrorClass("No solution defined");
    if (solIdx < 0 || solIdx >= optimization->numberOfSolutions)
        throw ErrorClass("solIdx is outside of range in routine getOtherObjectiveResultEnumerationDescription()");
    if (optimization->solution[solIdx] == NULL)
        throw ErrorClass("solution never defined in routine getOtherObjectiveResultEnumerationDescription()");

    if (optimization->solution[solIdx]->objectives == NULL)
        throw ErrorClass("variables result never defined in routine getOtherObjectiveResultEnumerationDescription()");
    if (otherIdx < 0 || otherIdx >= optimization->solution[solIdx]->objectives->numberOfOtherObjectiveResults)
        throw ErrorClass("otherIdx is outside of range in routine getOtherObjectiveResultEnumerationDescription()");
    if (optimization->solution[solIdx]->objectives->other == NULL)
        throw ErrorClass("other variable array never defined in routine getOtherObjectiveResultEnumerationDescription()");
    if (optimization->solution[solIdx]->objectives->other[otherIdx] == NULL)
        throw ErrorClass("other variable result never defined in routine getOtherObjectiveResultEnumerationDescription()");
    if (optimization->solution[solIdx]->objectives->other[otherIdx]->enumeration == NULL)
        throw ErrorClass("enumerations array never defined in routine getOtherObjectiveResultEnumerationDescription()");
    if (enumIdx < 0 || enumIdx >= optimization->solution[solIdx]->objectives->other[otherIdx]->numberOfEnumerations)
        throw ErrorClass("enumIdx is outside of range in routine getOtherObjectiveResultEnumerationDescription()");
    if (optimization->solution[solIdx]->objectives->other[otherIdx]->enumeration[enumIdx] == NULL)
        throw ErrorClass("enumeration never defined in routine getOtherObjectiveResultEnumerationDescription()");

    return optimization->solution[solIdx]->objectives->other[otherIdx]->enumeration[enumIdx]->description;
}//getOtherObjectiveResultEnumerationDescription


int OSResult::getOtherObjectiveResultEnumerationNumberOfEl(int solIdx,int otherIdx, int enumIdx)
{
    if (optimization == NULL || optimization->solution == NULL)
        throw ErrorClass("No solution defined");
    if (solIdx < 0 || solIdx >= optimization->numberOfSolutions)
        throw ErrorClass("solIdx is outside of range in routine getOtherObjectiveResultEnumerationNumberOfEl()");
    if (optimization->solution[solIdx] == NULL)
        throw ErrorClass("solution never defined in routine getOtherObjectiveResultEnumerationNumberOfEl()");

    if (optimization->solution[solIdx]->objectives == NULL)
        throw ErrorClass("variables result never defined in routine getOtherObjectiveResultEnumerationNumberOfEl()");
    if (otherIdx < 0 || otherIdx >= optimization->solution[solIdx]->objectives->numberOfOtherObjectiveResults)
        throw ErrorClass("otherIdx is outside of range in routine getOtherObjectiveResultEnumerationNumberOfEl()");
    if (optimization->solution[solIdx]->objectives->other == NULL)
        throw ErrorClass("other variable array never defined in routine getOtherObjectiveResultEnumerationNumberOfEl()");
    if (optimization->solution[solIdx]->objectives->other[otherIdx] == NULL)
        throw ErrorClass("other variable result never defined in routine getOtherObjectiveResultEnumerationNumberOfEl()");
    if (optimization->solution[solIdx]->objectives->other[otherIdx]->enumeration == NULL)
        throw ErrorClass("enumerations array never defined in routine getOtherObjectiveResultEnumerationNumberOfEl()");
    if (enumIdx < 0 || enumIdx >= optimization->solution[solIdx]->objectives->other[otherIdx]->numberOfEnumerations)
        throw ErrorClass("enumIdx is outside of range in routine getOtherObjectiveResultEnumerationNumberOfEl()");
    if (optimization->solution[solIdx]->objectives->other[otherIdx]->enumeration[enumIdx] == NULL)
        throw ErrorClass("enumeration never defined in routine getOtherObjectiveResultEnumerationNumberOfEl()");

    return optimization->solution[solIdx]->objectives->other[otherIdx]->enumeration[enumIdx]->numberOfEl;
}//getOtherObjectiveResultEnumerationNumberOfEl


int OSResult::getOtherObjectiveResultEnumerationEl(int solIdx,int otherIdx, int enumIdx, int j)
{
    if (optimization == NULL || optimization->solution == NULL)
        throw ErrorClass("No solution defined");
    if (solIdx < 0 || solIdx >= optimization->numberOfSolutions)
        throw ErrorClass("solIdx is outside of range in routine getOtherObjectiveResultEnumerationEl()");
    if (optimization->solution[solIdx] == NULL)
        throw ErrorClass("solution never defined in routine getOtherObjectiveResultEnumerationEl()");

    if (optimization->solution[solIdx]->objectives == NULL)
        throw ErrorClass("variables result never defined in routine getOtherObjectiveResultEnumerationEl()");
    if (otherIdx < 0 || otherIdx >= optimization->solution[solIdx]->objectives->numberOfOtherObjectiveResults)
        throw ErrorClass("otherIdx is outside of range in routine getOtherObjectiveResultEnumerationEl()");
    if (optimization->solution[solIdx]->objectives->other == NULL)
        throw ErrorClass("other variable array never defined in routine getOtherObjectiveResultEnumerationEl()");
    if (optimization->solution[solIdx]->objectives->other[otherIdx] == NULL)
        throw ErrorClass("other variable result never defined in routine getOtherObjectiveResultEnumerationEl()");
    if (optimization->solution[solIdx]->objectives->other[otherIdx]->enumeration == NULL)
        throw ErrorClass("enumerations array never defined in routine getOtherObjectiveResultEnumerationEl()");
    if (enumIdx < 0 || enumIdx >= optimization->solution[solIdx]->objectives->other[otherIdx]->numberOfEnumerations)
        throw ErrorClass("enumIdx is outside of range in routine getOtherObjectiveResultEnumerationEl()");
    if (optimization->solution[solIdx]->objectives->other[otherIdx]->enumeration[enumIdx] == NULL)
        throw ErrorClass("enumeration never defined in routine getOtherObjectiveResultEnumerationEl()");

    return optimization->solution[solIdx]->objectives->other[otherIdx]->enumeration[enumIdx]->getEl(j);
}//getOtherObjectiveResultEnumerationEl


int OSResult::getOtherObjectiveResultArrayDense(int solIdx, int otherIdx, std::string* resultArray, int dim)
{
    int i, j;
    if (optimization == NULL || optimization->solution == NULL)
        throw ErrorClass("No solution defined");
    if (solIdx < 0 || solIdx >= optimization->numberOfSolutions)
        throw ErrorClass("solIdx is outside of range in routine getOtherObjectiveResultArrayDense()");
    if (optimization->solution[solIdx] == NULL)
        throw ErrorClass("solution never defined in routine getOtherObjectiveResultArrayDense()");
    if (optimization->solution[solIdx]->objectives == NULL)
        throw ErrorClass("objectives result never defined in routine getOtherObjectiveResultArrayDense()");
    if (otherIdx < 0 || otherIdx >= optimization->solution[solIdx]->objectives->numberOfOtherObjectiveResults)
        throw ErrorClass("otherIdx is outside of range in routine getOtherObjectiveResultArrayDense()");
    if (optimization->solution[solIdx]->objectives->other == NULL)
        throw ErrorClass("other objective array never defined in routine getOtherObjectiveResultArrayDense()");
    if (optimization->solution[solIdx]->objectives->other[otherIdx] == NULL)
        throw ErrorClass("other objective result never defined in routine getOtherObjectiveResultArrayDense()");

    if (optimization->solution[solIdx]->objectives->other[otherIdx]->enumeration == NULL)
	{
        if (optimization->solution[solIdx]->objectives->other[otherIdx]->obj == NULL)
            return 0; // neither <obj> nor <enumeration>
        else // there is a <obj> array
        {
            for (i=0; i<dim; i++)
                resultArray[i] = "";
            for (i=0; i<optimization->solution[solIdx]->objectives->other[otherIdx]->numberOfObj; i++)
            {
                j = -1 - optimization->solution[solIdx]->objectives->other[otherIdx]->obj[i]->idx;
                if (j >= 0 && j < dim)
                    resultArray[j] = optimization->solution[solIdx]->objectives->other[otherIdx]->obj[i]->value;
                else
                    throw ErrorClass("objective index out of range in routine getOtherObjectiveResultArrayDense()");
            }
            return dim;
        }
    }
    else // there is an <enumeration> array
    {
        std::string val;
        int n,k;

        for (j=0; j<dim; j++)
            resultArray[j] = "";

        for (i=0; i<optimization->solution[solIdx]->objectives->other[otherIdx]->numberOfEnumerations; i++)
        {
            val = optimization->solution[solIdx]->objectives->other[otherIdx]->enumeration[i]->value;
            n   = optimization->solution[solIdx]->objectives->other[otherIdx]->enumeration[i]->numberOfEl;

            for (j=0; j<n; j++)
            {
                k = -1 - optimization->solution[solIdx]->objectives->other[otherIdx]->enumeration[i]->el[j];
                if (j >= 0 && j < dim)
                    resultArray[k] = val;
                else
                    throw ErrorClass("objective index out of range in routine getOtherObjectiveResultArrayDense()");
            }
        }
        return dim;
    }
    return -1;
}//getOtherObjectiveResultArrayDense


int OSResult::getNumberOfDualValues(int solIdx)
{
    if (optimization == NULL || optimization->solution == NULL)
        throw ErrorClass("No solution defined");
    int iSolutions = this->getSolutionNumber();
    if (solIdx < 0 || solIdx >= iSolutions)
        throw ErrorClass("solIdx is outside of range in routine getNumberOfDualValues()");
    if (optimization->solution[solIdx] == NULL) return -1;
    if (optimization->solution[solIdx]->constraints == NULL) return -1;
    if (optimization->solution[solIdx]->constraints->dualValues == NULL) return -1;
    return optimization->solution[solIdx]->constraints->dualValues->numberOfCon;
}//getNumberOfDualValues

int OSResult::getDualValueIdx(int solIdx, int conIdx)
{
    if (optimization == NULL || optimization->solution == NULL)
        throw ErrorClass("No solution defined");
    int iSolutions = this->getSolutionNumber();
    if (solIdx < 0 || solIdx >= iSolutions)
        throw ErrorClass("solIdx is outside of range in routine getDualValueIdx()");
    if (optimization->solution[solIdx] == NULL) return -1;
    if (optimization->solution[solIdx]->constraints == NULL) return -1;
    if (optimization->solution[solIdx]->constraints->dualValues == NULL) return -1;
    if (conIdx < 0 || conIdx >= optimization->solution[solIdx]->constraints->dualValues->numberOfCon)
        throw ErrorClass("conIdx is outside of range in routine getDualValueIdx()");
    return optimization->solution[solIdx]->constraints->dualValues->con[conIdx]->idx;
}//getDualValueIdx

std::string OSResult::getDualValueName(int solIdx, int conIdx)
{
    if (optimization == NULL || optimization->solution == NULL)
        throw ErrorClass("No solution defined");
    int iSolutions = this->getSolutionNumber();
    if (solIdx < 0 || solIdx >= iSolutions)
        throw ErrorClass("solIdx is outside of range in routine getDualValueIdx()");
    if (optimization->solution[solIdx] == NULL) return "";
    if (optimization->solution[solIdx]->constraints == NULL) return "";
    if (optimization->solution[solIdx]->constraints->dualValues == NULL) return "";
    if (conIdx < 0 || conIdx >= optimization->solution[solIdx]->constraints->dualValues->numberOfCon)
        throw ErrorClass("conIdx is outside of range in routine getDualValueIdx()");
    return optimization->solution[solIdx]->constraints->dualValues->con[conIdx]->name;
}//getDualValueName

double OSResult::getDualValue(int solIdx, int conIdx)
{
    if (optimization == NULL || optimization->solution == NULL)
        throw ErrorClass("No solution defined");
    int iSolutions = this->getSolutionNumber();
    if (solIdx < 0 || solIdx >= iSolutions)
        throw ErrorClass("solIdx is outside of range in routine getDualValue()");
    if (optimization->solution[solIdx] == NULL) return OSNaN();
    if (optimization->solution[solIdx]->constraints == NULL) return OSNaN();
    if (optimization->solution[solIdx]->constraints->dualValues == NULL) return OSNaN();
    if (conIdx < 0 || conIdx >= optimization->solution[solIdx]->constraints->dualValues->numberOfCon)
        throw ErrorClass("conIdx is outside of range in routine getDualValue()");
    return optimization->solution[solIdx]->constraints->dualValues->con[conIdx]->value;
}//getDualValue

std::vector<IndexValuePair*>  OSResult::getOptimalDualVariableValues(int solIdx)
{
    int numberOfCon;
    struct IndexValuePair *dualValPair;
    int iSolutions = this->getSolutionNumber();
    for(int i = 0; i < iSolutions; i++)
    {
        if(i != solIdx) continue;
        if(optimization->solution[i] == NULL) continue;
        if(optimization->solution[i]->constraints == NULL) continue;
        if(optimization->solution[i]->constraints->dualValues == NULL) continue;
        if((optimization->solution[i]->status->type.find("ptimal") != string::npos && m_mdDualValues == NULL) ||
                optimization->solution[i]->status->type.compare("globallyOptimal") == 0)
        {
            numberOfCon = optimization->solution[i]->constraints->dualValues->numberOfCon;
            for(int j = 0; j < numberOfCon;  j++)
            {
                dualValPair = new IndexValuePair();
                dualValPair->idx = optimization->solution[i]->constraints->dualValues->con[j]->idx;
                dualValPair->value = optimization->solution[i]->constraints->dualValues->con[j]->value;
                dualVals.push_back( dualValPair);
            }
        }
        if(optimization->solution[i]->status->type.compare("globallyOptimal") == 0)
        {
            return dualVals;
        }
    }
    return dualVals;
}//getOptimalDualVariableValues


int OSResult::getNumberOfOtherConstraintResults(int solIdx)
{
    if (optimization == NULL || optimization->solution == NULL)
        throw ErrorClass("No solution defined");
    int iSolutions = this->getSolutionNumber();
    if (solIdx < 0 || solIdx >= iSolutions)
        throw ErrorClass("solIdx is outside of range in routine getNumberOfOtherConstraintResults()");
    if (optimization->solution[solIdx] == NULL)
        throw ErrorClass("solution was never defined in routine getNumberOfOtherConstraintResults()");
    if (optimization->solution[solIdx]->constraints == NULL) return 0;
    if (optimization->solution[solIdx]->constraints->other == NULL) return 0;
    return optimization->solution[solIdx]->constraints->numberOfOtherConstraintResults;
}//getNumberOfOtherConstraintResults


string OSResult::getOtherConstraintResultName(int solIdx, int otherIdx)
{
    if (optimization == NULL || optimization->solution == NULL)
        throw ErrorClass("No solution defined");
    int iSolutions = this->getSolutionNumber();
    if (solIdx < 0 || solIdx >= iSolutions)
        throw ErrorClass("solIdx is outside of range in routine getOtherConstraintResultName()");
    if (optimization->solution[solIdx] == NULL) return "";
    if (optimization->solution[solIdx]->constraints == NULL) return "";
    if (optimization->solution[solIdx]->constraints->other == NULL) return "";
    if (otherIdx < 0 || otherIdx >= optimization->solution[solIdx]->constraints->numberOfOtherConstraintResults)
        throw ErrorClass("otherIdx is outside of range in routine getOtherConstraintResultName()");
    if (optimization->solution[solIdx]->constraints->other[ otherIdx] == NULL) return "";
    return optimization->solution[solIdx]->constraints->other[ otherIdx]->name;
}//getOtherConstraintResultName

string OSResult::getOtherConstraintResultType(int solIdx, int otherIdx)
{
    if (optimization == NULL || optimization->solution == NULL)
        throw ErrorClass("No solution defined");
    int iSolutions = this->getSolutionNumber();
    if (solIdx < 0 || solIdx >= iSolutions)
        throw ErrorClass("solIdx is outside of range in routine getOtherConstraintResultType()");
    if (optimization->solution[solIdx] == NULL) return "";
    if (optimization->solution[solIdx]->constraints == NULL) return "";
    if (optimization->solution[solIdx]->constraints->other == NULL) return "";
    if (otherIdx < 0 || otherIdx >= optimization->solution[solIdx]->constraints->numberOfOtherConstraintResults)
        throw ErrorClass("otherIdx is outside of range in routine getOtherConstraintResultType()");
    if (optimization->solution[solIdx]->constraints->other[ otherIdx] == NULL) return "";
    return optimization->solution[solIdx]->constraints->other[ otherIdx]->type;
}//getOtherConstraintResultType

string OSResult::getOtherConstraintResultValue(int solIdx, int otherIdx)
{
    if (optimization == NULL || optimization->solution == NULL)
        throw ErrorClass("No solution defined");
    int iSolutions = this->getSolutionNumber();
    if (solIdx < 0 || solIdx >= iSolutions)
        throw ErrorClass("solIdx is outside of range in routine getOtherConstraintResultValue()");
    if (optimization->solution[solIdx] == NULL) return "";
    if (optimization->solution[solIdx]->constraints == NULL) return "";
    if (optimization->solution[solIdx]->constraints->other == NULL) return "";
    if (otherIdx < 0 || otherIdx >= optimization->solution[solIdx]->constraints->numberOfOtherConstraintResults)
        throw ErrorClass("otherIdx is outside of range in routine getOtherConstraintResultValue()");
    if (optimization->solution[solIdx]->constraints->other[ otherIdx] == NULL) return "";
    return optimization->solution[solIdx]->constraints->other[ otherIdx]->value;
}//getOtherConstraintResultValue

string OSResult::getOtherConstraintResultDescription(int solIdx, int otherIdx)
{
    if (optimization == NULL || optimization->solution == NULL)
        throw ErrorClass("No solution defined");
    int iSolutions = this->getSolutionNumber();
    if (solIdx < 0 || solIdx >= iSolutions)
        throw ErrorClass("solIdx is outside of range in routine getOtherConstraintResultDescription()");
    if (optimization->solution[solIdx] == NULL) return "";
    if (optimization->solution[solIdx]->constraints == NULL) return "";
    if (optimization->solution[solIdx]->constraints->other == NULL) return "";
    if (otherIdx < 0 || otherIdx >= optimization->solution[solIdx]->constraints->numberOfOtherConstraintResults)
        throw ErrorClass("otherIdx is outside of range in routine getOtherConstraintResultDescription()");
    if (optimization->solution[solIdx]->constraints->other[ otherIdx] == NULL) return "";
    return optimization->solution[solIdx]->constraints->other[ otherIdx]->description;
}//getOtherConstraintResultDescription

int OSResult::getOtherConstraintResultNumberOfCon(int solIdx, int otherIdx)
{
    if (optimization == NULL || optimization->solution == NULL)
        throw ErrorClass("No solution defined");
    int iSolutions = this->getSolutionNumber();
    if (solIdx < 0 || solIdx >= iSolutions)
        throw ErrorClass("solIdx is outside of range in routine getOtherConstraintResultNumberOfCon()");
    if (optimization->solution[solIdx] == NULL) return -1;
    if (optimization->solution[solIdx]->constraints == NULL) return -1;
    if (optimization->solution[solIdx]->constraints->other == NULL) return -1;
    if (otherIdx < 0 || otherIdx >= optimization->solution[solIdx]->constraints->numberOfOtherConstraintResults)
        throw ErrorClass("otherIdx is outside of range in routine getOtherConstraintResultNumberOfCon()");
    if (optimization->solution[solIdx]->constraints->other[ otherIdx] == NULL) return -1;
    return optimization->solution[solIdx]->constraints->other[ otherIdx]->numberOfCon;
}//getOtherConstraintResultNumberOfCon

int OSResult::getOtherConstraintResultConIdx(int solIdx, int otherIdx, int conIdx)
{
    if (optimization == NULL || optimization->solution == NULL)
        throw ErrorClass("No solution defined");
    int iSolutions = this->getSolutionNumber();
    if (solIdx < 0 || solIdx >= iSolutions)
        throw ErrorClass("solIdx is outside of range in routine getOtherConstraintResultConIdx()");
    if (optimization->solution[solIdx] == NULL) return -1;
    if (optimization->solution[solIdx]->constraints == NULL) return -1;
    if (optimization->solution[solIdx]->constraints->other == NULL) return -1;
    if (otherIdx < 0 || otherIdx >= optimization->solution[solIdx]->constraints->numberOfOtherConstraintResults)
        throw ErrorClass("otherIdx is outside of range in routine getOtherConstraintResultConIdx()");
    if (optimization->solution[solIdx]->constraints->other[ otherIdx] == NULL) return -1;
    if (optimization->solution[solIdx]->constraints->other[ otherIdx]->con == NULL) return -1;
    if (conIdx < 0 || conIdx >= optimization->solution[solIdx]->constraints->other[ otherIdx]->numberOfCon)
        throw ErrorClass("otherIdx is outside of range in routine getOtherConstraintResultConIdx()");
    return optimization->solution[solIdx]->constraints->other[otherIdx]->con[conIdx]->idx;
}//getOtherConstraintResultConIdx

string OSResult::getOtherConstraintResultCon(int solIdx, int otherIdx, int conIdx)
{
    if (optimization == NULL || optimization->solution == NULL)
        throw ErrorClass("No solution defined");
    int iSolutions = this->getSolutionNumber();
    if (solIdx < 0 || solIdx >= iSolutions)
        throw ErrorClass("solIdx is outside of range in routine getOtherConstraintResultCon()");
    if (optimization->solution[solIdx] == NULL) return "";
    if (optimization->solution[solIdx]->constraints == NULL) return "";
    if (optimization->solution[solIdx]->constraints->other == NULL) return "";
    if (otherIdx < 0 || otherIdx >= optimization->solution[solIdx]->constraints->numberOfOtherConstraintResults)
        throw ErrorClass("otherIdx is outside of range in routine getOtherConstraintResultCon()");
    if (optimization->solution[solIdx]->constraints->other[ otherIdx] == NULL) return "";
    if (optimization->solution[solIdx]->constraints->other[ otherIdx]->con == NULL) return "";
    if (conIdx < 0 || conIdx >= optimization->solution[solIdx]->constraints->other[ otherIdx]->numberOfCon)
        throw ErrorClass("otherIdx is outside of range in routine getOtherConstraintResultCon()");
    return optimization->solution[solIdx]->constraints->other[otherIdx]->con[conIdx]->value;
}//getOtherConstraintResultCon


std::string OSResult::getOtherConstraintResultArrayType(int solIdx, int otherIdx)
{
    if (optimization == NULL || optimization->solution == NULL)
        throw ErrorClass("No solution defined");
    int iSolutions = this->getSolutionNumber();
    if (solIdx < 0 || solIdx >= iSolutions)
        throw ErrorClass("solIdx is outside of range in routine getOtherConstraintResultArrayType()");
    if (optimization->solution[solIdx] == NULL) return "";
    if (optimization->solution[solIdx]->constraints == NULL) return "";
    if (optimization->solution[solIdx]->constraints->other == NULL) return "";
    if (otherIdx < 0 || otherIdx >= optimization->solution[solIdx]->constraints->numberOfOtherConstraintResults)
        throw ErrorClass("otherIdx is outside of range in routine getOtherConstraintResultArrayType()");
    if (optimization->solution[solIdx]->constraints->other[ otherIdx] == NULL) return "";

    if (optimization->solution[solIdx]->constraints->other[ otherIdx]->con != NULL) 
        return optimization->solution[solIdx]->constraints->other[ otherIdx]->conType;
    else if (optimization->solution[solIdx]->constraints->other[ otherIdx]->enumeration != NULL) 
        return optimization->solution[solIdx]->constraints->other[ otherIdx]->enumType;
    else
        return "";
}//getOtherConstraintResultArrayType


int OSResult::getOtherConstraintResultNumberOfEnumerations(int solIdx, int otherIdx)
{
    if (optimization == NULL || optimization->solution == NULL)
        throw ErrorClass("No solution defined");
    int iSolutions = this->getSolutionNumber();
    if (solIdx < 0 || solIdx >= iSolutions)
        throw ErrorClass("solIdx is outside of range in routine getOtherConstraintResultNumberOfEnumerations()");
    if (optimization->solution[solIdx] == NULL) return -1;
    if (optimization->solution[solIdx]->constraints == NULL) return -1;
    if (optimization->solution[solIdx]->constraints->other == NULL) return -1;
    if (otherIdx < 0 || otherIdx >= optimization->solution[solIdx]->constraints->numberOfOtherConstraintResults)
        throw ErrorClass("otherIdx is outside of range in routine getOtherConstraintResultNumberOfEnumerations()");
    if (optimization->solution[solIdx]->constraints->other[ otherIdx] == NULL) return -1;
    return optimization->solution[solIdx]->constraints->other[ otherIdx]->numberOfEnumerations;
}//getOtherConstraintResultNumberOfEnumerations


std::string OSResult::getOtherConstraintResultEnumerationValue(int solIdx,int otherIdx, int enumIdx)
{
    if (optimization == NULL || optimization->solution == NULL)
        throw ErrorClass("No solution defined");
    if (solIdx < 0 || solIdx >= optimization->numberOfSolutions)
        throw ErrorClass("solIdx is outside of range in routine getOtherConstraintResultEnumerationValue()");
    if (optimization->solution[solIdx] == NULL)
        throw ErrorClass("solution never defined in routine getOtherConstraintResultEnumerationValue()");

    if (optimization->solution[solIdx]->constraints == NULL)
        throw ErrorClass("constraints result never defined in routine getOtherConstraintResultEnumerationValue()");
    if (otherIdx < 0 || otherIdx >= optimization->solution[solIdx]->constraints->numberOfOtherConstraintResults)
        throw ErrorClass("otherIdx is outside of range in routine getOtherConstraintResultEnumerationValue()");
    if (optimization->solution[solIdx]->constraints->other == NULL)
        throw ErrorClass("other constraint array never defined in routine getOtherConstraintResultEnumerationValue()");
    if (optimization->solution[solIdx]->constraints->other[otherIdx] == NULL)
        throw ErrorClass("other constraint result never defined in routine getOtherConstraintResultEnumerationValue()");
    if (optimization->solution[solIdx]->constraints->other[otherIdx]->enumeration == NULL)
        throw ErrorClass("enumerations array never defined in routine getOtherConstraintResultEnumerationValue()");
    if (enumIdx < 0 || enumIdx >= optimization->solution[solIdx]->constraints->other[otherIdx]->numberOfEnumerations)
        throw ErrorClass("enumIdx is outside of range in routine getOtherConstraintResultEnumerationValue()");
    if (optimization->solution[solIdx]->constraints->other[otherIdx]->enumeration[enumIdx] == NULL)
        throw ErrorClass("enumeration never defined in routine getOtherConstraintResultEnumerationValue()");

    return optimization->solution[solIdx]->constraints->other[otherIdx]->enumeration[enumIdx]->value;
}//getOtherConstraintResultEnumerationValue


std::string OSResult::getOtherConstraintResultEnumerationDescription(int solIdx,int otherIdx, int enumIdx)
{
    if (optimization == NULL || optimization->solution == NULL)
        throw ErrorClass("No solution defined");
    if (solIdx < 0 || solIdx >= optimization->numberOfSolutions)
        throw ErrorClass("solIdx is outside of range in routine getOtherConstraintResultEnumerationDescription()");
    if (optimization->solution[solIdx] == NULL)
        throw ErrorClass("solution never defined in routine getOtherConstraintResultEnumerationDescription()");

    if (optimization->solution[solIdx]->constraints == NULL)
        throw ErrorClass("constraints result never defined in routine getOtherConstraintResultEnumerationDescription()");
    if (otherIdx < 0 || otherIdx >= optimization->solution[solIdx]->constraints->numberOfOtherConstraintResults)
        throw ErrorClass("otherIdx is outside of range in routine getOtherConstraintResultEnumerationDescription()");
    if (optimization->solution[solIdx]->constraints->other == NULL)
        throw ErrorClass("other constraint array never defined in routine getOtherConstraintResultEnumerationDescription()");
    if (optimization->solution[solIdx]->constraints->other[otherIdx] == NULL)
        throw ErrorClass("other constraint result never defined in routine getOtherConstraintResultEnumerationDescription()");
    if (optimization->solution[solIdx]->constraints->other[otherIdx]->enumeration == NULL)
        throw ErrorClass("enumerations array never defined in routine getOtherConstraintResultEnumerationDescription()");
    if (enumIdx < 0 || enumIdx >= optimization->solution[solIdx]->constraints->other[otherIdx]->numberOfEnumerations)
        throw ErrorClass("enumIdx is outside of range in routine getOtherConstraintResultEnumerationDescription()");
    if (optimization->solution[solIdx]->constraints->other[otherIdx]->enumeration[enumIdx] == NULL)
        throw ErrorClass("enumeration never defined in routine getOtherConstraintResultEnumerationDescription()");

    return optimization->solution[solIdx]->constraints->other[otherIdx]->enumeration[enumIdx]->description;
}//getOtherConstraintResultEnumerationDescription

int OSResult::getOtherConstraintResultEnumerationNumberOfEl(int solIdx,int otherIdx, int enumIdx)
{
    if (optimization == NULL || optimization->solution == NULL)
        throw ErrorClass("No solution defined");
    if (solIdx < 0 || solIdx >= optimization->numberOfSolutions)
        throw ErrorClass("solIdx is outside of range in routine getOtherConstraintResultEnumerationNumberOfEl()");
    if (optimization->solution[solIdx] == NULL)
        throw ErrorClass("solution never defined in routine getOtherConstraintResultEnumerationNumberOfEl()");

    if (optimization->solution[solIdx]->constraints == NULL)
        throw ErrorClass("constraints result never defined in routine getOtherConstraintResultEnumerationNumberOfEl()");
    if (otherIdx < 0 || otherIdx >= optimization->solution[solIdx]->constraints->numberOfOtherConstraintResults)
        throw ErrorClass("otherIdx is outside of range in routine getOtherConstraintResultEnumerationNumberOfEl()");
    if (optimization->solution[solIdx]->constraints->other == NULL)
        throw ErrorClass("other constraint array never defined in routine getOtherConstraintResultEnumerationNumberOfEl()");
    if (optimization->solution[solIdx]->constraints->other[otherIdx] == NULL)
        throw ErrorClass("other constraint result never defined in routine getOtherConstraintResultEnumerationNumberOfEl()");
    if (optimization->solution[solIdx]->constraints->other[otherIdx]->enumeration == NULL)
        throw ErrorClass("enumerations array never defined in routine getOtherConstraintResultEnumerationNumberOfEl()");
    if (enumIdx < 0 || enumIdx >= optimization->solution[solIdx]->constraints->other[otherIdx]->numberOfEnumerations)
        throw ErrorClass("enumIdx is outside of range in routine getOtherConstraintResultEnumerationNumberOfEl()");
    if (optimization->solution[solIdx]->constraints->other[otherIdx]->enumeration[enumIdx] == NULL)
        throw ErrorClass("enumeration never defined in routine getOtherConstraintResultEnumerationNumberOfEl()");

    return optimization->solution[solIdx]->constraints->other[otherIdx]->enumeration[enumIdx]->numberOfEl;
}//getOtherConstraintResultEnumerationNumberOfEl

int OSResult::getOtherConstraintResultEnumerationEl(int solIdx,int otherIdx, int enumIdx, int j)
{
    if (optimization == NULL || optimization->solution == NULL)
        throw ErrorClass("No solution defined");
    if (solIdx < 0 || solIdx >= optimization->numberOfSolutions)
        throw ErrorClass("solIdx is outside of range in routine getOtherConstraintResultEnumerationEl()");
    if (optimization->solution[solIdx] == NULL)
        throw ErrorClass("solution never defined in routine getOtherConstraintResultEnumerationEl()");

    if (optimization->solution[solIdx]->constraints == NULL)
        throw ErrorClass("constraints result never defined in routine getOtherConstraintResultEnumerationEl()");
    if (otherIdx < 0 || otherIdx >= optimization->solution[solIdx]->constraints->numberOfOtherConstraintResults)
        throw ErrorClass("otherIdx is outside of range in routine getOtherConstraintResultEnumerationEl()");
    if (optimization->solution[solIdx]->constraints->other == NULL)
        throw ErrorClass("other constraint array never defined in routine getOtherConstraintResultEnumerationEl()");
    if (optimization->solution[solIdx]->constraints->other[otherIdx] == NULL)
        throw ErrorClass("other constraint result never defined in routine getOtherConstraintResultEnumerationEl()");
    if (optimization->solution[solIdx]->constraints->other[otherIdx]->enumeration == NULL)
        throw ErrorClass("enumerations array never defined in routine getOtherConstraintResultEnumerationEl()");
    if (enumIdx < 0 || enumIdx >= optimization->solution[solIdx]->constraints->other[otherIdx]->numberOfEnumerations)
        throw ErrorClass("enumIdx is outside of range in routine getOtherConstraintResultEnumerationEl()");
    if (optimization->solution[solIdx]->constraints->other[otherIdx]->enumeration[enumIdx] == NULL)
        throw ErrorClass("enumeration never defined in routine getOtherConstraintResultEnumerationEl()");

    return optimization->solution[solIdx]->constraints->other[otherIdx]->enumeration[enumIdx]->getEl(j);
}//getOtherConstraintResultEnumerationEl

int OSResult::getOtherConstraintResultArrayDense(int solIdx, int otherIdx, std::string* resultArray, int dim)
{
    int i, j;
    if (optimization == NULL || optimization->solution == NULL)
        throw ErrorClass("No solution defined");
    if (solIdx < 0 || solIdx >= optimization->numberOfSolutions)
        throw ErrorClass("solIdx is outside of range in routine getOtherConstraintResultArrayDense()");
    if (optimization->solution[solIdx] == NULL)
        throw ErrorClass("solution never defined in routine getOtherConstraintResultArrayDense()");
    if (optimization->solution[solIdx]->constraints == NULL)
        throw ErrorClass("constraints result never defined in routine getOtherConstraintResultArrayDense()");
    if (otherIdx < 0 || otherIdx >= optimization->solution[solIdx]->constraints->numberOfOtherConstraintResults)
        throw ErrorClass("otherIdx is outside of range in routine getOtherConstraintResultArrayDense()");
    if (optimization->solution[solIdx]->constraints->other == NULL)
        throw ErrorClass("other constraint array never defined in routine getOtherConstraintResultArrayDense()");
    if (optimization->solution[solIdx]->constraints->other[otherIdx] == NULL)
        throw ErrorClass("other constraint result never defined in routine getOtherConstraintResultArrayDense()");

    if (optimization->solution[solIdx]->constraints->other[otherIdx]->enumeration == NULL)
	{
        if (optimization->solution[solIdx]->constraints->other[otherIdx]->con == NULL)
            return 0; // neither <con> nor <enumeration>
        else // there is a <con> array
        {
            for (i=0; i<dim; i++)
                resultArray[i] = "";

            for (i=0; i<optimization->solution[solIdx]->constraints->other[otherIdx]->numberOfCon; i++)
            {
                j = optimization->solution[solIdx]->constraints->other[otherIdx]->con[i]->idx;
                if (j >= 0 && j < dim)
                    resultArray[j] = optimization->solution[solIdx]->constraints->other[otherIdx]->con[i]->value;
                else
                    throw ErrorClass("constraint index out of range in routine getOtherConstraintResultArrayDense()");
            }
            return dim;
        }
    }
    else // there is an <enumeration> array
    {
        std::string val;
        int n,k;

        for (j=0; j<dim; j++)
            resultArray[j] = "";

        for (i=0; i<optimization->solution[solIdx]->constraints->other[otherIdx]->numberOfEnumerations; i++)
        {
            val = optimization->solution[solIdx]->constraints->other[otherIdx]->enumeration[i]->value;
            n   = optimization->solution[solIdx]->constraints->other[otherIdx]->enumeration[i]->numberOfEl;

            for (j=0; j<n; j++)
            {
                k = optimization->solution[solIdx]->constraints->other[otherIdx]->enumeration[i]->el[j];
                if (j >= 0 && j < dim)
                    resultArray[k] = val;
                else
                    throw ErrorClass("constraint index out of range in routine getOtherConstraintResultArrayDense()");
            }
        }
        return dim;
    }
    return -1;
}//getOtherConstraintResultArrayDense



int OSResult::getNumberOfOtherSolutionResults(int solIdx)
{
    if (optimization == NULL || optimization->solution == NULL)
        throw ErrorClass("No solution defined");
    int iSolutions = this->getSolutionNumber();
    if (solIdx < 0 || solIdx >= iSolutions)
        throw ErrorClass("solIdx is outside of range in routine getNumberOfOtherSolutionResults()");
    if (optimization->solution[solIdx] == NULL) return -1;
    if (optimization->solution[solIdx]->otherSolutionResults == NULL) return -1;
    return optimization->solution[solIdx]->otherSolutionResults->numberOfOtherSolutionResults;
}//getNumberOfOtherSolutionResults

string OSResult::getOtherSolutionResultName(int solIdx, int otherIdx)
{
    if (optimization == NULL || optimization->solution == NULL)
        throw ErrorClass("No solution defined");
    int iSolutions = this->getSolutionNumber();
    if (solIdx < 0 || solIdx >= iSolutions)
        throw ErrorClass("solIdx is outside of range in routine getOtherSolutionResultName()");
    if (optimization->solution[solIdx] == NULL) return "";
    if (optimization->solution[solIdx]->otherSolutionResults == NULL) return "";
    if (otherIdx < 0 || otherIdx >= optimization->solution[solIdx]->otherSolutionResults->numberOfOtherSolutionResults)
        throw ErrorClass("otherIdx is outside of range in routine getOtherSolutionResultName()");
    if (optimization->solution[solIdx]->otherSolutionResults->otherSolutionResult[otherIdx] == NULL) return "";
    return optimization->solution[solIdx]->otherSolutionResults->otherSolutionResult[otherIdx]->name;
}//getOtherSolutionResultName

string OSResult::getOtherSolutionResultValue(int solIdx, int otherIdx)
{
    if (optimization == NULL || optimization->solution == NULL)
        throw ErrorClass("No solution defined");
    int iSolutions = this->getSolutionNumber();
    if (solIdx < 0 || solIdx >= iSolutions)
        throw ErrorClass("solIdx is outside of range in routine getOtherSolutionResultName()");
    if (optimization->solution[solIdx] == NULL) return "";
    if (optimization->solution[solIdx]->otherSolutionResults == NULL) return "";
    if (otherIdx < 0 || otherIdx >= optimization->solution[solIdx]->otherSolutionResults->numberOfOtherSolutionResults)
        throw ErrorClass("otherIdx is outside of range in routine getOtherSolutionResultValue()");
    if (optimization->solution[solIdx]->otherSolutionResults->otherSolutionResult[otherIdx] == NULL) return "";
    return optimization->solution[solIdx]->otherSolutionResults->otherSolutionResult[otherIdx]->value;
}//getOtherSolutionResultName

string OSResult::getOtherSolutionResultCategory(int solIdx, int otherIdx)
{
    if (optimization == NULL || optimization->solution == NULL)
        throw ErrorClass("No solution defined");
    int iSolutions = this->getSolutionNumber();
    if (solIdx < 0 || solIdx >= iSolutions)
        throw ErrorClass("solIdx is outside of range in routine getOtherSolutionResultCategory()");
    if (optimization->solution[solIdx] == NULL) return "";
    if (optimization->solution[solIdx]->otherSolutionResults == NULL) return "";
    if (otherIdx < 0 || otherIdx >= optimization->solution[solIdx]->otherSolutionResults->numberOfOtherSolutionResults)
        throw ErrorClass("otherIdx is outside of range in routine getOtherSolutionResultCategory()");
    if (optimization->solution[solIdx]->otherSolutionResults->otherSolutionResult[otherIdx] == NULL) return "";
    return optimization->solution[solIdx]->otherSolutionResults->otherSolutionResult[otherIdx]->category;
}//getOtherSolutionResultCategory

string OSResult::getOtherSolutionResultDescription(int solIdx, int otherIdx)
{
    if (optimization == NULL || optimization->solution == NULL)
        throw ErrorClass("No solution defined");
    int iSolutions = this->getSolutionNumber();
    if (solIdx < 0 || solIdx >= iSolutions)
        throw ErrorClass("solIdx is outside of range in routine getOtherSolutionResultDescription()");
    if (optimization->solution[solIdx] == NULL) return "";
    if (optimization->solution[solIdx]->otherSolutionResults == NULL) return "";
    if (otherIdx < 0 || otherIdx >= optimization->solution[solIdx]->otherSolutionResults->numberOfOtherSolutionResults)
        throw ErrorClass("otherIdx is outside of range in routine getOtherSolutionResultDescription()");
    if (optimization->solution[solIdx]->otherSolutionResults->otherSolutionResult[otherIdx] == NULL) return "";
    return optimization->solution[solIdx]->otherSolutionResults->otherSolutionResult[otherIdx]->description;
}//getOtherSolutionResultDescription

int OSResult::getOtherSolutionResultNumberOfItems(int solIdx, int otherIdx)
{
    if (optimization == NULL || optimization->solution == NULL)
        throw ErrorClass("No solution defined");
    int iSolutions = this->getSolutionNumber();
    if (solIdx < 0 || solIdx >= iSolutions)
        throw ErrorClass("solIdx is outside of range in routine getOtherSolutionResultNumberOfItems()");
    if (optimization->solution[solIdx] == NULL) return -1;
    if (optimization->solution[solIdx]->otherSolutionResults == NULL) return -1;
    if (otherIdx < 0 || otherIdx >= optimization->solution[solIdx]->otherSolutionResults->numberOfOtherSolutionResults)
        throw ErrorClass("otherIdx is outside of range in routine getOtherSolutionResultNumberOfItems()");
    if (optimization->solution[solIdx]->otherSolutionResults->otherSolutionResult[otherIdx] == NULL) return -1;
    return optimization->solution[solIdx]->otherSolutionResults->otherSolutionResult[otherIdx]->numberOfItems;
}//getOtherSolutionResultNumberOfItems

string OSResult::getOtherSolutionResultItem(int solIdx, int otherIdx, int itemIdx)
{
    if (optimization == NULL || optimization->solution == NULL)
        throw ErrorClass("No solution defined");
    int iSolutions = this->getSolutionNumber();
    if (solIdx < 0 || solIdx >= iSolutions)
        throw ErrorClass("solIdx is outside of range in routine getOtherSolutionResultItem()");
    if (optimization->solution[solIdx] == NULL) return "";
    if (optimization->solution[solIdx]->otherSolutionResults == NULL) return "";
    if (optimization->solution[solIdx]->otherSolutionResults->otherSolutionResult[otherIdx] == NULL) return "";
    if (otherIdx < 0 || otherIdx >= optimization->solution[solIdx]->otherSolutionResults->numberOfOtherSolutionResults)
        throw ErrorClass("otherIdx is outside of range in routine getOtherSolutionResultItem()");
    if (optimization->solution[solIdx]->otherSolutionResults->otherSolutionResult[otherIdx]->item == NULL) return "";
    if (itemIdx < 0 || itemIdx >= optimization->solution[solIdx]->otherSolutionResults->otherSolutionResult[otherIdx]->numberOfItems)
        throw ErrorClass("itemIdx is outside of range in routine getOtherSolutionResultItem()");
    return optimization->solution[solIdx]->otherSolutionResults->otherSolutionResult[otherIdx]->item[itemIdx];
}//getOtherSolutionResultItem

int OSResult::getNumberOfSolverOutputs()
{
    if (optimization == NULL || optimization->otherSolverOutput == NULL) return -1;
    return optimization->otherSolverOutput->numberOfSolverOutputs;
}//getNumberOfSolverOutputs

string OSResult::getSolverOutputName(int otherIdx)
{
    if (optimization == NULL) return "";
    if (optimization->otherSolverOutput == NULL) return "";
    if (otherIdx < 0 || otherIdx >= optimization->otherSolverOutput->numberOfSolverOutputs)
        throw ErrorClass("otherIdx is outside of range in routine getSolverOutputName()");
    if (optimization->otherSolverOutput->solverOutput[otherIdx] == NULL) return "";
    return optimization->otherSolverOutput->solverOutput[otherIdx]->name;
}//getSolverOutputName

string OSResult::getSolverOutputCategory(int otherIdx)
{
    if (optimization == NULL) return "";
    if (optimization->otherSolverOutput == NULL) return "";
    if (otherIdx < 0 || otherIdx >= optimization->otherSolverOutput->numberOfSolverOutputs)
        throw ErrorClass("otherIdx is outside of range in routine getSolverOutputCategory()");
    if (optimization->otherSolverOutput->solverOutput[otherIdx] == NULL) return "";
    return optimization->otherSolverOutput->solverOutput[otherIdx]->category;
}//getSolverOutputCategory

string OSResult::getSolverOutputDescription(int otherIdx)
{
    if (optimization == NULL) return "";
    if (optimization->otherSolverOutput == NULL) return "";
    if (otherIdx < 0 || otherIdx >= optimization->otherSolverOutput->numberOfSolverOutputs)
        throw ErrorClass("otherIdx is outside of range in routine getSolverOutputDescription()");
    if (optimization->otherSolverOutput->solverOutput[otherIdx] == NULL) return "";
    return optimization->otherSolverOutput->solverOutput[otherIdx]->description;
}//getSolverOutputDescription

int OSResult::getSolverOutputNumberOfItems(int otherIdx)
{
    if (optimization == NULL) return -1;
    if (optimization->otherSolverOutput == NULL) return -1;
    if (otherIdx < 0 || otherIdx >= optimization->otherSolverOutput->numberOfSolverOutputs)
        throw ErrorClass("otherIdx is outside of range in routine getSolverOutputNumberOfItems()");
    if (optimization->otherSolverOutput->solverOutput[otherIdx] == NULL) return -1;
    return optimization->otherSolverOutput->solverOutput[otherIdx]->numberOfItems;
}//getSolverOutputNumberOfItems

string OSResult::getSolverOutputItem(int otherIdx, int itemIdx)
{
    if (optimization == NULL) return "";
    if (optimization->otherSolverOutput == NULL) return "";
    if (otherIdx < 0 || otherIdx >= optimization->otherSolverOutput->numberOfSolverOutputs)
        throw ErrorClass("otherIdx is outside of range in routine getSolverOutputItem");
    if (optimization->otherSolverOutput->solverOutput[otherIdx] == NULL) return "";
    if (itemIdx < 0 || itemIdx >= optimization->otherSolverOutput->solverOutput[otherIdx]->numberOfItems)
        throw ErrorClass("itemIdx is outside of range in routine getSolverOutputItem()");
    return optimization->otherSolverOutput->solverOutput[otherIdx]->item[itemIdx];;
}//getSolverOutputItem

//==================================================================
// set methods

bool OSResult::setHeader(std::string name, std::string source,
                               std::string fileCreator, std::string description, std::string licence)
{
    if (this->resultHeader == NULL)
        this->resultHeader = new GeneralFileHeader();
    return this->resultHeader->setHeader(name, source, fileCreator, description, licence);
}// end of OSResult::setHeader

bool OSResult::setGeneralStatus(GeneralStatus *status)
{
    if (general == NULL) general = new GeneralResult();
    if (general->generalStatus == NULL) general->generalStatus = new GeneralStatus();
    general->generalStatus = status;
    return true;
}//setGeneralStatus

bool OSResult::setGeneralStatusType(string type)
{
    if (general == NULL) general = new GeneralResult();
    if (verifyGeneralResultStatus(type) == 0) return false;
    if (general->generalStatus == NULL) general->generalStatus = new GeneralStatus();
    general->generalStatus->type = type;
    return true;
}//setGeneralStatusType

bool OSResult::setGeneralStatusDescription(string description)
{
    if (general == NULL) general = new GeneralResult();
    if (general->generalStatus == NULL) general->generalStatus = new GeneralStatus();
    general->generalStatus->description = description;
    return true;
}//setGeneralStatusDescription

bool OSResult::setNumberOfGeneralSubstatuses(int num)
{
    if (num < 0) return false;

    if (general == NULL) general = new GeneralResult();
    if (general->generalStatus == NULL) general->generalStatus = new GeneralStatus();
    if (general->generalStatus->substatus != NULL) return false;
    general->generalStatus->numberOfSubstatuses = num;
    if (num > 0)
    {
        general->generalStatus->substatus = new GeneralSubstatus*[num];
        for(int i = 0; i < num; i++)
            general->generalStatus->substatus[i] = new GeneralSubstatus();
    }
    return true;
}//setNumberOfGeneralSubstatuses

bool OSResult::setGeneralSubstatusName(int idx, string name)
{
    if (general == NULL) general = new GeneralResult();
    if (general->generalStatus == NULL) return false;
    if (idx < 0 || idx >= general->generalStatus->numberOfSubstatuses) return false;
    general->generalStatus->substatus[idx]->name = name;
    return true;
}//setGeneralSubstatusName

bool OSResult::setGeneralSubstatusDescription(int idx, string description)
{
    if (general == NULL) general = new GeneralResult();
    if (general->generalStatus == NULL) return false;
    if (idx < 0 || idx >= general->generalStatus->numberOfSubstatuses) return false;
    general->generalStatus->substatus[idx]->description = description;
    return true;
}//setGeneralSubstatusDescription

bool OSResult::setGeneralMessage(string message)
{
    if (general == NULL) general = new GeneralResult();
    general->message = message;
    return true;
}//setGeneralMessage

bool OSResult::setServiceName(string serviceName)
{
    if (general == NULL) general = new GeneralResult();
    general->serviceName = serviceName;
    return true;
}//setServiceName

bool OSResult::setServiceURI(string serviceURI)
{
    if (general == NULL) general = new GeneralResult();
    general->serviceURI = serviceURI;
    return true;
}//setServiceURI

bool OSResult::setInstanceName(string instanceName)
{
    if (general == NULL) general = new GeneralResult();
    general->instanceName = instanceName;
    return true;
}//setInstanceName

bool OSResult::setJobID(string jobID)
{
    if (general == NULL) general = new GeneralResult();
    general->jobID = jobID;
    return true;
}//setJobID

bool OSResult::setSolverInvoked(string solverInvoked)
{
    if (general == NULL) general = new GeneralResult();
    general->solverInvoked = solverInvoked;
    return true;
}//setSolverInvoked

bool OSResult::setTimeStamp(string timeStamp)
{
    if (general == NULL) general = new GeneralResult();
    general->timeStamp = timeStamp;
    return true;
}//setTimeStamp

bool OSResult::setNumberOfOtherGeneralResults(int num)
{
    if (general == NULL) general = new GeneralResult();
    if(general->otherResults == NULL) general->otherResults = new OtherResults();
    if (num < 0) return false;
    if (general->otherResults->other != NULL) return false;
    general->otherResults->numberOfOtherResults = num;
    if (num > 0)
    {
        general->otherResults->other = new OtherOptionOrResult*[num];
        for(int i = 0; i < num; i++)
            general->otherResults->other[i] = new OtherOptionOrResult();
    }
    return true;
}//setNumberOfOtherGeneralResults


bool OSResult::setOtherGeneralResultName(int idx, string name)
{
    if (general == NULL) general = new GeneralResult();
    if (general->otherResults == NULL) return false;
    if (idx < 0 || idx >= general->otherResults->numberOfOtherResults)
        return false;
    general->otherResults->other[idx]->name = name;
    return true;
}//setOtherGeneralResultName

bool OSResult::setOtherGeneralResultValue(int idx, string value)
{
    if (general == NULL) general = new GeneralResult();
    if (general->otherResults == NULL) return false;
    if (idx < 0 || idx >= general->otherResults->numberOfOtherResults)
        return false;
    general->otherResults->other[idx]->value = value;
    return true;
}//setOtherGeneralResultValue

bool OSResult::setOtherGeneralResultDescription(int idx, string description)
{
    if (general == NULL) general = new GeneralResult();
    if (general->otherResults == NULL) return false;
    if (idx < 0 || idx >= general->otherResults->numberOfOtherResults)
        return false;
    general->otherResults->other[idx]->description = description;
    return true;
}//setOtherGeneralResultDescription

bool OSResult::setSystemInformation(string systemInformation)
{
    if (system == NULL) system = new SystemResult();
    system->systemInformation = systemInformation;
    return true;
}//setServiceName

bool OSResult::setAvailableDiskSpaceUnit(std::string unit)
{
    if (system == NULL) system = new SystemResult();
    if (system->availableDiskSpace == NULL) system->availableDiskSpace = new StorageCapacity();
    if (verifyStorageUnit(unit) == false) return false;
    system->availableDiskSpace->unit = unit;
    return true;
}//setAvailableDiskSpaceUnit

bool OSResult::setAvailableDiskSpaceDescription(std::string description)
{
    if (system == NULL) system = new SystemResult();
    if (system->availableDiskSpace == NULL) system->availableDiskSpace = new StorageCapacity();
    system->availableDiskSpace->description = description;
    return true;
}//setAvailableDiskSpaceDescription

bool OSResult::setAvailableDiskSpaceValue(double value)
{
    if (system == NULL) system = new SystemResult();
    if (system->availableDiskSpace == NULL) system->availableDiskSpace = new StorageCapacity();
    system->availableDiskSpace->value = value;
    return true;
}//setAvailableDiskSpaceValue

bool OSResult::setAvailableMemoryUnit(std::string unit)
{
    if (system == NULL) system = new SystemResult();
    if (system->availableMemory == NULL) system->availableMemory = new StorageCapacity();
    if (verifyStorageUnit(unit) == false) return false;
    system->availableMemory->unit = unit;
    return true;
}//setAvailableMemoryUnit

bool OSResult::setAvailableMemoryDescription(std::string description)
{
    if (system == NULL) system = new SystemResult();
    if (system->availableMemory == NULL) system->availableMemory = new StorageCapacity();
    system->availableMemory->description = description;
    return true;
}//setAvailableMemoryDescription

bool OSResult::setAvailableMemoryValue(double value)
{
    if (system == NULL) system = new SystemResult();
    if (system->availableMemory == NULL) system->availableMemory = new StorageCapacity();
    system->availableMemory->value = value;
    return true;
}//setAvailableMemoryValue

bool OSResult::setAvailableCPUSpeedUnit(std::string unit)
{
    if (system == NULL) return false;
    if (system->availableCPUSpeed == NULL) system->availableCPUSpeed = new CPUSpeed();
    if (verifyCPUSpeedUnit(unit) == false) return false;
    system->availableCPUSpeed->unit = unit;
    return true;
}//setAvailableCPUSpeedUnit

bool OSResult::setAvailableCPUSpeedDescription(std::string description)
{
    if (system == NULL) system = new SystemResult();
    if (system->availableCPUSpeed == NULL) system->availableCPUSpeed = new CPUSpeed();
    system->availableCPUSpeed->description = description;
    return true;
}//setAvailableCPUSpeedDescription

bool OSResult::setAvailableCPUSpeedValue(double value)
{
    if (system == NULL) system = new SystemResult();
    if (system->availableCPUSpeed == NULL) system->availableCPUSpeed = new CPUSpeed();
    system->availableCPUSpeed->value = value;
    return true;
}//setAvailableCPUSpeedValue

bool OSResult::setAvailableCPUNumberDescription(std::string description)
{
    if (system == NULL) system = new SystemResult();
    if (system->availableCPUNumber == NULL) system->availableCPUNumber = new CPUNumber();
    system->availableCPUNumber->description = description;
    return true;
}//setAvailableCPUNumberDescription

bool OSResult::setAvailableCPUNumberValue(int value)
{
    if (system == NULL) system = new SystemResult();
    if (system->availableCPUNumber == NULL) system->availableCPUNumber = new CPUNumber();
    system->availableCPUNumber->value = value;
    return true;
}//setAvailableCPUNumberValue

bool OSResult::setNumberOfOtherSystemResults(int num)
{
    if (system == NULL) system = new SystemResult();
    if(system->otherResults == NULL) system->otherResults = new OtherResults();
    if (num < 0) return false;
    if (system->otherResults->other != NULL) return false;
    system->otherResults->numberOfOtherResults = num;
    if (num > 0)
    {
        system->otherResults->other = new OtherOptionOrResult*[num];
        for(int i = 0; i < num; i++)
            system->otherResults->other[i] = new OtherOptionOrResult();
    }
    return true;
}//setNumberOfOtherSystemResults


bool OSResult::setOtherSystemResultName(int idx, string name)
{
    if (system == NULL) system = new SystemResult();
    if (system->otherResults == NULL) return false;
    if (idx < 0 || idx >= system->otherResults->numberOfOtherResults)
        return false;
    system->otherResults->other[idx]->name = name;
    return true;
}//setOtherSystemResultName

bool OSResult::setOtherSystemResultValue(int idx, string value)
{
    if (system == NULL) system = new SystemResult();
    if (system->otherResults == NULL) return false;
    if (idx < 0 || idx >= system->otherResults->numberOfOtherResults)
        return false;
    system->otherResults->other[idx]->value = value;
    return true;
}//setOtherSystemResultValue

bool OSResult::setOtherSystemResultDescription(int idx, string description)
{
    if (system == NULL) system = new SystemResult();
    if (system->otherResults == NULL) return false;
    if (idx < 0 || idx >= system->otherResults->numberOfOtherResults)
        return false;
    system->otherResults->other[idx]->description = description;
    return true;
}//setOtherSystemResultDescription

bool OSResult::setCurrentState(std::string currentState)
{
    if(verifySystemCurrentState(currentState) == 0) return false;

    if (service == NULL) service = new ServiceResult();
    service->currentState = currentState;
    return true;
}//setCurrentState

bool OSResult::setCurrentJobCount(int jobCount)
{
    if (service == NULL) service = new ServiceResult();
    service->currentJobCount = jobCount;
    return true;
}//setCurrentJobCount

bool OSResult::setTotalJobsSoFar(int number)
{
    if (service == NULL) service = new ServiceResult();
    service->totalJobsSoFar = number;
    return true;
}//setTotalJobsSoFar

bool OSResult::setTimeServiceStarted(std::string startTime)
{
    if (service == NULL) service = new ServiceResult();
    service->timeServiceStarted = startTime;
    return true;
}//setTimeServiceStarted

bool OSResult::setServiceUtilization(double value)
{
    if (service == NULL) service = new ServiceResult();
    service->serviceUtilization = value;
    return true;
}//setServiceUtilization

bool OSResult::setNumberOfOtherServiceResults(int num)
{
    if (num < 0) return false;

    if (service == NULL) service = new ServiceResult();
    if(service->otherResults == NULL) service->otherResults = new OtherResults();
    if (service->otherResults->other != NULL) return false;
    service->otherResults->numberOfOtherResults = num;
    if (num > 0)
    {
        service->otherResults->other = new OtherOptionOrResult*[num];
        for(int i = 0; i < num; i++)
            service->otherResults->other[i] = new OtherOptionOrResult();
    }
    return true;
}//setNumberOfOtherServiceResults

bool OSResult::setOtherServiceResultName(int idx, string name)
{
    if (service == NULL) service = new ServiceResult();
    if (service->otherResults == NULL) return false;
    if (idx < 0 || idx >= service->otherResults->numberOfOtherResults)
        return false;
    service->otherResults->other[idx]->name = name;
    return true;
}//setOtherServiceResultName

bool OSResult::setOtherServiceResultValue(int idx, string value)
{
    if (service == NULL) service = new ServiceResult();
    if (service->otherResults == NULL) return false;
    if (idx < 0 || idx >= service->otherResults->numberOfOtherResults)
        return false;
    service->otherResults->other[idx]->value = value;
    return true;
}//setOtherServiceResultValue

bool OSResult::setOtherServiceResultDescription(int idx, string description)
{
    if (service == NULL) service = new ServiceResult();
    if (service->otherResults == NULL) return false;
    if (idx < 0 || idx >= service->otherResults->numberOfOtherResults)
        return false;
    service->otherResults->other[idx]->description = description;
    return true;
}//setOtherServiceResultDescription

bool OSResult::setJobStatus(std::string status)
{
    if (verifyJobStatus(status) == 0) return false;

    if (job == NULL) job = new JobResult();
    job->status = status;
    return true;
}//setJobStatus

bool OSResult::setJobSubmitTime(std::string submitTime)
{
    if (job == NULL) job = new JobResult();
    job->submitTime = submitTime;
    return true;
}//setJobSubmitTime

bool OSResult::setScheduledStartTime(std::string scheduledStartTime)
{
    if (job == NULL) job = new JobResult();
    job->scheduledStartTime = scheduledStartTime;
    return true;
}//setScheduledStartTime

bool OSResult::setActualStartTime(std::string actualStartTime)
{
    if (job == NULL) job = new JobResult();
    job->actualStartTime = actualStartTime;
    return true;
}//setActualStartTime

bool OSResult::setJobEndTime(std::string endTime)
{
    if (job == NULL) job = new JobResult();
    job->endTime = endTime;
    return true;
}//setJobEndTime

bool OSResult::setTime(double time)
{
    return addTimingInformation("elapsedTime", "total", "second", "", time);
}//setTime

bool OSResult::addTimingInformation(std::string type, std::string category, std::string unit, std::string description, double value)

{
    int nt;
    int i;
    if (verifyTimeUnit(unit) != true)
        throw ErrorClass("Invalid unit of time in addTimingInformation()");
    if (job == NULL) job = new JobResult();
    if (job->timingInformation == NULL) job->timingInformation = new TimingInformation();

    nt = job->timingInformation->numberOfTimes;
    TimeMeasurement** temp = new TimeMeasurement*[nt+1];  //Allocate the new pointers
    for (i = 0; i < nt; i++)
        temp[i] = job->timingInformation->time[i];  //copy the pointers

    delete[] job->timingInformation->time; //delete old pointers

//	add in the new element
    temp[ nt] = new TimeMeasurement();

    temp[ nt]->type = type;
    temp[ nt]->category = category;
    temp[ nt]->unit = unit;
    temp[ nt]->description = description;
    temp[ nt]->value = value;

    job->timingInformation->time = temp;   //hook the new pointers into the data structure
    job->timingInformation->numberOfTimes = ++nt;

    return true;
}//addTimingInformation


bool OSResult::setTimingInformation(int idx, std::string type, std::string category,
                                    std::string unit, std::string description, double value)
{
    if (verifyTimeUnit(unit) == 0) return false;
    if (verifyTimeType(type) == 0) return false;
    if (verifyTimeCategory(category) == 0) return false;

    if (job == NULL) job = new JobResult();
    if (job->timingInformation == NULL) return false;
    if (idx < 0 || idx >= job->timingInformation->numberOfTimes)
        return false;

    job->timingInformation->time[idx]->type = type;
    job->timingInformation->time[idx]->category = category;
    job->timingInformation->time[idx]->unit = unit;
    job->timingInformation->time[idx]->description = description;
    job->timingInformation->time[idx]->value = value;

    return true;
}//setTimingInformation


bool OSResult::setNumberOfTimes(int numberOfTimes)
{
    if (numberOfTimes < 0) return false;

    if (job == NULL) job = new JobResult();
    if (job->timingInformation == NULL) job->timingInformation = new TimingInformation();
    job->timingInformation->numberOfTimes = numberOfTimes;
    if (numberOfTimes > 0)
    {



        job->timingInformation->time = new TimeMeasurement*[numberOfTimes];
        for(int i = 0; i < numberOfTimes; i++)
            job->timingInformation->time[i] = new TimeMeasurement();
    }
    return true;
}//setNumberOfTimes

bool OSResult::setTimeNumber(int numberOfTimes)
{
    if (numberOfTimes < 0) return false;

    if (job == NULL) job = new JobResult();
    if (job->timingInformation == NULL) job->timingInformation = new TimingInformation();
    job->timingInformation->numberOfTimes = numberOfTimes;
    return true;
}//setTimeNumber

bool OSResult::setUsedDiskSpaceUnit(std::string unit)
{
    if (verifyStorageUnit(unit) == 0) return false;

    if (job == NULL) job = new JobResult();
    if (job->usedDiskSpace == NULL) job->usedDiskSpace = new StorageCapacity();
    job->usedDiskSpace->unit = unit;
    return true;
}//setUsedDiskSpaceUnit

bool OSResult::setUsedDiskSpaceDescription(std::string description)
{
    if (job == NULL) job = new JobResult();
    if (job->usedDiskSpace == NULL) job->usedDiskSpace = new StorageCapacity();
    job->usedDiskSpace->description = description;
    return true;
}//setUsedDiskSpaceDescription

bool OSResult::setUsedDiskSpaceValue(double value)
{
    if (job == NULL) job = new JobResult();
    if (job->usedDiskSpace == NULL) job->usedDiskSpace = new StorageCapacity();
    job->usedDiskSpace->value = value;
    return true;
}//setUsedDiskSpaceValue

bool OSResult::setUsedMemoryUnit(std::string unit)
{
    if (verifyStorageUnit(unit) == 0) return false;

    if (job == NULL) job = new JobResult();
    if (job->usedMemory == NULL) job->usedMemory = new StorageCapacity();
    job->usedMemory->unit = unit;
    return true;
}//setUsedMemoryUnit

bool OSResult::setUsedMemoryDescription(std::string description)
{
    if (job == NULL) job = new JobResult();
    if (job->usedMemory == NULL) job->usedMemory = new StorageCapacity();
    job->usedMemory->description = description;
    return true;
}//setUsedMemoryDescription

bool OSResult::setUsedMemoryValue(double value)
{
    if (job == NULL) job = new JobResult();
    if (job->usedMemory == NULL) job->usedMemory = new StorageCapacity();
    job->usedMemory->value = value;
    return true;
}//setUsedMemoryValue

bool OSResult::setUsedCPUSpeedUnit(std::string unit)
{
    if ( verifyCPUSpeedUnit(unit) == 0) return false;

    if (job == NULL) job = new JobResult();
    if (job->usedCPUSpeed == NULL) job->usedCPUSpeed = new CPUSpeed();
    job->usedCPUSpeed->unit = unit;
    return true;
}//setUsedCPUSpeedUnit

bool OSResult::setUsedCPUSpeedDescription(std::string description)
{
    if (job == NULL) job = new JobResult();
    if (job->usedCPUSpeed == NULL) job->usedCPUSpeed = new CPUSpeed();
    job->usedCPUSpeed->description = description;
    return true;
}//setUsedCPUSpeedDescription

bool OSResult::setUsedCPUSpeedValue(double value)
{
    if (job == NULL) job = new JobResult();
    if (job->usedCPUSpeed == NULL) job->usedCPUSpeed = new CPUSpeed();
    job->usedCPUSpeed->value = value;
    return true;
}//setUsedCPUSpeedValue

bool OSResult::setUsedCPUNumberDescription(std::string description)
{
    if (job == NULL) job = new JobResult();
    if (job->usedCPUNumber == NULL) job->usedCPUNumber = new CPUNumber();
    job->usedCPUNumber->description = description;
    return true;
}//setUsedCPUNumberDescription

bool OSResult::setUsedCPUNumberValue(int value)
{
    if (job == NULL) job = new JobResult();
    if (job->usedCPUNumber == NULL) job->usedCPUNumber = new CPUNumber();
    job->usedCPUNumber->value = value;
    return true;
}//setUsedCPUNumberValue

bool OSResult::setNumberOfOtherJobResults(int num)
{
    if (job == NULL) job = new JobResult();
    if (job->otherResults == NULL) job->otherResults = new OtherResults();
    if (num < 0) return false;
    if (job->otherResults->other != NULL) return false;
    job->otherResults->numberOfOtherResults = num;
    if (num > 0)
    {
        job->otherResults->other = new OtherOptionOrResult*[num];
        for(int i = 0; i < num; i++)
            job->otherResults->other[i] = new OtherOptionOrResult();
    }
    return true;
}//setNumberOfOtherJobResults


bool OSResult::setOtherJobResultName(int idx, string name)
{
    if (job == NULL) job = new JobResult();
    if (job->otherResults == NULL) return false;
    if (idx < 0 || idx >= job->otherResults->numberOfOtherResults)
        return false;
    job->otherResults->other[idx]->name = name;
    return true;
}//setOtherJobResultName

bool OSResult::setOtherJobResultValue(int idx, string value)
{
    if (job == NULL) job = new JobResult();
    if (job->otherResults == NULL) return false;
    if (idx < 0 || idx >= job->otherResults->numberOfOtherResults)
        return false;
    job->otherResults->other[idx]->value = value;
    return true;
}//setOtherJobResultValue

bool OSResult::setOtherJobResultDescription(int idx, string description)
{
    if (job == NULL) job = new JobResult();
    if (job->otherResults == NULL) return false;
    if (idx < 0 || idx >= job->otherResults->numberOfOtherResults)
        return false;
    job->otherResults->other[idx]->description = description;
    return true;
}//setOtherJobResultDescription


bool OSResult::setVariableNumber(int variableNumber)
{
    if(variableNumber < 0)
        return false;
    if(optimization == NULL) optimization = new OptimizationResult();
    optimization->numberOfVariables = variableNumber;
    return true;
}//setVariableNumber

bool OSResult::setObjectiveNumber(int objectiveNumber)
{

    if(objectiveNumber < 0)
        return false;
    if(optimization == NULL) optimization = new OptimizationResult();
    optimization->numberOfObjectives = objectiveNumber;
    return true;
}//setObjectiveNumber

bool OSResult::setConstraintNumber(int constraintNumber)
{
    if(constraintNumber < 0)
        return false;
    if(optimization == NULL) optimization = new OptimizationResult();
    optimization->numberOfConstraints = constraintNumber;
    return true;
}//setConstraintNumber

bool OSResult::setSolutionNumber(int number)
{
    if(number < 0) return false;
    if(number == 0) return true;
    if(optimization == NULL) optimization = new OptimizationResult();
    optimization->numberOfSolutions = number;
    optimization->solution = new OptimizationSolution*[number];
    for(int i = 0; i < number; i++)
    {
        optimization->solution[i] = new OptimizationSolution();
    }
    return true;
}//setSolutionNumber

bool OSResult::setSolutionStatus(int solIdx, string type, string description)
{
    int nSols = this->getSolutionNumber();
    if(optimization == NULL) return false;
    if(nSols <= 0) return false;
    if(optimization->solution == NULL ||
            solIdx < 0 || solIdx >=  nSols) return false;
    if(optimization->solution[solIdx] == NULL)
        optimization->solution[solIdx] = new OptimizationSolution();
    if(optimization->solution[solIdx]->status == NULL)
        optimization->solution[solIdx]->status = new OptimizationSolutionStatus();

    if (verifySolutionStatus(type) == false) return false;

    optimization->solution[solIdx]->status->type = type;
    optimization->solution[solIdx]->status->description = description;
    return true;
}//setSolutionStatus

bool OSResult::setSolutionStatusType(int solIdx, std::string type)
{
    int nSols = this->getSolutionNumber();
    if(optimization == NULL) return false;
    if(nSols <= 0) return false;
    if(optimization->solution == NULL ||
            solIdx < 0 || solIdx >=  nSols) return false;
    if(optimization->solution[solIdx] == NULL)
        optimization->solution[solIdx] = new OptimizationSolution();
    if(optimization->solution[solIdx]->status == NULL)
        optimization->solution[solIdx]->status = new OptimizationSolutionStatus();

    if (verifySolutionStatus(type) == false) return false;

    optimization->solution[solIdx]->status->type = type;
    return true;
}//setSolutionStatusType

bool OSResult::setSolutionStatusDescription(int solIdx, std::string description)
{
    int nSols = this->getSolutionNumber();
    if(optimization == NULL) return false;
    if(nSols <= 0) return false;
    if(optimization->solution == NULL ||
            solIdx < 0 || solIdx >=  nSols) return false;
    if(optimization->solution[solIdx] == NULL)
    {
        optimization->solution[solIdx] = new OptimizationSolution();
    }
    if(optimization->solution[solIdx]->status == NULL)
    {
        optimization->solution[solIdx]->status = new OptimizationSolutionStatus();
    }
    optimization->solution[solIdx]->status->description = description;
    return true;
}//setSolutionStatusDescription

bool OSResult::setNumberOfSolutionSubstatuses(int solIdx, int num)
{
    int nSols = this->getSolutionNumber();
    if (optimization == NULL) return false;
    if (nSols <= 0) return false;
    if (optimization->solution == NULL ||
            solIdx < 0 || solIdx >=  nSols) return false;
    if (optimization->solution[solIdx] == NULL)
    {
        optimization->solution[solIdx] = new OptimizationSolution();
    }
    if (optimization->solution[solIdx]->status == NULL)
    {
        optimization->solution[solIdx]->status = new OptimizationSolutionStatus();
    }
    if (num < 0) return false;
    if (optimization->solution[solIdx]->status->substatus != NULL) return false;
    optimization->solution[solIdx]->status->numberOfSubstatuses = num;
    if (num > 0)
    {
        optimization->solution[solIdx]->status->substatus = new OptimizationSolutionSubstatus*[num];
        for(int i = 0; i < num; i++)
        {
            optimization->solution[solIdx]->status->substatus[i] = new OptimizationSolutionSubstatus();
        }
    }
    return true;
}//setNumberOfSolutionSubstatuses

bool OSResult::setSolutionSubstatusType(int solIdx, int substatusIdx, std::string type)
{
    int nSols = this->getSolutionNumber();
    if(optimization == NULL) return false;
    if(optimization->solution == NULL ||
            solIdx < 0 || solIdx >=  nSols) return false;
    if(optimization->solution[solIdx] == NULL) return false;
    if(optimization->solution[solIdx]->status == NULL) return false;
    int nSubs = optimization->solution[solIdx]->status->numberOfSubstatuses;
    if (substatusIdx < 0 || substatusIdx >= nSubs) return false;

    if (verifySolutionSubstatusType(type) == 0) return false;

    optimization->solution[solIdx]->status->substatus[substatusIdx]->type = type;
    return true;
}//setSolutionSubstatusType

bool OSResult::setSolutionSubstatusDescription(int solIdx, int substatusIdx, std::string description)
{
    int nSols = this->getSolutionNumber();
    if(optimization == NULL) return false;
    if(optimization->solution == NULL ||
            solIdx < 0 || solIdx >=  nSols) return false;
    if(optimization->solution[solIdx] == NULL) return false;
    if(optimization->solution[solIdx]->status == NULL) return false;
    int nSubs = optimization->solution[solIdx]->status->numberOfSubstatuses;
    if (substatusIdx < 0 || substatusIdx >= nSubs) return false;
    optimization->solution[solIdx]->status->substatus[substatusIdx]->description = description;
    return true;
}//setSolutionSubstatusDescription

bool OSResult::setSolutionTargetObjectiveIdx(int solIdx, int objectiveIdx)
{
    int nSols = this->getSolutionNumber();
    if(optimization == NULL) return false;
    if(nSols <= 0) return false;
    if(optimization == NULL) return false;
    if(optimization->solution == NULL ||
            solIdx < 0 || solIdx >=  nSols) return false;
    if(optimization->solution[solIdx] == NULL)
    {
        optimization->solution[solIdx] = new OptimizationSolution();
    }
    if(objectiveIdx >= 0) return false;
    optimization->solution[solIdx]->targetObjectiveIdx = objectiveIdx;
    return true;
}//setSolutionTargetObjectiveIdx

bool OSResult::setSolutionTargetObjectiveName(int solIdx, std::string objectiveName)
{
    int nSols = this->getSolutionNumber();
    if(optimization == NULL) return false;
    if(nSols <= 0) return false;
    if(optimization == NULL) return false;
    if(optimization->solution == NULL ||
            solIdx < 0 || solIdx >=  nSols) return false;
    if(optimization->solution[solIdx] == NULL)
    {
        optimization->solution[solIdx] = new OptimizationSolution();
    }
    optimization->solution[solIdx]->targetObjectiveName = objectiveName;
    return true;
}//setSolutionTargetObjectiveName

bool OSResult::setSolutionWeightedObjectives(int solIdx, bool weightedObjectives)
{
    int nSols = this->getSolutionNumber();
    if (optimization == NULL) return false;
    if (nSols <= 0) return false;
    if (optimization == NULL) return false;
    if (optimization->solution == NULL ||
            solIdx < 0 || solIdx >=  nSols) return false;
    if (optimization->solution[solIdx] == NULL)
        optimization->solution[solIdx] = new OptimizationSolution();
    optimization->solution[solIdx]->weightedObjectives = weightedObjectives;
    return true;
}//setSolutionWeightedObjectives

bool OSResult::setSolutionMessage(int solIdx, std::string msg)
{
    int nSols = this->getSolutionNumber();
    if(optimization == NULL) return false;
    if(nSols <= 0) return false;
    if(optimization == NULL) return false;
    if(optimization->solution == NULL ||
            solIdx < 0 || solIdx >=  nSols) return false;
    if(optimization->solution[solIdx] == NULL)
    {
        optimization->solution[solIdx] = new OptimizationSolution();
    }
    optimization->solution[solIdx]->message = msg;
    return true;
}//setSolutionMessage

bool OSResult::setNumberOfPrimalVariableValues(int solIdx, int numberOfVar)
{
    int nSols = this->getSolutionNumber();
    int nVar  = this->getVariableNumber();
    if (numberOfVar <= 0 || numberOfVar > nVar) return false;
    if (optimization == NULL) return false;
    if (nSols <= 0) return false;
    if (optimization->solution == NULL ||
            solIdx < 0 || solIdx >=  nSols) return false;
    if (optimization->solution[solIdx] == NULL)
    {
        optimization->solution[solIdx] = new OptimizationSolution();
    }
    if (optimization->solution[solIdx]->variables == NULL)
    {
        optimization->solution[solIdx]->variables = new VariableSolution();
    }
    if (optimization->solution[solIdx]->variables->values == NULL)
    {
        optimization->solution[solIdx]->variables->values = new VariableValues();
    }
    if (numberOfVar < 0) return false;
    if (optimization->solution[solIdx]->variables->values->var != NULL) return false;
    optimization->solution[solIdx]->variables->values->numberOfVar = numberOfVar;
    if (numberOfVar > 0)
        optimization->solution[solIdx]->variables->values->var = new VarValue*[numberOfVar];
    return true;
}//setNumberOfPrimalVariableValues

bool OSResult::setPrimalVariableValuesSparse(int solIdx, std::vector<IndexValuePair*> x)
{
    int nSols = this->getSolutionNumber();
    int numberOfVar = x.size();
    if(optimization == NULL) return false;
    if(nSols <= 0) return false;
    if(optimization->solution == NULL ||
            solIdx < 0 || solIdx >=  nSols) return false;
    if(optimization->solution[solIdx] == NULL)
    {
        optimization->solution[solIdx] = new OptimizationSolution();
    }
    if(optimization->solution[solIdx]->variables == NULL)
    {
        optimization->solution[solIdx]->variables = new VariableSolution();
    }
    if (optimization->solution[solIdx]->variables->values == NULL)
    {
        optimization->solution[solIdx]->variables->values = new VariableValues();
    }
    if (optimization->solution[solIdx]->variables->values->var == NULL)
    {
        optimization->solution[solIdx]->variables->values->var = new VarValue*[numberOfVar];
    }
    optimization->solution[solIdx]->variables->values->numberOfVar = numberOfVar;
    if(x.size() == 0)
    {
        //optimization->solution[solIdx]->variables->values->var = NULL;
        return true;
    }
    for(int i = 0; i < numberOfVar; i++)
    {
        optimization->solution[solIdx]->variables->values->var[i] = new VarValue();
        optimization->solution[solIdx]->variables->values->var[i]->idx = x[i]->idx;
        optimization->solution[solIdx]->variables->values->var[i]->value = x[i]->value;
    }
    return true;
}//setPrimalVariableValuesSparse

bool OSResult::setPrimalVariableValuesDense(int solIdx, double *x)
{
    int numberOfVar = this->getVariableNumber();
    int nSols = this->getSolutionNumber();
    if(optimization == NULL) return false;
    if(nSols <= 0) return false;
    if(optimization->solution == NULL ||
            solIdx < 0 || solIdx >=  nSols) return false;
    if(optimization->solution[solIdx] == NULL)
    {
        optimization->solution[solIdx] = new OptimizationSolution();
    }
    if(optimization->solution[solIdx]->variables == NULL)
    {
        optimization->solution[solIdx]->variables = new VariableSolution();
    }
    if(optimization->solution[solIdx]->variables->values == NULL)
    {
        optimization->solution[solIdx]->variables->values = new VariableValues();
    }
    if(optimization->solution[solIdx]->variables->values->var == NULL)
    {
        optimization->solution[solIdx]->variables->values->var = new VarValue*[numberOfVar];
    }
    optimization->solution[solIdx]->variables->values->numberOfVar = numberOfVar;
    if(x == NULL)
    {
        //optimization->solution[solIdx]->variables->values->var = NULL;
        return true;
    }
    for(int i = 0; i < numberOfVar; i++)
    {
        optimization->solution[solIdx]->variables->values->var[i] = new VarValue();
        optimization->solution[solIdx]->variables->values->var[i]->idx = i;
        optimization->solution[solIdx]->variables->values->var[i]->value = x[i];
    }
    return true;
}//setPrimalVariableValuesDense

bool OSResult::setNumberOfVarValues(int solIdx, int numberOfVar)
{
    if (optimization == NULL || optimization->solution == NULL)
    {
        //	throw ErrorClass("No optimization or solution object defined");
        return false;
    }
    int nSols = optimization->numberOfSolutions;
    if (solIdx < 0 || solIdx >=  nSols) return false;
    if (optimization->solution[solIdx] == NULL)
        optimization->solution[solIdx] = new OptimizationSolution();
    if (optimization->solution[solIdx]->variables == NULL)
        optimization->solution[solIdx]->variables = new VariableSolution();
    if (optimization->solution[solIdx]->variables->values == NULL)
        optimization->solution[solIdx]->variables->values = new VariableValues();
    if (optimization->solution[solIdx]->variables->values->numberOfVar > 0) return false;
    if (numberOfVar < 0) return false;
    if (optimization->solution[solIdx]->variables->values->var != NULL) return false;
    optimization->solution[solIdx]->variables->values->numberOfVar = numberOfVar;
    if (numberOfVar > 0)
    {
        optimization->solution[solIdx]->variables->values->var = new VarValue*[numberOfVar];
        for(int i = 0; i < numberOfVar; i++)
            optimization->solution[solIdx]->variables->values->var[i] = new VarValue();
    }
    return true;
}//setNumberOfVarValues

bool OSResult::setVarValue(int solIdx, int number, int idx, std::string name, double val)
{
    if (optimization == NULL || optimization->solution == NULL)
    {
        //	throw ErrorClass("No optimization or solution object defined");
        return false;
    }
    int nSols = optimization->numberOfSolutions;
    if (solIdx < 0 || solIdx >=  nSols)
    {
        //	throw ErrorClass("Trying to use a solution that was not previously declared");
        return false;
    }
    if (optimization->solution[solIdx] == NULL)
    {
        //	throw ErrorClass("Solution object not previously defined");
        return false;
    }
    if (optimization->solution[solIdx]->variables == NULL)
    {
        //	throw ErrorClass("variables object not previously defined");
        return false;
    }
    if (optimization->solution[solIdx]->variables->values == NULL)
    {
        //	throw ErrorClass("values object not previously defined");
        return false;
    }
    int nVar = 	optimization->solution[solIdx]->variables->values->numberOfVar;
    if (number < 0 || number >= nVar)
    {
        //	throw ErrorClass("Trying to set value outside of var array boundaries");
        return false;
    }
    if (idx < 0)
    {
        //	throw ErrorClass("Variable index cannot be negative.");
        return false;
    }
    optimization->solution[solIdx]->variables->values->var[number]->idx   = idx;
    optimization->solution[solIdx]->variables->values->var[number]->name  = name;
    optimization->solution[solIdx]->variables->values->var[number]->value = val;
    return true;
}//setVarValue


bool OSResult::setNumberOfVarValuesString(int solIdx, int numberOfVar)
{
    if (optimization == NULL || optimization->solution == NULL)
    {
        //	throw ErrorClass("No optimization or solution object defined");
        return false;
    }
    int nSols = optimization->numberOfSolutions;
    if (solIdx < 0 || solIdx >=  nSols)
    {
        //	throw ErrorClass("Trying to use a solution that was not previously declared");
        return false;
    }
    if (optimization->solution[solIdx] == NULL)
        optimization->solution[solIdx] = new OptimizationSolution();
    if (optimization->solution[solIdx]->variables == NULL)
        optimization->solution[solIdx]->variables = new VariableSolution();
    if (optimization->solution[solIdx]->variables->valuesString == NULL)
        optimization->solution[solIdx]->variables->valuesString = new VariableValuesString();
    if (optimization->solution[solIdx]->variables->valuesString->numberOfVar > 0)
        return false;
    if (numberOfVar < 0) return false;
    if (optimization->solution[solIdx]->variables->valuesString->var != NULL) return false;
    optimization->solution[solIdx]->variables->valuesString->numberOfVar = numberOfVar;
    if (numberOfVar > 0)
    {
        optimization->solution[solIdx]->variables->valuesString->var = new VarValueString*[numberOfVar];
        for(int i = 0; i < numberOfVar; i++)
            optimization->solution[solIdx]->variables->valuesString->var[i] = new VarValueString();
    }
    return true;
}//setNumberOfVarValuesString

bool OSResult::setVarValueString(int solIdx, int number, int idx, std::string name, std::string str)
{
    if (optimization == NULL || optimization->solution == NULL)
    {
        //	throw ErrorClass("No optimization or solution object defined");
        return false;
    }
    int nSols = optimization->numberOfSolutions;
    if (solIdx < 0 || solIdx >=  nSols)
    {
        //	throw ErrorClass("Trying to use a solution that was not previously declared");
        return false;
    }
    if (optimization->solution[solIdx] == NULL)
    {
        //	throw ErrorClass("Solution object not previously defined");
        return false;
    }
    if (optimization->solution[solIdx]->variables == NULL)
    {
        //	throw ErrorClass("variables object not previously defined");
        return false;
    }
    if (optimization->solution[solIdx]->variables->valuesString == NULL)
    {
        //	throw ErrorClass("values object not previously defined");
        return false;
    }
    int nVar = 	optimization->solution[solIdx]->variables->valuesString->numberOfVar;
    if (number < 0 || number >= nVar)
    {
        //	throw ErrorClass("Trying to set value outside of var array boundaries");
        return false;
    }
    if (idx < 0)
    {
        //	throw ErrorClass("Variable index cannot be negative.");
        return false;
    }
    optimization->solution[solIdx]->variables->valuesString->var[number]->idx   = idx;
    optimization->solution[solIdx]->variables->valuesString->var[number]->name  = name;
    optimization->solution[solIdx]->variables->valuesString->var[number]->value = str;
    return true;
}//setVarValueString

bool OSResult::setBasisStatus(int solIdx, int object, int status, int *i, int ni)
{
    if (optimization == NULL || optimization->solution == NULL)
        return false;
    int nSols = optimization->numberOfSolutions;
    if (solIdx < 0 || solIdx >=  nSols)
        return false;
    if (optimization->solution[solIdx] == NULL)
        optimization->solution[solIdx] = new OptimizationSolution();

    switch (object)
    {
    case ENUM_PROBLEM_COMPONENT_variables:
    {
        if (optimization->solution[solIdx]->variables == NULL)
            optimization->solution[solIdx]->variables = new VariableSolution();
        if (optimization->solution[solIdx]->variables->basisStatus == NULL)
            optimization->solution[solIdx]->variables->basisStatus = new BasisStatus();
        for (int j=0; j<ni; j++) if (i[j] < 0) return false;
        return optimization->solution[solIdx]->variables->basisStatus->setIntVector(status, i, ni);
    }
    case ENUM_PROBLEM_COMPONENT_objectives:
    {
        if (optimization->solution[solIdx]->objectives == NULL)
            optimization->solution[solIdx]->objectives = new ObjectiveSolution();
        if (optimization->solution[solIdx]->objectives->basisStatus == NULL)
            optimization->solution[solIdx]->objectives->basisStatus = new BasisStatus();
        for (int j=0; j<ni; j++) if (i[j] >= 0) return false;
        return optimization->solution[solIdx]->objectives->basisStatus->setIntVector(status, i, ni);
    }
    case ENUM_PROBLEM_COMPONENT_constraints:
    {
        if (optimization->solution[solIdx]->constraints == NULL)
            optimization->solution[solIdx]->constraints = new ConstraintSolution();
        if (optimization->solution[solIdx]->constraints->basisStatus == NULL)
            optimization->solution[solIdx]->constraints->basisStatus = new BasisStatus();
        for (int j=0; j<ni; j++) if (i[j] < 0) return false;
        return optimization->solution[solIdx]->constraints->basisStatus->setIntVector(status, i, ni);
    }
    default:
        throw ErrorClass("target object not implemented in setBasisStatus");
    }
}//setBasisStatus

bool OSResult::setNumberOfOtherVariableResults(int solIdx, int num)
{
    //int iNumberOfVariables = this->getVariableNumber();
    //if(iNumberOfVariables <= 0) return false;
    int nSols = this->getSolutionNumber();
    if (nSols <= 0) return false;
    if (optimization == NULL) return false;
    if (optimization->solution == NULL ||
            solIdx < 0 || solIdx >=  nSols) return false;
    if (optimization->solution[solIdx] == NULL)
        optimization->solution[solIdx] = new OptimizationSolution();
    if (optimization->solution[solIdx]->variables == NULL)
        optimization->solution[solIdx]->variables = new VariableSolution();
    if (num < 0) return false;
    if (optimization->solution[solIdx]->variables->other != NULL) return false;
    optimization->solution[solIdx]->variables->numberOfOtherVariableResults = num;
    if (num > 0)
    {
        optimization->solution[solIdx]->variables->other = new OtherVariableResult*[num];
        for(int i = 0; i < num; i++)
            optimization->solution[solIdx]->variables->other[ i]  = new OtherVariableResult();
    }
    return true;
}//setNumberOfOtherVariableResults


bool OSResult::setAnOtherVariableResultSparse(int solIdx, int otherIdx, string name, string value, string description, int  *idx,  string *s, int numberOfVar)
{
    int iNumberOfVariables = numberOfVar;
    if(iNumberOfVariables <= -1) return false;
    int nSols = this->getSolutionNumber();
    if(optimization == NULL) return false;
    if(nSols <= 0) return false;
    if(optimization == NULL) return false;
    if(optimization->solution == NULL ||
            solIdx < 0 || solIdx >=  nSols) return false;
    if(optimization->solution[solIdx] == NULL) return false;
    if(optimization->solution[solIdx]->variables == NULL)return false;
    if(optimization->solution[solIdx]->variables->other == NULL) return false;
    if(optimization->solution[solIdx]->variables->other[ otherIdx] == NULL) return false;
    optimization->solution[solIdx]->variables->other[ otherIdx]->name = name;
    optimization->solution[solIdx]->variables->other[ otherIdx]->value = value;
    optimization->solution[solIdx]->variables->other[ otherIdx]->description = description;
    optimization->solution[solIdx]->variables->other[ otherIdx]->numberOfVar = numberOfVar;
    if (optimization->solution[solIdx]->variables->other[ otherIdx]->var == NULL)
        optimization->solution[solIdx]->variables->other[ otherIdx]->var = new OtherVarResult*[numberOfVar];
    for(int i = 0; i < numberOfVar; i++)
    {
        optimization->solution[solIdx]->variables->other[ otherIdx]->var[i] = new OtherVarResult();
        optimization->solution[solIdx]->variables->other[ otherIdx]->var[i]->idx = idx[i];
        optimization->solution[solIdx]->variables->other[ otherIdx]->var[i]->value = s[i];
    }
    return true;
}//setAnOtherVariableResultSparse


bool OSResult::setAnOtherVariableResultSparse(int solIdx, int otherIdx, string name, string value, string description, int  *idx,  string *s, int numberOfVar, std::string type, std::string varType, std::string enumType)
{
    int iNumberOfVariables = numberOfVar;
    if(iNumberOfVariables <= -1) return false;
    int nSols = this->getSolutionNumber();
    if(optimization == NULL) return false;
    if(nSols <= 0) return false;
    if(optimization == NULL) return false;
    if(optimization->solution == NULL ||
            solIdx < 0 || solIdx >=  nSols) return false;
    if(optimization->solution[solIdx] == NULL) return false;
    if(optimization->solution[solIdx]->variables == NULL)return false;
    if(optimization->solution[solIdx]->variables->other == NULL) return false;
    if(optimization->solution[solIdx]->variables->other[ otherIdx] == NULL) return false;
    optimization->solution[solIdx]->variables->other[ otherIdx]->name = name;
    optimization->solution[solIdx]->variables->other[ otherIdx]->type = type;
    optimization->solution[solIdx]->variables->other[ otherIdx]->varType = varType;
    optimization->solution[solIdx]->variables->other[ otherIdx]->enumType = enumType;
    optimization->solution[solIdx]->variables->other[ otherIdx]->value = value;
    optimization->solution[solIdx]->variables->other[ otherIdx]->description = description;
    optimization->solution[solIdx]->variables->other[ otherIdx]->numberOfVar = numberOfVar;
    if (optimization->solution[solIdx]->variables->other[ otherIdx]->var != NULL) return false;
    optimization->solution[solIdx]->variables->other[ otherIdx]->var = new OtherVarResult*[numberOfVar];
    for(int i = 0; i < numberOfVar; i++)
    {
        optimization->solution[solIdx]->variables->other[ otherIdx]->var[i] = new OtherVarResult();
        optimization->solution[solIdx]->variables->other[ otherIdx]->var[i]->idx = idx[i];
        optimization->solution[solIdx]->variables->other[ otherIdx]->var[i]->value = s[i];
    }
    return true;
}//setAnOtherVariableResultSparse


bool OSResult::setAnOtherVariableResultDense(int solIdx, int otherIdx, string name, string value, string description, string *s)
{
    int numberOfVar = this->getVariableNumber();
    int iNumberOfVariables = numberOfVar;
    if (iNumberOfVariables <= -1) return false;
    int nSols = this->getSolutionNumber();
    if (optimization == NULL) return false;
    if (nSols <= 0) return false;
    if (optimization == NULL) return false;
    if (optimization->solution == NULL ||
            solIdx < 0 || solIdx >=  nSols) return false;
    if (optimization->solution[solIdx] == NULL) return false;
    if (optimization->solution[solIdx]->variables == NULL)return false;
    if (optimization->solution[solIdx]->variables->other == NULL) return false;
    if (optimization->solution[solIdx]->variables->other[ otherIdx] == NULL) return false;
    optimization->solution[solIdx]->variables->other[ otherIdx]->name = name;
    optimization->solution[solIdx]->variables->other[ otherIdx]->value = value;
    optimization->solution[solIdx]->variables->other[ otherIdx]->description = description;
    optimization->solution[solIdx]->variables->other[ otherIdx]->numberOfVar = numberOfVar;
    if (optimization->solution[solIdx]->variables->other[ otherIdx]->var == NULL)
        optimization->solution[solIdx]->variables->other[ otherIdx]->var = new OtherVarResult*[numberOfVar];
    for(int i = 0; i < numberOfVar; i++)
    {
        optimization->solution[solIdx]->variables->other[ otherIdx]->var[i] = new OtherVarResult();
        optimization->solution[solIdx]->variables->other[ otherIdx]->var[i]->idx = i;
        optimization->solution[solIdx]->variables->other[ otherIdx]->var[i]->value = s[i];
        ;
    }
    return true;
}//setAnOtherVariableResultDense

bool OSResult::setAnOtherVariableResultDense(int solIdx, int otherIdx, string name, string value, string description, string *s, std::string type, std::string varType, std::string enumType)
{
    int numberOfVar = this->getVariableNumber();
    int iNumberOfVariables = numberOfVar;
    if(iNumberOfVariables <= -1) return false;
    int nSols = this->getSolutionNumber();
    if(optimization == NULL) return false;
    if(nSols <= 0) return false;
    if(optimization == NULL) return false;
    if(optimization->solution == NULL ||
            solIdx < 0 || solIdx >=  nSols) return false;
    if(optimization->solution[solIdx] == NULL) return false;
    if(optimization->solution[solIdx]->variables == NULL)return false;
    if(optimization->solution[solIdx]->variables->other == NULL) return false;
    if(optimization->solution[solIdx]->variables->other[ otherIdx] == NULL) return false;
    optimization->solution[solIdx]->variables->other[ otherIdx]->name = name;
    optimization->solution[solIdx]->variables->other[ otherIdx]->type = type;
    optimization->solution[solIdx]->variables->other[ otherIdx]->varType = varType;
    optimization->solution[solIdx]->variables->other[ otherIdx]->enumType = enumType;
    optimization->solution[solIdx]->variables->other[ otherIdx]->value = value;
    optimization->solution[solIdx]->variables->other[ otherIdx]->description = description;
    optimization->solution[solIdx]->variables->other[ otherIdx]->numberOfVar = numberOfVar;
    if(optimization->solution[solIdx]->variables->other[ otherIdx]->var != NULL) return false;
    optimization->solution[solIdx]->variables->other[ otherIdx]->var = new OtherVarResult*[numberOfVar];
    for(int i = 0; i < numberOfVar; i++)
    {
        optimization->solution[solIdx]->variables->other[ otherIdx]->var[i] = new OtherVarResult();
        optimization->solution[solIdx]->variables->other[ otherIdx]->var[i]->idx = i;
        optimization->solution[solIdx]->variables->other[ otherIdx]->var[i]->value = s[i];
        ;
    }
    return true;
}//setAnOtherVariableResultDense

bool OSResult::setOtherVariableResultNumberOfVar(int solIdx, int otherIdx, int numberOfVar)
{
    int iNumberOfVariables = numberOfVar;
    if (iNumberOfVariables <= -1) return false;
    int nSols = this->getSolutionNumber();
    if (nSols <= 0) return false;
    if (optimization == NULL) return false;
    if (optimization->solution == NULL ||
            solIdx < 0 || solIdx >=  nSols) return false;
    if (optimization->solution[solIdx] == NULL) return false;
    if (optimization->solution[solIdx]->variables == NULL) return false;
    if (optimization->solution[solIdx]->variables->other == NULL) return false;
    if (optimization->solution[solIdx]->variables->other[ otherIdx] == NULL) return false;
    if (optimization->solution[solIdx]->variables->other[ otherIdx]->var == NULL)
        optimization->solution[solIdx]->variables->other[ otherIdx]->var = new OtherVarResult*[numberOfVar];
    for(int i = 0; i < numberOfVar; i++)
        optimization->solution[solIdx]->variables->other[ otherIdx]->var[i] = new OtherVarResult();
    optimization->solution[solIdx]->variables->other[ otherIdx]->numberOfVar = numberOfVar;
    return true;
}//setOtherVariableResultNumberOfVar


bool OSResult::setOtherVariableResultNumberOfEnumerations(int solIdx, int otherIdx, int numberOfEnumerations)
{
    int iNumberOfEnumerations = numberOfEnumerations;
    if (iNumberOfEnumerations <= -1) return false;
    int nSols = this->getSolutionNumber();
    if (nSols <= 0) return false;
    if (optimization == NULL) return false;
    if (optimization->solution == NULL ||
            solIdx < 0 || solIdx >=  nSols) return false;
    if (optimization->solution[solIdx] == NULL) return false;
    if (optimization->solution[solIdx]->variables == NULL) return false;
    if (optimization->solution[solIdx]->variables->other == NULL) return false;
    if (optimization->solution[solIdx]->variables->other[ otherIdx] == NULL) return false;
    if (optimization->solution[solIdx]->variables->other[ otherIdx]->enumeration == NULL)
        optimization->solution[solIdx]->variables->other[ otherIdx]->enumeration = new OtherOptionOrResultEnumeration*[numberOfEnumerations];
    for(int i = 0; i < numberOfEnumerations; i++)
        optimization->solution[solIdx]->variables->other[ otherIdx]->enumeration[i] = new OtherOptionOrResultEnumeration();
    optimization->solution[solIdx]->variables->other[ otherIdx]->numberOfEnumerations = numberOfEnumerations;
    return true;
}//setOtherVariableResultNumberOfEnumerations

bool OSResult::setOtherVariableResultName(int solIdx, int otherIdx, std::string name)
{
    int numberOfVar = this->getVariableNumber();
    int iNumberOfVariables = numberOfVar;
    if (iNumberOfVariables <= -1) return false;
    int nSols = this->getSolutionNumber();
    if (optimization == NULL) return false;
    if (nSols <= 0) return false;
    if (optimization == NULL) return false;
    if (optimization->solution == NULL ||
            solIdx < 0 || solIdx >=  nSols) return false;
    if (optimization->solution[solIdx] == NULL) return false;
    if (optimization->solution[solIdx]->variables == NULL)return false;
    if (optimization->solution[solIdx]->variables->other == NULL) return false;
    if (optimization->solution[solIdx]->variables->other[ otherIdx] == NULL) return false;
    optimization->solution[solIdx]->variables->other[ otherIdx]->name = name;
    return true;
}//setOtherVariableResultName

bool OSResult::setOtherVariableResultType(int solIdx, int otherIdx, std::string type)
{
    int numberOfVar = this->getVariableNumber();
    int iNumberOfVariables = numberOfVar;
    if (iNumberOfVariables <= -1) return false;
    int nSols = this->getSolutionNumber();
    if (optimization == NULL) return false;
    if (nSols <= 0) return false;
    if (optimization == NULL) return false;
    if (optimization->solution == NULL ||
            solIdx < 0 || solIdx >=  nSols) return false;
    if (optimization->solution[solIdx] == NULL) return false;
    if (optimization->solution[solIdx]->variables == NULL)return false;
    if (optimization->solution[solIdx]->variables->other == NULL) return false;
    if (optimization->solution[solIdx]->variables->other[ otherIdx] == NULL) return false;
    optimization->solution[solIdx]->variables->other[ otherIdx]->type = type;
    return true;
}//setOtherVariableResultType

bool OSResult::setOtherVariableResultVarType(int solIdx, int otherIdx, std::string varType)
{
    int numberOfVar = this->getVariableNumber();
    int iNumberOfVariables = numberOfVar;
    if (iNumberOfVariables <= -1) return false;
    int nSols = this->getSolutionNumber();
    if (optimization == NULL) return false;
    if (nSols <= 0) return false;
    if (optimization == NULL) return false;
    if (optimization->solution == NULL ||
            solIdx < 0 || solIdx >=  nSols) return false;
    if (optimization->solution[solIdx] == NULL) return false;


    if (optimization->solution[solIdx]->variables == NULL)return false;
    if (optimization->solution[solIdx]->variables->other == NULL) return false;
    if (optimization->solution[solIdx]->variables->other[ otherIdx] == NULL) return false;
    optimization->solution[solIdx]->variables->other[ otherIdx]->varType = varType;
    return true;
}//setOtherVariableResultVarType

bool OSResult::setOtherVariableResultEnumType(int solIdx, int otherIdx, std::string enumType)
{
    int numberOfVar = this->getVariableNumber();
    int iNumberOfVariables = numberOfVar;
    if (iNumberOfVariables <= -1) return false;
    int nSols = this->getSolutionNumber();
    if (optimization == NULL) return false;
    if (nSols <= 0) return false;
    if (optimization == NULL) return false;
    if (optimization->solution == NULL ||
            solIdx < 0 || solIdx >=  nSols) return false;
    if (optimization->solution[solIdx] == NULL) return false;
    if (optimization->solution[solIdx]->variables == NULL)return false;
    if (optimization->solution[solIdx]->variables->other == NULL) return false;
    if (optimization->solution[solIdx]->variables->other[ otherIdx] == NULL) return false;
    optimization->solution[solIdx]->variables->other[ otherIdx]->enumType = enumType;
    return true;
}//setOtherVariableResultEnumType

bool OSResult::setOtherVariableResultValue(int solIdx, int otherIdx, std::string value)
{
    int numberOfVar = this->getVariableNumber();
    int iNumberOfVariables = numberOfVar;
    if (iNumberOfVariables <= -1) return false;
    int nSols = this->getSolutionNumber();
    if (optimization == NULL) return false;
    if (nSols <= 0) return false;
    if (optimization == NULL) return false;
    if (optimization->solution == NULL ||
            solIdx < 0 || solIdx >=  nSols) return false;
    if (optimization->solution[solIdx] == NULL) return false;
    if (optimization->solution[solIdx]->variables == NULL)return false;
    if (optimization->solution[solIdx]->variables->other == NULL) return false;
    if (optimization->solution[solIdx]->variables->other[ otherIdx] == NULL) return false;
    optimization->solution[solIdx]->variables->other[ otherIdx]->value = value;
    return true;
}//setOtherVariableResultValue

bool OSResult::setOtherVariableResultDescription(int solIdx, int otherIdx, std::string description)
{
    int numberOfVar = this->getVariableNumber();
    int iNumberOfVariables = numberOfVar;
    if (iNumberOfVariables <= -1) return false;
    int nSols = this->getSolutionNumber();
    if (optimization == NULL) return false;
    if (nSols <= 0) return false;
    if (optimization == NULL) return false;
    if (optimization->solution == NULL ||
            solIdx < 0 || solIdx >=  nSols) return false;
    if (optimization->solution[solIdx] == NULL) return false;
    if (optimization->solution[solIdx]->variables == NULL)return false;
    if (optimization->solution[solIdx]->variables->other == NULL) return false;
    if (optimization->solution[solIdx]->variables->other[ otherIdx] == NULL) return false;
    optimization->solution[solIdx]->variables->other[ otherIdx]->description = description;
    return true;
}//setOtherVariableResultDescription

bool OSResult::setOtherVariableResultSolver(int solIdx, int otherIdx, std::string solver)
{
    int numberOfVar = this->getVariableNumber();
    int iNumberOfVariables = numberOfVar;
    if (iNumberOfVariables <= -1) return false;
    int nSols = this->getSolutionNumber();
    if (optimization == NULL) return false;
    if (nSols <= 0) return false;
    if (optimization == NULL) return false;
    if (optimization->solution == NULL ||
            solIdx < 0 || solIdx >=  nSols) return false;
    if (optimization->solution[solIdx] == NULL) return false;
    if (optimization->solution[solIdx]->variables == NULL)return false;
    if (optimization->solution[solIdx]->variables->other == NULL) return false;
    if (optimization->solution[solIdx]->variables->other[ otherIdx] == NULL) return false;
    optimization->solution[solIdx]->variables->other[ otherIdx]->solver = solver;
    return true;
}//setOtherVariableResultSolver

bool OSResult::setOtherVariableResultCategory(int solIdx, int otherIdx, std::string category)
{
    int numberOfVar = this->getVariableNumber();
    int iNumberOfVariables = numberOfVar;
    if (iNumberOfVariables <= -1) return false;
    int nSols = this->getSolutionNumber();
    if (optimization == NULL) return false;
    if (nSols <= 0) return false;
    if (optimization == NULL) return false;
    if (optimization->solution == NULL ||
            solIdx < 0 || solIdx >=  nSols) return false;
    if (optimization->solution[solIdx] == NULL) return false;
    if (optimization->solution[solIdx]->variables == NULL)return false;
    if (optimization->solution[solIdx]->variables->other == NULL) return false;
    if (optimization->solution[solIdx]->variables->other[ otherIdx] == NULL) return false;
    optimization->solution[solIdx]->variables->other[ otherIdx]->category = category;
    return true;
}//setOtherVariableResultCategory

bool OSResult::setOtherVariableResultVarIdx(int solIdx, int otherIdx, int varIdx, int idx)
{
    int nSols = this->getSolutionNumber();
    if(nSols <= 0) return false;
    if(optimization == NULL) return false;
    if(optimization->solution == NULL ||
            solIdx < 0 || solIdx >=  nSols) return false;
    if(optimization->solution[solIdx] == NULL) return false;
    if(optimization->solution[solIdx]->variables == NULL) return false;
    if(optimization->solution[solIdx]->variables->other[otherIdx] == NULL) return false;
    if(optimization->solution[solIdx]->variables->other[otherIdx]->var == NULL) return false;
    if (idx < 0) return false;
    optimization->solution[solIdx]->variables->other[otherIdx]->var[varIdx]->idx = idx;
    return true;
}//setOtherVariableResultVarIdx

bool OSResult::setOtherVariableResultVarName(int solIdx, int otherIdx, int varIdx, std::string name)
{
    int nSols = this->getSolutionNumber();
    if(nSols <= 0) return false;
    if(optimization == NULL) return false;
    if(optimization->solution == NULL ||
            solIdx < 0 || solIdx >=  nSols) return false;
    if(optimization->solution[solIdx] == NULL) return false;
    if(optimization->solution[solIdx]->variables == NULL) return false;
    if(optimization->solution[solIdx]->variables->other[otherIdx] == NULL) return false;
    if(optimization->solution[solIdx]->variables->other[otherIdx]->var == NULL) return false;
    optimization->solution[solIdx]->variables->other[otherIdx]->var[varIdx]->name = name;
    return true;
}//setOtherVariableResultVarName

bool OSResult::setOtherVariableResultVar(int solIdx, int otherIdx, int varIdx, std::string value)
{
    int nSols = this->getSolutionNumber();
    if(nSols <= 0) return false;
    if(optimization == NULL) return false;
    if(optimization->solution == NULL ||
            solIdx < 0 || solIdx >=  nSols) return false;
    if(optimization->solution[solIdx] == NULL) return false;
    if(optimization->solution[solIdx]->variables == NULL) return false;
    if(optimization->solution[solIdx]->variables->other[otherIdx] == NULL) return false;
    if(optimization->solution[solIdx]->variables->other[otherIdx]->var == NULL) return false;
    optimization->solution[solIdx]->variables->other[otherIdx]->var[varIdx]->value = value;
    return true;
}//setOtherVariableResultVar

bool OSResult::setOtherOptionOrResultEnumeration(int solIdx, int otherIdx, int object, int enumIdx, std::string value, std::string description, int *i, int ni)
{
    if (optimization == NULL || optimization->solution == NULL)
        return false;
    int nSols = optimization->numberOfSolutions;
    if (solIdx < 0 || solIdx >=  nSols)
        return false;
    if (optimization->solution[solIdx] == NULL) return false;

    switch (object)
    {
    case ENUM_PROBLEM_COMPONENT_variables:
    {
        if (optimization->solution[solIdx]->variables == NULL) return false;
        if (optimization->solution[solIdx]->variables->other == NULL) return false;
        int n_other = optimization->solution[solIdx]->variables->numberOfOtherVariableResults;
        if (otherIdx < 0 || otherIdx >= n_other) return false;
        if (optimization->solution[solIdx]->variables->other[ otherIdx] == NULL) return false;
        if (optimization->solution[solIdx]->variables->other[ otherIdx]->enumeration == NULL) return false;
        int n_enum = optimization->solution[solIdx]->variables->other[ otherIdx]->numberOfEnumerations;
        if (enumIdx < 0 || enumIdx >= n_enum) return false;
        if (optimization->solution[solIdx]->variables->other[ otherIdx]->enumeration[enumIdx] == NULL)
            optimization->solution[solIdx]->variables->other[ otherIdx]->enumeration[enumIdx] = new OtherOptionOrResultEnumeration();
        for (int j=0; j<ni; j++) if (i[j] < 0) return false;
        return optimization->solution[solIdx]->variables->other[ otherIdx]->enumeration[enumIdx]->setOtherOptionOrResultEnumeration(value, description, i, ni);
    }
    case ENUM_PROBLEM_COMPONENT_objectives:
    {
        if (optimization->solution[solIdx]->objectives == NULL) return false;
        if (optimization->solution[solIdx]->objectives->other == NULL) return false;
        if (optimization->solution[solIdx]->objectives->other[ otherIdx] == NULL) return false;
        if (optimization->solution[solIdx]->objectives->other[ otherIdx]->enumeration == NULL) return false;
        int n_enum = optimization->solution[solIdx]->objectives->other[ otherIdx]->numberOfEnumerations;
        if (enumIdx < 0 || enumIdx >= n_enum) return false;
        if (optimization->solution[solIdx]->objectives->other[ otherIdx]->enumeration[enumIdx] == NULL)
            optimization->solution[solIdx]->objectives->other[ otherIdx]->enumeration[enumIdx] = new OtherOptionOrResultEnumeration();
        for (int j=0; j<ni; j++) if (i[j] >= 0) return false;
        return optimization->solution[solIdx]->objectives->other[ otherIdx]->enumeration[enumIdx]->setOtherOptionOrResultEnumeration(value, description, i, ni);
    }
    case ENUM_PROBLEM_COMPONENT_constraints:
    {
        if (optimization->solution[solIdx]->constraints == NULL) return false;
        if (optimization->solution[solIdx]->constraints->other == NULL) return false;
        if (optimization->solution[solIdx]->constraints->other[ otherIdx] == NULL) return false;
        if (optimization->solution[solIdx]->constraints->other[ otherIdx]->enumeration == NULL) return false;
        int n_enum = optimization->solution[solIdx]->constraints->other[ otherIdx]->numberOfEnumerations;
        if (enumIdx < 0 || enumIdx >= n_enum) return false;
        if (optimization->solution[solIdx]->constraints->other[ otherIdx]->enumeration[enumIdx] == NULL)
            optimization->solution[solIdx]->constraints->other[ otherIdx]->enumeration[enumIdx] = new OtherOptionOrResultEnumeration();
        for (int j=0; j<ni; j++) if (i[j] < 0) return false;
        return optimization->solution[solIdx]->constraints->other[ otherIdx]->enumeration[enumIdx]->setOtherOptionOrResultEnumeration(value, description, i, ni);
    }

    default:
        throw ErrorClass("target object not implemented in setOtherOptionOrResultEnumeration");
    }
}//setOtherOptionOrResultEnumeration


bool OSResult::setNumberOfOtherObjectiveResults(int solIdx, int num)
{
    int nSols = this->getSolutionNumber();
    if (nSols <= 0) return false;
    if (optimization == NULL) return false;
    if (optimization->solution == NULL ||
            solIdx < 0 || solIdx >=  nSols) return false;
    if (optimization->solution[solIdx] == NULL)
    {
        optimization->solution[solIdx] = new OptimizationSolution();
    }
    if (optimization->solution[solIdx]->objectives == NULL)
    {
        optimization->solution[solIdx]->objectives = new ObjectiveSolution();
    }
    if (num < 0) return false;
    if (optimization->solution[solIdx]->objectives->other != NULL) return false;
    optimization->solution[solIdx]->objectives->numberOfOtherObjectiveResults = num;
    if (num > 0)
    {
        optimization->solution[solIdx]->objectives->other = new OtherObjectiveResult*[num];
        for(int i = 0; i < num; i++)
        {
            optimization->solution[solIdx]->objectives->other[ i]  = new OtherObjectiveResult();
        }
    }
    return true;
}//setNumberOfOtherObjectiveResults

bool OSResult::setNumberOfObjValues(int solIdx, int numberOfObj)
{
    if (optimization == NULL || optimization->solution == NULL)
    {
        //	throw ErrorClass("No optimization or solution object defined");
        return false;
    }
    int nSols = optimization->numberOfSolutions;
    if (solIdx < 0 || solIdx >=  nSols)
    {
        //	throw ErrorClass("Trying to use a solution that was not previously declared");
        return false;
    }
    if (optimization->solution[solIdx] == NULL)
        optimization->solution[solIdx] = new OptimizationSolution();
    if (optimization->solution[solIdx]->objectives == NULL)
        optimization->solution[solIdx]->objectives = new ObjectiveSolution();
    if (optimization->solution[solIdx]->objectives->values == NULL)
        optimization->solution[solIdx]->objectives->values = new ObjectiveValues();
    if (optimization->solution[solIdx]->objectives->values->numberOfObj > 0)
        return false;
    if (numberOfObj < 0) return false;
    if (optimization->solution[solIdx]->objectives->values->obj != NULL) return false;
    optimization->solution[solIdx]->objectives->values->numberOfObj = numberOfObj;
    if (numberOfObj > 0)
    {

        optimization->solution[solIdx]->objectives->values->obj = new ObjValue*[numberOfObj];
        for(int i = 0; i < numberOfObj; i++)
            optimization->solution[solIdx]->objectives->values->obj[i] = new ObjValue();
    }
    return true;
}//setNumberOfObjValues


bool OSResult::setNumberOfObjectiveValues(int solIdx, int numberOfObj)
{
    int nSols = this->getSolutionNumber();
    int nObj  = this->getObjectiveNumber();
    if (numberOfObj <= 0 || numberOfObj > nObj) return false;
    if (optimization == NULL) return false;
    if (nSols <= 0) return false;
    if (optimization->solution == NULL ||
            solIdx < 0 || solIdx >=  nSols) return false;
    if (optimization->solution[solIdx] == NULL)
    {
        optimization->solution[solIdx] = new OptimizationSolution();
    }

    if (optimization->solution[solIdx]->objectives == NULL)
    {
        optimization->solution[solIdx]->objectives = new ObjectiveSolution();
    }
    if (optimization->solution[solIdx]->objectives->values == NULL)
    {
        optimization->solution[solIdx]->objectives->values = new ObjectiveValues();
    }
    optimization->solution[solIdx]->objectives->values->numberOfObj = numberOfObj;
//	optimization->solution[solIdx]->objectives->values->obj = new ObjValue*[numberOfObj];

    return true;
}//setNumberOfObjectiveValues



bool OSResult::setObjectiveValuesSparse(int solIdx, std::vector<IndexValuePair*> x)
{
    int numberOfObj = x.size();
    int iNumberOfObjectives = numberOfObj;
    if(iNumberOfObjectives < 0) return false;
    if(iNumberOfObjectives == 0) return true;
    if(x.size() == 0) return false;
    int nSols = this->getSolutionNumber();
    if(optimization == NULL) return false;
    if(nSols <= 0) return false;
    if(optimization == NULL) return false;
    if(optimization->solution == NULL ||
            solIdx < 0 || solIdx >=  nSols) return false;
    if(optimization->solution[solIdx] == NULL)
    {
        optimization->solution[solIdx] = new OptimizationSolution();
    }
    if(optimization->solution[solIdx]->objectives == NULL)
    {
        optimization->solution[solIdx]->objectives = new ObjectiveSolution();
    }
    if(optimization->solution[solIdx]->objectives->values == NULL)
    {
        optimization->solution[solIdx]->objectives->values = new ObjectiveValues();
    }
    if(optimization->solution[solIdx]->objectives->values->obj == NULL)
    {
        optimization->solution[solIdx]->objectives->values->obj = new ObjValue*[iNumberOfObjectives];
    }
    optimization->solution[solIdx]->objectives->values->numberOfObj = iNumberOfObjectives;
    for(int i = 0; i < iNumberOfObjectives; i++)
    {
        optimization->solution[solIdx]->objectives->values->obj[i] = new ObjValue();
        optimization->solution[solIdx]->objectives->values->obj[i]->idx = x[i]->idx;
        optimization->solution[solIdx]->objectives->values->obj[i]->value = x[i]->value;
    }
    return true;
}//setObjectiveValuesSparse


bool OSResult::setObjectiveValuesDense(int solIdx, double *objectiveValues)
{
    int numberOfObj = this->getObjectiveNumber();
    int iNumberOfObjectives = numberOfObj;
    if (iNumberOfObjectives < 0) return false;
    if (iNumberOfObjectives == 0) return true;
    if (objectiveValues == NULL) return false;
    int nSols = this->getSolutionNumber();
    if (optimization == NULL) return false;
    if (nSols <= 0) return false;
    if (optimization == NULL) return false;
    if (optimization->solution == NULL ||
            solIdx < 0 || solIdx >=  nSols) return false;
    if (optimization->solution[solIdx] == NULL)
    {
        optimization->solution[solIdx] = new OptimizationSolution();
    }
    if (optimization->solution[solIdx]->objectives == NULL)
    {
        optimization->solution[solIdx]->objectives = new ObjectiveSolution();
    }
    if (optimization->solution[solIdx]->objectives->values == NULL)
    {
        optimization->solution[solIdx]->objectives->values = new ObjectiveValues();
    }
    if (optimization->solution[solIdx]->objectives->values->obj == NULL)
    {
        optimization->solution[solIdx]->objectives->values->obj = new ObjValue*[iNumberOfObjectives];
    }

    optimization->solution[solIdx]->objectives->values->numberOfObj = iNumberOfObjectives;
    for(int i = 0; i < iNumberOfObjectives; i++)
    {
        optimization->solution[solIdx]->objectives->values->obj[i] = new ObjValue();
        optimization->solution[solIdx]->objectives->values->obj[i]->idx = -(i+1);
        optimization->solution[solIdx]->objectives->values->obj[i]->value = objectiveValues[i];
    }

    return true;
}//setObjectiveValuesDense



bool OSResult::setObjValue(int solIdx, int number, int idx, std::string name, double val)
{
    if (optimization == NULL || optimization->solution == NULL)
    {
        //	throw ErrorClass("No optimization or solution object defined");
        return false;
    }
    int nSols = optimization->numberOfSolutions;
    if (solIdx < 0 || solIdx >=  nSols)
    {
        //	throw ErrorClass("Trying to use a solution that was not previously declared");
        return false;
    }
    if (optimization->solution[solIdx] == NULL)
    {
        //	throw ErrorClass("Solution object not previously defined");
        return false;
    }
    if (optimization->solution[solIdx]->objectives == NULL)
    {
        //	throw ErrorClass("objectives object not previously defined");
        return false;
    }
    if (optimization->solution[solIdx]->objectives->values == NULL)
    {
        //	throw ErrorClass("values object not previously defined");
        return false;
    }
    int nObj = 	optimization->solution[solIdx]->objectives->values->numberOfObj;
    if (number < 0 || number >= nObj)
    {
        //	throw ErrorClass("Trying to set value outside of obj array boundaries");
        return false;
    }
    if (idx >= 0)
    {
        //	throw ErrorClass("Objective index must be negative.");
        return false;
    }
    optimization->solution[solIdx]->objectives->values->obj[number]->idx   = idx;
    optimization->solution[solIdx]->objectives->values->obj[number]->name  = name;
    optimization->solution[solIdx]->objectives->values->obj[number]->value = val;
    return true;
}//setObjValue

bool OSResult::setOtherObjectiveResultNumberOfObj(int solIdx, int otherIdx, int numberOfObj)
{
    int iNumberOfObjectives = numberOfObj;
    if (iNumberOfObjectives <= -1) return false;
    int nSols = this->getSolutionNumber();
    if (optimization == NULL) return false;
    if (nSols <= 0) return false;
    if (optimization == NULL) return false;
    if (optimization->solution == NULL ||
            solIdx < 0 || solIdx >=  nSols) return false;
    if (optimization->solution[solIdx] == NULL) return false;
    if (optimization->solution[solIdx]->objectives == NULL)return false;
    if (optimization->solution[solIdx]->objectives->other == NULL) return false;
    if (optimization->solution[solIdx]->objectives->other[ otherIdx] == NULL) return false;
    if (optimization->solution[solIdx]->objectives->other[ otherIdx]->obj == NULL)
        optimization->solution[solIdx]->objectives->other[ otherIdx]->obj = new OtherObjResult*[numberOfObj];
    for(int i = 0; i < numberOfObj; i++)
    {
        optimization->solution[solIdx]->objectives->other[ otherIdx]->obj[i] = new OtherObjResult();
    }
    optimization->solution[solIdx]->objectives->other[ otherIdx]->numberOfObj = numberOfObj;
    return true;
}//setOtherObjectiveResultNumberOfObj


bool OSResult::setOtherObjectiveResultNumberOfEnumerations(int solIdx, int otherIdx, int numberOfEnumerations)
{
    int iNumberOfEnumerations = numberOfEnumerations;
    if (iNumberOfEnumerations <= -1) return false;
    int nSols = this->getSolutionNumber();
    if (nSols <= 0) return false;
    if (optimization == NULL) return false;
    if (optimization->solution == NULL ||
            solIdx < 0 || solIdx >=  nSols) return false;
    if (optimization->solution[solIdx] == NULL) return false;
    if (optimization->solution[solIdx]->objectives == NULL) return false;
    if (optimization->solution[solIdx]->objectives->other == NULL) return false;
    if (optimization->solution[solIdx]->objectives->other[ otherIdx] == NULL) return false;
    if (optimization->solution[solIdx]->objectives->other[ otherIdx]->enumeration == NULL)
        optimization->solution[solIdx]->objectives->other[ otherIdx]->enumeration = new OtherOptionOrResultEnumeration*[numberOfEnumerations];
    for(int i = 0; i < numberOfEnumerations; i++)
        optimization->solution[solIdx]->objectives->other[ otherIdx]->enumeration[i] = new OtherOptionOrResultEnumeration();
    optimization->solution[solIdx]->objectives->other[ otherIdx]->numberOfEnumerations = numberOfEnumerations;
    return true;
}//setOtherObjectiveResultNumberOfEnumerations

bool OSResult::setOtherObjectiveResultName(int solIdx, int otherIdx, std::string name)
{
    int numberOfObj = this->getObjectiveNumber();
    int iNumberOfObjectives = numberOfObj;
    if (iNumberOfObjectives <= -1) return false;
    int nSols = this->getSolutionNumber();
    if (optimization == NULL) return false;
    if (nSols <= 0) return false;
    if (optimization == NULL) return false;
    if (optimization->solution == NULL ||
            solIdx < 0 || solIdx >=  nSols) return false;
    if (optimization->solution[solIdx] == NULL) return false;
    if (optimization->solution[solIdx]->objectives == NULL)return false;
    if (optimization->solution[solIdx]->objectives->other == NULL) return false;
    if (optimization->solution[solIdx]->objectives->other[ otherIdx] == NULL) return false;
    optimization->solution[solIdx]->objectives->other[ otherIdx]->name = name;
    return true;
}//setOtherObjectiveResultName

bool OSResult::setOtherObjectiveResultType(int solIdx, int otherIdx, std::string type)
{
    int numberOfObj = this->getObjectiveNumber();
    int iNumberOfObjectives = numberOfObj;
    if (iNumberOfObjectives <= -1) return false;
    int nSols = this->getSolutionNumber();
    if (optimization == NULL) return false;
    if (nSols <= 0) return false;
    if (optimization == NULL) return false;
    if (optimization->solution == NULL ||
            solIdx < 0 || solIdx >=  nSols) return false;
    if (optimization->solution[solIdx] == NULL) return false;
    if (optimization->solution[solIdx]->objectives == NULL)return false;
    if (optimization->solution[solIdx]->objectives->other == NULL) return false;
    if (optimization->solution[solIdx]->objectives->other[ otherIdx] == NULL) return false;
    optimization->solution[solIdx]->objectives->other[ otherIdx]->type = type;
    return true;
}//setOtherObjectiveResultType

bool OSResult::setOtherObjectiveResultObjType(int solIdx, int otherIdx, std::string objType)
{
    int numberOfObj = this->getObjectiveNumber();
    int iNumberOfObjectives = numberOfObj;
    if (iNumberOfObjectives <= -1) return false;
    int nSols = this->getSolutionNumber();
    if (optimization == NULL) return false;
    if (nSols <= 0) return false;
    if (optimization == NULL) return false;
    if (optimization->solution == NULL ||
            solIdx < 0 || solIdx >=  nSols) return false;
    if (optimization->solution[solIdx] == NULL) return false;
    if (optimization->solution[solIdx]->objectives == NULL)return false;
    if (optimization->solution[solIdx]->objectives->other == NULL) return false;
    if (optimization->solution[solIdx]->objectives->other[ otherIdx] == NULL) return false;
    optimization->solution[solIdx]->objectives->other[ otherIdx]->objType = objType;
    return true;
}//setOtherObjectiveResultObjType

bool OSResult::setOtherObjectiveResultEnumType(int solIdx, int otherIdx, std::string enumType)
{
    int numberOfObj = this->getObjectiveNumber();
    int iNumberOfObjectives = numberOfObj;
    if (iNumberOfObjectives <= -1) return false;
    int nSols = this->getSolutionNumber();
    if (optimization == NULL) return false;
    if (nSols <= 0) return false;
    if (optimization == NULL) return false;
    if (optimization->solution == NULL ||
            solIdx < 0 || solIdx >=  nSols) return false;
    if (optimization->solution[solIdx] == NULL) return false;
    if (optimization->solution[solIdx]->objectives == NULL)return false;
    if (optimization->solution[solIdx]->objectives->other == NULL) return false;
    if (optimization->solution[solIdx]->objectives->other[ otherIdx] == NULL) return false;
    optimization->solution[solIdx]->objectives->other[ otherIdx]->enumType = enumType;
    return true;
}//setOtherObjectiveResultEnumType

bool OSResult::setOtherObjectiveResultValue(int solIdx, int otherIdx, std::string value)
{
    int numberOfObj = this->getObjectiveNumber();
    int iNumberOfObjectives = numberOfObj;
    if (iNumberOfObjectives <= -1) return false;
    int nSols = this->getSolutionNumber();
    if (optimization == NULL) return false;
    if (nSols <= 0) return false;
    if (optimization == NULL) return false;
    if (optimization->solution == NULL ||
            solIdx < 0 || solIdx >=  nSols) return false;
    if (optimization->solution[solIdx] == NULL) return false;
    if (optimization->solution[solIdx]->objectives == NULL)return false;
    if (optimization->solution[solIdx]->objectives->other == NULL) return false;
    if (optimization->solution[solIdx]->objectives->other[ otherIdx] == NULL) return false;
    optimization->solution[solIdx]->objectives->other[ otherIdx]->value = value;
    return true;
}//setOtherObjectiveResultValue

bool OSResult::setOtherObjectiveResultDescription(int solIdx, int otherIdx, std::string description)
{
    int numberOfObj = this->getObjectiveNumber();
    int iNumberOfObjectives = numberOfObj;
    if (iNumberOfObjectives <= -1) return false;
    int nSols = this->getSolutionNumber();
    if (optimization == NULL) return false;
    if (nSols <= 0) return false;
    if (optimization == NULL) return false;
    if (optimization->solution == NULL ||
            solIdx < 0 || solIdx >=  nSols) return false;
    if (optimization->solution[solIdx] == NULL) return false;
    if (optimization->solution[solIdx]->objectives == NULL)return false;
    if (optimization->solution[solIdx]->objectives->other == NULL) return false;
    if (optimization->solution[solIdx]->objectives->other[ otherIdx] == NULL) return false;
    optimization->solution[solIdx]->objectives->other[ otherIdx]->description = description;
    return true;
}//setOtherObjectiveResultDescription

bool OSResult::setOtherObjectiveResultSolver(int solIdx, int otherIdx, std::string solver)
{
    int numberOfObj = this->getObjectiveNumber();
    int iNumberOfObjectives = numberOfObj;
    if (iNumberOfObjectives <= -1) return false;
    int nSols = this->getSolutionNumber();
    if (optimization == NULL) return false;
    if (nSols <= 0) return false;
    if (optimization == NULL) return false;
    if (optimization->solution == NULL ||
            solIdx < 0 || solIdx >=  nSols) return false;
    if (optimization->solution[solIdx] == NULL) return false;
    if (optimization->solution[solIdx]->objectives == NULL)return false;
    if (optimization->solution[solIdx]->objectives->other == NULL) return false;
    if (optimization->solution[solIdx]->objectives->other[ otherIdx] == NULL) return false;
    optimization->solution[solIdx]->objectives->other[ otherIdx]->solver = solver;
    return true;
}//setOtherObjectiveResultSolver

bool OSResult::setOtherObjectiveResultCategory(int solIdx, int otherIdx, std::string category)
{
    int numberOfObj = this->getObjectiveNumber();
    int iNumberOfObjectives = numberOfObj;
    if (iNumberOfObjectives <= -1) return false;
    int nSols = this->getSolutionNumber();
    if (optimization == NULL) return false;
    if (nSols <= 0) return false;
    if (optimization == NULL) return false;
    if (optimization->solution == NULL ||
            solIdx < 0 || solIdx >=  nSols) return false;
    if (optimization->solution[solIdx] == NULL) return false;
    if (optimization->solution[solIdx]->objectives == NULL)return false;
    if (optimization->solution[solIdx]->objectives->other == NULL) return false;
    if (optimization->solution[solIdx]->objectives->other[ otherIdx] == NULL) return false;
    optimization->solution[solIdx]->objectives->other[ otherIdx]->category = category;
    return true;
}//setOtherObjectiveResultCategory

bool OSResult::setOtherObjectiveResultObjIdx(int solIdx, int otherIdx, int objIdx, int idx)
{
    int nSols = this->getSolutionNumber();
    if (nSols <= 0) return false;
    if (optimization == NULL) return false;
    if (optimization->solution == NULL ||
            solIdx < 0 || solIdx >=  nSols) return false;
    if (optimization->solution[solIdx] == NULL) return false;
    if (optimization->solution[solIdx]->objectives == NULL) return false;
    if (optimization->solution[solIdx]->objectives->other[otherIdx] == NULL) return false;
    if (optimization->solution[solIdx]->objectives->other[otherIdx]->obj == NULL) return false;
    if (idx >= 0) return false;
    optimization->solution[solIdx]->objectives->other[otherIdx]->obj[objIdx]->idx = idx;
    return true;
}//setOtherObjectiveResultObjIdx

bool OSResult::setOtherObjectiveResultObjName(int solIdx, int otherIdx, int objIdx, std::string name)
{
    int nSols = this->getSolutionNumber();
    if (nSols <= 0) return false;
    if (optimization == NULL) return false;
    if (optimization->solution == NULL ||
            solIdx < 0 || solIdx >=  nSols) return false;
    if (optimization->solution[solIdx] == NULL) return false;
    if (optimization->solution[solIdx]->objectives == NULL) return false;
    if (optimization->solution[solIdx]->objectives->other[otherIdx] == NULL) return false;
    if (optimization->solution[solIdx]->objectives->other[otherIdx]->obj == NULL) return false;
    optimization->solution[solIdx]->objectives->other[otherIdx]->obj[objIdx]->name = name;
    return true;
}//setOtherObjectiveResultObjName

bool OSResult::setOtherObjectiveResultObj(int solIdx, int otherIdx, int objIdx, std::string value)
{
    int nSols = this->getSolutionNumber();
    if (nSols <= 0) return false;
    if (optimization == NULL) return false;
    if (optimization->solution == NULL ||
            solIdx < 0 || solIdx >=  nSols) return false;
    if (optimization->solution[solIdx] == NULL) return false;
    if (optimization->solution[solIdx]->objectives == NULL) return false;
    if (optimization->solution[solIdx]->objectives->other[otherIdx] == NULL) return false;
    if (optimization->solution[solIdx]->objectives->other[otherIdx]->obj == NULL) return false;
    optimization->solution[solIdx]->objectives->other[otherIdx]->obj[objIdx]->value = value;
    return true;
}//setOtherObjectiveResultObj

bool OSResult::setNumberOfOtherConstraintResults(int solIdx, int num)
{
    int nSols = this->getSolutionNumber();
    if (nSols <= 0) return false;
    if (optimization == NULL) return false;
    if (optimization->solution == NULL ||
            solIdx < 0 || solIdx >=  nSols) return false;
    if (optimization->solution[solIdx] == NULL)
    {
        optimization->solution[solIdx] = new OptimizationSolution();
    }
    if (optimization->solution[solIdx]->constraints == NULL)
    {
        optimization->solution[solIdx]->constraints = new ConstraintSolution();
    }
    if (num < 0) return false;
    if (optimization->solution[solIdx]->constraints->other != NULL) return false;
    optimization->solution[solIdx]->constraints->numberOfOtherConstraintResults =  num;
    if (num > 0)
    {
        optimization->solution[solIdx]->constraints->other = new OtherConstraintResult*[num];
        for(int i = 0; i < num; i++)
        {
            optimization->solution[solIdx]->constraints->other[ i]  = new OtherConstraintResult();
        }
    }
    return true;
}//setNumberOfOtherConstraintResults

bool OSResult::setNumberOfDualValues(int solIdx, int numberOfCon)
{
    if (optimization == NULL || optimization->solution == NULL)
    {
        //	throw ErrorClass("No optimization or solution object defined");
        return false;
    }
    int nSols = optimization->numberOfSolutions;
    if (solIdx < 0 || solIdx >=  nSols)
    {
        //	throw ErrorClass("Trying to use a solution that was not previously declared");
        return false;
    }
    if (optimization->solution[solIdx] == NULL)
        optimization->solution[solIdx] = new OptimizationSolution();
    if (optimization->solution[solIdx]->constraints == NULL)
        optimization->solution[solIdx]->constraints = new ConstraintSolution();
    if (optimization->solution[solIdx]->constraints->dualValues == NULL)
        optimization->solution[solIdx]->constraints->dualValues = new DualVariableValues();
    if (optimization->solution[solIdx]->constraints->dualValues->numberOfCon > 0)
        return false;
    if (numberOfCon < 0) return false;
    if (optimization->solution[solIdx]->constraints->dualValues->con != NULL) return false;
    optimization->solution[solIdx]->constraints->dualValues->numberOfCon = numberOfCon;
    if (numberOfCon > 0)
    {
        optimization->solution[solIdx]->constraints->dualValues->con = new DualVarValue*[numberOfCon];
        for(int i = 0; i < numberOfCon; i++)
            optimization->solution[solIdx]->constraints->dualValues->con[i] = new DualVarValue();
    }
    return true;
}//setNumberOfDualValues


bool OSResult::setNumberOfDualVariableValues(int solIdx, int numberOfCon)
{
    int nSols = this->getSolutionNumber();
    int nCon  = this->getConstraintNumber();
    if (numberOfCon <= 0 || numberOfCon > nCon) return false;
    if (optimization == NULL) return false;
    if (nSols <= 0) return false;
    if (optimization->solution == NULL ||
            solIdx < 0 || solIdx >=  nSols) return false;
    if (optimization->solution[solIdx] == NULL)
    {
        optimization->solution[solIdx] = new OptimizationSolution();
    }
    if (optimization->solution[solIdx]->constraints == NULL)
    {
        optimization->solution[solIdx]->constraints = new ConstraintSolution();
    }
    if (optimization->solution[solIdx]->constraints->dualValues == NULL)
    {
        optimization->solution[solIdx]->constraints->dualValues = new DualVariableValues();
    }
    optimization->solution[solIdx]->constraints->dualValues->numberOfCon = numberOfCon;
//	optimization->solution[solIdx]->constraints->dualValues->con = new DualVarValue*[numberOfCon];

    return true;
}//setNumberOfDualVariableValues



bool OSResult::setDualVariableValuesSparse(int solIdx, std::vector<IndexValuePair*> x)
{
    int numberOfCon = x.size();
    int iNumberOfConstraints = numberOfCon;
    if(iNumberOfConstraints < 0) return false;
    if(iNumberOfConstraints == 0) return true;
    int nSols = this->getSolutionNumber();
    if(optimization == NULL) return false;
    if(nSols <= 0) return false;
    if(optimization == NULL) return false;
    if(optimization->solution == NULL ||
            solIdx < 0 || solIdx >=  nSols) return false;
    if(optimization->solution[solIdx] == NULL)
    {
        optimization->solution[solIdx] = new OptimizationSolution();
    }
    if(optimization->solution[solIdx]->constraints == NULL)
    {
        optimization->solution[solIdx]->constraints = new ConstraintSolution();
    }
    if(optimization->solution[solIdx]->constraints->dualValues == NULL)
    {
        optimization->solution[solIdx]->constraints->dualValues = new DualVariableValues();
    }
    if(optimization->solution[solIdx]->constraints->dualValues->con == NULL)
    {
        optimization->solution[solIdx]->constraints->dualValues->con = new DualVarValue*[numberOfCon];
    }
    if(x.size() == 0)
    {
        optimization->solution[solIdx]->constraints->dualValues = NULL;
        return true;
    }
    optimization->solution[solIdx]->constraints->dualValues->numberOfCon = numberOfCon;
    for(int i = 0; i < iNumberOfConstraints; i++)
    {
        optimization->solution[solIdx]->constraints->dualValues->con[i] = new DualVarValue();
        optimization->solution[solIdx]->constraints->dualValues->con[i]->idx = x[i]->idx;
        optimization->solution[solIdx]->constraints->dualValues->con[i]->value = x[i]->value;
    }
    return true;
}//setDualVariableValuesSparse

bool OSResult::setDualVariableValuesDense(int solIdx, double *y)
{
    int numberOfCon = this->getConstraintNumber();
    int iNumberOfConstraints = numberOfCon;
    if (iNumberOfConstraints < 0) return false;
    if (iNumberOfConstraints == 0) return true;
    int nSols = this->getSolutionNumber();
    if (optimization == NULL) return false;
    if (nSols <= 0) return false;
    if (optimization == NULL) return false;
    if (optimization->solution == NULL ||
            solIdx < 0 || solIdx >=  nSols) return false;
    if (optimization->solution[solIdx] == NULL)
    {
        optimization->solution[solIdx] = new OptimizationSolution();
    }
    if (optimization->solution[solIdx]->constraints == NULL)
    {
        optimization->solution[solIdx]->constraints = new ConstraintSolution();
    }
    if (optimization->solution[solIdx]->constraints->dualValues == NULL)
    {
        optimization->solution[solIdx]->constraints->dualValues = new DualVariableValues();
    }
    if (optimization->solution[solIdx]->constraints->dualValues->con == NULL)
    {
        optimization->solution[solIdx]->constraints->dualValues->con = new DualVarValue*[numberOfCon];
    }
    if (y == NULL)
    {
        optimization->solution[solIdx]->constraints->dualValues = NULL;
        return true;
    }
    optimization->solution[solIdx]->constraints->dualValues->numberOfCon = numberOfCon;
    for(int i = 0; i < iNumberOfConstraints; i++)
    {
        optimization->solution[solIdx]->constraints->dualValues->con[i] = new DualVarValue();
        optimization->solution[solIdx]->constraints->dualValues->con[i]->idx = i;
        optimization->solution[solIdx]->constraints->dualValues->con[i]->value = y[i];

    }
    return true;
}//setDualVariableValuesDense

bool OSResult::setConstraintValuesDense(int solIdx, double *dualVarValues)
{
    int numberOfCon = this->getConstraintNumber();
    int iNumberOfConstraints = numberOfCon;
    if (iNumberOfConstraints <= 0) return false;
    int nSols = this->getSolutionNumber();
    if (optimization == NULL) return false;
    if (nSols <= 0) return false;
    if (optimization == NULL) return false;
    if (optimization->solution == NULL ||
            solIdx < 0 || solIdx >=  nSols) return false;
    if (optimization->solution[solIdx] == NULL)
    {
        optimization->solution[solIdx] = new OptimizationSolution();
    }
    if (optimization->solution[solIdx]->constraints == NULL)
    {
        optimization->solution[solIdx]->constraints = new ConstraintSolution();
    }
    if (optimization->solution[solIdx]->constraints->dualValues == NULL)
    {
        optimization->solution[solIdx]->constraints->dualValues = new DualVariableValues();
    }
    if (optimization->solution[solIdx]->constraints->dualValues->con == NULL)
    {
        optimization->solution[solIdx]->constraints->dualValues->con = new DualVarValue*[numberOfCon];
    }
    if (dualVarValues == NULL)
    {
        optimization->solution[solIdx]->constraints->dualValues = NULL;
        return true;
    }
    //optimization->solution[solIdx]->constraints->dualValues->con = new ConValue*[ iNumberOfConstraints];
    optimization->solution[solIdx]->constraints->dualValues->numberOfCon = numberOfCon;
    for(int i = 0; i < iNumberOfConstraints; i++)
    {
        optimization->solution[solIdx]->constraints->dualValues->con[i] = new DualVarValue();
        //optimization->solution[solIdx]->constraints->dualValues->con[i] = new ConValue();
        optimization->solution[solIdx]->constraints->dualValues->con[i]->idx = i;
        optimization->solution[solIdx]->constraints->dualValues->con[i]->value = dualVarValues[i];
    }
    return true;
}//setConstraintValuesDense

bool OSResult::setDualValue(int solIdx, int number, int idx, std::string name, double val)
{
    if (optimization == NULL || optimization->solution == NULL)
    {
        //	throw ErrorClass("No optimization or solution object defined");
        return false;
    }
    int nSols = optimization->numberOfSolutions;
    if (solIdx < 0 || solIdx >=  nSols)
    {
        //	throw ErrorClass("Trying to use a solution that was not previously declared");
        return false;
    }
    if (optimization->solution[solIdx] == NULL)
    {
        //	throw ErrorClass("Solution object not previously defined");
        return false;
    }
    if (optimization->solution[solIdx]->constraints == NULL)
    {
        //	throw ErrorClass("constraints object not previously defined");
        return false;
    }
    if (optimization->solution[solIdx]->constraints->dualValues == NULL)
    {
        //	throw ErrorClass("values object not previously defined");
        return false;
    }
    int nCon = 	optimization->solution[solIdx]->constraints->dualValues->numberOfCon;
    if (number < 0 || number >= nCon)
    {
        //	throw ErrorClass("Trying to set value outside of con array boundaries");
        return false;
    }
    if (idx < 0)
    {
        //	throw ErrorClass("Constraint index cannot be negative.");
        return false;
    }
    optimization->solution[solIdx]->constraints->dualValues->con[number]->idx   = idx;
    optimization->solution[solIdx]->constraints->dualValues->con[number]->name  = name;
    optimization->solution[solIdx]->constraints->dualValues->con[number]->value = val;
    return true;
}//setDualValue

bool OSResult::setOtherConstraintResultNumberOfCon(int solIdx, int otherIdx, int numberOfCon)
{
    int iNumberOfConstraints = numberOfCon;
    if (iNumberOfConstraints <= -1) return false;
    int nSols = this->getSolutionNumber();
    if (optimization == NULL) return false;
    if (nSols <= 0) return false;
    if (optimization == NULL) return false;
    if (optimization->solution == NULL ||
            solIdx < 0 || solIdx >=  nSols) return false;
    if (optimization->solution[solIdx] == NULL) return false;
    if (optimization->solution[solIdx]->constraints == NULL)return false;
    if (optimization->solution[solIdx]->constraints->other == NULL) return false;
    if (optimization->solution[solIdx]->constraints->other[ otherIdx] == NULL) return false;
    if (optimization->solution[solIdx]->constraints->other[ otherIdx]->con == NULL)
        optimization->solution[solIdx]->constraints->other[ otherIdx]->con = new OtherConResult*[numberOfCon];
    for(int i = 0; i < numberOfCon; i++)
        optimization->solution[solIdx]->constraints->other[ otherIdx]->con[i] = new OtherConResult();
    optimization->solution[solIdx]->constraints->other[ otherIdx]->numberOfCon = numberOfCon;
    return true;
}//setOtherConstraintResultNumberOfCon


bool OSResult::setOtherConstraintResultNumberOfEnumerations(int solIdx, int otherIdx, int numberOfEnumerations)
{
    int iNumberOfEnumerations = numberOfEnumerations;
    if (iNumberOfEnumerations <= -1) return false;
    int nSols = this->getSolutionNumber();
    if (nSols <= 0) return false;
    if (optimization == NULL) return false;
    if (optimization->solution == NULL ||
            solIdx < 0 || solIdx >=  nSols) return false;
    if (optimization->solution[solIdx] == NULL) return false;
    if (optimization->solution[solIdx]->constraints == NULL) return false;
    if (optimization->solution[solIdx]->constraints->other == NULL) return false;
    if (optimization->solution[solIdx]->constraints->other[ otherIdx] == NULL) return false;
    if (optimization->solution[solIdx]->constraints->other[ otherIdx]->enumeration == NULL)
        optimization->solution[solIdx]->constraints->other[ otherIdx]->enumeration = new OtherOptionOrResultEnumeration*[numberOfEnumerations];
    for(int i = 0; i < numberOfEnumerations; i++)
        optimization->solution[solIdx]->constraints->other[ otherIdx]->enumeration[i] = new OtherOptionOrResultEnumeration();
    optimization->solution[solIdx]->constraints->other[ otherIdx]->numberOfEnumerations = numberOfEnumerations;
    return true;
}//setOtherConstraintResultNumberOfEnumerations

bool OSResult::setOtherConstraintResultName(int solIdx, int otherIdx, std::string name)
{
    int numberOfCon = this->getConstraintNumber();
    int iNumberOfConstraints = numberOfCon;
    if (iNumberOfConstraints <= -1) return false;
    int nSols = this->getSolutionNumber();
    if (optimization == NULL) return false;
    if (nSols <= 0) return false;
    if (optimization == NULL) return false;
    if (optimization->solution == NULL ||
            solIdx < 0 || solIdx >=  nSols) return false;
    if (optimization->solution[solIdx] == NULL) return false;
    if (optimization->solution[solIdx]->constraints == NULL)return false;
    if (optimization->solution[solIdx]->constraints->other == NULL) return false;
    if (optimization->solution[solIdx]->constraints->other[ otherIdx] == NULL) return false;
    optimization->solution[solIdx]->constraints->other[ otherIdx]->name = name;
    return true;
}//setOtherConstraintResultName

bool OSResult::setOtherConstraintResultType(int solIdx, int otherIdx, std::string type)
{
    int numberOfCon = this->getConstraintNumber();
    int iNumberOfConstraints = numberOfCon;
    if (iNumberOfConstraints <= -1) return false;
    int nSols = this->getSolutionNumber();
    if (optimization == NULL) return false;
    if (nSols <= 0) return false;
    if (optimization == NULL) return false;
    if (optimization->solution == NULL ||
            solIdx < 0 || solIdx >=  nSols) return false;
    if (optimization->solution[solIdx] == NULL) return false;
    if (optimization->solution[solIdx]->constraints == NULL)return false;
    if (optimization->solution[solIdx]->constraints->other == NULL) return false;
    if (optimization->solution[solIdx]->constraints->other[ otherIdx] == NULL) return false;
    optimization->solution[solIdx]->constraints->other[ otherIdx]->type = type;
    return true;
}//setOtherConstraintResultType

bool OSResult::setOtherConstraintResultConType(int solIdx, int otherIdx, std::string conType)
{
    int numberOfCon = this->getConstraintNumber();
    int iNumberOfConstraints = numberOfCon;
    if (iNumberOfConstraints <= -1) return false;
    int nSols = this->getSolutionNumber();
    if (optimization == NULL) return false;
    if (nSols <= 0) return false;
    if (optimization == NULL) return false;
    if (optimization->solution == NULL ||
            solIdx < 0 || solIdx >=  nSols) return false;
    if (optimization->solution[solIdx] == NULL) return false;
    if (optimization->solution[solIdx]->constraints == NULL)return false;
    if (optimization->solution[solIdx]->constraints->other == NULL) return false;
    if (optimization->solution[solIdx]->constraints->other[ otherIdx] == NULL) return false;
    optimization->solution[solIdx]->constraints->other[ otherIdx]->conType = conType;
    return true;
}//setOtherConstraintResultConType

bool OSResult::setOtherConstraintResultEnumType(int solIdx, int otherIdx, std::string enumType)
{
    int numberOfCon = this->getConstraintNumber();
    int iNumberOfConstraints = numberOfCon;
    if (iNumberOfConstraints <= -1) return false;
    int nSols = this->getSolutionNumber();
    if (optimization == NULL) return false;
    if (nSols <= 0) return false;
    if (optimization == NULL) return false;
    if (optimization->solution == NULL ||
            solIdx < 0 || solIdx >=  nSols) return false;
    if (optimization->solution[solIdx] == NULL) return false;
    if (optimization->solution[solIdx]->constraints == NULL)return false;
    if (optimization->solution[solIdx]->constraints->other == NULL) return false;
    if (optimization->solution[solIdx]->constraints->other[ otherIdx] == NULL) return false;
    optimization->solution[solIdx]->constraints->other[ otherIdx]->enumType = enumType;
    return true;
}//setOtherConstraintResultEnumType

bool OSResult::setOtherConstraintResultValue(int solIdx, int otherIdx, std::string value)
{
    int numberOfCon = this->getConstraintNumber();
    int iNumberOfConstraints = numberOfCon;
    if (iNumberOfConstraints <= -1) return false;
    int nSols = this->getSolutionNumber();
    if (optimization == NULL) return false;
    if (nSols <= 0) return false;
    if (optimization == NULL) return false;
    if (optimization->solution == NULL ||
            solIdx < 0 || solIdx >=  nSols) return false;
    if (optimization->solution[solIdx] == NULL) return false;
    if (optimization->solution[solIdx]->constraints == NULL)return false;
    if (optimization->solution[solIdx]->constraints->other == NULL) return false;
    if (optimization->solution[solIdx]->constraints->other[ otherIdx] == NULL) return false;
    optimization->solution[solIdx]->constraints->other[ otherIdx]->value = value;
    return true;
}//setOtherConstraintResultValue

bool OSResult::setOtherConstraintResultDescription(int solIdx, int otherIdx, std::string description)
{
    int numberOfCon = this->getConstraintNumber();
    int iNumberOfConstraints = numberOfCon;
    if (iNumberOfConstraints <= -1) return false;
    int nSols = this->getSolutionNumber();
    if (optimization == NULL) return false;
    if (nSols <= 0) return false;
    if (optimization == NULL) return false;
    if (optimization->solution == NULL ||
            solIdx < 0 || solIdx >=  nSols) return false;
    if (optimization->solution[solIdx] == NULL) return false;
    if (optimization->solution[solIdx]->constraints == NULL)return false;
    if (optimization->solution[solIdx]->constraints->other == NULL) return false;
    if (optimization->solution[solIdx]->constraints->other[ otherIdx] == NULL) return false;
    optimization->solution[solIdx]->constraints->other[ otherIdx]->description = description;
    return true;
}//setOtherConstraintResultDescription

bool OSResult::setOtherConstraintResultSolver(int solIdx, int otherIdx, std::string solver)
{
    int numberOfCon = this->getConstraintNumber();
    int iNumberOfConstraints = numberOfCon;
    if (iNumberOfConstraints <= -1) return false;
    int nSols = this->getSolutionNumber();
    if (optimization == NULL) return false;
    if (nSols <= 0) return false;
    if (optimization == NULL) return false;
    if (optimization->solution == NULL ||
            solIdx < 0 || solIdx >=  nSols) return false;
    if (optimization->solution[solIdx] == NULL) return false;
    if (optimization->solution[solIdx]->constraints == NULL)return false;
    if (optimization->solution[solIdx]->constraints->other == NULL) return false;
    if (optimization->solution[solIdx]->constraints->other[ otherIdx] == NULL) return false;
    optimization->solution[solIdx]->constraints->other[ otherIdx]->solver = solver;
    return true;
}//setOtherConstraintResultSolver

bool OSResult::setOtherConstraintResultCategory(int solIdx, int otherIdx, std::string category)
{
    int numberOfCon = this->getConstraintNumber();
    int iNumberOfConstraints = numberOfCon;
    if (iNumberOfConstraints <= -1) return false;
    int nSols = this->getSolutionNumber();
    if (optimization == NULL) return false;
    if (nSols <= 0) return false;
    if (optimization == NULL) return false;
    if (optimization->solution == NULL ||
            solIdx < 0 || solIdx >=  nSols) return false;
    if (optimization->solution[solIdx] == NULL) return false;
    if (optimization->solution[solIdx]->constraints == NULL)return false;
    if (optimization->solution[solIdx]->constraints->other == NULL) return false;
    if (optimization->solution[solIdx]->constraints->other[ otherIdx] == NULL) return false;
    optimization->solution[solIdx]->constraints->other[ otherIdx]->category = category;
    return true;
}//setOtherConstraintResultCategory

bool OSResult::setOtherConstraintResultConIdx(int solIdx, int otherIdx, int conIdx, int idx)
{
    int nSols = this->getSolutionNumber();
    if (nSols <= 0) return false;
    if (optimization == NULL) return false;
    if (optimization->solution == NULL ||
            solIdx < 0 || solIdx >=  nSols) return false;
    if (optimization->solution[solIdx] == NULL) return false;
    if (optimization->solution[solIdx]->constraints == NULL) return false;
    if (optimization->solution[solIdx]->constraints->other[otherIdx] == NULL) return false;
    if (optimization->solution[solIdx]->constraints->other[otherIdx]->con == NULL) return false;
    if (idx < 0) return false;
    optimization->solution[solIdx]->constraints->other[otherIdx]->con[conIdx]->idx = idx;
    return true;
}//setOtherConstraintResultConIdx

bool OSResult::setOtherConstraintResultConName(int solIdx, int otherIdx, int conIdx, std::string name)
{
    int nSols = this->getSolutionNumber();
    if (nSols <= 0) return false;
    if (optimization == NULL) return false;
    if (optimization->solution == NULL ||
            solIdx < 0 || solIdx >=  nSols) return false;
    if (optimization->solution[solIdx] == NULL) return false;
    if (optimization->solution[solIdx]->constraints == NULL) return false;
    if (optimization->solution[solIdx]->constraints->other[otherIdx] == NULL) return false;
    if (optimization->solution[solIdx]->constraints->other[otherIdx]->con == NULL) return false;
    optimization->solution[solIdx]->constraints->other[otherIdx]->con[conIdx]->name = name;
    return true;
}//setOtherConstraintResultConIdx

bool OSResult::setOtherConstraintResultCon(int solIdx, int otherIdx, int conIdx, std::string value)
{
    int nSols = this->getSolutionNumber();
    if (nSols <= 0) return false;
    if (optimization == NULL) return false;
    if (optimization->solution == NULL ||
            solIdx < 0 || solIdx >=  nSols) return false;
    if (optimization->solution[solIdx] == NULL) return false;
    if (optimization->solution[solIdx]->constraints == NULL) return false;
    if (optimization->solution[solIdx]->constraints->other[otherIdx] == NULL) return false;
    if (optimization->solution[solIdx]->constraints->other[otherIdx]->con == NULL) return false;
    optimization->solution[solIdx]->constraints->other[otherIdx]->con[conIdx]->value = value;
    return true;
}//setOtherConstraintResultCon

bool OSResult::setMatrixVariableSolution(int solIdx, int numberOfMatrixVar_, 
                                         int numberOfOtherMatrixVariableResults_)
{
    int nSols = this->getSolutionNumber();
    if (nSols <= 0) return false;
    if (optimization == NULL) return false;
    if (optimization->solution == NULL ||
            solIdx < 0 || solIdx >=  nSols) return false;
    if (optimization->solution[solIdx] == NULL) return false;
    if (optimization->solution[solIdx]->matrixProgramming == NULL) 
        optimization->solution[solIdx]->matrixProgramming = new MatrixProgrammingSolution();
    if (optimization->solution[solIdx]->matrixProgramming->matrixVariables == NULL) 
        optimization->solution[solIdx]->matrixProgramming->matrixVariables
            = new MatrixVariableSolution(); 
    if (optimization->solution[solIdx]->matrixProgramming->matrixVariables->values == NULL) 
        optimization->solution[solIdx]->matrixProgramming->matrixVariables->values
            = new MatrixVariableValues();
    optimization->solution[solIdx]->matrixProgramming->matrixVariables->values->numberOfMatrixVar
         = numberOfMatrixVar_;
    optimization->solution[solIdx]->matrixProgramming->matrixVariables->numberOfOtherMatrixVariableResults
        = numberOfOtherMatrixVariableResults_;

    optimization->solution[solIdx]->matrixProgramming->matrixVariables->values->matrixVar
            = new OSMatrixWithMatrixVarIdx*[numberOfMatrixVar_];
    optimization->solution[solIdx]->matrixProgramming->matrixVariables->other
            = new OtherMatrixVariableResult*[numberOfOtherMatrixVariableResults_];

    //Note: Initial to zero, so we can check for double usage later
    for (int i=0; i < numberOfMatrixVar_; i++)
        optimization->solution[solIdx]->matrixProgramming->matrixVariables->values->matrixVar[i] = NULL;
    for (int i=0; i < numberOfOtherMatrixVariableResults_; i++)
        optimization->solution[solIdx]->matrixProgramming->matrixVariables->other[i] = NULL;

    return true;
}//setMatrixVariableSolution


bool OSResult::setMatrixVarValuesAttributes(int solIdx, int idx, int matrixVarIdx, int numberOfRows, 
            int numberOfColumns, ENUM_MATRIX_SYMMETRY symmetry, 
            ENUM_MATRIX_TYPE type, std::string name)
{
    int nSols = this->getSolutionNumber();
    if (nSols <= 0) return false;
    if (optimization == NULL) return false;
    if (optimization->solution == NULL ||
            solIdx < 0 || solIdx >=  nSols) return false;
    if (optimization->solution[solIdx] == NULL) return false;
    if (optimization->solution[solIdx]->matrixProgramming == NULL) return false;
    if (optimization->solution[solIdx]->matrixProgramming->matrixVariables == NULL) return false; 
    if (optimization->solution[solIdx]->matrixProgramming->matrixVariables->values == NULL) return false;
    if (optimization->solution[solIdx]->matrixProgramming->matrixVariables->values->matrixVar == NULL)
        return false;
    if (idx < 0 || idx >= optimization->solution[solIdx]->matrixProgramming
                                    ->matrixVariables->values->numberOfMatrixVar) return false;
    if (optimization->solution[solIdx]->matrixProgramming->matrixVariables->values->matrixVar[idx]
        != NULL) return false;
    optimization->solution[solIdx]->matrixProgramming->matrixVariables->values->matrixVar[idx]
        = new OSMatrixWithMatrixVarIdx();
    optimization->solution[solIdx]->matrixProgramming->matrixVariables->values->matrixVar[idx]
        ->matrixVarIdx = matrixVarIdx;
    optimization->solution[solIdx]->matrixProgramming->matrixVariables->values->matrixVar[idx]
        ->numberOfRows = numberOfRows;
    optimization->solution[solIdx]->matrixProgramming->matrixVariables->values->matrixVar[idx]
        ->numberOfColumns = numberOfColumns;
    optimization->solution[solIdx]->matrixProgramming->matrixVariables->values->matrixVar[idx]
        ->symmetry = symmetry;
    optimization->solution[solIdx]->matrixProgramming->matrixVariables->values->matrixVar[idx]
        ->declaredMatrixType = type;
    optimization->solution[solIdx]->matrixProgramming->matrixVariables->values->matrixVar[idx]->name = name;
    return true;
}//setMatrixVarValuesAttributes

bool OSResult::setMatrixVarValuesBlockStructure(int solIdx, int idx, int* colOffset, int colOffsetSize,
            int* rowOffset, int rowOffsetSize, int numberOfBlocks, int blocksConstructorIdx)
{
    int nSols = this->getSolutionNumber();
    if (nSols <= 0) return false;
    if (optimization == NULL) return false;
    if (optimization->solution == NULL ||
            solIdx < 0 || solIdx >=  nSols) return false;
    if (optimization->solution[solIdx] == NULL) return false;
    if (optimization->solution[solIdx]->matrixProgramming == NULL) return false;
    if (optimization->solution[solIdx]->matrixProgramming->matrixVariables == NULL) return false; 
    if (optimization->solution[solIdx]->matrixProgramming->matrixVariables->values == NULL) return false;
    if (optimization->solution[solIdx]->matrixProgramming->matrixVariables->values->matrixVar == NULL)
        return false;
    if (idx < 0 || idx >= optimization->solution[solIdx]->matrixProgramming
                                    ->matrixVariables->values->numberOfMatrixVar) return false;

    optimization->solution[solIdx]->matrixProgramming->matrixVariables->values->matrixVar[idx]
        ->inumberOfChildren = 1; //single Blocks constructor
    optimization->solution[solIdx]->matrixProgramming->matrixVariables->values->matrixVar[idx]
        ->m_mChildren = new MatrixNode*[1];
    optimization->solution[solIdx]->matrixProgramming->matrixVariables->values->matrixVar[idx]
        ->m_mChildren[0] = new MatrixBlocks();
    optimization->solution[solIdx]->matrixProgramming->matrixVariables->values->matrixVar[idx]
        ->m_mChildren[0]->inumberOfChildren = numberOfBlocks;

    ((MatrixBlocks*)optimization->solution[solIdx]->matrixProgramming->matrixVariables->values
        ->matrixVar[idx]->m_mChildren[0])->colOffset = new IntVector(numberOfBlocks+1);

    for (int i=0; i <= numberOfBlocks; i++)
        ((MatrixBlocks*)optimization->solution[solIdx]->matrixProgramming->matrixVariables->values
            ->matrixVar[idx]->m_mChildren[0])->colOffset->el[i] = colOffset[i];

    ((MatrixBlocks*)optimization->solution[solIdx]->matrixProgramming->matrixVariables->values
        ->matrixVar[idx]->m_mChildren[0])->rowOffset = new IntVector(numberOfBlocks+1);

    for (int i=0; i <= numberOfBlocks; i++)
        ((MatrixBlocks*)optimization->solution[solIdx]->matrixProgramming->matrixVariables->values
            ->matrixVar[idx]->m_mChildren[0])->rowOffset->el[i] = rowOffset[i];

    //Note well: Individual pointers are set to NULL, which allows a check against double allocation later
    ((MatrixBlocks*)optimization->solution[solIdx]->matrixProgramming->matrixVariables->values
        ->matrixVar[idx]->m_mChildren[0])->m_mChildren = new MatrixNode*[numberOfBlocks];

    for (int i=0; i<numberOfBlocks; i++)
        ((MatrixBlocks*)optimization->solution[solIdx]->matrixProgramming->matrixVariables->values
            ->matrixVar[idx]->m_mChildren[0])->m_mChildren[i] = NULL;

    return true;
}//setMatrixVarValuesBlockStructure


bool OSResult::setMatrixVarValuesBlockElements(int solIdx, int idx, int blkno,
            int blkRowIdx, int blkColIdx, int nz, int* start, int* index,
            MatrixElementValues* value, ENUM_MATRIX_TYPE valueType,
            ENUM_MATRIX_SYMMETRY symmetry, bool rowMajor)
{
    try
    {
        int nSols = this->getSolutionNumber();
        if (nSols <= 0) return false;
        if (optimization == NULL) return false;
        if (optimization->solution == NULL ||
            solIdx < 0 || solIdx >= nSols) return false;
        if (optimization->solution[solIdx] == NULL) return false;
        if (optimization->solution[solIdx]->matrixProgramming == NULL) return false;
        if (optimization->solution[solIdx]->matrixProgramming->matrixVariables == NULL) return false; 
        if (optimization->solution[solIdx]->matrixProgramming->matrixVariables->values == NULL) 
            return false;
        if (optimization->solution[solIdx]->matrixProgramming->matrixVariables->values->matrixVar == NULL)
            return false;
        if (idx < 0 || idx >= optimization->solution[solIdx]->matrixProgramming
                                        ->matrixVariables->values->numberOfMatrixVar) return false;
        if (optimization->solution[solIdx]->matrixProgramming->matrixVariables->values->matrixVar[idx]
                == NULL) return false;
        if (optimization->solution[solIdx]->matrixProgramming->matrixVariables->values->matrixVar[idx]
            ->m_mChildren[0] == NULL) return false;

        if (blkno < 0 ||
            blkno >= ((MatrixBlocks*)optimization->solution[solIdx]->matrixProgramming->matrixVariables
                ->values->matrixVar[idx]->m_mChildren[0])->inumberOfChildren) return false;

        if ( ((MatrixBlocks*)optimization->solution[solIdx]->matrixProgramming->matrixVariables
                    ->values->matrixVar[idx]->m_mChildren[0])->m_mChildren[blkno] != NULL)
            throw ErrorClass("memory error in setMatrixVarBlockElements: block was previously allocated");

        ((MatrixBlocks*)optimization->solution[solIdx]->matrixProgramming->matrixVariables
                    ->values->matrixVar[idx]->m_mChildren[0])->m_mChildren[blkno] = new MatrixBlock();

        ((MatrixBlock*)((MatrixBlocks*)optimization->solution[solIdx]
                    ->matrixProgramming->matrixVariables->values->matrixVar[idx]->m_mChildren[0])
                    ->m_mChildren[blkno])->blockRowIdx = blkRowIdx;

        ((MatrixBlock*)((MatrixBlocks*)optimization->solution[solIdx]
                    ->matrixProgramming->matrixVariables->values->matrixVar[idx]->m_mChildren[0])
                    ->m_mChildren[blkno])->blockColIdx = blkColIdx;

        ((MatrixBlock*)((MatrixBlocks*)optimization->solution[solIdx]
                    ->matrixProgramming->matrixVariables->values->matrixVar[idx]->m_mChildren[0])
                    ->m_mChildren[blkno])->symmetry = symmetry;

        ((MatrixBlock*)((MatrixBlocks*)optimization->solution[solIdx]
                    ->matrixProgramming->matrixVariables->values->matrixVar[idx]->m_mChildren[0])
                    ->m_mChildren[blkno])->inumberOfChildren = 1;

        ((MatrixBlock*)((MatrixBlocks*)optimization->solution[solIdx]
                    ->matrixProgramming->matrixVariables->values->matrixVar[idx]->m_mChildren[0])
                    ->m_mChildren[blkno])->m_mChildren = new MatrixNode*[1];

        if (valueType == ENUM_MATRIX_TYPE_constant)
            ((MatrixBlocks*)optimization->solution[solIdx]
                    ->matrixProgramming->matrixVariables->values->matrixVar[idx]->m_mChildren[0])
                    ->m_mChildren[blkno]->m_mChildren[0] = new ConstantMatrixElements();
        else
            throw ErrorClass("in setMatrixVarBlockElements: element type not yet implemented:" 
                    + returnMatrixTypeString(valueType));

        ((MatrixElements*)((MatrixBlocks*)optimization->solution[solIdx]
                    ->matrixProgramming->matrixVariables->values->matrixVar[idx]->m_mChildren[0])
                    ->m_mChildren[blkno]->m_mChildren[0])->numberOfValues = nz;

        int startSize;

        if (rowMajor)
            startSize 
                = ((MatrixBlocks*)optimization->solution[solIdx]->matrixProgramming->matrixVariables
                    ->values->matrixVar[idx]->m_mChildren[0])->rowOffset->el[blkRowIdx+1]
                - ((MatrixBlocks*)optimization->solution[solIdx]->matrixProgramming->matrixVariables
                    ->values->matrixVar[idx]->m_mChildren[0])->rowOffset->el[blkRowIdx] + 1;
        else
            startSize 
                = ((MatrixBlocks*)optimization->solution[solIdx]->matrixProgramming->matrixVariables
                    ->values->matrixVar[idx]->m_mChildren[0])->colOffset->el[blkColIdx+1]
                - ((MatrixBlocks*)optimization->solution[solIdx]->matrixProgramming->matrixVariables
                    ->values->matrixVar[idx]->m_mChildren[0])->colOffset->el[blkColIdx] + 1;

        ((MatrixElements*)((MatrixBlocks*)optimization->solution[solIdx]
                    ->matrixProgramming->matrixVariables->values->matrixVar[idx]->m_mChildren[0])
                    ->m_mChildren[blkno]->m_mChildren[0])->start = new IntVector(startSize);

        for (int i=0; i<startSize; i++)
            ((MatrixElements*)((MatrixBlocks*)optimization->solution[solIdx]
                    ->matrixProgramming->matrixVariables->values->matrixVar[idx]->m_mChildren[0])
                    ->m_mChildren[blkno]->m_mChildren[0])->start->el[i] = start[i];

        if (nz > 0)
        {
            ((MatrixElements*)((MatrixBlocks*)optimization->solution[solIdx]
                    ->matrixProgramming->matrixVariables->values->matrixVar[idx]->m_mChildren[0])
                    ->m_mChildren[blkno]->m_mChildren[0])->index = new IntVector(nz);
        
            for (int i=0; i<nz; i++)
                ((MatrixElements*)((MatrixBlocks*)optimization->solution[solIdx]
                    ->matrixProgramming->matrixVariables->values->matrixVar[idx]->m_mChildren[0])
                    ->m_mChildren[blkno]->m_mChildren[0])->index->el[i] = index[i];

            if (valueType == ENUM_MATRIX_TYPE_constant)
            {
                ((ConstantMatrixElements*)((MatrixBlocks*)optimization->solution[solIdx]
                        ->matrixProgramming->matrixVariables->values->matrixVar[idx]->m_mChildren[0])
                        ->m_mChildren[blkno]->m_mChildren[0])->value = new ConstantMatrixValues();

                ((ConstantMatrixElements*)((MatrixBlocks*)optimization->solution[solIdx]
                        ->matrixProgramming->matrixVariables->values->matrixVar[idx]->m_mChildren[0])
                        ->m_mChildren[blkno]->m_mChildren[0])->value->numberOfEl = nz;

                ((ConstantMatrixElements*)((MatrixBlocks*)optimization->solution[solIdx]
                        ->matrixProgramming->matrixVariables->values->matrixVar[idx]->m_mChildren[0])
                        ->m_mChildren[blkno]->m_mChildren[0])->value->el = new double[nz];

                for (int i=0; i<nz; i++)            
                    ((ConstantMatrixValues*)((ConstantMatrixElements*)((MatrixBlocks*)optimization
                        ->solution[solIdx]->matrixProgramming->matrixVariables->values->matrixVar[idx]
                        ->m_mChildren[0])->m_mChildren[blkno]->m_mChildren[0])->value)->el[i]
                    = ((ConstantMatrixValues*)value)->el[i];
            }
        }
    }
    catch(const ErrorClass& eclass)
    {
        throw ErrorClass( eclass.errormsg);
    }
    return true;
}//setMatrixVarValuesBlockElements


bool OSResult::setMatrixVariablesOtherResultGeneralAttributes(int solIdx, int idx, std::string name, 
                            std::string description,   std::string value,          std::string type,
                            std::string solver,        std::string category,
                            int numberOfMatrixVar,     std::string matrixType, 
                            int numberOfEnumerations,  std::string enumType)
{
    int nSols = this->getSolutionNumber();
    if (nSols <= 0) return false;
    if (optimization == NULL) return false;
    if (optimization->solution == NULL ||
            solIdx < 0 || solIdx >= nSols) return false;
    if (optimization->solution[solIdx] == NULL) return false;
    if (optimization->solution[solIdx]->matrixProgramming == NULL) return false;
    if (optimization->solution[solIdx]->matrixProgramming->matrixVariables == NULL) return false; 
    if (optimization->solution[solIdx]->matrixProgramming->matrixVariables->other == NULL) return false;
    if (idx < 0 || idx >= optimization->solution[solIdx]->matrixProgramming
                                ->matrixVariables->numberOfOtherMatrixVariableResults) return false;
    if (optimization->solution[solIdx]->matrixProgramming->matrixVariables->other[idx] != NULL) 
        return false;
    optimization->solution[solIdx]->matrixProgramming->matrixVariables->other[idx]
        = new OtherMatrixVariableResult();
    optimization->solution[solIdx]->matrixProgramming->matrixVariables->other[idx]->name = name;
    optimization->solution[solIdx]->matrixProgramming->matrixVariables->other[idx]->description
        = description; 
    optimization->solution[solIdx]->matrixProgramming->matrixVariables->other[idx]->value    = value;
    optimization->solution[solIdx]->matrixProgramming->matrixVariables->other[idx]->type     = type;
    optimization->solution[solIdx]->matrixProgramming->matrixVariables->other[idx]->solver   = solver;
    optimization->solution[solIdx]->matrixProgramming->matrixVariables->other[idx]->category = category;
    optimization->solution[solIdx]->matrixProgramming->matrixVariables->other[idx]->numberOfMatrixVar
        = numberOfMatrixVar;
    optimization->solution[solIdx]->matrixProgramming->matrixVariables->other[idx]->matrixType
        = matrixType;
    optimization->solution[solIdx]->matrixProgramming->matrixVariables->other[idx]->numberOfEnumerations
        = numberOfEnumerations;
    optimization->solution[solIdx]->matrixProgramming->matrixVariables->other[idx]->enumType = enumType;

    if (numberOfMatrixVar > 0)
    {
        optimization->solution[solIdx]->matrixProgramming->matrixVariables->other[idx]->matrixVar
            = new OSMatrixWithMatrixVarIdx*[numberOfMatrixVar];
        for (int i=0; i<numberOfMatrixVar; i++)
            optimization->solution[solIdx]->matrixProgramming->matrixVariables->other[idx]->matrixVar[i]
                = NULL;
    }

    if (numberOfEnumerations > 0)
    {
        optimization->solution[solIdx]->matrixProgramming->matrixVariables->other[idx]->enumeration
            = new OtherOptionOrResultEnumeration*[numberOfEnumerations];
        for (int i=0; i<numberOfEnumerations; i++)
            optimization->solution[solIdx]->matrixProgramming->matrixVariables->other[idx]->enumeration[i]
                = NULL;
    }
    return true;
}//setMatrixVariablesOtherResultGeneralAttributes


bool OSResult::setMatrixVariablesOtherResultMatrixAttributes(int solIdx, int otherIdx, int matrixVarIdx, 
            int numberOfRows, int numberOfColumns, ENUM_MATRIX_SYMMETRY symmetry, 
            ENUM_MATRIX_TYPE type, std::string name)
{
    int nSols = this->getSolutionNumber();
    if (nSols <= 0) return false;
    if (optimization == NULL) return false;
    if (optimization->solution == NULL ||
            solIdx < 0 || solIdx >= nSols) return false;
    if (optimization->solution[solIdx] == NULL) return false;
    if (optimization->solution[solIdx]->matrixProgramming == NULL) return false;
    if (optimization->solution[solIdx]->matrixProgramming->matrixVariables == NULL) return false; 
    if (optimization->solution[solIdx]->matrixProgramming->matrixVariables->other == NULL) return false;

    if (otherIdx < 0 || otherIdx > optimization->solution[solIdx]->matrixProgramming->matrixVariables
        ->numberOfOtherMatrixVariableResults) return false;
    if (optimization->solution[solIdx]->matrixProgramming->matrixVariables->other[otherIdx] == NULL)
        return false;
    if (optimization->solution[solIdx]->matrixProgramming->matrixVariables->other[otherIdx]->matrixVar
        == NULL) return false;
    if (matrixVarIdx < 0 || 
        matrixVarIdx >= optimization->solution[solIdx]->matrixProgramming->matrixVariables
            ->other[otherIdx]->numberOfMatrixVar) return false;
    if (optimization->solution[solIdx]->matrixProgramming->matrixVariables->other[otherIdx]
        ->matrixVar[matrixVarIdx] != NULL) return false;
    optimization->solution[solIdx]->matrixProgramming->matrixVariables->other[otherIdx]
        ->matrixVar[matrixVarIdx] = new OSMatrixWithMatrixVarIdx();
    optimization->solution[solIdx]->matrixProgramming->matrixVariables->other[otherIdx]
        ->matrixVar[matrixVarIdx]->matrixVarIdx = matrixVarIdx;
    optimization->solution[solIdx]->matrixProgramming->matrixVariables->other[otherIdx]
        ->matrixVar[matrixVarIdx]->numberOfRows = numberOfRows;
    optimization->solution[solIdx]->matrixProgramming->matrixVariables->other[otherIdx]
        ->matrixVar[matrixVarIdx]->numberOfColumns = numberOfColumns;
    optimization->solution[solIdx]->matrixProgramming->matrixVariables->other[otherIdx]
        ->matrixVar[matrixVarIdx]->symmetry = symmetry;
    optimization->solution[solIdx]->matrixProgramming->matrixVariables->other[otherIdx]
        ->matrixVar[matrixVarIdx]->declaredMatrixType = type;
    optimization->solution[solIdx]->matrixProgramming->matrixVariables->other[otherIdx]
        ->matrixVar[matrixVarIdx]->name = name;
    return true;
}//setMatrixVariablesOtherResultMatrixAttributes

bool OSResult::setMatrixVariablesOtherResultBlockStructure(int solIdx, int otherIdx, int matrixVarIdx,
                                int* colOffset, int colOffsetSize, int* rowOffset, int rowOffsetSize,
                                int numberOfBlocks, int blocksConstructorIdx)
{
    int nSols = this->getSolutionNumber();
    if (nSols <= 0) return false;
    if (optimization == NULL) return false;
    if (optimization->solution == NULL ||
            solIdx < 0 || solIdx >= nSols) return false;
    if (optimization->solution[solIdx] == NULL) return false;
    if (optimization->solution[solIdx]->matrixProgramming == NULL) return false;
    if (optimization->solution[solIdx]->matrixProgramming->matrixVariables == NULL) return false; 
    if (optimization->solution[solIdx]->matrixProgramming->matrixVariables->other == NULL) return false;
    if (otherIdx < 0 || otherIdx >= optimization->solution[solIdx]->matrixProgramming->matrixVariables
        ->numberOfOtherMatrixVariableResults) return false;
    if (optimization->solution[solIdx]->matrixProgramming->matrixVariables->other[otherIdx] == NULL)
        return false;
    if (optimization->solution[solIdx]->matrixProgramming->matrixVariables->other[otherIdx]
        ->matrixVar == NULL) return false;
    if (matrixVarIdx < 0 || matrixVarIdx >= optimization->solution[solIdx]->matrixProgramming
                                ->matrixVariables->other[otherIdx]->numberOfMatrixVar) return false;

    optimization->solution[solIdx]->matrixProgramming->matrixVariables->other[otherIdx]
        ->matrixVar[matrixVarIdx]->inumberOfChildren = 1; //single Blocks constructor
    optimization->solution[solIdx]->matrixProgramming->matrixVariables->other[otherIdx]
        ->matrixVar[matrixVarIdx]->m_mChildren = new MatrixNode*[1];
    optimization->solution[solIdx]->matrixProgramming->matrixVariables->other[otherIdx]
        ->matrixVar[matrixVarIdx]->m_mChildren[0] = new MatrixBlocks();
    optimization->solution[solIdx]->matrixProgramming->matrixVariables->other[otherIdx]
        ->matrixVar[matrixVarIdx]->m_mChildren[0]->inumberOfChildren = numberOfBlocks;

    ((MatrixBlocks*)optimization->solution[solIdx]->matrixProgramming->matrixVariables->other[otherIdx]
        ->matrixVar[matrixVarIdx]->m_mChildren[0])->colOffset = new IntVector(numberOfBlocks+1);

    for (int i=0; i <= numberOfBlocks; i++)
        ((MatrixBlocks*)optimization->solution[solIdx]->matrixProgramming->matrixVariables->other[otherIdx]
            ->matrixVar[matrixVarIdx]->m_mChildren[0])->colOffset->el[i] = colOffset[i];

    ((MatrixBlocks*)optimization->solution[solIdx]->matrixProgramming->matrixVariables->other[otherIdx]
        ->matrixVar[matrixVarIdx]->m_mChildren[0])->rowOffset = new IntVector(numberOfBlocks+1);

    for (int i=0; i <= numberOfBlocks; i++)
        ((MatrixBlocks*)optimization->solution[solIdx]->matrixProgramming->matrixVariables->other[otherIdx]
            ->matrixVar[matrixVarIdx]->m_mChildren[0])->rowOffset->el[i] = rowOffset[i];

    //Note well: Individual pointers are set to NULL, which allows a check against double allocation later
    ((MatrixBlocks*)optimization->solution[solIdx]->matrixProgramming->matrixVariables->other[otherIdx]
        ->matrixVar[matrixVarIdx]->m_mChildren[0])->m_mChildren = new MatrixNode*[numberOfBlocks];

    for (int i=0; i<numberOfBlocks; i++)
        ((MatrixBlocks*)optimization->solution[solIdx]->matrixProgramming->matrixVariables->other[otherIdx]
            ->matrixVar[matrixVarIdx]->m_mChildren[0])->m_mChildren[i] = NULL;

    return true;
}//setMatrixVariablesOtherResultBlockStructure

bool OSResult::setMatrixVariablesOtherResultBlockElements(int solIdx, int otherIdx, int matrixVarIdx, 
                            int blkno, int blkRowIdx, int blkColIdx, int nz, int* start, int* index,
                            MatrixElementValues* value, ENUM_MATRIX_TYPE valueType,
                            ENUM_MATRIX_SYMMETRY symmetry, bool rowMajor)
{
    try
    {
        int nSols = this->getSolutionNumber();
        if (nSols <= 0) return false;
        if (optimization == NULL) return false;
        if (optimization->solution == NULL ||
            solIdx < 0 || solIdx >=  nSols) return false;
        if (optimization->solution[solIdx] == NULL) return false;
        if (optimization->solution[solIdx]->matrixProgramming == NULL) return false;
        if (optimization->solution[solIdx]->matrixProgramming->matrixVariables == NULL) return false; 

        if (optimization->solution[solIdx]->matrixProgramming->matrixVariables->other == NULL) return false;
        if (otherIdx < 0 || otherIdx >= optimization->solution[solIdx]->matrixProgramming->matrixVariables
            ->numberOfOtherMatrixVariableResults) return false;
        if (optimization->solution[solIdx]->matrixProgramming->matrixVariables->other[otherIdx] == NULL)
            return false;
        if (optimization->solution[solIdx]->matrixProgramming->matrixVariables->other[otherIdx]
            ->matrixVar == NULL) return false;
        if (matrixVarIdx < 0 || matrixVarIdx >= optimization->solution[solIdx]->matrixProgramming
                                    ->matrixVariables->other[otherIdx]->numberOfMatrixVar) return false;

        if (optimization->solution[solIdx]->matrixProgramming->matrixVariables->other[otherIdx]
            ->matrixVar[matrixVarIdx] == NULL) return false;
        if (optimization->solution[solIdx]->matrixProgramming->matrixVariables->other[otherIdx]
            ->matrixVar[matrixVarIdx]->m_mChildren[0] == NULL) return false;

        if (blkno < 0 ||
            blkno > ((MatrixBlocks*)optimization->solution[solIdx]->matrixProgramming->matrixVariables
                ->other[otherIdx]->matrixVar[matrixVarIdx]->m_mChildren[0])->inumberOfChildren) 
            return false;

        if ( ((MatrixBlocks*)optimization->solution[solIdx]->matrixProgramming->matrixVariables
                    ->other[otherIdx]->matrixVar[matrixVarIdx]->m_mChildren[0])->m_mChildren[blkno] != NULL)
            throw ErrorClass("memory error in setMatrixVarBlockElements: block was previously allocated");

        ((MatrixBlocks*)optimization->solution[solIdx]->matrixProgramming->matrixVariables
                    ->other[otherIdx]->matrixVar[matrixVarIdx]->m_mChildren[0])->m_mChildren[blkno]
            = new MatrixBlock();

        ((MatrixBlock*)((MatrixBlocks*)optimization->solution[solIdx]
                    ->matrixProgramming->matrixVariables->other[otherIdx]->matrixVar[matrixVarIdx]
                    ->m_mChildren[0])->m_mChildren[blkno])->blockRowIdx = blkRowIdx;

        ((MatrixBlock*)((MatrixBlocks*)optimization->solution[solIdx]
                    ->matrixProgramming->matrixVariables->other[otherIdx]->matrixVar[matrixVarIdx]
                    ->m_mChildren[0])->m_mChildren[blkno])->blockColIdx = blkColIdx;

        ((MatrixBlock*)((MatrixBlocks*)optimization->solution[solIdx]
                    ->matrixProgramming->matrixVariables->other[otherIdx]->matrixVar[matrixVarIdx]
                    ->m_mChildren[0])->m_mChildren[blkno])->symmetry = symmetry;

        ((MatrixBlock*)((MatrixBlocks*)optimization->solution[solIdx]
                    ->matrixProgramming->matrixVariables->other[otherIdx]->matrixVar[matrixVarIdx]
                    ->m_mChildren[0])->m_mChildren[blkno])->inumberOfChildren = 1;

        ((MatrixBlock*)((MatrixBlocks*)optimization->solution[solIdx]
                    ->matrixProgramming->matrixVariables->other[otherIdx]->matrixVar[matrixVarIdx]
                    ->m_mChildren[0])->m_mChildren[blkno])->m_mChildren = new MatrixNode*[1];

        if (valueType == ENUM_MATRIX_TYPE_constant)
            ((MatrixBlocks*)optimization->solution[solIdx]
                    ->matrixProgramming->matrixVariables->other[otherIdx]->matrixVar[matrixVarIdx]
                    ->m_mChildren[0])->m_mChildren[blkno]->m_mChildren[0] = new ConstantMatrixElements();
        else
            throw ErrorClass("in setMatrixVarBlockElements: element type not yet implemented:" 
                    + returnMatrixTypeString(valueType));

        ((MatrixElements*)((MatrixBlocks*)optimization->solution[solIdx]
                    ->matrixProgramming->matrixVariables->other[otherIdx]->matrixVar[matrixVarIdx]
                    ->m_mChildren[0])->m_mChildren[blkno]->m_mChildren[0])->numberOfValues = nz;

        int startSize;

        if (rowMajor)
            startSize 
                = ((MatrixBlocks*)optimization->solution[solIdx]->matrixProgramming->matrixVariables
                    ->other[otherIdx]->matrixVar[matrixVarIdx]->m_mChildren[0])->rowOffset->el[blkRowIdx+1]
                - ((MatrixBlocks*)optimization->solution[solIdx]->matrixProgramming->matrixVariables
                    ->other[otherIdx]->matrixVar[matrixVarIdx]->m_mChildren[0])->rowOffset->el[blkRowIdx] + 1;
        else
            startSize 
                = ((MatrixBlocks*)optimization->solution[solIdx]->matrixProgramming->matrixVariables
                    ->other[otherIdx]->matrixVar[matrixVarIdx]->m_mChildren[0])->colOffset->el[blkColIdx+1]
                - ((MatrixBlocks*)optimization->solution[solIdx]->matrixProgramming->matrixVariables
                    ->other[otherIdx]->matrixVar[matrixVarIdx]->m_mChildren[0])->colOffset->el[blkColIdx] + 1;

        ((MatrixElements*)((MatrixBlocks*)optimization->solution[solIdx]
                    ->matrixProgramming->matrixVariables->other[otherIdx]->matrixVar[matrixVarIdx]
                    ->m_mChildren[0])->m_mChildren[blkno]->m_mChildren[0])->start
            = new IntVector(startSize);

        for (int i=0; i<startSize; i++)
            ((MatrixElements*)((MatrixBlocks*)optimization->solution[solIdx]
                    ->matrixProgramming->matrixVariables->other[otherIdx]->matrixVar[matrixVarIdx]
                    ->m_mChildren[0])->m_mChildren[blkno]->m_mChildren[0])->start->el[i] = start[i];

        if (nz > 0)
        {
            ((MatrixElements*)((MatrixBlocks*)optimization->solution[solIdx]
                    ->matrixProgramming->matrixVariables->other[otherIdx]->matrixVar[matrixVarIdx]
                    ->m_mChildren[0])->m_mChildren[blkno]->m_mChildren[0])->index = new IntVector(nz);
        
            for (int i=0; i<nz; i++)
                ((MatrixElements*)((MatrixBlocks*)optimization->solution[solIdx]
                    ->matrixProgramming->matrixVariables->other[otherIdx]->matrixVar[matrixVarIdx]
                    ->m_mChildren[0])->m_mChildren[blkno]->m_mChildren[0])->index->el[i] = index[i];

            if (valueType == ENUM_MATRIX_TYPE_constant)
            {
                ((ConstantMatrixElements*)((MatrixBlocks*)optimization->solution[solIdx]
                        ->matrixProgramming->matrixVariables->other[otherIdx]->matrixVar[matrixVarIdx]
                        ->m_mChildren[0])->m_mChildren[blkno]->m_mChildren[0])->value
                    = new ConstantMatrixValues();

                ((ConstantMatrixElements*)((MatrixBlocks*)optimization->solution[solIdx]
                        ->matrixProgramming->matrixVariables->other[otherIdx]->matrixVar[matrixVarIdx]
                        ->m_mChildren[0])->m_mChildren[blkno]->m_mChildren[0])->value->numberOfEl = nz;

                ((ConstantMatrixElements*)((MatrixBlocks*)optimization->solution[solIdx]
                        ->matrixProgramming->matrixVariables->other[otherIdx]->matrixVar[matrixVarIdx]
                        ->m_mChildren[0])->m_mChildren[blkno]->m_mChildren[0])->value->el = new double[nz];

                for (int i=0; i<nz; i++)            
                    ((ConstantMatrixValues*)((ConstantMatrixElements*)((MatrixBlocks*)optimization
                        ->solution[solIdx]->matrixProgramming->matrixVariables->other[otherIdx]
                        ->matrixVar[matrixVarIdx]->m_mChildren[0])->m_mChildren[blkno]->m_mChildren[0])
                        ->value)->el[i] = ((ConstantMatrixValues*)value)->el[i];
            }
        }
    }
    catch(const ErrorClass& eclass)
    {
        throw ErrorClass( eclass.errormsg);
    }
    return true;
}//setMatrixVariablesOtherResultBlockElements


bool OSResult::setNumberOfOtherSolutionResults(int solIdx, int num)
{
    int nSols = this->getSolutionNumber();
    if (nSols <= 0) return false;
    if (optimization == NULL) return false;
    if (optimization->solution == NULL ||
            solIdx < 0 || solIdx >=  nSols) return false;
    if (optimization->solution[solIdx] == NULL)
    {
        optimization->solution[solIdx] = new OptimizationSolution();
    }
    if (optimization->solution[solIdx]->otherSolutionResults == NULL)
    {
        optimization->solution[solIdx]->otherSolutionResults = new OtherSolutionResults();
    }
    if (num < 0) return false;
    if (optimization->solution[solIdx]->otherSolutionResults->otherSolutionResult != NULL) return false;
    optimization->solution[solIdx]->otherSolutionResults->numberOfOtherSolutionResults = num;
    if (num > 0)
    {
        optimization->solution[solIdx]->otherSolutionResults->otherSolutionResult = new OtherSolutionResult*[num];
        for(int i = 0; i < num; i++)
        {
            optimization->solution[solIdx]->otherSolutionResults->otherSolutionResult[i] = new OtherSolutionResult();
        }
    }
    return true;
}//setNumberOfOtherSolutionResults

bool OSResult::setOtherSolutionResultName(int solIdx, int otherIdx, std::string name)
{
    int nSols = this->getSolutionNumber();
    if (nSols <= 0) return false;
    if (optimization == NULL) return false;
    if (optimization->solution == NULL ||
            solIdx < 0 || solIdx >=  nSols) return false;
    if (optimization->solution[solIdx] == NULL) return false;
    if (optimization->solution[solIdx]->otherSolutionResults == NULL) return false;
    if (optimization->solution[solIdx]->otherSolutionResults->otherSolutionResult[otherIdx] == NULL) return false;
    optimization->solution[solIdx]->otherSolutionResults->otherSolutionResult[otherIdx]->name = name;
    return true;
}//setOtherSolutionResultName

bool OSResult::setOtherSolutionResultValue(int solIdx, int otherIdx, std::string value)
{
    int nSols = this->getSolutionNumber();
    if (nSols <= 0) return false;
    if (optimization == NULL) return false;
    if (optimization->solution == NULL ||
            solIdx < 0 || solIdx >=  nSols) return false;
    if (optimization->solution[solIdx] == NULL) return false;
    if (optimization->solution[solIdx]->otherSolutionResults == NULL) return false;
    if (optimization->solution[solIdx]->otherSolutionResults->otherSolutionResult[otherIdx] == NULL) return false;
    optimization->solution[solIdx]->otherSolutionResults->otherSolutionResult[otherIdx]->value = value;
    return true;
}//setOtherSolutionResultValue

bool OSResult::setOtherSolutionResultCategory(int solIdx, int otherIdx, std::string category)
{
    int nSols = this->getSolutionNumber();
    if (nSols <= 0) return false;
    if (optimization == NULL) return false;
    if (optimization->solution == NULL ||
            solIdx < 0 || solIdx >=  nSols) return false;
    if (optimization->solution[solIdx] == NULL) return false;
    if (optimization->solution[solIdx]->otherSolutionResults == NULL) return false;
    if (optimization->solution[solIdx]->otherSolutionResults->otherSolutionResult[otherIdx] == NULL) return false;
    optimization->solution[solIdx]->otherSolutionResults->otherSolutionResult[otherIdx]->category = category;
    return true;
}//setOtherSolutionResultCategory


bool OSResult::setOtherSolutionResultDescription(int solIdx, int otherIdx, std::string description)
{
    int nSols = this->getSolutionNumber();
    if (nSols <= 0) return false;
    if (optimization == NULL) return false;
    if (optimization->solution == NULL ||
            solIdx < 0 || solIdx >=  nSols) return false;
    if (optimization->solution[solIdx] == NULL) return false;
    if (optimization->solution[solIdx]->otherSolutionResults == NULL) return false;
    if (optimization->solution[solIdx]->otherSolutionResults->otherSolutionResult[otherIdx] == NULL) return false;
    optimization->solution[solIdx]->otherSolutionResults->otherSolutionResult[otherIdx]->description = description;
    return true;
}//setOtherSolutionResultDescription


bool OSResult::setOtherSolutionResultNumberOfItems(int solIdx, int otherIdx, int numberOfItems)
{
    int nSols = this->getSolutionNumber();
    if (nSols <= 0) return false;
    if (optimization == NULL) return false;
    if (optimization->solution == NULL ||
            solIdx < 0 || solIdx >=  nSols) return false;
    if (optimization->solution[solIdx] == NULL) return false;
    if (optimization->solution[solIdx]->otherSolutionResults == NULL) return false;
    if (optimization->solution[solIdx]->otherSolutionResults->otherSolutionResult[otherIdx] == NULL)
        optimization->solution[solIdx]->otherSolutionResults->otherSolutionResult[otherIdx] = new OtherSolutionResult();
    if (numberOfItems < 0) return false;
    if (optimization->solution[solIdx]->otherSolutionResults->otherSolutionResult[otherIdx]->item != NULL) return false;
    optimization->solution[solIdx]->otherSolutionResults->otherSolutionResult[otherIdx]->numberOfItems = numberOfItems;
    if (numberOfItems > 0)
        optimization->solution[solIdx]->otherSolutionResults->otherSolutionResult[otherIdx]->item = new std::string[numberOfItems];
    return true;
}//setOtherSolutionResultNumberOfItems

bool OSResult::setOtherSolutionResultItem(int solIdx, int otherIdx, int itemIdx, std::string item)
{
    int nSols = this->getSolutionNumber();
    if (nSols <= 0) return false;
    if (optimization == NULL) return false;
    if (optimization->solution == NULL ||
            solIdx < 0 || solIdx >=  nSols) return false;
    if (optimization->solution[solIdx] == NULL) return false;
    if (optimization->solution[solIdx]->otherSolutionResults == NULL) return false;
    if (optimization->solution[solIdx]->otherSolutionResults->otherSolutionResult[otherIdx] == NULL) return false;
    if (optimization->solution[solIdx]->otherSolutionResults->otherSolutionResult[otherIdx]->item == NULL) return false;
    optimization->solution[solIdx]->otherSolutionResults->otherSolutionResult[otherIdx]->item[itemIdx] = item;
    return true;
}//setOtherSolutionResultItem

//----------------- start hard-hat area
//#if 0

bool OSResult::setAnOtherSolutionResult(int solIdx, std::string name, std::string value, 
	std::string category, std::string description, int numberOfItems, std::string* item)
{
    if (name == "") return false;
    int inumberOfItems = numberOfItems;
    if(inumberOfItems <= -1) return false;
    int nSols = this->getSolutionNumber();
    if(nSols <= 0) return false;
    if(optimization == NULL) return false;
    if(optimization->solution == NULL ||
            solIdx < 0 || solIdx >=  nSols) return false;
    if(optimization->solution[solIdx] == NULL) return false;

    try
    {
        if (optimization->solution[solIdx]->otherSolutionResults == NULL) 
            optimization->solution[solIdx]->otherSolutionResults = new OtherSolutionResults();

        int nres = optimization->solution[solIdx]->otherSolutionResults->numberOfOtherSolutionResults;
        int i;

        OtherSolutionResult** temp = new OtherSolutionResult*[nres+1];  //Allocate the new pointers
        for (i = 0; i < nres; i++)
            temp[i] = optimization->solution[solIdx]->otherSolutionResults->otherSolutionResult[i];  //copy the pointers

        delete[] optimization->solution[solIdx]->otherSolutionResults->otherSolutionResult; //delete old pointers

//	add in the new element
        temp[ nres] = new OtherSolutionResult();


        temp[ nres]->name = name;
        temp[ nres]->value = value;
        temp[ nres]->category = category;
        temp[ nres]->description = description;
        temp[ nres]->numberOfItems = numberOfItems;

        // if there was an item array, we do a hard copy
        if (item != NULL)
        {
            temp[nres]->item = new std::string[numberOfItems];
            for (i=0; i<numberOfItems; i++)
                temp[nres]->item[i] = item[i];
        }

    //hook the new pointers into the data structure
        optimization->solution[solIdx]->otherSolutionResults->otherSolutionResult = temp;   
        optimization->solution[solIdx]->otherSolutionResults->numberOfOtherSolutionResults = ++nres;

        return true;
    }
    catch(const ErrorClass& eclass)
    {
        osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_error, eclass.errormsg);
        return false;
    }
}//setAnOtherSolutionResult


//#endif
//+++++++++++++++++ end hard-hat area

bool OSResult::setNumberOfSolverOutputs(int num)
{
    if (optimization == NULL) return false;
    if (optimization->otherSolverOutput == NULL)
    {
        optimization->otherSolverOutput = new OtherSolverOutput();
    }
    if (num < 0) return false;
    if (optimization->otherSolverOutput->solverOutput != NULL) return false;
    optimization->otherSolverOutput->numberOfSolverOutputs = num;
    if (num > 0)
    {
        optimization->otherSolverOutput->solverOutput = new SolverOutput*[num];
        for(int i = 0; i < num; i++)
        {
            optimization->otherSolverOutput->solverOutput[ i]  = new SolverOutput();
        }
    }
    return true;
}//setNumberOfSolverOutputs

bool OSResult::setSolverOutputName(int otherIdx, std::string name)
{
    if (optimization == NULL) return false;
    if (optimization->otherSolverOutput == NULL) return false;
    if (optimization->otherSolverOutput->solverOutput[otherIdx] == NULL) return false;
    optimization->otherSolverOutput->solverOutput[otherIdx]->name = name;
    return true;
}//setSolverOutputName

bool OSResult::setSolverOutputCategory(int otherIdx, std::string category)
{
    if (optimization == NULL) return false;
    if (optimization->otherSolverOutput == NULL) return false;
    if (optimization->otherSolverOutput->solverOutput[otherIdx] == NULL) return false;
    optimization->otherSolverOutput->solverOutput[otherIdx]->category = category;
    return true;
}//setSolverOutputCategory

bool OSResult::setSolverOutputDescription(int otherIdx, std::string description)
{
    if (optimization == NULL) return false;
    if (optimization->otherSolverOutput == NULL) return false;
    if (optimization->otherSolverOutput->solverOutput[otherIdx] == NULL) return false;
    optimization->otherSolverOutput->solverOutput[otherIdx]->description = description;
    return true;
}//setSolverOutputDescription

bool OSResult::setSolverOutputNumberOfItems(int otherIdx, int numberOfItems)
{
    if (optimization == NULL) return false;
    if (optimization->otherSolverOutput == NULL) return false;
    if (optimization->otherSolverOutput->solverOutput[otherIdx] == NULL)
        optimization->otherSolverOutput->solverOutput[otherIdx] = new SolverOutput();
    if (numberOfItems < 0) return false;
    if (optimization->otherSolverOutput->solverOutput[otherIdx]->item != NULL) return false;
    optimization->otherSolverOutput->solverOutput[otherIdx]->numberOfItems = numberOfItems;
    if (numberOfItems > 0)
        optimization->otherSolverOutput->solverOutput[otherIdx]->item = new std::string[numberOfItems];
    return true;
}//setSolverOutputNumberOfItems

bool OSResult::setSolverOutputItem(int otherIdx, int itemIdx, std::string item)
{
    if (optimization == NULL) return false;
    if (optimization->otherSolverOutput == NULL) return false;
    if (optimization->otherSolverOutput->solverOutput == NULL) return false;
    if (optimization->otherSolverOutput->solverOutput[otherIdx] == NULL) return false;
    if (optimization->otherSolverOutput->solverOutput[otherIdx]->item == NULL) return false;
    optimization->otherSolverOutput->solverOutput[otherIdx]->item[itemIdx] = item;
    return true;
}//setSolverOutputItem



/***************************************************
 * methods to test whether two OSResult objects
 * or their components are equal to each other
 ***************************************************/
bool OSResult::IsEqual(OSResult *that)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSResult, ENUM_OUTPUT_LEVEL_trace, "Start comparing in OSResult");
#endif
    if (that == NULL)
    {
#ifndef NDEBUG
        osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_debug, 
            "Second object is NULL, first is not");
#endif
        return false;
    }
    else
    {
        if (this->general == NULL)
        {
            if (that->general != NULL)
                return false;
        }
        else
            if (!this->general->IsEqual(that->general))
                return false;

        if (this->system == NULL)
        {
            if (that->system != NULL)
                return false;
        }
        else
            if (!this->system->IsEqual(that->system))
                return false;

        if (this->service == NULL)
        {
            if (that->service != NULL)
                return false;
        }
        else
            if (!this->service->IsEqual(that->service))
                return false;

        if (this->job == NULL)
        {
            if (that->job != NULL)
                return false;
        }
        else
            if (!this->job->IsEqual(that->job))
                return false;

        if (this->optimization == NULL)
        {
            if (that->optimization != NULL)
                return false;
        }
        else
            if (!this->optimization->IsEqual(that->optimization))
                return false;
    }

    return true;
}//OSResult::IsEqual

bool GeneralResult::IsEqual(GeneralResult *that)
{
    std::ostringstream outStr;

#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSResult, ENUM_OUTPUT_LEVEL_trace, "Start comparing in GeneralResult");
#endif
    if (that == NULL)
    {
#ifndef NDEBUG
        osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_debug, 
            "Second object is NULL, first is not");
#endif
        return false;
    }
    else
    {
        if (this->message       != that->message       ||
            this->serviceURI    != that->serviceURI    ||
            this->serviceName   != that->serviceName   ||
            this->instanceName  != that->instanceName  ||
            this->jobID         != that->jobID         ||
            this->solverInvoked != that->solverInvoked ||
            this->timeStamp     != that->timeStamp )
        {
#ifndef NDEBUG
            outStr.str("");
            outStr.clear();
            outStr << "Differences in GeneralResult" << endl;
            outStr << "message:       " << this->message       << " vs. " << that->message       << endl;
            outStr << "serviceURI:    " << this->serviceURI    << " vs. " << that->serviceURI    << endl;
            outStr << "serviceName:   " << this->serviceName   << " vs. " << that->serviceName   << endl;
            outStr << "instanceName:  " << this->instanceName  << " vs. " << that->instanceName  << endl;
            outStr << "jobID:         " << this->jobID         << " vs. " << that->jobID         << endl;
            outStr << "solverInvoked: " << this->solverInvoked << " vs. " << that->solverInvoked << endl;
            outStr << "timeStamp:     " << this->timeStamp     << " vs. " << that->timeStamp     << endl;
            osoutput->OSPrint(ENUM_OUTPUT_AREA_OSResult, ENUM_OUTPUT_LEVEL_debug, outStr.str());
#endif
            return false;
       }

        if (this->generalStatus == NULL)
        {
            if (that->generalStatus != NULL)
                return false;
        }
        else
            if (!this->generalStatus->IsEqual(that->generalStatus))
                return false;

        if (this->otherResults == NULL)
        {
            if (that->otherResults != NULL)
                return false;
        }
        else
            if (!this->otherResults->IsEqual(that->otherResults))
                return false;
    }

    return true;
}//GeneralResult::IsEqual


bool GeneralStatus::IsEqual(GeneralStatus *that)
{
    std::ostringstream outStr;

#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSResult, ENUM_OUTPUT_LEVEL_trace, "Start comparing in GeneralStatus");
#endif
    if (that == NULL)
    {
#ifndef NDEBUG
        osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_debug, 
            "Second object is NULL, first is not");
#endif
        return false;
    }
    else
    {
        if (this->numberOfSubstatuses != that->numberOfSubstatuses ||
            this->type                != that->type                ||
            this->description         != that->description  )
        {
#ifndef NDEBUG
            outStr.str("");
            outStr.clear();
            outStr << "Differences in GeneralStatus" << endl;
            outStr << "numberOfSubstatuses: " << this->numberOfSubstatuses << " vs. " << that->numberOfSubstatuses << endl;
            outStr << "type:                " << this->type                << " vs. " << that->type                << endl;
            outStr << "description:         " << this->description         << " vs. " << that->description         << endl;
            osoutput->OSPrint(ENUM_OUTPUT_AREA_OSResult, ENUM_OUTPUT_LEVEL_debug, outStr.str());
#endif
            return false;
        }

        for (unsigned int i = 0; i < this->numberOfSubstatuses; i++)
        {
            if (this->substatus[i] == NULL)
            {
                if (that->substatus[i] != NULL)
                    return false;
            }
            else
                if (!this->substatus[i]->IsEqual(that->substatus[i]))
                    return false;
        }
    }

    return true;
}//GeneralStatus::IsEqual

bool GeneralSubstatus::IsEqual(GeneralSubstatus *that)
{
    std::ostringstream outStr;

#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSResult, ENUM_OUTPUT_LEVEL_trace, "Start comparing in GeneralSubstatus");
#endif
    if (that == NULL)
    {
#ifndef NDEBUG
        osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_debug, 
            "Second object is NULL, first is not");
#endif
        return false;
    }
    else
    {
        if (this->name        != that->name          ||
            this->description != that->description  )
        {
#ifndef NDEBUG
            outStr.str("");
            outStr.clear();
            outStr << "Differences in GeneralSubstatus" << endl;
            outStr << "name:        " << this->name        << " vs. " << that->name        << endl;
            outStr << "description: " << this->description << " vs. " << that->description << endl;
            osoutput->OSPrint(ENUM_OUTPUT_AREA_OSResult, ENUM_OUTPUT_LEVEL_debug, outStr.str());
#endif
            return false;
        }
    }

    return true;
}//GeneralSubstatus::IsEqual


bool OtherResults::IsEqual(OtherResults *that)
{
    std::ostringstream outStr;

#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSResult, ENUM_OUTPUT_LEVEL_trace, "Start comparing in OtherResults");
#endif
    if (that == NULL)
    {
#ifndef NDEBUG
        osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_debug, 
            "Second object is NULL, first is not");
#endif
        return false;
    }
    else
    {
        if (this->numberOfOtherResults != that->numberOfOtherResults)
        {
#ifndef NDEBUG
            outStr.str("");
            outStr.clear();
            outStr << "Differences in OtherResults" << endl;
            outStr << "numberOfOtherResults: " << this->numberOfOtherResults << " vs. " << that->numberOfOtherResults << endl;
            osoutput->OSPrint(ENUM_OUTPUT_AREA_OSResult, ENUM_OUTPUT_LEVEL_debug, outStr.str());
#endif
            return false;
        }

        for (unsigned int i = 0; i < this->numberOfOtherResults; i++)
        {
            if (this->other[i] == NULL)
            {
                if (that->other[i] != NULL)
                    return false;
            }
            else
                if (!this->other[i]->IsEqual(that->other[i]))
                    return false;
        }
    }

    return true;
}//OtherResults::IsEqual

#if 0
bool OtherResult::IsEqual(OtherResult *that)
{
    std::ostringstream outStr;

#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSResult, ENUM_OUTPUT_LEVEL_trace, "Start comparing in OtherResult");
#endif
    if (this == NULL)
    {
        if (that == NULL)
            return true;
        else
        {
#ifndef NDEBUG
            osoutput->OSPrint(ENUM_OUTPUT_AREA_OSResult, ENUM_OUTPUT_LEVEL_debug, "Differences in OtherResult");
            osoutput->OSPrint(ENUM_OUTPUT_AREA_OSResult, ENUM_OUTPUT_LEVEL_debug, "First object is NULL, second is not");
#endif
            return false;
        }
    }
    else
    {
        if (that == NULL)
        {
#ifndef NDEBUG
            osoutput->OSPrint(ENUM_OUTPUT_AREA_OSResult, ENUM_OUTPUT_LEVEL_debug, "Differences in OtherResult");
            osoutput->OSPrint(ENUM_OUTPUT_AREA_OSResult, ENUM_OUTPUT_LEVEL_debug, "Second object is NULL, first is not");
#endif
            return false;
        }
        else
        {
            if (this->name        != that->name          ||
                    this->value       != that->value         ||
                    this->description != that->description  )
            {
#ifndef NDEBUG
                outStr.str("");
                outStr.clear();
                outStr << "Differences in OtherResult" << endl;
                outStr << "name:        " << this->name        << " vs. " << that->name        << endl;
                outStr << "value:       " << this->value       << " vs. " << that->value       << endl;
                outStr << "description: " << this->description << " vs. " << that->description << endl;
                osoutput->OSPrint(ENUM_OUTPUT_AREA_OSResult, ENUM_OUTPUT_LEVEL_debug, outStr.str());
#endif
                return false;
            }
            return true;
        }
    }
}//OtherResult::IsEqual
#endif

bool SystemResult::IsEqual(SystemResult *that)
{
    std::ostringstream outStr;

#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSResult, ENUM_OUTPUT_LEVEL_trace, "Start comparing in SystemResult");
#endif
    if (that == NULL)
    {
#ifndef NDEBUG
        osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_debug, 
            "Second object is NULL, first is not");
#endif
        return false;
    }
    else
    {
        if (this->systemInformation != that->systemInformation)
        {
#ifndef NDEBUG
            outStr.str("");
            outStr.clear();
            outStr << "Differences in SystemResult" << endl;
            outStr << "systemInformation: " << this->systemInformation << " vs. " << that->systemInformation << endl;
            osoutput->OSPrint(ENUM_OUTPUT_AREA_OSResult, ENUM_OUTPUT_LEVEL_debug, outStr.str());
#endif
            return false;
        }

        if (this->availableDiskSpace == NULL)
        {
            if (that->availableDiskSpace != NULL)
                return false;
        }
        else
            if (!this->availableDiskSpace->IsEqual(that->availableDiskSpace))
                return false;

        if (this->availableMemory == NULL)
        {
            if (that->availableMemory != NULL)
                return false;
        }
        else
            if (!this->availableMemory->IsEqual(that->availableMemory))
                return false;

        if (this->availableCPUSpeed == NULL)
        {
            if (that->availableCPUSpeed != NULL)
                return false;
        }
        else
            if (!this->availableCPUSpeed->IsEqual(that->availableCPUSpeed))
                return false;

        if (this->availableCPUNumber == NULL)
        {
            if (that->availableCPUNumber != NULL)
                return false;
        }
        else
            if (!this->availableCPUNumber->IsEqual(that->availableCPUNumber))
                return false;

        if (this->otherResults == NULL)
        {
            if (that->otherResults != NULL)
                return false;
        }
        else
            if (!this->otherResults->IsEqual(that->otherResults))
                return false;
    }

    return true;
}//SystemResult::IsEqual



bool ServiceResult::IsEqual(ServiceResult *that)
{
    std::ostringstream outStr;

#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSResult, ENUM_OUTPUT_LEVEL_trace, "Start comparing in ServiceResult");
#endif
    if (that == NULL)
    {
#ifndef NDEBUG
        osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_debug, 
            "Second object is NULL, first is not");
#endif
        return false;
    }
    else
    {
        if (this->currentState       != that->currentState ||
            this->currentJobCount    != that->currentJobCount ||
            this->totalJobsSoFar     != that->totalJobsSoFar  ||
            this->timeServiceStarted != that->timeServiceStarted ||
            !OSIsEqual(this->serviceUtilization, that->serviceUtilization) )
        {
#ifndef NDEBUG
            outStr.str("");
            outStr.clear();
            outStr << "Differences in ServiceResult" << endl;
            outStr << "currentState:       " << this->currentState       << " vs. " << that->currentState       << endl;
            outStr << "currentJobCount:    " << this->currentJobCount    << " vs. " << that->currentJobCount    << endl;
            outStr << "totalJobsSoFar:     " << this->totalJobsSoFar     << " vs. " << that->totalJobsSoFar     << endl;
            outStr << "timeServiceStarted: " << this->timeServiceStarted << " vs. " << that->timeServiceStarted << endl;
            outStr << "serviceUtilization: " << this->serviceUtilization << " vs. " << that->serviceUtilization << endl;
            osoutput->OSPrint(ENUM_OUTPUT_AREA_OSResult, ENUM_OUTPUT_LEVEL_debug, outStr.str());
#endif
            return false;
        }

        if (this->otherResults == NULL)
        {
            if (that->otherResults != NULL)
                return false;
        }
        else

            if (!this->otherResults->IsEqual(that->otherResults))
                return false;
    }
    
    return true;
}//ServiceResult::IsEqual


bool JobResult::IsEqual(JobResult *that)
{
    std::ostringstream outStr;

#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSResult, ENUM_OUTPUT_LEVEL_trace, "Start comparing in JobResult");
#endif
    if (that == NULL)
    {
#ifndef NDEBUG
        osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_debug, 
            "Second object is NULL, first is not");
#endif
        return false;
    }
    else
    {
        if (this->status             != that->status             ||
            this->submitTime         != that->submitTime         ||
            this->scheduledStartTime != that->scheduledStartTime ||
            this->actualStartTime    != that->actualStartTime    ||
            this->endTime            != that->endTime          )
        {
#ifndef NDEBUG
            outStr.str("");
            outStr.clear();
            outStr << "Differences in JobResult" << endl;
            outStr << "status:             " << this->status             << " vs. " << that->status             << endl;
            outStr << "submitTime:         " << this->submitTime         << " vs. " << that->submitTime         << endl;
            outStr << "scheduledStartTime: " << this->scheduledStartTime << " vs. " << that->scheduledStartTime << endl;
            outStr << "actualStartTime:    " << this->actualStartTime    << " vs. " << that->actualStartTime    << endl;
            outStr << "endTime:            " << this->endTime            << " vs. " << that->endTime            << endl;
            osoutput->OSPrint(ENUM_OUTPUT_AREA_OSResult, ENUM_OUTPUT_LEVEL_debug, outStr.str());
#endif
            return false;
        }

        if (this->timingInformation == NULL)
        {
            if (that->timingInformation != NULL)
                return false;
        }
        else
            if (!this->timingInformation->IsEqual(that->timingInformation))
                return false;

        if (this->usedDiskSpace == NULL)
        {
            if (that->usedDiskSpace != NULL)
                return false;
        }
        else
            if (!this->usedDiskSpace->IsEqual(that->usedDiskSpace))
                return false;

        if (this->usedMemory == NULL)
        {
            if (that->usedMemory != NULL)
                return false;
        }
        else
            if (!this->usedMemory->IsEqual(that->usedMemory))
                return false;

        if (this->usedCPUSpeed == NULL)
        {
            if (that->usedCPUSpeed != NULL)
                return false;
        }
        else
            if (!this->usedCPUSpeed->IsEqual(that->usedCPUSpeed))
                return false;

        if (this->usedCPUNumber == NULL)
        {
            if (that->usedCPUNumber != NULL)
                return false;
        }
        else
            if (!this->usedCPUNumber->IsEqual(that->usedCPUNumber))
                return false;

        if (this->otherResults == NULL)
        {
            if (that->otherResults != NULL)
                return false;
        }
        else
            if (!this->otherResults->IsEqual(that->otherResults))
                return false;
    }

    return true;
}//JobResult::IsEqual


bool TimingInformation::IsEqual(TimingInformation *that)
{
    std::ostringstream outStr;

#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSResult, ENUM_OUTPUT_LEVEL_trace, "Start comparing in TimingInformation");
#endif
    if (that == NULL)
    {
#ifndef NDEBUG
        osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_debug, 
            "Second object is NULL, first is not");
#endif
        return false;
    }
    else
    {

        if (this->numberOfTimes != that->numberOfTimes)
        {
#ifndef NDEBUG
            outStr.str("");
            outStr.clear();
            outStr << "Differences in TimingInformation" << endl;
            outStr << "numberOfTimes: " << this->numberOfTimes << " vs. " << that->numberOfTimes << endl;
            osoutput->OSPrint(ENUM_OUTPUT_AREA_OSResult, ENUM_OUTPUT_LEVEL_debug, outStr.str());
#endif
            return false;
        }

        for (unsigned int i = 0; i < this->numberOfTimes; i++)
        {
            if (this->time[i] == NULL)
            {
                if (that->time[i] != NULL)
                    return false;
            }
            else
                if (!this->time[i]->IsEqual(that->time[i]))
                    return false;
        }
    }

    return true;
}//TimingInformation::IsEqual


bool TimeMeasurement::IsEqual(TimeMeasurement *that)
{
    std::ostringstream outStr;

#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSResult, ENUM_OUTPUT_LEVEL_trace, "Start comparing in TimeMeasurement");
#endif
    if (that == NULL)
    {
#ifndef NDEBUG
        osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_debug, 
            "Second object is NULL, first is not");
#endif
        return false;
    }
    else
    {
        if (this->type        != that->type      ||
            this->category    != that->category  ||
            this->description != that->description  )
        {
#ifndef NDEBUG
            outStr.str("");
            outStr.clear();
            outStr << "Differences in TimeMeasurement" << endl;
            outStr << "type:        " << this->type        << " vs. " << that->type        << endl;
            outStr << "category:    " << this->category    << " vs. " << that->category    << endl;
            outStr << "description: " << this->description << " vs. " << that->description << endl;
            osoutput->OSPrint(ENUM_OUTPUT_AREA_OSResult, ENUM_OUTPUT_LEVEL_debug, outStr.str());
#endif
            return false;
        }

        return this->TimeSpan::IsEqual(that);
    }

    return true;
}//TimeMeasurement::IsEqual


bool OptimizationResult::IsEqual(OptimizationResult *that)
{
    std::ostringstream outStr;

#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSResult, ENUM_OUTPUT_LEVEL_trace, "Start comparing in OptimizationResult");
#endif
    if (that == NULL)
    {
#ifndef NDEBUG
        osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_debug, 
            "Second object is NULL, first is not");
#endif
        return false;
    }
    else
    {
        if (this->numberOfSolutions   != that->numberOfSolutions   ||
            this->numberOfVariables   != that->numberOfVariables   ||
            this->numberOfObjectives  != that->numberOfObjectives  ||
            this->numberOfConstraints != that->numberOfConstraints  )
        {
#ifndef NDEBUG
            outStr.str("");
            outStr.clear();
            outStr << "Differences in OptimizationResult" << endl;
            outStr << "numberOfSolutions:   " << this->numberOfSolutions   << " vs. " << that->numberOfSolutions   << endl;
            outStr << "numberOfVariables:   " << this->numberOfVariables   << " vs. " << that->numberOfVariables   << endl;
            outStr << "numberOfObjectives:  " << this->numberOfObjectives  << " vs. " << that->numberOfObjectives  << endl;
            outStr << "numberOfConstraints: " << this->numberOfConstraints << " vs. " << that->numberOfConstraints << endl;
            osoutput->OSPrint(ENUM_OUTPUT_AREA_OSResult, ENUM_OUTPUT_LEVEL_debug, outStr.str());
#endif
            return false;
        }

        for (unsigned int i = 0; i < this->numberOfSolutions; i++)
        {
            if (this->solution[i] == NULL)
            {
                if (that->solution[i] != NULL)
                    return false;
            }
            else
                if (!this->solution[i]->IsEqual(that->solution[i]))
                    return false;
        }

        if (this->otherSolverOutput == NULL)
        {
            if (that->otherSolverOutput != NULL)
                return false;
        }
        else
            if (!this->otherSolverOutput->IsEqual(that->otherSolverOutput))
                return false;
    }

    return true;
}//OptimizationResult::IsEqual


bool OptimizationSolution::IsEqual(OptimizationSolution  *that)
{
    std::ostringstream outStr;

#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSResult, ENUM_OUTPUT_LEVEL_trace, "Start comparing in OptimizationSolution");
#endif
    if (that == NULL)
    {
#ifndef NDEBUG
        osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_debug, 
            "Second object is NULL, first is not");
#endif
        return false;
    }
    else
    {
        if (this->targetObjectiveIdx != that->targetObjectiveIdx)
        {
#ifndef NDEBUG
            outStr.str("");
            outStr.clear();
            outStr << "Differences in OptimizationSolution" << endl;
            outStr << "targetObjectiveIdx: " << this->targetObjectiveIdx << " vs. " << that->targetObjectiveIdx << endl;
            osoutput->OSPrint(ENUM_OUTPUT_AREA_OSResult, ENUM_OUTPUT_LEVEL_debug, outStr.str());
#endif
            return false;
        }

        if (this->targetObjectiveName != that->targetObjectiveName)
        {
#ifndef NDEBUG
            outStr.str("");
            outStr.clear();
            outStr << "Differences in OptimizationSolution" << endl;
            outStr << "targetObjectiveName: " << this->targetObjectiveName << " vs. " << that->targetObjectiveName << endl;
            osoutput->OSPrint(ENUM_OUTPUT_AREA_OSResult, ENUM_OUTPUT_LEVEL_debug, outStr.str());
#endif
            return false;
        }

        if (this->weightedObjectives != that->weightedObjectives)
        {
#ifndef NDEBUG
            outStr.str("");
            outStr.clear();
            outStr << "Differences in OptimizationSolution" << endl;
            outStr << "weightedObjectives: " << this->weightedObjectives << " vs. " << that->weightedObjectives << endl;
            osoutput->OSPrint(ENUM_OUTPUT_AREA_OSResult, ENUM_OUTPUT_LEVEL_debug, outStr.str());
#endif
            return false;
        }

        if (this->message != that->message)
        {
#ifndef NDEBUG
            outStr.str("");
            outStr.clear();
            outStr << "Differences in OptimizationSolution" << endl;
            outStr << "message: \'" << this->message << "\' vs. \'" << that->message << "\'" << endl;
            osoutput->OSPrint(ENUM_OUTPUT_AREA_OSResult, ENUM_OUTPUT_LEVEL_debug, outStr.str());
#endif
            return false;
        }

        if (this->status == NULL)
        {
            if (that->status != NULL)
                return false;
        }
        else
            if (!this->status->IsEqual(that->status))
                return false;

        if (this->variables == NULL)
        {
            if (that->variables != NULL)
                return false;
        }
        else
            if (!this->variables->IsEqual(that->variables))
                return false;

        if (this->objectives == NULL)
        {
            if (that->objectives != NULL)
                return false;
        }
        else
            if (!this->objectives->IsEqual(that->objectives))
                return false;

        if (this->constraints == NULL)
        {
            if (that->constraints != NULL)
                return false;
        }
        else
            if (!this->constraints->IsEqual(that->constraints))
                return false;

        if (this->otherSolutionResults == NULL)
        {
            if (that->otherSolutionResults != NULL)
                return false;
        }
        else
            if (!this->otherSolutionResults->IsEqual(that->otherSolutionResults))
                return false;
    }

    return true;
}//OptimizationSolution ::IsEqual


bool OptimizationSolutionStatus::IsEqual(OptimizationSolutionStatus *that)
{
    std::ostringstream outStr;

#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSResult, ENUM_OUTPUT_LEVEL_trace, "Start comparing in OptimizationSolutionStatus");
#endif
    if (that == NULL)
    {
#ifndef NDEBUG
        osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_debug, 
            "Second object is NULL, first is not");
#endif
        return false;
    }
    else
    {
        if (this->type        != that->type          ||
            this->description != that->description  )
        {
#ifndef NDEBUG
            outStr.str("");
            outStr.clear();
            outStr << "Differences in OptimizationSolutionStatus" << endl;
            outStr << "type:        " << this->type        << " vs. " << that->type        << endl;
            outStr << "description: " << this->description << " vs. " << that->description << endl;
            osoutput->OSPrint(ENUM_OUTPUT_AREA_OSResult, ENUM_OUTPUT_LEVEL_debug, outStr.str());
#endif
            return false;
        }

        if (this->numberOfSubstatuses != that->numberOfSubstatuses)
        {
#ifndef NDEBUG
            outStr.str("");
            outStr.clear();
            outStr << "Differences in OptimizationSolutionStatus" << endl;
            outStr << "numberOfSubstatuses: " << this->numberOfSubstatuses << " vs. " << that->numberOfSubstatuses << endl;
            osoutput->OSPrint(ENUM_OUTPUT_AREA_OSResult, ENUM_OUTPUT_LEVEL_debug, outStr.str());
#endif
            return false;
       }

        for (unsigned int i = 0; i < this->numberOfSubstatuses; i++)
        {
            if (this->substatus[i] == NULL)
            {
                if (that->substatus[i] != NULL)
                    return false;
            }
            else
                if (!this->substatus[i]->IsEqual(that->substatus[i]))
                    return false;
        }
    }

    return true;
}//OptimizationSolutionStatus::IsEqual


bool OptimizationSolutionSubstatus::IsEqual(OptimizationSolutionSubstatus *that)
{
    std::ostringstream outStr;

#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSResult, ENUM_OUTPUT_LEVEL_trace, "Start comparing in OptimizationSolutionSubstatus");
#endif
    if (that == NULL)
    {
#ifndef NDEBUG
        osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_debug, 
            "Second object is NULL, first is not");
#endif
        return false;
    }
    else
    {
        if (this->type        != that->type          ||
            this->description != that->description  )
        {
#ifndef NDEBUG
            outStr.str("");
            outStr.clear();
            outStr << "Differences in OptimizationSolutionSubstatus" << endl;
            outStr << "type:        " << this->type        << " vs. " << that->type        << endl;
            outStr << "description: " << this->description << " vs. " << that->description << endl;
            osoutput->OSPrint(ENUM_OUTPUT_AREA_OSResult, ENUM_OUTPUT_LEVEL_debug, outStr.str());
#endif
            return false;
        }
    }

    return true;
}//OptimizationSolutionSubstatus::IsEqual


bool VariableSolution::IsEqual(VariableSolution *that)
{
    std::ostringstream outStr;

#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSResult, ENUM_OUTPUT_LEVEL_trace, "Start comparing in VariableSolution");
#endif
    if (that == NULL)
    {
#ifndef NDEBUG
        osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_debug, 
            "Second object is NULL, first is not");
#endif
        return false;
    }
    else
    {
        if (this->numberOfOtherVariableResults != that->numberOfOtherVariableResults)
        {
#ifndef NDEBUG
            outStr.str("");
            outStr.clear();
            outStr << "Differences in VariableSolution" << endl;
            outStr << "numberOfOtherVariableResults: " << this->numberOfOtherVariableResults << " vs. " << that->numberOfOtherVariableResults << endl;
            osoutput->OSPrint(ENUM_OUTPUT_AREA_OSResult, ENUM_OUTPUT_LEVEL_debug, outStr.str());
#endif
            return false;
        }

        for (unsigned int i = 0; i < this->numberOfOtherVariableResults; i++)
        {
            if (this->other[i] == NULL)
            {
                if (that->other[i] != NULL)
                    return false;
            }
            else
                if (!this->other[i]->IsEqual(that->other[i]))
                    return false;
        }


        if (this->values == NULL)
        {
            if (that->values != NULL)
                return false;
        }
        else
            if (!this->values->IsEqual(that->values))
                return false;

        if (this->valuesString == NULL)
        {
            if (that->valuesString != NULL)
                return false;
        }
        else
            if (!this->valuesString->IsEqual(that->valuesString))
                return false;

        if (this->basisStatus == NULL)
        {
            if (that->basisStatus != NULL)
                return false;
        }
        else
            if (!this->basisStatus->IsEqual(that->basisStatus))
                return false;
    }

    return true;
}//VariableSolution::IsEqual


bool VariableValues::IsEqual(VariableValues *that)
{
    std::ostringstream outStr;

#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSResult, ENUM_OUTPUT_LEVEL_trace, "Start comparing in VariableValues");
#endif
    if (that == NULL)
    {
#ifndef NDEBUG
        osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_debug, 
            "Second object is NULL, first is not");
#endif
        return false;
    }
    else
    {
        if (this->numberOfVar != that->numberOfVar)
        {
#ifndef NDEBUG
            outStr.str("");
            outStr.clear();
            outStr << "Differences in VariableValues" << endl;
            outStr << "numberOfVar: " << this->numberOfVar << " vs. " << that->numberOfVar << endl;
            osoutput->OSPrint(ENUM_OUTPUT_AREA_OSResult, ENUM_OUTPUT_LEVEL_debug, outStr.str());
#endif
            return false;
        }

        for (unsigned int i = 0; i < this->numberOfVar; i++)
        {
            if (this->var[i] == NULL)
            {
                if (that->var[i] != NULL)
                    return false;
            }
            else
                if (!this->var[i]->IsEqual(that->var[i]))
                    return false;
        }
    }

    return true;
}//VariableValues::IsEqual


bool VarValue::IsEqual(VarValue *that)
{
    std::ostringstream outStr;

#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSResult, ENUM_OUTPUT_LEVEL_trace, "Start comparing in VarValue");
#endif
    if (that == NULL)
    {
#ifndef NDEBUG
        osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_debug, 
            "Second object is NULL, first is not");
#endif
        return false;
    }
    else
    {
        if (this->idx != that->idx || this->name != that->name ||
            !OSIsEqual(this->value, that->value) )
        {
#ifndef NDEBUG
            outStr.str("");
            outStr.clear();
            outStr << "Differences in VarValue" << endl;
            outStr << "idx:   " << this->idx   <<  " vs.  " << that->idx   << endl;
            outStr << "name: -" << this->name  << "- vs. -" << that->name  << "-" << endl;
            outStr << "value: " << this->value <<  " vs.  " << that->value << endl;
            osoutput->OSPrint(ENUM_OUTPUT_AREA_OSResult, ENUM_OUTPUT_LEVEL_debug, outStr.str());
#endif
            return false;
        }
    }

   return true;
}//VarValue::IsEqual


bool VariableValuesString::IsEqual(VariableValuesString *that)
{
    std::ostringstream outStr;

#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSResult, ENUM_OUTPUT_LEVEL_trace, "Start comparing in VariableValuesString");
#endif
    if (that == NULL)
    {
#ifndef NDEBUG
        osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_debug, 
            "Second object is NULL, first is not");
#endif
        return false;
    }
    else
    {
        if (this->numberOfVar != that->numberOfVar)
        {
#ifndef NDEBUG
            outStr.str("");
            outStr.clear();
            outStr << "Differences in VariableValuesString" << endl;
            outStr << "numberOfVar: " << this->numberOfVar << " vs. " << that->numberOfVar << endl;
            osoutput->OSPrint(ENUM_OUTPUT_AREA_OSResult, ENUM_OUTPUT_LEVEL_debug, outStr.str());
#endif
            return false;
        }

        for (unsigned int i = 0; i < this->numberOfVar; i++)
        {
            if (this->var[i] == NULL)
            {
                if (that->var[i] != NULL)
                    return false;
            }
            else
                if (!this->var[i]->IsEqual(that->var[i]))
                    return false;
        }
    }

    return true;
}//VariableValuesString::IsEqual


bool VarValueString::IsEqual(VarValueString *that)
{
    std::ostringstream outStr;

#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSResult, ENUM_OUTPUT_LEVEL_trace, "Start comparing in VarValueString");
#endif
    if (that == NULL)
    {
#ifndef NDEBUG
        osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_debug, 
            "Second object is NULL, first is not");
#endif
        return false;
    }
    else
    {
        if (this->idx   != that->idx  || this->name != that->name ||
            this->value != that->value )
        {
#ifndef NDEBUG
            outStr.str("");
            outStr.clear();
            outStr << "Differences in VarValueString" << endl;
            outStr << "idx:   " << this->idx   <<  " vs. "  << that->idx   << endl;
            outStr << "name: -" << this->name  << "- vs. -" << that->name  << "-" << endl;
            outStr << "value: " << this->value <<  " vs. "  << that->value << endl;
            osoutput->OSPrint(ENUM_OUTPUT_AREA_OSResult, ENUM_OUTPUT_LEVEL_debug, outStr.str());
#endif
            return false;
        }
    }

    return true;
}//VarValueString::IsEqual


bool OtherVariableResult::IsEqual(OtherVariableResult *that)
{
    std::ostringstream outStr;

#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSResult, ENUM_OUTPUT_LEVEL_trace, "Start comparing in OtherVariableResult");
#endif
    if (that == NULL)
    {
#ifndef NDEBUG
        osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_debug, 
            "Second object is NULL, first is not");
#endif
        return false;
    }
    else
    {
        if (this->name        != that->name          ||
            this->value       != that->value         ||
            this->description != that->description  )
        {
#ifndef NDEBUG
            outStr.str("");
            outStr.clear();
            outStr << "Differences in OtherVariableResult" << endl;
            outStr << "name:        " << this->name        << " vs. " << that->name        << endl;
            outStr << "value:       " << this->value       << " vs. " << that->value       << endl;
            outStr << "description: " << this->description << " vs. " << that->description << endl;
            osoutput->OSPrint(ENUM_OUTPUT_AREA_OSResult, ENUM_OUTPUT_LEVEL_debug, outStr.str());
#endif
            return false;
        }

        if (this->numberOfVar != that->numberOfVar)
        {
#ifndef NDEBUG
            outStr.str("");
            outStr.clear();
            outStr << "numberOfVar: " << this->numberOfVar << " vs. " << that->numberOfVar << endl;
            osoutput->OSPrint(ENUM_OUTPUT_AREA_OSResult, ENUM_OUTPUT_LEVEL_debug, outStr.str());
#endif
            return false;
        }

        for (unsigned int i = 0; i < this->numberOfVar; i++)
        {
            if (this->var[i] == NULL)
            {
                if (that->var[i] != NULL)
                    return false;
            }
            else
                if (!this->var[i]->IsEqual(that->var[i]))
                    return false;
        }

        if (this->numberOfEnumerations != that->numberOfEnumerations)
        {
#ifndef NDEBUG
            outStr.str("");
            outStr.clear();
            outStr << "Differences in OtherVariableResult" << endl;
            outStr << "numberOfEnumerations: " << this->numberOfEnumerations << " vs. " << that->numberOfEnumerations << endl;
            osoutput->OSPrint(ENUM_OUTPUT_AREA_OSResult, ENUM_OUTPUT_LEVEL_debug, outStr.str());
#endif
            return false;
        }

        for (unsigned int i = 0; i < this->numberOfEnumerations; i++)
        {
            if (this->enumeration[i] == NULL)
            {
                if (that->enumeration[i] != NULL)
                    return false;
            }
            else
                if (!this->enumeration[i]->IsEqual(that->enumeration[i]))
                    return false;
        }
    }

    return true;
}//OtherVariableResult::IsEqual


bool OtherVarResult::IsEqual(OtherVarResult *that)
{
    std::ostringstream outStr;

#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSResult, ENUM_OUTPUT_LEVEL_trace, "Start comparing in OtherVarResult");
#endif
    if (that == NULL)
    {
#ifndef NDEBUG
        osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_debug, 
            "Second object is NULL, first is not");
#endif
        return false;
    }
    else
    {
        if (this->idx   != that->idx  || this->name != that->name ||
            this->value != that->value )
        {
#ifndef NDEBUG
            outStr.str("");
            outStr.clear();
            outStr << "Differences in OtherVarResult" << endl;
            outStr << "idx:   " << this->idx   <<  " vs. "  << that->idx   << endl;
            outStr << "name: -" << this->name  << "- vs. -" << that->name  << "-" << endl;
            outStr << "value: " << this->value <<  " vs. "  << that->value << endl;
            osoutput->OSPrint(ENUM_OUTPUT_AREA_OSResult, ENUM_OUTPUT_LEVEL_debug, outStr.str());
#endif
            return false;
        }
    }

    return true;
}//OtherVarResult::IsEqual


bool ObjectiveSolution::IsEqual(ObjectiveSolution *that)
{
    std::ostringstream outStr;

#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSResult, ENUM_OUTPUT_LEVEL_trace, "Start comparing in ObjectiveSolution");
#endif
    if (that == NULL)
    {
#ifndef NDEBUG
        osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_debug, 
            "Second object is NULL, first is not");
#endif
        return false;
    }
    else
    {
        if (this->numberOfOtherObjectiveResults != that->numberOfOtherObjectiveResults)
        {
#ifndef NDEBUG
            outStr.str("");
            outStr.clear();
            outStr << "Differences in ObjectiveSolution" << endl;
            outStr << "numberOfOtherObjectiveResults: " << this->numberOfOtherObjectiveResults << " vs. " << that->numberOfOtherObjectiveResults << endl;
            osoutput->OSPrint(ENUM_OUTPUT_AREA_OSResult, ENUM_OUTPUT_LEVEL_debug, outStr.str());
#endif
            return false;
        }

        for (unsigned int i = 0; i < this->numberOfOtherObjectiveResults; i++)
        {
            if (this->other[i] == NULL)
            {
                if (that->other[i] != NULL)
                    return false;
            }
            else
                if (!this->other[i]->IsEqual(that->other[i]))
                    return false;
        }

        if (this->values == NULL)
        {
            if (that->values != NULL)
                return false;
        }
        else
            if (!this->values->IsEqual(that->values))
                return false;

        if (this->basisStatus == NULL)
        {
            if (that->basisStatus != NULL)
                return false;
        }
        else
            if (!this->basisStatus->IsEqual(that->basisStatus))
                return false;
    }

    return true;
}//ObjectiveSolution::IsEqual


bool ObjectiveValues::IsEqual(ObjectiveValues *that)
{
    std::ostringstream outStr;

#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSResult, ENUM_OUTPUT_LEVEL_trace, "Start comparing in ObjectiveValues");
#endif
    if (that == NULL)
    {
#ifndef NDEBUG
        osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_debug, 
            "Second object is NULL, first is not");
#endif
        return false;
    }
    else
    {
        if (this->numberOfObj != that->numberOfObj)
        {
#ifndef NDEBUG
            outStr.str("");
            outStr.clear();
            outStr << "Differences in ObjectiveValues" << endl;
            outStr << "numberOfObj: " << this->numberOfObj << " vs. " << that->numberOfObj << endl;
            osoutput->OSPrint(ENUM_OUTPUT_AREA_OSResult, ENUM_OUTPUT_LEVEL_debug, outStr.str());
#endif
            return false;
        }

       for (unsigned int i = 0; i < this->numberOfObj; i++)
        {
            if (this->obj[i] == NULL)
            {
                if (that->obj[i] != NULL)
                    return false;
            }
            else
                if (!this->obj[i]->IsEqual(that->obj[i]))
                    return false;
        }
    }

    return true;
}//ObjectiveValues::IsEqual


bool ObjValue::IsEqual(ObjValue *that)
{
    std::ostringstream outStr;

#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSResult, ENUM_OUTPUT_LEVEL_trace, "Start comparing in ObjValue");
#endif
    if (that == NULL)
    {
#ifndef NDEBUG
        osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_debug, 
            "Second object is NULL, first is not");
#endif
        return false;
    }
    else
    {
        if (this->idx   != that->idx  || this->name != that->name ||
            this->value != that->value )
        {
#ifndef NDEBUG
            outStr.str("");
            outStr.clear();
            outStr << "Differences in ObjValue" << endl;
            outStr << "idx:   " << this->idx   <<  " vs. "  << that->idx   << endl;
            outStr << "name: -" << this->name  << "- vs. -" << that->name  << "-" << endl;
            outStr << "value: " << this->value <<  " vs. "  << that->value << endl;
            osoutput->OSPrint(ENUM_OUTPUT_AREA_OSResult, ENUM_OUTPUT_LEVEL_debug, outStr.str());
#endif
            return false;
        }
    }

    return true;
}//ObjValue::IsEqual


bool OtherObjectiveResult::IsEqual(OtherObjectiveResult *that)
{
    std::ostringstream outStr;

#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSResult, ENUM_OUTPUT_LEVEL_trace, "Start comparing in OtherObjectiveResult");
#endif
    if (that == NULL)
    {
#ifndef NDEBUG
        osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_debug, 
            "Second object is NULL, first is not");
#endif
        return false;
    }
    else
    {
        if (this->value       != that->value   ||
            this->name        != that->name    ||
            this->description != that->description  )
        {
#ifndef NDEBUG
            outStr.str("");
            outStr.clear();
            outStr << "Differences in OtherObjectiveResult" << endl;
            outStr << "name:        " << this->name        << " vs. " << that->name        << endl;
            outStr << "value:       " << this->value       << " vs. " << that->value       << endl;
            outStr << "description: " << this->description << " vs. " << that->description << endl;
            osoutput->OSPrint(ENUM_OUTPUT_AREA_OSResult, ENUM_OUTPUT_LEVEL_debug, outStr.str());
#endif
            return false;
        }

        if (this->numberOfObj != that->numberOfObj)
        {
#ifndef NDEBUG
            outStr.str("");
            outStr.clear();
            outStr << "Differences in OtherObjectiveResult" << endl;
            outStr << "numberOfObj: " << this->numberOfObj << " vs. " << that->numberOfObj << endl;
            osoutput->OSPrint(ENUM_OUTPUT_AREA_OSResult, ENUM_OUTPUT_LEVEL_debug, outStr.str());
#endif
            return false;
        }

        for (unsigned int i = 0; i < this->numberOfObj; i++)
        {
            if (this->obj[i] == NULL)
            {
                if (that->obj[i] != NULL)
                    return false;
            }
            else
                if (!this->obj[i]->IsEqual(that->obj[i]))
                    return false;
        }

        if (this->numberOfEnumerations != that->numberOfEnumerations)
        {
#ifndef NDEBUG
            outStr.str("");
            outStr.clear();
            outStr << "Differences in OtherObjectiveResult" << endl;
            outStr << "numberOfEnumerations: " << this->numberOfEnumerations << " vs. " << that->numberOfEnumerations << endl;
            osoutput->OSPrint(ENUM_OUTPUT_AREA_OSResult, ENUM_OUTPUT_LEVEL_debug, outStr.str());
#endif
            return false;
        }

        for (unsigned int i = 0; i < this->numberOfEnumerations; i++)
        {
            if (this->enumeration[i] == NULL)
            {
                if (that->enumeration[i] != NULL)
                    return false;
            }
            else
                if (!this->enumeration[i]->IsEqual(that->enumeration[i]))
                    return false;
        }
    }

    return true;
}//OtherObjectiveResult::IsEqual


bool OtherObjResult::IsEqual(OtherObjResult *that)
{
    std::ostringstream outStr;

#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSResult, ENUM_OUTPUT_LEVEL_trace, "Start comparing in OtherObjResult");
#endif
    if (that == NULL)
    {
#ifndef NDEBUG
        osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_debug, 
            "Second object is NULL, first is not");
#endif
        return false;
    }
    else
    {
        if (this->idx   != that->idx  || this->name != that->name ||
            this->value != that->value )
        {
#ifndef NDEBUG
            outStr.str("");
            outStr.clear();
            outStr << "Differences in OtherObjResult" << endl;
            outStr << "idx:   " << this->idx   <<  " vs. "  << that->idx   << endl;
            outStr << "name: -" << this->name  << "- vs. -" << that->name  << "-" << endl;
            outStr << "value: " << this->value <<  " vs. "  << that->value << endl;
            osoutput->OSPrint(ENUM_OUTPUT_AREA_OSResult, ENUM_OUTPUT_LEVEL_debug, outStr.str());
#endif
            return false;
        }
    }

    return true;
}//OtherObjResult::IsEqual


bool ConstraintSolution::IsEqual(ConstraintSolution *that)
{
    std::ostringstream outStr;

#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSResult, ENUM_OUTPUT_LEVEL_trace, "Start comparing in ConstraintSolution");
#endif
    if (that == NULL)
    {
#ifndef NDEBUG
        osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_debug, 
            "Second object is NULL, first is not");
#endif
        return false;
    }
    else
    {
        if (this->numberOfOtherConstraintResults != that->numberOfOtherConstraintResults)
        {
#ifndef NDEBUG
            outStr.str("");
            outStr.clear();
            outStr << "Differences in ConstraintSolution" << endl;
            outStr << "numberOfOtherConstraintResults: " << this->numberOfOtherConstraintResults << " vs. " << that->numberOfOtherConstraintResults << endl;
            osoutput->OSPrint(ENUM_OUTPUT_AREA_OSResult, ENUM_OUTPUT_LEVEL_debug, outStr.str());
#endif
            return false;
        }

        for (unsigned int i = 0; i < this->numberOfOtherConstraintResults; i++)
        {
            if (this->other[i] == NULL)
            {
                if (that->other[i] != NULL)
                    return false;
            }
            else
                if (!this->other[i]->IsEqual(that->other[i]))
                    return false;
        }
 
        if (this->dualValues == NULL)
        {
            if (that->dualValues != NULL)
                return false;
        }
        else
            if (!this->dualValues->IsEqual(that->dualValues))
                return false;

        if (this->basisStatus == NULL)
        {
            if (that->basisStatus != NULL)
                return false;
        }
        else
            if (!this->basisStatus->IsEqual(that->basisStatus))
                return false;
    }

    return true;
}//ConstraintSolution::IsEqual


bool DualVariableValues::IsEqual(DualVariableValues *that)
{
    std::ostringstream outStr;

#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSResult, ENUM_OUTPUT_LEVEL_trace, "Start comparing in DualVariableValues");
#endif
    if (that == NULL)
    {
#ifndef NDEBUG
        osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_debug, 
            "Second object is NULL, first is not");
#endif
        return false;
    }
    else
    {
        if (this->numberOfCon != that->numberOfCon)
        {
#ifndef NDEBUG
            outStr.str("");
            outStr.clear();
            outStr << "Differences in DualVariableValues" << endl;
            outStr << "numberOfCon: " << this->numberOfCon << " vs. " << that->numberOfCon << endl;
            osoutput->OSPrint(ENUM_OUTPUT_AREA_OSResult, ENUM_OUTPUT_LEVEL_debug, outStr.str());
#endif
            return false;
        }

        for (unsigned int i = 0; i < this->numberOfCon; i++)
        {
            if (this->con[i] == NULL)
            {
                if (that->con[i] != NULL)
                    return false;
            }
            else
                if (!this->con[i]->IsEqual(that->con[i]))
                    return false;
        }
    }

    return true;
}//DualVariableValues::IsEqual

bool DualVarValue::IsEqual(DualVarValue *that)
{
    std::ostringstream outStr;

#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSResult, ENUM_OUTPUT_LEVEL_trace, "Start comparing in DualVarValue");
#endif
    if (that == NULL)
    {
#ifndef NDEBUG
        osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_debug, 
            "Second object is NULL, first is not");
#endif
        return false;
    }
    else
    {
        if (this->idx != that->idx  || this->name != that->name ||
            !OSIsEqual(this->value, that->value) )
        {
#ifndef NDEBUG
            outStr.str("");
            outStr.clear();
            outStr << "Differences in DualVarValue" << endl;
            outStr << "idx:   " << this->idx   <<  " vs. "  << that->idx   << endl;
            outStr << "name: -" << this->name  << "- vs. -" << that->name  << "-" << endl;
            outStr << "value: " << this->value <<  " vs. "  << that->value << endl;
            osoutput->OSPrint(ENUM_OUTPUT_AREA_OSResult, ENUM_OUTPUT_LEVEL_debug, outStr.str());
#endif
            return false;
        }
    }

    return true;
}//DualVarValue::IsEqual

bool OtherConstraintResult::IsEqual(OtherConstraintResult *that)
{
    std::ostringstream outStr;

#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSResult, ENUM_OUTPUT_LEVEL_trace, "Start comparing in OtherConstraintResult");
#endif
    if (that == NULL)
    {
#ifndef NDEBUG
        osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_debug, 
            "Second object is NULL, first is not");
#endif
        return false;
    }
    else
    {
        if (this->name        != that->name          ||
            this->value       != that->value         ||
            this->description != that->description  )
        {
#ifndef NDEBUG
            outStr.str("");
            outStr.clear();
            outStr << "Differences in OtherConstraintResult" << endl;
            outStr << "name:        " << this->name        << " vs. " << that->name        << endl;
            outStr << "value:       " << this->value       << " vs. " << that->value       << endl;
            outStr << "description: " << this->description << " vs. " << that->description << endl;
            osoutput->OSPrint(ENUM_OUTPUT_AREA_OSResult, ENUM_OUTPUT_LEVEL_debug, outStr.str());
#endif
            return false;
        }

        if (this->numberOfCon != that->numberOfCon)
        {
#ifndef NDEBUG
            outStr.str("");
            outStr.clear();
            outStr << "Differences in OtherConstraintResult" << endl;
            outStr << "numberOfCon: " << this->numberOfCon << " vs. " << that->numberOfCon << endl;
            osoutput->OSPrint(ENUM_OUTPUT_AREA_OSResult, ENUM_OUTPUT_LEVEL_debug, outStr.str());
#endif
            return false;
        }

        for (unsigned int i = 0; i < this->numberOfCon; i++)
        {
            if (this->con[i] == NULL)
            {
                if (that->con[i] != NULL)
                    return false;
            }
            else
                if (!this->con[i]->IsEqual(that->con[i]))
                    return false;
        }

        if (this->numberOfEnumerations != that->numberOfEnumerations)
        {
#ifndef NDEBUG
            outStr.str("");
            outStr.clear();
            outStr << "Differences in OtherConstraintResult" << endl;
            outStr << "numberOfEnumerations: " << this->numberOfEnumerations << " vs. " << that->numberOfEnumerations << endl;
            osoutput->OSPrint(ENUM_OUTPUT_AREA_OSResult, ENUM_OUTPUT_LEVEL_debug, outStr.str());
#endif
            return false;
        }

        for (unsigned int i = 0; i < this->numberOfEnumerations; i++)
        {
            if (this->enumeration[i] == NULL)
            {
                if (that->enumeration[i] != NULL)
                    return false;
            }
            else
                if (!this->enumeration[i]->IsEqual(that->enumeration[i]))
                    return false;
        }
    }

    return true;
}//OtherConstraintResult::IsEqual


bool OtherConResult::IsEqual(OtherConResult *that)
{
    std::ostringstream outStr;

#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSResult, ENUM_OUTPUT_LEVEL_trace, "Start comparing in OtherConResult");
#endif
    if (that == NULL)
    {
#ifndef NDEBUG
        osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_debug, 
            "Second object is NULL, first is not");
#endif
        return false;
    }
    else
    {
        if (this->idx   != that->idx  || this->name != that->name ||
            this->value != that->value )
        {
#ifndef NDEBUG
            outStr.str("");
            outStr.clear();
            outStr << "Differences in OtherConResult" << endl;
            outStr << "idx:   " << this->idx   <<  " vs. "  << that->idx   << endl;
            outStr << "name: -" << this->name  << "- vs. -" << that->name  << "-" << endl;
            outStr << "value: " << this->value <<  " vs. "  << that->value << endl;
            osoutput->OSPrint(ENUM_OUTPUT_AREA_OSResult, ENUM_OUTPUT_LEVEL_debug, outStr.str());
#endif
            return false;
        }
    }

    return true;
}//OtherConResult::IsEqual


bool OtherSolutionResults::IsEqual(OtherSolutionResults *that)
{
    std::ostringstream outStr;

#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSResult, ENUM_OUTPUT_LEVEL_trace, "Start comparing in OtherSolutionResults");
#endif
    if (that == NULL)
    {
#ifndef NDEBUG
        osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_debug, 
            "Second object is NULL, first is not");
#endif
        return false;
    }
    else
    {
        if (this->numberOfOtherSolutionResults != that->numberOfOtherSolutionResults)
        {
#ifndef NDEBUG
            outStr.str("");
            outStr.clear();
            outStr << "Differences in OtherSolutionResults" << endl;
            outStr << "numberOfOtherSolutionResults: " << this->numberOfOtherSolutionResults << " vs. " << that->numberOfOtherSolutionResults << endl;
            osoutput->OSPrint(ENUM_OUTPUT_AREA_OSResult, ENUM_OUTPUT_LEVEL_debug, outStr.str());
#endif
            return false;
        }

        for (unsigned int i = 0; i < this->numberOfOtherSolutionResults; i++)
        {
            if (this->otherSolutionResult[i] == NULL)
            {
                if (that->otherSolutionResult[i] != NULL)
                    return false;
            }
            else
                if (!this->otherSolutionResult[i]->IsEqual(that->otherSolutionResult[i]))
                    return false;
        }
    }

    return true;
}//OtherSolutionResults::IsEqual

bool OtherSolutionResult::IsEqual(OtherSolutionResult *that)
{
    std::ostringstream outStr;

#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSResult, ENUM_OUTPUT_LEVEL_trace, "Start comparing in OtherSolutionResult");
#endif
    if (that == NULL)
    {
#ifndef NDEBUG
        osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_debug, 
            "Second object is NULL, first is not");
#endif
        return false;
    }
    else
    {
        if (this->name        != that->name          ||
            this->category    != that->category      ||
            this->description != that->description  )
        {
#ifndef NDEBUG
            outStr.str("");
            outStr.clear();
            outStr << "Differences in OtherSolutionResult" << endl;
            outStr << "name:        " << this->name        << " vs. " << that->name        << endl;
            outStr << "category:    " << this->category    << " vs. " << that->category    << endl;
            outStr << "description: " << this->description << " vs. " << that->description << endl;
            osoutput->OSPrint(ENUM_OUTPUT_AREA_OSResult, ENUM_OUTPUT_LEVEL_debug, outStr.str());
#endif
            return false;
        }

        if (this->numberOfItems != that->numberOfItems)
        {
#ifndef NDEBUG
            outStr.str("");
            outStr.clear();
            outStr << "Differences in OtherSolutionResult" << endl;
            outStr << "numberOfItems: " << this->numberOfItems << " vs. " << that->numberOfItems << endl;
            osoutput->OSPrint(ENUM_OUTPUT_AREA_OSResult, ENUM_OUTPUT_LEVEL_debug, outStr.str());
#endif
            return false;
        }

        for (unsigned int i = 0; i < this->numberOfItems; i++)
        {
            if (this->item[i] != that->item[i])
            {
#ifndef NDEBUG
                outStr.str("");
                outStr.clear();
                outStr << "Differences in OtherSolutionResult" << endl;
                outStr << "item: " << this->item[i] << " vs. " << that->item[i] << endl;
                osoutput->OSPrint(ENUM_OUTPUT_AREA_OSResult, ENUM_OUTPUT_LEVEL_debug, outStr.str());
#endif
                return false;
            }
        }
    }

    return true;
}//OtherSolutionResult::IsEqual


bool OtherSolverOutput::IsEqual(OtherSolverOutput *that)
{
    std::ostringstream outStr;

#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSResult, ENUM_OUTPUT_LEVEL_trace, "Start comparing in OtherSolverOutput");
#endif
    if (that == NULL)
    {
#ifndef NDEBUG
        osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_debug, 
            "Second object is NULL, first is not");
#endif
        return false;
    }
    else
    {
        if (this->numberOfSolverOutputs != that->numberOfSolverOutputs)
        {
#ifndef NDEBUG
            outStr.str("");
            outStr.clear();
            outStr << "Differences in OtherSolverOutput" << endl;
            outStr << "numberOfSolverOutputs: " << this->numberOfSolverOutputs << " vs. " << that->numberOfSolverOutputs << endl;
            osoutput->OSPrint(ENUM_OUTPUT_AREA_OSResult, ENUM_OUTPUT_LEVEL_debug, outStr.str());
#endif
            return false;
        }

        for (unsigned int i = 0; i < this->numberOfSolverOutputs; i++)
        {
            if (this->solverOutput[i] == NULL)
            {
                if (that->solverOutput[i] != NULL)
                    return false;
            }
            else
                if (!this->solverOutput[i]->IsEqual(that->solverOutput[i]))
                    return false;
        }
    }

    return true;
}//OtherSolverOutput::IsEqual


bool SolverOutput::IsEqual(SolverOutput *that)
{
    std::ostringstream outStr;

#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSResult, ENUM_OUTPUT_LEVEL_trace, "Start comparing in SolverOutput");
#endif
    if (that == NULL)
    {
#ifndef NDEBUG
        osoutput->OSPrint(ENUM_OUTPUT_AREA_OSInstance, ENUM_OUTPUT_LEVEL_debug, 
            "Second object is NULL, first is not");
#endif
        return false;
    }
    else
    {
        if (this->name        != that->name          ||
            this->category    != that->category      ||
            this->description != that->description  )
        {
#ifndef NDEBUG
            outStr.str("");
            outStr.clear();
            outStr << "Differences in SolverOutput" << endl;
            outStr << "name:        " << this->name        << " vs. " << that->name        << endl;
            outStr << "category:    " << this->category    << " vs. " << that->category    << endl;
            outStr << "description: " << this->description << " vs. " << that->description << endl;
            osoutput->OSPrint(ENUM_OUTPUT_AREA_OSResult, ENUM_OUTPUT_LEVEL_debug, outStr.str());
#endif
            return false;
        }

        if (this->numberOfItems != that->numberOfItems)
        {
#ifndef NDEBUG
            outStr.str("");
            outStr.clear();
            outStr << "Differences in SolverOutput" << endl;
            outStr << "numberOfItems: " << this->numberOfItems << " vs. " << that->numberOfItems << endl;
            osoutput->OSPrint(ENUM_OUTPUT_AREA_OSResult, ENUM_OUTPUT_LEVEL_debug, outStr.str());
#endif
            return false;
        }

        for (unsigned int i = 0; i < numberOfItems; i++)
            if (this->item[i] != that->item[i])
            {
#ifndef NDEBUG
                outStr.str("");
                outStr.clear();
                outStr << "Differences in SolverOutput" << endl;
                outStr << "item: " << this->item[i] << " vs. " << that->item[i] << endl;
                osoutput->OSPrint(ENUM_OUTPUT_AREA_OSResult, ENUM_OUTPUT_LEVEL_debug, outStr.str());
#endif
                return false;
            }
    }

    return true;
}//SolverOutput::IsEqual


/******************************************************
 * methods to set random objects and their components
 ******************************************************/
bool OSResult::setRandom(double density, bool conformant)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSResult, ENUM_OUTPUT_LEVEL_trace, "Set random OSResult");
#endif
    if (OSRand() <= density)
    {
        resultHeader = new GeneralFileHeader();
        resultHeader->setRandom(density, conformant);
    }
    if (OSRand() <= density)
    {
        general = new GeneralResult();
        general->setRandom(density, conformant);
    }
    if (OSRand() <= density)
    {
        system = new SystemResult();
        system->setRandom(density, conformant);
    }
    if (OSRand() <= density)
    {
        service = new ServiceResult();
        service->setRandom(density, conformant);
    }
    if (OSRand() <= density)
    {
        job = new JobResult();
        job->setRandom(density, conformant);
    }
    if (OSRand() <= density)
    {
        optimization = new OptimizationResult();
        optimization->setRandom(density, conformant);
    }
    return true;
}//OSResult::setRandom


bool GeneralResult::setRandom(double density, bool conformant)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSResult, ENUM_OUTPUT_LEVEL_trace, "Set random GeneralResult");
#endif
    if (OSRand() <= density) this->message        = "random string";
    if (OSRand() <= density) this->serviceURI     = "random string";
    if (OSRand() <= density) this->serviceName    = "random string";
    if (OSRand() <= density) this->instanceName   = "random string";
    if (OSRand() <= density) this->jobID          = "random string";
    if (OSRand() <= density) this->solverInvoked  = "random string";
    if (OSRand() <= density) this->timeStamp      = "random string";

    if (OSRand() <= density)
    {
        generalStatus = new GeneralStatus();


        generalStatus->setRandom(density, conformant);
    }
    if (OSRand() <= density)
    {
        otherResults = new OtherResults();
        otherResults->setRandom(density, conformant);
    }
    return true;
}//GeneralResult::setRandom


bool GeneralStatus::setRandom(double density, bool conformant)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSResult, ENUM_OUTPUT_LEVEL_trace, "Set random GeneralStatus");
#endif
    int n;

    if (OSRand() <= density) numberOfSubstatuses = (int)(1+4*OSRand());
    if (OSRand() <= density) type = "normal";
    else type = "error";
    if (OSRand() <= density) description = "random string";

    if (conformant)	n = this->numberOfSubstatuses;
    else            n = (int)(1+4*OSRand());

    substatus = new GeneralSubstatus*[n];

    for (int i = 0; i < n; i++)
    {
        substatus[i] = new GeneralSubstatus();
        substatus[i]->setRandom(density, conformant);
    }

    return true;
}//GeneralStatus::setRandom

bool GeneralSubstatus::setRandom(double density, bool conformant)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSResult, ENUM_OUTPUT_LEVEL_trace, "Set random GeneralSubstatus");
#endif
    name = "substatus name";
    if (OSRand() <= density) description = "random string";
    return true;
}//GeneralSubstatus::setRandom


bool OtherResults::setRandom(double density, bool conformant)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSResult, ENUM_OUTPUT_LEVEL_trace, "Set random OtherResults");
#endif
    int n;

    this->numberOfOtherResults = (int)(1+4*OSRand());

    if (conformant)	n = this->numberOfOtherResults;
    else            n = (int)(1+4*OSRand());

    other = new OtherOptionOrResult*[n];

    for (int i = 0; i < n; i++)
    {
        other[i] = new OtherOptionOrResult();
        other[i]->setRandom(density, conformant);
    }

    return true;
}//OtherResults::setRandom

#if 0
bool OtherResult::setRandom(double density, bool conformant)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSResult, ENUM_OUTPUT_LEVEL_trace, "Set random OtherResult");
#endif
    name        = "other result";
    value       = "random string";
    description = "random string";
    return true;
}//OtherResult::setRandom
#endif

bool SystemResult::setRandom(double density, bool conformant)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSResult, ENUM_OUTPUT_LEVEL_trace, "Set random SystemResult");
#endif
    if (OSRand() <= density) systemInformation = "random string";

    if (OSRand() <= density)
    {
        availableDiskSpace = new StorageCapacity();
        availableDiskSpace->setRandom(density, conformant);
    }

    if (OSRand() <= density)
    {
        availableMemory = new StorageCapacity();
        availableMemory->setRandom(density, conformant);
    }
    if (OSRand() <= density)
    {
        availableCPUSpeed = new CPUSpeed();
        availableCPUSpeed->setRandom(density, conformant);
    }

    if (OSRand() <= density)
    {
        availableCPUNumber = new CPUNumber();
        availableCPUNumber->setRandom(density, conformant);
    }

    if (OSRand() <= density)
    {
        otherResults = new OtherResults();
        otherResults->setRandom(density, conformant);
    }
    return true;
}//SystemResult::setRandom

bool ServiceResult::setRandom(double density, bool conformant)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSResult, ENUM_OUTPUT_LEVEL_trace, "Set random ServiceResult");
#endif
    if (OSRand() <= density)
    {
        double temp = OSRand();
        if (conformant) temp = 0.5*temp;

        if      (temp <= 0.25) this->currentState = "unknown";
        else if (temp <= 0.50) this->currentState = "busy";
        else if (temp <= 0.75) this->currentState = "";
        else                   this->currentState = "known";
    }

    if (OSRand() <= density) currentJobCount = (int) (-1+4*OSRand());
    if (OSRand() <= density) totalJobsSoFar  = (int) (-1+4*OSRand());
    if (OSRand() <= density) timeServiceStarted  = "2010-07-12T01:23:45-03:00";

    if (OSRand() <= density)
    {
        double temp = OSRand();

        if      (temp <= 0.25) this->serviceUtilization = OSRand();
        else if (temp <= 0.50) this->serviceUtilization = -1.0;
        else if (temp <= 0.75) this->serviceUtilization = OSDBL_MAX;
        else                   this->serviceUtilization = OSNaN();
    }

    if (OSRand() <= density)
    {
        otherResults = new OtherResults();
        otherResults->setRandom(density, conformant);
    }
    return true;
}//ServiceResult::setRandom


bool JobResult::setRandom(double density, bool conformant)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSResult, ENUM_OUTPUT_LEVEL_trace, "Set random JobResult");
#endif
    if (OSRand() <= density)
    {
        double temp = OSRand();
        if (conformant) temp = 0.5*temp;

        if      (temp <= 0.25) this->status = "finished";
        else if (temp <= 0.50) this->status = "running";
        else if (temp <= 0.75) this->status = "";
        else                   this->status = "walking";
    }

    if (OSRand() <= density) submitTime         = "1970-01-01T00:00:00-00:00";
    if (OSRand() <= density) scheduledStartTime = "1970-01-01T00:00:00-00:00";
    if (OSRand() <= density) actualStartTime    = "1970-01-01T00:00:00-00:00";
    if (OSRand() <= density) endTime            = "1970-01-01T00:00:00-00:00";

    if (OSRand() <= density)
    {
        timingInformation = new TimingInformation();
        timingInformation->setRandom(density, conformant);
    }

    if (OSRand() <= density)
    {
        usedDiskSpace = new StorageCapacity();
        usedDiskSpace->setRandom(density, conformant);
    }

    if (OSRand() <= density)
    {
        usedMemory = new StorageCapacity();
        usedMemory->setRandom(density, conformant);
    }

    if (OSRand() <= density)
    {
        usedCPUSpeed = new CPUSpeed();
        usedCPUSpeed->setRandom(density, conformant);
    }

    if (OSRand() <= density)
    {
        usedCPUNumber = new CPUNumber();
        usedCPUNumber->setRandom(density, conformant);
    }

    if (OSRand() <= density)
    {
        otherResults = new OtherResults();
        otherResults->setRandom(density, conformant);
    }
    return true;
}//JobResult::setRandom


bool TimingInformation::setRandom(double density, bool conformant)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSResult, ENUM_OUTPUT_LEVEL_trace, "Set random TimingInformation");
#endif
    int n;

    this->numberOfTimes = (int)(1+4*OSRand());

    if (conformant)	n = this->numberOfTimes;
    else            n = (int)(1+4*OSRand());

    time = new TimeMeasurement*[n];

    for (int i = 0; i < n; i++)
    {
        time[i] = new TimeMeasurement();
        time[i]->setRandom(density, conformant);
    }

    return true;
}//TimingInformation::setRandom

#if 0
bool Time::setRandom(double density, bool conformant)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSResult, ENUM_OUTPUT_LEVEL_trace, "Set random Time");
#endif
    if (OSRand() <= density)
        this->description = "random string";

    if (OSRand() <= density)
    {
        double temp = OSRand();
        if (conformant) temp = 0.5*temp;

        if      (temp <= 0.25) this->type = "elapsedTime";
        else if (temp <= 0.50) this->type = "cpuTime";
        else if (temp <= 0.75) this->type = "";
        else                   this->type = "dinnerTime";
    }

    if (OSRand() <= density)
    {
        double temp = OSRand();
        if (conformant) temp = 0.5*temp;

        if      (temp <= 0.25) this->category = "total";
        else if (temp <= 0.50) this->category = "input";
        else if (temp <= 0.75) this->category = "";
        else                   this->category = "putin";
    }

    if (OSRand() <= density)
    {
        double temp = OSRand();
        if (conformant) temp = 0.5*temp;

        if      (temp <= 0.25) this->unit = "second";
        else if (temp <= 0.50) this->unit = "tick";
        else if (temp <= 0.75) this->unit = "";
        else                   this->unit = "flea";
    }

    if (OSRand() <= density)
    {
        if (OSRand() <= 0.5) this->value = 3.14156;
        else                 this->value = 2.71828;
    }
    return true;
}//Time::setRandom
#endif


bool TimeMeasurement::setRandom(double density, bool conformant)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSResult, ENUM_OUTPUT_LEVEL_trace, "Set random TimeMeasurement");
#endif
    if (OSRand() <= density)
        this->description = "random string";

    if (OSRand() <= density)
    {
        double temp = OSRand();
        if (conformant) temp = 0.5*temp;

        if      (temp <= 0.25) this->type = "elapsedTime";
        else if (temp <= 0.50) this->type = "cpuTime";
        else if (temp <= 0.75) this->type = "";
        else                   this->type = "dinnerTime";
    }

    if (OSRand() <= density)
    {
        double temp = OSRand();
        if (conformant) temp = 0.5*temp;

        if      (temp <= 0.25) this->category = "total";
        else if (temp <= 0.50) this->category = "input";
        else if (temp <= 0.75) this->category = "";
        else                   this->category = "putin";
    }

    if (OSRand() <= density) this->TimeSpan::setRandom(density,conformant);

    return true;
}//TimeMeasurement::setRandom

bool OptimizationResult::setRandom(double density, bool conformant)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSResult, ENUM_OUTPUT_LEVEL_trace, "Set random OptimizationResult");
#endif
    numberOfSolutions = (int)(1+4*OSRand());

    numberOfVariables   = 10;
    numberOfObjectives  = 2;
    numberOfConstraints = 5;

    int n;

    if (conformant)	n = this->numberOfSolutions;
    else            n = (int)(1+4*OSRand());

    solution = new OptimizationSolution*[n];

    for (int i = 0; i < n; i++)
    {
        solution[i] = new OptimizationSolution();
        solution[i]->setRandom(density,conformant);
    }

    return true;
}//OptimizationResult::setRandom

bool OptimizationSolution::setRandom(double density, bool conformant)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSResult, ENUM_OUTPUT_LEVEL_trace, "Set random OptimizationSolution");
#endif
    if (OSRand() <= density)
    {
        if (OSRand() <= density) targetObjectiveIdx = -1;
        else					 targetObjectiveIdx = -2;
    }

    if (OSRand() <= density) targetObjectiveName = "random string";
    if (OSRand() <= density) weightedObjectives = (OSRand() < 0.5);

    if (OSRand() <= density) message = "random string";

    status = new OptimizationSolutionStatus();
    status->setRandom(density, conformant);

    if (OSRand() <= density)
    {
        variables = new VariableSolution();
        variables->setRandom(density, conformant);
    }

    if (OSRand() <= density)
    {
        objectives = new ObjectiveSolution();
        objectives->setRandom(density, conformant);
    }

    if (OSRand() <= density)
    {
        constraints = new ConstraintSolution();
        constraints->setRandom(density, conformant);
    }

    if (OSRand() <= density)
    {
        otherSolutionResults = new OtherSolutionResults();
        otherSolutionResults->setRandom(density, conformant);
    }

    return true;
}//OptimizationSolution::setRandom


bool OptimizationSolutionStatus::setRandom(double density, bool conformant)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSResult, ENUM_OUTPUT_LEVEL_trace, "Set random OptimizationSolutionStatus");
#endif
    double temp = OSRand();
    if (conformant) temp = 0.5*temp;

    if      (temp <= 0.25) this->type = "optimal";
    else if (temp <= 0.50) this->type = "unsure";
    else if (temp <= 0.75) this->type = "";
    else                   this->type = "sure";

    if (OSRand() <= density) this->description = "random string";

    if (OSRand() <= density)
    {
        int n;

        this->numberOfSubstatuses = (int)(1+4*OSRand());

        if (conformant)	n = this->numberOfSubstatuses;
        else            n = (int)(1+4*OSRand());

        substatus = new OptimizationSolutionSubstatus*[n];

        for (int i = 0; i < n; i++)
        {
            substatus[i] = new OptimizationSolutionSubstatus();
            substatus[i]->setRandom(density, conformant);
        }
    }

    return true;
}//OptimizationSolutionStatus::setRandom


bool OptimizationSolutionSubstatus::setRandom(double density, bool conformant)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSResult, ENUM_OUTPUT_LEVEL_trace, "Set random OptimizationSolutionSubstatus");
#endif
    double temp = OSRand();
    if (conformant) temp = 0.5*temp;

    if      (temp <= 0.25) this->type = "stoppedByLimit";
    else if (temp <= 0.50) this->type = "stoppedByBounds";
    else if (temp <= 0.75) this->type = "";
    else                   this->type = "stoppedByPolice";

    if (OSRand() <= density) this->description = "random string";

    return true;
}//OptimizationSolutionSubstatus::setRandom


bool VariableSolution::setRandom(double density, bool conformant)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSResult, ENUM_OUTPUT_LEVEL_trace, "Set random VariableSolution");
#endif
    if (OSRand() <= density)
    {
        int n;

        this->numberOfOtherVariableResults = (int)(1+4*OSRand());

        if (conformant)	n = this->numberOfOtherVariableResults;
        else            n = (int)(1+4*OSRand());

        other = new OtherVariableResult*[n];

        for (int i = 0; i < n; i++)
        {
            other[i] = new OtherVariableResult();
            other[i]->setRandom(density, conformant);
        }
    }

    if (OSRand() <= density)
    {
        values = new VariableValues();
        values->setRandom(density, conformant);
    }

    if (OSRand() <= density)
    {
        valuesString = new VariableValuesString();
        valuesString->setRandom(density, conformant);
    }

    if (OSRand() <= density)
    {
        basisStatus = new BasisStatus();
        basisStatus->setRandom(density, conformant, 0, 9);
    }

    return true;
}//VariableSolution::setRandom

bool VariableValues::setRandom(double density, bool conformant)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSResult, ENUM_OUTPUT_LEVEL_trace, "Set random VariableValues");
#endif
    int n;

    this->numberOfVar = (int)(1+4*OSRand());

    if (conformant)	n = this->numberOfVar;
    else            n = (int)(1+4*OSRand());

    var = new VarValue*[n];

    for (int i = 0; i < n; i++)
    {
        var[i] = new VarValue();
        var[i]->setRandom(density, conformant);
    }

    return true;
}//VariableValues::setRandom


bool VarValue::setRandom(double density, bool conformant)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSResult, ENUM_OUTPUT_LEVEL_trace, "Set random VarValue");
#endif
    this->idx = (int)(10*OSRand());
    if (OSRand() <= 0.5) this->value = 3.14156;
    else                 this->value = 2.71828;

    if (OSRand() <= density) this->name = "random string";

    return true;
}//VarValue::setRandom


bool VariableValuesString::setRandom(double density, bool conformant)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSResult, ENUM_OUTPUT_LEVEL_trace, "Set random VariableValuesString");
#endif
    int n;

    this->numberOfVar = (int)(1+4*OSRand());

    if (conformant)	n = this->numberOfVar;
    else            n = (int)(1+4*OSRand());

    var = new VarValueString*[n];

    for (int i = 0; i < n; i++)
    {
        var[i] = new VarValueString();
        var[i]->setRandom(density, conformant);
    }

    return true;
}//VariableValuesString::setRandom


bool VarValueString::setRandom(double density, bool conformant)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSResult, ENUM_OUTPUT_LEVEL_trace, "Set random VarValueString");
#endif
    this->idx = (int)(10*OSRand());
    if (OSRand() <= 0.5) this->value = "random string";
    else                 this->value = "";

    if (OSRand() <= density) this->name = "random string";

    return true;
}//VarValueString::setRandom


bool OtherVariableResult::setRandom(double density, bool conformant)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSResult, ENUM_OUTPUT_LEVEL_trace, "Set random OtherVariableResult");
#endif
    this->name = "random string";
    if (OSRand() <= density) this->value       = "random string";
    if (OSRand() <= density) this->description = "random string";

    if (OSRand() <= density)
    {
        if (OSRand() <= 0.5)
        {
            int n;

            this->numberOfVar = (int)(1+4*OSRand());

            if (conformant)	n = this->numberOfVar;
            else            n = (int)(1+4*OSRand());

            var = new OtherVarResult*[n];

            for (int i = 0; i < n; i++)
            {
                var[i] = new OtherVarResult();
                var[i]->setRandom(density, conformant);
            }
        }
        else
        {
            int n;

            this->numberOfEnumerations = (int)(1+4*OSRand());

            if (conformant)	n = this->numberOfEnumerations;
            else            n = (int)(1+4*OSRand());

            enumeration = new OtherOptionOrResultEnumeration*[n];

            for (int i = 0; i < n; i++)
            {
                enumeration[i] = new OtherOptionOrResultEnumeration();
                enumeration[i]->setRandom(density, conformant, 0, 9);
            }
        }
    }

    return true;
}//OtherVariableResult::setRandom


bool OtherVarResult::setRandom(double density, bool conformant)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSResult, ENUM_OUTPUT_LEVEL_trace, "Set random OtherVarResult");
#endif
    this->idx = (int)(10*OSRand());
    if (OSRand() <= 0.5) this->value = "random string";
    else                 this->value = "";

    if (OSRand() <= density) this->name = "random string";

    return true;
}//OtherVarResult::setRandom


bool ObjectiveSolution::setRandom(double density, bool conformant)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSResult, ENUM_OUTPUT_LEVEL_trace, "Set random ObjectiveSolution");
#endif
    if (OSRand() <= density)
    {
        int n;

        this->numberOfOtherObjectiveResults = (int)(1+4*OSRand());

        if (conformant)	n = this->numberOfOtherObjectiveResults;
        else            n = (int)(1+4*OSRand());

        other = new OtherObjectiveResult*[n];

        for (int i = 0; i < n; i++)
        {

            other[i] = new OtherObjectiveResult();
            other[i]->setRandom(density, conformant);
        }
    }


    if (OSRand() <= density)
    {
        values = new ObjectiveValues();
        values->setRandom(density, conformant);
    }

    if (OSRand() <= density)
    {
        basisStatus = new BasisStatus();
        basisStatus->setRandom(density, conformant, -2, -1);
    }

    return true;
}//ObjectiveSolution::setRandom


bool ObjectiveValues::setRandom(double density, bool conformant)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSResult, ENUM_OUTPUT_LEVEL_trace, "Set random ObjectiveValues");
#endif
    int n;

    this->numberOfObj = (int)(1+4*OSRand());

    if (conformant)	n = this->numberOfObj;
    else            n = (int)(1+4*OSRand());

    obj = new ObjValue*[n];

    for (int i = 0; i < n; i++)
    {
        obj[i] = new ObjValue();
        obj[i]->setRandom(density, conformant);
    }

    return true;
}//ObjectiveValues::setRandom


bool ObjValue::setRandom(double density, bool conformant)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSResult, ENUM_OUTPUT_LEVEL_trace, "Set random ObjValue");
#endif
    if (OSRand() <= 0.5) this->idx = -1;
    else                 this->idx = -2;

    if (OSRand() <= 0.5) this->value = 3.14156;
    else                 this->value = 2.71828;

    if (OSRand() <= density) this->name = "random string";

    return true;
}//ObjValue::setRandom


bool OtherObjectiveResult::setRandom(double density, bool conformant)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSResult, ENUM_OUTPUT_LEVEL_trace, "Set random OtherObjectiveResult");
#endif
    this->name = "random string";
    if (OSRand() <= density) this->value       = "random string";
    if (OSRand() <= density) this->description = "random string";

    if (OSRand() <= density)
    {
        if (OSRand() <= 0.5)
        {
            int n;

            this->numberOfObj = (int)(1+4*OSRand());

            if (conformant)	n = this->numberOfObj;
            else            n = (int)(1+4*OSRand());

            obj = new OtherObjResult*[n];

            for (int i = 0; i < n; i++)
            {
                obj[i] = new OtherObjResult();
                obj[i]->setRandom(density, conformant);
            }
        }
        else
        {
            int n;

            this->numberOfEnumerations = (int)(1+4*OSRand());

            if (conformant)	n = this->numberOfEnumerations;
            else            n = (int)(1+4*OSRand());

            enumeration = new OtherOptionOrResultEnumeration*[n];

            for (int i = 0; i < n; i++)
            {
                enumeration[i] = new OtherOptionOrResultEnumeration();
                enumeration[i]->setRandom(density, conformant, -2, -1);
            }
        }
    }

    return true;
}//OtherObjectiveResult::setRandom


bool OtherObjResult::setRandom(double density, bool conformant)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSResult, ENUM_OUTPUT_LEVEL_trace, "Set random OtherObjResult");
#endif
    if (OSRand() <= 0.5) this->idx = -1;
    else                 this->idx = -2;

    if (OSRand() <= 0.5) this->value = "random string";
    else                 this->value = "";

    if (OSRand() <= density) this->name = "random string";

    return true;
}//OtherObjResult::setRandom


bool ConstraintSolution::setRandom(double density, bool conformant)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSResult, ENUM_OUTPUT_LEVEL_trace, "Set random ConstraintSolution");
#endif
    if (OSRand() <= density)
    {
        int n;

        this->numberOfOtherConstraintResults = (int)(1+4*OSRand());

        if (conformant)	n = this->numberOfOtherConstraintResults;
        else            n = (int)(1+4*OSRand());

        other = new OtherConstraintResult*[n];

        for (int i = 0; i < n; i++)
        {
            other[i] = new OtherConstraintResult();
            other[i]->setRandom(density, conformant);
        }
    }

    if (OSRand() <= density)
    {
        dualValues = new DualVariableValues();
        dualValues->setRandom(density, conformant);
    }

    if (OSRand() <= density)
    {
        basisStatus = new BasisStatus();
        basisStatus->setRandom(density, conformant, 0 ,4);
    }

    return true;
}//ConstraintSolution::setRandom


bool DualVariableValues::setRandom(double density, bool conformant)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSResult, ENUM_OUTPUT_LEVEL_trace, "Set random DualVariableValues");
#endif
    int n;

    this->numberOfCon = (int)(1+4*OSRand());

    if (conformant)	n = this->numberOfCon;
    else            n = (int)(1+4*OSRand());

    con = new DualVarValue*[n];

    for (int i = 0; i < n; i++)
    {
        con[i] = new DualVarValue();
        con[i]->setRandom(density, conformant);
    }

    return true;
}//DualVariableValues::setRandom

bool DualVarValue::setRandom(double density, bool conformant)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSResult, ENUM_OUTPUT_LEVEL_trace, "Set random DualVarValue");
#endif
    this->idx = (int)(5*OSRand());
    if (OSRand() <= 0.5) this->value = 3.14156;
    else                 this->value = 2.71828;

    if (OSRand() <= density) this->name = "random string";

    return true;
}//DualVarValue::setRandom

bool OtherConstraintResult::setRandom(double density, bool conformant)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSResult, ENUM_OUTPUT_LEVEL_trace, "Set random OtherConstraintResult");
#endif
    this->name = "random string";
    if (OSRand() <= density) this->value       = "random string";
    if (OSRand() <= density) this->description = "random string";

    if (OSRand() <= density)
    {
        if (OSRand() <= 0.5)
        {
            int n;

            this->numberOfCon = (int)(1+4*OSRand());

            if (conformant)	n = this->numberOfCon;
            else            n = (int)(1+4*OSRand());

            con = new OtherConResult*[n];

            for (int i = 0; i < n; i++)
            {
                con[i] = new OtherConResult();
                con[i]->setRandom(density, conformant);
            }
        }
        else
        {
            int n;

            this->numberOfEnumerations = (int)(1+4*OSRand());

            if (conformant)	n = this->numberOfEnumerations;
            else            n = (int)(1+4*OSRand());

            enumeration = new OtherOptionOrResultEnumeration*[n];

            for (int i = 0; i < n; i++)
            {
                enumeration[i] = new OtherOptionOrResultEnumeration();
                enumeration[i]->setRandom(density, conformant, 0, 4);
            }
        }
    }


    return true;
}//OtherConstraintResult::setRandom


bool OtherConResult::setRandom(double density, bool conformant)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSResult, ENUM_OUTPUT_LEVEL_trace, "Set random OtherConResult");
#endif
    this->idx = (int)(5*OSRand());
    if (OSRand() <= 0.5) this->value = "random string";
    else                 this->value = "";

    if (OSRand() <= density) this->name = "random string";

    return true;
}//OtherConResult::setRandom


bool OtherSolutionResults::setRandom(double density, bool conformant)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSResult, ENUM_OUTPUT_LEVEL_trace, "Set random OtherSolutionResults");
#endif
    numberOfOtherSolutionResults = (int)(4*OSRand());

    int n;

    if (conformant)	n = this->numberOfOtherSolutionResults;
    else            n = (int)(4*OSRand());

    otherSolutionResult = new OtherSolutionResult*[n];

    for (int i = 0; i < n; i++)
    {
        otherSolutionResult[i] = new OtherSolutionResult();
        otherSolutionResult[i]->setRandom(density, conformant);
    }

    return true;
}//OtherSolutionResults::setRandom

bool OtherSolutionResult::setRandom(double density, bool conformant)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSResult, ENUM_OUTPUT_LEVEL_trace, "Set random OtherSolutionResult");
#endif
    name = "random string";
    numberOfItems = (int) (4*OSRand());

    if (OSRand() <= density) category    = "random string";
    if (OSRand() <= density) description = "random string";

    int n;

    if (conformant)	n = this->numberOfItems;
    else            n = (int)(1+4*OSRand());

    if (n > 0 || OSRand() <= density)
    {
        item = new std::string[n];

        for (int i = 0; i < n; i++)
            item[i] = "random string";
    }

    return true;
}//OtherSolutionResult::setRandom


bool OtherSolverOutput::setRandom(double density, bool conformant)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSResult, ENUM_OUTPUT_LEVEL_trace, "Set random OtherSolverOutput");
#endif
    int n;

    this->numberOfSolverOutputs = (int)(1+4*OSRand());

    if (conformant)	n = this->numberOfSolverOutputs;
    else            n = (int)(1+4*OSRand());

    solverOutput = new SolverOutput*[n];

    for (int i = 0; i < n; i++)
    {
        solverOutput[i] = new SolverOutput();
        solverOutput[i]->setRandom(density, conformant);
    }

    return true;
}//OtherSolverOutput::setRandom


bool SolverOutput::setRandom(double density, bool conformant)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSResult, ENUM_OUTPUT_LEVEL_trace, "Set random SolverOutput");
#endif
    name = "random string";
    numberOfItems = (int) (4*OSRand());

    if (OSRand() <= density) category    = "random string";
    if (OSRand() <= density) description = "random string";

    int n;

    if (conformant)	n = this->numberOfItems;
    else            n = (int)(1+4*OSRand());

    if (n > 0 || OSRand() <= density)
    {
        item = new std::string[n];

        for (int i = 0; i < n; i++)
            item[i] = "random string";
    }

    return true;
}//SolverOutput::setRandom
