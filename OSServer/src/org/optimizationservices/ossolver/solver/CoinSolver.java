/**
 * @(#)CoinSolver 1.0 03/14/2004
 *
 * Copyright (c) 2004
 */
package org.optimizationservices.ossolver.solver;

import org.optimizationservices.oscommon.localinterface.DefaultSolver;

/**
*
* <P>The <code>CoinSolver</code> .</p>
*
* </p>
*
* @author Robert Fourer, Jun Ma, Kipp Martin
* @version 1.0, 03/14/2004
* @since OS 1.0
*/
public class CoinSolver extends DefaultSolver{
	/**
	 * constructor
	 */
	public CoinSolver(){
		
	}//constructor
	
	/**
	 * This solve method implements the abstract solve method in DefaultSolver. 
	 * @see org.optimizationservices.oscommon.localinterface.DefaultSolver; 
	 */
	public void solve(){
		super.osrl = nativeSolve(super.osil, super.osol);
	}//solve
	
	/** 
	 * this is the native (C code) solve method used to call 
	 * 
	 * @param osil holds the optimization instance in a string which format follows the
	 * Optimization Services instance Language (OSiL) schema.
	 * @param osol holds the optimization option in a string which format follows the 
	 * Optimization Services option Language (OSoL) schema.    
	 * @return the optimization result in a string which format follows the Optimization
	 * Services result Language (OSrL) schema.
	 */	 
	@SuppressWarnings("unused")
	private native String nativeSolve(String osil, String osol);
	
	/**
	 * static constructor
	 */
	static {
		System.loadLibrary("./lib/CoinSolverJNI"); //C:\WINDOWS\SYSTEM32 for windows
	}//static constructor
}//class
