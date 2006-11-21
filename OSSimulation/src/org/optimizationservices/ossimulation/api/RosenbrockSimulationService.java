/**
 * @(#)RosenbrockSimulationService 1.0 03/14/2004
 *
 * Copyright (c) 2004
 */
package org.optimizationservices.ossimulation.api;

import org.optimizationservices.oscommon.communicationinterface.OScL;
import org.optimizationservices.oscommon.representationparser.OSsLReader;
import org.optimizationservices.oscommon.representationparser.OSsLWriter;
import org.optimizationservices.oscommon.util.IOUtil;
import org.optimizationservices.ossimulation.simulation.RosenbrockSimulation;




/**
 *
 * <P>The <code>RosenbrockSimulationService</code> implements all the <code>OScL</code> interface.
 * Thus it is OS-type simulation service. It implements all the methods as specified in the
 * Optimization Services (OS) Framework, specifically the Optimization Services call
 * Language (OScL). These methods are called by an OS agent to invoke this OS-based simulation service.
 *
 * <p><code>RosenbrockSimulationService</code> carries out calculation of Rosenbrock function. </p>
 * 
 * </p>
 * 
 * @author Robert Fourer, Jun Ma, Kipp Martin
 * @version 1.0, 03/14/2004
 * @see org.optimizationservices.ossimulation.api.OScL
 * @since OS 1.0
 */
public class RosenbrockSimulationService implements OScL{
	/**
	 * Call the Rosenbrock simulation service whose input is given by a string following 
	 * the Optimization Services simulation Language (OSsL) schema and returns the analysis
	 * in a string that follows the Optimization Services simulation Language (OSsL) schema, 
	 * since OSsL specifies both simulation service input and output.
	 * 
	 * </P>
	 * 
	 * @param osslInput holds the simulation input in a string which format follows the 
	 * Optimization Services simulation Language (OSsL) schema.  
	 * @param osol holds the optimization option in a string which format follows the 
	 * Optimization Services option Language (OSoL) schema.    
	 * @return the simulation output in a string which format follows the Optimization
	 * Services simulation Language (OSsL) schema.  
	 * @see org.optimizationservices.ossimulation.api.OScL#call
	 */
	public String call(String osslInput, String osol){
		//read
		OSsLReader osslReader = new OSsLReader();	
		osslReader.readString(osslInput);
		String sX0 = osslReader.getInputByName("x0");
		String sX1 = osslReader.getInputByName("x1");
		double dX0 = Double.parseDouble(sX0);
		double dX1 = Double.parseDouble(sX1);
		
		//solve
		RosenbrockSimulation rosenbrockSimulation = new RosenbrockSimulation();
		double dResult = rosenbrockSimulation.calculate(dX0, dX1);
		
		//write
		OSsLWriter osslWriter = new OSsLWriter();
		osslWriter.setOutputElement("result", "string", dResult + "");
		return osslWriter.writeToString();
	}//call

	/**
	 * main for test purposes.
	 *
	 * </p>
	 *
	 * @param argv command line arguments.
	 */
	public static void main(String[] argv){
		RosenbrockSimulationService rosenbrockSimulationService = new RosenbrockSimulationService();
		String sOSsLInput = IOUtil.fileToString("xml/osslRosenbrock.xml");
		System.out.println(sOSsLInput);
		String sOSsLOutput = rosenbrockSimulationService.call(sOSsLInput, null);
		System.out.println(sOSsLOutput);
	}//main
	
}//class RosenbrockSimulationService
