/**
 * @(#)OSParameterWriter 1.0 03/14/2004
 *
 * Copyright (c) 2004
 */
package org.optimizationservices.oscommon.representationparser;

import java.util.Vector;

import org.optimizationservices.oscommon.util.OSParameter;
import org.optimizationservices.oscommon.util.XMLUtil;
import org.w3c.dom.Element;
import org.w3c.dom.ProcessingInstruction;

/**
 * The <code>OSParameterWriter</code> class is used to construct an instance that follows 
 * the OSParameter format. 
 * </p>
 *
 * @author Robert Fourer, Jun Ma, Kipp Martin
 * @version 1.0, 03/14/2004
 * @since OS 1.0
 */
public class OSParameterWriter extends OSgLWriter{
	/**
	 * m_eOSParameter holds the OSParameter root element.
	 */
	protected Element m_eOSParameter = null;
	
	/**
	 * Constructor.
	 */
	public OSParameterWriter(){
		m_document = XMLUtil.createNewDocument();
		if(OSParameter.XSLT_LOCATION != null && OSParameter.XSLT_LOCATION.length() > 0){
			ProcessingInstruction xsltPI = m_document.createProcessingInstruction("xml-stylesheet",
	           "type=\"text/xsl\" href = \"" + OSParameter.XSLT_LOCATION + "OSParameter.xslt\"");
			m_document.appendChild(xsltPI);     
		}
		m_eOSParameter = createOSParameterRoot();
		m_document.appendChild(m_eOSParameter);
	}//constructor

	/**
	 * Set the os parameter related elements. 
	 * 
	 * @param names holds the names of the os parameter. It is required. 
	 * @param values holds the values of the os parameter, empty string "" if no value for an option.
	 * @param descriptions holds the descriptions of the os parameter, empty string "" if no value for an option, null for
	 * the entire array if none of the options have descriptions.
	 * @return whether the os parameter element construction is successful.
	 */
	public boolean setOSParameters(String[] names, String[] values, String[] descriptions){
		if(names == null) return false;
		if(values == null) return false;
		if(names.length != values.length) return false;
		if(descriptions != null && names.length != descriptions.length) return false;
		for(int i = 0; i < names.length; i++){
			addOSParameter(names[i], values[i], (descriptions==null)?"":descriptions[i]);
		}
		return true;
	}//setOSParameters

	/**
	 * Add an os parameter element. 
	 * 
	 * @param name holds the name of the os parameter element. It is required.
	 * @param value holds the value of the os parameter element, empty string "" if none. 
	 * @param description holds the description of the os parameter element, empty string "" if none. 
	 * @return whether the os parameter element is added successfully.
	 */
	public boolean addOSParameter(String name, String value, String description){
		if(name == null) return false;

		Vector<Element> vElements = XMLUtil.getChildElementsByTagName(m_eOSParameter, "param");
		Element eParam;
		int iNls = vElements==null?0:vElements.size();
		for(int i = 0; i < iNls; i++){
			eParam = (Element)vElements.elementAt(i);
			if(eParam.getAttribute("name").equals(name)){
				m_eOSParameter.removeChild(eParam);
				break;
			}
		}
		eParam = createParam(name, value, description);
		m_eOSParameter.appendChild(eParam);
		return true;
	}//addOSParameter
	
	/**
	 * Create the osParameter root element and its most basic required structure.
	 *
	 * </p>
	 *
	 * @return the osParameter element.
	 */
	protected Element createOSParameterRoot(){
		Element eOSParameter = XMLUtil.createOSxLRootElement(m_document, "osParameter");
		return eOSParameter;
	}//createOSParameterRoot
			
	/**
	 * Create the param element and its most basic required structure.
	 * 
	 * @param name the name of the param element. 
	 * @param value the value of the param element, empty string "" if no value. 
	 * @param description holds the description of the os parameter element, empty string "" if none. 
	 * @return the param element.
	 */
	protected Element createParam(String name, String value, String description){
		Element eParam = m_document.createElement("param");
		eParam.setAttribute("name", name);
		eParam.setAttribute("description", (description==null)?"":description);
		if(value != null && value.length() > 0){
			eParam.appendChild(m_document.createTextNode(value));
		}
		return eParam;
	}//createParam
	
	/**
	 * main for test purposes.
	 *
	 * </p>
	 *
	 * @param argv command line arguments.
	 */
	public static void main(String[] argv){
		OSParameterWriter osParameterWriter = new OSParameterWriter();
		//String sFileName = OSParameter.CODE_HOME + "OSRepository/test/osparameter/osparameter.xml";
		String[] msOSParameterNames = {"param name 0", "param name 1"};
		String[] msOSParameterValues = {"param value 0", "param value 1"};
		if(!osParameterWriter.setOSParameters(msOSParameterNames, msOSParameterValues, null)) System.out.println("set param!");
	
		if(!osParameterWriter.addOSParameter("param name 2", "param value 2", null)) System.out.println("add param!");
		if(!osParameterWriter.addOSParameter("param name 3", "param value 3", "param description 3")) System.out.println("add param!");
		System.out.println(osParameterWriter.writeToString());
	}//main
	
}//class OSParameterWriter
