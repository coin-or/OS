/**
 * @(#)XMLUtil 1.0 03/14/2004
 *
 * Copyright (c) 2004
 */
package org.optimizationservices.oscommon.util;

import java.io.File;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.StringReader;
import java.io.StringWriter;
import java.util.GregorianCalendar;
import java.util.Vector;

import javax.xml.datatype.XMLGregorianCalendar;
import javax.xml.parsers.DocumentBuilderFactory;
import javax.xml.parsers.FactoryConfigurationError;
import javax.xml.parsers.ParserConfigurationException;

import org.apache.xerces.parsers.DOMParser;
import org.apache.xml.serialize.OutputFormat;
import org.apache.xml.serialize.XMLSerializer;
import org.w3c.dom.Attr;
import org.w3c.dom.Document;
import org.w3c.dom.Element;
import org.w3c.dom.Node;
import org.w3c.dom.NodeList;
import org.w3c.dom.Text;
import org.xml.sax.InputSource;
import org.xml.sax.SAXException;
import org.xml.sax.SAXParseException;
import org.xml.sax.XMLReader;
import org.xml.sax.helpers.DefaultHandler;
import org.xml.sax.helpers.XMLReaderFactory;

// FIXME: untested change in import
import org.apache.xerces.jaxp.datatype.DatatypeFactoryImpl;


/**
 *
 * <P>The <code>XMLUtil</code> class contains methods for performing
 * common basic XML-related operations used by various classes in the
 * Optimization Services (OS) framework. </p>
 *
 * </p>
 *
 * @author  Robert Fourer, Jun Ma, Kipp Martin
 * @version 1.0, 03/14/2004
 * @since   OS1.0
 */

public class XMLUtil {
	/**
	 * Returns the SAX Exception in the following XML format:
	 * <p>
	 * <p>&lt;parse_exceptionType&gt;
	 * <p>&lt;file&gt; ... &lt;/file&gt;
	 * <p>&lt;line&gt;...&lt;/line&gt;
	 * <p>&lt;column&gt;...&lt;/column&gt;
	 * <p>&lt;message&gt;...&lt;/message&gt;
	 * <p>&lt;/parse_exceptionType&gt;.
	 * </p>
	 *
	 * </p>
	 *
	 * @param   exceptionType   e.g. "warning", "error", "fatalError".
	 */
	public static String generateSaxParseExceptionInXML(String exceptionType, SAXParseException e){
		String sSaxException = "<parse_"+exceptionType+">"
		+"\n\t<file>\n\t\t"
		+e.getSystemId()
		+"\n\t</file>"
		+"\n\t<line>"+e.getLineNumber()+"</line>"
		+"\n\t<column>"+e.getColumnNumber()+"</column>"
		+"\n\t<message>\n\t\t"
		+e.getMessage()
		+"\n\t</message>"
		+"\n</parse_"+exceptionType+">";
		return sSaxException;
	}//printSaxParseException
	
	/**
	 * Parse the xml file that contains the xml instance using SAX.
	 *
	 * </p>
	 *
	 * @param fileName	holds the name of the file that contains the xml instance
	 * @param saxHandler is a user implementation of the core sax handlers.
	 * @param validate holds whether the parser should be validating against the xml schema or not.
	 * @return whether the file is read successfully without any error.
	 */
	public static boolean parseFileUsingSAX(String fileName, DefaultHandler saxHandler, boolean validate){
		try {
			//use Xerces parser.
			XMLReader saxParser = XMLReaderFactory.createXMLReader(OSConstant.SAX_PARSER_XERCES);
			saxParser.setFeature(OSConstant.SAX_VALIDATION_FEATURE, validate);
			saxParser.setFeature(OSConstant.SCHEMA_FEATURE, validate);
			saxParser.setContentHandler(saxHandler);
			saxParser.setErrorHandler(saxHandler);
			saxParser.parse(fileName);
			return true;
		}
		catch(IOException e) {
			e.printStackTrace();
			return false;
		}
		catch(SAXException e) {
			e.printStackTrace();
			return false;
		}
		catch(Exception e){
			e.printStackTrace();
			return false;
		}
	}//parseFileUsingSAX
	
	/**
	 * Parse the xml string that contains the xml instance using SAX.
	 *
	 * </p>
	 *
	 * @param xmlString	holds the xml string that contains the xml instance
	 * @param saxHandler is a user implementation of the core sax handlers.
	 * @param validate holds whether the parser should be validating against the xml schema or not.
	 * @return whether the string is parsed successfully without any error.
	 */
	public static boolean parseStringUsingSAX(String xmlString, DefaultHandler saxHandler, boolean validate){
		try {
			//use Xerces parser.
			XMLReader saxParser = XMLReaderFactory.createXMLReader(OSConstant.SAX_PARSER_XERCES);
			saxParser.setFeature(OSConstant.SAX_VALIDATION_FEATURE, validate);
			saxParser.setFeature(OSConstant.SCHEMA_FEATURE, validate);
			saxParser.setContentHandler(saxHandler);
			saxParser.setErrorHandler(saxHandler);
			saxParser.parse(new InputSource(IOUtil.stringToInputStream(xmlString)));
			return true;
		}
		catch(IOException e) {
			e.printStackTrace();
			return false;
		}
		catch(SAXException e) {
			e.printStackTrace();
			return false;
		}
		catch(Exception e){
			e.printStackTrace();
			return false;
		}
	}//parseStringUsingSAX
	
	/**
	 * Parse the xml file that contains the xml instance using DOM.
	 *
	 * </p>
	 *
	 * @param fileName	holds the name of the file that contains the xml instance.
	 * @param validate holds whether the parser should be validating against the xml schema or not.
	 * @return xml file in a DOM document. If there is error, return null.
	 */
	public static Document parseFileUsingDOM(String fileName, boolean validate){
		try {
			DOMParser parser = new DOMParser();
			CommonErrorHandler commonErrorHandler = new CommonErrorHandler();
			parser.setFeature(OSConstant.SAX_VALIDATION_FEATURE, validate);
			parser.setFeature(OSConstant.SCHEMA_FEATURE, validate);
			parser.setErrorHandler(commonErrorHandler);
			parser.parse(fileName);
			Document doc = parser.getDocument();
			if(commonErrorHandler.hasError()){
				return null;
			}
			return doc;
		}
		catch(SAXException e) {
			e.printStackTrace();
			return null;
		}
		catch(IOException e) {
			e.printStackTrace();
			return null;
		}
		catch(Exception e){
			e.printStackTrace();
			return null;
		}
	}//parseFileUsingDOM
	
	/**
	 * Parse the xml string that contains the xml instance using DOM.
	 *
	 * </p>
	 *
	 * @param xmlString	holds the xml string that contains the xml instance.
	 * @param validate holds whether the parser should be validating against the xml schema or not.
	 * @return xml string in a DOM document. If there is error, return null.
	 */
	public static Document parseStringUsingDOM(String xmlString, boolean validate){
		try {
			DOMParser parser = new DOMParser();
			CommonErrorHandler commonErrorHandler = new CommonErrorHandler();
			parser.setFeature(OSConstant.SAX_VALIDATION_FEATURE, validate);
			parser.setFeature(OSConstant.SCHEMA_FEATURE, validate);
			parser.setErrorHandler(commonErrorHandler);
			InputSource is = new InputSource(new StringReader(xmlString));
			parser.parse(is);
			Document doc = parser.getDocument();
			if(commonErrorHandler.hasError()){
				return null;
			}
			return doc;
		}
		catch(SAXException e) {
			e.printStackTrace();
			return null;
		}
		catch(IOException e) {
			e.printStackTrace();
			return null;
		}
		catch(Exception e){
			e.printStackTrace();
			return null;
		}
	}//parseStringUsingDOM
	
	/**
	 * Obtain a new instance of a DOM {@link org.w3c.dom.Document} object
	 * to build a DOM tree with.  An alternative way to create a DOM
	 * Document object is to use the
	 * {@link #getDOMImplementation() getDOMImplementation}
	 * method to get a DOM Level 2 DOMImplementation object and then use
	 * DOM Level 2 methods on that object to create a DOM Document object.
	 *
	 * @return A new instance of a DOM Document object. Return null if an error occurs.
	 */
	public static Document createNewDocument(){
		Document document = null;
		try {
			document = DocumentBuilderFactory.newInstance().newDocumentBuilder().newDocument();
			return document;
		}
		catch(ParserConfigurationException e){
			e.printStackTrace();
			return null;
		}
		catch(FactoryConfigurationError e){
			e.printStackTrace();
			return null;
		}
		catch(Exception e){
			e.printStackTrace();
			return null;
		}
	}//createNewDocument
	
	/**
	 * Write an xml file from a DOM tree document to a file.
	 *
	 * </p>
	 *
	 * @param xmlDocument holds the xml document to write out to a file.
	 * @param fileName	holds the xml filename to write out the file to.
	 * @return whether the file is written successfully without any error.
	 */
	public static boolean writeXMLDocumentToFile(Document xmlDocument, String fileName){
		try{
			OutputFormat outputFormat  = new OutputFormat(xmlDocument);
			outputFormat.setIndenting(OSParameter.XML_INDENTING);
			StringWriter  stringWriter = new StringWriter();
			XMLSerializer xmlSerializer = new XMLSerializer(stringWriter, outputFormat);
			xmlSerializer.asDOMSerializer();
			File file = new File(fileName);
			FileOutputStream fos = new FileOutputStream(file);
			xmlSerializer.setOutputByteStream(fos);
			xmlSerializer.serialize(xmlDocument);
			fos.close();
			return true;
		}
		catch(Exception e){
			e.printStackTrace();
			return false;
		}
	}//writeXMLDocumentToFile
	
	/**
	 * Write an xml file from a DOM tree document to the standard output (e.g. screen)..
	 *
	 * </p>
	 *
	 * @param xmlDocument holds the xml document to write out to the standard output.
	 * @return whether the file is written successfully without any error.
	 */
	public static boolean writeXMLDocumentToStandardOutput(Document xmlDocument){
		try{
			OutputFormat outputFormat  = new OutputFormat(xmlDocument);
			outputFormat.setIndenting(OSParameter.XML_INDENTING);
			StringWriter  stringWriter = new StringWriter();
			XMLSerializer xmlSerializer = new XMLSerializer(stringWriter, outputFormat);
			xmlSerializer.asDOMSerializer();
			xmlSerializer.setOutputByteStream(System.out);
			xmlSerializer.serialize(xmlDocument);
			return true;
		}
		catch(Exception e){
			e.printStackTrace();
			return false;
		}
	}//writeXMLDocumentToStandardOutput
	
	/**
	 * Write an xml file from a DOM tree document to a string.
	 *
	 * </p>
	 *
	 * @param xmlDocument holds the xml document to write out to the String.
	 * @return a string  that contains the xml. If error is encountered in writing the string, null is returned.
	 */
	public static String writeXMLDocumentToString(Document xmlDocument){
		String sOut = "";
		try{
			OutputFormat outputFormat  = new OutputFormat( xmlDocument );
			outputFormat.setIndenting(OSParameter.XML_INDENTING);
			StringWriter stringWriter = new StringWriter();
			XMLSerializer xmlSerializer = new XMLSerializer(stringWriter, outputFormat );
			xmlSerializer.asDOMSerializer();
			xmlSerializer.serialize( xmlDocument);
			sOut = stringWriter.toString();
			return sOut;
		}
		catch(Exception e){
			e.printStackTrace();
			return null;
		}
	}//writeXMLDocumentToString
	/**
	 * Write DOM tree element to a file.
	 *
	 * </p>
	 *
	 * @param element holds the xml element to write out to a file.
	 * @param fileName holds the xml filename to write out the file to.
	 * @return whether the file is written successfully without any error.
	 */
	public static boolean writeXMLElementToFile(Element element, String fileName){
		try{
			OutputFormat outputFormat  = new OutputFormat();
			outputFormat.setIndenting(OSParameter.XML_INDENTING);
			StringWriter  stringWriter = new StringWriter();
			XMLSerializer xmlSerializer = new XMLSerializer(stringWriter, outputFormat);
			xmlSerializer.asDOMSerializer();
			File file = new File(fileName);
			FileOutputStream fos = new FileOutputStream(file);
			xmlSerializer.setOutputByteStream(fos);
			xmlSerializer.serialize(element);
			fos.close();
			return true;
		}
		catch(Exception e){
			e.printStackTrace();
			return false;
		}
	}//writeXMLElementToFile
	
	/**
	 * Write DOM tree element to the standard output (e.g. screen)..
	 *
	 * </p>
	 *
	 * @param element holds the xml element to write out to the standard output.
	 * @return whether the file is written successfully without any error.
	 */
	public static boolean writeXMLElementToStandardOutput(Element element){
		try{
			OutputFormat outputFormat  = new OutputFormat();
			outputFormat.setIndenting(OSParameter.XML_INDENTING);
			StringWriter  stringWriter = new StringWriter();
			XMLSerializer xmlSerializer = new XMLSerializer(stringWriter, outputFormat);
			xmlSerializer.asDOMSerializer();
			xmlSerializer.setOutputByteStream(System.out);
			xmlSerializer.serialize(element);
			return true;
		}
		catch(Exception e){
			e.printStackTrace();
			return false;
		}
	}//writeXMLElementToStandardOutput
	
	/**
	 * Write an xml file from a DOM tree document to a string.
	 *
	 * </p>
	 *
	 * @param element holds the xml element to write out to the String.
	 * @return a string  that contains the xml. If error is encountered in writing the string, null is returned.
	 */
	public static String writeXMLElementToString(Element element){
		String sOut = "";
		try{
			OutputFormat outputFormat  = new OutputFormat();
			outputFormat.setIndenting(OSParameter.XML_INDENTING);
			StringWriter stringWriter = new StringWriter();
			XMLSerializer xmlSerializer = new XMLSerializer(stringWriter, outputFormat );
			xmlSerializer.asDOMSerializer();
			xmlSerializer.serialize(element);
			sOut = stringWriter.toString();
			return sOut;
		}
		catch(Exception e){
			e.printStackTrace();
			return null;
		}
	}//writeXMLElementToString
	
	/**
	 * Find a parent node's first child node by the child node's name.
	 *
	 * <p/>
	 *
	 * @param parentNode holds the parent node.
	 * @param childNodeName holds the name of the child node to find.
	 * @return the first child node if found, otherwise null.
	 */
	public static Node findChildNode(Node parentNode, String childNodeName){
		if(parentNode == null){
			return null;
		}
		NodeList childNodes = parentNode.getChildNodes();
		if(childNodes == null) return null;
		for(int i = 0; i < childNodes.getLength(); i++){
			if(childNodes.item(i).getNodeName().equals(childNodeName)){
				return childNodes.item(i);
			}
		}
		return null;
	}//findChildNode
	
	/**
	 * Get a parent node's child elements by the child node's tag name.
	 *
	 * <p/>
	 *
	 * @param parentNode holds the parent node.
	 * @param childNodeName holds the name of the children node to find.
	 * @return a vector of child elements that mathces the name.
	 */
	public static Vector<Element> getChildElementsByTagName(Node parentNode, String childNodeName){
		Vector<Element> vElement = new Vector<Element>();
		if(parentNode == null){
			return vElement;
		}
		NodeList childNodes = parentNode.getChildNodes();
		for(int i = 0; i < childNodes.getLength(); i++){
			if(childNodes.item(i).getNodeName().equals(childNodeName)){
				vElement.add((Element)childNodes.item(i));
			}
		}
		return vElement;
	}//getChildElementsByTagName
	
	/**
	 * Remove all the child nodes of a parent node.
	 *
	 * @param parentNode holds the node for which its child nodes are to be removed.
	 * @return the number of child nodes removed.
	 */
	public static int removeAllChildren(Node parentNode){
		int iChildren = 0;
		if(parentNode == null){
			return iChildren;
		}
		if(parentNode.getChildNodes() != null){
			iChildren = parentNode.getChildNodes().getLength();
			for(int i = 0; i < iChildren; i++){
				parentNode.removeChild(parentNode.getChildNodes().item(0));
			}
		}
		return iChildren;
	}//removeAllChildren

	/**
	 * Remove all the attributes of an element.
	 *
	 * @param element holds the element for which its attributes are to be removed.
	 * @return the number of attributes removed.
	 */
	public static int removeAllAttributes(Element element){
		int iAttributes = 0;
		if(element.getAttributes() != null){
			iAttributes = element.getAttributes().getLength();
			for(int i = 0; i < iAttributes; i++){
				element.removeAttributeNode((Attr)element.getAttributes().item(0));
			}
		}
		return iAttributes;
	}//removeAllAttributes

	/**
	 * Remove all the child nodes of a parent node with a given name.
	 *
	 * @param parentNode holds the node for which its child nodes are to be removed.
	 * @param childName holds the name of the children to be removed.
	 * @return the number of child nodes removed.
	 */
	public static int removeChildrenByName(Node parentNode, String childName){
		int iChild = 0;
		int iChildrenRemoved = 0;
		if(parentNode == null){
			return iChildrenRemoved;
		}
		while(iChild < parentNode.getChildNodes().getLength()){
			Node sNode = parentNode.getChildNodes().item(iChild);
			String sNodeName = sNode.getNodeName();
			if(sNodeName != null && sNodeName.equals(childName)){
				parentNode.removeChild(sNode);
				iChildrenRemoved++;
			}
			else{
				iChild++;
			}
		}
		return iChildrenRemoved;
	}//removeChildrenByName
	
	/**
	 * Get the text value of a descendant element by the element's name. If there
	 * are multiple elements with the same name, the method always return the value
	 * of the first element.
	 *
	 * @param rootElement holds the element for which its descendant element is to be found.
	 * @param descendantName holds the name of the descendant to be found.
	 * @return the text value of the first descendant element. If none found, a null value is returned.
	 */
	public static String getElementValueByName(Element rootElement, String descendantName){
		if(rootElement == null) return null;
		String sValue = null;
		NodeList nodeList = rootElement.getElementsByTagName(descendantName);
		if(nodeList.getLength() == 0){
			return null;
		}
		else{
			Element eDescendant = (Element)nodeList.item(0);
			if(eDescendant.getFirstChild() == null) return "";
			sValue = ((Text)eDescendant.getFirstChild()).getData();
			return sValue;
		}
	}//getElementValueByName
	
	/**
	 * Get the value of an element in a string.
	 *
	 * @param element holds the element for which its value is to be retrieved.
	 * @return the value of the element in a string.
	 */
	public static String getElementValue(Element element){
		if(element.getFirstChild() == null) return null;
		String sValue = ((Text)element.getFirstChild()).getData();
		return sValue;
	}//getElementValue
	
	/**
	 * Set the value (i.e. it's text child node) of an element -- &lt;element&gt;value&lt;/element&gt;.
	 *
	 * @param element holds the element to be set the value.
	 * @param value holds the value to set.
	 */
	public static void setElementValue(Element element, String value){
		NodeList nodeList = element.getChildNodes();
		if(nodeList == null || nodeList.getLength() <= 0){
			element.appendChild(element.getOwnerDocument().createTextNode(value));
		}
		else{
			nodeList.item(0).setNodeValue(value);			
		}
	}//setElementValue
	
	/**
	 * Create the basic OSxL root element.
	 *
	 * @param document holds the W3C DOM type document to create XML elements and attributes.
	 * It is the parent of the OSxL root element, e.g. the &lt;OSiL&gt; element in OSiL. It is used
	 * to create all the nodes in the DOM tree.
	 * @param osxlName holds the OSxL name used to create the root element.
	 * @return the OSxL root element.
	 */
	public static Element createOSxLRootElement(Document document, String osxlName){
		Element eOSxL = document.createElement(osxlName);
		eOSxL.setAttribute("xmlns", OSConstant.OS_NAMESPACE);
		eOSxL.setAttribute("xmlns:os", OSConstant.OS_NAMESPACE);
		eOSxL.setAttribute("xmlns:xs", OSConstant.XMLNS_XS_VALUE);
		eOSxL.setAttribute("xmlns:xsi", OSConstant.XMLNS_XSI_VALUE);
		String sSchemaName = osxlName;
		if(sSchemaName.length() == 4){
			sSchemaName = "OS" + sSchemaName.charAt(2) + "L";
		}
		else if(sSchemaName.equalsIgnoreCase("osparameter")){
			sSchemaName = "OSParameter";
		}
		else if(sSchemaName.equalsIgnoreCase("osregistry")){
			sSchemaName = "OSRegistry";
		}
		else if(sSchemaName.equalsIgnoreCase("osrepository")){
			sSchemaName = "OSRepository";
		}
		eOSxL.setAttribute("xsi:schemaLocation", OSConstant.OS_NAMESPACE+" " + OSParameter.OS_SCHEMA_SITE + "2.0/" +sSchemaName + ".xsd");
		return eOSxL;
	}//createOSxLRootElement
	
	
	/**
	 * Create the standard xs:dateTime string from the native date/time
	 * @param dateTime holds the native date/time. 
	 * 
	 * @return the standard xs:dateTime in a string. 
	 */
	public static String createXSDateTime(GregorianCalendar dateTime){//TODO
		if(dateTime == null) dateTime = new GregorianCalendar();
		DatatypeFactoryImpl datatypeFactoryImpl = new DatatypeFactoryImpl();
		XMLGregorianCalendar xmlGregorianCalendar = datatypeFactoryImpl.newXMLGregorianCalendar(dateTime);
		String sXSDateTime = xmlGregorianCalendar.toXMLFormat();
		return sXSDateTime; 
	}//createXSDateTime
	
	/**
	 * Create the the native date/time from the standard xs:dateTime. 
	 * @param xsDateTime holds standard xs:dateTime in a string.
	 * 
	 * @return the the native date/time (gregorian calendar).  
	 */
	public static GregorianCalendar createNativeDateTime(String xsDateTime){
		DatatypeFactoryImpl datatypeFactoryImpl = new DatatypeFactoryImpl();
		XMLGregorianCalendar xmlGregorianCalendar = datatypeFactoryImpl.newXMLGregorianCalendar(xsDateTime);
		return xmlGregorianCalendar.toGregorianCalendar();
	}//createNativeDateTime
	
	/**
	 * main for test purposes.
	 *
	 * </p>
	 *
	 * @param argv command line arguments.
	 */
	public static void main(String[] args) {
		System.out.println(createXSDateTime(null));
		System.out.println(createNativeDateTime("2005-11-28T12:28:39.437-06:00").getTime());
	}//main
	
}//class XMLUtil
