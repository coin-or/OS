/**
 * @(#)OSnLNodeXPath 1.0 03/14/2004
 *
 * Copyright (c) 2004
 */
package org.optimizationservices.oscommon.nonlinear;

import org.optimizationservices.oscommon.util.XPathUtil;
import org.w3c.dom.Document;
import org.w3c.dom.Element;


/**
 *
 * <P>The <code>OSnLNodeXPath</code> class represents an XPath node in an expression tree. An XPath node is mainly used for
 * look up inside an xml document given URI/Path and a bunch of XPath indexes that represent index names and values inside the
 * xml document. it extends the abstract OSnLNode class and implements its abstract methods such as calculateFunction(double[]).
 * </p>
 *
 * </p>
 *
 * @author Robert Fourer, Jun Ma, Kipp Martin
 * @version 1.0, 03/14/2004
 * @see org.optimizationservices.oscommon.nonlinear.OSExpressionTree;
 * @see org.optimizationservices.oscommon.nonlinear.OSnLNode;
 * @see org.optimizationservices.oscommon.nonlinear.OSnLNodeXPathIndex;
 * @since OS 1.0
 */
public class OSnLNodeXPath extends OSnLNode{

	/**
	 * m_sSymbol holds the symbol that this nlNode looks in ASCII.
	 */
	protected String m_sSymbol = "xPath";

	/**
	 * m_sSymbol holds the description of this nlNode
	 */
	protected String m_sDescription = "An xPath lookup function that is used for look up inside an xml document";

	/**
	 * m_iSymbol holds the four digit integer that represents this nlNode, with the leftmost (first)
	 * integer representing the category and the right three digits representing a unique sequence number
	 * in the node category.
	 */
	protected int m_iSymbol = 9008;

	/**
	 * m_iType holds the integer representation of the type of this nlNode.
	 */
	protected int m_iType = -1;

	/**
	 * m_sURI holds the location of the xml document to be looked up.
	 */
	protected String m_sURI = "";

	/**
	 * m_sXMLData holds the data string from the root element &lt;xmlData&gt; of xml data
	 * in an OSiL instance.
	 */
	protected static String m_sXMLData = null;

	/**
	 * m_sPath holds the path within the xml documetn to be looked up.
	 */
	protected String m_sPath = "";

	/**
	 * m_xpathUtil holds the XPathUtility class object used to evaluate XPath.
	 */
	protected XPathUtil m_xpathUtil= null;

	/**
	 * constructor
	 *
	 * </p>
	 *
	 * @param nodes holds the array of node operands (XPathIndexes) to XPath node as loopup xPath index input values.
	 * @param URI holds the location of the xml document to be looked up.
	 * @param path holds the path within the xml documetn to be looked up.
	 * @param xmlData holds the data string from the root element &lt;xmlData&gt; of xml data
	 * in an OSiL instance. This is provided there is no URI supplied or the supplied URI is ".", meaning
	 * the current document where the xpath appears.
	 */
	protected OSnLNodeXPath(OSnLNode[] nodes, String URI, String path, String xmlData){
		m_mChildren = nodes;
		m_sURI = URI;
		m_sPath = path;
		m_sSymbol = "xPath:" + m_sURI + ":" + m_sPath;
		if(URI == null || URI.equals(".")){
			m_sXMLData = xmlData;
			m_xpathUtil = new XPathUtil(m_sXMLData, false);
		}
		else{
			m_xpathUtil = new XPathUtil(m_sURI, true);
		}
	}//constructor

	/**
	 * default constructor
	 */
	protected OSnLNodeXPath(){
	}//constructor

	/**
	 * Calculate the result value of an XPath lookup given the current variable values.
	 *
	 * </p>
	 *
	 * @param x holds the values of the variables in a double array.
	 * @return the result value of the XPath lookup given the current variable values.
	 */
	protected double calculateFunction(double[] x){
		String sPathWithVariableReplaced = m_sPath;
		for(int i = 0; i < (m_mChildren==null?0:m_mChildren.length); i++){
			String sIndexName = ((OSnLNodeXPathIndex)m_mChildren[i]).getIndexName();
			String sIndexValue = ((OSnLNodeXPathIndex)m_mChildren[i]).getIndexValue();
			if(sIndexValue == null || sIndexValue.length() <= 0){
				double dIndexValue = m_mChildren[i].calculateFunction(x);
				if(Double.isNaN(dIndexValue) && m_mChildren[i].m_sFunctionValue != null){
					sIndexValue = m_mChildren[i].m_sFunctionValue;
				}
				else{
					sIndexValue = dIndexValue + "";
				}
			}
			sPathWithVariableReplaced = sPathWithVariableReplaced.replaceAll("\\$" + sIndexName, sIndexValue);
		}
		try{
			m_sFunctionValue = m_xpathUtil.queryFirst(sPathWithVariableReplaced, null);
			m_dFunctionValue = Double.parseDouble(m_sFunctionValue);
			m_sFunctionValue = null;
		}
		catch(Exception e){
			m_dFunctionValue = Double.NaN;
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
		String sPathWithVariableReplaced = m_sPath;
		for(int i = 0; i < (m_mChildren==null?0:m_mChildren.length); i++){
			String sIndexName = ((OSnLNodeXPathIndex)m_mChildren[i]).getIndexName();
			String sIndexValue = ((OSnLNodeXPathIndex)m_mChildren[i]).getIndexValue() + "";
			sPathWithVariableReplaced = sPathWithVariableReplaced.replaceAll("\\$" + sIndexName, sIndexValue);
		}
		try{
			m_sFunctionValue = m_xpathUtil.queryFirst(sPathWithVariableReplaced, null);
		}
		catch(Exception e){
			m_sFunctionValue = null;
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
		for(int i = 0; i < ((m_mChildren == null)?0:m_mChildren.length); i++){
			try{
				m_mChildren[i].m_dNodeDerivative = 0;
				m_mChildren[i].propogateDerivatives(rootNode, x);
			}
			catch(Exception e){
			}
		}
	}//propogateDerivatives

	/**
	 * Calculate the result value of the XPath node derivative given all the current variable values.
	 *
	 * </p>
	 *
	 * @param x holds the values of the variables in a double array.
	 * @param functionEvaluated holds whether the function has been evaluated.
	 * @return the result value of the XPath derivative given all the current variable values.
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
		Element eRoot = document.createElement("xPath");
		String sAttrValue = getURI();
		if(sAttrValue != null && sAttrValue.length() > 0) eRoot.setAttribute("uri", sAttrValue);
		sAttrValue = getPath();
		if(sAttrValue != null && sAttrValue.length() > 0) eRoot.setAttribute("path", sAttrValue);
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
	 * @return the xmlData which holds the data string from the root element &lt;xmlData&gt; of xml data
	 * in an OSiL instance.
	 */
	protected String getXMLData(){
		return m_sXMLData;
	}//getXMLData

	/**
	 * Set the xmlData which holds the data string from the root element &lt;xmlData&gt; of xml data
	 * in an OSiL instance.
	 *
	 * </p>
	 *
	 * @param xmlData holds the data string from the root element &lt;xmlData&gt; of xml data
	 * in an OSiL instance.
	 */
	protected void setXMLData(String xmlData){
		m_sXMLData = xmlData;
	}//setXMLData

	/**
	 *
	 * @return the URI which holds the location of the xml document to be looked up.
	 */
	protected String getURI(){
		return m_sURI;
	}//getURI

	/**
	 * Set the URI which holds the location of the xml document to be looked up.
	 *
	 * </p>
	 *
	 * @param URI holds the location of the xml document to be looked up.
	 */
	protected void setURI(String URI){
		m_sURI = URI;
		m_sSymbol = "xPath:" + m_sURI + ":" + m_sPath;
	}//setURI


	/**
	 *
	 * @return the path within the xml documetn to be looked up.
	 */
	protected String getPath(){
		return m_sPath;
	}//getPath

	/**
	 * Set the value of the path.
	 *
	 * </p>
	 *
	 * @param path holds the location within the xml documetn to be looked up.
	 */
	protected void setPath(String path){
		m_sPath = path;
		m_sSymbol = "xPath:" + m_sURI + ":" + m_sPath;
	}//setPath

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

}//class OSnLNodeXPath
