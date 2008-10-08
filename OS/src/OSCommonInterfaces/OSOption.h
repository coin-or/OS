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
	


public: //Put the get() and set() methods...

//   	/**
//	 * Get the general status.
//	 * 
//	 * @return the general status. 
//	 */
//	GeneralStatus* getGeneralStatus();
	
//  	/**
//	 * Get the general status type, which can be: 
//	 * success, error, warning. 
//	 * 
//	 * @return the general status type, null if none. 
//	 */
//	std::string getGeneralStatusType();
//	
//   	/**
//	 * Get the general status description. 
//	 * 
//	 * @return the general status description, null or empty std::string if none. 
//	 */
//	std::string getGeneralStatusDescription();

//	/**
//	 * Get one solution of optimal primal variable values. 
//	 * 
//	 * @param objIdx holds the objective index the optimal value corresponds to. 
//	 * @return a double dense array of the optimal values, null if no optimal value. 
//	 */
//	double* getOptimalPrimalVariableValues(int objIdx);

//	/**
//	 * Get the [i]th optimization solution status, where i equals the given solution index.   
//	 * The solution status includes the status type, optional descriptions and possibly substatuses.
//	 *  
//	 * @param solIdx holds the solution index to get the solution status. 
//	 * @return the optimization solution status that corresponds to solIdx, null if none.
//	 * @see org.optimizationservices.oscommon.datastructure.osresult.OptimizationSolutionStatus
//	 */	
//	OptimizationSolutionStatus* getSolutionStatus( int solIdx);

	
	// set methods
	//
	
	
	
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
	 * Get the number of initial variable values. 
	 * 
	 * @return the number of initial variable values. 
	 */
	int getnumberOfInitVarValues();

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
	 * @return a vector of pointers to InitVarValue objects that 
	 * hold inital values for (some of) the variables
	 */
	double *getInitVarValuesDense(int numberOfVariables);

	/**
	 * Get the number of solver options. 
	 * 
	 * @return the number of solver options. 
	 */
	int getnumberOfSolverOptions();
	
	/**
	 * Get the options associated with a given solver
	 * <p>
	 * 
	 * @param solver_name is the name of the solver whose options we want
	 * @return a vector of pointers to SolverOption objects that 
	 * correspond to the solver named. 
	 */
	std::vector<SolverOption*> getSolverOptions( std::string solver_name);
	

};
#endif
