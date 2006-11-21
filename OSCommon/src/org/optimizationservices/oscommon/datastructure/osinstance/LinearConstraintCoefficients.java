/**
 * @(#)LinearConstraintCoefficients 1.0 03/14/2004
 *
 * Copyright (c) 2004
 */
package org.optimizationservices.oscommon.datastructure.osinstance;

import org.optimizationservices.oscommon.datastructure.osgeneral.DoubleVector;
import org.optimizationservices.oscommon.datastructure.osgeneral.IntVector;



/**
 *
 * <p>A data structure class that corresponds to an xml element in the OSiL schema.  
 *  
 * </p>
 * @author Robert Fourer, Jun Ma, Kipp Martin
 * @version 1.0, 03/14/2004
 * @since OS 1.0
*/
public class LinearConstraintCoefficients{

	public int numberOfValues = 0;

	public IntVector start = new IntVector();
	
	public IntVector rowIdx = new IntVector();
	
	public IntVector colIdx = new IntVector();
	
	public DoubleVector value = new DoubleVector();

}//class LinearConstraintCoefficients
