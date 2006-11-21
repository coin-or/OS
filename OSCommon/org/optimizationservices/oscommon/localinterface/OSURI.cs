using System;

using org.optimizationservices.oscommon.datastructure.osuri;
using org.optimizationservices.oscommon.representationparser;

namespace org.optimizationservices.oscommon.localinterface{
	/// <summary>
	/// The <c>OSURI</c> class is a local interface for storing OS 
	/// uri. Its design follows the OSuL. Naming, structuring and layering 
	/// all are exactly the same as those in the OSuL schema. 
	/// @author Jun Ma	
	/// @version 1.0, 09/01/2005
	/// @since OS 1.0
	/// @copyright (c) 2005
	/// </summary>
	public class OSURI{
	
		/// <summary>
		/// uri holds an array of URIs.  
		/// </summary>
		public URI[] uri = null;

			
		/// <summary>
		/// Default constructor. 
		/// </summary>
		public OSURI(){

		}//constructor

		/// <summary>
		/// read an OSuL instance and return and OSURI object.  
		/// @throws Exception if there are errors in reading the string or setting the OSURI. 
		/// </summary>
		/// <param name="osul">holds the optimization uri in a string which format follows the
		/// Optimization Services uri Language (OSuL) schema</param>
		/// <param name="isFile">isFile holds whether the osul string is a file name or a string that literally holds the osul contents.  </param>
		/// <param name="validate">holds whether the reader should be validating against the schema or not.</param>
		/// <returns>the OSURI object constructed from the OSuL String.  </returns>
		public OSURI readOSuL(string osul, bool isFile, bool validate){
			OSuLReader osulReader = new OSuLReader(validate);
			bool bRead = false;
			if(isFile){
				bRead = osulReader.readFile(osul);
			}
			else{
				bRead = osulReader.readString(osul);			
			}
			if(!bRead) throw new Exception("OSuL string not valid");
			return osulReader.getOSURI();
		}//readOSuL
	   
		/// <summary>
		/// write the OSURI to an osul xml string. 
		/// @throws Exception if there are errors in writing the osul string. 
		/// </summary>
		/// <returns>the osul xml string. </returns>
		public string writeOSuL(){
			OSuLWriter osulWriter = new OSuLWriter();
			osulWriter.setOSURI(this);
			return osulWriter.writeToString();
		}//writeOSuL

		/// <summary>
		/// Get URI matches. 
		/// @see org.optimizationservices.oscommon.datastructure.osuri.URI
		/// </summary>
		/// <returns>an array of URIs, null if none.
		/// Each member of the URI array is of a URI data structure. 
		/// It contains information such as  
		/// the uri value, matchType, serviceName, licenceRequired, userNameRequired, passwordRequired
		/// </returns>
		public URI[] getURIMatches(){
			return uri;
		}//getURIMatches

		/// <summary>
		/// Set URI matches. 
		/// @see org.optimizationservices.oscommon.datastructure.osuri.URI
		/// </summary>
		/// <param name="URIs">holds an array of URIs. 
		/// Each member of the URI array is of a URI data structure.
		/// It contains information such as  
		/// the uri value, matchType, serviceName, licenceRequired, userNameRequired, passwordRequired
		/// </param>
		/// <returns>whether the URIs are set successfully or not. </returns>
		public bool setURIMatches(URI[] URIs){
			uri = URIs;
			return true;
		}//setURIMatches
	}//class OSURI
}//namespace
