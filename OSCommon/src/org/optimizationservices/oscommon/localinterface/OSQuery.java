/**
 * @(#)OSQuery 1.0 03/14/2005
 *
 * Copyright (c) 2005 
 */
package org.optimizationservices.oscommon.localinterface;

import org.optimizationservices.oscommon.datastructure.osquery.StandardQuery;
import org.optimizationservices.oscommon.representationparser.OSqLReader;
import org.optimizationservices.oscommon.representationparser.OSqLWriter;

/**
*
* <P>The <code>OSQuery</code> class is a local interface for storing Optimization Services
* query. Its design follows the Optimization Services query Language (OSqL). 
* All the data structures in this class are standards specified in OSqL. 
*
* @author Robert Fourer, Jun Ma, Kipp Martin
* @version 1.0, 03/14/2005
* @since OS 1.0
*/

public class OSQuery {
	
	/**
	 * standard holds the pre-built standard query keywords in the StandardQuery data structure. 
	 */
	public StandardQuery standard = null;

	/**
	 * xQuery holds the query in the W3C XQuery format. 
	 */
	public String xQuery = "";

	/**
	 *
	 * Default constructor. 
	 */
	public OSQuery(){
	}//constructor
	
	/**
	 * read an OSqL instance and return and OSQuery object.  
	 * 
	 * @param osql holds the optimization query in a string which format follows the
	 * Optimization Services query Language (OSqL) schema.
	 * @param isFile holds whether the osql string is a file name or a string that literally holds the osql contents.  
	 * @param validate holds whether the reader should be validating against the schema or not.
	 * @return the OSQuery object constructed from the OSqL String.  
	 * @throws Exception if there are errors in reading the string or setting the OSQuery. 
	 */
   	public OSQuery readOSqL(String osql, boolean isFile, boolean validate) throws Exception{
   		OSqLReader osqlReader = new OSqLReader(validate);
		boolean bRead = false;
		if(isFile){
			bRead = osqlReader.readFile(osql);
		}
		else{
			bRead = osqlReader.readString(osql);			
		}
		if(!bRead) throw new Exception("OSqL string not valid");
		return osqlReader.getOSQuery();
   	}//readOSqL
   	
   	/**
   	 * write the OSQuery to an osql xml string. 
   	 * 
   	 * @return the osql xml string. 
	 * @throws Exception if there are errors in writing the osql string. 
   	 */
   	public String writeOSqL() throws Exception{
		OSqLWriter osqlWriter = new OSqLWriter();
		osqlWriter.setOSQuery(this);
		return osqlWriter.writeToString();
   	}//writeOSqL
   	
	/**
	 * get the standard query data structure.  
	 * 
	 * @return standard query in the StandardQuery data structure; null if none.  
	 * @see org.optimizationservices.oscommon.datastructure.osquery.StandardQuery
	 */
	public StandardQuery getStandardQuery(){
		return standard;
	}//getStandardQuery
	
	/**
	 * set the standard query. 
	 * @param standardQuery holds the standard query in the StandardQuery data structure. 
	 * @return whether the standard query is set successfully. 
	 * @see org.optimizationservices.oscommon.datastructure.osquery.StandardQuery
	 */
	public boolean setStandardQuery(StandardQuery standardQuery){
		standard = standardQuery;
		return true;
	}//setStandardQuery
	

 	/**
	 * Get the xQuery in a string.  
	 * 
	 * 
	 * @return the xQuery, null or empty string if none. 
	 */
	public String getXQuery(){
		return xQuery;
	}//getXQuery
	
 	/**
	 * Set the XQuery. 
	 * 
	 * 
	 * @param xQuery holds the XQuery in a string. 
	 * @return whether the XQuery is set successfully or not. 
	 */
	public boolean setXQuery(String xQuery){
		this.xQuery = xQuery;
		return true;
	}//setXQuery

	
	/**
	 * main for test purposes.
	 *
	 * </p>
	 *
	 * @param argv command line arguments.
	 */
	public static void main(String[] args){
		
	}//main
}//class OSQuery

