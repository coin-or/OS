/**
 * @(#)AnalysisHeader 1.0 03/14/2004
 *
 * Copyright (c) 2004
 */
package org.optimizationservices.oscommon.datastructure.osanalysis;

import java.util.GregorianCalendar;

/**
*
* <p>A data structure class that corresponds to an xml element in the OSaL schema.  
*  
* </p>
* @author Robert Fourer, Jun Ma, Kipp Martin
* @version 1.0, 03/14/2004
* @since OS 1.0
*/
public class AnalysisHeader {
	
	public AnalysisStatus status = new AnalysisStatus();

	public String serviceURI = "";
	
	public String serviceName = "";

	public String instanceName = "";

	public String jobID = "";

	public GregorianCalendar time = null;
	
	public String message = "";
	
}//AnalysisHeader
