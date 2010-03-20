/**
 * @(#)ConstraintOption 1.0 03/14/2004
 *
 * Copyright (c) 2004
 */
package org.optimizationservices.oscommon.datastructure.osoption;


/**
 *
 * <p>A data structure class that corresponds to an xml element in the OSoL schema.  
 *  
 * </p>
 * @author Robert Fourer, Gus Gassmann, Jun Ma, Kipp Martin
 * @version 1.0, 03/14/2004
 * @since OS 1.0
*/
public class ConstraintOption{
	
	public int numberOfOtherConstraintOptions = 0;
	
	public InitialConstraintValues initialConstraintValues = null;

	public InitialDualVariableValues initialDualValues = null;
	
	public OtherConstraintOption[] other = null;

}//class ConstraintOption
