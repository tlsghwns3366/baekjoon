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
            string[] a = Console.ReadLine().Split(' ');
            char[] b = a[0].ToCharArray().Reverse().ToArray();
            char[] c = a[1].ToCharArray().Reverse().ToArray();
            int len;
            if(b.Length > c.Length)
                len = b.Length;
            else
                len = c.Length;
            int f = 0;
            string s ="";
            StringBuilder stringBuilder = new StringBuilder();
            for (int i=0;i< len;i++)
            {
                int e = 0;
                if (i < b.Length)
                    e += (b[i] - '0');
                else
                    e += 0;
                if (i < c.Length)
                    e += (c[i] - '0');
                else
                    e += 0;
                if (f==1)
                {
                    e++;
                    f = 0;
                }
                if (e >= 10)
                {
                    s += e % 10;
                    f = 1;
                }
                else
                    s += e;
            }
            if (f == 1)
                s += f;
            Console.WriteLine(s.ToCharArray().Reverse().ToArray());
        }
    }
}