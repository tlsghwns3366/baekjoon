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
            int a = int.Parse(Console.ReadLine());
            int b = int.Parse(Console.ReadLine());
            int c = int.Parse(Console.ReadLine());

            int d = a * b * c;
            int count = d.ToString().Length;
            int[] count2 = new int[10];
            for (int i =0; i < count; i++)
            {
                int e;
                e = d % 10;
                count2[e]++;
                d = d / 10;
            }
            for(int i =0; i <= 9;i++)
            {
                Console.WriteLine(count2[i]);
            }
        }
    }
}
