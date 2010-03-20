/**
 * @(#)OSConstant 1.0 05/20/2005
 *
 * Copyright (c) 2005 Impact 
 */
package org.optimizationservices.oscommon.util;

/**
 *
 * <P>The <code>OSConstant</code> class stores predefined constants (public, static and final)
 * used in other Optimization Services classes.  
 *  
 *
 * </p>
 * @author Robert Fourer, Jun Ma, Kipp Martin
 * @version 1.0, 03/14/2004
 * @since OS 1.0
*/
public class OSConstant{
	/**
	 *
	 * Default constructor. 
	 */
	public OSConstant(){
	}//constructor

	/*---------------------------------------------
	Routine/maintenance related constants
	---------------------------------------------*/	

	/// <summary>
	///OUTPUT
	/// </summary>
	public static final int STD_ERR = 0;
	public static final int STD_OUT = 1;
	public static final int FILE_OUT = 2;
	public static final int STRING_OUT = 3;

	
	/**
	 * JODID_DELIMITER holds the delimiter used in creating a job id. 
	 */
	public static final String JODID_DELIMITER = "__";
	
	/*---------------------------------------------
	Time related parameters
	---------------------------------------------*/	
	/**
	 * STANDARD_UNIX_EPOCH holds the Unix epoch time (1970/1/1) in the standard xs:date format. 
	 */
	public static final String STANDARD_UNIX_EPOCH = "1970-01-01T00:00:00-00:00";
	
	/**
	 * MILLISECONDS_PER_DAY holds the milliseconds in a day. 
	 */
	public static final int MILLISECONDS_PER_DAY = 86400000;
	
	/*---------------------------------------------
	Service site related constants
	---------------------------------------------*/	

	
	/*---------------------------------------------
	Exception related constants
	---------------------------------------------*/
	/**
	 * exception type
	 */
	public static final int FATAL_ERROR = 1; 
	public static final int ERROR = 2; 
	public static final int WARNING = 3; 
	public static final int OPTIMIZATION = 4; 
	public static final int SERVICES = 5;

	/*---------------------------------------------
	WEBSERVICES related constants
	---------------------------------------------*/
	public static final String XML_ENCODING_STYLE = "http://schemas.xmlsoap.org/soap/encoding";
	/*---------------------------------------------
	XQUERY related constants
	---------------------------------------------*/
	/*---------------------------------------------
	XPATH related constants
	---------------------------------------------*/
	/*---------------------------------------------
	XSLT related constants
	---------------------------------------------*/
	/**
	 * XSLT_TANSFORMER_FEATURE holds the constant for xslt transformer feature.
	 */
	public static final String XSLT_TANSFORMER_FEATURE = "javax.xml.transform.TransformerFactory";
	
	/**
	 * XSLT_TANSFORMER_CLASS holds the constant for Saxon 7 xslt transformer.
	 */
	public static final String XSLT_TANSFORMER_SAXON7 = "net.sf.saxon.TransformerFactoryImpl";
	
	/**
	 * XSLT_TANSFORMER_CLASS holds the constant for Saxon 7 xslt transformer.
	 */
	public static final String XSLT_TANSFORMER_SAXON6 = "com.icl.saxon.TransformerFactoryImpl";
	
	/**
	 * XSLT_TANSFORMER_CLASS holds the constant for Xalan xslt transformer.
	 */
	public static final String XSLT_TANSFORMER_XALAN = "org.apache.xalan.processor.TransformerFactoryImpl";

	/*---------------------------------------------
	XML related constants
	---------------------------------------------*/

	/**
	 * SAX_PARSER_FEATURE holds the constant of the sax parser feature.
	 */
	public static final String SAX_PARSER_FEATURE = "org.xml.sax.driver";
	
	/**
	 * SAX_PARSER_CLASS holds the constant of the actual xerces class that does SAX parsing.
	 */
	public static final String SAX_PARSER_XERCES = "org.apache.xerces.parsers.SAXParser";
	
	/**
	 * SAX_VALIDATION_FEATURE holds the constant for whether to set validation feature or not.
	 */
	public static final String SAX_VALIDATION_FEATURE = "http://xml.org/sax/features/validation";
	
	/**
	 * SCHEMA_FEATURE holds the constant for whether to set the schema validation feature or not.
	 */
	public static final String SCHEMA_FEATURE = "http://apache.org/xml/features/validation/schema";
	
	/**
	 * EXTERNAL_SCHEMA holds the constant for the external schema location property.
	 */
	public static final String EXTERNAL_SCHEMA = "http://apache.org/xml/properties/schema/external-schemaLocation";
	
	/**
	 * EXTERNAL_NONAMESPACE_SCHEMA holds the constant for the external no namespace schema location property.
	 */
	public static final String EXTERNAL_NONAMESPACE_SCHEMA = "http://apache.org/xml/properties/schema/external-noNamespaceSchemaLocation";
	
	/**
	 * NAMESPACE_PREFIXES holds the the constant used to indicate namespace prefixes awareness feature.
	 */
	public static final String NAMESPACE_PREFIXES = "http://xml.org/sax/features/namespace-prefixes";
	
	/**
	 * JAXP_SCHEMA_LANGUAGE holds the the constant used to indicate JAXP parser schema language attribute.
	 */
	public static final String JAXP_SCHEMA_LANGUAGE = "http://java.sun.com/xml/jaxp/properties/schemaLanguage";
	
	/**
	 * NAMESPACE_PREFIXES holds the the constant used to indicate JAXP parser schema source attribute.
	 */
	public static final String JAXP_SCHEMA_SOURCE = "http://java.sun.com/xml/jaxp/properties/schemaSource";
	
	/**
	 * NAMESPACE_PREFIXES holds the the constant used to indicate W3C XML Schema attribute.
	 */
	public static final String W3C_XML_SCHEMA = "http://www.w3c.org/2001/XMLSchema";
	
	/**
	 * XMLNS_XS_VALUE holds the value of the attribute name "xmlns:xs", usually an attribute of many XML documents to define a the namespace "xs", i.e. XML schema.
	 */
	public static final String XMLNS_XS_VALUE = "http://www.w3.org/2001/XMLSchema";
	
	/**
	 * XMLNS_XSI_VALUE holds the value of the attribute name "xmlns:xsi", usually an attribute of many XML documents to define a the namespace "xsi", i.e. XML schema instance.
	 */
	public static final String XMLNS_XSI_VALUE = "http://www.w3.org/2001/XMLSchema-instance";
	
	/**
	 * FML_NAMESPACE holds the value of the FML namespace.
	 */
	public static final String FML_NAMESPACE = "http://FML/lpfml.xsd";
	
	/**
	 * OS_NAMESPACE holds the value of the all the OSxL schema namespace.
	 */
	public static final String OS_NAMESPACE = "os.optimizationservices.org";
			
	/**
	 * main for test purposes.
	 *
	 * </p>
	 *
	 * @param argv command line arguments.
	 */
	public static void main(String[] args){
		
	}//main
}//OSConstant
