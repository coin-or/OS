/**
 * @(#)DefaultSolver 1.0 03/14/2005
 *
 * Copyright (c) 2005 
 */
package org.optimizationservices.oscommon.localinterface;


/**
*
* <P>The <code>DefaultSolver</code> class is a default abstract solver 
* that is to be implemented by a solver that needs to be implemented as an
* optimization service using OSServiceUtil. 
*
* @author Robert Fourer, Jun Ma, Kipp Martin
* @version 1.0, 03/14/2005
* @see org.optimizationservices.oscommon.util.OSServiceUtil
* @since OS 1.0
*/
public abstract class DefaultSolver {
	/**
	 * osil holds the OSiL string (input).
	 */
	public String osil = "";

	/**
	 * osol holds the OSoL string (input).
	 */
	public String osol = "";

	/**
	 * osrl holds the OSrL string (output).
	 */
	public String osrl = "";

	/**
	 * osInstance holds OS instance object (input).
	 */
	public OSInstance osInstance = null;

	/**
	 * osOption holds the OS option object (input)
	 */
	public OSOption osOption = null;

	/**
	 * osResult holds the OS result object (output)
	 */
	public OSResult osResult = null;

	/**
	 *
	 * Default constructor. 
	 */
	public DefaultSolver(){
	}//constructor

	/**
	 * The solve method that is to be implemented by an OS solver service.  
	 */
	public abstract void solve() throws Exception;
	
	/**
	 * The kill method that may be implemented by an OS solver service to do extra kill for clean up.  
	 */
	public void kill() throws Exception{
		return;
	}//kill
	
	/**
	 * main for test purposes.
	 *
	 * </p>
	 *
	 * @param argv command line arguments.
	 */
	public static void main(String[] args){

	}//main
	
}//class DefaultSolver
