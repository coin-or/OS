/**
 * @(#)OSParameterFile 1.0 05/20/2005
 *
 * Copyright (c) 2005  
 */
package org.optimizationservices.oscommon.util;

import java.io.File;

import javax.servlet.http.HttpServletRequest;

import org.apache.axis.MessageContext;
import org.apache.axis.transport.http.HTTPConstants;
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
	

	/**
	 * @return the parameter file path name the class sets. 
	 */
	public static String setParameterFile(){
		return setParameterFile(null);
	}
	
	/**
	 * @return the parameter file path name the class sets. 
	 */
	public static String setParameterFile(HttpServletRequest httpRequest){
		//automatically detect webapp context
		String SERVICE_FOLDER = "os";		
		
		MessageContext messageContext = MessageContext.getCurrentContext();
		HttpServletRequest request = null;
		if(httpRequest == null){
			request = (HttpServletRequest)messageContext.getProperty(HTTPConstants.MC_HTTP_SERVLETREQUEST);
		}
		else{
			request = httpRequest;
		}
		SERVICE_FOLDER = request.getContextPath();
		if(SERVICE_FOLDER != null && SERVICE_FOLDER.length() > 0)SERVICE_FOLDER = SERVICE_FOLDER.substring(1);
		if(SERVICE_FOLDER == null || SERVICE_FOLDER.length() <= 0) SERVICE_FOLDER = "os";		

		//automatically detect where the tomcat installation is. 
		String sDir = "";
		try {
			File dir = new File (".");
			sDir = dir.getCanonicalPath();
			sDir = sDir.replace('\\', '/');
			if(!sDir.endsWith("/")){
				sDir += "/";
			}
		}
		catch(Exception e) {
			sDir = "/Program Files/Apache Software Foundation/Tomcat 5.5/";
		}
		
		
		
		if(sDir.toLowerCase().endsWith("bin") || 
				sDir.toLowerCase().endsWith("bin\\") ||
				sDir.toLowerCase().endsWith("bin/")){
			int iIndex = sDir.lastIndexOf("bin");
			sDir = sDir.substring(0, iIndex);
		}
		if(!sDir.endsWith("/")){
			sDir += "/";
		}

		NAME = sDir+= "webapps/"+SERVICE_FOLDER+"/WEB-INF/code/OSConfig/OSParameter.xml";
		return NAME;
		
	}//setParameterFile
}//OSParameterFile
