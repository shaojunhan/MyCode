using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace Register
{
    public partial class Form1 : Form
    {
        //数据
        private string tBUserText;
        private string tBPassWordText;

        //构造
        public Form1()
        {
            InitializeComponent();
            //数据初始
            tBUserText = tBUser.Text;
            tBPassWordText = tBPassWord.Text;
            //错误提示为一直闪烁
            errorProvider1.BlinkStyle = ErrorBlinkStyle.AlwaysBlink;

            //取消最大最小话，取消还原
            this.MaximizeBox = false;
            this.MinimizeBox = false;
            //不能通过拖拽调整窗口大小，即固定边框
            this.FormBorderStyle = FormBorderStyle.FixedDialog;
        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }
           
        //OK按钮的点击事件
        private void oK_Click(object sender, EventArgs e)
        {
            tBUserInfo.Text = "用户名:"+ tBUserText + "  密码:" + tBPassWordText;
        }

        private bool ValidatingText(TextBox textBox, string text)
        {
            bool isValid = true;//返回值
            string s = text;//文本
            int length=s.Length;//长度
            if (length <= 0)
            {
                errorProvider1.SetError(textBox,"未输入信息");
                return (isValid = false);
            }

            for (int i = 0; i < length; i++)
            {
                //判断是数字或者是字母
                if (!char.IsLetterOrDigit(s[i]))
                {
                    isValid = false;
                    errorProvider1.SetError(textBox, "数字或字母");
                    return isValid;
                }
            }
            errorProvider1.SetError(textBox,"");
            //返回
            return (isValid = true);
        }

        private void tBUser_TextChanged(object sender, EventArgs e)
        {
            tBUserText = tBUser.Text;
        }

        private void tBPassWord_TextChanged(object sender, EventArgs e)
        {
            tBPassWordText = tBPassWord.Text;
        }

        private void tBUser_Validating(object sender, CancelEventArgs e)
        {
            ValidatingText(tBUser, tBUserText);
        }

        private void tBPassWord_Validating(object sender, CancelEventArgs e)
        {
            if (ValidatingText(tBPassWord,tBPassWordText) )
            {
                if (tBPassWordText.Length < 5)//密码长度小于5
                    errorProvider1.SetError(tBPassWord, "密码不得少于五位");
                else
                    errorProvider1.SetError(tBPassWord,"");
            }
        }
    }
}
