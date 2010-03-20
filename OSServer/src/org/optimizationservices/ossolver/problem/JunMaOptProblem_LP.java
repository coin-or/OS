/**
 * @(#)JunMaOptProblem_LP 1.0 03/14/2004
 *
 * Copyright (c) 2004
 */
package org.optimizationservices.ossolver.problem;

import optimization.OptProblem;


/**
 *
 * <P>The <code>JunMaOptProblem_LP</code> class is an optimization problem that is
 * of the structure needed by the JunMaLinearSolver.
 *
 * </p>
 * @author Robert Fourer, Jun Ma, Kipp Martin
 * @version 1.0, 03/14/2004
 * @see org.optimizationservices.ossolver.solver.JunMaLPSolver
 * @since OS 1.0
 */
public class JunMaOptProblem_LP extends OptProblem{
	/**
	 * sDescription holds the description of the problem.
	 */
	public String sDescription = "JunMaOptProblem_LP";
	
	/**
	 * msRowName holds an array of strings of row names.
	 */
	public String[] msRowName = null;
	
	/**
	 * msRowName holds an array of strings of column names.
	 */
	public String[] msColName = null;
	
	/**
	 * constructor
	 */
	public JunMaOptProblem_LP(){
	}//constructor
	
	
	/**
	 * calculateObjectiveFunction is orginally used for nonlinear problems.
	 * Ignore for linear problems.
	 */
	public double calculateObjectiveFunction(double[] X){
		return 0;
	}//calculateObjectiveFunction
	
	/**
	 * calculateObjectiveFunction is orginally used for nonlinear problems.
	 * Ignore for linear problems.
	 */
	public double[] calculateConstraints(double[] X){
		return new double[0];
	}//calculateRegularConstraints
	
}//class JunMaOptProblem_LP


