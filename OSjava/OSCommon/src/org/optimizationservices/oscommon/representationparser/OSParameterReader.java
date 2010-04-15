/**
 * @(#)OSParameterReader 1.0 03/14/2004
 *
 * Copyright (c) 2004
 */
package org.optimizationservices.oscommon.representationparser;

import java.util.Collection;
import java.util.HashMap;
import java.util.Set;
import java.util.Vector;

import org.optimizationservices.oscommon.util.IOUtil;
import org.optimizationservices.oscommon.util.OSParameter;
import org.optimizationservices.oscommon.util.XMLUtil;
import org.w3c.dom.Element;
import org.w3c.dom.NamedNodeMap;
import org.w3c.dom.Node;

/**
 * The <c>OSParameterReader</c> class parses an osParameter instance into a DOM tree and
 * provides a set of "get" methods that can be used to retrieve different 
 * pieces of information of the instance.
 * </p>
 *
 * @author Robert Fourer, Jun Ma, Kipp Martin
 * @version 1.0, 03/14/2004
 * @since OS 1.0
 */
public class OSParameterReader extends OSgLReader{	
	/**
	 * m_osParameterHashMap holds a hash map of os parameters.
	 */
	protected HashMap<String, String> m_osParameterHashMap = null;

	/**
	 * m_osParameterDescriptionHashMap holds a hash map of os parameter descriptions.
	 */
	protected HashMap<String, String>	m_osParameterDescriptionHashMap = null;
	
	/**
	 * constructor
	 *
	 * </p>
	 *
	 * @param validate holds whether the reader should be validating against the schema or not.
	 */
	public OSParameterReader(boolean validate){
		m_bXsdValidate = validate;
	}//constructor	
	
	
	/**
	 * Constructor.
	 */
	public OSParameterReader(){
		
	}//constructor
   	
	/**
	 * Get the hash map of os parameters. 
	 * 
	 * @return the hash map of os parameters.
	 */
	public HashMap getOSParameters(){
		if(m_osParameterHashMap != null) return m_osParameterHashMap;
		m_osParameterHashMap = new HashMap<String, String>();
		m_osParameterDescriptionHashMap = new HashMap<String, String>();
		try{
			Vector<Element> vElements = XMLUtil.getChildElementsByTagName(m_eRoot, "param");
			int iNls	= vElements==null?0:vElements.size();
			for(int i = 0; i < iNls; i++){
				Element eParam = (Element)(vElements.elementAt(i));
				NamedNodeMap	attributes =  eParam.getAttributes();
				int n =attributes.getLength();
				String sName = "";
				String sDescription = "";
				String sValue = XMLUtil.getElementValue(eParam);
				for (int j = 0; j < n; j++){
					Node	attr = attributes.item(j);
					String sAttributeName  = attr.getNodeName();
					String sAttributeValue = attr.getNodeValue();
					if (sAttributeName.equals("name")){
						sName = sAttributeValue;
					}
					else if (sAttributeName.equals("description")){
						sDescription = sAttributeValue;
					}
				}
				m_osParameterHashMap.put(sName, sValue);
				m_osParameterDescriptionHashMap.put(sName, sDescription);
			}
		}
		catch(Exception e){
			
		}
		return m_osParameterHashMap;
	}//getOSParameters

	/**
	 * Get the number of os parameters.  
	 * 
	 * @return the number of os parameters. 
	 */
	public int getOSParameterNumber(){
		getOSParameters();
		return m_osParameterHashMap.size();
	}//getOSParameterNumber

	/**
	 * Get the string value from the os parameter hash map. 
	 * 
	 * @param name holds the name of option to get.
	 * @return string value from the os parameter hash map, null if none. 
	 */
	public String getOSParameterValueByName(String name){
		getOSParameters();
		if(m_osParameterHashMap.containsKey(name)){
			return (String)m_osParameterHashMap.get(name);
		}
		else{ 
			return null;
		}
	}//getOSParameterValueByName

	/**
	 * Get the string value from the os parameter hash map.
	 * 
	 * @param name holds the name of option to get. 
	 * @return string value from the os parameter hash map, null if none. 
	 */
	public String getOSParameterDescriptionByName(String name){
		getOSParameters();
		if(m_osParameterDescriptionHashMap.containsKey(name)){
			return (String)m_osParameterDescriptionHashMap.get(name);
		}
		else{ 
			return null;
		}
	}//getOSParameterDescriptionByName

	/**
	 * Get the names of all os parameters. 
	 * 
	 * @return the names of all os parameters. 
	 */
	public String[] getOSParameterNames(){
		getOSParameters();	
		Set nameSet = m_osParameterHashMap.keySet();
		Object[] moName = nameSet.toArray();
		String[] msName = new String[nameSet.size()];
		for (int i = 0; i < nameSet.size(); i++) {
			msName[i] = (String)moName[i];
		}
		return msName;		
	}//getOSParameterNames
	
	/**
	 * Get the values of all os parameters. 
	 * 
	 * @return the values of all os parameters. 
	 */
	public String[] getOSParameterValues(){
		getOSParameters();			
		Collection valueCollection = m_osParameterHashMap.values();
		Object[] moValue = valueCollection.toArray();
		String[] msValue = new String[valueCollection.size()];
		for (int i = 0; i < valueCollection.size(); i++) {
			msValue[i] = moValue[i].toString();
		}
		return msValue;
	}//getOSParameterValues

	/**
	 * Get the descriptions of all os parameters. 
	 * 
	 * @return the descriptions of all os parameters.
	 */
	public String[] getOSParameterDescriptions(){
		getOSParameters();			
		Collection valueCollection = m_osParameterDescriptionHashMap.values();
		Object[] moValue = valueCollection.toArray();
		String[] msDescription = new String[valueCollection.size()];
		for (int i = 0; i < valueCollection.size(); i++) {
			msDescription[i] = moValue[i].toString();
		}
		return msDescription;
	}//getOSParameterDescriptions
	
	/**
	 * main for test purposes.
	 *
	 * </p>
	 *
	 * @param argv command line arguments.
	 */
	public static void main(String[] argv){
		OSParameterReader osParameterReader = new OSParameterReader(false);
		System.out.println(IOUtil.readStringFromFile(OSParameter.CODE_HOME + "OSRepository/test/osparameter/osparameter.xml"));
		System.out.println(osParameterReader.readFile(OSParameter.CODE_HOME + "OSRepository/test/osparameter/osparameter.xml"));
		System.out.println(osParameterReader.getOSParameterNumber());
		String sValue = osParameterReader.getOSParameterValueByName("param name 0");
		if(sValue == null) System.out.println("null");
		else System.out.println(sValue);
		String sDescription = osParameterReader.getOSParameterDescriptionByName("a");
		System.out.println(sDescription);
		for(int i=0;i<osParameterReader.getOSParameterNumber();i++){
			System.out.println(osParameterReader.getOSParameterNames()[i]);
			System.out.println(osParameterReader.getOSParameterValues()[i]);
			System.out.println(osParameterReader.getOSParameterDescriptions()[i]);
		}
	}//main
	
}//class OSParameterReader
