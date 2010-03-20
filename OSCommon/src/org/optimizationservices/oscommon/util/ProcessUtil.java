/**
 * @(#)ProcessUtil 1.0 03/14/2004
 *
 * Copyright (c) 2004
 */
package org.optimizationservices.oscommon.util;

import java.io.BufferedReader;
import java.io.File;
import java.io.IOException;
import java.io.InputStreamReader;

/**
 *
 * <P>The <code>ProcessUtil</code> is a process and runtime (or terminal environment) related utility class.
 * For example it provides methods to run commands (e.g. DOS or UNIX commands from within the programming
 * codes.</p>
 *
 * </p>
 *
 * @author Robert Fourer, Jun Ma, Kipp Martin
 * @version 1.0, 03/14/2004
 * @since OS 1.0
 */
public class ProcessUtil{
	
	/**
	 * constructor
	 */
	public ProcessUtil(){
		
	}//constructor
	
	
	/**
	 * Launch a process specified by a command string. 
	 *
	 * </p>
	 *
	 * @param command holds the command that is usually typed in a terminal. 
	 * @return true if the process is launched successfully.  
	 */
	public static boolean launch(String command){
		try{
			String sOS = System.getProperty("os.name").toLowerCase();
			if(sOS.indexOf("window") >= 0){
				String[] msCommand = {"cmd.exe",  "/c", command};
				Runtime.getRuntime().exec(msCommand);
			}
			else if(sOS.indexOf("window") < 0){
				//String[] msCommandLine = { "sh", "-c", command};
				String sCommandLine = command;
				Runtime.getRuntime().exec(sCommandLine);		
			}
			return true;
		}
		catch(Exception e){
			e.printStackTrace();
			return false;
		}
	}//launch
	
	/**
	 * Launch a command specified by a command string and wait for the process to finish before proceeding
	 * to the next line. 
	 *
	 * </p>
	 *
	 * @param command holds the command that is usually typed in a terminal. 
	 * @return true if the process is launched successfully.  
	 */
	public static boolean launchAndWaitForFinish(String command){
		try{
			String sOS = System.getProperty("os.name").toLowerCase();
			Process proc = null;			
			if(sOS.indexOf("window") >= 0){
				String[] msCommandLine = { "cmd.exe", "/c", command};
				proc = Runtime.getRuntime().exec(msCommandLine);		
			}
			else if(sOS.indexOf("window") < 0){
				//String[] msCommandLine = {"sh", "-c", command};
				String sCommandLine = command;
				proc = Runtime.getRuntime().exec(sCommandLine);		
			}			
			BufferedReader br = new BufferedReader (new InputStreamReader(proc.getInputStream ()));
			while (br.readLine()!= null);
			proc.waitFor();
			proc.destroy();
			br.close();
			return true;
		}
		catch(Exception e){
			e.printStackTrace();
			return false;
		}
	}//launchAndWaitForFinish
	
	//	---------------------------------------------------------------------
	//	 String[] envp is an array of environment variables in the type "path=\vp\agentLCD\execs"
	//	 File dir is the current working directory
	//	 sParameter is the second part of the command, e.g, "mkdir one"
	//	---------------------------------------------------------------------
	/**
	 * Launch a command specified by a command string along with some environment parameters 
	 * and wait for the process to finish before proceeding
	 * to the next line. 
	 *
	 * </p>
	 *
	 * @param command holds the command that is usually typed in a terminal. 
	 * @param envp holds array of strings, each element of which has environment variable settings in 
	 * format <i>name</i>=<i>value</i>.
	 * @param dir holds the working directory of the subprocess, or <tt>null</tt> if the subprocess 
	 * should inherit the working directory of the current process.
	 * @return true if the process is launched successfully.  
	 */
	public static boolean launchAndWaitForFinish(String command, String[] envp, File dir){
		//Try to launch a command line program such as notepad
		try{
			String sOS = System.getProperty("os.name").toLowerCase();
			Process proc = null;			
			if(sOS.indexOf("window") >= 0){				
				String[] msCommandLine = { "cmd.exe", "/c", command};
				proc = Runtime.getRuntime().exec(msCommandLine, envp, dir);
			}
			else if(sOS.indexOf("window") < 0){
				String[] msCommandLine = { "sh", "-c", command};
				proc = Runtime.getRuntime().exec(msCommandLine, envp, dir);		
			}
			BufferedReader br = new BufferedReader (new InputStreamReader(proc.getInputStream ()));
			while (br.readLine()!= null);
			proc.waitFor();
			proc.destroy();
			br.close();
			return true;
		}
		catch(Exception e){
			e.printStackTrace();
			return false;
		}
	}//launchAndWaitForFinish
	
	/**
	 * kill a process by the process name. 
	 * @param processName holds the process name.  
	 * @return whether the process is killed or not; it will return true if there was no such processName. 
	 */
	public static boolean killProcessByName(String processName){
		String sOS = System.getProperty("os.name").toLowerCase();
		if(sOS.indexOf("indow") >= 0){ 
	        String[] cmdAttribs = new String[] {"taskkill", "/F", "/T", "/IM",  processName};
	        String sModifiedProcessName = "";
			if(processName.endsWith(".exe")){
				sModifiedProcessName = processName.substring(0, processName.length()-4);
			}
			else{
				sModifiedProcessName = processName+".exe";
			}
	        String[] cmdAttribs2 = new String[] {"taskkill", "/F", "/T", "/IM", sModifiedProcessName};
        	try {
				Runtime.getRuntime().exec(cmdAttribs);
				Runtime.getRuntime().exec(cmdAttribs2);
				return true;
			} 
        	catch (IOException e) {
				return false;
			}    
		}
		else{//"nix systems"
	        String[] cmdAttribs = new String[] {"killall", "-9", processName};
        	try {
				Runtime.getRuntime().exec(cmdAttribs);
				return true;
			} 
        	catch (IOException e) {
				return false;
			}    
		}
	}//killProcessByName
	
	/**
	 * kill a process by the process id. 
	 * @param processID holds the process id. 
	 * @return whether the process is killed or not; it will return true if there was no such processID. 
	 */
	public static boolean killProcessByID(String processID){//TODO
		String sOS = System.getProperty("os.name").toLowerCase();
		if(sOS.indexOf("indow") >= 0){ 
	        String[] cmdAttribs = new String[] {"taskkill", "/PID", processID};
        	try {
				Runtime.getRuntime().exec(cmdAttribs);
				return true;
			} 
        	catch (IOException e) {
				return false;
			}    
		}
		else{//"nix systems"
	        String[] cmdAttribs = new String[] {"kill", "-9", processID};
        	try {
				Runtime.getRuntime().exec(cmdAttribs);
				return true;
			} 
        	catch (IOException e) {
				return false;
			}    
		}
	}//killProcessByID
	
	/**
     * get free physical memory on the system.
     *
     * @return the free physical memory in bytes.  
     */
	public static double getFreeMemory() {
		double dFreeMemory = Runtime.getRuntime().freeMemory();
		return dFreeMemory;
	}//getFreeMemory
	
	/**
	 * main for test purposes.
	 *
	 * </p>
	 *
	 * @param argv command line arguments.
	 */
	public static void main(String[] argv){
		//System.out.println("Launch successfull? " + ProcessUtil.launchAndWaitForFinish("notepad"));
		//String[] msCommands = {"pwd", ">", "~/temp/waittestls.dat"};
		//String sCommand = "/Users/kmartin/Documents/files/code/lindo/macosx/projects/oslindo/bin/lindo /Users/kmartin/Documents/files/code/lindo/macosx/projects/oslindo/instances/lindoinput.dat > /Users/kmartin/Documents/files/code/lindo/macosx/projects/oslindo/instances/lindosol.dat";
		//String[] msCommand = {"sh", "-c", "/Users/kmartin/Documents/files/code/lindo/macosx/projects/oslindo/bin/lindo", "/Users/kmartin/Documents/files/code/lindo/macosx/projects/oslindo/instances/lindoinput.dat"};
		//String sCommand = "/Users/kmartin/Documents/files/code/lindo/macosx/projects/oslindo/bin/lindo  /Users/kmartin/Documents/files/code/lindo/macosx/projects/oslindo/instances/lindoinput.dat /Users/kmartin/Documents/files/code/lindo/macosx/projects/oslindo/instances/lindosol.dat";
		//ProcessUtil.launchAndWaitForFinish(sCommand);
		//sCommand = "/Users/kmartin/temp/testbat";
		//ProcessUtil.launch(msCommand);
		//System.out.println("launch succesful? " + ProcessUtil.launchAndWaitForFinish(sCommand));
		//System.out.println("Launch successfull? " + ProcessUtil.launch("dir >file/temp.txt"));
			/*
			BufferedReader br = new BufferedReader (new InputStreamReader(proc.getInputStream ()));
			String sOut = "";
			String sTemp = "";			
			boolean bContinue = true;
			while (bContinue){
				sTemp = br.readLine();
				System.out.println("sTemp: " + sTemp);
				if(sTemp!= null){
					sOut += sTemp;
				}
				else{
					bContinue = false;
				}
				System.out.println(sOut);
			}
			proc.destroy();
			br.close();*/
		//System.out.println(ProcessUtil.killProcessByName("excel.exe"));
	}//main
	
}//Class ProcessUtil
