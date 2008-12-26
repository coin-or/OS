/**
 * @(#)InitObjBound 2.0 11/01/2008
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
* @version 2.0, 11/01/2008
* @since OS 2.0
*/
public class InitObjBound {
	
	public int idx = -1;
	
	public double lbValue = Double.NEGATIVE_INFINITY;

	public double ubValue = Double.POSITIVE_INFINITY;
	
}//InitObjBound

