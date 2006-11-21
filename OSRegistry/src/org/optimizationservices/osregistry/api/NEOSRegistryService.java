/**
 * @(#)NEOSRegistryService 1.0 03/14/2004
 *
 * Copyright (c) 2004
 */
package org.optimizationservices.osregistry.api;

import org.optimizationservices.oscommon.communicationinterface.OSdL;
import org.optimizationservices.oscommon.util.OSParameter;


/**
 *
 * <P>The <code>NEOSRegistryService</code> implements all the <code>OSdL</code> and 
 * <code>OSdL</code> interfaces. Thus it is an OS-type registry. It implements all the methods as specified in the
 * Optimization Services (OS) Framework, specifically the Optimization Services discover
 * Language (OSdL), the Optimization Services join Language (OSjL) and the Optimization Services validate Language (OSvL)
 * The methods in OSdL are called by an OS agent to  find and register in an OS registry
 * any OS services, such as OS solvers or analyzers. The methods in OShL are called by 
 * called by an OS service provider to join an OS registry. Any registry that wants to become 
 * an OS-type callable on the distributed system must implement these interfaces.  
 * These methods are called by an OS agent to validate an xml representation's validity.  
 *
 * </p>
 * @author Robert Fourer, Jun Ma, Kipp Martin
 * @version 1.0, 03/14/2004
 * @see org.optimizationservices.osregistry.api.OSdL
 * @since OS 1.0
 */
public class NEOSRegistryService implements OSdL{
	/**
	 * Find an Optimization Service whose instance is given by a string following
	 * the Optimization Services query Language (OSqL) schema and returns the location information
	 * in a string that follows the Optimization Services URI, or Universal Resource Indentifier
	 * Language, (OSuL) schema.
	 *
	 * </P>
	 *
	 * @param OSqL holds the Optimization Service query in a string which format follows the
	 * Optimization Services query Language (OSqL) schema.
	 * @param osol holds the optimization option in a string which format follows the 
	 * Optimization Services option Language (OSoL) schema.    
	 * @return the location information in a string that follows the Optimization Services URI,
	 * or Universal Resource Indentifier Language, (OSuL) schema.
	 * @see org.optimizationservices.osregistry.api.OSdL#find
	 */
	public String find(String osql, String osol){
		String sSite = OSParameter.OS_SERVICE_SITE;
		//String sJunMaLPSolverServiceAddress = "<OSuL>" + sSite + "ossolver/JunMaLPSolverService.jws</OSuL>";
		String sCOINLPSolverServiceAddress = "<OSuL>" + sSite + "ossolver/COINSolverService.jws</OSuL>";
		String sLindoSolverServiceAddress = "<OSuL>" + sSite + "ossolver/LindoSolverService.jws</OSuL>";
		String sKnitroSolverServiceAddress = "<OSuL>" + sSite + "ossolver/KnitroSolverService.jws</OSuL>";
		String sDrAMPLAnalyzerServiceAddress = "<OSuL>" + sSite + "osanalyzer/DrAMPLAnalyzerService.jws</OSuL>";
		String sNEOSRegistryServiceAddress = "<OSuL>" + sSite + "osregistry/NEOSRegistryService.jws</OSuL>";
		String sRosenbrockSimulationServiceAddress = "<OSuL>" + sSite + "ossimulation/RosenbrockSimulationService.jws</OSuL>";
		
		String sOSuL = "";
		if(osql.indexOf("xPath") >= 0 || osql.indexOf("userF") >=0 || osql.indexOf("simulation") >=0) {
			sOSuL =  sKnitroSolverServiceAddress;
		}
		else if(osql.indexOf("nonlinear") >= 0) {
			sOSuL =  sLindoSolverServiceAddress;
		}
		else if(osql.indexOf("linear") >= 0){
			sOSuL = sCOINLPSolverServiceAddress;
		}
		else if(osql.indexOf("analyzer") >= 0){
			sOSuL = sDrAMPLAnalyzerServiceAddress;
		}
		else if(osql.indexOf("registry") >= 0){
			sOSuL = sNEOSRegistryServiceAddress;
		}
		else if(osql.indexOf("rosenbrock") >= 0){
			sOSuL = sRosenbrockSimulationServiceAddress;
		}
		else{
			return "NOT FOUND";
		}
		return sOSuL;
	}//find
	
	/**
	 * Register an Optimization Service whose instance is given by a string following 
	 * the Optimization Services entity Language (OSeL) schema and returns a string that contains 
	 * an XSLT style sheet transformation so that it can be used for standard web pubblication of the 
	 * Optimization Service that just registered. The XSLT is espcially used to publish the OSeL. 
	 * 
	 * </P>
	 * 
	 * @param osel holds the Optimization Service entity description in a string which format follows the 
	 * Optimization Services entity Language (OSeL) schema.  
	 * @param osol holds the optimization option in a string which format follows the 
	 * Optimization Services option Language (OSoL) schema.    
	 * @return the register process output information in a string which format follows the OSpL schema.
	 */
	public String register(String osel, String osol){return "";}
	
	/**
	 * Validate an xml representation's validity.
	 * 
	 * </P>
	 * 
	 * @param osxl holds the xml string to be validated
	 * @param osol holds the optimization option in a string which format follows the 
	 * Optimization Services option Language (OSoL) schema.    
	 * @return the validate process output information in a string which format follows the OSpL schema.
	 */
	public String validate(String osxl, String osol){return "";}
	
	/**
	 * This method is called by one optimization service on another optimization service
	 * to provide runtime dynamic process information (push mechanism).
	 *
	 * </P>
	 * @param osplInput holds the input process information a string which format follows the Optimization
	 * Services process Language (OSpL) schema.
	 * @param osol holds the optimization option in a string which format follows the 
	 * Optimization Services option Language (OSoL) schema.    
	 * @return osplOutput, the ouput process information in a string which format follows the OSpL schema.
	 */
	public String knock(String osplInput, String osol){return "";}//knock
	
	/**
	 * main for test purposes.
	 *
	 * </p>
	 *
	 * @param argv command line arguments.
	 */
	public static void main(String[] argv){
		NEOSRegistryService neosRegistryService = new NEOSRegistryService();
		String sOSqL = "<OSqL>... registry ...</OSqL>";
		String sOSuL = neosRegistryService.find(sOSqL, null);
		System.out.println(sOSuL);
	}//main
	
}//class NEOSRegistryService
