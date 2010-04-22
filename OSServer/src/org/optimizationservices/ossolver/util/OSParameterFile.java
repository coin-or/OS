/**
 * @(#)OSParameterFile 1.0 05/20/2005
 *
 * Copyright (c) 2005  
 */
package org.optimizationservices.ossolver.util;

import javax.servlet.http.HttpServletRequest;

import org.apache.axis.MessageContext;
import org.apache.axis.transport.http.HTTPConstants;
import org.optimizationservices.oscommon.util.OSParameter;

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
	public static String NAME = "/code/OSConfig/OSParameter.xml"; 
	

	/**
	 * @return the parameter file path name the class sets. 
	 */
	public static String setParameterFile(){
		MessageContext messageContext = MessageContext.getCurrentContext();
		HttpServletRequest request = (HttpServletRequest)messageContext.getProperty(HTTPConstants.MC_HTTP_SERVLETREQUEST);
		return setParameterFile(request);
	}
	
	/**
	 * @return the parameter file path name the class sets. 
	 */
	public static String setParameterFile(HttpServletRequest httpRequest){
		OSParameter.SERVICE_FOLDER = httpRequest.getRealPath("/");
		NAME = OSParameter.SERVICE_FOLDER + "/WEB-INF/code/OSConfig/OSParameter.xml";
		return NAME;
		
	}//setParameterFile
	
}//OSParameterFile
