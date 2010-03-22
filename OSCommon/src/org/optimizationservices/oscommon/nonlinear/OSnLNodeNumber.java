/**
 * @(#)OSnLNodeNumber 1.0 03/14/2004
 *
 * Copyright (c) 2004
 */
package org.optimizationservices.oscommon.nonlinear;

import org.w3c.dom.Document;
import org.w3c.dom.Element;

/**
 *
 * <P>The <code>OSnLNodeNumber</code> class represents a number node in an expression tree.
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
public class OSnLNodeNumber extends OSnLNode{

	/**
	 * m_sSymbol holds the symbol that this nlNode looks in ASCII.
	 */
	protected String m_sSymbol = "number";

	/**
	 * m_sSymbol holds the description of this nlNode
	 */
	protected String m_sDescription = "A number";

	/**
	 * m_iSymbol holds the four digit integer that represents this nlNode, with the leftmost (first)
	 * integer representing the category and the right three digits representing a unique sequence number
	 * in the node category.
	 */
	protected int m_iSymbol = 5001;

	/**
	 * m_iType holds the integer representation of the type of this nlNode.
	 */
	protected int m_iType = 0;

	/**
	 * m_sNumberType holds the type of the number: real, string, or random.
	 */
	protected String m_sNumberType = "real";

	/**
	 * m_sNumberValue holds the value of the number in a string.
	 */
	protected String m_sNumberValue = null;

	/**
	 * m_sID holds a unique id of the number so that it can be referred.
	 */
	protected String m_sID = "";

	/**
	 * constructor
	 *
	 * </p>
	 *
	 * @param id holds a unique id of the number so that it can be referred. If null, no ID will be set.
	 * @param value holds the value of the number in a string.
	 * @param numberType holds the type of the number: real, string or random.
	 * no distribution name will be set.
	 */
	protected OSnLNodeNumber(String id, String value, String numberType){
		m_sNumberValue = value;
		m_sSymbol = m_sNumberValue;
		if(!numberType.equalsIgnoreCase("real")
				&& !numberType.equalsIgnoreCase("string")
				&& !numberType.equalsIgnoreCase("random")) m_sNumberType = "real";
		if(id != null && id.length() > 0){
			m_sID = id;
		}
		if(!m_sNumberType.equals("real") || (m_sID != null && m_sID.length() > 0)){
			m_sSymbol = m_sNumberValue + ":" + m_sNumberType + ":" + m_sID;
		}
		else m_sNumberType = numberType;
	}//constructor

	/**
	 * default constructor
	 */
	protected OSnLNodeNumber(){
	}//constructor

	/**
	 * Calculate the result value of a number given the current variable values.
	 *
	 * </p>
	 *
	 * @param x holds the values of the variables in a double array.
	 * @return the result value of the number given the current variable values.
	 */
	protected double calculateFunction(double[] x){
		if(!Double.isNaN(m_dFunctionValue)) return m_dFunctionValue;
		if(getNumberType().equals("string")){
			m_dFunctionValue = Double.NaN;
			m_sFunctionValue = m_sNumberValue;
		}
		else{
			try{
				m_dFunctionValue = Double.parseDouble(m_sNumberValue);
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
		if(functionEvaluated) return m_sFunctionValue;
		m_sFunctionValue = m_sNumberValue;
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
	 * Calculate the result value of a number's derivative given the current variable values.
	 *
	 * </p>
	 *
	 * @param x holds the values of the variables in a double array.
	 * @param functionEvaluated holds whether the function has been evaluated.
	 * @return the result value of the number's derivative given the current variable values.
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
		Element eRoot = document.createElement("number");
		String sAttrValue = getNumberValue();
		if(sAttrValue != null && sAttrValue.length() > 0) eRoot.setAttribute("value", sAttrValue);
		else eRoot.setAttribute("value", "0");
		sAttrValue = getNumberType();
		if(sAttrValue != null && sAttrValue.length() > 0 && !sAttrValue.equals("real")) eRoot.setAttribute("type", sAttrValue);
		sAttrValue = getNumberID();
		if(sAttrValue != null && sAttrValue.length() > 0) eRoot.setAttribute("id", sAttrValue);
		OSnLNode[] mChildren = getChildNodes();
		for(int i = 0; i < ((mChildren == null)?0:mChildren.length); i++){
			Element eChild = mChildren[i].getDOMTree(document);
			eRoot.appendChild(eChild);
		}
		return eRoot;
	}//getDOMTree

	/**
	 *
	 * @return the value of the number in a string.
	 */
	protected String getNumberValue(){
		return m_sNumberValue;
	}//getNumberValue

	/**
	 * Set the value of the number.
	 *
	 * </p>
	 *
	 * @param value holds the value of the number.
	 */
	protected void setNumberValue(String value){
		m_sNumberValue = value;
		m_sSymbol = m_sNumberValue;
		if(!m_sNumberType.equals("real") || (m_sID != null && m_sID.length() > 0)){
			m_sSymbol = m_sNumberValue + ":" + m_sNumberType + ":" + m_sID;
		}
	}//setNumberValue

	/**
	 *
	 * @return the type of the number: real, string, or random.
	 */
	protected String getNumberType(){
		return m_sNumberType;
	}//getNumberType

	/**
	 * Set the type of the number: real, string, or random.
	 * If none of these types, the method defaults to real.
	 *
	 * </p>
	 *
	 * @param type holds the type of the number: real, string or random.
	 */
	protected void setNumberType(String type){
		if(!type.equalsIgnoreCase("real")
				&& !type.equalsIgnoreCase("string")
				&& !type.equalsIgnoreCase("random")) m_sNumberType = "real";
		if(!m_sNumberType.equals("real") || (m_sID != null && m_sID.length() > 0)){
			m_sSymbol = m_sNumberValue + ":" + m_sNumberType + ":" + m_sID;
		}
		else m_sNumberType = type;
	}//setNumberType

	/**
	 *
	 * @return the unique id of the number so that it can be referred.
	 */
	protected String getNumberID(){
		return m_sID;
	}//getNumberID

	/**
	 * Set the unique id of the number so that it can be referred.
	 *
	 * </p>
	 *
	 * @param id holds the unique id of the number so that it can be referred.
	 */
	protected void setNumberID(String id){
		if(id != null && id.length() > 0){
			m_sID = id;
			if(!m_sNumberType.equals("real") || (m_sID != null && m_sID.length() > 0)){
				m_sSymbol = m_sNumberValue + ":" + m_sNumberType + ":" + m_sID;
			}
		}
	}//setNumberID

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

}//class OSnLNodeNumber
