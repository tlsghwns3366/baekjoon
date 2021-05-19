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
            for (int i = 0; i < a; i++)
            {
                int b = i;
                int c = b;
                for (int j = 0; j < i.ToString().Length;j++)
                {
                    c += b % 10;
                    if (i >= 10)
                        b = b / 10;
                }
                if (c == a)
                {
                    Console.WriteLine(i);
                    break;
                }
                if (i == a-1)
                    Console.WriteLine(0);
            }
        }
    }
}