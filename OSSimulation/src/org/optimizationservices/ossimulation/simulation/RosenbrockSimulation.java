/**
 * @(#)RosenbrockSimulation 1.0 03/14/2004
 *
 * Copyright (c) 2004
 */
package org.optimizationservices.ossimulation.simulation;


/**
 * <p>The <code>RosenbrockSimulation</code> class is an simulation that calculates
 * Rosenbrock function: 100*(X1-X0*X0)^2+(1-X[0])^2.</p>
 * 
 * <p>Rosenbrock's function: (1, 1) -> 0 has a irregular and narrow surface shape close to optimum.</p>
 *
 * 
 * @author Robert Fourer, Jun Ma, Kipp Martin
 * @version 1.0, 03/14/2004
 * @see org.optimizationservices.ossimulation.api.OScL
 * @since OS 1.0
 */
public class RosenbrockSimulation{
	
	/**
	 * Constructor.
	 *
	 */
	public RosenbrockSimulation(){
		
	}//Constructor
	
	/**
	 * Calculate Rosenbrock function: 100*(X1-X0*X0)^2+(1-X[0])^2. 
	 * 
	 * @param X0 holds the first input for Rosenbrock function.
	 * @param X1 holds the second input for Rosenbrock function.
	 * @return the Rosenbrock function value. 
	 */
	public double calculate(double X0, double X1){
		return 100*Math.pow(X1-X0*X0,2)+Math.pow(1-X0,2);
	}//calculate
	
	/**
	 * main for test purposes.
	 *
	 * </p>
	 *
	 * @param argv command line arguments.
	 */
	public static void main(String[] argv){
		RosenbrockSimulation rosenbrockSimulation = new RosenbrockSimulation();
		double dResult = rosenbrockSimulation.calculate(1, 1);
		System.out.println("RosenbrockSimulation: " + dResult);		
	}//main
	
}//class RosenbrockSimulation
