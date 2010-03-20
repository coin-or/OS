/**
 * @(#)ServiceEntry 1.0 03/14/2004
 *
 * Copyright (c) 2004
 */
package org.optimizationservices.oscommon.datastructure.osregistry;

import org.optimizationservices.oscommon.localinterface.OSBenchmark;
import org.optimizationservices.oscommon.localinterface.OSEntity;
import org.optimizationservices.oscommon.localinterface.OSProcess;


/**
 *
 * <p>A data structure class that corresponds to an xml element in the OSRegistry schema.  
 *  
 * </p>
 * @author Robert Fourer, Jun Ma, Kipp Martin
 * @version 1.0, 03/14/2004
 * @since OS 1.0
*/
public class ServiceEntry{

	public OSEntity osel = new OSEntity();

	public OSProcess ospl = new OSProcess();

	public OSBenchmark osbl = new OSBenchmark();
	
}//class ServiceEntry
