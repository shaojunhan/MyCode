using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using System.Drawing.Imaging;

namespace DealWithImage
{
    enum MyState { BITMAP, GRAPHICS,NONE};
    public partial class FormDealImage : Form
    {
        private float range;//缩放比率
        //控件的宽高
        private int pictureBoxWidth;
        private int pictureBoxHeight;
        //多边形的变数
        private string polyN;
        public string PolyN
        {
            set
            {
                polyN = value;
            }
            get
            {
                return polyN;
            }
        }
        //制图法
        private Graphics mGraphics;
        private MyState myState = MyState.NONE;
        //缩放比率
        private float rate = 1.2f;
        //图片随鼠标移动的坐标
        private Point startPoint;
        private Point endPoint;
        //需要处理的图片
        Bitmap myBitmap;


        //构造
        public FormDealImage()
        {
            InitializeComponent();
            //背景色
            pictureBox1.BackColor = Color.Black;
            //图片居中显示
            pictureBox1.SizeMode = PictureBoxSizeMode.CenterImage;
            //获得控件宽高
            pictureBoxWidth = pictureBox1.Width;
            pictureBoxHeight = pictureBox1.Height;
            //初始化制图法
            mGraphics = pictureBox1.CreateGraphics();
            //清空当前
            Clear(mGraphics);
        }
        //打开图片
        private void 打开ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            OpenFileDialog mOpenFileDialog = new OpenFileDialog();//打开文件对话框
            //文件过滤器
            mOpenFileDialog.Filter = "所有图片(All)|*.jpg;*.bmp;*.gif;*.png;*.tiff" + 
                "|*.jpg|*.jpg" + 
                "|*.png|*.png" +　
                "|*.bmp|*.bmp" + 
                "|*.gif|*.gif";
            //检测返回结果
            DialogResult result = mOpenFileDialog.ShowDialog();
            if (result == DialogResult.OK)
            {
                Clear(mGraphics);//清空屏幕
                string imageOpenFilePath = mOpenFileDialog.FileName;//获得文件路径
                Bitmap image = new Bitmap(imageOpenFilePath);//加载图片

                //图片缩放以适应App的大小
                float range1 = (float)image.Width / pictureBoxWidth;
                float range2 = (float)image.Height / pictureBoxHeight;
                range = range1 > range2 ? range1 : range2;
                
                //图片应该显示的宽高
                int imageWidth = (int) (image.Width / range);
                int imageHeight = (int) (image.Height / range);

                //显示图片
                Bitmap myBitmap = new Bitmap(imageWidth, imageHeight);//图片缩放
                Graphics g = Graphics.FromImage(myBitmap);
                g.DrawImage(image, new Rectangle(0, 0, imageWidth, imageHeight), 
                    new Rectangle(0, 0, image.Width, image.Height), GraphicsUnit.Pixel);//绘制myBitmap

                this.myBitmap = myBitmap;//图片赋值
                DrawPicture();//显示图片
                
                //标志位
                myState = MyState.BITMAP;
                //按钮可用
                放大ToolStripMenuItem.Enabled = true;
                缩小ToolStripMenuItem.Enabled = true;
                反转ToolStripMenuItem.Enabled = true;
                旋转ToolStripMenuItem.Enabled = true;
                //保存可选
                保存ToolStripMenuItem.Enabled = true;
            }
        }

        //清空当前
        private void Clear(Graphics g)
        {
            g.Clear(Color.Black);
            //设置不可选择
            放大ToolStripMenuItem.Enabled = false;
            缩小ToolStripMenuItem.Enabled = false;
            反转ToolStripMenuItem.Enabled = false;
            旋转ToolStripMenuItem.Enabled = false;
            //保存不可选
            保存ToolStripMenuItem.Enabled = false;
            //标志位
            myState = MyState.NONE;
        }

        //保存图片
        private void 保存ToolTipMenuItem_Click(object sender, EventArgs e)
        {
            //获取图片保存格式
            ToolStripMenuItem item = sender as ToolStripMenuItem;
            string s = item.Text.ToLower();
            //保存对话框
            SaveFileDialog mSaveFileDialog = new SaveFileDialog();
            mSaveFileDialog.Filter = "*." + s + "|*." + s;

            DialogResult result = mSaveFileDialog.ShowDialog();
            if (result == DialogResult.OK)
            {
                string imageSaveFilePath = mSaveFileDialog.FileName;//获得保存路径
                Bitmap myBitmap = new Bitmap(this.myBitmap);

                switch (s)
                {
                    case "jpg":
                        myBitmap.Save(imageSaveFilePath, ImageFormat.Jpeg);       
                        break;

                    case "png":
                        myBitmap.Save(imageSaveFilePath, ImageFormat.Png);       
                        break;

                    case "bmp":
                        myBitmap.Save(imageSaveFilePath, ImageFormat.Bmp);       
                        break;

                    case "gif":
                        myBitmap.Save(imageSaveFilePath, ImageFormat.Gif);       
                        break;

                    case "tiff":
                        myBitmap.Save(imageSaveFilePath, ImageFormat.Tiff);       
                        break;
                }
            }
        }

        //绘制多边形
        private void 多边形处理ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            bool flag = false;
            if( (sender as ToolStripMenuItem) == n边形ToolStripMenuItem )
                flag = true;

            if(!flag)
            {
                //获得边数
                ToolStripMenuItem item = sender as ToolStripMenuItem;
                polyN = item.Text.Substring(0,1);//变数
            }else{
                //启动第二个窗体
                Form2 form2 = new Form2();
                form2.Owner = this;
                form2.ShowDialog(this);
            }

            //处理变数
            int N;
            int.TryParse(polyN, out N);
            if (N >= 3)
            {
                int width = pictureBoxWidth>pictureBoxHeight?pictureBoxHeight:pictureBoxWidth;
                Size size = new Size(width,width);
                //清空绘图
                Clear(mGraphics);
                this.myBitmap = DrawPolygon.Draw(size, N);
                DrawPicture();//显示图片
                polyN = "0";
            }
            //标志位
            myState = MyState.BITMAP;
            //按钮可用
            放大ToolStripMenuItem.Enabled = true;
            缩小ToolStripMenuItem.Enabled = true;
            反转ToolStripMenuItem.Enabled = true;
            旋转ToolStripMenuItem.Enabled = true;
            //保存可选
            保存ToolStripMenuItem.Enabled = true;
        }

        //清空屏幕
        private void 清空ClearToolStripMenuItem_Click(object sender, EventArgs e)
        {
            if (mGraphics != null)
                Clear(mGraphics);
        }

        //图像放大
        private void 放大ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            //图片源
            Bitmap b1 = new Bitmap(myBitmap);
            if (rate < 1)
                rate = 1;
            rate = (float)(rate * 1.1);
            //处理结果
            Bitmap b2 = new Bitmap( (int)(b1.Width * rate), (int)(b1.Height * rate) );
            //获取绘图法
            Graphics g = Graphics.FromImage(b2);
            g.InterpolationMode = System.Drawing.Drawing2D.InterpolationMode.HighQualityBicubic;//指定差值算法的质量
            g.DrawImage(b1, new Rectangle(0, 0, (int)(b1.Width * rate), 
                (int)(b1.Height * rate)), new Rectangle(0, 0, b1.Width, b1.Height), GraphicsUnit.Pixel);
            DrawPicture(b2);//显示图片
        }

        //旋转,每次旋转90度
        private void 旋转ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            Bitmap b = new Bitmap(myBitmap);
            b.RotateFlip(RotateFlipType.Rotate90FlipXY);//旋转90度
            myBitmap = b;//设置图像
            DrawPicture();//显示图片
        }

        //缩小
        private void 缩小ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            //图片源
            Bitmap b1 = new Bitmap(myBitmap);
            if (rate > 1)
                rate = 1;
            rate = (float)(rate / 1.1);
            //处理结果
            Bitmap b2 = new Bitmap((int)(b1.Width * rate), (int)(b1.Height * rate));
            //获取绘图法
            Graphics g = Graphics.FromImage(b2);
            g.InterpolationMode = System.Drawing.Drawing2D.InterpolationMode.HighQualityBicubic;//指定差值算法的质量
            g.DrawImage(b1, new Rectangle(0, 0, (int)(b1.Width *rate), (int)(b1.Height * rate)), new Rectangle(0, 0, b1.Width, b1.Height), GraphicsUnit.Pixel);
            DrawPicture(b2);//显示图片

        }
        //左右反转
        private void 左右ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            //图片源
            Bitmap b = new Bitmap(myBitmap);
            //宽高
            int width = b.Width;
            int height = b.Height;
            //中间交换变量
            Color pixel1,pixel2;
            for (int i = 0; i < height; i++)
            {
                for (int j = 0,z = width-1; j <width/2 && z>=width/2; j++,z--)
                {
                    //暂存
                    pixel1 = b.GetPixel(j,i);
                    pixel2 = b.GetPixel(z,i);
                    //互换
                    b.SetPixel( j, i, Color.FromArgb( pixel2.A, pixel2.R, pixel2.G, pixel2.B) );
                    b.SetPixel( z, i, Color.FromArgb( pixel1.A, pixel1.R, pixel1.G, pixel1.B) );
                }
            }

            myBitmap = b;
            DrawPicture();//显示图片

        }

        //上下反转功能模块
        private void 上下ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            //图片源
            Bitmap b = new Bitmap(myBitmap);
            //宽高
            int width = b.Width;
            int height = b.Height;
            //中间交换变量
            Color pixel1, pixel2;
            for (int i = 0; i < width; i++)
            {
                for (int j = 0, z = height - 1; j < height/2 && z >= height/2; j++, z--)
                {
                    //暂存
                    pixel1 = b.GetPixel(i,j);
                    pixel2 = b.GetPixel(i,z);
                    //互换
                    b.SetPixel( i, j, Color.FromArgb(pixel2.A, pixel2.R, pixel2.G, pixel2.B));
                    b.SetPixel( i, z, Color.FromArgb(pixel1.A, pixel1.R, pixel1.G, pixel1.B));
                }
            }

            myBitmap = b;
            DrawPicture();//显示图片

        }
        //关于信息
        private void 关于AboutToolStripMenuItem_Click(object sender, EventArgs e)
        {
            //清理屏幕
            Clear(mGraphics);
            //图像
            Bitmap b = new Bitmap(pictureBoxWidth, pictureBoxHeight);
            Graphics g = Graphics.FromImage(b);
            //绘制文字
            string s1 = "图片简单处理V1.0.0版本";
            string s2 = "作者:开膛手杰克";
            //版本信息
            g.DrawString(s1,new Font("宋体",24), new SolidBrush(Color.Blue),300,100);
            g.DrawString(s2, new Font("宋体", 24), new SolidBrush(Color.FromArgb(60, Color.Blue)), 305, 205);
            g.DrawString(s2, new Font("宋体", 24), new SolidBrush(Color.Red), 300, 200);

            myBitmap = b;
            DrawPicture();//显示图片
        }
        //鼠标按下
        private void pictureBox1_MouseDown(object sender, MouseEventArgs e)
        {
            //记录按下的点
            startPoint = new Point(e.X, e.Y);
            endPoint = new Point(e.X, e.Y);
        }
        //鼠标移动
        private void pictureBox1_MouseMove(object sender, MouseEventArgs e)
        {
            //记录移动的点
            if (endPoint == null)
                endPoint = new Point();
            endPoint.X = e.X;
            endPoint.Y = e.Y;

            //图片随鼠标移动

        }
 
   
        //绘制图形
        private void DrawPicture()
        {
            mGraphics.Clear(Color.Black);
            pictureBox1.Image = myBitmap;
        }
        //绘制图片
        private void DrawPicture(Bitmap bitmap)
        {
            mGraphics.Clear(Color.Black);
            pictureBox1.Image = bitmap;
       
        }

        private void FormDealImage_Load(object sender, EventArgs e)
        {

        }
    }

    //绘制多边形模块
    public class DrawPolygon
    {
        //绘制多边形1
        public static Bitmap Draw(Size size, int N)
        {
            return Paint(size, N);
        }

        //绘制多边形2，坐标偏移量为p
        public static Bitmap Draw(Size size, int N, Point p)//p为偏移量
        {
            return Paint(size, N);
        }

        //绘制多边形3,坐标偏移x,y
        public static Bitmap Draw(Size size, int N, int x, int y)
        {
            return Paint(size, N);
        }

        private static Bitmap Paint(Size size, int N)
        {
            //计算尺寸
            int r = size.Width>size.Height?size.Width/3:size.Height/3;
            if (N < 3)
                return null;
            //初始的相位
            int p = 90;
            //x,y坐标
            double x = 0.0;
            double y = 0.0;
            //画笔
            Pen pen = new Pen(Color.Green, 1.0f);
            //图片大小
            int width = size.Width;
            int height = size.Width;
            //图形
            Bitmap b = new Bitmap(width, height);
            Graphics g2 = Graphics.FromImage( b );
            g2.Clear(Color.Black);//清空一下

            g2.TranslateTransform(width/2, height/2);
            //需要绘制的点
            N = N > 10000 ? 10000 : N;//处理N
            //角度
            double angle = (float)360 * 1.0 / N;
            PointF[] points = new PointF[N];//申请空间

            for (int i = 0; i < N; i++)
            {
                x = r * Math.Cos((angle * i + p) * Math.PI / 180);
                y = r * Math.Sin((angle * i + p) * Math.PI / 180);
                points[i] = new PointF((float)x,(float)-y );
            }
            //绘制多边形
            g2.DrawPolygon(pen, points);
            //恢复坐标
            g2.ResetTransform();
            //返回
            return b;
        }
    }
}
