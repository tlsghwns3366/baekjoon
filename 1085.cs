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
            string[] a =Console.ReadLine().Split(' ');
            int x = int.Parse(a[0]);
            int y = int.Parse(a[1]);
            int w = int.Parse(a[2]);
            int h = int.Parse(a[3]);
            int s = x;
            if (h - y > w - x)
                s = w - x;
            else
                s = h - y;
            if (s > x)
                s = x;
            if (s > y)
                s = y;
            Console.WriteLine(s);

        }
    }
}