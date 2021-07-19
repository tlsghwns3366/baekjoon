using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp2
{
    class Program
    {
        static void Main(string[] args)
        {
            string a;
            a = Console.ReadLine();
            int b = 0;
            for (int i = 1; i <= Convert.ToInt32(a); i++)
            {
                b = b + i;
            }
            Console.WriteLine(b);
        }
    }
}
