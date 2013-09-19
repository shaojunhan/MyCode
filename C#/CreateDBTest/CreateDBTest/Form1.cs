using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using System.Data.SqlClient;
using System.Data.Sql;
using System.Data.SqlTypes;

namespace CreateDBTest
{
    public partial class dbForm : Form
    {
        //数据库表
        private string tableName;

        public dbForm()
        {
            InitializeComponent();

            //获得表名
            if (radioButton1.Checked)
                tableName = radioButton1.Text;
            else if (radioButton2.Checked)
                tableName = radioButton2.Text;
            else if (radioButton3.Checked)
                tableName = radioButton3.Text;
        }

        private void dbForm_Load(object sender, EventArgs e)
        {
            //连接字符串
            string connectionString = Properties.Settings.Default.MydatabaseConnectionString;
            //SqlConnection实例
            SqlConnection conn = new SqlConnection(connectionString);
            //SqlDataAdapter实例
            SqlDataAdapter adapter = new SqlDataAdapter("select * from MajorTable", conn);
            //DataSet实例
            DataTable dataTable = new DataTable();
            //Fill方法
            adapter.Fill(dataTable);
        
            //添加数据
            DataRow row = dataTable.NewRow();
            row["编码"] = "001";
            row["专业名称"] = "计算机科学与技术";
            dataTable.Rows.Add(row);
            //引用表
            dbGridView.DataSource = dataTable;
            dbListBox.DataSource = dataTable;
        }

        private void button1_Click(object sender, EventArgs e)
        {
            //数据
            DataTable table = GetGridViewData();
            //设置dbGridView的item
            dbGridView.DataSource = table;
            //设置ListBox数据
            dbListBox.DataSource = table;
            dbListBox.DisplayMember = "编码";
        }

        private void button2_Click(object sender, EventArgs e)
        {

        }

        private void radioButton_CheckedChanged(object sender, EventArgs e)
        {
            //获取表名
            tableName = (sender as RadioButton).Text;
        }

        //设置ListBox的数据
        private SqlDataReader GetListBoxData()
        {
            //连接字符创
            string connectionString = Properties.Settings.Default.MydatabaseConnectionString;
            //SqlConnection实例
            SqlConnection conn = new SqlConnection(connectionString);
            //SqlCommand实例
            SqlCommand command = new SqlCommand("select * from "+tableName, conn);
            //打开数据连接
            try
            {
                conn.Open();
                return command.ExecuteReader();
            }
            catch (Exception e)
            {
                MessageBox.Show("连接数据库错误!");
                return null;
            }
        }
        //设置DataGridView的数据
        private DataTable GetGridViewData()
        {
            //连接字符串
            string connectionString = Properties.Settings.Default.MydatabaseConnectionString;
            //SqlConnection实例
            SqlConnection conn = new SqlConnection(connectionString);
            //SqlDataAdapter实例
            SqlDataAdapter adapter = new SqlDataAdapter("select * from "+tableName, conn);
            //DataTable实例
            DataTable table = new DataTable();
            //填充数据
            adapter.Fill(table);
            return table;
        }

    }
}
