/**
 * @(#)JunMaLPSolverFMLWriter 1.0 03/14/2004
 *
 * Copyright (c) 2004
 */
package org.optimizationservices.ossolver.parser;

import org.optimizationservices.oscommon.representationparser.FMLWriter;
import org.optimizationservices.ossolver.problem.JunMaOptProblem_LP;
import org.optimizationservices.ossolver.solver.JunMaLPSolver;

/**
 *
 * <P>The <code>JunMaLPSolverFMLWriter</code> class uses methods from <code>FMLWriter</code>
 * object to construct linear programming output data structures from our sample LP solver.
 *
 * </p>
 * @author Robert Fourer, Jun Ma, Kipp Martin
 * @version 1.0, 03/14/2004
 * @see org.optimizationservices.oscommon.representationparser.FMLWriter
 * @see org.optimizationservices.ossolver.problem.JunMaOptProblem_LP
 * @see org.optimizationservices.ossolver.solver.JunMaLPSolver
 * @since OS 1.0
 */
public class JunMaLPSolverFMLWriter {
	
	/**
	 * m_fmlWriter holds an instance of the <code>FMLWriter</code> class, from which many methods
	 * are used to construct the linear programming instance.
	 */
	protected FMLWriter m_fmlWriter = null;
	
	/**
	 * junmaLPSolver holds the sample linear solver provided in the OS framework
	 * for illustration of real solver reader implementation.
	 */
	public JunMaLPSolver junmaLPSolver = null;
	
	/**
	 * junmaOptProblem_LP holds the optimization problem structure accepted by the
	 * junmaLPSolver.
	 */
	public JunMaOptProblem_LP junmaOptProblem_LP = null;
	
	/**
	 * constructor
	 */
	public JunMaLPSolverFMLWriter(){
		m_fmlWriter = new FMLWriter();
	}//constructor
	
	/**
	 * constructor
	 *
	 * </p>
	 *
	 * @param junmaLPSolver holds the sample linear solver provided in the OS framework
	 * for illustration of real solver reader implementation.
	 * @param junMaOptProblem_LP holds the optimization problem structure accepted by the
	 * junmaLPSolver.
	 */
	public JunMaLPSolverFMLWriter(JunMaLPSolver junMaLPSolver, JunMaOptProblem_LP junMaOptProblem_LP){
		m_fmlWriter = new FMLWriter();
		junmaLPSolver = junMaLPSolver;
		junmaOptProblem_LP = junMaOptProblem_LP;
	}//constructor(JunMaLPSolver, JunMaOptProblem_LP)
	
	/**
	 * Write the LP Solution to an xml file following FML Schema.
	 *
	 * </p>
	 *
	 * @param fileName	holds the xml filename to write out the file to.
	 * @return whether the file is written successfully without any error.
	 */
	public boolean writeLPSolutionToFile(String fileName){
		if(!constructLPSolution()){
			return false;
		}
		return m_fmlWriter.writeToFile(fileName);
	}//writeLPSolutionFile
	
	/**
	 * Write the LP Solution to standard output following FML Schema.
	 *
	 * </p>
	 *
	 * @return whether the output is written successfully without any error.
	 */
	public boolean writeLPSolutionToStandardOutput(){
		if(!constructLPSolution()){
			return false;
		}
		return m_fmlWriter.writeToStandardOutput();
	}//writeLPSolutionToStandardOutput
	
	/**
	 * Write the LP Solution to a string following FML Schema.
	 *
	 * </p>
	 *
	 * @return whether the string is written successfully without any error.
	 */
	public String writeLPSolutionToString(){
		if(!constructLPSolution()){
			return null;
		}
		return m_fmlWriter.writeToString();
	}//writeLPSolutionToString
	
	/**
	 * Construct LP Solution following the FML Schema by using the methods from
	 * <code>FMLWriter<code>
	 *
	 * @return whether the LPSolution is constructed successfully without any error.
	 */
	private boolean constructLPSolution(){
		String sSource = junmaOptProblem_LP.sDescription;
		int iVariableCount = junmaOptProblem_LP.iCol;
		int iConstraintCount = (junmaOptProblem_LP.iRow - junmaOptProblem_LP.iCol*2)/2;
		if(!m_fmlWriter.setDescription(sSource, iVariableCount, iConstraintCount)){
			return false;
		}
		
		if(!m_fmlWriter.setObjective(junmaLPSolver.isMin(), junmaOptProblem_LP.dObjConstant, null)){
			return false;
		}
		
		String sStatusId = "";
		String sStatus = junmaLPSolver.getMessage();
		String sSolverMessage = junmaLPSolver.getMessage();
		double dOptimalValue = junmaLPSolver.getOptimalValue();
		if(junmaLPSolver.getSolutionStatus().equals("SOLVED")){
			sStatusId = "optimalSolutionFound";
			String[] msPrimalName = junmaOptProblem_LP.msColName;
			double[] mdPriamlValue = junmaLPSolver.getSolution();
			int[] miPrimalIndex = new int[mdPriamlValue.length];
			for(int i = 0; i < miPrimalIndex.length; i++){
				miPrimalIndex[i] = i;
			}
			if(!m_fmlWriter.setPrimalSolution(msPrimalName, mdPriamlValue, miPrimalIndex)){
				return false;
			}
		}
		else if(junmaLPSolver.getSolutionStatus().equals("UNBOUNDED")){
			sStatusId = "unbounded";
		}
		else if(junmaLPSolver.getSolutionStatus().equals("INFEASIBLE")){
			sStatusId = "infeasible";
		}
		else if(junmaLPSolver.getSolutionStatus().equals("UNKNOWN_LP")){
			sStatusId = "infeasible";
		}
		else if(junmaLPSolver.getSolutionStatus().equals("UNKNOWN_GENERAL")){
			sStatusId = "infeasible";
		}
		else{
			sStatusId = "infeasible";
		}
		if(!m_fmlWriter.setSolution(sStatusId, sStatus, sSolverMessage, dOptimalValue)){
			return false;
		}
		return true;
		
	}//constructLPSolution
	
	/**
	 *  main for test purposes.
	 *
	 * </p>
	 *
	 * @param argv command line arguments.
	 */
	public static void main(String[] argv){
		JunMaLPSolverFMLWriter fmlWriter = new JunMaLPSolverFMLWriter();
		JunMaOptProblem_LP junmaOptProblem_LP = new JunMaOptProblem_LP();
		junmaOptProblem_LP.initializeLP();
		fmlWriter.junmaOptProblem_LP = junmaOptProblem_LP;
		JunMaLPSolver junmaLPSolver = new JunMaLPSolver();
		junmaLPSolver.minimize(junmaOptProblem_LP);
		fmlWriter.junmaLPSolver = junmaLPSolver;
		fmlWriter.writeLPSolutionToStandardOutput();
	}//main
	
}//class JunMaLPSolverFMLWriter
