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

namespace BindingNavigatorExample
{
    public partial class Form1 : Form
    {   
        //
        private BindingSource bindingSource1;
        private MyDatabaseDataSet dataSet;
        private SqlDataAdapter adapter;
        private DataTable selectTable;

        public Form1()
        {
            InitializeComponent();
            //居中
            this.StartPosition = FormStartPosition.CenterScreen;

        }

        private void Form1_Load(object sender, EventArgs e)
        {
            //初始化
            dataSet = new MyDatabaseDataSet();
            bindingSource1 = new BindingSource();
            bindingNavigator1.BindingSource = bindingSource1;//绑定源

            for (int i = 0; i < dataSet.Tables.Count; i++)
            {
                listBox1.Items.Add(dataSet.Tables[i].TableName);//列表中加入
            }

            //不允许增加、删除
            dataGridView1.AllowUserToAddRows = false;
            dataGridView1.AllowUserToDeleteRows = false;

        }

        //listBox1表中选项变化
        private void listBox1_SelectedIndexChanged(object sender, EventArgs e)
        {
            ListBox lBox = (ListBox)sender;//类型转化

            int index = lBox.SelectedIndex;//当前选择项

            adapter = new SqlDataAdapter("select * from " + lBox.SelectedItem.ToString(),//实例化适配器
                Properties.Settings.Default.MyDatabaseConnectionString);

            //生成update、insert、delete命令
            SqlCommandBuilder builder = new SqlCommandBuilder(adapter);
            adapter.UpdateCommand = builder.GetUpdateCommand();
            adapter.InsertCommand = builder.GetInsertCommand();
            adapter.DeleteCommand = builder.GetDeleteCommand();
            //清空指定表
            dataSet.Tables[index].Clear();
            adapter.Fill(dataSet.Tables[index]);//填充表

            bindingSource1.DataSource = dataSet.Tables[index];//数据源
            dataGridView1.DataSource = bindingSource1;//数据源
        }

        //按钮添加的响应
        private void button1_Click(object sender, EventArgs e)
        {
            try
            {
                bindingSource1.AddNew();//增加新的行
                MessageBox.Show("添加数据成功");
            }
            catch (Exception err)
            {
                MessageBox.Show("添加数据失败");
            }
        }

        //按钮删除的响应事件
        private void button2_Click(object sender, EventArgs e)
        {
            if (dataGridView1.SelectedRows.Count <= 0)
            {
                MessageBox.Show("请选择需要删除的行");
            }
            else
            {
                if (MessageBox.Show("确定删除?", "确认", MessageBoxButtons.OKCancel, MessageBoxIcon.Question)
                    == DialogResult.OK)
                {

                    for (int i = dataGridView1.SelectedRows.Count - 1; i >= 0; i++)//遍历要删除的行(从大到小删除，产出后序列会发生变化)
                    {
                        bindingSource1.RemoveAt(dataGridView1.SelectedRows[i].Index);//移除
                    }
                }
                else
                {
                    MessageBox.Show("删除已经取消");
                }
               
            }
        }

        //按钮保存更改的响应
        private void button3_Click(object sender, EventArgs e)
        {
            this.Validate();
            try
            {
                adapter.Update(dataSet.Tables[listBox1.SelectedIndex]);//更新指定表
                bindingSource1.EndEdit();//停止编辑
                MessageBox.Show("保存成功");
            }
            catch (Exception err)
            {
                MessageBox.Show(err.Message);
            }
        }

        //添加新航的按钮事件响应
        private void bindingNavigatorAddNewItem_Click(object sender, EventArgs e)
        {
            try
            {
                bindingSource1.AddNew();//添加新行
                MessageBox.Show("添加数据成功");
            }
            catch (Exception err)
            {
                MessageBox.Show("添加数据失败");
            }
        }
    }
}
