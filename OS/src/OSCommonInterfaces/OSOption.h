/** @file OSOption.h
 * 
 *
 * @author  Gus Gassmann, Jun Ma, Kipp Martin, 
 * @version 1.0, 21/July/2008
 * @since   OS1.1
 *
 * \remarks
 * Copyright (C) 2005-2008, Robert Fourer, Gus Gassmann, Jun Ma, Kipp Martin,
 * Northwestern University, Dalhousie University and the University of Chicago.
 * All Rights Reserved.
 * This software is licensed under the Common Public License. 
 * Please see the accompanying LICENSE file in root directory for terms.
 * 
 */

#ifndef OSOPTION_H
#define OSOPTION_H
//#define DEBUG
#include <string>
#include <vector> 
#include <string>

/*! \class InstanceLocationOption
 *  \brief the InstanceLocationOption class.
 * 
 * @author Robert Fourer, Gus Gassmann, Jun Ma, Kipp Martin
 * @version 1.0, 21/07/2008
 * @since OS 1.1
 * 
 * \remarks
 * A data structure class that corresponds to the instanceLocation 
 * element in the OSoL schema.  
 */
class InstanceLocationOption {

public:
	/** the type of the location */
	std::string locationType;

	/** the value of the <instanceLocation> element */
	std::string value;

	/**
	 *
	 * Default constructor. 
	 */
	InstanceLocationOption();
	/**
	 *
	 * Class destructor. 
	 */
	~InstanceLocationOption();
}; //InstanceLocationOption


/*! \class ContactOption
 *  \brief the ContactOption class.
 * 
 * @author Robert Fourer, Gus Gassmann, Jun Ma, Kipp Martin
 * @version 1.0, 21/07/2008
 * @since OS 1.1
 * 
 * \remarks
 * A data structure class that corresponds to the contact method 
 * in the OSoL schema.  
 */
class ContactOption {

public:
	/** the contact mechanism */
	std::string transportType;

	/** the value of the <contact> element */
	std::string value;

	/**
	 *
	 * Default constructor. 
	 */
	ContactOption();
	/**
	 *
	 * Class destructor. 
	 */
	~ContactOption();		
}; //ContactOption


/*! \class OtherOption
 *  \brief the OtherOption class.
 * 
 * @author Robert Fourer, Gus Gassmann, Jun Ma, Kipp Martin
 * @version 1.0, 21/07/2008
 * @since OS 1.1
 * 
 * \remarks
 * A data structure class that corresponds to the OtherOption
 * element in the OSoL schema.  
 */
class OtherOption {

public:
	/** the name of the option */
	std::string name;

	/** the value of the option */
	std::string value;

	/** the description of the option */
	std::string description;
 
	/**
	 *
	 * Default constructor. 
	 */
	OtherOption();
	/**
	 *
	 * Class destructor. 
	 */
	~OtherOption();
}; //OtherOption


/*! \class OtherOptions
 *  \brief the OtherOptions class.
 * 
 * @author Robert Fourer, Gus Gassmann, Jun Ma, Kipp Martin
 * @version 1.0, 21/07/2008
 * @since OS 1.1
 * 
 * \remarks
 * A data structure class that corresponds to the OtherOptions 
 * element in the OSoL schema.  
 */
class OtherOptions {

public:
	/** the number of other options */
	int numberOfOtherOptions;
 
	/** the list of other options */
	OtherOption **other;

	/**
	 *
	 * Default constructor. 
	 */
	OtherOptions();
	/**
	 *
	 * Class destructor. 
	 */
	~OtherOptions();
}; //OtherOptions


/*! \class GeneralOption
 *  \brief The GeneralOption Class.
 * 
 * @author Robert Fourer, Gus Gassmann, Jun Ma, Kipp Martin
 * @version 1.0, 21/07/2008
 * @since OS 1.1
 * 
 * \remarks
 * A data structure class that corresponds to an xml element in 
 * the OSoL schema.  
 */
class GeneralOption {

public:

	/** the service URI */	
	std::string serviceURI;
	
	/** the name of the service */	
	std::string serviceName;

	/** the name of the instance */
	std::string instanceName;

	/** the location of the instance */
	InstanceLocationOption *instanceLocation;

	/** the job ID */
	std::string jobID;

	/** the solver to invoke */
	std::string solverToInvoke;

	/** the license information */
	std::string license;

	/** the username */
	std::string userName;

	/** the password */
	std::string password;

	/** the contact method */
	ContactOption *contact;

	/** the list of other general options */
	OtherOptions *otherOptions;

	/**
	 *
	 * Default constructor. 
	 */
	GeneralOption();
	/**
	 *
	 * Class destructor. 
	 */
	~GeneralOption();		
};//GeneralOption

/*! \class MinDiskSpace
 *  \brief the MinDiskSpace class.
 * 
 * @author Robert Fourer, Gus Gassmann, Jun Ma, Kipp Martin
 * @version 1.0, 21/07/2008
 * @since OS 1.1
 * 
 * \remarks
 * A data structure class that corresponds to an xml element in 
 * the OSoL schema.  
 */
class MinDiskSpace {

public:
	/** the unit in which disk space is measured */
	std::string unit;

	/** the minimum disk space required */
	double value;


	/**
	 *
	 * Default constructor. 
	 */
	MinDiskSpace();
	/**
	 *
	 * Class destructor. 
	 */
	~MinDiskSpace();
}; //MinDiskSpace

/*! \class MinMemorySize
 *  \brief the MinMemorySize class.
 * 
 * @author Robert Fourer, Gus Gassmann, Jun Ma, Kipp Martin
 * @version 1.0, 21/07/2008
 * @since OS 1.1
 * 
 * \remarks
 * A data structure class that corresponds to an xml element in 
 * the OSoL schema.  
 */
class MinMemorySize {

public:
	/** the unit in which memory size is measured */
	std::string unit;

	/** the minimum memory size required */
	double value;


	/**
	 *
	 * Default constructor. 
	 */
	MinMemorySize();
	/**
	 *
	 * Class destructor. 
	 */
	~MinMemorySize();
}; //MinMemorySize

/*! \class MinCPUSpeed
 *  \brief the MinCPUSpeed class.
 * 
 * @author Robert Fourer, Gus Gassmann, Jun Ma, Kipp Martin
 * @version 1.0, 21/07/2008
 * @since OS 1.1
 * 
 * \remarks
 * A data structure class that corresponds to an xml element in 
 * the OSoL schema.  
 */
class MinCPUSpeed {

public:
	/** the unit in which CPU speed is measured */
	std::string unit;

	/** the minimum CPU speed required */
	double value;


	/**
	 *
	 * Default constructor. 
	 */
	MinCPUSpeed();
	/**
	 *
	 * Class destructor. 
	 */
	~MinCPUSpeed();
}; //MinCPUSpeed


/*! \class SystemOption
 *  \brief the SystemOption class.
 * 
 * @author Robert Fourer, Gus Gassmann, Jun Ma, Kipp Martin
 * @version 1.0, 21/07/2008
 * @since OS 1.1
 * 
 * \remarks
 * A data structure class that corresponds to an xml element in 
 * the OSoL schema.  
 */
class SystemOption {

public:
	/** the minimum disk space required */
	MinDiskSpace *minDiskSpace;

	/** the minimum memory required */
	MinMemorySize *minMemorySize;

	/** the minimum CPU speed required */
	MinCPUSpeed *minCPUSpeed;

	/** the minimum number of processors required */
	int minCPUNumber;

	/** the list of other system options */
	OtherOptions *otherOptions;

	/**
	 *
	 * Default constructor. 
	 */
	SystemOption();
	/**
	 *
	 * Class destructor. 
	 */
	~SystemOption();
}; //SystemOption


/*! \class ServiceOption
 *  \brief the ServiceOption class.
 * 
 * @author Robert Fourer, Gus Gassmann, Jun Ma, Kipp Martin
 * @version 1.0, 21/07/2008
 * @since OS 1.1
 * 
 * \remarks
 * A data structure class that corresponds to an xml element in 
 * the OSoL schema.  
 */
class ServiceOption {

public:
	/** the service type */
	std::string type;

	/** the list of other service options */
	OtherOptions *otherOptions;

	/**
	 *
	 * Default constructor. 
	 */
	ServiceOption();
	/**
	 *
	 * Class destructor. 
	 */
	~ServiceOption();
}; //ServiceOption


/*! \class MaxTime
 *  \brief the MaxTime class.
 * 
 * @author Robert Fourer, Gus Gassmann, Jun Ma, Kipp Martin
 * @version 1.0, 21/07/2008
 * @since OS 1.1
 * 
 * \remarks
 * A data structure class that corresponds to an xml element in 
 * the OSoL schema.  
 */
class MaxTime {

public:
	/** the unit in which time is measured */
	std::string unit;

	/** the maximum time allowed */
	double value;


	/**
	 *
	 * Default constructor. 
	 */
	MaxTime();
	/**
	 *
	 * Class destructor. 
	 */
	~MaxTime();
}; //MaxTime


/*! \class JobDependencies
 *  \brief the JobDependencies class.
 * 
 * @author Robert Fourer, Gus Gassmann, Jun Ma, Kipp Martin
 * @version 1.0, 21/07/2008
 * @since OS 1.1
 * 
 * \remarks
 * A data structure class that corresponds to an xml element in 
 * the OSoL schema.  
 */
class JobDependencies {

public:
	/** the number of entries in the list of job dependencies */
	int numberOfJobIDs;

	/** the list of job IDs */
	std::string *jobID;

	/**
	 *
	 * Default constructor. 
	 */
	JobDependencies();
	/**
	 *
	 * Class destructor. 
	 */
	~JobDependencies();
}; //JobDependencies


/*! \class DirectoriesAndFiles
 *  \brief the DirectoriesAndFiles class.
 * 
 * @author Robert Fourer, Gus Gassmann, Jun Ma, Kipp Martin
 * @version 1.0, 21/07/2008
 * @since OS 1.1
 * 
 * \remarks
 * A data structure class that corresponds to an xml element in 
 * the OSoL schema.  
 */
class DirectoriesAndFiles {

public:
	/** the number of <path> children */
	int numberOfPaths;

	/** the list of directory and file paths */
	std::string *path;

	/**
	 *
	 * Default constructor. 
	 */
	DirectoriesAndFiles();
	/**
	 *
	 * Class destructor. 
	 */
	~DirectoriesAndFiles();
}; //DirectoriesAndFiles



/*! \class PathPair
 *  \brief the PathPair class.
 * 
 * @author Robert Fourer, Gus Gassmann, Jun Ma, Kipp Martin
 * @version 1.0, 21/07/2008
 * @since OS 1.1
 * 
 * \remarks
 * A data structure class that corresponds to an xml element in 
 * the OSoL schema.  
 */
class PathPair {

public:
	/** the file or directory to move/copy from */
	std::string from;

	/** the file or directory to move/copy to */
	std::string to;

	/** record whether a copy is to be made */
	bool makeCopy;

	/**
	 *
	 * Default constructor. 
	 */
	PathPair();
	/**
	 *
	 * Class destructor. 
	 */
	~PathPair();
}; //PathPair



/*! \class PathPairs
 *  \brief the PathPairs class.
 * 
 * @author Robert Fourer, Gus Gassmann, Jun Ma, Kipp Martin
 * @version 1.0, 21/07/2008
 * @since OS 1.1
 * 
 * \remarks
 * A data structure class that corresponds to an xml element in 
 * the OSoL schema.  
 */
class PathPairs {

public:
	/** the number of <path> children */
	int numberOfPathPairs;

	/** the list of directory and file paths */
	PathPair **pathPair;

	/**
	 *
	 * Default constructor. 
	 */
	PathPairs();
	/**
	 *
	 * Class destructor. 
	 */
	~PathPairs();
}; //PathPairs


/*! \class Processes
 *  \brief the Processes class.
 * 
 * @author Robert Fourer, Gus Gassmann, Jun Ma, Kipp Martin
 * @version 1.0, 21/07/2008
 * @since OS 1.1
 * 
 * \remarks
 * A data structure class that corresponds to an xml element in 
 * the OSoL schema.  
 */
class Processes {

public:
	/** the number of <process> children */
	int numberOfProcesses;

	/** the list of processes */
	std::string *process;

	/**
	 *
	 * Default constructor. 
	 */
	Processes();
	/**
	 *
	 * Class destructor. 
	 */
	~Processes();		
}; //Processes


/*! \class JobOption
 *  \brief the JobOption class.
 * 
 * @author Robert Fourer, Gus Gassmann, Jun Ma, Kipp Martin
 * @version 1.0, 21/07/2008
 * @since OS 1.1
 * 
 * \remarks
 * A data structure class that corresponds to an xml element in 
 * the OSoL schema.  
 */
class JobOption {

public:
	/** the maximum time allowed */
	MaxTime *maxTime;

	/** the scheduled time to start the job */
	std::string scheduledStartTime;

	/** the dependency set */
	JobDependencies *dependencies;

	/** directories  required to run the job */
	DirectoriesAndFiles *requiredDirectories;

	/** files required to run the job */
	DirectoriesAndFiles *requiredFiles;

	/** directories to make during the job */
	DirectoriesAndFiles *directoriesToMake;

	/** files to make during the job */
	DirectoriesAndFiles *filesToMake;

	/** input directories to move or copy */
	PathPairs *inputDirectoriesToMove;

	/** input files to move or copy */
	PathPairs *inputFilesToMove;

	/** output files to move or copy */
	PathPairs *outputFilesToMove;

	/** output directories to move or copy */
	PathPairs *outputDirectoriesToMove;

	/** files to delete upon completeion */
	DirectoriesAndFiles *filesToDelete;

	/** directories to delete upon completion */
	DirectoriesAndFiles *directoriesToDelete;

	/** processes to kill upon completion */
	Processes *processesToKill;

	/** list of other job options */
	OtherOptions *otherOptions;

	/**
	 *
	 * Default constructor. 
	 */
	JobOption();
	/**
	 *
	 * Class destructor. 
	 */
	~JobOption();		
}; //JobOption


/*! \class InitVarValue
 *  \brief the InitVarValue class.
 * 
 * @author Robert Fourer, Gus Gassmann, Jun Ma, Kipp Martin
 * @version 1.0, 21/07/2008
 * @since OS 1.1
 * 
 * \remarks
 * A data structure class that corresponds to an xml element in 
 * the OSoL schema.  
 */
class InitVarValue {

public:
	/** variable index */
	int idx;

	/** initial value */
	double value;

	/**
	 *
	 * Default constructor. 
	 */
	InitVarValue();
	/**
	 *
	 * Class destructor. 
	 */
	~InitVarValue();		
}; //InitVarValue


/*! \class InitVariableValues
 *  \brief the InitVariableValues class.
 * 
 * @author Robert Fourer, Gus Gassmann, Jun Ma, Kipp Martin
 * @version 1.0, 21/07/2008
 * @since OS 1.1
 * 
 * \remarks
 * A data structure class that corresponds to an xml element in 
 * the OSoL schema.  
 */
class InitVariableValues {

public:
	/** number of <var> children */
	int numberOfVar;

	/** initial value for each variable */
	InitVarValue **var;

	/**
	 *
	 * Default constructor. 
	 */
	InitVariableValues();
	/**
	 *
	 * Class destructor. 
	 */
	~InitVariableValues();
}; //InitVariableValues


/*! \class InitVarValueString
 *  \brief the InitVarValueString class.
 * 
 * @author Robert Fourer, Gus Gassmann, Jun Ma, Kipp Martin
 * @version 1.0, 21/07/2008
 * @since OS 1.1
 * 
 * \remarks
 * A data structure class that corresponds to an xml element in 
 * the OSoL schema.  
 */
class InitVarValueString {

public:
	/** variable index */
	int idx;

	/** initial value */
	std::string value;

	/**
	 *
	 * Default constructor. 
	 */
	InitVarValueString();
	/**
	 *
	 * Class destructor. 
	 */
	~InitVarValueString();		
}; //InitVarValueString


/*! \class InitVariableValuesString
 *  \brief the InitVariableValuesString class.
 * 
 * @author Robert Fourer, Gus Gassmann, Jun Ma, Kipp Martin
 * @version 1.0, 21/07/2008
 * @since OS 1.1
 * 
 * \remarks
 * A data structure class that corresponds to an xml element in 
 * the OSoL schema.  
 */
class InitVariableValuesString {

public:
	/** number of <var> children */
	int numberOfVar;

	/** initial value for each variable */
	InitVarValueString **var;

	/**
	 *
	 * Default constructor. 
	 */
	InitVariableValuesString();
	/**
	 *
	 * Class destructor. 
	 */
	~InitVariableValuesString();
}; //InitVariableValuesString

/*! \class InitBasStatus
 *  \brief the InitBasStatus class.
 * 
 * @author Robert Fourer, Gus Gassmann, Jun Ma, Kipp Martin
 * @version 1.0, 21/07/2008
 * @since OS 1.1
 * 
 * \remarks
 * A data structure class that corresponds to an xml element in 
 * the OSoL schema.  
 */
class InitBasStatus {

public:
	/** variable index */
	int idx;

	/** initial value */
	std::string value;

	/**
	 *
	 * Default constructor. 
	 */
	InitBasStatus();
	/**
	 *
	 * Class destructor. 
	 */
	~InitBasStatus();		
}; //InitBasStatus


/*! \class InitialBasisStatus
 *  \brief the InitialBasisStatus class.
 * 
 * @author Robert Fourer, Gus Gassmann, Jun Ma, Kipp Martin
 * @version 1.0, 21/07/2008
 * @since OS 1.1
 * 
 * \remarks
 * A data structure class that corresponds to an xml element in 
 * the OSoL schema.  
 */
class InitialBasisStatus {

public:
	/** number of <var> children */
	int numberOfVar;

	/** initial value for each variable */
	InitBasStatus **var;

	/**
	 *
	 * Default constructor. 
	 */
	InitialBasisStatus();
	/**
	 *
	 * Class destructor. 
	 */
	~InitialBasisStatus();
}; //InitialBasisStatus

/*! \class BranchingWeight
 *  \brief the BranchingWeight class.
 * 
 * @author Robert Fourer, Gus Gassmann, Jun Ma, Kipp Martin
 * @version 1.0, 21/11/2008
 * @since OS 1.1
 * 
 * \remarks
 * A data structure class that corresponds to an xml element in 
 * the OSoL schema.  
 */
class BranchingWeight {

public:
	/** index of the variable */
	int idx;

	/** branching weight */
	double value;

	/**
	 *
	 * Default constructor. 
	 */
	BranchingWeight();
	/**
	 *
	 * Class destructor. 
	 */
	~BranchingWeight();
}; //BranchingWeight



/*! \class IntegerVariableBranchingWeights
 *  \brief the IntegerVariableBranchingWeights class.
 * 
 * @author Robert Fourer, Gus Gassmann, Jun Ma, Kipp Martin
 * @version 1.0, 21/11/2008
 * @since OS 1.1
 * 
 * \remarks
 * A data structure class that corresponds to an xml element in 
 * the OSoL schema.  
 */
class IntegerVariableBranchingWeights {

public:
	/** number of <var> children */
	int numberOfVar;

	/** branching weight for each variable */
	BranchingWeight **var;

	/**
	 *
	 * Default constructor. 
	 */
	IntegerVariableBranchingWeights();
	/**
	 *
	 * Class destructor. 
	 */
	~IntegerVariableBranchingWeights();
}; //IntegerVariableBranchingWeights

/*! \class SOSWeights
 *  \brief the SOSWeights class.
 * 
 * @author Robert Fourer, Gus Gassmann, Jun Ma, Kipp Martin
 * @version 1.0, 21/11/2008
 * @since OS 1.1
 * 
 * \remarks
 * A data structure class that corresponds to an xml element in 
 * the OSoL schema.  
 */
class SOSWeights {

public:
	/** index of the SOS (to match the OSiL file) */
	int sosIdx;

	/** branching weight for the entire SOS */
	double groupWeight;

	/** number of <var> children */
	int numberOfVar;

	/** branching weights for individual variables */
	BranchingWeight **var;

	/**
	 *
	 * Default constructor. 
	 */
	SOSWeights();
	/**
	 *
	 * Class destructor. 
	 */
	~SOSWeights();
}; //SOSWeights


/*! \class SOSVariableBranchingWeights
 *  \brief the SOSVariableBranchingWeights class.
 * 
 * @author Robert Fourer, Gus Gassmann, Jun Ma, Kipp Martin
 * @version 1.0, 21/11/2008
 * @since OS 1.1
 * 
 * \remarks
 * A data structure class that corresponds to an xml element in 
 * the OSoL schema.  
 */
class SOSVariableBranchingWeights {

public:
	/** number of <sos> children */
	int numberOfSOS;

	/** branching weights for the SOS */
	SOSWeights **sos;

	/**
	 *
	 * Default constructor. 
	 */
	SOSVariableBranchingWeights();
	/**
	 *
	 * Class destructor. 
	 */
	~SOSVariableBranchingWeights();
}; //SOSVariableBranchingWeights

/*! \class OtherVarOption
 *  \brief the OtherVarOption class.
 * 
 * @author Robert Fourer, Gus Gassmann, Jun Ma, Kipp Martin
 * @version 1.0, 21/07/2008
 * @since OS 1.1
 * 
 * \remarks
 * A data structure class that corresponds to an xml element in 
 * the OSoL schema.  
 */
class OtherVarOption {

public:
	/** variable index*/
	int idx;

	/** value of the option */
	std::string value;

	/** lower bound on the value */
	std::string lbValue;

	/** lower bound on the value */
	std::string ubValue;

	/**
	 *
	 * Default constructor. 
	 */
	OtherVarOption();
	/**
	 *
	 * Class destructor. 
	 */
	~OtherVarOption();		
}; //OtherVarOption


/*! \class OtherVariableOption
 *  \brief the OtherVariableOption class.
 * 
 * @author Robert Fourer, Gus Gassmann, Jun Ma, Kipp Martin
 * @version 1.0, 21/07/2008
 * @since OS 1.1
 * 
 * \remarks
 * A data structure class that corresponds to an xml element in 
 * the OSoL schema.  
 */
class OtherVariableOption {

public:
	/** number of <var> child elements */
	int numberOfVar;

	/** name of the option */
	std::string name;

	/** value of the option */
	std::string value;

	/** name of the solver to which this option applies */
	std::string solver;

	/** name of the category into which this option falls */
	std::string category;

	/** type of the option value (integer, double, boolean, string) */
	std::string type;

	/** description of the option */
	std::string description;

	/** array of option values */
	OtherVarOption **var;

	/**
	 *
	 * Default constructor. 
	 */
	OtherVariableOption();
	/**
	 *
	 * Class destructor. 
	 */
	~OtherVariableOption();		
}; //OtherVariableOption


/*! \class VariableOption
 *  \brief the VariableOption class.
 * 
 * @author Robert Fourer, Gus Gassmann, Jun Ma, Kipp Martin
 * @version 1.0, 21/07/2008
 * @since OS 1.1
 * 
 * \remarks
 * A data structure class that corresponds to an xml element in 
 * the OSoL schema.  
 */
class VariableOption {

public:
	/** number of <other> child elements */
	int numberOfOtherVariableOptions;

	/** initial values for the variables */
	InitVariableValues *initialVariableValues;

	/** initial values for string-valued variables */
	InitVariableValuesString *initialVariableValuesString;

	/** initial basis information*/
	InitialBasisStatus *initialBasisStatus;

	/** branching weights for integer variables */
	IntegerVariableBranchingWeights *integerVariableBranchingWeights;

	/** branching weights for SOS variables and groups */
	SOSVariableBranchingWeights *sosVariableBranchingWeights;

	/** other variable options */
	OtherVariableOption **other;

	/**
	 *
	 * Default constructor. 
	 */
	VariableOption();
	/**
	 *
	 * Class destructor. 
	 */
	~VariableOption();		
}; //VariableOption


/*! \class InitObjValue
 *  \brief the InitObjValue class.
 * 
 * @author Robert Fourer, Gus Gassmann, Jun Ma, Kipp Martin
 * @version 1.0, 21/07/2008
 * @since OS 1.1
 * 
 * \remarks
 * A data structure class that corresponds to an xml element in 
 * the OSoL schema.  
 */
class InitObjValue {

public:
	/** objective index */
	int idx;

	/** initial value */
	double value;

	/**
	 *
	 * Default constructor. 
	 */
	InitObjValue();
	/**
	 *
	 * Class destructor. 
	 */
	~InitObjValue();		
}; //InitObjValue


/*! \class InitObjectiveValues
 *  \brief the InitObjectiveValues class.
 * 
 * @author Robert Fourer, Gus Gassmann, Jun Ma, Kipp Martin
 * @version 1.0, 21/07/2008
 * @since OS 1.1
 * 
 * \remarks
 * A data structure class that corresponds to an xml element in 
 * the OSoL schema.  
 */
class InitObjectiveValues {

public:
	/** number of <obj> children */
	int numberOfObj;

	/** initial value for each objective */
	InitObjValue **obj;

	/**
	 *
	 * Default constructor. 
	 */
	InitObjectiveValues();
	/**
	 *
	 * Class destructor. 
	 */
	~InitObjectiveValues();		
}; //InitObjectiveValues


/*! \class InitObjBound
 *  \brief the InitObjBound class.
 * 
 * @author Robert Fourer, Gus Gassmann, Jun Ma, Kipp Martin
 * @version 1.0, 21/07/2008
 * @since OS 1.1
 * 
 * \remarks
 * A data structure class that corresponds to an xml element in 
 * the OSoL schema.  
 */
class InitObjBound {

public:
	/** objective index */
	int idx;

	/** initial lower bound */
	double lbValue;

	/** initial upper bound */
	double ubValue;

	/**
	 *
	 * Default constructor. 
	 */
	InitObjBound();
	/**
	 *
	 * Class destructor. 
	 */
	~InitObjBound();		
}; //InitObjBound


/*! \class InitObjectiveBounds
 *  \brief the InitObjectiveBounds class.
 * 
 * @author Robert Fourer, Gus Gassmann, Jun Ma, Kipp Martin
 * @version 1.0, 21/07/2008
 * @since OS 1.1
 * 
 * \remarks
 * A data structure class that corresponds to an xml element in 
 * the OSoL schema.  
 */
class InitObjectiveBounds {

public:
	/** number of <obj> children */
	int numberOfObj;

	/** initial bounds for each objective */
	InitObjBound **obj;

	/**
	 *
	 * Default constructor. 
	 */
	InitObjectiveBounds();
	/**
	 *
	 * Class destructor. 
	 */
	~InitObjectiveBounds();		
}; //InitObjectiveBounds


/*! \class OtherObjOption
 *  \brief the OtherObjOption class.
 * 
 * @author Robert Fourer, Gus Gassmann, Jun Ma, Kipp Martin
 * @version 1.0, 21/07/2008
 * @since OS 1.1
 * 
 * \remarks
 * A data structure class that corresponds to an xml element in 
 * the OSoL schema.  
 */
class OtherObjOption {

public:
	/** variable index*/
	int idx;

	/** value of the option */
	std::string value;


	/** lower bound on the value */
	std::string lbValue;

	/** lower bound on the value */
	std::string ubValue;
	/**
	 *
	 * Default constructor. 
	 */
	OtherObjOption();
	/**
	 *
	 * Class destructor. 
	 */
	~OtherObjOption();		
}; //OtherObjOption


/*! \class OtherObjectiveOption
 *  \brief the OtherObjectiveOption class.
 * 
 * @author Robert Fourer, Gus Gassmann, Jun Ma, Kipp Martin
 * @version 1.0, 21/07/2008
 * @since OS 1.1
 * 
 * \remarks
 * A data structure class that corresponds to an xml element in 
 * the OSoL schema.  
 */
class OtherObjectiveOption {

public:
	/** number of <obj> children */
	int numberOfObj;

	/** name of the option */
	std::string name;

	/** value of the option */
	std::string value;

	/** name of the solver to which this option applies */
	std::string solver;

	/** name of the category into which this option falls */
	std::string category;

	/** type of the option value (integer, double, boolean, string) */
	std::string type;

	/** description of the option */
	std::string description;

	/** array of option values */
	OtherObjOption **obj;

	/**
	 *
	 * Default constructor. 
	 */
	OtherObjectiveOption();
	/**
	 *
	 * Class destructor. 
	 */
	~OtherObjectiveOption();		
}; //OtherObjectiveOption


/*! \class ObjectiveOption
 *  \brief the ObjectiveOption class.
 * 
 * @author Robert Fourer, Gus Gassmann, Jun Ma, Kipp Martin
 * @version 1.0, 21/07/2008
 * @since OS 1.1
 * 
 * \remarks
 * A data structure class that corresponds to an xml element in 
 * the OSoL schema.  
 */
class ObjectiveOption {

public:
	/** number of <other> child elements */
	int numberOfOtherObjectiveOptions;

	/** initial values for the objectives */
	InitObjectiveValues *initialObjectiveValues;

	/** initial vounds for the objectives */
	InitObjectiveBounds *initialObjectiveBounds;

	/** other information about the objectives */
	OtherObjectiveOption **other;

	/**
	 *
	 * Default constructor. 
	 */
	ObjectiveOption();
	/**
	 *
	 * Class destructor. 
	 */
	~ObjectiveOption();		
}; //ObjectiveOption


/*! \class InitConValue
 *  \brief the InitConValue class.
 * 
 * @author Robert Fourer, Gus Gassmann, Jun Ma, Kipp Martin
 * @version 1.0, 21/07/2008
 * @since OS 1.1
 * 
 * \remarks
 * A data structure class that corresponds to an xml element in 
 * the OSoL schema.  
 */
class InitConValue {

public:
	/** constraint index */
	int idx;

	/** initial value */
	double value;

	/**
	 *
	 * Default constructor. 
	 */
	InitConValue();
	/**
	 *
	 * Class destructor. 
	 */
	~InitConValue();		
}; //InitConValue


/*! \class InitConstraintValues
 *  \brief the InitConstraintValues class.
 * 
 * @author Robert Fourer, Gus Gassmann, Jun Ma, Kipp Martin
 * @version 1.0, 21/07/2008
 * @since OS 1.1
 * 
 * \remarks
 * A data structure class that corresponds to an xml element in 
 * the OSoL schema.  
 */
class InitConstraintValues {

public:
	/** number of <con> children */
	int numberOfCon;

	/** initial value for each constraint */
	InitConValue **con;

	/**
	 *
	 * Default constructor. 
	 */
	InitConstraintValues();
	/**
	 *
	 * Class destructor. 
	 */
	~InitConstraintValues();		
}; //InitConstraintValues


/*! \class InitDualVarValue
 *  \brief the InitDualVarValue class.
 * 
 * @author Robert Fourer, Gus Gassmann, Jun Ma, Kipp Martin
 * @version 1.0, 21/07/2008
 * @since OS 1.1
 * 
 * \remarks
 * A data structure class that corresponds to an xml element in 
 * the OSoL schema.  
 */
class InitDualVarValue {

public:
	/** objective index */
	int idx;

	/** initial lower bound */
	double lbValue;

	/** initial upper bound */
	double ubValue;

	/**
	 *
	 * Default constructor. 
	 */
	InitDualVarValue();
	/**
	 *
	 * Class destructor. 
	 */
	~InitDualVarValue();		
}; //InitDualVarValue


/*! \class InitDualVariableValues
 *  \brief the InitDualVariableValues class.
 * 
 * @author Robert Fourer, Gus Gassmann, Jun Ma, Kipp Martin
 * @version 1.0, 21/07/2008
 * @since OS 1.1
 * 
 * \remarks
 * A data structure class that corresponds to an xml element in 
 * the OSoL schema.  
 */
class InitDualVariableValues {

public:
	/** number of <con> children */
	int numberOfCon;

	/** initial dual values for each constraint */
	InitDualVarValue **con;

	/**
	 *
	 * Default constructor. 
	 */
	InitDualVariableValues();
	/**
	 *
	 * Class destructor. 
	 */
	~InitDualVariableValues();		
}; //InitDualVariableValues


/*! \class OtherConOption
 *  \brief the OtherConOption class.
 * 
 * @author Robert Fourer, Gus Gassmann, Jun Ma, Kipp Martin
 * @version 1.0, 21/07/2008
 * @since OS 1.1
 * 
 * \remarks
 * A data structure class that corresponds to an xml element in 
 * the OSoL schema.  
 */
class OtherConOption {

public:
	/** variable index*/
	int idx;

	/** value of the option */
	std::string value;

	/** lower bound of the option */
	std::string lbValue;

	/** upper bound of the option */
	std::string ubValue;

	/**
	 *
	 * Default constructor. 
	 */
	OtherConOption();
	/**
	 *
	 * Class destructor. 
	 */
	~OtherConOption();		
}; //OtherConOption


/*! \class OtherConstraintOption
 *  \brief the OtherConstraintOption class.
 * 
 * @author Robert Fourer, Gus Gassmann, Jun Ma, Kipp Martin
 * @version 1.0, 21/07/2008
 * @since OS 1.1
 * 
 * \remarks
 * A data structure class that corresponds to an xml element in 
 * the OSoL schema.  
 */
class OtherConstraintOption {

public:
	/** number of <con> children */
	int numberOfCon;

	/** name of the option */
	std::string name;

	/** value of the option */
	std::string value;

	/** name of the solver to which this option applies */
	std::string solver;

	/** name of the category into which this option falls */
	std::string category;

	/** type of the option value (integer, double, boolean, string) */
	std::string type;

	/** description of the option */
	std::string description;

	/** array of option values */
	OtherConOption **con;

	/**
	 *
	 * Default constructor. 
	 */
	OtherConstraintOption();
	/**
	 *
	 * Class destructor. 
	 */
	~OtherConstraintOption();		
}; //OtherConstraintOption


/*! \class ConstraintOption
 *  \brief the ConstraintOption class.
 * 
 * @author Robert Fourer, Gus Gassmann, Jun Ma, Kipp Martin
 * @version 1.0, 21/07/2008
 * @since OS 1.1
 * 
 * \remarks
 * A data structure class that corresponds to an xml element in 
 * the OSoL schema.  
 */
class ConstraintOption {

public:
	/** number of <other> child elements */
	int numberOfOtherConstraintOptions;

	/** initial values for the constraints */
	InitConstraintValues *initialConstraintValues;

	/** initial dual values for the constraints */
	InitDualVariableValues *initialDualValues;

	/** other information about the constraints */
	OtherConstraintOption **other;

	/**
	 *
	 * Default constructor. 
	 */
	ConstraintOption();
	/**
	 *
	 * Class destructor. 
	 */
	~ConstraintOption();		
}; //ConstraintOption


/*! \class SolverOption
 *  \brief the SolverOption class.
 * 
 * @author Robert Fourer, Gus Gassmann, Jun Ma, Kipp Martin
 * @version 1.0, 21/07/2008
 * @since OS 1.1
 * 
 * \remarks
 * A data structure class that corresponds to an xml element in 
 * the OSoL schema.  
 */
class SolverOption {

public:
	/** the name of the option */
	std::string name;

	/** the value of the option */
	std::string value;

	/** the solver to which the option applies*/
	std::string solver;

	/** the category to which the option belongs */
	std::string category;

	/** the type of the option value (integer, double, boolean, string) */
	std::string type;

	/** the description of the option */
	std::string description;

	/**
	 *
	 * Default constructor. 
	 */
	SolverOption();
	/**
	 *
	 * Class destructor. 
	 */
	~SolverOption();		
}; //SolverOption


/*! \class SolverOptions
 *  \brief the SolverOptions class.
 * 
 * @author Robert Fourer, Gus Gassmann, Jun Ma, Kipp Martin
 * @version 1.0, 21/07/2008
 * @since OS 1.1
 * 
 * \remarks
 * A data structure class that corresponds to an xml element in 
 * the OSoL schema.  
 */
class SolverOptions {

public:
	/** the number of solver options */
	int numberOfSolverOptions;

	/** the list of solver options */
	SolverOption **solverOption;

	/**
	 *
	 * Default constructor. 
	 */
	SolverOptions();
	/**
	 *
	 * Class destructor. 
	 */
	~SolverOptions();		
}; //SolverOptions


/*! \class OptimizationOption
 *  \brief the OptimizationOption class.
 * 
 * @author Robert Fourer, Gus Gassmann, Jun Ma, Kipp Martin
 * @version 1.0, 21/07/2008
 * @since OS 1.1
 * 
 * \remarks
 * A data structure class that corresponds to an xml element in 
 * the OSoL schema.  
 */
class OptimizationOption {

public:
	/** the number of variables */
	int numberOfVariables;

	/** the number of objectives */
	int numberOfObjectives;

	/** the number of constraints */
	int numberOfConstraints;

	/** the options for the variables */
	VariableOption *variables;

	/** the options for the objectives */
	ObjectiveOption *objectives;

	/** the options for the constraints */
	ConstraintOption *constraints;

	/** other solver options */
	SolverOptions *solverOptions;
	/**
	 *
	 * Default constructor. 
	 */
	OptimizationOption();
	/**
	 *
	 * Class destructor. 
	 */
	~OptimizationOption();	
	
private:
	

}; //OptimizationOption


/*! \class OSOption
 *  \brief The Option Class.
 * 
 * @author Robert Fourer, Gus Gassmann, Jun Ma, Kipp Martin
 * @version 1.0, 21/07/2008
 * @since OS 1.1
 * 
 * \remarks
 * A class for holding all the solver options information.
 */
class OSOption{

public:
	/**
	 *
	 * Default constructor. 
	 */
	OSOption(); 
	/**
	 *
	 * Class destructor. 
	 */
	~OSOption();

	/** 
	 * OSOption has five children: general, system, service, job, and optimization.
	 *
	 * generalOption holds the first child of the OSOption specified by the OSoL Schema. 
	 */
	GeneralOption *general;
	/**
	 * systemOption holds the second child of the OSOption specified by the OSoL Schema. 
	 */
	SystemOption *system;
	/**
	 * serviceOption holds the third child of the OSOption specified by the OSoL Schema. 
	 */
	ServiceOption *service;
	/**
	 * jobOption holds the fourth child of the OSOption specified by the OSoL Schema. 
	 */
	JobOption *job;
	/**
	 * optimizationOption holds the fifth child of the OSOption specified by the OSoL Schema. 
	 */
	OptimizationOption *optimization;


public: 
	
	// get() methods...
	
	/**
	 * Get the service URI
	 */
	std::string  getServiceURI();

	/**
	 * Get the service name
	 */
	std::string  getServiceName();

	/**
	 * Get the instance name
	 */
	std::string  getInstanceName();

	/**
	 * Get the instance location
	 */
	std::string  getInstanceLocation();

	/**
	 * Get the location type
	 */
	std::string  getInstanceLocationType();

	/**
	 * Get the job ID
	 */
	std::string  getJobID();

	/**
	 * Get the solver name
	 */
	std::string  getSolverToInvoke();

	/**
	 * Get the license string
	 */
	std::string  getLicense();

	/**
	 * Get the user name
	 */
	std::string  getUserName();

	/**
	 * Get the password
	 */
	std::string  getPassword();

	/**
	 * Get the contact information
	 */
	std::string  getContact();

	/**
	 * Get the transport type
	 */
	std::string  getContactTransportType();

	/**
	 * Get the disk space unit
	 */
	std::string  getMinDiskSpaceUnit();

	/**
	 * Get the memory unit
	 */
	std::string  getMinMemoryUnit();

	/**
	 * Get the CPU speed unit
	 */
	std::string  getMinCPUSpeedUnit();

	/**
	 * Get the service type
	 */
	std::string  getServiceType();

	/**
	 * Get the time unit
	 */
	std::string  getMaxTimeUnit();

	/**
	 * Get the scheduled starting time
	 */
	std::string  getScheduledStartTime();

	/**
	 * Get any of the string-valued options
	 */
	std::string  getOptionStr(std::string optionName);

	/**
	 * Get the minimum required disk space
	 */
	double  getMinDiskSpace();

	/**
	 * Get the minimum required memory
	 */
	double  getMinMemorySize();

	/**
	 * Get the minimum required CPU speed
	 */
	double  getMinCPUSpeed();

	/**
	 * Get the maximum allowed time
	 */
	double  getMaxTime();

	/**
	 * Get any of the double-valued options
	 */
	double  getOptionDbl(std::string optionName);

	/**
	 * Get the minimum required number of CPUs
	 */
	int  getMinCPUNumber();

	/**
	 * Get the number of <other> options in the <general> element
	 */
	int  getNumberOfOtherGeneralOptions();

	/**
	 * Get the number of <other> options in the <system> element
	 */
	int  getNumberOfOtherSystemOptions();

	/**
	 * Get the number of <other> options in the <service> element
	 */
	int  getNumberOfOtherServiceOptions();

	/**
	 * Get the number of <other> options in the <job> element
	 */
	int  getNumberOfOtherJobOptions();

	/**
	 * Get the number of job dependencies
	 */
	int  getNumberOfJobDependencies();

	/**
	 * Get the number of required directories
	 */
	int  getNumberOfRequiredDirectories();

	/**
	 * Get the number of required files
	 */
	int  getNumberOfRequiredFiles();

	/**
	 * Get the number of directories to make
	 */
	int  getNumberOfDirectoriesToMake();

	/**
	 * Get the number of files to make
	 */
	int  getNumberOfFilesToMake();

	/**
	 * Get the number of input directories to move
	 */
	int  getNumberOfInputDirectoriesToMove();

	/**
	 * Get the number of input files to move
	 */
	int  getNumberOfInputFilesToMove();

	/**
	 * Get the number of output directories to move
	 */
	int  getNumberOfOutputDirectoriesToMove();

	/**
	 * Get the number of output files to move
	 */
	int  getNumberOfOutputFilesToMove();

	/**
	 * Get the number of files to delete
	 */
	int  getNumberOfFilesToDelete();

	/**
	 * Get the number of directories to delete
	 */
	int  getNumberOfDirectoriesToDelete();

	/**
	 * Get the number of processes to kill
	 */
	int  getNumberOfProcessesToKill();

	/**
	 * Get the number of variables in the instance
	 */
	int  getNumberOfVariables();

	/**
	 * Get the number of objectives in the instance
	 */
	int  getNumberOfObjectives();

	/**
	 * Get the number of constraints in the instance
	 */
	int  getNumberOfConstraints();

	/**
	 * Get the number of initial variable values. 
	 * 
	 * @return the number of initial variable values. 
	 */
	int getNumberOfInitVarValues();

	/**
	 * Get the number of initial variable strings. 
	 * 
	 * @return the number of initial variable strings. 
	 */
	int getNumberOfInitVarValuesString();

	/**
	 * Get the number of variables for which initial basis information is provided. 
	 * 
	 * @return the number of variables. 
	 */
	int getNumberOfInitialBasisVariables();

	/**
	 * Get the number of other variable options
	 * 
	 * @return the number of other variable options. 
	 */
	int getNumberOfOtherVariableOptions();
	
	/**
	 * Get the number of initial objective values. 
	 * 
	 * @return the number of initial objective values. 
	 */
	int getNumberOfInitObjValues();

	/**
	 * Get the number of initial objective bounds. 
	 * 
	 * @return the number of initial objective bound values. 
	 */
	int getNumberOfInitObjBounds();

	/**
	 * Get the number of other objective options
	 * 
	 * @return the number of other objective options. 
	 */
	int getNumberOfOtherObjectiveOptions();
	
	/**
	 * Get the number of initial constraint values. 
	 * 
	 * @return the number of initial constraint values. 
	 */
	int getNumberOfInitConValues();

	/**
	 * Get the number of initial dual variable values. 
	 * 
	 * @return the number of initial dual variable values. 
	 */
	int getNumberOfInitDualVarValues();

	/**
	 * Get the number of other constraint options
	 * 
	 * @return the number of other constraint options. 
	 */
	int getNumberOfOtherConstraintOptions();
	
	/**
	 * Get the number of solver options. 
	 * 
	 * @return the number of solver options. 
	 */
	int getNumberOfSolverOptions();
	
	/**
	 * Get any of the integer-valued options
	 */
	int getOptionInt(std::string optionName);


	/**
	 * Get the array of other options associated with the <general> element
	 * <p>
	 * 
	 * @return a vector of pointers to otherOptions objects  
	 * associated with the <general> element
	 */
	OtherOption** getOtherGeneralOptions();

	/**
	 * Get the array of other options associated with the <system> element
	 * <p>
	 * 
	 * @return a vector of pointers to otherOptions objects  
	 * associated with the <system> element
	 */
	OtherOption** getOtherSystemOptions();

	/**
	 * Get the array of other options associated with the <service> element
	 * <p>
	 * 
	 * @return a vector of pointers to otherOptions objects  
	 * associated with the <service> element
	 */
	OtherOption** getOtherServiceOptions();

	/**
	 * Get the array of other options associated with the <job> element
	 * <p>
	 * 
	 * @return a vector of pointers to otherOptions objects  
	 * associated with the <job> element
	 */
	OtherOption** getOtherJobOptions();

	/**
	 * Get the array of other options associated with any element
	 * <p>
	 * 
	 * @return a vector of pointers to otherOptions objects  
	 * associated with the element whose name matches elementName
	 */
	OtherOption** getOtherOptions(std::string elementName);

	/**
	 * Get the array of all other options associated with the 
	 ** <general>, <system>, <service> and <job> elements
	 * <p>
	 * 
	 * @return a vector of pointers to all otherOptions objects  
	 */
	OtherOption** getAllOtherOptions();

	/**
	 * Get the array of job dependencies
	 * <p>
	 * 
	 * @return a vector of pointers to JobDependencies objects  
	 */
	std::string* getJobDependencies();

	/**
	 * Get the array of required directories
	 * <p>
	 * 
	 * @return a vector of pointers to DirectoriesAndFiles objects  
	 * giving the directories that are required by the current job
	 */
	std::string* getRequiredDirectories();

	/**
	 * Get the array of required files
	 * <p>
	 * 
	 * @return a vector of pointers to DirectoriesAndFiles objects  
	 * giving the files that are required by the current job
	 */
	std::string* getRequiredFiles();

	/**
	 * Get the array of directories to make
	 * <p>
	 * 
	 * @return a vector of pointers to DirectoriesAndFiles objects  
	 * giving the directories that must be created
	 */
	std::string* getDirectoriesToMake();

	/**
	 * Get the array of files to make
	 * <p>
	 * 
	 * @return a vector of pointers to DirectoriesAndFiles objects  
	 * giving the files that must be created
	 */
	std::string* getFilesToMake();

	/**
	 * Get the array of input directories to move
	 * <p>
	 * 
	 * @return a vector of pointers to PathPair objects  
	 * giving the input directories that must be moved
	 */
	PathPair** getInputDirectoriesToMove();

	/**
	 * Get the array of input files to move
	 * <p>
	 * 
	 * @return a vector of pointers to PathPair objects  
	 * giving the input files that must be moved
	 */
	PathPair** getInputFilesToMove();

	/**
	 * Get the array of output directories to move
	 * <p>
	 * 
	 * @return a vector of pointers to PathPair objects  
	 * giving the output directories that must be moved
	 */
	PathPair** getOutputDirectoriesToMove();

	/**
	 * Get the array of output files to move
	 * <p>
	 * 
	 * @return a vector of pointers to PathPair objects  
	 * giving the output files that must be moved
	 */
	PathPair** getOutputFilesToMove();

	/**
	 * Get the array of directories to delete
	 * <p>
	 * 
	 * @return a vector of pointers to DirectoriesAndFiles objects  
	 * giving the directories that must be deleted
	 */
	std::string* getDirectoriesToDelete();

	/**
	 * Get the array of files to delete
	 * <p>
	 * 
	 * @return a vector of pointers to DirectoriesAndFiles objects  
	 * giving the files that must be deleted
	 */
	std::string* getFilesToDelete();

	/**
	 * Get the array of processes to kill
	 * <p>
	 * 
	 * @return a vector of pointers to Processes objects  
	 * giving the processes that must be killed
	 */
	std::string* getProcessesToKill();

	/**
	 * Get the initial values associated with the variables in sparse form
	 * <p>
	 * 
	 * @return a vector of pointers to InitVarValue objects that 
	 * hold inital values for (some of) the variables
	 */
	InitVarValue** getInitVarValuesSparse();

	/**
	 * Get the initial values associated with the variables in dense form
	 * <p>
	 * 
	 * @return a vector of double that 
	 * hold inital values for all of the variables
	 */
	double *getInitVarValuesDense(int numberOfVariables);

	/**
	 * Get the initial value strings associated with the variables in sparse form
	 * <p>
	 * 
	 * @return a vector of strings that 
	 * hold inital value strings for (some of) the variables
	 */
	InitVarValueString** getInitVarStringsSparse();

	/**
	 * Get the initial value strings associated with the variables in dense form
	 * <p>
	 * 
	 * @return a vector of strings that 
	 * hold inital value strings (or OSNAN) for all of the variables
	 */
	std::string *getInitVarStringsDense(int numberOfVariables);

	/**
	 * Get the initial basis status in sparse form
	 * <p>
	 * 
	 * @return a vector of strings that 
	 * hold inital basis status for (some of) the variables
	 */
	InitBasStatus** getInitBasisStatusSparse();

	/**
	 * Get the initial basis status in dense form
	 * <p>
	 * 
	 * @return a vector of strings that 
	 * hold inital basis status (or "unknown") for all of the variables
	 */
	std::string *getInitBasisStatusDense(int numberOfVariables);

	/*
	getIntegerVariableBranchingWeightsSparse();
	getIntegerVariableBranchingWeightsDense(int numberOfVariables);
	getSOSVariableBranchingWeightsSparse(); // ?
	getSOSVariableBranchingWeightsDense(int numberOfVariables); // ?
	 */

	/**
	 * Get the array of other variable options
	 * <p>
	 * 
	 * @return a vector of pointers to OtherVariableOption objects  
	 */
	//std::vector<OtherVariableOption*> getOtherVariableOptions();

	/**
	 * Get the initial values associated with the objectives in sparse form
	 * <p>
	 * 
	 * @return a vector of pointers to InitObjValue objects that 
	 * hold inital values for (some of) the objectives
	 */
	InitObjValue** getInitObjValuesSparse();

	/**
	 * Get the initial values associated with the objectives in dense form
	 * <p>
	 * 
	 * @return a vector of double that 
	 * hold inital values (or OSNAN) for all of the objectives
	 */
	double *getInitObjValuesDense(int numberOfObjectives);

	/**
	 * Get the initial bounds associated with the objectives in sparse form
	 * <p>
	 * 
	 * @return a vector of pointers to InitObjBound objects that 
	 * hold inital bounds for (some of) the objectives
	 */
	InitObjBound** getInitObjBoundsSparse();

	/**
	 * Get the initial lower bounds associated with the objectives in dense form
	 * <p>
	 * 
	 * @return a vector of double that 
	 * hold inital lower bounds (or OSNAN) for all of the objectives
	 */
	double *getInitObjLowerBoundsDense(int numberOfObjectives);

	/**
	 * Get the initial upper bounds associated with the objectives in dense form
	 * <p>
	 * 
	 * @return a vector of double that 
	 * hold inital upper bounds (or OSNAN) for all of the objectives
	 */
	double *getInitObjUpperBoundsDense(int numberOfObjectives);

	/**
	 * Get the array of other objective options
	 * <p>
	 * 
	 * @return a vector of pointers to OtherObjectiveOption objects  
	 */
	//std::vector<OtherObjectiveOption*> getOtherObjectiveOptions();

	/**
	 * Get the initial values associated with the constraints in sparse form
	 * <p>
	 * 
	 * @return a vector of pointers to InitConValue objects that 
	 * hold inital values for (some of) the constraints
	 */
	InitConValue** getInitConValuesSparse();

	/**
	 * Get the initial values associated with the constraints in dense form
	 * <p>
	 * 
	 * @return a vector of double that 
	 * hold inital values for all of the constraints
	 */
	double *getInitConValuesDense(int numberOfConstraints);

	/**
	 * Get the initial bounds associated with the dual variables in sparse form
	 * <p>
	 * 
	 * @return a vector of pointers to InitDualVarValue objects that 
	 * hold inital bounds for (some of) the dual variables
	 */
	InitDualVarValue** getInitDualVarValuesSparse();

	/**
	 * Get the initial lower bounds associated with the dual variables in dense form
	 * <p>
	 * 
	 * @return a vector of double that 
	 * hold initial lower bounds for all of the dual variables
	 */
	double *getInitDualVarLowerBoundsDense(int numberOfConstraints);


	/**
	 * Get the initial upper bounds associated with the dual variables in dense form
	 * <p>
	 * 
	 * @return a vector of double that 
	 * hold initial upper bounds for all of the dual variables
	 */
	double *getInitDualVarUpperBoundsDense(int numberOfConstraints);

	/**
	 * Get the array of other constraint options
	 * <p>
	 * 
	 * @return a vector of pointers to OtherConstraintOption objects  
	 */
	//std::vector<OtherConstraintOption*> getOtherConstraintOptions();


	/**
	 * Get the options associated with a given solver
	 * <p>
	 * 
	 * @param solver_name is the name of the solver whose options we want
	 * @return a vector of pointers to SolverOption objects that 
	 * correspond to the solver named. 
	 */
	std::vector<SolverOption*> getSolverOptions( std::string solver_name);


	/**
	 * Set the serviceURI
	 */
	bool setServiceURI( std::string serviceURI);

	/**
	 * Set the service name
	 */
	bool setServiceName( std::string serviceName);

	/**
	 * Set the instance name
	 */
	bool setInstanceName( std::string instanceName);

	/**
	 * Set the instance location
	 */
	bool setInstanceLocation( std::string instanceLocation);

	/**
	 * Set the instance location type
	 */
	bool setLocationType( std::string locationType);

	/**
	 * Set the job ID
	 */
	bool setJobID( std::string jobID);

	/**
	 * Set the solver to be invoked
	 */
	bool setSolverToInvoke( std::string solverToInvoke);

	/**
	 * Set the license information
	 */
	bool setLicense( std::string license);

	/**
	 * Set the username
	 */
	bool setUserName( std::string userName);

	/**
	 * Set the password
	 */
	bool setPassword( std::string password);

	/**
	 * Set the contact information
	 */
	bool setContact( std::string contact);

	/**
	 * Set the transport type for contact
	 */
	bool setTransportType( std::string transportType);

	/**
	 * Set the number of other general options
	 */
	bool setNumberOfOtherGeneralOptions(int numberOfObjects);

	/**
	 * Set the other general options as an entire array
	 */
	bool setOtherGeneralOptions(int numberOfOptions, OtherOption** other);

	/**
	 * Add another general option to the general option array
	 */
	bool setAnOtherGeneralOption(OtherOption* optionValue);


	bool setMinDiskSpace(double value);

	bool setMinDiskSpaceUnit(std::string unit);

	bool setMinMemorySize(double value);

	bool setMinMemoryUnit(std::string unit);

	bool setMinCPUSpeed(double value);

	bool setMinCPUSpeedUnit(std::string unit);

	bool setMinCPUNumber( int number);

	bool setNumberOfOtherSystemOptions(int numberOfObjects);

	bool setOtherSystemOptions(int numberOfOptions, OtherOption** other);

	bool setAnOtherSystemOption(OtherOption* optionValue);


	bool setServiceType( std::string serviceType);

	bool setNumberOfOtherServiceOptions(int numberOfObjects);

	bool setOtherServiceOptions(int numberOfOptions, OtherOption** other);

	bool setAnOtherServiceOption(OtherOption* optionValue);


	bool setMaxTime(double value);

	bool setMaxTimeUnit(std::string unit);

	bool setScheduledStartTime(std::string time);

	bool setNumberOfJobDependencies(int numberOfObjects);
	bool setJobDependencies(int numberOfDependencies, std::string* jobDependencies);
	bool setAnotherJobDependency(std::string jobID);

	bool setNumberOfRequiredDirectories(int numberOfObjects);
	bool setRequiredDirectories(int numberOfPaths, std::string* paths);
	bool setAnotherRequiredDirectory(std::string path);

	bool setNumberOfRequiredFiles(int numberOfObjects);
	bool setRequiredFiles(int numberOfPaths, std::string* paths);
	bool setAnotherRequiredFile(std::string path);

	bool setNumberOfDirectoriesToMake(int numberOfObjects);
	bool setDirectoriesToMake(int numberOfPaths, std::string* paths);
	bool setAnotherDirectoryToMake(std::string path);

	bool setNumberOfFilesToMake(int numberOfObjects);
	bool setFilesToMake(int numberOfPaths, std::string* paths);
	bool setAnotherFileToMake(std::string path);

	bool setNumberOfInputDirectoriesToMove(int numberOfObjects);
	bool setInputDirectoriesToMove(int numberOfPathPairs, PathPair** pathPair);
	bool setAnotherInputDirectoryToMove(std::string fromPath, std::string toPath, bool makeCopy);

	bool setNumberOfInputFilesToMove(int numberOfObjects);
	bool setInputFilesToMove(int numberOfPathPairs, PathPair** pathPair);
	bool setAnotherInputFileToMove(std::string fromPath, std::string toPath, bool makeCopy);

	bool setNumberOfOutputFilesToMove(int numberOfObjects);
	bool setOutputFilesToMove(int numberOfPathPairs, PathPair** pathPair);
	bool setAnotherOutputFileToMove(std::string fromPath, std::string toPath, bool makeCopy);

	bool setNumberOfOutputDirectoriesToMove(int numberOfObjects);
	bool setOutputDirectoriesToMove(int numberOfPathPairs, PathPair** pathPair);
	bool setAnotherOutputDirectoryToMove(std::string fromPath, std::string toPath, bool makeCopy);

	bool setNumberOfFilesToDelete(int numberOfObjects);
	bool setFilesToDelete(int numberOfPaths, std::string* paths);
	bool setAnotherFileToDelete(std::string path);

	bool setNumberOfDirectoriesToDelete(int numberOfObjects);
	bool setDirectoriesToDelete(int numberOfPaths, std::string* paths);
	bool setAnotherDirectoryToDelete(std::string path);

	bool setNumberOfProcessesToKill(int numberOfObjects);
	bool setProcessesToKill(int numberOfProcesses, std::string* processes);
	bool setAnotherProcessToKill(std::string process);

	bool setNumberOfOtherJobOptions(int numberOfObjects);

	bool setOtherJobOptions(int numberOfOptions, OtherOption** other);

	bool setAnOtherJobOption(OtherOption* optionValue);


	bool setNumberOfVariables(int numberOfObjects);

	bool setNumberOfObjectives(int numberOfObjects);

	bool setNumberOfConstraints(int numberOfObjects);

	bool setNumberOfInitVarValues(int numberOfObjects);
	bool setInitVarValuesDense(int numberOfVar, int *idx, double *value);
	bool setInitVarValuesSparse(int numberOfVar, InitVarValue** var);
	bool setAnotherInitVarValue(int idx, double value);

	bool setNumberOfInitVarValuesString(int numberOfObjects);
	bool setInitVarValuesStringSparse(int numberOfVar, InitVarValueString** var);
	bool setInitVarValuesStringDense(int numberOfVar, int *idx, std::string *value);
	bool setAnotherInitVarValueString(int idx, std::string value);

	bool setNumberOfInitialBasisVariables(int numberOfObjects);
	bool setInitBasisStatusSparse(int numberOfVar, InitBasStatus** var);
	bool setInitBasisStatusDense(int numberOfVar, int *idx, std::string *var);
	bool setAnotherInitBasisStatus(int idx, std::string value);

	bool setNumberOfOtherVariableOptions(int numberOfObjects);
	bool setOtherVariableOptions(int numberOfVar, OtherVariableOption** var);
	bool setAnOtherVariableOption(OtherVariableOption* varOption);

	bool setNumberOfInitObjValues(int numberOfObjects);
	bool setInitObjValuesSparse(int numberOfObj, InitObjValue** obj);
	bool setInitObjValuesDense(int numberOfObj, double* obj);
	bool setAnotherInitObjValue(int idx, double value);

	bool setNumberOfInitObjBounds(int numberOfObjects);
	bool setInitObjBoundsSparse(int numberOfObj, InitObjValue** obj);
	bool setInitObjBoundsDense(int numberOfObj, double* lb, double* ub);
	bool setAnotherInitObjBound(int idx, double lbValue, double ubValue);

	bool setNumberOfOtherObjectiveOptions(int numberOfObjects);
	bool setOtherObjectiveOptions(int numberOfObj, OtherObjOption** obj);
	bool setAnOtherObjectiveOption(OtherObjOption* objOption);

	bool setNumberOfInitConValues(int numberOfObjects);
	bool setInitConValuesSparse(int numberOfCon, InitConValue** con);
	bool setInitConValuesDense(int numberOfCon, double* con);
	bool setAnotherInitConValue(int idx, double value);

	bool setNumberOfInitDualVarValues(int numberOfObjects);
	bool setInitDualVarValuesSparse(int numberOfCon, InitDualVarValue** con);
	bool setInitDualVarValuesDense(int numberOfCon, double* lb, double* ub);
	bool setAnotherInitDualVarValue(int idx, double lbValue, double ubValue);

	bool setNumberOfOtherConstraintOptions(int numberOfObjects);
	bool setOtherConstraintOptions(int numberOfCon, OtherConOption** con);
	bool setAnOtherConstraintOption(OtherConOption* conOption);

	bool setNumberOfSolverOptions(int numberOfObjects);
	bool setSolverOptions(int numberOfSolverOptions, SolverOption** solverOption);
	bool setAnotherSolverOption(SolverOption* solverOption);

	bool setOptionInt(std::string optionName, int optionValue);

	bool setOptionStr(std::string optionName, std::string optionValue);

	bool setOptionDbl(std::string optionName, double value);

};
#endif
