/**
 * @(#)OSfLReader 1.0 03/14/2004
 *
 * Copyright (c) 2004
 */
package org.optimizationservices.oscommon.representationparser;

/**
 * The <c>OSfLReader</c> class parses an OSfL instance into a DOM tree and
 * provides a set of "get" methods that can be used to retrieve different 
 * pieces of information of the instance.
 * </p>
 *
 * @author Robert Fourer, Jun Ma, Kipp Martin
 * @version 1.0, 03/14/2004
 * @since OS 1.0
 */
public class OSfLReader extends OSgLReader{
	/**
	 * constructor
	 *
	 * </p>
	 *
	 * @param validate holds whether the reader should be validating against the schema or not.
	 */
	public OSfLReader(boolean validate){
		m_bXsdValidate = validate;
	}//constructor
	
	/**
	 * Constructor.
	 */
	public OSfLReader(){
		
	}//constructor
	
	/**
	 * main for test purposes.
	 *
	 * </p>
	 *
	 * @param argv command line arguments.
	 */
	public static void main(String[] argv){
		
	}//main
	
}//class OSfLReader
