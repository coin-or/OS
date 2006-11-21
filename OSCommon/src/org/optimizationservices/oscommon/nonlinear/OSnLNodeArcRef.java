/**
 * @(#)OSnLNodeArcRef 1.0 03/14/2004
 *
 * Copyright (c) 2004
 */
package org.optimizationservices.oscommon.nonlinear;

import org.w3c.dom.Document;
import org.w3c.dom.Element;

/**
 *
 * <P>The <code>OSnLNodeArcRef</code> class represents a network arc reference. An arcRef node
 * is used to get and set values from a network arc.
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
 * @see org.optimizationservices.oscommon.nonlinear.OSnLNodeNodeRef;
 * @since OS 1.0
 */
public class OSnLNodeArcRef extends OSnLNode{

	/**
	 * m_sSymbol holds the symbol that this nlNode looks in ASCII.
	 */
	protected String m_sSymbol = "arcRef";

	/**
	 * m_sSymbol holds the description of this nlNode
	 */
	protected String m_sDescription = "A network arc reference node";

	/**
	 * m_iSymbol holds the four digit integer that represents this nlNode, with the leftmost (first)
	 * integer representing the category and the right three digits representing a unique sequence number
	 * in the node category.
	 */
	protected int m_iSymbol = 9011;

	/**
	 * m_iType holds the integer representation of the type of this nlNode.
	 */
	protected int m_iType = -1;

	/**
	 * m_iArcID holds the ID of the arc.
	 */
	protected int m_iArcID;

	/**
	 * m_sPropName holds the name of the arc property.
	 */
	protected String m_sPropName;


	/**
	 * constructor.
	 *
	 * </p>
	 *
	 * @param node holds the node operand as the arcRef's input value.
	 * @param arcID holds the ID of the arc.
	 * @param propName holds the name of the arc property.
	 */
	protected OSnLNodeArcRef(OSnLNode node, int arcID, String propName){
		m_mChildren = new OSnLNode[1];
		m_mChildren[0] = node;
		m_iArcID = arcID;
		m_sPropName = propName;
		m_sSymbol = "arcRef:" + m_iArcID + ":" + m_sPropName;
	}//constructor

	/**
	 * constructor.
	 *
	 * </p>
	 *
	 * @param arcID holds the ID of the arc.
	 * @param propName holds the name of the arc property.
	 */
	protected OSnLNodeArcRef(int arcID, String propName){
		m_iArcID = arcID;
		m_sPropName = propName;
		m_sSymbol = "arcRef:" + m_iArcID + ":" + m_sPropName;
	}//constructor

	/**
	 * default constructor.
	 */
	protected OSnLNodeArcRef(){
	}//constructor

	/**
	 * Calculate the result value of a arc reference node given the current variable values.
	 *
	 * </p>
	 *
	 * @param x holds the values of the variables in a double array.
	 * @return the result value of the arc reference node given the current variable values.
	 */
	protected double calculateFunction(double[] x){
		if(m_mChildren != null && m_mChildren.length == 1){
			m_dFunctionValue = m_mChildren[0].calculateFunction(x);
		}
		else{
			try{//TODO referto siminput/simoutput/sim/OSsLReader/OSExpressionTree.setGlobalDefinition/xpath/xpathindex
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
		if(m_mChildren != null && m_mChildren.length == 1){
			m_sFunctionValue = m_mChildren[0].calculateFunction(x, functionEvaluated);
		}
		else{//TODO referto siminput/simoutput/sim/OSsLReader/OSExpressionTree.setGlobalDefinition/xpath/xpathindex
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
		if(m_mChildren != null && m_mChildren.length == 1){
			m_mChildren[0].m_dNodeDerivative = m_dNodeDerivative;
			m_mChildren[0].propogateDerivatives(rootNode, x);
		}
	}//propogateDerivatives

	/**
	 * Calculate the result value of a arc reference node's derivative given the current variable values.
	 *
	 * </p>
	 *
	 * @param x holds the values of the variables in a double array.
	 * @param functionEvaluated holds whether the function has been evaluated.
	 * @return the result value of the arc reference node's derivative given the current variable values.
	 */
	protected double calculateDerivative(double[] x, int index, boolean functionEvaluated){
		double dDerivative;
		if(m_mChildren != null && m_mChildren.length == 1){
			dDerivative = m_mChildren[0].calculateDerivative(x, index, functionEvaluated);
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
		Element eRoot = document.createElement("arcRef");
		String sAttrValue = getArcID() + "";
		if(sAttrValue != null && sAttrValue.length() > 0) eRoot.setAttribute("arcID", sAttrValue);
		sAttrValue = getPropName();
		if(sAttrValue != null && sAttrValue.length() > 0) eRoot.setAttribute("propName", sAttrValue);
		OSnLNode[] mChildren = getChildNodes();
		for(int i = 0; i < ((mChildren == null)?0:mChildren.length); i++){
			Element eChild = mChildren[i].getDOMTree(document);
			eRoot.appendChild(eChild);
		}
		return eRoot;
	}//getDOMTree

	/**
	 *
	 * @return the arc ID.
	 */
	protected int getArcID(){
		return m_iArcID;
	}//getArcID

	/**
	 * Set ID of the arc.
	 *
	 * </p>
	 *
	 * @param arcID holds the ID of the arc.
	 */
	protected void setArcID(int arcID){
		m_iArcID = arcID;
		m_sSymbol = "arcRef:" + m_iArcID + ":" + m_sPropName;
	}//setArcID

	/**
	 *
	 * @return the arc property name.
	 */
	protected String getPropName(){
		return m_sPropName;
	}//getPropName

	/**
	 * Set name of the arc property.
	 *
	 * </p>
	 *
	 * @param propName holds the name of the arc property.
	 */
	protected void setPropName(String propName){
		m_sPropName = propName;
		m_sSymbol = "arcRef:" + m_iArcID + ":" + m_sPropName;
	}//setPropName

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

}//class OSnLNodeArcRef
