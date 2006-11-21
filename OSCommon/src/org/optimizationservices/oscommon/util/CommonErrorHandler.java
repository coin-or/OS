/**
 * @(#)CommonErrorHandler 1.0 03/14/2004
 *
 * Copyright (c) 2004
 */
package org.optimizationservices.oscommon.util;

import org.xml.sax.ErrorHandler;
import org.xml.sax.SAXException;
import org.xml.sax.SAXParseException;

/**
 *
 * <P>The <code>CommonErrorHandler</code> class is derived from the SAX DefaultHandler
 * class and provides common ways to handle warning, error, and fatalerror. </p>
 *
 * </p>
 *
 * @author  Robert Fourer, Jun Ma, Kipp Martin
 * @version 1.0, 03/14/2004
 * @see org.xml.sax.helpers.DefaultHandler
 * @since   OS1.0
 */

public class CommonErrorHandler implements ErrorHandler{
	/**
	 * m_bWarning holds whether there is warning message in parsing the XML instance.
	 */
	protected boolean m_bWarning = false;
	
	/**
	 * m_bWarning holds whether there is error message in parsing the XML instance.
	 */
	protected boolean m_bError = false;
	
	/**
	 * m_bWarning holds whether there is fatal error message in parsing the XML instance.
	 */
	protected boolean m_bFatalError = false;
	
	/**
	 * errorMessage holds the error message if any. 
	 */
	public String errorMessage = "";
	
	/**
	 * warningMessage holds the warning message if any. 
	 */
	public String warningMessage = "";
	
	/**
	 * Handle notification of a recoverable error.
	 *
	 * <p>This corresponds to the definition of "error" in section 1.2
	 * of the W3C XML 1.0 Recommendation such as a validity constraint.
	 * The implemented behavior is to print the xml style error message
	 * and set the error flag true.</p>
	 *
	 * <p>The SAX parser will continue to provide normal parsing events
	 * after invoking this method: it should still be possible for the
	 * application to process the document through to the end.  If the
	 * application cannot do so, then the parser will report a fatal
	 * error.</p>
	 *
	 * </p>
	 *
	 * @param exception The error information encapsulated in a SAX parse exception.
	 * @exception org.xml.sax.SAXException Any SAX exception, possibly wrapping
	 * another exception.
	 * @see org.xml.sax.SAXParseException
	 * @see org.xml.sax.ErrorHandler#error(org.xml.sax.SAXParseException)
	 */
	public void error(SAXParseException e) throws SAXException{
		String sSaxException = XMLUtil.generateSaxParseExceptionInXML("error", e);
		if(sSaxException.indexOf("Schema error")>=0) return;
		if(sSaxException.indexOf("math")>=0) return;
		System.err.println(sSaxException);
		errorMessage += ("[line: " + e.getLineNumber() + ", column: " + e.getColumnNumber()+"] " + e.getMessage());		
		m_bError = true;
	}//error
	
	/**
	 * Handle notification of a non-recoverable error.
	 *
	 * <p>This corresponds to the definition of "fatal error" in
	 * section 1.2 of the W3C XML 1.0 Recommendation, such as a
	 * well-formedness constraint.The implemented behavior is to
	 * print the xml style error message and set the fatalError flag
	 * true.</p>
	 *
	 * <p>The application will assume that the document is unusable
	 * after the parser has invoked this method, and will continue
	 * (if at all) only for the sake of collecting addition error
	 * messages: in fact, SAX parsers are free to stop reporting any
	 * other events once this method has been invoked.</p>
	 *
	 * </p>
	 *
	 * @param exception The error information encapsulated in a SAX parse exception.
	 * @exception org.xml.sax.SAXException Any SAX exception, possibly wrapping
	 * another exception.
	 * @see org.xml.sax.SAXParseException
	 * @see org.xml.sax.ErrorHandler#fatalError(org.xml.sax.SAXParseException)
	 */
	public void fatalError(SAXParseException e) throws SAXException{
		String sSaxException = XMLUtil.generateSaxParseExceptionInXML("fatalError", e);
		if(sSaxException.indexOf("Schema error")>=0) return;
		if(sSaxException.indexOf("math")>=0) return;
		System.err.println(sSaxException);
		errorMessage += ("[line: " + e.getLineNumber() + ", column: " + e.getColumnNumber()+"] " + e.getMessage());		
		m_bFatalError = true;
	}//fatalError
	
	/**
	 * Handle notification of a warning.
	 *
	 * <p>SAX parsers will use this method to report conditions that
	 * are not errors or fatal errors as defined by the XML 1.0
	 * recommendation.  The implemented behavior is to print
	 * the xml style warning message and set the warning flag true.</p>
	 *
	 * <p>The SAX parser will continue to provide normal parsing events
	 * after invoking this method: it should still be possible for the
	 * application to process the document through to the end.</p>
	 *
	 * </p>
	 *
	 * @param e The warning information encapsulated in a SAX parse exception.
	 * @exception org.xml.sax.SAXException Any SAX exception, possibly
	 * wrapping another exception.
	 * @see org.xml.sax.SAXParseException
	 * @see org.xml.sax.ErrorHandler#warning(org.xml.sax.SAXParseException)
	 */
	public void warning(SAXParseException e) throws SAXException{
		String sSaxException = XMLUtil.generateSaxParseExceptionInXML("warning", e);
		if(sSaxException.indexOf("Schema error")>=0) return;
		if(sSaxException.indexOf("math")>=0) return;
		System.err.println(sSaxException);
		warningMessage += ("[line: " + e.getLineNumber() + ", column: " + e.getColumnNumber()+"] " + e.getMessage());		
		m_bWarning = true;
	}//warning
	
	/**
	 *
	 * @return whether there is an error or fatalError in parsing.
	 */
	public boolean hasError(){
		return (m_bError || m_bFatalError);
	}//hasError
	
	/**
	 *
	 * @return whether there is a warning in parsing.
	 */
	public boolean hasWarning(){
		return m_bWarning;
	}//hasWarning
	
	/**
	 * main for test purposes.
	 *
	 * </p>
	 *
	 * @param argv command line arguments.
	 */
	public static void main(String[] argv){
		
	}//main
	
}//class CommonErrorHandler
