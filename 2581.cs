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
            int b = int.Parse(Console.ReadLine());
            int c = 0;
            int d = -1;
            for (int i = a; i <=     b; i++)
            {
                    c += sosu(i);
                if(sosu(i)!=0 && d == -1)
                {
                    d = i;
                }
            }
            if(d==-1)
                Console.WriteLine(d);
            else
            {
                Console.WriteLine(c);
                Console.WriteLine(d);
            }
        }
        private static int sosu(int a)
        {
            int b = (int)Math.Sqrt(a);
            if (a == 1)
                return 0;
            for (int i = 2; i <= b; i++)
            {
                if (a % i == 0 && a != i)
                return 0;
            }
            return a;
        }
    }
}