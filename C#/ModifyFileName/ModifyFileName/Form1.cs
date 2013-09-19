using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using System.IO;
using System.Runtime.InteropServices;

namespace ModifyFileName
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            FolderBrowserDialog folder = new FolderBrowserDialog();
            //修改文件名
            do
            {
                if (folder.ShowDialog() == DialogResult.OK)
                {
                    List<string> files =
                        Directory.GetFiles(folder.SelectedPath).Where(p => Path.GetExtension(p).ToLower().Equals(".rmvb")).ToList();
                    foreach (string sfi in files)
                    {
                        int i = sfi.IndexOf('[');
                        int j = sfi.IndexOf(']');
                        string temp;
                        if (i>1 && j>i)
                        {
                            temp = sfi.Substring(0, i)+sfi.Substring(j+1,sfi.Length-j-1);
                            File.Move(sfi, temp);
                        }
                        textBox1.Text += sfi+'\n';
                    }

                    if (MessageBox.Show("已完成", "OK", MessageBoxButtons.OK, MessageBoxIcon.Information) == DialogResult.OK)
                        break;
                }
            }while(MessageBox.Show("失败", "ERROR", MessageBoxButtons.RetryCancel, MessageBoxIcon.Error)==DialogResult.Retry);

        }

        //删除Zip文件
        private void button2_Click(object sender, EventArgs e)
        {
            string path = "C:\\Users\\Public\\Music";
            List<string> files = Directory.GetFiles(path).ToList();

            foreach(string sfi in files)
            {
                if (sfi.ToLower().EndsWith(".zip"))
                {
                    File.Delete(sfi);
                    textBox1.Text += sfi + "\r\n";
                }
            }
        }

        //删除Exe文件
        private void button3_Click(object sender, EventArgs e)
        {
            string path = "C:\\Users\\Public\\Music";
            List<string> files = Directory.GetFiles(path).ToList();

            foreach (string sfi in files)
            {
                if(sfi.ToLower().EndsWith(".exe"))
                {
                    File.Delete(sfi);
                    textBox1.Text += sfi + "\r\n";
                }
            }
        }

        //根据标题重命名
        private void button4_Click(object sender, EventArgs e)
        {
            string path = "C:\\Users\\Public\\Music";
            List<string> files = Directory.GetFiles(path).ToList();

            foreach (string sfi in files)
            {
                string cas="";
                int i=sfi.IndexOf('.');
                if(i>1)
                    cas=sfi.Substring(i,sfi.Length-i);
                //获取文件信息
                switch(cas)
                {
                    case ".mp3":
                        renameMp3(sfi);
                        break;
                    case ".wma":
                        renameWma(sfi);
                        break;
                }
             }
        }

        //根据标题对Mp3文件重命名
        private int renameMp3(string path)
        {
            bool isSet;
            byte[] b = new byte[128];
            FileStream fis = new FileStream(path, FileMode.Open);
            string tag,temp;

            isSet = false;
            fis.Seek(-128, SeekOrigin.End);//mp3文件的最后128个字符
            fis.Read(b, 0, 128);

            tag = System.Text.Encoding.Default.GetString(b, 0, 3);
            if (tag.ToLower().CompareTo("tag") == 0)
                isSet = true;
            if (isSet)
            {
                int i = path.LastIndexOf('\\');
                int j = path.LastIndexOf('.');
                if (i > 1 && j > 1)
                {
                    temp = path.Substring(0, i);
                    temp += System.Text.Encoding.Default.GetString(b, 3, 30);
                    temp += path.Substring(j, path.Length - j);
                    File.Move(path, temp);
                    return 1;
                }
                else
                    return 0;
            }
            else
                return -1;
        }

        //对wma文件进行重命名
        private int renameWma(string path)
        {
            string wmaFileName;
            string newPath;
            int i;

            Shell32.Shell shell = new Shell32.ShellClass();
            Shell32.Folder folder = shell.NameSpace(path.Substring(0, path.LastIndexOf("\\")));
            Shell32.FolderItem folderItem = folder.ParseName(path.Substring(path.LastIndexOf("\\")+1));

            wmaFileName = folder.GetDetailsOf(folderItem, 21);//文件标题
            newPath = path.Substring(0, path.LastIndexOf("\\")+1);
            newPath += wmaFileName+".wma";
            try
            {
                File.Move(path, newPath);
                return 1;
            }
            catch(IOException e2)
            {
                return -1;
            }
        }
    }
}
