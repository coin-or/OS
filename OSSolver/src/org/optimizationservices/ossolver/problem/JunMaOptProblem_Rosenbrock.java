/**
 * @(#)JunMaOptProblem_Rosenbrock 1.0 03/14/2004
 *
 * Copyright (c) 2004
 */
package org.optimizationservices.ossolver.problem;

/**
 * <p>The <code>JunMaOptProblem_Rosenbrock</code> class is an optimization problem that is
 * of the structure needed by the JunMaNLPSolver.</p>
 *
 * <p>Rosenbrock's function: (1, 1) -> 0 has a irregular and narrow surface shape close to optimum.</p>
 *
 * </p>
 * @author Robert Fourer, Jun Ma, Kipp Martin
 * @version 1.0, 03/14/2004
 * @see org.optimizationservices.ossolver.solver.JunMaLPSolver
 * @since OS 1.0
 */
import optimization.OptProblem;

public class JunMaOptProblem_Rosenbrock extends OptProblem{
	public JunMaOptProblem_Rosenbrock(){
		iVariableNumber = 2;
		iConstraintNumber= 2;
		super.initializeNLP();
		X[0]=0.5;
		X[1]=0.5;
		
		X_name[0]="X0";
		X_name[1]="X1";
		X_min[0]=-100;
		X_min[1]=-100;
		X_max[0]=-100;
		X_max[1]=100;
		
		dTolerance = 1e-5;
	}//constructor
	
	public double calculateObjectiveFunction(double[] X){
		try{Thread.sleep((long)(0*Math.random()));}catch(Exception e){}
		if(Math.random()<0.0){
			return 1/0;
		}
		else
			return 100*Math.pow(X[1]-X[0]*X[0],2)+Math.pow(1-X[0],2);
	}//calculateObjectiveFunction
	
	public double[] calculateConstraints(double[] X){
		double[] mdRes = new double[iConstraintNumber];
		mdRes[0]= /**/Math.pow(X[0]-10, 3)/**/;
		mdRes[1]= /**/Math.pow(X[1]-10, 3)/**/;
		return mdRes;
	}//calculateRegularConstraints
	
}//class
