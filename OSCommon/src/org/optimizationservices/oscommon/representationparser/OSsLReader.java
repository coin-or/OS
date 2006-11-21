/**
 * @(#)OSsLReader 1.0 03/14/2004
 *
 * Copyright (c) 2004
 */
package org.optimizationservices.oscommon.representationparser;

import java.util.Collection;
import java.util.HashMap;
import java.util.Set;

import org.optimizationservices.oscommon.datastructure.ossimulation.SimulationElement;
import org.optimizationservices.oscommon.localinterface.OSSimulation;
import org.optimizationservices.oscommon.util.IOUtil;
import org.optimizationservices.oscommon.util.OSParameter;
import org.optimizationservices.oscommon.util.XMLUtil;
import org.w3c.dom.Document;
import org.w3c.dom.Element;
import org.w3c.dom.NamedNodeMap;
import org.w3c.dom.Node;
import org.w3c.dom.NodeList;
 
/**
 * The <c>OSsLReader</c> class parses an OSsL instance into a DOM tree and
 * provides a set of "get" methods that can be used to retrieve different 
 * pieces of information of the instance.
 * </p>
 *
 * @author Robert Fourer, Jun Ma, Kipp Martin
 * @version 1.0, 03/14/2004
 * @since OS 1.0
 */
public class OSsLReader extends OSgLReader{	 
	/**
	 * m_osSimulation holds the standard OSSimulation, which is a local interface for 
	 * storing Optimization Services simulation input/output. 
	 */
	protected OSSimulation m_osSimulation = null;
	
	/**
	 * m_inputHashMap holds a hash map of the input of name-value pairs for the simulation. 
	 */
	protected HashMap<String, String> m_inputHashMap = null;
	
	/**
	 * m_outputHashMap holds a hash map of the output of name-value pairs for the simulation. 
	 */
	protected HashMap<String, String> m_outputHashMap = null;
	
	/**
	 * constructor.
	 *
	 * </p>
	 *
	 * @param validate holds whether the reader should be validating against the schema or not.
	 */
	public OSsLReader(boolean validate){
		m_bXsdValidate = validate;
	}//constructor	
	
	/**
	 * Constructor.
	 */
	public OSsLReader(){
		
	}//constructor
	
	/**
	 * get the standard OSSimulation, a local interface for 
	 * storing Optimization Services simulation.
	 * 
	 * @return the OSSimulation. 
	 * @throws Exception if there are errors getting the OSSimulation. 
	 */
   	public OSSimulation getOSSimulation() throws Exception{
		if(m_osSimulation != null){
			return m_osSimulation;
		}
		m_osSimulation = new OSSimulation();
		if(!m_osSimulation.setSimulationInputElements(getSimulationInputElements())) throw new Exception("setSimulationInputElements Unsuccessful");
		if(!m_osSimulation.setSimulationOutputElements(getSimulationOutputElements())) throw new Exception("setSimulationOutputElements Unsuccessful");
		return m_osSimulation;
   	}//getOSSimulation
   	
	/**
	 * get simulation input elements.
	 * 
	 * @return an array of simulation input elements, null if none. Each member of array 
	 * is a simulation element. 
	 * @see org.optimizationservices.oscommon.datastructure.ossimulation.SimulationElement
	 */
	public SimulationElement[] getSimulationInputElements(){
		Element eInput = (Element)XMLUtil.findChildNode(m_eRoot, "input");
		if(eInput == null) return null;
		NodeList nls = eInput.getElementsByTagName("el");
		int iNls = nls.getLength();
		if (iNls <= 0) return null;
		SimulationElement[] mElements = new SimulationElement[iNls];		
		for(int i = 0; i < iNls; i++){
			mElements[i] = new SimulationElement();		
			Element eEl = (Element)(nls.item(i));
			NamedNodeMap attributes =  eEl.getAttributes();
			int n =attributes.getLength();
			String sName = "";
			String sType = "string";
			String sValue = XMLUtil.getElementValue(eEl);
			for (int j = 0; j < n; j++){
				Node attr = attributes.item(j);
				String sAttributeName  = attr.getNodeName();
				String sAttributeValue = attr.getNodeValue();
				if (sAttributeName.equals("name")){
					sName = sAttributeValue;
				}
				else if (sAttributeName.equals("type")){
					sType = sAttributeValue;
				}
			}
			mElements[i].name = sName;
			mElements[i].type = sType;
			mElements[i].value = sValue;
		}
		return mElements;
	}//getSimulationInput
	
	/**
	 * get simulation output elements.
	 * 
	 * @return an array of simulation output elements, null if none. Each member of array 
	 * is a simulation element. 
	 * @see org.optimizationservices.oscommon.datastructure.ossimulation.SimulationElement
	 */
	public SimulationElement[] getSimulationOutputElements(){
		Element eOutput = (Element)XMLUtil.findChildNode(m_eRoot, "output");
		if(eOutput == null) return null;
		NodeList nls = eOutput.getElementsByTagName("el");
		int iNls = nls.getLength();
		if (iNls <= 0) return null;
		SimulationElement[] mElements = new SimulationElement[iNls];		
		for(int i = 0; i < iNls; i++){
			mElements[i] = new SimulationElement();		
			Element eEl = (Element)(nls.item(i));
			NamedNodeMap attributes =  eEl.getAttributes();
			int n =attributes.getLength();
			String sName = "";
			String sType = "string";
			String sValue = XMLUtil.getElementValue(eEl);
			for (int j = 0; j < n; j++){
				Node attr = attributes.item(j);
				String sAttributeName  = attr.getNodeName();
				String sAttributeValue = attr.getNodeValue();
				if (sAttributeName.equals("name")){
					sName = sAttributeValue;
				}
				else if (sAttributeName.equals("type")){
					sType = sAttributeValue;
				}
			}
			mElements[i].name = sName;
			mElements[i].type = sType;
			mElements[i].value = sValue;
		}
		return mElements;
	}//getSimulationOutput
	
	/**
	 * Get the hash map of the input or output of name-value pairs for the simulation. 
	 * If the value is from a link, it is encoded (base64) into a string and then stored.  
	 * So to retrieve it, the value has to decoded first. 
	 *
	 * </p>
	 *
	 * @param input holds whether to get input or output of OSsL. If true, will get the input.
	 * @return the hash map of the input or output of name-value pairs for the simulation.
	 */
	public HashMap<String, String> getInputOrOutput(boolean input){
		Element eleInputOrOutput = null;
		if(input){
			if(m_inputHashMap != null) return m_inputHashMap;
			eleInputOrOutput = (Element)XMLUtil.findChildNode(m_eRoot, "input");
			m_inputHashMap = new HashMap<String, String>();
		}
		else{
			if(m_outputHashMap != null) return m_outputHashMap;
			eleInputOrOutput = (Element)XMLUtil.findChildNode(m_eRoot, "output");
			m_outputHashMap = new HashMap<String, String>();
		}
		NodeList nls = eleInputOrOutput.getElementsByTagName("el");
		int iNls = nls.getLength();
		for(int i = 0; i < iNls; i++){
			Element eEl = (Element)(nls.item(i));
			NamedNodeMap attributes =  eEl.getAttributes();
			int n =attributes.getLength();
			String sName = "";
			String sValue = "";
			String sType = "string";
			for (int j = 0; j < n; j++){
				Node attr = attributes.item(j);
				String sAttributeName  = attr.getNodeName();
				String sAttributeValue = attr.getNodeValue();
				if (sAttributeName.equals("name")){
					sName = sAttributeValue;
				}
				else if (sAttributeName.equals("type")){
					sType = sAttributeValue;
				}
			}
			if(sType.equals("string")){
				sValue = XMLUtil.getElementValue(eEl);
			}
			else if(sType.equals("link")){
				sValue = IOUtil.bytesToEncodedString(IOUtil.readBytesFromURL(XMLUtil.getElementValue(eEl)));
			}
			if(input) m_inputHashMap.put(sName, sValue);
			else m_outputHashMap.put(sName, sValue);
		}
		if(input) return m_inputHashMap;
		else return m_outputHashMap;
	}//getInputOrOutput
	
	/**
	 * Set the hash map of the input or output of name-value pairs for the simulation. 
	 *
	 * </p>
	 *
	 * @param input holds whether to set input or output of OSsL. If true, will set the input.
	 * @param hashMap holds the hash map to set. 
	 */
	public void setInputOrOutput(boolean input, HashMap<String, String> hashMap){
		if(input) m_inputHashMap = hashMap;
		else m_outputHashMap = hashMap;
	}//setInputOrOutput
	
	/**
	 * Get the hash map of the inputs of name-value pairs for the simulation. 
	 * If the value is from a link, it is encoded (base64) into a string and then stored.  
	 * So to retrieve it, the value has to decoded first. 
	 *
	 * </p>
	 *
	 * @return the hash map of the inputs of name-value pairs for the simulation.
	 */
	public HashMap getInput(){
		return getInputOrOutput(true);	
	}//getInput
	
	/**
	 * Get the number of inputs of the simulation. 
	 * 
	 * @return the number of inputs of the simulation. 
	 */
	public int getInputNumber(){
		getInputOrOutput(true);
		return m_inputHashMap.size();
	}//getInputNumber
	
	/**
	 * Get the string value from the input hash map of the simulation given the input name. 
	 * If the value is from a link, it is encoded (base64) into a string and then stored.  
	 * So to retrieve it, the value has to decoded first. 
	 * 
	 * </p>
	 *
	 * @param name holds the input name of the simulation to be retrieved. 
	 * @return the string value from the input hash map of the simulation given the input name. 
	 */
	public String getInputByName(String name){
		getInputOrOutput(true);
		return (String)m_inputHashMap.get(name);
	}//getInputByName
	
	/**
	 * Get the names of all the simulation inputs in an array of string. 
	 *
	 * </p>
	 *
	 * @return the names of all the simulation inputs in an array of string. 
	 */
	public String[] getInputNames(){
		getInputOrOutput(true);	
		Set nameSet = m_inputHashMap.keySet();
		Object[] moName = nameSet.toArray();
		String[] msName = new String[nameSet.size()];
		for (int i = 0; i < nameSet.size(); i++) {
			msName[i] = (String)moName[i];
		}
		return msName;
	}//getInputNames
	
	/**
	 * Get the values of all the simulation inputs in an array of string. 
	 * If the value is from a link, it is encoded (base64) into a string and then stored.  
	 * So to retrieve it, the value has to decoded first. 
	 *
	 * </p>
	 *
	 * @return the values of all the simulation inputs in an array of string. 
	 */
	public String[] getInputValues(){
		getInputOrOutput(true);	
		Collection valueCollection = m_inputHashMap.values();
		Object[] moValue = valueCollection.toArray();
		String[] msValue = new String[valueCollection.size()];
		for (int i = 0; i < valueCollection.size(); i++) {
			msValue[i] = moValue[i].toString();
		}
		return msValue;
	}//getInputValues
	
	/**
	 * Replace an input el element's value.
	 * 
	 * </p>
	 *
	 * @param name holds the name of the input el element which value is to be replaced.  
	 * @param value holds the new value of the input el element to replace.  
	 * @return whether the input el element value is replaced successfully.
	 */
	public boolean replaceInputElementValue(String name, String value){
		getInputOrOutput(true);
		if(name == null) return false;
		if(value == null) return false;
		Element eInput = (Element)XMLUtil.findChildNode(m_eRoot, "input");
		if(eInput == null) return false;
		NodeList nodeList = eInput.getElementsByTagName("el");
		Element eEl;
		int iNls = nodeList==null?0:nodeList.getLength();
		for(int i = 0; i < iNls; i++){
			eEl = (Element)nodeList.item(i);
			if(eEl.getAttribute("name").equals(name)){
				XMLUtil.removeAllChildren(eEl);
				if(m_document == null) m_document = (Document)m_eRoot.getParentNode();
				eEl.appendChild(m_document.createTextNode(value));
				m_inputHashMap.remove(name);
				m_inputHashMap.put(name, value);
				return true;
			}
		}
		return false;
	}//replaceInputElementValue
	
	/**
	 * Get the hash map of the outputs of name-value pairs for the simulation. 
	 * If the value is from a link, it is encoded (base64) into a string and then stored.  
	 * So to retrieve it, the value has to decoded first. 
	 *
	 * </p>
	 *
	 * @return the hash map of the outputs of name-value pairs for the simulation.
	 */
	public HashMap getOutput(){
		return getInputOrOutput(false);	
	}//getOutput
	
	/**
	 * Get the number of outputs of the simulation. 
	 * 
	 * @return the number of outputs of the simulation. 
	 */
	public int getOutputNumber(){
		getInputOrOutput(false);
		return m_outputHashMap.size();
	}//getOutputNumber
	
	/**
	 * Get the string value from the output hash map of the simulation given the output name. 
	 * If the value is from a link, it is encoded (base64) into a string and then stored.  
	 * So to retrieve it, the value has to decoded first. 
	 * 
	 * </p>
	 *
	 * @param name holds the output name of the simulation to be retrieved.
	 * @return the string value from the output hash map of the simulation given the output name. 
	 */
	public String getOutputByName(String name){
		getInputOrOutput(false);
		return (String)m_outputHashMap.get(name);
	}//getOutputByName
	
	/**
	 * Get the names of all the simulation outputs in an array of string. 
	 *
	 * </p>
	 *
	 * @return the names of all the simulation outputs in an array of string. 
	 */
	public String[] getOutputNames(){
		getInputOrOutput(false);	
		Set nameSet = m_outputHashMap.keySet();
		Object[] moName = nameSet.toArray();
		String[] msName = new String[nameSet.size()];
		for (int i = 0; i < nameSet.size(); i++) {
			msName[i] = (String)moName[i];
		}
		return msName;
	}//getOutputNames
	
	/**
	 * Get the values of all the simulation outputs in an array of string. 
	 * If the value is from a link, it is encoded (base64) into a string and then stored.  
	 * So to retrieve it, the value has to decoded first. 
	 *
	 * </p>
	 *
	 * @return the values of all the simulation outputs in an array of string. 
	 */
	public String[] getOutputValues(){
		getInputOrOutput(false);	
		Collection valueCollection = m_outputHashMap.values();
		Object[] moValue = valueCollection.toArray();
		String[] msValue = new String[valueCollection.size()];
		for (int i = 0; i < valueCollection.size(); i++) {
			msValue[i] = moValue[i].toString();
		}
		return msValue;
	}//getOutputValues
	
	/**
	 * Replace an output el element's value.
	 * 
	 * </p>
	 *
	 * @param name holds the name of the output el element which value is to be replaced.  
	 * @param value holds the new value of the output el element to replace.  
	 * @return whether the output el element value is replaced successfully.
	 */
	public boolean replaceOutputElementValue(String name, String value){
		getInputOrOutput(false);
		if(name == null) return false;
		if(value == null) return false;
		Element eOutput = (Element)XMLUtil.findChildNode(m_eRoot, "output");
		if(eOutput == null) return false;
		NodeList nodeList = eOutput.getElementsByTagName("el");
		Element eEl;
		int iNls = nodeList==null?0:nodeList.getLength();
		for(int i = 0; i < iNls; i++){
			eEl = (Element)nodeList.item(i);
			if(eEl.getAttribute("name").equals(name)){
				XMLUtil.removeAllChildren(eEl);
				if(m_document == null) m_document = (Document)m_eRoot.getParentNode();
				eEl.appendChild(m_document.createTextNode(value));
				m_outputHashMap.remove(name);
				m_outputHashMap.put(name, value);
				return true;
			}
		}
		return false;
	}//replaceOutputElementValue
	
	/**
	 * main for test purposes.
	 *
	 * </p>
	 *
	 * @param argv command line arguments.
	 */
	public static void main(String[] argv){
		OSsLReader osslReader = new OSsLReader(false);
		System.out.println(IOUtil.readStringFromFile(OSParameter.CODE_HOME + "OSRepository/test/ossl/ossl.ossl"));
		System.out.println(osslReader.readFile(OSParameter.CODE_HOME + "OSRepository/test/ossl/ossl.ossl"));
		System.out.println(osslReader.getInputNumber());
		System.out.println(osslReader.getOutputNumber());
		System.out.println(osslReader.getInput());
		System.out.println(osslReader.getOutputByName("d"));
		String s = osslReader.getOutputByName("g");
		s = IOUtil.decodeString(s);
		System.out.println(s);
		for(int i=0;i<osslReader.getInputNumber();i++){
			System.out.println(osslReader.getInputNames()[i]);
			System.out.println(osslReader.getInputValues()[i]);
		}
		for(int i=0;i<osslReader.getOutputNumber();i++){
			System.out.println(osslReader.getOutputNames()[i]);
			System.out.println(osslReader.getOutputValues()[i]);
		}
		System.out.println(osslReader.replaceInputElementValue("b", "abc"));
		System.out.println(osslReader.replaceOutputElementValue("g", "http://www.yahoo.com"));
		
		osslReader.writeToStandardOutput();
	}//main
	
}//class OSsLReader
