/**
 * @(#)OSFlowAgent 1.0 03/14/2004
 *
 * Copyright (c) 2004
 */
package org.optimizationservices.oscommon.communicationagent;


import org.optimizationservices.oscommon.util.IOUtil;
import org.optimizationservices.oscommon.util.OSParameter;

/**
 *
 * <P>The <code>OSFlowAgent</code> class is a library class that invokes Optimization Services
 * according to the process/sequence specified in an Optimization Services flow Language (OSfL).</p>
 *
 * </p>
 *
 * @author Robert Fourer, Jun Ma, Kipp Martin
 * @version 1.0, 03/14/2004
 * @see org.optimizationservices.oscommon.communicationinterface.OScL
 * @see org.optimizationservices.oscommon.communicationinterface.OShL
 * @see org.optimizationservices.oscommon.communicationinterface.OSdL
 * @since OS 1.0
 */
public class OSFlowAgent {
	
	/**
	 * Constructor.
	 *
	 */
	public OSFlowAgent(){
		
	}//constructor
	
	public Object executeProcessFlow(String osfl, String osil){
		Object result = null;
		if(osfl.startsWith("find:analyzer->analyzer->find:solver->solver")){
			//registry
			OSRegistryAgent osRegistryAgent = new OSRegistryAgent();
			osRegistryAgent.registryAddress = OSParameter.OS_REGISTRY_SITE;
			System.out.println("\nregistry address:\n" + osRegistryAgent.registryAddress);
			
			//find analyzer
			String sOSqL = "<OSqL>... analyzer ...</OSqL>";
			String sOSuL = osRegistryAgent.find(sOSqL, null);
			System.out.println("\nanalyzer address:\n" + sOSuL);
			
			//analyzer
			String sAnalyzerAddress = sOSuL.substring(6, sOSuL.indexOf("</OSuL>"));
			String sOSiL = osil;
			OSAnalyzerAgent osAnalyzerAgent = new OSAnalyzerAgent();
			osAnalyzerAgent.analyzerAddress = sAnalyzerAddress;
			String sOSaL = osAnalyzerAgent.solve(sOSiL, null);
			System.out.println("\nanalyzer result:\n" + sOSaL);
			
			//find solver
			sOSqL = "<OSqL>... " + sOSaL + " ...</OSqL>";
			sOSuL = osRegistryAgent.find(sOSqL, null);
			System.out.println("\nsolver address:\n" + sOSuL);
			
			//solver
			String sSolverAddress = sOSuL.substring(6, sOSuL.indexOf("</OSuL>"));
			OSSolverAgent osSolverAgent = new OSSolverAgent();
			osSolverAgent.solverAddress = sSolverAddress;
			String sOSrL = osSolverAgent.solve(sOSiL, null);
			System.out.println("\nDone!\n");
			
			result = sOSrL;
		}
		else if(osfl.startsWith("solver")){
			String sOSiL = osil;
			OSSolverAgent osSolverAgent = new OSSolverAgent();
			String sSolverAddress = osfl.substring(osfl.indexOf("#")+1); 
			osSolverAgent.solverAddress = sSolverAddress;
			String sOSrL = osSolverAgent.solve(sOSiL, null);
			result = sOSrL;
			System.out.println("\nsolver result:\n" + sOSrL);
			
			result = sOSrL;
		}
		else{
			result = null;
		}
		return result;
	}//executeProcessFlow
	
	/**
	 * main for test purposes.
	 *
	 * </p>
	 *
	 * @param argv command line arguments.
	 */
	public static void main(String [] args){
		//String sSimpleFlow = "solver#http://iems218.iems.northwestern.edu:8080/os/ossolver/JunMaLPSolverService.jws";
		//String sSimpleFlow = "solver#http://iems218.iems.northwestern.edu:8080/os/ossolver/LindoSolverService.jws";
		String sComplexFlow = "find:analyzer->analyzer->find:solver->solver";
		OSFlowAgent osFlowAgent = new OSFlowAgent();
		//String sOSiL = IOUtil.fileToString("xml/lpfml/lpparinc.xml"); 
		String sOSiL = IOUtil.fileToString("../../../OSRepository/test/osil/rosenbrock.osil"); 
		//String sResult = (String)osFlowAgent.executeProcessFlow(sComplexFlow, sOSiL);
		String sResult = (String)osFlowAgent.executeProcessFlow(sComplexFlow, sOSiL);
		System.out.println(sResult);
	}//main
	
}//class OSFlowAgent
