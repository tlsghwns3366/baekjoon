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
            int b = 1;
            for(int i =1; i< a;)
            {
                i = i + 6 * b ;
                b++;
            }
            Console.WriteLine(b);
        }
    }
}