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

namespace CreateDatabaseExample
{
    public partial class Form1 : Form
    {
        //单选项标记
        private string checkedName;
        //待更新的数据
        private DataClass data;
        //数据库
        private string connectionString;//连接字符串
        private SqlConnection conn;//SlqConnection实例
        private SqlCommand cmd;//SqlCommand实例

        //构造(System生成)
        public Form1()
        {
            InitializeComponent();
            //单选项的响应事件
            radioButton1.CheckedChanged += new EventHandler(radioButton_CheckedChanged);
            radioButton2.CheckedChanged += new EventHandler(radioButton_CheckedChanged);
            radioButton3.CheckedChanged += new EventHandler(radioButton_CheckedChanged);

            //数据库连接字符串
            connectionString = Properties.Settings.Default.MyDatabaseConnectionString;
            //数据库连接对象SqlConnection实例
            conn = new SqlConnection();
            //数据库操作对象实例SqlCommand实例
            cmd = new SqlCommand();

            //窗体在屏幕正中显示
            this.StartPosition = FormStartPosition.CenterScreen;
        }
       
        //按钮button1的单击事件响应(System生成)
        private void button1_Click(object sender, EventArgs e)
        {
            this.Cursor = Cursors.WaitCursor;//光标为等待状态

            switch (checkedName)
            {
                case "radioButton1":
                    ShowAllName();//显示所有名字
                    break;
                case "radioButton2":
                    ShowAllMajor();//显示所有学院+专业
                    break;
                case "radioButton3":
                    AddNewData();
                    break;
            }
            this.Cursor = Cursors.Default;//光标恢复
        }

        //单选项的响应事件
        private void radioButton_CheckedChanged(object sender, EventArgs e)
        {
            RadioButton r = (RadioButton)sender;
            if (r.Checked)
                checkedName = r.Name;//标记名字
        }

        //显示所有人的姓名
        private void ShowAllName()
        {
            //连接字符串
            conn.ConnectionString = connectionString;
            //Sql命令
            cmd.CommandText = "select 姓名 from MyTable1";
            cmd.Connection = conn;
            listBox1.Items.Clear();//清空列表

            //数据库连接并读取数据
            try
            {
                conn.Open();//连接
                //读取数据
                SqlDataReader r = cmd.ExecuteReader();
                //在列表中显示数据
                while (r.Read())
                {
                    listBox1.Items.Add(string.Format("{0}", r[0]));
                }
                r.Close();
            }
            catch (Exception e)
            {
                listBox1.Items.Add( e.ToString() );
            }
            finally
            {
                conn.Close();//关闭数据库连接
            }
        }

        //显示所有专业
        private void ShowAllMajor()
        {
            conn.ConnectionString = connectionString;//连接字符串
            SqlCommand cmd1 = new SqlCommand( "select 学院,专业 from MyTable1", conn);//学院
            listBox1.Items.Clear();//清空列表

            try
            {
                conn.Open();//连接
                SqlDataReader r = cmd1.ExecuteReader();//读取数据
                while( r.Read() )
                {

                    if ( r[0] != null || r[1] != null)
                        listBox1.Items.Add( string.Format("【{0}】{1}", r[0], r[1]) );
                }
                r.Close();//读取数据
            }
            catch (Exception e)
            {
                listBox1.Items.Add( e.ToString() );
            }
            finally
            {
                conn.Close();//关闭数据库
            }
        }

        //增加新的数据
        private void AddNewData()
        {
            Form2 form2 = new Form2(ref data);
            form2.Owner = this;
            DialogResult result = form2.ShowDialog();
            listBox1.Items.Clear();//清空

            if (reslut == DialogResult.OK)
            {
                //对话框关闭后
                conn.ConnectionString = connectionString;//连接字符串
                cmd.Connection = conn;
                string insertValues = "";//字符串
                //字符串处理
                for (int i = 0; i < data.Size; i++)
                {
                    if (data.GetAt(i) == null || data.GetAt(i).Length <= 0)
                        insertValues += "null,";
                    else
                        insertValues += "'" + data.GetAt(i) + "',";
                }

                string s = insertValues.Substring(0, insertValues.Length - 1);//移除尾部的逗号

                cmd.CommandText = "insert into MyTable1 values(" + s + ")";//组拼SQL语句

                //插入
                try
                {
                    conn.Open();//连接
                    int i = cmd.ExecuteNonQuery();//插入
                    listBox1.Items.Add(string.Format("在第{0}行插入数据成功", i));//提示

                }
                catch (Exception e)
                {
                    listBox1.Items.Add(e.ToString());//提示信息
                }
                finally
                {
                    conn.Close(); //关闭连接
                }
            }
            else
            {
                listBox1.Items.Add("没有信息需要更新到数据库");//提示
            }
        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }
    }
}
