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
            string a,b;
            a = Console.ReadLine();
            b = Console.ReadLine();

            int c;
            if (Convert.ToInt32(a)>0)
            {
                if (Convert.ToInt32(b) > 0)
                {
                    c = 1;
                }
                else
                {
                    c = 4;
                }
            }
            else
            {
                if (Convert.ToInt32(b) > 0)
                {
                    c = 2;
                }
                else
                {
                    c = 3;
                }
            }
            Console.WriteLine(c);
        }
    }
}
