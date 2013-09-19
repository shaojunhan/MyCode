using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace ClassLibrary_Palindrome
{
    /// <summary>
    /// DLL组件设计(判断回文)
    /// </summary>
    public class Palindrome
    {
        /// <summary>
        /// 判断一个字符串是否是回文(正、反读都一样)，比如"madam"是回文
        /// </summary>
        /// <param name="s">字符串</param>
        /// <returns>如果是回文返回true，否则返回false</returns>
        public bool IsPalindrome(string s)
        {
            //初始化，判断s参数是否合法
            if (s == null)
                return false;
            int length = s.Length;
            if (length <= 0)
                return false;

            //判断回文
            for (int i = 0; i < length / 2; i++)
            {
                if (s[i] != s[length - i-1])
                {
                    return false;//不是回文
                }
            }
            //是回文
            return true;
        }
    }
}
