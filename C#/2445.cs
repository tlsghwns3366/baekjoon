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
            for (int i = 0; i < a*2-1; i++)
            {
                if (i < a)
                {
                    for (int j = 0; j <= i; j++)
                    {
                        Console.Write("*");
                    }
                }
                else
                {
                    for (int j = 2*a-i; j > 1; j--)
                    {
                        Console.Write("*");
                    }
                }
                if (i < a)
                {
                    for (int j = 2 * a -2* i ; j > 2; j--)
                    {
                        Console.Write(" ");
                    }
                }
                else
                {
                    for (int j = a-1; j <= 2*i-a; j++)
                    {
                        Console.Write(" ");
                    }
                }
                if (i < a)
                {
                    for (int j = 0; j <= i; j++)
                    {
                        Console.Write("*");
                    }
                }
                else
                {
                    for (int j = 2 * a - i; j > 1; j--)
                    {
                        Console.Write("*");
                    }
                }
                Console.WriteLine();
            }
        }
    }
}