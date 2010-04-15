/**
 * @(#)JobResult 1.0 03/14/2009
 *
 * Copyright (c) 2009
 */
package org.optimizationservices.oscommon.datastructure.osresult;

import java.util.GregorianCalendar;


/**
*
* <p>A data structure class that corresponds to an xml element in the OSrL schema.  
*  
* </p>
* @author Gus Gassmann, Jun Ma, Kipp Martin
* @version 1.0, 03/14/2009
* @since OS 2.0
*/
public class JobResult{
	
	public String status = "";

	public GregorianCalendar submitTime = new GregorianCalendar(1970, 0, 1, 0, 0, 0);
	
	public GregorianCalendar scheduledStartTime = new GregorianCalendar(1970, 0, 1, 0, 0, 0);

	public GregorianCalendar actualStartTime = new GregorianCalendar(1970, 0, 1, 0, 0, 0);

	public GregorianCalendar endTime = new GregorianCalendar(1970, 0, 1, 0, 0, 0);
	
	public TimingInformation timingInformation =  new TimingInformation();
	
	public CPUSpeed usedCPUSpeed = new CPUSpeed();
	
	public CPUNumber usedCPUNumber = new CPUNumber();
	
	public DiskSpace usedDiskSpace = new DiskSpace();
	
	public MemorySize usedMemory = new MemorySize();
	
	public OtherResults otherResults = null;
	
}//class JobResult
