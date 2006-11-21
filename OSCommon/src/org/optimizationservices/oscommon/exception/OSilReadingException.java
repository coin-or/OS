/**
 * @(#)OSiLReadingException 1.0 03/14/2004
 *
 * Copyright (c) 2004
 */
package org.optimizationservices.oscommon.exception;

import org.optimizationservices.oscommon.util.OSConstant;

/**
*
* <P>The <code>OSilReadingException</code> class is any exception when reading the OSiL instance. 
*  
* <P>The <code>OSException</code> class is the the parent class of 
* all the Optimization Services related exception classes. 
*  
 * </p>
 * @author Robert Fourer, Jun Ma, Kipp Martin
 * @version 1.0, 03/14/2004
 * @since OS 1.0
*/
public class OSilReadingException extends OSException{

	/**
	 * The serializable class OSilReadingException needs to declare a static final 
	 * serialVersionUID field of type long. 
	 */
	private static final long serialVersionUID = 7071136854188993340L;

	/**
	 *
	 * Default constructor. 
	 */
	public OSilReadingException(){
	}//constructor
	
    /**
     * Constructs a new exception with the specified detail message.  
     *
     * @param message holds the detail message.
     */
    public OSilReadingException(String message) {
    	super(message);
    }//constructor
	
	/**
	 * m_iExceptionId holds the exception id
	 */
	private int m_iExceptionId = 2001;

	/**
	 * m_sExceptionName holds the exception name
	 */
	private String m_sExceptionName = "OSiL Reading Exception";

	/**
	 * m_iExceptionType holds the exception type
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
