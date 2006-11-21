/**
 * @(#)VariableSolution 1.0 03/14/2004
 *
 * Copyright (c) 2004
 */
package org.optimizationservices.oscommon.datastructure.osresult;

/**
*
* <p>A data structure class that corresponds to an xml element in the OSrL schema.  
*  
* </p>
* @author Robert Fourer, Jun Ma, Kipp Martin
* @version 1.0, 03/14/2004
* @since OS 1.0
*/
public class VariableSolution {
		
	public VariableValues values = null;
	
	public VariableStringValues valuesString = null;

	public PrimalVariableUnboundedDirections primalUnboundedDirections = null;

	public VariableIrreducibleInconsistentSystem irreducibleInconsistentSystem = null;

	public ReducedCosts reducedCosts = null;

	public VariableSlacks slacks = null;

	public VariableAllowableIncreases allowableIncreases = null;

	public VariableAllowableDecreases allowableDecreases = null;

	public VariableOVFunctions ovFunctions = null;

	public OtherVariableResult other[] = null;
	
}//VariableSolution
