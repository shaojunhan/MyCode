using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Drawing;
using System.Data;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using System.Drawing.Drawing2D;

namespace UserControlExample
{
    public enum FlashButtonStyle { 椭圆, 矩形, 圆角矩形, 阴影 };
    public partial class FlashButton : UserControl
    {
        /// <summary>获得或者设置按钮形状</summary>
        [DefaultValue(FlashButtonStyle.矩形)]
        [Description("按钮形状"), Category("外观")]
        [Browsable(true)]
        public FlashButtonStyle ButtonStyle { 
            get{ return buttonStyle; }
            set { buttonStyle = value; this.Refresh(); }
        }
        private FlashButtonStyle buttonStyle = FlashButtonStyle.矩形;

        /// <summary>获取设置中心扩散颜色</summary>
        [Description("中心扩散颜色"), Category("外观")]
        public Color CenterColor
        {
            get { return centerColor; }
            set { centerColor = value; this.Refresh(); }
        }
        private Color centerColor = Color.FromArgb(255, 0, 0, 255);

        /// <summary>获取或设置周边颜色</summary>
        [Description("周边颜色"),Category("外观")]
        public Color SurroundColor
        {
            get { return surroundColor; }
            set { surroundColor = value; this.Refresh(); }
        }
        private Color surroundColor = Color.FromArgb(255, 0, 200, 255);

        /// <summary>文本颜色</summary>
        [Description("文本颜色"), Category("外观")]
        public Color TextColor
        {
            get { return textColor; }
            set { textColor = value; this.Refresh(); }
        }
        private Color textColor = Color.Black;

        /// <summary>文本</summary>
        [Description("在按钮上显示的字"), Category("文本")]
        public string ButtonText
        {
            get { return text; }
            set { text = value; this.Refresh(); }
        }
        private string text = "FlashButton1";

        /// <summary>圆角宽度</summary>
        [Description("圆角宽度(仅适用于圆角按钮)"), Category("外观")]
        public int ArcWidth
        {
            get { return arcWidth; }
            set { arcWidth = value; this.Refresh(); }
        }
        private int arcWidth = 20;

        /// <summary>阴影类型</summary>
        [Description("阴影类型(仅适用于阴影按钮)"), Category("外观")]
        public HatchStyle ButtonHatchStyle
        {
            get { return buttonHatchStyle; }
            set { buttonHatchStyle = value; this.Refresh(); }
        }
        private HatchStyle buttonHatchStyle = HatchStyle.DiagonalBrick;
        public FlashButton()
        {
            InitializeComponent();
        }

        private void FlashButton_Load(object sender, EventArgs e)
        {

        }

        //Paint事件
        public void FlashButton_Paint(object sender, PaintEventArgs e)
        {
            this.Region = new Region(this.ClientRectangle);

            if (this.buttonStyle == FlashButtonStyle.矩形)
            {
                GraphicsPath path = new GraphicsPath();
                path.AddRectangle(this.ClientRectangle);

                PathGradientBrush brush = CreatePathGradientBrush(path);
                e.Graphics.FillRectangle(brush, this.ClientRectangle);
            }
            else if (this.buttonStyle == FlashButtonStyle.椭圆)
            {
                GraphicsPath path = new GraphicsPath();
                path.AddEllipse(this.ClientRectangle);

                PathGradientBrush brush = CreatePathGradientBrush(path);
                e.Graphics.FillEllipse(brush, this.ClientRectangle);
            }
            else if (this.buttonStyle == FlashButtonStyle.圆角矩形)
            {
                Rectangle rect = this.ClientRectangle;
                GraphicsPath path = new GraphicsPath();
                
                path.StartFigure();
                path.AddArc(rect.X, rect.Y, arcWidth * 2, rect.Height, 90, 180);
                path.AddRectangle( new Rectangle(rect.X + arcWidth, rect.Y, rect.Width - arcWidth*2, rect.Height) );
                path.AddArc(rect.X + rect.Width - arcWidth*2, rect.Y, arcWidth*2, rect.Height, -90, 180);
                path.CloseFigure();

                Region region = new Region(path);
                PathGradientBrush brush = CreatePathGradientBrush(path);
                e.Graphics.FillRegion(brush, region);

                this.Region = region;

            }
            else if (this.buttonStyle == FlashButtonStyle.阴影)
            {
                HatchBrush brush = new HatchBrush(buttonHatchStyle, this.ForeColor, this.BackColor);
                Rectangle rect = this.ClientRectangle;

                Graphics g = e.Graphics;
                g.FillRectangle(brush, rect);
                Pen pen = new Pen(Color.Gray,2);
                g.DrawRectangle(pen, rect);
            }
            DrawText(e);
        }

        //
        private PathGradientBrush CreatePathGradientBrush(GraphicsPath path)
        {
            PathGradientBrush pGBrush = new PathGradientBrush(path);

            pGBrush.CenterColor = centerColor;
            Color[] colors = { surroundColor};

            pGBrush.SurroundColors = colors;

            return pGBrush;
        }

        //
        private void DrawText(PaintEventArgs e)
        {
            SizeF textSize = e.Graphics.MeasureString(text, this.Font);

            float x = (this.Width - textSize.Width) / 2;
            float y = (this.Height - textSize.Height) /2;

            e.Graphics.DrawString(text, this.Font, new SolidBrush(textColor), x, y);
        }

        //
        private void FlashButton_MouseEnter(object sender, EventArgs e)
        {
            ChangeColor();
            this.Refresh();
        }

        //
        private void FlashButton_MouseLeave(object sender, EventArgs e)
        {
            ChangeColor();
            this.Refresh();
        }

        //
        private void ChangeColor()
        {
            //Color tempColor = this.ForeColor;
            //this.ForeColor = this.BackColor;
            //this.BackColor = tempColor;

            Color tempColor = new Color();
            tempColor = this.centerColor;
            this.centerColor = this.surroundColor;
            this.surroundColor = tempColor;
        }
    }
}
