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
            int[] a = new int[10000];
            StringBuilder stringBuilder = new StringBuilder();
            for (int i = 0; i < 10000; i++)
            {
                int b = np(i + 1);
                if (b < 10000)
                {
                    a[b] = 1;
                }
                if (a[i] != 1 && i !=0)
                {
                    stringBuilder.AppendLine(i.ToString());
                }
            }
            Console.WriteLine(stringBuilder);
            int np(int n)
            {
                int dn = n;
                int len = n.ToString().Length;
                for (int i = 0; i < len; i++)
                {
                    if (n >= 10)
                    {
                        dn += n % 10;
                        n = n / 10;
                    }
                    else
                    {
                        dn += n;
                    }
                }
                return dn;
            }
        }
    }
}
