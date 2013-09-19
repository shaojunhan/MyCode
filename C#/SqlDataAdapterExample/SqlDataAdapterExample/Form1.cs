using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using System.Data.SqlClient;
using System.Data.SqlTypes;

namespace SqlDataAdapterExample
{
    public partial class Form1 : Form
    {
        //数据
        private DataTable table;
        private SqlDataAdapter adapter;

        public Form1()
        {
            InitializeComponent();
            this.StartPosition = FormStartPosition.CenterScreen;//在屏幕中居中显示
        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }

        //显示数据按钮的响应事件
        private void button1_Click(object sender, EventArgs e)
        {
            this.Cursor = Cursors.WaitCursor;//光标等待

            string tableName = "MyTable1";
            SqlConnection conn = new SqlConnection();//SqlConnection对象
            conn.ConnectionString = Properties.Settings.Default.MyDatabaseConnectionString;//连接字符串
            adapter = new SqlDataAdapter("select * from " + tableName, conn);
            //SQL命令
            SqlCommandBuilder builder = new SqlCommandBuilder(adapter);

            adapter.UpdateCommand = builder.GetUpdateCommand();
            adapter.InsertCommand = builder.GetInsertCommand();
            adapter.DeleteCommand = builder.GetDeleteCommand();
            //填充表
            table = new DataTable();
            adapter.Fill(table);
            dataGridView1.DataSource = table;

            this.Cursor = Cursors.Default;//光标恢复默认
        }

        //更新按钮的响应事件
        private void 更新数据_Click(object sender, EventArgs e)
        {
            dataGridView1.EndEdit();//停止编辑

            try
            {
                adapter.Update(table);//更新数据
                MessageBox.Show("更新成功");
            }
            catch (Exception e2)
            {
                DataTable tablePrompt = new DataTable();//新建信息提示表
                tablePrompt.Columns.Add("错误");

                DataRow row = tablePrompt.NewRow();//行信息
                row["错误"] = e2.ToString();

                tablePrompt.Rows.Add(row);//增加一行
                dataGridView1.DataSource = tablePrompt;//显示提示信息
            }
        }
    }
}
