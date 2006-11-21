/**
 * @(#)OSInstance 1.0 03/14/2005
 *
 * Copyright (c) 2005
 */
package org.optimizationservices.oscommon.localinterface;

import it.unimi.dsi.fastutil.ints.Int2DoubleOpenHashMap;
import it.unimi.dsi.fastutil.ints.Int2ObjectOpenHashMap;
import it.unimi.dsi.fastutil.ints.IntIterator;
import it.unimi.dsi.fastutil.ints.IntOpenHashSet;
import it.unimi.dsi.fastutil.objects.Object2DoubleOpenHashMap;

import java.util.Hashtable;
import java.util.Iterator;
import java.util.Vector;

import org.optimizationservices.oscommon.datastructure.osgeneral.IntVector;
import org.optimizationservices.oscommon.datastructure.osgeneral.MatrixMarket;
import org.optimizationservices.oscommon.datastructure.osgeneral.QuadraticTerms;
import org.optimizationservices.oscommon.datastructure.osgeneral.SparseMatrix;
import org.optimizationservices.oscommon.datastructure.osgeneral.SparseVector;
import org.optimizationservices.oscommon.datastructure.osinstance.Constraint;
import org.optimizationservices.oscommon.datastructure.osinstance.Constraints;
import org.optimizationservices.oscommon.datastructure.osinstance.InstanceData;
import org.optimizationservices.oscommon.datastructure.osinstance.InstanceHeader;
import org.optimizationservices.oscommon.datastructure.osinstance.LinearConstraintCoefficients;
import org.optimizationservices.oscommon.datastructure.osinstance.Nl;
import org.optimizationservices.oscommon.datastructure.osinstance.NonlinearExpressions;
import org.optimizationservices.oscommon.datastructure.osinstance.ObjCoef;
import org.optimizationservices.oscommon.datastructure.osinstance.Objective;
import org.optimizationservices.oscommon.datastructure.osinstance.Objectives;
import org.optimizationservices.oscommon.datastructure.osinstance.QuadraticCoefficients;
import org.optimizationservices.oscommon.datastructure.osinstance.QuadraticTerm;
import org.optimizationservices.oscommon.datastructure.osinstance.Variable;
import org.optimizationservices.oscommon.datastructure.osinstance.Variables;
import org.optimizationservices.oscommon.nonlinear.OSExpressionTree;
import org.optimizationservices.oscommon.representationparser.OSiLReader;
import org.optimizationservices.oscommon.representationparser.OSiLWriter;
import org.optimizationservices.oscommon.util.CommonUtil;
import org.optimizationservices.oscommon.util.MathUtil;
import org.optimizationservices.oscommon.util.OSParameter;

/**
 *
 * <P>The <code>OSInstance</code> class is a local interface for storing Optimization Services problem instance. 
 * Its design follows the Optimization Services instance Language (OSiL). Naming, structuring and layering 
 * all are exactly the same as those in the OSiL schema. In general there are three simple rules in translating the OSiL schema. 
 * 1. An element that is not of simple type (contains non-char nodes) or has attributes, become a class. 
 * The class type corresponds to the element type defined in the schema. 
 * 2. A simple type element (just contains character data in the element) becomes a correponding programming language (Java/C++/C#) data type. 
 * 3. A "sequence" of one or more same-type elements becomes an array, members with the selected choice being non-null. 
 * There are some exceptions. 
 * 1. Each "OSnLNode" "nonlinearExpressions" or "userFunctions" becomes an OSExpressionTree.         
 * 2. There are no definitions of "userFunctions", "simulations" and "realTimeData" because these
 * definitions are substituted.
 * 3. All compression-related elements and attributes in xml disappear in the local interface because they are all expanded. 
 * 4. "semidefiniteBlocks", "cones", "stages", "stochasticInformation" and "xmlData" are not implemented yet. 
 *
 * @author Robert Fourer, Jun Ma, Kipp Martin
 * @version 1.0, 03/14/2005
 * @see org.optimizationservices.oscommon.localinterface.OSResult
 * @see org.optimizationservices.oscommon.localinterface.OSAnalysis
 * @see org.optimizationservices.oscommon.localinterface.OSOption
 * @since OS 1.0
 */
public class OSInstance {
	
	/**
	 * instanceHeader holds the first child of the OSInstance specified by the OSiL Schema. 
	 */
	public InstanceHeader instanceHeader = new InstanceHeader();

	/**
	 * instanceData holds the second child of the OSInstance specified by the OSiL Schema. 
	 */
	public InstanceData instanceData = new InstanceData();

	/**
	 * m_sInstanceName holds the instance name. 
	 */
	protected String m_sInstanceName = "";
	
	/**
	 * m_sInstanceSource holds the instance source. 
	 */
	protected String m_sInstanceSource = "";
	
	/**
	 * m_sInstanceDescription holds the instance description. 
	 */
	protected String m_sInstanceDescription = "";
	
	/**
	 * m_bProcessVariables holds whether the variables are processed. 
	 */
	protected boolean m_bProcessVariables = false;
	
	/**
	 * m_iVariableNumber holds the variable number. 
	 */
	protected int m_iVariableNumber = -1;

	/**
	 * m_msVariableNames holds an array of variable names. 
	 */
	protected String[] m_msVariableNames = null;
	
	/**
	 * m_mdVariableInitialValues holds a double array of the initial variable values. 
	 */
	protected double[] m_mdVariableInitialValues = null;

	/**
	 * m_msVariableInitialStringValues holds a string array of the initial variable values. 
	 */
	protected String[] m_msVariableInitialStringValues = null;

	/**
	 * m_mcVariableTypes holds a char array of variable types (default = 'C').
	 * (C for Continuous; B for Binary; I for Integer; S for String)
	 */
	protected char[] m_mcVariableTypes = null;

	/**
	 * m_mdVariableLowerBounds holds a double array of variable lower bounds (default = 0.0).
	 */
	protected double[] m_mdVariableLowerBounds = null;

	/**
	 * m_mdVariableUpperBounds holds a double array of variable upper bounds (default = INF).
	 */
	protected double[] m_mdVariableUpperBounds = null;

	/**
	 * m_bProcessObjectives holds whether the objectives are processed. 
	 */
	protected boolean m_bProcessObjectives = false;

	/**
	 * m_iObjectiveNumber holds the objective number. 
	 */
	protected int m_iObjectiveNumber = -1;

	/**
	 * m_msObjectiveNames holds an array of objective names. 
	 */
	protected String[] m_msObjectiveNames = null;
	
	/**
	 * m_msMaxOrMins holds a string array of objective maxOrMins ("max" or "min").  
	 */
	protected String[] m_msMaxOrMins = null;
	
	/**
	 * m_miNumberOfObjCoef holds an integer array of number of objective coefficients (default = 0.0). 
	 */
	protected int[] m_miNumberOfObjCoef = null;

	/**
	 * m_mdObjectiveConstants holds an array of objective constants (default = 0.0). 
	 */
	protected double[] m_mdObjectiveConstants = null;
	
	/**
	 * m_mdObjectiveWeights holds an array of objective weights (default = 1.0).
	 */
	protected double[] m_mdObjectiveWeights = null;
	
	/**
	 * m_mObjectiveCoefficients holds an array of objective coefficients, one set of objective 
	 * coefficients for each objective. 
	 */
	protected SparseVector[] m_mObjectiveCoefficients = null;
	
	/**
	 * m_mmdDenseObjectiveCoefficients holds an array of dense objective coefficient arrays. 
	 * Each member of the array corresponsd to one objective. 
	 */
	protected double[][] m_mmdDenseObjectiveCoefficients = null;

	/**
	 * m_bGetDenseObjectives holds whther the dense objectives have already been obtained. 
	 */
	protected boolean m_bGetDenseObjectives = false;
	
	/**
	 * m_bProcessConstraints holds whether the constraints are processed. 
	 */
	protected boolean m_bProcessConstraints = false;
	
	/**
	 * m_iConstraintNumber holds the constraint number. 
	 */
	protected int m_iConstraintNumber = -1;

	/**
	 * m_msConstraintNames holds an array of constraint names. 
	 */
	protected String[] m_msConstraintNames = null;
	
	/**
	 * m_mdConstraintLowerBounds holds an array of constraint lower bounds (default = -INF). 
	 */
	protected double[] m_mdConstraintLowerBounds = null;

	/**
	 * m_mdConstraintUpperBounds holds an array of constraint upper bounds (default = INF). 
	 */
	protected double[] m_mdConstraintUpperBounds = null;

	/**
	 * m_mdConstraintConstants holds an array of constraint constants (default = 0.0). 
	 */
	protected double[] m_mdConstraintConstants = null;

	
	/**
	 * m_mcConstraintTypes holds a char array of constraint types
	 * (R for range; L for <=; G for >=; E for =; U for unconstrained)
	 */
	protected char[] m_mcConstraintTypes = null;
	
	/**
	 * m_bProcessLinearConstraintCoefficients holds whether the linear constraint coefficients are processed. 
	 */
	protected boolean m_bProcessLinearConstraintCoefficients = false;
	
	/**
	 * m_iLinearConstraintCoefficientNumber holds the number of specified 
	 * (usually nonzero) linear constraint coefficient values. 
	 */
	protected int m_iLinearConstraintCoefficientNumber = -1;

	/**
	 * m_bColumnMajor holds whether the linear constraint coefficients are stored in column major. 
	 */
	protected boolean m_bColumnMajor = true;

	/**
	 * m_linearConstraintCoefficientsInColumnMajor holds the standard 3 array data structure for linear constraint coefficients 
	 * (starts, indexes and values) in column major. 
	 */
	protected SparseMatrix m_linearConstraintCoefficientsInColumnMajor = null;

	/**
	 * m_linearConstraintCoefficientsInRowMajor holds the standard 3 array data structure for linear constraint coefficients 
	 * (starts, indexes and values) in row major. 
	 */
	protected SparseMatrix m_linearConstraintCoefficientsInRowMajor = null;

	/**
	 * m_linearConstraintCoefficientsInMatrixMarket holds linear constraint coefficients in the matrix market  
	 * form (rowIndex, columnIndex, Value[rowIndex,columnIndex]). 
	 */
	protected MatrixMarket m_linearConstraintCoefficientsInMatrixMarket = null;
	
	/**
	 * m_bProcessQuadraticTerms holds whether the quadratic terms are processed. 
	 */
	protected boolean m_bProcessQuadraticTerms = false;

	/**
	 * m_iQuadraticTermNumber holds the number of specified 
	 * (usually nonzero) qTerms in the quadratic coefficients. 
	 */
	protected int m_iQuadraticTermNumber = -1;

	/**
	 * m_quadraticTerms the data structure for all the quadratic terms in the instance. 
	 * (rowIdx, varOneIdx, varTwoIdx, coef)
	 */
	protected QuadraticTerms m_quadraticTerms = null;
	
	/**
	 * m_miQuadraticRowIndexes holds an integer array of quadratic expression indexes,
	 * negative indexes correspond to objectives.  
	 */
	protected int[] m_miQuadraticRowIndexes = null;
	
	/**
	 * m_quadraticTermMap holds a hash map of quadratic terms, with the key being the rowIdx (row number)
	 * and value being the holding a vecotr of quadratic terms of that row.
	 */
	protected Hashtable <String, Vector<QuadraticTerm>> m_quadraticTermMap = new Hashtable<String, Vector<QuadraticTerm>>();

	/**
	 * m_bProcessNonlinearExpressions holds whether the nonlinear expressions are processed. 
	 */
	protected boolean m_bProcessNonlinearExpressions = false;
	
	/**
	 * m_iNonlinearExpressionNumber holds the number of nonlinear expressions. 
	 */
	protected int m_iNonlinearExpressionNumber = -1;

	/**
	 * m_miNonlinearExpressionIndexes holds an integer array of nonlinear expression indexes,
	 * negative indexes correspond to objectives.  
	 */
	protected int[] m_miNonlinearExpressionIndexes = null;
	
	/**
	 * m_mNonlinearExpressionTrees holds an array of nonlinear expression trees, each tree is of the standard
	 * type OSExpressionTree. 
	 */
	protected OSExpressionTree[] m_mNonlinearExpressionTrees = null;

	/**
	 * m_mapExpressionTrees holds a hash map of expression trees, with the key being the row index
	 * and value being the expression tree representing the nonlinear expression of that row.
	 */
	protected Int2ObjectOpenHashMap m_mapExpressionTrees = null;

	/**
	 * m_iCurrentlyAddedNumberOfNonlinearExpressions holds the number of nonlinear expressions that 
	 * are currently added. 
	 */
	protected int m_iCurrentlyAddedNumberOfNonlinearExpressions = 0;
	
	/**
	 * default constructor.
	 */
	public OSInstance(){
	}//constructor
	
	/**
	 * read an OSiL instance and return an OSInstance object.  
	 * 
	 * @param osil holds the optimization instance in a string which format follows the
	 * Optimization Services instance Language (OSiL) schema.
	 * @param isFile holds whether the osil string is a file name or a string that literally holds the osil instance.  
	 * @param validate holds whether the reader should be validating against the schema or not.
	 * @return the OSInstance constructed from the OSiL String.  
	 * @throws Exception if there are errors in reading the string or setting the OSInstnace. 
	 */
   	public OSInstance readOSiL(String osil, boolean isFile, boolean validate) throws Exception{
   		OSiLReader osilReader = new OSiLReader(validate);
		boolean bRead = false;
		if(isFile){
			bRead = osilReader.readFile(osil);
		}
		else{
			bRead = osilReader.readString(osil);			
		}
		if(!bRead) throw new Exception("OSiL string not valid");
		String sLogicError = osilReader.getLogicError();
		if(sLogicError.length() > 0) throw new Exception("OSiL string logically inconsistent:\n" + sLogicError);
		return osilReader.getOSInstance();
   	}//readOSiL
   	
   	/**
   	 * write the OSInstance to an osil xml string. 
   	 * 
   	 * @return the osil xml string. 
	 * @throws Exception if there are errors in writing the osil string. 
   	 */
   	public String writeOSiL() throws Exception{
		OSiLWriter osilWriter = new OSiLWriter();
		osilWriter.setOSInstance(this);
		return osilWriter.writeToString();
   	}//writeOSiL
	
   	/**
   	 * clone a new osInstance.
   	 * 
	 * @return the cloned copy of the current OS Instance, null if there are errors. 
   	 */
   	public OSInstance clone(){
		try {
			String sOSiL = this.writeOSiL();
			OSiLReader osilReader = new OSiLReader(OSParameter.VALIDATE);
			boolean bRead = osilReader.readString(sOSiL);
			if(!bRead) throw new Exception("OSiL not read successfully");
			OSInstance osInstance = osilReader.getOSInstance();
			return osInstance; 
		} 
		catch (Exception e) {
			e.printStackTrace();
			return null;
		}		
	}//clone
   	/**
	 * Get instance name. 
	 * 
	 * @return instance name. Null or empty string ("") if there is no instance name. 
	 */
	public String getInstanceName(){
		if(m_sInstanceName == null || m_sInstanceName.length() <= 0){
			m_sInstanceName = instanceHeader.name;
		}
		return m_sInstanceName;
	}//getInstanceName
	
	/**
	 * Get instance source. 
	 * 
	 * @return instance source. Null or empty string ("") if there is no instance source. 
	 */
	public String getInstanceSource(){
		if(m_sInstanceSource == null || m_sInstanceSource.length() <= 0){
			m_sInstanceSource = instanceHeader.source;
		}
		return m_sInstanceSource;
	}//getInstanceSource
	
	/**
	 * Get instance description. 
	 * 
	 * @return instance description. Null or empty string ("") if there is no instance description. 
	 */
	public String getInstanceDescription(){
		if(m_sInstanceDescription == null || m_sInstanceDescription.length() <= 0){
			m_sInstanceDescription = instanceHeader.description;
		}
		return m_sInstanceDescription;
	}//getInstanceDescription
	
	/**
	 * Get variable number. 
	 * 
	 * @return variable number. 
	 */
	public int getVariableNumber(){
		m_iVariableNumber = instanceData.variables.numberOfVariables;
		return m_iVariableNumber;
	}//getVariableNumber

	/**
	 * process variables. 
	 * 
	 * @return true if the variables are processed. 
	 * @throws Exception if the elements in variables are logically inconsistent. 
	 */
	private boolean processVariables() throws Exception{
		if(m_bProcessVariables) return true;
		m_bProcessVariables = true;
		int i = 0;
		int n = instanceData.variables.numberOfVariables;
		Variable[] var = instanceData.variables.var;
		if(var == null) throw new Exception("no variables defined");
		if(n != var.length) throw new Exception("variable number inconsistent with variable array");
		
		if((var[0].name != null && var[0].name.length() > 0) ||
				var[n-1].name !=null && var[n-1].name.length() > 0){
			m_msVariableNames = new String[n];
			for(i = 0; i < n; i++) m_msVariableNames[i] = var[i].name;
		}
		if(!Double.isNaN(var[0].init)){
			m_mdVariableInitialValues = new double[n];
			for(i = 0; i < n; i++) m_mdVariableInitialValues[i] = var[i].init;
		}
		if((var[0].initString != null && var[0].initString.length() > 0)){
			m_msVariableInitialStringValues = new String[n];
			for(i = 0; i < n; i++) m_msVariableInitialStringValues[i] = var[i].initString;
		}
		m_mcVariableTypes = new char[n];
		m_mdVariableLowerBounds = new double[n];
		m_mdVariableUpperBounds = new double[n];
		for(i = 0; i < n; i++){
			if("CBIS".indexOf(var[i].type+"") < 0) throw new Exception("wrong variable type");
			m_mcVariableTypes[i] = var[i].type;
			m_mdVariableLowerBounds[i] = var[i].lb;
			m_mdVariableUpperBounds[i] = var[i].ub;
		}
		
		return true;
	}//processVariables
	
	/**
	 * Get variable names. 
	 * 
	 * @return a string array of variable names, null if no variable names.
	 * @throws Exception if the elements in variables are logically inconsistent. 
	 */
	public String[] getVariableNames() throws Exception{
		processVariables();
		return m_msVariableNames;
	}//getVariableNames

	/**
	 * Get variable initial values. 
	 * 
	 * @return a double array of variable initial values, null if no initial variable values.
	 * @throws Exception if the elements in variables are logically inconsistent. 
	 */
	public double[] getVariableInitialValues() throws Exception{
		processVariables();
		return m_mdVariableInitialValues;
	}//getVariableInitialValues
	
	/**
	 * Get variable initial string values. 
	 * 
	 * @return a string array of variable initial values, null if no initial variable string values.
	 * @throws Exception if the elements in variables are logically inconsistent. 
	 */
	public String[] getVariableInitialStringValues() throws Exception{
		processVariables();
		return m_msVariableInitialStringValues;
	}//getVariableInitialStringValues

	/**
	 * Get variable types. 
	 * <ul>
	 * <li>C for Continuous </li>
	 * <li>B for Binary </li> 
	 * <li>I for Integer</li> 
	 * <li>S for String</li>
	 * </ul>
	 * @return a char array of variable types. 
	 * @throws Exception if the elements in variables are logically inconsistent. 
	 */
	public char[] getVariableTypes() throws Exception{
		processVariables();
		return m_mcVariableTypes;
	}//getVariableTypes
	
	/**
	 * Get variable lower bounds. 
	 * 
	 * @return a double array of variable lower bounds. 
	 * @throws Exception if the elements in variables are logically inconsistent. 
	 */
	public double[] getVariableLowerBounds() throws Exception{
		processVariables();
		return m_mdVariableLowerBounds;
	}//getVariableLowerBounds

	/**
	 * Get variable upper bounds. 
	 * 
	 * @return a double array of variable upper bounds. 
	 * @throws Exception if the elements in variables are logically inconsistent. 
	 */
	public double[] getVariableUpperBounds() throws Exception{
		processVariables();
		return m_mdVariableUpperBounds;
	}//getVariableUpperBounds
	
	/**
	 * Get objective number. 
	 * 
	 * @return objective number. 
	 */
	public int getObjectiveNumber(){
		m_iObjectiveNumber = instanceData.objectives.numberOfObjectives;
		return m_iObjectiveNumber;
	}//getObjectiveNumber

	/**
	 * process objectives. 
	 * 
	 * @return true if the objectives are processed. 
	 * @throws Exception if the elements in objectives are logically inconsistent. 
	 */
	private boolean processObjectives() throws Exception{
		if(m_bProcessObjectives) return true;
		m_bProcessObjectives = true;
		int i = 0;
		int j = 0;
		int n = instanceData.objectives.numberOfObjectives;
		Objective[] obj = instanceData.objectives.obj;
		if((obj == null && n != 0) || (obj != null && n != obj.length)) throw new Exception("objective number inconsistent with objective array");		
		if(obj == null) return true;
		if((obj[0].name != null && obj[0].name.length() > 0) ||
			obj[n-1].name != null && obj[n-1].name.length() > 0){
			m_msObjectiveNames = new String[n];
			for(i = 0; i < n; i++) m_msObjectiveNames[i] = obj[i].name;
		}
		m_msMaxOrMins = new String[n];
		m_miNumberOfObjCoef = new int[n];
		m_mdObjectiveConstants = new double[n];
		m_mdObjectiveWeights = new double[n];
		m_mObjectiveCoefficients = new SparseVector[n];
		for(i = 0; i < n; i++){
			if(!obj[i].maxOrMin.equals("max") && !obj[i].maxOrMin.equals("min")) throw new Exception("wrong objective maxOrMin");
			m_msMaxOrMins[i] = obj[i].maxOrMin;
			m_miNumberOfObjCoef[i] = obj[i].numberOfObjCoef;
			m_mdObjectiveConstants[i] = obj[i].constant;
			m_mdObjectiveWeights[i] = obj[i].weight;
			if(obj[i].coef == null && m_miNumberOfObjCoef[i] != 0) throw new Exception("objective coefficient number inconsistent with objective coefficient array");
			if(obj[i].coef != null){
				if(obj[i].coef.length != m_miNumberOfObjCoef[i]) throw new Exception("objective coefficient number inconsistent with objective coefficient array");
				m_mObjectiveCoefficients[i] = new SparseVector();
				int iValues = obj[i].coef.length;
				m_mObjectiveCoefficients[i].indexes = new int[iValues];
				m_mObjectiveCoefficients[i].values = new double[iValues];
				for(j = 0; j < iValues; j++){
					m_mObjectiveCoefficients[i].indexes[j] = obj[i].coef[j].idx;
					m_mObjectiveCoefficients[i].values[j] = obj[i].coef[j].value;					
				}
			}
		}		
		return true;
	}//processObjectives

	/**
	 * Get objective names. 
	 * 
	 * @return a string array of objective names. Null if no objective names.
	 * @throws Exception if the elements in objectives are logically inconsistent. 
	 */
	public String[] getObjectiveNames() throws Exception{
		processObjectives();
		return m_msObjectiveNames;
	}//getObjectiveNames

	/**
	 * Get objective maxOrMins. One maxOrMin for each objective.
	 * 
	 * @return a string array of objective maxOrMins ("max" or "min"), null if no objectives. 
	 * @throws Exception if the elements in objectives are logically inconsistent. 
	 */
	public String[] getObjectiveMaxOrMins() throws Exception{
		processObjectives();
		return m_msMaxOrMins;
	}//getObjectiveMaxOrMins

	/**
	 * Get objective coefficient number. One number for each objective.
	 * 
	 * @return an integer array of objective coefficient numbers, null if no objectives. 
	 * @throws Exception if the elements in objectives are logically inconsistent. 
	 */
	public int[] getObjectiveCoefficientNumbers() throws Exception{
		processObjectives();
		return m_miNumberOfObjCoef;
	}//getObjectiveCoefficientNumbers

	/**
	 * Get objective constants. One constant for each objective.
	 * 
	 * @return a double array of objective constants, null if no objectives. 
	 * @throws Exception if the elements in objectives are logically inconsistent. 
	 */
	public double[] getObjectiveConstants() throws Exception{
		processObjectives();
		return m_mdObjectiveConstants;
	}//getObjectiveConstants
	
	/**
	 * Get objective weights. One weight for each objective.
	 * 
	 * @return a double array of objective weights, null if no objectives. 
	 * @throws Exception if the elements in objectives are logically inconsistent. 
	 */
	public double[] getObjectiveWeights() throws Exception{
		processObjectives();
		return m_mdObjectiveWeights;
	}//getObjectiveWeights
	
	/**
	 * Get objective coefficients. One set of objective coefficients for each objective.
	 * 
	 * @see org.optimizationservices.oscommon.datastructure.osgeneral.SparseVector
	 * @return an array of objective coefficients, null if no objective coefficients. 
	 * If any one objective has objective coefficients, the array will not be null and the array 
	 * size is equal to the number of objective functions. Each member of the array can still be null if
	 * the corresponding objective function doesn't have coefficients. 
	 * Each member of the array is of type ObjectiveCoefficients. The ObjectiveCoefficients class contains two arrays:
	 * variableIndexes is an integer array and values is a double array of coefficient values. 
	 * @throws Exception if the elements in objectives are logically inconsistent. 
	 */
	public SparseVector[] getObjectiveCoefficients() throws Exception{
		processObjectives();
		return m_mObjectiveCoefficients;
	}//getObjectiveCoefficients
	
	/**
	 * Get dense objective coefficients. One set of dense objective coefficients for each objective.
	 * @return an array of dense objective coefficients, null if no objective coefficients.
	 * If any one objective has objective coefficients, the array will not be null and the array 
	 * size is equal to the number of objective functions. Each member of the array can still be null if
	 * the corresponding objective function doesn't have coefficients. 
	 * @throws Exception if the elements in objectives are logically inconsistent.  
	 */
	public double[][] getDenseObjectiveCoefficients() throws Exception{
		if(m_bGetDenseObjectives) return m_mmdDenseObjectiveCoefficients;
		m_bGetDenseObjectives = true;
		if(instanceData.objectives.obj == null || 
				instanceData.objectives.numberOfObjectives == 0) return  m_mmdDenseObjectiveCoefficients;
		int m = instanceData.objectives.numberOfObjectives;
		int n = instanceData.variables.numberOfVariables;
		m_mmdDenseObjectiveCoefficients = new double[m][];
		int i, j, numobjcoef;
		SparseVector sparsevec;
		if(this.getObjectiveCoefficients() == null) return null;
		for(i = 0; i < m; i++){
			sparsevec = this.getObjectiveCoefficients()[i];
			if(sparsevec == null){
				m_mmdDenseObjectiveCoefficients[i] = null;
				continue;
			}
			m_mmdDenseObjectiveCoefficients[i] = new double[n];
			numobjcoef = (sparsevec.values == null?0:sparsevec.values.length);
			for(j = 0; j < numobjcoef; j++){
				m_mmdDenseObjectiveCoefficients[i][sparsevec.indexes[ j]]
				                                    = sparsevec.values[ j];
			}
		}
		return m_mmdDenseObjectiveCoefficients;
	}//getDenseObjectiveCoefficients

	
	/**
	 * Get constraint number. 
	 * 
	 * @return constraint number. 
	 */
	public int getConstraintNumber(){
		m_iConstraintNumber = instanceData.constraints.numberOfConstraints;
		return m_iConstraintNumber;
	}//getConstraintNumber

	/**
	 * process constraints.
	 * 
	 * @return true if the constraints are processed.
	 * @throws Exception if the elements in constraints are logically inconsistent. 
	 */
	private boolean processConstraints() throws Exception{
		if(m_bProcessConstraints) return true;
		m_bProcessConstraints = true;
		int i = 0;
		int n = instanceData.constraints.numberOfConstraints;
		Constraint[] con = instanceData.constraints.con;
		if((con == null && n != 0) || (con != null && n != con.length)) throw new Exception("constraint number inconsistent with constraint array");		
		if(con == null) return true;
		if((con[0].name != null && con[0].name.length() > 0)||
				con[n-1].name != null && con[n-1].name.length() > 0){
			m_msConstraintNames = new String[n];
			for(i = 0; i < n; i++) m_msConstraintNames[i] = con[i].name;
		}
		m_mdConstraintLowerBounds = new double[n];
		m_mdConstraintUpperBounds = new double[n];
		m_mdConstraintConstants = new double[n];
		m_mcConstraintTypes = new char[n];
		for(i = 0; i < n; i++){
			m_mdConstraintLowerBounds[i] = con[i].lb;
			m_mdConstraintUpperBounds[i] = con[i].ub;
			m_mdConstraintConstants[i] = con[i].constant;
			if(m_mdConstraintLowerBounds[i] == Double.POSITIVE_INFINITY || m_mdConstraintUpperBounds[i] == Double.NEGATIVE_INFINITY) 
				throw new Exception("constraint " + i + "infeasible");
			else if(m_mdConstraintLowerBounds[i] > m_mdConstraintUpperBounds[i])
				throw new Exception("constraint " + i + "infeasible");
			else if(m_mdConstraintLowerBounds[i] == Double.NEGATIVE_INFINITY && m_mdConstraintUpperBounds[i] == Double.POSITIVE_INFINITY)
				m_mcConstraintTypes[i] = 'U';
			else if(m_mdConstraintLowerBounds[i] == m_mdConstraintUpperBounds[i]) 
				m_mcConstraintTypes[i] = 'E';
			else if(m_mdConstraintLowerBounds[i] == Double.NEGATIVE_INFINITY)
				m_mcConstraintTypes[i] = 'L';
			else if(m_mdConstraintUpperBounds[i] == Double.POSITIVE_INFINITY)
				m_mcConstraintTypes[i] = 'G';
			else m_mcConstraintTypes[i] = 'R';
		}
		return true;
	}//processConstraints
	
	/**
	 * Get constraint names. 
	 * 
	 * @return a string array of constraint names, null if no constraint names.
	 * @throws Exception if the elements in constraints are logically inconsistent. 
	 */
	public String[] getConstraintNames() throws Exception{
		processConstraints();
		return m_msConstraintNames;
	}//getConstraintNames
	
	/**
	 * Get constraint lower bounds. 
	 * 
	 * @return a double array of constraint lower bounds, null if no constraints.
	 * @throws Exception if the elements in constraints are logically inconsistent. 
	 */
	public double[] getConstraintLowerBounds() throws Exception{
		processConstraints();
		return m_mdConstraintLowerBounds;
	}//getConstraintLowerBounds

	/**
	 * Get constraint upper bounds. 
	 * 
	 * @return a double array of constraint upper bounds, null if no constraints. 
	 * @throws Exception if the elements in constraints are logically inconsistent. 
	 */
	public double[] getConstraintUpperBounds() throws Exception{
		processConstraints();
		return m_mdConstraintUpperBounds;
	}//getConstraintUpperBounds

	/**
	 * Get constraint constants. 
	 * 
	 * @return a double array of constraint constants, null if no constraints. 
	 * @throws Exception if the elements in constraints are logically inconsistent. 
	 */
	public double[] getConstraintConstants() throws Exception{
		processConstraints();
		return m_mdConstraintConstants;
	}//getConstraintConstants

	/**
	 * Get constraint types. 
	 * <ul>
	 * <li>R for range constraint lb <= constraint <= ub </li>
	 * <li>L for less than constraint  -INF <= con <= ub or con <= ub</li>
	 * <li>G for greater than constraint lb <= con <= INF or con >= lb </li>
	 * <li>E for equal to constraint  lb <= con <= ub where lb = ub  or con = lb/ub </li>
	 * <li>U for unconstrained constraint -INF <= con <= INF</li>
	 * </ul>
	 * @return a char array of constraint types, null if no constraints.
	 * @throws Exception if the elements in constraints are logically inconsistent. 
	 */
	public char[] getConstraintTypes() throws Exception{
		processConstraints();
		return m_mcConstraintTypes;
		
	}//getConstraintTypes
	
	/**
	 * Get number of specified (usually nonzero) linear constraint coefficient values. 
	 * 
	 * @return number of specified (usually nonzero) linear constraint coefficient values. 
	 */
	public int getLinearConstraintCoefficientNumber(){
		if(instanceData == null || instanceData.linearConstraintCoefficients == null){
			m_iLinearConstraintCoefficientNumber = 0;
		}
		else{
			m_iLinearConstraintCoefficientNumber = instanceData.linearConstraintCoefficients.numberOfValues;				
		}
		return m_iLinearConstraintCoefficientNumber;
	}//getLinearConstraintCoefficientNumber
	
	/**
	 * process linear constraint coefficients. 
	 * 
	 * @return true if the inear constraint coefficients are processed. 
	 * @throws Exception if the elements in inear constraint coefficients are logically inconsistent. 
	 */
	private boolean processLinearConstraintCoefficients() throws Exception{
		if(m_bProcessLinearConstraintCoefficients) return true;
		m_bProcessLinearConstraintCoefficients = true;
		LinearConstraintCoefficients coefMatrix = instanceData.linearConstraintCoefficients;
		if(coefMatrix == null || coefMatrix.value == null || coefMatrix.value.el == null) return true;
		int n = instanceData.linearConstraintCoefficients.numberOfValues;
		
		//value array
		if((coefMatrix.value.el == null || coefMatrix.value.el.length == 0) && n != 0) 
			throw new Exception("linear constraint coefficient number inconsistent with linear constraint coefficient value array ");		
		if(coefMatrix.value.el.length != n) 
			throw new Exception("linear constraint coefficient number inconsistent with linear constraint coefficient value array ");		

		//index array
		IntVector idx = null;
		if((coefMatrix.colIdx != null && coefMatrix.colIdx.el != null && coefMatrix.colIdx.el.length > 0) && 
		   (coefMatrix.rowIdx != null && coefMatrix.rowIdx.el != null && coefMatrix.rowIdx.el.length > 0))
			throw new Exception("ambiguous linear constraint coefficient major");
		else if((coefMatrix.colIdx.el == null || coefMatrix.colIdx.el.length == 0) &&
		   (coefMatrix.rowIdx.el == null || coefMatrix.rowIdx.el.length == 0) &&
		   n != 0)
			throw new Exception("linear constraint coefficient number inconsistent with linear constraint coefficient index array ");
		else if((coefMatrix.colIdx.el != null && coefMatrix.colIdx.el.length > 0) &&
		   (coefMatrix.rowIdx.el != null && coefMatrix.rowIdx.el.length > 0))
			throw new Exception("ambiguous linear constraint coefficient major");
		else{
			if(coefMatrix.rowIdx.el != null && coefMatrix.rowIdx.el.length > 0){
				idx = coefMatrix.rowIdx;
				m_bColumnMajor = true;
				m_linearConstraintCoefficientsInColumnMajor = new SparseMatrix();
				m_linearConstraintCoefficientsInColumnMajor.isColumnMajor = true;
			}
			else{ 
				idx = coefMatrix.colIdx;
				m_bColumnMajor = false;
				m_linearConstraintCoefficientsInRowMajor = new SparseMatrix();
				m_linearConstraintCoefficientsInRowMajor.isColumnMajor = false;
			}
			if(idx.el.length != n)
				throw new Exception("linear constraint coefficient number inconsistent with linear constraint coefficient index array ");		
		}

		//start array
		if((coefMatrix.start.el == null || coefMatrix.start.el.length == 0) && n != 0)
			throw new Exception("linear constraint coefficient number inconsistent with linear constraint coefficient start array ");
		else if(coefMatrix.start.el.length != (m_bColumnMajor?getVariableNumber()+1:getConstraintNumber()+1))
			throw new Exception("linear constraint coefficient start array inconsistent with variable or constraint number");			
		if(m_bColumnMajor){
			m_linearConstraintCoefficientsInColumnMajor.values = coefMatrix.value.el;
			m_linearConstraintCoefficientsInColumnMajor.indexes = coefMatrix.rowIdx.el;
			m_linearConstraintCoefficientsInColumnMajor.starts = coefMatrix.start.el;			
		}
		else{
			m_linearConstraintCoefficientsInRowMajor.values = coefMatrix.value.el;
			m_linearConstraintCoefficientsInRowMajor.indexes = coefMatrix.colIdx.el;
			m_linearConstraintCoefficientsInRowMajor.starts = coefMatrix.start.el;						
		}
		return true;
	}//processLinearConstraintCoefficients

	/**
	 * Get whether the constraint coefficients is in column major (true) or row major (false). 
	 * 
	 * @return whether the constraint coefficients is in column major (true) or row major (false).
	 * @throws Exception if the elements in linear constraint coefficients are logically inconsistent. 
	 */
	public boolean getLinearConstraintCoefficientMajor() throws Exception{
		processLinearConstraintCoefficients();	
		return m_bColumnMajor; 		
	}//getLinearConstraintCoefficientMajor
	
	/**
	 * Get linear constraint coefficients in column major. 
	 * @return a sparse matrix reprsentation of linear constraint coefficients in column major, null if no linear constraint coefficients. 
	 * @throws Exception if the elements in linear constraint coefficients are logically inconsistent. 
	 * @see org.optimizationservices.oscommon.datastructure.osgeneral.SparseMatrix	 
	 */
	public SparseMatrix getLinearConstraintCoefficientsInColumnMajor() throws Exception{
		processLinearConstraintCoefficients();
		if(m_linearConstraintCoefficientsInColumnMajor != null) return m_linearConstraintCoefficientsInColumnMajor;
		if(!m_bColumnMajor){
			if(m_linearConstraintCoefficientsInRowMajor == null) return null;
			m_linearConstraintCoefficientsInColumnMajor = 
				MathUtil.convertLinearConstraintCoefficientMatrixToTheOtherMajor(false, 
						m_linearConstraintCoefficientsInRowMajor.starts,
						m_linearConstraintCoefficientsInRowMajor.indexes,
						m_linearConstraintCoefficientsInRowMajor.values,
						getVariableNumber());
		}
		return m_linearConstraintCoefficientsInColumnMajor; 		
	}//getLinearConstraintCoefficientsInColumnMajor
	
	/**
	 * Get linear constraint coefficients in row major. 
	 * @return a sparse matrix reprsentation of linear constraint coefficients in row major, null if no linear constraint coefficients. 
	 * @throws Exception if the elements in linear constraint coefficients are logically inconsistent. 
	 * @see org.optimizationservices.oscommon.datastructure.osgeneral.SparseMatrix
	 */
	public SparseMatrix getLinearConstraintCoefficientsInRowMajor() throws Exception{
		processLinearConstraintCoefficients();
		if(m_linearConstraintCoefficientsInRowMajor != null) return m_linearConstraintCoefficientsInRowMajor;
		if(m_bColumnMajor){
			if(m_linearConstraintCoefficientsInColumnMajor == null) return null;
			m_linearConstraintCoefficientsInRowMajor = 
				MathUtil.convertLinearConstraintCoefficientMatrixToTheOtherMajor(true, 
						m_linearConstraintCoefficientsInColumnMajor.starts,
						m_linearConstraintCoefficientsInColumnMajor.indexes,
						m_linearConstraintCoefficientsInColumnMajor.values,
						getConstraintNumber());
		}
		return m_linearConstraintCoefficientsInRowMajor; 
	}//getLinearConstraintCoefficientsInRowMajor
	
	/**
	 * Get linear constraint coefficients in matrix market form. 
	 * @return a matrix market reprsentation (i, j, Cij) of linear constraint coefficients, null if no linear constraint coefficients. 
	 * @throws Exception if the elements in linear constraint coefficients are logically inconsistent. 
	 * @see org.optimizationservices.oscommon.datastructure.osgeneral.MatrixMarket
	 */
	public MatrixMarket getLinearConstraintCoefficientsInMatrixMarket() throws Exception{
		if(m_linearConstraintCoefficientsInMatrixMarket != null) return m_linearConstraintCoefficientsInMatrixMarket;
		if(getLinearConstraintCoefficientNumber() == 0) return null;
		processLinearConstraintCoefficients();
		SparseMatrix coefMatrix = m_bColumnMajor?m_linearConstraintCoefficientsInColumnMajor:m_linearConstraintCoefficientsInRowMajor;
		m_linearConstraintCoefficientsInMatrixMarket.rowIndexes = new int[getLinearConstraintCoefficientNumber()];
		m_linearConstraintCoefficientsInMatrixMarket.columnIndexes = new int[getLinearConstraintCoefficientNumber()];
		m_linearConstraintCoefficientsInMatrixMarket.values = new double[getLinearConstraintCoefficientNumber()];
		
		int iRow = 0;
		int iCol = 0;
		int k = 0;
		for(int i = 0; i < (coefMatrix.starts.length-1); i++){
			if(coefMatrix.isColumnMajor) iCol = i;
			else iRow = i;
			for(int j = coefMatrix.starts[i]; j < coefMatrix.starts[i+1]; j++){
				if(coefMatrix.isColumnMajor) iRow = coefMatrix.indexes[j];
				else iCol = coefMatrix.indexes[j];
				m_linearConstraintCoefficientsInMatrixMarket.values[k] = coefMatrix.values[j];
				m_linearConstraintCoefficientsInMatrixMarket.rowIndexes[k] = iRow;
				m_linearConstraintCoefficientsInMatrixMarket.columnIndexes[k] = iCol;
				k++;
			}
		}
		return m_linearConstraintCoefficientsInMatrixMarket;
	}//getLinearConstraintCoefficientsInMatrixMarket
	
	/**
	 * Get the number of specified (usually nonzero) qTerms in the quadratic coefficients. 
	 * 
	 * @return qTerm number. 
	 */
	public int getQuadraticTermNumber(){
		if(instanceData.quadraticCoefficients == null || instanceData.quadraticCoefficients.qTerm == null){
			m_iQuadraticTermNumber = 0;
		}
		else{
			m_iQuadraticTermNumber = instanceData.quadraticCoefficients.numberOfQuadraticTerms;
		}
		return m_iQuadraticTermNumber;
	}//getQuadraticTermNumber
	
	/**
	 * Process all the quadratic terms in the instance. 
	 * 
	 * @return true if the quadratic terms are processed. 
	 * @throws Exception if the elements in quadratic coefficients are logically inconsistent. 
	 * @see org.optimizationservices.oscommon.datastructure.osgeneral.QuadraticTerms
	 */
	private boolean processQuadraticTerms() throws Exception{
		if(m_bProcessQuadraticTerms) return true;
		m_bProcessQuadraticTerms = true;
		if(instanceData.quadraticCoefficients == null || instanceData.quadraticCoefficients.qTerm == null){
			m_iQuadraticTermNumber = 0;
			return true;
		}
		int i = 0;
		QuadraticCoefficients quadraticCoefs = instanceData.quadraticCoefficients;
		int n = quadraticCoefs.numberOfQuadraticTerms;
		m_iQuadraticTermNumber = n;
		if((quadraticCoefs.qTerm == null || quadraticCoefs.qTerm.length == 0) && n != 0) 
			throw new Exception("quadratic term number inconsistent with quadratic term array");		
		if(quadraticCoefs.qTerm.length != n) 
			throw new Exception("quadratic term number inconsistent with quadratic term array");
		m_quadraticTerms = new QuadraticTerms();
		m_quadraticTerms.rowIndexes = new int[n];
		m_quadraticTerms.varOneIndexes = new int[n];
		m_quadraticTerms.varTwoIndexes = new int[n];
		m_quadraticTerms.coefficients = new double[n];
		QuadraticTerm[] qTerm = quadraticCoefs.qTerm;
		IntOpenHashSet intHashSet = new IntOpenHashSet();
		int iRow;
		String sRow;
		for(i = 0; i < n; i++){
			iRow = qTerm[i].idx;
			sRow = iRow + "";
			m_quadraticTerms.rowIndexes[i] = iRow;
			intHashSet.add(iRow);
			m_quadraticTerms.varOneIndexes[i] = qTerm[i].idxOne;
			m_quadraticTerms.varTwoIndexes[i] = qTerm[i].idxTwo;
			m_quadraticTerms.coefficients[i] = qTerm[i].coef;
			
			Vector<QuadraticTerm> vQTerms = m_quadraticTermMap.get(sRow);
			if(vQTerms == null){
				vQTerms = new Vector<QuadraticTerm>();
				m_quadraticTermMap.remove(sRow);
				m_quadraticTermMap.put(sRow, vQTerms);
			}
			vQTerms.add(qTerm[i]);				
		}
		m_miQuadraticRowIndexes = intHashSet.toIntArray();
		return true;
	}//processQuadraticTerms
	
	/**
	 * Get all the quadratic terms in the instance. 
	 * 
	 * @return the QuadraticTerms data structure for all quadratic terms in the instance, null if no quadratic terms. 
	 * The QuadraticTerms contains four arrays: rowIndexes, varOneIndexes, varTwoIndexes, coefficients.
	 * @throws Exception if the elements in quadratic coefficients are logically inconsistent. 
	 * @see org.optimizationservices.oscommon.datastructure.osgeneral.QuadraticTerms
	 */
	public QuadraticTerms getQuadraticTerms() throws Exception{
		processQuadraticTerms();
		return m_quadraticTerms;
	}//getQuadraticTerms
	
	/**
  	 * Get all the unique quadratic row indexes, i.e. indexes of rows (objetives or constraints) that contain quadratic terms. 
   	 * 
   	 * @return an integer array of unique quadratic row indexes. 
	 * @throws Exception if the elements in quadratic expressions are logically inconsistent. 
   	 */
	public int[] getQuadraticRowIndexes() throws Exception{
		processQuadraticTerms();
		return m_miQuadraticRowIndexes;
	}//getQuadraticTerms
	
	/**
	 * process nonlinear expressions. 
	 * 
	 * @return true if the nonlinear expressions are processed. 
	 * @throws Exception if the elements in nonlinear expressions are logically inconsistent. 
	 */
	private boolean processNonlinearExpressions() throws Exception{
		if(m_bProcessNonlinearExpressions) return true;
		m_bProcessNonlinearExpressions = true;
		int i = 0;
		Nl[] nl = instanceData.nonlinearExpressions.nl;
		if(nl == null){
			m_iNonlinearExpressionNumber = 0;
			return true;
		}
		int n = nl.length;
		if(n != instanceData.nonlinearExpressions.numberOfNonlinearExpressions) throw new Exception("nonlinear expression number inconsistent with nl array ");
		m_iNonlinearExpressionNumber = n;
		m_miNonlinearExpressionIndexes = new int[n];
		m_mNonlinearExpressionTrees = new OSExpressionTree[n];
		m_mapExpressionTrees = new Int2ObjectOpenHashMap();
		int iObjNumber = getObjectiveNumber();
		int iConNumber = getConstraintNumber();
		for(i = 0; i < n; i++){
			m_miNonlinearExpressionIndexes[i] = nl[i].idx;	
			if(nl[i].idx < -iObjNumber || nl[i].idx >= iConNumber) 
				throw new Exception("nonlinear expression tree " + i + "with wrong index " + nl[i].idx);
			m_mNonlinearExpressionTrees[i] = nl[i].osExpressionTree;
			m_mapExpressionTrees.put(nl[i].idx, nl[i].osExpressionTree);
		}
		return true;
	}//processNonlinearExpressions

   	/**
   	 * Get the number of nonlinear expression trees, i.e. the number of nonlinear objectives or constraints. 
   	 * 
   	 * @return the number of nonlinear expression trees, i.e. the number of nonlinear objectives or constraints.
	 * @throws Exception if the elements in nonlinear expressions are logically inconsistent. 
   	 */
   	public int getNonlinearExpressionTreeNumber() throws Exception{
   		processNonlinearExpressions();
   		return m_iNonlinearExpressionNumber;
   	}//getNonlinearExpressionTreeNumber
   	
   	/**
   	 * Get all the nonlinear expression tree indexes, i.e. indexes of rows (objetives or constraints) that contain nonlinear expressions. 
   	 * 
   	 * @return an integer array of nonlinear expression tree indexes. 
	 * @throws Exception if the elements in nonlinear expressions are logically inconsistent. 
   	 */
   	public int[] getNonlinearExpressionTreeIndexes() throws Exception{
   		processNonlinearExpressions();
   		return m_miNonlinearExpressionIndexes;
   	}//getNonlinearExpressionTreeIndexes

   	/**
   	 * Get all the nonlinear expression trees. 
   	 * 
   	 * @return an array of nonlinear expression trees, each tree is of the standard
	 * type OSExpressionTree.   
	 * @throws Exception if the elements in nonlinear expressions are logically inconsistent. 
	 * @see org.optimizationservices.oscommon.nonlinear.OSExpressionTree
   	 */
   	public OSExpressionTree[] getNonlinearExpressionTrees() throws Exception{
   		processNonlinearExpressions();
   		return m_mNonlinearExpressionTrees;
   	}//getNonlinearExpressionTrees

   	/**
   	 * Get the nonlinear expression tree of a specific row in . 
   	 * 
	 * @param index holds the row index (objective or constraint) to which the nonlinear expression tree belongs.
	 * Constraint indexes start from 0, 1, 2, ... up. 
	 * Objective indexes start from -1, -2, -3, ... down. 
   	 * @return a nonlinear expression trees, of the standard type OSExpressionTree, null if there is no nonlinear
   	 * expression tree from that row. 
	 * @throws Exception if the elements in nonlinear expressions are logically inconsistent. 
	 * @see org.optimizationservices.oscommon.nonlinear.OSExpressionTree
   	 */
   	public OSExpressionTree getNonlinearExpressionTree(int index) throws Exception{
   		processNonlinearExpressions();
   		if(m_mapExpressionTrees == null) return null;
   		else{
   			return (OSExpressionTree)m_mapExpressionTrees.get(index);
   		}
   	}//getNonlinearExpressionTree(int)

   	/**
   	 * Get the nonlinear expression tree of a specific row in a string array of prefix tokens. 
   	 * 
	 * @param index holds the row index (objective or constraint) to which the nonlinear expression tree belongs.
	 * Constraint indexes start from 0, 1, 2, ... up. 
	 * Objective indexes start from -1, -2, -3, ... down. 
   	 * @return a nonlinear expression tree of a specific row in a string array of prefix tokens. 
	 * @throws Exception if the elements in nonlinear expressions are logically inconsistent. 
	 * @see org.optimizationservices.oscommon.nonlinear.OSExpressionTree
   	 */
   	public String[] getNonlinearExpressionTreeInPrefix(int index) throws Exception{
   		processNonlinearExpressions();
   		if(m_mapExpressionTrees == null) return null;
   		else{
   			if(m_mapExpressionTrees.get(index) == null) return null;
   			Vector<String> vPrefix = ((OSExpressionTree)m_mapExpressionTrees.get(index)).getPrefix();
   			return CommonUtil.vectorToStrArray(vPrefix);
   		}
   	}//getNonlinearExpressionTreeInPrefix(int)
   	
   	/**
   	 * Get the nonlinear expression tree of a specific row in a string array of postfix tokens. 
   	 * 
	 * @param index holds the row index (objective or constraint) to which the nonlinear expression tree belongs.
	 * Constraint indexes start from 0, 1, 2, ... up. 
	 * Objective indexes start from -1, -2, -3, ... down. 
   	 * @return a nonlinear expression tree of a specific row in a string array of postfix tokens. 
	 * @throws Exception if the elements in nonlinear expressions are logically inconsistent. 
	 * @see org.optimizationservices.oscommon.nonlinear.OSExpressionTree
   	 */
   	public String[] getNonlinearExpressionTreeInPostfix(int index) throws Exception{
   		processNonlinearExpressions();
   		if(m_mapExpressionTrees == null) return null;
   		else{
   			if(m_mapExpressionTrees.get(index) == null) return null;
   			Vector<String> vPostfix = ((OSExpressionTree)m_mapExpressionTrees.get(index)).getPostfix();
   			return CommonUtil.vectorToStrArray(vPostfix);
   		}
   	}//getNonlinearExpressionTreeInPostfix(int)
   	
   	/**
   	 * Get the nonlinear expression tree of a specific row in a string array of infix tokens. 
   	 * 
	 * @param index holds the row index (objective or constraint) to which the nonlinear expression tree belongs.
	 * Constraint indexes start from 0, 1, 2, ... up. 
	 * Objective indexes start from -1, -2, -3, ... down. 
   	 * @return a nonlinear expression tree of a specific row in a string array of infix tokens. 
	 * @throws Exception if the elements in nonlinear expressions are logically inconsistent. 
	 * @see org.optimizationservices.oscommon.nonlinear.OSExpressionTree
   	 */
   	public String[] getNonlinearExpressionTreeInInfix(int index) throws Exception{
   		processNonlinearExpressions();
   		if(m_mapExpressionTrees == null) return null;
   		else{
   			if(m_mapExpressionTrees.get(index) == null) return null;
   			Vector<String> vInfix = ((OSExpressionTree)m_mapExpressionTrees.get(index)).getInfix();
   			return CommonUtil.vectorToStrArray(vInfix);
   		}
   	}//getNonlinearExpressionTreeInInfix(int)

	/**
	 * Express the function in the specified constraint (row) in a postfix vecotr of operator symbols.
	 * If the row idx is negative, it returns that from an objective function.
	 *
	 * </p>
	 *
	 * @param index holds the row index to which the function belongs. if negative, it is an objective function.
	 * @return the function in the specified constraint (row) expressed in a postfix vector of operator symbols.
	 * If the row idx is negative, it returns that from an objective function.
	 */
	public Vector getPostfix(int index){
		Vector<String> vNonlinearPostfix = new Vector<String>();
		try {
			processNonlinearExpressions();
		} 
		catch (Exception e1) {
			e1.printStackTrace();
		}
		OSExpressionTree exTree = (OSExpressionTree)(m_mapExpressionTrees.get(index));
		if(exTree != null) vNonlinearPostfix = exTree.getPostfix();

		try {
			processQuadraticTerms();
		} 
		catch (Exception e1) {
			e1.printStackTrace();
		}
		Vector<QuadraticTerm> vQuadraticTerms = m_quadraticTermMap.get(index+"");
		int iQuadraticTerms = vQuadraticTerms==null?0:vQuadraticTerms.size();
		Vector<String> vQuadraticPostfix = new Vector<String>(iQuadraticTerms);
		for(int i = 0; i < iQuadraticTerms; i++){
			QuadraticTerm qTerm = vQuadraticTerms.elementAt(i);
			vQuadraticPostfix.addElement("X"+qTerm.idxOne);
			vQuadraticPostfix.addElement("X"+qTerm.idxTwo);
			vQuadraticPostfix.addElement("times");
			if(qTerm.coef != 1){
				vQuadraticPostfix.addElement(qTerm.coef+"");
				vQuadraticPostfix.addElement("times");
			}
		}
		if(iQuadraticTerms > 1) vQuadraticPostfix.addElement("sum[" + iQuadraticTerms + "]");
		
		Vector<String> vLinearPostfix = new Vector<String>();
		int iLinearTerms = 0;
		try {
			processObjectives();
		} 
		catch (Exception e1) {
			e1.printStackTrace();
		}
		if(index < 0 && m_mObjectiveCoefficients != null){
			double[] mdCoefValue = m_mObjectiveCoefficients[Math.abs(index)-1].values;
			int[] mdCoefIndex = m_mObjectiveCoefficients[Math.abs(index)-1].indexes;
			int n = (mdCoefValue==null)?0:mdCoefValue.length;
			for(int i = 0; i < n; i++){
				double dCoef = mdCoefValue[i];
				if(dCoef != 0){
					iLinearTerms++;
					if(dCoef != 1) vLinearPostfix.addElement(dCoef + "");
					vLinearPostfix.addElement("X" + mdCoefIndex[i]);
					if(dCoef != 1) vLinearPostfix.addElement("times");
				}
			}
		}
		else{
			try {
				getLinearConstraintCoefficientsInRowMajor();
			} 
			catch (Exception e) {
				e.printStackTrace();
			}
			int iRow = 0;
			int iCol = 0;
			if(m_linearConstraintCoefficientsInRowMajor!=null && m_linearConstraintCoefficientsInRowMajor.starts != null){
				iRow = index;
				for(int j = m_linearConstraintCoefficientsInRowMajor.starts[iRow]; j < m_linearConstraintCoefficientsInRowMajor.starts[iRow+1]; j++){
					iCol = m_linearConstraintCoefficientsInRowMajor.indexes[j];
					iLinearTerms++;
					if(m_linearConstraintCoefficientsInRowMajor.values[j] != 1) vLinearPostfix.addElement(m_linearConstraintCoefficientsInRowMajor.values[j] + "");
					vLinearPostfix.addElement("X" + iCol);
					if(m_linearConstraintCoefficientsInRowMajor.values[j] != 1) vLinearPostfix.addElement("times");
				}
			}
		}		
		if(iLinearTerms > 1) vLinearPostfix.addElement("sum[" + iLinearTerms + "]");
		
		Vector<String> vPostfix = new Vector<String>();		
		if(vLinearPostfix.size() <= 0){
			vPostfix = vNonlinearPostfix;
		}
		else if(vNonlinearPostfix.size() <= 0){
			vPostfix = vLinearPostfix;
		}
		else{
			vLinearPostfix.addAll(vNonlinearPostfix);
			vPostfix = vLinearPostfix;
			vPostfix.addElement("plus");
		}
		
		if(iQuadraticTerms > 0){
			vPostfix.addAll(vQuadraticPostfix);
			if(vPostfix.size() > vQuadraticPostfix.size()){
				vPostfix.addElement("plus");
			}
		}
		return vPostfix;
	}//getPostfix

	/**
	 * Express the function in the specified constraint (row) in a prefix vector of operator symbols..
	 * If the row idx is negative, it returns that from an objective function.
	 *
	 * </p>
	 *
	 * @param index holds the row idx to which the function belongs. if negative, it is an objective function.
	 * @return the function in the specified constraint (row) expressed in a prefix vector of operator symbols.
	 * If the row idx is negative, it returns that from an objective function.
	 */
	public Vector getPrefix(int index){
		Vector<String> vNonlinearPrefix = new Vector<String>();
		try {
			processNonlinearExpressions();
		} 
		catch (Exception e1) {
			e1.printStackTrace();
		}
		OSExpressionTree exTree = (OSExpressionTree)(m_mapExpressionTrees.get(index));
		if(exTree != null) vNonlinearPrefix = exTree.getPrefix();

		try {
			processQuadraticTerms();
		} 
		catch (Exception e1) {
			e1.printStackTrace();
		}
		Vector<QuadraticTerm> vQuadraticTerms = m_quadraticTermMap.get(index+"");
		int iQuadraticTerms = vQuadraticTerms==null?0:vQuadraticTerms.size();
		Vector<String> vQuadraticPrefix = new Vector<String>(iQuadraticTerms);
		if(iQuadraticTerms > 1) vQuadraticPrefix.addElement("sum[" + iQuadraticTerms + "]");
		for(int i = 0; i < iQuadraticTerms; i++){
			QuadraticTerm qTerm = vQuadraticTerms.elementAt(i);
			if(qTerm.coef != 1){
				vQuadraticPrefix.addElement("times");
				vQuadraticPrefix.addElement(qTerm.coef+"");
			}
			vQuadraticPrefix.addElement("times");
			vQuadraticPrefix.addElement("X"+qTerm.idxOne);
			vQuadraticPrefix.addElement("X"+qTerm.idxTwo);
		}

		Vector<String> vLinearPrefix = new Vector<String>();
		int iLinearTerms = 0;
		try {
			processObjectives();
		} 
		catch (Exception e1) {
			e1.printStackTrace();
		}
		if(index < 0 && m_mObjectiveCoefficients != null){
			double[] mdCoefValue = m_mObjectiveCoefficients[Math.abs(index)-1].values;
			int[] mdCoefIndex = m_mObjectiveCoefficients[Math.abs(index)-1].indexes;
			int n = (mdCoefValue==null)?0:mdCoefValue.length;
			for(int i = 0; i < n; i++){
				double dCoef = mdCoefValue[i];
				if(dCoef != 0){
					iLinearTerms++;
					if(dCoef != 1){
						vLinearPrefix.addElement("times");
						vLinearPrefix.addElement(dCoef + "");
					}
					vLinearPrefix.addElement("X" + mdCoefIndex[i]);
				}
			}
		}
		else{
			try {
				getLinearConstraintCoefficientsInRowMajor();
			} 
			catch (Exception e) {
				e.printStackTrace();
			}
			
			int iRow = 0;
			int iCol = 0;
			if(m_linearConstraintCoefficientsInRowMajor!=null && m_linearConstraintCoefficientsInRowMajor.starts != null){
				iRow = index;
				for(int j = m_linearConstraintCoefficientsInRowMajor.starts[iRow]; j < m_linearConstraintCoefficientsInRowMajor.starts[iRow+1]; j++){
					iCol = m_linearConstraintCoefficientsInRowMajor.indexes[j];
					iLinearTerms++;
					if(m_linearConstraintCoefficientsInRowMajor.values[j] != 1){
						vLinearPrefix.addElement("times");
						vLinearPrefix.addElement(m_linearConstraintCoefficientsInRowMajor.values[j] + "");
					}
					vLinearPrefix.addElement("X" + iCol);
				}
			}
		}
		Vector<String> vPrefix = new Vector<String>();
		if(vLinearPrefix.size() <= 0){
			vPrefix = vNonlinearPrefix;
		}
		else if(vNonlinearPrefix.size() <= 0){
			vPrefix = vLinearPrefix;
		}
		else{
			vPrefix.addElement("plus");
			if(iLinearTerms > 1) vPrefix.addElement("sum[" + iLinearTerms + "]");
			vPrefix.addAll(vLinearPrefix);
			vPrefix.addAll(vNonlinearPrefix);
		}
		
		if(iQuadraticTerms > 0){
			vPrefix.addAll(vQuadraticPrefix);
			if(vPrefix.size() > vQuadraticPrefix.size()){
				vPrefix.insertElementAt("plus", 0);
			}
		}

		
		return vPrefix;
	}//getPrefix

	/**
	 * Express the function in the specified constraint (row) in an infix vecotr of operator symbols.
	 * If the row idx is negative, it returns that from an objective function.
	 *
	 * </p>
	 *
	 * @param index holds the row number to which the function belongs. if negative, it is an objective function.
	 * @return the function in the specified constraint (row) expressed in a infix vector of operator symbols.
	 * If the row idx is negative, it returns that from an objective function.
	 */
	public Vector getInfix(int index){
		Vector<String> vNonlinearInfix = new Vector<String>();
		try {
			processNonlinearExpressions();
		} 
		catch (Exception e1) {
			e1.printStackTrace();
		}
		OSExpressionTree exTree = (OSExpressionTree)(m_mapExpressionTrees.get(index));
		if(exTree != null) vNonlinearInfix = exTree.getInfix();

		try {
			processQuadraticTerms();
		} 
		catch (Exception e1) {
			e1.printStackTrace();
		}
		Vector<QuadraticTerm> vQuadraticTerms = m_quadraticTermMap.get(index+"");
		int iQuadraticTerms = vQuadraticTerms==null?0:vQuadraticTerms.size();
		Vector<String> vQuadraticInfix = new Vector<String>(iQuadraticTerms);
		
		if(iQuadraticTerms > 1){
			vQuadraticInfix.addElement("sum[" + iQuadraticTerms + "]");
			vQuadraticInfix.addElement("(");
		}
		for(int i = 0; i < iQuadraticTerms; i++){
			QuadraticTerm qTerm = vQuadraticTerms.elementAt(i);
			if(qTerm.coef != 1){
				vQuadraticInfix.addElement(qTerm.coef+"");
				vQuadraticInfix.addElement("times");
			}
			vQuadraticInfix.addElement("X"+qTerm.idxOne);
			vQuadraticInfix.addElement("times");
			vQuadraticInfix.addElement("X"+qTerm.idxTwo);
		}
		if(iQuadraticTerms > 1){
			vQuadraticInfix.addElement(")");
		}

		
		Vector<String> vLinearInfix = new Vector<String>();
		int iLinearTerms = 0;
		try {
			processObjectives();
		} 
		catch (Exception e1) {
			e1.printStackTrace();
		}
		if(index < 0 && m_mObjectiveCoefficients != null){
			double[] mdCoefValue = m_mObjectiveCoefficients[Math.abs(index)-1].values;
			int[] mdCoefIndex = m_mObjectiveCoefficients[Math.abs(index)-1].indexes;
			int n = (mdCoefValue==null)?0:mdCoefValue.length;
			for(int i = 0; i < n; i++){
				double dCoef = mdCoefValue[i];
				if(dCoef != 0){
					iLinearTerms++;
					if(dCoef != 1){
						vLinearInfix.addElement(dCoef + "");
						if(dCoef != 1) vLinearInfix.addElement("times");
					}
					vLinearInfix.addElement("X" + mdCoefIndex[i]);
				}
			}
		}
		else{
			try {
				getLinearConstraintCoefficientsInRowMajor();
			} 
			catch (Exception e) {
				e.printStackTrace();
			}
			
			int iRow = 0;
			int iCol = 0;
			if(m_linearConstraintCoefficientsInRowMajor!=null && m_linearConstraintCoefficientsInRowMajor.starts != null){
				iRow = index;
				for(int j = m_linearConstraintCoefficientsInRowMajor.starts[iRow]; j < m_linearConstraintCoefficientsInRowMajor.starts[iRow+1]; j++){
					iCol = m_linearConstraintCoefficientsInRowMajor.indexes[j];
					iLinearTerms++;
					if(m_linearConstraintCoefficientsInRowMajor.values[j] != 1){
						vLinearInfix.addElement(m_linearConstraintCoefficientsInRowMajor.values[j] + "");
						vLinearInfix.addElement("times");
					}
					vLinearInfix.addElement("X" + iCol);
				}
			}
		}
			
						
		if(iLinearTerms > 1) vLinearInfix.insertElementAt("sum[" + iLinearTerms + "]", 0);
		if(iLinearTerms > 1) vLinearInfix.insertElementAt("(", 1);
		
		Vector<String> vInfix = new Vector<String>();
		if(vLinearInfix.size() <= 0){
			vInfix = vNonlinearInfix;
		}
		else if(vNonlinearInfix.size() <= 0){
			vInfix = vLinearInfix;
		}
		else{
			if(iLinearTerms > 1) vLinearInfix.addElement(")");
			vLinearInfix.add("plus");
			vLinearInfix.add("(");
			vLinearInfix.addAll(vNonlinearInfix);
			vLinearInfix.add(")");
			vInfix = vLinearInfix;
		}
		
		if(iQuadraticTerms > 0){
			if(vInfix.size() > 0){
				vInfix.add("plus");
			}
			vInfix.addAll(vQuadraticInfix);
		}

		return vInfix;
	}//getInfix

	/**
	 * Calculate the value of the linear part of a function in a specified row 
	 * given the current variable values.  Negative row indicates an objective function. 
	 *
	 * </p>
	 *
	 * @param index holds the row number to which the linear function belongs. Negative row indicates an objective function.
	 * @param x holds the values of the variables in a double array.
	 * @return the linear part value of the function in the specified row.
	 * If there are errors, Doule.NaN is returned.  
	 */
	public double calculateLinearFunctionValue(int index, double[] x){
		double dValue = 0.0;
		int i, j;
		if(index < 0){
			try{
				getObjectiveCoefficients();
			}
			catch(Exception e){
				return Double.NaN;
			}
			SparseVector objCoefs = m_mObjectiveCoefficients[Math.abs(index)-1];
			int n = (objCoefs.values==null)?0:objCoefs.values.length;
			for(i = 0; i < n; i++){
				dValue += objCoefs.values[i] * x[objCoefs.indexes[i]];
			}
			dValue+= m_mdObjectiveConstants[Math.abs(index)-1];
			return dValue;
		}
		else{
			try {
				getLinearConstraintCoefficientsInRowMajor();
			} catch (Exception e) {
				return Double.NaN;
			}
			double[] values = m_linearConstraintCoefficientsInRowMajor.values;
			int[] starts = m_linearConstraintCoefficientsInRowMajor.starts;
			int[] indexes = m_linearConstraintCoefficientsInRowMajor.indexes;
			i = starts[index];
			j = starts[index+1];
			while(i < j){
				 dValue += values[i] * x[indexes[i]];
				 i++;
			}
			dValue+=m_mdConstraintConstants[index];
			return dValue;
		}
	}//calculateLinearFunctionValue

	/**
	 * Calculate all the values of the linear parts of the constraint functions 
	 * given the current variable values.
	 *
	 * </p>
	 *
	 * @param x holds the values of the variables in a double array.
	 * @return a double array of the linear part values of all the constraints.
	 * If there are errors, null is returned.  
	 */
	public double[] calculateLinearConstraintFunctionValues(double[] x){
		int iConstraintNumber = getConstraintNumber();
		double mdValues[] = new double[iConstraintNumber];
		try {
			getLinearConstraintCoefficientsInColumnMajor();
		} 
		catch (Exception e) {
			return null;
		}
		if(m_linearConstraintCoefficientsInColumnMajor == null){
			return mdValues;
		}
		double[] values = m_linearConstraintCoefficientsInColumnMajor.values;
		int[] starts = m_linearConstraintCoefficientsInColumnMajor.starts;
		int[] indexes = m_linearConstraintCoefficientsInColumnMajor.indexes;
		int n = (starts==null)?0:starts.length-1;
		int i, j;
		for(i = 0; i < n; i++){
			for(j = starts[i]; j < starts[i+1]; j++){
				mdValues[indexes[j]] += values[j] * x[i];
			}
		}
		for(i = 0; i< iConstraintNumber; i++){
			mdValues[i] += m_mdConstraintConstants[i];
		}
		return mdValues;
	}//calculateLinearConstraintFunctionValues

	/**
	 * Calculate the value of the quadratic part of a function in a specified row 
	 * given the current variable values. Negative row indicates an objective function.
	 *
	 * </p>
	 *
	 * @param index holds the row number to which the quadratic function belongs. Negative row indicates an objective function.
	 * @param x holds the values of the variables in a double array.
	 * @return the quadratic part value of the function in the specified row.
	 * If there are errors, Doule.NaN is returned.  
	 */
	public double calculateQuadraticFunctionValue(int index, double[] x){
		double dValue = 0;
		try {
			getQuadraticTerms();
		} catch (Exception e) {
			return Double.NaN;
		}
		if(m_quadraticTerms == null) return 0;
		int n = (m_quadraticTerms.coefficients==null)?0:m_quadraticTerms.coefficients.length;
		for(int i = 0; i < n; i++){
			if(m_quadraticTerms.rowIndexes[i] == index){
				dValue+= m_quadraticTerms.coefficients[i] * x[m_quadraticTerms.varOneIndexes[i]] * x[m_quadraticTerms.varTwoIndexes[i]];
			}
		}
		return dValue;
	}//calculateQuadraticFunctionValue
	
	/**
	 * Calculate the value of the quadratic part of a function in a specified row 
	 * given the current variable values. Negative row indicates an objective function.
	 *
	 * </p>
	 *
	 * @param x holds the values of the variables in a double array.
	 * @return the quadratic part value of the function in the specified row.
	 * If there are errors or there are no quadratic terms, null will be returned.  
	 */
	public double[] calculateQuadraticConstraintFunctionValues(double[] x){
		try {
			getQuadraticTerms();
		} catch (Exception e) {
			return null;
		}
		if(m_quadraticTerms == null) return null;
		double mdValue[] = new double[getConstraintNumber()];
		int n = (m_quadraticTerms.coefficients==null)?0:m_quadraticTerms.coefficients.length;
		for(int i = 0; i < n; i++){
			if(m_quadraticTerms.rowIndexes[i] < 0) continue;
			mdValue[m_quadraticTerms.rowIndexes[i]] += m_quadraticTerms.coefficients[i] * x[m_quadraticTerms.varOneIndexes[i]] * x[m_quadraticTerms.varTwoIndexes[i]];
		}
		return mdValue;
	}//calculateQuadraticConstraintFunctionValues
   	
	/**
	 * Calculate the nonlinear function value in a specified row given the current variable values.
	 * 
	 * </p>
	 * 
	 * @param index holds the row number to which the nonlinear function belongs. if negative, it is an objective function.
	 * @param x holds the values of the variables in a double array.
	 * @param functionEvaluated holds whether the function has been evaluated.
	 * @return the nonlinear function value in the specified constraint (row) given the current variable values.
	 */
   	public double calculateNonlinearExpressionValue(int index, double[] x){
   		try{
   			processNonlinearExpressions();
   		}
   		catch(Exception e){
   			return Double.NaN;
   		}
   		if(m_mapExpressionTrees == null) return 0;   		
   		OSExpressionTree exTree = (OSExpressionTree)m_mapExpressionTrees.get(index);
   		if(exTree == null) return 0;
   		return exTree.calculateFunction(x);
   	}//calculateNonlinearExpressionValue

	/**
	 * Calculate the function (nonlinear+quadratic+linear) 
	 * value in a specified row given the current variable values.
	 *
	 * </p>
	 *
	 * @param index holds the row number to which the function belongs. if negative, it is an objective function. 
	 * @param x holds the values of the variables in a double array.
	 * @return the function value in the specified row given the current variable values.
	 */
   	public double calculateFunctionValue(int index, double[] x){
   		double dLinear = calculateLinearFunctionValue(index, x);
   		double dQudratic = calculateQuadraticFunctionValue(index, x);
   		double dNonlinear = calculateNonlinearExpressionValue(index, x);
   		return dLinear + dQudratic + dNonlinear;
   	}//calculateFunctionValue

	/**
	 * Calculate all the constraint function (nonlinear+quadratic+linear) values given the current variable values.
	 *
	 * </p>
	 *
	 * @param x holds the values of the variables in a double array.
	 * @return all the constraint function values given the current variable values.
	 * If there are errors, null is returned;
	 */
   	public double[] calculateConstraintFunctionValues(double[] x){
   		double[] mdLinear = calculateLinearConstraintFunctionValues(x);
   		double[] mdQudratic = calculateQuadraticConstraintFunctionValues(x);
   		
   		int i;
   		double[] mdValues = mdLinear;
   		if(mdQudratic != null){
   			for(i = 0; i < mdQudratic.length; i++) mdValues[i] += mdQudratic[i];
   		}
   		int[] miNLTreeIndexes;
   		try {
			miNLTreeIndexes = getNonlinearExpressionTreeIndexes();
		} catch (Exception e1) {
			return null;
		}
   		if(miNLTreeIndexes == null) return mdValues;
   		for(i = 0; i < miNLTreeIndexes.length; i++){
   			if(miNLTreeIndexes[i] >= 0){
   				try{
   	   				mdValues[miNLTreeIndexes[i]] += getNonlinearExpressionTree(miNLTreeIndexes[i]).calculateFunction(x);   					
   				}
   				catch(Exception e){
   					return null;
   				}
   			}
   		}
   		return mdValues;
   	}//calculateConstraintFunctionValues

	/**
	 * Calculate the nonlinear gradients in a specified row given the current variable.
	 * </p>
	 *
	 * @param index holds the row number to which the nonlinear expression belongs. If negative, it's an objective function.
	 * @param x holds the values of the variables in a double array.
	 * @param functionEvaluated holds whether the function has been evaluated.
	 * @return a sparse representation of the function gradient values.
	 * <P>The <code>SparseVector</code> class holds a two array data structure (indexes, values). The indexes are not ordered.
	 * @see org.optimizationservices.oscommon.datastructure.osgeneral.SparseVector
	 */
   	public SparseVector calculateNonlinearExpressionGradients(int index, double[] x, boolean functionEvaluated){
   		try{
   			processNonlinearExpressions();
   		}
   		catch(Exception e){
   			return null;
   		}
   		if(m_mapExpressionTrees == null) return null; 
   		OSExpressionTree exTree = (OSExpressionTree)m_mapExpressionTrees.get(index);
   		if(exTree == null) return null;
   		Int2DoubleOpenHashMap map = exTree.calculateDerivatives(x, functionEvaluated);
   		SparseVector gradients = new SparseVector();
   		int n = map.size();
   		gradients.indexes = new int[n];
   		gradients.values = new double[n];
   		int i = 0;  		
		IntIterator iter = (IntIterator)map.keySet().iterator();
		while(iter.hasNext()){			
			gradients.indexes[i] = iter.nextInt();
			gradients.values[i] = map.get(gradients.indexes[i]);
		    i++;
		}
   		return gradients;
   	}//calculateNonlinearExpressionGradients

   	public SparseVector calculateFunctionGradients(int index, double[] x, boolean functionEValuated){//TODO wayne
   		SparseVector gradients = new SparseVector();
   		//get linear gradients
   		//get qudratic gradients
   		//get nonlinear gradients
   		//add all the above 3 types of gradients
   		return gradients;
   	}//calculateFunctionGradients

   	public SparseVector[] calculateFunctionGradients(double[] x, boolean functionEValuated){//TODO wayne
   		return null;
   	}//calculateFunctionGradients
   	
	/**
	 * Calculate the nonlinear hessian in a specified row given the current variable.
	 * </p>
	 *
	 * @param index holds the row number to which the nonlinear expression belongs. If negative, it's an objective function.
	 * @param x holds the values of the variables in a double array.
	 * @param functionEvaluated holds whether the function has been evaluated.
	 * @return a matrix market (i, j, Cij triplets) representation of the function hessian values, null if none. 
	 * <P>The <code>MatrixMarket</code> class holds the matrix market  
	 * data structure (rowIndex, columnIndex, Value[rowIndex,columnIndex]) hessian values.  
	 * @see org.optimizationservices.oscommon.datastructure.osgeneral.MatrixMarket
	 */
   	public MatrixMarket calculateNonlinearExpressionHessian(int index, double[] x, boolean gradientEvaluated){//TODO wayne
   		try{
   			processNonlinearExpressions();
   		}
   		catch(Exception e){
   			return null;
   		}
   		if(m_mapExpressionTrees == null) return null; 
   		OSExpressionTree exTree = (OSExpressionTree)m_mapExpressionTrees.get(index);
   		if(exTree == null) return null;
   		Object2DoubleOpenHashMap map = exTree.calculateHessian(x, gradientEvaluated);
   		MatrixMarket hessian = new MatrixMarket();
   		int n = map.size();
   		hessian.rowIndexes = new int[n];
   		hessian.columnIndexes = new int[n];
   		hessian.values = new double[n];   		
   		int i = 0;  
   		String sKey = null;
   		int iRow;
   		int iCol;
   		int iDelimiter;
		Iterator iter = map.keySet().iterator();
		while(iter.hasNext()){
			sKey = (String)iter.next();
			iDelimiter = sKey.indexOf(",");
			iRow = Integer.parseInt(sKey.substring(0, iDelimiter));
			iCol = Integer.parseInt(sKey.substring(iDelimiter+1));
			hessian.rowIndexes[i] = iRow;
			hessian.columnIndexes[i] = iCol;
			hessian.values[i] = map.getDouble(sKey);
		    i++;
		}
   		return hessian;
   	}//calculateNonlinearExpressionHessian

   	public MatrixMarket calculateFunctionHessian(int index, double[] x, boolean gradientEvaluated){//TODO wayne
   		return null;
   	}//calculateFunctionHessian
    	
   	public MatrixMarket calculateLagragianFunctionHessian(int objectiveIndex, double[] x, double[] weights, boolean gradientEvaluated){//TODO wayne
   		return null; 
   	}//calculateLagragianFunctionHessian
   	
   	public double[] calculateLagragianFunctionHessianTimesVector(int objectiveIndex, double[] x, double[] weights, double[] vector, boolean gradientEvaluated){//TODO wayne
   		return null; 
   	}//calculateLagragianFunctionHessianTimesVector
   	/***********************************************************************/

   	/**
   	 * set the instance source. 
   	 * 
   	 * @param source holds the instance source. 
   	 * @return whether the instance source is set successfully. 
   	 */
   	public boolean setInstanceSource(String source){
   		instanceHeader.source = source;
   		return true;
   	}//setInstanceSource
   	
   	/**
   	 * set the instance description. 
   	 * 
   	 * @param description holds the instance description. 
   	 * @return whether the instance description is set successfully. 
   	 */
   	public boolean setInstanceDescription(String description){
   		instanceHeader.description = description;
   		return true;
   	}//setInstanceDescription
   	  	
   	/**
   	 * set the instance name. 
   	 * 
   	 * @param name holds the instance name. 
   	 * @return whether the instance name is set successfully. 
   	 */
   	public boolean setInstanceName(String name){
   		instanceHeader.name = name;
   		return true;
   	}//setInstanceName
   	
   	/**
   	 * set the variable number. 
   	 * 
   	 * @param number holds the variable number. 
   	 * @return whether the variable number is set successfully. 
  	 */
   	public boolean setVariableNumber(int number){
   		if(number <= 0) return false;
   		if(instanceData.variables == null) instanceData.variables = new Variables();
   		instanceData.variables.numberOfVariables = number;
		instanceData.variables.var = new Variable[number];
   		for(int i = 0; i < number; i++) instanceData.variables.var[i] = new Variable();
   		return true;
   	}//setVariableNumber

   	/**
   	 * add a variable. In order to use the add method, the setVariableNumber must first be called
   	 * so that the variable number is known ahead of time to assign appropriate memory.  
   	 * If a variable with the given variable index already exists, the old variable will be replaced. 
   	 * 
   	 * <p>
   	 * 
   	 * @param index holds the variable index. It is required.  
   	 * @param name holds the variable name; use null or empty string ("") if no variable name. 
   	 * @param lowerBound holds the variable lower bound; use Double.NEGATIVE_INFINITY if no lower bound. 
   	 * @param upperBound holds the variable upper bound; use Double.POSITIVE_INFINITY if no upper bound. 
   	 * @param type holds the variable type character, B for Binary, I for Integer, S for String, C or any other char for Continuous)
   	 * @param init holds the double variable initial value; use Double.NaN if no initial value. 
   	 * @param initString holds the string variable initial value; use null or empty string ("") if no initial string value.  
   	 * @return whether the variable is added successfully. 
   	 */
   	public boolean addVariable(int index, String name, double lowerBound, double upperBound, char type, double init, String initString){
   		Variable[] var = instanceData.variables.var;
   		if(index < 0 || instanceData.variables.numberOfVariables <= 0 || index >= instanceData.variables.numberOfVariables) return false;
   		var[index].name = name;
   		var[index].lb = lowerBound;
   		var[index].ub = upperBound;
   		var[index].type = type;
   		var[index].init = init;
   		var[index].initString = initString;
   		return true;
   	}//addVariable
   	
   	/**
   	 * set all the variable related elements. All the previous variable-related elements will be deleted. 
   	 * 
   	 * <p>
   	 * 
   	 * @param number holds the number of variables. It is required.  
   	 * @param names holds a string array of variable names; use null if no variable names. 
   	 * @param lowerBounds holds a double array of variable lower bounds; use null all lower bounds are 0; use Double.NEGATIVE_INFINITY if no lower bound for a specific variable in the array. 
   	 * @param upperBounds holds a double array of variable upper bounds; use null if no upper bounds; use Double.POSITIVE_INFINITY if no upper bound for a specific variable in the array. 
   	 * @param types holds a char array of variable types; use null if all variables are continuous; 
   	 * for a specfic variable in the array use B for Binary, I for Integer, S for String, C or any other char for Continuous,)  
   	 * @param inits holds a double array of varible initial values; use null if no initial values. 
   	 * @param initsString holds a string array of varible initial values; use null if no initial string values.  
   	 * @return whether the variables are set successfully. 
   	 */
   	public boolean setVariables(int number, String[] names, double[] lowerBounds, double[] upperBounds, char[] types, double[] inits, String[] initsString){
   		if(number <= 0) return false;
   		if((names != null && names.length != number) ||
   		   (lowerBounds != null && lowerBounds.length != number) ||
   		   (upperBounds != null && upperBounds.length != number) ||
   		   (types != null && types.length != number) ||
   		   (inits != null && inits.length != number) ||
   		   (initsString != null && initsString.length != number)) return false;
   		instanceData.variables.numberOfVariables = number;
   		instanceData.variables.var = new Variable[number];
   		int i = 0;
   		for(i = 0; i < number; i++){
   			instanceData.variables.var[i] = new Variable();
   		}
   		Variable[] var = instanceData.variables.var;
   		if(names != null){
   	   		for(i = 0; i < number; i++) var[i].name = names[i];   			
   		}
   		if(lowerBounds != null){
   	   		for(i = 0; i < number; i++) var[i].lb = lowerBounds[i];   			
   		}
   		if(upperBounds != null){
   	   		for(i = 0; i < number; i++) var[i].ub = upperBounds[i];   			
   		}
   		if(types != null){
   	   		for(i = 0; i < number; i++){
   	   			var[i].type = types[i];
   	   			if(types[i] != 'C' && types[i] != 'B' && types[i] != 'I' && types[i] != 'S') types[i] = 'C';
   	   		}
   		}
   		if(inits != null){
   	   		for(i = 0; i < number; i++) var[i].init = inits[i];   			
   		}
   		if(initsString != null){
   	   		for(i = 0; i < number; i++) var[i].initString = initsString[i];   			
   		}
   		return true;
   	}//setVariables

   	/**
   	 * set the objective number. 
   	 * 
   	 * @param number holds the objective number. 
   	 * @return whether the objective number is set successfully. 
   	 */
   	public boolean setObjectiveNumber(int number){
   		if(number < 0) return false;
   		if(number == 0){
   			instanceData.objectives = new Objectives();
   			instanceData.objectives.numberOfObjectives = 0;
   			instanceData.objectives.obj = null;
   			return true;
   		}
   		if(instanceData.objectives == null) instanceData.objectives = new Objectives();
   		instanceData.objectives.numberOfObjectives = number;
   		instanceData.objectives.obj = new Objective[number];  			
   		for(int i = 0; i < number; i++) instanceData.objectives.obj[i] = new Objective();
   		return true;
   	}//setObjectiveNumber
   	   	
   	/**
   	 * add an objective. In order to use the add method, the setObjectiveNumber must first be called
   	 * so that the objective number is known ahead of time to assign appropriate memory.  
   	 * If a objective with the given objective index already exists, the old objective will be replaced.
   	 * Objective index will start from -1, -2, -3, ... down, with -1 corresponding to the first objective.  
   	 * 
   	 * <p>
   	 * 
   	 * @param index holds the objective index. Remember the first objective index is -1, second -2, ...
   	 * @param name holds the objective name; use null or empty string ("") if no objective name. 
   	 * @param maxOrMin holds the objective sense or direction; it can only take two values: "max" or "min". 
   	 * @param constant holds the objective constant; use 0.0 if no objective constant. 
   	 * @param weight holds the objective weight; use 1.0 if no objective weight.
   	 * @param objectiveCoefficients holds the objective coefficients (null if no objective coefficients) in a sparse 
   	 * representation that holds two arrays: index array and a value array.  
   	 * @return whether the objective is added successfully. 
   	 */
   	public boolean addObjective(int index, String name, String maxOrMin, double constant, double weight, SparseVector objectiveCoefficients){
   		Objective[] obj = instanceData.objectives.obj;
   		if(index >= 0 || instanceData.objectives.numberOfObjectives <= 0 || Math.abs(index) > instanceData.objectives.numberOfObjectives) return false;
   		int arrayIndex = Math.abs(index) -1;
   		obj[arrayIndex].name = name;
   		if(maxOrMin == null || (!maxOrMin.equals("max") && !maxOrMin.equals("min"))) return false;
   		else obj[arrayIndex].maxOrMin = maxOrMin;
   		obj[arrayIndex].constant = constant;
   		obj[arrayIndex].weight = weight;
   		int n = (objectiveCoefficients == null || objectiveCoefficients.indexes == null)?0:objectiveCoefficients.indexes.length;   		
   		obj[arrayIndex].numberOfObjCoef = n;
   		if(n == 0){
   			obj[arrayIndex].coef = null;
   		}
   		else{
   	   		obj[arrayIndex].coef = new ObjCoef[n];
   	   		for(int i = 0; i < n; i++){
   	   	   		obj[arrayIndex].coef[i] = new ObjCoef();
   	   	   		obj[arrayIndex].coef[i].idx = objectiveCoefficients.indexes[i];
   	   			obj[arrayIndex].coef[i].value = objectiveCoefficients.values[i];   			
   	   		}   			
   		}
   		return true;
   	}//addObjective
   	
   	/**
   	 * set all the objectives related elements. All the previous objective-related elements will be deleted. 
   	 * 
   	 * <p>
   	 * 
   	 * @param number holds the number of objectives. It is required.  
   	 * @param names holds a string array of objective names; use null if no objective names. 
   	 * @param maxOrMins holds a string array of objective objective senses or directions: "max" or "min"; use null if all objectives are "min".   
   	 * @param constants holds a double array of objective constants; use null if all objective constants are 0.0. 
   	 * @param weights holds a double array of objective weights; use null if all objective weights are 1.0. 
     * @param objectitiveCoefficients holds an array of objective coefficients, (null if no objective have any coefficeints)
     * For each objective, the coefficients are stored in a sparse representation that holds two arrays: index array and a value array.  
     * If for a specific objective, there are no objecitve coefficients, use null for the corresponding array member. 
  	 * @return whether the objectives are set successfully. 
   	 */
   	public boolean setObjectives(int number, String[] names, String[] maxOrMins, double[] constants, double[] weights, SparseVector[] objectitiveCoefficients){
   		if(number < 0) return false;
   		if(number == 0){
   			instanceData.objectives = new Objectives();
   			instanceData.objectives.numberOfObjectives = 0;
   			instanceData.objectives.obj = null;
   			return true;
   		}
   		if((names != null && names.length != number) ||
   		   (maxOrMins != null && maxOrMins.length != number) ||
   		   (maxOrMins != null && maxOrMins.length != number) ||
   		   (constants != null && constants.length != number) ||
   		   (weights != null && weights.length != number) ||
   		   (objectitiveCoefficients != null && objectitiveCoefficients.length != number)) return false;
   		instanceData.objectives.numberOfObjectives = number;
   		instanceData.objectives.obj = new Objective[number];
   		int i = 0;
   		int j = 0;
   		for(i = 0; i < number; i++){
   			instanceData.objectives.obj[i] = new Objective();
   		}
   		Objective[] obj = instanceData.objectives.obj;
   		if(names != null){
   	   		for(i = 0; i < number; i++) obj[i].name = names[i];   			
   		}	
   		if(maxOrMins != null){
	   		for(i = 0; i < number; i++){
	   			if(maxOrMins[i] == null || (!maxOrMins[i].equals("max") && !maxOrMins[i].equals("min"))) return false;
	   			obj[i].maxOrMin = maxOrMins[i];   			
	   		}
   		}
   		if(constants != null){
   	   		for(i = 0; i < number; i++) obj[i].constant = constants[i];   			
   		}
   		if(weights != null){
   	   		for(i = 0; i < number; i++) obj[i].weight = weights[i];   			
   		}
   		if(objectitiveCoefficients != null){
   			for(i = 0; i < number; i++){
   	   	   		int n = (objectitiveCoefficients[i] == null || objectitiveCoefficients[i].indexes == null)?0:objectitiveCoefficients[i].indexes.length;   		
   	   	   		obj[i].numberOfObjCoef = n;
   	   	   		if(n == 0){
   	   	   			obj[i].coef = null;
   	   	   		}
   	   	   		else{
   	   	   	   		obj[i].coef = new ObjCoef[n];
   	   	   	   		for(j = 0; j < n; j++){
   	   	   	   			obj[i].coef[j] = new ObjCoef();
   	   	   	   			obj[i].coef[j].idx = objectitiveCoefficients[i].indexes[j];
   	   	   	   			obj[i].coef[j].value = objectitiveCoefficients[i].values[j];   			
   	   	   	   		}   			
   	   	   		}   			   				
   			}
   		}
   		return true;
   	}//setObjectives

   	/**
   	 * set the constraint number. 
   	 * 
   	 * @param number holds the constraint number. 
   	 * @return whether the constraint number is set successfully. 
   	 */
   	public boolean setConstraintNumber(int number){
   		if(number < 0) return false;
   		if(number == 0){
   			instanceData.constraints = new Constraints();
   			instanceData.constraints.numberOfConstraints = 0;
   			instanceData.constraints.con = null;
   			return true;
   		}
   		if(instanceData.constraints == null) instanceData.constraints = new Constraints();
   		instanceData.constraints.numberOfConstraints = number;
   		instanceData.constraints.con = new Constraint[number];
   		for(int i = 0; i < number; i++) instanceData.constraints.con[i] = new Constraint();
   		return true;
   	}//setConstraintNumber

   	/**
   	 * add a constraint. In order to use the add method, the setConstraintNumber must first be called
   	 * so that the constraint number is known ahead of time to assign appropriate memory.  
   	 * If a constraint with the given constraint index already exists, the old constraint will be replaced. 
   	 * 
   	 * <p>
   	 * 
   	 * @param index holds the constraint index. It is required.  
   	 * @param name holds the constraint name; use null or empty string ("") if no constraint name. 
   	 * @param lowerBound holds the constraint lower bound; use Double.NEGATIVE_INFINITY if no lower bound. 
   	 * @param upperBound holds the constraint upper bound; use Double.POSITIVE_INFINITY if no upper bound. 
   	 * @param constant holds the constraint constant.
   	 * @return whether the constraint is added successfully. 
   	 */
   	public boolean addConstraint(int index, String name, double lowerBound, double upperBound, double constant) {
   		Constraint[] con = instanceData.constraints.con;
   		if(index < 0 || instanceData.constraints.numberOfConstraints <= 0 || index >= instanceData.constraints.numberOfConstraints) return false;
   		con[index].name = name;
   		con[index].lb = lowerBound;
   		con[index].ub = upperBound;
   		con[index].constant = constant;
   		return true;
   	}//addConstraint

   	/**
   	 * set all the constraint related elements. All the previous constraint-related elements will be deleted. 
   	 * 
   	 * <p>
   	 * 
   	 * @param number holds the number of constraints. It is required.  
   	 * @param names holds a string array of constraint names; use null if no constraint names. 
   	 * @param lowerBounds holds a double array of constraint lower bounds; use null if no lower bounds; use Double.NEGATIVE_INFINITY if no lower bound for a specific constraint in the array. 
   	 * @param upperBounds holds a double array of constraint upper bounds; use null if no upper bounds; use Double.POSITIVE_INFINITY if no upper bound for a specific constraint in the array.
   	 * @param constants holds a double array of constraint constants, use null if all are zeros.  
   	 * @return whether the constraints are set successfully. 
   	 */
   	public boolean setConstraints(int number, String[] names, double[] lowerBounds, double[] upperBounds, double[] constants){
   		if(number < 0) return false;
   		if(number == 0){
   			instanceData.constraints = new Constraints();
   			instanceData.constraints.numberOfConstraints = 0;
   			instanceData.constraints.con = null;
   			return true;
   		}
   		if((names != null && names.length != number) ||
   		   (lowerBounds != null && lowerBounds.length != number) ||
   		   (upperBounds != null && upperBounds.length != number) ||
   		   (constants != null && constants.length != number)) return false;
   		instanceData.constraints.numberOfConstraints = number;
   		instanceData.constraints.con = new Constraint[number];
   		int i = 0;
   		for(i = 0; i < number; i++){
   			instanceData.constraints.con[i] = new Constraint();
   		}
   		Constraint[] con = instanceData.constraints.con;
   		if(names != null){
   	   		for(i = 0; i < number; i++) con[i].name = names[i];   			
   		}
   		if(lowerBounds != null){
   	   		for(i = 0; i < number; i++) con[i].lb = lowerBounds[i];   			
   		}
   		if(upperBounds != null){
   	   		for(i = 0; i < number; i++) con[i].ub = upperBounds[i];   			
   		}
   		if(constants != null){
   	   		for(i = 0; i < number; i++) con[i].constant = constants[i];   			
   		}
   		return true;
   	}//setConstraints


   	/**
   	 * set linear constraint coefficients
   	 * 
   	 * <p>
   	 * 
   	 * @param number holds the number of specified coefficient values (usually nonzero) in the coefficient matrix. 
   	 * @param isColumnMajor holds whether the coefficient matrix is stored in column major (true) or row major (false).
   	 * @param values holds a double array coefficient values in the matrix. 
   	 * @param valuesBegin holds the begin index of the values array to copy from (usually 0). 
   	 * @param valuesEnd holds the end index of the values array to copy till (usually values.lenght - 1). 
   	 * @param indexes holds an integer array column/row indexes for each value in the values array.
   	 * @param indexesBegin holds the begin index of the indexes array to copy from (usually 0).
   	 * @param indexesEnd holds the end index of the indexes array to copy till (usually indexes.lenght - 1).
   	 * @param starts holds an integer array start indexes in the matrix; the first value of starts should always be 0. 
   	 * @param startsBegin holds the begin index of the starts array to copy from (usually 0).
   	 * @param startsEnd holds the end index of the starts array to copy till (usually starts.lenght - 1). 
   	 * @return whether the linear constraint coefficients are set successfully.  
   	 */
   	public boolean setLinearConstraintCoefficients(int number, boolean isColumnMajor, 
   			double[] values, int valuesBegin, int valuesEnd, 
   			int[] indexes, int indexesBegin, int indexesEnd,   			
   			int[] starts, int startsBegin, int startsEnd){
   		if(number < 0) return false;
   		if(number == 0){
   			instanceData.linearConstraintCoefficients = new LinearConstraintCoefficients();
   			return true;
   		}
   		if((values == null || values.length < number) ||
   		   (valuesBegin < 0 || valuesEnd >= values.length || (valuesEnd - valuesBegin + 1) != number) ||
   		   (indexes == null || indexes.length < number) ||
   		   (indexesBegin < 0 || indexesEnd >= indexes.length || (indexesEnd - indexesBegin + 1) != number) ||
   		   (starts == null || starts.length <= 1) ||
   		   (startsBegin < 0 || startsEnd >= starts.length || startsBegin >= startsEnd)) return false;
   		instanceData.linearConstraintCoefficients = new LinearConstraintCoefficients();
   		instanceData.linearConstraintCoefficients.numberOfValues = number;
 
   		int i = 0;
   		//values
   		if(valuesBegin == 0 && valuesEnd == values.length -1){
   			instanceData.linearConstraintCoefficients.value.el = values;
   		}
   		else{
   	   		instanceData.linearConstraintCoefficients.value.el = new double[number];
   	   		int k = 0;
   	   		for(i = valuesBegin; i <= valuesEnd; i++){
   	   			instanceData.linearConstraintCoefficients.value.el[k] = values[i];
   	   			k++;
   	   		}
   		}
   		//indexes
   		if(isColumnMajor){
   	   		if(indexesBegin == 0 && indexesEnd == indexes.length -1){
   	   			instanceData.linearConstraintCoefficients.rowIdx.el = indexes;
   	   		}
   	   		else{
   	   	   		instanceData.linearConstraintCoefficients.rowIdx.el = new int[number];
   	   	   		int k = 0;
   	   	   		for(i = indexesBegin; i <= indexesEnd; i++){
   	   	   			instanceData.linearConstraintCoefficients.rowIdx.el[k] = indexes[i];
   	   	   			k++;
   	   	   		}
   	   		}
   		} 
   		else{
   	   		if(indexesBegin == 0 && indexesEnd == indexes.length -1){
   	   			instanceData.linearConstraintCoefficients.colIdx.el = indexes;
   	   		}
   	   		else{
   	   	   		instanceData.linearConstraintCoefficients.colIdx.el = new int[number];
   	   	   		int k = 0;
   	   	   		for(i = indexesBegin; i <= indexesEnd; i++){
   	   	   			instanceData.linearConstraintCoefficients.colIdx.el[k] = indexes[i];
   	   	   			k++;
   	   	   		}
   	   		}
   		}
   		//starts
   		if(startsBegin == 0 && startsEnd == starts.length -1){
   			instanceData.linearConstraintCoefficients.start.el = starts;
   		}
   		else{
   	   		instanceData.linearConstraintCoefficients.start.el = new int[startsEnd - startsBegin + 1];
   	   		int k = 0;
   	   		for(i = startsBegin; i <= startsEnd; i++){
   	   			instanceData.linearConstraintCoefficients.start.el[k] = starts[i];
   	   			k++;
   	   		}
   		}
   		return true;
   	}//setLinearConstraintCoefficients
   	
   	/**
   	 * set quadratic terms
   	 * 
   	 * <p>
   	 * 
   	 * @param number holds the number of quadratic terms. 
   	 * @param rowIndexes holds an integer array of row indexes of all the quadratic terms. 
	 * A negative integer corresponds to an objective row, e.g. -1 for 1st objective and -2 for 2nd.
   	 * @param varOneIndexes holds an integer array of the first varialbe indexes of all the quadratic terms.
   	 * @param varTwoIndexes holds an integer array of the second varialbe indexes of all the quadratic terms.
   	 * @param coefficients holds a double array all the quadratic term coefficients.
   	 * @param begin holds the begin index of all the arrays to copy from (usually = 0). 
   	 * @param end holds the end index of all the arrays to copy till (usually = array length -1).
   	 * @return whether the quadratic terms are set successfully.  
   	 */
	public boolean setQuadraticTerms(int number, 
			int[] rowIndexes, int[] varOneIndexes, int[] varTwoIndexes, double[] coefficients,
			int begin, int end){
 		if(number < 0) return false;
   		if(number == 0){
   			instanceData.quadraticCoefficients = null;
   			return true;
   		}
   		if(((end - begin + 1) != number) ||
   		   (rowIndexes == null || rowIndexes.length < number) ||   		   
   		   (varOneIndexes == null || varOneIndexes.length < number) ||
   		   (varTwoIndexes == null || varTwoIndexes.length < number) ||
   		   (coefficients == null || coefficients.length < number)) return false;
   		instanceData.quadraticCoefficients = new QuadraticCoefficients();
   		instanceData.quadraticCoefficients.numberOfQuadraticTerms = number;
   		int i = 0;
   		instanceData.quadraticCoefficients.qTerm = new QuadraticTerm[number];
   		for(i = 0; i < number; i++) instanceData.quadraticCoefficients.qTerm[i] = new QuadraticTerm();
   	   	int k = 0;
   	   	for(i = begin; i <= end; i++){
	   			instanceData.quadraticCoefficients.qTerm[k].idx = rowIndexes[i];
	   			instanceData.quadraticCoefficients.qTerm[k].idxOne = varOneIndexes[i];
	   			instanceData.quadraticCoefficients.qTerm[k].idxTwo = varTwoIndexes[i];
	   			instanceData.quadraticCoefficients.qTerm[k].coef = coefficients[i];
	   			k++;
	   	}
		return true;
	}//setQuadraticTerms
 	 
   	/**
   	 * set the number of nonlinear expression trees to add. Expression trees with the same row indexes are concatenaged so 
   	 * they are counted as just one nonlinear expression tree. 
   	 * 
   	 * @param number holds the nonlinear expression tree number.  
   	 * @return whether the nonlinear expression tree number is set successfully. 
   	 */	
	public boolean setNonlinearExpressionTreeNumber(int number){
		m_iCurrentlyAddedNumberOfNonlinearExpressions = 0;
   		if(number < 0) return false;
   		instanceData.nonlinearExpressions.numberOfNonlinearExpressions = number;
   		if(number == 0){
   			instanceData.nonlinearExpressions = new NonlinearExpressions();
   			instanceData.nonlinearExpressions.nl = null;
   			return true;
   		}
   		if(instanceData.nonlinearExpressions == null) instanceData.nonlinearExpressions = new NonlinearExpressions();
   		if(instanceData.nonlinearExpressions.nl == null || instanceData.nonlinearExpressions.nl.length != number){
   	   		instanceData.nonlinearExpressions.nl = new Nl[number];
   	   		for(int i = 0; i < number; i++) instanceData.nonlinearExpressions.nl[i] = new Nl();
   		}
   		return true;
	}//setNonlinearExpressionTreeNumber
	
	/**
	 * add a nonlinear expression tree. In order to use the add method, the setNonlinearExpressionTreeNumber 
	 * must first be called so that the nonlinear expression tree number is known ahead of time to 
	 * assign appropriate memory.  
   	 * If a nonlinear expression tree with the given index already exists, the old constraint will be concatenated (added)
   	 * with the new expression tree. 
   	 * 
	 * 
   	 * @param index holds the row the nonlienar expression tree belongs to. If negative, it is an objective function.   
	 * @param osExpressionTree holds the os expression. 
	 * @return whether the expression tree is added successfully.
	 * @see org.optimizationservices.oscommon.nonlinear.OSExpressionTree;
	 */
	public boolean addNonlinearExpressionTree(int index, OSExpressionTree osExpressionTree){
		Nl[] nl = instanceData.nonlinearExpressions.nl;
   		if((index < 0 && Math.abs(index) > instanceData.objectives.numberOfObjectives) 
   				|| index >= instanceData.constraints.numberOfConstraints) return false;
   		
		if(m_mapExpressionTrees == null)  m_mapExpressionTrees = new Int2ObjectOpenHashMap();
		OSExpressionTree tree = (OSExpressionTree)m_mapExpressionTrees.get(index);
		if( tree!= null){
			tree.concatenate(osExpressionTree);
		}
		else{
			m_mapExpressionTrees.put(index, osExpressionTree);			
	   		nl[m_iCurrentlyAddedNumberOfNonlinearExpressions].idx = index;
	   		nl[m_iCurrentlyAddedNumberOfNonlinearExpressions].osExpressionTree = osExpressionTree;
	   		m_iCurrentlyAddedNumberOfNonlinearExpressions++;
		}
   		
   		return true;
	}//addNonlinearExpressionTree -- OSExpressionTree
	
	/**
	 * add a nonlinear expression tree. In order to use the add method, the setNonlinearExpressionTreeNumber 
	 * must first be called so that the nonlinear expression tree number is known ahead of time to 
	 * assign appropriate memory.  
   	 * If a nonlinear expression tree with the given index already exists, the old constraint will be concatenated (added)
   	 * with the new expression tree. 
	 * 
   	 * @param index holds the row the nonlienar expression tree belongs to. If negative, it is an objective function.   
	 * @param tokens holds a string array of the tokenized expression, in either postfix, prefix, or infix.
	 * The operator name in each token has to be exactly the same as the name specified in the OSnL Schema. 
	 * The operator name in the token may be followed (without space) by a sequence of ":atrributeValue" and end with
	 * [i] to indicate the number of arguments the operator can take if the operator's type is indefinite. 
	 * The attributes specified have to follow the sequence in the OSnL schema.  
	 * If one attribute is specified, all attributes have to be specified together. If an attribute 
	 * are missing, an empty string has to be in place. Two alternative exception can be allowed for variable 
	 * and number. A number can just a a numeric value and the variable can take the form Xi where i is the 
	 * integer index of capital letter X. 
	 * @param fixType holds whether the expression is in postfix, prefix or infix
	 * @param start holds the index of the tokenizedExpression to start processing (ususually 0).
	 * @param end holds the index of the tokenizedExpression to finish processing (usually tokens.length-1). 
	 * @return whether the expression tree is added successfully.
	 */
	public boolean addNonlinearExpressionTree(int index, String[] tokens, int start, int end, String fixType){
		int i; 
		int n = (tokens==null)?0:tokens.length;
		Vector<String> vTokens = new Vector<String>();
		for(i = 0; i < n; i++){
			vTokens.add(tokens[i]);
		}
		OSExpressionTree osExpressionTree = new OSExpressionTree(vTokens, fixType, start, end);		
		Nl[] nl = instanceData.nonlinearExpressions.nl;
   		if((index < 0 && Math.abs(index) > instanceData.objectives.numberOfObjectives) 
   				|| index >= instanceData.constraints.numberOfConstraints) return false;
   		
   		
		if(m_mapExpressionTrees == null)  m_mapExpressionTrees = new Int2ObjectOpenHashMap();
		OSExpressionTree tree = (OSExpressionTree)m_mapExpressionTrees.get(index);
		if( tree!= null){
			tree.concatenate(osExpressionTree);
		}
		else{
			m_mapExpressionTrees.put(index, osExpressionTree);			
	   		nl[m_iCurrentlyAddedNumberOfNonlinearExpressions].idx = index;
	   		nl[m_iCurrentlyAddedNumberOfNonlinearExpressions].osExpressionTree = osExpressionTree;
	   		m_iCurrentlyAddedNumberOfNonlinearExpressions++;
		}
   		return true;
	}//addNonlinearExpressionTree -- string tokens

	/**
	 * main for test purposes.
	 *
	 * </p>
	 *
	 * @param argv command line arguments.
	 */
	public static void main(String[] args){

		OSInstance p = new OSInstance();
		
		int i, j;
		p.setInstanceSource("source1");
		System.out.println(p.getInstanceSource());
		p.setInstanceName("name1");
		System.out.println(p.getInstanceName());
		p.setInstanceDescription("description1");
		System.out.println(p.getInstanceDescription());
		p.setVariableNumber(2);
		String[] varNames = {"var0", "var1"};
		double[] varLbs = null;//{-100, -200};
		double[] varUbs = null;//{100, 200};
		char[] varTypes = null;//{'C', 'B'};
		double[] varInits = null;// {1.1, 2.2};
		String[] varInitsString = null;// {"1.1a", "2.2a"};
		if(!p.setVariables(2, varNames, varLbs, varUbs, varTypes, varInits, varInitsString)) System.out.println("setVariables ERROR");
		//if(!p.addVariable(0, "var00", -100, -200, 'C', 1.1, "1.1a")) System.out.println("addVariable ERROR");
		//if(!p.addVariable(1, "var11", -100, 200, 'B', 2.2, "2.2a")) System.out.println("addVariable ERROR");
		int nVar = p.getVariableNumber();
		System.out.println("varNumber: " + nVar);
		try{
			String[] ms;
			double[] md;
			char[] mc;
			ms = p.getVariableNames();
			System.out.println("variable names");
			for(i = 0; i < (ms==null?0:ms.length); i++){
				System.out.println(ms[i]);
			}
			System.out.println("variable inits");
			md = p.getVariableInitialValues();
			for(i = 0; i < (md==null?0:md.length); i++){
				System.out.println(md[i]);
			}
			System.out.println("variable initsString");
			ms = p.getVariableInitialStringValues();
			for(i = 0; i < (ms==null?0:ms.length); i++){
				System.out.println(ms[i]);
			}
			System.out.println("variable lbs");
			md = p.getVariableLowerBounds();
			for(i = 0; i < (md==null?0:md.length); i++){
				System.out.println(md[i]);
			}
			System.out.println("variable ubs");
			md = p.getVariableUpperBounds();
			for(i = 0; i < (md==null?0:md.length); i++){
				System.out.println(md[i]);
			}
			System.out.println("variable types");
			mc = p.getVariableTypes();
			for(i = 0; i < (mc==null?0:mc.length); i++){
				System.out.println(mc[i]);
			}
		}
		catch(Exception e){
			e.printStackTrace();
		}
		p.setObjectiveNumber(2);
		//String[] objNames = null;//{"obj0", "obj1"};
		//double[] objWeights = null;//{1.0, 2.0};
		//double[] objConstants = null;//{1.11111, 2.22222};
		//String[] objTypes = null;//{"min", "max"};
		SparseVector[] objCoefArray = new SparseVector[2];
		objCoefArray[0] = new SparseVector();
		objCoefArray[0].indexes = new int[1];
		objCoefArray[0].indexes[0] = 0;
		objCoefArray[0].values = new double[1];
		objCoefArray[0].values[0] = 1;
		objCoefArray[1] = new SparseVector();
		objCoefArray[1].indexes = new int[2];
		objCoefArray[1].indexes[0] = 0;
		objCoefArray[1].indexes[1] = 1;
		objCoefArray[1].values = new double[2];
		objCoefArray[1].values[0] = 2;
		objCoefArray[1].values[1] = 3;
		
		
		//if(!p.setObjectives(2, objNames, objTypes, objConstants, objWeights, objCoefArray)) System.out.println("setObjectives ERROR");
		if(!p.addObjective(-1, "obj00", "min", 1.1111, 1.0, objCoefArray[0])) System.out.println("addObjective ERROR");
		if(!p.addObjective(-2, "obj11", "max", 2.2222, 2.0, objCoefArray[1])) System.out.println("addObjective ERROR");
		int nObj = p.getObjectiveNumber();
		System.out.println("objNumber: " + nObj);
		try{
			String[] ms;
			double[] md;
			int[] mi;
			SparseVector[] mObjCoef;
			ms = p.getObjectiveNames();
			System.out.println("obj names");
			for(i = 0; i < (ms==null?0:ms.length); i++){
				System.out.println(ms[i]);
			}
			ms = p.getObjectiveMaxOrMins();
			System.out.println("obj maxOrMins");
			for(i = 0; i < (ms==null?0:ms.length); i++){
				System.out.println(ms[i]);
			}
			mi = p.getObjectiveCoefficientNumbers();
			System.out.println("obj constants");
			md = p.getObjectiveConstants();
			for(i = 0; i < (md==null?0:md.length); i++){
				System.out.println(md[i]);
			}
			System.out.println("obj weights");
			md = p.getObjectiveWeights();
			for(i = 0; i < (md==null?0:md.length); i++){
				System.out.println(md[i]);
			}
			System.out.println("obj coefs");
			mObjCoef = p.getObjectiveCoefficients();
			for(i = 0; i < (mObjCoef==null?0:mObjCoef.length); i++){
				System.out.println("obj: " + i);
				System.out.println("numberOfObjCoef: " + mi[i]);
				for(j = 0; j < (mObjCoef[i] == null || mObjCoef[i].indexes==null?0:mObjCoef[i].indexes.length); j++){
					System.out.println("X[" + mObjCoef[i].indexes[j] + "] coef = " + mObjCoef[i].values[j]);
				}
			}
		}
		catch(Exception e){
			e.printStackTrace();
		}
		p.setConstraintNumber(6);
		String[] conNames = null;//{"con0", "con1", "con2", "con3", "con4", "con5"};
		double[] conLbs = null;//{-100, Double.NEGATIVE_INFINITY, -300, 400, Double.NEGATIVE_INFINITY,-600};
		double[] conUbs = null;//{100, 200, Double.POSITIVE_INFINITY, 400, Double.POSITIVE_INFINITY, 600};
		if(!p.setConstraints(6, conNames, conLbs, conUbs, null)) System.out.println("setConstraint ERROR");
		//if(!p.addConstraint(0, "con00", -100, 100)) System.out.println("addConstraint ERROR");
		//if(!p.addConstraint(5, "con11", -200, 200)) System.out.println("addConstraint ERROR");
		int nCon = p.getConstraintNumber();
		System.out.println("conNumber: " + nCon);
		try{
			String[] ms;
			double[] md;
			char[] mc;
			ms = p.getConstraintNames();
			System.out.println("constraint names");
			for(i = 0; i < (ms==null?0:ms.length); i++){
				System.out.println(ms[i]);
			}
			System.out.println("constraint lbs");
			md = p.getConstraintLowerBounds();
			for(i = 0; i < (md==null?0:md.length); i++){
				System.out.println(md[i]);
			}
			System.out.println("constraint ubs");
			md = p.getConstraintUpperBounds();
			for(i = 0; i < (md==null?0:md.length); i++){
				System.out.println(md[i]);
			}
			System.out.println("constraint types");
			mc = p.getConstraintTypes();
			for(i = 0; i < (mc==null?0:mc.length); i++){
				System.out.println(mc[i]);
			}
		}
		catch(Exception e){
			e.printStackTrace();
		}
				
		int[] miStarts = {0, 2, 4, 4, 4, 4, 4};
		int[] miIndexes = {0, 1, 0, 1};
		double[] mdCoefs = {1, 2, 3, 4};
		if(!p.setLinearConstraintCoefficients(4, false, 
				mdCoefs, 0, mdCoefs.length-1, 
				miIndexes, 0, miIndexes.length-1, 
				miStarts, 0, miStarts.length-1)) System.out.println("setLinearConstraintCoefficients ERROR");
		int nLPCoef = p.getLinearConstraintCoefficientNumber();
		System.out.println("linearConstraintCoefficientNumber: " + nLPCoef);
		try{
			//SparseMatrix matrix = p.getLinearConstraintCoefficientsInColumnMajor();
			SparseMatrix matrix = p.getLinearConstraintCoefficientsInRowMajor();
			int[] miStart = matrix.starts;
			int[] miIndex = matrix.indexes;
			double[] mdCoef = matrix.values;
			System.out.println(p.getLinearConstraintCoefficientMajor());
			for(i = 0; i < (miStart==null?0:miStart.length); i++){
				System.out.println("start: " + miStart[i]);
			}
			for(i = 0; i < (mdCoef==null?0:mdCoef.length); i++){
				System.out.println("index: " + miIndex[i] + "   coef: " + mdCoef[i]);
			}
		}
		catch(Exception e){
			e.printStackTrace();
		}
	
		int[] miRowIndexes = {1, 0, 0};
		int[] miVarOneIndexes = {0, 0, 1};
		int[] miVarTwoIndexes = {0, 1, 1};
		double[] mdQuadraticCoefs = {1.00, 0.01, 0.11};
		if(!p.setQuadraticTerms(3, miRowIndexes, miVarOneIndexes, miVarTwoIndexes, mdQuadraticCoefs, 0, 2)) System.out.println("setQuadraticTerms ERROR");
		int nQTerm = p.getQuadraticTermNumber();
		System.out.println("qTermNumber: " + nQTerm);
		try{
			QuadraticTerms qTerms = p.getQuadraticTerms();
			int[] miRow = qTerms.rowIndexes;
			int[] miVarOneIdx = qTerms.varOneIndexes;
			int[] miVarTwoIdx = qTerms.varTwoIndexes;
			double[] mdQuadraticCoef = qTerms.coefficients;
			for(i = 0; i < (mdQuadraticCoef==null?0:mdQuadraticCoef.length); i++){
				System.out.println("X[" + miVarOneIdx[i] + ", " + miVarTwoIdx[i]+"] row = " + miRow[i] + " coef = " + mdQuadraticCoef[i]);
			}
		}
		catch(Exception e){
			e.printStackTrace();
		}
		p.setNonlinearExpressionTreeNumber(1);
		String[] msTokens = {"X0", "times", "X1"};
		String sFixType = "infix";
		int nlRow = 1;
		if(!p.addNonlinearExpressionTree(nlRow, msTokens, 0, msTokens.length-1, sFixType)) System.out.println("addNonlinearExpressionTree ERROR");
		try {
			String[] msToken = p.getNonlinearExpressionTreeInInfix(1);
			System.out.println("nlRow: " + nlRow + "   " + "Infix:" );
			for(i = 0; i < msToken.length; i++) System.out.println(msToken[i]);
		} catch (Exception e) {
			e.printStackTrace();
		}
		double[] x = {1.1, 2.2};
		System.out.println("function value: " + p.calculateNonlinearExpressionValue(1, x));
		System.out.println("gradient value: ");
		SparseVector gradients = p.calculateNonlinearExpressionGradients(1, x, true);
		int[] gIndex = gradients.indexes;
		double[] gValue = gradients.values;
		for(i = 0; i < (gIndex==null?0:gIndex.length); i++){
			System.out.println("X[" + gIndex[i] + "] gradient=" + gValue[i]);
		}
		
		try {
			System.out.println(p.writeOSiL());
		} 
		catch (Exception e1) {
			// TODO Auto-generated catch block
			e1.printStackTrace();
		}
		/*
		String sOSiL = IOUtil.fileToString("../../../OSRepository/test/osil/parincLinear.osil");
		try {
			p = p.readOSiL(sOSiL, false, false);
			SparseMatrix matrix = p.getLinearConstraintCoefficientsInRowMajor();
			matrix.display(p.m_iVariableNumber);
			matrix = p.getLinearConstraintCoefficientsInColumnMajor();
			matrix.display(p.m_iConstraintNumber);
			System.out.println(p.writeOSiL());
		} catch (Exception e) {
			e.printStackTrace();
		}
		*/

	}//main
	
	
}//class OSInstance