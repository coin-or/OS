/**
 * @(#)JunMaLPSolverService 1.0 03/14/2004
 *
 * Copyright (c) 2004
 */
package org.optimizationservices.ossolver.api;

import org.optimizationservices.oscommon.communicationinterface.OShL;
import org.optimizationservices.oscommon.util.IOUtil;
import org.optimizationservices.ossolver.parser.JunMaLPSolverFMLReader;
import org.optimizationservices.ossolver.parser.JunMaLPSolverFMLWriter;
import org.optimizationservices.ossolver.problem.JunMaOptProblem_LP;
import org.optimizationservices.ossolver.solver.JunMaLPSolver;

/**
 *
 * <P>The <code>JunMaLPSolverService</code> implements all the <code>OShL</code> interface.
 * Thus it is OS-type solver. It implements all the methods as specified in the
 * Optimization Services (OS) Framework, specifically the Optimization Services hook-up
 * Language (OShL). These methods are called by an OS agent to invoke this OS-based solver.
 *
 * </p>
 * @author Robert Fourer, Jun Ma, Kipp Martin
 * @version 1.0, 03/14/2004
 * @see org.optimizationservices.ossolver.api.OShL
 * @since OS 1.0
 */
public class JunMaLPSolverService implements OShL{
	
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
		String sOSrL = "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n<OSrL></OSrL>";
		
		//read
		JunMaLPSolverFMLReader junmaLPSolverFMLReader = new JunMaLPSolverFMLReader();
		if(!junmaLPSolverFMLReader.readString(osil)) return sOSrL;
		
		//solve
		JunMaLPSolver junmaLPSolver = junmaLPSolverFMLReader.junmaLPSolver;
		JunMaOptProblem_LP junMaOptProblem_LP = junmaLPSolverFMLReader.junmaOptProblem_LP;
		junmaLPSolver.minimize(junMaOptProblem_LP);
		junmaLPSolver.printProblem(junMaOptProblem_LP);
		junmaLPSolver.printSolution();
		
		//write and return
		JunMaLPSolverFMLWriter junmaLPSolverFMLWriter = new JunMaLPSolverFMLWriter(junmaLPSolver, junMaOptProblem_LP);
		sOSrL = junmaLPSolverFMLWriter.writeLPSolutionToString();
		return sOSrL;
	}//solve
		
	/**
	 * Methods in OShL that are not implemented.
	 */
	public boolean send(String osil, String osol){return false;}

	/**
	 * Methods in OShL that are not implemented.
	 */
	public String kill(String osol){return null;}
	
	/**
	 * Methods in OShL that are not implemented.
	 */
	public String knock(String ospl, String osol){return null;}

	/**
	 * Methods in OShL that are not implemented.
	 */
	public String getJobID(String osol){ return null;}
	
	/**
	 * Methods in OShL that are not implemented.
	 */
	public String retrieve(String osol){return null;}
	/**
	 * main for test purposes.
	 *
	 * </p>
	 *
	 * @param argv command line arguments.
	 */
	public static void main(String[] argv){
		JunMaLPSolverService junmaLPSolverService = new JunMaLPSolverService();
		String sOSiL = IOUtil.fileToString("../../../OSRepository/test/junma/lpparinc.xml");
		String sOSrL = junmaLPSolverService.solve(sOSiL, null);
		System.out.println(sOSrL);
	}//main
	
}//class JunMaLPSolverService
