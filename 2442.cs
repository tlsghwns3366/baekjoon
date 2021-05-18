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
            for(int i =0; i<a; i++)
            {
                for (int j = a-i; j > 1; j--)
                {
                    Console.Write(" ");
                }
                for(int j = 0 ;j< i * 2 + 1;j++)
                {
                    Console.Write("*");
                }
                Console.WriteLine();
            }
        }
    }
}