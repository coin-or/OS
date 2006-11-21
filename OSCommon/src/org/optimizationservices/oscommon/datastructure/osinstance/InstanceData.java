/**
 * @(#)InstanceData 1.0 03/14/2004
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
public class InstanceData{
	
	public Variables variables = new Variables();
	
	public Objectives objectives = new Objectives();
	
	public Constraints constraints = new Constraints();
	
	public LinearConstraintCoefficients linearConstraintCoefficients = new LinearConstraintCoefficients();
	
	public QuadraticCoefficients quadraticCoefficients = new QuadraticCoefficients();

	public NonlinearExpressions nonlinearExpressions = new NonlinearExpressions();
	
	public XMLData xmlData = new XMLData();

}//class InstanceData
