using System;

using org.optimizationservices.oscommon.datastructure.osinstance;
using org.optimizationservices.oscommon.representationparser;

namespace org.optimizationservices.oscommon.localinterface{
	/// <summary>
	/// The <c>OSInstance</c> class is a local interface for storing OS 
	/// problem instance. Its design follows the OSiL. Naming, structuring and layering 
	/// all are exactly the same as those in the OSiL schema. In general there are 
	/// three simple rules in translating the OSiL schema.
	/// 1. An element that is not of simple type (contains non-char nodes) 
	/// or has attributes, become a class. 
	/// The class type corresponds to the element type defined in the schema. 
	/// 2. A simple type element (just contains character data in the element) 
	/// becomes a correponding programming language (Java/C++/C#) data type. 
	/// 3. A "sequence" of one or more same-type elements becomes an array, members 
	/// with the selected choice being non-null. 
	/// There are some exceptions. 
	/// 1. Each "OSnLNode" "nonlinearExpressions" or "userFunctions" becomes an OSExpressionTree.
	/// 2. There are no definitions of "userFunctions", "simulations" and "realTimeData" 
	/// because these definitions are substituted.
	/// 3. All compression-related elements and attributes in xml disappear in the 
	/// local interface because they are all expanded. 
	/// 4. "semidefiniteBlocks", "cones", "stages", "stochasticInformation" and 
	/// "xmlData" are not implemented yet. 
	/// @author Jun Ma	
	/// @version 1.0, 09/01/2005
	/// @since OS 1.0
	/// @copyright (c) 2005
	/// <see cref="org.optimizationservices.oscommon.localinterface.OSResult"/>
	/// <see cref="org.optimizationservices.oscommon.localinterface.OSAnalysis"/>
	/// <see cref="org.optimizationservices.oscommon.localinterface.OSOption"/>
	/// </summary>
	public class OSInstance{

		/// <summary>
		/// instanceHeader holds the first child of the OSInstance specified by the OSiL Schema. 
		/// </summary>
		public InstanceHeader instanceHeader = new InstanceHeader();

		/// <summary>
		/// instanceData holds the second child of the OSInstance specified by the OSiL Schema. 
		/// </summary>
		public InstanceData instanceData = new InstanceData();

		/// <summary>
		/// Default constructor. 
		/// </summary>
		public OSInstance(){
		}//constructor

		/// <summary>
		/// read an OSiL instance and return and OSInstance object.  
		/// @throws Exception if there are errors in reading the string or setting the OSInstance. 
		/// </summary>
		/// <param name="osil">holds the optimization instance in a string which format follows the
		/// Optimization Services instance Language (OSiL) schema</param>
		/// <param name="isFile">isFile holds whether the osil string is a file name or a string that literally holds the osil contents.  </param>
		/// <param name="validate">holds whether the reader should be validating against the schema or not.</param>
		/// <returns>the OSInstance object constructed from the OSiL String.  </returns>
		public OSInstance readOSiL(string osil, bool isFile, bool validate){
			OSiLReader osilReader = new OSiLReader(validate);
			bool bRead = false;
			if(isFile){
				bRead = osilReader.readFile(osil);
			}
			else{
				bRead = osilReader.readString(osil);			
			}
			if(!bRead) throw new Exception("OSiL string not valid");
			return osilReader.getOSInstance();
		}//readOSiL
	   
		/// <summary>
		/// write the OSInstance to an osil xml string. 
		/// @throws Exception if there are errors in writing the osil string. 
		/// </summary>
		/// <returns>the osil xml string. </returns>
		public String writeOSiL(){
			OSiLWriter osilWriter = new OSiLWriter();
			osilWriter.setOSInstance(this);
			return osilWriter.writeToString();
		}//writeOSiL

		///TODO: implement get/set methods in OSInstance

	}//class OSInstance
}//namespace
