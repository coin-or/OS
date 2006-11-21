/**
 * @(#)JunMaLPSolverFMLReader 1.0 03/14/2004
 *
 * Copyright (c) 2004
 */
package org.optimizationservices.ossolver.parser;

import org.optimizationservices.oscommon.representationparser.FMLReader;
import org.optimizationservices.oscommon.util.IOUtil;
import org.optimizationservices.ossolver.problem.JunMaOptProblem_LP;
import org.optimizationservices.ossolver.solver.JunMaLPSolver;

/**
 *
 * <P>The <code>JunMaLPSolverFMLReader</code> class extends<code>FMLReader</code>
 * class and implements the methods necessary for creating the linear programming
 * data structures for our sample JunMaLPsolver.
 *
 * </p>
 * @author Robert Fourer, Jun Ma, Kipp Martin
 * @version 1.0, 03/14/2004
 * @see org.optimizationservices.oscommon.representationparser.FMLReader
 * @see org.optimizationservices.ossolver.problem.JunMaOptProblem_LP
 * @see org.optimizationservices.ossolver.solver.JunMaLPSolver
 * @since OS 1.0
 */
public class JunMaLPSolverFMLReader extends FMLReader{
	
	/**
	 * JunMaLPSolver holds the sample JunMaLPsolver provided in the OS framework
	 * for illustration of real solver reader implementation.
	 */
	public JunMaLPSolver junmaLPSolver = null;
	
	/**
	 * JunMaOptProblem_LP holds the optimization problem structure accepted by the
	 * JunMaLPSolver.
	 */
	public JunMaOptProblem_LP junmaOptProblem_LP = null;
	
	/**
	 * constructor
	 */
	public JunMaLPSolverFMLReader(){
		junmaLPSolver = new JunMaLPSolver();
		junmaOptProblem_LP = new JunMaOptProblem_LP();
	}//constructor
	
	/**
	 * Receive notification when a linearProgramDescription is encountered.
	 *
	 * </p>
	 *
	 * @param source holds the source information of the optimization problem.
	 * @param variableCount holds the number of columns, i.e. variable number.
	 * @param constraintCount holds the number of rows, i.e. constraint number.
	 */
	public void onDescription(String source, int variableCount, int constraintCount){
		junmaOptProblem_LP.sDescription = source;
		junmaOptProblem_LP.iCol = variableCount;
		junmaOptProblem_LP.iRow = constraintCount*2+variableCount*2;//lb and ub for constraints and vars
		junmaOptProblem_LP.initializeLP();
	}//onDescription
	
	/**
	 * Receive notification when options are encountered.
	 *
	 * </p>
	 *
	 * @param optionNames holds the names of all the options.
	 * @param optionValues holds the values of all the options corresponding to the names.
	 * @return whether user wants to clear the arrays passed in to save memory
	 * if the arrays will still be referenced, a false value is to be returned.
	 */
	public boolean onOption(String[] optionNames, String[] optionValues){
		for(int i = 0; i < optionNames.length; i++){
			if(optionNames[i].equalsIgnoreCase("scaling")){
				junmaLPSolver.setAutomaticScaling((optionValues[i].equalsIgnoreCase("true"))?true:false);
			}
			if(optionNames[i].equalsIgnoreCase("range")){
				junmaLPSolver.setMaxIteration(Integer.parseInt(optionValues[i]));
			}
		}
		return true;
	}//onOption
	
	/**
	 * Receive notification when variables are encountered.
	 *
	 * </p>
	 *
	 * @param variableNames holds the names of all the columns, i.e. variable names.
	 * @param variableLbs holds the values of lower bounds for the variables.
	 * @param variableUbs holds the values of upper bounds for the variables.
	 * @param variableDomains holds the types of all the variables, (e.g. 'C' for continuous type,
	 * 'I' for integer type, and 'B' for binary type).
	 * @return whether user wants to clear the arrays passed in to save memory
	 * if the arrays will still be referenced, a false value is to be returned.
	 */
	public boolean onVariables(String[] variableNames, double[] variableLbs, double[] variableUbs,
			char[] variableDomains){
		System.gc();
		int iRowSize = junmaOptProblem_LP.iRow;
		int iColSize = junmaOptProblem_LP.iCol;
		int iRegularConstraintSize = iRowSize - iColSize*2;
		//variable boundary constraints (after the regular constraints)
		int i = 0;
		int j = 0;
		if(junmaOptProblem_LP.msRowName ==null) junmaOptProblem_LP.msRowName = new String[iRowSize];
		for(i = iRegularConstraintSize; i < iRowSize; i+=2){
			String sVariableName = (variableNames[j].length()<=0)?("X"+i):variableNames[j];
			//Xi >= Xi_lb
			junmaOptProblem_LP.msRowName[i] = sVariableName+"_lb";
			junmaOptProblem_LP.mmdCoef[i][j] = 1;
			junmaOptProblem_LP.miEquationType[i]= 1;
			junmaOptProblem_LP.mdRHS[i] = variableLbs[j];
			//Xi <= Xi_ub
			junmaOptProblem_LP.msRowName[i+1] = sVariableName+"_ub";
			junmaOptProblem_LP.mmdCoef[i+1][j] = 1;
			junmaOptProblem_LP.miEquationType[i+1]= -1;
			junmaOptProblem_LP.mdRHS[i+1] = variableUbs[j];
			j++;
		}
		//variables
		junmaOptProblem_LP.msColName = new String[iColSize];
		for(j = 0; j < iColSize; j++){
			junmaOptProblem_LP.msColName[j] = (variableNames[j].length()<=0)?("X"+j):variableNames[j];
			switch(variableDomains[j]){
			case 'B':
				junmaOptProblem_LP.miVarType[j] = 1;
				break;
			case 'I':
				junmaOptProblem_LP.miVarType[j] = 2;
				break;
			default:
				junmaOptProblem_LP.miVarType[j] = 0;
			break;
			}
		}
		return true;
	}//onVariables
	
	/**
	 * Receive notification when constraints are encountered.
	 *
	 * <p>The constraint information contains all the information about the linear constraints
	 * except for the AMatrix, which is notified in the {@link #onAMatrix onAMatrix} method.
	 *
	 * </p>
	 *
	 * @param constraintNames holds the names of all the rows, i.e. constraint names.
	 * @param constraintLhs holds the values of the lower bounds for the constraints.
	 * @param constraintRhs holds the values of the upper bounds for the constraints.
	 * @return whether user wants to clear the arrays passed in to save memory
	 * if the arrays will still be referenced, a false value is to be returned.
	 * @see #onAMatrix
	 */
	public boolean onConstraints(String[] constraintNames, double[] constraintLhs, double[] constraintRhs){
		System.gc();
		int iRowSize = junmaOptProblem_LP.iRow;
		int iColSize = junmaOptProblem_LP.iCol;
		int iRegularConstraintSize = iRowSize - iColSize*2;
		if(junmaOptProblem_LP.msRowName ==null) junmaOptProblem_LP.msRowName = new String[iRowSize];int i = 0;
		int j = 0;
		for(i = 0; i < iRegularConstraintSize; i+=2){
			String sConstraintName = (constraintNames[j].length()<=0)?("C"+i):constraintNames[j];
			//Ci >= Ci_lb
			junmaOptProblem_LP.msRowName[i] = sConstraintName+"_lb";
			junmaOptProblem_LP.miEquationType[i]= 1;
			junmaOptProblem_LP.mdRHS[i] = constraintLhs[j];
			//Ci <= Ci_ub
			junmaOptProblem_LP.msRowName[i+1] = sConstraintName+"_ub";
			junmaOptProblem_LP.miEquationType[i+1]= -1;
			junmaOptProblem_LP.mdRHS[i+1] = constraintRhs[j];
			j++;
		}
		return true;
	}//onConstraints
	
	/**
	 * Receive notification when an AMatrix is encountered.
	 *
	 * <p>The AMatrix stores all the information in the A part of the linear constraints lhs<=AX<=rhs</p>
	 *
	 * </p>
	 *
	 * @param isColumnMajor holds the value of whether the AMatrix holding linear program data is stored by column.
	 * If false, the matrix is stored by row.
	 * @param nonzeroValues holds the values of the vector element nonz in AMatrix, which contains nonzero elements.
	 * @param nonzeroIndexes holds the values of the vector element rowIdx or colIdx in AMatrix. If the matrix is
	 * stored by column (row), rowIdx (colIdx) is the vector of row (column) indexes.
	 * @param endIndexes holds the values of the vector element pntANonz in AMatrix, which points to the end of a
	 * column (row) of nonzero elements in AMatrix.
	 * @param numberOfNonzeros holds the values of the vector element numNonz in AMatrix. The vector numNonz,
	 * if present, stores the number of nonzero elements in the column (row). If numNonz is not present, then
	 * nonz stores the columns (rows) in matrix order.
	 * @return whether user wants to clear the arrays passed in to save memory if the arrays will still be referenced,
	 * a false value is to be returned.
	 */
	public boolean onAMatrix(boolean isColumnMajor, double[] nonzeroValues, int[] nonzeroIndexes,
			int[] endIndexes, int[] numberOfNonzeros){
		System.gc();
		//This sample linear solver does not utitilize numberOfNonzeros argument.
		int iBeginIndex = 0;
		int iRow = 0;
		int iCol = 0;
		for(int i = 0; i < endIndexes.length; i++){
			if(isColumnMajor) iCol = i;
			else iRow = 2*i; //each constaint has left and right hand sides
			for(int j = iBeginIndex; j < endIndexes[i]; j++){
				if(isColumnMajor) iRow = 2*nonzeroIndexes[j]; //each constaint has left and right hand sides
				else iCol = nonzeroIndexes[j];
				junmaOptProblem_LP.mmdCoef[iRow][iCol] = nonzeroValues[j];
				junmaOptProblem_LP.mmdCoef[iRow+1][iCol] = nonzeroValues[j];
			}
			iBeginIndex = endIndexes[i];
		}
		return true;
	}//onAMatrix
	
	/**
	 *
	 * Receive notification when an objective function is encountered.
	 *
	 * </p>
	 *
	 * @param isMinimization holds whether the objective is minimization or not.
	 * @param objectiveConstant holds the value of objective function constant.
	 * @param ObjectiveCoefficients	holds the values of the objective function coefficients.
	 * @return whether user wants to clear the arrays passed in to save memory if the arrays
	 * will still be referenced, a false value is to be returned.
	 */
	public boolean onObjective(boolean isMinimization, double objectiveConstant, double[] ObjectiveCoefficients){
		int iSign = isMinimization?1:-1;
		junmaLPSolver.setMin(isMinimization);
		for(int i = 0; i < ObjectiveCoefficients.length; i++){
			junmaOptProblem_LP.mdObjCoef[i] = iSign*ObjectiveCoefficients[i];
		}
		junmaOptProblem_LP.dObjConstant = objectiveConstant;
		return true;
	}//onObjective
	
	/**
	 * main for test purposes.
	 *
	 * </p>
	 *
	 * @param argv command line arguments.
	 */
	public static void main(String[] argv) {
		JunMaLPSolverFMLReader fmlReader = new JunMaLPSolverFMLReader();
		boolean bRead = false;
		//bRead = fmlReader.readFile("xml/lpfml/lpfml_1.xml");
		String sFML = IOUtil.fileToString("xml/lpfml/lpparinc.xml");
		bRead = fmlReader.readString(sFML);
		System.out.println(bRead);
		System.out.println("Done Reading");
		fmlReader.junmaLPSolver.minimize(fmlReader.junmaOptProblem_LP);
		fmlReader.junmaLPSolver.printProblem(fmlReader.junmaOptProblem_LP);
		fmlReader.junmaLPSolver.printSolution();
	}//main
	
}//class JunMaLPSolverFMLReader
