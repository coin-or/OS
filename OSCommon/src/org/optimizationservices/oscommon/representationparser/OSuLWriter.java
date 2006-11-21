/**
 * @(#)OSuLWriter 1.0 03/14/2004
 *
 * Copyright (c) 2004
 */
package org.optimizationservices.oscommon.representationparser;

import org.optimizationservices.oscommon.datastructure.osuri.URI;
import org.optimizationservices.oscommon.localinterface.OSURI;
import org.optimizationservices.oscommon.util.OSParameter;
import org.optimizationservices.oscommon.util.XMLUtil;
import org.w3c.dom.Element;
import org.w3c.dom.NodeList;
import org.w3c.dom.ProcessingInstruction;

/**
 * The <code>OSuLWriter</code> class is used to construct an instance that follows 
 * the OSuL format. 
 * </p>
 *
 * @author Robert Fourer, Jun Ma, Kipp Martin
 * @version 1.0, 03/14/2004
 * @since OS 1.0
 */
public class OSuLWriter extends OSgLWriter{
	
	/**
	 * m_eOSuL holds the OSuL root element.
	 */
	protected Element m_eOSuL = null;
	
	/**
	 * constructor. 
	 *
	 */
	public OSuLWriter(){
		m_document = XMLUtil.createNewDocument();
		if(OSParameter.XSLT_LOCATION != null && OSParameter.XSLT_LOCATION.length() > 0){
			ProcessingInstruction xsltPI = m_document.createProcessingInstruction("xml-stylesheet",
	           "type=\"text/xsl\" href = \"" + OSParameter.XSLT_LOCATION + "OSuL.xslt\"");
			m_document.appendChild(xsltPI);     
		}
		m_eOSuL = createOSuLRoot();
		m_document.appendChild(m_eOSuL);
	}//constructor
	
	/**
	 * set the OSURI, a standard os uri/url interface. 
	 * @param osURI holds the standard os uri interface. 
	 * @return whether the OSURI is set successfully. 
	 */
	public boolean setOSURI(OSURI osURI) throws Exception{
		if(!setURIMatches(osURI.getURIMatches())){ 
   			throw new Exception("setURIMatches Unsuccessful");
		}
		return true;
	}//setOSURI
	
	/**
	 * Set URI matches. 
	 * 
	 * @param URIs holds an array of URIs. 
	 * Each member of the URI array is of a URI data structure. It contains information such as  
	 * the uri value, matchType, serviceName, licenceRequired, userNameRequired, passwordRequired.
	 * @return whether the URIs are set successfully or not. 
	 * @see org.optimizationservices.oscommon.datastructure.osuri.URI
	 */
	public boolean setURIMatches(URI[] URIs){
		if(URIs == null || URIs.length <= 0){
			XMLUtil.removeAllChildren(m_eOSuL);
			return true;
		}
		for(int i = 0; i < URIs.length; i++){
			addURI(URIs[i]);
		}
		return true;
	}//setURIMatches
	
	
	/**
	 * Add a uri match. 
	 * 
	 * @param URI holds a uri match. It contains information such as  
	 * the uri value, matchType, serviceName, licenceRequired, userNameRequired, passwordRequired.
	 * @return whether the uri element is added successfully.
	 */
	public boolean addURI(URI uri){
		if(uri == null) return true;
		NodeList nodeList = m_eOSuL.getElementsByTagName("uri");
		Element eURI;
		if(nodeList != null){
			for(int i = 0; i < nodeList.getLength(); i++){
				eURI = (Element)nodeList.item(i);
				if(XMLUtil.getElementValue(eURI).equals(uri.value)){
					m_eOSuL.removeChild(eURI);
					break;
				}
			}
		}
		eURI =  m_document.createElement("uri");
		eURI.appendChild(m_document.createTextNode(uri.value));
		if(uri.serviceName != null && uri.serviceName.length() > 0) {
			eURI.setAttribute("serviceName", uri.serviceName);
		}
		if(uri.matchType != null && uri.matchType.length() > 0 && !uri.matchType.equals("exact")) {
			eURI.setAttribute("matchType", uri.matchType);
		}
		if(uri.licenseRequired == true) {
			eURI.setAttribute("licenseRequired", "true");
		}
		if(uri.userNameRequired == true) {
			eURI.setAttribute("userNameRequired", "true");
		}
		if(uri.passwordRequired == true) {
			eURI.setAttribute("passwordRequired", "true");
		}
		m_eOSuL.appendChild(eURI);
		return true;
	}//addURI
	
	/**
	 * Create the OSuL root element and its most basic required structure.
	 * 
	 * @return the OSuL element.
	 */
	protected Element createOSuLRoot(){
		Element eOSuL = XMLUtil.createOSxLRootElement(m_document, "osul");

		return eOSuL;
	}//createOSuLRoot
	
	/**
	 * main for test purposes.
	 *
	 * </p>
	 *
	 * @param argv command line arguments.
	 */
	public static void main(String[] argv){
		OSuLWriter osulWriter = new OSuLWriter();
		String sFileName = OSParameter.CODE_HOME + "OSRepository/test/osul/osul.osul";
		
		URI[] mURI = new URI[2];
		mURI[0] = new URI();
		mURI[1] = new URI();
		mURI[0].value = "http://www.yahoo.com";
		mURI[0].serviceName = "yahoo";
		mURI[0].matchType="guess";
		mURI[0].licenseRequired = true;
		mURI[0].userNameRequired = true;
		mURI[0].passwordRequired = true;
		mURI[1].value = "http://google.com";
		if(!osulWriter.setURIMatches(mURI)) System.out.println(1);
		if(!osulWriter.addURI(mURI[0])) System.out.println(2);
		
		////////////////////

		OSuLReader osulReader = new OSuLReader(false);
		if(!osulReader.readFile(sFileName)) System.out.println("reading");
		OSURI osURI;
		try {
			osURI = osulReader.getOSURI();
			if(!osulWriter.setOSURI(osURI)) System.out.println("setOSURI");
		} 
		catch (Exception e) {
			e.printStackTrace();
		}
		////////////////////
		
		System.out.println(osulWriter.writeToString());
	}//main
	
}//class OSuLWriter
