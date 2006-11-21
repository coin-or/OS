using System;
using System.Xml;

using org.optimizationservices.oscommon.util;
using org.optimizationservices.oscommon.localinterface;

namespace org.optimizationservices.oscommon.representationparser{
	/// <summary>
	/// The <c>OSgLWriter</c> class is a general and generic writer class for all 
	/// the other OSxL writer classes to extend, which mostly writes a DOM tree of an 
	/// OSxL instance and provide a set of "set" and "add" methods that can be used to 
	/// construct different pieces of information of the OSxL instance.
	/// @author Jun Ma	
	/// @version 1.0, 09/01/2005
	/// @since OS 1.0
	/// @copyright (c) 2005
	/// </summary>
	public class OSgLWriter{

		/// <summary>
		/// m_document holds the W3C DOM type document to create XML elements and attributes.
		/// It is the parent of the root element, e.g. the &lt;OSiL&gt; element in OSiL. 
		/// It is used to create all the nodes in the DOM tree.
		/// </summary>
		public XmlDocument m_document = null;
	
		/// <summary>
		/// Default constructor. 
		/// </summary>
		public OSgLWriter(){
		}//constructor

		/// <summary>
		/// Write the xml file from the internally constructed DOM tree structure that contains the
		/// OSxL instance to a file.
		/// </summary>
		/// <param name="fileName">holds the xml filename to write out the file to.</param>
		/// <returns>whether the file is written successfully without any error.</returns>
		public bool writeToFile(string fileName){
			return XMLUtil.writeXMLDocumentToFile(m_document, fileName);
		}//writeToFile

		/// <summary>
		/// Write the xml file from the internally constructed DOM tree structure that contains the
		/// OSxL instance to the standard output (e.g. screen).
		/// </summary>
		/// <returns>whether the output is written successfully without any error.</returns>
		public bool writeToStandardOutput(){
			return XMLUtil.writeXMLDocumentToStandardOutput(m_document);
		}//writeToStandardOutput

		/// <summary>
		/// Write the xml file from the internally constructed DOM tree structure that contains the
		/// OSxL instance to a string to be returned.
		/// </summary>
		/// <returns>a string  that contains the OSiL optimization instance. If error is encountered in writing the string, null is returned.</returns>
		public string writeToString(){
			return XMLUtil.writeXMLDocumentToString(m_document);
		}//writeToString

		/// <summary>
		/// Set document. 
		/// </summary>
		/// <param name="document">document holds the W3C DOM type document to create XML elements
		///  and attributes. It is the parent of the root element, e.g. the &lt;OSiL&gt; 
		///  element in OSiL. It is used to create all the nodes in the DOM tree.</param>
		public void setDocument(XmlDocument document){
			m_document = document;
		}//setDocument

		/// <summary>
		/// Get document.
		/// </summary>
		/// <returns>the document which holds the W3C DOM type document to create XML elements and attributes.
		/// It is the parent of the root element, e.g. the &lt;OSiL&gt; element in OSiL. 
		/// It is used to create all the nodes in the DOM tree.</returns>
		public XmlDocument getDocument(){
			return m_document;
		}//getDocument

	}//class OSgLWriter
}//namespace
