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
            string[] b = Console.ReadLine().Split(' ');
            string[] c = Console.ReadLine().Split(' ');
            string[] d = new string[2];

            if(a[0]==b[0])
            {
                d[0] = c[0];
            }
            else if (b[0] == c[0])
            {
                d[0] = a[0];
            }
            else
            {
                d[0] = b[0];
            }

            if (a[1] == b[1])
            {
                d[1] = c[1];
            }
            else if (b[1] == c[1])
            {
                d[1] = a[1];
            }
            else
            {
                d[1] = b[1];
            }
            Console.WriteLine(d[0] + " " + d[1]);
        }
    }
}