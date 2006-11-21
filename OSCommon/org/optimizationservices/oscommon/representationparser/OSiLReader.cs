using System;

using org.optimizationservices.oscommon.localinterface;

namespace org.optimizationservices.oscommon.representationparser{
	/// <summary>
	/// The <c>OSiLReader</c> class parses an OSiL instance into a DOM tree and
	/// provides a set of "get" methods (e.g. getVariableNames) that can be 
	/// used to retrieve different pieces of information of the instance.
	/// @author Jun Ma	
	/// @version 1.0, 09/01/2005
	/// @since OS 1.0
	/// @copyright (c) 2005
	/// </summary>
	public class OSiLReader : OSgLReader{

		/// <summary>
		/// m_osInstance holds the standard OSInstance, which is is a local interface for 
		/// storing Optimization Services problem input. 
		/// </summary>
		protected OSInstance m_osInstance = null;

		
		///	<summary>
		///	constructor.
		///	</summary>
		///	<param name="validate">holds whether the reader	should be validating against the schema	or not.</param>
		public OSiLReader(bool validate){
			m_bXsdValidate = validate;
		}//constructor
	
		///	<summary>
		///	Default	constructor. 
		///	</summary>
		public OSiLReader(){
		}//constructor

		/// <summary>
		/// get the standard OSInstance, a local interface for 
		/// storing Optimization Services problem instance.
		/// </summary>
		/// <returns>the OSInstance.</returns>
		public OSInstance getOSInstance(){
			if(m_osInstance != null){
				return m_osInstance;
			}
			m_osInstance = new OSInstance();
			//TODO
			return m_osInstance;
		}//getOSInstance

	}//class OSiLReader
}//namespace
