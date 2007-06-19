/**
 * @(#)IOUtil 1.0 03/14/2004
 *
 * Copyright (c) 2004
 */
package org.optimizationservices.oscommon.util;
import java.io.BufferedReader;
import java.io.ByteArrayInputStream;
import java.io.ByteArrayOutputStream;
import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.FilenameFilter;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.Serializable;
import java.io.StringWriter;
import java.net.URL;
import java.util.ArrayList;
import java.util.Calendar;
import java.util.GregorianCalendar;
import java.util.StringTokenizer;

import sun.misc.BASE64Decoder;
import sun.misc.BASE64Encoder;
/**
 *
 * <P>The <code>IOUtil</code> class contains methods for performing
 * common basic input-output (I/O) operations, such as file reading/writing,
 * used by various components in the
 * Optimization Services (OS) framework. </p>
 *
 * </p>
 *
 * @author  Robert Fourer, Jun Ma, Kipp Martin
 * @version 1.0, 03/14/2004
 * @since   OS1.0
 */
public class IOUtil implements Serializable{
	/**
	 * The serializable class IOUtil needs to declare a static final serialVersionUID field of type long.
	 */
	private static final long serialVersionUID = 1L;
	/**
	 * m_sName holds the name of this class.
	 */
	public String m_sName ="IOUtil, implments serizlizable";

	/**
	 * Encode a plain string with base64 encoding. 
	 * 
	 * @param string holds the plain string to be encoded. 
	 * @return the base64 encoded string. 
	 */
	public static String encodeString(String string){
		return bytesToEncodedString(stringToBytes(string));
	}//encodeString

	/**
	 * Deconde a base64 encoded string. 
	 * 
	 * @param string holds the base64 encoded string to be decoded into a plain string. 
	 * @return the plain string that is decoded. 
	 */
	public static String decodeString(String encodedString){
		return bytesToString(encodedStringToBytes(encodedString));
	}//decodeString

	/**
	 * Read a file into a string (unencoded).
	 *
	 * </p>
	 *
	 * @param fileName holds the name of the file to read.
	 * @return the file in a string.
	 */
	public static String fileToString(String fileName ){
		FileInputStream fis = null;
		try{
			String returnVal = null;
			File file = new File(fileName);
			if( file.exists() && file.canRead()){
				fis = new FileInputStream(file);
				byte theBytes[] = new byte[(int)file.length()];
				if( ((long)fis.read(theBytes, 0, (int) file.length())) == file.length()){
					returnVal = new String(theBytes );
				}

			}
			if(fis != null) fis.close();
			return returnVal;
		}
		catch(Exception e){
			e.printStackTrace();
			return null;
		}
	}//fileToString

	/**
	 * Saves a string into a file.
	 *
	 * </p>
	 *
	 * @param string holds the string to be saved.
	 * @param fileName holds the name of the file to save the string.
	 * @return whether the string is saved to a file successfully.
	 */
	public static boolean stringToFile(String string, String fileName){
		try{
			byte[] bArray =  string.getBytes();
			FileOutputStream fos = new FileOutputStream(fileName);
			DataOutputStream dos = new DataOutputStream(fos);
			dos.write(bArray);
			fos.flush();
			dos.flush();
			fos.close();
			dos.close();
			return true;
		}
		catch(Exception e){
			e.printStackTrace();
			return false;
		}
	}//stringToFile

	/**
	 * Converts any file into a base64 encoded string.
	 *
	 * </p>
	 *
	 * @param fileName holds the name of the file to be converted to a base64 encoded string.
	 * @return the base64 encoded string from the file. The method returns null if an error occurs.
	 */
	public static String fileToEncodedString(String fileName){
		try{
			File file = new File(fileName);
			FileInputStream fis = new FileInputStream(file);
			DataInputStream dis = new DataInputStream(fis);

			int iArraySize = (int)file.length();
			byte[] bArray = new byte[iArraySize];
			dis.read(bArray);

			String sOut = (new BASE64Encoder()).encodeBuffer(bArray);
			fis.close();
			dis.close();
			return sOut;
		}
		catch(Exception e){
			e.printStackTrace();
			return null;
		}
	}//fileToEncodedString

	/**
	 * Decodes and saves a base64 encoded string into a file.
	 *
	 * </p>
	 *
	 * @param string holds base64 encoded string to be decoded and saved.
	 * @param fileName holds the name of the file to save the string.
	 * @return whether the encoded string is decoded and saved to a file successfully.
	 */
	public static boolean encodedStringToFile(String string, String fileName){
		try{
			byte[] bArray =  (new BASE64Decoder()).decodeBuffer(string);
			FileOutputStream fos = new FileOutputStream(fileName);
			DataOutputStream dos = new DataOutputStream(fos);
			dos.write(bArray);
			fos.flush();
			dos.flush();
			fos.close();
			dos.close();
			return true;
		}
		catch(Exception e){
			e.printStackTrace();
			return false;
		}
	}//encodedStringToFile

	/**
	 * Converts an array of bytes into a string (unencoded).
	 *
	 * </p>
	 *
	 * @param byteArray holds the array of bytes to be converted to a string.
	 * @return the string from the bytes.
	 */
	public static String bytesToString(byte[] byteArray) {
		return (new String(byteArray));
	}//bytesToString

	/**
	 * Return a string (unencoded) in an array of bytes.
	 *
	 * </p>
	 *
	 * @param string holds string to be put in an array of bytes.
	 * @return the string in an array of bytes.
	 */
	public static byte[] stringToBytes(String string){
		return string.getBytes();
	}//stringToBytes

	/**
	 * Converts an array of bytes into a base64 encoded string.
	 *
	 * </p>
	 *
	 * @param byteArray holds the array of bytes to be converted to a base64 encoded string.
	 * @return the base64 encoded string from the bytes.
	 */
	public static String bytesToEncodedString(byte[] byteArray) {
		return (new BASE64Encoder()).encodeBuffer(byteArray);
	}//bytesToEncodedString

	/**
	 * Decodes a base64 encoded string and return them in an array of bytes.
	 *
	 * </p>
	 *
	 * @param string holds base64 encoded string to be decoded and put in an array of bytes.
	 * @return the decoded string in an array of bytes. The method returns null if an error occurs.
	 */
	public static byte[] encodedStringToBytes(String string){
		try{
			return (new BASE64Decoder()).decodeBuffer(string);
		}
		catch(Exception e){
			e.printStackTrace();
			return null;
		}
	}//encodedStringToBytes

	/**
	 * Return an object in an array of bytes.
	 *
	 * </p>
	 *
	 * @param object holds the serializable object to be put into an array of bytes.
	 * @return the object in an array of bytes. The object has to implement the interface of
	 * <code>java.io.Serializable</code>. The method returns null if an error occurs.
	 */
	public static byte[] objectToBytes(Object object){
		byte[] bArray = null;
		try{
			ByteArrayOutputStream baos = new ByteArrayOutputStream();
			ObjectOutputStream oos = new ObjectOutputStream(baos);
			oos.writeObject(object);
			oos.flush();
			bArray = baos.toByteArray();
			baos.close();
			oos.close();
			return bArray;
		}
		catch(Exception e){
			e.printStackTrace();
			return null;
		}
	}//objectToBytes

	/**
	 * Converts an array of bytes into an object.
	 *
	 * </p>
	 *
	 * @param byteArray holds the array of bytes to be converted to an object.
	 * @return the object. The object can then be type cast into a more concrete object
	 * that implements the <code>java.io.Serializable</code>. The method returns null if
	 * an error occurs.
	 */
	public static Object bytesToObject(byte[] byteArray){
		try{
			ByteArrayInputStream bais = new ByteArrayInputStream(byteArray);
			ObjectInputStream ois = new ObjectInputStream(bais);
			Object object = ois.readObject();
			bais.close();
			ois.close();
			return object;
		}
		catch(Exception e){
			e.printStackTrace();
			return null;
		}
	}//bytesToObject

	/**
	 * Return an object in a base64 encoded string.
	 *
	 * </p>
	 *
	 * @param object holds the serializable object to be encoded to a string.
	 * @return the object in a base64 encoded string. The object has to implement the interface of
	 * <code>java.io.Serializable</code>. The method returns null if an error occurs.
	 */
	public static String objectToEncodedString(Object object){
		try{
			return bytesToEncodedString(objectToBytes(object));
		}
		catch(Exception e){
			e.printStackTrace();
			return null;
		}
	}//objectToEncodedString

	/**
	 * Decodes a base64 encoded string and return them in an object.
	 *
	 * </p>
	 *
	 * @param string holds base64 encoded string to be decoded and converted to an object.
	 * @return the object. The object can then be type cast into a more concrete object
	 * that implements the <code>java.io.Serializable</code>. The method returns null if
	 * an error occurs.
	 */
	public static Object encodedStringToObject(String string){
		try{
			return bytesToObject(encodedStringToBytes(string));
		}
		catch(Exception e){
			e.printStackTrace();
			return null;
		}
	}//encodedStringToObject

	/**
	 * Save a object into a file.
	 *
	 * </p>
	 *
	 * @param object holds the serializable object to be saved into a file.
	 * @param fileName holds the name of the file to save the object.
	 * @return whether the object is saved to a file successfully. The object has
	 * to implement the interface of <code>java.io.Serializable</code>.
	 */
	public static boolean objectToFile(Object object, String fileName){
		try{
			FileOutputStream fos = new FileOutputStream(fileName);
			ObjectOutputStream oos = new ObjectOutputStream(fos);
			oos.writeObject(object);
			oos.flush();
			fos.close();
			oos.close();
			return true;
		}
		catch(Exception e){
			e.printStackTrace();
			return false;
		}
	}//objectToFile

	/**
	 * Converts file that was previously serialized from an object into an object in memory.
	 *
	 * </p>
	 *
	 * @param fileName holds the name of the file to was previsouly serialized from an object.
	 * @return the object. The object can then be type cast into a more concrete object
	 * that implements the <code>java.io.Serializable</code>. The method returns null if
	 * an error occurs.
	 */
	public static Object fileToObject(String fileName){
		try{
			FileInputStream fis = new FileInputStream(fileName);
			ObjectInputStream ois = new ObjectInputStream(fis);
			Object object = ois.readObject();
			fis.close();
			ois.close();
			return object;
		}
		catch(Exception e){
			e.printStackTrace();
			return null;
		}
	}//fileToObject

	/**
	 * Save an array of bytes into a file.
	 *
	 * </p>
	 *
	 * @param byteArray holds an array of bytes to be saved into a file.
	 * @param fileName holds the name of the file to save the array of bytes.
	 * @return whether the array of bytes is saved to a file successfully.
	 */
	public static boolean bytesToFile(byte[] byteArray, String fileName){
		try{
			FileOutputStream fos = new FileOutputStream(fileName);
			DataOutputStream dos = new DataOutputStream(fos);
			dos.write(byteArray);
			dos.flush();
			fos.close();
			dos.close();
			return true;
		}
		catch(Exception e){
			e.printStackTrace();
			return false;
		}
	}//bytesToFile

	/**
	 * Retrieve a file into an array of bytes.
	 *
	 * </p>
	 *
	 * @param fileName holds the name of the file to be retrieved into the array of bytes.
	 * @return the array of bytes that is retrieved from the file.
	 */
	public static byte[] fileToBytes(String fileName){
		try{
			FileInputStream fis = new FileInputStream(fileName);
			byte[] bArray = new byte[fis.available()];
			fis.read(bArray);
			fis.close();
			return bArray;
		}
		catch(Exception e){
			e.printStackTrace();
			return null;
		}
	}//bytesToFile

	/**
	 * Converts a string file to a binary file.
	 *
	 * </p>
	 *
	 * @param inFileName holds the name of the string file.
	 * @param outFileName holds the name of the binary file to be converted.
	 * @return whether the conversion from string file to binary is successful or not.
	 */
	public static boolean stringFileToBinaryFile(String inFileName, String outFileName){
		String sInput = null;
		try{
			sInput=fileToString(inFileName);
		}
		catch(Exception e){
			e.printStackTrace();
			return false;
		}
		byte[] bArray =null;
		try{
			bArray = encodedStringToBytes(sInput);
		}
		catch(Exception e){
			e.printStackTrace();
			return false;
		}
		return bytesToFile(bArray, outFileName);
	}//stringFileToBinaryFile

	/**
	 * Reads from a file to a string in memory.
	 *
	 * </p>
	 *
	 * @param fileName holds the file name of the file to be converted into a string
	 * @return the string to that is constructed from the file. A null value will be returned if
	 * there is any error in the reading.
	 */
	public static String readStringFromFile(String fileName){
		String sOut = "";
		try{
			StringBuffer sBuffer = new StringBuffer();
			String sLine = "";
			FileReader fr = new FileReader(new File(fileName));
			BufferedReader br = new BufferedReader(fr);
			while((sLine = br.readLine())!=null){
				sBuffer.append(sLine+"\n");
			}
			sOut = sBuffer.toString();
			fr.close();
			br.close();
			return sOut;
		}
		catch(Exception e){
			//e.printStackTrace();
			return null;
		}
	}//readStringFromFile

	/**
	 * Writes a string to a file. 
	 * @param string holds the string to be written to a file.
	 * @param fileName holds the file name of the file to save the string.
	 * @return whether the string is saved to the file successfully or not.
	 */
	public static boolean writeStringToFile(String string, String fileName){
		try{
			FileWriter fw = new FileWriter(new File(fileName));
			fw.write(string);
			fw.close();
			return true;
		}
		catch(Exception e){
			e.printStackTrace();
			return false;
		}
	}//writeStringToFile

	/**
	 * Appends a string to a file. 
	 * @param string holds the string to be appended to a file.
	 * @param fileName holds the file name of the file to append the string.
	 * @return whether the string is appended to the file successfully or not.
	 */
	public static boolean appendStringToFile(String string, String fileName){
		try{
			FileWriter fw = new FileWriter(new File(fileName), true);
			fw.write(string);
			fw.close();
			return true;
		}
		catch(Exception e){
			e.printStackTrace();
			return false;
		}
	}//appendStringToFile

	/**
	 * Reads from a url to a string in memory.
	 *
	 * </p>
	 *
	 * @param url holds the link address of the content to be converted into a string.
	 * @return the string constructed from reading the content of the link. A null value will be returned if
	 * there is any error in the reading.
	 */
	public static String readStringFromURL(String url){
		StringBuffer sBuffer = new StringBuffer();
		String sLine;
		try{
			URL urlObject = new URL(url);
			//urlObject.getContent();
			//urlObject.getFile();
			BufferedReader br = new BufferedReader(new InputStreamReader(urlObject.openStream()));
			while ((sLine = br.readLine()) != null){
				sBuffer.append(sLine + "\n");
			}
			br.close();
			return sBuffer.toString();
		}
		catch(IOException e){
			e.printStackTrace();
			return null;
		}
		catch(Exception e){
			e.printStackTrace();
			return null;
		}
	}//readStringFromURI

	/**
	 * Reads from a url to a string in memory.
	 *
	 * </p>
	 *
	 * @param url holds the link address of the content to be converted into a string.
	 * @return the bytes constructed from reading the content of the link. A null value will be returned if
	 * there is any error in the reading.
	 */
	public static byte[] readBytesFromURL(String url){
		try{
			URL urlObject = new URL(url);
			urlObject.getContent();
			InputStream is = urlObject.openStream();
			int i, m, n = 0;
			byte[] mbResult = new byte[0];
			byte[] mbChunk;
			byte[] mbTemp;			
			if (is==null) return null;
			m = is.available();		
			if (m < 256) m = 256;
			mbChunk = new byte[m];
			while (true){
				if (++n == 3 && m < 16000){
					n = 0;
					mbChunk = new byte[m *= 8];
				}

				if ((i = is.read(mbChunk)) < 0) break;				
				mbTemp = new byte[mbResult.length + i];
				if (mbResult.length > 0) System.arraycopy(mbResult, 0, mbTemp, 0, mbResult.length);
				System.arraycopy(mbChunk, 0, mbTemp, mbResult.length, i);
				mbResult = mbTemp;
			}
			return mbResult;
		}
		catch (Exception e){
			e.printStackTrace();
			return null;
		}
	}//readBytesFromURL

	/**
	 *
	 * @param string holds the string to be converted to an inputstream.
	 * @return an inputStream that is constructed from the string.
	 */
	public static InputStream stringToInputStream(String string){
		InputStream is = new ByteArrayInputStream(string.getBytes());
		return is;
	}//stringToInputStream

	/**
	 *
	 * @param file holds the file to converted to an inputstream.
	 * @return an inputStream that is constructed from the file.
	 */
	public static InputStream fileToInputStream(String fileName){
		try{
			FileInputStream fis = new FileInputStream(fileName);
			return fis;
		}
		catch(Exception e){
			return null;
		}
	}//fileToInputStream

	/**
	 *
	 * @param file holds the file to converted to an Outputstream.
	 * @return an OutputStream that is constructed from the file.
	 */
	public static OutputStream fileToOnputStream(String fileName){
		try{
			FileOutputStream fos = new FileOutputStream(fileName);
			return fos;
		}
		catch(Exception e){
			return null;
		}
	}//fileToInputStream

	/// <summary>
	/// logs message to a file. 
	/// </summary> 
	/// <param name="logMessage">holds the log message to be appended to the log file.</param>
	/// <param name="logFileName">holds the log file name. 
	/// The method uses a default log file if the file name is null or empty.</param>
	/// <returns>whether the string is appended to the file successfully or not.</returns>
	public static boolean log(String logMessage, String logFileName){
		try{
			String sLogFileName = OSParameter.LOG_FILE;
			if(logFileName != null && logFileName.length() > 0) sLogFileName = logFileName;
			FileWriter fw = new FileWriter(new File(sLogFileName), true);
			fw.write("\r\nLog Entry: \n\r");
			Calendar calendar = new GregorianCalendar();
			fw.write(calendar.getTime().toString());
			fw.write("\n\r\n\r  :\n\r");
			fw.write("\n\r  :" + logMessage + "\n\r");
			fw.write("\n\r---------------------------------\n\r");
			fw.flush();
			fw.close();
			return true;
		}
		catch(Exception e){
			e.printStackTrace();
			return false;
		}		
	}//log

	/**
	 * Print out a string message. 
	 * @param s holds the string message to print.
	 * @param outputStream holds the output stream to print the message to
	 * @return whether the print is successful. 
	 */
	public static boolean print(String s, OutputStream outputStream){
		try {
			if(outputStream == null){
				System.out.print(s);
			}
			else{
				outputStream.write(s.getBytes());
			}
			return true;
		} 
		catch (Exception e) {
			e.printStackTrace();
			return false;
		}

	}//print with the output stream 

	/**
	 * Print out a line feed "\n". 
	 * @return whether the print is successful. 
	 */
	public static boolean println(){
		return print("\n");
	}//println

	/**
	 * Print out a string message with an extra line feed "\n". 
	 * @param s holds the string message to print. 
	 * @return whether the print is successful. 
	 */
	public static boolean println(String s){
		return print(s+"\n");
	}//println

	/**
	 * Print out a string message. 
	 * @param s holds the string message to print. 
	 * @return whether the print is successful. 
	 */
	public static boolean print(String s){
		OutputStream outputStream = null;
		if(OSParameter.DEFAULT_OUTPUT == OSConstant.STD_OUT){
			outputStream = System.out;
			return print(s, outputStream);
		}
		else if(OSParameter.DEFAULT_OUTPUT == OSConstant.STD_ERR){
			outputStream = System.err;
			return print(s, outputStream);
		}
		else if(OSParameter.DEFAULT_OUTPUT == OSConstant.FILE_OUT){
			try {
				outputStream = new FileOutputStream(OSParameter.PRINT_FILE, OSParameter.APPEND_PRINT_FILE);

			} 
			catch (FileNotFoundException e){
				e.printStackTrace();
			}
			return print(s, outputStream);
		}
		else{//if(ImpactOption.DefaultOutput == ImpactConstant.StringOut)
			OSParameter.PRINT_STRING_WRITER.write(s);
			return true;
		}	
	}//print

	/**
	 * Convert printStackTrace() to a String. 
	 * 
	 * @param e holds the exception to be redirected. 
	 * @return the converted string. 
	 */
	public static String exceptionStackToString(Exception e) {
		try {
			StringWriter sw = new StringWriter();
			PrintWriter pw = new PrintWriter(sw);
			e.printStackTrace(pw);
			return sw.toString();
		}
		catch(Exception e2) {
			return "exceptionStackToString error in IOUtil";
		}
	}//exceptionStackToString


	/**
	 * clean up disks, mainly including deleting temp files. 
	 * 
	 * @return whether the clean up is successful or not. 
	 */
	public static boolean cleanUpDisk(){
		long lTempFileKeepTime;
		double dFreeDiskSpace = -1;
		try{
			dFreeDiskSpace = getFreeDiskSpace(OSParameter.CODE_DRIVE);
		}
		catch(Exception e){
			IOUtil.log(exceptionStackToString(e), null);
		}
		if(dFreeDiskSpace != -1 && dFreeDiskSpace < OSParameter.MINIMUM_DISKSPACE_TRIGGER){
			lTempFileKeepTime= OSParameter.TEMP_FILE_MIN_DAYS*86400000
			+OSParameter.TEMP_FILE_MIN_HOURS*3600000
			+OSParameter.TEMP_FILE_MIN_MINUTES*60000
			+OSParameter.TEMP_FILE_MIN_SECONDS*1000;
		}
		else{
			lTempFileKeepTime= OSParameter.TEMP_FILE_MAX_DAYS*86400000
			+OSParameter.TEMP_FILE_MAX_HOURS*3600000
			+OSParameter.TEMP_FILE_MAX_MINUTES*60000
			+OSParameter.TEMP_FILE_MAX_SECONDS*1000;
		}

		IOUtil ioUtil = new IOUtil();
		DiskCleanUpFilter filter = ioUtil.new DiskCleanUpFilter();
		filter.m_lTempFileKeepTime = lTempFileKeepTime;

		File dir;
		int iFolderNumber = OSParameter.CLEAN_UP_FOLDERS==null?0:OSParameter.CLEAN_UP_FOLDERS.length;
		int i, j;
		//delete files and dirs
		for(i = 0; i < iFolderNumber; i++){
			dir = new File(OSParameter.CLEAN_UP_FOLDERS[i]);
			String[] msFiles = dir.list(filter);
			int iFileNumber = msFiles==null?0:msFiles.length;
			String sPath;
			for(j = 0; j < iFileNumber; j++){
				sPath = OSParameter.CLEAN_UP_FOLDERS[i] + msFiles[j];
				if(isDir(sPath)){
					deleteDir(sPath);
				}
				else{
					deleteFile(sPath);
				}
			}
		}
		//backup files and dirs
		if((OSParameter.SERVICE_TYPE != null && OSParameter.SERVICE_TYPE.equals("registry")) || 
				(OSParameter.SERVICE_TYPE != null && OSParameter.SERVICE_TYPE.equals("scheduler") && OSParameter.SCHEDULER_WITH_REGISTRY)){
			File registryLogFile = new File(OSParameter.REGISTRY_LOG_FILE);
			if(registryLogFile.exists()){
				if(registryLogFile.length() >= OSParameter.MAX_LOG_FILE_SIZE){
					String sTimeStamp = XMLUtil.createXSDateTime(new GregorianCalendar());
					sTimeStamp = sTimeStamp.replace(':', '.');
					String sBackUpRegistryLogFile = OSParameter.BACKUP_FOLDER + "registryLog_" + sTimeStamp + ".txt";
					IOUtil.moveFile(OSParameter.REGISTRY_LOG_FILE, sBackUpRegistryLogFile);
					IOUtil.createFile(OSParameter.REGISTRY_LOG_FILE);
				}
			}		
			File registrySummaryReport = new File(OSParameter.REGISTRY_SUMMARY_REPORT);
			if(registrySummaryReport.exists()){
				if(registrySummaryReport.length() >= OSParameter.MAX_LOG_FILE_SIZE){
					String sTimeStamp = XMLUtil.createXSDateTime(new GregorianCalendar());
					sTimeStamp = sTimeStamp.replace(':', '.');
					String sBackUpRegistrySummaryReport = OSParameter.BACKUP_FOLDER + "registrySummaryReport_" + sTimeStamp + ".txt";
					IOUtil.moveFile(OSParameter.REGISTRY_SUMMARY_REPORT, sBackUpRegistrySummaryReport);
					IOUtil.createFile(OSParameter.REGISTRY_SUMMARY_REPORT);
				}
			}				
			File registryDetailedReport = new File(OSParameter.REGISTRY_DETAILED_REPORT);
			if(registryDetailedReport.exists()){
				if(registryDetailedReport.length() >= OSParameter.MAX_LOG_FILE_SIZE){
					String sTimeStamp = XMLUtil.createXSDateTime(new GregorianCalendar());
					sTimeStamp = sTimeStamp.replace(':', '.');
					String sBackUpRegistryDetailedReport = OSParameter.BACKUP_FOLDER + "registryDetailedReport_" + sTimeStamp + ".txt";
					IOUtil.moveFile(OSParameter.REGISTRY_DETAILED_REPORT, sBackUpRegistryDetailedReport);
					IOUtil.createFile(OSParameter.REGISTRY_DETAILED_REPORT);
				}
			}				
		}
		if(OSParameter.SERVICE_TYPE == null || !OSParameter.SERVICE_TYPE.equals("registry")){
			File logFile = new File(OSParameter.LOG_FILE);
			if(logFile.exists()){
				if(logFile.length() >= OSParameter.MAX_LOG_FILE_SIZE){
					String sTimeStamp = XMLUtil.createXSDateTime(new GregorianCalendar());
					sTimeStamp = sTimeStamp.replace(':', '.');
					String sBackUpLogFile = OSParameter.BACKUP_FOLDER + "log_" + sTimeStamp + ".txt";
					IOUtil.moveFile(OSParameter.LOG_FILE, sBackUpLogFile);
					IOUtil.createFile(OSParameter.LOG_FILE);
				}
			}	
		}		
		File printFile = new File(OSParameter.PRINT_FILE);
		if(printFile.exists()){
			if(printFile.length() >= OSParameter.MAX_LOG_FILE_SIZE){
				String sTimeStamp = XMLUtil.createXSDateTime(new GregorianCalendar());
				sTimeStamp = sTimeStamp.replace(':', '.');
				String sBackUpPrintFile = OSParameter.BACKUP_FOLDER + "print_" + sTimeStamp + ".txt";
				IOUtil.moveFile(OSParameter.PRINT_FILE, sBackUpPrintFile);
				IOUtil.createFile(OSParameter.PRINT_FILE);
			}
		}			
		File osplFile = new File(OSParameter.PROCESS_FILE+"_backup");
		if(osplFile.exists()){
			String sTimeStamp = XMLUtil.createXSDateTime(new GregorianCalendar());
			sTimeStamp = sTimeStamp = sTimeStamp.replace(':', '.');
			String sBackUpOSpLFile = OSParameter.BACKUP_FOLDER + "OSpL_" + sTimeStamp + ".xml";
			IOUtil.copyFile(OSParameter.PROCESS_FILE+"_backup", sBackUpOSpLFile);
		}			
		return true;
	}//cleanUpDisk

	/**
	 * <P>The <code>DiskCleanUpFilter</code> class is an internal 
	 *file name filter class called by <code>cleanUpDisk</code>.
	 */
	protected class DiskCleanUpFilter implements FilenameFilter{

		/**
		 * m_lTempFileKeepTime holds the time to keep the temp file. 
		 */
		protected long m_lTempFileKeepTime;

		/**
		 * Tests if a specified file should be included in a file list. 
		 * It implements the abstract accept method in FilenameFilter. 
		 * 
		 * @param dir the directory in which the file was found.
		 * @param name the name of the file.
		 */
		public boolean accept(File dir, String name){
			boolean bAccept = false;			
			File file = new File(dir, name);

			Calendar calendar = Calendar.getInstance();
			long lNow = calendar.getTimeInMillis();
			long lLastModified = file.lastModified(); 
			long lDifference = lNow - lLastModified ;

			if( lDifference > m_lTempFileKeepTime){
				bAccept = true;
			}
			else if(name.endsWith(".tmp") || 
					name.endsWith(".temp")){
				bAccept = true;
			}

			return bAccept;
		}//accept

	}//DiskCleanUpFilter

	/**
	 * check if a file or directory exists. 
	 * 
	 * @param path holds the the file or dir path to check. 
	 * @return whether a file or directory exists. 
	 */
	public static boolean existsFileOrDir(String path){
		File f;
		try {
			f = new File(path);			
			return f.exists();
		} 
		catch (Exception e) {
			return false;
		}
	}//existsFile

	/**
	 * get the last write time of the file. 
	 * @param file holds the name of the file to check. 
	 * @return the last write time of the file in millisecond.  
	 */
	public static long getLastWriteTime(String file){
		File f = new File(file);
		return f.lastModified();
	}//getLastWriteTime

	/**
	 * test whether a path is a directory or not. 
	 * @param path holds the file or dir path. 
	 * @return true if the path is not a directory, false otherwise. 
	 */
	public static boolean isDir(String path){
		try {
			File file = new File(path);
			return file.isDirectory();
		} 
		catch (Exception e) {
			return false;
		}
	}//isDir

	/**
	 * Create a file. 
	 * 
	 * @param file holds the name of the file to create. 
	 * @return whether the file is created successfully. 
	 */
	public static boolean createFile(String file){
		try {
			File newFile = new File(file);
			newFile.createNewFile();
			return true;
		} 
		catch (Exception e) {
			IOUtil.log(IOUtil.exceptionStackToString(e), null);
			return false;
		}
	}//createFile

	/**
	 * delete a file. 
	 * 
	 * @param file holds the name of the file to delete. 
	 * @return whether the file is deleted successfully. 
	 */
	public static boolean deleteFile(String file){
		try{
			File deleteFile = new File(file);
			deleteFile.delete();
			return true;
		}
		catch(Exception e){
			IOUtil.log(IOUtil.exceptionStackToString(e), null);
			return false;
		}
	}//deleteFile

	/**
	 * copy a file. 
	 * 
	 * @param from holds the file to copy from.
	 * @param to holds the file to copy to.
	 * @return whether the file is copied successfully. 
	 */
	public static boolean copyFile(String from, String to) {
		try {
			FileInputStream fis  = new FileInputStream(from);
			FileOutputStream fos = new FileOutputStream(to);
			byte[] buf = new byte[1024];
			int i = 0;
			while((i=fis.read(buf))!=-1) {
				fos.write(buf, 0, i);
			}
			fis.close();
			fos.close();
			return true;
		} 
		catch (FileNotFoundException e) {
			IOUtil.log(IOUtil.exceptionStackToString(e), null);
			return false;
		} 
		catch (IOException e) {
			IOUtil.log(IOUtil.exceptionStackToString(e), null);
			return false;
		}
		catch (Exception e) {
			IOUtil.log(IOUtil.exceptionStackToString(e), null);
			return false;
		}
	}//copyFile

	/**
	 * move a file. 
	 * 
	 * @param from holds the file to move from.
	 * @param to holds the file to move to.
	 * @return whether the file is moved successfully. 
	 */
	public static boolean moveFile(String from, String to) {
		try {
			File fromFile = new File(from);
			File toFile = new File(to);
			if(fromFile.exists() && toFile.exists()){
				toFile.delete();
			}
			boolean success = fromFile.renameTo(toFile);
			if(!success) throw new Exception("move file from " + from + " to " + to + " not successfull.");
			else return true;
		} 
		catch (Exception e) {
			IOUtil.log(IOUtil.exceptionStackToString(e), null);
			return false;
		}
	}//moveFile

	/**
	 * Make a directory. 
	 * 
	 * @param dir holds the directory path
	 * @return whether the directory is made successfully. 
	 */
	public static boolean makeDir(String dir){
		try {
			File newDir = new File(dir);
			newDir.mkdir();	
			return true;
		} 
		catch (Exception e) {
			IOUtil.log(IOUtil.exceptionStackToString(e), null);
			return false;
		}
	}//makeDir

	/**
	 * Delete a directory. 
	 * 
	 * @param dir holds the directory path
	 * @return whether the directory is deleted successfully. 
	 */
	static public boolean deleteDir(String dir) {
		try {
			File delDir = new File(dir);
			if( delDir.exists() ) {
				File[] files = delDir.listFiles();
				for(int i=0; i<files.length; i++) {
					if(files[i].isDirectory()) {
						deleteDir(files[i].getCanonicalPath());
					}
					else {
						files[i].delete();
					}
				}
			}
			return( delDir.delete() );
		} 
		catch (Exception e) {
			IOUtil.log(IOUtil.exceptionStackToString(e), null);
			return false;
		}	
	}//deleteDir

	/**
	 * copy directory. 
	 * 
	 * @param fromDir holds the directory to copy from.
	 * @param toDir holds the directory to copy to.
	 * @return whether the directory is copied successfully. 
	 */
	static public boolean copyDir(String fromDir, String toDir) {
		try {
			String sPathSeparator = System.getProperty("file.separator");
			File[] mfFiles;
			if(!toDir.endsWith(sPathSeparator)){ 
				toDir += System.getProperty("file.separator");
			}
			File fFromDir = new File(fromDir);
			File fToDir = new File(toDir);
			if(!fToDir.exists()){
				makeDir(toDir);
			}
			mfFiles = fFromDir.listFiles();
			int iFiles = mfFiles==null?0:mfFiles.length;
			for(int i = 0; i < iFiles; i++){
				if(mfFiles[i].isDirectory()) {
					String sFromDir = mfFiles[i].getCanonicalPath();
					String sToDir = toDir + mfFiles[i].getName();
					copyDir(sFromDir, sToDir);
				}
				else{ 
					String sFromFile = mfFiles[i].getCanonicalPath();
					String sToFile = toDir + mfFiles[i].getName();
					copyFile(sFromFile, sToFile);
				}
			}
			return true;
		} 
		catch (Exception e) {
			IOUtil.log(IOUtil.exceptionStackToString(e), null);
			return false;
		}	
	}//copyDir

	/**
	 * move directory. 
	 * 
	 * @param fromDir holds the directory to move from.
	 * @param toDir holds the directory to move to.
	 * @return whether the directory is copied successfully. 
	 */
	static public boolean moveDir(String fromDir, String toDir) {
		try {
			String sPathSeparator = System.getProperty("file.separator");
			File[] mfFiles;
			if(!toDir.endsWith(sPathSeparator)){ 
				toDir += System.getProperty("file.separator");
			}
			File fFromDir = new File(fromDir);
			File fToDir = new File(toDir);
			if(!fToDir.exists()){
				makeDir(toDir);
			}
			mfFiles = fFromDir.listFiles();
			int iFiles = mfFiles==null?0:mfFiles.length;
			for(int i = 0; i < iFiles; i++){
				if(mfFiles[i].isDirectory()) {
					String sFromDir = mfFiles[i].getCanonicalPath();
					String sToDir = toDir + mfFiles[i].getName();
					moveDir(sFromDir, sToDir);
				}
				else{ 
					String sFromFile = mfFiles[i].getCanonicalPath();
					String sToFile = toDir + mfFiles[i].getName();
					moveFile(sFromFile, sToFile);
				}
			}
			deleteDir(fromDir);
			return true;
		} 
		catch (Exception e) {
			IOUtil.log(IOUtil.exceptionStackToString(e), null);
			return false;
		}	
	}//moveDir

	/**
	 * Get the current directory. Note the path is denoted by "/". 
	 * If there any error, null will be returned.  
	 * @return the current directory in a path ending with "/"
	 */
	public static String getCurrentDir(){
		try {
			File dir = new File (".");
			String sCurrentDir = dir.getCanonicalPath();
			sCurrentDir = sCurrentDir.replace('\\', '/');
			if(!sCurrentDir.endsWith("/")){
				sCurrentDir += "/";
			}
			return sCurrentDir;
		}
		catch(Exception e) {
			IOUtil.log(IOUtil.exceptionStackToString(e), null);
			return null;
		}	     

	}//getCurrentDir

	/**
	 * Get the parent directory. Note the path is denoted by "/". 
	 * If there any error, null will be returned.  
	 * @return the parent directory in a path ending with "/"
	 */
	public static String getParentDir(){
		try {
			File dir = new File ("..");
			String sCurrentDir = dir.getCanonicalPath();
			sCurrentDir = sCurrentDir.replace('\\', '/');
			if(!sCurrentDir.endsWith("/")){
				sCurrentDir += "/";
			}
			return sCurrentDir;
		}
		catch(Exception e) {
			IOUtil.log(IOUtil.exceptionStackToString(e), null);
			return null;
		}	     
	}//getParentDir

	/**
	 * get free disk space.
	 *
	 * @param path holds the path to get free space for, (including the colon on the windows system.) 
	 * @return the amount of free drive space on the drive
	 * @throws IOException if an error occurs
	 */
	public static double getFreeDiskSpace(String path)throws IOException {
		if (path == null) {
			throw new IllegalArgumentException("Path must not be null");
		}
		String sOS = System.getProperty("os.name").toLowerCase();
		if(sOS.indexOf("indow") >= 0){ 
			if (path.length() > 2 && path.charAt(1) == ':') {
				path = path.substring(0, 2);  // seems to make it work
			}
			// build and run the 'dir' command
			String[] cmdAttrbs = new String[] {"cmd.exe", "/C", "dir /-c " + path};

			// read in the output of the command to an ArrayList
			BufferedReader in = null;
			String line = null;
			ArrayList<String> lines = new ArrayList<String>();
			try {
				Process proc = Runtime.getRuntime().exec(cmdAttrbs);          
				in = new BufferedReader(new InputStreamReader(proc.getInputStream()));
				line = in.readLine();
				while (line != null) {
					line = line.toLowerCase().trim();
					lines.add(line);
					line = in.readLine();
				}
			} 
			finally {
				try {
					if (in != null) {
						in.close();
					}
				} catch (IOException ioe) {
					// ignore
				}	
			}
			if (lines.size() == 0) {
				// unknown problem, throw exception
				throw new IOException(
						"Command line 'dir /c' did not return any info " +
						"for command '" + cmdAttrbs[2] + "'");
			}
			// now iterate over the lines we just read and find the LAST
			// non-empty line (the free space bytes should be in the last element
			// of the ArrayList anyway, but this will ensure it works even if it's
			// not, still assuming it is on the last non-blank line)
			double bytes = -1.0;
			int i = lines.size() - 1;
			int bytesStart = 0;
			int bytesEnd = 0;
			outerLoop: while (i > 0) {
				line = (String) lines.get(i);
				if (line.length() > 0) {
					// found it, so now read from the end of the line to find the
					// last numeric character on the line, then continue until we
					// find the first non-numeric character, and everything between
					// that and the last numeric character inclusive is our free
					// space bytes count
					int j = line.length() - 1;
					innerLoop1: while (j >= 0) {
						char c = line.charAt(j);
						if (Character.isDigit(c)) {
							// found the last numeric character, this is the end of
							// the free space bytes count
							bytesEnd = j + 1;
							break innerLoop1;
						}
						j--;
					}
					innerLoop2: while (j >= 0) {
						char c = line.charAt(j);
						if (!Character.isDigit(c) && c != ',' && c != '.') {
							// found the next non-numeric character, this is the
							// beginning of the free space bytes count
							bytesStart = j + 1;
							break innerLoop2;
						}
						j--;
					}
					break outerLoop;
				}
			}

			// remove commas and dots in the bytes count
			StringBuffer buf = new StringBuffer(line.substring(bytesStart, bytesEnd));
			for (int k = 0; k < buf.length(); k++) {
				if (buf.charAt(k) == ',' || buf.charAt(k) == '.') {
					buf.deleteCharAt(k--);
				}
			}
			bytes = Double.parseDouble(buf.toString());
			return bytes;
		}
		else{//"nix systems"
			if (path.length() == 0) {
				throw new IllegalArgumentException("Path must not be empty");
			}
			// build and run the 'df' command
			String[] cmdAttribs = new String[] {"df", path};

			// read the output from the command until we come to the second line
			double bytes = -1.0;
			BufferedReader in = null;
			try {
				Process proc = Runtime.getRuntime().exec(cmdAttribs);          
				in = new BufferedReader(new InputStreamReader(proc.getInputStream()));
				String line1 = in.readLine(); // header line (ignore it)
				String line2 = in.readLine(); // the line we're interested in
				String line3 = in.readLine(); // possibly interesting line
				if (line2 == null) {
					// unknown problem, throw exception
					throw new IOException(
							"Command line 'df' did not return info as expected " +
							"for path '" + path +
							"'- response on second line was '" + line1 + "'");
				}
				line2 = line2.trim();

				// Now, we tokenize the string. The fourth element is what we want.
				StringTokenizer tok = new StringTokenizer(line2, " ");
				if (tok.countTokens() < 4) {
					// could be long Filesystem, thus data on third line
					if (tok.countTokens() == 1 && line3 != null) {
						line3 = line3.trim();
						tok = new StringTokenizer(line3, " ");
					} else {
						throw new IOException(
								"Command line 'df' did not return data as expected " +
								"for path '" + path + "'- check path is valid");
					}
				} 
				else {
					tok.nextToken(); // Ignore Filesystem
				}
				tok.nextToken(); // Ignore 1K-blocks
				tok.nextToken(); // Ignore Used
				String freeSpace = tok.nextToken();
				try {
					bytes = 1000*Double.parseDouble(freeSpace);
				} catch (NumberFormatException ex) {
					throw new IOException(
							"Command line 'df' did not return numeric data as expected " +
							"for path '" + path + "'- check path is valid");
				}

			} 
			catch(Exception e){
				IOUtil.log(IOUtil.exceptionStackToString(e), null);
			}
			finally {
				try {
					if (in != null) {
						in.close();
					}
				} catch (IOException ioe) {
					// ignore
				}
			}

			if (bytes < 0) {
				throw new IOException(
						"Command line 'df' did not find free space in response " +
						"for path '" + path + "'- check path is valid");
			}
			return bytes;
		}

	}//getFreeDiskSpace

	/**
	 * get Unix or Linux drive.
	 *
	 * @param path holds the path of the file that resides on the drive 
	 * @return the drive name (e.g. /dev/hda1/ or /dev/hda2/
	 * @throws IOException if an error occurs
	 */
	public static String getUnixDrive(String path)throws IOException {
		if (path == null) {
			throw new IllegalArgumentException("Path must not be null");
		}
		// build and run the 'df' command
		String[] cmdAttribs = new String[] {"df", path};

		// read the output from the command until we come to the second line
		String sDrive = "";
		BufferedReader in = null;
		try {
			Process proc = Runtime.getRuntime().exec(cmdAttribs);          
			in = new BufferedReader(new InputStreamReader(proc.getInputStream()));
			String line1 = in.readLine(); // header line (ignore it)
			String line2 = in.readLine(); // the line we're interested in
			String line3 = in.readLine(); // possibly interesting line
			if (line2 == null) {
				// unknown problem, throw exception
				throw new IOException(
						"Command line 'df' did not return info as expected " +
						"for path '" + path +
						"'- response on second line was '" + line1 + "'");
			}
			line2 = line2.trim();

			// Now, we tokenize the string. The first element is what we want.
			StringTokenizer tok = new StringTokenizer(line2, " ");
			if (tok.countTokens() < 4) {
				// could be long Filesystem, thus data on third line
				if (tok.countTokens() == 1 && line3 != null) {
					line3 = line3.trim();
					tok = new StringTokenizer(line3, " ");
				} 
				else {
					throw new IOException(
							"Command line 'df' did not return data as expected " +
							"for path '" + path + "'- check path is valid");
				}
			} 
			sDrive = tok.nextToken().trim(); 
		} 
		catch(Exception e){
			IOUtil.log(IOUtil.exceptionStackToString(e), null);
		}
		finally {
			try {
				if (in != null) {
					in.close();
				}
			} catch (IOException ioe) {
				// ignore
			}
		}

		if (sDrive == null || sDrive.length() < 0) {
			throw new IOException(
					"Command line 'df' did not find drive name in response " +
					"for path '" + path + "'- check path is valid");
		}
		return sDrive;
	}//getUnixDrive

	/**
	 * main for test purposes.
	 *
	 * </p>
	 *
	 * @param argv command line arguments.
	 */
	public static void main(String[] args){
		/*
		byte[] bArray = readBytesFromURL("http://gsbkip.chicagogsb.edu");
		//byte[] bArray = readBytesFromURL("http://gsbkip.chicagogsb.edu/os/image/os1.jpg");
		encodedStringToFile(bytesToEncodedString(bArray), "c:\\temp\\test.html");
		System.out.println("---------------File_String_File-------------------");
		String s = fileToString("file/a.xls");
		stringToFile(s, "file/b.xls");
		System.out.println(s.length());
		//System.out.println(fileToEncodedString("file/b.xls"));
		//String s2Input = fileToEncodedString("file/a.xls");
		//encodedStringToFile(s2Input, "file/b.xls");
		System.out.println("-------------OjectBytes_String_ByteOjbect---------------------");
		IOUtil ioUtilObject1 = new IOUtil();
		String sIOUtilObject1 = objectToEncodedString(ioUtilObject1);
		System.out.println(sIOUtilObject1);
		IOUtil ioUtilObject2 = (IOUtil)encodedStringToObject(sIOUtilObject1);
		System.out.println(ioUtilObject2.m_sName);

		System.out.println("-------------OjectFile_String_FileOjbect---------------------");
		IOUtil thisIOUtilObject2 = new IOUtil();
		objectToFile(thisIOUtilObject2, "file/obj1.ser");
		String sThisObject2 = fileToEncodedString("file/obj1.ser");
		System.out.println(sThisObject2);
		encodedStringToFile(sThisObject2, "file/obj2.ser");
		IOUtil thatIOUtilObject2 = (IOUtil)fileToObject("file/obj2.ser");
		System.out.println(thatIOUtilObject2.m_sName);
		System.out.println("-------------other---------------------");
		byte[] bytes = fileToBytes("file/c.xls");
		System.out.println(bytes.length);
		bytesToFile(bytes, "file/d.xls");
		 */

//		IOUtil.print("abc");
//		IOUtil.println("efg");
//		IOUtil.print("123");
//		System.out.println(OSParameter.PRINT_STRING_WRITER.toString());

		//IOUtil.copyFile("c:/code/temp/m.xls", "c:/code/temp/copy.xls");
		//IOUtil.deleteFile("c:/temp/1.temp");
		//IOUtil.moveFile("c:/abc", "c:/abcd");
		//IOUtil.createFile("c:/aaa.txt");
		//IOUtil.cleanUpDisk();

		//System.out.println(IOUtil.getParentDir());
		//IOUtil.makeDir("c:/abc");
		//IOUtil.deleteDir("c:/abc");
		//System.out.println(IOUtil.isDir("c:/abc/abc.txt"));
//		try {
//		System.out.println(IOUtil.getFreeDiskSpace("c:/"));
//		} catch (IOException e) {
//		e.printStackTrace();
//		}
		//System.out.println(IOUtil.existsFileOrDir("c:/code/"));
		//System.out.println(IOUtil.getLastWriteTime("C:/code/OSConfig/OSRegistry.xml"));
		//IOUtil.appendStringToFile("aaaa", "c:/aaabbb.txt");
		//IOUtil.appendStringToFile("bbbb", "c:/aaabbb.txt");

	}//main

}//class IOUtil