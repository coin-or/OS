/**
 * @(#)OSnLNodeNodeRef 1.0 03/14/2004
 *
 * Copyright (c) 2004
 */
package org.optimizationservices.oscommon.nonlinear;

import org.w3c.dom.Document;
import org.w3c.dom.Element;

/**
 *
 * <P>The <code>OSnLNodeNodeRef</code> class represents a network node reference. An nodeRef node
 * is used to get and set values from a network node.
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
 * @see org.optimizationservices.oscommon.nonlinear.OSnLNodeArcRef;
 * @since OS 1.0
 */
public class OSnLNodeNodeRef extends OSnLNode{

	/**
	 * m_sSymbol holds the symbol that this nlNode looks in ASCII.
	 */
	protected String m_sSymbol = "nodeRef";

	/**
	 * m_sSymbol holds the description of this nlNode
	 */
	protected String m_sDescription = "A network node reference node";

	/**
	 * m_iSymbol holds the four digit integer that represents this nlNode, with the leftmost (first)
	 * integer representing the category and the right three digits representing a unique sequence number
	 * in the node category.
	 */
	protected int m_iSymbol = 9010;

	/**
	 * m_iType holds the integer representation of the type of this nlNode.
	 */
	protected int m_iType = -1;

	/**
	 * m_sNodeID holds the id of the node.
	 */
	protected int m_iNodeID;

	/**
	 * m_sPropName holds the name of the node property.
	 */
	protected String m_sPropName;


	/**
	 * constructor.
	 *
	 * </p>
	 *
	 * @param node holds the node operand as the nodeRef's input value.
	 * @param nodeID holds the ID of the node.
	 * @param propName holds the name of the node property.
	 */
	protected OSnLNodeNodeRef(OSnLNode node, int nodeID, String propName){
		m_mChildren = new OSnLNode[1];
		m_mChildren[0] = node;
		m_iNodeID = nodeID;
		m_sPropName = propName;
		m_sSymbol = "nodeRef:" + m_iNodeID + ":" + m_sPropName;
	}//constructor

	/**
	 * constructor.
	 *
	 * </p>
	 *
	 * @param nodeID holds the ID of the node.
	 * @param propName holds the name of the node property.
	 */
	protected OSnLNodeNodeRef(int nodeID, String propName){
		m_iNodeID = nodeID;
		m_sPropName = propName;
		m_sSymbol = "nodeRef:" + m_iNodeID + ":" + m_sPropName;
	}//constructor

	/**
	 * default constructor.
	 */
	protected OSnLNodeNodeRef(){
	}//constructor

	/**
	 * Calculate the result value of a node reference node given the current variable values.
	 *
	 * </p>
	 *
	 * @param x holds the values of the variables in a double array.
	 * @return the result value of the node reference node given the current variable values.
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
	 * Calculate the result value of a node reference node's derivative given the current variable values.
	 *
	 * </p>
	 *
	 * @param x holds the values of the variables in a double array.
	 * @param functionEvaluated holds whether the function has been evaluated.
	 * @return the result value of the node reference node's derivative given the current variable values.
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
		Element eRoot = document.createElement("nodeRef");
		String sAttrValue = getNodeID() + "";
		if(sAttrValue != null && sAttrValue.length() > 0) eRoot.setAttribute("nodeID", sAttrValue);
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
	 * @return the node ID.
	 */
	protected int getNodeID(){
		return m_iNodeID;
	}//getNodeID

	/**
	 * Set ID of the node.
	 *
	 * </p>
	 *
	 * @param nodeID holds the ID of the node.
	 */
	protected void setNodeID(int nodeID){
		m_iNodeID = nodeID;
		m_sSymbol = "nodeRef:" + m_iNodeID + ":" + m_sPropName;
	}//setNodeID

	/**
	 *
	 * @return the node property name.
	 */
	protected String getPropName(){
		return m_sPropName;
	}//getPropName

	/**
	 * Set name of the node property.
	 *
	 * </p>
	 *
	 * @param propName holds the name of the node property.
	 */
	protected void setPropName(String propName){
		m_sPropName = propName;
		m_sSymbol = "nodeRef:" + m_iNodeID + ":" + m_sPropName;
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

}//class OSnLNodeNodeRef
