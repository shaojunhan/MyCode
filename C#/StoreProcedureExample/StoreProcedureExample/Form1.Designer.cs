namespace StoreProcedureExample
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
            this.splitContainer1 = new System.Windows.Forms.SplitContainer();
            this.radioButtonGrade = new System.Windows.Forms.RadioButton();
            this.radioButtonCount = new System.Windows.Forms.RadioButton();
            this.buttonQuery = new System.Windows.Forms.Button();
            this.listBox1 = new System.Windows.Forms.ListBox();
            this.splitContainer1.Panel1.SuspendLayout();
            this.splitContainer1.Panel2.SuspendLayout();
            this.splitContainer1.SuspendLayout();
            this.SuspendLayout();
            // 
            // splitContainer1
            // 
            this.splitContainer1.Dock = System.Windows.Forms.DockStyle.Fill;
            this.splitContainer1.IsSplitterFixed = true;
            this.splitContainer1.Location = new System.Drawing.Point(0, 0);
            this.splitContainer1.Name = "splitContainer1";
            this.splitContainer1.Orientation = System.Windows.Forms.Orientation.Horizontal;
            // 
            // splitContainer1.Panel1
            // 
            this.splitContainer1.Panel1.Controls.Add(this.buttonQuery);
            this.splitContainer1.Panel1.Controls.Add(this.radioButtonCount);
            this.splitContainer1.Panel1.Controls.Add(this.radioButtonGrade);
            // 
            // splitContainer1.Panel2
            // 
            this.splitContainer1.Panel2.Controls.Add(this.listBox1);
            this.splitContainer1.Size = new System.Drawing.Size(367, 262);
            this.splitContainer1.SplitterDistance = 97;
            this.splitContainer1.TabIndex = 0;
            // 
            // radioButtonGrade
            // 
            this.radioButtonGrade.AutoSize = true;
            this.radioButtonGrade.Location = new System.Drawing.Point(43, 28);
            this.radioButtonGrade.Name = "radioButtonGrade";
            this.radioButtonGrade.Size = new System.Drawing.Size(107, 16);
            this.radioButtonGrade.TabIndex = 0;
            this.radioButtonGrade.TabStop = true;
            this.radioButtonGrade.Text = "显示所有的年级";
            this.radioButtonGrade.UseVisualStyleBackColor = true;
            // 
            // radioButtonCount
            // 
            this.radioButtonCount.AutoSize = true;
            this.radioButtonCount.Location = new System.Drawing.Point(194, 28);
            this.radioButtonCount.Name = "radioButtonCount";
            this.radioButtonCount.Size = new System.Drawing.Size(143, 16);
            this.radioButtonCount.TabIndex = 1;
            this.radioButtonCount.TabStop = true;
            this.radioButtonCount.Text = "查询男生和女生的人数";
            this.radioButtonCount.UseVisualStyleBackColor = true;
            // 
            // buttonQuery
            // 
            this.buttonQuery.Location = new System.Drawing.Point(132, 60);
            this.buttonQuery.Name = "buttonQuery";
            this.buttonQuery.Size = new System.Drawing.Size(75, 23);
            this.buttonQuery.TabIndex = 2;
            this.buttonQuery.Text = "查询";
            this.buttonQuery.UseVisualStyleBackColor = true;
            this.buttonQuery.Click += new System.EventHandler(this.buttonQuery_Click);
            // 
            // listBox1
            // 
            this.listBox1.Dock = System.Windows.Forms.DockStyle.Fill;
            this.listBox1.FormattingEnabled = true;
            this.listBox1.ItemHeight = 12;
            this.listBox1.Location = new System.Drawing.Point(0, 0);
            this.listBox1.Name = "listBox1";
            this.listBox1.Size = new System.Drawing.Size(367, 160);
            this.listBox1.TabIndex = 0;
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(367, 262);
            this.Controls.Add(this.splitContainer1);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedSingle;
            this.MaximizeBox = false;
            this.Name = "Form1";
            this.Text = "StoreProcedureExample";
            this.Load += new System.EventHandler(this.Form1_Load);
            this.splitContainer1.Panel1.ResumeLayout(false);
            this.splitContainer1.Panel1.PerformLayout();
            this.splitContainer1.Panel2.ResumeLayout(false);
            this.splitContainer1.ResumeLayout(false);
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.SplitContainer splitContainer1;
        private System.Windows.Forms.Button buttonQuery;
        private System.Windows.Forms.RadioButton radioButtonCount;
        private System.Windows.Forms.RadioButton radioButtonGrade;
        private System.Windows.Forms.ListBox listBox1;
    }
}

