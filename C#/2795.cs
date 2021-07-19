using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace ConsoleApp1
{
    class Program
    {
        static void Main(string[] args)
        {
            string[] a = Console.ReadLine().Split(' ');
            int b = int.Parse(a[0]);
            int c = int.Parse(a[1]);
            int[] d = new int[b];
            string[] e = Console.ReadLine().Split(' ');
            for (int i =0;i < b;i++)
            {
                d[i] = int.Parse(e[i]);
            }
            int f1 = 0;
            int f2 = 1;
            int f3 = 2;
            int g = 0;
            while (true)
            {

                if (f3==b)
                {
                    f2++;
                    f3 = f2+1;
                }
                if(f2 == b-1 && f3 == b)
                {
                    f1++;
                    f2 = f1 + 1;
                    f3 = f2 + 1;
                }
                if (g == c || f1 == b - 2)
                    break;
                int h = d[f1] + d[f2] + d[f3];
                if (h <= c)
                    if (h >= g)
                        g = h;
                f3++;
            }
            Console.WriteLine(g);
        }
    }
}