using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace CreateDatabaseExample
{
    public partial class Form2 : Form
    {
        private DataClass data;
        private const int eight = 8;
        public Form2(ref DataClass data)
        {
            InitializeComponent();
            //事件响应
            textBox1.TextChanged +=new EventHandler(textBox_TextChanged);
            textBox2.TextChanged += new EventHandler(textBox_TextChanged);
            textBox3.TextChanged += new EventHandler(textBox_TextChanged);
            textBox4.TextChanged += new EventHandler(textBox_TextChanged);
            textBox5.TextChanged += new EventHandler(textBox_TextChanged);
            textBox6.TextChanged += new EventHandler(textBox_TextChanged);
            textBox7.TextChanged += new EventHandler(textBox_TextChanged);
            textBox8.TextChanged += new EventHandler(textBox_TextChanged);

            //数据
            data = new DataClass(eight);
            this.data = data;
            //初始显示位置
            this.StartPosition = FormStartPosition.CenterParent;

        }

        private void Form2_Load(object sender, EventArgs e)
        {
 

        }

        //textBox事件响应
        private void textBox_TextChanged(object sender, EventArgs e)
        {
            TextBox tBox = sender as TextBox;//类型转换

            string s = tBox.Name;//名字字符串
            string num = s.Substring(s.Length-1,1);//获取数字

            try
            {
                data.SetAt( int.Parse(num) - 1, tBox.Text.Trim() );
            }
            catch (Exception e2)
            {
                MessageBox.Show(e2.ToString(),"错误",MessageBoxButtons.OK,MessageBoxIcon.Error);
            }
        }

        //取消按钮响应
        private void button2_Click(object sender, EventArgs e)
        {
            this.Close(); //关闭窗体
        }

        //提交更新数据
        private void button1_Click(object sender, EventArgs e)
        {
            //判断数据是否合法
            if (IsLegal())
            {
                this.Close();

            }else
            {
                MessageBox.Show("数据不符合要求!","错误",MessageBoxButtons.OK,MessageBoxIcon.Error);
                return;
            }
        }

        //数据是否合法
        private bool IsLegal()
        {
            if (data.GetAt(0) != null && data.GetAt(0).Length > 0)
            {
                if (data.GetAt(5) != null && data.GetAt(5).Length > 0)
                {
                    return true;
                }
                else
                {
                    return false;
                }
            }
            else
            {
                return false;
            }
        }
    }
}
