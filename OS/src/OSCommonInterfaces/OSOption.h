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



/*! \class InstanceLocationOption
 *  \brief the InstanceLocationOption class.
 * 
 * @author Robert Fourer, Gus Gassmann, Jun Ma, Kipp Martin
 * @version 1.0, 21/07/2008
 * @since OS 1.1
 * 
 * \remarks
 * A data structure class that corresponds to the instanceLocation 
 * in the OSoL schema.  
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
	/** the contact type */
	std::string contactType;

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

	/** the license information */
	std::string license;

	/** the username */
	std::string userName;

	/** the password */
	std::string password;

	/** the contact method */
	ContactOption *contact;

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
	double minDiskSpace;

	/** the minimum memory required */
	double minMemorySize;

	/** the minimum CPU speed required */
	double minCPUSpeed;

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
	double maxTime;

	/** the scheduled time to start the job */
	std::string scheduledStartTime;

	/** the dependency set */
	JobDependencies *dependencies;

	/** directories and files required to run the job */
	DirectoriesAndFiles *requiredDirectoriesAndFiles;

	/** directories to make during the job */
	DirectoriesAndFiles *directoriesToMake;

	/** files to make during the job */
	DirectoriesAndFiles *filesToCreate;

	/** input files to copy from */
	DirectoriesAndFiles *inputFilesToCopyFrom;

	/** input files to copy into */
	DirectoriesAndFiles *inputFilesToCopyTo;

	/** input files to move from */
	DirectoriesAndFiles *inputFilesToMoveFrom;

	/** input files to move to */
	DirectoriesAndFiles *inputFilesToMoveTo;

	/** output files to copy from */
	DirectoriesAndFiles *outputFilesToCopyFrom;

	/** output files to copy into */
	DirectoriesAndFiles *outputFilesToCopyTo;

	/** output files to move from */
	DirectoriesAndFiles *outputFilesToMoveFrom;

	/** output files to move to */
	DirectoriesAndFiles *outputFilesToMoveTo;

	/** files to delete upon completeion */
	DirectoriesAndFiles *filesToDelete;

	/** directories to delete upon completion */
	DirectoriesAndFiles *directoriesToDelete;

	/** processes to kill upon completion */
	Processes *processesToKill;

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
	std::string value;

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
	InitVarValue *var;

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

	/** other information about the variables */
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


/*! \class InitDualValues
 *  \brief the InitDualValues class.
 * 
 * @author Robert Fourer, Gus Gassmann, Jun Ma, Kipp Martin
 * @version 1.0, 21/07/2008
 * @since OS 1.1
 * 
 * \remarks
 * A data structure class that corresponds to an xml element in 
 * the OSoL schema.  
 */
class InitDualValues {

public:
	/** number of <con> children */
	int numberOfCon;

	/** initial dual values for each constraint */
	InitDualVarValue **con;

	/**
	 *
	 * Default constructor. 
	 */
	InitDualValues();
	/**
	 *
	 * Class destructor. 
	 */
	~InitDualValues();		
}; //InitDualValues


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
	InitDualValues *initialDualValues;

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


/*! \class OtherOption
 *  \brief the OtherOption class.
 * 
 * @author Robert Fourer, Gus Gassmann, Jun Ma, Kipp Martin
 * @version 1.0, 21/07/2008
 * @since OS 1.1
 * 
 * \remarks
 * A data structure class that corresponds to an xml element in 
 * the OSoL schema.  
 */
class OtherOption {

public:
	/** the name of the option */
	std::string name;

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

	/** the number of <other> optimization options */
	int numberOfOtherOptions;

	/** the options for the variables */
	VariableOption *variables;

	/** the options for the objectives */
	ObjectiveOption *objectives;

	/** the options for the constraints */
	ConstraintOption *constraints;

	/** other optimization options */
	OtherOption **other;
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
	 * OSOption has six children: general, system, service, job, optimization and other.
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
	/**
	 * otherOption holds the sixth child of the OSOption specified by the OSoL Schema. 
	 */
	OtherOption **other;


public:	

	/**
	 * m_inumberOfJobDependencies holds the number of JobDependencies objects. 
	 */	
	int m_inumberOfJobDependencies;

	/**
	 * m_inumberOfRequiredDirectories holds the number of RequiredDirectoriesAndFiles objects. 
	 */	
	int m_inumberOfRequiredDirectories;

	/**
	 * m_inumberOfDirectoriesToMake holds the number of DirectoriesToMake objects. 
	 */	
	int m_inumberOfDirectoriesToMake;

	/**
	 * m_inumberOfFilesToCreate holds the number of FilesToCreate objects. 
	 */	
	int m_inumberOfFilesToCreate;

	/**
	 * m_inumberOfInputFilesToCopyFrom holds the number of InputFilesToCopyFrom objects. 
	 */	
	int m_inumberOfInputFilesToCopyFrom;

	/**
	 * m_inumberOfInputFilesToCopyTo holds the number of InputFilesToCopyTo objects. 
	 */	
	int m_inumberOfInputFilesToCopyTo;

	/**
	 * m_inumberOfInputFilesToMoveFrom holds the number of InputFilesToMoveFrom objects. 
	 */	
	int m_inumberOfInputFilesToMoveFrom;

	/**
	 * m_inumberOfInputFilesToMoveTo holds the number of InputFilesToMoveTo objects. 
	 */	
	int m_inumberOfInputFilesToMoveTo;

	/**
	 * m_inumberOfOutputFilesToCopyFrom holds the number of OutputFilesToCopyFrom objects. 
	 */	
	int m_inumberOfOutputFilesToCopyFrom;

	/**
	 * m_inumberOfOutputFilesToCopyTo holds the number of OutputFilesToCopyTo objects. 
	 */	
	int m_inumberOfOutputFilesToCopyTo;

	/**
	 * m_inumberOfOutputFilesToMoveFrom holds the number of OutputFilesToMoveFrom objects. 
	 */	
	int m_inumberOfOutputFilesToMoveFrom;

	/**
	 * m_inumberOfOutputFilesToMoveTo holds the number of OutputFilesToMoveTo objects. 
	 */	
	int m_inumberOfOutputFilesToMoveTo;

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
	 * m_inumberOfInitVarValues holds the number of InitVarValues objects. 
	 */	
	int m_inumberOfInitVarValues;

	/**
	 * m_inumberOfOtherVariableOptions holds the number of OtherVariableOptions objects. 
	 */	
	int m_inumberOfOtherVariableOptions;

	/**
	 * m_inumberOfOtherVarOptions is an array for the number of OtherVarOptions objects. 
	 */	
	int *mm_inumberOfOtherVarOptions;

	/**
	 * m_inumberOfInitObjValues holds the number of InitObjValues objects. 
	 */	
	int m_inumberOfInitObjValues;

	/**
	 * m_inumberOfInitObjBounds holds the number of InitObjBounds objects. 
	 */	
	int m_inumberOfInitObjBounds;

	/**
	 * m_inumberOfOtherObjectiveOptions holds the number of OtherObjectiveOptions objects. 
	 */	
	int m_inumberOfOtherObjectiveOptions;

	/**
	 * m_inumberOfOtherObjOptions is an array for the number of OtherObjOptions objects. 
	 */	
	int *mm_inumberOfOtherObjOptions;

	/**
	 * m_inumberOfInitConValues holds the number of InitConValues objects. 
	 */	
	int m_inumberOfInitConValues;

	/**
	 * m_inumberOfInitDualVarValues holds the number of InitDualVarValues objects. 
	 */	
	int m_inumberOfInitDualVarValues;

	/**
	 * m_inumberOfOtherConstraintOptions holds the number of OtherConstraintOptions objects. 
	 */	
	int m_inumberOfOtherConstraintOptions;

	/**
	 * m_inumberOfOtherConOptions is an array for the number of OtherConOptions objects. 
	 */	
	int *mm_inumberOfOtherConOptions;

	/**
	 * m_inumberOfOtherOptimizationOptions holds the number of OtherOptimizationOptions objects. 
	 */	
	int m_inumberOfOtherOptimizationOptions;

	/**
	 * m_inumberOfOtherOptions holds the number of OtherOptions objects. 
	 */	
	int m_inumberOfOtherOptions;


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
	


};
#endif
