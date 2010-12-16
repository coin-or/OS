/* $Id: OSGeneral.h 3172 2010-02-05 04:59:24Z Gassmann $ */
/** @file OSGeneral.h
 * 
 *
 * @author  Horand Gassmann, Jun Ma, Kipp Martin, 
 * @version 1.0, 19/07/2010
 * @since   OS2.2
 *
 * \remarks
 * Copyright (C) 2005-2010, Horand Gassmann, Jun Ma,  Kipp Martin,
 * Dalhousie University, Northwestern University, and the University of Chicago.
 * All Rights Reserved.
 * This software is licensed under the Common Public License. 
 * Please see the accompanying LICENSE file in root directory for terms.
 * 
 */

#ifndef OSGENERAL_H
#define OSGENERAL_H


#ifdef HAVE_CSTDLIB
# include <cstdlib>
#else
# ifdef HAVE_STDLIB_H
#  include <stdlib.h>
# endif
#endif

#include "OSConfig.h"

#include <string>
#include <vector>



/*! \class SparseMatrix
 * \brief a sparse matrix data structure
 */
class SparseMatrix {
	public:
	
	/**
	 * bDeleteArrays is true if we delete the arrays in garbage collection
	 * set to true by default
	 */
	bool bDeleteArrays;
	
	/**
	 * isColumnMajor holds whether the coefMatrix (AMatrix) holding linear program
	 * data is stored by column. If false, the matrix is stored by row.
	 */
	bool isColumnMajor;
	
	/**
	 * startSize is the dimension of the starts array
	 */
	int startSize;
	
	/**
	 * valueSize is the dimension of the starts array
	 */
	int valueSize;
	
	/**
	 * starts holds an integer array of start elements in coefMatrix (AMatrix),
	 * which points to the start of a column (row) of nonzero elements in coefMatrix (AMatrix).
	 */
	int* starts; 
	
	/**
	 * indexes holds an integer array of rowIdx (or colIdx) elements in coefMatrix (AMatrix).
	 * If the matrix is stored by column (row), rowIdx (colIdx) is the array of row (column) indices.
	 */
	int* indexes;

	/**
	 * values holds a double array of value elements in coefMatrix (AMatrix),
	 * which contains nonzero elements.
	 */
	double* values;
	
	/**
	 *
	 * Default constructor. 
	 */
	SparseMatrix();
	
	/**
	 * Constructor.
	 * 
	 * @param isColumnMajor holds whether the coefMatrix (AMatrix) holding linear program
	 * data is stored by column. If false, the matrix is stored by row.
	 * @param startSize holds the size of the start array.
	 * @param valueSize holds the size of the value and index arrays.
	 */
	SparseMatrix(bool isColumnMajor_, int startSize, int valueSize);
	/**
	 *
	 * Default destructor. 
	 */	
	~SparseMatrix();
	
	/**
	 * This method displays data structure in the matrix format.
	 * </p>
	 * @return
	 */
	bool display(int secondaryDim);

}; //SparseMatrix


/*! \class SparseVector
 * \brief a sparse vector data structure
 */
class SparseVector{
	public:
	
	/**
	 * Constructor.
	 * 
	 * @param number holds the size of the vector.
	 */
	SparseVector(int number);
	
	/**
	 *
	 * Default Constructor. 
	 */	
	SparseVector();
	
	/**
	 *
	 * Default destructor. 
	 */	
	~SparseVector();

	/**
	 * bDeleteArrays is true if we delete the arrays in garbage collection
	 * set to true by default
	 */
	bool bDeleteArrays;
	
	/**
	 * number is the number of elements in the indexes and values arrays.
	 */
	int number;
	
	/**
	 * indexes holds an integer array of indexes, which corresponding values are nonzero.
	 */
	int* indexes;

	/**
	 * values holds a double array of nonzero values.
	 */
	double* values;

}; //SparseVector


/*! \class SparseJacobianMatrix
 * \brief a sparse Jacobian matrix data structure
 */
class SparseJacobianMatrix {
	public:
	
	/**
	 * bDeleteArrays is true if we delete the arrays in garbage collection
	 * set to true by default
	 */
	bool bDeleteArrays;
	
	/**
	 * startSize is the dimension of the starts array -- should equal number of rows + 1
	 */
	int startSize;
	
	/**
	 * valueSize is the dimension of the values array
	 */
	int valueSize;
	
	/**
	 * starts holds an integer array of start elements, each start element
	 * pints to the start of partials for that row
	 */
	int* starts; 
	
	/**
	 * conVals holds an integer array of integers, conVals[i] is the number of constant terms
	 * in the gradient for row i.
	 */
	int* conVals; 
	
	/**
	 * indexes holds an integer array of variable indicies.
	 */
	int* indexes;

	/**
	 * values holds a double array of nonzero partial derivatives
	 */
	double* values;
	
	/**
	 *
	 * Default constructor. 
	 */
	SparseJacobianMatrix();
	
	/**
	 * Constructor.
	 * 
	 * @param startSize holds the size of the start array.
	 * @param valueSize holds the size of the value and index arrays.
	 */
	SparseJacobianMatrix(int startSize, int valueSize);

	/**
	 *
	 * Default destructor. 
	 */	
	~SparseJacobianMatrix();

}; //SparseJacobianMatrix





/*! \class SparseHessianMatrix SparseHessianMatrix.h "SparseHessianMatrix.h"
 *  \brief The in-memory representation of a SparseHessianMatrix..
 *
 * \remarks 
<p>  Store and uppertriangular Hessian Matrix in sparse format </p>
<p>  Assume there are n variables in what follows </p>

 *
 * 
 */
class SparseHessianMatrix {
	public:
	
	/**
	 * bDeleteArrays is true if we delete the arrays in garbage collection
	 * set to true by default
	 */
	bool bDeleteArrays;

	/**
	 * hessDimension is the number of nonzeros in each array.
	 */
	int hessDimension;
	
	/**
	 * hessRowIdx is an integer array of row indicies in the range 0, ..., n - 1.
	 */
	int* hessRowIdx; 
	
	/**
	 * hessColIdx is an integer array of column indicies in the range 0, ..., n - 1.
	 */
	int* hessColIdx; 
	
	/**
	 * hessValues is a double array of the Hessian values.
	 */
	double* hessValues;

	/**
	 *
	 * Default constructor. 
	 */
	SparseHessianMatrix();
	
	/**
	 * An Alternative Constructor.
	 * 
	 * @param startSize holds the size of the arrays.
	 * @param valueSize holds the size of the value and index arrays.
	 */
	SparseHessianMatrix(int startSize, int valueSize);

	/**
	 *
	 * Default destructor. 
	 */	
	~SparseHessianMatrix();

}; //SparseHessianMatrix

/*! \class QuadraticTerms
 * \brief a data structure for holding quadratic terms
 */
class QuadraticTerms {

	public:
	
	/**
	 * rowIndexes holds an integer array of row indexes of all the quadratic terms. 
	 * A negative integer corresponds to an objective row, e.g. -1 for 1st objective and -2 for 2nd.
	 */
	int* rowIndexes; 

	/**
	 * varOneIndexes holds an integer array of the first variable indexes of all the quadratic terms. 
	 */
	int* varOneIndexes; 

	/**
	 * varTwoIndexes holds an integer array of the second variable indexes of all the quadratic terms. 
	 */
	int* varTwoIndexes; 

	/**
	 * coefficients holds a double array all the quadratic term coefficients. 
	 */
	double* coefficients; 

	/**
	 *
	 * Default constructor. 
	 */
	QuadraticTerms();
	~QuadraticTerms();
}; //QuadraticTerms



/*! \class IntVector
 * \brief an integer Vector data structure
 */	
class IntVector{
public:
	IntVector();
	~IntVector();

	// alternate constructor
	IntVector(int n);

	/**
	 * bDeleteArrays is true if we delete the arrays in garbage collection
	 * set to true by default
	 */
	bool bDeleteArrays;
	int numberOfEl;
	int *el;

	/**
	 *  A method to compare two invectors
	 */	  
	bool IsEqual(IntVector *that);

	/**
	 *  set values into an IntVector
	 *  @param ni contains the dimension of the IntVector
	 *  @param i contains the array of values
	 */
 	bool setIntVector(int *i, int ni);

	/**
	 *  get the dimension of an IntVector
	 */
	int getNumberOfEl();

	/**
	 *  get an entry in the data array of an IntVector
	 *  @param j is the index of the entry that is to be retrieved
	 */
	int getEl(int j);


	/**
	 *  Get the integer data array of an IntVector
	 *  @param i is the location where the user wants to store the array
	 *  @return the value
	 *
	 *  @note it is the user's responsibility to reserve sufficient memory to hold the vector being returned.
	 */
	bool getEl(int *i);
};//class IntVector


/*! \class OtherOptionEnumeration
 *  brief an integer vector data structure used in OSOption and OSResult
 *
 *  This class extends IntVector by adding two string-valued elements, value and description
 */	
class OtherOptionEnumeration : public IntVector{
public:
	std::string value;
	std::string description;

	OtherOptionEnumeration();
	~OtherOptionEnumeration();

	// alternate constructor
	OtherOptionEnumeration(int n);

	bool IsEqual(OtherOptionEnumeration *that);

	/**
	 *  Set the indices for a particular level in an enumeration
	 *  @param value represents the value of this enumeration member
	 *  @param description holds additional information about this value
	 *  @param i contains the array of indices
	 *  @param ni contains the number of elements in i
	 */
	bool setOtherOptionEnumeration(std::string value, std::string description, int *i, int ni);


	/**
	 *  Get the value for a particular level in an enumeration
	 */
	std::string getValue();

	/**
	 *  Get the description for a particular level in an enumeration
	 */
	std::string getDescription();

};//class OtherOptionEnumeration



/*! \class DoubleVector
 * \brief a double vector data structure
 */
class DoubleVector{
public:
	DoubleVector();
	~DoubleVector();
	/**
	 * bDeleteArrays is true if we delete the arrays in garbage collection
	 * set to true by default
	 */
	bool bDeleteArrays;
	int numberOfEl;
	double *el;			

	bool IsEqual(DoubleVector *that);
};//class DoubleVector


/*! \struct IndexValuePair
 *  \brief A commonly used structure holding an index-value pair
 */
struct IndexValuePair{
	/** idx holds the index of an entity (such as a variable, constraint, objective)
	 *  that is part of a sparse vector
	 */
	int idx;

	/** value is a double that holds the value of the entity
	 */ 
	double value;
		
};

/*! \class BasisStatus
 * \brief a data structure to represent an LP basis on both input and output 
 *
 */
class BasisStatus{
public:
	BasisStatus();
	~BasisStatus();

	IntVector* basic;
	IntVector* atLower;
	IntVector* atUpper;
	IntVector* isFree;
	IntVector* superbasic;
	IntVector* unknown;
	bool IsEqual(BasisStatus *that);

/**
 *  Set the indices for a particular status
 *  @param status is a string representing the allowed statuses 
 *  (at present "basic", "atLower", "atUpper", "isFree", "superbasic", "unknown")
 *  @param i contains the array of indices
 *  @param ni contains the number of elements in i
 */
	bool setIntVector(int status, int *i, int ni);


/**
 *  Get the number of indices for a particular status
 *  @param status is a string representing the allowed statuses 
 *  (at present "basic", "atLower", "atUpper", "isFree", "superbasic", "unknown")
 *  @return the number of indices or -1 if the object does not exist
 */
	int getNumberOfEl(int status);


/**
 *  Get one entry in the array of indices for a particular status
 *  @param status is a string representing the allowed statuses 
 *  (at present "basic", "atLower", "atUpper", "isFree", "superbasic", "unknown")
 *  @param j is the (zero-based) position of the entry within the array
 *  @return the value
 */
	int getEl(int status, int j);

/**
 *  Get the entire array of indices for a particular status
 *  @param status is a string representing the allowed statuses 
 *  (at present "basic", "atLower", "atUpper", "isFree", "superbasic", "unknown")
 *  @param i is the location where the user wants to store the array
 *  @return the value
 *
 *  @note it is the user's responsibility to reserve sufficient memory to hold the vector being returned.
 */
	bool getIntVector(int status, int *i);
};//class BasisStatus 
	
class OSGeneral{

};

/***************************************************************************************
 * In the schemas there is a growing number of string elements that can only take 
 * a small number of values. One implementation in C++ uses enumerations, but the
 * elements appear in the schemas as strings, so they must be stored internally
 * as strings also. Below we list the enumerations and provide two utility methods
 * that make working with them convenient:
 * return...() functions that return the integer value associated with that enumeration
 * verify...() functions that check that a string has a legal value for the enumeration
 ***************************************************************************************/

enum ENUM_CPUSPEEDUNIT 
{
	ENUM_CPUSPEEDUNIT_hertz = 1,
	ENUM_CPUSPEEDUNIT_kilohertz,
	ENUM_CPUSPEEDUNIT_megahertz,
	ENUM_CPUSPEEDUNIT_gigahertz,
	ENUM_CPUSPEEDUNIT_terahertz,
	ENUM_CPUSPEEDUNIT_flops,
	ENUM_CPUSPEEDUNIT_kiloflops,
	ENUM_CPUSPEEDUNIT_megaflops,
	ENUM_CPUSPEEDUNIT_gigaflops,
	ENUM_CPUSPEEDUNIT_teraflops,
	ENUM_CPUSPEEDUNIT_petaflops
};

inline int returnCPUSpeedUnit(std::string unit)
{
	if (unit == "hertz"    ) return ENUM_CPUSPEEDUNIT_hertz;
	if (unit == "kilohertz") return ENUM_CPUSPEEDUNIT_kilohertz;
	if (unit == "megahertz") return ENUM_CPUSPEEDUNIT_megahertz;
	if (unit == "gigahertz") return ENUM_CPUSPEEDUNIT_gigahertz;
	if (unit == "terahertz") return ENUM_CPUSPEEDUNIT_terahertz;
	if (unit == "flops"    ) return ENUM_CPUSPEEDUNIT_flops;
	if (unit == "kiloflops") return ENUM_CPUSPEEDUNIT_kiloflops;
	if (unit == "megaflops") return ENUM_CPUSPEEDUNIT_megaflops;
	if (unit == "gigaflops") return ENUM_CPUSPEEDUNIT_gigaflops;
	if (unit == "teraflops") return ENUM_CPUSPEEDUNIT_teraflops;
	if (unit == "petaflops") return ENUM_CPUSPEEDUNIT_petaflops;
	return 0;
}//returnCPUSpeedUnit

inline bool verifyCPUSpeedUnit(std::string unit)
{
	return (returnCPUSpeedUnit(unit) > 0);
}//verifyCPUSpeedUnit

enum ENUM_STORAGEUNIT 
{
	ENUM_STORAGEUNIT_byte = 1,
	ENUM_STORAGEUNIT_kilobyte,
	ENUM_STORAGEUNIT_megabyte,
	ENUM_STORAGEUNIT_gigabyte,
	ENUM_STORAGEUNIT_terabyte,
	ENUM_STORAGEUNIT_petabyte,
	ENUM_STORAGEUNIT_exabyte,
	ENUM_STORAGEUNIT_zettabyte,
	ENUM_STORAGEUNIT_yottabyte
};

inline int returnStorageUnit(std::string unit)
{
	if (unit == "byte"     ) return ENUM_STORAGEUNIT_byte;
	if (unit == "kilobyte" ) return ENUM_STORAGEUNIT_kilobyte;
	if (unit == "megabyte" ) return ENUM_STORAGEUNIT_megabyte;
	if (unit == "gigabyte" ) return ENUM_STORAGEUNIT_gigabyte;
	if (unit == "terabyte" ) return ENUM_STORAGEUNIT_terabyte;
	if (unit == "petabyte" ) return ENUM_STORAGEUNIT_petabyte;
	if (unit == "exabyte"  ) return ENUM_STORAGEUNIT_exabyte;
	if (unit == "zettabyte") return ENUM_STORAGEUNIT_zettabyte;
	if (unit == "yottabyte") return ENUM_STORAGEUNIT_yottabyte;
	return 0;
}//returnStorageUnit

inline bool verifyStorageUnit(std::string unit)
{
	return (returnStorageUnit(unit) > 0);
}//verifyCPUSpeedUnit

enum ENUM_TIMEUNIT 
{
	ENUM_TIMEUNIT_tick = 1,
	ENUM_TIMEUNIT_millisecond,
	ENUM_TIMEUNIT_second,
	ENUM_TIMEUNIT_minute,
	ENUM_TIMEUNIT_hour,
	ENUM_TIMEUNIT_day,
	ENUM_TIMEUNIT_week,
	ENUM_TIMEUNIT_month,
	ENUM_TIMEUNIT_year
};

inline int returnTimeUnit(std::string unit)
{
	if (unit == "tick"       ) return ENUM_TIMEUNIT_tick;
	if (unit == "millisecond") return ENUM_TIMEUNIT_millisecond;
	if (unit == "second"     ) return ENUM_TIMEUNIT_second;
	if (unit == "minute"     ) return ENUM_TIMEUNIT_minute;
	if (unit == "hour"       ) return ENUM_TIMEUNIT_hour;
	if (unit == "day"        ) return ENUM_TIMEUNIT_day;
	if (unit == "week"       ) return ENUM_TIMEUNIT_week;
	if (unit == "month"      ) return ENUM_TIMEUNIT_month;
	if (unit == "year"       ) return ENUM_TIMEUNIT_year;
	return 0;
}//returnTimeUnit

inline bool verifyTimeUnit(std::string unit)
{
	return (returnTimeUnit(unit) > 0);
}//verifyTimeUnit

enum ENUM_TIMETYPE 
{
	ENUM_TIMETYPE_cpuTime = 1,
	ENUM_TIMETYPE_elapsedTime,
	ENUM_TIMETYPE_other
};

inline int returnTimeType(std::string type)
{
	if (type == "cpuTime"    ) return ENUM_TIMETYPE_cpuTime;
	if (type == "elapsedTime") return ENUM_TIMETYPE_elapsedTime;
	if (type == "other"      ) return ENUM_TIMETYPE_other;
	return 0;
}//returnTimeType

inline bool verifyTimeType(std::string type)
{
	return (returnTimeType(type) > 0);
}//verifyTimeType

enum ENUM_TIMECATEGORY 
{
	ENUM_TIMECATEGORY_total = 1,
	ENUM_TIMECATEGORY_input,
	ENUM_TIMECATEGORY_preprocessing,
	ENUM_TIMECATEGORY_optimization,
	ENUM_TIMECATEGORY_postprocessing,
	ENUM_TIMECATEGORY_output,
	ENUM_TIMECATEGORY_other
};

inline int returnTimeCategory(std::string category)
{
	if (category == "total"         ) return ENUM_TIMECATEGORY_total;
	if (category == "input"         ) return ENUM_TIMECATEGORY_input;
	if (category == "preprocessing" ) return ENUM_TIMECATEGORY_preprocessing;
	if (category == "optimization"  ) return ENUM_TIMECATEGORY_optimization;
	if (category == "postprocessing") return ENUM_TIMECATEGORY_postprocessing;
	if (category == "output"        ) return ENUM_TIMECATEGORY_output;
	if (category == "other"         ) return ENUM_TIMECATEGORY_other;
	return 0;
}//returnTimeCategory

inline bool verifyTimeCategory(std::string category)
{
	return (returnTimeCategory(category) > 0);
}//verifyTimeCategory

enum ENUM_LOCATIONTYPE 
{
	ENUM_LOCATIONTYPE_local = 1,
	ENUM_LOCATIONTYPE_http,
	ENUM_LOCATIONTYPE_ftp
};

inline int returnLocationType(std::string type)
{
	if (type == "local") return ENUM_LOCATIONTYPE_local;
	if (type == "http" ) return ENUM_LOCATIONTYPE_http;
	if (type == "ftp"  ) return ENUM_LOCATIONTYPE_ftp;
	return 0;
}//returnLocationType

inline bool verifyLocationType(std::string type)
{
	return (returnLocationType(type) > 0);
}//verifyLocationType

enum ENUM_TRANSPORT_TYPE 
{
	ENUM_TRANSPORT_TYPE_osp = 1,
	ENUM_TRANSPORT_TYPE_http,
	ENUM_TRANSPORT_TYPE_smtp,
	ENUM_TRANSPORT_TYPE_ftp,
	ENUM_TRANSPORT_TYPE_other
};

inline int returnTransportType(std::string type)
{
	if (type == "osp"  ) return ENUM_TRANSPORT_TYPE_osp;
	if (type == "http" ) return ENUM_TRANSPORT_TYPE_http;
	if (type == "smtp" ) return ENUM_TRANSPORT_TYPE_smtp;
	if (type == "ftp"  ) return ENUM_TRANSPORT_TYPE_ftp;
	if (type == "other") return ENUM_TRANSPORT_TYPE_other;
	return 0;
}//returnTransportType

inline bool verifyTransportType(std::string type)
{
	return (returnTransportType(type) > 0);
}//verifyTransportType

enum ENUM_SERVICE_TYPE 
{
	ENUM_SERVICE_TYPE_analyzer = 1,
	ENUM_SERVICE_TYPE_solver,
	ENUM_SERVICE_TYPE_scheduler,
	ENUM_SERVICE_TYPE_modeler,
	ENUM_SERVICE_TYPE_registry,
	ENUM_SERVICE_TYPE_agent,
	ENUM_SERVICE_TYPE_simulations
};

inline int returnServiceType(std::string type)
{
	if (type == "analyzer"   ) return ENUM_SERVICE_TYPE_analyzer;
	if (type == "solver"     ) return ENUM_SERVICE_TYPE_solver;
	if (type == "scheduler"  ) return ENUM_SERVICE_TYPE_scheduler;
	if (type == "modeler"    ) return ENUM_SERVICE_TYPE_modeler;
	if (type == "registry"   ) return ENUM_SERVICE_TYPE_registry;
	if (type == "agent"      ) return ENUM_SERVICE_TYPE_agent;
	if (type == "simulations") return ENUM_SERVICE_TYPE_simulations;
	return 0;
}//returnServiceType

inline bool verifyServiceType(std::string type)
{
	return (returnServiceType(type) > 0);
}//verifyServiceType

enum ENUM_GENERAL_RESULT_STATUS 
{
	ENUM_GENERAL_RESULT_STATUS_error = 1,
	ENUM_GENERAL_RESULT_STATUS_warning,
	ENUM_GENERAL_RESULT_STATUS_normal
};

inline int returnGeneralResultStatus(std::string status)
{
	if (status == "error"  ) return ENUM_GENERAL_RESULT_STATUS_error;
	if (status == "warning") return ENUM_GENERAL_RESULT_STATUS_warning;
	if (status == "normal" ) return ENUM_GENERAL_RESULT_STATUS_normal;
	return 0;
}//returnGeneralResultStatus

inline bool verifyGeneralResultStatus(std::string status)
{
	return (returnGeneralResultStatus(status) > 0);
}//verifyGeneralResultStatus

enum ENUM_SYSTEM_CURRENT_STATE 
{
	ENUM_SYSTEM_CURRENT_STATE_busy = 1,
	ENUM_SYSTEM_CURRENT_STATE_busyButAccepting,
	ENUM_SYSTEM_CURRENT_STATE_idle,
	ENUM_SYSTEM_CURRENT_STATE_idleButNotAccepting,
	ENUM_SYSTEM_CURRENT_STATE_noResponse
};

inline int returnSystemCurrentState(std::string status)
{
	if (status == "busy"               ) return ENUM_SYSTEM_CURRENT_STATE_busy;
	if (status == "busyButAccepting"   ) return ENUM_SYSTEM_CURRENT_STATE_busyButAccepting;
	if (status == "idle"               ) return ENUM_SYSTEM_CURRENT_STATE_idle;
	if (status == "idleButNotAccepting") return ENUM_SYSTEM_CURRENT_STATE_idleButNotAccepting;
	if (status == "noResponse"         ) return ENUM_SYSTEM_CURRENT_STATE_noResponse;
	return 0;
}//returnSystemCurrentState

inline bool verifySystemCurrentState(std::string status)
{
	return (returnSystemCurrentState(status) > 0);
}//verifySystemCurrentState

enum ENUM_JOB_STATUS 
{
	ENUM_JOB_STATUS_waiting = 1,
	ENUM_JOB_STATUS_running,
	ENUM_JOB_STATUS_killed,
	ENUM_JOB_STATUS_finished,
	ENUM_JOB_STATUS_unknown
};

inline int returnJobStatus(std::string status)
{
	if (status == "waiting" ) return ENUM_JOB_STATUS_waiting;
	if (status == "running" ) return ENUM_JOB_STATUS_running;
	if (status == "killed"  ) return ENUM_JOB_STATUS_killed;
	if (status == "finished") return ENUM_JOB_STATUS_finished;
	if (status == "unknown" ) return ENUM_JOB_STATUS_unknown;
	return 0;
}//returnJobStatus

inline bool verifyJobStatus(std::string status)
{
	return (returnJobStatus(status) > 0);
}//verifyJobStatus


enum ENUM_BASIS_STATUS 
{
	ENUM_BASIS_STATUS_basic = 1,
	ENUM_BASIS_STATUS_atLower,
	ENUM_BASIS_STATUS_atUpper,
	ENUM_BASIS_STATUS_isFree,
	ENUM_BASIS_STATUS_superbasic,
	ENUM_BASIS_STATUS_unknown
};

inline int returnBasisStatus(std::string status)
{
	if (status == "basic"     ) return ENUM_BASIS_STATUS_basic;
	if (status == "atLower"   ) return ENUM_BASIS_STATUS_atLower;
	if (status == "atUpper"   ) return ENUM_BASIS_STATUS_atUpper;
	if (status == "isFree"    ) return ENUM_BASIS_STATUS_isFree;
	if (status == "superBasic") return ENUM_BASIS_STATUS_superbasic;
	if (status == "unknown"   ) return ENUM_BASIS_STATUS_unknown;
	return 0;
}//returnBasisStatus

inline bool verifyBasisStatus(std::string status)
{
	return (returnBasisStatus(status) > 0);
}//verifyBasisStatus

enum ENUM_SOLUTION_STATUS 
{
	ENUM_SOLUTION_STATUS_unbounded = 1,
	ENUM_SOLUTION_STATUS_globallyOptimal,
	ENUM_SOLUTION_STATUS_locallyOptimal,
	ENUM_SOLUTION_STATUS_optimal,
	ENUM_SOLUTION_STATUS_bestSoFar,
	ENUM_SOLUTION_STATUS_feasible,
	ENUM_SOLUTION_STATUS_infeasible,
	ENUM_SOLUTION_STATUS_unsure,
	ENUM_SOLUTION_STATUS_error,
	ENUM_SOLUTION_STATUS_other
};

inline int returnSolutionStatus(std::string status)
{
	if (status == "unbounded"      ) return ENUM_SOLUTION_STATUS_unbounded;
	if (status == "globallyOptimal") return ENUM_SOLUTION_STATUS_globallyOptimal;
	if (status == "locallyOptimal" ) return ENUM_SOLUTION_STATUS_locallyOptimal;
	if (status == "optimal"        ) return ENUM_SOLUTION_STATUS_optimal;
	if (status == "bestSoFar"      ) return ENUM_SOLUTION_STATUS_bestSoFar;
	if (status == "feasible"       ) return ENUM_SOLUTION_STATUS_feasible;
	if (status == "infeasible"     ) return ENUM_SOLUTION_STATUS_infeasible;
	if (status == "unsure"         ) return ENUM_SOLUTION_STATUS_unsure;
	if (status == "error"          ) return ENUM_SOLUTION_STATUS_error;
	if (status == "other"          ) return ENUM_SOLUTION_STATUS_other;
	return 0;
}//returnSolutionStatus

inline bool verifySolutionStatus(std::string status)
{
	return (returnSolutionStatus(status) > 0);
}//verifySolutionStatus

enum ENUM_SOLUTION_SUBSTATUSTYPE 
{
	ENUM_SOLUTION_SUBSTATUSTYPE_stoppedByLimit = 1,
	ENUM_SOLUTION_SUBSTATUSTYPE_stoppedByBounds,
	ENUM_SOLUTION_SUBSTATUSTYPE_other
};

inline int returnSolutionSubstatusType(std::string type)
{
	if (type == "stoppedByLimit" ) return ENUM_SOLUTION_SUBSTATUSTYPE_stoppedByLimit;
	if (type == "stoppedByBounds") return ENUM_SOLUTION_SUBSTATUSTYPE_stoppedByBounds;
	if (type == "other"          ) return ENUM_SOLUTION_SUBSTATUSTYPE_other;
	return 0;
}//returnSolutionSubstatusType

inline bool verifySolutionSubstatusType(std::string type)
{
	return (returnSolutionSubstatusType(type) > 0);
}//verifySolutionSubstatusType

enum ENUM_VARTYPE 
{
	ENUM_VARTYPE_CONTINUOUS = 1,
	ENUM_VARTYPE_INTEGER,
	ENUM_VARTYPE_BINARY,
	ENUM_VARTYPE_SEMICONTINUOUS,
	ENUM_VARTYPE_SEMIINTEGER,
	ENUM_VARTYPE_STRING
};

inline int returnVarType(char vt)
{
	if (vt == 'C') return ENUM_VARTYPE_CONTINUOUS;
	if (vt == 'B') return ENUM_VARTYPE_BINARY;
	if (vt == 'I') return ENUM_VARTYPE_INTEGER;
	if (vt == 'S') return ENUM_VARTYPE_STRING;
	if (vt == 'D') return ENUM_VARTYPE_SEMICONTINUOUS;
	if (vt == 'J') return ENUM_VARTYPE_SEMIINTEGER;
	return 0;
}//returnVarType

inline bool verifyVarType(char vt)
{
	return (returnVarType(vt) > 0);
}//verifyVarType

#endif
