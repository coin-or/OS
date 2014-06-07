/* $Id$ */
/** @file OSnLNode.h
 * \brief This file defines the OSnLNode class along with its derived classes.
 *
 * @author  Robert Fourer, Horand Gassmann, Jun Ma, Kipp Martin,
 *
 * \remarks
 * Copyright (C) 2005-2011, Robert Fourer, Horand Gassmann, Jun Ma, Kipp Martin,
 * Northwestern University, and the University of Chicago.
 * All Rights Reserved.
 * This software is licensed under the Eclipse Public License.
 * Please see the accompanying LICENSE file in root directory for terms.
 *
 */

#ifndef OSNLNODE_H
#define OSNLNODE_H

#include "OSConfig.h"
#include "OSErrorClass.h"
#include <iostream>
#include <vector>
#include <map>


#ifdef OS_HAS_CPPAD
# include <cppad/cppad.hpp>
typedef CppAD::AD<double>  ADdouble;
typedef CppAD::vector<ADdouble> ADvector;
#else
typedef double  ADdouble;
typedef std::vector<ADdouble> ADvector;
#endif



/*! \class OSnLNode OSnLNode.h "OSnLNode.h"
 *  \brief The OSnLNode Class.
 *
 * @author  Horand Gassmann, Jun Ma, Kipp Martin,
 * @version 1.0, 10/05/2005
 * @since   OS1.0
 *
 * \remarks
 * in this file we define an OSnL node for a subset of the nodes
 * defined in the OSnL schema
 *
 */

class OSnLNode
{
public:

    /**  inumberOfChildren is the number of OSnLNode child elements
     *   if this number is not fixed, e.g., for a sum node, it is temporarily set to 0
     */
    unsigned int inumberOfChildren;

    /**  inodeInt is the unique integer assigned to the OSnLNode*/
    int inodeInt;

    /** inodeType essentially tracks whether the number of children are known or not
     *  most nodes have a known number of children, then inodeType is set to inumberOfChildren
     *  for some nodes the number of children is not known a priori, e.g., a sum node
     *  then inodeType is set to -1
     */
    int inodeType;

    /**
     * m_mChildren holds all the operands, that is, nodes that the current node operates on.
     */
    OSnLNode **m_mChildren;

    /**
     * m_dFunctionValue holds the function value given the current variable values.
     */
    double m_dFunctionValue;

    /**
     * m_ADTape stores the expression tree for the this OSnLNode as an ADdouble.
     */
    ADdouble m_ADTape;

    /**
     * @return the value of inodeInt
     */
    virtual std::string getTokenNumber();

    /**
     * @return the value of operator name
     */
    virtual std::string getTokenName() = 0;

    /**
     * <p>
     * the following method writes an OSnLNode in
     * OSiL format, it is used by OSiLWriter to take
     * an OSInstance and write the corresponding OSiL
     * </p>
     *
     * @return the OSnLNode and its children as an OSiL string.
     */
    virtual  std::string getNonlinearExpressionInXML();

    /**
     * <p>
     * Take a vector of OSnLNodes in postfix format 
     * and create an OSExpressionTree root node
     * </p>
     * @param nlNodeVec holds a vector of pointers to OSnLNodes
     * in postfix format
     * @return a pointer to an OSnLNode which is the root of
     * an OSExpressionTree.
     */
    OSnLNode* createExpressionTreeFromPostfix(std::vector<OSnLNode*> nlNodeVec);


    /**
     * <p>
     * Take a vector of OSnLNodes in prefix format
     * and create an OSExpressionTree root node
     * </p>
     * @param nlNodeVec holds a vector of pointers to OSnLNodes
     * in prefix format
     * @return a pointer to an OSnLNode which is the root of
     * an OSExpressionTree.
     */
    OSnLNode* createExpressionTreeFromPrefix(std::vector<OSnLNode*> nlNodeVec);

    /**
     * <p>
     * Get a vector of pointers to OSnLNodes that correspond to
     * the OSExpressionTree in prefix format
     * </p>
     *
     * @return the expression tree as a vector of OSnLNodes in prefix.
     */
    std::vector<OSnLNode*> getPrefixFromExpressionTree();

    /**
     * <p>
     * Called by getPrefixFromExpressionTree().  This method calls
     * itself recursively and
     * generates a vector of pointers to OSnLNodes in prefix
     * </p>
     * @param a pointer prefixVector to a vector of pointers of OSnLNodes
     * @return a vector of pointers to OSnLNodes in prefix.
     */
    std::vector<OSnLNode*> preOrderOSnLNodeTraversal( std::vector<OSnLNode*> *prefixVector);

    /**
     * <p>
     * Get a vector of pointers to OSnLNodes that correspond to
     * the OSExpressionTree in postfix format
     * </p>
     *
     * @return the expression tree as a vector of OSnLNodes in postfix.
     */
    std::vector<OSnLNode*> getPostfixFromExpressionTree();

    /**
     * <p>
     * Called by getPostfixFromExpressionTree().  This method calls
     * itself recursively and
     * generates a vector of pointers to OSnLNodes in postfix
     * </p>
     * @param a pointer postfixVector to a vector of pointers of OSnLNodes
     * @return a vector of pointers to OSnLNodes in postfix.
     */
    std::vector<OSnLNode*> postOrderOSnLNodeTraversal( std::vector<OSnLNode*> *postfixVector);

    /**
     * <p>
     * varIdx is a map where the key is the index of an OSnLNodeVariable and
     * (*varIdx)[ idx] is the kth variable in the map, e.g.
     * (*varIdx)[ 5] = 2 means that variable indexed by 5 is the second variable
     * in the OSnLNode and all of its children
     * </p>
     * @param a pointer to a map of the variables in the OSnLNode and its children
     */
    virtual void getVariableIndexMap(std::map<int, int> *varIdx);


    /**
     * <p>
     * Calculate the function value given the current variable values.
     * This is an abstract method which is required to be implemented by the concrete
     * operator nodes that derive or extend from this OSnLNode class.
     * </p>
     *
     * @param x holds the values of the variables in a double array.
     * @return the function value given the current variable values.
     */
    virtual double calculateFunction(double *x) = 0;


    /**
     * <p>
     * Create the AD tape to be evaluated by AD.
     * This is an abstract method which is required to be implemented by the concrete
     * operator nodes that derive or extend from this OSnLNode class.
     * </p>
     *
     * @return the expression tree.
     */
    virtual ADdouble constructADTape(std::map<int, int> *ADIdx, ADvector *XAD) = 0;

	/**
	 *
	 * make a copy of this node and all its descendants
	 * @return a pointer to the duplicate node
	 */
	OSnLNode* copyNodeAndDescendants();

    /**
     * <p>
     * Create or clone a node of this type.
     * This is an abstract method which is required to be implemented by the concrete
     * operator nodes that derive or extend from this OSnLNode class.
     * </p>
     *
     * @param x holds the values of the variables in a double array.
     * @return the function value given the current variable values.
     */
    virtual OSnLNode *cloneOSnLNode() = 0;

    /**
     * default constructor.
     */
    OSnLNode();

    /**
     * default destructor.
     */
    virtual ~OSnLNode();

    /**
     * A function to check for the equality of two objects
     */
    bool IsEqual(OSnLNode *that);
};//end OSnLNode

/*! \class OSnLNodePlus
 *  \brief The OSnLNodePlus Class.
 *
 * @author  Robert Fourer, Jun Ma, Kipp Martin,
 * @version 1.0, 10/05/2005
 * @since   OS1.0
 *
 * \remarks
 * The in-memory representation of the OSnL element <plus>
 *
 */
class OSnLNodePlus : public OSnLNode
{
public:
    /**
     * default constructor.
     */
    OSnLNodePlus();

    /**
     * default destructor.
     */
    ~OSnLNodePlus();

    /**
     *
     * @return the value of operator name
     */
    virtual std::string getTokenName();

    /*! \fn double OSnLNodePlus::calculateFunction(double *x)
     *  \brief The implementation of the virtual functions.
     *  \return a double.
     */
    virtual double calculateFunction( double *x);

    /*! \fn double OSnLNodePlus::constructADTape(std::map<int, int> *ADIdx, vector< ADdouble > *XAD)
     *  \brief The implementation of the virtual functions.
     *  \return a ADdouble.
     */
    virtual ADdouble constructADTape(std::map<int, int> *ADIdx, ADvector *XAD) ;

    /*! \fn OSnLNode *cloneOSnLNode(double *x)
     *  \brief The implementation of the virtual functions.
     *  \return a point to a new OSnLNode of the proper type.
     */

    virtual OSnLNode *cloneOSnLNode() ;

};//end OSnLNodePlus

/*! \class OSnLNodeSum
 *  \brief The OSnLNodeSum Class.
 *
 * @author  Robert Fourer, Jun Ma, Kipp Martin,
 * @version 1.0, 10/05/2005
 * @since   OS1.0
 *
 * \remarks
 * The in-memory representation of the OSnL element <sum>
 *
 */
class OSnLNodeSum : public OSnLNode
{
public:
    /**
     * default constructor.
     */
    OSnLNodeSum();

    /**
     * default destructor.
     */
    ~OSnLNodeSum();

    /**
     *
     * @return the value of operator name
     */
    virtual std::string getTokenName();

    /*! \fn double OSnLNodeSum::double(double *x)
     *  \brief The implementation of the virtual functions.
     *  \return a double.
     */
    virtual double calculateFunction( double *x);

    /*! \fn OSnLNode *cloneOSnLNode(double *x)
     *  \brief The implementation of the virtual functions.
     *  \return a point to a new OSnLNode of the proper type.
     */
    virtual OSnLNode *cloneOSnLNode() ;

    /*! \fn double OSnLNodeSum::constructADTape(std::map<int, int> *ADIdx, vector< ADdouble > *XAD)
     *  \brief The implementation of the virtual functions.
     *  \return a ADdouble.
     */
    virtual ADdouble constructADTape(std::map<int, int> *ADIdx, ADvector *XAD) ;
};//end OSnLNodeSum

/*! \class OSnLNodeMax
 *  \brief The OSnLNodeMax Class.
 *
 * @author  Robert Fourer, Jun Ma, Kipp Martin,
 * @version 1.0, 10/05/2005
 * @since   OS1.0
 *
 * \remarks
 * The in-memory representation of the OSnL element <max>
 *
 */
class OSnLNodeMax : public OSnLNode
{
public:
    /**
     * default constructor.
     */
    OSnLNodeMax();

    /**
     * default destructor.
     */
    ~OSnLNodeMax();

    /**
     *
     * @return the value of operator name
     */
    virtual std::string getTokenName();

    /*! \fn double OSnLNodeMax::double(double *x)
     *  \brief The implementation of the virtual functions.
     *  \return a double.
     */
    virtual double calculateFunction( double *x);

    /*! \fn OSnLNode *cloneOSnLNode(double *x)
     *  \brief The implementation of the virtual functions.
     *  \return a point to a new OSnLNode of the proper type.
     */
    virtual OSnLNode *cloneOSnLNode() ;

    /*! \fn double OSnLNodeMax::constructADTape(std::map<int, int> *ADIdx, vector< ADdouble > *XAD)
     *  \brief The implementation of the virtual functions.
     *  \return a ADdouble.
     */
    virtual ADdouble constructADTape(std::map<int, int> *ADIdx, ADvector *XAD);
};//end OSnLNodeMax

/*! \class OSnLNodeMin
 *  \brief The OSnLNodeMin Class.
 *
 * @author  Robert Fourer, Jun Ma, Kipp Martin,
 * @version 1.0, 10/05/2005
 * @since   OS1.0
 *
 * \remarks
 * The in-memory representation of the OSnL element <min>
 *
 */
class OSnLNodeMin : public OSnLNode
{
public:
    /**
     * default constructor.
     */
    OSnLNodeMin();

    /**
     * default destructor.
     */
    ~OSnLNodeMin();

    /**
     *
     * @return the value of operator name
     */
    virtual std::string getTokenName();

    /*! \fn double OSnLNodeMin::double(double *x)
     *  \brief The implementation of the virtual functions.
     *  \return a double.
     */
    virtual double calculateFunction( double *x);

    /*! \fn OSnLNode *cloneOSnLNode(double *x)
     *  \brief The implementation of the virtual functions.
     *  \return a point to a new OSnLNode of the proper type.
     */
    virtual OSnLNode *cloneOSnLNode() ;

    /*! \fn double OSnLNodeMin::constructADTape(std::map<int, int> *ADIdx, vector< ADdouble > *XAD)
     *  \brief The implementation of the virtual functions.
     *  \return a ADdouble.
     */
    virtual ADdouble constructADTape(std::map<int, int> *ADIdx, ADvector *XAD) ;

};//end OSnLNodeMin


/*! \class OSnLNodeMinus
 *  \brief The OSnLNodeMinus Class.
 *
 * @author  Robert Fourer, Jun Ma, Kipp Martin,
 * @version 1.0, 10/05/2005
 * @since   OS1.0
 *
 * \remarks
 * The in-memory representation of the OSnL element <minus>
 *
 */
class OSnLNodeMinus : public OSnLNode
{
public:
    /**
     * default constructor.
     */
    OSnLNodeMinus();

    /**
     * default destructor.
     */
    ~OSnLNodeMinus();


    /**
     *
     * @return the value of operator name
     */
    virtual std::string getTokenName();

    /*! \fn double OSnLNodeMinus::double(double *x)
     *  \brief The implementation of the virtual functions.
     *  \return a double.
     */
    virtual double calculateFunction( double *x);

    /*! \fn OSnLNode *cloneOSnLNode(double *x)
     *  \brief The implementation of the virtual functions.
     *  \return a point to a new OSnLNode of the proper type.
     */
    virtual OSnLNode *cloneOSnLNode() ;

    /*! \fn double OSnLNodeMinus::constructADTape(std::map<int, int> *ADIdx, vector< ADdouble > *XAD)
     *  \brief The implementation of the virtual functions.
     *  \return a ADdouble.
     */
    virtual ADdouble constructADTape(std::map<int, int> *ADIdx, ADvector *XAD) ;

};//end OSnLNodeMinus

/*! \class OSnLNodeNegate
 *  \brief The OSnLNodeNegate Class.
 *
 * @author  Robert Fourer, Jun Ma, Kipp Martin,
 * @version 1.0, 10/05/2005
 * @since   OS1.0
 *
 * \remarks
 * The in-memory representation of the OSnL element <negate>
 *
 */
class OSnLNodeNegate : public OSnLNode
{
public:
    /**
     * default constructor.
     */
    OSnLNodeNegate();

    /**
     * default destructor.
     */
    ~OSnLNodeNegate();

    /**
     *
     * @return the value of operator name
     */
    virtual std::string getTokenName();

    /*! \fn double OSnLNodeNegate::double(double *x)
     *  \brief The implementation of the virtual functions.
     *  \return a double.
     */
    virtual double calculateFunction( double *x);

    /*! \fn OSnLNode *cloneOSnLNode(double *x)
     *  \brief The implementation of the virtual functions.
     *  \return a point to a new OSnLNode of the proper type.
     */
    virtual OSnLNode *cloneOSnLNode() ;


    /*! \fn double OSnLNodeNegate::constructADTape(std::map<int, int> *ADIdx, vector< ADdouble > *XAD)
     *  \brief The implementation of the virtual functions.
     *  \return a ADdouble.
     */
    virtual ADdouble constructADTape(std::map<int, int> *ADIdx, ADvector *XAD) ;
};//end OSnLNodeNegate


/*! \class OSnLNodeTimes
 *  \brief The OSnLNodeTimes Class.
 *
 * @author  Robert Fourer, Jun Ma, Kipp Martin,
 * @version 1.0, 10/05/2005
 * @since   OS1.0
 *
 * \remarks
 * The in-memory representation of the OSnL element <times>
 *
 */
class OSnLNodeTimes : public OSnLNode
{
public:
    /**
     * default constructor.
     */
    OSnLNodeTimes();

    /**
     * default destructor.
     */
    ~OSnLNodeTimes();

    /**
     *
     * @return the value of operator name
     */
    virtual std::string getTokenName();

    /*! \fn double OSnLNodeTimes::double(double *x)
     *  \brief The implementation of the virtual functions.
     *  \return a double.
     */
    virtual double calculateFunction( double *x);

    /*! \fn OSnLNode *cloneOSnLNode(double *x)
     *  \brief The implementation of the virtual functions.
     *  \return a point to a new OSnLNode of the proper type.
     */
    virtual OSnLNode *cloneOSnLNode() ;

    /*! \fn double OSnLNodeNegate::constructADTape(std::map<int, int> *ADIdx, vector< ADdouble > *XAD)
     *  \brief The implementation of the virtual functions.
     *  \return a ADdouble.
     */
    virtual ADdouble constructADTape(std::map<int, int> *ADIdx, ADvector *XAD) ;

};//end OSnLNodeTimes


/*! \class OSnLNodeDivide
 *  \brief The OSnLNodeDivide Class.
 *
 * @author  Robert Fourer, Jun Ma, Kipp Martin,
 * @version 1.0, 10/05/2005
 * @since   OS1.0
 *
 * \remarks
 * The in-memory representation of the OSnL element <divide>
 *
 */
class OSnLNodeDivide : public OSnLNode
{
public:
    /**
     * default constructor.
     */
    OSnLNodeDivide();

    /**
     * default destructor.
     */
    ~OSnLNodeDivide();


    /**
     *
     * @return the value of operator name
     */
    virtual std::string getTokenName();

    /*! \fn double OSnLNodeDivide::double(double *x)
     *  \brief The implementation of the virtual functions.
     *  \return a double.
     */
    virtual double calculateFunction( double *x);

    /*! \fn OSnLNode *cloneOSnLNode(double *x)
     *  \brief The implementation of the virtual functions.
     *  \return a point to a new OSnLNode of the proper type.
     */
    virtual OSnLNode *cloneOSnLNode() ;

    /*! \fn double OSnLNodeDivide::constructADTape(std::map<int, int> *ADIdx, vector< ADdouble > *XAD)
     *  \brief The implementation of the virtual functions.
     *  \return a ADdouble.
     */
    virtual ADdouble constructADTape(std::map<int, int> *ADIdx, ADvector *XAD);
};//end OSnLNodeDivide

/*! \class OSnLNodePower
 *  \brief The OSnLNodePower Class.
 *
 * @author  Robert Fourer, Jun Ma, Kipp Martin,
 * @version 1.0, 10/05/2005
 * @since   OS1.0
 *
 * \remarks
 * The in-memory representation of the OSnL element <power>
 *
 */
class OSnLNodePower : public OSnLNode
{
public:
    /**
     * default constructor.
     */
    OSnLNodePower();

    /**
     * default destructor.
     */
    ~OSnLNodePower();

    /**
     *
     * @return the value of operator name
     */
    virtual std::string getTokenName();

    /*! \fn double OSnLNodePower::double(double *x)
     *  \brief The implementation of the virtual functions.
     *  \return a double.
     */
    virtual double calculateFunction( double *x);

    /*! \fn OSnLNode *cloneOSnLNode(double *x)
     *  \brief The implementation of the virtual functions.
     *  \return a point to a new OSnLNode of the proper type.
     */
    virtual OSnLNode *cloneOSnLNode() ;

    /*! \fn double OSnLNodePower::constructADTape(std::map<int, int> *ADIdx, vector< ADdouble > *XAD)
     *  \brief The implementation of the virtual functions.
     *  \return a ADdouble.
     */
    virtual ADdouble constructADTape(std::map<int, int> *ADIdx, ADvector *XAD);

};//end OSnLNodePower

/*! \class OSnLNodeProduct
 *  \brief The OSnLNodeProduct Class.
 *
 * @author  Robert Fourer, Jun Ma, Kipp Martin,
 * @version 1.0, 10/05/2005
 * @since   OS1.0
 *
 * \remarks
 * The in-memory representation of the OSnL element <product>
 *
 */
class OSnLNodeProduct : public OSnLNode
{
public:
    /**
     * default constructor.
     */
    OSnLNodeProduct();

    /**
     * default destructor.
     */
    ~OSnLNodeProduct();

    /**
     *
     * @return the value of operator name
     */
    virtual std::string getTokenName();

    /*! \fn double OSnLNodeProduct::double(double *x)
     *  \brief The implementation of the virtual functions.
     *  \return a double.
     */
    virtual double calculateFunction( double *x);

    /*! \fn OSnLNode *cloneOSnLNode(double *x)
     *  \brief The implementation of the virtual functions.
     *  \return a point to a new OSnLNode of the proper type.
     */
    virtual OSnLNode *cloneOSnLNode() ;

    /*! \fn double OSnLNodeProduct::constructADTape(std::map<int, int> *ADIdx, vector< ADdouble > *XAD)
     *  \brief The implementation of the virtual functions.
     *  \return a ADdouble.
     */
    virtual ADdouble constructADTape(std::map<int, int> *ADIdx, ADvector *XAD);

};//end OSnLNodeProduct


/*! \class OSnLNodeLn
 *  \brief The OSnLNodeLn Class.
 *
 * @author  Robert Fourer, Jun Ma, Kipp Martin,
 * @version 1.0, 10/05/2005
 * @since   OS1.0
 *
 * \remarks
 * The in-memory representation of the OSnL element <ln>
 *
 */
class OSnLNodeLn : public OSnLNode
{
public:
    /**
     * default constructor.
     */
    OSnLNodeLn();

    /**
     * default destructor.
     */
    ~OSnLNodeLn();

    /**
     *
     * @return the value of operator name
     */
    virtual std::string getTokenName();

    /*! \fn double OSnLNodeLn::double(double *x)
     *  \brief The implementation of the virtual functions.
     *  \return a double.
     */
    virtual double calculateFunction( double *x);

    /*! \fn OSnLNode *cloneOSnLNode(double *x)
     *  \brief The implementation of the virtual functions.
     *  \return a point to a new OSnLNode of the proper type.
     */
    virtual OSnLNode *cloneOSnLNode() ;

    /*! \fn double OSnLNodeLn::constructADTape(std::map<int, int> *ADIdx, vector< ADdouble > *XAD)
     *  \brief The implementation of the virtual functions.
     *  \return a ADdouble.
     */
    virtual ADdouble constructADTape(std::map<int, int> *ADIdx, ADvector *XAD);


};//end OSnLNodeLn

/*! \class OSnLNodeSqrt
 *  \brief The OSnLNodeSqrt Class.
 *
 * @author  Robert Fourer, Jun Ma, Kipp Martin,
 * @version 1.0, 10/05/2005
 * @since   OS1.0
 *
 * \remarks
 * The in-memory representation of the OSnL element <sqrt>
 *
 */
class OSnLNodeSqrt : public OSnLNode
{
public:
    /**
     * default constructor.
     */
    OSnLNodeSqrt();

    /**
     * default destructor.
     */
    ~OSnLNodeSqrt();

    /**
     *
     * @return the value of operator name
     */
    virtual std::string getTokenName();

    /*! \fn double OSnLNodeSqrt::double(double *x)
     *  \brief The implementation of the virtual functions.
     *  \return a double.
     */
    virtual double calculateFunction( double *x);

    /*! \fn OSnLNode *cloneOSnLNode(double *x)
     *  \brief The implementation of the virtual functions.
     *  \return a point to a new OSnLNode of the proper type.
     */
    virtual OSnLNode *cloneOSnLNode() ;
    /*! \fn double OSnLNodeSqrt::constructADTape(std::map<int, int> *ADIdx, vector< ADdouble > *XAD)
     *  \brief The implementation of the virtual functions.
     *  \return a ADdouble.
     */
    virtual ADdouble constructADTape(std::map<int, int> *ADIdx, ADvector *XAD);


};//end OSnLNodeSqrt

/*! \class OSnLNodeSquare
 *  \brief The OSnLNodeSquare Class.
 *
 * @author  Robert Fourer, Jun Ma, Kipp Martin,
 * @version 1.0, 10/05/2005
 * @since   OS1.0
 *
 * \remarks
 * The in-memory representation of the OSnL element <square>
 *
 */
class OSnLNodeSquare : public OSnLNode
{
public:
    /**
     * default constructor.
     */
    OSnLNodeSquare();

    /**
     * default destructor.
     */
    ~OSnLNodeSquare();

    /**
     *
     * @return the value of operator name
     */
    virtual std::string getTokenName();

    /*! \fn double OSnLNodeSquare::double(double *x)
     *  \brief The implementation of the virtual functions.
     *  \return a double.
     */
    virtual double calculateFunction( double *x);

    /*! \fn OSnLNode *cloneOSnLNode(double *x)
     *  \brief The implementation of the virtual functions.
     *  \return a point to a new OSnLNode of the proper type.
     */
    virtual OSnLNode *cloneOSnLNode() ;

    /*! \fn double OSnLNodeSquare::constructADTape(std::map<int, int> *ADIdx, vector< ADdouble > *XAD)
     *  \brief The implementation of the virtual functions.
     *  \return a ADdouble.
     */
    virtual ADdouble constructADTape(std::map<int, int> *ADIdx, ADvector *XAD);
};//end OSnLNodeSquare

/*! \class OSnLNodeCos
 *  \brief The OSnLNodeCos Class.
 *
 * @author  Robert Fourer, Jun Ma, Kipp Martin,
 * @version 1.0, 10/05/2005
 * @since   OS1.0
 *
 * \remarks
 * The in-memory representation of the OSnL element <cos>
 *
 */
class OSnLNodeCos : public OSnLNode
{
public:
    /**
     * default constructor.
     */
    OSnLNodeCos();

    /**
     * default destructor.
     */
    ~OSnLNodeCos();

    /**
     *
     * @return the value of operator name
     */
    virtual std::string getTokenName();

    /*! \fn double OSnLNodeCos::double(double *x)
     *  \brief The implementation of the virtual functions.
     *  \return a double.
     */
    virtual double calculateFunction( double *x);

    /*! \fn OSnLNode *cloneOSnLNode(double *x)
     *  \brief The implementation of the virtual functions.
     *  \return a point to a new OSnLNode of the proper type.
     */
    virtual OSnLNode *cloneOSnLNode() ;

    /*! \fn double OSnLNodeCos::constructADTape(std::map<int, int> *ADIdx, vector< ADdouble > *XAD)
     *  \brief The implementation of the virtual functions.
     *  \return a ADdouble.
     */
    virtual ADdouble constructADTape(std::map<int, int> *ADIdx, ADvector *XAD);
};//end OSnLNodeCos

/*! \class OSnLNodeSin
 *  \brief The OSnLNodeSin Class.
 *
 * @author  Robert Fourer, Jun Ma, Kipp Martin,
 * @version 1.0, 10/05/2005
 * @since   OS1.0
 *
 * \remarks
 * The in-memory representation of the OSnL element <sin>
 *
 */
class OSnLNodeSin : public OSnLNode
{
public:
    /**
     * default constructor.
     */
    OSnLNodeSin();

    /**
     * default destructor.
     */
    ~OSnLNodeSin();

    /**
     *
     * @return the value of operator name
     */
    virtual std::string getTokenName();

    /*! \fn double OSnLNodeSin::double(double *x)
     *  \brief The implementation of the virtual functions.
     *  \return a double.
     */
    virtual double calculateFunction( double *x);

    /*! \fn OSnLNode *cloneOSnLNode(double *x)
     *  \brief The implementation of the virtual functions.
     *  \return a point to a new OSnLNode of the proper type.
     */
    virtual OSnLNode *cloneOSnLNode() ;

    /*! \fn double OSnLNodeSin::constructADTape(std::map<int, int> *ADIdx, vector< ADdouble > *XAD)
     *  \brief The implementation of the virtual functions.
     *  \return a ADdouble.
     */
    virtual ADdouble constructADTape(std::map<int, int> *ADIdx, ADvector *XAD);
};//end OSnLNodeSin

/*! \class OSnLNodeExp
 *  \brief The OSnLNodeExp Class.
 *
 * @author  Robert Fourer, Jun Ma, Kipp Martin,
 * @version 1.0, 10/05/2005
 * @since   OS1.0
 *
 * \remarks
 * The in-memory representation of the OSnL element <exp>
 *
 */
class OSnLNodeExp : public OSnLNode
{
public:
    /**
     * default constructor.
     */
    OSnLNodeExp();

    /**
     * default destructor.
     */
    ~OSnLNodeExp();

    /**
     *
     * @return the value of operator name
     */
    virtual std::string getTokenName();

    /*! \fn double OSnLNodeExp::double(double *x)
     *  \brief The implementation of the virtual functions.
     *  \return a double.
     */
    virtual double calculateFunction( double *x);

    /*! \fn double OSnLNodeExp::constructADTape(std::map<int, int> *ADIdx, vector< ADdouble > *XAD)
     *  \brief The implementation of the virtual functions.
     *  \return a ADdouble.
     */
    virtual ADdouble constructADTape(std::map<int, int> *ADIdx, ADvector *XAD);
    /*! \fn OSnLNode *cloneOSnLNode(double *x)
     *  \brief The implementation of the virtual functions.
     *  \return a point to a new OSnLNode of the proper type.
     */

    virtual OSnLNode *cloneOSnLNode() ;

};//end OSnLNodeExp

/*! \class OSnLNodeAbs
 *  \brief The OSnLNodeAbs Class.
 *
 * @author  Robert Fourer, Jun Ma, Kipp Martin,
 * @version 1.0, 10/05/2005
 * @since   OS1.0
 *
 * \remarks
 * The in-memory representation of the OSnL element <abs>
 *
 */
class OSnLNodeAbs : public OSnLNode
{
public:
    /**
     * default constructor.
     */
    OSnLNodeAbs();

    /**
     * default destructor.
     */
    ~OSnLNodeAbs();

    /**
     *
     * @return the value of operator name
     */
    virtual std::string getTokenName();

    /*! \fn double OSnLNodeAbs::double(double *x)
     *  \brief The implementation of the virtual functions.
     *  \return a double.
     */
    virtual double calculateFunction( double *x);

    /*! \fn OSnLNode *cloneOSnLNode(double *x)
     *  \brief The implementation of the virtual functions.
     *  \return a point to a new OSnLNode of the proper type.
     */
    virtual OSnLNode *cloneOSnLNode() ;

    /*! \fn double OSnLNodeAbs::constructADTape(std::map<int, int> *ADIdx, vector< ADdouble > *XAD)
     *  \brief The implementation of the virtual functions.
     *  \return a ADdouble.
     */
    virtual ADdouble constructADTape(std::map<int, int> *ADIdx, ADvector *XAD);

};//end OSnLNodeAbs


/*! \class OSnLNodeErf
 *  \brief The OSnLNodeErf Class.
 *
 * @author  Horand Gassmann, Jun Ma, Kipp Martin,
 * @version 1.0, 10/05/2005
 * @since   OS1.0
 *
 * \remarks
 * The in-memory representation of the OSnL element <ln>
 *
 */
class OSnLNodeErf : public OSnLNode
{
public:
    /**
     * default constructor.
     */
    OSnLNodeErf();

    /**
     * default destructor.
     */
    ~OSnLNodeErf();

    /**
     *
     * @return the value of operator name
     */
    virtual std::string getTokenName();

    /*! \fn double OSnLNodeErf::double(double *x)
     *  \brief The implementation of the virtual functions.
     *  \return a double.
     */
    virtual double calculateFunction( double *x);

    /*! \fn OSnLNode *cloneOSnLNode(double *x)
     *  \brief The implementation of the virtual functions.
     *  \return a point to a new OSnLNode of the proper type.
     */
    virtual OSnLNode *cloneOSnLNode() ;

    /*! \fn double OSnLNodeLn::constructADTape(std::map<int, int> *ADIdx, vector< ADdouble > *XAD)
     *  \brief The implementation of the virtual functions.
     *  \return a ADdouble.
     */
    virtual ADdouble constructADTape(std::map<int, int> *ADIdx, ADvector *XAD);
};//end OSnLNodeErf




/*! \class OSnLNodeIf
 *  \brief The OSnLNodeIf Class.
 *
 * @author  Robert Fourer, Jun Ma, Kipp Martin,
 * @version 1.0, 10/05/2005
 * @since   OS1.0
 *
 * \remarks
 * The in-memory representation of the OSnL element <if>
 *
 */
class OSnLNodeIf : public OSnLNode
{
public:
    /**
     * default constructor.
     */
    OSnLNodeIf();

    /**
     * default destructor.
     */
    ~OSnLNodeIf();

    /**
     *
     * @return the value of operator name
     */
    virtual std::string getTokenName();

    /*! \fn double OSnLNodeIf::double(double *x)
     *  \brief The implementation of the virtual functions.
     *  \return a double.
     */
    virtual double calculateFunction( double *x);

    /*! \fn OSnLNode *cloneOSnLNode(double *x)
     *  \brief The implementation of the virtual functions.
     *  \return a point to a new OSnLNode of the proper type.
     */
    virtual OSnLNode *cloneOSnLNode() ;

    /*! \fn double OSnLNodeIf::constructADTape(std::map<int, int> *ADIdx, vector< ADdouble > *XAD)
     *  \brief The implementation of the virtual functions.
     *  \return a ADdouble.
     */
    virtual ADdouble constructADTape(std::map<int, int> *ADIdx, ADvector *XAD);

};//end OSnLNodeIf

/*! \class OSnLNodeNumber
 *  \brief The OSnLNodeNumber Class.
 *
 * @author  Robert Fourer, Jun Ma, Kipp Martin,
 * @version 1.0, 10/05/2005
 * @since   OS1.0
 *
 * \remarks
 * The in-memory representation of the OSnL element <number>
 *
 */
class OSnLNodeNumber : public OSnLNode
{
public:

    /** value is the value of the number */
    double value;
    /** in the C++ type is real */
    std::string type;
    /** later, e.g. stochastic programming, we may wish
     * to give an id to a number
     */
    std::string id;

    /**
     * default constructor.
     */
    OSnLNodeNumber();

    /**
     * default destructor.
     */
    ~OSnLNodeNumber();

    /**
     *
     * @return the value of operator name
     */
    virtual std::string getTokenName();

    /**
     *
     * @return a string token that corresponds to the OSnLNode.
     */
    virtual std::string getTokenNumber();

    /**
     *
     * @return the OSiL XML for the number node.
     */
    virtual std::string getNonlinearExpressionInXML();

    /*! \fn double OSnLNodeNumber::double(double *x)
     *  \brief The implementation of the virtual functions.
     *  \return a double.
     */
    virtual double calculateFunction( double *x);

    /*! \fn OSnLNode *cloneOSnLNode(double *x)
     *  \brief The implementation of the virtual functions.
     *  \return a point to a new OSnLNode of the proper type.
     */
    virtual OSnLNode *cloneOSnLNode() ;


    /*! \fn double OSnLNodeNumber::constructADTape(std::map<int, int> *ADIdx, vector< ADdouble > *XAD)
     *  \brief The implementation of the virtual functions.
     *  \return a ADdouble.
     */
    virtual ADdouble constructADTape(std::map<int, int> *ADIdx, ADvector *XAD);


};//end OSnLNodeNumber


/*! \class OSnLNodeE
 *  \brief The OSnLNodeE Class.
 *
 * @author  Robert Fourer, Jun Ma, Kipp Martin,
 * @version 1.0, 10/05/2005
 * @since   OS1.0
 *
 * \remarks
 * The in-memory representation of the OSnL element <E>
 *
 */
class OSnLNodeE : public OSnLNode
{
public:

    /**
     * default constructor.
     */
    OSnLNodeE();

    /**
     * default destructor.
     */
    ~OSnLNodeE();


    /**
     *
     * @return a string token that corresponds to the OSnLNode.
     */
    virtual std::string getTokenNumber();


    /**
     *
     * @return a string token that corresponds to the OSnLNode.
     */
    virtual std::string getTokenName();

    /**
     *
     * @return the OSiL XML for the number node.
     */
    virtual std::string getNonlinearExpressionInXML();

    /*! \fn double OSnLNodeE::double(double *x)
     *  \brief The implementation of the virtual functions.
     *  \return a double.
     */
    virtual double calculateFunction( double *x);

    /*! \fn OSnLNode *cloneOSnLNode(double *x)
     *  \brief The implementation of the virtual functions.
     *  \return a point to a new OSnLNode of the proper type.
     */
    virtual OSnLNode *cloneOSnLNode() ;


    /*! \fn double OSnLNodeE::constructADTape(std::map<int, int> *ADIdx, vector< ADdouble > *XAD)
     *  \brief The implementation of the virtual functions.
     *  \return a ADdouble.
     */
    virtual ADdouble constructADTape(std::map<int, int> *ADIdx, ADvector *XAD);


};//end OSnLNodeE

/*! \class OSnLNodePI
 *  \brief The OSnLNodePI Class.
 *
 * @author  Robert Fourer, Jun Ma, Kipp Martin,
 * @version 1.0, 10/05/2005
 * @since   OS1.0
 *
 * \remarks
 * The in-memory representation of the OSnL element <pi>
 *
 */
class OSnLNodePI : public OSnLNode
{
public:

    /**
     * default constructor.
     */
    OSnLNodePI();

    /**
     * default destructor.
     */
    ~OSnLNodePI();


    /**
     *
     * @return a string token that corresponds to the OSnLNode.
     */
    virtual std::string getTokenNumber();


    /**
     *
     * @return a string token that corresponds to the OSnLNode.
     */
    virtual std::string getTokenName();

    /**
     *
     * @return the OSiL XML for the number node.
     */
    virtual std::string getNonlinearExpressionInXML();

    /*! \fn double OSnLNodePI::double(double *x)
     *  \brief The implementation of the virtual functions.
     *  \return a double.
     */
    virtual double calculateFunction( double *x);

    /*! \fn OSnLNode *cloneOSnLNode(double *x)
     *  \brief The implementation of the virtual functions.
     *  \return a point to a new OSnLNode of the proper type.
     */
    virtual OSnLNode *cloneOSnLNode() ;


    /*! \fn double OSnLNodePI::constructADTape(std::map<int, int> *ADIdx, vector< ADdouble > *XAD)
     *  \brief The implementation of the virtual functions.
     *  \return a ADdouble.
     */
    virtual ADdouble constructADTape(std::map<int, int> *ADIdx, ADvector *XAD);


};//end OSnLNodePI


/*! \class OSnLNodeVariable
 *  \brief The OSnLNodeVariable Class.
 *
 * @author  Robert Fourer, Jun Ma, Kipp Martin,
 * @version 1.0, 10/05/2005
 * @since   OS1.0
 *
 * \remarks
 * The in-memory representation of the OSnL element <variable>
 *
 */
class OSnLNodeVariable : public OSnLNode
{
public:

    /** coef is an option coefficient on the variable, the
     * default value is 1.0
     */
    double coef;

    /** idx is the index of the variable */
    int idx;

    /**
     * default constructor.
     */
    OSnLNodeVariable();

    /**
     * default destructor.
     */
    ~OSnLNodeVariable();



    virtual void getVariableIndexMap(std::map<int, int> *varIdx);

    /**
     *
     * @return a string token that corresponds to the OSnLNode.
     */
    virtual std::string getTokenNumber();


    /**
     *
     * @return a std::string token that corresponds to the OSnLNode.
     */
    virtual std::string getTokenName();

    /**
     *
     * @return the OSiL XML for the variable node.
     */
    virtual std::string getNonlinearExpressionInXML();

    /*! \fn double OSnLNodeVariable::double(double *x)
     *  \brief The implementation of the virtual functions.
     *  \return a double.
     */
    virtual double calculateFunction( double *x);

    /*! \fn OSnLNode *cloneOSnLNode(double *x)
     *  \brief The implementation of the virtual functions.
     *  \return a point to a new OSnLNode of the proper type.
     */
    virtual OSnLNode *cloneOSnLNode() ;

    /*! \fn double OSnLNodeVariable::constructADTape(std::map<int, int> *ADIdx, vector< ADdouble > *XAD)
     *  \brief The implementation of the virtual functions.
     *  \return a ADdouble.
     */
    virtual ADdouble constructADTape(std::map<int, int> *ADIdx, ADvector *XAD);


};//end OSnLNodeVariable

/*! \class OSnLNodeAllDiff
 *  \brief The OSnLNodeAllDiff Class.
 *
 * @author  Robert Fourer, Jun Ma, Kipp Martin,
 * @version 1.0, 10/05/2005
 * @since   OS1.0
 *
 * \remarks
 * The in-memory representation of the OSnL element <alldiff>
 *
 */

class OSnLNodeAllDiff : public OSnLNode
{
public:
    /**
     * default constructor.
     */
    OSnLNodeAllDiff();

    /**
     * default destructor.
     */
    ~OSnLNodeAllDiff();

    /**
     *
     * @return the value of operator name
     */
    virtual std::string getTokenName();

    /*! \fn double OSnLNodeAllDiff::double(double *x)
     *  \brief The implementation of the virtual functions.
     *  \return a double.
     */
    virtual double calculateFunction( double *x);

    /*! \fn OSnLNode *cloneOSnLNode(double *x)
     *  \brief The implementation of the virtual functions.
     *  \return a point to a new OSnLNode of the proper type.
     */
    virtual OSnLNode *cloneOSnLNode() ;

    /*! \fn double OSnLNodeAllDiff::constructADTape(std::map<int, int> *ADIdx, vector< ADdouble > *XAD)
     *  \brief The implementation of the virtual functions.
     *  \return a ADdouble.
     */
    virtual ADdouble constructADTape(std::map<int, int> *ADIdx, ADvector *XAD);

};//end OSnLNodeAllDiff



/*
TO DO:

1.  Allow for a variable node with a child

2.  When we create the Expression Tree from postfix, do we check if the coefficient of a variable is 1?
*/
#endif


