/* $Id: OSGeneral.h 3172 2010-02-05 04:59:24Z Gassmann $ */
/** @file OSGeneral.h
 *
 * @author  Horand Gassmann, Jun Ma, Kipp Martin
 *
 * \remarks
 * Copyright (C) 2005-2014, Horand Gassmann, Jun Ma, Kipp Martin,
 * Northwestern University, and the University of Chicago.
 * All Rights Reserved.
 * This software is licensed under the Eclipse Public License.
 * Please see the accompanying LICENSE file in root directory for terms.
 *
 * This file contains the following classes that correspond to ComplexTypes in the OSgL schema:
 *      GeneralFileHeader
 *      SparseVector
 *      SparseIntVector
 *      SparseMatrix
 *      SparseJacobianMatrix
 *      SparseHessianMatrix
 *      QuadraticTerms
 *      IntVector
 *      DoubleVector
 *      IndexValuePair
 *      BasisStatus
 *      StorageCapacity
 *      CPUSpeed
 *      CPUNumber
 *      TimeSpan
 *      OtherOptionOrResultElementString
 *      OtherObjOptionOrResultElementString
 *      OtherOptionOrResultEnumeration : public IntVector
 *      OtherVariableOptionOrResult
 *      OtherObjectiveOptionOrResult
 *      OtherConstraintOptionOrResult
 *      OtherSOSOptionOrResult
 *      OtherSpecialOrderedSetsOptionOrResult
 *      OtherMatrixVariableOptionOrResult
 *      OtherMatrixObjectiveOptionOrResult
 *      OtherMatrixConstraintOptionOrResult
 *      OtherOptionOrResult
 *      SolverOptionOrResult
 */

#ifndef OSGENERAL_H
#define OSGENERAL_H

#include "OSConfig.h"
#include "OSParameters.h"
#include "OSMatrix.h"
#include "OSnLNode.h"
#include "OSExpressionTree.h"

#include <string>
#include <vector>

/**
 *  Some forward declarations in order to work around circular references
 */
class OSMatrix;
class OSMatrixWithMatrixVarIdx;
class OSMatrixWithMatrixObjIdx;
class OSMatrixWithMatrixConIdx;



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
     */
    GeneralFileHeader();

    /**
     * Default destructor.
     */
    ~GeneralFileHeader();

    /**
     * A function to check for the equality of two objects
     */
    bool IsEqual(GeneralFileHeader *that);

    /**
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
     * indexes holds an integer array of indexes whose corresponding values
     * are listed in the same order in the values array. 
     * Typically those would be nonzero.
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
     * valueSize is the dimension of the indexes and values arrays
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
<p>  Store an upper-triangular Hessian Matrix in sparse format </p>
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

    /** alternate constructor */
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

    /** value is a double that holds the value of the entity */
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
     * A function to check for the equality of two objects
     */
    bool IsEqual(BasisStatus *that);

    /**
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

/*! \class Matrices
 * \brief The in-memory representation of the
 * <b><matrices></b> element.
 */
class Matrices
{
public:

    /** The Matrices class constructor */
    Matrices();

    /** The Matrices class destructor */
    ~Matrices();

    /** numberOfMatrices is the number of
     * <nl> elements in the
     * <b><matrices></b> element.
     */
    int numberOfMatrices;

    /** matrix is a pointer to an array of OSMatrix object pointers */
    OSMatrix **matrix;

    /**
     * A function to check for the equality of two objects
     */
    bool IsEqual(Matrices *that);

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
    bool deepCopyFrom(Matrices *that);
}; // Matrices


/*! \class OtherOptionOrResultElementString
 *  \brief the OtherOptionOrResultElementString class.
 *
 * @author Robert Fourer, Horand Gassmann, Jun Ma, Kipp Martin
 * @version 1.0, 21/07/2008
 * @since OS 1.1
 *
 * \remarks
 * A class that implements an xml schema element
 */
class OtherOptionOrResultElementString
{
public:
    /** the index of the variable or constraint associated with this option or result */
    int idx;

    /** the name of the option or result the user is defining */
    std::string name;

    /** a brief description of the type of option or result */
    std::string description;

    /** the value of the option or result */
    std::string value;

    /** the type of the option or result value (integer, double, boolean, string, etc.) */
//    std::string valueType;

    /** the value of the option or result associated with the lower bound on the variable or constraint */
    std::string lbValue;

    /** the type of the option or result value associated with the lower bound */
//    std::string lbValueType;

    /** the value of the option or result associated with the upper bound on the variable or constraint */
    std::string ubValue;

    /** the type of the option or result value associated with the upper bound */
//    std::string ubValueType;

    /**
     * Default constructor.
     */
    OtherOptionOrResultElementString();

    /**
     * Class destructor.
     */
    ~OtherOptionOrResultElementString();

    /**
     * A function to check for the equality of two objects
     */
    bool IsEqual(OtherOptionOrResultElementString *that);

    /**
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
    bool deepCopyFrom(OtherOptionOrResultElementString *that);
}; //OtherOptionOrResultElementString


/*! \class OtherObjOptionOrResultElementString
 *  \brief the OtherObjOptionOrResultElementString class.
 *
 * @author Robert Fourer, Horand Gassmann, Jun Ma, Kipp Martin
 * @version 1.0, 21/07/2008
 * @since OS 1.1
 *
 * \remarks
 * A data structure class that corresponds to an xml element in
 * the OSoL schema.
 */
class OtherObjOptionOrResultElementString
{

public:
    /** the index of the objective associated with this option or result */
    int idx;

    /** the name of the option or result the user is defining */
    std::string name;

    /** a brief description of the type of option or result */
    std::string description;

    /** the value of the option or result */
    std::string value;

    /** the type of the option or result value (integer, double, boolean, string, etc.) */
//    std::string valueType;

    /** the value of the option or result associated with the constant part of the objective */
    std::string constantValue;

    /** the type of the option or result value associated with the objective constant */
//    std::string constantValueType;

    /** the value of the option or result associated with the weight of the objective */
    std::string weightValue;

    /** the type of the option or result value associated with the objective weight */
//    std::string weightValueType;

    /**
     * Default constructor.
     */
    OtherObjOptionOrResultElementString();

    /**
     * Class destructor.
     */
    ~OtherObjOptionOrResultElementString();

    /**
     * A function to check for the equality of two objects
     */
    bool IsEqual(OtherObjOptionOrResultElementString *that);

    /**
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
    bool deepCopyFrom(OtherObjOptionOrResultElementString *that);
}; //OtherObjOptionOrResultElementString


/*! \class OtherOptionOrResultEnumeration
 *  brief an integer vector data structure used in OSOption and OSResult
 *
 *  This class extends IntVector by adding two string-valued elements, value and description
 */
class OtherOptionOrResultEnumeration : public IntVector
{
public:
    std::string value;
    std::string description;

    OtherOptionOrResultEnumeration();
    ~OtherOptionOrResultEnumeration();

    /** alternate constructor */
    OtherOptionOrResultEnumeration(int n);

    /**
     * A function to check for the equality of two objects
     */
    bool IsEqual(OtherOptionOrResultEnumeration *that);

    /**
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
    bool deepCopyFrom(OtherOptionOrResultEnumeration *that);

    /**
     *  Set the indices for a particular level in an enumeration
     *  @param value represents the value of this enumeration member
     *  @param description holds additional information about this value
     *  @param i contains the array of indices
     *  @param ni contains the number of elements in i
     */
    bool setOtherOptionOrResultEnumeration(std::string value, std::string description, int *i, int ni);

    /**
     *  Get the value for a particular level in an enumeration
     */
    std::string getValue();

    /**
     *  Get the description for a particular level in an enumeration
     */
    std::string getDescription();

};//class OtherOptionOrResultEnumeration



/*! \class OtherVariableOptionOrResult
 *  \brief the OtherVariableOptionOrResult class.
 *
 *
 * \remarks
 * A data structure class that corresponds to an xml element in
 * the OSoL schema.
 */
class OtherVariableOptionOrResult
{

public:
    /** name of the option */
    std::string name;

    /** description of the option */
    std::string description;

    /** value of the option */
    std::string value;

    /** type of the option value (integer, double, boolean, string) */
    std::string type;

    /** name of the solver to which this option applies */
    std::string solver;

    /** name of the category into which this option falls */
    std::string category;

    /** number of <enumeration> child elements */
    unsigned int numberOfEnumerations;

    /** type of the values in the enumeration array */
    std::string enumType;

    /** number of <var> child elements */
    unsigned int numberOfVar;

    /** 
     *  type of values in the elements "value", "lbValue" and/or "ubValue"
     *  of the descendant array var
     */
    std::string varType;

    /** array of option values */
    OtherOptionOrResultElementString **var;

    /* a pointer to OtherOptionOrResultEnumeration objects that will
     * give for each distinct value the set of indices for
     * this user defined variable result
     */
    OtherOptionOrResultEnumeration** enumeration;

    /**
     * Default constructor.
     */
    OtherVariableOptionOrResult();

    /**
     * Class destructor.
     */
    ~OtherVariableOptionOrResult();

    /**
     * A function to check for the equality of two objects
     */
    bool IsEqual(OtherVariableOptionOrResult *that);

    /**
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
    bool deepCopyFrom(OtherVariableOptionOrResult *that);

    /**
     *
     * A function to set an array of <var> elements
     * @param numberOfVar: number of <var> elements to be set
     * @param var: the array of <var> elements that are to be set
     */
    bool setVar(int numberOfVar, OtherOptionOrResultElementString **var);

    /**
     *
     * A function to add a <var> element
     * @param idx: the index of the variable
     * @param value: the value associated with this variable
     * @param lbValue: a lower bound associated with this variable
     * @param ubValue: an upper bound associated with this variable
     */
    bool addVar(int idx, std::string value, std::string lbValue, std::string ubValue);
}; //OtherVariableOptionOrResult

#if 0
/*! \class OtherObjOptionOrResult
 *  \brief the OtherObjOptionOrResult class.
 *
 * @author Robert Fourer, Horand Gassmann, Jun Ma, Kipp Martin
 * @version 1.0, 21/07/2008
 * @since OS 1.1
 *
 * \remarks
 * A data structure class that corresponds to an xml element in
 * the OSoL schema.
 */
class OtherObjOptionOrResult
{

public:
    /** variable index*/
    int idx;

    /** optional variable name */
    std::string name;

    /** value of the option */
    std::string value;

    /** lower bound on the value */
    std::string lbValue;

    /** lower bound on the value */
    std::string ubValue;

    /**
     * Default constructor.
     */
    OtherObjOptionOrResult();

    /**
     * Class destructor.
     */
    ~OtherObjOptionOrResult();

    /**
     * A function to check for the equality of two objects
     */
    bool IsEqual(OtherObjOptionOrResult *that);

    /**
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
    bool deepCopyFrom(OtherObjOptionOrResult *that);
}; //OtherObjOptionOrResult
#endif

/*! \class OtherObjectiveOptionOrResult
 *  \brief the OtherObjectiveOptionOrResult class.
 *
 * @author Robert Fourer, Horand Gassmann, Jun Ma, Kipp Martin
 * @version 1.0, 21/07/2008
 * @since OS 1.1
 *
 * \remarks
 * A data structure class that corresponds to an xml element in
 * the OSoL schema.
 */
class OtherObjectiveOptionOrResult
{
public:
    /** name of the option */
    std::string name;

    /** description of the option */
    std::string description;

    /** value of the option */
    std::string value;

    /** type of the option value (integer, double, boolean, string) */
    std::string type;

    /** name of the solver to which this option applies */
    std::string solver;

    /** name of the category into which this option falls */
    std::string category;

    /** number of <enumeration> child elements */
    int numberOfEnumerations;

    /** type of the values in the enumeration array */
    std::string enumType;

    /** number of <obj> children */
    int numberOfObj;

    /** 
     *  type of values in the elements "value", "constantValue"
     *  and/or "ubValue" of the descendant array obj
     */
    std::string objType;

    /** array of option values */
    OtherObjOptionOrResultElementString **obj;

    /* a pointer to OtherOptionOrResultEnumeration objects that will
     * give for each distinct value the set of indices for
     * this user defined variable result
     */
    OtherOptionOrResultEnumeration** enumeration;

    /**
     * Default constructor.
     */
    OtherObjectiveOptionOrResult();

    /**
     * Class destructor.
     */
    ~OtherObjectiveOptionOrResult();

    /**
     * A function to check for the equality of two objects
     */
    bool IsEqual(OtherObjectiveOptionOrResult *that);

    /**
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
    bool deepCopyFrom(OtherObjectiveOptionOrResult *that);

    /**
     *
     * A function to set an array of <obj> elements
     * @param numberOfObj: number of <obj> elements to be set
     * @param obj: the array of <obj> elements that are to be set
     */
    bool setObj(int numberOfObj, OtherObjOptionOrResultElementString **obj);

    /**
     *
     * A function to add a <obj> element
     * @param idx: the index of the objective
     * @param value: the value associated with this objective
     * @param lbValue: a lower bound associated with this objective
     * @param ubValue: an upper bound associated with this objective
     */
    bool addObj(int idx, std::string value, std::string lbValue, std::string ubValue);
}; //OtherObjectiveOptionOrResult


#if 0
/*! \class OtherConOptionOrResult
 *  \brief the OtherConOptionOrResult class.
 *
 * @author Robert Fourer, Horand Gassmann, Jun Ma, Kipp Martin
 * @version 1.0, 21/07/2008
 * @since OS 1.1
 *
 * \remarks
 * A data structure class that corresponds to an xml element in
 * the OSoL schema.
 */
class OtherConOptionOrResult
{

public:
    /** variable index*/
    int idx;

    /** optional variable name */
    std::string name;

    /** value of the option */
    std::string value;

    /** lower bound of the option */
    std::string lbValue;

    /** upper bound of the option */
    std::string ubValue;

    /**
     * Default constructor.
     */
    OtherConOptionOrResult();

	/**
     * Class destructor.
     */
    ~OtherConOptionOrResult();

    /**
     * A function to check for the equality of two objects
     */
    bool IsEqual(OtherConOptionOrResult *that);

    /**
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
    bool deepCopyFrom(OtherConOptionOrResult *that);
}; //OtherConOptionOrResult
#endif

/*! \class OtherConstraintOptionOrResult
 *  \brief the OtherConstraintOptionOrResult class.
 *
 * @author Robert Fourer, Horand Gassmann, Jun Ma, Kipp Martin
 * @version 1.0, 21/07/2008
 * @since OS 1.1
 *
 * \remarks
 * A data structure class that corresponds to an xml element in
 * the OSoL schema.
 */
class OtherConstraintOptionOrResult
{

public:
    /** name of the option */
    std::string name;

    /** description of the option */
    std::string description;

    /** value of the option */
    std::string value;

    /** type of the option value (integer, double, boolean, string) */
    std::string type;

    /** name of the solver to which this option applies */
    std::string solver;

    /** name of the category into which this option falls */
    std::string category;

    /** number of <enumeration> child elements */
    int numberOfEnumerations;

    /** type of the values in the enumeration array */
    std::string enumType;

    /** number of <con> children */
    int numberOfCon;

    /** 
     *  type of values in the elements "value", "lbValue" and/or "ubValue"
     *  of the descendant array con
     */
    std::string conType;

    /** array of option values */
    OtherOptionOrResultElementString **con;

    /* a pointer to OtherOptionOrResultEnumeration objects that will
     * give for each distinct value the set of indices for
     * this user defined variable result
     */
    OtherOptionOrResultEnumeration** enumeration;

    /**
     * Default constructor.
     */
    OtherConstraintOptionOrResult();

	/**
     * Class destructor.
     */
    ~OtherConstraintOptionOrResult();

    /**
     *
     * A function to check for the equality of two objects
     */
    bool IsEqual(OtherConstraintOptionOrResult *that);

    /**
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
    bool deepCopyFrom(OtherConstraintOptionOrResult *that);

    /**
     *
     * A function to set an array of <con> elements
     * @param numberOfCon: number of <con> elements to be set
     * @param obj: the array of <con> elements that are to be set
     */
    bool setCon(int numberOfCon, OtherOptionOrResultElementString **con);

    /**
     *
     * A function to add a <con> element
     * @param idx: the index of the constraint
     * @param value: the value associated with this constraint
     * @param lbValue: a lower bound associated with this constraint
     * @param ubValue: an upper bound associated with this constraint
     */
    bool addCon(int idx, std::string value, std::string lbValue, std::string ubValue);
}; //OtherConstraintOptionOrResult


/*! \class OtherSOSOptionOrResult
 *  \brief the OtherSOSOptionOrResult class.
 *
 * @author Robert Fourer, Horand Gassmann, Jun Ma, Kipp Martin
 * @version 1.0, 21/07/2008
 * @since OS 1.1
 *
 * \remarks
 * A data structure class that corresponds to an xml element in
 * the OSoL schema.
 */
class OtherSOSOptionOrResult
{
public:
    /** the index of the special ordered set to which this option pertains */
    int idx;

    /** name of the option */
    std::string name;

    /** description of the option */
    std::string description;

    /** value of the option */
    std::string value;

    /** type of the option value (integer, double, boolean, string) */
    std::string type;

    /** number of <enumeration> child elements */
    int numberOfEnumerations;

    /** type of the values in the enumeration array */
    std::string enumType;

    /** number of <var> children */
    int numberOfVar;

    /** 
     *  type of values in the elements "value", "lbValue" and/or "ubValue"
     *  of the descendant array var
     */
    std::string varType;

    /** array of option values */
    OtherOptionOrResultElementString **var;

    /* a pointer to OtherOptionOrResultEnumeration objects that will
     * give for each distinct value the set of indices for
     * this user defined variable result
     */
    OtherOptionOrResultEnumeration** enumeration;

    /**
     * Default constructor.
     */
    OtherSOSOptionOrResult();

	/**
     * Class destructor.
     */
    ~OtherSOSOptionOrResult();

    /**
     *
     * A function to check for the equality of two objects
     */
    bool IsEqual(OtherSOSOptionOrResult *that);

    /**
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
    bool deepCopyFrom(OtherSOSOptionOrResult *that);

    /**
     * A function to set an array of <sos> elements
     * @param numberOfSOS: number of <sos> elements to be set
     * @param obj: the array of <sos> elements that are to be set
     */
    bool setSOS(int numberOfVar, OtherOptionOrResultElementString **var);

    /**
     * A function to add a <sos> element
     * @param idx: the index of the constraint
     * @param value: the value associated with this constraint
     * @param lbValue: a lower bound associated with this constraint
     * @param ubValue: an upper bound associated with this constraint
     */
    bool addSOS(int idx, std::string value, std::string lbValue, std::string ubValue);
}; //OtherSOSOptionOrResult


/*! \class OtherSpecialOrderedSetsOptionOrResult
 *  \brief the OtherSpecialOrderedSetsOptionOrResult class.
 *
 * @author Robert Fourer, Horand Gassmann, Jun Ma, Kipp Martin
 * @version 1.0, 21/07/2008
 * @since OS 1.1
 *
 * \remarks
 * A data structure class that corresponds to an xml element in
 * the OSoL schema.
 */
class OtherSpecialOrderedSetsOptionOrResult
{

public:
    /** name of the option */
    std::string name;

    /** description of the option */
    std::string description;

    /** value of the option */
    std::string value;

    /** type of the option value (integer, double, boolean, string) */
    std::string type;

    /** name of the solver to which this option applies */
    std::string solver;

    /** name of the category into which this option falls */
    std::string category;

    /** number of <enumeration> child elements */
    int numberOfEnumerations;

    /** type of the values in the enumeration array */
    std::string enumType;

    /** number of <sos> children */
    int numberOfSOS;

    /** array of option values */
    OtherSOSOptionOrResult **sos;

    /* a pointer to OtherOptionOrResultEnumeration objects that will
     * give for each distinct value the set of indices for
     * this user defined variable result
     */
    OtherOptionOrResultEnumeration** enumeration;

    /**
     * Default constructor.
     */
    OtherSpecialOrderedSetsOptionOrResult();

	/**
     * Class destructor.
     */
    ~OtherSpecialOrderedSetsOptionOrResult();

    /**
     *
     * A function to check for the equality of two objects
     */
    bool IsEqual(OtherSpecialOrderedSetsOptionOrResult *that);

    /**
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
    bool deepCopyFrom(OtherSpecialOrderedSetsOptionOrResult *that);

    /**
     *
     * A function to set an array of <sos> elements
     * @param numberOfSOS: number of <sos> elements to be set
     * @param obj: the array of <sos> elements that are to be set
     */
    bool setSos(int numberOfVar, OtherSOSOptionOrResult **sos);

    /**
     *
     * A function to add a <sos> element
     * @param idx: the index of the constraint
     * @param value: the value associated with this constraint
     * @param lbValue: a lower bound associated with this constraint
     * @param ubValue: an upper bound associated with this constraint
     */
    bool addSOS(int idx, std::string value, std::string lbValue, std::string ubValue);
}; //OtherSpecialOrderedSetsOptionOrResult


/*! \class OtherMatrixVariableOptionOrResult
 *  brief a data structure used in OSOption and OSResult
 */
class OtherMatrixVariableOptionOrResult
{
public:
    /** name of the option */
    std::string name;

    /** description of the option */
    std::string description;

    /** value of the option */
    std::string value;

    /** type of the option value (integer, double, boolean, string) */
    std::string type;

    /** name of the solver to which this option applies */
    std::string solver;

    /** name of the category into which this option falls */
    std::string category;

    /** number of <enumeration> child elements */
    int numberOfEnumerations;

    /** type of the values in the enumeration array */
    std::string enumType;

    /** number of <matrixVar> child elements */
    int numberOfMatrixVar;

    /** array of option values */
    OSMatrixWithMatrixVarIdx **matrixVar;

    /* a pointer to OtherOptionOrResultEnumeration objects that will
     * give for each distinct value the set of indices for
     * this user defined variable result
     */
    OtherOptionOrResultEnumeration** enumeration;

    /**
     * Default constructor.
     */
    OtherMatrixVariableOptionOrResult();
    /**
     * Class destructor.
     */
    ~OtherMatrixVariableOptionOrResult();

    /**
     * A function to check for the equality of two objects
     */
    bool IsEqual(OtherMatrixVariableOptionOrResult *that);

    /**
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
    bool deepCopyFrom(OtherMatrixVariableOptionOrResult *that);

    /**
     *
     * A function to set an array of <var> elements
     * @param numberOfVar: number of <var> elements to be set
     * @param var: the array of <var> elements that are to be set
     */
    bool setVar(int numberOfVar, OtherMatrixVariableOptionOrResult **var);

    /**
     * A function to add a <var> element
     * @param idx: the index of the variable
     * @param value: the value associated with this variable
     * @param lbValue: a lower bound associated with this variable
     * @param ubValue: an upper bound associated with this variable
     */
    bool addVar(int idx, std::string value, std::string lbValue, std::string ubValue);
};// OtherMatrixVariableOptionOrResult 


/*! \class OtherMatrixObjectiveOptionOrResult
 *  brief a data structure used in OSOption and OSResult
 */
class OtherMatrixObjectiveOptionOrResult : public IntVector
{
public:
    /** name of the option */
    std::string name;

    /** description of the option */
    std::string description;

    /** value of the option */
    std::string value;

    /** type of the option value (integer, double, boolean, string) */
    std::string type;

    /** name of the solver to which this option applies */
    std::string solver;

    /** name of the category into which this option falls */
    std::string category;

    /** number of <enumeration> child elements */
    int numberOfEnumerations;

    /** type of the values in the enumeration array */
    std::string enumType;

    /** number of <matrixObj> child elements */
    int numberOfMatrixObj;

    /** array of option values */
    OSMatrixWithMatrixObjIdx **matrixObj;

    /* a pointer to OtherOptionOrResultEnumeration objects that will
     * give for each distinct value the set of indices for
     * this user defined variable result
     */
    OtherOptionOrResultEnumeration** enumeration;

    /**
     * Default constructor.
     */
    OtherMatrixObjectiveOptionOrResult();

    /**
     * Class destructor.
     */
    ~OtherMatrixObjectiveOptionOrResult();

    /**
     * A function to check for the equality of two objects
     */
    bool IsEqual(OtherMatrixObjectiveOptionOrResult *that);

    /**
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
    bool deepCopyFrom(OtherMatrixObjectiveOptionOrResult *that);

    /**
     * A function to set an array of <matrixObj> elements
     * @param numberOfVar: number of <matrixObj> elements to be set
     * @param matrixObj: the array of <matrixObj> elements that are to be set
     */
    bool setMatrixObj(int numberOfMatrixObj, OtherMatrixObjectiveOptionOrResult **matrixObj);

    /**
     * A function to add a <var> element
     * @param idx: the index of the variable
     * @param value: the value associated with this variable
     * @param lbValue: a lower bound associated with this variable
     * @param ubValue: an upper bound associated with this variable
     */
    bool addMatrixObj(int idx, std::string value, std::string lbValue, std::string ubValue);
};// OtherMatrixObjectiveOptionOrResult 


/*! \class OtherMatrixConstraintOptionOrResult
 *  brief a data structure used in OSOption and OSResult
 */
class OtherMatrixConstraintOptionOrResult : public IntVector
{
public:
    /** name of the option */
    std::string name;

    /** description of the option */
    std::string description;

    /** value of the option */
    std::string value;

    /** type of the option value (integer, double, boolean, string) */
    std::string type;

    /** name of the solver to which this option applies */
    std::string solver;

    /** name of the category into which this option falls */
    std::string category;

    /** number of <enumeration> child elements */
    int numberOfEnumerations;

    /** type of the values in the enumeration array */
    std::string enumType;

    /** number of <matrixCon> child elements */
    int numberOfMatrixCon;

    /** array of option values */
    OSMatrixWithMatrixConIdx **matrixCon;

    /* a pointer to OtherOptionOrResultEnumeration objects that will
     * give for each distinct value the set of indices for
     * this user defined variable result
     */
    OtherOptionOrResultEnumeration** enumeration;

    /**
     * Default constructor.
     */
    OtherMatrixConstraintOptionOrResult();

    /**
     * Class destructor.
     */
    ~OtherMatrixConstraintOptionOrResult();

    /**
     * A function to check for the equality of two objects
     */
    bool IsEqual(OtherMatrixConstraintOptionOrResult *that);

    /**
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
    bool deepCopyFrom(OtherMatrixConstraintOptionOrResult *that);

    /**
     * A function to set an array of <matrixCon> elements
     * @param numberOfVar: number of <matrixCon> elements to be set
     * @param matrixCon: the array of <matrixCon> elements that are to be set
     */
    bool setMatrixCon(int numberOfMatrixCon, OtherMatrixConstraintOptionOrResult **matrixCon);

    /**
     * A function to add a <matrixCon> element
     * @param idx: the index of the matrix constraint

     * @param value: the value associated with this matrix constraint
     * @param lbValue: a lower bound associated with this matrix constraint
     * @param ubValue: an upper bound associated with this matrix constraint
     */
    bool addMatrixCon(int idx, std::string value, std::string lbValue, std::string ubValue);
};// OtherMatrixConstraintOptionOrResult 


/*! \class OtherOptionOrResult
 *  \brief The OtherOptionOrResult  Class.
 *
 * @author Horand Gassmann, Jun Ma, Kipp Martin
 * @version 1.0, 03/14/2004
 * @since OS 1.0
 *
 * \remarks
 * A class that implements an xml schema element
 */
class OtherOptionOrResult
{
public:
    /** the name of the option or result the user is defining */
    std::string name;

    /** a brief description of the type of option or result */
    std::string description;

    /** the value of the option or result */
    std::string value;

    /** the type of the option or result value (integer, double, boolean, string) */
    std::string type;

    /**
     * Default constructor.
     */
    OtherOptionOrResult();

    /**
     * Class destructor.
     */
    ~OtherOptionOrResult();

    /**
     * A function to check for the equality of two objects
     */
    bool IsEqual(OtherOptionOrResult *that);

    /**
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
    bool deepCopyFrom(OtherOptionOrResult *that);
};//OtherOptionOrResult



/*! \class SolverOptionOrResult
 *  \brief The SolverOptionOrResult  Class.
 *
 * @author Horand Gassmann, Jun Ma, Kipp Martin
 * @version 1.0, 03/14/2004
 * @since OS 1.0
 *
 * \remarks
 * A class that allows arbitrary input or output communication with the solver
 * concerning an option or result associated with the solution.
 */
class SolverOptionOrResult
{
public:
    /** the name of the option or result the user is defining */
    std::string name;

    /** a brief description of the type of option or result */
    std::string description;

    /** the value of the option or result */
    std::string value;

    /** the type of the option or result value (integer, double, boolean, string) */
    std::string type;

    /** the solver to which the option or result applies */
    std::string solver;

    /** this element allows a specific category to be associated with this
     *  particular type of option or result
     */
    std::string category;

    /** the number of matrix valued input contained in this SolverOptionOrResult
     */
    int numberOfMatrices;

    /** the number of items contained in this SolverOptionOrResult
     */
    int numberOfItems;

        /** an array of matrices
     */
    OSMatrix **matrix;

    /** an array of items (string-valued)
     */
    std::string *item;

    /**
     * Default constructor.
     */
    SolverOptionOrResult();

    /**
     * Class destructor.
     */
    ~SolverOptionOrResult();

    /**
     * A function to check for the equality of two objects
     */
    bool IsEqual(SolverOptionOrResult *that);

    /**
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
    bool deepCopyFrom(SolverOptionOrResult *that);
};//SolverOptionOrResult

class OSGeneral
{

};


/*************************************************
 *
 * A function to test equality of two doubles.
 * This is needed to check equality of objects
 * when members can have NaN as a possible value
 * since ordinary rules evaluate NaN as different
 * from any other value --- even another NaN
 * We sometimes want (NaN == NaN) to evaluate to true
 *
 *************************************************/
inline bool OSIsEqual(double x, double y)
{
    if (OSIsnan(x) && OSIsnan(y)) return true;
    if (x == y) return true;
    return false;
}


#endif
