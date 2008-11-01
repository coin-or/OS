/** @file OSOption.h
 * 
 *
 * @author  Robert Fourer, Gus Gassmann, Jun Ma, Kipp Martin, 
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
	DirectoriesAndFiles *filesToCreate;

	/** input directories to move or copy */
	PathPairs *inputDirectoriesToMove;

	/** input files to move or copy */
	PathPairs *inputFilesToMove;

	/** output directories to move or copy */
	PathPairs *outputDirectoriesToMove;

	/** output files to move or copy */
	PathPairs *outputFilesToMove;

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

	/**
	 * m_inumberOfOtherGeneralOptions holds the number of other general option objects. 
	 */	
	int m_inumberOfOtherGeneralOptions;

	/**
	 * m_inumberOfOtherSystemOptions holds the number of other system option objects. 
	 */	
	int m_inumberOfOtherSystemOptions;

	/**
	 * m_inumberOfOtherServiceOptions holds the number of other service option objects. 
	 */	
	int m_inumberOfOtherServiceOptions;

	/**
	 * m_inumberOfOtherJobOptions holds the number of other job option objects. 
	 */	
	int m_inumberOfOtherJobOptions;

	/**
	 * m_inumberOfJobDependencies holds the number of JobDependencies objects. 
	 */	
	int m_inumberOfJobDependencies;

	/**
	 * m_inumberOfRequiredDirectories holds the number of RequiredDirectories objects. 
	 */	
	int m_inumberOfRequiredDirectories;

	/**
	 * m_inumberOfRequiredFiles holds the number of RequiredFiles objects. 
	 */	
	int m_inumberOfRequiredFiles;

	/**
	 * m_inumberOfDirectoriesToMake holds the number of DirectoriesToMake objects. 
	 */	
	int m_inumberOfDirectoriesToMake;

	/**
	 * m_inumberOfFilesToCreate holds the number of FilesToCreate objects. 
	 */	
	int m_inumberOfFilesToCreate;

	/**
	 * m_inumberOfInputDirectoriesToMove holds the number of input directories to move or copy. 
	 */	
	int m_inumberOfInputDirectoriesToMove;

	/**
	 * m_inumberOfInputFilesToMove holds the number of input files to move or copy. 
	 */	
	int m_inumberOfInputFilesToMove;

	/**
	 * m_inumberOfOutputDirectoriesToMove holds the number of output directories to move or copy. 
	 */	
	int m_inumberOfOutputDirectoriesToMove;

	/**
	 * m_inumberOfOutputFilesToMove holds the number of output files to move or copy. 
	 */	
	int m_inumberOfOutputFilesToMove;

	/**
	 * m_inumberOfFilesToDelete holds the number of FilesToDelete objects. 
	 */	
	int m_inumberOfFilesToDelete;

	/**
	 * m_inumberOfDirectoriesToDelete holds the number of DirectoriesToDelete objects. 
	 */	
	int m_inumberOfDirectoriesToDelete;

	/**
	 * m_inumberOfProcessesToKill holds the number of ProcessesToKill objects. 
	 */	
	int m_inumberOfProcessesToKill;

	/**
	 * m_inumberOfInitVarValues holds the number of InitVarValue objects. 
	 */	
	int m_inumberOfInitVarValues;

	/**
	 * m_inumberOfInitVarValuesString holds the number of InitVarValueString objects. 
	 */	
	int m_inumberOfInitVarValuesString;

	/**
	 * m_inumberOfOtherVariableOptions holds the number of OtherVariableOption objects. 
	 */	
	int m_inumberOfOtherVariableOptions;

	/**
	 * m_inumberOfOtherVarOptions is an array for the number of OtherVarOption objects. 
	 */	
	int *mm_inumberOfOtherVarOptions;

	/**
	 * m_inumberOfInitObjValues holds the number of InitObjValue objects. 
	 */	
	int m_inumberOfInitObjValues;

	/**
	 * m_inumberOfInitObjBounds holds the number of InitObjBound objects. 
	 */	
	int m_inumberOfInitObjBounds;

	/**
	 * m_inumberOfOtherObjectiveOptions holds the number of OtherObjectiveOption objects. 
	 */	
	int m_inumberOfOtherObjectiveOptions;

	/**
	 * m_inumberOfOtherObjOptions is an array for the number of OtherObjOption objects. 
	 */	
	int *mm_inumberOfOtherObjOptions;

	/**
	 * m_inumberOfInitConValues holds the number of InitConValue objects. 
	 */	
	int m_inumberOfInitConValues;

	/**
	 * m_inumberOfInitDualVarValues holds the number of InitDualVarValue objects. 
	 */	
	int m_inumberOfInitDualVarValues;

	/**
	 * m_inumberOfOtherConstraintOptions holds the number of OtherConstraintOption objects. 
	 */	
	int m_inumberOfOtherConstraintOptions;

	/**
	 * m_inumberOfOtherConOptions is an array for the number of OtherConOption objects. 
	 */	
	int *mm_inumberOfOtherConOptions;

	/**
	 * m_inumberOfSolverOptions holds the number of SolverOption objects. 
	 */	
	int m_inumberOfSolverOptions;
	


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
	std::string  getLocationType();

	/**
	 * Get the job ID
	 */
	std::string  getJobID();

	/**
	 * Get the solver name
	 */
	std::string  getSolverName();

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
	 * Get the conact information
	 */
	std::string  getContact();

	/**
	 * Get the transport type
	 */
	std::string  getTransportType();

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
	double  getMinMemory();

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
	 * Get the number of files to create
	 */
	int  getNumberOfFilesToCreate();

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
	std::vector<OtherOption*> getOtherGeneralOptions();

	/**
	 * Get the array of other options associated with the <system> element
	 * <p>
	 * 
	 * @return a vector of pointers to otherOptions objects  
	 * associated with the <system> element
	 */
	std::vector<OtherOption*> getOtherSystemOptions();

	/**
	 * Get the array of other options associated with the <service> element
	 * <p>
	 * 
	 * @return a vector of pointers to otherOptions objects  
	 * associated with the <service> element
	 */
	std::vector<OtherOption*> getOtherServiceOptions();

	/**
	 * Get the array of other options associated with the <job> element
	 * <p>
	 * 
	 * @return a vector of pointers to otherOptions objects  
	 * associated with the <job> element
	 */
	std::vector<OtherOption*> getOtherJobOptions();

	/**
	 * Get the array of other options associated with any element
	 * <p>
	 * 
	 * @return a vector of pointers to otherOptions objects  
	 * associated with the element whose name matches elementName
	 */
	std::vector<OtherOption*> getOtherOptions(std::string elementName);

	/**
	 * Get the array of all other options associated with the 
	 ** <general>, <system>, <service> and <job> elements
	 * <p>
	 * 
	 * @return a vector of pointers to all otherOptions objects  
	 */
	std::vector<OtherOption*> getAllOtherOptions();

	/**
	 * Get the array of job dependencies
	 * <p>
	 * 
	 * @return a vector of pointers to JobDependencies objects  
	 */
	std::vector<JobDependencies*> getJobDependencies();

	/**
	 * Get the array of required directories
	 * <p>
	 * 
	 * @return a vector of pointers to DirectoriesAndFiles objects  
	 * giving the directories that are required by the current job
	 */
	std::vector<DirectoriesAndFiles*> getRequiredDirectories();

	/**
	 * Get the array of required files
	 * <p>
	 * 
	 * @return a vector of pointers to DirectoriesAndFiles objects  
	 * giving the files that are required by the current job
	 */
	std::vector<DirectoriesAndFiles*> getRequiredFiles();

	/**
	 * Get the array of directories to make
	 * <p>
	 * 
	 * @return a vector of pointers to DirectoriesAndFiles objects  
	 * giving the directories that must be created
	 */
	std::vector<DirectoriesAndFiles*> getDirectoriesToMake();

	/**
	 * Get the array of files to create
	 * <p>
	 * 
	 * @return a vector of pointers to DirectoriesAndFiles objects  
	 * giving the files that must be created
	 */
	std::vector<DirectoriesAndFiles*> getFilesToCreate();

	/**
	 * Get the array of input directories to move
	 * <p>
	 * 
	 * @return a vector of pointers to PathPair objects  
	 * giving the input directories that must be moved
	 */
	std::vector<PathPair*> getInputDirectoriesToMove();

	/**
	 * Get the array of input files to move
	 * <p>
	 * 
	 * @return a vector of pointers to PathPair objects  
	 * giving the input files that must be moved
	 */
	std::vector<PathPair*> getInputFilesToMove();

	/**
	 * Get the array of output directories to move
	 * <p>
	 * 
	 * @return a vector of pointers to PathPair objects  
	 * giving the output directories that must be moved
	 */
	std::vector<PathPair*> getOutputDirectoriesToMove();

	/**
	 * Get the array of output files to move
	 * <p>
	 * 
	 * @return a vector of pointers to PathPair objects  
	 * giving the output files that must be moved
	 */
	std::vector<PathPair*> getOutputFilesToMove();

	/**
	 * Get the array of directories to delete
	 * <p>
	 * 
	 * @return a vector of pointers to DirectoriesAndFiles objects  
	 * giving the directories that must be deleted
	 */
	std::vector<DirectoriesAndFiles*> getDirectoriesToDelete();

	/**
	 * Get the array of files to delete
	 * <p>
	 * 
	 * @return a vector of pointers to DirectoriesAndFiles objects  
	 * giving the files that must be deleted
	 */
	std::vector<DirectoriesAndFiles*> getFilesToDelete();

	/**
	 * Get the array of processes to kill
	 * <p>
	 * 
	 * @return a vector of pointers to Processes objects  
	 * giving the processes that must be killed
	 */
	std::vector<Processes*> getProcessesToKill();

	/**
	 * Get the initial values associated with the variables in sparse form
	 * <p>
	 * 
	 * @return a vector of pointers to InitVarValue objects that 
	 * hold inital values for (some of) the variables
	 */
	std::vector<InitVarValue*> getInitVarValuesSparse();

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
	std::vector<InitVarValueString*> getInitVarStringsSparse();

	/**
	 * Get the initial value strings associated with the variables in dense form
	 * <p>
	 * 
	 * @return a vector of strings that 
	 * hold inital value strings (or OSNAN) for all of the variables
	 */
	std::string *getInitVarStringsDense(int numberOfVariables);

	/**
	 * Get the array of other variable options
	 * <p>
	 * 
	 * @return a vector of pointers to OtherVariableOption objects  
	 */
	std::vector<OtherVariableOption*> getOtherVariableOptions();

	/**
	 * Get the initial values associated with the objectives in sparse form
	 * <p>
	 * 
	 * @return a vector of pointers to InitObjValue objects that 
	 * hold inital values for (some of) the objectives
	 */
	std::vector<InitObjValue*> getInitObjValuesSparse();

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
	std::vector<InitObjBound*> getInitObjBoundsSparse();

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
	std::vector<OtherObjectiveOption*> getOtherObjectiveOptions();

	/**
	 * Get the initial values associated with the constraints in sparse form
	 * <p>
	 * 
	 * @return a vector of pointers to InitConValue objects that 
	 * hold inital values for (some of) the constraints
	 */
	std::vector<InitConValue*> getInitConValuesSparse();

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
	std::vector<InitDualVarValue*> getInitDualVarValuesSparse();

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
	std::vector<OtherConstraintOption*> getOtherConstraintOptions();


	/**
	 * Get the options associated with a given solver
	 * <p>
	 * 
	 * @param solver_name is the name of the solver whose options we want
	 * @return a vector of pointers to SolverOption objects that 
	 * correspond to the solver named. 
	 */
	std::vector<SolverOption*> getSolverOptions( std::string solver_name);

//   	/**
//	 * Set the general status
//	 * 
//	 * @param status holds the general status.
//	 * @return whether the general status is set successfully. 
//	 */
//	bool setGeneralStatus(GeneralStatus *status);
			
//   	/**
//	 * Set the general status type, which can be: 
//	 * success, error, warning. 
//	 * 
//	 * @param type holds the general status type
//	 * @return whether the general status type is set successfully or not. 
//	 */
//	bool setGeneralStatusType(std::string type);	



	/**
	 * Set the serviceURI
	 */
	bool setServiceURI( std::string serviceURI);

	/**
	 * Set the minimum number of CPUs that the system must provide
	 */
	bool setMinCPUNumber( int minCPUNumber);

};
#endif
