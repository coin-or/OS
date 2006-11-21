/**
 * @(#)TestASMXAgent 1.0 03/14/2004
 *
 * Copyright (c) 2004
 */
package org.optimizationservices.oscommon.communicationagent;

import org.optimizationservices.oscommon.util.WSUtil;


/**
 *
 * <P>The <code>TestASMXAgent</code> is a test agent for ASMX Web Services.</p> 
 *
 * @author Robert Fourer, Jun Ma, Kipp Martin
 * @version 1.0, 03/14/2004
 * @since OS 1.0
 */
public class TestASMXAgent{
	/**
	 * address holds the address (uri/url) of the Optimization Services (OS) simulation.
	 */
	public String address = "";
	
	/**
	 * Constructor. 
	 *
	 */
	public TestASMXAgent(){
		
	}//constructor
	
	/**
	 * Constructor.
	 * 
	 * @param address holds the address (uri/url) of the Web Services.
	 */
	public TestASMXAgent(String address){
		this.address = address;
	}//constructor
	
	/**
	 * Invoke the Web Services. 
	 */
	public String call(String input){
		String sMethod = "helloCSharp";
		String[] msInputs = new String[]{input};
		String[] msInputNames = new String[]{"input"};
		String sNameSpace = "org.optimizationservices.ossolver";
		String sOutput = WSUtil.invokeOptimizationServices(address, sMethod, msInputs, msInputNames, null, sNameSpace+"/"+sMethod);
		return sOutput;
	}//call
	
	/**
	 * Invoke the Web Services. 
	 */
	public String getJobID(String input){
		String sMethod = "retrieve";
		String[] msInputs = new String[]{input};
		String[] msInputNames = new String[]{"input"};
		String sOutput = WSUtil.invokeOptimizationServices(address, sMethod, msInputs, msInputNames, null, "");
		return sOutput;
	}//call
	
	/**
	 * main for test purposes.
	 *
	 * </p>
	 *
	 * @param argv command line arguments.
	 */
	public static void main(String [] args) {
	
		//String sAddress = "http://localhost/OSSolver/ASMXTestService.asmx";	
		String sAddress = "http://localhost/OSSolver/CGSolverService.asmx";
		TestASMXAgent testAgent = new TestASMXAgent();
		testAgent.address = sAddress;
		String sOutput = testAgent.getJobID("java input2");
		System.out.println(sOutput);
	}//main
	
}//class TestASMXAgent
