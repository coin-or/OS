/**
 * @(#)OSdL 1.0 03/14/2004
 *
 * Copyright (c) 2004
 */
package org.optimizationservices.oscommon.communicationinterface;

/**
 *
 * <P>The <code>OSdL</code> interface declares all the methods as specified in the 
 * Optimization Services (OS) Framework, specifically the Optimization Services discover 
 * Language (OSdL). These methods are called by an OS agent to  register, find and validate 
 * in an OS registry any OS services, such as OS solvers or analyzers.  
 * Any registry that wants to become an OS-type callable on the distributed system must implement 
 * this interface.  
 *
 * </p>
 * @author Robert Fourer, Jun Ma, Kipp Martin
 * @version 1.0, 03/14/2004
 * @since OS 1.0
 */
public interface OSdL{
	
	/**
	 * Discover an Optimization Service whose instance is given by a string following 
	 * the Optimization Services query Language (OSqL) schema and returns the location information
	 * in a string that follows the Optimization Services URI, or Universal Resource Indentifier 
	 * Language, (OSuL) schema.
	 * 
	 * </P>
	 *
	 * @param OSqL holds the Optimization Service query in a string which format follows the 
	 * Optimization Services query Language (OSqL) schema.  
	 * @param osol holds the optimization option in a string which format follows the 
	 * Optimization Services option Language (OSoL) schema.    
	 * @return the location information in a string that follows the Optimization Services URI, 
	 * or Universal Resource Indentifier Language, (OSuL) schema.
	 */
	public String find(String osql, String osol);
	
	/**
	 * register an Optimization Service whose instance is given by a string following 
	 * the Optimization Services entity Language (OSeL) schema and returns a string that contains 
	 * an XSLT style sheet transformation so that it can be used for standard web pubblication of the 
	 * Optimization Service that just joined. The XSLT is espcially used to publish the OSeL. 
	 * 
	 * </P>
	 * 
	 * @param osel holds the Optimization Service entity description in a string which format follows the 
	 * Optimization Services entity Language (OSeL) schema.  
	 * @param osol holds the optimization option in a string which format follows the 
	 * Optimization Services option Language (OSoL) schema.    
	 * @return the register process output information in a string which format follows the OSpL schema.
	 */
	public String register(String osel, String osol);

	/**
	 * Validate an osxl string according to the corresponding OSxL schema.
	 *
	 * </P>
	 *
	 * @param osxl holds the xml string to be validated. 
	 * @param osol holds the optimization option in a string which format follows the 
	 * Optimization Services option Language (OSoL) schema.    
	 * @return the validate process output information in a string which format follows the OSpL schema.
	 */	
	public String validate(String osxl, String osol);
	
	/**
	 * This method is called by one optimization service on another optimization service
	 * to provide runtime dynamic process information (push mechanism).
	 *
	 * </P>
	 * @param osplInput holds the input process information a string which format follows the Optimization
	 * Services process Language (OSpL) schema.
	 * @param osol holds the optimization option in a string which format follows the 
	 * Optimization Services option Language (OSoL) schema.    
	 * @return osplOutput, the ouput process information in a string which format follows the OSpL schema.
	 */
	public String knock(String osplInput, String osol);

	
}//interface OSdL
