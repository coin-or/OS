/**
 * @(#)ServiceOption 1.0 03/14/2009
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
public class ServiceResult{
	
	public String currentState = "unknown";
	
	public int currentJobCount = -1;
	
	public int totalJobsSoFar = -1;
	
	public GregorianCalendar timeServiceStarted = new GregorianCalendar(1970, 0, 1, 0, 0, 0);
	
	public double serviceUtilization = -1.0;
	
	public OtherResults otherResults = null;
	
}//class ServiceResult
