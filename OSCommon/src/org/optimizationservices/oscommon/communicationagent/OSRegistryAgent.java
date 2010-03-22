/**
 * @(#)OSRegistryAgent 1.0 03/14/2004
 *
 * Copyright (c) 2004
 */
package org.optimizationservices.oscommon.communicationagent;

import org.optimizationservices.oscommon.communicationinterface.OSdL;
import org.optimizationservices.oscommon.util.OSParameter;
import org.optimizationservices.oscommon.util.WSUtil;


/**
 *
 * <P>The <code>OSRegistryAgent</code> class implements all the <code>OSdL</code> interface.
 * Thus it is OS-type registry. It implements all the methods as specified in the
 * Optimization Services (OS) Framework, specifically the Optimization Services discover
 * Language (OSdL).</p> 
 * 
 * <P>The <code>OSRegistryAgent</code> class is a library class that contains methods
 * to help registry agents communicate with Optimization Services (OS) registries as specified
 * by the Optimization Services framework. It hides all the SOAP protocol related technical details
 * from an optimization user.</p>
 *
 * </p>
 *
 * @author Robert Fourer, Jun Ma, Kipp Martin
 * @version 1.0, 03/14/2004
 * @see org.optimizationservices.oscommon.communicationinterface.OSdL
 * @since OS 1.0
 */
public class OSRegistryAgent implements OSdL{
	/**
	 * registryAddress holds the address (uri/url) of the Optimization Services (OS) registry.
	 */
	public String registryAddress = "";
	
	/**
	 * Constructor. 
	 *
	 */
	public OSRegistryAgent(){
		
	}//constructor
	
	/**
	 * Constructor.
	 * 
	 * @param registryAddress holds the address (uri/url) of the Optimization Services (OS) registry.
	 */
	public OSRegistryAgent(String registryAddress){
		this.registryAddress = registryAddress;
	}//constructor
	
	/**
	 * Discover an Optimization Service whose instance is given by a string following 
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
	 */
	public String find(String osql, String osol){
		String sMethod = "find";
		String[] msInputs = new String[]{osql, osol};
		String[] msInputNames = new String[]{"osql", "osol"};
		String sReturnName = "osul"; 
		String sSoapAction = "OSRegistryService#find";
		String sOSuL = WSUtil.invokeOptimizationServices(registryAddress, sMethod, msInputs, msInputNames, sReturnName, sSoapAction);
		return sOSuL;
	}//find
	
	/**
	 * register an Optimization Service whose instance is given by a string following 
	 * the Optimization Services entity Language (OSeL) schema and returns a string that contains 
	 * an XSLT style sheet transformation so that it can be used for standard web pubblication of the 
	 * Optimization Service that just joined. The XSLT is espcially used to publish the OSeL. 
	 * 
	 * </P>
	 * 
	 * @param osel holds the Optimization Service entity description in a string which format follows the 
	 * Optimization Services entity Language (OSeL) schema.  
	 * @param osol holds the optimization option in a string which format follows the 
	 * Optimization Services option Language (OSoL) schema.    
	 * @return the register process output information in a string which format follows the OSpL schema.
	 */
	public String register(String osel, String osol){
		String sMethod = "register";
		String[] msInputs = new String[]{osel, osol};
		String[] msInputNames = new String[]{"osel", "osol"};
		String sReturnName = "ospl"; 
		String sSoapAction = "OSRegistryService#register";
		String sOSpL = WSUtil.invokeOptimizationServices(registryAddress, sMethod, msInputs, msInputNames, sReturnName, sSoapAction);
		return sOSpL;
	}//register

	/**
	 * Validate an osxl string according to the corresponding OSxL schema.
	 *
	 * </P>
	 *
	 * @param osxl holds the xml string to be validated. 
	 * @param osol holds the optimization option in a string which format follows the 
	 * Optimization Services option Language (OSoL) schema.    
	 * @return the validate process output information in a string which format follows the OSpL schema.
	 */
	public String validate(String osxl, String osol){
		String sMethod = "validate";
		String[] msInputs = new String[]{osxl, osol};
		String[] msInputNames = new String[]{"osxl", "osol"};
		String sReturnName = "ospl"; 
		String sSoapAction = "OSRegistryService#validate";
		String sOSpL = WSUtil.invokeOptimizationServices(registryAddress, sMethod, msInputs, msInputNames, sReturnName, sSoapAction);
		return sOSpL;
	}//validate

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
	public String knock(String osplInput, String osol){
		String sMethod = "knock";		
		String[] msInputs = new String[]{osplInput, (osol==null)?"":osol};
		String[] msInputNames = new String[]{"osplInput", "osol"};
		String sReturnName = "osplOutput"; 
		String sSoapAction = "OSRegistryService#knock";
		String sOSpLOutput = WSUtil.invokeOptimizationServices(registryAddress, sMethod, msInputs, msInputNames, sReturnName, sSoapAction);
		return sOSpLOutput;
	}//knock

	/**
	 * main for test purposes.
	 *
	 * </p>
	 *
	 * @param argv command line arguments.
	 */
	public static void main(String [] args) {
		String sOSqL = "<OSqL>blah blah registry blah blah</OSqL>";
		OSRegistryAgent osRegistryAgent = new OSRegistryAgent();
		osRegistryAgent.registryAddress = OSParameter.OS_REGISTRY_SITE;
		String sOSuL = osRegistryAgent.find(sOSqL, null);
		System.out.println(sOSuL);
	}//main
	
}//class OSRegistryAgent
