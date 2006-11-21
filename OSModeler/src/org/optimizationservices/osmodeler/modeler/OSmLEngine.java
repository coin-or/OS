/**
 * @(#)OSmLEngine 1.0 03/14/2004
 *
 * Copyright (c) 2004
 */
package org.optimizationservices.osmodeler.modeler;

import java.io.ByteArrayInputStream;
import java.io.InputStream;
import java.util.List;

import org.optimizationservices.oscommon.communicationagent.OSSolverAgent;
import org.optimizationservices.oscommon.util.IOUtil;
import org.optimizationservices.oscommon.util.XQueryUtil;
import org.optimizationservices.osmodeler.parser.osml.OSmLPreParser;
import org.optimizationservices.osmodeler.parser.osml.OSmLQueryResultToOSiL;

/**
 *
 * <P>The <code>OSmLEngine</code> class interprets the XQuery based Optimization Services 
 * Modeling Language model and compiles the model into an Optimization Services instance
 * Language (OSiL) low level representation.</p>
 *
 * </p>
 *
 * @author Robert Fourer, Jun Ma, Kipp Martin
 * @version 1.0, 03/14/2004
 * @see org.optimizationservices.osmodeler.parser.OSmLPreParser
 * @since OS 1.0
 */
public class OSmLEngine {
	/**
	 * preparsedModel is the preparsed model from OSmL in the first stage parsing. It
	 * is a pure XQuery Language. 
	 */
	public String preparsedModel = "";

	/**
	 * queryResult is the xml intermediate result after executing the XQuery language.
	 */
	public String queryResult = "";

	/**
	 * osilInstance is the xml instance language, that follows the OSiL schema. It is the input to other 
	 * Optimization Services, such as solvers. 
	 */
	public String osilInstance = "";

	/**
	 * constructor
	 */
	public OSmLEngine() {

	}//constructor

	/**
	 * <p>Interpret a string that contains XQuery based Optimization Services Modeling Language 
	 * model and compiles the model into an Optimization Services Instance Language (OSiL) 
	 * low level representation.</p>
	 * 
	 * </p>
	 * 
	 * @param osmlModelString holds a string the XQuery based Optimization Services Modeling Language 
	 * model to be compiled.
	 * @param xmlDataString holds the xml data in a string to be queried.
	 
	 * @return an Optimization Services Instance Language (OSiL) low level representation string.
	 */
	public String modelString(String osmlModelString, String xmlDataString) {
		//1. OSmL ---preparse---> preparsed model
		InputStream is = new ByteArrayInputStream(osmlModelString.getBytes());
		OSmLPreParser osmlPreparser = new OSmLPreParser(is);
		preparsedModel = osmlPreparser.preParse();

		//2. preparsed model and data ---query---> query result 
		XQueryUtil xqueryUtil = new XQueryUtil(preparsedModel, xmlDataString,
				false);
		List queryResultList = xqueryUtil.query(null);
		queryResult = XQueryUtil.queryResultToString(queryResultList);

		//3. query result ---parse---> OSiL instance
		OSmLQueryResultToOSiL osmlQueryResultToOSiL = new OSmLQueryResultToOSiL();
		osilInstance = osmlQueryResultToOSiL.parseQueryResult(queryResult);

		return osilInstance;
	}//modelString

	/**
	 * <p>Interpret a file that contains XQuery based Optimization Services Modeling Language 
	 * model and compiles the model into an Optimization Services Instance Language (OSiL) 
	 * low level representation.</p>
	 * 
	 * </p>
	 * 
	 * @param osmlModelFile holds the name of a file of an XQuery based Optimization Services Modeling Language 
	 * model to be compiled.
	 * @param xmlDataFile holds the name of the file that contains the xml data to be queried.
	 * @return an Optimization Services Instance Language (OSiL) low level representation string.
	 */
	public String modelFile(String osmlModelFile, String xmlDataFile) {
		String sOSiLInstance = "";
		//1. OSmL ---preparse---> preparsed model
		InputStream is = IOUtil.fileToInputStream(osmlModelFile);
		OSmLPreParser preParser = new OSmLPreParser(is);
		preparsedModel = preParser.preParse();

		//2. preparsed model and data ---query---> query result 
		long start = System.currentTimeMillis();
		String sXmlDataString = (xmlDataFile == null ? null : IOUtil
				.fileToString(xmlDataFile));
		XQueryUtil xqueryUtil = new XQueryUtil(preparsedModel, sXmlDataString,
				false);
		List queryResultList = xqueryUtil.query(null);
		queryResult = XQueryUtil.queryResultToString(queryResultList);
		System.out.println("The XQuery is complete");
		long finishXQuery = System.currentTimeMillis();
		System.out.println("CPU Time For XQuery =  "
				+ Long.toString(finishXQuery - start));

		//3. query result ---parse---> OSiL instance
		OSmLQueryResultToOSiL osmlQueryResultToOSiL = new OSmLQueryResultToOSiL();
		sOSiLInstance = osmlQueryResultToOSiL.parseQueryResult(queryResult);
		System.out.println("Done converting to OSiL");
		long finishOSiLCreation = System.currentTimeMillis();
		System.out.println("CPU Time For Create OSiL =  "
				+ Long.toString(finishOSiLCreation - finishXQuery));
		//IOUtil.stringToFile(sOSiLInstance, "./xml/testresult.xml");
		return sOSiLInstance;
	}//modelFile

	/**
	 * main for test purposes.
	 *
	 * </p>
	 *
	 * @param argv command line arguments.
	 */
	public static void main(String args[]){	
		String[] msModel = {"lindo_ex_nlp1.osml", "knitroexample.osml", "rosenbrock.osml",  "parinc.osml", 
				"dietproblem.osml",  "lotsize.osml", "transportation.osml", "markowitz.osml", "lindo_ex_nlp2.osml"};
		//String[] msModel ={"knitroexample.osml"};
		for(int i = 3; i < 4; i++){
			OSmLEngine OSmLEngine = new OSmLEngine();
			System.out.println("*********************************");
			System.out.println("Here is problem " + msModel[ i]);
			try{
				String sModel = "../../../OSRepository/test/osml/"+msModel[ i];
				//System.out.println(sModel);
				String sData = null;
				//String sOSiLInstance = OSmLEngine.modelFile(sModel, sData);
				String sOSiLInstance = OSmLEngine.modelString(IOUtil.readStringFromFile(sModel), sData);
				String sEmptyOSiL = "<?xml version=\"1.0\" encoding=\"UTF-8\"?><OSoL/>";
				System.out.println(OSmLEngine.preparsedModel);
				System.out.println(OSmLEngine.queryResult);
				System.out.println( sOSiLInstance);
				/*
				// solve on the server
				
				//OSAgentService osAgentService = new OSAgentService();	
				//String sSolverAddress = "http://gsbkip.chicagogsb.edu/os/ossolver/KnitroSolverService.jws";
				//String sSolverAddress = OSParameter.OS_SERVICE_SITE + "/ossolver/LindoSolverService.jws";
				//String sSolverAddress = "http://128.135.130.17:8181/OSSolverService";
				String sSolverAddress = "http://localhost:8080/os/ossolver/ImpactSolverService.jws";
				OSSolverAgent osSolverAgent = new OSSolverAgent();
				osSolverAgent.solverAddress = sSolverAddress;
				String sOSrLInstance = osSolverAgent.solve( sOSiLInstance, sEmptyOSiL);	
						
				// Solve locally
				//KnitroSolverService solverService = new KnitroSolverService();
				//LindoSolverService solverService = new LindoSolverService();				
				//String sOSrLInstance = solverService.solve(sOSiLInstance, null);
				//ImpactSolverService impactSolverService = new ImpactSolverService();
				//String sOSrLInstance = impactSolverService.solve(sOSiLInstance, sEmptyOSiL);
				System.out.println( "result: "+sOSrLInstance);
				System.out.println("*********************************");
				*/
			}
			catch(Exception e){
				e.printStackTrace();
			}
		}
	}//main

}//class OSmL
