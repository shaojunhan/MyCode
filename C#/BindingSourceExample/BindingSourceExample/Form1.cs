using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace BindingSourceExample
{
    public partial class Form1 : Form
    {
        //绑定数据源
        private BindingSource bindingSource1;

        public Form1()
        {
            InitializeComponent();
            //居中显示，边框固定
            this.StartPosition = FormStartPosition.CenterScreen;
            this.FormBorderStyle = FormBorderStyle.Fixed3D;
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            List<Font> fonts = new List<Font>();//字体列表
            //获得系统字体
            for (int i = 0; i < FontFamily.Families.Length; i++)
            {
                if (FontFamily.Families[i].IsStyleAvailable(FontStyle.Regular))
                {
                    Font font = new Font(FontFamily.Families[i], 20.0f, FontStyle.Regular);

                    fonts.Add(font);
                }
            }

            //实例化绑定数据源
            bindingSource1 = new BindingSource();
            bindingSource1.DataSource = fonts;//数据源

            //绑定数据
            label1.DataBindings.Add("Text", bindingSource1, "Name");//字体名与Text绑定
            listBox1.DataSource = bindingSource1;
            listBox1.DisplayMember = "Name";//显示字体名

            //导航数据绑定
            bindingNavigator1.BindingSource = bindingSource1;
        }

        private void listBox1_SelectedIndexChanged(object sender, EventArgs e)
        {
            label1.Font = (Font)bindingSource1.Current;//当前字体
          
        }
    }
}
