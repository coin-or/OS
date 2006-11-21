using System;
using System.Xml;

using org.optimizationservices.oscommon.util;
using org.optimizationservices.oscommon.localinterface;

namespace org.optimizationservices.oscommon.representationparser{
	/// <summary>
	/// The <c>OSgLReader</c> class is a general and generic reader class 
	/// for all the other OSxL reader classes to extend, which mostly parse an 
	/// OSxL instance into a DOM tree and provide a set of "get" methods that 
	/// can be used to retrieve different pieces of information of the OSxL instance.
	/// @author Jun Ma	
	/// @version 1.0, 09/01/2005
	/// @since OS 1.0
	/// @copyright (c) 2005
	/// </summary>
	public class OSgLReader{

		/// <summary>
		/// m_sOSxL holds the osxl String or file to be passed.
		/// </summary>
		protected string m_sOSxL = "";

		/// <summary>
		/// m_bIsOSxLFile holds whether the osxl string is a file name or a string that literally holds the osxl instance.
		/// </summary>
		protected bool m_bIsOSxLFile = false;
		
		/// <summary>
		/// m_document holds the W3C DOM type document to create XML elements and attributes. 
		/// It is the parent of the root element, e.g. the &lt;OSiL&gt; element in OSiL. It is used
		/// to create all the nodes in the DOM tree.																																																		  */
		/// </summary>        		
		public XmlDocument m_document = null;

		/// <summary>
		/// m_root holds the root node of the parsed OSxL DOM tree.
		/// </summary>
		protected internal XmlElement m_eRoot = null;
	
		/// <summary>
		/// bXsdValidate holds whether the parser should be validating against the schema or not.
		/// </summary>
		protected bool m_bXsdValidate = OSParameter.VALIDATE;

		/// <summary>
		/// Default constructor. 
		/// </summary>
		public OSgLReader(){
		}//constructor

		/// <summary>
		/// constructor
		/// </summary>
		/// <param name="validate">holds whether the OSgLReader should be validating against the schema or not.</param>
		public OSgLReader(bool validate){
			m_bXsdValidate = validate;
		}//constructor


		/// <summary>
		/// set document																																																		   */
		/// </summary>
		/// <param name="document">holds the W3C DOM type document to create XML elements and attributes.
		/// It is the parent of the root element, e.g. the &lt;OSiL&gt; element in OSiL. It is used
		/// to create all the nodes in the DOM tree.</param>
		public void setDocument(XmlDocument document){
			m_document = document;
		}//setDocument

		/// <summary>
		/// get document
		/// </summary>
		/// <returns>the document which holds the W3C DOM type document to create XML elements and attributes.
		/// It is the parent of the root element, e.g. the &lt;OSiL&gt; element in OSiL. It is used
		/// to create all the nodes in the DOM tree.</returns>
		public XmlDocument getDocument(){
			return m_document;
		}//getDocument

		/// <summary>
		/// set root element
		/// </summary>
		/// <param name="rootElement">rootElement holds the root element to be set. </param>
		public void setRootElement(XmlElement rootElement){
			m_eRoot = rootElement;
		}//setRootElement

		/// <summary>
		/// Get root element. 
		/// </summary>
		/// <returns>the root element. </returns>
		public XmlElement getRootElement(){
			return m_eRoot;
		}//getRootElement

		/// <summary>
		/// Get whether the parser should be validating against the schema or not.
		/// </summary>
		/// <returns>whether the parser should be validating against the schema or not.</returns>
		public bool isValidate(){
			return m_bXsdValidate;
		}//isValidate

		/// <summary>
		/// Set whether the parser should be validating against the schema or not.
		/// </summary>
		/// <param name="xsdValidate">holds whether the parser should be validating against the schema or not.</param>
		public void setValidate(bool xsdValidate){
			m_bXsdValidate = xsdValidate;
		}//setValidate
	
		/// <summary>
		/// Read the xml file that contains the OSxL instance.
		/// </summary>
		/// <param name="fileName">holds the xml filename that contains the OSxL instance.</param>
		/// <returns>whether the file is read successfully without any error.</returns>
		public bool readFile(string fileName){
			m_sOSxL = fileName;
			m_bIsOSxLFile = true;
			XmlDocument doc = XMLUtil.parseFileUsingDOM(fileName, m_bXsdValidate);
			if(doc == null){
				return false;
			}
			else{
				m_eRoot = (XmlElement)doc.DocumentElement;
				return true;
			}
		}//readFile

		/// <summary>
		/// Read the xml string that contains the OSxL instance.
		/// </summary>
		/// <param name="osxlString">holds the xml string that contains the OSxL instance.</param>
		/// <returns>whether the string is read successfully without any error.</returns>
		public bool readString(string osxlString){
			m_sOSxL = osxlString;
			m_bIsOSxLFile = false;
			XmlDocument doc = XMLUtil.parseStringUsingDOM(osxlString, m_bXsdValidate);
			if(doc == null){
				return false;
			}
			else{
				m_eRoot = (XmlElement)doc.DocumentElement;
				return true;
			}
		}//readString
		

		/// <summary>
		/// Write the xml file from the internally constructed DOM tree structure that contains the
		/// OSxL instance to a file.
		/// </summary>
		/// <param name="fileName">holds the xml filename to write out the file to.</param>
		/// <returns>whether the file is written successfully without any error.</returns>
		public bool writeToFile(string fileName){
			if(m_document == null) m_document = (XmlDocument)m_eRoot.ParentNode;
			return XMLUtil.writeXMLDocumentToFile(m_document, fileName);
		}//writeToFile

		/// <summary>
		/// Write the xml file from the internally constructed DOM tree structure that contains the
		/// OSxL instance to the standard output (e.g. screen).
		/// </summary>
		/// <returns>whether the output is written successfully without any error.</returns>
		public bool writeToStandardOutput(){
			if(m_document == null) m_document = (XmlDocument)m_eRoot.ParentNode;
			return XMLUtil.writeXMLDocumentToStandardOutput(m_document);
		}//writeToStandardOutput

		/// <summary>
		/// Write the xml file from the internally constructed DOM tree structure that contains the
		/// OSxL instance to a string to be returned.
		/// </summary>
		/// <returns>a string  that contains the OSxL optimization instance. If error is encountered in writing the string, null is returned.</returns>
		public String writeToString(){
			if(m_document == null) m_document = (XmlDocument)m_eRoot.ParentNode;
			return XMLUtil.writeXMLDocumentToString(m_document);
		}//writeToString

	}//class OSgLReader
}//namespace
