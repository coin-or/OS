/**
 * @(#)JunMaOptProblem_Beale 1.0 03/14/2004
 *
 * Copyright (c) 2004
 */
package org.optimizationservices.ossolver.problem;

import optimization.OptProblem;

/**
 * <p>The <code>JunMaOptProblem_Beale</code> class is an optimization problem that is
 * of the structure needed by the JunMaNLPSolver.</p>
 *
 * <p>Beale's function: (3, 1/2) -> 0 has a valley approaching the line X[1]=1.</p>
 *
 * </p>
 * @author Robert Fourer, Jun Ma, Kipp Martin
 * @version 1.0, 03/14/2004
 * @see org.optimizationservices.ossolver.solver.JunMaLPSolver
 * @since OS 1.0
 */
public class JunMaOptProblem_Beale extends OptProblem{
	public JunMaOptProblem_Beale(){
		iVariableNumber = 2;  iConstraintNumber= 2;
		super.initializeNLP();
		dTolerance = 1e-5;
		X[0]=0.5;
		X[1]=5;
	}//constructor
	
	public double calculateObjectiveFunction(double[] X){
		return Math.pow(1.5-X[0]*(1-X[1]),2)
		+Math.pow(2.25-X[0]*(1-X[1]*X[1]),2)
		+Math.pow(2.625-X[0]*(1-X[1]*X[1]*X[1]),2);
	}//calculateObjectiveFunction
	
	public double[] calculateConstraints(double[] X){
		double[] mdRes = new double[iConstraintNumber];
		mdRes[0]= Math.pow(X[0]-1, 1);
		mdRes[1]= Math.pow(X[1]-1, 1);
		return mdRes;
	}//calculateRegularConstraints
	
}//class


