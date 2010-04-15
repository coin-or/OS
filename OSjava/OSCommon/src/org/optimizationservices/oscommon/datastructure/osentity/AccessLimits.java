/**
 * @(#)AccessLimits 1.0 03/14/2004
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
public class AccessLimits {
	
	public double maxDiskSpace = Double.POSITIVE_INFINITY;

	public double maxMemory = Double.POSITIVE_INFINITY;

	public int maxJobs = -1;
	
	public int maxVariables = -1;

	public int maxBinaryVariables = -1;

	public int maxIntegerVariables = -1;

	public int maxObjectives = -1;

	public int maxConstraints = -1;

	public int maxNonzeroLinearConstraintCoefficients = -1;
	
}//AccessLimits
