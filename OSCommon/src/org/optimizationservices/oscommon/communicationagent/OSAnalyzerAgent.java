/**
 * @(#)OSSolverAgent 1.0 03/14/2004
 *
 * Copyright (c) 2004
 */
package org.optimizationservices.oscommon.communicationagent;

import org.optimizationservices.oscommon.communicationinterface.OShL;
import org.optimizationservices.oscommon.util.IOUtil;
import org.optimizationservices.oscommon.util.OSParameter;
import org.optimizationservices.oscommon.util.WSUtil;


/**
 *
 * <P>The <code>OSAnalyzerAgent</code> class  implements  the <code>OShL</code> interface.
 * Thus it is OS-type analyzer. It implements all the methods as specified in the
 * Optimization Services (OS) Framework, specifically the Optimization Services hook-up
 * Language (OShL).</p>
 *
 * <P>The <code>OSAnalyzerAgent</code> class is a library class that contains methods
 * to help analyzer agents communicate with Optimization Services (OS) analyzers as specified
 * by the Optimization Services framework. It hides all the SOAP protocol related technical details
 * from an optimization user.</p>
 *
 * </p>
 *
 * @author Robert Fourer, Jun Ma, Kipp Martin
 * @version 1.0, 03/14/2004
 * @see org.optimizationservices.oscommon.communicationinterface.OShL
 * @since OS 1.0
 */
public class OSAnalyzerAgent implements OShL{
	/**
	 * analyzerAddress holds the address (uri/url) of the Optimization Services (OS) analyzer.
	 */
	public String analyzerAddress = "";
	
	/**
	 * Constructor.
	 *
	 */
	public OSAnalyzerAgent(){
		
	}//constructor
	
	/**
	 * Constructor.
	 *
	 * @param analyzerAddress holds the address (uri/url) of the Optimization Services (OS) analyzer.
	 */
	public OSAnalyzerAgent(String analyzerAddress){
		this.analyzerAddress = analyzerAddress;
	}//constructor


	/**
	 * Analyze an optimization problem with options. The problem instance is given by a string following 
	 * the Optimization Services instance Language (OSiL) schema. The options are given in a string following 
	 * the Optimization Services option Language (OSoL) schema. The function returns the solution
	 * in a string that follows the Optimization Services result Language (OSrL) schema. 
	 * 
	 * </P>
	 * 
	 * @param osil holds the optimization instance in a string which format follows the 
	 * Optimization Services instance Language (OSiL) schema.  
	 * @param osol holds the optimization option in a string which format follows the 
	 * Optimization Services option Language (OSoL) schema. 
	 * @return the optimization result in a string which format follows the Optimization
	 * Services result Language (OSrL) schema.  
	 */
	public String solve(String osil, String osol){
		String sMethod = "solve";
		String[] msInputs = new String[]{osil, osol};
		String[] msInputNames = new String[]{"osil", "osol"};
		String sReturnName = "osrl"; 
		String sSoapAction = "OSSolverService#solve";
		String sOSrL = WSUtil.invokeOptimizationServices(analyzerAddress, sMethod, msInputs, msInputNames, sReturnName,  sSoapAction);
		return sOSrL;
	}
	
	/**
	 * Methods in OShL that are not implemented.
	 */
	public boolean send(String osil, String osol){return false;}

	/**
	 * Methods in OShL that are not implemented.
	 */
	public String getJobID(String osol){ return null;}
	
	/**
	 * Methods in OShL that are not implemented.
	 */
	public String retrieve(String osol){return null;}
	
	/**
	 * Methods in OShL that are not implemented.
	 */
	public String kill(String osol){return null;}
	
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
	public static void main(String [] args) {
		//registry
		OSRegistryAgent osRegistryAgent = new OSRegistryAgent();
		osRegistryAgent.registryAddress = OSParameter.OS_REGISTRY_SITE;
		
		//find analyzer
		String sOSqL = "<OSqL>... analyzer ...</OSqL>";
		String sOSuL = osRegistryAgent.find(sOSqL, null);
		
		//analyzer
		String sAnalyzerAddress = sOSuL.substring(6, sOSuL.indexOf("</OSuL>"));
		String sOSiL = IOUtil.fileToString("../../../OSRepository/test/osil/parinc.osil"); //linear
		OSAnalyzerAgent osAnalyzerAgent = new OSAnalyzerAgent();
		osAnalyzerAgent.analyzerAddress = sAnalyzerAddress;
		String sOSrL = osAnalyzerAgent.solve(sOSiL, null);
		System.out.println(sOSrL);
	}//main
	
}//class OSAnalyzerAgent
