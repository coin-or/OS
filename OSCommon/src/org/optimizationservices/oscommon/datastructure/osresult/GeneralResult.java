/**
 * @(#)GeneralOption 1.0 03/14/2004
 *
 * Copyright (c) 2004
 */
package org.optimizationservices.oscommon.datastructure.osresult;


/**
 *
 * <p>A data structure class that corresponds to an xml element in the OSoL schema.  
 *  
 * </p>
 * @author Robert Fourer, Gus Gassmann, Jun Ma, Kipp Martin
 * @version 1.0, 03/14/2004
 * @since OS 1.0
*/
public class GeneralResult{
	
	public String serviceURI = "";

	public String serviceName = "";

	public String instanceName = "";
	
	public InstanceLocationOption instanceLocation = null;
	
	public String jobID = "";

	public String solverToInvoke = "";
	
	public String license = "";
	
	public String userName = "";
	
	public String password = "";
	
	public ContactOption contact = null;
	
	public OtherOptions otherOptions = null;
	
}//class GeneralOption
