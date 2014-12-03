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
#include "OSExpressionTree.h"

#include <string>
#include <vector>



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

    /** alternate constructor */
    OtherOptionEnumeration(int n);

    /**
     * A function to check for the equality of two objects
     */
    bool IsEqual(OtherOptionEnumeration *that);

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
class ScalarExpressionTree;


/*! \class MatrixNode
 *  \brief a generic class from which we derive matrix constructors
 *  (BaseMatrix, MatrixElements, MatrixTransformation and MatrixBlocks)
 *  as well as matrix types (OSMatrix and MatrixBlock).
 */
class MatrixNode
{
public:
    /**
     *  matrixType tracks the type of elements contained in this MatrixNode,
     *  which may be useful in solver selection
     */
    ENUM_MATRIX_TYPE matrixType;

    /**
     *  nType is a unique integer assigned to each type of matrix node
     */
    ENUM_MATRIX_CONSTRUCTOR_TYPE nType;

    /**  inumberOfChildren is the number of MatrixNode child elements
     *   For the matrix types (OSMatrix and MatrixBlock) this number
     *   is not fixed and is temporarily set to 0
     */
    unsigned int inumberOfChildren;

    /**
     * m_mChildren holds all the children, that is, nodes used
     * in the definition or construction of the current node.
     */
    MatrixNode **m_mChildren;

    /** default constructor */
    MatrixNode();

    /** destructor */
    virtual ~MatrixNode();

    /**
     * @return the value of nType
     */
    virtual ENUM_MATRIX_CONSTRUCTOR_TYPE getNodeType();

    /**
     * @return the name of the matrix constructor
     */
    virtual std::string getNodeName() = 0;

    /**
     * <p>
     * The following method writes a matrix node in OSgL format. 
     * it is used by OSgLWriter to write a <matrix> element.
     * </p>
     *
     * @return the MatrixNode and its children as an OSgL string.
     */
    virtual std::string getMatrixNodeInXML() = 0;

    /**
     * <p>
     * Get a vector of pointers to OSnLNodes and OSnLMNodes that correspond to
     * the MatrixNode tree in prefix format.
     * </p>
     *
     * @return the node tree as a vector of MatrixNodes in prefix.
     */
    std::vector<MatrixNode*> getPrefixFromNodeTree();

    /*
     * <p>
     * Called by getPrefixFromNodeTree().  
     * This method calls itself recursively and
     * generates a vector of pointers to MatrixNode in prefix
     * </p>
     * @param a pointer prefixVector to a vector of pointers of MatrixNodes
     * @return a vector of pointers to MatrixNode in prefix.
     */
    std::vector<MatrixNode*> preOrderMatrixNodeTraversal( std::vector<MatrixNode*> *prefixVector);

    /**
     * <p>
     * Get a vector of pointers to MatrixNodes that correspond to
     * the MatrixNode tree in postfix format
     * </p>
     *
     * @return the node tree as a vector of MatrixNodes in postfix.
     */
    std::vector<MatrixNode*> getPostfixFromNodeTree();

    /**
     * <p>
     * Called by getPostfixFromNodeTree(). 
     * This method calls itself recursively and
     * generates a vector of pointers to MatrixNodes in postfix.
     * </p>
     * @param a pointer postfixVector to a vector of pointers of MatrixNodes
     * @return a vector of pointers to MatrixNodes in postfix.
     */
    std::vector<MatrixNode*> postOrderMatrixNodeTraversal( std::vector<MatrixNode*> *postfixVector);

    /**
     * <p>
     * Create or clone a node of this type.
     * This is an abstract method which is required to be implemented by the concrete
     * operator nodes that derive or extend from this class.
     * </p>
     */
    virtual MatrixNode *cloneMatrixNode() = 0;

    /**
     * A function to check for the equality of two objects
     */
    virtual bool IsEqual(MatrixNode *that);

    /**
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
    bool deepCopyFrom(MatrixNode *that);
};//end MatrixNode


/*! \class MatrixConstructor
 *  \brief a data structure to describe one step in the construction of a matrix.
 *  To facilitate parsing of complicated matrix constructors we distinguish
 *  a number of different forms of constructor:
 *  1 - BaseMatrix
 *  2 - Elements   
 *  3 - Transformation
 *  4 - MatrixBlocks
 */
class MatrixConstructor : public MatrixNode
{
public:
    /** constructor */
    MatrixConstructor();

    /** destructor */
    ~MatrixConstructor();

    /**
     *
     * A function to check for the equality of two objects
     */
    bool IsEqual(MatrixConstructor *that);

    /**
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


/*! \class ConstantMatrixElements
 * \brief a data structure to represent the constant elements in a MatrixType object
 */
class ConstantMatrixElements
{
public:
    /**
     *  To indicate whether the constant matrix elements are stored 
     *  in row major form or column major form
     */
    bool rowMajor;
 
    /**
     *  numberOfValues records the number of entries in the arrays
     *  that make up the instance of nonzeros
     */
    int numberOfValues;

    /**
     *  A vector listing the row or column starts
     */
    IntVector *start;

    /** The indices and values of the (nonzero) constant elements */
    IntVector *indexes;
    DoubleVector *values;


    ConstantMatrixElements();
    ~ConstantMatrixElements();

    /**
     *
     * A function to check for the equality of two objects
     */
    bool IsEqual(ConstantMatrixElements *that);

    /**
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
    /**
     *  numberOfValues records the number of entries in the arrays
     *  that make up the instance of nonzeros
     */
    int numberOfValues;
 
    /**
     *  To indicate whether the varReference matrix elements are stored 
     *  in row major form or column major form
     */
    bool rowMajor;

    /**
     *  A vector listing the row or column starts
     */
    IntVector *start;

    /** The row (or column) indices and variable references of the elements */
    IntVector *indexes;
    IntVector *values;

    VarReferenceMatrixElements();
    ~VarReferenceMatrixElements();

    /**
     * A function to check for the equality of two objects
     */
    bool IsEqual(VarReferenceMatrixElements *that);

    /**
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
     * A function to check for the equality of two objects
     */
    bool IsEqual(LinearMatrixElementTerm *that);

    /**
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
     * A function to check for the equality of two objects
     */
    bool IsEqual(LinearMatrixElement *that);

    /**
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
 * \brief a data structure to represent the linear expressions in a LinearMatrixNonzeros element
 */
class LinearMatrixValues
{
public:
    int numberOfEl;
    LinearMatrixElement **el;     
    
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


/*! \class LinearMatrixNonzeros
 * \brief a data structure to represent the nonzeros in a linearMatrix element
 */
class LinearMatrixNonzeros
{
public:
    /**
     *  numberOfEl gives the number of nonzero elements, which is the dimension
     *  of both the indexes and values element
     */
    //int numberOfEl;

    /** row or column indices, depending on rowMajor */
    IntVector *indexes;

    /**
     *  The values are expressions of the form
     *  a_0 + a_1 x_{i_1} * a_2 x_{i_2} + ...
     *  Each term in this sum is stored as a separate LinearMatrixElementTerm object
     */
    LinearMatrixValues *values;     
    
    LinearMatrixNonzeros();
    ~LinearMatrixNonzeros();

    /**
     * A function to check for the equality of two objects
     */
    bool IsEqual(LinearMatrixNonzeros *that);

    /**
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
    bool deepCopyFrom(LinearMatrixNonzeros *that);
};//class LinearMatrixNonzeros

/*! \class LinearMatrixElements
 * \brief a data structure to represent the nonzero values in a linearMatrix element
 */
class LinearMatrixElements
{
public:
    /**
     *  numberOfValues records the number of entries in the arrays
     *  that make up the instance of nonzeros
     */
    int numberOfValues;
 
    /**
     *  To indicate whether the linear matrix elements are stored 
     *  in row major form or column major form
     */
    bool rowMajor;

    /**
     *  A vector listing the row or column starts
     */
    IntVector *start;

    /** 
     *  The indexes of the (nonzero) linear matrix elements
     *  row or column indexes, depending on rowMajor */
    IntVector *indexes;

    /**
     *  The values are expressions of the form
     *  a_0 + a_1 x_{i_1} * a_2 x_{i_2} + ...
     *  Each term in this sum is stored as a separate LinearMatrixElementTerm object
     */
    LinearMatrixValues *values;     

    LinearMatrixElements();
    ~LinearMatrixElements();

    /**
     *
     * A function to check for the equality of two objects
     */
    bool IsEqual(LinearMatrixElements *that);

    /**
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

#if 0

/*! \class GeneralMatrixElement
 * \brief a data structure to represent one nonzero in a generalMatrix element
 */
class GeneralMatrixElement
{
public:
    int numberOfEl;
    Nl **el;

    GeneralMatrixElement();
    ~GeneralMatrixElement();

    /**
     *
     * A function to check for the equality of two objects
     */
    bool IsEqual(GeneralMatrixElement *that);

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
    bool deepCopyFrom(GeneralMatrixElement *that);
};//class GeneralMatrixElement
#endif

/*! \class GeneralMatrixValues
 * \brief a data structure to represent the nonzeros in a generalMatrix element
 */
class GeneralMatrixValues
{
public:
    int numberOfEl;
    ScalarExpressionTree **el;

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
    /**
     *  numberOfValues records the number of entries in the arrays
     *  that make up the instance of nonzeros
     */
    int numberOfValues;
 
    /**
     *  To indicate whether the general matrix elements are stored 
     *  in row major form or column major form
     */
    bool rowMajor;

    /**
     *  A vector listing the row or column starts
     */
    IntVector *start;

    /** 
     *  The indexes of the (nonzero) linear matrix elements
     *  row or column indexes, depending on rowMajor */
    IntVector *indexes;

    /**
     *  The values are general nonlinear expressions 
     */
    GeneralMatrixValues *values;

    GeneralMatrixElements();
    ~GeneralMatrixElements();

    /**
     * A function to check for the equality of two objects
     */
    bool IsEqual(GeneralMatrixElements *that);

    /**
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
    /**
     *  numberOfValues records the number of entries in the arrays
     *  that make up the instance of nonzeros
     */
    int numberOfValues;
 
    /**
     *  To indicate whether the objReference matrix elements are stored 
     *  in row major form or column major form
     */
    bool rowMajor;

    /**
     *  A vector listing the row or column starts
     */
    IntVector *start;

    /** The row (or column) indices and objective references of the elements */
    IntVector *indexes;
    IntVector *values;

    ObjReferenceMatrixElements();
    ~ObjReferenceMatrixElements();

    /**
     *
     * A function to check for the equality of two objects
     */
    bool IsEqual(ObjReferenceMatrixElements *that);

    /**
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
    /**
     *  numberOfValues records the number of entries in the arrays
     *  that make up the instance of nonzeros
     */
    int numberOfValues;
 
    /**
     *  To indicate whether the conReference matrix elements are stored 
     *  in row major form or column major form
     */
    bool rowMajor;

    /**
     *  A vector listing the row or column starts
     */
    IntVector *start;

    /** The row (or column) indices and constraint references of the elements */
    IntVector *indexes;
    IntVector *values;

    ConReferenceMatrixElements();
    ~ConReferenceMatrixElements();

    /**
     *
     * A function to check for the equality of two objects
     */
    bool IsEqual(ConReferenceMatrixElements *that);

    /**
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


/*! \class MatrixElements
 * \brief a data structure to represent the nonzeroes of a matrix explicitly element by element
 */
class MatrixElements : public MatrixConstructor
{
public:
    ConstantMatrixElements         *constantElements;
    VarReferenceMatrixElements *varReferenceElements;
    LinearMatrixElements             *linearElements;
    GeneralMatrixElements           *generalElements;
    ObjReferenceMatrixElements *objReferenceElements;
    ConReferenceMatrixElements *conReferenceElements;

    MatrixElements();
    virtual ~MatrixElements();

    /**
     * @return the value of nType
     */
    virtual ENUM_MATRIX_CONSTRUCTOR_TYPE getNodeType();

    /**
     * @return the name of the operator
     */
    virtual std::string getNodeName();


    /*! \fn MatrixElements *cloneMatrixNode()
     *  \brief The implementation of the virtual functions.
     *  \return a pointer to a new MatrixNode of the proper type.
     */
    virtual MatrixElements *cloneMatrixNode();

    /**
     * make a copy of this node and all its descendants
     * @return a pointer to the duplicate node
     */
    MatrixElements* copyNodeAndDescendants();

    /**
     * A function to check for the equality of two objects
     */
    bool IsEqual(MatrixElements *that);

    /**
     * <p>
     * The following method writes a matrix node in OSgL format. 
     * it is used by OSgLWriter to write a <matrix> element.
     * </p>
     *
     * @return the MatrixNode and its children as an OSgL string.
     */
    virtual std::string getMatrixNodeInXML();

    /**
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
class MatrixTransformation : public MatrixConstructor
{
public:
    OSnLMNode *transformation;

    MatrixTransformation();
    ~MatrixTransformation();

    /**
     * @return the value of nType
     */
    virtual ENUM_MATRIX_CONSTRUCTOR_TYPE getNodeType();

    /**
     * @return the name of the operator
     */
    virtual std::string getNodeName();


    /**
     * <p>
     * The following method writes a matrix node in OSgL format. 
     * it is used by OSgLWriter to write a <matrix> element.
     * </p>
     *
     * @return the MatrixNode and its children as an OSgL string.
     */
    virtual std::string getMatrixNodeInXML();

    /*! \fn MatrixTransformation *cloneMatrixNode()
     *  \brief The implementation of the virtual functions.
     *  \return a pointer to a new MatrixNode of the proper type.
     */
    virtual MatrixTransformation *cloneMatrixNode();

    /**
     *
     * A function to check for the equality of two objects
     */
    bool IsEqual(MatrixTransformation *that);

    /**
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
 *  through transformation, or by nested blocks, and so on, recursively.
 */
class MatrixBlocks : public MatrixConstructor
{
public:
    /**
     *  An array listing the leftmost column of each block within the larger matrix
     *  It is assumed that the blocks are neatly "stacked"
     */
    IntVector *colOffsets;

    /**
     *  An array listing the top row of each block within the larger matrix
     */
    IntVector *rowOffsets;

    /** 
     *  This integer gives the number of blocks for which values are provided
     *  Due to block-sparsity, this could be less than card(colOffsets)*card(rowOffsets)
     */
    int numberOfBlocks;

    /** The nonzeros in each block are held in this data structure */
    MatrixBlock **block;

    MatrixBlocks();
    ~MatrixBlocks();

    /**
     * @return the value of nType
     */
    virtual ENUM_MATRIX_CONSTRUCTOR_TYPE getNodeType();

    /**
     * @return the name of the operator
     */
    virtual std::string getNodeName();


    /**
     * <p>
     * The following method writes a matrix node in OSgL format. 
     * it is used by OSgLWriter to write a <matrix> element.
     * </p>
     *
     * @return the MatrixNode and its children as an OSgL string.
     */
    virtual std::string getMatrixNodeInXML();

    /*! \fn MatrixBlocks *cloneMatrixNode()
     *  \brief The implementation of the virtual functions.
     *  \return a pointer to a new MatrixNode of the proper type.
     */
    virtual MatrixBlocks *cloneMatrixNode();

    /**
     * A function to check for the equality of two objects
     */
    bool IsEqual(MatrixBlocks *that);

    /**
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


/*! \class BaseMatrix
 * \brief a data structure to represent a point of departure for
 *  constructing a matrix by modifying parts of a previously defined matrix 
 */
class BaseMatrix : public MatrixConstructor
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
     * @return the value of nType
     */
    virtual ENUM_MATRIX_CONSTRUCTOR_TYPE getNodeType();

    /**
     * @return the name of the operator
     */
    virtual std::string getNodeName();


    /**
     * <p>
     * The following method writes a matrix node in OSgL format. 
     * it is used by OSgLWriter to write a <matrix> element.
     * </p>
     *
     * @return the MatrixNode and its children as an OSgL string.
     */
    virtual std::string getMatrixNodeInXML();

    /*! \fn BaseMatrix *cloneMatrixNode()
     *  \brief The implementation of the virtual functions.
     *  \return a pointer to a new MatrixNode of the proper type.
     */
    virtual BaseMatrix *cloneMatrixNode();

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
 * \brief a data structure to represent a MatrixType object (from which we derive OSMatrix and MatrixBlock)
 *
 */
class MatrixType : public MatrixNode
{
public:
    int numberOfRows;
    int numberOfColumns;
    ENUM_MATRIX_SYMMETRY symmetry;

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
 * \brief a data structure to represent a matrix object (derived from MatrixType)
 *
 */
class OSMatrix : public MatrixType
{
public:
//    int numberOfRows;
//    int numberOfColumns;
    int idx;
    std::string name;

    OSMatrix();
    ~OSMatrix();

    /**
     * <p>
     * Take a vector of MatrixNodes in prefix format
     * and create a matrix root node
     * </p>
     * @param mtxConstructorVec holds a vector of pointers to matrix constructors,
     * mtxConstructorVec and blocks in prefix format
     * @return a pointer to an OSMatrix which is the root of
     * a list of constructors.
     */
    OSMatrix* createConstructorTreeFromPrefix(std::vector<MatrixNode*> mtxConstructorVec);

    /**
     * @return the value of nType
     */
    virtual ENUM_MATRIX_CONSTRUCTOR_TYPE getNodeType();

    /**
     * @return the name of the operator
     */
    virtual std::string getNodeName();

    /**
     * add values to this matrix.
     *
     * <p>
     *
     * @param name holds the matrix name; use null or empty std::string ("") if no matrix name.
     * @param numberOfRows holds the number of rows. It is required. Use 1 for column vectors.
     * @param numberOfColumns holds the number of columns. It is required. Use 1 for row vectors.
     * @param symmetry holds the type of symmetry used in the definition of the matrix. 
     *        For more information  see the enumeration ENUM_MATRIX_SYMMETRY in OSGeneral.h.
     *        If no symmetry, use ENUM_MATRIX_SYMMETRY_none.
     * @param matrixType tracks the type of elements contained in this matrix.
     *        For more information  see the enumeration ENUM_MATRIX_TYPE in OSGeneral.h.
     *        If unsure, use ENUM_MATRIX_TYPE_unknown.
     * @param inumberOfChildren is the number of MatrixNode child elements,
     *        i.e., the number of matrix constructors in the m_mChildren array. 
     * @param m_mChildren is the array of matrix constructors used in the definition of this matrix.
     * @return whether the matrix was added successfully.
     */
    bool setMatrix(std::string name, int numberOfRows, int numberOfColumns, 
                   ENUM_MATRIX_SYMMETRY symmetry, ENUM_MATRIX_TYPE matrixType, 
                   unsigned int inumberOfChildren, MatrixNode **m_mChildren);


    /**
     * <p>
     * The following method writes a matrix node in OSgL format. 
     * it is used by OSgLWriter to write a <matrix> element.
     * </p>
     *
     * @return the MatrixNode and its children as an OSgL string.
     */
    virtual std::string getMatrixNodeInXML();

    /*! \fn OSMatrix *cloneMatrixNode()
     *  \brief The implementation of the virtual functions.
     *  \return a pointer to a new MatrixNode of the proper type.
     */
    virtual OSMatrix *cloneMatrixNode();

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
     * @return the value of nType
     */
    virtual ENUM_MATRIX_CONSTRUCTOR_TYPE getNodeType();

    /**
     * @return the name of the operator
     */
    virtual std::string getNodeName();


    /**
     * <p>
     * The following method writes a matrix node in OSgL format. 
     * it is used by OSgLWriter to write a <matrix> element.
     * </p>
     *
     * @return the MatrixNode and its children as an OSgL string.
     */
    virtual std::string getMatrixNodeInXML();

    /*! \fn MatrixBlock *cloneMatrixNode()
     *  \brief The implementation of the virtual functions.
     *  \return a pointer to a new MatrixNode of the proper type.
     */
    virtual MatrixBlock *cloneMatrixNode();

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
