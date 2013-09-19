using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace DataGridViewExample
{
    public partial class Form1 : Form
    {
        //
        private SqlClass sqlClass1;
        private SqlClass sqlClass2;
        private BindingSource bindingSource1;
        
        public Form1()
        {
            InitializeComponent();
            //数据SqlClass对象
            sqlClass1 = new SqlClass("select * from MyTable2", ConnectionStyle.Express);//SQL Express烈性的数据库
            sqlClass2 = new SqlClass("select * from MyTable3", ConnectionStyle.Express);
            bindingSource1 = null;
            //按钮不可用
            toolStripButton2.Enabled = false;
            toolStripButton3.Enabled = false;

            bindingNavigator1.BindingSource = bindingSource1;//绑定源
        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }

        //绑定/解除绑定按钮的响应事件
        private void toolStripButton1_Click(object sender, EventArgs e)
        {
            if (bindingSource1 != null)
            {
                bindingSource1 = null;//绑定源
                dataGridView1.DataSource = null;
                for (int i = 0; i < dataGridView1.Columns.Count; i++)
                    dataGridView1.Columns.RemoveAt(i);

                bindingNavigator1.BindingSource = bindingSource1;
               // toolStripButton2.Enabled = false;
                toolStripButton3.Enabled = false;

            }
            else
            {
                sqlClass1.Adapter.Fill(sqlClass1.Table);
                sqlClass2.Adapter.Fill(sqlClass2.Table);

                bindingSource1 = new BindingSource();

                bindingSource1.DataSource = sqlClass2.Table;
                dataGridView1.DataSource = bindingSource1;
                bindingNavigator1.BindingSource = bindingSource1;
               //toolStripButton2.Enabled = true;
                toolStripButton3.Enabled = true;
            }
        }

        //按钮的响应事件
        private void toolStripButton2_Click(object sender, EventArgs e)
        {
            if (bindingSource1.DataSource == sqlClass1.Table)
            {
                bindingSource1.DataSource = sqlClass2.Table;

            }
            else
            {
                bindingSource1.DataSource = sqlClass1.Table;
            }
        }

        //按钮的响应事件
        private void toolStripButton3_Click(object sender, EventArgs e)
        {
            try
            {
                this.Validate();
                bindingSource1.EndEdit();

                if (bindingSource1.DataSource == sqlClass1.Table)
                {
                    sqlClass1.Adapter.Update(sqlClass1.Table);
                }
                else if (bindingSource1.DataSource == sqlClass2.Table)
                {
                    sqlClass2.Adapter.Update(sqlClass2.Table);
                }

                MessageBox.Show("保存成功");
            }
            catch (Exception e2)
            {
                string s = e2.ToString();
                int startIndex = s.IndexOf(':');
                int endIndex = s.IndexOf('。');
                MessageBox.Show("数据库连接错误:" + s.Substring(startIndex + 1, endIndex - startIndex - 1));
            }
        }

        //按钮的响应事件
        private void button1_Click(object sender, EventArgs e)
        {
            DataGridViewColumn column = dataGridView1.Columns["学号"];

            if (column.HeaderText == column.DataPropertyName)
            {
                column.HeaderText = "Student ID";
            }
            else
            {
                column.HeaderText = column.DataPropertyName;
            }
        }

        //按钮的响应事件
        private void button3_Click(object sender, EventArgs e)
        {
            if (dataGridView1.AlternatingRowsDefaultCellStyle.BackColor != Color.MistyRose)
            {
              
                dataGridView1.RowsDefaultCellStyle.BackColor = dataGridView1.DefaultCellStyle.BackColor;

                dataGridView1.AlternatingRowsDefaultCellStyle.BackColor = Color.MistyRose;
            }
            else
            {
                dataGridView1.AlternatingRowsDefaultCellStyle.BackColor = dataGridView1.DefaultCellStyle.BackColor;
            }
        }

        //按钮的响应事件
        private void button5_Click(object sender, EventArgs e)
        {

            string selectInfo = "";

            for (int i = 0; i < dataGridView1.SelectedRows.Count; i++)
            {
                selectInfo += string.Format("第{0}行:学号{1}\r\n",
                    dataGridView1.SelectedRows[i].Index, 
                    dataGridView1.SelectedRows[i].Cells["学号"].Value);
            }

            if (selectInfo == "")
                selectInfo = "选择为空";
            MessageBox.Show(selectInfo, "选择的行信息");
        }

        //按钮的响应事件
        private void button7_Click(object sender, EventArgs e)
        {
            foreach(DataGridViewRow row in dataGridView1.Rows)
            {
                object rowValue = row.Cells["性别"].Value;
                if(rowValue != null)
                {
                    if (rowValue.ToString() == "男")
                    {
                        row.DefaultCellStyle.BackColor = Color.MistyRose;
                    }
                }
            }
        }

        //按钮的响应事件
        private void button2_Click(object sender, EventArgs e)
        {
            dataGridView1.Columns["照片"].Visible = !dataGridView1.Columns["照片"].Visible;
        }

        //按钮的响应事件
        private void button4_Click(object sender, EventArgs e)
        {
            int index = dataGridView1.Columns["学号"].DisplayIndex;

            dataGridView1.Columns["学号"].DisplayIndex = dataGridView1.Columns["姓名"].DisplayIndex;
            dataGridView1.Columns["姓名"].DisplayIndex = index;
        }

        //按钮的响应事件
        private void button6_Click(object sender, EventArgs e)
        {
            if (dataGridView1.Columns["学号"].Frozen == false)
            {
                dataGridView1.Columns["学号"].Frozen = true;
                dataGridView1.Dock = DockStyle.Top;
                bindingNavigator1.Dock = DockStyle.Bottom;
            }
            else
            {
                dataGridView1.Columns["学号"].Frozen = false;
                dataGridView1.Dock = DockStyle.Bottom;
                bindingNavigator1.Dock = DockStyle.Top;
            }
        }

        //按钮的响应事件
        private void button8_Click(object sender, EventArgs e)
        {
            dataGridView1.AutoResizeColumns(DataGridViewAutoSizeColumnsMode.AllCells);
        }

        //按钮的响应事件
        private void button9_Click(object sender, EventArgs e)
        {
            string selectString = "";

            for (int i = dataGridView1.SelectedCells.Count - 1; i >= 0; i--)
            {
                selectString += string.Format("第{0}行第{1}列:{2}",
                    dataGridView1.SelectedCells[i].RowIndex+1,
                    dataGridView1.SelectedCells[i].ColumnIndex+1,
                    dataGridView1.SelectedCells[i].Value);
            }

            if (selectString == "")
                selectString = "选择为空";

            MessageBox.Show(selectString, "选择的单元格信息");
        }

        //随即更改单元格按钮的响应事件
        private void button10_Click(object sender, EventArgs e)
        {
            Random r = new Random();//产生随机数的变量

            int row = r.Next(dataGridView1.CurrentCell.RowIndex);
            int column = r.Next(dataGridView1.CurrentCell.ColumnIndex);

            dataGridView1.CurrentCell = dataGridView1.Rows[row].Cells[column];//设置当前单元格
        }

        //设置生日日期格式按钮的响应事件
        private void button11_Click(object sender, EventArgs e)
        {
            DataGridViewColumn column = dataGridView1.Columns["出生日期"];//出生日期列

            column.DefaultCellStyle.Format = "yy.MM";//显示格式
            column.DefaultCellStyle.BackColor = Color.YellowGreen;//背景色
            column.DefaultCellStyle.ForeColor = Color.Black;//前景色
            column.DefaultCellStyle.Font = new Font(dataGridView1.Font, FontStyle.Italic);//字体
            column.DefaultCellStyle.Alignment = DataGridViewContentAlignment.MiddleCenter;//居中显示
        }

        //更改学院编码的录入方式按钮的响应事件
        private void button12_Click(object sender, EventArgs e)
        {
            DataGridViewComboBoxColumn comboBoxColumn = new DataGridViewComboBoxColumn();

            if (bindingSource1 != null)
            {
                try
                {
                    //增加列、删除列
                    dataGridView1.Columns.Add(comboBoxColumn);
                    comboBoxColumn.DisplayIndex = dataGridView1.Columns["学院代号"].DisplayIndex;
                    dataGridView1.Columns.Remove(dataGridView1.Columns["学院代号"]);
                    //增加的列的属性设置
                    comboBoxColumn.DataPropertyName = "学院名称";//列的属性名称
                    comboBoxColumn.DataSource = sqlClass1.Table;//数据源
                    comboBoxColumn.DisplayMember = "学院名称";//显示数据
                    comboBoxColumn.ValueMember = "学院代号";//值数据
                    comboBoxColumn.Name = "学院名称";//列名
                    comboBoxColumn.HeaderText = "学院名称";//标题名
                }
                catch (Exception e2)
                {
                    dataGridView1.Columns.Remove(comboBoxColumn);//把多余的列删除掉
                }
            }
            else
            {
                MessageBox.Show("空的数据");
            }
        }

        //CellFormatting按钮的响应
        private void button13_Click(object sender, EventArgs e)
        {
            dataGridView1.CellFormatting += new DataGridViewCellFormattingEventHandler(CellFormatting);//注册事件，该事件是每个单元格绘制的时候触发
            dataGridView1.Refresh();
        }

        //DataGridView的CellFormatting注册事件
        private void CellFormatting(object sender, DataGridViewCellFormattingEventArgs e)
        {
            if (dataGridView1.Columns[e.ColumnIndex].DataPropertyName == "GPA")
            {
                float gpa;

                if (e.Value != null)
                {

                    if (float.TryParse(e.Value.ToString(), out gpa) == true)
                    {
                        if (gpa < 3.0f)
                        {
                            e.CellStyle.ForeColor = Color.Red;
                            e.CellStyle.BackColor = Color.MistyRose;
                        }
                    }
                }
            }
        }

        //DataError按钮的响应
        private void button14_Click(object sender, EventArgs e)
        {
            dataGridView1.DataError += new DataGridViewDataErrorEventHandler(DataError);//注册事件
            MessageBox.Show("现在可以输入超过10位的学号检验错误监听");
        }

        //DataGridView的DataError的注册事件
        private void DataError(object sender, DataGridViewDataErrorEventArgs e)
        {
            MessageBox.Show(e.Exception.Message,"出错了");//出错提示
        }

        //CellValidating按钮事件
        private void button15_Click(object sender, EventArgs e)
        {
            dataGridView1.CellValidating += new DataGridViewCellValidatingEventHandler(CellValidating);//注册事件
            MessageBox.Show("现在可以输入不足10位或者10位非全数字的学号检验时间监听");
        }

        //DataGridView的CellValidating注册事件
        private void CellValidating(object sender, DataGridViewCellValidatingEventArgs e)
        {
            if (dataGridView1.Columns[e.ColumnIndex].DataPropertyName == "学号")//为"学号"的列名
            {
                string dataError = "";//错误信息

                if (e.FormattedValue == null)
                {
                    dataError = "学号不能为空";
                }
                else
                {
                    string s = e.FormattedValue.ToString();
                    if (s.Length < 10)//学号为10位
                    {
                        dataError = "学号不能小于10位";
                    }
                    else
                    {
                        for (int i = 0; i < s.Length; i++)//学号全部为数字
                        {
                            if (char.IsDigit(s[i]) == false)
                            {
                                dataError = "学号必须全部是数字";
                                break;
                            }
                        }
                    }
                }

                if (dataError.Length > 0)
                {
                    MessageBox.Show(string.Format("第{0}行,第{1}列", e.RowIndex + 1, e.ColumnIndex + 1));//提示出错的行号和列号

                    dataGridView1.Rows[e.RowIndex].Cells[e.ColumnIndex].ErrorText = dataError;//该行该列的错误信息
                }
                else
                {
                    dataGridView1.Rows[e.RowIndex].Cells[e.ColumnIndex].ErrorText = null;//空的错误信息
                }
            }
        }
    }
}
