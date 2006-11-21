using System;
using System.Xml;
using System.Text;
using System.IO;
using System.Collections;

namespace org.optimizationservices.oscommon.util{
	/// <summary>
	/// The <c>XMLUtil</c> class contains methods for performing
	/// XML related operations used by all other classes and projects
	/// @author Jun Ma	
	/// @version 1.0, 09/01/2005
	/// @since OS 1.0
	/// @copyright (c) 2005
	/// </summary>
	public class XMLUtil{
		public XMLUtil(){
		}//constructor

		/// <summary>
		/// Parse the xml file that contains the xml instance using DOM.
		/// </summary>
		/// <param name="fileName">holds the name of the file that contains the xml instance.</param>
		/// <param name="validate">holds whether the parser should be validating against the xml schema or not.</param>
		/// <returns>xml file in a DOM document. If there is error, return null.</returns>
		public static XmlDocument parseFileUsingDOM(string fileName, bool validate){
			try {
				XmlDocument document = new XmlDocument();
				XmlTextReader xmlTextReader = new XmlTextReader(fileName);
				if(validate){
					XmlValidatingReader xmlValidatingReader = new XmlValidatingReader(xmlTextReader);
					xmlValidatingReader.ValidationType = ValidationType.Auto;
					document.Load(xmlValidatingReader);
				}
				else{
					document.Load(xmlTextReader);
				}
				return document;
			}
			catch(Exception e){
				Console.WriteLine(e.ToString());
				return null;
			}
		}//parseFileUsingDOM

		/// <summary>
		/// Parse the xml string that contains the xml instance using DOM.
		/// </summary>
		/// <param name="xmlString">holds the xml string that contains the xml instance.</param>
		/// <param name="validate">holds whether the parser should be validating against the xml schema or not.</param>
		/// <returns>xml string in a DOM document. If there is error, return null.</returns>
		public static XmlDocument parseStringUsingDOM(string xmlString, bool validate){
			try {
				XmlDocument document = new XmlDocument();
				XmlTextReader xmlTextReader = new XmlTextReader(xmlString, XmlNodeType.Document, null);					
				if(validate){
					XmlValidatingReader xmlValidatingReader = new XmlValidatingReader(xmlTextReader);
					xmlValidatingReader.ValidationType = ValidationType.Auto;
					document.Load(xmlValidatingReader);
				}
				else{
					document.Load(xmlTextReader);
				}
				return document;
			}
			catch(Exception e){
				Console.WriteLine(e.ToString());
				return null;
			}
		}//parseStringUsingDOM

		/// <summary>
		/// Obtain a new instance of a DOM object to build a DOM tree with.  
		/// </summary>
		/// <returns>a new instance of a DOM Document object.</returns>
		public static XmlDocument createNewDocument(){
			return new XmlDocument();
		}//createNewDocument


		/// <summary>
		/// Write an xml file from a DOM tree document to a file.
		/// </summary>
		/// <param name="xmlDocument">xmlDocument holds the xml document to write out to a file.</param>
		/// <param name="fileName">fileName	holds the xml filename to write out the file to.</param>
		/// <returns>whether the file is written successfully without any error.</returns>
		public static bool writeXMLDocumentToFile(XmlDocument xmlDocument, string fileName){
			try{
				XmlTextWriter xmlTextWriter = new XmlTextWriter(fileName, System.Text.Encoding.UTF8);
				xmlTextWriter.Formatting = OSParameter.XML_INDENTING?Formatting.Indented:Formatting.None;
				xmlDocument.Save(xmlTextWriter);
				xmlTextWriter.Flush();
				xmlTextWriter.Close();
				return true;
			}
			catch(Exception e){
				Console.WriteLine(e.ToString());
				return false;
			}
		}//writeXMLDocumentToFile

		/// <summary>
		/// Write an xml file from a DOM tree document to the standard output (e.g. screen)..
		/// </summary>
		/// <param name="xmlDocument">xmlDocument holds the xml document to write out to the standard output.</param>
		/// <returns>whether the file is written successfully without any error.</returns>
		public static bool writeXMLDocumentToStandardOutput(XmlDocument xmlDocument){
			try{
				//XmlTextWriter xmlTextWriter = new XmlTextWriter(Console.Out, System.Text.Encoding.UTF8);
				XmlTextWriter xmlTextWriter = new XmlTextWriter(Console.OpenStandardOutput(), Encoding.UTF8); 

				xmlTextWriter.Formatting = OSParameter.XML_INDENTING?Formatting.Indented:Formatting.None;
				xmlDocument.Save(xmlTextWriter);
				xmlTextWriter.Flush();
				xmlTextWriter.Close();
				return true;
			}
			catch(Exception e){
				Console.WriteLine(e.ToString());
				return false;
			}
		}//writeXMLDocumentToStandardOutput

		/// <summary>
		/// Write an xml file from a DOM tree document to a string.
		/// </summary>
		/// <param name="xmlDocument">xmlDocument holds the xml document to write out to the String.</param>
		/// <returns>a string  that contains the xml. If error is encountered in writing the string, null is returned.</returns>
		public static string writeXMLDocumentToString(XmlDocument xmlDocument){
			string sOut = "";
			try{
				StringBuilder stringBuilder = new StringBuilder();
				EncodedStringWriter encodedStringWriter = new EncodedStringWriter(stringBuilder, Encoding.UTF8);
				XmlTextWriter xmlTextWriter = new XmlTextWriter(encodedStringWriter);
				xmlTextWriter.Formatting = OSParameter.XML_INDENTING?Formatting.Indented:Formatting.None;
				xmlDocument.Save(xmlTextWriter);
				xmlTextWriter.Flush();
				xmlTextWriter.Close();
				sOut = stringBuilder.ToString();
				return sOut;
			}
			catch(Exception e){
				Console.WriteLine(e.ToString());
				return null;
			}
		}//writeXMLDocumentToString
		
		/// <summary>
		/// Implements a TextWriter for writing information to a string. 
		/// The information is stored in an underlying StringBuilder.
		/// This class is used by the writeXMLDocumentToString method. 
		/// </summary>
		public class EncodedStringWriter: StringWriter{
			/// <summary>
			/// m_encoding holds the encoding style of the string writer. 
			/// </summary>
			private Encoding m_encoding;

			/// <summary>
			/// Constuctor with encoding to set. 
			/// </summary>
			/// <param name="stringBuilder">holds the string builder to be constructed</param>
			/// <param name="encoding">holds the encoding style for the string writer</param>
			public EncodedStringWriter(StringBuilder stringBuilder, Encoding encoding):base(stringBuilder){
				m_encoding = encoding;
			}//constructor

			/// <summary>
			/// Gets the Encoding in which the output is written.</
			/// </summary>
			public override Encoding Encoding{
				get{
					return m_encoding;
				}
			}//Encoding property

		}//class EncodedStringWriter

		/// <summary>
		/// Find a parent node's first child node by the child node's name.
		/// </summary>
		/// <param name="parentNode">parentNode holds the parent node.</param>
		/// <param name="childNodeName">childNodeName holds the name of the child node to find.</param>
		/// <returns>the first child node if found, otherwise null.</returns>
		public static XmlNode findChildNode(XmlNode parentNode, string childNodeName){
			XmlNodeList childNodes = parentNode.ChildNodes;
			if(childNodes == null) return null;
			for(int i = 0; i < childNodes.Count; i++){
				if(childNodes.Item(i).LocalName.Equals(childNodeName)){
					return childNodes.Item(i);
				}
			}
			return null;
		}//findChildNode

		/// <summary>
		/// Get a parent node's child elements by the child node's tag name.
		/// </summary>
		/// <param name="parentNode">parentNode holds the parent node.</param>
		/// <param name="childNodeName">childNodeName holds the name of the children node to find.</param>
		/// <returns>a vector of child elements that mathces the name.</returns>
		public static ArrayList getChildElementsByTagName(XmlNode parentNode, String childNodeName){
			ArrayList vElement = new ArrayList();
			XmlNodeList childNodes =	parentNode.ChildNodes;
			for(int i	= 0; i < childNodes.Count; i++){
				if(childNodes.Item(i).LocalName.Equals(childNodeName)){
					vElement.Add((XmlElement)childNodes.Item(i));
				}
			}
			return vElement;
		}//getChildElementsByTagName

		/// <summary>
		/// Remove all the child nodes of a parent node.
		/// </summary>
		/// <param name="parentNode">holds the node for which its child nodes are to be removed.</param>
		/// <returns>the number of child nodes removed.</returns>
		public static int removeAllChildren(XmlNode parentNode){
			int iChildren = 0;
			if(parentNode.ChildNodes != null){
				iChildren = parentNode.ChildNodes.Count;
				for(int i = 0; i < iChildren; i++){
					parentNode.RemoveChild(parentNode.ChildNodes.Item(0));
				}
			}
			return iChildren;
		}//removeAllChildren

		/// <summary>
		/// Remove all the attributes of an element.
		/// </summary>
		/// <param name="element">element holds the element for which its attributes are to be removed.</param>
		/// <returns>the number of attributes removed.</returns>
		public static int removeAllAttributes(XmlElement element){
			int iAttributes = 0;
			if(element.Attributes != null){
				iAttributes = element.Attributes.Count;
				for(int i = 0; i < iAttributes; i++){
					element.RemoveAttributeNode((XmlAttribute)element.Attributes.Item(0));
				}
			}
			return iAttributes;
		}//removeAllAttributes

		/// <summary>
		/// Remove all the child nodes of a parent node with a given name.
		/// </summary>
		/// <param name="parentNode">holds the node for which its child nodes are to be removed.</param>
		/// <param name="childName">holds the name of the children to be removed.</param>
		/// <returns>the number of child nodes removed.</returns>
		public static int removeChildrenByName(XmlNode parentNode, string childName){
			int iChild = 0;
			int iChildrenRemoved = 0;
			while(iChild < parentNode.ChildNodes.Count){
				XmlNode sNode = parentNode.ChildNodes.Item(iChild);
				String sNodeName = sNode.LocalName;
				if(sNodeName != null && sNodeName.Equals(childName)){
					parentNode.RemoveChild(sNode);
					iChildrenRemoved++;
				}
				else{
					iChild++;
				}
			}
			return iChildrenRemoved;
		}//removeChildrenByName

		/// <summary>
		///  Get the text value of a descendant element by the element's name. If there
		///  are multiple elements with the same name, the method always return the value
		///  of the first element.
		/// </summary>
		/// <param name="rootElement">holds the element for which its descendant element is to be found.</param>
		/// <param name="descendantName">holds the name of the descendant to be found.</param>
		/// <returns>the text value of the first descendant element. If none found, a null value is returned.</returns>
		public static string getElementValueByName(XmlElement rootElement, string descendantName){
			String sValue = null;
			XmlNodeList nodeList = rootElement.GetElementsByTagName(descendantName);
			if(nodeList.Count == 0){
				return null;
			}
			else{
				XmlElement eDescendant = (XmlElement)nodeList.Item(0);
				if(eDescendant.FirstChild == null) return "";
				sValue = ((XmlText)eDescendant.FirstChild).Data;
				return sValue;
			}
		}//getElementValueByName

		/// <summary>
		/// Get the value of an element in a string.
		/// </summary>
		/// <param name="element">holds the element for which its value is to be retrieved.</param>
		/// <returns>the value of the element in a string.</returns>
		public static string getElementValue(XmlElement element){
			if(element.FirstChild == null) return null;
			string sValue = ((XmlText)element.FirstChild).Data;
			return sValue;
		}//getElementValue

		/// <summary>
		/// Set the value (i.e. it's text child node) of an element -- &lt;element&gt;value&lt;/element&gt;.
		/// </summary>
		/// <param name="element">holds the element to be set the value.</param>
		/// <param name="value">holds the value to set.</param>
		public static void setElementValue(XmlElement element, string value){
			XmlNodeList nodeList = element.ChildNodes;
			if(nodeList == null || nodeList.Count <= 0){
				element.AppendChild(element.OwnerDocument.CreateTextNode(value));
			}
			else{
				nodeList.Item(0).Value = value;			
			}
		}//setElementValue

		public static XmlElement createOSxLRootElement(XmlDocument document, string osxlName){
			XmlElement eOSxL = document.CreateElement(osxlName);
			eOSxL.SetAttribute("xmlns", OSConstant.OS_NAMESPACE);
			eOSxL.SetAttribute("xmlns:os", OSConstant.OS_NAMESPACE);
			eOSxL.SetAttribute("xmlns:xs", OSConstant.XMLNS_XS_VALUE);
			eOSxL.SetAttribute("xmlns:xsi", OSConstant.XMLNS_XSI_VALUE);
			string sSchemaName = osxlName;
			if(sSchemaName.Length == 4){
				sSchemaName = "OS" + sSchemaName[2] + "L";
			}
			else if(sSchemaName.ToLower().Equals("osparameter")){
				sSchemaName = "OSParameter";
			}
			else if(sSchemaName.ToLower().Equals("osregistry")){
				sSchemaName = "OSRegistry";
			}
			else if(sSchemaName.ToLower().Equals("osrepository")){
				sSchemaName = "OSRepository";
			}
			eOSxL.SetAttribute("schemaLocation", OSConstant.XMLNS_XSI_VALUE, OSConstant.OS_NAMESPACE+" " + OSParameter.OS_SCHEMA_SITE + sSchemaName + ".xsd");
			return eOSxL;
		}//createOSxLRootElement

		/// <summary>
		/// Create the standard xs:dateTime string from the native date/time.
		/// </summary>
		/// <param name="dateTime">calendar holds the native date/time. </param>
		/// <returns>the standard xs:dateTime in a string.</returns>
		public static string createXSDateTime(DateTime dateTime){
			String sXSDateTime = XmlConvert.ToString(dateTime);
			return sXSDateTime;
		}//createXSDateTime

		/// <summary>
		/// Create the the native date/time from the standard xs:dateTime. 
		/// </summary>
		/// <param name="xsDateTime">holds standard xs:dateTime in a string.</param>
		/// <returns>the the native date/time.  </returns>
		public static DateTime createNativeDateTime(String xsDateTime){//TODO
			return XmlConvert.ToDateTime(xsDateTime);
		}//createNativeDateTime
	}//class XMLUtil
}//namespace
