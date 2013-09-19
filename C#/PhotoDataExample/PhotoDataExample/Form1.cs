using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using System.Data.SqlClient;
using System.IO;
using System.Data.SqlTypes;

namespace PhotoDataExample
{
    public partial class Form1 : Form
    {
        //数据
        private DataTable table;
        private SqlDataAdapter adapter;
        private BindingSource bindingSoruce1;
        private string studentName;
        private Stream stream;
        
        public Form1()
        {
            InitializeComponent();
            //居中显示
            this.StartPosition = FormStartPosition.CenterScreen;
            studentName = "";

            //初始化对象
            table = new DataTable();
            bindingSoruce1 = new BindingSource();
            adapter = new SqlDataAdapter("select * from MyTable3",
                Properties.Settings.Default.MyDatabaseConnectionString);
            //自动生成select，delete ，update 语句
            SqlCommandBuilder builder = new SqlCommandBuilder(adapter);

            adapter.Fill(table);//填充表
            bindingSoruce1.DataSource = table;//数据绑定

            listBox1.DataSource = table;//数据绑定，显示数据位姓名，valueMember为学号
            listBox1.DisplayMember = "姓名";
            listBox1.ValueMember = "学号";

            pictureBox1.DataBindings.Add("Image", bindingSoruce1, "照片", true);//把照片绑定到pictureBox1.Image字段
            bindingNavigator1.BindingSource = bindingSoruce1;
        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }

        //
        private void buttonOut1_Click(object sender, EventArgs e)
        {
            if (!studentName.Equals(""))
            {
                string connectionString = Properties.Settings.Default.MyDatabaseConnectionString;//连接字符串
                string selectString = "select 照片 from Mytable3 where 姓名=@name";//SqlCommand语句

                using (SqlConnection conn = new SqlConnection(connectionString))
                {
                    SqlCommand cmd = new SqlCommand(selectString, conn);
                    cmd.Parameters.Add("@name", SqlDbType.NVarChar).Value = studentName;//参数
                    conn.Open();//打开连接
                    SqlDataReader reader = cmd.ExecuteReader();//执行

                    try
                    {
                        reader.Read();//读取(必须先读取)

                        if (reader[0].GetType() != typeof(DBNull))//首字节为数据类型
                        {
                            byte[] image = (byte[])reader[0];//首字节后的内存为数据

                            MemoryStream memoryStream = new MemoryStream(image);//内存流
                            Bitmap bitmap = new Bitmap(memoryStream);//流中创建对象

                            pictureBox1.Image = bitmap;//设置图片

                            Graphics g = panel1.CreateGraphics();//在panel1创建画刷、绘图
                            g.DrawImage(bitmap, panel1.DisplayRectangle);//默认控件尺寸

                            g.Dispose();//注销掉，释放内存
                            memoryStream.Dispose();
                        }
                        else
                        {
                            MessageBox.Show("导出失败");
                        }
                    }
                    catch (Exception e2)
                    {
                        MessageBox.Show("数据读取失败");
                    }
                    finally
                    {
                        reader.Close();
                    }
                }
            }
            else
            {
                MessageBox.Show("请从列表选择");
            }
        }

        //
        private void buttonIn1_Click(object sender, EventArgs e)
        {
            OpenFile();//得到流

            if (stream != null)
            {
                string connectionString = Properties.Settings.Default.MyDatabaseConnectionString;//连接字符串
                string updateString = "update MyTable3 set 照片=@photo where 姓名=@name";//SqlCommand语句

                if (!studentName.Equals(""))
                {
                    using (SqlConnection conn = new SqlConnection(connectionString))//using确保数据库关闭
                    {
                        SqlCommand cmd = new SqlCommand(updateString, conn);//SqlCommand实例
                        cmd.Parameters.Add("@name", SqlDbType.NVarChar).Value = studentName;//参数
                        byte[] bs = new byte[stream.Length];//数据

                        stream.Read( bs, 0, (int)(stream.Length - 1) );//流中读取数据到内存

                        cmd.Parameters.Add("@photo", SqlDbType.Image).Value = bs;//参数

                        conn.Open();//打开数据连接
                        cmd.ExecuteNonQuery();//执行语句
                    }

                    MessageBox.Show("导入成功");
                }
                else
                {
                    MessageBox.Show("请从列表中选择");
                }
            }
            else
            {
                MessageBox.Show("内存读取错误");
            }
        }

        //打开
        private void OpenFile()
        {
            OpenFileDialog file = new OpenFileDialog();
            file.Filter = "图片文件|*.jpg;*.gif;*.bmp;*.png;*.tiff";//过滤器
            if (file.ShowDialog() == DialogResult.OK)//返回OK
            {
                stream = file.OpenFile();//打开流
            }
            else
            {
               stream = null;
            }
        }

        //
        private void listBox1_SelectedIndexChanged(object sender, EventArgs e)
        {
            ListBox listBox1 = sender as ListBox;//类型转换

            studentName = listBox1.Text;//当前选择项的文本

            //使导航控件移动到指定位置(即同步，之所以这样设置，是因为listBox1和bindingNavigator1在两个不同的GroupBox中)
            while( bindingSoruce1.Position < listBox1.SelectedIndex){
                bindingSoruce1.MoveNext();
            }

            while (bindingSoruce1.Position > listBox1.SelectedIndex)
            {
                bindingSoruce1.MovePrevious();
            }
        }

        //绑定Image的导入
        private void buttonIn2_Click(object sender, EventArgs e)
        {
            OpenFile();

            if (stream != null)
            {
                if (pictureBox1.Image != null)
                    pictureBox1.Image.Dispose();

                Bitmap bitmap = new Bitmap(stream);//从流中构造图片
                pictureBox1.Image = bitmap;//设置图片

                bindingSoruce1.EndEdit();//结束编辑后再更新数据库
                adapter.Update(table);//更新数据库

                MessageBox.Show("导入成功");
            }
            else
            {
                MessageBox.Show("内存读取失败");
            }
        }
    }
}
