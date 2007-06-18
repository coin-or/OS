/**
 * @(#)StandardSolver 1.0 03/14/2004
 *
 * Copyright (c) 2004
 */
package org.optimizationservices.oscommon.util;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.GregorianCalendar;
import java.util.Hashtable;
import java.util.Vector;

import org.optimizationservices.oscommon.localinterface.DefaultSolver;
import org.optimizationservices.oscommon.representationparser.OSrLWriter;
/**
*
* <P>The <code>StandardSolver</code>class is the standard solver engine. 
*
* </p>
* @author Robert Fourer, Jun Ma, Kipp Martin
* @version 1.0, 03/14/2004
* @since OS 1.0
*/
public class StandardSolver extends DefaultSolver{
	/**
	 * default constructor.
	 */
	public StandardSolver(){
	}//constructor

	/**
	 * run the CG solver command that is specified in the batch file. 
	 */
	public void solve(){
		String sOS = System.getProperty("os.name").toLowerCase();
		String sJobID = osOption.getJobID();
		String sOSSolver = "";
		Hashtable<String, String> otherOptimizationValues = osOption.getOtherOptimizationOptionValues();
		if(otherOptimizationValues != null){
			sOSSolver = otherOptimizationValues.get("os_solver;");
		}
		if(sOSSolver == null || sOSSolver.length() <= 0) sOSSolver = OSParameter.OS_SOLVER;
		
		String sInstanceFile = OSParameter.TEMP_FILE_FOLDER+sJobID+".osil";
		if(IOUtil.existsFileOrDir(sInstanceFile)){
			IOUtil.writeStringToFile(osil, sInstanceFile);
		}
		String sOptionFile = OSParameter.TEMP_FILE_FOLDER+sJobID+".osol";
		if(IOUtil.existsFileOrDir(sOptionFile)){
			IOUtil.writeStringToFile(osol, sOptionFile);
		}
		String sResultFile = OSParameter.TEMP_FILE_FOLDER+sJobID+".osrl";
		OSrLWriter osrlWriter = new OSrLWriter();
		osrlWriter.setServiceURI(OSParameter.SERVICE_URI);
		osrlWriter.setServiceName(OSParameter.SERVICE_NAME);
		osrlWriter.setResultTime(new GregorianCalendar());

		//change starts
		String sSolverPath =  OSParameter.CODE_HOME + "solver/OSSolverService";
		if(sOS.toLowerCase().indexOf("window") >= 0){
			sSolverPath += ".exe";
		}
		else if(sOS.toLowerCase().indexOf("linux") >= 0 || sOS.toLowerCase().indexOf("nix") >= 0){
			sSolverPath += "Linux";;	
		}
		else if(sOS.toLowerCase().indexOf("mac") >= 0){
			sSolverPath += "Mac";;
		}
		else{
			;
		}
		String sArguments = 
			" -osil " + sInstanceFile + 
			" -osol " + sOptionFile +
			" -osrl " + sResultFile + 
			" -solver" + sOSSolver; 
		
		String[] msCommandLine = {
				sSolverPath, 
				"-osil", sInstanceFile, 
				"-osol", sOptionFile,
				"-osrl", sResultFile,
				"-solver", sOSSolver};

		//no need to change below
		boolean bUseSimple = false;
		if(OSParameter.SERVICE_URI == null || OSParameter.SERVICE_URI.length() <= 0){
			bUseSimple = true;
		}
		else{
			bUseSimple = false;
		}
		if(bUseSimple){//simple version - not registering process 
			try {
				ProcessUtil.launchAndWaitForFinish(sSolverPath + " " + sArguments);
				super.osrl = IOUtil.readStringFromFile(sResultFile);				
			} 
			catch (Exception e) {
				IOUtil.log(IOUtil.exceptionStackToString(e), null);
				osrlWriter.setGeneralStatusType("error");
				osrlWriter.setGeneralStatusDescription(e.getMessage());
				super.osrl = osrlWriter.writeToString();
			}
		}
		else{ //complex version - registering process
			try{
				Process process = null;		
				process = Runtime.getRuntime().exec(msCommandLine);		
				Vector<Process> vProcess = (Vector<Process>)OSServiceUtil.processsHashTable.get(sJobID);
				if(vProcess == null || vProcess.size() <= 0){
					vProcess = new Vector<Process>();
				}
				vProcess.add(process);
				OSServiceUtil.processsHashTable.put(sJobID, vProcess);
				BufferedReader br = new BufferedReader (new InputStreamReader(process.getInputStream ()));
				boolean bCont = true;
				String sProcessOutput = "";
				String sTemp;
				while (bCont){
					sTemp = br.readLine(); 
					if(sTemp != null){
						sProcessOutput += sTemp;							
					}
					else{
						bCont = false;
					}
				}
				process.waitFor();
				vProcess.remove(process);
				if(vProcess.size() <= 0){
					OSServiceUtil.processsHashTable.remove(sJobID);
				}
				br.close();	
				super.osrl = IOUtil.readStringFromFile(sResultFile);
			}
			catch(Exception e){
				IOUtil.log(IOUtil.exceptionStackToString(e), null);
				osrlWriter.setGeneralStatusType("error");
				osrlWriter.setGeneralStatusDescription(e.getMessage());
				super.osrl = osrlWriter.writeToString();
			}
		}
		if(OSParameter.SERVICE_URI == null || OSParameter.SERVICE_URI.length() <= 0){
			IOUtil.deleteFile(sInstanceFile);
			IOUtil.deleteFile(sOptionFile);
			IOUtil.deleteFile(sResultFile);
		}
		return;

	}//solve
	
	/**
	 * main for test purposes.
	 *
	 * </p>
	 *
	 * @param argv command line arguments.
	 */
	public static void main(String[] argv){
	}//main

}//StandardSolver
