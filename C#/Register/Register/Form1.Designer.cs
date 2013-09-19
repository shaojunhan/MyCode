namespace Register
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
            this.components = new System.ComponentModel.Container();
            this.labelPassWord = new System.Windows.Forms.Label();
            this.labelUser = new System.Windows.Forms.Label();
            this.groupBox1 = new System.Windows.Forms.GroupBox();
            this.tBUser = new System.Windows.Forms.TextBox();
            this.tBPassWord = new System.Windows.Forms.TextBox();
            this.groupBox2 = new System.Windows.Forms.GroupBox();
            this.tBUserInfo = new System.Windows.Forms.TextBox();
            this.oK = new System.Windows.Forms.Button();
            this.errorProvider1 = new System.Windows.Forms.ErrorProvider(this.components);
            this.helpProvider1 = new System.Windows.Forms.HelpProvider();
            this.groupBox1.SuspendLayout();
            this.groupBox2.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.errorProvider1)).BeginInit();
            this.SuspendLayout();
            // 
            // labelPassWord
            // 
            this.labelPassWord.AutoSize = true;
            this.labelPassWord.Location = new System.Drawing.Point(20, 71);
            this.labelPassWord.Name = "labelPassWord";
            this.labelPassWord.Size = new System.Drawing.Size(53, 12);
            this.labelPassWord.TabIndex = 0;
            this.labelPassWord.Text = "PassWord";
            // 
            // labelUser
            // 
            this.labelUser.AutoSize = true;
            this.labelUser.Location = new System.Drawing.Point(20, 34);
            this.labelUser.Name = "labelUser";
            this.labelUser.Size = new System.Drawing.Size(29, 12);
            this.labelUser.TabIndex = 1;
            this.labelUser.Text = "User";
            // 
            // groupBox1
            // 
            this.groupBox1.Controls.Add(this.tBUser);
            this.groupBox1.Controls.Add(this.tBPassWord);
            this.groupBox1.Controls.Add(this.labelPassWord);
            this.groupBox1.Controls.Add(this.labelUser);
            this.groupBox1.Location = new System.Drawing.Point(1, 2);
            this.groupBox1.Name = "groupBox1";
            this.groupBox1.Size = new System.Drawing.Size(313, 100);
            this.groupBox1.TabIndex = 2;
            this.groupBox1.TabStop = false;
            // 
            // tBUser
            // 
            this.tBUser.Location = new System.Drawing.Point(87, 34);
            this.tBUser.Name = "tBUser";
            this.tBUser.Size = new System.Drawing.Size(193, 21);
            this.tBUser.TabIndex = 3;
            this.tBUser.TextChanged += new System.EventHandler(this.tBUser_TextChanged);
            this.tBUser.Validating += new System.ComponentModel.CancelEventHandler(this.tBUser_Validating);
            // 
            // tBPassWord
            // 
            this.tBPassWord.Location = new System.Drawing.Point(87, 71);
            this.tBPassWord.Name = "tBPassWord";
            this.tBPassWord.PasswordChar = '*';
            this.tBPassWord.Size = new System.Drawing.Size(193, 21);
            this.tBPassWord.TabIndex = 2;
            this.tBPassWord.TextChanged += new System.EventHandler(this.tBPassWord_TextChanged);
            this.tBPassWord.Validating += new System.ComponentModel.CancelEventHandler(this.tBPassWord_Validating);
            // 
            // groupBox2
            // 
            this.groupBox2.Controls.Add(this.tBUserInfo);
            this.groupBox2.Location = new System.Drawing.Point(1, 139);
            this.groupBox2.Name = "groupBox2";
            this.groupBox2.Size = new System.Drawing.Size(313, 44);
            this.groupBox2.TabIndex = 3;
            this.groupBox2.TabStop = false;
            this.groupBox2.Text = "PassWordMessage";
            // 
            // tBUserInfo
            // 
            this.tBUserInfo.Location = new System.Drawing.Point(5, 15);
            this.tBUserInfo.Name = "tBUserInfo";
            this.tBUserInfo.ReadOnly = true;
            this.tBUserInfo.Size = new System.Drawing.Size(275, 21);
            this.tBUserInfo.TabIndex = 0;
            // 
            // oK
            // 
            this.oK.Location = new System.Drawing.Point(101, 109);
            this.oK.Name = "oK";
            this.oK.Size = new System.Drawing.Size(75, 23);
            this.oK.TabIndex = 4;
            this.oK.Text = "OK";
            this.oK.UseVisualStyleBackColor = true;
            this.oK.Click += new System.EventHandler(this.oK_Click);
            // 
            // errorProvider1
            // 
            this.errorProvider1.ContainerControl = this;
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(318, 185);
            this.Controls.Add(this.oK);
            this.Controls.Add(this.groupBox2);
            this.Controls.Add(this.groupBox1);
            this.Name = "Form1";
            this.ShowIcon = false;
            this.Text = "Register";
            this.Load += new System.EventHandler(this.Form1_Load);
            this.groupBox1.ResumeLayout(false);
            this.groupBox1.PerformLayout();
            this.groupBox2.ResumeLayout(false);
            this.groupBox2.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.errorProvider1)).EndInit();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.Label labelPassWord;
        private System.Windows.Forms.Label labelUser;
        private System.Windows.Forms.GroupBox groupBox1;
        private System.Windows.Forms.GroupBox groupBox2;
        private System.Windows.Forms.TextBox tBUserInfo;
        private System.Windows.Forms.Button oK;
        private System.Windows.Forms.TextBox tBUser;
        private System.Windows.Forms.TextBox tBPassWord;
        private System.Windows.Forms.ErrorProvider errorProvider1;
        private System.Windows.Forms.HelpProvider helpProvider1;
    }
}

