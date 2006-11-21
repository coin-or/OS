using System;
using System.Collections;
using System.Xml;

using org.optimizationservices.oscommon.util;

namespace org.optimizationservices.oscommon.nonlinear{
	/// <summary>
	/// The <c>OSnLNodeQpTerm</c> class represents a qpTerm node in an expression tree.
	/// It extends the abstract OSnLNode class and implements its abstract methods such as
	/// calculateFunction(double[]).
	/// @author Jun Ma	
	/// @version 1.0, 09/01/2005
	/// @since OS 1.0
	/// @copyright (c) 2005
	/// </summary>
	public class OSnLNodeQpTerm :OSnLNode{

		/**
		 * m_sSymbol holds the symbol that this nlNode looks in ASCII.
		 */
		protected internal string m_sSymbol = "qpTerm";

		/**
		 * m_sSymbol holds the description of this nlNode
		 */
		protected internal string m_sDescription = "A quadratic term node used in a quadratic expression";

		/**
		 * m_iSymbol holds the four digit integer that represents this nlNode, with the leftmost (first)
		 * integer representing the category and the right three digits representing a unique sequence number
		 * in the node category.
		 */
		protected internal int m_iSymbol = 9001;

		/**
		 * m_iType holds the integer representation of the type of this nlNode.
		 */
		protected internal int m_iType = -1;

		/**
		 * m_iVarOneIdx holds the variable index of the first variable of the quadratic term.
		 */
		protected internal int m_iVarOneIdx;

		/**
		 * m_iVarTwoIdx holds the variable index of the second variable of the quadratic term.
		 */
		protected internal int m_iVarTwoIdx;

		/**
		 * m_dCoef holds the coefficient of the quadratic term.
		 */
		protected internal double m_dCoef = 1;

		/**
		 * constructor
		 *
		 * </p>
		 *
		 * @param varOneIdx holds the variable index of the first variable of the quadratic term.
		 * @param varTwoIdx holds the variable index of the second variable of the quadratic term.
		 * @param coef holds the coefficient of the quadratic term.
		 */
		protected internal OSnLNodeQpTerm(int varOneIdx, int varTwoIdx, double coef){
			m_iVarOneIdx = varOneIdx;
			m_iVarTwoIdx = varTwoIdx;
			m_dCoef = coef;
			m_sSymbol = "qpTerm[0]:" + m_iVarOneIdx + ":" + m_iVarTwoIdx + ":" + m_dCoef;
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
		protected internal OSnLNodeQpTerm(int varOneIdx, int varTwoIdx, OSnLNode node){
			m_iVarOneIdx = varOneIdx;
			m_iVarTwoIdx = varTwoIdx;
			m_mChildren = new OSnLNode[1];
			m_mChildren[0] = node;
			m_sSymbol = "qpTerm[1]:" + m_iVarOneIdx + ":" + m_iVarTwoIdx + ":" + "1";
		}//constructor

		/**
		 * default constructor
		 */
		protected internal OSnLNodeQpTerm(){
		}//constructor

		/**
		 * Calculate the result value of a quadratic term node given the current variable values.
		 *
		 * </p>
		 *
		 * @param x holds the values of the variables in a double array.
		 * @return the result value of the quadratic term node given the current variable values.
		 */
		protected internal override double calculateFunction(double[] x){
			if(m_mChildren != null && m_mChildren.Length == 1) m_dCoef = m_mChildren[0].calculateFunction(m_mdX);
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
		protected internal override void propogateDerivatives(OSnLNode rootNode, double[] x){
			if(m_mChildren != null && m_mChildren.Length == 1) m_dCoef = m_mChildren[0].calculateFunction(m_mdX);
			double dX1Derivative = Convert.ToDouble(rootNode.m_mapDerivativeValues[m_iVarOneIdx.ToString()]);
			dX1Derivative += (m_dNodeDerivative * m_dCoef * m_mdX[m_iVarTwoIdx]);
			rootNode.m_mapDerivativeValues.Add(m_iVarOneIdx, dX1Derivative);

			double dX2Derivative = Convert.ToDouble(rootNode.m_mapDerivativeValues[m_iVarTwoIdx.ToString()]);
			dX2Derivative += (m_dNodeDerivative * m_dCoef * m_mdX[m_iVarOneIdx]);
			rootNode.m_mapDerivativeValues.Add(m_iVarTwoIdx, dX2Derivative);
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
		protected internal override double calculateDerivative(double[] x, int index, bool functionEvaluated){
			if(m_mChildren != null && m_mChildren.Length == 1) m_dCoef = m_mChildren[0].calculateFunction(m_mdX);
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
		 *
		 * @return the nonlinear expression starting with the current node in a postfix vector of operator symbols.
		 */
		protected internal override ArrayList getPostfix(){
			if(m_mChildren != null && m_mChildren.Length == 1){
				ArrayList vPostfix = m_mChildren[0].getPostfix();
				vPostfix.Add("x" + m_iVarOneIdx);
				vPostfix.Add("x" + m_iVarTwoIdx);
				vPostfix.Add("times");
				vPostfix.Add("times");
				return vPostfix;
			}
			else{
				string sPostfix = m_dCoef + ",x" + m_iVarOneIdx + ",x" + m_iVarTwoIdx + ",times,times";
				return CommonUtil.stringToVector(sPostfix, ",");
			}
		}//getPostfix

		/**
		 *
		 * @return the nonlinear expression starting with the current node in a prefix vector of operator symbols.
		 */
		protected internal override ArrayList getPrefix(){
			if(m_mChildren != null && m_mChildren.Length == 1){
				ArrayList vPrefix = new ArrayList();
					vPrefix.Add("times");
				vPrefix.AddRange(m_mChildren[0].getPrefix());
				vPrefix.Add("times");
				vPrefix.Add("x" + m_iVarOneIdx);
				vPrefix.Add("x" + m_iVarTwoIdx);
				return vPrefix;
			}
			else{
				string sPrefix = "times," + m_dCoef + ",times,x" + m_iVarOneIdx + ",x" + m_iVarTwoIdx;
				return CommonUtil.stringToVector(sPrefix, ",");
			}
		}//getPrefix

		/**
		 *
		 * @return the nonlinear expression starting with the current node in an infix vector of operator symbols.
		 */
		protected internal override ArrayList getInfix(){
			if(m_mChildren != null && m_mChildren.Length == 1){
				ArrayList vInfix = m_mChildren[0].getInfix();
				vInfix.Add("times");
				vInfix.Add("x" + m_iVarOneIdx);
				vInfix.Add("times");
				vInfix.Add("x" + m_iVarTwoIdx);
				return vInfix;
			}
			else{
				string sInfix = m_dCoef + ",times,x" + m_iVarOneIdx + ",times,x" + m_iVarTwoIdx;
				return CommonUtil.stringToVector(sInfix, ",");
			}
		}//getInfix

		/**
		 *
		 * @param document holds the W3C DOM type document to create XML elements and attributes.
		 * It is the parent of the root element, e.g. the &lt;OSiL&gt; element in OSiL. It is used
		 * to create all the nodes in the DOM tree.
		 * @return the nonlinear expression starting with the current node in an XML DOM Tree.
		 */
		protected internal override XmlElement getDOMTree(XmlDocument document){
			XmlElement eRoot = document.CreateElement("qpTerm");
			string sAttrValue = getVarOneIndex() + "";
			if(sAttrValue != null && sAttrValue.Length > 0) eRoot.SetAttribute("idxOne", sAttrValue);
			sAttrValue = getVarTwoIndex() + "";
			if(sAttrValue != null && sAttrValue.Length > 0) eRoot.SetAttribute("idxTwo", sAttrValue);
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
		 * @return the variable index of the first variable of the quadratic term.
		 */
		protected internal int getVarOneIndex(){
			return m_iVarOneIdx;
		}//getVarOneIndex

		/**
		 * Set the variable index of the first variable of the quadratic term.
		 *
		 * </p>
		 *
		 * @param varOneIndex holds the variable index of the first variable of the quadratic term.
		 */
		protected internal void setVarOneIndex(int varOneIndex){
			m_iVarOneIdx = varOneIndex;
			if(m_mChildren != null && m_mChildren.Length == 1){
				m_sSymbol = "qpTerm[1]:" + m_iVarOneIdx + ":" + m_iVarTwoIdx + ":" + "1";
			}
			else{
				m_sSymbol = "qpTerm[0]:" + m_iVarOneIdx + ":" + m_iVarTwoIdx + ":" + m_dCoef;
			}
		}//setVarOneIndex

		/**
		 *
		 * @return the variable index of the second variable of the quadratic term.
		 */
		protected internal int getVarTwoIndex(){
			return m_iVarTwoIdx;
		}//getVarTwoIndex

		/**
		 * Set the variable index of the second variable of the quadratic term.
		 *
		 * </p>
		 *
		 * @param varTwoIndex holds the variable index of the second variable of the quadratic term.
		 */
		protected internal void setVarTwoIndex(int varTwoIndex){
			m_iVarTwoIdx = varTwoIndex;
			if(m_mChildren != null && m_mChildren.Length == 1){
				m_sSymbol = "qpTerm[1]:" + m_iVarOneIdx + ":" + m_iVarTwoIdx + ":" + "1";
			}
			else{
				m_sSymbol = "qpTerm[0]:" + m_iVarOneIdx + ":" + m_iVarTwoIdx + ":" + m_dCoef;
			}
		}//setVarTwoIndex

		/**
		 *
		 * @return the the coefficient of the quadratic term.
		 */
		protected internal double getCoef(){
			return m_dCoef;
		}//getCoef

		/**
		 * Set the the coefficient of the quadratic term.
		 *
		 * </p>
		 *
		 * @param coef holds the coefficient of the quadratic term.
		 */
		protected internal void setCoef(double coef){
			m_dCoef = coef;
			m_sSymbol = "qpTerm[0]:" + m_iVarOneIdx + ":" + m_iVarTwoIdx + ":" + m_dCoef;
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


	}//class OSnLNodeQpTerm
}//namespace
