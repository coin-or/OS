/**
 * @(#)OSiLWriter 1.0 03/14/2004
 *
 * Copyright (c) 2004
 */
package org.optimizationservices.oscommon.representationparser;

import java.util.Vector;

import org.optimizationservices.oscommon.datastructure.osgeneral.QuadraticTerms;
import org.optimizationservices.oscommon.datastructure.osgeneral.SparseMatrix;
import org.optimizationservices.oscommon.datastructure.osgeneral.SparseVector;
import org.optimizationservices.oscommon.localinterface.OSInstance;
import org.optimizationservices.oscommon.nonlinear.OSExpressionTree;
import org.optimizationservices.oscommon.util.OSParameter;
import org.optimizationservices.oscommon.util.XMLUtil;
import org.w3c.dom.Document;
import org.w3c.dom.Element;
import org.w3c.dom.Node;
import org.w3c.dom.NodeList;
import org.w3c.dom.ProcessingInstruction;
import org.w3c.dom.Text;







/**
 *
 * <P>The <code>OSiLWriter</code> class is used to construct an optimization instance that follows
 * the Optimization Services instance Language format. Each element declared in the OSiL Schema has
 * a corresponding protected element creation method (e.g. createEl for creation of element el).
 * User do not have direct access to any of these protected methods. They get to manipulate the output of OSiL
 * construction through a group of higher level optimization related public "set" methods (e.g. setConstraints).
 * The "set" methods are the opposite "get" method in the corresponding {@link org.optimizationservices.oscommon.representationparser.OSiLReader OSiLReader}
 * class. Each method checks within itself the argument consistency against OSiL Schema at the syntax level.
 * There is no specific sequence the user should follow to invoke these set methods. User can call the
 * same set methods several times. If the parameters are different, old values will be replaced by new ones.
 * Users should, though, make sure values submitted through different "set" methods are consistent, i.e. logically correct.
 * For example if variableCount in {@link #setDescription setDescription} is set to 2, then the variableLbs array in
 * {@link #setVariables setVariables} has to have a length 2.</p>
 *
 * <p>The OSiLWriter class also provides auxiliary facilities to write the xml to different output.</p>
 *
 * <p>The OSiLWriter class does not support writing mathML related elements.</p>
 *
 * </p>
 *
 * @author Robert Fourer, Jun Ma, Kipp Martin
 * @version 1.0, 03/14/2004
 * @see org.optimizationservices.oscommon.representationparser.OSiLReader
 * @since OS 1.0
 */

public class OSiLWriter extends OSgLWriter{
	
	/**
	 * m_eOSiL holds the OSiL root element.
	 */
	protected Element m_eOSiL = null;
	
	/**
	 * m_eInstanceHeader holds the 1st child element InstanceHeader of root element OSiL.
	 */
	protected Element m_eInstanceHeader = null;
	
	/**
	 * m_eInstanceData holds the 2nd child element InstanceData of root element OSiL.
	 */
	protected Element m_eInstanceData = null;
	
	/**
	 * constructor
	 */
	public OSiLWriter(){
		m_document = XMLUtil.createNewDocument();
		if(OSParameter.XSLT_LOCATION != null && OSParameter.XSLT_LOCATION.length() > 0){
			ProcessingInstruction xsltPI = m_document.createProcessingInstruction("xml-stylesheet",
	           "type=\"text/xsl\" href = \"" + OSParameter.XSLT_LOCATION + "OSiL.xslt\"");
			m_document.appendChild(xsltPI);     
		}
		m_eOSiL = createOSiLRoot();
		m_document.appendChild(m_eOSiL);
	}//constructor
	
	/**
	 * set the OSInstance, a standard optimization problem/data api.  
	 * 
	 * @return whether the OSInstance is set successfully 
	 * @throws Exception if there are errors setting the OSInstnace. 
	 */
   	public boolean setOSInstance(OSInstance osInstance) throws Exception{
		int nVar = osInstance.getVariableNumber();
		int nObj = osInstance.getObjectiveNumber();
		int nCon = osInstance.getConstraintNumber();
		int nLinearCoef = osInstance.getLinearConstraintCoefficientNumber();
		int nQuadraticCoef = osInstance.getQuadraticTermNumber();
   		int nNonlinearExpression = osInstance.getNonlinearExpressionTreeNumber();
		
		int i;
		if(!setInstanceHeader(osInstance.getInstanceName(), 
   				osInstance.getInstanceSource(), 
   				osInstance.getInstanceDescription())) 
   			throw new Exception("setInstanceHeader Unsuccessful");
		
		//set variables
   		if(!setVariables(nVar,
   				osInstance.getVariableNames(), 
   				osInstance.getVariableLowerBounds(), 
   				osInstance.getVariableUpperBounds(),
   				osInstance.getVariableTypes(),
   				osInstance.getVariableInitialValues(),
   				osInstance.getVariableInitialStringValues())) 
   			throw new Exception("setVariables Unsuccessful");

   		//set objectives
   		String[] msObjNames = osInstance.getObjectiveNames();
		String[] msObjMaxOrMins = osInstance.getObjectiveMaxOrMins();
		double[] mdObjConstants = osInstance.getObjectiveConstants();
		double[] mdObjWeights = osInstance.getObjectiveWeights();
		SparseVector[] mObjCoef = osInstance.getObjectiveCoefficients();
   		for(i = 0; i < nObj; i++){ 
   			if(!addObjective( (msObjNames==null)?null:msObjNames[i], 
   					msObjMaxOrMins[i].equals("min"), 
   					mdObjConstants[i], 
   					mdObjWeights[i],
   					(mObjCoef[i]==null)?null:mObjCoef[i].values,
   					(mObjCoef[i]==null)?null:mObjCoef[i].indexes))
   				throw new Exception("addObjective Unsuccessful");
   		}
   		
   		//set constraints
   		if(!setConstraints(nCon,
   				osInstance.getConstraintNames(), 
   				osInstance.getConstraintLowerBounds(), 
   				osInstance.getConstraintUpperBounds(),
   				osInstance.getConstraintConstants()))
   			throw new Exception("addObjective Unsuccessful");
   		
   		//set linear constraint coefficients
   		boolean bColumnMajor = osInstance.getLinearConstraintCoefficientMajor();
   		SparseMatrix matrix = bColumnMajor?osInstance.getLinearConstraintCoefficientsInColumnMajor():osInstance.getLinearConstraintCoefficientsInRowMajor();
   		if(matrix != null){
   	   		if(!setLinearConstraintCoefficients(nLinearCoef, bColumnMajor, matrix.values, matrix.indexes, matrix.starts))
   	   			throw new Exception("setLinearConstraintCoefficients Unsuccessful");
   		}
   		
   		//set qudratic terms
   		QuadraticTerms qTerms = osInstance.getQuadraticTerms();
   		if(qTerms != null && qTerms.coefficients != null){
   	   		if(!setQuadraticTerms(nQuadraticCoef, 
   	   				qTerms.rowIndexes, 
   	   				qTerms.varOneIndexes, 
   	   				qTerms.varTwoIndexes, 
   	   				qTerms.coefficients, 0, 
   	   				qTerms.coefficients.length -1))
   	   			throw new Exception("setQuadraticTerms Unsuccessful");
   		}
   		
   		//set nonlinear expression trees
   		int[] miNlIndexes = osInstance.getNonlinearExpressionTreeIndexes();
   		for(i = 0; i < nNonlinearExpression; i++){
   	   		if(!addNlNode(osInstance.getNonlinearExpressionTree(miNlIndexes[i]), miNlIndexes[i]))
   	   			throw new Exception("addNlNode Unsuccessful");;   			
   		}
   		return true;
   	}//setOSInstance
	
	
	/**
	 * Set the InstanceHeader related elements. If the elements (e.g. the required elements) are
	 * already there, it will reset the them. If the elements are not there (e.g. the optional elements),
	 * it will add them.
	 *
	 * </p>
	 *
	 * @param name holds the name of the optimization problem.
	 * @param source holds the source information of the optimization problem.
	 * @param description holds the description information of the optimization problem.
	 * @return whether the InstanceHeader construction is successful.
	 */
	public boolean setInstanceHeader(String name, String source, String description){
		try{
			Node nodeRef = null;
			if(description != null && description.length() > 0){
				Element eDescription = (Element)XMLUtil.findChildNode(m_eInstanceHeader, "description");
				if(eDescription == null){
					eDescription = createDescription(description);
					m_eInstanceHeader.insertBefore(eDescription, nodeRef);
				}
				else{
					XMLUtil.setElementValue(eDescription, description);
				}
			}
			if(source != null && source.length() > 0){
				Element eSource = (Element)XMLUtil.findChildNode(m_eInstanceHeader, "source");
				if(eSource == null){
					eSource = createSource(source);
					nodeRef = XMLUtil.findChildNode(m_eInstanceHeader, "description");
					m_eInstanceHeader.insertBefore(eSource, nodeRef);
				}
				else{
					XMLUtil.setElementValue(eSource, source);
				}
			}
			if(name != null && name.length() > 0){
				Element eName = (Element)XMLUtil.findChildNode(m_eInstanceHeader, "name");
				if(eName == null){
					eName = createName(name);
					nodeRef = XMLUtil.findChildNode(m_eInstanceHeader, "source");
					if(nodeRef == null)
						nodeRef = XMLUtil.findChildNode(m_eInstanceHeader, "description");
					m_eInstanceHeader.insertBefore(eName, nodeRef);
				}
				else{
					XMLUtil.setElementValue(eName, name);
				}
			}
		}
		catch(Exception e){
			e.printStackTrace();
			return false;
		}
		return true;
	}//setInstanceHeader
	
	/**
	 * Set the variable related elements. If the elements (e.g. the required elements) are
	 * already there, it will reset the them. If the elements are not there (e.g. the optional elements),
	 * it will add them.
	 *
	 * </p>
	 *
	 * @param numberVariables holds the number of variables. 
	 * @param variableNames holds the names of all the variables. It may be empty.
	 * @param variableLbs holds the values of lower bounds for the variables. It may be empty.
	 * @param variableUbs holds the values of upper bounds for the variables. It may be empty.
	 * @param variableTypes holds the types of all the variables, (e.g. 'C' for continuous
	 * type, 'I' for integer type, and 'B' for binary type). It may be empty.
	 * @param initialValues holds the initial double values of the variables. It may be empty.
	 * @param initialStringValues holds the initial string values of the variables. It may be empty.
	 * @return whether variable construction is successful.
	 */
	public boolean setVariables(int numberVariables, String[] variableNames, double[] variableLbs, double[] variableUbs,
			char[] variableTypes, double[] initialValues, String[] initialStringValues){
		try{
			if((variableNames != null && variableNames.length != numberVariables)
			|| (variableLbs != null && variableLbs.length != numberVariables)
			|| (variableUbs != null && variableUbs.length != numberVariables)
			|| (initialValues != null && initialValues.length != numberVariables)
			|| (initialStringValues != null && initialStringValues.length != numberVariables)
			|| (variableTypes != null && variableTypes.length != numberVariables)){
				return false;
			}
			Element eVariables = (Element)XMLUtil.findChildNode(m_eInstanceData, "variables");
			XMLUtil.removeAllChildren(eVariables);
			if(variableNames == null && variableLbs == null && variableUbs == null && variableTypes == null && initialValues == null){
				Element eVar = createVar();
				eVariables.appendChild(eVar);
				eVariables.setAttribute("numberOfVariables", numberVariables + "");
				eVar.setAttribute("mult", numberVariables + "");
				return true;
			}
			for(int i = 0; i < numberVariables; i++){
				Element eVar = null;
				eVar = createVar();
				eVariables.appendChild(eVar);
				if(variableNames != null && variableNames[i] != null && variableNames[i].length() > 0){
					eVar.setAttribute("name", variableNames[i]);
				}
				if(variableUbs != null){
					if(variableUbs[i] != Double.POSITIVE_INFINITY){
						eVar.setAttribute("ub", variableUbs[i]+"");
					}
				}
				if(variableLbs != null){
					if(variableLbs[i] != 0){
						if(variableLbs[i] == Double.NEGATIVE_INFINITY){
							eVar.setAttribute("lb", "-INF");
						}
						else{
							eVar.setAttribute("lb", variableLbs[i]+"");
						}
					}
				}
				if(variableTypes != null){
					if("IBS".indexOf(variableTypes[i]+"") != -1){
						eVar.setAttribute("type", variableTypes[i]+"");
					}
				}
				if(initialValues != null && !Double.isNaN(initialValues[i])){
					eVar.setAttribute("init", initialValues[i]+"");
				}
				if(initialStringValues != null && initialStringValues[i] != null && initialStringValues[i].length() > 0){
					eVar.setAttribute("initString", initialStringValues[i]+"");
				}
				//mult is not set (or by default = 1). For future developement, may want to check multiplicity.
			}
			eVariables.setAttribute("numberOfVariables", numberVariables+"");
		}
		catch(Exception e){
			e.printStackTrace();
			return false;
		}
		return true;
	}//setVariables
	
	/**
	 * add a variable (or var element).
	 * 
	 * @param variableName holds the name of a variable. It may be null.
	 * @param variableLb holds the value of the lower bound for the variable. 
	 * @param variableUb holds the value of the upper bound for the variables. 
	 * @param variableType holds the type of the variable, (e.g. 'C' for continuous
	 * type, 'I' for integer type, and 'B' for binary type).
	 * @param initialValue holds the initial value of the variables. It may be NaN, i.e. Double.NaN.
	 * @param initialStringValue holds the initial string value of the variables. It may be null. 
	 * @return whether variable addition is successful.
	 */
	public boolean addVariable(String variableName, double variableLb, double variableUb, char variableType, double initialValue, String initialStringValue){
		try{
			Element eVariables = (Element)XMLUtil.findChildNode(m_eInstanceData, "variables");
			Element eVar = createVar();
			eVariables.appendChild(eVar);
			if(variableName != null && variableName.length() > 0){
				eVar.setAttribute("name", variableName);
			}
			if(variableUb != Double.POSITIVE_INFINITY){
				eVar.setAttribute("ub", variableUb+"");
			}
			if(variableLb != 0){
				if(variableLb == Double.NEGATIVE_INFINITY){
					eVar.setAttribute("lb", "-INF");
				}
				else{
					eVar.setAttribute("lb", variableLb+"");
				}
			}
			if("IBS".indexOf(variableType+"") != -1){
				eVar.setAttribute("type", variableType+"");
			}
			if(!Double.isNaN(initialValue)){
				eVar.setAttribute("init", initialValue+"");
			}
			if(initialStringValue != null && initialStringValue.length() > 0){
				eVar.setAttribute("initString", initialStringValue);
			}
			int iVariables = eVariables.getElementsByTagName("var").getLength();
			eVariables.setAttribute("numberOfVariables", iVariables+"");			
		}
		catch(Exception e){
			e.printStackTrace();
			return false;
		}
		return true;
	}//addVariable

	/**
	 * add an objective function related elements. If the elements (e.g. the required elements) are
	 * already there, it will reset the them. If the elements are not there (e.g. the optional elements),
	 * it will add them.
	 *
	 * </p>
	 *
	 * @param objectiveName holds the name of the objective. It may be empty.
	 * @param isMin holds whether the objective is minimization or not.
	 * @param objectiveConstant holds the objective constant. It may be zero. 
	 * @param coefValues holds the nonzero coefficient values of the objective function.
	 * @param coefIndexes holds the nonzero coefficient variable indexes of the objective function.
	 * @return objectiveWeight holds the weight of the objective. It is usually 1 by default. 
	 */
	public boolean addObjective(String objectiveName, boolean isMin, double objectiveConstant, double objectiveWeight,
			double[] coefValues, int[] coefIndexes){
		try{
			if((coefValues != null && coefIndexes != null && coefValues.length != coefIndexes.length) ||
			   (coefValues != null && coefIndexes == null) ||
			   (coefValues == null && coefIndexes != null)){
				return false;
			}
			Node nodeRef = null;
			Element eObjectives = (Element)XMLUtil.findChildNode(m_eInstanceData, "objectives");
			if(eObjectives == null){
				eObjectives = createObjectives(1);
				nodeRef = XMLUtil.findChildNode(m_eInstanceData, "variables");
				nodeRef = nodeRef.getNextSibling();
				m_eInstanceData.insertBefore(eObjectives, nodeRef);
			}
			int iNumberOfObjCoef = (coefValues==null)?0:coefValues.length;
			Element eObj = createObj(isMin, -1);
			eObjectives.appendChild(eObj);
			if(objectiveName != null && objectiveName.length() > 0){
				eObj.setAttribute("name", objectiveName);
			}
			if(objectiveConstant != 0){
				eObj.setAttribute("constant", objectiveConstant+"");
			}
			if(objectiveWeight != 1){
				eObj.setAttribute("weight", objectiveWeight+"");
			}
			if(coefValues != null && coefIndexes != null){
				for(int i = 0; i < coefValues.length; i++){
					if(coefValues[i] != 0.0){
						Element eCoef = createCoef(coefValues[i], coefIndexes[i]);
						eObj.appendChild(eCoef);	
					}
					else{
						iNumberOfObjCoef--;
					}
				}
			}
			eObj.setAttribute("numberOfObjCoef", iNumberOfObjCoef+"");
			Vector<Element> vElements = XMLUtil.getChildElementsByTagName(eObjectives, "obj");
			int iObjectives = vElements==null?0:vElements.size();
			eObjectives.setAttribute("numberOfObjectives", iObjectives+"");		
		}
		catch(Exception e){
			e.printStackTrace();
			return false;
		}
		return true;
	}//addObjective
	
	/**
	 * Set the constraint related elements. If the elements (e.g. the required elements) are
	 * already there, it will reset the them. If the elements are not there (e.g. the optional elements),
	 * it will add them.
	 *
	 * <p>The constraint information contains all the information about the constraints
	 * except for the coefMatrix (AMatrix), which is to be set in the {@link #setCoefMatrix setCoefMatrix} method.</p>
	 *
	 * </p>
	 *
	 * @param numberConstraints holds the number of constraints. 
	 * @param constraintNames holds the names of all the constraints. It may be empty.
	 * @param constraintLbs holds the values of the lower bounds for the constraints. It may be empty.
	 * @param constraintUbs holds the values of the upper bounds for the constraints. It may be empty.
	 * @param constraintConstants holds the values of the constants for the constraints. It may be empty.
	 * @return whether constraint construction is successful.
	 */
	public boolean setConstraints(int numberConstraints, String[] constraintNames, double[] constraintLbs, double[] constraintUbs, double[] constraintConstants){
		try{
			if((constraintNames != null && constraintNames.length != numberConstraints)
			|| (constraintUbs != null && constraintUbs.length != numberConstraints)
			|| (constraintLbs != null && constraintLbs.length != numberConstraints)
			|| (constraintConstants != null && constraintConstants.length != numberConstraints)){
				return false;
			}
			Node nodeRef = null;
			Element eConstraints = (Element)XMLUtil.findChildNode(m_eInstanceData, "constraints");
			if(eConstraints == null){
				eConstraints = createConstraints(0);
				nodeRef = XMLUtil.findChildNode(m_eInstanceData, "objectives");
				if(nodeRef == null){
					nodeRef = XMLUtil.findChildNode(m_eInstanceData, "variables");
				}
				nodeRef = nodeRef.getNextSibling();
				m_eInstanceData.insertBefore(eConstraints, nodeRef);
			}
			XMLUtil.removeAllChildren(eConstraints);
			if(numberConstraints != 0 && constraintNames == null && constraintLbs == null && constraintUbs == null && constraintConstants == null){
				Element eCon = createCon();
				eConstraints.appendChild(eCon);
				eConstraints.setAttribute("numberOfConstraints", numberConstraints + "");
				eCon.setAttribute("mult", numberConstraints + "");
				return true;
			}
			for(int i = 0; i < numberConstraints; i++){
				Element eCon = null;
				eCon = createCon();
				eConstraints.appendChild(eCon);
				if(constraintNames != null && constraintNames[i] != null && constraintNames[i].length() > 0){
					eCon.setAttribute("name", constraintNames[i]);
				}
				if(constraintLbs != null){
					if(constraintLbs[i] != Double.NEGATIVE_INFINITY){	
						eCon.setAttribute("lb", constraintLbs[i]+"");
					}
				}
				if(constraintUbs != null){
					if(constraintUbs[i] != Double.POSITIVE_INFINITY){
						eCon.setAttribute("ub", constraintUbs[i]+"");
					}
				}
				if(constraintConstants != null){
					if(constraintConstants[i] != 0.0){	
						eCon.setAttribute("constant", constraintConstants[i]+"");
					}
				}
				//mult is not set (or by default = 1). For future developement, may want to check multiplicity.
			}
			eConstraints.setAttribute("numberOfConstraints", numberConstraints+"");
		}
		catch(Exception e){
			e.printStackTrace();
			return false;
		}
		return true;
	}//setConstraints
	
	/**
	 * Add a constraint (or &lt;con&gt; element) to the existing constraints. 
	 *
	 * @param constraintName holds the name of a constraint. It may be null.
	 * @param constraintLhs holds the value of the lower bounds for the constraint.
	 * @param constraintRhs holds the values of the upper bounds for the constraint.
	 * @param constraintConstant holds the values of the constant for the constraint.
	 * @return whether constraint addition is successful.
	 */
	public boolean addConstraint(String constraintName, double constraintLhs, double constraintRhs, double constraintConstant){
		try{
			Node nodeRef = null;
			Element eConstraints = (Element)XMLUtil.findChildNode(m_eInstanceData, "constraints");
			if(eConstraints == null){
				eConstraints = createConstraints(0);
				nodeRef = XMLUtil.findChildNode(m_eInstanceData, "objectives");
				if(nodeRef == null){
					nodeRef = XMLUtil.findChildNode(m_eInstanceData, "variables");
				}
				nodeRef = nodeRef.getNextSibling();
				m_eInstanceData.insertBefore(eConstraints, nodeRef);
			}			
			Element eCon = createCon();
			eConstraints.appendChild(eCon);
			if(constraintName != null && constraintName.length() > 0){
				eCon.setAttribute("name", constraintName);
			}
			if(constraintLhs != Double.NEGATIVE_INFINITY){
				eCon.setAttribute("lb", constraintLhs+"");
			}
			if(constraintRhs != Double.POSITIVE_INFINITY){
				eCon.setAttribute("ub", constraintRhs+"");
			}
			if(constraintConstant != 0.0){
				eCon.setAttribute("constant", constraintConstant+"");
			}
			int iConstraints = eConstraints.getElementsByTagName("con").getLength();
			eConstraints.setAttribute("numberOfConstraints", iConstraints+"");	
		}
		catch(Exception e){
			e.printStackTrace();
			return false;
		}		
		return true;
	}//addConstraint

	/**
	 * Set the sparse coefficient matrix related elements. If the elements (e.g. the required elements) are
	 * already there, it will reset the them. If the elements are not there (e.g. the optional elements),
	 * it will add them. The sizes of all the input arrays should be consistent with constraint and variable
	 * number in the optimization problem.  
	 *
	 * <p>The coefMatrix (AMatrix) stores all the information in the A part of Ax ~ b, i.e. the linear part of all constraints</p>
	 *
	 * </p>
	 *
	 * @param numberOfValues holds the number of specified values in the linear coefficient matrix.
	 * @param isColumnMajor holds the value of whether the coefMatrix (AMatrix) holding linear constraint data is stored
	 * by column. If false, the matrix is stored by row.
	 * @param nonzeroValues holds the values of the vector element value in coefMatrix (AMatrix), which contains nonzero elements.
	 * @param nonzeroIndexes holds the values of the vector element rowIdx or colIdx in coefMatrix (AMatrix). If the matrix is
	 * stored by column (row), rowIdx (colIdx) is the vector of row (column) indexes.
	 * @param startIndexes holds the values of the vector element start in coefMatrix (AMatrix), which points to the start of a
	 * column (row) of nonzero elements in coefMatrix (AMatrix).
	 * @return whether user wants to clear the arrays passed in to save memory if the arrays
	 * will still be referenced, a false value is to be returned.
	 */
	public boolean setLinearConstraintCoefficients(int numberOfValues, boolean isColumnMajor, double[] nonzeroValues, int[] nonzeroIndexes, int[] startIndexes){
		try{
			if(nonzeroValues == null || nonzeroIndexes == null || startIndexes == null){
				return false;
			}
			if(nonzeroValues.length != numberOfValues || nonzeroIndexes.length != numberOfValues){
				return false;
			}
			if((nonzeroValues != null && nonzeroIndexes != null && nonzeroValues.length != nonzeroIndexes.length)){
				return false;
			}
			return setLinearConstraintCoefficients(numberOfValues,  isColumnMajor, 
					nonzeroValues, 0, nonzeroValues.length-1, 
					nonzeroIndexes, 0, nonzeroIndexes.length-1, 
					startIndexes, 0, startIndexes.length-1);
		}
		catch(Exception e){
			e.printStackTrace();
			return false;
		}
	}//setLinearConstraintCoefficients

	/**
	 * Set the sparse coefficient matrix related elements. If the elements (e.g. the required elements) are
	 * already there, it will reset the them. If the elements are not there (e.g. the optional elements),
	 * it will add them. The start and begin array indexes should be consistent with constraint and variable
	 * number in the optimization problem.  
	 *
	 * <p>The coefMatrix (AMatrix) stores all the information in the A part of Ax ~ b, i.e. the linear part of all constraints</p>
	 *
	 * </p>
	 *
	 * @param numberOfValues holds the number of specified values in the linear coefficient matrix.
	 * @param isColumnMajor holds the value of whether the coefMatrix (AMatrix) holding linear constraint data is stored
	 * by column. If false, the matrix is stored by row.
	 * @param nonzeroValues holds the values of the vector element value in coefMatrix (AMatrix), which contains nonzero elements.
	 * @param nonzeroValuesBegin holds the begin index of the nonzeroValues array
	 * @param nonzeroValuesEnd holds the end index of the nonzeroValues array
	 * @param nonzeroIndexes holds the values of the vector element rowIdx or colIdx in coefMatrix (AMatrix). If the matrix is
	 * stored by column (row), rowIdx (colIdx) is the vector of row (column) indexes.
	 * @param nonzeroIndexesBegin holds the begin index of the nonzeroIndexes array
	 * @param nonzeroIndexesEnd holds the end index of the nonzeroIndexes array
	 * @param startIndexes holds the values of the vector element start in coefMatrix (AMatrix), which points to the start of a
	 * column (row) of nonzero elements in coefMatrix (AMatrix).
	 * @param startIndexesBegin holds the begin index of the startIndexes array
	 * @param startIndexesEnd holds the end index of the startIndexes array 
	 * @return whether user wants to clear the arrays passed in to save memory if the arrays
	 * will still be referenced, a false value is to be returned.
	 */
	public boolean setLinearConstraintCoefficients(int numberOfValues, boolean isColumnMajor, 
			double[] nonzeroValues, int nonzeroValuesBegin, int nonzeroValuesEnd, 
			int[] nonzeroIndexes, int nonzeroIndexesBegin, int nonzeroIndexesEnd, 
			int[] startIndexes, int startIndexesBegin, int startIndexesEnd){
		try{
			if(nonzeroValues == null || nonzeroIndexes == null || startIndexes == null){
				return false;
			}
			if((nonzeroValuesEnd - nonzeroValuesBegin + 1)  != numberOfValues 
					|| (nonzeroIndexesEnd - nonzeroIndexesBegin + 1) != numberOfValues){
				return false;
			}
			
			 return setLinearConstraintCoefficients(numberOfValues, isColumnMajor, 
					nonzeroValues, null, null, nonzeroValuesBegin, nonzeroValuesEnd,
					nonzeroIndexes, null, null, nonzeroIndexesBegin, nonzeroIndexesEnd, 
					startIndexes, null, null, startIndexesBegin, startIndexesEnd);
		}
		catch(Exception e){
			e.printStackTrace();
			return false;
		}
	}//setLinearConstraintCoefficients

	/**
	 * Set the compressed sparse coefficient matrix related elements with support for multiplicity and increment. 
	 * If the elements (e.g. the required elements) are already there, it will reset the them. If the elements are not there (e.g. the optional elements),
	 * it will add them.
	 *
	 * <p>The coefMatrix (AMatrix) stores all the information in the A part of Ax ~ b, i.e. the linear part of all constraints</p>
	 *
	 * </p>
	 *
	 * @param numberOfValues holds the number of specified values in the linear coefficient matrix.
	 * @param isColumnMajor holds the value of whether the coefMatrix (AMatrix) holding linear constraint data is stored
	 * by column. If false, the matrix is stored by row.
	 * @param nonzeroValues holds the values of the vector element value in coefMatrix (AMatrix), which contains nonzero elements.
	 * @param nonzeroValuesMultiplicity holds the multiplicity (repetition) of each nonzero value in the nonzeroValues array.  If null, all multiplicities are 1.
	 * @param nonzeroValuesIncrement holds the increment value of each repetition of the nonzeroValues for "multiplicity" times. If null, all increments are 0.  
	 * @param nonzeroIndexes holds the values of the vector element rowIdx or colIdx in coefMatrix (AMatrix). If the matrix is
	 * stored by column (row), rowIdx (colIdx) is the vector of row (column) indexes.
	 * @param nonzeroIndexesMultiplicity holds the multiplicity (repetition) of each nonzero index in the nonzeroIndexes array. If null, all multiplicities are 1.
	 * @param nonzeroIndexesIncrement holds the increment value of each repetition of the nonzeroIndexes for "multiplicity" times. If null, all increments are 0.  
	 * @param startIndexes holds the values of the vector element start in coefMatrix (AMatrix), which points to the start of a
	 * column (row) of nonzero elements in coefMatrix (AMatrix).
	 * @param startIndexesMultiplicity holds the multiplicity (repetition) of each start index in the startIndexes array. If null, all multiplicities are 1.
	 * @param startIndexesIncrement holds the increment value of each repetition of the startIndexes for "multiplicity" times. If null, all increments are 0.  
	 * @return whether user wants to clear the arrays passed in to save memory if the arrays
	 * will still be referenced, a false value is to be returned.
	 */
	public boolean setLinearConstraintCoefficients(int numberOfValues, boolean isColumnMajor, 
			double[] nonzeroValues, int[] nonzeroValuesMultiplicity, double[] nonzeroValuesIncrement, 
			int[] nonzeroIndexes, int[] nonzeroIndexesMultiplicity, int[] nonzeroIndexesIncrement,
			int[] startIndexes, int[] startIndexesMultiplicity, int[] startIndexesIncrement){
		try{
			if(nonzeroValues == null || nonzeroIndexes == null || startIndexes == null){
				return false;
			}
			if(nonzeroValuesMultiplicity != null &&  nonzeroValuesMultiplicity.length != nonzeroValues.length){
				return false;
			}
			if(nonzeroValuesIncrement != null &&  nonzeroValuesIncrement.length != nonzeroValues.length){
				return false;
			}
			if(nonzeroIndexesMultiplicity != null &&  nonzeroIndexesMultiplicity.length != nonzeroIndexes.length){
				return false;
			}
			if(nonzeroIndexesIncrement != null &&  nonzeroIndexesIncrement.length != nonzeroIndexes.length){
				return false;
			}
			if(startIndexesMultiplicity != null &&  startIndexesMultiplicity.length != startIndexes.length){
				return false;
			}
			if(startIndexesIncrement != null &&  startIndexesIncrement.length != startIndexes.length){
				return false;
			}
			
			return setLinearConstraintCoefficients(numberOfValues, isColumnMajor, 
					nonzeroValues, nonzeroValuesMultiplicity, nonzeroValuesIncrement, 0, nonzeroValues.length-1,
					nonzeroIndexes, nonzeroIndexesMultiplicity, nonzeroIndexesIncrement, 0, nonzeroIndexes.length-1, 
					startIndexes, startIndexesMultiplicity, startIndexesIncrement, 0, startIndexes.length-1);

		}
		catch(Exception e){
			e.printStackTrace();
			return false;
		}
	}//setLinearConstraintCoefficients

	/**
	 * Set the compressed sparse coefficient matrix related elements with support for multiplicity and increment. 
	 * If the elements (e.g. the required elements) are already there, it will reset the them. If the elements are not there (e.g. the optional elements),
	 * it will add them.
	 *
	 * <p>The coefMatrix (AMatrix) stores all the information in the A part of Ax ~ b, i.e. the linear part of all constraints</p>
	 *
	 * </p>
	 *
	 * @param numberOfValues holds the number of specified values in the linear coefficient matrix.
	 * @param isColumnMajor holds the value of whether the coefMatrix (AMatrix) holding linear constraint data is stored
	 * by column. If false, the matrix is stored by row.
	 * @param nonzeroValues holds the values of the vector element value in coefMatrix (AMatrix), which contains nonzero elements.
	 * @param nonzeroValuesMultiplicity holds the multiplicity (repetition) of each nonzero value in the nonzeroValues array.  If null, all multiplicities are 1.
	 * @param nonzeroValuesIncrement holds the increment value of each repetition of the nonzeroValues for "multiplicity" times. If null, all increments are 0.  
	 * @param nonzeroValuesBegin holds the begin index of the nonzeroValues array
	 * @param nonzeroValuesEnd holds the end index of the nonzeroValues array
	 * @param nonzeroIndexes holds the values of the vector element rowIdx or colIdx in coefMatrix (AMatrix). If the matrix is
	 * stored by column (row), rowIdx (colIdx) is the vector of row (column) indexes.
	 * @param nonzeroIndexesMultiplicity holds the multiplicity (repetition) of each nonzero index in the nonzeroIndexes array. If null, all multiplicities are 1.
	 * @param nonzeroIndexesIncrement holds the increment value of each repetition of the nonzeroIndexes for "multiplicity" times. If null, all increments are 0.  
	 * @param nonzeroIndexesBegin holds the begin index of the nonzeroIndexes array
	 * @param nonzeroIndexesEnd holds the end index of the nonzeroIndexes array
	 * @param startIndexes holds the values of the vector element start in coefMatrix (AMatrix), which points to the start of a
	 * column (row) of nonzero elements in coefMatrix (AMatrix).
	 * @param startIndexesMultiplicity holds the multiplicity (repetition) of each start index in the startIndexes array. If null, all multiplicities are 1.
	 * @param startIndexesIncrement holds the increment value of each repetition of the startIndexes for "multiplicity" times. If null, all increments are 0.  
	 * @param startIndexesBegin holds the begin index of the startIndexes array
	 * @param startIndexesEnd holds the end index of the startIndexes array 
	 * @return whether user wants to clear the arrays passed in to save memory if the arrays
	 * will still be referenced, a false value is to be returned.
	 */
	public boolean setLinearConstraintCoefficients(int numberOfValues, boolean isColumnMajor, 
			double[] nonzeroValues, int[] nonzeroValuesMultiplicity, double[] nonzeroValuesIncrement, int nonzeroValuesBegin, int nonzeroValuesEnd,
			int[] nonzeroIndexes, int[] nonzeroIndexesMultiplicity, int[] nonzeroIndexesIncrement, int nonzeroIndexesBegin, int nonzeroIndexesEnd, 
			int[] startIndexes, int[] startIndexesMultiplicity, int[] startIndexesIncrement, int startIndexesBegin, int startIndexesEnd){
		try{
			if(nonzeroValues == null || nonzeroIndexes == null || startIndexes == null){
				return false;
			}

			Node nodeRef = null;
			Element eCoefMatrix = (Element)XMLUtil.findChildNode(m_eInstanceData, "linearConstraintCoefficients");
			if(eCoefMatrix == null){
				eCoefMatrix = createLinearConstraintCoefficients(isColumnMajor, numberOfValues);
				nodeRef = XMLUtil.findChildNode(m_eInstanceData, "constraints");
				if(nodeRef == null)
					nodeRef = XMLUtil.findChildNode(m_eInstanceData, "objectives");
				if(nodeRef == null)
					nodeRef = XMLUtil.findChildNode(m_eInstanceData, "variables");
				nodeRef = nodeRef.getNextSibling();
				m_eInstanceData.insertBefore(eCoefMatrix, nodeRef);
			}			
			Element eStart = (Element)XMLUtil.findChildNode(eCoefMatrix, "start");
			Element eValue = (Element)XMLUtil.findChildNode(eCoefMatrix, "value");
			Element eIdx = null;
			Element eRowIdx = (Element)XMLUtil.findChildNode(eCoefMatrix, "rowIdx");
			if(eRowIdx != null){
				eIdx = eRowIdx;
			}
			Element eColIdx = (Element)XMLUtil.findChildNode(eCoefMatrix, "colIdx");
			if(eColIdx != null){
				eIdx = eColIdx;
			}
			if(eRowIdx != null && !isColumnMajor){
				eIdx = createColIdx();
				eCoefMatrix.replaceChild(eRowIdx, eIdx);
			}
			if(eColIdx != null && isColumnMajor){
				eIdx = createRowIdx();
				eCoefMatrix.replaceChild(eColIdx, eIdx);
			}
			XMLUtil.removeAllChildren(eStart);
			XMLUtil.removeAllChildren(eValue);
			XMLUtil.removeAllChildren(eIdx);
			
			if(startIndexesMultiplicity == null){
				for(int i = startIndexesBegin; i <= startIndexesEnd; i++){
					eStart.appendChild(createEl(startIndexes[i]));
				}
			}
			else if(startIndexesMultiplicity != null && startIndexesIncrement == null){
				for(int i = startIndexesBegin; i <= startIndexesEnd; i++){
					eStart.appendChild(createEl(startIndexes[i], startIndexesMultiplicity[i], 0));
				}
			}
			else{
				for(int i = startIndexesBegin; i <= startIndexesEnd; i++){
					eStart.appendChild(createEl(startIndexes[i], startIndexesMultiplicity[i], startIndexesIncrement[i]));
				}				
			}
			
			if(nonzeroIndexesMultiplicity == null){
				for(int i = nonzeroIndexesBegin; i <= nonzeroIndexesEnd; i++){
					eIdx.appendChild(createEl(nonzeroIndexes[i]));
				}
			}
			else if(nonzeroIndexesMultiplicity != null && nonzeroIndexesIncrement == null){
				for(int i = nonzeroIndexesBegin; i <= nonzeroIndexesEnd; i++){
					eIdx.appendChild(createEl(nonzeroIndexes[i], nonzeroIndexesMultiplicity[i], 0));
				}
			}
			else{
				for(int i = nonzeroIndexesBegin; i <= nonzeroIndexesEnd; i++){
					eIdx.appendChild(createEl(nonzeroIndexes[i], nonzeroIndexesMultiplicity[i], nonzeroIndexesIncrement[i]));
				}				
			}
			
			if(nonzeroValuesMultiplicity == null){
				for(int i = nonzeroValuesBegin; i <= nonzeroValuesEnd; i++){
					eValue.appendChild(createEl(nonzeroValues[i]));
				}
			}
			else if(nonzeroValuesMultiplicity != null && nonzeroValuesIncrement == null){
				for(int i = nonzeroValuesBegin; i <= nonzeroValuesEnd; i++){
					eValue.appendChild(createEl(nonzeroIndexes[i], nonzeroValuesMultiplicity[i], 0));
				}
			}
			else{
				for(int i = nonzeroValuesBegin; i <= nonzeroIndexesEnd; i++){
					eValue.appendChild(createEl(nonzeroValues[i], nonzeroValuesMultiplicity[i], nonzeroValuesIncrement[i]));
				}				
			}
			eCoefMatrix.setAttribute("numberOfValues", numberOfValues+"");
		}
		catch(Exception e){
			e.printStackTrace();
			return false;
		}
		return true;
	}//setLinearConstraintCoefficients

   	/**
	 * Set the quadratic coefficient terms related elements. If the elements (e.g. the required elements) are
	 * already there, it will reset the them. If the elements are not there (e.g. the optional elements),
	 * it will add them.
	 *
	 * </p>
   	 * 
   	 * @param numberOfQuadraticTerms holds the number of quadratic terms. 
   	 * @param rowIndexes holds an integer array of row indexes of all the quadratic terms. 
	 * A negative integer corresponds to an objective row, e.g. -1 for 1st objective and -2 for 2nd.
   	 * @param varOneIndexes holds an integer array of the first varialbe indexes of all the quadratic terms.
   	 * @param varTwoIndexes holds an integer array of the second varialbe indexes of all the quadratic terms.
   	 * @param coefficients holds a double array all the quadratic term coefficients. If null all coefficient values are 1. 
   	 * @param begin holds the begin index of all the arrays to copy from (usually = 0). 
   	 * @param end holds the end index of all the arrays to copy till (usually = array length -1).
   	 * @return whether the quadratic terms are set successfully.  
   	 */
	public boolean setQuadraticTerms(int numberOfQuadraticTerms, 
			int[] rowIndexes, int[] varOneIndexes, int[] varTwoIndexes, double[] coefficients,
			int begin, int end){
		try{
			if(end - begin + 1 != numberOfQuadraticTerms
			|| (rowIndexes == null || rowIndexes.length < numberOfQuadraticTerms)
			|| (varOneIndexes == null || varOneIndexes.length < numberOfQuadraticTerms)
			|| (coefficients != null && coefficients.length < numberOfQuadraticTerms)){
				return false;
			}
			Node nodeRef = null;
			Element eQuadraticCoef = (Element)XMLUtil.findChildNode(m_eInstanceData, "quadraticCoefficients");
			if(eQuadraticCoef == null){
				eQuadraticCoef = createQuadraticCoefficients(numberOfQuadraticTerms);
				nodeRef = XMLUtil.findChildNode(m_eInstanceData, "linearConstraintCoefficients");
				if(nodeRef == null){
					nodeRef = XMLUtil.findChildNode(m_eInstanceData, "constraints");
				}
				if(nodeRef == null){
					nodeRef = XMLUtil.findChildNode(m_eInstanceData, "objectives");
				}
				if(nodeRef == null){
					nodeRef = XMLUtil.findChildNode(m_eInstanceData, "variables");
				}
				nodeRef = nodeRef.getNextSibling();
				m_eInstanceData.insertBefore(eQuadraticCoef, nodeRef);
			}
			XMLUtil.removeAllChildren(eQuadraticCoef);
			for(int i = begin; i <= end; i++){
				Element eQuadraticTerm = createQTerm(rowIndexes[i], 
						varOneIndexes[i], 
						varTwoIndexes[i], 
						coefficients==null?1:coefficients[i]);
				eQuadraticCoef.appendChild(eQuadraticTerm);
			}
		}
		catch(Exception e){
			e.printStackTrace();
			return false;
		}
		return true;
	}//setQuadraticTerms
	
	/**
	 * Add an nl node. It holds a nonlinear expression tree.  
	 * 
	 * @param tokenizedExpression holds the expression tokenized in a string vector in either postfix, prefix, or infix.
	 * The operator name in each token has to be exactly the same as the name specified in the OSnL Schema. 
	 * The operator name in the token may be followed (without space) by a sequence of ":atrributeValue" and end with
	 * [i] to indicate the number of arguments the operator can take if the operator's type is indefinite. 
	 * The attributes specified have to follow the sequence in the OSnL schema.  
	 * If one attribute is specified, all attributes have to be specified together. If an attribute 
	 * are missing, an empty string has to be in place. Two alternative exception can be allowed for variable 
	 * and number. A number can just a a numeric value and the variable can take the form Xi where i is the 
	 * integer index of capital letter X. 
	 * @param type whether the expression is in postfix, prefix or infix
	 * @param rowIdx holds the row number the nl node corresponds to. If rowIdx is negative, it corresponds to an objective.  
	 * @param start holds the index of the tokenizedExpression to start processing. 
	 * @param end holds the index of the tokenizedExpression to finish processing. 
	 * @return whether nl node addition is successful.
	 */
	public boolean addNlNode(Vector tokenizedExpression, String type, int rowIdx, int start, int end){
		try{
			Node nodeRef = null;
			Element eNonlinearExpressions = (Element)XMLUtil.findChildNode(m_eInstanceData, "nonlinearExpressions");
			if(eNonlinearExpressions == null){
				eNonlinearExpressions = createNonlinearExpressions();
				nodeRef = XMLUtil.findChildNode(m_eInstanceData, "linearConstraintCoefficients");
				if(nodeRef == null)
					nodeRef = XMLUtil.findChildNode(m_eInstanceData, "constraints");
				if(nodeRef == null)
					nodeRef = XMLUtil.findChildNode(m_eInstanceData, "objectives");
				if(nodeRef == null)
					nodeRef = XMLUtil.findChildNode(m_eInstanceData, "variables");
				nodeRef = nodeRef.getNextSibling();
				m_eInstanceData.insertBefore(eNonlinearExpressions, nodeRef);
			}						
			Element eNl = createNl(rowIdx);
			eNonlinearExpressions.appendChild(eNl);			
			OSExpressionTree eTree = new OSExpressionTree(tokenizedExpression, type, start, end);
			Element eExpressionRoot = eTree.getDomTreeRoot(m_document);
			eNl.appendChild(eExpressionRoot);
			Vector<Element> vElements = XMLUtil.getChildElementsByTagName(eNonlinearExpressions, "nl");
			int iNl = vElements==null?0:vElements.size();
			eNonlinearExpressions.setAttribute("numberOfNonlinearExpressions", iNl+"");
		}
		catch(Exception e){
			e.printStackTrace();
			return false;
		}
		return true;
	}//addNlNode

	/**
	 * Add an nl node. It holds a nonlinear expression tree.  
	 * 
	 * @param expressionTree holds the os expression of the nl node. 
	 * @param rowIdx holds the row number the nl node corresponds to. If rowIdx is negative, it corresponds to an objective.  
	 * @return whether nl node addition is successful.
	 */
	public boolean addNlNode(OSExpressionTree expressionTree, int rowIdx){
		try{
			Node nodeRef = null;
			Element eNonlinearExpressions = (Element)XMLUtil.findChildNode(m_eInstanceData, "nonlinearExpressions");
			if(eNonlinearExpressions == null){
				eNonlinearExpressions = createNonlinearExpressions();
				nodeRef = XMLUtil.findChildNode(m_eInstanceData, "quadraticCoefficients");
				if(nodeRef == null)
					nodeRef = XMLUtil.findChildNode(m_eInstanceData, "linearConstraintCoefficients");
				if(nodeRef == null)
					nodeRef = XMLUtil.findChildNode(m_eInstanceData, "constraints");
				if(nodeRef == null)
					nodeRef = XMLUtil.findChildNode(m_eInstanceData, "objectives");
				if(nodeRef == null)
					nodeRef = XMLUtil.findChildNode(m_eInstanceData, "variables");
				nodeRef = nodeRef.getNextSibling();
				m_eInstanceData.insertBefore(eNonlinearExpressions, nodeRef);
			}						
			Element eNl = createNl(rowIdx);
			eNonlinearExpressions.appendChild(eNl);			
			Element eExpressionRoot = expressionTree.getDomTreeRoot(m_document);
			eNl.appendChild(eExpressionRoot);
			Vector<Element> vElements = XMLUtil.getChildElementsByTagName(eNonlinearExpressions, "nl");
			int iNl = vElements==null?0:vElements.size();
			eNonlinearExpressions.setAttribute("numberOfNonlinearExpressions", iNl+"");
		}
		catch(Exception e){
			e.printStackTrace();
			return false;
		}
		return true;
	}//addNlNode

	/**
	 * Add a simulation node.   
	 *
	 * @param name holds the name of the simulation
	 * @param uri holds the uri address of the simulation
	 * @param osslWriter holds the the root element of ossl. 
	 * @return whether simulation node addition is successful.
	 */
	public boolean addSimulation(String name, String uri, OSsLWriter osslWriter){
		try{
			Node nodeRef = null;
			Element eSimulations = (Element)XMLUtil.findChildNode(m_eInstanceData, "simulations");
			if(eSimulations == null){
				eSimulations = createSimulations();
				nodeRef = XMLUtil.findChildNode(m_eInstanceData, "xmlData");
				m_eInstanceData.insertBefore(eSimulations, nodeRef);
			}
			Element eSimulation = createSimulation(name, uri, osslWriter);
			eSimulations.appendChild(eSimulation);
		}
		catch(Exception e){
			e.printStackTrace();
			return false;
		}
		return true;
	}//addSimulation

	/**
	 * Add a userFunction node.   
	 *
	 * @param name holds the name of the userFunction
	 * @param numArg holds the number of arguments of the user function
	 * @param tokenizedExpression holds the expression tokenized in a string vector in either postfix, prefix, or infix.
	 * The operator name in each token has to be exactly the same as the name specified in the OSnL Schema. 
	 * The operator name in the token may be followed (without space) by a sequence of ":atrributeValue" and end with
	 * [i] to indicate the number of arguments the operator can take if the operator's type is indefinite. 
	 * The attributes specified have to follow the sequence in the OSnL schema.  
	 * If one attribute is specified, all attributes have to be specified together. If an attribute 
	 * are missing, an empty string has to be in place. Two alternative exception can be allowed for variable 
	 * and number. A number can just a a numeric value and the variable can take the form Xi where i is the 
	 * integer index of capital letter X. 
	 * @param type whether the expression is in postfix, prefix or infix
	 * @param start holds the index of the tokenizedExpression to start processing. 
	 * @param end holds the index of the tokenizedExpression to finish processing. 
	 * @return whether userFunction node addition is successful.
	 */
	public boolean addUserFunction(String name, int numArg, Vector tokenizedExpression, String type, int start, int end){
		try{
			Node nodeRef = null;
			Element eUserFunctions = (Element)XMLUtil.findChildNode(m_eInstanceData, "userFunctions");
			if(eUserFunctions == null){
				eUserFunctions = createUserFunctions();
				nodeRef = XMLUtil.findChildNode(m_eInstanceData, "simulations");
				if(nodeRef == null)
					nodeRef = XMLUtil.findChildNode(m_eInstanceData, "xmlData");
				m_eInstanceData.insertBefore(eUserFunctions, nodeRef);
			}
			Element eUserFunction = createUserFunction(name, numArg);
			eUserFunctions.appendChild(eUserFunction);
			OSExpressionTree eTree = new OSExpressionTree(tokenizedExpression, type, start, end);
			Element eExpressionRoot = eTree.getDomTreeRoot(m_document);
			eUserFunction.appendChild(eExpressionRoot);
		}
		catch(Exception e){
			e.printStackTrace();
			return false;
		}
		return true;
	}//addUserFunction

	/**
	 * Add a userFunction node.   
	 *
	 * @param name holds the name of the userFunction
	 * @param numArg holds the number of arguments of the user function
	 * @param expressionTree holds the os expression of the nl node. 
	 * @return whether userFunction node addition is successful.
	 */
	public boolean addUserFunction(String name, int numArg, OSExpressionTree expressionTree){
		try{
			Node nodeRef = null;
			Element eUserFunctions = (Element)XMLUtil.findChildNode(m_eInstanceData, "userFunctions");
			if(eUserFunctions == null){
				eUserFunctions = createUserFunctions();
				nodeRef = XMLUtil.findChildNode(m_eInstanceData, "simulations");
				if(nodeRef == null)
					nodeRef = XMLUtil.findChildNode(m_eInstanceData, "xmlData");
				m_eInstanceData.insertBefore(eUserFunctions, nodeRef);
			}
			Element eUserFunction = createUserFunction(name, numArg);
			eUserFunctions.appendChild(eUserFunction);
			
			Element eExpressionRoot = expressionTree.getDomTreeRoot(m_document);
			eUserFunction.appendChild(eExpressionRoot);
		}
		catch(Exception e){
			e.printStackTrace();
			return false;
		}
		return true;
	}//addUserFunction

	/**
	 * Set the xmldData related elements. If the elements (e.g. the required elements) are
	 * already there, it will reset the them. If the elements are not there (e.g. the optional elements),
	 * it will add them. xmlDataElement can either have a root of &lt;xmlData&gt; or not. The method will add
	 * the root if the root is not there. 
	 *
	 * </p>
	 *
	 * @param xmlDataElement holds the xmlData element. xmlDataElement can either have a root 
	 * of &lt;xmlData&gt; or not. The method will add the root if the root is not there. 
	 * @return whether the xmldData construction is successful.
	 */
	public boolean setXMLData(Element xmlDataElement){
		try{
			Element eCopy = (Element)m_document.importNode(xmlDataElement, true);
			Element eXMLData;
			if(!eCopy.getNodeName().equals("xmlData")){
				eXMLData = createXMLData();
				eXMLData.appendChild(eCopy.cloneNode(true));
			}
			else{
				eXMLData = (Element)eCopy.cloneNode(true);
			}
			XMLUtil.removeChildrenByName(m_eInstanceData, "xmlData");
			m_eInstanceData.appendChild(eXMLData);

		}
		catch(Exception e){
			e.printStackTrace();
			return false;
		}
		return true;
	}//setXMLData

	/**
	 * Set the xmldData related elements. If the elements (e.g. the required elements) are
	 * already there, it will reset the them. If the elements are not there (e.g. the optional elements),
	 * it will add them. xmlDataString can either have a root of &lt;xmlData&gt; or not. The method will add
	 * the root if the root is not there. 
	 *
	 * </p>
	 *
	 * @param xmlDataString holds the xmlData element. xmlDataElement can either have a root 
	 * of &lt;xmlData&gt; or not. The method will add the root if the root is not there. 
	 * @return whether the xmldData construction is successful.
	 */
	public boolean setXMLData(String xmlDataString){
		try{
			Element eXMLData = (Element)(XMLUtil.parseStringUsingDOM(xmlDataString, false).getFirstChild());
			Element eCopy = (Element)m_document.importNode(eXMLData, true);			
			setXMLData(eCopy);
		}
		catch(Exception e){
			e.printStackTrace();
			return false;
		}
		return true;
	}//setXMLData


	/**
	 * Create the OSiL root element and its most basic required structure.
	 *
	 * </p>
	 *
	 * @return the OSiL element.
	 */
	protected Element createOSiLRoot(){
		Element eOSiL = XMLUtil.createOSxLRootElement(m_document, "osil");
		m_eInstanceHeader = createInstanceHeader();
		eOSiL.appendChild(m_eInstanceHeader);
		m_eInstanceData = createInstanceData();
		eOSiL.appendChild(m_eInstanceData);
		return eOSiL;
	}//createOSiLRoot

	/**
	 * Create the instanceHeader element and its most basic required structure.
	 *
	 * </p>
	 * @return the instanceHeader element.
	 */
	protected Element createInstanceHeader(){
		Element eInstanceHeader = m_document.createElement("instanceHeader");
		
		return eInstanceHeader;
	}//createInstanceHeader

	/**
	 * Create the instanceData element and its most basic required structure.
	 *
	 * </p>
	 *
	 * @return the instanceData element.
	 */
	protected Element createInstanceData(){
		Element eInstanceData = m_document.createElement("instanceData");
		
		Element eVariables = createVariables(0);
		
		eInstanceData.appendChild(eVariables);
		
		return eInstanceData;
	}//createInstanceData

	/**
	 * Create the name element and its most basic required structure.
	 *
	 * </p>
	 *
	 * @param name holds the value of the name of the OSiL optimization instance.
	 * @return the source element.
	 */
	protected Element createName(String name){
		Element eSource = m_document.createElement("name");
		
		eSource.appendChild(m_document.createTextNode(name));
		
		return eSource;
	}//createName

	/**
	 * Create the source element and its most basic required structure.
	 *
	 * </p>
	 *
	 * @param source holds the value of the source of the OSiL optimization instance.
	 * @return the source element.
	 */
	protected Element createSource(String source){
		Element eSource = m_document.createElement("source");
		
		eSource.appendChild(m_document.createTextNode(source));
		
		return eSource;
	}//createSource

	/**
	 * Create the description element and its most basic required structure.
	 *
	 * </p>
	 *
	 * @param description holds the value of the description of the OSiL optimization instance.
	 * @return the description element.
	 */
	protected Element createDescription(String description){
		Element eDescription = m_document.createElement("description");
		
		eDescription.appendChild(m_document.createTextNode(description));
		
		return eDescription;
	}//createDescription

	/**
	 * Create the variables element and its most basic required structure.
	 *
	 * </p>
	 *
	 * @param number holds the number of variables.
	 * @return the variables element
	 */
	protected Element createVariables(int number){
		Element eVariables = m_document.createElement("variables");
		eVariables.setAttribute("numberOfVariables", number+"");
		
		return eVariables;
	}//createVariables

	/**
	 * Create the var element and its most basic required structure.
	 *
	 * </p>
	 *
	 * @return the var element
	 */
	protected Element createVar(){
		Element eVar = m_document.createElement("var");
		
		return eVar;
	}//createVar
	
	/**
	 * Create the objectives element and its most basic required structure.
	 *
	 * </p>
	 *
	 * @param number holds the number of objective functions. 
	 * @return the objectives element
	 */
	protected Element createObjectives(int number){
		Element eObjectives = m_document.createElement("objectives");
		eObjectives.setAttribute("numberOfObjectives", number+"");
		return eObjectives;
	}//createObjectives

	/**
	 * Create the obj element and its most basic required structure.
	 *
	 * </p>
	 * @param isMin holds whether the objective is minimization or not
	 * @param numberOfObjCoef holds the number of objective coefficients.
	 * @return the obj element
	 */
	protected Element createObj(boolean isMin, int numberOfObjCoef){
		Element eObj = m_document.createElement("obj");
		eObj.setAttribute("maxOrMin", (isMin)?"min":"max");
		eObj.setAttribute("numberOfObjCoef", numberOfObjCoef+"");
		return eObj;
	}//createObj
	
	/**
	 * Create the coef element and its most basic required structure.
	 *
	 * </p>
	 * @param coefValue holds objective coefficient value. 
	 * @param coefIndex holds variable index of the objective coefficient. 
	 * @return the obj element
	 */
	protected Element createCoef(double coefValue, int coefIndex){
		Element eCoef = m_document.createElement("coef");
		eCoef.setAttribute("idx", coefIndex + "");
		eCoef.appendChild(m_document.createTextNode(coefValue+""));
		return eCoef;
	}//createCoef

	/**
	 * Create the constraints element and its most basic required structure.
	 *
	 * </p>
	 *
	 * @param number holds the number of constraints. 
	 * @return the constraints element
	 */
	protected Element createConstraints(int number){
		Element eConstraints = m_document.createElement("constraints");
		eConstraints.setAttribute("numberOfConstraints", number+"");
		return eConstraints;
	}//createConstraints

	/**
	 * Create the con element and its most basic required structure.
	 *
	 * </p>
	 *
	 * @return the con element
	 */
	protected Element createCon(){
		Element eCon = m_document.createElement("con");
		
		return eCon;
	}//createCon
	
	/**
	 * Create the sparse coefficient matrix element and its most basic required structure.
	 *
	 * </p>
	 *
	 * @param isColumnMajor holds whether the sparse coefficient matrix holding the linear data is stored
	 * @param numberOfValues holds the number of nonzero values in the coefficient matrix.   
	 * by column. If false, the sparse  coefficient matrix is stored by row.
	 * @return the sparse coefficient matrix element.
	 */
	protected Element createLinearConstraintCoefficients(boolean isColumnMajor, int numberOfValues){
		Element eCoefMatrix = m_document.createElement("linearConstraintCoefficients");
		eCoefMatrix.setAttribute("numberOfValues", numberOfValues+"");
		
		Element eStart = createStart();
		Element eRowIdx =  createRowIdx();
		Element eColIdx = createColIdx();
		Element eValue = createValue();
		
		eCoefMatrix.appendChild(eStart);
		if(isColumnMajor){
			eCoefMatrix.appendChild(eRowIdx);
		}
		else{
			eCoefMatrix.appendChild(eColIdx);
		}
		eCoefMatrix.appendChild(eValue);
		
		return eCoefMatrix;
	}//createLinearConstraintCoefficients

	/**
	 * Create the quadraticCoefficients element and its most basic required structure.
	 *
	 * </p>
	 *
	 * @param numberOfQuadraticTerms holds the number of QuadraticTerms in quadraticCoefficients. 
	 * @return the quadraticCoefficients element
	 */
	protected Element createQuadraticCoefficients(int numberOfQuadraticTerms){
		Element eQuadraticCoef = m_document.createElement("quadraticCoefficients");
		eQuadraticCoef.setAttribute("numberOfQuadraticTerms", numberOfQuadraticTerms+"");
		return eQuadraticCoef;
	}//createQuadraticCoefficients

	/**
	 * Create the qTerm element and its most basic required structure.
	 *
	 * </p>
	 *
	 * @return the qTerm element
	 */
	protected Element createQTerm(int idx, int idxOne, int idxTwo, double coef){
		Element eQTerm = m_document.createElement("qTerm");
		eQTerm.setAttribute("idx", idx+"");
		eQTerm.setAttribute("idxOne", idxOne+"");
		eQTerm.setAttribute("idxTwo", idxTwo+"");
		if(coef != 1) eQTerm.setAttribute("coef", coef+"");
		return eQTerm;
	}//createQTerm
	
	/**
	 * Create the el element and its most basic required structure.
	 *
	 * </p>
	 *
	 * @param value holds the double value of the el element
	 * @return the el element.
	 */
	protected Element createEl(double value){
		Element eEl = m_document.createElement("el");
		
		eEl.appendChild(m_document.createTextNode(value+""));
		
		return eEl;
	}//createEl(double)

	/**
	 * Create the el element with multiplicity and increment attricutes and its most basic required structure.
	 *
	 * </p>
	 *
	 * @param value holds the double value of the el element
	 * @param multiplicity holds the multiplicity (repetition) of the el element. 
	 * @param increment holds the increment of the value in the el element.  
	 * @return the el element.
	 */
	protected Element createEl(double value, int multiplicity, double increment){
		Element eEl = m_document.createElement("el");
		if(increment != 0.0) eEl.setAttribute("incr", increment+"");
		if(multiplicity > 1) eEl.setAttribute("mult", multiplicity+"");
		
		eEl.appendChild(m_document.createTextNode(value+""));
		
		return eEl;
	}//createEl(double, int, double)

	/**
	 * Create the el element and its most basic required structure.
	 *
	 * </p>
	 *
	 * @param value holds the integer value of the el element
	 * @return the el element.
	 */
	protected Element createEl(int value){
		Element eEl = m_document.createElement("el");
		
		eEl.appendChild(m_document.createTextNode(value+""));
		
		return eEl;
	}//createEl(int)

	/**
	 * Create the el element with multiplicity and increment attricutes and its most basic required structure.
	 *
	 * </p>
	 *
	 * @value holds the double value of the el element
	 * @param multiplicity holds the multiplicity (repetition) of the el element. 
	 * @param increment holds the increment of the value in the el element.  
	 * @return the el element.
	 */
	protected Element createEl(int value, int multiplicity, double increment){
		Element eEl = m_document.createElement("el");
		if(increment != 0.0) eEl.setAttribute("incr", increment+"");
		if(multiplicity > 1) eEl.setAttribute("mult", multiplicity+"");
		
		eEl.appendChild(m_document.createTextNode(value+""));
		
		return eEl;
	}//createEl(int, int, double)
	
	/**
	 * Create the sparse coefficient matrix value element and its most basic required structure.
	 *
	 * </p>
	 *
	 * @return the value element.
	 */
	protected Element createValue(){
		Element eValue = m_document.createElement("value");
		
		return eValue;
	}//createValue

	/**
	 * Create the base64BinaryData element and its most basic required structure.
	 *
	 * </p>
	 *
	 * @param numericType holds the data type converted to base 64 (e.g. double or int).
	 * @param sizeOf holds the number of byes used in representing each number of the
	 * indicated numeric type.
	 * @return the base64BinaryData element or null if the parameter values are not proper.
	 */
	protected Element createBase64BinaryData(String numericType, int sizeOf){
		String[] msNumericType = {"double", "float", "decimal", "int", "long", "string"};
		boolean bNumericType = false;
		for(int i = 0; i < msNumericType.length; i++){
			if(msNumericType[i].equals(numericType)){
				bNumericType = true;
			}
		}
		if(!bNumericType || sizeOf <= 0){
			return null;
		}
		
		Element eBase64BinaryData = m_document.createElement("base64BinaryData");
		eBase64BinaryData.setAttribute("numericType", numericType);
		eBase64BinaryData.setAttribute("sizeOf", sizeOf+"");
		
		return eBase64BinaryData;
	}//createBase64BinaryData
	
	/**
	 * Create the sparse coefficient matrix start element and its most basic required structure.
	 *
	 * </p>
	 *
	 * @return the start element.
	 */
	protected Element createStart(){
		Element eStart = m_document.createElement("start");
		
		return eStart;
	}//createStart
	
	/**
	 * Create the sparse coefficient matrix rowIdx element and its most basic required structure.
	 *
	 * </p>
	 *
	 * @return the rowIdx element.
	 */
	protected Element createRowIdx(){
		Element eRowIdx = m_document.createElement("rowIdx");
		
		return eRowIdx;
	}//createRowIdx
	
	/**
	 * Create the sparse coefficient matrix colIdx element and its most basic required structure.
	 *
	 * </p>
	 *
	 * @return the colIdx element.
	 */
	protected Element createColIdx(){
		Element eColIdx = m_document.createElement("colIdx");
		
		return eColIdx;
	}//createColIdx
	
	/**
	 * Create the nonlinear expressions element and its most basic required structure.
	 *
	 * </p>
	 *
	 * @return the nonlinearExpressions element.
	 */
	protected Element createNonlinearExpressions(){
		Element eNonlinearExpressions = m_document.createElement("nonlinearExpressions");
		
		return eNonlinearExpressions;
	}//createNonlinearExpressions
	
	/**
	 * Create the nl element and its most basic required structure.
	 *
	 * </p>
	 *
	 * @param rowIdx holds the row number the nl node corresponds to. If rowIdx is negative, it corresponds to an objective. 
	 * @return the nl element.
	 */
	protected Element createNl(int rowIdx){
		Element eNl = m_document.createElement("nl");
		eNl.setAttribute("idx", rowIdx+"");
		
		return eNl;
	}//createNl

	/**
	 * Create the userFunctions and its most basic required structure.
	 *
	 * </p>
	 *
	 * @return the userFunctions element.
	 */
	protected Element createUserFunctions(){
		Element eUserFunctions = m_document.createElement("userFunctions");
		
		return eUserFunctions;
	}//createUserFunctions
	
	/**
	 * Create the userFunction and its most basic required structure.
	 *
	 * </p>
	 *
	 * @param name holds the name of the userFunction
	 * @param numArg holds the number of arguments of the user function
	 * @return the userFunction element.
	 */
	protected Element createUserFunction(String name, int numArg){
		Element eUserFunction = m_document.createElement("userFunction");
		eUserFunction.setAttribute("name", name);
		eUserFunction.setAttribute("numArg", numArg+"");
		
		return eUserFunction;
	}//createUserFunction

	/**
	 * Create the simulations and its most basic required structure.
	 *
	 * </p>
	 *
	 * @return the simulations element.
	 */
	protected Element createSimulations(){
		Element eSimulations = m_document.createElement("simulations");
		
		return eSimulations;
	}//createSimulations
	
	/**
	 * Create the simulation and its most basic required structure.
	 *
	 * </p>
	 *
	 * @param name holds the name of the simulation
	 * @param uri holds the uri address of the simulation
	 * @param osslWriter holds the the root element of ossl. 
	 * @return the simulation element.
	 */
	protected Element createSimulation(String name, String uri, OSsLWriter osslWriter){
		Element eSimulation = m_document.createElement("simulation");
		eSimulation.setAttribute("name", name);
		
		Element eURI = createURI(uri);
		eSimulation.appendChild(eURI);
		
		Element eOSsL = createOSsL(osslWriter);
		eSimulation.appendChild(eOSsL);
		
		return eSimulation;
	}//createSimulation
	
	/**
	 * Create the uri and its most basic required structure.
	 *
	 * </p>
	 *
	 * @param value holds the uri value. 
	 * @return the uri element.
	 */
	protected Element createURI(String value){
		Element eURI = m_document.createElement("uri");
		eURI.setAttribute("value", value);
		
		return eURI;
	}//createURI

	/**
	 * Create the OSsL and its most basic required structure.
	 *
	 * </p>
	 *
	 * @param osslWriter holds the the root element of ossl. 
	 * @return the OSsL element.
	 */
	protected Element createOSsL(OSsLWriter osslWriter){
		Element eOSsL = m_document.createElement("ossl");
		for(int k = 0; k <=1; k++){
			Element oldInputOutput = null;
			Element newInputOutput = null;
			if(k == 0) oldInputOutput = osslWriter.m_eInput;
			else oldInputOutput = osslWriter.m_eOutput;
			if( oldInputOutput != null){
				if(k == 0) newInputOutput = m_document.createElement("input");
				else newInputOutput = m_document.createElement("output");
				eOSsL.appendChild(newInputOutput);
				NodeList nl = oldInputOutput.getElementsByTagName("el");
				for(int i = 0; i < (nl==null?0:nl.getLength()); i++){
					Element oldEl = (Element)nl.item(i);
					Element newEl = m_document.createElement("el");
					String sName = oldEl.getAttribute("name");
					newEl.setAttribute("name", sName);
					String sType = oldEl.getAttribute("type");
					if(sType != null && sType.length() > 0)
						newEl.setAttribute("type", sType);
					String sValue = XMLUtil.getElementValue(oldEl);
					if(sValue != null && sValue.length() > 0){
						newEl.appendChild(m_document.createTextNode(sValue));
					}
					newInputOutput.appendChild(newEl);
				}
			}			
		}
		return eOSsL;
	}//createOSsL

	/**
	 * Create the xmlData and its most basic required structure.
	 *
	 * </p>
	 *
	 * @return the xmlData element.
	 */
	protected Element createXMLData(){
		Element eXMLData = m_document.createElement("xmlData");
		
		return eXMLData;
	}//createXMLData

	/**
	 * main for test purposes.
	 *
	 * </p>
	 *
	 * @param argv command line arguments.
	 */
	public static void main(String[] argv){
		OSiLWriter osilWriter = new OSiLWriter();
		//String fName = "xml/osxl/osil_2.xml";
		//boolean bSet = true;
		
		if(!osilWriter.setInstanceHeader("name1", "source1", "description1")) System.out.println(3);
		if(!osilWriter.setInstanceHeader("name2", "revised source", "description1"))System.out.println(4);
		
		String[] msVariableNames1 = {"v1", "v2"};
		double[] mdVariableLbs1 = {0.0, 1.0};
		double[] mdVariableUbs1 = {10.0, 20.0};
		char[] mcVariableTypes1 = {'C', 'I'};
		if(!osilWriter.setVariables(2, msVariableNames1, mdVariableLbs1, mdVariableUbs1, mcVariableTypes1, null, null)) System.out.println(5);
		//String[] msVariableNames2 = {"v3", "v4", "v5"};
		double[] mdVariableLbs2 = {2.0, 3.0, 4.0};
		double[] mdVariableUbs2 = {30.0, 40.0, 50.0};
		char[] mcVariableTypes2 = {'B', 'C', 'I'};
		if(!osilWriter.setVariables(3, null, mdVariableLbs2, mdVariableUbs2, mcVariableTypes2, null, null))System.out.println(6);
		
		double[] mdNonz1 = {1.0, 2.0};
		int[] miNonzIdx1 = {1, 2};
		int[] miStartIdx1 = {0, 2, 3};
		if(!osilWriter.setLinearConstraintCoefficients(2, true, mdNonz1, miNonzIdx1, miStartIdx1)) System.out.println(7);
		double[] mdNonz2 = {10.0, 20.0};
		int[] miNonzIdx2 = {10, 20};
		int[] miStartIdx2 = {0, 20, 30};
		if(!osilWriter.setLinearConstraintCoefficients(2, true, mdNonz2, miNonzIdx2, miStartIdx2)) System.out.println(8);
//		double[] mdNonz3 = {100.0, 200.0};
//		int[] miNonz3Mult = {2, 3};
//		double[] mdNonz3Incr = {0, 1};
//		int[] miNonzIdx3 = {100, 200};
//		int[] miNonzIdx3Mult = {2, 3};
//		int[] miNonzIdx3Incr = {0, 1};
//		int[] miStartIdx3 = {200, 300};
//		int[] miStartIdx3Mult = {2, 3};
//		int[] mdStarIdx3Incr = {0, 1};
		//if(!osilWriter.setLinearConstraintCoefficients(5, true, mdNonz3, miNonz3Mult, mdNonz3Incr, miNonzIdx3, miNonzIdx3Mult, miNonzIdx3Incr, miStartIdx3, miStartIdx3Mult, mdStarIdx3Incr)) System.out.println(8.1);

		
		String[] msConstraintNames1 = {"c1", "c2"};
		double[] mdConstraintLhs1 = {0.0, 1.0};
		double[] mdConstraintRhs1 = {10.0, 20.0};
		if(!osilWriter.setConstraints(2, msConstraintNames1, mdConstraintLhs1, mdConstraintRhs1, null)) System.out.println(9);
		String[] msConstraintNames2 = {"c3", "c4", "c5"};
		double[] mdConstraintLhs2 = {2.0, 3.0, 4.0};
		double[] mdConstraintRhs2 =null;// {30.0, 40.0, 50.0};
		if(!osilWriter.setConstraints(3, msConstraintNames2, mdConstraintLhs2, mdConstraintRhs2, null)) System.out.println(10);
		
		double[] mdObjectiveCoefValues1 = {0.0, 1.0};
		int[] mdObjectiveCoefIndexes1 = {0, 1};
		if(!osilWriter.addObjective("name1", false, 1, 1, mdObjectiveCoefValues1, mdObjectiveCoefIndexes1)) System.out.println(11);
		double[] mdObjectiveCoefValues2 = {2.0, 3.0};
		int[] mdObjectiveCoefIndexes2 = {5, 6};
		if(!osilWriter.addObjective("name2", true, 2, 2, mdObjectiveCoefValues2, mdObjectiveCoefIndexes2)) System.out.println(12);

		if(!osilWriter.addConstraint("addCon1", Double.NEGATIVE_INFINITY, 8, 0)) System.out.println(13);
		if(!osilWriter.addVariable("addVar1", 0, 8, 'C', 3, null)) System.out.println(13);
		Vector<String> vToken = new Vector<String>();
		vToken.add("2"); vToken.add("plus"); vToken.add("3");
		if(!osilWriter.addNlNode(vToken, "infix", 0, 0, vToken.size()-1)) System.out.println(14);
		Vector<String> vToken2 = new Vector<String>();
		vToken2.add("arg:0"); vToken2.add("plus"); vToken2.add("3"); vToken2.add("times"); vToken2.add("arg:1");		
		if(!osilWriter.addUserFunction("myF", 2, vToken2, "infix", 0, vToken2.size()-1)) System.out.println(15);

		OSsLWriter osslWriter = new OSsLWriter();
		String[] msInputNames = {"a", "b"};
		String[] msInputTypes = null;//{"", "link"};
		String[] msInputValues = {"aaa", "http://www.google.com"};	
		osslWriter.setInput(msInputNames, msInputTypes, msInputValues);
		String[] msOutputNames = {"c", "d"};
		String[] msOutputTypes = {"", "link"};
		String[] msOutputValues = {"ccc", "http://www.google.com"};		
		osslWriter.setOutput(msOutputNames, msOutputTypes, msOutputValues);
		if(!osilWriter.addSimulation("myS", "www.yahoo.com", osslWriter)) System.out.println(15);
		
		Document document =  XMLUtil.createNewDocument();
		Element eXMLData = document.createElement("xmlData");
		Element eABC = document.createElement("abc");
		eXMLData.appendChild(eABC);
		osilWriter.setXMLData(eXMLData);
		Text text = document.createTextNode("1234");
		eABC.appendChild(text);
		osilWriter.setXMLData(eABC);

		String sXML = "<jun><ma></ma></jun>";
		osilWriter.setXMLData(sXML);
		sXML = "<xmlData><ma><jun>123</jun></ma></xmlData>";
		osilWriter.setXMLData(sXML);

		//osilWriter.writeToFile(fName);
		//System.out.println(IOUtil.fileToString(fName));
		osilWriter.writeToStandardOutput();
		//System.out.println(osilWriter.writeToString());
	}//main
		
}//class OSiLWriter
