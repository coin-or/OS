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
		iNumberIPAddress = iNumberIPAddress==0?0:1;
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
	 * mpsToOSiL and createOSRepository removed due to or124.jar license issues.
	 * See SVN for old code.
	 */
	
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
