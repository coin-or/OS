/**
 * @(#)Time 1.0 03/14/2009
 *
 * Copyright (c) 2009
 */
package org.optimizationservices.oscommon.datastructure.osresult;



/**
*
* <p>A data structure class that corresponds to an xml element in the OSrL schema.  
*  
* </p>
* @author Gus Gassmann, Jun Ma, Kipp Martin
* @version 1.0, 03/14/2009
* @since OS 2.0
*/
public class Time{
	
	public String type = "elapsedTime";

	public String category = "total";

	public String unit = "second";

	public String description = "";
	
	public double value = Double.NaN;

}//class Time
