/**
 * @(#)OSiLReader 1.0 03/14/2004
 *
 * Copyright (c) 2004
 */
package org.optimizationservices.oscommon.representationparser;

import it.unimi.dsi.fastutil.ints.Int2DoubleOpenHashMap;
import it.unimi.dsi.fastutil.ints.Int2ObjectOpenHashMap;
import it.unimi.dsi.fastutil.ints.IntIterator;
import it.unimi.dsi.fastutil.ints.IntOpenHashSet;
import it.unimi.dsi.fastutil.objects.Object2DoubleOpenHashMap;

import java.util.HashSet;
import java.util.Hashtable;
import java.util.Vector;

import org.optimizationservices.oscommon.datastructure.osgeneral.QuadraticTerms;
import org.optimizationservices.oscommon.datastructure.osgeneral.SparseVector;
import org.optimizationservices.oscommon.datastructure.osinstance.QuadraticTerm;
import org.optimizationservices.oscommon.localinterface.OSInstance;
import org.optimizationservices.oscommon.nonlinear.OSExpressionTree;
import org.optimizationservices.oscommon.nonlinear.OSnLNode;
import org.optimizationservices.oscommon.util.CommonUtil;
import org.optimizationservices.oscommon.util.IOUtil;
import org.optimizationservices.oscommon.util.XMLUtil;
import org.w3c.dom.Element;
import org.w3c.dom.NamedNodeMap;
import org.w3c.dom.Node;
import org.w3c.dom.NodeList;
import org.w3c.dom.Text;



/**
 *
 * <P>The <code>OSiLReader</code> class parses an OSiL instance into a DOM tree and
 * provides a set of "get" methods (e.g. getVariableNames) that can be used to retrieve
 * different pieces of information of the optimization instance.</p>
 *
 * </p>
 *
 * @author Robert Fourer, Jun Ma, Kipp Martin
 * @version 1.0, 03/14/2004
 * @see org.optimizationservices.ossolver.parser.FMLHandler
 * @see org.optimizationservices.ossolver.parser.FMLReader
 * @see org.xml.sax.XMLReader
 * @see org.optimizationservices.oscommon.representationparser.OSiLReader
 * @since OS 1.0
 */
public class OSiLReader extends OSgLReader{
	/**
	 * m_osInstance holds the standard OSInstance, which is is a local interface for 
	 * storing Optimization Services problem input. 
	 */
	protected OSInstance m_osInstance = null;
	
	/**
	 * m_sLogicError holds the message of logic errors OSiLReader finds in
	 * the OSiL instance.
	 */
	protected String m_sLogicError = "";
	
	/**
	 * m_bProcessVariables holds whether the &lt;variables&gt; element has been processed.
	 */
	protected boolean m_bProcessVariables = false;

	/**
	 * m_bProcessObjectivess holds whether the &lt;objectives&gt; element has been processed.
	 */
	protected boolean m_bProcessObjectives = false;

	/**
	 * m_bProcessConstraints holds whether the &lt;constraints&gt; element has been processed.
	 */
	protected boolean m_bProcessConstraints = false;

	/**
	 * m_bconvertSDPA holds whether the &lt;sparseSDPA&gt; element has been processed.
	 */
	protected boolean m_bProcessSDPA = false;
	
	/**
	 * m_bProcessVariables holds whether the &lt;nl&gt; elements has been processed.
	 */
	protected boolean m_bProcessNonlinearExpressions = false;
	
	/**
	 * m_bCheckColumnMajor holds whether the reader has checked the coefMatrix (AMatrix) is column major or not.
	 */
	protected boolean m_bCheckColumnMajor = false;

	/**
	 * m_iNumberVariables holds the number of variables.
	 */
	protected int m_iNumberVariables = -1;
	
	/**
	 * m_iNumberObjectives holds the number of objectives.
	 */
	protected int m_iNumberObjectives = -1;
	
	/**
	 * m_iNumberConstraints holds the number of constraints.
	 */
	protected int m_iNumberConstraints = -1;

	/**
	 * m_iNumberCoefficientMatrixValues holds the number of specified values (usually nonzero) in the 
	 * linear coefficient matrix.
	 */
	protected int m_iNumberCoefficientMatrixValues = -1;

	/**
	 * m_iQuadraticTermNumber holds the number of specified 
	 * (usually nonzero) qTerms in the quadratic coefficients. 
	 */
	private int m_iNumberQuadraticCoefficientTerms = -1;
	
	/**
	 * m_iNonlinearExpressionNumber holds the number of nonlinear expressions. 
	 */
	private int m_iNonlinearExpressionNumber = -1;

	/**
	 * m_sName holds the name of the optimization problem.
	 */
	protected String m_sName = null;

	/**
	 * m_sSource holds the source information of the optimization problem.
	 */
	protected String m_sSource = null;

	/**
	 * m_sDescription holds the description information of the optimization problem.
	 */
	protected String m_sDescription = null;

	/**
	 * m_mdObjConstant holds an array of objective function constants.
	 */
	protected double[] m_mdObjConstant = null;
	
	/**
	 * m_msObjName holds an array of objective names. 
	 */
	protected String[] m_msObjName = null;
	
	/**
	 * m_msMaxOrMin holds an array of objective function directions (or senses).
	 */
	protected String[] m_msMaxOrMin = null;

	/**
	 * m_mdObjWeight holds an array of objective function weights.
	 */
	protected double[] m_mdObjWeight = null;

	/**
	 * m_bColumnMajor holds whether the coefMatrix (AMatrix) holding linear program
	 * data is stored by column. If false, the matrix is stored by row.
	 */
	protected boolean m_bColumnMajorInCoefMatrix = true;
	
	/**
	 * m_miStartCoefMatrix holds an integer array of start elements in coefMatrix (AMatrix),
	 * which points to the start of a column (row) of nonzero elements in coefMatrix (AMatrix).
	 */
	protected int[] m_miStartCoefMatrix = null; 
	
	/**
	 * m_viIdx holds an integer array of rowIdx (or colIdx) elements in coefMatrix (AMatrix).
	 * If the matrix is stored by column (row), rowIdx (colIdx) is the array of
	 * row (column) indices.
	 */
	protected int[] m_miIdxCoefMatrix = null;

	/**
	 * m_mdValueCoefMatrix holds a double array of value elements in coefMatrix (AMatrix),
	 * which contains nonzero elements.
	 */
	protected double[] m_mdValueCoefMatrix = null;

	/**
	 * m_quadraticTerms holds the data structure for all quadratic terms in the optimization instance. 
	 * (rowIndexes, varOneIndexes, varTwoIndexes, coefficients)
	 */
	protected QuadraticTerms m_quadraticTerms = null;

	/**
	 * m_mmiJacobianNonzeroIndex holds a two dimmensional integer array indexes = int[2][numNonzeroIndexes]. So in essense, the method returns
	 * two arrays of the same size. The 1st array -- indexes[0] of size numNonzeroIndexes -- contains the row (constraint) number of a variable 
	 * index and the 2nd array -- indexes[1] again of size numNonzeroIndexes -- contains the variable index. For example
	 * if indexes[0] = {0, 0, 1, 1, 2} and indexes[1] = {1, 3, 0, 2, 1}, it means variables appear in (row, col) = (0, 1), (0, 3), (1, 0), (1, 2) and (2, 1) 
	 * so the corresponding entries in the Jacobian matrix may be nonzeros.  
	 */
	protected int[][] m_mmiJacobianNonzeroIndex = null;

	/**
	 * m_mmdObjDenseCoefValue holds an array of double arrays; each double array holds the dense coefficient values of an objective function.
	 */
	protected double[][] m_mmdObjDenseCoefValue = null;

	/**
	 * m_miObjNonzeroCoefNumber holds the numbers of the nonzero coefficient values of all objective functions.
	 */
	protected int[] m_miObjNonzeroCoefNumber = null;

	/**
	 * m_mmdObjNonzeroCoefValue holds an array of double arrays; each double array holds the nonzero coefficient values of an objective function.
	 */
	protected double[][] m_mmdObjNonzeroCoefValue = null;
	
	/**
	 * m_mmiObjNonzeroCoefIndex holds an array of integer arrays; each integer array holds the variable indexes of the nonzero coefficient values of an objective function.
	 */
	protected int[][] m_mmiObjNonzeroCoefIndex = null;

	/**
	 * m_mObjectiveCoefficients holds an array of objective coefficients, one set of objective 
	 * coefficients for each objective. 
	 */
	protected SparseVector[] m_mObjectiveCoefficients = null;
	
	/**
	 * m_mdInit holds an array of variable initial values in doubles.
	 */
	protected double[] m_mdInit = null;

	/**
	 * m_msInit holds an array of variable initial values (value kept in strings).
	 */
	protected String[] m_msInit = null;
	
	/**
	 * m_mdLb holds an array of variable lower bounds.
	 */
	protected double[] m_mdLb = null;
	
	/**
	 *m_mdUb holds an array of variable upper bounds.
	 */
	protected double[] m_mdUb = null;
	
	/**
	 * m_mdLhs holds an array of the constraint lower bounds.
	 */
	protected double[] m_mdLhs = null;
	
	/**
	 * m_mdRhs holds an array of the constraint upper bounds.
	 */
	protected double[] m_mdRhs = null;
	
	/**
	 * m_mdConstraintConstant holds an array of constraint function constants.
	 */
	protected double[] m_mdConstraintConstant = null;
	
	/**
	 * m_mcConstraintTypes holds a char array of constraint types
	 * (R for range; L for <=; G for >=; E for =; U for unconstrained)
	 */
	private char[] m_mcConstraintTypes = null;
	
	/**
	 * m_msVarName holds an array of variable names.
	 */
	protected String[] m_msVarName = null;
	
	/**
	 * m_msConName holds an array of constraint names.
	 */
	protected String[] m_msConName = null;
	
	/**
	 * m_vcVarType holds an array of variable types (character), e.g. 'C' for continuous
	 * type, 'I' for integer type, 'B' for binary type, 'S' for string type).
	 */
	protected char[] m_mcVarType = null;
	
	/**
	 * m_sSDPA holds the text of SDPA format.
	 */
	protected String m_sSDPA = "";

	/**
	 * m_quadraticTermMap holds a hash map of quadratic terms, with the key being the rowIdx (row number)
	 * and value being the holding a vecotr of quadratic terms of that row.
	 */
	protected Hashtable <String, Vector<QuadraticTerm>> m_quadraticTermMap = new Hashtable<String, Vector<QuadraticTerm>>();

	/**
	 * m_expressionMap holds a hash map of expression trees, with the key being the rowIdx (row number)
	 * and value being the expression tree representing the nonlinear function of that row.
	 */
	protected Int2ObjectOpenHashMap m_expressionTrees = new Int2ObjectOpenHashMap();
	
	/**
	 * m_miNonlinearExpressionIndexes holds an integer array of nonlinear expression indexes,
	 * negative indexes correspond to objectives.  
	 */
	private int[] m_miNonlinearExpressionIndexes = null;

	/**
	 * m_eXMLData holds the &lt;xmlData&gt; element. 
	 */
	protected Element m_eXMLData = null;
	
	/**
	 * constructor.
	 *
	 * </p>
	 *
	 * @param validate holds whether the reader should be validating against the schema or not.
	 */
	public OSiLReader(boolean validate){
		m_bXsdValidate = validate;
	}//constructor
	
	/**
	 * constructor.
	 */
	public OSiLReader(){
		
	}//constructor
	   	
	/**
	 * get the OSInstance, a standard optimization problem/data api.  
	 * 
	 * @return the OSInstance. 
	 * @throws Exception if there are errors getting the OSInstnace. 
	 */
   	public OSInstance getOSInstance() throws Exception{
		if(m_osInstance != null){
			return m_osInstance;
		}
		m_osInstance = new OSInstance();

		if(!m_osInstance.setInstanceName(getInstanceName())) throw new Exception("setInstanceName Unsuccessful");
		if(!m_osInstance.setInstanceSource(getInstanceSource())) throw new Exception("setInstanceSource Unsuccessful");
		if(!m_osInstance.setInstanceDescription(getInstanceDescription())) throw new Exception("setInstanceDescription Unsuccessful");

		int nVar = getVariableNumber();
		int nObj = getObjectiveNumber();
		int nCon = getConstraintNumber();
		int nLinearCoef = getLinearConstraintCoefficientNumber();
		int nQuadraticCoef = getQuadraticTermNumber();
		if(!m_osInstance.setVariableNumber(nVar)) throw new Exception("setVariableNumber Unsuccessful");
		if(!m_osInstance.setObjectiveNumber(nObj)) throw new Exception("setObjectiveNumber Unsuccessful");
		if(!m_osInstance.setConstraintNumber(nCon)) throw new Exception("setConstraintNumber Unsuccessful");
		
		
		int i;
		//set variables
		String[] msVarNames = getVariableNames();
		double[] mdVarLbs = getVariableLowerBounds();
		double[] mdVarUbs = getVariableUpperBounds();
		char[] mcVarTypes = getVariableTypes();
		double[] mdVarIits = getVariableInitialValues();
		String[] msVarInitsString = getVariableInitialStringValues();
		if(!m_osInstance.setVariables(nVar, msVarNames, mdVarLbs, mdVarUbs, mcVarTypes, mdVarIits, msVarInitsString))
			throw new Exception("setVariables Unsuccessful");
		
		//set objectives
		String[] msObjNames = getObjectiveNames();
		String[] msObjMaxOrMins = getObjectiveMaxOrMins();
		double[] mdObjConstants = getObjectiveConstants();
		double[] mdObjWeights = getObjectiveWeights();
		int[][] mmiObjCoefIndexes = getObjectiveNonzeroCoefficientIndexes();
		double[][] mmdObjCoefValues = getObjectiveNonzeroCoefficientValues();
		SparseVector[] mObjCoefs = null;
		if(mmdObjCoefValues != null){
			mObjCoefs = new SparseVector[nObj];
			for(i = 0; i < nObj; i ++){
				mObjCoefs[i] = new SparseVector();
				mObjCoefs[i].indexes = mmiObjCoefIndexes[i];
				mObjCoefs[i].values = mmdObjCoefValues[i];
			} 
		}
		if(!m_osInstance.setObjectives(nObj, msObjNames, msObjMaxOrMins, mdObjConstants, mdObjWeights, mObjCoefs))
			throw new Exception("setObjectives Unsuccessful");
		
		//set constraints
		String[] msConNames = getConstraintNames();
		double[] mdConLbs = getConstraintLowerBounds();
		double[] mdConUbs = getConstraintUpperBounds();
		double[] mdConConstants = getConstraintConstants();
		if(!m_osInstance.setConstraints(nCon, msConNames, mdConLbs, mdConUbs, mdConConstants))
			throw new Exception("setConstraints Unsuccessful");
		
		//set linear constraint coefficients 
		double[] mdValues = getLinearConstraintCoefficientMatrixNonzeroValues();
		int[] miIndexes = getLinearConstraintCoefficientMatrixNonzeroIndexes();
		int[] miStarts = getLinearConstraintCoefficientMatrixStartIndexes();
		if(mdValues != null){
			if(!m_osInstance.setLinearConstraintCoefficients(nLinearCoef,
					getLinearConstraintCoefficientMajor(),
					mdValues, 0, mdValues.length-1, 
	     			miIndexes, 0, miIndexes.length-1, 
	     			miStarts, 0, miStarts.length-1))
	     		throw new Exception("setLinearConstraintCoefficients Unsuccessful");  			
		}
		//set quadratic coefficients
		QuadraticTerms qTerms = getQuadraticTerms();
		if(qTerms != null){
			if(!m_osInstance.setQuadraticTerms(nQuadraticCoef, 
					qTerms.rowIndexes, qTerms.varOneIndexes, qTerms.varTwoIndexes, qTerms.coefficients,
					0, qTerms.coefficients.length-1))
					throw new Exception("setQuadraticTerms Unsuccessful");  			
		}
		
		//set nonlienar expression trees
		Int2ObjectOpenHashMap exTreeMap = getNonlinearExpressions();
		if(exTreeMap != null && exTreeMap.size() > 0){
			if(!m_osInstance.setNonlinearExpressionTreeNumber(exTreeMap.size())) throw new Exception("setNonlinearExpressionTreeNumber Unsuccessful");  
			IntIterator it = (IntIterator)exTreeMap.keySet().iterator();
			while(it.hasNext()){
				int iKey = it.nextInt();
				if(!m_osInstance.addNonlinearExpressionTree(iKey, (OSExpressionTree)exTreeMap.get(iKey))) throw new Exception("addNonlinearExpressionTree Unsuccessful");
			}
		}
		
		return m_osInstance;
	}//getOSInstance
		
	/**
	 * Converts an OSiL instance to an SDPA semidefinite programming instance. Assuming the OSiL is a pure SDPA program.  
	 * 
	 * @param osilInstance holds an instance of OSiL to be converted to an SDPA instance.
	 * @return the SDPA instance that is converted from the OSiL instance. A null is returned 
	 * if there is any error in the conversion. 
	 */
	protected String convertToSDPA(){
		if(m_bProcessSDPA){
			return m_sSDPA;
		}
		int i, j, k;
		Element eInstanceData = (Element)XMLUtil.findChildNode(m_eRoot, "instanceData");
		Element eSemidefiniteBlocks = (Element)XMLUtil.findChildNode(eInstanceData, "semidefiniteBlocks");
		if(eSemidefiniteBlocks == null) return null;
		Element eBlockSizes = (Element)eSemidefiniteBlocks.getElementsByTagName("blockSizes").item(0);
		NodeList blockSizeList = eBlockSizes.getElementsByTagName("el");
		Vector<String> vsElValue = new Vector<String>();
		int iEl = blockSizeList.getLength();
		for(i = 0; i < iEl; i++){
			int iMult = 1;
			int iInc = 0;
			Element eEl = (Element)(blockSizeList.item(i));
			int iElValue = Integer.parseInt(XMLUtil.getElementValue(eEl));
			NamedNodeMap attributes =  eEl.getAttributes();
			int n =attributes.getLength();
			for (j = 0; j < n; j++) {
				String sLocalName = attributes.item(i).getLocalName();
				String sValue = attributes.item(i).getNodeValue();
				if (sLocalName.equals("mult")) {
					iMult = Integer.parseInt(sValue);
				}
				else if (sLocalName.equals("incr")) {
					iInc = Integer.parseInt(sValue);
				}
			}	
			for (k = 0; k < iMult; k++) {
				vsElValue.add((iElValue + iInc * i) + "");
			}
		}
		NodeList matrixList = eSemidefiniteBlocks.getElementsByTagName("matrix");
		if(matrixList.getLength() > getVariableNumber() + 1)m_sLogicError += "<sparseSDPA>: too many matrices.\n";
		m_sSDPA += matrixList.getLength() + "\n";
		if(vsElValue.size() > getConstraintNumber())m_sLogicError += "<sparseSDPA>: matrix size inconsistent with number of constraints.\n";
		m_sSDPA += vsElValue.size() + "\n";
		int iTotalBlockSize = 0;
		for(i = 0; i < vsElValue.size(); i++){
			int iBlockSize = Integer.parseInt((String)vsElValue.elementAt(i));
			if(iBlockSize <= 0)m_sLogicError += "<sparseSDPA>: nonpositive block size.\n";
			iTotalBlockSize += iBlockSize;
			m_sSDPA += (String)vsElValue.elementAt(i);
		}
		if(iTotalBlockSize != getConstraintNumber())m_sLogicError += "<sparseSDPA>: block sizes not adding up to number of constraints.\n";
		m_sSDPA += "\n";
		double[] mdObjCoefValue = getFirstObjectiveNonzeroCoefficientValues();
		int[] miObjCoefIndex = getFirstObjectiveNonzeroCoefficientIndexes();
		int n = getVariableNumber();
		int start = 0;
		for(i = 0; i < ((miObjCoefIndex==null)?0:miObjCoefIndex.length); i++){
			for(j = start; j < miObjCoefIndex[i]; j++){ 
				m_sSDPA += (0 + " ");
			}
			m_sSDPA += (mdObjCoefValue[i] + " ");
			start = miObjCoefIndex[i]+1;
		}
		for(j = start; j < n; j++){
			m_sSDPA += (0 + " ");
		}
		m_sSDPA += "\n";
		for(i = 0; i < matrixList.getLength(); i++){
			Element eMatrix = (Element)matrixList.item(i);
			String sMatrixID = eMatrix.getAttribute("id");
			int iMatrixID = Integer.parseInt(sMatrixID);
			if(iMatrixID >= matrixList.getLength())m_sLogicError += "<sparseSDPA>: matrix id larger than total matrix number.\n";
			if(iMatrixID < 0)m_sLogicError += "<sparseSDPA>: matrix id negative.\n";
			NodeList blockList = eMatrix.getElementsByTagName("block");
			for(j = 0; j < blockList.getLength(); j++){
				Element eBlock = (Element)blockList.item(j);
				String sBlockID = eBlock.getAttribute("id");
				int iBlockID = Integer.parseInt(sBlockID);
				if(iBlockID >= vsElValue.size())m_sLogicError += "<sparseSDPA>: block id larger than total block number.\n";
				if(iBlockID < 0)m_sLogicError += "<sparseSDPA>: block id negative.\n";
				NodeList elList = eBlock.getElementsByTagName("el");
				for(k = 0; k < elList.getLength(); k++){
					Element eEl = (Element)elList.item(k);
					String sElRow = eEl.getAttribute("row");
					String sElCol = eEl.getAttribute("col");
					int iElRow = Integer.parseInt(sElRow);
					if(iElRow < 0) m_sLogicError += "<sparseSDPA>: row index negative.\n";
					if(iBlockID >= 0 && iBlockID < vsElValue.size()){
						int iRowSize = Integer.parseInt((String)vsElValue.elementAt(iBlockID));
						if(iElRow >= iRowSize) m_sLogicError += "<sparseSDPA>: row index bigger than block size.\n";
					}
					int iElCol = Integer.parseInt(sElCol);
					if(iElCol < 0) m_sLogicError += "<sparseSDPA>: column index negative.\n";
					if(iBlockID >= 0 && iBlockID < vsElValue.size()){
						int iColSize = Integer.parseInt((String)vsElValue.elementAt(iBlockID));
						if(iElCol >= iColSize) m_sLogicError += "<sparseSDPA>: column index bigger than block size.\n";
					}
					if(iBlockID >= vsElValue.size())m_sLogicError += "<sparseSDPA>: block id larger than total block number.\n";
					String sElValue = XMLUtil.getElementValue(eEl);
					m_sSDPA += sMatrixID + " ";
					m_sSDPA += sBlockID + " ";
					m_sSDPA += sElRow + " ";
					m_sSDPA += sElCol + " ";
					m_sSDPA += sElValue + " ";
					m_sSDPA += "\n";
				}
			}
		}
		m_bProcessSDPA = true;
		return m_sSDPA;
	}//convertToSDPA
	
		
	/**
	 * Get logic error messages (one a line) the OSiLReader finds in the OSiL instance.
	 * 
	 * @return logic error messages (one a line) the OSiLReader finds in the OSiL instance.
	 */
	public String getLogicError(){
		int iVariables = getVariableNumber();
		int iObjectives = getObjectiveNumber();
		int iConstraints = getConstraintNumber();
		if(iVariables < 0 || iObjectives < 0 || iConstraints <0) m_sLogicError += "<instanceHeader>: variable, objective or constraint count negative.\n";
		processObjectives();
		processVariables();
		processConstraints();
		getLinearConstraintCoefficientMatrixStartIndexes();
		getLinearConstraintCoefficientMatrixNonzeroIndexes();
		getLinearConstraintCoefficientMatrixNonzeroValues();
		getNonlinearExpressions();
		convertToSDPA();
		return m_sLogicError;
	}//getLogicError

	/**
	 * Get the value of  &lt;name&gt; element in the OSiL instance.
	 *
	 * </p>
	 *
	 * @return the name of the OSiL instance, null if none.
	 */
	public String getInstanceName(){
		if(m_sName == null){
			m_sName = XMLUtil.getElementValueByName(m_eRoot, "name");
		}
		return m_sName;
	}//getInstanceName 

	
	/**
	 * Get the value of  &lt;source&gt; element in the OSiL instance.
	 *
	 * </p>
	 *
	 * @return the source information of the OSiL instance, null if none.
	 */
	public String getInstanceSource(){
		if(m_sSource == null){
			m_sSource = XMLUtil.getElementValueByName(m_eRoot, "source");
		}
		return m_sSource;
	}//getInstanceSource 

	/**
	 * Get the value of  &lt;description&gt; element in the OSiL instance.
	 *
	 * </p>
	 *
	 * @return the description information of the OSiL instance, null if none.
	 */
	public String getInstanceDescription(){
		if(m_sDescription == null){
			m_sDescription = XMLUtil.getElementValueByName(m_eRoot, "description");
		}
		return m_sDescription;
	}//getInstanceDescription
	
	/**
	 * Get the the number of variables. 
	 *
	 * </p>
	 *
	 * @return the number of variables.
	 */
	public int getVariableNumber(){
		if(m_iNumberVariables == -1){
			Element eInstanceData = (Element)XMLUtil.findChildNode(m_eRoot, "instanceData");
			Element eVariables = (Element)XMLUtil.findChildNode(eInstanceData, "variables");
			String sNumber =  eVariables.getAttribute("numberOfVariables");
			m_iNumberVariables = Integer.parseInt(sNumber);
		}
		return m_iNumberVariables;
	}//getVariableNumber
	
	/**
	 * Get the number of objective functions.
	 *
	 * </p>
	 *
	 * @return the number of Objectives.
	 */
	public int getObjectiveNumber(){
		if(m_iNumberObjectives == -1){
			Element eInstanceData = (Element)XMLUtil.findChildNode(m_eRoot, "instanceData");
			Element eObjectives = (Element)XMLUtil.findChildNode(eInstanceData, "objectives");
			if(eObjectives != null){
				String sNumber =  eObjectives.getAttribute("numberOfObjectives");
				if(sNumber != null && sNumber.length() > 0){
					m_iNumberObjectives = Integer.parseInt(sNumber);					
				}
				else{
					m_iNumberObjectives = 1;
				}
			}
			else{
				m_iNumberObjectives = 0;
			}
		}
		return m_iNumberObjectives;
	}//getObjectiveNumber


	/**
	 * Get the number of constraints. 
	 *
	 * </p>
	 *
	 * @return the number of constraints.
	 */
	public int getConstraintNumber(){
		if(m_iNumberConstraints == -1){
			Element eInstanceData = (Element)XMLUtil.findChildNode(m_eRoot, "instanceData");
			Element eConstraints = (Element)XMLUtil.findChildNode(eInstanceData, "constraints");
			if(eConstraints != null){
				String sNumber =  eConstraints.getAttribute("numberOfConstraints");
				m_iNumberConstraints = Integer.parseInt(sNumber);					
			}
			else{
				m_iNumberConstraints = 0;
			}
		}
		return m_iNumberConstraints;
	}//getConstraintNumber

	/**
	 * Get the number of specified values (usually nonzero) in the linear coefficient matrix.
	 *
	 * </p>
	 *
	 * @return the number of values in the linear coefficient matrix.
	 */
	public int getLinearConstraintCoefficientNumber(){
		if(m_iNumberCoefficientMatrixValues == -1){
			Element eInstanceData = (Element)XMLUtil.findChildNode(m_eRoot, "instanceData");
			Element eCoefMatrix = (Element)XMLUtil.findChildNode(eInstanceData, "linearConstraintCoefficients");
			if(eCoefMatrix != null){
				String sNumber =  eCoefMatrix.getAttribute("numberOfValues");
				m_iNumberCoefficientMatrixValues = Integer.parseInt(sNumber);					
			}
		}
		return m_iNumberCoefficientMatrixValues;
	}//getLinearConstraintCoefficientNumber

	/**
	 * Get the number of specified qTerms (usually nonzero) in the quadratic coefficients.
	 *
	 * </p>
	 *
	 * @return the number of specified qTerms (usually nonzero) in the quadratic coefficients.
	 */
	public int getQuadraticTermNumber(){
		if(m_iNumberQuadraticCoefficientTerms == -1){
			Element eInstanceData = (Element)XMLUtil.findChildNode(m_eRoot, "instanceData");
			Element eQuadCoef = (Element)XMLUtil.findChildNode(eInstanceData, "quadraticCoefficients");
			if(eQuadCoef != null){
				String sNumber =  eQuadCoef.getAttribute("numberOfQuadraticTerms");
				m_iNumberQuadraticCoefficientTerms = Integer.parseInt(sNumber);					
			}
			else{
				m_iNumberQuadraticCoefficientTerms = 0;
			}
		}
		return m_iNumberQuadraticCoefficientTerms;
	}//getQuadraticTermNumber

	/**
	 * Get the number of nonlinear expressions. 
	 *
	 * </p>
	 *
	 * @return the number of nonlinear expressions.
	 */
	public int getNonlinearExpressionTreeNumber(){
		if(m_iNonlinearExpressionNumber == -1){
			Element eInstanceData = (Element)XMLUtil.findChildNode(m_eRoot, "instanceData");
			Element eNonlinearExpressions = (Element)XMLUtil.findChildNode(eInstanceData, "nonlinearExpressions");
			if(eNonlinearExpressions != null){
				String sNumber =  eNonlinearExpressions.getAttribute("numberOfNonlinearExpressions");
				m_iNonlinearExpressionNumber = Integer.parseInt(sNumber);					
			}
			else{
				m_iNonlinearExpressionNumber = 0;
			}
		}
		return m_iNonlinearExpressionNumber;
	}//getNonlinearExpressionTreeNumber

	/**
	 * Process &lt;variables&gt; element in the OSiL instance and retrive information from all its
	 * &lt;var&gt; child elements. Information retrieved includes name, init, type, ub, lb.
	 *
	 * </p>
	 *
	 * @return whether the &lt;variables&gt; element has been processed.
	 */
	protected boolean processVariables(){
		if(m_bProcessVariables){
			return true;
		}
		Element eInstanceData = (Element)XMLUtil.findChildNode(m_eRoot, "instanceData");
		Element eVariables = (Element)XMLUtil.findChildNode(eInstanceData, "variables");
		if(eVariables == null) return false;
		NodeList nodeList = eVariables.getElementsByTagName("var");
		int iVarChildren = nodeList.getLength();
		int iVariableCount = getVariableNumber();
		int iVarIndex = 0;
		m_msVarName = new String[iVariableCount];
		m_mdInit = new double[iVariableCount];
		m_msInit = new String[iVariableCount];
		m_mcVarType = new char[iVariableCount];
		m_mdLb = new double[iVariableCount];
		m_mdUb =new double[iVariableCount];
		Element eVar = null;
		int i, j;
		for(i = 0; i < iVarChildren; i++){
			eVar = (Element)(nodeList.item(i));
			NamedNodeMap attributes =  eVar.getAttributes();
			int n =attributes.getLength();
			String sName = "";
			double dInit = Double.NaN;
			String sInit = "";
			char cType = 'C';
			double dUb = Double.POSITIVE_INFINITY;
			double dLb = 0.0;
			int iMult = 1;
			for (j = 0; j < n; j++) {
				Node attr = attributes.item(j);
				String sLocalName = attr.getNodeName();
				String sValue = attr.getNodeValue();
				if (sLocalName.equals("name")){
					sName = sValue;
				}
				else if (sLocalName.equals("init")){
					if(CommonUtil.isPostiveInfinity(sValue)) dInit = Double.POSITIVE_INFINITY;
					else if(CommonUtil.isNegativeInfinity(sValue)) dInit = Double.NEGATIVE_INFINITY;
					else dInit = Double.parseDouble(sValue);
				}
				else if (sLocalName.equals("initString")){
					if(CommonUtil.isPostiveInfinity(sValue)) sInit = Double.POSITIVE_INFINITY + "";
					else if(CommonUtil.isNegativeInfinity(sValue)) sInit = Double.NEGATIVE_INFINITY + "";
					else sInit = sValue;
				}
				else if (sLocalName.equals("type")){
					cType = sValue.charAt(0);
				}
				else if (sLocalName.equals("lb")){
					if(CommonUtil.isPostiveInfinity(sValue)) dLb = Double.POSITIVE_INFINITY;
					else if(CommonUtil.isNegativeInfinity(sValue)) dLb = Double.NEGATIVE_INFINITY;
					else dLb = Double.parseDouble(sValue);
				}
				else if (sLocalName.equals("ub")){
					if(CommonUtil.isPostiveInfinity(sValue)) dUb = Double.POSITIVE_INFINITY;
					else if(CommonUtil.isNegativeInfinity(sValue)) dUb = Double.NEGATIVE_INFINITY;
					else dUb = Double.parseDouble(sValue);
				}
				else if (sLocalName.equals("mult")){
					iMult = Integer.parseInt(sValue);
				}
			}
			for (j = 0; j < iMult; j++){
				m_msVarName[iVarIndex] = sName;
				m_mdInit[iVarIndex] = dInit;
				m_msInit[iVarIndex] = sInit;
				m_mcVarType[iVarIndex] = cType;
				m_mdLb[iVarIndex] = dLb;
				m_mdUb[iVarIndex] = dUb;
				iVarIndex++;
				if(iVarIndex > iVariableCount){
					m_sLogicError += "<variables>: number of variables inconsistent with declaration.\n";
					break;
				}
			}
		}
		if(iVarIndex != iVariableCount) m_sLogicError += "<variables>: number of variables inconsistent with declaration.\n";
		boolean bSetToNull = true;
		for(i = 0; i <iVariableCount; i++){
			if(m_msVarName[i].length() > 0){
				bSetToNull = false;
				break;
			}
		}
		if(bSetToNull) m_msVarName = null;

		bSetToNull = true;
		for(i = 0; i <iVariableCount; i++){
			if(!Double.isNaN(m_mdInit[i])){
				bSetToNull = false;
				break;
			}
		}
		if(bSetToNull) m_mdInit = null;

		bSetToNull = true;
		for(i = 0; i <iVariableCount; i++){
			if(m_msInit[i].length() > 0){
				bSetToNull = false;
				break;
			}
		}
		if(bSetToNull) m_msInit = null;

		/*
		bSetToNull = true;
		for(i = 0; i <iVariableCount; i++){
			if(m_mcVarType[i] != 'C'){
				bSetToNull = false;
				break;
			}
		}
		if(bSetToNull) m_mcVarType = null;
		
		bSetToNull = true;
		for(i = 0; i <iVariableCount; i++){
			if(m_mdLb[i] != 0){
				bSetToNull = false;
				break;
			}
		}
		if(bSetToNull) m_mdLb = null;

		bSetToNull = true;
		for(i = 0; i <iVariableCount; i++){
			if(!Double.isInfinite(m_mdUb[i])){
				bSetToNull = false;
				break;
			}
		}
		if(bSetToNull) m_mdUb = null;
		*/
		
		
		m_bProcessVariables = true;
		return true;
	}//processVariables
	
	/**
	 * Get the values of all variable names in the OSiL instance.
	 *
	 * </p>
	 *
	 * @return a String array of variable names in the OSiL instance.
	 */
	public String[] getVariableNames(){
		processVariables();
		return m_msVarName;
	}//getVariableNames
	
	/**
	 * Get the values of all variable initial double values in the OSiL instance.
	 *
	 * </p>
	 *
	 * @return a double array of variable initial values in the OSiL instance.
	 */
	public double[] getVariableInitialValues(){
		processVariables();
		return m_mdInit;
	}//getVariableInitialValues
	
	/**
	 * Get the values of all variable initial string values in the OSiL instance.
	 *
	 * </p>
	 *
	 * @return a String array of variable initial values in the OSiL instance.
	 */
	public String[] getVariableInitialStringValues(){
		processVariables();
		return m_msInit;
	}//getVariableInitialStringValues


	/**
	 * Get the types of all the variables, (e.g. 'C' for continuous
	 * type, 'I' for integer type, 'B' for binary type and 'S' for string type).
	 *
	 * </p>
	 *
	 * @return a Character vector of variable types in the OSiL instance.
	 */
	public char[] getVariableTypes(){
		processVariables();
		return m_mcVarType;
	}//getVariableTypes
	
	/**
	 * Get the values of all variable lower bounds in the OSiL instance.
	 *
	 * </p>
	 *
	 * @return a double array of variable lower bounds in the OSiL instance.
	 */
	public double[] getVariableLowerBounds(){
		processVariables();
		return m_mdLb;
	}//getVariableLowerBounds
	
	/**
	 * Get the values of all variable upper bounds in the OSiL instance.
	 *
	 * </p>
	 *
	 * @return a double array of variable upper bounds in the OSiL instance.
	 */
	public double[] getVariableUpperBounds(){
		processVariables();
		return m_mdUb;
	}//getVariableUpperBounds
	
	/**
	 * Process &lt;objectives&gt; element in the OSiL instance and retrive information from all its
	 * &lt;obj&gt; child elements. Information retrieved includes name, maxOrMin, constant, weight and coef of each objective.
	 *
	 * </p>
	 *
	 * @return whether the &lt;objectives&gt; element has been processed.
	 */
	protected boolean processObjectives(){
		if(m_bProcessObjectives){
			return true;
		}
		Element eInstanceData = (Element)XMLUtil.findChildNode(m_eRoot, "instanceData");
		Element eObjectives = (Element)XMLUtil.findChildNode(eInstanceData, "objectives");
		if(eObjectives == null) return true;
		Vector<Element> vElements = XMLUtil.getChildElementsByTagName(eObjectives, "obj");
		int iObjChildren = vElements==null?0:vElements.size();
		int iObjectiveCount = getObjectiveNumber();
		int iObjIndex = 0;
		m_msObjName = new String[iObjectiveCount];
		m_msMaxOrMin = new String[iObjectiveCount];
		m_miObjNonzeroCoefNumber = new int[iObjectiveCount];
		m_mdObjConstant = new double[iObjectiveCount];
		m_mdObjWeight = new double[iObjectiveCount];
		m_mmdObjNonzeroCoefValue = new double[iObjectiveCount][];
		m_mmiObjNonzeroCoefIndex = new int[iObjectiveCount][];
		m_mObjectiveCoefficients = new SparseVector[iObjectiveCount];
		Element eObj = null;
		int i, j;
		for(i = 0; i < iObjChildren; i++){
			eObj = (Element)(vElements.elementAt(i));
			NamedNodeMap attributes =  eObj.getAttributes();
			int n =attributes.getLength();
			String sName = "";
			String sMaxOrMin = "min";
			int iCoefNumber = 0;
			double dConstant = 0.0;
			double dWeight = 1.0;
			int iMult = 1;
			for (j = 0; j < n; j++){
				Node attr = attributes.item(j);
				String sAttributeName = attr.getNodeName();
				String sAttributeValue = attr.getNodeValue();
				if (sAttributeName.equals("name")){
					sName = sAttributeValue;
				}
				else if (sAttributeName.equals("maxOrMin")){
					sMaxOrMin = sAttributeValue;
				}
				else if (sAttributeName.equals("numberOfObjCoef")){
					iCoefNumber = Integer.parseInt(sAttributeValue);
				}
				else if (sAttributeName.equals("constant")){
					dConstant = Double.parseDouble(sAttributeValue);
				}
				else if (sAttributeName.equals("weight")){
					dWeight = Double.parseDouble(sAttributeValue);
				}
				else if (sAttributeName.equals("mult")){
					iMult = Integer.parseInt(sAttributeValue);
				}
			}
			for (j = 0; j < iMult; j++) {
				m_msObjName[iObjIndex] = sName; 
				m_msMaxOrMin[iObjIndex] = sMaxOrMin;
				m_miObjNonzeroCoefNumber[iObjIndex] = iCoefNumber;
				m_mdObjConstant[iObjIndex] = dConstant;
				m_mdObjWeight[iObjIndex] = dWeight;
				NodeList coefNodeList = eObj.getElementsByTagName("coef");
				int iCoefChildren = coefNodeList.getLength();
				if(iCoefChildren != iCoefNumber) m_sLogicError += "<objectives>: number of objective coefficient nodes inconsistent with declaration.\n";				
				m_mmdObjNonzeroCoefValue[iObjIndex] = new double[iCoefChildren];
				m_mmiObjNonzeroCoefIndex[iObjIndex] = new int[iCoefChildren];
				m_mObjectiveCoefficients[iObjIndex] = new SparseVector();
				Element eCoef = null;
				for(int k = 0; k < iCoefChildren; k++){
					eCoef = (Element)(coefNodeList.item(k));
					m_mmdObjNonzeroCoefValue[iObjIndex][k] =Double.parseDouble(XMLUtil.getElementValue(eCoef));
					m_mmiObjNonzeroCoefIndex[iObjIndex][k] =Integer.parseInt(eCoef.getAttribute("idx"));
					if(m_mmiObjNonzeroCoefIndex[iObjIndex][k] < 0 || m_mmiObjNonzeroCoefIndex[iObjIndex][k] >= getVariableNumber()) m_sLogicError += "<objectives>: variable indexes of objective coefficients invalid.\n";
				}
				m_mObjectiveCoefficients[iObjIndex].indexes = m_mmiObjNonzeroCoefIndex[iObjIndex];
				m_mObjectiveCoefficients[iObjIndex].values = m_mmdObjNonzeroCoefValue[iObjIndex];
				iObjIndex++;
				if(iObjIndex > getObjectiveNumber()) m_sLogicError += "<objectives>: number of objectives inconsistent with declaration.\n";
			}
		}
		if(iObjIndex != iObjectiveCount) m_sLogicError += "<objectives>: number of objectives inconsistent with declaration.\n";
		
		
		boolean bSetToNull = true;
		for(i = 0; i <iObjectiveCount; i++){
			if(m_msObjName[i].length() > 0){
				bSetToNull = false;
				break;
			}
		}
		if(bSetToNull) m_msObjName = null;

		/*
		bSetToNull = true;
		for(i = 0; i <iObjectiveCount; i++){
			if(m_mdObjConstant[i] != 0){
				bSetToNull = false;
				break;
			}
		}
		if(bSetToNull) m_mdObjConstant = null;
		
		bSetToNull = true;
		for(i = 0; i <iObjectiveCount; i++){
			if(m_mdObjWeight[i] != 1){
				bSetToNull = false;
				break;
			}
		}
		if(bSetToNull) m_mdObjWeight = null;
				
		bSetToNull = true;
		for(i = 0; i <iObjectiveCount; i++){
			if(m_mmdObjNonzeroCoefValue[i] != null && m_mmdObjNonzeroCoefValue[i].length > 0){
				bSetToNull = false;
				break;
			}
		}
		if(bSetToNull){ 
			m_mmdObjNonzeroCoefValue = null;
			m_mmdObjNonzeroCoefValue = null;
		}
		*/
		
		m_bProcessObjectives = true;
		return true;
	}//processObjectives
	
	/**
	 * Get the name of the first objective function in the OSiL instance.
	 *
	 * </p>
	 *
	 * @return the first objective name of the OSiL instance, null string if none.
	 */
	public String getFirstObjectiveName(){
		processObjectives();
		if(getObjectiveNumber() > 0) return m_msObjName[0];
		else return null;
	}//getFirstObjectiveName
	
	/**
	 * Get a string array of all the objective function names in the OSiL instance.
	 *
	 * </p>
	 *
	 * @return a string array of all the objective function names, null if none.
	 */
	public String[] getObjectiveNames(){
		processObjectives();
		if(getObjectiveNumber() > 0) return m_msObjName;
		else return null;
	}//getObjectiveNames

	/**
	 * Get the maxOrMin (direction or sense) of the first objective function in the OSiL instance.
	 *
	 * </p>
	 *
	 * @return the first objective maxOrMin of the OSiL instance, null string if none.
	 */
	public String getFirstObjectiveMaxOrMin(){
		processObjectives();
		if(getObjectiveNumber() > 0) return m_msMaxOrMin[0];
		else return null;
	}//getFirstObjectiveMaxOrMin
	
	/**
	 * Get a string array of all the objective function maxOrMins (directions or senses) in the OSiL instance.
	 *
	 * </p>
	 *
	 * @return a string array of all the objective function maxOrMins, null if none.
	 */
	public String[] getObjectiveMaxOrMins(){
		processObjectives();
		if(getObjectiveNumber() > 0) return m_msMaxOrMin;
		else return null;
	}//getObjectiveMaxOrMins
	
	/**
	 * Get the constant of the first objective function in the OSiL instance.
	 *
	 * </p>
	 *
	 * @return the first objective constant of the OSiL instance, 0 if none. 
	 */
	public double getFirstObjectiveConstant(){
		processObjectives();
		if(getObjectiveNumber() > 0) return m_mdObjConstant[0];
		else return 0;
	}//getFirstObjectiveConstant
	
	/**
	 * Get a double array of all the objective function constants in the OSiL instance.
	 *
	 * </p>
	 *
	 * @return a double array of all the objective function constants, null if none.
	 */
	public double[] getObjectiveConstants(){
		processObjectives();
		if(getObjectiveNumber() > 0) return m_mdObjConstant;
		else return null;
	}//getObjectiveConstants

	/**
	 * Get the weight of the first objective function in the OSiL instance.
	 *
	 * </p>
	 *
	 * @return the first objective function weight of the OSiL instance, 0 if none. 
	 */
	public double getFirstObjectiveWeight(){
		processObjectives();
		if(getObjectiveNumber() > 0) return m_mdObjWeight[0];
		else return 0;
	}//getFirstObjectiveWeight
	
	/**
	 * Get a double array of all the objective function weights in the OSiL instance.
	 *
	 * </p>
	 *
	 * @return a double array of all the objective function weights, null if none.
	 */
	public double[] getObjectiveWeights(){
		processObjectives();
		if(getObjectiveNumber() > 0) return m_mdObjWeight;
		else return null;
	}//getObjectiveWeights
	
	/**
	 * Get the nonzero coefficient values of the first objective function in the OSiL instance.
	 *
	 * </p>
	 *
	 * @return the nonzero coefficient values of the first objective function in the OSiL instance, null if none. 
	 */
	public double[] getFirstDenseObjectiveCoefficientValues(){
		processObjectives();
		if(getObjectiveNumber() > 0) {
			if(m_mmdObjDenseCoefValue == null){
				int iObjectiveCount = getObjectiveNumber();
				int iVariableCount = getVariableNumber();
				m_mmdObjDenseCoefValue = new double[iObjectiveCount][iVariableCount];	
				for(int i = 0; i < iObjectiveCount; i++){
					for(int j = 0; j < ((m_mmiObjNonzeroCoefIndex[i]==null)?0:m_mmiObjNonzeroCoefIndex[i].length); j++){
						m_mmdObjDenseCoefValue[i][m_mmiObjNonzeroCoefIndex[i][j]]= m_mmdObjNonzeroCoefValue[i][j];
					}
				}
			}
			return m_mmdObjDenseCoefValue[0];			
		}
		else return null;
	}//getFirstDenseObjectiveCoefficientValues
	
	/**
	 * Get the nonzero coefficient values of the first objective function in the OSiL instance.
	 *
	 * </p>
	 *
	 * @return the nonzero coefficient values of the first objective function in the OSiL instance, null if none. 
	 */
	public double[][] getDenseObjectiveCoefficients(){
		processObjectives();
		if(getObjectiveNumber() > 0) {
			if(m_mmdObjDenseCoefValue == null){
				int iObjectiveCount = getObjectiveNumber();
				int iVariableCount = getVariableNumber();
				m_mmdObjDenseCoefValue = new double[iObjectiveCount][iVariableCount];	
				for(int i = 0; i < iObjectiveCount; i++){
					for(int j = 0; j < ((m_mmiObjNonzeroCoefIndex[i]==null)?0:m_mmiObjNonzeroCoefIndex[i].length); j++){
						m_mmdObjDenseCoefValue[i][m_mmiObjNonzeroCoefIndex[i][j]]= m_mmdObjNonzeroCoefValue[i][j];
					}
				}
			}
			return m_mmdObjDenseCoefValue;			
		}
		else return null;
	}//getDenseObjectiveCoefficients
	
	/**
	 * Get the number of nonzero coefficient values of the first objective function in the OSiL instance.
	 *
	 * </p>
	 *
	 * @return the number of nonzero coefficient values of the first objective function in the OSiL instance, -1
	 * if no objective functions. 
	 */
	public int getFirstObjectiveCoefficientNumber(){
		processObjectives();
		if(getObjectiveNumber() > 0) return m_miObjNonzeroCoefNumber[0];
		else return -1;
	}//getFirstObjectiveNonzeroCoefficientValues
	
	/**
	 * Get the numbers of nonzero coefficient values of all the objective functions in the OSiL instance.
	 *
	 * </p>
	 *
	 * @return an integer arrays of the numbers of nonzero coefficient values of all the 
	 * objective functions in the OSiL instance, null if no objective functions.  
	 */
	public int[] getObjectiveCoefficientNumbers(){
		processObjectives();
		if(getObjectiveNumber() > 0) return m_miObjNonzeroCoefNumber;
		else return null;
	}//getObjectiveCoefficientNumbers

	
	/**
	 * Get the nonzero coefficient values of the first objective function in the OSiL instance.
	 *
	 * </p>
	 *
	 * @return the nonzero coefficient values of the first objective function in the OSiL instance, null if none. 
	 */
	public double[] getFirstObjectiveNonzeroCoefficientValues(){
		processObjectives();
		if(getObjectiveNumber() > 0) return m_mmdObjNonzeroCoefValue[0];
		else return null;
	}//getFirstObjectiveNonzeroCoefficientValues
	
	/**
	 * Get the nonzero coefficient values of all the objective functions in the OSiL instance.
	 *
	 * </p>
	 *
	 * @return an array of double arrays; each double array holds the nonzero coefficient values of an objective function, null if none. 
	 */
	public double[][] getObjectiveNonzeroCoefficientValues(){
		processObjectives();
		if(getObjectiveNumber() > 0) return m_mmdObjNonzeroCoefValue;
		else return null;
	}//getObjectiveNonzeroCoefficientValues
	
	/**
	 * Get the nonzero coefficient indexes of the first objective function in the OSiL instance.
	 *
	 * </p>
	 *
	 * @return the nonzero coefficient indexes of the first objective function in the OSiL instance, null if none. 
	 */
	public int[] getFirstObjectiveNonzeroCoefficientIndexes(){
		processObjectives();
		if(getObjectiveNumber() > 0) return m_mmiObjNonzeroCoefIndex[0];
		else return null;
	}//getFirstObjectiveNonzeroCoefficientIndexes
	
	/**
	 * Get the nonzero coefficient indexes of all the objective functions in the OSiL instance.
	 *
	 * </p>
	 *
	 * @return an array of integer arrays; each integer array holds the variable indexes 
	 * of the nonzero coefficient values of an objective function, null if none. 
	 */
	public int[][] getObjectiveNonzeroCoefficientIndexes(){
		processObjectives();
		if(getObjectiveNumber() > 0) return m_mmiObjNonzeroCoefIndex;
		else return null;
	}//getObjectiveNonzeroCoefficientIndexes
	
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
	 */
	public SparseVector[] getObjectiveCoefficients() throws Exception{
		processObjectives();
		if(getObjectiveNumber() > 0){
			return m_mObjectiveCoefficients;
		}
		else{
			return null;
		}
	}//getObjectiveCoefficients
	
	/**
	 * Process &lt;constraints&gt; element in the OSiL instance and retrive information from all its
	 * &lt;constraints&gt; elements. Information retrieved includes name, ub and lb of each constraint.
	 *
	 * </p>
	 *
	 * @return whether the &lt;constraints&gt; element has been processed.
	 */
	protected boolean processConstraints(){
		if(m_bProcessConstraints){
			return true;
		}
		Element eInstanceData = (Element)XMLUtil.findChildNode(m_eRoot, "instanceData");
		Element eConstraints = (Element)XMLUtil.findChildNode(eInstanceData, "constraints");
		if(eConstraints == null) return true;
		NodeList nodeList = eConstraints.getElementsByTagName("con");
		int iConChildren = nodeList.getLength();
		int iConstraintCount = getConstraintNumber();
		int iConIndex = 0;
		m_msConName = new String[iConstraintCount];
		m_mdConstraintConstant = new double[iConstraintCount];
		m_mcConstraintTypes = new char[iConstraintCount];
		m_mdLhs = new double[iConstraintCount];
		m_mdRhs = new double[iConstraintCount];
		Element eCon = null;
		int i, j;
		for(i = 0; i < iConChildren; i++){
			eCon = (Element)(nodeList.item(i));
			NamedNodeMap attributes =  eCon.getAttributes();
			int n =attributes.getLength();
			String sName = "";
			double dLhs = Double.NEGATIVE_INFINITY;
			double dRhs = Double.POSITIVE_INFINITY;
			double dConstant = 0.0;
			int iMult = 1;
			for (j = 0; j < n; j++){
				Node attr = attributes.item(j);
				String sAttributeName = attr.getNodeName();
				String sAttributeValue = attr.getNodeValue();
				if (sAttributeName.equals("name")){
					sName = sAttributeValue;
				}
				else if (sAttributeName.equals("lb")){
					if(CommonUtil.isPostiveInfinity(sAttributeValue)) dLhs = Double.POSITIVE_INFINITY;
					else if(CommonUtil.isNegativeInfinity(sAttributeValue)) dLhs = Double.NEGATIVE_INFINITY;
					else dLhs = Double.parseDouble(sAttributeValue);
				}
				else if (sAttributeName.equals("ub")){
					if(CommonUtil.isPostiveInfinity(sAttributeValue)) dRhs = Double.POSITIVE_INFINITY;
					else if(CommonUtil.isNegativeInfinity(sAttributeValue)) dRhs = Double.NEGATIVE_INFINITY;
					else dRhs = Double.parseDouble(sAttributeValue);
				}
				else if (sAttributeName.equals("constant")){
					dConstant = Double.parseDouble(sAttributeValue);
				}
				else if (sAttributeName.equals("mult")){
					iMult = Integer.parseInt(sAttributeValue);
				}
			}
			for (j = 0; j < iMult; j++) {
				m_msConName[iConIndex] = sName;
				m_mdLhs[iConIndex] = dLhs;
				m_mdRhs[iConIndex] = dRhs;
				m_mdConstraintConstant[iConIndex] = dConstant;
				if(m_mdLhs[iConIndex] == Double.POSITIVE_INFINITY || m_mdRhs[iConIndex] == Double.NEGATIVE_INFINITY) 
					m_sLogicError += ("<constraints>: constraint " + iConIndex + "infeasible");
				else if(m_mdLhs[iConIndex] > m_mdRhs[iConIndex]) 
					m_sLogicError += ("<constraints>: constraint " + iConIndex + "infeasible");
				else if(m_mdLhs[iConIndex] == Double.NEGATIVE_INFINITY && m_mdRhs[iConIndex] == Double.POSITIVE_INFINITY)
					m_mcConstraintTypes[iConIndex] = 'U';
				else if(m_mdLhs[iConIndex] == m_mdRhs[iConIndex]) 
					m_mcConstraintTypes[iConIndex] = 'E';
				else if(m_mdLhs[iConIndex] == Double.NEGATIVE_INFINITY)
					m_mcConstraintTypes[iConIndex] = 'L';
				else if(m_mdRhs[iConIndex] == Double.POSITIVE_INFINITY)
					m_mcConstraintTypes[iConIndex] = 'G';
				else m_mcConstraintTypes[iConIndex] = 'R';
				
				iConIndex++;
				if(iConIndex > getConstraintNumber()) m_sLogicError += "<constraints>: number of constraints inconsistent with declaration.\n";
			}
		}
		if(iConIndex != getConstraintNumber()) m_sLogicError += "<constraints>: number of constraints inconsistent with declaration.\n";
	
		boolean bSetToNull = true;


		for(i = 0; i <iConstraintCount; i++){
			if(m_msConName[i].length() > 0){
				bSetToNull = false;
				break;
			}
		}
		if(bSetToNull) m_msConName = null;

		/*
		bSetToNull = true;
		for(i = 0; i <iConstraintCount; i++){
			if(!Double.isInfinite(m_mdLhs[i])){
				bSetToNull = false;
				break;
			}
		}
		if(bSetToNull) m_mdLhs = null;

		bSetToNull = true;
		for(i = 0; i <iConstraintCount; i++){
			if(!Double.isInfinite(m_mdRhs[i])){
				bSetToNull = false;
				break;
			}
		}
		if(bSetToNull) m_mdRhs = null;
		*/
		
		m_bProcessConstraints = true;
		return true;
	}//processConstraints
	
	/**
	 * Get the values of all constraint names in the OSiL instance.
	 *
	 * </p>
	 *
	 * @return a String array of constraint names in the OSiL instance.
	 */
	public String[] getConstraintNames(){
		processConstraints();
		return m_msConName;
	}//getConstraintNames
	
	/**
	 * Get the values of all constraint lower bounds (or left hand sides) in the OSiL instance.
	 *
	 * </p>
	 *
	 * @return a double array of constraint lower bound values in the OSiL instance.
	 */
	public double[] getConstraintLowerBounds(){
		processConstraints();
		return m_mdLhs;
	}//getConstraintLowerBounds
	
	/**
	 * Get the values of all constraint upper bounds (or right hand sides) in the OSiL instance.
	 *
	 * </p>
	 *
	 * @return a double array of constraint upper bound values in the OSiL instance.
	 */
	public double[] getConstraintUpperBounds(){
		processConstraints();
		return m_mdRhs;
	}//getConstraintUpperBounds
	
	/**
	 * Get the values of all constraint constants in the OSiL instance.
	 *
	 * </p>
	 *
	 * @return a double array of constraint constants in the OSiL instance.
	 */
	public double[] getConstraintConstants(){
		processConstraints();
		return m_mdConstraintConstant;
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
	 * @return a char array of constraint types, null if constraints.
	 * @throws Exception if the elements in constraints are logically inconsistent. 
	 */
	public char[] getConstraintTypes() throws Exception{
		processConstraints();
		return m_mcConstraintTypes;
		
	}//getConstraintTypes
	/**
	 * Get the linear Constraint coefficient given row and column numbers.
	 *
	 * </p>
	 *
	 * @param rowIdx holds the row number to which the linear function belongs.
	 * @param colIdx holds the column number or the variable index.
	 * @return the linear function value in the specified constraint (row) given the current variable values.
	 */
	public double getLinearConstraintCoefficient(int rowIdx, int colIdx){
		if(rowIdx < 0 || colIdx < 0) return 0;
		double dValue = 0;
		getLinearConstraintCoefficientMatrixNonzeroValues();
		getLinearConstraintCoefficientMatrixNonzeroIndexes();
		getLinearConstraintCoefficientMatrixStartIndexes();
		
		int iRow = 0;
		int iCol = 0;
		for(int i = 0; i < ((m_miStartCoefMatrix==null)?0:m_miStartCoefMatrix.length-1); i++){
			if(getLinearConstraintCoefficientMajor()) iCol = i;
			else iRow = i;
			for(int j = m_miStartCoefMatrix[i]; j < m_miStartCoefMatrix[i+1]; j++){
				if(getLinearConstraintCoefficientMajor())iRow = m_miIdxCoefMatrix[j];
				else iCol = m_miIdxCoefMatrix[j];
				if(iRow == rowIdx && iCol == colIdx){
					dValue = m_mdValueCoefMatrix[j];
					return dValue;
				}
				
			}
		}
		return 0;
	}//getLinearConstraintCoefficient
	
	
	/**
	 * Get the values of the elements &lt;start&gt; in coefMatrix,
	 * which points to the start of a column (row) of nonzero elements in linearConstraintCoefficients.
	 *
	 * </p>
	 *
	 * @return an Integer array of the the values of the elements &lt;start&gt; in coefMatrix.
	 */
	public int[] getLinearConstraintCoefficientMatrixStartIndexes(){
		if(m_miStartCoefMatrix == null){
			Element eInstanceData = (Element)XMLUtil.findChildNode(m_eRoot, "instanceData");
			Element eCoefMatrix = (Element)XMLUtil.findChildNode(eInstanceData, "linearConstraintCoefficients");
			if(eCoefMatrix == null) return null;
			Element eStart = (Element)XMLUtil.findChildNode(eCoefMatrix, "start");
			NodeList nodeList = eStart.getElementsByTagName("el");
			int iEl = nodeList.getLength();
			int iSize = 0;
			if(getLinearConstraintCoefficientMajor()){
				iSize = getVariableNumber()+1;
				m_miStartCoefMatrix = new int[iSize];
			}
			else{
				iSize = getConstraintNumber()+1;
				m_miStartCoefMatrix = new int[iSize];				
			}
			int iMult = 1;
			int iInc = 0;
			Element eEl = null;		
			int k = 0;
			for(int i = 0; i < iEl; i++){
				eEl = (Element)(nodeList.item(i));				
				int iValue = Integer.parseInt(((Text)eEl.getFirstChild()).getData());
				NamedNodeMap attributes =  eEl.getAttributes();
				int n =attributes.getLength();
				for (int j = 0; j < n; j++) {
					String sLocalName = attributes.item(j).getLocalName();
					String sValue = attributes.item(j).getNodeValue();
					if (sLocalName.equals("mult")) {
						iMult = Integer.parseInt(sValue);
					}
					else if (sLocalName.equals("incr")) {
						iInc = Integer.parseInt(sValue);
					}
				}
				for (int j = 0; j < iMult; j++) {
					m_miStartCoefMatrix[k] =  iValue + iInc * j;
					k++;
				}
				iMult = 1;
				iInc = 0;
			}
		}
		return m_miStartCoefMatrix;
	}//getLinearConstraintCoefficientMatrixStartIndexes
	
	/**
	 * Get the values of the vector element value in coefMatrix,
	 * which contains nonzero elements.
	 *
	 * </p>
	 *
	 * @return a double array of the the values of the elements &lt;value&gt; in coefMatrix.
	 */
	public double[] getLinearConstraintCoefficientMatrixNonzeroValues(){
		if(m_mdValueCoefMatrix == null){
			Element eInstanceData = (Element)XMLUtil.findChildNode(m_eRoot, "instanceData");
			Element eCoefMatrix = (Element)XMLUtil.findChildNode(eInstanceData, "linearConstraintCoefficients");
			if(eCoefMatrix == null) return null;
			Element eValue = (Element)XMLUtil.findChildNode(eCoefMatrix, "value");
			NodeList nodeList = eValue.getElementsByTagName("el");
			int iEl = nodeList.getLength();
			int iSize = getLinearConstraintCoefficientNumber();
			if(iSize > getConstraintNumber()*getVariableNumber()) m_sLogicError += "<linearConstraintCoefficients>: A Matrix not valid.\n";
			m_mdValueCoefMatrix = new double[iSize];
			int iMult = 1;
			double dInc = 0.0;
			Element eEl = null;	
			int k = 0;
			for(int i = 0; i < iEl; i++){
				eEl = (Element)(nodeList.item(i));				
				double dValue = Double.parseDouble(((Text)eEl.getFirstChild()).getData());
				NamedNodeMap attributes =  eEl.getAttributes();
				int n =attributes.getLength();
				for (int j = 0; j < n; j++) {
					String sLocalName = attributes.item(j).getLocalName();
					String sValue = attributes.item(j).getNodeValue();
					if (sLocalName.equals("mult")) {
						iMult = Integer.parseInt(sValue);
					}
					else if (sLocalName.equals("incr")) {
						dInc = Integer.parseInt(sValue);
					}
				}		
				for (int j = 0; j < iMult; j++) {
					m_mdValueCoefMatrix[k] =  dValue + dInc * j;
					k++;
				}
				iMult = 1;
				dInc = 0.0;
			}
		}
		return m_mdValueCoefMatrix;
	}//getLinearConstraintCoefficientMatrixNonzeroValues
	
	/**
	 * Get the the values of the vector element rowIdx or colIdx in coefMatrix.
	 * If the matrix is stored by column (row), rowIdx (colIdx) is the vector of
	 * row (column) indices.
	 *
	 * </p>
	 *
	 * @return an integer array of the the values of the elements &lt;rowIdx&gt; or &lt;colIdx&gt; in coefMatrix.
	 */
	public int[] getLinearConstraintCoefficientMatrixNonzeroIndexes(){		
		if(m_miIdxCoefMatrix == null){
			Element eInstanceData = (Element)XMLUtil.findChildNode(m_eRoot, "instanceData");
			Element eCoefMatrix = (Element)XMLUtil.findChildNode(eInstanceData, "linearConstraintCoefficients");
			if(eCoefMatrix == null) return null;
			Element eIdx = (Element)XMLUtil.findChildNode(eCoefMatrix, "rowIdx");
			if(eIdx == null){
				eIdx = (Element)XMLUtil.findChildNode(eCoefMatrix, "colIdx");
			}
			NodeList nodeList = eIdx.getElementsByTagName("el");
			int iEl = nodeList.getLength();
			int iSize = getLinearConstraintCoefficientNumber();
			if(iSize > getConstraintNumber()*getVariableNumber()) m_sLogicError += "<linearConstraintCoefficients>: A Matrix not valid.\n";
			m_miIdxCoefMatrix = new int[iSize];
			int iMult = 1;
			int iInc = 0;
			Element eEl = null;	
			int k = 0;
			for(int i = 0; i < iEl; i++){
				eEl = (Element)(nodeList.item(i));				
				int iValue = Integer.parseInt(((Text)eEl.getFirstChild()).getData());
				NamedNodeMap attributes =  eEl.getAttributes();
				int n =attributes.getLength();
				for (int j = 0; j < n; j++) {
					String sLocalName = attributes.item(j).getLocalName();
					String sValue = attributes.item(j).getNodeValue();
					if (sLocalName.equals("mult")) {
						iMult = Integer.parseInt(sValue);
					}
					else if (sLocalName.equals("incr")) {
						iInc = Integer.parseInt(sValue);
					}
				}		
				for (int j = 0; j < iMult; j++) {
					m_miIdxCoefMatrix[k] =  iValue + iInc * j;
					k++;
				}
				iMult = 1;
				iInc = 0;
			}
		}
		return m_miIdxCoefMatrix;
	}//getLinearConstraintCoefficientMatrixNonzeroIndexes
	
	/**
	 * Gets whether the coefMatrix (AMatrix) holding linear program
	 * data is stored by column. If false, the matrix is stored by row.
	 *
	 * </p>
	 *
	 * @return whether the coefMatrix (AMatrix) holding linear program data is stored
	 * by column. If false, the matrix is stored by row.
	 */
	public boolean getLinearConstraintCoefficientMajor(){
		if(m_bCheckColumnMajor){
			return m_bColumnMajorInCoefMatrix;
		}
		else{
			Element eInstanceData = (Element)XMLUtil.findChildNode(m_eRoot, "instanceData");
			Element eCoefMatrix = (Element)XMLUtil.findChildNode(eInstanceData, "linearConstraintCoefficients");
			Element eIdx = (Element)XMLUtil.findChildNode(eCoefMatrix, "rowIdx");
			if(eIdx == null){
				m_bColumnMajorInCoefMatrix = false;
			}
			else{
				m_bColumnMajorInCoefMatrix = true;
			}
			m_bCheckColumnMajor = true;
		}
		return m_bColumnMajorInCoefMatrix;
	}//getLinearConstraintCoefficientMajor
	
	/**
	 * Construct and get the nonsparse A matrix from the linearConstraintCoefficients.
	 *
	 * </p>
	 *
	 * @return a 2-dim array of doubles that represents the nonsparse A Matrix.
	 */
	public double[][] getDenseLinearConstraintCoefficientMatrix(){
		getLinearConstraintCoefficientMatrixNonzeroValues();
		getLinearConstraintCoefficientMatrixNonzeroIndexes();
		getLinearConstraintCoefficientMatrixStartIndexes();
		
		double[][] mmdA = new double[getConstraintNumber()][getVariableNumber()];
		
		int iRow = 0;
		int iCol = 0;
		for(int i = 0; i < ((m_miStartCoefMatrix==null)?0:m_miStartCoefMatrix.length-1); i++){
			if(getLinearConstraintCoefficientMajor()) iCol = i;
			else iRow = i;
			for(int j = m_miStartCoefMatrix[i]; j < m_miStartCoefMatrix[i+1]; j++){
				if(getLinearConstraintCoefficientMajor())iRow = m_miIdxCoefMatrix[j];
				else iCol = m_miIdxCoefMatrix[j];
				mmdA[iRow][iCol] = m_mdValueCoefMatrix[j];
			}
		}
		return mmdA;
	}//getLinearConstraintCoefficientMatrixNonzeroIndexes
	
	/**
	 * Get all the quadratic terms in quadratic coefficients. 
	 * 
	 * @return the QuadraticTerms data structure for all quadratic terms in the quadratic coefficients, null if none.  
	 * The QuadraticTerms contains four arrays: rowIndexes, varOneIndexes, varTwoIndexes, coefficients
	 * @see org.optimizationservices.oscommon.datastructure.osgeneral.QuadraticTerms
	 */
	public QuadraticTerms getQuadraticTerms(){
		int i;
		if(m_quadraticTerms == null){
			Element eInstanceData = (Element)XMLUtil.findChildNode(m_eRoot, "instanceData");
			Element eQuadCoef = (Element)XMLUtil.findChildNode(eInstanceData, "quadraticCoefficients");
			if(eQuadCoef == null) return null;
			NodeList nodeList = eQuadCoef.getElementsByTagName("qTerm");
			int iEl = nodeList.getLength();
			int iSize = getQuadraticTermNumber();
			if(iSize != iEl) m_sLogicError += "<quadraticCoefficients>: number of QuadraticTerms inconsistent with QuadraticTerm array size.\n";
			m_quadraticTerms = new QuadraticTerms();
			m_quadraticTerms.coefficients = new double[iSize];
			for(i = 0; i < iEl; i++) m_quadraticTerms.coefficients[i] = 1.0;
			m_quadraticTerms.rowIndexes = new int[iSize];
			m_quadraticTerms.varOneIndexes = new int[iSize];
			m_quadraticTerms.varTwoIndexes = new int[iSize];
			Element eEl = null;	
			String sRow = "";
			for(i = 0; i < iEl; i++){
				eEl = (Element)(nodeList.item(i));				
				NamedNodeMap attributes =  eEl.getAttributes();
				int n =attributes.getLength();
				for (int j = 0; j < n; j++) {
					String sLocalName = attributes.item(j).getLocalName();
					String sValue = attributes.item(j).getNodeValue();
					if (sLocalName.equals("idx")) {
						sRow = sValue;
						m_quadraticTerms.rowIndexes[i] = Integer.parseInt(sValue);
					}
					if (sLocalName.equals("idxOne")) {
						m_quadraticTerms.varOneIndexes[i] = Integer.parseInt(sValue);
					}
					if (sLocalName.equals("idxTwo")) {
						m_quadraticTerms.varTwoIndexes[i] = Integer.parseInt(sValue);
					}
					if (sLocalName.equals("coef")) {
						m_quadraticTerms.coefficients[i] = Double.parseDouble(sValue);
					}
				}
				Vector<QuadraticTerm> vQTerms = m_quadraticTermMap.get(sRow);
				if(vQTerms == null){
					vQTerms = new Vector<QuadraticTerm>();
					m_quadraticTermMap.remove(sRow);
					m_quadraticTermMap.put(sRow, vQTerms);
				}
				QuadraticTerm quadraticTerm = new QuadraticTerm();
				quadraticTerm.coef = m_quadraticTerms.coefficients[i];
				quadraticTerm.idx = m_quadraticTerms.rowIndexes[i];
				quadraticTerm.idxOne = m_quadraticTerms.varOneIndexes[i];
				quadraticTerm.idxTwo = m_quadraticTerms.varTwoIndexes[i];				
				vQTerms.add(quadraticTerm);				
			}
		}
		return m_quadraticTerms;
	}//getQuadraticTerms

	
	/**
	 * Calculate the linear objective function value given the current variable values.
	 *
	 * </p>
	 *
	 * @param rowIdx holds the row number to which the linear function belongs. if negative, it is an objective function.
	 * @param x holds the values of the variables in a double array.
	 * @return the linear objective function value given the current variable values.
	 */
	public double calculateLinearObjectiveFunction(int rowIdx, double[] x){
		if(rowIdx >= 0) return Double.NaN;
		if(Math.abs(rowIdx) <= getObjectiveNumber()){
			double dValue = 0;
			double[] mdCoefValue = (getObjectiveNonzeroCoefficientValues())[Math.abs(rowIdx)-1];
			int[] miCoefIndex = (getObjectiveNonzeroCoefficientIndexes())[Math.abs(rowIdx)-1];
			double dObjConstant = (getObjectiveConstants())[Math.abs(rowIdx)-1];
			for(int i = 0; i < ((mdCoefValue==null)?0:mdCoefValue.length); i++){
				dValue += mdCoefValue[i]* x[miCoefIndex[i]];
			}
			dValue +=dObjConstant;
			return dValue;
		}
		return Double.NaN;
	}//calculateLinearObjectiveFunction
	
	/**
	 * Calculate the quadratic objective function value given the current variable values.
	 *
	 * </p>
	 *
	 * @param rowIdx holds the row number to which the quadratic function belongs. if negative, it is an objective function.
	 * @param x holds the values of the variables in a double array.
	 * @return the quadratic objective function value given the current variable values.
	 */
	public double calculateQuadraticObjectiveFunction(int rowIdx, double[] x){
		if(rowIdx >= 0) return Double.NaN;
		if(Math.abs(rowIdx) <= getObjectiveNumber()){
			double dValue = 0;
			getQuadraticTerms();
			if(m_quadraticTerms == null) return 0;
			int n = (m_quadraticTerms.coefficients==null)?0:m_quadraticTerms.coefficients.length;
			for(int i = 0; i < n; i++){
				if(m_quadraticTerms.rowIndexes[i] == Math.abs(rowIdx)-1){
					dValue+= m_quadraticTerms.coefficients[i] * x[m_quadraticTerms.varOneIndexes[i]] * x[m_quadraticTerms.varTwoIndexes[i]];
				}
			}
			return dValue;
		}
		return Double.NaN;
	}//calculateQuadraticObjectiveFunction
	
	/**
	 * Calculate the linear function value in a specified constraint (row) given the current variable values.
	 * If the row idx is negative, it returns a linear objective function
	 *
	 * </p>
	 *
	 * @param rowIdx holds the row number to which the linear function belongs. if negative, it is an objective function.
	 * @param x holds the values of the variables in a double array.
	 * @return the linear function value in the specified constraint (row) given the current variable values.
	 * If the row idx is negative, it returns the linear objective function
	 */
	public double calculateLinearFunction(int rowIdx, double[] x){
		if(rowIdx < 0) return calculateLinearObjectiveFunction(rowIdx, x);
		double dValue = 0;
		getLinearConstraintCoefficientMatrixNonzeroValues();
		getLinearConstraintCoefficientMatrixNonzeroIndexes();
		getLinearConstraintCoefficientMatrixStartIndexes();
		
		int iRow = 0;
		int iCol = 0;
		double dConstraintConstant = (getConstraintConstants())[rowIdx];
		for(int i = 0; i < ((m_miStartCoefMatrix==null)?0:m_miStartCoefMatrix.length-1); i++){
			if(getLinearConstraintCoefficientMajor()) iCol = i;
			else iRow = i;
			for(int j = m_miStartCoefMatrix[i]; j < m_miStartCoefMatrix[i+1]; j++){
				if(getLinearConstraintCoefficientMajor())iRow = m_miIdxCoefMatrix[j];
				else iCol = m_miIdxCoefMatrix[j];
				if(iRow == rowIdx){
					dValue += m_mdValueCoefMatrix[j] * x[iCol];
				}
			}
		}
		dValue+=dConstraintConstant;
		return dValue;
	}//calculateLinearFunction
	
	/**
	 * Calculate the quadratic function value in a specified constraint (row) given the current variable values.
	 * If the row idx is negative, it returns a quadratic objective function
	 *
	 * </p>
	 *
	 * @param rowIdx holds the row number to which the quadratic function belongs. if negative, it is an objective function.
	 * @param x holds the values of the variables in a double array.
	 * @return the quadratic function value in the specified constraint (row) given the current variable values.
	 * If the row idx is negative, it returns the quadratic objective function
	 */
	public double calculateQuadraticFunction(int rowIdx, double[] x){
		if(rowIdx < 0) return calculateLinearObjectiveFunction(rowIdx, x);
		double dValue = 0;
		getQuadraticTerms();
		if(m_quadraticTerms == null) return 0;
		int n = (m_quadraticTerms.coefficients==null)?0:m_quadraticTerms.coefficients.length;
		for(int i = 0; i < n; i++){
			if(m_quadraticTerms.rowIndexes[i] == rowIdx){
				dValue+= m_quadraticTerms.coefficients[i] * x[m_quadraticTerms.varOneIndexes[i]] * x[m_quadraticTerms.varTwoIndexes[i]];
			}
		}
		return dValue;
	}//calculateQuadraticFunction
		
	/**
	 * Calculate the all the linear constraint function values given the current variable values.
	 *
	 * </p>
	 *
	 * @param x holds the values of the variables in a double array.
	 * @return all the linear function values given the current variable values in a double array.
	 */
	public double[] calculateLinearConstraintFunctions(double[] x){
		int n = getConstraintNumber();
		double mdValue[] = new double[n];
		getLinearConstraintCoefficientMatrixNonzeroValues();
		getLinearConstraintCoefficientMatrixNonzeroIndexes();
		getLinearConstraintCoefficientMatrixStartIndexes();
		double[] mdConstraintConstant = getConstraintConstants();
		int iRow = 0;
		int iCol = 0;
		for(int i = 0; i < ((m_miStartCoefMatrix==null)?0:m_miStartCoefMatrix.length-1); i++){
			if(getLinearConstraintCoefficientMajor()) iCol = i;
			else iRow = i;
			for(int j = m_miStartCoefMatrix[i]; j < m_miStartCoefMatrix[i+1]; j++){
				if(getLinearConstraintCoefficientMajor())iRow = m_miIdxCoefMatrix[j];
				else iCol = m_miIdxCoefMatrix[j];
				mdValue[iRow] += m_mdValueCoefMatrix[j] * x[iCol];
			}
		}
		for(int i = 0; i< n; i++){
			mdValue[i] += mdConstraintConstant[i];
		}
		return mdValue;
	}//calculateLinearConstraintFunctions
	
	/**
	 * Calculate all quadratic constraint function values given the current variable values.
	 *
	 * </p>
	 *
	 * @param x holds the values of the variables in a double array.
	 * @return all quadratic constraint function values given the current variable values.
	 * If no qudratic terms, null will be returned. 
	 */
	public double[] calculateQuadraticConstraintFunctions(double[] x){
		getQuadraticTerms();
		if(m_quadraticTerms == null) return null;
		double mdValue[] = new double[getConstraintNumber()];
		int n = (m_quadraticTerms.coefficients==null)?0:m_quadraticTerms.coefficients.length;
		for(int i = 0; i < n; i++){
			mdValue[m_quadraticTerms.rowIndexes[i]] += m_quadraticTerms.coefficients[i] * x[m_quadraticTerms.varOneIndexes[i]] * x[m_quadraticTerms.varTwoIndexes[i]];
		}
		return mdValue;
	}//calculateQuadraticConstraintFunctions
	
	/**
	 *
	 * @return the information of all nonlinear nodes in a colon delimited string.
	 * The string is in a table format with the first row being the colmn title.
	 */
	public static String getNlNodeInfo(){
		return OSExpressionTree.getNlNodeInfo();
	}//getNlNodeInfo
	
	/**
	 *
	 * @return the delimiter used in the expression postfix and prefix notation strings.
	 */
	public static String getDelimiter(){
		String sDelimiter = OSExpressionTree.getDelimiter();
		return sDelimiter;
	}//getDelimiter
	
	
	/**
	 * Process &lt;nl&gt; elements in the OSiL instance, which are the nolinear extensions to the
	 * linear program data and construct nolinear expression trees
	 *
	 * </p>
	 *
	 * @return a hash map of expression trees, with the key being the rowIdx (row number)
	 * and value being the expression tree representing the nonlinear function of that constraint (row).
	 */
	public Int2ObjectOpenHashMap getNonlinearExpressions(){
		if(m_bProcessNonlinearExpressions){
			return m_expressionTrees;
		}
		Element eInstanceData = (Element)XMLUtil.findChildNode(m_eRoot, "instanceData");		
		Element eNonlinearExpressions = (Element)XMLUtil.findChildNode(eInstanceData, "nonlinearExpressions");
		if(eNonlinearExpressions == null) return m_expressionTrees;
		Vector<Element> vElements =XMLUtil.getChildElementsByTagName(eNonlinearExpressions, "nl");		
		int iNls = (vElements==null)?0:vElements.size();
		m_iNonlinearExpressionNumber = Integer.parseInt(eNonlinearExpressions.getAttribute("numberOfNonlinearExpressions"));
		if(m_iNonlinearExpressionNumber != iNls) m_sLogicError += "<nl>: number of nl nodes inconsistent with declaration ";

		IntOpenHashSet indexSet = new IntOpenHashSet();		
		for(int i = 0; i < iNls; i++){
			Element eNl = (Element)(vElements.elementAt(i));
			String sRowIdx = eNl.getAttribute("idx");
			int iRowIdx = Integer.parseInt(sRowIdx);
			if(iRowIdx >= getConstraintNumber())m_sLogicError += "<nl>: nlNode row idx larger than total constraint count.\n";
			indexSet.add(iRowIdx);
			Element eTreeRoot = null;
			for(Node child = eNl.getFirstChild(); child != null; child = child.getNextSibling()){
				if(child instanceof Element){
					eTreeRoot = (Element)child;
					break;
				}
			}
			if(eTreeRoot.getLocalName().startsWith("math")) continue;
			OSExpressionTree exTree = new OSExpressionTree(eTreeRoot, m_eRoot);
			if(m_expressionTrees.containsKey(iRowIdx)){
				((OSExpressionTree)m_expressionTrees.get(iRowIdx)).concatenate(exTree);
			}
			else{
				m_expressionTrees.put(iRowIdx, exTree);
			}
		}
		m_miNonlinearExpressionIndexes = indexSet.toIntArray();

		m_bProcessNonlinearExpressions = true;
		return m_expressionTrees;
	}//getNonlinearExpressions
	
	/**
	 * Get the nonlinear expression of a certain constraint (row). Constraint row starts with row 0. If
	 * the row idx is negative, it corresponds to an objective.
	 *
	 * </p>
	 *
	 * @param rowIdx holds the row number to which the nonlinear expression belongs. if negative, it is an objective function.
	 * @return the nnonlinear expression of a certain constraint (row). Constraint row starts with row 0. If
	 * the row idx is negative, it corresponds to an objective. If there is no nonlinear part 
	 * of a constraint (row), then a null will be returned. 
	 */
	public OSExpressionTree getNonlinearExpression(int rowIdx){
		getNonlinearExpressions();
		Object obj = m_expressionTrees.get(rowIdx);
		if(obj == null) return null;
		else return (OSExpressionTree)obj;
	}//getNonlinearExpression
	
   	/**
   	 * Get all the nonlinear expression tree indexes, i.e. indexes of rows (objetives or constraints) that contain nonlinear expressions. 
   	 * 
   	 * @return an integer array of nonlinear expression tree indexes, null if none. 
   	 */
   	public int[] getNonlinearExpressionTreeIndexes(){
   		getNonlinearExpressions();
   		return m_miNonlinearExpressionIndexes;
   	}//getNonlinearExpressionTreeIndexes

	/**
	 * Get the nonlinear function's root node (of OSnLNode type). The method is of little use due to the
	 * fact that most of the methods in the OSnLNode class are protected or protected. User should
	 * try the getNonlinearExpression(int)in this class instead.
	 *
	 * </p>
	 *
	 * @param rowIdx holds the row number to which the nonlinear function belongs. if negative, it is an objective function. 
	 * @return the nonlinear function's root node (of OSnLNode type).
	 * @see #getNonlinearExpression(int)
	 */
	public OSnLNode getNonlinearRootNode(int rowIdx){
		getNonlinearExpressions();
		OSExpressionTree exTree = (OSExpressionTree)(m_expressionTrees.get(rowIdx));
		if(exTree == null) return null;
		return exTree.getRootNode();
	}//getNonlinearRootNode
	
	/**
	 * Calculate the nonlinear function value in a specified constraint (row) given the current variable values.
	 *
	 * </p>
	 *
	 * @param rowIdx holds the row number to which the nonlinear function belongs. if negative, it is an objective function. 
	 * @param x holds the values of the variables in a double array.
	 * @return the nonlinear function value in the specified constraint (row) given the current variable values.
	 */
	public double calculateNonlinearFunction(int rowIdx, double[] x){
		getNonlinearExpressions();
		OSExpressionTree exTree = (OSExpressionTree)(m_expressionTrees.get(rowIdx));
		if(exTree == null) return 0;
		return exTree.calculateFunction(x);
	}//calculateNonlinearFunction

	/**
	 * Calculate the function (nonlinear+quadratic+linear) value in a specified constraint (row) given the current variable values.
	 *
	 * </p>
	 *
	 * @param rowIdx holds the row number to which the function belongs. if negative, it is an objective function. 
	 * @param x holds the values of the variables in a double array.
	 * @return the function value in the specified constraint (row) given the current variable values.
	 */
	public double calculateFunction(int rowIdx, double[] x){
		double dResult = calculateLinearFunction(rowIdx, x) + 
					  calculateQuadraticFunction(rowIdx, x) + 
					  calculateNonlinearFunction(rowIdx, x);
		return dResult;
	}//calculateFunction

	/**
	 * Calculate the nonlinear function value in a specified constraint (row) given the current variable values.
	 * If the function has been evaluated over the current x values, the method will retrieve it.
	 *
	 * </p>
	 *
	 * @param rowIdx holds the row number to which the nonlinear function belongs. if negative, it is an objective function. 
	 * @param x holds the values of the variables in a double array.
	 * @param functionEvaluated holds whether the function has been evaluated.
	 * @return the nonlinear function value in the specified constraint (row) given the current variable values.
	 */
	public double calculateNonlinearFunction(int rowIdx, double[] x, boolean functionEvaluated){
		getNonlinearExpressions();
		OSExpressionTree exTree = (OSExpressionTree)(m_expressionTrees.get(rowIdx));
		if(exTree == null) return 0;
		return exTree.calculateFunction(x, functionEvaluated);
	}//calculateNonlinearFunction
	
	/**
	 * Calculate the function (nonlinear+quadratic+linear) value in a specified constraint (row) given the current variable values.
	 *
	 * </p>
	 *
	 * @param rowIdx holds the row number to which the function belongs. if negative, it is an objective function. 
	 * @param x holds the values of the variables in a double array.
	 * @param functionEvaluated holds whether the function has been evaluated.
	 * @return the function value in the specified constraint (row) given the current variable values.
	 */
	public double calculateFunction(int rowIdx, double[] x,boolean functionEvaluated){
		double dResult = calculateLinearFunction(rowIdx, x) + 
			calculateQuadraticFunction(rowIdx, x) + 		 
			calculateNonlinearFunction(rowIdx, x, functionEvaluated);
		return dResult;
	}//calculateFunction

	/**
	 * Calculate the nonlinear function value in a specified constraint (row) given the current variable values.
	 * If the function has been evaluated over the current x values, the method will retrieve it.
	 *
	 * </p>
	 *
	 * @param rowIdx holds the row number to which the nonlinear function belongs. if negative, it is an objective function.
	 * @param x holds the values of the variables in a string array.
	 * @param functionEvaluated holds whether the function has been evaluated.
	 * @return the nonlinear function value in the specified constraint (row) given the current variable values in a string.
	 */
	public String calculateNonlinearFunction(int rowIdx, String[] x, boolean functionEvaluated){
		getNonlinearExpressions();
		OSExpressionTree exTree = (OSExpressionTree)(m_expressionTrees.get(rowIdx));
		if(exTree == null) return "";
		return exTree.calculateFunction(x, functionEvaluated);
	}//calculateNonlinearFunction - string based
	
	/**
	 * Calculate the nonlinear function derivatives in a specified constraint (row) given the current variable values w.r.t all variables.
	 * </p>
	 *
	 * @param rowIdx holds the row number to which the nonlinear function belongs. If negative, it's an objective function.
	 * @param x holds the values of the variables in a double array.
	 * @param functionEvaluated holds whether the function has been evaluated.
	 * @return a hashmap of the nonzero function derivative values given the current variable values.
	 * The map keys are variable indexes, and the map values are nonzero derivatives. 	 
	 */
	public Int2DoubleOpenHashMap calculateNonlinearDerivatives(int rowIdx, double[] x, boolean functionEvaluated){
		getNonlinearExpressions();
		OSExpressionTree exTree = (OSExpressionTree)(m_expressionTrees.get(rowIdx));
		if(exTree == null) return null;
		return exTree.calculateDerivatives(x, functionEvaluated);
	}//calculateNonlinearDerivatives
	
	/**
	 * Get the nonlinear function derivatives in a specified constraint (row) given the current variable values w.r.t. all variables.
	 * This method assumes that the derivatives have already been calculated over the current variable values.
	 *
	 * </p>
	 *
	 * @param rowIdx holds the row number to which the nonlinear function belongs. If negative, it's an objective function.
	 * @return a hashmap of the nonzero function derivative values given the current variable values.
	 * The map keys are variable indexes, and the map values are nonzero derivatives. 
	 * This method assumes that the derivative values have already been calculated over the current variable values w.r.t all variables.
	 */
	public Int2DoubleOpenHashMap getNonlinearDerivatives(int rowIdx){
		getNonlinearExpressions();
		OSExpressionTree exTree = (OSExpressionTree)(m_expressionTrees.get(rowIdx));
		if(exTree == null) return null;
		return exTree.getDerivatives();
	}//getNonlinearDerivatives
	
	/**
	 * Calculate the nonlinear function derivative in a specified constraint (row) given the current variable values w.r.t one variable.
	 * </p>
	 *
	 * @param rowIdx holds the row number to which the nonlinear function belongs. If negative, it's an objective function.
	 * @param x holds the values of the variables in a double array.
	 * @param varIndex holds the variable index on which to take the derivative.
	 * @param functionEvaluated holds whether the function has been evaluated.
	 * @return the nonlinear function derivative in the specified constraint (row) given the current variable values w.r.t the specified variable.
	 */
	public double calculateNonlinearDerivative(int rowIdx, double[] x, int varIndex, boolean functionEvaluated){
		getNonlinearExpressions();
		OSExpressionTree exTree = (OSExpressionTree)(m_expressionTrees.get(rowIdx));
		if(exTree == null) return 0;
		return exTree.calculateDerivative(x, varIndex, functionEvaluated);
	}//calculateNonlinearDerivative
	
	/**
	 * Get the nonlinear function derivative in a specified constraint (row) given the current variable values w.r.t. one variable.
	 * This method assumes that the derivatives have already been calculated over the current variable values.
	 *
	 * </p>
	 *
	 * @param rowIdx holds the row number to which the nonlinear function belongs. If negative, it's an objective function.
	 * @param varIndex holds the variable index on which to take the derivative.
	 * @return the nonlinear function derivative in the specified constraint (row) given of the current variable values w.r.t the specified variable
	 * assuming that the derivative has already been calculated over the current variable values w.r.t the specified variable.
	 */
	public double getNonlinearDerivative(int rowIdx, int varIndex){
		getNonlinearExpressions();
		OSExpressionTree exTree = (OSExpressionTree)(m_expressionTrees.get(rowIdx));
		if(exTree == null) return 0;
		return exTree.getDerivative(varIndex);
	}//getNonlinearDerivative
	
	/**
	 * Calculate the nonlinear Hessian in a specified constraint (row) given the current variable values w.r.t all variables.
	 * </p>
	 *
	 * @param rowIdx holds the row number to which the nonlinear function belongs. If negative, it's an objective function.
	 * @param x holds the values of the variables in a double array.
	 * @param derivativeEvaluated holds whether the function derivatives have been evaluated.
	 * @return a sparse hash map of the upper triangular non-zero second partial derivatives w.r.t to variable i and then j, 
	 * given the current variable values. The map keys are the strings of variable indexes delimited by a comma, 
	 * i.e. "i,j" and the map values are the Hessian values. 
	 */
	public Object2DoubleOpenHashMap calculateNonlinearHessianMatrix(int rowIdx, double[] x, boolean derivativeEvaluated){
		getNonlinearExpressions();
		OSExpressionTree exTree = (OSExpressionTree)(m_expressionTrees.get(rowIdx));
		if(exTree == null) return null;
		return exTree.calculateHessian(x, derivativeEvaluated);
	}//calculateNonlinearHessian
	
	/**
	 * Get the nonlinear Hessian in a specified constraint (row) given the current variable values w.r.t all variables.
	 * This method assumes that the Hessian has already been calculated over the current variable values.
	 *
	 * </p>
	 *
	 * @param rowIdx holds the row number to which the nonlinear function belongs. If negative, it's an objective function.
	 * @return a sparse hash map of the upper triangular non-zero second partial derivatives w.r.t to variable i and then j, 
	 * given the current variable values. The map keys are the strings of variable indexes delimited by a comma, 
	 * i.e. "i,j" and the map values are the Hessian values. 
	 * This method assumes that the Hessian has already been calculated over the current variable values w.r.t all variables.
	 */
	public Object2DoubleOpenHashMap getNonlinearHessianMatrix(int rowIdx){
		getNonlinearExpressions();
		OSExpressionTree exTree = (OSExpressionTree)(m_expressionTrees.get(rowIdx));
		if(exTree == null) return null;
		return exTree.getHessian();
	}//getNonlinearHessianMatrix	
	
	/**
	 * Get the nonlinear Hessian in a specified constraint (row) given the current variable values w.r.t Xi and Xj.
	 * This method assumes that the Hessian has already been calculated over the current variable values.
	 *
	 * </p>
	 *
	 * @param rowIdx holds the row number to which the nonlinear function belongs. If negative, it's an objective function.
	 * @param i holds the first variable index of the second order partial derivative. 
	 * @param j holds the second variable index of the second order partial derivative. 
	 * @return the function Hessian value (i.e. second order partial derivative) corresponding to variable i and j. 
	 */
	public double getNonlinearHessianValue(int rowIdx, int i, int j){
		int iSmall = (i<=j)?i:j;
		int iBig = (i<=j)?j:i;
		Object2DoubleOpenHashMap hessianMap = getNonlinearHessianMatrix(rowIdx);
		if(hessianMap == null) return 0;
		String sKey = iSmall + "," + iBig;
		return hessianMap.getDouble(sKey);
	}//getNonlinearHessianValue		
	
	/**
	 * Express the nonlinear function in the specified constraint (row) in a postfix vector of operator symbols.
	 * If the row idx is negative, it returns that from an objective function.
	 * </p>
	 *
	 * @param rowIdx holds the row number to which the nonlinear function belongs. if negative, it is an objective function.
	 * @return the nonlinear function in the specified constraint (row) expressed in a postfix vector of operator symbols..
	 * If the row idx is negative, it returns that from an objective function.
	 */
	public Vector getNonlinearPostfix(int rowIdx){
		getNonlinearExpressions();
		OSExpressionTree exTree = (OSExpressionTree)(m_expressionTrees.get(rowIdx));
		if(exTree == null) return null;
		return exTree.getPostfix();
	}//getNonlinearPostfix
	
	/**
	 * Express the nonlinear function in the specified row in a prefix vector of operator symbols
	 * If the row idx is negative, it returns that from an objective function.
	 *
	 * </p>
	 *
	 * @param rowIdx holds the row idx to which the nonlinear function belongs. if negative, it is an objective function.
	 * @return the nonlinear function in the specified constraint (row) expressed in a prefix vector of operator symbols.
	 * If the row idx is negative, it returns that from an objective function.
	 */
	public Vector getNonlinearPrefix(int rowIdx){
		getNonlinearExpressions();
		OSExpressionTree exTree = (OSExpressionTree)(m_expressionTrees.get(rowIdx));
		if(exTree == null) return null;
		return exTree.getPrefix();
	}//getNonlinearPrefix

	/**
	 * Express the nonlinear function in the specified constraint (row) in an infix vector of operator symbols
	 * If the row idx is negative, it returns that from an objective function.
	 *
	 * </p>
	 *
	 * @param rowIdx holds the row idx to which the nonlinear function belongs. if negative, it is an objective function.
	 * @return the nonlinear function in the specified constraint (row) expressed in an infix vector of operator symbols.
	 * If the row idx is negative, it returns that from an objective function.
	 */
	public Vector getNonlinearInfix(int rowIdx){
		getNonlinearExpressions();
		OSExpressionTree exTree = (OSExpressionTree)(m_expressionTrees.get(rowIdx));
		if(exTree == null) return null;
		return exTree.getInfix();
	}//getNonlinearInfix

	/**
	 * Express the function in the specified constraint (row) in a postfix vecotr of operator symbols.
	 * If the row idx is negative, it returns that from an objective function.
	 *
	 * </p>
	 *
	 * @param rowIdx holds the row number to which the function belongs. if negative, it is an objective function.
	 * @return the function in the specified constraint (row) expressed in a postfix vector of operator symbols.
	 * If the row idx is negative, it returns that from an objective function.
	 */
	public Vector getPostfix(int rowIdx){
		Vector<String> vNonlinearPostfix = new Vector<String>();
		getNonlinearExpressions();
		OSExpressionTree exTree = (OSExpressionTree)(m_expressionTrees.get(rowIdx));
		if(exTree != null) vNonlinearPostfix = exTree.getPostfix();

		getQuadraticTerms();
		Vector<QuadraticTerm> vQuadraticTerms = m_quadraticTermMap.get(rowIdx+"");
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
		if(rowIdx < 0){
			double[] mdCoefValue = (getObjectiveNonzeroCoefficientValues())[Math.abs(rowIdx)-1];
			int[] mdCoefIndex = (getObjectiveNonzeroCoefficientIndexes())[Math.abs(rowIdx)-1];
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
			getLinearConstraintCoefficientMatrixNonzeroValues();
			getLinearConstraintCoefficientMatrixNonzeroIndexes();
			getLinearConstraintCoefficientMatrixStartIndexes();
			int iRow = 0;
			int iCol = 0;
			for(int i = 0; i < ((m_miStartCoefMatrix==null)?0:m_miStartCoefMatrix.length-1); i++){
				if(getLinearConstraintCoefficientMajor()) iCol = i;
				else iRow = i;
				for(int j = m_miStartCoefMatrix[i]; j < m_miStartCoefMatrix[i+1]; j++){
					if(getLinearConstraintCoefficientMajor())iRow = m_miIdxCoefMatrix[j];
					else iCol = m_miIdxCoefMatrix[j];
					if(iRow == rowIdx){
						iLinearTerms++;
						if(m_mdValueCoefMatrix[j] != 1) vLinearPostfix.addElement(m_mdValueCoefMatrix[j] + "");
						vLinearPostfix.addElement("X" + iCol);
						if(m_mdValueCoefMatrix[j] != 1) vLinearPostfix.addElement("times");
					}
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
	 * @param rowIdx holds the row idx to which the function belongs. if negative, it is an objective function.
	 * @return the function in the specified constraint (row) expressed in a prefix vector of operator symbols.
	 * If the row idx is negative, it returns that from an objective function.
	 */
	public Vector getPrefix(int rowIdx){
		Vector<String> vNonlinearPrefix = new Vector<String>();
		getNonlinearExpressions();
		OSExpressionTree exTree = (OSExpressionTree)(m_expressionTrees.get(rowIdx));
		if(exTree != null) vNonlinearPrefix = exTree.getPrefix();

		getQuadraticTerms();
		Vector<QuadraticTerm> vQuadraticTerms = m_quadraticTermMap.get(rowIdx+"");
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
		if(rowIdx < 0){
			double[] mdCoefValue = (getObjectiveNonzeroCoefficientValues())[Math.abs(rowIdx)-1];
			int[] mdCoefIndex = (getObjectiveNonzeroCoefficientIndexes())[Math.abs(rowIdx)-1];
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
			getLinearConstraintCoefficientMatrixNonzeroValues();
			getLinearConstraintCoefficientMatrixNonzeroIndexes();
			getLinearConstraintCoefficientMatrixStartIndexes();
			int iRow = 0;
			int iCol = 0;
			for(int i = 0; i < ((m_miStartCoefMatrix==null)?0:m_miStartCoefMatrix.length-1); i++){
				if(getLinearConstraintCoefficientMajor()) iCol = i;
				else iRow = i;
				for(int j = m_miStartCoefMatrix[i]; j < m_miStartCoefMatrix[i+1]; j++){
					if(getLinearConstraintCoefficientMajor())iRow = m_miIdxCoefMatrix[j];
					else iCol = m_miIdxCoefMatrix[j];
					if(iRow == rowIdx){
						iLinearTerms++;
						if(m_mdValueCoefMatrix[j] != 1){
							vLinearPrefix.addElement("times");
							vLinearPrefix.addElement(m_mdValueCoefMatrix[j] + "");
						}
						vLinearPrefix.addElement("X" + iCol);
					}
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
	 * @param rowIdx holds the row number to which the function belongs. if negative, it is an objective function.
	 * @return the function in the specified constraint (row) expressed in a infix vector of operator symbols.
	 * If the row idx is negative, it returns that from an objective function.
	 */
	public Vector getInfix(int rowIdx){
		Vector<String> vNonlinearInfix = new Vector<String>();
		getNonlinearExpressions();
		OSExpressionTree exTree = (OSExpressionTree)(m_expressionTrees.get(rowIdx));
		if(exTree != null) vNonlinearInfix = exTree.getInfix();

		getQuadraticTerms();
		Vector<QuadraticTerm> vQuadraticTerms = m_quadraticTermMap.get(rowIdx+"");
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
		if(rowIdx < 0){
			double[] mdCoefValue = (getObjectiveNonzeroCoefficientValues())[Math.abs(rowIdx)-1];
			int[] mdCoefIndex = (getObjectiveNonzeroCoefficientIndexes())[Math.abs(rowIdx)-1];
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
			getLinearConstraintCoefficientMatrixNonzeroValues();
			getLinearConstraintCoefficientMatrixNonzeroIndexes();
			getLinearConstraintCoefficientMatrixStartIndexes();
			int iRow = 0;
			int iCol = 0;
			for(int i = 0; i < ((m_miStartCoefMatrix==null)?0:m_miStartCoefMatrix.length-1); i++){
				if(getLinearConstraintCoefficientMajor()) iCol = i;
				else iRow = i;
				for(int j = m_miStartCoefMatrix[i]; j < m_miStartCoefMatrix[i+1]; j++){
					if(getLinearConstraintCoefficientMajor())iRow = m_miIdxCoefMatrix[j];
					else iCol = m_miIdxCoefMatrix[j];
					if(iRow == rowIdx){
						iLinearTerms++;
						if(m_mdValueCoefMatrix[j] != 1){
							vLinearInfix.addElement(m_mdValueCoefMatrix[j] + "");
							vLinearInfix.addElement("times");
						}
						vLinearInfix.addElement("X" + iCol);
					}
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
	 * Simplify the nonlinear part of the function in a specified constraint (row). 
	 * 
	 * @param rowIdx holds the row number to which the function belongs. if negative, it is an objective function.
	 * @return the reduction size, i.e. the number of nodes taken out of the original expression tree. 
	 * If 0, the nonlinear function is reduced. 
	 */
	public int simplifyNonlinearFunction(int rowIdx){
		getNonlinearExpressions();
		OSExpressionTree exTree = (OSExpressionTree)(m_expressionTrees.get(rowIdx));
		if(exTree == null) return 0;
		return exTree.simplify();
	}//simplifyNonlinearFunction
	
	/**
	 * <p>Linearize the the expression tree of a specified constraint (row) so that it doesn't contain linear terms. 
	 * The expression tree of the node will become smaller if there are linear terms. 
	 * If the node is fully linear, the node becomes null. If the node is not linear 
	 * at all, it will remain the same and the returned hash map has a size zero.  
	 * </p>
	 * 
	 * @param rowIdx holds the row number to which the function belongs. if negative, it is an objective function.
	 * @return a hashmap of linear terms extracted out from the expression tree of the specified row, 
	 * with keys being the variable indices and values being the variable coefficients.
	 */
	public Int2DoubleOpenHashMap linearizeNonlinearFunction(int rowIdx){//TODO
		getNonlinearExpressions();
		OSExpressionTree exTree = (OSExpressionTree)(m_expressionTrees.get(rowIdx));
		if(exTree == null) return null;
		return exTree.linearize();
	}//linearizeNonlinearFunction
	
	/**
	 * <p>Quadratize the current expression tree, or make all the quadratic terms written in the 
	 * form of a quadratic node with its children being the quadratic terms.  
	 * 
	 * @param rowIdx holds the row number to which the function belongs. if negative, it is an objective function.
	 * @return whether there is conversion of some quadratic terms.
	 */
	public boolean quadratizeNonlinearFunction(int rowIdx){//TODO
		getNonlinearExpressions();
		OSExpressionTree exTree = (OSExpressionTree)(m_expressionTrees.get(rowIdx));
		if(exTree == null) return false;
		return exTree.quadratize();
	}//quadratizeNonlinearFunction
	
	
	/**
	 * Get an integer set of indices of the variables that exist in the nonlinear part of the function 
	 * in a specified constraint (row).
	 * 
	 * @param rowIdx holds the row number to which the function belongs. if negative, it is an objective function.
	 * @return a set of indices of the variables that exist in the nonlinear part of the function 
	 * in the specified constraint (row).
	 */
	public IntOpenHashSet getNonlinearVariableIndices(int rowIdx){
		getNonlinearExpressions();
		OSExpressionTree exTree = (OSExpressionTree)(m_expressionTrees.get(rowIdx));
		if(exTree == null) return null;
		return exTree.getVariableIndices();
	}//getNonlinearVariableIndices
	
	/**
	 * <p> Get row (constraint) and col (var) indexes of nonzero elements of the constraint gradients (Jacobian Matrix).
	 * This is usually needed before a nonlinear optimization starts. A variable index will be counted once 
	 * everytime the variable appears in a separate row (or constraint). </p>
	 * It is not appropriate to use this method if there is a variable that takes as its index an integer-valued variable.  
	 *  
	 * @return a two dimmensional integer array indexes = int[2][numNonzeroIndexes]. So in essense, the method returns
	 * two arrays of the same size. The 1st array -- indexes[0] of size numNonzeroIndexes -- contains the row (constraint) number of a variable 
	 * indexes and the 2nd array -- indexes[1] again of size numNonzeroIndexes -- contains the variable indexes. For example
	 * if indexes[0] = {0, 0, 1, 1, 2} and indexes[1] = {1, 3, 0, 2, 1}, it means variables appear in (row, col) = (0, 1), (0, 3), (1, 0), (1, 2) and (2, 1) 
	 * so the corresponding entries in the Jacobian matrix may be nonzeros.  
	 *  
	 */
	public int[][] getJacobianNonzeroIndexes(){
		if(m_mmiJacobianNonzeroIndex != null) return m_mmiJacobianNonzeroIndex;
		m_mmiJacobianNonzeroIndex = new int[2][];
		getNonlinearExpressions();
		IntOpenHashSet[] mHashSet = new IntOpenHashSet[getConstraintNumber()];
		for(int i = 0; i < getConstraintNumber(); i++){
			mHashSet[i] = new IntOpenHashSet();
			OSExpressionTree exTree = (OSExpressionTree)(m_expressionTrees.get(i));
			if(exTree != null){
				mHashSet[i] = exTree.getVariableIndices();				
			}
		}		
		getLinearConstraintCoefficientMatrixNonzeroValues();
		getLinearConstraintCoefficientMatrixNonzeroIndexes();
		getLinearConstraintCoefficientMatrixStartIndexes();
		int iRow = 0;
		int iCol = 0;
		for(int i = 0; i < ((m_miStartCoefMatrix==null)?0:m_miStartCoefMatrix.length-1); i++){
			if(getLinearConstraintCoefficientMajor()) iCol = i;
			else iRow = i;
			for(int j = m_miStartCoefMatrix[i]; j < m_miStartCoefMatrix[i+1]; j++){
				if(getLinearConstraintCoefficientMajor())iRow = m_miIdxCoefMatrix[j];
				else iCol = m_miIdxCoefMatrix[j];
				if( m_mdValueCoefMatrix[j] != 0){
					mHashSet[iRow].add(iCol);
				}
			}
		}
		int iSize = 0;
		for(int i = 0; i < mHashSet.length; i++) iSize += mHashSet[i].size();
		m_mmiJacobianNonzeroIndex[0] = new int[iSize];
		m_mmiJacobianNonzeroIndex[1] = new int[iSize];
		int i= 0;
		for(int j = 0; j < mHashSet.length; j++){
			IntIterator iter = mHashSet[j].intIterator();
			while(iter.hasNext()){			
				m_mmiJacobianNonzeroIndex[0][i] = j;
				m_mmiJacobianNonzeroIndex[1][i] = iter.nextInt();
			    i++;
			}
		}
		return m_mmiJacobianNonzeroIndex;
	}//getJacobianNonzeroIndexes
	
	/**
	 * Get the expression tree size, i.e. the number of nodes, of the nonlinear expression tree
	 * in the specified constraint (row). 
	 * 
	 * @param rowIdx holds the row number to which the function belongs. if negative, it is an objective function.
	 * @return the tree size, i.e. the number of nodes, of the nonlinear expression tree
	 * in the specified constraint (row). 
	 */
	public int getExpressionTreeSize(int rowIdx){
		getNonlinearExpressions();
		OSExpressionTree exTree = (OSExpressionTree)(m_expressionTrees.get(rowIdx));
		if(exTree == null) return 0;
		return exTree.getSize();
	}//getExpressionTreeSize
	
	/**
	 * Get the number of trigonometric functions in the nonlinear function of the specified row. 
	 *  
	 * @param rowIdx holds the row number to which the function belongs. if negative, it is an objective function.
	 * @return the number of trigonometric functions in the nonlinear function of the specified row. 
	 */
	public int getTrigonometricFunctionNumbers(int rowIdx){
		getNonlinearExpressions();
		OSExpressionTree exTree = (OSExpressionTree)(m_expressionTrees.get(rowIdx));
		if(exTree == null) return 0;
		return exTree.getNumberOfTrigonometricFunctions();
	}//getTrigonometricFunctionNumbers
	
	/**
	 * Get the number of statistic functions in the nonlinear function of the specified constraint (row). 
	 * 
	 * @param rowIdx holds the row number to which the function belongs. if negative, it is an objective function.
	 * @return the number of statistic functions in the nonlinear function of the specified constraint (row). 
	 */
	public int getNumberOfStatisticFunctions(int rowIdx){
		getNonlinearExpressions();
		OSExpressionTree exTree = (OSExpressionTree)(m_expressionTrees.get(rowIdx));
		if(exTree == null) return 0;
		return exTree.getNumberOfStatisticFunctions();
	}//getNumberOfStatisticFunctions
	
	/**
	 * Get the number of probability functions in the nonlinear function of the specified constraint (row). 
	 * 
	 * @param rowIdx holds the row number to which the function belongs. if negative, it is an objective function.
	 * @return the number of probability functions in the nonlinear function of the specified constraint (row). 
	 */
	public int getNumberOfProbabilityFunctions(int rowIdx){
		getNonlinearExpressions();
		OSExpressionTree exTree = (OSExpressionTree)(m_expressionTrees.get(rowIdx));
		if(exTree == null) return 0;
		return exTree.getNumberOfProbabilityFunctions();
	}//getNumberOfProbabilityFunctions
	
	/**
	 * Get a set of number values that exist in the nonlinear function of the specified constraint (row).  
	 * 
	 * @param rowIdx holds the row number to which the function belongs. if negative, it is an objective function.
	 * @return a set of number values that exist in the nonlinear function of the specified constraint (row).  
	 */
	public  HashSet getNumberValues(int rowIdx){
		getNonlinearExpressions();
		OSExpressionTree exTree = (OSExpressionTree)(m_expressionTrees.get(rowIdx));
		if(exTree == null) return null;
		return exTree.getNumberValues();
	}//getNumberValues
	
	/**
	 * Get a set of names of identifiers that exist in the nonlinear function of the specified constraint (row). 
	 * 
	 * @param rowIdx holds the row number to which the function belongs. if negative, it is an objective function.
	 * @return a set of names of identifiers that exist in the nonlinear function of the specified constraint (row). 
	 */
	public  HashSet getIdentifiers(int rowIdx){
		getNonlinearExpressions();
		OSExpressionTree exTree = (OSExpressionTree)(m_expressionTrees.get(rowIdx));
		if(exTree == null) return null;
		return exTree.getIdentifiers();
	}//getIdentifiers
	
	/**
	 * @return a set of logic and relational operator symbols that exist in the nonlinear expression
	 * of the specified constraint (row). 
	 * 
	 * @param rowIdx holds the row number to which the function belongs. if negative, it is an objective function.
	 * @return a set of logic and relational operator symbols that exist in the nonlinear expression
	 * of the specified constraint (row). 
	 */
	public  HashSet getLogicAndRelationalSymbols(int rowIdx){
		getNonlinearExpressions();
		OSExpressionTree exTree = (OSExpressionTree)(m_expressionTrees.get(rowIdx));
		if(exTree == null) return null;
		return exTree.getLogicAndRelationalSymbols();
	}//getLogicAndRelationalSymbols
	
	/**
	 * Get a set of quadratic terms that exist in the expression tree of the specified constraint (row), 
	 * each set member is of the form: i,j,coef, that is the first variable index, 
	 * the second variable index and the coefficient value, delimited by comma. 
	 * 
	 * @param rowIdx holds the row number to which the function belongs. if negative, it is an objective function.
	 * @return a set of quadratic terms that exist in the expression tree of the specified constraint (row).
	 */
	public  HashSet getNonlinearQuadraticTerms(int rowIdx){
		getNonlinearExpressions();
		OSExpressionTree exTree = (OSExpressionTree)(m_expressionTrees.get(rowIdx));
		if(exTree == null) return null;
		return exTree.getQuadraticTerms();
	}//getQuadraticTerms
	
	/**
	 * Get a set of names of the simulations that exist in the expression tree of the specified constraint (row). 
	 * 
	 * @param rowIdx holds the row number to which the function belongs. if negative, it is an objective function.
	 * @return a set of names of the simulations that exist in the expression tree of the specified constraint (row). 
	 */
	public  HashSet getSimulationNames(int rowIdx){
		getNonlinearExpressions();
		OSExpressionTree exTree = (OSExpressionTree)(m_expressionTrees.get(rowIdx));
		if(exTree == null) return null;
		return exTree.getSimulationNames();
	}//getNonlinearQuadraticTerms
	
	/**
	 * Get a set of names of the user defined functions that exist in the expression tree of the specified constraint (row). 
	 * 
	 * @param rowIdx holds the row number to which the function belongs. if negative, it is an objective function.
	 * @return a set of names of the user defined functions that exist in the expression tree of the specified constraint (row). 
	 */
	public  HashSet getUserFunctionNames(int rowIdx){
		getNonlinearExpressions();
		OSExpressionTree exTree = (OSExpressionTree)(m_expressionTrees.get(rowIdx));
		if(exTree == null) return null;
		return exTree.getUserFunctionNames();
	}//getUserFunctionNames
	
	/**
	 * Get a set of XPaths that exist in the expression tree of the specified constraint (row), 
	 * each set member is of the form: uri:path, that is uri and path delimited by :. 
	 * 
	 * @param rowIdx holds the row number to which the function belongs. if negative, it is an objective function.
	 * @return a set of XPaths that exist in the expression tree of the specified constraint (row), 
	 * each set member is of the form: uri:path, that is uri and path delimited by :. 
	 */
	public  HashSet getXPath(int rowIdx){
		getNonlinearExpressions();
		OSExpressionTree exTree = (OSExpressionTree)(m_expressionTrees.get(rowIdx));
		if(exTree == null) return null;
		return exTree.getXPath();
	}//getXPath
	
	/**
	 * Get a set of network nodes that are referred in the expression tree of the specified constraint (row), 
	 * each set member is of the form: nodeName:propertyName, that is nodeName and property name delimited :. 
	 * 
	 * @param rowIdx holds the row number to which the function belongs. if negative, it is an objective function.
	 * @return a set of network nodes that are referred in the expression tree of the specified constraint (row), 
	 * each set member is of the form: nodeName:propertyName, that is nodeName and property name delimited :. 
	 */
	public  HashSet getNetworkNodes(int rowIdx){
		getNonlinearExpressions();
		OSExpressionTree exTree = (OSExpressionTree)(m_expressionTrees.get(rowIdx));
		if(exTree == null) return null;
		return exTree.getNetworkNodes();
	}//getNetworkNodes
	
	/**
	 * Get a set of network arcs that are referred in the expression tree of the specified constraint (row), 
	 * each set member is of the form: arcName:propertyName, that is arcName and property name delimited :. 
	 * 
	 * @param rowIdx holds the row number to which the function belongs. if negative, it is an objective function.
	 * @return a set of network arcs that are referred in the expression tree of the specified constraint (row), 
	 * each set member is of the form: arcName:propertyName, that is arcName and property name delimited :. 
	 */
	public  HashSet getNetworkArcs(int rowIdx){
		getNonlinearExpressions();
		OSExpressionTree exTree = (OSExpressionTree)(m_expressionTrees.get(rowIdx));
		if(exTree == null) return null;
		return exTree.getNetworkArcs();
	}//getNetworkArcs
	
	/**
	 * Get the number of the complements operator in the expression tree of the specified constraint (row). 
	 * 
	 * @param rowIdx holds the row number to which the function belongs. if negative, it is an objective function.
	 * @return the number of the complements operator in the expression tree of the specified constraint (row). 
	 */
	public int getNumberOfComplementsOperator(int rowIdx){
		getNonlinearExpressions();
		OSExpressionTree exTree = (OSExpressionTree)(m_expressionTrees.get(rowIdx));
		if(exTree == null) return 0;
		return exTree.getNumberOfComplementsOperator();
	}//getNumberOfComplementsOperator
	
	/**
	 * Get the number of the probability operator (usually in chance constraint) in the expression tree of the specified constraint (row). 
	 * 
	 * @param rowIdx holds the row number to which the function belongs. if negative, it is an objective function.
	 * @return Get the number of the probability operator (usually in chance constraint) in the expression tree of the specified constraint (row). 
	 */
	public int getNumberOfProbOperator(int rowIdx){
		getNonlinearExpressions();
		OSExpressionTree exTree = (OSExpressionTree)(m_expressionTrees.get(rowIdx));
		if(exTree == null) return 0;
		return exTree.getNumberOfProbOperator();
	}//getNumberOfProbOperator
	
	/**
	 * Get the xmlData element.  
	 * 
	 * @return the xmlData element. 
	 */
	public Element getXMLDataElement(){
		if(m_eXMLData == null){
			Element eInstanceData = (Element)XMLUtil.findChildNode(m_eRoot, "instanceData");
			m_eXMLData = (Element)XMLUtil.findChildNode(eInstanceData, "xmlData");
		}
		return m_eXMLData;
	}//getXMLDataElement

	/**
	 * Get the xmlData in a string.  
	 * 
	 * @return the xmlData in a string. 
	 */
	public String getXMLDataString(){
		getXMLDataElement();
		if(m_eXMLData == null) return "";
		String sXMLData = XMLUtil.writeXMLElementToString(m_eXMLData);
		sXMLData = sXMLData.substring(sXMLData.indexOf("<xmlData>"));
		return sXMLData;
	}//getXMLDataString


	
	/**
	 * main for test purposes.
	 *
	 * </p>
	 *
	 * @param argv command line arguments.
	 */
	public static void main(String[] argv){
		OSiLReader osilReader = new OSiLReader(true);
		boolean bRead = false;
		String sOSiL = IOUtil.fileToString("xml/osxl/osil_2.xml");
		//String sOSiL = IOUtil.fileToString("xml/osxl/osil_2_MPSMatrix.xml");
		//String sOSiL = IOUtil.fileToString("xml/osxl/parinc.xml");
		//String sOSiL = IOUtil.fileToString("xml/osxl/sparseSDPA.xml");
		//System.out.println(sOSiL);
		
		bRead = osilReader.readString(sOSiL);
		System.out.println("bRead: " + bRead);
		String sLogicError = osilReader.getLogicError();
		if(sLogicError.length() == 0) System.out.println("No Logic Error Found.");
		else System.out.println(sLogicError);
		
		//System.out.println(osilReader.convertToFML());
		//System.out.println(osilReader.convertToSDPA());
			
		 System.out.println("getSource: "+osilReader.getInstanceSource());
		 System.out.println("getDescription: "+osilReader.getInstanceDescription());
		 System.out.println("getVariableCount: "+ osilReader.getVariableNumber());
		 System.out.println("getObjConstant: "+osilReader.getFirstObjectiveConstant());
		 System.out.println("getConstraintCount: "+osilReader.getConstraintNumber());
		 System.out.println("getCoefficientMatrixValueCount: "+osilReader.getLinearConstraintCoefficientNumber());
		 for(int i=0; i<osilReader.getVariableNumber(); i++){
		 	System.out.println("var: " + i);	 
		 	System.out.println("getVariableLBs: "+ (osilReader.getVariableLowerBounds())[i]);
			System.out.println("getVariableUBs: "+ (osilReader.getVariableUpperBounds())[i]);
			System.out.println("getVariableTypes: "+ (osilReader.getVariableTypes())[i]);
		 }

		 for(int i=0; i<osilReader.getVariableNumber(); i++){
		 	System.out.println("con: " + i);
		 	System.out.println("getConstraintNames: "+(osilReader.getConstraintNames())[i]);
		 	System.out.println("getConstraintLBs: "+(osilReader.getConstraintLowerBounds())[i]);
		 	System.out.println("getConstraintUBs: "+(osilReader.getConstraintUpperBounds())[i]);
		 	System.out.println("getVariableNames: "+(osilReader.getVariableNames())[i]);
		 	System.out.println("getVariableInits: "+(osilReader.getVariableInitialStringValues())[i]);
		}
		 for(int i=0; i<(osilReader.getFirstObjectiveNonzeroCoefficientValues()).length; i++)
		 	System.out.println("getFirstObjectiveCoefficientValues: "+(osilReader.getFirstObjectiveNonzeroCoefficientValues())[i]);
		 for(int i=0; i<(osilReader.getFirstObjectiveNonzeroCoefficientIndexes()).length; i++)	
		 	System.out.println("getFirstObjectiveCoefficientIndexes: "+(osilReader.getFirstObjectiveNonzeroCoefficientIndexes())[i]);
		 System.out.println("getFirstObjectiveMaxOrMin: "+osilReader.getFirstObjectiveMaxOrMin());
		 for(int i=0; i<osilReader.getObjectiveNumber(); i++){
		 	System.out.println("obj: " + i);
		 	System.out.println("getObjectiveNames: "+(osilReader.getObjectiveNames())[i]);
		 	System.out.println("getObjectiveMaxOrMins: "+(osilReader.getObjectiveMaxOrMins())[i]);
		 	System.out.println("getObjectiveConstants: "+(osilReader.getObjectiveConstants())[i]);
		 	System.out.println("getObjectiveWeights: "+(osilReader.getObjectiveWeights())[i]);
		 	for(int j=0; j<(osilReader.getObjectiveNonzeroCoefficientValues())[i].length; j++){
			 	System.out.println("coefValue[" + j +"]: " + (osilReader.getObjectiveNonzeroCoefficientValues())[i][j]);
			 	System.out.println("coefIndex[" + j +"]: " + (osilReader.getObjectiveNonzeroCoefficientIndexes())[i][j]);
		 	}

		}
		 for(int i = 0; i < (osilReader.getLinearConstraintCoefficientMatrixStartIndexes()).length; i++)
		 	System.out.println("getMatrixStartIndexes: "+osilReader.getLinearConstraintCoefficientMatrixStartIndexes()[i]);
		 for(int i = 0; i < (osilReader.getLinearConstraintCoefficientMatrixNonzeroValues()).length; i++)
		 	System.out.println("getMatrixNonzeroValues: "+osilReader.getLinearConstraintCoefficientMatrixNonzeroValues()[i]);
		 for(int i = 0; i < (osilReader.getLinearConstraintCoefficientMatrixNonzeroIndexes()).length; i++)
		 	System.out.println("getMatrixNonzeroIndexes: "+osilReader.getLinearConstraintCoefficientMatrixNonzeroIndexes()[i]);
		 System.out.println("getMatrixColumnMajor: "+osilReader.getLinearConstraintCoefficientMajor());
		
		double[][] coefMatrix = osilReader.getDenseLinearConstraintCoefficientMatrix();
		for(int i = 0; i < (coefMatrix==null?0:coefMatrix.length); i++){
			for(int j = 0; j < (coefMatrix[0]==null?0:coefMatrix[0].length); j++){
				System.out.print(coefMatrix[i][j]+", ");
			}
			System.out.println();
		}
		
		Int2ObjectOpenHashMap map = osilReader.getNonlinearExpressions();
		IntIterator it = (IntIterator)map.keySet().iterator();
		while(it.hasNext()){
			int iKey = it.nextInt();
			System.out.println("rowIdx: " + iKey);
			System.out.println("nonlinearpostfix: " + osilReader.getNonlinearPostfix(iKey));
			System.out.println("postfix: " + osilReader.getPostfix(iKey));
			System.out.println("nonlinearprefix: " + osilReader.getNonlinearPrefix(iKey));
			System.out.println("prefix: " + osilReader.getPrefix(iKey));
			System.out.println("nonlinearinfix: " + osilReader.getNonlinearInfix(iKey));
			System.out.println("infix: " + osilReader.getInfix(iKey));
			System.out.println();
		}
		
		
		double d = 1e-8;
		double v0 = 1;
		double v1 = 2;
		double v2 = 1;
		double[] X = {v0, v1, v2};
		String[] sX = {v0+"", v1+"", v2+""};
		double [] Xd ={v0+d, v1, v2};
		double val;
		System.out.println("auxilliary methods");
		IntOpenHashSet intSetVal = osilReader.getNonlinearVariableIndices(0);
		System.out.println("vars: " + intSetVal);
		val = osilReader.getExpressionTreeSize(0);
		System.out.println("tree size: " + val);
		val = osilReader.getTrigonometricFunctionNumbers(0);
		System.out.println("trigonometric: " + val);
		val = osilReader.getNumberOfStatisticFunctions(0);
		System.out.println("statistics: " + val);
		val = osilReader.getNumberOfProbabilityFunctions(0);
		System.out.println("probability: " + val);
		HashSet setVal = osilReader.getNumberValues(0);
		System.out.println("numbers: " + setVal);
		setVal = osilReader.getIdentifiers(0);
		System.out.println("identifiers: " + setVal);
		setVal = osilReader.getLogicAndRelationalSymbols(0);
		System.out.println("logic/relational: " + setVal);
		setVal = osilReader.getNonlinearQuadraticTerms(0);
		System.out.println("q terms: " + setVal);
		setVal = osilReader.getSimulationNames(0);
		System.out.println("sim: " + setVal);
		setVal = osilReader.getUserFunctionNames(0);
		System.out.println("userF: " + setVal);
		setVal = osilReader.getXPath(0);
		System.out.println("XPath: " + setVal);
		setVal = osilReader.getNetworkNodes(0);
		System.out.println("network nodes: " + setVal);
		setVal = osilReader.getNetworkArcs(0);
		System.out.println("network arcs: " + setVal);
		val = osilReader.getNumberOfComplementsOperator(0);
		System.out.println("complements: " + val);
		val = osilReader.getNumberOfProbOperator(0);
		System.out.println("prob: " + val);
		System.out.println("linear value");
		val = osilReader.calculateLinearObjectiveFunction(-1, X);
		System.out.println(val);
		val = osilReader.calculateLinearFunction(0, X);
		System.out.println(val);
		
		val = osilReader.calculateLinearFunction(0, X);
		System.out.println(val);
		val = osilReader.calculateLinearFunction(1, X);
		System.out.println(val);
		val = osilReader.calculateLinearFunction(2, X);
		System.out.println(val);
		val = osilReader.calculateLinearFunction(3, X);
		System.out.println(val);
		System.out.println("\nlinear derivative");
		double vals[] = osilReader.calculateLinearConstraintFunctions(X);
		System.out.println(vals[1]);
		System.out.println("\nnonlinear function");
		System.out.println(osilReader.getNonlinearInfix(0));
		System.out.println(X[0]);
		val = osilReader.calculateNonlinearFunction(0, X, false);
		System.out.println(val);		
		String sVal = osilReader.calculateNonlinearFunction(0, sX, false);
		System.out.println(sVal);
		val = osilReader.calculateNonlinearFunction(0, X);
		System.out.println(val);		
		val = osilReader.calculateNonlinearFunction(0, X, true);
		System.out.println(val);		
		sVal = osilReader.calculateNonlinearFunction(0, sX, true);
		System.out.println(sVal);
		System.out.println("\nnonlinear derivative");
		val = osilReader.calculateNonlinearDerivative(0, X, 0, false);
		System.out.println(val);
		Int2DoubleOpenHashMap mapVal = osilReader.calculateNonlinearDerivatives(0, X, false);
		if(mapVal == null) mapVal = new Int2DoubleOpenHashMap();
		System.out.println("map: " + mapVal);
		val = osilReader.getNonlinearDerivative(0, 0);
		System.out.println(val);
		mapVal = osilReader.getNonlinearDerivatives(0);
		if(mapVal == null) mapVal = new Int2DoubleOpenHashMap();
		System.out.println("map: " + mapVal.get(0));
		System.out.println("\nnonlinear Hessian");
		Object2DoubleOpenHashMap mapVal2 = osilReader.calculateNonlinearHessianMatrix(0, X, true);
		if(mapVal2 == null) mapVal2 = new Object2DoubleOpenHashMap();
		System.out.println("map: " + mapVal2);
		mapVal2 = osilReader.calculateNonlinearHessianMatrix(0, X, false);
		if(mapVal2 == null) mapVal2 = new Object2DoubleOpenHashMap();
		System.out.println("map: " + mapVal2);
		val = osilReader.getNonlinearHessianValue(0, 0, 0);
		System.out.println(val);
		System.out.println("verify");
		int n = 1;
		long start = System.currentTimeMillis();
		for(int i=0; i<n; i++) val = (osilReader.calculateNonlinearFunction(0, Xd, false) - osilReader.calculateNonlinearFunction(0, X, false))/d;
		long finish = System.currentTimeMillis();
		System.out.println("finite difference:( " + Long.toString(finish - start) + ") " + val);
		start = System.currentTimeMillis();
		for(int i=0; i<n; i++) val = osilReader.calculateNonlinearDerivative(0, X, 0, false);
		finish = System.currentTimeMillis();
		System.out.println("automatic difference: leaf-root:( " + Long.toString(finish - start) + ") " + val);
		start = System.currentTimeMillis();
		for(int i=0; i<n; i++) mapVal = osilReader.calculateNonlinearDerivatives(0, X, false);
		finish = System.currentTimeMillis();
		System.out.println("automatic difference: root-leaf:( " + Long.toString(finish - start) + ") " + mapVal);
		
		System.out.println("getJacobianNonzeroIndexes");
		int[][] indexes = osilReader.getJacobianNonzeroIndexes();
		for(int i=0; i<indexes[0].length; i++){
			System.out.print(indexes[0][i] + ", ");
			System.out.println(indexes[1][i]);
		}
		System.out.println("xmlData:\n" + osilReader.getXMLDataString());
	}//main
	
	static void usage(){
		System.out.println(" ");
		System.out.println("usage: java OSiLReader [options] <data file>");
		System.out.println("options: -f file name of an instance is supplied");
		System.out.println("\t-s an instance is supplied");
		System.out.println(" ");
	}//usage
	
}//class OSiLReader