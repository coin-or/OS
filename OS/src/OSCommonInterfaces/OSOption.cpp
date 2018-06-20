/* $Id$ */
/** @file OSOption.cpp
 *
 *
 * @author Horand Gassmann, Jun Ma, Kipp Martin
 *
 * \remarks
 * Copyright (C) 2005-2011, Horand Gassmann, Jun Ma, Kipp Martin,
 * Northwestern University, and the University of Chicago.
 * All Rights Reserved.
 * This software is licensed under the Eclipse Public License.
 * Please see the accompanying LICENSE file in root directory for terms.
 *
 */

#include "OSOption.h"

using namespace std;

InstanceLocationOption::InstanceLocationOption():
    locationType ("local"),
    value ("")
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_trace, "Inside InstanceLocationOption Constructor");
#endif
}// end InstanceLocationOption constructor

InstanceLocationOption::~InstanceLocationOption()
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_trace, "InstanceLocationOption Destructor Called");
#endif
}//end InstanceLocationOption destructor


ContactOption::ContactOption():
    transportType ("osp"),
    value ("")
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_trace, "Inside ContactOption Constructor");
#endif
}// end ContactOption constructor

ContactOption::~ContactOption()
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_trace, "ContactOption Destructor Called");
#endif
}//end ContactOption destructor

#if 0
OtherOption::OtherOption():
    name (""),
    value (""),
    description ("")
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_trace, "Inside OtherOption Constructor");
#endif
}// end OtherOption constructor

OtherOption::~OtherOption()
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_trace, "OtherOption Destructor Called");
#endif
}//end OtherOption destructor
#endif

OtherOptions::OtherOptions():
    numberOfOtherOptions(0)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_trace, "Inside OtherOptions Constructor");
#endif
    other = NULL;
}// end OtherOptions constructor

OtherOptions::~OtherOptions()
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_trace, "OtherOptions Destructor Called");
#endif

    if (other != NULL)
    {
        int i;
        for (i=0; i<numberOfOtherOptions; i++)
        {
            delete other[i];
            other[i] = NULL;
        }
        delete[] other;
        other = NULL;
    }
}//end OtherOptions destructor


GeneralOption::GeneralOption():
    serviceURI (""),
    serviceName (""),
    instanceName (""),
    jobID (""),
    solverToInvoke (""),
    license (""),
    userName (""),
    password ("")
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_trace, "Inside GeneralOption Constructor");
#endif
    instanceLocation = NULL;
    contact = NULL;
    otherOptions = NULL;
}// end GeneralOption constructor

GeneralOption::~GeneralOption()
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_trace, "GeneralOption Destructor Called");
#endif
    if (instanceLocation != NULL) delete instanceLocation;
    instanceLocation = NULL;
    if (contact != NULL) delete contact;
    contact = NULL;
    if (otherOptions != NULL) delete otherOptions;
    otherOptions = NULL;
}//end GeneralOption destructor


MinDiskSpace::MinDiskSpace():
    unit ("byte"),
    description(""),
    value (0.0)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_trace, "Inside MinDiskSpace Constructor");
#endif
}// end MinDiskSpace constructor

MinDiskSpace::~MinDiskSpace()
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_trace, "MinDiskSpace Destructor Called");
#endif
}// end MinDiskSpace destructor


MinMemorySize::MinMemorySize():
    unit ("byte"),
    description(""),
    value (0.0)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_trace, "Inside MinMemorySize Constructor");
#endif
}// end MinMemorySize constructor

MinMemorySize::~MinMemorySize()
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_trace, "MinMemorySize Destructor Called");
#endif
}// end MinMemorySize destructor


MinCPUSpeed::MinCPUSpeed():
    unit ("hertz"),
    description(""),
    value (0.0)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_trace, "Inside MinCPUSpeed Constructor");
#endif
}// end MinCPUSpeed constructor

MinCPUSpeed::~MinCPUSpeed()
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_trace, "MinCPUSpeed Destructor Called");
#endif
}// end MinCPUSpeed destructor

MinCPUNumber::MinCPUNumber():
    description(""),
    value (0)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_trace, "Inside MinCPUNumber Constructor");
#endif
}// end MinCPUNumber constructor

MinCPUNumber::~MinCPUNumber()
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_trace, "MinCPUNumber Destructor Called");
#endif
}// end MinCPUNumber destructor


SystemOption::SystemOption()
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_trace, "Inside SystemOption Constructor");
#endif
    minDiskSpace = NULL;
    minMemorySize = NULL;
    minCPUSpeed = NULL;
    minCPUNumber = NULL;
    otherOptions = NULL;
}// end SystemOption constructor

SystemOption::~SystemOption()
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_trace, "SystemOption Destructor Called");
#endif
    if (minDiskSpace != NULL) delete minDiskSpace;
    minDiskSpace = NULL;
    if (minMemorySize != NULL) delete minMemorySize;
    minMemorySize = NULL;
    if (minCPUSpeed != NULL) delete minCPUSpeed;
    minCPUSpeed = NULL;
    if (minCPUNumber != NULL) delete minCPUNumber;
    minCPUNumber = NULL;
    if (otherOptions != NULL) delete otherOptions;
    otherOptions = NULL;
}//end SystemOption destructor


ServiceOption::ServiceOption():
    type ("solver")
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_trace, "Inside ServiceOption Constructor");
#endif
    otherOptions = NULL;
}// end ServiceOption constructor

ServiceOption::~ServiceOption()
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_trace, "ServiceOption Destructor Called");
#endif
    if (otherOptions != NULL) delete otherOptions;
    otherOptions = NULL;
}//end ServiceOption destructor


JobDependencies::JobDependencies():
    numberOfJobIDs (0)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_trace, "Inside JobDependencies Constructor");
#endif
    jobID = NULL;
}// end JobDependencies constructor

JobDependencies::~JobDependencies()
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_trace, "JobDependencies Destructor Called");
#endif

    if (jobID != NULL)
    {
        delete[] jobID;
        jobID = NULL;
    }
}//end JobDependencies destructor


DirectoriesAndFiles::DirectoriesAndFiles():
    numberOfPaths (0)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_trace, "Inside DirectoriesAndFiles Constructor");
#endif
    path = NULL;
}// end DirectoriesAndFiles constructor

DirectoriesAndFiles::~DirectoriesAndFiles()
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_trace, "DirectoriesAndFiles Destructor Called");
#endif
    if (path != NULL)
    {
        delete[] path;
        path = NULL;
    }
}//end DirectoriesAndFiles destructor


PathPair::PathPair():
    from (""),
    to (""),
    makeCopy (false)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_trace, "Inside PathPair Constructor");
#endif
}// end PathPair constructor

PathPair::~PathPair()
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_trace, "PathPair Destructor Called");
#endif
}//end PathPair destructor


PathPairs::PathPairs():
    numberOfPathPairs(0)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_trace, "Inside PathPairs Constructor");
#endif
    pathPair = NULL;
}// end PathPairs constructor

PathPairs::~PathPairs()
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_trace, "PathPairs Destructor Called");
#endif
    int i;
    if (pathPair != NULL)
    {
        for (i=0; i < numberOfPathPairs; i++)
        {
            delete pathPair[i];
            pathPair[i] = NULL;
        }
        delete[] pathPair;
        pathPair = NULL;
    }
}//end PathPairs destructor



Processes::Processes():
    numberOfProcesses(0)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_trace, "Inside Processes Constructor");
#endif
    process = NULL;
}// end Processes constructor

Processes::~Processes()
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_trace, "Processes Destructor Called");
#endif
    if (process != NULL)
    {
        delete[] process;
        process = NULL;
    }
}//end Processes destructor


JobOption::JobOption():
    requestedStartTime("")
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_trace, "Inside JobOption Constructor");
#endif
    maxTime = NULL;
    dependencies = NULL;
    requiredDirectories = NULL;
    requiredFiles = NULL;
    directoriesToMake = NULL;
    filesToMake = NULL;
    inputDirectoriesToMove = NULL;
    inputFilesToMove = NULL;
    outputFilesToMove = NULL;
    outputDirectoriesToMove = NULL;
    filesToDelete = NULL;
    directoriesToDelete = NULL;
    processesToKill = NULL;
    otherOptions = NULL;
}// end JobOption constructor

JobOption::~JobOption()
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_trace, "JobOption Destructor Called");
#endif
    if (maxTime != NULL) delete maxTime;
    maxTime = NULL;
    if (dependencies != NULL) delete dependencies;
    dependencies = NULL;
    if (requiredDirectories != NULL) delete requiredDirectories;
    requiredDirectories = NULL;
    if (requiredFiles != NULL) delete requiredFiles;
    requiredFiles = NULL;
    if (directoriesToMake != NULL) delete directoriesToMake;
    directoriesToMake = NULL;
    if (filesToMake != NULL) delete filesToMake;
    filesToMake = NULL;
    if (inputDirectoriesToMove != NULL) delete inputDirectoriesToMove;
    inputDirectoriesToMove = NULL;
    if (inputFilesToMove != NULL) delete inputFilesToMove;
    inputFilesToMove = NULL;
    if (outputDirectoriesToMove != NULL) delete outputDirectoriesToMove;
    outputDirectoriesToMove = NULL;
    if (outputFilesToMove != NULL) delete outputFilesToMove;
    outputFilesToMove = NULL;
    if (filesToDelete != NULL) delete filesToDelete;
    filesToDelete = NULL;
    if (directoriesToDelete != NULL) delete directoriesToDelete;
    directoriesToDelete = NULL;
    if (processesToKill != NULL) delete processesToKill;
    processesToKill = NULL;
    if (otherOptions != NULL) delete otherOptions;
    otherOptions = NULL;
}//end JobOption destructor


InitVarValue::InitVarValue():
    idx (-1),
    name (""),
    value (OSNaN())
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_trace, "Inside InitVarValue Constructor");
#endif
}// end InitVarValue constructor

InitVarValue::~InitVarValue()
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_trace, "InitVarValue Destructor Called");
#endif
}//end InitVarValue destructor


InitVariableValues::InitVariableValues():
    numberOfVar (0)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_trace, "Inside InitVariableValues Constructor");
#endif
    var = NULL;
}// end InitVariableValues constructor

InitVariableValues::~InitVariableValues()
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_trace, "InitVariableValues Destructor Called");
#endif
    int i;
    if (var != NULL)
    {
        for (i=0; i < numberOfVar; i++)
        {
            delete var[i];
            var[i] = NULL;
        }
        delete[] var;
        var = NULL;
    }
}//end InitVariableValues destructor


InitVarValueString::InitVarValueString():
    idx (-1),
    name (""),
    value ("")
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_trace, "Inside InitVarValueString Constructor");
#endif
}// end InitVarValueString constructor

InitVarValueString::~InitVarValueString()
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_trace, "InitVarValueString Destructor Called");
#endif
}//end InitVarValueString destructor


InitVariableValuesString::InitVariableValuesString():
    numberOfVar (0)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_trace, "Inside InitVariableValuesString Constructor");
#endif
    var = NULL;
}// end InitVariableValuesString constructor

InitVariableValuesString::~InitVariableValuesString()
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_trace, "InitVariableValuesString Destructor Called");
#endif
    int i;
    if (var != NULL)
    {
        for (i=0; i < numberOfVar; i++)
        {
            delete var[i];
            var[i] = NULL;
        }
        delete[] var;
        var = NULL;
    }
}//end InitVariableValues destructor

InitBasStatus::InitBasStatus():
    idx (-1),
    value ("unknown")
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_trace, "Inside InitBasStatus Constructor");
#endif
}// end InitBasStatus constructor

InitBasStatus::~InitBasStatus()
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_trace, "InitBasStatus Destructor Called");
#endif
}//end InitBasStatus destructor

InitialBasisStatus::InitialBasisStatus():
    numberOfVar (0)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_trace, "Inside InitialBasisStatus Constructor");
#endif
    var = NULL;
}// end InitialBasisStatus constructor

InitialBasisStatus::~InitialBasisStatus()
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_trace, "InitialBasisStatus Destructor Called");
#endif
    if (var != NULL)
    {
        int i;
        for (i=0; i < numberOfVar; i++)
        {
            delete var[i];
            var[i] = NULL;
        }
        delete[] var;
        var = NULL;
    }
}//end InitialBasisStatus destructor

BranchingWeight::BranchingWeight():
    idx (-1),
    name (""),
    value (0.0)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_trace, "Inside BranchingWeight Constructor");
#endif
}// end BranchingWeight constructor

BranchingWeight::~BranchingWeight()
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_trace, "BranchingWeight Destructor Called");
#endif
}//end BranchingWeight destructor


IntegerVariableBranchingWeights::IntegerVariableBranchingWeights():
    numberOfVar (0)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_trace, "Inside IntegerVariableBranchingWeights Constructor");
#endif
    var = NULL;
}// end IntegerVariableBranchingWeights constructor

IntegerVariableBranchingWeights::~IntegerVariableBranchingWeights()
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_trace, "IntegerVariableBranchingWeights Destructor Called");
#endif
    if (var != NULL)
    {
        int i;
        for (i=0; i < numberOfVar; i++)
        {
            delete var[i];
            var[i] = NULL;
        }
        delete[] var;
        var = NULL;
    }
}//end IntegerVariableBranchingWeights destructor

SOSWeights::SOSWeights():
    sosIdx (-1),
    groupWeight (1.0),
    numberOfVar (0)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_trace, "Inside SOSWeights Constructor");
#endif
    var = NULL;
}// end SOSWeights constructor

SOSWeights::~SOSWeights()
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_trace, "SOSWeights Destructor Called");
#endif
    if (var != NULL)
    {
        int i;
        for (i=0; i < numberOfVar; i++)
        {
            delete var[i];
            var[i] = NULL;
        }
        delete[] var;
        var = NULL;
    }
}//end SOSWeights destructor

SOSVariableBranchingWeights::SOSVariableBranchingWeights():
    numberOfSOS (0)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_trace, "Inside SOSVariableBranchingWeights Constructor");
#endif
    sos = NULL;
}// end SOSVariableBranchingWeights constructor

SOSVariableBranchingWeights::~SOSVariableBranchingWeights()
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_trace, "SOSVariableBranchingWeights Destructor Called");
#endif
    if (sos != NULL)
    {
        int i;
        for (i=0; i < numberOfSOS; i++)
        {
            delete sos[i];
            sos[i] = NULL;
        }
        delete[] sos;
        sos = NULL;
    }
}//end SOSVariableBranchingWeights destructor

OtherVarOption::OtherVarOption():
    idx (0),
    name (""),
    value (""),
    lbValue (""),
    ubValue ("")
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_trace, "Inside OtherVarOption Constructor");
#endif
}// end OtherVarOption constructor

OtherVarOption::~OtherVarOption()
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_trace, "OtherVarOption Destructor Called");
#endif
}//end OtherVarOption destructor

#if 0
OtherVariableOption::OtherVariableOption():
    numberOfVar(0),
    numberOfEnumerations(0),
    name (""),
    value (""),
    solver(""),
    category (""),
    type (""),
    description (""),

    varType (""),
    enumType ("")
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_trace, "Inside OtherVariableOption Constructor");
#endif
    var = NULL;
    enumeration = NULL;
}// end OtherVariableOption constructor

OtherVariableOption::~OtherVariableOption()
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_trace, "OtherVariableOption Destructor Called");
#endif
    if (var != NULL)
    {
        for (int i=0; i < numberOfVar; i++)
        {
            delete var[i];
            var[i] = NULL;
        }
        delete[] var;
        var = NULL;
    }
    if (enumeration != NULL)
    {
        for (int i=0; i < numberOfEnumerations; i++)
        {
            delete enumeration[i];
            enumeration[i] = NULL;
        }
        delete[] enumeration;
        enumeration = NULL;
    }
}//end OtherVariableOption destructor
#endif

VariableOption::VariableOption():
    numberOfOtherVariableOptions(0)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_trace, "Inside VariableOption Constructor");
#endif
    initialVariableValues = NULL;
    initialVariableValuesString = NULL;
    initialBasisStatus = NULL;
    integerVariableBranchingWeights = NULL;
    sosVariableBranchingWeights = NULL;
    other = NULL;
}// end VariableOption constructor

VariableOption::~VariableOption()
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_trace, "VariableOption Destructor Called");
#endif
    if (initialVariableValues != NULL) delete initialVariableValues;
    initialVariableValues = NULL;
    if (initialVariableValuesString != NULL) delete initialVariableValuesString;
    initialVariableValuesString = NULL;
    if (initialBasisStatus != NULL) delete initialBasisStatus;
    initialBasisStatus = NULL;
    if (integerVariableBranchingWeights != NULL) delete integerVariableBranchingWeights;
    integerVariableBranchingWeights = NULL;
    if (sosVariableBranchingWeights != NULL) delete sosVariableBranchingWeights;
    sosVariableBranchingWeights = NULL;
    if (other != NULL)
    {
        int i;
        for (i=0; i < numberOfOtherVariableOptions; i++)
        {
            if (other[i] != NULL)
                delete other[i];
            other[i] = NULL;

        };
        delete[] other;
        other = NULL;
    };
}//end VariableOption destructor


InitObjValue::InitObjValue():
    idx (-1),
    name (""),
    value (OSNaN())
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_trace, "Inside InitObjValue Constructor");
#endif
}// end InitObjValue constructor

InitObjValue::~InitObjValue()
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_trace, "InitObjValue Destructor Called");
#endif
}//end InitObjValue destructor


InitObjectiveValues::InitObjectiveValues():
    numberOfObj (0)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_trace, "Inside InitObjectiveValues Constructor");
#endif
    obj = NULL;
}// end InitObjectiveValues constructor

InitObjectiveValues::~InitObjectiveValues()
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_trace, "InitObjectiveValues Destructor Called");
#endif
    if (obj != NULL)
    {
        int i;
        for (i=0; i < numberOfObj; i++)
        {
            delete obj[i];
            obj[i] = NULL;
        }
        delete[] obj;
        obj = NULL;
    };
}//end InitObjectiveValues destructor


InitObjBound::InitObjBound():
    idx (-1),
    name (""),
    lbValue (-OSDBL_MAX),
    ubValue ( OSDBL_MAX)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_trace, "Inside InitObjBound Constructor");
#endif
}// end  constructor  template

InitObjBound::~InitObjBound()
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_trace, "InitObjBound Destructor Called");
#endif
}//end InitObjBound destructor


InitObjectiveBounds::InitObjectiveBounds():
    numberOfObj (0)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_trace, "Inside InitObjectiveBounds Constructor");
#endif
    obj = NULL;
}// end InitObjectiveBounds constructor

InitObjectiveBounds::~InitObjectiveBounds()
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_trace, "InitObjectiveBounds Destructor Called");
#endif
    if (obj != NULL)
    {
        int i;
        for (i=0; i < numberOfObj; i++)
        {
            delete obj[i];
            obj[i] = NULL;
        }
        delete[] obj;
        obj = NULL;
    };
}//end InitObjectiveBounds destructor


OtherObjOption::OtherObjOption():
    idx (-1),
    name (""),
    value (""),
    lbValue (""),
    ubValue ("")
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_trace, "Inside OtherObjOption Constructor");
#endif
}// end OtherObjOption constructor

OtherObjOption::~OtherObjOption()
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_trace, "OtherObjOption Destructor Called");
#endif
}//end OtherObjOption destructor

#if 0
OtherObjectiveOption::OtherObjectiveOption():
    numberOfObj(0),
    numberOfEnumerations(0),
    name (""),
    value (""),
    solver(""),

    category (""),
    type (""),
    description (""),
    objType (""),
    enumType ("")
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_trace, "Inside OtherObjectiveOption Constructor");
#endif
    obj = NULL;
    enumeration = NULL;
}// end OtherObjectiveOption constructor

OtherObjectiveOption::~OtherObjectiveOption()
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_trace, "OtherObjectiveOption Destructor Called");
#endif
    if (obj != NULL)
    {
        for (int i=0; i < numberOfObj; i++)
        {
            delete obj[i];
            obj[i] = NULL;
        }
        delete[] obj;
        obj = NULL;
    }
    if (enumeration != NULL)
    {
        for (int i=0; i < numberOfEnumerations; i++)
        {
            delete enumeration[i];
            enumeration[i] = NULL;
        }
        delete[] enumeration;
        enumeration = NULL;
    }
}//end OtherObjectiveOption destructor
#endif

ObjectiveOption::ObjectiveOption():
    numberOfOtherObjectiveOptions (0)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_trace, "Inside ObjectiveOption Constructor");
#endif
    initialObjectiveValues = NULL;
    initialObjectiveBounds = NULL;
    initialBasisStatus = NULL;
    other = NULL;
}// end ObjectiveOption constructor

ObjectiveOption::~ObjectiveOption()
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_trace, "ObjectiveOption Destructor Called");
#endif
    if (initialObjectiveValues != NULL) delete initialObjectiveValues;
    initialObjectiveValues = NULL;
    if (initialObjectiveBounds != NULL) delete initialObjectiveBounds;
    initialObjectiveBounds = NULL;
    if (initialBasisStatus != NULL) delete initialBasisStatus;
    initialBasisStatus = NULL;
    if (other != NULL)
    {
        int i;
        for (i=0; i < numberOfOtherObjectiveOptions; i++)
        {
            delete other[i];
            other[i] = NULL;
        }
        delete[] other;
        other = NULL;
    }
}//end ObjectiveOption destructor


InitConValue::InitConValue():
    idx (0),
    name (""),
    value (OSNaN())
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_trace, "Inside InitConValue Constructor");
#endif
}// end InitConValue constructor

InitConValue::~InitConValue()
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_trace, "InitConValue Destructor Called");
#endif
}//end InitConValue destructor


InitConstraintValues::InitConstraintValues():
    numberOfCon (0)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_trace, "Inside InitConstraintValues Constructor");
#endif
    con = NULL;
}// end InitConstraintValues constructor

InitConstraintValues::~InitConstraintValues()
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_trace, "InitConstraintValues Destructor Called");
#endif
    if (con != NULL)
    {
        int i;
        for (i=0; i < numberOfCon; i++)
        {
            delete con[i];
            con[i] = NULL;
        }
        delete[] con;
        con = NULL;
    };
}//end InitConstraintValues destructor


InitDualVarValue::InitDualVarValue():
    idx (0),
    name (""),
    lbDualValue (0.0),
    ubDualValue (0.0)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_trace, "Inside InitDualVarValue Constructor");
#endif
}// end InitDualVarValue constructor

InitDualVarValue::~InitDualVarValue()
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_trace, "InitDualVarValue Destructor Called");
#endif
}//end InitDualVarValue destructor


InitDualVariableValues::InitDualVariableValues():
    numberOfCon (0)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_trace, "Inside InitDualVariableValues Constructor");
#endif
    con = NULL;
}// end InitDualVariableValues constructor

InitDualVariableValues::~InitDualVariableValues()
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_trace, "InitDualVariableValues Destructor Called");
#endif
    if (con != NULL)
    {
        int i;
        for (i=0; i < numberOfCon; i++)
        {
            delete con[i];
            con[i] = NULL;
        }
        delete[] con;
        con = NULL;
    };
}//end InitDualVariableValues destructor


OtherConOption::OtherConOption():
    idx (0),
    name (""),
    value (""),
    lbValue (""),
    ubValue ("")
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_trace, "Inside OtherConOption Constructor");
#endif
}// end OtherConOption constructor

OtherConOption::~OtherConOption()
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_trace, "OtherConOption Destructor Called");
#endif
}//end OtherConOption destructor

#if 0
OtherConstraintOption::OtherConstraintOption():
    numberOfCon(0),
    numberOfEnumerations(0),
    name (""),
    value (""),
    solver(""),
    category (""),
    type (""),
    description (""),
    conType (""),
    enumType ("")
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_trace, "Inside OtherConstraintOption Constructor");
#endif
    con = NULL;
    enumeration = NULL;
}// end OtherConstraintOption constructor

OtherConstraintOption::~OtherConstraintOption()
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_trace, "OtherConstraintOption Destructor Called");
#endif
    if (con != NULL)
    {
        for (int i=0; i < numberOfCon; i++)
        {
            if (con[i]!= NULL) delete con[i];
            con[i] = NULL;
        }
        delete[] con;
        con = NULL;
    }
    if (enumeration != NULL)
    {
        for (int i=0; i < numberOfEnumerations; i++)
        {
            delete enumeration[i];
            enumeration[i] = NULL;
        }
        delete[] enumeration;
        enumeration = NULL;
    }
}//end OtherConstraintOption destructor
#endif

ConstraintOption::ConstraintOption():
    numberOfOtherConstraintOptions (0)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_trace, "Inside ConstraintOption Constructor");
#endif
    initialConstraintValues = NULL;
    initialDualValues = NULL;
    initialBasisStatus = NULL;
    other = NULL;
}// end ConstraintOption constructor

ConstraintOption::~ConstraintOption()
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_trace, "ConstraintOption Destructor Called");
#endif
    if (initialConstraintValues != NULL) delete initialConstraintValues;
    initialConstraintValues = NULL;
    if (initialDualValues != NULL) delete initialDualValues;
    initialDualValues = NULL;
    if (initialBasisStatus != NULL) delete initialBasisStatus;
    initialBasisStatus = NULL;
    if (other != NULL)
    {
        int i;
        for (i=0; i < numberOfOtherConstraintOptions; i++)
        {
            delete other[i];
            other[i] = NULL;
        }
        delete[] other;
        other = NULL;
    }
}//end ConstraintOption destructor


InitMatrixVariableValues::InitMatrixVariableValues():
    numberOfMatrixVar(0),
    matrixVar(NULL)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_trace,
        "Inside InitMatrixVariableValues Constructor");
#endif
}// end InitMatrixVariableValues constructor

InitMatrixVariableValues::~InitMatrixVariableValues()
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_trace, 
        "InitMatrixVariableValues Destructor Called");
#endif
    if (numberOfMatrixVar > 0)
        if (matrixVar != NULL)
        {
            for (int i=0; i< numberOfMatrixVar; ++i)
                if (matrixVar[i] != NULL)
                    delete matrixVar[i];
            delete [] matrixVar;
            matrixVar = NULL;
        }
}//end InitMatrixVariableValues destructor


MatrixVariableOption::MatrixVariableOption():
    numberOfOtherMatrixVariableOptions(0)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_trace, "Inside MatrixVariableOption Constructor");
#endif
    initialMatrixVariableValues = NULL;
    initialMatrixVariableDualValues = NULL;
    other = NULL;
}// end MatrixVariableOption constructor

MatrixVariableOption::~MatrixVariableOption()
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_trace, "MatrixVariableOption Destructor Called");
#endif
    if (initialMatrixVariableValues != NULL)
    {
        delete initialMatrixVariableValues;
        initialMatrixVariableValues = NULL;
    }

    if (initialMatrixVariableDualValues != NULL)
    {
        delete initialMatrixVariableDualValues;
        initialMatrixVariableDualValues = NULL;
    }

    if (numberOfOtherMatrixVariableOptions > 0)
        if (other != NULL)
        {
            for (int i=0; i< numberOfOtherMatrixVariableOptions; ++i)
                if (other[i] != NULL)
                    delete other[i];
            delete [] other;
            other = NULL;
        }
}//end MatrixVariableOption destructor


MatrixProgrammingOption::MatrixProgrammingOption():
    numberOfOtherMatrixProgrammingOptions(0)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_trace, "Inside MatrixProgrammingOption Constructor");
#endif
    matrixVariables = NULL;
    matrixObjectives = NULL;
    matrixConstraints = NULL;
    other = NULL;
}// end MatrixProgrammingOption constructor

MatrixProgrammingOption::~MatrixProgrammingOption()
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_trace, "MatrixProgrammingOption Destructor Called");
#endif
    if (matrixVariables != NULL)
    {
        delete matrixVariables;
        matrixVariables = NULL;
    }
#if 0
    if (matrixObjectives != NULL)
    {
        delete matrixObjectives;
        matrixObjectives = NULL;
    }

    if (matrixConstraints != NULL)
    {
        delete matrixConstraints;
        matrixConstraints = NULL;
    }
#endif
    if (numberOfOtherMatrixProgrammingOptions > 0)
        if (other != NULL)
        {
            for (int i=0; i< numberOfOtherMatrixProgrammingOptions; ++i)
                if (other[i] != NULL)
                    delete other[i];
            delete [] other;
            other = NULL;
        }
}//end MatrixProgrammingOption destructor


SolverOptions::SolverOptions():
    numberOfSolverOptions(0)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_trace, "Inside SolverOptions Constructor");
#endif
    solverOption = NULL;
}// end SolverOptions constructor

SolverOptions::~SolverOptions()
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_trace, "SolverOptions Destructor Called");
#endif
    if (solverOption != NULL)
    {
        int i;
        for (i=0; i<numberOfSolverOptions; i++)
        {
            delete solverOption[i];
            solverOption[i] = NULL;
        }
        delete[] solverOption;
        solverOption = NULL;
    }
}//end SolverOptions destructor


OptimizationOption::OptimizationOption():
    numberOfVariables (0),
    numberOfObjectives (0),
    numberOfConstraints (0),
    numberOfVariablesIsSet (false),
    numberOfObjectivesIsSet (false),
    numberOfConstraintsIsSet (false)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_trace, "Inside OptimizationOption Constructor");
#endif
    matrices = NULL;
    variables = NULL;
    objectives = NULL;
    constraints = NULL;
    solverOptions = NULL;
}// end OptimizationOption constructor

OptimizationOption::~OptimizationOption()
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_trace, "OptimizationOption Destructor Called");
#endif
    if (variables != NULL) delete variables;
    variables = NULL;
    if (objectives != NULL) delete objectives;
    objectives = NULL;
    if (constraints != NULL) delete constraints;
    constraints = NULL;
    if (solverOptions != NULL) delete solverOptions;
    solverOptions = NULL;
}//end OptimizationOption destructor


OSOption::OSOption()
//(initializations)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_trace, "Inside OSOption Constructor");
#endif

    optionHeader = NULL;
    general = NULL;
    system = NULL;
    service = NULL;
    job = NULL;
    optimization = NULL;
    m_mdInitVarValuesDense = NULL;
    m_mdInitVarValuesStringDense = NULL;
    m_mdInitBasisStatusDense = NULL;
    m_mdIntegerVariableBranchingWeightsDense = NULL;
    m_mdInitObjValuesDense = NULL;
    m_mdInitObjLowerBoundsDense = NULL;
    m_mdInitObjUpperBoundsDense = NULL;
    m_mdInitConValuesDense = NULL;
    m_mdInitDualVarLowerBoundsDense = NULL;
    m_mdInitDualVarUpperBoundsDense = NULL;
}// end OSOption constructor

OSOption::~OSOption()
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_trace, "OSOption Destructor Called");
#endif
    if (optionHeader != NULL) delete optionHeader;
    optionHeader = NULL;
    if (general != NULL) delete general;
    general = NULL;
    if (system != NULL) delete system;
    system = NULL;
    if (service != NULL) delete service;
    service = NULL;
    if (job != NULL) delete job;
    job = NULL;
    if (optimization != NULL) delete optimization;
    optimization = NULL;

    if (m_mdInitVarValuesDense != NULL)
        delete[] m_mdInitVarValuesDense;
    m_mdInitVarValuesDense = NULL;

    if (m_mdInitVarValuesStringDense != NULL)
        delete[] m_mdInitVarValuesStringDense;
    m_mdInitVarValuesStringDense = NULL;

    if (m_mdInitBasisStatusDense != NULL)
        delete[] m_mdInitBasisStatusDense;
    m_mdInitBasisStatusDense = NULL;

    if (m_mdIntegerVariableBranchingWeightsDense != NULL)
        delete[] m_mdIntegerVariableBranchingWeightsDense;
    m_mdIntegerVariableBranchingWeightsDense = NULL;

    if (m_mdInitObjValuesDense != NULL)
        delete[] m_mdInitObjValuesDense;
    m_mdInitObjValuesDense = NULL;

    if (m_mdInitObjLowerBoundsDense != NULL)
        delete[] m_mdInitObjLowerBoundsDense;
    m_mdInitObjLowerBoundsDense = NULL;

    if (m_mdInitObjUpperBoundsDense != NULL)
        delete[] m_mdInitObjUpperBoundsDense;
    m_mdInitObjUpperBoundsDense = NULL;

    if (m_mdInitConValuesDense != NULL)
        delete[] m_mdInitConValuesDense;
    m_mdInitConValuesDense = NULL;

    if (m_mdInitDualVarLowerBoundsDense != NULL)
        delete[] m_mdInitDualVarLowerBoundsDense;
    m_mdInitDualVarLowerBoundsDense = NULL;

    if (m_mdInitDualVarUpperBoundsDense != NULL)
        delete[] m_mdInitDualVarUpperBoundsDense;
    m_mdInitDualVarUpperBoundsDense = NULL;
}//end OSOption destructor




/****************************************************************
 * get() methods
 ****************************************************************/

/***********************************
 * get() methods that return strings
 ***********************************/

/**
 * get the file name (in <optionHeader> element)
 */
std::string  OSOption::getFileName()
{
    if (this->optionHeader != NULL)
        return this->optionHeader->name;

    return "";
}//getFileName

/**
 * get the file source (in <optionHeader> element)
 */
std::string  OSOption::getFileSource()
{
    if (this->optionHeader != NULL)
        return this->optionHeader->source;

    return "";
}//getFileSource

/**
 * get the file description (in <optionHeader> element)
 */
std::string  OSOption::getFileDescription()
{
    if (this->optionHeader != NULL)
        return this->optionHeader->description;

    return "";
}//getFileDescription

/**
 * get the file creator (in <optionHeader> element)
 */
std::string  OSOption::getFileCreator()
{
    if (this->optionHeader != NULL)
        return this->optionHeader->fileCreator;

    return "";
}//getFileCreator

/**
 * get the file licence information (in <optionHeader> element)
 */
std::string  OSOption::getFileLicence()
{
    if (this->optionHeader != NULL)
        return this->optionHeader->licence;

    return "";
}//getFileLicence


/**
 * get the service URI (in <general> element)
 */
std::string  OSOption::getServiceURI()
{
    if (this->general != NULL)
        return this->general->serviceURI;

    return "";
}//getServiceURI

/**
 * get the service name (in <general> element)
 */
std::string  OSOption::getServiceName()
{
    if (this->general != NULL)
        return this->general->serviceName;

    return "";
}//getServiceName

/**
 * get the instance name (in <general> element)
 */
std::string  OSOption::getInstanceName()
{
    if (this->general != NULL)
        return this->general->instanceName;

    return "";
}//getInstanceName

/**
 * get the instance location (in <general> element)
 */
std::string  OSOption::getInstanceLocation()
{
    if (this->general != NULL)
        if (this->general->instanceLocation != NULL)
            return this->general->instanceLocation->value;

    return "";
}//getInstanceLocation

/**
 * get the instance location type (in <general> element)
 */
std::string  OSOption::getInstanceLocationType()
{
    if (this->general != NULL)
        if (this->general->instanceLocation != NULL)
            return this->general->instanceLocation->locationType;

    return "";
}//getLocationType

/**
 * get the job ID (in <general> element)
 */
std::string  OSOption::getJobID()
{
    if (this->general != NULL)
        return this->general->jobID;

    return "";
}//getJobID

/**
 * get the name of the solver to be invoked (in <general> element)
 */
std::string  OSOption::getSolverToInvoke()
{
    if (this->general != NULL)
        return this->general->solverToInvoke;

    return "";
}//getSolverToInvoke

/**
 * get the license information (in <general> element)
 */
std::string  OSOption::getLicense()
{
    if (this->general != NULL)
        return this->general->license;

    return "";
}//getLicense

/**
 * get the user name (in <general> element)
 */
std::string  OSOption::getUserName()
{
    if (this->general != NULL)
        return this->general->userName;

    return "";
}//getUserName

/**
 * get the password (in <general> element)
 */
std::string  OSOption::getPassword()
{
    if (this->general != NULL)
        return this->general->password;

    return "";
}//getPassword

/**
 * get the contact information (in <general> element)
 */
std::string  OSOption::getContact()
{
    if (this->general != NULL)
        if (this->general->contact != NULL)
            return this->general->contact->value;

    return "";
}//getContact

/**
 * get the transport type (in <general> element)
 */
std::string  OSOption::getContactTransportType()
{
    if (this->general != NULL)
        if (this->general->contact != NULL)
            return this->general->contact->transportType;

    return "";
}//getContactTransportType

/**
 * get the disk space units (in <system> element)
 */
std::string  OSOption::getMinDiskSpaceUnit()
{
    if (this->system != NULL)
        if (this->system->minDiskSpace != NULL)
            return this->system->minDiskSpace->unit;

    return "";
}//getMinDiskSpaceUnit

/**
 * get the disk space description (in <system> element)
 */
std::string  OSOption::getMinDiskSpaceDescription()
{
    if (this->system != NULL)
        if (this->system->minDiskSpace != NULL)
            return this->system->minDiskSpace->description;

    return "";
}//getMinDiskSpaceDescription

/**
 * get the memory units (in <system> element)
 */
std::string  OSOption::getMinMemoryUnit()
{
    if (this->system != NULL)
        if (this->system->minMemorySize != NULL)
            return this->system->minMemorySize->unit;

    return "";
}//getMinMemory

/**
 * get the memory description (in <system> element)
 */
std::string  OSOption::getMinMemoryDescription()
{
    if (this->system != NULL)
        if (this->system->minMemorySize != NULL)
            return this->system->minMemorySize->description;

    return "";
}//getMinMemoryDescription

/**
 * get the CPU speed units (in <system> element)
 */
std::string  OSOption::getMinCPUSpeedUnit()
{
    if (this->system != NULL)
        if (this->system->minCPUSpeed != NULL)
            return this->system->minCPUSpeed->unit;

    return "";
}//getMinCPUSpeed

/**
 * get the CPU speed description (in <system> element)
 */
std::string  OSOption::getMinCPUSpeedDescription()
{
    if (this->system != NULL)
        if (this->system->minCPUSpeed != NULL)
            return this->system->minCPUSpeed->description;

    return "";
}//getMinCPUSpeedDescription

/**
 * get the CPU description (in <system> element)
 */
std::string  OSOption::getMinCPUNumberDescription()
{
    if (this->system != NULL)
        if (this->system->minCPUNumber != NULL)
            return this->system->minCPUNumber->description;

    return "";
}//getMinCPUNumberDescription

/**
 * get the service type (in <service> element)
 */
std::string  OSOption::getServiceType()
{
    if (this->service != NULL)
        return this->service->type;

    return "";
}//getServiceType

/**
 * get the time unit (in <job> element)
 */
std::string  OSOption::getMaxTimeUnit()
{
    if (this->job != NULL)
        if (this->job->maxTime != NULL)
            return this->job->maxTime->unit;

    return "";
}//getMaxTimeUnit

/**
 * get the requested start time (in <job> element)
 */
std::string  OSOption::getRequestedStartTime()
{
    if (this->job != NULL)
        return this->job->requestedStartTime;

    return "";
}//getRequestedStartTime

/**
 * get the value of a string-valued option
 * @param optionName The name of the option
 * @return the value of the option optionName
 * @note This function returns the empty string "" if optionName is not found
 */
std::string  OSOption::getOptionStr(std::string optionName)
{
    if (optionName == "serviceURI")
        return this->getServiceURI();

    if (optionName == "serviceName")
        return this->getServiceName();

    if (optionName == "instanceName")
        return this->getInstanceName();

    if (optionName == "instanceLocation")
        return this->getInstanceLocation();

    if (optionName == "instanceLocationType")
        return this->getInstanceLocationType();

    if (optionName == "jobID")
        return this->getJobID();

    if (optionName == "solverToInvoke")
        return this->getSolverToInvoke();

    if (optionName == "license")
        return this->getLicense();

    if (optionName == "userName")
        return this->getUserName();

    if (optionName == "password")
        return this->getPassword();

    if (optionName == "contact")
        return this->getContact();

    if (optionName == "contactTransportType")
        return this->getContactTransportType();

    if (optionName == "minDiskSpaceUnit")
        return this->getMinDiskSpaceUnit();

    if (optionName == "minMemoryUnit")
        return this->getMinMemoryUnit();

    if (optionName == "minCPUSpeedUnit")
        return this->getMinCPUSpeedUnit();

    if (optionName == "serviceType")
        return this->getServiceType();

    if (optionName == "maxTimeUnit")
        return this->getMaxTimeUnit();

    if (optionName == "requestedStartTime")
        return this->getRequestedStartTime();

    return "";
}//getOptionStr

/***********************************
 * get() methods that return doubles
 ***********************************/

/**
 * get the minimum disk space required (in <system> element)
 */
double  OSOption::getMinDiskSpace()
{
    if (this->system != NULL)
        if (this->system->minDiskSpace != NULL)
            return this->system->minDiskSpace->value;

    return 0;
}//getMinDiskSpace

/**
 * get the minimum memory required (in <system> element)
 */
double  OSOption::getMinMemorySize()
{
    if (this->system != NULL)
        if (this->system->minMemorySize != NULL)
            return this->system->minMemorySize->value;

    return 0;
}//getMinMemorySize

/**
 * get the minimum CPU speed required (in <system> element)
 */
double  OSOption::getMinCPUSpeed()
{
    if (this->system != NULL)
        if (this->system->minCPUSpeed != NULL)
            return this->system->minCPUSpeed->value;

    return 0;
}//getMinCPUSpeed

/**
 * get the maximum time allowed (in <job> element)
 */
double  OSOption::getMaxTime()
{
    if (this->job != NULL)
        if (this->job->maxTime != NULL)
            return job->maxTime->value;

    return 0;
}//getMaxTime

/**
 * get the value of a double-valued option
 * @param optionName The name of the option
 * @return the value of the option optionName
 * @note returns 0 if optionName is not found
 */
double  OSOption::getOptionDbl(std::string optionName)
{
    if (optionName == "minDiskSpace")
        return this->getMinDiskSpace();

    if (optionName == "minMemory")
        return this->getMinMemorySize();

    if (optionName == "minCPUSpeed")
        return this->getMinCPUSpeed();

    if (optionName == "maxTime")
        return this->getMaxTime();

    return 0;
}//getOptionDbl

/**
 * get() methods that return integers
 */

/**
 * get the minimum number of CPUs required (in <system> element)
 */
int  OSOption::getMinCPUNumber()
{
    if (this->system != NULL)
        return this->system->minCPUNumber->value;

    return 0;
}//getMinCPUNumber

/**
 * get the number of other <general> options
 */
int  OSOption::getNumberOfOtherGeneralOptions()
{
    if (this->general != NULL)
        if (this->general->otherOptions != NULL)
            return this->general->otherOptions->numberOfOtherOptions;

    return 0;
}//getNumberOfOtherGeneralOptions

/**
 * get the number of other <system> options
 */
int  OSOption::getNumberOfOtherSystemOptions()
{
    if (this->system != NULL)
        if (this->system->otherOptions != NULL)
            return this->system->otherOptions->numberOfOtherOptions;

    return 0;
}//getNumberOfOtherSystemOptions

/**
 * get the number of other <service> options
 */
int  OSOption::getNumberOfOtherServiceOptions()
{
    if (this->service != NULL)
        if (this->service->otherOptions != NULL)
            return this->service->otherOptions->numberOfOtherOptions;

    return 0;
}//getNumberOfOtherServiceOptions

/**
 * get the number of other <job> options
 */
int  OSOption::getNumberOfOtherJobOptions()
{
    if (this->job != NULL)
        if (this->job->otherOptions != NULL)
            return this->job->otherOptions->numberOfOtherOptions;

    return 0;
}//getNumberOfOtherJobOptions

/**
 * get the number of job dependencies (in <job> element)
 */
int  OSOption::getNumberOfJobDependencies()
{
    if (this->job != NULL)
        if (this->job->dependencies != NULL)
            return this->job->dependencies->numberOfJobIDs;

    return 0;
}//getNumberOfJobDependencies

/**
 * get the number of required directories (in <job> element)
 */
int  OSOption::getNumberOfRequiredDirectories()
{
    if (this->job != NULL)
        if (this->job->requiredDirectories != NULL)
            return this->job->requiredDirectories->numberOfPaths;

    return 0;
}//getNumberOfRequiredDirectories

/**
 * get the number of required files (in <job> element)
 */
int  OSOption::getNumberOfRequiredFiles()
{
    if (this->job != NULL)
        if (this->job->requiredFiles != NULL)
            return this->job->requiredFiles->numberOfPaths;

    return 0;
}//getNumberOfRequiredFiles

/**
 * get the number of directories to make (in <job> element)
 */
int  OSOption::getNumberOfDirectoriesToMake()
{
    if (this->job != NULL)
        if (this->job->directoriesToMake != NULL)
            return this->job->directoriesToMake->numberOfPaths;

    return 0;
}//getNumberOfDirectoriesToMake

/**
 * get the number of files to create (in <job> element)
 */
int  OSOption::getNumberOfFilesToMake()
{
    if (this->job != NULL)
        if (this->job->filesToMake != NULL)
            return this->job->filesToMake->numberOfPaths;

    return 0;
}//getNumberOfFilesToMake

/**
 * get the number of input directories to move or copy (in <job> element)
 */
int  OSOption::getNumberOfInputDirectoriesToMove()
{
    if (this->job != NULL)
        if (this->job->inputDirectoriesToMove != NULL)
            return this->job->inputDirectoriesToMove->numberOfPathPairs;

    return 0;
}//getNumberOfInputDirectoriesToMove

/**
 * get the number of input files to move or copy (in <job> element)
 */
int  OSOption::getNumberOfInputFilesToMove()
{
    if (this->job != NULL)
        if (this->job->inputFilesToMove != NULL)
            return this->job->inputFilesToMove->numberOfPathPairs;

    return 0;
}//getNumberOfInputFilesToMove

/**
 * get the number of output directories to move or copy (in <job> element)
 */
int  OSOption::getNumberOfOutputDirectoriesToMove()
{
    if (this->job != NULL)
        if (this->job->outputDirectoriesToMove != NULL)
            return this->job->outputDirectoriesToMove->numberOfPathPairs;

    return 0;
}//getNumberOfOutputDirectoriesToMove

/**
 * get the number of output files to move or copy (in <job> element)
 */
int  OSOption::getNumberOfOutputFilesToMove()
{
    if (this->job != NULL)
        if (this->job->outputFilesToMove != NULL)
            return this->job->outputFilesToMove->numberOfPathPairs;

    return 0;
}//getNumberOfOutputFilesToMove

/**
 * get the number of files to delete (in <job> element)
 */
int  OSOption::getNumberOfFilesToDelete()
{
    if (this->job != NULL)
        if (this->job->filesToDelete != NULL)
            return this->job->filesToDelete->numberOfPaths;

    return 0;
}//getNumberOfFilesToDelete

/**
 * get the number of directories to delete (in <job> element)
 */
int  OSOption::getNumberOfDirectoriesToDelete()
{
    if (this->job != NULL)
        if (this->job->directoriesToDelete != NULL)
            return this->job->directoriesToDelete->numberOfPaths;

    return 0;
}//getNumberOfDirectoriesToDelete

/**
 * get the number of processes to kill (in <job> element)
 */
int  OSOption::getNumberOfProcessesToKill()
{
    if (this->job != NULL)
        if (this->job->processesToKill != NULL)
            return this->job->processesToKill->numberOfProcesses;

    return 0;
}//getNumberOfProcessesToKill

/**
 * get the number of variables (in <optimization> element)
 */
int  OSOption::getNumberOfVariables()
{
    if (this->optimization != NULL)
        return this->optimization->numberOfVariables;

    return 0;
}//getNumberOfVariables

/**
 * get whether the number of variables has been set (in <optimization> element)
 */
bool OSOption::getIsSetNumberOfVariables()
{
    if (this->optimization != NULL)
        return this->optimization->numberOfVariablesIsSet;

    return false;
}//getIsSetNumberOfVariables

/**
 * get the number of objectives (in <optimization> element)
 */
int  OSOption::getNumberOfObjectives()
{
    if (this->optimization != NULL)
        return this->optimization->numberOfObjectives;

    return 0;
}//getNumberOfObjectives

/**
 * get whether the number of objectives has been set (in <optimization> element)
 */
bool OSOption::getIsSetNumberOfObjectives()
{
    if (this->optimization != NULL)
        return this->optimization->numberOfObjectivesIsSet;

    return false;
}//getIsSetNumberOfObjectives

/**
 * get the number of constraints (in <optimization> element)
 */
int  OSOption::getNumberOfConstraints()
{
    if (this->optimization != NULL)
        return this->optimization->numberOfConstraints;

    return 0;
}//getNumberOfConstraints

/**
 * get whether the number of constraints has been set (in <optimization> element)
 */
bool OSOption::getIsSetNumberOfConstraints()
{
    if (this->optimization != NULL)
        return this->optimization->numberOfConstraintsIsSet;

    return false;
}//getIsSetNumberOfConstraints


/**
 * get the number of variables that have initial values (in <optimization> element)
 */
int OSOption::getNumberOfInitVarValues()
{
    if (this->optimization != NULL)
    {
        if (this->optimization->variables != NULL)
        {
            if (this->optimization->variables->initialVariableValues != NULL)
            {
                return this->optimization->variables->initialVariableValues->numberOfVar;
            }
        }
    }
    return 0;
}//getNumberOfInitVarValues

/**
 * get the number of string-valued variables that have initial values (in <optimization> element)
 */
int OSOption::getNumberOfInitVarValuesString()
{
    if (this->optimization != NULL)
        if (this->optimization->variables != NULL)
            if (this->optimization->variables->initialVariableValuesString != NULL)
                return this->optimization->variables->initialVariableValuesString->numberOfVar;
    return 0;
}//getNumberOfInitVarValuesString


/**
 * get the number of variables that are given integer branching weights (in <optimization> element)
 */
int OSOption::getNumberOfIntegerVariableBranchingWeights()
{
    if (this->optimization != NULL)
        if (this->optimization->variables != NULL)
            if (this->optimization->variables->integerVariableBranchingWeights != NULL)
                return this->optimization->variables->integerVariableBranchingWeights->numberOfVar;
    return 0;
}//getNumberOfIntegerBranchingWeights

/**
 * get the number of SOS that are given branching weights (in <optimization> element)
 */
int OSOption::getNumberOfSOS()
{
    if (this->optimization != NULL)
        if (this->optimization->variables != NULL)
            if (this->optimization->variables->sosVariableBranchingWeights != NULL)
                return this->optimization->variables->sosVariableBranchingWeights->numberOfSOS;
    return 0;
}//getNumberOfSOS

/**
 * get the number of variables that are given integer branching weights (in <optimization> element)
 */
int OSOption::getNumberOfSOSVarBranchingWeights(int iSOS)
{
    if (this->optimization != NULL)
        if (this->optimization->variables != NULL)
            if (this->optimization->variables->sosVariableBranchingWeights != NULL)
            {
                if (iSOS >= 0 && iSOS < this->optimization->variables->sosVariableBranchingWeights->numberOfSOS)
                    if (this->optimization->variables->sosVariableBranchingWeights->sos[iSOS] != NULL)
                        return this->optimization->variables->sosVariableBranchingWeights->sos[iSOS]->numberOfVar;
            }
    return 0;
}//getNumberOfSOSVarBranchingWeights

/**
 * get the number of other variable options (in <optimization> element)
 */
int OSOption::getNumberOfOtherVariableOptions()
{
    if (this->optimization != NULL)
        if (this->optimization->variables != NULL)
            return this->optimization->variables->numberOfOtherVariableOptions;

    return 0;
}//getNumberOfOtherVariableOptions

/**
 * get the number of objectives for which initial values are given (in <optimization> element)
 */
int OSOption::getNumberOfInitObjValues()
{
    if (this->optimization != NULL)
        if (this->optimization->objectives != NULL)
            if (this->optimization->objectives->initialObjectiveValues != NULL)
                return this->optimization->objectives->initialObjectiveValues->numberOfObj;

    return 0;
}//getNumberOfInitObjValues

/**
 * get the number of objectives for which initial bounds are given (in <optimization> element)
 */
int OSOption::getNumberOfInitObjBounds()
{
    if (this->optimization != NULL)
        if (this->optimization->objectives != NULL)
            if (this->optimization->objectives->initialObjectiveBounds != NULL)
                return this->optimization->objectives->initialObjectiveBounds->numberOfObj;
    return 0;
}//getNumberOfInitObjBounds

/**
 * get the number of other objective options (in <optimization> element)
 */
int OSOption::getNumberOfOtherObjectiveOptions()
{
    if (this->optimization != NULL)
        if (this->optimization->objectives != NULL)
            return this->optimization->objectives->numberOfOtherObjectiveOptions;
    return 0;
}//getNumberOfOtherObjectiveOptions

/**
 * get the number of constraints for which initial values are given (in <optimization> element)
 */
int OSOption::getNumberOfInitConValues()
{
    if (this->optimization != NULL)
        if (this->optimization->constraints != NULL)
            if (this->optimization->constraints->initialConstraintValues != NULL)
                return this->optimization->constraints->initialConstraintValues->numberOfCon;
    return 0;
}//getNumberOfInitConValues

/**
 * get the number of constraints for which initial dual values are given (in <optimization> element)
 */
int OSOption::getNumberOfInitDualVarValues()
{
    if (this->optimization != NULL)
        if (this->optimization->constraints != NULL)
            if (this->optimization->constraints->initialDualValues != NULL)
                return this->optimization->constraints->initialDualValues->numberOfCon;

    return 0;
}//getNumberOfInitDualVarValues

/**
 * get the number of other constraint options (in <optimization> element)
 */
int OSOption::getNumberOfOtherConstraintOptions()
{
    if (this->optimization != NULL)
        if (this->optimization->constraints != NULL)
            return this->optimization->constraints->numberOfOtherConstraintOptions;

    return 0;
}//getNumberOfOtherConstraintOptions

/**
 * get the number of other solver options (in <optimization> element)
 */
int OSOption::getNumberOfSolverOptions()
{
    if (this->optimization != NULL)
        if (this->optimization->solverOptions != NULL)
            return this->optimization->solverOptions->numberOfSolverOptions;

    return 0;
}//getNumberOfSolverOptions

/**
 * get the value of an integer-valued option
 * @param optionName The name of the option
 * @return the value of the option optionName
 * @note This function throws an error if optionName is not found
 */
int  OSOption::getOptionInt(std::string optionName)
{
    if (optionName == "minCPUNumber")
        return this->getMinCPUNumber();

    if (optionName == "numberOfOtherGeneralOptions")
        return this->getNumberOfOtherGeneralOptions();

    if (optionName == "numberOfOtherSystemOptions")
        return this->getNumberOfOtherSystemOptions();

    if (optionName == "numberOfOtherServiceOptions")
        return this->getNumberOfOtherServiceOptions();

    if (optionName == "numberOfOtherJobOptions")
        return this->getNumberOfOtherJobOptions();

    if (optionName == "numberOfJobDependencies")
        return this->getNumberOfJobDependencies();

    if (optionName == "numberOfRequiredDirectories")
        return this->getNumberOfRequiredDirectories();

    if (optionName == "numberOfRequiredFiles")
        return this->getNumberOfRequiredFiles();

    if (optionName == "numberOfDirectoriesToMake")
        return this->getNumberOfDirectoriesToMake();

    if (optionName == "numberOfFilesToMake")
        return this->getNumberOfFilesToMake();

    if (optionName == "numberOfInputDirectoriesToMove")
        return this->getNumberOfInputDirectoriesToMove();

    if (optionName == "numberOfInputFilesToMove")
        return this->getNumberOfInputFilesToMove();

    if (optionName == "numberOfOutputDirectoriesToMove")
        return this->getNumberOfOutputDirectoriesToMove();

    if (optionName == "numberOfOutputFilesToMove")
        return this->getNumberOfOutputFilesToMove();

    if (optionName == "numberOfFilesToDelete")
        return this->getNumberOfFilesToDelete();

    if (optionName == "numberOfDirectoriesToDelete")
        return this->getNumberOfDirectoriesToDelete();

    if (optionName == "numberOfProcessesToKill")
        return this->getNumberOfProcessesToKill();

    if (optionName == "numberOfVariables")
        return this->getNumberOfVariables();

    if (optionName == "numberOfObjectives")
        return this->getNumberOfObjectives();

    if (optionName == "numberOfConstraints")
        return this->getNumberOfConstraints();

    if (optionName == "numberOfInitVarValues")
        return this->getNumberOfInitVarValues();

    if (optionName == "numberOfInitVarValuesString")
        return this->getNumberOfInitVarValuesString();

    if (optionName == "numberOfIntegerVariableBranchingWeights")
        return this->getNumberOfIntegerVariableBranchingWeights();

    if (optionName == "numberOfSOS")
        return this->getNumberOfSOS();

    if (optionName == "numberOfOtherVariableOptions")
        return this->getNumberOfOtherVariableOptions();

    if (optionName == "numberOfInitObjValues")
        return this->getNumberOfInitObjValues();

    if (optionName == "numberOfInitObjBounds")
        return this->getNumberOfInitObjBounds();

    if (optionName == "numberOfOtherObjectiveOptions")
        return this->getNumberOfOtherObjectiveOptions();

    if (optionName == "numberOfInitConValues")
        return this->getNumberOfInitConValues();

    if (optionName == "numberOfInitDualVarValues")
        return this->getNumberOfInitDualVarValues();

    if (optionName == "numberOfOtherConstraintOptions")
        return this->getNumberOfOtherConstraintOptions();

    if (optionName == "numberOfSolverOptions")
        return this->getNumberOfSolverOptions();

    throw ErrorClass("optionName not recognized");
}//getOptionInt


/****************************************************
 * get() methods that return arrays of various kinds
 ****************************************************/

/**
 * get the array of other <general> options
 */
OtherOptionOrResult** OSOption::getOtherGeneralOptions()
{
    if (this->general != NULL)
    {
        if (this->general->otherOptions != NULL)
            return this->general->otherOptions->other;
    }
    return NULL;
}//getOtherGeneralOptions

/**
 * get the array of other <system> options
 */
OtherOptionOrResult** OSOption::getOtherSystemOptions()
{
    if (this->system != NULL)
    {
        if (this->system->otherOptions != NULL)
            return this->system->otherOptions->other;
    }
    return NULL;
}//getOtherSystemOptions

/**
 * get the array of other <service> options
 */
OtherOptionOrResult** OSOption::getOtherServiceOptions()
{
    if (this->service != NULL)
    {
        if (this->service->otherOptions != NULL)
            return this->service->otherOptions->other;
    }
    return NULL;
}//getOtherServiceOptions

/**
 * get the array of other <job> options
 */
OtherOptionOrResult** OSOption::getOtherJobOptions()
{
    if (this->job != NULL)
    {
        if (this->job->otherOptions != NULL)
            return this->job->otherOptions->other;
    }
    return NULL;
}//getOtherJobOptions

/**
 * get the array of other options associated with a category
 * @param category - The name of the option category
 * @return other options associated with the element <"category">
 * @note This function returns NULL if category is not found
 */
OtherOptionOrResult** OSOption::getOtherOptions(std::string category)
{
    if (category == "general")
        return this->getOtherGeneralOptions();

    if (category == "system")
        return this->getOtherSystemOptions();

    if (category == "service")
        return this->getOtherServiceOptions();

    if (category == "job")
        return this->getOtherJobOptions();

    return NULL;
}//getOtherOptions

/**
 * get the array of other options associated with all children of <osol>
 */
OtherOptionOrResult** OSOption::getAllOtherOptions()
{
    OtherOptionOrResult** optionVector = NULL;
    int prev_options[4];
    int num_options[4];
    int num_opt;
    int i;

    for (i = 0; i < 4; i++)
    {
        prev_options[i] = 0;
        num_options[i] = 0;
    }
    if (this->general != NULL)
    {
        if (this->general->otherOptions != NULL)
        {
            num_opt = this->getNumberOfOtherGeneralOptions();
            num_options[0] = num_opt;
        }
    }

    if (this->system != NULL)
    {
        if (this->system->otherOptions != NULL)
        {
            num_opt = this->getNumberOfOtherSystemOptions();
            num_options[1] = num_opt;
        }
    }
    prev_options[1] = prev_options[0] + num_options[0];

    if (this->service != NULL)
    {
        if (this->service->otherOptions != NULL)
        {
            num_opt = this->getNumberOfOtherServiceOptions();
            num_options[2] = num_opt;
        }
    }
    prev_options[2] = prev_options[1] + num_options[1];

    if (this->job != NULL)
    {
        if (this->job->otherOptions != NULL)
        {
            num_opt = this->getNumberOfOtherJobOptions();
            num_options[3] = num_opt;
        }
    }
    prev_options[3] = prev_options[2] + num_options[2];

    num_opt = num_options[0] + num_options[1] + num_options[2] + num_options[3];
    optionVector = new OtherOptionOrResult*[num_opt];

    if (num_options[0] > 0)
    {
        for (i = 0; i < num_options[0]; i++)
        {
            optionVector[prev_options[0] + i] = this->general->otherOptions->other[i];
        }
    }

    if (num_options[1] > 0)
    {
        for (i = 0; i < num_options[1]; i++)
        {
            optionVector[prev_options[1] + i] = this->system->otherOptions->other[i];
        }
    }

    if (num_options[2] > 0)
    {
        for (i = 0; i < num_options[2]; i++)
        {
            optionVector[prev_options[2] + i] = this->service->otherOptions->other[i];
        }
    }

    if (num_options[3] > 0)
    {
        for (i = 0; i < num_options[3]; i++)
        {
            optionVector[prev_options[3] + i] = this->job->otherOptions->other[i];
        }
    }

    return optionVector;
}//getOtherJobOptions

/**
 * get the array of job dependencies
 */
std::string*  OSOption::getJobDependencies()
{
    std::string* dependenciesVector = NULL;
    if (this->job != NULL)
    {
        if (this->job->dependencies != NULL)
            dependenciesVector = this->job->dependencies->jobID;
        else
            throw ErrorClass("<dependencies> object must be defined before getting the jobIDs");
    }
    else
        throw ErrorClass("<job> object must be defined before getting the jobIDs");

    return dependenciesVector;
}//getJobDependencies

/**
 * get the list of required directories
 */
std::string*  OSOption::getRequiredDirectories()
{
    std::string* pathVector = NULL;
    if (this->job != NULL)
    {
        if (this->job->requiredDirectories != NULL)
            pathVector = this->job->requiredDirectories->path;
        else
            throw ErrorClass("<requiredDirectories> object must be defined before getting the paths");
    }
    else
        throw ErrorClass("<job> object must be defined before getting the paths");
    return pathVector;
}//getRequiredDirectories

/**
 * get the list of required files
 */
std::string*  OSOption::getRequiredFiles()
{
    std::string* pathVector = NULL;
    if (this->job != NULL)
    {
        if (this->job->requiredFiles != NULL)
            pathVector = this->job->requiredFiles->path;
        else
            throw ErrorClass("<requiredFiles> object must be defined before getting the paths");
    }
    else
        throw ErrorClass("<job> object must be defined before getting the paths");
    return pathVector;
}//getRequiredFiles

/**
 * get the list of directories that need to be created
 */
std::string*  OSOption::getDirectoriesToMake()
{
    std::string* pathVector = NULL;
    if (this->job != NULL)
    {
        if (this->job->directoriesToMake != NULL)
            pathVector = this->job->directoriesToMake->path;
        else
            throw ErrorClass("<directoriesToMake> object must be defined before getting the paths");
    }
    else
        throw ErrorClass("<job> object must be defined before getting the paths");
    return pathVector;
}//getDirectoriesToMake

/**
 * get the list of files that need to be created
 */
std::string*  OSOption::getFilesToMake()
{
    std::string* pathVector = NULL;
    if (this->job != NULL)
    {
        if (this->job->filesToMake != NULL)
            pathVector = this->job->filesToMake->path;
        else
            throw ErrorClass("<filesToMake> object must be defined before getting the paths");
    }
    else
        throw ErrorClass("<job> object must be defined before getting the paths");
    return pathVector;
}//getFilesToMake

/**
 * get the list of input directories that need to be moved or copied
 */
PathPair** OSOption::getInputDirectoriesToMove()
{
    PathPair** pathPairVector = NULL;
    if (this->job != NULL)
    {
        if (this->job->inputDirectoriesToMove != NULL)
            pathPairVector = this->job->inputDirectoriesToMove->pathPair;
        else
            throw ErrorClass("<inputDirectoriesToMove> object must be defined before getting the paths");
    }
    else
        throw ErrorClass("<job> object must be defined before getting the paths");
    return pathPairVector;
}//getInputDirectoriesToMove

/**
 * get the list of input files that need to be moved or copied
 */
PathPair** OSOption::getInputFilesToMove()
{
    PathPair** pathPairVector = NULL;
    if (this->job != NULL)
    {
        if (this->job->inputFilesToMove != NULL)
            pathPairVector = this->job->inputFilesToMove->pathPair;
        else
            throw ErrorClass("<inputFilesToMove> object must be defined before getting the paths");
    }
    else
        throw ErrorClass("<job> object must be defined before getting the paths");
    return pathPairVector;
}//getInputFilesToMove

/**
 * get the list of output files that need to be moved or copied
 */
PathPair** OSOption::getOutputFilesToMove()
{
    PathPair** pathPairVector = NULL;
    if (this->job != NULL)
    {
        if (this->job->outputFilesToMove != NULL)
            pathPairVector = this->job->outputFilesToMove->pathPair;
        else
            throw ErrorClass("<outputFilesToMove> object must be defined before getting the paths");
    }
    else
        throw ErrorClass("<job> object must be defined before getting the paths");
    return pathPairVector;
}//getOutputFilesToMove

/**
 * get the list of output directories that need to be moved or copied
 */
PathPair** OSOption::getOutputDirectoriesToMove()
{
    PathPair** pathPairVector = NULL;
    if (this->job != NULL)
    {
        if (this->job->outputDirectoriesToMove != NULL)
            pathPairVector = this->job->outputDirectoriesToMove->pathPair;
        else
            throw ErrorClass("<outputDirectoriesToMove> object must be defined before getting the paths");
    }
    else
        throw ErrorClass("<job> object must be defined before getting the paths");
    return pathPairVector;
}//getOutputDirectoriesToMove

/**
 * get the list of files that need to be deleted
 */
std::string*  OSOption::getFilesToDelete()
{
    std::string* pathVector = NULL;
    if (this->job != NULL)
    {
        if (this->job->filesToDelete != NULL)
            pathVector = this->job->filesToDelete->path;
        else
            throw ErrorClass("<filesToDelete> object must be defined before getting the paths");
    }
    else
        throw ErrorClass("<job> object must be defined before getting the paths");
    return pathVector;
}//getFilesToDelete

/**
 * get the list of directories that need to be deleted
 */
std::string*  OSOption::getDirectoriesToDelete()
{
    std::string* pathVector = NULL;
    if (this->job != NULL)
    {
        if (this->job->directoriesToDelete != NULL)
            pathVector = this->job->directoriesToDelete->path;
        else
            throw ErrorClass("<directoriesToDelete> object must be defined before getting the paths");
    }
    else
        throw ErrorClass("<job> object must be defined before getting the paths");
    return pathVector;
}//getDirectoriesToDelete

/**
 * get the list of processes that need to be killed
 */
std::string*  OSOption::getProcessesToKill()
{
    std::string* processes = NULL;
    if (this->job != NULL)
    {
        if (this->job->processesToKill != NULL)
            processes = this->job->processesToKill->process;
        else
            throw ErrorClass("<processesToKill> object must be defined before getting the processes");
    }
    else
        throw ErrorClass("<job> object must be defined before getting the processes");
    return processes;
}//getProcessesToKill



/**
 * get the list of initial variable values in sparse form
 * @return a list of index/value pairs
 */
InitVarValue**  OSOption::getInitVarValuesSparse()
{
    InitVarValue**  initVarVector;
    if (this->optimization != NULL)
    {
        if (this->optimization->variables != NULL)
        {
            if (this->optimization->variables->initialVariableValues != NULL)
                initVarVector = this->optimization->variables->initialVariableValues->var;
            else
                throw ErrorClass("<initialVariableValues> object must be defined before getting the data");
        }
        else
            throw ErrorClass("<variables> object must be defined before getting the data");
    }
    else
        throw ErrorClass("<optimization> object must be defined before getting the data");
    return initVarVector;
}//getInitVarValuesSparse

/**
 * get the list of initial variable values in dense form
 * @return an array of values
 * @note return OSNaN() for variables that are not initialed
 */
double* OSOption::getInitVarValuesDense()
{
    try
    {
        int numberOfVariables;
        numberOfVariables = this->getNumberOfVariables();
        if (numberOfVariables < 0)
            throw ErrorClass("\"numberOfVariables\" must be present to use dense methods");

        if (this->optimization != NULL)
        {
            if (this->optimization->variables != NULL)
            {
                if (this->optimization->variables->initialVariableValues != NULL)
                {
                    int i,j,k;
                    int num_var;
                    num_var = this->getNumberOfInitVarValues();

                    if (m_mdInitVarValuesDense != NULL)
                        delete [] m_mdInitVarValuesDense;
                    m_mdInitVarValuesDense = new double[numberOfVariables];
                    for (k = 0; k < numberOfVariables; k++) m_mdInitVarValuesDense[k] = OSNaN();

                    for (i = 0; i < num_var; i++)
                    {
                        j = this->optimization->variables->initialVariableValues->var[i]->idx;
                        if (j >= 0 && j < numberOfVariables)
                            m_mdInitVarValuesDense[j]
                                = this->optimization->variables->initialVariableValues->var[i]->value;
                        else
                            throw ErrorClass("Variable index out of range");
                    }
                    return m_mdInitVarValuesDense;
                }
            }
        }
    }
    catch(const ErrorClass& eclass)
    {
        throw ErrorClass(eclass.errormsg);
    }
    return NULL;
}//getInitVarValuesDense

/**
 * get the list of initial variable values in dense form
 * @param numberOfVariables is the dimension of the array
 * @return an array of values
 * @note return OSNaN() for variables that are not initialed
 */
double* OSOption::getInitVarValuesDense(int numberOfVariables)
{
    try
    {
        if (numberOfVariables < 0)
            throw ErrorClass("\"numberOfVariables\" must be present to use dense methods");

        if (this->optimization != NULL)
        {
            if (this->optimization->variables != NULL)
            {
                if (this->optimization->variables->initialVariableValues != NULL)
                {
                    int i,j,k;
                    int num_var;
                    num_var = this->getNumberOfInitVarValues();

                    if (m_mdInitVarValuesDense != NULL)
                        delete [] m_mdInitVarValuesDense;
                    m_mdInitVarValuesDense = new double[numberOfVariables];
                    for (k = 0; k < numberOfVariables; k++) m_mdInitVarValuesDense[k] = OSNaN();

                    for (i = 0; i < num_var; i++)
                    {
                        j = this->optimization->variables->initialVariableValues->var[i]->idx;
                        if (j >= 0 && j < numberOfVariables)
                            m_mdInitVarValuesDense[j]
                                = this->optimization->variables->initialVariableValues->var[i]->value;
                        else
                            throw ErrorClass("Variable index out of range");
                    }
                    return m_mdInitVarValuesDense;
                }
            }
        }
    }
    catch(const ErrorClass& eclass)
    {
        throw ErrorClass(eclass.errormsg);
    }
    return NULL;
}//getInitVarValuesDense

/**
 * get the list of initial values for string-valued variables in sparse form
 * @return a list of index/value pairs
 */
InitVarValueString**  OSOption::getInitVarValuesStringSparse()
{
    InitVarValueString** initVarVector;
    if (this->optimization != NULL)
    {
        if (this->optimization->variables != NULL)
        {
            if (this->optimization->variables->initialVariableValuesString != NULL)
                initVarVector = this->optimization->variables->initialVariableValuesString->var;
            else
                throw ErrorClass("<initialVariableValuesString> object must be defined before getting the data");
        }
        else
            throw ErrorClass("<variables> object must be defined before getting the data");
    }
    else
        throw ErrorClass("<optimization> object must be defined before getting the data");
    return initVarVector;
}//getInitVarValuesStringSparse

/**
 * get the list of initial values for string-valued variables in dense form
 * @return an array of value strings
 * @note return the empty string "" for variables that are not initialed
 */
std::string *OSOption::getInitVarValuesStringDense()
{
    try
    {
        int numberOfVariables;
        numberOfVariables = this->getNumberOfVariables();
        if (numberOfVariables < 0)
            throw ErrorClass("\"numberOfVariables\" must be present to use dense methods");

        if (this->optimization != NULL)
        {
            if (this->optimization->variables != NULL)
            {
                if (this->optimization->variables->initialVariableValuesString != NULL)
                {
                    int i,j,k;
                    int num_var;
                    num_var = this->getNumberOfInitVarValuesString();

                    if (m_mdInitVarValuesStringDense != NULL)
                        delete [] m_mdInitVarValuesStringDense;
                    m_mdInitVarValuesStringDense = new std::string[numberOfVariables];
                    for (k = 0; k < numberOfVariables; k++) m_mdInitVarValuesStringDense[k] = "";

                    for (i = 0; i < num_var; i++)
                    {
                        j = this->optimization->variables->initialVariableValuesString->var[i]->idx;
                        if (j >= 0 && j < numberOfVariables)
                            m_mdInitVarValuesStringDense[j]
                                = this->optimization->variables->initialVariableValuesString->var[i]->value;
                        else
                            throw ErrorClass("Variable index out of range");
                    }
                    return m_mdInitVarValuesStringDense;
                }
            }
        }
    }
    catch(const ErrorClass& eclass)
    {
        throw ErrorClass(eclass.errormsg);
    }
    return NULL;
}//getInitVarValuesStringDense

/**
 * get the list of initial values for string-valued variables in dense form
 * @param numberOfVariables is the dimension of the array
 * @return an array of value strings
 * @note return the empty string "" for variables that are not initialed
std::string *OSOption::getInitVarValuesStringDense(int numberOfVariables)
{    try
    {    if (numberOfVariables < 0)
            throw ErrorClass("\"numberOfVariables\" must be present to use dense methods");

        if (this->optimization != NULL)
        {    if (this->optimization->variables != NULL)
            {    if (this->optimization->variables->initialVariableValuesString != NULL)
                {    int i,j,k;
                    int num_var;
                    num_var = this->getNumberOfInitVarValuesString();

                    if (m_mdInitVarValuesStringDense != NULL)
                        delete [] m_mdInitVarValuesStringDense;
                    m_mdInitVarValuesStringDense = new std::string[numberOfVariables];
                    for (k = 0; k < numberOfVariables; k++) m_mdInitVarValuesStringDense[k] = "";

                    for (i = 0; i < num_var; i++)
                    {    j = this->optimization->variables->initialVariableValuesString->var[i]->idx;
                        if (j >= 0 && j < numberOfVariables)
                            m_mdInitVarValuesStringDense[j]
                              = this->optimization->variables->initialVariableValuesString->var[i]->value;
                        else
                            throw ErrorClass("Variable index out of range");
                    }
                    return m_mdInitVarValuesStringDense;
                }
            }
        }
    }
    catch(const ErrorClass& eclass)
    {    throw ErrorClass(eclass.errormsg);
    }
    return NULL;
}//getInitVarValuesStringDense
 */


/**
 * get the basis status for all variables in dense form
 * @return an array of int, with values corresponding to ENUM_BASIS_STATUS -- see OSGeneral.g
 * @note returns ENUM_BASIS_STATUS_unknown for variables that are not initialed
 * @param numberOfVariables is the dimension of the array
 */
int* OSOption::getVariableInitialBasisStatusDense(int numberOfVariables)
{
    try
    {
        if (numberOfVariables < 0)
            throw ErrorClass("\"numberOfVariables\" must be set to use dense methods");

        if (this->optimization == NULL)
            throw ErrorClass("<optimization> element was never set");

        if (this->optimization->variables == NULL)
            throw ErrorClass("<optimization> <variables> element was never set");

        if (this->optimization->variables->initialBasisStatus == NULL)
            throw ErrorClass("initial basis was never set");

        int i,j,k;

        if (m_mdInitBasisStatusDense != NULL)
            delete [] m_mdInitBasisStatusDense;
        m_mdInitBasisStatusDense = new int[numberOfVariables];
        for (k = 0; k < numberOfVariables; k++) m_mdInitBasisStatusDense[k] = ENUM_BASIS_STATUS_unknown;

        int num_var;


        if (this->optimization->variables->initialBasisStatus->basic != NULL)
        {
            num_var = this->optimization->variables->initialBasisStatus->basic->numberOfEl;
            for (i = 0; i < num_var; i++)
            {
                j = this->optimization->variables->initialBasisStatus->basic->el[i];
                if (j >= 0 && j < numberOfVariables)
                    m_mdInitBasisStatusDense[j] = ENUM_BASIS_STATUS_basic;
                else
                    throw ErrorClass("Variable index out of range");
            }
        }

        if (this->optimization->variables->initialBasisStatus->atLower != NULL)
        {
            num_var = this->optimization->variables->initialBasisStatus->atLower->numberOfEl;
            for (i = 0; i < num_var; i++)
            {
                j = this->optimization->variables->initialBasisStatus->atLower->el[i];
                if (j >= 0 && j < numberOfVariables)
                    m_mdInitBasisStatusDense[j] = ENUM_BASIS_STATUS_atLower;
                else
                    throw ErrorClass("Variable index out of range");
            }
        }

        if (this->optimization->variables->initialBasisStatus->atUpper != NULL)
        {
            num_var = this->optimization->variables->initialBasisStatus->atUpper->numberOfEl;



            for (i = 0; i < num_var; i++)
            {
                j = this->optimization->variables->initialBasisStatus->atUpper->el[i];
                if (j >= 0 && j < numberOfVariables)
                    m_mdInitBasisStatusDense[j] = ENUM_BASIS_STATUS_atUpper;
                else
                    throw ErrorClass("Variable index out of range");
            }
        }

        if (this->optimization->variables->initialBasisStatus->isFree != NULL)
        {
            num_var = this->optimization->variables->initialBasisStatus->isFree->numberOfEl;
            for (i = 0; i < num_var; i++)
            {
                j = this->optimization->variables->initialBasisStatus->isFree->el[i];
                if (j >= 0 && j < numberOfVariables)
                    m_mdInitBasisStatusDense[j] = ENUM_BASIS_STATUS_isFree;
                else
                    throw ErrorClass("Variable index out of range");
            }
        }

        if (this->optimization->variables->initialBasisStatus->superbasic != NULL)
        {
            num_var = this->optimization->variables->initialBasisStatus->superbasic->numberOfEl;
            for (i = 0; i < num_var; i++)
            {
                j = this->optimization->variables->initialBasisStatus->superbasic->el[i];
                if (j >= 0 && j < numberOfVariables)
                    m_mdInitBasisStatusDense[j] = ENUM_BASIS_STATUS_superbasic;
                else
                    throw ErrorClass("Variable index out of range");
            }
        }

        return m_mdInitBasisStatusDense;
    }

    catch(const ErrorClass& eclass)
    {
        throw ErrorClass(eclass.errormsg);
    }
    return NULL;
}//getVariableInitialBasisStatusDense


int OSOption::getNumberOfInitialBasisElements(int type, int status)
{
    if (this->optimization == NULL)
        throw ErrorClass("<optimization> element was never set");

    switch (type)
    {
    case ENUM_PROBLEM_COMPONENT_variables:
    {
        if (this->optimization->variables == NULL)
            throw ErrorClass("<optimization> <variables> element was never set");

        if (this->optimization->variables->initialBasisStatus == NULL)
            throw ErrorClass("initial basis was never set");

        return this->optimization->variables->initialBasisStatus->getNumberOfEl(status);
    }
    case ENUM_PROBLEM_COMPONENT_objectives:
    {
        if (this->optimization->objectives == NULL)
            throw ErrorClass("<optimization> <objectives> element was never set");

        if (this->optimization->objectives->initialBasisStatus == NULL)
            throw ErrorClass("initial basis was never set");

        return this->optimization->objectives->initialBasisStatus->getNumberOfEl(status);
    }
    case ENUM_PROBLEM_COMPONENT_constraints:
    {
        if (this->optimization->constraints == NULL)
            throw ErrorClass("<optimization> <constraints> element was never set");

        if (this->optimization->constraints->initialBasisStatus == NULL)
            throw ErrorClass("initial basis was never set");

        return this->optimization->constraints->initialBasisStatus->getNumberOfEl(status);
    }
    default:
        throw ErrorClass("target object not implemented in getNumberOfInitialBasisElements");
    }
}//getNumberOfInitialBasisElements

bool OSOption::getInitialBasisElements(int type, int status, int* elem)
{
    if (this->optimization == NULL)
        throw ErrorClass("<optimization> element was never set");

    switch (type)
    {
    case ENUM_PROBLEM_COMPONENT_variables:
    {
        if (this->optimization->variables == NULL)
            throw ErrorClass("<optimization> <variables> element was never set");

        if (this->optimization->variables->initialBasisStatus == NULL)
            throw ErrorClass("initial basis was never set");

        return this->optimization->variables->initialBasisStatus->getIntVector(status, elem);
    }
    case ENUM_PROBLEM_COMPONENT_objectives:
    {
        if (this->optimization->objectives == NULL)
            throw ErrorClass("<optimization> <objectives> element was never set");

        if (this->optimization->objectives->initialBasisStatus == NULL)
            throw ErrorClass("initial basis was never set");

        return this->optimization->objectives->initialBasisStatus->getIntVector(status, elem);
    }
    case ENUM_PROBLEM_COMPONENT_constraints:
    {
        if (this->optimization->constraints == NULL)
            throw ErrorClass("<optimization> <constraints> element was never set");

        if (this->optimization->constraints->initialBasisStatus == NULL)
            throw ErrorClass("initial basis was never set");

        return this->optimization->constraints->initialBasisStatus->getIntVector(status, elem);
    }
    default:
        throw ErrorClass("target object not implemented in getInitialBasisElements");
    }
}//getInitialBasisElements




/**
 * get a list of branching weights for integer variables in sparse form
 * @return a list of index/value pairs
 */
BranchingWeight**  OSOption::getIntegerVariableBranchingWeightsSparse()
{
    BranchingWeight** intVarVector;
    if (this->optimization != NULL)
    {
        if (this->optimization->variables != NULL)
        {
            if (this->optimization->variables->integerVariableBranchingWeights != NULL)
                intVarVector = this->optimization->variables->integerVariableBranchingWeights->var;
            else
                throw ErrorClass("<integerVariableBranchingWeights> object must be defined before getting the data");
        }
        else
            throw ErrorClass("<variables> object must be defined before getting the data");
    }
    else
        throw ErrorClass("<optimization> object must be defined before getting the data");
    return intVarVector;
}//getIntegerVariableBranchingWeightsSparse


/**
 * get a list of branching weights for integer variables in dense form
 * @return an array of values
 * @note return OSNaN() for variables that are not initialed
 */
double* OSOption::getIntegerVariableBranchingWeightsDense()
{
    try
    {
        int numberOfVariables;
        numberOfVariables = this->getNumberOfVariables();
        if (numberOfVariables < 0)
            throw ErrorClass("\"numberOfVariables\" must be present to use dense methods");

        if (this->optimization != NULL)
        {
            if (this->optimization->variables != NULL)
            {
                if (this->optimization->variables->integerVariableBranchingWeights != NULL)
                {
                    int i,j,k;
                    int num_var;
                    num_var = this->getNumberOfIntegerVariableBranchingWeights();

                    if (m_mdIntegerVariableBranchingWeightsDense != NULL)
                        delete [] m_mdIntegerVariableBranchingWeightsDense;
                    m_mdIntegerVariableBranchingWeightsDense = new double[numberOfVariables];
                    for (k = 0; k < numberOfVariables; k++) m_mdIntegerVariableBranchingWeightsDense[k] = OSNaN();

                    for (i = 0; i < num_var; i++)
                    {
                        j = this->optimization->variables->integerVariableBranchingWeights->var[i]->idx;
                        if (j >= 0 && j < numberOfVariables)
                            m_mdIntegerVariableBranchingWeightsDense[j]
                                = this->optimization->variables->integerVariableBranchingWeights->var[i]->value;
                        else
                            throw ErrorClass("Variable index out of range");
                    }
                    return m_mdIntegerVariableBranchingWeightsDense;
                }
            }
        }
    }
    catch(const ErrorClass& eclass)
    {
        throw ErrorClass(eclass.errormsg);
    }
    return NULL;
}//getIntegerVariableBranchingWeightsDense

/**
 * get a list of branching weights for integer variables in dense form

 * @param numberOfVariables is the dimension of the array
 * @return an array of values
 * @note return OSNaN() for variables that are not initialed
 */
double* OSOption::getIntegerVariableBranchingWeightsDense(int numberOfVariables)
{
    try
    {
        if (numberOfVariables < 0)
            throw ErrorClass("\"numberOfVariables\" must be present to use dense methods");

        if (this->optimization != NULL)
        {
            if (this->optimization->variables != NULL)
            {
                if (this->optimization->variables->integerVariableBranchingWeights != NULL)
                {
                    int i,j,k;
                    int num_var;
                    num_var = this->getNumberOfIntegerVariableBranchingWeights();

                    if (m_mdIntegerVariableBranchingWeightsDense != NULL)
                        delete [] m_mdIntegerVariableBranchingWeightsDense;
                    m_mdIntegerVariableBranchingWeightsDense = new double[numberOfVariables];
                    for (k = 0; k < numberOfVariables; k++) m_mdIntegerVariableBranchingWeightsDense[k] = OSNaN();

                    for (i = 0; i < num_var; i++)
                    {
                        j = this->optimization->variables->integerVariableBranchingWeights->var[i]->idx;
                        if (j >= 0 && j < numberOfVariables)
                            m_mdIntegerVariableBranchingWeightsDense[j]
                                = this->optimization->variables->integerVariableBranchingWeights->var[i]->value;
                        else
                            throw ErrorClass("Variable index out of range");
                    }
                    return m_mdIntegerVariableBranchingWeightsDense;
                }
            }
        }
    }
    catch(const ErrorClass& eclass)
    {
        throw ErrorClass(eclass.errormsg);
    }
    return NULL;
}//getIntegerVariableBranchingWeightsDense

/**
 * get a list of branching weights for SOS variables in sparse form
 * @return a list of SOSWeights objects
 */
SOSWeights**  OSOption::getSOSVariableBranchingWeightsSparse()
{
    SOSWeights** sosVarVector;
    if (this->optimization != NULL)
    {
        if (this->optimization->variables != NULL)
        {
            if (this->optimization->variables->sosVariableBranchingWeights != NULL)
                sosVarVector = this->optimization->variables->sosVariableBranchingWeights->sos;
            else
                throw ErrorClass("<sosVariableBranchingWeights> object must be defined before getting the data");
        }
        else
            throw ErrorClass("<variables> object must be defined before getting the data");
    }
    else
        throw ErrorClass("<optimization> object must be defined before getting the data");
    return sosVarVector;
}//getSOSVariableBranchingWeightsSparse


/**
 * get the array of other variable options associated with a particular solver
 * @param solver_name is the name of the solver
 * @return an array of other variable options associated with this solver
 */
std::vector<OtherVariableOptionOrResult*>  OSOption::getOtherVariableOptions( std::string solver_name)
{
    std::vector<OtherVariableOptionOrResult*> optionsVector;
    if (this->optimization != NULL)
    {
        if (this->optimization->variables != NULL)
        {
            int i;
            int num_options;
            num_options = this->getNumberOfOtherVariableOptions();
            for(i = 0; i < num_options; i++)
                if (solver_name == this->optimization->variables->other[ i]->solver)
                    optionsVector.push_back( this->optimization->variables->other[ i]);
        }
        else
            throw ErrorClass("<variables> object must be defined before getting the data");
    }
    else
        throw ErrorClass("<optimization> object must be defined before getting the data");
    return optionsVector;
}//getOtherVariableOptions

/**
 * get the array of all other variable options
 * @return an array of other variable options associated with this solver
 */
OtherVariableOptionOrResult** OSOption::getAllOtherVariableOptions()
{
    OtherVariableOptionOrResult** optionsVector;
    if (this->optimization != NULL)
    {
        if (this->optimization->variables != NULL)
            optionsVector = this->optimization->variables->other;
        else
            throw ErrorClass("<variables> object must be defined before getting the data");
    }
    else
        throw ErrorClass("<optimization> object must be defined before getting the data");
    return optionsVector;
}//getAllOtherVariableOptions

/**
 * Get one particular <other> variable option from the array of options
 * <p>
 *
 * @param optionNumber is the index of the option in the array
 * @return a pointer to one OtherVariableOption object
 */
OtherVariableOptionOrResult* OSOption::getOtherVariableOption(int optionNumber)
{
    if (this->optimization != NULL)
    {
        if (this->optimization->variables != NULL)
        {
            int num_options;
            num_options = this->getNumberOfOtherVariableOptions();
            if (optionNumber < 0 || optionNumber >= num_options)
                throw ErrorClass("optionNumber not in legal range");
            return this->optimization->variables->other[optionNumber];
        }
        else
            throw ErrorClass("<variables> object must be defined before getting the data");
    }
    else
        throw ErrorClass("<optimization> object must be defined before getting the data");
}//getOtherVariableOption

/**
 * get the list of initial objective values in sparse form
 * @return a list of index/value pairs
 */
InitObjValue**  OSOption::getInitObjValuesSparse()
{
    InitObjValue** initObjVector;
    if (this->optimization != NULL)
    {
        if (this->optimization->objectives != NULL)
        {
            if (this->optimization->objectives->initialObjectiveValues != NULL)
                initObjVector = this->optimization->objectives->initialObjectiveValues->obj;
            else
                throw ErrorClass("<initialObjectiveValues> object must be defined before getting the data");
        }
        else
            throw ErrorClass("<objectives> object must be defined before getting the data");
    }
    else
        throw ErrorClass("<optimization> object must be defined before getting the data");
    return initObjVector;
}//getInitObjValuesSparse

/**
 * get the list of initial objective values in dense form
 * @return an array of values
 * @note return OSNaN() for objectives that are not initialed
 */
double* OSOption::getInitObjValuesDense()
{
    try
    {
        int numberOfObjectives;
        numberOfObjectives = this->getNumberOfObjectives();
        if (numberOfObjectives < 0)
            throw ErrorClass("\"numberOfObjectives\" must be present to use dense methods");

        if (this->optimization != NULL)
        {
            if (this->optimization->objectives != NULL)
            {
                if (this->optimization->objectives->initialObjectiveValues != NULL)
                {
                    int i,j,k;
                    int num_obj;
                    num_obj = this->getNumberOfInitObjValues();

                    if (m_mdInitObjValuesDense != NULL)
                        delete [] m_mdInitObjValuesDense;
                    m_mdInitObjValuesDense = new double[numberOfObjectives];
                    for (k = 0; k < numberOfObjectives; k++) m_mdInitObjValuesDense[k] = OSNaN();

                    for (i = 0; i < num_obj; i++)
                    {
                        j = this->optimization->objectives->initialObjectiveValues->obj[i]->idx;
                        if (j < 0 && -j <= numberOfObjectives)
                            m_mdInitObjValuesDense[-1-j]
                                = this->optimization->objectives->initialObjectiveValues->obj[i]->value;
                        else
                        {
                            throw ErrorClass("Objective index out of range");
                        }
                    }
                    return m_mdInitObjValuesDense;
                }
            }
        }
    }
    catch(const ErrorClass& eclass)
    {
        throw ErrorClass(eclass.errormsg);
    }
    return NULL;
}//getInitObjValuesDense

/**
 * get the list of initial objective values in dense form
 * @param numberOfObjectives is the dimension of the array
 * @return an array of values
 * @note return OSNaN() for objectives that are not initialed
 */
double* OSOption::getInitObjValuesDense(int numberOfObjectives)
{
    try
    {
        if (numberOfObjectives < 0)

            throw ErrorClass("\"numberOfObjectives\" must be present to use dense methods");

        if (this->optimization != NULL)
        {
            if (this->optimization->objectives != NULL)
            {
                if (this->optimization->objectives->initialObjectiveValues != NULL)
                {
                    int i,j,k;
                    int num_obj;
                    num_obj = this->getNumberOfInitObjValues();

                    if (m_mdInitObjValuesDense != NULL)
                        delete [] m_mdInitObjValuesDense;
                    m_mdInitObjValuesDense = new double[numberOfObjectives];
                    for (k = 0; k < numberOfObjectives; k++) m_mdInitObjValuesDense[k] = OSNaN();

                    for (i = 0; i < num_obj; i++)
                    {
                        j = this->optimization->objectives->initialObjectiveValues->obj[i]->idx;
                        if (j < 0 && -j <= numberOfObjectives)
                            m_mdInitObjValuesDense[-1-j]
                                = this->optimization->objectives->initialObjectiveValues->obj[i]->value;
                        else
                        {
                            throw ErrorClass("Objective index out of range");
                        }
                    }
                    return m_mdInitObjValuesDense;
                }
            }
        }
    }
    catch(const ErrorClass& eclass)
    {
        throw ErrorClass(eclass.errormsg);
    }
    return NULL;
}//getInitObjValuesDense

/**
 * get the list of initial objective bounds in sparse form
 * @return a list of index/value/value triples
 */
InitObjBound**  OSOption::getInitObjBoundsSparse()
{
    InitObjBound** initObjBounds;
    if (this->optimization != NULL)
    {
        if (this->optimization->objectives != NULL)
        {
            if (this->optimization->objectives->initialObjectiveBounds != NULL)
                initObjBounds = this->optimization->objectives->initialObjectiveBounds->obj;
            else
                throw ErrorClass("<initialObjectiveBounds> object must be defined before getting the data");
        }
        else
            throw ErrorClass("<objectives> object must be defined before getting the data");
    }
    else
        throw ErrorClass("<optimization> object must be defined before getting the data");
    return initObjBounds;
}//getInitObjBoundsSparse

/**
 * get the list of initial objective lower bounds in dense form
 * @return an array of values
 * @note return OSNaN() for objectives that are not initialed
 */
double* OSOption::getInitObjLowerBoundsDense()
{
    try
    {
        int numberOfObjectives;
        numberOfObjectives = this->getNumberOfObjectives();
        if (numberOfObjectives < 0)
            throw ErrorClass("\"numberOfObjectives\" must be present to use dense methods");

        if (this->optimization != NULL)
        {
            if (this->optimization->objectives != NULL)
            {
                if (this->optimization->objectives->initialObjectiveBounds != NULL)
                {
                    int i,j,k;
                    int num_obj;
                    num_obj = this->getNumberOfInitObjBounds();

                    if (m_mdInitObjLowerBoundsDense != NULL)
                        delete [] m_mdInitObjLowerBoundsDense;
                    m_mdInitObjLowerBoundsDense = new double[numberOfObjectives];
                    for (k = 0; k < numberOfObjectives; k++) m_mdInitObjLowerBoundsDense[k] = OSNaN();

                    for (i = 0; i < num_obj; i++)
                    {
                        j = this->optimization->objectives->initialObjectiveBounds->obj[i]->idx;
                        if (j < 0 && -j <= numberOfObjectives)
                            m_mdInitObjLowerBoundsDense[-1-j]
                                = this->optimization->objectives->initialObjectiveBounds->obj[i]->lbValue;
                        else
                        {
                            throw ErrorClass("Objective index out of range");
                        }
                    }
                    return m_mdInitObjLowerBoundsDense;
                }
            }
        }
    }
    catch(const ErrorClass& eclass)
    {
        throw ErrorClass(eclass.errormsg);
    }
    return NULL;
}//getInitObjLowerBoundsDense

/**
 * get the list of initial objective lower bounds in dense form
 * @param numberOfObjectives is the dimension of the array
 * @return an array of values
 * @note return OSNaN() for objectives that are not initialed
 */
double* OSOption::getInitObjLowerBoundsDense(int numberOfObjectives)
{
    try
    {
        if (numberOfObjectives < 0)
            throw ErrorClass("\"numberOfObjectives\" must be present to use dense methods");

        if (this->optimization != NULL)
        {
            if (this->optimization->objectives != NULL)
            {
                if (this->optimization->objectives->initialObjectiveBounds != NULL)
                {
                    int i,j,k;
                    int num_obj;
                    num_obj = this->getNumberOfInitObjBounds();

                    if (m_mdInitObjLowerBoundsDense != NULL)
                        delete [] m_mdInitObjLowerBoundsDense;
                    m_mdInitObjLowerBoundsDense = new double[numberOfObjectives];
                    for (k = 0; k < numberOfObjectives; k++) m_mdInitObjLowerBoundsDense[k] = OSNaN();

                    for (i = 0; i < num_obj; i++)
                    {
                        j = this->optimization->objectives->initialObjectiveBounds->obj[i]->idx;
                        if (j < 0 && -j <= numberOfObjectives)
                            m_mdInitObjLowerBoundsDense[-1-j]
                                = this->optimization->objectives->initialObjectiveBounds->obj[i]->lbValue;
                        else
                        {
                            throw ErrorClass("Objective index out of range");
                        }
                    }
                    return m_mdInitObjLowerBoundsDense;
                }
            }
        }
    }
    catch(const ErrorClass& eclass)
    {
        throw ErrorClass(eclass.errormsg);
    }
    return NULL;
}//getInitObjLowerBoundsDense

/**
 * get the list of initial objective upper bounds in dense form
 * @return an array of values
 * @note return OSNaN() for objectives that are not initialed
 */
double* OSOption::getInitObjUpperBoundsDense()
{
    try
    {
        int numberOfObjectives;
        numberOfObjectives = this->getNumberOfObjectives();
        if (numberOfObjectives < 0)
            throw ErrorClass("\"numberOfObjectives\" must be present to use dense methods");

        if (this->optimization != NULL)
        {
            if (this->optimization->objectives != NULL)
            {
                if (this->optimization->objectives->initialObjectiveBounds != NULL)
                {
                    int i,j,k;
                    int num_obj;
                    num_obj = this->getNumberOfInitObjBounds();

                    if (m_mdInitObjUpperBoundsDense != NULL)
                        delete [] m_mdInitObjUpperBoundsDense;
                    m_mdInitObjUpperBoundsDense = new double[numberOfObjectives];
                    for (k = 0; k < numberOfObjectives; k++) m_mdInitObjUpperBoundsDense[k] = OSNaN();

                    for (i = 0; i < num_obj; i++)
                    {
                        j = this->optimization->objectives->initialObjectiveBounds->obj[i]->idx;
                        if (j < 0 && -j <= numberOfObjectives)
                            m_mdInitObjUpperBoundsDense[-1-j]
                                = this->optimization->objectives->initialObjectiveBounds->obj[i]->ubValue;
                        else
                        {
                            throw ErrorClass("Objective index out of range");
                        }
                    }
                    return m_mdInitObjUpperBoundsDense;
                }
            }
        }
    }
    catch(const ErrorClass& eclass)
    {
        throw ErrorClass(eclass.errormsg);
    }
    return NULL;
}//getInitObjUpperBoundsDense

/**
 * get the list of initial objective upper bounds in dense form
 * @param numberOfObjectives is the dimension of the array
 * @return an array of values
 * @note return OSNaN() for objectives that are not initialed
 */
double* OSOption::getInitObjUpperBoundsDense(int numberOfObjectives)
{
    try
    {
        if (numberOfObjectives < 0)
            throw ErrorClass("\"numberOfObjectives\" must be present to use dense methods");

        if (this->optimization != NULL)
        {
            if (this->optimization->objectives != NULL)
            {
                if (this->optimization->objectives->initialObjectiveBounds != NULL)
                {
                    int i,j,k;
                    int num_obj;
                    num_obj = this->getNumberOfInitObjBounds();

                    if (m_mdInitObjUpperBoundsDense != NULL)
                        delete [] m_mdInitObjUpperBoundsDense;
                    m_mdInitObjUpperBoundsDense = new double[numberOfObjectives];
                    for (k = 0; k < numberOfObjectives; k++) m_mdInitObjUpperBoundsDense[k] = OSNaN();

                    for (i = 0; i < num_obj; i++)
                    {
                        j = this->optimization->objectives->initialObjectiveBounds->obj[i]->idx;
                        if (j < 0 && -j <= numberOfObjectives)
                            m_mdInitObjUpperBoundsDense[-1-j]
                                = this->optimization->objectives->initialObjectiveBounds->obj[i]->ubValue;
                        else
                        {
                            throw ErrorClass("Objective index out of range");
                        }
                    }
                    return m_mdInitObjUpperBoundsDense;
                }
            }
        }
    }
    catch(const ErrorClass& eclass)
    {
        throw ErrorClass(eclass.errormsg);
    }
    return NULL;
}//getInitObjUpperBoundsDense

/**
 * get the list of initial values for string-valued variables in dense form
 * @param numberOfVariables is the dimension of the array
 * @return an array of value strings
 * @note return the empty string "" for variables that are not initialed
 */
std::string *OSOption::getInitVarValuesStringDense(int numberOfVariables)
{
    try
    {
        if (numberOfVariables < 0)
            throw ErrorClass("\"numberOfVariables\" must be present to use dense methods");

        if (this->optimization != NULL)
        {
            if (this->optimization->variables != NULL)
            {
                if (this->optimization->variables->initialVariableValuesString != NULL)
                {
                    int i,j,k;
                    int num_var;
                    num_var = this->getNumberOfInitVarValuesString();

                    if (m_mdInitVarValuesStringDense != NULL)
                        delete [] m_mdInitVarValuesStringDense;
                    m_mdInitVarValuesStringDense = new std::string[numberOfVariables];
                    for (k = 0; k < numberOfVariables; k++) m_mdInitVarValuesStringDense[k] = "";

                    for (i = 0; i < num_var; i++)
                    {
                        j = this->optimization->variables->initialVariableValuesString->var[i]->idx;
                        if (j >= 0 && j < numberOfVariables)
                            m_mdInitVarValuesStringDense[j]
                                = this->optimization->variables->initialVariableValuesString->var[i]->value;
                        else
                            throw ErrorClass("Variable index out of range");
                    }
                    return m_mdInitVarValuesStringDense;
                }
            }
        }
    }
    catch(const ErrorClass& eclass)
    {
        throw ErrorClass(eclass.errormsg);
    }
    return NULL;
}//getInitVarValuesStringDense


/**
 * get the basis status for all objectives in dense form
 * @return an array of int, with values corresponding to ENUM_BASIS_STATUS -- see OSGeneral.g
 * @note returns ENUM_BASIS_STATUS_unknown for objectives that are not initialed
 * @param numberOfObjectives is the dimension of the array
 */

int* OSOption::getObjectiveInitialBasisStatusDense(int numberOfObjectives)
{
    try
    {
        if (numberOfObjectives < 0)
            throw ErrorClass("\"numberOfObjectives\" must be set to use dense methods");

        if (this->optimization == NULL)
            throw ErrorClass("<optimization> element was never set");

        if (this->optimization->objectives == NULL)
            throw ErrorClass("<optimization> <objectives> element was never set");

        if (this->optimization->objectives->initialBasisStatus == NULL)
            throw ErrorClass("initial basis was never set");

        int i,j,k;

        if (m_mdInitBasisStatusDense != NULL)
            delete [] m_mdInitBasisStatusDense;
        m_mdInitBasisStatusDense = new int[numberOfObjectives];
        for (k = 0; k < numberOfObjectives; k++) m_mdInitBasisStatusDense[k] = ENUM_BASIS_STATUS_unknown;

        int num_obj;

        if (this->optimization->objectives->initialBasisStatus->basic != NULL)
        {
            num_obj = this->optimization->objectives->initialBasisStatus->basic->numberOfEl;
            for (i = 0; i < num_obj; i++)
            {
                j = this->optimization->objectives->initialBasisStatus->basic->el[i];
                if (j >= 0 || j < -numberOfObjectives)
                    throw ErrorClass("Objective index out of range");
                else
                    m_mdInitBasisStatusDense[j] = ENUM_BASIS_STATUS_basic;
            }
        }

        if (this->optimization->objectives->initialBasisStatus->atLower != NULL)
        {
            num_obj = this->optimization->objectives->initialBasisStatus->atLower->numberOfEl;
            for (i = 0; i < num_obj; i++)
            {
                j = this->optimization->objectives->initialBasisStatus->atLower->el[i];
                if (j >= 0 || j < -numberOfObjectives)
                    throw ErrorClass("Objective index out of range");
                else
                    m_mdInitBasisStatusDense[j] = ENUM_BASIS_STATUS_atLower;
            }
        }

        if (this->optimization->objectives->initialBasisStatus->atUpper != NULL)
        {
            num_obj = this->optimization->objectives->initialBasisStatus->atUpper->numberOfEl;
            for (i = 0; i < num_obj; i++)
            {
                j = this->optimization->objectives->initialBasisStatus->atUpper->el[i];
                if (j >= 0 || j < -numberOfObjectives)
                    throw ErrorClass("Objective index out of range");
                else
                    m_mdInitBasisStatusDense[j] = ENUM_BASIS_STATUS_atUpper;
            }
        }

        if (this->optimization->objectives->initialBasisStatus->isFree != NULL)
        {
            num_obj = this->optimization->objectives->initialBasisStatus->isFree->numberOfEl;
            for (i = 0; i < num_obj; i++)
            {
                j = this->optimization->objectives->initialBasisStatus->isFree->el[i];
                if (j >= 0 || j < -numberOfObjectives)
                    throw ErrorClass("Objective index out of range");
                else
                    m_mdInitBasisStatusDense[j] = ENUM_BASIS_STATUS_isFree;
            }
        }

        if (this->optimization->objectives->initialBasisStatus->superbasic != NULL)
        {
            num_obj = this->optimization->objectives->initialBasisStatus->superbasic->numberOfEl;
            for (i = 0; i < num_obj; i++)
            {
                j = this->optimization->objectives->initialBasisStatus->superbasic->el[i];
                if (j >= 0 || j < -numberOfObjectives)
                    throw ErrorClass("Objective index out of range");
                else
                    m_mdInitBasisStatusDense[j] = ENUM_BASIS_STATUS_superbasic;
            }
        }

        return m_mdInitBasisStatusDense;
    }

    catch(const ErrorClass& eclass)
    {
        throw ErrorClass(eclass.errormsg);

    }
    return NULL;
}//getVariableInitialBasisStatusDense




/**
 * get the array of other objective options associated with a particular solver
 * @param solver_name is the name of the solver
 * @return an array of other objective options associated with this solver
 */
std::vector<OtherObjectiveOptionOrResult*>  OSOption::getOtherObjectiveOptions( std::string solver_name)
{
    std::vector<OtherObjectiveOptionOrResult*> optionsVector;
    if (this->optimization != NULL)
    {
        if (this->optimization->variables != NULL)
        {
            int i;
            int num_options;
            num_options = this->getNumberOfOtherObjectiveOptions();
            for(i = 0; i < num_options; i++)
                if (solver_name == this->optimization->objectives->other[ i]->solver)
                    optionsVector.push_back( this->optimization->objectives->other[ i]);
        }
        else
            throw ErrorClass("<objectives> object must be defined before getting the data");
    }
    else
        throw ErrorClass("<optimization> object must be defined before getting the data");
    return optionsVector;
}//getOtherObjectiveOptions

/**
 * Get one particular <other> objective option from the array of options
 * <p>
 *
 * @param optionNumber is the index of the option in the array
 * @return a pointer to one OtherObjectiveOption object
 */
OtherObjectiveOptionOrResult* OSOption::getOtherObjectiveOption(int optionNumber)
{
    if (this->optimization != NULL)
    {
        if (this->optimization->objectives != NULL)
        {
            int num_options;
            num_options = this->getNumberOfOtherObjectiveOptions();
            if (optionNumber < 0 || optionNumber >= num_options)
                throw ErrorClass("optionNumber not in legal range");
            return this->optimization->objectives->other[optionNumber];
        }
        else
            throw ErrorClass("<objectives> object must be defined before getting the data");
    }
    else
        throw ErrorClass("<optimization> object must be defined before getting the data");
}//getOtherObjectiveOption

/**
 * get the array of all other objective options
 * @return an array of other objective options associated with this solver
 */


OtherObjectiveOptionOrResult** OSOption::getAllOtherObjectiveOptions()
{
    OtherObjectiveOptionOrResult** optionsVector;
    if (this->optimization != NULL)
    {
        if (this->optimization->objectives != NULL)
            optionsVector = this->optimization->objectives->other;
        else
            throw ErrorClass("<objectives> object must be defined before getting the data");
    }
    else
        throw ErrorClass("<optimization> object must be defined before getting the data");
    return optionsVector;
}//getAllOtherObjectiveOptions


/**
 * get the list of initial constraint values in sparse form
 * @return a list of index/value pairs
 */
InitConValue**  OSOption::getInitConValuesSparse()
{
    InitConValue** initConVector;
    if (this->optimization != NULL)
    {
        if (this->optimization->constraints != NULL)
        {
            if (this->optimization->constraints->initialConstraintValues != NULL)
                initConVector = this->optimization->constraints->initialConstraintValues->con;
            else
                throw ErrorClass("<initialConstraintValues> object must be defined before getting the data");
        }
        else
            throw ErrorClass("<constraints> object must be defined before getting the data");
    }
    else
        throw ErrorClass("<optimization> object must be defined before getting the data");
    return initConVector;
}//getInitConValuesSparse

/**
 * get the list of initial constraint values in dense form
 * @return an array of values
 * @note return OSNaN() for constraints that are not initialed
 */
double* OSOption::getInitConValuesDense()
{
    try
    {
        int numberOfConstraints;
        numberOfConstraints = this->getNumberOfConstraints();
        if (numberOfConstraints < 0)
            throw ErrorClass("\"numberOfConstraints\" must be present to use dense methods");

        if (this->optimization != NULL)
        {
            if (this->optimization->constraints != NULL)
            {
                if (this->optimization->constraints->initialConstraintValues != NULL)
                {
                    int i,j,k;
                    int num_con;
                    num_con = this->getNumberOfInitConValues();

                    if (m_mdInitConValuesDense != NULL)
                        delete [] m_mdInitConValuesDense;
                    m_mdInitConValuesDense = new double[numberOfConstraints];
                    for (k = 0; k < numberOfConstraints; k++) m_mdInitConValuesDense[k] = OSNaN();

                    for (i = 0; i < num_con; i++)
                    {
                        j = this->optimization->constraints->initialConstraintValues->con[i]->idx;
                        if (j >= 0 && j < numberOfConstraints)
                            m_mdInitConValuesDense[j]
                                = this->optimization->constraints->initialConstraintValues->con[i]->value;
                        else
                            throw ErrorClass("Constraint index out of range");
                    }
                    return m_mdInitConValuesDense;
                }
            }
        }
    }
    catch(const ErrorClass& eclass)
    {
        throw ErrorClass(eclass.errormsg);
    }
    return NULL;
}//getInitConValuesDense

/**
 * get the list of initial constraint values in dense form
 * @param numberOfConstraints is the dimension of the array
 * @return an array of values
 * @note return OSNaN() for constraints that are not initialed
 */
double* OSOption::getInitConValuesDense(int numberOfConstraints)
{
    try
    {
        if (numberOfConstraints < 0)
            throw ErrorClass("\"numberOfConstraints\" must be present to use dense methods");

        if (this->optimization != NULL)
        {
            if (this->optimization->constraints != NULL)
            {
                if (this->optimization->constraints->initialConstraintValues != NULL)
                {
                    int i,j,k;
                    int num_con;
                    num_con = this->getNumberOfInitConValues();

                    if (m_mdInitConValuesDense != NULL)
                        delete [] m_mdInitConValuesDense;
                    m_mdInitConValuesDense = new double[numberOfConstraints];
                    for (k = 0; k < numberOfConstraints; k++) m_mdInitConValuesDense[k] = OSNaN();

                    for (i = 0; i < num_con; i++)
                    {
                        j = this->optimization->constraints->initialConstraintValues->con[i]->idx;
                        if (j >= 0 && j < numberOfConstraints)
                            m_mdInitConValuesDense[j]
                                = this->optimization->constraints->initialConstraintValues->con[i]->value;
                        else
                            throw ErrorClass("Constraint index out of range");
                    }
                    return m_mdInitConValuesDense;
                }
            }
        }
    }
    catch(const ErrorClass& eclass)
    {
        throw ErrorClass(eclass.errormsg);
    }
    return NULL;
}//getInitConValuesDense

/**
 * get the list of initial dual variables in sparse form
 * @return a list of index/value/value triples
 */
InitDualVarValue**  OSOption::getInitDualVarValuesSparse()
{
    InitDualVarValue** initDualVector;
    if (this->optimization != NULL)
    {
        if (this->optimization->constraints != NULL)
        {
            if (this->optimization->constraints->initialDualValues != NULL)
                initDualVector = this->optimization->constraints->initialDualValues->con;
            else
                throw ErrorClass("<initialDualValues> object must be defined before getting the data");
        }
        else
            throw ErrorClass("<constraints> object must be defined before getting the data");
    }
    else
        throw ErrorClass("<optimization> object must be defined before getting the data");
    return initDualVector;
}//getInitDualVarValuesSparse

/**
 * get the list of initial dual variables associated with the lower bounds in dense form
 * @return an array of values
 * @note return OSNaN() for dual variables that are not initialed
 */
double* OSOption::getInitDualVarLowerBoundsDense()
{
    try
    {
        int numberOfConstraints;
        numberOfConstraints = this->getNumberOfConstraints();
        if (numberOfConstraints < 0)
            throw ErrorClass("\"numberOfConstraints\" must be present to use dense methods");

        if (this->optimization != NULL)
        {
            if (this->optimization->constraints != NULL)
            {
                if (this->optimization->constraints->initialDualValues != NULL)
                {

                    int i,j,k;

                    int num_con;
                    num_con = this->getNumberOfInitDualVarValues();

                    if (m_mdInitDualVarLowerBoundsDense != NULL)
                        delete [] m_mdInitDualVarLowerBoundsDense;
                    m_mdInitDualVarLowerBoundsDense = new double[numberOfConstraints];
                    for (k = 0; k < numberOfConstraints; k++) m_mdInitDualVarLowerBoundsDense[k] = 0.0;

                    for (i = 0; i < num_con; i++)
                    {
                        j = this->optimization->constraints->initialDualValues->con[i]->idx;
                        if (j >= 0 && j < numberOfConstraints)
                            m_mdInitDualVarLowerBoundsDense[j]
                                = this->optimization->constraints->initialDualValues->con[i]->lbDualValue;
                        else
                            throw ErrorClass("Constraint index out of range");
                    }
                    return m_mdInitDualVarLowerBoundsDense;
                }
            }
        }
        return NULL;
    }
    catch(const ErrorClass& eclass)
    {
        throw ErrorClass(eclass.errormsg);
    }
    return NULL;
}//getInitDualVarLowerBoundsDense

/**
 * get the list of initial dual variables associated with the lower bounds in dense form
 * @param numberOfConstraints is the dimension of the array
 * @return an array of values
 * @note return OSNaN() for dual variables that are not initialed
 */
double* OSOption::getInitDualVarLowerBoundsDense(int numberOfConstraints)
{
    try
    {
        if (numberOfConstraints < 0)
            throw ErrorClass("\"numberOfConstraints\" must be present to use dense methods");

        if (this->optimization != NULL)
        {
            if (this->optimization->constraints != NULL)
            {
                if (this->optimization->constraints->initialDualValues != NULL)
                {
                    int i,j,k;
                    int num_con;
                    num_con = this->getNumberOfInitDualVarValues();

                    if (m_mdInitDualVarLowerBoundsDense != NULL)
                        delete [] m_mdInitDualVarLowerBoundsDense;
                    m_mdInitDualVarLowerBoundsDense = new double[numberOfConstraints];
                    for (k = 0; k < numberOfConstraints; k++) m_mdInitDualVarLowerBoundsDense[k] = 0.0;

                    for (i = 0; i < num_con; i++)
                    {
                        j = this->optimization->constraints->initialDualValues->con[i]->idx;
                        if (j >= 0 && j < numberOfConstraints)
                            m_mdInitDualVarLowerBoundsDense[j]
                                = this->optimization->constraints->initialDualValues->con[i]->lbDualValue;
                        else
                            throw ErrorClass("Constraint index out of range");
                    }
                    return m_mdInitDualVarLowerBoundsDense;
                }
            }
        }
        return NULL;
    }
    catch(const ErrorClass& eclass)
    {
        throw ErrorClass(eclass.errormsg);
    }
    return NULL;
}//getInitDualVarLowerBoundsDense

/**
 * get the list of initial dual variables associated with the upper bounds in dense form
 * @return an array of values
 * @note return OSNaN() for dual variables that are not initialed
 */
double* OSOption::getInitDualVarUpperBoundsDense()
{
    try
    {
        if (this->optimization != NULL)
        {
            int numberOfConstraints;
            numberOfConstraints = this->getNumberOfConstraints();
            if (numberOfConstraints < 0)
                throw ErrorClass("\"numberOfConstraints\" must be present to use dense methods");

            if (this->optimization->constraints != NULL)
            {
                if (this->optimization->constraints->initialDualValues != NULL)
                {
                    int i,j,k;
                    int num_con;
                    num_con = this->getNumberOfInitDualVarValues();
                    numberOfConstraints = this->getNumberOfConstraints();

                    if (m_mdInitDualVarUpperBoundsDense != NULL)
                        delete [] m_mdInitDualVarUpperBoundsDense;
                    m_mdInitDualVarUpperBoundsDense = new double[numberOfConstraints];
                    for (k = 0; k < numberOfConstraints; k++) m_mdInitDualVarUpperBoundsDense[k] = 0.0;

                    for (i = 0; i < num_con; i++)
                    {
                        j = this->optimization->constraints->initialDualValues->con[i]->idx;
                        if (j >= 0 && j < numberOfConstraints)
                        {
                            m_mdInitDualVarUpperBoundsDense[j]
                                = this->optimization->constraints->initialDualValues->con[i]->ubDualValue;
                        }
                        else
                            throw ErrorClass("Constraint index out of range");
                    }
                    return m_mdInitDualVarUpperBoundsDense;
                }
            }
        }
        return NULL;
    }
    catch(const ErrorClass& eclass)
    {
        throw ErrorClass(eclass.errormsg);
    }
    return NULL;
}//getInitDualVarUpperBoundsDense

/**
 * get the list of initial dual variables associated with the upper bounds in dense form
 * @param numberOfConstraints is the dimension of the array
 * @return an array of values
 * @note return OSNaN() for dual variables that are not initialed
 */
double* OSOption::getInitDualVarUpperBoundsDense(int numberOfConstraints)
{
    try
    {
        if (numberOfConstraints < 0)
            throw ErrorClass("\"numberOfConstraints\" must be present to use dense methods");

        if (this->optimization != NULL)
        {
            if (this->optimization->constraints != NULL)
            {
                if (this->optimization->constraints->initialDualValues != NULL)
                {
                    int i,j,k;
                    int num_con;
                    num_con = this->getNumberOfInitDualVarValues();
                    numberOfConstraints = this->getNumberOfConstraints();

                    if (m_mdInitDualVarUpperBoundsDense != NULL)
                        delete [] m_mdInitDualVarUpperBoundsDense;
                    m_mdInitDualVarUpperBoundsDense = new double[numberOfConstraints];
                    for (k = 0; k < numberOfConstraints; k++) m_mdInitDualVarUpperBoundsDense[k] = 0.0;

                    for (i = 0; i < num_con; i++)
                    {
                        j = this->optimization->constraints->initialDualValues->con[i]->idx;
                        if (j >= 0 && j < numberOfConstraints)
                            m_mdInitDualVarUpperBoundsDense[j]
                                = this->optimization->constraints->initialDualValues->con[i]->ubDualValue;
                        else
                            throw ErrorClass("Constraint index out of range");
                    }
                    return m_mdInitDualVarUpperBoundsDense;
                }
            }
        }
        return NULL;
    }
    catch(const ErrorClass& eclass)
    {
        throw ErrorClass(eclass.errormsg);
    }
    return NULL;
}//getInitDualVarUpperBoundsDense


/**
 * get the basis status for all slack variables in dense form
 * @return an array of int, with values corresponding to ENUM_BASIS_STATUS -- see OSGeneral.g
 * @note returns ENUM_BASIS_STATUS_unknown for slackss that are not initialed
 * @param numberOfConstraints is the dimension of the array
 */
int* OSOption::getSlackVariableInitialBasisStatusDense(int numberOfConstraints)
{
    try
    {
        if (numberOfConstraints < 0)
            throw ErrorClass("\"numberOfConstraints\" must be set to use dense methods");

        if (this->optimization == NULL)
            throw ErrorClass("<optimization> element was never set");

        if (this->optimization->constraints == NULL)
            throw ErrorClass("<optimization> <constraints> element was never set");

        if (this->optimization->constraints->initialBasisStatus == NULL)
            throw ErrorClass("initial basis was never set");

        int i,j,k;

        if (m_mdInitBasisStatusDense != NULL)
            delete [] m_mdInitBasisStatusDense;
        m_mdInitBasisStatusDense = new int[numberOfConstraints];
        for (k = 0; k < numberOfConstraints; k++) m_mdInitBasisStatusDense[k] = ENUM_BASIS_STATUS_unknown;

        int num_slack;

        if (this->optimization->constraints->initialBasisStatus->basic != NULL)
        {
            num_slack = this->optimization->constraints->initialBasisStatus->basic->numberOfEl;
            for (i = 0; i < num_slack; i++)
            {
                j = this->optimization->constraints->initialBasisStatus->basic->el[i];
                if (j >= 0 && j < numberOfConstraints)
                    m_mdInitBasisStatusDense[j] = ENUM_BASIS_STATUS_basic;
                else
                    throw ErrorClass("Constraint index out of range");
            }
        }

        if (this->optimization->constraints->initialBasisStatus->atLower != NULL)
        {
            num_slack = this->optimization->constraints->initialBasisStatus->atLower->numberOfEl;
            for (i = 0; i < num_slack; i++)
            {
                j = this->optimization->constraints->initialBasisStatus->atLower->el[i];
                if (j >= 0 && j < numberOfConstraints)
                    m_mdInitBasisStatusDense[j] = ENUM_BASIS_STATUS_atLower;
                else
                    throw ErrorClass("Constraint index out of range");
            }
        }

        if (this->optimization->constraints->initialBasisStatus->atUpper != NULL)
        {
            num_slack = this->optimization->constraints->initialBasisStatus->atUpper->numberOfEl;
            for (i = 0; i < num_slack; i++)
            {
                j = this->optimization->constraints->initialBasisStatus->atUpper->el[i];
                if (j >= 0 && j < numberOfConstraints)
                    m_mdInitBasisStatusDense[j] = ENUM_BASIS_STATUS_atUpper;
                else
                    throw ErrorClass("Constraint index out of range");
            }
        }

        if (this->optimization->constraints->initialBasisStatus->isFree != NULL)
        {
            num_slack = this->optimization->constraints->initialBasisStatus->isFree->numberOfEl;
            for (i = 0; i < num_slack; i++)
            {
                j = this->optimization->constraints->initialBasisStatus->isFree->el[i];
                if (j >= 0 && j < numberOfConstraints)
                    m_mdInitBasisStatusDense[j] = ENUM_BASIS_STATUS_isFree;
                else
                    throw ErrorClass("Constraint index out of range");
            }
        }

        if (this->optimization->constraints->initialBasisStatus->superbasic != NULL)
        {
            num_slack = this->optimization->constraints->initialBasisStatus->superbasic->numberOfEl;
            for (i = 0; i < num_slack; i++)
            {
                j = this->optimization->constraints->initialBasisStatus->superbasic->el[i];
                if (j >= 0 && j < numberOfConstraints)
                    m_mdInitBasisStatusDense[j] = ENUM_BASIS_STATUS_superbasic;
                else
                    throw ErrorClass("Constraint index out of range");
            }
        }

        return m_mdInitBasisStatusDense;
    }

    catch(const ErrorClass& eclass)
    {
        throw ErrorClass(eclass.errormsg);
    }
    return NULL;
}//getSlackVariableInitialBasisStatusDense


/**
 * get the array of other constraint options associated with a particular solver
 * @param solver_name is the name of the solver
 * @return an array of other constraint options associated with this solver
 */
std::vector<OtherConstraintOptionOrResult*>  OSOption::getOtherConstraintOptions( std::string solver_name)
{
    std::vector<OtherConstraintOptionOrResult*> optionsVector;
    if (this->optimization != NULL)
    {
        if (this->optimization->constraints != NULL)
        {
            int i;
            int num_options;
            num_options = this->getNumberOfOtherConstraintOptions();
            for(i = 0; i < num_options; i++)
                if (solver_name == this->optimization->constraints->other[ i]->solver)
                    optionsVector.push_back( this->optimization->constraints->other[ i]);
        }
        else
            throw ErrorClass("<constraints> object must be defined before getting the data");
    }
    else
        throw ErrorClass("<optimization> object must be defined before getting the data");
    return optionsVector;
}//getOtherConstraintOptions

/**
 * get the array of all other constraint options
 * @return an array of other constraint options associated with this solver
 */
OtherConstraintOptionOrResult** OSOption::getAllOtherConstraintOptions()
{
    OtherConstraintOptionOrResult** optionsVector;
    if (this->optimization != NULL)
    {
        if (this->optimization->constraints != NULL)
            optionsVector = this->optimization->constraints->other;
        else
            throw ErrorClass("<constraints> object must be defined before getting the data");
    }
    else
        throw ErrorClass("<optimization> object must be defined before getting the data");
    return optionsVector;
}//getAllOtherConstraintOptions

/**
 * Get one particular <other> constraint option from the array of options
 * <p>
 *
 * @param optionNumber is the index of the option in the array
 * @return a pointer to one OtherConstraintOption object
 */
OtherConstraintOptionOrResult* OSOption::getOtherConstraintOption(int optionNumber)
{
    if (this->optimization != NULL)
    {
        if (this->optimization->constraints != NULL)
        {
            int num_options;
            num_options = this->getNumberOfOtherConstraintOptions();
            if (optionNumber < 0 || optionNumber >= num_options)
                throw ErrorClass("optionNumber not in legal range");
            return this->optimization->constraints->other[optionNumber];
        }
        else
            throw ErrorClass("<constraints> object must be defined before getting the data");
    }
    else
        throw ErrorClass("<optimization> object must be defined before getting the data");
}//getOtherConstraintOption()

/**
 *  Get the initial values for a particular matrix variable in block form
 */
ExpandedMatrixBlocks* OSOption::getInitialMatrixVarBlocks(int mtxVarIdx, OSMatrix** matrixArray, 
                                                    int* rowPartition, int rowPartitionSize,
                                                    int* colPartition, int colPartitionSize,
                                                    ENUM_MATRIX_TYPE convertTo_,
                                                    ENUM_MATRIX_SYMMETRY symmetry_ )
                                                throw (ErrorClass)
{
    ExpandedMatrixBlocks* tmpBlocks = NULL;
    try
    {
        if (rowPartition == NULL || rowPartitionSize < 2 ||
            colPartition == NULL || colPartitionSize < 2 )
            throw ErrorClass("bad block structure requested in getInitialMatrixVarBlocks()");

        if (mtxVarIdx < 0) 
            throw ErrorClass("mtxVarIdx must not be negative in getInitialMatrixVarBlocks()");

        if (this->optimization == NULL)
            return NULL;
        if (this->optimization->matrixProgramming == NULL)
            return NULL;
        if (this->optimization->matrixProgramming->matrixVariables == NULL)
            return NULL;
        if (this->optimization->matrixProgramming->matrixVariables
                ->initialMatrixVariableValues == NULL)
            return NULL;
        
        int n = this->optimization->matrixProgramming->matrixVariables
                ->initialMatrixVariableValues->numberOfMatrixVar;
        for (int i=0; i < n; i++)
        {
            if (this->optimization->matrixProgramming->matrixVariables
                ->initialMatrixVariableValues->matrixVar[i] == NULL) continue;
            if (this->optimization->matrixProgramming->matrixVariables
                ->initialMatrixVariableValues->matrixVar[i]->matrixVarIdx != mtxVarIdx) continue;
                        
            int expIdx = this->optimization->matrixProgramming->matrixVariables
                ->initialMatrixVariableValues->matrixVar[i]
                ->getBlockExpansion(rowPartition, rowPartitionSize,
                                    colPartition, colPartitionSize,
                                    matrixArray, true, false, convertTo_, symmetry_);
            if (expIdx < 0)
               throw ErrorClass("Error during block expansion in OSOption");

            tmpBlocks = this->optimization->matrixProgramming->matrixVariables
                ->initialMatrixVariableValues->matrixVar[i]->expandedMatrixByBlocks[expIdx];
            return tmpBlocks;
        }
        return NULL;
    }
    catch (ErrorClass)
    {
    }
}//getInitialMatrixVarBlocks()

/**
 *  Get the initial values for a particular dual matrix variable in block form
 */
ExpandedMatrixBlocks* OSOption::getInitialMatrixDualVarBlocks(int mtxVarIdx, OSMatrix** matrixArray,
                                                    int* rowPartition, int rowPartitionSize,
                                                    int* colPartition, int colPartitionSize,
                                                    ENUM_MATRIX_TYPE convertTo_,
                                                    ENUM_MATRIX_SYMMETRY symmetry_ )
                                                throw (ErrorClass)
{
    ExpandedMatrixBlocks* tmpBlocks = NULL;
    try
    {
        if (rowPartition == NULL || rowPartitionSize < 2 ||
            colPartition == NULL || colPartitionSize < 2 )
            throw ErrorClass("bad block structure requested in getInitialMatrixDualVarBlocks()");

        if (mtxVarIdx < 0) 
            throw ErrorClass("mtxVarIdx must not be negative in getInitialMatrixDualVarBlocks()");

        if (this->optimization == NULL)
            return NULL;
        if (this->optimization->matrixProgramming == NULL)
            return NULL;
        if (this->optimization->matrixProgramming->matrixVariables == NULL)
            return NULL;
        if ( (this->optimization->matrixProgramming->matrixVariables->other == NULL) ||
             (this->optimization->matrixProgramming->matrixVariables
                  ->numberOfOtherMatrixVariableOptions == 0) )
            return NULL;

        int nOther = this->optimization->matrixProgramming->matrixVariables
                         ->numberOfOtherMatrixVariableOptions;

        for (int i=0; i < nOther; i++)
        {
            if (this->optimization->matrixProgramming->matrixVariables->other[i]->name !=
                    "initialMatrixDuals") continue;

            // found initial matrix duals. If this option is repeated, ignore all but the first
            OtherMatrixVariableOptionOrResult* initialMatrixDuals =
                this->optimization->matrixProgramming->matrixVariables->other[i];

            if (initialMatrixDuals->numberOfMatrixVar == 0 || 
                initialMatrixDuals->matrixVar         == NULL )
                return NULL;
        
            for (int i=0; i < initialMatrixDuals->numberOfMatrixVar; i++)
            {
                if (initialMatrixDuals->matrixVar[i] == NULL) continue;
                if (initialMatrixDuals->matrixVar[i]->matrixVarIdx != mtxVarIdx) continue;
            
                int expIdx = initialMatrixDuals->matrixVar[i]
                    ->getBlockExpansion(rowPartition, rowPartitionSize,
                                        colPartition, colPartitionSize,
                                        matrixArray, true, false, convertTo_, symmetry_);
                if (expIdx < 0)
                    throw ErrorClass("Error during block expansion in OSOption");

                tmpBlocks = initialMatrixDuals->matrixVar[i]->expandedMatrixByBlocks[expIdx];
                return tmpBlocks;
            }
            return NULL;
        }
        return NULL;
    }
    catch (ErrorClass)
    {
    }
}//getInitialMatrixDualVarBlocks()


/**
 * get the array of solver options associated with a particular solver
 * @param solver_name is the name of the solver
 * @return an array of solver options associated with this solver
 */
std::vector<SolverOptionOrResult*>  OSOption::getSolverOptions( std::string solver_name)
{
    std::vector<SolverOptionOrResult*> optionsVector;
    if (this->optimization != NULL)
    {
        if (this->optimization->solverOptions != NULL)
        {
            int i;
            int num_options;
            num_options = this->getNumberOfSolverOptions();
            for(i = 0; i < num_options; i++)
                if (solver_name == this->optimization->solverOptions->solverOption[ i]->solver)
                    optionsVector.push_back( this->optimization->solverOptions->solverOption[ i]);
        }
        else
            throw ErrorClass("<solverOptions> object must be defined before getting the data");
    }
    else
        throw ErrorClass("<optimization> object must be defined before getting the data");
    return optionsVector;
}//getSolverOptions


/**
 * get the array of solver options associated with a particular solver and
 * the solver options not associated with any solver (if desired)
 * @param solver_name is the name of the solver
 * @param getFreeOptions is a boolean controlling whether unassociated (free)
 *        options should be returned or not
 * @return an array of solver options associated with this solver
 */
std::vector<SolverOptionOrResult*>  OSOption::getSolverOptions( std::string solver_name, bool getFreeOptions)
{
    std::vector<SolverOptionOrResult*> optionsVector;
    if (this->optimization != NULL)
    {
        if (this->optimization->solverOptions != NULL)
        {
            int i;
            int num_options;
            num_options = this->getNumberOfSolverOptions();
            for (i = 0; i < num_options; i++)
            {
                if (this->optimization->solverOptions->solverOption[i]->solver == solver_name ||
                        (this->optimization->solverOptions->solverOption[i]->solver == "" && getFreeOptions))
                    optionsVector.push_back( this->optimization->solverOptions->solverOption[i]);
            }
        }
        else
            throw ErrorClass("<solverOptions> object must be defined before getting the data");
    }
    else
        throw ErrorClass("<optimization> object must be defined before getting the data");
    return optionsVector;
}//getSolverOptions
/**
 * get the array of all solver options
 * @return an array of other constraint options associated with this solver
 */
SolverOptionOrResult** OSOption::getAllSolverOptions()
{
    SolverOptionOrResult** optionsVector;
    if (this->optimization != NULL)
    {
        if (this->optimization->solverOptions != NULL)
            optionsVector = this->optimization->solverOptions->solverOption;
        else
            throw ErrorClass("<solverOptions> object must be defined before getting the data");
    }
    else
        throw ErrorClass("<optimization> object must be defined before getting the data");
    return optionsVector;
}//getAllOtherConstraintOptions



/**
 *  ---------------------------------------------------------
 *      set() options
 *  ---------------------------------------------------------
 */

/* ----------------------------------------------------------
 * Start with a number of set() and add() methods for arrays
 * used in various subelements.
 * These have been put here in order of appearance
 * ----------------------------------------------------------*/

/** setOther()
 *  set an array of <other> elements in <general>, <system>, <service> and <job>
 */
bool OtherOptions::setOther(int numberOfOptions, OtherOptionOrResult** other)
{
    try
    {
        if (this->other != NULL)
            throw ErrorClass( "otherOptions array previously used.");

        if (numberOfOptions < 0)
            throw ErrorClass( "length of otherOptions array cannot be negative.");

        this->numberOfOtherOptions = numberOfOptions;
        if (numberOfOptions == 0)
            return true;

        this->other = new OtherOptionOrResult*[numberOfOptions];

        int  i;
        for (i = 0; i < numberOfOptions; i++)
        {
            this->other[i] = new OtherOptionOrResult();
            *this->other[i] = *other[i];
        }
        return true;
    }
    catch(const ErrorClass& eclass)
    {
        osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_error, eclass.errormsg);
        return false;
    }
}//setOther

/** addOther()
 *  used to add an <other> element in <general>, <system>, <service>, <job> etc.
 */
bool OtherOptions::addOther(std::string name, std::string value, std::string description)
{
    try
    {
        int nopt;
        int i;
        if (name.empty() )
            throw ErrorClass( "the name of an option cannot be empty." );

        if (this->other == NULL)
            nopt = 0;
        else
            nopt = this->numberOfOtherOptions;

        OtherOptionOrResult** temp = new OtherOptionOrResult*[nopt+1];  //Allocate the new pointers
        for (i = 0; i < nopt; i++)
            temp[i] = this->other[i];  //copy the pointers

        delete[] this->other; //delete old pointers

//    add in the new element
        temp[ nopt] = new OtherOptionOrResult();

        temp[ nopt]->name = name;
        temp[ nopt]->value = value;
        temp[ nopt]->description = description;

        this->other = temp;   //hook the new pointers into the data structure
        this->numberOfOtherOptions = ++nopt;

        return true;
    }
    catch(const ErrorClass& eclass)
    {
        osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_error, eclass.errormsg);
        return false;
    }
}//addOther

/**
 * A function to set an array of <jobID> elements
 * @param numberOfJobIDs: number of <jobID> elements to be set
 * @param jobID: the array of <jobID> elements that are to be set
 */
bool JobDependencies::setJobID(int numberOfJobIDs, std::string *jobID)
{
    try
    {
        if (this->jobID != NULL)
        //    throw ErrorClass( "jobID array previously used.");
            return false;

        if (numberOfJobIDs < 0)
        //    throw ErrorClass( "length of jobID array cannot be negative.");
            return false;

        this->numberOfJobIDs = numberOfJobIDs;
        if (numberOfJobIDs == 0)
            return true;

        this->jobID = new std::string[numberOfJobIDs];
        int i;
        for (i = 0; i < numberOfJobIDs; i++)
            this->jobID[i] = jobID[i];

        return true;
    }
    catch(const ErrorClass& eclass)
    {
        osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_error, eclass.errormsg);
        return false;
    }
}//setJobID

/**
 *
 * A function to add an <jobID> element
 * @param jobID: the name of the <jobID> element to be added
 */
bool JobDependencies::addJobID(std::string jobID)
{
    try
    {
        int nopt;
        if (jobID.empty() )
        //    throw ErrorClass( "the name of a jobID cannot be empty." );
            return false;

        if (this->jobID == NULL)
            nopt = 0;
        else
            nopt = this->numberOfJobIDs;

        std::string* temp = new std::string[nopt+1];
        int i;
        for (i = 0; i < nopt; i++)
            temp[i] = this->jobID[i]; // create the new jobID

        delete[] this->jobID;

        temp[nopt] = jobID;

        this->jobID = temp;
        this->numberOfJobIDs = ++nopt;
        return true;
    }
    catch(const ErrorClass& eclass)
    {
        osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_error, eclass.errormsg);
        return false;
    }
}//addJobID

/**
 *
 * A function to set an array of <path> elements
 * @param numberOfPaths: number of <path> elements to be set
 * @param path: the array of <path> elements that are to be set
 */
bool DirectoriesAndFiles::setPath(int numberOfPaths, std::string *path)
{
    try
    {
        if (this->path != NULL)
        //    throw ErrorClass( "path array previously used.");
            return false;

        if (numberOfPaths < 0)
        //    throw ErrorClass( "length of path array cannot be negative.");
            return false;

        this->numberOfPaths = numberOfPaths;
        if (numberOfPaths == 0)
            return true;

        this->path = new std::string[numberOfPaths];
        int i;
        for (i = 0; i < numberOfPaths; i++)
            this->path[i] = path[i];

        return true;
    }
    catch(const ErrorClass& eclass)
    {
        osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_error, eclass.errormsg);
        return false;
    }
}//setPath

/**
 *
 * A function to add a <path> element
 * @param path: the path to be added
 */
bool DirectoriesAndFiles::addPath(std::string path)
{
    try
    {
        int nopt;
        if (path.empty() )
        //    throw ErrorClass( "the path cannot be empty." );
            return false;

        if (this->path == NULL)
            nopt = 0;
        else
            nopt = this->numberOfPaths;

        std::string* temp = new std::string[nopt+1];
        int i;
        for (i = 0; i < nopt; i++)
            temp[i] = this->path[i]; // create the new path

        delete[] this->path;

        temp[nopt] = path;

        this->path = temp;
        this->numberOfPaths = ++nopt;
        return true;
    }
    catch(const ErrorClass& eclass)
    {
        osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_error, eclass.errormsg);
        return false;
    }
}//addPath

/**
 *
 * A function to set an array of <pathPair> elements
 * @param numberOfPathPairs: number of <pathPair> elements to be set
 * @param path: the array of <pathPair> elements that are to be set
 */
bool PathPairs::setPathPair(int numberOfPathPairs, PathPair **pathPair)
{
    try
    {
        if (this->pathPair != NULL)
        //    throw ErrorClass( "pathPair array previously used.");
            return false;

        if (numberOfPathPairs < 0)
        //    throw ErrorClass( "length of pathPair array cannot be negative.");
            return false;

        this->numberOfPathPairs = numberOfPathPairs;
        if (numberOfPathPairs == 0)
            return true;

        this->pathPair = new PathPair*[numberOfPathPairs];

        int  i;
        for (i = 0; i < numberOfPathPairs; i++)
        {
             this->pathPair[i] = new PathPair();
            *this->pathPair[i] = *pathPair[i];
        }
        return true;
    }
    catch(const ErrorClass& eclass)
    {
        osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_error, eclass.errormsg);
        return false;
    }
}//setPathPair


bool PathPairs::setPathPair(std::string *from, std::string *to, bool *makeCopy, int numberOfPathPairs)
{
//    if (this->pathPair != NULL)
//        return false;

    this->numberOfPathPairs = numberOfPathPairs;
    if (numberOfPathPairs == 0)
        return true;

    this->pathPair = new PathPair*[numberOfPathPairs];

    int  i;
    for (i = 0; i < numberOfPathPairs; i++)
    {
        this->pathPair[i] = new PathPair();
        this->pathPair[i]->from = from[i];
        this->pathPair[i]->to = to[i];
        this->pathPair[i]->makeCopy = makeCopy[i];
    }
    return true;
}//setPathPair

/**
 *
 * A function to add a <pathPair> element
 * @param fromPath: the path from which to copy or move
 * @param toPath: the path to which to copy or move
 * @param makecopy: tracks whether a copy is to be made
 */
bool PathPairs::addPathPair(std::string fromPath, std::string toPath, bool makeCopy)
{
    try
    {
        int nopt;
        int i;
        if (fromPath.empty() )
        //    throw ErrorClass( "the \"from\" path cannot be empty." );
            return false;
        if (toPath.empty() )
        //    throw ErrorClass( "the \"to\" path cannot be empty." );
            return false;

        if (this->pathPair == NULL)
            nopt = 0;
        else
            nopt = this->numberOfPathPairs;

        PathPair** temp = new PathPair*[nopt+1];  //Allocate the new pointers
        for (i = 0; i < nopt; i++)
            temp[i] = this->pathPair[i];  //copy the pointers

        delete[] this->pathPair; //delete old pointers

//    add in the new element
        temp[ nopt] = new PathPair();

        temp[ nopt]->from = fromPath;
        temp[ nopt]->to = toPath;
        temp[ nopt]->makeCopy = makeCopy;

        this->pathPair = temp;   //hook the new pointers into the data structure
        this->numberOfPathPairs = ++nopt;

        return true;
    }
    catch(const ErrorClass& eclass)
    {
        osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_error, eclass.errormsg);
        return false;
    }
}//addPathPair

/**
 *
 * A function to set an array of <process> elements
 * @param numberOfProcesses: number of <process> elements to be set
 * @param path: the array of <process> elements that are to be set
 */
bool Processes::setProcess(int numberOfProcesses, std::string *process)
{
    try
    {
        if (this->process != NULL)
        //    throw ErrorClass( "process array previously used.");
            return false;

        if (numberOfProcesses < 0)
        //    throw ErrorClass( "length of process array cannot be negative.");
            return false;

        this->numberOfProcesses= numberOfProcesses;
        if (numberOfProcesses == 0)
            return true;

        this->process = new std::string[numberOfProcesses];
        int i;
        for (i = 0; i < numberOfProcesses; i++)
            this->process[i] = process[i];

        return true;
    }
    catch(const ErrorClass& eclass)
    {
        osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_error, eclass.errormsg);
        return false;
    }
}//setProcess

/**
 *
 * A function to add a <process> element
 * @param process: the ID of the process to be added
 */
bool Processes::addProcess(std::string process)
{
    try
    {
        int nopt;
        if (process.empty() )
            throw ErrorClass( "the name of a process cannot be empty." );

        if (this->process == NULL)
            nopt = 0;
        else
            nopt = this->numberOfProcesses;

        std::string* temp = new std::string[nopt+1];
        int i;
        for (i = 0; i < nopt; i++)
            temp[i] = this->process[i]; // create the new jobID

        delete[] this->process;

        temp[nopt] = process;

        this->process = temp;
        this->numberOfProcesses = ++nopt;
        return true;
    }
    catch(const ErrorClass& eclass)
    {
        osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_error, eclass.errormsg);
        return false;
    }
}//addProcess

/**
 *
 * A function to set an array of <var> elements
 * @param numberOfVar: number of <var> elements to be set
 * @param var: the array of <var> elements that are to be set
 */
bool InitVariableValues::setVar(int numberOfVar, InitVarValue **var)
{
    try
    {
        if (this->var != NULL)
            throw ErrorClass( "InitVarValue array previously used.");

        if (numberOfVar < 0)
            throw ErrorClass( "length of var array cannot be negative.");

        this->numberOfVar = numberOfVar;
        if (numberOfVar == 0)
            return true;

        this->var = new InitVarValue*[numberOfVar];

        int  i;
        for (i = 0; i < numberOfVar; i++)
        {
            this->var[i] = new InitVarValue();
           *this->var[i] = *var[i];
        }
        return true;
    }
    catch(const ErrorClass& eclass)
    {
        osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_error, eclass.errormsg);
        return false;
    }
}//setVar

/**
 *
 * A function to set an array of <var> elements
 * @param numberOfVar: number of <var> elements to be set
 * @param var: the array of <var> elements that are to be set
 * @param disp: method of disposition if previous data exist
 */
bool InitVariableValues::setVar(int numberOfVar, InitVarValue **var, ENUM_COMBINE_ARRAYS disp)
{
    try
    {
        if (this->var != NULL)
        {
            if (disp == ENUM_COMBINE_ARRAYS_throw)
                throw ErrorClass( "InitVarValue array previously used.");
            if (disp == ENUM_COMBINE_ARRAYS_ignore)
                return true;

            if (disp == ENUM_COMBINE_ARRAYS_merge)
                return this->addVar(numberOfVar, var);

            //here we replace the old data
            for (int i = 0; i < this->numberOfVar; i++)
                delete this->var[i];
            delete [] this->var;
            this->var = NULL;
        }

        if (numberOfVar < 0)
            throw ErrorClass( "length of var array cannot be negative.");

        this->numberOfVar = numberOfVar;
        if (numberOfVar == 0)
            return true;

        this->var = new InitVarValue*[numberOfVar];

        int  i;
        for (i = 0; i < numberOfVar; i++)
        {
            this->var[i] = new InitVarValue();
           *this->var[i] = *var[i];
        }
        return true;
    }
    catch(const ErrorClass& eclass)
    {
        osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_error, eclass.errormsg);
        return false;
    }
}//setVar


/**
 *
 * A function to set an array of <var> elements
 * @param numberOfVar: number of <var> elements to be set
 * @param idx: the array of indices for the elements that are to be set
 * @param value: the array of the corresponding values
 * @param name: the array of the corresponding names
 */
bool InitVariableValues::setVar(int numberOfVar, int *idx, double *value, std::string *name)
{
    if (this->var != NULL)
        return false;

    if (numberOfVar < 0)
        return false;

    this->numberOfVar = numberOfVar;
    if (numberOfVar == 0)
        return true;

    this->var = new InitVarValue*[numberOfVar];

    int  i;
    for (i = 0; i < numberOfVar; i++)
    {
        this->var[i] = new InitVarValue();
        this->var[i]->idx = idx[i];
        this->var[i]->name = name[i];
        this->var[i]->value = value[i];
    }
    return true;
}//setVar

/**
 *
 * A function to add a <var> element
 * @param idx: the index of the variable to be given an initial value
 * @param value: the initial variable value to be added
 */
bool InitVariableValues::addVar(int idx, double value)
{
    try
    {
        int nopt;
        int i;
        if (idx < 0)
            throw ErrorClass( "the index of a variable cannot be negative." );

        if (this->var == NULL)
            nopt = 0;
        else
            nopt = this->numberOfVar;

        InitVarValue** temp = new InitVarValue*[nopt+1];  //Allocate the new pointers
        for (i = 0; i < nopt; i++)
            temp[i] = this->var[i];  //copy the pointers

        delete[] this->var; //delete old pointers

//    add in the new element
        temp[ nopt] = new InitVarValue();

        temp[ nopt]->idx = idx;
        temp[ nopt]->value = value;

        this->var = temp;   //hook the new pointers into the data structure
        this->numberOfVar = ++nopt;

        return true;
    }
    catch(const ErrorClass& eclass)
    {
        osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_error, eclass.errormsg);
        return false;
    }
}//addVar

/**
 * A function to add several <var> elements
 * @param numberOfVar: number of <var> elements to be added
 * @param var: the array of <var> elements that are to be added
 */
bool InitVariableValues::addVar(int numberOfVar, InitVarValue **var)
{
    try
    {
        if (numberOfVar < 0)
            throw ErrorClass( "length of var array cannot be negative.");

        if (numberOfVar == 0)
            return true;

        int nprev = this->numberOfVar;

        InitVarValue** temp = new InitVarValue*[nprev+numberOfVar];  //Allocate the new pointers
        for (int i = 0; i < nprev; i++)
            temp[i] = this->var[i];  //copy the pointers

        delete[] this->var; //delete old pointers

//    add in the new elements
        for (int i=0; i < numberOfVar; i++)
        {
            temp[nprev+i] = new InitVarValue();
           *temp[nprev+i] = *var[i];
        }

        this->var = temp;   //hook the new pointers into the data structure
           this->numberOfVar = nprev + numberOfVar;

        return true;
    }
    catch(const ErrorClass& eclass)
    {
        osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_error, eclass.errormsg);
        return false;
    }
}//addVar

/**
 *
 * A function to set an array of <var> elements
 * @param numberOfVar: number of <var> elements to be set
 * @param var: the array of <var> elements that are to be set
 */
bool InitVariableValuesString::setVar(int numberOfVar, InitVarValueString **var)
{
    try
    {
        if (this->var != NULL)
            throw ErrorClass( "InitVarValueString array previously used.");

        if (numberOfVar < 0)
            throw ErrorClass( "length of var array cannot be negative.");

        this->numberOfVar = numberOfVar;
        if (numberOfVar == 0)
            return true;

        this->var = new InitVarValueString*[numberOfVar];

        int  i;
        for (i = 0; i < numberOfVar; i++)
        {
            this->var[i] = new InitVarValueString();
           *this->var[i] = *var[i];
        }
        return true;
    }
    catch(const ErrorClass& eclass)
    {
        osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_error, eclass.errormsg);
        return false;
    }
}//setVar

/**
 *
 * A function to set an array of <var> elements
 * @param numberOfVar: number of <var> elements to be set
 * @param var: the array of <var> elements that are to be set
 */
bool InitVariableValuesString::setVar(int numberOfVar, InitVarValueString **var, ENUM_COMBINE_ARRAYS disp)
{
    try
    {
        if (this->var != NULL)
        {
            if (disp == ENUM_COMBINE_ARRAYS_throw)
                throw ErrorClass( "InitVarValueString array previously used.");
            if (disp == ENUM_COMBINE_ARRAYS_ignore)
                return true;
            if (disp == ENUM_COMBINE_ARRAYS_merge)
                return this->addVar(numberOfVar, var);

            //here we replace the old data
            for (int i = 0; i < this->numberOfVar; i++)
                delete this->var[i];
            delete [] this->var;
            this->var = NULL;
        }            
            
        if (numberOfVar < 0)
            throw ErrorClass( "length of var array cannot be negative.");

        this->numberOfVar = numberOfVar;
        if (numberOfVar == 0)
            return true;

        this->var = new InitVarValueString*[numberOfVar];

        int  i;
        for (i = 0; i < numberOfVar; i++)
        {
            this->var[i] = new InitVarValueString();
           *this->var[i] = *var[i];
        }
        return true;
    }
    catch(const ErrorClass& eclass)
    {
        osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_error, eclass.errormsg);
        return false;
    }
}//setVar

/**
 *
 * A function to set an array of <var> elements
 * @param numberOfVar: number of <var> elements to be set
 * @param idx: the array of indices for the elements that are to be set
 * @param value: the array of the corresponding values
 * @param name: the array of the corresponding names
 */
bool InitVariableValuesString::setVar(int numberOfVar, int *idx, std::string *value, std::string *name)
{
    if (this->var != NULL)
        return false;


    if (numberOfVar < 0)
        return false;

    this->numberOfVar = numberOfVar;
    if (numberOfVar == 0)
        return true;

    this->var = new InitVarValueString*[numberOfVar];

    int  i;
    for (i = 0; i < numberOfVar; i++)
    {
        this->var[i] = new InitVarValueString();
        this->var[i]->idx = idx[i];
        this->var[i]->name = name[i];
        this->var[i]->value = value[i];
    }
    return true;
}//setVar

/**
 *
 * A function to add a <var> element
 * @param idx: the index of the variable to be given an initial value
 * @param value: the initial string value to be added
 */
bool InitVariableValuesString::addVar(int idx, std::string value)
{
    try
    {
        int nopt;
        int i;
        if (idx < 0)
            throw ErrorClass( "the index of a variable cannot be negative." );

        if (this->var == NULL)
            nopt = 0;
        else
            nopt = this->numberOfVar;

        InitVarValueString** temp = new InitVarValueString*[nopt+1];  //Allocate the new pointers
        for (i = 0; i < nopt; i++)
            temp[i] = this->var[i];  //copy the pointers

        delete[] this->var; //delete old pointers

//    add in the new element
        temp[ nopt] = new InitVarValueString();

        temp[ nopt]->idx = idx;
        temp[ nopt]->value = value;

        this->var = temp;   //hook the new pointers into the data structure
        this->numberOfVar = ++nopt;

        return true;
    }
    catch(const ErrorClass& eclass)
    {
        osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_error, eclass.errormsg);
        return false;
    }
}//addVar

/**
 *
 * A function to add several <var> elements
 * @param numberOfVar: number of <var> elements to be added
 * @param var: the array of <var> elements that are to be added
 */
bool InitVariableValuesString::addVar(int numberOfVar, InitVarValueString **var)
{
    try
    {
        if (numberOfVar < 0)
            throw ErrorClass( "length of var array cannot be negative.");

        if (numberOfVar == 0)
            return true;

        int nprev = this->numberOfVar;

        InitVarValueString** temp = new InitVarValueString*[nprev+numberOfVar];  //Allocate the new pointers
        for (int i = 0; i < nprev; i++)
            temp[i] = this->var[i];  //copy the pointers

        delete[] this->var; //delete old pointers

//    add in the new elements
        for (int i=0; i < numberOfVar; i++)
        {
            temp[nprev+i] = new InitVarValueString();
           *temp[nprev+i] = *var[i];
        }

        this->var = temp;   //hook the new pointers into the data structure
           this->numberOfVar = nprev + numberOfVar;

        return true;
    }
    catch(const ErrorClass& eclass)
    {
        osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_error, eclass.errormsg);
        return false;
    }
}//addVar

/**
 *
 * A function to set an array of <var> elements
 * @param numberOfVar: number of <var> elements to be set
 * @param var: the array of <var> elements to be that are to be set
 */
bool InitialBasisStatus::setVar(int numberOfVar, InitBasStatus **var)
{
    try
    {
        if (this->var != NULL)
            throw ErrorClass( "InitBasStatus array previously used.");

        if (numberOfVar < 0)
            throw ErrorClass( "length of var array cannot be negative.");

        this->numberOfVar = numberOfVar;
        if (numberOfVar == 0)
            return true;

        this->var = new InitBasStatus*[numberOfVar];

        int  i;
        for (i = 0; i < numberOfVar; i++)
        {
            this->var[i] = new InitBasStatus();
           *this->var[i] = *var[i];
        }
        return true;
    }
    catch(const ErrorClass& eclass)
    {
        osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_error, eclass.errormsg);
        return false;
    }
}//setVar

/**
 *
 * A function to add a <var> element
 * @param idx: the index of the variable to be given an initial basis status
 * @param value: the initial basis status to be added
 */
bool InitialBasisStatus::addVar(int idx, std::string value)
{
    try
    {
        int nopt;
        int i;
        if (idx < 0)
            throw ErrorClass( "the index of a variable cannot be negative." );
        if (value != "atLower" && value != "basic" && value != "unknown" &&
                value != "atUpper" && value != "superbasic" )
            throw ErrorClass( "Illegal basis status " + value );

        if (this->var == NULL)
            nopt = 0;
        else
            nopt = this->numberOfVar;

        InitBasStatus** temp = new InitBasStatus*[nopt+1];  //Allocate the new pointers
        for (i = 0; i < nopt; i++)
            temp[i] = this->var[i];  //copy the pointers

        delete[] this->var; //delete old pointers

//    add in the new element
        temp[ nopt] = new InitBasStatus();

        temp[ nopt]->idx = idx;
        temp[ nopt]->value = value;

        this->var = temp;   //hook the new pointers into the data structure
        this->numberOfVar = ++nopt;

        return true;
    }
    catch(const ErrorClass& eclass)
    {
        osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_error, eclass.errormsg);
        return false;
    }
}//addVar

/**
 *
 * A function to set an array of <var> elements
 * @param numberOfVar: number of <var> elements to be set
 * @param var: the array of <var> elements to be that are to be set
 */
bool IntegerVariableBranchingWeights::setVar(int numberOfVar, BranchingWeight **var)
{
    try
    {
        if (this->var != NULL)
            return false;

        if (numberOfVar < 0)
            return false;

        this->numberOfVar = numberOfVar;
        if (numberOfVar == 0)
            return true;

        this->var = new BranchingWeight*[numberOfVar];

        int  i;
        for (i = 0; i < numberOfVar; i++)
        {
            this->var[i] = new BranchingWeight();
           *this->var[i] = *var[i];
        }
        return true;
    }
    catch(const ErrorClass& eclass)
    {
        osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_error, eclass.errormsg);
        return false;
    }
}//setVar

/**
 *
 * A function to set an array of <var> elements
 * @param numberOfVar: number of <var> elements to be set
 * @param var: the array of <var> elements to be that are to be set
 */
bool IntegerVariableBranchingWeights::setVar(int numberOfVar, BranchingWeight **var, ENUM_COMBINE_ARRAYS disp)
{
    try
    {
        if (this->var != NULL)
        {
            if (disp == ENUM_COMBINE_ARRAYS_throw)
                throw ErrorClass( "BranchingWeight array previously used.");
            if (disp == ENUM_COMBINE_ARRAYS_ignore)
                return true;
            if (disp == ENUM_COMBINE_ARRAYS_merge)
                return this->addVar(numberOfVar, var);

            //here we replace the old data
            for (int i = 0; i < this->numberOfVar; i++)
                delete this->var[i];
            delete [] this->var;
            this->var = NULL;
        }

        if (numberOfVar < 0)
            throw ErrorClass( "length of var array cannot be negative.");

        this->numberOfVar = numberOfVar;
        if (numberOfVar == 0)
            return true;

        this->var = new BranchingWeight*[numberOfVar];

        int  i;
        for (i = 0; i < numberOfVar; i++)
        {
            this->var[i] = new BranchingWeight();
           *this->var[i] = *var[i];
        }
        return true;
    }
    catch(const ErrorClass& eclass)
    {
        osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_error, eclass.errormsg);
        return false;
    }
}//setVar

/**
 *
 * A function to set an array of <var> elements
 * @param numberOfVar: number of <var> elements to be set
 * @param idx: the array of indices for the elements that are to be set
 * @param value: the array of the corresponding values
 * @param name: the array of the corresponding names
 */
bool IntegerVariableBranchingWeights::setVar(int numberOfVar, int *idx, double *value, std::string *name)
{
    if (this->var != NULL)
        return false;

    if (numberOfVar < 0)
        return false;

    this->numberOfVar = numberOfVar;
    if (numberOfVar == 0)
        return true;

    this->var = new BranchingWeight*[numberOfVar];

    int  i;
    for (i = 0; i < numberOfVar; i++)
    {
        this->var[i] = new BranchingWeight();
        this->var[i]->idx = idx[i];
        this->var[i]->name = name[i];
        this->var[i]->value = value[i];
    }
    return true;
}//setVar





/**
 *
 * A function to add a <var> element
 * @param idx: the index of the variable to be given a branching weight
 * @param value: the branching weight to be added
 */
bool IntegerVariableBranchingWeights::addVar(int idx, double value)
{
    try
    {
        int nopt;
        int i;
        if (idx < 0)
            throw ErrorClass( "the index of a variable cannot be negative." );

        if (this->var == NULL)
            nopt = 0;
        else
            nopt = this->numberOfVar;

        BranchingWeight** temp = new BranchingWeight*[nopt+1];  //Allocate the new pointers
        for (i = 0; i < nopt; i++)
            temp[i] = this->var[i];  //copy the pointers

        delete[] this->var; //delete old pointers

//    add in the new element
        temp[ nopt] = new BranchingWeight();

        temp[ nopt]->idx = idx;
        temp[ nopt]->value = value;

        this->var = temp;   //hook the new pointers into the data structure
        this->numberOfVar = ++nopt;

        return true;
    }
    catch(const ErrorClass& eclass)
    {
        osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_error, eclass.errormsg);
        return false;
    }
}//addVar

/**
 * A function to add several <var> elements
 * @param numberOfVar: number of <var> elements to be added
 * @param var: the array of <var> elements that are to be added
 */
bool IntegerVariableBranchingWeights::addVar(int numberOfVar, BranchingWeight **var)
{
    try
    {
        if (numberOfVar < 0)
            throw ErrorClass( "length of var array cannot be negative.");

        if (numberOfVar == 0)
            return true;

        int nprev = this->numberOfVar;

        BranchingWeight** temp = new BranchingWeight*[nprev+numberOfVar];  //Allocate the new pointers
        for (int i = 0; i < nprev; i++)
            temp[i] = this->var[i];  //copy the pointers

        delete[] this->var; //delete old pointers

//    add in the new elements
        for (int i=0; i < numberOfVar; i++)
        {
            temp[nprev+i] = new BranchingWeight();
           *temp[nprev+i] = *var[i];
        }

        this->var = temp;   //hook the new pointers into the data structure
           this->numberOfVar = nprev + numberOfVar;

        return true;
    }
    catch(const ErrorClass& eclass)
    {
        osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_error, eclass.errormsg);
        return false;
    }
}//addVar

/**
 *
 * A function to set an array of <var> elements
 * @param numberOfVar: number of <var> elements to be set
 * @param var: the array of <var> elements that are to be set
 */
bool SOSWeights::setVar(int numberOfVar, BranchingWeight **var)
{
    try
    {
        if (this->var != NULL)
            throw ErrorClass( "BranchingWeight array previously used.");

        if (numberOfVar < 0)
            throw ErrorClass( "length of var array cannot be negative.");

        this->numberOfVar = numberOfVar;
        if (numberOfVar == 0)
            return true;

        this->var = new BranchingWeight*[numberOfVar];

        int  i;
        for (i = 0; i < numberOfVar; i++)
        {
            this->var[i] = new BranchingWeight();
           *this->var[i] = *var[i];
        }
        return true;
    }
    catch(const ErrorClass& eclass)
    {
        osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_error, eclass.errormsg);
        return false;
    }
}//setVar

/**
 *
 * A function to add a <var> element
 * @param idx: the index of the variable to be given a branching weight
 * @param value: the branching weight to be added
 */
bool SOSWeights::addVar(int idx, double value)
{
    try
    {
        int nopt;
        int i;
        if (idx < 0)
            throw ErrorClass( "the index of a variable cannot be negative." );

        if (this->var == NULL)
            nopt = 0;
        else
            nopt = this->numberOfVar;

        BranchingWeight** temp = new BranchingWeight*[nopt+1];  //Allocate the new pointers
        for (i = 0; i < nopt; i++)
            temp[i] = this->var[i];  //copy the pointers

        delete[] this->var; //delete old pointers

//    add in the new element
        temp[ nopt] = new BranchingWeight();

        temp[ nopt]->idx = idx;
        temp[ nopt]->value = value;

        this->var = temp;   //hook the new pointers into the data structure
        this->numberOfVar = ++nopt;

        return true;
    }
    catch(const ErrorClass& eclass)
    {
        osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_error, eclass.errormsg);
        return false;
    }
}//addVar

/**
 *
 * A function to set an array of <sos> elements
 * @param numberOfSOS: number of <sos> elements to be set
 * @param sos: the array of <sos> elements that are to be set
 */
bool SOSVariableBranchingWeights::setSOS(int numberOfSOS, SOSWeights **sos)
{
    try
    {
        if (this->sos != NULL)
            throw ErrorClass( "SOS array previously used.");

        if (numberOfSOS < 0)
            throw ErrorClass( "length of sos array cannot be negative.");

        this->numberOfSOS = numberOfSOS;
        if (numberOfSOS == 0) return true;

        this->sos = new SOSWeights*[numberOfSOS];

        int  i, j;
        for (i = 0; i < numberOfSOS; i++)
        {
            this->sos[i] = new SOSWeights();
            this->sos[i]->sosIdx      = sos[i]->sosIdx;
            this->sos[i]->groupWeight = sos[i]->groupWeight;

            if (sos[i]->numberOfVar < 0)
                throw ErrorClass( "the number of variables in the SOS cannot be negative.");

            this->sos[i]->numberOfVar = sos[i]->numberOfVar;

            if (sos[i]->numberOfVar > 0)
            {
                this->sos[i]->var = new BranchingWeight*[sos[i]->numberOfVar];
                for (j = 0; j < sos[i]->numberOfVar; j++)
                {
                    this->sos[i]->var[j] = new BranchingWeight();
                   *this->sos[i]->var[j] = *sos[i]->var[j];
                }
            }
        }
        return true;
    }
    catch(const ErrorClass& eclass)
    {
        osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_error, eclass.errormsg);
        return false;
    }
}//setSOS

/**
 *
 * A function to add an <sos> element
 * @param sos: the content of the <sos> element that is to be added
 */
bool SOSVariableBranchingWeights::addSOS(int sosIdx, int nvar, double weight, int* idx, double* value, std::string* name)
{
    try
    {
        int nopt;
        int i;
        if (sosIdx < 0)
            throw ErrorClass( "the index of the SOS cannot be negative." );
        if (nvar < 0)
            throw ErrorClass( "the number of variables in the SOS cannot be negative." );

        if (this->sos  == NULL)
            nopt = 0;
        else
            nopt = this->numberOfSOS;

        SOSWeights** temp = new SOSWeights*[nopt+1];  //Allocate the new pointers
        for (i = 0; i < nopt; i++)
            temp[i] = this->sos[i];  //copy the pointers

        delete[] this->sos; //delete old pointers

//    add in the new element
        temp[ nopt] = new SOSWeights();

        temp[ nopt]->sosIdx = sosIdx;
        temp[ nopt]->groupWeight = weight;
        temp[ nopt]->numberOfVar = nvar;
        temp[ nopt]->var = new BranchingWeight*[nvar];
        for (i = 0; i < nvar; i++)
        {
            temp[nopt]->var[i] = new BranchingWeight();
            temp[nopt]->var[i]->idx   = idx[i];
            temp[nopt]->var[i]->name  = name[i];
            temp[nopt]->var[i]->value = value[i];
        }

        this->sos  = temp;   //hook the new pointers into the data structure
        this->numberOfSOS = ++nopt;

        return true;
    }
    catch(const ErrorClass& eclass)
    {
        osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_error, eclass.errormsg);
        return false;
    }
}//addSOS

/**
 *
 * A function to set an array of <var> elements
 * @param numberOfVar: number of <var> elements to be set
 * @param var: the array of <var> elements that are to be set
 */
bool OtherVariableOptionOrResult::setVar(int numberOfVar, OtherOptionOrResultElementString **var)
{
    try
    {
        if (this->var != NULL)
            throw ErrorClass( "OtherVarOption array previously used.");

        if (numberOfVar < 0)
            throw ErrorClass( "length of <var> array cannot be negative.");

        this->numberOfVar = numberOfVar;
        if (numberOfVar == 0) return true;

        this->var = new OtherOptionOrResultElementString*[numberOfVar];

        int  i;
        for (i = 0; i < numberOfVar; i++)
        {
            this->var[i] = new OtherOptionOrResultElementString();
           *this->var[i] = *var[i];
        }
        return true;
    }
    catch(const ErrorClass& eclass)
    {
        osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_error, eclass.errormsg);
        return false;
    }
}//setVar

/**
 *
 * A function to add a <var> element
 * @param idx: the index of the variable
 * @param value: the value associated with this variable
 * @param lbValue: a lower bound associated with this variable
 * @param ubValue: an upper bound associated with this variable
 */
bool OtherVariableOptionOrResult::addVar(int idx, std::string value,
                                         std::string lbValue, std::string ubValue)
{
    try
    {
        int nopt;
        int i;
        if (idx < 0)
            throw ErrorClass( "the index of a variable cannot be negative." );

        if (this->var == NULL)
            nopt = 0;
        else
            nopt = this->numberOfVar;

        OtherOptionOrResultElementString** temp = new OtherOptionOrResultElementString*[nopt+1];  //Allocate the new pointers
        for (i = 0; i < nopt; i++)
            temp[i] = this->var[i];  //copy the pointers

        delete[] this->var; //delete old pointers

//    add in the new element
        temp[ nopt] = new OtherOptionOrResultElementString();

        temp[ nopt]->idx = idx;
        temp[ nopt]->value = value;
        temp[ nopt]->lbValue = lbValue;
        temp[ nopt]->ubValue = ubValue;

        this->var = temp;   //hook the new pointers into the data structure
        this->numberOfVar = ++nopt;

        return true;
    }
    catch(const ErrorClass& eclass)
    {
        osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_error, eclass.errormsg);
        return false;
    }
}//addVar

/**
 *
 * A function to set an array of <other> elements
 * @param numberOfOptions: number of <other> elements to be set
 * @param other: the array of <other> elements that are to be set
 */
bool VariableOption::setOther(int numberOfOptions, OtherVariableOptionOrResult  **other)
{
    try
    {
        if (this->other != NULL)
            throw ErrorClass( "otherVariableOptions array previously used.");

        if (numberOfOptions < 0)
            throw ErrorClass( "length of <other> array cannot be negative.");

        this->numberOfOtherVariableOptions = numberOfOptions;
        if (numberOfOptions == 0) return true;

        this->other = new OtherVariableOptionOrResult*[numberOfOptions];

        int  i, j;
        for (i = 0; i < numberOfOptions; i++)
        {
            this->other[i] = new OtherVariableOptionOrResult();
            this->other[i]->name        = other[i]->name;
            this->other[i]->description = other[i]->description;
            this->other[i]->value       = other[i]->value;
            this->other[i]->type        = other[i]->type;
            this->other[i]->solver      = other[i]->solver;
            this->other[i]->category    = other[i]->category;
            this->other[i]->enumType    = other[i]->enumType;
            this->other[i]->varType     = other[i]->varType;

            if (other[i]->numberOfVar < 0)
                throw ErrorClass( "the number of variables in otherVariableOption cannot be negative.");

            this->other[i]->numberOfVar = other[i]->numberOfVar;

            if (other[i]->numberOfVar > 0)
            {
                this->other[i]->var = new OtherOptionOrResultElementString*[other[i]->numberOfVar];
                for (j = 0; j < other[i]->numberOfVar; j++)
                {
                    this->other[i]->var[j] = new OtherOptionOrResultElementString();
                    *this->other[i]->var[j] = *other[i]->var[j];
                }
            }
            this->other[i]->numberOfEnumerations = other[i]->numberOfEnumerations;

            if (this->other[i]->numberOfEnumerations > 0)
            {
                this->other[i]->enumeration = new OtherOptionOrResultEnumeration*[this->other[i]->numberOfEnumerations];
                for (j = 0; j < this->other[i]->numberOfEnumerations; j++)
                {
                    this->other[i]->enumeration[j]  = new OtherOptionOrResultEnumeration();
                    this->other[i]->enumeration[j]->setOtherOptionOrResultEnumeration(
                        other[i]->enumeration[j]->value,
                        other[i]->enumeration[j]->description,
                        other[i]->enumeration[j]->el,
                        other[i]->enumeration[j]->numberOfEl);
                }
            }
        }
        return true;
    }
    catch(const ErrorClass& eclass)
    {
        osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_error, eclass.errormsg);
        return false;
    }
}//setOther

/**
 *
 * A function to add an <other> element
 * @param other: the content of the <other> element to be added
 */
bool VariableOption::addOther(OtherVariableOptionOrResult *other)
{
    try
    {
        int nopt, i, j;
        if (this->other == NULL)
            nopt = 0;
        else
            nopt = this->numberOfOtherVariableOptions;

        OtherVariableOptionOrResult** temp
            = new OtherVariableOptionOrResult*[nopt+1];  //Allocate the new pointers
        for (i = 0; i < nopt; i++)
            temp[i] = this->other[i];  //copy the pointers

        delete[] this->other; //delete old pointers

//    add in the new element
        temp[ nopt] = new OtherVariableOptionOrResult();
        temp[ nopt]->name        = other->name;
        temp[ nopt]->value       = other->value;
        temp[ nopt]->solver      = other->solver;
        temp[ nopt]->category    = other->category;
        temp[ nopt]->type        = other->type;
        temp[ nopt]->varType     = other->varType;
        temp[ nopt]->enumType    = other->enumType;
        temp[ nopt]->description = other->description;

        if (other->numberOfVar < 0)
            throw ErrorClass( "the number of variables in otherVariableOption cannot be negative.");

        temp[ nopt]->numberOfVar = other->numberOfVar;

        if (other->numberOfVar > 0)
        {
            temp[ nopt]->var = new OtherOptionOrResultElementString*[other->numberOfVar];
            for (j = 0; j < other->numberOfVar; j++)
            {
                temp[nopt]->var[j] = new OtherOptionOrResultElementString();
               *temp[nopt]->var[j] = *other->var[j];
            }
        }

        temp[ nopt]->numberOfEnumerations = other->numberOfEnumerations;

        if (other->numberOfEnumerations > 0)
        {
            temp[ nopt]->enumeration = new OtherOptionOrResultEnumeration*[other->numberOfEnumerations];
            for (j = 0; j < other->numberOfEnumerations; j++)
            {
                temp[ nopt]->enumeration[j]  = new OtherOptionOrResultEnumeration();
                temp[ nopt]->enumeration[j]->setOtherOptionOrResultEnumeration(
                    other->enumeration[j]->value,
                    other->enumeration[j]->description,
                    other->enumeration[j]->el,
                    other->enumeration[j]->numberOfEl);
            }
        }


        this->other = temp;   //hook the new pointers into the data structure
        this->numberOfOtherVariableOptions = ++nopt;

        return true;
    }
    catch(const ErrorClass& eclass)
    {
        osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_error, eclass.errormsg);
        return false;
    }
}//addOther

/**
 *
 * A function to set an array of <obj> elements
 * @param numberOfObj: number of <obj> elements to be set
 * @param obj: the array of <obj> elements that are to be set
 */
bool InitObjectiveValues::setObj(int numberOfObj, InitObjValue **obj)
{
    try
    {
        if (this->obj != NULL)
            throw ErrorClass( "InitObjValue array previously used.");

        if (numberOfObj < 0)
            throw ErrorClass( "length of obj array cannot be negative.");

        this->numberOfObj = numberOfObj;
        if (numberOfObj == 0)
            return true;

        this->obj = new InitObjValue*[numberOfObj];

        int  i;
        for (i = 0; i < numberOfObj; i++)
        {
            this->obj[i] = new InitObjValue();
           *this->obj[i] = *obj[i];
        }
        return true;
    }
    catch(const ErrorClass& eclass)
    {
        osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_error, eclass.errormsg);
        return false;
    }
}//setObj

/**
 *
 * A function to set an array of <obj> elements
 * @param numberOfObj: number of <obj> elements to be set
 * @param obj: the array of <obj> elements that are to be set
 * @param disp: method of disposition if previous data exist
 */
bool InitObjectiveValues::setObj(int numberOfObj, InitObjValue **obj, ENUM_COMBINE_ARRAYS disp)
{
    try
    {
        if (this->obj != NULL)
        {
            if (disp == ENUM_COMBINE_ARRAYS_throw)
                throw ErrorClass( "InitObjValue array previously used.");
            if (disp == ENUM_COMBINE_ARRAYS_ignore)
                return true;
            if (disp == ENUM_COMBINE_ARRAYS_merge)
                return this->addObj(numberOfObj, obj);

            //here we replace the old data
            for (int i = 0; i < this->numberOfObj; i++)
                delete this->obj[i];
            delete [] this->obj;
            this->obj = NULL;
        }

        if (numberOfObj < 0)
            throw ErrorClass( "length of obj array cannot be negative.");

        this->numberOfObj = numberOfObj;
        if (numberOfObj == 0)
            return true;

        this->obj = new InitObjValue*[numberOfObj];

        int  i;
        for (i = 0; i < numberOfObj; i++)
        {
            this->obj[i] = new InitObjValue();
           *this->obj[i] = *obj[i];
        }
        return true;
    }
    catch(const ErrorClass& eclass)
    {
        osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_error, eclass.errormsg);
        return false;
    }
}//setObj

bool InitObjectiveValues::setObj(int numberOfObj, int *idx, double *value, std::string *name)
{
    if (this->obj != NULL) return false;

    if (numberOfObj < 0) return false;

    this->numberOfObj = numberOfObj;
    if (numberOfObj == 0) return true;

    this->obj = new InitObjValue*[numberOfObj];

    int  i;
    for (i = 0; i < numberOfObj; i++)
    {
        this->obj[i] = new InitObjValue();
        this->obj[i]->idx = idx[i];
        this->obj[i]->name = name[i];
        this->obj[i]->value = value[i];
    }
    return true;
}//setObj


/**
 *
 * A function to add a <obj> element
 * @param idx: the index of the objective to be given an initial value
 * @param value: the inital value to be added
 */
bool InitObjectiveValues::addObj(int idx, double value)
{
    try
    {
        int nopt;
        int i;
        if (idx >= 0)
            throw ErrorClass( "the index of an objective must be negative." );

        if (this->obj == NULL)
            nopt = 0;
        else
            nopt = this->numberOfObj;

        InitObjValue** temp = new InitObjValue*[nopt+1];  //Allocate the new pointers
        for (i = 0; i < nopt; i++)
            temp[i] = this->obj[i];  //copy the pointers

        delete[] this->obj; //delete old pointers

//    add in the new element
        temp[ nopt] = new InitObjValue();

        temp[ nopt]->idx = idx;
        temp[ nopt]->value = value;

        this->obj = temp;   //hook the new pointers into the data structure
        this->numberOfObj = ++nopt;

        return true;
    }
    catch(const ErrorClass& eclass)
    {
        osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_error, eclass.errormsg);
        return false;
    }
}//addObj

/**
 * A function to add several <obj> elements
 * @param numberOfVar: number of <obj> elements to be added
 * @param obj: the array of <obj> elements that are to be added
 */
bool InitObjectiveValues::addObj(int numberOfObj, InitObjValue **obj)
{
    try
    {
        if (numberOfObj < 0)
            throw ErrorClass( "length of obj array cannot be negative.");

        if (numberOfObj == 0)
            return true;

        int nprev = this->numberOfObj;

        InitObjValue** temp = new InitObjValue*[nprev+numberOfObj];  //Allocate the new pointers
        for (int i = 0; i < nprev; i++)
            temp[i] = this->obj[i];  //copy the pointers

        delete[] this->obj; //delete old pointers

//    add in the new elements
        for (int i=0; i < numberOfObj; i++)
        {
            temp[nprev+i] = new InitObjValue();
           *temp[nprev+i] = *obj[i];
        }

        this->obj = temp;   //hook the new pointers into the data structure
           this->numberOfObj = nprev + numberOfObj;

        return true;
    }
    catch(const ErrorClass& eclass)
    {
        osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_error, eclass.errormsg);
        return false;
    }
}//addObj

/**
 *
 * A function to set an array of <obj> elements
 * @param numberOfObj: number of <obj> elements to be set
 * @param obj: the array of <obj> elements that are to be set
 */
bool InitObjectiveBounds::setObj(int numberOfObj, InitObjBound **obj)
{
    try
    {
        if (this->obj != NULL)
            throw ErrorClass( "InitObjBound array previously used.");

        if (numberOfObj < 0)
            throw ErrorClass( "length of obj array cannot be negative.");

        this->numberOfObj = numberOfObj;
        if (numberOfObj == 0)
            return true;

        this->obj = new InitObjBound*[numberOfObj];

        int  i;
        for (i = 0; i < numberOfObj; i++)
        {
            this->obj[i] = new InitObjBound();
           *this->obj[i] = *obj[i];
        }
        return true;
    }
    catch(const ErrorClass& eclass)
    {
        osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_error, eclass.errormsg);
        return false;
    }
}//setObj

/**
 *
 * A function to set an array of <obj> elements
 * @param numberOfObj: number of <obj> elements to be set
 * @param obj: the array of <obj> elements that are to be set
 * @param disp: method of disposition if previous data exist
*/
bool InitObjectiveBounds::setObj(int numberOfObj, InitObjBound **obj, ENUM_COMBINE_ARRAYS disp)
{
    try
    {
        if (this->obj != NULL)
        {
            if (disp == ENUM_COMBINE_ARRAYS_throw)
                throw ErrorClass( "InitObjBound array previously used.");
            if (disp == ENUM_COMBINE_ARRAYS_ignore)
                return true;
            if (disp == ENUM_COMBINE_ARRAYS_merge)
                return this->addObj(numberOfObj, obj);

            //here we replace the old data
            for (int i = 0; i < this->numberOfObj; i++)
                delete this->obj[i];
            delete [] this->obj;
            this->obj = NULL;
        }

        if (numberOfObj < 0)
            throw ErrorClass( "length of obj array cannot be negative.");

        this->numberOfObj = numberOfObj;
        if (numberOfObj == 0)
            return true;

        this->obj = new InitObjBound*[numberOfObj];


        int  i;
        for (i = 0; i < numberOfObj; i++)
        {
            this->obj[i] = new InitObjBound();
           *this->obj[i] = *obj[i];
        }
        return true;
    }
    catch(const ErrorClass& eclass)
    {
        osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_error, eclass.errormsg);
        return false;
    }
}//setObj

bool InitObjectiveBounds::setObj(int numberOfObj, int *idx, double *lbValue, double *ubValue, std::string *name)
{
    if (this->obj != NULL)
        return false;

    if (numberOfObj < 0)
        return false;

    this->numberOfObj = numberOfObj;
    if (numberOfObj == 0)
        return true;

    this->obj = new InitObjBound*[numberOfObj];

    int  i;
    for (i = 0; i < numberOfObj; i++)
    {
        this->obj[i] = new InitObjBound();
        this->obj[i]->idx = idx[i];
        this->obj[i]->name = name[i];
        this->obj[i]->lbValue = lbValue[i];
        this->obj[i]->ubValue = ubValue[i];
    }
    return true;
}//setObj


/**
 *
 * A function to add a <obj> element
 * @param idx: the index of the objective to be given initial bounds
 * @param lbValue: the initial lower bound for the objective
 * @param ubValue: the initial upper bound for the objective
 */
bool InitObjectiveBounds::addObj(int idx, double lbValue, double ubValue)
{
    try
    {
        int nopt;
        int i;
        if (idx >= 0)
            throw ErrorClass( "the index of an objective must be negative." );

        if (this->obj == NULL)
            nopt = 0;
        else
            nopt = this->numberOfObj;

        InitObjBound** temp = new InitObjBound*[nopt+1];  //Allocate the new pointers
        for (i = 0; i < nopt; i++)
            temp[i] = this->obj[i];  //copy the pointers

        delete[] this->obj; //delete old pointers

//    add in the new element
        temp[ nopt] = new InitObjBound();

        temp[ nopt]->idx = idx;
        temp[ nopt]->lbValue = lbValue;
        temp[ nopt]->ubValue = ubValue;

        this->obj = temp;   //hook the new pointers into the data structure
        this->numberOfObj = ++nopt;

        return true;
    }
    catch(const ErrorClass& eclass)
    {
        osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_error, eclass.errormsg);
        return false;
    }
}//addObj

/**
 * A function to add several <obj> elements
 * @param numberOfVar: number of <obj> elements to be added
 * @param obj: the array of <obj> elements that are to be added
 */
bool InitObjectiveBounds::addObj(int numberOfObj, InitObjBound **obj)
{
    try
    {
        if (numberOfObj < 0)
            throw ErrorClass( "length of obj array cannot be negative.");

        if (numberOfObj == 0)
            return true;

        int nprev = this->numberOfObj;

        InitObjBound** temp = new InitObjBound*[nprev+numberOfObj];  //Allocate the new pointers
        for (int i = 0; i < nprev; i++)
            temp[i] = this->obj[i];  //copy the pointers

        delete[] this->obj; //delete old pointers

//    add in the new elements
        for (int i=0; i < numberOfObj; i++)
        {
            temp[nprev+i] = new InitObjBound();
           *temp[nprev+i] = *obj[i];
        }

        this->obj = temp;   //hook the new pointers into the data structure
           this->numberOfObj = nprev + numberOfObj;

        return true;
    }
    catch(const ErrorClass& eclass)
    {
        osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_error, eclass.errormsg);
        return false;
    }
}//addObj

#if 0
/**
 *
 * A function to set an array of <obj> elements
 * @param numberOfObj: number of <obj> elements to be set
 * @param obj: the array of <obj> elements that are to be set
 */
bool OtherObjectiveOption::setObj(int numberOfObj, OtherObjOption **obj)
{
    try
    {
        if (this->obj != NULL)
            throw ErrorClass( "OtherObjOption array previously used.");

        if (numberOfObj < 0)
            throw ErrorClass( "length of <obj> array cannot be negative.");

        this->numberOfObj= numberOfObj;
        if (numberOfObj == 0)
            return true;

        this->obj = new OtherObjOption*[numberOfObj];

        int  i;
        for (i = 0; i < numberOfObj; i++)
        {
            this->obj[i] = new OtherObjOption();
           *this->obj[i] = *obj[i];
        }
        return true;
    }
    catch(const ErrorClass& eclass)
    {
        osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_error, eclass.errormsg);
        return false;
    }
}//setObj

/**
 *
 * A function to add a <obj> element
 * @param idx: the index of the objective
 * @param value: the value associated with this objective
 * @param lbValue: a lower bound associated with this objective
 * @param ubValue: an upper bound associated with this objective
 */
bool OtherObjectiveOption::addObj(int idx, std::string value, std::string lbValue, std::string ubValue)
{
    try
    {
        int nopt;
        int i;
        if (idx >= 0)
            throw ErrorClass( "the index of an objective must be negative." );

        if (this->obj == NULL)
            nopt = 0;
        else
            nopt = this->numberOfObj;

        OtherObjOption** temp = new OtherObjOption*[nopt+1];  //Allocate the new pointers
        for (i = 0; i < nopt; i++)
            temp[i] = this->obj[i];  //copy the pointers

        delete[] this->obj; //delete old pointers

//    add in the new element
        temp[ nopt] = new OtherObjOption();

        temp[ nopt]->idx = idx;
        temp[ nopt]->value = value;
        temp[ nopt]->lbValue = lbValue;
        temp[ nopt]->ubValue = ubValue;

        this->obj = temp;   //hook the new pointers into the data structure
        this->numberOfObj = ++nopt;

        return true;
    }
    catch(const ErrorClass& eclass)
    {
        osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_error, eclass.errormsg);
        return false;
    }
}//addObj
#endif

/**
 *
 * A function to set an array of <other> elements
 * @param numberOfOptions: number of <other> elements to be set
 * @param other: the array of <other> elements that are to be set
 */
bool ObjectiveOption::setOther(int numberOfOptions, OtherObjectiveOptionOrResult **other)
{
    try
    {
        if (this->other != NULL)
            throw ErrorClass( "otherObjectiveOptions array previously used.");

        if (numberOfOptions < 0)
            throw ErrorClass( "length of <other> array cannot be negative.");

        this->numberOfOtherObjectiveOptions = numberOfOptions;
        if (numberOfOptions == 0) return true;

        this->other = new OtherObjectiveOptionOrResult*[numberOfOptions];

        int  i, j;
        for (i = 0; i < numberOfOptions; i++)
        {
            this->other[i] = new OtherObjectiveOptionOrResult();
            this->other[i]->name        = other[i]->name;
            this->other[i]->value       = other[i]->value;
            this->other[i]->solver      = other[i]->solver;
            this->other[i]->category    = other[i]->category;
            this->other[i]->type        = other[i]->type;
            this->other[i]->description = other[i]->description;
            this->other[i]->enumType    = other[i]->enumType;
            this->other[i]->objType     = other[i]->objType;

            if (other[i]->numberOfObj < 0)
                throw ErrorClass( "the number of objectives in otherObjectiveOption cannot be negative.");

            this->other[i]->numberOfObj = other[i]->numberOfObj;

            if (other[i]->numberOfObj > 0)
            {
                this->other[i]->obj = new OtherObjOptionOrResultElementString*[other[i]->numberOfObj];
                for (j = 0; j < other[i]->numberOfObj; j++)
                {
                    this->other[i]->obj[j] = new OtherObjOptionOrResultElementString();
                    *this->other[i]->obj[j] = *other[i]->obj[j];
                }
            }
            this->other[i]->numberOfEnumerations = other[i]->numberOfEnumerations;

            if (this->other[i]->numberOfEnumerations > 0)
            {

                this->other[i]->enumeration
                    = new OtherOptionOrResultEnumeration*[this->other[i]->numberOfEnumerations];
                for (j = 0; j < this->other[i]->numberOfEnumerations; j++)
                {
                    this->other[i]->enumeration[j]  = new OtherOptionOrResultEnumeration();
                    this->other[i]->enumeration[j]->setOtherOptionOrResultEnumeration(
                        other[i]->enumeration[j]->value,
                        other[i]->enumeration[j]->description,
                        other[i]->enumeration[j]->el,
                        other[i]->enumeration[j]->numberOfEl);
                }
            }
        }
        return true;
    }
    catch(const ErrorClass& eclass)
    {
        osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_error, eclass.errormsg);
        return false;
    }
}//setOther

/**
 *
 * A function to add an <other> element
 * @param other: the content of the <other> element to be added
 */
bool ObjectiveOption::addOther(OtherObjectiveOptionOrResult *other)
{
    try
    {
        int nopt, i, j;
        if (this->other == NULL)
            nopt = 0;
        else
            nopt = this->numberOfOtherObjectiveOptions;

        OtherObjectiveOptionOrResult** temp = new OtherObjectiveOptionOrResult*[nopt+1];  //Allocate the new pointers
        for (i = 0; i < nopt; i++)
            temp[i] = this->other[i];  //copy the pointers

        delete[] this->other; //delete old pointers

//    add in the new element
        temp[ nopt] = new OtherObjectiveOptionOrResult();
        temp[ nopt]->name        = other->name;
        temp[ nopt]->value       = other->value;
        temp[ nopt]->solver      = other->solver;
        temp[ nopt]->category    = other->category;
        temp[ nopt]->type        = other->type;
        temp[ nopt]->objType     = other->objType;
        temp[ nopt]->enumType    = other->enumType;
        temp[ nopt]->description = other->description;

        if (other->numberOfObj < 0)
            throw ErrorClass( "the number of objectives in otherObjectiveOption cannot be negative.");

        temp[ nopt]->numberOfObj = other->numberOfObj;

        if (other->numberOfObj > 0)
        {
            temp[ nopt]->obj = new OtherObjOptionOrResultElementString*[other->numberOfObj];
            for (j = 0; j < other->numberOfObj; j++)
            {
                temp[nopt]->obj[j] = new OtherObjOptionOrResultElementString();
               *temp[nopt]->obj[j] = *other->obj[j];
            }
        }

        if (other->numberOfEnumerations < 0)
            throw ErrorClass( "the number of enumerations in otherObjectiveOption cannot be negative.");

        temp[ nopt]->numberOfEnumerations = other->numberOfEnumerations;

        if (other->numberOfEnumerations > 0)
        {
            temp[ nopt]->enumeration = new OtherOptionOrResultEnumeration*[other->numberOfEnumerations];
            for (j = 0; j < other->numberOfEnumerations; j++)
            {
                temp[ nopt]->enumeration[j]  = new OtherOptionOrResultEnumeration();
                temp[ nopt]->enumeration[j]->setOtherOptionOrResultEnumeration(
                    other->enumeration[j]->value,
                    other->enumeration[j]->description,
                    other->enumeration[j]->el,
                    other->enumeration[j]->numberOfEl);
            }
        }


        this->other = temp;   //hook the new pointers into the data structure
        this->numberOfOtherObjectiveOptions = ++nopt;

        return true;
    }
    catch(const ErrorClass& eclass)
    {
        osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_error, eclass.errormsg);
        return false;
    }
}//addOther



/**
 *
 * A function to set an array of <con> elements
 * @param numberOfCon: number of <con> elements to be set
 * @param con: the array of <con> elements that are to be set
 */
bool InitConstraintValues::setCon(int numberOfCon, InitConValue **con)
{
    try
    {
        if (this->con != NULL)
            throw ErrorClass( "InitConValue array previously used.");

        if (numberOfCon < 0)
            throw ErrorClass( "length of con array cannot be negative.");

        this->numberOfCon = numberOfCon;
        if (numberOfCon == 0)
            return true;

        this->con = new InitConValue*[numberOfCon];

        int  i;
        for (i = 0; i < numberOfCon; i++)
        {
            this->con[i] = new InitConValue();
           *this->con[i] = *con[i];
        }
        return true;
    }
    catch(const ErrorClass& eclass)
    {
        osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_error, eclass.errormsg);
        return false;
    }
}//setCon

/**
 *
 * A function to set an array of <con> elements
 * @param numberOfCon: number of <con> elements to be set
 * @param con: the array of <con> elements that are to be set
 * @param disp: method of disposition if previous data exist
 */
bool InitConstraintValues::setCon(int numberOfCon, InitConValue **con, ENUM_COMBINE_ARRAYS disp)
{
    try
    {
        if (this->con != NULL)
        {
            if (disp == ENUM_COMBINE_ARRAYS_throw)
                throw ErrorClass( "InitConValue array previously used.");
            if (disp == ENUM_COMBINE_ARRAYS_ignore)
                return true;
            if (disp == ENUM_COMBINE_ARRAYS_merge)
                return this->addCon(numberOfCon, con);

            //here we replace the old data
            for (int i = 0; i < this->numberOfCon; i++)
                delete this->con[i];
            delete [] this->con;
            this->con = NULL;
        }

        if (numberOfCon < 0)
            throw ErrorClass( "length of con array cannot be negative.");

        this->numberOfCon = numberOfCon;
        if (numberOfCon == 0)
            return true;

        this->con = new InitConValue*[numberOfCon];

        int  i;
        for (i = 0; i < numberOfCon; i++)
        {
            this->con[i] = new InitConValue();
           *this->con[i] = *con[i];
        }

        return true;
    }
    catch(const ErrorClass& eclass)
    {
        osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_error, eclass.errormsg);
        return false;
    }
}//setCon

bool InitConstraintValues::setCon(int numberOfCon, int *idx, double *value, std::string *name)
{
    if (this->con != NULL)
        return false;

    if (numberOfCon < 0)
        return false;

    this->numberOfCon = numberOfCon;
    if (numberOfCon == 0)
        return true;

    this->con = new InitConValue*[numberOfCon];

    int  i;
    for (i = 0; i < numberOfCon; i++)
    {
        this->con[i] = new InitConValue();
        this->con[i]->idx = idx[i];
        this->con[i]->name = name[i];
        this->con[i]->value = value[i];
    }
    return true;
}//setCon



/**
 *
 * A function to add a <con> element
 * @param idx: the index of the constraint to be given an inital value
 * @param value: the initial value to be added
 */
bool InitConstraintValues::addCon(int idx, double value)
{
    try
    {
        int nopt;
        int i;
        if (idx < 0)
            throw ErrorClass( "the index of a constraint cannot be negative." );

        if (this->con == NULL)
            nopt = 0;
        else
            nopt = this->numberOfCon;

        InitConValue** temp = new InitConValue*[nopt+1];  //Allocate the new pointers
        for (i = 0; i < nopt; i++)
            temp[i] = this->con[i];  //copy the pointers

        delete[] this->con; //delete old pointers

//    add in the new element
        temp[ nopt] = new InitConValue();

        temp[ nopt]->idx = idx;
        temp[ nopt]->value = value;

        this->con = temp;   //hook the new pointers into the data structure
        this->numberOfCon = ++nopt;

        return true;
    }
    catch(const ErrorClass& eclass)
    {
        osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_error, eclass.errormsg);
        return false;
    }
}//addCon

/**
 * A function to add several <con> elements
 * @param numberOfVar: number of <con> elements to be added
 * @param con: the array of <con> elements that are to be added
 */
bool InitConstraintValues::addCon(int numberOfCon, InitConValue **con)
{
    try
    {
        if (numberOfCon < 0)
            throw ErrorClass( "length of con array cannot be negative.");

        if (numberOfCon == 0)
            return true;

        int nprev = this->numberOfCon;

        InitConValue** temp = new InitConValue*[nprev+numberOfCon];  //Allocate the new pointers
        for (int i = 0; i < nprev; i++)
            temp[i] = this->con[i];  //copy the pointers

        delete[] this->con; //delete old pointers

//    add in the new elements
        for (int i=0; i < numberOfCon; i++)
        {
            temp[nprev+i] = new InitConValue();
           *temp[nprev+i] = *con[i];
        }

        this->con = temp;   //hook the new pointers into the data structure
           this->numberOfCon = nprev + numberOfCon;

        return true;
    }
    catch(const ErrorClass& eclass)
    {
        osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_error, eclass.errormsg);
        return false;
    }
}//addCon


/**
 *
 * A function to set an array of <con> elements
 * @param numberOfCon: number of <con> elements to be set
 * @param con: the array of <con> elements that are to be set
 */
bool InitDualVariableValues::setCon(int numberOfCon, InitDualVarValue **con)
{
    try
    {
        if (this->con != NULL)
            throw ErrorClass( "InitDualVarValue array previously used.");

        if (numberOfCon < 0)
            throw ErrorClass( "length of con array cannot be negative.");

        this->numberOfCon = numberOfCon;
        if (numberOfCon == 0)
            return true;

        this->con = new InitDualVarValue*[numberOfCon];

        int  i;
        for (i = 0; i < numberOfCon; i++)
        {
            this->con[i] = new InitDualVarValue();
           *this->con[i] = *con[i];
        }
        return true;
    }
    catch(const ErrorClass& eclass)
    {
        osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_error, eclass.errormsg);
        return false;
    }
}//setCon
/**
 *
 * A function to set an array of <con> elements
 * @param numberOfCon: number of <con> elements to be set
 * @param con: the array of <con> elements that are to be set
 * @param disp: method of disposition if previous data exist
 */
bool InitDualVariableValues::setCon(int numberOfCon, InitDualVarValue **con, ENUM_COMBINE_ARRAYS disp)
{
    try
    {
        if (this->con != NULL)
        {
            if (disp == ENUM_COMBINE_ARRAYS_throw)
                throw ErrorClass( "InitDualVarValue array previously used.");
            if (disp == ENUM_COMBINE_ARRAYS_ignore)
                return true;
            if (disp == ENUM_COMBINE_ARRAYS_merge)
                return this->addCon(numberOfCon, con);

            //here we replace the old data
            for (int i = 0; i < this->numberOfCon; i++)
                delete this->con[i];
            delete [] this->con;
            this->con = NULL;
        }

        if (numberOfCon < 0)
            throw ErrorClass( "length of con array cannot be negative.");

        this->numberOfCon = numberOfCon;
        if (numberOfCon == 0)
            return true;

        this->con = new InitDualVarValue*[numberOfCon];

        int  i;
        for (i = 0; i < numberOfCon; i++)
        {
            this->con[i] = new InitDualVarValue();
           *this->con[i] = *con[i];
        }
        return true;
    }
    catch(const ErrorClass& eclass)
    {
        osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_error, eclass.errormsg);
        return false;
    }
}//setCon

bool InitDualVariableValues::setCon(int numberOfCon, int *idx, double *lbValue, double *ubValue, std::string *name)
{
    if (this->con != NULL)
        return false;

    if (numberOfCon < 0)
        return false;

    this->numberOfCon = numberOfCon;
    if (numberOfCon == 0)
        return true;

    this->con = new InitDualVarValue*[numberOfCon];

    int  i;
    for (i = 0; i < numberOfCon; i++)
    {
        this->con[i] = new InitDualVarValue();
        this->con[i]->idx = idx[i];
        this->con[i]->name = name[i];
        this->con[i]->lbDualValue = lbValue[i];
        this->con[i]->ubDualValue = ubValue[i];
    }
    return true;
}//setCon


/**
 *
 * A function to add a <con> element
 * @param idx: the index of the constraint to be given initial dual variable bounds
 * @param lbValue: an initial lower bound for the dual variable
 * @param ubValue: an initial upper bound for the dual variable
 */
bool InitDualVariableValues::addCon(int idx, double lbDualValue, double ubDualValue)
{
    try
    {
        int nopt;
        int i;
        if (idx < 0)
            throw ErrorClass( "the index of a constraint cannot be negative." );

        if (this->con == NULL)
            nopt = 0;
        else
            nopt = this->numberOfCon;

        InitDualVarValue** temp = new InitDualVarValue*[nopt+1];  //Allocate the new pointers
        for (i = 0; i < nopt; i++)
            temp[i] = this->con[i];  //copy the pointers

        delete[] this->con; //delete old pointers

//    add in the new element
        temp[ nopt] = new InitDualVarValue();

        temp[ nopt]->idx = idx;
        temp[ nopt]->lbDualValue = lbDualValue;
        temp[ nopt]->ubDualValue = ubDualValue;

        this->con = temp;   //hook the new pointers into the data structure
        this->numberOfCon = ++nopt;

        return true;
    }
    catch(const ErrorClass& eclass)
    {
        osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_error, eclass.errormsg);
        return false;
    }
}//addCon

/**
 * A function to add several <con> elements
 * @param numberOfVar: number of <con> elements to be added
 * @param con: the array of <con> elements that are to be added
 */
bool InitDualVariableValues::addCon(int numberOfCon, InitDualVarValue **con)
{
    try
    {
        if (numberOfCon < 0)
            throw ErrorClass( "length of con array cannot be negative.");

        if (numberOfCon == 0)
            return true;

        int nprev = this->numberOfCon;

        InitDualVarValue** temp = new InitDualVarValue*[nprev+numberOfCon];  //Allocate the new pointers
        for (int i = 0; i < nprev; i++)
            temp[i] = this->con[i];  //copy the pointers

        delete[] this->con; //delete old pointers

//    add in the new elements
        for (int i=0; i < numberOfCon; i++)
        {
            temp[nprev+i] = new InitDualVarValue();
           *temp[nprev+i] = *con[i];
        }

        this->con = temp;   //hook the new pointers into the data structure
           this->numberOfCon = nprev + numberOfCon;

        return true;
    }
    catch(const ErrorClass& eclass)
    {
        osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_error, eclass.errormsg);
        return false;
    }
}//addCon

#if 0
/**
 *
 * A function to set an array of <con> elements
 * @param numberOfCon: number of <con> elements to be set
 * @param obj: the array of <con> elements that are to be set
 */
bool OtherConstraintOption::setCon(int numberOfCon, OtherConOption **con)
{
    try
    {
        if (this->con != NULL)
            throw ErrorClass( "OtherConOption array previously used.");

        if (numberOfCon < 0)
            throw ErrorClass( "length of <con> array cannot be negative.");

        this->numberOfCon = numberOfCon;
        if (numberOfCon == 0)
            return true;
        this->con = new OtherConOption*[numberOfCon];

        int  i;
        for (i = 0; i < numberOfCon; i++)
        {
            this->con[i] = new OtherConOption();
            *this->con[i] = *con[i];
        }
        return true;
    }
    catch(const ErrorClass& eclass)
    {
        osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_error, eclass.errormsg);
        return false;
    }
}//setCon

/**
 *
 * A function to add a <con> element
 * @param idx: the index of the constraint
 * @param value: the value associated with this constraint
 * @param lbValue: a lower bound associated with this constraint
 * @param ubValue: an upper bound associated with this constraint
 */
bool OtherConstraintOption::addCon(int idx, std::string value, std::string lbValue, std::string ubValue)
{
    try
    {
        int nopt;
        int i;
        if (idx < 0)
            throw ErrorClass( "the index of a variable cannot be negative." );

        if (this->con == NULL)
            nopt = 0;
        else
            nopt = this->numberOfCon;

        OtherConOption** temp = new OtherConOption*[nopt+1];  //Allocate the new pointers
        for (i = 0; i < nopt; i++)
            temp[i] = this->con[i];  //copy the pointers

        delete[] this->con; //delete old pointers

//    add in the new element
        temp[ nopt] = new OtherConOption();

        temp[ nopt]->idx = idx;
        temp[ nopt]->value = value;
        temp[ nopt]->lbValue = lbValue;
        temp[ nopt]->ubValue = ubValue;

        this->con = temp;   //hook the new pointers into the data structure
        this->numberOfCon = ++nopt;

        return true;
    }
    catch(const ErrorClass& eclass)
    {
        osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_error, eclass.errormsg);
        return false;
    }
}//addCon
#endif

/**
 *
 * A function to set an array of <other> elements
 * @param numberOfOptions: number of <other> elements to be set
 * @param other: the array of <other> elements that are to be set
 */
bool ConstraintOption::setOther(int numberOfOptions, OtherConstraintOptionOrResult  **other)
{
    try
    {
        if (this->other != NULL)
            throw ErrorClass( "otherConstraintOptions array previously used.");

        if (numberOfOptions < 0)
            throw ErrorClass( "length of <other> array cannot be negative.");

        this->numberOfOtherConstraintOptions = numberOfOptions;
        if (numberOfOptions == 0)
            return true;

        this->other = new OtherConstraintOptionOrResult*[numberOfOptions];

        int  i, j;
        for (i = 0; i < numberOfOptions; i++)
        {
            this->other[i] = new OtherConstraintOptionOrResult();
            this->other[i]->name        = other[i]->name;
            this->other[i]->value       = other[i]->value;
            this->other[i]->solver      = other[i]->solver;
            this->other[i]->category    = other[i]->category;
            this->other[i]->type        = other[i]->type;
            this->other[i]->description = other[i]->description;
            this->other[i]->enumType    = other[i]->enumType;
            this->other[i]->conType     = other[i]->conType;

            if (other[i]->numberOfCon < 0)
                throw ErrorClass( "the number of constraints in otherConstraintOption cannot be negative.");

            this->other[i]->numberOfCon = other[i]->numberOfCon;

            if (other[i]->numberOfCon > 0)
            {
                this->other[i]->con = new OtherOptionOrResultElementString*[other[i]->numberOfCon];
                for (j = 0; j < other[i]->numberOfCon; j++)
                {
                    this->other[i]->con[j] = new OtherOptionOrResultElementString();
                   *this->other[i]->con[j] = *other[i]->con[j];
                }
            }

            this->other[i]->numberOfEnumerations = other[i]->numberOfEnumerations;

            if (this->other[i]->numberOfEnumerations > 0)
            {
                this->other[i]->enumeration = new OtherOptionOrResultEnumeration*[this->other[i]->numberOfEnumerations];
                for (j = 0; j < this->other[i]->numberOfEnumerations; j++)
                {
                    this->other[i]->enumeration[j]  = new OtherOptionOrResultEnumeration();
                    this->other[i]->enumeration[j]->setOtherOptionOrResultEnumeration(
                        other[i]->enumeration[j]->value,
                        other[i]->enumeration[j]->description,
                        other[i]->enumeration[j]->el,
                        other[i]->enumeration[j]->numberOfEl);
                }
            }
        }
        return true;
    }
    catch(const ErrorClass& eclass)
    {
        osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_error, eclass.errormsg);
        return false;
    }
}//setOther

/**
 *
 * A function to add an <other> element
 * @param other: the content of the <other> element to be added
 */
bool ConstraintOption::addOther(OtherConstraintOptionOrResult *other)
{
    try
    {
        int nopt, i, j;
        if (this->other == NULL)
            nopt = 0;
        else
            nopt = this->numberOfOtherConstraintOptions;

        OtherConstraintOptionOrResult** temp
            = new OtherConstraintOptionOrResult*[nopt+1];  //Allocate the new pointers
        for (i = 0; i < nopt; i++)
            temp[i] = this->other[i];  //copy the pointers

        delete[] this->other; //delete old pointers

//    add in the new element
        temp[ nopt] = new OtherConstraintOptionOrResult();
        temp[ nopt]->name        = other->name;
        temp[ nopt]->value       = other->value;
        temp[ nopt]->solver      = other->solver;
        temp[ nopt]->category    = other->category;
        temp[ nopt]->type        = other->type;
        temp[ nopt]->conType     = other->conType;
        temp[ nopt]->enumType    = other->enumType;
        temp[ nopt]->description = other->description;

        if (other->numberOfCon < 0)
            throw ErrorClass( "the number of constraints in otherConstraintOption cannot be negative.");

        temp[ nopt]->numberOfCon = other->numberOfCon;

        if (other->numberOfCon > 0)
        {
            temp[ nopt]->con = new OtherOptionOrResultElementString*[other->numberOfCon];
            for (j = 0; j < other->numberOfCon; j++)
            {
                temp[nopt]->con[j] = new OtherOptionOrResultElementString();
               *temp[nopt]->con[j] = *other->con[j];
            }
        }

        temp[ nopt]->numberOfEnumerations = other->numberOfEnumerations;

        if (other->numberOfEnumerations < 0)
            throw ErrorClass( "the number of enumerations in otherConstraintOption cannot be negative.");

        if (other->numberOfEnumerations > 0)
        {
            temp[ nopt]->enumeration = new OtherOptionOrResultEnumeration*[other->numberOfEnumerations];
            for (j = 0; j < other->numberOfEnumerations; j++)
            {
                temp[ nopt]->enumeration[j]  = new OtherOptionOrResultEnumeration();
                temp[ nopt]->enumeration[j]->setOtherOptionOrResultEnumeration(
                    other->enumeration[j]->value,
                    other->enumeration[j]->description,
                    other->enumeration[j]->el,
                    other->enumeration[j]->numberOfEl);
            }
        }

        this->other = temp;   //hook the new pointers into the data structure
        this->numberOfOtherConstraintOptions = ++nopt;

        return true;
    }
    catch(const ErrorClass& eclass)
    {
        osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_error, eclass.errormsg);
        return false;
    }
}//addOther


/**
 *
 * A function to set an array of solver options
 * @param numberOfOptions: number of solver options to be set
 * @param solverOption: the array of solver options that are to be set
 */
bool SolverOptions::setSolverOptions(int numberOfOptions, SolverOptionOrResult **solverOption)
{
    try
    {
        if (this->solverOption != NULL)
            throw ErrorClass( "solverOptions array previously used.");

        if (numberOfOptions < 0)
            throw ErrorClass( "length of <solverOption> array cannot be negative.");

        this->numberOfSolverOptions = numberOfOptions;
        if (numberOfOptions == 0)
            return true;

        this->solverOption = new SolverOptionOrResult*[numberOfOptions];

        int  i;
        for (i = 0; i < numberOfOptions; i++)
        {
            this->solverOption[i] = new SolverOptionOrResult();

            this->solverOption[i]->numberOfItems = solverOption[i]->numberOfItems;
            this->solverOption[i]->name = solverOption[i]->name;
            this->solverOption[i]->value = solverOption[i]->value;
            this->solverOption[i]->solver = solverOption[i]->solver;
            this->solverOption[i]->category = solverOption[i]->category;
            this->solverOption[i]->type = solverOption[i]->type;
            this->solverOption[i]->description = solverOption[i]->description;

            if (solverOption[i]->numberOfItems > 0)
            {
                this->solverOption[i]->item = new std::string[solverOption[i]->numberOfItems];
                for (int j=0; j<solverOption[i]->numberOfItems; j++)
                    this->solverOption[i]->item[j] = solverOption[i]->item[j];
            }
        }
        return true;
    }
    catch(const ErrorClass& eclass)
    {
        osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_error, eclass.errormsg);
        return false;
    }
}//setSolverOption


/**
 *
 * A function to add a solver option
 * @param name: the name of the solver option (required)
 * @param value: a value associated with the option (optional)
 * @param solver: the solver to which the option applies (optional)
 * @param category: the category (and subcategories) of the option (optional)
 * @param type: the type of the option (optional)
 * @param description: a description associated with the option (optional)
 */
bool SolverOptions::addSolverOption(std::string name, std::string value, std::string solver,
                                    std::string category, std::string type, std::string description)
{
    try
    {
        int nopt;
        int i;
        if (name.empty() )
            throw ErrorClass( "the name of a solver option cannot be empty." );

        if (this->solverOption == NULL)
            nopt = 0;
        else
            nopt = this->numberOfSolverOptions;

        SolverOptionOrResult** temp = new SolverOptionOrResult*[nopt+1];  //Allocate the new pointers
        for (i = 0; i < nopt; i++)
            temp[i] = this->solverOption[i];  //copy the pointers

        delete[] this->solverOption; //delete old pointers

//    add in the new element
        temp[ nopt] = new SolverOptionOrResult();

        temp[ nopt]->numberOfItems = 0;
        temp[ nopt]->name = name;
        temp[ nopt]->value = value;
        temp[ nopt]->solver = solver;
        temp[ nopt]->type = type;
        temp[ nopt]->category = category;
        temp[ nopt]->description = description;

        this->solverOption = temp;   //hook the new pointers into the data structure
        this->numberOfSolverOptions = ++nopt;

        return true;
    }
    catch(const ErrorClass& eclass)
    {
        osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_error, eclass.errormsg);
        return false;
    }
}//addSolverOption

/**
 *  set option header
 */

bool OSOption::setHeader(std::string name, std::string source,
                               std::string description, std::string fileCreator, std::string licence)
{
    if (this->optionHeader == NULL)
        this->optionHeader = new GeneralFileHeader();
    return this->optionHeader->setHeader(name, source, description, fileCreator, licence);
}// end of OSOption::setHeader

/**
 *  set() options in the <general> element
 */

bool OSOption::setServiceURI( std::string serviceURI)
{
    if (this->general == NULL)
        this->general = new GeneralOption();
    this->general->serviceURI = serviceURI;
    return true;
}//setServiceURI

bool OSOption::setServiceName( std::string serviceName)
{
    if (this->general == NULL)
        this->general = new GeneralOption();
    this->general->serviceName = serviceName;
    return true;
}//setServiceName

bool OSOption::setInstanceName( std::string instanceName)
{
    if (this->general == NULL)
        this->general = new GeneralOption();
    this->general->instanceName = instanceName;
    return true;
}//setInstanceName

bool OSOption::setInstanceLocation( std::string instanceLocation)
{
    if (this->general == NULL)
        this->general = new GeneralOption();
    if (this->general->instanceLocation == NULL)
        this->general->instanceLocation = new InstanceLocationOption();
    this->general->instanceLocation->value = instanceLocation;
    return true;
}//setInstanceLocation

bool OSOption::setInstanceLocation( std::string instanceLocation, std::string locationType)
{
    if (verifyLocationType(locationType) == 0)
        return false;

    if (this->general == NULL)
        this->general = new GeneralOption();
    if (this->general->instanceLocation == NULL)
        this->general->instanceLocation = new InstanceLocationOption();
    this->general->instanceLocation->value = instanceLocation;
    this->general->instanceLocation->locationType = locationType;
    return true;
}//setInstanceLocation

bool OSOption::setInstanceLocationType( std::string locationType)
{
    try
    {
        if (this->general == NULL)
            this->general = new GeneralOption();
        if (this->general->instanceLocation == NULL)
            this->general->instanceLocation = new InstanceLocationOption();

        if (verifyLocationType(locationType) == 0)
            return false;

        this->general->instanceLocation->locationType = locationType;
        return true;
    }
    catch(const ErrorClass& eclass)
    {
        osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_error, eclass.errormsg);
        return false;
    }
}//setLocationType

bool OSOption::setJobID( std::string jobID)
{
    if (this->general == NULL)
        this->general = new GeneralOption();
    this->general->jobID = jobID;
    return true;
}//setJobID

bool OSOption::setSolverToInvoke( std::string solverToInvoke)
{
    if (this->general == NULL)
        this->general = new GeneralOption();
    this->general->solverToInvoke = solverToInvoke;
    return true;
}//setSolverToInvoke

bool OSOption::setLicense( std::string license)
{
    if (this->general == NULL)
        this->general = new GeneralOption();
    this->general->license = license;
    return true;
}//setLicense

bool OSOption::setUserName( std::string userName)
{
    if (this->general == NULL)
        this->general = new GeneralOption();
    this->general->userName = userName;
    return true;
}//setUserName

bool OSOption::setPassword( std::string password)
{
    if (this->general == NULL)
        this->general = new GeneralOption();
    this->general->password = password;
    return true;
}//setPassword

bool OSOption::setContact( std::string contact)
{
    if (this->general == NULL)
        this->general = new GeneralOption();
    if (this->general->contact == NULL)
        this->general->contact = new ContactOption();
    this->general->contact->value = contact;
    return true;
}//setContact

bool OSOption::setContact(std::string contact,std::string transportType)
{
    if (verifyTransportType(transportType) == 0)
        return false;

    if (this->general == NULL)
        this->general = new GeneralOption();
    if (this->general->contact == NULL)
        this->general->contact = new ContactOption();
    this->general->contact->value = contact;
    this->general->contact->transportType = transportType;
    return true;
}//setContact

bool OSOption::setContactTransportType( std::string transportType)
{
    try
    {
        if (this->general == NULL)
            this->general = new GeneralOption();
        if (this->general->contact == NULL)
            this->general->contact = new ContactOption();

        if (verifyTransportType(transportType) == 0)
            throw ErrorClass( "transport type not recognized.");

        this->general->contact->transportType = transportType;
        return true;
    }
    catch(const ErrorClass& eclass)
    {
        osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_error, eclass.errormsg);
        return false;
    }
}//setContactTransportType

bool OSOption::setOtherGeneralOptions(int numberOfOptions, OtherOptionOrResult** other)
{
    if (this->general == NULL)
        this->general = new GeneralOption();
    if (this->general->otherOptions == NULL)
        this->general->otherOptions = new OtherOptions();
    else
    {
        int i;
        for (i = 0; i < this->general->otherOptions->numberOfOtherOptions; i++)
            delete this->general->otherOptions->other[i];
        delete[] this->general->otherOptions->other;
        this->general->otherOptions->other = NULL;
    }
    return this->general->otherOptions->setOther(numberOfOptions, other);
}//setOtherGeneralOptions

bool OSOption::setAnOtherGeneralOption(std::string name, std::string value, std::string description)
{
    if (this->general == NULL)
        this->general = new GeneralOption();
    if (this->general->otherOptions == NULL)
        this->general->otherOptions = new OtherOptions();
    return this->general->otherOptions->addOther(name, value, description);
}//setAnOtherGeneralOption


/**
 *  set() options in the <system> element
 */

bool OSOption::setMinDiskSpace(std::string unit, std::string description, double value)
{
    if (verifyStorageUnit(unit) == 0)
        return false;

    if (this->system == NULL)
        this->system = new SystemOption();
    if (this->system->minDiskSpace == NULL)
        this->system->minDiskSpace = new StorageCapacity();
    this->system->minDiskSpace->unit = unit;
    this->system->minDiskSpace->value = value;
    this->system->minDiskSpace->description = description;
    return true;
}//setMinDiskSpace

bool OSOption::setMinDiskSpace(double value)
{
    if (this->system == NULL)
        this->system = new SystemOption();
    if (this->system->minDiskSpace == NULL)
        this->system->minDiskSpace = new StorageCapacity();
    this->system->minDiskSpace->value = value;
    return true;
}//setMinDiskSpace

bool OSOption::setMinDiskSpaceUnit(std::string unit)
{
    try
    {
        if (this->system == NULL)
            this->system = new SystemOption();
        if (this->system->minDiskSpace == NULL)
            this->system->minDiskSpace = new StorageCapacity();

        if (verifyStorageUnit(unit) == 0)
            throw ErrorClass( "disk space unit not recognized.");

        this->system->minDiskSpace->unit = unit;
        return true;
    }
    catch(const ErrorClass& eclass)
    {
        osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_error, eclass.errormsg);
        return false;
    }
}//setMinDiskSpaceUnit

bool OSOption::setMinMemorySize(std::string unit, std::string description, double value)
{
    if (verifyStorageUnit(unit) == 0)
        return false;

    if (this->system == NULL)
        this->system = new SystemOption();
    if (this->system->minMemorySize == NULL)
        this->system->minMemorySize = new StorageCapacity();
    this->system->minMemorySize->unit = unit;
    this->system->minMemorySize->value = value;
    this->system->minMemorySize->description = description;
    return true;
}//setMinDiskSpace

bool OSOption::setMinMemorySize(double value)
{
    if (this->system == NULL)
        this->system = new SystemOption();
    if (this->system->minMemorySize == NULL)
        this->system->minMemorySize = new StorageCapacity();
    this->system->minMemorySize->value = value;
    return true;
}//setMinMemorySize

bool OSOption::setMinMemoryUnit(std::string unit)
{
    try
    {
        if (this->system == NULL)
            this->system = new SystemOption();
        if (this->system->minMemorySize == NULL)
            this->system->minMemorySize = new StorageCapacity();

        if (verifyStorageUnit(unit) == 0)
            throw ErrorClass( "memory size unit not recognized.");

        this->system->minMemorySize->unit = unit;
        return true;
    }
    catch(const ErrorClass& eclass)
    {
        osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_error, eclass.errormsg);
        return false;
    }
}//setMinMemoryUnit

bool OSOption::setMinCPUSpeed(double value)
{
    if (this->system == NULL)
        this->system = new SystemOption();
    if (this->system->minCPUSpeed == NULL)
        this->system->minCPUSpeed = new CPUSpeed();
    this->system->minCPUSpeed->value = value;
    return true;
}//setMinCPUSpeed

bool OSOption::setMinCPUSpeed(std::string unit, std::string description, double value)
{
    if (verifyCPUSpeedUnit(unit) == 0)
        return false;

    if (this->system == NULL)
        this->system = new SystemOption();
    if (this->system->minCPUSpeed == NULL)
        this->system->minCPUSpeed = new CPUSpeed();
    this->system->minCPUSpeed->unit = unit;
    this->system->minCPUSpeed->value = value;
    this->system->minCPUSpeed->description = description;
    return true;
}//setMinCPUSpeed

bool OSOption::setMinCPUSpeedUnit(std::string unit)
{
    try
    {
        if (this->system == NULL)
            this->system = new SystemOption();
        if (this->system->minCPUSpeed == NULL)
            this->system->minCPUSpeed = new CPUSpeed();

        if (verifyCPUSpeedUnit(unit) == 0)
            throw ErrorClass( "CPU speed unit not recognized.");

        this->system->minCPUSpeed->unit = unit;
        return true;
    }
    catch(const ErrorClass& eclass)
    {
        osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_error, eclass.errormsg);
        return false;
    }
}//setMinCPUSpeedUnit

bool OSOption::setMinCPUNumber(int number)
{
    if (this->system == NULL)
        this->system = new SystemOption();
    if (this->system->minCPUNumber == NULL)
        this->system->minCPUNumber = new CPUNumber();
    this->system->minCPUNumber->value = number;
    return true;
}//setMinCPUNumber

bool OSOption::setMinCPUNumber(int number, std::string description)
{
    if (this->system == NULL)
        this->system = new SystemOption();
    if (this->system->minCPUNumber == NULL)
        this->system->minCPUNumber = new CPUNumber();
    this->system->minCPUNumber->value = number;
    this->system->minCPUNumber->description = description;
    return true;
}//setMinCPUNumber

bool OSOption::setOtherSystemOptions(int numberOfOptions, OtherOptionOrResult** other)
{
    if (this->system == NULL)
        this->system = new SystemOption();
    if (this->system->otherOptions == NULL)
        this->system->otherOptions = new OtherOptions();
    else
    {
        int i;
        for (i = 0; i < this->system->otherOptions->numberOfOtherOptions; i++)
            delete this->system->otherOptions->other[i];
        delete[] this->system->otherOptions->other;
        this->system->otherOptions->other = NULL;
        this->system->otherOptions->numberOfOtherOptions = 0;
    }
    return this->system->otherOptions->setOther(numberOfOptions, other);
}//setOtherSystemOptions

bool OSOption::setAnOtherSystemOption(std::string name, std::string value, std::string description)
{
    if (this->system == NULL)
        this->system = new SystemOption();
    if (this->system->otherOptions == NULL)
        this->system->otherOptions = new OtherOptions();
    return this->system->otherOptions->addOther(name, value, description);
}//setAnOtherSystemOption


/**
 *  set() options in the <service> element
 */

bool OSOption::setServiceType( std::string serviceType)
{
    try
    {
        if (this->service == NULL)
            this->service = new ServiceOption();

        if (verifyServiceType(serviceType) == 0)
            throw ErrorClass( "service type not recognized.");

        this->service->type = serviceType;
        return true;
    }
    catch(const ErrorClass& eclass)
    {
        osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_error, eclass.errormsg);
        return false;
    }
}//setServiceType

bool OSOption::setOtherServiceOptions(int numberOfOptions, OtherOptionOrResult** other)
{
    if (this->service == NULL)
        this->service = new ServiceOption();
    if (this->service->otherOptions == NULL)
        this->service->otherOptions = new OtherOptions();
    else
    {
        int i;
        for (i = 0; i < this->service->otherOptions->numberOfOtherOptions; i++)
            delete this->service->otherOptions->other[i];
        delete[] this->service->otherOptions->other;
        this->service->otherOptions->other = NULL;
    }
    return this->service->otherOptions->setOther(numberOfOptions, other);
}//setOtherServiceOptions

bool OSOption::setAnOtherServiceOption(std::string name, std::string value, std::string description)
{
    if (this->service == NULL)
        this->service = new ServiceOption();
    if (this->service->otherOptions == NULL)
        this->service->otherOptions = new OtherOptions();
    return this->service->otherOptions->addOther(name, value, description);
}//setAnOtherServiceOption

/**
 *  set() options in the <job> element
 */

bool OSOption::setMaxTime(double value)
{
    if (this->job == NULL)
        this->job = new JobOption();
    if (this->job->maxTime == NULL)
        this->job->maxTime = new TimeSpan();
    this->job->maxTime->value = value;
    return true;
}//setMaxTime

bool OSOption::setMaxTime(double value, std::string unit)
{
    if (verifyTimeUnit(unit) == 0)
        return false;

    if (this->job == NULL)
        this->job = new JobOption();

    if (this->job->maxTime == NULL)
        this->job->maxTime = new TimeSpan();
    this->job->maxTime->value = value;
    this->job->maxTime->unit = unit;
    return true;
}//setMaxTime

bool OSOption::setMaxTimeUnit(std::string unit)
{
    try
    {
        if (this->job == NULL)
            this->job = new JobOption();
        if (this->job->maxTime == NULL)
            this->job->maxTime = new TimeSpan();

        if (verifyTimeUnit(unit) == 0)
            throw ErrorClass( "time unit not recognized.");

        this->job->maxTime->unit = unit;
        return true;
    }
    catch(const ErrorClass& eclass)
    {
        osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_error, eclass.errormsg);
        return false;
    }
}//setMaxTimeUnit

bool OSOption::setRequestedStartTime(std::string time)
{
    if (this->job == NULL)
        this->job = new JobOption();
    this->job->requestedStartTime = time;
    return true;
}//setRequestedStartTime


bool OSOption::setJobDependencies(int numberOfDependencies, std::string* jobDependencies)
{
    if (this->job == NULL)
        this->job = new JobOption();
    if (this->job->dependencies == NULL)
        this->job->dependencies = new JobDependencies();
    else
        delete[] this->job->dependencies->jobID;
    this->job->dependencies->jobID = NULL;
    return this->job->dependencies->setJobID(numberOfDependencies, jobDependencies);
}//setJobDependencies

bool OSOption::setAnotherJobDependency(std::string jobID)
{
    if (this->job == NULL)
        this->job = new JobOption();
    if (this->job->dependencies == NULL)
        this->job->dependencies = new JobDependencies();
    return this->job->dependencies->addJobID(jobID);
}//setAnotherJobDependency


bool OSOption::setRequiredDirectories(int numberOfPaths, std::string* paths)
{
    if (this->job == NULL)
        this->job = new JobOption();
    if (this->job->requiredDirectories == NULL)
        this->job->requiredDirectories = new DirectoriesAndFiles();
    else
        delete[] this->job->requiredDirectories->path;
    this->job->requiredDirectories->path = NULL;
    return this->job->requiredDirectories->setPath(numberOfPaths, paths);
}//setRequiredDirectories

bool OSOption::setAnotherRequiredDirectory(std::string path)
{
    if (this->job == NULL)
        this->job = new JobOption();
    if (this->job->requiredDirectories == NULL)
        this->job->requiredDirectories = new DirectoriesAndFiles();
    return this->job->requiredDirectories->addPath(path);
}//setAnotherRequiredDirectory


bool OSOption::setRequiredFiles(int numberOfPaths, std::string* paths)
{
    if (this->job == NULL)
        this->job = new JobOption();
    if (this->job->requiredFiles == NULL)
        this->job->requiredFiles = new DirectoriesAndFiles();
    else
        delete[] this->job->requiredFiles->path;
    this->job->requiredFiles->path = NULL;
    return this->job->requiredFiles->setPath(numberOfPaths, paths);
}//setRequiredFiles

bool OSOption::setAnotherRequiredFile(std::string path)
{
    if (this->job == NULL)
        this->job = new JobOption();
    if (this->job->requiredFiles == NULL)
        this->job->requiredFiles = new DirectoriesAndFiles();
    return this->job->requiredFiles->addPath(path);
}//setAnotherRequiredFile


bool OSOption::setDirectoriesToMake(int numberOfPaths, std::string* paths)
{
    if (this->job == NULL)
        this->job = new JobOption();
    if (this->job->directoriesToMake == NULL)
        this->job->directoriesToMake = new DirectoriesAndFiles();
    else
        delete[] this->job->directoriesToMake->path;
    this->job->directoriesToMake->path = NULL;
    return this->job->directoriesToMake->setPath(numberOfPaths, paths);
}//setDirectoriesToMake

bool OSOption::setAnotherDirectoryToMake(std::string path)
{
    if (this->job == NULL)
        this->job = new JobOption();
    if (this->job->directoriesToMake == NULL)
        this->job->directoriesToMake = new DirectoriesAndFiles();
    return this->job->directoriesToMake->addPath(path);
}//setAnotherDirectoryToMake


bool OSOption::setFilesToMake(int numberOfPaths, std::string* paths)
{
    if (this->job == NULL)
        this->job = new JobOption();
    if (this->job->filesToMake == NULL)
        this->job->filesToMake = new DirectoriesAndFiles();
    else
        delete[] this->job->filesToMake->path;
    this->job->filesToMake->path = NULL;
    return this->job->filesToMake->setPath(numberOfPaths, paths);
}//setFilesToMake

bool OSOption::setAnotherFileToMake(std::string path)
{
    if (this->job == NULL)
        this->job = new JobOption();
    if (this->job->filesToMake == NULL)
        this->job->filesToMake = new DirectoriesAndFiles();
    return this->job->filesToMake->addPath(path);
}//setAnotherFileToMake

bool OSOption::setPathPairs(int object, std::string *from, std::string *to,
                                bool *makeCopy, int numberOfPathPairs)
{
    if (numberOfPathPairs < 0) return false;
    if (this->job == NULL)
        this->job = new JobOption();
    switch (object)
    {
    case ENUM_PATHPAIR_input_dir:
    {
        if (this->job->inputDirectoriesToMove == NULL)
            this->job->inputDirectoriesToMove = new PathPairs();
        return this->job->inputDirectoriesToMove->setPathPair(from, to, makeCopy, numberOfPathPairs);
    }
    case ENUM_PATHPAIR_input_file:
    {
        if (this->job->inputFilesToMove == NULL)
            this->job->inputFilesToMove = new PathPairs();
        return this->job->inputFilesToMove->setPathPair(from, to, makeCopy, numberOfPathPairs);
    }
    case ENUM_PATHPAIR_output_file:
    {
        if (this->job->outputFilesToMove == NULL)
            this->job->outputFilesToMove = new PathPairs();
        return this->job->outputFilesToMove->setPathPair(from, to, makeCopy, numberOfPathPairs);
    }
    case ENUM_PATHPAIR_output_dir:
    {
        if (this->job->outputDirectoriesToMove == NULL)
            this->job->outputDirectoriesToMove = new PathPairs();
        return this->job->outputDirectoriesToMove->setPathPair(from, to, makeCopy, numberOfPathPairs);
    }
    default:
        throw ErrorClass("target object not implemented in setPathPairs");
    }

}//setPathPairs


bool OSOption::setInputDirectoriesToMove(int numberOfPathPairs, PathPair** pathPair)
{
    if (this->job == NULL)
        this->job = new JobOption();
    if (this->job->inputDirectoriesToMove == NULL)
        this->job->inputDirectoriesToMove = new PathPairs();
    else
        delete[] this->job->inputDirectoriesToMove->pathPair;
    this->job->inputDirectoriesToMove->pathPair = NULL;
    return this->job->inputDirectoriesToMove->setPathPair(numberOfPathPairs, pathPair);
}//setInputDirectoriesToMove

bool OSOption::setAnotherInputDirectoryToMove(std::string fromPath, std::string toPath, bool makeCopy)
{
    if (this->job == NULL)
        this->job = new JobOption();
    if (this->job->inputDirectoriesToMove == NULL)
        this->job->inputDirectoriesToMove = new PathPairs();
    return this->job->inputDirectoriesToMove->addPathPair(fromPath, toPath, makeCopy);
}//setAnotherInputDirectoryToMove


bool OSOption::setInputFilesToMove(int numberOfPathPairs, PathPair** pathPair)
{
    if (this->job == NULL)
        this->job = new JobOption();
    if (this->job->inputFilesToMove == NULL)
        this->job->inputFilesToMove = new PathPairs();
    else
        delete[] this->job->inputFilesToMove->pathPair;
    this->job->inputFilesToMove->pathPair = NULL;
    return this->job->inputFilesToMove->setPathPair(numberOfPathPairs, pathPair);
}//setInputFilesToMove

bool OSOption::setAnotherInputFileToMove(std::string fromPath, std::string toPath, bool makeCopy)
{
    if (this->job == NULL)
        this->job = new JobOption();
    if (this->job->inputFilesToMove == NULL)
        this->job->inputFilesToMove = new PathPairs();
    return this->job->inputFilesToMove->addPathPair(fromPath, toPath, makeCopy);
}//setAnotherInputFileToMove


bool OSOption::setOutputFilesToMove(int numberOfPathPairs, PathPair** pathPair)
{
    if (this->job == NULL)
        this->job = new JobOption();
    if (this->job->outputFilesToMove == NULL)
        this->job->outputFilesToMove = new PathPairs();
    else
        delete[] this->job->outputFilesToMove->pathPair;
    this->job->outputFilesToMove->pathPair = NULL;
    return this->job->outputFilesToMove->setPathPair(numberOfPathPairs, pathPair);
}//setOutputFilesToMove

bool OSOption::setAnotherOutputFileToMove(std::string fromPath, std::string toPath, bool makeCopy)
{
    if (this->job == NULL)
        this->job = new JobOption();
    if (this->job->outputFilesToMove == NULL)
        this->job->outputFilesToMove = new PathPairs();
    return this->job->outputFilesToMove->addPathPair(fromPath, toPath, makeCopy);
}//setAnotherOutputFileToMove


bool OSOption::setOutputDirectoriesToMove(int numberOfPathPairs, PathPair** pathPair)
{
    if (this->job == NULL)
        this->job = new JobOption();
    if (this->job->outputDirectoriesToMove == NULL)
        this->job->outputDirectoriesToMove = new PathPairs();
    else
        delete[] this->job->outputDirectoriesToMove->pathPair;
    this->job->outputDirectoriesToMove->pathPair = NULL;
    return this->job->outputDirectoriesToMove->setPathPair(numberOfPathPairs, pathPair);
}//setOutputDirectoriesToMove

bool OSOption::setAnotherOutputDirectoryToMove(std::string fromPath, std::string toPath, bool makeCopy)
{
    if (this->job == NULL)
        this->job = new JobOption();
    if (this->job->outputDirectoriesToMove == NULL)
        this->job->outputDirectoriesToMove = new PathPairs();
    return this->job->outputDirectoriesToMove->addPathPair(fromPath, toPath, makeCopy);
}//setAnotherOutputDirectoryToMove


bool OSOption::setFilesToDelete(int numberOfPaths, std::string* paths)
{
    if (this->job == NULL)
        this->job = new JobOption();
    if (this->job->filesToDelete == NULL)
        this->job->filesToDelete = new DirectoriesAndFiles();
    else
        delete[] this->job->filesToDelete->path;
    this->job->filesToDelete->path = NULL;
    return this->job->filesToDelete->setPath(numberOfPaths, paths);
}//setFilesToDelete

bool OSOption::setAnotherFileToDelete(std::string path)
{
    if (this->job == NULL)
        this->job = new JobOption();
    if (this->job->filesToDelete == NULL)
        this->job->filesToDelete = new DirectoriesAndFiles();
    return this->job->filesToDelete->addPath(path);
}//setAnotherFileToDelete


bool OSOption::setDirectoriesToDelete(int numberOfPaths, std::string* paths)
{
    if (this->job == NULL)
        this->job = new JobOption();
    if (this->job->directoriesToDelete == NULL)
        this->job->directoriesToDelete = new DirectoriesAndFiles();
    else
        delete[] this->job->directoriesToDelete->path;
    this->job->directoriesToDelete->path = NULL;
    return this->job->directoriesToDelete->setPath(numberOfPaths, paths);
}//setDirectoriesToDelete

bool OSOption::setAnotherDirectoryToDelete(std::string path)
{
    if (this->job == NULL)
        this->job = new JobOption();
    if (this->job->directoriesToDelete == NULL)
        this->job->directoriesToDelete = new DirectoriesAndFiles();
    return this->job->directoriesToDelete->addPath(path);
}//setAnotherDirectoryToDelete


bool OSOption::setProcessesToKill(int numberOfProcesses, std::string* processes)
{
    if (this->job == NULL)
        this->job = new JobOption();
    if (this->job->processesToKill == NULL)
        this->job->processesToKill = new Processes();
    else
        delete[] this->job->processesToKill->process;
    this->job->processesToKill->process = NULL;
    return this->job->processesToKill->setProcess(numberOfProcesses, processes);
}//setProcessesToKill

bool OSOption::setAnotherProcessToKill(std::string process)
{
    if (this->job == NULL)
        this->job = new JobOption();
    if (this->job->processesToKill == NULL)
        this->job->processesToKill = new Processes();
    return this->job->processesToKill->addProcess(process);
}//setAnotherProcessToKill


bool OSOption::setOtherJobOptions(int numberOfOptions, OtherOptionOrResult** other)
{
    if (this->job == NULL)
        this->job = new JobOption();
    if (this->job->otherOptions == NULL)
        this->job->otherOptions = new OtherOptions();
    else
    {
        int i;
        for (i = 0; i < this->job->otherOptions->numberOfOtherOptions; i++)
            delete this->job->otherOptions->other[i];
        delete[] this->job->otherOptions->other;
        this->job->otherOptions->other = NULL;
    }
    return this->job->otherOptions->setOther(numberOfOptions, other);
}//setOtherJobOptions

bool OSOption::setAnOtherJobOption(std::string name, std::string value, std::string description)
{
    if (this->job == NULL)
        this->job = new JobOption();
    if (this->job->otherOptions == NULL)
        this->job->otherOptions = new OtherOptions();
    return this->job->otherOptions->addOther(name, value, description);
}//setAnOtherJobOption


bool OSOption::setNumberOfVariables(int numberOfVariables)
{
    if (this->optimization == NULL)
        this->optimization = new OptimizationOption();
    this->optimization->numberOfVariables = numberOfVariables;
    this->optimization->numberOfVariablesIsSet = true;
    return true;
}//setNumberOfVariables

bool OSOption::setNumberOfObjectives(int numberOfObjectives)
{
    if (this->optimization == NULL)
        this->optimization = new OptimizationOption();
    this->optimization->numberOfObjectives = numberOfObjectives;
    this->optimization->numberOfObjectivesIsSet = true;
    return true;
}//setNumberOfObjectives

bool OSOption::setNumberOfConstraints(int numberOfConstraints)
{
    if (this->optimization == NULL)
        this->optimization = new OptimizationOption();
    this->optimization->numberOfConstraints = numberOfConstraints;
    this->optimization->numberOfConstraintsIsSet = true;
    return true;
}//setNumberOfConstraints


bool OSOption::setInitVarValues(int numberOfVar, int* idx, double* value, std::string* name)
{
    if (this->optimization == NULL)
        this->optimization = new OptimizationOption();
    if (this->optimization->variables == NULL)
        this->optimization->variables = new VariableOption();
    if (this->optimization->variables->initialVariableValues != NULL)
        return false;

    this->optimization->variables->initialVariableValues = new InitVariableValues();

    return this->optimization->variables->initialVariableValues->setVar(numberOfVar, idx, value, name);
}//setInitVarValues

bool OSOption::setInitVarValuesSparse(int numberOfVar, InitVarValue** var)
{
    if (this->optimization == NULL)
        this->optimization = new OptimizationOption();
    if (this->optimization->variables == NULL)
        this->optimization->variables = new VariableOption();
    if (this->optimization->variables->initialVariableValues == NULL)
        this->optimization->variables->initialVariableValues = new InitVariableValues();
    else
    {
        int i;
        for (i = 0; i < this->optimization->variables->initialVariableValues->numberOfVar; i++)
            delete this->optimization->variables->initialVariableValues->var[i];
        delete[] this->optimization->variables->initialVariableValues->var;
        this->optimization->variables->initialVariableValues->var = NULL;
    }
    return this->optimization->variables->initialVariableValues->setVar(numberOfVar, var);
}//setInitVarValuesSparse

bool OSOption::setInitVarValuesSparse(int numberOfVar, InitVarValue** var, ENUM_COMBINE_ARRAYS disp)
{
    if (this->optimization == NULL)
        this->optimization = new OptimizationOption();
    if (this->optimization->variables == NULL)
        this->optimization->variables = new VariableOption();
    if (this->optimization->variables->initialVariableValues == NULL)
        this->optimization->variables->initialVariableValues = new InitVariableValues();
    return this->optimization->variables->initialVariableValues->setVar(numberOfVar, var, disp);
}//setInitVarValuesSparse

bool OSOption::setInitVarValuesDense(int numberOfVar, double *value)
{
    if (this->optimization == NULL)
        this->optimization = new OptimizationOption();
    if (this->optimization->variables == NULL)
        this->optimization->variables = new VariableOption();
    if (this->optimization->variables->initialVariableValues == NULL)
        this->optimization->variables->initialVariableValues = new InitVariableValues();
    else
    {
        delete[] this->optimization->variables->initialVariableValues->var;
        this->optimization->variables->initialVariableValues->var = NULL;
    }

    int i;
    for (i = 0; i < numberOfVar; i++)
    {
//        if (!CoinIsnan(value[i]))
        if (!this->optimization->variables->initialVariableValues->addVar(i, value[i]))
            return false;
    }
    return true;
}//setInitVarValuesDense

bool OSOption::setAnotherInitVarValue(int idx, double value)
{
    if (this->optimization == NULL)
        this->optimization = new OptimizationOption();
    if (this->optimization->variables == NULL)
        this->optimization->variables = new VariableOption();
    if (this->optimization->variables->initialVariableValues == NULL)
        this->optimization->variables->initialVariableValues = new InitVariableValues();
    return this->optimization->variables->initialVariableValues->addVar(idx, value);
}//setAnotherInitVarValue

bool OSOption::setInitVarValuesString(int numberOfVar, int* idx, std::string* value, std::string* name)
{
    if (this->optimization == NULL)
        this->optimization = new OptimizationOption();
    if (this->optimization->variables == NULL)
        this->optimization->variables = new VariableOption();
    if (this->optimization->variables->initialVariableValuesString != NULL)
        return false;

    this->optimization->variables->initialVariableValuesString = new InitVariableValuesString();

    return this->optimization->variables->initialVariableValuesString->setVar(numberOfVar, idx, value, name);
}//setInitVarValuesString

bool OSOption::setInitVarValuesStringSparse(int numberOfVar, InitVarValueString** var)
{
    if (this->optimization == NULL)
        this->optimization = new OptimizationOption();
    if (this->optimization->variables == NULL)
        this->optimization->variables = new VariableOption();
    if (this->optimization->variables->initialVariableValuesString == NULL)
        this->optimization->variables->initialVariableValuesString = new InitVariableValuesString();
    else
    {
        int i;
        for (i = 0; i < this->optimization->variables->initialVariableValuesString->numberOfVar; i++)
            delete this->optimization->variables->initialVariableValuesString->var[i];
        delete[] this->optimization->variables->initialVariableValuesString->var;
        this->optimization->variables->initialVariableValuesString->var = NULL;
    }
    return this->optimization->variables->initialVariableValuesString->setVar(numberOfVar, var);
}//setInitVarValuesStringSparse

bool OSOption::setInitVarValuesStringSparse(int numberOfVar, InitVarValueString** var, ENUM_COMBINE_ARRAYS disp)
{
    if (this->optimization == NULL)
        this->optimization = new OptimizationOption();
    if (this->optimization->variables == NULL)
        this->optimization->variables = new VariableOption();
    if (this->optimization->variables->initialVariableValuesString == NULL)
        this->optimization->variables->initialVariableValuesString = new InitVariableValuesString();
    return this->optimization->variables->initialVariableValuesString->setVar(numberOfVar, var, disp);
}//setInitVarValuesStringSparse

bool OSOption::setInitVarValuesStringDense(int numberOfVar, std::string *value)
{
    if (this->optimization == NULL)
        this->optimization = new OptimizationOption();
    if (this->optimization->variables == NULL)
        this->optimization->variables = new VariableOption();
    if (this->optimization->variables->initialVariableValuesString == NULL)
        this->optimization->variables->initialVariableValuesString = new InitVariableValuesString();
    else
    {
        delete[] this->optimization->variables->initialVariableValuesString->var;
        this->optimization->variables->initialVariableValuesString->var = NULL;
    }
    int i;
    for (i = 0; i < numberOfVar; i++)
    {
        if (value[i] != "")
            if (!this->optimization->variables->initialVariableValuesString->addVar(i, value[i]))
                return false;
    }
    return true;
}//setInitVarValuesStringDense

bool OSOption::setAnotherInitVarValueString(int idx, std::string value)
{
    if (this->optimization == NULL)
        this->optimization = new OptimizationOption();
    if (this->optimization->variables == NULL)
        this->optimization->variables = new VariableOption();
    if (this->optimization->variables->initialVariableValuesString == NULL)
        this->optimization->variables->initialVariableValuesString = new InitVariableValuesString();
    return this->optimization->variables->initialVariableValuesString->addVar(idx, value);
}//setAnotherInitVarValueString

bool OSOption::setInitBasisStatus(int object, int status, int *i, int ni)
{
    if (optimization == NULL) return false;

    switch (object)
    {
    case ENUM_PROBLEM_COMPONENT_variables:
    {
        if (optimization->variables == NULL)
            optimization->variables = new VariableOption();
        if (optimization->variables->initialBasisStatus == NULL)
            optimization->variables->initialBasisStatus = new BasisStatus();

        for (int j=0; j<ni; j++)
        {
            if (i[j] < 0)
                return false;
        }
        return optimization->variables->initialBasisStatus->setIntVector(status, i, ni);
    }
    case ENUM_PROBLEM_COMPONENT_objectives:
    {
        if (optimization->objectives == NULL)
            optimization->objectives = new ObjectiveOption();
        if (optimization->objectives->initialBasisStatus == NULL)
            optimization->objectives->initialBasisStatus = new BasisStatus();
        for (int j=0; j<ni; j++) 
        {
            if (i[j] >= 0) 
                return false;
        }
        return optimization->objectives->initialBasisStatus->setIntVector(status, i, ni);
    }
    case ENUM_PROBLEM_COMPONENT_constraints:
    {
        if (optimization->constraints == NULL)
            optimization->constraints = new ConstraintOption();
        if (optimization->constraints->initialBasisStatus == NULL)
            optimization->constraints->initialBasisStatus = new BasisStatus();
        for (int j=0; j<ni; j++) 
        {
            if (i[j] < 0) 
                return false;
        }
        return optimization->constraints->initialBasisStatus->setIntVector(status, i, ni);
    }
    default:
        throw ErrorClass("target object not implemented in setInitBasisStatus");
    }
}//setInitBasisStatus

bool OSOption::setAnotherInitBasisStatus(int object, int idx, int status)
{
    if (optimization == NULL) return false;

    switch (object)
    {
    case ENUM_PROBLEM_COMPONENT_variables:
    {
        if (optimization->variables == NULL)
            optimization->variables = new VariableOption();
        if (optimization->variables->initialBasisStatus == NULL)
            optimization->variables->initialBasisStatus = new BasisStatus();
        if (idx < 0) return false;
        return optimization->variables->initialBasisStatus->addIdx(status, idx);
    }
    case ENUM_PROBLEM_COMPONENT_objectives:
    {
        if (optimization->objectives == NULL)
            optimization->objectives = new ObjectiveOption();
        if (optimization->objectives->initialBasisStatus == NULL)
            optimization->objectives->initialBasisStatus = new BasisStatus();
        if (idx >= 0) return false;
        return optimization->objectives->initialBasisStatus->addIdx(status, idx);
    }
    case ENUM_PROBLEM_COMPONENT_constraints:
    {
        if (optimization->constraints == NULL)
            optimization->constraints = new ConstraintOption();
        if (optimization->constraints->initialBasisStatus == NULL)
            optimization->constraints->initialBasisStatus = new BasisStatus();
        if (idx < 0) return false;
        return optimization->constraints->initialBasisStatus->addIdx(status, idx);
    }
    default:
        throw ErrorClass("target object not implemented in setAnotherInitBasisStatus");
    }
}//setAnotherInitBasisStatus

bool OSOption::setIntegerVariableBranchingWeights(int numberOfVar, int* idx, double* value, std::string* name)
{
    if (this->optimization == NULL)
        this->optimization = new OptimizationOption();
    if (this->optimization->variables == NULL)
        this->optimization->variables = new VariableOption();
    if (this->optimization->variables->integerVariableBranchingWeights != NULL)
        return false;

    this->optimization->variables->integerVariableBranchingWeights = new IntegerVariableBranchingWeights();

    return this->optimization->variables->integerVariableBranchingWeights->setVar(numberOfVar, idx, value, name);
}//setIntegerVariableBranchingWeights

bool OSOption::setIntegerVariableBranchingWeightsSparse(int numberOfVar, BranchingWeight** var)
{
    if (this->optimization == NULL)
        this->optimization = new OptimizationOption();
    if (this->optimization->variables == NULL)
        this->optimization->variables = new VariableOption();
    if (this->optimization->variables->integerVariableBranchingWeights == NULL)
        this->optimization->variables->integerVariableBranchingWeights = new IntegerVariableBranchingWeights();
    else
    {
        int i;
        for (i = 0; i < this->optimization->variables->integerVariableBranchingWeights->numberOfVar; i++)
            delete this->optimization->variables->integerVariableBranchingWeights->var[i];
        delete[] this->optimization->variables->integerVariableBranchingWeights->var;
        this->optimization->variables->integerVariableBranchingWeights->var = NULL;
    }
    return this->optimization->variables->integerVariableBranchingWeights->setVar(numberOfVar, var);
}//setIntegerVariableBranchingWeightsSparse

bool OSOption::setIntegerVariableBranchingWeightsSparse(int numberOfVar, BranchingWeight** var, ENUM_COMBINE_ARRAYS disp)
{
    if (this->optimization == NULL)
        this->optimization = new OptimizationOption();
    if (this->optimization->variables == NULL)
        this->optimization->variables = new VariableOption();
    if (this->optimization->variables->integerVariableBranchingWeights == NULL)
        this->optimization->variables->integerVariableBranchingWeights = new IntegerVariableBranchingWeights();
    return this->optimization->variables->integerVariableBranchingWeights->setVar(numberOfVar, var, disp);
}//setIntegerVariableBranchingWeightsSparse

bool OSOption::setIntegerVariableBranchingWeightsDense(int numberOfVar, double *value)
{
    if (this->optimization == NULL)
        this->optimization = new OptimizationOption();
    if (this->optimization->variables == NULL)
        this->optimization->variables = new VariableOption();
    if (this->optimization->variables->integerVariableBranchingWeights == NULL)
        this->optimization->variables->integerVariableBranchingWeights = new IntegerVariableBranchingWeights();
    else
    {
        delete[] this->optimization->variables->integerVariableBranchingWeights->var;
        this->optimization->variables->integerVariableBranchingWeights->var = NULL;
    }
    int i;
    for (i = 0; i < numberOfVar; i++)
    {
//        if (!CoinIsnan(value[i]))
        if (!this->optimization->variables->integerVariableBranchingWeights->addVar(i, value[i]))
            return false;
    }
    return true;
}//setIntegerVariableBranchingWeightsDense

bool OSOption::setAnotherIntegerVariableBranchingWeight(int idx, double value)
{
    if (this->optimization == NULL)
        this->optimization = new OptimizationOption();
    if (this->optimization->variables == NULL)
        this->optimization->variables = new VariableOption();
    if (this->optimization->variables->integerVariableBranchingWeights == NULL)
        this->optimization->variables->integerVariableBranchingWeights = new IntegerVariableBranchingWeights();
    return this->optimization->variables->integerVariableBranchingWeights->addVar(idx, value);
}//setAnotherIntegerVariableBranchingWeight


bool OSOption::setSOSVariableBranchingWeights(int numberOfSOS, SOSWeights** sos)
{
    if (this->optimization == NULL)
        this->optimization = new OptimizationOption();
    if (this->optimization->variables == NULL)
        this->optimization->variables = new VariableOption();
    if (this->optimization->variables->sosVariableBranchingWeights == NULL)
        this->optimization->variables->sosVariableBranchingWeights = new SOSVariableBranchingWeights();
    else
    {
        int i;
        for (i = 0; i < this->optimization->variables->sosVariableBranchingWeights->numberOfSOS; i++)
            delete this->optimization->variables->sosVariableBranchingWeights->sos[i];
        delete[] this->optimization->variables->sosVariableBranchingWeights->sos;
        this->optimization->variables->sosVariableBranchingWeights->sos = NULL;
    }
    return this->optimization->variables->sosVariableBranchingWeights->setSOS(numberOfSOS, sos);
}//setSOSVariableBranchingWeights

bool OSOption::setAnotherSOSVariableBranchingWeight(int sosIdx, int nvar, double weight, int* idx, double* value, std::string* name)
{
    if (this->optimization == NULL)
        this->optimization = new OptimizationOption();
    if (this->optimization->variables == NULL)
        this->optimization->variables = new VariableOption();
    if (this->optimization->variables->sosVariableBranchingWeights == NULL)
        this->optimization->variables->sosVariableBranchingWeights = new SOSVariableBranchingWeights();
    return this->optimization->variables->sosVariableBranchingWeights->addSOS(sosIdx, nvar, weight, idx, value, name);
}//setAnotherSOSVariableBranchingWeight

bool OSOption::setNumberOfOtherVariableOptions(int numberOfOther)
{
    if (optimization == NULL) 
        optimization = new OptimizationOption();
    if (optimization->variables == NULL)
        optimization->variables = new VariableOption();
    if(optimization->variables->numberOfOtherVariableOptions < 0) return false;

    optimization->variables->numberOfOtherVariableOptions = numberOfOther;

    if (numberOfOther > 0)
    {
        optimization->variables->other = new OtherVariableOptionOrResult*[numberOfOther];

        for (int j=0; j < numberOfOther; j++)
            optimization->variables->other[j] = new OtherVariableOptionOrResult();
    }

    return true;
}//setNumberOfOtherVariableOptions

bool OSOption::setOtherVariableOptionAttributes(int iOther, int numberOfVar,
        int numberOfEnumerations, std::string name,
        std::string value, std::string solver,
        std::string category, std::string type,
        std::string varType, std::string enumType,
        std::string description)
{
    if (optimization == NULL) return false;
    if (optimization->variables == NULL) return false;
    if (optimization->variables->other == NULL) return false;

    if (iOther < 0 || iOther >= optimization->variables->numberOfOtherVariableOptions) return false;

    optimization->variables->other[iOther]->numberOfVar          = numberOfVar;
    optimization->variables->other[iOther]->numberOfEnumerations = numberOfEnumerations;
    optimization->variables->other[iOther]->name                 = name;
    optimization->variables->other[iOther]->value                = value;
    optimization->variables->other[iOther]->solver               = solver;
    optimization->variables->other[iOther]->category             = category;
    optimization->variables->other[iOther]->type                 = type;
    optimization->variables->other[iOther]->enumType             = enumType;
    optimization->variables->other[iOther]->varType              = varType;
    optimization->variables->other[iOther]->description          = description;

    if (numberOfVar > 0)
    {
        optimization->variables->other[iOther]->var = new OtherOptionOrResultElementString*[numberOfVar];
        for (int j=0; j<numberOfVar; j++)
            optimization->variables->other[iOther]->var[j] = new OtherOptionOrResultElementString();
    }

    if (numberOfEnumerations > 0)
    {
        optimization->variables->other[iOther]->enumeration
            = new OtherOptionOrResultEnumeration*[numberOfEnumerations];
        for (int j=0; j<numberOfEnumerations; j++)
            optimization->variables->other[iOther]->enumeration[j]
                = new OtherOptionOrResultEnumeration();
    }
    return true;
}//setOtherVariableOptionAttributes


bool OSOption::setOtherOptionOrResultEnumeration(int object, int otherOptionNumber, int enumerationNumber,
        int numberOfEl, std::string value, std::string description, int* idxArray)
{
    if (optimization == NULL) return false;
    if (numberOfEl < 0) return false;

    switch (object)
    {
    case ENUM_PROBLEM_COMPONENT_variables:
    {
        if (optimization->variables == NULL) return false;
        if (optimization->variables->other == NULL) return false;
        if (otherOptionNumber < 0 || otherOptionNumber >= optimization->variables->numberOfOtherVariableOptions) return false;
        if (optimization->variables->other[otherOptionNumber] == NULL) return false;
        for (int j=0; j<numberOfEl; j++) if (idxArray[j] < 0) return false;

        if (optimization->variables->other[otherOptionNumber]->enumeration == NULL) return false;
        if (enumerationNumber < 0 || enumerationNumber >= optimization->variables->other[otherOptionNumber]->numberOfEnumerations) return false;
        if (optimization->variables->other[otherOptionNumber]->enumeration[enumerationNumber] == NULL) return false;

        return optimization->variables->other[otherOptionNumber]->enumeration[enumerationNumber]->setOtherOptionOrResultEnumeration(value, description, idxArray, numberOfEl);
    }

    case ENUM_PROBLEM_COMPONENT_objectives:
    {
        if (optimization->objectives == NULL) return false;
        if (optimization->objectives->other == NULL) return false;
        if (otherOptionNumber < 0 || otherOptionNumber >= optimization->objectives->numberOfOtherObjectiveOptions) return false;
        if (optimization->objectives->other[otherOptionNumber] == NULL) return false;
        for (int j=0; j<numberOfEl; j++) if (idxArray[j] >= 0) return false;

        if (optimization->objectives->other[otherOptionNumber]->enumeration == NULL) return false;
        if (enumerationNumber < 0 || enumerationNumber >= optimization->objectives->other[otherOptionNumber]->numberOfEnumerations) return false;
        if (optimization->objectives->other[otherOptionNumber]->enumeration[enumerationNumber] == NULL) return false;

        return optimization->objectives->other[otherOptionNumber]->enumeration[enumerationNumber]->setOtherOptionOrResultEnumeration(value, description, idxArray, numberOfEl);
    }

    case ENUM_PROBLEM_COMPONENT_constraints:
    {
        if (optimization->constraints == NULL) return false;
        if (optimization->constraints->other == NULL) return false;
        if (otherOptionNumber < 0 || otherOptionNumber >= optimization->constraints->numberOfOtherConstraintOptions) return false;
        if (optimization->constraints->other[otherOptionNumber] == NULL) return false;
        for (int j=0; j<numberOfEl; j++) if (idxArray[j] < 0) return false;


        if (optimization->constraints->other[otherOptionNumber]->enumeration == NULL) return false;
        if (enumerationNumber < 0 || enumerationNumber >= optimization->constraints->other[otherOptionNumber]->numberOfEnumerations) return false;
        if (optimization->constraints->other[otherOptionNumber]->enumeration[enumerationNumber] == NULL) return false;

        return optimization->constraints->other[otherOptionNumber]->enumeration[enumerationNumber]->setOtherOptionOrResultEnumeration(value, description, idxArray, numberOfEl);
    }
    default:
        throw ErrorClass("target object not implemented in setOtherOptionOrResultEnumeration");
    }
}//setOtherOptionOrResultEnumeration


bool OSOption::setOtherVariableOptionVar(int otherOptionNumber, int varNumber,
        int idx, std::string name, std::string value, std::string lbValue, std::string ubValue)
{
    if (optimization == NULL) return false;

    if (optimization->variables == NULL) return false;
    if (optimization->variables->other == NULL) return false;
    if (otherOptionNumber < 0 || otherOptionNumber >= optimization->variables->numberOfOtherVariableOptions) return false;
    if (optimization->variables->other[otherOptionNumber] == NULL) return false;
    if (idx < 0) return false;

    if (optimization->variables->other[otherOptionNumber]->var == NULL) return false;
    if (varNumber < 0 || varNumber >= optimization->variables->other[otherOptionNumber]->numberOfVar) return false;
    if (optimization->variables->other[otherOptionNumber]->var[varNumber] == NULL) return false;

    optimization->variables->other[otherOptionNumber]->var[varNumber]->idx = idx;
    optimization->variables->other[otherOptionNumber]->var[varNumber]->name = name;
    optimization->variables->other[otherOptionNumber]->var[varNumber]->value = value;
    optimization->variables->other[otherOptionNumber]->var[varNumber]->lbValue = lbValue;
    optimization->variables->other[otherOptionNumber]->var[varNumber]->ubValue = ubValue;
    return true;
}//setOtherVariableOptionVar

bool OSOption::setOtherVariableOptions(int numberOfOptions, OtherVariableOptionOrResult** other)
{
    if (this->optimization == NULL)
        this->optimization = new OptimizationOption();
    if (this->optimization->variables == NULL)
        this->optimization->variables = new VariableOption();
    else
    {
        int i;
        for (i = 0; i < this->optimization->variables->numberOfOtherVariableOptions; i++)
            delete this->optimization->variables->other[i];
        delete[] this->optimization->variables->other;
        this->optimization->variables->other = NULL;
    }
    return this->optimization->variables->setOther(numberOfOptions, other);
}//setOtherVariableOptions

bool OSOption::setAnOtherVariableOption(OtherVariableOptionOrResult* optionValue)
{
    if (this->optimization == NULL)
        this->optimization = new OptimizationOption();
    if (this->optimization->variables == NULL)
        this->optimization->variables = new VariableOption();
    return this->optimization->variables->addOther(optionValue);
}//setAnOtherVariableOption

bool OSOption::setInitObjValues(int numberOfObj, int* idx, double* value, std::string* name)
{
    if (this->optimization == NULL)
        this->optimization = new OptimizationOption();
    if (this->optimization->objectives == NULL)
        this->optimization->objectives = new ObjectiveOption();
    if (this->optimization->objectives->initialObjectiveValues != NULL)
        return false;

    this->optimization->objectives->initialObjectiveValues = new InitObjectiveValues();

    return this->optimization->objectives->initialObjectiveValues->setObj(numberOfObj, idx, value, name);
}//setInitObjValues

bool OSOption::setInitObjValuesSparse(int numberOfObj, InitObjValue** obj)
{
    if (this->optimization == NULL)
        this->optimization = new OptimizationOption();
    if (this->optimization->objectives == NULL)
        this->optimization->objectives = new ObjectiveOption();
    if (this->optimization->objectives->initialObjectiveValues == NULL)
        this->optimization->objectives->initialObjectiveValues = new InitObjectiveValues();
    else
    {
        int i;
        for (i = 0; i < this->optimization->objectives->initialObjectiveValues->numberOfObj; i++)
            delete this->optimization->objectives->initialObjectiveValues->obj[i];
        delete[] this->optimization->objectives->initialObjectiveValues->obj;
        this->optimization->objectives->initialObjectiveValues->obj = NULL;
    }
    return this->optimization->objectives->initialObjectiveValues->setObj(numberOfObj, obj);
}//setInitObjValuesSparse

bool OSOption::setInitObjValuesSparse(int numberOfObj, InitObjValue** obj, ENUM_COMBINE_ARRAYS disp)
{
    if (this->optimization == NULL)
        this->optimization = new OptimizationOption();
    if (this->optimization->objectives == NULL)
        this->optimization->objectives = new ObjectiveOption();
    if (this->optimization->objectives->initialObjectiveValues == NULL)
        this->optimization->objectives->initialObjectiveValues = new InitObjectiveValues();
    return this->optimization->objectives->initialObjectiveValues->setObj(numberOfObj, obj, disp);
}//setInitObjValuesSparse

bool OSOption::setInitObjValuesDense(int numberOfObj, double *value)
{
    if (this->optimization == NULL)
        this->optimization = new OptimizationOption();
    if (this->optimization->objectives == NULL)
        this->optimization->objectives = new ObjectiveOption();
    if (this->optimization->objectives->initialObjectiveValues == NULL)
        this->optimization->objectives->initialObjectiveValues = new InitObjectiveValues();
    else
    {
        delete[] this->optimization->objectives->initialObjectiveValues->obj;
        this->optimization->objectives->initialObjectiveValues->obj = NULL;
    }
    int i;
    for (i = 0; i < numberOfObj; i++)
    {
//        if (!CoinIsnan(value[i]))
        if (!this->optimization->objectives->initialObjectiveValues->addObj(-1-i, value[i]))
            return false;
    }
    return true;
}//setInitObjValuesDense

bool OSOption::setAnotherInitObjValue(int idx, double value)
{
    if (this->optimization == NULL)
        this->optimization = new OptimizationOption();
    if (this->optimization->objectives == NULL)
        this->optimization->objectives = new ObjectiveOption();
    if (this->optimization->objectives->initialObjectiveValues == NULL)
        this->optimization->objectives->initialObjectiveValues = new InitObjectiveValues();
    return this->optimization->objectives->initialObjectiveValues->addObj(idx, value);
}//setAnotherInitObjValue

bool OSOption::setInitObjBounds(int numberOfObj, int* idx, double* lbValue, double* ubValue, std::string* name)
{
    if (this->optimization == NULL)
        this->optimization = new OptimizationOption();
    if (this->optimization->objectives == NULL)
        this->optimization->objectives = new ObjectiveOption();

    if (this->optimization->objectives->initialObjectiveBounds != NULL)
        return false;

    this->optimization->objectives->initialObjectiveBounds = new InitObjectiveBounds();

    return this->optimization->objectives->initialObjectiveBounds->setObj(numberOfObj, idx, lbValue, ubValue, name);
}//setInitObjBounds

bool OSOption::setInitObjBoundsSparse(int numberOfObj, InitObjBound** obj)
{
    if (this->optimization == NULL)
        this->optimization = new OptimizationOption();
    if (this->optimization->objectives == NULL)
        this->optimization->objectives = new ObjectiveOption();
    if (this->optimization->objectives->initialObjectiveBounds == NULL)
        this->optimization->objectives->initialObjectiveBounds = new InitObjectiveBounds();
    else
    {
        int i;
        for (i = 0; i < this->optimization->objectives->initialObjectiveBounds->numberOfObj; i++)
            delete this->optimization->objectives->initialObjectiveBounds->obj[i];
        delete[] this->optimization->objectives->initialObjectiveBounds->obj;
        this->optimization->objectives->initialObjectiveBounds->obj = NULL;
    }
    return this->optimization->objectives->initialObjectiveBounds->setObj(numberOfObj, obj);
}//setInitObjBoundsSparse

bool OSOption::setInitObjBoundsSparse(int numberOfObj, InitObjBound** obj, ENUM_COMBINE_ARRAYS disp)
{
    if (this->optimization == NULL)
        this->optimization = new OptimizationOption();
    if (this->optimization->objectives == NULL)
        this->optimization->objectives = new ObjectiveOption();
    if (this->optimization->objectives->initialObjectiveBounds == NULL)
        this->optimization->objectives->initialObjectiveBounds = new InitObjectiveBounds();
    return this->optimization->objectives->initialObjectiveBounds->setObj(numberOfObj, obj, disp);
}//setInitObjBoundsSparse

bool OSOption::setInitObjBoundsDense(int numberOfObj, double* lb, double* ub)
{
    if (this->optimization == NULL)
        this->optimization = new OptimizationOption();
    if (this->optimization->objectives == NULL)
        this->optimization->objectives = new ObjectiveOption();
    if (this->optimization->objectives->initialObjectiveBounds == NULL)
        this->optimization->objectives->initialObjectiveBounds = new InitObjectiveBounds();
    else
    {
        delete[] this->optimization->objectives->initialObjectiveBounds->obj;
        this->optimization->objectives->initialObjectiveBounds->obj = NULL;
    }
    int i;
    for (i = 0; i < numberOfObj; i++)
    {
        if (!this->optimization->objectives->initialObjectiveBounds->addObj(-1-i, lb[i], ub[i]))
            return false;
    }
    return true;
}//setInitObjBoundsDense

bool OSOption::setAnotherInitObjBound(int idx, double lb, double ub)
{
    if (this->optimization == NULL)
        this->optimization = new OptimizationOption();
    if (this->optimization->objectives == NULL)
        this->optimization->objectives = new ObjectiveOption();
    if (this->optimization->objectives->initialObjectiveBounds == NULL)
        this->optimization->objectives->initialObjectiveBounds = new InitObjectiveBounds();
    return this->optimization->objectives->initialObjectiveBounds->addObj(idx, lb, ub);
}//setAnotherInitObjBound


bool OSOption::setOtherObjectiveOptionObj(int otherOptionNumber, int objNumber,
        int idx, std::string name, std::string value, std::string constantValue, std::string weightValue)
{
    if (optimization == NULL) return false;

    if (optimization->objectives == NULL) return false;
    if (optimization->objectives->other == NULL) return false;
    if (otherOptionNumber < 0 || otherOptionNumber >= optimization->objectives->numberOfOtherObjectiveOptions) return false;
    if (optimization->objectives->other[otherOptionNumber] == NULL) return false;
    if (idx >= 0) return false;

    if (optimization->objectives->other[otherOptionNumber]->obj == NULL) return false;
    if (objNumber < 0 || objNumber >= optimization->objectives->other[otherOptionNumber]->numberOfObj) return false;
    if (optimization->objectives->other[otherOptionNumber]->obj[objNumber] == NULL) return false;

    optimization->objectives->other[otherOptionNumber]->obj[objNumber]->idx = idx;
    optimization->objectives->other[otherOptionNumber]->obj[objNumber]->name = name;
    optimization->objectives->other[otherOptionNumber]->obj[objNumber]->value = value;
    optimization->objectives->other[otherOptionNumber]->obj[objNumber]->constantValue = constantValue;
    optimization->objectives->other[otherOptionNumber]->obj[objNumber]->weightValue = weightValue;
    return true;
}//setOtherOptionObj

bool OSOption::setNumberOfOtherObjectiveOptions(int numberOfOther)
{
    if (optimization == NULL) return false;
    if (optimization->objectives == NULL)
        optimization->objectives = new ObjectiveOption();
    if (optimization->objectives->numberOfOtherObjectiveOptions < 0) return false;

    optimization->objectives->numberOfOtherObjectiveOptions = numberOfOther;

    if (numberOfOther > 0)
    {
        optimization->objectives->other = new OtherObjectiveOptionOrResult*[numberOfOther];

        for (int j=0; j < numberOfOther; j++)
            optimization->objectives->other[j] = new OtherObjectiveOptionOrResult();
    }
    return true;

}//setNumberOfOtherObjectiveOptions

bool OSOption::setOtherObjectiveOptionAttributes(int iOther, int numberOfObj,
        int numberOfEnumerations, std::string name,
        std::string value, std::string solver,
        std::string category, std::string type,
        std::string objType, std::string enumType,
        std::string description)
{
    if (optimization == NULL) return false;
    if (optimization->objectives == NULL) return false;
    if (optimization->objectives->other == NULL) return false;

    if (iOther < 0 || iOther >= optimization->objectives->numberOfOtherObjectiveOptions) return false;

    optimization->objectives->other[iOther]->numberOfObj          = numberOfObj;
    optimization->objectives->other[iOther]->numberOfEnumerations = numberOfEnumerations;
    optimization->objectives->other[iOther]->name                 = name;
    optimization->objectives->other[iOther]->value                = value;
    optimization->objectives->other[iOther]->solver               = solver;
    optimization->objectives->other[iOther]->category             = category;
    optimization->objectives->other[iOther]->type                 = type;
    optimization->objectives->other[iOther]->enumType             = enumType;
    optimization->objectives->other[iOther]->objType              = objType;
    optimization->objectives->other[iOther]->description          = description;

    if (numberOfObj > 0)
    {
        optimization->objectives->other[iOther]->obj
            = new OtherObjOptionOrResultElementString*[numberOfObj];
        for (int j=0; j<numberOfObj; j++)
            optimization->objectives->other[iOther]->obj[j] = new OtherObjOptionOrResultElementString();
    }

    if (numberOfEnumerations > 0)
    {
        optimization->objectives->other[iOther]->enumeration = new OtherOptionOrResultEnumeration*[numberOfEnumerations];
        for (int j=0; j<numberOfEnumerations; j++)
            optimization->objectives->other[iOther]->enumeration[j] = new OtherOptionOrResultEnumeration();
    }
    return true;
}//setOtherObjOptionAttributes

bool OSOption::setOtherObjectiveOptions(int numberOfOptions, OtherObjectiveOptionOrResult** other)
{
    if (this->optimization == NULL)
        this->optimization = new OptimizationOption();
    if (this->optimization->objectives == NULL)
        this->optimization->objectives = new ObjectiveOption();
    else
    {
        int i;
        for (i = 0; i < this->optimization->objectives->numberOfOtherObjectiveOptions; i++)
            delete this->optimization->objectives->other[i];
        delete[] this->optimization->objectives->other;
        this->optimization->objectives->other = NULL;
    }
    return this->optimization->objectives->setOther(numberOfOptions, other);
}//setOtherObjectiveOptions

bool OSOption::setAnOtherObjectiveOption(OtherObjectiveOptionOrResult* optionValue)
{
    if (this->optimization == NULL)
        this->optimization = new OptimizationOption();
    if (this->optimization->objectives == NULL)
        this->optimization->objectives = new ObjectiveOption();
    return this->optimization->objectives->addOther(optionValue);
}//setAnOtherObjectiveOption

bool OSOption::setInitConValues(int numberOfCon, int* idx, double* value, std::string* name)
{
    if (this->optimization == NULL)
        this->optimization = new OptimizationOption();
    if (this->optimization->constraints == NULL)
        this->optimization->constraints = new ConstraintOption();
    if (this->optimization->constraints->initialConstraintValues != NULL)
        return false;

    this->optimization->constraints->initialConstraintValues = new InitConstraintValues();

    return this->optimization->constraints->initialConstraintValues->setCon(numberOfCon, idx, value, name);
}//setInitConValues


bool OSOption::setInitConValuesSparse(int numberOfCon, InitConValue** con)
{
    if (this->optimization == NULL)
        this->optimization = new OptimizationOption();
    if (this->optimization->constraints == NULL)
        this->optimization->constraints = new ConstraintOption();
    if (this->optimization->constraints->initialConstraintValues == NULL)
        this->optimization->constraints->initialConstraintValues = new InitConstraintValues();
    else
    {
        int i;
        for (i = 0; i < this->optimization->constraints->initialConstraintValues->numberOfCon; i++)
            delete this->optimization->constraints->initialConstraintValues->con[i];
        delete[] this->optimization->constraints->initialConstraintValues->con;
        this->optimization->constraints->initialConstraintValues->con = NULL;
    }
    return this->optimization->constraints->initialConstraintValues->setCon(numberOfCon, con);
}//setInitConValuesSparse

bool OSOption::setInitConValuesSparse(int numberOfCon, InitConValue** con, ENUM_COMBINE_ARRAYS disp)
{
    if (this->optimization == NULL)
        this->optimization = new OptimizationOption();
    if (this->optimization->constraints == NULL)
        this->optimization->constraints = new ConstraintOption();
    if (this->optimization->constraints->initialConstraintValues == NULL)
        this->optimization->constraints->initialConstraintValues = new InitConstraintValues();
    return this->optimization->constraints->initialConstraintValues->setCon(numberOfCon, con, disp);
}//setInitConValuesSparse

bool OSOption::setInitConValuesDense(int numberOfCon, double *value)
{
    if (this->optimization == NULL)
        this->optimization = new OptimizationOption();
    if (this->optimization->constraints == NULL)
        this->optimization->constraints = new ConstraintOption();
    if (this->optimization->constraints->initialConstraintValues == NULL)
        this->optimization->constraints->initialConstraintValues = new InitConstraintValues();
    else
    {
        delete[] this->optimization->constraints->initialConstraintValues->con;
        this->optimization->constraints->initialConstraintValues->con = NULL;
    }
    int i;
    for (i = 0; i < numberOfCon; i++)
    {
//        if (!CoinIsnan(value[i]))
        if (!this->optimization->constraints->initialConstraintValues->addCon(i, value[i]))
            return false;
    }
    return true;
}//setInitConValuesDense

bool OSOption::setAnotherInitConValue(int idx, double value)
{
    if (this->optimization == NULL)
        this->optimization = new OptimizationOption();
    if (this->optimization->constraints == NULL)
        this->optimization->constraints = new ConstraintOption();
    if (this->optimization->constraints->initialConstraintValues == NULL)
        this->optimization->constraints->initialConstraintValues = new InitConstraintValues();
    return this->optimization->constraints->initialConstraintValues->addCon(idx, value);
}//setAnotherInitConValue

bool OSOption::setInitDualValues(int numberOfCon, int* idx, double* lbValue, double* ubValue, std::string* name)
{
    if (this->optimization == NULL)
        this->optimization = new OptimizationOption();
    if (this->optimization->constraints == NULL)
        this->optimization->constraints = new ConstraintOption();
    if (this->optimization->constraints->initialDualValues != NULL)
        return false;

    this->optimization->constraints->initialDualValues = new InitDualVariableValues();

    return this->optimization->constraints->initialDualValues->setCon(numberOfCon, idx, lbValue, ubValue, name);
}//setInitDualValues

bool OSOption::setInitDualVarValuesSparse(int numberOfCon, InitDualVarValue** con)
{
    if (this->optimization == NULL)
        this->optimization = new OptimizationOption();
    if (this->optimization->constraints == NULL)
        this->optimization->constraints = new ConstraintOption();
    if (this->optimization->constraints->initialDualValues == NULL)
        this->optimization->constraints->initialDualValues = new InitDualVariableValues();
    else
    {
        int i;
        for (i = 0; i < this->optimization->constraints->initialDualValues->numberOfCon; i++)
            delete this->optimization->constraints->initialDualValues->con[i];
        delete[] this->optimization->constraints->initialDualValues->con;
        this->optimization->constraints->initialDualValues->con = NULL;
    }
    return this->optimization->constraints->initialDualValues->setCon(numberOfCon, con);
}//setInitDualVarValuesSparse

bool OSOption::setInitDualVarValuesSparse(int numberOfCon, InitDualVarValue** con, ENUM_COMBINE_ARRAYS disp)
{
    if (this->optimization == NULL)
        this->optimization = new OptimizationOption();
    if (this->optimization->constraints == NULL)
        this->optimization->constraints = new ConstraintOption();
    if (this->optimization->constraints->initialDualValues == NULL)
        this->optimization->constraints->initialDualValues = new InitDualVariableValues();
    return this->optimization->constraints->initialDualValues->setCon(numberOfCon, con, disp);
}//setInitDualVarValuesSparse

bool OSOption::setInitDualVarValuesDense(int numberOfCon, double* lb, double* ub)
{
    if (this->optimization == NULL)
        this->optimization = new OptimizationOption();
    if (this->optimization->constraints == NULL)
        this->optimization->constraints = new ConstraintOption();
    if (this->optimization->constraints->initialDualValues == NULL)
        this->optimization->constraints->initialDualValues = new InitDualVariableValues();
    else
    {
        delete[] this->optimization->constraints->initialDualValues->con;
        this->optimization->constraints->initialDualValues->con = NULL;
    }
    int i;
    for (i = 0; i < numberOfCon; i++)
    {
        if ((lb[i] != 0.0) || (ub[i] != 0.0))
            if (!this->optimization->constraints->initialDualValues->addCon(i, lb[i], ub[i]))
                return false;
    }
    return true;
}//setInitDualVarValuesDense

bool OSOption::setAnotherInitDualVarValue(int idx, double lbValue, double ubValue)
{
    if (this->optimization == NULL)
        this->optimization = new OptimizationOption();
    if (this->optimization->constraints == NULL)
        this->optimization->constraints = new ConstraintOption();
    if (this->optimization->constraints->initialDualValues == NULL)
        this->optimization->constraints->initialDualValues = new InitDualVariableValues();
    return this->optimization->constraints->initialDualValues->addCon(idx, lbValue, ubValue);
}//setAnotherInitConValue

bool OSOption::setNumberOfOtherConstraintOptions(int numberOfOther)
{
    if (optimization == NULL) return false;
    if (optimization->constraints == NULL)
        optimization->constraints = new ConstraintOption();
    if (optimization->constraints->numberOfOtherConstraintOptions < 0) return false;

    optimization->constraints->numberOfOtherConstraintOptions = numberOfOther;

    if (numberOfOther > 0)
    {
        optimization->constraints->other = new OtherConstraintOptionOrResult*[numberOfOther];

        for (int j=0; j < numberOfOther; j++)
            optimization->constraints->other[j] = new OtherConstraintOptionOrResult();
    }

    return true;
}//setNumberOfOtherConstraintOptions

bool OSOption::setOtherConstraintOptionAttributes(int iOther, int numberOfCon,
        int numberOfEnumerations, std::string name,
        std::string value, std::string solver,
        std::string category, std::string type,
        std::string conType, std::string enumType,
        std::string description)
{
    if (optimization == NULL) return false;
    if (optimization->constraints == NULL) return false;
    if (optimization->constraints->other == NULL) return false;
    if (iOther < 0 || iOther >= optimization->constraints->numberOfOtherConstraintOptions) return false;

    optimization->constraints->other[iOther]->numberOfCon          = numberOfCon;
    optimization->constraints->other[iOther]->numberOfEnumerations = numberOfEnumerations;
    optimization->constraints->other[iOther]->name                 = name;
    optimization->constraints->other[iOther]->value                = value;
    optimization->constraints->other[iOther]->solver               = solver;
    optimization->constraints->other[iOther]->category             = category;
    optimization->constraints->other[iOther]->type                 = type;
    optimization->constraints->other[iOther]->enumType             = enumType;
    optimization->constraints->other[iOther]->conType              = conType;
    optimization->constraints->other[iOther]->description          = description;

    if (numberOfCon > 0)
    {
        optimization->constraints->other[iOther]->con = new OtherOptionOrResultElementString*[numberOfCon];
        for (int j=0; j<numberOfCon; j++)
            optimization->constraints->other[iOther]->con[j] = new OtherOptionOrResultElementString();
    }

    if (numberOfEnumerations > 0)
    {
        optimization->constraints->other[iOther]->enumeration = new OtherOptionOrResultEnumeration*[numberOfEnumerations];
        for (int j=0; j<numberOfEnumerations; j++)
            optimization->constraints->other[iOther]->enumeration[j] = new OtherOptionOrResultEnumeration();
    }
    return true;
}//setOtherConOptionAttributes


bool OSOption::setOtherConstraintOptionCon(int otherOptionNumber, int conNumber,
        int idx, std::string name, std::string value, std::string lbValue, std::string ubValue)
{
    if (optimization == NULL) return false;

    if (optimization->constraints == NULL) return false;
    if (optimization->constraints->other == NULL) return false;
    if (otherOptionNumber < 0 || otherOptionNumber >= optimization->constraints->numberOfOtherConstraintOptions) return false;
    if (optimization->constraints->other[otherOptionNumber] == NULL) return false;
    if (idx < 0) return false;

    if (optimization->constraints->other[otherOptionNumber]->con == NULL) return false;
    if (conNumber < 0 || conNumber >= optimization->constraints->other[otherOptionNumber]->numberOfCon) return false;
    if (optimization->constraints->other[otherOptionNumber]->con[conNumber] == NULL) return false;

    optimization->constraints->other[otherOptionNumber]->con[conNumber]->idx = idx;
    optimization->constraints->other[otherOptionNumber]->con[conNumber]->name = name;
    optimization->constraints->other[otherOptionNumber]->con[conNumber]->value = value;
    optimization->constraints->other[otherOptionNumber]->con[conNumber]->lbValue = lbValue;
    optimization->constraints->other[otherOptionNumber]->con[conNumber]->ubValue = ubValue;
    return true;
}//setOtherOptionCon



bool OSOption::setOtherConstraintOptions(int numberOfOptions, OtherConstraintOptionOrResult** other)
{
    if (this->optimization == NULL)
        this->optimization = new OptimizationOption();
    if (this->optimization->constraints == NULL)
        this->optimization->constraints = new ConstraintOption();
    else
    {
        int i;
        for (i = 0; i < this->optimization->constraints->numberOfOtherConstraintOptions; i++)
            delete this->optimization->constraints->other[i];
        delete[] this->optimization->constraints->other;
        this->optimization->constraints->other = NULL;
    }
    return this->optimization->constraints->setOther(numberOfOptions, other);
}//setOtherConstraintOptions

bool OSOption::setAnOtherConstraintOption(OtherConstraintOptionOrResult* optionValue)
{
    if (this->optimization == NULL)
        this->optimization = new OptimizationOption();
    if (this->optimization->constraints == NULL)
        this->optimization->constraints = new ConstraintOption();
    return this->optimization->constraints->addOther(optionValue);
}//setAnOtherConstraintOption

bool OSOption::setNumberOfSolverOptions(int numberOfOptions)
{
    if (optimization == NULL) return false;
    if (optimization->solverOptions != NULL) return false;

    optimization->solverOptions = new SolverOptions();
    optimization->solverOptions->numberOfSolverOptions = numberOfOptions;
    optimization->solverOptions->solverOption = new SolverOptionOrResult*[numberOfOptions];

    for (int j=0; j < numberOfOptions; j++)
        optimization->solverOptions->solverOption[j] = new SolverOptionOrResult();
    return true;
}//setNumberOfSolverOptions

bool OSOption::setSolverOptionContent(int iOption, int numberOfMatrices, int numberOfItems,
                                      std::string name, std::string value,
                                      std::string solver, std::string category,
                                      std::string type, std::string description,
                                      OSMatrix **matrix, std::string *itemList)
{
    if (optimization == NULL) return false;
    if (optimization->solverOptions == NULL) return false;
    if (optimization->solverOptions->solverOption == NULL) return false;

    if (iOption < 0 || iOption >= optimization->solverOptions->numberOfSolverOptions) return false;

    optimization->solverOptions->solverOption[iOption]->numberOfMatrices = numberOfMatrices;
    optimization->solverOptions->solverOption[iOption]->numberOfItems    = numberOfItems;
    optimization->solverOptions->solverOption[iOption]->name             = name;
    optimization->solverOptions->solverOption[iOption]->value            = value;
    optimization->solverOptions->solverOption[iOption]->solver           = solver;
    optimization->solverOptions->solverOption[iOption]->category         = category;
    optimization->solverOptions->solverOption[iOption]->type             = type;
    optimization->solverOptions->solverOption[iOption]->description      = description;

    if (numberOfMatrices > 0)
        optimization->solverOptions->solverOption[iOption]->matrix = matrix;

    if (numberOfItems > 0)
    {
        optimization->solverOptions->solverOption[iOption]->item = new std::string[numberOfItems];
        for (int j=0; j<numberOfItems; j++)
            optimization->solverOptions->solverOption[iOption]->item[j] = itemList[j];
    }

    return true;
}//setSolverOptionContent

bool OSOption::setSolverOptions(int numberOfSolverOptions, SolverOptionOrResult** solverOption)
{
    if (this->optimization == NULL)
        this->optimization = new OptimizationOption();
    if (this->optimization->solverOptions == NULL)
        this->optimization->solverOptions = new SolverOptions();
    else
    {
        int i;
        for (i = 0; i < this->optimization->solverOptions->numberOfSolverOptions; i++)
            delete this->optimization->solverOptions->solverOption[i];
        delete[] this->optimization->solverOptions->solverOption;
        this->optimization->solverOptions->solverOption = NULL;
    }
    return this->optimization->solverOptions->setSolverOptions(numberOfSolverOptions, solverOption);
}//setSolverOptions

bool OSOption::setAnotherSolverOption(std::string name, std::string value, std::string solver,
                                      std::string category, std::string type, std::string description)
{
    if (this->optimization == NULL)
        this->optimization = new OptimizationOption();
    if (this->optimization->solverOptions == NULL)
        this->optimization->solverOptions = new SolverOptions();
    return this->optimization->solverOptions->addSolverOption(name, value, solver, category, type, description);
}//setAnotherSolverOption


bool OSOption::setOptionStr(std::string optionName, std::string optionValue)
{
    if (optionName == "serviceURI")
        return this->setServiceURI(optionValue);

    if (optionName == "serviceName")
        return this->setServiceName(optionValue);

    if (optionName == "instanceName")
        return this->setInstanceName(optionValue);

    if (optionName == "instanceLocation")
        return this->setInstanceLocation(optionValue);

    if (optionName == "locationType")
        return this->setInstanceLocationType(optionValue);

    if (optionName == "jobID")
        return this->setJobID(optionValue);

    if (optionName == "solverName")
        return this->setSolverToInvoke(optionValue);

    if (optionName == "solverToInvoke")
        return this->setSolverToInvoke(optionValue);

    if (optionName == "license")
        return this->setLicense(optionValue);

    if (optionName == "userName")
        return this->setUserName(optionValue);

    if (optionName == "password")
        return this->setPassword(optionValue);

    if (optionName == "contact")
        return this->setContact(optionValue);

    if (optionName == "transportType")
        return this->setContactTransportType(optionValue);

    if (optionName == "minDiskSpaceUnit")
        return this->setMinDiskSpaceUnit(optionValue);

    if (optionName == "minMemoryUnit")
        return this->setMinMemoryUnit(optionValue);

    if (optionName == "minCPUSpeedUnit")
        return this->setMinCPUSpeedUnit(optionValue);

    if (optionName == "serviceType")
        return this->setServiceType(optionValue);

    if (optionName == "maxTimeUnit")
        return this->setMaxTimeUnit(optionValue);

    if (optionName == "requestedStartTime")
        return this->setRequestedStartTime(optionValue);

    return false;
}//setOptionStr


bool OSOption::setOptionInt(std::string optionName, int optionValue)
{
    if (optionName == "minCPUNumber")
        return this->setMinCPUNumber(optionValue);

    return false;
}//setOptionInt


bool OSOption::setOptionDbl(std::string optionName, double value)
{
    if (optionName == "minDiskSpaceValue")
        return this->setMinDiskSpace(value);

    if (optionName == "minMemoryValue")
        return this->setMinMemorySize(value);

    if (optionName == "minCPUSpeedValue")

        return this->setMinCPUSpeed(value);

    if (optionName == "maxTime")
        return this->setMaxTime(value);

    return false;
}//setOptionDbl

/***************************************************
 * methods to test whether two OSOption objects
 * or their components are equal to each other
 ***************************************************/
bool OSOption::IsEqual(OSOption *that)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_debug, "Start comparing in OSOption");
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
        if (this->optionHeader == NULL)
        {
            if (that->optionHeader != NULL)
                return false;
        }
        else
            if (!this->optionHeader->IsEqual(that->optionHeader))
                return false;

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
}//OSOption::IsEqual


bool GeneralOption::IsEqual(GeneralOption *that)
{
    std::ostringstream outStr;

#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_debug, "Start comparing in GeneralOption");
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
        bool same;
        same =  (this->serviceURI     == that->serviceURI);
        same = ((this->serviceName    == that->serviceName )   && same);
        same = ((this->instanceName   == that->instanceName )  && same);
        same = ((this->jobID          == that->jobID )         && same);
        same = ((this->solverToInvoke == that->solverToInvoke) && same);
        same = ((this->license        == that->license )       && same);
        same = ((this->userName       == that->userName )      && same);
        same = ((this->password       == that->password )      && same);
        if (!same)
        {
#ifndef NDEBUG
            outStr.str("");
            outStr.clear();
            outStr << "serviceURI:    " << this->serviceURI     << " vs. " << that->serviceURI     << endl;
            outStr << "serviceName:   " << this->serviceName    << " vs. " << that->serviceName    << endl;
            outStr << "instanceName:  " << this->instanceName   << " vs. " << that->instanceName   << endl;
            outStr << "jobID:         " << this->jobID          << " vs. " << that->jobID          << endl;
            outStr << "solverToInvoke:" << this->solverToInvoke << " vs. " << that->solverToInvoke << endl;
            outStr << "license:       " << this->license        << " vs. " << that->license        << endl;
            outStr << "userName:      " << this->userName       << " vs. " << that->userName       << endl;
            outStr << "password:      " << this->password       << " vs. " << that->password       << endl;
            osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_debug, outStr.str());
#endif
            return false;
        }

        if (this->instanceLocation == NULL)
        {
            if (that->instanceLocation != NULL)
                return false;
        }
        else
            if (!this->instanceLocation->IsEqual(that->instanceLocation))
                return false;

        if (this->contact == NULL)
        {
            if (that->contact != NULL)
                return false;
        }
        else
            if (!this->contact->IsEqual(that->contact))
                return false;

        if (this->otherOptions == NULL)
        {
            if (that->otherOptions != NULL)
                return false;
        }
        else
            if (!this->otherOptions->IsEqual(that->otherOptions))
                return false;
    }

    return true;
}//GeneralOption::IsEqual


bool SystemOption::IsEqual(SystemOption *that)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_debug, "Start comparing in SystemOption");
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
        if (this->minDiskSpace == NULL)
        {
            if (that->minDiskSpace != NULL)
                return false;
        }
        else
           if (!this->minDiskSpace->IsEqual(that->minDiskSpace))
                return false;

        if (this->minMemorySize == NULL)
        {
            if (that->minMemorySize != NULL)
                return false;
        }
        else
            if (!this->minMemorySize->IsEqual(that->minMemorySize))
                return false;

        if (this->minCPUSpeed == NULL)
        {
            if (that->minCPUSpeed != NULL)
                return false;
        }
        else
            if (!this->minCPUSpeed->IsEqual(that->minCPUSpeed))
                return false;

        if (this->minCPUNumber == NULL)
        {
            if (that->minCPUNumber != NULL)
                return false;
        }
        else
            if (!this->minCPUNumber->IsEqual(that->minCPUNumber))
                return false;

        if (this->otherOptions == NULL)
        {
            if (that->otherOptions != NULL)
                return false;
        }
        else
            if (!this->otherOptions->IsEqual(that->otherOptions))
                return false;
    }

    return true;
}//SystemOption::IsEqual


bool ServiceOption::IsEqual(ServiceOption *that)
{
    std::ostringstream outStr;

#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_debug, "Start comparing in ServiceOption");
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
        if (this->type != that->type)
        {
#ifndef NDEBUG
            outStr.str("");
            outStr.clear();
            outStr << "service type: " << this->type << " vs. " << that->type << endl;
            osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_debug, outStr.str());
#endif
            return false;
        }

        if (this->otherOptions == NULL)
        {
            if (that->otherOptions != NULL)
                return false;
        }
        else
            if (!this->otherOptions->IsEqual(that->otherOptions))
                return false;
    }

    return true;
}//ServiceOption::IsEqual


bool JobOption::IsEqual(JobOption *that)
{
    std::ostringstream outStr;

#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_debug, "Start comparing in JobOption");
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
        if (this->requestedStartTime != that->requestedStartTime)
        {
#ifndef NDEBUG
            outStr.str("");
            outStr.clear();
            outStr << "requestedStartTime: " << this->requestedStartTime << " vs. " << that->requestedStartTime << endl;
            osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_debug, outStr.str());
#endif
            return false;
        }

        if (this->maxTime == NULL)
        {
            if (that->maxTime != NULL)
                return false;
        }
        else
            if (!this->maxTime->IsEqual(that->maxTime))
                return false;

        if (this->dependencies == NULL)
        {
            if (that->dependencies != NULL)
                return false;
        }
        else
            if (!this->dependencies->IsEqual(that->dependencies))
                return false;

        if (this->requiredDirectories == NULL)
        {
            if (that->requiredDirectories != NULL)
                return false;
        }
        else
            if (!this->requiredDirectories->IsEqual(that->requiredDirectories))
                return false;

        if (this->requiredFiles == NULL)
        {
            if (that->requiredFiles != NULL)
                return false;
        }
        else
            if (!this->requiredFiles->IsEqual(that->requiredFiles))
                return false;

        if (this->directoriesToMake == NULL)
        {
            if (that->directoriesToMake != NULL)
                return false;
        }
        else
            if (!this->directoriesToMake->IsEqual(that->directoriesToMake))
                return false;

        if (this->filesToMake == NULL)
        {
            if (that->filesToMake != NULL)
                return false;
        }
        else
            if (!this->filesToMake->IsEqual(that->filesToMake))
                return false;

        if (this->inputDirectoriesToMove == NULL)
        {
            if (that->inputDirectoriesToMove != NULL)
                return false;
        }
        else
            if (!this->inputDirectoriesToMove->IsEqual(that->inputDirectoriesToMove))
                return false;

        if (this->inputFilesToMove == NULL)
        {
            if (that->inputFilesToMove != NULL)
                return false;
        }
        else
            if (!this->inputFilesToMove->IsEqual(that->inputFilesToMove))
                return false;

        if (this->outputFilesToMove == NULL)
        {
            if (that->outputFilesToMove != NULL)
                return false;
        }
        else
            if (!this->outputFilesToMove->IsEqual(that->outputFilesToMove))
                return false;

        if (this->outputDirectoriesToMove == NULL)
        {
            if (that->outputDirectoriesToMove != NULL)
                return false;
        }
        else
            if (!this->outputDirectoriesToMove->IsEqual(that->outputDirectoriesToMove))
                return false;

        if (this->filesToDelete == NULL)
        {
            if (that->filesToDelete != NULL)
                return false;
        }
        else
            if (!this->filesToDelete->IsEqual(that->filesToDelete))
                return false;

        if (this->directoriesToDelete == NULL)
        {
            if (that->directoriesToDelete != NULL)
                return false;
        }
        else
            if (!this->directoriesToDelete->IsEqual(that->directoriesToDelete))
                return false;

        if (this->processesToKill == NULL)
        {
            if (that->processesToKill != NULL)
                return false;
        }
        else
            if (!this->processesToKill->IsEqual(that->processesToKill))
                return false;

        if (this->otherOptions == NULL)
        {
            if (that->otherOptions != NULL)
                return false;
        }
        else
            if (!this->otherOptions->IsEqual(that->otherOptions))
                return false;
    }

    return true;
}//JobOption::IsEqual

bool OptimizationOption::IsEqual(OptimizationOption *that)
{
    std::ostringstream outStr;

#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_debug, "Start comparing in OptimizationOption");
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
        if ((this->numberOfVariables != that->numberOfVariables) &&
            (this->numberOfVariables *  that->numberOfVariables) != 0)
        {
#ifndef NDEBUG
            outStr.str("");
            outStr.clear();
            outStr << "numberOfVariables: "
                   << this->numberOfVariables << " vs. " << that->numberOfVariables << endl;
            osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_debug, outStr.str());
#endif
            return false;
        }
        if ((this->numberOfObjectives != that->numberOfObjectives) &&
            (this->numberOfObjectives *  that->numberOfObjectives) != 0)
        {
#ifndef NDEBUG
            outStr.str("");
            outStr.clear();
            outStr << "numberOfObjectives: "
                   << this->numberOfObjectives << " vs. " << that->numberOfObjectives << endl;
            osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_debug, outStr.str());
#endif
            return false;
        }

        if ((this->numberOfConstraints != that->numberOfConstraints) &&
            (this->numberOfConstraints *  that->numberOfConstraints) != 0)
        {
#ifndef NDEBUG
            outStr.str("");
            outStr.clear();
            outStr << "numberOfConstraints: "
                   << this->numberOfConstraints << " vs. " << that->numberOfConstraints << endl;
            osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_debug, outStr.str());
#endif
            return false;
        }

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

        if (this->solverOptions == NULL)
        {
            if (that->solverOptions != NULL)
                return false;
        }
        else
            if (!this->solverOptions->IsEqual(that->solverOptions))
                return false;
    }

    return true;
}//OptimizationOption::IsEqual

bool InstanceLocationOption::IsEqual(InstanceLocationOption *that)
{
    std::ostringstream outStr;

#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_debug, "Start comparing in InstanceLocation");
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
        if ((this->locationType != that->locationType) || (this->value != that->value))
        {
#ifndef NDEBUG
            outStr.str("");
            outStr.clear();
            outStr << "location type: " << this->locationType << " vs. " << that->locationType << endl;
            outStr << "value: "         << this->value        << " vs. " << that->value        << endl;
            osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_debug, outStr.str());
#endif
            return false;
        }
    }

    return true;
}//InstanceLocationOption::IsEqual

bool ContactOption::IsEqual(ContactOption *that)
{
    std::ostringstream outStr;

#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_debug, "Start comparing in ContactOption");
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
        if ((this->transportType != that->transportType) || (this->value != that->value))
        {
#ifndef NDEBUG
            outStr.str("");
            outStr.clear();
            outStr << "transport type: " << this->transportType << " vs. " << that->transportType << endl;
            outStr << "value: "          << this->value         << " vs. " << that->value         << endl;
            osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_debug, outStr.str());
#endif
            return false;
        }
    }

    return true;
}//ContactOption::IsEqual

bool OtherOptions::IsEqual(OtherOptions *that)
{
    std::ostringstream outStr;

#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_debug, "Start comparing in OtherOptions");
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
        if (this->numberOfOtherOptions  != that->numberOfOtherOptions)
        {
#ifndef NDEBUG
            outStr.str("");
            outStr.clear();
            outStr << "numberOfOtherOptions: " << this->numberOfOtherOptions << " vs. " << that->numberOfOtherOptions << endl;
            osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_debug, outStr.str());
#endif
            return false;
        }

        for (unsigned int i = 0; i < this->numberOfOtherOptions; i++)
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
}//OtherOptions::IsEqual


bool MinDiskSpace::IsEqual(MinDiskSpace *that)
{
    std::ostringstream outStr;

#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_debug, "Start comparing in MinDiskSpace");
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
        if ((this->unit        != that->unit)    ||
            !OSIsEqual(this->value, that->value) ||
            (this->description != that->description) )
        {
#ifndef NDEBUG
            outStr.str("");
            outStr.clear();
            outStr << "unit:        " << this->unit        << " vs. " << that->unit        << endl;
            outStr << "value:       " << this->value       << " vs. " << that->value       << endl;
            outStr << "description: " << this->description << " vs. " << that->description << endl;
            osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_debug, outStr.str());
#endif
            return false;
        }
    }

   return true;
}//MinDiskSpace::IsEqual

bool MinMemorySize::IsEqual(MinMemorySize *that)
{
    std::ostringstream outStr;

#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_debug, "Start comparing in MinMemorySize");
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
        if ((this->unit        != that->unit)  ||
             !OSIsEqual(this->value, that->value) ||
             (this->description != that->description) )
        {
#ifndef NDEBUG
            outStr.str("");
            outStr.clear();
            outStr << "unit: "  << this->unit  << " vs. " << that->unit  << endl;
            outStr << "value: " << this->value << " vs. " << that->value << endl;
            osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_debug, outStr.str());
#endif
            return false;
        }
    }

    return true;
}//MinMemorySize::IsEqual

bool MinCPUSpeed::IsEqual(MinCPUSpeed *that)
{
    std::ostringstream outStr;

#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_debug, "Start comparing in MinCPUSpeed");
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
        if ((this->unit        != that->unit)  ||
             !OSIsEqual(this->value, that->value) ||
             (this->description != that->description) )
        {
#ifndef NDEBUG
            outStr.str("");
            outStr.clear();
            outStr << "unit: "  << this->unit  << " vs. " << that->unit  << endl;
            outStr << "value: " << this->value << " vs. " << that->value << endl;
            osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_debug, outStr.str());
#endif
            return false;
        }
    }

    return true;
}//MinCPUSpeed::IsEqual

bool MinCPUNumber::IsEqual(MinCPUNumber *that)
{
    std::ostringstream outStr;

#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_debug, "Start comparing in MinCPUNumber");
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
        if ((this->description != that->description)  ||
            (this->value != that->value) )
        {
#ifndef NDEBUG
            outStr.str("");
            outStr.clear();
            outStr << "description: " << this->description  << " vs. " << that->description  << endl;
            outStr << "value:       " << this->value << " vs. " << that->value << endl;
            osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_debug, outStr.str());
#endif
            return false;
        }
    }

    return true;
}//MinCPUNumber::IsEqual

bool JobDependencies::IsEqual(JobDependencies *that)
{
    std::ostringstream outStr;

#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_debug, "Start comparing in JobDependencies");
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
        if (this->numberOfJobIDs != that->numberOfJobIDs)
        {
#ifndef NDEBUG
            outStr.str("");
            outStr.clear();
            outStr << "numberOfJobIDs: " << this->numberOfJobIDs << " vs. " << that->numberOfJobIDs << endl;
            osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_debug, outStr.str());
#endif
            return false;
        }

        for (unsigned int i = 0; i < this->numberOfJobIDs; i++)
        {
            if (this->jobID[i] != that->jobID[i])
            {
#ifndef NDEBUG
                outStr.str("");
                outStr.clear();
                outStr << "jobID[" << i << "]: " << this->jobID[i] << " vs. " << that->jobID[i] << endl;
                osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_debug, outStr.str());
#endif
                return false;
            }
        }
    }

    return true;
}//JobDependencies::IsEqual

bool DirectoriesAndFiles::IsEqual(DirectoriesAndFiles *that)
{
    std::ostringstream outStr;

#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_debug, "Start comparing in DirectoriesAndFiles");
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
        if (this->numberOfPaths != that->numberOfPaths)
        {
#ifndef NDEBUG
            outStr.str("");
            outStr.clear();
            outStr << "numberOfPaths: " << this->numberOfPaths << " vs. " << that->numberOfPaths << endl;
            osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_debug, outStr.str());
#endif
            return false;
        }

        for (unsigned int i = 0; i < numberOfPaths; i++)
            if (this->path[i] != that->path[i])
            {
#ifndef NDEBUG
                outStr.str("");
                outStr.clear();
                outStr << "path[" << i << "]: \'" << this->path[i] << "\' vs. \'" << that->path[i] << "\'" << endl;
                osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_debug, outStr.str());
#endif
                return false;
            }
    }

    return true;
}//DirectoriesAndFiles::IsEqual

bool PathPairs::IsEqual(PathPairs *that)
{
    std::ostringstream outStr;

#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_debug, "Start comparing in PathPairs");
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
        if (this->numberOfPathPairs != that->numberOfPathPairs)
        {
#ifndef NDEBUG
            outStr.str("");
            outStr.clear();
            outStr << "numberOfPathPairs: " << this->numberOfPathPairs << " vs. " << that->numberOfPathPairs << endl;
            osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_debug, outStr.str());
#endif
            return false;
        }

        for (unsigned int i = 0; i < this->numberOfPathPairs; i++)
        {
            if (this->pathPair[i] == NULL)
            {
                if (that->pathPair[i] != NULL)
                    return false;
            }
            else
                if (!this->pathPair[i]->IsEqual(that->pathPair[i]))
                    return false;
        }
    }

    return true;
}//PathPairs::IsEqual


bool PathPair::IsEqual(PathPair *that)
{
    std::ostringstream outStr;

#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_debug, "Start comparing in PathPair");
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
        if ((this->from != that->from) || (this->to != that->to) || (this->makeCopy != that->makeCopy))
        {
#ifndef NDEBUG
            outStr.str("");
            outStr.clear();
            outStr << "from: "     << this->from     << " vs. " << that->from     << endl;
            outStr << "to: "       << this->to       << " vs. " << that->to       << endl;
            outStr << "makeCopy: " << this->makeCopy << " vs. " << that->makeCopy << endl;
            osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_debug, outStr.str());
#endif
            return false;
        }
    }

    return true;
}//PathPair::IsEqual

bool Processes::IsEqual(Processes *that)
{
    std::ostringstream outStr;

#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_debug, "Start comparing in Processes");
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
        if (this->numberOfProcesses != that->numberOfProcesses)
        {
#ifndef NDEBUG
            outStr.str("");
            outStr.clear();
            outStr << "numberOfProcesses: " << this->numberOfProcesses << " vs. " << that->numberOfProcesses << endl;
            osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_debug, outStr.str());
#endif
            return false;
        }

        for (unsigned int i = 0; i < this->numberOfProcesses; i++)
        {
            if (this->process[i] != that->process[i])
            {
#ifndef NDEBUG
                outStr.str("");
                outStr.clear();
                outStr << "process[" << i << "]: " << this->process[i] << " vs. " << that->process[i] << endl;
                osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_debug, outStr.str());
#endif
                return false;
            }
        }
    }

    return true;
}//Processes::IsEqual


bool VariableOption::IsEqual(VariableOption *that)
{
    std::ostringstream outStr;

#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_debug, "Start comparing in VariableOption");
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

        if (this->initialVariableValues == NULL)
        {
            if (that->initialVariableValues != NULL)
                return false;
        }
        else
            if (!this->initialVariableValues->IsEqual(that->initialVariableValues))
                return false;

        if (this->initialVariableValuesString == NULL)
        {
            if (that->initialVariableValuesString != NULL)
                return false;
        }
        else
            if (!this->initialVariableValuesString->IsEqual(that->initialVariableValuesString))
                return false;

        if (this->initialBasisStatus == NULL)
        {
            if (that->initialBasisStatus != NULL)
                return false;
        }
        else
            if (!this->initialBasisStatus->IsEqual(that->initialBasisStatus))
                return false;

        if (this->integerVariableBranchingWeights == NULL)
        {
            if (that->integerVariableBranchingWeights != NULL)
                return false;
        }
        else
            if (!this->integerVariableBranchingWeights->IsEqual(that->integerVariableBranchingWeights))
                return false;

        if (this->sosVariableBranchingWeights == NULL)
        {
            if (that->sosVariableBranchingWeights != NULL)
                return false;
        }
        else
            if (!this->sosVariableBranchingWeights->IsEqual(that->sosVariableBranchingWeights))
                return false;

        if (this->numberOfOtherVariableOptions != that->numberOfOtherVariableOptions)
        {
#ifndef NDEBUG
            outStr.str("");
            outStr.clear();
            outStr << "numberOfOtherVariableOptions: " << this->numberOfOtherVariableOptions 
                   << " vs. " << that->numberOfOtherVariableOptions << endl;
            osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_debug, outStr.str());
#endif
            return false;
        }


        for (unsigned int i = 0; i < this->numberOfOtherVariableOptions; i++)
        {
            if (this->other[i] == NULL)
            {
                if (that->other[i] != NULL)
                    return false;
            }
            else
                if (!this->other[i]->IsEqual(that->other[i]))
                {
#ifndef NDEBUG
                    outStr.str("");
                    outStr.clear();
                    outStr << "other[" << i << "]: " << this->other[i] << " vs. " << that->other[i] << endl;
                    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_debug, outStr.str());
#endif
                    return false;
                }
        }
    }

    return true;
}//VariableOption::IsEqual

bool InitVariableValues::IsEqual(InitVariableValues *that)
{
    std::ostringstream outStr;

#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_debug, "Start comparing in InitVariableValues");
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
            outStr << "numberOfVar: " << this->numberOfVar << " vs. " << that->numberOfVar << endl;
            osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_debug, outStr.str());
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
}//InitVariableValues::IsEqual

bool InitVarValue::IsEqual(InitVarValue *that)
{
    std::ostringstream outStr;

#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_debug, "Start comparing in InitVarValue");
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
        if ((this->idx != that->idx) || this->name != that->name 
                                     || !OSIsEqual(this->value, that->value))
        {
#ifndef NDEBUG
            outStr.str("");
            outStr.clear();
            outStr << "idx: "   << this->idx   << " vs. " << that->idx   << endl;
            outStr << "value: " << this->value << " vs. " << that->value << endl;
            osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_debug, outStr.str());
#endif
            return false;
        }
    }

    return true;
}//InitVarValue::IsEqual


bool InitVariableValuesString::IsEqual(InitVariableValuesString *that)
{
    std::ostringstream outStr;

#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_debug, "Start comparing in InitVariableValuesString");
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
            outStr << "numberOfVar: " << this->numberOfVar << " vs. " << that->numberOfVar << endl;
            osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_debug, outStr.str());
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
}//InitVariableValuesString::IsEqual

bool InitVarValueString::IsEqual(InitVarValueString *that)
{
    std::ostringstream outStr;

#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_debug, "Start comparing in InitVarValueString");
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
        if ((this->idx != that->idx) || this->name != that->name || (this->value != that->value))
        {
#ifndef NDEBUG
            outStr.str("");
            outStr.clear();
            outStr << "idx: "   << this->idx   << " vs. " << that->idx   << endl;
            outStr << "value: " << this->value << " vs. " << that->value << endl;
            osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_debug, outStr.str());
#endif
            return false;
        }
    }

    return true;
}//InitVarValueString::IsEqual

bool InitialBasisStatus::IsEqual(InitialBasisStatus *that)
{
    std::ostringstream outStr;

#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_debug, "Start comparing in InitialBasisStatus");
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
            outStr << "numberOfVar: " << this->numberOfVar << " vs. " << that->numberOfVar << endl;
            osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_debug, outStr.str());
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
}//InitialBasisStatus::IsEqual

bool InitBasStatus::IsEqual(InitBasStatus *that)
{
    std::ostringstream outStr;

#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_debug, "Start comparing in InitBasStatus");
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
        if ((this->idx != that->idx) || (this->value != that->value) ||
            (this->value != "unknown" && that->value != "") ||
            (that->value != "unknown" && this->value != "") )
        {
#ifndef NDEBUG
            outStr.str("");
            outStr.clear();
            outStr << "idx: "   << this->idx   << " vs. " << that->idx   << endl;
            outStr << "value: " << this->value << " vs. " << that->value << endl;
            osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_debug, outStr.str());
#endif
            return false;
        }
    }

    return true;
}//InitBasStatus::IsEqual


bool IntegerVariableBranchingWeights::IsEqual(IntegerVariableBranchingWeights *that)
{
    std::ostringstream outStr;

#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_debug, "Start comparing in IntegerVariableBranchingWeights");
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
            outStr << "numberOfVar: " << this->numberOfVar << " vs. " << that->numberOfVar << endl;
            osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_debug, outStr.str());
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
}//IntegerVariableBranchingWeights::IsEqual

bool SOSVariableBranchingWeights::IsEqual(SOSVariableBranchingWeights *that)
{
    std::ostringstream outStr;

#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_debug, "Start comparing in SOSVariableBranchingWeights");
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
        if (this->numberOfSOS != that->numberOfSOS)
        {
#ifndef NDEBUG
            outStr.str("");
            outStr.clear();
            outStr << "numberOfSOS: " << this->numberOfSOS << " vs. " << that->numberOfSOS << endl;
            osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_debug, outStr.str());
#endif
            return false;
        }

        for (unsigned int i = 0; i < this->numberOfSOS; i++)
        {
            if (this->sos[i] == NULL)
            {
                if (that->sos[i] != NULL)
                    return false;
            }
            else
                if (!this->sos[i]->IsEqual(that->sos[i]))
                    return false;
        }
    }

    return true;
}//SOSVariableBranchingWeights::IsEqual


bool SOSWeights::IsEqual(SOSWeights *that)
{
    std::ostringstream outStr;

#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_debug, "Start comparing in SOSWeights");
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
        if ((this->sosIdx != that->sosIdx) ||
            !OSIsEqual(this->groupWeight, that->groupWeight))
        {
#ifndef NDEBUG
            outStr.str("");
            outStr.clear();
            outStr << "sosIdx: "      << this->sosIdx      << " vs. " << that->sosIdx      << endl;
            outStr << "groupWeight: " << this->groupWeight << " vs. " << that->groupWeight << endl;
            osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_debug, outStr.str());
#endif
            return false;
        }

        if (this->numberOfVar != that->numberOfVar)
        {
#ifndef NDEBUG
            outStr.str("");
            outStr.clear();
            outStr << "numberOfVar: " << this->numberOfVar << " vs. " << that->numberOfVar << endl;
            osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_debug, outStr.str());
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
}//SOSWeights::IsEqual


bool BranchingWeight::IsEqual(BranchingWeight *that)
{
    std::ostringstream outStr;

#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_debug, "Start comparing in BranchingWeight");
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
        if ((this->idx != that->idx) || this->name != that->name || !OSIsEqual(this->value, that->value))
        {
#ifndef NDEBUG
            outStr.str("");
            outStr.clear();
            outStr << "idx: "   << this->idx   <<  " vs. "  << that->idx   << endl;
            outStr << "value: " << this->value <<  " vs. "  << that->value << endl;
            outStr << "name: -" << this->name  << "- vs. -" << that->name  << "-" << endl;
            osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_debug, outStr.str());
#endif
            return false;
        }
    }

    return true;
}//BranchingWeight::IsEqual

#if 0
bool OtherVariableOption::IsEqual(OtherVariableOption *that)
{
    std::ostringstream outStr;

#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_debug, "Start comparing in OtherVariableOption");
#endif
    if (this == NULL)
    {
        if (that == NULL)
            return true;
        else
        {
#ifndef NDEBUG
            osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_debug, "First object is NULL, second is not");
#endif
            return false;
        }
    }
    else
    {
        if (that == NULL)
        {
#ifndef NDEBUG
            osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_debug, "Second object is NULL, first is not");
#endif
            return false;
        }
        else
        {
            if ((this->name        != that->name)     ||
                    (this->value       != that->value)    ||
                    (this->solver      != that->solver)   ||
                    (this->category    != that->category) ||
                    (this->type        != that->type)     ||
                    (this->description != that->description))
            {
#ifndef NDEBUG
                outStr.str("");
                outStr.clear();
                outStr << "name: "        << this->name        << " vs. " << that->name        << endl;
                outStr << "value: "       << this->value       << " vs. " << that->value       << endl;
                outStr << "solver: "      << this->solver      << " vs. " << that->solver      << endl;
                outStr << "category: "    << this->category    << " vs. " << that->category    << endl;
                outStr << "type: "        << this->type        << " vs. " << that->type        << endl;
                outStr << "description: " << this->description << " vs. " << that->description << endl;
                osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_debug, outStr.str());
#endif
                return false;
            }

            if (this->numberOfVar != that->numberOfVar)
            {
#ifndef NDEBUG
                outStr.str("");
                outStr.clear();
                outStr << "numberOfVar: " << this->numberOfVar << " vs. " << that->numberOfVar << endl;
                osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_debug, outStr.str());
#endif
                return false;
            }
            int i;
            for (i = 0; i < numberOfVar; i++)
                if (!this->var[i]->IsEqual(that->var[i]))
                    return false;

            if (this->numberOfEnumerations != that->numberOfEnumerations)
            {
#ifndef NDEBUG
                outStr.str("");
                outStr.clear();
                outStr << "numberOfEnumerations: " << this->numberOfEnumerations << " vs. " << that->numberOfEnumerations << endl;
                osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_debug, outStr.str());
#endif
                return false;
            }
            for (i = 0; i < numberOfEnumerations; i++)
                if (!this->enumeration[i]->IsEqual(that->enumeration[i]))
                    return false;
            return true;
        }
    }
}//OtherVariableOption::IsEqual

bool OtherVarOption::IsEqual(OtherVarOption *that)
{
    std::ostringstream outStr;

#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_debug, "Start comparing in OtherVarOption");
#endif
    if (this == NULL)
    {
        if (that == NULL)
            return true;
        else
        {
#ifndef NDEBUG
            osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_debug, "First object is NULL, second is not");
#endif
            return false;
        }
    }
    else
    {
        if (that == NULL)
        {
#ifndef NDEBUG
            osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_debug, "Second object is NULL, first is not");
#endif
            return false;
        }
        else
        {
            if ((this->idx     != that->idx)     ||  this->name != that->name   || (this->value   != that->value) ||
                    (this->lbValue != that->lbValue) || (this->ubValue != that->ubValue))
            {
#ifndef NDEBUG
                outStr.str("");
                outStr.clear();
                outStr << "idx: "     << this->idx     << " vs. " << that->idx     << endl;
                outStr << "value: "   << this->value   << " vs. " << that->value   << endl;
                outStr << "lbValue: " << this->lbValue << " vs. " << that->lbValue << endl;
                outStr << "ubValue: " << this->ubValue << " vs. " << that->ubValue << endl;
                osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_debug, outStr.str());
#endif
                return false;
            }
            return true;
        }
    }
}//OtherVarOption::IsEqual
#endif

bool ObjectiveOption::IsEqual(ObjectiveOption *that)
{
    std::ostringstream outStr;

#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_debug, "Start comparing in ObjectiveOption");
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
        if (this->initialObjectiveValues == NULL)
        {
            if (that->initialObjectiveValues != NULL)
                return false;
        }
        else
            if (!this->initialObjectiveValues->IsEqual(that->initialObjectiveValues))
                return false;

        if (this->initialObjectiveBounds == NULL)
        {
            if (that->initialObjectiveBounds != NULL)
                return false;
        }
        else
            if (!this->initialObjectiveBounds->IsEqual(that->initialObjectiveBounds))
                return false;

        if (this->initialBasisStatus == NULL)
        {
            if (that->initialBasisStatus != NULL)
                return false;
        }
        else
            if (!this->initialBasisStatus->IsEqual(that->initialBasisStatus))
                return false;

        if (this->numberOfOtherObjectiveOptions != that->numberOfOtherObjectiveOptions)
        {
#ifndef NDEBUG
            outStr.str("");
            outStr.clear();
            outStr << "numberOfOtherObjectiveOptions: " << this->numberOfOtherObjectiveOptions << " vs. " << that->numberOfOtherObjectiveOptions << endl;
            osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_debug, outStr.str());
#endif
            return false;
        }

        for (unsigned int i = 0; i < this->numberOfOtherObjectiveOptions; i++)
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
}//ObjectiveOption::IsEqual

bool InitObjectiveValues::IsEqual(InitObjectiveValues *that)
{
    std::ostringstream outStr;

#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_debug, "Start comparing in InitObjectiveValues");
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
            outStr << "numberOfObj: " << this->numberOfObj << " vs. " << that->numberOfObj << endl;
            osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_debug, outStr.str());
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
}//InitObjectiveValues::IsEqual

bool InitObjValue::IsEqual(InitObjValue *that)
{
    std::ostringstream outStr;

#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_debug, "Start comparing in InitObjValue");
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
        if ((this->idx != that->idx) || this->name != that->name || !OSIsEqual(this->value, that->value))
        {
#ifndef NDEBUG
            outStr.str("");
            outStr.clear();
            outStr << "idx: "   << this->idx   << " vs. " << that->idx   << endl;
            outStr << "value: " << this->value << " vs. " << that->value << endl;
            osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_debug, outStr.str());
#endif
            return false;
        }
    }

    return true;
}//InitObjValue::IsEqual

bool InitObjectiveBounds::IsEqual(InitObjectiveBounds *that)
{
    std::ostringstream outStr;

#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_debug, "Start comparing in InitObjectiveBounds");
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
            outStr << "numberOfObj: " << this->numberOfObj << " vs. " << that->numberOfObj << endl;
            osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_debug, outStr.str());
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
}//InitObjectiveBounds::IsEqual

bool InitObjBound::IsEqual(InitObjBound *that)
{
    std::ostringstream outStr;

#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_debug, "Start comparing in InitObjBound");
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
        if ((this->idx  != that->idx) ||
             this->name != that->name ||
             !OSIsEqual(this->lbValue, that->lbValue) ||
             !OSIsEqual(this->ubValue, that->ubValue) )
        {
#ifndef NDEBUG
            outStr.str("");
            outStr.clear();
            outStr << "idx: "     << this->idx     << " vs. " << that->idx     << endl;
            outStr << "lbValue: " << this->lbValue << " vs. " << that->lbValue << endl;
            outStr << "ubValue: " << this->ubValue << " vs. " << that->ubValue << endl;
            osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_debug, outStr.str());
#endif
            return false;
        }
    }

    return true;
}//InitObjBound::IsEqual

#if 0
bool OtherObjectiveOption::IsEqual(OtherObjectiveOption *that)
{
    std::ostringstream outStr;

#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_debug, "Start comparing in OtherObjectiveOption");
#endif
    if (this == NULL)
    {
        if (that == NULL)
            return true;
        else
        {
#ifndef NDEBUG
            osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_debug, "First object is NULL, second is not");
#endif
            return false;
        }
    }
    else
    {
        if (that == NULL)
        {
#ifndef NDEBUG
            osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_debug, "Second object is NULL, first is not");
#endif
            return false;
        }
        else
        {
            if ((this->name        != that->name)     ||
                    (this->value       != that->value)    ||
                    (this->solver      != that->solver)   ||
                    (this->category    != that->category) ||
                    (this->type        != that->type)     ||
                    (this->description != that->description))
            {
#ifndef NDEBUG
                outStr.str("");
                outStr.clear();
                outStr << "name: "        << this->name        << " vs. " << that->name        << endl;
                outStr << "value: "       << this->value       << " vs. " << that->value       << endl;
                outStr << "solver: "      << this->solver      << " vs. " << that->solver      << endl;
                outStr << "category: "    << this->category    << " vs. " << that->category    << endl;
                outStr << "type: "        << this->type        << " vs. " << that->type        << endl;
                outStr << "description: " << this->description << " vs. " << that->description << endl;
                osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_debug, outStr.str());
#endif
                return false;
            }

            if (this->numberOfObj != that->numberOfObj)
            {
#ifndef NDEBUG
                outStr.str("");
                outStr.clear();
                outStr << "numberOfObj: " << this->numberOfObj << " vs. " << that->numberOfObj << endl;
                osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_debug, outStr.str());
#endif
                return false;
            }
            int i;
            for (i = 0; i < numberOfObj; i++)
                if (!this->obj[i]->IsEqual(that->obj[i]))
                    return false;
            return true;
        }
    }
}//OtherObjectiveOption::IsEqual

bool OtherObjOption::IsEqual(OtherObjOption *that)
{
    std::ostringstream outStr;

#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_debug, "Start comparing in OtherObjOption");
#endif
    if (this == NULL)
    {
        if (that == NULL)
            return true;
        else
        {
#ifndef NDEBUG
            osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_debug, "First object is NULL, second is not");
#endif
            return false;
        }
    }
    else
    {
        if (that == NULL)
        {
#ifndef NDEBUG
            osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_debug, "Second object is NULL, first is not");
#endif
            return false;
        }
        else
        {
            if ((this->idx     != that->idx)     || this->name != that->name  || (this->value   != that->value) ||
                    (this->lbValue != that->lbValue) || (this->ubValue != that->ubValue))
            {
#ifndef NDEBUG
                outStr.str("");
                outStr.clear();
                outStr << "idx: "     << this->idx     << " vs. " << that->idx     << endl;
                outStr << "value: "   << this->value   << " vs. " << that->value   << endl;
                outStr << "lbValue: " << this->lbValue << " vs. " << that->lbValue << endl;
                outStr << "ubValue: " << this->ubValue << " vs. " << that->ubValue << endl;
                osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_debug, outStr.str());
#endif
                return false;
            }
            return true;
        }
    }
}//OtherObjOption::IsEqual
#endif

bool ConstraintOption::IsEqual(ConstraintOption *that)
{
    std::ostringstream outStr;

#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_debug, "Start comparing in ConstraintOption");
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

        if (this->initialConstraintValues == NULL)
        {
            if (that->initialConstraintValues != NULL)
                return false;
        }
        else
            if (!this->initialConstraintValues->IsEqual(that->initialConstraintValues))
                return false;

        if (this->initialDualValues == NULL)
        {
            if (that->initialDualValues != NULL)
                return false;
        }
        else
            if (!this->initialDualValues->IsEqual(that->initialDualValues))
                return false;

        if (this->initialBasisStatus == NULL)
        {
            if (that->initialBasisStatus != NULL)
                return false;
        }
        else
            if (!this->initialBasisStatus->IsEqual(that->initialBasisStatus))
                return false;

        if (this->numberOfOtherConstraintOptions != that->numberOfOtherConstraintOptions)
        {
#ifndef NDEBUG
            outStr.str("");
            outStr.clear();
            outStr << "numberOfOtherConstraintOptions: " << this->numberOfOtherConstraintOptions << " vs. " << that->numberOfOtherConstraintOptions << endl;
            osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_debug, outStr.str());
#endif
            return false;
        }

        for (unsigned int i = 0; i < this->numberOfOtherConstraintOptions; i++)
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
}//ConstraintOption::IsEqual

bool InitConstraintValues::IsEqual(InitConstraintValues *that)
{
    std::ostringstream outStr;

#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_debug, "Start comparing in InitConstraintValues");
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
            outStr << "numberOfCon: " << this->numberOfCon << " vs. " << that->numberOfCon << endl;
            osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_debug, outStr.str());
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
}//InitConstraintValues::IsEqual

bool InitConValue::IsEqual(InitConValue *that)
{
    std::ostringstream outStr;

#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_debug, "Start comparing in InitConValue");
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
        if ((this->idx != that->idx) || this->name != that->name || !OSIsEqual(this->value, that->value))
        {
#ifndef NDEBUG
            outStr.str("");
            outStr.clear();
            outStr << "idx: "   << this->idx   << " vs. " << that->idx   << endl;
            outStr << "value: " << this->value << " vs. " << that->value << endl;
            osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_debug, outStr.str());
#endif
            return false;
        }
    }

    return true;
}//InitConValue::IsEqual

bool InitDualVariableValues::IsEqual(InitDualVariableValues *that)
{
    std::ostringstream outStr;

#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_debug, "Start comparing in InitDualVariableValues");
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
            outStr << "numberOfCon: " << this->numberOfCon << " vs. " << that->numberOfCon << endl;
            osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_debug, outStr.str());
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
}//InitDualVariableValues::IsEqual

bool InitDualVarValue::IsEqual(InitDualVarValue *that)
{
    std::ostringstream outStr;

#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_debug, "Start comparing in InitDualVarValue");
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
        if ((this->idx != that->idx) || this->name != that->name ||
                !OSIsEqual(this->lbDualValue, that->lbDualValue) ||
                !OSIsEqual(this->ubDualValue, that->ubDualValue))
        {
#ifndef NDEBUG
            outStr.str("");
            outStr.clear();
            outStr << "idx: "         << this->idx         << " vs. " << that->idx         << endl;
            outStr << "lbDualValue: " << this->lbDualValue << " vs. " << that->lbDualValue << endl;
            outStr << "ubDualValue: " << this->ubDualValue << " vs. " << that->ubDualValue << endl;
            osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_debug, outStr.str());
#endif
            return false;
        }
    }

    return true;
}//InitDualVarValue::IsEqual

#if 0
bool OtherConstraintOption::IsEqual(OtherConstraintOption *that)
{
    std::ostringstream outStr;

#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_debug, "Start comparing in OtherConstraintOption");
#endif
    if (this == NULL)
    {
        if (that == NULL)
            return true;
        else
        {
#ifndef NDEBUG
            osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_debug, "First object is NULL, second is not");
#endif
            return false;
        }
    }
    else
    {
        if (that == NULL)
        {
#ifndef NDEBUG
            osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_debug, "Second object is NULL, first is not");
#endif
            return false;
        }
        else
        {
            if ((this->name        != that->name)     ||
                    (this->value       != that->value)    ||
                    (this->solver      != that->solver)   ||
                    (this->category    != that->category) ||
                    (this->type        != that->type)     ||
                    (this->description != that->description))
            {
#ifndef NDEBUG
                outStr.str("");
                outStr.clear();
                outStr << "name: "        << this->name        << " vs. " << that->name        << endl;
                outStr << "value: "       << this->value       << " vs. " << that->value       << endl;
                outStr << "solver: "      << this->solver      << " vs. " << that->solver      << endl;
                outStr << "category: "    << this->category    << " vs. " << that->category    << endl;
                outStr << "type: "        << this->type        << " vs. " << that->type        << endl;
                outStr << "description: " << this->description << " vs. " << that->description << endl;
                osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_debug, outStr.str());
#endif
                return false;
            }

            if (this->numberOfCon != that->numberOfCon)
            {
#ifndef NDEBUG
                outStr.str("");
                outStr.clear();
                outStr << "numberOfCon: " << this->numberOfCon << " vs. " << that->numberOfCon << endl;
                osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_debug, outStr.str());
#endif
                return false;
            }
            int i;
            for (i = 0; i < numberOfCon; i++)
                if (!this->con[i]->IsEqual(that->con[i]))
                    return false;
            return true;
        }
    }
}//OtherConstraintOption::IsEqual

bool OtherConOption::IsEqual(OtherConOption *that)
{
    std::ostringstream outStr;

#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_debug, "Start comparing in OtherConOption");
#endif
    if (this == NULL)
    {
        if (that == NULL)
            return true;
        else
        {
#ifndef NDEBUG
            osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_debug, "First object is NULL, second is not");
#endif
            return false;
        }
    }
    else
    {
        if (that == NULL)
        {
#ifndef NDEBUG
            osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_debug, "Second object is NULL, first is not");
#endif
            return false;
        }

        else
        {
            if ((this->idx     != that->idx)     || this->name != that->name || (this->value   != that->value) ||
                    (this->lbValue != that->lbValue) || (this->ubValue != that->ubValue))
            {
#ifndef NDEBUG
                outStr.str("");
                outStr.clear();
                outStr << "idx: "     << this->idx     << " vs. " << that->idx     << endl;
                outStr << "value: "   << this->value   << " vs. " << that->value   << endl;
                outStr << "lbValue: " << this->lbValue << " vs. " << that->lbValue << endl;
                outStr << "ubValue: " << this->ubValue << " vs. " << that->ubValue << endl;
                osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_debug, outStr.str());
#endif
                return false;
            }
            return true;
        }
    }
}//OtherConOption::IsEqual
#endif

bool SolverOptions::IsEqual(SolverOptions *that)
{
    std::ostringstream outStr;

#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_debug,
        "Start comparing in SolverOptions");
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
        if (this->numberOfSolverOptions != that->numberOfSolverOptions)
        {
#ifndef NDEBUG
            outStr.str("");
            outStr.clear();
            outStr << "numberOfSolverOptions: " << this->numberOfSolverOptions << " vs. " << that->numberOfSolverOptions << endl;
            osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_debug, outStr.str());
#endif
            return false;
        }

        for (unsigned int i = 0; i < this->numberOfSolverOptions; i++)
        {
            if (this->solverOption[i] == NULL)
            {
                if (that->solverOption[i] != NULL)
                    return false;
            }
            else
                if (!this->solverOption[i]->IsEqual(that->solverOption[i]))
                    return false;
        }
    }

    return true;
}//SolverOptions::IsEqual


/***********************************************************************
 *
 * Methods to set a random OSOption object.
 *
 * These methods are mostly useful during the debugging process
 * but might come in handy in other ways
 * The calling sequence is identical in all cases: setRandom( double density, bool conformant )
 * @param density gives the probability that a particular child element is generated
 * @param conformant controls whether side constraints (such as agreement of "numberOfChildren"
 *      attributes with the number of <child> elements) should be enforced (conformant=true) or not
 *
 ***********************************************************************/
bool OSOption::setRandom( double density, bool conformant )
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_trace, "Set random OSOption");
#endif
    if (OSRand() <= density)
    {
        optionHeader = new GeneralFileHeader();
        optionHeader->setRandom(density, conformant);
    }
    if (OSRand() <= density)
    {
        general = new GeneralOption();
        general->setRandom(density, conformant);
    }
    if (OSRand() <= density)
    {
        system = new SystemOption();
        system->setRandom(density, conformant);
    }
    if (OSRand() <= density)
    {
        service = new ServiceOption();
        service->setRandom(density, conformant);
    }
    if (OSRand() <= density)
    {
        job = new JobOption();
        job->setRandom(density, conformant);
    }
    if (OSRand() <= density)
    {
        optimization = new OptimizationOption();
        optimization->setRandom(density, conformant);
    }
    return true;
}//OSOption::setRandom


bool GeneralOption::setRandom( double density, bool conformant )
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_trace, "Set random GeneralOption");
#endif
    if (OSRand() <= density) this->serviceURI     = "random string";
    if (OSRand() <= density) this->serviceName    = "random string";
    if (OSRand() <= density) this->instanceName   = "random string";
    if (OSRand() <= density) this->jobID          = "random string";
    if (OSRand() <= density) this->solverToInvoke = "random string";
    if (OSRand() <= density) this->license        = "random string";
    if (OSRand() <= density) this->userName       = "random string";
    if (OSRand() <= density) this->password       = "random string";

    if (OSRand() <= density)
    {
        instanceLocation = new InstanceLocationOption();
        instanceLocation->setRandom(density, conformant);
    }
    if (OSRand() <= density)
    {
        contact = new ContactOption();
        contact->setRandom(density, conformant);
    }
    if (OSRand() <= density)
    {
        otherOptions = new OtherOptions();
        otherOptions->setRandom(density, conformant);
    }
    return true;
}//GeneralOption::setRandom


bool SystemOption::setRandom( double density, bool conformant )
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_trace, "Set random SystemOption");
#endif
    if (OSRand() <= density)
    {
        minDiskSpace = new StorageCapacity();
        minDiskSpace->setRandom(density, conformant);
    }
    if (OSRand() <= density)
    {
        minMemorySize = new StorageCapacity();
        minMemorySize->setRandom(density, conformant);
    }
    if (OSRand() <= density)
    {
        minCPUSpeed = new CPUSpeed();
        minCPUSpeed->setRandom(density, conformant);
    }
    if (OSRand() <= density)
    {
        minCPUNumber = new CPUNumber();
        minCPUNumber->setRandom(density, conformant);
    }
    if (OSRand() <= density)
    {
        otherOptions = new OtherOptions();
        otherOptions->setRandom(density, conformant);
    }
    return true;
}//SystemOption::setRandom


bool ServiceOption::setRandom( double density, bool conformant )
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_trace, "Set random ServiceOption");
#endif
    if (OSRand() <= density)
    {
        double temp = OSRand();
        if (conformant) temp = 0.5*temp;

        if      (temp <= 0.25) this->type = "solver";
        else if (temp <= 0.50) this->type = "agent";
        else if (temp <= 0.75) this->type = "";
        else                   this->type = "spy";
    }

    if (OSRand() <= density)
    {
        otherOptions = new OtherOptions();
        otherOptions->setRandom(density, conformant);
    }

    return true;
}//ServiceOption::setRandom


bool JobOption::setRandom( double density, bool conformant )
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_trace, "Set random JobOption");
#endif
    if (OSRand() <= density) this->requestedStartTime = "1997-08-11T01:23:45-09:13";

    if (OSRand() <= density)
    {
        maxTime = new TimeSpan();
        maxTime->setRandom(density, conformant);
    }
    if (OSRand() <= density)
    {
        dependencies = new JobDependencies();
        dependencies->setRandom(density, conformant);
    }
    if (OSRand() <= density)
    {
        requiredDirectories = new DirectoriesAndFiles();
        requiredDirectories->setRandom(density, conformant);
    }
    if (OSRand() <= density)
    {
        requiredFiles = new DirectoriesAndFiles();
        requiredFiles->setRandom(density, conformant);
    }
    if (OSRand() <= density)
    {
        directoriesToMake = new DirectoriesAndFiles();
        directoriesToMake->setRandom(density, conformant);
    }
    if (OSRand() <= density)
    {
        filesToMake = new DirectoriesAndFiles();
        filesToMake->setRandom(density, conformant);
    }
    if (OSRand() <= density)
    {
        inputDirectoriesToMove = new PathPairs();
        inputDirectoriesToMove->setRandom(density, conformant);
    }
    if (OSRand() <= density)
    {
        inputFilesToMove = new PathPairs();
        inputFilesToMove->setRandom(density, conformant);
    }
    if (OSRand() <= density)
    {
        outputFilesToMove = new PathPairs();
        outputFilesToMove->setRandom(density, conformant);
    }
    if (OSRand() <= density)
    {
        outputDirectoriesToMove = new PathPairs();
        outputDirectoriesToMove->setRandom(density, conformant);
    }
    if (OSRand() <= density)
    {
        filesToDelete = new DirectoriesAndFiles();
        filesToDelete->setRandom(density, conformant);
    }
    if (OSRand() <= density)
    {
        directoriesToDelete = new DirectoriesAndFiles();
        directoriesToDelete->setRandom(density, conformant);
    }
    if (OSRand() <= density)
    {
        processesToKill = new Processes();
        processesToKill->setRandom(density, conformant);
    }
    if (OSRand() <= density)
    {
        otherOptions = new OtherOptions();
        otherOptions->setRandom(density, conformant);
    }
    return true;
}//JobOption::setRandom

bool OptimizationOption::setRandom( double density, bool conformant )
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_trace, "Set random OptimizationOption");
#endif
    if (OSRand() <= density && !conformant) this->numberOfVariables   = (int)(1+9*OSRand());
    if (OSRand() <= density && !conformant) this->numberOfObjectives  = (int)(1+9*OSRand());
    if (OSRand() <= density && !conformant) this->numberOfConstraints = (int)(1+9*OSRand());

    if (OSRand() <= density)
    {
        variables = new VariableOption();
        variables->setRandom(density, conformant);
    }
    if (OSRand() <= density)
    {
        objectives = new ObjectiveOption();
        objectives->setRandom(density, conformant);
    }
    if (OSRand() <= density)
    {
        constraints = new ConstraintOption();
        constraints->setRandom(density, conformant);
    }
    if (OSRand() <= density)
    {
        solverOptions = new SolverOptions();
        solverOptions->setRandom(density, conformant);
    }

    return true;
}//OptimizationOption::setRandom

bool InstanceLocationOption::setRandom( double density, bool conformant )
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_trace, "Set random InstanceLocationOption");
#endif
    if (OSRand() <= density) this->value = "http://www.google.com";
    if (OSRand() <= density)
    {
        double temp = OSRand();
        if (conformant) temp = 0.5*temp;

        if      (temp <= 0.25) this->locationType = "local";
        else if (temp <= 0.50) this->locationType = "ftp";
        else if (temp <= 0.75) this->locationType = "";
        else                   this->locationType = "global";
    }
    return true;
}//InstanceLocationOption::setRandom

bool ContactOption::setRandom( double density, bool conformant )
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_trace, "Set random ContactOption");
#endif
    if (OSRand() <= density) this->value = "http://www.google.com";
    if (OSRand() <= density)
    {
        double temp = OSRand();
        if (conformant) temp = 0.5*temp;

        if      (temp <= 0.25) this->transportType = "osp";
        else if (temp <= 0.50) this->transportType = "ftp";
        else if (temp <= 0.75) this->transportType = "";
        else                   this->transportType = "nlp";
    }
    return true;
}//ContactOption::setRandom

bool OtherOptions::setRandom( double density, bool conformant )
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_trace, "Set random OtherOptions");
#endif
    int n;

    this->numberOfOtherOptions = (int)(1+4*OSRand());

    if (conformant)    n = this->numberOfOtherOptions;
    else            n = (int)(1+4*OSRand());

    other = new OtherOptionOrResult*[n];

    for (int i = 0; i < n; i++)
    {
        other[i] = new OtherOptionOrResult();
        other[i]->setRandom(density, conformant);
    }

    return true;
}//OtherOptions::setRandom


bool JobDependencies::setRandom( double density, bool conformant )
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_trace, "Set random JobDependencies");
#endif
    int n;

    this->numberOfJobIDs = (int)(1+4*OSRand());

    if (conformant)    n = this->numberOfJobIDs;
    else            n = (int)(1+4*OSRand());

    jobID = new std::string[n];
    for (int i = 0; i < n; i++)
        jobID[i] = "random string";

    return true;
}//JobDependencies::setRandom

bool DirectoriesAndFiles::setRandom( double density, bool conformant )
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_trace, "Set random DirectoriesAndFiles");
#endif
    int n;

    this->numberOfPaths = (int)(1+4*OSRand());

    if (conformant)    n = this->numberOfPaths;
    else            n = (int)(1+4*OSRand());


    path = new std::string[n];
    for (int i = 0; i < n; i++)
        path[i] = "random string";

    return true;
}//DirectoriesAndFiles::setRandom

bool PathPairs::setRandom( double density, bool conformant )
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_trace, "Set random PathPairs");
#endif
    int n;

    this->numberOfPathPairs = (int)(1+4*OSRand());

    if (conformant)    n = this->numberOfPathPairs;
    else            n =(int)(1+4*OSRand());

    pathPair = new PathPair*[n];
    for (int i = 0; i < n; i++)
    {
        this->pathPair[i] = new PathPair();
        this->pathPair[i]->setRandom(density, conformant);
    }

    return true;
}//PathPairs::setRandom

bool PathPair::setRandom( double density, bool conformant )
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_trace, "Set random PathPair");
#endif
    this->from = "random string";
    this->to   = "random string";
    if (OSRand() <= density) this->makeCopy = (OSRand() <= 0.5);
    return true;
}//PathPair::setRandom

bool Processes::setRandom( double density, bool conformant )
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_trace, "Set random Processes");
#endif
    int n;

    this->numberOfProcesses = (int)(1+4*OSRand());

    if (conformant)    n = this->numberOfProcesses;
    else            n = (int)(1+4*OSRand());

    process = new std::string[n];
    for (int i = 0; i < n; i++)
        process[i] = "random string";

    return true;
}//Processes::setRandom

bool VariableOption::setRandom( double density, bool conformant )
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_trace, "Set random VariableOption");
#endif
    if (OSRand() <= density)
    {
        this->initialVariableValues = new InitVariableValues();
        this->initialVariableValues->setRandom(density, conformant);
    }
    return false;
    if (OSRand() <= density)
    {
        this->initialVariableValuesString = new InitVariableValuesString();
        this->initialVariableValuesString->setRandom(density, conformant);
    }
    if (OSRand() <= density)
    {
        this->initialBasisStatus = new BasisStatus();
        this->initialBasisStatus->setRandom(density, conformant, 0, 9);
    }
    if (OSRand() <= density)
    {
        this->integerVariableBranchingWeights = new IntegerVariableBranchingWeights();
        this->integerVariableBranchingWeights->setRandom(density, conformant);
    }
    if (OSRand() <= density)
    {
        this->sosVariableBranchingWeights = new SOSVariableBranchingWeights();
        this->sosVariableBranchingWeights->setRandom(density, conformant);
    }

    this->numberOfOtherVariableOptions = (int)(4*OSRand());

    int n;

    if (conformant)    n = this->numberOfOtherVariableOptions;
    else            n = (int)(4*OSRand());

    other = new OtherVariableOptionOrResult*[n];
    for (int i = 0; i < n; i++)
    {
        other[i] = new OtherVariableOptionOrResult();
        other[i]->setRandom(density, conformant);
    }
    return true;
}//VariableOption::setRandom

bool InitVariableValues::setRandom( double density, bool conformant )
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_trace, "Set random InitVariableValues");
#endif
    this->numberOfVar = (int)(1+4*OSRand());

    int n;

    if (conformant)    n = this->numberOfVar;
    else            n = (int)(1+4*OSRand());

    var = new InitVarValue*[n];
    for (int i = 0; i < n; i++)
    {
        var[i] = new InitVarValue();
        var[i]->setRandom(density, conformant);
    }
    return true;
}//InitVariableValues::setRandom

bool InitVarValue::setRandom( double density, bool conformant )
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_trace, "Set random InitVarValue");
#endif
    this->idx = (int)(4*OSRand());

    if (OSRand() <= density)
        this->name = "random string";

    if (OSRand() <= density)
    {
        if (OSRand() <= 0.5) this->value = 3.14156;
        else                 this->value = 2.71828;
    }
    return true;
}//InitVarValue::setRandom


bool InitVariableValuesString::setRandom( double density, bool conformant )
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_trace, "Set random InitVariableValuesString");
#endif
    this->numberOfVar = (int)(1+4*OSRand());

    int n;

    if (conformant)    n = this->numberOfVar;
    else            n = (int)(1+4*OSRand());

    var = new InitVarValueString*[n];
    for (int i = 0; i < n; i++)
    {
        var[i] = new InitVarValueString();
        var[i]->setRandom(density, conformant);
    }
    return true;
}//InitVariableValuesString::setRandom

bool InitVarValueString::setRandom( double density, bool conformant )
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_trace, "Set random InitVarValueString");
#endif
    this->idx = (int)(4*OSRand());

    if (OSRand() <= density) this->name  = "random string";
    if (OSRand() <= density) this->value = "random string";

    return true;
}//InitVarValueString::setRandom


bool IntegerVariableBranchingWeights::setRandom( double density, bool conformant )
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_trace, "Set random IntegerVariableBranchingWeights");
#endif
    this->numberOfVar = (int)(1+4*OSRand());

    int n;

    if (conformant)    n = this->numberOfVar;
    else            n = (int)(1+4*OSRand());

    var = new BranchingWeight*[n];
    for (int i = 0; i < n; i++)
    {
        var[i] = new BranchingWeight();
        var[i]->setRandom(density, conformant);
    }
    return true;
}//IntegerVariableBranchingWeights::setRandom

bool SOSVariableBranchingWeights::setRandom( double density, bool conformant )
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_trace, "Set random SOSVariableBranchingWeights");
#endif
    this->numberOfSOS = (int)(1+4*OSRand());

    int n;

    if (conformant)    n = this->numberOfSOS;
    else            n = (int)(1+4*OSRand());

    sos = new SOSWeights*[n];
    for (int i = 0; i < n; i++)
    {
        sos[i] = new SOSWeights();
        sos[i]->setRandom(density, conformant);
    }
    return true;
}//SOSVariableBranchingWeights::setRandom


bool SOSWeights::setRandom( double density, bool conformant )
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_trace, "Set random SOSWeights");
#endif
    this->sosIdx      = (int)(4*OSRand());
    this->numberOfVar = (int)(4*OSRand());

    if (OSRand() <= density) this->groupWeight = OSRand();

    int n;

    if (conformant)    n = this->numberOfVar;
    else            n = (int)(4*OSRand());

    var = new BranchingWeight*[n];
    for (int i = 0; i < n; i++)
    {
        var[i] = new BranchingWeight();
        var[i]->setRandom(density, conformant);
    }
    return true;
}//SOSWeights::setRandom


bool BranchingWeight::setRandom( double density, bool conformant )
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_trace, "Set random BranchingWeight");
#endif
    this->idx = (int)(4*OSRand());

    if (OSRand() <= density) this->name  = "random string";

    if (OSRand() <= density)
        this->value = OSRand();
    return true;
}//BranchingWeight::setRandom

#if 0
bool OtherVariableOption::setRandom( double density, bool conformant )
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_trace, "Set random OtherVariableOption");
#endif
    this->name = "random string";
    if (OSRand() <= density) this->value       = "random string";
    if (OSRand() <= density) this->solver      = "random string";
    if (OSRand() <= density) this->category    = "random string";
    if (OSRand() <= density) this->type        = "random string";
    if (OSRand() <= density) this->description = "random string";

    if (OSRand() <= density)
    {
        if (OSRand() <= 0.5)
        {
            this->numberOfVar = (int)(4*OSRand());

            int n;

            if (conformant)    n = this->numberOfVar;
            else            n = (int)(4*OSRand());

            var = new OtherVarOption*[n];
            for (int i = 0; i < n; i++)
            {
                var[i] = new OtherVarOption();
                var[i]->setRandom(density, conformant);
            }
        }
        else
        {
            this->numberOfEnumerations = (int)(4*OSRand());

            int n;

            if (conformant)    n = this->numberOfEnumerations;
            else            n = (int)(4*OSRand());

            enumeration = new OtherOptionOrResultEnumeration*[n];
            for (int i = 0; i < n; i++)
            {
                enumeration[i] = new OtherOptionOrResultEnumeration();
                enumeration[i]->setRandom(density, conformant, 0, 9);
            }
        }
    }
    return true;
}//OtherVariableOption::setRandom

bool OtherVarOption::setRandom( double density, bool conformant )
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_trace, "Set random OtherVarOption");
#endif
    this->idx = (int)(4*OSRand());
    if (OSRand() <= density) this->name    = "random string";
    if (OSRand() <= density) this->value   = "random string";
    if (OSRand() <= density) this->lbValue = "random string";
    if (OSRand() <= density) this->ubValue = "random string";
    return true;
}//OtherVarOption::setRandom
#endif

bool ObjectiveOption::setRandom( double density, bool conformant )
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_trace, "Set random ObjectiveOption");
#endif
    if (OSRand() <= density)
    {
        this->initialObjectiveValues = new InitObjectiveValues();
        this->initialObjectiveValues->setRandom(density, conformant);
    }
    return false;
    if (OSRand() <= density)
    {
        this->initialObjectiveBounds = new InitObjectiveBounds();
        this->initialObjectiveBounds->setRandom(density, conformant);
    }
    if (OSRand() <= density)
    {
        this->initialBasisStatus = new BasisStatus();
        this->initialBasisStatus->setRandom(density, conformant, -2, -1);
    }

    if (OSRand() <= density)
    {
        this->numberOfOtherObjectiveOptions = (int)(4*OSRand());

        int n;

        if (conformant)    n = this->numberOfOtherObjectiveOptions;
        else            n = (int)(4*OSRand());

        other = new OtherObjectiveOptionOrResult*[n];
        for (int i = 0; i < n; i++)
        {
            other[i] = new OtherObjectiveOptionOrResult();
            other[i]->setRandom(density, conformant);
        }
    }
    return true;
}//ObjectiveOption::setRandom

bool InitObjectiveValues::setRandom( double density, bool conformant )
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_trace, "Set random InitObjectiveValues");
#endif
    this->numberOfObj = (int)(1+4*OSRand());

    int n;

    if (conformant)    n = this->numberOfObj;
    else            n = (int)(1+4*OSRand());

    obj = new InitObjValue*[n];
    for (int i = 0; i < n; i++)
    {
        obj[i] = new InitObjValue();
        obj[i]->setRandom(density, conformant);
    }
    return true;
}//InitObjectiveValues::setRandom

bool InitObjValue::setRandom( double density, bool conformant )
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_trace, "Set random InitObjValue");
#endif
    if (OSRand() <= 0.5) idx = -1;
    else                 idx = -2;

    if (OSRand() <= density) this->name  = "random string";

    if (OSRand() <= density)
    {
        if (OSRand() <= 0.5) this->value = 3.14156;
        else                 this->value = 2.71828;
    }
    return true;
}//InitObjValue::setRandom

bool InitObjectiveBounds::setRandom( double density, bool conformant )
{

#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_trace, "Set random InitObjectiveBounds");
#endif
    this->numberOfObj = (int)(1+4*OSRand());

    int n;

    if (conformant)    n = this->numberOfObj;
    else            n = (int)(1+4*OSRand());

    obj = new InitObjBound*[n];
    for (int i = 0; i < n; i++)
    {
        obj[i] = new InitObjBound();
        obj[i]->setRandom(density, conformant);
    }
    return true;
}//InitObjectiveBounds::setRandom

bool InitObjBound::setRandom( double density, bool conformant )
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_trace, "Set random InitObjBound");
#endif
    if (OSRand() <= 0.5) idx = -1;
    else                 idx = -2;

    if (OSRand() <= density) this->name  = "random string";

    if (OSRand() <= density)
    {
        if (OSRand() <= 0.5) this->lbValue = 3.14156;
        else                 this->lbValue = 2.71828;
        if (OSRand() <= 0.5) this->ubValue = 3.14156;
        else                 this->ubValue = 2.71828;
    }
    return true;
}//InitObjBound::setRandom

#if 0
bool OtherObjectiveOption::setRandom( double density, bool conformant )
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_trace, "Set random OtherObjectiveOption");
#endif
    this->name = "random string";
    if (OSRand() <= density) this->value       = "random string";
    if (OSRand() <= density) this->solver      = "random string";
    if (OSRand() <= density) this->category    = "random string";
    if (OSRand() <= density) this->type        = "random string";
    if (OSRand() <= density) this->description = "random string";

    if (OSRand() <= density)
    {
        if (OSRand() <= 0.5)
        {
            this->numberOfObj = (int)(4*OSRand());

            int n;

            if (conformant)    n = this->numberOfObj;
            else            n = (int)(4*OSRand());

            obj = new OtherObjOption*[n];
            for (int i = 0; i < n; i++)
            {
                obj[i] = new OtherObjOption();
                obj[i]->setRandom(density, conformant);
            }
        }
        else
        {
            this->numberOfEnumerations = (int)(4*OSRand());

            int n;

            if (conformant)    n = this->numberOfEnumerations;
            else            n = (int)(4*OSRand());

            enumeration = new OtherOptionOrResultEnumeration*[n];
            for (int i = 0; i < n; i++)
            {
                enumeration[i] = new OtherOptionOrResultEnumeration();
                enumeration[i]->setRandom(density, conformant, -2, -1);
            }
        }
    }
    return true;
}//OtherObjectiveOption::setRandom

bool OtherObjOption::setRandom( double density, bool conformant )
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_trace, "Set random OtherObjOption");
#endif
    if (OSRand() <= 0.5) this->idx = -1;
    else                 this->idx = -2;
    if (OSRand() <= density) this->name    = "random string";
    if (OSRand() <= density) this->value   = "random string";
    if (OSRand() <= density) this->lbValue = "random string";
    if (OSRand() <= density) this->ubValue = "random string";
    return true;
}//OtherObjOption::setRandom
#endif

bool ConstraintOption::setRandom( double density, bool conformant )
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_trace, "Set random ConstraintOption");
#endif
    if (OSRand() <= density)
    {
        this->initialConstraintValues = new InitConstraintValues();
        this->initialConstraintValues->setRandom(density, conformant);
    }
    return false;
    if (OSRand() <= density)
    {
        this->initialDualValues = new InitDualVariableValues();
        this->initialDualValues->setRandom(density, conformant);
    }
    if (OSRand() <= density)
    {
        this->initialBasisStatus = new BasisStatus();
        this->initialBasisStatus->setRandom(density, conformant, 0, 4);
    }

    if (OSRand() <= density)
    {
        this->numberOfOtherConstraintOptions = (int)(4*OSRand());

        int n;

        if (conformant)    n = this->numberOfOtherConstraintOptions;
        else            n = (int)(4*OSRand());

        other = new OtherConstraintOptionOrResult*[n];
        for (int i = 0; i < n; i++)
        {
            other[i] = new OtherConstraintOptionOrResult();
            other[i]->setRandom(density, conformant);
        }
    }
    return true;
}//ConstraintOption::setRandom

bool InitConstraintValues::setRandom( double density, bool conformant )
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_trace, "Set random InitConstraintValues");
#endif
    this->numberOfCon = (int)(1+4*OSRand());

    int n;

    if (conformant)    n = this->numberOfCon;
    else            n = (int)(1+4*OSRand());

    con = new InitConValue*[n];
    for (int i = 0; i < n; i++)
    {
        con[i] = new InitConValue();
        con[i]->setRandom(density, conformant);
    }
    return true;
}//InitConstraintValues::setRandom

bool InitConValue::setRandom( double density, bool conformant )
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_trace, "Set random InitConValue");
#endif
    this->idx = (int)(4*OSRand());

    if (OSRand() <= density) this->name  = "random string";

    if (OSRand() <= density)

    {
        if (OSRand() <= 0.5) this->value = 3.14156;
        else                 this->value = 2.71828;
    }
    return true;
}//InitConValue::setRandom

bool InitDualVariableValues::setRandom( double density, bool conformant )
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_trace, "Set random InitDualVariableValues");
#endif
    this->numberOfCon = (int)(1+4*OSRand());

    int n;

    if (conformant)    n = this->numberOfCon;
    else            n = (int)(1+4*OSRand());

    con = new InitDualVarValue*[n];
    for (int i = 0; i < n; i++)
    {
        con[i] = new InitDualVarValue();
        con[i]->setRandom(density, conformant);
    }
    return true;
}//InitDualVariableValues::setRandom

bool InitDualVarValue::setRandom( double density, bool conformant )
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_trace, "Set random InitDualVarValue");
#endif
    this->idx = (int)(4*OSRand());

    if (OSRand() <= density) this->name  = "random string";

    if (OSRand() <= density)
    {
        if (OSRand() <= 0.5) this->lbDualValue = 3.14156;
        else                 this->lbDualValue = 2.71828;
        if (OSRand() <= 0.5) this->ubDualValue = 3.14156;
        else                 this->ubDualValue = 2.71828;
    }
    return true;
}//InitDualVarValue::setRandom

#if 0
bool OtherConstraintOption::setRandom( double density, bool conformant )
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_trace, "Set random OtherConstraintOption");
#endif
    this->name = "random string";
    if (OSRand() <= density) this->value       = "random string";
    if (OSRand() <= density) this->solver      = "random string";
    if (OSRand() <= density) this->category    = "random string";
    if (OSRand() <= density) this->type        = "random string";
    if (OSRand() <= density) this->description = "random string";

    if (OSRand() <= density)
    {
        if (OSRand() <= 0.5)
        {
            this->numberOfCon = (int)(4*OSRand());

            int n;

            if (conformant)    n = this->numberOfCon;
            else            n = (int)(4*OSRand());

            con = new OtherConOption*[n];
            for (int i = 0; i < n; i++)
            {
                con[i] = new OtherConOption();
                con[i]->setRandom(density, conformant);
            }
        }
        else
        {
            this->numberOfEnumerations = (int)(4*OSRand());

            int n;

            if (conformant)    n = this->numberOfEnumerations;
            else            n = (int)(4*OSRand());

            enumeration = new OtherOptionOrResultEnumeration*[n];
            for (int i = 0; i < n; i++)
            {
                enumeration[i] = new OtherOptionOrResultEnumeration();
                enumeration[i]->setRandom(density, conformant, 0, 4);
            }
        }
    }
    return true;
}//OtherConstraintOption::setRandom

bool OtherConOption::setRandom( double density, bool conformant )
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_trace, "Set random OtherConOption");
#endif
    this->idx = (int)(4*OSRand());
    if (OSRand() <= density) this->name    = "random string";
    if (OSRand() <= density) this->value   = "random string";
    if (OSRand() <= density) this->lbValue = "random string";
    if (OSRand() <= density) this->ubValue = "random string";
    return true;
}//OtherConOption::setRandom
#endif

bool SolverOptions::setRandom( double density, bool conformant )
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_trace, "Set random SolverOptions");
#endif
    this->numberOfSolverOptions = (int)(1+4*OSRand());

    int n;

    if (conformant)    n = this->numberOfSolverOptions;
    else            n = (int)(1+4*OSRand());

    solverOption = new SolverOptionOrResult*[n];
    for (int i = 0; i < n; i++)
    {
        solverOption[i] = new SolverOptionOrResult();
        solverOption[i]->setRandom(density, conformant);
    }
    return true;
}//SolverOptions::setRandom


/***********************************************************************
 *
 * Methods that allow deep copies of an OSOption object.
 *
 * These methods call each other recursively.
 *
 ***********************************************************************/

bool OSOption::deepCopyFrom(OSOption *that)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_trace, "Make deep copy of OSOption");
#endif
    if (that->optionHeader != NULL)
    {
        this->optionHeader = new GeneralFileHeader();
        if (!this->optionHeader->deepCopyFrom(that->optionHeader))
            return false;
    }
    if (that->general != NULL)
    {
        this->general = new GeneralOption();
        if (!this->general->deepCopyFrom(that->general))
            return false;
    }
    if (that->system != NULL)
    {
        this->system = new SystemOption();
        if (!this->system->deepCopyFrom(that->system))
            return false;
    }
    if (that->service != NULL)
    {
        this->service = new ServiceOption();
        if (!this->service->deepCopyFrom(that->service))
            return false;
    }
    if (that->job != NULL)
    {
        this->job = new JobOption();
        if (!this->job->deepCopyFrom(that->job))
            return false;
    }
    if (that->optimization != NULL)
    {
        this->optimization = new OptimizationOption();
        if (!this->optimization->deepCopyFrom(that->optimization))
            return false;
    }
    return true;
}//OSOption::deepCopyFrom


bool GeneralOption::deepCopyFrom(GeneralOption *that)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_trace, "Make deep copy of GeneralOption");
#endif
    this->serviceURI     = that->serviceURI;
    this->serviceName    = that->serviceName;
    this->instanceName   = that->instanceName;
    this->jobID          = that->jobID;
    this->solverToInvoke = that->solverToInvoke;
    this->license        = that->license;
    this->userName       = that->userName;
    this->password       = that->password;

    if (that->instanceLocation != NULL)
    {
        this->instanceLocation = new InstanceLocationOption();
        if (!this->instanceLocation->deepCopyFrom(that->instanceLocation))
            return false;
    }
    if (that->contact != NULL)
    {
        this->contact = new ContactOption();
        if (!this->contact->deepCopyFrom(that->contact))
            return false;
    }
    if (that->otherOptions != NULL)
    {
        this->otherOptions = new OtherOptions();
        if (!this->otherOptions->deepCopyFrom(that->otherOptions))
            return false;
    }
    return true;
}//GeneralOption::deepCopyFrom


bool SystemOption::deepCopyFrom(SystemOption *that)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_trace, "Make deep copy of SystemOption");
#endif
    if (that->minDiskSpace != NULL)
    {
        this->minDiskSpace = new StorageCapacity();
        if (!this->minDiskSpace->deepCopyFrom(that->minDiskSpace))
            return false;
    }
    if (that->minMemorySize != NULL)
    {
        this->minMemorySize = new StorageCapacity();
        if (!this->minMemorySize->deepCopyFrom(that->minMemorySize))
            return false;
    }
    if (that->minCPUSpeed != NULL)
    {
        this->minCPUSpeed = new CPUSpeed();
        if (!this->minCPUSpeed->deepCopyFrom(that->minCPUSpeed))
            return false;
    }
    if (that->minCPUNumber != NULL)
    {
        this->minCPUNumber = new CPUNumber();
        if (!this->minCPUNumber->deepCopyFrom(that->minCPUNumber))
            return false;
    }
    if (that->otherOptions != NULL)
    {
        this->otherOptions = new OtherOptions();
        if (!this->otherOptions->deepCopyFrom(that->otherOptions))
            return false;
    }
    return true;
}//SystemOption::deepCopyFrom


bool ServiceOption::deepCopyFrom(ServiceOption *that)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_trace, "Make deep copy of ServiceOption");
#endif
        this->type = that->type;

    if (that->otherOptions != NULL)
    {
        otherOptions = new OtherOptions();
        if (!otherOptions->deepCopyFrom(that->otherOptions))
            return false;
    }

    return true;
}//ServiceOption::deepCopyFrom


bool JobOption::deepCopyFrom(JobOption *that)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_trace, "Make deep copy of JobOption");
#endif
    this->requestedStartTime = that->requestedStartTime;

    if (that->maxTime != NULL)
    {
        maxTime = new TimeSpan();
        if (!maxTime->deepCopyFrom(that->maxTime))
            return false;
    }
    if (that->dependencies != NULL)
    {
        dependencies = new JobDependencies();
        if (!dependencies->deepCopyFrom(that->dependencies))
            return false;
    }
    if (that->requiredDirectories != NULL)
    {
        requiredDirectories = new DirectoriesAndFiles();
        if (!requiredDirectories->deepCopyFrom(that->requiredDirectories))
            return false;
    }
    if (that->requiredFiles != NULL)
    {
        requiredFiles = new DirectoriesAndFiles();
        if (!requiredFiles->deepCopyFrom(that->requiredFiles))
            return false;
    }
    if (that->directoriesToMake != NULL)
    {
        directoriesToMake = new DirectoriesAndFiles();
        if (!directoriesToMake->deepCopyFrom(that->directoriesToMake))
            return false;
    }
    if (that->filesToMake != NULL)
    {
        filesToMake = new DirectoriesAndFiles();
        if (!filesToMake->deepCopyFrom(that->filesToMake))
            return false;
    }
    if (that->inputDirectoriesToMove != NULL)
    {
        inputDirectoriesToMove = new PathPairs();
        if (!inputDirectoriesToMove->deepCopyFrom(that->inputDirectoriesToMove))
            return false;
    }
    if (that->inputFilesToMove != NULL)
    {
        inputFilesToMove = new PathPairs();
        if (!inputFilesToMove->deepCopyFrom(that->inputFilesToMove))
            return false;
    }
    if (that->outputFilesToMove != NULL)
    {
        outputFilesToMove = new PathPairs();
        if (!outputFilesToMove->deepCopyFrom(that->outputFilesToMove))
            return false;
    }
    if (that->outputDirectoriesToMove != NULL)
    {
        outputDirectoriesToMove = new PathPairs();
        if (!outputDirectoriesToMove->deepCopyFrom(that->outputDirectoriesToMove))
            return false;
    }
    if (that->filesToDelete != NULL)
    {
        filesToDelete = new DirectoriesAndFiles();
        if (!filesToDelete->deepCopyFrom(that->filesToDelete))
            return false;
    }
    if (that->directoriesToDelete != NULL)
    {
        directoriesToDelete = new DirectoriesAndFiles();
        if (!directoriesToDelete->deepCopyFrom(that->directoriesToDelete))
            return false;
    }
    if (that->processesToKill != NULL)
    {
        processesToKill = new Processes();
        if (!processesToKill->deepCopyFrom(that->processesToKill))
            return false;
    }
    if (that->otherOptions != NULL)
    {
        otherOptions = new OtherOptions();
        if (!otherOptions->deepCopyFrom(that->otherOptions))
            return false;
    }
    return true;
}//JobOption::deepCopyFrom

bool OptimizationOption::deepCopyFrom(OptimizationOption *that)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_trace, "Make deep copy of OptimizationOption");
#endif
    this->numberOfVariables   = that->numberOfVariables;
    this->numberOfObjectives  = that->numberOfObjectives;
    this->numberOfConstraints = that->numberOfConstraints;

    if (that->variables != NULL)
    {
        variables = new VariableOption();
        if (!variables->deepCopyFrom(that->variables))
            return false;
    }
    if (that->objectives != NULL)
    {
        objectives = new ObjectiveOption();
        if (!objectives->deepCopyFrom(that->objectives))
            return false;
    }
    if (that->constraints != NULL)
    {
        constraints = new ConstraintOption();
        if (!constraints->deepCopyFrom(that->constraints))
            return false;
    }
    if (that->solverOptions != NULL)
    {
        solverOptions = new SolverOptions();
        if (!solverOptions->deepCopyFrom(that->solverOptions))
            return false;
    }

    return true;
}//OptimizationOption::deepCopyFrom

bool InstanceLocationOption::deepCopyFrom(InstanceLocationOption *that)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_trace, "Make deep copy of InstanceLocationOption");
#endif
    this->value        = that->value;
    this->locationType = that->locationType;
    return true;
}//InstanceLocationOption::deepCopyFrom

bool ContactOption::deepCopyFrom(ContactOption *that)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_trace, "Make deep copy of ContactOption");
#endif
    this->value         = that->value;
    this->transportType = that->transportType;
    return true;
}//ContactOption::deepCopyFrom

bool OtherOptions::deepCopyFrom(OtherOptions *that)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_trace, "Make deep copy of OtherOptions");
#endif
    int n;

    n = that->numberOfOtherOptions;
    this->numberOfOtherOptions = n;

    if (n  < 0) return false;
    if (n == 0) return true;

    this->other = new OtherOptionOrResult*[n];

    for (int i = 0; i < n; i++)
    {
        this->other[i] = new OtherOptionOrResult();
        if (!this->other[i]->deepCopyFrom(that->other[i]))
            return false;
    }

    return true;
}//OtherOptions::deepCopyFrom


bool JobDependencies::deepCopyFrom(JobDependencies *that)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_trace, "Make deep copy of JobDependencies");
#endif
    int n;

    this->numberOfJobIDs = that->numberOfJobIDs;
    n = this->numberOfJobIDs;

    if (n  < 0) return false;
    if (n == 0) return true;

    this->jobID = new std::string[n];
    for (int i = 0; i < n; i++)
        this->jobID[i] = that->jobID[i];

    return true;
}//JobDependencies::deepCopyFrom

bool DirectoriesAndFiles::deepCopyFrom(DirectoriesAndFiles *that)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_trace, "Make deep copy of DirectoriesAndFiles");
#endif
    int n;

    this->numberOfPaths = that->numberOfPaths;
    n = this->numberOfPaths;

    if (n  < 0) return false;
    if (n == 0) return true;

    this->path = new std::string[n];
    for (int i = 0; i < n; i++)
        this->path[i] = that->path[i];

    return true;
}//DirectoriesAndFiles::deepCopyFrom

bool PathPairs::deepCopyFrom(PathPairs *that)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_trace, "Make deep copy of PathPairs");
#endif
    int n;

    this->numberOfPathPairs = that->numberOfPathPairs;
    n = this->numberOfPathPairs;

    if (n  < 0) return false;
    if (n == 0) return true;

    pathPair = new PathPair*[n];
    for (int i = 0; i < n; i++)
    {
        this->pathPair[i] = new PathPair();
        if (!this->pathPair[i]->deepCopyFrom(that->pathPair[i]))
            return false;
    }

    return true;
}//PathPairs::deepCopyFrom

bool PathPair::deepCopyFrom(PathPair *that)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_trace, "Make deep copy of PathPair");
#endif
    this->from     = that->from;
    this->to       = that->to;
    this->makeCopy = that->makeCopy;
    return true;
}//PathPair::deepCopyFrom

bool Processes::deepCopyFrom(Processes *that)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_trace, "Make deep copy of Processes");
#endif
    int n;

    this->numberOfProcesses = that->numberOfProcesses;
    n = this->numberOfProcesses;

    if (n  < 0) return false;
    if (n == 0) return true;

    process = new std::string[n];
    for (int i = 0; i < n; i++)
        this->process[i] = that->process[i];

    return true;
}//Processes::deepCopyFrom


bool VariableOption::deepCopyFrom(VariableOption *that)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_trace, "Make deep copy of VariableOption");
#endif
    if (that->initialVariableValues != NULL)
    {
        this->initialVariableValues = new InitVariableValues();
        if (!this->initialVariableValues->deepCopyFrom(that->initialVariableValues))
            return false;
    }
    if (that->initialVariableValuesString != NULL)
    {
        this->initialVariableValuesString = new InitVariableValuesString();
        if (!this->initialVariableValuesString->deepCopyFrom(that->initialVariableValuesString))
            return false;
    }
    if (that->initialBasisStatus != NULL)
    {
        this->initialBasisStatus = new BasisStatus();
        if (!this->initialBasisStatus->deepCopyFrom(that->initialBasisStatus))
            return false;
    }
    if (that->integerVariableBranchingWeights != NULL)
    {
        this->integerVariableBranchingWeights = new IntegerVariableBranchingWeights();
        if (!this->integerVariableBranchingWeights->deepCopyFrom(that->integerVariableBranchingWeights))
            return false;
    }
    if (that->sosVariableBranchingWeights != NULL)
    {
        this->sosVariableBranchingWeights = new SOSVariableBranchingWeights();
        if (!this->sosVariableBranchingWeights->deepCopyFrom(that->sosVariableBranchingWeights))
            return false;
    }

    this->numberOfOtherVariableOptions = that->numberOfOtherVariableOptions;
    int n = this->numberOfOtherVariableOptions;

    if (n  < 0) return false;
    if (n == 0) return true;

    this->other = new OtherVariableOptionOrResult*[n];
    for (int i = 0; i < n; i++)
    {
        this->other[i] = new OtherVariableOptionOrResult();
        if (!this->other[i]->deepCopyFrom(that->other[i]))
            return false;
    }
    return true;
}//VariableOption::deepCopyFrom

bool InitVariableValues::deepCopyFrom(InitVariableValues *that)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_trace, "Make deep copy of InitVariableValues");
#endif
    this->numberOfVar = that->numberOfVar;

    int n = this->numberOfVar;

    if (n  < 0) return false;
    if (n == 0) return true;

    this->var = new InitVarValue*[n];
    for (int i = 0; i < n; i++)
    {
        this->var[i] = new InitVarValue();
        if (!this->var[i]->deepCopyFrom(that->var[i]))
            return false;
    }
    return true;
}//InitVariableValues::deepCopyFrom

bool InitVarValue::deepCopyFrom(InitVarValue *that)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_trace, "Make deep copy of InitVarValue");
#endif
    this->idx   = that->idx;
    this->name  = that->name;
    this->value = that->value;
    return true;
}//InitVarValue::deepCopyFrom


bool InitVariableValuesString::deepCopyFrom(InitVariableValuesString *that)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_trace, "Make deep copy of InitVariableValuesString");
#endif
    this->numberOfVar = that->numberOfVar;
    int n = this->numberOfVar;

    if (n  < 0) return false;
    if (n == 0) return true;

    this->var = new InitVarValueString*[n];
    for (int i = 0; i < n; i++)
    {
        this->var[i] = new InitVarValueString();
        if (!this->var[i]->deepCopyFrom(that->var[i]))
            return false;
    }
    return true;
}//InitVariableValuesString::deepCopyFrom

bool InitVarValueString::deepCopyFrom(InitVarValueString *that)
{

#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_trace, "Make deep copy of InitVarValueString");
#endif
    this->idx   = that->idx;
    this->name  = that->name;
    this->value = that->value;
    return true;
}//InitVarValueString::deepCopyFrom


bool IntegerVariableBranchingWeights::deepCopyFrom(IntegerVariableBranchingWeights *that)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_trace, "Make deep copy of IntegerVariableBranchingWeights");
#endif
    this->numberOfVar = that->numberOfVar;
    int n = this->numberOfVar;

    if (n  < 0) return false;
    if (n == 0) return true;

    this->var = new BranchingWeight*[n];
    for (int i = 0; i < n; i++)
    {
        this->var[i] = new BranchingWeight();
        if (!this->var[i]->deepCopyFrom(that->var[i]))
            return false;
    }
    return true;
}//IntegerVariableBranchingWeights::deepCopyFrom

bool SOSVariableBranchingWeights::deepCopyFrom(SOSVariableBranchingWeights *that)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_trace, "Make deep copy of SOSVariableBranchingWeights");
#endif
    this->numberOfSOS = that->numberOfSOS;
    int n = this->numberOfSOS;

    if (n  < 0) return false;
    if (n == 0) return true;

    this->sos = new SOSWeights*[n];
    for (int i = 0; i < n; i++)
    {
        this->sos[i] = new SOSWeights();
        if (!this->sos[i]->deepCopyFrom(that->sos[i]))
            return false;
    }
    return true;
}//SOSVariableBranchingWeights::deepCopyFrom


bool SOSWeights::deepCopyFrom(SOSWeights *that)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_trace, "Make deep copy of SOSWeights");
#endif
    this->sosIdx      = that->sosIdx;
    this->groupWeight = that->groupWeight;

    this->numberOfVar = that->numberOfVar;
    int n = this->numberOfVar;

    if (n  < 0) return false;
    if (n == 0) return true;

    this->var = new BranchingWeight*[n];
    for (int i = 0; i < n; i++)
    {
        this->var[i] = new BranchingWeight();
        if (!this->var[i]->deepCopyFrom(that->var[i]))
            return false;
    }
    return true;
}//SOSWeights::deepCopyFrom


bool BranchingWeight::deepCopyFrom(BranchingWeight *that)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_trace, "Make deep copy of BranchingWeight");
#endif
    this->idx   = that->idx;
    this->name  = that->name;
    this->value = that->value;
    return true;
}//BranchingWeight::deepCopyFrom


bool ObjectiveOption::deepCopyFrom(ObjectiveOption *that)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_trace, "Make deep copy of ObjectiveOption");
#endif
    if (that->initialObjectiveValues != NULL)
    {
        this->initialObjectiveValues = new InitObjectiveValues();
        if (!this->initialObjectiveValues->deepCopyFrom(that->initialObjectiveValues))
            return false;
    }
    if (that->initialObjectiveBounds != NULL)
    {
        this->initialObjectiveBounds = new InitObjectiveBounds();
        if (!this->initialObjectiveBounds->deepCopyFrom(that->initialObjectiveBounds))
            return false;
    }
    if (that->initialBasisStatus != NULL)
    {
        this->initialBasisStatus = new BasisStatus();
        if (!this->initialBasisStatus->deepCopyFrom(that->initialBasisStatus))
            return false;
    }

    this->numberOfOtherObjectiveOptions = that->numberOfOtherObjectiveOptions;
    int n = this->numberOfOtherObjectiveOptions;

    if (n  < 0) return false;
    if (n == 0) return true;

    this->other = new OtherObjectiveOptionOrResult*[n];
    for (int i = 0; i < n; i++)
    {
        this->other[i] = new OtherObjectiveOptionOrResult();
        if (!this->other[i]->deepCopyFrom(that->other[i]))
            return false;
    }
    return true;
}//ObjectiveOption::deepCopyFrom

bool InitObjectiveValues::deepCopyFrom(InitObjectiveValues *that)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_trace, "Make deep copy of InitObjectiveValues");
#endif
    this->numberOfObj = that->numberOfObj;
    int n = this->numberOfObj;

    if (n  < 0) return false;
    if (n == 0) return true;

    this->obj = new InitObjValue*[n];
    for (int i = 0; i < n; i++)
    {
        this->obj[i] = new InitObjValue();
        if (!this->obj[i]->deepCopyFrom(that->obj[i]))
            return false;
    }
    return true;
}//InitObjectiveValues::deepCopyFrom

bool InitObjValue::deepCopyFrom(InitObjValue *that)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_trace, "Make deep copy of InitObjValue");
#endif
    this->idx   = that->idx;
    this->name  = that->name;
    this->value = that->value;
    return true;
}//InitObjValue::deepCopyFrom

bool InitObjectiveBounds::deepCopyFrom(InitObjectiveBounds *that)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_trace, "Make deep copy of InitObjectiveBounds");
#endif
    this->numberOfObj = that->numberOfObj;
    int n = this->numberOfObj;

    if (n  < 0) return false;
    if (n == 0) return true;

    this->obj = new InitObjBound*[n];
    for (int i = 0; i < n; i++)
    {
        this->obj[i] = new InitObjBound();
        if (!this->obj[i]->deepCopyFrom(that->obj[i]))
            return false;
    }
    return true;
}//InitObjectiveBounds::deepCopyFrom

bool InitObjBound::deepCopyFrom(InitObjBound *that)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_trace, "Make deep copy of InitObjBound");
#endif
    this->idx     = that->idx;
    this->name    = that->name;
    this->lbValue = that->lbValue;
    this->ubValue = that->ubValue;
    return true;
}//InitObjBound::deepCopyFrom

#if 0
bool OtherObjectiveOption::deepCopyFrom(OtherObjectiveOption *that)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_trace, "Make deep copy of OtherObjectiveOption");
#endif
    this->name        = that->name;
    this->value       = that->value;
    this->solver      = that->solver;
    this->category    = that->category;
    this->type        = that->type;
    this->objType     = that->objType;
    this->enumType    = that->enumType;
    this->description = that->description;

    int n;

    this->numberOfObj = that->numberOfObj;

    n = this->numberOfObj;

    if (n < 0) return false;
    if (n > 0)
    {
        this->obj = new OtherObjOption*[n];
        for (int i = 0; i < n; i++)
        {
            this->obj[i] = new OtherObjOption();
            if (!this->obj[i]->deepCopyFrom(that->obj[i]))
                return false;
        }
    }

    this->numberOfEnumerations = that->numberOfEnumerations;
    n = this->numberOfEnumerations;

    if (n < 0) return false;
    if (n > 0)
    {
        this->enumeration = new OtherOptionOrResultEnumeration*[n];
        for (int i = 0; i < n; i++)
        {
            this->enumeration[i] = new OtherOptionOrResultEnumeration();
            if (!this->enumeration[i]->deepCopyFrom(that->enumeration[i]))
                return false;
        }
    }
    return true;
}//OtherObjectiveOption::deepCopyFrom

bool OtherObjOption::deepCopyFrom(OtherObjOption *that)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_trace, "Make deep copy of OtherObjOption");
#endif
    this->idx     = that->idx;
    this->name    = that->name;
    this->value   = that->value;
    this->lbValue = that->lbValue;
    this->ubValue = that->ubValue;
    return true;
}//OtherObjOption::deepCopyFrom
#endif

bool ConstraintOption::deepCopyFrom(ConstraintOption *that)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_trace, "Make deep copy of ConstraintOption");
#endif
    if (that->initialConstraintValues != NULL)
    {
        this->initialConstraintValues = new InitConstraintValues();
        if (!this->initialConstraintValues->deepCopyFrom(that->initialConstraintValues))
            return false;
    }
    if (that->initialDualValues != NULL)
    {
        this->initialDualValues = new InitDualVariableValues();
        if (!this->initialDualValues->deepCopyFrom(that->initialDualValues))
            return false;
    }
    if (that->initialBasisStatus != NULL)
    {
        this->initialBasisStatus = new BasisStatus();
        if (!this->initialBasisStatus->deepCopyFrom(that->initialBasisStatus))
            return false;
    }

    this->numberOfOtherConstraintOptions = that->numberOfOtherConstraintOptions;
    int n = this->numberOfOtherConstraintOptions;

    if (n  < 0) return false;
    if (n == 0) return true;

    this->other = new OtherConstraintOptionOrResult*[n];
    for (int i = 0; i < n; i++)
    {
        this->other[i] = new OtherConstraintOptionOrResult();
        if (!this->other[i]->deepCopyFrom(that->other[i]))
            return false;
    }
    return true;
}//ConstraintOption::deepCopyFrom

bool InitConstraintValues::deepCopyFrom(InitConstraintValues *that)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_trace, "Make deep copy of InitConstraintValues");
#endif
    this->numberOfCon = that->numberOfCon;
    int n = this->numberOfCon;

    if (n  < 0) return false;
    if (n == 0) return true;

    this->con = new InitConValue*[n];
    for (int i = 0; i < n; i++)
    {
        this->con[i] = new InitConValue();
        if (!this->con[i]->deepCopyFrom(that->con[i]))
            return false;
    }
    return true;
}//InitConstraintValues::deepCopyFrom

bool InitConValue::deepCopyFrom(InitConValue *that)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_trace, "Make deep copy of InitConValue");
#endif
    this->idx   = that->idx;
    this->name  = that->name;
    this->value = that->value;
    return true;
}//InitConValue::deepCopyFrom

bool InitDualVariableValues::deepCopyFrom(InitDualVariableValues *that)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_trace, "Make deep copy of InitDualVariableValues");
#endif
    this->numberOfCon = that->numberOfCon;
    int n = this->numberOfCon;

    if (n  < 0) return false;
    if (n == 0) return true;

    this->con = new InitDualVarValue*[n];
    for (int i = 0; i < n; i++)
    {
        this->con[i] = new InitDualVarValue();
        if (!this->con[i]->deepCopyFrom(that->con[i]))
            return false;
    }
    return true;
}//InitDualVariableValues::deepCopyFrom

bool InitDualVarValue::deepCopyFrom(InitDualVarValue *that)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_trace, "Make deep copy of InitDualVarValue");
#endif
    this->idx         = that->idx;
    this->name        = that->name;
    this->lbDualValue = that->lbDualValue;
    this->ubDualValue = that->ubDualValue;
    return true;
}//InitDualVarValue::deepCopyFrom

#if 0
bool OtherConstraintOption::deepCopyFrom(OtherConstraintOption *that)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_trace, "Make deep copy of OtherConstraintOption");
#endif
    this->name        = that->name;
    this->value       = that->value;
    this->solver      = that->solver;
    this->category    = that->category;
    this->type        = that->type;
    this->conType     = that->conType;
    this->enumType    = that->enumType;
    this->description = that->description;

    int n;

    this->numberOfCon = that->numberOfCon;
    n = this->numberOfCon;

    if (n < 0) return false;
    if (n > 0)
    {
        this->con = new OtherConOption*[n];
        for (int i = 0; i < n; i++)
        {
            this->con[i] = new OtherConOption();
            if (!this->con[i]->deepCopyFrom(that->con[i]))
                return false;
        }
    }

    this->numberOfEnumerations = that->numberOfEnumerations;
    n = this->numberOfEnumerations;

    if (n < 0) return false;
    if (n > 0)
    {
        this->enumeration = new OtherOptionOrResultEnumeration*[n];
        for (int i = 0; i < n; i++)
        {
            this->enumeration[i] = new OtherOptionOrResultEnumeration();
            if (!this->enumeration[i]->deepCopyFrom(that->enumeration[i]))
                return false;
        }
    }
    return true;
}//OtherConstraintOption::deepCopyFrom

bool OtherConOption::deepCopyFrom(OtherConOption *that)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_trace, "Make deep copy of OtherConOption");
#endif
    this->idx     = that->idx;
    this->name    = that->name;
    this->value   = that->value;
    this->lbValue = that->lbValue;
    this->ubValue = that->ubValue;
    return true;
}//OtherConOption::deepCopyFrom
#endif

bool SolverOptions::deepCopyFrom(SolverOptions *that)
{
#ifndef NDEBUG
    osoutput->OSPrint(ENUM_OUTPUT_AREA_OSOption, ENUM_OUTPUT_LEVEL_trace, "Make deep copy of SolverOptions");
#endif
    this->numberOfSolverOptions = that->numberOfSolverOptions;
    int n = this->numberOfSolverOptions;

    if (n  < 0) return false;
    if (n == 0) return true;

    this->solverOption = new SolverOptionOrResult*[n];
    for (int i = 0; i < n; i++)
    {
        this->solverOption[i] = new SolverOptionOrResult();
        if (!this->solverOption[i]->deepCopyFrom(that->solverOption[i]))
            return false;
    }
    return true;
}//SolverOptions::deepCopyFrom

