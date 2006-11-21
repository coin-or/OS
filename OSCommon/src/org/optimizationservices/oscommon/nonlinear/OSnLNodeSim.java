/**
 * @(#)OSnLNodeSim 1.0 03/14/2004
 *
 * Copyright (c) 2004
 */
package org.optimizationservices.oscommon.nonlinear;

import org.optimizationservices.oscommon.communicationagent.OSSimulationAgent;
import org.optimizationservices.oscommon.representationparser.OSsLReader;
import org.optimizationservices.oscommon.util.XMLUtil;
import org.w3c.dom.Document;
import org.w3c.dom.Element;

/**
 *
 * <P>The <code>OSnLNodeSim</code> class represents a simulaion node in an expression tree. A simulation
 * takes an array of input (in OSsL format) and returns an output. The function form of the simlation is hidden,
 * i.e. a black box evaluation. The <code>OSnLNodeSim</code> extends the abstract OSnLNode class and implements its abstract methods such as
 * calculateFunction(double[]).
 * </p>
 *
 * </p>
 *
 * @author Robert Fourer, Jun Ma, Kipp Martin
 * @version 1.0, 03/14/2004
 * @see org.optimizationservices.oscommon.nonlinear.OSExpressionTree;
 * @see org.optimizationservices.oscommon.nonlinear.OSnLNode;
 * @see org.optimizationservices.ossimulation.*;
 * @since OS 1.0
 */
public class OSnLNodeSim extends OSnLNode{

	/**
	 * m_sSymbol holds the symbol that this nlNode looks in ASCII.
	 */
	protected String m_sSymbol = "sim";

	/**
	 * m_sSymbol holds the description of this nlNode
	 */
	protected String m_sDescription = "A simulation that takes an array of input (in OSsL format) and returns an output. The function form of the simlation is hidden, i.e. a black box evaluation. ";

	/**
	 * m_iSymbol holds the four digit integer that represents this nlNode, with the leftmost (first)
	 * integer representing the category and the right three digits representing a unique sequence number
	 * in the node category.
	 */
	protected int m_iSymbol = 9003;

	/**
	 * m_iType holds the integer representation of the type of this nlNode.
	 */
	protected int m_iType = -1;

	/**
	 * m_sSimName holds the name of the simulation.
	 */
	protected String m_sSimName = "";

	/**
	 * m_sURI holds the URI or the location of the simulation.
	 */
	protected String m_sURI = "";

	/**
	 * m_osslReader holds an OSsL reader object, from which we can get all the information of the OSsL instance
	 * wrapped inside this reader object.
	 */
	protected OSsLReader m_osslReader = null;

	/**
	 * constructor
	 *
	 * </p>
	 *
	 * @param nodes holds the array of node operands to simulation as input values.
	 * The last NlNode of the array is always for simulation output (simOutput).
	 * @param simName holds the name of the simulation.
	 * @param outputName holds the name of the simulation output.
	 */
	protected OSnLNodeSim(OSnLNode[] nodes, String simName, String outputName){
		m_mChildren = nodes;
		m_sSimName = simName;
		m_sSymbol = "sim:" + m_sSimName;
	}//constructor


	/**
	 * default constructor
	 */
	protected OSnLNodeSim(){
	}//constructor

	/**
	 * Calculate the result value of an simulation given the current variable values.
	 *
	 * </p>
	 *
	 * @param x holds the values of the variables in a double array.
	 * @return the result value of the simulation given the current variable values.
	 */
	protected double calculateFunction(double[] x){
		for(int i = 0; i < m_mChildren.length - 1; i++){
			OSnLNodeSimInput simInput = (OSnLNodeSimInput)(m_mChildren[i]);
			String sInputName = simInput.getInputName();
			double dValue = simInput.calculateFunction(x);
			String sValue = null;
			if(Double.isNaN(dValue) && simInput.m_sFunctionValue != null){
				sValue = simInput.m_sFunctionValue;
			}
			else{
				sValue = dValue + "";
			}
			m_osslReader.replaceInputElementValue(sInputName, sValue);
		}
		String sOSsLInput = XMLUtil.writeXMLElementToString(m_osslReader.getRootElement());
		String sReplace = "ossl xmlns=\"os.optimizationservices.org\" xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\" xsi:schemaLocation=\"os.optimizationservices.org http://www.optimizationservices.org/schemas/OSsL.xsd\"";
		sOSsLInput = sOSsLInput.replaceFirst("ossl", sReplace);
		OSSimulationAgent osSimulationAgent = new OSSimulationAgent();
		osSimulationAgent.simulationAddress = m_sURI;
		String sOSsLOutput = osSimulationAgent.call(sOSsLInput, null);
		try{
			OSnLNodeSimOutput simOutput = (OSnLNodeSimOutput)(m_mChildren[m_mChildren.length - 1]);
			OSsLReader osslReader = new OSsLReader();
			osslReader.readString(sOSsLOutput);
			if(m_osslReader.getInputOrOutput(true) != null){
				osslReader.setInputOrOutput(true, m_osslReader.getInputOrOutput(true));
			}
			simOutput.setOSsLReader(osslReader);
			m_dFunctionValue = simOutput.calculateFunction(x);
			if(Double.isNaN(m_dFunctionValue) && simOutput.m_sFunctionValue != null){
				m_sFunctionValue = simOutput.m_sFunctionValue;
				try{
					m_dFunctionValue = Double.parseDouble(m_sFunctionValue);
					m_sFunctionValue = null;
				}
				catch(Exception e){
					m_dFunctionValue = Double.NaN;
				}
			}
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
		for(int i = 0; i < m_mChildren.length - 1; i++){
			OSnLNodeSimInput simInput = (OSnLNodeSimInput)(m_mChildren[i]);
			String sInputName = simInput.getInputName();
			String sValue = simInput.calculateFunction(x, functionEvaluated);
			m_osslReader.replaceInputElementValue(sInputName, sValue);
		}
		String sOSsLInput = XMLUtil.writeXMLElementToString(m_osslReader.getRootElement());
		String sReplace = "ossl xmlns=\"os.optimizationservices.org\" xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\" xsi:schemaLocation=\"os.optimizationservices.org http://www.optimizationservices.org/schemas/OSsL.xsd\"";
		sOSsLInput = sOSsLInput.replaceFirst("ossl", sReplace);
		OSSimulationAgent osSimulationAgent = new OSSimulationAgent();
		osSimulationAgent.simulationAddress = m_sURI;
		String sOSsLOutput = osSimulationAgent.call(sOSsLInput, null);
		try{
			OSnLNodeSimOutput simOutput = (OSnLNodeSimOutput)(m_mChildren[m_mChildren.length - 1]);
			OSsLReader osslReader = new OSsLReader();
			osslReader.readString(sOSsLOutput);
			if(m_osslReader.getInputOrOutput(true) != null){
				osslReader.setInputOrOutput(true, m_osslReader.getInputOrOutput(true));
			}
			simOutput.setOSsLReader(osslReader);
			m_sFunctionValue = simOutput.calculateFunction(x, functionEvaluated);
		}
		catch(Exception e){
			e.printStackTrace();
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
		int i;
		int iInput = m_mChildren.length - 1;
		m_mChildren[iInput].m_dNodeDerivative = m_dNodeDerivative;
		double[] mdArgumentValues = null;
		if(iInput > 0) mdArgumentValues = new double[iInput];
		for(i = 0; i < iInput; i++) mdArgumentValues[i] = m_mChildren[i].calculateFunction(x, true);
		for(i = 0; i < iInput; i++){
			double dCurrentValue = calculateFunction(mdArgumentValues, true);
			mdArgumentValues[i] +=  m_dDelta;
			double dCurrentPlusDeltaValue = calculateFunction(mdArgumentValues, false);
			mdArgumentValues[i] -= m_dDelta;
			m_dFunctionValue = dCurrentValue;
			double dDerivative = (dCurrentPlusDeltaValue - dCurrentValue)/m_dDelta;
			m_mChildren[i].m_dNodeDerivative = m_dNodeDerivative * dDerivative;
			m_mChildren[i].propogateDerivatives(rootNode, x);
		}
	}//propogateDerivatives

	/**
	 *
	 * @param document holds the W3C DOM type document to create XML elements and attributes.
	 * It is the parent of the root element, e.g. the &lt;OSiL&gt; element in OSiL. It is used
	 * to create all the nodes in the DOM tree.
	 * @return the nonlinear expression starting with the current node in an XML DOM Tree.
	 */
	protected Element getDOMTree(Document document){
		Element eRoot = document.createElement("sim");
		String sAttrValue = getSimName();
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
	 * @return the name of the simulation.
	 */
	protected String getSimName(){
		return m_sSimName;
	}//getSimName

	/**
	 * Set the name of the simulation.
	 *
	 * </p>
	 *
	 * @param simName holds the name of the simulation.
	 */
	protected void setSimName(String simName){
		m_sSimName = simName;
		m_sSymbol = "sim:" + m_sSimName;
	}//setSimName

	/**
	 *
	 * @return the URI of the simulation.
	 */
	protected String getURI(){
		return m_sURI;
	}//getURI

	/**
	 * Set the URI of the simulation.
	 *
	 * </p>
	 *
	 * @param uri holds the uri of the simulation.
	 */
	protected void setURI(String uri){
		m_sURI = uri;
	}//setURI

	/**
	 *
	 * @return the OSsLReader of the simulation.
	 */
	protected OSsLReader getOSsLReader(){
		return m_osslReader;
	}//getOSsLReader

	/**
	 * Set the OSsLReader of the simulation.
	 *
	 * </p>
	 *
	 * @param osslReader holds an OSsL reader object, from which we can get all the information of the OSsL instance
	 * wrapped inside this reader object.
	 */
	protected void setOSsLReader(OSsLReader osslReader){
		m_osslReader = osslReader;
	}//setOSsLReader

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

}//class NlNodeSimulation
