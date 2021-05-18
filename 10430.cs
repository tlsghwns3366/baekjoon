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
            int c,d,e,f;
            c = (Convert.ToInt32(b[0]) + Convert.ToInt32(b[1])) % Convert.ToInt32(b[2]);
            d = ((Convert.ToInt32(b[0]) % Convert.ToInt32(b[2])) + (Convert.ToInt32(b[1]) % Convert.ToInt32(b[2]))) % Convert.ToInt32(b[2]);
            e = (Convert.ToInt32(b[0]) * Convert.ToInt32(b[1])) % Convert.ToInt32(b[2]);
            f = ((Convert.ToInt32(b[0]) % Convert.ToInt32(b[2])) * (Convert.ToInt32(b[1]) % Convert.ToInt32(b[2]))) % Convert.ToInt32(b[2]);
            Console.WriteLine(c);
            Console.WriteLine(d);
            Console.WriteLine(e);
            Console.WriteLine(f);
        }
    }
}
