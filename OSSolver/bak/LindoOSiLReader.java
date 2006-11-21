/**
 * @(#)LindoOSiLReader 1.0 03/14/2004
 *
 * Copyright (c) 2004
 */
package org.optimizationservices.ossolver.parser;

import java.util.HashMap;
import java.util.StringTokenizer;
import java.util.Vector;

import org.optimizationservices.oscommon.representationparser.OSiLReader;
import org.optimizationservices.oscommon.util.CommonUtil;
import org.optimizationservices.oscommon.util.IOUtil;
import org.optimizationservices.oscommon.util.OSParameter;


/**
 *
 * <P>The <code>LindoOSiLReader</code> class uses the generic <code>OSilReader</code> to parse
 * an OSiL instance into the data structure that can be inputted into the Lindo solver.
 * </p>
 *
 * @author Robert Fourer, Jun Ma, Kipp Martin
 * @version 1.0, 03/14/2004
 * @see org.optimizationservices.oscommon.representationparser.OSiLReader
 * @since OS 1.0
 */
public class LindoOSiLReader{
	protected String[] m_msNodeSymbols = {
			/*1--*/"plus", "sum", "minus", "negate", "times", "divide",
			/*2--*/"abs", "floor", "ceiling", "power", "square", "squareRoot", "ln", "log", "exp",
			/*3--*/"sin", "cos", "tan", "arcsin", "arccos", "arctan", "sinh", "cosh", "tanh", "arcsinh", "arccosh", "arctanh",
			/*4--*/"mean", "max", "min",
			/*5--*/"num", "identifier", "PI", "E", "INF", "EPS", "TRUE", "FALSE", "EULERGAMMA", "NAN",
			/*6--*/"X",
			/*7--*/"if", "lt", "leq", "gt", "geq", "eq", "neq", "and", "or", "xor", "implies", "not",
			/*8--*/
			/*9--*/"quadratic", "qTerm", "sim", "simInput", "simOutput", "userF", "arg", "xPath", "xPathIndex",   
	};
	protected String[] m_msLindoNames = {
			/*1--*/"EP_PLUS", "EP_SUM", "EP_MINUS", "EP_NEGATE", "EP_MUTIPLY", "EP_DIVIDE",
			/*2--*/"EP_ABS", "EP_FLOOR", "EP_NO_OP", "EP_POWER", "EP_NO_OP", "EP_SQRT", "EP_LN", "EP_NO_OP", "EP_EXP",
			/*3--*/"EP_SIN", "EP_COS", "EP_TAN", "EP_ASIN", "EP_ACOS", "EP_ATAN", "EP_NO_OP", "EP_NO_OP", "EP_NO_OP", "EP_NO_OP", "EP_NO_OP", "EP_NO_OP",
			/*4--*/"EP_NO_OP", "EP_MAX", "EP_MIN",
			/*5--*/"EP_PUSH_NUM", "EP_NO_OP", "EP_PI", "EP_NO_OP", "EP_NO_OP", "EP_NO_OP", "EP_TRUE", "EP_FALSE", "EP_NO_OP", "EP_NO_OP",
			/*6--*/"EP_PUSH_VAR",
			/*7--*/"EP_IF", "EP_LTHAN", "EP_LTOREQ", "EP_GTHAN", "EP_GTOREQ", "EP_EQUAL", "EP_NOT_EQUAL", "EP_AND", "EP_OR", "EP_NO_OP", "EP_NO_OP", "EP_NOT",
			/*8--*/
			/*9--*/"EP_NO_OP", "EP_NO_OP", "EP_NO_OP", "EP_NO_OP", "EP_NO_OP", "EP_NO_OP", "EP_NO_OP", "EP_NO_OP", "EP_NO_OP",
	};
	protected String[] m_msLindoNumbers = {
			/*1--*/"1001", "1055", "1002", "1017", "1003", "1004",
			/*2--*/"1018", "1039", "0000", "1005", "0000", "1019", "1021", "0000", "1030",
			/*3--*/"1023", "1024", "1025", "1028", "1029", "1027", "0000", "0000", "0000", "0000", "0000", "0000",
			/*4--*/"0000", "1058", "1057",
			/*5--*/"1062", "0000", "1022", "0000", "0000", "0000", "1033", "1032", "0000", "0000",
			/*6--*/"1063",
			/*7--*/"1034", "1010", "1008", "1011", "1009", "1006", "1007", "1012", "1013", "0000", "0000", "1014",
			/*8--*/
			/*9--*/"0000", "0000", "0000", "0000", "0000", "0000", "0000", "0000", "0000",
	};
	
	/**
	 * m_sLogicError holds the message of logic errors OSiLReader finds in
	 * the OSiL instance.
	 */
	public String m_sLogicError = "";
	
	/**
	 * nameMap holds a hash map of OSiL operator names (keys) to Lindo operator names (values).
	 */
	private HashMap<String, String> m_nameMap = new HashMap<String, String>();
	
	/**
	 * numberMap holds a hash map of OSiL operator names (keys) to Lindo operator numbers/indexes (values).
	 */
	private HashMap<String, String> m_numberMap = new HashMap<String, String>();
	
	/**
	 * m_vsConstant holds a String vector of constants in all the instruction list.
	 */
	private Vector<String> m_vsConstant = new Vector<String>();
	
	/**
	 * m_iObjInstructionListLength holds the length of the objective function instruction list.
	 */
	private int m_iObjInstructionListLength = 0;
	
	/**
	 * m_iNumberOfItemsInInstructionList holds the length of all the instruction list.
	 */
	private int m_iNumberOfItemsInInstructionList = 0;
	
	/**
	 * m_vsConstraintStart holds a String vector of pointers to start of each constraint in the instruction list.
	 */
	private Vector<String> m_vsConstraintStart = new Vector<String>();
	
	/**
	 * m_vsConstraintLength holds a String vector of lengths of each constraint in instruction list.
	 */
	private Vector<String> m_vsConstraintLength = new Vector<String>();
	
	/**
	 * constructor
	 */
	public LindoOSiLReader(){
		for(int i = 0; i < m_msNodeSymbols.length; i++){
			m_nameMap.put(m_msNodeSymbols[i], m_msLindoNames[i]);
			m_numberMap.put(m_msNodeSymbols[i], m_msLindoNumbers[i]);
		}
	}//constructor
	
	/**
	 * Construct Lindo solver's instruction list style input file from an OSiL instance.
	 *
	 * </p>
	 *
	 * @return an string that contains Lindo solver's instruction list style input.
	 */
	public String osilToInstructionLists(String osilInstance){
		int i;
		OSiLReader osilReader = new OSiLReader(OSParameter.VALIDATE);
		boolean bRead = osilReader.readString(osilInstance);
		if(!bRead) return null;
		m_sLogicError = osilReader.getLogicError();
		if(m_sLogicError.length() > 0){
			return null;
		}
		String s = "";
		String sOut = "";
		//String sOut2 = "";
		StringBuffer sBuffer = new StringBuffer();
		StringBuffer sBuffer2 = new StringBuffer();
		
		//constraint number
		s = "?";
		int iPos1 = sBuffer.length();
		int iPos1a = sBuffer2.length();
		sBuffer.append(s + "\n");
		sBuffer2.append(s + " :constraint number\n");
		//objective number
		s = "1";
		sBuffer.append(s + "\n");
		sBuffer2.append(s + " :objective number\n");
		//variable number
		s = osilReader.getVariableNumber() + "";
		sBuffer.append(s + "\n");
		sBuffer2.append(s + " :variable number\n");
		//number of real number constants
		s = "?";
		int iPos2 = sBuffer.length();
		int iPos2a = sBuffer2.length();
		sBuffer.append(s + "\n");
		sBuffer2.append(s + " :number of real number constants\n");
		//vector of variable indices
		for(i = 0; i < osilReader.getVariableNumber(); i++){
			sBuffer.append(i + " ");
			sBuffer2.append(i + " ");
		}
		sBuffer.append("\n");
		sBuffer2.append(" :vector of variable indices\n");
		//vector of variable lbs
		double[] mdLb = osilReader.getVariableLowerBounds();
		for(i = 0; i < osilReader.getVariableNumber(); i++){
			s = mdLb[i] + "";
			if(s.indexOf("nf") >= 0) s = "-1e30";
			sBuffer.append( s + " ");
			sBuffer2.append(s + " ");
		}
		sBuffer.append("\n");
		sBuffer2.append(" :vector of variable lbs\n");
		//vector of variable ubs
		double[] mdUb = osilReader.getVariableUpperBounds();
		for(i = 0; i < osilReader.getVariableNumber(); i++){
			s = mdUb[i] + "";
			if(s.indexOf("nf") >= 0) s = "1e30";
			sBuffer.append( s + " ");
			sBuffer2.append(s + " ");
		}
		sBuffer.append("\n");
		sBuffer2.append(" :vector of variable ubs\n");
		//vector of variable starting points
		double[] mdInit = osilReader.getVariableInitialValues();
		for(i = 0; i < osilReader.getVariableNumber(); i++){
			try{
				s = mdInit[i] + "";
				Double.parseDouble(s);
			}
			catch(Exception e){
				s = "0";
			}
			sBuffer.append( s + " ");
			sBuffer2.append(s + " ");
		}
		sBuffer.append("\n");
		sBuffer2.append(" :vector of variable starting points\n");
		//vector of variable types
		char[] mcType = osilReader.getVariableTypes();
		for(i = 0; i < osilReader.getVariableNumber(); i++){
			s = mcType[i] + "";
			sBuffer.append( s + " ");
			sBuffer2.append(s + " ");
		}
		sBuffer.append("\n");
		sBuffer2.append(" :vector of variable types\n");
		//vector of real number constants
		s = "?";
		int iPos3 = sBuffer.length();
		int iPos3a = sBuffer2.length();
		sBuffer.append(s + "\n");
		sBuffer2.append(s + " :vector of real number constants\n");
		//objective function direction
		s = osilReader.getFirstObjectiveMaxOrMin();
		if(s.equalsIgnoreCase("max")) s = "-1";
		else s = "1";
		sBuffer.append(s + "\n");
		sBuffer2.append(s + " :objective function direction\n");
		//pointers to the beginning of the objective function in the instruction list
		s = 0 + "";
		sBuffer.append(s + "\n");
		sBuffer2.append(s + " :pointers to the beginning of the objective function in the instruction list \n");
		//length of the objective function instruction list
		s = "?";
		int iPos4 = sBuffer.length();
		int iPos4a = sBuffer2.length();
		sBuffer.append(s + "\n");
		sBuffer2.append(s + " :length of the objective function instruction list \n");
		//number of items in the instruction list
		s = "?";
		int iPos5 = sBuffer.length();
		int iPos5a = sBuffer2.length();
		sBuffer.append(s + "\n");
		sBuffer2.append(s + " :number of items in the instruction list\n");
		//vector of constraint types, e.g. L, G, E
		int iOneSidedConstraint = 0;
		double[] mdLhs = osilReader.getConstraintLowerBounds();
		double[] mdRhs = osilReader.getConstraintUpperBounds();
		for(i = 0; i < osilReader.getConstraintNumber(); i++){
			s = "";
			double d1 = mdLhs[i];
			double d2 = mdRhs[i];
			if(d1 == d2){
				s = "E ";
				iOneSidedConstraint++;
			}
			else{
				if(!Double.isInfinite(d1)){
					s += "G ";
					iOneSidedConstraint++;
				}
				if(!Double.isInfinite(d2)){
					s += "L ";
					iOneSidedConstraint++;
				}
			}
			sBuffer.append( s + " ");
			sBuffer2.append(s + " ");
		}
		sBuffer.append("\n");
		sBuffer2.append(" :vector of constraint types\n");
		//vector of pointers to start of each constraint in the instruction list
		s = "?";
		int iPos6 = sBuffer.length();
		int iPos6a = sBuffer2.length();
		sBuffer.append(s + "\n");
		sBuffer2.append(s + " :vector of pointers to start of each constraint in the instruction list\n");
		//vector of lengths of each constraint in the instruction list
		s = "?";
		int iPos7 = sBuffer.length();
		int iPos7a = sBuffer2.length();
		sBuffer.append(s + "\n");
		sBuffer2.append(s + " :vector of lengths of each constraint in the instruction list \n");
		//vector of instructions in postfix format
		Vector vPostfix = osilReader.getPostfix(-1);
		Vector vLindoPostfixTokens = convertToLindoPostfix(CommonUtil.vectorToString(vPostfix, ','), true);
		m_iObjInstructionListLength = vLindoPostfixTokens.size();
		m_iNumberOfItemsInInstructionList += m_iObjInstructionListLength;
		String sLindoPostfixNumber = CommonUtil.vectorToString(vLindoPostfixTokens, ' ');
		vLindoPostfixTokens = convertToLindoPostfix(CommonUtil.vectorToString(vPostfix, ','), false);
		String sLindoPostfixName = CommonUtil.vectorToString(vLindoPostfixTokens, ' ');
		sBuffer.append(sLindoPostfixNumber + "\n");
		sBuffer2.append(sLindoPostfixName + " :postfix -1" + "\n");
		for(i = 0; i < osilReader.getConstraintNumber(); i++){
			double d1 = mdLhs[i];
			double d2 = mdRhs[i];
			vPostfix = osilReader.getPostfix(i);
			vLindoPostfixTokens = convertToLindoPostfix(CommonUtil.vectorToString(vPostfix, ','), true);			
			sLindoPostfixNumber = CommonUtil.vectorToString(vLindoPostfixTokens, ' ');
			vLindoPostfixTokens = convertToLindoPostfix(CommonUtil.vectorToString(vPostfix, ','), false);
			sLindoPostfixName = CommonUtil.vectorToString(vLindoPostfixTokens, ' ');			
			if(d1 == d2){	
				m_vsConstraintStart.addElement(m_iNumberOfItemsInInstructionList + "");
				m_vsConstraintLength.addElement((vLindoPostfixTokens.size() + (d1==0?0:3))+ "");
				m_iNumberOfItemsInInstructionList += (vLindoPostfixTokens.size() + (d1==0?0:3));
				sBuffer.append(sLindoPostfixNumber + (d1==0?"":(" 1062 " + m_vsConstant.size() + " 1002")) + "\n");
				sBuffer2.append(sLindoPostfixName + (d1==0?"":(" EP_PUSH_NUM " + m_vsConstant.size() + " EP_MINUS ")) + " :postfix " + i + "\n");
				if(d1 != 0) m_vsConstant.add(d1 + "");		
			}
			else{
				if(!Double.isInfinite(d1)){
					m_vsConstraintStart.addElement(m_iNumberOfItemsInInstructionList + "");
					m_vsConstraintLength.addElement((vLindoPostfixTokens.size() + (d1==0?0:3))+ "");
					m_iNumberOfItemsInInstructionList += (vLindoPostfixTokens.size() + (d1==0?0:3));
					sBuffer.append(sLindoPostfixNumber + (d1==0?"":(" 1062 " + m_vsConstant.size() + " 1002")) + "\n");
					sBuffer2.append(sLindoPostfixName + (d1==0?"":(" EP_PUSH_NUM " + m_vsConstant.size() + " EP_MINUS ")) + " :postfix " + i + "\n");
					if(d1 != 0) m_vsConstant.add(d1 + "");					
				}
				if(!Double.isInfinite(d2)){
					m_vsConstraintStart.addElement(m_iNumberOfItemsInInstructionList + "");
					m_vsConstraintLength.addElement((vLindoPostfixTokens.size() + (d2==0?0:3))+ "");
					m_iNumberOfItemsInInstructionList += (vLindoPostfixTokens.size() + (d2==0?0:3));
					sBuffer.append(sLindoPostfixNumber + (d2==0?"":(" 1062 " + m_vsConstant.size() + " 1002")) + "\n");
					sBuffer2.append(sLindoPostfixName + (d2==0?"":(" EP_PUSH_NUM " + m_vsConstant.size() + " EP_MINUS ")) + " :postfix " + i + "\n");
					if(d2 != 0) m_vsConstant.add(d2 + "");					
				}
			}
		}
		//replace questions marks (?)
		String sConstraintLength = CommonUtil.vectorToString(m_vsConstraintLength, ' ');
		sBuffer.replace(iPos7, iPos7+1, sConstraintLength);
		sBuffer2.replace(iPos7a, iPos7a+1, sConstraintLength);
		
		String sConstraintStart = CommonUtil.vectorToString(m_vsConstraintStart, ' ');
		sBuffer.replace(iPos6, iPos6+1, sConstraintStart);
		sBuffer2.replace(iPos6a, iPos6a+1, sConstraintStart);
		
		sBuffer.replace(iPos5, iPos5+1, (m_iNumberOfItemsInInstructionList + ""));
		sBuffer2.replace(iPos5a, iPos5a+1, (m_iNumberOfItemsInInstructionList + ""));
		
		sBuffer.replace(iPos4, iPos4+1, (m_iObjInstructionListLength + ""));
		sBuffer2.replace(iPos4a, iPos4a+1, (m_iObjInstructionListLength + ""));
		
		String sConstants = CommonUtil.vectorToString(m_vsConstant, ' ');
		sBuffer.replace(iPos3, iPos3+1, sConstants);
		sBuffer2.replace(iPos3a, iPos3a+1, sConstants);
		
		sBuffer.replace(iPos2, iPos2+1, (m_vsConstant.size() + ""));
		sBuffer2.replace(iPos2a, iPos2a+1, (m_vsConstant.size() + ""));
		
		sBuffer.replace(iPos1, iPos1+1, (iOneSidedConstraint + ""));
		sBuffer2.replace(iPos1a, iPos1a+1, (iOneSidedConstraint + ""));
		
		sOut = sBuffer.toString();
		//sOut2 = sBuffer2.toString();
		//System.out.println(sOut);
		//System.out.println(sOut2);
		return sOut;
	}//osilToInstructionList
	
	/**
	 * Convert the OSiL postfix to Lindo postfix.
	 *
	 * </p>
	 *
	 * @param osilPostfix holds the OSiL postfix string to be converted
	 * @param useIndex holds whether to convert to Lindo postfix of operator names or operator indexes.
	 * If true, it will convert to postfix of operator indexes.
	 * @return a String vector of converted Lindo postfix operator tokens.
	 */
	private Vector convertToLindoPostfix(String osilPostfix, boolean useIndex){
		StringTokenizer st = new StringTokenizer(osilPostfix, OSiLReader.getDelimiter()+" ");
		Vector<String> vLindoPostfix = new Vector<String>();
		while (st.hasMoreTokens()){
			String sOSiLToken = st.nextToken();
			String sLindoToken = "";
			try{
				double d = Double.parseDouble(sOSiLToken);
				sLindoToken = (String)(useIndex?m_numberMap.get("num"):m_nameMap.get("num"));
				vLindoPostfix.addElement(sLindoToken);
				vLindoPostfix.addElement(m_vsConstant.size() + "");
				m_vsConstant.add(d + "");
			}
			catch(Exception e){
				if(sOSiLToken.startsWith("X")){
					sLindoToken = (String)(useIndex?m_numberMap.get("X"):m_nameMap.get("X"));
					vLindoPostfix.addElement(sLindoToken);
					vLindoPostfix.addElement(sOSiLToken.substring(1));
				}
				else{
					String sName = sOSiLToken;
					String sNumber = "";
					if(sOSiLToken.indexOf("[") >= 0){
						sName = sOSiLToken.substring(0, sOSiLToken.indexOf("["));
						sNumber = sOSiLToken.substring(sOSiLToken.indexOf("[") + 1, sOSiLToken.indexOf("]"));
					}
					sLindoToken = (String)(useIndex?m_numberMap.get(sName):m_nameMap.get(sName));
					vLindoPostfix.addElement(sLindoToken);
					if(sNumber != null && sNumber.length() > 0) vLindoPostfix.addElement(sNumber);
				}
			}
		}
		return vLindoPostfix;
	}//convertToLindoPostfix
	
	/**
	 * main for test purposes.
	 *
	 * </p>
	 *
	 * @param argv command line arguments.
	 */
	public static void main(String[] argv){
		LindoOSiLReader lindoOSiLReader = new LindoOSiLReader();
		String sOSiLinstance = IOUtil.fileToString("xml/osxl/markowitz.xml");
		String sLindoInput = lindoOSiLReader.osilToInstructionLists(sOSiLinstance);
		System.out.println(sLindoInput);
	}//main
}//LindoOSiLReader
