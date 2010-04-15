/**
 * @(#)XSLTUtil 1.0 03/14/2004
 *
 * Copyright (c) 2004
 */
package org.optimizationservices.oscommon.util;

import java.io.ByteArrayOutputStream;
import java.io.File;

import javax.xml.transform.OutputKeys;
import javax.xml.transform.Templates;
import javax.xml.transform.Transformer;
import javax.xml.transform.TransformerFactory;
import javax.xml.transform.stream.StreamResult;
import javax.xml.transform.stream.StreamSource;

/**
 *
 * <P>The <code>XSLTUtil</code> class contains methods for performing
 * common basic XSLT-related operations used by various classes in the
 * Optimization Services (OS) framework. </p>
 *
 * </p>
 *
 * @author  Robert Fourer, Jun Ma, Kipp Martin
 * @version 1.0, 03/14/2004
 * @since   OS1.0
 */

public class XSLTUtil{
	/**
	 * Create an xslt transformer from an xslt transformation file.
	 *
	 * </p>
	 *
	 * @param xsltFileName holds the xslt file that does the transformation from xml input to xml output.
	 * @return an xslt transformer from the xslt transformation file.
	 */
	public static Transformer createTransformerFromFile(String xsltFileName){
		try{
			System.setProperty(OSConstant.XSLT_TANSFORMER_FEATURE, OSConstant.XSLT_TANSFORMER_SAXON7);
			System.setProperty(OSConstant.SAX_PARSER_FEATURE,OSConstant.SAX_PARSER_XERCES);
			
			TransformerFactory factory = TransformerFactory.newInstance();
			Templates initialTemplates = factory.newTemplates(new StreamSource(xsltFileName));
			Transformer xsltTransformer = initialTemplates.newTransformer();
			xsltTransformer.setOutputProperty(OutputKeys.METHOD, "xml");
			return xsltTransformer;
		}
		catch (Exception e) {
			e.printStackTrace();
			return null;
		}
	}//createTransformerFromFile
	
	/**
	 * Create an xslt transformer from an xslt string.
	 *
	 * </p>
	 *
	 * @param xsltString holds the xslt string that does the transformation from xml input to xml output.
	 * @return an xslt transformer from the xslt transformation string.
	 */
	public static Transformer createTransformerFromString(String xsltString){
		try{
			System.setProperty(OSConstant.XSLT_TANSFORMER_FEATURE, OSConstant.XSLT_TANSFORMER_SAXON7);
			System.setProperty(OSConstant.SAX_PARSER_FEATURE,OSConstant.SAX_PARSER_XERCES);
			
			TransformerFactory factory = TransformerFactory.newInstance();
			Templates initialTemplates = factory.newTemplates(new StreamSource(IOUtil.stringToInputStream(xsltString)));
			Transformer xsltTransformer = initialTemplates.newTransformer();
			xsltTransformer.setOutputProperty(OutputKeys.METHOD, "xml");
			return xsltTransformer;
		}
		catch (Exception e) {
			e.printStackTrace();
			return null;
		}
	}//createTransformerFromString
	
	/**
	 * Transform an xml file input to an xml file output according to an xslt transformation file.
	 *
	 * </p>
	 *
	 * @param inputFileName holds the name of the input xml file to be transformed.
	 * @param xsltFileName holds the xslt file that does the transformation from xml input to xml output.
	 * @param outputFilename holds the name of the output xml file to save the transformed result.
	 * @return whether the transformation is carried out succesfully or not.
	 */
	public static boolean transformFile(String inputFileName, String xsltFileName, String outputFilename){
		try{
			Transformer xsltTransformer = createTransformerFromFile(xsltFileName);
			xsltTransformer.transform(new StreamSource(inputFileName), new StreamResult(new File(outputFilename)) );
			return true;
		}
		catch(Exception e) {
			e.printStackTrace();
			return false;
		}
	}//transformFile
	
	/**
	 * Transform an xml string input and return an xml string output according to an xslt transformation string.
	 *
	 * </p>
	 *
	 * @param inputFileName holds the name of the input xml file to be transformed.
	 * @param xsltFileName holds the xslt file that does the transformation from xml input to xml output.
	 * @return
	 */
	public static String transformString(String inputString, String xsltString){
		try{
			Transformer xsltTransformer = createTransformerFromString(xsltString);
			ByteArrayOutputStream bos = new ByteArrayOutputStream();
			xsltTransformer.transform(new StreamSource(IOUtil.stringToInputStream(inputString)), new StreamResult(bos));
			return bos.toString();
		}
		catch (Exception e) {
			e.printStackTrace();
			return null;
		}
	}//transformString
	
	/**
	 * main for test purposes.
	 *
	 * </p>
	 *
	 * @param argv command line arguments.
	 */
	public static void main(String[] args){
		String rawDataXML = "xml/lpfml/parinc.xml";
		String initialStylesheet = "xml/lpfml/fml.xsl";
		String tmpfilename = "xml/lpfml/xsltresult.html";
		long start = System.currentTimeMillis();
		transformFile(rawDataXML, initialStylesheet, tmpfilename);
		long finish = System.currentTimeMillis();
		System.out.println("CPU Time =  " +  Long.toString(finish - start));
	}//main
	
}//class XSLTUtil
