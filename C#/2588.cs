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
            string b;
            a = Console.ReadLine();
            b = Console.ReadLine();
            int c,d,e,f,g;
            g = Convert.ToInt32(b);
            c = Convert.ToInt32(a) * (g % 10);
            g /= 10;
            d = Convert.ToInt32(a) * (g % 10);
            g /= 10;
            e = Convert.ToInt32(a) * (g % 10);
            f = e * 100 + d * 10 + c;
            Console.WriteLine(c);
            Console.WriteLine(d);
            Console.WriteLine(e);
            Console.WriteLine(f);
        }
    }
}
