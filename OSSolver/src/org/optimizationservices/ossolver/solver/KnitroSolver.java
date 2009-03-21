package org.optimizationservices.ossolver.solver;
import it.unimi.dsi.fastutil.ints.Int2DoubleOpenHashMap;

import org.optimizationservices.oscommon.representationparser.OSiLReader;

public class KnitroSolver {
	/** The class constructor */
	public KnitroSolver() {
	}

	/**
	 * m_osilReader holds all the problem parameters and routines to be used 
	 * for an optimization solver. 
	 */
	private OSiLReader m_osilReader = null;
	
	/**
	 * m_mdSolution holds an array of current solution. 
	 */
	public double[] m_mdSolution = null;
	

	/**
	 * m_bMin holds whether the objective is minimization or not. 
	 */
	private boolean m_bMin = true;
	
	/**
	 * m_dObjCoef holds an array of objective coefficients. 
	 */
	private double[] m_mdObjCoef = null;
	
	/** below is a Knitro constant -- the Knitro infinity */
	private static final double KTR_INFBOUND = Double.POSITIVE_INFINITY;

	/** number of variables in the model */
	private int numvar;

	/** number of constraints in the model */
	private int numcon;

	/** number of nonzeros terms in sparse Jacoban */
	private int nnzj;

	/** number of nonzeros in upper triange of sparse Hessian */
	// note we won's use this
	private int nnzh;

	/** the type of objective function */
	private int ftype;

	/** upper bound on each variable */
	double bu[];

	/** lower bound on each variable */
	double bl[];

	/** upper bound on each constraint */
	double cu[];

	/** lower bound on each constraint */
	double cl[];

	/** the constraint types */
	int ctype[];

	/** the initial point */
	double[] x;

	/** indvar[i] = j if cjac[i] comes from taking a partial with respect to variable j */
	int indvar[];

	/** indfun[i] = k , then cjac[i] refers to kth constraint*/
	int indfun[];

	/** this is the only native (C code) method it uses the method arguments
	 * to create a problem instance  
	 */
	private native void nativeMain(int numvar, int numcon, int nnzj, int nnzh,
			int ftype, double bl[], double bu[], double cl[], double cu[],
			int ctype[], double x[], int indvar[], int indfun[]);

	/** this Java function corresponds to the Knitro callback function
	 * evalc -- it gets called from the Knitro function
	 * @param x -- the solution n-vector
	 * @param c -- an m-vector, the  value of each constraint
	 * @return -- the objective function value of the current soluiton
	 */
	protected double javaEvalfc(double[] x, double[] c) {
		// work for Jun
		// replace the calculation below with calls to our Java OSiL Reader
		double result = m_osilReader.calculateFunction(-1, x);
		for(int i = 0; i < numcon; i++){
			c[i] = m_osilReader.calculateFunction(i, x);
		}
		// end Jun work
		
		/* original sample
		double result = 1.0e3 - x[0] * x[0] - 2.0e0 * x[1] * x[1] - x[2] * x[2] - x[0] * x[1] - x[0] * x[2];
		// Equality constraint. 
		c[0] = 8.0e0 * x[0] + 14.0e0 * x[1] + 7.0e0 * x[2] - 56.0e0;

		// Inequality constraint.
		c[1] = x[0] * x[0] + x[1] * x[1] + x[2] * x[2] - 25.0e0;
		*/
		m_mdSolution = x;
		
		if(!m_bMin) result *= -1;
		return result;
	}
	
	/** This function is called from the Knitro callback function evalga
	 * 
	 * @param x -- solution n vector of current iteration
	 * @param fgrad -- return the value of the obj gradient
	 * @param cjac -- return the value of sparse constraint gradients
	 */
	protected void javaEvalga(double[] x, double[] fgrad, double[] cjac) {
		/*
		 * work for Jun replace the calculation below with calls to our Java lib
		 * calculate gradient of objective function as a dense vector calculate
		 * the gradient of the constraints as a sparse vector
		 */
		if(m_mdObjCoef == null){
			m_mdObjCoef = m_osilReader.getFirstDenseObjectiveCoefficientValues();
		}
		Int2DoubleOpenHashMap nonlinearObjGrad = m_osilReader.calculateNonlinearDerivatives(-1, x, false);
		double dNonlinearObjGrad = 0;
		for(int i = 0; i < numvar; i++){
			dNonlinearObjGrad = 0;
			if(nonlinearObjGrad != null){
				dNonlinearObjGrad = nonlinearObjGrad.get(i);
			}
			fgrad[i] = m_mdObjCoef[i] + dNonlinearObjGrad;
			if(!m_bMin) fgrad[i] *= -1;
		}
		double dNonlinearConGrad = 0;
		//String sNonlinearConGrad = "0";
		int iRow = -1;
		int iCol = -1;
		Int2DoubleOpenHashMap nonlinearConGrad = null;
		boolean bRowChange = false;
		for(int i = 0; i < nnzj; i++){
			if(indfun[i] != iRow){ 
				iRow = indfun[i];
				bRowChange = true;
			}
			else{
				bRowChange = false;
			}
			if(bRowChange) nonlinearConGrad = m_osilReader.calculateNonlinearDerivatives(iRow, x, true);
			iCol = indvar[i];
			dNonlinearConGrad = 0;
			if(nonlinearConGrad != null){
				dNonlinearConGrad = nonlinearConGrad.get(iCol);
			}
			cjac[i] = m_osilReader.getLinearConstraintCoefficient(iRow, iCol) + dNonlinearConGrad;
		}
		// end Jun work
		
		/* orginal sample
		fgrad[0] = -2.0e0 * x[0] - x[1] - x[2];
		fgrad[1] = -4.0e0 * x[1] - x[0];
		fgrad[2] = -2.0e0 * x[2] - x[0];

		// Gradient of the first constraint, c[0]. 

		cjac[0] = 8.0e0;
		cjac[1] = 14.0e0;
		cjac[2] = 7.0e0;

		// Gradient of the second constraint, c[1]. 

		cjac[3] = 2.0e0 * x[0];
		cjac[4] = 2.0e0 * x[1];
		cjac[5] = 2.0e0 * x[2];
		*/
	}

	/**
	 * The main solve routine. It sets the problem parameters from the OSiLReader.
	 * This method calls the native method method nativeMain which then
	 * call the Knitro solve routine
	 * 
	 * 
	 * @param osilReader holds all the problem parameters and routines to be used 
	 * for an optimization solver. 
	 * @return a string that contains the solution. 
	 */
	public String solve(OSiLReader osilReader) {
		m_osilReader = osilReader;
		String sResult = "";
		int i;

		m_bMin = m_osilReader.getFirstObjectiveMaxOrMin().equals("min");
		numvar = m_osilReader.getVariableNumber();
		sResult += ("numvar: " + numvar + "\n");

		numcon = m_osilReader.getConstraintNumber();
		sResult += ("numcon: " + numcon + "\n");

		int[][] mmIndexes = m_osilReader.getJacobianNonzeroIndexes();		
		nnzj = (mmIndexes[0]==null)?0:mmIndexes[0].length;
		sResult += ("nnzj: " + nnzj + "\n");

		nnzh = 0;
		sResult += ("nnzh: " + nnzh + "\n");

		if(m_osilReader.getNonlinearExpression(-1) == null) ftype = 1;
		else if(m_osilReader.getNonlinearQuadraticTerms(-1).size() > 0) ftype = 2;
		else ftype = 0;
		sResult += ("ftype: " + ftype + "\n");

		bl = m_osilReader.getVariableLowerBounds();
		bu = m_osilReader.getVariableUpperBounds();
		for (i = 0; i < numvar; i++) {
			sResult += ("bl[" + i + "]: " + bl[i] + "\n");
			sResult += ("bu" + i + "]: " + bu[i] + "\n");
		}
		
		cl = m_osilReader.getConstraintLowerBounds();
		cu = m_osilReader.getConstraintUpperBounds();
		for (i = 0; i < numcon; i++) {
			sResult += ("cl[" + i + "]: " + cl[i] + "\n");
			sResult += ("cu" + i + "]: " + cu[i] + "\n");
		}

		ctype = new int[numcon];
		for (i = 0; i < numcon; i++) {
			if(m_osilReader.getNonlinearExpression(i) == null) ctype[i] = 1;
			else if(m_osilReader.getNonlinearQuadraticTerms(i).size() > 0) ctype[i] = 2;
			else ctype[i] = 0;
			sResult += ("ctype" + i + "]: " + ctype[i] + "\n");
		}
		
//		double[] mdX = m_osilReader.getVariableInitialValues();
//		if(mdX == null) mdX = new double[numvar];
//		for (i = 0; i < numvar; i++) {
//			sResult += ("x[" + i + "]: " + mdX[i] + "\n");
//		}

		indvar = new int[nnzj];
		indfun = new int[nnzj];
		for(i = 0; i < nnzj; i++){
			indfun[i] = mmIndexes[0][i];
			indvar[i] = mmIndexes[1][i];
			sResult += ("indfun[" + i + "]: " + indfun[i] + "\n");
			sResult += ("indvar[" + i + "]: " + indvar[i] + "\n");				
		}
		/** this is the native method that takes the problem parameters
		 * and sets up the model. It also calls Knitro solve. Knitro solve 
		 * then makes callbacks to the Java methods javaEvalfc and javaEvalga
		 */
		nativeMain(numvar, numcon, nnzj, nnzh, ftype, bl, bu, cl, cu, ctype, x, indvar, indfun);
		
		for(i = 0; i < m_mdSolution.length; i++){
			sResult += ("X[" + i + "]: " + m_mdSolution[i] + "\n");
		}
		double dResult = (osilReader.calculateLinearFunction(-1, m_mdSolution) +
				osilReader.calculateNonlinearFunction(-1, m_mdSolution));
		sResult += ("objective: " + dResult + "\n");
		return sResult;
	}
	
	/** Here is the main routine it sets the problem problem parameters
	 * these data come from the OSiL Reader
	 * this method also calls the native method method nativeMain which then
	 * call the Knitro solve routine
	 * @param args -- no command line parameters
	 */
	public static void main(String[] args) {
		KnitroSolver knitro = new KnitroSolver();
		int i;
		// Jun -- below change to get values from OSiLReader
		knitro.numvar = 3;
		knitro.numcon = 2;
		knitro.nnzj = 6;
		knitro.nnzh = 0;
		knitro.ftype = 2;
		knitro.bl = new double[knitro.numvar];
		knitro.bu = new double[knitro.numvar];
		for (i = 0; i < knitro.numvar; i++) {
			knitro.bl[i] = 0.0e0;
			knitro.bu[i] = KTR_INFBOUND;
		}
		knitro.cl = new double[knitro.numcon];
		knitro.cu = new double[knitro.numcon];
		knitro.cl[0] = 0.0e0;
		knitro.cl[1] = 0.0e0;
		knitro.cu[0] = 0.0e0;
		knitro.cu[1] = KTR_INFBOUND;
		//
		knitro.ctype = new int[knitro.numcon];
		knitro.ctype[0] = 1;
		knitro.ctype[1] = 2;
		//
		knitro.x = new double[knitro.numvar];
		knitro.x[0] = 2.0e0;
		knitro.x[1] = 2.0e0;
		knitro.x[2] = 2.0e0;
		//
		knitro.indvar = new int[knitro.nnzj];
		knitro.indfun = new int[knitro.nnzj];

		knitro.indvar[0] = 0;
		knitro.indfun[0] = 0;

		knitro.indvar[1] = 1;
		knitro.indfun[1] = 0;

		knitro.indvar[2] = 2;
		knitro.indfun[2] = 0;

		knitro.indvar[3] = 0;
		knitro.indfun[3] = 1;

		knitro.indvar[4] = 1;
		knitro.indfun[4] = 1;

		knitro.indvar[5] = 2;
		knitro.indfun[5] = 1;
		/** this is the native method that takes the problem parameters
		 * and sets up the model. It also calls Knitro solve. Knitro solve 
		 * then makes callbacks to the Java methods javaEvalfc and javaEvalga
		 */
		knitro.nativeMain(knitro.numvar, knitro.numcon, knitro.nnzj,
				knitro.nnzh, knitro.ftype, knitro.bl, knitro.bu,
				knitro.cl, knitro.cu, knitro.ctype, knitro.x,
				knitro.indvar, knitro.indfun);
	}
	
	static {
		System.loadLibrary("./Knitro/KnitroSolver"); //C:\WINDOWS\SYSTEM32 for windows
	}
}