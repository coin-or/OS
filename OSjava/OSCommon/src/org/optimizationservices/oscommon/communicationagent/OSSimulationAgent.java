/**
 * @(#)OSSimulationAgent 1.0 03/14/2004
 *
 * Copyright (c) 2004
 */
package org.optimizationservices.oscommon.communicationagent;

import org.optimizationservices.oscommon.communicationinterface.OScL;
import org.optimizationservices.oscommon.util.IOUtil;
import org.optimizationservices.oscommon.util.OSParameter;
import org.optimizationservices.oscommon.util.WSUtil;


/**
 *
 * <P>The <code>OSSimulationAgent</code> class implements all the <code>OScL</code> interface.
 * Thus it is OS-type solver. It implements all the methods as specified in the
 * Optimization Services (OS) Framework, specifically the Optimization Services call
 * Language (OScL).</p> 
 * 
 * <P>The <code>OSSimulationAgent</code> class is a library class that contains methods
 * to help simulation agents communicate with Optimization Services (OS) simulations as specified
 * by the Optimization Services framework. It hides all the SOAP protocol related technical details
 * from an optimization user.</p>
 *
 * </p>
 *
 * @author Robert Fourer, Jun Ma, Kipp Martin
 * @version 1.0, 03/14/2004
 * @see org.optimizationservices.oscommon.communicationinterface.OScL
 * @since OS 1.0
 */
public class OSSimulationAgent implements OScL{
	/**
	 * simulationAddress holds the address (uri/url) of the Optimization Services (OS) simulation.
	 */
	public String simulationAddress = "";
	
	/**
	 * Constructor. 
	 *
	 */
	public OSSimulationAgent(){
		
	}//constructor
	
	/**
	 * Constructor.
	 * 
	 * @param simulationAddress holds the address (uri/url) of the Optimization Services (OS) simulation.
	 */
	public OSSimulationAgent(String simulationAddress){
		this.simulationAddress = simulationAddress;
	}//constructor
	
	/**
	 * Call a simulation service whose input is given by a string following 
	 * the Optimization Services simulation Language (OSsL) schema and returns the analysis
	 * in a string that follows the Optimization Services simulation Language (OSsL) schema, 
	 * since OSsL specifies both simulation service input and output.
	 * 
	 * </P>
	 *
	 * @param OSsL holds the simulation input in a string which format follows the 
	 * Optimization Services simulation Language (OSsL) schema.  
	 * @param osol holds the optimization option in a string which format follows the 
	 * Optimization Services option Language (OSoL) schema.    
	 * @return osslInput the simulation output in a string which format follows the Optimization
	 * Services simulation Language (OSsL) schema.  
	 */
	public String call(String osslInput, String osol){
		String sMethod = "call";
		String[] msInputs = new String[]{osslInput, osol};
		String[] msInputNames = new String[]{"osslInput", "osol"};
		String sReturnName = "osslOutput"; 
		String sSoapAction = "OSSimulationService#call";
		String sOSsLOutput = WSUtil.invokeOptimizationServices(simulationAddress, sMethod, msInputs, msInputNames, sReturnName, sSoapAction);
		return sOSsLOutput;
	}//call
	
	/**
	 * main for test purposes.
	 *
	 * </p>
	 *
	 * @param argv command line arguments.
	 */
	public static void main(String [] args) {
		//registry
		OSRegistryAgent osRegistryAgent = new OSRegistryAgent();
		osRegistryAgent.registryAddress = OSParameter.OS_REGISTRY_SITE;
		
		//find simulation rosenbrock
		String sOSqL = "<OSqL>blah blah rosenbrock blah blah</OSqL>";
		String sOSuL = osRegistryAgent.find(sOSqL, null);
		
		//simulation 		
		String sSimulationAddress = sOSuL.substring(6, sOSuL.indexOf("</OSuL>"));		
		String sOSsLInput = IOUtil.fileToString("../../../OSRepository/test/ossl/osslRosenbrock.ossl");
		OSSimulationAgent osSimulationAgent = new OSSimulationAgent();
		osSimulationAgent.simulationAddress = sSimulationAddress;
		String sOSsLOutput = osSimulationAgent.call(sOSsLInput, null);
		System.out.println(sOSsLOutput);
	}//main
	
}//class OSSimulationAgent
