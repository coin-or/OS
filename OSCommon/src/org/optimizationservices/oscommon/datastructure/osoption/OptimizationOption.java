/**
 * @(#)OptimizationOption 1.0 03/14/2004
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
public class OptimizationOption{


	public int numberOfVariables = -1;
	
	public int numberOfObjectives = -1;

    public int numberOfConstraints = -1;
	
	public VariableOption variables = null;
	
	public ObjectiveOption objectives = null;
	
	public ConstraintOption constraints = null;
	
	public SolverOptions solverOptions = null;
	
}//class OptimizationOption
