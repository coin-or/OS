/**
 * @(#)OSnLNodeArg 1.0 03/14/2004
 *
 * Copyright (c) 2004
 */
package org.optimizationservices.oscommon.nonlinear;

import org.w3c.dom.Document;
import org.w3c.dom.Element;

/**
 *
 * <P>The <code>OSnLNodeArg</code> class represents an argument node in an expression tree, which is usually used in the
 * definition of a user function rather than directly in a function expression tree. It extends the abstract OSnLNode class and implements its abstract methods such as
 * calculateFunction(double[]).
 * </p>
 *
 * </p>
 *
 * @author Robert Fourer, Jun Ma, Kipp Martin
 * @version 1.0, 03/14/2004
 * @see org.optimizationservices.oscommon.nonlinear.OSExpressionTree;
 * @see org.optimizationservices.oscommon.nonlinear.OSnLNode;
 * @see org.optimizationservices.oscommon.nonlinear.OSnLNodeUserF;
 * @since OS 1.0
 */
public class OSnLNodeArg extends OSnLNode{

	/**
	 * m_sSymbol holds the symbol that this nlNode looks in ASCII.
	 */
	protected String m_sSymbol = "arg";

	/**
	 * m_sSymbol holds the description of this nlNode
	 */
	protected String m_sDescription = "An argument node used mainly for defining a function";

	/**
	 * m_iSymbol holds the four digit integer that represents this nlNode, with the leftmost (first)
	 * integer representing the category and the right three digits representing a unique sequence number
	 * in the node category.
	 */
	protected int m_iSymbol = 9007;

	/**
	 * m_iType holds the integer representation of the type of this nlNode.
	 */
	protected int m_iType = 0;

	/**
	 * m_iArgIdx holds the integer index of the argment.
	 */
	protected int m_iArgIdx;

	/**
	 * constructor
	 *
	 * </p>
	 *
	 * @param value holds the integer index of the argument.
	 */
	protected OSnLNodeArg(int argIdx){
		m_iArgIdx = argIdx;
		m_sSymbol = "arg"+m_iArgIdx;
	}//constructor

	/**
	 * default constructor
	 */
	protected OSnLNodeArg(){
	}//constructor

	/**
	 * Calculate the result value of an argument node given the current variable values.
	 *
	 * </p>
	 *
	 * @param x holds the values of the variables in a double array.
	 * @return the result value of the argument node given the current variable values.
	 */
	protected double calculateFunction(double[] x){
		if(OSnLNode.m_iEvaluateUserFunctionArguments == 0) return 0.0;
		m_dFunctionValue = x[m_iArgIdx];
		if(Double.isNaN(m_dFunctionValue) && m_sFunctionValue != null){
			try{
				m_dFunctionValue = Double.parseDouble(m_sFunctionValue);
				m_sFunctionValue = null;
			}
			catch(Exception e){
				m_dFunctionValue = Double.NaN;
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
		if(OSnLNode.m_iEvaluateUserFunctionArguments == 0) return null;
		if(functionEvaluated) return m_sFunctionValue;
		m_sFunctionValue = x[m_iArgIdx];
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
		if(OSnLNode.m_iEvaluateUserFunctionArguments == 0) return;
		double dXDerivative = rootNode.m_mapDerivativeValues.get(m_iArgIdx);
		dXDerivative += m_dNodeDerivative;
		if(dXDerivative != 0) rootNode.m_mapDerivativeValues.put(m_iArgIdx, dXDerivative);
	}//propogateDerivatives


	/**
	 * Calculate the result value of a argument node's derivative given the current variable values.
	 *
	 * </p>
	 *
	 * @param x holds the values of the variables in a double array.
	 * @param functionEvaluated holds whether the function has been evaluated.
	 * @return the result value of the argument node's derivative given the current variable values.
	 */
	protected double calculateDerivative(double[] x, int index, boolean functionEvaluated){
		if(OSnLNode.m_iEvaluateUserFunctionArguments == 0) return 0.0;		
		double dDerivative = 0;
		if(m_iArgIdx == index){
			dDerivative = 1;
		}
		return dDerivative;
	}//calculateDerivative

	/**
	 *
	 * @param document holds the W3C DOM type document to create XML elements and attributes.
	 * It is the parent of the root element, e.g. the &lt;OSiL&gt; element in OSiL. It is used
	 * to create all the nodes in the DOM tree.
	 * @return the nonlinear expression starting with the current node in an XML DOM Tree.
	 */
	protected Element getDOMTree(Document document){
		Element eRoot = document.createElement("arg");
		String sAttrValue = getArgumentIndex() + "";
		if(sAttrValue != null && sAttrValue.length() > 0) eRoot.setAttribute("idx", sAttrValue);
		OSnLNode[] mChildren = getChildNodes();
		for(int i = 0; i < ((mChildren == null)?0:mChildren.length); i++){
			Element eChild = mChildren[i].getDOMTree(document);
			eRoot.appendChild(eChild);
		}
		return eRoot;
	}//getDOMTree

	/**
	 *
	 * @return the index value of the argument.
	 */
	protected int getArgumentIndex(){
		return m_iArgIdx;
	}//getArgumentIndex

	/**
	 * Set the index value of the argument.
	 *
	 * </p>
	 *
	 * @param argIndex holds the index of the argument.
	 */
	protected void setArgumentIndex(int argIndex){
		m_iArgIdx = argIndex;
		m_sSymbol = "arg"+m_iArgIdx;
	}//setArgumentIndex

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

}//class OSnLNodeArg
