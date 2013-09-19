using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using System.Drawing.Drawing2D;

namespace PaintXY
{
    public partial class FromPaintXY : Form
    {
        //宽高
        private float halfWidth;
        private float halfHeight;

        public FromPaintXY()
        {
            InitializeComponent();

            this.FormBorderStyle = FormBorderStyle.FixedSingle;
            //获得面板的宽和高
            halfWidth = this.Width/2;
            halfHeight = this.Height/2;
        }

        private void FromPaintXY_Paint(object sender, PaintEventArgs e)
        {
            //绘制坐标轴类
            PointXY xy = new PointXY(halfWidth, halfHeight);

            Graphics g = xy.Paintxy(e.Graphics, GraphicsUnit.Pixel);
            xy.PaintUnit(g, GraphicsUnit.Pixel);
            //绘制sin曲线类
            PointSin sin = new PointSin();
            sin.Pointsin(g, GraphicsUnit.Pixel);

            ////绘制特效字
            //PointString p = new PointString(e.Graphics);
            //p.Mstring = "旋转的文字";
            //p.MPoint = new Point(50, 0);
            //p.PointRotateString(new Point(100, 100));

            //p.Mstring = "阴影的文字";
            //p.MPoint = new Point(300, 200);
            //p.PointShadowString();


            //p.Mstring = "彩色的文字";
            //p.MPoint = new Point(300, 100);
            //p.PointColorfulString();
        }
    }


    public class PointXY
    {
        //属性
        private float halfWidth;
        private float halfHeight;

        //绘制坐标系相对于原系统坐标的平移量
        public float HalfWidth
        {
            set { halfWidth = value; }
            get { return halfWidth; }
        }
        public float HalfHeight
        {
            set { halfHeight = value; }
            get { return halfHeight; }

        }

        public PointXY(float halfWidth, float halfHeight)
        {
            HalfWidth = halfWidth;
            HalfHeight = halfHeight;
        }

        public void PaintUnit(Graphics g, GraphicsUnit unit)
        {
            g.PageUnit = unit;
            //绘制坐标轴上的单位长度
            Pen p = new Pen(Color.Black, 0.5f);

            //绘制横坐标的单位
            for (int i = 0; i < halfWidth - 10; i += 10)
            {
                g.DrawLine(p, GetX(i), GetY(-1), GetX(i), GetY(1));
                g.DrawLine(p, GetX(-i), GetY(-1), GetX(-i), GetY(1));
            }
            //绘制总坐标的单位
            for (int i = 0; i < halfHeight - 10; i += 10)
            {
                g.DrawLine(p, GetX(-1), GetY(i), GetX(1), GetY(i));
                g.DrawLine(p, GetX(-1), GetY(-i), GetX(1), GetY(-i));
            }
        }

        //绘制坐标轴
        public Graphics Paintxy(Graphics g, GraphicsUnit unit)
        {
            //绘制单位
            g.PageUnit = unit;
            //箭头
            AdjustableArrowCap arrow = new AdjustableArrowCap(8, 8, false);
            Pen myPen = new Pen(Color.Green, 0.5f);
            myPen.CustomEndCap = arrow;

            //重新设置系统坐标原点为窗体正中
            g.TranslateTransform(halfWidth, halfHeight);
            //绘制横轴
            g.DrawLine(myPen, GetX(-halfWidth), GetY(0), GetX(halfWidth - 10), GetY(0));
            //绘制纵轴
            g.DrawLine(myPen, GetX(0), GetY(-halfHeight), GetX(0), GetY(halfHeight));

            return g;
        }

        //计算x坐标
        public float GetX(float x)
        {
            return x;
        }

        //计算y坐标
        public float GetY(float y)
        {
            return -y;
        }
    }

    public class PointSin
    {
        //绘制sin曲线的起始点
        private int start;
        private int end;
        //初始振幅和相位
        private float A;
        private int p;
        //绘制的周期
        private float T;

        public PointSin()
        {
            start = -360;
            end = 360;
            T = (float)(2 * Math.PI);
            A = GetY(100);
        }
       //带参数的构造
        public PointSin(int start, int end, float T, int p, float A)
        {
            this.start = start;
            this.end = end;
            this.T = T;
            this.A = A;
            this.p = p;
        }
        //带参数的构造2
        public PointSin(int start, int end)
        {
            this.start = start;
            this.end = end;
            T = (float)(2 * Math.PI);
            p = 0;
            A = GetY(100);
        }

        //绘制sin曲线
        public void Pointsin(Graphics g, GraphicsUnit unit)
        {
            //单位
            g.PageUnit = unit;
            //坐标点
            Point[] points = new Point[end - start];
            int length = points.Length;
            //计算坐标
            for (int i = start, j = 0; i < end && j < length; i++, j++)
            {
                float y = (float)(A * Math.Sin(i * Math.PI / 180.0 * 2 * Math.PI/T + this.p));
                points[j] = new Point(i, (int)y);
            }

            //绘制sin图形
            Pen p = new Pen(Color.Red, 1.0f);
            for (int i = 0; i < length-1; i++)
            {
                g.DrawLine(p, points[i].X, points[i].Y, points[i + 1].X, points[i + 1].Y);
            }
        }

        //获得X
        private float GetX(float x)
        {
            return x;
        }
        //获得Y
        private float GetY(float y)
        {
            return -y;
        }
    }

    //绘制特效文字
    public class PointString
    {
        private string mstring;
        private Point mPoint;
        private Graphics mGraphics;
        private Font mFont;
        private GraphicsUnit mGraphicsUnit;
        private SolidBrush mBrush;

        //mPoint属性
        public Point MPoint
        {
            set
            {
                mPoint = value;
            }
            get
            {
                return mPoint;
            }
        }
        //mGraphics属性
        public Graphics MGraphics
        {
            set
            {
                mGraphics = value;
            }
            get
            {
                return mGraphics;
            }
        }
        //mstring属性
        public string Mstring
        {
            set
            {
                mstring = value;
            }
            get
            {
                return mstring;
            }
        }
        //mGraphicsUnit属性
        public GraphicsUnit MGraphicsUnit
        {
            set
            {
                mGraphicsUnit = value;
            }
            get
            {
                return mGraphicsUnit;
            }
        }
        //mFont属性
        public Font MFont
        {
            set
            {
                mFont = value;
            }
            get
            {
                return mFont;
            }
        }
        //mBrush属性
        public SolidBrush MBrush
        {
            set
            {
                mBrush = value;
            }
            get
            {
                return mBrush;
            }
        }


        //无参的构造函数
        public PointString(Graphics g)
        {
            Mstring = "未设定文字";
            MPoint = new Point(0, 0);
            MFont = new Font("宋体",24);
            MGraphics = g;
            MGraphicsUnit = GraphicsUnit.Pixel;
            MBrush = new SolidBrush(Color.Red);
        }

        public PointString(string s, Graphics g, GraphicsUnit u,Font f, Point p ,SolidBrush b)
        {
            Mstring = s;
            MGraphicsUnit = u;
            MGraphics = g;
            MFont = f;
            MPoint = p;
            MBrush = b; 
        }

        //绘制旋转的文字
        public Graphics PointRotateString(Point translateTranform)
        {
            Point1(translateTranform);
            return mGraphics;
        }
        //重载 绘制旋转的文字
        public Graphics PointRotateString()
        {
            Point m = new Point(0, 0);
            Point1(m);
            return mGraphics;
        }

        //具体的绘制方法
        private void Point1(Point translateTranform)
        {
            //设置单位
            mGraphics.PageUnit = mGraphicsUnit;

            for (int i = 0; i < 360; i += 10)
            {
                mGraphics.TranslateTransform(translateTranform.X, translateTranform.Y);//系统坐标原点重新定位
                mGraphics.RotateTransform(i);//旋转
                mGraphics.DrawString(mstring, mFont, mBrush, mPoint);
                mGraphics.ResetTransform();
            }
        }

        //绘制带阴影的文字
        public Graphics PointShadowString()
        {
            //设置单位
            mGraphics.PageUnit = mGraphicsUnit;
            //绘制文字
            mGraphics.DrawString(mstring,mFont,mBrush, mPoint);
            mGraphics.DrawString(mstring,mFont,new SolidBrush(Color.FromArgb(60,Color.Blue)), 
                mPoint.X+5, mPoint.Y+5);

            return mGraphics;
        }

        //绘制彩色效果的文字
        public Graphics PointColorfulString(Color c1, Color c2)
        {
            HatchBrush mBrush = new HatchBrush(HatchStyle.Plaid, c1, c2);//画刷
            mGraphics.DrawString(mstring, mFont, mBrush, mPoint);//绘制彩色字体
            return mGraphics;
        }
        public Graphics PointColorfulString()
        {
            HatchBrush b = new HatchBrush(HatchStyle.Plaid, Color.Blue, Color.Red);
            mGraphics.DrawString(mstring, mFont, b, mPoint);
            return mGraphics;
        }
    }
}
