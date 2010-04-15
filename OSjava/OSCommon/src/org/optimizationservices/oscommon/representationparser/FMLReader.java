/**
 * @(#)FMLReader 1.0 03/14/2004
 *
 * Copyright (c) 2004
 */
package org.optimizationservices.oscommon.representationparser;

import org.optimizationservices.oscommon.util.IOUtil;
import org.optimizationservices.oscommon.util.XMLUtil;



/**
 *
 * <P>The <code>FMLReader</code> class creates the <code>SAX2XMLReader</code>
 * parser object. Associated with the FMLReader class are numerous virtual "on" methods
 * that when called by an <code>FMLHandler</code> object create the necessary data
 * structures for the solver. In FMLReader these methods are empty and the solver
 * specific classes that extends from <code>FMLReader</code> are responsible for the
 * actual implementation of these methods. Each "on" method has a corresponding
 * opposite "set" method in the {@link org.optimizationservices.oscommon.representationparser.FMLWriter FMLWriter}
 * class. There is no specific sequence the user should follow to invoke these on methods. </p>
 *
 * </p>
 *
 * @author Robert Fourer, Jun Ma, Kipp Martin
 * @version 1.0, 03/14/2004
 * @see org.optimizationservices.oscommon.representationparser.FMLHandler
 * @see org.optimizationservices.oscommon.representationparser.FMLWriter
 * @see org.xml.sax.XMLReader
 * @since OS 1.0
 */
public class FMLReader{
	
	/**
	 * bXsdValidate holds whether the parser should be validating against the schema or not.
	 */
	protected boolean m_bXsdValidate = false;
	
	/**
	 * m_sSchemaFile holds the file name of the LPFML Schema to validate any LPFML linear instance.
	 */
	String m_sSchemaFile = "xml/lpfml/lpfml.xsd";
	
	/**
	 * m_sOSiL holds an OSiL instance that is converted from the FML instance. 
	 */
	private String m_sOSiL = null;
	
	/**
	 * m_sSource holds the source information of the optimization problem.
	 */
	private String m_sSource = "";
	 
	/**
	 * m_iVariableCount holds the number of columns, i.e. variable number.
	 */
	private int m_iVariableCount;
	
	/**
	 * m_iConstraintCount holds the number of rows, i.e. constraint number.
	 */
	private int m_iConstraintCount;

	/**
	 * m_msVariableNames holds the names of all the columns, i.e. variable names.
	 */
	private String[] m_msVariableNames = null;
	 
	 /**
	  * m_mdVariableLbs holds the values of lower bounds for the variables.
	  */
	 private double[] m_mdVariableLbs = null;
	 
	 /**
	  * m_mdVariableUbs holds the values of upper bounds for the variables.
	  */
	 private double[] m_mdVariableUbs = null;
	 
	 /**
	  * m_mcVariableDomains holds the types of all the variables, (e.g. 'C' for continuous
	  * type, 'I' for integer type, and 'B' for binary type).
	  */
	 private char[] m_mcVariableDomains = null;
	 
	 /**
	  * m_msConstraintNames holds the names of all the rows, i.e. constraint names.
	  */
	 private String[] m_msConstraintNames;
	 
	 /**
	  * m_mdConstraintLhs holds the values of the lower bounds for the constraints.
	  */
	 private double[] m_mdConstraintLhs = null;
	 
	 /**
	  * m_mdConstraintRhs holds the values of the upper bounds for the constraints.
	  */
	 private double[] m_mdConstraintRhs = null;
	 
	 /**
	  * m_bColumnMajor holds the value of whether the AMatrix holding linear program data is stored
	  * by column. If false, the matrix is stored by row.
	  */
	 private boolean m_bColumnMajor = true;
	 
	 /**
	  * m_mdNonzeroValues holds the values of the vector element nonz in AMatrix, which contains nonzero elements.
	  */
	 private double[] m_mdNonzeroValues = null;

	 /**
	  * m_miNonzeroIndexes holds the values of the vector element rowIdx or colIdx in AMatrix. If the matrix is
	  * stored by column (row), rowIdx (colIdx) is the vector of row (column) indices.
	  */
	 private int[] m_miNonzeroIndexes = null;
	 
	 /**
	  * m_miStartIndexes holds the values of the vector element pntANonz in AMatrix, which points to the end of a
	  * column (row) of nonzero elements in AMatrix.
	  */
	 private int[] m_miStartIndexes = null;
	 
	 /**
	  * m_bMinimization holds whether the objective is minimization or not.
	  */
	 private boolean m_bMinimization = true;
	 
	 /**
	  * m_dObjectiveConstant holds the value of objective function constant.
	  */
	 private double m_dObjectiveConstant = 0.0;
	 
	 /**
	  * m_mdObjectiveCoefficients holds the values of the objective function coefficients.
	  */
	 private double[] m_mdObjectiveCoefficients = null;
	 
	/**
	 * constructor
	 */
	public FMLReader(){
		
	}//constructor
	
	/**
	 * @return whether the parser should be validating against the schema or not.
	 */
	public boolean isValidate(){
		return m_bXsdValidate;
	}//isValidate
	
	/**
	 * @param xsdValidate holds whether the parser should be validating against the schema or not.
	 */
	public void setValidate(boolean xsdValidate){
		m_bXsdValidate = xsdValidate;
	}//setValidate
	
	/**
	 * Read the xml file that contains the FML linear program instance.
	 *
	 * </p>
	 *
	 * @param fileName holds the xml filename that contains the FML linear program instance
	 * @return whether the file is read successfully without any error.
	 */
	public boolean readFile(String fileName){
		FMLHandler fmlHandler = new FMLHandler(this);
		boolean bRead = XMLUtil.parseFileUsingSAX(fileName, fmlHandler, m_bXsdValidate);
		if(fmlHandler.m_bError || fmlHandler.m_bFatalError) bRead = false;
		return bRead;
	}//readFile
	
	/**
	 * Read the xml string that contains the FML linear program instance.
	 *
	 * </p>
	 *
	 * @param fmlString	holds the xml string that contains the FML linear program instance
	 * @return whether the string is read successfully without any error.
	 */
	public boolean readString(String fmlString){
		FMLHandler fmlHandler = new FMLHandler(this);
		boolean bRead =  XMLUtil.parseStringUsingSAX(fmlString, fmlHandler, m_bXsdValidate);
		if(fmlHandler.m_bError || fmlHandler.m_bFatalError) bRead = false;
		return bRead;
	}//readString
	
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
		m_sSource = source;
		m_iVariableCount = variableCount;
		m_iConstraintCount = constraintCount;
	}//onDescription
	
	/**
	 * Receive notification when options are encountered.
	 *
	 * </p>
	 *
	 * @param optionNames holds the names of all the options.
	 * @param optionValues holds the values of all the options corresponding to the names.
	 * @return whether user wants to clear the arrays passed in to save memory if the arrays
	 * will still be referenced, a false value is to be returned.
	 */
	public boolean onOption(String[] optionNames, String[] optionValues){
		return true;
	}//onOption
	
	/**
	 * Receive notification when variables are encountered.
	 * </p>
	 *
	 * @param variableNames holds the names of all the columns, i.e. variable names.
	 * @param variableLbs holds the values of lower bounds for the variables.
	 * @param variableUbs holds the values of upper bounds for the variables.
	 * @param variableDomains holds the types of all the variables, (e.g. 'C' for continuous
	 * type, 'I' for integer type, and 'B' for binary type).
	 * @return whether user wants to clear the arrays passed in to save memory if the arrays
	 * will still be referenced, a false value is to be returned.
	 */
	public boolean onVariables(String[] variableNames, double[] variableLbs, double[] variableUbs,
			char[] variableDomains){
		m_msVariableNames = variableNames;
		m_mdVariableLbs = variableLbs;
		m_mdVariableUbs = variableUbs;
		m_mcVariableDomains = variableDomains;
		return true;
	}//onVariables
	
	/**
	 * Receive notification when constraints are encountered.
	 *
	 * <p>The constraint information contains all the information about the linear constraints
	 * except for the AMatrix, which is notified in the {@link #onAMatrix onAMatrix} method.</p>
	 *
	 * </p>
	 *
	 * @param constraintNames holds the names of all the rows, i.e. constraint names.
	 * @param constraintLhs holds the values of the lower bounds for the constraints.
	 * @param constraintRhs holds the values of the upper bounds for the constraints.
	 * @return whether user wants to clear the arrays passed in to save memory if the arrays
	 * will still be referenced, a false value is to be returned.
	 * @see #onAMatrix
	 */
	public boolean onConstraints(String[] constraintNames, double[] constraintLhs, double[] constraintRhs){
		m_msConstraintNames = constraintNames;
		m_mdConstraintLhs = constraintLhs;
		m_mdConstraintRhs = constraintRhs;
		return true;
	}//onConstraints
	
	/**
	 * Receive notification when an AMatrix is encountered.
	 *
	 * <p>The AMatrix stores all the information in the A part of the linear constraints lhs<=AX<=rhs</p>
	 *
	 * </p>
	 *
	 * @param isColumnMajor holds the value of whether the AMatrix holding linear program data is stored
	 * by column. If false, the matrix is stored by row.
	 * @param nonzeroValues holds the values of the vector element nonz in AMatrix, which contains nonzero elements.
	 * @param nonzeroIndexes holds the values of the vector element rowIdx or colIdx in AMatrix. If the matrix is
	 * stored by column (row), rowIdx (colIdx) is the vector of row (column) indices.
	 * @param endIndexes holds the values of the vector element pntANonz in AMatrix, which points to the end of a
	 * column (row) of nonzero elements in AMatrix.
	 * @param numberOfNonzeros holds the values of the vector element numNonz in AMatrix. The vector numNonz, if
	 * present, stores the number of nonzero elements in the column (row). If numNonz is not present, then nonz
	 * stores the columns (rows) in matrix order. If the matrix is stored by column (row), rowIdx (colIdx) is
	 * the vector of row (column) indices.
	 * @return whether user wants to clear the arrays passed in to save memory if the arrays
	 * will still be referenced, a false value is to be returned.
	 */
	public boolean onAMatrix(boolean isColumnMajor, double[] nonzeroValues, int[] nonzeroIndexes,
			int[] endIndexes, int[] numberOfNonzeros){
		m_bColumnMajor = isColumnMajor;
		m_mdNonzeroValues = nonzeroValues;
		m_miNonzeroIndexes = nonzeroIndexes;
		m_miStartIndexes = new int[endIndexes.length + 1];
		m_miStartIndexes[0] = 0;
		for(int i = 1; i < m_miStartIndexes.length; i++){
			m_miStartIndexes[i] =  endIndexes[i-1];
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
		m_bMinimization = isMinimization;
		m_dObjectiveConstant = objectiveConstant;
		m_mdObjectiveCoefficients = ObjectiveCoefficients;
		return true;
	}//onObjective
	
	/**
	 *
	 * Receive notification when an objective solution is encountered. It only provides general
	 * solution information.
	 *
	 * <p>The information does not include primal and dual solutions which are notified
	 * in the {@link #onPrimalSolution onPrimalSolution} and {@link #onDualSolution onDualSolution}
	 * methods.</p>
	 *
	 * </p>
	 *
	 * @param statusId holds the information of optimization solution status id.
	 * @param status holds the status message of the optimization solution.
	 * @param solverMessage holds the value of solver message.
	 * @param optimalValue holds the value of the optimal solution.
	 * @see #onPrimalSolution
	 * @see #onDualSolution
	 */
	public void onSolution(String statusId, String status, String solverMessage, double optimalValue){
	}//onSolution
	
	/**
	 * Receive notification when primal solutions are encountered.
	 *
	 *</p>
	 *
	 * @param priamlNames holds the names of primal variable solutions. It may be empty.
	 * @param primalValues holds the values of primal variable solutions corresponding to the primalIndexes.
	 * @param primalIndexes holds the indexes of primal variable solutions corresponding to the primalValues.
	 * @return whether user wants to clear the arrays passed in to save memory if the arrays will still be
	 * referenced, a false value is to be returned.
	 */
	public boolean onPrimalSolution(String[] primalNames, double[] primalValues, int[] primalIndexes){
		return true;
	}//onPrimalSolution
	
	/**
	 * Receive notification when dual solutions are encountered.
	 *
	 *</p>
	 *
	 * @param dualNames holds the names of dual variable solutions. It may be empty.
	 * @param dualValues holds the values of dual variable solutions corresponding to the primalIndexes.
	 * @param dualIndexes holds the indexes of dual variable solutions corresponding to the primalValues.
	 * @return whether user wants to clear the arrays passed in to save memory if the arrays will still
	 * be referenced, a false value is to be returned.
	 */
	public boolean onDualSolution(String[] dualNames, double[] dualValues, int[] dualIndexes){
		return true;
	}//onDualSolution
	
	/**
	 * @return the source information of the optimization problem.
	 */
	public String getSource(){
		return m_sSource;
	}//getSource
	 
	/**
	 * @return the number of columns, i.e. variable number.
	 */
	public int getVariableCount(){
		return m_iVariableCount;
	}//getVariableCount
	
	/**
	 * @return the number of rows, i.e. constraint number.
	 */
	public int getConstraintCount(){
		return m_iConstraintCount;
	}//getConstraintCount

	/**
	 * @return the names of all the columns, i.e. variable names.
	 */
	public String[] getVariableNames(){
		return m_msVariableNames;
	}//getVariableNames
	 
	 /**
	  * @return the values of lower bounds for the variables.
	  */
	public double[] getVariableLbs(){
		 return m_mdVariableLbs;
	 }//getVariableLbs
	 
	 /**
	  * @return the values of upper bounds for the variables.
	  */
	 public double[] getVariableUbs(){
		 return m_mdVariableUbs;
	 }//getVariableUbs
	 
	 /**
	  * @return the types of all the variables, (e.g. 'C' for continuous
	  * type, 'I' for integer type, and 'B' for binary type).
	  */
	 public char[] getVariableDomains(){
		 return m_mcVariableDomains;
	 }//getVariableDomains
	 
	 /**
	  * @return the names of all the rows, i.e. constraint names.
	  */
	 public String[] getConstraintNames(){
		 return m_msConstraintNames;
	 }//getConstraintNames
	 
	 /**
	  * @return the values of the lower bounds for the constraints.
	  */
	 public double[] getConstraintLhs(){
		 return m_mdConstraintLhs;
	 }//getConstraintLhs
	 
	 /**
	  * @return the values of the upper bounds for the constraints.
	  */
	 public double[] getConstraintRhs(){
		 return m_mdConstraintRhs;
	 }//getConstraintRhs
	 
	 /**
	  * @return the value of whether the AMatrix holding linear program data is stored
	  * by column. If false, the matrix is stored by row.
	  */
	 public boolean getColumnMajor(){
		 return m_bColumnMajor;
	 }//getColumnMajor
	 
	 /**
	  * @return the values of the vector element nonz in AMatrix, which contains nonzero elements.
	  */
	 public double[] getNonzeroValues(){
		 return m_mdNonzeroValues;
	 }//getNonzeroValues

	 /**
	  * @return the values of the vector element rowIdx or colIdx in AMatrix. If the matrix is
	  * stored by column (row), rowIdx (colIdx) is the vector of row (column) indices.
	  */
	 public int[] getNonzeroIndexes(){
		 return m_miNonzeroIndexes;
	 }//getNonzeroIndexes
	 
	 /**
	  * @return the values of the vector element pntANonz in AMatrix, which points to the end of a
	  * column (row) of nonzero elements in AMatrix.
	  */
	 public int[] getStartIndexes(){
		 return m_miStartIndexes;
	 }//getStartIndexes
	 
	 /**
	  * @return whether the objective is minimization or not.
	  */
	 public boolean getMinimization(){
		 return m_bMinimization;
	 }//getMinimization
	 
	 /**
	  * @return the value of objective function constant.
	  */
	 public double getObjectiveConstant(){
		 return m_dObjectiveConstant;
	 }//getObjectiveConstant
	 
	 /**
	  * @return the values of the objective function coefficients.
	  */
	 public double[] getObjectiveCoefficients(){
		 return m_mdObjectiveCoefficients;
	 }//getObjectiveCoefficients


		/**
		 * Converts an FML instance to an OSiL linear instance. 
		 * 
		 * @return the OSiL linear instance that is converted from the FML instance. A null is returned 
		 * if there is any error in the conversion. 
		 */
	 public String convertToOSiL(){
		 OSiLWriter osilWriter = new OSiLWriter();
		 try {
			 osilWriter.setInstanceHeader(null, getSource(), null);
			 osilWriter.setVariables(getVariableCount(), getVariableNames(), getVariableLbs(), getVariableUbs(), getVariableDomains()/*, null, null*/);
			 double[] mdCoef = getObjectiveCoefficients();
			 int[] miCoefIndex = new int[mdCoef.length];
			 for(int i = 0; i < miCoefIndex.length; i++) miCoefIndex[i] = i;
			 osilWriter.addObjective(null, getMinimization(), getObjectiveConstant(), 1, mdCoef, miCoefIndex);
			 osilWriter.setConstraints(getConstraintCount(), getConstraintNames(), getConstraintLhs(), getConstraintRhs(), null);
			 double[] mdValue = getNonzeroValues();
			 osilWriter.setLinearConstraintCoefficients(mdValue.length, getColumnMajor(), getNonzeroValues(), getNonzeroIndexes(), getStartIndexes());
			 m_sOSiL = osilWriter.writeToString();
			 return m_sOSiL;
		 }
		 catch(Exception e){
			 e.printStackTrace();
			 return null;
		 }
	 }//convertToOSiL
		
	/**
	 * main for test purposes.
	 *
	 * </p>
	 *
	 * @param argv command line arguments.
	 */
	public static void main(String[] argv) {
		FMLReader fmlReader = new FMLReader();
		boolean bRead = false;
		String[] msFiles = {"80bau3b", "d6cube", "degen3", "dfl001", "fit2d", "fit2p", "greenbea", "greenbeb", "maros-r7", "mps", "pilot", "pilot87", "wood1p", "woodw"};
		String sFMLDir = "../../../OSRepository/lpfml/";
		String sOSiLDir = "../../../OSRepository/linear/continuous/";
		for(int i = 0; i < msFiles.length; i++){
			bRead = fmlReader.readFile(sFMLDir+msFiles[i]+ ".mps.xml");
			System.out.println(bRead);
			String sOSiL = fmlReader.convertToOSiL();
			//System.out.println(sOSiL);
			IOUtil.writeStringToFile(sOSiL, sOSiLDir + msFiles[i] + ".osil");	
		}
		//String sFML = IOUtil.fileToString("xml/lpfml/lpparinc.xml");
		//bRead = fmlReader.readString(sFML);
		//System.out.println(sFML);
//		System.out.println("getSource: " + fmlReader.getSource());
//		System.out.println("getVariableCount: " + fmlReader.getVariableCount());
//		System.out.println("getConstraintCount: " + fmlReader.getConstraintCount());
//		System.out.println("getVariableNames: " + fmlReader.getVariableNames()[0]);
//		System.out.println("getVariableLbs: " + fmlReader.getVariableLbs()[0]);
//		System.out.println("getVariableUbs: " + fmlReader.getVariableUbs()[0]);
//		System.out.println("getVariableDomains: " + fmlReader.getVariableDomains()[0]);
//		System.out.println("getConstraintNames: " + fmlReader.getConstraintNames()[0]);
//		System.out.println("getConstraintLhs: " + fmlReader.getConstraintLhs()[0]);
//		System.out.println("getConstraintRhs: " + fmlReader.getConstraintRhs()[0]);
//		System.out.println("getColumnMajor: " + fmlReader.getColumnMajor());
//		System.out.println("getNonzeroValues: " + fmlReader.getNonzeroValues()[0]);
//		System.out.println("getNonzeroIndexes: " + fmlReader.getNonzeroIndexes()[0]);
//		System.out.println("getStartIndexes: " + fmlReader.getStartIndexes()[2]);
//		System.out.println("getMinimization: " + fmlReader.getMinimization());
//		System.out.println("getObjectiveConstant: " + fmlReader.getObjectiveConstant());
//		System.out.println("getObjectiveCoefficients: " + fmlReader.getObjectiveCoefficients()[0]);
	}//main
	
}//class FMLReader
