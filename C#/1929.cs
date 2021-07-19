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
            int[] t = new int[c+1];
            Array.Clear(t, 0, c+1);
            int d = (int)Math.Sqrt(c);
            StringBuilder stringBuilder = new StringBuilder();
            t[1] = 1;
            for (int j = 2; j <= d; j++)
            {
                for (int i = j+j; i < c + 1; i=i+j)
                {
                    t[i] = 1;
                }
            }
            for (int i = b; i <= c; i++)
            {
                if (t[i] != 1)
                    stringBuilder.AppendLine(i.ToString());
            }
            Console.Write(stringBuilder);
        }
    }
}