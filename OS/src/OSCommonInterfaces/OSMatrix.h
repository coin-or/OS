/* $Id: OSMatrix.h 3172 2010-02-05 04:59:24Z Gassmann $ */
/** @file OSMatrix.h
 *
 * @author  Horand Gassmann, Jun Ma, Kipp Martin
 *
 * \remarks
 * Copyright (C) 2010-2015, Horand Gassmann, Jun Ma, Kipp Martin,
 * Northwestern University, and the University of Chicago.
 * All Rights Reserved.
 * This software is licensed under the Eclipse Public License.
 * Please see the accompanying LICENSE file in root directory for terms.
 *
 */

#ifndef OSMATRIX_H
#define OSMATRIX_H

#include "OSConfig.h"
#include "OSParameters.h"
#include "OSnLNode.h"
#include "OSExpressionTree.h"

#include <string>
#include <vector>
#include <complex>


/*********************************************************************************
 *
 * This file contains a number of classes to represent a matrix
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
class OSnLCNode;
class RealValuedExpressionTree;


/*! \class MatrixNode
 *  \brief a generic class from which we derive matrix constructors
 *  (BaseMatrix, MatrixElements, MatrixTransformation and MatrixBlocks)
 *  as well as matrix types (OSMatrix and MatrixBlock).
 *
 *  The full inheritance tree looks like this:
 *  MatrixNode   
 *      MatrixConstructor
 *          BaseMatrix
 *          MatrixTransformation
 *          MatrixElements
 *              ConstantMatrixElements
 *              ComplexMatrixElements
 *              VarReferenceMatrixElements
 *              ObjReferenceMatrixElements
 *              ConReferenceMatrixElements
 *              MixedRowReferenceMatrixElements
 *              LinearMatrixElements
 *              RealValuedExpressions
 *              ComplexValuedExpressions
 *              StringValuedMatrixElements
 *      MatrixType
 *          MatrixBlock
 *          OSMatrix
 *              OSMatrixWithVarIdx
 *              OSMatrixWithObjIdx
 *              OSMatrixWithConIdx
 */
class MatrixNode
{
public:
    /**
     *  The next two data items track the type of elements contained in this MatrixNode,
     *  which may be useful in solver selection
     *  For an enumeration of the possible types see OSParameters.h
     *  declaredMatrixType contains any type that the user may have declared,
     *  inferredMatrixType contains the type derived from the list of matrix constructors
     */
    ENUM_MATRIX_TYPE declaredMatrixType;
    ENUM_MATRIX_TYPE inferredMatrixType;

    /**
     *  nType is a unique integer assigned to each type of matrix node
     *  (see OSParameters.h)
     */
    ENUM_MATRIX_CONSTRUCTOR_TYPE nType;

    /** inumberOfChildren is the number of MatrixNode child elements
     *  For the matrix types (OSMatrix and MatrixBlock) this number
     *  is not fixed and is temporarily set to 0
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
     *  @return the declared type of the matrix elements
     */
    virtual ENUM_MATRIX_TYPE getDeclaredMatrixType();

    /**
     *  @return the inferred type of the matrix elements
     */
    virtual ENUM_MATRIX_TYPE getInferredMatrixType();

    /**
     *  getMatrixType() amalgamates the declared and inferred types 
     *  @return the amalgamated type of the matrix elements:
     *          if mergeTypes(declared,inferred) = declared, return declared
     *          else throw an error (matrix contains undeclared element types)
     */
    virtual ENUM_MATRIX_TYPE getMatrixType();

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
     *  Check whether a submatrix aligns with the block partition of a matrix
     *  or block or other constructor
     *  @param firstRow gives the number of the first row in the submatrix (zero-based)
     *  @param firstColumn gives the number of the first column in the submatrix (zero-based)
     *  @param nRows gives the number of rows in the submatrix
     *  @param nColumns gives the number of columns in the submatrix
     *  @return true if the submatrix aligns with the boundaries of a block
     *  This is an abstract method which is required to be implemented by the concrete
     *  operator nodes that derive or extend from this class.
     */
    virtual bool alignsOnBlockBoundary(int firstRow, int firstColumn, int nRows, int nCols) = 0;

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
 *  To facilitate parsing of complicated matrix constructors and the recursion
 *  implicit in the block structure, we distinguish the following types:
 *  1 - BaseMatrix
 *  2 - several types of Elements (e.g., constant, var reference, etc.)
 *  3 - Transformation
 *  4 - MatrixBlocks
 *  5 - MatrixBlock
 *  6 - OSMatrix
 *  Most of the logic of this representation is derived from the OSnLNode class.
 */
class MatrixConstructor : public MatrixNode
{
public:
    /** constructor */
    MatrixConstructor();

    /** destructor */
    virtual ~MatrixConstructor();

    /**
     *
     * A function to check for the equality of two objects
     */
    //bool IsEqual(MatrixConstructor *that);

    /**
     * A function to make a random instance of this class
     * @param density: corresponds to the probability that a particular child element is created
     * @param conformant: if true enforces side constraints not enforceable in the schema
     *     (e.g., agreement of "numberOfXXX" attributes and <XXX> children)
     * @param iMin: lowest index value (inclusive) that a variable reference in this matrix can take
     * @param iMax: greatest index value (inclusive) that a variable reference in this matrix can take
     */
    //bool setRandom(double density, bool conformant, int iMin, int iMax);

    /**
     * A function to make a deep copy of an instance of this class
     * @param that: the instance from which information is to be copied
     * @return whether the copy was created successfully
     */
    //bool deepCopyFrom(MatrixConstructor *that);
};//class MatrixConstructor


/*! \class MatrixElements
 * \brief an abstract class to help represent the elements in a MatrixType object
 * From this we derive the following concrete classes used to store specific types of values:
 *     ConstantMatrixElements     (real-valued constants, such as 3.14) 
 *     ComplexMatrixElements      (complex-valued constants, such as 1 + 2.78*i)
 *     VarReferenceMatrixElements (elements of the form x_i - return current value of the variable)
 *     LinearMatrixElements       (elements of the form a_0 + a_1*x_{i_1} + ... + a_k*x_{i_k}) 
 *     RealValuedExpressions      (an expression tree with a    real-valued root)
 *     ComplexValuedExpressions   (an expression tree with a complex-valued root)
 *     ObjReferenceMatrixElements (elements of the form o_i - return value of the i'th objective)
 *     ConReferenceMatrixElements (elements of the form c_i - return values associated with i'th constraint)
 *     StringValuedMatrixElements (elements can be general or symbolic strings)
 */
class MatrixElements: public MatrixConstructor
{
public:
    /**
     *  To indicate whether the matrix elements are stored 
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

    /** The index array of the (nonzero) elements */
    IntVector *index;

    /**
     *  To track the kind of symmetry present in the matrix element tag
     *  @remark for definitions, see OSParameters.h
     */
    ENUM_MATRIX_SYMMETRY symmetry;


    MatrixElements();
    virtual ~MatrixElements();

    /**
     * Returns whether the matrix is stored row-wise or column-wise
     */
    bool getRowMajor();

    /**
     * <p>
     * The following method writes a matrix node in OSgL format. 
     * it is used by OSgLWriter to write a <matrix> element.
     * </p>
     *
     * @return the MatrixNode and its children as an OSgL string.
     */
    //virtual std::string getMatrixElementsInXML() = 0;

    /**
     * A function to check for the equality of two objects
     */
    bool IsEqual(MatrixElements *that);

#if 0
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
#endif
};//class MatrixElements


/*! \class MatrixElementValues
 * \brief an abstract class to help represent the elements in a MatrixType object
 * From this we derive concrete classes that are used to store specific types of values,
 * such as constant values, variable references, general nonlinear expressions, etc.
 */
class MatrixElementValues
{
public:
    /** each type of value is stored as an array named "el". 
     *  numberOfEl records the size of this array.
     */
    int numberOfEl;

    MatrixElementValues();
    virtual ~MatrixElementValues();

    /**
     * <p>
     * The following method writes a matrix node in OSgL format. 
     * it is used by OSgLWriter to write a <matrix> element.
     * </p>
     *
     * @return the MatrixNode and its children as an OSgL string.
     */
    //virtual std::string getMatrixValuesInXML() = 0;

    /**
     *
     * A function to check for the equality of two objects
     */
    //bool IsEqual(MatrixElementValues *that);

    /**
     * A function to make a random instance of this class
     * @param density: corresponds to the probability that a particular child element is created
     * @param conformant: if true enforces side constraints not enforceable in the schema
     *     (e.g., agreement of "numberOfXXX" attributes and <XXX> children)
     * @param iMin: lowest index value (inclusive) that a variable reference in this matrix can take
     * @param iMax: greatest index value (inclusive) that a variable reference in this matrix can take
     */
    //bool setRandom(double density, bool conformant, int iMin, int iMax);

    /**
     * A function to make a deep copy of an instance of this class
     * @param that: the instance from which information is to be copied
     * @return whether the copy was created successfully
     */
    virtual bool deepCopyFrom(MatrixElementValues *that);
};//class MatrixElementValues

// ------------------ concrete classes start here ------------------------------

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


/*! \class ConReferenceMatrixElement
 *  \brief a data structure to represent an entry in a conReferenceMatrix element,
 *  which consists of a constraint reference as well as a value type.
 *  @remark We use the same class to describe MixedRowReferenceMatrix elements.
 *  A MixedRowReferenceMatrix is obtained by combining ObjReferenceMatrix elements
 *  and ConReferenceMatrix elements into a single matrix constructor.
 */
class ConReferenceMatrixElement
{
public:
    /** 
     *  contains a reference to a row of the problem (objective if negative, constraint otherwise) 
     *  @remark If used in a ConReferenceMatrix, the nonnegativity required is verified and enforced
     */
    int conReference;

    /**
     *  Several different types of values can be derived from a problem constraint. 
     *  (See OSParameters.h for an enumeration.) 
     */
    ENUM_CONREFERENCE_VALUETYPE valueType;

    /** This element contains the value */
    double value;

    ConReferenceMatrixElement();
    ~ConReferenceMatrixElement();

    /**
     * A function to check for the equality of two objects
     */
    bool IsEqual(ConReferenceMatrixElement *that);

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
    bool deepCopyFrom(ConReferenceMatrixElement *that);
};//class ConReferenceMatrixElement

#if 0
/*! \class ComplexMatrixElement
 *  \brief a data structure to represent an entry in a complexMatrix element,
 *  which consists of a real and an imaginary part.
 */
class ComplexMatrixElement
{
public:
    /** 
     *  the real part 
     */
    int Re;

    /** 
     *  the imaginary part 
     */
    int Im;

    ComplexMatrixElement();
    ~ComplexMatrixElement();

    /**
     * A function to check for the equality of two objects
     */
    bool IsEqual(ComplexMatrixElement *that);

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
    bool deepCopyFrom(ComplexMatrixElement *that);
};//class ComplexMatrixElement
#endif

/*! \class ConstantMatrixValues
 *  \brief to represent the nonzeros in a constantMatrix element
 */
class ConstantMatrixValues : public MatrixElementValues
{
public:
    double *el;

    ConstantMatrixValues();
    ~ConstantMatrixValues();

    /**
     * @return the value of nType
     */
    //virtual ENUM_MATRIX_CONSTRUCTOR_TYPE getNodeType();

    /**
     *  @return the type of the matrix elements
     */
    //virtual ENUM_MATRIX_TYPE getMatrixType();

    /**
     * @return the name of the matrix constructor
     */
    //virtual std::string getNodeName();

    /**
     * <p>
     * The following method writes a matrix node in OSgL format. 
     * it is used by OSgLWriter to write a <matrix> element.
     * </p>
     *
     * @return the MatrixNode and its children as an OSgL string.
     */
    //virtual std::string getMatrixValuesInXML();

    /**
     *
     * A function to check for the equality of two objects
     */
    bool IsEqual(ConstantMatrixValues *that);

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
    bool deepCopyFrom(ConstantMatrixValues *that);
};//class ConstantMatrixValues


/*! \class ComplexMatrixValues
 *  \brief to represent the nonzeros in a complexConstantMatrix element
 */
class ComplexMatrixValues : public MatrixElementValues
{
public:
    std::complex<double> *el;

    ComplexMatrixValues();
    ~ComplexMatrixValues();

    /**
     * @return the value of nType
     */
    //virtual ENUM_MATRIX_CONSTRUCTOR_TYPE getNodeType();

    /**
     *  @return the type of the matrix elements
     */
    //virtual ENUM_MATRIX_TYPE getMatrixType();

    /**
     * @return the name of the matrix constructor
     */
    //virtual std::string getNodeName();

    /**
     * <p>
     * The following method writes a matrix node in OSgL format. 
     * it is used by OSgLWriter to write a <matrix> element.
     * </p>
     *
     * @return the MatrixNode and its children as an OSgL string.
     */
    //virtual std::string getMatrixValuesInXML();

    /**
     *
     * A function to check for the equality of two objects
     */
    bool IsEqual(ComplexMatrixValues *that);

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
    bool deepCopyFrom(ComplexMatrixValues *that);
};//class ComplexMatrixValues


/*! \class VarReferenceMatrixValues
 * \brief A concrete class that is used to store a specific type of matrix values,
 * references to variable indexes defined in the core section.
 */
class VarReferenceMatrixValues : public MatrixElementValues
{
public:
    /**
     * Each el is a reference to a constraint defined in the <constraints> section of the OSiL file
     */
    int *el;

    VarReferenceMatrixValues();
    ~VarReferenceMatrixValues();

    /**
     *
     * A function to check for the equality of two objects
     */
    bool IsEqual(VarReferenceMatrixValues *that);

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
    virtual bool deepCopyFrom(VarReferenceMatrixValues *that);
};//class VarReferenceMatrixValues


/*! \class LinearMatrixValues
 * \brief a data structure to represent the linear expressions in a LinearMatrixElement object
 */
class LinearMatrixValues : public MatrixElementValues
{
public:
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
    virtual bool deepCopyFrom(LinearMatrixValues *that);
};//class LinearMatrixValues


/*! \class RealValuedExpressionArray
 * \brief a data structure to represent the nonzeros in a matrix of real-valued expressions
 */
class RealValuedExpressionArray : public MatrixElementValues
{
public:
    RealValuedExpressionTree **el;

    RealValuedExpressionArray();
    ~RealValuedExpressionArray();

    /**
     *
     * A function to check for the equality of two objects
     */
    bool IsEqual(RealValuedExpressionArray *that);

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
    virtual bool deepCopyFrom(RealValuedExpressionArray *that);
};//class RealValuedExpressionArray


/*! \class ComplexValuedExpressionArray
 * \brief a data structure to represent nonzero expressions in an OSMatrix element
 */
class ComplexValuedExpressionArray : public MatrixElementValues
{
public:
    ComplexValuedExpressionTree **el;

    ComplexValuedExpressionArray();
    ~ComplexValuedExpressionArray();

    /**
     *
     * A function to check for the equality of two objects
     */
    bool IsEqual(ComplexValuedExpressionArray *that);

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
    virtual bool deepCopyFrom(ComplexValuedExpressionArray *that);
};//class ComplexValuedExpressionArray


/*! \class ObjReferenceMatrixValues
 *  \brief to represent the nonzeros in an objReferenceMatrix element
 */
class ObjReferenceMatrixValues : public MatrixElementValues
{
public:
    int *el;

    ObjReferenceMatrixValues();
    ~ObjReferenceMatrixValues();

    /**
     *
     * A function to check for the equality of two objects
     */
    bool IsEqual(ObjReferenceMatrixValues *that);

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
    virtual bool deepCopyFrom(ObjReferenceMatrixValues *that);
};//class ObjReferenceMatrixValues


/*! \class ConReferenceMatrixValues
 *  \brief a data structure to represent the nonzeros in a conReferenceMatrix element
 */
class ConReferenceMatrixValues : public MatrixElementValues
{
public:
    /** 
     *  el contains the indices of the matrix constraints along with the valueType.
     */  
    ConReferenceMatrixElement **el;

    ConReferenceMatrixValues();
    ~ConReferenceMatrixValues();

    /**
     * A function to check for the equality of two objects
     */
    bool IsEqual(ConReferenceMatrixValues *that);

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
    virtual bool deepCopyFrom(ConReferenceMatrixValues *that);
};//class ConReferenceMatrixValues


/*! \class StringValuedMatrixValues
 *  \brief to represent the nonzeros in a stringValuedMatrix element
 */
class StringValuedMatrixValues : public MatrixElementValues
{
public:
    std::string *el;

    StringValuedMatrixValues();
    ~StringValuedMatrixValues();

    /**
     * @return the value of nType
     */
    //virtual ENUM_MATRIX_CONSTRUCTOR_TYPE getNodeType();

    /**
     *  @return the type of the matrix elements
     */
    //virtual ENUM_MATRIX_TYPE getMatrixType();

    /**
     * @return the name of the matrix constructor
     */
    //virtual std::string getNodeName();

    /**
     * <p>
     * The following method writes a matrix node in OSgL format. 
     * it is used by OSgLWriter to write a <matrix> element.
     * </p>
     *
     * @return the MatrixNode and its children as an OSgL string.
     */
    //virtual std::string getMatrixValuesInXML();

    /**
     *
     * A function to check for the equality of two objects
     */
    bool IsEqual(StringValuedMatrixValues *that);

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
    bool deepCopyFrom(StringValuedMatrixValues *that);
};//class StringValuedMatrixValues


/*! \class ConstantMatrixElements
 * \brief a data structure to represent the constant elements in a MatrixType object
 */
class ConstantMatrixElements: public MatrixElements
{
public:
    /** The value array of the (nonzero) constant elements */
    ConstantMatrixValues *value;

    ConstantMatrixElements();
    ~ConstantMatrixElements();


    /**
     * @return the value of nType
     */
    virtual ENUM_MATRIX_CONSTRUCTOR_TYPE getNodeType();

    /**
     * @return the name of the matrix constructor
     */
    virtual std::string getNodeName();

    /**
     *  @return the inferred type of the matrix elements
     */
    virtual ENUM_MATRIX_TYPE getInferredMatrixType();

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
     *  Check whether a submatrix aligns with the block partition of a matrix
     *  or block or other constructor
     *  @param firstRow gives the number of the first row in the submatrix (zero-based)
     *  @param firstColumn gives the number of the first column in the submatrix (zero-based)
     *  @param nRows gives the number of rows in the submatrix
     *  @param nColumns gives the number of columns in the submatrix
     *  @return true if the submatrix aligns with the boundaries of a block
     *  This is an abstract method which is required to be implemented by the concrete
     *  operator nodes that derive or extend from this class.
     */
    virtual bool alignsOnBlockBoundary(int firstRow, int firstColumn, int nRows, int nCols);

    /**
     * <p>
     * Create or clone a node of this type.
     * This is an abstract method which is required to be implemented by the concrete
     * operator nodes that derive or extend from this class.
     * </p>
     */
    virtual ConstantMatrixElements *cloneMatrixNode();

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


/*! \class ComplexMatrixElements
 * \brief a data structure to represent the complex-valued constant elements in a MatrixType object
 */
class ComplexMatrixElements: public MatrixElements
{
public:
    /** The value array of the (nonzero) complex elements */
    ComplexMatrixValues *value;

    ComplexMatrixElements();
    ~ComplexMatrixElements();


    /**
     * @return the value of nType
     */
    virtual ENUM_MATRIX_CONSTRUCTOR_TYPE getNodeType();

    /**
     * @return the name of the matrix constructor
     */
    virtual std::string getNodeName();

    /**
     *  @return the inferred type of the matrix elements
     */
    virtual ENUM_MATRIX_TYPE getInferredMatrixType();

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
     *  Check whether a submatrix aligns with the block partition of a matrix
     *  or block or other constructor
     *  @param firstRow gives the number of the first row in the submatrix (zero-based)
     *  @param firstColumn gives the number of the first column in the submatrix (zero-based)
     *  @param nRows gives the number of rows in the submatrix
     *  @param nColumns gives the number of columns in the submatrix
     *  @return true if the submatrix aligns with the boundaries of a block
     *  This is an abstract method which is required to be implemented by the concrete
     *  operator nodes that derive or extend from this class.
     */
    virtual bool alignsOnBlockBoundary(int firstRow, int firstColumn, int nRows, int nCols);

    /**
     * <p>
     * Create or clone a node of this type.
     * This is an abstract method which is required to be implemented by the concrete
     * operator nodes that derive or extend from this class.
     * </p>
     */
    virtual ComplexMatrixElements *cloneMatrixNode();

    /**
     *
     * A function to check for the equality of two objects
     */
    bool IsEqual(ComplexMatrixElements *that);

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
    bool deepCopyFrom(ComplexMatrixElements *that);
};//class ComplexMatrixElements


/*! \class VarReferenceMatrixElements
 * \brief a data structure to represent variable reference elements in a MatrixType object
 *  Each nonzero element is of the form x_{k} where k is the index of a variable
 */
class VarReferenceMatrixElements: public MatrixElements
{
public:
    /** The variable references (indexes of core variables) of the elements */
    VarReferenceMatrixValues *value;

    VarReferenceMatrixElements();
    ~VarReferenceMatrixElements();

    /**
     * @return the value of nType
     */
    virtual ENUM_MATRIX_CONSTRUCTOR_TYPE getNodeType();

    /**
     *  @return the inferred type of the matrix elements
     */
    virtual ENUM_MATRIX_TYPE getInferredMatrixType();

    /**
     * @return the name of the matrix constructor
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

    /** 
     *  Check whether a submatrix aligns with the block partition of a matrix
     *  or block or other constructor
     *  @param firstRow gives the number of the first row in the submatrix (zero-based)
     *  @param firstColumn gives the number of the first column in the submatrix (zero-based)
     *  @param nRows gives the number of rows in the submatrix
     *  @param nColumns gives the number of columns in the submatrix
     *  @return true if the submatrix aligns with the boundaries of a block
     *  This is an abstract method which is required to be implemented by the concrete
     *  operator nodes that derive or extend from this class.
     */
    virtual bool alignsOnBlockBoundary(int firstRow, int firstColumn, int nRows, int nCols);

    /**
     * <p>
     * Create or clone a node of this type.
     * This is an abstract method which is required to be implemented by the concrete
     * operator nodes that derive or extend from this class.
     * </p>
     */
    virtual VarReferenceMatrixElements *cloneMatrixNode();

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


/*! \class LinearMatrixElements
 * \brief a data structure to represent the nonzero values in a linearMatrix element
 */
class LinearMatrixElements: public MatrixElements
{
public:
    /**
     *  The values are expressions of the form
     *  a_0 + a_1 x_{i_1} * a_2 x_{i_2} + ...
     *  Each term in this sum is stored as a separate LinearMatrixValues object
     */
    LinearMatrixValues *value;     

    LinearMatrixElements();
    ~LinearMatrixElements();


    /**
     * @return the value of nType
     */
    virtual ENUM_MATRIX_CONSTRUCTOR_TYPE getNodeType();

    /**
     *  @return the inferred type of the matrix elements
     */
    virtual ENUM_MATRIX_TYPE getInferredMatrixType();

    /**
     * @return the name of the matrix constructor
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

    /** 
     *  Check whether a submatrix aligns with the block partition of a matrix
     *  or block or other constructor
     *  @param firstRow gives the number of the first row in the submatrix (zero-based)
     *  @param firstColumn gives the number of the first column in the submatrix (zero-based)
     *  @param nRows gives the number of rows in the submatrix
     *  @param nColumns gives the number of columns in the submatrix
     *  @return true if the submatrix aligns with the boundaries of a block
     *  This is an abstract method which is required to be implemented by the concrete
     *  operator nodes that derive or extend from this class.
     */
    virtual bool alignsOnBlockBoundary(int firstRow, int firstColumn, int nRows, int nCols);

    /**
     * <p>
     * Create or clone a node of this type.
     * This is an abstract method which is required to be implemented by the concrete
     * operator nodes that derive or extend from this class.
     * </p>
     */
    virtual LinearMatrixElements *cloneMatrixNode();

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

    /**
     *  Some methods to convert one type of matrix elements into another
     *  @param _values is the array  of matrix elements that are to be converted
     *  @param nvalues is the number of matrix elements that are to be converted
     *  @return true if the conversion was successful
     */
    bool convertFromConstant(ConstantMatrixValues*     _values, int nvalues);
    bool convertFromVarRef  (VarReferenceMatrixValues* _values, int nvalues);
};//class LinearMatrixElements


/*! \class RealValuedExpressions
 * \brief a data structure to represent the nonzero values in a matrix of real-valued expressions
 */
class RealValuedExpressions: public MatrixElements
{
public:
    /**
     *  The values are general nonlinear expressions 
     */
    RealValuedExpressionArray *value;

    RealValuedExpressions();
    ~RealValuedExpressions();


    /**
     * @return the value of nType
     */
    virtual ENUM_MATRIX_CONSTRUCTOR_TYPE getNodeType();

    /**
     *  @return the inferred type of the matrix elements
     */
    virtual ENUM_MATRIX_TYPE getInferredMatrixType();

    /**
     * @return the name of the matrix constructor
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

    /** 
     *  Check whether a submatrix aligns with the block partition of a matrix
     *  or block or other constructor
     *  @param firstRow gives the number of the first row in the submatrix (zero-based)
     *  @param firstColumn gives the number of the first column in the submatrix (zero-based)
     *  @param nRows gives the number of rows in the submatrix
     *  @param nColumns gives the number of columns in the submatrix
     *  @return true if the submatrix aligns with the boundaries of a block
     *  This is an abstract method which is required to be implemented by the concrete
     *  operator nodes that derive or extend from this class.
     */
    virtual bool alignsOnBlockBoundary(int firstRow, int firstColumn, int nRows, int nCols);

    /**
     * <p>
     * Create or clone a node of this type.
     * This is an abstract method which is required to be implemented by the concrete
     * operator nodes that derive or extend from this class.
     * </p>
     */
    virtual RealValuedExpressions *cloneMatrixNode();

    /**
     * A function to check for the equality of two objects
     */
    bool IsEqual(RealValuedExpressions *that);

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
    bool deepCopyFrom(RealValuedExpressions *that);
};//class RealValuedExpressions


/*! \class ComplexValuedExpressions
 * \brief a data structure to represent nonzero values in the form of complex-valued expression trees
 */
class ComplexValuedExpressions: public MatrixElements
{
public:
    /**
     *  The values are general nonlinear expressions 
     */
    ComplexValuedExpressionArray *value;

    ComplexValuedExpressions();
    ~ComplexValuedExpressions();


    /**
     * @return the value of nType
     */
    virtual ENUM_MATRIX_CONSTRUCTOR_TYPE getNodeType();

    /**
     *  @return the inferred type of the matrix elements
     */
    virtual ENUM_MATRIX_TYPE getInferredMatrixType();

    /**
     * @return the name of the matrix constructor
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

    /** 
     *  Check whether a submatrix aligns with the block partition of a matrix
     *  or block or other constructor
     *  @param firstRow gives the number of the first row in the submatrix (zero-based)
     *  @param firstColumn gives the number of the first column in the submatrix (zero-based)
     *  @param nRows gives the number of rows in the submatrix
     *  @param nColumns gives the number of columns in the submatrix
     *  @return true if the submatrix aligns with the boundaries of a block
     *  This is an abstract method which is required to be implemented by the concrete
     *  operator nodes that derive or extend from this class.
     */
    virtual bool alignsOnBlockBoundary(int firstRow, int firstColumn, int nRows, int nCols);

    /**
     * <p>
     * Create or clone a node of this type.
     * This is an abstract method which is required to be implemented by the concrete
     * operator nodes that derive or extend from this class.
     * </p>
     */
    virtual ComplexValuedExpressions *cloneMatrixNode();

    /**
     * A function to check for the equality of two objects
     */
    bool IsEqual(ComplexValuedExpressions *that);

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
    bool deepCopyFrom(ComplexValuedExpressions *that);
};//class ComplexValuedExpressions


/*! \class ObjReferenceMatrixElements
 * \brief a data structure to represent objective reference elements in a MatrixType object
 *  Each nonzero element is of the form x_{k} where k is the index of an objective (i.e., less than zero)
 */
class ObjReferenceMatrixElements: public MatrixElements
{
public:
    /** The objective references (indexes of core objectives) of the elements */
    ObjReferenceMatrixValues *value;

    ObjReferenceMatrixElements();
    ~ObjReferenceMatrixElements();


    /**
     * @return the value of nType
     */
    virtual ENUM_MATRIX_CONSTRUCTOR_TYPE getNodeType();

    /**
     *  @return the inferred type of the matrix elements
     */
    virtual ENUM_MATRIX_TYPE getInferredMatrixType();

    /**
     * @return the name of the matrix constructor
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

    /** 
     *  Check whether a submatrix aligns with the block partition of a matrix
     *  or block or other constructor
     *  @param firstRow gives the number of the first row in the submatrix (zero-based)
     *  @param firstColumn gives the number of the first column in the submatrix (zero-based)
     *  @param nRows gives the number of rows in the submatrix
     *  @param nColumns gives the number of columns in the submatrix
     *  @return true if the submatrix aligns with the boundaries of a block
     *  This is an abstract method which is required to be implemented by the concrete
     *  operator nodes that derive or extend from this class.
     */
    virtual bool alignsOnBlockBoundary(int firstRow, int firstColumn, int nRows, int nCols);

    /**
     * <p>
     * Create or clone a node of this type.
     * This is an abstract method which is required to be implemented by the concrete
     * operator nodes that derive or extend from this class.
     * </p>
     */
    virtual ObjReferenceMatrixElements *cloneMatrixNode();

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
 * \brief a data structure to represent row reference elements in a MatrixType object
 *  Each nonzero element is of the form x_{k} where k is the index of a constraint
 */
class ConReferenceMatrixElements: public MatrixElements
{
public:
    /** The constraint references (indexes of core constraints and value types) of the elements */
    ConReferenceMatrixValues *value;

    ConReferenceMatrixElements();
    ~ConReferenceMatrixElements();


    /**
     *  @return the constructor type 
     */
    virtual ENUM_MATRIX_CONSTRUCTOR_TYPE getNodeType();

    /**
     *  @return the inferred type of the matrix elements
     */
    virtual ENUM_MATRIX_TYPE getInferredMatrixType();

    /**
     * @return the name of the matrix constructor
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

    /** 
     *  Check whether a submatrix aligns with the block partition of a matrix
     *  or block or other constructor
     *  @param firstRow gives the number of the first row in the submatrix (zero-based)
     *  @param firstColumn gives the number of the first column in the submatrix (zero-based)
     *  @param nRows gives the number of rows in the submatrix
     *  @param nColumns gives the number of columns in the submatrix
     *  @return true if the submatrix aligns with the boundaries of a block
     *  This is an abstract method which is required to be implemented by the concrete
     *  operator nodes that derive or extend from this class.
     */
    virtual bool alignsOnBlockBoundary(int firstRow, int firstColumn, int nRows, int nCols);

    /**
     * <p>
     * Create or clone a node of this type.
     * This is an abstract method which is required to be implemented by the concrete
     * operator nodes that derive or extend from this class.
     * </p>
     */
    virtual ConReferenceMatrixElements *cloneMatrixNode();

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

    /**
     *  A method to convert objReference matrix elements into general rowReferences
     *  @param _values is the array  of matrix elements that are to be converted
     *  @param nvalues is the number of matrix elements that are to be converted
     *  @return true if the conversion was successful
     */
    bool convertFromObjRef(ObjReferenceMatrixValues* _values, int nvalues);
};//class ConReferenceMatrixElements


/*! \class MixedRowReferenceMatrixElements
 * \brief a data structure to represent row reference elements in a MatrixType object
 *  Each nonzero element references a row (if index is negative) or constraint (otherwise)
 *  This class allows the combining of row and constraint references in a single matrix constructor.
 */
class MixedRowReferenceMatrixElements: public MatrixElements
{
public:
    /** The row references (indexes of core rows plus value type) of the elements.
     *  This information is recycled from the ConReferenceMatrix class.
     *  Negative indices describe objectives (in which case the value type must
     *  be ENUM_CONREFERENCE_VALUETYPE_value).
     *  <p>
     *  Row reference elements are not part of the OSiL schema; they only exist 
     *  in the consolidated form of a matrix (where they are the ONLY constructor).
     */  
    ConReferenceMatrixValues *value;

    MixedRowReferenceMatrixElements();
    ~MixedRowReferenceMatrixElements();


    /**
     * @return the value of nType
     */
    virtual ENUM_MATRIX_CONSTRUCTOR_TYPE getNodeType();

    /**
     *  @return the inferred type of the matrix elements
     */
    virtual ENUM_MATRIX_TYPE getInferredMatrixType();
 
    /**
     * @return the name of the matrix constructor
     */
    virtual std::string getNodeName();

    /**
     * <p>
     * The following method writes the row reference elements in OSgL format. 
     * it is used by OSgLWriter to write a <matrix> element.
     * </p>
     *
     * @return the MatrixNode and its children as an OSgL string.
     * @remark Since row reference elements do not exist in the schema,
     * they must be separated into objective and constraint references.
     */
    virtual std::string getMatrixNodeInXML();

    /** 
     *  Check whether a submatrix aligns with the block partition of a matrix
     *  or block or other constructor
     *  @param firstRow gives the number of the first row in the submatrix (zero-based)
     *  @param firstColumn gives the number of the first column in the submatrix (zero-based)
     *  @param nRows gives the number of rows in the submatrix
     *  @param nColumns gives the number of columns in the submatrix
     *  @return true if the submatrix aligns with the boundaries of a block
     *  This is an abstract method which is required to be implemented by the concrete
     *  operator nodes that derive or extend from this class.
     */
    virtual bool alignsOnBlockBoundary(int firstRow, int firstColumn, int nRows, int nCols);

    /**
     * <p>
     * Create or clone a node of this type.
     * This is an abstract method which is required to be implemented by the concrete
     * operator nodes that derive or extend from this class.
     * </p>
     */
    virtual MixedRowReferenceMatrixElements *cloneMatrixNode();

    /**
     * A function to check for the equality of two objects
     */
    bool IsEqual(MixedRowReferenceMatrixElements *that);

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
    bool deepCopyFrom(MixedRowReferenceMatrixElements *that);
};//class MixedRowReferenceMatrixElements


/*! \class StringValuedMatrixElements
 * \brief a data structure to represent the string-valued elements in a MatrixType object
 */
class StringValuedMatrixElements: public MatrixElements
{
public:
    /** The value array of the (nonzero) constant elements */
    StringValuedMatrixValues *value;

    StringValuedMatrixElements();
    ~StringValuedMatrixElements();


    /**
     * @return the value of nType
     */
    virtual ENUM_MATRIX_CONSTRUCTOR_TYPE getNodeType();

    /**
     * @return the name of the matrix constructor
     */
    virtual std::string getNodeName();

    /**
     *  @return the inferred type of the matrix elements
     */
    virtual ENUM_MATRIX_TYPE getInferredMatrixType();

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
     *  Check whether a submatrix aligns with the block partition of a matrix
     *  or block or other constructor
     *  @param firstRow gives the number of the first row in the submatrix (zero-based)
     *  @param firstColumn gives the number of the first column in the submatrix (zero-based)
     *  @param nRows gives the number of rows in the submatrix
     *  @param nColumns gives the number of columns in the submatrix
     *  @return true if the submatrix aligns with the boundaries of a block
     *  This is an abstract method which is required to be implemented by the concrete
     *  operator nodes that derive or extend from this class.
     */
    virtual bool alignsOnBlockBoundary(int firstRow, int firstColumn, int nRows, int nCols);

    /**
     * <p>
     * Create or clone a node of this type.
     * This is an abstract method which is required to be implemented by the concrete
     * operator nodes that derive or extend from this class.
     * </p>
     */
    virtual StringValuedMatrixElements *cloneMatrixNode();

    /**
     *
     * A function to check for the equality of two objects
     */
    bool IsEqual(StringValuedMatrixElements *that);

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
    bool deepCopyFrom(StringValuedMatrixElements *that);

    /**
     *  Some methods to convert one type of matrix elements into another
     *  @param _values is the array  of matrix elements that are to be converted
     *  @param nvalues is the number of matrix elements that are to be converted
     *  @return true if the conversion was successful
     */
    bool convertFromConstant   (ConstantMatrixValues*         _values, int nvalues);
    bool convertFromVarRef     (VarReferenceMatrixValues*     _values, int nvalues);
    bool convertFromObjRef     (ObjReferenceMatrixValues*     _values, int nvalues);
    bool convertFromLinear     (LinearMatrixValues*           _values, int nvalues);
    bool convertFromConRef     (ConReferenceMatrixValues*     _values, int nvalues);
    bool convertFromGeneral    (RealValuedExpressionArray*    _values, int nvalues);
    bool convertFromComplex    (ComplexMatrixValues*          _values, int nvalues);
    bool convertFromComplexExpr(ComplexValuedExpressionArray* _values, int nvalues);
};//class StringValuedMatrixElements



/*! \class MatrixTransformation
 * \brief a data structure to represent the nonzeroes of a matrix 
 *  by transformation from other (previously defined) matrices 
 */
class MatrixTransformation : public MatrixConstructor
{
public:
    /**
     *  A transformation is essentially an expression tree that evaluates to a matrix
     */
    OSnLMNode *transformation;

    /**
     *  shape can be used to specify linearity etc. of an expression
     *  For possible values, see OSParamaters.h
     */
    ENUM_NL_EXPR_SHAPE shape;

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

#if 0
    /**
     *  @return the declared type of the matrix elements
     */
    virtual ENUM_MATRIX_TYPE getDeclaredMatrixType();

    /**
     *  @return the inferred type of the matrix elements
     */
    virtual ENUM_MATRIX_TYPE getInferredMatrixType();

    /**
     *  @return the amalgamated type of the matrix elements
     */
    virtual ENUM_MATRIX_TYPE getMatrixType();
#endif

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
     *  Check whether a submatrix aligns with the block partition of a matrix
     *  or block or other constructor
     *  @param firstRow gives the number of the first row in the submatrix (zero-based)
     *  @param firstColumn gives the number of the first column in the submatrix (zero-based)
     *  @param nRows gives the number of rows in the submatrix
     *  @param nColumns gives the number of columns in the submatrix
     *  @return true if the submatrix aligns with the boundaries of a block
     */
    virtual bool alignsOnBlockBoundary(int firstRow, int firstColumn, int nRows, int nCols);

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

//class MatrixBlock; //forward declaration

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
    IntVector *colOffset;

    /**
     *  An array listing the top row of each block within the larger matrix
     */
    IntVector *rowOffset;

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

#if 0
    /**
     *  @return the declared type of the matrix elements
     */
    virtual ENUM_MATRIX_TYPE getDeclaredMatrixType();

    /**
     *  @return the inferred type of the matrix elements
     */
    virtual ENUM_MATRIX_TYPE getInferredMatrixType();

    /**
     *  @return the amalgamated type of the matrix elements
     */
    virtual ENUM_MATRIX_TYPE getMatrixType();
#endif

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
     *  Check whether a submatrix aligns with the block partition of a matrix
     *  or block or other constructor
     *  @param firstRow gives the number of the first row in the submatrix (zero-based)
     *  @param firstColumn gives the number of the first column in the submatrix (zero-based)
     *  @param nRows gives the number of rows in the submatrix
     *  @param nColumns gives the number of columns in the submatrix
     *  @return true if the submatrix aligns with the boundaries of a block
     */
    virtual bool alignsOnBlockBoundary(int firstRow, int firstColumn, int nRows, int nCols) ;

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
     * a pointer to the base matrix
     */
    OSMatrix* baseMatrix;

    /**
     * to pinpoint the position of the upper left corner of the base matrix within the target matrix
     */
    int targetMatrixFirstRow;
    int targetMatrixFirstCol;

    /**
     * to pinpoint the position of the upper left corner 
     * of the portion of the base matrix that is to be selected 
     */
    int baseMatrixStartRow;
    int baseMatrixStartCol;

    /**
     * to pinpoint the position of the lower right corner 
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
     * since we permit complex matrix values, we cater to complex multipliers, 
     * which are implemented in the schema as two separate reals for the real and imaginary parts
     */
    double scalarMultiplier;
    double scalarImaginaryPart;

    /** Standard constructor and destructor methods */
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
     *  @return the declared type of the matrix elements
     */
    virtual ENUM_MATRIX_TYPE getDeclaredMatrixType();

    /**
     *  @return the inferred type of the matrix elements
     */
    virtual ENUM_MATRIX_TYPE getInferredMatrixType();

    /**
     *  @return the amalgamated type of the matrix elements
     */
    virtual ENUM_MATRIX_TYPE getMatrixType();

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
     *  Check whether a submatrix aligns with the block partition of a matrix
     *  or block or other constructor
     *  @param firstRow gives the number of the first row in the submatrix (zero-based)
     *  @param firstColumn gives the number of the first column in the submatrix (zero-based)
     *  @param nRows gives the number of rows in the submatrix
     *  @param nColumns gives the number of columns in the submatrix
     *  @return true if the submatrix aligns with the boundaries of a block
     */
    virtual bool alignsOnBlockBoundary(int firstRow, int firstColumn, int nRows, int nCols) ;

    /*! \fn BaseMatrix *cloneMatrixNode()
     *  \brief The implementation of the virtual functions.
     *  \return a pointer to a new MatrixNode of the proper type.
     */
    virtual BaseMatrix *cloneMatrixNode();

    /**
     * A function to check for the equality of two objects
     */
    bool IsEqual(BaseMatrix *that);

#if 0
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
    bool deepCopyFrom(BaseMatrix *that);
#endif
};//class BaseMatrix


/*! \class GeneralSparseMatrix
 * \brief a sparse matrix data structure for matrices that can hold nonconstant values
 */
class GeneralSparseMatrix
{
public:
    /**
     * numberOfRows and numberOfColumns give the dimensions of the matrix
     */
    int numberOfRows;
    int numberOfColumns;

    /**
     * valueType holds the type of values found in the value array.
     * @remark See OSParameters.h for a list of possible types
     */
    ENUM_MATRIX_TYPE valueType;

    /**
     * isRowMajor holds whether the matrix is stored by row. 
     * If false, the matrix is stored by column (which is the default).
     */
    bool isRowMajor;

    /**
     *  To track the type of symmetry present in the matrix or block
     *  @remark for definitions, see OSParameters.h
     */
    ENUM_MATRIX_SYMMETRY symmetry;

    /**
     * startSize is the dimension of the starts array
     */
    int startSize;

    /**
     * valueSize is the dimension of the index and value arrays
     */
    int valueSize;

    /**
     * start holds an integer array of start elements in the matrix,
     * which points to the start of a column (row) of nonzero elements.
     */
    int* start;

    /**
     * index holds an integer array of rowIdx (or colIdx) elements in coefMatrix (AMatrix).
     * If the matrix is stored by column (row), rowIdx (colIdx) is the array of row (column) indices.
     */
    int* index;

    /**
     * value holds a general array of value elements in the matrix,
     * which could be constants, linear expressions, general nonlinear expressions,
     * variable, constraint or objective references, etc. If mixed types are
     * encountered (e.g., constant and nonlinear expression), they are converted 
     * to the most general form found.
     */
    MatrixElementValues* value;

    /**
     * b_deleteStartArray is true if we delete the start array
     * in garbage collection --- set to true by default
     */
    bool b_deleteStartArray;

    /**
     * b_deleteIndexArray is true if we delete the index array
     * in garbage collection --- set to true by default
     */
    bool b_deleteIndexArray;

    /**
     * b_deleteValueArray is true if we delete the value array
     * in garbage collection --- set to true by default
     */
    bool b_deleteValueArray;

    /**
     * Default constructor.
     */
    GeneralSparseMatrix();

    /**
     * Alternate constructor.
     *
     * @param isRowMajor_ holds whether the matrix is stored by column. 
     *        If true, the matrix is stored by row.
     * @param numberOfRows holds the number of rows
     * @param numberOfColumns holds the number of columns
     * @param startSize_ holds the size of the start array.
     * @param valueSize_ holds the size of the value and index arrays.
     * @param type_ describes the type of values held in the matrix (see OSParameters.h).
     */
    GeneralSparseMatrix(bool isRowMajor_, int numberOfRows_, int numberOfColumns_, 
                        int startSize_, int valueSize_, ENUM_MATRIX_TYPE type_);

    /**
     *
     * Default destructor.
     */
    ~GeneralSparseMatrix();

    /**
     * This method displays the data contained in the matrix.
     * </p>
     * @return
     */
    bool printMatrix();

    /**
     *  A method to allocate the value array in a GeneralSparseMatrix
     *  @param nValues gives the size of the value->el array
     *  @return whether the allocation was successful
     *  @remark it is assumed that the element type has been set previously into matrixType
     */
    bool allocateValueArray(int nValues); 

    /**
     *  A method to copy one value from one generalSparseMatrix to another 
     *  of possibly different type
     *  @param sourceMtx is the source from which to copy
     *  @param sourceIndex gives the location within the source's value array to be copied from
     *  @param targetIndex gives the location within the target's value array to be copied to
     *  @param scalarMult if present, gives a real scalar by which to multiply the value to be copied
     *  @param scalarImag if present, gives the imaginary part of the scalar multiplier
     *  @return whether the copy operation was successful
     */
    bool copyValue(GeneralSparseMatrix* sourceMtx, int sourceIndex, int targetIndex, 
                                                   double scalarMult = 1.0, double scalarImag = 0.0); 

    /**
     *  A method to change the orientation of a generalSparseMatrix 
     *  and store the result into another of possibly different type
     *  @remark The normal use of this procedure is to change from a column-wise representation
     *          of a matrix to a row-wise one and vice versa. (This means that row indices are
     *          changed into column indices and vice versa.) However, the same procedure can be
     *          used to find the transpose of a matrix. In this case, the new indices have the
     *          same meaning (row indices, resp. column indices) as in the old matrix.
     *  @param convertTo_ gives the type of elements to be stored into the target matrix
     *  @param transpose_ specifies whether the matrix is to be transposed in the process
     *          (i.e., the identity of the index array is to be adjusted)
     *  @return the transformed matrix
     */
    GeneralSparseMatrix* convertToOtherMajor(ENUM_MATRIX_TYPE convertTo_, bool transpose_);

    /**
     *  A method to change the type of elements in a generalSparseMatrix 
     *  and store the result into another generalSparseMatrix
     *  @param convertTo_ gives the type of elements to be stored into the target matrix
     *  @return the transformed matrix
     */
    GeneralSparseMatrix* convertType(ENUM_MATRIX_TYPE convertTo_);

    /**
     *  A method to change the type of symmetry used in storing a generalSparseMatrix 
     *  The result is stored into another generalSparseMatrix with the same type of values
     *  @param symmetry_ gives the type of symmetry to be used in the target matrix
     *  @return the transformed matrix
     */
    GeneralSparseMatrix* convertSymmetry(ENUM_MATRIX_SYMMETRY symmetry_);

    /**
     *  a method to determine whether the matrix is diagonal
     *  @return whether the matrix is diagonal or not
     */
    bool isDiagonal(); 
}; //GeneralSparseMatrix


/** \class ExpandedMatrixBlocks
 *  \brief a sparse matrix data structure for matrices
 *  that can hold nonconstant values and have block structure
 *  In addition it is assumed that all nesting of blocks
 *  has been resolved.
 */
class ExpandedMatrixBlocks
{
public:
    /**
     *  valueType holds the inferred (usually, the most general) type
     *  of (nonzero) values in this collection of blocks. 
     *  All blocks are assumed to have values of this type (converted, if necessary) 
     */
    ENUM_MATRIX_TYPE valueType;

    /**
     * isRowMajor holds whether the (nonzero) values holding the data in each block
     * are stored by column or row. If false, every block is stored by column.
     */
    bool isRowMajor;

    /**
     *  To track the type of symmetry present in the matrix or block
     *  @remark for definitions, see OSParameters.h
     *  @remark each block is stored in the same format
     */
    ENUM_MATRIX_SYMMETRY symmetry;

    /** 
     * rowOffset gives the row offsets of the block decomposition
     * It does not have to correspond to the row offsets in the matrix's 
     * <blocks> element (indeed there does not have to be such an element
     * at all, or there may be several, possibly incompatible decompositions).
     */
    int* rowOffset;

    /** 
     * colOffset gives the column offsets of the block decomposition
     * It does not have to correspond to the column offsets in the matrix's 
     * <blocks> element (indeed there does not have to be such an element
     * at all, or there may be several, possibly incompatible decompositions).
     */
    int* colOffset;

    /**
     * These two parameters give the size of the rowOffset and colOffset arrays, respectively
     */
    int rowOffsetSize;
    int colOffsetSize;

    /**
     * blockNumber gives the number of blocks (which is the size of
     * the blockRows, blockColumns and blocks arrays below).
     */
    int blockNumber;

    /**
     * blockRows holds an integer array of the row to which a block belongs.
     * It must be of dimension blockNumber.
     * @Remark It is assumed that all blocks in a row have the same number of rows 
     * (while the number of columns is allowed to vary).
     */
    int* blockRows;

    /**
     * blockColumns holds an integer array of the column to which a block belongs.
     * It must be of dimension blockNumber.
     * @Remark It is assumed that all blocks in a column have the same number of columns
     * (while the number of rows is allowed to vary).
     */
    int* blockColumns;

    /**
     * blocks holds the blocks that make up the matrix.
     * All blocks have the same type of values, the same symmetry, 
     * and the same row/column major form.
     */
    GeneralSparseMatrix** blocks;

    /**
     * bDeleteArrays is true if we delete the arrays in garbage collection
     * set to true by default
     */
    bool bDeleteArrays;

    /**
     *
     * Default constructor.
     */
    ExpandedMatrixBlocks();

    /**
     *
     * Default destructor.
     */
    ~ExpandedMatrixBlocks();

    /** 
     * a method to retrieve a particular block from a collection
     * @param rowIdx is the row index of the block to be retrieved
     * @param colIdx is the column index of the block to be retrieved
     * @return a pointer to the block (as a GeneralSparseMatrix)
     */
    GeneralSparseMatrix* getBlock(int rowIdx, int colIdx);

    /**
     *  a method to determine whether the collection is blockDiagonal
     *  @return whether the collection is blockDiagonal or not
     */
    bool isBlockDiagonal(); 
}; //ExpandedMatrixBlocks


/*! \class MatrixType
 * \brief a data structure to represent a MatrixType object (from which we derive OSMatrix and MatrixBlock)
 *
 */
class MatrixType : public MatrixNode
{
public:
    /**
     *  To track the type of symmetry present in the matrix or block
     *  @remark for definitions, see OSParameters.h
     */
    ENUM_MATRIX_SYMMETRY symmetry;

    /**
     *  numberOfRows and numberOfColumns track the dimsion of the matrix or block
     */
    int numberOfRows;
    int numberOfColumns;
   
    /**
     *  The matrix can be held in expanded form elementwise or partitioned into blocks.
     *  In both cases the elements or blocks can be stored by row or by column, symmetry
     *  can be exploited, and the elements can be represented in a number of different formats.
     */
    std::vector<GeneralSparseMatrix* > expandedMatrixByElements;
    std::vector<ExpandedMatrixBlocks*> expandedMatrixByBlocks;

private:
    /** m_bHaveRowPartition tracks whether the row partition has been determined
     *  from the constructor list and stored in m_miRowPartition
     */
    bool m_bHaveRowPartition; 

    /** m_iRowPartitionSize gives the size of the m_miRowPartition array, 
     *  which is one more than the number of blocks in each row
     */
    int m_iRowPartitionSize;

    /** m_miRowPartition is the partition vector of the matrix rows into blocks
     *  @remark This only tracks the top-level partition and does not recurse
     */
    int* m_miRowPartition;

    /** m_bHaveColumnPartition tracks whether the column partition has been determined
     *  from the constructor list and stored in m_miColumnPartition
     */
    bool m_bHaveColumnPartition; 

    /** m_iColumnPartitionSize gives the size of the m_miColumnPartition array, 
     *  which is one more than the number of blocks in each column
     */
    int m_iColumnPartitionSize;

    /** m_miColumnPartition is the partition vector of the matrix columns into blocks
     *  @remark This only tracks the top-level partition and does not recurse
     */
    int* m_miColumnPartition;

public:
    /** default constructor */
    MatrixType();

    /** default destructor */
    virtual ~MatrixType();

    /** 
     *  Check whether a submatrix aligns with the block partition of a matrix
     *  or block or other constructor
     *  @param firstRow gives the number of the first row in the submatrix (zero-based)
     *  @param firstColumn gives the number of the first column in the submatrix (zero-based)
     *  @param nRows gives the number of rows in the submatrix
     *  @param nColumns gives the number of columns in the submatrix
     *  @return true if the submatrix aligns with the boundaries of a block
     */
    virtual bool alignsOnBlockBoundary(int firstRow, int firstColumn, int nRows, int nCols) ;

    /**
     *  Several tools to parse the constructor list of a matrix
     */
    bool matrixHasBase();
    bool matrixHasElements();
    bool matrixHasTransformations();
    bool matrixHasBlocks();
    int  getNumberOfElementConstructors();
    int  getNumberOfTransformationConstructors();
    int  getNumberOfBlocksConstructors();

    /**
     *  a utility routine to expand a matrix into one of several different forms
     *  the expansions are held in expandedMatrixByElements, a std::vector of GeneralSparseMatrix
     *  @param rowMajor_ controls whether the matrix should be expanded into row or column major format
     *  @param convertTo_ controls whether elements should be converted from one type to another
     *  @param symmetry_  controls whether a particular type of symmetry should be enforced
     *                    The default value does not change the symmetry 
     *  @return the index in the collection of expanded matrices corresponding to the current expansion
     *  @remark the return value is -1 in case of any error
     */
    int getExpandedMatrix(bool rowMajor_, 
                          ENUM_MATRIX_TYPE convertTo_    = ENUM_MATRIX_TYPE_unknown,
                          ENUM_MATRIX_SYMMETRY symmetry_ = ENUM_MATRIX_SYMMETRY_default);


    GeneralSparseMatrix* getMatrixBlockInColumnMajorForm(int columnIdx, int rowIdx,
                                 ENUM_MATRIX_TYPE convertTo = ENUM_MATRIX_TYPE_unknown);

    /**
     *  a utility routine to print the expanded matrix or block.
     *  @param idx indicates which entry in the vector of expansions is to be printed
     *  @return whether the operation was successful
     */
    bool printExpandedMatrix(int idx);

    /**
     *  get the size of the row partition of a matrix
     *
     *  @return an corresponding to the number of partition points
     *  of the rows of this matrix (which is one more than the number
     *  of blocks in one row)
     */
    int  getRowPartitionSize();

    /**
     *  get the row partition of the matrix
     *
     *  @return a vector of int corresponding to the partition points
     *  of the rows of this matrix
     */
    int* getRowPartition();

    /**
     *  get the size of the column partition of a matrix
     *
     *  @return an corresponding to the number of partition points
     *  of the columns of this matrix (which is one more than the number
     *  of blocks in one column)
     */
    int  getColumnPartitionSize();

    /**
     *  get the column partition of the matrix
     *
     *  @return a vector of int corresponding to the partition points
     *  of the columns of this matrix
     */
    int* getColumnPartition();

    /** 
     *  A method to expand an element constructor of a matrix or block
     *  The result is a GeneralSparseMatrix object of constant matrix elements,
     *  variable references, linear or nonlinear expressions, or objective and 
     *  constraint references (possibly mixed). (Values depend on the matrixType.)
     *  Duplicate elements are removed according to the rules formulated in the OSiL schema.
     *  @param rowMajor can be used to store the objects in row major form.
     *  @return whether the operation was successful or not.
     */
    virtual bool expandElements(bool rowMajor);

    /**
     * A method to convert a matrix to the other major. 
     * @param isColumnMajor holds whether the matrix is currently stored by column.
     *        If true, the matrix is converted to row major form.
     *        If false, the matrix is stored by row and is converted to column major.
     * @return A pointer to the matrix in the other major. Return null if input matrix not valid.
     */
    GeneralSparseMatrix* convertToOtherMajor(bool isColumnMajor);

    /**
     *  A method to process a baseMatrix into the form required in the referencing matrixType. 
     *  Processing may include cropping, scaling and transformation of the base matrix elements
     *  and may require that the baseMatrix itself be properly expanded first.
     *
     *  @param rowMajor_ indicates whether the baseMatrix should be stored in row major (if true)
     *         or column major.
     *  @param convertTo_ indicates the form of the value array in the expanded matrix
     *         The default is "unknown", which infers the value type from the content of the matrix 
     *  @param symmetry_ can be used to store only the upper or lower triangle, depending
     *         on the parameter value --- see OSParameters.h for definitions
     *  @return the processed elements of the baseMatrix as a pointer to a GeneralSparseMatrix object.
     */
     virtual GeneralSparseMatrix* 
                    processBaseMatrix(bool rowMajor_, 
                                      ENUM_MATRIX_TYPE convertTo_    = ENUM_MATRIX_TYPE_unknown,
                                      ENUM_MATRIX_SYMMETRY symmetry_ = ENUM_MATRIX_SYMMETRY_default);

    /**
     *  A method to determine the block structure of a matrixType 
     *  as defined by the <blocks> element or elements.
     *  If multiple partitions are found, they are consolidated into the
     *  coarsest partition (intersection of all partition sets).
     *
     *  @return whether the operation was successful
     *
     *  @remark This method sets m_iRowPartition, m_iRowPartitionSize, 
     *          m_iColumnPartition and m_iColumnPartitionSize,
     *          but does not expand any of the blocks themselves.
     */
    bool processBlockPartition();

    /**
     *  A method to expand a blocks constructor into a single matrix of a particular form. 
     *  Processing may require that the blocks themselves be properly expanded first,
     *  and may include applying symmetry, changing the value type and transposing
     *  the elements in some or all of the blocks.
     *
     *  @param currentBlocks is a pointer to the collection of blocks that is to be expanded
     *  @param rowMajor_ indicates whether the expanded matrix should be stored in row major (if true)
     *         or column major.
     *  @param convertTo_ indicates the form of the value array in the expanded matrix
     *         The default is "unknown", which infers the value type from the content of the matrix 
     *  @param symmetry_ can be used to store only the upper or lower triangle, depending
     *         on the parameter value --- see OSParameters.h for definitions
     *  @return the expanded elements of all blocks as a pointer to a GeneralSparseMatrix object.
     */
     virtual GeneralSparseMatrix* 
                expandBlocks( ExpandedMatrixBlocks* currentBlocks, bool rowMajor_,
                                ENUM_MATRIX_TYPE convertTo_    = ENUM_MATRIX_TYPE_unknown,
                                ENUM_MATRIX_SYMMETRY symmetry_ = ENUM_MATRIX_SYMMETRY_default);

    /**
     *  A method to expand a blocks constructor into a single matrix of a particular form. 
     *  Processing may require that the blocks themselves be properly expanded first,
     *  and may include applying symmetry, changing the value type and transposing
     *  the elements in some or all of the blocks.
     *
     *  @param rowMajor_ indicates whether the expanded matrix should be stored in row major (if true)
     *         or column major.
     *  @param convertTo_ indicates the form of the value array in the expanded matrix
     *         The default is "unknown", which infers the value type from the content of the matrix 
     *  @param symmetry_ can be used to store only the upper or lower triangle, depending
     *         on the parameter value --- see OSParameters.h for definitions
     *  @param i indicates the position of the constructor in the array m_mChildren, the child
     *         elements of the current matrix (i.e., the list of constructors)
     *  @return the expanded elements of all blocks as a pointer to a GeneralSparseMatrix object.
     */
     virtual GeneralSparseMatrix* 
                    expandBlocks( int nConst, bool rowMajor_,
                                  ENUM_MATRIX_TYPE convertTo_    = ENUM_MATRIX_TYPE_unknown,
                                  ENUM_MATRIX_SYMMETRY symmetry_ = ENUM_MATRIX_SYMMETRY_default);

    /**
     *  A method to repackage an elements constructor into the form required in the referencing matrixType. 
     *  Processing may include transposing the elements and applying symmetry.
     *
     *  @param nConst gives the number of the constructor within the constructor list
     *         of the parent matrix or block
     *  @param rowMajor indicates whether the baseMatrix should be stored in row major (if true)
     *         or column major.
     *  @param symmetry_ can be used to store only the upper or lower triangle, depending
     *         on the parameter value --- see OSParameters.h for definitions
     *  @return the expanded elements as a pointer to a GeneralSparseMatrix object.
     */
    virtual GeneralSparseMatrix* 
        extractElements(int constructorNo_, bool rowMajor,
                        ENUM_MATRIX_SYMMETRY symmetry_ = ENUM_MATRIX_SYMMETRY_default);
    /**
     *  A method to expand a matrix transformation into the form required in the referencing matrixType. 
     *  Processing may require recursion, transposing the elements, and applying symmetry.
     *
     *  @param rowMajor indicates whether the baseMatrix should be stored in row major (if true)
     *         or column major.
     *  @param symmetry can be used to store only the upper or lower triangle, depending
     *         on the parameter value --- see OSParameters.h for definitions
     *  @return the expanded elements of the transformation as a pointer to a GeneralSparseMatrix object.
     */
    virtual GeneralSparseMatrix* 
        expandTransformation(bool rowMajor,
                             ENUM_MATRIX_SYMMETRY symmetry_ = ENUM_MATRIX_SYMMETRY_default);

    /**
     *  A method to process a matrixType into a block structure defined by 
     *  the <blocks> element or elements.
     *  @param rowMajor_ indicates whether the blocks should be stored in row major (if true)
     *         or column major.
     *  @param convertTo_ is an optional parameter that can be used to covert the elements
     *         of all blocks to a different type 
     *  @param symmetry_ can be used to store only the upper or lower triangle, depending
     *         on the parameter value --- see OSParameters.h for definitions. The default is "none"
     *  @return whether the operation was successful
     *
     *  @remark The blocks are stored into a std::vector of type expandedMatrixBlocks
     *          so that they can be retrieved later using extractBlocks (see below).
     *          It is possible (though probably not advisable) to maintain multiple
     *          decompositions with different row and column partitions (see next method)
     */
     virtual bool processBlocks(bool rowMajor_, 
                                ENUM_MATRIX_TYPE convertTo_ = ENUM_MATRIX_TYPE_unknown,
                                ENUM_MATRIX_SYMMETRY symmetry_ = ENUM_MATRIX_SYMMETRY_default);

    /**
     *  A method to process a matrixType into a specific block structure.
     *  @param rowOffset defines a partition of the matrix rows into the blocks
     *  @param rowOffsetSize gives the number of elements in the rowOffset array 
     *  @param colOffset defines a partition of the matrix columns into the blocks
     *  @param colOffsetSize gives the number of elements in the colOffset array 
     *  @param rowMajor_ controls whether the blocks are stored by row or by column
     *  @param convertTo_ is an optional parameter that can be used to covert the elements
     *         of all blocks to a different type 
     *  @param symmetry_ can be used to store only the upper or lower triangle, depending
     *         on the parameter value --- see OSParameters.h for definitions
     *  @return whether the operation was successful
     *
     *  @remark The blocks are stored into a std::vector of type expandedMatrixBlocks
     *          so that they can be retrieved later using extractBlock (see below).
     *          It is possible (though probably not advisable) to maintain multiple
     *          decompositions with different row and column partitions
     */
     virtual bool processBlocks(int* rowOffset, int rowOffsetSize, int* colOffset,
                                int colOffsetSize, bool rowMajor_,
                                ENUM_MATRIX_TYPE convertTo_ = ENUM_MATRIX_TYPE_unknown,
                                ENUM_MATRIX_SYMMETRY symmetry_ = ENUM_MATRIX_SYMMETRY_default);

    /** 
     *  A method to extract a block from a larger matrix
     *  The result is a sparse matrix object, depending on the matrixType, 
     *  of constant matrix elements, variable references, linear or nonlinear expressions, 
     *  or objective and constraint references (possibly mixed).
     *  Duplicate elements are removed according to the rules formulated in the OSiL schema.
     *  @param firstrow gives the first row of the block
     *  @param firstcol gives the first column of the block
     *  @param lastrow gives the last row of the block  
     *  @param lastcol gives the last column of the block  
     *  @param rowMajor_ can be used to store the objects in row major form.
     *  @param symmetry_ can be used to store only the upper or lower triangle, depending
     *         on the parameter value --- see OSParameters.h for definitions
     *  @return the block as a general sparse matrix
     *  @remark Before extracting a block it is necessary to call processBlocks()
     *          in order to make sure that a block partition conformal to the
     *          block dimensions and positions has been defined or prepared.
     */
    GeneralSparseMatrix* extractBlock(int firstrow, int firstcol, int lastrow, int lastcol,
                                      bool rowMajor_, 
                                      ENUM_MATRIX_SYMMETRY symmetry_ = ENUM_MATRIX_SYMMETRY_default);

    /** 
     *  A method to retrieve the blocks from a particular collection.
     *  The result is an object of general sparse matrices, depending on the matrixType, 
     *  of constant matrix elements, variable references, linear or nonlinear expressions, 
     *  or objective and constraint references (possibly mixed).
     *  @param rowPartition defines the partition of the set of rows into the blocks  
     *  @param rowPartitionSize gives the size of the rowPartition array
     *  @param colPartition defines the partition of the set of columns into the blocks  
     *  @param colPartitionSize gives the size of the colPartition array
     *  @param appendToBlockArray determines whether the blocks should be created if not found. 
     *  @param rowMajor indicates whether the blocks are stored in row major form or not.
     *  @param convertTo_ is an optional parameter that can be used to covert the elements
     *         of all blocks to a different type. 
     *  @param symmetry_ can be used to store only the upper or lower triangle, depending
     *         on the parameter value --- see OSParameters.h for definitions
     *
     *  @return the blocks as an ExpandedMatrixBlocks object, which is essentially 
     *          an array of general sparse matrices. 
     *
     *  @remark If blocks corresponding to the indicated partition do not exist,
     *          this method can try to create them. This can be quite storage-intensive
     *          and is controlled by the parameter appendToBlockArray. If no blocks
     *          found (and appending is inhibited) return NULL.
     */
    ExpandedMatrixBlocks* getBlocks(int* rowPartition, int rowPartitionSize, 
                                    int* colPartition, int colPartitionSize, 
                                    bool appendToBlockArray, bool rowMajor, 
                                    ENUM_MATRIX_TYPE convertTo_ = ENUM_MATRIX_TYPE_unknown,
                                    ENUM_MATRIX_SYMMETRY symmetry_ = ENUM_MATRIX_SYMMETRY_default);

    /** 
     *  A method to retrieve the blocks from a particular <blocks> constructor.
     *  The result is an object of general sparse matrices, depending on the matrixType, 
     *  of constant matrix elements, variable references, linear or nonlinear expressions, 
     *  or objective and constraint references (possibly mixed).
     *  @param i is the number of the <blocks> constructor in the array of matrix constructors.
     *  @param appendToBlockArray determines whether the blocks should be created if not found. 
     *  @param rowMajor indicates whether the blocks are stored in row major form or not.
     *  @param convertTo_ is an optional parameter that can be used to covert the elements
     *         of all blocks to a different type. 
     *  @param symmetry_ can be used to store only the upper or lower triangle, depending
     *         on the parameter value --- see OSParameters.h for definitions
     *
     *  @return the blocks as an ExpandedMatrixBlocks object, which is essentially 
     *          an array of general sparse matrices. 
     *
     *  @remark If blocks corresponding to the indicated partition do not exist,
     *          this method can try to create them. This can be quite storage-intensive
     *          and is controlled by the parameter appendToBlockArray. If no blocks
     *          found (and appending is inhibited) return NULL.
     */
    //ExpandedMatrixBlocks* getBlocks(int i, bool appendToBlockArray, bool rowMajor, 
    //                                ENUM_MATRIX_TYPE convertTo_ = ENUM_MATRIX_TYPE_unknown,
    //                                ENUM_MATRIX_SYMMETRY symmetry_ = ENUM_MATRIX_SYMMETRY_default);

    /** 
     *  A method to disassemble a MatrixType into individual blocks of specific structure
     *  @param rowPartition defines the partition of the set of rows into the blocks  
     *  @param rowPartitionSize gives the size of the rowPartition array
     *  @param colPartition defines the partition of the set of columns into the blocks  
     *  @param colPartitionSize gives the size of the colPartition array
     *  @param rowMajor_ indicates whether the blocks are stored in row major form or not.
     *  @param valueType_ indicates in which form to store the disassembled matrix
     *         The default for this optional parameter is ENUM_MATRIX_TYPE_unknown
     *  @param symmetry_ determines what kind of symmetry to use in representing the blocks.
     *         If this parameter is missing, the default value is NO symmetry
     *
     *  @return the blocks as an ExpandedMatrixBlocks object, which is essentially 
     *          an array of general sparse matrices. 
     */
    ExpandedMatrixBlocks* disassembleMatrix(int* rowPartition, int rowPartitionSize, 
                                    int* colPartition, int colPartitionSize, bool rowMajor_, 
                                    ENUM_MATRIX_TYPE valueType_    = ENUM_MATRIX_TYPE_unknown,
                                    ENUM_MATRIX_SYMMETRY symmetry_ = ENUM_MATRIX_SYMMETRY_default);

    /**
     *  A function to check for the equality of two objects
     */
    bool IsEqual(MatrixType *that);

    /**
     * A function to make a random instance of this class
     * @param density: corresponds to the probability that a particular child element is created
     * @param conformant: if true enforces side constraints not enforceable in the schema
     *                    (e.g., agreement of "numberOfXXX" attributes and <XXX> children)
     *                    if false, then side constraints are not enforced,
     *                    which can be useful for parser stress and compliance tests 
     * @param iMin: lowest index value (inclusive) that a variable reference in this matrix can take
     * @param iMax: greatest index value (inclusive) that a variable reference in this matrix can take
     */
    bool setRandom(double density, bool conformant, int iMin, int iMax);

    /**
     * A function to make a deep copy of an instance of this class
     *
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
    int idx;
    std::string name;

public:
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

#if 0
    /**
     *  @return the declared type of the matrix elements
     */
    virtual ENUM_MATRIX_TYPE getDeclaredMatrixType();

    /**
     *  @return the inferred type of the matrix elements
     */
    virtual ENUM_MATRIX_TYPE getInferredMatrixType();

    /**
     *  @return the amalgamated type of the matrix elements
     */
    virtual ENUM_MATRIX_TYPE getMatrixType();
#endif

    /**
     *  A method to process a matrixType into a specific block structure.
     *  @param rowOffset defines a partition of the matrix rows into the blocks
     *  @param colOffset defines a partition of the matrix columns into the blocks
     *  @param rowMajor controls whether the blocks are stored by row or by column
     *  @param symmetry can be used to store only the upper or lower triangle, depending
     *         on the parameter value --- see OSParameters.h for definitions
     *  @return whether the operation was successful
     *
     *  @remark The blocks are stored into a std::vector of type expandedMatrixBlocks
     *          so that they can be retrieved later using extractBlock (see below).
     *          It is possible (though probably not advisable) to maintain multiple
     *          decompositions with different row and column partitions
     */
     //virtual bool processBlocks(int* rowOffset, int* colOffset,
     //                                 bool rowMajor, ENUM_MATRIX_SYMMETRY symmetry);

    /** 
     *  A method to expand a matrix or block
     *  The result is a GeneralSparseMatrix object of constant matrix elements,
     *  variable references, linear or nonlinear expressions, or objective and 
     *  constraint references (possibly mixed). (Values depend on the matrixType.)
     *  Duplicate elements are removed according to the rules formulated in the OSiL schema.
     *  @param rowMajor can be used to store the objects in row major form.
     *  @return whether the operation was successful or not.
     */
    virtual bool expandElements(bool rowMajor);

    /** 
     *  Check whether a submatrix aligns with the block partition of a matrix
     *  or block or other constructor
     *  @param firstRow gives the number of the first row in the submatrix (zero-based)
     *  @param firstColumn gives the number of the first column in the submatrix (zero-based)
     *  @param nRows gives the number of rows in the submatrix
     *  @param nColumns gives the number of columns in the submatrix
     *  @return true if the submatrix aligns with the boundaries of a block
     */
    virtual bool alignsOnBlockBoundary(int firstRow, int firstColumn, int nRows, int nCols) ;

    /**
     *  A method to check whether a matrix is block-diagonal
     */
    bool isBlockDiagonal();

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
     * @param declaredMatrixType tracks the type of elements contained in this matrix.
     *        For more information  see the enumeration ENUM_MATRIX_TYPE in OSGeneral.h.
     *        If unsure, use ENUM_MATRIX_TYPE_unknown.
     * @param inumberOfChildren is the number of MatrixNode child elements,
     *        i.e., the number of matrix constructors in the m_mChildren array. 
     * @param m_mChildren is the array of matrix constructors used in the definition of this matrix.
     * @return whether the matrix was added successfully.
     */
    bool setMatrix(std::string name, int numberOfRows, int numberOfColumns, 
                         ENUM_MATRIX_SYMMETRY symmetry, ENUM_MATRIX_TYPE declaredMatrixType, 
                         ENUM_MATRIX_TYPE inferredMatrixType, unsigned int inumberOfChildren, 
                         MatrixNode **m_mChildren);
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


/*! \class OSMatrixWithMatrixVarIdx : OSMatrix
 * \brief this class extends OSMatrix for use, e.g., in the matrixVar section of OSoL and OSrL
 *
 */
class OSMatrixWithMatrixVarIdx : public OSMatrix
{
public:
    int matrixVarIdx;

public:
    OSMatrixWithMatrixVarIdx();
    ~OSMatrixWithMatrixVarIdx();

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
    virtual OSMatrixWithMatrixVarIdx *cloneMatrixNode();

    /**
     *
     * A function to check for the equality of two objects
     */
    bool IsEqual(OSMatrixWithMatrixVarIdx *that);

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
    bool deepCopyFrom(OSMatrixWithMatrixVarIdx *that);
};// class OSMatrixWithMatrixVarIdx


/*! \class OSMatrixWithMatrixObjIdx : OSMatrix
 * \brief this class extends OSMatrix for use, e.g., in the matrixObj section of OSoL and OSrL
 *
 */
class OSMatrixWithMatrixObjIdx : public OSMatrix
{
public:
    int matrixObjIdx;

public:
    OSMatrixWithMatrixObjIdx();
    ~OSMatrixWithMatrixObjIdx();

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
    virtual OSMatrixWithMatrixObjIdx *cloneMatrixNode();

    /**
     *
     * A function to check for the equality of two objects
     */
    bool IsEqual(OSMatrixWithMatrixObjIdx *that);

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
    bool deepCopyFrom(OSMatrixWithMatrixObjIdx *that);
};// class OSMatrixWithMatrixObjIdx

/*! \class OSMatrixWithMatrixConIdx : OSMatrix
 * \brief this class extends OSMatrix for use, e.g., in the matrixCon section of OSoL and OSrL
 *
 */
class OSMatrixWithMatrixConIdx : public OSMatrix
{
public:
    int matrixConIdx;

public:
    OSMatrixWithMatrixConIdx();
    ~OSMatrixWithMatrixConIdx();

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
    virtual OSMatrixWithMatrixConIdx *cloneMatrixNode();

    /**
     *
     * A function to check for the equality of two objects
     */
    bool IsEqual(OSMatrixWithMatrixConIdx *that);

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
    bool deepCopyFrom(OSMatrixWithMatrixConIdx *that);
};// class OSMatrixWithMatrixConIdx


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

#if 0
    /**
     *  @return the declared type of the matrix elements
     */
    virtual ENUM_MATRIX_TYPE getDeclaredMatrixType();

    /**
     *  @return the inferred type of the matrix elements
     */
    virtual ENUM_MATRIX_TYPE getInferredMatrixType();

    /**
     *  @return the amalgamated type of the matrix elements
     */
    virtual ENUM_MATRIX_TYPE getMatrixType();
#endif

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
     *  Check whether a submatrix aligns with the block partition of a matrix
     *  or block or other constructor
     *  @param firstRow gives the number of the first row in the submatrix (zero-based)
     *  @param firstColumn gives the number of the first column in the submatrix (zero-based)
     *  @param nRows gives the number of rows in the submatrix
     *  @param nColumns gives the number of columns in the submatrix
     *  @return true if the submatrix aligns with the boundaries of a block
     */
    virtual bool alignsOnBlockBoundary(int firstRow, int firstColumn, int nRows, int nCols);

    /** 
     *  A method to expand a matrix or block
     *  The result is a GeneralSparseMatrix object of constant matrix elements,
     *  variable references, linear or nonlinear expressions, or objective and 
     *  constraint references (possibly mixed). (Values depend on the matrixType.)
     *  Duplicate elements are removed according to the rules formulated in the OSiL schema.
     *  @param rowMajor can be used to store the objects in row major form.
     *  @return whether the operation was successful or not.
     */
    virtual bool expandElements(bool rowMajor);

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



/**
 *  Some methods to convert one type of matrix element into another
 */
LinearMatrixElement* convertToLinearMatrixElement(double val);
LinearMatrixElement* convertToLinearMatrixElement(int varref);
RealValuedExpressionTree* convertToRealExpressionTree(double val);
RealValuedExpressionTree* convertToRealExpressionTree(int idx, bool varref); // use for varRef and objRef
RealValuedExpressionTree* convertToRealExpressionTree(LinearMatrixElement* val);
RealValuedExpressionTree* convertToRealExpressionTree(ConReferenceMatrixElement* val);
ConReferenceMatrixElement* convertToConReferenceMatrixElement(int objRef);
std::complex<double> convertToComplexMatrixElement(double val);
ComplexValuedExpressionTree* convertToComplexExpressionTree(double val);
ComplexValuedExpressionTree* convertToComplexExpressionTree(int idx, bool varref); // for varRef and objRef
ComplexValuedExpressionTree* convertToComplexExpressionTree(LinearMatrixElement* val);
ComplexValuedExpressionTree* convertToComplexExpressionTree(ConReferenceMatrixElement* val);
ComplexValuedExpressionTree* convertToComplexExpressionTree(std::complex<double> val);
ComplexValuedExpressionTree* convertToComplexExpressionTree(RealValuedExpressionTree* val);
std::string convertToString(double val);
std::string convertToString(int idx, bool varref); // use for varRef and objRef
std::string convertToString(LinearMatrixElement* val);
std::string convertToString(ConReferenceMatrixElement* val);
std::string convertToString(std::complex<double> val);
std::string convertToString(RealValuedExpressionTree* val);
std::string convertToString(ComplexValuedExpressionTree* val);

/** other potential conversions: (do not implement for now)
 *      string to constant
 *      linear to varref
 *      linear to constant
 *      real expression to constant
 *      real expression to linear
 *      real expression to varref
 *      complex constant to real constant
 *      complex expression to complex constant
 **/


    /**
     *  Some methods to convert one type of matrix elements into another
     *  @param _values is the array  of matrix elements that are to be converted
     *  @param nvalues is the number of matrix elements that are to be converted
     *  @return true if the conversion was successful
     */
    bool convertFromConstant(ConstantMatrixValues*   _values, int nvalues);
    bool convertFromVarRef(VarReferenceMatrixValues* _values, int nvalues);
    /**
     *  Some methods to convert one type of matrix elements into another
     *  @param _values is the array  of matrix elements that are to be converted
     *  @param nvalues is the number of matrix elements that are to be converted
     *  @return true if the conversion was successful
     */
//    bool convertFromConstant(ConstantMatrixValues*     _values, int nvalues);
//    bool convertFromVarRef  (VarReferenceMatrixValues* _values, int nvalues);
//    bool convertFromObjRef  (ObjReferenceMatrixValues* _values, int nvalues);
//    bool convertFromLinear  (LinearMatrixValues*       _values, int nvalues);
//    bool convertFromConRef  (ConReferenceMatrixValues* _values, int nvalues);
//    bool convertFromGeneral (RealValuedExpressionArray*      _values, int nvalues);
#endif
