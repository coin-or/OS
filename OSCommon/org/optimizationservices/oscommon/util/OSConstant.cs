using System;

namespace org.optimizationservices.oscommon.util{
	/// <summary>
	/// The <c>OSConstant</c> class stores predefined constants (public, static and const)
	/// used in other classes. 
	/// @author Jun Ma	
	/// @version 1.0, 09/01/2005
	/// @since OS 1.0
	/// @copyright (c) 2005
	/// </summary>
	public abstract class OSConstant{
		/// <summary>
		/// Default constructor. 
		/// </summary>
		public OSConstant(){
		}//constructor
		
		/*---------------------------------------------
		Routine/maintenance related constants
		---------------------------------------------*/
		
		
		/// <summary>
		///OUTPUT
		/// </summary>
		public const int STD_ERR = 0;
		public const int STD_OUT = 1;
		public const int FILE_OUT = 2;
		public const int STRING_OUT = 3;

		/// <summary>
		///J ODID_DELIMITER holds the delimiter used in creating a job id. 
		/// </summary>
		public const string JODID_DELIMITER = "__";

				
		/*---------------------------------------------
		Time related parameters
		---------------------------------------------*/		
		/// <summary>
		/// STANDARD_UNIX_EPOCH holds the Unix epoch time (1970/1/1) in the standard xs:date format. 
		/// </summary>
		public const String STANDARD_UNIX_EPOCH = "1970-01-01T00:00:00-00:00";
		
		/// <summary>
		/// MILLISECONDS_PER_DAY holds the milliseconds in a day. 
		/// </summary>
		public const int MILLISECONDS_PER_DAY = 86400000;


		/*---------------------------------------------
		Service site related constants
		---------------------------------------------*/		

		/*---------------------------------------------
		Exception related constants
		---------------------------------------------*/
		/// <summary>
		/// exception type
		/// </summary>
		public const int FATAL_ERROR = 1; 
		public const int ERROR = 2; 
		public const int WARNING = 3; 
		public const int OPTIMIZATION = 4; 
		public const int SERVICES = 5;

		/*---------------------------------------------
		WEBSERVICES related constants
		---------------------------------------------*/


		/*---------------------------------------------
		XQUERY related constants
		---------------------------------------------*/


		/*---------------------------------------------
		XPATH related constants
		---------------------------------------------*/


		/*---------------------------------------------
		XSLT related constants
		---------------------------------------------*/
		/// <summary>
		/// XSLT_TANSFORMER_FEATURE holds the constant for xslt transformer feature.
		/// </summary>
		public const string XSLT_TANSFORMER_FEATURE = "javax.xml.transform.TransformerFactory";
		
		/// <summary>
		/// XSLT_TANSFORMER_CLASS holds the constant for Saxon 7 xslt transformer.
		/// </summary>
		public const string XSLT_TANSFORMER_SAXON7 = "net.sf.saxon.TransformerFactoryImpl";
		
		/// <summary>
		/// XSLT_TANSFORMER_CLASS holds the constant for Saxon 7 xslt transformer.
		/// </summary>
		public const string XSLT_TANSFORMER_SAXON6 = "com.icl.saxon.TransformerFactoryImpl";
		
		/// <summary>
		/// XSLT_TANSFORMER_CLASS holds the constant for Xalan xslt transformer.
		/// </summary>
		public const string XSLT_TANSFORMER_XALAN = "org.apache.xalan.processor.TransformerFactoryImpl";

		/*---------------------------------------------
		XML related constants
		---------------------------------------------*/
		/// <summary>
		/// SAX_PARSER_FEATURE holds the constant of the sax parser feature.
		/// </summary>
		public const string SAX_PARSER_FEATURE = "org.xml.sax.driver";
	
		/// <summary>
		/// SAX_PARSER_CLASS holds the constant of the actual xerces class that does SAX parsing.
		/// </summary>
		public const string SAX_PARSER_XERCES = "org.apache.xerces.parsers.SAXParser";
	
		/// <summary>
		/// SAX_VALIDATION_FEATURE holds the constant for whether to set validation feature or not.
		/// </summary>
		public const string SAX_VALIDATION_FEATURE = "http://xml.org/sax/features/validation";
	
		/// <summary>
		/// SCHEMA_FEATURE holds the constant for whether to set the schema validation feature or not.
		/// </summary>
		public const string SCHEMA_FEATURE = "http://apache.org/xml/features/validation/schema";
	
		/// <summary>
		/// EXTERNAL_SCHEMA holds the constant for the external schema location property.
		/// </summary>
		public const string EXTERNAL_SCHEMA = "http://apache.org/xml/properties/schema/external-schemaLocation";
	
		/// <summary>
		/// EXTERNAL_NONAMESPACE_SCHEMA holds the constant for the external no namespace schema location property.
		/// </summary>
		public const string EXTERNAL_NONAMESPACE_SCHEMA = "http://apache.org/xml/properties/schema/external-noNamespaceSchemaLocation";
	
		/// <summary>
		/// NAMESPACE_PREFIXES holds the the constant used to indicate namespace prefixes awareness feature.
		/// </summary>
		public const string NAMESPACE_PREFIXES = "http://xml.org/sax/features/namespace-prefixes";
	
		/// <summary>
		/// JAXP_SCHEMA_LANGUAGE holds the the constant used to indicate JAXP parser schema language attribute.
		/// </summary>
		public const string JAXP_SCHEMA_LANGUAGE = "http://java.sun.com/xml/jaxp/properties/schemaLanguage";
	
		/// <summary>
		/// NAMESPACE_PREFIXES holds the the constant used to indicate JAXP parser schema source attribute.
		/// </summary>
		public const string JAXP_SCHEMA_SOURCE = "http://java.sun.com/xml/jaxp/properties/schemaSource";
		
		/// <summary>
		/// NAMESPACE_PREFIXES holds the the constant used to indicate W3C XML Schema attribute.
		/// </summary>
		public const string W3C_XML_SCHEMA = "http://www.w3c.org/2001/XMLSchema";
	
		/// <summary>
		/// XMLNS_XS_VALUE holds the value of the attribute name "xmlns:xs", usually an attribute of many XML documents to define a the namespace "xs", i.e. XML schema.
		/// </summary>
		public const string XMLNS_XS_VALUE = "http://www.w3.org/2001/XMLSchema";
		
		/// <summary>
		/// XMLNS_XSI_VALUE holds the value of the attribute name "xmlns:xsi", usually an attribute of many XML documents to define a the namespace "xsi", i.e. XML schema instance.
		/// </summary>
		public const string XMLNS_XSI_VALUE = "http://www.w3.org/2001/XMLSchema-instance";
	
		/// <summary>
		/// FML_PUBLIC_SITE holds the value of the FML schema public site.
		/// </summary>
		public const string FML_PUBLIC_SITE = "http://gsbkip.chicagogsb.edu/fml/testproblems/lpfml.xsd";
		
		/// <summary>
		/// FML_NAMESPACE holds the value of the FML namespace.
		/// </summary>
		public const string FML_NAMESPACE = "http://FML/lpfml.xsd";
	
		/// <summary>
		/// OS_NAMESPACE holds the value of the all the OSxL schema namespace.
		/// </summary>
		public const string OS_NAMESPACE = "os.optimizationservices.org";
	
	}//class OSConstant
}//namespace


