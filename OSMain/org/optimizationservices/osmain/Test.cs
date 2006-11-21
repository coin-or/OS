using System;
using System.Windows.Forms;
using System.Diagnostics;
using System.Collections;
using System.Xml;
using System.IO;
using System.Reflection;

using org.optimizationservices.oscommon.localinterface;
using org.optimizationservices.oscommon.util;
using org.optimizationservices.ossolver;
using org.optimizationservices.oscommon.communicationagent;
using org.optimizationservices.oscommon.representationparser;
using org.optimizationservices.oscommon.datastructure.osentity;
using org.optimizationservices.oscommon.datastructure.osprocess;
using org.optimizationservices.oscommon.datastructure.osanalysis;
using org.optimizationservices.oscommon.datastructure.osbenchmark;
using org.optimizationservices.oscommon.datastructure.osoption;
using org.optimizationservices.oscommon.datastructure.osgeneral;
using org.optimizationservices.oscommon.datastructure.osquery;
using org.optimizationservices.oscommon.datastructure.osregistry;
using org.optimizationservices.oscommon.datastructure.osrepository;
using org.optimizationservices.oscommon.datastructure.osresult;
using org.optimizationservices.ossolver.solver;
using IEnNET;



namespace org.optimizationservices.osmain
{

	/// <summary>
	/// Summary description for Class1.
	/// </summary>	
	class Test{
		/// <summary>
		/// The main entry point for the application.
		/// </summary>
		[STAThread]
		public static void Main(string[] args){
			//test jws web service
			/*
			JavaTestService javaTestService = new JavaTestService();
			Console.WriteLine(javaTestService.helloJava("csharp input1"));
			*/
			
			//test asmx web service
			/*
			ASMXTestService asmxTestService = new ASMXTestService();
			Console.WriteLine(asmxTestService.helloCSharp("csharp input2"));
			*/
			
			//test command launching
			/*
			Process process = new Process();
			process.StartInfo = new ProcessStartInfo("c:\\CGWeb\\RunCG.bat");
			process.Start();
			process.WaitForExit();
			*/
			/*
			ProcessUtil.launchAndWaitForFinish("notepad", null, null);
			ProcessUtil.launchAndWaitForFinish("cmd.exe", "c:\\code\\temp\\OSMain.exe", "c:\\code\\temp\\abc.txt");			
			ProcessUtil.launchAndWaitForFinish("c:\\code\\temp\\OSMain.exe", null, null);
			string sBatchFile = "c:\\code\\sas\\SASUser\\sasbatch.bat";
			ProcessUtil.launchAndWaitForFinish(sBatchFile, null, null);
			*/

			//test sleep
			
			//System.Threading.Thread.Sleep(7000);
			/*
			for(int i = 0; i < 100; i++) Console.WriteLine("CG is run successfully");
			IOUtil.log("from c:\\code\\temp\\OSMain.exe", null);
			*/

			//test using message box. 
			/*
			System.Windows.Forms.MessageBox.Show();
			*/

			//test arraylist
			/*
			ArrayList arrayList = new ArrayList();
			arrayList.Add(1);
			arrayList.Add(2);
			object[] copyArray = arrayList.ToArray();
			for(int i = 0; i < copyArray.Length; i++){
				int a = System.Convert.ToInt32(copyArray[i]);
				int b = (int)copyArray[i];
				Console.WriteLine("a: " + a);
				Console.WriteLine("b: " + b);
			}
			*/

			//test reading and writing file
			/*
			string sOut = IOUtil.readStringFromFile("c:\\code\\temp\\myText.txt");
			if(sOut == null) Console.WriteLine("null");
			else Console.WriteLine(sOut);
			bool bWrite = IOUtil.writestringToFile(sOut, "c:\\code\\temp\\myTextOut.txt");
			Console.WriteLine(bWrite);
			*/

			//test CGSolver
			/*
			CGSolverService cgsolverService = new CGSolverService();
			string sResult = cgsolverService.solve("");
			Console.WriteLine(sResult);
			*/
			
			//test java Web Services
			/*
			//string sSolverAddress = "http://gsbkip.chicagogsb.edu/os/ossolver/LindoSolverService.jws";
			string sSolverAddress = "http://128.135.130.17:8181/axis/OSSolverService";
			//string sOSiL = IOUtil.readStringFromFile("../../../../OSRepository/test/osil/parinc.osil"); 
			string sOSiL = IOUtil.readStringFromFile("../../../../OSRepository/test/kmartin/parinc.osil");
			OSSolverAgent osSolverAgent = new OSSolverAgent();
			osSolverAgent.solverAddress = sSolverAddress;
			Console.WriteLine("file: "+ sOSiL);
			string sOSrL = osSolverAgent.solve(sOSiL, "");
			Console.WriteLine(sOSrL);
			Console.ReadLine();	
			*/	
			

			//test xml reading
			/*
			string fileName = "..\\..\\..\\..\\OSRepository\\test\\ossl\\ossl.ossl";
			//XmlDocument doc = XMLUtil.parseFileUsingDOM(fileName, true);
			XmlDocument doc = XMLUtil.parsestringUsingDOM(IOUtil.readStringFromFile(fileName), false);
			Console.WriteLine(doc.GetElementsByTagName("el").Count);
			*/

			//test xml writing
			/*
			//string fileName = "..\\..\\..\\..\\OSRepository\\test\\ossl\\ossl1.ossl";
			XmlDocument doc = XMLUtil.createNewDocument();
			XmlElement ele = doc.CreateElement("abc");
			doc.AppendChild(ele);
			//XMLUtil.writeXMLDocumentToStandardOutput(doc);
			Console.WriteLine(XMLUtil.writeXMLDocumentTostring(doc));
			*/
			
			//test readingstringFromUrl
			/*
			Console.WriteLine(IOUtil.readStringFromURL("http://cgweb14.macorp.local:8080/cgRequest.ossl"));
			*/


			//test OSoLReader
			/*
			OSoLReader osolReader = new OSoLReader(false);
			Console.WriteLine(IOUtil.readStringFromFile("../../../../OSRepository/test/osol/osol.osol"));
			Console.WriteLine(osolReader.readFile("../../../../OSRepository/test/osol/osol.osol"));
			Console.WriteLine(osolReader.getJobID());
			Console.WriteLine(osolReader.getOtherOptionNumber());
			string sValue = osolReader.getOtherOptionValueByName("ad");
			if(sValue == null) Console.WriteLine("null");
			else Console.WriteLine(sValue);
			string sDescription = osolReader.getOtherOptionDescriptionByName("a");
			Console.WriteLine(sDescription);
			for(int i=0;i<osolReader.getOtherOptionNumber();i++){
				Console.WriteLine(osolReader.getOtherOptionNames()[i]);
				Console.WriteLine(osolReader.getOtherOptionValues()[i]);
				Console.WriteLine(osolReader.getOtherOptionDescriptions()[i]);
			}
			
			osolReader.writeToStandardOutput();
			*/
			
			//test OSoLWriter
			/*
			OSoLWriter osolWriter = new OSoLWriter();
			//string fName = "../../../../OSRepository/test/osol/osol.osol";
		
			string[] msOtherOptionNames = {"c", "d"};
			string[] msOtherOptionValues = {"c1", "d1"};
		
			if(!osolWriter.setJobID("IdealE456")) Console.WriteLine(1);
			if(!osolWriter.setJobID("IdealE457")) Console.WriteLine(1);
			if(!osolWriter.setOtherOptions(msOtherOptionNames, msOtherOptionValues, null)) Console.WriteLine(2);
		
			osolWriter.addOtherOption("g", "g1", null);
			osolWriter.addOtherOption("g", "g2", "gdescription");

			osolWriter.writeToStandardOutput();
			*/
			

			//test OSaLReader
			/*
			OSaLReader osalReader = new OSaLReader(false);
			Console.WriteLine(IOUtil.readStringFromFile(OSParameter.CODE_HOME + "OSRepository/test/osal/osal.osal"));
			Console.WriteLine(osalReader.readFile(OSParameter.CODE_HOME + "OSRepository/test/osal/osal.osal"));
			Console.WriteLine(osalReader.getAnalysisMessage());
			Console.WriteLine(osalReader.getJobID());
			AnalysisStatus status = osalReader.getAnalysisStatus();
			Console.WriteLine(status.type);
			Console.WriteLine(status.description);
			int iSubstatus = status.substatus==null?0:status.substatus.Length;
			for(int i = 0; i < iSubstatus; i++){
				Console.WriteLine(status.substatus[i].name);
				Console.WriteLine(status.substatus[i].description);
				Console.WriteLine(status.substatus[i].value);			
			}
			Console.WriteLine(osalReader.getAnalysisTime());
			Console.WriteLine(osalReader.getInstanceName());
			Console.WriteLine(osalReader.getServiceName());
			Console.WriteLine(osalReader.getServiceURI());
			Console.WriteLine(osalReader.getVariableNumber());	
			Console.WriteLine(osalReader.getObjectiveNumber());
			Console.WriteLine(osalReader.getConstraintNumber());
			osalReader.getInstanceAnalysis();
			osalReader.getVariableAnalysis();
			osalReader.getObjectiveAnalysis();
			osalReader.getConstraintAnalysis();
			osalReader.getLinearConstraintCoefficientAnalysis();
			osalReader.getQuadraticCoefficientAnalysis();
			osalReader.getNonlinearExpressionAnalysis();
			Console.WriteLine(osalReader.getOtherAnalysisNumber());
			string sValue = osalReader.getOtherAnalysisValueByName("ad");
			if(sValue == null) Console.WriteLine("null");
			else Console.WriteLine(sValue);
			string sDescription = osalReader.getOtherAnalysisDescriptionByName("a");
			Console.WriteLine(sDescription);
			for(int i=0;i<osalReader.getOtherAnalysisNumber();i++){
				Console.WriteLine(osalReader.getOtherAnalysisNames()[i]);
				Console.WriteLine(osalReader.getOtherAnalysisValues()[i]);
				Console.WriteLine(osalReader.getOtherAnalysisDescriptions()[i]);
			}
			
			osalReader.writeToStandardOutput();
				*/		
			//test OSaLWriter
			/*
			OSaLWriter osalWriter = new OSaLWriter();
			string sFileName = OSParameter.CODE_HOME + "OSRepository/test/osal/osal.osal";
			osalWriter.setVariableNumber(1);
			osalWriter.setObjectiveNumber(0);
			osalWriter.setConstraintNumber(0);
			AnalysisStatus status = new AnalysisStatus();
			status.type= "success";
			status.description = "my status description";
			AnalysisSubstatus[] substatuses = new AnalysisSubstatus[2];
			substatuses[0] = new AnalysisSubstatus();
			substatuses[0].name = "sub name 0";
			substatuses[0].description = "sub description 0";
			substatuses[0].value = "sub value 0";
			substatuses[1] = new AnalysisSubstatus();
			substatuses[1].name = "sub name 1";
			substatuses[1].description = "sub description 1";
			substatuses[1].value = "sub value 1";
			status.substatus = substatuses;
			if(!osalWriter.setAnalysisStatus(status)) Console.WriteLine("status!");
			if(!osalWriter.setAnalysisMessage("my message")) Console.WriteLine("message!");
			if(!osalWriter.setInstanceName("my instance")) Console.WriteLine("instance");
			if(!osalWriter.setServiceName("my service name")) Console.WriteLine("service name");
			if(!osalWriter.setServiceURI("my service uri")) Console.WriteLine("uri");
			if(!osalWriter.setJobID("my job ID")) Console.WriteLine("job ID");
			if(!osalWriter.setAnalysisTime(new DateTime(1970, 1, 1, 0, 0, 0))) Console.WriteLine("time!");
			if(!osalWriter.setAnalysisTime(DateTime.Now)) Console.WriteLine("time!");
				
			if(!osalWriter.setInstanceAnalysis(new InstanceAnalysis())) Console.WriteLine("instance analysis");
			if(!osalWriter.setVariableAnalysis(new VariableAnalysis())) Console.WriteLine("variable analysis");
			if(!osalWriter.setObjectiveAnalysis(new ObjectiveAnalysis())) Console.WriteLine("objective analysis");
			if(!osalWriter.setConstraintAnalysis(new ConstraintAnalysis())) Console.WriteLine("constraint analysis");
			if(!osalWriter.setLinearConstraintCoefficientAnalysis(new LinearConstraintCoefficientAnalysis())) Console.WriteLine("linearConstraintCoef analysis");
			if(!osalWriter.setQuadraticCoefficientAnalysis(new QuadraticCoefficientAnalysis())) Console.WriteLine("quadraticCoef analysis");
			if(!osalWriter.setNonlinearExpressionAnalysis(null)) Console.WriteLine("nonlinear expression analysis");
			if(!osalWriter.setNonlinearExpressionAnalysis(new NonlinearExpressionAnalysis())) Console.WriteLine("nonlinear expression analysis");
			if(!osalWriter.setNonlinearExpressionAnalysis(new NonlinearExpressionAnalysis())) Console.WriteLine("nonlinear expression analysis");
			
			string[] msOtherAnalysisNames = {"other name 0", "other name 1"};
			string[] msOtherAnalysisValues = {"other value 0", "other value 1"};
			if(!osalWriter.setOtherAnalyses(msOtherAnalysisNames, msOtherAnalysisValues, null)) Console.WriteLine("set other!");
		
			if(!osalWriter.addOtherAnalysis("other name 2", "other value 2", null)) Console.WriteLine("add other!");
			if(!osalWriter.addOtherAnalysis("other name 3", "other value 3", "other description 3")) Console.WriteLine("add other!");
			
				
			/////////////////////
			
			OSaLReader osalReader = new OSaLReader(false);
			if(!osalReader.readFile(sFileName)) Console.WriteLine("reading");
			OSAnalysis osAnalysis;
			try {
				osAnalysis = osalReader.getOSAnalysis();
				if(!osalWriter.setOSAnalysis(osAnalysis)) Console.WriteLine("set osAnalysis");
			} 
			catch (Exception e) {
				Console.WriteLine(e.Tostring());
			}	
			
			////////////////////
			//osalWriter.writeToStandardOutput();
			Console.WriteLine(osalWriter.writeToString());
			
			*/
			//test OSbLReader
			/*
			OSbLReader osblReader = new OSbLReader(false);
			Console.WriteLine(IOUtil.readStringFromFile(OSParameter.CODE_HOME + "OSRepository/test/osbl/osbl.osbl"));
			Console.WriteLine(osblReader.readFile(OSParameter.CODE_HOME + "OSRepository/test/osbl/osbl.osbl"));
			Console.WriteLine(osblReader.getBenchmarkMessage());
			Console.WriteLine(XMLUtil.createXSDateTime(osblReader.getBenchmarkTime()));
			Console.WriteLine(osblReader.getServiceName());
			Console.WriteLine(osblReader.getServiceURI());
			BenchmarkScores benchmarkScores = osblReader.getBenchmarkScores();
			if(benchmarkScores != null){
				Console.WriteLine(benchmarkScores.computation);
				Console.WriteLine(benchmarkScores.expertAssessment);
				Console.WriteLine(benchmarkScores.overall);
				Console.WriteLine(benchmarkScores.owner);
				Console.WriteLine(benchmarkScores.popularity);
				Console.WriteLine(benchmarkScores.reputation);
				Console.WriteLine(benchmarkScores.service);
				Console.WriteLine(benchmarkScores.support);
				Console.WriteLine(benchmarkScores.system);
				Console.WriteLine(benchmarkScores.userAssessment);
			}
			BenchmarkStatistics benchmarkStatistics = osblReader.getBenchmarkStatistics();
			if(benchmarkStatistics != null){
				Console.WriteLine(benchmarkStatistics.averageJobs);
				Console.WriteLine(benchmarkStatistics.averageServiceTime);
				Console.WriteLine(benchmarkStatistics.averageWaitTime);
			}
			osblReader.getOptimizationBenchmark();
			Console.WriteLine(osblReader.getOtherBenchmarkNumber());
			string sValue = osblReader.getOtherBenchmarkValueByName("ad");
			if(sValue == null) Console.WriteLine("null");
			else Console.WriteLine(sValue);
			string sDescription = osblReader.getOtherBenchmarkDescriptionByName("a");
			Console.WriteLine(sDescription);
			for(int i=0;i<osblReader.getOtherBenchmarkNumber();i++){
				Console.WriteLine(osblReader.getOtherBenchmarkNames()[i]);
				Console.WriteLine(osblReader.getOtherBenchmarkValues()[i]);
				Console.WriteLine(osblReader.getOtherBenchmarkDescriptions()[i]);
			}
			
			osblReader.writeToStandardOutput();
			*/
			//test OSbLWriter
			/*
			OSbLWriter osblWriter = new OSbLWriter();
			string sFileName = OSParameter.CODE_HOME + "OSRepository/test/osbl/osbl.osbl";
			if(!osblWriter.setBenchmarkMessage("my message")) Console.WriteLine("message!");
			//if(!osblWriter.setBenchmarkMessage("")) Console.WriteLine("message!");
			if(!osblWriter.setServiceName("my service name")) Console.WriteLine("service name");
			if(!osblWriter.setServiceURI("my service uri")) Console.WriteLine("uri");
			if(!osblWriter.setBenchmarkTime(new DateTime(1970, 1, 1, 0, 0, 0))) Console.WriteLine("time!");
			BenchmarkScores benchmarkScores = new BenchmarkScores();
			benchmarkScores.computation = 1.1;
			benchmarkScores.expertAssessment = 1.2;
			benchmarkScores.overall = 1.3;
			benchmarkScores.owner = 1.4;
			benchmarkScores.popularity = 1.5;
			benchmarkScores.reputation = 1.6;
			benchmarkScores.service = 1.7;
			benchmarkScores.support = 1.8;
			benchmarkScores.system = 1.9;
			benchmarkScores.userAssessment = 2;
			if(!osblWriter.setBenchmarkScores(benchmarkScores)) Console.WriteLine("setBenchmarkScores");
			if(!osblWriter.setOptimizationBenchmark(new OptimizationBenchmark())) Console.WriteLine("setOptimizationBenchmark");
			BenchmarkStatistics benchmarkStatistics = new BenchmarkStatistics();
			benchmarkStatistics.averageJobs = 3.1;
			benchmarkStatistics.averageServiceTime = 3.2;
			benchmarkStatistics.averageWaitTime = 3.3;
			if(!osblWriter.setBenchmarkStatistics(benchmarkStatistics)) Console.WriteLine("setBenchmarkStatistics");
			
			string[] msOtherBenchmarkNames = {"other name 0", "other name 1"};
			string[] msOtherBenchmarkValues = {"other value 0", "other value 1"};
			if(!osblWriter.setOtherBenchmarks(msOtherBenchmarkNames, msOtherBenchmarkValues, null)) Console.WriteLine("set other!");
		
			if(!osblWriter.addOtherBenchmark("other name 2", "other value 2", null)) Console.WriteLine("add other!");
			if(!osblWriter.addOtherBenchmark("other name 3", "other value 3", "other description 3")) Console.WriteLine("add other!");

			////////////////////
			
			OSbLReader osblReader = new OSbLReader(false);
			if(!osblReader.readFile(sFileName)) Console.WriteLine("reading");
			OSBenchmark osBenchmark;
			try {
				osBenchmark = osblReader.getOSBenchmark();
				if(!osblWriter.setOSBenchmark(osBenchmark)) Console.WriteLine("set osBenchmark");
			} 
			catch (Exception e) {
				Console.WriteLine(e.Tostring());
			}
			////////////////////
			
			//osblWriter.writeToStandardOutput();
			Console.WriteLine(osblWriter.writeToString());
			*/
			//test OSeLReader
			/*
			OSeLReader oselReader = new OSeLReader(false);
			Console.WriteLine(IOUtil.readStringFromFile(OSParameter.CODE_HOME + "OSRepository/test/osel/osel.osel"));
			Console.WriteLine(oselReader.readFile(OSParameter.CODE_HOME + "OSRepository/test/osel/osel.osel"));
			Console.WriteLine(oselReader.getMessage());
			Console.WriteLine(XMLUtil.createXSDateTime(oselReader.getRegistrationDate()));
			Console.WriteLine(oselReader.getServiceName());
			Console.WriteLine(oselReader.getServiceURI());
			Console.WriteLine(oselReader.getLicenseRequired());
			Console.WriteLine(oselReader.getUserNameRequired());
			Console.WriteLine(oselReader.getPasswordRequired());
			Console.WriteLine(oselReader.getOwner().names);
			Console.WriteLine(oselReader.getOwner().contact);
			Console.WriteLine(oselReader.getKeyWords()==null?0:oselReader.getKeyWords().Length
				);
			Link[] links = oselReader.getLinks();
			Console.WriteLine(links==null?null:(links[0]).value);
			Console.WriteLine(oselReader.getSystemDescription());
			Console.WriteLine(oselReader.getSystemDedication());
			Console.WriteLine(oselReader.getSystemHardwareInfo().busSpeed);
			Console.WriteLine(oselReader.getSystemHardwareInfo().cpuNumber);
			Console.WriteLine(oselReader.getServiceDescription());
			Console.WriteLine(oselReader.getServiceType());
			Console.WriteLine(oselReader.getServiceCategory());
			Console.WriteLine(oselReader.getServiceSoftwareDescription());
			Console.WriteLine(oselReader.getServiceAlgorithmDescription());
			Console.WriteLine(oselReader.getServiceWebPage());
			Console.WriteLine(oselReader.getServiceWSDLLocation());
			Console.WriteLine(oselReader.getServiceLogoImageLink());
			Console.WriteLine(oselReader.getDefaultOptionNamesAndValues());
			Console.WriteLine(oselReader.getOptimizationDescription());
			Console.WriteLine("**************option***************");
			OSOption osOption = oselReader.getDefaultOptionNamesAndValues();
			if(osOption != null){
				Console.WriteLine(osOption.getConstraintNumber());
				Console.WriteLine(osOption.getJobMaxTime());
			}
			Console.WriteLine("**************option***************");			
			Console.WriteLine(oselReader.getOptimizationObjectiveType());
			Console.WriteLine(oselReader.getOptimizationConstraintType());
			Console.WriteLine(oselReader.getOptimizationObjectiveLinearity());
			Console.WriteLine(oselReader.getOptimizationConstraintLinearity());
			Console.WriteLine(oselReader.getOptimizationObjectiveDifferentiability());
			Console.WriteLine(oselReader.getOptimizationConstraintDifferentiability());
			Console.WriteLine(oselReader.getOptimizationParameterType());
			Console.WriteLine(oselReader.getOptimizationStochasticity());
			Console.WriteLine(oselReader.getOptimizationRealTime());
			Console.WriteLine(oselReader.getOptimizationFunctionType().probability);
			Console.WriteLine(oselReader.getOptimizationFunctionType().basic);
			Console.WriteLine(oselReader.getOptimizationSpecialStructure().coneProgram);
			Console.WriteLine(oselReader.getOptimizationSpecialStructure().disjunctiveProgram);
			Console.WriteLine(oselReader.getOptimizationSpecialAlgorithm().dynamicProgramming);
			Console.WriteLine(oselReader.getOptimizationSpecialAlgorithm().globalOptimization);
			Console.WriteLine(oselReader.getOtherEntityInfoNumber());
			string sValue = oselReader.getOtherEntityInfoValueByName("ad");
			if(sValue == null) Console.WriteLine("null");
			else Console.WriteLine(sValue);
			string sDescription = oselReader.getOtherEntityDescriptionByName("a");
			Console.WriteLine(sDescription);
			for(int i=0;i<oselReader.getOtherEntityInfoNumber();i++){
				Console.WriteLine(oselReader.getOtherEntityInfoNames()[i]);
				Console.WriteLine(oselReader.getOtherEntityInfoValues()[i]);
				Console.WriteLine(oselReader.getOtherEntityDescriptions()[i]);
			}
			

			oselReader.writeToStandardOutput();
			*/
			//test OSeLWriter
			/*
			OSeLWriter oselWriter = new OSeLWriter();
			string sFileName = OSParameter.CODE_HOME + "OSRepository/test/osel/osel.osel";
			
			if(!oselWriter.setMessage("my message")) Console.WriteLine("message!");
			if(!oselWriter.setMessage("")) Console.WriteLine("message!");
			if(!oselWriter.setServiceName("my service name")) Console.WriteLine("service name");
			if(!oselWriter.setServiceURI("my service uri")) Console.WriteLine("uri");
			if(!oselWriter.setRegistrationDate(new DateTime(1970, 1, 1, 0, 0, 0))) Console.WriteLine("time!");
			
			if(!oselWriter.setLicenseRequired(false))Console.WriteLine("setLicenseRequired Unsuccessful");
			if(!oselWriter.setUserNameRequired(true)) Console.WriteLine("setUserNameRequired Unsuccessful");
			if(!oselWriter.setPasswordRequired(true)) Console.WriteLine("setPasswordRequired Unsuccessful");
			AccessLimits accessLimits = new AccessLimits();
			accessLimits.maxBinaryVariables = 8888;
			if(!oselWriter.setAccessLimits(accessLimits)) Console.WriteLine("setAccessLimits Unsuccessful");
			Owner owner = new Owner();
			owner.names = "Jun Ma";
			owner.description = "cool person";
			if(!oselWriter.setOwner(owner)) Console.WriteLine("setOwner Unsuccessful");
			string[] keyWords = new string[2];
			keyWords[0] = "key0";
			keyWords[1] = "key1";
			if(!oselWriter.setKeyWords(keyWords))Console.WriteLine("setKeyWords Unsuccessful");
			Link[] links = new Link[2];
			links[0] = new Link();
			links[0].description = "";
			links[0].type = "service";
			links[0].value = "http://yahoo.com";
			links[1] = new Link();
			links[1].description = "description 1";
			links[1].type = "service";
			links[1].value = "http://google.com";
			if(!oselWriter.setLinks(links)) Console.WriteLine("setLinks Unsuccessful");
			if(!oselWriter.setSystemDescription("systemDescription"))Console.WriteLine("setSystemDescription Unsuccessful");
			if(!oselWriter.setSystemDedication(0.3)) Console.WriteLine("setSystemDedication Unsuccessful");
			HardwareInfo systemHardwareInfo = new HardwareInfo();
			systemHardwareInfo.busSpeed = 1.2;
			systemHardwareInfo.cpuNumber = 2;
			systemHardwareInfo.cpuSpeed = 3.4;
			systemHardwareInfo.diskSpace = 4.5;
			systemHardwareInfo.downloadSpeed = 5;
			systemHardwareInfo.memorySize = 4.5;
			systemHardwareInfo.nicSpeed = 4.6;
			systemHardwareInfo.uploadSpeed = 6.7;
			if(!oselWriter.setSystemHardwareInfo(systemHardwareInfo)) Console.WriteLine("setSystemHardwareInfo Unsuccessful");
			if(!oselWriter.setServiceDescription("serviceDescription")) Console.WriteLine("setServiceDescription Unsuccessful");
			if(!oselWriter.setServiceType("solver")) Console.WriteLine("setServiceType Unsuccessful");
			if(!oselWriter.setServiceCategory("education")) Console.WriteLine("setServiceCategory Unsuccessful");
			if(!oselWriter.setServiceSoftwareDescription("serviceSoftwareDescription")) Console.WriteLine("setServiceSoftwareDescription Unsuccessful");
			if(!oselWriter.setServiceAlgorithmDescription("serviceAlgorithmDescription")) Console.WriteLine("setServiceAlgorithmDescription Unsuccessful");
			if(!oselWriter.setServiceWebPage("serviceWebPage")) Console.WriteLine("setServiceWebPage Unsuccessful");
			if(!oselWriter.setServiceWSDLLocation("serviceWSDLLocation")) Console.WriteLine("setServiceWSDLLocation Unsuccessful");
			if(!oselWriter.setServiceLogoImageLink("serviceLogoImageLink")) Console.WriteLine("setServiceLogoImageLink Unsuccessful");
			/////////////////option///////////////////
			OSOption defaultOptionNamesAndValues = new OSOption();
			defaultOptionNamesAndValues.setConstraintNumber(3);
			if(!oselWriter.setDefaultOptionNamesAndValues(defaultOptionNamesAndValues)) Console.WriteLine("setDefaultOptionNamesAndValues Unsuccessful");
			/////////////////option///////////////////
			if(!oselWriter.setOptimizationDescription("none")) Console.WriteLine("setOptimizationDescription Unsuccessful");
			if(!oselWriter.setOptimizationVariableType("continuous")) Console.WriteLine("setOptimizationVariableType Unsuccessful");
			if(!oselWriter.setOptimizationObjectiveType("singleObjective")) Console.WriteLine("setOptimizationObjectiveType Unsuccessful");
			if(!oselWriter.setOptimizationConstraintType("generalRange")) Console.WriteLine("setOptimizationConstraintType Unsuccessful");
			if(!oselWriter.setOptimizationObjectiveLinearity("linear")) Console.WriteLine("setOptimizationObjectiveLinearity Unsuccessful");
			if(!oselWriter.setOptimizationConstraintLinearity("bound")) Console.WriteLine("setOptimizationConstraintLinearity Unsuccessful");
			if(!oselWriter.setOptimizationObjectiveDifferentiability("simulation")) Console.WriteLine("setOptimizationObjectiveDifferentiability Unsuccessful");
			if(!oselWriter.setOptimizationConstraintDifferentiability("nonContinuous")) Console.WriteLine("setOptimizationConstraintDifferentiability Unsuccessful");
			if(!oselWriter.setOptimizationParameterType("number")) Console.WriteLine("setOptimizationParameterType Unsuccessful");
			if(!oselWriter.setOptimizationStochasticity("deterministic")) Console.WriteLine("setOptimizationStochasticity Unsuccessful");
			if(!oselWriter.setOptimizationRealTime(false)) Console.WriteLine("setOptimizationRealTime Unsuccessful");
			FunctionType optimizationFunctionType = new FunctionType();
			optimizationFunctionType.probability = true;
			if(!oselWriter.setOptimizationFunctionType(optimizationFunctionType)) Console.WriteLine("setOptimizationFunctionType Unsuccessful");
			SpecialStructure optimizationSpecialStructure = new SpecialStructure();
			optimizationSpecialStructure.disjunctiveProgram = true;
			if(!oselWriter.setOptimizationSpecialStructure(optimizationSpecialStructure)) Console.WriteLine("setOptimizationSpecialStructure Unsuccessful");
			SpecialAlgorithm optimizationSpecialAlgorithm = new SpecialAlgorithm();
			optimizationSpecialAlgorithm.dynamicProgramming = true;
			if(!oselWriter.setOptimizationSpecialAlgorithm(optimizationSpecialAlgorithm)) Console.WriteLine("setOptimizationSpecialAlgorithm Unsuccessful");
			string[] msOtherEntityNames = {"other name 0", "other name 1"};
			string[] msOtherEntityValues = {"other value 0", "other value 1"};
			if(!oselWriter.setOtherEntityInfo(msOtherEntityNames, msOtherEntityValues, null)) Console.WriteLine("set other!");
		
			if(!oselWriter.addOtherEntityInfo("other name 2", "other value 2", null)) Console.WriteLine("add other!");
			if(!oselWriter.addOtherEntityInfo("other name 3", "other value 3", "other description 3")) Console.WriteLine("add other!");
			
			////////////////////
			
			OSeLReader oselReader = new OSeLReader(false);
			if(!oselReader.readFile(sFileName)) Console.WriteLine("reading");
			OSEntity osEntity;
			try {
				osEntity = oselReader.getOSEntity();
				if(!oselWriter.setOSEntity(osEntity)) Console.WriteLine("set osEntity");
			} 
			catch (Exception e) {
				Console.WriteLine(e.Tostring());
			}
			////////////////////
			
			//oselWriter.writeToStandardOutput();
			Console.WriteLine(oselWriter.writeToString());
			*/
			//test OSoLReader
			/*
			OSoLReader osolReader = new OSoLReader(false);
			Console.WriteLine(IOUtil.readStringFromFile(OSParameter.CODE_HOME + "OSRepository/test/osol/osol.osol"));
			Console.WriteLine(osolReader.readFile(OSParameter.CODE_HOME + "OSRepository/test/osol/osol.osol"));
			Console.WriteLine(osolReader.getServiceName());
			Console.WriteLine(osolReader.getServiceURI());
			Console.WriteLine(osolReader.getInstanceName());		
			Console.WriteLine(osolReader.getJobID());		
			Console.WriteLine(osolReader.getLicense());		
			Console.WriteLine(osolReader.getUserName());		
			Console.WriteLine(osolReader.getPassword());		
			Console.WriteLine(osolReader.getContactTransportType());		
			Console.WriteLine(osolReader.getContactAddress());		
			Console.WriteLine(osolReader.getSystemMinDiskSpace());		
			Console.WriteLine(osolReader.getSystemMinMemorySize());		
			Console.WriteLine(osolReader.getSystemMinCPUSpeed());		
			Console.WriteLine(osolReader.getServiceType());		
			Console.WriteLine(osolReader.getJobMaxTime());		
			Console.WriteLine(XMLUtil.createXSDateTime(osolReader.getJobScheduledStartTime()));		
			string[] msJobs = osolReader.getJobDependencies();
			Console.WriteLine(msJobs==null?"null":msJobs[0]);		
			Console.WriteLine(osolReader.getVariableNumber());		
			Console.WriteLine(osolReader.getObjectiveNumber());		
			Console.WriteLine(osolReader.getConstraintNumber());	
			double[] mdInitValues = osolReader.getInitialVariableValues();
			Console.WriteLine(mdInitValues==null?"NULL":mdInitValues[0]+"");		

			Console.WriteLine(osolReader.getOtherOptionNumber());
			string sValue = osolReader.getOtherOptionValueByName("ad");
			if(sValue == null) Console.WriteLine("null");
			else Console.WriteLine(sValue);
			string sDescription = osolReader.getOtherOptionDescriptionByName("a");
			Console.WriteLine(sDescription);
			for(int i=0;i<osolReader.getOtherOptionNumber();i++){
				Console.WriteLine(osolReader.getOtherOptionNames()[i]);
				Console.WriteLine(osolReader.getOtherOptionValues()[i]);
				Console.WriteLine(osolReader.getOtherOptionDescriptions()[i]);
			}
			osolReader.writeToStandardOutput();
			*/
			//test OSoLWriter
			/*
			OSoLWriter osolWriter = new OSoLWriter();
			string sFileName = OSParameter.CODE_HOME + "OSRepository/test/osol/osol.osol";

			if(!osolWriter.setServiceName("my service name")) Console.WriteLine("service name");
			if(!osolWriter.setServiceURI("my service uri")) Console.WriteLine("uri");

			if(!osolWriter.setInstanceName("instanceName")) Console.WriteLine("setInstanceName Unsuccessful");		
			if(!osolWriter.setJobID("jobID")) Console.WriteLine("setJobID Unsuccessful");		
			if(!osolWriter.setLicense("license")) Console.WriteLine("setLicense Unsuccessful");		
			if(!osolWriter.setUserName("userName")) Console.WriteLine("setUserName Unsuccessful");		
			if(!osolWriter.setPassword("password")) Console.WriteLine("setPassword Unsuccessful");		
			if(!osolWriter.setContactTransportType("smtp")) Console.WriteLine("setContactTransportType Unsuccessful");		
			if(!osolWriter.setContactAddress("contactAddress")) Console.WriteLine("setContactAddress Unsuccessful");		
			if(!osolWriter.setSystemMinDiskSpace(10)) Console.WriteLine("setSystemMinDiskSpace Unsuccessful");		
			if(!osolWriter.setSystemMinMemorySize(20)) Console.WriteLine("setSystemMinMemorySize Unsuccessful");		
			if(!osolWriter.setSystemMinCPUSpeed(30)) Console.WriteLine("setSystemMinCPUSpeed Unsuccessful");		
			if(!osolWriter.setServiceType("solver")) Console.WriteLine("setServiceType Unsuccessful");		
			if(!osolWriter.setJobMaxTime(9999)) Console.WriteLine("setJobMaxTime Unsuccessful");		
			if(!osolWriter.setJobScheduledStartTime(new DateTime(1970, 1, 1, 0, 0, 0))) Console.WriteLine("setJobScheduledStartTime Unsuccessful");		
			string[] jobDependencies = {"a1", "b3"};
			if(!osolWriter.setJobDependencies(jobDependencies)) Console.WriteLine("setJobDependencies Unsuccessful");		
			if(!osolWriter.setVariableNumber(3)) Console.WriteLine("setVariableNumber Unsuccessful");		
			if(!osolWriter.setObjectiveNumber(3)) Console.WriteLine("setObjectiveNumber Unsuccessful");		
			if(!osolWriter.setConstraintNumber(2)) Console.WriteLine("setConstraintNumber Unsuccessful");		
			double[] initialVariableValues = {1, 2, 3};
			if(!osolWriter.setInitialVariableValues(initialVariableValues)) Console.WriteLine("setInitialVariableValues Unsuccessful");		

			
			
			string[] msOtherOptionNames = {"other name 0", "other name 1"};
			string[] msOtherOptionValues = {"other value 0", "other value 1"};
			if(!osolWriter.setOtherOptions(msOtherOptionNames, msOtherOptionValues, null)) Console.WriteLine("set other!");
		
			if(!osolWriter.addOtherOption("other name 2", "other value 2", null)) Console.WriteLine("add other!");
			if(!osolWriter.addOtherOption("other name 3", "other value 3", "other description 3")) Console.WriteLine("add other!");

			////////////////////
			
			OSoLReader osolReader = new OSoLReader(false);
			if(!osolReader.readFile(sFileName)) Console.WriteLine("reading");
			OSOption osOption;
			try {
				osOption = osolReader.getOSOption();
				if(!osolWriter.setOSOption(osOption)) Console.WriteLine("set osOption");
			} 
			catch (Exception e) {
				Console.WriteLine(e.Tostring());
			}
			////////////////////
			
			//osolWriter.writeToStandardOutput();
			Console.WriteLine(osolWriter.writeToString());
			*/

			//test OSpLReader
			/*
			OSpLReader osplReader = new OSpLReader(false);
			Console.WriteLine(IOUtil.readStringFromFile(OSParameter.CODE_HOME + "OSRepository/test/ospl/ospl.ospl"));
			Console.WriteLine(osplReader.readFile(OSParameter.CODE_HOME + "OSRepository/test/ospl/ospl.ospl"));
			Console.WriteLine(osplReader.getRequestAction());
			Console.WriteLine(osplReader.getRequestDescription());
			Console.WriteLine(osplReader.getResponseStatus());
			Console.WriteLine(osplReader.getResponseDescription());
		
			Console.WriteLine(osplReader.getProcessMessage());
			Console.WriteLine(XMLUtil.createXSDateTime(osplReader.getProcessTime()));
			Console.WriteLine(osplReader.getServiceName());
			Console.WriteLine(osplReader.getServiceURI());
		
			Console.WriteLine(osplReader.getCurrentState());
			Console.WriteLine(osplReader.getAvailableDiskSpace());
			Console.WriteLine(osplReader.getAvailableMemory());
			Console.WriteLine(osplReader.getCurrentJobCount());
			Console.WriteLine(osplReader.getTotalJobsSoFar());
			Console.WriteLine(XMLUtil.createXSDateTime(osplReader.getTimeLastJobEnded()));
			Console.WriteLine(XMLUtil.createXSDateTime(osplReader.getTimeServiceStarted()));
			Console.WriteLine(osplReader.getTimeLastJobTook());
			Console.WriteLine(osplReader.getServiceUtilization());
			ProcessStatistics processStatistics = osplReader.getProcessStatistics();
			Console.WriteLine(processStatistics.currentState);
			Console.WriteLine(processStatistics.availableDiskSpace);
			Console.WriteLine(processStatistics.availableMemory);
			Console.WriteLine(processStatistics.currentJobCount);
			Console.WriteLine(processStatistics.totalJobsSoFar);
			Console.WriteLine(XMLUtil.createXSDateTime(processStatistics.timeLastJobEnded));
			Console.WriteLine(XMLUtil.createXSDateTime(processStatistics.timeServiceStarted));
			Console.WriteLine(processStatistics.timeLastJobTook);
			Console.WriteLine(processStatistics.serviceUtilization);
			Jobs jobs = processStatistics.jobs;
			if(jobs != null){
				JobStatistics[] mJobStatistics = jobs.job;
				int iJobStatistics = mJobStatistics==null?0:mJobStatistics.Length; 
				if(iJobStatistics > 0){
					Console.WriteLine(iJobStatistics);
					Console.WriteLine(mJobStatistics[0].jobID);
					Console.WriteLine(mJobStatistics[0].duration);
					if(mJobStatistics[0].dependencies != null)
						Console.WriteLine(mJobStatistics[0].dependencies.jobID[0]);
				}
			}
		
			OptimizationProcess optimizationProcess = osplReader.getOptimizationProcess();
			int iJobOptimization = (optimizationProcess == null || optimizationProcess.job == null)?0:optimizationProcess.job.Length; 
			if(iJobOptimization > 0){
				Console.WriteLine(iJobOptimization);
				Console.WriteLine(optimizationProcess.job[0].jobID);
			}
			Console.WriteLine(osplReader.getOtherProcessNumber());
			string sValue = osplReader.getOtherProcessValueByName("ad");
			if(sValue == null) Console.WriteLine("null");
			else Console.WriteLine(sValue);
			string sDescription = osplReader.getOtherProcessDescriptionByName("a");
			Console.WriteLine(sDescription);
			for(int i=0;i<osplReader.getOtherProcessNumber();i++){
				Console.WriteLine(osplReader.getOtherProcessNames()[i]);
				Console.WriteLine(osplReader.getOtherProcessValues()[i]);
				Console.WriteLine(osplReader.getOtherProcessDescriptions()[i]);
			}
		

			osplReader.writeToStandardOutput();
			*/
			//test OSpLWriter
			/*
			OSpLWriter osplWriter = new OSpLWriter();
			string sFileName = OSParameter.CODE_HOME + "OSRepository/test/ospl/ospl.ospl";

			if(!osplWriter.setRequestAction("getAll")) Console.WriteLine("setRequestAction!");
			if(!osplWriter.setRequestAction("setAll")) Console.WriteLine("setRequestAction!");
			if(!osplWriter.setRequestDescription("setRequestDescription")) Console.WriteLine("setRequestAction!");
			if(!osplWriter.setResponseStatus("success")) Console.WriteLine("setResponseStatus!");
			if(!osplWriter.setResponseDescription("successfully done")) Console.WriteLine("setResponseDescription!");
			
			if(!osplWriter.setProcessMessage("my message")) Console.WriteLine("message!");
			if(!osplWriter.setProcessMessage("")) Console.WriteLine("message!");
			if(!osplWriter.setServiceURI("my uri")) Console.WriteLine("serviceURI!");
			if(!osplWriter.setServiceName("my name")) Console.WriteLine("serviceName!");
			if(!osplWriter.setProcessTime(DateTime.Now)) Console.WriteLine("time!");
			
			if(!osplWriter.setCurrentState("busy")) Console.WriteLine("setCurrentState!");
			if(!osplWriter.setAvailableDiskSpace(1.2)) Console.WriteLine("setAvailableDiskSpace!");
			if(!osplWriter.setAvailableMemory(3.4)) Console.WriteLine("setAvailableMemory!");
			if(!osplWriter.setCurrentJobCount(0)) Console.WriteLine("setCurrentJobCount!");
			if(!osplWriter.setTotalJobsSoFar(100)) Console.WriteLine("setTotalJobsSoFar!");
			if(!osplWriter.setTimeLastJobEnded(new DateTime(2006, 1, 31, 15, 3, 4))) Console.WriteLine("setTimeLastJobEnded!");
			if(!osplWriter.setTimeLastJobTook(200.4)) Console.WriteLine("setTimeLastJobTook!");
			if(!osplWriter.setTimeServiceStarted(new DateTime(2003, 1, 31, 15, 3, 4))) Console.WriteLine("setTimeServiceStarted!");
			if(!osplWriter.setServiceUtilization(1.3)) Console.WriteLine("setServiceUtilization!");
			JobStatistics[] jobstatistics = new JobStatistics[2];
			jobstatistics[0] = new JobStatistics();
			jobstatistics[1] = new JobStatistics();
			jobstatistics[0].jobID = "job0000";
			jobstatistics[1].jobID = "job1111";
			jobstatistics[0].duration = 2.3;
			jobstatistics[0].startTime = new DateTime(2006, 1, 3);
			jobstatistics[0].endTime = new DateTime(2006, 1, 4);
			jobstatistics[0].scheduledStartTime = new DateTime(2006, 1, 3);
			jobstatistics[0].state = "running";
			JobDependencies dependencies = new JobDependencies();
			dependencies.jobID = new string[2];
			dependencies.jobID[0] = "333";
			dependencies.jobID[1] = "aaa";
			jobstatistics[0].dependencies = dependencies;
			
			if(!osplWriter.setJobStatistics(jobstatistics)) Console.WriteLine("setJobStatistics!");

//			ProcessStatistics processStatistics = new ProcessStatistics();
//			processStatistics.jobs = new Jobs();
//			processStatistics.jobs.job = jobstatistics;
//			if(!osplWriter.setProcessStatistics(processStatistics)) Console.WriteLine("setJobStatistics!");
			
//			JobOptimization[] mJobOptimization = new JobOptimization[1];
//			mJobOptimization[0] = new JobOptimization();
//			mJobOptimization[0].jobID = "88888";
//			mJobOptimization[0].osrl = new OSResult();
//			if(!osplWriter.setOptimizationProcess(mJobOptimization)) Console.WriteLine("setJobStatistics!");

			string[] msOtherProcessNames = {"other name 0", "other name 1"};
			string[] msOtherProcessValues = {"other value 0", "other value 1"};
			if(!osplWriter.setOtherProcesses(msOtherProcessNames, msOtherProcessValues, null)) Console.WriteLine("set other!");
		
			
			if(!osplWriter.addOtherProcess("other name 2", "other value 2", null)) Console.WriteLine("add other!");
			if(!osplWriter.addOtherProcess("other name 3", "other value 3", "other description 3")) Console.WriteLine("add other!");
			
			////////////////////

//			OSpLReader osplReader = new OSpLReader(false);
//			if(!osplReader.readFile(sFileName)) Console.WriteLine("reading");
//			OSProcess osProcess;
//			try {
//				osProcess = osplReader.getOSProcess();
//				if(!osplWriter.setOSProcess(osProcess)) Console.WriteLine("set osProcess");
//			} 
//			catch (Exception e) {
//				Console.WriteLine(e.Tostring());
//			}
			////////////////////
			
			//osplWriter.writeToStandardOutput();
			Console.WriteLine(osplWriter.writeToString());
			*/
			//test OSqLReader
			/*
			OSqLReader osqlReader = new OSqLReader(false);
			Console.WriteLine(IOUtil.readStringFromFile(OSParameter.CODE_HOME + "OSRepository/test/osql/osql.osql"));
			Console.WriteLine(osqlReader.readFile(OSParameter.CODE_HOME + "OSRepository/test/osql/osql.osql"));
			Console.WriteLine(osqlReader.getXQuery());
			StandardQuery q = osqlReader.getStandardQuery();
			Console.WriteLine(q.currentState);
			if(q.optimization != null){
				Console.WriteLine(q.optimization.variableType);	
				Console.WriteLine(q.optimization.constraintDifferentiability);	
				Console.WriteLine(q.optimization.constraintType);	
				Console.WriteLine(q.optimization.objectiveLinearity);	
				if(q.optimization.functionType != null){
					Console.WriteLine(q.optimization.functionType.arithmetic);
					Console.WriteLine(q.optimization.functionType.probability);
					Console.WriteLine(q.optimization.functionType.statistics);
				}
				if(q.optimization.specialStructure != null){
					Console.WriteLine(q.optimization.specialStructure.disjunctiveProgram);
					Console.WriteLine(q.optimization.specialStructure.coneProgram);
				}
				if(q.optimization.specialAlgorithm != null){
					Console.WriteLine(q.optimization.specialAlgorithm.globalOptimization);
					Console.WriteLine(q.optimization.specialAlgorithm.decomposition);
				}
			}
			
			osqlReader.writeToStandardOutput();
			*/
			//test OSqLWriter
			/*
			OSqLWriter osqlWriter = new OSqLWriter();
			string sFileName = OSParameter.CODE_HOME + "OSRepository/test/osql/osql.osql";

			if(!osqlWriter.setXQuery("xQuery xQuery xQuery")) Console.WriteLine("setXQuery!");
			StandardQuery q = new StandardQuery();
			q.currentState = "busy";
			OptimizationInfo opt = new OptimizationInfo();
			opt.constraintType = "generalRange";
			opt.variableType = "mixedInteger";
			opt.objectiveLinearity = "linear";
			opt.functionType = new FunctionType();
			opt.functionType.probability = true;
			opt.specialAlgorithm = new SpecialAlgorithm();
			opt.specialAlgorithm.decomposition = true;
			opt.specialStructure = new SpecialStructure();
			opt.specialStructure.disjunctiveProgram = true;
			q.optimization = opt;
			if(!osqlWriter.setStandardQuery(q)) Console.WriteLine("setStandardQuery!");
		
			////////////////////
			
			OSqLReader osqlReader = new OSqLReader(false);
			if(!osqlReader.readFile(sFileName)) Console.WriteLine("reading");
			OSQuery osQuery;
			try {
				osQuery = osqlReader.getOSQuery();
				if(!osqlWriter.setOSQuery(osQuery)) Console.WriteLine("set OSQuery");
			} 
			catch (Exception e) {
				Console.WriteLine(e.Tostring());
			}
			////////////////////
			
			//osqlWriter.writeToStandardOutput();
			Console.WriteLine(osqlWriter.writeToString());
			*/
			//test OSsLReader
			/*
			OSsLReader osslReader = new OSsLReader(false);
			Console.WriteLine(IOUtil.readStringFromFile(OSParameter.CODE_HOME + "OSRepository/test/ossl/ossl.ossl"));
			Console.WriteLine(osslReader.readFile(OSParameter.CODE_HOME + "OSRepository/test/ossl/ossl.ossl"));
			Console.WriteLine(osslReader.getInputNumber());
			Console.WriteLine(osslReader.getOutputNumber());
			Console.WriteLine(osslReader.getInput());
			Console.WriteLine(osslReader.getOutputByName("d"));
			string s = osslReader.getOutputByName("g");
			Console.WriteLine(s);
			for(int i=0;i<osslReader.getInputNumber();i++){
				Console.WriteLine(osslReader.getInputNames()[i]);
				Console.WriteLine(osslReader.getInputValues()[i]);
			}
			for(int i=0;i<osslReader.getOutputNumber();i++){
				Console.WriteLine(osslReader.getOutputNames()[i]);
				Console.WriteLine(osslReader.getOutputValues()[i]);
			}
			Console.WriteLine(osslReader.replaceInputElementValue("b", "abc"));
			Console.WriteLine(osslReader.replaceOutputElementValue("g", "http://www.yahoo.com"));
			
			osslReader.writeToStandardOutput();
			*/
			//test OSsLWriter
			/*
			OSsLWriter osslWriter = new OSsLWriter();
			string sFileName = OSParameter.CODE_HOME + "OSRepository/test/ossl/ossl.ossl";
			
			string[] msInputNames = {"a", "b"};
			string[] msInputTypes = null;//{"", "link"};
			string[] msInputValues = {"aaa", "http://www.google.com"};
			
			if(!osslWriter.setInput(msInputNames, msInputTypes, msInputValues)) Console.WriteLine(1);
			if(!osslWriter.setInput(msInputNames, msInputTypes, msInputValues)) Console.WriteLine(2);
			
			string[] msOutputNames = {"c", "g"};
			string[] msOutputTypes = {"", "link"};
			string[] msOutputValues = {"ccc", "http://www.google.com"};
			
			if(!osslWriter.setOutput(msOutputNames, msOutputTypes, msOutputValues)) Console.WriteLine(3);
			if(!osslWriter.setOutput(msOutputNames, msOutputTypes, msOutputValues)) Console.WriteLine(4);
			
			osslWriter.setInputElement("x", "a", "xxx");
			osslWriter.setInputElement("x", "a", "xyz");
			
			osslWriter.setOutputElement("v", "string", "vvv");
			//osslWriter.setOutputElement("v", "string", "www");

			////////////////////

			OSsLReader osslReader = new OSsLReader(false);
			if(!osslReader.readFile(sFileName)) Console.WriteLine("reading");
			OSSimulation osSimulation;
			try {
				osSimulation = osslReader.getOSSimulation();
				if(!osslWriter.setOSSimulation(osSimulation)) Console.WriteLine("setOSSimulation");
			} 
			catch (Exception e) {
				Console.WriteLine(e.ToString());
			}
			////////////////////
			
			//osslWriter.writeToStandardOutput();
			Console.WriteLine(osslWriter.writeToString());
			*/

			//test OSuLReader
			/*
			OSuLReader osulReader = new OSuLReader(false);
			Console.WriteLine(IOUtil.readStringFromFile("../../../../OSRepository/test/osul/osul.osul"));
			Console.WriteLine(osulReader.readFile("../../../../OSRepository/test/osul/osul.osul"));
			Console.WriteLine(osulReader.getURINumber());
			string sMatchType = osulReader.getMatchTypeByURI("http://www.altova.com6");
			if(sMatchType == null) Console.WriteLine("null");
			else Console.WriteLine(sMatchType);
			for(int i=0;i<osulReader.getURINumber();i++){
				Console.WriteLine(osulReader.getURIs()[i]);
				Console.WriteLine(osulReader.getMatchTypes()[i]);
			}
			*/
			//test OSuLWriter
			/*
			OSuLWriter osulWriter = new OSuLWriter();
			//string fName = "../../../../OSRepository/test/osul/osul.osul";
			
			string[] msURIs = {"http://123", "http://abc"};
			string[] msMatchTypes = {"exact", "guess"};
		
			if(!osulWriter.setURIs(msURIs, msMatchTypes)) Console.WriteLine(2);
		
			osulWriter.addURI("http://xyz", "moreGeneral");
			osulWriter.addURI("http://xyz", "moreGeneral");
	
			////////////////////
			OSuLReader osulReader = new OSuLReader(false);
			if(!osulReader.readFile(sFileName)) Console.WriteLine("reading");
			OSURI osURI;
			try {
				osURI = osulReader.getOSURI();
				if(!osulWriter.setOSURI(osURI)) Console.WriteLine("setOSURI");
			} 
			catch (Exception e) {
				Console.WriteLine(e.ToString());
			}
			////////////////////

			osulWriter.writeToStandardOutput();
			
			*/
			//test OSRegistryReader
			/*
			OSRegistryReader osRegistryReader = new OSRegistryReader(false);
			Console.WriteLine(IOUtil.readStringFromFile(OSParameter.CODE_HOME + "OSRepository/test/osregistry/osregistry.xml"));
			Console.WriteLine(osRegistryReader.readFile(OSParameter.CODE_HOME + "OSRepository/test/osregistry/osregistry.xml"));
			Console.WriteLine(osRegistryReader.getDescription());
			Console.WriteLine(osRegistryReader.getNews()[0].value);
			Console.WriteLine(osRegistryReader.getServices()[0].osel.entityHeader.serviceName);
			Console.WriteLine(osRegistryReader.getService("xxx2").ospl.getRequestAction());
			*/
			//test OSRegistryWriter
			/*
			OSRegistryWriter osRegistryWriter = new OSRegistryWriter();
			String sFileName = OSParameter.CODE_HOME + "OSRepository/test/osregistry/osregistry.xml";
			
			if(!osRegistryWriter.setDescription("registry description")) Console.WriteLine("description!");
			for(int i = 0; i < 3; i++){
				osRegistryWriter.addNewsElement(new DateTime(2006, 1, 2, 3, 4, i), "news: " + i);
			}
			ServiceEntry service = new ServiceEntry();
			OSeLReader oselReader = new OSeLReader(false);
			String sOSeLFileName = OSParameter.CODE_HOME + "OSRepository/test/osel/osel.osel";
			if(!oselReader.readFile(sOSeLFileName)) Console.WriteLine("reading");
			OSEntity osEntity = null;
			try {
				osEntity = oselReader.getOSEntity();
			} 
			catch (Exception e) {
				Console.WriteLine(e.ToString());
			}
			service.osel = osEntity;
			
			OSpLReader osplReader = new OSpLReader(false);
			String sOSpLFileName = OSParameter.CODE_HOME + "OSRepository/test/ospl/ospl.ospl";
			if(!osplReader.readFile(sOSpLFileName)) Console.WriteLine("reading");
			OSProcess osProcess = null;
			try {
				osProcess = osplReader.getOSProcess();
			} 
			catch (Exception e) {
				Console.WriteLine(e.ToString());
			}
			service.ospl = osProcess;
			
			OSbLReader osblReader = new OSbLReader(false);
			String sOSbLFileName = OSParameter.CODE_HOME + "OSRepository/test/osbl/osbl.osbl";
			if(!osblReader.readFile(sOSbLFileName)) Console.WriteLine("reading");
			OSBenchmark osBenchmark = null;
			try {
				osBenchmark = osblReader.getOSBenchmark();
			} 
			catch (Exception e) {
				Console.WriteLine(e.ToString());
			}
			service.osbl = osBenchmark;
			osRegistryWriter.addService(service);
			service.osel.setServiceURI("xxx2");
			//osRegistryWriter.addService(service);
			
			
			////////////////////
			
			OSRegistryReader osRegistryReader = new OSRegistryReader(false);
			if(!osRegistryReader.readFile(sFileName)) Console.WriteLine("reading");
			org.optimizationservices.oscommon.localinterface.OSRegistry osRegistry;
			try {
				osRegistry = osRegistryReader.getOSRegistry();
				if(!osRegistryWriter.setOSRegistry(osRegistry)) Console.WriteLine("setOSRegistry");
			} 
			catch (Exception e) {
				Console.WriteLine(e.ToString());
			}
			
			////////////////////
			//osregistryWriter.writeToStandardOutput();
			Console.WriteLine(osRegistryWriter.writeToString());
			*/
			//test OSRepositoryReader
			/*
			OSRepositoryReader osRepositoryReader = new OSRepositoryReader(false);
			Console.WriteLine(IOUtil.readStringFromFile(OSParameter.CODE_HOME + "OSRepository/OSRepositoryTemp.xml"));
			Console.WriteLine(osRepositoryReader.readFile(OSParameter.CODE_HOME + "OSRepository/OSRepositoryTemp.xml"));
			Console.WriteLine(osRepositoryReader.getDescription());
			Console.WriteLine(osRepositoryReader.getNews()[0].value);
			Console.WriteLine(osRepositoryReader.getInstances()[0].name);
			Console.WriteLine(osRepositoryReader.getInstances().Length);
			Console.WriteLine(osRepositoryReader.getInstance("name2").source);
			OSRepositoryWriter osRepositoryWriter = new OSRepositoryWriter();
			osRepositoryWriter.setOSRepository(osRepositoryReader.getOSRepository());
			osRepositoryWriter.writeToStandardOutput();
			*/
			//test OSRepositoryWriter
			/*
			OSRepositoryWriter osRepositoryWriter = new OSRepositoryWriter();
			String sFileName = OSParameter.CODE_HOME + "OSRepository/OSRepositoryTemp.xml";
			
			if(!osRepositoryWriter.setDescription("registry description")) Console.WriteLine("description!");
			for(int i = 0; i < 3; i++){
				osRepositoryWriter.addNewsElement(new DateTime(2006, 1, 2, 3, 4, i), "news: " + i);
			}
			RepositoryInstance[] mInstance = new RepositoryInstance[3];
			for(int i = 0; i < 3; i++){
				mInstance[i] = new RepositoryInstance();
				mInstance[i].name = "name"+i;
				mInstance[i].source = "source"+i;
				mInstance[i].description = "description"+i;
				mInstance[i].originalFileName = "originalFileName"+i;
				mInstance[i].osDirectoty = "osDirectoty"+i;
				mInstance[i].osFileName = "osFileName"+i;
				osRepositoryWriter.addInstance(mInstance[i]);
			}
			
			////////////////////
			
			OSRepositoryReader osRepositoryReader = new OSRepositoryReader(false);
			if(!osRepositoryReader.readFile(sFileName)) Console.WriteLine("reading");
			OSRepository osRepository;
			try {
				osRepository = osRepositoryReader.getOSRepository();
				if(!osRepositoryWriter.setOSRepository(osRepository)) Console.WriteLine("setOSRepository");
			} 
			catch (Exception e) {
				Console.WriteLine(e.ToString());
			}
			
			////////////////////
			//osRepositoryWriter.writeToStandardOutput();
			Console.WriteLine(osRepositoryWriter.writeToString());
			*/
			//test OSParameterReader
			/*
			OSParameterReader osParameterReader = new OSParameterReader(false);
			Console.WriteLine(IOUtil.readStringFromFile(OSParameter.CODE_HOME + "OSRepository/test/osparameter/osparameter.xml"));
			Console.WriteLine(osParameterReader.readFile(OSParameter.CODE_HOME + "OSRepository/test/osparameter/osparameter.xml"));
			Console.WriteLine(osParameterReader.getOSParameterNumber());
			String sValue = osParameterReader.getOSParameterValueByName("param name 0");
			if(sValue == null) Console.WriteLine("null");
			else Console.WriteLine(sValue);
			String sDescription = osParameterReader.getOSParameterDescriptionByName("a");
			Console.WriteLine(sDescription);
			for(int i=0;i<osParameterReader.getOSParameterNumber();i++){
				Console.WriteLine(osParameterReader.getOSParameterNames()[i]);
				Console.WriteLine(osParameterReader.getOSParameterValues()[i]);
				Console.WriteLine(osParameterReader.getOSParameterDescriptions()[i]);
			}
			*/
			//test OSParameterWriter
			/*
			OSParameterWriter osParameterWriter = new OSParameterWriter();
			//String sFileName = OSParameter.CODE_HOME + "OSRepository/test/osparameter/osparameter.xml";
			String[] msOSParameterNames = {"param name 0", "param name 1"};
			String[] msOSParameterValues = {"param value 0", "param value 1"};
			if(!osParameterWriter.setOSParameters(msOSParameterNames, msOSParameterValues, null)) Console.WriteLine("set param!");
		
			if(!osParameterWriter.addOSParameter("param name 2", "param value 2", null)) Console.WriteLine("add param!");
			if(!osParameterWriter.addOSParameter("param name 3", "param value 3", "param description 3")) Console.WriteLine("add param!");
			Console.WriteLine(osParameterWriter.writeToString());
			*/
			//test OSrLReader
			/*
			OSrLReader osrlReader = new OSrLReader(false);
			Console.WriteLine(IOUtil.readStringFromFile(OSParameter.CODE_HOME + "OSRepository/test/osrl/osrl.osrl"));
			Console.WriteLine(osrlReader.readFile(OSParameter.CODE_HOME + "OSRepository/test/osrl/osrl.osrl"));
			
			Console.WriteLine(osrlReader.getGeneralMessage());
			Console.WriteLine(osrlReader.getJobID());
			GeneralStatus status = osrlReader.getGeneralStatus();
			Console.WriteLine(status.type);
			Console.WriteLine(status.description);
			int iSubstatus = status.substatus==null?0:status.substatus.Length;
			for(int i = 0; i < iSubstatus; i++){
				Console.WriteLine(status.substatus[i].name);
				Console.WriteLine(status.substatus[i].description);
				Console.WriteLine(status.substatus[i].value);			
			}
			Console.WriteLine(XMLUtil.createXSDateTime(osrlReader.getResultTime()));
			Console.WriteLine(osrlReader.getInstanceName());
			Console.WriteLine(osrlReader.getServiceName());
			Console.WriteLine(osrlReader.getServiceURI());

			
			Console.WriteLine(osrlReader.getOtherResultNumber());
			String sValue = osrlReader.getOtherResultValueByName("ad");
			if(sValue == null) Console.WriteLine("null");
			else Console.WriteLine(sValue);
			String sDescription = osrlReader.getOtherResultDescriptionByName("a");
			Console.WriteLine(sDescription);
			for(int i=0;i<osrlReader.getOtherResultNumber();i++){
				Console.WriteLine(osrlReader.getOtherResultNames()[i]);
				Console.WriteLine(osrlReader.getOtherResultValues()[i]);
				Console.WriteLine(osrlReader.getOtherResultDescriptions()[i]);
			}
			
			Console.WriteLine("get process stat");
			Console.WriteLine(osrlReader.getCurrentState());
			Console.WriteLine(osrlReader.getAvailableDiskSpace());
			Console.WriteLine(osrlReader.getAvailableMemory());
			Console.WriteLine(osrlReader.getCurrentJobCount());
			Console.WriteLine(osrlReader.getTotalJobsSoFar());
			Console.WriteLine(XMLUtil.createXSDateTime(osrlReader.getTimeLastJobEnded()));
			Console.WriteLine(XMLUtil.createXSDateTime(osrlReader.getTimeServiceStarted()));
			Console.WriteLine(osrlReader.getTimeLastJobTook());
			Console.WriteLine(osrlReader.getServiceUtilization());
			ProcessStatistics processStatistics = osrlReader.getProcessStatistics();
			Console.WriteLine(processStatistics.currentState);
			Console.WriteLine(processStatistics.availableDiskSpace);
			Console.WriteLine(processStatistics.availableMemory);
			Console.WriteLine(processStatistics.currentJobCount);
			Console.WriteLine(processStatistics.totalJobsSoFar);
			Console.WriteLine(XMLUtil.createXSDateTime(processStatistics.timeLastJobEnded));
			Console.WriteLine(XMLUtil.createXSDateTime(processStatistics.timeServiceStarted));
			Console.WriteLine(processStatistics.timeLastJobTook);
			Console.WriteLine(processStatistics.serviceUtilization);
			Jobs jobs = processStatistics.jobs;
			if(jobs != null){
				JobStatistics[] mJobStatistics = jobs.job;
				int iJobStatistics = mJobStatistics==null?0:mJobStatistics.Length; 
				if(iJobStatistics > 0){
					Console.WriteLine(iJobStatistics);
					Console.WriteLine(mJobStatistics[0].jobID);
					Console.WriteLine(mJobStatistics[0].duration);
					if(mJobStatistics[0].dependencies != null)
					Console.WriteLine(mJobStatistics[0].dependencies.jobID[0]);
				}
			}
			
			
			Console.WriteLine(osrlReader.getVariableNumber());	
			Console.WriteLine(osrlReader.getObjectiveNumber());
			Console.WriteLine(osrlReader.getConstraintNumber());
			Console.WriteLine(osrlReader.getSolutionNumber());
			for(int i = 0; i < osrlReader.getSolutionNumber(); i++){
				Console.WriteLine("************solution: " + i);
				Console.WriteLine(osrlReader.getSolutionStatusType(i));			
				Console.WriteLine(osrlReader.getSolutionStatusDescription(i));			
				Console.WriteLine(osrlReader.getSolutionStatusDescription(i));			
				Console.WriteLine(osrlReader.getSolutionObjectiveIndex(i));			
				Console.WriteLine(osrlReader.getSolutionMessage(i));	
				OptimizationSolutionSubstatus[] substatus = osrlReader.getSolutionSubStatuses(i);
				Console.WriteLine("sub # " + (substatus==null?0:substatus.Length));
				OptimizationSolutionStatus optStatus = osrlReader.getSolutionStatus(i);
				Console.WriteLine(optStatus.type);
				Console.WriteLine(osrlReader.getVariableValues(i)[0]);
				Console.WriteLine(osrlReader.getVariableStringValues(i)[0]);
				OtherVariableResult[] otherVar = osrlReader.getOtherVariableResults(i);
				if(otherVar != null){
					Console.WriteLine(otherVar.Length);
					Console.WriteLine(otherVar[0].name);
					Console.WriteLine(otherVar[0].value);
					Console.WriteLine(otherVar[0].description);
					Console.WriteLine(otherVar[0].var[0].idx);
					Console.WriteLine(otherVar[0].var[0].value);
				}
				Console.WriteLine(osrlReader.getObjectiveValues(i)[0]);
				OtherObjectiveResult[] otherObj = osrlReader.getOtherObjectiveResults(i);
				if(otherObj != null){
					Console.WriteLine(otherObj.Length);
					Console.WriteLine(otherObj[0].name);
					Console.WriteLine(otherObj[0].value);
					Console.WriteLine(otherObj[0].description);
					Console.WriteLine(otherObj[0].obj[0].idx);
					Console.WriteLine(otherObj[0].obj[0].value);
				}
				double[] mdValues = osrlReader.getDualVariableValues(i);
				Console.WriteLine(mdValues==null?"null":(mdValues[0]+""));

				OtherConstraintResult[] otherCon = osrlReader.getOtherConstraintResults(i);
				if(otherCon != null){
					Console.WriteLine(otherCon.Length);
					Console.WriteLine(otherCon[0].name);
					Console.WriteLine(otherCon[0].value);
					Console.WriteLine(otherCon[0].description);
					Console.WriteLine(otherCon[0].con[0].idx);
					Console.WriteLine(otherCon[0].con[0].value);
				}
				
				OtherOptimizationResult[] otherOPT = osrlReader.getOtherOptimizationResults(i);
				if(otherOPT != null){
					Console.WriteLine(otherOPT.Length);
					Console.WriteLine(otherOPT[0].name);
					Console.WriteLine(otherOPT[0].description);
					Console.WriteLine(otherOPT[0].value);
				}
			}
			Console.WriteLine(osrlReader.getOSAnalysis().getJobID());
			
			double[] mdValues2 = osrlReader.getOptimalPrimalVariableValues(-1);
			if(mdValues2 == null) Console.WriteLine("no optimal variable values");
			else{
				for(int i = 0; i < mdValues2.Length; i++){
					Console.WriteLine(mdValues2[i]);
				}
				
			}
			String[] msValues2 = osrlReader.getOptimalPrimalVariableStringValues(-1);
			if(msValues2 == null) Console.WriteLine("no optimal variable string values");
			else{
				for(int i = 0; i < msValues2.Length; i++){
					Console.WriteLine(msValues2[i]);
				}
				
			}
			mdValues2 = osrlReader.getOptimalDualVariableValues(-1);
			if(mdValues2 == null) Console.WriteLine("no optimal dual variable values");
			else{
				for(int i = 0; i < mdValues2.Length; i++){
					Console.WriteLine(mdValues2[i]);
				}
				
			}
			
			//osrlReader.writeToStandardOutput();
			*/
			//test OSrLWriter
			/*
			OSrLWriter osrlWriter = new OSrLWriter();
			String sFileName = OSParameter.CODE_HOME + "OSRepository/test/osrl/osrl.osrl";
			String sAnalysisFileName = OSParameter.CODE_HOME + "OSRepository/test/osal/osal.osal";
			
			GeneralStatus status = new GeneralStatus();
			status.type= "success";
			status.description = "my status description";
			GeneralSubstatus[] substatuses = new GeneralSubstatus[2];
			substatuses[0] = new GeneralSubstatus();
			substatuses[0].name = "sub name 0";
			substatuses[0].description = "sub description 0";
			substatuses[0].value = "sub value 0";
			substatuses[1] = new GeneralSubstatus();
			substatuses[1].name = "sub name 1";
			substatuses[1].description = "sub description 1";
			substatuses[1].value = "sub value 1";
			status.substatus = substatuses;
			if(!osrlWriter.setGeneralStatus(status)) Console.WriteLine("status!");
			if(!osrlWriter.setGeneralMessage("my message")) Console.WriteLine("message!");
			//if(!osrlWriter.setGeneralMessage("")) Console.WriteLine("message!");
			if(!osrlWriter.setInstanceName("my instance")) Console.WriteLine("instance");
			if(!osrlWriter.setServiceName("my service name")) Console.WriteLine("service name");
			if(!osrlWriter.setServiceURI("my service uri")) Console.WriteLine("uri");
			if(!osrlWriter.setJobID("my job ID")) Console.WriteLine("job ID");
			if(!osrlWriter.setResultTime(new DateTime())) Console.WriteLine("time!");

		
			if(!osrlWriter.setCurrentState("busy")) Console.WriteLine("setCurrentState!");
			if(!osrlWriter.setAvailableDiskSpace(1.2)) Console.WriteLine("setAvailableDiskSpace!");
			if(!osrlWriter.setAvailableMemory(3.4)) Console.WriteLine("setAvailableMemory!");
			if(!osrlWriter.setCurrentJobCount(0)) Console.WriteLine("setCurrentJobCount!");
			if(!osrlWriter.setTotalJobsSoFar(100)) Console.WriteLine("setTotalJobsSoFar!");
			if(!osrlWriter.setTimeLastJobEnded(new DateTime(2006, 1, 31, 15, 3, 4))) Console.WriteLine("setTimeLastJobEnded!");
			if(!osrlWriter.setTimeLastJobTook(200.4)) Console.WriteLine("setTimeLastJobTook!");
			if(!osrlWriter.setTimeServiceStarted(new DateTime(2003, 1, 31, 15, 3, 4))) Console.WriteLine("setTimeServiceStarted!");
			if(!osrlWriter.setServiceUtilization(1.3)) Console.WriteLine("setServiceUtilization!");
			JobStatistics[] jobstatistics = new JobStatistics[2];
			jobstatistics[0] = new JobStatistics();
			jobstatistics[1] = new JobStatistics();
			jobstatistics[0].jobID = "job0000";
			jobstatistics[1].jobID = "job1111";
			jobstatistics[0].duration = 2.3;
			jobstatistics[0].startTime = new DateTime(2006, 1, 3);
			jobstatistics[0].endTime = new DateTime(2006, 1, 4);
			jobstatistics[0].scheduledStartTime = new DateTime(2006, 1, 3);
			jobstatistics[0].state = "running";
			JobDependencies dependencies = new JobDependencies();
			dependencies.jobID = new String[2];
			dependencies.jobID[0] = "333";
			dependencies.jobID[1] = "aaa";
			jobstatistics[0].dependencies = dependencies;	
			if(!osrlWriter.setJobStatistics(jobstatistics)) Console.WriteLine("setJobStatistics!");
			//		ProcessStatistics processStatistics = new ProcessStatistics();
			//		processStatistics.jobs = new Jobs();
			//		processStatistics.jobs.job = jobstatistics;
			//		if(!osrlWriter.setProcessStatistics(processStatistics)) Console.WriteLine("setJobStatistics!");

		
			String[] msOtherResultNames = {"other name 0", "other name 1"};
			String[] msOtherResultValues = {"other value 0", "other value 1"};
			if(!osrlWriter.setOtherResults(msOtherResultNames, msOtherResultValues, null)) Console.WriteLine("set other!");
	
			if(!osrlWriter.addOtherResult("other name 2", "other value 2", null)) Console.WriteLine("add other!");
			if(!osrlWriter.addOtherResult("other name 3", "other value 3", "other description 3")) Console.WriteLine("add other!");

		
			osrlWriter.setVariableNumber(3);
			osrlWriter.setObjectiveNumber(2);
			osrlWriter.setConstraintNumber(4);
			osrlWriter.setSolutionNumber(3);
		
			if(!osrlWriter.setSolutionStatus(0, "optimal", "solved", null)) Console.WriteLine("setSolutionStatus");
			if(!osrlWriter.setSolutionStatus(1, "infeasible", "solved", null)) Console.WriteLine("setSolutionStatus");
			if(!osrlWriter.setSolutionStatus(2, "globallyOptimal", "solved", null)) Console.WriteLine("setSolutionStatus");

			if(!osrlWriter.setSolutionMessage(0, "sol0 message")) Console.WriteLine("setSolutionMessage");
			if(!osrlWriter.setSolutionMessage(1, "sol1 message")) Console.WriteLine("setSolutionMessage");
			if(!osrlWriter.setSolutionMessage(2, "sol2 message")) Console.WriteLine("setSolutionMessage");


			if(!osrlWriter.setSolutionObjectiveIndex(0, -1)) Console.WriteLine("setSolutionObjectiveIndex");
			if(!osrlWriter.setSolutionObjectiveIndex(1, -1)) Console.WriteLine("setSolutionObjectiveIndex");
			if(!osrlWriter.setSolutionObjectiveIndex(2, -1)) Console.WriteLine("setSolutionObjectiveIndex");

			String[] msValues1 = {"a", "b", "c"};
			if(!osrlWriter.setPrimalVariableStringValues(0, msValues1)) Console.WriteLine("setPrimalVariableStringValues");
			String[] msValues2 = {"b", "c", "d"};
			if(!osrlWriter.setPrimalVariableStringValues(1, msValues2)) Console.WriteLine("setPrimalVariableStringValues");
			String[] msValues3 = {"c", "d", "e"};
			if(!osrlWriter.setPrimalVariableStringValues(2, msValues3)) Console.WriteLine("setPrimalVariableStringValues");

		
			double[] mdValues1 = {1, 2, 3};
			if(!osrlWriter.setPrimalVariableValues(0, mdValues1)) Console.WriteLine("setPrimalVariableValues");
			double[] mdValues2 = {2, 3, 4};
			if(!osrlWriter.setPrimalVariableValues(1, mdValues2)) Console.WriteLine("setPrimalVariableValues");
			double[] mdValues3 = {3, 4, 5};
			if(!osrlWriter.setPrimalVariableValues(2, mdValues3)) Console.WriteLine("setPrimalVariableValues");

			double[] mdValues11 = {1, 2};
			if(!osrlWriter.setObjectiveValues(0, mdValues11)) Console.WriteLine("setObjectiveValues");
			double[] mdValues22 = {2, 3};
			if(!osrlWriter.setObjectiveValues(1, mdValues22)) Console.WriteLine("setObjectiveValues");
			double[] mdValues33 = {3, 4};
			if(!osrlWriter.setObjectiveValues(2, mdValues33)) Console.WriteLine("setObjectiveValues");

			double[] mdValues77 = {4, 2, 3, 4};
			if(!osrlWriter.setDualVariableValues(0, mdValues77)) Console.WriteLine("setDualVariableValues");
			double[] mdValues88 = {5, 3, 4, 5};
			if(!osrlWriter.setDualVariableValues(1, mdValues88)) Console.WriteLine("setDualVariableValues");
			double[] mdValues99 = {6, 4, 5, 6};
			if(!osrlWriter.setDualVariableValues(2, mdValues99)) Console.WriteLine("setDualVariableValues");

			OtherVariableResult[] varOT1 = new OtherVariableResult[2];
			varOT1[0] = new OtherVariableResult();	
			varOT1[0].var = new OtherVarResult[2];
			varOT1[0].var[0] = new OtherVarResult();
			varOT1[0].name = "varOT1 name";
			varOT1[0].description = "varOT1 description";
			varOT1[0].value = "varOT1 value";		
			varOT1[0].var[0].idx = 0;
			varOT1[0].var[0].value = "a";
			varOT1[0].var[1] = new OtherVarResult();
			varOT1[0].var[1].idx = 1;
			varOT1[0].var[1].value = "b";
			varOT1[1] = new OtherVariableResult();	
			varOT1[1].name = "varOT2 name";
			varOT1[1].description = "varOT2 description";
			varOT1[1].value = "varOT2 value";		
			varOT1[1].var = new OtherVarResult[2];
			varOT1[1].var[0] = new OtherVarResult();
			varOT1[1].var[0].idx = 0;
			varOT1[1].var[0].value = "a";
			varOT1[1].var[1] = new OtherVarResult();
			varOT1[1].var[1].idx = 1;
			varOT1[1].var[1].value = "b";
			if(!osrlWriter.setOtherVariableResults(0, varOT1)) Console.WriteLine("setOtherVariableResults");
			if(!osrlWriter.setOtherVariableResults(1, varOT1)) Console.WriteLine("setOtherVariableResults");
			if(!osrlWriter.setOtherVariableResults(2, varOT1)) Console.WriteLine("setOtherVariableResults");

			OtherConstraintResult[] conOT1 = new OtherConstraintResult[2];
			conOT1[0] = new OtherConstraintResult();	
			conOT1[0].con = new OtherConResult[2];
			conOT1[0].con[0] = new OtherConResult();
			conOT1[0].name = "conOT1 name";
			conOT1[0].description = "conOT1 description";
			conOT1[0].value = "conOT1 value";		
			conOT1[0].con[0].idx = 0;
			conOT1[0].con[0].value = "a";
			conOT1[0].con[1] = new OtherConResult();
			conOT1[0].con[1].idx = 1;
			conOT1[0].con[1].value = "b";
			conOT1[1] = new OtherConstraintResult();	
			conOT1[1].name = "conOT2 name";
			conOT1[1].description = "conOT2 description";
			conOT1[1].value = "conOT2 value";		
			conOT1[1].con = new OtherConResult[2];
			conOT1[1].con[0] = new OtherConResult();
			conOT1[1].con[0].idx = 0;
			conOT1[1].con[0].value = "a";
			conOT1[1].con[1] = new OtherConResult();
			conOT1[1].con[1].idx = 1;
			conOT1[1].con[1].value = "b";
			if(!osrlWriter.setOtherConstraintResults(0, conOT1)) Console.WriteLine("setOtherConstraintResults");
			if(!osrlWriter.setOtherConstraintResults(1, conOT1)) Console.WriteLine("setOtherConstraintResults");
			if(!osrlWriter.setOtherConstraintResults(2, conOT1)) Console.WriteLine("setOtherConstraintResults");
		
		
			OtherObjectiveResult[] objOT1 = new OtherObjectiveResult[2];
			objOT1[0] = new OtherObjectiveResult();	
			objOT1[0].obj = new OtherObjResult[2];
			objOT1[0].obj[0] = new OtherObjResult();
			objOT1[0].name = "objOT1 name";
			objOT1[0].description = "objOT1 description";
			objOT1[0].value = "objOT1 value";		
			objOT1[0].obj[0].idx = -1;
			objOT1[0].obj[0].value = "a";
			objOT1[0].obj[1] = new OtherObjResult();
			objOT1[0].obj[1].idx = -2;
			objOT1[0].obj[1].value = "b";
			objOT1[1] = new OtherObjectiveResult();	
			objOT1[1].name = "objOT2 name";
			objOT1[1].description = "objOT2 description";
			objOT1[1].value = "objOT2 value";		
			objOT1[1].obj = new OtherObjResult[2];
			objOT1[1].obj[0] = new OtherObjResult();
			objOT1[1].obj[0].idx = -1;
			objOT1[1].obj[0].value = "a";
			objOT1[1].obj[1] = new OtherObjResult();
			objOT1[1].obj[1].idx = -2;
			objOT1[1].obj[1].value = "b";
			if(!osrlWriter.setOtherObjectiveResults(0, objOT1)) Console.WriteLine("setOtherObjectiveResults");
			if(!osrlWriter.setOtherObjectiveResults(1, objOT1)) Console.WriteLine("setOtherObjectiveResults");
			if(!osrlWriter.setOtherObjectiveResults(2, objOT1)) Console.WriteLine("setOtherObjectiveResults");
		
			OtherOptimizationResult[] otherOpt = new OtherOptimizationResult[2];
			otherOpt[0] = new OtherOptimizationResult();
			otherOpt[0].name = "othetOpt0 name";
			otherOpt[0].value = "othetOpt0 value";
			otherOpt[0].description = "othetOpt0 description";
			otherOpt[1] = new OtherOptimizationResult();
			otherOpt[1].name = "othetOpt1 name";
			otherOpt[1].value = "othetOpt1 value";
			otherOpt[1].description = "othetOpt1 description";
			if(!osrlWriter.setOtherOptimizationResults(0, otherOpt)) Console.WriteLine("setOtherOptimizationResults");
			if(!osrlWriter.setOtherOptimizationResults(1, otherOpt)) Console.WriteLine("setOtherOptimizationResults");
			if(!osrlWriter.setOtherOptimizationResults(0, otherOpt)) Console.WriteLine("setOtherOptimizationResults");
		
			OSaLReader osalReader = new OSaLReader(false);
			if(!osalReader.readFile(sAnalysisFileName)) Console.WriteLine("reading");
			OSAnalysis osAnalysis = null;
			try {
				osAnalysis = osalReader.getOSAnalysis();
			} 
			catch (Exception e) {
				Console.WriteLine(e.ToString());
			}
			if(!osrlWriter.setOSAnalysis(osAnalysis)) Console.WriteLine("setOSAnalysis");
			
			
			///////////////////////
			
			OSrLReader osrlReader = new OSrLReader(false);
			if(!osrlReader.readFile(sFileName)) Console.WriteLine("reading");
			OSResult osResult = null;
			try {
				osResult = osrlReader.getOSResult();
				osrlWriter = new OSrLWriter();
				if(!osrlWriter.setOSResult(osResult)) Console.WriteLine("setOSResult");
			} 
			catch (Exception e) {
				Console.WriteLine(e.ToString());
			}
			
			///////////////////////
			Console.WriteLine(osrlWriter.writeToString());
			*/
			//test CGRegistry Service
			/*
			CGRegistryService cgRegistryService = new CGRegistryService();
			Console.WriteLine(DefaultRegistry.osRegistry.description);
			*/
			//test xml date
			/*
			Console.WriteLine(XMLUtil.createNativeDateTime("2005-11-23T17:33:41.750-06:00").Tostring());
			Console.WriteLine(XMLUtil.createXSDateTime(DateTime.Now));
			*/

			//test ioutil.print
			/*
			IOUtil.println("abc");
			IOUtil.println("efg");
			IOUtil.println();
			IOUtil.print("1234");
			Console.WriteLine(OSParameter.PRINT_STRING_WRITER.Tostring());
			*/

			//test OSServiceUtil static timer
			/*
			OSServiceUtil osServiceUtil = new OSServiceUtil();
			*/
			
			//test IOUtil copy, move, delete, create file and directory, get current/parent directory
			/*
			IOUtil.copyDir("\\\\Cgweb14\\c\\abc\\", "c:\\abcd\\");
			IOUtil.moveDir("\\\\Cgweb14\\c\\abc\\", "c:\\abcd\\");
			IOUtil.appendStringToFile("bbbb", "c:/aaabbb.txt");
			IOUtil.appendStringToFile("cccc", "c:/aaabbb.txt");
			Console.WriteLine(IOUtil.existsFileOrDir("c:/code"));
			Console.WriteLine(IOUtil.existsFileOrDir("c:/code"));
			IOUtil.copyFile("c:/code/temp/m.xls", "c:/code/temp/copy.xls");
			IOUtil.moveFile("c:/code/temp/m.xls", "c:/code/temp/copy.xls");
			IOUtil.deleteFile("c:/code/temp/copy.xls");
			IOUtil.makeDir("c:/abc/");
			IOUtil.deleteDir("c:/abc/");
			Console.WriteLine(IOUtil.getCurrentDir());
			Console.WriteLine(IOUtil.getParentDir());
			Console.WriteLine(IOUtil.isDir("c:/abc/abc.txt"));
			IOUtil.cleanUpDisk();
			Console.WriteLine(IOUtil.getFreeDiskSpace("c:"));
			*/
			
			//test stringToVector
			/*
			Console.WriteLine(CommonUtil.stringToVector("aaa\r  bbb\nccc \t;\n", ",; \t\r\n").Count);
			*/
			//test mail util send 
			/*
			Console.WriteLine(MailUtil.send("maj@northwestern.edu", null, "xuhmaj@hotmail.com, majxuh@hotmail.com",  "", "ccHii", ".net hello world", OSParameter.LOG_FILE+" "+"c:/s19o.qr"));
			*/
			//test currentTimeMillis and createNativeDateTime from CommonUtil
			//long lStart = CommonUtil.currentTimeMillis();
			/*
			long lStart = CommonUtil.timeMillis();
			Console.WriteLine(lStart);
			System.Threading.Thread.Sleep(1111);
			long lEnd = CommonUtil.currentTimeMillis();
			Console.WriteLine(lEnd);
			Console.WriteLine(lEnd - lStart);

			DateTime time = CommonUtil.createNativeDateTime(CommonUtil.currentTimeMillis());
			Console.WriteLine(XMLUtil.createXSDateTime(time));
			Console.WriteLine(XMLUtil.createXSDateTime(DateTime.Now));
			*/

			//test random
			/*
			Random rand = new Random();
			for(int i = 0; i < 100; i++) Console.WriteLine(rand.NextDouble().Tostring());
			*/

			//test time
			/*			
			DateTime time1 = new DateTime(1970, 1, 1);
			DateTime time2 = new DateTime(1970, 1, 1, 0, 0, 0);
			if(time1 == time2) Console.WriteLine("time equal");
			else Console.WriteLine("time not equal");
			Console.WriteLine(new DateTime());
			*/
			//Test process, memory, kill process by name, by id
			//Console.WriteLine(ProcessUtil.getFreeMemory());
			//Console.WriteLine(ProcessUtil.killProcessByName("EXCEL.exe"));

			//test int long, double and time conversion
			/*
			double time = 7360.2;
			int hour = (int)time/3600;
			int min = (int)(time-hour*3600)/60;
			int sec = (int)time%60;
			Console.WriteLine(hour);
			Console.WriteLine(min);
			Console.WriteLine(sec);
			*/
			//test DateTime
			/*
			Console.WriteLine(CommonUtil.timeMillis(new DateTime(2006, 2, 8, 16, 2, 0)));
			Console.WriteLine(CommonUtil.timeMillis(DateTime.Now));
			*/

			//test the registry service
			/*
			CGRegistryService registry = new CGRegistryService();
			String sRegistrySiteNet = "http://localhost/OSRegistry/CGRegistryService.asmx";
			//String sRegistrySiteJava ="http://localhost:8080/os/osregistry/CGRegistryService.jws";
			OSRegistryAgent agent = new OSRegistryAgent(sRegistrySiteNet);
			*/
			//test register
			/*
			//String sRegisterOutput = registry.register("this is osel", "this is osol");
			String sRegisterOutput = agent.register("this is osel", "this is osol");
			Console.WriteLine(sRegisterOutput);
			*/

			//test validate
			/*
			String sOSxL = 	IOUtil.readStringFromFile(OSParameter.CODE_HOME + "OSRepository/test/osel/osel.osel");
			//String sValidateOutput = registry.validate(sOSxL, "");
			String sValidateOutput = agent.validate(sOSxL, "");
			Console.WriteLine(sValidateOutput);
			*/

			//test find
			/*
			OSqLWriter osqlWriter = new OSqLWriter();
			StandardQuery sq = new StandardQuery();
			sq.currentState = "accepting";
			osqlWriter.setStandardQuery(sq);
			String sOSqL = osqlWriter.writeToString();
			Console.WriteLine(sOSqL);
		
			OSoLWriter osolWriter = new OSoLWriter();
			String sOSoL = osolWriter.writeToString();
			Console.WriteLine(sOSoL);

			String sOSuL = registry.find(sOSqL, sOSoL);
			//String sOSuL = agent.find(sOSqL, sOSoL);
			Console.WriteLine(sOSuL);
			*/
		
			//test knock
			/*
			OSoLWriter osolWriter = new OSoLWriter();
			osolWriter.setServiceURI("http://localhost/OSSolver/CGSolverService.asmx");
			//osolWriter.setServiceURI("http://localhost:8080/os/ossolver/CGSolverService.jws");
			String sOSoL = osolWriter.writeToString();
			Console.WriteLine(sOSoL);
		
			OSpLWriter osplWriter = new OSpLWriter();
			osplWriter.setServiceURI("http://localhost:8080/os/ossolver/CGSolverService.jws");
			osplWriter.setRequestAction("ping");
			//osplWriter.setRequestAction("notifyJobCompletion");
			//osplWriter.setRequestAction("requestJob");
			//osplWriter.setRequestAction("getServiceStatistics");
			//osplWriter.setRequestAction("getJobStatistics");
			//osplWriter.setRequestAction("getAll");
			//osplWriter.setRequestAction("setServiceStatistics");
			//osplWriter.setRequestAction("setAll");
			//osplWriter.setRequestAction("setJobStatistics");
				//osplWriter.setCurrentState("busyButAccepting");		
				//JobStatistics[] mJobStatistics = new JobStatistics[2];
				//mJobStatistics[0] = new JobStatistics();
				//mJobStatistics[0].jobID = "abc";
				//mJobStatistics[1] = new JobStatistics();
				//mJobStatistics[1].jobID = "def";
				//osplWriter.setJobStatistics(mJobStatistics);
			string sOSpLInput = osplWriter.writeToString();
			Console.WriteLine(sOSpLInput);
		
		
			//string sOSpLOutput = registry.knock(sOSpLInput, sOSoL);
			String sOSpLOutput = agent.knock(sOSpLInput, sOSoL);
			Console.WriteLine(sOSpLOutput);
			*/

			//test registry's other function
			/*
			OSpLWriter osplWriter = new OSpLWriter();
			osplWriter.setRequestAction("getServiceStatistics");
			osplWriter.setServiceName("OSRegistry");
			osplWriter.setServiceURI(OSParameter.OS_REGISTRY_SITE);
			osplWriter.setProcessTime(DateTime.Now);
			String sOSpLInput = osplWriter.writeToString();
				
			OSoLWriter osolWriter = new OSoLWriter();
			String sOSoL = osolWriter.writeToString();


			OSSolverAgent osSolverAgent = new OSSolverAgent();
			osSolverAgent.solverAddress = "http://localhost:8080/os/ossolver/CGSolverService.jws";
			string sOSrL = osSolverAgent.knock(sOSpLInput, sOSoL);
			Console.WriteLine(sOSrL);
			Console.ReadLine();	
			*/
			//test create instance from class name
			/*
			try {
				string sClassName = "org.optimizationservices.ossolver.solver.Class1";
				Assembly assembly = Assembly.LoadFrom("OSSolver.dll");
				Type type = assembly.GetType(sClassName);
				Class1 class1 =  (Class1) Activator.CreateInstance(type); 
				Console.WriteLine(class1.print("cde"));


			} 
			catch (Exception e) {
				e.ToString();
			}			
			CGSolverService service = new CGSolverService();
			*/
			//tokenize, string array, split
			/*
			string s = "a, b,c";
			char[] delimiters = {',', ' '};
			string[] ms = s.Split(delimiters);
			Console.WriteLine(ms[0]);
			Console.WriteLine(ms.Length);
			*/

			//test IEnNETService
			IEnNETService service = new IEnNETService();
			string sToken = service.Login("ennetdemo@gridlogix.com", "Test");
			Console.WriteLine(sToken);

			string sVavTempID = "//EnNET-OPCDA/Servers/192.168.0.182/OPC Server/Configured Aliases/vav/temperature/ItemValue";
			Console.WriteLine((service.GetValue(sToken, sVavTempID)).Value);
			Console.ReadLine();
			
		}//main
	}//class test
}//namespace
