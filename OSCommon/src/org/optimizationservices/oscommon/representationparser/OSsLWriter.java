/**
 * @(#)OSsLWriter 1.0 03/14/2004
 *
 * Copyright (c) 2004
 */
package org.optimizationservices.oscommon.representationparser;


import org.optimizationservices.oscommon.datastructure.ossimulation.SimulationElement;
import org.optimizationservices.oscommon.localinterface.OSSimulation;
import org.optimizationservices.oscommon.util.OSParameter;
import org.optimizationservices.oscommon.util.XMLUtil;
import org.w3c.dom.Element;
import org.w3c.dom.NodeList;
import org.w3c.dom.ProcessingInstruction;


/**
 * The <code>OSsLWriter</code> class is used to construct an instance that follows 
 * the OSsL format. 
 * </p>
 *
 * @author Robert Fourer, Jun Ma, Kipp Martin
 * @version 1.0, 03/14/2004
 * @since OS 1.0
 */
public class OSsLWriter extends OSgLWriter{
	
	/**
	 * m_eOSsL holds the OSsL root element.
	 */
	protected Element m_eOSsL = null;
	
	/**
	 * m_eInput holds the input child element of root element OSsL.
	 */
	protected Element m_eInput = null;
	
	/**
	 * m_eOutput holds the output child element of root element OSsL.
	 */
	protected Element m_eOutput = null;
	
	
	/**
	 * constructor
	 */
	public OSsLWriter(){
		m_document = XMLUtil.createNewDocument();
		if(OSParameter.XSLT_LOCATION != null && OSParameter.XSLT_LOCATION.length() > 0){
			ProcessingInstruction xsltPI = m_document.createProcessingInstruction("xml-stylesheet",
	           "type=\"text/xsl\" href = \"" + OSParameter.XSLT_LOCATION + "OSsL.xslt\"");
			m_document.appendChild(xsltPI);     
		}
		m_eOSsL = createOSsLRoot();
		m_document.appendChild(m_eOSsL);
	}//constructor
	
	/**
	 * set the OSSimulation, a standard os simulation interface. 
	 * @param osSimulation holds the standard os simulation interface. 
	 * @return whether the OSSimulation is set successfully. 
	 */
	public boolean setOSSimulation(OSSimulation osSimulation) throws Exception{
		if(!setSimulationInputElements(osSimulation.getSimulationInputElements())){ 
   			throw new Exception("setSimulationInputElements Unsuccessful");
		}
		if(!setSimulationOutputElements(osSimulation.getSimulationOutputElements())){ 
   			throw new Exception("setSimulationOutputElements Unsuccessful");
		}
		return true;
	}//setOSSimulation
	
	/**
	 * set simulation input elements.
	 * 
	 * @param simulationInputElements holds an array of simulation input elements. 
	 * Each member of array is a simulation element. 
	 * @return whether the simulation input elements are set successfully or not. 
	 * @see org.optimizationservices.oscommon.datastructure.ossimulation.SimulationElement
	 */
	public boolean setSimulationInputElements(SimulationElement[] simulationInputElements){
		if(simulationInputElements == null || simulationInputElements.length <= 0){
			XMLUtil.removeChildrenByName(m_eOSsL, "input");
			return true;
		}
		for(int i = 0; i < simulationInputElements.length; i++){
			setInputElement(simulationInputElements[i].name, 
					simulationInputElements[i].type==null?"":simulationInputElements[i].type, 
					simulationInputElements[i].value);
		}
		return true;
	}//setSimulationInputElements
	
	/**
	 * set simulation output elements.
	 * 
	 * @param simulationOutputElements holds an array of simulation output elements. 
	 * Each member of array is a simulation element. 
	 * @return whether the simulation output elements are set successfully or not. 
	 * @see org.optimizationservices.oscommon.datastructure.ossimulation.SimulationElement
	 */
	public boolean setSimulationOutputElements(SimulationElement[] simulationOutputElements){
		if(simulationOutputElements == null || simulationOutputElements.length <= 0){
			XMLUtil.removeChildrenByName(m_eOSsL, "output");
			return true;
		}
		for(int i = 0; i < simulationOutputElements.length; i++){
			setOutputElement(simulationOutputElements[i].name, 
					simulationOutputElements[i].type==null?"":simulationOutputElements[i].type, 
					simulationOutputElements[i].value);
		}
		return true;
	}//setSimulationOutputElements
	
	/**
	 * Set the input related elements. If the elements (e.g. the required elements) are
	 * already there, it will reset the them. If the elements are not there (e.g. the optional elements),
	 * it will add them.
	 *
	 * </p>
	 *
	 * @param names holds the names of the inputs. It is required. 
	 * @param types holds the types of the inputs, either string (default) or link. 
	 * @param values holds the values of inputs. It is required. 
	 * @return whether the input element construction is successful.
	 */
	public boolean setInput(String[] names, String[] types, String[] values){
		if(names == null) return false;
		if(values == null) return false;
		if(names.length != values.length) return false;
		if(types != null && types.length != names.length) return false;
		for(int i = 0; i < names.length; i++){
			setInputElement(names[i], (types==null)?"":types[i], values[i]);
		}
		return true;
	}//setInput
	
	/**
	 * Set an input el element. If the el element is already there, 
	 * it will reset the element. If the elements is not there, it will add the element.
	 *
	 * </p>
	 *
	 * @param name holds the name of the input el element. It is required. 
	 * @param type holds the type of the input el element, either string (default) or link. 
	 * @param value holds the value of the input el element. It is required. 
	 * @return whether the input el element is set successfully.
	 */
	public boolean setInputElement(String name, String type, String value){
		if(name == null) return false;
		if(value == null) return false;
		if(m_eInput == null){
			m_eInput = createInput(new Element[]{createEl(name, type, value)});
			m_eOSsL.appendChild(m_eInput);
			return true;
		}
		NodeList nodeList = m_eInput.getElementsByTagName("el");
		Element eEl;
		for(int i = 0; i < nodeList.getLength(); i++){
			eEl = (Element)nodeList.item(i);
			if(eEl.getAttribute("name").equals(name)){
				m_eInput.removeChild(eEl);
				break;
			}
		}
		eEl = createEl(name, type, value);
		m_eInput.appendChild(eEl);
		return true;
	}//setInputElement
	
	/**
	 * Set the output related elements. If the elements (e.g. the required elements) are
	 * already there, it will reset the them. If the elements are not there (e.g. the optional elements),
	 * it will add them.
	 *
	 * </p>
	 *
	 * @param names holds the names of the outputs. It is required. 
	 * @param types holds the types of the outputs, either string (default) or link. 
	 * @param values holds the values of outputs. It is required. 
	 * @return whether the output element construction is successful.
	 */
	public boolean setOutput(String[] names, String[] types, String[] values){
		if(names == null) return false;
		if(values == null) return false;
		if(names.length != values.length) return false;
		if(types != null && types.length != names.length) return false;
		for(int i = 0; i < names.length; i++){
			setOutputElement(names[i], (types==null)?"":types[i], values[i]);
		}
		return true;
	}//setOutput
	
	/**
	 * Set an output el element. If the el element is already there, 
	 * it will reset the element. If the elements is not there, it will add the element.
	 *
	 * </p>
	 *
	 * @param name holds the name of the output el element. It is required. 
	 * @param type holds the type of the output el element, either string (default) or link. 
	 * @param value holds the value of the output el element. It is required. 
	 * @return whether the output el element is successfully.
	 */
	public boolean setOutputElement(String name, String type, String value){
		if(name == null) return false;
		if(value == null) return false;
		if(m_eOutput == null){
			m_eOutput = createOutput(new Element[]{createEl(name, type, value)});
			m_eOSsL.appendChild(m_eOutput);
			return true;
		}
		NodeList nodeList = m_eOutput.getElementsByTagName("el");
		Element eEl;
		for(int i = 0; i < nodeList.getLength(); i++){
			eEl = (Element)nodeList.item(i);
			if(eEl.getAttribute("name").equals(name)){
				m_eOutput.removeChild(eEl);
				break;
			}
		}
		eEl = createEl(name, type, value);
		m_eOutput.appendChild(eEl);
		return true;
	}//setOutputElement
	
	/**
	 * Create the OSsL root element and its most basic required structure.
	 *
	 * </p>
	 *
	 * @return the OSsL element.
	 */
	protected Element createOSsLRoot(){
		Element eOSsL = XMLUtil.createOSxLRootElement(m_document, "ossl");
		return eOSsL;
	}//createOSsLRoot
	
	/**
	 * Create the input element and its most basic required structure.
	 *
	 * </p>
	 *
	 * @return the input element
	 */
	protected Element createInput(Element[] elArray){
		Element eInput = m_document.createElement("input");
		if(elArray != null){
			for(int i = 0; i < elArray.length; i++){
				eInput.appendChild(elArray[i]);
			}
		}
		return eInput;
	}//createInput
	
	/**
	 * Create the output element and its most basic required structure.
	 *
	 * </p>
	 *
	 * @return the output element
	 */
	protected Element createOutput(Element[] elArray){
		Element eOutput = m_document.createElement("output");
		if(elArray == null) return null;
		for(int i = 0; i < elArray.length; i++){
			eOutput.appendChild(elArray[i]);
		}
		return eOutput;
	}//createOutput
	
	/**
	 * Create the el element and its most basic required structure.
	 *
	 * </p>
	 *
	 * @return the el element
	 */
	protected Element createEl(String name, String type, String value){
		Element eEl = m_document.createElement("el");
		eEl.setAttribute("name", name);
		if(type != null && type.length() > 0){
			if(type.equals("link")) eEl.setAttribute("type", "link");
			else eEl.setAttribute("type", "string");
		}
		eEl.appendChild(m_document.createTextNode(value));
		return eEl;
	}//createEl
	
	/**
	 * main for test purposes.
	 *
	 * </p>
	 *
	 * @param argv command line arguments.
	 */
	public static void main(String[] argv){
		OSsLWriter osslWriter = new OSsLWriter();
		String sFileName = OSParameter.CODE_HOME + "OSRepository/test/ossl/ossl.ossl";
		
		String[] msInputNames = {"a", "b"};
		String[] msInputTypes = null;//{"", "link"};
		String[] msInputValues = {"aaa", "http://www.google.com"};
		
		if(!osslWriter.setInput(msInputNames, msInputTypes, msInputValues)) System.out.println(1);
		if(!osslWriter.setInput(msInputNames, msInputTypes, msInputValues)) System.out.println(2);
		
		String[] msOutputNames = {"c", "g"};
		String[] msOutputTypes = {"", "link"};
		String[] msOutputValues = {"ccc", "http://www.google.com"};
		
		if(!osslWriter.setOutput(msOutputNames, msOutputTypes, msOutputValues)) System.out.println(3);
		if(!osslWriter.setOutput(msOutputNames, msOutputTypes, msOutputValues)) System.out.println(4);
		
		osslWriter.setInputElement("x", "a", "xxx");
		osslWriter.setInputElement("x", "a", "xyz");
		
		osslWriter.setOutputElement("v", "string", "vvv");
		//osslWriter.setOutputElement("v", "string", "www");

		////////////////////

		OSsLReader osslReader = new OSsLReader(false);
		if(!osslReader.readFile(sFileName)) System.out.println("reading");
		OSSimulation osSimulation;
		try {
			osSimulation = osslReader.getOSSimulation();
			if(!osslWriter.setOSSimulation(osSimulation)) System.out.println("setOSSimulation");
		} 
		catch (Exception e) {
			e.printStackTrace();
		}
		////////////////////
		
		//osslWriter.writeToStandardOutput();
		System.out.println(osslWriter.writeToString());
		
	}//main
	
}//class OSsLWriter
