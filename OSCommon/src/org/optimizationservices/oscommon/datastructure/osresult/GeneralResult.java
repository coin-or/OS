/**
 * @(#)GeneralResult 1.0 03/14/2009
 *
 * Copyright (c) 2009
 */
package org.optimizationservices.oscommon.datastructure.osresult;

import java.util.GregorianCalendar;


/**
 *
 * <p>A data structure class that corresponds to an xml element in the OSrL schema.  
 *  
 * </p>
 * @author Gus Gassmann, Jun Ma, Kipp Martin
 * @version 1.0, 03/14/2009
 * @since OS 2.0
*/
public class GeneralResult{
	
	public GeneralStatus generalStatus = null;
	
	public String message = "";

	public String serviceURI = "";

	public String serviceName = "";

	public String instanceName = "";
	
	public String jobID = "";

	public String solverInvoked = "";

	public GregorianCalendar timeStamp = null;
	
	public OtherResults otherOptions = null;
	
}//class GeneralGeneral
