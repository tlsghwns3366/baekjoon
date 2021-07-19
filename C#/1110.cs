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
            int n = int.Parse(Console.ReadLine());
            int a = 0, b = 0;
            int sum = 0;
            int c = 1;
            if (n < 10)
            {
                a = 0;
                b = n;
                sum = a + b;
                sum = b * 10 + sum % 10;
            }
            else
            {
                a = n / 10;
                b = n % 10;
                sum = a + b;
                sum = b * 10 + sum % 10;
            }
            while (true)
            {
                if (n == sum)
                {
                    break;
                }
                c++;
                a = sum / 10;
                b = sum % 10;
                sum = a + b;
                sum = b * 10 + sum % 10;
            }
            Console.WriteLine(c);
        }
    }
}
