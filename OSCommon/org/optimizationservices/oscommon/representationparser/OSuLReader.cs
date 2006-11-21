using System;
using System.Xml;

using org.optimizationservices.oscommon.util;
using org.optimizationservices.oscommon.localinterface;
using org.optimizationservices.oscommon.datastructure.osuri;

namespace org.optimizationservices.oscommon.representationparser{
	///	<summary>
	///	The	<c>OSuLReader</c> class	parses an OSuL instance	into a DOM tree	and
	///	provides a set of "get"	methods	that can be	
	///	used to	retrieve different pieces of information of	the	instance.
	///	@author	Jun	Ma	
	///	@version 1.0, 09/01/2005
	///	@since OS 1.0
	///	@copyright (c) 2005
	///	</summary>
	public class OSuLReader	: OSgLReader{
		/// <summary>
		/// m_osURI holds the standard OSURI, which is a local interface for 
		/// storing Optimization Services uri/url result. 
		/// </summary>
		protected OSURI m_osURI = null;

		///	<summary>
		///	constructor.
		///	</summary>
		///	<param name="validate">holds whether the reader	should be validating against the schema	or not.</param>
		public OSuLReader(bool validate){
			m_bXsdValidate = validate;
		}//constructor
	
		///	<summary>
		///	Default	constructor. 
		///	</summary>
		public OSuLReader(){
		}//constructor

		/// <summary>
		/// get the standard OSURI, a local interface for 
		/// storing Optimization Services uri/url results.
		/// </summary>
		/// <returns>the OSURI. </returns>
		public OSURI getOSURI(){
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
		 * Each member of the URI array is of a URI data structure. 
		 * It contains information such as  
		 * the uri value, matchType, serviceName, licenceRequired, userNameRequired, passwordRequired
		 * @see org.optimizationservices.oscommon.datastructure.osuri.URI
		 */
		public URI[] getURIMatches(){
			XmlNodeList nls = m_eRoot.GetElementsByTagName("uri");
			if(nls == null) return null;
			int iNls	= nls.Count;
			if(iNls <= 0) return null;
			URI[] mURI = new URI[iNls];
			for(int i = 0; i < iNls; i++){
				mURI[i] = new URI();
				XmlElement eURI = (XmlElement)(nls.Item(i));
				XmlNamedNodeMap	attributes =  eURI.Attributes;
				int n =attributes.Count;
				string sURI = XMLUtil.getElementValue(eURI);
				string sServiceName = "";
				string sMatchType = "exact";
				bool bLicenseRequired = false;
				bool bUserNameRequired = false;
				bool bPasswordRequired = false;
				for (int j = 0; j < n; j++){
					XmlNode	attr = attributes.Item(j);
					string sAttributeName  = attr.LocalName;
					string sAttributeValue = attr.Value;
					if (sAttributeName.Equals("matchType")){
						sMatchType = sAttributeValue;
					}
					if (sAttributeName.Equals("serviceName")){
						sServiceName = sAttributeValue;
					}
					if (sAttributeName.Equals("licenseRequired")){
						bLicenseRequired = (sAttributeValue!=null&&sAttributeValue.StartsWith("t"))?true:false;
					}
					if (sAttributeName.Equals("userNameRequired")){
						bUserNameRequired = (sAttributeValue!=null&&sAttributeValue.StartsWith("t"))?true:false;
					}
					if (sAttributeName.Equals("passwordRequired")){
						bPasswordRequired = (sAttributeValue!=null&&sAttributeValue.StartsWith("t"))?true:false;
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



	}//class OSuLReader
}//namespace