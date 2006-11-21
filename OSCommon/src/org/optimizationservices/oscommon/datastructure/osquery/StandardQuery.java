/**
 * @(#)StandardQuery 1.0 03/14/2004
 *
 * Copyright (c) 2004
 */
package org.optimizationservices.oscommon.datastructure.osquery;

import org.optimizationservices.oscommon.datastructure.osentity.OptimizationInfo;



/**
 *
 * <p>A data structure class that corresponds to an xml element in the OSqL schema.  
 *  
 * </p>
 * @author Robert Fourer, Jun Ma, Kipp Martin
 * @version 1.0, 03/14/2004
 * @since OS 1.0
*/
public class StandardQuery{

	public String currentState = null;

	public String serviceType = "solver";

	public OptimizationInfo optimization = null;
	
}//class StandardQuery
