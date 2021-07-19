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
            string[] b = Console.ReadLine().Split(' ');
            int c = a;
            for(int i =0;i<a;i++)
            {
                for (int j = 2; j <= 1000; j++)
                {
                    if (int.Parse(b[i]) % j == 0 && j != int.Parse(b[i]) || int.Parse(b[i]) == 1)
                    {
                        c--;
                        break;
                    }
                }
            }
            Console.WriteLine(c);
        }
    }
}