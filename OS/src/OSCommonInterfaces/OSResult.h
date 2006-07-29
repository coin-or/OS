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
#include <string>



/**
*
* <p>A data structure class that corresponds to an xml element in the OSaL schema.  
*  
* </p>
* @author Robert Fourer, Jun Ma, Kipp Martin
* @version 1.0, 03/14/2004
* @since OS 1.0
*/
class GeneralStatus {

public:
		
	std::string type;
		
	std::string description;
	
//public GeneralSubstatus[] substatus = null;

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


class ResultHeader{
public:
	GeneralStatus *generalStatus;
	std::string serviceURI;
	std::string serviceName;
	std::string instanceName;
	std::string jobID;
	std::string time;
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

struct ResultParameters
{
	int numberOfVariables;
	int numberOfObjectives;
	int numberOfConstraints;
	int numberOfSolutions;
}; 





/**
*
* <p>A data structure class that corresponds to an xml element in the OSrL schema.  
*  
* </p>
* @author Robert Fourer, Jun Ma, Kipp Martin
* @version 1.0, 03/14/2004
* @since OS 1.0
*/
class VarValue{
public:

	int idx;
	
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

/**
*
* <p>A data structure class that corresponds to an xml element in the OSrL schema.  
*  
* </p>
* @author Robert Fourer, Jun Ma, Kipp Martin
* @version 1.0, 03/14/2004
* @since OS 1.0
*/
class OtherVarResult {
public:
	
	int idx;
	
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

/**
*
* <p>A data structure class that corresponds to an xml element in the OSrL schema.  
*  
* </p>
* @author Robert Fourer, Jun Ma, Kipp Martin
* @version 1.0, 03/14/2004
* @since OS 1.0
*/
class OtherObjResult {
public:
	
	int idx;
	
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


/**
*
* <p>A data structure class that corresponds to an xml element in the OSrL schema.  
*  
* </p>
* @author Robert Fourer, Jun Ma, Kipp Martin
* @version 1.0, 03/14/2004
* @since OS 1.0
*/
class OtherConResult {
public:
	
	int idx;
	
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


/**
*
* <p>A data structure class that corresponds to an xml element in the OSrL schema.  
*  
* </p>
* @author Robert Fourer, Jun Ma, Kipp Martin
* @version 1.0, 03/14/2004
* @since OS 1.0
*/
class ObjValue {
public:	
	int idx;
	
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



/**
*
* <p>A data structure class that corresponds to an xml element in the OSrL schema.  
*  
* </p>
* @author Robert Fourer, Jun Ma, Kipp Martin
* @version 1.0, 03/14/2004
* @since OS 1.0
*/
class ConValue{
public:

	int idx;
	
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

};// class VarValue

/**
*
* <p>A data structure class that corresponds to an xml element in the OSrL schema.  
*  
* </p>
* @author Robert Fourer, Jun Ma, Kipp Martin
* @version 1.0, 03/14/2004
* @since OS 1.0
*/
class DualVarValue {
public:	
	int idx;
	
	double lbValue;
	
	double ubValue;
	
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

class VariableValues{
public:

	VarValue **var;
	
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


/**
*
* <p>A data structure class that corresponds to an xml element in the OSrL schema.  
*  
* </p>
* @author Robert Fourer, Jun Ma, Kipp Martin
* @version 1.0, 03/14/2004
* @since OS 1.0
*/
class OtherVariableResult {
public:

	std::string name;
	
	std::string description;
	
	OtherVarResult **var;
	
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


/**
*
* <p>A data structure class that corresponds to an xml element in the OSrL schema.  
*  
* </p>
* @author Robert Fourer, Jun Ma, Kipp Martin
* @version 1.0, 03/14/2004
* @since OS 1.0
*/
class OtherObjectiveResult {
public:

	std::string name;
	
	std::string description;
	
	
	OtherObjResult **obj;
	
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


/**
*
* <p>A data structure class that corresponds to an xml element in the OSrL schema.  
*  
* </p>
* @author Robert Fourer, Jun Ma, Kipp Martin
* @version 1.0, 03/14/2004
* @since OS 1.0
*/
class OtherConstraintResult {
public:

	std::string name;
	
	std::string description;
	
	
	OtherConResult **con;
	
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

/**
*
* <p>A data structure class that corresponds to an xml element in the OSrL schema.  
*  
* </p>
* @author Robert Fourer, Jun Ma, Kipp Martin
* @version 1.0, 03/14/2004
* @since OS 1.0
*/
class ObjectiveValues {
public:
	
	ObjValue **obj;
	
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


/**
*
* <p>A data structure class that corresponds to an xml element in the OSrL schema.  
*  
* </p>
* @author Robert Fourer, Jun Ma, Kipp Martin
* @version 1.0, 03/14/2004
* @since OS 1.0
*/
class ConstraintValues{
public:
	ConValue **con;
	
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


/**
*
* <p>A data structure class that corresponds to an xml element in the OSrL schema.  
*  
* </p>
* @author Robert Fourer, Jun Ma, Kipp Martin
* @version 1.0, 03/14/2004
* @since OS 1.0
*/
class DualVariableValues {
public:
	
	DualVarValue **con;
	
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


	


class VariableSolution{
public:

	int numberOfOtherVariableResult;

	VariableValues *values;
	
	//VariableStringValues *valuesString;

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

/**
*
* <p>A data structure class that corresponds to an xml element in the OSrL schema.  
*  
* </p>
* @author Robert Fourer, Jun Ma, Kipp Martin
* @version 1.0, 03/14/2004
* @since OS 1.0
*/
class ObjectiveSolution {
public:

	int numberOfOtherObjectiveResult;
		
	ObjectiveValues *values;
	
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

/**
*
* <p>A data structure class that corresponds to an xml element in the OSrL schema.  
*  
* </p>
* @author Robert Fourer, Jun Ma, Kipp Martin
* @version 1.0, 03/14/2004
* @since OS 1.0
*/
class ConstraintSolution {

public:

	int numberOfOtherConstraintResult;
	
	 ConstraintValues *values;
	 
	 DualVariableValues *dualValues;
	 
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

/**
*
* <p>A data structure class that corresponds to an xml element in the OSaL schema.  
*  
* </p>
* @author Robert Fourer, Jun Ma, Kipp Martin
* @version 1.0, 03/14/2004
* @since OS 1.0
*/
class OptimizationSolutionStatus {
public:
	
	std::string type;
	
	std::string description;
	
	//public OptimizationSolutionSubstatus[] substatus = null;
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



/**
*
* <p>A data structure class that corresponds to an xml element in the OSrL schema.  
*  
* </p>
* @author Robert Fourer, Jun Ma, Kipp Martin
* @version 1.0, 03/14/2004
* @since OS 1.0
*/
class OptimizationSolution{
public:
	int objectiveIdx;
	
	OptimizationSolutionStatus *status;
	
	std::string message;
	
	VariableSolution *variables;
	
	ObjectiveSolution *objectives;
	
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



class OptimizationResult{
public:


	
	int numberOfVariables;
	
	int numberOfObjectives;

    int numberOfConstraints;
	
	int numberOfSolutions;

	OptimizationSolution **solution;
	
	//OSAnalysis osal = null;

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


class ResultData{
public:
	//ProcessStatistics *statistics;
	//OtherResult *other;
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
