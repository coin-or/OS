/**
 * @(#)OSnLNodeXPathIndex 1.0 03/14/2004
 *
 * Copyright (c) 2004
 */
package org.optimizationservices.oscommon.nonlinear;

import java.util.Vector;

import org.w3c.dom.Document;
import org.w3c.dom.Element;

/**
 *
 * <P>The <code>OSnLNodeXPathIndex</code> class represents an XPath index which is used by the XPath node to look up
 * a value given the index name and index value of the XPath index.
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
 * @see org.optimizationservices.oscommon.nonlinear.OSnLNodeXPath;
 * @since OS 1.0
 */
public class OSnLNodeXPathIndex extends OSnLNode{

	/**
	 * m_sSymbol holds the symbol that this nlNode looks in ASCII.
	 */
	protected String m_sSymbol = "xPathIndex";

	/**
	 * m_sSymbol holds the description of this nlNode
	 */
	protected String m_sDescription = "XPath index used by the XPath node to look up a value given the index name and index value of the XPath index.";

	/**
	 * m_iSymbol holds the four digit integer that represents this nlNode, with the leftmost (first)
	 * integer representing the category and the right three digits representing a unique sequence number
	 * in the node category.
	 */
	protected int m_iSymbol = 9009;

	/**
	 * m_iType holds the integer representation of the type of this nlNode.
	 */
	protected int m_iType = -1;

	/**
	 * m_sIndexName holds the xPath index name.
	 */
	protected String m_sIndexName = null;

	/**
	 * m_iIndexValue holds the index value of the index name.
	 */
	protected String m_sIndexValue = null;


	/**
	 * constructor
	 *
	 * </p>
	 *
	 * @param indexName holds the name of the xPath index.
	 * @param node holds the node operand as the XPathIndex node's index value, either a terminal node of a function.
	 */
	protected OSnLNodeXPathIndex(String indexName, OSnLNode node){
		m_mChildren = new OSnLNode[1];
		m_mChildren[0] = node;
		m_sIndexName = indexName;
		m_sSymbol = "xPathIndex:" + m_sIndexName;
	}//constructor

	/**
	 * Constructor
	 *
	 * </p>
	 *
	 * @param indexName holds the name of the xPath index.
	 * @param indexValue holds the index value of the index name.
	 * child of the element represented by the m_sIndexName.
	 */
	protected OSnLNodeXPathIndex(String indexName, String indexValue){
		m_sIndexName = indexName;
		m_sIndexValue = indexValue;
		m_sSymbol = "xPathIndex:" + m_sIndexName;
	}//constructor

	/**
	 *
	 * Default Constructor
	 */
	protected OSnLNodeXPathIndex(){
	}//constructor

	/**
	 * Calculate the result value of the XPathIndex given all the current variable values.
	 *
	 * </p>
	 *
	 * @param x holds the values of the variables in a double array.
	 * @return the result value of the XPath index given all the current variable values.
	 */
	protected double calculateFunction(double[] x){
		if(m_mChildren != null && m_mChildren.length == 1){
			m_dFunctionValue = m_mChildren[0].calculateFunction(x);
			if(Double.isNaN(m_dFunctionValue) && m_mChildren[0].m_sFunctionValue != null){
				m_sFunctionValue = m_mChildren[0].m_sFunctionValue;
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
			m_sFunctionValue = getIndexValue();
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
		if(m_mChildren != null && m_mChildren.length == 1){
			m_sFunctionValue = m_mChildren[0].calculateFunction(x, functionEvaluated);
		}
		else{
			m_sFunctionValue = getIndexValue();
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
		try{
			if(m_mChildren != null && m_mChildren.length > 0){
				m_mChildren[0].m_dNodeDerivative = m_dNodeDerivative;
				m_mChildren[0].propogateDerivatives(rootNode, x);
			}
		}
		catch(Exception e){
			e.printStackTrace();
		}
	}//propogateDerivatives

	/**
	 * Calculate the result value of the XPath index derivative given all the current variable values.
	 *
	 * </p>
	 *
	 * @param x holds the values of the variables in a double array.
	 * @param functionEvaluated holds whether the function has been evaluated.
	 * @return the result value of the XPath index derivative given all the current variable values.
	 */
	protected double calculateDerivative(double[] x, int index, boolean functionEvaluated){
		double dDerivative;
		if(m_mChildren != null & m_mChildren.length == 1){
			try{
				dDerivative = m_mChildren[0].calculateDerivative(x, index, functionEvaluated);
			}
			catch(Exception e){
				dDerivative = 0;
			}
		}
		else{
			dDerivative = 0;
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
		Element eRoot = document.createElement("xPathIndex");
		String sAttrValue = getIndexName();
		if(sAttrValue != null && sAttrValue.length() > 0) eRoot.setAttribute("indexName", sAttrValue);
		sAttrValue = getIndexValue();
		if(sAttrValue != null && sAttrValue.length() > 0) eRoot.setAttribute("indexValue", sAttrValue);
		OSnLNode[] mChildren = getChildNodes();
		for(int i = 0; i < ((mChildren == null)?0:mChildren.length); i++){
			Element eChild = mChildren[i].getDOMTree(document);
			eRoot.appendChild(eChild);
		}
		return eRoot;
	}//getDOMTree

	/**
	 * This is the recursive call. 
	 * @param vPostfix holds the vector to put in the postfix tokens. 
	 * @return the nonlinear expression starting with the current node in a postfix vector of operator symbols.
	 */
	protected Vector<String> getPostfix(Vector<String> vPostfix){
		String sSymbol = m_sSymbol;
		if(m_sIndexValue != null && m_sIndexValue.length() > 0) vPostfix.addElement(sSymbol + ":" + m_sIndexValue + "[0]");
		else{
			sSymbol += "[1]";
			for(int i = 0; i < ((m_mChildren == null)?0:m_mChildren.length); i++){
				m_mChildren[i].getPostfix(vPostfix);
			}
			vPostfix.addElement(sSymbol);
		}
		return vPostfix;
	}//getPostfix

	/**
	 * This is the recursive call. 
	 * @param vPrefix holds the vector to put in the prefix tokens. 
	 * @return the nonlinear expression starting with the current node in a prefix vector of operator symbols.
	 */
	protected Vector<String> getPrefix(Vector<String> vPrefix){
		String sSymbol = m_sSymbol;
		if(m_sIndexValue != null && m_sIndexValue.length() > 0) vPrefix.addElement(sSymbol + ":" + m_sIndexValue + "[0]");
		else{
			sSymbol += "[1]";
			vPrefix.addElement(sSymbol);
			for(int i = 0; i < ((m_mChildren == null)?0:m_mChildren.length); i++){
				m_mChildren[i].getPrefix(vPrefix);
			}
		}
		return vPrefix;
	}//getPrefix

	/**
	 * This is the recursive call. 
	 * @param vInfix holds the vector to put in the infix tokens. 
	 * @return the nonlinear expression starting with the current node in an infix vector of operator symbols.
	 */
	protected Vector<String> getInfix(Vector<String> vInfix){
		String sSymbol = m_sSymbol;
		if(m_sIndexValue != null && m_sIndexValue.length() > 0) vInfix.addElement(sSymbol + ":" + m_sIndexValue + "[0]");
		else{
			sSymbol += "[1]";
			vInfix.addElement(sSymbol);
			if(m_mChildren != null) vInfix.addElement("(");
			for(int i = 0; i < ((m_mChildren == null)?0:m_mChildren.length); i++){
				m_mChildren[i].getInfix(vInfix);
			}
			if(m_mChildren != null) vInfix.addElement(")");
		}
		return vInfix;
	}//getInfix

	/**
	 *
	 * @return the xPath index name.
	 */
	protected String getIndexName(){
		return m_sIndexName;
	}//getIndexName

	/**
	 * Set the xPath index name.
	 *
	 * </p>
	 *
	 * @param indexName holds the xPath index name, which usually correspond to a name of an xml element.
	 */
	protected void setIndexName(String indexName){
		m_sIndexName = indexName;
		m_sSymbol = "xPathIndex:" + m_sIndexName;
	}//setIndexName

	/**
	 *
	 * @return the xPath index value.
	 */
	protected String getIndexValue(){
		return m_sIndexValue;
	}//getINdexValue

	/**
	 * Set the the xPath index value.
	 *
	 * </p>
	 *
	 * @param indexValue holds the xPath index value.
	 */
	protected void setIndexValue(String indexValue){
		m_sIndexValue = indexValue;
	}//setIndexValue

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

}//class OSnLNodeXPathIndex