/**
 * @(#)OSExpressionTree 1.0 03/14/2004
 *
 * Copyright (c) 2004
 */
package org.optimizationservices.oscommon.nonlinear;

import it.unimi.dsi.fastutil.ints.Int2DoubleOpenHashMap;
import it.unimi.dsi.fastutil.ints.IntOpenHashSet;
import it.unimi.dsi.fastutil.objects.Object2DoubleOpenHashMap;

import java.util.HashMap;
import java.util.HashSet;
import java.util.Stack;
import java.util.Vector;

import org.optimizationservices.oscommon.representationparser.OSsLReader;
import org.optimizationservices.oscommon.util.CommonUtil;
import org.optimizationservices.oscommon.util.XMLUtil;
import org.optimizationservices.oscommon.util.XPathUtil;
import org.w3c.dom.Document;
import org.w3c.dom.Element;
import org.w3c.dom.Node;

/**
 * 
 * <P>
 * The <code>OSExpressionTree</code> class represents an expression tree for a
 * nonlinear function (linear ones being special cases) and provide convenience
 * methods to process the contained nonlinear function. In essence it contains
 * the root node (of OSnLNode type) of an expression and hides all the internal
 * nodes. It is the only public class that interfaces with any component (e.g. a
 * solver) that needs to manipulate the nonlinear functions in an instance. For
 * example, it is mainly used in the osilReader class to parse a nonlinear
 * optimization instance.
 * </p>
 * 
 * </p>
 * 
 * @author Robert Fourer, Jun Ma, Kipp Martin
 * @version 1.0, 03/14/2004
 * @see org.optimizationservices.oscommon.nonlinear.OSnLNode;
 * @see org.optimizationservices.oscommon.parser.OSiLReader;
 * @since OS 1.0
 */
public class OSExpressionTree{
	/**
	 * m_sPackageName holds the package name of all the nonliner nodes including
	 * the abstract OSnLNode class and the OSExpressionTree class itself.
	 */
	private static String m_sPackageName = "org.optimizationservices.oscommon.nonlinear";
	
	/**
	 * m_sNlNodeStartString holds the common start name of all the
	 * nonlinearNodes. It is immediately followed by the name of each node
	 * operator.
	 */
	private static String m_sNlNodeStartString = "OSnLNode";
	
	/**
	 * m_treeRoot holds the root node (of OSnLNode type) of the expression tree.
	 */
	private OSnLNode m_treeRoot;

	/**
	 * m_numHashMap holds a hash map of number with IDs, with keys being
	 * the number ID and values being the number node.
	 */
	protected static HashMap<String, OSnLNode> m_numHashMap = null;
	
	/**
	 * m_simURIHashMap holds a hash map of simulation URIs, with keys being
	 * simulation names and values being URIs.
	 */
	protected static HashMap<String, String> m_simURIHashMap = null;
	
	/**
	 * m_simOSsLReaderHashMap holds a hash map simulations, with keys being
	 * simulation names and values being OSsLReaders.
	 */
	protected static HashMap<String, OSsLReader> m_simOSsLReaderHashMap = null;
	
	/**
	 * m_userFNumArgHashMap holds a hash map of userFunction number of arguments
	 * (numArg), with keys being user function names and values being number of
	 * arguments.
	 */
	protected static HashMap<String, String> m_userFNumArgHashMap = null;
	
	/**
	 * m_userFRootNodeHashMap holds a hash map of userFunction root nodes, with
	 * keys being user function names and values being userFunction root nodes
	 * of OSnLNode class type.
	 */
	protected static HashMap<String, OSnLNode> m_userFRootNodeHashMap = null;
	
	/**
	 * m_eXmlData holds the root element &lt;xmlData&gt; of xml data in an OSiL
	 * instance.
	 */
	protected static Element m_eXmlData = null;

	/**
	 * Get the root node of the expression tree.
	 * 
	 * </p>
	 * 
	 * @return the treeRoot that holds the root node (of OSnLNode type) of the
	 *         expression tree.
	 */
	public OSnLNode getRootNode(){
		return m_treeRoot;
	}//getRootNode

	/**
	 * Set the root node of the expression tree.
	 * 
	 * </p>
	 * 
	 * @param treeRoot
	 *            holds the root node (of OSnLNode type) of the expression tree.
	 */
	public void setRootNode(OSnLNode treeRoot){
		m_treeRoot = treeRoot;
		OSnLNode.m_treeRoot = m_treeRoot;
	}//setRootNode
	
	/**
	 * Constructor.
	 */
	public OSExpressionTree(){
		OSnLNode.m_treeRoot = m_treeRoot;
	}//constructor

	/**
	 * Constructor
	 * 
	 * </p>
	 * 
	 * @param expressionTreeRoot
	 *            holds the XML element from an OSiL instance that represents a
	 *            root node of the expression tree.
	 * @param documentRoot
	 *            holds the XML element from an OSiL instance that represents a
	 *            root node of the whole OSiL document. This root element of the
	 *            document is necessary because some of the node in the
	 *            expression tree can point to infomation outside of the
	 *            expression tree, which cannot be accessed through
	 *            expressionTreeRoot, but can be accessed through documentRoot.
	 */
	public OSExpressionTree(Element expressionTreeRoot, Element documentRoot){
		setGlobalDefinition(documentRoot);
		m_treeRoot = setExpressionTree(expressionTreeRoot);
		OSnLNode.m_treeRoot = m_treeRoot;
	}//constructor

	/**
	 * Constructor
	 * 
	 * </p>
	 * 
	 * @param tokenizedExpression holds the expression tokenized in a string vector in either postfix, prefix, or infix.
	 * The operator name in each token has to be exactly the same as the name specified in the OSnL Schema. 
	 * The operator name in the token may be followed (without space) by a sequence of ":atrributeValue" and end with
	 * [i] to indicate the number of arguments the operator can take if the operator's type is indefinite. 
	 * The attributes specified have to follow the sequence in the OSnL schema.  
	 * If one attribute is specified, all attributes have to be specified together. If an attribute 
	 * is missing, an empty string has to be in place. Two alternative exception can be allowed for variable 
	 * and number. A number can just a a numeric value and the variable can take the form Xi where i is the 
	 * integer index of capital letter X. 
	 * @param type holds whether the expression is in postfix, prefix or infix
	 * @param start holds the index of the tokenizedExpression to start processing. 
	 * @param end holds the index of the tokenizedExpression to finish processing. 
	 */
	public OSExpressionTree(Vector tokenizedExpression, String type, int start, int end){
		if(type.equalsIgnoreCase("postfix")) m_treeRoot = setExpressionTreeFromPostfix(tokenizedExpression, start, end);
		else if(type.equalsIgnoreCase("prefix")) m_treeRoot = setExpressionTreeFromPrefix(tokenizedExpression, start, end);
		else if(type.equalsIgnoreCase("infix")) m_treeRoot = setExpressionTreeFromInfix(tokenizedExpression, start, end);
		else m_treeRoot = null;
		OSnLNode.m_treeRoot = m_treeRoot;
	}//constructor
	
	/**
	 * clone an expression tree to a new copy.
	 * 
	 * @return the cloned copy of the current OS expression tree.  
	 */
	public OSExpressionTree clone(){
		Vector<String> vPostfix = this.getPostfix();
		int iSize = vPostfix==null?0:vPostfix.size();
		return new OSExpressionTree(vPostfix, "postfix", 0, iSize-1);
	}//clone
	
	/**
	 * Set global definitions such as defined userFunctions, simulations,
	 * xmlData etc that are used by all the expression trees.
	 * 
	 * </p>
	 * 
	 * @param documentRoot
	 *            holds the XML element from an OSiL instance that represents a
	 *            root node of the whole OSiL document. This root element of the
	 *            document is necessary because some of the node in the
	 *            expression tree can point to infomation outside of the
	 *            expression tree, which cannot be accessed through
	 *            expressionTreeRoot, but can be accessed through documentRoot.
	 */
	public void setGlobalDefinition(Element documentRoot){
		if (m_simURIHashMap == null){
			m_simURIHashMap = new HashMap<String, String>();
			m_simOSsLReaderHashMap = new HashMap<String, OSsLReader>();
			Element eInstanceData = (Element)XMLUtil.findChildNode(documentRoot, "instanceData");
			Element eSimulations = (Element)XMLUtil.findChildNode(eInstanceData, "simulations");
			Vector<Element> vNodeListSim = null;
			if (eSimulations != null)
				vNodeListSim = XMLUtil.getChildElementsByTagName(eSimulations, "simulation");
			int iNls = (vNodeListSim == null)?0:vNodeListSim.size();
			for (int i = 0; i < iNls; i++){
				String sSimName = ((Element) (vNodeListSim.elementAt(i))).getAttribute("name");
				Element eURI = (Element) (XMLUtil.findChildNode((Element)vNodeListSim.elementAt(i),"uri"));
				String sURIValue = eURI.getAttribute("value");
				OSsLReader osslReader = new OSsLReader();
				Element eOSsL = (Element) (XMLUtil.findChildNode((Element)vNodeListSim.elementAt(i),"ossl")); 
				osslReader.setRootElement(eOSsL);
				osslReader.setDocument((Document)documentRoot.getParentNode());
				m_simURIHashMap.put(sSimName, sURIValue);
				m_simOSsLReaderHashMap.put(sSimName, osslReader);
			}
		}
		if (m_userFNumArgHashMap == null){
			m_userFNumArgHashMap = new HashMap<String, String>();
			m_userFRootNodeHashMap = new HashMap<String, OSnLNode>();
			Element eInstanceData = (Element)XMLUtil.findChildNode(documentRoot, "instanceData");
			Element eUserFunctions = (Element)XMLUtil.findChildNode(eInstanceData, "userFunctions"); 
			Vector<Element> vNodeListUserF = null;
			if (eUserFunctions != null)
				vNodeListUserF = XMLUtil.getChildElementsByTagName(eUserFunctions, "userFunction");
			int iNls = vNodeListUserF == null?0:vNodeListUserF.size();
			for (int i = 0; i < iNls; i++){
				Element eUserF = (Element) vNodeListUserF.elementAt(i);
				String sUserFName = eUserF.getAttribute("name");
				Element eUserFRoot = null;
				for (Node child = eUserF.getFirstChild(); child != null; child = child
				.getNextSibling()){
					if (child instanceof Element){
						eUserFRoot = (Element) child;
						break;
					}
				}
				if (eUserFRoot.getLocalName().startsWith("math"))
					continue;
				String sNumArg = eUserF.getAttribute("numArg");
				OSnLNode userFunctionRootNode = setExpressionTree(eUserFRoot);
				m_userFNumArgHashMap.put(sUserFName, sNumArg);
				m_userFRootNodeHashMap.put(sUserFName, userFunctionRootNode);
			}
		}
		if (m_eXmlData == null){
			Element eInstanceData = (Element)XMLUtil.findChildNode(documentRoot, "instanceData");
			m_eXmlData = (Element)XMLUtil.findChildNode(eInstanceData, "xmlData");
		}
	}//setGlobalDefinition
	
	/**
	 * Set the expression tree with an XML element from an OSiL instance that
	 * represents a root node of the expression tree.
	 * 
	 * </p>
	 * 
	 * @param expressionTreeRoot
	 *            holds the XML element from an OSiL instance that represents a
	 *            root node of the expression tree.
	 */
	public OSnLNode setExpressionTree(Element expressionTreeRoot){
		OSnLNode nlNode = convertElementToNlNode(expressionTreeRoot);
		Vector<OSnLNode> vChrildren = new Vector<OSnLNode>();
		for (Node child = expressionTreeRoot.getFirstChild(); child != null; child = child
		.getNextSibling()){
			if (child instanceof Element){
				OSnLNode childNlNode = convertElementToNlNode((Element) child);
				setExpressionTreeRecursively((Element) child, childNlNode);
				vChrildren.add(childNlNode);
			} else{
				; //do nothing -- s stopping case
			}
		}
		nlNode.setChildNodes(vChrildren);
		return nlNode;
	}//setExpressionTree
	
	/**
	 * Set the expression tree with an XML elements from an OSiL instance that
	 * represents an internal node of the expression tree.
	 * 
	 * </p>
	 * 
	 * @param expressionTreeNode
	 *            holds the XML element from an OSiL instance that represents an
	 *            internal node of the expression tree.
	 * @param parentNlNode
	 *            holds the parent nlNode for the internal (child) nodes to be
	 *            appended to.
	 */
	private void setExpressionTreeRecursively(Element expressionTreeNode,
			OSnLNode parentNlNode){
		Vector<OSnLNode> vChrildren = new Vector<OSnLNode>();
		for (Node child = expressionTreeNode.getFirstChild(); child != null; child = child
		.getNextSibling()){
			if (child instanceof Element){
				OSnLNode childNlNode = convertElementToNlNode((Element) child);
				setExpressionTreeRecursively((Element) child, childNlNode);
				vChrildren.add(childNlNode);
			} else{
				; //do nothing -- s stopping case
			}
		}
		parentNlNode.setChildNodes(vChrildren);
	}//setExpressionTreeRecursively
	
	/**
	 * Convert an XML element from an OSiL instance that represents a node to an
	 * OSnLNode instance.
	 * 
	 * </p>
	 * 
	 * @param xmlEleTreeRoot
	 *            holds the XML element from an OSiL instance that represents an
	 *            expression tree node.
	 * @param documentRoot
	 *            holds the XML element from an OSiL instance that represents a
	 *            root node of the whole OSiL document. This root element of the
	 *            document is necessary because some of the node in the
	 *            expression tree can point to infomation outside of the
	 *            expression tree, which cannot be accessed through
	 *            expressionTreeRoot, but can be accessed through documentRoot.
	 * @return the converted root node (of OSnLNode type) of the expression
	 *         tree.
	 */
	private OSnLNode convertElementToNlNode(Element ele){
		OSnLNode nlNode = null;
		String sNodeName = "";
		try{
			sNodeName = ele.getLocalName();
			String sNlNodeClass = m_sPackageName + "." + m_sNlNodeStartString
			+ sNodeName.substring(0, 1).toUpperCase()
			+ sNodeName.substring(1);
			Class nlNodeClass = Class.forName(sNlNodeClass);
			nlNode = (OSnLNode) nlNodeClass.newInstance();
		} catch (ClassNotFoundException e){
			e.printStackTrace();
		} catch (InstantiationException e){
			e.printStackTrace();
		} catch (IllegalAccessException e){
			e.printStackTrace();
		} catch (Exception e){
			e.printStackTrace();
		}
		if (sNodeName.equalsIgnoreCase("number")){
			String sValue = ele.getAttribute("value");
			if (sValue != null && sValue.length() > 0){
				((OSnLNodeNumber) nlNode).setNumberValue(sValue);
			} 
			else{
				((OSnLNodeNumber) nlNode).setNumberValue(null);
			}
			String sType = ele.getAttribute("type");
			if (sType != null && sType.length() > 0){
				((OSnLNodeNumber) nlNode).setNumberType(sType);
			} 
			else{
				((OSnLNodeNumber) nlNode).setNumberType("real");
			}
			String sID = ele.getAttribute("id");
			if (sID != null && sID.length() > 0){
				((OSnLNodeNumber) nlNode).setNumberID(sID);
				if(m_numHashMap == null) m_numHashMap = new HashMap<String, OSnLNode>();
				m_numHashMap.put(sID, nlNode);
			}
		}
		if (sNodeName.equalsIgnoreCase("identifier")){
			String sName = ele.getAttribute("name");
			if (sName != null && sName.length() > 0){
				((OSnLNodeIdentifier) nlNode).setIdentifierName(sName);
			}
		}
		if (sNodeName.equalsIgnoreCase("variable")){
			String sIdx = ele.getAttribute("idx");
			if (sIdx != null && sIdx.length() > 0){
				((OSnLNodeVariable) nlNode).setIndex(Integer.parseInt(sIdx));
			}
			String sCoef = ele.getAttribute("coef");
			if (sCoef != null && sCoef.length() > 0){
				((OSnLNodeVariable) nlNode).setCoef(Double.parseDouble(sCoef));
			}
		}
		if (sNodeName.equalsIgnoreCase("qTerm")){
			String sIdxOne = ele.getAttribute("idxOne");
			if (sIdxOne != null && sIdxOne.length() > 0){
				((OSnLNodeQTerm) nlNode).setVarOneIndex(Integer
						.parseInt(sIdxOne));
			}
			String sIdxTwo = ele.getAttribute("idxTwo");
			if (sIdxTwo != null && sIdxTwo.length() > 0){
				((OSnLNodeQTerm) nlNode).setVarTwoIndex(Integer
						.parseInt(sIdxTwo));
			}
			String sCoef = ele.getAttribute("coef");
			if (sCoef != null && sCoef.length() > 0){
				((OSnLNodeQTerm) nlNode).setCoef(Double.parseDouble(sCoef));
			}
		}
		if (sNodeName.equalsIgnoreCase("sim")){
			String sName = ele.getAttribute("name");
			if (sName != null && sName.length() > 0){
				((OSnLNodeSim) nlNode).setSimName(sName);
			}
			((OSnLNodeSim) nlNode).setURI((String) m_simURIHashMap.get(sName));
			((OSnLNodeSim) nlNode)
			.setOSsLReader((OSsLReader) m_simOSsLReaderHashMap
					.get(sName));
		}
		if (sNodeName.equalsIgnoreCase("simInput")){
			String sSimName = ele.getAttribute("simName");
			if (sSimName != null && sSimName.length() > 0){
				((OSnLNodeSimInput) nlNode).setSimName(sSimName);
			} else{
				Element eParentSim = (Element) ele.getParentNode();
				String sParentSimName = "";
				if (eParentSim.getLocalName().startsWith("sim")){
					sParentSimName = eParentSim.getAttribute("simName");
					if (sParentSimName.length() <= 0)
						sParentSimName = eParentSim.getAttribute("name");
				}
				while (sParentSimName.length() <= 0){
					eParentSim = (Element) eParentSim.getParentNode();
					if (eParentSim.getLocalName().startsWith("sim")){
						sParentSimName = eParentSim.getAttribute("simName");
						if (sParentSimName.length() <= 0)
							sParentSimName = eParentSim.getAttribute("name");
					}
				}
				((OSnLNodeSimInput) nlNode).setSimName(sParentSimName);
			}
			String sInputName = ele.getAttribute("inputName");
			if (sInputName != null && sInputName.length() > 0){
				((OSnLNodeSimInput) nlNode).setInputName(sInputName);
			}
			((OSnLNodeSimInput) nlNode).setURI((String) m_simURIHashMap
					.get(sSimName));
			((OSnLNodeSimInput) nlNode)
			.setOSsLReader((OSsLReader) m_simOSsLReaderHashMap
					.get(sSimName));
		}
		if (sNodeName.equalsIgnoreCase("simOutput")){
			String sSimName = ele.getAttribute("simName");
			if (sSimName != null && sSimName.length() > 0){
				((OSnLNodeSimOutput) nlNode).setSimName(sSimName);
			} else{
				Element eParentSim = (Element) ele.getParentNode();
				String sParentSimName = "";
				if (eParentSim.getLocalName().startsWith("sim")){
					sParentSimName = eParentSim.getAttribute("simName");
					if (sParentSimName.length() <= 0)
						sParentSimName = eParentSim.getAttribute("name");
				}
				while (sParentSimName.length() <= 0){
					eParentSim = (Element) eParentSim.getParentNode();
					if (eParentSim.getLocalName().startsWith("sim")){
						sParentSimName = eParentSim.getAttribute("simName");
						if (sParentSimName.length() <= 0)
							sParentSimName = eParentSim.getAttribute("name");
					}
				}
				((OSnLNodeSimOutput) nlNode).setSimName(sParentSimName);
			}
			String sOutputName = ele.getAttribute("outputName");
			if (sOutputName != null && sOutputName.length() > 0){
				((OSnLNodeSimOutput) nlNode).setOutputName(sOutputName);
			}
			((OSnLNodeSimOutput) nlNode).setURI((String) m_simURIHashMap.get(sSimName));
			((OSnLNodeSimOutput) nlNode).setOSsLReader((OSsLReader) m_simOSsLReaderHashMap
					.get(sSimName));
		}
		if (sNodeName.equalsIgnoreCase("userF")){
			String sName = ele.getAttribute("name");
			if (sName != null && sName.length() > 0){
				((OSnLNodeUserF) nlNode).setUserFName(sName);
			}
			((OSnLNodeUserF) nlNode).setNumArg(Integer.parseInt((String) m_userFNumArgHashMap.get(sName)));
			((OSnLNodeUserF) nlNode).setRootNode((OSnLNode) m_userFRootNodeHashMap.get(sName));
		}
		if (sNodeName.equalsIgnoreCase("arg")){
			String sIdx = ele.getAttribute("idx");
			if (sIdx != null && sIdx.length() > 0){
				((OSnLNodeArg) nlNode).setArgumentIndex(Integer.parseInt(sIdx));
			}
		}
		if (sNodeName.equalsIgnoreCase("xPath")){
			String sURI = ele.getAttribute("uri");
			if (sURI != null && sURI.length() > 0 && !sURI.equals(".")){
				((OSnLNodeXPath) nlNode).setURI(sURI);
				((OSnLNodeXPath) nlNode).m_xpathUtil = new XPathUtil(sURI, true);
			} else{ 
				((OSnLNodeXPath) nlNode).setURI(".");
				if (OSnLNodeXPath.m_sXMLData == null)
					((OSnLNodeXPath) nlNode).setXMLData(XMLUtil.writeXMLElementToString(m_eXmlData));
				((OSnLNodeXPath) nlNode).m_xpathUtil = new XPathUtil(
						OSnLNodeXPath.m_sXMLData, false);
			}
			String sPath = ele.getAttribute("path");
			if (sPath != null && sPath.length() > 0){
				((OSnLNodeXPath) nlNode).setPath(sPath);
			}
		}
		if (sNodeName.equalsIgnoreCase("xPathIndex")){
			String sIndexName = ele.getAttribute("indexName");
			if (sIndexName != null && sIndexName.length() > 0){
				((OSnLNodeXPathIndex) nlNode).setIndexName(sIndexName);
			}
			String sIndexValue = ele.getAttribute("indexValue");
			if (sIndexValue != null && sIndexValue.length() > 0){
				((OSnLNodeXPathIndex) nlNode).setIndexValue(sIndexValue);
			}
		}
		if (sNodeName.equalsIgnoreCase("nodeRef")){
			String sNetworkNodeID = ele.getAttribute("nodeID");
			if (sNetworkNodeID != null && sNetworkNodeID.length() > 0){
				((OSnLNodeNodeRef) nlNode).setNodeID(Integer.parseInt(sNetworkNodeID));
			}
			String sPropName = ele.getAttribute("propName");
			if (sPropName != null && sPropName.length() > 0){
				((OSnLNodeNodeRef) nlNode).setPropName(sPropName);
			}
		}
		if (sNodeName.equalsIgnoreCase("arcRef")){
			String sNetworkArcID = ele.getAttribute("arcID");
			if (sNetworkArcID != null && sNetworkArcID.length() > 0){
				((OSnLNodeArcRef) nlNode).setArcID(Integer.parseInt(sNetworkArcID));
			}
			String sPropName = ele.getAttribute("propName");
			if (sPropName != null && sPropName.length() > 0){
				((OSnLNodeArcRef) nlNode).setPropName(sPropName);
			}
		}
		return nlNode;
	}//convertElementToNlNode
	
	/**
	 * Set the expression tree with from a tokenized string vector in postfix format.  
	 * 
	 * </p>
	 * 
	 * @param tokenizedExpression holds the expression tokenized in a string vector in postfix. 
	 * The operator name in the token may be followed (without space) by a sequence of ":atrributeValue" and end with
	 * [i] to indicate the number of arguments the operator can take if the operator's type is indefinite. 
	 * The attributes specified have to follow the sequence in the OSnL schema.  
	 * If one attribute is specified, all attributes have to be specified together. If an attribute 
	 * is missing, an empty string has to be in place. Two alternative exception can be allowed for variable 
	 * and number. A number can just a a numeric value and the variable can take the form Xi where i is the 
	 * integer index of capital letter X.  
	 * @param start holds the index of the tokenizedExpression to start processing. 
	 * @param end holds the index of the tokenizedExpression to finish processing.
	 * @return the tree root of the expression tree.  
	 */
	public OSnLNode setExpressionTreeFromPostfix(Vector tokenizedExpression, int start, int end){
		Stack<OSnLNode> stack = new Stack<OSnLNode>();
		OSnLNode nlNode = null;
		for(int i = start; i <= end; i++){
			String sToken = (String)tokenizedExpression.elementAt(i);
			nlNode = convertStringTokenToNlNode(sToken);
			int iArgNum = getArgumentNumber(nlNode, sToken);
			if(iArgNum == 0){
				stack.push(nlNode);
			}
			else{
				OSnLNode[] mChildren = new OSnLNode[iArgNum];
				for(int j = iArgNum - 1; j >= 0; j--){
					mChildren[j] = (OSnLNode)stack.pop();
				}
				nlNode.setChildNodes(mChildren);
				stack.push(nlNode);
			}
		}
		OSnLNode root = (OSnLNode)stack.pop();
		if(!stack.isEmpty()) return null;
		return root;
	}//setExpressionTreeFromPostFix

	/**
	 * Set the expression tree with from a tokenized string vector in prefix format.  
	 * 
	 * </p>
	 * 
	 * @param tokenizedExpression holds the expression tokenized in a string vector in prefix. 
	 * The operator name in the token may be followed (without space) by a sequence of ":atrributeValue" and end with
	 * [i] to indicate the number of arguments the operator can take if the operator's type is indefinite. 
	 * The attributes specified have to follow the sequence in the OSnL schema.  
	 * If one attribute is specified, all attributes have to be specified together. If an attribute 
	 * is missing, an empty string has to be in place. Two alternative exception can be allowed for variable 
	 * and number. A number can just a a numeric value and the variable can take the form Xi where i is the 
	 * integer index of capital letter X.  
	 * @param start holds the index of the tokenizedExpression to start processing. 
	 * @param end holds the index of the tokenizedExpression to finish processing. 
	 * @return the tree root of the expression tree.  
	 */
	public OSnLNode setExpressionTreeFromPrefix(Vector tokenizedExpression, int start, int end){
		Stack<OSnLNode> stack = new Stack<OSnLNode>();
		OSnLNode nlNode = null;
		for(int i = end; i >= start ; i--){
			String sToken = (String)tokenizedExpression.elementAt(i);
			nlNode = convertStringTokenToNlNode(sToken);
			int iArgNum = getArgumentNumber(nlNode, sToken);
			if(iArgNum == 0){
				stack.push(nlNode);
			}
			else{
				OSnLNode[] mChildren = new OSnLNode[iArgNum];
				for(int j =  0; j < iArgNum; j++){
					mChildren[j] = (OSnLNode)stack.pop();
				}
				nlNode.setChildNodes(mChildren);
				stack.push(nlNode);
			}
		}
		OSnLNode root = (OSnLNode)stack.pop();
		if(!stack.isEmpty()) return null;
		return root;
	}//setExpressionTreeFromPreFix

	/**
	 * Set the expression tree with from a tokenized string vector in infix format.  
	 * 
	 * </p>
	 * 
	 * @param tokenizedExpression holds the expression tokenized in a string vector in infix. 
	 * The operator name in the token may be followed (without space) by a sequence of ":atrributeValue" and end with
	 * [i] to indicate the number of arguments the operator can take if the operator's type is indefinite. 
	 * The attributes specified have to follow the sequence in the OSnL schema.  
	 * If one attribute is specified, all attributes have to be specified together. If an attribute 
	 * is missing, an empty string  has to be in place. Two alternative exception can be allowed for variable 
	 * and number. A number can just a a numeric value and the variable can take the form Xi where i is the 
	 * integer index of capital letter X.  
	 * @param start holds the index of the tokenizedExpression to start processing. 
	 * @param end holds the index of the tokenizedExpression to finish processing. 
	 * @return the tree root of the expression tree.  
	 */
	public OSnLNode setExpressionTreeFromInfix(Vector tokenizedExpression, int start, int end){
		Stack<Object> stack1 = new Stack<Object>();
		Vector<Object> vOutput = new Vector<Object>();
		OSnLNode nlNode = null;
		int iArgNum = 0;
		int iPrecedence = 0;
		int iPreviousPrecedence = 0;
		for(int i = start; i <= end ; i++){
			iPreviousPrecedence = iPrecedence;
			String sToken = (String)tokenizedExpression.elementAt(i);
			if(sToken.equals("(")){
				iPrecedence = 0;
				stack1.push(sToken);
			}
			else if(sToken.equals(")")){
				iPrecedence = 0;
				Object obj;
				boolean bCont = true;
				while(bCont){
					obj = stack1.pop();
					try{
						nlNode = (OSnLNode)obj;
						vOutput.add(nlNode);
					}
					catch(Exception e){
						if(!stack1.isEmpty()){
							try{
								if(((OSnLNode)stack1.peek()).getPrecedence() < 200){
									vOutput.add(stack1.pop());
								}
							}
							catch(Exception e2){								
							}
						}
						bCont = false;
					}
				}
			}
			else{
				nlNode = convertStringTokenToNlNode(sToken); 
				iArgNum = getArgumentNumber(nlNode, sToken);
				iPrecedence = nlNode.getPrecedence();
				if((iPrecedence < 200 || nlNode.getSymbol().equals("negate")) && iPreviousPrecedence < 200){
					Object obj;
					boolean bCont = true;
					if(stack1.isEmpty())bCont = false;
					try{
						 if(((String)stack1.peek()).equals("(")) bCont = false;
					}
					catch(Exception e){}
					while(bCont){
						obj = stack1.pop();
						try{
							OSnLNode stackNode = (OSnLNode)obj;
							vOutput.add(stackNode);
						}
						catch(Exception e){
							bCont = false;
						}
						if(stack1.isEmpty()) bCont = false;
						try{
							 if(((String)stack1.peek()).equals("(")) bCont = false;
						}
						catch(Exception e){}
					}
				}
				if(iArgNum == 0){
					nlNode.m_mChildren = null;
					vOutput.add(nlNode);
				}
				else{
					nlNode.m_mChildren = new OSnLNode[iArgNum];
					boolean bCont = true;
					if(stack1.isEmpty()){
						stack1.push(nlNode);
						bCont = false;
					}
					while(bCont){
						try{
							OSnLNode stackNlNode = (OSnLNode)stack1.peek();
							int iStackPrecedence = stackNlNode.getPrecedence();
							if(iPrecedence >= iStackPrecedence && 
									!(nlNode.getSymbol().equals("power") && stackNlNode.getSymbol().equals("power"))){
								vOutput.add(stack1.pop());
								if(stack1.isEmpty()){
									stack1.push(nlNode);
									bCont = false;
								}
							}
							else{
								stack1.push(nlNode);
								bCont = false;
							}
						}
						catch(Exception e){
							stack1.push(nlNode);
							bCont = false;
						}
					}
				}
			}
		}
		while(!stack1.isEmpty()){
			vOutput.add(stack1.pop());
		}
		Stack<OSnLNode> stack2 = new Stack<OSnLNode>();
		for(int i = 0; i < vOutput.size(); i++){
			nlNode = (OSnLNode)vOutput.elementAt(i);
			iArgNum = (nlNode.getChildNodes()==null)?0:nlNode.getChildNodes().length;
			if(iArgNum == 0){
				stack2.push(nlNode);
			}
			else{
				for(int j = iArgNum - 1; j >= 0; j--){
					nlNode.m_mChildren[j] = (OSnLNode)stack2.pop();
				}
				stack2.push(nlNode);
			}
		}
		OSnLNode root = (OSnLNode)stack2.pop();
		if(!stack2.isEmpty()) return null;
		return root;
	}//setExpressionTreeFromInFix

	
	/**
	 * Get the number arguments from an OSnLNode. If the operator's type is indefinite, the number of arguments
	 * will be obtained from the provided token.
	 * 
	 * </p>
	 * 
	 * @param holds the OSnLNode to find the the number arguments of this operator. 
	 * @param token holds a string token from a postfix/prefix/infix string. 
	 * The operator name in the token may be followed (without space) by a sequence of ":atrributeValue" and end with
	 * [i] to indicate the number of arguments the operator can take if the operator's type is indefinite. 
	 * The attributes specified have to follow the sequence in the OSnL schema.  
	 * If one attribute is specified, all attributes have to be specified together. If an attribute 
	 * is missing, an empty string has to be in place. Two alternative exception can be allowed for variable 
	 * and number. A number can just a a numeric value and the variable can take the form Xi where i is the 
	 * integer index of capital letter X.  
	 * @return the converted root node (of OSnLNode type) of the expression tree.
	 */
	private int getArgumentNumber(OSnLNode node, String token){
		int iArg = node.getType();
		if(iArg == -1){
			int i1 = token.lastIndexOf("[");
			int i2 = token.lastIndexOf("]");
			if(token.startsWith("X") && i1 == -1) iArg = 0;
			else if(token.startsWith("variable") && i1 == -1) iArg = 0;
			else{
				String sArg = token.substring(i1+1, i2);
				try{
					iArg = Integer.parseInt(sArg);
				}
				catch(Exception e){
					iArg = 0;
				}
			}
		}
		return iArg;
	}
	/**
	 * Convert a string token from a postfix/prefix/infix string to an OSnLNode instance.
	 * 
	 * </p>
	 * 
	 * @param token holds a string token from a postfix/prefix/infix string. 
	 * The operator name in the token may be followed (without space) by a sequence of ":atrributeValue" and end with
	 * [i] to indicate the number of arguments the operator can take if the operator's type is indefinite. 
	 * The attributes specified have to follow the sequence in the OSnL schema.  
	 * If one attribute is specified, all attributes have to be specified together. If an attribute 
	 * is missing, an empty string has to be in place. Two alternative exception can be allowed for variable 
	 * and number. A number can just a a numeric value and the variable can take the form Xi where i is the 
	 * integer index of capital letter X.  
	 * @return the converted root node (of OSnLNode type) of the expression tree.
	 */
	private OSnLNode convertStringTokenToNlNode(String token){
		OSnLNode nlNode = null;
		String sNodeName = ""; 
		
		try{
			try{
				Double.parseDouble(token);
				sNodeName = "number";
			}
			catch(Exception e){
				if(token.startsWith("X") || (token.startsWith("variable"))){
					sNodeName = "variable";
				}
				else{
					int i1 = token.indexOf(":");
					int i2 = token.lastIndexOf("[");
					if(i1 != -1) sNodeName = token.substring(0, i1);
					else if(i2 != -1) sNodeName = token.substring(0, i2);
					else sNodeName = token;
				}				
			}
			if(token.equals("+")) sNodeName = "plus"; 
			else if(token.equals("-")) sNodeName = "minus"; 
			else if(token.equals("(-)")) sNodeName = "negate"; 
			else if(token.equals("*")) sNodeName = "times";
			else if(token.equals("/")) sNodeName = "divide";
			else if(token.equals("^")) sNodeName = "power";

			String sNlNodeClass = m_sPackageName + "." + m_sNlNodeStartString
			+ sNodeName.substring(0, 1).toUpperCase()
			+ sNodeName.substring(1);
			Class nlNodeClass = Class.forName(sNlNodeClass);
			nlNode = (OSnLNode) nlNodeClass.newInstance();
		} 
		catch (ClassNotFoundException e){
			nlNode = new OSnLNodeNumber(null, sNodeName, "string");
			e.printStackTrace();
		} 
		catch (InstantiationException e){
			e.printStackTrace();
		} 
		catch (IllegalAccessException e){
			e.printStackTrace();
		} 
		catch (Exception e){
			e.printStackTrace();
		}
		int i1 = token.indexOf(":");
		if(i1 == -1) i1 = token.length();
		int i2 = token.indexOf(":", i1+1);
		if(i2 == -1) i2 = token.length();
		int i3 = token.indexOf(":", i2+1);	
		if(i3 == -1) i3 = token.length();
		int j = token.lastIndexOf("[");
		if(j == -1) j = token.length();
		if(i1 >= j) i1 = j;
		if(i2 >= j) i2 = j;
		if(i3 >= j) i3 = j;
		boolean bSimpleNum = false;
		if (sNodeName.equalsIgnoreCase("number")){
			try{
				Double.parseDouble(token);
				bSimpleNum = true;
			}
			catch(Exception e){
				
			}
			if(bSimpleNum){
				((OSnLNodeNumber) nlNode).setNumberValue(token);
			}
			else{
				String sValue = token.substring(i1+1, i2);
				if (sValue != null && sValue.length() > 0 && !sValue.equalsIgnoreCase("null")){
					((OSnLNodeNumber) nlNode).setNumberValue(sValue);
				} 
				else{
					((OSnLNodeNumber) nlNode).setNumberValue(null);
				}
				String sType = token.substring(i2+1, i3);
				if (sType != null && sType.length() > 0 && !sType.equalsIgnoreCase("null")){
					((OSnLNodeNumber) nlNode).setNumberType(sType);
				} 
				else{
					((OSnLNodeNumber) nlNode).setNumberType("real");
				}
				String sID = token.substring(i3+1, j);
				if (sID != null && sID.length() > 0 && !sID.equalsIgnoreCase("null")){
					((OSnLNodeNumber) nlNode).setNumberID(sID);
					if(m_numHashMap == null) m_numHashMap = new HashMap<String, OSnLNode>();
					m_numHashMap.put(sID, nlNode);
				}
			}
		}
		if (sNodeName.equalsIgnoreCase("identifier")){
			String sName = token.substring(i1+1, j);
			if (sName != null && sName.length() > 0 && !sName.equalsIgnoreCase("null")){
				((OSnLNodeIdentifier) nlNode).setIdentifierName(sName);
			}
		}
		if (sNodeName.equalsIgnoreCase("variable")){
			String sIdx = "";
			int j1 = token.lastIndexOf("[");
			int j2 = token.lastIndexOf("]");
			int nArg = 0;
			if(j1 >= 0){
				nArg = Integer.parseInt(token.substring(j+1, j2));
			}
			if(token.startsWith("variable")){
				if(nArg == 0){
					if(token.charAt(8) != ':'){
						sIdx = token.substring(8, i1);			
					}
					else{
						sIdx = token.substring(i1+1, i2);
					}
				}
			}
			else{ 
				if(nArg == 0){
					if(token.charAt(1) != ':'){
						sIdx = token.substring(1, i1);			
					}
					else{
						sIdx = token.substring(i1+1, i2);
					}
				}
			}
			if (sIdx != null && sIdx.length() > 0 && !sIdx.equalsIgnoreCase("null")){
				((OSnLNodeVariable) nlNode).setIndex(Integer.parseInt(sIdx));
			}
			String sCoef = "";
			if(token.startsWith("variable")){
				if(nArg == 0){
					if(token.charAt(8) != ':'){
						if(i1+1 >= j) sCoef = null;
						else sCoef = token.substring(i1+1, j);	
					}
					else{
						if(i2+1 >= j) sCoef = null;
						else sCoef = token.substring(i2+1, j);
					}
				}
				else{
					if(i1+1 >= j) sCoef = null;
					else sCoef = token.substring(i1+1, j);			
				}
			}
			else{
				if(nArg == 0){
					if(token.charAt(1) != ':'){
						if(i1+1 >= j) sCoef = null;
						else sCoef = token.substring(i1+1, j);	
					}
					else{
						if(i2+1 >= j) sCoef = null;
						else sCoef = token.substring(i2+1, j);
					}
				}
				else{				
					if(i1+1 >= j) sCoef = null;
					else sCoef = token.substring(i1+1, j);
				}
			}
			if (sCoef != null && sCoef.length() > 0 && !sCoef.equalsIgnoreCase("null")){
				((OSnLNodeVariable) nlNode).setCoef(Double.parseDouble(sCoef));
			}
		}
		if (sNodeName.equalsIgnoreCase("qTerm")){
			String sIdxOne = token.substring(i1+1, i2);
			if (sIdxOne != null && sIdxOne.length() > 0 && !sIdxOne.equalsIgnoreCase("null")){
				((OSnLNodeQTerm) nlNode).setVarOneIndex(Integer
						.parseInt(sIdxOne));
			}
			String sIdxTwo = token.substring(i2+1, i3);
			if (sIdxTwo != null && sIdxTwo.length() > 0 && !sIdxTwo.equalsIgnoreCase("null")){
				((OSnLNodeQTerm) nlNode).setVarTwoIndex(Integer
						.parseInt(sIdxTwo));
			}
			String sCoef = token.substring(i3+1, j);
			if (sCoef != null && sCoef.length() > 0 && !sCoef.equalsIgnoreCase("null")){
				((OSnLNodeQTerm) nlNode).setCoef(Double.parseDouble(sCoef));
			}
		}
		if (sNodeName.equalsIgnoreCase("sim")){
			String sName = token.substring(i1+1, j);
			if (sName != null && sName.length() > 0 && !sName.equalsIgnoreCase("null")){
				((OSnLNodeSim) nlNode).setSimName(sName);
			}
		}
		if (sNodeName.equalsIgnoreCase("simInput")){
			String sSimName = token.substring(i1+1, i2);
			if (sSimName != null && sSimName.length() > 0 && !sSimName.equalsIgnoreCase("null")){
				((OSnLNodeSimInput) nlNode).setSimName(sSimName);
			}
			String sInputName = token.substring(i2+1, j);
			if (sInputName != null && sInputName.length() > 0 && !sInputName.equalsIgnoreCase("null")){
				((OSnLNodeSimInput) nlNode).setInputName(sInputName);
			}
		}
		if (sNodeName.equalsIgnoreCase("simOutput")){
			String sSimName = token.substring(i1+1, i2);
			if (sSimName != null && sSimName.length() > 0 && !sSimName.equalsIgnoreCase("null")){
				((OSnLNodeSimOutput) nlNode).setSimName(sSimName);
			} 
			String sOutputName = token.substring(i2+1, j);
			if (sOutputName != null && sOutputName.length() > 0 && !sOutputName.equalsIgnoreCase("null")){
				((OSnLNodeSimOutput) nlNode).setOutputName(sOutputName);
			}
		}
		if (sNodeName.equalsIgnoreCase("userF")){
			String sName = token.substring(i1+1, j);
			if (sName != null && sName.length() > 0 && !sName.equalsIgnoreCase("null")){
				((OSnLNodeUserF) nlNode).setUserFName(sName);
			}
		}
		if (sNodeName.equalsIgnoreCase("arg")){
			String sIdx = token.substring(i1+1, j);
			if (sIdx != null && sIdx.length() > 0 && !sIdx.equalsIgnoreCase("null")){
				((OSnLNodeArg) nlNode).setArgumentIndex(Integer.parseInt(sIdx));
			}
		}
		if (sNodeName.equalsIgnoreCase("xPath")){
			if(j == -1) j = token.length();
			String sToken2 = token.replaceAll("::", "@@");
			i2 = sToken2.lastIndexOf(":");
			String sURI = token.substring(i1+1, i2);
			if (sURI != null && sURI.length() > 0  && !sURI.equals(".") && !sURI.equalsIgnoreCase("null")){
				((OSnLNodeXPath) nlNode).setURI(sURI);
				((OSnLNodeXPath) nlNode).m_xpathUtil = new XPathUtil(sURI, true);
			} 
			else{ 
				((OSnLNodeXPath) nlNode).setURI(".");
			}
			String sPath = token.substring(i2+1, j);
			if (sPath != null && sPath.length() > 0  && !sURI.equals(".") && !sPath.equalsIgnoreCase("null")){
				((OSnLNodeXPath) nlNode).setPath(sPath);
			}
		}
		if (sNodeName.equalsIgnoreCase("xPathIndex")){
			String sIndexName = token.substring(i1+1, i2);
			if (sIndexName != null && sIndexName.length() > 0 && !sIndexName.equalsIgnoreCase("null")){
				((OSnLNodeXPathIndex) nlNode).setIndexName(sIndexName);
			}
			String sIndexValue = token.substring(i2+1, j);
			if (sIndexValue != null && sIndexValue.length() > 0 && !sIndexValue.equalsIgnoreCase("null")){
				((OSnLNodeXPathIndex) nlNode).setIndexValue(sIndexValue);
			}
		}
		if (sNodeName.equalsIgnoreCase("nodeRef")){
			String sNetworkNodeID = token.substring(i1+1, i2);
			if (sNetworkNodeID != null && sNetworkNodeID.length() > 0 && !sNetworkNodeID.equalsIgnoreCase("null")){
				((OSnLNodeNodeRef) nlNode).setNodeID(Integer.parseInt(sNetworkNodeID));
			}
			String sPropName = token.substring(i2+1, j);
			if (sPropName != null && sPropName.length() > 0 && !sPropName.equalsIgnoreCase("null")){
				((OSnLNodeNodeRef) nlNode).setPropName(sPropName);
			}
		}
		if (sNodeName.equalsIgnoreCase("arcRef")){
			String sNetworkArcID = token.substring(i1+1, i2);
			if (sNetworkArcID != null && sNetworkArcID.length() > 0 && !sNetworkArcID.equalsIgnoreCase("null")){
				((OSnLNodeArcRef) nlNode).setArcID(Integer.parseInt(sNetworkArcID));
			}
			String sPropName = token.substring(i2+1, j);
			if (sPropName != null && sPropName.length() > 0 && !sPropName.equalsIgnoreCase("null")){
				((OSnLNodeArcRef) nlNode).setPropName(sPropName);
			}
		}
		return nlNode;
	}//convertStringTokenToNlNode
	
	/**
	 * 
	 * @param eTree
	 *            holds the expression tree to be concatenated (i.e. linked with
	 *            an add operator) to the current expression.
	 */
	public void concatenate(OSExpressionTree eTree){
		OSnLNodePlus newTreeRoot = new OSnLNodePlus(this.m_treeRoot, eTree.m_treeRoot);
		m_treeRoot = newTreeRoot;
	}//concatenate
	
	/**
	 * 
	 * @return the delimiter used in OSnLNode classes and expression trees. 
	 */
	public static String getDelimiter(){
		String sDelimiter = OSnLNode.m_sDelimiter;
		return sDelimiter;
	}//getDelimiter
	
	/**
	 * 
	 * @return the information of all nonlinear nodes in a colon delimited
	 *         string. The string is in a table format with the first row being
	 *         the colmn title.
	 */
	public static String getNlNodeInfo(){
		String sSpace = ": ";
		String sInfo = "NAME" + sSpace + "INDEX" + sSpace + "SYMBOL" + sSpace + "TYPE" + sSpace
		+ "ATTRIBUTES" + sSpace + "DESCRIPTION\n";
		for (int i = 0; i < OSnLNode.msNodeNames.length; i++){
			sInfo += i + sSpace + OSnLNode.msNodeNames[i] + sSpace;
			String sNodeName = OSnLNode.msNodeNames[i];
			String sNlNodeClass = m_sPackageName + "." + m_sNlNodeStartString
			+ sNodeName.substring(0, 1).toUpperCase()
			+ sNodeName.substring(1);
			OSnLNode nlNode = null;
			try{
				Class nlNodeClass = Class.forName(sNlNodeClass);
				nlNode = (OSnLNode) nlNodeClass.newInstance();
				sInfo += nlNode.getSymbolInteger() + sSpace
				+ nlNode.getSymbol() + sSpace + nlNode.getType()
				+ sSpace;
				if (sNodeName.equalsIgnoreCase("number")){
					sInfo += "id, value, type" + sSpace;
				}
				if (sNodeName.equalsIgnoreCase("identifier")){
					sInfo += "name" + sSpace;
				}
				if (sNodeName.equalsIgnoreCase("variable")){
					sInfo += "coef, index" + sSpace;
				}
				if (sNodeName.equalsIgnoreCase("qTerm")){
					sInfo += "idxOne, idxTwo, coef" + sSpace;
				}
				if (sNodeName.equalsIgnoreCase("sim")){
					sInfo += "name" + sSpace;
				}
				if (sNodeName.equalsIgnoreCase("simInput")){
					sInfo += "simName, inputName" + sSpace;
				}
				if (sNodeName.equalsIgnoreCase("simOutput")){
					sInfo += "simName, outputName" + sSpace;
				}
				if (sNodeName.equalsIgnoreCase("userF")){
					sInfo += "name" + sSpace;
				}
				if (sNodeName.equalsIgnoreCase("arg")){
					sInfo += "idx" + sSpace;
				}
				if (sNodeName.equalsIgnoreCase("xPath")){
					sInfo += "uri, path" + sSpace;
				}
				if (sNodeName.equalsIgnoreCase("xPathIndex")){
					sInfo += "indexName, indexValue" + sSpace;
				}
				if (sNodeName.equalsIgnoreCase("nodeRef")){
					sInfo += "nodeID, propName" + sSpace;
				}
				if (sNodeName.equalsIgnoreCase("arcRef")){
					sInfo += "arcID, propName" + sSpace;
				}
				sInfo += nlNode.getDescription() + "\n";
			} catch (ClassNotFoundException e){
				sInfo += " !!!NOT IMPLEMENTED!!!\n";
				//e.printStackTrace();
			} 
			catch (InstantiationException e){
				//e.printStackTrace();
			} 
			catch (IllegalAccessException e){
				//e.printStackTrace();
			} 
			catch (Exception e){
				//e.printStackTrace();
			}
		}
		return sInfo;
	}//getNlNodeInfo
	
	/**
	 * Calculate the function value of the expression tree.
	 * 
	 * </p>
	 * 
	 * @param x holds the values of the variables in a double array.
	 * @return the function value of the expression tree given the current
	 *         variable values.
	 */
	public double calculateFunction(double[] x){
		OSnLNode.m_treeRoot = m_treeRoot;
		OSnLNode.m_mdX = x;
		return m_treeRoot.calculateFunction(x);
	}//calculateFunction
	
	/**
	 * Calculate the expression tree function value given the current variable
	 * values. If the function has been evaluated over the current x values, the
	 * method will retrieve it.
	 * 
	 * </p>
	 * 
	 * @param x
	 *            holds the values of the variables in a double array.
	 * @param functionEvaluated
	 *            holds whether the function has been evaluated.
	 * @return the expression function value given the current variable values.
	 */
	public double calculateFunction(double[] x, boolean functionEvaluated){
		OSnLNode.m_treeRoot = m_treeRoot;
		OSnLNode.m_mdX = x;
		return m_treeRoot.calculateFunction(x, functionEvaluated);
	}//calculateFunction
	
	/**
	 * Calculate the expression tree function value given the current variable
	 * values. If the function has been evaluated over the current x values, the
	 * method will retrieve it.
	 * 
	 * </p>
	 * 
	 * @param x
	 *            holds the values of the variables in a string array.
	 * @param functionEvaluated
	 *            holds whether the function has been evaluated.
	 * @return the expression tree function derivative value given the current
	 *         variable values in a string.
	 */
	public String calculateFunction(String[] x, boolean functionEvaluated){
		OSnLNode.m_treeRoot = m_treeRoot;
		OSnLNode.m_msX = x;
		return m_treeRoot.calculateFunction(x, functionEvaluated);
	}//calculateFunction - string based
	
	/**
	 * Calculate the function derivative value given the current variable values
	 * w.r.t one variable. If the function has been evaluated over the current x
	 * values, the method will retrieve it.
	 * 
	 * </p>
	 * 
	 * @param x
	 *            holds the values of the variables in a double array.
	 * @param index
	 *            holds the variable index on which to take the derivative.
	 * @param functionEvaluated
	 *            holds whether the function has been evaluated.
	 * @return the expression tree function derivative given the current
	 *         variable values w.r.t the specified variable.
	 */
	public double calculateDerivative(double[] x, int index, boolean functionEvaluated){
		OSnLNode.m_treeRoot = m_treeRoot;
		OSnLNode.m_mdX = x;
		double dDerivative = m_treeRoot.calculateDerivative(x, index, functionEvaluated);
		if(dDerivative != 0) m_treeRoot.m_mapDerivativeValues.put(index,  dDerivative);
		return dDerivative;
	}//calculateDerivative
	
	/**
	 * Get the expression tree function derivative value given the current
	 * variable values values w.r.t one variable. This method assumes that the
	 * derivative has already been calculated over the current variable values.
	 * 
	 * </p>
	 * 
	 * @param index holds the variable index on which to get the derivative.
	 * @return the expression tree function derivative value of the current 
	 * variable values assuming that the derivative has already been
	 * calculated over the current variable values w.r.t the specified variable.
	 */
	public double getDerivative(int index){
		return m_treeRoot.m_mapDerivativeValues.get(index);
	}//getDerivative
	
	/**
	 * Calculate the function partial derivatives given the current variable
	 * values w.r.t all variables. If the function has been evaluated over the
	 * current x values, the method will retrieve it.
	 * 
	 * </p>
	 * 
	 * @param x
	 *            holds the values of the variables in a double array.
	 * @param functionEvaluated
	 *            holds whether the function has been evaluated.
	 * @return a hashmap of the nonzero function derivative values given the
	 *         current variable values. The map keys are variable indexes, and
	 *         the map values are nonzero derivatives.
	 */
	public Int2DoubleOpenHashMap calculateDerivatives(double[] x, boolean functionEvaluated){
		OSnLNode.m_treeRoot = m_treeRoot;
		OSnLNode.m_mdX = x;
		if (!functionEvaluated){
			calculateFunction(x);
		}
		m_treeRoot.m_mapDerivativeValues.clear();
		m_treeRoot.propogateDerivatives(m_treeRoot, x);
		return m_treeRoot.m_mapDerivativeValues;
	}//calculateDerivatives
	
	/**
	 * Get the expression tree function derivatives given the current variable
	 * values w.r.t all variables. This method assumes that the derivatives have
	 * already been calculated over the current variable values.
	 * 
	 * </p>
	 * 
	 * @return a hashmap of the nonzero function derivative values given the
	 *         current variable values. The map keys are variable indexes, and
	 *         the map values are nonzero derivatives. This method assumes that
	 *         the derivative values have already been calculated over the
	 *         current variable values w.r.t all variables.
	 */
	public Int2DoubleOpenHashMap getDerivatives(){
		return m_treeRoot.m_mapDerivativeValues;
	}//getDerivatives
	
	/**
	 * Calculate the function Hessian given the current variable values w.r.t
	 * all variables.
	 * 
	 * </p>
	 * 
	 * @param x
	 *            holds the values of the variables in a double array.
	 * @param derivativeEvaluated
	 *            holds whether the function derivatives have been evaluated.
	 * @return a sparse hash map of the upper triangular (i<=j) non-zero second partial
	 *         derivatives w.r.t to variable i and then j, given the current
	 *         variable values. The map keys are the strings of variable indexes
	 *         delimited by a comma, i.e. "i,j" and the map values are the
	 *         Hessian values.
	 */
	public Object2DoubleOpenHashMap calculateHessian(double[] x, boolean derivativeEvaluated){
		OSnLNode.m_treeRoot = m_treeRoot;
		OSnLNode.m_mdX = x;
		int i, j;
		Int2DoubleOpenHashMap currentDerivatives;
		if (derivativeEvaluated)
			currentDerivatives = (Int2DoubleOpenHashMap)(m_treeRoot.m_mapDerivativeValues.clone());
		else
			currentDerivatives = (Int2DoubleOpenHashMap)(calculateDerivatives(x, derivativeEvaluated).clone());
		double[] mdXPlusDelta = new double[x.length];
		for (i = 0; i < x.length; i++)
			mdXPlusDelta[i] = x[i];
		IntOpenHashSet indexSet = m_treeRoot.getVariableIndices();
		int n = indexSet.size();
		int[] miIndex = indexSet.toIntArray();
		double dCurrentDerivative = 0;
		double dCurrentPlusDetalDerivative = 0;
		double dHessianValue;
		for (i = 0; i < n; i++){
			mdXPlusDelta[miIndex[i]] += OSnLNode.m_dDelta;
			Int2DoubleOpenHashMap currentPlusDeltaDerivatives = calculateDerivatives(
					mdXPlusDelta, false);
			for (j = i; j < n; j++){
				dCurrentDerivative = currentDerivatives.get(miIndex[j]);
				dCurrentPlusDetalDerivative = currentPlusDeltaDerivatives.get(miIndex[j]);
				dHessianValue = (dCurrentPlusDetalDerivative - dCurrentDerivative) / OSnLNode.m_dDelta;
				if (dHessianValue != 0){
					if (miIndex[i] <= miIndex[j])
						m_treeRoot.m_mapHessianValues.put(miIndex[i] + ","
								+ miIndex[j], dHessianValue);
					else
						m_treeRoot.m_mapHessianValues.put(miIndex[j] + ","
								+ miIndex[i], dHessianValue);
				}
			}
			mdXPlusDelta[miIndex[i]] -= OSnLNode.m_dDelta;
		}
		m_treeRoot.m_mapDerivativeValues = currentDerivatives;
		return m_treeRoot.m_mapHessianValues;
	}//calculateHessian
	
	
	/** Calculate the function Hessian given the current variable values
	 * w.r.t all variables.
	 * 
	 * </p>
	 * 
	 * @return a sparse hash map of the upper triangular non-zero second partial
	 *         derivatives w.r.t to variable i and then j, given the current
	 *         variable values. The map keys are the strings of variable indexes
	 *         delimited by a comma, i.e. "i,j" and the map values are the
	 *         Hessian values.
	 */
	public Object2DoubleOpenHashMap getHessian(){
		return m_treeRoot.m_mapHessianValues;
	}//getHessian
	
	/**
	 * 
	 * @return the expression tree in a postfix vector of operator symbols.
	 */
	public Vector<String> getPostfix(){
		return m_treeRoot.getPostfix();
	}//getPostfix
	
	/**
	 * 
	 * @return the expression tree in a prefix vector of operator symbols.
	 */
	public Vector<String> getPrefix(){
		return m_treeRoot.getPrefix();
	}//getPrefix
	
	/**
	 * 
	 * @return the expression tree in a infix vector of operator symbols.
	 */
	public Vector<String> getInfix(){
		return m_treeRoot.getInfix();
	}//getInfix

	/**
	 * 
	 * @param document holds the W3C DOM type document to create XML elements and attributes.
	 * It is the parent of the root element, e.g. the &lt;OSiL&gt; element in OSiL. It is used
	 * to create all the nodes in the DOM tree.
	 * @return the nonlinear expression starting with the root node in an XML DOM Tree.
	 */
	public Element getDomTreeRoot(Document document){
		return m_treeRoot.getDOMTree(document);
	}//getDomTreeRoot

	/**
	 * 
	 * @param document holds the W3C DOM type document to create XML elements and attributes.
	 * It is the parent of the root element, e.g. the &lt;OSiL&gt; element in OSiL. It is used
	 * to create all the nodes in the DOM tree.
	 * @return the nonlinear expression string representation starting with the root node in an XML DOM Tree.
	 */
	public String getDomTreeString(Document document){
		m_treeRoot.getDOMTree(document);
		return XMLUtil.writeXMLDocumentToString(document);
	}//getDomTreeString

	/**
	 * relabel variable indices, e.g. X0 -> X2; X1 -> X0; X2 -> X1. 
	 * 
	 * @param newVariableIndices holds the new varialbe indices. For the example above it would be [2, 0, 1]. 
	 * @return whether the relabeling is successful or not. 
	 */
	public boolean reLabelVariableIndices(int[] newVariableIndices){
		return m_treeRoot.reLabelVariableIndices(newVariableIndices);
	}//reLabelVariableIndices
	
	/**
	 * Simplify the current expression tree. Also simplify the variables by converting number*variable into
	 * just a variable with the number as a coefficient of the varialbe. 
	 * 
	 * @return the reduction size, i.e. the number of nodes taken out of the original expression tree. 
	 * If 0, the nonlinear function is already the simplest. 
	 */
	public int simplify(){//TODO it may be complete
		int iOldSize = m_treeRoot.getSize();
		if(m_treeRoot.simplify()){
			double dValue = m_treeRoot.calculateFunction(null);
			OSnLNodeNumber osnlNodeNumber = new OSnLNodeNumber(null, dValue + "", "real");
			m_treeRoot = osnlNodeNumber;
		}
		simplifyVariables();
		int iNewSize = m_treeRoot.getSize();
		return iOldSize - iNewSize;
	}//simplify
	
	/**
	 * <p>Simplify the variables of the current node's children. The method converts number*variable into
	 * just a variable with the number as a coefficient of the varialbe. 
	 */
	protected void simplifyVariables(){
		m_treeRoot.simplifyVariables();				
		if(m_treeRoot.getSymbolInteger() == 1005){
			int i, j;
			i = m_treeRoot.m_mChildren[0].getSymbolInteger();
			j = m_treeRoot.m_mChildren[1].getSymbolInteger();
			if((i >= 5001 && i < 6000 && i != 5002) && j == 6001){
				if(m_treeRoot.m_mChildren[0].getSymbolInteger() == 5001 && 
						!((OSnLNodeNumber)m_treeRoot.m_mChildren[0]).getNumberType().equals("real"));
				else{
					OSnLNodeVariable varNode = (OSnLNodeVariable)m_treeRoot.m_mChildren[1];
					double dCoef = varNode.getCoef();
					dCoef *= m_treeRoot.m_mChildren[0].calculateFunction(null);
					varNode.setCoef(dCoef);
					m_treeRoot = varNode;
				}
			}
			else if(i == 6001 && (j >= 5001 && j < 6000 && j != 5002)){
				if(m_treeRoot.m_mChildren[1].getSymbolInteger() == 5001 && 
						!((OSnLNodeNumber)m_treeRoot.m_mChildren[1]).getNumberType().equals("real"));
				else{
					OSnLNodeVariable varNode = (OSnLNodeVariable)m_treeRoot.m_mChildren[0];
					double dCoef = varNode.getCoef();
					dCoef *= m_treeRoot.m_mChildren[1].calculateFunction(null);
					varNode.setCoef(dCoef);
					m_treeRoot = varNode;
				}
			}
		}
		else if(m_treeRoot.getSymbolInteger() == 1004){
			int i;
			i = m_treeRoot.m_mChildren[0].getSymbolInteger();
			if(i == 6001){
				OSnLNodeVariable varNode = (OSnLNodeVariable)m_treeRoot.m_mChildren[0];
				double dCoef = varNode.getCoef()*(-1);
				varNode.setCoef(dCoef);
				m_treeRoot = varNode;
			}
		}
		else if(m_treeRoot.getSymbolInteger() == 1006){
			int i, j;
			i = m_treeRoot.m_mChildren[0].getSymbolInteger();
			j = m_treeRoot.m_mChildren[1].getSymbolInteger();
			if(i == 6001 && (j >= 5001 && j < 6000 && j != 5002)){
				if(m_treeRoot.m_mChildren[1].getSymbolInteger() == 5001 && 
						!((OSnLNodeNumber)m_treeRoot.m_mChildren[1]).getNumberType().equals("real"));
				else{
					OSnLNodeVariable varNode = (OSnLNodeVariable)m_treeRoot.m_mChildren[0];
					double dCoef = varNode.getCoef();
					dCoef /= m_treeRoot.m_mChildren[1].calculateFunction(null);
					varNode.setCoef(dCoef);
					m_treeRoot = varNode;
				}
			}
		}
	}//simplifyVariables

	
	/**
	 * <p>Linearize the current node so that it doesn't contain linear terms. 
	 * The expression tree of the node will become smaller if there are linear terms. 
	 * If the node is fully linear, the node becomes null. If the node is not linear 
	 * at all, it will remain the same and the returned hash map has a size zero.  
	 * </p>
	 * 
	 * @return a hashmap of linear terms extracted out from this expression tree, 
	 * with keys being the variable indices and values being the variable coefficients. 
	 */
	public Int2DoubleOpenHashMap linearize(){//TODO 
		return m_treeRoot.linearize();
	}//linearize
	
	/**
	 * <p>Quadratize the current expression tree, or make all the quadratic terms written in the 
	 * form of a quadratic node with its children being the quadratic terms.   
	 * </p>
	 * 
	 * @return whether there is conversion of some quadratic terms.
	 */
	public boolean quadratize(){//TODO 
		return m_treeRoot.quadratize();
	}//quadratize
	
	/**
	 * 
	 * @return an integer set of indices of the variables that exist in the current
	 *         nonlinear expression tree.
	 */
	public IntOpenHashSet getVariableIndices(){
		return m_treeRoot.getVariableIndices();
	}//getVariableIndices
	
	/**
	 * 
	 * @return the tree size, i.e. the number of nodes, of the expression tree. 
	 */
	public int getSize(){
		return m_treeRoot.getSize();
	}//getSize
	
	/**
	 * 
	 * @return the number of trigonometric functions in the expression tree. 
	 */
	public int getNumberOfTrigonometricFunctions(){
		return m_treeRoot.getNumberOfTrigonometricFunctions();
	}//getNumberOfTrigonometricFunctions
	
	/**
	 * 
	 * @return the number of statistic functions in the expression tree. 
	 */
	public int getNumberOfStatisticFunctions(){
		return m_treeRoot.getNumberOfStatisticFunctions();
	}//getNumberOfStatisticFunctions
	
	/**
	 * 
	 * @return the number of probability functions in the expression tree. 
	 */
	public int getNumberOfProbabilityFunctions(){
		return m_treeRoot.getNumberOfProbabilityFunctions();
	}//getNumberOfProbabilityFunctions
	
	/**
	 * 
	 * @return a set of number values that exist in the expression tree. 
	 */
	public  HashSet getNumberValues(){
		return m_treeRoot.getNumberValues();
	}//getNumberValues
	
	/**
	 * 
	 * @return a set of names of identifiers that exist in the expression tree. 
	 */
	public  HashSet getIdentifiers(){
		return m_treeRoot.getIdentifiers();
	}//getIdentifiers
	
	/**
	 * 
	 * @return a set of logic and relational operator symbols that exist in the expression tree. 
	 */
	public  HashSet getLogicAndRelationalSymbols(){
		return m_treeRoot.getLogicAndRelationalSymbols();
	}//getLogicAndRelationalSymbols
	
	/**
	 * 
	 * @return a set of quadratic terms that exist in the expression tree.
	 */
	public  HashSet getQuadraticTerms(){
		return m_treeRoot.getQuadraticTerms();
	}//getQuadraticTerms
	
	/**
	 * 
	 * @return a set of names of the simulations that exist in the expression tree. 
	 */
	public  HashSet getSimulationNames(){
		return m_treeRoot.getSimulationNames();
	}//getSimulationNames
	
	/**
	 * 
	 * @return a set of names of the user defined functions that exist in the expression tree. 
	 */
	public  HashSet getUserFunctionNames(){
		return m_treeRoot.getUserFunctionNames();
	}//getUserFunctionNames
	
	/**
	 * 
	 * @return a set of XPaths that exist in the expression tree, each set member is of the form:
	 * uri:path, that is uri and path delimited by :. 
	 */
	public  HashSet getXPath(){
		return m_treeRoot.getXPath();
	}//getXPath
	
	/**
	 * 
	 * @return a set of network nodes that are referred in the expression tree, each set member is of the form:
	 * nodeName:propertyName, that is nodeName and property name delimited :. 
	 */
	public  HashSet getNetworkNodes(){
		return m_treeRoot.getNetworkNodes();
	}//getNetworkNodes
	
	/**
	 * 
	 * @return a set of network arcs that are referred in the expression tree, each set member is of the form:
	 * arcName:propertyName, that is arcName and property name delimited :. 
	 */
	public  HashSet getNetworkArcs(){
		return m_treeRoot.getNetworkArcs();
	}//getNetworkArcs
	
	/**
	 * 
	 * @return the number of the complements operator in the expression tree. 
	 */
	public int getNumberOfComplementsOperator(){
		return m_treeRoot.getNumberOfComplementsOperator();
	}//getNumberOfComplementsOperator
	
	/**
	 * 
	 * @return the number of the probability operator (usually in a chance constraint) in the expression tree. 
	 */
	public int getNumberOfProbOperator(){
		return m_treeRoot.getNumberOfProbOperator();
	}//getNumberOfProbOperator
	
	/**
	 * main for test purposes.
	 *
	 * </p>
	 *
	 * @param argv command line arguments.
	 */
	public static void main(String[] argv){
		System.out.println(OSExpressionTree.getNlNodeInfo());
		String s = "1,2,3, power, plus";
		s = "X3:1,plus,number:4::";
		s="X1, plus, 2, divide, sin, (, PI, )";
		s="sum[4], (, X1, 3, times, X1, sin, (, sum[1], (, PI, ), ), PI, )";
		s = "negate, (, 2, times 3, times, X1:5, divide, 2, )";
		s = "sum[2], (, 10, times, variable:0:1[0],  9, times, variable:1:1[0], )";
		s = "sum[9], (, variable:0:19[0], times, variable:0:1[0], variable:0:25[0], times, variable:1:1[0], variable:0:37[0], times, variable:2:1[0], variable:1:25[0], times, variable:0:1[0], variable:1:24[0], times, variable:1:1[0], variable:1:10[0], times, variable:2:1[0], variable:2:37[0], times, variable:0:1[0], variable:2:10[0], times, variable:1:1[0], variable:2:75[0], times, variable:2:1[0], )";
		s = "sum[3], (, variable:1:24[0], times, variable:1:1[0],  variable:1:10[0], times, variable:2:1[0], variable:2:37[0], times, variable:0:1[0], )";
		s = "sum[3], (, variable:1:24[0], times, variable:1:1[0],  negate, variable:1:10[0], times, variable:2:1[0], variable:2:37[0], times, variable:0:1[0], )";
		s = "sum[3], (, 2, *, 3,  (-), 4, times, 5, 6, times, 7, )";
		s = "100,times,(,X1,minus,X0,power,2,),power,2,plus,(,1,minus,X0,),power,2,plus,7,times,X1";
		s = "100,times,(,X1,minus,X0,power,2,),power,2,plus,(,1,minus,X0,),power,2,plus,X1:7";
		s = "number:100:real:null,times,(,variable:1:1[0],minus,X0:1,power,number:2:real:null,),power,number:2:real:null,plus,(,number:1:real:null,minus,variable:0:1[0],),power,number:2:real:null,plus,variable:1:7[0]";
		s = "3,plus,2,times,4,power,2,power,3";
		//s = "sum[2], (, 0.7, times, X0, sum[2], (, 0.7, times, X0, X1, ), ), plus, (, arcRef:arc4:use[0], plus, sim:sim1[3], (, simInput:sim1:x0[1], (, X0, ), simInput:sim1:x1[1], (, X1, ), simOutput:sim1:result[0], ), plus, userF:myparam[3], (, 2, X[1], (, xPath:lotsizelookup.xml:\"xmlData/lotsizeVar/product[position()=$prodIndex]/period[position()=$timeIndex]/@idxVal\"[2], (, xPathIndex:prodIndex:2[0], xPathIndex:timeIndex:4[0], ), ), 4, ), )";
		Vector v = CommonUtil.stringToVector(s, ", ");
		System.out.println(v);
		OSExpressionTree etree = new OSExpressionTree(v, "infix", 0, v.size()-1);
		//System.out.println(etree.getPostfix());
		System.out.println(etree.getInfix());
		System.out.println(etree.getPostfix());
		//System.out.println(etree.getSize());
		//etree.simplify();
		//etree.simplifyVariables();
		//System.out.println(etree.getSize());
		//System.out.println(etree.getInfix());	
	}//main
	
}//class OSExpressionTree
