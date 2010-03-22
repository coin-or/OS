/**
 * @(#)TestJWSAgent 1.0 03/14/2004
 *
 * Copyright (c) 2004
 */
package org.optimizationservices.oscommon.communicationagent;

import org.optimizationservices.oscommon.util.WSUtil;


/**
 *
 * <P>The <code>TestJWSAgent</code> is a test agent for JWS Web Services.</p> 
 *
 * @author Robert Fourer, Jun Ma, Kipp Martin
 * @version 1.0, 03/14/2004
 * @since OS 1.0
 */
public class TestJWSAgent{
	/**
	 * address holds the address (uri/url) of the Optimization Services (OS) simulation.
	 */
	public String address = "";
	
	/**
	 * Constructor. 
	 *
	 */
	public TestJWSAgent(){
		
	}//constructor
	
	/**
	 * Constructor.
	 * 
	 * @param address holds the address (uri/url) of the Web Services.
	 */
	public TestJWSAgent(String address){
		this.address = address;
	}//constructor
	
	/**
	 * Invoke the Web Services. 
	 */
	public String call(String input){
		String sMethod = "helloJava";
		String[] msInputs = new String[]{input};;
		String[] msInputNames = new String[]{"inputName1"};
		String sOutput = WSUtil.invokeOptimizationServices(address, sMethod, msInputs, msInputNames, null, "org.optimizationservices.ossolver/HelloCSharp");
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
	
		String sAddress = "http://localhost:8080/os/ostest/JavaTestService.jws";		
		TestJWSAgent testAgent = new TestJWSAgent();
		testAgent.address = sAddress;
		String sOutput = testAgent.call("java input1");
		System.out.println(sOutput);
	}//main
	
}//class OSSimulationAgent
