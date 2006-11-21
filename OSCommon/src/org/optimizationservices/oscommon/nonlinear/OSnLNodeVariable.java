/**
 * @(#)OSnLNodeVariable 1.0 03/14/2004
 *
 * Copyright (c) 2004
 */
package org.optimizationservices.oscommon.nonlinear;

import java.util.Vector;

import org.w3c.dom.Document;
import org.w3c.dom.Element;

/**
 *
 * <P>The <code>OSnLNodeVariable</code> class represents a variable node in an expression tree.
 * The variable can be treated as a unary operator with its index as a subscript operand of the "variable operator".
 * If the variable index is a number, there is no operand node. The number is treated as the variables attribute.
 * If the variable index is an integer-valued function or a look up from some data source, it is treated no
 * different from a unary operator.
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
public class OSnLNodeVariable extends OSnLNode{

	/**
	 * m_sSymbol holds the symbol that this nlNode looks in ASCII.
	 */
	protected String m_sSymbol = "X";

	/**
	 * m_sSymbol holds the description of this nlNode
	 */
	protected String m_sDescription = "Variable node which takes an integer-valued node operand as its index";

	/**
	 * m_iSymbol holds the four digit integer that represents this nlNode, with the leftmost (first)
	 * integer representing the category and the right three digits representing a unique sequence number
	 * in the node category.
	 */
	protected int m_iSymbol = 6001;

	/**
	 * m_iType holds the integer representation of the type of this nlNode.
	 */
	protected int m_iType = -1;

	/**
	 * m_iIndex holds the integer number for the variable index.
	 */
	protected int m_iIndex = -1;

	/**
	 * m_dCoef holds the coefficient for the variable.
	 */
	protected double m_dCoef = 1;

	/**
	 * m_dLeafDerivative holds the derivative for the function against this variable node which is a leaf node.
	 * This is mainly used for the purpose of automatic differentiation based on the chain rule of
	 * calculus. Since dF_root/dF_leaf is independent of the variable X[i], m_dLeafDerivative remains
	 * the same for all X[i]'s.
	 * The m_dLeafDerivative is then to be mulplied by this variable node's derivative against X[i]
	 * which is specified in the calculateDerivative method of this class.
	 * The derivative over this variable of function represented by the root of
	 * the expression tree is then
	 * sum_overAllLeavesContainingVariables(m_dLeafDerivative * derivative_of_this_variable_node)
	 */
	protected static double m_dLeafDerivative = 1;
	/**
	 * constructor
	 *
	 * </p>
	 *
	 * @param node holds the node operand as the varible node's index, which should calculate to a number of an integer-valued function.
	 * @param coef holds the coefficient for the variable.
	 */
	protected OSnLNodeVariable(OSnLNode node, double coef){
		m_mChildren = new OSnLNode[1];
		m_mChildren[0] = node;
		m_dCoef = coef;
	}//constructor

	/**
	 * Constructor
	 *
	 * </p>
	 *
	 * @param index holds the integer number for the variable index.
	 * @param coef holds the coefficient for the variable.
	 */
	protected OSnLNodeVariable(int index, double coef){
		m_iIndex = index;
		m_dCoef = coef;
	}//constructor

	/**
	 *
	 * Default Constructor
	 */
	protected OSnLNodeVariable(){
	}//constructor

	/**
	 * Calculate the result value of the varible given all the current variable values.
	 *
	 * </p>
	 *
	 * @param x holds the values of the variables in a double array.
	 * @return the result value of the varible given all the current variable values.
	 */
	protected double calculateFunction(double[] x){
		if(m_iIndex >= 0){
			m_dFunctionValue = m_mdX[m_iIndex];
		}
		else{
			double dIndex = m_mChildren[0].calculateFunction(x);
			int iIndex = (int)(dIndex + 0.5);
			if(Math.abs(dIndex - iIndex) < OSnLNode.m_dIntTol){
				try{
					m_dFunctionValue = m_mdX[iIndex];
				}
				catch(Exception e){
					m_dFunctionValue = Double.NaN;
				}
			}
			else m_dFunctionValue = Double.NaN;
		}
		m_dFunctionValue = m_dFunctionValue * m_dCoef;
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
		if(m_iIndex >= 0){
			m_sFunctionValue = m_msX[m_iIndex];
		}
		else{
			String sIndex = m_mChildren[0].calculateFunction(x, functionEvaluated);
			double dIndex = Double.NaN;
			int iIndex = -1;
			try{
				dIndex = Double.parseDouble(sIndex);
				iIndex = (int)(iIndex + 0.5);
			}
			catch(Exception e){

			}
			if(Math.abs(dIndex - iIndex) < OSnLNode.m_dIntTol){
				try{
					m_sFunctionValue = m_msX[iIndex];
				}
				catch(Exception e){
					m_sFunctionValue = null;
				}
			}
			else m_sFunctionValue = null;
		}
		try{
			double dValue = Double.parseDouble(m_sFunctionValue);
			dValue = dValue * m_dCoef;
			m_sFunctionValue = dValue + "";
		}
		catch(Exception e){

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
		if(m_iIndex >= 0){
			double dXDerivative = m_treeRoot.m_mapDerivativeValues.get(m_iIndex);
			dXDerivative += (m_dNodeDerivative * m_dCoef);
			if(dXDerivative != 0) m_treeRoot.m_mapDerivativeValues.put(m_iIndex, dXDerivative);
		}
		else{
			m_mChildren[0].m_dNodeDerivative = Double.NaN;
			m_mChildren[0].propogateDerivatives(rootNode, x);
		}
	}//propogateDerivatives

	/**
	 * Calculate the result value of the varible derivative given all the current variable values.
	 *
	 * </p>
	 *
	 * @param x holds the values of the variables in a double array.
	 * @param functionEvaluated holds whether the function has been evaluated.
	 * @return the result value of the varible given all the current variable values.
	 */
	protected double calculateDerivative(double[] x, int index, boolean functionEvaluated){
		if(OSnLNode.m_iEvaluateUserFunctionArguments != 0) return 0.0;		
		double dDerivative;
		if(m_iIndex < 0){
			dDerivative = Double.NaN;
		}
		else if(m_iIndex != index){
			dDerivative = 0;
		}
		else{
			dDerivative = m_dCoef;
		}
		return dDerivative;
	}//calculateDerivative

	/**
	 * This is the recursive call. 
	 * @param vPostfix holds the vector to put in the postfix tokens. 
	 * @return the nonlinear expression starting with the current node in a postfix vector of operator symbols.
	 */
	protected Vector<String> getPostfix(Vector<String> vPostfix){
		String sSymbol = getSymbol();
		if(m_iIndex < 0) sSymbol += "[1]";
		if(m_dCoef != 1) vPostfix.addElement(m_dCoef + "");
		if(m_iIndex >= 0) vPostfix.addElement(sSymbol + m_iIndex);
		else{
			for(int i = 0; i < ((m_mChildren == null)?0:m_mChildren.length); i++){
				m_mChildren[i].getPostfix(vPostfix);
			}
			vPostfix.addElement(sSymbol);
		}
		if(m_dCoef != 1) vPostfix.addElement("times");
		return vPostfix;
	}//getPostfix

	/**
	 * This is the recursive call. 
	 * @param vPrefix holds the vector to put in the prefix tokens. 
	 * @return the nonlinear expression starting with the current node in a prefix vector of operator symbols.
	 */
	protected Vector<String> getPrefix(Vector<String> vPrefix){
		String sSymbol = m_sSymbol;
		if(m_iIndex < 0) sSymbol += "[1]";
		if(m_dCoef != 1){
			vPrefix.addElement("times");
			vPrefix.addElement(m_dCoef + "");
		}
		if(m_iIndex >= 0) vPrefix.addElement(sSymbol + m_iIndex);
		else{
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
		if(m_iIndex < 0) sSymbol += "[1]";
		if(m_dCoef != 1){
			vInfix.addElement(m_dCoef + "");
			vInfix.addElement("times");
		}
		if(m_iIndex >= 0) vInfix.addElement(sSymbol + m_iIndex);
		else{
			vInfix.addElement(sSymbol);
			if(m_mChildren != null) vInfix.addElement("(");
			for(int i = 0; i < ((m_mChildren == null)?0:m_mChildren.length); i++){
				m_mChildren[i].getInfix(vInfix);
			}
			if(m_mChildren != null) vInfix.addElement(")");
		}
		return vInfix;
	}//getPrefix

	/**
	 *
	 * @param document holds the W3C DOM type document to create XML elements and attributes.
	 * It is the parent of the root element, e.g. the &lt;OSiL&gt; element in OSiL. It is used
	 * to create all the nodes in the DOM tree.
	 * @return the nonlinear expression starting with the current node in an XML DOM Tree.
	 */
	protected Element getDOMTree(Document document){
		Element eRoot = document.createElement("variable");
		String sAttrValue = getIndex() + "";
		if(sAttrValue != null && sAttrValue.length() > 0) eRoot.setAttribute("idx", sAttrValue);
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
	 * @return the integer number for the variable index.
	 */
	protected int getIndex(){
		return m_iIndex;
	}//getIndex

	/**
	 * Set the integer number for the variable index.
	 *
	 * </p>
	 *
	 * @param index holds the integer number for the variable index.
	 */
	protected void setIndex(int index){
		m_iIndex = index;
	}//setIndex

	/**
	 *
	 * @return the coefficient for the variable.
	 */
	protected double getCoef(){
		return m_dCoef;
	}//getCoef

	/**
	 * Set the coefficient for the variable.
	 *
	 * </p>
	 *
	 * @param coef holds the coefficient for the variable.
	 */
	protected void setCoef(double coef){
		m_dCoef = coef;
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

}//class OSnLNodeVariable
