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
		
	public int numberOfOtherVariableResults = 0;
	
	public VariableValues values = null;
	
	public VariableStringValues valuesString = null;

	public BasisStatus basisStatus = null;
	
	public OtherVariableResult other[] = null;
	
}//VariableSolution
