/* $Id: OSMatrix.h 3172 2010-02-05 04:59:24Z Gassmann $ */
/** @file OSMatrix.h
 *
 * @author  Horand Gassmann, Jun Ma, Kipp Martin
 *
 * \remarks
 * Copyright (C) 2010-2014, Horand Gassmann, Jun Ma, Kipp Martin,
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
 *  To facilitate parsing of complicated matrix constructors and the recursion
 *  implicit in the block structure, we distinguish the following six types:
 *  1 - BaseMatrix
 *  2 - Elements   
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
 * \brief a data structure to represent the linear expressions in a LinearMatrixElement object
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

#if 0
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
#endif

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
     *  Each term in this sum is stored as a separate LinearMatrixValues object
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


#endif
