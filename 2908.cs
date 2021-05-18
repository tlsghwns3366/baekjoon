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
            int b = int.Parse(a[0]);
            int c = int.Parse(a[1]);

            int d = 0,e = 0;
            for (int i = 0; i < 3; i++)
            {
                d = d * 10;
                e = e * 10;
                d = d + (b % 10);
                e = e + (c % 10);
                b = b / 10;
                c = c / 10;
            }
            if(d>e)
            {
                Console.WriteLine(d);
            }
            else
            {
                Console.WriteLine(e);
            }
        }
    }
    
}
