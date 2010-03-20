/**
 * @(#)FMLWriter 1.0 03/14/2004
 *
 * Copyright (c) 2004
 */
package org.optimizationservices.oscommon.representationparser;

import org.optimizationservices.oscommon.util.OSConstant;
import org.optimizationservices.oscommon.util.OSParameter;
import org.optimizationservices.oscommon.util.XMLUtil;
import org.w3c.dom.Document;
import org.w3c.dom.Element;
import org.w3c.dom.Node;


/**
 *
 * <P>The <code>FMLWriter</code> class is used to output different parts of
 * a linear program (e.g. data and solutions) to a document object model (DOM) that follows
 * FML Schema. Each element declared in the FML Schema has a corresponding protected element creation
 * method (e.g. createEl for creation of element el). User do not have direct access to any of these
 * protected methods. They get to manipulate the output of FML construction through a group of higher level
 * optimization related public "set" methods (e.g. setConstraints). Each "set" method has a corresponding
 * opposite "on" method in the {@link org.optimizationservices.oscommon.representationparser.FMLReader FMLReader} class, which has
 * exactly the same set of arguments. Each method checks within itself the argument consistency against FML Schema.
 * There is no specific sequence the user should follow to invoke these set methods. User can call the
 * same set methods several times. If the parameters are different, old values will be replaced by new ones.
 * User should, though, make sure values submitted through different "set" methods are consistent. For example
 * if variableCount in {@link #setDescription setDescription} is set to 2, then the variableLbs array in
 * {@link #setVariables setVariables} has to have a length 2.</p>
 *
 * <p>The FMLWriter class also provides auxiliary facilities to write the xml to different output.</p>
 *
 * </p>
 *
 * @author Robert Fourer, Jun Ma, Kipp Martin
 * @version 1.0, 03/14/2004
 * @see org.optimizationservices.oscommon.representationparser.FMLReader
 * @since OS 1.0
 */
public class FMLWriter{
	
	/**
	 * m_document holds the W3C DOM type document to create XML elements and attributes.
	 * It is the parent of the root element, i.e. the mathProgram element in FML. It is used
	 * to create all the nodes in the DOM tree.
	 */
	protected Document m_document = null;
	
	/**
	 * m_eleMathProgram holds the FML root element mathProgram.
	 */
	protected Element m_eleMathProgram = null;
	
	/**
	 * m_eleSparseVector holds the 1st child element sparseVector of root mathProgram.
	 */
	protected Element m_eleSparseVector = null;
	
	/**
	 * m_eleSparseMatrix holds the 2nd child element sparseMatrix of root mathProgram.
	 */
	protected Element m_eleSparseMatrix = null;
	
	/**
	 * m_eleLinearProgramDescription holds the 3rd child element linearProgramDescription of root mathProgram.
	 */
	protected Element m_eleLinearProgramDescription = null;
	
	/**
	 * m_linearProgramData holds the 4th child element linearProgramData of root mathProgram.
	 */
	protected Element m_eleLinearProgramData = null;
	
	/**
	 * m_eleLinearProgramSolution holds the 5th child element linearProgramSolution; of root mathProgram.
	 */
	protected Element m_eleLinearProgramSolution = null;
	
	/**
	 * m_eleLlinearProgramIterative holds the 6th child element linearProgramIterative of root mathProgram.
	 */
	protected Element m_eleLinearProgramIterative = null;
	
	/**
	 * constructor
	 */
	public FMLWriter(){
		try {
			m_document = XMLUtil.createNewDocument();
			m_eleMathProgram = createMathProgram();
			m_document.appendChild(m_eleMathProgram);
		}
		catch(Exception e){
			e.printStackTrace();
		}
	}//constructor
	
	/**
	 * Write the xml file from the internally constructed DOM tree structure that contains the
	 * FML linear program instance (data and/or solution) to a file.
	 *
	 * </p>
	 *
	 * @param fileName	holds the xml filename to write out the file to.
	 * @return whether the file is written successfully without any error.
	 */
	public boolean writeToFile(String fileName){
		return XMLUtil.writeXMLDocumentToFile(m_document, fileName);
	}//writeToFile
	
	/**
	 * Write the xml file from the internally constructed DOM tree structure that contains the
	 * FML linear program instance (data and/or solution) to the standard output (e.g. screen).
	 *
	 * </p>
	 *
	 * @return whether the output is written successfully without any error.
	 */
	public boolean writeToStandardOutput(){
		return XMLUtil.writeXMLDocumentToStandardOutput(m_document);
	}//writeToStandardOutput
	
	/**
	 * Write the xml file from the internally constructed DOM tree structure that contains the
	 * FML linear program instance (data and/or solution) to a string to be returned.
	 *
	 * </p>
	 *
	 * @return a string  that contains the FML linear program instance (data and/or solution).
	 * If error is encountered in writing the string, null is returned.
	 */
	public String writeToString(){
		return XMLUtil.writeXMLDocumentToString(m_document);
	}//writeToString
	
	/**
	 * Set the linearProgramDescription related elements. If the elements (e.g. the required elements) are
	 * already there, it will reset the them. If the elements are not there (e.g. the optional elements),
	 * it will add them.
	 *
	 * </p>
	 *
	 * @param source holds the source information of the optimization problem.
	 * @param variableCount holds the number of columns, i.e. variable number.
	 * @param constraintCount holds the number of rows, i.e. constraint number.
	 * @return whether the linearProgramDescription construction is successful.
	 */
	public boolean setDescription(String source, int variableCount, int constraintCount){
		try{
			Node nodeRef = null;
			Element eleSource = (Element)XMLUtil.findChildNode(m_eleLinearProgramDescription, "source");
			if(eleSource == null){
				eleSource = createSource(source);
				nodeRef = XMLUtil.findChildNode(m_eleLinearProgramDescription, "maxOrMin");
				m_eleLinearProgramDescription.insertBefore(eleSource, nodeRef);
			}
			else{
				eleSource.getChildNodes().item(0).setNodeValue(source);
			}
			Element eleVariableCount = (Element)XMLUtil.findChildNode(m_eleLinearProgramDescription, "numberVars");
			eleVariableCount.getChildNodes().item(0).setNodeValue(variableCount+"");
			Element eleConstraintCount = (Element)XMLUtil.findChildNode(m_eleLinearProgramDescription, "numberRows");
			eleConstraintCount.getChildNodes().item(0).setNodeValue(constraintCount+"");
		}
		catch(Exception e){
			e.printStackTrace();
			return false;
		}
		return true;
	}//setDescription
	
	/**
	 * Set the option related elements. If the elements (e.g. the required elements) are
	 * already there, it will reset the them. If the elements are not there (e.g. the optional elements),
	 * it will add them.
	 *
	 * </p>
	 *
	 * @param optionNames holds the names of all the options.
	 * @param optionValues holds the values of all the options corresponding to the names.
	 * @return whether the option construction is successful.
	 */
	public boolean setOption(String[] optionNames, String[] optionValues){
		try{
			int iOptionNames = (optionNames == null)?0:optionNames.length;
			int iOptionValues = (optionValues == null)?0:optionValues.length;
			if(iOptionNames != iOptionValues){
				return false;
			}
			XMLUtil.removeChildrenByName(m_eleLinearProgramDescription, "option");
			for(int i = 0; i < iOptionNames; i++){
				Element eleOption = createOption(optionNames[i], optionValues[i]);
				m_eleLinearProgramDescription.appendChild(eleOption);
			}
		}
		catch(Exception e){
			e.printStackTrace();
			return false;
		}
		return true;
	}//setOption
	
	/**
	 * Set the variable related elements. If the elements (e.g. the required elements) are
	 * already there, it will reset the them. If the elements are not there (e.g. the optional elements),
	 * it will add them.
	 *
	 * </p>
	 *
	 * @param variableNames holds the names of all the columns, i.e. variable names. It may be empty.
	 * @param variableLbs holds the values of lower bounds for the variables. It may be empty.
	 * @param variableUbs holds the values of upper bounds for the variables. It may be empty.
	 * @param variableDomains holds the types of all the variables, (e.g. 'C' for continuous
	 * type, 'I' for integer type, and 'B' for binary type). It may be empty.
	 * @return whether variable construction is successful.
	 */
	public boolean setVariables(String[] variableNames, double[] variableLbs, double[] variableUbs,
			char[] variableDomains){
		try{
			if((variableNames != null && variableLbs != null && variableNames.length != variableLbs.length)
					|| (variableNames != null && variableUbs != null && variableNames.length != variableUbs.length)
					|| (variableNames != null && variableDomains != null && variableNames.length != variableDomains.length)
					|| (variableLbs != null && variableUbs != null && variableLbs.length != variableUbs.length)
					|| (variableLbs != null && variableDomains != null && variableLbs.length != variableDomains.length)
					|| (variableUbs != null && variableDomains != null && variableUbs.length != variableDomains.length)){
				return false;
			}
			Node nodeRef = null;
			if(m_eleLinearProgramData == null){
				m_eleLinearProgramData = createLinearProgramData();
				nodeRef = XMLUtil.findChildNode(m_eleMathProgram, "linearProgramSolution");
				if(nodeRef == null){
					nodeRef = XMLUtil.findChildNode(m_eleMathProgram, "linearProgramIterative");
				}
				m_eleMathProgram.insertBefore(m_eleLinearProgramData, nodeRef);
			}
			Element eleColumns = (Element)XMLUtil.findChildNode(m_eleLinearProgramData, "columns");
			int iCols = 0;
			if(variableNames != null ){
				iCols = variableNames.length;
			}
			else if(variableLbs != null){
				iCols = variableLbs.length;
			}
			else if(variableUbs != null){
				iCols = variableUbs.length;
			}
			else if(variableUbs != null){
				iCols = variableUbs.length;
			}
			boolean bCreateCol = false;
			if(eleColumns.getChildNodes().getLength() != iCols){
				bCreateCol = true;
				XMLUtil.removeAllChildren(eleColumns);
			}
			for(int i = 0; i < iCols; i++){
				Element eleCol = null;
				if(bCreateCol){
					eleCol = createCol();
					eleColumns.appendChild(eleCol);
				}
				else{
					eleCol = (Element)eleColumns.getChildNodes().item(i);
				}
				if(variableNames != null){
					eleCol.setAttribute("colName", variableNames[i]);
				}
				else{
					eleCol.removeAttribute("colName");
				}
				if(variableUbs != null && !Double.isInfinite(variableUbs[i])){
					eleCol.setAttribute("colUB", variableUbs[i]+"");
				}
				else{
					eleCol.removeAttribute("colUB");
				}
				if(variableLbs != null && !Double.isInfinite(variableLbs[i])){
					eleCol.setAttribute("colLB", variableLbs[i]+"");
				}
				else{
					eleCol.removeAttribute("colLB");
				}
				if(variableDomains != null){
					if("CIB".indexOf(variableDomains[i]+"") == -1){
						return false;
					}
					eleCol.setAttribute("colType", variableDomains[i]+"");
				}
				else{
					eleCol.removeAttribute("colType");
				}
				//mult is not set (or by default = 1). For future developement, may want to check multiplicty.
			}
		}
		catch(Exception e){
			e.printStackTrace();
			return false;
		}
		return true;
	}//setVariables
	
	/**
	 * Set the constraint related elements. If the elements (e.g. the required elements) are
	 * already there, it will reset the them. If the elements are not there (e.g. the optional elements),
	 * it will add them.
	 *
	 * <p>The constraint information contains all the information about the linear constraints
	 * except for the AMatrix, which is to be set in the {@link #setAMatrix setAMatrix} method.</p>
	 *
	 * </p>
	 *
	 * @param constraintNames holds the names of all the rows, i.e. constraint names. It may be empty.
	 * @param constraintLhs holds the values of the lower bounds for the constraints. It may be empty.
	 * @param constraintRhs holds the values of the upper bounds for the constraints. It may be empty.
	 * @return whether constraint construction is successful.
	 */
	public boolean setConstraints(String[] constraintNames, double[] constraintLhs, double[] constraintRhs){
		try{
			if((constraintNames != null && constraintLhs != null && constraintNames.length != constraintLhs.length)
					|| (constraintNames != null && constraintRhs != null && constraintNames.length != constraintRhs.length)
					|| (constraintLhs != null && constraintRhs != null && constraintLhs.length != constraintRhs.length)){
				return false;
			}
			Node nodeRef = null;
			if(m_eleLinearProgramData == null){
				m_eleLinearProgramData = createLinearProgramData();
				nodeRef = XMLUtil.findChildNode(m_eleMathProgram, "linearProgramSolution");
				if(nodeRef == null){
					nodeRef = XMLUtil.findChildNode(m_eleMathProgram, "linearProgramIterative");
				}
				m_eleMathProgram.insertBefore(m_eleLinearProgramData, nodeRef);
			}
			Element eleRows = (Element)XMLUtil.findChildNode(m_eleLinearProgramData, "rows");
			int iRows = 0;
			if(constraintNames != null ){
				iRows = constraintNames.length;
			}
			else if(constraintLhs != null){
				iRows = constraintLhs.length;
			}
			else if(constraintRhs != null){
				iRows = constraintRhs.length;
			}
			boolean bCreateRow = false;
			if(eleRows.getChildNodes().getLength() != iRows){
				bCreateRow = true;
				XMLUtil.removeAllChildren(eleRows);
			}
			for(int i = 0; i < iRows; i++){
				Element eleRow = null;
				if(bCreateRow){
					eleRow = createRow();
					eleRows.appendChild(eleRow);
				}
				else{
					eleRow = (Element)eleRows.getChildNodes().item(i);
				}
				if(constraintNames != null){
					eleRow.setAttribute("rowName", constraintNames[i]);
				}
				else{
					eleRow.removeAttribute("rowName");
				}
				if(constraintLhs != null && !Double.isInfinite(constraintLhs[i])){
					eleRow.setAttribute("rowLB", constraintLhs[i]+"");
				}
				else{
					eleRow.removeAttribute("rowLB");
				}
				if(constraintRhs != null && !Double.isInfinite(constraintRhs[i])){
					eleRow.setAttribute("rowUB", constraintRhs[i]+"");
				}
				else{
					eleRow.removeAttribute("rowUB");
				}
				//mult is not set (or by default = 1). For future developement, may want to check multiplicty.
			}
		}
		catch(Exception e){
			e.printStackTrace();
			return false;
		}
		return true;
	}//setConstraints
	
	/**
	 * Set the AMatrix related elements. If the elements (e.g. the required elements) are
	 * already there, it will reset the them. If the elements are not there (e.g. the optional elements),
	 * it will add them.
	 *
	 * <p>The AMatrix stores all the information in the A part of the linear constraints lhs<=AX<=rhs</p>
	 *
	 * </p>
	 *
	 * @param isColumnMajor holds the value of whether the AMatrix holding linear program data is stored
	 * by column. If false, the matrix is stored by row.
	 * @param nonzeroValues holds the values of the vector element nonz in AMatrix, which contains nonzero elements.
	 * @param nonzeroIndexes holds the values of the vector element rowIdx or colIdx in AMatrix. If the matrix is
	 * stored by column (row), rowIdx (colIdx) is the vector of row (column) indexes.
	 * @param endIndexes holds the values of the vector element pntANonz in AMatrix, which points to the end of a
	 * column (row) of nonzero elements in AMatrix.
	 * @param numberOfNonzeros holds the values of the vector element numNonz in AMatrix. The vector numNonz, if
	 * present, stores the number of nonzero elements in the column (row). If numNonz is not present, then nonz
	 * stores the columns (rows) in matrix order. If the matrix is stored by column (row), rowIdx (colIdx) is
	 * the vector of row (column) indexes.
	 * @return whether user wants to clear the arrays passed in to save memory if the arrays
	 * will still be referenced, a false value is to be returned.
	 */
	public boolean setAMatrix(boolean isColumnMajor, double[] nonzeroValues, int[] nonzeroIndexes,
			int[] endIndexes, int[] numberOfNonzeros){
		try{
			if(nonzeroValues == null || nonzeroIndexes == null || endIndexes == null){
				return false;
			}
			if((nonzeroValues != null && nonzeroIndexes != null && nonzeroValues.length != nonzeroIndexes.length)
					|| (endIndexes != null && numberOfNonzeros != null && endIndexes.length != numberOfNonzeros.length)){
				return false;
			}
			Node nodeRef = null;
			if(m_eleLinearProgramData == null){
				m_eleLinearProgramData = createLinearProgramData();
				nodeRef = XMLUtil.findChildNode(m_eleMathProgram, "linearProgramSolution");
				if(nodeRef == null){
					nodeRef = XMLUtil.findChildNode(m_eleMathProgram, "linearProgramIterative");
				}
				m_eleMathProgram.insertBefore(m_eleLinearProgramData, nodeRef);
			}
			Element eleAMatrix = (Element)XMLUtil.findChildNode(m_eleLinearProgramData, "amatrix");
			
			Element eleSparseMatrix = (Element)XMLUtil.findChildNode(eleAMatrix, "sparseMatrix");
			
			Element elePntANonz = (Element)XMLUtil.findChildNode(eleSparseMatrix, "pntANonz");
			Element eleNonz = (Element)XMLUtil.findChildNode(eleSparseMatrix, "nonz");
			Element eleIdx = null;
			Element eleRowIdx = (Element)XMLUtil.findChildNode(eleSparseMatrix, "rowIdx");
			if(eleRowIdx != null){
				eleIdx = eleRowIdx;
			}
			Element eleColIdx = (Element)XMLUtil.findChildNode(eleSparseMatrix, "colIdx");
			if(eleColIdx != null){
				eleIdx = eleColIdx;
			}
			if(eleRowIdx != null && !isColumnMajor){
				eleIdx = createColIdx();
				eleSparseMatrix.replaceChild(eleRowIdx, eleIdx);
			}
			if(eleColIdx != null && isColumnMajor){
				eleIdx = createRowIdx();
				eleSparseMatrix.replaceChild(eleColIdx, eleIdx);
			}
			Element eleNumNonz = (Element)XMLUtil.findChildNode(eleSparseMatrix, "numNonz");
			if(eleNumNonz == null){
				nodeRef = eleNonz;
				eleNumNonz = createNumNonz();
				eleSparseMatrix.insertBefore(eleNumNonz, nodeRef);
			}
			
			XMLUtil.removeAllChildren(elePntANonz);
			XMLUtil.removeAllChildren(eleNonz);
			XMLUtil.removeAllChildren(eleIdx);
			XMLUtil.removeAllChildren(eleNumNonz);
			
			for(int i = 0; i < endIndexes.length; i++){
				elePntANonz.appendChild(createEl(endIndexes[i]));
			}
			for(int i = 0; i < nonzeroIndexes.length; i++){
				eleIdx.appendChild(createEl(nonzeroIndexes[i]));
			}
			for(int i = 0; i < nonzeroValues.length; i++){
				eleNonz.appendChild(createEl(nonzeroValues[i]));
			}
			if(numberOfNonzeros != null){
				for(int i = 0; i < numberOfNonzeros.length; i++){
					eleNumNonz.appendChild(createEl(numberOfNonzeros[i]));
				}
			}
			else{
				eleSparseMatrix.removeChild(eleNumNonz);
			}
		}
		catch(Exception e){
			e.printStackTrace();
			return false;
		}
		return true;
	}//setAMatrix
	
	/**
	 * Set the objective function related elements. If the elements (e.g. the required elements) are
	 * already there, it will reset the them. If the elements are not there (e.g. the optional elements),
	 * it will add them.
	 *
	 * </p>
	 *
	 * @param isMinimization holds whether the objective is minimization or not.
	 * @param objectiveConstant holds the value of objective function constant.
	 * @param ObjectiveCoefficients	holds the values of the objective function coefficients. It may be empty.
	 * @return whether objective construction is successful.
	 */
	public boolean setObjective(boolean isMinimization, double objectiveConstant, double[] ObjectiveCoefficients){
		try{
			Node nodeRef = null;
			if(m_eleLinearProgramData == null){
				m_eleLinearProgramData = createLinearProgramData();
				nodeRef = XMLUtil.findChildNode(m_eleMathProgram, "linearProgramSolution");
				if(nodeRef == null){
					nodeRef = XMLUtil.findChildNode(m_eleMathProgram, "linearProgramIterative");
				}
				m_eleMathProgram.insertBefore(m_eleLinearProgramData, nodeRef);
			}
			
			Element eleMaxOrMin = (Element)XMLUtil.findChildNode(m_eleLinearProgramDescription, "maxOrMin");
			eleMaxOrMin.getChildNodes().item(0).setNodeValue(isMinimization?"min":"max");
			
			Element eleObjConstant = (Element)XMLUtil.findChildNode(m_eleLinearProgramDescription, "objConstant");
			if(eleObjConstant == null){
				eleObjConstant = createObjConstant(objectiveConstant);
				nodeRef = XMLUtil.findChildNode(m_eleLinearProgramDescription, "numberRows");
				m_eleLinearProgramDescription.insertBefore(eleObjConstant, nodeRef);
			}
			else{
				eleObjConstant.getChildNodes().item(0).setNodeValue(objectiveConstant+"");
			}
			
			Element eleColumns = (Element)XMLUtil.findChildNode(m_eleLinearProgramData, "columns");
			int iCols = 0;
			if(ObjectiveCoefficients != null ){
				iCols = ObjectiveCoefficients.length;
			}
			boolean bCreateCol = false;
			if(eleColumns.getChildNodes().getLength() != iCols){
				bCreateCol = true;
				XMLUtil.removeAllChildren(eleColumns);
			}
			for(int i = 0; i < iCols; i++){
				Element eleCol = null;
				if(bCreateCol){
					eleCol = createCol();
					eleColumns.appendChild(eleCol);
				}
				else{
					eleCol = (Element)eleColumns.getChildNodes().item(i);
				}
				if(ObjectiveCoefficients != null){
					eleCol.setAttribute("objVal", ObjectiveCoefficients[i]+"");
				}
				else{
					eleCol.removeAttribute("objVal");
				}
			}
		}
		catch(Exception e){
			e.printStackTrace();
			return false;
		}
		return true;
	}//setObjective
	
	/**
	 *
	 * Set the objective solution related elements. If the elements (e.g. the required elements) are
	 * already there, it will reset the them. If the elements are not there (e.g. the optional elements),
	 * it will add them.
	 *
	 * <p>The objective solution does not include primal and dual solutions which are to be set
	 * in the {@link #setPrimalSolution setPrimalSolution} and {@link #setDualSolution setDualSolution}
	 * methods.</p>
	 *
	 * </p>
	 *
	 * @param statusId holds the information of optimization solution status id.
	 * @param status holds the status message of the optimization solution.
	 * @param solverMessage holds the value of solver message.
	 * @param optimalValue holds the value of the optimal solution.
	 * @return whether solution construction is successful.
	 * @see #setPrimalSolution
	 * @see #setDualSolution
	 */
	public boolean setSolution(String statusId, String status, String solverMessage, double optimalValue){
		try{
			Node nodeRef = null;
			if(m_eleLinearProgramSolution == null){
				m_eleLinearProgramSolution = createLinearProgramSolution();
				nodeRef = XMLUtil.findChildNode(m_eleMathProgram, "linearProgramIterative");
				m_eleMathProgram.insertBefore(m_eleLinearProgramSolution, nodeRef);
			}
			
			Element eleStatus = (Element)XMLUtil.findChildNode(m_eleLinearProgramSolution, "status");
			eleStatus.setAttribute("statusId", statusId);
			eleStatus.getChildNodes().item(0).setNodeValue(status);
			
			Element eleSolverMessage = (Element)XMLUtil.findChildNode(m_eleLinearProgramSolution, "solverMessage");
			if(eleSolverMessage == null){
				eleSolverMessage = createSolverMessage(solverMessage);
				nodeRef = XMLUtil.findChildNode(m_eleLinearProgramSolution, "metaData");
				m_eleLinearProgramSolution.insertBefore(eleSolverMessage, nodeRef);
			}
			else{
				eleSolverMessage.getChildNodes().item(0).setNodeValue(solverMessage);
			}
			
			Element eleOptimalValue = (Element)XMLUtil.findChildNode(m_eleLinearProgramSolution, "optimalValue");
			if(eleOptimalValue == null){
				eleOptimalValue = createOptimalValue(optimalValue);
				nodeRef = XMLUtil.findChildNode(m_eleLinearProgramSolution, "status");
				m_eleLinearProgramSolution.insertBefore(eleOptimalValue, nodeRef);
			}
			else{
				eleSolverMessage.getChildNodes().item(0).setNodeValue(optimalValue+"");
			}
		}
		catch(Exception e){
			e.printStackTrace();
			return false;
		}
		return true;
	}//setSolution
	
	/**
	 * Set the primal solution related elements. If the elements (e.g. the required elements) are
	 * already there, it will reset the them. If the elements are not there (e.g. the optional elements),
	 * it will add them.
	 *
	 *</p>
	 *
	 * @param priamlNames holds the names of primal variable solutions. It may be empty.
	 * @param primalValues holds the values of primal variable solutions corresponding to the primalIndexes.
	 * @param primalIndexes holds the indexes of primal variable solutions corresponding to the primalValues.
	 * @return whether primal solution construction is successful.
	 */
	public boolean setPrimalSolution(String[] primalNames, double[] primalValues, int[] primalIndexes){
		try{
			if(primalValues == null || primalIndexes == null){
				return false;
			}
			if((primalNames != null && primalValues != null && primalNames.length != primalValues.length)
					|| (primalNames != null && primalIndexes != null && primalNames.length != primalIndexes.length)
					|| (primalValues != null && primalIndexes != null && primalValues.length != primalIndexes.length)){
				return false;
			}
			Node nodeRef = null;
			if(m_eleLinearProgramSolution == null){
				m_eleLinearProgramSolution = createLinearProgramSolution();
				nodeRef = XMLUtil.findChildNode(m_eleMathProgram, "linearProgramIterative");
				m_eleMathProgram.insertBefore(m_eleLinearProgramSolution, nodeRef);
			}
			Element elePrimalSolution = (Element)XMLUtil.findChildNode(m_eleLinearProgramSolution, "primalSolution");
			if(elePrimalSolution == null){
				elePrimalSolution = createPrimalSolution();
				nodeRef = XMLUtil.findChildNode(m_eleLinearProgramSolution, "dualSolution");
				if(nodeRef == null){
					nodeRef = XMLUtil.findChildNode(m_eleLinearProgramSolution, "optimalValue");
				}
				if(nodeRef == null){
					nodeRef = XMLUtil.findChildNode(m_eleLinearProgramSolution, "status");
				}
				m_eleLinearProgramSolution.insertBefore(elePrimalSolution, nodeRef);
			}
			int iSols = 0;
			if(primalNames != null ){
				iSols = primalNames.length;
			}
			else if(primalValues != null){
				iSols = primalValues.length;
			}
			else if(primalIndexes != null){
				iSols = primalIndexes.length;
			}
			boolean bCreateSol = false;
			if(elePrimalSolution.getChildNodes().getLength() != iSols){
				bCreateSol = true;
				XMLUtil.removeAllChildren(elePrimalSolution);
			}
			for(int i = 0; i < iSols; i++){
				Element eleSol = null;
				if(bCreateSol){
					eleSol = createSol(primalIndexes[i], primalValues[i]);
					elePrimalSolution.appendChild(eleSol);
				}
				else{
					eleSol = (Element)elePrimalSolution.getChildNodes().item(i);
				}
				if(primalNames != null){
					eleSol.setAttribute("name", primalNames[i]);
				}
				else{
					eleSol.removeAttribute("name");
				}
			}
		}
		catch(Exception e){
			e.printStackTrace();
			return false;
		}
		return true;
	}//setPrimalSolution
	
	/**
	 * Set the dual solution related elements. If the elements (e.g. the required elements) are
	 * already there, it will reset the them. If the elements are not there (e.g. the optional elements),
	 * it will add them.
	 *
	 *</p>
	 *
	 * @param dualNames holds the names of dual variable solutions. It may be empty.
	 * @param dualValues holds the values of dual variable solutions corresponding to the primalIndexes.
	 * @param dualIndexes holds the indexes of dual variable solutions corresponding to the primalValues.
	 * @return whether dual solution construction is successful.
	 */
	public boolean setDualSolution(String[] dualNames, double[] dualValues, int[] dualIndexes){
		try{
			if(dualValues == null || dualIndexes == null){
				return false;
			}
			if((dualNames != null && dualValues != null && dualNames.length != dualValues.length)
					|| (dualNames != null && dualIndexes != null && dualNames.length != dualIndexes.length)
					|| (dualValues != null && dualIndexes != null && dualValues.length != dualIndexes.length)){
				return false;
			}
			Node nodeRef = null;
			if(m_eleLinearProgramSolution == null){
				m_eleLinearProgramSolution = createLinearProgramSolution();
				nodeRef = XMLUtil.findChildNode(m_eleMathProgram, "linearProgramIterative");
				m_eleMathProgram.insertBefore(m_eleLinearProgramSolution, nodeRef);
			}
			Element eleDualSolution = (Element)XMLUtil.findChildNode(m_eleLinearProgramSolution, "dualSolution");
			if(eleDualSolution == null){
				eleDualSolution = createDualSolution();
				nodeRef = XMLUtil.findChildNode(m_eleLinearProgramSolution, "optimalValue");
				if(nodeRef == null){
					nodeRef = XMLUtil.findChildNode(m_eleLinearProgramSolution, "status");
				}
				m_eleLinearProgramSolution.insertBefore(eleDualSolution, nodeRef);
			}
			int iSols = 0;
			if(dualNames != null ){
				iSols = dualNames.length;
			}
			else if(dualValues != null){
				iSols = dualValues.length;
			}
			else if(dualIndexes != null){
				iSols = dualIndexes.length;
			}
			boolean bCreateSol = false;
			if(eleDualSolution.getChildNodes().getLength() != iSols){
				bCreateSol = true;
				XMLUtil.removeAllChildren(eleDualSolution);
			}
			for(int i = 0; i < iSols; i++){
				Element eleSol = null;
				if(bCreateSol){
					eleSol = createSol(dualIndexes[i], dualValues[i]);
					eleDualSolution.appendChild(eleSol);
				}
				else{
					eleSol = (Element)eleDualSolution.getChildNodes().item(i);
				}
				if(dualNames != null){
					eleSol.setAttribute("name", dualNames[i]);
				}
				else{
					eleSol.removeAttribute("name");
				}
			}
		}
		catch(Exception e){
			e.printStackTrace();
			return false;
		}
		return true;
	}//setDualSolution
	
	/**
	 * Create the mathProgram element and its most basic required structure.
	 *
	 * </p>
	 *
	 * @return the mathProgram element.
	 */
	protected Element createMathProgram(){
		Element eleMathProgram = m_document.createElement("mathProgram");
		
		eleMathProgram.setAttribute("xmlns", OSConstant.FML_NAMESPACE);
		eleMathProgram.setAttribute("xmlns:xs", OSConstant.XMLNS_XS_VALUE);
		eleMathProgram.setAttribute("xmlns:xsi", OSConstant.XMLNS_XSI_VALUE);
		eleMathProgram.setAttribute("xsi:schemaLocation", OSConstant.FML_NAMESPACE+" "+OSParameter.FML_PUBLIC_SITE);
		
		m_eleLinearProgramDescription = createLinearProgramDescription();
		
		eleMathProgram.appendChild(m_eleLinearProgramDescription);
		
		return eleMathProgram;
	}//createMathProgram
	
	/**
	 * Create the sparseVector element and its most basic required structure.
	 *
	 * </p>
	 *
	 * @return the sparseVectorElement.
	 */
	protected Element createSparseVector(){
		Element eleSparseVector = m_document.createElement("sparseVector");
		
		Element eleIdx = createIdx();
		Element eleNonz = createNonz();
		
		eleSparseVector.appendChild(eleIdx);
		eleSparseVector.appendChild(eleNonz);
		
		return eleSparseVector;
	}//createSparseVector
	
	/**
	 * Create the sparseMatrix element and its most basic required structure.
	 *
	 * </p>
	 *
	 * @param isColumnMajor holds whether the sparse matrix holding linear program data is stored
	 * by column. If false, the sparse matrix is stored by row.
	 * @return the sparseMatrix element.
	 */
	protected Element createSparseMatrix(boolean isColumnMajor){
		Element eleSparseMatrix = m_document.createElement("sparseMatrix");
		
		Element elePntANonz = createPntANonz();
		Element eleRowIdx =  createRowIdx();
		Element eleColIdx = createColIdx();
		Element eleNonz = createNonz();
		
		eleSparseMatrix.appendChild(elePntANonz);
		if(isColumnMajor){
			eleSparseMatrix.appendChild(eleRowIdx);
		}
		else{
			eleSparseMatrix.appendChild(eleColIdx);
		}
		eleSparseMatrix.appendChild(eleNonz);
		
		return eleSparseMatrix;
	}//createSparseMatrix
	
	/**
	 * Create the linearProgramDescription element and its most basic required structure.
	 *
	 * </p>
	 * @return the linearProgramDescription element.
	 */
	protected Element createLinearProgramDescription(){
		Element eleLinearProgramDescription = m_document.createElement("linearProgramDescription");
		
		Element eleMaxOrMin = createMaxOrMin(true);
		Element eleNumberRows = createNumberRows(0);
		Element eleNumberVars = createNumberVars(0);
		
		eleLinearProgramDescription.appendChild(eleMaxOrMin);
		eleLinearProgramDescription.appendChild(eleNumberRows);
		eleLinearProgramDescription.appendChild(eleNumberVars);
		
		return eleLinearProgramDescription;
	}//createLinearProgramDescription
	
	/**
	 * Create the linearProgramData element and its most basic required structure.
	 *
	 * </p>
	 *
	 * @return the linearProgramData element.
	 */
	protected Element createLinearProgramData(){
		Element eleLinearProgramData = m_document.createElement("linearProgramData");
		
		Element eleRows = createRows();
		Element eleColumns = createColumns();
		Element eleAMatrix = createAMatrix(true);
		
		eleLinearProgramData.appendChild(eleRows);
		eleLinearProgramData.appendChild(eleColumns);
		eleLinearProgramData.appendChild(eleAMatrix);
		
		return eleLinearProgramData;
	}//createLinearProgramData
	
	/**
	 * Create the linearProgramSolution element and its most basic required structure.
	 *
	 * </p>
	 *
	 * @return the linearProgramSolution element.
	 */
	protected Element createLinearProgramSolution(){
		Element eleLinearProgramSolution = m_document.createElement("linearProgramSolution");
		
		Element eleStatus = createStatus("alternativeOptima", "");
		
		eleLinearProgramSolution.appendChild(eleStatus);
		
		return eleLinearProgramSolution;
	}//createLinearProgramSolution
	
	/**
	 * Create the linearProgramIterative element and its most basic required structure.
	 *
	 * </p>
	 *
	 * @return the linearProgramIterative element.
	 */
	protected Element createLinearProgramIterative(){
		Element eleLinearProgramIterative = m_document.createElement("linearProgramIterative");
		
		return eleLinearProgramIterative;
	}//createLinearProgramIterative
	
	/**
	 * Create the idx element and its most basic required structure.
	 *
	 * </p>
	 *
	 * @return the idx element.
	 */
	protected Element createIdx(){
		Element eleIdx = m_document.createElement("idx");
		
		return eleIdx;
	}//createIdx
	
	/**
	 * Create the nonz element and its most basic required structure.
	 *
	 * </p>
	 *
	 * @return the nonz element.
	 */
	protected Element createNonz(){
		Element eleNonz = m_document.createElement("nonz");
		
		return eleNonz;
	}//createNonz
	
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
		
		Element eleBase64BinaryData = m_document.createElement("base64BinaryData");
		eleBase64BinaryData.setAttribute("numericType", numericType);
		eleBase64BinaryData.setAttribute("sizeOf", sizeOf+"");
		
		return eleBase64BinaryData;
	}//createBase64BinaryData
	
	/**
	 * Create the el element and its most basic required structure.
	 *
	 * </p>
	 *
	 * @value holds the double value of the el element
	 * @return the el element.
	 */
	protected Element createEl(double value){
		Element eleEl = m_document.createElement("el");
		
		eleEl.appendChild(m_document.createTextNode(value+""));
		
		return eleEl;
	}//createEl(double)
	
	/**
	 * Create the el element and its most basic required structure.
	 *
	 * </p>
	 *
	 * @value holds the integer value of the el element
	 * @return the el element.
	 */
	protected Element createEl(int value){
		Element eleEl = m_document.createElement("el");
		
		eleEl.appendChild(m_document.createTextNode(value+""));
		
		return eleEl;
	}//createEl(int)
	
	/**
	 * Create the pntANonz element and its most basic required structure.
	 *
	 * </p>
	 *
	 * @return the pntANonz element.
	 */
	protected Element createPntANonz(){
		Element elePntANonz = m_document.createElement("pntANonz");
		
		return elePntANonz;
	}//createPntANonz
	
	/**
	 * Create the rowIdx element and its most basic required structure.
	 *
	 * </p>
	 *
	 * @return the rowIdx element.
	 */
	protected Element createRowIdx(){
		Element eleRowIdx = m_document.createElement("rowIdx");
		
		return eleRowIdx;
	}//createRowIdx
	
	/**
	 * Create the colIdx element and its most basic required structure.
	 *
	 * </p>
	 *
	 * @return the colIdx element.
	 */
	protected Element createColIdx(){
		Element eleColIdx = m_document.createElement("colIdx");
		
		return eleColIdx;
	}//createColIdx
	
	/**
	 * Create the numNonz element and its most basic required structure.
	 *
	 * </p>
	 *
	 * @return the numNonz element.
	 */
	protected Element createNumNonz(){
		Element eleNumNonz = m_document.createElement("numNonz");
		
		return eleNumNonz;
	}//createNumNonz
	
	/**
	 * Create the source element and its most basic required structure.
	 *
	 * </p>
	 *
	 * @param source holds the value of the source of the linear program instance.
	 * @return the source element.
	 */
	protected Element createSource(String source){
		Element eleSource = m_document.createElement("source");
		
		eleSource.appendChild(m_document.createTextNode(source));
		
		return eleSource;
	}//createSource
	
	/**
	 * Create the maxOrMin element and its most basic required structure.
	 *
	 * </p>
	 *
	 * @param isMin holds whether the objective is minimization or not
	 * @return the maxOrMin element.
	 */
	protected Element createMaxOrMin(boolean isMin){
		Element eleMaxOrMin = m_document.createElement("maxOrMin");
		
		eleMaxOrMin.appendChild(m_document.createTextNode(isMin?"min":"max"));
		return eleMaxOrMin;
	}//createMaxOrMin
	
	/**
	 * Create the objConstant element and its most basic required structure.
	 *
	 * </p>
	 *
	 * @param objConstant holds the value of the objective function constant term.
	 * @return the objConstant element.
	 */
	protected Element createObjConstant(double objConstant){
		Element eleObjConstant = m_document.createElement("objConstant");
		
		eleObjConstant.appendChild(m_document.createTextNode(objConstant+""));
		
		return eleObjConstant;
	}//createObjConstant
	
	/**
	 * Create the numberRows element and its most basic required structure.
	 *
	 * </p>
	 *
	 * @param numberRows holds the number of rows, i.e. constraint number.
	 * @return the numberRows element.
	 */
	protected Element createNumberRows(int numberRows){
		Element eleNumberRows = m_document.createElement("numberRows");
		
		eleNumberRows.appendChild(m_document.createTextNode(numberRows+""));
		
		return eleNumberRows;
	}//createNumberRows
	
	/**
	 * Create the numberVars element and its most basic required structure.
	 *
	 * </p>
	 *
	 * @param numberVars holds the number of columns, i.e. variable number.
	 * @return the numberVars element.
	 */
	protected Element createNumberVars(int numberVars){
		Element eleNumberVars = m_document.createElement("numberVars");
		
		eleNumberVars.appendChild(m_document.createTextNode(numberVars+""));
		
		return eleNumberVars;
	}//createNumberVars
	
	/**
	 * Create the option element and its most basic required structure.
	 *
	 * </p>
	 *
	 * @param name
	 * @param value
	 * @return the option element
	 */
	protected Element createOption(String name, String value){
		Element eleOption = m_document.createElement("option");
		
		eleOption.setAttribute("name", name);
		eleOption.setAttribute("value", value);
		
		return eleOption;
	}//createOption
	
	/**
	 * Create the rows element and its most basic required structure.
	 *
	 * </p>
	 *
	 * @return the rows element
	 */
	protected Element createRows(){
		Element eleRows = m_document.createElement("rows");
		
		return eleRows;
	}//createRows
	
	/**
	 * Create the columns element and its most basic required structure.
	 *
	 * </p>
	 *
	 * @return the columns element
	 */
	protected Element createColumns(){
		Element eleColumns = m_document.createElement("columns");
		
		return eleColumns;
	}//createColumns
	
	/**
	 * Create the amatrix element and its most basic required structure.
	 *
	 * </p>
	 *
	 * @param isColumnMajor holds whether the amatrix holding linear program data is stored
	 * by column. If false, the amatrix is stored by row.
	 * @return the amatrix element
	 */
	protected Element createAMatrix(boolean isColumnMajor){
		Element eleAMatrix = m_document.createElement("amatrix");
		
		Element eleSparseMatrix = createSparseMatrix(isColumnMajor);
		
		eleAMatrix.appendChild(eleSparseMatrix);
		
		return eleAMatrix;
	}//createAMatrix
	
	/**
	 * Create the row element and its most basic required structure.
	 *
	 * </p>
	 *
	 * @return the row element
	 */
	protected Element createRow(){
		Element eleRow = m_document.createElement("row");
		
		return eleRow;
	}//createRow
	
	/**
	 * Create the col element and its most basic required structure.
	 *
	 * </p>
	 *
	 * @return the col element
	 */
	protected Element createCol(){
		Element eleCol = m_document.createElement("col");
		
		return eleCol;
	}//createCol
	
	/**
	 *
	 * Create the metaData element and its most basic required structure.
	 *
	 * </p>
	 *
	 * @param info holds the name of the metadata element
	 * @param object holds the value of the metadata element
	 * @return the metaData element.
	 */
	protected Element createMetaData(String info, String object){
		Element eleMetaData = m_document.createElement("metaData");
		
		eleMetaData.setAttribute("info", info);
		eleMetaData.setAttribute("object", object);
		
		return eleMetaData;
	}//createMetaData
	
	/**
	 *
	 * Create the primalSolution element and its most basic required structure.
	 *
	 * </p>
	 *
	 * @return the primalSolution element.
	 */
	protected Element createPrimalSolution(){
		Element elePrimalSolution = m_document.createElement("primalSolution");
		
		return elePrimalSolution;
	}//createPrimalSolution
	
	/**
	 *
	 * Create the dualSolution element and its most basic required structure.
	 *
	 * </p>
	 *
	 * @return the dualSolution element.
	 */
	protected Element createDualSolution(){
		Element eleDualSolution = m_document.createElement("dualSolution");
		
		return eleDualSolution;
	}//createDualSolution
	
	/**
	 *
	 * Create the optimalValue element and its most basic required structure.
	 *
	 * </p>
	 *
	 * @param optimalValue holds the optimal value of the optimization solution
	 * @return the optimalValue element.
	 */
	protected Element createOptimalValue(double optimalValue){
		Element eleOptimalValue = m_document.createElement("optimalValue");
		
		if(optimalValue < Double.POSITIVE_INFINITY && optimalValue > Double.NEGATIVE_INFINITY){
			eleOptimalValue.appendChild(m_document.createTextNode(optimalValue+""));
		}
		
		return eleOptimalValue;
	}//createOptimalValue
	
	/**
	 * Create the status element and its most basic required structure.
	 *
	 * </p>
	 *
	 * @param statusId holds the information of optimization solution status id
	 * (e.g. infeasible).
	 * @param status holds the status message.
	 * @return the status element or null if the parameter values are not proper.
	 */
	protected Element createStatus(String statusId, String status){
		String[] msStatusId = {"optimalSolutionFound", "unbounded", "infeasible", "alternativeOptima"};
		boolean bStatusId = false;
		for(int i = 0; i < msStatusId.length; i++){
			if(msStatusId[i].equals(statusId)){
				bStatusId = true;
			}
		}
		if(!bStatusId){
			return null;
		}
		
		Element eleStatus = m_document.createElement("status");
		
		eleStatus.setAttribute("statusId", statusId);
		eleStatus.appendChild(m_document.createTextNode(status));
		
		return eleStatus;
	}//createStatus
	
	/**
	 * Create the solverMessage element and its most basic required structure.
	 *
	 * </p>
	 *
	 * @return the solverMessage element.
	 */
	protected Element createSolverMessage(String solverMessage){
		Element eleSolverMessage = m_document.createElement("solverMessage");
		
		eleSolverMessage.appendChild(m_document.createTextNode(solverMessage));
		
		return eleSolverMessage;
	}//createSolverMessage
	
	/**
	 * Create the sol element and its most basic required structure.
	 *
	 * </p>
	 *
	 * @param idx holds the index of a solution, primal solution(i.e. variable)
	 * or dual solution (i.e. constraint).
	 * @param value holds the value of a solution.
	 * @return the sol element or null if the parameter values are not proper.
	 */
	protected Element createSol(int idx, double value){
		if(idx < 0){
			return null;
		}
		
		Element eleSol = m_document.createElement("sol");
		
		eleSol.setAttribute("idx", idx+"");
		eleSol.setAttribute("val", value+"");
		
		return eleSol;
	}//createSol
	
	/**
	 * main for test purposes.
	 *
	 * </p>
	 *
	 * @param argv command line arguments.
	 */
	public static void main(String[] argv){
		FMLWriter fmlWriter = new FMLWriter();
		//String fName = "xml/lpfml/lpfml_2.xml";
		//boolean bSet = true;
		
		String[] msOptionName1 = {"o1", "o2"};
		String[] msOptionValue1  = {"1", "2"};
		if(!fmlWriter.setOption(msOptionName1, msOptionValue1)) System.out.println(1);
		String[] msOptionName2 = {"o3", "o4"};
		String[] msOptionValue2  = {"3", "4"};
		if(!fmlWriter.setOption(msOptionName2, msOptionValue2)) System.out.println(2);
		
		if(!fmlWriter.setDescription("source1", 2, 3)) System.out.println(3);
		if(!fmlWriter.setDescription("revised source", 2, 2))System.out.println(4);
		
		String[] msVariableNames1 = {"v1", "v2"};
		double[] mdVariableLbs1 = {0.0, 1.0};
		double[] mdVariableUbs1 = {10.0, 20.0};
		char[] mcVariableDomains1 = {'C', 'I'};
		if(!fmlWriter.setVariables(msVariableNames1, mdVariableLbs1, mdVariableUbs1, mcVariableDomains1)) System.out.println(5);
		//String[] msVariableNames2 = {"v3", "v4"};
		double[] mdVariableLbs2 = {2.0, 3.0, 4.0};
		double[] mdVariableUbs2 = {30.0, 40.0, 50.0};
		char[] mcVariableDomains2 = {'B', 'C', 'I'};
		if(!fmlWriter.setVariables(null, mdVariableLbs2, mdVariableUbs2, mcVariableDomains2))System.out.println(6);
		
		double[] mdNonz1 = {1.0, 2.0};
		int[] miNonzIdx1 = {1, 2};
		int[] miEndIdx1 = {2, 3};
		int[] miNumNonz1 = {1, 3};
		if(!fmlWriter.setAMatrix(true, mdNonz1, miNonzIdx1, miEndIdx1, miNumNonz1)) System.out.println(7);
		double[] mdNonz2 = {10.0, 20.0};
		int[] miNonzIdx2 = {10, 20};
		int[] miEndIdx2 = {20, 30};
		//int[] miNumNonz2 = {10, 30};
		if(!fmlWriter.setAMatrix(true, mdNonz2, miNonzIdx2, miEndIdx2, null)) System.out.println(8);
		
		
		String[] msConstraintNames1 = {"c1", "c2"};
		double[] mdConstraintLhs1 = {0.0, 1.0};
		double[] mdConstraintRhs1 = {10.0, 20.0};
		if(!fmlWriter.setConstraints(msConstraintNames1, mdConstraintLhs1, mdConstraintRhs1)) System.out.println(9);
		String[] msConstraintNames2 = {"c3", "c4", "c5"};
		double[] mdConstraintLhs2 = {2.0, 3.0, 4.0};
		double[] mdConstraintRhs2 =null;// {30.0, 40.0, 50.0};
		if(!fmlWriter.setConstraints(msConstraintNames2, mdConstraintLhs2, mdConstraintRhs2)) System.out.println(10);
		
		double[] mdObjectiveCoefficients1 = {0.0, 1.0};
		if(!fmlWriter.setObjective(false, 1, mdObjectiveCoefficients1)) System.out.println(11);
		double[] mdObjectiveCoefficients2 = {2.0, 3.0};
		if(!fmlWriter.setObjective(true, 2, mdObjectiveCoefficients2)) System.out.println(12);
		
		if(!fmlWriter.setSolution("infeasible", "status1", "solverMessage 1", 1.0)) System.out.println(13);
		if(!fmlWriter.setSolution("unbounded", "status2", "solverMessage 2", 1.0)) System.out.println(14);
		
		String[] msPrimalNames1 = {"p1", "p2", "p3"};
		double[] mdPrimalValues1 = {1.0, 2.0, 3.0};
		int[] miPrimalIndexes1 = {1, 2, 3};
		if(!fmlWriter.setPrimalSolution(msPrimalNames1, mdPrimalValues1, miPrimalIndexes1)) System.out.println(15);
		String[] msPrimalNames2 = {"p4", "p5"};
		double[] mdPrimalValues2 = {4.0, 5.0};
		int[] miPrimalIndexes2 = {4, 5};
		
		if(!fmlWriter.setPrimalSolution(msPrimalNames2, mdPrimalValues2, miPrimalIndexes2)) System.out.println(16);
		String[] msDualNames1 = {"d1", "d2", "d3"};
		double[] mdDualValues1 = {1.0, 2.0, 3.0};
		int[] miDualIndexes1 = {1, 2, 3};
		if(!fmlWriter.setDualSolution(msDualNames1, mdDualValues1, miDualIndexes1)) System.out.println(17);
		String[] msDualNames2 = {"d4", "d5"};
		double[] mdDualValues2 = {4.0, 5.0};
		int[] miDualIndexes2 = {4, 5};
		if(!fmlWriter.setDualSolution(msDualNames2, mdDualValues2, miDualIndexes2)) System.out.println(18);
		
		//fmlWriter.writeToFile(fName);System.out.println(XMLUtil.FileToString(fName, false));
		//fmlWriter.writeToStandardOutput();
		System.out.println(fmlWriter.writeToString());
	}//main
	
}//class FMLWriter
