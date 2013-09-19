using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Data.SqlClient;
using System.Data.SqlTypes;
using System.Data;
using System.Windows.Forms;

namespace DataGridViewExample
{
    enum ConnectionStyle{Express,Other};
    class SqlClass
    {
        //
        public SqlDataAdapter Adapter{get;set;}
        public DataTable Table{get;set;}
        public string ConnectionString{get;set;}

        public SqlClass(string selectString, ConnectionStyle sqlStyle)
        {
            if (sqlStyle == ConnectionStyle.Express)
            {
                ConnectionString = @"Data Source=.\SQLEXPRESS;" +
                    @"AttachDbFileName=|DataDirectory|\MyDatabase.mdf;" +
                    "Integrated Security=True;User Instance=True";
            }
            else
            {
                ConnectionString = "Integrated Security=SSPI;"+
                    "Persist Security Info=False;"+
                    "Initial Catalog=MyDatabase;Data Source=localhost";
            }

            try
            {
                Adapter = new SqlDataAdapter(selectString, ConnectionString);
                Table = new DataTable();
                Adapter.FillSchema(Table, SchemaType.Source);
                SqlCommandBuilder builder = new SqlCommandBuilder(Adapter);
            }
            catch (Exception e)
            {
                string s = e.ToString();
                int startIndex = s.IndexOf(':');
                int endIndex = s.IndexOf('。');
                MessageBox.Show("数据库连接错误:" + s.Substring(startIndex+1, endIndex-startIndex-1));
            }
        }
    }
}
