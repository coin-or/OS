/**
 * @(#)OSEntity 1.0 03/14/2005
 *
 * Copyright (c) 2005 
 */
package org.optimizationservices.oscommon.localinterface;

import java.util.GregorianCalendar;
import java.util.Hashtable;

import org.optimizationservices.oscommon.datastructure.osentity.Access;
import org.optimizationservices.oscommon.datastructure.osentity.AccessLimits;
import org.optimizationservices.oscommon.datastructure.osentity.AccessType;
import org.optimizationservices.oscommon.datastructure.osentity.EntityData;
import org.optimizationservices.oscommon.datastructure.osentity.EntityHeader;
import org.optimizationservices.oscommon.datastructure.osentity.FunctionType;
import org.optimizationservices.oscommon.datastructure.osentity.GeneralInfo;
import org.optimizationservices.oscommon.datastructure.osentity.HardwareInfo;
import org.optimizationservices.oscommon.datastructure.osentity.JobInfo;
import org.optimizationservices.oscommon.datastructure.osentity.KeyWords;
import org.optimizationservices.oscommon.datastructure.osentity.Link;
import org.optimizationservices.oscommon.datastructure.osentity.Links;
import org.optimizationservices.oscommon.datastructure.osentity.OptimizationInfo;
import org.optimizationservices.oscommon.datastructure.osentity.OtherEntityInfo;
import org.optimizationservices.oscommon.datastructure.osentity.Owner;
import org.optimizationservices.oscommon.datastructure.osentity.ServiceInfo;
import org.optimizationservices.oscommon.datastructure.osentity.SpecialAlgorithm;
import org.optimizationservices.oscommon.datastructure.osentity.SpecialStructure;
import org.optimizationservices.oscommon.datastructure.osentity.SystemInfo;
import org.optimizationservices.oscommon.representationparser.OSeLReader;
import org.optimizationservices.oscommon.representationparser.OSeLWriter;

/**
*
* <P>The <code>OSEntity</code> class is a local interface for storing Optimization Services
* entity. Its design follows the Optimization Services entity Language (OSeL). 
* All the data structures in this class are standards specified in OSeL. 
*
* @author Robert Fourer, Jun Ma, Kipp Martin
* @version 1.0, 03/14/2005
* @since OS 1.0
*/

public class OSEntity {
		
	/**
	 * entityHeader holds the first child of the OSEntity specified by the OSeL Schema. 
	 */
	public EntityHeader entityHeader = new EntityHeader();

	/**
	 * entityData holds the second child of the OSEntity specified by the OSeL Schema. 
	 */
	public EntityData entityData = new EntityData();

	/**
	 *
	 * Default constructor. 
	 */
	public OSEntity(){
	}//constructor
	
	/**
	 * read an OSeL instance and return and OSEntity object.  
	 * 
	 * @param osel holds the optimization entity in a string which format follows the
	 * Optimization Services entity Language (OSeL) schema.
	 * @param isFile holds whether the osel string is a file name or a string that literally holds the osel contents.  
	 * @param validate holds whether the reader should be validating against the schema or not.
	 * @return the OSEntity object constructed from the OSeL String.  
	 * @throws Exception if there are errors in reading the string or setting the OSEntity. 
	 */
   	public OSEntity readOSeL(String osel, boolean isFile, boolean validate) throws Exception{
   		OSeLReader oselReader = new OSeLReader(validate);
		boolean bRead = false;
		if(isFile){
			bRead = oselReader.readFile(osel);
		}
		else{
			bRead = oselReader.readString(osel);			
		}
		if(!bRead) throw new Exception("OSeL string not valid");
		return oselReader.getOSEntity();
   	}//readOSeL
   	
   	/**
   	 * write the OSEntity to an osel xml string. 
   	 * 
   	 * @return the osel xml string. 
	 * @throws Exception if there are errors in writing the osel string. 
   	 */
   	public String writeOSeL() throws Exception{
		OSeLWriter oselWriter = new OSeLWriter();
		oselWriter.setOSEntity(this);
		return oselWriter.writeToString();
   	}//writeOSeL
   	
   	/**
	 * Get service name.
	 * 
	 * @return the service name. 
	 */
	public String getServiceName(){
		return entityHeader.serviceName;
	}//getServiceName
	
   	/**
	 * Set service name.
	 * 
	 * @param serviceName holds the name of the service. 
	 * @return whether the service name is set successfully. 
	 */
	public boolean setServiceName(String serviceName){
		entityHeader.serviceName = serviceName;
		return true;
	}//setServiceName
	
   	/**
	 * Get service uri.
	 * 
	 * @return the service uri. 
	 */
	public String getServiceURI(){
		return entityHeader.serviceURI;
	}//getServiceURI
	
   	/**
	 * Set service uri.
	 * 
	 * @param serviceURI holds the uri of the service. 
	 * @return whether the service uri is set successfully. 
	 */
	public boolean setServiceURI(String serviceURI){
		entityHeader.serviceURI = serviceURI;
		return true;
	}//setServiceURI
	
   	/**
	 * Get time of the registration date.
	 * 
	 * @return the time of the registration date.
	 */
	public GregorianCalendar getRegistrationDate(){
		return entityHeader.registrationDate;
	}//getRegistrationDate
	
   	/**
	 * Set time of the registration date.
	 * 
	 * @param date holds the registration date.
	 * @return whether registration date is set successfully. 
	 */
	public boolean setRegistrationDate(GregorianCalendar date){
		entityHeader.registrationDate = date;
		return true;
	}//setRegistrationDate
	
   	/**
	 * Get the message. 
	 * 
	 * @return the message. 
	 */
	public String getMessage(){
		return entityHeader.message;
	}//getMessage
	
   	/**
	 * Set the message. 
	 * 
	 * @param message holds the message. 
	 * @return whether the message is set successfully. 
	 */
	public boolean setMessage(String message){
		entityHeader.message = message;
		return true;
	}//setMessage

	/**
	 * Get whether the license is reqired of the service or not. 
	 * 
	 * @return whether the license is reqired of the service or not. 
	 */
	public boolean getLicenseRequired(){
		if(entityData.general == null) return false;
		if(entityData.general.access == null) return false;
		if(entityData.general.access.type == null) return false;
		return entityData.general.access.type.licenseRequired;
	}//getLicenseRequired
	
	/**
	 * Set whether the license is reqired of the service or not. 
	 * 
	 * @param licenseRequired holds whether the license is reqired of the service or not.
	 * 
	 * @return whether the licenseRequired is set successfully or not. 
	 */
	public boolean setLicenseRequired(boolean licenseRequired){
		if(entityData.general == null) entityData.general = new GeneralInfo();
		if(entityData.general.access == null) entityData.general.access = new Access();
		if(entityData.general.access.type == null) entityData.general.access.type = new AccessType();
		entityData.general.access.type.licenseRequired = licenseRequired;
		return true;
	}//setLicenseRequired

	/**
	 * Get whether the user name is reqired of the service or not. 
	 * 
	 * @return whether the user name is reqired of the service or not. 
	 */
	public boolean getUserNameRequired(){
		if(entityData.general == null) return false;
		if(entityData.general.access == null) return false;
		if(entityData.general.access.type == null) return false;
		return entityData.general.access.type.userNameRequired;
	}//getUserNameRequired
	
	/**
	 * Set whether the user name is reqired of the service or not. 
	 * 
	 * @param userNameRequired holds whether the user name is reqired of the service or not.
	 * 
	 * @return whether the userNameRequired is set successfully or not. 
	 */
	public boolean setUserNameRequired(boolean userNameRequired){
		if(entityData.general == null) entityData.general = new GeneralInfo();
		if(entityData.general.access == null) entityData.general.access = new Access();
		if(entityData.general.access.type == null) entityData.general.access.type = new AccessType();
		entityData.general.access.type.userNameRequired = userNameRequired;
		return true;
	}//setUserNameRequired

	/**
	 * Get whether the password is reqired of the service or not. 
	 * 
	 * @return whether the password is reqired of the service or not. 
	 */
	public boolean getPasswordRequired(){
		if(entityData.general == null) return false;
		if(entityData.general.access == null) return false;
		if(entityData.general.access.type == null) return false;
		return entityData.general.access.type.passwordRequired;
	}//getPasswordRequired
	
	/**
	 * Set whether the password is reqired of the service or not. 
	 * 
	 * @param passwordRequired holds whether the password is reqired of the service or not.
	 * 
	 * @return whether the passwordRequired is set successfully or not. 
	 */
	public boolean setPasswordRequired(boolean passwordRequired){
		if(entityData.general == null) entityData.general = new GeneralInfo();
		if(entityData.general.access == null) entityData.general.access = new Access();
		if(entityData.general.access.type == null) entityData.general.access.type = new AccessType();
		entityData.general.access.type.passwordRequired = passwordRequired;
		return true;
	}//setPasswordRequired

	/**
	 * Get the access limits of the service. 
	 * 
	 * @return the access limits information of the service entity; null if none. 
	 */
	public AccessLimits getAccessLimits(){
		if(entityData.general == null) return null;
		if(entityData.general.access == null) return null;
		return entityData.general.access.limits;
	}//getAccessLimits
	
	/**
	 * Set the access limit information of the service entity. 
	 * 
	 * @param accessLimits holds the access limit information.
	 * 
	 * @return whether the access limit information is set successfully or not. 
	 */
	public boolean setAccessLimits(AccessLimits accessLimits){
		if(entityData.general == null) entityData.general = new GeneralInfo();
		if(entityData.general.access == null) entityData.general.access = new Access();
		entityData.general.access.limits = accessLimits;
		return true;
	}//setAccessLimits
	
	/**
	 * Get the owner information of the service entity. 
	 * 
	 * @return the owner information of the service entity; null if none. 
	 */
	public Owner getOwner(){
		if(entityData.general == null) return null;
		return entityData.general.owner;
	}//getOwner
	
	/**
	 * Set the owner information of the service entity. 
	 * 
	 * @param owner holds the service owner.
	 * 
	 * @return whether the owner information is set successfully or not. 
	 */
	public boolean setOwner(Owner owner){
		if(entityData.general == null) entityData.general = new GeneralInfo();
		entityData.general.owner = owner;
		return true;
	}//setOwner
	
	/**
	 * Get the key words of the service. 
	 * 
	 * @return the key words in a string array; null if none.  
	 */
	public String[] getKeyWords(){
		if(entityData.general == null) return null;
		if(entityData.general.keyWords == null) return null;
		return entityData.general.keyWords.key;
	}//getKeyWords

	/**
	 * Set the key words of the service. 
	 * 
	 * @param keyWords holds the service key words.
	 * 
	 * @return whether the key words of the service are set successfully or not. 
	 */
	public boolean setKeyWords(String[] keyWords){
		if(entityData.general == null) entityData.general = new GeneralInfo();
		if(entityData.general.keyWords == null) entityData.general.keyWords = new KeyWords();
		entityData.general.keyWords.key = keyWords;
		return true;
	}//setKeyWords
	
	/**
	 * Get the links of the service. 
	 * 
	 * @return the links of the service; null if none. 
	 */
	public Link[] getLinks(){
		if(entityData.general == null) return null;
		if(entityData.general.links == null) return null;
		return entityData.general.links.link;
	}//getLinks
	
	/**
	 * Set the links of the service. 
	 * 
	 * @param links holds a Link array of the service links.  
	 * @return whether the links of the service are set successfully. 
	 */
	public boolean setLinks(Link[] links){
		if(entityData.general == null) entityData.general = new GeneralInfo();
		if(entityData.general.links == null) entityData.general.links = new Links();
		entityData.general.links.link = links;
		return true;
	}//setLinks


	/**
	 * Get the system description. 
	 * 
	 * @return the system description; null or empty string if none. 
	 */
	public String getSystemDescription(){
		if(entityData.system == null) return null;
		return entityData.system.description;
	}//getSystemDescription
	
	/**
	 * Set the system description. 
	 * 
	 * @param description holds the system description. 
	 * 
	 * @return whether the system description is set successfully or not. 
	 */
	public boolean setSystemDescription(String description){
		if(entityData.system == null) entityData.system = new SystemInfo();
		entityData.system.description = description;
		return true;
	}//setSystemDescription

	/**
	 * Get the system dedication, a double between 0 and 1 with 1 being fully dedicated. 
	 * 
	 * @return the system dedication; Double.NaN if none. 
	 */
	public double getSystemDedication(){
		if(entityData.system == null) return Double.NaN;
		return entityData.system.dedication;
	}//getSystemDedication
	
	/**
	 * Set the system dedication. 
	 * 
	 * @param dedication holds the system dedication, a double between 0 and 1 with 1 being fully dedicated.  
	 * 
	 * @return whether the system dedication.  is set successfully or not. 
	 */
	public boolean setSystemDedication(double dedication){
		if(dedication < 0 || dedication > 1) return false;
		if(entityData.system == null) entityData.system = new SystemInfo();
		entityData.system.dedication = dedication;
		return true;
	}//setSystemDedication
	
	/**
	 * Get the system hardware information.  
	 * 
	 * @return the system hardware information; null if none. 
	 */
	public HardwareInfo getSystemHardwareInfo(){
		if(entityData.system == null) return null;
		return entityData.system.hardware;
	}//getSystemHardwareInfo
	
	/**
	 * Set the system hardware information.
	 * 
	 * @param hardwareInfo holds the system hardware information.
	 * 
	 * @return whether the system hardware information is set successfully or not. 
	 */
	public boolean setSystemHardwareInfo(HardwareInfo hardwareInfo){
		if(entityData.system == null) entityData.system = new SystemInfo();
		entityData.system.hardware = hardwareInfo;
		return true;
	}//setSystemHardwareInfo
	
	/**
	 * Get the service description.  
	 * 
	 * @return the service description; null or empty string if none. 
	 */
	public String getServiceDescription(){
		if(entityData.service == null) return null;
		return entityData.service.description;
	}//getServiceDescription
	
	/**
	 * Set the service description. 
	 * 
	 * @param description holds the service description.
	 * 
	 * @return whether the service description is set successfully or not. 
	 */
	public boolean setServiceDescription(String description){
		if(entityData.service == null) entityData.service = new ServiceInfo();
		entityData.service.description = description;
		return true;
	}//setServiceDescription

	/**
	 * Get the service type, which can be: 
	 * solver, analyzer, scheduler, simulation, registry, modeler, agent 
	 * 
	 * @return the service type; null or empty string if none. 
	 */
	public String getServiceType(){
		if(entityData.service == null) return null;
		return entityData.service.type;
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
		if(type != null &&
		   type.length() > 0 && 
		   !type.equals("solver") && 
		   !type.equals("analyzer") &&
		   !type.equals("scheduler") &&
		   !type.equals("simulation") &&
		   !type.equals("registry") &&
		   !type.equals("modeler") &&
		   !type.equals("agent")) return false;
		if(entityData.service == null) entityData.service = new ServiceInfo();
		entityData.service.type = type;
		return true;
	}//setServiceType

	/**
	 * Get the service category, which can be: 
	 * education, government, organization, company, military, personal, other
	 * 
	 * @return the service category; null or empty string if none. 
	 */
	public String getServiceCategory(){
		if(entityData.service == null) return null;
		return entityData.service.category;
	}//getServiceCategory
	
	/**
	 * Set the service category. 
	 * 
	 * @param category holds the service category, which can be:
	 * education, government, organization, company, military, personal, other
	 * 
	 * @return whether the service category is set successfully or not. 
	 */
	public boolean setServiceCategory(String category){
		if(category != null &&
		   category.length() > 0 &&
		   !category.equals("education") && 
		   !category.equals("government") &&
		   !category.equals("organization") &&
		   !category.equals("company") &&
		   !category.equals("military") &&
		   !category.equals("personal") &&
		   !category.equals("other")) return false;
		if(entityData.service == null) entityData.service = new ServiceInfo();
		entityData.service.category = category;
		return true;
	}//setServiceCategory
	
	/**
	 * Get the service software description.  
	 * 
	 * @return the software description; null or empty string if none. 
	 */
	public String getServiceSoftwareDescription(){
		if(entityData.service == null) return null;
		return entityData.service.software;
	}//getServiceSoftwareDescription
	
	/**
	 * Set the service software description. 
	 * 
	 * @param softwareDescription holds the software description.
	 * 
	 * @return whether the software description is set successfully or not. 
	 */
	public boolean setServiceSoftwareDescription(String softwareDescription){
		if(entityData.service == null) entityData.service = new ServiceInfo();
		entityData.service.software = softwareDescription;
		return true;
	}//setServiceSoftwareDescription

	/**
	 * Get the service algorithm description.  
	 * 
	 * @return the algorithm description; null or empty string if none. 
	 */
	public String getServiceAlgorithmDescription(){
		if(entityData.service == null) return null;
		return entityData.service.algorithm;
	}//getServiceAlgorithmDescription
	
	/**
	 * Set the algorithm description. 
	 * 
	 * @param algorithmDescription holds the algorithm description.
	 * 
	 * @return whether the algorithm description is set successfully or not. 
	 */
	public boolean setServiceAlgorithmDescription(String algorithmDescription){
		if(entityData.service == null) entityData.service = new ServiceInfo();
		entityData.service.algorithm = algorithmDescription;
		return true;
	}//setServiceAlgorithmDescription

	/**
	 * Get the service web page.  
	 * 
	 * @return the service web page; null or empty string if none. 
	 */
	public String getServiceWebPage(){
		if(entityData.service == null) return null;
		return entityData.service.webPage;
	}//getServiceWebPage
	
	/**
	 * Set the service web page. 
	 * 
	 * @param webPage holds the service web page.
	 * 
	 * @return whether the service web page is set successfully or not. 
	 */
	public boolean setServiceWebPage(String webPage){
		if(entityData.service == null) entityData.service = new ServiceInfo();
		entityData.service.webPage = webPage;
		return true;
	}//setServiceWebPage

	/**
	 * Get the service wsdl location.  
	 * 
	 * @return the service wsdl location; null or empty string if none. 
	 */
	public String getServiceWSDLLocation(){
		if(entityData.service == null) return null;
		return entityData.service.wsdlLocation;
	}//getServiceWSDLLocation
	
	/**
	 * Set the service wsdl location. 
	 * 
	 * @param wsdlLocation holds the service wsdl location.
	 * 
	 * @return whether the service wsdlLocation is set successfully or not. 
	 */
	public boolean setServiceWSDLLocation(String wsdlLocation){
		if(entityData.service == null) entityData.service = new ServiceInfo();
		entityData.service.wsdlLocation = wsdlLocation;
		return true;
	}//setServiceWSDLLocation
	
	/**
	 * Get the service logo image link.  
	 * 
	 * @return the service logo image link; null or empty string if none. 
	 */
	public String getServiceLogoImageLink(){
		if(entityData.service == null) return null;
		return entityData.service.logoImageLink;
	}//getServiceLogoImageLink
	
	/**
	 * Set the service logo image link. 
	 * 
	 * @param logoImageLink holds the service logo image link.
	 * 
	 * @return whether the service logoImageLink is set successfully or not. 
	 */
	public boolean setServiceLogoImageLink(String logoImageLink){
		if(entityData.service == null) entityData.service = new ServiceInfo();
		entityData.service.logoImageLink = logoImageLink;
		return true;
	}//setServiceLogoImageLink

	/**
	 * Get the default option names and values in the standard OSOption structure which 
	 * is specified by the OSoL schema. 
	 * 
	 * @return the default option names and values in the standard OSOption structure, null if none. 
	 */
	public OSOption getDefaultOptionNamesAndValues(){
		if(entityData.job == null) return null;
		return entityData.job.osol;	
	}//getDefaultOptionNamesAndValues
	
	/**
	 * Set the default option names and values in the standard OSOption structure which 
	 * is specified by the OSoL schema. 
	 * 
	 * @param osOption holds the default option names and values in the standard OSOption structure. 
	 * @return wehter the the default option names and values are set successfully or not. 
	 */
	public boolean setDefaultOptionNamesAndValues(OSOption osOption){
		if(entityData.job == null) entityData.job = new JobInfo();
		entityData.job.osol = osOption;	
		return true;
	}//setDefaultOptionNamesAndValues

	/**
	 * Get the optimization description.  
	 * 
	 * @return the optimization description; null or empty string if none. 
	 */
	public String getOptimizationDescription(){
		if(entityData.optimization == null) return null;
		return entityData.optimization.description;
	}//getOptimizationDescription
	
	/**
	 * Set the optimization description. 
	 * 
	 * @param description holds the optimization description.
	 * 
	 * @return whether the optimization description is set successfully or not. 
	 */
	public boolean setOptimizationDescription(String description){
		if(entityData.optimization == null) entityData.optimization = new OptimizationInfo();
		entityData.optimization.description = description;
		return true;
	}//setOptimizationDescription

	/**
	 * Get the optimization variable type, which can be: 
	 * continuous, pureBinary, mixedBinary, pureInteger, mixedInteger, discrete.  
	 * 
	 * @return the optimization variable type; null or empty string if none. 
	 */
	public String getOptimizationVariableType(){
		if(entityData.optimization == null) return null;
		return entityData.optimization.variableType;
	}//getOptimizationVariableType
	
	/**
	 * Set the optimization variable type. 
	 * 
	 * @param variableType holds the optimization variable type, which can be:
	 * continuous, pureBinary, mixedBinary, pureInteger, mixedInteger, discrete
	 * 
	 * @return whether the optimization variable type is set successfully or not. 
	 */
	public boolean setOptimizationVariableType(String variableType){
		if(variableType != null &&
		   variableType.length() > 0 &&
		   !variableType.equals("continuous") && 
		   !variableType.equals("pureBinary") &&
		   !variableType.equals("mixedBinary") &&
		   !variableType.equals("pureInteger") &&
		   !variableType.equals("mixedInteger") &&
		   !variableType.equals("discrete")) return false;
		if(entityData.optimization == null) entityData.optimization = new OptimizationInfo();
		entityData.optimization.variableType = variableType;
		return true;
	}//setOptimizationVariableType

	/**
	 * Get the optimization objective type, which can be: 
	 * none, singleObjective, multiObjectives
	 * 
	 * @return the optimization objective type; null or empty string if none. 
	 */
	public String getOptimizationObjectiveType(){
		if(entityData.optimization == null) return null;
		return entityData.optimization.objectiveType;
	}//getOptimizationObjectiveType
	
	/**
	 * Set the optimization objective type. 
	 * 
	 * @param objectiveType holds the optimization objective type, which can be:
	 * none, singleObjective, multiObjectives
	 * 
	 * @return whether the optimization objective type is set successfully or not. 
	 */
	public boolean setOptimizationObjectiveType(String objectiveType){
		if(objectiveType != null &&
		   objectiveType.length() > 0 &&
		   !objectiveType.equals("none") && 
		   !objectiveType.equals("singleObjective") &&
		   !objectiveType.equals("multiObjectives")) return false;
		if(entityData.optimization == null) entityData.optimization = new OptimizationInfo();
		entityData.optimization.objectiveType = objectiveType;
		return true;
	}//setOptimizationObjectiveType

	/**
	 * Get the optimization constraint type, which can be: 
	 * generalRange, pureEquality, pureBound, 
	 * pureLinearComplementarity, pureNonlinearComplementarity, 
	 * linearMixedComplementarity, nonlinearMixedComplementarity, generalMixedComplementarity,
	 * pureCone, mixedCone. 
	 * 
	 * @return the optimization constraint type; null or empty string if none. 
	 */
	public String getOptimizationConstraintType(){
		if(entityData.optimization == null) return null;
		return entityData.optimization.constraintType;
	}//getOptimizationConstraintType
	
	/**
	 * Set the optimization constraint type. 
	 * 
	 * @param constraintType holds the optimization constraint type, which can be:
	 * generalRange, pureEquality, pureBound, 
	 * pureLinearComplementarity, pureNonlinearComplementarity, 
	 * linearMixedComplementarity, nonlinearMixedComplementarity, generalMixedComplementarity,
	 * pureCone, mixedCone. 
	 * 
	 * @return whether the optimization constraint type is set successfully or not. 
	 */
	public boolean setOptimizationConstraintType(String constraintType){
		if(constraintType != null &&
		   constraintType.length() > 0 &&
		   !constraintType.equals("generalRange") && 
		   !constraintType.equals("pureEquality") &&
		   !constraintType.equals("pureBound") &&
		   !constraintType.equals("pureLinearComplementarity") &&
		   !constraintType.equals("pureNonlinearComplementarity") &&
		   !constraintType.equals("linearMixedComplementarity") &&
		   !constraintType.equals("nonlinearMixedComplementarity") &&
		   !constraintType.equals("generalMixedComplementarity") &&
		   !constraintType.equals("pureCone") &&
		   !constraintType.equals("mixedCone")) return false;
		if(entityData.optimization == null) entityData.optimization = new OptimizationInfo();
		entityData.optimization.constraintType = constraintType;
		return true;
	}//setOptimizationConstraintType

	/**
	 * Get the optimization objective linearity, which can be: 
	 * none, linearNetwork, linear, sumOfSquares, convexQuadratic, convexNonlinear, generalQuadratic, generalNonlinear
	 * 
	 * @return the optimization objective linearity; null or empty string if none. 
	 */
	public String getOptimizationObjectiveLinearity(){
		if(entityData.optimization == null) return null;
		return entityData.optimization.objectiveLinearity;
	}//getOptimizationObjectiveLinearity
	
	/**
	 * Set the optimization objective linearity. 
	 * 
	 * @param objectiveLinearity holds the optimization objective linearity, which can be:
	 * none, linearNetwork, linear sumOfSquares, convexQuadratic, convexNonlinear, generalQuadratic, generalNonlinear
	 * 
	 * @return whether the optimization objective linearity is set successfully or not. 
	 */
	public boolean setOptimizationObjectiveLinearity(String objectiveLinearity){
		if(objectiveLinearity != null &&
		   objectiveLinearity.length() > 0 &&
		   !objectiveLinearity.equals("none") && 
		   !objectiveLinearity.equals("linearNetwork") &&
		   !objectiveLinearity.equals("linear") &&
		   !objectiveLinearity.equals("sumOfSquares") &&
		   !objectiveLinearity.equals("convexQuadratic") &&
		   !objectiveLinearity.equals("convexNonlinear") &&
		   !objectiveLinearity.equals("generalQuadratic") &&
		   !objectiveLinearity.equals("generalNonlinear")) return false;
		if(entityData.optimization == null) entityData.optimization = new OptimizationInfo();
		entityData.optimization.objectiveLinearity = objectiveLinearity;
		return true;
	}//setOptimizationObjectiveLinearity

	/**
	 * Get the constraint objective linearity, which can be: 
	 * none, bound, linearNetwork, linear, convexQuadratic, convexNonlinear, generalQuadratic, generalNonlinear
	 * 
	 * @return the optimization constraint linearity; null or empty string if none. 
	 */
	public String getOptimizationConstraintLinearity(){
		if(entityData.optimization == null) return null;
		return entityData.optimization.constraintLinearity;
	}//getOptimizationConstraintLinearity
	
	/**
	 * Set the optimization constraint linearity. 
	 * 
	 * @param constraintLinearity holds the optimization constraint linearity, which can be:
	 * none, bound, linearNetwork, linear, convexQuadratic, convexNonlinear, generalQuadratic, generalNonlinear
	 * 
	 * @return whether the optimization constraint linearity is set successfully or not. 
	 */
	public boolean setOptimizationConstraintLinearity(String constraintLinearity){
		if(constraintLinearity != null &&
		   constraintLinearity.length() > 0 &&
		   !constraintLinearity.equals("none") && 
		   !constraintLinearity.equals("bound") &&
		   !constraintLinearity.equals("linearNetwork") &&
		   !constraintLinearity.equals("linear") &&
		   !constraintLinearity.equals("convexQuadratic") &&
		   !constraintLinearity.equals("convexNonlinear") &&
		   !constraintLinearity.equals("generalQuadratic") &&
		   !constraintLinearity.equals("generalNonlinear")) return false;
		if(entityData.optimization == null) entityData.optimization = new OptimizationInfo();
		entityData.optimization.constraintLinearity = constraintLinearity;
		return true;
	}//setOptimizationConstraintLinearity
	
	/**
	 * Get the optimization objective differentiability, which can be: 
	 * generallyDifferentiable, twiceDifferentiable, firstDifferentiable, 
	 * nonDifferentiableContinous, nonContinuous, simulation. 
	 * 
	 * @return the optimization objective differentiability; null or empty string if none. 
	 */
	public String getOptimizationObjectiveDifferentiability(){
		if(entityData.optimization == null) return null;
		return entityData.optimization.objectiveDifferentiability;
	}//getOptimizationObjectiveDifferentiability
	
	/**
	 * Set the optimization objective differentiability. 
	 * 
	 * @param objectiveDifferentiability holds the optimization objective differentiability, which can be:
	 * generallyDifferentiable, twiceDifferentiable, firstDifferentiable, 
	 * nonDifferentiableContinous, nonContinuous, simulation. 
	 * 
	 * @return whether the optimization objective differentiability is set successfully or not. 
	 */
	public boolean setOptimizationObjectiveDifferentiability(String objectiveDifferentiability){
		if(objectiveDifferentiability != null &&
		   objectiveDifferentiability.length() > 0 &&
		   !objectiveDifferentiability.equals("generallyDifferentiable") && 
		   !objectiveDifferentiability.equals("twiceDifferentiable") &&
		   !objectiveDifferentiability.equals("firstDifferentiable") &&
		   !objectiveDifferentiability.equals("nonDifferentiableContinous") &&
		   !objectiveDifferentiability.equals("nonContinuous") &&
		   !objectiveDifferentiability.equals("simulation")) return false;
		if(entityData.optimization == null) entityData.optimization = new OptimizationInfo();
		entityData.optimization.objectiveDifferentiability = objectiveDifferentiability;
		return true;
	}//setOptimizationObjectiveDifferentiability

	/**
	 * Get the optimization constraint differentiability, which can be: 
	 * generallyDifferentiable, twiceDifferentiable, firstDifferentiable, 
	 * nonDifferentiableContinous, nonContinuous, simulation. 
	 * 
	 * @return the optimization constraint differentiability; null or empty string if none. 
	 */
	public String getOptimizationConstraintDifferentiability(){
		if(entityData.optimization == null) return null;
		return entityData.optimization.constraintDifferentiability;
	}//getOptimizationConstraintDifferentiability
	
	/**
	 * Set the optimization constraint differentiability. 
	 * 
	 * @param constraintDifferentiability holds the optimization constraint differentiability, which can be:
	 * generallyDifferentiable, twiceDifferentiable, firstDifferentiable, 
	 * nonDifferentiableContinous, nonContinuous, simulation. 
	 * 
	 * @return whether the optimization constraint differentiability is set successfully or not. 
	 */
	public boolean setOptimizationConstraintDifferentiability(String constraintDifferentiability){
		if(constraintDifferentiability != null &&
		   constraintDifferentiability.length() > 0 &&
		   !constraintDifferentiability.equals("generallyDifferentiable") && 
		   !constraintDifferentiability.equals("twiceDifferentiable") &&
		   !constraintDifferentiability.equals("firstDifferentiable") &&
		   !constraintDifferentiability.equals("nonDifferentiableContinous") &&
		   !constraintDifferentiability.equals("nonContinuous") &&
		   !constraintDifferentiability.equals("simulation")) return false;
		if(entityData.optimization == null) entityData.optimization = new OptimizationInfo();
		entityData.optimization.constraintDifferentiability = constraintDifferentiability;
		return true;
	}//setOptimizationConstraintDifferentiability

	/**
	 * Get the optimization parameter type, which can be: 
	 * number, string, both
	 * 
	 * @return the optimization parameter type; null or empty string if none. 
	 */
	public String getOptimizationParameterType(){
		if(entityData.optimization == null) return null;
		return entityData.optimization.parameterType;
	}//getOptimizationParameterType
	
	/**
	 * Set the optimization parameter type. 
	 * 
	 * @param parameterType holds the optimization parameter type, which can be:
	 * number, string, both
	 * 
	 * @return whether the optimization parameter type is set successfully or not. 
	 */
	public boolean setOptimizationParameterType(String parameterType){
		if(parameterType != null &&
		   parameterType.length() > 0 &&
		   !parameterType.equals("number") && 
		   !parameterType.equals("string") &&
		   !parameterType.equals("both")) return false;
		if(entityData.optimization == null) entityData.optimization = new OptimizationInfo();
		entityData.optimization.parameterType = parameterType;
		return true;
	}//setOptimizationParameterType

	/**
	 * Get the optimization stochasticity, which can be: 
	 * deterministic, stochastic, both
	 * 
	 * @return the optimization stochasticity; null or empty string if none. 
	 */
	public String getOptimizationStochasticity(){
		if(entityData.optimization == null) return null;
		return entityData.optimization.stochasticity;
	}//getOptimizationStochasticity
	
	/**
	 * Set the optimization stochasticity. 
	 * 
	 * @param tochasticity holds the optimization stochasticity, which can be:
	 * deterministic, stochastic, both
	 * 
	 * @return whether the optimization stochasticity is set successfully or not. 
	 */
	public boolean setOptimizationStochasticity(String stochasticity){
		if(stochasticity != null &&
		   stochasticity.length() > 0 &&
		   !stochasticity.equals("deterministic") && 
		   !stochasticity.equals("stochastic") &&
		   !stochasticity.equals("both")) return false;
		if(entityData.optimization == null) entityData.optimization = new OptimizationInfo();
		entityData.optimization.stochasticity = stochasticity;
		return true;
	}//setOptimizationStochasticity

	/**
	 * Get whether the service supports real time optimization or not.  
	 * 
	 * @return whether the service supports real time optimization or not.  
	 */
	public boolean getOptimizationRealTime(){
		if(entityData.optimization == null) return false;
		return entityData.optimization.realTime;
	}//getOptimizationRealTime
	
	/**
	 * Set whether the service supports real time optimization or not.  
	 * 
	 * @param realTime holds whether the service supports real time optimization or not.  
	 * 
	 * @return whether the service supports real time optimization or not.  
	 */
	public boolean setOptimizationRealTime(boolean realTime){
		if(entityData.optimization == null) entityData.optimization = new OptimizationInfo();
		entityData.optimization.realTime = realTime;
		return true;
	}//setOptimizationRealTime

	/**
	 * Get the function types that the service supports.   
	 * 
	 * @return the function types that the service supports, null if none.    
	 */
	public FunctionType getOptimizationFunctionType(){
		if(entityData.optimization == null) return null;
		return entityData.optimization.functionType;
	}//getOptimizationFunctionType
	
	/**
	 * Set the function types that the service supports.   
	 * 
	 * @param functionType holds the function types that the service supports.     
	 * 
	 * @return the function types that the service supports.   
	 */
	public boolean setOptimizationFunctionType(FunctionType functionType){
		if(entityData.optimization == null) entityData.optimization = new OptimizationInfo();
		entityData.optimization.functionType = functionType;
		return true;
	}//setOptimizationFunctionType

	
	/**
	 * Get the special structures that the service supports.   
	 * 
	 * @return the special structures that the service supports, null if none.    
	 */
	public SpecialStructure getOptimizationSpecialStructure(){
		if(entityData.optimization == null) return null;
		return entityData.optimization.specialStructure;
	}//getOptimizationSpecialStructure
	
	/**
	 * Set the special structures that the service supports.   
	 * 
	 * @param specialStructure holds the special structures that the service supports.     
	 * 
	 * @return the special structures that the service supports.   
	 */
	public boolean setOptimizationSpecialStructure(SpecialStructure specialStructure){
		if(entityData.optimization == null) entityData.optimization = new OptimizationInfo();
		entityData.optimization.specialStructure = specialStructure;
		return true;
	}//setOptimizationSpecialStructure

	/**
	 * Get the special algorithms that the service supports.   
	 * 
	 * @return the special algorithms that the service supports, null if none.    
	 */
	public SpecialAlgorithm getOptimizationSpecialAlgorithm(){
		if(entityData.optimization == null) return null;
		return entityData.optimization.specialAlgorithm;
	}//getOptimizationSpecialAlgorithm
	
	/**
	 * Set the special algorithms that the service supports.   
	 * 
	 * @param specialAlgorithm holds the special algorithms that the service supports.     
	 * 
	 * @return the special algorithms that the service supports.   
	 */
	public boolean setOptimizationSpecialAlgorithm(SpecialAlgorithm specialAlgorithm){
		if(entityData.optimization == null) entityData.optimization = new OptimizationInfo();
		entityData.optimization.specialAlgorithm = specialAlgorithm;
		return true;
	}//setOptimizationSpecialAlgorithm

	/**
	 * get a string array of names of other entity info. 
	 * 
	 * @return a string array of names of other entity info, null if no other entity info.  
	 */
	public String[] getOtherEntityInfoNames(){
		if(entityData.other == null) return null;
		int n = entityData.other.length;
		if(n <= 0) return null;
		String[] otherEntityInfoNames = new String[n];
		for(int i = 0; i < n; i++){
			otherEntityInfoNames[i] = entityData.other[i].name;
		}
		return otherEntityInfoNames;
	}//getOtherEntityNames
	
	/**
	 * get a hashmap of other entity info descriptions. 
	 * The keys of the hashmap are the entity info names, and 
	 * the values of the hashmap are the entity info descriptions.  
	 * 
	 * @return a hashmap of other entity info descriptions, null if no other entity info. 
	 */
	public Hashtable<String, String>  getOtherEntityInfoDescriptions(){
		if(entityData.other == null) return null;
		int n = entityData.other.length;
		if(n <= 0) return null;
		Hashtable<String, String> otherEntityInfoDescriptions = new Hashtable<String, String>();
		for(int i = 0; i < n; i++){
			otherEntityInfoDescriptions.put(entityData.other[i].name, entityData.other[i].description);
		}
		return otherEntityInfoDescriptions;
	}//getOtherEntityInfoDescriptions

	/**
	 * get a hashmap of other entity info values. 
	 * The keys of the hashmap are the entity info names, and 
	 * the values of the hashmap are the entity info values.  
	 * 
	 * @return a hashmap of other entity info values, null if no other entity info. 
	 */
	public Hashtable<String, String>  getOtherEntityInfoValues(){
		if(entityData.other == null) return null;
		int n = entityData.other.length;
		if(n <= 0) return null;
		Hashtable<String, String> otherEntityInfoValues = new Hashtable<String, String>();
		for(int i = 0; i < n; i++){
			otherEntityInfoValues.put(entityData.other[i].name, entityData.other[i].value);
		}
		return otherEntityInfoValues;
	}//getOtherEntityInfoValues

	/**
	 * set other entity info, with their names (required), descriptions (optional) and values (optional). 
	 * 
	 * @param names holds the names of the other entity info; it is required.  
	 * @param descriptions holds the descriptions of the other entity info; null if none. 
	 * @param values holds the values of the other entity info; null if none. 
	 * @return whether the other anlysis information is set successfully. 
	 */
	public boolean setOtherEntityInfo(String[] names, String[] descriptions, String[] values){
		if(names == null) return false;
		if(descriptions != null && descriptions.length != names.length) return false;
		if(values != null && values.length != names.length) return false;
		int n = names.length;
		entityData.other = new OtherEntityInfo[n];
		for(int i = 0; i < n; i++){
			entityData.other[i] = new OtherEntityInfo();
		}
		for(int i = 0; i < n; i++){
			entityData.other[i].name = names[i];
		}
		if(descriptions != null){
			for(int i = 0; i < n; i++){
				entityData.other[i].description = descriptions[i];
			}	
		}
		if(values != null){
			for(int i = 0; i < n; i++){
				entityData.other[i].value = values[i];
			}	
		}
		return true;
	}//setOtherEntityInfo

	/**
	 * main for test purposes.
	 *
	 * </p>
	 *
	 * @param argv command line arguments.
	 */
	public static void main(String[] args){
		
	}//main
}//class OSEntity

