using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace WindowsFormsApplication1
{
    public partial class Form1 : Form
    {
        private string label = "Hello World!";
        private string[] text;
        private int j = 0;

        public Form1()
        {
            InitializeComponent();
        }
        //TODO:HelloWorld
        private void Form1_Load(object sender, EventArgs e);
        private void timer1_Tick(object sender, EventArgs e)
        {
            if (j >= text.Length)
                timer1.Stop();
            if (j < text.Length)
                showHello.Text = text[j];
            j++;
        }
    }
}
