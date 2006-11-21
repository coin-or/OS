/**
 * @(#)OSParameterFile 1.0 05/20/2005
 *
 * Copyright (c) 2005  
 */
package org.optimizationservices.oscommon.util;

/**
*
* <P>The <code>OSParameterFile</code> class stores OSParameter file related information.  
*  
*
* </p>
* @author Robert Fourer, Jun Ma, Kipp Martin
* @version 1.0, 03/14/2004
* @since OS 1.0
*/
public final class OSParameterFile {

	/**
	 *
	 * Default constructor. 
	 */
	public OSParameterFile(){
	}//constructor
	
	/**
	 * NAME holds the file name that keeps the parameter information. 
	 */
	public static String NAME = "/code/OSConfig/OSParameter.xml"; //IOUtil.getCurrentDir()+"webapps/os/code/OSParameter.xml"; 
	
}//OSParameterFile
