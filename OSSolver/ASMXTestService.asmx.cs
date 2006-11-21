using System;
using System.Collections;
using System.ComponentModel;
using System.Data;
using System.Diagnostics;
using System.Web;
using System.Web.Services;

/// <summary>
/// Summary description for ASMXTestService.
/// 
/// @author Jun Ma	
/// @version 1.0, 09/01/2005
/// @since OS 1.0
/// @copyright (c) 2005
/// </summary>
[WebService(Namespace="org.optimizationservices.ossolver")]
public class ASMXTestService : System.Web.Services.WebService{

	private static int counter = 0;

	public ASMXTestService(){
		//CODEGEN: This call is required by the ASP.NET Web Services Designer
		InitializeComponent();
	}//constructor

	#region Component Designer generated code
	
	//Required by the Web Services Designer 
	private IContainer components = null;
			
	/// <summary>
	/// Required method for Designer support - do not modify
	/// the contents of this method with the code editor.
	/// </summary>
	private void InitializeComponent() {
	}

	/// <summary>
	/// Clean up any resources being used.
	/// </summary>
	protected override void Dispose( bool disposing ) {
		if(disposing && components != null) {
			components.Dispose();
		}
		base.Dispose(disposing);		
	}
	
	#endregion

	/// <summary>
	/// test csharp asmx method
	/// </summary>
	/// <param name="input">any input</param>
	/// <returns></returns>
	[WebMethod]
	public string helloCSharp(string input){
		counter++;
		return input + " [asmx return" + counter + "]";
	}//helloCSharp

}//ASMXTestService
