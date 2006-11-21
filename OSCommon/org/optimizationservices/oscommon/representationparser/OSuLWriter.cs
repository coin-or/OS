using System;
using System.Xml;
using org.optimizationservices.oscommon.util;
using org.optimizationservices.oscommon.localinterface;
using org.optimizationservices.oscommon.datastructure.osuri;

namespace org.optimizationservices.oscommon.representationparser{
	/// <summary>
	/// The <c>OSuLWriter</c> class is used to construct an instance that follows 
	/// the OSuL format. 
	/// @author Jun Ma	
	/// @version 1.0, 09/01/2005
	/// @since OS 1.0
	/// @copyright (c) 2005
	/// </summary>
	public class OSuLWriter : OSgLWriter{
		/// <summary>
		/// m_eOSuL holds the OSuL root element.
		/// </summary>
		protected internal XmlElement m_eOSuL = null;


		/// <summary>
		/// constructor. 
		/// </summary>
		public OSuLWriter(){
			m_document = XMLUtil.createNewDocument();
			if(OSParameter.XSLT_LOCATION != null && OSParameter.XSLT_LOCATION.Length > 0){
				XmlProcessingInstruction xsltPI = m_document.CreateProcessingInstruction("xml-stylesheet",
					"type=\"text/xsl\" href = \"" + OSParameter.XSLT_LOCATION + "OSuL.xslt\"");
				m_document.AppendChild(xsltPI);     
			}
			m_eOSuL = createOSuLRoot();
			m_document.AppendChild(m_eOSuL);
		}//constructor

		/// <summary>
		/// set the OSURI, a standard os uri/url interface. 
		/// </summary>
		/// <param name="osURI">holds the standard os uri interface. </param>
		/// <returns>whether the OSURI is set successfully. </returns>
		public bool setOSURI(OSURI osURI){
			if(!setURIMatches(osURI.getURIMatches())){ 
				throw new Exception("setURIMatches Unsuccessful");
			}
			return true;
		}//setOSURI

		/// <summarySet URI matches. >
		/// @see org.optimizationservices.oscommon.datastructure.osuri.URI
		/// 
		/// </summary>
		/// <param name="URIs">holds an array of URIs. 
		/// Each member of the URI array is of a URI data structure. 
		/// It contains information such as  
		/// the uri value, matchType, serviceName, licenceRequired, userNameRequired, 
		/// passwordRequired
		/// </param>
		/// <returns>whether the URIs are set successfully or not. </returns>
		public bool setURIMatches(URI[] URIs){
			if(URIs == null || URIs.Length <= 0){
				XMLUtil.removeAllChildren(m_eOSuL);
				return true;
			}
			for(int i = 0; i < URIs.Length; i++){
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
		public bool addURI(URI uri){
			if(uri == null) return true;
			XmlNodeList nodeList = m_eOSuL.GetElementsByTagName("uri");
			XmlElement eURI;
			if(nodeList != null){
				for(int i = 0; i < nodeList.Count; i++){
					eURI = (XmlElement)nodeList.Item(i);
					if(XMLUtil.getElementValue(eURI).Equals(uri.value)){
						m_eOSuL.RemoveChild(eURI);
						break;
					}
				}
			}
			eURI =  m_document.CreateElement("uri");
			eURI.AppendChild(m_document.CreateTextNode(uri.value));
			if(uri.serviceName != null && uri.serviceName.Length > 0) {
				eURI.SetAttribute("serviceName", uri.serviceName);
			}
			if(uri.matchType != null && uri.matchType.Length > 0 && !uri.matchType.Equals("exact")) {
				eURI.SetAttribute("matchType", uri.matchType);
			}
			if(uri.licenseRequired == true) {
				eURI.SetAttribute("licenseRequired", "true");
			}
			if(uri.userNameRequired == true) {
				eURI.SetAttribute("userNameRequired", "true");
			}
			if(uri.passwordRequired == true) {
				eURI.SetAttribute("passwordRequired", "true");
			}
			m_eOSuL.AppendChild(eURI);
			return true;
		}//addURI

		/// <summary>
		/// Create the OSuL root element and its most basic required structure.
		/// </summary>
		/// <returns>the OSuL element.</returns>
		protected XmlElement createOSuLRoot(){
			XmlElement eOSuL = XMLUtil.createOSxLRootElement(m_document, "osul");

			return eOSuL;
		}//createOSuLRoot

	}//class OSuLWriter
}//namespace
