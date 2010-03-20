/**
 * @(#)OSnLNodeMax 1.0 03/14/2004
 *
 * Copyright (c) 2004
 */
package org.optimizationservices.oscommon.nonlinear;

/**
 *
 * <P>The <code>OSnLNodeMax</code> class represents a maximum node in an expression tree.
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
 * @since OS 1.0
 */
public class OSnLNodeMax extends OSnLNode{

	/**
	 * m_sSymbol holds the symbol that this nlNode looks in ASCII.
	 */
	protected String m_sSymbol = "max";

	/**
	 * m_sSymbol holds the description of this nlNode
	 */
	protected String m_sDescription = "Maximum of n node operands";

	/**
	 * m_iSymbol holds the four digit integer that represents this nlNode, with the leftmost (first)
	 * integer representing the category and the right three digits representing a unique sequence number
	 * in the node category.
	 */
	protected int m_iSymbol = 4011;

	/**
	 * m_iType holds the integer representation of the type of this nlNode.
	 */
	protected int m_iType = -1;

	/**
	 * constructor
	 *
	 * </p>
	 *
	 * @param nodes holds the array of node operands to max.
	 */
	protected OSnLNodeMax(OSnLNode[] nodes){
		m_mChildren = nodes;
	}//constructor

	/**
	 *
	 * Default Constructor
	 */
	protected OSnLNodeMax(){
	}//constructor

	/**
	 * Calculate the result value of addition given the current variable values.
	 *
	 * </p>
	 *
	 * @param x holds the values of the variables in a double array.
	 * @return the result value of maximum given the current variable values.
	 */
	protected double calculateFunction(double[] x){
		m_dFunctionValue = m_mChildren[0].calculateFunction(x);
		double d;
		for(int i = 1; i < ((m_mChildren == null)?0:m_mChildren.length); i++){
			d = m_mChildren[i].calculateFunction(x);
			if(d > m_dFunctionValue) m_dFunctionValue = d;
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
		double dMax = m_mChildren[0].calculateFunction(x);
		double d;
		int iMaxIndex = 0;
		for(int i = 1; i < ((m_mChildren == null)?0:m_mChildren.length); i++){
			d = m_mChildren[i].calculateFunction(x);
			if(d > dMax){
				dMax = d;
				iMaxIndex = i;
			}
		}
		m_mChildren[iMaxIndex].m_dNodeDerivative = m_dNodeDerivative;
		m_mChildren[iMaxIndex].propogateDerivatives(rootNode, x);
	}//propogateDerivatives

	/**
	 * Calculate the result value of maximum derivative given the current variable values.
	 *
	 * </p>
	 *
	 * @param x holds the values of the variables in a double array.
	 * @param functionEvaluated holds whether the function has been evaluated.
	 * @return the result value of maximum derivative given the current variable values.
	 */
	protected double calculateDerivative(double[] x, int index, boolean functionEvaluated){
		double dDerivative = 0;
		double dMax = m_mChildren[0].calculateFunction(x);
		double d;
		int iMaxIndex = 0;
		for(int i = 1; i < ((m_mChildren == null)?0:m_mChildren.length); i++){
			d = m_mChildren[i].calculateFunction(x);
			if(d > dMax){
				dMax = d;
				iMaxIndex = i;
			}
		}
		dDerivative = m_mChildren[iMaxIndex].calculateDerivative(x, index, functionEvaluated);
		return dDerivative;
	}//calculateDerivative

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

}//class OSnLNodeMax
