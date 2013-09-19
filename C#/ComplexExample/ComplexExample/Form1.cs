using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using System.Data.SqlClient;

namespace ComplexExample
{
    public partial class Form1 : Form
    {


        public Form1()
        {
            InitializeComponent();
            //
            this.StartPosition = FormStartPosition.CenterScreen;
            pictureBoxPhoto.SizeMode = PictureBoxSizeMode.Zoom;
            myTable3DataGridView.SelectionMode = DataGridViewSelectionMode.FullRowSelect;
        }
        private void Form1_Load(object sender, EventArgs e)
        {
            // TODO: 这行代码将数据加载到表“myDatabaseDataSet.MyTable4”中。您可以根据需要移动或移除它。
            this.myTable4TableAdapter.Fill(this.myDatabaseDataSet.MyTable4);
            // TODO: 这行代码将数据加载到表“myDatabaseDataSet.MyTable3”中。您可以根据需要移动或移除它。
            this.myTable3TableAdapter.Fill(this.myDatabaseDataSet.MyTable3);


            BindingSource myTable2BindingSource = new BindingSource();//绑定数据源对象
            MyDatabaseDataSetTableAdapters.MyTable2TableAdapter myTable2Adapter = 
                new ComplexExample.MyDatabaseDataSetTableAdapters.MyTable2TableAdapter();//myTable2适配器

            myTable2Adapter.Fill(myDatabaseDataSet.MyTable2);//填充

            //数据源，显示对象为 学院名称 值对象为学院代号
            comboBox1.DataSource = myDatabaseDataSet.MyTable2;
            comboBox1.DisplayMember = "学院名称";
            comboBox1.ValueMember = "学院代号";

            comboBox1.DataBindings.Add("SelectedValue", myTable3BindingSource, "学院代号");//当前选择的值与myTable3的学院代号进行绑定
        }

        //保存
        private void myTable3BindingNavigatorSaveItem_Click(object sender, EventArgs e)
        {
            this.Validate();
            try
            {
                this.myTable3BindingSource.EndEdit();//停止编辑
                this.tableAdapterManager.UpdateAll(this.myDatabaseDataSet);//表适配器管理器tableAdapterManager更新整个数据集myDatabaseDataSet
                bindingNavigatorAddNewItem.Enabled = true;//按钮可用(目的是每次只能增加一行，在完善数据之前不能连续添加)
            }
            catch (Exception e2)
            {
                MessageBox.Show( e2.Message);
            }
        }

        //增加
        private void bindingNavigatorAddNewItem_Click(object sender, EventArgs e)
        {
            bindingNavigatorAddNewItem.Enabled = false;
            学号TextBox.Text = GetNextStudentID();//获得下一个学号(解决学号是主键不能为空的问题)
        }

        //删除
        private void bindingNavigatorDeleteItem_Click(object sender, EventArgs e)
        {
            if (myTable3DataGridView.SelectedRows.Count > 0)//选择的行数大于0
            {
                if (MessageBox.Show("确定删除？", "警告", MessageBoxButtons.YesNo, MessageBoxIcon.Question)
                    == DialogResult.Yes)//提示
                {
                    for (int i = myTable3DataGridView.SelectedRows.Count - 1; i >= 0; i--)//从最大开始删除，要不然会改变索引号
                    {
                        myTable3DataGridView.Rows.Remove(myTable3DataGridView.SelectedRows[i]);//移除行
                    }
                    MessageBox.Show("删除成功");
                }
            }
            else
            {
                MessageBox.Show("选择为空");
            }
        }

        //导入
        private void buttonImport_Click(object sender, EventArgs e)
        {
            OpenFileDialog photoFile = new OpenFileDialog();//OpenFileDialog对话框

            photoFile.Filter = "图形图像文件|*.jpg;*.png;*.bmp;*.tiff;*.gif";//过滤器

            if (photoFile.ShowDialog() == DialogResult.OK)//确定打开
            {
                Bitmap bitmap = new Bitmap(photoFile.OpenFile());//从流中获取数据
                ClearPhoto();
                pictureBoxPhoto.Image = bitmap;//设置图片
            }
        }

        //旋转
        private void buttonRotate_Click(object sender, EventArgs e)
        {
            if (pictureBoxPhoto.Image != null)
            {
                pictureBoxPhoto.Image.RotateFlip(RotateFlipType.Rotate90FlipXY);//x,y同时旋转90度
                pictureBoxPhoto.Refresh();//旋转后刷新才能看到效果
            }
        }

        //清空
        private void buttonClear_Click(object sender, EventArgs e)
        {
            ClearPhoto();
        }

        //清空的调用函数
        private void ClearPhoto()
        {
            if (pictureBoxPhoto.Image != null)
            {
                pictureBoxPhoto.Image.Dispose();//释放图片内存
                pictureBoxPhoto.Image = null;
            }
        }

        //选项改变时
        private void comboBox1_SelectedIndexChanged(object sender, EventArgs e)
        {
            if (comboBox1.SelectedValue != null)
            {
                label1.Text = "编码:" + comboBox1.SelectedValue;//label1提示信息为当前选择项的学院代号
            }
        }

        //求下一个ID
        private string GetNextStudentID()
        {
            long max = 0;//初始化

            for (int i = 0; i < myTable3DataGridView.Rows.Count - 2; i++)//比当前少一个,因为有一个新添加的空数据行
            {
                try
                {
                    string studentID = myTable3DataGridView.Rows[i].Cells[0].Value.ToString();//获得某行某列的值

                    string s = studentID.Substring(4, 6);//从第5个开始长度为6的子串

                    long temp = 0;
                    if (long.TryParse(s, out temp) == true)
                    {
                        if (max < temp)//最大值
                            max = temp;
                    }
                }
                catch (Exception e2)
                {
                    MessageBox.Show(e2.Message);
                }
            }
            //最值处理
            max += 1;
            if (max > 1000000)
                max = 999999;
            else if (max <= 0)
            {
                max = 100000;
            }

            return "0304" + max.ToString();
        }

        private void buttonImport_MouseDown(object sender, MouseEventArgs e)
        {
            MessageBox.Show("");
        }

    }
}
