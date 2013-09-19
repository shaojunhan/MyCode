using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using System.Data.SqlTypes;
using System.Data.SqlClient;

namespace CreateDataTableExample
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            this.StartPosition = FormStartPosition.CenterScreen;//程序居与屏幕正中显示
        }
        //显示按钮的响应事件
        private void button1_Click(object sender, EventArgs e)
        {
            DataTable table = new DataTable();

            //增加新的列
            table.Columns.Add( "学号", typeof(SqlString) );
            table.Columns.Add( "姓名", typeof(SqlString) );
            table.Columns.Add( "年龄", typeof(SqlInt32));
            table.Columns.Add( "性别", typeof(SqlString) );
            table.Columns.Add( "联系电话", typeof(SqlString) );

            //主键设置
            DataColumn[] key = new DataColumn[1];
            key[0] = table.Columns["学号"];
            table.PrimaryKey = key;

            //测试数据
            DataRow row = table.NewRow();
            row["学号"] = "0304110504";
            row["姓名"] = "韩少军";
            row["年龄"] = 23;
            row["性别"] = "男";
            row["联系电话"] = "18262284686";
            
            //增加新的行
            table.Rows.Add(row);
            //设置数据源（数据绑定）
            dataGridView1.DataSource = table;
        }

        //显示数据库表
        private void button2_Click(object sender, EventArgs e)
        {
            SqlConnection conn = new SqlConnection();//数据库连接及连接字符串
            conn.ConnectionString = Properties.Settings.Default.CollegeDatabaseConnectionString;

            string tableName = "CollegeTable";//数据表名
            SqlDataAdapter adapter = new SqlDataAdapter( "select * from " + tableName, conn );//SqlAdapter实例

            DataSet dataSet = new DataSet();//数据集DataSet实例

            adapter.Fill(dataSet);//填充数据到数据集
            dataGridView1.DataSource = dataSet.Tables[0];//设置数据源
        }
    }
}
