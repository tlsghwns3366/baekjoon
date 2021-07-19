using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace ConsoleApp2
{
    class Program
    {
        static void Main(string[] args)
        {
            int a = int.Parse(Console.ReadLine());
            int count = 0;
            for (int i = 1; i <= a; i++)
            {
                if (np(i) == true)
                {
                    count++;
                }
            }
            Console.Write(count);
            bool np(int n)
            {
                int len = n.ToString().Length;
                int[] s = new int[len];
                for (int i = 0; i < len; i++)
                {
                    s[i] = n % 10;
                    n = n / 10;
                }
                int c1;
                int c2;
                bool b = true; ;
                for (int i = 1; i < s.Length-1; i++)
                {
                    c1 = s[i-1] - s[i];
                    c2 = s[i] - s[i + 1];
                    if(c1 != c2)
                    {
                        b = false;
                    }
                    else
                    {
                        b = true;
                    }
                }
                return b;
            }
        }
    }
}
