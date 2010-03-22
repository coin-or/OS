/**
 * @(#)Constraint 1.0 03/14/2004
 *
 * Copyright (c) 2004
 */
package org.optimizationservices.oscommon.datastructure.osinstance;



/**
 *
 * <p>A data structure class that corresponds to an xml element in the OSiL schema.  
 *  
 * </p>
 * @author Robert Fourer, Jun Ma, Kipp Martin
 * @version 1.0, 03/14/2004
 * @since OS 1.0
*/
public class Constraint{
	
	public String name = "";
	
	public double lb = Double.NEGATIVE_INFINITY;
	
	public double ub = Double.POSITIVE_INFINITY;

	public double constant = 0.0;
	
}//class Constraint
