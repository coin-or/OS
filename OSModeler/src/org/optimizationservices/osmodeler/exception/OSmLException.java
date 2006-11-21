/**
 * @(#)OSmLException 1.0 03/14/2004
 *
 * Copyright (c) 2004
 */

package org.optimizationservices.osmodeler.exception;

import org.optimizationservices.oscommon.exception.OSException;

/**
*
* <P>The <code>OSmLException</code> class is the the parent class of 
* all the OSmL modeling language environment related exception classes.  
 * </p>
 *
 * @author Robert Fourer, Jun Ma, Kipp Martin
 * @version 1.0, 03/14/2004
 * @see org.optimizationservices.osmodeler.parser.OSmLGUI
 * @since OS 1.0
 */
public abstract class OSmLException extends OSException {
	/**
	 *
	 * Default constructor. 
	 */
	public OSmLException(){
	}//constructor
	
	/**
	 * main for test purposes.
	 *
	 * </p>
	 *
	 * @param argv command line arguments.
	 */
	public static void main(String[] args){
		
	}//main
}//class OSmLException
