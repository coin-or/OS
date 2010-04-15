/**
 * @(#)DefaultSimulation 1.0 03/14/2005
 *
 * Copyright (c) 2005 
 */
package org.optimizationservices.oscommon.localinterface;



/**
*
* <P>The <code>DefaultSimulation</code> class is a default abstract simulation 
* that is to be implemented by a simulation that needs to be implemented as an
* optimization service using OSServiceUtil. 
*
* @author Robert Fourer, Jun Ma, Kipp Martin
* @version 1.0, 03/14/2005
* @see org.optimizationservices.oscommon.util.OSServiceUtil
* @since OS 1.0
*/
public abstract class DefaultSimulation {
	/**
	 * osslInput holds the OSiL input string.
	 */
	public String osslInput = null;

	/**
	 * osol holds the OSoL string (input).
	 */
	public String osol = null;

	/**
	 * osslOutput holds the OSsL output string.
	 */
	public String osslOutput = null;
	
	/**
	 * osSimulationInput holds the OS simulation object (input).
	 */
	public OSSimulation osSimulationInput = null;
	
	/**
	 * osSimulationOutput holds the OS simulation object (output). 
	 */
	public OSSimulation osSimulationOutput = null;
	
	/**
	 * osOption holds the OS option object (input).
	 */
	public OSOption osOption = null;

	/**
	 *
	 * Default constructor. 
	 */
	public DefaultSimulation(){
	}//constructor

	/**
	 * The call method that is to be implemented by an OS simulation service.  
	 */
	public abstract void call();
	
	/**
	 * main for test purposes.
	 *
	 * </p>
	 *
	 * @param argv command line arguments.
	 */
	public static void main(String[] args){

	}//main
	
}//class DefaultSimulation
