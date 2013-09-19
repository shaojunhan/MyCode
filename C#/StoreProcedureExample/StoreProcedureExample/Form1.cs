using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace StoreProcedureExample
{
    public partial class Form1 : Form
    {
        private MyDatabaseDataSet myDatabaseSet;
        private MyDatabaseDataSetTableAdapters.GradeProcedureTableAdapter gradeAdapter;
        private MyDatabaseDataSetTableAdapters.QueriesTableAdapter countAdapter;
        
        public Form1()
        {
            InitializeComponent();

            
            this.StartPosition = FormStartPosition.CenterScreen;//居中
            radioButtonGrade.Checked = true;//默认选择
            myDatabaseSet = new MyDatabaseDataSet();//DataSet实例
            gradeAdapter = new StoreProcedureExample.MyDatabaseDataSetTableAdapters.GradeProcedureTableAdapter();//存储过程GrageProcedure适配器
            countAdapter = new StoreProcedureExample.MyDatabaseDataSetTableAdapters.QueriesTableAdapter();//存储过程CountProcedure适配器

        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }

        //
        private void buttonQuery_Click(object sender, EventArgs e)
        {
            if (radioButtonGrade.Checked == true)//选中年纪查询
            {
                gradeAdapter.Fill(myDatabaseSet.GradeProcedure);//填充存储过程

                listBox1.Items.Clear();//清空列表
                listBox1.Items.Add("数据库中存在以下年纪:");
                foreach (var item in myDatabaseSet.GradeProcedure)//把存储过程的数据添加进列表
                {
                    listBox1.Items.Add(item.grade);
                }
            }
            else
            {
                listBox1.Items.Clear();
                int? femaleCount = 0;//int?是可控类型的泛型结构，表示可以为空的值类型
                int? maleCount = 0;

                countAdapter.CountProcedure( ref femaleCount, ref maleCount);//数据位引用
                listBox1.Items.Add("数据库中的男女人数分别为:");

                listBox1.Items.Add("女:" + femaleCount);
                listBox1.Items.Add("男:"+ maleCount);
            }

            MessageBox.Show("查询完成");
        }
    }
}
