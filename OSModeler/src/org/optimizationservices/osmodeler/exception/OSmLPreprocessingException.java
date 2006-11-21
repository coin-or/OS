/**
 * @(#)OSilReadingException 1.0 05/20/2005
 *
 * Copyright (c) 2005 Impact 
 */
package org.optimizationservices.osmodeler.exception;

import org.optimizationservices.oscommon.exception.OSException;
import org.optimizationservices.oscommon.util.OSConstant;

/**
*
* <P>The <code>OSilReadingException</code> class [fill in]... 
*  
* @author Jun Ma, Sanjay Mehrotra, Huanyuan Sheng
* @version 1.0, 05/24/2005
* @since Impact1.0
*/
public class OSmLPreprocessingException extends OSException{

	/**
	 * The serializable class ImpactInfeasibleException needs to declare a static final 
	 * serialVersionUID field of type long. 
	 */
	private static final long serialVersionUID = 9078830378288899040L;

	/**
	 *
	 * Default constructor. 
	 */
	public OSmLPreprocessingException(){
	}//constructor
	
    /**
     * Constructs a new exception with the specified detail message.  
     *
     * @param message holds the detail message.
     */
    public OSmLPreprocessingException(String message) {
    	super(message);
    }//constructor
	
	/**
	 * 
	 */
	private int m_iExceptionId = 2001;

	/**
	 * 
	 */
	private String m_sExceptionName = "Impact Parsing Exception";

	/**
	 * 
	 */
	private int m_iExceptionType = OSConstant.ERROR;

	/**
	 * 
	 */
	public int getExceptionId() {
		return m_iExceptionId;
	}//getExceptionId
	
	/**
	 * 
	 */
	public String getExceptionName() {
		return m_sExceptionName;
	}//getExceptionName
	
	/**
	 * 
	 */
	public int getExceptionType() {
		return m_iExceptionType;
	}//getExceptionType

	/**
	 * main for test purposes.
	 *
	 * </p>
	 *
	 * @param argv command line arguments.
	 */
	public static void main(String[] args){
	}//main
	
}//class OSilReadingException
