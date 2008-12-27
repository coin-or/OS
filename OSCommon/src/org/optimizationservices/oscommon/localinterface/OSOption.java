/**
 * @(#)OSOption 1.0 03/14/2005
 *
 * Copyright (c) 2005 
 */
package org.optimizationservices.oscommon.localinterface;

import java.util.GregorianCalendar;

import org.optimizationservices.oscommon.datastructure.osgeneral.DirectoriesAndFiles;
import org.optimizationservices.oscommon.datastructure.osgeneral.JobDependencies;
import org.optimizationservices.oscommon.datastructure.osgeneral.Processes;
import org.optimizationservices.oscommon.datastructure.osoption.BranchingWeight;
import org.optimizationservices.oscommon.datastructure.osoption.ConstraintOption;
import org.optimizationservices.oscommon.datastructure.osoption.ContactOption;
import org.optimizationservices.oscommon.datastructure.osoption.GeneralOption;
import org.optimizationservices.oscommon.datastructure.osoption.InitBasStatus;
import org.optimizationservices.oscommon.datastructure.osoption.InitConValue;
import org.optimizationservices.oscommon.datastructure.osoption.InitDualVarValue;
import org.optimizationservices.oscommon.datastructure.osoption.InitObjBound;
import org.optimizationservices.oscommon.datastructure.osoption.InitObjValue;
import org.optimizationservices.oscommon.datastructure.osoption.InitVarValue;
import org.optimizationservices.oscommon.datastructure.osoption.InitVarValueString;
import org.optimizationservices.oscommon.datastructure.osoption.InitialBasisStatus;
import org.optimizationservices.oscommon.datastructure.osoption.InitialConstraintValues;
import org.optimizationservices.oscommon.datastructure.osoption.InitialDualVariableValues;
import org.optimizationservices.oscommon.datastructure.osoption.InitialObjectiveBounds;
import org.optimizationservices.oscommon.datastructure.osoption.InitialObjectiveValues;
import org.optimizationservices.oscommon.datastructure.osoption.InitialVariableValues;
import org.optimizationservices.oscommon.datastructure.osoption.InitialVariableValuesString;
import org.optimizationservices.oscommon.datastructure.osoption.InstanceLocationOption;
import org.optimizationservices.oscommon.datastructure.osoption.IntegerVariableBranchingWeights;
import org.optimizationservices.oscommon.datastructure.osoption.JobOption;
import org.optimizationservices.oscommon.datastructure.osoption.ObjectiveOption;
import org.optimizationservices.oscommon.datastructure.osoption.OptimizationOption;
import org.optimizationservices.oscommon.datastructure.osoption.OtherConOption;
import org.optimizationservices.oscommon.datastructure.osoption.OtherConstraintOption;
import org.optimizationservices.oscommon.datastructure.osoption.OtherObjOption;
import org.optimizationservices.oscommon.datastructure.osoption.OtherObjectiveOption;
import org.optimizationservices.oscommon.datastructure.osoption.OtherOption;
import org.optimizationservices.oscommon.datastructure.osoption.OtherOptions;
import org.optimizationservices.oscommon.datastructure.osoption.OtherVarOption;
import org.optimizationservices.oscommon.datastructure.osoption.OtherVariableOption;
import org.optimizationservices.oscommon.datastructure.osoption.PathPair;
import org.optimizationservices.oscommon.datastructure.osoption.PathPairs;
import org.optimizationservices.oscommon.datastructure.osoption.SOSVariableBranchingWeights;
import org.optimizationservices.oscommon.datastructure.osoption.SOSWeights;
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
	 * Add an other general option element. 
	 * 
	 * @param name holds the name of the other option element. It is required.
	 * @param value holds the value of the other option element, empty string "" or null if none. 
	 * @param description holds the description of the other option element, empty string "" or null if none. 
	 * @return whether the other option element is added successfully.
	 */
	public boolean addOtherGeneralOption(String name, String value, String description){
		if(name == null || name.length() <= 0) return false;		
		if(general.otherOptions == null) general.otherOptions = new OtherOptions();

		int n = general.otherOptions.other==null?0:general.otherOptions.other.length;
		boolean bAdd = true;
		for(int i = 0; i < n; i++){
			OtherOption other = general.otherOptions.other[i];
			if(other.name != null && other.name.equals(name)){
				other.value = value;
				other.description = description;
				bAdd = false;
				break;
			}
		}
		if(bAdd){
			n++;
			OtherOption[] mOthers = new OtherOption[n];
			for(int i = 0; i < n-1; i++){
				mOthers[i].name = general.otherOptions.other[i].name;
				mOthers[i].value = general.otherOptions.other[i].value;
				mOthers[i].description = general.otherOptions.other[i].description;
			}
			mOthers[n-1].name = name;
			mOthers[n-1].value = value;
			mOthers[n-1].description = description;
			general.otherOptions.other = mOthers;
		}
		general.otherOptions.numberOfOtherOptions = n;
		return true;

	}//addOtherGeneralOption

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
	 * Add an other system option element. 
	 * 
	 * @param name holds the name of the other option element. It is required.
	 * @param value holds the value of the other option element, empty string "" or null if none. 
	 * @param description holds the description of the other option element, empty string "" or null if none. 
	 * @return whether the other option element is added successfully.
	 */
	public boolean addOtherSystemOption(String name, String value, String description){
		if(name == null || name.length() <= 0) return false;		
		if(system.otherOptions == null) system.otherOptions = new OtherOptions();

		int n = system.otherOptions.other==null?0:system.otherOptions.other.length;
		boolean bAdd = true;
		for(int i = 0; i < n; i++){
			OtherOption other = system.otherOptions.other[i];
			if(other.name != null && other.name.equals(name)){
				other.value = value;
				other.description = description;
				bAdd = false;
				break;
			}
		}
		if(bAdd){
			n++;
			OtherOption[] mOthers = new OtherOption[n];
			for(int i = 0; i < n-1; i++){
				mOthers[i].name = system.otherOptions.other[i].name;
				mOthers[i].value = system.otherOptions.other[i].value;
				mOthers[i].description = system.otherOptions.other[i].description;
			}
			mOthers[n-1].name = name;
			mOthers[n-1].value = value;
			mOthers[n-1].description = description;
			system.otherOptions.other = mOthers;
		}
		system.otherOptions.numberOfOtherOptions = n;
		return true;

	}//addOtherSystemOption

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
	 * Add an other service option element. 
	 * 
	 * @param name holds the name of the other option element. It is required.
	 * @param value holds the value of the other option element, empty string "" or null if none. 
	 * @param description holds the description of the other option element, empty string "" or null if none. 
	 * @return whether the other option element is added successfully.
	 */
	public boolean addOtherServiceOption(String name, String value, String description){
		if(name == null || name.length() <= 0) return false;		
		if(service.otherOptions == null) service.otherOptions = new OtherOptions();

		int n = service.otherOptions.other==null?0:service.otherOptions.other.length;
		boolean bAdd = true;
		for(int i = 0; i < n; i++){
			OtherOption other = service.otherOptions.other[i];
			if(other.name != null && other.name.equals(name)){
				other.value = value;
				other.description = description;
				bAdd = false;
				break;
			}
		}
		if(bAdd){
			n++;
			OtherOption[] mOthers = new OtherOption[n];
			for(int i = 0; i < n-1; i++){
				mOthers[i].name = service.otherOptions.other[i].name;
				mOthers[i].value = service.otherOptions.other[i].value;
				mOthers[i].description = service.otherOptions.other[i].description;
			}
			mOthers[n-1].name = name;
			mOthers[n-1].value = value;
			mOthers[n-1].description = description;
			service.otherOptions.other = mOthers;
		}
		service.otherOptions.numberOfOtherOptions = n;
		return true;

	}//addOtherServiceOption

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
	 * Add an other job option element. 
	 * 
	 * @param name holds the name of the other option element. It is required.
	 * @param value holds the value of the other option element, empty string "" or null if none. 
	 * @param description holds the description of the other option element, empty string "" or null if none. 
	 * @return whether the other option element is added successfully.
	 */
	public boolean addOtherJobOption(String name, String value, String description){
		if(name == null || name.length() <= 0) return false;		
		if(job.otherOptions == null) job.otherOptions = new OtherOptions();

		int n = job.otherOptions.other==null?0:job.otherOptions.other.length;
		boolean bAdd = true;
		for(int i = 0; i < n; i++){
			OtherOption other = job.otherOptions.other[i];
			if(other.name != null && other.name.equals(name)){
				other.value = value;
				other.description = description;
				bAdd = false;
				break;
			}
		}
		if(bAdd){
			n++;
			OtherOption[] mOthers = new OtherOption[n];
			for(int i = 0; i < n-1; i++){
				mOthers[i].name = job.otherOptions.other[i].name;
				mOthers[i].value = job.otherOptions.other[i].value;
				mOthers[i].description = job.otherOptions.other[i].description;
			}
			mOthers[n-1].name = name;
			mOthers[n-1].value = value;
			mOthers[n-1].description = description;
			job.otherOptions.other = mOthers;
		}
		job.otherOptions.numberOfOtherOptions = n;
		return true;

	}//addOtherJobOption

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
	 * get the number of string-valued variables that have initial values (in <optimization> element)
	 * @return the number of string-valued variables that have initial values (in <optimization> element)
	 */
	public int getNumberOfInitVarValuesString(){
		if(optimization == null) return 0;
		if(optimization.variables == null) return 0;
		if(optimization.variables.initialVariableValuesString == null) return 0;
		return optimization.variables.initialVariableValuesString.numberOfVar;
	}//getNumberOfInitVarValues

	/**
	 * get the list of initial values for string-valued variables in dense form
	 * @return an array of value strings
	 *  @note return the null string for variables that are not initialed
	 */
	public String[] getInitVarStringsDense(){
		if(optimization == null) return null;
		int iNumberOfVariables = this.getNumberOfVariables();
		if(iNumberOfVariables <= 0) return null;
		if(optimization.variables == null) return null;
		if(optimization.variables.initialVariableValuesString == null) return null;
		InitVarValueString[] var = optimization.variables.initialVariableValuesString.var; 
		int iVars = (var==null)?0:var.length;
		String[] msValues = new String[iNumberOfVariables];
		for(int i = 0; i < iVars; i++){
			msValues[var[i].idx] = var[i].value;
		}
		return msValues;		
	}//getInitVarStringsDense

	/**
	 * Set initial variable values (string[]). 
	 * Before this method is called, the setVariable(int), setObjective(int), setConstraint(int)
	 * methods are recommended  to be called first. 
	 * @param initialVariableValues holds a double array of initial variable values. 
	 * @return whether the initial variable values string are set successfully or not. 
	 */
	public boolean setInitVarValuesStringDense(String[] initialVariableValuesString){
		int iNumberOfVariables = this.getNumberOfVariables();
		if(iNumberOfVariables <= 0) return true;
		if(initialVariableValuesString != null && initialVariableValuesString.length != iNumberOfVariables) return false;
		if(optimization == null) optimization = new OptimizationOption();
		if(optimization.variables == null){
			optimization.variables = new VariableOption();
		}
		if(optimization.variables.initialVariableValuesString == null){
			optimization.variables.initialVariableValuesString = new InitialVariableValuesString();
		}
		if(initialVariableValuesString == null){
			optimization.variables.initialVariableValuesString.var = null;
			return true;
		}
		int iVars = 0;
		for(int i = 0; i < initialVariableValuesString.length; i++){
			if(initialVariableValuesString[i] != null && initialVariableValuesString.length >0) iVars++;
		}
		optimization.variables.initialVariableValuesString.numberOfVar = iVars;
		optimization.variables.initialVariableValuesString.var = new InitVarValueString[iVars];
		InitVarValueString[] var = optimization.variables.initialVariableValuesString.var;
		for(int i = 0; i < iVars; i++) var[i] = new InitVarValueString();
		int j = 0;
		for(int i = 0; i < initialVariableValuesString.length; i++){
			if(initialVariableValuesString[i] != null && initialVariableValuesString.length >0){
				var[j].idx = i;
				var[j].value = initialVariableValuesString[i];
				j++;
			}
		}
		return true; 
	}//initialVariableValuesString

	/**
	 * get the list of initial values for string-valued variables in sparse form
	 * @return a list of index/value pairs
	 */
	public InitVarValueString[] getInitVarStringsSparse(){
		if(optimization == null) return null;
		if(optimization.variables == null) return null;
		if(optimization.variables.initialVariableValuesString == null) return null;
		return optimization.variables.initialVariableValuesString.var; 
	}//getInitVarStringsSparses

	/**
	 * Set initial variable values (InitVarValueString[]). 
	 * Before this method is called, the setVariable(int), setObjective(int), setConstraint(int)
	 * methods are recommended  to be called first. 
	 * @param initialVariableValues holds the initial variable values in sparse form (InitVarValue[]). 
	 * @return whether the initial variable values string are set successfully or not. 
	 */
	public boolean setInitVarValuesStringSparse(InitVarValueString[] initialVariableValuesString){
		if(optimization == null) optimization = new OptimizationOption();
		if(optimization.variables == null) optimization.variables = new VariableOption();
		if(optimization.variables.initialVariableValuesString == null) optimization.variables.initialVariableValuesString = new InitialVariableValuesString();
		if(initialVariableValuesString == null)optimization.variables.initialVariableValues.var = null;
		else optimization.variables.initialVariableValuesString.var = initialVariableValuesString;
		int n = initialVariableValuesString==null?0:initialVariableValuesString.length;
		optimization.variables.initialVariableValuesString.numberOfVar = n;
		return true;
	}//setInitVarValuesStringSparse

	/**
	 * get the number of variables that are given initial basis status (in <optimization> element)
	 * @return the number of variables that are given initial basis status (in <optimization> element)
	 */
	public int getNumberOfInitialBasisVariables(){
		if(optimization == null) return 0;
		if(optimization.variables == null) return 0;
		if(optimization.variables.initialBasisStatus == null) return 0;
		return optimization.variables.initialBasisStatus.numberOfVar;
	}//getNumberOfInitialBasisVariables

	/**
	 * get the list of initial basis status for string-valued variables in dense form
	 * @return an array of value strings
	 */
	public String[] getInitBasisStatusDense(){
		if(optimization == null) return null;
		int iNumberOfVariables = this.getNumberOfVariables();
		if(iNumberOfVariables <= 0) return null;
		if(optimization.variables == null) return null;
		if(optimization.variables.initialBasisStatus == null) return null;
		InitBasStatus[] var = optimization.variables.initialBasisStatus.var; 
		int iVars = (var==null)?0:var.length;
		String[] msValues = new String[iNumberOfVariables];
		for(int i = 0; i < iVars; i++){
			msValues[var[i].idx] = var[i].value;
		}
		return msValues;		
	}//getInitBasisStatusDense

	/**
	 * Set initial basis status (string[]). 
	 * Before this method is called, the setVariable(int), setObjective(int), setConstraint(int)
	 * methods are recommended  to be called first. 
	 * @param initialBasisStatus holds a string array of initial basis status. 
	 * @return whether the initial basis status are set successfully or not. 
	 */
	public boolean setInitBasisStatusDense(String[] initialBasisStatus){
		int iNumberOfVariables = this.getNumberOfVariables();
		if(iNumberOfVariables <= 0) return true;
		if(initialBasisStatus != null && initialBasisStatus.length != iNumberOfVariables) return false;
		if(optimization == null) optimization = new OptimizationOption();
		if(optimization.variables == null){
			optimization.variables = new VariableOption();
		}
		if(optimization.variables.initialBasisStatus == null){
			optimization.variables.initialBasisStatus = new InitialBasisStatus();
		}
		if(initialBasisStatus == null){
			optimization.variables.initialBasisStatus.var = null;
			return true;
		}
		int iVars = 0;
		for(int i = 0; i < initialBasisStatus.length; i++){
			if(initialBasisStatus[i] != null && initialBasisStatus.length >0) iVars++;
		}
		optimization.variables.initialBasisStatus.numberOfVar = iVars;
		optimization.variables.initialBasisStatus.var = new InitBasStatus[iVars];
		InitBasStatus[] var = optimization.variables.initialBasisStatus.var;
		for(int i = 0; i < iVars; i++) var[i] = new InitBasStatus();
		int j = 0;
		for(int i = 0; i < initialBasisStatus.length; i++){
			if(initialBasisStatus[i] != null && initialBasisStatus.length >0){
				var[j].idx = i;
				var[j].value = initialBasisStatus[i];
				j++;
			}
		}
		return true; 
	}//setInitBasisStatusDense

	/**
	 * get the list of initial variable basis status in sparse form
	 * @return a list of index/value pairs.
	 */
	public InitBasStatus[] getInitBasisStatusSparse(){
		if(optimization == null) return null;
		if(optimization.variables == null) return null;
		if(optimization.variables.initialBasisStatus == null) return null;
		return optimization.variables.initialBasisStatus.var; 
	}//getInitBasisStatusSparse

	/**
	 * Set initial basis status (InitBasStatus[]). 
	 * Before this method is called, the setVariable(int), setObjective(int), setConstraint(int)
	 * methods are recommended  to be called first. 
	 * @param initialVariableValues holds the initial basis status in sparse form (InitBasStatus[]). 
	 * @return whether the initial basis status are set successfully or not. 
	 */
	public boolean setInitBasisStatusSparse(InitBasStatus[] initialBasisStatus){
		if(optimization == null) optimization = new OptimizationOption();
		if(optimization.variables == null) optimization.variables = new VariableOption();
		if(optimization.variables.initialBasisStatus == null) optimization.variables.initialBasisStatus = new InitialBasisStatus();
		if(initialBasisStatus == null)optimization.variables.initialVariableValues.var = null;
		else optimization.variables.initialBasisStatus.var = initialBasisStatus;
		int n = initialBasisStatus==null?0:initialBasisStatus.length;
		optimization.variables.initialBasisStatus.numberOfVar = n;
		return true;
	}//setInitBasisStatusSparse

	/**
	 * get the number of variables that are given integer variable selection weights (in <optimization> element)
	 * @return the number of variables that are given integer variable selection weights (in <optimization> element)
	 */
	public int getNumberOfIntegerVariableBranchingWeights(){
		if(optimization == null) return 0;
		if(optimization.variables == null) return 0;
		if(optimization.variables.integerVariableBranchingWeights == null) return 0;
		return optimization.variables.integerVariableBranchingWeights.numberOfVar;
	}//getNumberOfIntegerVariableBranchingWeights

	/**
	 * get a list of branching weights for integer variables in dense form
	 * @return an array of values
	 * @note return Double.NaN for variables that are not initialed
	 */
	public double[] getIntegerVariableBranchingWeightsDense(){
		if(optimization == null) return null;
		int iNumberOfVariables = this.getNumberOfVariables();
		if(iNumberOfVariables <= 0) return null;
		if(optimization.variables == null) return null;
		if(optimization.variables.integerVariableBranchingWeights == null) return null;
		BranchingWeight[] var = optimization.variables.integerVariableBranchingWeights.var; 
		int iVars = (var==null)?0:var.length;
		double[] mdValues = new double[iNumberOfVariables];
		for(int i = 0; i < iVars; i++){
			mdValues[var[i].idx] = var[i].value;
		}
		return mdValues;		
	}//getIntegerVariableBranchingWeightsDense

	/**
	 * Set integer variable branching weights (double[]). 
	 * Before this method is called, the setVariable(int), setObjective(int), setConstraint(int)
	 * methods are recommended  to be called first. 
	 * @param integerVariableBranchingWeights holds a double array of integer variable branching weights. 
	 * @return whether the integer variable branching weights are set successfully or not. 
	 */
	public boolean setIntegerVariableBranchingWeightsDense(double[] integerVariableBranchingWeights){
		int iNumberOfVariables = this.getNumberOfVariables();
		if(iNumberOfVariables <= 0) return true;
		if(integerVariableBranchingWeights != null && integerVariableBranchingWeights.length != iNumberOfVariables) return false;
		if(optimization == null) optimization = new OptimizationOption();
		if(optimization.variables == null){
			optimization.variables = new VariableOption();
		}
		if(optimization.variables.integerVariableBranchingWeights == null){
			optimization.variables.integerVariableBranchingWeights = new IntegerVariableBranchingWeights();
		}
		if(integerVariableBranchingWeights == null){
			optimization.variables.integerVariableBranchingWeights.var = null;
			return true;
		}
		int iVars = 0;
		for(int i = 0; i < integerVariableBranchingWeights.length; i++){
			if(integerVariableBranchingWeights[i] != 0) iVars++;
		}
		optimization.variables.integerVariableBranchingWeights.numberOfVar = iVars;
		optimization.variables.integerVariableBranchingWeights.var = new BranchingWeight[iVars];
		BranchingWeight[] var = optimization.variables.integerVariableBranchingWeights.var;
		for(int i = 0; i < iVars; i++) var[i] = new BranchingWeight();
		int j = 0;
		for(int i = 0; i < integerVariableBranchingWeights.length; i++){
			if(integerVariableBranchingWeights[i] != 0){
				var[j].idx = i;
				var[j].value = integerVariableBranchingWeights[i];
				j++;
			}
		}
		return true; 
	}//setIntegerVariableBranchingWeightsDense

	/**
	 * get a list of branching weights for integer variables in sparse form
	 * @return a list of index/value pairs
	 */
	public BranchingWeight[] getIntegerVariableBranchingWeightsSparse(){
		if(optimization == null) return null;
		if(optimization.variables == null) return null;
		if(optimization.variables.integerVariableBranchingWeights == null) return null;
		return optimization.variables.integerVariableBranchingWeights.var; 
	}//getIntegerVariableBranchingWeightsSparse

	/**
	 * Set  integer variable branching weights  (InitBasStatus[]). 
	 * Before this method is called, the setVariable(int), setObjective(int), setConstraint(int)
	 * methods are recommended  to be called first. 
	 * @param integerVariableBranchingWeights holds integer variable branching weights in sparse form (BranchingWeight[]). 
	 * @return whether the integer variable branching weights are set successfully or not. 
	 */
	public boolean setIntegerVariableBranchingWeightsSparse(BranchingWeight[] integerVariableBranchingWeights){
		if(optimization == null) optimization = new OptimizationOption();
		if(optimization.variables == null) optimization.variables = new VariableOption();
		if(optimization.variables.integerVariableBranchingWeights == null) optimization.variables.integerVariableBranchingWeights = new IntegerVariableBranchingWeights();
		if(integerVariableBranchingWeights == null)optimization.variables.integerVariableBranchingWeights.var = null;
		else optimization.variables.integerVariableBranchingWeights.var = integerVariableBranchingWeights;
		int n = integerVariableBranchingWeights==null?0:integerVariableBranchingWeights.length;
		optimization.variables.integerVariableBranchingWeights.numberOfVar = n;
		return true;
	}//setIntegerVariableBranchingWeightsSparse

	/**
	 * get the number of SOS that are given branching weights (in <optimization> element)
	 * @return the number of SOS that are given branching weights (in <optimization> element)
	 */
	public int getNumberOfSOSWeights(){
		if(optimization == null) return 0;
		if(optimization.variables == null) return 0;
		if(optimization.variables.sosVariableBranchingWeights == null) return 0;
		return optimization.variables.sosVariableBranchingWeights.numberOfSOS;
	}//getNumberOfSOSWeights

	/**
	 * get an array of SOS branching weights (in <optimization> element)
	 * @return an array of SOS branching weights (in <optimization> element)
	 */
	public SOSWeights[] getSOSWeights(){
		if(optimization == null) return null;
		if(optimization.variables == null) return null;
		if(optimization.variables.sosVariableBranchingWeights == null) return null;
		return optimization.variables.sosVariableBranchingWeights.sos; 
	}//getSOSWeights

	/**
	 * get the number of variables that are given integer branching weights (in <optimization> element)
	 * 
	 * @param idx
	 * return the number of variables that are given integer branching weights (in <optimization> element)
	 */
	public int getNumberOfSOSVarBranchingWeights(int idx){
		if(idx < 0 || idx >= this.getNumberOfSOSWeights()){
			return -1;
		}
		if(optimization == null) return -1;
		if(optimization.variables == null) return -1;
		if(optimization.variables.sosVariableBranchingWeights == null) return -1;
		if(optimization.variables.sosVariableBranchingWeights.sos[idx] == null) return -1; 
		return optimization.variables.sosVariableBranchingWeights.sos[idx].numberOfVar;
	}//getNumberOfSOSVarBranchingWeights

	/**
	 * get the SOS branching weights for one SOS given an index (in <optimization> element)
	 * 
	 * @param idx
	 * @return the SOS branching weights for one SOS given an index (in <optimization> element)
	 */
	public SOSWeights getSOSVarBranchingWeights(int idx){
		if(idx < 0 || idx >= this.getNumberOfSOSWeights()){
			return null;
		}
		if(optimization == null) return null;
		if(optimization.variables == null) return null;
		if(optimization.variables.sosVariableBranchingWeights == null) return null;
		if(optimization.variables.sosVariableBranchingWeights.sos[idx] == null) return null; 
		return optimization.variables.sosVariableBranchingWeights.sos[idx];
	}//getSOSVarBranchingWeights


	/**
	 * add variable branching weights for one SOS  (InitBasStatus[]). 
	 * Before this method is called, the setVariable(int), setObjective(int), setConstraint(int)
	 * methods are recommended  to be called first.
	 * @param sosIdx
	 * @param groupWeight
	 * @param branchingWeights holds sos branching weights in sparse form (BranchingWeight[]). 
	 * @return whether the sos branching weights are set successfully or not. 
	 */
	public boolean addSOSVariableBranchingWeightsForOneSOS(int sosIdx, double groupWeight, BranchingWeight[] branchingWeights){
		if(branchingWeights == null || branchingWeights.length <= 0 || sosIdx <0){
			return false;
		}
		if(optimization == null) optimization = new OptimizationOption();
		if(optimization.variables == null) optimization.variables = new VariableOption();
		if(optimization.variables.sosVariableBranchingWeights == null) optimization.variables.sosVariableBranchingWeights = new SOSVariableBranchingWeights();

		SOSVariableBranchingWeights sosRoot = optimization.variables.sosVariableBranchingWeights;

		int nVar = branchingWeights==null?0:branchingWeights.length;
		int nSOS = sosRoot.sos==null?0: sosRoot.sos.length;
		boolean bAdd = true;
		for(int i = 0; i < nSOS; i++){
			SOSWeights sosWeights = sosRoot.sos[i];
			if(sosWeights.sosIdx == sosIdx){
				sosWeights.groupWeight = groupWeight;
				sosWeights.numberOfVar = nVar;
				sosWeights.var = branchingWeights;
				bAdd = false;
				break;
			}
		}
		if(bAdd){
			nSOS++;
			SOSWeights[] mSOSWeights = new SOSWeights[nSOS];
			for(int i = 0; i < nSOS-1; i++){
				mSOSWeights[i] = sosRoot.sos[i];
			}
			mSOSWeights[nSOS-1] = new SOSWeights();
			mSOSWeights[nSOS-1].sosIdx = sosIdx;
			mSOSWeights[nSOS-1].numberOfVar = nVar;
			mSOSWeights[nSOS-1].groupWeight = groupWeight;
			mSOSWeights[nSOS-1].var = branchingWeights;
			sosRoot.sos = mSOSWeights;
		}
		sosRoot.numberOfSOS = nSOS;
		return true;		
	}//	addSOSVariableBranchingWeightsForOneSOS

	/**
	 * get the number of other variable options (in <optimization> element)
	 * @return the number of other variable options (in <optimization> element)
	 */
	public int getNumberOfOtherVariableOptions(){
		if(optimization == null) return -1;
		if(optimization.variables == null) return -1;
		return optimization.variables.numberOfOtherVariableOptions;
	}//getNumberOfOtherVariableOptions

	/**
	 * get a list of other variable options
	 * @return an array of other variable options
	 */
	public OtherVariableOption[] getOtherVariableOptions(String solverName){
		if(optimization == null) return null;
		if(optimization.variables == null) return null;
		if(solverName == null || solverName.length() <= 0) return optimization.variables.other; 
		int n = optimization.variables.other == null?0:optimization.variables.other.length;
		int iCount = 0;
		for(int i = 0; i < n; i++){
			if(solverName.equals(optimization.variables.other[i].name)) iCount++;
		}
		if(iCount == 0) return null;
		OtherVariableOption[] other = new OtherVariableOption[iCount];
		for(int i = 0; i < n; i++){
			if(solverName.equals(optimization.variables.other[i].name)){
				other[i]=optimization.variables.other[i];
			}
		}
		return other;
	}//getOtherVariableOptions

	/**
	 * Set the number of other variable options. 
	 * 
	 * @param numberOfOtherVariableOptions holds the number of other variable options
	 * @return whether the number is set successfully or not. 
	 */
	public boolean setNumberOfOtherVariableOptions(int numberOfOtherVariableOptions){
		if(numberOfOtherVariableOptions < 0) return false;
		if(optimization == null) optimization = new OptimizationOption();
		if(optimization.variables == null) optimization.variables  = new VariableOption();
		optimization.variables.numberOfOtherVariableOptions = numberOfOtherVariableOptions;
		return true;
	}//setNumberOfOtherVariableOptions

	/**
	 * Add another variable option element. 
	 * 
	 * @param name holds the name of the option element. It is required.
	 * @param value holds the value of the option element, empty string "" or null if none. 
	 * @param description holds the description of the option element, empty string "" or null if none. 
	 * @param solver holds the solver of the option element, empty string "" or null if no value. 
	 * @param category holds the category of the option element, empty string "" or null if no value. 
	 * @param type holds the type of the option element, empty string "" or null if no value. 
	 * @param vars holds an array of var options
	 * @return whether the other variable option element is added successfully.
	 */
	public boolean addOtherVariableOption(String name, String value, String description, String solver, String category, String type, OtherVarOption[] vars){
		if(name == null || name.length() <= 0) return false;		
		if(optimization == null) optimization = new OptimizationOption();
		if(optimization.variables == null) optimization.variables = new VariableOption();

		int n = optimization.variables.other==null?0:optimization.variables.other.length;
		boolean bAdd = true;
		int nVar = vars==null?0:vars.length;
		for(int i = 0; i < n; i++){
			OtherVariableOption otherOption = optimization.variables.other[i];
			if(otherOption.name != null && otherOption.name.equals(name)){
				otherOption.value = value;
				otherOption.description = description;
				otherOption.solver = solver;
				otherOption.category = category;
				otherOption.type = type;
				otherOption.numberOfVar = nVar;
				otherOption.var = vars;
				bAdd = false;
				break;
			}
		}
		if(bAdd){
			n++;
			OtherVariableOption[] mOtherOptions = new OtherVariableOption[n];
			for(int i = 0; i < n-1; i++){
				mOtherOptions[i] = optimization.variables.other[i];
			}
			mOtherOptions[n-1].name = name;
			mOtherOptions[n-1].value = value;
			mOtherOptions[n-1].description = description;
			mOtherOptions[n-1].solver = solver;
			mOtherOptions[n-1].category = category;
			mOtherOptions[n-1].type = type;
			mOtherOptions[n-1].numberOfVar = nVar;
			mOtherOptions[n-1].var = vars;
			optimization.variables.other = mOtherOptions;
		}
		optimization.variables.numberOfOtherVariableOptions = n;
		return true;
	}//addOtherVariableOption

	/**
	 * get the numer of objectives that have initial values (in <optimization> element)
	 * @return the numer of objectives that have initial values (in <optimization> element)
	 */
	public int getNumberOfInitObjValues(){
		if(optimization == null) return -1;
		if(optimization.objectives == null) return -1;
		if(optimization.objectives.initialObjectiveValues == null) return -1;
		return optimization.objectives.initialObjectiveValues.numberOfObj;
	}//getNumberOfInitObjValues

	/**
	 * get initial objective values (double[]). 
	 * @return a double array of the initial objective values, null if none. 
	 */
	public double[] getInitObjValuesDense(){
		if(optimization == null) return null;
		int iNumberOfObjectives = this.getNumberOfObjectives();
		if(iNumberOfObjectives <= 0) return null;
		if(optimization.objectives == null) return null;
		if(optimization.objectives.initialObjectiveValues == null) return null;
		InitObjValue[] obj = optimization.objectives.initialObjectiveValues.obj; 
		int iObjs = (obj==null)?0:obj.length;
		double[] mdValues = new double[iNumberOfObjectives];
		for(int i = 0; i < iObjs; i++){
			mdValues[Math.abs(obj[i].idx)-1] = obj[i].value;
		}
		return mdValues;		
	}//getInitObjValuesDense

	/**
	 * Set initial objective values (double[]). 
	 * Before this method is called, the setVariable(int), setObjective(int), setConstraint(int)
	 * methods are recommended  to be called first. 
	 * @param initialObjectiveValues holds a double array of initial objective values. 
	 * @return whether the initial objective values are set successfully or not. 
	 */
	public boolean setInitObjValuesDense(double[] initialObjectiveValues){
		int iNumberOfObjectives = this.getNumberOfObjectives();
		if(iNumberOfObjectives <= 0) return true;
		if(initialObjectiveValues != null && initialObjectiveValues.length != iNumberOfObjectives) return false;
		if(optimization == null) optimization = new OptimizationOption();
		if(optimization.objectives == null){
			optimization.objectives = new ObjectiveOption();
		}
		if(optimization.objectives.initialObjectiveValues == null){
			optimization.objectives.initialObjectiveValues = new InitialObjectiveValues();
		}
		if(initialObjectiveValues == null){
			optimization.objectives.initialObjectiveValues.obj = null;
			return true;
		}
		int iObjs = 0;
		for(int i = 0; i < initialObjectiveValues.length; i++){
			if(initialObjectiveValues[i] != 0) iObjs++;
		}
		optimization.objectives.initialObjectiveValues.numberOfObj = iObjs;
		optimization.objectives.initialObjectiveValues.obj = new InitObjValue[iObjs];
		InitObjValue[] obj = optimization.objectives.initialObjectiveValues.obj;
		for(int i = 0; i < iObjs; i++) obj[i] = new InitObjValue();
		int j = 0;
		for(int i = 0; i < initialObjectiveValues.length; i++){
			if(initialObjectiveValues[i] != 0){
				obj[j].idx = i;
				obj[j].value = initialObjectiveValues[i];
				j++;
			}
		}
		return true; 	
	}//setInitObjValuesDense

	/**
	 * get the list of initial objective values in sparse form
	 * @return a list of index/value pairs.
	 */
	public InitObjValue[] getInitObjValuesSparse(){
		if(optimization == null) return null;
		if(optimization.objectives == null) return null;
		if(optimization.objectives.initialObjectiveValues == null) return null;
		return optimization.objectives.initialObjectiveValues.obj; 
	}//getInitObjValuesSparse


	/**
	 * Set initial objective values (InitObjValue[]). 
	 * Before this method is called, the setVariable(int), setObjective(int), setConstraint(int)
	 * methods are recommended  to be called first. 
	 * @param initialObjectiveValues holds the initial objective values in sparse form (InitObjValue[]). 
	 * @return whether the initial objective values are set successfully or not. 
	 */
	public boolean setInitObjValuesSparse(InitObjValue[] initialObjectiveValues){
		if(optimization == null) optimization = new OptimizationOption();
		if(optimization.objectives == null) optimization.objectives = new ObjectiveOption();
		if(optimization.objectives.initialObjectiveValues == null) optimization.objectives.initialObjectiveValues = new InitialObjectiveValues();
		if(initialObjectiveValues == null)optimization.objectives.initialObjectiveValues.obj = null;
		else optimization.objectives.initialObjectiveValues.obj = initialObjectiveValues;
		int n = initialObjectiveValues==null?0:initialObjectiveValues.length;
		optimization.objectives.initialObjectiveValues.numberOfObj = n;
		return true;
	}//setInitObjValuesSparse

	/**
	 * get the numer of objectives that have initial bounds (in <optimization> element)
	 * @return the numer of objectives that have initial bounds (in <optimization> element)
	 */
	public int getNumberOfInitObjBounds(){
		if(optimization == null) return -1;
		if(optimization.objectives == null) return -1;
		if(optimization.objectives.initialObjectiveBounds == null) return -1;
		return optimization.objectives.initialObjectiveBounds.numberOfObj;
	}//getNumberOfInitObjBounds

	/**
	 * get initial objective lower bounds (double[]). 
	 * @return a double array of the initial objective lower bounds, null if none. 
	 */
	public double[] getInitObjLowerBoundsDense(){
		if(optimization == null) return null;
		int iNumberOfObjectives = this.getNumberOfObjectives();
		if(iNumberOfObjectives <= 0) return null;
		if(optimization.objectives == null) return null;
		if(optimization.objectives.initialObjectiveBounds == null) return null;
		InitObjBound[] obj = optimization.objectives.initialObjectiveBounds.obj; 
		int iObjs = (obj==null)?0:obj.length;
		double[] mdValues = new double[iNumberOfObjectives];
		for(int i = 0; i < iObjs; i++){
			mdValues[Math.abs(obj[i].idx)-1] = obj[i].lbValue;
		}
		return mdValues;		
	}//getInitObjLowerBoundsDense

	/**
	 * get initial objective uppper bounds (double[]). 
	 * @return a double array of the initial objective upper bounds, null if none. 
	 */
	public double[] getInitObjUpperBoundsDense(){
		if(optimization == null) return null;
		int iNumberOfObjectives = this.getNumberOfObjectives();
		if(iNumberOfObjectives <= 0) return null;
		if(optimization.objectives == null) return null;
		if(optimization.objectives.initialObjectiveBounds == null) return null;
		InitObjBound[] obj = optimization.objectives.initialObjectiveBounds.obj; 
		int iObjs = (obj==null)?0:obj.length;
		double[] mdValues = new double[iNumberOfObjectives];
		for(int i = 0; i < iObjs; i++){
			mdValues[Math.abs(obj[i].idx)-1] = obj[i].ubValue;
		}
		return mdValues;		
	}//getInitObjUpperBoundsDense

	/**
	 * Set initial objective bounds (double[]). 
	 * Before this method is called, the setVariable(int), setObjective(int), setConstraint(int)
	 * methods are recommended  to be called first. 
	 * @param initialObjectiveLowerBounds holds the initial objective lower bounds in sparse form (InitObjBound[]). 
	 * @param initialObjectiveUpperBounds holds the initial objective upper bounds in sparse form (InitObjBound[]). 
	 * @return whether the initial objective bounds are set successfully or not. 
	 */
	public boolean setInitObjBoundsDense(double[] initialObjectiveLowerBounds, double[] initialObjectiveUpperBounds){
		int iNumberOfObjectives = this.getNumberOfObjectives();
		if(iNumberOfObjectives <= 0) return true;
		if(initialObjectiveLowerBounds != null && initialObjectiveLowerBounds.length != iNumberOfObjectives) return false;
		if(initialObjectiveUpperBounds != null && initialObjectiveUpperBounds.length != iNumberOfObjectives) return false;
		if(optimization == null) optimization = new OptimizationOption();
		if(optimization.objectives == null){
			optimization.objectives = new ObjectiveOption();
		}
		if(optimization.objectives.initialObjectiveBounds == null){
			optimization.objectives.initialObjectiveBounds = new InitialObjectiveBounds();
		}
		if(initialObjectiveLowerBounds == null && initialObjectiveUpperBounds == null){
			optimization.objectives.initialObjectiveBounds.obj = null;
		}
		int iObjs = 0;
		int nBounds = initialObjectiveLowerBounds==null?0:initialObjectiveLowerBounds.length;
		if(nBounds == 0) nBounds = initialObjectiveUpperBounds==null?0:initialObjectiveUpperBounds.length;

		for(int i = 0; i < nBounds; i++){
			if((initialObjectiveLowerBounds != null && initialObjectiveLowerBounds[i] != 0) 
					|| (initialObjectiveUpperBounds != null && initialObjectiveUpperBounds[i] != 0)) iObjs++;
		}
		optimization.objectives.initialObjectiveBounds.numberOfObj = iObjs;
		optimization.objectives.initialObjectiveBounds.obj = new InitObjBound[iObjs];
		InitObjBound[] obj = optimization.objectives.initialObjectiveBounds.obj;
		for(int i = 0; i < iObjs; i++) obj[i] = new InitObjBound();
		int j = 0;
		for(int i = 0; i < nBounds; i++){
			if((initialObjectiveLowerBounds != null && initialObjectiveLowerBounds[i] != 0) 
					|| (initialObjectiveUpperBounds != null && initialObjectiveUpperBounds[i] != 0)) {
				obj[j].idx = i;
				obj[j].lbValue = initialObjectiveLowerBounds==null?0:initialObjectiveLowerBounds[i];
				obj[j].ubValue = initialObjectiveUpperBounds==null?0:initialObjectiveUpperBounds[i];
				j++;
			}
		}
		return true; 	
	}//setInitObjBoundsDense

	/**
	 * get the list of initial objective bounds in sparse form
	 * @return a list of index/bound pairs.
	 */
	public InitObjBound[] getInitObjBoundsSparse(){
		if(optimization == null) return null;
		if(optimization.objectives == null) return null;
		if(optimization.objectives.initialObjectiveBounds == null) return null;
		return optimization.objectives.initialObjectiveBounds.obj; 
	}//getInitObjBoundsSparse

	/**
	 * Set initial objective bounds (InitObjBound[]). 
	 * Before this method is called, the setVariable(int), setObjective(int), setConstraint(int)
	 * methods are recommended  to be called first. 
	 * @param initialObjectiveBounds holds the initial objective bounds in sparse form (InitObjBound[]). 
	 * @return whether the initial objective bounds are set successfully or not. 
	 */
	public boolean setInitObjBoundsSparse(InitObjBound[] initialObjectiveBounds){
		if(optimization == null) optimization = new OptimizationOption();
		if(optimization.objectives == null) optimization.objectives = new ObjectiveOption();
		if(optimization.objectives.initialObjectiveBounds == null) optimization.objectives.initialObjectiveBounds = new InitialObjectiveBounds();
		if(initialObjectiveBounds == null)optimization.objectives.initialObjectiveBounds.obj = null;
		else optimization.objectives.initialObjectiveBounds.obj = initialObjectiveBounds;
		int n = initialObjectiveBounds==null?0:initialObjectiveBounds.length;
		optimization.objectives.initialObjectiveBounds.numberOfObj = n;
		return true;
	}//setInitObjBoundsSparse

	/**
	 * get the number of other objective options (in <optimization> element)
	 * @return the number of other objective options (in <optimization> element)
	 */
	public int getNumberOfOtherObjectiveOptions(){
		if(optimization == null) return -1;
		if(optimization.objectives == null) return -1;
		return optimization.objectives.numberOfOtherObjectiveOptions;
	}//getNumberOfOtherObjectiveOptions

	/**
	 * Set the number of other objective options. 
	 * 
	 * @param numberOfOtherObjectiveOptions holds the number of other objective options
	 * @return whether the number is set successfully or not. 
	 */
	public boolean setNumberOfOtherObjectiveOptions(int numberOfOtherObjectiveOptions){
		if(numberOfOtherObjectiveOptions < 0) return false;
		if(optimization == null) optimization = new OptimizationOption();
		if(optimization.objectives == null) optimization.objectives  = new ObjectiveOption();
		optimization.objectives.numberOfOtherObjectiveOptions = numberOfOtherObjectiveOptions;
		return true;
	}//setNumberOfOtherObjectiveOptions

	/**
	 * get a list of other objective options
	 * @return an array of other objective options
	 */
	public OtherObjectiveOption[] getOtherObjectiveOptions(String solverName){
		if(optimization == null) return null;
		if(optimization.objectives == null) return null;
		if(solverName == null || solverName.length() <= 0) return optimization.objectives.other; 
		int n = optimization.objectives.other == null?0:optimization.objectives.other.length;
		int iCount = 0;
		for(int i = 0; i < n; i++){
			if(solverName.equals(optimization.objectives.other[i].name)) iCount++;
		}
		if(iCount == 0) return null;
		OtherObjectiveOption[] other = new OtherObjectiveOption[iCount];
		for(int i = 0; i < n; i++){
			if(solverName.equals(optimization.objectives.other[i].name)){
				other[i]=optimization.objectives.other[i];
			}
		}
		return other;
	}//getOtherObjectiveOptions

	/**
	 * Add another objective option element. 
	 * 
	 * @param name holds the name of the option element. It is required.
	 * @param value holds the value of the option element, empty string "" or null if none. 
	 * @param description holds the description of the option element, empty string "" or null if none. 
	 * @param solver holds the solver of the option element, empty string "" or null if no value. 
	 * @param category holds the category of the option element, empty string "" or null if no value. 
	 * @param type holds the type of the option element, empty string "" or null if no value. 
	 * @param objs holds an array of obj options
	 * @return whether the other objective option element is added successfully.
	 */
	public boolean addOtherObjectiveOption(String name, String value, String description, String solver, String category, String type, OtherObjOption[] objs){
		if(name == null || name.length() <= 0) return false;		
		if(optimization == null) optimization = new OptimizationOption();
		if(optimization.objectives == null) optimization.objectives = new ObjectiveOption();

		int n = optimization.objectives.other==null?0:optimization.objectives.other.length;
		boolean bAdd = true;
		int nObj = objs==null?0:objs.length;
		for(int i = 0; i < n; i++){
			OtherObjectiveOption otherOption = optimization.objectives.other[i];
			if(otherOption.name != null && otherOption.name.equals(name)){
				otherOption.value = value;
				otherOption.description = description;
				otherOption.solver = solver;
				otherOption.category = category;
				otherOption.type = type;
				otherOption.numberOfObj = nObj;
				otherOption.obj = objs;
				bAdd = false;
				break;
			}
		}
		if(bAdd){
			n++;
			OtherObjectiveOption[] mOtherOptions = new OtherObjectiveOption[n];
			for(int i = 0; i < n-1; i++){
				mOtherOptions[i] = optimization.objectives.other[i];
			}
			mOtherOptions[n-1].name = name;
			mOtherOptions[n-1].value = value;
			mOtherOptions[n-1].description = description;
			mOtherOptions[n-1].solver = solver;
			mOtherOptions[n-1].category = category;
			mOtherOptions[n-1].type = type;
			mOtherOptions[n-1].numberOfObj = nObj;
			mOtherOptions[n-1].obj = objs;
			optimization.objectives.other = mOtherOptions;
		}
		optimization.objectives.numberOfOtherObjectiveOptions = n;
		return true;	
	}//addOtherObjectiveOption

	/**
	 * get the numer of constraints that have initial values (in <optimization> element)
	 * @return the numer of constraints that have initial values (in <optimization> element)
	 */
	public int getNumberOfInitConValues(){
		if(optimization == null) return -1;
		if(optimization.constraints == null) return -1;
		if(optimization.constraints.initialConstraintValues == null) return -1;
		return optimization.constraints.initialConstraintValues.numberOfCon;

	}//getNumberOfInitConValues

	/**
	 * get initial constraint values (double[]). 
	 * @return a double array of the initial constraint values, null if none. 
	 */
	public double[] getInitConValuesDense(){
		if(optimization == null) return null;
		int iNumberOfConstraints = this.getNumberOfConstraints();
		if(iNumberOfConstraints <= 0) return null;
		if(optimization.constraints == null) return null;
		if(optimization.constraints.initialConstraintValues == null) return null;
		InitConValue[] con = optimization.constraints.initialConstraintValues.con; 
		int iCons = (con==null)?0:con.length;
		double[] mdValues = new double[iNumberOfConstraints];
		for(int i = 0; i < iCons; i++){
			mdValues[Math.abs(con[i].idx)-1] = con[i].value;
		}
		return mdValues;		
	}//getInitConValuesDense

	/**
	 * Set initial constraint values (double[]). 
	 * Before this method is called, the setVariable(int), setObjective(int), setConstraint(int)
	 * methods are recommended  to be called first. 
	 * @param initialConstraintValues holds a double array of initial constraint values. 
	 * @return whether the initial constraint values are set successfully or not. 
	 */
	public boolean setInitConValuesDense(double[] initialConstraintValues){
		int iNumberOfConstraints = this.getNumberOfConstraints();
		if(iNumberOfConstraints <= 0) return true;
		if(initialConstraintValues != null && initialConstraintValues.length != iNumberOfConstraints) return false;
		if(optimization == null) optimization = new OptimizationOption();
		if(optimization.constraints == null){
			optimization.constraints = new ConstraintOption();
		}
		if(optimization.constraints.initialConstraintValues == null){
			optimization.constraints.initialConstraintValues = new InitialConstraintValues();
		}
		if(initialConstraintValues == null){
			optimization.constraints.initialConstraintValues.con = null;
			return true;
		}
		int iCons = 0;
		for(int i = 0; i < initialConstraintValues.length; i++){
			if(initialConstraintValues[i] != 0) iCons++;
		}
		optimization.constraints.initialConstraintValues.numberOfCon = iCons;
		optimization.constraints.initialConstraintValues.con = new InitConValue[iCons];
		InitConValue[] con = optimization.constraints.initialConstraintValues.con;
		for(int i = 0; i < iCons; i++) con[i] = new InitConValue();
		int j = 0;
		for(int i = 0; i < initialConstraintValues.length; i++){
			if(initialConstraintValues[i] != 0){
				con[j].idx = i;
				con[j].value = initialConstraintValues[i];
				j++;
			}
		}
		return true; 		
	}//setInitConValuesDense

	/**
	 * get the list of initial constraint values in sparse form
	 * @return a list of index/value pairs.
	 */
	public InitConValue[] getInitConValuesSparse(){
		if(optimization == null) return null;
		if(optimization.constraints == null) return null;
		if(optimization.constraints.initialConstraintValues == null) return null;
		return optimization.constraints.initialConstraintValues.con; 
	}//getInitConValuesSparse

	/**
	 * Set initial constraint values (InitConValue[]). 
	 * Before this method is called, the setVariable(int), setConective(int), setConstraint(int)
	 * methods are recommended  to be called first. 
	 * @param initialConstraintValues holds the initial constraint values in sparse form (InitConValue[]). 
	 * @return whether the initial constraint values are set successfully or not. 
	 */
	public boolean setInitConValuesSparse(InitConValue[] initialConstraintValues){
		if(optimization == null) optimization = new OptimizationOption();
		if(optimization.constraints == null) optimization.constraints = new ConstraintOption();
		if(optimization.constraints.initialConstraintValues == null) optimization.constraints.initialConstraintValues = new InitialConstraintValues();
		if(initialConstraintValues == null)optimization.constraints.initialConstraintValues.con = null;
		else optimization.constraints.initialConstraintValues.con = initialConstraintValues;
		int n = initialConstraintValues==null?0:initialConstraintValues.length;
		optimization.constraints.initialConstraintValues.numberOfCon = n;
		return true;
	}//setInitConValuesSparse

	/**
	 * get the numer of constraints that have initial dual values (in <optimization> element)
	 * @return the numer of constraints that have initial dual values (in <optimization> element)
	 */
	public int getNumberOfInitDualVarValues(){
		if(optimization == null) return -1;
		if(optimization.constraints == null) return -1;
		if(optimization.constraints.initialDualValues == null) return -1;
		return optimization.constraints.initialDualValues.numberOfCon;
	}//getNumberOfInitDualVarValues

	/**
	 * get initial dual variable lower bounds (double[]). 
	 * @return a double array of the initial dual variable lower bounds, null if none. 
	 */
	public double[] getInitDualVarLowerBoundsDense(){
		if(optimization == null) return null;
		int iNumberOfConstraints = this.getNumberOfConstraints();
		if(iNumberOfConstraints <= 0) return null;
		if(optimization.constraints == null) return null;
		if(optimization.constraints.initialDualValues == null) return null;
		InitDualVarValue[] con = optimization.constraints.initialDualValues.con; 
		int iCons = (con==null)?0:con.length;
		double[] mdValues = new double[iNumberOfConstraints];
		for(int i = 0; i < iCons; i++){
			mdValues[con[i].idx] = con[i].lbDualValue;
		}
		return mdValues;		
	}//getInitDualVarLowerBoundsDense

	/**
	 * get initial dual variable uppper bounds (double[]). 
	 * @return a double array of the initial  dual variable upper bounds, null if none. 
	 */
	public double[] getInitDualVarUpperBoundsDense(){
		if(optimization == null) return null;
		int iNumberOfConstraints = this.getNumberOfConstraints();
		if(iNumberOfConstraints <= 0) return null;
		if(optimization.constraints == null) return null;
		if(optimization.constraints.initialDualValues == null) return null;
		InitDualVarValue[] con = optimization.constraints.initialDualValues.con; 
		int iCons = (con==null)?0:con.length;
		double[] mdValues = new double[iNumberOfConstraints];
		for(int i = 0; i < iCons; i++){
			mdValues[con[i].idx] = con[i].ubDualValue;
		}
		return mdValues;			
	}//getInitDualVarUpperBoundsDense

	/**
	 * get the list of initial dual variable values in sparse form
	 * @return a list of index/bound pairs.
	 */
	public InitDualVarValue[] getInitDualVarValuesSparse(){
		if(optimization == null) return null;
		if(optimization.constraints == null) return null;
		if(optimization.constraints.initialDualValues == null) return null;
		return optimization.constraints.initialDualValues.con; 
	}//getInitDualVarValuesSparse

	/**
	 * Set initial dual values (double[]). 
	 * Before this method is called, the setVariable(int), setObjective(int), setConstraint(int)
	 * methods are recommended  to be called first. 
	 * @param initialLbDualValues holds the initial dual value at lower bounds.
	 * @param initialUbDualValues holds the initial dual value at upper bounds. 
	 * @return whether the initial dual values are set successfully or not. 
	 */
	public boolean setInitDualValuesDense(double[]initialLbDualValues, double[] initialUbDualValues){
		int iNumberOfConstraints = this.getNumberOfConstraints();
		if(iNumberOfConstraints <= 0) return true;
		if(initialLbDualValues != null && initialLbDualValues.length != iNumberOfConstraints) return false;
		if(initialUbDualValues != null && initialUbDualValues.length != iNumberOfConstraints) return false;
		if(optimization == null) optimization = new OptimizationOption();
		if(optimization.constraints == null){
			optimization.constraints = new ConstraintOption();
		}
		if(optimization.constraints.initialDualValues == null){
			optimization.constraints.initialDualValues = new InitialDualVariableValues();
		}
		if(initialLbDualValues == null && initialUbDualValues == null){
			optimization.constraints.initialDualValues.con = null;
		}
		int iCons = 0;
		int nDuals = initialLbDualValues==null?0:initialLbDualValues.length;
		if(nDuals == 0) nDuals = initialUbDualValues==null?0:initialUbDualValues.length;

		for(int i = 0; i < nDuals; i++){
			if((initialLbDualValues != null && initialLbDualValues[i] != 0) 
					|| (initialUbDualValues != null && initialUbDualValues[i] != 0)) iCons++;
		}
		optimization.constraints.initialDualValues.numberOfCon = iCons;
		optimization.constraints.initialDualValues.con = new InitDualVarValue[iCons];
		InitDualVarValue[] con = optimization.constraints.initialDualValues.con;
		for(int i = 0; i < iCons; i++) con[i] = new InitDualVarValue();
		int j = 0;
		for(int i = 0; i < nDuals; i++){
			if((initialLbDualValues != null && initialLbDualValues[i] != 0) 
					|| (initialUbDualValues != null && initialUbDualValues[i] != 0)) {
				con[j].idx = i;
				con[j].lbDualValue = initialLbDualValues==null?0:initialLbDualValues[i];
				con[j].ubDualValue = initialUbDualValues==null?0:initialUbDualValues[i];
				j++;
			}
		}
		return true; 	
	}//setInitDualValuesDense

	/**
	 * Set initial dual values (InitDualVarValue[]). 
	 * Before this method is called, the setVariable(int), setObjective(int), setConstraint(int)
	 * methods are recommended  to be called first. 
	 * @param initialDualValues holds the initial dual values in sparse form (InitDualVarValue[]). 
	 * @return whether the initial dual values are set successfully or not. 
	 */
	public boolean setInitDualValuesSparse(InitDualVarValue[] initialDualValues){
		if(optimization == null) optimization = new OptimizationOption();
		if(optimization.constraints == null) optimization.constraints = new ConstraintOption();
		if(optimization.constraints.initialDualValues == null) optimization.constraints.initialDualValues = new InitialDualVariableValues();
		if(initialDualValues == null)optimization.constraints.initialDualValues.con = null;
		else optimization.constraints.initialDualValues.con = initialDualValues;
		int n = initialDualValues==null?0:initialDualValues.length;
		optimization.constraints.initialDualValues.numberOfCon = n;
		return true;
	}//setInitDualValuesSparse

	/**
	 * get the number of other constraint options (in <optimization> element)
	 * @return the number of other constraint options (in <optimization> element)
	 */
	public int getNumberOfOtherConstraintOptions(){
		if(optimization == null) return -1;
		if(optimization.constraints == null) return -1;
		return optimization.constraints.numberOfOtherConstraintOptions;

	}//getNumberOfOtherConstraintOptions

	/**
	 * get a list of other constraint options
	 * @return an array of other constraint options
	 */
	public OtherConstraintOption[] getOtherConstraintOptions(String solverName){
		if(optimization == null) return null;
		if(optimization.constraints == null) return null;
		if(solverName == null || solverName.length() <= 0) return optimization.constraints.other; 
		int n = optimization.constraints.other == null?0:optimization.constraints.other.length;
		int iCount = 0;
		for(int i = 0; i < n; i++){
			if(solverName.equals(optimization.constraints.other[i].name)) iCount++;
		}
		if(iCount == 0) return null;
		OtherConstraintOption[] other = new OtherConstraintOption[iCount];
		for(int i = 0; i < n; i++){
			if(solverName.equals(optimization.constraints.other[i].name)){
				other[i]=optimization.constraints.other[i];
			}
		}
		return other;
	}//getOtherConstraintOptions

	/**
	 * Set the number of other constraint options. 
	 * 
	 * @param numberOfOtherConstraintOptions holds the number of other constraint options
	 * @return whether the number is set successfully or not. 
	 */
	public boolean setNumberOfOtherConstraintOptions(int numberOfOtherConstraintOptions){
		if(numberOfOtherConstraintOptions < 0) return false;
		if(optimization == null) optimization = new OptimizationOption();
		if(optimization.constraints == null) optimization.constraints  = new ConstraintOption();
		optimization.constraints.numberOfOtherConstraintOptions = numberOfOtherConstraintOptions;
		return true;
	}//setNumberOfOtherConstraintOptions

	/**
	 * Add another constraint option element. 
	 * 
	 * @param name holds the name of the option element. It is required.
	 * @param value holds the value of the option element, empty string "" or null if none. 
	 * @param description holds the description of the option element, empty string "" or null if none. 
	 * @param solver holds the solver of the option element, empty string "" or null if no value. 
	 * @param category holds the category of the option element, empty string "" or null if no value. 
	 * @param type holds the type of the option element, empty string "" or null if no value. 
	 * @param cons holds an array of con options
	 * @return whether the other constraint option element is added successfully.
	 */
	public boolean addOtherConstraintOption(String name, String value, String description, String solver, String category, String type, OtherConOption[] cons){
		if(name == null || name.length() <= 0) return false;		
		if(optimization == null) optimization = new OptimizationOption();
		if(optimization.constraints == null) optimization.constraints = new ConstraintOption();

		int n = optimization.constraints.other==null?0:optimization.constraints.other.length;
		boolean bAdd = true;
		int nCon = cons==null?0:cons.length;
		for(int i = 0; i < n; i++){
			OtherConstraintOption otherOption = optimization.constraints.other[i];
			if(otherOption.name != null && otherOption.name.equals(name)){
				otherOption.value = value;
				otherOption.description = description;
				otherOption.solver = solver;
				otherOption.category = category;
				otherOption.type = type;
				otherOption.numberOfCon = nCon;
				otherOption.con = cons;
				bAdd = false;
				break;
			}
		}
		if(bAdd){
			n++;
			OtherConstraintOption[] mOtherOptions = new OtherConstraintOption[n];
			for(int i = 0; i < n-1; i++){
				mOtherOptions[i] = optimization.constraints.other[i];
			}
			mOtherOptions[n-1].name = name;
			mOtherOptions[n-1].value = value;
			mOtherOptions[n-1].description = description;
			mOtherOptions[n-1].solver = solver;
			mOtherOptions[n-1].category = category;
			mOtherOptions[n-1].type = type;
			mOtherOptions[n-1].numberOfCon = nCon;
			mOtherOptions[n-1].con = cons;
			optimization.constraints.other = mOtherOptions;
		}
		optimization.constraints.numberOfOtherConstraintOptions = n;
		return true;	
	}//addOtherConstraintOption


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
	 * @param solverName is the name of the solver
	 * 
	 * @return an array of solver options associated with this solver
	 */
	public SolverOption[] getSolverOptions(String solverName){
		if(optimization == null) return null;
		if(optimization.solverOptions == null) return null;
		if(solverName == null || solverName.length() <= 0) return optimization.solverOptions.solverOption; 
		int n = optimization.solverOptions.solverOption == null?0:optimization.solverOptions.solverOption.length;
		int iCount = 0;
		for(int i = 0; i < n; i++){
			if(solverName.equals(optimization.solverOptions.solverOption[i].name)) iCount++;
		}
		if(iCount == 0) return null;
		SolverOption[] solverOptions = new SolverOption[iCount];
		for(int i = 0; i < n; i++){
			if(solverName.equals(optimization.solverOptions.solverOption[i].name)){
				solverOptions[i]=optimization.solverOptions.solverOption[i];
			}
		}
		return solverOptions;
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
	 * Add a solver option element. 
	 * 
	 * @param name holds the name of the solver option element. It is required.
	 * @param value holds the value of the solver option element, empty string "" or null if none. 
	 * @param description holds the description of the solver option element, empty string "" or null if none. 
	 * @param solver holds the solver of the solverOption element, empty string "" or null if no value. 
	 * @param category holds the category of the solverOption element, empty string "" or null if no value. 
	 * @param type holds the type of the solverOption element, empty string "" or null if no value. 
	 * @return whether the solver option element is added successfully.
	 */
	public boolean addSolverOption(String name, String value, String description, String solver, String category, String type){
		if(name == null || name.length() <= 0) return false;		
		if(optimization == null) optimization = new OptimizationOption();
		if(optimization.solverOptions == null) optimization.solverOptions = new SolverOptions();

		int n = optimization.solverOptions.solverOption==null?0:optimization.solverOptions.solverOption.length;
		boolean bAdd = true;
		for(int i = 0; i < n; i++){
			SolverOption solverOption = optimization.solverOptions.solverOption[i];
			if(solverOption.name != null && solverOption.name.equals(name)){
				solverOption.value = value;
				solverOption.description = description;
				solverOption.solver = solver;
				solverOption.category = category;
				solverOption.type = type;
				bAdd = false;
				break;
			}
		}
		if(bAdd){
			n++;
			SolverOption[] mSolverOptions = new SolverOption[n];
			for(int i = 0; i < n-1; i++){
				mSolverOptions[i].name = optimization.solverOptions.solverOption[i].name;
				mSolverOptions[i].value = optimization.solverOptions.solverOption[i].value;
				mSolverOptions[i].description = optimization.solverOptions.solverOption[i].description;
				mSolverOptions[i].solver = optimization.solverOptions.solverOption[i].solver;
				mSolverOptions[i].category = optimization.solverOptions.solverOption[i].category;
				mSolverOptions[i].type = optimization.solverOptions.solverOption[i].type;
			}
			mSolverOptions[n-1].name = name;
			mSolverOptions[n-1].value = value;
			mSolverOptions[n-1].description = description;
			mSolverOptions[n-1].solver = solver;
			mSolverOptions[n-1].category = category;
			mSolverOptions[n-1].type = type;
			optimization.solverOptions.solverOption = mSolverOptions;
		}
		optimization.solverOptions.numberOfSolverOptions = n;
		return true;
	}//addSolverOption

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
