/**
 * @(#)DefaultRegistry 1.0 03/14/2005
 *
 * Copyright (c) 2006 	Robert Fourer, Jun Ma, Kipp Martin, Wayne Sheng,
 * Northwestern University, and the University of Chicago.
 * All Rights Reserved.
 * This software is licensed under the Common Public License. 
 * Please see the accompanying file for terms. 
 */
package org.optimizationservices.oscommon.util;

import java.io.IOException;
import java.io.StringReader;
import java.util.GregorianCalendar;
import java.util.Hashtable;
import java.util.Timer;
import java.util.TimerTask;

import org.apache.xerces.parsers.DOMParser;
import org.optimizationservices.oscommon.communicationagent.OSSolverAgent;
import org.optimizationservices.oscommon.datastructure.osprocess.JobOptimization;
import org.optimizationservices.oscommon.datastructure.osprocess.JobStatistics;
import org.optimizationservices.oscommon.datastructure.osprocess.OptimizationProcess;
import org.optimizationservices.oscommon.datastructure.osprocess.ProcessStatistics;
import org.optimizationservices.oscommon.datastructure.osquery.StandardQuery;
import org.optimizationservices.oscommon.datastructure.osregistry.ServiceEntry;
import org.optimizationservices.oscommon.datastructure.osuri.URI;
import org.optimizationservices.oscommon.localinterface.OSProcess;
import org.optimizationservices.oscommon.localinterface.OSRegistry;
import org.optimizationservices.oscommon.representationparser.OSRegistryReader;
import org.optimizationservices.oscommon.representationparser.OSRegistryWriter;
import org.optimizationservices.oscommon.representationparser.OSeLReader;
import org.optimizationservices.oscommon.representationparser.OSoLReader;
import org.optimizationservices.oscommon.representationparser.OSoLWriter;
import org.optimizationservices.oscommon.representationparser.OSpLReader;
import org.optimizationservices.oscommon.representationparser.OSpLWriter;
import org.optimizationservices.oscommon.representationparser.OSqLReader;
import org.optimizationservices.oscommon.representationparser.OSqLWriter;
import org.optimizationservices.oscommon.representationparser.OSuLReader;
import org.optimizationservices.oscommon.representationparser.OSuLWriter;
import org.xml.sax.InputSource;
import org.xml.sax.SAXException;


/**
*
* <P>The <code>DefaultRegistry</code> class is a default registry 
* that is to be implemented by a registry that needs to be implemented as an
* optimization service using OSServiceUtil. 
*
* @author Robert Fourer, Jun Ma, Kipp Martin
* @version 1.0, 03/14/2005
* @see org.optimizationservices.oscommon.util.OSServiceUtil
* @since OS 1.0
*/
public class DefaultRegistry {

	/**
	 * m_sRegistryServiceName holds the registry service name.
	 */
	public static String m_sRegistryServiceName = "OSRegistryService";

	/**
	 * m_sSystemPassword holds the password used for communication between system components.
	 */
	private static String m_sSystemPassword = "";	

	/**
	 *  m_bValidate holds whether the parser should be validating against the xml schema or not
	 */
	protected boolean m_bValidate = OSParameter.VALIDATE; 

	/**
	 * serviceName holds the service name. 
	 */
	public String serviceName = m_sRegistryServiceName;
	
	/**
	 * serviceURI holds the service uri. 
	 */
	public String serviceURI = OSParameter.OS_REGISTRY_SITE;
	
	/**
	 * serviceType holds the service type. 
	 */
	public String serviceType = "registry";
	
	/**
	 * m_sInstanceName holds the name of the instance being solved.
	 */
	protected String m_sInstanceName = "";
	
	/**
	 * m_sJobID holds the job ID;
	 */
	protected String m_sJobID = "";
	
	/**
	 * m_sLicense holds the license. 
	 */
	protected String m_sLicense = "";

	/**
	 * m_sUserName holds the user name. 
	 */
	protected String m_sUserName = "";

	/**
	 * m_sPassword holds the password. 
	 */
	protected String m_sPassword = "";
	
	/**
	 * m_sContactTransportType holds the constact transport type. 
	 */
	protected String m_sContactTransportType = "";

	/**
	 * m_sContactAddress holds the contact address. 
	 */
	protected String m_sContactAddress = "";
	
	/**
	 * m_dMinDiskSpace holds the minimum disk sapce required by the job. 
	 */
	protected double m_dMinDiskSpace = 0;

	/**
	 * m_dMinMemorySize holds the minimum memory size required by the job. 
	 */
	protected double m_dMinMemorySize = 0;

	/**
	 * m_dMinCPUSpeed holds the minimum cpu speed required by the job. 
	 */
	protected double m_dMinCPUSpeed = 0;

	/**
	 * m_dJobMaxTime holds the maximum time allowed for the job. 
	 */
	protected double m_dJobMaxTime = OSParameter.JOB_MAX_TIME;
	
	/**
	 * m_jobScheduledStartTime holds the job's scheduled start time.
	 */
	protected GregorianCalendar m_jobScheduledStartTime = new GregorianCalendar(1970, 0, 1, 0, 0, 0);

	/**
	 * m_msJobDependencies holds a string array of jobIDs the the current job depends on.
	 */
	protected String[] m_msJobDependencies = null;
	
	/**
	 * m_sCurrentState holds the current state of the service: which can be: 
	 * busy, busyButAccepting, idle, idleButNotAccepting, noResponse. 
	 */
	protected static String m_sCurrentState = "noResponse";
	
	/**
	 * m_dAvailableDiskSpace holds the available disk space. 
	 */
	protected static double m_dAvailableDiskSpace = Double.POSITIVE_INFINITY;

	/**
	 * m_dAvailableMemory holds the available memory. 
	 */
	protected static double m_dAvailableMemory = Double.POSITIVE_INFINITY;
	
	/**
	 * m_iCurrentJobCount holds the current number of active jobs. 
	 */
	protected static int m_iCurrentJobCount = 0;
	
	/**
	 * m_iTotalJobsSoFar holds the number of jobs so far recieved. 
	 */
	protected static int m_iTotalJobsSoFar = 0;

	/**
	 * m_lLastJobEnded holds the time the last job ended (in millisecond since 1970 UTC).  
	 */
	protected static long m_lTimeLastJobEnded = -1;

	/**
	 * m_lLastJobTook holds the time the last job took in millisecond.  
	 */
	protected static long m_lLastJobTook = -1;
	
	/**
	 * m_lTimeServiceStarted holds the service start time (in millisecond since 1970 UTC).    
	 */
	protected static long m_lTimeServiceStarted = System.currentTimeMillis();

	/**
	 * m_dServiceUtilization holds the service utilization (time solving jobs / total time since start)
	 */
	protected static double m_dServiceUtilization = -1.0;
	
	/**
	 * m_lTotalBusyTime holds the total busy time (solving jobs) since service start. 
	 */
	protected static long m_lTotalBusyTime = 0;
	
	/**
	 * m_sJobState holds the job state, which can be waiting, running, killed, finished or unknown.  
	 */
	protected String m_sJobState= "unknown";
	
	/**
	 * m_lJobStartTime holds the job start time. 
	 */
	protected long m_lJobStartTime = -1;

	/**
	 * m_lJobEndTime holds the job end time. 
	 */
	protected long m_lJobEndTime = -1;

	/**
	 * m_lJobDuration holds the time the job took in millisecond. 
	 */
	protected long m_lJobDuration = -1;

	/**
	 * timer holds the timer thread
	 */
	protected static Timer timer  = null;
	
	/**
	 * osql holds the OSqL query input string.
	 */
	public String osql = null;

	/**
	 * osel holds the OSeL entity input string to be registered.
	 */
	public String osel = null;

	/**
	 * osxl holds the OSxL input string to be validated.
	 */
	public String osxl = null;

	/**
	 * osplInput hols the OSpL knock process string (input)
	 */
	public String osplKnockInput = null;

	/**
	 * osolKnock holds the OSoL knock option string (input).
	 */
	public String osolKnock = null;

	/**
	 * osolRegister holds the OSoL register option string (input).
	 */
	public String osolRegister = null;

	/**
	 * osolFind holds the OSoL find option string (input).
	 */
	public String osolFind = null;

	/**
	 * osolValidate holds the OSoL validate option string (input).
	 */
	public String osolValidate = null;
	
	/**
	 * osplKnockOutput hols the OSpL knock process string (output)
	 */
	public String osplKnockOutput = null;

	/**
	 * osplValidateOutput hols the OSpL validate process string (output)
	 */
	public String osplValidateOutput = null;
	
	/**
	 * osplRegisterOutput hols the OSpL register process string (output)
	 */
	public String osplRegisterOutput = null;
	
	/**
	 * osul holds the os uri/url string (output)
	 */
	public String osul = null;
	
	/**
	 * osRegistry holds the registry database information in the standard OSRegistry data structure. 
	 */
	public static OSRegistry osRegistry = new OSRegistry();
	
	
	/**
	 * serviceHashTable holds a hash table of registered services.
	 * The key is the serviceURI, and the value is the service of type ServiceEntry
	 */
	public static Hashtable<String, ServiceEntry> serviceHashTable = new Hashtable<String, ServiceEntry>();
	
	/**
	 * m_osolReader holds the OSoL reader.
	 */
	protected OSoLReader m_osolReader = null;
	
	/**
	 * m_osplReader holds the OSpL reader.
	 */
	protected OSpLReader m_osplReader = null;
	
	/**
	 * m_osqlReader holds the OSqL reader.
	 */
	protected OSqLReader m_osqlReader = null;
	
	/**
	 * m_osulReader holds the OSuL reader.
	 */
	protected OSuLReader m_osulReader = null;

	/**
	 * m_osRegistryReader holds the OSRegistry reader.
	 */
	protected OSRegistryReader m_osRegistryReader = null;

	
	/**
	 * m_osolWriter holds the OSoL writer.
	 */
	protected OSoLWriter m_osolWriter = null;

	/**
	 * m_osplWriter holds the OSpL writer.
	 */
	protected OSpLWriter m_osplWriter = null;
	
	/**
	 * m_osqlWriter holds the OSqL writer.
	 */
	protected OSqLWriter m_osqlWriter = null;
	
	/**
	 * m_osulWriter holds the OSuL writer.
	 */
	protected OSuLWriter m_osulWriter = null;

	/**
	 * m_osRegistryWriter holds the OSRegistry writer.
	 */
	protected OSRegistryWriter m_osRegistryWriter = null;

	/**
	 *
	 * Default constructor. 
	 */
	public DefaultRegistry(){
	}//constructor
	
	
	/**
	 * register an Optimization Service whose instance is given by a string following 
	 * the Optimization Services entity Language (OSeL) schema and returns a string that contains 
	 * an XSLT style sheet transformation so that it can be used for standard web pubblication of the 
	 * Optimization Service that just joined. The XSLT is espcially used to publish the OSeL. 
	 */
	public void register(){
		if(osel == null) osel = "";
		if(osolRegister== null) osolRegister = "";

		m_osplWriter = new OSpLWriter();
		m_osplWriter.setServiceName((serviceName==null || serviceName.length() == 0)?OSParameter.SERVICE_NAME:serviceName);
		m_osplWriter.setServiceURI((serviceURI==null || serviceURI.length() == 0)?OSParameter.OS_REGISTRY_SITE:serviceURI);
		m_osplWriter.setProcessTime(new GregorianCalendar());

		//check osol
		boolean bSystemAdmin = false;
		String sServiceURIInOSoL = "";
		m_osolReader = new OSoLReader(m_bValidate);
		if(osolRegister != null && osolRegister.length() > 0){
			try {
				//get system password
				boolean bRead = m_osolReader.readString(osolRegister);
				if(!bRead){
					m_osplWriter.setResponseStatus("error");
					m_osplWriter.setResponseDescription("osol option string is invalid [registry]");
					osplRegisterOutput = m_osplWriter.writeToString();
					return;
				}
				m_sPassword = m_osolReader.getPassword();
				sServiceURIInOSoL = m_osolReader.getServiceURI();
				if(m_sPassword != null && m_sPassword.length() > 0 && OSParameter.checkSystemPassword(m_sPassword)){
					bSystemAdmin = true;
				}
			} 
			catch (Exception e) {
				m_osplWriter.setResponseStatus("error");
				m_osplWriter.setResponseDescription("osol option string is invalid: " + e.getMessage() + " [registry]");
				m_osplWriter.setProcessMessage(IOUtil.exceptionStackToString(e));
				osplRegisterOutput = m_osplWriter.writeToString();
				return;
			}
		}
		if(bSystemAdmin){
			try {
				//delete the service
				if(osel == null || osel.length() <= 0){
					int iService = osRegistry.service==null?0:osRegistry.service.length;
					ServiceEntry serviceEntry = serviceHashTable.get(sServiceURIInOSoL);
					if(serviceEntry != null){
						serviceHashTable.remove(sServiceURIInOSoL);
						int iNewService =  ((iService-1)<=0)?0:(iService-1);
						ServiceEntry[] mNewServices = new ServiceEntry[iNewService];
						int j = 0;
						for(int i = 0; i < iService; i++){
							try {
								if(sServiceURIInOSoL.equals(osRegistry.service[i].osel.getServiceURI())){
									continue;
								}
								mNewServices[j] = osRegistry.service[i];
								j++;								
							} 
							catch (Exception e) {
							}
						}
						osRegistry.service = mNewServices;
						m_osplWriter.setResponseStatus("success");
						m_osplWriter.setResponseDescription("The service is deleted [registry]");
						osplRegisterOutput = m_osplWriter.writeToString();
						return;
					}
					else{
						m_osplWriter.setResponseStatus("warning");
						m_osplWriter.setResponseDescription("Cannot find the service to delete in the registry given the serviceURI [registry]");
						osplRegisterOutput = m_osplWriter.writeToString();
						return;
					}
				}
				//add the service
				else{
					ServiceEntry newService = new ServiceEntry();
					OSeLReader oselReader = new OSeLReader(OSParameter.VALIDATE);
					if(!oselReader.readString(osel)){
						throw new Exception("Error reading OSeL file.");
					}
					newService.osel = oselReader.getOSEntity();
					newService.ospl.setServiceName(newService.osel.getServiceName());
					newService.ospl.setServiceURI(newService.osel.getServiceURI());
					newService.ospl.setProcessTime(new GregorianCalendar());
					newService.ospl.setCurrentState("noResponse");
		
					int iService = osRegistry.service==null?0:osRegistry.service.length;
					ServiceEntry[] service = osRegistry.service;
					
					ServiceEntry serviceEntry = serviceHashTable.get(newService.osel.getServiceURI());
					//update
					if(serviceEntry != null){
						serviceHashTable.remove(newService.osel.getServiceURI());
						serviceHashTable.put(newService.osel.getServiceURI(), newService);
						for(int i = 0; i < iService; i++){
							try {
								if((newService.osel.getServiceURI()).equals(osRegistry.service[i].osel.getServiceURI())){
									osRegistry.service[i] = newService;
									break;
								}								
							} 
							catch (Exception e) {
							}
						}
						m_osplWriter.setResponseStatus("success");
						m_osplWriter.setResponseDescription("The new service is updated [registry]");
					}
					//add
					else{
						ServiceEntry[] mNewServices = new ServiceEntry[iService+1];
						for(int i = 0; i < iService; i++){
							try {
								mNewServices[i] = service[i];								
							} 
							catch (Exception e) {
							}
						}
						mNewServices[iService] = newService; 
						serviceHashTable.put(newService.osel.getServiceURI(), newService);
						osRegistry.service = mNewServices;	
						m_osplWriter.setResponseStatus("success");
						m_osplWriter.setResponseDescription("The new service is added [registry]");

					}
					osplRegisterOutput = m_osplWriter.writeToString();
					
					//update process w/ thread
					OSpLWriter osplWriter = new OSpLWriter();
					osplWriter.setRequestAction("getServiceStatistics");
					osplWriter.setServiceName(m_sRegistryServiceName);
					osplWriter.setServiceURI(OSParameter.OS_REGISTRY_SITE);
					osplWriter.setProcessTime(new GregorianCalendar());
					String sOSpLInput = osplWriter.writeToString();
					
					OSoLWriter osolWriter = new OSoLWriter();
					osolWriter.setPassword(OSParameter.getSystemPassword());
					String sOSoL = osolWriter.writeToString();
					
					KnockThread knockThread = new KnockThread();
					knockThread.m_sOSpLInput = sOSpLInput;
					knockThread.m_sOSoL = sOSoL;
					
					String sServiceType = newService.osel.getServiceType();
					if(sServiceType != null && sServiceType.equals("scheduler")){
						knockThread.m_bSchedulerWithRegistry = OSParameter.SCHEDULER_WITH_REGISTRY;
					}
					else{
						knockThread.m_bSchedulerWithRegistry = false;
					}			
					knockThread.m_sAddress = newService.osel.getServiceURI();
					knockThread.m_bSetServiceStatistics = true;
					Thread thread = new Thread(knockThread);	
					thread.start();	
					return;
				}
			} 
			catch (Exception e) {
				IOUtil.log("Error in registering using system admin rights: \n\r" + IOUtil.exceptionStackToString(e), OSParameter.REGISTRY_REGISTRATION_FILE);
				m_osplWriter.setResponseStatus("error");
				m_osplWriter.setResponseDescription("Error in registering using system admin rights [registry]");
				m_osplWriter.setProcessMessage(IOUtil.exceptionStackToString(e));
				osplRegisterOutput = m_osplWriter.writeToString();			
				return;
			}
		}
		else{
			String sRegsitrationMessage = "\r\n" + osel + "\n\r\n\r" + osolRegister + "\r\n"; 
			IOUtil.log(sRegsitrationMessage, OSParameter.REGISTRY_REGISTRATION_FILE);
			String sSubject = "new OSRegistry registration";
			new MailUtil().sendInThread(OSParameter.FROM_EMAIL, OSParameter.TO_EMAIL, null, null, sSubject, sRegsitrationMessage, null);
			m_osplWriter = new OSpLWriter();
			m_osplWriter.setResponseStatus("success");
			m_osplWriter.setResponseDescription("The registration has been received  [registry]");
			String sMessage = "We will contact you according to the information that you provided.";
			m_osplWriter.setProcessMessage(sMessage);
			osplRegisterOutput = m_osplWriter.writeToString();
			return;
		}
	}//register
	
	/**
	 * Validate an osxl string according to the corresponding OSxL schema.
	 */	
	public void validate(){
		if(osxl == null) osxl = "";
		if(osolValidate== null) osolValidate = "";

		m_osplWriter = new OSpLWriter();
		String sStatus = "success";
		m_osplWriter.setResponseStatus("success");
		String sResponseDescription = "The OSxL string is valid";
		String sMessage = "";
		m_osplWriter.setProcessTime(new GregorianCalendar());
		m_osplWriter.setServiceName((serviceName==null || serviceName.length() == 0)?OSParameter.SERVICE_NAME:serviceName);
		m_osplWriter.setServiceURI((serviceURI==null || serviceURI.length() == 0)?OSParameter.OS_REGISTRY_SITE:serviceURI);
		
		//check osol
		if(osolValidate != null && osolValidate.length() > 0){
			try {
				m_osolReader = new OSoLReader(m_bValidate);
				boolean bRead = m_osolReader.readString(osolValidate);
				if(!bRead){
					m_osplWriter.setResponseStatus("error");
					m_osplWriter.setResponseDescription("osol option string is invalid [registry]");
					osplValidateOutput = m_osplWriter.writeToString();
					return;
				}
			} 
			catch (Exception e) {
				m_osplWriter.setResponseStatus("error");
				m_osplWriter.setResponseDescription("osol option string is invalid: " + e.getMessage() + " [registry]");
				m_osplWriter.setProcessMessage(IOUtil.exceptionStackToString(e));
				osplValidateOutput = m_osplWriter.writeToString();
				return;
			}
		}	
		
		try {
			DOMParser parser = new DOMParser();
			CommonErrorHandler commonErrorHandler = new CommonErrorHandler();
			parser.setFeature(OSConstant.SAX_VALIDATION_FEATURE, true);
			parser.setFeature(OSConstant.SCHEMA_FEATURE, true);
			parser.setErrorHandler(commonErrorHandler);
			InputSource is = new InputSource(new StringReader(osxl));
			parser.parse(is);
			if(commonErrorHandler.hasError()){
				sStatus = "error";
				sResponseDescription = "The string is not valid.";
				sMessage = commonErrorHandler.errorMessage;
			}
			else if(commonErrorHandler.hasWarning()){
				sStatus = "warning";
				sResponseDescription = "The string is likely valid but see the warning in the message.";
				sMessage = commonErrorHandler.warningMessage;
			}
		}
		catch(SAXException e) {
			sStatus = "error";
			sResponseDescription = e.getMessage();
			sMessage = IOUtil.exceptionStackToString(e);
		}
		catch(IOException e) {
			sStatus = "error";
			sResponseDescription = e.getMessage();
			sMessage = IOUtil.exceptionStackToString(e);
		}
		catch(Exception e){
			sStatus = "error";
			sResponseDescription = e.getMessage();
			sMessage = IOUtil.exceptionStackToString(e);
		}
		m_osplWriter.setResponseStatus(sStatus);
		m_osplWriter.setResponseDescription(sResponseDescription + " [registry]");
		m_osplWriter.setProcessMessage(sMessage);
		osplValidateOutput = m_osplWriter.writeToString();
		return;
	}//validate
	
	/**
	 * Discover an Optimization Service whose instance is given by a string following 
	 * the Optimization Services query Language (OSqL) schema and returns the location information
	 * in a string that follows the Optimization Services URI, or Universal Resource Indentifier 
	 * Language, (OSuL) schema.
	 */
	public void find(){
		if(osql == null) osql = "";
		if(osolFind== null) osolFind = "";

		try{
			if(osql != null && osql.length() > 0){
				m_osqlReader = new OSqLReader(m_bValidate);
				boolean bRead = m_osqlReader.readString(osql);
				if(!bRead){
					throw new Exception("OSqL query string is not valid");
				}
			}
		}
		catch(Exception e){
			IOUtil.log(IOUtil.exceptionStackToString(e), OSParameter.REGISTRY_LOG_FILE);
			m_osulWriter = new OSuLWriter();
			osul = m_osulWriter.writeToString();
			return;
		}
		try{
			if(osolFind != null && osolFind.length() > 0){
				m_osolReader = new OSoLReader(m_bValidate);
				boolean  bRead = m_osolReader.readString(osolFind);
				if(!bRead){
					throw new Exception("OSoL option string is not valid");
				}
			}
		}
		catch(Exception e){
			IOUtil.log(IOUtil.exceptionStackToString(e), OSParameter.REGISTRY_LOG_FILE);
			m_osulWriter = new OSuLWriter();
			osul = m_osulWriter.writeToString();
			return;
		}
		m_osulWriter = new OSuLWriter();
		int iServiceNumber = (osRegistry.service == null)?0:osRegistry.service.length;
		ServiceEntry[] service = osRegistry.service;
		
		StandardQuery standardQuery = null;
		String sXQuery = null;
		if(osql != null && osql.length() > 0){
			standardQuery = m_osqlReader.getStandardQuery();
			sXQuery = m_osqlReader.getXQuery();
		}
		try {
			if(standardQuery == null && (sXQuery == null || sXQuery.length() <= 0)){
				for(int i = 0; i < iServiceNumber; i++){
					try{
						String sServiceType = service[i].osel.getServiceType();
						if(sServiceType == null || sServiceType.length() <= 0) sServiceType = "solver";
						if(service[i] != null && service[i].ospl != null){
							String sCurrentState = service[i].ospl.getCurrentState();
							if(sCurrentState != null && (sCurrentState.equals("idle") || sCurrentState.equals("busyButAccepting")) && sServiceType.equals("solver")){
								URI uri = new URI();
								uri.value = service[i].osel.getServiceURI();
								if(uri.value != null || uri.value.length() > 0){
									uri.licenseRequired = service[i].osel.getLicenseRequired();
									uri.userNameRequired = service[i].osel.getUserNameRequired();
									uri.passwordRequired = service[i].osel.getPasswordRequired();
									m_osulWriter.addURI(uri);						
								}
							}
						}
					}
					catch(Exception e){					
					}
				}
				osul = m_osulWriter.writeToString();	
				return;
			}
			else if(sXQuery != null && sXQuery.length() > 0){//TODO XQuery
				osul = m_osulWriter.writeToString();	
				return;
			}
			else{//StandardQuery
				for(int i = 0; i < iServiceNumber; i++){
					try{
						if(service[i] == null) continue;
						//service type
						if(standardQuery.serviceType != null && standardQuery.serviceType.length() > 0){
							standardQuery.serviceType = "solver";
						}
						String sServiceType = service[i].osel.getServiceType();
						if(sServiceType == null || sServiceType.length() == 0) sServiceType = "solver";
						if(!sServiceType.equals(standardQuery.serviceType)){
							continue;
						}
						//current state
						if(standardQuery.currentState != null && standardQuery.currentState.length() > 0){
							if(service[i].ospl == null) continue;
							String sCurrentState = service[i].ospl.getCurrentState();
							if(sCurrentState == null || sCurrentState.length() <= 0){
								continue;
							}
							if(standardQuery.currentState.equals("accepting")){
								if(!sCurrentState.equals("idle") && !sCurrentState.equals("busyButAccepting")){
									continue;
								}
							}
							else if(standardQuery.currentState.equals("notAccepting")){
								if(sCurrentState.equals("idle") || sCurrentState.equals("busyButAccepting")){
									continue;
								}
							}
							else{
								if(!sCurrentState.equals(standardQuery.currentState)){
									continue;
								}
							}
						}
						if(standardQuery.optimization != null){
							//TODO
						}
						//add uri
						URI uri = new URI();
						uri.value = service[i].osel.getServiceURI();
						if(uri.value != null || uri.value.length() > 0){
							uri.licenseRequired = service[i].osel.getLicenseRequired();
							uri.userNameRequired = service[i].osel.getUserNameRequired();
							uri.passwordRequired = service[i].osel.getPasswordRequired();
							m_osulWriter.addURI(uri);
						}
					}
					catch(Exception e){
					}
				}
				osul = m_osulWriter.writeToString();
				return;
			}
		} 
		catch (Exception e) {
			IOUtil.log(IOUtil.exceptionStackToString(e), OSParameter.REGISTRY_LOG_FILE);
			osul = m_osulWriter.writeToString();
			return;
		}
	}//find
	
	/**
	 * This method is called by one optimization service on another optimization service
	 * to provide runtime dynamic process information (push mechanism).
	 */
	public void knock(){
		if(osplKnockInput == null) osplKnockInput = "";
		if(osolKnock == null) osolKnock = "";
		
		m_osplWriter = new OSpLWriter();
		m_osplWriter.setServiceName((serviceName==null || serviceName.length() == 0)?OSParameter.SERVICE_NAME:serviceName);
		m_osplWriter.setServiceURI((serviceURI==null || serviceURI.length() == 0)?OSParameter.OS_REGISTRY_SITE:serviceURI);
		m_osplWriter.setProcessTime(new GregorianCalendar());
		m_osplWriter.setResponseDescription("Information provided by the registry may not be exactly the same as that from the services");

		//check osol
		m_osolReader = new OSoLReader(m_bValidate);
		String sServiceURIInOSoL = "";
		if(osolKnock != null && osolKnock.length() > 0){
			try {
				//get general options
				boolean bRead = m_osolReader.readString(osolKnock);
				if(!bRead){
					m_osplWriter.setResponseStatus("error");
					m_osplWriter.setResponseDescription("osol option string is invalid [registry]");
					osplKnockOutput = m_osplWriter.writeToString();
					return;
				}
				m_sJobID = m_osolReader.getJobID();
				m_sInstanceName = m_osolReader.getInstanceName();
				
				//check license, userName, password
				m_sLicense = m_osolReader.getLicense();
				m_sUserName = m_osolReader.getUserName();
				m_sPassword = m_osolReader.getPassword();
				if(OSParameter.REQUIRE_LICENSE || OSParameter.REQUIRE_USER_NAME || OSParameter.REQUIRE_PASSWORD){
					boolean bCheck = false;
					if(m_sPassword != null && m_sPassword.length() > 0 && OSParameter.checkSystemPassword(m_sPassword)){
						bCheck = true;
						
					}
					else{
						if(OSParameter.REQUIRE_LICENSE){
							bCheck = OSParameter.checkLicense(m_sUserName, m_sLicense);							
							if(!bCheck){
								m_osplWriter.setResponseStatus("error");
								m_osplWriter.setResponseDescription("Wrong licence [registry]");
							}
						}
						if(bCheck && (OSParameter.REQUIRE_USER_NAME || OSParameter.REQUIRE_PASSWORD)){
							bCheck = OSParameter.checkUserNameAndPassword(m_sUserName, m_sPassword);
							if(!bCheck){
								m_osplWriter.setResponseStatus("error");
								m_osplWriter.setResponseDescription("Wrong user name and/or password [registry]");
							}
						}
					}
					if(!bCheck){
						osplKnockOutput = m_osplWriter.writeToString();
						return;
					}
				}

				//get contact
				m_sContactTransportType = m_osolReader.getContactTransportType();
				if(m_sContactTransportType == null || m_sContactTransportType.length() > 0){
					m_sContactTransportType = "osp";
				}
				m_sContactAddress = m_osolReader.getContact();
				
				sServiceURIInOSoL = m_osolReader.getServiceURI();
			} 
			catch (Exception e) {
				IOUtil.log(IOUtil.exceptionStackToString(e), OSParameter.REGISTRY_LOG_FILE);
				m_osplWriter.setResponseStatus("error");
				m_osplWriter.setResponseDescription(e.getMessage() + " [registry]");
				m_osplWriter.setProcessMessage(IOUtil.exceptionStackToString(e));
				osplKnockOutput = m_osplWriter.writeToString();
				return;
			}
		}
		else{
			//if no options, check license, userName, password requirements
			boolean bRequireLUP = false;
			if(m_sPassword != null && m_sPassword.length() > 0 && OSParameter.checkSystemPassword(m_sPassword)){
				bRequireLUP = false;
			}
			else{
				if(OSParameter.REQUIRE_LICENSE){
					bRequireLUP = true;
					m_osplWriter.setResponseStatus("error");
					m_osplWriter.setResponseDescription("The service requires license. [registry]");
				}
				if(OSParameter.REQUIRE_USER_NAME){
					bRequireLUP = true;
					m_osplWriter.setResponseStatus("error");
					m_osplWriter.setResponseDescription("The service requires user name. [registry]");
				}
				if(OSParameter.REQUIRE_PASSWORD){
					bRequireLUP = true;
					m_osplWriter.setResponseStatus("error");
					m_osplWriter.setResponseDescription("The service requires password. [registry]");
				}
			}
			if(bRequireLUP){
				osplKnockOutput = m_osplWriter.writeToString();
				return;
			}
		}
		
		//check ospl
		m_osplReader = new OSpLReader(m_bValidate);
		String sAction = "";
		String sRequestDescription = "";
		String sServiceName = "";
		String sServiceURI = "";
		GregorianCalendar processTime = null;
		String sProcessMessage = "";
		ProcessStatistics processStatistics = null;
		JobStatistics[] mJobStatistics = null;
		OptimizationProcess optimizationProcess = null;
				
		if(osplKnockInput == null || osplKnockInput.length() == 0){
			m_osplWriter.setResponseStatus("error");
			m_osplWriter.setResponseDescription("ospl string is empty [registry]");
			osplKnockOutput = m_osplWriter.writeToString();
			return;
		}
		else{
			try {
				boolean bRead = m_osplReader.readString(osplKnockInput);
				if(!bRead){
					m_osplWriter.setResponseStatus("error");
					m_osplWriter.setResponseDescription("ospl input string is invalid [registry]");
					osplKnockOutput = m_osplWriter.writeToString();
					return;
				}
				sAction = m_osplReader.getRequestAction();
				if((sAction == null || sAction.length() <= 0)){
					m_osplWriter.setResponseStatus("error");
					m_osplWriter.setResponseDescription("no request action specified in ospl [registry]");
					osplKnockOutput = m_osplWriter.writeToString();
					return;
				}
				else if(!sAction.equals("ping") &&
					    !sAction.equals("notifyJobCompletion") &&
					    !sAction.equals("requestJob") &&
					    !sAction.equals("getServiceStatistics") &&
					    !sAction.equals("setServiceStatistics") &&
					    !sAction.equals("getJobStatistics") &&
					    !sAction.equals("setJobStatistics") &&
					    !sAction.equals("getOptimization") &&
					    !sAction.equals("setOptimization") &&
					    !sAction.equals("getAll") &&
					    !sAction.equals("setAll")){
					m_osplWriter.setResponseStatus("error");
					m_osplWriter.setResponseDescription("request action specified in ospl has to one of the following values: " +
							"ping, notifyJobCompletion, requestJob, " +
							"getServiceStatistics, setServiceStatistics, " +
							"getJobStatistics, setJobStatistics, getOptimization, setOptimization, getAll, setAll [registry]");
					osplKnockOutput = m_osplWriter.writeToString();
					return;
				}
				sRequestDescription = m_osplReader.getRequestAction();
				sServiceName = m_osplReader.getServiceName();
				sServiceURI = m_osplReader.getServiceURI();
				processTime = m_osplReader.getProcessTime();
				sProcessMessage = m_osplReader.getProcessMessage();
				processStatistics = m_osplReader.getProcessStatistics();
				mJobStatistics = (processStatistics==null || processStatistics.jobs==null)?null:processStatistics.jobs.job;
				optimizationProcess = m_osplReader.getOptimizationProcess();

			}
			catch (Exception e) {
				IOUtil.log(IOUtil.exceptionStackToString(e), OSParameter.REGISTRY_LOG_FILE);
				m_osplWriter.setResponseStatus("error");
				m_osplWriter.setResponseDescription(e.getMessage() +  " [registry]");
				m_osplWriter.setProcessMessage(IOUtil.exceptionStackToString(e));
				osplKnockOutput = m_osplWriter.writeToString();
				return;
			}
		}
		boolean bKeepJobStatistics = true;
		boolean bKeepOptimization = false;
		if(sAction.equals("ping")){
			m_osplWriter.setResponseStatus("success");
			m_osplWriter.setResponseDescription("The registry service is alive [registry]");
			osplKnockOutput = m_osplWriter.writeToString();
			return;
		}//ping
		if(sAction.equals("notifyJobCompletion")){
			if(sServiceURIInOSoL != null && sServiceURIInOSoL.length() > 0){
				sServiceURI = sServiceURIInOSoL;
			}
			if(sServiceURI == null || sServiceURI.length() <= 0){
				m_osplWriter.setResponseStatus("error");
				m_osplWriter.setResponseDescription("No service URI is provided. [registry]");
				osplKnockOutput = m_osplWriter.writeToString();				
				return;
			}
			else{		
				try{
					ServiceEntry service = serviceHashTable.get(sServiceURI);
					if(service == null){
						m_osplWriter.setResponseStatus("warning");
						m_osplWriter.setResponseDescription("Cannot find the service in the registry given the serviceURI [registry]");
						return;
					}
					OSpLWriter osplWriter1 = new OSpLWriter();
					osplWriter1.setRequestAction("getServiceStatistics");
					osplWriter1.setServiceName(serviceName);
					osplWriter1.setServiceURI(serviceURI);
					osplWriter1.setProcessTime(new GregorianCalendar());
					String sOSpLInput = osplWriter1.writeToString();
					
					OSoLWriter osolWriter1 = new OSoLWriter();
					osolWriter1.setPassword(m_sSystemPassword);
					String sOSoLInput = osolWriter1.writeToString();
					
					KnockThread knockThread = new KnockThread();
					knockThread.m_sOSpLInput = sOSpLInput;
					knockThread.m_sOSoL = sOSoLInput;
					
					String sServiceType = service.osel.getServiceType();
					if(sServiceType != null && sServiceType.equals("scheduler")){
						knockThread.m_bSchedulerWithRegistry = OSParameter.SCHEDULER_WITH_REGISTRY;
					}
					else{
						knockThread.m_bSchedulerWithRegistry = false;
					}			
					knockThread.m_sAddress = sServiceURI;
					knockThread.m_bSetServiceStatistics = true;
					Thread thread = new Thread(knockThread);	
					thread.start();
	
				}
				catch (Exception e){
					IOUtil.log(IOUtil.exceptionStackToString(e), OSParameter.REGISTRY_LOG_FILE);
				}
				m_osplWriter.setResponseStatus("success");
				m_osplWriter.setResponseDescription("The service has got the notification. [registry]");
				return;
			}
		}//notifyJobCompletion
		if(sAction.equals("requestJob")){
			m_osplWriter.setResponseStatus("warning");
			m_osplWriter.setResponseDescription("The registry service does not take job request. [registry]");
			osplKnockOutput = m_osplWriter.writeToString();
			return;		
		}//requestJob
		if(sAction.equals("getServiceStatistics" ) || sAction.equals("getAll")){
			if(sServiceURIInOSoL == null || sServiceURIInOSoL.length() <= 0){
				sServiceURIInOSoL = sServiceURI;
			}
			if(sServiceURIInOSoL == null || sServiceURIInOSoL.length() <= 0){
				m_osplWriter.setResponseStatus("error");
				m_osplWriter.setResponseDescription("No service URI is provided. [registry]");
				osplKnockOutput = m_osplWriter.writeToString();				
				return;
			}
			else{
				m_osplWriter.setServiceURI(sServiceURIInOSoL);
				try {
					ServiceEntry serviceEntry = serviceHashTable.get(sServiceURIInOSoL);
					if(serviceEntry != null){
						m_osplWriter.setProcessStatistics(serviceEntry.ospl.getProcessStatistics());
						if(!sAction.equals("getAll")){
							m_osplWriter.setResponseStatus("success");
							m_osplWriter.setResponseDescription("Got the service statistics. It may not exactly the same as that from the service");
							osplKnockOutput = m_osplWriter.writeToString();				
							return;
						}
					}
					else{
						m_osplWriter.setResponseStatus("warning");
						m_osplWriter.setResponseDescription("cannot find the service URI provided. [registry]");
						osplKnockOutput = m_osplWriter.writeToString();				
						return;					
					}
				} 
				catch (Exception e) {
					IOUtil.log(IOUtil.exceptionStackToString(e), OSParameter.REGISTRY_LOG_FILE);
					m_osplWriter.setResponseStatus("warning");
					m_osplWriter.setResponseDescription("Unable to provide the information: " + e.getMessage() + " [registry]");
					m_osplWriter.setProcessMessage(IOUtil.exceptionStackToString(e));
					osplKnockOutput = m_osplWriter.writeToString();				
					return;					
				}			
			}
		}//getServiceStatistics
		if(sAction.equals("setServiceStatistics") || sAction.equals("setAll")){
			if(sServiceURIInOSoL == null || sServiceURIInOSoL.length() <= 0){
				sServiceURIInOSoL = sServiceURI;
			}
			if(sServiceURIInOSoL == null || sServiceURIInOSoL.length() <= 0){
				m_osplWriter.setResponseStatus("error");
				m_osplWriter.setResponseDescription("No service URI is provided. [registry]");
				osplKnockOutput = m_osplWriter.writeToString();				
				return;
			}
			else{
				m_osplWriter.setServiceURI(sServiceURIInOSoL);
				try {
					ServiceEntry serviceEntry = serviceHashTable.get(sServiceURIInOSoL);
					if(serviceEntry != null){
						if(!bKeepJobStatistics){
							processStatistics.jobs = null;
						}
						String sNewState = processStatistics.currentState;
						if(sNewState != null && !sServiceURIInOSoL.equals(OSParameter.OS_SCHEDULER_SITE) &&
								(sNewState.equals("busy") || sNewState.equals("idleButNotAccepting") || sNewState.equals("noResponse"))){
							if(OSParameter.SCHEDULER_WITH_REGISTRY){
								OSServiceUtil.acceptingSolverURIs.remove(sServiceURIInOSoL);
							}
						}
						serviceEntry.ospl.setProcessStatistics(processStatistics);
						if(!sAction.equals("setAll")){
							m_osplWriter.setResponseStatus("success");
							m_osplWriter.setResponseDescription("Set the service statistics. [registry]");
							osplKnockOutput = m_osplWriter.writeToString();				
							return;					
						}
					}
					else{
						m_osplWriter.setResponseStatus("warning");
						m_osplWriter.setResponseDescription("cannot find the service URI provided. [registry]");
						osplKnockOutput = m_osplWriter.writeToString();				
						return;					
					}
				} 
				catch (Exception e) {
					IOUtil.log(IOUtil.exceptionStackToString(e), OSParameter.REGISTRY_LOG_FILE);
					m_osplWriter.setResponseStatus("warning");
					m_osplWriter.setResponseDescription("Unable to update information: " + e.getMessage() + " [registry]");
					m_osplWriter.setProcessMessage(IOUtil.exceptionStackToString(e));
					osplKnockOutput = m_osplWriter.writeToString();				
					return;					
				}			
			}
		}//setServiceStatistics
		if(sAction.equals("getJobStatistics")){
			if(!bKeepJobStatistics){
				m_osplWriter.setResponseStatus("warning");
				m_osplWriter.setResponseDescription("The registry service does not keep job statistics. [registry]");
				osplKnockOutput = m_osplWriter.writeToString();
				return;		
			}
			if(sServiceURIInOSoL == null || sServiceURIInOSoL.length() <= 0){
				sServiceURIInOSoL = sServiceURI;
			}
			if(sServiceURIInOSoL == null || sServiceURIInOSoL.length() <= 0){
				m_osplWriter.setResponseStatus("error");
				m_osplWriter.setResponseDescription("No service URI is provided. [registry]");
				osplKnockOutput = m_osplWriter.writeToString();				
				return;
			}
			else{
				m_osplWriter.setServiceURI(sServiceURIInOSoL);
				try {
					ServiceEntry serviceEntry = serviceHashTable.get(sServiceURIInOSoL);
					if(serviceEntry != null){
						m_osplWriter.setJobStatistics(serviceEntry.ospl.getJobStatistics());
						m_osplWriter.setResponseStatus("success");
						m_osplWriter.setResponseDescription("Got the job statistics. [registry]");
						osplKnockOutput = m_osplWriter.writeToString();				
						return;					
					}
					else{
						m_osplWriter.setResponseStatus("warning");
						m_osplWriter.setResponseDescription("cannot find the service URI provided. [registry]");
						osplKnockOutput = m_osplWriter.writeToString();				
						return;					
					}
				} 
				catch (Exception e) {
					IOUtil.log(IOUtil.exceptionStackToString(e), OSParameter.REGISTRY_LOG_FILE);
					m_osplWriter.setResponseStatus("warning");
					m_osplWriter.setResponseDescription("Unable to provide the information: " + e.getMessage() + " [registry]");
					m_osplWriter.setProcessMessage(IOUtil.exceptionStackToString(e));
					osplKnockOutput = m_osplWriter.writeToString();				
					return;					
				}			
			}
		}//getJobStatistics
		if(sAction.equals("setJobStatistics")){
			if(!bKeepJobStatistics){
				m_osplWriter.setResponseStatus("warning");
				m_osplWriter.setResponseDescription("The registry service does not keep job statistics. [registry]");
				osplKnockOutput = m_osplWriter.writeToString();
				return;		
			}
			if(sServiceURIInOSoL == null || sServiceURIInOSoL.length() <= 0){
				sServiceURIInOSoL = sServiceURI;
			}
			if(sServiceURIInOSoL == null || sServiceURIInOSoL.length() <= 0){
				m_osplWriter.setResponseStatus("error");
				m_osplWriter.setResponseDescription("No service URI is provided. [registry]");
				osplKnockOutput = m_osplWriter.writeToString();				
				return;
			}
			else{
				m_osplWriter.setServiceURI(sServiceURIInOSoL);
				try {
					ServiceEntry serviceEntry = serviceHashTable.get(sServiceURIInOSoL);
					if(serviceEntry != null){
						serviceEntry.ospl.setJobStatistics(mJobStatistics);
						m_osplWriter.setResponseStatus("success");
						m_osplWriter.setResponseDescription("Set the job statistics. [registry]");
						osplKnockOutput = m_osplWriter.writeToString();				
						return;					
					}
					else{
						m_osplWriter.setResponseStatus("warning");
						m_osplWriter.setResponseDescription("cannot find the service URI provided. [registry]");
						osplKnockOutput = m_osplWriter.writeToString();				
						return;					
					}
				} 
				catch (Exception e) {
					IOUtil.log(IOUtil.exceptionStackToString(e), OSParameter.REGISTRY_LOG_FILE);
					m_osplWriter.setResponseStatus("warning");
					m_osplWriter.setResponseDescription("Unable to update information: " + e.getMessage() + " [registry]");
					m_osplWriter.setProcessMessage(IOUtil.exceptionStackToString(e));
					osplKnockOutput = m_osplWriter.writeToString();				
					return;					
				}			
			}	
		}//setJobStatistics
		if(sAction.equals("getOptimization") || (sAction.equals("getAll") && bKeepOptimization)){
			if(!bKeepOptimization){
				m_osplWriter.setResponseStatus("warning");
				m_osplWriter.setResponseDescription("The registry service does not keep optimization information. [registry]");
				osplKnockOutput = m_osplWriter.writeToString();
				return;		
			}
			if(sServiceURIInOSoL == null || sServiceURIInOSoL.length() <= 0){
				sServiceURIInOSoL = sServiceURI;
			}
			if(sServiceURIInOSoL == null || sServiceURIInOSoL.length() <= 0){
				m_osplWriter.setResponseStatus("error");
				m_osplWriter.setResponseDescription("No service URI is provided. [registry]");
				osplKnockOutput = m_osplWriter.writeToString();				
				return;
			}
			else{
				try {
					ServiceEntry serviceEntry = serviceHashTable.get(sServiceURIInOSoL);
					if(serviceEntry != null){
						m_osplWriter.setOptimizationProcess(serviceEntry.ospl.getOptimizationProcess());
						if(!sAction.equals("getAll")){
							m_osplWriter.setResponseStatus("success");
							m_osplWriter.setResponseDescription("Got the optimization information. [registry]");
							osplKnockOutput = m_osplWriter.writeToString();				
							return;					
						}
					}
					else{
						m_osplWriter.setResponseStatus("warning");
						m_osplWriter.setResponseDescription("cannot find the service URI provided. [registry]");
						osplKnockOutput = m_osplWriter.writeToString();				
						return;					
					}
				} 
				catch (Exception e) {
					IOUtil.log(IOUtil.exceptionStackToString(e), OSParameter.REGISTRY_LOG_FILE);
					m_osplWriter.setResponseStatus("warning");
					m_osplWriter.setResponseDescription("Unable to provide the information: " + e.getMessage() + " [registry]");
					m_osplWriter.setProcessMessage(IOUtil.exceptionStackToString(e));
					osplKnockOutput = m_osplWriter.writeToString();				
					return;					
				}			
			}
		}//getOptimization
		if(sAction.equals("setOptimization") || (sAction.equals("setAll") && bKeepOptimization)){
			if(!bKeepOptimization){
				m_osplWriter.setResponseStatus("warning");
				m_osplWriter.setResponseDescription("The registry service does not keep optimization information. [registry]");
				osplKnockOutput = m_osplWriter.writeToString();
				return;		
			}
			if(sServiceURIInOSoL == null || sServiceURIInOSoL.length() <= 0){
				sServiceURIInOSoL = sServiceURI;
			}
			if(sServiceURIInOSoL == null || sServiceURIInOSoL.length() <= 0){
				m_osplWriter.setResponseStatus("error");
				m_osplWriter.setResponseDescription("No service URI is provided. [registry]");
				osplKnockOutput = m_osplWriter.writeToString();				
				return;
			}
			else{
				try {
					ServiceEntry serviceEntry = serviceHashTable.get(sServiceURIInOSoL);
					if(serviceEntry != null){
						serviceEntry.ospl.setOptimizationProcess(optimizationProcess);
						if(!sAction.equals("setAll")){
							m_osplWriter.setResponseStatus("success");
							m_osplWriter.setResponseDescription("Set the optimization information. [registry]");
							osplKnockOutput = m_osplWriter.writeToString();				
							return;					
						}
					}
					else{
						m_osplWriter.setResponseStatus("warning");
						m_osplWriter.setResponseDescription("cannot find the service URI provided. [registry]");
						osplKnockOutput = m_osplWriter.writeToString();				
						return;					
					}
				} 
				catch (Exception e) {
					IOUtil.log(IOUtil.exceptionStackToString(e), OSParameter.REGISTRY_LOG_FILE);
					m_osplWriter.setResponseStatus("warning");
					m_osplWriter.setResponseDescription("Unable to update information: " + e.getMessage() + " [registry]");
					m_osplWriter.setProcessMessage(IOUtil.exceptionStackToString(e));
					osplKnockOutput = m_osplWriter.writeToString();				
					return;					
				}			
			}	
		}//setOptimization
		if(sAction.equals("getAll")){
			m_osplWriter.setResponseStatus("success");					
			m_osplWriter.setResponseDescription("All the information has been obtained. [registry]");
			osplKnockOutput = m_osplWriter.writeToString();
			return;	
		}//getAll
		if(sAction.equals("setAll")){
			m_osplWriter.setResponseStatus("success");					
			m_osplWriter.setResponseDescription("All the information has been set. [registry]");
			osplKnockOutput = m_osplWriter.writeToString();
			return;	
		}//setAll

		m_osplWriter.setResponseStatus("error");
		m_osplWriter.setResponseDescription("Request action is not recognized. [registry]");
		osplKnockOutput = m_osplWriter.writeToString();
		return;				
	}//knock

	/**
	 * <P>The <code>KnockThread</code> class is an internal thread controlled by <code>DefaultRegistry</code>.
	 */
	protected static class KnockThread implements Runnable{
		/**
		 * m_sOSpLInput holds the OSpL process input for the knock. 
		 */
		protected String m_sOSpLInput = null;
		
		/**
		 * m_sOSoL holds the OSoL process input for the knock.
		 */
		protected String m_sOSoL = null;
		
		/**
		 * m_sAddress holds the address of the remote solver or scheduler. 
		 */
		protected String m_sAddress = null;
		
		/**
		 * m_bSchedulerWithRegistry holds whether the scheduler is with the registry. 
		 */
		protected boolean m_bSchedulerWithRegistry = false;
		
		/**
		 * m_sOSpLOutput holds the OSpL process output for the knock.
		 */
		protected String m_sOSpLOutput = null;
	
		/**
		 * m_bSetServiceStatistics holds whether to set the service statistics after knocking. 
		 */
		protected boolean m_bSetServiceStatistics = false;
		
		/**
		 * default constructor.
		 */
		protected KnockThread(){
		}//constructor

		/**
		 * A knock method is implemented here. 
		 */
		public void run(){	
			ServiceEntry serviceEntry = serviceHashTable.get(m_sAddress);
			if(m_bSchedulerWithRegistry){
				try{
					OSServiceUtil osServiceUtil = new OSServiceUtil();
					osServiceUtil.serviceName = OSParameter.SERVICE_NAME;
					osServiceUtil.serviceURI = OSParameter.OS_SCHEDULER_SITE;
					osServiceUtil.serviceType = "scheduler";
					osServiceUtil.solver = null;
					m_sOSpLOutput = osServiceUtil.knock(m_sOSpLInput, m_sOSoL);					
				}
				catch (Exception e) {
					IOUtil.log("Error invoking scheduler \n\r" + IOUtil.exceptionStackToString(e), OSParameter.REGISTRY_LOG_FILE);
					return;
				}
			}
			else{
				try {
					OSSolverAgent solverAgent = new OSSolverAgent(m_sAddress);
					m_sOSpLOutput = solverAgent.knock(m_sOSpLInput, m_sOSoL);
					if(m_sOSpLOutput == null || m_sOSpLOutput.length() <= 0){
						throw new Exception("Unable to contact at the provided service URI: " + m_sAddress);
					}
				} 
				catch (Exception e) {
					IOUtil.log("Error contacting " + m_sAddress, OSParameter.REGISTRY_LOG_FILE);
					if(serviceEntry != null){
						serviceEntry.ospl.setCurrentState("noResponse");							
					}
					return;
				}
			}
			if(m_bSetServiceStatistics){
				if(serviceEntry != null){
					try {
						OSpLReader osplReader = new OSpLReader();
						osplReader.readString(m_sOSpLOutput);
						OSProcess osProcess = osplReader.getOSProcess();
						serviceEntry.ospl.processHeader = osProcess.processHeader;
						serviceEntry.ospl.setProcessStatistics(osplReader.getProcessStatistics());
					} 
					catch (Exception e){
						IOUtil.log("Can't set service statistics: \n\r" + IOUtil.exceptionStackToString(e), OSParameter.REGISTRY_LOG_FILE);			
						return;
					} 		
					try {
						OSRegistryWriter osRegistryWriter = new OSRegistryWriter();
						osRegistryWriter.setOSRegistry(DefaultRegistry.osRegistry);
						osRegistryWriter.writeToFile(OSParameter.REGISTRY_FILE+"_backup");
						return;
					} 
					catch (Exception e) {
						IOUtil.log(IOUtil.exceptionStackToString(e), OSParameter.REGISTRY_LOG_FILE);
						return;
					}
				}
				else{
					IOUtil.log("Cannot find service " + m_sAddress, OSParameter.REGISTRY_LOG_FILE);
					return;
				}
				
			}
		}//run		
	}//KnockThread
	
	/**
	 * main for test purposes.
	 *
	 * </p>
	 *
	 * @param argv command line arguments.
	 */
	public static void main(String[] args){
	}//main
	/**
	 * <P>The <code>ServiceTask1</code> class is an internal 
	 * timer task class called by <code>OSServiceUtil</code>.
	 * It is carried out in short intervals periodically.  
	 */
    protected static class ServiceTask1 extends TimerTask {//TODO delete IOUtil.log & make timmer long
    	/**
    	 * Specifies the task to run. 
    	 */
        public void run() { 
			int iService = osRegistry.service==null?0:osRegistry.service.length;
			String sSystemPassword = OSParameter.getSystemPassword();
			//backup registry
			try {
				OSRegistryWriter osRegistryWriter = new OSRegistryWriter();
				osRegistryWriter.setOSRegistry(DefaultRegistry.osRegistry);
				osRegistryWriter.writeToFile(OSParameter.REGISTRY_FILE+"_backup");
			} 
			catch (Exception e) {
				IOUtil.log(IOUtil.exceptionStackToString(e), OSParameter.REGISTRY_LOG_FILE);
			}

			//pull info and update services
			for(int i = 0; i < iService; i++){
				try{
					OSpLWriter osplWriter = new OSpLWriter();
					osplWriter.setRequestAction("getServiceStatistics");
					osplWriter.setServiceName(m_sRegistryServiceName);
					osplWriter.setServiceURI(OSParameter.OS_REGISTRY_SITE);
					osplWriter.setProcessTime(new GregorianCalendar());
					String sOSpLInput = osplWriter.writeToString();
					
					OSoLWriter osolWriter = new OSoLWriter();
					osolWriter.setPassword(sSystemPassword);
					String sOSoL = osolWriter.writeToString();
					
					KnockThread knockThread = new KnockThread();
					knockThread.m_sOSpLInput = sOSpLInput;
					knockThread.m_sOSoL = sOSoL;
					
					String sServiceType = osRegistry.service[i].osel.getServiceType();
					if(sServiceType != null && sServiceType.equals("scheduler")){
						knockThread.m_bSchedulerWithRegistry = OSParameter.SCHEDULER_WITH_REGISTRY;
					}
					else{
						knockThread.m_bSchedulerWithRegistry = false;
					}			
					knockThread.m_sAddress = osRegistry.service[i].osel.getServiceURI();
					knockThread.m_bSetServiceStatistics = true;
					Thread thread = new Thread(knockThread);	
					thread.start();
				}
				catch(Exception e){
				}			
			}
		}//run
    }//class ServiceTask1
    
	/**
	 * <P>The <code>ServiceTask2</code> class is an internal 
	 * timer task class called by <code>OSServiceUtil</code>.
	 * It is carried out periodically in intervals that are neither too short nor too long. 
	 */
    protected static class ServiceTask2 extends TimerTask {
    	/**
    	 * Specifies the task to run. 
    	 */
        public void run() {     
			//clean up disks
        	if(!OSParameter.SCHEDULER_WITH_REGISTRY){
        		IOUtil.cleanUpDisk();
        	}
            //prepare report
        	String sSummaryReport = "";
        	StringBuffer sbDetailedReport = new StringBuffer();
    		int iServiceNumber = (osRegistry.service == null)?0:osRegistry.service.length;
    		int iIdle = 0;
    		int iIdleButNotAccepting = 0;
    		int iBusy = 0;
    		int iBusyButAccepting = 0;
    		int iUnknown = 0;
    		String sSchedulerState = "";
    		String sTime = XMLUtil.createXSDateTime(new GregorianCalendar());
    		sSummaryReport += (sTime + ",");
    		
    		String sLine = "*************************************\r\n";
    		sbDetailedReport.append(sLine);
    		sbDetailedReport.append(sTime+"\r\n");
    		ServiceEntry[] service = osRegistry.service;
			for(int i = 0; i < iServiceNumber; i++){
				try{
					String sServiceURI = service[i].osel.getServiceURI();
					String sServiceName = service[i].osel.getServiceName();
					String sServiceType = service[i].osel.getServiceType();
					if(sServiceType == null || sServiceType.length() == 0) sServiceType = "solver";
					sbDetailedReport.append(sServiceURI+", " + sServiceName+", " + sServiceType+"\r\n");
					if(service[i] != null && service[i].ospl != null){
						String sCurrentState = service[i].ospl.getCurrentState();
						sbDetailedReport.append(sCurrentState+",");
						sbDetailedReport.append(service[i].ospl.getAvailableDiskSpace()+",");
						sbDetailedReport.append(service[i].ospl.getAvailableMemory()+",");
						sbDetailedReport.append(service[i].ospl.getCurrentJobCount()+",");
						sbDetailedReport.append(service[i].ospl.getTotalJobsSoFar()+",");
						sbDetailedReport.append(XMLUtil.createXSDateTime(service[i].ospl.getTimeLastJobEnded()));
						sbDetailedReport.append(service[i].ospl.getTimeLastJobTook()+",");
						sbDetailedReport.append(XMLUtil.createXSDateTime(service[i].ospl.getTimeServiceStarted()));
						sbDetailedReport.append(service[i].ospl.getServiceUtilization()+"\r\n");
						if(sServiceType.equals("solver")){
							if(sCurrentState == null){
								iUnknown++;
							}
							else if(sCurrentState.equals("idle")){
								iIdle++;
							}
							else if(sCurrentState.equals("idleButNotAccepting")){
								iIdleButNotAccepting++;
							}
							else if(sCurrentState.equals("busy")){
								iBusy++;
							}
							else if(sCurrentState.equals("busyButAccepting")){
								iBusyButAccepting++;
							}
							else{
								iUnknown++;
							}
						}
						else{
							sSchedulerState = sCurrentState;
						}
					}
					else{
						iUnknown++;
					}
				}
				catch(Exception e){
				}
			}//for
			sSummaryReport += (iServiceNumber+","+sSchedulerState+","+iIdle+","+iIdleButNotAccepting+","+iBusy+","+iBusyButAccepting+"\r\n");
			IOUtil.appendStringToFile(sSummaryReport, OSParameter.REGISTRY_SUMMARY_REPORT);
    		sbDetailedReport.append(sLine);
    		IOUtil.appendStringToFile(sbDetailedReport.toString(), OSParameter.REGISTRY_DETAILED_REPORT); 
    		//end preparing report

        }//run
    }//class ServiceTask2
    

	/**
	 * <P>The <code>ServiceTask3</code> class is an internal 
	 * timer task class called by <code>OSServiceUtil</code>.
	 * It is carried out periodically in long intervals. 
	 */
    protected static class ServiceTask3 extends TimerTask {
    	/**
    	 * Specifies the task to run. 
    	 */
        public void run() {
			int iService = osRegistry.service==null?0:osRegistry.service.length;
			String sSystemPassword = OSParameter.getSystemPassword();
			//pull info and update services
			for(int i = 0; i < iService; i++){
				try{
					OSpLWriter osplWriter = new OSpLWriter();
					osplWriter.setRequestAction("getServiceStatistics");
					osplWriter.setServiceName(m_sRegistryServiceName);
					osplWriter.setServiceURI(OSParameter.OS_REGISTRY_SITE);
					osplWriter.setProcessTime(new GregorianCalendar());
					String sOSpLInput = osplWriter.writeToString();
					
					OSoLWriter osolWriter = new OSoLWriter();
					osolWriter.setPassword(sSystemPassword);
					String sOSoL = osolWriter.writeToString();				
					
					OSSolverAgent solverAgent = new OSSolverAgent();
					solverAgent.solverAddress = osRegistry.service[i].osel.getServiceURI();
					try {
						OSpLReader osplReader = new OSpLReader();
						String sOSpLOutput = solverAgent.knock(sOSpLInput, sOSoL);
						if(sOSpLOutput == null || sOSpLOutput.length() <= 0){
							throw new Exception("Unable to contact at the provided service URI: " + solverAgent.solverAddress);
						}
						boolean bRead = osplReader.readString(sOSpLOutput);
						if(!bRead){
							throw new Exception("OSpL output string is not valid");
						}
						if(osplReader.getCurrentState().equals("idleButNotAccepting")){
							String sError = "solver " + solverAgent.solverAddress + "is not accepting jobs";
							IOUtil.log(sError, OSParameter.REGISTRY_LOG_FILE);
							new MailUtil().sendInThread(OSParameter.FROM_EMAIL, null, null, null, OSParameter.MAIL_SUBJECT, sError, null );					
						}
					} 
					catch (Exception e){
						String sError = "unable to get service statistics from " + solverAgent.solverAddress;
						IOUtil.log(sError, OSParameter.REGISTRY_LOG_FILE);
						new MailUtil().sendInThread(OSParameter.FROM_EMAIL, null, null, null, OSParameter.MAIL_SUBJECT, sError, null );					
					}     
				}
				catch(Exception e){
				}
			}
			new MailUtil().sendInThread(OSParameter.FROM_EMAIL, null, null, null, "REGISTRY_SUMMARY_REPORT", "", OSParameter.REGISTRY_SUMMARY_REPORT );					
			new MailUtil().sendInThread(OSParameter.FROM_EMAIL, null, null, null, "REGISTRY_DETAILED_REPORT", "", OSParameter.REGISTRY_DETAILED_REPORT );					

        }//run
    }//class ServiceTask3

	/**
	 * static constructor
	 */
	static {
		if(!OSParameter.SCHEDULER_WITH_REGISTRY){
			DefaultRegistry.m_sRegistryServiceName = OSParameter.SERVICE_NAME;
		}

		//carry out maintenance
		if(true || OSParameter.SERVICE_TYPE != null &&
				(OSParameter.SERVICE_TYPE.equals("registry") || 
				(OSParameter.SERVICE_TYPE.equals("scheduler") && OSParameter.SCHEDULER_WITH_REGISTRY))){
			m_sSystemPassword = OSParameter.getSystemPassword();
			//load osRegistry information from backup file if it is more updated
			OSRegistryReader osRegistryReader = new OSRegistryReader();
			String sFileName = OSParameter.REGISTRY_FILE;
			String sBackupFileName = sFileName+"_backup";
			try {
				if((!IOUtil.existsFileOrDir(sFileName) && IOUtil.existsFileOrDir(sBackupFileName)) || 
					(IOUtil.existsFileOrDir(sBackupFileName) && IOUtil.getLastWriteTime(sBackupFileName) > IOUtil.getLastWriteTime(sFileName))){
					IOUtil.copyFile(sBackupFileName, sFileName);
				}
				osRegistryReader.readFile(sFileName);
				DefaultRegistry.osRegistry = osRegistryReader.getOSRegistry();
			} 
			catch (Exception e) {
				IOUtil.log(IOUtil.exceptionStackToString(e), null);
			}
			int iService = DefaultRegistry.osRegistry.service==null?0:DefaultRegistry.osRegistry.service.length;
			for(int i = 0; i < iService; i++){			
				try{
					DefaultRegistry.serviceHashTable.put(DefaultRegistry.osRegistry.service[i].osel.getServiceURI(), DefaultRegistry.osRegistry.service[i]);
				}
				catch(Exception e){
				}
			}
			
			m_lTimeServiceStarted = System.currentTimeMillis();
			
			//pull info and update services
			OSpLWriter osplWriter = new OSpLWriter();
			osplWriter.setRequestAction("getServiceStatistics");
			osplWriter.setServiceName(m_sRegistryServiceName);
			osplWriter.setServiceURI(OSParameter.OS_REGISTRY_SITE);
			osplWriter.setProcessTime(new GregorianCalendar());
			String sOSpLInput = osplWriter.writeToString();
			
			OSoLWriter osolWriter = new OSoLWriter();
			osolWriter.setPassword(m_sSystemPassword);
			String sOSoL = osolWriter.writeToString();

			Thread[] mThread = new Thread[iService];
			for(int i = 0; i < iService; i++){
				try{					
					KnockThread knockThread = new KnockThread();
					knockThread.m_sOSpLInput = sOSpLInput;
					knockThread.m_sOSoL = sOSoL;
					
					String sServiceType = osRegistry.service[i].osel.getServiceType();
					if(sServiceType != null && sServiceType.equals("scheduler")){
						knockThread.m_bSchedulerWithRegistry = OSParameter.SCHEDULER_WITH_REGISTRY;
					}
					else{
						knockThread.m_bSchedulerWithRegistry = false;
					}			
					knockThread.m_sAddress = osRegistry.service[i].osel.getServiceURI();
					knockThread.m_bSetServiceStatistics = true;
					Thread thread = new Thread(knockThread);	
					mThread[i] = thread;
					thread.start();
				}
				catch(Exception e){
					IOUtil.log(IOUtil.exceptionStackToString(e), null);
				}			
			}
			long lTimeSpan = 10000L;
			for(int i = 0; i < iService; i++){
				try{	
					mThread[i].join(lTimeSpan);
				}
				catch(Exception e){
					IOUtil.log(IOUtil.exceptionStackToString(e), null);
				}			
			}
			
			timer = new Timer();
			timer.schedule(new ServiceTask1(), 0, OSParameter.SERVICE_POLLING_INTERVAL_SHORT);
			timer.schedule(new ServiceTask2(), 3000, OSParameter.SERVICE_POLLING_INTERVAL_MEDIUM);
			timer.schedule(new ServiceTask3(), 7000, OSParameter.SERVICE_POLLING_INTERVAL_LONG);
		}
	}//static constructor.
	
}//class DefaultRegistry
