using System;
using org.optimizationservices.oscommon.localinterface;

namespace org.optimizationservices.oscommon.representationparser{
	/// <summary>
	/// The <c>OSiLWriter</c> class is used to construct an optimization instance that follows 
	/// the Optimization Services instance Language format. Each element declared in the OSiL 
	/// Schema has a corresponding protected element creation method (e.g. createEl for 
	/// creation of element el). User do not have direct access to any of these 
	/// protected methods. They get to manipulate the output of OSiL construction through a 
	/// group of higher level optimization related public "set" methods (e.g. setConstraints).
	/// The "set" methods are the opposite "get" method in the corresponding OSiLReader class. 
	/// Each method checks within itself the argument consistency against OSiL Schema at 
	/// the syntax level. There is no specific sequence the user should follow to 
	/// invoke these set methods. User can call the same set methods several times. If 
	/// the parameters are different, old values will be replaced by new ones. Users should, 
	/// though, make sure values submitted through different "set" methods are consistent, 
	/// i.e. logically correct.For example if variableCount in #setDescription 
	/// is set to 2, then the variableLbs array in #setVariables 
	/// has to have a length 2. 
	/// The OSiLWriter class also provides auxiliary facilities to write the xml 
	/// to different output. 
	/// The OSiLWriter class does not support writing mathML related elements.
	/// @author Jun Ma	
	/// @version 1.0, 09/01/2005
	/// @since OS 1.0
	/// @copyright (c) 2005
	/// </summary>
	public class OSiLWriter: OSgLWriter{
	
		/// <summary>
		/// Default constructor. 
		/// </summary>
		public OSiLWriter(){
		}//constructor

		/// <summary>
		/// set the OSInstance, a standard os instance interface. 
		/// </summary>
		/// <param name="osInstance">holds the standard os instance interface. </param>
		/// <returns>whether the OSInstance is set successfully. </returns>
		public bool setOSInstance(OSInstance osInstance){
			//TODO
			return true;
		}//setOSInstance

		///TODO: implement OSiLWriter and all other OSxLWriter

	}//class OSiLWriter
}//namespace
