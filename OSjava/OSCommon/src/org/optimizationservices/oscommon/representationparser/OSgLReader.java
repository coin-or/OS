/**
 * @(#)OSgLReader 1.0 03/14/2004
 *
 * Copyright (c) 2004
 */
package org.optimizationservices.oscommon.representationparser;

import org.optimizationservices.oscommon.util.OSParameter;
import org.optimizationservices.oscommon.util.XMLUtil;
import org.w3c.dom.Document;
import org.w3c.dom.Element;


/**
 * <P>The <code>OSgLReader</code> class is a general and generic reader class for all the other OSxL reader classes
 * to extend, which mostly parse an OSxL instance into a DOM tree and
 * provide a set of "get" methods that can be used to retrieve different pieces of information of 
 * the OSxL instance.</p>
 * 
 * </p>
 *
 * @author Robert Fourer, Jun Ma, Kipp Martin
 * @version 1.0, 03/14/2004
 * @since OS 1.0
 */
public class OSgLReader{
	/**
	 * m_sOSxL holds the osxl String or file to be passed. 
	 */
	protected String m_sOSxL = "";

	/**
	 * m_bIsOSxLFile holds whether the osxl string is a file name or a string that literally holds the osxl instance.
	 */
	protected boolean m_bIsOSxLFile = false;
	/**
	 * m_document holds the W3C DOM type document to create XML elements and attributes.
	 * It is the parent of the root element, e.g. the &lt;OSiL&gt; element in OSiL. It is used
	 * to create all the nodes in the DOM tree.
	 */
	public Document m_document = null;

	/**
	 * m_root holds the root node of the parsed OSxL DOM tree.
	 */
	protected Element m_eRoot = null;
	
	/**
	 * bXsdValidate holds whether the parser should be validating against the schema or not.
	 */
	protected boolean m_bXsdValidate = OSParameter.VALIDATE;
	
	/**
	 * Constructor.
	 */
	public OSgLReader(){
		
	}//constructor
	
	/**
	 * constructor
	 *
	 * </p>
	 *
	 * @param validate holds whether the OSgLReader should be validating against the schema or not.
	 */
	public OSgLReader(boolean validate){
		m_bXsdValidate = validate;
	}//constructor

	/**
	 * set document
	 * 
	 * @param document holds the W3C DOM type document to create XML elements and attributes.
	 * It is the parent of the root element, e.g. the &lt;OSiL&gt; element in OSiL. It is used
	 * to create all the nodes in the DOM tree.
	 */
	public void setDocument(Document document){
		m_document = document;
	}//setDocument
	
	/**
	 * get document
	 * @return the document which holds the W3C DOM type document to create XML elements and attributes.
	 * It is the parent of the root element, e.g. the &lt;OSiL&gt; element in OSiL. It is used
	 * to create all the nodes in the DOM tree.
	 */
	public Document getDocument(){
		return m_document;
	}//getDocument

	/**
	 * Set root element
	 * 
	 * @param rootElement holds the root element to be set. 
	 */
	public void setRootElement(Element rootElement){
		m_eRoot = rootElement;
	}//setRootElement
	
	/**
	 * @return the root element. 
	 */
	public Element getRootElement(){
		return m_eRoot;
	}//getRootElement
	
	/**
	 * @return whether the parser should be validating against the schema or not.
	 */
	public boolean isValidate(){
		return m_bXsdValidate;
	}//isValidate
	
	/**
	 * @param xsdValidate holds whether the parser should be validating against the schema or not.
	 */
	public void setValidate(boolean xsdValidate){
		m_bXsdValidate = xsdValidate;
	}//setValidate
	
	/**
	 * Read the xml file that contains the OSxL instance.
	 *
	 * </p>
	 *
	 * @param fileName	holds the xml filename that contains the OSxL instance
	 * @return whether the file is read successfully without any error.
	 */
	public boolean readFile(String fileName){
		m_sOSxL = fileName;
		m_bIsOSxLFile = true;
		Document doc = XMLUtil.parseFileUsingDOM(fileName, m_bXsdValidate);
		if(doc == null){
			return false;
		}
		else{
			m_eRoot = (Element)doc.getDocumentElement();
			return true;
		}
	}//readFile
	
	/**
	 * Read the xml string that contains the OSxL instance.
	 *
	 * </p>
	 *
	 * @param osxlString holds the xml string that contains the OSxL instance
	 * @return whether the string is read successfully without any error.
	 */
	public boolean readString(String osxlString){
		m_sOSxL = osxlString;
		m_bIsOSxLFile = false;
		Document doc = XMLUtil.parseStringUsingDOM(osxlString, m_bXsdValidate);
		if(doc == null){
			return false;
		}
		else{
			m_eRoot = (Element)doc.getDocumentElement();
			return true;
		}
	}//readString
	
	
	/**
	 * Write the xml file from the internally constructed DOM tree structure that contains the
	 * OSxL instance to a file.
	 *
	 * </p>
	 *
	 * @param fileName	holds the xml filename to write out the file to.
	 * @return whether the file is written successfully without any error.
	 */
	public boolean writeToFile(String fileName){
		if(m_document == null) m_document = (Document)m_eRoot.getParentNode();
		return XMLUtil.writeXMLDocumentToFile(m_document, fileName);
	}//writeToFile
	
	/**
	 * Write the xml file from the internally constructed DOM tree structure that contains the
	 * OSxL instance to the standard output (e.g. screen).
	 *
	 * </p>
	 *
	 * @return whether the output is written successfully without any error.
	 */
	public boolean writeToStandardOutput(){
		if(m_document == null) m_document = (Document)m_eRoot.getParentNode();
		return XMLUtil.writeXMLDocumentToStandardOutput(m_document);
	}//writeToStandardOutput
	
	/**
	 * Write the xml file from the internally constructed DOM tree structure that contains the
	 * OSxL instance to a string to be returned.
	 *
	 * </p>
	 *
	 * @return a string  that contains the OSxL optimization instance. If error is encountered in writing the string, null is returned.
	 */
	public String writeToString(){
		if(m_document == null) m_document = (Document)m_eRoot.getParentNode();
		return XMLUtil.writeXMLDocumentToString(m_document);
	}//writeToString
	
	/**
	 * main for test purposes.
	 *
	 * </p>
	 *
	 * @param argv command line arguments.
	 */
	public static void main(String[] argv){
		
	}//main
	
}//class OSgLReader
