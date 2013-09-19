using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace CreateDatabaseExample
{
    public class DataClass
    {
        //数据
        private string[] data;

        public DataClass(int size)
        {
            data = new string[size];//初始化
        }

        //get、set方法
        public string GetAt(int i)
        {
            return data[i];
        }

        public void SetAt(int i, string s)
        {
            data[i] = s;
        }

        //元素数
        public int Size
        {
            get{
                return data.Length;
            }
        }
    }
}
