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
            int n = int.Parse(Console.ReadLine());
            int[] a = new int[n];
            string[] b = Console.ReadLine().Split(' ');
            for (int i = 0; i < n; i++)
            {
                a[i] = int.Parse(b[i]);
            }
            Array.Sort(a);
            Console.WriteLine(a[0] + " " + a[n - 1]);
        }
    }
}