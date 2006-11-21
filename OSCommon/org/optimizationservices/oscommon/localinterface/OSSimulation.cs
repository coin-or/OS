using System;

using org.optimizationservices.oscommon.datastructure.ossimulation;
using org.optimizationservices.oscommon.representationparser;

namespace org.optimizationservices.oscommon.localinterface{
	/// <summary>
	/// The <c>OSSimulation</c> class is a local interface for storing OS 
	/// simulation. Its design follows the OSsL. Naming, structuring and layering 
	/// all are exactly the same as those in the OSsL schema. 
	/// @author Jun Ma	
	/// @version 1.0, 09/01/2005
	/// @since OS 1.0
	/// @copyright (c) 2005
	/// </summary>
	public class OSSimulation{
	
		/// <summary>
		/// input holds the simulation input.
		/// </summary>
		public SimulationInput input = new SimulationInput();

		/// <summary>
		/// output holds the simulation output.
		/// </summary>
		public SimulationOutput output = new SimulationOutput();	

		/// <summary>
		/// Default constructor. 
		/// </summary>
		public OSSimulation(){
		}//constructor

		/// <summary>
		/// read an OSsL instance and return and OSSimulation object.  
		/// @throws Exception if there are errors in reading the string or setting the OSSimulation. 
		/// </summary>
		/// <param name="ossl">holds the optimization simulation in a string which format follows the
		/// Optimization Services simulation Language (OSsL) schema</param>
		/// <param name="isFile">isFile holds whether the ossl string is a file name or a string that literally holds the ossl contents.  </param>
		/// <param name="validate">holds whether the reader should be validating against the schema or not.</param>
		/// <returns>the OSSimulation object constructed from the OSsL String.  </returns>
		public OSSimulation readOSsL(string ossl, bool isFile, bool validate){
			OSsLReader osslReader = new OSsLReader(validate);
			bool bRead = false;
			if(isFile){
				bRead = osslReader.readFile(ossl);
			}
			else{
				bRead = osslReader.readString(ossl);			
			}
			if(!bRead) throw new Exception("OSsL string not valid");
			return osslReader.getOSSimulation();
		}//readOSsL
	   
		/// <summary>
		/// write the OSSimulation to an ossl xml string. 
		/// @throws Exception if there are errors in writing the ossl string. 
		/// </summary>
		/// <returns>the ossl xml string. </returns>
		public string writeOSsL(){
			OSsLWriter osslWriter = new OSsLWriter();
			osslWriter.setOSSimulation(this);
			return osslWriter.writeToString();

		}//writeOSsL
		/// <summary>
		/// get simulation input elements.
		/// @see org.optimizationservices.oscommon.datastructure.ossimulation.SimulationElement
		/// </summary>
		/// <returns>an array of simulation input elements, null if none. 
		/// Each member of array is a simulation element. 
		/// </returns>
		public SimulationElement[] getSimulationInputElements(){
			return input.el;
		}//getSimulationInput

		/// <summary>
		/// set simulation input elements.
		/// @see org.optimizationservices.oscommon.datastructure.ossimulation.SimulationElement
		/// </summary>
		/// <param name="simulationInputElements">holds an array of simulation input elements. 
		/// Each member of array is a simulation element. 
		/// </param>
		/// <returns>whether the simulation input elements are set successfully or not. </returns>
		public bool setSimulationInputElements(SimulationElement[] simulationInputElements){
			input.el = simulationInputElements;
			return true;
		}//setSimulationInputElements
	
		/// <summary>
		/// get simulation output elements.
		/// @see org.optimizationservices.oscommon.datastructure.ossimulation.SimulationElement
		/// </summary>
		/// <returns>an array of simulation output elements, null if none. 
		/// Each member of array is a simulation element. 
		/// </returns>
		public SimulationElement[] getSimulationOutputElements(){
			return output.el;
		}//getSimulationOutput

		/// <summary>
		/// set simulation output elements.
		/// @see org.optimizationservices.oscommon.datastructure.ossimulation.SimulationElement
		/// </summary>
		/// <param name="simulationOutputElements">holds an array of simulation output elements. 
		/// Each member of array is a simulation element. 
		/// </param>
		/// <returns>whether the simulation output elements are set successfully or not. </returns>
		public bool setSimulationOutputElements(SimulationElement[] simulationOutputElements){
			output.el = simulationOutputElements;
			return true;
		}//setSimulationOutputElements
	}//class OSSimulation
}//namespace
