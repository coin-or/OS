/**
 * @(#)BenchmarkHeader 1.0 03/14/2004
 *
 * Copyright (c) 2004
 */
package org.optimizationservices.oscommon.datastructure.osbenchmark;

import java.util.GregorianCalendar;

/**
*
* <p>A data structure class that corresponds to an xml element in the OSbL schema.  
*  
* </p>
* @author Robert Fourer, Jun Ma, Kipp Martin
* @version 1.0, 03/14/2004
* @since OS 1.0
*/
public class BenchmarkHeader {
	
	public String serviceURI = "";

	public String serviceName = "";

	public GregorianCalendar time = null;
	
	public String message = "";

}//BenchmarkHeader
