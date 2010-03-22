/**
 * @(#)OSnLNodeProduct 1.0 03/14/2004
 *
 * Copyright (c) 2004
 */
package org.optimizationservices.oscommon.nonlinear;

/**
 *
 * <P>The <code>OSnLNodeProduct</code> class represents a product node in an expression tree.
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
public class OSnLNodeProduct extends OSnLNode{

	/**
	 * m_sSymbol holds the symbol that this nlNode looks in ASCII.
	 */
	protected String m_sSymbol = "product";

	/**
	 * m_sSymbol holds the description of this nlNode
	 */
	protected String m_sDescription = "Product of n node operands";

	/**
	 * m_iSymbol holds the four digit integer that represents this nlNode, with the leftmost (first)
	 * integer representing the category and the right three digits representing a unique sequence number
	 * in the node category.
	 */
	protected int m_iSymbol = 1010;

	/**
	 * m_iType holds the integer representation of the type of this nlNode.
	 */
	protected int m_iType = -1;

	/**
	 * constructor
	 *
	 * </p>
	 *
	 * @param nodes holds the array of node operands to product.
	 */
	protected OSnLNodeProduct(OSnLNode[] nodes){
		m_mChildren = nodes;
	}//constructor

	/**
	 *
	 * Default Constructor
	 */
	protected OSnLNodeProduct(){
	}//constructor

	/**
	 * Calculate the result value of addition given the current variable values.
	 *
	 * </p>
	 *
	 * @param x holds the values of the variables in a double array.
	 * @return the result value of product given the current variable values.
	 */
	protected double calculateFunction(double[] x){
		m_dFunctionValue = 1.0;
		for(int i = 0; i < ((m_mChildren == null)?0:m_mChildren.length); i++){
			m_dFunctionValue *= m_mChildren[i].calculateFunction(x);
		}
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
		int iTerm = (m_mChildren == null)?0:m_mChildren.length;
		double[] mdChildFunctionValues = new double[iTerm];
		double dProduct = 1.0;
		for(int i = 0; i < iTerm; i++){
			mdChildFunctionValues[i] = m_mChildren[i].calculateFunction(x, true);
			dProduct *= mdChildFunctionValues[i];
		}
		for(int i = 0; i < iTerm; i++){
			m_mChildren[i].m_dNodeDerivative = m_dNodeDerivative * (dProduct/mdChildFunctionValues[i]);
			m_mChildren[i].propogateDerivatives(rootNode, x);
		}		

	}//propogateDerivatives

	/**
	 * Calculate the result value of product derivative given the current variable values.
	 *
	 * </p>
	 *
	 * @param x holds the values of the variables in a double array.
	 * @param functionEvaluated holds whether the function has been evaluated.
	 * @return the result value of product derivative given the current variable values.
	 */
	protected double calculateDerivative(double[] x, int index, boolean functionEvaluated){
		double dDerivative = 0;
		int iTerm = (m_mChildren == null)?0:m_mChildren.length;
		double[] mdChildFunctionValues = new double[iTerm];
		for(int i = 0; i < iTerm; i++){
			mdChildFunctionValues[i] = m_mChildren[i].calculateFunction(x, functionEvaluated);
		}
		for(int i = 0; i < iTerm; i++){
			double dTermDerivative = m_mChildren[i].calculateDerivative(x, index, functionEvaluated) ;
			for(int j = 0; j < iTerm; j++){
				if(j == i){
					continue;
				}
				dTermDerivative *= mdChildFunctionValues[j];
			}
			dDerivative += dTermDerivative; 
		}
		return dDerivative;
	}//calculateDerivative

	/**
	 * <p>Simplify the current node's children and return whether the current node's children
	 * can be simplified or not. The current node is simplifiable if it has all constants/numbers
	 * as its children.
	 *
	 * @return whether the node is simplifiable or not.
	 */
	protected boolean simplify(){
		if(m_mChildren == null) return false;
		boolean bSimplifiable = true;
		double dProduct = 1;
		int iNewChildNum = (m_mChildren==null)?0:m_mChildren.length;
		for(int i = 0; i < ((m_mChildren == null)?0:m_mChildren.length); i++){
			if(m_mChildren[i].simplify()){
				double dValue = m_mChildren[i].calculateFunction(null);
				dProduct *= dValue;
				iNewChildNum--;
				m_mChildren[i] = null;
			}
			else{
				int iChildIndex = m_mChildren[i].getSymbolInteger();
				if(iChildIndex == 5001){
					String sType = ((OSnLNodeNumber)m_mChildren[i]).getNumberType();
					if(sType.equalsIgnoreCase("string") || sType.equalsIgnoreCase("random")){
						bSimplifiable = false;
					}
					else{
						dProduct *= Double.parseDouble(((OSnLNodeNumber)m_mChildren[i]).getNumberValue());
						iNewChildNum--;
						m_mChildren[i] = null;
					}
				}
				else if(iChildIndex >= 5003 && iChildIndex < 6000){
					dProduct *= (m_mChildren[i]).calculateFunction(null);
					iNewChildNum--;
					m_mChildren[i] = null;
				}
				else{
					bSimplifiable = false;
				}
			}
		}
		if(dProduct != 1) iNewChildNum ++;
		OSnLNode[] mNewChildren = new OSnLNode[iNewChildNum];
		int k = 0;
		for(int i = 0; i < ((m_mChildren==null)?0:m_mChildren.length); i++){
			if(m_mChildren[i] != null){
				mNewChildren[k] = m_mChildren[i];
				k++;
			}
		}
		if(dProduct != 1) mNewChildren[iNewChildNum-1] = new OSnLNodeNumber(null, dProduct + "", "real");
		m_mChildren = mNewChildren;
		return bSimplifiable;
	}//simplify

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

}//class OSnLNodeProduct
