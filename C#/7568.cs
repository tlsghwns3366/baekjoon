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
            int[,] b = new int[a, 2];
            for (int i = 0; i < a; i++)
            {
                string[] c = Console.ReadLine().Split(' ');
                b[i, 0] = int.Parse(c[0]);
                b[i, 1] = int.Parse(c[1]);
            }
            for (int i =0;i<a;i++)
            {
                int d = 1;
                for (int j =0;j<a;j++)
                {
                    if (b[i, 0] < b[j, 0] && b[i, 1] < b[j, 1])
                    {
                        d++;
                    }
                }
                Console.Write(d);
                Console.WriteLine();
            }


        }
    }
}