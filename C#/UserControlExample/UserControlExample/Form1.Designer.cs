namespace UserControlExample
{
    partial class Form1
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
            this.flashButton4 = new UserControlExample.FlashButton();
            this.flashButton3 = new UserControlExample.FlashButton();
            this.FlashButton2 = new UserControlExample.FlashButton();
            this.flashButton1 = new UserControlExample.FlashButton();
            this.flashButton5 = new UserControlExample.FlashButton();
            this.flashButton6 = new UserControlExample.FlashButton();
            this.SuspendLayout();
            // 
            // flashButton4
            // 
            this.flashButton4.ArcWidth = 20;
            this.flashButton4.ButtonHatchStyle = System.Drawing.Drawing2D.HatchStyle.DiagonalBrick;
            this.flashButton4.ButtonStyle = UserControlExample.FlashButtonStyle.圆角矩形;
            this.flashButton4.ButtonText = "Flash按钮";
            this.flashButton4.CenterColor = System.Drawing.Color.FromArgb(((int)(((byte)(0)))), ((int)(((byte)(0)))), ((int)(((byte)(255)))));
            this.flashButton4.Location = new System.Drawing.Point(233, 25);
            this.flashButton4.Name = "flashButton4";
            this.flashButton4.Size = new System.Drawing.Size(150, 46);
            this.flashButton4.SurroundColor = System.Drawing.Color.FromArgb(((int)(((byte)(0)))), ((int)(((byte)(200)))), ((int)(((byte)(255)))));
            this.flashButton4.TabIndex = 3;
            this.flashButton4.TextColor = System.Drawing.Color.Black;
            // 
            // flashButton3
            // 
            this.flashButton3.ArcWidth = 20;
            this.flashButton3.ButtonHatchStyle = System.Drawing.Drawing2D.HatchStyle.DiagonalBrick;
            this.flashButton3.ButtonStyle = UserControlExample.FlashButtonStyle.椭圆;
            this.flashButton3.ButtonText = "Flash按钮";
            this.flashButton3.CenterColor = System.Drawing.Color.FromArgb(((int)(((byte)(0)))), ((int)(((byte)(0)))), ((int)(((byte)(255)))));
            this.flashButton3.Location = new System.Drawing.Point(12, 25);
            this.flashButton3.Name = "flashButton3";
            this.flashButton3.Size = new System.Drawing.Size(150, 46);
            this.flashButton3.SurroundColor = System.Drawing.Color.FromArgb(((int)(((byte)(0)))), ((int)(((byte)(200)))), ((int)(((byte)(255)))));
            this.flashButton3.TabIndex = 2;
            this.flashButton3.TextColor = System.Drawing.Color.Black;
            // 
            // FlashButton2
            // 
            this.FlashButton2.ArcWidth = 20;
            this.FlashButton2.ButtonHatchStyle = System.Drawing.Drawing2D.HatchStyle.DiagonalBrick;
            this.FlashButton2.ButtonText = "Flash按钮";
            this.FlashButton2.CenterColor = System.Drawing.Color.FromArgb(((int)(((byte)(0)))), ((int)(((byte)(0)))), ((int)(((byte)(255)))));
            this.FlashButton2.Location = new System.Drawing.Point(12, 100);
            this.FlashButton2.Name = "FlashButton2";
            this.FlashButton2.Size = new System.Drawing.Size(150, 46);
            this.FlashButton2.SurroundColor = System.Drawing.Color.FromArgb(((int)(((byte)(0)))), ((int)(((byte)(200)))), ((int)(((byte)(255)))));
            this.FlashButton2.TabIndex = 1;
            this.FlashButton2.TextColor = System.Drawing.Color.Black;
            // 
            // flashButton1
            // 
            this.flashButton1.ArcWidth = 20;
            this.flashButton1.ButtonHatchStyle = System.Drawing.Drawing2D.HatchStyle.BackwardDiagonal;
            this.flashButton1.ButtonStyle = UserControlExample.FlashButtonStyle.阴影;
            this.flashButton1.ButtonText = "阴影按钮";
            this.flashButton1.CenterColor = System.Drawing.Color.FromArgb(((int)(((byte)(0)))), ((int)(((byte)(0)))), ((int)(((byte)(255)))));
            this.flashButton1.Location = new System.Drawing.Point(12, 172);
            this.flashButton1.Name = "flashButton1";
            this.flashButton1.Size = new System.Drawing.Size(150, 46);
            this.flashButton1.SurroundColor = System.Drawing.Color.FromArgb(((int)(((byte)(0)))), ((int)(((byte)(200)))), ((int)(((byte)(255)))));
            this.flashButton1.TabIndex = 0;
            this.flashButton1.TextColor = System.Drawing.Color.Black;
            // 
            // flashButton5
            // 
            this.flashButton5.ArcWidth = 20;
            this.flashButton5.ButtonHatchStyle = System.Drawing.Drawing2D.HatchStyle.DiagonalBrick;
            this.flashButton5.ButtonText = "FlashButton1";
            this.flashButton5.CenterColor = System.Drawing.Color.FromArgb(((int)(((byte)(0)))), ((int)(((byte)(0)))), ((int)(((byte)(255)))));
            this.flashButton5.Location = new System.Drawing.Point(233, 100);
            this.flashButton5.Name = "flashButton5";
            this.flashButton5.Size = new System.Drawing.Size(150, 46);
            this.flashButton5.SurroundColor = System.Drawing.Color.FromArgb(((int)(((byte)(0)))), ((int)(((byte)(200)))), ((int)(((byte)(255)))));
            this.flashButton5.TabIndex = 4;
            this.flashButton5.TextColor = System.Drawing.Color.Black;
            // 
            // flashButton6
            // 
            this.flashButton6.ArcWidth = 20;
            this.flashButton6.ButtonHatchStyle = System.Drawing.Drawing2D.HatchStyle.DiagonalBrick;
            this.flashButton6.ButtonText = "FlashButton1";
            this.flashButton6.CenterColor = System.Drawing.Color.FromArgb(((int)(((byte)(0)))), ((int)(((byte)(0)))), ((int)(((byte)(255)))));
            this.flashButton6.Location = new System.Drawing.Point(233, 172);
            this.flashButton6.Name = "flashButton6";
            this.flashButton6.Size = new System.Drawing.Size(150, 46);
            this.flashButton6.SurroundColor = System.Drawing.Color.FromArgb(((int)(((byte)(0)))), ((int)(((byte)(200)))), ((int)(((byte)(255)))));
            this.flashButton6.TabIndex = 5;
            this.flashButton6.TextColor = System.Drawing.Color.Black;
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(432, 262);
            this.Controls.Add(this.flashButton6);
            this.Controls.Add(this.flashButton5);
            this.Controls.Add(this.flashButton4);
            this.Controls.Add(this.flashButton3);
            this.Controls.Add(this.FlashButton2);
            this.Controls.Add(this.flashButton1);
            this.Name = "Form1";
            this.Text = "Form1";
            this.ResumeLayout(false);

        }

        #endregion

        private FlashButton flashButton1;
        private FlashButton FlashButton2;
        private FlashButton flashButton3;
        private FlashButton flashButton4;
        private FlashButton flashButton5;
        private FlashButton flashButton6;
    }
}

