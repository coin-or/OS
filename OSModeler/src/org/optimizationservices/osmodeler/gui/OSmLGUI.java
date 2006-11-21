/**
 * @(#)OSmLGUI 1.0 03/14/2004
 *
 * Copyright (c) 2004
 */
package org.optimizationservices.osmodeler.gui;

import java.io.File;
import java.util.GregorianCalendar;
import java.util.Hashtable;
import java.util.Vector;

import org.eclipse.swt.SWT;
import org.eclipse.swt.custom.ExtendedModifyListener;
import org.eclipse.swt.graphics.Font;
import org.eclipse.swt.layout.FillLayout;
import org.eclipse.swt.layout.GridData;
import org.eclipse.swt.widgets.Display;
import org.eclipse.swt.widgets.Event;
import org.eclipse.swt.widgets.FileDialog;
import org.eclipse.swt.widgets.Listener;
import org.eclipse.swt.widgets.Menu;
import org.eclipse.swt.widgets.MenuItem;
import org.eclipse.swt.widgets.MessageBox;
import org.eclipse.swt.widgets.Shell;
import org.eclipse.swt.widgets.TabFolder;
import org.eclipse.swt.widgets.TabItem;
import org.eclipse.swt.widgets.Text;
import org.optimizationservices.oscommon.communicationagent.OSSolverAgent;
import org.optimizationservices.oscommon.representationparser.OSoLWriter;
import org.optimizationservices.oscommon.representationparser.OSpLReader;
import org.optimizationservices.oscommon.representationparser.OSpLWriter;
import org.optimizationservices.oscommon.representationparser.OSrLReader;
import org.optimizationservices.oscommon.representationparser.OSsLWriter;
import org.optimizationservices.oscommon.util.IOUtil;
import org.optimizationservices.oscommon.util.OSParameter;
import org.optimizationservices.oscommon.util.ProcessUtil;
import org.optimizationservices.osmodeler.modeler.OSmLEngine;

/**
 *
 * <P>The <code>OSmLEngine</code> class interprets the XQuery based Optimization Services 
 * Modeling Language model and compiles the model into an Optimization Services Instance
 * Language (OSiL) low level representation.</p>
 *
 * </p>
 *
 * @author Robert Fourer, Jun Ma, Kipp Martin
 * @version 1.0, 03/14/2004
 * @see org.optimizationservices.osmodeler.parser.OSmLGUI
 * @since OS 1.0
 */
public class OSmLGUI {
	/**
	 * Various controls of the GUI
	 */
	private static Shell shell;
	private static TabFolder tabFolder = null;
	private static TabItem theModel = null;
	private static TabItem thepreParsedModel = null;
	private static TabItem thequeryResult = null;
	private static TabItem theOSiL = null;
	private static TabItem theOSoL = null;
	private static TabItem theService = null;
	private static TabItem theJobID = null;
	private static TabItem theOSrL = null;
	//private static TabItem thePostFix = null;
	private Text osmlText; 	//private StyledText osmlText;
	private Text preParsedText;
	private Text queryResultText;
	private Text osilText;
	private Text solutionText;
	private Text jobIDText;
	private Text serviceText;
	private Text osolText;
	//private Text postfixText;
	private Font font;
	//private Color color;
	boolean isBold = false;
	Vector cachedStyles = new Vector();
	ExtendedModifyListener extendedModifyListener;

	private String m_sModel = "";
	
	private String m_sData = "";
	
	private String m_sOSiL = "";

	private String m_sOSoL = "";

	private String m_sEmptyOSiL = "<?xml version=\"1.0\" encoding=\"UTF-8\"?><OSoL/>";	

	private String m_sOSpLInput = "";
	
	private OSmLEngine m_OSmLEngine = null;
	
	private OSSolverAgent m_osSolverAgent = new OSSolverAgent();
	
	private String m_sLocalServer = "http://localhost:8080/";
	private String m_sServer = "http://128.135.130.17:8080/";
	private String m_sImpactSolverServiceAddress = m_sServer+"ImpactSolverService.jws";
	private String m_sLindoSolverServiceAddress = m_sServer+"lindo/LindoSolverService.jws";
	private String m_sLocalLindoSolverServiceAddress = m_sLocalServer+"lindo/LindoSolverService.jws";
	private String m_sCLPSolverServiceAddress = m_sServer+"clp/CLPSolverService.jws";
	private String m_sLocalCLPSolverServiceAddress = m_sLocalServer+"clp/CLPSolverService.jws";
	private String m_sCBCSolverServiceAddress = m_sServer+"cbc/CBCSolverService.jws";
	private String m_sLocalCBCSolverServiceAddress = m_sLocalServer+"cbc/CBCSolverService.jws";
	private String m_sGLPKSolverServiceAddress = m_sServer+"glpk/GLPKSolverService.jws";
	private String m_sLocalGLPKSolverServiceAddress = m_sLocalServer+"glpk/GLPKSolverService.jws";
	private String m_sKnitroSolverServiceAddress = m_sServer+"KnitroSolverService.jws";
	private String m_sCOINSolverServiceAddress = m_sServer+"COINSolverService.jws";

	private String m_sJobID = "";

	private String m_sServiceName = "lindo";
	private String m_sServiceAddress = m_sLindoSolverServiceAddress;

	private boolean m_bValidate = OSParameter.VALIDATE;
	private OSrLReader m_osrlReader = new OSrLReader();
	private OSsLWriter m_osslWriter = new OSsLWriter();
	private OSoLWriter m_osolWriter = new OSoLWriter();
	private OSpLReader m_osplReader = new OSpLReader();
	private OSpLWriter m_osplWriter = new OSpLWriter();

	private Hashtable<String, String> m_mapServiceAddress = new Hashtable<String, String>();

	/**
	 * constructor
	 */
	public OSmLGUI(){
		m_mapServiceAddress.put("impact", m_sImpactSolverServiceAddress);
		m_mapServiceAddress.put("lindo", m_sLindoSolverServiceAddress);
		m_mapServiceAddress.put("clp", m_sCLPSolverServiceAddress);
		m_mapServiceAddress.put("cbc", m_sCBCSolverServiceAddress);
		m_mapServiceAddress.put("glpk", m_sGLPKSolverServiceAddress);
		m_mapServiceAddress.put("coin", m_sCOINSolverServiceAddress);
		m_mapServiceAddress.put("knitro", m_sKnitroSolverServiceAddress);
		m_mapServiceAddress.put("locallindo", m_sLocalLindoSolverServiceAddress);
		m_mapServiceAddress.put("localclp", m_sLocalCLPSolverServiceAddress);
		m_mapServiceAddress.put("localcbc", m_sLocalCBCSolverServiceAddress);
		m_mapServiceAddress.put("localglpk", m_sLocalGLPKSolverServiceAddress);
		
		m_osolWriter.setContactTransportType("smtp");
		m_osolWriter.setContactAddress("kipp.martin@chicagogsb.edu");		
		m_osolWriter.setJobID(m_sJobID);
		m_osolWriter.setInstanceName(m_sJobID+".osil");


		m_osplWriter = new OSpLWriter();
		m_osplWriter.setRequestAction("getAll");
		m_osplWriter.setProcessTime(new GregorianCalendar());
		m_sOSpLInput = m_osplWriter.writeToString();

	}//constructor
	
	private void initializeInput(){
		m_OSmLEngine = new OSmLEngine();
		m_sModel = osmlText.getText();
		m_OSmLEngine.modelString(m_sModel, m_sData);		
		osilText.setText("");
		preParsedText.setText(m_OSmLEngine.preparsedModel);
		queryResultText.setText(m_OSmLEngine.queryResult) ;
		osilText.setText( m_OSmLEngine.osilInstance);
		m_sOSiL = osilText.getText();
		/*
		OSiLReader osilReader = new OSiLReader( true);
		boolean bRead = false;
		bRead = osilReader.readString(OSmLEngine.osilInstance);
		String pfText = "";
		HashMap map = osilReader.getNonlinearExpressions();
		java.util.Iterator it = map.keySet().iterator();
		while(it.hasNext()){
			String key = (String)it.next();
			pfText += ("rowNum: " + key);
			pfText += ("\npostfix: " + osilReader.getPostfix(Integer.parseInt(key)));
			pfText += ("\nprefix: " + osilReader.getPrefix(Integer.parseInt(key)));
			pfText += ("\ninfix: " + osilReader.getInfix(Integer.parseInt(key)));
			pfText += "\n";
		}
		postfixText.setText( pfText);*/
	}//initializeInput

	private void initializeService(){
		m_sServiceName = serviceText.getText().trim().toLowerCase();
		if(m_sServiceName == null || m_sServiceName.length() <= 0){
			m_sServiceName = "lindo";
		}
		else{
			m_sServiceName = m_sServiceName.toLowerCase();
		}
		m_sServiceAddress = m_mapServiceAddress.get(m_sServiceName);
		System.out.println(m_sServiceAddress);
		
		m_sJobID = jobIDText.getText();
		
		m_osolWriter.setJobID(m_sJobID);
		m_osolWriter.setInstanceName(m_sJobID+".osil");
		osolText.setText(m_osolWriter.writeToString());
		m_osSolverAgent.solverAddress = m_sServiceAddress;

	}
	/**
	 * Create the GUI menu. 
	 *
	 */
	public void createMenu(){
		//create the menu bar
		Menu menu = new Menu(shell, SWT.BAR);
		shell.setMenuBar(menu);
		//add File option to it
		MenuItem file = new MenuItem(menu, SWT.CASCADE);
		file.setText("File");		
		//set the menu for the File option
		Menu filemenu = new Menu(shell, SWT.DROP_DOWN);
		file.setMenu(filemenu);
		//add MenuItems to the File menu
		MenuItem openOSModel = new MenuItem(filemenu, SWT.PUSH);
		openOSModel.setText("Open OSModel");
		// add OSiL
		MenuItem openOSiL = new MenuItem(filemenu, SWT.PUSH);
		openOSiL.setText("Open OSiL");	
		// add OSoL
		MenuItem openOSoL = new MenuItem(filemenu, SWT.PUSH);
		openOSoL.setText("Open OSoL");	
		// separator
		//MenuItem separator = new MenuItem( filemenu, SWT.SEPARATOR);
		//add MenuItems to the File menu
		MenuItem saveOSModel = new MenuItem(filemenu, SWT.PUSH);
		saveOSModel.setText("Save OSModel");
		//Impact item
		 
		MenuItem IMPACT = new MenuItem(menu, SWT.CASCADE);
		IMPACT.setText("Action");
		Menu IMPACTmenu = new Menu(shell, SWT.DROP_DOWN);
		IMPACT.setMenu( IMPACTmenu);
		MenuItem getJobID = new MenuItem(IMPACTmenu, SWT.PUSH);
		getJobID.setText("getJobID");
		MenuItem solveImpact = new MenuItem(IMPACTmenu, SWT.PUSH);
		solveImpact.setText("solve");
		MenuItem send = new MenuItem(IMPACTmenu, SWT.PUSH);
		send.setText("send");
		MenuItem retrieve = new MenuItem(IMPACTmenu, SWT.PUSH);
		retrieve.setText("retrieve");
		MenuItem kill = new MenuItem(IMPACTmenu, SWT.PUSH);
		kill.setText("kill");
		MenuItem knock = new MenuItem(IMPACTmenu, SWT.PUSH);
		knock.setText("knock");

		// Now the run Item
		MenuItem run = new MenuItem(menu, SWT.CASCADE);
		run.setText("");
		Menu runmenu = new Menu(shell, SWT.DROP_DOWN);
		run.setMenu( runmenu);
		MenuItem solve = new MenuItem(runmenu, SWT.CASCADE);
		solve.setText("solve");
		Menu solveSubMenu = new Menu (shell, SWT.DROP_DOWN);
		MenuItem Automatic = new MenuItem(solveSubMenu, SWT.PUSH);
		Automatic.setText("automatic");
		MenuItem Impact = new MenuItem(solveSubMenu, SWT.PUSH);
		Impact.setText("Impact");
		MenuItem Knitro = new MenuItem(solveSubMenu, SWT.PUSH);
		Knitro.setText("Knitro");
		MenuItem Lindo = new MenuItem(solveSubMenu, SWT.PUSH);
		Lindo.setText("Lindo");
		MenuItem Coin = new MenuItem(solveSubMenu, SWT.CASCADE);
		Coin.setText("Coin");
		Menu coinSubMenu = new Menu (shell, SWT.DROP_DOWN);
		MenuItem CLP = new MenuItem(coinSubMenu, SWT.PUSH);
		CLP.setText("CLP");
		MenuItem CBC = new MenuItem(coinSubMenu, SWT.PUSH);
		CBC.setText("CBC");
		MenuItem GLPK = new MenuItem(coinSubMenu, SWT.PUSH);
		GLPK.setText("GLPK");
		Coin.setMenu(coinSubMenu);
		solve.setMenu(solveSubMenu);

		//action to take on opening the OS model
		openOSModel.addListener(SWT.Selection, new Listener() {
			public void handleEvent(Event e) {
				tabFolder.setSelection(0);
	            tabFolder.forceFocus();
				String selectedFile = openFile();
				if( selectedFile != null){
					String theOSModelfile =  IOUtil.fileToString( selectedFile);
					osmlText.setText( theOSModelfile);
				}
				osilText.setText( "");
			}
		});
		//action to take on opening the OSiL instance
		openOSiL.addListener(SWT.Selection, new Listener() {
			public void handleEvent(Event e) {
				tabFolder.setSelection(3);
	            tabFolder.forceFocus();
				String selectedFile = openFile();
				if( selectedFile != null){
					String theOSiLfile =  IOUtil.fileToString( selectedFile);
					osilText.setText( theOSiLfile);
				}
				osmlText.setText( "");			
			}
		});
		//action to take on opening the OSoL option
		openOSoL.addListener(SWT.Selection, new Listener() {
			public void handleEvent(Event e) {
				tabFolder.setSelection(4);
	            tabFolder.forceFocus();
				String selectedFile = openFile();
				if( selectedFile != null){
					String theOSoLfile =  IOUtil.fileToString( selectedFile);
					osilText.setText( theOSoLfile);
				}
			}
		});
		//action to take on saving the OS model
		saveOSModel.addListener(SWT.Selection, new Listener() {
			public void handleEvent(Event e) {
				String selectedFile = saveFile();
				if(selectedFile != null){
					IOUtil.writeStringToFile(osmlText.getText(), selectedFile);
				}
			}
		});
		
		getJobID.addListener(SWT.Selection, new Listener() {
			public void handleEvent(Event event) {
				try{
					jobIDText.setText("");
					tabFolder.setSelection(6);
		            tabFolder.forceFocus();
     				initializeService();
					 m_osSolverAgent.solverAddress = m_sServiceAddress;
						m_sJobID = m_osSolverAgent.getJobID(m_sEmptyOSiL);
						jobIDText.setText(m_sJobID);	
						m_osolWriter.setJobID(m_sJobID);
						osolText.setText(m_osolWriter.writeToString());
				}
				catch(Exception e){
					e.printStackTrace();
				}
			}
		});
		
		solveImpact.addListener(SWT.Selection, new Listener() {
			public void handleEvent(Event event) {
				try{		
					solutionText.setText("");
					tabFolder.setSelection(7);
		            tabFolder.forceFocus();
					m_sOSiL = osilText.getText();
					if(m_sOSiL == null || m_sOSiL.length()<= 0){
						initializeInput();
					}
     				initializeService();
					m_sOSoL = osolText.getText();
					System.out.println(m_sOSoL);
					System.out.println("-------------");
					System.out.println(m_sOSiL);
					String sOSrL = m_osSolverAgent.solve(m_sOSiL, m_sOSoL);
					solutionText.setText( sOSrL);
					String sResultFile = "/code/temp/" + m_sJobID+".osrl";
					IOUtil.writeStringToFile(sOSrL,sResultFile);
					ProcessUtil.launch("/Applications/Firefox.app/Contents/MacOS/firefox "+sResultFile);

					/*wait simulation
					if(sOSoL.equalsIgnoreCase("wait")){
						m_osolWriter.addOtherOption("wait", "true", "let the solver wait for testing purpose");
					}
					*/
				}
				catch(Exception e){
					e.printStackTrace();
				}
			}
		});

		send.addListener(SWT.Selection, new Listener() {
			public void handleEvent(Event event) {
				try{    
					solutionText.setText("");
					tabFolder.setSelection(7);
		            tabFolder.forceFocus();
					m_sOSiL = osilText.getText();
					if(m_sOSiL == null || m_sOSiL.length()<= 0){
						initializeInput();
					}
     				initializeService();
					m_sOSoL = osolText.getText();
					boolean bResult = m_osSolverAgent.send(m_sOSiL, m_sOSoL);
					solutionText.setText("send: " + bResult);					 
				}
				catch(Exception e){
					e.printStackTrace();
				}
			}
		});
		
		retrieve.addListener(SWT.Selection, new Listener() {
			public void handleEvent(Event event) {
				try{ 
					solutionText.setText("");
					tabFolder.setSelection(7);
		            tabFolder.forceFocus();
     				initializeService();
					m_sOSoL = osolText.getText();
					String sOSrL = m_osSolverAgent.retrieve(m_sOSoL);					
					solutionText.setText(sOSrL);
					String sResultFile = "/code/temp/" + m_sJobID+".osrl";
					IOUtil.writeStringToFile(sOSrL,sResultFile);
					ProcessUtil.launch("/Applications/Firefox.app/Contents/MacOS/firefox "+sResultFile);
				}
				catch(Exception e){
					e.printStackTrace();
				}
			}
		});

		kill.addListener(SWT.Selection, new Listener() {
			public void handleEvent(Event event) {
				try{ 
					solutionText.setText("");
					tabFolder.setSelection(7);
		            tabFolder.forceFocus();
     				initializeService();
					m_sOSoL = osolText.getText();

					String sOSpLOutput = m_osSolverAgent.kill(m_sOSoL);
					solutionText.setText(sOSpLOutput);
				}
				catch(Exception e){
					e.printStackTrace();
				}
			}
		});
		
		knock.addListener(SWT.Selection, new Listener() {
			public void handleEvent(Event event) {
				try{ 
     				initializeService();
					m_sOSoL = osolText.getText();
					
					String sOSpLOutput = m_osSolverAgent.knock(m_sOSpLInput, m_sOSoL);
					solutionText.setText(sOSpLOutput);
				}
				catch(Exception e){
					e.printStackTrace();
				}
			}
		});

		Lindo.addListener(SWT.Selection, new Listener() {
			public void handleEvent(Event event) {
				try{
					initializeInput(); 
					m_sOSoL = m_osolWriter.writeToString();
					m_osSolverAgent.solverAddress = m_sLindoSolverServiceAddress;
					String sOSrL = m_osSolverAgent.solve(m_sOSiL, m_sOSoL);
//					LindoSolverService lindoSolverService = new LindoSolverService();
//					String sOSrL = lindoSolverService.solve(m_sOSiL, sOSoL);
					solutionText.setText( sOSrL);
				}
				catch(Exception e){
					e.printStackTrace();
				}
				}
		});

		//action to take on action1 in run menu
		Impact.addListener(SWT.Selection, new Listener() {
			public void handleEvent(Event event) {
				try{
					
					/*
					OSAgentService osAgentService = new OSAgentService();
					String sOSrLInstance = osAgentService.call("complex", sOSiLInstance);
					solutionText.setText( sOSrLInstance);
					*/
					
					/*
					 OSSolverAgent osSolverAgent = new OSSolverAgent();
					 osSolverAgent.solverAddress = "http://gsbkip.chicagogsb.edu/os/ossolver/LindoSolverService.jws";
					 String sOSrLInstance = osSolverAgent.solve(sOSiLInstance);
					 solutionText.setText( sOSrLInstance);
					 */
					
					 initializeInput();
//					 ImpactSolverService impactSolverService = new ImpactSolverService();
//					 String sOSrLInstance = impactSolverService.solve(m_sOSiL, m_sEmptyOSiL);
//					 solutionText.setText( sOSrLInstance);

					String sOption = osolText.getText();
					if(sOption.equalsIgnoreCase("wait")){
						m_osolWriter.addOtherOption("wait", "true", "let the solver wait for testing purpose");
					}
					m_sJobID = jobIDText.getText();
					if(m_sJobID != null && m_sJobID.length() > 0){
						m_osolWriter.setJobID(m_sJobID);
					}
					else{
						m_osolWriter.setJobID("DEFAULTJOBID12345");
					}
					String sOSoL = m_osolWriter.writeToString();
					 m_osSolverAgent.solverAddress = m_sImpactSolverServiceAddress;
					 String sOSrL = m_osSolverAgent.solve(m_sOSiL, sOSoL);
					 solutionText.setText( sOSrL);
					 
				}
				catch(Exception e){
					e.printStackTrace();
				}
			}
		});
		Knitro.addListener(SWT.Selection, new Listener() {
			public void handleEvent(Event event) {
				try{
					initializeInput(); 
					String sOSoL = m_osolWriter.writeToString();
					m_osSolverAgent.solverAddress = m_sKnitroSolverServiceAddress;
					String sOSrL = m_osSolverAgent.solve(m_sOSiL, sOSoL);
//					KnitroSolverService knitroSolverService = new KnitroSolverService();
//					String sOSrL = knitroSolverService.solve(m_sOSiL, sOSoL);
					solutionText.setText( sOSrL);
				}
				catch(Exception e){
					e.printStackTrace();
				}
			}
		});

		CLP.addListener(SWT.Selection, new Listener() {
			public void handleEvent(Event event) {
				try{
					//initializeInput(); 
					m_osolWriter.addOtherOption("subSolver", "clp", "sub solver of coin like clp or glpk");
					String sOSoL = m_osolWriter.writeToString();
					//m_osSolverAgent.solverAddress = m_sCOINSolverServiceAddress;
					m_osSolverAgent.solverAddress = m_sCLPSolverServiceAddress;
					m_sOSiL = osilText.getText();
					String sOSrL = m_osSolverAgent.solve(m_sOSiL, sOSoL);
					//COINSolverService coinSolverService = new COINSolverService();
					//String sOSrL = coinSolverService.solve(m_sOSiL, sOSoL);
					solutionText.setText( sOSrL);

				}
				catch(Exception e){
					e.printStackTrace();
				}
			}
		});

		CBC.addListener(SWT.Selection, new Listener() {
			public void handleEvent(Event event) {
				try{
					//initializeInput(); 
					m_osolWriter.addOtherOption("subSolver", "cbc", "sub solver of coin like cbc or glpk");
					String sOSoL = m_osolWriter.writeToString();
					//m_osSolverAgent.solverAddress = m_sCOINSolverServiceAddress;
					m_osSolverAgent.solverAddress = m_sCBCSolverServiceAddress;
					m_sOSiL = osilText.getText();
					String sOSrL = m_osSolverAgent.solve(m_sOSiL, sOSoL);
					//COINSolverService coinSolverService = new COINSolverService();
					//String sOSrL = coinSolverService.solve(m_sOSiL, sOSoL);
					solutionText.setText( sOSrL);

				}
				catch(Exception e){
					e.printStackTrace();
				}
			}
		});

		GLPK.addListener(SWT.Selection, new Listener() {
			public void handleEvent(Event event) {
				try{
					//initializeInput(); 
					m_osolWriter.addOtherOption("subSolver", "glpk", "sub solver of coin like clp, cbc or glpk");
					String sOSoL = m_osolWriter.writeToString();
					m_osSolverAgent.solverAddress = m_sCOINSolverServiceAddress;
					m_sOSiL = osilText.getText();
					String sOSrL = m_osSolverAgent.solve(m_sOSiL, sOSoL);
//					COINSolverService coinSolverService = new COINSolverService();
//					String sOSrL = coinSolverService.solve(m_sOSiL, sOSoL);
					solutionText.setText( sOSrL);

				}
				catch(Exception e){
					e.printStackTrace();
				}
			}
		});

	}//createMenu
	
	
	/**
	 * Open a file. 
	 * 
	 * @return the name of the selected file. 
	 */
	public static String openFile(){
		String[] filterExtensions = {"*.*", "*.osml", "*.xq", "*.xml"};
		String selectedFile = null;
		FileDialog openFileDialog = new FileDialog(shell, SWT.OPEN);
		openFileDialog.setText( "Open query file:");
		openFileDialog.setFilterPath("./xml");
		openFileDialog.setFilterExtensions(filterExtensions);
		selectedFile = openFileDialog.open();
		return selectedFile; 
	}//openFileDialog
	
	/**
	 * Save a file. 
	 * 
	 * @return the name of the saved file. 
	 */
	public static String saveFile(){
		boolean yes = true;
		String[] filterExtensions = {"*.*", "*.osml", "*.xq", "*.xml"};
		String selectedFile = null;
		FileDialog saveFileDialog = new FileDialog(shell, SWT.SAVE);
		saveFileDialog.setText( "Save query file:");
		saveFileDialog.setFilterPath(".");
		saveFileDialog.setFilterExtensions(filterExtensions);
		selectedFile = saveFileDialog.open();
		if(selectedFile != null){
			File file = new File( selectedFile);
			if (file.exists()){
				MessageBox mbox = new MessageBox(saveFileDialog.getParent(), 
						SWT.ICON_WARNING | SWT.YES | SWT.NO);
				mbox.setMessage(selectedFile + "exists. Do you want to replace it" );
				yes = mbox.open() == SWT.YES;
				if (!yes)return null;
			}
			return selectedFile;
		}
		else return selectedFile;	
	}//saveFileDialog

	
	
	/**
	 * Open the OSmL GUI application. 
	 * 
	 * @param display holds various display parameters. 
	 * @return the GUI shell. 
	 */
	public Shell open (Display display) {
		//createShell (display);
		shell = new Shell (display);
		shell.setLayout(new FillLayout());
		shell.setText ( "OSmLGUI");	
		font = new Font(display, "Arial", 12, SWT.NORMAL);
		tabFolder = new TabFolder(shell, SWT.NONE);
		theModel = new TabItem(tabFolder, SWT.BORDER);
		theModel.setText("The Model");
		osmlText = new Text(tabFolder, SWT.MULTI | SWT.BORDER | SWT.WRAP | SWT.V_SCROLL);
		osmlText.setLayoutData(new GridData(GridData.FILL_BOTH));
		osmlText.setFont( font);
		theModel.setControl( osmlText);
		createMenu();
		// Use the following if you want to write the model using sytlized text
		//createStyledText ();

		thepreParsedModel = new TabItem(tabFolder, SWT.BORDER);
		thepreParsedModel.setText("PreParsed Model");
		preParsedText = new Text(tabFolder, SWT.MULTI | SWT.BORDER | SWT.WRAP | SWT.V_SCROLL);
		preParsedText.setLayoutData(new GridData(GridData.FILL_BOTH));
		preParsedText.setFont( font);
		thepreParsedModel.setControl( preParsedText);
		
		thequeryResult = new TabItem(tabFolder, SWT.BORDER);
		thequeryResult.setText("Query Result");
		queryResultText = new Text(tabFolder, SWT.MULTI | SWT.BORDER | SWT.WRAP | SWT.V_SCROLL);
		queryResultText.setLayoutData(new GridData(GridData.FILL_BOTH));
		queryResultText.setFont( font);
		thequeryResult.setControl( queryResultText);
		
		theOSiL = new TabItem(tabFolder, SWT.BORDER);
		theOSiL.setText("instance (OSiL)");
		osilText = new Text(tabFolder, SWT.MULTI | SWT.BORDER | SWT.WRAP | SWT.V_SCROLL);
		osilText.setLayoutData(new GridData(GridData.FILL_BOTH));
		osilText.setFont( font);
		theOSiL.setControl( osilText);
//		thePostFix = new TabItem(tabFolder, SWT.BORDER);
//		thePostFix.setText("PostFix Instance");
//		postfixText = new Text(tabFolder, SWT.MULTI | SWT.BORDER | SWT.WRAP | SWT.V_SCROLL);
//		postfixText.setLayoutData(new GridData(GridData.FILL_BOTH));
//		postfixText.setFont( font);
//		thePostFix.setControl( postfixText);

		
		theOSoL = new TabItem(tabFolder, SWT.BORDER);
		theOSoL.setText("option (OSoL)");
		osolText = new Text(tabFolder, SWT.MULTI | SWT.BORDER | SWT.WRAP | SWT.V_SCROLL);
		osolText.setLayoutData(new GridData(GridData.FILL_BOTH));
		osolText.setFont( font);
		theOSoL.setControl( osolText);
		osolText.setText(m_osolWriter.writeToString());
		
		theService = new TabItem(tabFolder, SWT.BORDER);
		theService.setText("Service");
		serviceText = new Text(tabFolder, SWT.MULTI | SWT.BORDER | SWT.WRAP | SWT.V_SCROLL);
		serviceText.setText("lindo");		
		serviceText.setLayoutData(new GridData(GridData.FILL_BOTH));
		serviceText.setFont( font);
		theService.setControl( serviceText);

		theJobID = new TabItem(tabFolder, SWT.BORDER);
		theJobID.setText("JobID");

		jobIDText = new Text(tabFolder, SWT.MULTI | SWT.BORDER | SWT.WRAP | SWT.V_SCROLL);
		jobIDText.setLayoutData(new GridData(GridData.FILL_BOTH));
		jobIDText.setFont( font);
		theJobID.setControl( jobIDText);
	
		theOSrL = new TabItem(tabFolder, SWT.BORDER);
		theOSrL.setText("output");
		solutionText = new Text(tabFolder, SWT.MULTI | SWT.BORDER | SWT.WRAP | SWT.V_SCROLL);
		solutionText.setLayoutData(new GridData(GridData.FILL_BOTH));
		solutionText.setFont( font);
		theOSrL.setControl( solutionText);

		
		shell.setSize(700, 600);
		shell.open ();
		return shell;
	}//open

	/**
	 * Create styled text. 
	 *
	 */
	public void createStyledText() {
		//initializeColors();
		/*osmlText = new StyledText (tabFolder, SWT.BORDER | SWT.MULTI | SWT.V_SCROLL);
		 GridData spec = new GridData();
		 spec.horizontalAlignment = GridData.FILL;
		 spec.grabExcessHorizontalSpace = true;
		 spec.verticalAlignment = GridData.FILL;
		 spec.grabExcessVerticalSpace = true;
		 osmlText.setLayoutData(spec);
		 osmlText.setFont( font);
		 theModel.setControl(osmlText);
		 */
	}//createStyleText
	
	/**
	 * main for test purposes.
	 *
	 * </p>
	 *
	 * @param argv command line arguments.
	 */
	public static void main(String[] args) throws Exception {
		/* Before this is run, be sure to set up the following in the launch configuration 
		 * (Arguments->VM Arguments) for the correct SWT library path. 
		 * The following is a windows example:
		 * -Djava.library.path="installation_directory\plugins\org.eclipse.swt.win32_3.0.0\os\win32\x86"
		 */
		OSmLGUI thisClass = new OSmLGUI();
		Display display = new Display ();
		shell = thisClass.open (display);		
		while (!shell.isDisposed()) {
			if (!display.readAndDispatch()) display.sleep ();
		}
		display.dispose();		
	}//main
	
	/**
	 * static constructor
	 */
	static{
	}//static constructor
	
}//class OSmLGUI

