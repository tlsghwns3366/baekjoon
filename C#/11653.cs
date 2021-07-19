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
            int b = 0;
            for(int i =2;i<=a;i++)
            {
                if(a%i==0)
                {
                    b = a / i;
                    a = b;
                    Console.WriteLine(i);
                    i = 1;
                }
            }
        }
    }
}