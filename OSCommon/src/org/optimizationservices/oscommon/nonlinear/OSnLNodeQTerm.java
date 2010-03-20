/**
 * @(#)OSnLNodeQpTerm 1.0 03/14/2004
 *
 * Copyright (c) 2004
 */
package org.optimizationservices.oscommon.nonlinear;

import java.util.Vector;

import org.optimizationservices.oscommon.util.CommonUtil;
import org.w3c.dom.Document;
import org.w3c.dom.Element;


/**
 *
 * <P>The <code>OSnLNodeQTerm</code> class represents an quadratic term node a quadratic expression. A quadratic term is of the form
 * Cij*Xi*Xj, where Xi and Xj are the variables (i can be the same as j) and Cij is the corresponding coefficient.
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
 * @see org.optimizationservices.oscommon.nonlinear.OSnLNodeQuadratic;
 * @since OS 1.0
 */
public class OSnLNodeQTerm extends OSnLNode{

	/**
	 * m_sSymbol holds the symbol that this nlNode looks in ASCII.
	 */
	protected String m_sSymbol = "qTerm";

	/**
	 * m_sSymbol holds the description of this nlNode
	 */
	protected String m_sDescription = "A quadratic term node used in a quadratic expression";

	/**
	 * m_iSymbol holds the four digit integer that represents this nlNode, with the leftmost (first)
	 * integer representing the category and the right three digits representing a unique sequence number
	 * in the node category.
	 */
	protected int m_iSymbol = 9001;

	/**
	 * m_iType holds the integer representation of the type of this nlNode.
	 */
	protected int m_iType = -1;

	/**
	 * m_iVarOneIdx holds the variable index of the first variable of the quadratic term.
	 */
	protected int m_iVarOneIdx;

	/**
	 * m_iVarTwoIdx holds the variable index of the second variable of the quadratic term.
	 */
	protected int m_iVarTwoIdx;

	/**
	 * m_dCoef holds the coefficient of the quadratic term.
	 */
	protected double m_dCoef = 1;

	/**
	 * constructor
	 *
	 * </p>
	 *
	 * @param varOneIdx holds the variable index of the first variable of the quadratic term.
	 * @param varTwoIdx holds the variable index of the second variable of the quadratic term.
	 * @param coef holds the coefficient of the quadratic term.
	 */
	protected OSnLNodeQTerm(int varOneIdx, int varTwoIdx, double coef){
		m_iVarOneIdx = varOneIdx;
		m_iVarTwoIdx = varTwoIdx;
		m_dCoef = coef;
		m_sSymbol = "qTerm[0]:" + m_iVarOneIdx + ":" + m_iVarTwoIdx + ":" + m_dCoef;
	}//constructor

	/**
	 * constructor
	 *
	 * </p>
	 *
	 * @param varOneIdx holds the variable index of the first variable of the quadratic term.
	 * @param varTwoIdx holds the variable index of the second variable of the quadratic term.
	 * @param node holds the node operand as the quadratic term node's coeficient.
	 */
	protected OSnLNodeQTerm(int varOneIdx, int varTwoIdx, OSnLNode node){
		m_iVarOneIdx = varOneIdx;
		m_iVarTwoIdx = varTwoIdx;
		m_mChildren = new OSnLNode[1];
		m_mChildren[0] = node;
		m_sSymbol = "qTerm[1]:" + m_iVarOneIdx + ":" + m_iVarTwoIdx + ":" + "1";
	}//constructor

	/**
	 * default constructor
	 */
	protected OSnLNodeQTerm(){
	}//constructor

	/**
	 * Calculate the result value of a quadratic term node given the current variable values.
	 *
	 * </p>
	 *
	 * @param x holds the values of the variables in a double array.
	 * @return the result value of the quadratic term node given the current variable values.
	 */
	protected double calculateFunction(double[] x){
		if(m_mChildren != null && m_mChildren.length == 1) m_dCoef = m_mChildren[0].calculateFunction(m_mdX);
		m_dFunctionValue = m_dCoef * m_mdX[m_iVarOneIdx] * m_mdX[m_iVarTwoIdx];
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
		if(m_mChildren != null && m_mChildren.length == 1) m_dCoef = m_mChildren[0].calculateFunction(m_mdX);
		double dX1Derivative = rootNode.m_mapDerivativeValues.get(m_iVarOneIdx);
		dX1Derivative += (m_dNodeDerivative * m_dCoef * m_mdX[m_iVarTwoIdx]);
		rootNode.m_mapDerivativeValues.put(m_iVarOneIdx, dX1Derivative);

		double dX2Derivative = rootNode.m_mapDerivativeValues.get(m_iVarTwoIdx);
		dX2Derivative += (m_dNodeDerivative * m_dCoef * m_mdX[m_iVarOneIdx]);
		rootNode.m_mapDerivativeValues.put(m_iVarTwoIdx, dX2Derivative);
	}//propogateDerivatives

	/**
	 * Calculate the result value of a quadratic term node's derivative given the current variable values.
	 *
	 * </p>
	 *
	 * @param x holds the values of the variables in a double array.
	 * @param functionEvaluated holds whether the function has been evaluated.
	 * @return the result value of the quadratic term node's derivative given the current variable values.
	 */
	protected double calculateDerivative(double[] x, int index, boolean functionEvaluated){
		if(m_mChildren != null && m_mChildren.length == 1) m_dCoef = m_mChildren[0].calculateFunction(m_mdX);
		double dDerivative;
		if(m_iVarOneIdx != index && m_iVarTwoIdx != index){
			dDerivative = 0;
		}
		else if(m_iVarOneIdx == index && m_iVarTwoIdx != index){
			dDerivative = m_dCoef * m_mdX[m_iVarTwoIdx];
		}
		else if(m_iVarTwoIdx != index && m_iVarTwoIdx == index){
			dDerivative = m_dCoef * m_mdX[m_iVarOneIdx];
		}
		else{
			dDerivative = m_dCoef * (m_mdX[m_iVarOneIdx] + m_mdX[m_iVarTwoIdx]);
		}
		return dDerivative;
	}//calculateDerivative

	/**
	 * This is the recursive call. 
	 * @param vPostfix holds the vector to put in the postfix tokens. 
	 * @return the nonlinear expression starting with the current node in a postfix vector of operator symbols.
	 */
	protected Vector<String> getPostfix(Vector<String> vPostfix){
		if(m_mChildren != null && m_mChildren.length == 1){
			m_mChildren[0].getPostfix(vPostfix);
			vPostfix.add("X" + m_iVarOneIdx);
			vPostfix.add("X" + m_iVarTwoIdx);
			vPostfix.add("times");
			vPostfix.add("times");
		}
		else{
			String sPostfix = m_dCoef + ",X" + m_iVarOneIdx + ",X" + m_iVarTwoIdx + ",times,times";
			vPostfix.addAll(CommonUtil.stringToVector(sPostfix, ","));
		}
		return vPostfix;
	}//getPostfix

	/**
	 * This is the recursive call. 
	 * @param vPrefix holds the vector to put in the prefix tokens. 
	 * @return the nonlinear expression starting with the current node in a prefix vector of operator symbols.
	 */
	protected Vector<String> getPrefix(Vector<String> vPrefix){
		if(m_mChildren != null && m_mChildren.length == 1){
			vPrefix.add("times");
			m_mChildren[0].getPrefix(vPrefix);
			vPrefix.add("times");
			vPrefix.add("X" + m_iVarOneIdx);
			vPrefix.add("X" + m_iVarTwoIdx);
		}
		else{
			String sPrefix = "times," + m_dCoef + ",times,X" + m_iVarOneIdx + ",X" + m_iVarTwoIdx;
			vPrefix.addAll(CommonUtil.stringToVector(sPrefix, ","));
		}
		return vPrefix;
	}//getPrefix

	/**
	 * This is the recursive call. 
	 * @param vInfix holds the vector to put in the infix tokens. 
	 * @return the nonlinear expression starting with the current node in an infix vector of operator symbols.
	 */
	protected Vector<String> getInfix(Vector<String> vInfix){
		if(m_mChildren != null && m_mChildren.length == 1){
			m_mChildren[0].getInfix(vInfix);
			vInfix.add("times");
			vInfix.add("X" + m_iVarOneIdx);
			vInfix.add("times");
			vInfix.add("X" + m_iVarTwoIdx);
		}
		else{
			String sInfix = m_dCoef + ",times,X" + m_iVarOneIdx + ",times,X" + m_iVarTwoIdx;
			vInfix.addAll(CommonUtil.stringToVector(sInfix, ","));
		}
		return vInfix;
	}//getInfix

	/**
	 *
	 * @param document holds the W3C DOM type document to create XML elements and attributes.
	 * It is the parent of the root element, e.g. the &lt;OSiL&gt; element in OSiL. It is used
	 * to create all the nodes in the DOM tree.
	 * @return the nonlinear expression starting with the current node in an XML DOM Tree.
	 */
	protected Element getDOMTree(Document document){
		Element eRoot = document.createElement("qTerm");
		String sAttrValue = getVarOneIndex() + "";
		if(sAttrValue != null && sAttrValue.length() > 0) eRoot.setAttribute("idxOne", sAttrValue);
		sAttrValue = getVarTwoIndex() + "";
		if(sAttrValue != null && sAttrValue.length() > 0) eRoot.setAttribute("idxTwo", sAttrValue);
		sAttrValue = getCoef() + "";
		if(sAttrValue != null && sAttrValue.length() > 0) eRoot.setAttribute("coef", sAttrValue);
		OSnLNode[] mChildren = getChildNodes();
		for(int i = 0; i < ((mChildren == null)?0:mChildren.length); i++){
			Element eChild = mChildren[i].getDOMTree(document);
			eRoot.appendChild(eChild);
		}
		return eRoot;
	}//getDOMTree

	/**
	 *
	 * @return the variable index of the first variable of the quadratic term.
	 */
	protected int getVarOneIndex(){
		return m_iVarOneIdx;
	}//getVarOneIndex

	/**
	 * Set the variable index of the first variable of the quadratic term.
	 *
	 * </p>
	 *
	 * @param varOneIndex holds the variable index of the first variable of the quadratic term.
	 */
	protected void setVarOneIndex(int varOneIndex){
		m_iVarOneIdx = varOneIndex;
		if(m_mChildren != null && m_mChildren.length == 1){
			m_sSymbol = "qTerm[1]:" + m_iVarOneIdx + ":" + m_iVarTwoIdx + ":" + "1";
		}
		else{
			m_sSymbol = "qTerm[0]:" + m_iVarOneIdx + ":" + m_iVarTwoIdx + ":" + m_dCoef;
		}
	}//setVarOneIndex

	/**
	 *
	 * @return the variable index of the second variable of the quadratic term.
	 */
	protected int getVarTwoIndex(){
		return m_iVarTwoIdx;
	}//getVarTwoIndex

	/**
	 * Set the variable index of the second variable of the quadratic term.
	 *
	 * </p>
	 *
	 * @param varTwoIndex holds the variable index of the second variable of the quadratic term.
	 */
	protected void setVarTwoIndex(int varTwoIndex){
		m_iVarTwoIdx = varTwoIndex;
		if(m_mChildren != null && m_mChildren.length == 1){
			m_sSymbol = "qTerm[1]:" + m_iVarOneIdx + ":" + m_iVarTwoIdx + ":" + "1";
		}
		else{
			m_sSymbol = "qTerm[0]:" + m_iVarOneIdx + ":" + m_iVarTwoIdx + ":" + m_dCoef;
		}
	}//setVarTwoIndex

	/**
	 *
	 * @return the the coefficient of the quadratic term.
	 */
	protected double getCoef(){
		return m_dCoef;
	}//getCoef

	/**
	 * Set the the coefficient of the quadratic term.
	 *
	 * </p>
	 *
	 * @param coef holds the coefficient of the quadratic term.
	 */
	protected void setCoef(double coef){
		m_dCoef = coef;
		m_sSymbol = "qTerm[0]:" + m_iVarOneIdx + ":" + m_iVarTwoIdx + ":" + m_dCoef;
	}//setCoef

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

}//class OSnLNodeQTerm
