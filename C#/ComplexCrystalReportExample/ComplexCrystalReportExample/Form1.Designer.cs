namespace ComplexCrystalReportExample
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
            this.groupBox1 = new System.Windows.Forms.GroupBox();
            this.radioButtonGPA = new System.Windows.Forms.RadioButton();
            this.radioButtonHan = new System.Windows.Forms.RadioButton();
            this.radioButtonAll = new System.Windows.Forms.RadioButton();
            this.crystalReportViewer1 = new CrystalDecisions.Windows.Forms.CrystalReportViewer();
            this.myDatabaseDataSet1 = new ComplexCrystalReportExample.MyDatabaseDataSet();
            this.myTable2TableAdapter1 = new ComplexCrystalReportExample.MyDatabaseDataSetTableAdapters.MyTable2TableAdapter();
            this.myTable3TableAdapter1 = new ComplexCrystalReportExample.MyDatabaseDataSetTableAdapters.MyTable3TableAdapter();
            this.myTable4TableAdapter1 = new ComplexCrystalReportExample.MyDatabaseDataSetTableAdapters.MyTable4TableAdapter();
            this.splitContainer1.Panel1.SuspendLayout();
            this.splitContainer1.Panel2.SuspendLayout();
            this.splitContainer1.SuspendLayout();
            this.groupBox1.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.myDatabaseDataSet1)).BeginInit();
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
            this.splitContainer1.Panel1.Controls.Add(this.groupBox1);
            // 
            // splitContainer1.Panel2
            // 
            this.splitContainer1.Panel2.Controls.Add(this.crystalReportViewer1);
            this.splitContainer1.Size = new System.Drawing.Size(784, 477);
            this.splitContainer1.SplitterDistance = 53;
            this.splitContainer1.TabIndex = 0;
            // 
            // groupBox1
            // 
            this.groupBox1.Controls.Add(this.radioButtonGPA);
            this.groupBox1.Controls.Add(this.radioButtonHan);
            this.groupBox1.Controls.Add(this.radioButtonAll);
            this.groupBox1.Dock = System.Windows.Forms.DockStyle.Fill;
            this.groupBox1.Location = new System.Drawing.Point(0, 0);
            this.groupBox1.Name = "groupBox1";
            this.groupBox1.Size = new System.Drawing.Size(784, 53);
            this.groupBox1.TabIndex = 0;
            this.groupBox1.TabStop = false;
            this.groupBox1.Text = "选择项";
            // 
            // radioButtonGPA
            // 
            this.radioButtonGPA.AutoSize = true;
            this.radioButtonGPA.Location = new System.Drawing.Point(298, 24);
            this.radioButtonGPA.Name = "radioButtonGPA";
            this.radioButtonGPA.Size = new System.Drawing.Size(125, 16);
            this.radioButtonGPA.TabIndex = 2;
            this.radioButtonGPA.TabStop = true;
            this.radioButtonGPA.Text = "GPA大于3.00的学生";
            this.radioButtonGPA.UseVisualStyleBackColor = true;
            // 
            // radioButtonHan
            // 
            this.radioButtonHan.AutoSize = true;
            this.radioButtonHan.Location = new System.Drawing.Point(164, 24);
            this.radioButtonHan.Name = "radioButtonHan";
            this.radioButtonHan.Size = new System.Drawing.Size(107, 16);
            this.radioButtonHan.TabIndex = 1;
            this.radioButtonHan.TabStop = true;
            this.radioButtonHan.Text = "所有姓韩的学生";
            this.radioButtonHan.UseVisualStyleBackColor = true;
            // 
            // radioButtonAll
            // 
            this.radioButtonAll.AutoSize = true;
            this.radioButtonAll.Location = new System.Drawing.Point(42, 24);
            this.radioButtonAll.Name = "radioButtonAll";
            this.radioButtonAll.Size = new System.Drawing.Size(71, 16);
            this.radioButtonAll.TabIndex = 0;
            this.radioButtonAll.TabStop = true;
            this.radioButtonAll.Text = "全部学生";
            this.radioButtonAll.UseVisualStyleBackColor = true;
            // 
            // crystalReportViewer1
            // 
            this.crystalReportViewer1.ActiveViewIndex = -1;
            this.crystalReportViewer1.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.crystalReportViewer1.Dock = System.Windows.Forms.DockStyle.Fill;
            this.crystalReportViewer1.Location = new System.Drawing.Point(0, 0);
            this.crystalReportViewer1.Name = "crystalReportViewer1";
            this.crystalReportViewer1.SelectionFormula = "";
            this.crystalReportViewer1.Size = new System.Drawing.Size(784, 420);
            this.crystalReportViewer1.TabIndex = 0;
            this.crystalReportViewer1.ViewTimeSelectionFormula = "";
            // 
            // myDatabaseDataSet1
            // 
            this.myDatabaseDataSet1.DataSetName = "MyDatabaseDataSet";
            this.myDatabaseDataSet1.SchemaSerializationMode = System.Data.SchemaSerializationMode.IncludeSchema;
            // 
            // myTable2TableAdapter1
            // 
            this.myTable2TableAdapter1.ClearBeforeFill = true;
            // 
            // myTable3TableAdapter1
            // 
            this.myTable3TableAdapter1.ClearBeforeFill = true;
            // 
            // myTable4TableAdapter1
            // 
            this.myTable4TableAdapter1.ClearBeforeFill = true;
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(784, 477);
            this.Controls.Add(this.splitContainer1);
            this.Name = "Form1";
            this.Text = "Form1";
            this.Load += new System.EventHandler(this.Form1_Load);
            this.splitContainer1.Panel1.ResumeLayout(false);
            this.splitContainer1.Panel2.ResumeLayout(false);
            this.splitContainer1.ResumeLayout(false);
            this.groupBox1.ResumeLayout(false);
            this.groupBox1.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.myDatabaseDataSet1)).EndInit();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.SplitContainer splitContainer1;
        private System.Windows.Forms.GroupBox groupBox1;
        private System.Windows.Forms.RadioButton radioButtonGPA;
        private System.Windows.Forms.RadioButton radioButtonHan;
        private System.Windows.Forms.RadioButton radioButtonAll;
        private CrystalDecisions.Windows.Forms.CrystalReportViewer crystalReportViewer1;
        private MyDatabaseDataSet myDatabaseDataSet1;
        private ComplexCrystalReportExample.MyDatabaseDataSetTableAdapters.MyTable2TableAdapter myTable2TableAdapter1;
        private ComplexCrystalReportExample.MyDatabaseDataSetTableAdapters.MyTable3TableAdapter myTable3TableAdapter1;
        private ComplexCrystalReportExample.MyDatabaseDataSetTableAdapters.MyTable4TableAdapter myTable4TableAdapter1;
    }
}

