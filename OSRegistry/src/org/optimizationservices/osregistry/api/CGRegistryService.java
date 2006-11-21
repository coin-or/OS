/**
 * @(#)CGRegistryService 1.0 03/14/2004
 *
 * Copyright (c) 2004
 */
package org.optimizationservices.osregistry.api;

import org.optimizationservices.oscommon.communicationinterface.OSdL;
import org.optimizationservices.oscommon.util.DefaultRegistry;
import org.optimizationservices.oscommon.util.OSParameter;
import org.optimizationservices.oscommon.util.OSParameterFile;
import org.optimizationservices.oscommon.util.OSServiceUtil;


/**
 *
 * <P>The <code>CGRegistryService</code> implements all the <code>OSdL</code> and 
 * <code>OSdL</code> interfaces. Thus it is an OS-type registry. It implements all the methods as specified in the
 * Optimization Services (OS) Framework, specifically the Optimization Services discover
 * Language (OSdL), the Optimization Services join Language (OSjL) and the Optimization Services validate Language (OSvL)
 * The methods in OSdL are called by an OS agent to  find and register in an OS registry
 * any OS services, such as OS solvers or analyzers. The methods in OShL are called by 
 * called by an OS service provider to join an OS registry. Any registry that wants to become 
 * an OS-type callable on the distributed system must implement these interfaces.  
 * These methods are called by an OS agent to validate an xml representation's validity.  
 *
 * </p>
 * @author Robert Fourer, Jun Ma, Kipp Martin
 * @version 1.0, 03/14/2004
 * @see org.optimizationservices.osregistry.api.OSdL
 * @since OS 1.0
 */
public class CGRegistryService implements OSdL{
	/**
	 * m_osServiceUtil holds a default implementation of the registry service.  
	 */ 
	private OSServiceUtil m_osServiceUtil = new OSServiceUtil();
	
		
	/**
	 * default constructor.
	 */
	public CGRegistryService(){
		if(OSParameter.SCHEDULER_WITH_REGISTRY  || OSParameter.SERVICE_URI == OSParameter.OS_SCHEDULER_SITE){
			DefaultRegistry.m_sRegistryServiceName = "OSRegistryService";
			m_osServiceUtil.serviceName = DefaultRegistry.m_sRegistryServiceName;
		}
		else{
			m_osServiceUtil.serviceName = OSParameter.SERVICE_NAME;
		}
		m_osServiceUtil.serviceURI = OSParameter.OS_REGISTRY_SITE; ;
		m_osServiceUtil.serviceType = "registry";
		m_osServiceUtil.registry = new DefaultRegistry();
	}//constructor
	
	/**
	 * Find an Optimization Service whose instance is given by a string following
	 * the Optimization Services query Language (OSqL) schema and returns the location information
	 * in a string that follows the Optimization Services URI, or Universal Resource Indentifier
	 * Language, (OSuL) schema.
	 *
	 * </P>
	 *
	 * @param OSqL holds the Optimization Service query in a string which format follows the
	 * Optimization Services query Language (OSqL) schema.
	 * @param osol holds the optimization option in a string which format follows the 
	 * Optimization Services option Language (OSoL) schema.    
	 * @return the location information in a string that follows the Optimization Services URI,
	 * or Universal Resource Indentifier Language, (OSuL) schema.
	 * @see org.optimizationservices.osregistry.api.OSdL#find
	 */
	public String find(String osql, String osol){
		return m_osServiceUtil.find(osql, osol);
	}//find
	
	/**
	 * Register an Optimization Service whose instance is given by a string following 
	 * the Optimization Services entity Language (OSeL) schema and returns a string that contains 
	 * an XSLT style sheet transformation so that it can be used for standard web pubblication of the 
	 * Optimization Service that just registered. The XSLT is espcially used to publish the OSeL. 
	 * 
	 * </P>
	 * 
	 * @param osel holds the Optimization Service entity description in a string which format follows the 
	 * Optimization Services entity Language (OSeL) schema.  
	 * @param osol holds the optimization option in a string which format follows the 
	 * Optimization Services option Language (OSoL) schema.    
	 * @return the register process output information in a string which format follows the OSpL schema.
	 */
	public String register(String osel, String osol){
		return m_osServiceUtil.register(osel, osol);
	}//register
	
	/**
	 * Validate an xml representation's validity.
	 * 
	 * </P>
	 * 
	 * @param osxl holds the xml string to be validated
	 * @param osol holds the optimization option in a string which format follows the 
	 * Optimization Services option Language (OSoL) schema.    
	 * @return the validate process output information in a string which format follows the OSpL schema.
	 */
	public String validate(String osxl, String osol){
		return m_osServiceUtil.validate(osxl, osol);
	}//validate
	
	/**
	 * This method is called by one optimization service on another optimization service
	 * to provide runtime dynamic process information (push mechanism).
	 *
	 * </P>
	 * @param osplInput holds the input process information a string which format follows the Optimization
	 * Services process Language (OSpL) schema.
	 * @param osol holds the optimization option in a string which format follows the 
	 * Optimization Services option Language (OSoL) schema.    
	 * @return osplOutput, the ouput process information in a string which format follows the OSpL schema.
	 */
	public String knock(String osplInput, String osol){
		return m_osServiceUtil.knock(osplInput, osol);
	}//knock
	
	/**
	 * main for test purposes.
	 *
	 * </p>
	 *
	 * @param argv command line arguments.
	 */
	public static void main(String[] argv){		
		/*
		CGRegistryService registry = new CGRegistryService();
		OSRegistryAgent agent = new OSRegistryAgent(OSParameter.OS_REGISTRY_SITE);		
		System.out.println(OSParameter.OS_REGISTRY_SITE);
		//test register
		
		try {
			//String sRegisterOutput = registry.register("this is osel", "this is osol");
			String sRegisterOutput = agent.register("this is osel", "this is osol");
			System.out.println(sRegisterOutput);			
		} 
		catch (Exception e) {
			e.printStackTrace();
		}
		
		*/
		
		//test validate
		/*
		String sOSxL = 	IOUtil.readStringFromFile(OSParameter.CODE_HOME + "OSRepository/test/osel/osel.osel");
		String sValidateOutput = registry.validate(sOSxL, "efg");
		//String sValidateOutput = agent.validate(sOSxL, "efg");
		System.out.println(sValidateOutput);
		*/
		
		//test find
		/*
		OSqLWriter osqlWriter = new OSqLWriter();
		StandardQuery sq = new StandardQuery();
		sq.currentState = "accepting";
		osqlWriter.setStandardQuery(sq);
		String sOSqL = osqlWriter.writeToString();
		System.out.println(sOSqL);
		
		OSoLWriter osolWriter = new OSoLWriter();
		String sOSoL = osolWriter.writeToString();
		System.out.println(sOSoL);

		String sOSuL = registry.find(sOSqL, sOSoL);
		//String sOSuL = agent.find(sOSqL, sOSoL);
		System.out.println(sOSuL);
		*/
		
		//test knock
		/*
		OSoLWriter osolWriter = new OSoLWriter();
		osolWriter.setServiceURI("http://localhost/OSSolver/CGSolverService.asmx");
		//osolWriter.setServiceURI("http://localhost:8080/os/ossolver/CGSolverService.jws");
		String sOSoL = osolWriter.writeToString();
		System.out.println(sOSoL);
		
		OSpLWriter osplWriter = new OSpLWriter();
		osplWriter.setServiceURI("http://localhost:8080/os/ossolver/CGSolverService.jws");
		//osplWriter.setRequestAction("ping");
		//osplWriter.setRequestAction("notifyJobCompletion");
		//osplWriter.setRequestAction("requestJob");
		//osplWriter.setRequestAction("getServiceStatistics");
		//osplWriter.setRequestAction("getJobStatistics");
		//osplWriter.setRequestAction("getAll");
		//osplWriter.setRequestAction("setServiceStatistics");
		//osplWriter.setRequestAction("setAll");
		osplWriter.setRequestAction("setJobStatistics");
			//osplWriter.setCurrentState("busyButAccepting");		
			JobStatistics[] mJobStatistics = new JobStatistics[2];
			mJobStatistics[0] = new JobStatistics();
			mJobStatistics[0].jobID = "abc";
			mJobStatistics[1] = new JobStatistics();
			mJobStatistics[1].jobID = "def";
			osplWriter.setJobStatistics(mJobStatistics);
		String sOSpLInput = osplWriter.writeToString();
		System.out.println(sOSpLInput);
		
		
		String sOSpLOutput = registry.knock(sOSpLInput, sOSoL);
		//String sOSpLOutput = agent.knock(sOSpLInput, sOSoL);
		System.out.println(sOSpLOutput);
		*/
	}//main
	
	static{
		OSParameterFile.NAME = "/code0/OSConfig/OSParameter_CGSchedulerService.xml";
	}//static constructor
}//class CGRegistryService






