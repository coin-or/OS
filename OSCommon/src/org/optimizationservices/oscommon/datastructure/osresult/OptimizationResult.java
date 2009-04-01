/**
 * @(#)OptimizationOption 1.0 03/14/20090
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
public class OptimizationResult{


	public int numberOfVariables = -1;
	
	public int numberOfObjectives = -1;

    public int numberOfConstraints = -1;
	
	public VariableOption variables = null;
	
	public ObjectiveOption objectives = null;
	
	public ConstraintOption constraints = null;
	
	public SolverOptions solverOptions = null;
	
}//class OptimizationResult
