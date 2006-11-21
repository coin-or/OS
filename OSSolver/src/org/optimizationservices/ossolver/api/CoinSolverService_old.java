/**
 * @(#)CoinSolverService 1.0 03/14/2004
 *
 * Copyright (c) 2004
 */
package org.optimizationservices.ossolver.api;

import org.optimizationservices.oscommon.communicationinterface.OShL;
import org.optimizationservices.oscommon.localinterface.DefaultSolver;
import org.optimizationservices.oscommon.util.IOUtil;
import org.optimizationservices.oscommon.util.OSServiceUtil;
import org.optimizationservices.ossolver.solver.CoinSolver;


/**
 *
 * <P>The <code>CoinSolverService</code> is the Coin Solver's Web Service facade. 
 *
 * </p>
 * @author Robert Fourer, Jun Ma, Kipp Martin
 * @version 1.0, 03/14/2004
 * @see org.optimizationservices.ossolver.api.OShL
 * @since OS 1.0
 */
public class CoinSolverService_old implements OShL{
	/**
	 * m_osServiceUtil holds a default implementation of the solver service.
	 */
	private OSServiceUtil m_osServiceUtil = new OSServiceUtil();

	/**
	 * m_sServiceName holds the service name. 
	 */
	private String m_sServiceName = "CoinSolverService";

	/**
	 * m_sServiceURI holds the service uri.
	 */
	private String m_sServiceURI = "http://128.135.130.128:8080/os/ossolver/CoinSolverService.jws";
		
	/**
	 * m_Solver holds the default solver.
	 */
	private DefaultSolver m_Solver = new CoinSolver();
	
	/**
	 * default constructor.
	 *
	 */
	public CoinSolverService_old(){
		m_osServiceUtil.serviceName = m_sServiceName;
		m_osServiceUtil.serviceURI = m_sServiceURI;
		m_osServiceUtil.solver = m_Solver;
	}//constructor
	
	/**
	 * Solve an optimization problem whose instance is given by a string following
	 * the Optimization Services instance Language (OSiL) schema and returns the solution
	 * in a string that follows the Optimization Services result Language (OSrL) schema.
	 *
	 * </P>
	 *
	 * @param osil holds the optimization instance in a string which format follows the
	 * Optimization Services instance Language (OSiL) schema.
	 * @param osol holds the optimization option in a string which format follows the 
	 * Optimization Services option Language (OSoL) schema.    
	 * @return the optimization result in a string which format follows the Optimization
	 * Services result Language (OSrL) schema.
	 * @see org.optimizationservices.ossolver.api.OShL#solve
	 */
	public String solve(String osil, String osol){
		return m_osServiceUtil.solve(osil, osol);
		
		
		/*
		//read
			//Not necessary, because the solver executable will parse the OSiL string. 
		//solve
		String sOS = System.getProperty("os.name").toLowerCase();
		String sCoinProblemFileName = "";
		String sCoinIntermediateOutputFileName = "";
		String sCoinSolutionFileName = ""; 
		String sCoinPathName = "";
		if(sOS.indexOf("window") >= 0){
			sCoinProblemFileName = "c:\\code\\coin\\win32\\temp\\problem.osil";
			sCoinIntermediateOutputFileName = "c:\\code\\coin\\win32\\temp\\problem.txt";
			sCoinSolutionFileName = "c:\\code\\coin\\win32\\temp\\problem.osil_out.xml";
			IOUtil.writeStringToFile(osil, sCoinProblemFileName);
			String sCommand = "c:\\code\\coin\\win32\\bin\\osil --parser=osiclp " + sCoinProblemFileName + " > " + sCoinIntermediateOutputFileName;
			ProcessUtil.launchAndWaitForFinish(sCommand);
			
		}
		else if(sOS.indexOf("window") < 0){
			OSoLReader osolReader = new OSoLReader(OSParameter.VALIDATE);
			osolReader.readString(osol);
			String sSubSolver = osolReader.getOtherOptionValueByName("subSolver"); //clp or glpk
			if(sSubSolver!=null && !sSubSolver.equalsIgnoreCase("glpk")) sSubSolver = "clp";
			String sUserHome = System.getProperty("user.home");
			sCoinProblemFileName = sUserHome + "/Documents/files/code/cpp/OScpp/OSMain/xml/coininput.dat";
			sCoinSolutionFileName = sUserHome + "/Documents/files/code/cpp/OScpp/OSMain/xml/coinsolution.dat";
			sCoinPathName = sUserHome +         "/Documents/files/code/cpp/OScpp/OSMain/bin/coinsolverservice";
			IOUtil.writeStringToFile(osil, sCoinProblemFileName);
			String sCommand = sCoinPathName + " " + sSubSolver + " " + sCoinProblemFileName + " " +  sCoinSolutionFileName;
			System.out.println(sCommand);
			ProcessUtil.launchAndWaitForFinish(sCommand);
		}
		
		//write
		String sOSrL = IOUtil.readStringFromFile(sCoinSolutionFileName);
		return sOSrL;
		*/
	}//solve


	/**
	 * get a job id 
	 * 
	 * @param osol holds the option for job id retrieval
	 * @return a jobID string. 
	 */
	public String getJobID(String osol){
		return m_osServiceUtil.getJobID(osol);
	}//getJobID

	/**
	 * An asynchronous send method with instance and option for the Solver. 
	 * The option must contain a job id so that the job result can be retrieved later.
	 * 
	 * @param  osil holds the input instance. 
	 * @param osol holds the input option. 
	 * @return whether the instance and option are sent and received by this method successfully. 
	 */
	public boolean send(String osil, String osol){
		return m_osServiceUtil.send(osil, osol);
	}//send
	
	/**
	 * 
	 * Retrieve a previously sent job's result with a job id. If the job result is not ready, an empty string 
	 * will be returned.
	 * 
	 * @param osol holds input option, that contains the job id. 
	 * @return Retrieved result in a string, null or empty if result not ready. 
	 */
	public String retrieve(String osol){
		return m_osServiceUtil.retrieve(osol);
	}//retrieve
	
	/**
	 * Kill a previously sent job.
	 * 
	 * @param osol holds input option, that contains the job id. 
	 * @return the kill process status of the kill operation. 
	 */
	public String kill(String osol){
		return m_osServiceUtil.kill(osol);
	}//kill
	
	/**
	 * Set (push) and/or get (pull) runtime dynamic process information to and/or from the service. 
	 *
	 * @param osplInput holds the input process information in a string which format follows OSpL schema.
	 * @param holds the option in a string which format follows OSoL schema. 
	 * @return the output process information in a string which format follows the OSpL schema.
	 */
	public String knock(String osplInput, String osol){
		return m_osServiceUtil.knock(osplInput, osol);
	}//knock

	/**
	 * main for test purposes.
	 *
	 * </p>
	 *
	 * @param argv command line arguments.
	 */
	public static void main(String[] argv){
		CoinSolverService_old coinSolverService = new CoinSolverService_old();
		String sOSoL = null;
		//sOSoL = IOUtil.fileToString("../../../OSRepository/test/osol/parinclinear.osol");
		String sOSiL = IOUtil.fileToString("../../../OSRepository/test/osil/parinc.osil");
//		sOSiL = IOUtil.fileToString("../../../OSRepository/test/osil/knitroexample.osil");
//		sOSiL = IOUtil.fileToString("../../../OSRepository/test/osil/rosenbrock.osil");
//		sOSiL = IOUtil.fileToString("../../../OSRepository/test/osil/parincLinear.osil");
//		sOSiL = IOUtil.fileToString("../../../OSRepository/test/osil/parinc.osil");
//		sOSiL = IOUtil.fileToString("../../../OSRepository/test/osil/dietproblem.osil");
//		sOSiL = IOUtil.fileToString("../../../OSRepository/test/osil/lotsize.osil");
//		sOSiL = IOUtil.fileToString("../../../OSRepository/test/osil/transportation.osil");
//		sOSiL = IOUtil.fileToString("../../../OSRepository/test/osil/markowitz.osil");
//		sOSiL = IOUtil.fileToString("../../../OSRepository/test/osil/lindo_api_ex_nl1.osil");
//		sOSiL = IOUtil.fileToString("../../../OSRepository/test/osil/lindo_api_ex_nl2.osil");

		String sOSrL = coinSolverService.solve(sOSiL, sOSoL);
		System.out.println("result: " + sOSrL);
		
	}//main
	
	/// <summary>
	/// static constructor
	/// </summary>
	static{
	}//static constructor
}//class CoinSolverService
