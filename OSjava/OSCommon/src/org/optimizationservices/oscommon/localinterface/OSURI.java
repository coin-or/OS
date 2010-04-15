/**
 * @(#)OSURI 1.0 03/14/2005
 *
 * Copyright (c) 2005 
 */
package org.optimizationservices.oscommon.localinterface;

import org.optimizationservices.oscommon.datastructure.osuri.URI;
import org.optimizationservices.oscommon.representationparser.OSuLReader;
import org.optimizationservices.oscommon.representationparser.OSuLWriter;

/**
*
* <P>The <code>OSURI</code> class is a local interface for storing Optimization Services
* uri. Its design follows the Optimization Services uri Language (OSuL). 
* All the data structures in this class are standards specified in OSuL. 
*
* @author Robert Fourer, Jun Ma, Kipp Martin
* @version 1.0, 03/14/2005
* @since OS 1.0
*/

public class OSURI {	

	/**
	 * uri holds an array of URIs. 
	 */
	public URI[] uri = null;

	/**
	 *
	 * Default constructor. 
	 */
	public OSURI(){
	}//constructor
	
	/**
	 * read an OSuL instance and return and OSURI object.  
	 * 
	 * @param osul holds the optimization uri in a string which format follows the
	 * Optimization Services uri Language (OSuL) schema.
	 * @param isFile holds whether the osul string is a file name or a string that literally holds the osul contents.  
	 * @param validate holds whether the reader should be validating against the schema or not.
	 * @return the OSURI object constructed from the OSuL String.  
	 * @throws Exception if there are errors in reading the string or setting the OSURI. 
	 */
   	public OSURI readOSuL(String osul, boolean isFile, boolean validate) throws Exception{
   		OSuLReader osulReader = new OSuLReader(validate);
		boolean bRead = false;
		if(isFile){
			bRead = osulReader.readFile(osul);
		}
		else{
			bRead = osulReader.readString(osul);			
		}
		if(!bRead) throw new Exception("OSuL string not valid");
		return osulReader.getOSURI();
   	}//readOSuL
   	
   	/**
   	 * write the OSURI to an osul xml string. 
   	 * 
   	 * @return the osul xml string. 
	 * @throws Exception if there are errors in writing the osul string. 
   	 */
   	public String writeOSuL() throws Exception{
		OSuLWriter osulWriter = new OSuLWriter();
		osulWriter.setOSURI(this);
		return osulWriter.writeToString();
   	}//writeOSuL
   	
	/**
	 * Get URI matches. 
	 * 
	 * @return an array of URIs, null if none. 
	 * Each member of the URI array is of a URI data structure. It contains information such as  
	 * the uri value, matchType, serviceName, licenceRequired, userNameRequired, passwordRequired.
	 * @see org.optimizationservices.oscommon.datastructure.osuri.URI
	 */
	public URI[] getURIMatches(){
		return uri;
	}//getURIMatches
	
	/**
	 * Set URI matches. 
	 * 
	 * @param URIs holds an array of URIs. 
	 * Each member of the URI array is of a URI data structure. It contains information such as  
	 * the uri value, matchType, serviceName, licenceRequired, userNameRequired, passwordRequired.
	 * @return whether the URIs are set successfully or not. 
	 * @see org.optimizationservices.oscommon.datastructure.osuri.URI
	 */
	public boolean setURIMatches(URI[] URIs){
		uri = URIs;
		return true;
	}//setURIMatches
	
	/**
	 * main for test purposes.
	 *
	 * </p>
	 *
	 * @param argv command line arguments.
	 */
	public static void main(String[] args){

	}//main
}//class OSURI

