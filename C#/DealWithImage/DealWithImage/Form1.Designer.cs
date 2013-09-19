namespace DealWithImage
{
    partial class FormDealImage
    {
        /// <summary>
        /// 必需的设计器变量。
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// 清理所有正在使用的资源。
        /// </summary>
        /// <param name="disposing">如果应释放托管资源，为 true；否则为 false。</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows 窗体设计器生成的代码

        /// <summary>
        /// 设计器支持所需的方法 - 不要
        /// 使用代码编辑器修改此方法的内容。
        /// </summary>
        private void InitializeComponent()
        {
            this.panel1 = new System.Windows.Forms.Panel();
            this.pictureBox1 = new System.Windows.Forms.PictureBox();
            this.menuStrip1 = new System.Windows.Forms.MenuStrip();
            this.fileFToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.打开ToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.保存ToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.jPGToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.bMPToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.pNGToolStripMenuItem1 = new System.Windows.Forms.ToolStripMenuItem();
            this.gIFToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.tIFFToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.editEToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.任意多边形ToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.边形ToolStripMenuItem1 = new System.Windows.Forms.ToolStripMenuItem();
            this.边形ToolStripMenuItem2 = new System.Windows.Forms.ToolStripMenuItem();
            this.边形ToolStripMenuItem3 = new System.Windows.Forms.ToolStripMenuItem();
            this.边形ToolStripMenuItem4 = new System.Windows.Forms.ToolStripMenuItem();
            this.n边形ToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.toolStripSeparator1 = new System.Windows.Forms.ToolStripSeparator();
            this.放大ToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.缩小ToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.旋转ToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.反转ToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.左右ToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.上下ToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.toolStripSeparator2 = new System.Windows.Forms.ToolStripSeparator();
            this.清空ClearToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.helpHToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.关于AboutToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.panel1.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox1)).BeginInit();
            this.menuStrip1.SuspendLayout();
            this.SuspendLayout();
            // 
            // panel1
            // 
            this.panel1.Controls.Add(this.pictureBox1);
            this.panel1.Location = new System.Drawing.Point(-1, 26);
            this.panel1.Name = "panel1";
            this.panel1.Size = new System.Drawing.Size(1002, 472);
            this.panel1.TabIndex = 0;
            // 
            // pictureBox1
            // 
            this.pictureBox1.Dock = System.Windows.Forms.DockStyle.Fill;
            this.pictureBox1.Location = new System.Drawing.Point(0, 0);
            this.pictureBox1.Name = "pictureBox1";
            this.pictureBox1.Padding = new System.Windows.Forms.Padding(5);
            this.pictureBox1.Size = new System.Drawing.Size(1002, 472);
            this.pictureBox1.TabIndex = 0;
            this.pictureBox1.TabStop = false;
            this.pictureBox1.MouseMove += new System.Windows.Forms.MouseEventHandler(this.pictureBox1_MouseMove);
            this.pictureBox1.MouseDown += new System.Windows.Forms.MouseEventHandler(this.pictureBox1_MouseDown);
            // 
            // menuStrip1
            // 
            this.menuStrip1.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.fileFToolStripMenuItem,
            this.editEToolStripMenuItem,
            this.helpHToolStripMenuItem});
            this.menuStrip1.Location = new System.Drawing.Point(0, 0);
            this.menuStrip1.Name = "menuStrip1";
            this.menuStrip1.Size = new System.Drawing.Size(1001, 25);
            this.menuStrip1.TabIndex = 1;
            this.menuStrip1.Text = "menuStrip1";
            // 
            // fileFToolStripMenuItem
            // 
            this.fileFToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.打开ToolStripMenuItem,
            this.保存ToolStripMenuItem});
            this.fileFToolStripMenuItem.Name = "fileFToolStripMenuItem";
            this.fileFToolStripMenuItem.ShortcutKeys = ((System.Windows.Forms.Keys)((System.Windows.Forms.Keys.Alt | System.Windows.Forms.Keys.F)));
            this.fileFToolStripMenuItem.Size = new System.Drawing.Size(58, 21);
            this.fileFToolStripMenuItem.Text = "文件(&F)";
            // 
            // 打开ToolStripMenuItem
            // 
            this.打开ToolStripMenuItem.Name = "打开ToolStripMenuItem";
            this.打开ToolStripMenuItem.Size = new System.Drawing.Size(140, 22);
            this.打开ToolStripMenuItem.Text = "打开(Open)";
            this.打开ToolStripMenuItem.Click += new System.EventHandler(this.打开ToolStripMenuItem_Click);
            // 
            // 保存ToolStripMenuItem
            // 
            this.保存ToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.jPGToolStripMenuItem,
            this.bMPToolStripMenuItem,
            this.pNGToolStripMenuItem1,
            this.gIFToolStripMenuItem,
            this.tIFFToolStripMenuItem});
            this.保存ToolStripMenuItem.Name = "保存ToolStripMenuItem";
            this.保存ToolStripMenuItem.Size = new System.Drawing.Size(140, 22);
            this.保存ToolStripMenuItem.Text = "保存(Save)";
            // 
            // jPGToolStripMenuItem
            // 
            this.jPGToolStripMenuItem.Name = "jPGToolStripMenuItem";
            this.jPGToolStripMenuItem.Size = new System.Drawing.Size(103, 22);
            this.jPGToolStripMenuItem.Text = "JPG";
            this.jPGToolStripMenuItem.Click += new System.EventHandler(this.保存ToolTipMenuItem_Click);
            // 
            // bMPToolStripMenuItem
            // 
            this.bMPToolStripMenuItem.Name = "bMPToolStripMenuItem";
            this.bMPToolStripMenuItem.Size = new System.Drawing.Size(103, 22);
            this.bMPToolStripMenuItem.Text = "BMP";
            this.bMPToolStripMenuItem.Click += new System.EventHandler(this.保存ToolTipMenuItem_Click);
            // 
            // pNGToolStripMenuItem1
            // 
            this.pNGToolStripMenuItem1.Name = "pNGToolStripMenuItem1";
            this.pNGToolStripMenuItem1.Size = new System.Drawing.Size(103, 22);
            this.pNGToolStripMenuItem1.Text = "PNG";
            this.pNGToolStripMenuItem1.Click += new System.EventHandler(this.保存ToolTipMenuItem_Click);
            // 
            // gIFToolStripMenuItem
            // 
            this.gIFToolStripMenuItem.Name = "gIFToolStripMenuItem";
            this.gIFToolStripMenuItem.Size = new System.Drawing.Size(103, 22);
            this.gIFToolStripMenuItem.Text = "GIF";
            this.gIFToolStripMenuItem.Click += new System.EventHandler(this.保存ToolTipMenuItem_Click);
            // 
            // tIFFToolStripMenuItem
            // 
            this.tIFFToolStripMenuItem.Name = "tIFFToolStripMenuItem";
            this.tIFFToolStripMenuItem.Size = new System.Drawing.Size(103, 22);
            this.tIFFToolStripMenuItem.Text = "TIFF";
            this.tIFFToolStripMenuItem.Click += new System.EventHandler(this.保存ToolTipMenuItem_Click);
            // 
            // editEToolStripMenuItem
            // 
            this.editEToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.任意多边形ToolStripMenuItem,
            this.toolStripSeparator1,
            this.放大ToolStripMenuItem,
            this.缩小ToolStripMenuItem,
            this.旋转ToolStripMenuItem,
            this.反转ToolStripMenuItem,
            this.toolStripSeparator2,
            this.清空ClearToolStripMenuItem});
            this.editEToolStripMenuItem.Name = "editEToolStripMenuItem";
            this.editEToolStripMenuItem.ShortcutKeys = ((System.Windows.Forms.Keys)((System.Windows.Forms.Keys.Alt | System.Windows.Forms.Keys.E)));
            this.editEToolStripMenuItem.Size = new System.Drawing.Size(59, 21);
            this.editEToolStripMenuItem.Text = "编辑(&E)";
            // 
            // 任意多边形ToolStripMenuItem
            // 
            this.任意多边形ToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.边形ToolStripMenuItem1,
            this.边形ToolStripMenuItem2,
            this.边形ToolStripMenuItem3,
            this.边形ToolStripMenuItem4,
            this.n边形ToolStripMenuItem});
            this.任意多边形ToolStripMenuItem.Name = "任意多边形ToolStripMenuItem";
            this.任意多边形ToolStripMenuItem.Size = new System.Drawing.Size(203, 22);
            this.任意多边形ToolStripMenuItem.Text = "任意正多边形(Polygon)";
            // 
            // 边形ToolStripMenuItem1
            // 
            this.边形ToolStripMenuItem1.Name = "边形ToolStripMenuItem1";
            this.边形ToolStripMenuItem1.Size = new System.Drawing.Size(110, 22);
            this.边形ToolStripMenuItem1.Text = "3边形";
            this.边形ToolStripMenuItem1.Click += new System.EventHandler(this.多边形处理ToolStripMenuItem_Click);
            // 
            // 边形ToolStripMenuItem2
            // 
            this.边形ToolStripMenuItem2.Name = "边形ToolStripMenuItem2";
            this.边形ToolStripMenuItem2.Size = new System.Drawing.Size(110, 22);
            this.边形ToolStripMenuItem2.Text = "4边形";
            this.边形ToolStripMenuItem2.Click += new System.EventHandler(this.多边形处理ToolStripMenuItem_Click);
            // 
            // 边形ToolStripMenuItem3
            // 
            this.边形ToolStripMenuItem3.Name = "边形ToolStripMenuItem3";
            this.边形ToolStripMenuItem3.Size = new System.Drawing.Size(110, 22);
            this.边形ToolStripMenuItem3.Text = "5边形";
            this.边形ToolStripMenuItem3.Click += new System.EventHandler(this.多边形处理ToolStripMenuItem_Click);
            // 
            // 边形ToolStripMenuItem4
            // 
            this.边形ToolStripMenuItem4.Name = "边形ToolStripMenuItem4";
            this.边形ToolStripMenuItem4.Size = new System.Drawing.Size(110, 22);
            this.边形ToolStripMenuItem4.Text = "6边形";
            this.边形ToolStripMenuItem4.Click += new System.EventHandler(this.多边形处理ToolStripMenuItem_Click);
            // 
            // n边形ToolStripMenuItem
            // 
            this.n边形ToolStripMenuItem.Name = "n边形ToolStripMenuItem";
            this.n边形ToolStripMenuItem.Size = new System.Drawing.Size(110, 22);
            this.n边形ToolStripMenuItem.Text = "N边形";
            this.n边形ToolStripMenuItem.Click += new System.EventHandler(this.多边形处理ToolStripMenuItem_Click);
            // 
            // toolStripSeparator1
            // 
            this.toolStripSeparator1.Name = "toolStripSeparator1";
            this.toolStripSeparator1.Size = new System.Drawing.Size(200, 6);
            // 
            // 放大ToolStripMenuItem
            // 
            this.放大ToolStripMenuItem.Name = "放大ToolStripMenuItem";
            this.放大ToolStripMenuItem.Size = new System.Drawing.Size(203, 22);
            this.放大ToolStripMenuItem.Text = "放大(Expand)";
            this.放大ToolStripMenuItem.Click += new System.EventHandler(this.放大ToolStripMenuItem_Click);
            // 
            // 缩小ToolStripMenuItem
            // 
            this.缩小ToolStripMenuItem.Name = "缩小ToolStripMenuItem";
            this.缩小ToolStripMenuItem.Size = new System.Drawing.Size(203, 22);
            this.缩小ToolStripMenuItem.Text = "缩小(Shrink)";
            this.缩小ToolStripMenuItem.Click += new System.EventHandler(this.缩小ToolStripMenuItem_Click);
            // 
            // 旋转ToolStripMenuItem
            // 
            this.旋转ToolStripMenuItem.Name = "旋转ToolStripMenuItem";
            this.旋转ToolStripMenuItem.Size = new System.Drawing.Size(203, 22);
            this.旋转ToolStripMenuItem.Text = "旋转(Circle)";
            this.旋转ToolStripMenuItem.Click += new System.EventHandler(this.旋转ToolStripMenuItem_Click);
            // 
            // 反转ToolStripMenuItem
            // 
            this.反转ToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.左右ToolStripMenuItem,
            this.上下ToolStripMenuItem});
            this.反转ToolStripMenuItem.Name = "反转ToolStripMenuItem";
            this.反转ToolStripMenuItem.Size = new System.Drawing.Size(203, 22);
            this.反转ToolStripMenuItem.Text = "反转(Rotate)";
            // 
            // 左右ToolStripMenuItem
            // 
            this.左右ToolStripMenuItem.Name = "左右ToolStripMenuItem";
            this.左右ToolStripMenuItem.Size = new System.Drawing.Size(100, 22);
            this.左右ToolStripMenuItem.Text = "左右";
            this.左右ToolStripMenuItem.Click += new System.EventHandler(this.左右ToolStripMenuItem_Click);
            // 
            // 上下ToolStripMenuItem
            // 
            this.上下ToolStripMenuItem.Name = "上下ToolStripMenuItem";
            this.上下ToolStripMenuItem.Size = new System.Drawing.Size(100, 22);
            this.上下ToolStripMenuItem.Text = "上下";
            this.上下ToolStripMenuItem.Click += new System.EventHandler(this.上下ToolStripMenuItem_Click);
            // 
            // toolStripSeparator2
            // 
            this.toolStripSeparator2.Name = "toolStripSeparator2";
            this.toolStripSeparator2.Size = new System.Drawing.Size(200, 6);
            // 
            // 清空ClearToolStripMenuItem
            // 
            this.清空ClearToolStripMenuItem.Name = "清空ClearToolStripMenuItem";
            this.清空ClearToolStripMenuItem.Size = new System.Drawing.Size(203, 22);
            this.清空ClearToolStripMenuItem.Text = "清空(Clear)";
            this.清空ClearToolStripMenuItem.Click += new System.EventHandler(this.清空ClearToolStripMenuItem_Click);
            // 
            // helpHToolStripMenuItem
            // 
            this.helpHToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.关于AboutToolStripMenuItem});
            this.helpHToolStripMenuItem.Name = "helpHToolStripMenuItem";
            this.helpHToolStripMenuItem.ShortcutKeys = ((System.Windows.Forms.Keys)((System.Windows.Forms.Keys.Alt | System.Windows.Forms.Keys.H)));
            this.helpHToolStripMenuItem.Size = new System.Drawing.Size(61, 21);
            this.helpHToolStripMenuItem.Text = "帮助(&H)";
            // 
            // 关于AboutToolStripMenuItem
            // 
            this.关于AboutToolStripMenuItem.Name = "关于AboutToolStripMenuItem";
            this.关于AboutToolStripMenuItem.Size = new System.Drawing.Size(143, 22);
            this.关于AboutToolStripMenuItem.Text = "关于(About)";
            this.关于AboutToolStripMenuItem.Click += new System.EventHandler(this.关于AboutToolStripMenuItem_Click);
            // 
            // FormDealImage
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(1001, 496);
            this.Controls.Add(this.panel1);
            this.Controls.Add(this.menuStrip1);
            this.MainMenuStrip = this.menuStrip1;
            this.MaximizeBox = false;
            this.Name = "FormDealImage";
            this.ShowIcon = false;
            this.Text = "图片的简单处理";
            this.Load += new System.EventHandler(this.FormDealImage_Load);
            this.panel1.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox1)).EndInit();
            this.menuStrip1.ResumeLayout(false);
            this.menuStrip1.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Panel panel1;
        private System.Windows.Forms.MenuStrip menuStrip1;
        private System.Windows.Forms.ToolStripMenuItem fileFToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem editEToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem helpHToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem 任意多边形ToolStripMenuItem;
        private System.Windows.Forms.ToolStripSeparator toolStripSeparator1;
        private System.Windows.Forms.ToolStripMenuItem 放大ToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem 缩小ToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem 反转ToolStripMenuItem;
        private System.Windows.Forms.PictureBox pictureBox1;
        private System.Windows.Forms.ToolStripMenuItem 打开ToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem 保存ToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem 关于AboutToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem jPGToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem bMPToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem pNGToolStripMenuItem1;
        private System.Windows.Forms.ToolStripMenuItem gIFToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem tIFFToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem 边形ToolStripMenuItem1;
        private System.Windows.Forms.ToolStripMenuItem 边形ToolStripMenuItem2;
        private System.Windows.Forms.ToolStripMenuItem 边形ToolStripMenuItem3;
        private System.Windows.Forms.ToolStripMenuItem 边形ToolStripMenuItem4;
        private System.Windows.Forms.ToolStripMenuItem n边形ToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem 清空ClearToolStripMenuItem;
        private System.Windows.Forms.ToolStripSeparator toolStripSeparator2;
        private System.Windows.Forms.ToolStripMenuItem 旋转ToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem 左右ToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem 上下ToolStripMenuItem;
    }
}

