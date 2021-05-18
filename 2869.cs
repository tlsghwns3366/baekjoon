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
            int[] b = new int[3];
            int c;
            b[0] = int.Parse(a[0]);
            b[1] = int.Parse(a[1]);
            b[2] = int.Parse(a[2]);
            c = (b[2] - b[1] -1) / (b[0]-b[1]) +1;
            Console.WriteLine(c);
        }
    }
}