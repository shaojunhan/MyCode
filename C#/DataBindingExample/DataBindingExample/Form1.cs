using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using System.Data.SqlClient;

namespace DataBindingExample
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
            //居中显示
            this.StartPosition = FormStartPosition.CenterScreen;
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            MyDatabaseDataSetTableAdapters.MyTable2TableAdapter adapter = 
                new MyDatabaseDataSetTableAdapters.MyTable2TableAdapter();//适配器

            MyDatabaseDataSet dataSet = new MyDatabaseDataSet();//数据集

            adapter.Fill(dataSet.MyTable2);//填充数据集
            
            //新建绑定源对象
            BindingSource bindingSource1 = new BindingSource();
            bindingSource1.DataSource = dataSet;
            bindingSource1.DataMember = "MyTable2";

            //绑定数据
            textBox1.DataBindings.Add( "Text", bindingSource1, "学院名称" );//把bindingSource1中的学院名称绑定到textBox1的Text
            
            listBox1.DataSource = bindingSource1;
            listBox1.DisplayMember = "学院名称";//显示数据源的"学院名称"项
            listBox1.ValueMember = "学院代号";

            dataGridView1.DataSource = bindingSource1;
            //显示选中的Value值
            textBox2.Text = listBox1.SelectedValue.ToString();
        }

        private void listBox1_SelectedIndexChanged(object sender, EventArgs e)
        {
            //显示Value值
            ListBox lBox = (ListBox)sender;
            textBox2.Text = lBox.SelectedValue.ToString();
        }
    }
}
