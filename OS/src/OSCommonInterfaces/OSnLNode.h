/** @file OSExpressionTree.cpp
 * \brief This file defines the OSnLNode class along with its derived classes..
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




 
#ifndef OSNLNODE_H
#define OSNLNODE_H
#include<iostream>
#include<vector>


/*! \class OSnLNode OSnLNode.h "OSnLNode.h"
 *  \brief The OSnLNode Class.
 *
 * @author  Robert Fourer, Jun Ma, Kipp Martin, 
 * @version 1.0, 10/05/2005
 * @since   OS1.0
 * 
 */

enum OP_CODES{
	OS_PLUS = 1001,
	OS_SUM = 1002,
	OS_MINUS = 1003,
	OS_NEGATE = 1004,
	OS_TIMES = 1005,
	OS_DIVIDE = 1006,
	OS_POWER = 1009,
	OS_PRODUCT = 1010,
	OS_LN = 2007,
	OS_EXP = 2010,
	OS_NUMBER = 5001,
	OS_VARIABLE = 6001,
	OS_IF = 7001,
	OS_ABS = 2001,
	OS_MAX = 3024
};

class OSnLNode{  

public:	
	
	/** nodeName holds the OSnLNode name */
	std::string snodeName;
	
	/**  numberOfChildren is the number of OSnLNode child elements*/
	int inumberOfChildren;	

	/**  ssymbolInt is the unique integer assigned to the OSnLNode*/	
	int inodeInt;

	/**  ssymbolInt is the unique integer assigned to the OSnLNode*/	
	int inodeType;
	
	/**
	 * m_mChildren holds all the operands, that is nodes that the current node operate on.
	 */
	OSnLNode **m_mChildren;
	
	/**
	 * m_dFunctionValue holds the function value given the current variable values.
	 */
	double m_dFunctionValue;
	

	
	/**
	 *
	 * @return the child nodes of this nlNode.
	 */
	//OSnLNode **getChildNodes();
	
	
	
	/**
	 *
	 * @return the the current node and all children in a postfix vector of operator symbols.
	 * some exceptions:
	 * a number node should have the format:
	 * 5001:value:type:id, for example
	 * 5001:32.5:real: or 5001:32.5::
	 * we must always have the value
	 * a variable node should have the format
	 * 6001[inumberOfChildren]:idx:coef
	 * idx is the variable index
	 * coef is the coefficient on the variable, it is 1 by default
	 */
	virtual std::string getTokenNumberFromOSnLNode();
	
	virtual std::string getTokenNameFromOSnLNode();
	
	virtual  std::string getNonlinearExpressionInXML();
	
	OSnLNode* createExpressionTreeFromPostfix(std::vector<OSnLNode*> nlNodeVec);
	
	OSnLNode* createExpressionTreeFromPrefix(std::vector<OSnLNode*> nlNodeVec);
	
	std::vector<OSnLNode*> getPrefixFromExpressionTree();

	std::vector<OSnLNode*> preOrderOSnLNodeTraversal();
	
	std::vector<OSnLNode*> getPostfixFromExpressionTree();
	
	std::vector<OSnLNode*> postOrderOSnLNodeTraversal();
	
	/**
	 *
	 * @return the the current node as a string token.
	 * the token is the 
	 * the integer (opCode) assigned -- inodeType
	 * some exceptions:
	 * a sum node should have
	 * sum[numberOfChildren]
	 * a product node should have
	 * product[numberOfChildren]
	 * a number node should have the format:
	 * 5001:value:type:id, for example
	 * 5001:32.5:real: or 5001:32.5::
	 * we must always have the value
	 * a variable node should have the format
	 * 6001[inumberOfChildren]:idx:coef
	 * idx is the variable index
	 * coef is the coefficient on the variable, it is 1 by default
	 */	
	std::string getTokenFromOSnLNode();
	
	static void setnlNodeIdxMap();
	
	static OSnLNode* getOSnLNodeFromToken(std::string sOSnLNodeToken);
	
	/**
	 * Calculate the function value given the current variable values.
	 * This is an abstract method which is required to be implemented by the concrete
	 * operator nodes that derive or extend from this OSnLNode class.
	 *
	 * </p>
	 *
	 * @param x holds the values of the variables in a double array.
	 * @return the function value given the current variable values.
	 */
	virtual double calculateFunction(double *x) = 0;	
	
	/**
	 * Create or clone a node of this type.
	 * This is an abstract method which is required to be implemented by the concrete
	 * operator nodes that derive or extend from this OSnLNode class.
	 *
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
	
};//end OSnLNode

class OSnLNodePlus : public OSnLNode{  
public:
	/**
	 * default constructor.
	 */
	OSnLNodePlus();

	/**
	 * default destructor.
	 */	
	~OSnLNodePlus();
	
	/*! \fn double OSnLNodePlus::calculateFunction(double *x) 
	 *  \brief The implementation of the virtual functions. 
	 *  \return a double.
	 */	
	virtual double calculateFunction( double *x);
	
	/*! \fn OSnLNode *cloneOSnLNode(double *x) 
	 *  \brief The implementation of the virtual functions. 
	 *  \return a point to a new OSnLNode of the proper type.
	 */	
	
	virtual OSnLNode *cloneOSnLNode() ;

};//end OSnLNodePlus


class OSnLNodeSum : public OSnLNode{  
public:
	/**
	 * default constructor.
	 */
	OSnLNodeSum();

	/**
	 * default destructor.
	 */	
	~OSnLNodeSum();
	
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

};//end OSnLNodeSum

class OSnLNodeMax : public OSnLNode{  
public:
	/**
	 * default constructor.
	 */
	OSnLNodeMax();

	/**
	 * default destructor.
	 */	
	~OSnLNodeMax();
	
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

};//end OSnLNodeMax

class OSnLNodeMinus : public OSnLNode{  
public:
	/**
	 * default constructor.
	 */
	OSnLNodeMinus();

	/**
	 * default destructor.
	 */	
	~OSnLNodeMinus();
	
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

};//end OSnLNodeMinus


class OSnLNodeNegate : public OSnLNode{  
public:
	/**
	 * default constructor.
	 */
	OSnLNodeNegate();

	/**
	 * default destructor.
	 */	
	~OSnLNodeNegate();
	
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

};//end OSnLNodeNegate



class OSnLNodeTimes : public OSnLNode{  
public:
	/**
	 * default constructor.
	 */
	OSnLNodeTimes();

	/**
	 * default destructor.
	 */	
	~OSnLNodeTimes();
	
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

};//end OSnLNodeTimes



class OSnLNodeDivide : public OSnLNode{  
public:
	/**
	 * default constructor.
	 */
	OSnLNodeDivide();

	/**
	 * default destructor.
	 */	
	~OSnLNodeDivide();
	
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
	


};//end OSnLNodeDivide


class OSnLNodePower : public OSnLNode{  
public:
	/**
	 * default constructor.
	 */
	OSnLNodePower();

	/**
	 * default destructor.
	 */	
	~OSnLNodePower();
	
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

};//end OSnLNodePower


class OSnLNodeProduct : public OSnLNode{  
public:
	/**
	 * default constructor.
	 */
	OSnLNodeProduct();

	/**
	 * default destructor.
	 */	
	~OSnLNodeProduct();
	
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

};//end OSnLNodeProduct


class OSnLNodeLn : public OSnLNode{  
public:
	/**
	 * default constructor.
	 */
	OSnLNodeLn();

	/**
	 * default destructor.
	 */	
	~OSnLNodeLn();
	
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
	

};//end OSnLNodeLn


class OSnLNodeExp : public OSnLNode{  
public:
	/**
	 * default constructor.
	 */
	OSnLNodeExp();

	/**
	 * default destructor.
	 */	
	~OSnLNodeExp();
	
	/*! \fn double OSnLNodeExp::double(double *x) 
	 *  \brief The implementation of the virtual functions. 
	 *  \return a double.
	 */	
	virtual double calculateFunction( double *x);
	
	/*! \fn OSnLNode *cloneOSnLNode(double *x) 
	 *  \brief The implementation of the virtual functions. 
	 *  \return a point to a new OSnLNode of the proper type.
	 */	
	
	virtual OSnLNode *cloneOSnLNode() ;

};//end OSnLNodeExp

class OSnLNodeAbs : public OSnLNode{  
public:
	/**
	 * default constructor.
	 */
	OSnLNodeAbs();

	/**
	 * default destructor.
	 */	
	~OSnLNodeAbs();
	
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

};//end OSnLNodeAbs


class OSnLNodeIf : public OSnLNode{  
public:
	/**
	 * default constructor.
	 */
	OSnLNodeIf();

	/**
	 * default destructor.
	 */	
	~OSnLNodeIf();
	
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

};//end OSnLNodeIf

class OSnLNodeNumber : public OSnLNode{  
public:

	double value;
	std::string type;
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
	 * @return a string token that corresponds to the OSnLNode.
	 */
	virtual std::string getTokenNumberFromOSnLNode();
	
	
	/**
	 *
	 * @return a string token that corresponds to the OSnLNode.
	 */
	virtual std::string getTokenNameFromOSnLNode();
	
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

};//end OSnLNodeNumber

class OSnLNodeVariable : public OSnLNode{  
public:

	double coef;
	int idx;

	/**
	 * default constructor.
	 */
	OSnLNodeVariable();

	/**
	 * default destructor.
	 */	
	~OSnLNodeVariable();
	
	/**
	 *
	 * @return a string token that corresponds to the OSnLNode.
	 */
	virtual std::string getTokenNumberFromOSnLNode();
	
	
	/**
	 *
	 * @return a std::string token that corresponds to the OSnLNode.
	 */
	virtual std::string getTokenNameFromOSnLNode();
	
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

};//end OSnLNodeVariable

/* 
TO DO:

1.  Allow for a variable node with a child

2.  When we create the Expression Tree from postfix, do we check if the coefficient of a variable is 1?
*/
#endif


