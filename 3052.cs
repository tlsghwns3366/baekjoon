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
            int[] a = new int[10];
            int[] b = new int[10];
            for (int i = 0; i < 10; i++)
            {
                a[i] = int.Parse(Console.ReadLine());
                b[i] = a[i] % 42;
            }
            int count = 10;
            bool[] c = new bool[10] { false, false, false, false, false, false, false, false, false, false };
            for (int i = 0; i < 10; i++)
            {
                for(int j = i; j < 10; j++)
                {
                    if (b[i] == b[j] && i != j && c[i] == false)
                    {
                        c[j] = true;
                        count--;
                    }
                }
            }
            Console.WriteLine(count);
        }
    }
}
