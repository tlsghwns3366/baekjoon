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
            int c,d,e,f,g;
            c = Convert.ToInt32(b[0]) + Convert.ToInt32(b[1]);
            d = Convert.ToInt32(b[0]) - Convert.ToInt32(b[1]);
            e = Convert.ToInt32(b[0]) * Convert.ToInt32(b[1]);
            f = Convert.ToInt32(b[0]) / Convert.ToInt32(b[1]);
            g = Convert.ToInt32(b[0]) % Convert.ToInt32(b[1]);
            Console.WriteLine(c);
            Console.WriteLine(d);
            Console.WriteLine(e);
            Console.WriteLine(f);
            Console.WriteLine(g);

        }
    }
}
