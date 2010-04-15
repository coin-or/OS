/**
 * @(#)OSnLNodeIdentifier 1.0 03/14/2004
 *
 */
package org.optimizationservices.oscommon.nonlinear;

import org.w3c.dom.Document;
import org.w3c.dom.Element;

/**
 *
 * <P>The <code>OSnLNodeIdentifier</code> class represents an identifier node in an expression tree, which is mainly
 * used for symbolic computation. It extends the abstract OSnLNode class and implements its abstract methods such as
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
public class OSnLNodeIdentifier extends OSnLNode{

	/**
	 * m_sSymbol holds the symbol that this nlNode looks in ASCII.
	 */
	protected String m_sSymbol = "identifier";

	/**
	 * m_sSymbol holds the description of this nlNode
	 */
	protected String m_sDescription = "An identifier";

	/**
	 * m_iSymbol holds the four digit integer that represents this nlNode, with the leftmost (first)
	 * integer representing the category and the right three digits representing a unique sequence number
	 * in the node category.
	 */
	protected int m_iSymbol = 5002;

	/**
	 * m_iType holds the integer representation of the type of this nlNode.
	 */
	protected int m_iType = 0;

	/**
	 * m_sIdentifierName holds the name of the identifier.
	 */
	protected String m_sIdentifierName = "";

	/**
	 * constructor
	 *
	 * </p>
	 *
	 * @param value holds the name of the identifier.
	 */
	protected OSnLNodeIdentifier(String identifierName){
		m_sIdentifierName = identifierName;
		m_sSymbol = "identifier:" + m_sIdentifierName;
	}//constructor

	/**
	 * default constructor
	 */
	protected OSnLNodeIdentifier(){
	}//constructor

	/**
	 * Calculate the result value of an identifier given the current variable values.
	 *
	 * </p>
	 *
	 * @param x holds the values of the variables in a double array.
	 * @return the result value of the identifier given the current variable values.
	 */
	protected double calculateFunction(double[] x){
		m_sFunctionValue = getIdentifierName();
		m_dFunctionValue = Double.NaN;
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
		m_sFunctionValue = getIdentifierName();
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
	}//propogateDerivatives

	/**
	 * Calculate the result value of a identifier's derivative given the current variable values.
	 *
	 * </p>
	 *
	 * @param x holds the values of the variables in a double array.
	 * @param functionEvaluated holds whether the function has been evaluated.
	 * @return the result value of the identifier's derivative given the current variable values.
	 */
	protected double calculateDerivative(double[] x, int index, boolean functionEvaluated){
		double dDerivative = 0;
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
		Element eRoot = document.createElement("identifier");
		String sAttrValue = getIdentifierName();
		if(sAttrValue != null && sAttrValue.length() > 0) eRoot.setAttribute("name", sAttrValue);
		else eRoot.setAttribute("value", "");
		OSnLNode[] mChildren = getChildNodes();
		for(int i = 0; i < ((mChildren == null)?0:mChildren.length); i++){
			Element eChild = mChildren[i].getDOMTree(document);
			eRoot.appendChild(eChild);
		}
		return eRoot;
	}//getDOMTree

	/**
	 *
	 * @return the name of the identifier.
	 */
	protected String getIdentifierName(){
		return m_sIdentifierName;
	}//getIdentifierName

	/**
	 * Set the value of the identifier.
	 *
	 * </p>
	 *
	 * @param identifierName holds the name of the identifier.
	 */
	protected void setIdentifierName(String identifierName){
		m_sIdentifierName = identifierName;
		m_sSymbol = "identifier:" + m_sIdentifierName;
	}//setIdentifierName

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

}//class OSnLNodeIdentifier
