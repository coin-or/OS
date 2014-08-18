/* $Id: OSGeneral.h 3172 2010-02-05 04:59:24Z Gassmann $ */
/** @file OSGeneral.h
 *
 *
 * @author  Horand Gassmann, Jun Ma, Kipp Martin
 *
 * \remarks
 * Copyright (C) 2005-2014, Horand Gassmann, Jun Ma,  Kipp Martin,
 * Northwestern University, and the University of Chicago.
 * All Rights Reserved.
 * This software is licensed under the Eclipse Public License.
 * Please see the accompanying LICENSE file in root directory for terms.
 *
 */

#ifndef OSGENERAL_H
#define OSGENERAL_H

#include "OSConfig.h"
#include "OSParameters.h"
#include "OSnLNode.h"

#include <string>
#include <vector>


/***************************************************************************************
 * In the schemas there is a growing number of string elements that can only take
 * a small number of values. In C++ this can be implemented using enumerations, but the
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

/**
 *  Enumeration for the different states that can be used in representating a basis
 *  The last state, ENUM_BASIS_STATUS_NUMBER_OF_STATES, is used *only* to record the
 *  number of states, which makes it easier to convert between different representations.
 *  (For instance, AMPL uses a different order, so there may be a need to recode values.
 *   See OSosrl2ampl.cpp for an application.) 
 */
enum ENUM_BASIS_STATUS
{
    ENUM_BASIS_STATUS_basic = 0,
    ENUM_BASIS_STATUS_atLower,
    ENUM_BASIS_STATUS_atUpper,
    ENUM_BASIS_STATUS_atEquality,
    ENUM_BASIS_STATUS_isFree,
    ENUM_BASIS_STATUS_superbasic,
    ENUM_BASIS_STATUS_unknown,
    ENUM_BASIS_STATUS_NUMBER_OF_STATES
};

inline int returnBasisStatus(std::string status)
{
    if (status == "basic"     ) return ENUM_BASIS_STATUS_basic;
    if (status == "atLower"   ) return ENUM_BASIS_STATUS_atLower;
    if (status == "atUpper"   ) return ENUM_BASIS_STATUS_atUpper;
    if (status == "atEquality") return ENUM_BASIS_STATUS_atEquality;
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

enum ENUM_PROBLEM_COMPONENT
{
    ENUM_PROBLEM_COMPONENT_variables = 1,
    ENUM_PROBLEM_COMPONENT_objectives,
    ENUM_PROBLEM_COMPONENT_constraints
};

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


enum ENUM_PATHPAIR
{
    ENUM_PATHPAIR_input_dir = 1,
    ENUM_PATHPAIR_input_file,
    ENUM_PATHPAIR_output_file,
    ENUM_PATHPAIR_output_dir
};

/**
 * An enum to track the many different types of values that a matrix can contain
 * Note that these types are partially ordered, which makes it easier to infer a matrix's type
 * from the types of its constructors
 */
enum ENUM_MATRIX_TYPE
{
    ENUM_MATRIX_TYPE_zero = 1,        // matrix is empty

    ENUM_MATRIX_TYPE_constant = 10,   // matrix elements contain constant values
    ENUM_MATRIX_TYPE_linear,          // matrix contains linear expressions
    ENUM_MATRIX_TYPE_quadratic,       // matrix contains quadratic expressions
    ENUM_MATRIX_TYPE_general,         // matrix contains general nonlinear expressions

    ENUM_MATRIX_TYPE_varref = 20,     // matrix elements contain indexes of variables in the core
    ENUM_MATRIX_TYPE_conref,          // matrix elements contain indexes of objectives in the core
    ENUM_MATRIX_TYPE_objref,          // matrix elements contain indexes of constraints in the core
    ENUM_MATRIX_TYPE_mixedref,        // mixed reference to objectives and constraints

    ENUM_MATRIX_TYPE_pospattern = 30, // matrix contains ones for matrix elements that should be included
    ENUM_MATRIX_TYPE_negpattern,      // matrix contains ones for matrix elements that should be zeroed out

    ENUM_MATRIX_TYPE_jumbled = 40,    // mixture of matrix elements that is unsuited for further use
    ENUM_MATRIX_TYPE_unknown = 99

};

inline int returnMatrixType(std::string type)
{
    if (type == "zero"      ) return ENUM_MATRIX_TYPE_zero;
    if (type == "constant"  ) return ENUM_MATRIX_TYPE_constant;
    if (type == "linear"    ) return ENUM_MATRIX_TYPE_linear;
    if (type == "quadratic" ) return ENUM_MATRIX_TYPE_quadratic;
    if (type == "general"   ) return ENUM_MATRIX_TYPE_general;

    if (type == "varref"    ) return ENUM_MATRIX_TYPE_varref;
    if (type == "conref"    ) return ENUM_MATRIX_TYPE_conref;
    if (type == "objref"    ) return ENUM_MATRIX_TYPE_objref;
    if (type == "mixedref"  ) return ENUM_MATRIX_TYPE_mixedref;

    if (type == "pospattern") return ENUM_MATRIX_TYPE_pospattern;
    if (type == "negpattern") return ENUM_MATRIX_TYPE_negpattern;

    if (type == "jumbled"   ) return ENUM_MATRIX_TYPE_jumbled;
    if (type == "unknown"   ) return ENUM_MATRIX_TYPE_unknown;
    return 0;
}//returnMatrixType

inline bool verifyMatrixType(std::string type)
{
    return (returnMatrixType(type) > 0);
}//verifyMatrixType

/**
 *  A function to merge two matrix types so we can infer the type of a matrix recursively
 */
inline int mergeMatrixType(ENUM_MATRIX_TYPE type1, ENUM_MATRIX_TYPE type2)
{
    // two matrices of same type 
    if (type1 == type2) return type1;

    // if one matrix is jumbled, the result must be a jumbled matrix
    if (type1 == ENUM_MATRIX_TYPE_jumbled || type2 == ENUM_MATRIX_TYPE_jumbled) 
        return ENUM_MATRIX_TYPE_jumbled;

    if (type1 == ENUM_MATRIX_TYPE_unknown) return type2;
    if (type2 == ENUM_MATRIX_TYPE_unknown) return type1;
    if (type1 == ENUM_MATRIX_TYPE_zero) return type2;
    if (type2 == ENUM_MATRIX_TYPE_zero) return type1;

    // these matrix types do not mix with any other types (NOTE: type1 and type2 are now different!)
    if (type1 == ENUM_MATRIX_TYPE_varref || type2 == ENUM_MATRIX_TYPE_varref) 
        return ENUM_MATRIX_TYPE_jumbled;
    if (type1 == ENUM_MATRIX_TYPE_pospattern || type2 == ENUM_MATRIX_TYPE_pospattern) 
        return ENUM_MATRIX_TYPE_jumbled;
    if (type1 == ENUM_MATRIX_TYPE_negpattern || type2 == ENUM_MATRIX_TYPE_negpattern) 
        return ENUM_MATRIX_TYPE_jumbled;

    // at this point we have row references or expressions (of unequal type) 
    if (type1 > ENUM_MATRIX_TYPE_varref) // row reference (objective or constraint)
    {
        if (type2 > ENUM_MATRIX_TYPE_varref)
            return ENUM_MATRIX_TYPE_mixedref;
        else
            return ENUM_MATRIX_TYPE_jumbled;
    }                                  
    else // linear or nonlinear expression   
    {
        if (type2 > ENUM_MATRIX_TYPE_varref) return ENUM_MATRIX_TYPE_jumbled;  
        else if (type1 < type2) return type2;
        else return type1;
    }
    return ENUM_MATRIX_TYPE_unknown;
}//returnMatrixType

enum ENUM_MATRIX_SYMMETRY
{
    ENUM_MATRIX_SYMMETRY_none = 1,
    ENUM_MATRIX_SYMMETRY_symmetricUpper,
    ENUM_MATRIX_SYMMETRY_symmetricLower,
    ENUM_MATRIX_SYMMETRY_skewSymmetricUpper,
    ENUM_MATRIX_SYMMETRY_skewSymmetricLower,
    ENUM_MATRIX_SYMMETRY_hermitianLower,
    ENUM_MATRIX_SYMMETRY_hermitianUpper
};

inline int returnMatrixSymmetry(std::string symmetry)
{
    if (symmetry == "none"              ) return ENUM_MATRIX_SYMMETRY_none;
    if (symmetry == "symmetricUpper"    ) return ENUM_MATRIX_SYMMETRY_symmetricUpper;
    if (symmetry == "symmetricLower"    ) return ENUM_MATRIX_SYMMETRY_symmetricLower;
    if (symmetry == "skewSymmetricUpper") return ENUM_MATRIX_SYMMETRY_skewSymmetricUpper;
    if (symmetry == "skewSymmetricLower") return ENUM_MATRIX_SYMMETRY_skewSymmetricLower;
    if (symmetry == "hermitianLower"    ) return ENUM_MATRIX_SYMMETRY_hermitianLower;
    if (symmetry == "hermitianLower"    ) return ENUM_MATRIX_SYMMETRY_hermitianLower;
    return 0;
}//returnMatrixSymmetry

inline bool verifyMatrixSymmetry(std::string symmetry)
{
    return (returnMatrixSymmetry(symmetry) > 0);
}//verifyMatrixSymmetry


/**
 * An enum to streamline set() methods of vectors
 */
enum ENUM_COMBINE_ARRAYS
{
    ENUM_COMBINE_ARRAYS_replace, // silently replace previous data (if any)
    ENUM_COMBINE_ARRAYS_merge,   // merge two vectors into one
    ENUM_COMBINE_ARRAYS_ignore,  // silently ignore current vector if previous data exist
    ENUM_COMBINE_ARRAYS_throw    // throw an error if previous data detected
};


/*! \class GeneralFileHeader
 * \brief a data structure that holds general information about files
 * that conform to one of the OSxL schemas
 */
class GeneralFileHeader
{
public:

    /**
     * used to give a name to the file or the problem contained within it
     */
    std::string name;

    /**
     * used when the file or problem appeared in the literature
     * (could be in BiBTeX format or similar)
     */
    std::string source;

    /**
     * further information about the file or the problem contained within it
     */
    std::string description;

    /**
     * name(s) of author(s) who created this file
     */
    std::string fileCreator;

    /**
     * licensing information if applicable
     */
    std::string licence;


    /**
     * Constructor.
     *
     */
    GeneralFileHeader();

    /**
     *
     * Default destructor.
     */
    ~GeneralFileHeader();

    /**
     *
     * A function to check for the equality of two objects
     */
    bool IsEqual(GeneralFileHeader *that);

    /**
     *
     * A function to make a random instance of this class
     * @param density: corresponds to the probability that a particular child element is created
     * @param conformant: if true enforces side constraints not enforceable in the schema
     *     (e.g., agreement of "numberOfXXX" attributes and <XXX> children)
     */
    bool setRandom(double density, bool conformant);

    /**
     * A function to make a deep copy of an instance of this class
     * @param that: the instance from which information is to be copied
     * @return whether the copy was created successfully
     */
    bool deepCopyFrom(GeneralFileHeader *that);

    /**
     *
     * A function to retrieve a data item contained in this class
     * @param item: the type of information sought (name, source, description, fileCreator, licence)
     */
    std::string getHeaderItem(std::string item);

    /**
     *
     * A function to populate an instance of this class
     * @param name: the name of this file or instance
     * @param source: the source (e.g., in BiBTeX format)
     * @param description: further description about this file and/or its contents
     * @param fileCreator: the creator of this file
     * @param licence: licence information if applicable
     */
    bool setHeader(std::string name, std::string source, std::string description,
                   std::string fileCreator, std::string licence);

}; //GeneralFileHeader


/*! \class SparseVector
 * \brief a sparse vector data structure
 */
class SparseVector
{
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
     * indexes holds an integer array of indexes whose corresponding values are nonzero.
     */
    int* indexes;

    /**
     * values holds a double array of nonzero values.
     */
    double* values;

}; //SparseVector

/*! \class SparseIntVector
 * \brief a sparse vector data structure for integer vectors
 */
class SparseIntVector
{
public:

    /**
     * Constructor.
     *
     * @param number holds the size of the vector.
     */
    SparseIntVector(int number);

    /**
     *
     * Default Constructor.
     */
    SparseIntVector();

    /**
     *
     * Default destructor.
     */
    ~SparseIntVector();

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
     * indexes holds an integer array of indexes whose corresponding values are nonzero.
     */
    int* indexes;

    /**
     * values holds an integer array of nonzero values.
     */
    int* values;

}; //SparseIntVector


/*! \class SparseMatrix
 * \brief a sparse matrix data structure
 */
class SparseMatrix
{
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


/*! \class SparseJacobianMatrix
 * \brief a sparse Jacobian matrix data structure
 */
class SparseJacobianMatrix
{
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
     * points to the start of partials for that row
     */
    int* starts;

    /**
     * conVals holds an integer array of integers, conVals[i] is the number of constant terms
     * in the gradient for row i.
     */
    int* conVals;

    /**
     * indexes holds an integer array of variable indices.
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
class SparseHessianMatrix
{
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
     * hessRowIdx is an integer array of row indices in the range 0, ..., n - 1.
     */
    int* hessRowIdx;

    /**
     * hessColIdx is an integer array of column indices in the range 0, ..., n - 1.
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
class QuadraticTerms
{

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
class IntVector
{
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
     *
     * A function to make a random instance of this class
     * @param density: corresponds to the probability that a particular child element is created
     * @param conformant: if true enforces side constraints not enforceable in the schema
     *     (e.g., agreement of "numberOfXXX" attributes and <XXX> children)
     * @param iMin: lowest value (inclusive) that an entry in this vector can take
     * @param iMax: greatest value (inclusive) that an entry in this vector can take
     */
    bool setRandom(double density, bool conformant, int iMin, int iMax);

    /**
     * A function to make a deep copy of an instance of this class
     * @param that: the instance from which information is to be copied
     * @return whether the copy was created successfully
     */
    bool deepCopyFrom(IntVector *that);

    /**
     *  set values into an IntVector
     *  @param ni contains the dimension of the IntVector
     *  @param i contains the array of values
     */
    bool setIntVector(int *i, int ni);

    /**
     *  append a value to an IntVector
     *  @param i contains the value to be appended
     */
    bool extendIntVector(int i);

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
class OtherOptionEnumeration : public IntVector
{
public:
    std::string value;
    std::string description;

    OtherOptionEnumeration();
    ~OtherOptionEnumeration();

    // alternate constructor
    OtherOptionEnumeration(int n);

    /**
     *
     * A function to check for the equality of two objects
     */
    bool IsEqual(OtherOptionEnumeration *that);

    /**
     *
     * A function to make a random instance of this class
     * @param density: corresponds to the probability that a particular child element is created
     * @param conformant: if true enforces side constraints not enforceable in the schema
     *     (e.g., agreement of "numberOfXXX" attributes and <XXX> children)
     * @param iMin: lowest value (inclusive) that an entry in this vector can take
     * @param iMax: greatest value (inclusive) that an entry in this vector can take
     */
    bool setRandom(double density, bool conformant, int iMin, int iMax);

    /**
     * A function to make a deep copy of an instance of this class
     * @param that: the instance from which information is to be copied
     * @return whether the copy was created successfully
     */
    bool deepCopyFrom(OtherOptionEnumeration *that);

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
class DoubleVector
{
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
struct IndexValuePair
{
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
class BasisStatus
{
public:
    IntVector* basic;
    IntVector* atLower;
    IntVector* atUpper;
    IntVector* atEquality;
    IntVector* isFree;
    IntVector* superbasic;
    IntVector* unknown;

    BasisStatus();
    ~BasisStatus();

    /**
     *
     * A function to check for the equality of two objects
     */
    bool IsEqual(BasisStatus *that);

    /**
     *
     * A function to make a random instance of this class
     * @param density: corresponds to the probability that a particular child element is created
     * @param conformant: if true enforces side constraints not enforceable in the schema
     *     (e.g., agreement of "numberOfXXX" attributes and <XXX> children)
     * @param iMin: lowest index value (inclusive) that an entry in this basis can take
     * @param iMax: greatest index value (inclusive) that an entry in this basis can take
     */
    bool setRandom(double density, bool conformant, int iMin, int iMax);

    /**
     * A function to make a deep copy of an instance of this class
     * @param that: the instance from which information is to be copied
     * @return whether the copy was created successfully
     */
    bool deepCopyFrom(BasisStatus *that);

    /**
     *  Set the indices for a particular status
     *  @param status is a string representing the allowed statuses
     *        (as defined in enumeration ENUM_BASIS_STATUS - see below)
     *  @param i contains the array of indices
     *  @param ni contains the number of elements in i
     */
    bool setIntVector(int status, int *i, int ni);

    /**
     *  Add one index to a particular status
     *  @param status is a string representing the allowed statuses
     *        (as defined in enumeration ENUM_BASIS_STATUS - see below)
     *  @param idx contains the value of the index
     */
    bool addIdx(int status, int idx);

    /**
     *  Get the number of indices for a particular status
     *  @param status is a string representing the allowed statuses
     *  (at present "basic", "atLower", "atUpper", "isFree", "superbasic", "unknown")
     *  @return the number of indices or -1 if the object does not exist
     */
    int getNumberOfEl(int status);


    /**
     *  Get one entry in the array of indices for a particular status
     *  @param status is an integer representing the allowed statuses
     *  (as governed by enumeration ENUM_BASIS_STATUS --- see below)
     *  @param j is the (zero-based) position of the entry within the array
     *  @return the value
     */
    int getEl(int status, int j);

    /**
     *  Get the entire array of indices for a particular status
     *  @param status is a string representing the allowed statuses
     *  (as governed by enumeration ENUM_BASIS_STATUS --- see below)
     *  @param i is the location where the user wants to store the array
     *  @return whether the operation was successful
     *
     *  @note it is the user's responsibility to reserve sufficient memory to hold the vector being returned.
     */
    bool getIntVector(int status, int *i);

    /**
     *  Get the entire array of basis status in dense form
     *  @param resultArray is the location where the user wants to store the array
     *  @param dim is the size of the resultArray
     *  @param flipIdx indicates whether the index values need to be flipped 
     *   (used for representations of objective rows)
     *  @return status of the operation:
     *     < 0: error condition
     *     = 0: no new data found (i.e., basis information is empty)
     *     > 0: number of elements found
     *
     *  @note it is the user's responsibility to reserve sufficient memory to hold the vector being returned.
     */
    int getBasisDense(int *resultArray, int dim, bool flipIdx);
};//class BasisStatus


/*********************************************************************************
 *
 * Here we have a number of classes to represent a matrix
 * This construct is new to OS starting June 2014 (trunk version 4811)
 *
 *********************************************************************************/

/** 
 *  There is a circular dependency involving general matrices, 
 *  since the elements may contain nonlinear expressions (OSnLNodes)
 *  which themselves may contain references to matrices.
 *  Thus we need several forward declarations both here and in OSnLNode.h
 */
class OSnLNode;
class OSnLMNode;

/*! \class ConstantMatrixElements
 * \brief a data structure to represent the constant elements in a MatrixType object
 */
class ConstantMatrixElements
{
public:
    IntVector *start;
    SparseVector *nonzeros;

    ConstantMatrixElements();
    ~ConstantMatrixElements();

    /**
     *
     * A function to check for the equality of two objects
     */
    bool IsEqual(ConstantMatrixElements *that);

    /**
     *
     * A function to make a random instance of this class
     * @param density: corresponds to the probability that a particular child element is created
     * @param conformant: if true enforces side constraints not enforceable in the schema
     *     (e.g., agreement of "numberOfXXX" attributes and <XXX> children)
     * @param iMin: lowest index value (inclusive) that a variable reference in this matrix can take
     * @param iMax: greatest index value (inclusive) that a variable reference in this matrix can take
     */
    bool setRandom(double density, bool conformant, int iMin, int iMax);

    /**
     * A function to make a deep copy of an instance of this class
     * @param that: the instance from which information is to be copied
     * @return whether the copy was created successfully
     */
    bool deepCopyFrom(ConstantMatrixElements *that);
};//class ConstantMatrixElements

/*! \class VarReferenceMatrixElements
 * \brief a data structure to represent variable reference elements in a MatrixType object
 *  Each nonzero element is of the form x_{k} where k is the index of a variable
 */
class VarReferenceMatrixElements
{
public:
    IntVector *start;
    SparseIntVector *nonzeros;

    VarReferenceMatrixElements();
    ~VarReferenceMatrixElements();

    /**
     *
     * A function to check for the equality of two objects
     */
    bool IsEqual(VarReferenceMatrixElements *that);

    /**
     *
     * A function to make a random instance of this class
     * @param density: corresponds to the probability that a particular child element is created
     * @param conformant: if true enforces side constraints not enforceable in the schema
     *     (e.g., agreement of "numberOfXXX" attributes and <XXX> children)
     * @param iMin: lowest index value (inclusive) that a variable reference in this matrix can take
     * @param iMax: greatest index value (inclusive) that a variable reference in this matrix can take
     */
    bool setRandom(double density, bool conformant, int iMin, int iMax);

    /**
     * A function to make a deep copy of an instance of this class
     * @param that: the instance from which information is to be copied
     * @return whether the copy was created successfully
     */
    bool deepCopyFrom(VarReferenceMatrixElements *that);
};//class VarReferenceMatrixElements


/*! \class LinearMatrixElementTerm
 * \brief a data structure to represent a term in a linearMatrix element
 *  A term has the form c*x_{k}, where c defaults to 1 and k is a valid index for a variable
 *  This is essentially an index-value pair, but with the presence of a default value
 */
class LinearMatrixElementTerm
{
public:
    int idx;
    double coef;

    LinearMatrixElementTerm();
    ~LinearMatrixElementTerm();

    /**
     *
     * A function to check for the equality of two objects
     */
    bool IsEqual(LinearMatrixElementTerm *that);

    /**
     *
     * A function to make a random instance of this class
     * @param density: corresponds to the probability that a particular child element is created
     * @param conformant: if true enforces side constraints not enforceable in the schema
     *     (e.g., agreement of "numberOfXXX" attributes and <XXX> children)
     * @param iMin: lowest index value (inclusive) that a variable reference in this matrix can take
     * @param iMax: greatest index value (inclusive) that a variable reference in this matrix can take
     */
    bool setRandom(double density, bool conformant, int iMin, int iMax);

    /**
     * A function to make a deep copy of an instance of this class
     * @param that: the instance from which information is to be copied
     * @return whether the copy was created successfully
     */
    bool deepCopyFrom(LinearMatrixElementTerm *that);
};//class LinearMatrixElementTerm

/*! \class LinearMatrixElement
 * \brief a data structure to represent an expression in a linearMatrix element
 *  A LinearMatrixElement is a (finite) sum of LinearMatrixElementTerms,
 *  with an optional additive constant
 * @param numberOfVarIdx gives the number of terms in the expression
 */
class LinearMatrixElement
{
public:
    int numberOfVarIdx;
    double constant;

    LinearMatrixElementTerm** varIdx;

    LinearMatrixElement();
    ~LinearMatrixElement();

    /**
     *
     * A function to check for the equality of two objects
     */
    bool IsEqual(LinearMatrixElement *that);

    /**
     *
     * A function to make a random instance of this class
     * @param density: corresponds to the probability that a particular child element is created
     * @param conformant: if true enforces side constraints not enforceable in the schema
     *     (e.g., agreement of "numberOfXXX" attributes and <XXX> children)
     * @param iMin: lowest index value (inclusive) that a variable reference in this matrix can take
     * @param iMax: greatest index value (inclusive) that a variable reference in this matrix can take
     */
    bool setRandom(double density, bool conformant, int iMin, int iMax);

    /**
     * A function to make a deep copy of an instance of this class
     * @param that: the instance from which information is to be copied
     * @return whether the copy was created successfully
     */
    bool deepCopyFrom(LinearMatrixElement *that);
};//class LinearMatrixElement

/*! \class LinearMatrixValues
 * \brief a data structure to represent the nonzeros in a linearMatrix element
 */
class LinearMatrixValues
{
public:
    int numberOfEl;
    IntVector *indexes;
    LinearMatrixElement *values;     
    
    LinearMatrixValues();
    ~LinearMatrixValues();

    /**
     *
     * A function to check for the equality of two objects
     */
    bool IsEqual(LinearMatrixValues *that);

    /**
     *
     * A function to make a random instance of this class
     * @param density: corresponds to the probability that a particular child element is created
     * @param conformant: if true enforces side constraints not enforceable in the schema
     *     (e.g., agreement of "numberOfXXX" attributes and <XXX> children)
     * @param iMin: lowest index value (inclusive) that a variable reference in this matrix can take
     * @param iMax: greatest index value (inclusive) that a variable reference in this matrix can take
     */
    bool setRandom(double density, bool conformant, int iMin, int iMax);

    /**
     * A function to make a deep copy of an instance of this class
     * @param that: the instance from which information is to be copied
     * @return whether the copy was created successfully
     */
    bool deepCopyFrom(LinearMatrixValues *that);
};//class LinearMatrixValues

/*! \class LinearMatrixElements
 * \brief a data structure to represent the nonzero values in a linearMatrix element
 */
class LinearMatrixElements
{
public:
    IntVector *start;
    LinearMatrixValues *nonzeros;

    LinearMatrixElements();
    ~LinearMatrixElements();

    /**
     *
     * A function to check for the equality of two objects
     */
    bool IsEqual(LinearMatrixElements *that);

    /**
     *
     * A function to make a random instance of this class
     * @param density: corresponds to the probability that a particular child element is created
     * @param conformant: if true enforces side constraints not enforceable in the schema
     *     (e.g., agreement of "numberOfXXX" attributes and <XXX> children)
     * @param iMin: lowest index value (inclusive) that a variable reference in this matrix can take
     * @param iMax: greatest index value (inclusive) that a variable reference in this matrix can take
     */
    bool setRandom(double density, bool conformant, int iMin, int iMax);

    /**
     * A function to make a deep copy of an instance of this class
     * @param that: the instance from which information is to be copied
     * @return whether the copy was created successfully
     */
    bool deepCopyFrom(LinearMatrixElements *that);
};//class LinearMatrixElements

/*! \class GeneralMatrixValues
 * \brief a data structure to represent the nonzeros in a generalMatrix element
 */
class GeneralMatrixValues
{
public:
    int numberOfEl;
    IntVector *indexes;
    OSnLNode **values;

    GeneralMatrixValues();
    ~GeneralMatrixValues();

    /**
     *
     * A function to check for the equality of two objects
     */
    bool IsEqual(GeneralMatrixValues *that);

    /**
     *
     * A function to make a random instance of this class
     * @param density: corresponds to the probability that a particular child element is created
     * @param conformant: if true enforces side constraints not enforceable in the schema
     *     (e.g., agreement of "numberOfXXX" attributes and <XXX> children)
     * @param iMin: lowest index value (inclusive) that a variable reference in this matrix can take
     * @param iMax: greatest index value (inclusive) that a variable reference in this matrix can take
     */
    bool setRandom(double density, bool conformant, int iMin, int iMax);

    /**
     * A function to make a deep copy of an instance of this class
     * @param that: the instance from which information is to be copied
     * @return whether the copy was created successfully
     */
    bool deepCopyFrom(GeneralMatrixValues *that);
};//class GeneralMatrixValues

/*! \class GeneralMatrixElements
 * \brief a data structure to represent the nonzero values in a generalMatrix element
 */
class GeneralMatrixElements
{
public:
    IntVector *start;
    GeneralMatrixValues *nonzeros;

    GeneralMatrixElements();
    ~GeneralMatrixElements();

    /**
     *
     * A function to check for the equality of two objects
     */
    bool IsEqual(GeneralMatrixElements *that);

    /**
     *
     * A function to make a random instance of this class
     * @param density: corresponds to the probability that a particular child element is created
     * @param conformant: if true enforces side constraints not enforceable in the schema
     *     (e.g., agreement of "numberOfXXX" attributes and <XXX> children)
     * @param iMin: lowest index value (inclusive) that a variable reference in this matrix can take
     * @param iMax: greatest index value (inclusive) that a variable reference in this matrix can take
     */
    bool setRandom(double density, bool conformant, int iMin, int iMax);

    /**
     * A function to make a deep copy of an instance of this class
     * @param that: the instance from which information is to be copied
     * @return whether the copy was created successfully
     */
    bool deepCopyFrom(GeneralMatrixElements *that);
};//class GeneralMatrixElements


/*! \class ObjReferenceMatrixElements
 * \brief a data structure to represent objective reference elements in a MatrixType object
 *  Each nonzero element is of the form x_{k} where k is the index of an objective (i.e., less than zero)
 */
class ObjReferenceMatrixElements
{
public:
    IntVector *start;
    SparseIntVector *nonzeros;

    ObjReferenceMatrixElements();
    ~ObjReferenceMatrixElements();

    /**
     *
     * A function to check for the equality of two objects
     */
    bool IsEqual(ObjReferenceMatrixElements *that);

    /**
     *
     * A function to make a random instance of this class
     * @param density: corresponds to the probability that a particular child element is created
     * @param conformant: if true enforces side constraints not enforceable in the schema
     *     (e.g., agreement of "numberOfXXX" attributes and <XXX> children)
     * @param iMin: lowest index value (inclusive) that a variable reference in this matrix can take
     * @param iMax: greatest index value (inclusive) that a variable reference in this matrix can take
     */
    bool setRandom(double density, bool conformant, int iMin, int iMax);

    /**
     * A function to make a deep copy of an instance of this class
     * @param that: the instance from which information is to be copied
     * @return whether the copy was created successfully
     */
    bool deepCopyFrom(ObjReferenceMatrixElements *that);
};//class ObjReferenceMatrixElements


/*! \class ConReferenceMatrixElements
 * \brief a data structure to represent constraint reference elements in a MatrixType object
 *  Each nonzero element is of the form x_{k} where k is the index of a constraint
 */
class ConReferenceMatrixElements
{
public:
    IntVector *start;
    SparseIntVector *nonzeros;

    ConReferenceMatrixElements();
    ~ConReferenceMatrixElements();

    /**
     *
     * A function to check for the equality of two objects
     */
    bool IsEqual(ConReferenceMatrixElements *that);

    /**
     *
     * A function to make a random instance of this class
     * @param density: corresponds to the probability that a particular child element is created
     * @param conformant: if true enforces side constraints not enforceable in the schema
     *     (e.g., agreement of "numberOfXXX" attributes and <XXX> children)
     * @param iMin: lowest index value (inclusive) that a variable reference in this matrix can take
     * @param iMax: greatest index value (inclusive) that a variable reference in this matrix can take
     */
    bool setRandom(double density, bool conformant, int iMin, int iMax);

    /**
     * A function to make a deep copy of an instance of this class
     * @param that: the instance from which information is to be copied
     * @return whether the copy was created successfully
     */
    bool deepCopyFrom(ConReferenceMatrixElements *that);
};//class ConReferenceMatrixElements

/*! \class PatternMatrixElements
 * \brief a data structure to represent "pattern" elements in a MatrixType object
 *  Each nonzero element must be +1 (so only the indexes are represented) and
 *  denotes a location in the pattern matrix that either can or cannot be nonzero,
 *  depending on the value of the boolean excludeElementIfSet;
 */
class PatternMatrixElements
{
public:
    bool excludeElementIfSet;
    IntVector *start;
    IntVector *nonzeros;

    PatternMatrixElements();
    ~PatternMatrixElements();

    /**
     *
     * A function to check for the equality of two objects
     */
    bool IsEqual(PatternMatrixElements *that);

    /**
     *
     * A function to make a random instance of this class
     * @param density: corresponds to the probability that a particular child element is created
     * @param conformant: if true enforces side constraints not enforceable in the schema
     *     (e.g., agreement of "numberOfXXX" attributes and <XXX> children)
     * @param iMin: lowest index value (inclusive) that a variable reference in this matrix can take
     * @param iMax: greatest index value (inclusive) that a variable reference in this matrix can take
     */
    bool setRandom(double density, bool conformant, int iMin, int iMax);

    /**
     * A function to make a deep copy of an instance of this class
     * @param that: the instance from which information is to be copied
     * @return whether the copy was created successfully
     */
    bool deepCopyFrom(PatternMatrixElements *that);
};//class PatternMatrixElements


/*! \class MatrixElements
 * \brief a data structure to represent the nonzeroes of a matrix explicitly element by element
 */
class MatrixElements
{
public:
    ConstantMatrixElements         *constantElements;
    VarReferenceMatrixElements *varReferenceElements;
    LinearMatrixElements             *linearElements;
    GeneralMatrixElements           *generalElements;
    ObjReferenceMatrixElements *objReferenceElements;
    ConReferenceMatrixElements *conReferenceElements;
    PatternMatrixElements           *patternElements;

    bool rowMajor;

    MatrixElements();
    ~MatrixElements();

    /**
     *
     * A function to check for the equality of two objects
     */
    bool IsEqual(MatrixElements *that);

    /**
     *
     * A function to make a random instance of this class
     * @param density: corresponds to the probability that a particular child element is created
     * @param conformant: if true enforces side constraints not enforceable in the schema
     *     (e.g., agreement of "numberOfXXX" attributes and <XXX> children)
     * @param iMin: lowest index value (inclusive) that a variable reference in this matrix can take
     * @param iMax: greatest index value (inclusive) that a variable reference in this matrix can take
     */
    bool setRandom(double density, bool conformant, int iMin, int iMax);

    /**
     * A function to make a deep copy of an instance of this class
     * @param that: the instance from which information is to be copied
     * @return whether the copy was created successfully
     */
    bool deepCopyFrom(MatrixElements *that);
};//class MatrixElements


/*! \class MatrixTransformation
 * \brief a data structure to represent the nonzeroes of a matrix 
 *  by transformation from other (previously defined) matrices 
 */
class MatrixTransformation
{
public:
    OSnLMNode *transformation;

    MatrixTransformation();
    ~MatrixTransformation();

    /**
     *
     * A function to check for the equality of two objects
     */
    bool IsEqual(MatrixTransformation *that);

    /**
     *
     * A function to make a random instance of this class
     * @param density: corresponds to the probability that a particular child element is created
     * @param conformant: if true enforces side constraints not enforceable in the schema
     *     (e.g., agreement of "numberOfXXX" attributes and <XXX> children)
     * @param iMin: lowest index value (inclusive) that a variable reference in this matrix can take
     * @param iMax: greatest index value (inclusive) that a variable reference in this matrix can take
     */
    bool setRandom(double density, bool conformant, int iMin, int iMax);

    /**
     * A function to make a deep copy of an instance of this class
     * @param that: the instance from which information is to be copied
     * @return whether the copy was created successfully
     */
    bool deepCopyFrom(MatrixTransformation *that);
};//class MatrixTransformation

class MatrixBlock; //forward desclaration

/*! \class MatrixBlocks
 * \brief a data structure to represent the nonzeroes of a matrix 
 *  in a blockwise fashion. Each block can be given elementwise, 
 *  through transformation, or nested blocks, and so on, recursively.
 */
class MatrixBlocks
{
public:
    int numberOfBlocks;
    IntVector *colOffsets;
    IntVector *rowOffsets;
    MatrixBlock **block;

    MatrixBlocks();
    ~MatrixBlocks();

    /**
     *
     * A function to check for the equality of two objects
     */
    bool IsEqual(MatrixBlocks *that);

    /**
     *
     * A function to make a random instance of this class
     * @param density: corresponds to the probability that a particular child element is created
     * @param conformant: if true enforces side constraints not enforceable in the schema
     *     (e.g., agreement of "numberOfXXX" attributes and <XXX> children)
     * @param iMin: lowest index value (inclusive) that a variable reference in this matrix can take
     * @param iMax: greatest index value (inclusive) that a variable reference in this matrix can take
     */
    bool setRandom(double density, bool conformant, int iMin, int iMax);

    /**
     * A function to make a deep copy of an instance of this class
     * @param that: the instance from which information is to be copied
     * @return whether the copy was created successfully
     */
    bool deepCopyFrom(MatrixBlocks *that);
};//class MatrixBlocks


/*! \class MatrixConstructor
 * \brief a data structure to describe one step in the construction of a matrix
 *  Each constructor is either an elementwise description,  or as a transformation 
 *  involving matrices defined earlier in the process, or as a blockwise description, 
 *  which itself can contain other constructors recursively in setting up each block.
 */
class MatrixConstructor
{
public:

/**
 *  The type of each constructor is tracked in the integer cType
 *  cType = 1: MatrixElements
 *  cType = 2: Transformation
 *  cType = 3: MatrixBlocks
 */
    int cType;

/**
 * The pointer to the constructor is originally maintained as a void*,
 * to be changed as needed
 */
    void* cPtr;

    MatrixConstructor();
    ~MatrixConstructor();

    /**
     *
     * A function to check for the equality of two objects
     */
    bool IsEqual(MatrixConstructor *that);

    /**
     *
     * A function to make a random instance of this class
     * @param density: corresponds to the probability that a particular child element is created
     * @param conformant: if true enforces side constraints not enforceable in the schema
     *     (e.g., agreement of "numberOfXXX" attributes and <XXX> children)
     * @param iMin: lowest index value (inclusive) that a variable reference in this matrix can take
     * @param iMax: greatest index value (inclusive) that a variable reference in this matrix can take
     */
    bool setRandom(double density, bool conformant, int iMin, int iMax);

    /**
     * A function to make a deep copy of an instance of this class
     * @param that: the instance from which information is to be copied
     * @return whether the copy was created successfully
     */
    bool deepCopyFrom(MatrixConstructor *that);
};//class MatrixConstructor

/*! \class BaseMatrix
 * \brief a data structure to represent a point of departure for
 *  constructing a matrix by modifying parts of a previously defined matrix 
 */
class BaseMatrix
{
public:
    /**
     * the index of the base matrix
     */
    int baseMatrixIdx;

    /**
     * to pinpoint the position of the upper left corner of the base matrix within the target matrix
     */
    int targetMatrixFirstRow;
    int targetMatrixFirstCol;

    /**
     * to select the position of the upper left corner 
     * of the portion of the base matrix that is to be selected 
     */
    int baseMatrixStartRow;
    int baseMatrixStartCol;

    /**
     * to select the position of the lower right corner 
     * of the portion of the base matrix that is to be selected 
     */
    int baseMatrixEndRow;
    int baseMatrixEndCol;

    /**
     * to allow the base matrix to be transposed before it is attached to the target matrix
     */
    bool baseTranspose;

    /**
     * to allow the base matrix to be scaled before it is attached to the target matrix
     */
    double scalarMultiplier;


    BaseMatrix();
    ~BaseMatrix();

    /**
     *
     * A function to check for the equality of two objects
     */
    bool IsEqual(BaseMatrix *that);

    /**
     *
     * A function to make a random instance of this class
     * @param density: corresponds to the probability that a particular child element is created
     * @param conformant: if true enforces side constraints not enforceable in the schema
     *     (e.g., agreement of "numberOfXXX" attributes and <XXX> children)
     * @param iMin: lowest index value (inclusive) that a variable reference in this matrix can take
     * @param iMax: greatest index value (inclusive) that a variable reference in this matrix can take
     */
    bool setRandom(double density, bool conformant, int iMin, int iMax);

    /**
     * A function to make a deep copy of an instance of this class
     * @param that: the instance from which information is to be copied

     * @return whether the copy was created successfully
     */
    bool deepCopyFrom(BaseMatrix *that);
};//class BaseMatrix


/*! \class MatrixType
 * \brief a data structure to represent a MatrixType object (from which we derive Matrix and MatrixBlock)
 *
 */
class MatrixType
{
public:
    ENUM_MATRIX_SYMMETRY symmetry;
    ENUM_MATRIX_TYPE  matrixType;

    BaseMatrix *baseMatrix;
    std::vector<MatrixConstructor*> matrixConstructor;

    MatrixType();
    ~MatrixType();

    /**
     *
     * A function to check for the equality of two objects
     */
    bool IsEqual(MatrixType *that);

    /**
     *
     * A function to make a random instance of this class
     * @param density: corresponds to the probability that a particular child element is created
     * @param conformant: if true enforces side constraints not enforceable in the schema
     *     (e.g., agreement of "numberOfXXX" attributes and <XXX> children)
     * @param iMin: lowest index value (inclusive) that a variable reference in this matrix can take
     * @param iMax: greatest index value (inclusive) that a variable reference in this matrix can take
     */
    bool setRandom(double density, bool conformant, int iMin, int iMax);

    /**
     * A function to make a deep copy of an instance of this class

     * @param that: the instance from which information is to be copied
     * @return whether the copy was created successfully
     */
    bool deepCopyFrom(MatrixType *that);

};// class MatrixType



/*! \class OSMatrix
 * \brief a data structure to represent a Matrix object (derived from MatrixType)
 *
 */
class OSMatrix : public MatrixType
{
public:
    int numberOfRows;
    int numberOfColumns;
    int idx;
    std::string name;

    OSMatrix();
    ~OSMatrix();

    /**
     *
     * A function to check for the equality of two objects
     */
    bool IsEqual(OSMatrix *that);

    /**
     *
     * A function to make a random instance of this class
     * @param density: corresponds to the probability that a particular child element is created
     * @param conformant: if true enforces side constraints not enforceable in the schema
     *     (e.g., agreement of "numberOfXXX" attributes and <XXX> children)
     * @param iMin: lowest index value (inclusive) that a variable reference in this matrix can take
     * @param iMax: greatest index value (inclusive) that a variable reference in this matrix can take
     */
    bool setRandom(double density, bool conformant, int iMin, int iMax);

    /**
     * A function to make a deep copy of an instance of this class
     * @param that: the instance from which information is to be copied
     * @return whether the copy was created successfully
     */
    bool deepCopyFrom(OSMatrix *that);

};// class OSMatrix


/*! \class MatrixBlock
 * \brief a data structure to represent a MatrixBlock object (derived from MatrixType)
 *
 */
class MatrixBlock : public MatrixType
{
public:
    int blockRowIdx;
    int blockColIdx;

    MatrixBlock();
    ~MatrixBlock();

    /**
     *
     * A function to check for the equality of two objects
     */
    bool IsEqual(MatrixBlock *that);

    /**
     *
     * A function to make a random instance of this class
     * @param density: corresponds to the probability that a particular child element is created
     * @param conformant: if true enforces side constraints not enforceable in the schema
     *     (e.g., agreement of "numberOfXXX" attributes and <XXX> children)
     * @param iMin: lowest index value (inclusive) that a variable reference in this matrix can take
     * @param iMax: greatest index value (inclusive) that a variable reference in this matrix can take
     */
    bool setRandom(double density, bool conformant, int iMin, int iMax);

    /**
     * A function to make a deep copy of an instance of this class
     * @param that: the instance from which information is to be copied
     * @return whether the copy was created successfully
     */
    bool deepCopyFrom(MatrixBlock *that);
};// class MatrixBlock



/*! \class StorageCapacity
 *  \brief the StorageCapacity class.
 *
 * @author Horand Gassmann, Jun Ma, Kipp Martin
 *
 * \remarks
 * A data structure class that corresponds to an xml element in
 * the OSgL schema.
 */
class StorageCapacity
{

public:
    /** the unit in which storage capacity is measured */
    std::string unit;

    /** additional description about the storage */
    std::string description;

    /** the number of units of storage capacity */
    double value;

    /**
     *
     * Default constructor.
     */
    StorageCapacity();
    /**
     *
     * Class destructor.
     */
    ~StorageCapacity();

    /**
     *
     * A function to check for the equality of two objects
     */
    bool IsEqual(StorageCapacity *that);

    /**
     *
     * A function to make a random instance of this class
     * @param density: corresponds to the probability that a particular child element is created
     * @param conformant: if true enforces side constraints not enforceable in the schema
     *     (e.g., agreement of "numberOfXXX" attributes and <XXX> children)
     */
    bool setRandom(double density, bool conformant);

    /**
     * A function to make a deep copy of an instance of this class
     * @param that: the instance from which information is to be copied
     * @return whether the copy was created successfully
     */
    bool deepCopyFrom(StorageCapacity *that);
}; //StorageCapacity

/*! \class CPUSpeed
 *  \brief the CPUSpeed class.
 *
 * @author Horand Gassmann, Jun Ma, Kipp Martin
 * @version 1.0, 21/07/2008
 * @since OS 1.1
 *
 * \remarks
 * A data structure class that corresponds to an xml element in
 * the OSgL schema.
 */
class CPUSpeed
{

public:
    /** the unit in which CPU speed is measured */
    std::string unit;

    /** additional description about the CPU speed */
    std::string description;

    /** the CPU speed (expressed in multiples of unit) */
    double value;

    /**
     *
     * Default constructor.
     */
    CPUSpeed();
    /**
     *
     * Class destructor.
     */
    ~CPUSpeed();

    /**
     *
     * A function to check for the equality of two objects
     */
    bool IsEqual(CPUSpeed *that);

    /**
     *
     * A function to make a random instance of this class
     * @param density: corresponds to the probability that a particular child element is created
     * @param conformant: if true enforces side constraints not enforceable in the schema
     *     (e.g., agreement of "numberOfXXX" attributes and <XXX> children)
     */
    bool setRandom(double density, bool conformant);

    /**
     * A function to make a deep copy of an instance of this class
     * @param that: the instance from which information is to be copied
     * @return whether the copy was created successfully
     */
    bool deepCopyFrom(CPUSpeed *that);
}; //CPUSpeed

/*! \class CPUNumber
 *  \brief the CPUNumber class.
 *
 * @author Horand Gassmann, Jun Ma, Kipp Martin
 * @version 1.0, 21/07/2008
 * @since OS 1.1
 *
 * \remarks
 * A data structure class that corresponds to an xml element in
 * the OSgL schema.
 */
class CPUNumber
{

public:
    /** additional description about the CPU */
    std::string description;

    /** the number of CPUs */
    int value;

    /**
     *
     * Default constructor.
     */
    CPUNumber();
    /**
     *
     * Class destructor.
     */
    ~CPUNumber();

    /**
     *
     * A function to check for the equality of two objects
     */
    bool IsEqual(CPUNumber *that);

    /**
     *
     * A function to make a random instance of this class
     * @param density: corresponds to the probability that a particular child element is created
     * @param conformant: if true enforces side constraints not enforceable in the schema
     *     (e.g., agreement of "numberOfXXX" attributes and <XXX> children)
     */
    bool setRandom(double density, bool conformant);

    /**
     * A function to make a deep copy of an instance of this class
     * @param that: the instance from which information is to be copied
     * @return whether the copy was created successfully
     */
    bool deepCopyFrom(CPUNumber *that);
}; //CPUNumber

/*! \class TimeSpan
 *  \brief the TimeSpan class.
 *
 * @author Horand Gassmann, Jun Ma, Kipp Martin
 *
 * \remarks
 * A data structure class that corresponds to an xml element in
 * the OSgL schema.
 */
class TimeSpan
{

public:
    /** the unit in which time is measured */
    std::string unit;

    /** the number of units */
    double value;

    /**
     *
     * Default constructor.
     */
    TimeSpan();
    /**
     *
     * Class destructor.
     */
    ~TimeSpan();

    /**
     *
     * A function to check for the equality of two objects
     */
    bool IsEqual(TimeSpan *that);

    /**
     *
     * A function to make a random instance of this class
     * @param density: corresponds to the probability that a particular child element is created
     * @param conformant: if true enforces side constraints not enforceable in the schema
     *     (e.g., agreement of "numberOfXXX" attributes and <XXX> children)
     */
    bool setRandom(double density, bool conformant);

    /**
     * A function to make a deep copy of an instance of this class
     * @param that: the instance from which information is to be copied
     * @return whether the copy was created successfully
     */
    bool deepCopyFrom(TimeSpan *that);
}; //TimeSpan



class OSGeneral
{

};


/*************************************************
 *
 * A function to test equality of two doubles
 * This is needed to check equality of objects
 * when members can have NaN as a possible value
 *
 *************************************************/
inline bool isEqual(double x, double y)
{
    if (OSIsnan(x) && OSIsnan(y)) return true;
    if (x == y) return true;
    return false;
}

#endif
