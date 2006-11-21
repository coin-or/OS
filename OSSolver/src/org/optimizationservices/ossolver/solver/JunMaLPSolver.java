/**
 * @(#)JunMaLPSolver 1.0 03/14/2004
 *
 * Copyright (c) 2004
 */
package org.optimizationservices.ossolver.solver;

import optimization.Optimizer;

import org.optimizationservices.ossolver.problem.JunMaOptProblem_LP;

import drasys.or.matrix.SparseMatrix;
import drasys.or.matrix.SparseVector;
import drasys.or.opt.lp.DenseSimplex;
import drasys.or.opt.lp.LPException;
import drasys.or.opt.lp.LinearProgrammingI;

/**
 *
 * <P>The <code>JunMaLPSolver</code> class is a sample linear programming solver
 * provided in the Optimization Services framework, to illustrate use of linear
 * solvers as an Optimization Service.
 *
 * </p>
 * @author Robert Fourer, Jun Ma, Kipp Martin
 * @version 1.0, 03/14/2004
 * @see org.optimizationservices.ossolver.solver.JunMaOptProblem_LP
 * @since OS 1.0
 */
public class JunMaLPSolver extends Optimizer{
	/**
	 * dEPS holds the value for a very small positive number considered by the solver.
	 */
	private double m_dEPS   = 1.0e-16;
	
	/**
	 * dRange holds the value for a very big number positive considered by the solver.
	 */
	private double m_dRange = Double.POSITIVE_INFINITY;
	
	/**
	 * m_iMaxIteration holds the value for the maximum number of iteration in minimization process.
	 */
	private int m_iMaxIteration = Integer.MAX_VALUE;
	
	
	/**
	 * m_bMin holds the value of whether the optimization problem is originally minimization
	 * or maximization. Since only minimization method is provided from the JunMaLPSolver, orginal
	 * maximization problem has to be converted to minimization by multiplying their objective
	 * coefficient with -1. m_bMin is intended to remember the original objective direction, so that
	 * objective coefficients can be converted back if original objective direction is maximization.
	 */
	private boolean m_bMin = true;
	
	/**
	 * m_bAutomaticScaling holds whether to enable automatic scaling in minimization process.
	 */
	private boolean m_bAutomaticScaling = false;
	
	/**
	 * m_sSolutionStatus holds the status of the solution: SOLVED, UNBOUNDED, INFEASIBLE, UNKNOWN_LP, UNKNOWN_GENERAL.
	 */
	private String m_sSolutionStatus = "SOLVED";
	
	/**
	 * m_sMessage holds any message (mainly errors or warnings) from the solver.
	 */
	private String m_sMessage = "The JunMa sample solver finds a solution successfully.";
	
	/**
	 * m_dSolution holds the solution of the variables if the optimization is solved.
	 */
	private double[] m_mdSolution = null;
	
	/**
	 * m_dOptimalValue holds the objective solution if the optimization is solved.
	 */
	private double m_dOptimalValue = Double.NaN;
	
	/**
	 * @param maxIteration The maximum iteration to set for the minimization process.
	 */
	public void setMaxIteration(int maxIteration) {
		m_iMaxIteration = maxIteration;
	}//setMaxIteration
	
	/**
	 * @return the maximum iteration of the minimization process.
	 */
	public int getMaxIteration() {
		return m_iMaxIteration;
	}//getMaxIteration
	
	/**
	 * @return whether the original problem is minimization or not.
	 */
	public boolean isMin() {
		return m_bMin;
	}//isMin
	
	/**
	 * @param isMin holds whether the original problem is minimization or not..
	 */
	public void setMin(boolean isMin) {
		m_bMin = isMin;
	}//setMin
	
	/**
	 * @return whether the minimization process enables automatic scaling.
	 */
	public boolean isAutomaticScaling() {
		return m_bAutomaticScaling;
	}//isAutomaticScaling
	
	/**
	 * @param isAutomaticScaling holds whether to enable automatic scaling in minimization process.
	 */
	public void setAutomaticScaling(boolean isAutomaticScaling) {
		m_bAutomaticScaling = isAutomaticScaling;
	}//setAutomaticScaling
	
	/**
	 * @return the objective solution if the optimization is solved..
	 */
	public double getOptimalValue() {
		return m_dOptimalValue;
	}//getSolution
	
	/**
	 * @return the solution of the variables if the optimization is solved..
	 */
	public double[] getSolution() {
		return m_mdSolution;
	}//getSolution
	
	/**
	 * @return any message (mainly errors or warnings) from the solver corresponding to each solution status.
	 */
	public String getMessage() {
		return m_sMessage;
	}//getMessage
	
	/**
	 * @return the status of the solution: SOLVED, UNBOUNDED, INFEASIBLE, UNKNOWN_LP, UNKNOWN_GENERAL.
	 */
	public String getSolutionStatus() {
		return m_sSolutionStatus;
	}//getSolutionStatus
	
	/**
	 * constructor
	 */
	public JunMaLPSolver(){
		
	}//constructor
	
	/**
	 * Minimize the linear optimization problem. Since only this minization method is provided
	 * original maximization problem has to be converted to minimization by multiplying their objective
	 * coefficient with -1. m_bMin is intended to remember the original objective direction, so that
	 * objective coefficients can be converted back if original objective direction is maximization.
	 *
	 * </p>
	 *
	 * @param lpProblem holds the LP problem to be minimized.
	 * @return whether the optimization problem is solved successfully or not.
	 */
	public boolean minimize(JunMaOptProblem_LP lpProblem){
		//final int DOUBLE = 0;
		//final int BINARY = 1;
		//final int INTEGER = 2;
		final int LE = -1;
		final int EQ = 0;
		final int GE = 1;
		double dObjConstant = 0.0;
		
		dObjConstant = lpProblem.dObjConstant;
		//set up
		LinearProgrammingI LP = new DenseSimplex(lpProblem.iRow, lpProblem.iCol);
		double dR = LP.getRangeMax();
		double dL = LP.getRangeMin();
		if(dR < m_dRange) dR = m_dRange;
		if(dL < m_dEPS) dL = m_dEPS;
		LP.setRange(dL, dR);
		LP.setMaxIterations(m_iMaxIteration);
		LP.setAutomaticScaling(m_bAutomaticScaling);
		
		//transfer equation types to native equation type expressions
		byte[] mbEquationType = new byte[lpProblem.iRow];
		for (int i = 0; i < lpProblem.iRow; i++){
			if (lpProblem.miEquationType[i] == LE){
				mbEquationType[i] = LinearProgrammingI.LESS;
			}
			if (lpProblem.miEquationType[i] == EQ){
				mbEquationType[i] = LinearProgrammingI.EQUAL;
			}
			if (lpProblem.miEquationType[i] == GE){
				mbEquationType[i] = LinearProgrammingI.GREATER;
			}
		}
		LP.setObjective(new SparseVector(lpProblem.mdObjCoef));
		LP.addConstraint(new SparseMatrix(lpProblem.mmdCoef), new SparseVector(lpProblem.mdRHS), mbEquationType);
		
		//solve LP
		try{
			double dObj = LP.minimize();
			if(dObj <= Double.NEGATIVE_INFINITY || dObj >= Double.POSITIVE_INFINITY){
				m_sSolutionStatus = "UNBOUNDED";
				m_sMessage = "The JunMa sample solver finds that the linear problem is unbounded.";
				return false;
			}
			if((dObj+"").equals("NaN")){
				m_sSolutionStatus = "INFEASIBLE";
				m_sMessage = "The JunMa sample solver cannot find a solution.";
				return false;
			}
			if(m_bMin){
				m_dOptimalValue = dObj + dObjConstant;
			}
			else{
				m_dOptimalValue = -dObj + dObjConstant;
			}
			m_mdSolution = new double[lpProblem.iCol];
			for(int i = 0; i < lpProblem.iCol; i++){
				m_mdSolution[i] = LP.getSolution().elementAt(i);
			}
		}
		catch(LPException e){
			String sException = e.toString();
			if(sException.indexOf("NoSolution") >= 0){
				m_sSolutionStatus = "INFEASIBLE";
				m_sMessage = "The JunMa sample solver cannot find a solution.";
			}
			else if(sException.indexOf("Unbounded") >= 0){
				m_sSolutionStatus = "UNBOUNDED";
				m_sMessage = "The JunMa sample solver finds that the linear problem is unbounded.";
			}
			else{
				m_sSolutionStatus = "UNKNOWN_LP";
				m_sMessage = "The JunMa sample solver encounters some unknown linear programming realted errors: " + sException + ".";
			}
			return false;
		}
		catch(Exception e){
			m_sSolutionStatus = "UNKNOWN_GENERAL";
			m_sMessage = "The JunMa sample solver encounters some general unknown errors: " + e.toString() + ".";
			return false;
		}
		return true;
	}//minimize
	
	/**
	 * Print the linear optimization problem.
	 *
	 * </p>
	 *
	 * @param lplpProblem holds the LP problem to be minimized.
	 */
	public void printProblem(JunMaOptProblem_LP lpProblem){
		//final int DOUBLE = 0;
		//final int BINARY = 1;
		//final int INTEGER = 2;
		final int LE = -1;
		final int EQ = 0;
		final int GE = 1;
		int i = 0;
		int j = 0;
		LinearProgrammingI LP = new DenseSimplex(lpProblem.iRow, lpProblem.iCol);
		double dR = LP.getRangeMax();
		double dL = LP.getRangeMin();
		if(dR < m_dRange) dR = m_dRange;
		if(dL < m_dEPS) dL = m_dEPS;
		LP.setRange(dL, dR);
		
		byte[] mbEquationType = new byte[lpProblem.iRow];
		for (i = 0; i < lpProblem.iRow; i++){
			if (lpProblem.miEquationType[i] == LE){
				mbEquationType[i] = LinearProgrammingI.LESS;
			}
			if (lpProblem.miEquationType[i] == EQ){
				mbEquationType[i] = LinearProgrammingI.EQUAL;
			}
			if (lpProblem.miEquationType[i] == GE){
				mbEquationType[i] = LinearProgrammingI.GREATER;
			}
		}
		System.out.print("MIN\t");
		for(j = 0; j < lpProblem.iCol; j++){
			System.out.print(lpProblem.mdObjCoef[j]+"X"+j);
			if(j != lpProblem.iCol-1){
				System.out.print(" + ");
			}
			else{
				System.out.println();
			}
		}
		System.out.println("S.T.");
		for(i = 0; i < lpProblem.iRow; i++){
			System.out.print(i+":\t");
			for(j=0; j<lpProblem.iCol; j++){
				System.out.print(lpProblem.mmdCoef[i][j]+"X"+j);
				if(j!=lpProblem.iCol-1){
					System.out.print(" + ");
				}
			}
			if(mbEquationType[i] ==LinearProgrammingI.LESS){
				System.out.print(" <= ");
			}
			else if(mbEquationType[i] ==LinearProgrammingI.GREATER){
				System.out.print(" >= ");
			}
			else{
				System.out.print(" = ");
			}
			System.out.print(lpProblem.mdRHS[i]+"\n");
		}
	}//printProblem
	
	/**
	 * Print the linear optimization solution.
	 */
	public void printSolution(){
		System.out.println("\nStatus: " + m_sSolutionStatus);
		System.out.println("\nMessge: " + m_sMessage);
		if(m_sSolutionStatus.equals("SOLVED")){
			System.out.println("\n\nObjective Value: " + m_dOptimalValue);
			System.out.println("Variable values: ");
			for(int i = 0; i < m_mdSolution.length; i++){
				System.out.println("X["+i+"]: " + m_mdSolution[i]);
			}
		}
	}//printSolution
	
	/**
	 * main for test purposes.
	 *
	 * </p>
	 *
	 * @param argv command line arguments.
	 */
	public static void main(String[] argv){
		
	}//main
	
}//class JunMaLPSolver

