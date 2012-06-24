/**
 * @(#)StandardOSSolver 1.0 03/14/2004
 *
 * Copyright (c) 2004
 */
package org.optimizationservices.oscommon.util;

import java.io.BufferedReader;
import java.io.File;
import java.io.InputStreamReader;
import java.util.GregorianCalendar;
import java.util.Vector;

import org.optimizationservices.oscommon.datastructure.osoption.OtherOption;
import org.optimizationservices.oscommon.localinterface.DefaultSolver;
import org.optimizationservices.oscommon.localinterface.OSOption;
import org.optimizationservices.oscommon.localinterface.OSResult;
import org.optimizationservices.oscommon.representationparser.OSrLReader;
import org.optimizationservices.oscommon.representationparser.OSrLWriter;
import org.optimizationservices.oscommon.util.IOUtil;
import org.optimizationservices.oscommon.util.OSParameter;
import org.optimizationservices.oscommon.util.OSServiceUtil;
import org.optimizationservices.oscommon.util.ProcessUtil;
/**
 *
 * <P>The <code>StandardOSSolver</code>class is the standard solver engine. 
 *
 * </p>
 * @author Robert Fourer, Jun Ma, Kipp Martin
 * @version 1.0, 03/14/2004
 * @since OS 1.0
 */
public class StandardOSSolver extends DefaultSolver{
	/**
	 * default constructor.
	 */
	public StandardOSSolver(){
	}//constructor

	/**
	 * run the standard solve method. ***
	 */
	public void solve(){
		String sOS = System.getProperty("os.name");
		String sArch = System.getProperty("os.arch");
		String sJobID = osOption.getJobID();

		//		String sOSSolver = osOption.getOtherOptimizationOptionValueByName("os_solver");
		String sOSSolver = osOption.getSolverToInvoke();
		//		if(sOSSolver == null || sOSSolver.length() <= 0) sOSSolver = osOption.getOtherOptionValueByName("os_solver");
		if(sOSSolver == null || sOSSolver.length() <= 0) sOSSolver = osOption.getSolverToInvoke();
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
		osrlWriter.setResultTimeStamp(new GregorianCalendar());

		//process get_stdout
		String sGetStdout = "false";
		OtherOption[] otherJobOptions = osOption.getOtherJobOptions();
		if(otherJobOptions != null){
			int nJobOptions = otherJobOptions.length;
			for(int i = 0; i < nJobOptions; i++){
				if(otherJobOptions[i].name != null && otherJobOptions[i].name.equals("get_stdout")){
					if(otherJobOptions[i].value != null && otherJobOptions[i].value.equals("true")){
						sGetStdout = "true";
					}
					break;
				}
			}
		}
		String sStdOutFile = null;
		if(sGetStdout != null && sGetStdout.equals("true")){
			sStdOutFile = OSParameter.TEMP_FILE_FOLDER+sJobID+".stdout";
		}

		//change starts
		String sSolverPath = "";
		if(OSParameter.SOLVER_EXECUTABLE.startsWith("OSSolverService")){
			// Eclipse deploys to here a lot easier
			sSolverPath =  OSParameter.SERVICE_FOLDER + "WEB-INF/classes/OSSolverService";
			File exe=new File(sSolverPath);
			if(!exe.exists()){
				// normalize java to unix naming conventions.
				if(sArch.equals("i386"))
					sArch="-x86";
				else if(sArch.equals("amd64"))
					sArch="-x86_64";
				if(sOS.startsWith("Linux"))
					sOS="-linux";
				if(sOS.startsWith("Mac"))
					sOS="-mac-osx";
				else if(sOS.startsWith("Windows")){
					sOS="-win32";
					sArch="";
				}
				sSolverPath += sOS + sArch;
				exe=new File(sSolverPath);
			}
			// make executable if necessary (war deployment hack) -- need 1.6
			//if(! exe.canExecute()){
			//	exe.setExecutable(true);
			//}
		}
		else{
			sSolverPath =  OSParameter.CODE_HOME + "solver/"+OSParameter.SOLVER_EXECUTABLE;
		}
		String sArguments = 
			" -osil " + sInstanceFile + 
			" -osol " + sOptionFile +
			" -osrl " + sResultFile + 
			((sOSSolver==null || sOSSolver.trim().length()<=0)?" ":(" -solver " + sOSSolver)); 

		String[] msCommandLine = {
				sSolverPath, 
				"-osil", sInstanceFile, 
				"-osol", sOptionFile,
				"-osrl", sResultFile,
				"-solver", sOSSolver};
		if(sOSSolver==null || sOSSolver.trim().length()<=0){
			String[] msCommandLineAlt = {
					sSolverPath, 
					"-osil", sInstanceFile, 
					"-osol", sOptionFile,
					"-osrl", sResultFile};
			msCommandLine = msCommandLineAlt;
		}

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
				String sCommand = sSolverPath + " " + sArguments;
				if(sStdOutFile != null && sStdOutFile.length() > 0){
					sCommand = sCommand + " > \""+sStdOutFile+"\"";
				}
				ProcessUtil.launchAndWaitForFinish(sCommand);
				super.osrl = IOUtil.readStringFromFile(sResultFile);				
			} 
			catch (Exception e) {
				IOUtil.log(IOUtil.exceptionStackToString(e), null);
				osrlWriter.setGeneralStatusType("error");
				//osrlWriter.setGeneralStatusDescription(e.getMessage());
				osrlWriter.setGeneralStatusDescription("Error: the executable "+ OSParameter.SOLVER_EXECUTABLE + " is missing -- please see INSTALL file");
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
						sProcessOutput += "\n";							
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

				if(sStdOutFile != null && sStdOutFile.length() > 0){
					IOUtil.writeStringToFile(sProcessOutput, sStdOutFile);
				}
				super.osrl = IOUtil.readStringFromFile(sResultFile);
			}
			catch(Exception e){
				IOUtil.log(IOUtil.exceptionStackToString(e), null);
				osrlWriter.setGeneralStatusType("error");
				//osrlWriter.setGeneralStatusDescription(e.getMessage());
				osrlWriter.setGeneralStatusDescription("Error: the executable "+ OSParameter.SOLVER_EXECUTABLE + " is missing -- please see INSTALL file");
				super.osrl = osrlWriter.writeToString();
			}
		}
		if(sStdOutFile != null && sStdOutFile.length() > 0){
			try {
				OSrLReader osrlReader = new OSrLReader();
				boolean bRead = osrlReader.readString(super.osrl);
				if(bRead){
					OSResult osResult = osrlReader.getOSResult();
					osrlWriter.setOSResult(osResult);
					String sStdOut = IOUtil.readStringFromFile(sStdOutFile);
					osrlWriter.addOtherJobResult("stdout_capture", sStdOut, "standard out capture");
					super.osrl = osrlWriter.writeToString();

				}
			} 
			catch (Exception e) {
				e.printStackTrace();
			}

		}
		if(OSParameter.SERVICE_URI == null || OSParameter.SERVICE_URI.length() <= 0){
			IOUtil.deleteFile(sInstanceFile);
			IOUtil.deleteFile(sOptionFile);
			IOUtil.deleteFile(sResultFile);
			IOUtil.deleteFile(sStdOutFile);
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
		OSOption osOption = new OSOption();
		try {
			osOption = osOption.readOSoL("c:/temp.osol", true, false);

			//		String sOSSolver = osOption.getOtherOptimizationOptionValueByName("os_solver");
			String sOSSolver = osOption.getSolverToInvoke();
			System.out.println(sOSSolver);



			//process get_stdout
			String sJobID = "1";
			String sSolverPath = "D:\\code\\temp\\OSSolverService.exe";
			String sArgument1 = " -osil a ";
			String sArgument2 = "-osrl d:\\code\\temp\\test.osrl";
			String[] msCommandLine = {sSolverPath, "-osil", "a", "-osrl", "d:\\code\\temp\\test.osrl"};


			String sGetStdout = "true";
			OtherOption[] otherJobOptions = osOption.getOtherJobOptions();
			if(otherJobOptions != null){
				int nJobOptions = otherJobOptions.length;
				for(int i = 0; i < nJobOptions; i++){
					if(otherJobOptions[i].name != null && otherJobOptions[i].name.equals("get_stdout")){
						if(otherJobOptions[i].value != null && otherJobOptions[i].value.equals("true")){
							sGetStdout = "true";
						}
						break;
					}
				}
			}
			String sStdOutFile = null;
			if(sGetStdout != null && sGetStdout.equals("true")){
				sStdOutFile = OSParameter.TEMP_FILE_FOLDER+sJobID+".stdout";
			}

			System.out.println(sStdOutFile);
			boolean bUseSimple = false;
			if(OSParameter.SERVICE_URI == null || OSParameter.SERVICE_URI.length() <= 0){
				bUseSimple = true;
			}
			else{
				bUseSimple = false;
			}
			bUseSimple = false;
			if(bUseSimple){//simple version - not registering process 
				try {
					String sCommand = sSolverPath + " " + sArgument1+ " " + sArgument2;
					if(sStdOutFile != null && sStdOutFile.length() > 0){
						sCommand = sCommand + " > \""+sStdOutFile+"\"";
					}
					System.out.println(sCommand);
					ProcessUtil.launchAndWaitForFinish(sCommand);
				} 
				catch (Exception e) {
				}
			}
			else{ //complex version - registering process
				try{
					Process process = null;		
					process = Runtime.getRuntime().exec(msCommandLine);		
					BufferedReader br = new BufferedReader (new InputStreamReader(process.getInputStream ()));
					boolean bCont = true;
					String sProcessOutput = "";
					String sTemp;
					while (bCont){
						sTemp = br.readLine(); 
						if(sTemp != null){
							sProcessOutput += sTemp;							
							sProcessOutput += "\n";							
						}
						else{
							bCont = false;
						}
					}
					process.waitFor();
					br.close();	
					System.out.println(sProcessOutput);
					if(sStdOutFile != null && sStdOutFile.length() > 0){
						IOUtil.writeStringToFile(sProcessOutput, sStdOutFile);
					}
				}
				catch(Exception e){
					e.printStackTrace();
				}
			}

		} catch (Exception e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}//main

}//StandardOSSolver
