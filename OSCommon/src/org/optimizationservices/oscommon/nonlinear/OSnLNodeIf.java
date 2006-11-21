/**
 * @(#)OSnLNodeIf 1.0 03/14/2004
 *
 * Copyright (c) 2004
 */
package org.optimizationservices.oscommon.nonlinear;

/**
 *
 * <P>The <code>OSnLNodeIf</code> class represents an if-then-else conditional logic node in an expression tree.
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
public class OSnLNodeIf extends OSnLNode{

	/**
	 * m_sSymbol holds the symbol that this nlNode looks in ASCII.
	 */
	protected String m_sSymbol = "if";

	/**
	 * m_sSymbol holds the description of this nlNode
	 */
	protected String m_sDescription = "If-then-else conditional logic node";

	/**
	 * m_iSymbol holds the four digit integer that represents this nlNode, with the leftmost (first)
	 * integer representing the category and the right three digits representing a unique sequence number
	 * in the node category.
	 */
	protected int m_iSymbol = 7001;

	/**
	 * m_iType holds the integer representation of the type of this nlNode.
	 */
	protected int m_iType = 3;

	/**
	 * constructor
	 *
	 * </p>
	 *
	 * @param ifNode
	 * @param thenNode
	 * @param elseNode
	 */
	protected OSnLNodeIf(OSnLNode ifNode, OSnLNode thenNode, OSnLNode elseNode){
		m_mChildren = new OSnLNode[3];
		m_mChildren[0] = ifNode;
		m_mChildren[1] = thenNode;
		m_mChildren[2] = elseNode;
	}//constructor

	/**
	 *
	 * Default Constructor
	 */
	protected OSnLNodeIf(){
		m_mChildren = new OSnLNode[3];
	}//constructor


	/**
	 * Calculate the result value of if-then-else logic given the current variable values.
	 *
	 * </p>
	 *
	 * @param x holds the values of the variables in a double array.
	 * @return the result value of if-then-else logic given the current variable values.
	 */
	protected double calculateFunction(double[] x){
		if(m_mChildren[0].calculateFunction(x) > 0){
			m_dFunctionValue = m_mChildren[1].calculateFunction(x);
			if(Double.isNaN(m_dFunctionValue) && m_mChildren[1].m_sFunctionValue != null){
				m_sFunctionValue = m_mChildren[1].m_sFunctionValue;
				try{
					m_dFunctionValue = Double.parseDouble(m_sFunctionValue);
					m_sFunctionValue = null;
				}
				catch(Exception e){
					m_dFunctionValue = Double.NaN;
				}			
			}
		}
		else{
			m_dFunctionValue = m_mChildren[2].calculateFunction(x);
			if(Double.isNaN(m_dFunctionValue) && m_mChildren[2].m_sFunctionValue != null){
				m_sFunctionValue = m_mChildren[2].m_sFunctionValue;
				try{
					m_dFunctionValue = Double.parseDouble(m_sFunctionValue);
					m_sFunctionValue = null;
				}
				catch(Exception e){
					m_dFunctionValue = Double.NaN;
				}			
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
		if(functionEvaluated) return m_sFunctionValue;
		if(m_mChildren[0].calculateFunction(x, functionEvaluated).equals(OSnLNode.m_dTRUE + "")){
			m_sFunctionValue = m_mChildren[1].calculateFunction(x, functionEvaluated);
		}
		else{
			m_sFunctionValue = m_mChildren[2].calculateFunction(x, functionEvaluated);
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
		double dFirstValue = m_mChildren[0].calculateFunction(x, true);
		if(dFirstValue > 0){
			m_mChildren[1].m_dNodeDerivative = m_dNodeDerivative;
			m_mChildren[2].m_dNodeDerivative = 0;
		}
		else{
			m_mChildren[1].m_dNodeDerivative = 0;
			m_mChildren[2].m_dNodeDerivative = m_dNodeDerivative;
		}
		m_mChildren[1].propogateDerivatives(rootNode, x);
		m_mChildren[2].propogateDerivatives(rootNode, x);
	}//propogateDerivatives

	/**
	 * Calculate the result value of if-then-else logic derivative given the current variable values.
	 *
	 * </p>
	 *
	 * @param x holds the values of the variables in a double array.
	 * @param functionEvaluated holds whether the function has been evaluated.
	 * @return the result value of if-then-else logic derivative given the current variable values.
	 */
	protected double calculateDerivative(double[] x, int index, boolean functionEvaluated){
		double dDerivative;
		double dFirst = m_mChildren[0].calculateFunction(x, functionEvaluated);
		double dSecond = m_mChildren[1].calculateFunction(x, functionEvaluated);
		double dThird = m_mChildren[2].calculateFunction(x, functionEvaluated);
		double dFirstDerivative = m_mChildren[0].calculateDerivative(x, index, functionEvaluated);
		double dSecondDerivative = m_mChildren[1].calculateDerivative(x, index, functionEvaluated);
		double dThirdDerivative = m_mChildren[2].calculateDerivative(x, index, functionEvaluated);
		if(dFirst == OSnLNode.m_dTRUE){
			if(dFirstDerivative == Double.NEGATIVE_INFINITY || dFirstDerivative == Double.NaN){
				if(dSecond < dThird) dDerivative = Double.POSITIVE_INFINITY;
				if(dSecond == dThird) dDerivative = (dSecondDerivative + dThirdDerivative) / 2;
				else dDerivative = Double.NEGATIVE_INFINITY;
			}
			else dDerivative = dSecondDerivative;
		}
		else if(dFirst == OSnLNode.m_dFALSE){
			if(dFirstDerivative == Double.POSITIVE_INFINITY || dFirstDerivative == Double.NaN){
				if(dSecond < dThird) dDerivative = Double.NEGATIVE_INFINITY;
				if(dSecond == dThird) dDerivative = (dSecondDerivative + dThirdDerivative) / 2;
				else dDerivative = Double.POSITIVE_INFINITY;
			}
			else dDerivative = dThirdDerivative;
		}
		else if(dFirst > 0){
			if(Double.isNaN(dFirstDerivative) || dFirstDerivative == Double.NEGATIVE_INFINITY){
				dDerivative = Double.NaN;
			}
			else{
				dDerivative = dSecondDerivative;
			}
		}
		else if(dFirst ==  0){
			if(dFirstDerivative < 0){
				if(dSecond < dThird) dDerivative = Double.POSITIVE_INFINITY;
				if(dSecond == dThird) dDerivative = (dSecondDerivative + dThirdDerivative) / 2;
				else dDerivative = Double.NEGATIVE_INFINITY;
			}
			else if(dFirstDerivative > 0){
				if(dSecond < dThird) dDerivative = Double.NEGATIVE_INFINITY;
				if(dSecond == dThird) dDerivative = (dSecondDerivative + dThirdDerivative) / 2;
				else dDerivative = Double.POSITIVE_INFINITY;
			}
			else if(Double.isNaN(dFirstDerivative)) dDerivative = Double.NaN;
			else dDerivative = dThirdDerivative;
		}
		else{
			if(Double.isNaN(dFirstDerivative) || dFirstDerivative == Double.POSITIVE_INFINITY){
				dDerivative = Double.NaN;
			}
			else{
				dDerivative = dThirdDerivative;
			}
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

}//class OSnLNodeIf
