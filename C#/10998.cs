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
            string[] b;
            a = Console.ReadLine();
            b = a.Split(' ');
            int c;
            c = Convert.ToInt32(b[0]) * Convert.ToInt32(b[1]);
            Console.Write(c);
        }
    }
}
