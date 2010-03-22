/**
 * @(#)FunctionType 1.0 03/14/2004
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
public class FunctionType{
	
	public boolean general = false;

	public boolean basic = true;

	public boolean arithmetic = true;

	public boolean trigonometric = false;

	public boolean statistics = false;

	public boolean probability = false;

	public boolean relationalAndLogic = false;

	public boolean userFunction = false;

	public boolean simulation = false;

}//class FunctionType
