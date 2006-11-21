/**
 * @(#)OSgLWriter 1.0 03/14/2004
 *
 * Copyright (c) 2004
 */
package org.optimizationservices.oscommon.representationparser;

import org.optimizationservices.oscommon.util.XMLUtil;
import org.w3c.dom.Document;


/**
 * <P>The <code>OSgLWriter</code> class is a general and generic writer class for all the other OSxL writer 
 * classes to extend, which mostly writes a DOM tree of an OSxL instance and provide a set of "set" and "add" 
 * methods that can be used to construct different pieces of information of the OSxL instance.</p>
 * 
 * </p>
 *
 * @author Robert Fourer, Jun Ma, Kipp Martin
 * @version 1.0, 03/14/2004
 * @since OS 1.0
 */
public class OSgLWriter{
	
	/**
	 * m_document holds the W3C DOM type document to create XML elements and attributes.
	 * It is the parent of the root element, e.g. the &lt;OSiL&gt; element in OSiL. It is used
	 * to create all the nodes in the DOM tree.
	 */
	public Document m_document = null;
	
	/**
	 * Constructor.
	 */
	public OSgLWriter(){
		
	}//constructor
	
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
		return XMLUtil.writeXMLDocumentToStandardOutput(m_document);
	}//writeToStandardOutput
	
	/**
	 * Write the xml file from the internally constructed DOM tree structure that contains the
	 * OSxL instance to a string to be returned.
	 *
	 * </p>
	 *
	 * @return a string  that contains the OSiL optimization instance. If error is encountered in writing the string, null is returned.
	 */
	public String writeToString(){
		return XMLUtil.writeXMLDocumentToString(m_document);
	}//writeToString
	
	/**
	 * @param document holds the W3C DOM type document to create XML elements and attributes.
	 * It is the parent of the root element, e.g. the &lt;OSiL&gt; element in OSiL. It is used
	 * to create all the nodes in the DOM tree.
	 */
	public void setDocument(Document document){
		m_document = document;
	}//setDocument
	
	/**
	 * @return the document which holds the W3C DOM type document to create XML elements and attributes.
	 * It is the parent of the root element, e.g. the &lt;OSiL&gt; element in OSiL. It is used
	 * to create all the nodes in the DOM tree.. 
	 */
	public Document getDocument(){
		return m_document;
	}//getDocument
	
	/**
	 * main for test purposes.
	 *
	 * </p>
	 *
	 * @param argv command line arguments.
	 */
	public static void main(String[] argv){
		
	}//main
	
}//class OSgLWriter
