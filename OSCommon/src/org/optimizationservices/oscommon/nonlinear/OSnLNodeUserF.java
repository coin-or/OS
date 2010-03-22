/**
 * @(#)OSnLNodeUserF 1.0 03/14/2004
 *
 * Copyright (c) 2004
 */
package org.optimizationservices.oscommon.nonlinear;

import org.w3c.dom.Document;
import org.w3c.dom.Element;


/**
 *
 * <P>The <code>OSnLNodeUserF</code> class represents a user defined function, with a function name.
 * It uses the arg node along with all the other expression nodes to define a function.
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
 * * @see org.optimizationservices.oscommon.nonlinear.OSnLNodeArg;
 * @since OS 1.0
 */
public class OSnLNodeUserF extends OSnLNode{

	/**
	 * m_sSymbol holds the symbol that this nlNode looks in ASCII.
	 */
	protected String m_sSymbol = "userF";

	/**
	 * m_sSymbol holds the description of this nlNode
	 */
	protected String m_sDescription = "A user defined function, with a function name";

	/**
	 * m_iSymbol holds the four digit integer that represents this nlNode, with the leftmost (first)
	 * integer representing the category and the right three digits representing a unique sequence number
	 * in the node category.
	 */
	protected int m_iSymbol = 9006;

	/**
	 * m_iType holds the integer representation of the type of this nlNode.
	 */
	protected int m_iType = -1;

	/**
	 * m_sUserFName holds the name of the user defined function.
	 */
	protected String m_sUserFName = "userF";

	/**
	 * m_iNumArg holds the number of arguments the user function takes.
	 */
	protected int m_iNumArg;

	/**
	 * m_userFRootNode holds the user function root node of OSnLNode class type.
	 */
	protected OSnLNode m_userFRootNode = null;

	/**
	 * constructor
	 *
	 * </p>
	 *
	 * @param nodes holds the array of node operands to the user function as input values.
	 * @param userFName holds the name of the user defined function.
	 */
	protected OSnLNodeUserF(OSnLNode[] nodes, String userFName){
		m_mChildren = nodes;
		m_sUserFName = userFName;
		m_sSymbol = "userF:" + m_sUserFName;
	}//constructor

	/**
	 *
	 * Default Constructor
	 */
	protected OSnLNodeUserF(){
	}//constructor

	/**
	 * Calculate the result value of the user function given all the current variable values.
	 *
	 * </p>
	 *
	 * @param x holds the values of the variables in a double array.
	 * @return the result value of the user function given all the current variable values.
	 */
	protected double calculateFunction(double[] x){
		if(m_mChildren.length != m_iNumArg){
			m_dFunctionValue = Double.NaN;
			return m_dFunctionValue;
		}
		double[] mdArgumentValues = new double[m_iNumArg];
		String[] msArgumentValues = new String[m_iNumArg];
		boolean bString = false;
		for(int i = 0; i < m_iNumArg; i++){
			mdArgumentValues[i] = m_mChildren[i].calculateFunction(x);
			if(Double.isNaN(mdArgumentValues[i]) && m_mChildren[i].m_sFunctionValue != null){
				msArgumentValues[i] = m_mChildren[i].m_sFunctionValue;
				bString = true;
			}
			else{
				if(!Double.isNaN(mdArgumentValues[i])) msArgumentValues[i] = mdArgumentValues[i] + "";
			}
		}
		if(bString){
			m_userFRootNode.setArgumentStringValues(msArgumentValues);
			m_sFunctionValue = m_userFRootNode.calculateFunction(msArgumentValues, false);			
			try{
				m_dFunctionValue = Double.parseDouble(m_sFunctionValue);
				m_sFunctionValue = null;
			}
			catch(Exception e){
				m_dFunctionValue = Double.NaN;
			}
		}
		else{
			OSnLNode.m_iEvaluateUserFunctionArguments += 1;
			m_dFunctionValue = m_userFRootNode.calculateFunction(mdArgumentValues);
			OSnLNode.m_iEvaluateUserFunctionArguments -= 1;
			if(Double.isNaN(m_dFunctionValue) && m_userFRootNode.m_sFunctionValue != null){
				m_sFunctionValue = m_userFRootNode.m_sFunctionValue;
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
		if(m_mChildren.length != m_iNumArg){
			m_sFunctionValue = null;
			return m_sFunctionValue;
		}
		String[] msArgumentValues = new String[m_iNumArg];
		for(int i = 0; i < m_iNumArg; i++){
			msArgumentValues[i] = m_mChildren[i].calculateFunction(x, functionEvaluated);
		}
		OSnLNode.m_iEvaluateUserFunctionArguments += 1;
		m_sFunctionValue = m_userFRootNode.calculateFunction(msArgumentValues, functionEvaluated);
		OSnLNode.m_iEvaluateUserFunctionArguments -= 1;
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
		if(m_mChildren.length != m_iNumArg){
			m_mChildren[0].m_dNodeDerivative = Double.NaN;
		}
		else{
			double[] mdArgumentValues = new double[m_iNumArg];
			for(int i = 0; i < m_iNumArg; i++){
				mdArgumentValues[i] = m_mChildren[i].calculateFunction(x, true);
			}
			m_userFRootNode.m_dNodeDerivative = m_dNodeDerivative;
			m_mapDerivativeValues.clear();
			OSnLNode.m_iEvaluateUserFunctionArguments += 1;
			m_userFRootNode.propogateDerivatives(this, mdArgumentValues);
			OSnLNode.m_iEvaluateUserFunctionArguments -= 1;
			for(int i = 0; i < m_iNumArg; i++){
				m_mChildren[i].m_dNodeDerivative = m_mapDerivativeValues.get(i);
				m_mChildren[i].propogateDerivatives(rootNode, x);
			}
		}
	}//propogateDerivatives

	/**
	 * Calculate the result value of the user function derivative given all the current variable values.
	 *
	 * </p>
	 *
	 * @param x holds the values of the variables in a double array.
	 * @param functionEvaluated holds whether the function has been evaluated.
	 * @return the result value of the user function derivative given all the current variable values.
	 */
	protected double calculateDerivative(double[] x, int index, boolean functionEvaluated){
		double dDerivative;
		if(m_mChildren.length != m_iNumArg){
			dDerivative = Double.NaN;
		}
		else{
			dDerivative = 0;
			double[] mdFunctionOverArgumentDerivatives = new double[m_iNumArg];
			double dArgumentDerivative = 0;
			double[] mdArgumentValues = new double[m_iNumArg];
			for(int i = 0; i < m_iNumArg; i++){
				mdArgumentValues[i] = m_mChildren[i].calculateFunction(x, functionEvaluated);
			}
			for(int i = 0; i < m_iNumArg; i++){
				OSnLNode.m_iEvaluateUserFunctionArguments += 1;
				mdFunctionOverArgumentDerivatives[i] = m_userFRootNode.calculateDerivative(mdArgumentValues, i, functionEvaluated);
				OSnLNode.m_iEvaluateUserFunctionArguments -= 1;
				dArgumentDerivative = m_mChildren[i].calculateDerivative(x, index, functionEvaluated);
				dDerivative += mdFunctionOverArgumentDerivatives[i] * dArgumentDerivative;
			}
			try{
				double dTemp = m_userFRootNode.calculateDerivative(x, index, functionEvaluated);
				dDerivative += dTemp; 
			}
			catch (Exception e){			
			}
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
		Element eRoot = document.createElement("userF");
		String sAttrValue = getUserFName();
		if(sAttrValue != null && sAttrValue.length() > 0) eRoot.setAttribute("name", sAttrValue);
		OSnLNode[] mChildren = getChildNodes();
		for(int i = 0; i < ((mChildren == null)?0:mChildren.length); i++){
			Element eChild = mChildren[i].getDOMTree(document);
			eRoot.appendChild(eChild);
		}
		return eRoot;
	}//getDOMTree

	/**
	 * <p>Simplify the current node's children and return whether the current node's children
	 * can be simplified or not. The current node is simplifiable if it has all constants/numbers
	 * as its children.
	 *
	 * @return whether the node is simplifiable or not.
	 */
	protected boolean simplify(){
		return false;
	}//simplify

	/**
	 *
	 * @return the user function name.
	 */
	protected String getUserFName(){
		return m_sUserFName;
	}//getUserFName

	/**
	 * Set the user function name.
	 *
	 * </p>
	 *
	 * @param userFName holds the name of the user function.
	 */
	protected void setUserFName(String userFName){
		m_sUserFName = userFName;
		m_sSymbol = "userF:" + m_sUserFName;
	}//setUserFName

	/**
	 *
	 * @return the number of arguments the user function takes.
	 */
	protected int getNumArg(){
		return m_iNumArg;
	}//getNumArg

	/**
	 * Set the number of arguments the user function takes.
	 *
	 * </p>
	 *
	 * @param numArg holds the number of arguments the user function takes.
	 */
	protected void setNumArg(int numArg){
		m_iNumArg = numArg;
	}//setNumArg

	/**
	 *
	 * @return the user function root node of OSnLNode class type.
	 */
	protected OSnLNode getRootNode(){
		return m_userFRootNode;
	}//getRootNode

	/**
	 * Set the user function root node of OSnLNode class type.
	 *
	 * </p>
	 *
	 * @param rootNode holds the user function root node of OSnLNode class type.
	 */
	protected void setRootNode(OSnLNode rootNode){
		m_userFRootNode = rootNode;
	}//setRootNode

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

}//class OSnLNodeUserF
