/**
 * @(#)WSUtil 1.0 03/14/2004
 *
 * Copyright (c) 2004
 */
package org.optimizationservices.oscommon.util;

import javax.xml.namespace.QName;
import javax.xml.rpc.ServiceException;

import org.apache.axis.client.Call;
import org.apache.axis.client.Service;

/**
 *
 * <P>The <code>WSUtil</code> class contains methods for performing
 * common web services related operations, such as soap construction/web services invocation,
 * used by various components in the Optimization Services (OS) framework. </p>
 *
 * </p>
 *
 * @author Robert Fourer, Jun Ma, Kipp Martin
 * @version 1.0, 03/14/2004
 * @see org.optimizationservices.ossolver.api.IOSSolver
 * @since OS 1.0
 */
public class WSUtil{
	
	protected Call call = null;
		
	/**
	 * Invoke Optimization Services, whose arguments are string based.
	 *
	 * @param address holds where the Optimization Service is.
	 * @param methodName holds the name of the method that is invoked.
	 * @param arguments holds an array of String arguments as the input for the invoked method.
	 * @param argumentNames holds the name of teh the argements. If null will use default.
	 * @param returnName holds the return name of the method
	 * @param soapAction holds the SOAP action in the HTTP header file. 
	 * @return the output of the Optimization Service invokation. If arguments are incorrect or inconsistent, returns null.
	 */
	public static String invokeOptimizationServices(String address, String methodName, String[] arguments, String[] argumentNames, String returnName, String soapAction){
		if(argumentNames != null && argumentNames == null) return null;
		if(argumentNames != null && argumentNames != null && argumentNames.length != argumentNames.length) return null;
		String sOutput = "";
		String sNamespace = OSParameter.OS_SITE;

		try {
			Service service = new Service();
			Call call = (Call)service.createCall();
            //call.setMaintainSession(super.maintainSession);
            //call.setUsername(super.cachedUsername);
            //call.setPassword(super.cachedPassword);
            //call.setTargetEndpointAddress(super.cachedEndpoint);
			call.setTimeout(new Integer(360000));
            //call.setTimeout(super.cachedTimeout);
            //call.setPortName(super.cachedPortName);
			/* -- super should be org.apache.axis.client.Stub
			java.util.Enumeration keys = super.cachedProperties.keys();  
			while (keys.hasMoreElements()) {
	        	java.lang.String key = (java.lang.String) keys.nextElement();
	            call.setProperty(key, super.cachedProperties.get(key));
	        }
	        */	
	        call.setSOAPVersion(org.apache.axis.soap.SOAPConstants.SOAP11_CONSTANTS);
			call.setEncodingStyle(OSConstant.XML_ENCODING_STYLE);
			call.setTargetEndpointAddress( new java.net.URL(address));
			call.setOperationName(new QName(sNamespace, methodName) );
			call.setOperationStyle(org.apache.axis.constants.Style.RPC);
			call.setOperationUse(org.apache.axis.constants.Use.ENCODED);

			if(soapAction != null && soapAction.length() > 0){
				call.setUseSOAPAction(true);
				call.setSOAPActionURI(soapAction);
			}
			else{
				call.setUseSOAPAction(false);
			}
			
			if(argumentNames != null){
				for(int i = 0; i < argumentNames.length; i++){
					call.addParameter(new QName("", argumentNames[i]), 
							org.apache.axis.Constants.XSD_STRING, 
							javax.xml.rpc.ParameterMode.IN);
				}
			}
			else if(arguments !=null){
				for(int i = 0; i < arguments.length; i++){
					call.addParameter(new QName("", "osInput"+i), 
							org.apache.axis.Constants.XSD_STRING, 
							javax.xml.rpc.ParameterMode.IN);
				}
			}
			
			if(methodName.equals("send")){
				call.setReturnType(org.apache.axis.Constants.XSD_BOOLEAN);
				call.setReturnClass(Boolean.class);
			}
			else{
				call.setReturnType(org.apache.axis.Constants.XSD_STRING);
				call.setReturnClass(String.class);
			}
			
			if(returnName != null && returnName.length() > 0){
				call.setReturnQName(new QName("", returnName));				
			}
			else{
				call.setReturnQName(new QName("", "osOutput"));		
			}

			if(methodName.equals("send")){
				boolean bOutput = ((Boolean) call.invoke(arguments)).booleanValue();
				sOutput = bOutput?"true":"false";
				return sOutput;					
			}
			else{
				sOutput = (String) call.invoke(arguments);
				return sOutput;				
			}
		}
		catch (Exception e){
			e.printStackTrace();
			return null;
		}		
	}//invokeOptimizationServices
	
	/**
	 * main for test purposes.
	 *
	 * </p>
	 *
	 * @param argv command line arguments.
	 */
	public static void main(String [] args) {
		String sOSiL = IOUtil.readStringFromFile("xml/osxl/parinc.xml");
		String sSolverAddress = "http://iems218.iems.northwestern.edu:8080/os/osanalyzer/DrAMPLAnalyzerService.jws";
		String sMethod = "analyze";
		String[] msInputs = new String[]{sOSiL};
		String[] msInputNames = new String[]{"OSiL"};
		String sOSrL = WSUtil.invokeOptimizationServices(sSolverAddress, sMethod, msInputs, msInputNames, "osrl", null);
		System.out.println(sOSrL);
	}//main
	
	/**
	 * static constructor
	 */
	static {
	}//static constructor
}//class
