/**
 * @(#)Var 1.0 03/14/2004
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
public class Variable{
	
	public String name = "";
	
	public double init = Double.NaN;
	
	public String initString = "";
	
	public char type = 'C';
	
	public double lb = 0;
	
	public double ub = Double.POSITIVE_INFINITY;

}//class Var
