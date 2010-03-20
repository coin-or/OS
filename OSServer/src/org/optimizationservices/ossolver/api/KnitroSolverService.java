/**
 * @(#)KnitroSolverService 1.0 03/14/2004
 *
 * Copyright (c) 2004
 */
package org.optimizationservices.ossolver.api;
import org.optimizationservices.oscommon.communicationinterface.OShL;
import org.optimizationservices.oscommon.representationparser.OSiLReader;
import org.optimizationservices.oscommon.util.IOUtil;
import org.optimizationservices.oscommon.util.OSParameter;
import org.optimizationservices.ossolver.solver.KnitroSolver;
/**
 *
 * <P>The <code>KnitroSolverService</code> implements all the <code>OShL</code> interface.
 * Thus it is OS-type solver. It implements all the methods as specified in the
 * Optimization Services (OS) Framework, specifically the Optimization Services hook-up
 * Language (OShL). These methods are called by an OS agent to invoke this OS-based Knitro solver.
 *
 * </p>
 * @author Robert Fourer, Jun Ma, Kipp Martin
 * @version 1.0, 03/14/2004
 * @see org.optimizationservices.ossolver.api.OShL
 * @since OS 1.0
 */
public class KnitroSolverService implements OShL{
	
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

		//read
		OSiLReader osilReader = new OSiLReader(OSParameter.VALIDATE);
		boolean bRead = osilReader.readString(osil);
		if(!bRead){
			return "Knitro can't solve the problem. The xml file is not valid.\n";
		}
		String sLogicError = osilReader.getLogicError();
		if(sLogicError.length() > 0){
			return "Knitro can't solve the problem. The instance is wrong: \n" + sLogicError;
		}
		
		//solve
		KnitroSolver knitro = new KnitroSolver();		
		String sResult = knitro.solve( osilReader);
		
		//write
		String sOSrL = sResult;
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
	public String kill(String ospl){return null;}
	
	/**
	 * Methods in OShL that are not implemented.
	 */
	public String knock(String ospl, String osol){return null;}

	/**
	 * Methods in OSkL that are not implemented.
	 */
	public boolean knock(String ospl){return false;}

	/**
	 * main for test purposes.
	 *
	 * </p>
	 *
	 * @param argv command line arguments.
	 */

	public static void main(String[] argv){
		KnitroSolverService knitroSolverService = new KnitroSolverService();
		String sOSiL;
		sOSiL = IOUtil.fileToString("../../../OSRepository/test/osil/knitroexample.osil");
		//sOSiL = IOUtil.fileToString("../../../OSRepository/test/osil/rosenbrock.osil");
		//sOSiL = IOUtil.fileToString("../../../OSRepository/test/osil/parinc.osil");
		//sOSiL = IOUtil.fileToString("../../../OSRepository/test/osil/dietproblem.osil");
		//sOSiL = IOUtil.fileToString("../../../OSRepository/test/osil/lotsize.osil");
		//sOSiL = IOUtil.fileToString("../../../OSRepository/test/osil/transportation.osil");
		//sOSiL = IOUtil.fileToString("../../../OSRepository/test/osil/markowitz.osil");
		//sOSiL = IOUtil.fileToString("../../../OSRepository/test/osil/markowitzmod.osil");
		//sOSiL = IOUtil.fileToString("../../../OSRepository/test/osil/lindo_api_ex_nl1.osil");
		//sOSiL = IOUtil.fileToString("../../../OSRepository/test/osil/lindo_api_ex_nl2.osil");
		String sOSrL = knitroSolverService.solve(sOSiL, null);
		System.out.println("result: " + sOSrL);
	}//main
	
}//class KnitroSolverService
