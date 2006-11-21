using System;
using System.Collections;

using org.optimizationservices.oscommon.datastructure.osquery;
using org.optimizationservices.oscommon.localinterface;
using org.optimizationservices.oscommon.representationparser;

namespace org.optimizationservices.oscommon.localinterface{
	/// <summary>
	/// The <c>OSQuery</c> class is a local interface for storing OS 
	/// query. Its design follows the OSqL. Naming, structuring and layering 
	/// all are exactly the same as those in the OSqL schema. 
	/// @author Jun Ma	
	/// @version 1.0, 09/01/2005
	/// @since OS 1.0
	/// @copyright (c) 2005
	/// </summary>
	public class OSQuery{

		/// <summary>
		/// standard holds the pre-built standard query keywords in the StandardQuery data structure.
		/// </summary>
		public StandardQuery standard = new StandardQuery();

		/// <summary>
		/// xQuery holds the query in the W3C XQuery format. 
		/// </summary>
		public string xQuery = "";
			
		/// <summary>
		/// Default constructor. 
		/// </summary>
		public OSQuery(){

		}//constructor

		/// <summary>
		/// read an OSqL instance and return and OSQuery object.  
		/// @throws Exception if there are errors in reading the string or setting the OSQuery. 
		/// </summary>
		/// <param name="osql">holds the optimization query in a string which format follows the
		/// Optimization Services query Language (OSqL) schema</param>
		/// <param name="isFile">isFile holds whether the osql string is a file name or a string that literally holds the osql contents.  </param>
		/// <param name="validate">holds whether the reader should be validating against the schema or not.</param>
		/// <returns>the OSQuery object constructed from the OSqL String.  </returns>
		public OSQuery readOSqL(string osql, bool isFile, bool validate){
			OSqLReader osqlReader = new OSqLReader(validate);
			bool bRead = false;
			if(isFile){
				bRead = osqlReader.readFile(osql);
			}
			else{
				bRead = osqlReader.readString(osql);			
			}
			if(!bRead) throw new Exception("OSqL string not valid");
			return osqlReader.getOSQuery();
		}//readOSqL
	   
		/// <summary>
		/// write the OSQuery to an osql xml string. 
		/// @throws Exception if there are errors in writing the osql string. 
		/// </summary>
		/// <returns>the osql xml string. </returns>
		public string writeOSqL(){
			OSqLWriter osqlWriter = new OSqLWriter();
			osqlWriter.setOSQuery(this);
			return osqlWriter.writeToString();
		}//writeOSqL

		/// <summary>
		/// get the standard query data structure.  
		/// @see org.optimizationservices.oscommon.datastructure.osquery.StandardQuery
		/// </summary>
		/// <returns>standard query in the StandardQuery data structure; null if none.  </returns>
		public StandardQuery getStandardQuery(){
			return standard;
		}//getStandardQuery
	
		/// <summary>
		/// set the standard query. 
		/// @see org.optimizationservices.oscommon.datastructure.osquery.StandardQuery
		/// </summary>
		/// <param name="standardQuery">holds the standard query in the StandardQuery data structure. </param>
		/// <returns>whether the standard query is set successfully. </returns>
		public bool setStandardQuery(StandardQuery standardQuery){
			standard = standardQuery;
			return true;
		}//setStandardQuery

		/// <summary>
		/// Get the xQuery in a string.  
		/// </summary>
		/// <returns>the xQuery. </returns>
		public string getXQuery(){
			return xQuery;
		}//getXQuery

		/// <summary>
		/// Set the XQuery. 
		/// </summary>
		/// <param name="xQuery">holds the XQuery in a string. </param>
		/// <returns>whether the XQuery is set successfully or not. </returns>
		public bool setXQuery(string xQuery){
			this.xQuery = xQuery;
			return true;
		}//setXQuery

	
	}//class OSQuery
}//namespace
