/**
 * @(#)OSnLNodeEq 1.0 03/14/2004
 *
 * Copyright (c) 2004
 */
package org.optimizationservices.oscommon.nonlinear;

/**
 *
 * <P>The <code>OSnLNodeEq</code> class represents an eq (or equal) relational node in an expression tree.
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
public class OSnLNodeEq extends OSnLNode{

	/**
	 * m_sSymbol holds the symbol that this nlNode looks in ASCII.
	 */
	protected String m_sSymbol = "eq";

	/**
	 * m_sSymbol holds the description of this nlNode
	 */
	protected String m_sDescription = "Eq (or equal) relational node.";

	/**
	 * m_iSymbol holds the four digit integer that represents this nlNode, with the leftmost (first)
	 * integer representing the category and the right three digits representing a unique sequence number
	 * in the node category.
	 */
	protected int m_iSymbol = 7006;

	/**
	 * m_iType holds the integer representation of the type of this nlNode.
	 */
	protected int m_iType = 2;

	/**
	 * constructor
	 *
	 * </p>
	 *
	 * @param leftNode
	 * @param rightNode
	 */
	protected OSnLNodeEq(OSnLNode leftNode, OSnLNode rightNode){
		m_mChildren = new OSnLNode[2];
		m_mChildren[0] = leftNode;
		m_mChildren[1] = rightNode;
	}//constructor

	/**
	 *
	 * Default Constructor
	 */
	protected OSnLNodeEq(){
		m_mChildren = new OSnLNode[2];
	}//constructor


	/**
	 * Calculate the result value of eq (or equal) relational operator given the current variable values.
	 *
	 * </p>
	 *
	 * @param x holds the values of the variables in a double array.
	 * @return the result value of eq (or equal to) relational operator given the current variable values.
	 */
	protected double calculateFunction(double[] x){
		double dLeft = m_mChildren[0].calculateFunction(x);
		double dRight = m_mChildren[1].calculateFunction(x);
		if((Double.isNaN(dLeft) && m_mChildren[0].m_sFunctionValue != null) &&
		   (Double.isNaN(dLeft) && m_mChildren[0].m_sFunctionValue != null)){
			String sLeft = m_mChildren[0].m_sFunctionValue;
			String sRight = m_mChildren[1].m_sFunctionValue;
			if( sLeft.equals(sRight)){
				m_dFunctionValue = OSnLNode.m_dTRUE;
			}
			else{
				m_dFunctionValue = OSnLNode.m_dFALSE;
			}			
		}	
		else{
			if( dLeft == dRight ){
				m_dFunctionValue = OSnLNode.m_dTRUE;
			}
			else{
				m_dFunctionValue = OSnLNode.m_dFALSE;
			}
		}
		return m_dFunctionValue;
	}//calculateFunction

	/**
	 * Calculate the function value given the current variable values.
	 * If the function has been evaluated over the current x values, the method will retrieve it.
	 *
	 * </p>
	 *
	 * @param x holds the values of the variables in a string array.
	 * @param functionEvaluated holds whether the function has been evaluated.
	 * @return the function derivative value given the current variable values in a string.
	 */
	protected String calculateFunction(String[] x, boolean functionEvaluated){
		String sLeft = m_mChildren[0].calculateFunction(x, functionEvaluated);
		String sRight = m_mChildren[1].calculateFunction(x, functionEvaluated);
		if( sLeft.equals(sRight)){
			m_sFunctionValue = OSnLNode.m_dTRUE + "";
		}
		else{
			m_sFunctionValue = OSnLNode.m_dFALSE + "";
		}			
		return m_sFunctionValue;
	}//calculateFunction - string based

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
		m_mChildren[0].m_dNodeDerivative = 0;
		if(dLeftValue ==  dRightValue){
			m_mChildren[0].m_dNodeDerivative = Double.NaN;
			m_mChildren[1].m_dNodeDerivative = Double.NaN;
		}
		else{
			m_mChildren[0].m_dNodeDerivative = m_dNodeDerivative * 0;
			m_mChildren[1].m_dNodeDerivative = m_dNodeDerivative * 0;
		}
		m_mChildren[0].propogateDerivatives(rootNode, x);
		m_mChildren[1].propogateDerivatives(rootNode, x);
	}//propogateDerivatives

	/**
	 * Calculate the result value of eq (or equal to) relational operator derivative given the current variable values.
	 *
	 * </p>
	 *
	 * @param x holds the values of the variables in a double array.
	 * @param functionEvaluated holds whether the function has been evaluated.
	 * @return the result value of eq (or equal to) relational operator derivative given the current variable values.
	 */
	protected double calculateDerivative(double[] x, int index, boolean functionEvaluated){
		double dDerivative;
		double dV0 = m_mChildren[0].calculateDerivative(x, index, functionEvaluated);
		double dV1 = m_mChildren[1].calculateDerivative(x, index, functionEvaluated);
		if(m_mChildren[0].calculateFunction(x, functionEvaluated) ==  m_mChildren[1].calculateFunction(x, functionEvaluated)){
			if(dV0 == 0 && dV1 == 0){
				dDerivative = 0;
			}
			else{
				dDerivative = Double.NaN;
			}
		}
		else{
			dDerivative = 0 * (dV0 + dV1);
		}
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

}//class OSnLNodeEq
