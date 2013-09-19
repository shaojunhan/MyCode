using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace ComplexCrystalReportExample
{
    public partial class Form1 : Form
    {
        private StudentCrystalReport stuReport;

        public Form1()
        {
            InitializeComponent();
            //居中显示
            this.StartPosition = FormStartPosition.CenterScreen;

            //注册事件
            radioButtonAll.CheckedChanged += new EventHandler(radioButton_CheckedChanged);
            radioButtonHan.CheckedChanged += new EventHandler(radioButton_CheckedChanged);
            radioButtonGPA.CheckedChanged += new EventHandler(radioButton_CheckedChanged);
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            //填充数据
            myTable2TableAdapter1.Fill(myDatabaseDataSet1.MyTable2);
            myTable3TableAdapter1.Fill(myDatabaseDataSet1.MyTable3);
            myTable4TableAdapter1.Fill(myDatabaseDataSet1.MyTable4);
            //实例化StudentCtystalReport
            stuReport = new StudentCrystalReport();
            stuReport.SetDataSource(myDatabaseDataSet1);//设置数据源
            stuReport.SummaryInfo.ReportTitle = "学生基本情况表";//表标题
            radioButtonAll.Checked = true;//"全部学生"选项选中
        }

        //注册事件
        private void radioButton_CheckedChanged(object sender, EventArgs e)
        {
            RadioButton radioButton = sender as RadioButton;//类型转换
            stuReport.SetDataSource(myDatabaseDataSet1);//更新数据源

            switch (radioButton.Text)//根据文本判断显示报表
            {
                case "全部学生":
                    stuReport.RecordSelectionFormula = "";
                    break;

                case "所有姓韩的学生":
                    stuReport.RecordSelectionFormula = "{MyTable3.姓名} like '韩*'";
                    break;

                case "GPA大于3.00的学生":
                    stuReport.RecordSelectionFormula = "{MyTable3.GPA} > 3.00";
                    break;
            }

            crystalReportViewer1.ReportSource = stuReport;//设置报表数据源
            crystalReportViewer1.Zoom(76);//缩放为76%
        }
    }
}
