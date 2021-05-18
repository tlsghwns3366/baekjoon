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
            for (int i = a; i > 0; i--)
            {
                for (int j = i; j < a; j++)
                {
                    Console.Write(" ");
                }
                for (int j = i * 2 - 1; j > 0; j--)
                {
                    Console.Write("*");
                }
                Console.WriteLine();
            }
        }
    }
}