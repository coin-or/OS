using System;
using System.Collections;
using System.Xml;

namespace org.optimizationservices.oscommon.nonlinear{
	/// <summary>
	/// The <c>OSnLNodeVariable</c> class represents a variable node in an expression tree.
	/// It extends the abstract OSnLNode class and implements its abstract methods such as
	/// calculateFunction(double[]).
	/// @author Jun Ma	
	/// @version 1.0, 09/01/2005
	/// @since OS 1.0
	/// @copyright (c) 2005
	/// </summary>
	public class OSnLNodeVariable :OSnLNode{

		/**
		* m_sSymbol holds the symbol that this nlNode looks in ASCII.
		*/
		protected internal string m_sSymbol = "X";

		/**
		 * m_sSymbol holds the description of this nlNode
		 */
		protected internal string m_sDescription = "Variable node which takes an integer-valued node operand as its index";

		/**
		 * m_iSymbol holds the four digit integer that represents this nlNode, with the leftmost (first)
		 * integer representing the category and the right three digits representing a unique sequence number
		 * in the node category.
		 */
		protected internal int m_iSymbol = 6001;

		/**
		 * m_iType holds the integer representation of the type of this nlNode.
		 */
		protected internal int m_iType = -1;

		/**
		 * m_iIndex holds the integer number for the variable index.
		 */
		protected internal int m_iIndex = -1;

		/**
		 * m_dCoef holds the coefficient for the variable.
		 */
		protected internal double m_dCoef = 1;

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
		protected internal static double m_dLeafDerivative = 1;
		/**
		 * constructor
		 *
		 * </p>
		 *
		 * @param node holds the node operand as the varible node's index, which should calculate to a number of an integer-valued function.
		 * @param coef holds the coefficient for the variable.
		 */
		protected internal OSnLNodeVariable(OSnLNode node, double coef){
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
		protected internal OSnLNodeVariable(int index, double coef){
			m_iIndex = index;
			m_dCoef = coef;
		}//constructor

		/**
		 *
		 * Default Constructor
		 */
		protected internal OSnLNodeVariable(){
		}//constructor

		/**
		 * Calculate the result value of the varible given all the current variable values.
		 *
		 * </p>
		 *
		 * @param x holds the values of the variables in a double array.
		 * @return the result value of the varible given all the current variable values.
		 */
		protected internal override double calculateFunction(double[] x){
			if(m_iIndex >= 0){
				m_dFunctionValue = m_mdX[m_iIndex];
			}
			else{
				double dIndex = m_mChildren[0].calculateFunction(x);
				int iIndex = (int)(dIndex + 0.5);
				if(Math.Abs(dIndex - iIndex) < OSnLNode.m_dIntTol){
					try{
						m_dFunctionValue = m_mdX[iIndex];
					}
					catch(Exception){
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
		protected internal override string calculateFunction(string[] x, bool functionEvaluated){
			if(functionEvaluated) return m_sFunctionValue;
			if(m_iIndex >= 0){
				m_sFunctionValue = m_msX[m_iIndex];
			}
			else{
				string sIndex = m_mChildren[0].calculateFunction(x, functionEvaluated);
				double dIndex = Double.NaN;
				int iIndex = -1;
				try{
					dIndex = Convert.ToDouble(sIndex);
					iIndex = (int)(iIndex + 0.5);
				}
				catch(Exception){

				}
				if(Math.Abs(dIndex - iIndex) < OSnLNode.m_dIntTol){
					try{
						m_sFunctionValue = m_msX[iIndex];
					}
					catch(Exception){
						m_sFunctionValue = null;
					}
				}
				else m_sFunctionValue = null;
			}
			try{
				double dValue = Convert.ToDouble(m_sFunctionValue);
				dValue = dValue * m_dCoef;
				m_sFunctionValue = dValue + "";
			}
			catch(Exception){

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
		protected internal override void propogateDerivatives(OSnLNode rootNode, double[] x){
			if(m_iIndex >= 0){
				double dXDerivative = Convert.ToDouble(m_treeRoot.m_mapDerivativeValues[m_iIndex.ToString()]);
				dXDerivative += (m_dNodeDerivative * m_dCoef);
				if(dXDerivative != 0) m_treeRoot.m_mapDerivativeValues.Add(m_iIndex, dXDerivative);
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
		protected internal override double calculateDerivative(double[] x, int index, bool functionEvaluated){
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
		 *
		 * @return the nonlinear expression starting with the current node in a postfix vector of operator symbols.
		 */
		protected internal override ArrayList getPostfix(){
			string sSymbol = getSymbol();
			if(m_iIndex < 0) sSymbol += "[1]";
			ArrayList vPostfix = new ArrayList();
				if(m_dCoef != 1) vPostfix.Add(m_dCoef + "");
			if(m_iIndex >= 0) vPostfix.Add(sSymbol + m_iIndex);
			else{
				for(int i = 0; i < ((m_mChildren == null)?0:m_mChildren.Length); i++){
					vPostfix.AddRange(m_mChildren[i].getPostfix());
				}
				vPostfix.Add(sSymbol);
			}
			if(m_dCoef != 1) vPostfix.Add("times");
			return vPostfix;
		}//getPostfix

		/**
		 *
		 * @return the nonlinear expression starting with the current node in a prefix vector of operator symbols.
		 */
		protected internal override ArrayList getPrefix(){
			ArrayList vPrefix = new ArrayList();
				string sSymbol = m_sSymbol;
			if(m_iIndex < 0) sSymbol += "[1]";
			if(m_dCoef != 1){
				vPrefix.Add("times");
				vPrefix.Add(m_dCoef + "");
			}
			if(m_iIndex >= 0) vPrefix.Add(sSymbol + m_iIndex);
			else{
				vPrefix.Add(sSymbol);
				for(int i = 0; i < ((m_mChildren == null)?0:m_mChildren.Length); i++){
					vPrefix.AddRange(m_mChildren[i].getPrefix());
				}
			}
			return vPrefix;
		}//getPrefix

		/**
		 *
		 * @return the nonlinear expression starting with the current node in an infix vector of operator symbols.
		 */
		protected internal override ArrayList getInfix(){
			ArrayList vInfix = new ArrayList();
				string sSymbol = m_sSymbol;
			if(m_iIndex < 0) sSymbol += "[1]";
			if(m_dCoef != 1){
				vInfix.Add(m_dCoef + "");
				vInfix.Add("times");
			}
			if(m_iIndex >= 0) vInfix.Add(sSymbol + m_iIndex);
			else{
				vInfix.Add(sSymbol);
				if(m_mChildren != null) vInfix.Add("(");
				for(int i = 0; i < ((m_mChildren == null)?0:m_mChildren.Length); i++){
					vInfix.AddRange(m_mChildren[i].getInfix());
				}
				if(m_mChildren != null) vInfix.Add(")");
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
		protected internal override XmlElement getDOMTree(XmlDocument document){
			XmlElement eRoot = document.CreateElement("variable");
			string sAttrValue = getIndex() + "";
			if(sAttrValue != null && sAttrValue.Length > 0) eRoot.SetAttribute("idx", sAttrValue);
			sAttrValue = getCoef() + "";
			if(sAttrValue != null && sAttrValue.Length > 0) eRoot.SetAttribute("coef", sAttrValue);
			OSnLNode[] mChildren = getChildNodes();
			for(int i = 0; i < ((mChildren == null)?0:mChildren.Length); i++){
				XmlElement eChild = mChildren[i].getDOMTree(document);
				eRoot.AppendChild(eChild);
			}
			return eRoot;
		}//getDOMTree

		/**
		 *
		 * @return the integer number for the variable index.
		 */
		protected internal int getIndex(){
			return m_iIndex;
		}//getIndex

		/**
		 * Set the integer number for the variable index.
		 *
		 * </p>
		 *
		 * @param index holds the integer number for the variable index.
		 */
		protected internal void setIndex(int index){
			m_iIndex = index;
		}//setIndex

		/**
		 *
		 * @return the coefficient for the variable.
		 */
		protected internal double getCoef(){
			return m_dCoef;
		}//getCoef

		/**
		 * Set the coefficient for the variable.
		 *
		 * </p>
		 *
		 * @param coef holds the coefficient for the variable.
		 */
		protected internal void setCoef(double coef){
			m_dCoef = coef;
		}//setCoef

		/**
		 *
		 * @return the symbol of this nlNode in ASCII string.
		 */
		protected internal override string getSymbol(){
			return m_sSymbol;
		}//getSymbol

		/**
		 *
		 * @return the symbol of this nlNode in integer.
		 */
		protected internal override int getSymbolInteger(){
			return m_iSymbol;
		}//getSymbolInteger

		/**
		 *
		 * @return the type of this nlNode.
		 */
		protected internal override int getType(){
			return m_iType;
		}//getType

		/**
		 *
		 * @return the description of this nlNode.
		 */
		protected internal override string getDescription(){
			return m_sDescription;
		}//getDescription

	}//class OSnLNodeVariable
}//namespace
