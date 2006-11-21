/**
 * @(#)ConstraintSolution 1.0 03/14/2004
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
public class ConstraintSolution {
	
	 public ConstraintValues values = null;
	
	 public DualVariableUnboundedDirections dualUnboundedDirections = null;
	 
	 public ConstraintIrreducibleInconsistentSystem irreducibleInconsistentSystem = null;
	 
	 public DualVariableValues dualValues = null;
	 
	 public ConstraintSlacks slacks = null;
	 
	 public ConstraintAllowableIncreases allowableIncreases = null;
	 
	 public ConstraintAllowableDecreases allowableDecreases = null;
	 
	 public ConstraintOVFunctions ovFunctions = null;
	 
	 public OtherConstraintResult[] other = null;
	
}//ConstraintSolution
