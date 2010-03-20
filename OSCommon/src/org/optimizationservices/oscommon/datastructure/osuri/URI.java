/**
 * @(#)URI 1.0 03/14/2004
 *
 * Copyright (c) 2004
 */
package org.optimizationservices.oscommon.datastructure.osuri;



/**
 *
 * <p>A data structure class that corresponds to an xml element in the OSqL schema.  
 *  
 * </p>
 * @author Robert Fourer, Jun Ma, Kipp Martin
 * @version 1.0, 03/14/2004
 * @since OS 1.0
*/
public class URI{
	
	public String serviceName = "";
	
	public String matchType = "exact";
	
	public boolean licenseRequired = false;
	
	public boolean userNameRequired = false;
	
	public boolean passwordRequired = false;

	public String value = "";
	
}//class URI
