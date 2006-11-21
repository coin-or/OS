/**
 * @(#)HardwareInfo 1.0 03/14/2004
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
public class HardwareInfo{
		
	public int cpuNumber = 1;
	
	public double cpuSpeed = Double.NaN;

	public double memorySize = Double.NaN;

	public double busSpeed = Double.NaN;

	public double diskSpace = Double.NaN;

	public double nicSpeed = Double.NaN;

	public double downloadSpeed = Double.NaN;

	public double uploadSpeed = Double.NaN;

}//class HardwareInfo
