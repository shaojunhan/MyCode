namespace CreateDBTest
{
    partial class dbForm
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
            this.dbGridView = new System.Windows.Forms.DataGridView();
            this.dbPanel = new System.Windows.Forms.Panel();
            this.mydatabaseDataSet1 = new CreateDBTest.MydatabaseDataSet();
            this.radioButton1 = new System.Windows.Forms.RadioButton();
            this.radioButton2 = new System.Windows.Forms.RadioButton();
            this.radioButton3 = new System.Windows.Forms.RadioButton();
            this.button1 = new System.Windows.Forms.Button();
            this.button2 = new System.Windows.Forms.Button();
            this.panel1 = new System.Windows.Forms.Panel();
            this.dbListBox = new System.Windows.Forms.ListBox();
            ((System.ComponentModel.ISupportInitialize)(this.dbGridView)).BeginInit();
            this.dbPanel.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.mydatabaseDataSet1)).BeginInit();
            this.panel1.SuspendLayout();
            this.SuspendLayout();
            // 
            // dbGridView
            // 
            this.dbGridView.BackgroundColor = System.Drawing.Color.Silver;
            this.dbGridView.BorderStyle = System.Windows.Forms.BorderStyle.Fixed3D;
            this.dbGridView.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.dbGridView.Dock = System.Windows.Forms.DockStyle.Fill;
            this.dbGridView.GridColor = System.Drawing.SystemColors.ActiveCaptionText;
            this.dbGridView.Location = new System.Drawing.Point(0, 0);
            this.dbGridView.Margin = new System.Windows.Forms.Padding(0);
            this.dbGridView.Name = "dbGridView";
            this.dbGridView.RowTemplate.Height = 23;
            this.dbGridView.Size = new System.Drawing.Size(249, 150);
            this.dbGridView.TabIndex = 0;
            // 
            // dbPanel
            // 
            this.dbPanel.AutoScroll = true;
            this.dbPanel.AutoSize = true;
            this.dbPanel.Controls.Add(this.dbGridView);
            this.dbPanel.Location = new System.Drawing.Point(0, 0);
            this.dbPanel.Name = "dbPanel";
            this.dbPanel.Size = new System.Drawing.Size(249, 150);
            this.dbPanel.TabIndex = 1;
            // 
            // mydatabaseDataSet1
            // 
            this.mydatabaseDataSet1.DataSetName = "MydatabaseDataSet";
            this.mydatabaseDataSet1.SchemaSerializationMode = System.Data.SchemaSerializationMode.IncludeSchema;
            // 
            // radioButton1
            // 
            this.radioButton1.AutoSize = true;
            this.radioButton1.Checked = true;
            this.radioButton1.Location = new System.Drawing.Point(58, 167);
            this.radioButton1.Name = "radioButton1";
            this.radioButton1.Size = new System.Drawing.Size(83, 16);
            this.radioButton1.TabIndex = 2;
            this.radioButton1.TabStop = true;
            this.radioButton1.Text = "MajorTable";
            this.radioButton1.UseVisualStyleBackColor = true;
            this.radioButton1.CheckedChanged += new System.EventHandler(this.radioButton_CheckedChanged);
            // 
            // radioButton2
            // 
            this.radioButton2.AutoSize = true;
            this.radioButton2.Location = new System.Drawing.Point(58, 190);
            this.radioButton2.Name = "radioButton2";
            this.radioButton2.Size = new System.Drawing.Size(149, 16);
            this.radioButton2.TabIndex = 3;
            this.radioButton2.TabStop = true;
            this.radioButton2.Text = "StudentBasicDataTable";
            this.radioButton2.UseVisualStyleBackColor = true;
            this.radioButton2.CheckedChanged += new System.EventHandler(this.radioButton_CheckedChanged);
            // 
            // radioButton3
            // 
            this.radioButton3.AutoSize = true;
            this.radioButton3.Location = new System.Drawing.Point(58, 213);
            this.radioButton3.Name = "radioButton3";
            this.radioButton3.Size = new System.Drawing.Size(95, 16);
            this.radioButton3.TabIndex = 4;
            this.radioButton3.TabStop = true;
            this.radioButton3.Text = "MessageTable";
            this.radioButton3.UseVisualStyleBackColor = true;
            this.radioButton3.CheckedChanged += new System.EventHandler(this.radioButton_CheckedChanged);
            // 
            // button1
            // 
            this.button1.Location = new System.Drawing.Point(258, 190);
            this.button1.Name = "button1";
            this.button1.Size = new System.Drawing.Size(75, 23);
            this.button1.TabIndex = 5;
            this.button1.Text = "OK";
            this.button1.UseVisualStyleBackColor = true;
            this.button1.Click += new System.EventHandler(this.button1_Click);
            // 
            // button2
            // 
            this.button2.Location = new System.Drawing.Point(376, 189);
            this.button2.Name = "button2";
            this.button2.Size = new System.Drawing.Size(75, 23);
            this.button2.TabIndex = 6;
            this.button2.Text = "Cancel";
            this.button2.UseVisualStyleBackColor = true;
            this.button2.Click += new System.EventHandler(this.button2_Click);
            // 
            // panel1
            // 
            this.panel1.Controls.Add(this.dbListBox);
            this.panel1.Location = new System.Drawing.Point(251, 0);
            this.panel1.Name = "panel1";
            this.panel1.Size = new System.Drawing.Size(254, 150);
            this.panel1.TabIndex = 7;
            // 
            // dbListBox
            // 
            this.dbListBox.FormattingEnabled = true;
            this.dbListBox.ItemHeight = 12;
            this.dbListBox.Location = new System.Drawing.Point(1, 1);
            this.dbListBox.Name = "dbListBox";
            this.dbListBox.Size = new System.Drawing.Size(252, 148);
            this.dbListBox.TabIndex = 0;
            // 
            // dbForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(505, 250);
            this.Controls.Add(this.panel1);
            this.Controls.Add(this.button2);
            this.Controls.Add(this.button1);
            this.Controls.Add(this.radioButton3);
            this.Controls.Add(this.radioButton2);
            this.Controls.Add(this.radioButton1);
            this.Controls.Add(this.dbPanel);
            this.MaximizeBox = false;
            this.Name = "dbForm";
            this.Text = "DBTest";
            this.Load += new System.EventHandler(this.dbForm_Load);
            ((System.ComponentModel.ISupportInitialize)(this.dbGridView)).EndInit();
            this.dbPanel.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize)(this.mydatabaseDataSet1)).EndInit();
            this.panel1.ResumeLayout(false);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.DataGridView dbGridView;
        private System.Windows.Forms.Panel dbPanel;
        private MydatabaseDataSet mydatabaseDataSet1;
        private System.Windows.Forms.RadioButton radioButton1;
        private System.Windows.Forms.RadioButton radioButton2;
        private System.Windows.Forms.RadioButton radioButton3;
        private System.Windows.Forms.Button button1;
        private System.Windows.Forms.Button button2;
        private System.Windows.Forms.Panel panel1;
        private System.Windows.Forms.ListBox dbListBox;
    }
}

