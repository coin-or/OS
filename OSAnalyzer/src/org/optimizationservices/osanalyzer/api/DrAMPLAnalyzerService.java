/**
 * @(#)NEOSRegistryService 1.0 03/14/2004
 *
 * Copyright (c) 2004
 */
package org.optimizationservices.osanalyzer.api;

import org.optimizationservices.oscommon.communicationinterface.OShL;



/**
 *
 * <P>The <code>DrAMPLAnalyzerService</code> implements all the <code>OShL</code> interface.
 * Thus it is OS-type solver. It implements all the methods as specified in the
 * Optimization Services (OS) Framework, specifically the Optimization Services hook-up
 * Language (OShL). These methods are called by an OS agent to invoke this OS-based solver.
 *
 * </p>
 * @author Robert Fourer, Jun Ma, Kipp Martin
 * @version 1.0, 03/14/2004
 * @see org.optimizationservices.osanalyzer.api.OShL
 * @since OS 1.0
 */
public class DrAMPLAnalyzerService implements OShL{
	/**
	 * Analyze an optimization problem whose instance is given by a string following 
	 * the Optimization Services instance Language (OSiL) schema and returns the Optimization 
	 * Services result Language(OSrL) schema. OSrL contains a section of OSaL for analysis.  
	 * OSrL also contains sections for storing optimization results in case that the analyzer finds
	 * solutions.
	 * 
	 * </P>
	 * 
	 * @param OSiL holds the optimization instance in a string which format follows the 
	 * Optimization Services instance Language (OSiL) schema.  
	 * @param osol holds the optimization option in a string which format follows the 
	 * Optimization Services option Language (OSoL) schema. 
	 * @return the optimization result in a string which format follows the Optimization
	 * Services result Language (OSrL) schema.  
	 * @see org.optimizationservices.osanalyzer.api.OShL#analyze
	 */
	public String solve(String osil, String osol){
		String sOSaL = "<OSaL>";
		if(osil.indexOf("xPath") >= 0) {
			sOSaL += "xPath" ;
		}
		else if(osil.indexOf("userF") >= 0) {
			sOSaL += "userF" ;
		}
		else if(osil.indexOf("simulation") >= 0) {
			sOSaL += "simulation";
		}
		else if(osil.indexOf("</nl>") >= 0) {
			sOSaL +=  "nonlinear";
		}
		else{
			sOSaL +=  "linear";
		}
		sOSaL += "/<OSaL>";
		return sOSaL;
	}//analyze
	
	/**
	 * Methods in OShL that are not implemented. 
	 */
	public boolean send(String osil, String osol){return false;};
	
	/**
	 * Methods in OShL that are not implemented.
	 */
	public String getJobID(String osol){ return null;}
	
	/**
	 * Methods in OShL that are not implemented.
	 */
	public String retrieve(String jobID){return null;}
	
	/**
	 * Methods in OShL that are not implemented.
	 */
	public String kill(String osol){return null;}
	
	/**
	 * Methods in OSkL that are not implemented.
	 */
	public String knock(String osol){return null;}

	/**
	 * Methods in OShL that are not implemented.
	 */
	public String knock(String ospl, String osol){return null;}

	/**
	 * main for test purposes.
	 *
	 * </p>
	 *
	 * @param argv command line arguments.
	 */
	public static void main(String[] argv){
		DrAMPLAnalyzerService drAMPLAnalyzerService = new DrAMPLAnalyzerService();
		String sOSiL = "<OSiL>blah blah </nl> blah blah<OSiL>";
		String sOSaL = drAMPLAnalyzerService.solve(sOSiL, null);
		System.out.println(sOSaL);
	}//main
	
}//class DrAMPLAnalyzerService
