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
            int a= 0;
            while ((a = int.Parse(Console.ReadLine()))!=0)
            {
                int c = 0;
                for (int i = a+1; i <= 2*a ; i++)
                {
                    if(sosu(i)!=0)
                    {
                        c++;
                    }
                }
                Console.WriteLine(c);
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