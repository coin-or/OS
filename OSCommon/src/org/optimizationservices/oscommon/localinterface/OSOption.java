/**
 * @(#)OSOption 1.0 03/14/2005
 *
 * Copyright (c) 2005 
 */
package org.optimizationservices.oscommon.localinterface;

import java.util.GregorianCalendar;
import java.util.Hashtable;

import org.optimizationservices.oscommon.datastructure.osgeneral.JobDependencies;
import org.optimizationservices.oscommon.datastructure.osgeneral.DirectoriesAndFiles;
import org.optimizationservices.oscommon.datastructure.osgeneral.Processes;
import org.optimizationservices.oscommon.datastructure.osoption.ContactOption;
import org.optimizationservices.oscommon.datastructure.osoption.GeneralOption;
import org.optimizationservices.oscommon.datastructure.osoption.InitVarValue;
import org.optimizationservices.oscommon.datastructure.osoption.InitialVariableValues;
import org.optimizationservices.oscommon.datastructure.osoption.InstanceLocationOption;
import org.optimizationservices.oscommon.datastructure.osoption.JobOption;
import org.optimizationservices.oscommon.datastructure.osoption.OptimizationOption;
import org.optimizationservices.oscommon.datastructure.osoption.OtherOption;
import org.optimizationservices.oscommon.datastructure.osoption.OtherOptions;
import org.optimizationservices.oscommon.datastructure.osoption.PathPair;
import org.optimizationservices.oscommon.datastructure.osoption.PathPairs;
import org.optimizationservices.oscommon.datastructure.osoption.ServiceOption;
import org.optimizationservices.oscommon.datastructure.osoption.SolverOption;
import org.optimizationservices.oscommon.datastructure.osoption.SolverOptions;
import org.optimizationservices.oscommon.datastructure.osoption.SystemOption;
import org.optimizationservices.oscommon.datastructure.osoption.VariableOption;
import org.optimizationservices.oscommon.representationparser.OSoLReader;
import org.optimizationservices.oscommon.representationparser.OSoLWriter;


/**
*
* <P>The <code>OSOption</code> class is a local interface for storing Optimization Services
* options, especially solver service options. Its design follows the Optimization Services 
* option Language (OSoL). All the data structures in this class are standards specified in OSoL. 
* Developers can add service-specific options by extending this class.  
*
* @author Robert Fourer, Jun Ma, Kipp Martin
* @version 1.0, 03/14/2005
* @see org.optimizationservices.oscommon.localinterface.OSInstance
* @see org.optimizationservices.oscommon.localinterface.OSResult
* @see org.optimizationservices.oscommon.localinterface.OSAnalysis
* @since OS 1.0
*/
public class OSOption {

	/**
	 * m_iVariableNumber holds the variable number. 
	 */
	private int m_iVariableNumber = -1;
	
	/**
	 * m_iObjectiveNumber holds the objective number. 
	 */
	private int m_iObjectiveNumber = -1;
	
	/**
	 * m_iConstraintNumber holds the constraint number. 
	 */
	private int m_iConstraintNumber = -1;
	
	/**
	 * general holds the general option specified by the OSoL Schema. 
	 */
	public GeneralOption general = new GeneralOption();
	
	/**
	 * system holds the system option specified by the OSoL Schema. 
	 */
	public SystemOption system = new SystemOption();

	/**
	 * service holds the service option specified by the OSoL Schema. 
	 */
	public ServiceOption service = new ServiceOption();

	
	/**
	 * job holds the job option specified by the OSoL Schema. 
	 */
	public JobOption job = new JobOption();
	
	/**
	 * optimization holds the optimization option specified by the OSoL Schema. 
	 */
	public OptimizationOption optimization = new OptimizationOption();

	/**
	 *
	 * Default constructor. 
	 */
	public OSOption(){
	}//constructor
	
	/**
	 * read an OSoL instance and return and OSOption object.  
	 * 
	 * @param osol holds the optimization option in a string which format follows the
	 * Optimization Services option Language (OSoL) schema.
	 * @param isFile holds whether the osol string is a file name or a string that literally holds the osol contents.  
	 * @param validate holds whether the reader should be validating against the schema or not.
	 * @return the OSOption object constructed from the OSoL String.  
	 * @throws Exception if there are errors in reading the string or setting the OSOption. 
	 */
   	public OSOption readOSoL(String osol, boolean isFile, boolean validate) throws Exception{
   		OSoLReader osolReader = new OSoLReader(validate);
		boolean bRead = false;
		if(isFile){
			bRead = osolReader.readFile(osol);
		}
		else{
			bRead = osolReader.readString(osol);			
		}
		if(!bRead) throw new Exception("OSoL string not valid");
		return osolReader.getOSOption();
   	}//readOSoL
   	
   	/**
   	 * write the OSOption to an osol xml string. 
   	 * 
   	 * @return the osol xml string. 
	 * @throws Exception if there are errors in writing the osol string. 
   	 */
   	public String writeOSoL() throws Exception{
		OSoLWriter osolWriter = new OSoLWriter();
		osolWriter.setOSOption(this);
		return osolWriter.writeToString();
   	}//writeOSoL
   	
   	/**
	 * Get service name.
	 * 
	 * @return the service name. 
	 */
	public String getServiceName(){
		return general.serviceName;
	}//getServiceName
	
   	/**
	 * Set service name.
	 * 
	 * @param serviceName holds the name of the service. 
	 * @return whether the service name is set successfully. 
	 */
	public boolean setServiceName(String serviceName){
		general.serviceName = serviceName;
		return true;
	}//setServiceName

   	/**
	 * Get service uri.
	 * 
	 * @return the service uri. 
	 */
	public String getServiceURI(){
		return general.serviceURI;
	}//getServiceURI
	
   	/**
	 * Set service uri.
	 * 
	 * @param serviceURI holds the uri of the service. 
	 * @return whether the service uri is set successfully. 
	 */
	public boolean setServiceURI(String serviceURI){
		general.serviceURI = serviceURI;
		return true;
	}//setServiceURI
	
   	/**
	 * Get instance name.
	 * 
	 * @return the instance name. 
	 */
	public String getInstanceName(){
		return general.instanceName;
	}//getInstanceName
	
   	/**
	 * Set instance name.
	 * 
	 * @param instanceName holds the name of the instance. 
	 * @return whether the instance name is set successfully. 
	 */
	public boolean setInstanceName(String instanceName){
		general.instanceName = instanceName;
		return true;
	}//setInstanceName
	
	/**
	 * Get the instance address to get the instance. 
	 * 
	 * @return the instance address, null or empty string if none. 
	 */
	public String getInstanceLocation(){
		if(general.instanceLocation == null) general.instanceLocation = new InstanceLocationOption();
		return general.instanceLocation.value;
	}//getInstanceLocation
	
	/**
	 * Set the instance address to get the instance. 
	 * 
	 * @param address holds the instance address. 
	 * @return whether the instance address is set successfully.
	 */
	public boolean setInstanceLocation(String address){
		if(general.instanceLocation == null) general.instanceLocation = new InstanceLocationOption();
		general.instanceLocation.value = address;
		return true;
	}//setInstanceLocation

	/**
	 * Get the instance location type to get the instance. 
	 * e.g. local, http, ftp.
	 * 
	 * @return the instance location type, null or empty string if none. 
	 */
	public String getInstanceLocationType(){
		if(general.instanceLocation == null) general.instanceLocation = new InstanceLocationOption();
		return general.instanceLocation.locationType;
	}//getInstanceLocationType
	
	/**
	 * Set the instance location type to get the instance. 
	 * 
	 * @param locationType holds the instance location type, e.g. local, http, ftp.
	 * @return whether the instance location type is set successfully.
	 */
	public boolean setInstanceLocationType(String locationType){
		if(general.instanceLocation == null) general.instanceLocation = new InstanceLocationOption();
		general.instanceLocation.locationType = locationType;
		return true;
	}//setInstanceLocationType

	/**
	 * Get job ID. 
	 * 
	 * @return the job ID, null or empty string if none. 
	 */
	public String getJobID(){
		return general.jobID;
	}//getJobID
	
	/**
	 * Set jobID.
	 * 
	 * @param jobID holds the jobID.
	 * @return whether the jobID is set successfully.
	 */
	public boolean setJobID(String jobID){
		general.jobID = jobID;
		return true;
	}//setJobID

	/**
	 * Get the solver to invoke. 
	 * 
	 * @return the solver to invoke, null or empty string if none. 
	 */
	public String getSolverToInvoke(){
		return general.solverToInvoke;
	}//getSolverToInvoke
	
	/**
	 * Set jobID.
	 * 
	 * @param jobID holds the jobID.
	 * @return whether the jobID is set successfully.
	 */
	public boolean setSolverToInvoke(String solverToInvoke){
		general.solverToInvoke = solverToInvoke;
		return true;
	}//setSolverToInvoke

	/**
	 * Get license. 
	 * 
	 * @return the license, null or empty string if none. 
	 */
	public String getLicense(){
		return general.license;
	}//getLicense
	
	/**
	 * Set license.
	 * 
	 * @param license holds the license required by the service.
	 * @return whether the license is set successfully.
	 */
	public boolean setLicense(String license){
		general.license = license;
		return true;
	}//setLicense

	/**
	 * Get the userName. 
	 * 
	 * @return the user name, null or empty string if none. 
	 */
	public String getUserName(){
		return general.userName;
	}//getUserName
	
	/**
	 * Set the user name.
	 * 
	 * @param userName holds the user name required by the service.
	 * @return whether the user name is set successfully.
	 */
	public boolean setUserName(String userName){
		general.userName = userName;
		return true;
	}//setUserName
	
	/**
	 * Get the password. 
	 * 
	 * @return the password, null or empty string if none. 
	 */
	public String getPassword(){
		return general.password;
	}//getPassword
	
	/**
	 * Set the password.
	 * 
	 * @param password holds the password required by the service.
	 * @return whether the password is set successfully.
	 */
	public boolean setPassword(String password){
		general.password = password;
		return true;
	}//setPassword
	
	/**
	 * Get the contact address to respond to the requester. 
	 * For example it can be an email address if the contact transport type is smtp
	 * or a http uri if the contact transport type is osp (for knocking back on the requester), etc.
	 * 
	 * @return the contact trasport address, null or empty string if none. 
	 */
	public String getContact(){
		return general.contact.value;
	}//getContact
	
	/**
	 * Set the contact address to respond to the requester. 
	 * For example it can be an email address if the contact transport type is smtp
	 * or a http uri if the contact transport type is osp (for knocking back on the requester), etc.
	 * 
	 * @param address holds the contact address. 
	 * @return whether the contact address is set successfully.
	 */
	public boolean setContact(String address){
		general.contact.value = address;
		return true;
	}//setContact
	
	/**
	 * Get the contact transport type to respond to the requester,
	 * smtp (for email), osp (for knocking back on the requester), etc.
	 * 
	 * @return the contact trasport type, null or empty string if none. 
	 */
	public String getContactTransportType(){
		if(general.contact == null) general.contact = new ContactOption();
		return general.contact.transportType;
	}//getContactTransportType
	
	/**
	 * Set the contact transport type to respond to the requester,
	 * smtp (for email), osp (for knocking back on the requester), etc.
	 * 
	 * @param transportType holds the contact transport type. 
	 * @return whether the contact transport type is set successfully.
	 */
	public boolean setContactTransportType(String transportType){
		if(general.contact == null) general.contact = new ContactOption();
		general.contact.transportType = transportType;
		return true;
	}//setContactTransportType
	
	/**
	 * get the number of other <general> options
	 * 
	 * @return the number of other <general> options
	 */
	public int  getNumberOfOtherGeneralOptions(){
		if(general.otherOptions == null) return 0;
		else return general.otherOptions.numberOfOtherOptions;
	}//getNumberOfOtherGeneralOptions
	
	/**
	 * Set the number of other general options. 
	 * 
	 * @param numberOfOtherGeneralOptions holds the number of other general options
	 * @return whether the number is set successfully or not. 
	 */
	public boolean setNumberOfOtherGeneralOptions(int numberOfOtherGeneralOptions){
		if(numberOfOtherGeneralOptions < 0) return false;
		if(general.otherOptions == null) general.otherOptions = new OtherOptions();
		general.otherOptions.numberOfOtherOptions = numberOfOtherGeneralOptions;
		return true;
	}//setNumberOfOtherGeneralOptions
	
	/**
	 * get the array of other <general> options
	 * 
	 * @return the array of other <general> options
	 */
	public OtherOption[] getOtherGeneralOptions(){
		if(general.otherOptions == null) return null;
		else return general.otherOptions.other;
	}//getOtherGeneralOptions
	
	
	/**
	 * set the array of other <general> options
	 * 
	 * @return  whether the other options element construction is successful.
	 */
	public boolean setOtherGeneralOptions(OtherOption[] other){
		if(general.otherOptions == null) general.otherOptions = new OtherOptions();
		int n = other==null?0:other.length;
		general.otherOptions.numberOfOtherOptions = n; 
		general.otherOptions.other = other;
		return true;
	}//setOtherGeneralOptions
	
	/**
	 * Set the other general options. 
	 * 
	 * @param names holds the names of the other options. It is required. 
	 * @param values holds the values of the other options, empty string "" or null if no value for an option.
	 * @param descriptions holds the descriptions of the other options, empty string "" or null if no value for an option, null for
	 * the entire array if none of the options have descriptions.
	 * @return whether the other options element construction is successful.
	 */
	public boolean setOtherGeneralOptions(String[] names, String[] values, String[] descriptions){
		if(names == null) return false;
		if(descriptions != null && descriptions.length != names.length) return false;
		if(values != null && values.length != names.length) return false;		
		
		int n = names.length;
		
		if(general.otherOptions == null) general.otherOptions = new OtherOptions();
		general.otherOptions.numberOfOtherOptions = n;
		general.otherOptions.other = new OtherOption[n];
		
		for(int i = 0; i < n; i++){
			general.otherOptions.other[i] = new OtherOption();
		}
		for(int i = 0; i < n; i++){
			general.otherOptions.other[i].name = names[i];
		}
		if(descriptions != null){
			for(int i = 0; i < n; i++){
				general.otherOptions.other[i].description = descriptions[i];
			}	
		}
		if(values != null){
			for(int i = 0; i < n; i++){
				general.otherOptions.other[i].value = values[i];
			}	
		}
		return true;
	}//setOtherGeneralOptions
	
	/**
	 * Get the system minimum disk space required to solve the job. 
	 * 
	 * @return the system minimum disk space, 0.0 if none. 
	 */
	public double getMinDiskSpace(){
		return system.minDiskSpace.value;
	}//getMinDiskSpace
	
	/**
	 * Set the the system minimum disk space required to solve the job.
	 * 
	 * @param minDiskSpace holds the  minimum disk space required to solve the job. 
	 * @return whether the minimum disk space is set successfully.
	 */
	public boolean setMinDiskSpace(double minDiskSpace){
		if(minDiskSpace < 0) system.minDiskSpace.value = 0;
		else system.minDiskSpace.value = minDiskSpace;
		return true;
	}//setMinDiskSpace

	/**
	 * Get the unit of the system minimum disk space required to solve the job. 
	 * 
	 * @return the unit of the system minimum disk space, byte if none. 
	 */
	public String getMinDiskSpaceUnit(){
		return system.minDiskSpace.unit;
	}//getMinDiskSpaceUnit
	
	/**
	 * Set the unit of the system minimum disk space required to solve the job.
	 * 
	 * @param unit holds the unit of the disk space.
	 * @return whether the unit of the minimum disk space is set successfully.
	 */
	public boolean setMinDiskSpaceUnit(String unit){
		system.minDiskSpace.unit = unit;
		return true;
	}//setMinDiskSpaceUnit
	
	/**
	 * Get the system minimum memory size required to solve the job. 
	 * 
	 * @return the system minimum memory size, 0.0 if none. 
	 */
	public double getMinMemorySize(){
		return system.minMemorySize.value;
	}//getMinMemorySize
	
	/**
	 * Set the the system minimum memory size required to solve the job.
	 * 
	 * @param minMemorySize holds the  minimum memory size required to solve the job. 
	 * @return whether the minimum memory size is set successfully.
	 */
	public boolean setMinMemorySize(double minMemorySize){
		if(minMemorySize < 0) system.minMemorySize.value = 0;
		else system.minMemorySize.value = minMemorySize;
		return true;
	}//setMinMemorySize

	/**
	 * Get the unit of the system minimum memory size required to solve the job. 
	 * 
	 * @return the unit of the system minimum memory size, byte if none. 
	 */
	public String getMinMemorySizeUnit(){
		return system.minMemorySize.unit;
	}//getMinMemorySizeUnit
	
	/**
	 * Set the unit of the system minimum memory size required to solve the job.
	 * 
	 * @param unit holds the unit of the memory size.
	 * @return whether the unit of the minimum memory size is set successfully.
	 */
	public boolean setMinMemorySizeUnit(String unit){
		system.minMemorySize.unit = unit;
		return true;
	}//setMinMemorySize
	
	/**
	 * Get the system minimum cpu speed required to solve the job. 
	 * 
	 * @return the system minimum cpu speed, 0.0 if none. 
	 */
	public double getMinCPUSpeed(){
		return system.minCPUSpeed.value;
	}//getMinCPUSpeed
	
	/**
	 * Set the the system minimum cpu speed required to solve the job.
	 * 
	 * @param minCPUSpeed holds the  minimum cpu speed required to solve the job. 
	 * @return whether the minimum cpu speed is set successfully.
	 */
	public boolean setMinCPUSpeed(double minCPUSpeed){
		if(minCPUSpeed < 0) system.minCPUSpeed.value = 0;
		else system.minCPUSpeed.value = minCPUSpeed;
		return true;
	}//setMinCPUSpeed

	/**
	 * Get the unit of the system minimum cpu speed required to solve the job. 
	 * 
	 * @return the unit of the system minimum cpu speed, 0.0 if none. 
	 */
	public String getMinCPUSpeedUnit(){
		return system.minCPUSpeed.unit;
	}//getMinCPUSpeedUnit
	
	/**
	 * Set the unit of the system cpu speed required to solve the job.
	 * 
	 * @param unit holds the unit of the cpu speed.
	 * @return whether the unit of the minimum cpu speed is set successfully.
	 */
	public boolean setMinCPUSpeedUnit(String unit){
		system.minCPUSpeed.unit = unit;
		return true;
	}//setMinCPUSpeedUnit
	
	/**
	 * Get the system minimum cpu number required to solve the job. 
	 * 
	 * @return the system minimum cpu number, 0 if none. 
	 */
	public int getMinCPUNumber(){
		return system.minCPUNumber;
	}//getMinCPUNumber
	

	/**
	 * Set the the system minimum cpu number required to solve the job.
	 * 
	 * @param minCPUNumber holds the  minimum cpu number required to solve the job. 
	 * @return whether the minimum cpu number is set successfully.
	 */
	public boolean setMinCPUNumber(int minCPUNumber){
		system.minCPUNumber = minCPUNumber;
		return true;
	}//setMinCPUNumber
	
	/**
	 * get the number of other <system> options
	 * 
	 * @return the number of other <system> options
	 */
	public int  getNumberOfOtherSystemOptions(){
		if(system.otherOptions == null) return 0;
		else return system.otherOptions.numberOfOtherOptions;
	}//getNumberOfOtherSystemOptions
	
	/**
	 * Set the number of other system options. 
	 * 
	 * @param numberOfOtherSystemOptions holds the number of other system options
	 * @return whether the number is set successfully or not. 
	 */
	public boolean setNumberOfOtherSystemOptions(int numberOfOtherSystemOptions){
		if(numberOfOtherSystemOptions < 0) return false;
		if(system.otherOptions == null) system.otherOptions = new OtherOptions();
		system.otherOptions.numberOfOtherOptions = numberOfOtherSystemOptions;
		return true;
	}//setNumberOfOtherSystemOptions
	
	/**
	 * get the array of other <system> options
	 * 
	 * @return the array of other <system> options
	 */
	public OtherOption[] getOtherSystemOptions(){
		if(system.otherOptions == null) return null;
		else return system.otherOptions.other;
	}//getOtherSystemOptions
	
	
	/**
	 * set the array of other <system> options
	 * 
	 * @return  whether the other options element construction is successful.
	 */
	public boolean setOtherSystemOptions(OtherOption[] other){
		if(system.otherOptions == null) system.otherOptions = new OtherOptions();
		int n = other==null?0:other.length;
		system.otherOptions.numberOfOtherOptions = n; 
		system.otherOptions.other = other;
		return true;
	}//setOtherSystemOptions
	
	/**
	 * Set the other system options. 
	 * 
	 * @param names holds the names of the other options. It is required. 
	 * @param values holds the values of the other options, empty string "" or null if no value for an option.
	 * @param descriptions holds the descriptions of the other options, empty string "" or null if no value for an option, null for
	 * the entire array if none of the options have descriptions.
	 * @return whether the other options element construction is successful.
	 */
	public boolean setOtherSystemOptions(String[] names, String[] values, String[] descriptions){
		if(names == null) return false;
		if(descriptions != null && descriptions.length != names.length) return false;
		if(values != null && values.length != names.length) return false;		
		
		int n = names.length;
		
		if(system.otherOptions == null) system.otherOptions = new OtherOptions();
		system.otherOptions.numberOfOtherOptions = n;
		system.otherOptions.other = new OtherOption[n];
		
		for(int i = 0; i < n; i++){
			system.otherOptions.other[i] = new OtherOption();
		}
		for(int i = 0; i < n; i++){
			system.otherOptions.other[i].name = names[i];
		}
		if(descriptions != null){
			for(int i = 0; i < n; i++){
				system.otherOptions.other[i].description = descriptions[i];
			}	
		}
		if(values != null){
			for(int i = 0; i < n; i++){
				system.otherOptions.other[i].value = values[i];
			}	
		}
		return true;
	}//setOtherSystemOptions
	
	/**
	 * Get the service type, which can be: 
	 * solver, analyzer, scheduler, simulation, registry, modeler, agent 
	 * 
	 * @return the service type; null or empty string if none. 
	 */
	public String getServiceType(){
		return service.type;
	}//getServiceType
	
	/**
	 * Set the service type. 
	 * 
	 * @param type holds the service type, which can be:
	 * solver, analyzer, scheduler, simulation, registry, modeler, agent 
	 * 
	 * @return whether the service type is set successfully or not. 
	 */
	public boolean setServiceType(String type){
		if(!type.equals("solver") && 
		   !type.equals("analyzer") &&
		   !type.equals("scheduler") &&
		   !type.equals("simulation") &&
		   !type.equals("registry") &&
		   !type.equals("modeler") &&
		   !type.equals("agent")) return false;
		service.type = type;
		return true;
	}//setServiceType

	/**
	 * get the number of other <service> options
	 * 
	 * @return the number of other <service> options
	 */
	public int  getNumberOfOtherServiceOptions(){
		if(service.otherOptions == null) return 0;
		else return service.otherOptions.numberOfOtherOptions;
	}//getNumberOfOtherServiceOptions
	
	/**
	 * Set the number of other service options. 
	 * 
	 * @param numberOfOtherServiceOptions holds the number of other service options
	 * @return whether the number is set successfully or not. 
	 */
	public boolean setNumberOfOtherServiceOptions(int numberOfOtherServiceOptions){
		if(numberOfOtherServiceOptions < 0) return false;
		if(service.otherOptions == null) service.otherOptions = new OtherOptions();
		service.otherOptions.numberOfOtherOptions = numberOfOtherServiceOptions;
		return true;
	}//setNumberOfOtherServiceOptions
	
	/**
	 * get the array of other <service> options
	 * 
	 * @return the array of other <service> options
	 */
	public OtherOption[] getOtherServiceOptions(){
		if(service.otherOptions == null) return null;
		else return service.otherOptions.other;
	}//getOtherServiceOptions
	
	
	/**
	 * set the array of other <service> options
	 * 
	 * @return  whether the other options element construction is successful.
	 */
	public boolean setOtherServiceOptions(OtherOption[] other){
		if(service.otherOptions == null) service.otherOptions = new OtherOptions();
		int n = other==null?0:other.length;
		service.otherOptions.numberOfOtherOptions = n; 
		service.otherOptions.other = other;
		return true;
	}//setOtherServiceOptions
	
	/**
	 * Set the other service options. 
	 * 
	 * @param names holds the names of the other options. It is required. 
	 * @param values holds the values of the other options, empty string "" or null if no value for an option.
	 * @param descriptions holds the descriptions of the other options, empty string "" or null if no value for an option, null for
	 * the entire array if none of the options have descriptions.
	 * @return whether the other options element construction is successful.
	 */
	public boolean setOtherServiceOptions(String[] names, String[] values, String[] descriptions){
		if(names == null) return false;
		if(descriptions != null && descriptions.length != names.length) return false;
		if(values != null && values.length != names.length) return false;		
		
		int n = names.length;
		
		if(service.otherOptions == null) service.otherOptions = new OtherOptions();
		service.otherOptions.numberOfOtherOptions = n;
		service.otherOptions.other = new OtherOption[n];
		
		for(int i = 0; i < n; i++){
			service.otherOptions.other[i] = new OtherOption();
		}
		for(int i = 0; i < n; i++){
			service.otherOptions.other[i].name = names[i];
		}
		if(descriptions != null){
			for(int i = 0; i < n; i++){
				service.otherOptions.other[i].description = descriptions[i];
			}	
		}
		if(values != null){
			for(int i = 0; i < n; i++){
				service.otherOptions.other[i].value = values[i];
			}	
		}
		return true;
	}//setOtherServiceOptions
	
	/**
	 * Get the maximum time (in seconds) before the job is terminated.  
	 * 
	 * @return the maximum time, Double.POSITIVE_INFINITY if none. 
	 */
	public double getMaxTime(){
		return job.maxTime.value;
	}//getMaxTime
	
	/**
	 * Set the maximum time before the job is terminated.  
	 * 
	 * @param maxTime holds the maximum time in seconds. 
	 * @return whether the maximum time is set successfully.
	 */
	public boolean setMaxTime(double maxTime){
		if(maxTime <= 0) return false;
		else job.maxTime.value = maxTime;
		return true;
	}//setMaxTime

	/**
	 * Get the unit of the job max time required to solve the job. 
	 * 
	 * @return the unit of the system minimum cpu speed, 0.0 if none. 
	 */
	public String getMaxTimeUnit(){
		return job.maxTime.unit;
	}//getMaxTimeUnit
	
	/**
	 * Set the unit of the maximum time before the job is terminated.  
	 * 
	 * @param maxTime holds the maximum time in seconds. 
	 * @return whether the maximum time is set successfully.
	 */
	public boolean setMaxTimeUnit(String unit){
		job.maxTime.unit = unit;
		return true;
	}//setMaxTimeUnit
	
	/**
	 * Get the scheduled start time for the job.   
	 * 
	 * @return the scheduled start time for the job, null or UNIX time (1970/1/1) if none. 
	 */
	public GregorianCalendar getScheduledStartTime(){ 
		return job.scheduledStartTime;
	}//getScheduledStartTime
	
	/**
	 * Set the scheduled start time for the job.   
	 * 
	 * @param scheduledStartTime holds the scheduled start time for the job.   
	 * @return whether the scheduled start time is set successfully.
	 */
	public boolean setScheduledStartTime(GregorianCalendar scheduledStartTime){
		if(scheduledStartTime.getTimeInMillis() <= 0) job.scheduledStartTime = new GregorianCalendar(1970, 0, 1, 0, 0, 0);
		else job.scheduledStartTime = scheduledStartTime;
		return true;
	}//setScheduledStartTime
	
	/**
	 * get the number of job dependencies (in <job> element)
	 * 
	 * @return the number of job dependencies (in <job> element)
	 */
	public int  getNumberOfJobDependencies(){
		if(job.dependencies == null) return 0;
		return job.dependencies.numberOfJobIDs;
	}//getNumberOfJobDependencies
	
	/**
	 * Get the dependencies of the current job, which is 
	 * a string array of ids of the jobs that have run before the current job. 
	 * 
	 * @return a string array of ids of the jobs that have to run before the current job. 
	 */
	public String[] getJobDependencies(){
		if(job.dependencies == null) return null;
		return job.dependencies.jobID;
	}//getJobDependencies
	
	/**
	 * Get the dependencies of the current job, which is 
	 * a string array of ids of the jobs that have run before the current job. 
	 * @param jobIDs holds a string array of ids of the jobs that have run before the current job. 
	 * @return whether the job dependencies are set successfully.
	 */
	public boolean setJobDependencies(String[] jobIDs){
		if(job.dependencies == null) job.dependencies = new JobDependencies();
		job.dependencies.jobID = jobIDs;
		int n = (jobIDs==null?0:jobIDs.length);
		job.dependencies.numberOfJobIDs = n;
		return true;
	}//setJobDependencies

	/**
	 * get the number of required directories (in <job> element)
	 * 
	 * @return the number of required directories (in <job> element)
	 */
	public int  getNumberOfRequiredDirectories(){
		if(job.requiredDirectories == null) return 0;
		return job.requiredDirectories.numberOfPaths;
	}//getNumberOfRequiredDirectories
	
	/**
	 * Get the required directories to run the job, which is 
	 * a string array of paths. 
	 * 
	 * @return a string array of direcotry paths required to run the job. 
	 */
	public String[] getRequiredDirectories(){
		if(job.requiredDirectories == null) return null;
		return job.requiredDirectories.path;
	}//getRequiredDirectoriesAndFiles

	/**
	 * Set the required directories to run the job, which is 
	 * a string array of paths. 
	 * @param paths holds a string array of directory paths required to run the job. 
	 * @return whether the required directories are set successfully.
	 */
	public boolean setRequiredDirectories(String[] paths){
		if(job.requiredDirectories == null) job.requiredDirectories = new DirectoriesAndFiles();
		job.requiredDirectories.path = paths;
		int n = (paths==null?0:paths.length);
		job.requiredDirectories.numberOfPaths = n;
		return true;
	}//setRequiredDirectories

	/**
	 * get the number of required files (in <job> element)
	 * 
	 * @return the number of required files (in <job> element)
	 */
	public int  getNumberOfRequiredFiles(){
		if(job.requiredFiles == null) return 0;
		return job.requiredFiles.numberOfPaths;
	}//getNumberOfRequiredFiles
	
	/**
	 * Get the required files to run the job, which is 
	 * a string array of paths. 
	 * 
	 * @return a string array of file paths required to run the job. 
	 */
	public String[] getRequiredFiles(){
		if(job.requiredFiles == null) return null;
		return job.requiredFiles.path;
	}//getRequiredFiles

	/**
	 * Set the required files to run the job, which is 
	 * a string array of paths. 
	 * @param paths holds a string array of file paths required to run the job. 
	 * @return whether the required files are set successfully.
	 */
	public boolean setRequiredFiles(String[] paths){
		if(job.requiredFiles == null) job.requiredFiles = new DirectoriesAndFiles();
		job.requiredFiles.path = paths;
		int n = (paths==null?0:paths.length);
		job.requiredFiles.numberOfPaths = n;
		return true;
	}//setRequiredFiles

	/**
	 * get the number of directories to make (in <job> element)
	 * 
	 * @return the number of directories to make (in <job> element)
	 */
	public int  getNumberOfDirectoriesToMake(){
		if(job.directoriesToMake == null) return 0;
		return job.directoriesToMake.numberOfPaths;
	}//getNumberOfDirectoriesToMake

	/**
	 * Get the directories to make before running the job, which is 
	 * a string array of paths. 
	 * 
	 * @return a string array of direcotry paths to make. 
	 */
	public String[] getDirectoriesToMake(){
		if(job.directoriesToMake == null) return null;
		return job.directoriesToMake.path;
	}//getDirectoriesToMake

	/**
	 * Set the directories to make before running the job, which is 
	 * a string array of paths. 
	 * @param paths holds a string array of directories to make before running the job. 
	 * @return whether the directories to make are set successfully.
	 */
	public boolean setDirectoriesToMake(String[] paths){
		if(job.directoriesToMake == null) job.directoriesToMake = new DirectoriesAndFiles();
		job.directoriesToMake.path = paths;
		int n = (paths==null?0:paths.length);
		job.directoriesToMake.numberOfPaths = n;
		return true;
	}//setDirectoriesToMake

	/**
	 * get the number of files to make (in <job> element)
	 * 
	 * @return the number of files to make (in <job> element)
	 */
	public int  getNumberOfFilesToMake(){
		if(job.filesToMake == null) return 0;
		return job.filesToMake.numberOfPaths;
	}//getNumberOfFilesToMake
	
	/**
	 * Get the files to make before running the job, which is 
	 * a string array of paths. 
	 * 
	 * @return a string array of file paths to make. 
	 */
	public String[] getFilesToMake(){
		if(job.filesToMake == null) return null;
		return job.filesToMake.path;
	}//getFilesToMake

	/**
	 * Set the files to make before running the job, which is 
	 * a string array of paths. 
	 * @param paths holds a string array of files to make before running the job. 
	 * @return whether the files to make are set successfully.
	 */
	public boolean setFilesToMake(String[] paths){
		if(job.filesToMake == null) job.filesToMake = new DirectoriesAndFiles();
		job.filesToMake.path = paths;
		int n = (paths==null?0:paths.length);
		job.filesToMake.numberOfPaths = n;
		return true;
	}//setFilesToMake

	/**
	 * get the number of input directories to move or copy (in <job> element)
	 * 
	 * @return the number of input directories to move or copy (in <job> element)
	 */
	public int  getNumberOfInputDirectoriesToMove(){
		if(job.inputDirectoriesToMove == null) return 0;
		return job.inputDirectoriesToMove.numberOfPathPairs;
	}//getNumberOfInputDirectoriesToMove
	
	/**
	 * Get the input directories to copy from before running the job, which is 
	 * a string array of paths. 
	 * 
	 * @return a string array of directory paths to copy from. 
	 */
	public PathPair[] getInputDirectoriesToMove(){
		if(job.inputDirectoriesToMove == null) return null;
		return job.inputDirectoriesToMove.pathPair;
	}//getInputDirectoriesToCopyFrom

	/**
	 * Set the input directories to copy from before running the job, which is 
	 * a string array of paths. 
	 * @param paths holds a string array of input directories to copy from before running the job. 
	 * @return whether the input directories to copy from are set successfully.
	 */
	public boolean setInputDirectoriesToMove(PathPair[] pathPairs){
		if(job.inputDirectoriesToMove == null) job.inputDirectoriesToMove = new PathPairs();
		job.inputDirectoriesToMove.pathPair = pathPairs;
		int n = (pathPairs==null?0:pathPairs.length);
		job.inputDirectoriesToMove.numberOfPathPairs = n;
		return true;
	}//setInputDirectoriesToMove

	/**
	 * get the number of input files to move or copy (in <job> element)
	 * 
	 * @return the number of input file to move or copy (in <job> element)
	 */
	public int  getNumberOfInputFilesToMove(){
		if(job.inputFilesToMove == null) return 0;
		return job.inputFilesToMove.numberOfPathPairs;
	}//getNumberOfInputFilesToMove
	
	/**
	 * Get the input files to copy from before running the job, which is 
	 * a string array of paths. 
	 * 
	 * @return a string array of file paths to copy from. 
	 */
	public PathPair[] getInputFilesToMove(){
		if(job.inputFilesToMove == null) return null;
		return job.inputFilesToMove.pathPair;
	}//getInputFilesToCopyFrom

	/**
	 * Set the input files to copy from before running the job, which is 
	 * a string array of paths. 
	 * @param paths holds a string array of input files to copy from before running the job. 
	 * @return whether the input files to copy from are set successfully.
	 */
	public boolean setInputFilesToMove(PathPair[] pathPairs){
		if(job.inputFilesToMove == null) job.inputFilesToMove = new PathPairs();
		job.inputFilesToMove.pathPair = pathPairs;
		int n = (pathPairs==null?0:pathPairs.length);
		job.inputFilesToMove.numberOfPathPairs = n;
		return true;
	}//setInputFilesToMove
	
	/**
	 * get the number of output directories to move or copy (in <job> element)
	 * 
	 * @return the number of output directories to move or copy (in <job> element)
	 */
	public int  getNumberOfOutputDirectoriesToMove(){
		if(job.outputDirectoriesToMove == null) return 0;
		return job.outputDirectoriesToMove.numberOfPathPairs;
	}//getNumberOfOutputDirectoriesToMove
	
	/**
	 * Get the output directories to copy from before running the job, which is 
	 * a string array of paths. 
	 * 
	 * @return a string array of directory paths to copy from. 
	 */
	public PathPair[] getOutputDirectoriesToMove(){
		if(job.outputDirectoriesToMove == null) return null;
		return job.outputDirectoriesToMove.pathPair;
	}//getOutputDirectoriesToCopyFrom

	/**
	 * Set the output directories to copy from before running the job, which is 
	 * a string array of paths. 
	 * @param paths holds a string array of output directories to copy from before running the job. 
	 * @return whether the output directories to copy from are set successfully.
	 */
	public boolean setOutputDirectoriesToMove(PathPair[] pathPairs){
		if(job.outputDirectoriesToMove == null) job.outputDirectoriesToMove = new PathPairs();
		job.outputDirectoriesToMove.pathPair = pathPairs;
		int n = (pathPairs==null?0:pathPairs.length);
		job.outputDirectoriesToMove.numberOfPathPairs = n;
		return true;
	}//setOutputDirectoriesToMove

	/**
	 * get the number of output files to move or copy (in <job> element)
	 * 
	 * @return the number of output file to move or copy (in <job> element)
	 */
	public int  getNumberOfOutputFilesToMove(){
		if(job.outputFilesToMove == null) return 0;
		return job.outputFilesToMove.numberOfPathPairs;
	}//getNumberOfOutputFilesToMove
	
	/**
	 * Get the output files to copy from before running the job, which is 
	 * a string array of paths. 
	 * 
	 * @return a string array of file paths to copy from. 
	 */
	public PathPair[] getOutputFilesToMove(){
		if(job.outputFilesToMove == null) return null;
		return job.outputFilesToMove.pathPair;
	}//getOutputFilesToCopyFrom

	/**
	 * Set the output files to copy from before running the job, which is 
	 * a string array of paths. 
	 * @param paths holds a string array of output files to copy from before running the job. 
	 * @return whether the output files to copy from are set successfully.
	 */
	public boolean setOutputFilesToMove(PathPair[] pathPairs){
		if(job.outputFilesToMove == null) job.outputFilesToMove = new PathPairs();
		job.outputFilesToMove.pathPair = pathPairs;
		int n = (pathPairs==null?0:pathPairs.length);
		job.outputFilesToMove.numberOfPathPairs = n;
		return true;
	}//setOutputFilesToMove
	/**
	 * get the number of files to delete (in <job> element)
	 * 
	 * @return the number of files to delete (in <job> element)
	 */
	public int  getNumberOfFilesToDelete(){
		if(job.filesToDelete == null) return 0;
		return job.filesToDelete.numberOfPaths;
	}//getNumberOfFilesToDelete
	
	/**
	 * Get the files to delete after running the job, which is 
	 * a string array of paths. 
	 * 
	 * @return a string array of file paths to delete. 
	 */
	public String[] getFilesToDelete(){
		if(job.filesToDelete == null) return null;
		return job.filesToDelete.path;
	}//getFilesToDelete

	/**
	 * Set the files to delete after running the job, which is 
	 * a string array of paths. 
	 * @param paths holds a string array of file paths to delete after running the job. 
	 * @return whether the files to delete are set successfully.
	 */
	public boolean setFilesToDelete(String[] paths){
		if(job.filesToDelete == null) job.filesToDelete = new DirectoriesAndFiles();
		job.filesToDelete.path = paths;
		int n = (paths==null?0:paths.length);
		job.filesToDelete.numberOfPaths = n;
		return true;
	}//setFilesToDelete

	/**
	 * get the number of directories to delete (in <job> element)
	 * 
	 * @return the number of directories to delete (in <job> element)
	 */
	public int  getNumberOfDirectoriesToDelete(){
		if(job.directoriesToDelete == null) return 0;
		return job.directoriesToDelete.numberOfPaths;
	}//getNumberOfDirectoriesToDelete
	
	/**
	 * Get the directories to delete after running the job, which is 
	 * a string array of paths. 
	 * 
	 * @return a string array of directory paths to delete. 
	 */
	public String[] getDirectoriesToDelete(){
		if(job.directoriesToDelete == null) return null;
		return job.directoriesToDelete.path;
	}//getDirectoriesToDelete

	/**
	 * Set the directories to delete after running the job, which is 
	 * a string array of paths. 
	 * @param paths holds a string array of directory paths to delete after running the job. 
	 * @return whether the directories to delete are set successfully.
	 */
	public boolean setDirectoriesToDelete(String[] paths){
		if(job.directoriesToDelete == null) job.directoriesToDelete = new DirectoriesAndFiles();
		job.directoriesToDelete.path = paths;
		int n = (paths==null?0:paths.length);
		job.directoriesToDelete.numberOfPaths = n;
		return true;
	}//setDirectoriesToDelete

	/**
	 * get the number of processes to kill (in <job> element)
	 * 
	 * @return the number of processes to kill (in <job> element)
	 */
	public int  getNumberOfProcessesToKill(){
		if(job.processesToKill == null) return 0;
		return job.processesToKill.numberOfProcesses;
	}//getNumberOfProcessesToKill
	
	/**
	 * Get the processes to kill after running the job, which is 
	 * a string array of process names. 
	 * 
	 * @return a string array of process names to kill. 
	 */
	public String[] getProcessesToKill(){
		if(job.processesToKill == null) return null;
		return job.processesToKill.process;
	}//getProcessesToKill

	/**
	 * Set the processes to kill after running the job, which is 
	 * a string array of paths. 
	 * @param processNames holds a string array of process names to kill after running the job. 
	 * @return whether the processes to kill are set successfully.
	 */
	public boolean setProcessesToKill(String[] processNames){
		if(job.processesToKill == null) job.processesToKill = new Processes();
		job.processesToKill.process = processNames;
		int n = (processNames==null?0:processNames.length);
		job.processesToKill.numberOfProcesses = n;
		return true;
	}//setProcessesToKill
	
	/**
	 * get the number of other <job> options
	 * 
	 * @return the number of other <job> options
	 */
	public int  getNumberOfOtherJobOptions(){
		if(job.otherOptions == null) return 0;
		else return job.otherOptions.numberOfOtherOptions;
	}//getNumberOfOtherJobOptions
	
	/**
	 * Set the number of other job options. 
	 * 
	 * @param numberOfOtherJobOptions holds the number of other job options
	 * @return whether the number is set successfully or not. 
	 */
	public boolean setNumberOfOtherJobOptions(int numberOfOtherJobOptions){
		if(numberOfOtherJobOptions < 0) return false;
		if(job.otherOptions == null) job.otherOptions = new OtherOptions();
		job.otherOptions.numberOfOtherOptions = numberOfOtherJobOptions;
		return true;
	}//setNumberOfOtherJobOptions
	
	/**
	 * get the array of other <job> options
	 * 
	 * @return the array of other <job> options
	 */
	public OtherOption[] getOtherJobOptions(){
		if(job.otherOptions == null) return null;
		else return job.otherOptions.other;
	}//getOtherJobOptions
	
	
	/**
	 * set the array of other <job> options
	 * 
	 * @return  whether the other options element construction is successful.
	 */
	public boolean setOtherJobOptions(OtherOption[] other){
		if(job.otherOptions == null) job.otherOptions = new OtherOptions();
		int n = other==null?0:other.length;
		job.otherOptions.numberOfOtherOptions = n; 
		job.otherOptions.other = other;
		return true;
	}//setOtherJobOptions
	
	/**
	 * Set the other job options. 
	 * 
	 * @param names holds the names of the other options. It is required. 
	 * @param values holds the values of the other options, empty string "" or null if no value for an option.
	 * @param descriptions holds the descriptions of the other options, empty string "" or null if no value for an option, null for
	 * the entire array if none of the options have descriptions.
	 * @return whether the other options element construction is successful.
	 */
	public boolean setOtherJobOptions(String[] names, String[] values, String[] descriptions){
		if(names == null) return false;
		if(descriptions != null && descriptions.length != names.length) return false;
		if(values != null && values.length != names.length) return false;		
		
		int n = names.length;
		
		if(job.otherOptions == null) job.otherOptions = new OtherOptions();
		job.otherOptions.numberOfOtherOptions = n;
		job.otherOptions.other = new OtherOption[n];
		
		for(int i = 0; i < n; i++){
			job.otherOptions.other[i] = new OtherOption();
		}
		for(int i = 0; i < n; i++){
			job.otherOptions.other[i].name = names[i];
		}
		if(descriptions != null){
			for(int i = 0; i < n; i++){
				job.otherOptions.other[i].description = descriptions[i];
			}	
		}
		if(values != null){
			for(int i = 0; i < n; i++){
				job.otherOptions.other[i].value = values[i];
			}	
		}
		return true;
	}//setOtherJobOptions
	
	/**
	 * Get variable number. 
	 * 
	 * @return variable number, -1 if no information. 
	 */
	public int getNumberOfVariables(){
		if(m_iVariableNumber == -1){
			if(optimization == null) return -1;
			m_iVariableNumber = optimization.numberOfVariables;
		}
		return m_iVariableNumber;
	}//getNumberOfVariables

	/**
	 * Set the variable number. 
	 * 
	 * @param variableNumber holds the number of variables
	 * @return whether the variable number is set successfully or not. 
	 */
	public boolean setNumberOfVariables(int variableNumber){
		if(variableNumber < 0){
			return true;
		}
		if(optimization == null) optimization = new OptimizationOption();
		m_iVariableNumber = variableNumber;
		optimization.numberOfVariables = variableNumber;
		return true;
	}//setNumberOfVariables
	
	/**
	 * Get objective number. 
	 * 
	 * @return objective number, -1 if no information. 
	 */
	public int getNumberOfObjectives(){
		if(m_iObjectiveNumber == -1){
			if(optimization == null) return -1;
			m_iObjectiveNumber = optimization.numberOfObjectives;
		}
		return m_iObjectiveNumber;
	}//getNumberOfObjectives
	
	/**
	 * Set the objective number. 
	 * 
	 * @param objectiveNumber holds the number of objectives
	 * @return whether the objective number is set successfully or not. 
	 */
	public boolean setNumberOfObjectives(int objectiveNumber){
		if(objectiveNumber < 0){
			return true;
		}
		if(optimization == null) optimization = new OptimizationOption();
		m_iObjectiveNumber = objectiveNumber;
		optimization.numberOfObjectives = objectiveNumber;
		return true;
	}//setNumberOfObjectives
	
	/**
	 * Get constraint number. 
	 * 
	 * @return constraint number, -1 if no information. 
	 */
	public int getNumberOfConstraints(){
		if(m_iConstraintNumber == -1){
			if(optimization == null) return -1;
			m_iConstraintNumber = optimization.numberOfConstraints;
		}
		return m_iConstraintNumber;
	}//getNumberOfConstraints

	/**
	 * Set the constraint number. 
	 * 
	 * @param constraintNumber holds the number of constraints
	 * @return whether the constraint number is set successfully or not. 
	 */
	public boolean setNumberOfConstraints(int constraintNumber){
		if(constraintNumber < 0){
			return true;
		}
		if(optimization == null) optimization = new OptimizationOption();
		m_iConstraintNumber = constraintNumber;
		optimization.numberOfConstraints = constraintNumber;
		return true;
	}//setNumberOfConstraints
	

	/**
	 * get the numer of variables that have initial values (in <optimization> element)
	 * @return the numer of variables that have initial values (in <optimization> element)
	 */
	public int getNumberOfInitVarValues(){
		if(optimization == null) return 0;
		if(optimization.variables == null) return 0;
		if(optimization.variables.initialVariableValues == null) return 0;
		return optimization.variables.initialVariableValues.numberOfVar;
	}//getNumberOfInitVarValues
	
	/**
	 * get initial variable values (double[]). 
	 * @return a double array of the initial variable values, null if none. 
	 */
	public double[] getInitVarValuesDense(){
		if(optimization == null) return null;
		int iNumberOfVariables = this.getNumberOfVariables();
		if(iNumberOfVariables <= 0) return null;
		if(optimization.variables == null) return null;
		if(optimization.variables.initialVariableValues == null) return null;
		InitVarValue[] var = optimization.variables.initialVariableValues.var; 
		int iVars = (var==null)?0:var.length;
		double[] mdValues = new double[iNumberOfVariables];
		for(int i = 0; i < iVars; i++){
			mdValues[var[i].idx] = var[i].value;
		}
		return mdValues;		
	}//getInitVarValuesDense
	
	/**
	 * Set initial variable values (double[]). 
	 * Before this method is called, the setVariable(int), setObjective(int), setConstraint(int)
	 * methods are recommended  to be called first. 
	 * @param initialVariableValues holds a double array of initial variable values. 
	 * @return whether the initial variable values are set successfully or not. 
	 */
	public boolean setInitVarValuesDense(double[] initialVariableValues){
		int iNumberOfVariables = this.getNumberOfVariables();
		if(iNumberOfVariables <= 0) return true;
		if(initialVariableValues != null && initialVariableValues.length != iNumberOfVariables) return false;
		if(optimization == null) optimization = new OptimizationOption();
		if(optimization.variables == null){
			optimization.variables = new VariableOption();
		}
		if(optimization.variables.initialVariableValues == null){
			optimization.variables.initialVariableValues = new InitialVariableValues();
		}
		if(initialVariableValues == null){
			optimization.variables.initialVariableValues.var = null;
			return true;
		}
		int iVars = 0;
		for(int i = 0; i < initialVariableValues.length; i++){
			if(initialVariableValues[i] != 0) iVars++;
		}
		optimization.variables.initialVariableValues.numberOfVar = iVars;
		optimization.variables.initialVariableValues.var = new InitVarValue[iVars];
		InitVarValue[] var = optimization.variables.initialVariableValues.var;
		for(int i = 0; i < iVars; i++) var[i] = new InitVarValue();
		int j = 0;
		for(int i = 0; i < initialVariableValues.length; i++){
			if(initialVariableValues[i] != 0){
				var[j].idx = i;
				var[j].value = initialVariableValues[i];
				j++;
			}
		}
		return true; 
	}//setInitVarValuesDense

	/**
	 * get the list of initial variable values in sparse form
	 * @return a list of index/value pairs.
	 */
	public InitVarValue[] getInitVarValuesSparse(){
		if(optimization == null) return null;
		if(optimization.variables == null) return null;
		if(optimization.variables.initialVariableValues == null) return null;
		return optimization.variables.initialVariableValues.var; 
	}//getInitVarValuesSparse
	
	/**
	 * Set initial variable values (InitVarValue[]). 
	 * Before this method is called, the setVariable(int), setObjective(int), setConstraint(int)
	 * methods are recommended  to be called first. 
	 * @param initialVariableValues holds the initial variable values in sparse form (InitVarValue[]). 
	 * @return whether the initial variable values are set successfully or not. 
	 */
	public boolean setInitVarValuesSparse(InitVarValue[] initialVariableValues){
		if(optimization == null) optimization = new OptimizationOption();
		if(optimization.variables == null) optimization.variables = new VariableOption();
		if(optimization.variables.initialVariableValues == null) optimization.variables.initialVariableValues = new InitialVariableValues();
		if(initialVariableValues == null)optimization.variables.initialVariableValues.var = null;
		else optimization.variables.initialVariableValues.var = initialVariableValues;
		int n = initialVariableValues==null?0:initialVariableValues.length;
		optimization.variables.initialVariableValues.numberOfVar = n;
		return true;
	}//setInitVarValuesSparse
	
	/**
	 * get the number of other solver options (in <optimization> element)
	 * @return the number of other solver options (in <optimization> element)
	 */
	public int getNumberOfSolverOptions(){
		if(optimization == null) return 0;
		if(optimization.solverOptions == null) return 0;
		return optimization.solverOptions.numberOfSolverOptions;
	}//getNumberOfSolverOptions
	
	/**
	 * Set the number of other solver options. 
	 * 
	 * @param numberOfOtherSolverOptions holds the number of other solver options
	 * @return whether the number is set successfully or not. 
	 */
	public boolean setNumberOfSolverOptions(int numberOfSolverOptions){
		if(numberOfSolverOptions < 0) return false;
		if(optimization == null) optimization = new OptimizationOption();
		if(optimization.solverOptions == null) optimization.solverOptions = new SolverOptions();
		optimization.solverOptions.numberOfSolverOptions = numberOfSolverOptions;
		return true;
	}//setNumberOfSolverOptions

	
	/**
	 * get the array of solver options associated with a particular solver
	 * @param solver_name is the name of the solver
	 * 
	 * @return an array of solver options associated with this solver
	 */
	public SolverOption[] getSolverOptions(){
		if(optimization == null) return null;
		if(optimization.solverOptions == null) return null;
		return optimization.solverOptions.solverOption;
	}//getSolverOptions
	

	
	public boolean setSolverOptions(SolverOption[] solverOptions){
		if(optimization == null) optimization = new OptimizationOption();
		if(optimization.solverOptions == null) optimization.solverOptions = new SolverOptions();
		if(solverOptions == null)optimization.solverOptions.solverOption = null;
		else optimization.solverOptions.solverOption = solverOptions;
		int n = solverOptions==null?0:solverOptions.length;
		optimization.solverOptions.numberOfSolverOptions = n;
		return true;
	}//setSolverOptions
	
	/**
	 * Set the solver options. 
	 * 
	 * @param names holds the names of the solver options. It is required. 
	 * @param values holds the values of the solver options, empty string "" or null if no value for an option.
	 * @param descriptions holds the descriptions of the solver options, empty string "" or null if no value for an option, null for
	 * the entire array if none of the options have descriptions.
	 * @param solvers holds the solvers of the solver options, empty string "" or null if no value for an option, null for
	 * the entire array if none of the options have solvers.
	 * @param categories holds the categories of the solver options, empty string "" or null if no value for an option, null for
	 * the entire array if none of the options have categories.
	 * @param types holds the types of the solver options, empty string "" or null if no value for an option, null for
	 * the entire array if none of the options have types.
	 * @return whether the solver options element construction is successful.
	 */
	public boolean setSolverOptions(String[] names, String[] values, String[] descriptions, String[] solvers, String[] categories, String[] types){
		if(names == null) return false;
		if(descriptions != null && descriptions.length != names.length) return false;
		if(values != null && values.length != names.length) return false;		
		if(solvers != null && solvers.length != names.length) return false;		
		if(categories != null && categories.length != names.length) return false;		
		if(types != null && types.length != names.length) return false;		
		
		int n = names.length;
		
		if(optimization == null) optimization = new OptimizationOption();
		if(optimization.solverOptions == null) optimization.solverOptions = new SolverOptions();
		optimization.solverOptions.solverOption = new SolverOption[n];
		for(int i = 0; i < n; i++){
			optimization.solverOptions.solverOption[i] = new SolverOption();
		}
		for(int i = 0; i < n; i++){
			optimization.solverOptions.solverOption[i].name = names[i];
		}
		if(descriptions != null){
			for(int i = 0; i < n; i++){
				optimization.solverOptions.solverOption[i].description = descriptions[i];
			}	
		}
		if(values != null){
			for(int i = 0; i < n; i++){
				optimization.solverOptions.solverOption[i].value = values[i];
			}	
		}
		if(solvers != null){
			for(int i = 0; i < n; i++){
				optimization.solverOptions.solverOption[i].value = solvers[i];
			}	
		}
		if(categories != null){
			for(int i = 0; i < n; i++){
				optimization.solverOptions.solverOption[i].category = categories[i];
			}	
		}
		if(types != null){
			for(int i = 0; i < n; i++){
				optimization.solverOptions.solverOption[i].type = types[i];
			}	
		}
		return true;
	}//setSolverOptions

	
	/**
	 * main for test purposes.
	 *
	 * </p>
	 *
	 * @param argv command line arguments.
	 */
	public static void main(String[] args){

	}//main
	
}//class OSOption
