using System;
using System.Xml;
using System.Collections;

using org.optimizationservices.oscommon.localinterface;
using org.optimizationservices.oscommon.util;

namespace org.optimizationservices.oscommon.representationparser{
	/// <summary>
	/// The <c>OSParameterWriter</c> class is used to construct an instance that follows 
	/// the OSParameter format. 
	/// @author Jun Ma	
	/// @version 1.0, 09/01/2005
	/// @since OS 1.0
	/// @copyright (c) 2005
	/// </summary>
	public class OSParameterWriter : OSgLWriter{
		/// <summary>
		/// m_eOSParameter holds the OSParameter root element.
		/// </summary>
		protected internal XmlElement m_eOSParameter = null;
			
		/// <summary>
		/// constructor. 
		/// </summary>
		public OSParameterWriter(){
			m_document = XMLUtil.createNewDocument();
			if(OSParameter.XSLT_LOCATION != null && OSParameter.XSLT_LOCATION.Length > 0){
				XmlProcessingInstruction xsltPI = m_document.CreateProcessingInstruction("xml-stylesheet",
					"type=\"text/xsl\" href = \"" + OSParameter.XSLT_LOCATION + "OSParameter.xslt\"");
				m_document.AppendChild(xsltPI);     
			}
			m_eOSParameter = createOSParameterRoot();
			m_document.AppendChild(m_eOSParameter);
		}//constructor

		
		/// <summary>
		/// Set the os parameter related elements. 
		/// </summary>
		/// <param name="names">holds the names of the os parameter. It is required. </param>
		/// <param name="values">holds the values of the os parameter, empty string "" if no value for an option.</param>
		/// <param name="descriptions">holds the descriptions of the os parameter, empty string "" if no value for an option, null for
		/// the entire array if none of the options have descriptions.</param>
		/// <returns>whether the os parameter element construction is successful.</returns>
		public bool setOSParameters(string[] names, string[] values, string[] descriptions){
			if(names == null) return false;
			if(values == null) return false;
			if(names.Length != values.Length) return false;
			if(descriptions != null && names.Length != descriptions.Length) return false;
			for(int i = 0; i < names.Length; i++){
				addOSParameter(names[i], values[i], (descriptions==null)?"":descriptions[i]);
			}
			return true;
		}//setOSParameters


		/// <summary>
		/// Add an os parameter element. 
		/// </summary>
		/// <param name="name">holds the name of the os parameter element. It is required. </param>
		/// <param name="value">holds the value of the os parameter element, empty string "" if none. </param>
		/// <param name="description">holds the description of the os parameter element, empty string "" if none. </param>
		/// <returns>whether the os parameter element is added successfully.</returns>
		public bool addOSParameter(string name, string value, string description){
			if(name == null) return false;

			ArrayList vNodeList = XMLUtil.getChildElementsByTagName(m_eOSParameter, "param"); 
			int iNls = vNodeList==null?0:vNodeList.Count;
			XmlElement eParam;
			for(int i = 0; i < iNls; i++){
				eParam = (XmlElement)vNodeList[i];
				if(eParam.GetAttribute("name").Equals(name)){
					m_eOSParameter.RemoveChild(eParam);
					break;
				}
			}
			eParam = createParam(name, value, description);
			m_eOSParameter.AppendChild(eParam);
			return true;
		}//addOSParameter

		/// <summary>
		/// Create the osParameter root element and its most basic required structure.
		/// </summary>
		/// <returns>the osParameter element.</returns>
		protected XmlElement createOSParameterRoot(){
			XmlElement eOSParameter = XMLUtil.createOSxLRootElement(m_document, "osParameter");
			return eOSParameter;
		}//createOSParameterRoot

		/// <summary>
		/// Create the param element and its most basic required structure.
		/// </summary>
		/// <param name="name">the name of the param element. </param>
		/// <param name="value">the value of the param element, empty string "" if no value. </param>
		/// <param name="description">holds the description of the os parameter element, empty string "" if none. </param>
		/// <returns>the param element.</returns>
		protected XmlElement createParam(string name, string value, string description){
			XmlElement eParam = m_document.CreateElement("param");
			eParam.SetAttribute("name", name);
			eParam.SetAttribute("description", (description==null)?"":description);
			if(value != null && value.Length > 0){
				eParam.AppendChild(m_document.CreateTextNode(value));
			}
			return eParam;
		}//createParam

	}//class OSParameterWriter
}//namespace
