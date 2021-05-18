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
            int a = int.Parse(Console.ReadLine());
            Console.WriteLine(f(a).ToString());
        }
        static public int f(int a)
        {
            if (a > 1)
                return f(a - 2) + f(a-1);
            else if (a == 1)
                return 1;
            else
                return 0;
        }
    }
}