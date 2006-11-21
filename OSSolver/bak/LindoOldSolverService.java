/**
 * @(#)LindoSolverService 1.0 03/14/2004
 *
 * Copyright (c) 2004
 */
package org.optimizationservices.ossolver.api;

import org.optimizationservices.oscommon.communicationinterface.OShL;
import org.optimizationservices.oscommon.util.IOUtil;
import org.optimizationservices.ossolver.parser.LindoOSiLReader;
import org.optimizationservices.ossolver.solver.LindoSolver;

/**
 *
 * <P>The <code>LindoSolverService</code> implements all the <code>OShL</code> interface.
 * Thus it is OS-type solver. It implements all the methods as specified in the
 * Optimization Services (OS) Framework, specifically the Optimization Services hook-up
 * Language (OShL). These methods are called by an OS agent to invoke this OS-based Lindo solver.
 *
 * </p>
 * @author Robert Fourer, Jun Ma, Kipp Martin
 * @version 1.0, 03/14/2004
 * @see org.optimizationservices.ossolver.api.OShL
 * @since OS 1.0
 */
public class LindoSolverService implements OShL{
	
	/**
	 * Solve an optimization problem whose instance is given by a string following
	 * the Optimization Services instance Language (OSiL) schema and returns the solution
	 * in a string that follows the Optimization Services result Language (OSrL) schema.
	 *
	 * </P>
	 *
	 * @param osil holds the optimization instance in a string which format follows the
	 * Optimization Services instance Language (OSiL) schema.
	 * @return the optimization result in a string which format follows the Optimization
	 * Services result Language (OSrL) schema.
	 * @see org.optimizationservices.ossolver.api.OShL#solve
	 */
	public String solve(String osil, String osol){
		//read
		LindoOSiLReader lindoOSiLReader = new LindoOSiLReader();
		String sLindoInput = lindoOSiLReader.osilToInstructionLists(osil);
		if(sLindoInput == null && lindoOSiLReader.m_sLogicError.length() == 0){
			return "Lindo can't solve the problem. The xml file is not valid.\n";
		}
		if(sLindoInput == null && lindoOSiLReader.m_sLogicError.length() > 0){
			return "Lindo can't solve the problem. The instance is wrong: \n" + lindoOSiLReader.m_sLogicError;
		}
		
		String sOS = System.getProperty("os.name").toLowerCase();
		String sInstructionListFileName = "";
		if(sOS.indexOf("window") >= 0) sInstructionListFileName = "c:\\code\\lindo\\win32\\temp\\lindoinput.dat"; 
		else if(sOS.indexOf("window") < 0){
			sInstructionListFileName = System.getProperty("user.home") + "/Documents/files/code/lindo/macosx/projects/oslindo/instances/lindoinput.dat";
		}
		IOUtil.stringToFile(sLindoInput, sInstructionListFileName);
		//solve
		LindoSolver lindoSolver = new LindoSolver();
		String sLindoSolutionFileName = lindoSolver.solve(sInstructionListFileName);
		
		//write
		
		String sOSrL = IOUtil.readStringFromFile(sLindoSolutionFileName);
		return sOSrL;
	}//solve
	

	/**
	 * Methods in OShL that are not implemented.
	 */
	public boolean send(String osil, String osol){return false;}

	/**
	 * Methods in OShL that are not implemented.
	 */
	public String getJobID(String osol){ return null;}
	
	/**
	 * Methods in OShL that are not implemented.
	 */
	public String retrieve(String osol){return null;}
	
	/**
	 * Methods in OShL that are not implemented.
	 */
	public String kill(String osol){return null;}
	
	/**
	 * Methods in OShL that are not implemented.
	 */
	public String knock(String ospl, String osol){return null;}

	/**
	 * main for test purposes.
	 *
	 * </p>
	 *
	 * @param argv command line arguments.
	 */
	public static void main(String[] argv){
		LindoSolverService lindoSolverService = new LindoSolverService();
		String sOSiL;
		//sOSiL = IOUtil.fileToString("../../../OSRepository/");
		//sOSiL = IOUtil.fileToString("../../../OSRepository/test/wayne/lotsize_w2.osil");
		//sOSiL = IOUtil.fileToString("../../../OSRepository/test/osil/knitroexample.osil");
		//sOSiL = IOUtil.fileToString("../../../OSRepository/test/wayne/dietproblem_w1.osil");
		//sOSiL = IOUtil.fileToString("../../../OSRepository/test/osil/rosenbrock.osil");
		//sOSiL = IOUtil.fileToString("../../../OSRepository/test/osil/parinc.osil");
		//sOSiL = IOUtil.fileToString("../../../OSRepository/test/osil/dietproblem.osil");
		//sOSiL = IOUtil.fileToString("../../../OSRepository/test/osil/lotsize.osil");
		sOSiL = IOUtil.fileToString("../../../OSRepository/test/osil/transportation.osil");
		//sOSiL = IOUtil.fileToString("../../../OSRepository/test/osil/markowitz.osil");
		//sOSiL = IOUtil.fileToString("../../../OSRepository/test/osil/lindo_api_ex_nl1.osil");
		//sOSiL = IOUtil.fileToString("../../../OSRepository/test/osil/lindo_api_ex_nl2.osil");
		//OSiLReader reader = new OSiLReader(true);
		//reader.readString(sOSiL);
		//System.out.println(sOSiL);
		String sOSrL = lindoSolverService.solve(sOSiL, null);
		System.out.println("result: " + sOSrL);
	}//main
	
}//class LindoSolverService
