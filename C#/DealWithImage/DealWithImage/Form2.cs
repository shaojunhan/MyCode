using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace DealWithImage
{
    public partial class Form2 : Form
    {
        private FormDealImage father;
        //带参的构造
        public Form2()
        {
            InitializeComponent();
            Init();

        }

        //初始化
        private void Init()
        {
            string[] items = new string[4];
            for (int i = 0; i < items.Length; i++)
            {
                items[i] = (i+3).ToString();
                comboBox1.Items.Add(items[i]);
            }
        }

        private void Form2_Load(object sender, EventArgs e)
        {
            father =(FormDealImage) this.Owner;
        }

        private void buttonOK_Click(object sender, EventArgs e)
        {
            father.PolyN = comboBox1.Text;
            this.Close();

        }

        private void buttonCancel_Click(object sender, EventArgs e)
        {
            this.Close();
        }
    }
}
