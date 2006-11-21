using System;

namespace org.optimizationservices.oscommon.util{
	/// <summary>
	/// The <c>OSParameter</c> class stores predefined parameters (public and static)
	/// used in other classes. 
	/// @author Jun Ma	
	/// @version 1.0, 09/01/2005
	/// @since OS 1.0
	/// @copyright (c) 2005
	/// </summary>
	public class OSParameterFile{

		/// <summary>
		/// Default constructor. 
		/// </summary>
		public OSParameterFile(){
			
		}//constructor

		/// <summary>
		/// NAME holds the file name that keeps the parameter information. 
		/// </summary>
		public static string NAME = "c:/code/OSConfig/OSParameter.xml";
	}//class OSParameterFile
}//namespace
