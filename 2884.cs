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

            int c,d;
            c = Convert.ToInt32(b[0]);

            if((d = Convert.ToInt32(b[1]) - 45) < 0)
            {
                d = 60 + d;
                c = c - 1;
                if(c < 0)
                {
                    c = 23;
                }
            }
            Console.Write(c + " " + d);
        }
    }
}
