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
            bool b = false;
            if (a % 5 == 0)
            {
                Console.WriteLine(a / 5);
                b = true;
            }
            else
            {
                for (int i = 1; i < 2000; i++)
                {
                    for(int j = 0; j< 1000;j++)
                    {
                        if (3 * i + 5 * j == a && !b)
                        {
                            Console.WriteLine(i+j);
                            b = true;
                        }
                    }
                }
            }
            if(b==false)
            {
                Console.WriteLine(-1);
            }
        }
    }
}