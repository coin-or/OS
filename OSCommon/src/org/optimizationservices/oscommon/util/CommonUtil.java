/**
 * @(#)CommonUtil 1.0 03/14/2004
 *
 * Copyright (c) 2004
 */
package org.optimizationservices.oscommon.util;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileReader;
import java.io.InputStreamReader;
import java.net.InetAddress;
import java.net.UnknownHostException;
import java.util.Calendar;
import java.util.Enumeration;
import java.util.GregorianCalendar;
import java.util.Random;
import java.util.StringTokenizer;
import java.util.Vector;

import org.optimizationservices.oscommon.datastructure.osgeneral.NewsElement;
import org.optimizationservices.oscommon.datastructure.osrepository.RepositoryInstance;
import org.optimizationservices.oscommon.representationparser.OSRepositoryReader;
import org.optimizationservices.oscommon.representationparser.OSiLReader;
import org.optimizationservices.oscommon.representationparser.OSiLWriter;
import org.optimizationservices.oscommon.representationparser.OSoLReader;

import drasys.or.mp.Constraint;
import drasys.or.mp.ConstraintI;
import drasys.or.mp.Problem;
import drasys.or.mp.VariableI;
import drasys.or.mp.util.MPSReader;

/**
 *
 * <P>The <code>CommonUtil</code> class contains methods for performing
 * common basic operations used by many classes in the
 * Optimization Services (OS) framework. </p>
 *
 * </p>
 *
 * @author  Robert Fourer, Jun Ma, Kipp Martin
 * @version 1.0, 03/14/2004
 * @since   OS1.0
 */
public class CommonUtil{
	
	/**
	 * Constructor.
	 *
	 */
	public CommonUtil(){
		
	}//constructor
	
	public static String getJobID(String option){
		if(option != null && option.length() > 0){
			try{
				OSoLReader osolReader = new OSoLReader(OSParameter.VALIDATE);
				osolReader.readString(option);
			}
			catch(Exception e){
				IOUtil.log(IOUtil.exceptionStackToString(e), null);
			}
		}
		
		String sJobID = "";
		InetAddress inetAddress = null;
		try{
			inetAddress = InetAddress.getLocalHost();
		}
		catch(Exception e){
			e.printStackTrace();
		}
		String sHostName = inetAddress.getHostName();
		sJobID += (sHostName + OSConstant.JODID_DELIMITER);
		
		InetAddress[] mIPAddress = null;
		
		try {
			mIPAddress = InetAddress.getAllByName(sHostName);
		} catch (UnknownHostException e) {
			e.printStackTrace();
		}
		int i;
		int iNumberIPAddress = (mIPAddress == null)?0:mIPAddress.length;
		for(i = 0; i < iNumberIPAddress; i++){
			sJobID += mIPAddress[i].getHostAddress();
			if(i != iNumberIPAddress -1) sJobID+="_";
		}
		sJobID += OSConstant.JODID_DELIMITER;

		GregorianCalendar calendar = new GregorianCalendar();
		sJobID += XMLUtil.createXSDateTime(calendar);
		/*
		sJobID += ((calendar.get(Calendar.MONTH)+1) + "." + 
				   calendar.get(Calendar.DAY_OF_MONTH) + "." +
				   calendar.get(Calendar.YEAR) + "." + 
				   calendar.get(Calendar.DAY_OF_WEEK) + "." + 
				   calendar.get(Calendar.HOUR_OF_DAY) + "." + 
				   calendar.get(Calendar.MINUTE) + "." + 
				   calendar.get(Calendar.SECOND) + "." + 
				   calendar.get(Calendar.MILLISECOND)  + OSConstant.JODID_DELIMITER);
		*/
		Random random = new Random();
		sJobID += random.nextInt(1000000000);
		sJobID = sJobID.replace(':', '.');
		sJobID = sJobID.replace('%', '.');
		return sJobID;
	}//getJobID

	/**
	 * get IP address
	 * @return IP address in a string
	 */
	public static String getIPAddress(){
		String sIP = "";
		InetAddress inetAddress = null;
		try{
			inetAddress = InetAddress.getLocalHost();
		}
		catch(Exception e){
			e.printStackTrace();
		}
		String sHostName = inetAddress.getHostName();
		InetAddress[] mIPAddress = null;
		
		try {
			mIPAddress = InetAddress.getAllByName(sHostName);
		} catch (UnknownHostException e) {
			e.printStackTrace();
		}
		int i;
		int iNumberIPAddress = (mIPAddress == null)?0:mIPAddress.length;
		for(i = 0; i < iNumberIPAddress; i++){
			sIP = mIPAddress[i].getHostAddress();
			if(!sIP.trim().startsWith("0") && sIP.indexOf("127.0.0.1") < 0) return sIP;
		}
		return "localhost";
	}//getIPAddress
	
	
	
	/**
	 * Converts a vector of integers to an integer array.
	 *
	 * </p>
	 *
	 * @param v The vector to be converted.
	 * @return an integer array.
	 */
	public static int[] vectorToIntArray(Vector v){
		if(v == null) return null;
		int n = v.size();
		int[] miIntArray = new int[n];
		for(int i = 0; i < n; i++){
			miIntArray[i] = ((Integer)v.elementAt(i)).intValue();
		}
		return miIntArray;
	}//vectorToIntArray
	
	/**
	 * Converts a vector of doubles to a double array.
	 *
	 * </p>
	 *
	 * @param v the vector to be converted.
	 * @return a double array.
	 */
	public static double[] vectorToDblArray(Vector v){
		if(v == null) return null;
		int n = v.size();
		double[] mdDblArray = new double[n];
		for(int i = 0; i < n; i++){
			mdDblArray[i] = ((Double)v.elementAt(i)).doubleValue();
		}
		return mdDblArray;
	}//vectorToDblArray
	
	/**
	 * Converts a vector of strings to a string array.
	 *
	 * </p>
	 *
	 * @param v the vector to be converted.
	 * @return a string array.
	 */
	public static String[] vectorToStrArray(Vector v){
		if(v == null) return null;
		int n = v.size();
		String[] msStrArray = new String[n];
		for(int i = 0; i < n; i++){
			msStrArray[i] = (String)v.elementAt(i);
		}
		return msStrArray;
	}//vectorToStrArray
	
	/**
	 * Converts a vector of boolean to a boolean array.
	 *
	 * </p>
	 *
	 * @param v the vector to be converted.
	 * @return a boolean array.
	 */
	public static boolean[] vectorToBolArray(Vector v){
		if(v == null) return null;
		int n = v.size();
		boolean[] mbBolArray = new boolean[n];
		for(int i = 0; i < n; i++){
			mbBolArray[i] = ((Boolean)v.elementAt(i)).booleanValue();
		}
		return mbBolArray;
	}//vectorToBolArray
	
	/**
	 * Converts a vector of characters to a character array.
	 *
	 * </p>
	 *
	 * @param v the vector to be converted.
	 * @return a character array.
	 */
	public static char[] vectorToChaArray(Vector v){
		if(v == null) return null;
		int n = v.size();
		char[] mcChaArray = new char[n];
		for(int i = 0; i < n; i++){
			mcChaArray[i] = ((Character)v.elementAt(i)).charValue();
		}
		return mcChaArray;
	}//vectorToChaArray
	
	/**
	 * Converts a delimited string to a vector. 
	 * 
	 * @param string holds the string to be converted to a vector. 
	 * @param delimiter holds the delimiters of the string. 
	 * @return the vector converted from the string
	 */
	public static Vector<String> stringToVector(String string, String delimiters){
		StringTokenizer st = new StringTokenizer(string, delimiters); 
		Vector<String> vector = new Vector<String>();
		while (st.hasMoreTokens()){ 
			String sToken = st.nextToken();
			vector.add(sToken);
		}
		return vector;
	}//stringToVector
	
	/**
	 * Converts a vector to a string, delimited by a specified delimiter. 
	 * 
	 * @param vector holds the vector to be converted to a string. 
	 * @param delimiter holds the delimiter character to put in the converted string. 
	 * @return
	 */
	public static String vectorToString(Vector vector, char delimiter){
		String string = "";
		int i = 0;
		for(i = 0; i < vector.size()-1; i++){
			string += vector.elementAt(i).toString();
			string += delimiter;
		}
		if(vector.size() > 0) string += vector.elementAt(i);
		return string;
	}//vectorToString
	
	/**
	 * Check whether a number string is positive infinity or not, 
	 * including the following (case insensitive):
	 * infinity, inf,
	 * 
	 * @param numberString holds the number string to be checked. 
	 * @return whether a number string is postive infinity or not. 
	 */
	public static boolean isPostiveInfinity(String numberString){
		if(numberString.equalsIgnoreCase("infinity")) return true;
		if(numberString.equalsIgnoreCase("inf")) return true;
		return false;
	}//isPostiveInfinity
	
	/**
	 * Check whether a number string is negative infinity or not, 
	 * including the following (case insensitive):
	 * -infinity, -inf,
	 * 
	 * @param numberString holds the number string to be checked. 
	 * @return whether a number string is negative infinity or not. 
	 */
	public static boolean isNegativeInfinity(String numberString){
		if(numberString.equalsIgnoreCase("-infinity")) return true;
		if(numberString.equalsIgnoreCase("-inf")) return true;
		return false;
	}//isNegativeInfinity
	
	/**
	 * check the OSRepository from the information given in OSRepository.xml and print out 
	 * relevant information. 
	 * 
	 * @return whether the OSRepository is checked successfully or not. 
	 */
	public static boolean checkOSRepository(){
		String sOSRepositoryXMLFile = OSParameter.CODE_HOME + "OSRepository/OSRepository.xml";
		String sOSRepositoryDir = OSParameter.CODE_HOME + "OSRepository/";
		String sNetLibProblemDir = sOSRepositoryDir + "other/MPS_netlib/netlib/data/";
		String sMIP03LibProblemDir = sOSRepositoryDir + "other/miplib2003/";
		
		OSRepositoryReader osRepositoryReader = new OSRepositoryReader(false);
		OSiLReader osilReader;
		osRepositoryReader.readFile(sOSRepositoryXMLFile);
		System.out.println("OSRepository Description\n" + osRepositoryReader.getDescription());
		System.out.println("\nOSRepository News\n");
		NewsElement[] mNews = osRepositoryReader.getNews();
		int iNews = mNews==null?0:mNews.length;
		for(int i = 0; i < iNews; i++){
			System.out.println("time: " + XMLUtil.createXSDateTime(mNews[i].time) + ": " + mNews[i].value);
		}
		RepositoryInstance[] mInstancce = osRepositoryReader.getInstances();
		int iInstance = mInstancce==null?0:mInstancce.length;
		int iNetLib = 98; //E226 is treated specially for its obj constant.
		int iKeninninton = 16; //4 big files are usually skipped. 
		int iInfeasible = 29; //be careful with the infeasible greanbea, which is generated manually. 
		int iMIP03Lib = 60; 
		String sLine = "------------------------------------------------------";
		System.out.println("\n\n" + "OSRepository instances: " + iInstance);
		System.out.println("Number of Netlib Problems: " + iNetLib);
		System.out.println("Number of Keninninton Problems: " + iKeninninton);
		System.out.println("Number of infeasible Problems: " + iInfeasible);
		System.out.println("Number of mixed integer Problems: " + iMIP03Lib);
		for(int i = iNetLib+iKeninninton+iInfeasible; i < iNetLib+iKeninninton+iInfeasible+iMIP03Lib; i++){
			System.out.println(sLine);
			System.out.println(i);
			System.out.println("name: " + mInstancce[i].name);	
			
			//Start of skipping 4 big files. 
			if(mInstancce[i].name.equals("KEN-18")){
				System.out.println("!!too big!!");
				continue;
			}
			if(mInstancce[i].name.equals("OSA-30")){
				System.out.println("!!too big!!");
				continue;
			}
			if(mInstancce[i].name.equals("OSA-60")){
				System.out.println("!!too big!!");
				continue;
			}
			if(mInstancce[i].name.equals("PDS-20")){
				System.out.println("!!too big!!");
				continue;
			}
			//End of skipping 4 big files. 
			 
			System.out.println("source: " + mInstancce[i].source);
			System.out.println("description: " + mInstancce[i].description);
			String sDir = sNetLibProblemDir;
			if(i >= iNetLib+iKeninninton+iInfeasible) sDir = sMIP03LibProblemDir;
			System.out.println("originalFileName: " + (sDir+ mInstancce[i].originalFileName));
			System.out.println("osDirectoty: " + mInstancce[i].osDirectoty);
			System.out.println("osFileName: " + mInstancce[i].osFileName);
			String sOSiLFile = sOSRepositoryDir + mInstancce[i].osDirectoty + mInstancce[i].osFileName;
			osilReader = new OSiLReader();
			osilReader.readFile(sOSiLFile);			
			System.out.println("objective number: " + osilReader.getObjectiveNumber());
			System.out.println("constraint number: " + osilReader.getConstraintNumber());
			System.out.println("variable number: " + osilReader.getVariableNumber());
			int iObjCoef = osilReader.getFirstObjectiveCoefficientNumber();
			int iMatrixNonzero = osilReader.getLinearConstraintCoefficientNumber();
			System.out.println("objCoef Number " + iObjCoef);
			System.out.println("matrix nonzero number: " + iMatrixNonzero);
			System.out.println("total nonzero number: " + (iObjCoef + iMatrixNonzero));
		}
		System.out.println(sLine);
		System.out.println("END");
		return true;
		
	}//checkOSRepository

	
	/**
	 * Create the OSRepository from the information given in OSRepository.xml. 
	 * 
	 * @return whether the OSRepository is created successfully or not. 
	 */
	public static boolean createOSRepository(){
		String sOSRepositoryXMLFile = OSParameter.CODE_HOME + "OSRepository/OSRepository.xml";
		String sOSRepositoryDir = OSParameter.CODE_HOME + "OSRepository/";
		String sNetLibProblemDir = sOSRepositoryDir + "other/MPS_netlib/netlib/data/";
		String sMIP03LibProblemDir = sOSRepositoryDir + "other/miplib2003/";

		OSRepositoryReader osRepositoryReader = new OSRepositoryReader(false);
		osRepositoryReader.readFile(sOSRepositoryXMLFile);
		System.out.println("OSRepository Description\n" + osRepositoryReader.getDescription());
		System.out.println("\nOSRepository News\n");
		NewsElement[] mNews = osRepositoryReader.getNews();
		int iNews = mNews==null?0:mNews.length;
		for(int i = 0; i < iNews; i++){
			System.out.println("time: " + XMLUtil.createXSDateTime(mNews[i].time) + ": " + mNews[i].value);
		}
		RepositoryInstance[] mInstancce = osRepositoryReader.getInstances();
		int iInstance = mInstancce==null?0:mInstancce.length;
		int iNetLib = 98; //E226 is treated specially for its obj constant.
		int iKeninninton = 16; //4 big files are usually skipped. 
		int iInfeasible = 29; //skipping the infeasible greanbea
		int iMIP03Lib = 60;//disktom.mps changed to disctom.mps
		String sLine = "------------------------------------------------------";
		System.out.println("\n\n" + "OSRepository instances: " + iInstance);
		System.out.println("Number of Netlib Problems: " + iNetLib);
		System.out.println("Number of Keninninton Problems: " + iKeninninton);
		System.out.println("Number of infeasible Problems: " + iInfeasible);
		System.out.println("Number of mixed integer Problems: " + iMIP03Lib);
		for(int i = iNetLib+iKeninninton+iInfeasible; i < iNetLib+iKeninninton+iInfeasible+iMIP03Lib; i++){
			System.out.println(sLine);
			System.out.println(i);
			System.out.println("name: " + mInstancce[i].name);
			
			//Start of skipping 4 big files and 1 infeasible greenbea. 
			if(mInstancce[i].name.equals("KEN-18")){
				System.out.println("!!too big!!");
				continue;
			}
			if(mInstancce[i].name.equals("OSA-30")){
				System.out.println("!!too big!!");
				continue;
			}
			if(mInstancce[i].name.equals("OSA-60")){
				System.out.println("!!too big!!");
				continue;
			}
			if(mInstancce[i].name.equals("PDS-20")){
				System.out.println("!!too big!!");
				continue;
			}
			/////GREENBEA_INFEASIBLE is generated manually////////
			if(mInstancce[i].name.equals("GREENBEA_INFEASIBLE")){
				System.out.println("Skip GREENBEA_INFEASIBLE!!!");
				continue;
			}
			//////////////////////////////////////////////////////
			//End of skipping 4 big files and 1 infeasible greenbea.
			System.out.println("source: " + mInstancce[i].source);
			System.out.println("description: " + mInstancce[i].description);

			String sDir = sNetLibProblemDir;
			if(i >= iNetLib+iKeninninton+iInfeasible) sDir = sMIP03LibProblemDir;
			System.out.println("originalFileName: " + (sDir + mInstancce[i].originalFileName));
			System.out.println("osDirectoty: " + mInstancce[i].osDirectoty);
			System.out.println("osFileName: " + mInstancce[i].osFileName);
			System.out.println("creating...");
			System.out.println(CommonUtil.mpsToOSiL(
					sDir+ mInstancce[i].originalFileName, 
					sOSRepositoryDir + mInstancce[i].osDirectoty + mInstancce[i].osFileName, 
					mInstancce[i].name, 
					mInstancce[i].source, 
					mInstancce[i].description));
		}
		System.out.println(sLine);
		System.out.println("END");
		return true;
	}//createOSRepository
	
	
	/**
	 * Write the sparse coefficient matrix related elements in an OSiL xml file. 
	 *
	 * <p>The coefMatrix (AMatrix) stores all the information in the A part of Ax ~ b, i.e. the linear part of all constraints</p>
	 *
	 * </p>
	 *
	 * @param isColumnMajor holds the value of whether the coefMatrix (AMatrix) holding linear constraint data is stored
	 * by column. If false, the matrix is stored by row.
	 * @param nonzeroValues holds the values of the vector element value in coefMatrix (AMatrix), which contains nonzero elements.
	 * @param nonzeroIndexes holds the values of the vector element rowIdx or colIdx in coefMatrix (AMatrix). If the matrix is
	 * stored by column (row), rowIdx (colIdx) is the vector of row (column) indexes.
	 * @param startIndexes holds the values of the vector element start in coefMatrix (AMatrix), which points to the start of a
	 * column (row) of nonzero elements in coefMatrix (AMatrix).
	 * @param mpsFileName holds the name of the file to be written to. The path is fixed at the xml folder of the impact project. 
	 * @param name
	 * @param source
	 * @param description
	 * @return whether user wants to clear the arrays passed in to save memory if the arrays
	 * will still be referenced, a false value is to be returned.
	 */
	public static boolean mpsToOSiL(String mpsFileName, String osilFileName, String instanceName, String instanceSource, String instanceDescription){
		drasys.or.mp.Problem problem = new Problem(1000, 1000);
		String sObjectiveName = "";
		double dObjectiveConstant = 0; 
		if(osilFileName.endsWith("e226.osil")) dObjectiveConstant = -7.113;
		try {
			FileReader fr = new FileReader(new File(mpsFileName));
			BufferedReader br = new BufferedReader(fr);
			br.readLine();
			br.readLine();
			String sLine = "";
			while(true){
				try {
					sLine = br.readLine();
					if(sLine.charAt(1) == 'N' || sLine.charAt(2) == 'N'){
						sObjectiveName = sLine.substring(4).trim();
						break;
					}					
				} 
				catch (Exception e) {
				}
			}
			br.close();
		} 
		catch (Exception e) {
			e.printStackTrace();
		}
		
		try{
			String sMPSFileName = mpsFileName;
			FileInputStream fis = new FileInputStream(sMPSFileName);
			InputStreamReader isr = new InputStreamReader(fis);
			MPSReader mpsReader = new MPSReader(isr);
			mpsReader.readProblem(problem);
		}
		catch(Exception e){
			e.printStackTrace();
		}
		
		int iNumberVariables = problem.sizeOfVariables();
		int iNumberConstrains = problem.sizeOfConstraints();
		int iNumberCoefMatrixValues = problem.sizeOfCoefficients();
		double[] mdObjCoef = new double[iNumberVariables];
		int[] miObjCoefIndex = new int[iNumberVariables];
		double[] mdVarLb = new double[iNumberVariables]; 
		double[] mdVarUb = new double[iNumberVariables];
		char[] mcVarType = new char[iNumberVariables];
		String[] msVarName = new String[iNumberVariables];
		double[] mdConUb = new double[iNumberConstrains];
		double[] mdConLb = new double[iNumberConstrains];
		String[] msConName = new String[iNumberConstrains];
		double[] mdValue = new double[iNumberCoefMatrixValues];
		int[] miRowIdx = new int[iNumberCoefMatrixValues];
		//int[] miColIdx = new int[iNumberCoefMatrixValues];
		int[] miStart = new int[iNumberVariables+1];
		
		Enumeration enumVar = problem.variables();
		VariableI var;
		while (enumVar.hasMoreElements()){
			var = (VariableI)enumVar.nextElement();
			int i=var.getColumnIndex();
			mdObjCoef[i] = var.getObjectiveCoefficient();
			miObjCoefIndex[i] = i;
			mdVarLb[i] = var.getLowerBound();
			mdVarUb[i] = var.getUpperBound();
			msVarName[i] = var.getName();

			byte bType = var.getType(); 
			switch (bType){
			case VariableI.BOOLEAN:
				mcVarType[i] = 'B';
			break;
			case VariableI.INTEGER:
				mcVarType[i] = 'I';
			break;
			case VariableI.REAL:
				mcVarType[i] = 'C';
			break;
			case VariableI.FREE:
				mcVarType[i] = 'C';
			break;
			}
		}		
		Enumeration enumCon = problem.constraints();
		ConstraintI con;

		while (enumCon.hasMoreElements()){
			con = (ConstraintI)enumCon.nextElement();
			int i = con.getRowIndex();
			msConName[i] = con.getName();
			switch (con.getType()){
			case ConstraintI.EQUAL:
				mdConUb[i] = con.getRightHandSide();
				mdConLb[i] = con.getRightHandSide();
			break;
			case Constraint.GREATER:
				mdConLb[i] = con.getRightHandSide();
				mdConUb[i] = Double.POSITIVE_INFINITY;
			break;
			case Constraint.LESS:
				mdConUb[i] = con.getRightHandSide();
				mdConLb[i] = Double.NEGATIVE_INFINITY;
			break;
			case Constraint.FREE:
				mdConLb[i] = Double.NEGATIVE_INFINITY;
				mdConUb[i] = Double.POSITIVE_INFINITY;
			break;
			case Constraint.RANGE:
				mdConLb[i] = con.getLowerRange();
				mdConUb[i] = con.getUpperRange();
			break;
			}
		}
		
		drasys.or.matrix.MatrixI matrix = problem.getCoefficientMatrix();
		Enumeration enumValue;
		drasys.or.matrix.MatrixElementI matrixEntry;
		int k = 0;
		/*
		for (int i = 0; i < iNumberConstrains; i++){
			miStart[i] = k;
			enumValue = matrix.rowElements(i);
			while (enumValue.hasMoreElements()) {
				matrixEntry = (drasys.or.matrix.MatrixElementI)enumValue.nextElement();
				mdValue[k] = matrixEntry.getValue();
				miColIdx[k] = matrixEntry.getColumnIndex();
				k++;
			}
		}
		*/
		for (int i = 0; i < iNumberVariables; i++){
			miStart[i] = k;
			enumValue = matrix.columnElements(i);
			while (enumValue.hasMoreElements()) {
				matrixEntry = (drasys.or.matrix.MatrixElementI)enumValue.nextElement();
				mdValue[k] = matrixEntry.getValue();
				miRowIdx[k] = matrixEntry.getRowIndex();
				k++;
			}
		}
		miStart[iNumberVariables] = k;
		
		String sFileName = osilFileName;
		OSiLWriter osilWriter = new OSiLWriter();
		
		osilWriter.setInstanceHeader(instanceName, instanceSource, instanceDescription);
		osilWriter.setVariables(iNumberVariables, msVarName, mdVarLb, mdVarUb, mcVarType, null, null);
		osilWriter.setConstraints(iNumberConstrains, msConName, mdConLb, mdConUb, null);
		osilWriter.addObjective(sObjectiveName, true, dObjectiveConstant, 1, mdObjCoef, miObjCoefIndex);
		osilWriter.setLinearConstraintCoefficients(iNumberCoefMatrixValues, true, mdValue, miRowIdx, miStart);
		//osilWriter.writeToStandardOutput();
		osilWriter.writeToFile(sFileName);
		return true;
	}//mpsToOSiL
	
	/**
	 * create the native dateTime from a the timeMillis, which is the millisecond
	 * since 1/1/1970. 
	 * 
	 * @param timeMillis holds the time represented in milliseconds since 1/1/1970.
	 * @return the converted native dateTime (Gregorian Calendar). 
	 */
	public static GregorianCalendar createNativeDateTime(long timeMillis){
		if(timeMillis <= 0){
			return new GregorianCalendar(1970, 0, 1, 0, 0, 0);
		}
		GregorianCalendar time = new GregorianCalendar();
		time.setTimeInMillis(timeMillis);
		return time;
	}//createNativeDateTime

	/**
	 * main for test purposes.
	 *
	 * </p>
	 *
	 * @param argv command line arguments.
	 */
	public static void main(String[] argv){
		//convert from mps to osil
		/*
		String[] msName = {"adlittle", "afiro", "kb2", "sc50a", "sc50b", "share2b", "blend"};
		String sMPSDir = "../../../OSRepository/other/MPS_netlib/netlib/data/";
		String sOSiLDir = "../../../OSRepository/linear/continuous/";
		for(int i = 0; i < msName.length; i++){
			System.out.println(CommonUtil.mpsToOSiL(sMPSDir+msName[i]+".mps", sOSiLDir+msName[i]+".osil", null, null, null));
		}
		*/
		//create OSRepository
		//CommonUtil.createOSRepository();
		//check OSRepository
		//CommonUtil.checkOSRepository();
		
		//System.out.println(XMLUtil.createXSDateTime(createNativeDateTime(System.currentTimeMillis())));
		
		/* Wayne Test
		 for(int i = 1; i <= 5; i++){
			CommonUtil.mpsToOSiL(
					"C:\\code\\OSRepository\\test\\wayne\\mps\\Law"+i+".mps",
					"C:\\code\\OSRepository\\test\\wayne\\mps\\Law"+i+".osil",
					"LAW"+i,
					"Aardal's paper on mixed integer programming", "No feasible solution.");
		}
		for(int i = 1; i <= 20; i++){
			CommonUtil.mpsToOSiL(
					"C:\\code\\OSRepository\\test\\wayne\\mps\\Problem"+i+".mps",
					"C:\\code\\OSRepository\\test\\wayne\\mps\\Problem"+i+".osil",
					"WAYNE_TEST_PROBLEM_"+i,
					"Aardal's paper on mixed integer programming", "No feasible solution.");
		}
		 */
		System.out.println(CommonUtil.getJobID(null));
		
	}//main
}//class CommonUtil
