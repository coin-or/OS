/**
 * @(#)ProcessStatistics 1.0 03/14/2004
 *
 * Copyright (c) 2004
 */
package org.optimizationservices.oscommon.datastructure.osprocess;

import java.util.GregorianCalendar;



/**
 *
 * <p>A data structure class that corresponds to an xml element in the OSpL schema.  
 *  
 * </p>
 * @author Robert Fourer, Jun Ma, Kipp Martin
 * @version 1.0, 03/14/2004
 * @since OS 1.0
*/
public class ProcessStatistics{

	public String currentState = "noResponse";

	public double availableDiskSpace = Double.POSITIVE_INFINITY;
	
	public double availableMemory = Double.POSITIVE_INFINITY;
	
	public int currentJobCount = -1;

	public int totalJobsSoFar = -1;

	public GregorianCalendar timeLastJobEnded = new GregorianCalendar(1970, 0, 1, 0, 0, 0);

	public double timeLastJobTook = Double.NaN;

	public GregorianCalendar timeServiceStarted = new GregorianCalendar(1970, 0, 1, 0, 0, 0);

	public double serviceUtilization = Double.NaN;
	
	public Jobs jobs = null;
		
}//class ProcessStatistics
