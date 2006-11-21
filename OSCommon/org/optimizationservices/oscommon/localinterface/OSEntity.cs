using System;
using System.Collections;

using org.optimizationservices.oscommon.datastructure.osentity;
using org.optimizationservices.oscommon.representationparser;

namespace org.optimizationservices.oscommon.localinterface{
	/// <summary>
	/// The <c>OSEntity</c> class is a local interface for storing OS 
	/// entity. Its design follows the OSeL. Naming, structuring and layering 
	/// all are exactly the same as those in the OSeL schema. 
	/// @author Jun Ma	
	/// @version 1.0, 09/01/2005
	/// @since OS 1.0
	/// @copyright (c) 2005
	/// </summary>
	public class OSEntity{

		/// <summary>
		/// entityHeader holds the first child of the OSEntity specified by the OSbL Schema. 
		/// </summary>
		public EntityHeader entityHeader = new EntityHeader();

		/// <summary>
		/// entityData holds the second child of the OSEntity specified by the OSbL Schema. 
		/// </summary>
		public EntityData entityData = new EntityData();
			
		/// <summary>
		/// Default constructor. 
		/// </summary>
		public OSEntity(){
		}//constructor

		/// <summary>
		/// read an OSeL instance and return and OSEntity object.  
		/// @throws Exception if there are errors in reading the string or setting the OSEntity. 
		/// </summary>
		/// <param name="osel">holds the optimization entity in a string which format follows the
		/// Optimization Services entity Language (OSeL) schema</param>
		/// <param name="isFile">isFile holds whether the osel string is a file name or a string that literally holds the osel contents.  </param>
		/// <param name="validate">holds whether the reader should be validating against the schema or not.</param>
		/// <returns>the OSEntity object constructed from the OSeL String.  </returns>
		public OSEntity readOSeL(string osel, bool isFile, bool validate){
			OSeLReader oselReader = new OSeLReader(validate);
			bool bRead = false;
			if(isFile){
				bRead = oselReader.readFile(osel);
			}
			else{
				bRead = oselReader.readString(osel);			
			}
			if(!bRead) throw new Exception("OSeL string not valid");
			return oselReader.getOSEntity();
		}//readOSeL
	   
		/// <summary>
		/// write the OSEntity to an osel xml string. 
		/// @throws Exception if there are errors in writing the osel string. 
		/// </summary>
		/// <returns>the osel xml string. </returns>
		public string writeOSeL(){
			OSeLWriter oselWriter = new OSeLWriter();
			oselWriter.setOSEntity(this);
			return oselWriter.writeToString();
		}//writeOSeL

		/// <summary>
		/// Get service name.
		/// </summary>
		/// <returns>the service name. </returns>
		public string getServiceName(){
			return entityHeader.serviceName;
		}//getServiceName

		/// <summary>
		/// Set service name.
		/// </summary>
		/// <param name="serviceName">holds the name of the service. </param>
		/// <returns>whether the service name is set successfully. </returns>
		public bool setServiceName(string serviceName){
			entityHeader.serviceName = serviceName;
			return true;
		}//setServiceName

		/// <summary>
		/// Get service uri.
		/// </summary>
		/// <returns>the service uri. </returns>
		public string getServiceURI(){
			return entityHeader.serviceURI;
		}//getServiceURI

		/// <summary>
		/// Set service uri.
		/// </summary>
		/// <param name="serviceURI">holds the uri of the service. </param>
		/// <returns>whether the service uri is set successfully. </returns>
		public bool setServiceURI(string serviceURI){
			entityHeader.serviceURI = serviceURI;
			return true;
		}//setServiceURI

		/// <summary>
		/// Get time of the registration date.
		/// </summary>
		/// <returns>the time of the registration date.</returns>
		public DateTime getRegistrationDate(){
			return entityHeader.registrationDate;
		}//getRegistrationDate

		/// <summary>
		/// Set time of the registration date.
		/// </summary>
		/// <param name="date">holds the registration date.</param>
		/// <returns>whether registration date is set successfully. </returns>
		public bool setRegistrationDate(DateTime date){
			entityHeader.registrationDate = date;
			return true;
		}//setRegistrationDate

		/// <summary>
		/// Get the message. 
		/// </summary>
		/// <returns>the message. </returns>
		public string getMessage(){
			return entityHeader.message;
		}//getMessage
	
		/// <summary>
		/// Set the message. 
		/// </summary>
		/// <param name="message">holds the message. </param>
		/// <returns>whether the message is set successfully. </returns>
		public bool setMessage(string message){
			entityHeader.message = message;
			return true;
		}//setMessage

		/// <summary>
		/// Get whether the license is reqired of the service or not.
		/// </summary>
		/// <returns>whether the license is reqired of the service or not. </returns>
		public bool getLicenseRequired(){
			if(entityData.general == null) return false;
			if(entityData.general.access == null) return false;
			if(entityData.general.access.type == null) return false;
			return entityData.general.access.type.licenseRequired;
		}//getLicenseRequired

		/// <summary>
		/// Set whether the license is reqired of the service or not. 
		/// </summary>
		/// <param name="licenseRequired">whether the license is reqired of the service or not.</param>
		/// <returns>the licenseRequired is set successfully or not. </returns>
		public bool setLicenseRequired(bool licenseRequired){
			if(entityData.general == null) entityData.general = new GeneralInfo();
			if(entityData.general.access == null) entityData.general.access = new Access();
			if(entityData.general.access.type == null) entityData.general.access.type = new AccessType();
			entityData.general.access.type.licenseRequired = licenseRequired;
			return true;
		}//setLicenseRequired

		/// <summary>
		/// Get whether the user name is reqired of the service or not. 
		/// </summary>
		/// <returns>whether the user name is reqired of the service or not. </returns>
		public bool getUserNameRequired(){
			if(entityData.general == null) return false;
			if(entityData.general.access == null) return false;
			if(entityData.general.access.type == null) return false;
			return entityData.general.access.type.userNameRequired;
		}//getUserNameRequired
	
		/// <summary>
		/// Set whether the user name is reqired of the service or not. 
		/// </summary>
		/// <param name="userNameRequired">holds whether the user name is reqired of the service or not.</param>
		/// <returns>whether the userNameRequired is set successfully or not.</returns>
		public bool setUserNameRequired(bool userNameRequired){
			if(entityData.general == null) entityData.general = new GeneralInfo();
			if(entityData.general.access == null) entityData.general.access = new Access();
			if(entityData.general.access.type == null) entityData.general.access.type = new AccessType();
			entityData.general.access.type.userNameRequired = userNameRequired;
			return true;
		}//setUserNameRequired

		/// <summary>
		/// Get whether the password is reqired of the service or not.  
		/// </summary>
		/// <returns>whether the password is reqired of the service or not. </returns>
		public bool getPasswordRequired(){
			if(entityData.general == null) return false;
			if(entityData.general.access == null) return false;
			if(entityData.general.access.type == null) return false;
			return entityData.general.access.type.passwordRequired;
		}//getPasswordRequired

		/// <summary>
		/// Set whether the password is reqired of the service or not. 
		/// </summary>
		/// <param name="passwordRequired">holds whether the password is reqired of the service or not.</param>
		/// <returns>whether the passwordRequired is set successfully or not. </returns>
		public bool setPasswordRequired(bool passwordRequired){
			if(entityData.general == null) entityData.general = new GeneralInfo();
			if(entityData.general.access == null) entityData.general.access = new Access();
			if(entityData.general.access.type == null) entityData.general.access.type = new AccessType();
			entityData.general.access.type.passwordRequired = passwordRequired;
			return true;
		}//setPasswordRequired

		/// <summary>
		/// Get the access limits of the service. 
		/// </summary>
		/// <returns>the access limits information of the service entity; null if none. </returns>
		public AccessLimits getAccessLimits(){
			if(entityData.general == null) return null;
			if(entityData.general.access == null) return null;
			return entityData.general.access.limits;
		}//getAccessLimits

		/// <summary>
		/// Set the access limit information of the service entity. 
		/// </summary>
		/// <param name="accessLimits">holds the service access limit information.</param>
		/// <returns>whether the access limit information is set successfully or not. </returns>
		public bool setAccessLimits(AccessLimits accessLimits){
			if(entityData.general == null) entityData.general = new GeneralInfo();
			if(entityData.general.access == null) entityData.general.access = new Access();
			entityData.general.access.limits = accessLimits;
			return true;
		}//setAccessLimits

		/// <summary>
		/// Get the owner information of the service entity.
		/// </summary>
		/// <returns>the owner information of the service entity; null if none.</returns>
		public Owner getOwner(){
			if(entityData.general == null) return null;
			return entityData.general.owner;
		}//getOwner

		/// <summary>
		/// Set the owner information of the service entity. 
		/// </summary>
		/// <param name="owner">holds the service owner.</param>
		/// <returns>whether the owner information is set successfully or not. </returns>
		public bool setOwner(Owner owner){
			if(entityData.general == null) entityData.general = new GeneralInfo();
			entityData.general.owner = owner;
			return true;
		}//setOwner
	

		/// <summary>
		/// Get the key words of the service. 
		/// </summary>
		/// <returns>the key words in a string array; null if none.  </returns>
		public string[] getKeyWords(){
			if(entityData.general == null) return null;
			if(entityData.general.keyWords == null) return null;
			return entityData.general.keyWords.key;
		}//getKeyWords

		/// <summary>
		/// Set the key words of the service. 
		/// </summary>
		/// <param name="keyWords">holds the service key words.</param>
		/// <returns>whether the key words of the service are set successfully or not. </returns>
		public bool setKeyWords(string[] keyWords){
			if(entityData.general == null) entityData.general = new GeneralInfo();
			if(entityData.general.keyWords == null) entityData.general.keyWords = new KeyWords();
			entityData.general.keyWords.key = keyWords;
			return true;
		}//setKeyWords

		/// <summary>
		/// Get the links of the service. 
		/// </summary>
		/// <returns>the links of the service; null if none. </returns>
		public Link[] getLinks(){
			if(entityData.general == null) return null;
			if(entityData.general.links == null) return null;
			return entityData.general.links.link;
		}//getLinks

		/// <summary>
		/// Set the links of the service.
		/// </summary>
		/// <param name="links">holds a Link array of the service links.  </param>
		/// <returns>the links of the service are set successfully. </returns>
		public bool setLinks(Link[] links){
			if(entityData.general == null) entityData.general = new GeneralInfo();
			if(entityData.general.links == null) entityData.general.links = new Links();
			entityData.general.links.link = links;
			return true;
		}//setLinks

		/// <summary>
		/// Get the system description. 
		/// </summary>
		/// <returns>the system description; null or empty string if none. </returns>
		public string getSystemDescription(){
			if(entityData.system == null) return null;
			return entityData.system.description;
		}//getSystemDescription

		/// <summary>
		///  Set the system description. 
		/// </summary>
		/// <param name="description">holds the system description. </param>
		/// <returns>whether the system description is set successfully or not. </returns>
		public bool setSystemDescription(string description){
			if(entityData.system == null) entityData.system = new SystemInfo();
			entityData.system.description = description;
			return true;
		}//setSystemDescription

		/// <summary>
		/// Get the system dedication, a double between 0 and 1 with 1 being fully dedicated. 
		/// </summary>
		/// <returns>the system dedication; Double.NaN if none. </returns>
		public double getSystemDedication(){
			if(entityData.system == null) return Double.NaN;
			return entityData.system.dedication;
		}//getSystemDedication

		/// <summary>
		/// Set the system dedication. 
		/// </summary>
		/// <param name="dedication">holds the system dedication, a double between 0 and 1 with 1 being fully dedicated.  </param>
		/// <returns>whether the system dedication.  is set successfully or not. </returns>
		public bool setSystemDedication(double dedication){
			if(dedication < 0 || dedication > 1) return false;
			if(entityData.system == null) entityData.system = new SystemInfo();
			entityData.system.dedication = dedication;
			return true;
		}//setSystemDedication

		/// <summary>
		/// Get the system hardware information.  
		/// </summary>
		/// <returns>the system hardware information; null if none. </returns>
		public HardwareInfo getSystemHardwareInfo(){
			if(entityData.system == null) return null;
			return entityData.system.hardware;
		}//getSystemHardwareInfo

		/// <summary>
		/// Set the system hardware information.
		/// </summary>
		/// <param name="hardwareInfo">holds the system hardware information.</param>
		/// <returns>whether the system hardware information is set successfully or not.</returns>
		public bool setSystemHardwareInfo(HardwareInfo hardwareInfo){
			if(entityData.system == null) entityData.system = new SystemInfo();
			entityData.system.hardware = hardwareInfo;
			return true;
		}//setSystemHardwareInfo

		/// <summary>
		/// Get the service description.  
		/// </summary>
		/// <returns>the service description; null or empty string if none. </returns>
		public string getServiceDescription(){
			if(entityData.service == null) return null;
			return entityData.service.description;
		}//getServiceDescription


		/// <summary>
		/// Set the service description. 
		/// </summary>
		/// <param name="description">holds the service description.</param>
		/// <returns>whether the service description is set successfully or not. </returns>
		public bool setServiceDescription(string description){
			if(entityData.service == null) entityData.service = new ServiceInfo();
			entityData.service.description = description;
			return true;
		}//setServiceDescription

		/// <summary>
		/// Get the service type, which can be: 
		/// solver, analyzer, scheduler, simulation, registry, modeler, agent 
		/// </summary>
		/// <returns>the service type; null or empty string if none. </returns>
		public string getServiceType(){
			if(entityData.service == null) return null;
			return entityData.service.type;
		}//getServiceType

		/// <summary>
		/// Set the service type. 
		/// </summary>
		/// <param name="type">holds the service type, which can be:
		/// solver, analyzer, scheduler, simulation, registry, modeler, agent </param>
		/// <returns>whether the service type is set successfully or not. </returns>
		public bool setServiceType(string type){
			if(type != null &&
				type.Length > 0 &&
				!type.Equals("solver") && 
				!type.Equals("analyzer") &&
				!type.Equals("scheduler") &&
				!type.Equals("simulation") &&
				!type.Equals("registry") &&
				!type.Equals("modeler") &&
				!type.Equals("agent")) return false;
			if(entityData.service == null) entityData.service = new ServiceInfo();
			entityData.service.type = type;
			return true;
		}//setServiceType

		/// <summary>
		/// Get the service category, which can be: 
		///  education, government, organization, company, military, personal, other
		/// </summary>
		/// <returns>the service category; null or empty string if none. </returns>
		public string getServiceCategory(){
			if(entityData.service == null) return null;
			return entityData.service.category;
		}//getServiceCategory

		/// <summary>
		/// Set the service category. 
		/// </summary>
		/// <param name="category">holds the service category, which can be:
		///  education, government, organization, company, military, personal, other</param>
		/// <returns>whether the service category is set successfully or not. </returns>
		public bool setServiceCategory(string category){
			if(category != null &&
				category.Length > 0 &&
				!category.Equals("education") && 
				!category.Equals("government") &&
				!category.Equals("organization") &&
				!category.Equals("company") &&
				!category.Equals("military") &&
				!category.Equals("personal") &&
				!category.Equals("other")) return false;
			if(entityData.service == null) entityData.service = new ServiceInfo();
			entityData.service.category = category;
			return true;
		}//setServiceCategory

		/// <summary>
		/// Get the service software description.  
		/// </summary>
		/// <returns>the software description; null or empty string if none.</returns>
		public string getServiceSoftwareDescription(){
			if(entityData.service == null) return null;
			return entityData.service.software;
		}//getServiceSoftwareDescription

		/// <summary>
		/// Set the service software description. 
		/// </summary>
		/// <param name="softwareDescription">holds the software description.</param>
		/// <returns>whether the software description is set successfully or not. </returns>
		public bool setServiceSoftwareDescription(string softwareDescription){
			if(entityData.service == null) entityData.service = new ServiceInfo();
			entityData.service.software = softwareDescription;
			return true;
		}//setServiceSoftwareDescription

		/// <summary>
		/// Get the service algorithm description. 
		/// </summary>
		/// <returns>the algorithm description; null or empty string if none. </returns>
		public string getServiceAlgorithmDescription(){
			if(entityData.service == null) return null;
			return entityData.service.algorithm;
		}//getServiceAlgorithmDescription


		/// <summary>
		/// Set the algorithm description. 
		/// </summary>
		/// <param name="algorithmDescription">holds the algorithm description.</param>
		/// <returns>whether the algorithm description is set successfully or not. </returns>
		public bool setServiceAlgorithmDescription(string algorithmDescription){
			if(entityData.service == null) entityData.service = new ServiceInfo();
			entityData.service.algorithm = algorithmDescription;
			return true;
		}//setServiceAlgorithmDescription

		/// <summary>
		/// Get the service web page.  
		/// </summary>
		/// <returns>the service web page; null or empty string if none. </returns>
		public string getServiceWebPage(){
			if(entityData.service == null) return null;
			return entityData.service.webPage;
		}//getServiceWebPage

		/// <summary>
		/// Set the service web page. 
		/// </summary>
		/// <param name="webPage">webPage holds the service web page.</param>
		/// <returns>whether the service web page is set successfully or not. </returns>
		public bool setServiceWebPage(string webPage){
			if(entityData.service == null) entityData.service = new ServiceInfo();
			entityData.service.webPage = webPage;
			return true;
		}//setServiceWebPage

		/// <summary>
		/// Get the service wsdl location.  
		/// </summary>
		/// <returns>the service wsdl location; null or empty string if none. </returns>
		public string getServiceWSDLLocation(){
			if(entityData.service == null) return null;
			return entityData.service.wsdlLocation;
		}//getServiceWSDLLocation

		/// <summary>
		/// Set the service wsdl location. 
		/// </summary>
		/// <param name="wsdlLocation">holds the service wsdl location.</param>
		/// <returns>whether the service wsdlLocation is set successfully or not. </returns>
		public bool setServiceWSDLLocation(string wsdlLocation){
			if(entityData.service == null) entityData.service = new ServiceInfo();
			entityData.service.wsdlLocation = wsdlLocation;
			return true;
		}//setServiceWSDLLocation

		/// <summary>
		/// Get the service logo image link.  
		/// </summary>
		/// <returns>the service logo image link; null or empty string if none. </returns>
		public string getServiceLogoImageLink(){
			if(entityData.service == null) return null;
			return entityData.service.logoImageLink;
		}//getServiceLogoImageLink

		/// <summary>
		/// Set the service logo image link. 
		/// </summary>
		/// <param name="logoImageLink">holds the service logo image link.</param>
		/// <returns>whether the service logoImageLink is set successfully or not. </returns>
		public bool setServiceLogoImageLink(string logoImageLink){
			if(entityData.service == null) entityData.service = new ServiceInfo();
			entityData.service.logoImageLink = logoImageLink;
			return true;
		}//setServiceLogoImageLink

		/// <summary>
		/// Get the default option names and values in the standard OSOption structure which 
		/// is specified by the OSoL schema.
		/// </summary>
		/// <returns>the default option names and values in the standard OSOption structure, null if none. </returns>
		public OSOption getDefaultOptionNamesAndValues(){
			if(entityData.job == null) return null;
			return entityData.job.osol;	
		}//getDefaultOptionNamesAndValues

		/// <summary>
		/// Set the default option names and values in the standard OSOption structure which 
		/// is specified by the OSoL schema. 
		/// </summary>
		/// <param name="osOption">holds the default option names and values in the standard OSOption structure. </param>
		/// <returns>wehter the the default option names and values are set successfully or not. </returns>
		public bool setDefaultOptionNamesAndValues(OSOption osOption){
			if(entityData.job == null) entityData.job = new JobInfo();
			entityData.job.osol = osOption;	
			return true;
		}//setDefaultOptionNamesAndValues

		/// <summary>
		/// Get the optimization description.  
		/// </summary>
		/// <returns>the optimization description; null or empty string if none. </returns>
		public string getOptimizationDescription(){
			if(entityData.optimization == null) return null;
			return entityData.optimization.description;
		}//getOptimizationDescription
	
		/// <summary>
		/// Set the optimization description. 
		/// </summary>
		/// <param name="description">holds the optimization description.</param>
		/// <returns>whether the optimization description is set successfully or not. </returns>
		public bool setOptimizationDescription(string description){
			if(entityData.optimization == null) entityData.optimization = new OptimizationInfo();
			entityData.optimization.description = description;
			return true;
		}//setOptimizationDescription

		/// <summary>
		/// Get the optimization variable type, which can be: 
		/// continuous, pureBinary, mixedBinary, pureInteger, mixedInteger, discrete.  
		/// </summary>
		/// <returns>the optimization variable type; null or empty string if none. </returns>
		public string getOptimizationVariableType(){
			if(entityData.optimization == null) return null;
			return entityData.optimization.variableType;
		}//getOptimizationVariableType

		/// <summary>
		/// Set the optimization variable type. 
		/// </summary>
		/// <param name="variableType">holds the optimization variable type, which can be:
		/// continuous, pureBinary, mixedBinary, pureInteger, mixedInteger, discrete</param>
		/// <returns>whether the optimization variable type is set successfully or not. </returns>
		public bool setOptimizationVariableType(string variableType){
			if(variableType != null &&
				variableType.Length > 0 &&
				!variableType.Equals("continuous") && 
				!variableType.Equals("pureBinary") &&
				!variableType.Equals("mixedBinary") &&
				!variableType.Equals("pureInteger") &&
				!variableType.Equals("mixedInteger") &&
				!variableType.Equals("discrete")) return false;
			if(entityData.optimization == null) entityData.optimization = new OptimizationInfo();
			entityData.optimization.variableType = variableType;
			return true;
		}//setOptimizationVariableType

		/// <summary>
		/// Get the optimization objective type, which can be: 
		/// none, singleObjective, multiObjectives
		/// </summary>
		/// <returns>the optimization objective type; null or empty string if none. </returns>
		public string getOptimizationObjectiveType(){
			if(entityData.optimization == null) return null;
			return entityData.optimization.objectiveType;
		}//getOptimizationObjectiveType

		/// <summary>
		/// Set the optimization objective type. 
		/// </summary>
		/// <param name="objectiveType">holds the optimization objective type, which can be:
		/// none, singleObjective, multiObjectives</param>
		/// <returns>whether the optimization objective type is set successfully or not.</returns>
		public bool setOptimizationObjectiveType(string objectiveType){
			if(objectiveType != null &&
				objectiveType.Length > 0 &&
				!objectiveType.Equals("none") && 
				!objectiveType.Equals("singleObjective") &&
				!objectiveType.Equals("multiObjectives")) return false;
			if(entityData.optimization == null) entityData.optimization = new OptimizationInfo();
			entityData.optimization.objectiveType = objectiveType;
			return true;
		}//setOptimizationObjectiveType

		/// <summary>
		/// Get the optimization constraint type, which can be: 
		/// generalRange, pureEquality, pureBound, 
		/// pureLinearComplementarity, pureNonlinearComplementarity, 
		/// linearMixedComplementarity, nonlinearMixedComplementarity, generalMixedComplementarity,
		/// pureCone, mixedCone. 
		/// </summary>
		/// <returns>the optimization constraint type; null or empty string if none. </returns>
		public string getOptimizationConstraintType(){
			if(entityData.optimization == null) return null;
			return entityData.optimization.constraintType;
		}//getOptimizationConstraintType

		/// <summary>
		/// Set the optimization constraint type. 
		/// </summary>
		/// <param name="constraintType">holds the optimization constraint type, which can be:
		/// generalRange, pureEquality, pureBound, 
		/// pureLinearComplementarity, pureNonlinearComplementarity, 
		/// linearMixedComplementarity, nonlinearMixedComplementarity, generalMixedComplementarity,
		/// pureCone, mixedCone. 
		/// </param>
		/// <returns></returns>
		public bool setOptimizationConstraintType(string constraintType){
			if(constraintType != null &&
				constraintType.Length > 0 &&
				!constraintType.Equals("generalRange") && 
				!constraintType.Equals("pureEquality") &&
				!constraintType.Equals("pureBound") &&
				!constraintType.Equals("pureLinearComplementarity") &&
				!constraintType.Equals("pureNonlinearComplementarity") &&
				!constraintType.Equals("linearMixedComplementarity") &&
				!constraintType.Equals("nonlinearMixedComplementarity") &&
				!constraintType.Equals("generalMixedComplementarity") &&
				!constraintType.Equals("pureCone") &&
				!constraintType.Equals("mixedCone")) return false;
			if(entityData.optimization == null) entityData.optimization = new OptimizationInfo();
			entityData.optimization.constraintType = constraintType;
			return true;
		}//setOptimizationConstraintType

		/// <summary>
		/// Get the optimization objective linearity, which can be: 
		/// none, linearNetwork, linear, sumOfSquares, convexQuadratic, convexNonlinear, generalQuadratic, generalNonlinear
		/// </summary>
		/// <returns>the optimization objective linearity; null or empty string if none. </returns>
		public string getOptimizationObjectiveLinearity(){
			if(entityData.optimization == null) return null;
			return entityData.optimization.objectiveLinearity;
		}//getOptimizationObjectiveLinearity

		/// <summary>
		/// Set the optimization objective linearity. 
		/// </summary>
		/// <param name="objectiveLinearity">holds the optimization objective linearity, which can be:
		/// none, linearNetwork, linear sumOfSquares, convexQuadratic, convexNonlinear, generalQuadratic, generalNonlinear
		/// </param>
		/// <returns>whether the optimization objective linearity is set successfully or not. </returns>
		public bool setOptimizationObjectiveLinearity(string objectiveLinearity){
			if(objectiveLinearity != null &&
				objectiveLinearity.Length > 0 &&
				!objectiveLinearity.Equals("none") && 
				!objectiveLinearity.Equals("linearNetwork") &&
				!objectiveLinearity.Equals("linear") &&
				!objectiveLinearity.Equals("sumOfSquares") &&
				!objectiveLinearity.Equals("convexQuadratic") &&
				!objectiveLinearity.Equals("convexNonlinear") &&
				!objectiveLinearity.Equals("generalQuadratic") &&
				!objectiveLinearity.Equals("generalNonlinear")) return false;
			if(entityData.optimization == null) entityData.optimization = new OptimizationInfo();
			entityData.optimization.objectiveLinearity = objectiveLinearity;
			return true;
		}//setOptimizationObjectiveLinearity

		/// <summary>
		/// Get the constraint objective linearity, which can be: 
		/// none, bound, linearNetwork, linear, convexQuadratic, convexNonlinear, generalQuadratic, generalNonlinear
		/// </summary>
		/// <returns>the optimization constraint linearity; null or empty string if none. </returns>
		public string getOptimizationConstraintLinearity(){
			if(entityData.optimization == null) return null;
			return entityData.optimization.constraintLinearity;
		}//getOptimizationConstraintLinearity

		/// <summary>
		/// Set the optimization constraint linearity. 
		/// </summary>
		/// <param name="constraintLinearity">holds the optimization constraint linearity, which can be:
		///  none, bound, linearNetwork, linear, convexQuadratic, convexNonlinear, generalQuadratic, generalNonlinear
		/// </param>
		/// <returns>whether the optimization constraint linearity is set successfully or not. </returns>
		public bool setOptimizationConstraintLinearity(string constraintLinearity){
			if(constraintLinearity != null &&
				constraintLinearity.Length > 0 &&
				!constraintLinearity.Equals("none") && 
				!constraintLinearity.Equals("bound") &&
				!constraintLinearity.Equals("linearNetwork") &&
				!constraintLinearity.Equals("linear") &&
				!constraintLinearity.Equals("convexQuadratic") &&
				!constraintLinearity.Equals("convexNonlinear") &&
				!constraintLinearity.Equals("generalQuadratic") &&
				!constraintLinearity.Equals("generalNonlinear")) return false;
			if(entityData.optimization == null) entityData.optimization = new OptimizationInfo();
			entityData.optimization.constraintLinearity = constraintLinearity;
			return true;
		}//setOptimizationConstraintLinearity

		/// <summary>
		/// Get the optimization objective differentiability, which can be: 
		/// generallyDifferentiable, twiceDifferentiable, firstDifferentiable, 
		/// nonDifferentiableContinous, nonContinuous, simulation.  
		/// </summary>
		/// <returns>the optimization objective differentiability; null or empty string if none. </returns>
		public string getOptimizationObjectiveDifferentiability(){
			if(entityData.optimization == null) return null;
			return entityData.optimization.objectiveDifferentiability;
		}//getOptimizationObjectiveDifferentiability
	
		/// <summary>
		/// Set the optimization objective differentiability. 
		/// </summary>
		/// <param name="objectiveDifferentiability">holds the optimization objective differentiability, which can be:
		/// generallyDifferentiable, twiceDifferentiable, firstDifferentiable, 
		/// nonDifferentiableContinous, nonContinuous, simulation. 
		/// </param>
		/// <returns>whether the optimization objective differentiability is set successfully or not. </returns>
		public bool setOptimizationObjectiveDifferentiability(string objectiveDifferentiability){
			if(objectiveDifferentiability != null &&
				objectiveDifferentiability.Length > 0 &&
				!objectiveDifferentiability.Equals("generallyDifferentiable") && 
				!objectiveDifferentiability.Equals("twiceDifferentiable") &&
				!objectiveDifferentiability.Equals("firstDifferentiable") &&
				!objectiveDifferentiability.Equals("nonDifferentiableContinous") &&
				!objectiveDifferentiability.Equals("nonContinuous") &&
				!objectiveDifferentiability.Equals("simulation")) return false;
			if(entityData.optimization == null) entityData.optimization = new OptimizationInfo();
			entityData.optimization.objectiveDifferentiability = objectiveDifferentiability;
			return true;
		}//setOptimizationObjectiveDifferentiability

		/// <summary>
		/// Get the optimization constraint differentiability, which can be: 
		/// generallyDifferentiable, twiceDifferentiable, firstDifferentiable, 
		/// nonDifferentiableContinous, nonContinuous, simulation. 
		/// </summary>
		/// <returns>the optimization constraint differentiability; null or empty string if none. </returns>
		public string getOptimizationConstraintDifferentiability(){
			if(entityData.optimization == null) return null;
			return entityData.optimization.constraintDifferentiability;
		}//getOptimizationConstraintDifferentiability

		/// <summary>
		/// Set the optimization constraint differentiability. 
		/// </summary>
		/// <param name="constraintDifferentiability">holds the optimization constraint differentiability, which can be:
		/// generallyDifferentiable, twiceDifferentiable, firstDifferentiable, 
		/// nonDifferentiableContinous, nonContinuous, simulation. 
		/// </param>
		/// <returns>whether the optimization constraint differentiability is set successfully or not. </returns>
		public bool setOptimizationConstraintDifferentiability(string constraintDifferentiability){
			if(constraintDifferentiability != null &&
				constraintDifferentiability.Length > 0 &&
				!constraintDifferentiability.Equals("generallyDifferentiable") && 
				!constraintDifferentiability.Equals("twiceDifferentiable") &&
				!constraintDifferentiability.Equals("firstDifferentiable") &&
				!constraintDifferentiability.Equals("nonDifferentiableContinous") &&
				!constraintDifferentiability.Equals("nonContinuous") &&
				!constraintDifferentiability.Equals("simulation")) return false;
			if(entityData.optimization == null) entityData.optimization = new OptimizationInfo();
			entityData.optimization.constraintDifferentiability = constraintDifferentiability;
			return true;
		}//setOptimizationConstraintDifferentiability

		/// <summary>
		/// Get the optimization parameter type, which can be:
		/// number, string, both
		/// </summary>
		/// <returns>the optimization parameter type; null or empty string if none. </returns>
		public string getOptimizationParameterType(){
			if(entityData.optimization == null) return null;
			return entityData.optimization.parameterType;
		}//getOptimizationParameterType

		/// <summary>
		/// Set the optimization parameter type. 
		/// </summary>
		/// <param name="parameterType">parameterType holds the optimization parameter type, which can be:
		/// number, string, both
		/// </param>
		/// <returns>whether the optimization parameter type is set successfully or not. </returns>
		public bool setOptimizationParameterType(string parameterType){
			if(parameterType != null &&
				parameterType.Length > 0 &&
				!parameterType.Equals("number") && 
				!parameterType.Equals("string") &&
				!parameterType.Equals("both")) return false;
			if(entityData.optimization == null) entityData.optimization = new OptimizationInfo();
			entityData.optimization.parameterType = parameterType;
			return true;
		}//setOptimizationParameterType

		/// <summary>
		/// Get the optimization stochasticity, which can be: 
		/// deterministic, stochastic, both
		/// </summary>
		/// <returns>the optimization stochasticity; null or empty string if none. </returns>
		public string getOptimizationStochasticity(){
			if(entityData.optimization == null) return null;
			return entityData.optimization.stochasticity;
		}//getOptimizationStochasticity

		/// <summary>
		/// Set the optimization stochasticity. 
		/// </summary>
		/// <param name="stochasticity">holds the optimization stochasticity, which can be:
		/// deterministic, stochastic, both
		/// </param>
		/// <returns>whether the optimization stochasticity is set successfully or not. </returns>
		public bool setOptimizationStochasticity(string stochasticity){
			if(stochasticity != null &&
				stochasticity.Length > 0 &&
				!stochasticity.Equals("deterministic") && 
				!stochasticity.Equals("stochastic") &&
				!stochasticity.Equals("both")) return false;
			if(entityData.optimization == null) entityData.optimization = new OptimizationInfo();
			entityData.optimization.stochasticity = stochasticity;
			return true;
		}//setOptimizationStochasticity

		/// <summary>
		/// Get whether the service supports real time optimization or not. 
		/// </summary>
		/// <returns>whether the service supports real time optimization or not.  </returns>
		public bool getOptimizationRealTime(){
			if(entityData.optimization == null) return false;
			return entityData.optimization.realTime;
		}//getOptimizationRealTime

		/// <summary>
		/// Set whether the service supports real time optimization or not.  
		/// </summary>
		/// <param name="realTime">holds whether the service supports real time optimization or not.  </param>
		/// <returns>whether the service supports real time optimization or not.  </returns>
		public bool setOptimizationRealTime(bool realTime){
			if(entityData.optimization == null) entityData.optimization = new OptimizationInfo();
			entityData.optimization.realTime = realTime;
			return true;
		}//setOptimizationRealTime

		/// <summary>
		/// Get the function types that the service supports.
		/// </summary>
		/// <returns>the function types that the service supports, null if none. </returns>
		public FunctionType getOptimizationFunctionType(){
			if(entityData.optimization == null) return null;
			return entityData.optimization.functionType;
		}//getOptimizationFunctionType


		/// <summary>
		/// Set the function types that the service supports.   
		/// </summary>
		/// <param name="functionType">holds the function types that the service supports.    </param>
		/// <returns>the function types that the service supports. </returns>
		public bool setOptimizationFunctionType(FunctionType functionType){
			if(entityData.optimization == null) entityData.optimization = new OptimizationInfo();
			entityData.optimization.functionType = functionType;
			return true;
		}//setOptimizationFunctionType

		/// <summary>
		/// Get the special structures that the service supports.   
		/// </summary>
		/// <returns>the special structures that the service supports, null if none.    </returns>
		public SpecialStructure getOptimizationSpecialStructure(){
			if(entityData.optimization == null) return null;
			return entityData.optimization.specialStructure;
		}//getOptimizationSpecialStructure

		/// <summary>
		/// Set the special structures that the service supports.   
		/// </summary>
		/// <param name="specialStructure">holds the special structures that the service supports.     </param>
		/// <returns>the special structures that the service supports.   </returns>
		public bool setOptimizationSpecialStructure(SpecialStructure specialStructure){
			if(entityData.optimization == null) entityData.optimization = new OptimizationInfo();
			entityData.optimization.specialStructure = specialStructure;
			return true;
		}//setOptimizationSpecialStructure

		/// <summary>
		/// Get the special algorithms that the service supports.   
		/// </summary>
		/// <returns>the special algorithms that the service supports, null if none.    </returns>
		public SpecialAlgorithm getOptimizationSpecialAlgorithm(){
			if(entityData.optimization == null) return null;
			return entityData.optimization.specialAlgorithm;
		}//getOptimizationSpecialAlgorithm

		/// <summary>
		/// Set the special algorithms that the service supports.   
		/// </summary>
		/// <param name="specialAlgorithm">holds the special algorithms that the service supports.    </param>
		/// <returns>the special algorithms that the service supports.   </returns>
		public bool setOptimizationSpecialAlgorithm(SpecialAlgorithm specialAlgorithm){
			if(entityData.optimization == null) entityData.optimization = new OptimizationInfo();
			entityData.optimization.specialAlgorithm = specialAlgorithm;
			return true;
		}//setOptimizationSpecialAlgorithm

		/// <summary>
		/// get a string array of names of other entity info. 
		/// </summary>
		/// <returns>a string array of names of other entity info, null if no other entity info.  </returns>
		public string[] getOtherEntityInfoNames(){
			if(entityData.other == null) return null;
			int n = entityData.other.Length;
			if(n <= 0) return null;
			string[] otherEntityInfoNames = new string[n];
			for(int i = 0; i < n; i++){
				otherEntityInfoNames[i] = entityData.other[i].name;
			}
			return otherEntityInfoNames;
		}//getOtherEntityNames


		/// <summary>
		/// get a hashmap of other entity info descriptions. 
		/// The keys of the hashmap are the entity info names, and 
		/// the values of the hashmap are the entity info descriptions.  
		/// </summary>
		/// <returns>a hashmap of other entity info descriptions, null if no other entity info. </returns>
		public Hashtable getOtherEntityInfoDescriptions(){
			if(entityData.other == null) return null;
			int n = entityData.other.Length;
			if(n <= 0) return null;
			Hashtable otherEntityInfoDescriptions = new Hashtable();
			for(int i = 0; i < n; i++){
				otherEntityInfoDescriptions.Add(entityData.other[i].name, entityData.other[i].description);
			}
			return otherEntityInfoDescriptions;
		}//getOtherEntityInfoDescriptions

		/// <summary>
		/// get a hashmap The keys of the hashmap are the entity info names, 
		/// and  of other entity info values. 
		/// the values of the hashmap are the entity info values.  
		/// </summary>
		/// <returns>a hashmap of other entity info values, null if no other entity info. </returns>
		public Hashtable  getOtherEntityInfoValues(){
			if(entityData.other == null) return null;
			int n = entityData.other.Length;
			if(n <= 0) return null;
			Hashtable otherEntityInfoValues = new Hashtable();
			for(int i = 0; i < n; i++){
				otherEntityInfoValues.Add(entityData.other[i].name, entityData.other[i].value);
			}
			return otherEntityInfoValues;
		}//getOtherEntityInfoValues

		/// <summary>
		///  set other entity info, with their names (required), descriptions (optional) and values (optional). 
		/// </summary>
		/// <param name="names">holds the names of the other entity info; it is required.  </param>
		/// <param name="descriptions">holds the descriptions of the other entity info; null if none. </param>
		/// <param name="values">the values of the other entity info; null if none. </param>
		/// <returns>whether the other anlysis information is set successfully. </returns>
		public bool setOtherEntityInfo(string[] names, string[] descriptions, string[] values){
			if(names == null) return false;
			if(descriptions != null && descriptions.Length != names.Length) return false;
			if(values != null && values.Length != names.Length) return false;
			int n = names.Length;
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


	}//class OSEntity
}//namespace
