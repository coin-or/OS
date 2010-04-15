/**
 * @(#)OSuLReader 1.0 03/14/2004
 *
 * Copyright (c) 2004
 */
package org.optimizationservices.oscommon.representationparser;
import org.optimizationservices.oscommon.datastructure.osuri.URI;
import org.optimizationservices.oscommon.localinterface.OSURI;
import org.optimizationservices.oscommon.util.XMLUtil;
import org.w3c.dom.Element;
import org.w3c.dom.NamedNodeMap;
import org.w3c.dom.Node;
import org.w3c.dom.NodeList;

/**
 * The <c>OSuLReader</c> class parses an OSuL instance into a DOM tree and
 * provides a set of "get" methods that can be used to retrieve different 
 * pieces of information of the instance.
 * </p>
 *
 * @author Robert Fourer, Jun Ma, Kipp Martin
 * @version 1.0, 03/14/2004
 * @since OS 1.0
 */
public class OSuLReader extends OSgLReader{	
	/**
	 * m_osURI holds the standard OSURI, which is a local interface for 
	 * storing Optimization Services uri/url result. 
	 */
	protected OSURI m_osURI = null;
	
	/**
	 * constructor.
	 * 
	 * @param validate holds whether the reader	should be validating against the schema	or not.
	 */
	public OSuLReader(boolean validate){
		m_bXsdValidate = validate;
	}//constructor
	
	/**
	 * Default	constructor. 
	 *
	 */
	public OSuLReader(){
	}//constructor
		
	/**
	 * get the standard OSURI, a local interface for 
	 * storing Optimization Services uri/url results.
	 * 
	 * @return the OSURI. 
	 * @throws Exception if there are errors getting the OSURI. 
	 */
   	public OSURI getOSURI() throws Exception{
		if(m_osURI != null){
			return m_osURI;
		}
		m_osURI = new OSURI();
		if(!m_osURI.setURIMatches(getURIMatches())) throw new Exception("setURIMatches Unsuccessful");
		return m_osURI;
   	}//getOSURI
   	
	/**
	 * Get URI matches. 
	 * 
	 * @return an array of URIs, null if none. 
	 * Each member of the URI array is of a URI data structure. It contains information such as  
	 * the uri value, matchType, serviceName, licenceRequired, userNameRequired, passwordRequired.
	 * @see org.optimizationservices.oscommon.datastructure.osuri.URI
	 */
	public URI[] getURIMatches(){
		NodeList nls = m_eRoot.getElementsByTagName("uri");
		if(nls == null) return null;
		int iNls	= nls.getLength();
		if(iNls <= 0) return null;
		URI[] mURI = new URI[iNls];
		for(int i = 0; i < iNls; i++){
			mURI[i] = new URI();
			Element eURI = (Element)(nls.item(i));
			NamedNodeMap	attributes =  eURI.getAttributes();
			int n =attributes.getLength();
			String sURI = XMLUtil.getElementValue(eURI);
			String sServiceName = "";
			String sMatchType = "exact";
			boolean bLicenseRequired = false;
			boolean bUserNameRequired = false;
			boolean bPasswordRequired = false;
			for (int j = 0; j < n; j++){
				Node	attr = attributes.item(j);
				String sAttributeName  = attr.getNodeName();
				String sAttributeValue = attr.getNodeValue();
				if (sAttributeName.equals("matchType")){
					sMatchType = sAttributeValue;
				}
				if (sAttributeName.equals("serviceName")){
					sServiceName = sAttributeValue;
				}
				if (sAttributeName.equals("licenseRequired")){
					bLicenseRequired = (sAttributeValue!=null&&sAttributeValue.startsWith("t"))?true:false;
				}
				if (sAttributeName.equals("userNameRequired")){
					bUserNameRequired = (sAttributeValue!=null&&sAttributeValue.startsWith("t"))?true:false;
				}
				if (sAttributeName.equals("passwordRequired")){
					bPasswordRequired = (sAttributeValue!=null&&sAttributeValue.startsWith("t"))?true:false;
				}
			}
			mURI[i].value = sURI;
			mURI[i].matchType = sMatchType;
			mURI[i].serviceName = sServiceName;
			mURI[i].licenseRequired = bLicenseRequired;
			mURI[i].userNameRequired = bUserNameRequired;
			mURI[i].passwordRequired = bPasswordRequired;
		}
		return mURI;
	}//getURIMatches
	
	/**
	 * main for test purposes.
	 *
	 * </p>
	 *
	 * @param argv command line arguments.
	 */
	public static void main(String[] argv){

	}//main
	
}//class OSuLReader
