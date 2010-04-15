/**
 * @(#)OSnLNodeOr 1.0 03/14/2004
 *
 * Copyright (c) 2004
 */
package org.optimizationservices.oscommon.nonlinear;

/**
 *
 * <P>The <code>OSnLNodeOr</code> class represents an or conditional logic node in an expression tree.
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
public class OSnLNodeOr extends OSnLNode{

	/**
	 * m_sSymbol holds the symbol that this nlNode looks in ASCII.
	 */
	protected String m_sSymbol = "or";

	/**
	 * m_sSymbol holds the description of this nlNode
	 */
	protected String m_sDescription = "Or conditional logic node";

	/**
	 * m_iSymbol holds the four digit integer that represents this nlNode, with the leftmost (first)
	 * integer representing the category and the right three digits representing a unique sequence number
	 * in the node category.
	 */
	protected int m_iSymbol = 7009;

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
	protected OSnLNodeOr(OSnLNode leftNode, OSnLNode rightNode){
		m_mChildren = new OSnLNode[2];
		m_mChildren[0] = leftNode;
		m_mChildren[1] = rightNode;
	}//constructor

	/**
	 *
	 * Default Constructor
	 */
	protected OSnLNodeOr(){
		m_mChildren = new OSnLNode[2];
	}//constructor


	/**
	 * Calculate the result value of or conditional logic operator given the current variable values.
	 *
	 * </p>
	 *
	 * @param x holds the values of the variables in a double array.
	 * @return the result value of or conditional logic operator given the current variable values.
	 */
	protected double calculateFunction(double[] x){
		if(m_mChildren[0].calculateFunction(x) > 0 ||
				m_mChildren[1].calculateFunction(x) > 0){
			m_dFunctionValue = OSnLNode.m_dTRUE;
		}
		else{
			m_dFunctionValue = OSnLNode.m_dFALSE;
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
		m_mChildren[0].m_dNodeDerivative = Double.NaN;
		m_mChildren[1].m_dNodeDerivative = Double.NaN;
		m_mChildren[0].propogateDerivatives(rootNode, x);
		m_mChildren[1].propogateDerivatives(rootNode, x);
	}//propogateDerivatives

	/**
	 * Calculate the result value of or conditional logic operator derivative given the current variable values.
	 *
	 * </p>
	 *
	 * @param x holds the values of the variables in a double array.
	 * @param functionEvaluated holds whether the function has been evaluated.
	 * @return the result value of or conditional logic operator derivative given the current variable values.
	 */
	protected double calculateDerivative(double[] x, int index, boolean functionEvaluated){
		double dDerivative;
		double dLeft = m_mChildren[0].calculateFunction(x, functionEvaluated);
		double dRight = m_mChildren[1].calculateFunction(x, functionEvaluated);
		double dLeftDerivative = m_mChildren[0].calculateDerivative(x, index, functionEvaluated);
		double dRightDerivative = m_mChildren[1].calculateDerivative(x, index, functionEvaluated);
		//(left, right) in {Boolean, Boolean}
		if(dLeft == OSnLNode.m_dTRUE && dRight == OSnLNode.m_dTRUE){
			if(Double.isNaN(dLeftDerivative) && Double.isNaN(dRightDerivative)) dDerivative = Double.NaN;
			else if(dLeftDerivative == Double.POSITIVE_INFINITY && dRightDerivative == Double.POSITIVE_INFINITY) dDerivative = Double.POSITIVE_INFINITY;
			else if(!(dLeftDerivative >=0) &&  !(dRightDerivative >= 0)) dDerivative = Double.NEGATIVE_INFINITY;
			else dDerivative = 0;
		}
		else if(dLeft == OSnLNode.m_dTRUE && dRight == OSnLNode.m_dFALSE){
			if(Double.isNaN(dLeftDerivative) && dRightDerivative == 0) dDerivative = Double.NaN;
			else if(dLeftDerivative == Double.POSITIVE_INFINITY && dRightDerivative != Double.NEGATIVE_INFINITY) dDerivative = Double.POSITIVE_INFINITY;
			else if(!(dLeftDerivative >= 0) && dRightDerivative <= 0) dDerivative = Double.NEGATIVE_INFINITY;
			else dDerivative = 0;
		}
		else if(dLeft == OSnLNode.m_dFALSE && dRight == OSnLNode.m_dTRUE){
			if(Double.isNaN(dRightDerivative) && dLeftDerivative == 0) dDerivative = Double.NaN;
			else if(dRightDerivative == Double.POSITIVE_INFINITY && dLeftDerivative != Double.NEGATIVE_INFINITY) dDerivative = Double.POSITIVE_INFINITY;
			else if(!(dRightDerivative >= 0) && dLeftDerivative <= 0) dDerivative = Double.NEGATIVE_INFINITY;
			else dDerivative = 0;
		}
		else if(dLeft == OSnLNode.m_dFALSE && dRight == OSnLNode.m_dFALSE){
			if((dLeftDerivative == Double.POSITIVE_INFINITY && dRightDerivative != Double.NEGATIVE_INFINITY) ||
					(dRightDerivative == Double.POSITIVE_INFINITY && dLeftDerivative != Double.NEGATIVE_INFINITY)) dDerivative = Double.POSITIVE_INFINITY;
			else if(dLeftDerivative <= 0 && dRightDerivative <= 0 && !(dLeftDerivative == 0 && dRightDerivative == 0)) dDerivative = Double.NEGATIVE_INFINITY;
			else if(!Double.isInfinite(dLeftDerivative) && !Double.isInfinite(dRightDerivative) && !(dLeftDerivative == 0 && dRightDerivative == 0)) dDerivative = Double.NaN;
			else dDerivative = 0;
		}
		//(left, right) in {Boolean, Real}
		else if(dLeft == OSnLNode.m_dTRUE && dRight > 0){
			if(!(dLeftDerivative >= 0) && !(dRightDerivative > Double.NEGATIVE_INFINITY)) dDerivative = Double.NaN;
			else dDerivative = 0;
		}
		else if(dLeft == OSnLNode.m_dTRUE && dRight == 0){
			if(dLeftDerivative == Double.POSITIVE_INFINITY && !(dRightDerivative < 0)) dDerivative = Double.POSITIVE_INFINITY;
			else if((Double.isNaN(dRightDerivative) && dLeftDerivative != 0) || (Double.isNaN(dLeftDerivative) && dRightDerivative == 0)) dDerivative = Double.NaN;
			else if((dLeftDerivative == Double.NEGATIVE_INFINITY || Double.isNaN(dLeftDerivative)) && !(dRightDerivative > 0)) dDerivative = Double.NEGATIVE_INFINITY;
			else dDerivative = 0;
		}
		else if(dLeft == OSnLNode.m_dTRUE && dRight < 0){
			if(dLeftDerivative == Double.POSITIVE_INFINITY) dDerivative = Double.POSITIVE_INFINITY;
			else if(dLeftDerivative == Double.NEGATIVE_INFINITY && dRightDerivative < Double.POSITIVE_INFINITY) dDerivative = Double.NEGATIVE_INFINITY;
			else if(Double.isNaN(dLeftDerivative) || dLeftDerivative == Double.NEGATIVE_INFINITY) dDerivative = Double.NaN;
			else dDerivative = 0;
		}
		else if(dLeft == OSnLNode.m_dFALSE && dRight > 0){
			if(dLeftDerivative <= 0 && !(dRightDerivative > Double.NEGATIVE_INFINITY)) dDerivative = Double.NaN;
			else dDerivative = 0;
		}
		else if(dLeft == OSnLNode.m_dFALSE && dRight == 0){
			if((Double.isNaN(dRightDerivative) && dLeftDerivative != Double.POSITIVE_INFINITY) ||
					(Double.isNaN(dLeftDerivative) && dRightDerivative == 0)) dDerivative = Double.NaN;
			else if((dLeftDerivative <= 0 && dRightDerivative <= 0) && !(dLeftDerivative == 0 && dRightDerivative == 0)) dDerivative = Double.NEGATIVE_INFINITY;
			else if((dLeftDerivative == Double.POSITIVE_INFINITY && Double.isNaN(dRightDerivative)) ||
					(dLeftDerivative == Double.POSITIVE_INFINITY && dRightDerivative == 0) ||
					(dRightDerivative > 0 && dLeftDerivative != Double.NEGATIVE_INFINITY)) dDerivative = Double.POSITIVE_INFINITY;
			else dDerivative = 0;
		}
		else if(dLeft == OSnLNode.m_dFALSE && dRight < 0){
			if(dLeftDerivative == Double.POSITIVE_INFINITY) dDerivative = Double.POSITIVE_INFINITY;
			else if(dLeftDerivative == Double.NEGATIVE_INFINITY && dRightDerivative < Double.POSITIVE_INFINITY) dDerivative = Double.NEGATIVE_INFINITY;
			else if(Double.isNaN(dLeftDerivative) || Double.isNaN(dRightDerivative) || dRightDerivative == Double.POSITIVE_INFINITY) dDerivative = Double.NaN;
			else dDerivative = 0;
		}
		//(left, right) in {Real, Boolean}
		else if(dLeft > 0 && dRight == OSnLNode.m_dTRUE){
			if(!(dRightDerivative >= 0) && !(dLeftDerivative > Double.NEGATIVE_INFINITY)) dDerivative = Double.NaN;
			else dDerivative = 0;
		}
		else if(dLeft == 0 && dRight == OSnLNode.m_dTRUE){
			if(dRightDerivative == Double.POSITIVE_INFINITY && !(dLeftDerivative < 0)) dDerivative = Double.POSITIVE_INFINITY;
			else if((Double.isNaN(dLeftDerivative) && dRightDerivative != 0) || (Double.isNaN(dRightDerivative) && dLeftDerivative == 0)) dDerivative = Double.NaN;
			else if((dRightDerivative == Double.NEGATIVE_INFINITY || Double.isNaN(dRightDerivative)) && !(dLeftDerivative > 0)) dDerivative = Double.NEGATIVE_INFINITY;
			else dDerivative = 0;
		}
		else if(dLeft < 0 && dRight == OSnLNode.m_dTRUE){
			if(dRightDerivative == Double.POSITIVE_INFINITY) dDerivative = Double.POSITIVE_INFINITY;
			else if(dRightDerivative == Double.NEGATIVE_INFINITY && dLeftDerivative < Double.POSITIVE_INFINITY) dDerivative = Double.NEGATIVE_INFINITY;
			else if(Double.isNaN(dRightDerivative) || dRightDerivative == Double.NEGATIVE_INFINITY) dDerivative = Double.NaN;
			else dDerivative = 0;
		}
		else if(dLeft > 0 && dRight == OSnLNode.m_dFALSE){
			if(dRightDerivative <= 0 && !(dLeftDerivative > Double.NEGATIVE_INFINITY)) dDerivative = Double.NaN;
			else dDerivative = 0;
		}
		else if(dLeft == 0 && dRight == OSnLNode.m_dFALSE){
			if((Double.isNaN(dLeftDerivative) && dRightDerivative != Double.POSITIVE_INFINITY) ||
					(Double.isNaN(dRightDerivative) && dLeftDerivative == 0)) dDerivative = Double.NaN;
			else if((dRightDerivative <= 0 && dLeftDerivative <= 0) && !(dRightDerivative == 0 && dLeftDerivative == 0)) dDerivative = Double.NEGATIVE_INFINITY;
			else if((dRightDerivative == Double.POSITIVE_INFINITY && Double.isNaN(dLeftDerivative)) ||
					(dRightDerivative == Double.POSITIVE_INFINITY && dLeftDerivative == 0) ||
					(dLeftDerivative > 0 && dRightDerivative != Double.NEGATIVE_INFINITY)) dDerivative = Double.POSITIVE_INFINITY;
			else dDerivative = 0;
		}
		else if(dLeft < 0 && dRight == OSnLNode.m_dFALSE){
			if(dRightDerivative == Double.POSITIVE_INFINITY) dDerivative = Double.POSITIVE_INFINITY;
			else if(dRightDerivative == Double.NEGATIVE_INFINITY && dLeftDerivative < Double.POSITIVE_INFINITY) dDerivative = Double.NEGATIVE_INFINITY;
			else if(Double.isNaN(dRightDerivative) || Double.isNaN(dLeftDerivative) || dLeftDerivative == Double.POSITIVE_INFINITY) dDerivative = Double.NaN;
			else dDerivative = 0;
		}
		//(left, right) in {Real, Real}
		else if(dLeft < 0 && dRight < 0){
			if((Double.isNaN(dLeftDerivative) || dLeftDerivative == Double.POSITIVE_INFINITY) ||
					(Double.isNaN(dRightDerivative) || dRightDerivative == Double.POSITIVE_INFINITY)) dDerivative = Double.NaN;
			else dDerivative = 0;
		}
		else if(dLeft < 0 && dRight == 0){
			if(dRightDerivative > 0) dDerivative = Double.POSITIVE_INFINITY;
			else if(dRightDerivative < 0 && dLeftDerivative != Double.POSITIVE_INFINITY && !Double.isNaN(dLeftDerivative)) dDerivative = Double.NEGATIVE_INFINITY;
			else if(Double.isNaN(dRightDerivative) || dLeftDerivative == Double.POSITIVE_INFINITY || Double.isNaN(dLeftDerivative)) dDerivative = Double.NaN;
			else dDerivative = 0;
		}
		else if(dLeft == 0 && dRight < 0){
			if(dLeftDerivative > 0) dDerivative = Double.POSITIVE_INFINITY;
			else if(dLeftDerivative < 0 && dRightDerivative != Double.POSITIVE_INFINITY && !Double.isNaN(dRightDerivative)) dDerivative = Double.NEGATIVE_INFINITY;
			else if(Double.isNaN(dLeftDerivative) || dRightDerivative == Double.POSITIVE_INFINITY || Double.isNaN(dRightDerivative)) dDerivative = Double.NaN;
			else dDerivative = 0;
		}
		else if(dLeft == 0 && dRight == 0){
			if(Double.isNaN(dLeftDerivative) && !(dRightDerivative > 0) ||
					(Double.isNaN(dRightDerivative) && !(dLeftDerivative > 0))) dDerivative = Double.NaN;
			else if(dLeftDerivative <= 0 && dRightDerivative <= 0 && !(dLeftDerivative == 0 && dRightDerivative == 0)) dDerivative = Double.NEGATIVE_INFINITY;
			else if(Double.isNaN(dLeftDerivative) || Double.isNaN(dRightDerivative) ||
					(dLeftDerivative >= 0 && dRightDerivative >= 0 && !(dLeftDerivative == 0 && dRightDerivative == 0))) dDerivative = Double.POSITIVE_INFINITY;
			else dDerivative = 0;
		}
		else{
			if(!(dLeftDerivative > Double.NEGATIVE_INFINITY) && !(dRightDerivative > Double.NEGATIVE_INFINITY)) dDerivative = Double.NaN;
			else dDerivative = 0;
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

}//class OSnLNodeOr
