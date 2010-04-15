/**
 * @(#)OSnLNodeQuadratic 1.0 03/14/2004
 *
 * Copyright (c) 2004
 */
package org.optimizationservices.oscommon.nonlinear;

import java.util.Vector;

/**
 *
 * <P>The <code>OSnLNodeQuadratic</code> class represents a summation node of quadratic terms in an expression tree.
 * It extends the abstract OSnLNode class and implements its abstract methods such as
 * calculateFunction(double[]).
 * </p>
 *
 * </p>
 *
 * @author Robert Fourer, Jun Ma, Kipp Martin
 * @version 1.0, 03/14/2004
 * @see org.optimizationservices.oscommon.nonlinear.OSExpressionTree;
 * @see org.optimizationservices.oscommon.nonlinear.OSnLNode;
 * @see org.optimizationservices.oscommon.nonlinear.NlNodeQqTerm;
 * @since OS 1.0
 */
public class OSnLNodeQuadratic extends OSnLNode{

	/**
	 * m_sSymbol holds the symbol that this nlNode looks in ASCII.
	 */
	protected String m_sSymbol = "quadratic";

	/**
	 * m_sSymbol holds the description of this nlNode
	 */
	protected String m_sDescription = "Summation of n quadratic term node operands";

	/**
	 * m_iSymbol holds the four digit integer that represents this nlNode, with the leftmost (first)
	 * integer representing the category and the right three digits representing a unique sequence number
	 * in the node category.
	 */
	protected int m_iSymbol = 9002;

	/**
	 * m_iType holds the integer representation of the type of this nlNode.
	 */
	protected int m_iType = -1;

	/**
	 * constructor
	 *
	 * </p>
	 *
	 * @param nodes holds the array of node operands to sum the quadratic terms.
	 */
	protected OSnLNodeQuadratic(OSnLNode[] nodes){
		m_mChildren = nodes;
	}//constructor

	/**
	 *
	 * Default Constructor
	 */
	protected OSnLNodeQuadratic(){
	}//constructor

	/**
	 * Calculate the result value of addition given the current variable values.
	 *
	 * </p>
	 *
	 * @param x holds the values of the variables in a double array.
	 * @return the result value of summation of quadratic terms given the current variable values.
	 */
	protected double calculateFunction(double[] x){
		m_dFunctionValue = 0.0;
		for(int i = 0; i < ((m_mChildren == null)?0:m_mChildren.length); i++){
			m_dFunctionValue += m_mChildren[i].calculateFunction(x);
		}
		return m_dFunctionValue;
	}//calculateFunction

	/**
	 * Propogate the function derivatives w.r.t the nodes from the root to the node's children.
	 * This is mainly used for the the calculation of all derivatives at the same time to avoid
	 * redundancies, which is based on automatic differentiation.
	 *
	 * </p>
	 *
	 * @param rootNode holds root node of this current node.
	 * @param x holds the values of the variables in a double array.
	 * @see ExpressionTree#calculateDerivatives
	 */
	protected void propogateDerivatives(OSnLNode rootNode, double[] x){
		for(int i = 0; i < ((m_mChildren == null)?0:m_mChildren.length); i++){
			m_mChildren[i].m_dNodeDerivative = m_dNodeDerivative;
			m_mChildren[i].propogateDerivatives(rootNode, x);
		}
	}//propogateDerivatives

	/**
	 * Calculate the result value of quadratic term summation derivative given the current variable values.
	 *
	 * </p>
	 *
	 * @param x holds the values of the variables in a double array.
	 * @param functionEvaluated holds whether the function has been evaluated.
	 * @return the result value of quadratic term summation derivative given the current variable values.
	 */
	protected double calculateDerivative(double[] x, int index, boolean functionEvaluated){
		double dDerivative = 0;
		for(int i = 0; i < ((m_mChildren == null)?0:m_mChildren.length); i++){
			dDerivative += m_mChildren[i].calculateDerivative(x, index, functionEvaluated);
		}
		return dDerivative;
	}//calculateDerivative

	/**
	 * This is the recursive call. 
	 * @param vPostfix holds the vector to put in the postfix tokens. 
	 * @return the nonlinear expression starting with the current node in a postfix vector of operator symbols.
	 */
	protected Vector<String> getPostfix(Vector<String> vPostfix){
		for(int i = 0; i < ((getChildNodes() == null)?0:m_mChildren.length); i++){
			m_mChildren[i].getPostfix(vPostfix);
		}
		String sSum = "sum";
		if(getType() == -1){
			sSum += "[";
			sSum += ((getChildNodes() == null)?0:m_mChildren.length);
			sSum += "]";
		}
		vPostfix.addElement(sSum);
		return vPostfix;
	}//getPostfix

	/**
	 * This is the recursive call. 
	 * @param vPrefix holds the vector to put in the prefix tokens. 
	 * @return the nonlinear expression starting with the current node in a prefix vector of operator symbols.
	 */
	protected Vector<String> getPrefix(Vector<String> vPrefix){
		String sSum = "sum";
		if(getType() == -1){
			sSum += "[";
			sSum += ((getChildNodes() == null)?0:m_mChildren.length);
			sSum += "]";
		}
		vPrefix.addElement(sSum);
		for(int i = 0; i < ((m_mChildren == null)?0:m_mChildren.length); i++){
			m_mChildren[i].getPrefix(vPrefix);
		}
		return vPrefix;
	}//getPrefix

	/**
	 * This is the recursive call. 
	 * @param vInfix holds the vector to put in the infix tokens. 
	 * @return the nonlinear expression starting with the current node in an infix vector of operator symbols.
	 */
	protected Vector<String> getInfix(Vector<String> vInfix){
		String sSum = "sum";
		if(getType() == -1){
			sSum += "[";
			sSum += ((getChildNodes() == null)?0:m_mChildren.length);
			sSum += "]";
		}
		vInfix.addElement(sSum);
		if(m_mChildren != null) vInfix.addElement("(");
		for(int i = 0; i < ((m_mChildren == null)?0:m_mChildren.length); i++){
			m_mChildren[i].getInfix(vInfix);
		}
		if(m_mChildren != null) vInfix.addElement(")");
		return vInfix;
	}//getInfix

	/**
	 *
	 * @return the symbol of this nlNode in ASCII string.
	 */
	protected String getSymbol(){
		return m_sSymbol;
	}//getSymbol

	/**
	 *
	 * @return the symbol of this nlNode in integer.
	 */
	protected int getSymbolInteger(){
		return m_iSymbol;
	}//getSymbolInteger

	/**
	 *
	 * @return the type of this nlNode.
	 */
	protected int getType(){
		return m_iType;
	}//getType

	/**
	 *
	 * @return the description of this nlNode.
	 */
	protected String getDescription(){
		return m_sDescription;
	}//getDescription

}//class OSnLNodeQuadratic
