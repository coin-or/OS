/**
 * @(#)OScL 1.0 03/14/2004
 *
 * Copyright (c) 2004
 */
package org.optimizationservices.oscommon.communicationinterface;

/**
 *
 * <P>The <code>OScL</code> interface declares all the methods as specified in the 
 * Optimization Services (OS) Framework, specifically the Optimization Services call 
 * Language (OScL). These methods are called by an OS agent to invoke any OS-based simulation service. 
 * Any simulation service that wants to become an OS-type callable on the distributed system must implement this interface.  
 *
 * </p>
 * @author Robert Fourer, Jun Ma, Kipp Martin
 * @version 1.0, 03/14/2004
 * @since OS 1.0
 */
public interface OScL{
	
	/**
	 * Call a simulation service whose input is given by a string following 
	 * the Optimization Services simulation Language (OSsL) schema and returns the result
	 * in a string that follows the Optimization Services simulation Language (OSsL) schema, 
	 * since OSsL specifies both simulation service input and output.
	 * 
	 * </P>
	 * 
	 * @param osslInput holds the simulation input in a string which format follows the 
	 * Optimization Services simulation Language (OSsL) schema.  
	 * @param osol holds the optimization option in a string which format follows the 
	 * Optimization Services option Language (OSoL) schema.    
	 * @return osslOutput, the simulation output in a string which format follows the Optimization
	 * Services simulation Language (OSsL) schema.  
	 */
	public String call(String osslInput, String osol);
	
}//interface OScL
