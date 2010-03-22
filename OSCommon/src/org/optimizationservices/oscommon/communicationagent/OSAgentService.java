/**
 * @(#)OSAgentService 1.0 03/14/2004
 *
 * Copyright (c) 2004
 */
package org.optimizationservices.oscommon.communicationagent;



import org.optimizationservices.oscommon.util.IOUtil;


/**
 *
 * <P>The <code>OSAgentService</code> class is sample agent implementation that uses convenient
 * methods provided from the {@link edu.northwestern.impact.communication.OSSolverAgent OSSolverAgent} library
 * to invoke the sampleLPSolver, an Optimization Services (OS) type solver provided in the
 * org.optimizationservices.ossolver.solver package.
 *
 * </p>
 *
 * @author Robert Fourer, Jun Ma, Kipp Martin
 * @version 1.0, 03/14/2004
 * @see edu.northwestern.impact.communication.OSSolverAgent
 * @since OS 1.0
 */
public class OSAgentService{
	
	/**
	 * Constructor.
	 */
	public OSAgentService(){
	}//constructor
	
	/**
	 *
	 * @param flowName holds the flow of launching the Optimization Serives Process. For now either "simple" or "complex".
	 * @param input holds the initial input for the flow.
	 * @return the result after excuting the whole Optimization Services flow process.
	 */
	public String call(String flowName, String input){
		String sSimpleFlow = "solver#http://gsbkip.chicagogsb.edu/os/ossolver/JunMaLPSolverService.jws";
		String sComplexFlow = "find:analyzer->analyzer->find:solver->solver";
		String sFlow = "";
		if(flowName.equalsIgnoreCase("simple")) sFlow = sSimpleFlow;
		else sFlow = sComplexFlow;
		OSFlowAgent osFlowAgent = new OSFlowAgent();
		String sOSiL = input;
		String sResult = (String)osFlowAgent.executeProcessFlow(sFlow, sOSiL);
		return sResult;
	}//call
	
	/**
	 * main for test purposes.
	 *
	 * </p>
	 *
	 * @param argv command line arguments.
	 */
	public static void main(String [] args) {
		//String sOSiL = IOUtil.fileToString("xml/lpfml/lpparinc.xml");
		String sOSiL = IOUtil.fileToString("xml/osxl/osilrosenbrock.xml");
		OSAgentService osAgentService = new OSAgentService();
		String sResult = osAgentService.call("complex", sOSiL);
		System.out.println(sResult);
	}//main
	
}//class SampleLPSolver
