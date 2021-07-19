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
            int c = 0;
            if (int.Parse(a[2]) - int.Parse(a[1]) > 0)
            {
                b = b / (int.Parse(a[2]) - int.Parse(a[1])) + 1;
                Console.WriteLine(b);
            }
            else
            {
                c = -1;
                Console.WriteLine(c);
            }
        }
    }
}