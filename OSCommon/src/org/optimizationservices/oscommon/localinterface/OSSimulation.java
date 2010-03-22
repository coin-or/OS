/**
 * @(#)OSSimulation 1.0 03/14/2005
 *
 * Copyright (c) 2005 
 */
package org.optimizationservices.oscommon.localinterface;

import org.optimizationservices.oscommon.datastructure.ossimulation.SimulationElement;
import org.optimizationservices.oscommon.datastructure.ossimulation.SimulationInput;
import org.optimizationservices.oscommon.datastructure.ossimulation.SimulationOutput;
import org.optimizationservices.oscommon.representationparser.OSsLReader;
import org.optimizationservices.oscommon.representationparser.OSsLWriter;

/**
*
* <P>The <code>OSSimulation</code> class is a local interface for storing Optimization Services
* simulation. Its design follows the Optimization Services simulation Language (OSsL). 
* All the data structures in this class are standards specified in OSsL. 
*
* @author Robert Fourer, Jun Ma, Kipp Martin
* @version 1.0, 03/14/2005
* @since OS 1.0
*/

public class OSSimulation {
	
	/**
	 * input holds the simulation input.
	 */
	public SimulationInput input = new SimulationInput();

	/**
	 * output holds the simulation output.
	 */
	public SimulationOutput output = new SimulationOutput();	
	
	/**
	 *
	 * Default constructor. 
	 */
	public OSSimulation(){
	}//constructor
	
	/**
	 * read an OSsL instance and return and OSSimulation object.  
	 * 
	 * @param ossl holds the optimization simulation in a string which format follows the
	 * Optimization Services simulation Language (OSsL) schema.
	 * @param isFile holds whether the ossl string is a file name or a string that literally holds the ossl contents.  
	 * @param validate holds whether the reader should be validating against the schema or not.
	 * @return the OSSimulation object constructed from the OSsL String.  
	 * @throws Exception if there are errors in reading the string or setting the OSSimulation. 
	 */
   	public OSSimulation readOSsL(String ossl, boolean isFile, boolean validate) throws Exception{
   		OSsLReader osslReader = new OSsLReader(validate);
		boolean bRead = false;
		if(isFile){
			bRead = osslReader.readFile(ossl);
		}
		else{
			bRead = osslReader.readString(ossl);			
		}
		if(!bRead) throw new Exception("OSsL string not valid");
		return osslReader.getOSSimulation();
   	}//readOSsL
   	
   	/**
   	 * write the OSSimulation to an ossl xml string. 
   	 * 
   	 * @return the ossl xml string. 
	 * @throws Exception if there are errors in writing the ossl string. 
   	 */
   	public String writeOSsL() throws Exception{
		OSsLWriter osslWriter = new OSsLWriter();
		osslWriter.setOSSimulation(this);
		return osslWriter.writeToString();
   	}//writeOSsL
   	
	/**
	 * get simulation input elements.
	 * 
	 * @return an array of simulation input elements, null if none. Each member of array 
	 * is a simulation element. 
	 * @see org.optimizationservices.oscommon.datastructure.ossimulation.SimulationElement
	 */
	public SimulationElement[] getSimulationInputElements(){
		return input.el;
	}//getSimulationInput
	
	/**
	 * set simulation input elements.
	 * 
	 * @param simulationInputElements holds an array of simulation input elements. 
	 * Each member of array is a simulation element. 
	 * @return whether the simulation input elements are set successfully or not. 
	 * @see org.optimizationservices.oscommon.datastructure.ossimulation.SimulationElement
	 */
	public boolean setSimulationInputElements(SimulationElement[] simulationInputElements){
		input.el = simulationInputElements;
		return true;
	}//setSimulationInputElements
	
	/**
	 * get simulation output elements.
	 * 
	 * @return an array of simulation output elements, null if none. Each member of array 
	 * is a simulation element. 
	 * @see org.optimizationservices.oscommon.datastructure.ossimulation.SimulationElement
	 */
	public SimulationElement[] getSimulationOutputElements(){
		return output.el;
	}//getSimulationOutput
	
	/**
	 * set simulation output elements.
	 * 
	 * @param simulationOutputElements holds an array of simulation output elements. 
	 * Each member of array is a simulation element. 
	 * @return whether the simulation output elements are set successfully or not. 
	 * @see org.optimizationservices.oscommon.datastructure.ossimulation.SimulationElement
	 */
	public boolean setSimulationOutputElements(SimulationElement[] simulationOutputElements){
		output.el = simulationOutputElements;
		return true;
	}//setSimulationOutputElements
	
	
	/**
	 * main for test purposes.
	 *
	 * </p>
	 *
	 * @param argv command line arguments.
	 */
	public static void main(String[] args){
		
	}//main
}//class OSSimulation

