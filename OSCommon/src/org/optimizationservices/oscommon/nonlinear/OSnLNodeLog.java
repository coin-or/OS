/**
 * @(#)OSnLNodeLog 1.0 03/14/2004
 *
 * Copyright (c) 2004
 */
package org.optimizationservices.oscommon.nonlinear;

/**
 *
 * <P>The <code>OSnLNodeLog</code> class represents a log node in an expression tree.
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
public class OSnLNodeLog extends OSnLNode{

	/**
	 * m_sSymbol holds the symbol that this nlNode looks in ASCII.
	 */
	protected String m_sSymbol = "log";

	/**
	 * m_sSymbol holds the description of this nlNode
	 */
	protected String m_sDescription = "Log function of a node operand";

	/**
	 * m_iSymbol holds the four digit integer that represents this nlNode, with the leftmost (first)
	 * integer representing the category and the right three digits representing a unique sequence number
	 * in the node category.
	 */
	protected int m_iSymbol = 2008;

	/**
	 * m_iType holds the integer representation of the type of this nlNode.
	 */
	protected int m_iType = 2;

	/**
	 * constructor
	 *
	 * </p>
	 *
	 * @param baseNode holds the base node of the log function.
	 * @param exponentNode holds the exponent node of the log function.
	 */
	protected OSnLNodeLog(OSnLNode baseNode, OSnLNode exponentNode){
		m_mChildren = new OSnLNode[2];
		m_mChildren[0] = baseNode;
		m_mChildren[1] = exponentNode;
	}//constructor

	/**
	 *
	 * Default Constructor
	 */
	protected OSnLNodeLog(){
		m_mChildren = new OSnLNode[2];
	}//constructor

	/**
	 * Calculate the result value of log function given the current variable values.
	 *
	 * </p>
	 *
	 * @param x holds the values of the variables in a double array.
	 * @return the result value of log function given the current variable values.
	 */
	protected double calculateFunction(double[] x){
		double dBase = m_mChildren[0].calculateFunction(x);
		double dExponent = m_mChildren[1].calculateFunction(x);
		if(dBase <= 0 || dBase == 1 || dExponent <= 0) m_dFunctionValue = Double.NaN;
		else m_dFunctionValue = Math.log(dExponent) / Math.log(dBase);
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
		double dLeftValue = m_mChildren[0].calculateFunction(x, true);
		double dRightValue = m_mChildren[1].calculateFunction(x, true);
		if(dLeftValue <= 0 || dLeftValue == 1 || dRightValue <= 0){
			m_mChildren[0].m_dNodeDerivative = Double.NaN;
			m_mChildren[1].m_dNodeDerivative = Double.NaN;
		}
		else{
			m_mChildren[0].m_dNodeDerivative = m_dNodeDerivative * (-Math.log(dRightValue) / (Math.pow(Math.log(dLeftValue), 2) * dLeftValue));
			m_mChildren[1].m_dNodeDerivative = m_dNodeDerivative * (1 / (dRightValue * Math.log(dLeftValue)));
		}
		m_mChildren[0].propogateDerivatives(rootNode, x);
		m_mChildren[1].propogateDerivatives(rootNode, x);
	}//propogateDerivatives

	/**
	 * Calculate the result value of log function derivative given the current variable values.
	 *
	 * </p>
	 *
	 * @param x holds the values of the variables in a double array.
	 * @param functionEvaluated holds whether the function has been evaluated.
	 * @return the result value of log function derivative given the current variable values.
	 */
	protected double calculateDerivative(double[] x, int index, boolean functionEvaluated){
		double dDerivative;
		double dBase = m_mChildren[0].calculateFunction(x, functionEvaluated);
		double dExponent = m_mChildren[1].calculateFunction(x, functionEvaluated);
		double dBaseDerivative = m_mChildren[0].calculateDerivative(x, index, functionEvaluated);
		double dExponentDerivative = m_mChildren[1].calculateDerivative(x, index, functionEvaluated);
		if(dBase <= 0 || dBase == 1 || dExponent <= 0) dDerivative = Double.NaN;
		else dDerivative = dExponentDerivative / (dExponent * Math.log(dBase)) -
		Math.log(dExponent) * dBaseDerivative / (Math.pow(Math.log(dBase), 2) * dBase);
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

}//class OSnLNodeLog
