/**
 * @(#)OSException 1.0 03/14/2004
 *
 * Copyright (c) 2004
 */
package org.optimizationservices.oscommon.exception;

/**
 *
 * <P>The <code>OSException</code> class is the the parent class of 
 * all the Optimization Services related exception classes. 
 *  
 * </p>
 * @author Robert Fourer, Jun Ma, Kipp Martin
 * @version 1.0, 03/14/2004
 * @since OS 1.0
*/
public abstract class OSException extends Exception {
	/**
	 *
	 * Default constructor. 
	 */
	public OSException(){
	}//constructor
	
    /**
     * Constructs a new exception with the specified detail message.  
     *
     * @param message holds the detail message.
     */
    public OSException(String message) {
    	super(message);
    }//constructor
    
	/**
	 * get exeption id
	 * 
	 * @return exception id
	 */
	public abstract int getExceptionId();
	
	/**
	 * get exception name
	 * 
	 * @return exception name
	 */
	public abstract String getExceptionName();
	
	/**
	 * get exception type
	 * 
	 * @return exception type
	 */
	public abstract int getExceptionType();
	
	/**
	 * main for test purposes.
	 *
	 * </p>
	 *
	 * @param argv command line arguments.
	 */
	public static void main(String[] args){
	}//main
}//class OSException
