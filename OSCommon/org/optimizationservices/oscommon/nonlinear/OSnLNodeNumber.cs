using System;
using System.Collections;
using System.Xml;

namespace org.optimizationservices.oscommon.nonlinear{
	/// <summary>
	/// The <c>OSnLNodeNumber</c> class represents a a number node in an expression tree.
	/// It extends the abstract OSnLNode class and implements its abstract methods such as
	/// calculateFunction(double[]).
	/// @author Jun Ma	
	/// @version 1.0, 09/01/2005
	/// @since OS 1.0
	/// @copyright (c) 2005
	/// </summary>
	public class OSnLNodeNumber :OSnLNode{
	

		/**
		 * m_sSymbol holds the symbol that this nlNode looks in ASCII.
		 */
		protected internal string m_sSymbol = "number";

		/**
		 * m_sSymbol holds the description of this nlNode
		 */
		protected internal string m_sDescription = "A number";

		/**
		 * m_iSymbol holds the four digit integer that represents this nlNode, with the leftmost (first)
		 * integer representing the category and the right three digits representing a unique sequence number
		 * in the node category.
		 */
		protected internal int m_iSymbol = 5001;

		/**
		 * m_iType holds the integer representation of the type of this nlNode.
		 */
		protected internal int m_iType = 0;

		/**
		 * m_sNumberType holds the type of the number: real, string, or random.
		 */
		protected internal string m_sNumberType = "real";

		/**
		 * m_sNumberValue holds the value of the number in a string.
		 */
		protected internal string m_sNumberValue = null;

		/**
		 * m_sID holds a unique id of the number so that it can be referred.
		 */
		protected internal string m_sID = "";

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
		protected internal OSnLNodeNumber(string id, string value, string numberType){
			m_sNumberValue = value;
			m_sSymbol = m_sNumberValue;
			if(!numberType.ToLower().Equals("real")
				&& !numberType.ToLower().Equals("string")
				&& !numberType.ToLower().Equals("random")) m_sNumberType = "real";
			if(id != null && id.Length > 0){
				m_sID = id;
			}
			if(!m_sNumberType.Equals("real") || (m_sID != null && m_sID.Length > 0)){
				m_sSymbol = m_sNumberValue + ":" + m_sNumberType + ":" + m_sID;
			}
			else m_sNumberType = numberType;
		}//constructor

		/**
		 * default constructor
		 */
		protected internal OSnLNodeNumber(){
		}//constructor

		/**
		 * Calculate the result value of a number given the current variable values.
		 *
		 * </p>
		 *
		 * @param x holds the values of the variables in a double array.
		 * @return the result value of the number given the current variable values.
		 */
		protected internal override double calculateFunction(double[] x){
			if(!Double.IsNaN(m_dFunctionValue)) return m_dFunctionValue;
			if(getNumberType().Equals("string")){
				m_dFunctionValue = Double.NaN;
				m_sFunctionValue = m_sNumberValue;
			}
			else{
				try{
					m_dFunctionValue = Convert.ToDouble(m_sNumberValue);
				}
				catch(Exception){
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
		protected internal override string calculateFunction(string[] x, bool functionEvaluated){
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
		protected internal override void propogateDerivatives(OSnLNode rootNode, double[] x){
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
		protected internal override double calculateDerivative(double[] x, int index, bool functionEvaluated){
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
		protected internal override XmlElement getDOMTree(XmlDocument document){
			XmlElement eRoot = document.CreateElement("number");
			string sAttrValue = getNumberValue();
			if(sAttrValue != null && sAttrValue.Length > 0) eRoot.SetAttribute("value", sAttrValue);
			else eRoot.SetAttribute("value", "0");
			sAttrValue = getNumberType();
			if(sAttrValue != null && sAttrValue.Length > 0 && !sAttrValue.Equals("real")) eRoot.SetAttribute("type", sAttrValue);
			sAttrValue = getNumberID();
			if(sAttrValue != null && sAttrValue.Length > 0) eRoot.SetAttribute("id", sAttrValue);
			OSnLNode[] mChildren = getChildNodes();
			for(int i = 0; i < ((mChildren == null)?0:mChildren.Length); i++){
				XmlElement eChild = mChildren[i].getDOMTree(document);
				eRoot.AppendChild(eChild);
			}
			return eRoot;
		}//getDOMTree

		/**
		 *
		 * @return the value of the number in a string.
		 */
		protected internal string getNumberValue(){
			return m_sNumberValue;
		}//getNumberValue

		/**
		 * Set the value of the number.
		 *
		 * </p>
		 *
		 * @param value holds the value of the number.
		 */
		protected internal void setNumberValue(string value){
			m_sNumberValue = value;
			m_sSymbol = m_sNumberValue;
		}//setNumberValue

		/**
		 *
		 * @return the type of the number: real, string, or random.
		 */
		protected internal string getNumberType(){
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
		protected internal void setNumberType(string type){
			if(!type.ToLower().Equals("real")
				&& !type.ToLower().Equals("string")
				&& !type.ToLower().Equals("random")) m_sNumberType = "real";
			if(!m_sNumberType.Equals("real")){
				m_sSymbol = m_sNumberValue + ":" + m_sNumberType + ":" + m_sID;
			}
			else m_sNumberType = type;
		}//setNumberType

		/**
		 *
		 * @return the unique id of the number so that it can be referred.
		 */
		protected internal string getNumberID(){
			return m_sID;
		}//getNumberID

		/**
		 * Set the unique id of the number so that it can be referred.
		 *
		 * </p>
		 *
		 * @param id holds the unique id of the number so that it can be referred.
		 */
		protected internal void setNumberID(string id){
			if(id != null && id.Length > 0){
				m_sID = id;
				if(m_sID != null && m_sID.Length > 0){
					m_sSymbol = m_sNumberValue + ":" + m_sNumberType + ":" + m_sID;
				}
			}
		}//setNumberID

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
		protected override internal int getType(){
			return m_iType;
		}//getType

		/**
		 *
		 * @return the description of this nlNode.
		 */
		protected override internal string getDescription(){
			return m_sDescription;
		}//getDescription

	}//class OSnLNodeNumber
}//namespace
