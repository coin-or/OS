/**
 * @(#)OtherObjectiveOption 2.0 11/01/2008
 *
 * Copyright (c) 2008
 */
package org.optimizationservices.oscommon.datastructure.osoption;

/**
*
* <p>A data structure class that corresponds to an xml element in the OSoL schema.  
*  
* </p>
* @author Gus Gassmann, Jun Ma, Kipp Martin
* @version 1.0, 11/01/2008
* @since OS 2.0
*/
public class OtherObjectiveOption {
	
	public int numberOfObj = 0;
	
	public String name = "";

	public String value = "";

	public String solver = "";

	public String category = "";

	public String type = "string";

	public String description = "";	
	
	public OtherObjOption[] obj = null;
	
}//OtherObjectiveOption

