/** @file OSResult.h
 * 
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
 */

#ifndef OSRESULT_H
#define OSRESULT_H
//#define DEBUG
#include <string>
#include <vector> 


/*! \class GeneralStatus
 *  \brief The GeneralStatus  Class.
 * 
 * @author Robert Fourer, Jun Ma, Kipp Martin
 * @version 1.0, 03/14/2004
 * @since OS 1.0
 * 
 * \remarks
 * A data structure class that corresponds to an xml element in 
 * the OSrL schema.  
 */
class GeneralStatus {

public:

	/** the type of status */	
	std::string type;
	
	/** the description of the status */	
	std::string description;
	

	/**
	 *
	 * Default constructor. 
	 */
	GeneralStatus();
	/**
	 *
	 * Class destructor. 
	 */
	~GeneralStatus();
		
};//GeneralStatus


/*! \class ResultHeader
 *  \brief The ResultHeader  Class.
 * 
 * @author Robert Fourer, Jun Ma, Kipp Martin
 * @version 1.0, 03/14/2004
 * @since OS 1.0
 * 
 * \remarks
 * A class that provides the header information 
 * that is defined the OSrL schema.  
 */
class ResultHeader{
public:

	/** a pointer to the GeneralStatus class */
	GeneralStatus *generalStatus;
	
	/** the serviceURI is the URI of the solver service
	 * that did the optimiation 
	 */
	std::string serviceURI;
	
	/** the serviceName is the name of the sovler service
	 * that did the optimization
	 */
	std::string serviceName;
	
	/** the name of the instance that was solved */
	std::string instanceName;
	
	/** the jobID is the ID associated with the solution
	 * of this instance
	 */
	std::string jobID;
	
	/** the time when solution was complete 
	 * kippster -- verify this
	 */
	std::string time;
	
	/** any general message associated with the optimization */
	std::string message;
	
	/**
	 *
	 * Default constructor. 
	 */
	ResultHeader();
	/**
	 *
	 * Class destructor. 
	 */
	~ResultHeader();
};//class ResultHeader

/*! \class VarValue
 *  \brief VarValue  Class.
 * 
 * @author Robert Fourer, Jun Ma, Kipp Martin
 * @version 1.0, 03/14/2004
 * @since OS 1.0
 * 
 * \remarks
 * A class that is used to provide the value and index
 * associated with the variables in the solution.  
 */
class VarValue{
public:

	/** idx is the index on variable in the solution */
	int idx;
	
	/* value is the value of the variable indexed by idx
	 * in the solution
	 */	
	double value;

	/**
	 *
	 * Default constructor. 
	 */
	VarValue();
	/**
	 *
	 * Class destructor. 
	 */
	~VarValue();

};// class VarValue


/*! \class OtherVarResult
 *  \brief OtherVarResult Class.
 * 
 * @author Robert Fourer, Jun Ma, Kipp Martin
 * @version 1.0, 03/14/2004
 * @since OS 1.0
 * 
 * \remarks A class used to provide solution information
 * associated with the variables.
 */
class OtherVarResult {
public:
	
	/** the index of a variable in the solution */
	int idx;
	
	/** value holds a general value for a variable,
	 * for example, rather than the value of a variable
	 * we may wish to store the variable name associated
	 * with the vairable with index idx, hence we want
	 * a string here and not a double
	 */
	std::string value;
	
	/**
	 *
	 * Default constructor. 
	 */
	OtherVarResult();
	/**
	 *
	 * Class destructor. 
	 */
	~OtherVarResult();
	
};//OtherVarResult


/*! \class OtherObjResult
 *  \brief The OtherObjResult  Class.
 * 
 * @author Robert Fourer, Jun Ma, Kipp Martin
 * @version 1.0, 03/14/2004
 * @since OS 1.0
 * 
 * \remarks
 * A class that provides general result information
 * for objective functions. 
 */
class OtherObjResult {
public:
	
	/** idx is the index on a objective function */
	int idx;
	
	
	/** value is a value associated with an objective function
	 * indexed by idx
	 */
	std::string value;
	
	/**
	 *
	 * Default constructor. 
	 */
	OtherObjResult();
	/**
	 *
	 * Class destructor. 
	 */
	~OtherObjResult();
	
};//OtherObjResult



/*! \class OtherConResult
 *  \brief The OtherConResult  Class.
 * 
 * @author Robert Fourer, Jun Ma, Kipp Martin
 * @version 1.0, 03/14/2004
 * @since OS 1.0
 * 
 * \remarks
 * A class that provides general result information
 * for constraints. 
 */
class OtherConResult {
public:
	
	/** idx is the index on the constraint */
	int idx;
	
	/** value is a value associated with the constraint
	 * indexed by idx, for example value might be the 
	 * value of a dual variable or it might be the name
	 * of the constraint.
	 */
	std::string value;
	
	/**
	 *
	 * Default constructor. 
	 */
	OtherConResult();
	/**
	 *
	 * Class destructor. 
	 */
	~OtherConResult();
	
};//OtherConResult



/*! \class ObjValue
 *  \brief The ObjValue  Class.
 * 
 * @author Robert Fourer, Jun Ma, Kipp Martin
 * @version 1.0, 03/14/2004
 * @since OS 1.0
 * 
 * \remarks
 * A class that provides the value of an objective
 * function
 */
class ObjValue {
public:	

	/** idx is the index on an objective function */
	int idx;
	
	/** the value of the objective indexed by idx */
	double value;
	
	/**
	 *
	 * Default constructor. 
	 */
	ObjValue();
	/**
	 *
	 * Class destructor. 
	 */
	~ObjValue();
	
};//ObjectiveValues



/*! \class ConValue
 *  \brief The ConValue  Class.
 * 
 * @author Robert Fourer, Jun Ma, Kipp Martin
 * @version 1.0, 03/14/2004
 * @since OS 1.0
 * 
 * \remarks
 * A class that provides the value of a constraint 
 */
class ConValue{
public:

	/** idx is the index on a constraint */
	int idx;
	
	/** the value of the constraint indexed by idx */
	double value;

	/**
	 *
	 * Default constructor. 
	 */
	ConValue();
	/**
	 *
	 * Class destructor. 
	 */
	~ConValue();

};// class ConValue



/*! \class DualVarValue
 *  \brief The DualVarValue  Class.
 * 
 * @author Robert Fourer, Jun Ma, Kipp Martin
 * @version 1.0, 03/14/2004
 * @since OS 1.0
 * 
 * \remarks
 * A class that provides the dual value of a constraint 
 */
class DualVarValue {
public:	

	/** idx is the index on a constraint */
	int idx;

	/** lbValue is the value of dual variable on
	 * the constraint indexed by idx if the constraint
	 * is at its lower bound
	 */		
	double lbValue;
	
	
	/** ubValue is the value of dual variable on
	 * the constraint indexed by idx if the constraint
	 * is at its upper bound
	 */	
	double ubValue;
	
	/** value of dual variable on
	 * the constraint indexed by idx if the constraint
	 */
	double value;
	
	/**
	 *
	 * Default constructor. 
	 */
	DualVarValue();
	/**
	 *
	 * Class destructor. 
	 */
	~DualVarValue();
	
};//DualVarValue


/*! \class VariableValues
 *  \brief The VariableValues Class.
 * 
 * @author Robert Fourer, Jun Ma, Kipp Martin
 * @version 1.0, 03/14/2004
 * @since OS 1.0
 * 
 * \remarks
 * A class that values for all the variables
 */	
class VariableValues{
public:

	/** a vector of VarValue objects, there will be one
	 * for each variable in the solution
	 */
	std::vector<VarValue*> var;

	
	/**
	 *
	 * Default constructor. 
	 */
	VariableValues();
	
	/**
	 *
	 * Class destructor. 
	 */
	~VariableValues();

};// class VariableValues


/*! \class OtherVariableResult
 *  \brief The OtherVariableResult  Class.
 * 
 * @author Robert Fourer, Jun Ma, Kipp Martin
 * @version 1.0, 03/14/2004
 * @since OS 1.0
 * 
 * \remarks
 * A class that allows the solver to report an
 * arbitrary result associated with variables 
 */
class OtherVariableResult {
public:

	/** the name of the result the user is defining */
	std::string name;
	
	/** a brief description of the type of result */
	std::string description;
	
	/* a vector of OtherVarResult objects that will
	 * give for each variable the index and value for 
	 * this user defined variable result
	 */
	std::vector<OtherVarResult*> var;	
	/**
	 *
	 * Default constructor. 
	 */
	OtherVariableResult();
	
	/**
	 *
	 * Class destructor. 
	 */
	~OtherVariableResult();
	
};//OtherVariableResult


/*! \class OtherObjectiveResult
 *  \brief The OtherObjectiveResult  Class.
 * 
 * @author Robert Fourer, Jun Ma, Kipp Martin
 * @version 1.0, 03/14/2004
 * @since OS 1.0
 * 
 * \remarks
 * A class that allows the solver to report an
 * arbitrary result associated with objective functions 
 */
class OtherObjectiveResult {
public:

	/** the name of the result the user is defining */
	std::string name;
	
	/** a brief description of the type of result */
	std::string description;

	/* a vector of OtherObjResult objects that will
	 * give for each objective function the index and 
	 * value for this user defined objective function result
	 */	
	std::vector<OtherObjResult*> obj;
	
	/**
	 *
	 * Default constructor. 
	 */
	OtherObjectiveResult();
	
	/**
	 *
	 * Class destructor. 
	 */
	~OtherObjectiveResult();
	
};//OtherObjectiveResult


/*! \class OtherConstraintResult
 *  \brief The OtherConstraintResult  Class.
 * 
 * @author Robert Fourer, Jun Ma, Kipp Martin
 * @version 1.0, 03/14/2004
 * @since OS 1.0
 * 
 * \remarks
 * A class that allows the solver to report an
 * arbitrary result associated with constraints. 
 */
class OtherConstraintResult {
public:

	/** the name of the result the user is defining */
	std::string name;
	
	/** a brief description of the type of result */
	std::string description;
	
	
	/* a vector of OtherConResult objects that will
	 * give for each constraint the index and 
	 * value for this user defined objective function result
	 */	
	std::vector<OtherConResult*> con;	
	/**
	 *
	 * Default constructor. 
	 */
	OtherConstraintResult();
	
	/**
	 *
	 * Class destructor. 
	 */
	~OtherConstraintResult();
	
};//OtherConstraintResult

/*! \class ObjectiveValues
 *  \brief The ObjectiveValues  Class.
 * 
 * @author Robert Fourer, Jun Ma, Kipp Martin
 * @version 1.0, 03/14/2004
 * @since OS 1.0
 * 
 * \remarks
 * A class for reporting objective function values 
 */
class ObjectiveValues {
public:
	
	/** obj is a vector of ObjValue objects that
	 * give an index and objective function value for
	 * each objective function.
	 */
	std::vector<ObjValue*> obj;
	
	/**
	 *
	 * Default constructor. 
	 */
	ObjectiveValues();
	
	/**
	 *
	 * Class destructor. 
	 */
	~ObjectiveValues();
	
};//ObjectiveValues


/*! \class ConstraintValues
 *  \brief The ConstraintValues Class.
 * 
 * @author Robert Fourer, Jun Ma, Kipp Martin
 * @version 1.0, 03/14/2004
 * @since OS 1.0
 * 
 * \remarks
 * A class for reporting constraint values 
 */
class ConstraintValues{
public:

	/** con is a vector of ConValue objects that
	 * give an index and constraint function value for
	 * each constraint function.
	 */
	std::vector<ConValue*> con;
	
	/**
	 *
	 * Default constructor. 
	 */
	ConstraintValues();
	
	/**
	 *
	 * Class destructor. 
	 */
	~ConstraintValues();

};// class ConstraintValues


/*! \class DualVariableValues
 *  \brief The DualVariableValues Class.
 * 
 * @author Robert Fourer, Jun Ma, Kipp Martin
 * @version 1.0, 03/14/2004
 * @since OS 1.0
 * 
 * \remarks
 * A class for reporting dual variable values 
 */
class DualVariableValues {
public:


	/** con is a vector of DualVarValue objects that
	 * give an index and dual variable value for
	 * each constraint function.
	 */
	std::vector<DualVarValue*> con;
	
	/**
	 *
	 * Default constructor. 
	 */
	DualVariableValues();
	
	/**
	 *
	 * Class destructor. 
	 */
	~DualVariableValues();
	
};//DualVariableValues


	

/*! \class VariableSolution
 *  \brief The VariableSolution Class.
 * 
 * @author Robert Fourer, Jun Ma, Kipp Martin
 * @version 1.0, 03/14/2004
 * @since OS 1.0
 * 
 * \remarks
 * A class for reporting all of the types of solution values
 * associated with variables.
 */
class VariableSolution{
public:

	/** the number of types of variable results other
	 * than the value of the variable
	 */
	int numberOfOtherVariableResult;

	/** a pointer to an array of VariableValues objects */
	VariableValues *values;
	

	/** a pointer to an array of other pointer objects for 
	 * variables
	 */
	OtherVariableResult **other;

	/**
	 *
	 * Default constructor. 
	 */
	VariableSolution();
	
	/**
	 *
	 * Class destructor. 
	 */
	~VariableSolution();

};// class VariableSolution


/*! \class ObjectiveSolution
 *  \brief The ObjectiveSolution Class.
 * 
 * @author Robert Fourer, Jun Ma, Kipp Martin
 * @version 1.0, 03/14/2004
 * @since OS 1.0
 * 
 * \remarks
 * A class for reporting all of the types of solution values
 * associated with objective functions.
 */
class ObjectiveSolution {
public:

	/** the number of types of objective function results other
	 * than the basic objective function values
	 */
	int numberOfOtherObjectiveResult;
	
	/** a pointer to an array of ObjectiveValues objects */	
	ObjectiveValues *values;

	/** a pointer to an array of other pointer objects for 
	 * objective functions
	 */	
	OtherObjectiveResult **other; 

	/**
	 *
	 * Default constructor. 
	 */
	ObjectiveSolution();
	
	/**
	 *
	 * Class destructor. 
	 */
	~ObjectiveSolution();

};//ObjectiveSolution


/*! \class ConstraintSolution
 *  \brief The ConstraintSolution Class.
 * 
 * @author Robert Fourer, Jun Ma, Kipp Martin
 * @version 1.0, 03/14/2004
 * @since OS 1.0
 * 
 * \remarks
 * A class for reporting all of the types of solution values
 * associated with objective functions.
 */
class ConstraintSolution {

public:

	/** the number of types of constraint function results other
	 * than the basic constraint function values
	 */
	int numberOfOtherConstraintResult;
	
	/** a pointer to an array of ConstraintValues objects */
	 ConstraintValues *values;
	 
	/** a pointer to an array of DualVariableValues objects */
	 DualVariableValues *dualValues;
	
	/** a pointer to an array of other pointer objects for 
	 * constraint functions
	 */	 
	 OtherConstraintResult **other;
	
	/**
	 *
	 * Default constructor. 
	 */
	ConstraintSolution();
	
	/**
	 *
	 * Class destructor. 
	 */
	~ConstraintSolution();
	
};//ConstraintSolution


/*! \class OptimizationSolutionStatus
 *  \brief The OptimizationSolutionStatus Class.
 * 
 * @author Robert Fourer, Jun Ma, Kipp Martin
 * @version 1.0, 03/14/2004
 * @since OS 1.0
 * 
 * \remarks
 * A class for holding various attributes of a solution
 * status
 */	
class OptimizationSolutionStatus {
public:
	
	/** the type of solution status */
	std::string type;
	
	/** a description of the solution status type */
	std::string description;
	
	
	/**
	 * Default constructor. 
	 */
	OptimizationSolutionStatus();
	/**
	 *
	 * Class destructor. 
	 */
	~OptimizationSolutionStatus();
		
};//OptimizationSolutionStatus



/*! \class OptimizationSolution
 *  \brief The OptimizationSolution Class.
 * 
 * @author Robert Fourer, Jun Ma, Kipp Martin
 * @version 1.0, 03/14/2004
 * @since OS 1.0
 * 
 * \remarks
 * A class for reporting the various components of
 * an optimization solution.
 */
class OptimizationSolution{
public:

	/** the index of the objective function for which we are 
	 * reporting solution information 
	 */
	int objectiveIdx;
	
	/** status is a pointer to an OptimizationSolutionStatus
	 * object associated with this optimization solution
	 */
	OptimizationSolutionStatus *status;
	
	/** a message associated with this solution */
	std::string message;
	
	/** variables holds the solution information for
	 * the variables
	 */
	VariableSolution *variables;
	
	/** objectives holds the solution information
	 * for the objectives
	 */
	ObjectiveSolution *objectives;
	
	/** constraints holds the solution information
	 * for the constraints
	 */
	ConstraintSolution *constraints;
	
	//OtherOptimizationResult **other = null;
	/**
	 *
	 * Default constructor. 
	 */
	OptimizationSolution();
	/**
	 *
	 * Class destructor. 
	 */
	~OptimizationSolution();

};// class OptimizationSolution


/*! \class OptimizationResult
 *  \brief The OptimizationResult Class.
 * 
 * @author Robert Fourer, Jun Ma, Kipp Martin
 * @version 1.0, 03/14/2004
 * @since OS 1.0
 * 
 * \remarks
 * A class for holding information that might be associated
 * with an optimization solution.
 */
class OptimizationResult{
public:
	
	/** numberOfVariables is the number of variables reported 
	 * in the solution.
	 */
	int numberOfVariables;
	
	/** numberOfObjectives is the number of objective functions
	 * reported in the solution.
	 */
	int numberOfObjectives;

	/** numberOfConstrants is the number of constraint functions
	 * reported in the solution.
	 */
    int numberOfConstraints;

	/** numberOfSolubitons is the number of objective functions
	 * reported.
	 */	
	int numberOfSolutions;

	/** solution is an array of pointers to OptimizationSolution
	 * objects
	 */
	OptimizationSolution **solution;
	
	/**
	 *
	 * Default constructor. 
	 */
	OptimizationResult();
	/**
	 *
	 * Class destructor. 
	 */
	~OptimizationResult();

};// class OptimizationResult

/*! \class ResultData
 *  \brief The ResultData Class.
 * 
 * @author Robert Fourer, Jun Ma, Kipp Martin
 * @version 1.0, 03/14/2004
 * @since OS 1.0
 * 
 * \remarks
 * A class for the result data in an optimization.
 */
class ResultData{
public:

	/** optimization is a pointer to an OptimizationResult
	 * object
	 */
	OptimizationResult *optimization;

	/**
	 *
	 * Default constructor. 
	 */
	ResultData();
	/**
	 *
	 * Class destructor. 
	 */
	~ResultData();
};//class ResultData


/*! \class OSResult
 *  \brief The Result Class.
 * 
 * @author Robert Fourer, Jun Ma, Kipp Martin
 * @version 1.0, 03/14/2004
 * @since OS 1.0
 * 
 * \remarks
 * A class for holding all the solution information.
 */
class OSResult{

public:
	/**
	 *
	 * Default constructor. 
	 */
	OSResult(); 
	/**
	 *
	 * Class destructor. 
	 */
	~OSResult();
	/**
	 * resultHeader holds the first child of the OSResult specified by the OSiL Schema. 
	 */
	ResultHeader *resultHeader;
	/**
	 * resultData holds the second child of the OSResult specified by the OSiL Schema. 
	 */
	ResultData *resultData;
public:	
	
	/**
	 * m_iVariableNumber holds the variable number. 
	 */
	int m_iVariableNumber;
	
	/**
	 * m_iObjectiveNumber holds the objective number. 
	 */
	int m_iObjectiveNumber;
	
	/**
	 * m_iConstraintNumber holds the constraint number. 
	 */
	int m_iConstraintNumber;
	
	/**
	 * m_iNumberOfOtherVariableResult holds the number of OtherVariableResult objects. 
	 */	
	int m_iNumberOfOtherVariableResult;
	
	/**
	 * m_mdPrimalValues a vector of primal variables. 
	 */
	double *m_mdPrimalValues;
	
	/**
	 * m_mdDualValues a vector of primal variables. 
	 */
	double *m_mdDualValues;
	
	


public:

   	/**
	 * Get the general status.
	 * 
	 * @return the general status. 
	 */
	GeneralStatus* getGeneralStatus();
	
  	/**
	 * Get the general status type, which can be: 
	 * success, error, warning. 
	 * 
	 * @return the general status type, null if none. 
	 */
	std::string getGeneralStatusType();
	
   	/**
	 * Get the general status description. 
	 * 
	 * @return the general status description, null or empty std::string if none. 
	 */
	std::string getGeneralStatusDescription();

   	/**
	 * Get service name.
	 * 
	 * @return the service name. 
	 */
	std::string getServiceName();
	
  	/**
	 * Get service uri.
	 * 
	 * @return the service uri. 
	 */
	std::string getServiceURI();
	
  	/**
	 * Get instance name.
	 * 
	 * @return the instance name. 
	 */
	std::string getInstanceName();
	
  	/**
	 * Get the job id.
	 * 
	 * @return the job id. 
	 */
	std::string getJobID();
	
   	/**
	 * Get the general message. 
	 * 
	 * @return the general message. 
	 */
	std::string getGeneralMessage();

	/**
	 * Get one solution of optimal primal variable values. 
	 * 
	 * @param objIdx holds the objective index the optimal value corresponds to. 
	 * @return a double dense array of the optimal values, null if no optimal value. 
	 */
	double* getOptimalPrimalVariableValues(int objIdx);

	/**
	 * Get one solution of optimal dual variable values. 
	 * 
	 * @param objIdx holds the objective index the optimal value corresponds to. 
	 * @return a double dense array of the optimal dual values, null if no optimal value. 
	 */	
	double* getOptimalDualVariableValues(int objIdx);
	
	//Solution getSolution(int solIdx);

	/**
	 * Get the [i]th optimization solution status, where i equals the given solution index.   
	 * The solution status includes the status type, optional descriptions and possibly substatuses.
	 *  
	 * @param solIdx holds the solution index to get the solution status. 
	 * @return the optimization solution status that corresponds to solIdx, null if none.
	 * @see org.optimizationservices.oscommon.datastructure.osresult.OptimizationSolutionStatus
	 */	
	OptimizationSolutionStatus* getSolutionStatus( int solIdx);

	/**
	 * Get the [i]th optimization solution status type, where i equals the given solution index.   
	 * The solution status type can be: 
	 * unbounded, globallyOptimal, locallyOptimal, optimal, bestSoFar, feasible, infeasible, 
	 * stoppedByLimit, unsure, error, other 
	 * 
	 * @param solIdx holds the solution index to get the solution status type. 
	 * @return the optimization solution status type that corresponds to solIdx, null or empty std::string if none.
	 */	
	std::string getSolutionStatusType(int solIdx);

	/**
	 * Get the [i]th optimization solution status description, where i equals the given solution index.   
	 * 
	 * @param solIdx holds the solution index to get the solution status description. 
	 * @return the optimization solution status description that corresponds to solIdx, null or empty std::string if none.
	 */	
	std::string getSolutionStatusDescription(int solIdx);
	
	/**
	 * Get the [i]th optimization solution message, where i equals the given solution index.  
	 * 
	 * @param solIdx holds the solution index to get the solution message. 
	 * @return the optimization solution message that corresponds to solIdx, null or empty if none.
	 */	
	std::string getSolutionMessage(int solIdx);
	

	
	
	/**
	 * Get variable number. 
	 * 
	 * @return variable number, -1 if no information. 
	 */
	int getVariableNumber();
	
	/**
	 * Get objective number. 
	 * 
	 * @return objective number, -1 if no information. 
	 */
	int getObjectiveNumber();
	
	/**
	 * Get constraint number. 
	 * 
	 * @return constraint number, -1 if no information. 
	 */
	int getConstraintNumber();
	
	/**
	 * get the number of solutions. 
	 * 
	 * @return the number of solutions, 0 if none.  
	 */
	int getSolutionNumber();	
	
	/**
	 * Get numberOfOtherVariableResult. 
	 * 
	 * @return numberOfOtherVariableResult, -1 if no information. 
	 */
	int getNumberOfOtherVariableResult( int solIdx);
	
	// set methods
	//
	
	
	
   	/**
	 * Set the general status
	 * 
	 * @param status holds the general status.
	 * @return whether the general status is set successfully. 
	 */
	bool setGeneralStatus(GeneralStatus *status);
			
   	/**
	 * Set the general status type, which can be: 
	 * success, error, warning. 
	 * 
	 * @param type holds the general status type
	 * @return whether the general status type is set successfully or not. 
	 */
	bool setGeneralStatusType(std::string type);	
	
   	/**
	 * Set the general status description. 
	 * 
	 * @param description holds the general status description.
	 * @return whether the general status description is set successfully or not. 
	 */
	bool setGeneralStatusDescription(std::string description);
	
   	/**
	 * Set the general message. 
	 * 
	 * @param message holds the general message. 
	 * @return whether process message is set successfully. 
	 */
	bool setGeneralMessage(std::string message);

   	/**
	 * Set service name.
	 * 
	 * @param serviceName holds the name of the service. 
	 * @return whether the service name is set successfully. 
	 */
	bool setServiceName(std::string serviceName);
	
   	/**
	 * Set service uri.
	 * 
	 * @param serviceURI holds the uri of the service. 
	 * @return whether the service uri is set successfully. 
	 */
	bool setServiceURI(std::string serviceURI);	
	
   	/**
	 * Set instance name.
	 * 
	 * @param instanceName holds the name of the instance. 
	 * @return whether the instance name is set successfully. 
	 */
	bool setInstanceName(std::string instanceName);
		
   	/**
	 * Set job id.
	 * 
	 * @param jobID holds the job id. 
	 * @return whether the job id is set successfully. 
	 */
	bool setJobID(std::string jobID);
		
	
	/**
	 * Set the variable number. 
	 * 
	 * @param variableNumber holds the number of variables
	 * @return whether the variable number is set successfully or not. 
	 */
	bool setVariableNumber(int variableNumber);
	
	/**
	 * Set the objective number. 
	 * 
	 * @param objectiveNumber holds the number of objectives
	 * @return whether the objective number is set successfully or not. 
	 */
	bool setObjectiveNumber(int objectiveNumber);
	
	/**
	 * Set the constraint number. 
	 * 
	 * @param constraintNumber holds the number of constraints
	 * @return whether the constraint number is set successfully or not. 
	 */
	bool setConstraintNumber(int constraintNumber);
		
	/**
	 * set the number of solutions. This method must be called before setting other optimization solution 
	 * related results.  
	 * Before this method is called, the setVariableNumber(int), setObjectiveNumber(int), setConstraintNumber(int) methods 
	 * have to be called first. 
	 * 
	 * @param number holds the number of solutions to set. 
	 * @return whether the solution number is set successfully.   
	 * @see #setVariableNumber(int)
	 * @see #setObjectiveNumber(int)
	 * @see #setConstraintNumber(int)
	 */
	bool setSolutionNumber(int number);
	
	
	/**
	 * Set the [i]th optimization solution status, where i equals the given solution index.   
	 * The solution status includes the status type, optional descriptions and possibly substatuses. 
	 * Before this method is called, the setSolutionNumber(int) method has to be called first. 
	 * 
	 * @param solIdx holds the solution index to set the solution status.
	 * @param status holds the optimization solution status to set.  
	 * 
	 * @return whether the optimization solution status is set successfully or not. 
	 * @see org.optimizationservices.oscommon.datastructure.osresult.OptimizationSolutionStatus
	 * @see #setSolutionNumber(int)
	 */
	bool setSolutionStatus(int solIdx, std::string type, std::string description);

	/**
	 * Set the [i]th optimization solution's objective index, where i equals the given solution index.   
	 * The first objective's index should be -1, the second -2, and so on.  
	 * Before this method is called, the setSolutionNumber(int) method has to be called first. 
	 * 
	 * @param solIdx holds the solution index to set the objective index.
	 * @param objectiveIdx holds the objective index to set.  
	 * All the objective indexes are negative starting from -1 downward. 
	 * 
	 * @return whether the optimization objective index is set successfully or not. 
	 * @see #setSolutionNumber(int)
	 */
	bool setSolutionObjectiveIndex(int solIdx, int objectiveIdx);
	
	/**
	 * Set the [i]th optimization solution's primal variable values, where i equals the given solution index.   
	 * Before this method is called, the setSolutionNumber(int) method has to be called first. 
	 * @param solIdx holds the solution index to set the primal variable values. 
	 * @param x holds the a double dense array of variable values to set; it could be null if all variables are 0.
	 * 
	 * @return whether primal variable values are set successfully or not. 
	 * @see #setSolutionNumber(int)
	 */
	bool setPrimalVariableValues(int solIdx, double *x);
		
	/**
	 * Set the [i]th optimization solution's other (non-standard/solver specific)variable-related results, 
	 * where i equals the given solution index.   
	 * Before this method is called, the setSolutionNumber(int) method has to be called first. 
	 * This method then allocates the memory for the new OtherVariableResult objects
	 * @param solIdx is the solution index 
	 * @param numberOfOtherVariableResult holds the number of OtherVariableResult objects
	 * Each other variable result contains the name (required), an optional description (std::string) and an optional
	 * value (std::string). Each other variable result can also optionally contain an array OtherVarResult for each variable. 
	 * The OtherVarResult contains a variable idx (required) and an optional std::string value.   
	 * 
	 * @return whether the other variable results are set successfully or not. 
	 * @see org.optimizationservices.oscommon.datastructure.osresult.OtherVariableResult
	 * @see org.optimizationservices.oscommon.datastructure.osresult.OtherVarResult
	 * @see #setSolutionNumber(int)
	 */
	bool setNumberOfOtherVariableResult(int solIdx, int numberOfOtherVariableResult);
		
	/**
	 * Set the [i]th optimization solution's other (non-standard/solver specific)variable-related results, 
	 * where i equals the given solution index.   
	 * Before this method is called, the setSolutionNumber(int) method has to be called first. 
	 * @param solIdx holds the solution index  
	 * @param otherIdx holds the index of the new OtherVariableResult object
	 * @name holds the name of the other element
	 * @std::string a pointer to the values of the var element
	 *
	 * @return whether the other variable results are set successfully or not. 
	 * @see org.optimizationservices.oscommon.datastructure.osresult.OtherVariableResult
	 * @see org.optimizationservices.oscommon.datastructure.osresult.OtherVarResult
	 * @see #setSolutionNumber(int)
	 */
	bool setAnOtherVariableResult(int solIdx, int otherIdx, std::string name, std::string description, std::string *s);
		
	
	/**
	 * Set the [i]th optimization solution's objective values, where i equals the given solution index.   
	 * Usually one of the objective is what the solution was solved for (or based on). Its index should be indicated 
	 * in the solution's objectiveIdx attribute. Based on this objective's solution, the rest of the objective 
	 * values are (optionally) calculated. 
	 * Before this method is called, the setSolutionNumber(int) method has to be called first. 
	 * @param solIdx holds the solution index to set the objective values. 
	 * @param objectiveValues holds the a double dense array of objective values to set.
	 * Possibly only the objective that the solution is based on has the value, and the rest of the objective
	 * values all get a Double.NaN value, meaning that they are not calculated.   
	 * 
	 * @return whether objective values are set successfully or not. 
	 * @see #setSolutionNumber(int)
	 */
	bool setObjectiveValues(int solIdx, double *objectiveValues);
	

	/**
	 * Set the [i]th optimization solution's dual variable values, where i equals the given solution index. 
	 * The method allows setting dual values at both the constraints' lower and upper bounds.   
	 * Before this method is called, the setSolutionNumber(int) method has to be called first. 
	 * @param solIdx holds the solution index to set the dual variable values. 
	 * @param lbValues holds the a double dense array of variable dual values to set at the lower bounds; it could be null if all values are 0.
	 * @param ubValues holds the a double dense array of variable dual values to set at the upper bounds; it could be null if all values are 0.
	 * 
	 * @return whether dual variable values are set successfully or not. 
	 * @see #setSolutionNumber(int)
	 */	
	bool setDualVariableValues(int solIdx, double* lbValues, double* ubValues);
	
	/**
	 * Set the [i]th optimization solution's dual variable values, where i equals the given solution index. 
	 * The method allows setting dual values at both the constraints' lower and upper bounds.   
	 * Before this method is called, the setSolutionNumber(int) method has to be called first. 
	 * @param solIdx holds the solution index to set the dual variable values. 
	 * @param y holds the a double dense array of variable dual values; it could be null if all values are 0.	 * 
	 * @return whether dual variable values are set successfully or not. 
	 * @see #setSolutionNumber(int)
	 */	
	bool setDualVariableValues(int solIdx, double *y);
	
	/**
	 * Set the [i]th optimization solution's constraint values, where i equals the given solution index.   
	 * Before this method is called, the setSolutionNumber(int) method has to be called first. 
	 * @param solIdx holds the solution index to set the constraint values. 
	 * @param constraintValues holds the a double dense array of constraint values to set; it could be null if all constraint values are 0.
	 * 
	 * @return whether constraint values are set successfully or not. 
	 * @see #setSolutionNumber(int)
	 */
	bool setConstraintValues(int solIdx, double *constraintValues);



};
#endif
