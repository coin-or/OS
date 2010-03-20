/**
 * @(#)NewsElement 1.0 03/14/2004
 *
 * Copyright (c) 2004
 */
package org.optimizationservices.oscommon.datastructure.osgeneral;

import java.util.GregorianCalendar;


/**
 *
 * <p>A data structure class that corresponds to an xml element in the OSgL schema.  
 *  
 * </p>
 * @author Robert Fourer, Jun Ma, Kipp Martin
 * @version 1.0, 03/14/2004
 * @since OS 1.0
*/
public class NewsElement{

	public GregorianCalendar time = new GregorianCalendar();
	
	public String value = "";
	
}//class NewsElement
