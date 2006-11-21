using System;
using System.Drawing;
using System.Collections;
using System.ComponentModel;
using System.Windows.Forms;
using org.optimizationservices.ossolver.solver;

namespace org.optimizationservices.osmodeler.gui{
	/// <summary>
	/// <c>OSmLGUI</c> GUI for OSmL. 
	/// @author Jun Ma	
	/// @version 1.0, 09/01/2005
	/// @since OS 1.0
	/// @copyright (c) 2005
	/// </summary>
	public class OSmLGUI : System.Windows.Forms.Form{
		private System.Windows.Forms.TextBox textBox1;
		private System.Windows.Forms.Button button1;
		/// <summary>
		/// Required designer variable.
		/// </summary>
		private System.ComponentModel.Container components = null;


		private CGSolver m_cgSolver = new CGSolver();

		public OSmLGUI(){
			//
			// Required for Windows Form Designer support
			//
			InitializeComponent();

			//
			// TODO: Add any constructor code after InitializeComponent call
			//
		}//construcotr

		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		protected override void Dispose( bool disposing ){
			if( disposing ) {
				if(components != null) {
					components.Dispose();
				}
			}
			base.Dispose( disposing );
		}//Dispose

		#region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		private void InitializeComponent() {
			this.textBox1 = new System.Windows.Forms.TextBox();
			this.button1 = new System.Windows.Forms.Button();
			this.SuspendLayout();
			// 
			// textBox1
			// 
			this.textBox1.Location = new System.Drawing.Point(16, 24);
			this.textBox1.Name = "textBox1";
			this.textBox1.Size = new System.Drawing.Size(344, 20);
			this.textBox1.TabIndex = 0;
			this.textBox1.Text = "textBox1";
			// 
			// button1
			// 
			this.button1.Location = new System.Drawing.Point(24, 80);
			this.button1.Name = "button1";
			this.button1.TabIndex = 1;
			this.button1.Text = "button1";
			this.button1.Click += new System.EventHandler(this.button1_Click);
			// 
			// OSmLGUI
			// 
			this.AutoScaleBaseSize = new System.Drawing.Size(5, 13);
			this.ClientSize = new System.Drawing.Size(800, 510);
			this.Controls.Add(this.button1);
			this.Controls.Add(this.textBox1);
			this.Name = "OSmLGUI";
			this.Text = "OSmLGUI";
			this.Load += new System.EventHandler(this.OSmLGUI_Load);
			this.ResumeLayout(false);

		}
		#endregion

		private void OSmLGUI_Load(object sender, System.EventArgs e){
		
		}//OSmLGUI_Load
		private void button1_Click(object sender, System.EventArgs e) {
			m_cgSolver.osil = "abc";
			m_cgSolver.solve();
			string sResult = m_cgSolver.osol;
			textBox1.Text = sResult;
		}
		/// <summary>
		/// OSmL GUI main entry point
		/// </summary>
		[STAThread]
		public static void Main(){
			Application.Run(new OSmLGUI());
		}//main


	}//class OSmLGUI
}//namespace
