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
            for(int i = 1; i < 10; i++)
            {
                Console.WriteLine(a + " * " + i + " = "+ i*Convert.ToInt32(a));
            }
        }
    }
}
