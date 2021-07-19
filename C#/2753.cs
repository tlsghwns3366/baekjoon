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
            
            int c;
            if ((Convert.ToInt32(a) % 4 == 0 && Convert.ToInt32(a) % 100 != 0)|| Convert.ToInt32(a)%400 == 0)
            {
                c = 1;
            }
            else
            {
                c = 0;
            }
            Console.WriteLine(c);
        }
    }
}
