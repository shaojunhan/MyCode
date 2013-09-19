using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using System.Data.SqlClient;
using CrystalDecisions.CrystalReports.Engine;

namespace SimpleCrystalReportExample
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();

            this.StartPosition = FormStartPosition.CenterScreen;
            myTable3TableAdapter1.Fill(myDatabaseDataSet1.MyTable3);

            MyCrystalReport myTable3Report = new MyCrystalReport();
            myTable3Report.SetDataSource(myDatabaseDataSet1);

            ReportDocument document = (ReportDocument)myTable3Report;
            document.SummaryInfo.ReportTitle = "学生基本情况表";

            crystalReportViewer1.ReportSource = document;
            crystalReportViewer1.Zoom(75);//
        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }
    }
}
