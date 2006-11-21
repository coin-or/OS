/**
 * @(#)OptimizationInfo 1.0 03/14/2004
 *
 * Copyright (c) 2004
 */
package org.optimizationservices.oscommon.datastructure.osentity;


/**
 *
 * <p>A data structure class that corresponds to an xml element in the OSeL schema.  
 *  
 * </p>
 * @author Robert Fourer, Jun Ma, Kipp Martin
 * @version 1.0, 03/14/2004
 * @since OS 1.0
*/
public class OptimizationInfo{
		
	public String description = "";

	public String variableType = "";

	public String objectiveType = "";

	public String constraintType = "";

	public String objectiveLinearity = "";

	public String constraintLinearity = "";

	public String objectiveDifferentiability = "";

	public String constraintDifferentiability = "";

	public String parameterType = "";

	public String stochasticity = "";

	public boolean realTime = false;
	
	public FunctionType functionType = null;

	public SpecialStructure specialStructure = null;

	public SpecialAlgorithm specialAlgorithm = null;

}//class OptimizationInfo
